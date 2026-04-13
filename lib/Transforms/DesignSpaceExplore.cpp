//===----------------------------------------------------------------------===//
//
// Copyright 2020-2021 The codo Authors.
//
//===----------------------------------------------------------------------===//

#include "mlir/Dialect/Affine/Analysis/LoopAnalysis.h"
#include "mlir/Dialect/Affine/Analysis/Utils.h"
#include "mlir/Support/FileUtilities.h"
#include "mlir/Dialect/Affine/LoopUtils.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "mlir/Dialect/Affine/Utils.h"
#include "codo/Support/Explorer.h"
#include "codo/Support/Utils.h"
#include "codo/Support/Estimator.h"
#include "codo/Transforms/Passes.h"
#include "codo/Init_All_Dialects.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/ToolOutputFile.h"
#include "llvm/ADT/SmallPtrSet.h"
#include "llvm/ADT/StringMap.h"
#include <iostream>
#include <utility> 
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <filesystem>
// #include <pthread.h>

#define DEBUG_TYPE "codo"

using namespace mlir;
using namespace mlir::affine;
using namespace codo;

// using FuncTripCountMap = llvm::StringMap<int64_t>;
// llvm::StringMap<int64_t> funcTripCountMap;
struct FuncDependency {
    func::FuncOp consumer; // 被依赖的函数
    unsigned producerArgIndex;          // 当前函数的参数索引
    unsigned consumerArgIndex;       // 依赖函数的参数索引
};
llvm::StringMap<int> funcTripCountMap;
std::vector<std::pair<std::string, int>> funcLevelMapping; // 存储func和它对应的梯队编号
llvm::DenseMap<func::FuncOp, SmallVector<FuncDependency, 4>> producerToConsumers;
llvm::DenseMap<func::FuncOp, SmallVector<FuncDependency, 4>> consumerToProducers;

/// Update paretoPoints to remove design points that are not pareto frontiers.
template <typename DesignPointType>
static void updateParetoPoints(SmallVector<DesignPointType, 16> &paretoPoints) {
  // Sort the pareto points with in an ascending order of latency and the an
  // ascending order of dsp number.
  auto latencyThenDspNum = [&](const DesignPointType &a,
                               const DesignPointType &b) {
    return (a.latency < b.latency ||
            (a.latency == b.latency && a.dspNum < b.dspNum));
  };
  llvm::sort(paretoPoints, latencyThenDspNum);

  // Find pareto frontiers. After the sorting, the first design point must be a
  // pareto point.
  auto paretoPoint = paretoPoints[0];
  auto paretoLatency = paretoPoint.latency;
  auto paretoDspNum = paretoPoint.dspNum;
  SmallVector<DesignPointType, 16> frontiers;

  for (auto point : paretoPoints) {
    auto tmpLatency = point.latency;
    auto tmpDspNum = point.dspNum;

    if (tmpDspNum < paretoDspNum) {
      frontiers.push_back(point);

      paretoPoint = point;
      paretoLatency = tmpLatency;
      paretoDspNum = tmpDspNum;

    } else if (tmpDspNum == paretoDspNum && tmpLatency == paretoLatency)
      frontiers.push_back(point);
  }

  paretoPoints = frontiers;
}

//===----------------------------------------------------------------------===//
// LoopDesignSpace Class Definition
//===----------------------------------------------------------------------===//

static void emitTileListDebugInfo(FactorList tileList) {
  LLVM_DEBUG(llvm::dbgs() << "(";
             for (unsigned i = 0, e = tileList.size(); i < e; ++i) {
               llvm::dbgs() << tileList[i];
               if (i != e - 1)
                 llvm::dbgs() << ",";
               else
                 llvm::dbgs() << ") ";
             });
}

LoopDesignSpace::LoopDesignSpace(func::FuncOp func, AffineLoopBand &band,
                                 codoEstimator &estimator,
                                 unsigned maxDspNum, unsigned maxExplParallel,
                                 unsigned maxLoopParallel, bool directiveOnly)
    : func(func), band(band), estimator(estimator), maxDspNum(maxDspNum) {
  // Initialize tile vector related members.
  validTileConfigNum = 1;
  for (auto loop : band) {
    auto optionalTripCount = getConstantTripCount(loop);
    if (!optionalTripCount)
      loop.emitError("has variable loop bound");

    unsigned tripCount = optionalTripCount.value();
    tripCountList.push_back(tripCount);

    SmallVector<unsigned, 8> validSizes;
    unsigned size = 1;
    while (size <= std::min(tripCount, maxLoopParallel)) {
      // Push back the current size.
      validSizes.push_back(size);

      // Find the next possible size.
      ++size;
      while (size <= tripCount && tripCount % size != 0)
        ++size;
    }

    validTileSizesList.push_back(validSizes);
    validTileConfigNum *= validSizes.size();
  }

  // The last design point (all loops are fully unrolled) is removed.
  --validTileConfigNum;

  for (TileConfig config = 0; config < validTileConfigNum; ++config) {
    auto tileList = getTileList(config);

    // If the overall parallelism is out of bound, continue to next config.
    auto parallel = std::accumulate(tileList.begin(), tileList.end(),
                                    (unsigned)1, std::multiplies<unsigned>());
    if (parallel > maxExplParallel)
      continue;

    // In only directive opt should be applied, once one loop is unrolled, all
    // innter loops should be fully unrolled.
    if (directiveOnly) {
      bool mustFullyUnroll = false;
      bool isInvalid = false;
      unsigned i = 0;

      for (auto tile : tileList) {
        if (mustFullyUnroll && tile != tripCountList[i])
          isInvalid = true;
        if (tile != 1)
          mustFullyUnroll = true;
        ++i;
      }

      if (isInvalid)
        continue;
    }

    unestimatedTileConfigs.insert(config);
  }
}

/// Return the actual tile vector given a tile config.
FactorList LoopDesignSpace::getTileList(TileConfig config) {
  assert(config < validTileConfigNum && "invalid tile config");

  FactorList tileList;
  unsigned factor = 1;
  for (auto validSizes : validTileSizesList) {
    auto idx = config / factor % validSizes.size();
    factor *= validSizes.size();

    auto size = validSizes[idx];
    tileList.push_back(size);
  }
  return tileList;
}

/// Return the corresponding tile config given a tile list.
TileConfig LoopDesignSpace::getTileConfig(FactorList tileList) {
  assert(tileList.size() == validTileSizesList.size() && "invalid tile list");

  TileConfig config = 0;
  unsigned factor = 1;
  for (unsigned i = 0, e = tileList.size(); i < e; ++i) {
    auto tile = tileList[i];
    auto validSizes = validTileSizesList[i];

    auto idx = llvm::find(validSizes, tile) - validSizes.begin();

    assert(idx >= 0 && idx < (long)validSizes.size() && "invalid tile list");

    config += factor * idx;
    factor *= validSizes.size();
  }

  return config;
}

/// Calculate the Euclid distance of config a and config b.
float LoopDesignSpace::getTileConfigDistance(TileConfig configA,
                                             TileConfig configB) {
  assert(configA < validTileConfigNum && configB < validTileConfigNum &&
         "invalid tile config");

  int64_t distanceSquare = 0;
  unsigned factor = 1;
  for (auto validSizes : validTileSizesList) {
    int64_t idxA = configA / factor % validSizes.size();
    int64_t idxB = configB / factor % validSizes.size();
    factor *= validSizes.size();

    auto idxDistance = idxA - idxB;
    distanceSquare += idxDistance * idxDistance;
  }

  return sqrtf(distanceSquare);
}

/// Evaluate all design points under the given tile config.
bool LoopDesignSpace::evaluateTileConfig(TileConfig config) {
  // If the current tile config is already estimated, return false.
  if (!unestimatedTileConfigs.count(config))
    return false;

  // Annotate the current tile config as estimated.
  unestimatedTileConfigs.erase(config);

  // Clone a temporary loop band by cloning the outermost loop.
  auto outerLoop = band.front();
  auto tmpOuterLoop = outerLoop.clone();
  AffineLoopBand tmpBand;
  getLoopBandFromOutermost(tmpOuterLoop, tmpBand);

  // Insert the clone loop band to the front of the original band for the
  // convenience of the estimation.
  auto builder = OpBuilder(func);
  builder.setInsertionPoint(outerLoop);
  builder.insert(tmpOuterLoop);

  // Apply the tile config and estimate the loop band.
  auto tileList = getTileList(config);
  emitTileListDebugInfo(tileList);

  // Calculate the total iteration number.
  unsigned iterNum = 1;
  for (unsigned i = 0, e = tileList.size(); i < e; ++i)
    iterNum *= tripCountList[i] / tileList[i];

  // We always don't fully unroll all loops in the loop band.
  if (iterNum == 1)
    return false;

  // Apply the current tiling config and start the estimation. Note that after
  // optimization, tmpBand is optimized in place and becomes a new loop band.
  if (!applyOptStrategy(tmpBand, func, tileList, (unsigned)1))
    return false;
  tmpOuterLoop = tmpBand.front();
  estimator.estimateLoop(tmpOuterLoop, func);

  // Fetch latency and resource utilization.
  auto tmpInnerLoop = tmpBand.back();
  auto info = getLoopInfo(tmpInnerLoop);
  auto resource = getResource(tmpOuterLoop);
  assert(info && resource && "loop info or resource is not estimated");
  auto totalDsp = resource.getDsp() * info.getMinII();

  // Improve target II until II is equal to iteration latency. Note that when II
  // equal to iteration latency, the pipeline pragma is similar to a region
  // fully unroll pragma which unrolls all contained loops.
  for (auto tmpII = info.getMinII(); tmpII <= info.getIterLatency(); ++tmpII) {
    auto tmpDspNum = totalDsp / tmpII + 1;
    auto tmpLatency = info.getIterLatency() + tmpII * (iterNum - 1) + 2;
    auto point = LoopDesignPoint(tmpLatency, tmpDspNum, config, tmpII);

    allPoints.push_back(point);
    if (tmpDspNum <= maxDspNum)
      paretoPoints.push_back(point);
  }

  // Erase the temporary loop band.
  tmpOuterLoop.erase();
  return true;
}

/// Initialize the design space.
void LoopDesignSpace::initializeLoopDesignSpace(unsigned maxInitParallel) {
  LLVM_DEBUG(llvm::dbgs() << "Initialize the loop design space...\n";);

  for (TileConfig config = 0; config < validTileConfigNum; ++config) {
    auto tileList = getTileList(config);

    // We only evaluate the design points whose overall parallel is smaller
    // than the maxInitParallel to improve the efficiency.
    auto parallel = std::accumulate(tileList.begin(), tileList.end(),
                                    (unsigned)1, std::multiplies<unsigned>());

    if (parallel <= maxInitParallel) // || config == parallelConfig)
      evaluateTileConfig(config);
  }

  LLVM_DEBUG(llvm::dbgs() << "\n\n");
  updateParetoPoints(paretoPoints);
}

/// Dump pareto and non-pareto points which have been evaluated in the design
/// space to a csv output file.
void LoopDesignSpace::dumpLoopDesignSpace(StringRef csvFilePath) {
  std::string errorMessage;
  auto csvFile = mlir::openOutputFile(csvFilePath, &errorMessage);
  if (!csvFile)
    return;
  auto &os = csvFile->os();

  // Print header row.
  for (unsigned i = 0; i < tripCountList.size(); ++i)
    os << "l" << i << ",";
  os << "ii,cycle,dsp,type\n";

  // Print pareto design points.
  for (auto &point : paretoPoints) {
    for (auto size : getTileList(point.tileConfig))
      os << size << ",";
    os << point.targetII << "," << point.latency << "," << point.dspNum
       << ",pareto\n";
  }

  // Print all design points.
  for (auto &point : allPoints) {
    for (auto size : getTileList(point.tileConfig))
      os << size << ",";
    os << point.targetII << "," << point.latency << "," << point.dspNum
       << ",non-pareto\n";
  }

  csvFile->keep();
  LLVM_DEBUG(llvm::dbgs() << "Loop design space is dumped to file \""
                          << csvFilePath << "\".\n\n");
}

/// Get a random tile config which is one of the closest neighbors of "point".
std::optional<TileConfig>
LoopDesignSpace::getRandomClosestNeighbor(LoopDesignPoint point,
                                          float maxDistance) {
  // Traverse all unestimated tile configs and collect all neighbors.
  SmallVector<std::pair<float, TileConfig>, 8> candidateConfigs;
  for (auto config : unestimatedTileConfigs) {
    auto distance = getTileConfigDistance(point.tileConfig, config);
    if (distance <= maxDistance)
      candidateConfigs.push_back(
          std::pair<float, TileConfig>(distance, config));
  }

  if (candidateConfigs.empty())
    return std::optional<TileConfig>();

  // Sort candidate configs and collect the closest points.
  llvm::sort(candidateConfigs);
  SmallVector<TileConfig, 8> closestConfigs;
  float minDistance = maxDistance;

  for (auto configPair : candidateConfigs) {
    if (configPair.first <= minDistance) {
      closestConfigs.push_back(configPair.second);
      minDistance = configPair.first;
    } else
      break;
  }

  // Randomly pick one as the return point.
  std::srand(time(0));
  llvm::shuffle(closestConfigs.begin(), closestConfigs.end(),
                []() { return std::rand(); });

  return closestConfigs.front();
}

void LoopDesignSpace::exploreLoopDesignSpace(unsigned maxIterNum,
                                             float maxDistance) {
  LLVM_DEBUG(llvm::dbgs() << "Explore the loop design space...\n";);

  // Exploration loop of the dse.
  for (unsigned i = 0; i < maxIterNum; ++i) {
    std::srand(time(0));
    llvm::shuffle(paretoPoints.begin(), paretoPoints.end(),
                  []() { return std::rand(); });

    bool foundValidNeighbor = false;
    for (auto &point : paretoPoints) {
      if (!point.isActive)
        continue;

      auto closestNeighbor = getRandomClosestNeighbor(point, maxDistance);
      if (!closestNeighbor) {
        point.isActive = false;
        continue;
      }

      foundValidNeighbor = true;
      auto config = closestNeighbor.value();
      auto tileList = getTileList(config);

      evaluateTileConfig(config);
      break;
    }

    // Early termination if no valid neighbor is found.
    if (!foundValidNeighbor)
      break;

    // Update pareto points after each dse iteration.
    updateParetoPoints(paretoPoints);
  }
  LLVM_DEBUG(llvm::dbgs() << "\n\n";);
}

//===----------------------------------------------------------------------===//
// FuncDesignSpace Class Definition
//===----------------------------------------------------------------------===//

void FuncDesignSpace::dumpFuncDesignSpace(StringRef csvFilePath) {
  std::string errorMessage;
  auto csvFile = mlir::openOutputFile(csvFilePath, &errorMessage);
  if (!csvFile)
    return;
  auto &os = csvFile->os();

  // Print header row.
  for (unsigned i = 0, ei = loopDesignSpaces.size(); i < ei; ++i) {
    auto &loopSpace = loopDesignSpaces[i];

    for (unsigned j = 0, ej = loopSpace.tripCountList.size(); j < ej; ++j)
      os << "b" << i << "l" << j << ",";
    os << "b" << i << "ii,";
  }
  os << "cycle,dsp,type\n";

  // Print pareto design points.
  for (auto &funcPoint : paretoPoints) {
    for (unsigned i = 0, e = loopDesignSpaces.size(); i < e; ++i) {
      auto &loopPoint = funcPoint.loopDesignPoints[i];
      auto &loopSpace = loopDesignSpaces[i];

      for (auto size : loopSpace.getTileList(loopPoint.tileConfig))
        os << size << ",";
      os << loopPoint.targetII << ",";
    }
    os << funcPoint.latency << "," << funcPoint.dspNum << ",pareto\n";
  }

  csvFile->keep();
  LLVM_DEBUG(llvm::dbgs() << "Function design space is dumped to file \""
                          << csvFilePath << "\".\n\n");
}

void FuncDesignSpace::combLoopDesignSpaces() {
  LLVM_DEBUG(llvm::dbgs() << "Combine the loop design spaces...\n";);

  // Initialize the function design space with the first loop design space.
  auto &firstLoopSpace = loopDesignSpaces[0];
  for (auto &loopPoint : firstLoopSpace.paretoPoints) {
    // Annotate the first loop.
    auto loop = targetLoops[0];
    setTiming(loop, -1, -1, loopPoint.latency, -1);
    setResource(loop, -1, loopPoint.dspNum, -1);

    // Estimate the function and generate a new function design point.
    estimator.estimateFunc(func);
    auto latency = getTiming(func).getLatency();
    auto dspNum = getResource(func).getDsp();
    auto funcPoint = FuncDesignPoint(latency, dspNum, loopPoint);

    paretoPoints.push_back(funcPoint);
  }

  updateParetoPoints(paretoPoints);
  LLVM_DEBUG(llvm::dbgs() << "Iteration 0 pareto points number: "
                          << paretoPoints.size() << "\n";);

  // Combine other loop design spaces to the function design space one by one.
  for (unsigned i = 1, e = loopDesignSpaces.size(); i < e; ++i) {
    SmallVector<FuncDesignPoint, 16> newParetoPoints;
    auto &loopSpace = loopDesignSpaces[i];

    // Traverse all function design points.
    for (auto &funcPoint : paretoPoints) {
      // Annotate latency and dsp to all loops that are already included in the
      // function point, they are static for all design points of the new loop.
      for (unsigned ii = 0; ii < i; ++ii) {
        auto &oldLoopPoint = funcPoint.loopDesignPoints[ii];
        auto oldLoop = targetLoops[ii];
        setTiming(oldLoop, -1, -1, oldLoopPoint.latency, -1);
        setResource(oldLoop, -1, oldLoopPoint.dspNum, -1);
      }

      // Traverse all design points of the NEW loop.
      for (auto &loopPoint : loopSpace.paretoPoints) {
        // Annotate the new loop,
        auto loop = targetLoops[i];
        setTiming(loop, -1, -1, loopPoint.latency, -1);
        setResource(loop, -1, loopPoint.dspNum, -1);

        // Estimate the function and generate a new function design point.
        auto loopPoints = funcPoint.loopDesignPoints;
        loopPoints.push_back(loopPoint);

        estimator.estimateFunc(func);
        auto latency = getTiming(func).getLatency();
        auto dspNum = getResource(func).getDsp();
        auto newFuncPoint = FuncDesignPoint(latency, dspNum, loopPoints);

        newParetoPoints.push_back(newFuncPoint);
      }
    }

    // Update pareto points after each combination.
    updateParetoPoints(newParetoPoints);
    paretoPoints = newParetoPoints;
    LLVM_DEBUG(llvm::dbgs() << "Iteration " << i << " pareto points number: "
                            << paretoPoints.size() << "\n";);
  }
  LLVM_DEBUG(llvm::dbgs() << "\n";);
}

bool FuncDesignSpace::exportParetoDesigns(unsigned outputNum,
                                          StringRef outputRootPath) {
  unsigned paretoNum = paretoPoints.size();
  auto sampleStep = std::max(paretoNum / outputNum, (unsigned)1);

  // Traverse all detected pareto points.
  unsigned sampleIndex = 0;
  for (auto &funcPoint : paretoPoints) {
    // Only export sampled points.
    if (sampleIndex % sampleStep == 0) {
      std::vector<FactorList> tileLists;
      SmallVector<unsigned, 4> targetIIs;

      for (unsigned i = 0; i < loopDesignSpaces.size(); ++i) {
        auto &loopSpace = loopDesignSpaces[i];
        auto &loopPoint = funcPoint.loopDesignPoints[i];
        auto tileList = loopSpace.getTileList(loopPoint.tileConfig);
        auto targetII = loopPoint.targetII;

        tileLists.push_back(tileList);
        targetIIs.push_back(targetII);
      }

      // Clone a new function and apply optimization.
      auto tmpFunc = func.clone();
      if (!applyOptStrategy(tmpFunc, tileLists, targetIIs))
        return false;
      estimator.estimateFunc(tmpFunc);

      // Parse a new output file.
      auto outputFilePath = outputRootPath.str() + func.getName().str() +
                            "_pareto_" + std::to_string(sampleIndex) + ".mlir";

      std::string errorMessage;
      auto outputFile = mlir::openOutputFile(outputFilePath, &errorMessage);
      if (!outputFile)
        return false;

      auto &os = outputFile->os();
      os << tmpFunc << "\n";
      outputFile->keep();
    }
    ++sampleIndex;
  }

  LLVM_DEBUG(
      llvm::dbgs() << "Sampled pareto points MLIR files are exported to path \""
                   << outputRootPath << "\".\n\n");
  return true;
}

//===----------------------------------------------------------------------===//
// Explorer Class Definition
//===----------------------------------------------------------------------===//

bool codoExplorer::emitQoRDebugInfo(func::FuncOp func,
                                        std::string message) {
  estimator.estimateFunc(func);
  // auto latency = getTiming(func).getLatency();
  auto dspNum = getResource(func).getDsp();

  LLVM_DEBUG(llvm::dbgs() << message + "\n";
             //  llvm::dbgs() << "The clock cycle is " << Twine(latency)
             //               << ", DSP usage is " << Twine(dspNum) << ".\n\n";
  );

  return dspNum <= maxDspNum;
}

static int64_t getInnerParallelism(Block &block) {
  int64_t count = 0;
  for (auto loop : block.getOps<AffineForOp>()) {
    auto innerCount = getInnerParallelism(*loop.getBody());
    if (auto trip = getAverageTripCount(loop))
      count += trip.value() * innerCount;
    else
      count += innerCount;
  }

  // If the current loop is innermost loop, count should be one.
  return std::max(count, (int64_t)1);
}

bool codoExplorer::evaluateFuncPipeline(func::FuncOp func) { return true; }

/// DSE Stage1: Simplify loop nests by unrolling. If we take the following loops
/// as example, where each nodes represents one sequential loop nests (LN). In
/// the simplification, we'll first try to pipeline LN1 and LN6. Suppose
/// unrolling LN6's region meets the resource constaints while pipelining LN1
/// not, we'll unroll LN6's region (fully unroll LN7 and LN8) and keep LN1
/// untouched. In the next step, we'll look into LN1 and check whether LN2's
/// region can be unrolled. Suppose unrolling LN2's region meets the resource
/// constraints, we'll unrolling LN2's region (fully unroll LN7 and LN8). Note
/// that in this simplification, all LNs that don't contain any LNs will not be
/// touched, such as LN5. Their optimization will be explored later. This
/// procedure will recursively applied to inner LNs until no eligible LN exists.
///
///     LN1      LN6
///      |        |
///     / \      / \
///   LN2 LN5  LN7 LN8
///    |
///   / \
/// LN3 LN4
///
/// After the simplification, the loop becomes the following one, where LN1 has
/// been proved untouchable as region loop unrolling is the primary optimization
/// that consumes the least extra resources. Formally, in the simplified
/// function, all non-leaf LNs is untouchable (LN1) and only leaf LNs can be
/// further optimized (LN2, LN5, and LN6).
///
///     LN1      LN6
///      |
///     / \
///   LN2 LN5
///
/// TODO: there is a large design space in this simplification.
bool codoExplorer::simplifyLoopNests(func::FuncOp func) {
  LLVM_DEBUG(llvm::dbgs()
                 << "----------\nStage1: Simplify loop nests structure...\n";);
  llvm::dbgs() << "----------\nStage1: Simplify loop nests structure...\n";

  auto funcForOps = func.getOps<AffineForOp>();
  auto targetLoops =
      SmallVector<AffineForOp, 8>(funcForOps.begin(), funcForOps.end());

  while (!targetLoops.empty()) {
    SmallVector<std::pair<int64_t, AffineForOp>, 8> candidateLoops;

    // Collect all candidate loops. Here, only loops whose innermost loop has
    // more than one inner loops will be considered as a candidate.
    for (auto target : targetLoops) {
      AffineLoopBand loopBand;
      auto innermostLoop = getLoopBandFromOutermost(target, loopBand);

      // Calculate the overall introduced parallelism if the innermost loop of
      // the current loop band is fully unrolled.
      auto parallelism =
          getInnerParallelism(*innermostLoop.getBody());

      // Collect all candidate loops into an vector, we'll ignore too large
      // parallelism as unrolling them typically introduce very high cost.
      if (parallelism > 1 && parallelism <= 512)
        candidateLoops.push_back(
            std::pair<int64_t, AffineForOp>(parallelism, innermostLoop));
    }

    // Since all target loops have been handled, clear the targetLoops vector.
    targetLoops.clear();

    // Sort the candidate loops.
    llvm::sort(candidateLoops);

    // Traverse all candidates to check whether applying fully loop unrolling
    // has violation with the resource constraints. If so, add all inner loops
    // into targetLoops. Otherwise, fully unroll the candidate.
    for (auto pair : candidateLoops) {
      auto candidate = pair.second;

      // Create a temporary function.
      candidate->setAttr("opt_flag", BoolAttr::get(func.getContext(), true));
      auto tmpFunc = func.clone();

      // Find the candidate loop in the temporary function and apply fully loop
      // unrolling to it.
      tmpFunc.walk([&](AffineForOp loop) {
        if (loop->getAttrOfType<BoolAttr>("opt_flag")) {
          applyFullyLoopUnrolling(*loop.getBody());
          // applyMemoryOpts(tmpFunc);
          // applyAutoArrayPartition(tmpFunc);
          return;
        }
      });

      // Estimate the temporary function.
      estimator.estimateFunc(tmpFunc);

      // Fully unroll the candidate loop or delve into child loops.
      if (getResource(tmpFunc).getDsp() <= maxDspNum) {
        applyFullyLoopUnrolling(*candidate.getBody());
        // applyMemoryOpts(func);
        // applyAutoArrayPartition(func);
      } else {
        auto childForOps = candidate.getOps<AffineForOp>();
        targetLoops.append(childForOps.begin(), childForOps.end());
      }

      candidate->removeAttr("opt_flag");
    }
  }

  return emitQoRDebugInfo(func, "\nFinish Stage1.");
}

/// DSE Stage2: Optimize leaf loop nests. Different optimization conbinations
/// will be applied to each leaf LNs, and the best one which meets the resource
/// constraints will be picked as the final solution.
/// TODO: better handle variable bound kernels.
bool codoExplorer::optimizeLoopBands(func::FuncOp func,
                                         bool directiveOnly) {
  LLVM_DEBUG(llvm::dbgs() << "----------\nStage2: Apply loop perfection, loop "
                             "order opt, and remove variable loop bound...\n";);

  // llvm::outs() << "----------\nStage2: Apply loop perfection, loop "
  //                            "order opt, and remove variable loop bound...\n";

  AffineLoopBands targetBands;
  getLoopBands(func.front(), targetBands);
  unsigned targetNum = targetBands.size();

  // Loop perfection, remove variable bound, and loop order optimization are
  // always applied for the convenience of polyhedral optimizations.
  for (unsigned i = 0; i < targetNum; ++i) {
    auto &band = targetBands[i];
    LLVM_DEBUG(llvm::dbgs() << "Loop band " << i << ": ";);
    // llvm::outs() << "Loop band " << i << ": ";
    // applyAffineLoopPerfection(band);

    // If only explore directive optimizations, disable loop oreder opt.
    if (!directiveOnly)
      applyAffineLoopOrderOpt(band);

    // applyRemoveVariableBound(band);
  }

  return emitQoRDebugInfo(func, "\nFinish Stage2.");
}

/// DSE Stage3: Explore the function design space through dynamic programming.
bool codoExplorer::exploreDesignSpace(func::FuncOp func, bool directiveOnly,
                                          StringRef outputRootPath,
                                          StringRef csvRootPath) {
  LLVM_DEBUG(llvm::dbgs() << "----------\nStage3: Conduct top function design "
                             "space exploration...\n";);
  // llvm::outs() << "----------\nStage3: Conduct top function design "
  //                            "space exploration...\n";

  auto tmpFunc = func.clone();
  AffineLoopBands targetBands;
  getLoopBands(tmpFunc.front(), targetBands);
  unsigned targetNum = targetBands.size();

  // Search for the pareto frontiers of each target loop band.
  SmallVector<LoopDesignSpace, 4> loopSpaces;
  for (unsigned i = 0; i < targetNum; ++i) {
    auto space =
        LoopDesignSpace(tmpFunc, targetBands[i], estimator, maxDspNum,
                        maxExplParallel, maxLoopParallel, directiveOnly);

    // LLVM_DEBUG(llvm::dbgs() << "Loop band " << i << ": ";);
    // llvm::outs() << "Loop band " << i << ": ";
    space.initializeLoopDesignSpace(maxInitParallel);

    // llvm::outs() << "Loop band " << i << ": ";
    space.exploreLoopDesignSpace(maxIterNum, maxDistance);
    loopSpaces.push_back(space);

    // Dump design points to csv file for each loop band.
    auto loopCsvFilePath = csvRootPath.str() + func.getName().str() + "_loop_" +
                           std::to_string(i) + "_space.csv";
    space.dumpLoopDesignSpace(loopCsvFilePath);
  }

  // Combine all loop design spaces into a function design space.
  tmpFunc = func.clone();
  auto funcSpace = FuncDesignSpace(tmpFunc, loopSpaces, estimator, maxDspNum);
  funcSpace.combLoopDesignSpaces();

  // Dump design points to csv file for each function.
  auto funcCsvFilePath =
      csvRootPath.str() + func.getName().str() + "_space.csv";
  funcSpace.dumpFuncDesignSpace(funcCsvFilePath);

  // Export sampled pareto points MLIR source.
  funcSpace.exportParetoDesigns(outputNum, outputRootPath);

  // Apply the best function design point under the constraints.
  for (auto &funcPoint : funcSpace.paretoPoints) {
    if (funcPoint.dspNum <= maxDspNum) {
      std::vector<FactorList> tileLists;
      SmallVector<unsigned, 4> targetIIs;

      for (unsigned i = 0; i < targetNum; ++i) {
        auto &loopSpace = funcSpace.loopDesignSpaces[i];
        auto &loopPoint = funcPoint.loopDesignPoints[i];
        auto tileList = loopSpace.getTileList(loopPoint.tileConfig);
        auto targetII = loopPoint.targetII;

        LLVM_DEBUG(llvm::dbgs() << "Loop band " << i << ": "
                                << "Loop tiling & pipelining (";);
        // llvm::outs() << "Loop band " << i << ": "
        //                         << "Loop tiling & pipelining (";
        // for (auto tile : tileList) { llvm::outs() << tile << ","; }
        // LLVM_DEBUG();
        // llvm::outs() << targetII << ")\n";
        // LLVM_DEBUG();

        tileLists.push_back(tileList);
        targetIIs.push_back(targetII);
      }

      // if (!applyOptStrategy(func, tileLists, targetIIs))
      //   return false;
      break;
    }
  }

  return emitQoRDebugInfo(func, "\nFinish Stage3.");
}

static void updateSubFuncs(func::FuncOp func, Builder builder) {
  func.walk([&](func::CallOp op) {
    auto callee = SymbolTable::lookupNearestSymbolFrom(op, op.getCalleeAttr());
    auto subFunc = dyn_cast<func::FuncOp>(callee);

    // Set sub-function type.
    auto subResultTypes = op.getResultTypes();
    auto subInputTypes = op.getOperandTypes();
    auto newType = builder.getFunctionType(subInputTypes, subResultTypes);

    if (subFunc.getFunctionType() != newType) {
      subFunc.setType(newType);

      // Set arguments type.
      unsigned index = 0;
      for (auto inputType : op.getOperandTypes())
        subFunc.getArgument(index++).setType(inputType);

      // Set results type.
      auto returnOp = cast<func::ReturnOp>(subFunc.front().getTerminator());
      index = 0;
      for (auto resultType : op.getResultTypes())
        returnOp.getOperand(index++).setType(resultType);

      // Recursively apply array partition strategy.
      updateSubFuncs(subFunc, builder);
    }
  });
}

static void updateParentFunc(func::FuncOp func, Builder builder) {
  // 找到父函数
  auto parentFunc = func.getOperation()->getParentOfType<func::FuncOp>();
  if (!parentFunc) return; // 如果没有父函数则返回

  // 获取当前函数的输入和输出类型
  auto subResultTypes = func.getResultTypes();
  auto subInputTypes = func.getArgumentTypes();
  auto newType = builder.getFunctionType(subInputTypes, subResultTypes);

  // 检查父函数的类型是否需要更新
  if (parentFunc.getFunctionType() != newType) {
    parentFunc.setType(newType);

    // 更新父函数的参数类型
    unsigned index = 0;
    for (auto inputType : subInputTypes) {
      if (index < parentFunc.getNumArguments()) {
        parentFunc.getArgument(index).setType(inputType);
      }
      index++;
    }

    // 更新父函数的返回值类型
    auto returnOp = cast<func::ReturnOp>(parentFunc.front().getTerminator());
    index = 0;
    for (auto resultType : subResultTypes) {
      if (index < returnOp.getNumOperands()) {
        returnOp.getOperand(index).setType(resultType);
      }
      index++;
    }

    // 递归更新父函数的其他调用（如果需要）
    updateParentFunc(parentFunc, builder);
  }
}

static void updateTopFunc(func::FuncOp topFunc, Builder builder) {
    topFunc.walk([&](func::CallOp callOp) {
        auto callee = SymbolTable::lookupNearestSymbolFrom(callOp, callOp.getCalleeAttr());
        auto subFunc = dyn_cast<func::FuncOp>(callee);
        if (!subFunc) return;

        // 建立映射关系
        DenseMap<Value, Value> argMapping;
        for (unsigned index = 0; index < callOp.getNumOperands(); ++index) {
            auto operand = callOp.getOperand(index);
            auto subArg = subFunc.getArgument(index);
            argMapping[operand] = subArg;
        }

        // 更新调用操作的参数类型
        for (auto &mapping : argMapping) {
            auto operand = mapping.first;
            auto subArgType = mapping.second.getType();
            int temp = -1;
            for (unsigned index = 0; index < topFunc.getNumArguments(); ++index) {
                if (operand == topFunc.getArgument(index)) {
                  temp = index;
                }
            }
            if (operand.getType() != subArgType) {
                operand.setType(subArgType);
            }
            if(temp!=-1){
              topFunc.getArgument(temp).setType(subArgType);
            }
        }
        auto resultTypes = topFunc.front().getTerminator()->getOperandTypes();
        auto inputTypes = topFunc.front().getArgumentTypes();
        topFunc.setType(builder.getFunctionType(inputTypes, resultTypes));

    });
}


//===----------------------------------------------------------------------===//
// DesignSpaceExplore Entry
//===----------------------------------------------------------------------===//
func::FuncOp codoExplorer::applyDesignSpaceExplore(func::FuncOp func,
                                               int level) {
  // emitQoRDebugInfo(func, "Start multiple level DSE.");
  auto clonedFunc = func.clone();
  // clonedFunc.dump();
  // auto clonedFunc = originalFunc.clone();

  DenseMap<Value, Value> memrefMapping;
  SmallVector<Value> memref_func;
  SmallVector<Value> memref_cloned;

  // AffineLoopBands targetBands_func;
  // getLoopBands(func.front(), targetBands_func);
  // SmallVector<Block *, 4> targetBlocks_func;
  // for (auto &band : targetBands_func){
  //     targetBlocks_func.push_back(band.back().getBody());
  // }
  for (auto arg : func.getArguments()) {
    if (auto memrefType = arg.getType().dyn_cast<MemRefType>()) {
      memref_func.push_back(arg);
    }
  }

  func.walk([&](BufferOp bufferOp) {
    memref_func.push_back(bufferOp.getResult());
    // llvm::outs() << "Found BufferOp: " << bufferOp << "\n";
  });



  // AffineLoopBands targetBands_cloned;
  // getLoopBands(clonedFunc.front(), targetBands_cloned);
  // SmallVector<Block *, 4> targetBlocks_cloned;
  //   for (auto &band : targetBands_cloned){
  //     targetBlocks_cloned.push_back(band.back().getBody());
  // }
  for (auto arg : clonedFunc.getArguments()) {
    if (auto memrefType = arg.getType().dyn_cast<MemRefType>()) {
      memref_cloned.push_back(arg);
    }
  }
  clonedFunc.walk([&](BufferOp bufferOp) {

    memref_cloned.push_back(bufferOp.getResult());
  });


  assert(memref_func.size() == memref_cloned.size() && "Mismatch in sizes");

  for (size_t i = 0; i < memref_func.size(); ++i) {
      Value originalMemRef = memref_func[i];
      Value clonedMemRef = memref_cloned[i];
      memrefMapping[clonedMemRef] = originalMemRef;

  }

  

  // int tilesize = 4;



  DenseMap<Value, SmallVector<Partition, 4>> partitionsMap;
  clonedFunc.walk([&](AffineForOp forOp) {
    // if (isa<func::FuncOp>(forOp->getParentOp())||isa<codo::TaskOp>(forOp->getParentOp())) {
      AffineLoopBand band;
      getLoopBandFromOutermost(forOp, band);
      auto bandDepth = band.size();
      // llvm::outs()<<"band size: "<<bandDepth;
      if((forOp->hasAttrOfType<UnitAttr>("conv_loop")||forOp->hasAttrOfType<UnitAttr>("io_loop")) && !forOp->hasAttrOfType<UnitAttr>("opted")){
        forOp.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));

        bool is_depthConv = false;
        bool need_tile = true;
        if(forOp->hasAttrOfType<UnitAttr>("depth_conv_loop")){
          is_depthConv = true;
          
        }
        int tilesize = 1;
        // forOp.dump();
        // Example to apply tiling using MLIR utilities
        // applyAffineLoopTiling(band[0], 2);
        if(band[1].getConstantUpperBound()>=32){
            band[0]=band[1];
            if(band[1].getConstantUpperBound()>=64){
              tilesize = 1;
            }
            else{
              tilesize = 1;
            }
            // if(band[2].getConstantUpperBound()>=16){
            //   tilesize = 8;

            // }
              
            need_tile = false;
          }
        // else if(band[0].getConstantUpperBound()>=32){
        //     // tilesize = 32;
        // }
        band.resize(1);
        SmallVector<unsigned, 8> tileList({tilesize});
        AffineLoopBand tiledBand;

        tilePerfectlyNested(band, tileList, &tiledBand);
        (void)normalizeAffineFor(tiledBand[0]);
        (void)normalizeAffineFor(tiledBand[1]);

        // Now In order to keep FIFO read-write consistency, we need to 
        // perform the same tiling strategy to the consumers
        llvm::SmallVector<AffineStoreOp> storeOps;
        tiledBand[0].walk([&](AffineStoreOp storeOp) {
          storeOps.push_back(storeOp);

        });
        // tiledBand[0].dump();
        auto users = storeOps.back().getMemRef().getUsers();
        size_t userCount = std::distance(users.begin(), users.end());
        // TODO: if size>1, the consumer and the producer are in the same node
        // bool skipConv = true;
        if(userCount>1 && is_depthConv || userCount>1 && need_tile){
          // TODO
          // tiledBand[0].dump();
          // skipConv = false;
          // llvm::outs() << "Found BufferOp: "<< "\n";
          for (auto user : users) {
            if (auto loadOp = dyn_cast<affine::AffineLoadOp>(user)) {
                // llvm::outs() << "This user is a LoadOp: " <<"\n";
                auto currentOp = loadOp.getOperation();
                auto parentFor = currentOp->getParentOfType<mlir::affine::AffineForOp>();
                getLoopBandFromOutermost(parentFor, band);
                SmallVector<unsigned, 8> tileList2({tilesize});
                AffineLoopBand tiledBand2;

                tilePerfectlyNested(band, tileList2, &tiledBand2);
                (void)normalizeAffineFor(tiledBand2[0]);
                (void)normalizeAffineFor(tiledBand2[1]);
                applyLoopPipelining(tiledBand2,0,1);
                applyFullyLoopUnrolling(*tiledBand2[0].getBody()); 
                

                // tiledBand2[0].dump();
            }
          }

        }
        // else{
        //   clonedFunc.walk([&](AffineForOp newforOp) {
        //     if((newforOp->hasAttrOfType<UnitAttr>("top_loop")||forOp->hasAttrOfType<UnitAttr>("wb_loop=")) && !forOp->hasAttrOfType<UnitAttr>("opted")){
        //       newforOp.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));
        //       AffineLoopBand testband;
        //       getLoopBandFromOutermost(newforOp, testband);
        //       testband.resize(1);
        //       SmallVector<unsigned, 8> testtileList({8});
        //       AffineLoopBand testtiledBand;
        //       if(testband[3].getUpperBoundMap().getSingleConstantResult()>8){
        //           tilePerfectlyNested(band, testtileList, &testtiledBand);
        //           (void)normalizeAffineFor(testtiledBand[0]);
        //           (void)normalizeAffineFor(testtiledBand[1]);
        //           applyLoopPipelining(testtiledBand,0,1);
        //           applyFullyLoopUnrolling(*testtiledBand[0].getBody()); 
        //       }
        //     }
        //   });
        // }
        if(userCount==1 || userCount>1 && is_depthConv || userCount>1 && need_tile){
          //FIXME:其实这里逻辑不正确，这个分支应该只适用于resnetNode33以及后面的pooling
          //正确的逻辑是如果并行的维度会影响后续的read，则后面应该做相同的优化。这个分析方法待补充，眼下是按照模型结构
          //设置的，不够general
          for (const auto &dependency : producerToConsumers[func]) {
            func::FuncOp consumerFunc = dependency.consumer;
            int consumerIndex = dependency.consumerArgIndex;
            auto consumerArg = consumerFunc.getArgument(consumerIndex);
            auto clonedConsumerFunc = consumerFunc.clone();
            auto currentSize = memref_func.size();
            if(consumerFunc->hasAttrOfType<UnitAttr>("conv_node") && !func->hasAttrOfType<UnitAttr>("conv_node")  ){
              return WalkResult::interrupt();
            }
            for (auto arg : consumerFunc.getArguments()) {
              if (auto memrefType = arg.getType().dyn_cast<MemRefType>()) {
                memref_func.push_back(arg);
              }
            }
            consumerFunc.walk([&](BufferOp bufferOp) {
              memref_func.push_back(bufferOp.getResult());
              // llvm::outs() << "Found BufferOp: " << bufferOp << "\n";
            });

            for (auto arg : clonedConsumerFunc.getArguments()) {
              if (auto memrefType = arg.getType().dyn_cast<MemRefType>()) {
                memref_cloned.push_back(arg);
              }
            }
            clonedConsumerFunc.walk([&](BufferOp bufferOp) {
              memref_cloned.push_back(bufferOp.getResult());
            });

            assert(memref_func.size() == memref_cloned.size() && "Mismatch in sizes");

            for (size_t i = currentSize; i < memref_func.size(); ++i) {
                Value originalMemRef = memref_func[i];
                Value clonedMemRef = memref_cloned[i];
                memrefMapping[clonedMemRef] = originalMemRef;
            }
            clonedConsumerFunc.walk([&](AffineLoadOp op) {
              if (auto loadOp = llvm::dyn_cast<mlir::affine::AffineLoadOp>(&op)) {
                // 找到 store 操作的目标
                auto target = loadOp->getMemRef();
                // llvm::outs()<<"target: "<<consumerArg<<"\n";
                // llvm::outs()<<"current: "<<target<<"\n";
                if (target == clonedConsumerFunc.getArgument(consumerIndex)) {
                  // llvm::outs()<<"entenr : "<<consumerArg<<"\n";
                  auto currentOp = loadOp->getOperation();
                  auto topLevelFor = currentOp->getParentOfType<mlir::affine::AffineForOp>();
                  // topLevelFor.dump();
                  AffineLoopBand topband;
                  getLoopBandFromInnermost(topLevelFor,topband);
                  if(!topLevelFor->hasAttrOfType<UnitAttr>("opted")){
                    AffineLoopBand consumerBand;
                    AffineLoopBand consumerTiledBand;
                    
                    consumerBand.push_back(topLevelFor);

                    tilePerfectlyNested(consumerBand, tileList, &consumerTiledBand);
                    (void)normalizeAffineFor(consumerTiledBand[0]);
                    (void)normalizeAffineFor(consumerTiledBand[1]);
                    // if(consumerTiledBand[0].getUpperBoundMap().getSingleConstantResult()==tilesize){
                      // applyLoopPipelining(consumerTiledBand,1,1);
                    // }else{
                      applyLoopPipelining(consumerTiledBand,0,1);
                    // }
                    // applyLoopPipelining(consumerTiledBand,0,1);
                    applyFullyLoopUnrolling(*consumerTiledBand[0].getBody()); 
                    consumerTiledBand[0].getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));
                    // topLevelFor.dump();

                    if(!topband[0].getOperation()->hasAttrOfType<UnitAttr>("top_loop")){
                      // llvm::outs()<<"current: "<<"\n";
                      bool opt1, opt2 = false;
                        clonedConsumerFunc.walk([&](AffineForOp consuforOp) {
                          if(consuforOp->hasAttrOfType<UnitAttr>("top_loop")){
                            // llvm::outs()<<"current: "<<"\n";
                            topLevelFor.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));
                            opt1= true;
                            AffineLoopBand consumerBand1;
                            AffineLoopBand consumerTiledBand1;

                            getLoopBandFromOutermost(consuforOp, consumerBand1);
                            consumerBand1[0]=consumerBand1[3];
                            consumerBand1.resize(1);
                            
                            // consumerBand1.push_back(consuforOp);

                            tilePerfectlyNested(consumerBand1, tileList, &consumerTiledBand1);
                            (void)normalizeAffineFor(consumerTiledBand1[0]);
                            (void)normalizeAffineFor(consumerTiledBand1[1]);
                            if(consumerTiledBand1[0].getUpperBoundMap().getSingleConstantResult()==tilesize){
                              applyLoopPipelining(consumerTiledBand1,1,1);
                            }else{
                              applyLoopPipelining(consumerTiledBand1,0,1);
                            }
                            
                            applyFullyLoopUnrolling(*consumerTiledBand1[0].getBody());

                          }else if(consuforOp->hasAttrOfType<UnitAttr>("wb_loop")){
                            topLevelFor.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));
                            opt2= true;
                            AffineLoopBand consumerBand1;
                            AffineLoopBand consumerTiledBand1;

                            getLoopBandFromOutermost(consuforOp, consumerBand1);
                            // consumerBand1[0]=consumerBand1[3];
                            consumerBand1.resize(1);
                            
                            // consumerBand1.push_back(consuforOp);

                            tilePerfectlyNested(consumerBand1, tileList, &consumerTiledBand1);
                            (void)normalizeAffineFor(consumerTiledBand1[0]);
                            (void)normalizeAffineFor(consumerTiledBand1[1]);
                            // if(consumerTiledBand1[0].getUpperBoundMap().getSingleConstantResult()==tilesize){
                            //   applyLoopPipelining(consumerTiledBand1,1,1);
                            // }else{
                              applyLoopPipelining(consumerTiledBand1,0,1);
                            // }
                            
                            applyFullyLoopUnrolling(*consumerTiledBand1[0].getBody());
                          }
                          // if(opt1==true&&opt2==true){
                          //   // return WalkResult::interrupt();
                          // }
                        });
                      
                    }else{
                      clonedConsumerFunc.walk([&](AffineForOp consuforOp) {
                          if(consuforOp->hasAttrOfType<UnitAttr>("wb_loop")){
                            topLevelFor.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));
                            // opt2= true;
                            AffineLoopBand consumerBand1;
                            AffineLoopBand consumerTiledBand1;

                            getLoopBandFromOutermost(consuforOp, consumerBand1);
                            // consumerBand1[0]=consumerBand1[3];
                            consumerBand1.resize(1);
                            
                            // consumerBand1.push_back(consuforOp);

                            tilePerfectlyNested(consumerBand1, tileList, &consumerTiledBand1);
                            (void)normalizeAffineFor(consumerTiledBand1[0]);
                            (void)normalizeAffineFor(consumerTiledBand1[1]);
                            if(consumerTiledBand1[0].getUpperBoundMap().getSingleConstantResult()==tilesize){
                              applyLoopPipelining(consumerTiledBand1,1,1);
                            }else{
                              applyLoopPipelining(consumerTiledBand1,0,1);
                            }
                            
                            applyFullyLoopUnrolling(*consumerTiledBand1[0].getBody());
                          }
                        });

                    }
                  
                  }
                  return WalkResult::interrupt();
                }
              }
            });
            applyAutoArrayPartition(clonedConsumerFunc, partitionsMap, 1024);
          }
   
        // }
        // for (auto *user : storeOps.back().getMemRef().getUsers()) {
        //       llvm::outs() << "User: " << *user << "\n";
        // }

      // clonedFunc.dump();
      } 
      applyLoopPipelining(tiledBand,0,1);
      applyFullyLoopUnrolling(*tiledBand[0].getBody()); 
      applyAutoArrayPartition(clonedFunc, partitionsMap, 1024);
   }
  });

  func.walk([&](AffineForOp forOp) {
    // if (isa<func::FuncOp>(forOp->getParentOp())||isa<codo::TaskOp>(forOp->getParentOp())) {
      AffineLoopBand band;
      getLoopBandFromOutermost(forOp, band);
      // auto bandDepth = band.size();
      // llvm::SmallVector<AffineStoreOp> storeOps;
      //   tiledBand[0].walk([&](AffineStoreOp storeOp) {
      //     storeOps.push_back(storeOp);

      // });

      if((forOp->hasAttrOfType<UnitAttr>("conv_loop")||forOp->hasAttrOfType<UnitAttr>("io_loop"))&& !forOp->hasAttrOfType<UnitAttr>("opted")){
        forOp.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));

        bool is_depthConv = false;
        bool need_tile = true;
        if(forOp->hasAttrOfType<UnitAttr>("depth_conv_loop")){
          is_depthConv = true;
        }

        AffineLoopBand innerBand;
        getLoopBandFromOutermost(forOp,innerBand);
        int tilesize = 1;
        // If input channel is large, we turn to optimize ci.
        // So the related FIFO array and the related loops shound 
        // have consistant opt strategy.
        bool resetConv = true;
        if(band[1].getConstantUpperBound()>=32){
          band[0]=band[1];
          resetConv = false;
          if(band[1].getConstantUpperBound()>=64){
            tilesize = 1;
          }
          else{
            tilesize = 1;
          }
          // if(band[2].getConstantUpperBound()>=16){
          //   tilesize = 8;

          // }
            
          need_tile = false;
        }
        // else if(band[0].getConstantUpperBound()>=32){
        //   tilesize = 32;
        // }
        band.resize(1);
        SmallVector<unsigned, 8> tileList({tilesize});
        AffineLoopBand tiledBand;
        
        tilePerfectlyNested(band, tileList, &tiledBand);
        (void)normalizeAffineFor(tiledBand[0]);
        (void)normalizeAffineFor(tiledBand[1]);
        applyLoopPipelining(tiledBand,0,1);

        if(resetConv == true){
          tiledBand[0].getOperation()->setAttr("conv_loop", UnitAttr::get(tiledBand[0]->getContext()));
        }
        // if(func.getName()=="main_graph_node33")
        //   tiledBand[0].dump();
        // Now In order to keep FIFO read-write consistency, we need to 
        // perform the same tiling strategy to the consumers
        llvm::SmallVector<AffineStoreOp> storeOps;
        tiledBand[0].walk([&](AffineStoreOp storeOp) {
          storeOps.push_back(storeOp);

        });
        auto users = storeOps.back().getMemRef().getUsers();
        size_t userCount = std::distance(users.begin(), users.end());
        // TODO: if size>1, the consumer and the producer are in the same node
        if(userCount>1 && is_depthConv || userCount>1 && need_tile){
          // TODO
          // tiledBand[0].dump();
          // skipConv = false;
          // llvm::outs() << "Found BufferOp: "<< "\n";
          for (auto user : users) {
            if (auto loadOp = dyn_cast<affine::AffineLoadOp>(user)) {
                // llvm::outs() << "This user is a LoadOp: " <<"\n";
                auto currentOp = loadOp.getOperation();
                auto parentFor = currentOp->getParentOfType<mlir::affine::AffineForOp>();
                getLoopBandFromOutermost(parentFor, band);
                SmallVector<unsigned, 8> tileList2({tilesize});
                AffineLoopBand tiledBand2;

                tilePerfectlyNested(band, tileList2, &tiledBand2);
                (void)normalizeAffineFor(tiledBand2[0]);
                (void)normalizeAffineFor(tiledBand2[1]);
                applyLoopPipelining(tiledBand2,0,1);

                // tiledBand2[0].dump();
            }
          }

        }
        // else{
        //   func.walk([&](AffineForOp newforOp) {
        //     if((newforOp->hasAttrOfType<UnitAttr>("top_loop")||forOp->hasAttrOfType<UnitAttr>("wb_loop")) && !forOp->hasAttrOfType<UnitAttr>("opted")){
        //       newforOp.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));
        //       AffineLoopBand testband;
        //       getLoopBandFromOutermost(newforOp, testband);
        //       testband.resize(1);
        //       SmallVector<unsigned, 8> testtileList({8});
        //       AffineLoopBand testtiledBand;
        //       if(testband[3].getUpperBoundMap().getSingleConstantResult()>8){
        //           tilePerfectlyNested(band, testtileList, &testtiledBand);
        //           (void)normalizeAffineFor(testtiledBand[0]);
        //           (void)normalizeAffineFor(testtiledBand[1]);
        //           applyLoopPipelining(testtiledBand,0,1);
        //           applyFullyLoopUnrolling(*testtiledBand[0].getBody()); 
        //       }
        //     }
        //   });
        // }
        if(userCount==1 || userCount>1 && is_depthConv || userCount>1 && need_tile){
          for (const auto &dependency : producerToConsumers[func]) {
            func::FuncOp consumerFunc = dependency.consumer;
            int consumerIndex = dependency.consumerArgIndex;
            auto consumerArg = consumerFunc.getArgument(consumerIndex);
            // consumerFunc.dump();
            if(consumerFunc->hasAttrOfType<UnitAttr>("conv_node") && !func->hasAttrOfType<UnitAttr>("conv_node")){
              return WalkResult::interrupt();
            }
            consumerFunc.walk([&](AffineLoadOp op) {
              if (auto loadOp = llvm::dyn_cast<mlir::affine::AffineLoadOp>(&op)) {
                auto target = loadOp->getMemRef();
                
                if (target == consumerArg) {
                  // llvm::outs()<<target<<"\n";
                  auto currentOp = loadOp->getOperation();
                  auto topLevelFor = currentOp->getParentOfType<mlir::affine::AffineForOp>();
                  // topLevelFor.dump();
                  AffineLoopBand topband;
                  getLoopBandFromInnermost(topLevelFor,topband);
                  if(!topLevelFor->hasAttrOfType<UnitAttr>("opted")){
                    AffineLoopBand consumerBand;
                    AffineLoopBand consumerTiledBand;
                    
                    consumerBand.push_back(topLevelFor);

                    tilePerfectlyNested(consumerBand, tileList, &consumerTiledBand);
                    (void)normalizeAffineFor(consumerTiledBand[0]);
                    (void)normalizeAffineFor(consumerTiledBand[1]);
                    // applyLoopPipelining(consumerTiledBand,0,1);
                    // if(consumerTiledBand[0].getUpperBoundMap().getSingleConstantResult()==tilesize){
                    //   applyLoopPipelining(consumerTiledBand,1,1);
                    // }else{
                      applyLoopPipelining(consumerTiledBand,0,1);
                    // }
                    // consumerTiledBand[0]->hasAttrOfType<UnitAttr>("opted");

                    if(!topband[0].getOperation()->hasAttrOfType<UnitAttr>("top_loop")){
                      // llvm::outs()<<"current: "<<"\n";
                      bool opt1, opt2 = false;
                        consumerFunc.walk([&](AffineForOp consuforOp) {
                          if(consuforOp->hasAttrOfType<UnitAttr>("top_loop")){
                            topLevelFor.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));
                            opt1 = true;
                            // llvm::outs()<<"current: "<<"\n";
                            AffineLoopBand consumerBand1;
                            AffineLoopBand consumerTiledBand1;

                            getLoopBandFromOutermost(consuforOp, consumerBand1);
                            consumerBand1[0]=consumerBand1[3];
                            consumerBand1.resize(1);
                            
                            // consumerBand1.push_back(consuforOp);

                            tilePerfectlyNested(consumerBand1, tileList, &consumerTiledBand1);
                            (void)normalizeAffineFor(consumerTiledBand1[0]);
                            (void)normalizeAffineFor(consumerTiledBand1[1]);
                            // applyLoopPipelining(consumerTiledBand1,0,1);
                            // if(consumerTiledBand1[0].getUpperBoundMap().getSingleConstantResult()==tilesize){
                            //   llvm::outs()<<"current: "<<"\n";
                            //   applyLoopPipelining(consumerTiledBand1,1,1);
                            // }else{
                              applyLoopPipelining(consumerTiledBand1,0,1);
                            // }
                            // return WalkResult::interrupt();
                            // applyFullyLoopUnrolling(*consumerTiledBand1[0].getBody());

                          }else if(consuforOp->hasAttrOfType<UnitAttr>("wb_loop")){
                            topLevelFor.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));
                            opt2 = true;
                            AffineLoopBand consumerBand1;
                            AffineLoopBand consumerTiledBand1;

                            getLoopBandFromOutermost(consuforOp, consumerBand1);
                            // consumerBand1[0]=consumerBand1[3];
                            consumerBand1.resize(1);
                            
                            // consumerBand1.push_back(consuforOp);

                            tilePerfectlyNested(consumerBand1, tileList, &consumerTiledBand1);
                            (void)normalizeAffineFor(consumerTiledBand1[0]);
                            (void)normalizeAffineFor(consumerTiledBand1[1]);
                            // if(consumerTiledBand1[0].getUpperBoundMap().getSingleConstantResult()==tilesize){
                            //   applyLoopPipelining(consumerTiledBand1,1,1);
                            // }else{
                              applyLoopPipelining(consumerTiledBand1,0,1);
                            // }
                            // return WalkResult::interrupt();
                            
                            // applyFullyLoopUnrolling(*consumerTiledBand1[0].getBody());
                          }
                          // if(opt1==true&&opt2==true){
                          //   return WalkResult::interrupt();
                          // }
                        });
                      
                    }else{
                      consumerFunc.walk([&](AffineForOp consuforOp) {
                          if(consuforOp->hasAttrOfType<UnitAttr>("wb_loop")){
                            topLevelFor.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));
                            // opt2 = true;
                            AffineLoopBand consumerBand1;
                            AffineLoopBand consumerTiledBand1;

                            getLoopBandFromOutermost(consuforOp, consumerBand1);
                            // consumerBand1[0]=consumerBand1[3];
                            consumerBand1.resize(1);
                            
                            // consumerBand1.push_back(consuforOp);

                            tilePerfectlyNested(consumerBand1, tileList, &consumerTiledBand1);
                            (void)normalizeAffineFor(consumerTiledBand1[0]);
                            (void)normalizeAffineFor(consumerTiledBand1[1]);
                            // if(consumerTiledBand1[0].getUpperBoundMap().getSingleConstantResult()==tilesize){
                            //   applyLoopPipelining(consumerTiledBand1,1,1);
                            // }else{
                              applyLoopPipelining(consumerTiledBand1,0,1);
                            // }
                            // return WalkResult::interrupt();
                            
                            // applyFullyLoopUnrolling(*consumerTiledBand1[0].getBody());
                          }
                          // if(opt1==true&&opt2==true){
                          //   return WalkResult::interrupt();
                          // }
                        });

                    }
                  }

                  return WalkResult::interrupt();
                  // applyFullyLoopUnrolling(*consumerTiledBand[0].getBody()); 
                  // while (topLevelFor) {
                  //   auto parentFor = topLevelFor->getParentOfType<mlir::affine::AffineForOp>();
                  //   if (!parentFor) {
                  //       break;
                  //   }
                  //   topLevelFor = parentFor;
                  // }
                }
              }
            });
            // applyAutoArrayPartition(clonedConsumerFunc, partitionsMap, 128);
          }
   
        }
      } 
  // }
  });


  auto builder = Builder(func);
  for (auto [memref, partitions] : partitionsMap) {
    SmallVector<PartitionKind, 4> kinds;
    SmallVector<unsigned, 4> factors;
    for (auto [kind, factor] : partitions) {
      kinds.push_back(kind);
      if(factor>=96){
        factor = 32;
      }
      factors.push_back(factor);
    }
    if (llvm::any_of(kinds, [](PartitionKind kind) {
          return kind != PartitionKind::NONE;
        }))
    { 
      applyArrayPartition(memrefMapping[memref], factors, kinds, false, 1024);
    }
  }
  // Align function type with entry block argument types.
  if(!hasTopFuncAttr(func)){
    auto resultTypes = func.front().getTerminator()->getOperandTypes();
    auto inputTypes = clonedFunc.front().getArgumentTypes();
    func.setType(builder.getFunctionType(inputTypes, resultTypes));

    updateParentFunc(func, builder);
  }else{

  }


  // Update the types of all sub-functions.
  // updateSubFuncs(func, builder);

  // func.dump();
// }
  // // Explore the design space through a multiple level approach.
  // if (!exploreDesignSpace(func, directiveOnly, outputRootPath, csvRootPath))
    return clonedFunc;
}



namespace {
struct DesignSpaceExplore : public DesignSpaceExploreBase<DesignSpaceExplore> {
  DesignSpaceExplore() = default;
  DesignSpaceExplore(std::string dseTargetSpec, int dseMaxParallelismFactor, int dseAdjustParallelismCnt, float dseAdjustParallelismFactor) { 
    targetSpec = dseTargetSpec;
    MaxParallelismFactor = dseMaxParallelismFactor;
    AdjustParallelismCnt = dseAdjustParallelismCnt; 
    AdjustParallelismFactor = dseAdjustParallelismFactor;
  }

  void runOnOperation() override {
    auto module = getOperation();
    
    // Read target specification JSON file.
    std::string errorMessage;
    auto configFile = mlir::openInputFile(targetSpec, &errorMessage);
    if (!configFile) {
      llvm::errs() << errorMessage << "\n";
      return signalPassFailure();
    }

    // Parse JSON file into memory.
    auto config = llvm::json::parse(configFile->getBuffer());
    if (!config) {
      llvm::errs() << "failed to parse the target spec json file\n";
      return signalPassFailure();
    }
    auto configObj = config.get().getAsObject();
    if (!configObj) {
      llvm::errs() << "support an object in the target spec json file, found "
                      "something else\n";
      return signalPassFailure();
    }

    // Collect DSE configurations.
    unsigned outputNum = configObj->getInteger("output_num").value_or(30);

    unsigned maxInitParallel =
        configObj->getInteger("max_init_parallel").value_or(32);
    unsigned maxExplParallel =
        configObj->getInteger("max_expl_parallel").value_or(1024);
    unsigned maxLoopParallel =
        configObj->getInteger("max_loop_parallel").value_or(128);

    assert(maxInitParallel <= maxExplParallel &&
           maxLoopParallel <= maxExplParallel &&
           "invalid configuration of DSE");

    unsigned maxIterNum = configObj->getInteger("max_iter_num").value_or(30);
    float maxDistance = configObj->getNumber("max_distance").value_or(3.0);

    bool directiveOnly =
        configObj->getBoolean("directive_only").value_or(false);
    bool resourceConstr =
        configObj->getBoolean("resource_constr").value_or(true);

    // Collect profiling latency and DSP usage data, where default values are
    // based on Xilinx PYNQ-Z1 board.
    llvm::StringMap<int64_t> latencyMap;
    getLatencyMap(configObj, latencyMap);
    llvm::StringMap<int64_t> dspUsageMap; 
    codo::getDspUsageMap(configObj, dspUsageMap);

    unsigned maxDspNum = ceil(configObj->getInteger("dsp").value_or(220) * 1.1);
    if (!resourceConstr)
      maxDspNum = UINT_MAX;
    // Initialize an performance and resource estimator.
    auto estimator = codoEstimator(latencyMap, dspUsageMap, true);
    auto explorer = codoExplorer(estimator, outputNum, maxDspNum,
                                     maxInitParallel, maxExplParallel,
                                     maxLoopParallel, maxIterNum, maxDistance);

    // module.walk([&](AffineForOp forOp) {
    //     SimplyfyPool(forOp);
    // });
    module.walk([&](func::FuncOp func) {
      if (func->hasAttrOfType<UnitAttr>("conv_node")) {
        auto tripCountAttr = func.getOperation()->getAttrOfType<IntegerAttr>("tripcount");
        if (tripCountAttr) {
          int tripCount = tripCountAttr.getInt();
          funcTripCountMap[func.getName()] = tripCount;
        }
      }
    });

    // 使用常量引用遍历 funcTripCountMap，避免复制
    // for (const auto &entry : funcTripCountMap) {
    //     llvm::outs() << "Function: " << entry.getKey() << ", TripCount: " << entry.second << "\n";
    // }
    
    std::vector<std::pair<int, std::string>> tripCountList;
    for (const auto &entry : funcTripCountMap) {
        tripCountList.push_back(std::make_pair(entry.second, std::string(entry.getKey())));
    }
    
    // 按值升序排序
    std::sort(tripCountList.begin(), tripCountList.end(), 
              [](const std::pair<int, std::string>& a, const std::pair<int, std::string>& b) {
                  return a.first < b.first;
              });
    
    // Level division
    int currentLevel = 1;
    funcLevelMapping.push_back(std::make_pair(tripCountList[0].second, currentLevel));
    for (size_t i = 1; i < tripCountList.size(); ++i) {
        // Determine the difference between the current value and the previous value
        if (tripCountList[i].first <= tripCountList[i-1].first * 1.1) { // Configurable parameter: difference number
            // If the difference is within 10%, it belongs to the same level
            funcLevelMapping.push_back(std::make_pair(tripCountList[i].second, currentLevel));
        } else {
            // Otherwise, go to the next level
            currentLevel = std::min(currentLevel + 1, 4); // Configurable parameter: number of levels
            funcLevelMapping.push_back(std::make_pair(tripCountList[i].second, currentLevel));
        }
    }

    // 输出分配的梯队
    // for (const auto &entry : funcLevelMapping) {
    //     llvm::outs() << "Function: " << entry.first << ", Level: " << entry.second << "\n";
    // }








    // TODO: Node FIFO Read-Write Balance
    // llvm::outs() << "start Function list size" <<"\n";
    std::vector<func::FuncOp> funcList;
    std::vector<codo::BufferOp> bufferList;
    func::FuncOp topFunction;
    module.walk([&](func::FuncOp topFunc) {
    if (hasTopFuncAttr(topFunc)) { 
      topFunction = topFunc;
      topFunc.walk([&](BufferOp op) {
          bufferList.push_back(op);
      });
      // llvm::outs() << "Processing top function: " << topFunc.getName() << "\n";
        topFunc.walk([&](Operation *op) {
          if (auto callOp = dyn_cast<func::CallOp>(op)) {
            StringRef callee = callOp.getCallee();
            // llvm::outs() << "Found call to function: " << callee << "\n";
            module.lookupSymbol<func::FuncOp>(callee).walk([&](func::FuncOp childFunc) {
              funcList.push_back(childFunc);
              if (!childFunc->hasAttrOfType<UnitAttr>("conv_node")) {
                // TODO: Fine-grained Conflict detection between Loops
                childFunc.walk([&](BufferOp op) {
                  op.setStringAttr(StringRef("non_fifo"));
                    // bufferList.push_back(op);
                });
              }
              // llvm::outs() << "Child function: " << childFunc.getName() << "\n";
            });
          }
        });
      }
    });


    // std::reverse(funcList.begin(), funcList.end());
    // llvm::outs() << "Function list size" << funcList.size()<<"\n";
    
    llvm::DenseMap<func::FuncOp, SmallVector<func::FuncOp, 4>> funcToDeps;
    llvm::DenseMap<func::FuncOp, SmallVector<func::FuncOp, 4>> depsToFunc;
    for (size_t i = 0; i < funcList.size(); ++i) {
      auto func = funcList[i];
      // llvm::outs()<< "Function name: " << func.getName()
      //                           <<"\n";
      // if (func->hasAttrOfType<UnitAttr>("conv_node")) {
        for (size_t j = i + 1; j < funcList.size(); ++j) {
          auto nextFunc = funcList[j];
          for(auto buffer: bufferList){
            for (auto *user : buffer.getResult().getUsers()) {
              if (auto callOp = llvm::dyn_cast<mlir::func::CallOp>(user)) {
                auto callee = SymbolTable::lookupNearestSymbolFrom(callOp, callOp.getCalleeAttr());
                auto subFunc = dyn_cast<func::FuncOp>(callee);
                // Check if the current func is the callee
                if (subFunc == func) {
                  // Iterate over all other users of the buffer and create a mapping.
                  for (auto *otherUser : buffer.getResult().getUsers()) {
                    if (otherUser != user) { 
                      if (auto otherCallOp = llvm::dyn_cast<mlir::func::CallOp>(otherUser)) {
                        auto otherCallee = SymbolTable::lookupNearestSymbolFrom(otherCallOp, otherCallOp.getCalleeAttr());
                        auto otherSubFunc = dyn_cast<func::FuncOp>(otherCallee);
                        if(otherSubFunc==nextFunc){
                          // if(otherSubFunc.getOperation()->hasAttrOfType<UnitAttr>("unbalanced"))
                            // buffer.setStringAttr(StringRef("non_fifo"));
                          if(!func->hasAttrOfType<UnitAttr>("conv_node") && !otherSubFunc->hasAttrOfType<UnitAttr>("conv_node")){
                            if(!func->hasAttrOfType<UnitAttr>("pool_opted")&& !otherSubFunc->hasAttrOfType<UnitAttr>("pool_opted")){
                              buffer.setStringAttr(StringRef("non_fifo"));
                            }
                          }
                            
                          funcToDeps[func].push_back(otherSubFunc);
                          depsToFunc[otherSubFunc].push_back(func);
                          // llvm::outs()<< "Function " << nextFunc.getName()
                          //       << " is dependent on " << func.getName() 
                          //       << "\n";
                          // FIXME: Add an assertion
                          int producerIndex = -1;
                          int consumerIndex = -1;
                          for (unsigned index = 0; index < callOp.getNumOperands(); ++index) {
                            auto operand = callOp.getOperand(index);
                            if(buffer.getResult()==operand){
                              producerIndex = index;
                              // llvm::outs()<<"find the producer target value at index "<<index<<"\n";
                            }
                          }
                          for (unsigned index = 0; index < otherCallOp.getNumOperands(); ++index) {
                            auto operand = otherCallOp.getOperand(index);
                            if(buffer.getResult()==operand){
                              consumerIndex = index;
                              // llvm::outs()<<"find the consumer target value at index "<<index<<"\n";
                            }
                          }
                          assert(producerIndex >= 0 && "Producer index should be valid");
                          assert(consumerIndex >= 0 && "Consumer index should be valid");
                          producerToConsumers[func].push_back({nextFunc, producerIndex, consumerIndex});
                        }
                        
                      }
                    }   
                  }
                }
              }
            }
          }   
        }
      // }
    }

    for (const auto &entry : producerToConsumers) {
      func::FuncOp producerFunc = entry.first;
      // if (producerFunc->hasAttrOfType<UnitAttr>("conv_node")) {
        for (const auto &dependency : entry.second) {
          func::FuncOp consumerFunc = dependency.consumer;
          int producerIndex = dependency.producerArgIndex;
          int consumerIndex = dependency.consumerArgIndex;
          auto producerArg = producerFunc.getArgument(producerIndex);
          // llvm::outs()<<producerArg<<"\n";
          auto consumerArg = consumerFunc.getArgument(consumerIndex);

          // find the store operation in the producer argument list
          std::map<int, std::vector<int>> producerRankMap;
         
          // std::vector<int> consumerRanks;
          mlir::affine::AffineForOp  proFor;
          producerFunc.walk([&](AffineStoreOp op) {
            if (auto storeOp = llvm::dyn_cast<mlir::affine::AffineStoreOp>(&op)) {
              // 找到 store 操作的目标
              auto target = storeOp->getMemRef();
              // llvm::outs()<<target<<"\n";
              if (target == producerArg) {
                auto currentOp = storeOp->getOperation();
                auto topLevelFor = currentOp->getParentOfType<mlir::affine::AffineForOp>();
                while (topLevelFor) {
                  auto parentFor = topLevelFor->getParentOfType<mlir::affine::AffineForOp>();
                  if (!parentFor) {
                      break;
                  }
                  topLevelFor = parentFor;
                   proFor = topLevelFor;
                  
                }
                if (topLevelFor) {
                  std::vector<int> loopdepth;
                  auto indices = storeOp->getIndices();
                  // FIXME: We need a function to analysis indics like in the consumerFunc part
                  for (auto operand : indices) { 
                    int level = 0;
                    topLevelFor.walk([&](affine::AffineForOp op) {
                        level+=1;
                        auto inductionVar = op.getInductionVar();
                        if (operand == inductionVar) {
                            // llvm::outs() << "Found matching induction variable: " << inductionVar << "\n";
                            loopdepth.push_back(level);
                        }
                    });
                  }

                  // std::vector<std::pair<int, int>> indexedArr(loopdepth.size());
                  // for (int i = 0; i < loopdepth.size(); ++i) {
                  //     indexedArr[i] = {loopdepth[i], i}; 
                  //     llvm::outs()<<"index: "<<loopdepth[i]<<"\n";
                  // }
                  std::vector<int> indices1(loopdepth.size());
                  for (int i = 0; i < loopdepth.size(); ++i) {
                      indices1[i] = i; // 填充索引
                  }
                  std::sort(indices1.begin(), indices1.end(), [&](int a, int b) {
                      return loopdepth[a] > loopdepth[b]; // 从大到小排序
                  });
                  std::vector<int> indexOrder(loopdepth.size());
                  for (int i = 0; i < loopdepth.size(); ++i) {
                      indexOrder[indices1[i]] = i; // 填充原数组位置的大小次序
                  }
                  // for (int i = 0; i < loopdepth.size(); ++i) {
                  //     llvm::outs()<<"indexedArr: "<<indexOrder[i]<<"\n";
                  // }
                  // std::sort(indexedArr.begin(), indexedArr.end(), [](const auto& a, const auto& b) {
                  //     return a.first > b.first; 
                  // });
                  // std::vector<int> ranks(loopdepth.size());
                  // for (int i = 0; i < loopdepth.size(); ++i) {
                  //     ranks[i] = indexedArr[i].second ; 
                  //     llvm::outs()<<"indexedArr: "<<ranks[i]<<"\n";
                  // }
                  for (int i = 0; i < indexOrder.size(); ++i) {
                    producerRankMap[i].push_back(indexOrder[i]);
                  }
                  // for (int key = 0; key < producerRankMap.size(); ++key) {
                  //   llvm::outs() << "Key: " << key << " -> Values: ";
                  //   for (int value : producerRankMap[key]) {
                  //       llvm::outs()  << value << " ";
                  //   }
                  //   llvm::outs()  << "\n";
                  // }
                  return WalkResult::interrupt();
                }
              }
              
            }
            
          });
          
          // Consumer index access order
          std::map<int, std::vector<int>> consumerRankMap;
          consumerFunc.walk([&](AffineLoadOp op) {
            if (auto loadOp = llvm::dyn_cast<mlir::affine::AffineLoadOp>(&op)) {
              // 找到 store 操作的目标
              auto target = loadOp->getMemRef();
              // llvm::outs()<<target<<"\n";
              if (target == consumerArg) {
                auto currentOp = loadOp->getOperation();
                auto topLevelFor = currentOp->getParentOfType<mlir::affine::AffineForOp>();
                while (topLevelFor) {
                  auto parentFor = topLevelFor->getParentOfType<mlir::affine::AffineForOp>();
                  if (!parentFor) {
                      break;
                  }
                  topLevelFor = parentFor;
                }
                if (topLevelFor) {
                  std::vector<int> loopdepth;
                  auto indices = loadOp->getIndices();
                  auto affineMap = loadOp->getAffineMap();
                  auto exprs = loadOp->getAffineMap().getResults();
                  int indexDims = exprs.size();
                  std::vector<int> numberOfArgs(indexDims, 0);
                  
                  for (int dimIndex=0; dimIndex<indexDims; dimIndex++) {
                    // FIXME:Encapsulate the following code in a function
                    if (auto dimExpr = exprs[dimIndex].dyn_cast<AffineDimExpr>()) {
                      unsigned dimPosition = dimExpr.getPosition();
                      numberOfArgs[dimIndex]=1;
                    }else if (auto dimExpr = exprs[dimIndex].dyn_cast<AffineConstantExpr>()) {
                      // unsigned dimPosition = dimExpr.getPosition();
                      numberOfArgs[dimIndex]=1;
                    }
                    else if(auto dimExpr = exprs[dimIndex].dyn_cast<AffineBinaryOpExpr>()){
                      // TODO:This method needs extension, it should be a recursive function
                      if (auto outerRHS = dimExpr.getRHS().dyn_cast<AffineBinaryOpExpr>()) {
                        if (auto innerRHS = outerRHS.getRHS().dyn_cast<AffineDimExpr>()) {
                          unsigned dimPosition = innerRHS.getPosition();
                          numberOfArgs[dimIndex]+=1;
                        }
                        if(auto innerLHS = outerRHS.getLHS().dyn_cast<AffineDimExpr>()){
                          unsigned dimPosition = innerLHS.getPosition();
                          numberOfArgs[dimIndex]+=1;
                        }
                      }
                      if (auto outerLHS = dimExpr.getLHS().dyn_cast<AffineBinaryOpExpr>()) {
                        if (auto innerRHS = outerLHS.getRHS().dyn_cast<AffineDimExpr>()) {
                          unsigned dimPosition = innerRHS.getPosition();
                          numberOfArgs[dimIndex]+=1;
                          // llvm::outs()<<"dimPosition: "<<dimPosition<<"\n";
                        }
                        if(auto innerLHS = outerLHS.getLHS().dyn_cast<AffineDimExpr>()){
                          unsigned dimPosition = innerLHS.getPosition();
                          numberOfArgs[dimIndex]+=1;
                        }
                      }if(auto outerRHS = dimExpr.getRHS().dyn_cast<AffineDimExpr>()){
                          unsigned dimPosition = outerRHS.getPosition();
                          numberOfArgs[dimIndex]+=1;
                      }if(auto outerLHS = dimExpr.getLHS().dyn_cast<AffineDimExpr>()){
                          unsigned dimPosition = outerLHS.getPosition();
                          numberOfArgs[dimIndex]+=1;
                      }
                    }
                  }
                  // llvm::outs() << "indices size: " << indices.size() << "\n";
                  // llvm::outs() << "affinemap size: " << affineMap.getNumResults() << "\n";
                  // FIXME: This case indicates that there is a "0" index
                  if(indices.size()<affineMap.getNumResults()){
                      loopdepth.push_back(20);
                  }

                  for (auto operand : indices) {
                    int level = 0;
                    topLevelFor.walk([&](affine::AffineForOp op) {
                        level+=1;
                        auto inductionVar = op.getInductionVar();
                        if (operand == inductionVar) {
                            
                            loopdepth.push_back(level);
                        }
                        // else if(operand.getDefiningOp() == 0){
                        //   llvm::outs() << "Found matching induction variable: " << inductionVar << "\n";
                        //   // Else it is a "0", Normally the batch size dim
                        //   loopdepth.push_back(20);
                        //   return WalkResult::interrupt();
                        // }
                        // llvm::outs() << "Found matching induction variable: " << operand.getDefiningOp() << "\n";
                    });
                  }

                  std::vector<int> indices2(loopdepth.size());
                  for (int i = 0; i < loopdepth.size(); ++i) {
                      indices2[i] = i; // 填充索引
                  }
                  std::sort(indices2.begin(), indices2.end(), [&](int a, int b) {
                      return loopdepth[a] > loopdepth[b]; // 从大到小排序
                  });
                  std::vector<int> indexOrder2(loopdepth.size());
                  for (int i = 0; i < loopdepth.size(); ++i) {
                      indexOrder2[indices2[i]] = i; // 填充原数组位置的大小次序
                  }
                  // for (int i = 0; i < loopdepth.size(); ++i) {
                  //     llvm::outs()<<"indexedArr: "<<indexOrder2[i]<<"\n";
                  // }
                  // llvm::outs()<<"numberOfArgs.size(): "<<numberOfArgs.size()<<"\n";
                  int currentIndex = 0; 
                  for (int key = 0; key < numberOfArgs.size(); ++key) {
                      int count = numberOfArgs[key]; 
                      for (int i = 0; i < count && currentIndex < indexOrder2.size(); ++i) {
                          consumerRankMap[key].push_back(indexOrder2[currentIndex]);
                          currentIndex++;
                      }
                  }
                  // for (int key = 0; key < consumerRankMap.size(); ++key) {
                  //   llvm::outs() << "Key: " << key << " -> Values: ";
                  //   for (int value : consumerRankMap[key]) {
                  //       llvm::outs()  << value << " ";
                  //   }
                  //   llvm::outs()  << "\n";
                  // }
                  
                  
                  std::map<int, bool> opted;
                  int optSize=0;
                  int bias = 0;
                  int counter = 0;
                  while(optSize<producerRankMap.size()){
                    // llvm::outs()<<"iteration: "  << "\n";
                    for(int key = 0; key < producerRankMap.size(); ++key){
                    // We assume producerRankMap.second.size()==1
                      // assert(producerRankMap[key].size()==1 && "producerRankMap.second.size() is not 1!");
                      
                      if(opted[key]!=true){
                        for (int value : producerRankMap[key]) {
                          
                          // FIXME:Currently we only support small dims mapping to the same or larger dims
                            if(value==counter){
                              // llvm::outs()<<"value: "<<value<< "\n";
                              int cuIndex = 0;
                              int count = numberOfArgs[key]; 
                              // llvm::outs()<<"count: "<<count<< "\n";
                              producerRankMap[key].clear();
                              producerRankMap[key].push_back(value+bias);
                              // llvm::outs()<<"value+bias: "<<value+bias<< "\n";
                              for (int i = 0; i < count-1; ++i) {
                                  producerRankMap[key].push_back(value+bias+i+1);
                                  currentIndex++;
                                  
                              }
                              bias+=count-1;
                              counter++; 
                              opted[key]=true;
                             
                              optSize+=1;
                              break;
                            }  
                        }
                      }
                    }
                    
                    // optSize = opted.size();
                    // llvm::outs()<<"optSize: "<<optSize  << "\n";
                    // llvm::outs()<<"counter: "<<counter  << "\n";
                  }
                  std::vector<int> targetOrder;
                  std::vector<int> currentOrder;
                  std::map<int, int> permMap;
                  std::map<int, int> rePermMap;
                  SmallVector<unsigned, 6> targetPerm;
                  SmallVector<unsigned, 6> targetRePerm;
                  
                  for (int key = 0; key < producerRankMap.size(); ++key) {
                    // llvm::outs() << "Key: " << key << " -> Values: ";
                    for (int value : producerRankMap[key]) {
                        targetOrder.push_back(value);
                        // llvm::outs()  << value << " ";
                    }
                    // llvm::outs()  << "\n";

                  }

                  for (int key = 0; key < consumerRankMap.size(); ++key) {
                    // llvm::outs() << "Key: " << key << " -> Values: ";
                    for (int value : consumerRankMap[key]) {
                        currentOrder.push_back(value);
                        // llvm::outs()  << value << " ";
                    }
                    // llvm::outs()  << "\n";

                  }
                  

                                      
                  for(int i=0; i<targetOrder.size(); i++){
                    permMap[currentOrder[i]]=targetOrder[i];
                    rePermMap[targetOrder[i]]=currentOrder[i];
                  }
                  for (int key = 0; key < permMap.size(); ++key) {
                    // llvm::outs() << "Key: " << key << " -> Values: ";
                    // for (int value : permMap[key]) {
                    targetPerm.push_back(permMap[key]);
                    targetRePerm.push_back(rePermMap[key]);
                    // llvm::outs() << permMap[key] << "\n";
                    // llvm::outs() << rePermMap[key] << "\n";
                    // }
                  }

                  // SmallVector<unsigned, 6> permMap = {0,5,3,1,2,4};
                  // SmallVector<unsigned, 6> permMap = {0,1,3,2,4,5};
                  AffineLoopBand band;
                  if(producerFunc->hasAttrOfType<UnitAttr>("conv_node")&&!consumerFunc->hasAttrOfType<UnitAttr>("conv_node")){
                      
                      getLoopBandFromOutermost(topLevelFor, band);
                      // llvm::outs() << "Here 1: " << " \n ";
                      // FIXME
                      if(band.size()<4){
                        // linear. do nothing
                        // llvm::outs() << "-------------------: " << " \n ";
                        // llvm::outs() << band.size() << " \n ";
                        // band[0].dump();
                        // for(auto temp: targetPerm){
                        //   llvm::outs()<<"temp: "<<temp<<"\n";
                        // }
                        // consumerArg.(non_fifo)
                        // FuncOp topFunc = consumerFunc.getParentOfType<func::FuncOp>();  // 获取顶层函数
                        topFunction.walk([&](Operation *op) {
                          if (auto callOp = dyn_cast<func::CallOp>(op)) {
                            StringRef callee = callOp.getCallee();
                            module.lookupSymbol<func::FuncOp>(callee).walk([&](func::FuncOp childFunc) {
                              // funcList.push_back(childFunc);
                              if(childFunc == consumerFunc){
                                  auto buffer = childFunc.getArguments()[consumerIndex];
                                  auto secondParam = callOp.getOperands()[consumerIndex];
                                  // auto targetBufferOp = secondParam.getDefiningOp();
                                  auto targetBufferOp = dyn_cast<codo::BufferOp>(secondParam.getDefiningOp());

                                  targetBufferOp.setStringAttr(StringRef("non_fifo"));
                                  // targetBufferOp->setAttr("non_fifo", StringAttr::get(targetBufferOp->getContext(), "true"));
                                  
                                  
                           
                                  llvm::outs()<<"get: "<<buffer<<"\n";
                                  llvm::outs()<<"get: "<<targetBufferOp<<"\n";
                                  
                              }
                                
                            });
                          }
                        });
                        // op.setStringAttr(StringRef("non_fifo"));
                      }else{
                        permuteLoops(band, targetPerm);
                        topLevelFor.getOperation()->setAttr("conv_guided_opt", UnitAttr::get(topLevelFor->getContext()));
                      }
                      
                      
                  }
                  if(!producerFunc->hasAttrOfType<UnitAttr>("conv_node")&&consumerFunc->hasAttrOfType<UnitAttr>("conv_node")){
                      // llvm::outs()<<"func name:"<<producerFunc.getName()<<"\n";
                      // llvm::outs()<<"func name:"<<consumerFunc.getName()<<"\n";
                      proFor.getOperation()->setAttr("conv_guided_opt", UnitAttr::get( proFor->getContext()));
                      getLoopBandFromOutermost(proFor, band);
                      // llvm::outs() << "Here 222222222222222222222: " << " \n ";
                      // band[0].dump();
                      // SmallVector<unsigned, 6> permMap2 = {3,0,1,2};
                      // for(auto temp: targetPerm){
                      //   llvm::outs()<<"temp: "<<temp<<"\n";
                      // }
                      // FIXME: ResNet18-small, targetRePerm=2！
                      if(band.size()>=targetRePerm.size()&&targetRePerm.size()>=4){
                          band.resize(4);
                          permuteLoops(band, targetRePerm);
                      }else{}
                      
                      
                      // permuteLoops(band, targetRePerm);
                  }
                  // if(!producerFunc->hasAttrOfType<UnitAttr>("conv_node")&&!consumerFunc->hasAttrOfType<UnitAttr>("conv_node")){
                  //     getLoopBandFromOutermost(topLevelFor, band);
                  //     band[0].dump();
                  //     // permuteLoops(band, targetPerm);
                  // }
                  
                  // forOp.dump();
                  
                  // permuteLoops(band, targetPerm);
                  // band[0].dump();
                  return WalkResult::interrupt();
                }
              }
            }
          });
          
        }
      // }
    }

    for (const auto &entry : producerToConsumers) {
      func::FuncOp producerFunc = entry.first;
      // if (producerFunc->hasAttrOfType<UnitAttr>("conv_node")) {
        for (const auto &dependency : entry.second) {
          func::FuncOp consumerFunc = dependency.consumer;
          int producerIndex = dependency.producerArgIndex;
          int consumerIndex = dependency.consumerArgIndex;
          auto producerArg = producerFunc.getArgument(producerIndex);
          // llvm::outs()<<producerArg<<"\n";
          auto consumerArg = consumerFunc.getArgument(consumerIndex);

          // find the store operation in the producer argument list
          std::map<int, std::vector<int>> producerRankMap;
         
          // std::vector<int> consumerRanks;
          mlir::affine::AffineForOp  proFor;
          producerFunc.walk([&](AffineStoreOp op) {
            if (auto storeOp = llvm::dyn_cast<mlir::affine::AffineStoreOp>(&op)) {
              // 找到 store 操作的目标
              auto target = storeOp->getMemRef();
              // llvm::outs()<<target<<"\n";
              if (target == producerArg) {
                auto currentOp = storeOp->getOperation();
                auto topLevelFor = currentOp->getParentOfType<mlir::affine::AffineForOp>();
                while (topLevelFor) {
                  auto parentFor = topLevelFor->getParentOfType<mlir::affine::AffineForOp>();
                  if (!parentFor) {
                      break;
                  }
                  topLevelFor = parentFor;
                   proFor = topLevelFor;
                  
                }
                if (topLevelFor) {
                  std::vector<int> loopdepth;
                  auto indices = storeOp->getIndices();
                  // FIXME: We need a function to analysis indics like in the consumerFunc part
                  for (auto operand : indices) { 
                    int level = 0;
                    topLevelFor.walk([&](affine::AffineForOp op) {
                        level+=1;
                        auto inductionVar = op.getInductionVar();
                        if (operand == inductionVar) {
                            // llvm::outs() << "Found matching induction variable: " << inductionVar << "\n";
                            loopdepth.push_back(level);
                        }
                    });
                  }

                  // std::vector<std::pair<int, int>> indexedArr(loopdepth.size());

                  std::vector<int> indices1(loopdepth.size());
                  for (int i = 0; i < loopdepth.size(); ++i) {
                      indices1[i] = i; // 填充索引
                  }
                  std::sort(indices1.begin(), indices1.end(), [&](int a, int b) {
                      return loopdepth[a] > loopdepth[b]; // 从大到小排序
                  });
                  std::vector<int> indexOrder(loopdepth.size());
                  for (int i = 0; i < loopdepth.size(); ++i) {
                      indexOrder[indices1[i]] = i; // 填充原数组位置的大小次序
                  }
                  // for (int i = 0; i < loopdepth.size(); ++i) {
                  //     llvm::outs()<<"indexedArr: "<<indexOrder[i]<<"\n";
                  // }
                  // std::sort(indexedArr.begin(), indexedArr.end(), [](const auto& a, const auto& b) {
                  //     return a.first > b.first; 
                  // });
                  // std::vector<int> ranks(loopdepth.size());
                  // for (int i = 0; i < loopdepth.size(); ++i) {
                  //     ranks[i] = indexedArr[i].second ; 
                  //     llvm::outs()<<"indexedArr: "<<ranks[i]<<"\n";
                  // }
                  for (int i = 0; i < indexOrder.size(); ++i) {
                    producerRankMap[i].push_back(indexOrder[i]);
                  }
                  // for (int key = 0; key < producerRankMap.size(); ++key) {
                  //   llvm::outs() << "Key: " << key << " -> Values: ";
                  //   for (int value : producerRankMap[key]) {
                  //       llvm::outs()  << value << " ";
                  //   }
                  //   llvm::outs()  << "\n";
                  // }
                  return WalkResult::interrupt();
                }
              }
              
            }
            
          });
          
          // Consumer index access order
          std::map<int, std::vector<int>> consumerRankMap;
          consumerFunc.walk([&](AffineLoadOp op) {
            if (auto loadOp = llvm::dyn_cast<mlir::affine::AffineLoadOp>(&op)) {
              // 找到 store 操作的目标
              auto target = loadOp->getMemRef();
              // llvm::outs()<<target<<"\n";
              if (target == consumerArg) {
                auto currentOp = loadOp->getOperation();
                auto topLevelFor = currentOp->getParentOfType<mlir::affine::AffineForOp>();
                while (topLevelFor) {
                  auto parentFor = topLevelFor->getParentOfType<mlir::affine::AffineForOp>();
                  if (!parentFor) {
                      break;
                  }
                  topLevelFor = parentFor;
                }
                if (topLevelFor) {
                  std::vector<int> loopdepth;
                  auto indices = loadOp->getIndices();
                  auto affineMap = loadOp->getAffineMap();
                  auto exprs = loadOp->getAffineMap().getResults();
                  int indexDims = exprs.size();
                  std::vector<int> numberOfArgs(indexDims, 0);
                  
                  for (int dimIndex=0; dimIndex<indexDims; dimIndex++) {
                    // FIXME:Encapsulate the following code in a function
                    if (auto dimExpr = exprs[dimIndex].dyn_cast<AffineDimExpr>()) {
                      unsigned dimPosition = dimExpr.getPosition();
                      numberOfArgs[dimIndex]=1;
                    }else if (auto dimExpr = exprs[dimIndex].dyn_cast<AffineConstantExpr>()) {
                      // unsigned dimPosition = dimExpr.getPosition();
                      numberOfArgs[dimIndex]=1;
                    }
                    else if(auto dimExpr = exprs[dimIndex].dyn_cast<AffineBinaryOpExpr>()){
                      // TODO:This method needs extension, it should be a recursive function
                      if (auto outerRHS = dimExpr.getRHS().dyn_cast<AffineBinaryOpExpr>()) {
                        if (auto innerRHS = outerRHS.getRHS().dyn_cast<AffineDimExpr>()) {
                          unsigned dimPosition = innerRHS.getPosition();
                          numberOfArgs[dimIndex]+=1;
                        }
                        if(auto innerLHS = outerRHS.getLHS().dyn_cast<AffineDimExpr>()){
                          unsigned dimPosition = innerLHS.getPosition();
                          numberOfArgs[dimIndex]+=1;
                        }
                      }
                      if (auto outerLHS = dimExpr.getLHS().dyn_cast<AffineBinaryOpExpr>()) {
                        if (auto innerRHS = outerLHS.getRHS().dyn_cast<AffineDimExpr>()) {
                          unsigned dimPosition = innerRHS.getPosition();
                          numberOfArgs[dimIndex]+=1;
                          // llvm::outs()<<"dimPosition: "<<dimPosition<<"\n";
                        }
                        if(auto innerLHS = outerLHS.getLHS().dyn_cast<AffineDimExpr>()){
                          unsigned dimPosition = innerLHS.getPosition();
                          numberOfArgs[dimIndex]+=1;
                        }
                      }if(auto outerRHS = dimExpr.getRHS().dyn_cast<AffineDimExpr>()){
                          unsigned dimPosition = outerRHS.getPosition();
                          numberOfArgs[dimIndex]+=1;
                      }if(auto outerLHS = dimExpr.getLHS().dyn_cast<AffineDimExpr>()){
                          unsigned dimPosition = outerLHS.getPosition();
                          numberOfArgs[dimIndex]+=1;
                      }
                    }
                  }
                  // llvm::outs() << "indices size: " << indices.size() << "\n";
                  // llvm::outs() << "affinemap size: " << affineMap.getNumResults() << "\n";
                  // FIXME: This case indicates that there is a "0" index
                  if(indices.size()<affineMap.getNumResults()){
                      loopdepth.push_back(65536);
                  }

                  for (auto operand : indices) {
                    int level = 0;
                    topLevelFor.walk([&](affine::AffineForOp op) {
                        level+=1;
                        auto inductionVar = op.getInductionVar();
                        if (operand == inductionVar) {
                            
                            loopdepth.push_back(level);
                        }
                        // else if(operand.getDefiningOp() == 0){
                        //   llvm::outs() << "Found matching induction variable: " << inductionVar << "\n";
                        //   // Else it is a "0", Normally the batch size dim
                        //   loopdepth.push_back(20);
                        //   return WalkResult::interrupt();
                        // }
                        // llvm::outs() << "Found matching induction variable: " << operand.getDefiningOp() << "\n";
                    });
                  }

                  
                  

                  std::vector<int> indices2(loopdepth.size());
                  for (int i = 0; i < loopdepth.size(); ++i) {
                      indices2[i] = i; // 填充索引
                  }
                  std::sort(indices2.begin(), indices2.end(), [&](int a, int b) {
                      return loopdepth[a] > loopdepth[b]; // 从大到小排序
                  });
                  std::vector<int> indexOrder2(loopdepth.size());
                  for (int i = 0; i < loopdepth.size(); ++i) {
                      indexOrder2[indices2[i]] = i; // 填充原数组位置的大小次序
                  }
    
                  // llvm::outs()<<"numberOfArgs.size(): "<<numberOfArgs.size()<<"\n";
                  int currentIndex = 0; 
                  for (int key = 0; key < numberOfArgs.size(); ++key) {
                      int count = numberOfArgs[key]; 
                      for (int i = 0; i < count && currentIndex < indexOrder2.size(); ++i) {
                          consumerRankMap[key].push_back(indexOrder2[currentIndex]);
                          currentIndex++;
                      }
                  }
                  // for (int key = 0; key < consumerRankMap.size(); ++key) {
                  //   llvm::outs() << "Key: " << key << " -> Values: ";
                  //   for (int value : consumerRankMap[key]) {
                  //       llvm::outs()  << value << " ";
                  //   }
                  //   llvm::outs()  << "\n";
                  // }
                  
                  
                  std::map<int, bool> opted;
                  int optSize=0;
                  int bias = 0;
                  int counter = 0;
                  while(optSize<producerRankMap.size()){
                    // llvm::outs()<<"iteration: "  << "\n";
                    for(int key = 0; key < producerRankMap.size(); ++key){
                    // We assume producerRankMap.second.size()==1
                      // assert(producerRankMap[key].size()==1 && "producerRankMap.second.size() is not 1!");
                      
                      if(opted[key]!=true){
                        for (int value : producerRankMap[key]) {
                          
                          // FIXME:Currently we only support small dims mapping to the same or larger dims
                            if(value==counter){
                              // llvm::outs()<<"value: "<<value<< "\n";
                              int cuIndex = 0;
                              int count = numberOfArgs[key]; 
                              // llvm::outs()<<"count: "<<count<< "\n";
                              producerRankMap[key].clear();
                              producerRankMap[key].push_back(value+bias);
                              // llvm::outs()<<"value+bias: "<<value+bias<< "\n";
                              for (int i = 0; i < count-1; ++i) {
                                  producerRankMap[key].push_back(value+bias+i+1);
                                  currentIndex++;
                                  
                              }
                              bias+=count-1;
                              counter++; 
                              opted[key]=true;
                             
                              optSize+=1;
                              break;
                            }  
                        }
                      }
                    }
                    
                    // // optSize = opted.size();
                    // llvm::outs()<<"optSize: "<<optSize  << "\n";
                    // llvm::outs()<<"counter: "<<counter  << "\n";
                  }
                  std::vector<int> targetOrder;
                  std::vector<int> currentOrder;
                  std::map<int, int> permMap;
                  std::map<int, int> rePermMap;
                  SmallVector<unsigned, 6> targetPerm;
                  SmallVector<unsigned, 6> targetRePerm;
                  
                  for (int key = 0; key < producerRankMap.size(); ++key) {
                    // llvm::outs() << "Key: " << key << " -> Values: ";
                    for (int value : producerRankMap[key]) {
                        targetOrder.push_back(value);
                        // llvm::outs()  << value << " ";
                    }
                    // llvm::outs()  << "\n";

                  }

                  for (int key = 0; key < consumerRankMap.size(); ++key) {
                    // llvm::outs() << "Key: " << key << " -> Values: ";
                    for (int value : consumerRankMap[key]) {
                        currentOrder.push_back(value);
                        // llvm::outs()  << value << " ";
                    }
                    // llvm::outs()  << "\n";

                  }
                  

                                      
                  for(int i=0; i<targetOrder.size(); i++){
                    permMap[currentOrder[i]]=targetOrder[i];
                    rePermMap[targetOrder[i]]=currentOrder[i];
                  }
                  for (int key = 0; key < permMap.size(); ++key) {
                    // llvm::outs() << "Key: " << key << " -> Values: ";
                    // for (int value : permMap[key]) {
                    targetPerm.push_back(permMap[key]);
                    targetRePerm.push_back(rePermMap[key]);
                    // llvm::outs() << permMap[key] << "\n";
                    // llvm::outs() << rePermMap[key] << "\n";
                    // }
                  }

                  // SmallVector<unsigned, 6> permMap = {0,5,3,1,2,4};
                  // SmallVector<unsigned, 6> permMap = {0,1,3,2,4,5};
                  AffineLoopBand band;

                  if(!producerFunc->hasAttrOfType<UnitAttr>("conv_node")&&!consumerFunc->hasAttrOfType<UnitAttr>("conv_node")){
                      if(topLevelFor->hasAttrOfType<UnitAttr>("conv_guided_opt")){
                          getLoopBandFromOutermost(proFor, band);
                          llvm::outs()<<"optimize producer:"<<producerFunc.getName()<<"\n";
                          // band[0].dump();
                          // TODO: General implementation
                          band.resize(4);
                          // for (int i = 0; i < loopdepth.size(); ++i) {
                          //     llvm::outs()<<"indexedArr: "<<loopdepth[i]<<"\n";
                          // }
                          permuteLoops(band, targetRePerm);
                          

                      }
                      else{
                          getLoopBandFromOutermost(topLevelFor, band);
                          // permuteLoops(band, targetPerm);
                          // llvm::outs()<<"optimize consumer:"<<consumerFunc.getName()<<"\n";
                          
                          // band[0].dump();
                      }
                      
                      // 
                  }
                  
                  // forOp.dump();
                  
                  // permuteLoops(band, targetPerm);
                  // band[0].dump();
                  return WalkResult::interrupt();
                }
              }
            }
          });
          
        }
      // }
    }



    // module.walk([&](func::FuncOp topFunc) {
    // if (hasTopFuncAttr(topFunc)) { 
    //     topFunc.walk([&](Operation *op) {
    //       if (auto callOp = dyn_cast<func::CallOp>(op)) {
    //         StringRef callee = callOp.getCallee();
    //         module.lookupSymbol<func::FuncOp>(callee).walk([&](func::FuncOp childFunc) {
    //           // funcList.push_back(childFunc);
    //           // if(childFunc.getName()=="main_graph_node33"){
    //           //   childFunc.dump();
    //           // }
    //           auto clonedFunc = explorer.applyDesignSpaceExplore(childFunc, directiveOnly, outputPath,
    //                                      csvPath);
    //           // if(func.getName()=="main_graph_node33"){
    //           //   func.dump();
    //           // }
    //           if (!hasTopFuncAttr(clonedFunc)&&clonedFunc->hasAttrOfType<UnitAttr>("conv_node")){
    //             llvm::outs()<<"func name: "+clonedFunc.getName()<<"\n";
    //             for (auto loop : clonedFunc.getOps<affine::AffineForOp>()){
    //               if((loop->hasAttrOfType<UnitAttr>("top_loop"))){
    //                 // clonedFunc.dump();
    //                 // codoEstimator(latencyMap, dspUsageMap, true).estimateLoop(loop,clonedFunc);
    //                 // estimateConvLoop(loop);
                  
    //                 // auto latency = codo::getTiming(loop).getLatency();
    //                 // llvm::outs()<<"latency: "+std::to_string(latency)<<"\n";
    //                 // auto dspNum = codo::getResource(loop).getDsp();
    //                 // llvm::outs()<<"dsp: "+std::to_string(dspNum)<<"\n";
    //                 // std::string errorMessage;
    //                 // auto csvFile = mlir::openOutputFile("/home/wczhang/codo/samples/output.mlir", &errorMessage);

    //                 // if (!csvFile) {
    //                 //     llvm::outs() << "Error opening file: " << errorMessage << "\n";
    //                 //     return;
    //                 // }

    //                 // // 将clonedFunc输出到output.mlir文件
    //                 // clonedFunc.print(csvFile);
    //                 // llvm::outs() << "clonedFunc written to output.mlir\n";

    //                 std::error_code error;
    //                 std::string s = clonedFunc.getName().str();
    //                 std::string pwd = std::filesystem::current_path().parent_path();
    //                 std::string path = pwd+"/samples/"+s+".mlir";
    //                 // llvm::outs()<<"path"<<path<<"\n";
    //                 llvm::raw_fd_ostream os(path, error);
    //                 os << *clonedFunc;

                    
    //               }
    //             }
    //           }
    //           auto builder = Builder(childFunc);
    //           updateTopFunc(childFunc, builder);
    //         });
    //       }
    //     });
    //   }
    // });

    // Optimize the top function.
    // TODO: Support to contain sub-functions.
    llvm::DenseMap<affine::AffineForOp, long> tempLatencyMap;
    llvm::DenseMap<affine::AffineForOp, long> allLatencyMap;
    for (auto func : module.getOps<func::FuncOp>()) {
      if (!hasTopFuncAttr(func)&&func->hasAttrOfType<UnitAttr>("conv_node")){
        
        llvm::outs()<<"func name: "+func.getName()<<"\n";
        auto clonedFunc = func.clone();
        explorer.applyDesignSpaceExplore(clonedFunc, 1);
        // auto builder = Builder(func);
        // updateTopFunc(func, builder);
        for (auto clonedLoop : clonedFunc.getOps<affine::AffineForOp>()){
          if((clonedLoop->hasAttrOfType<UnitAttr>("top_loop"))){
            estimateConvLoop(clonedLoop, tempLatencyMap); 
            for (auto loop : func.getOps<affine::AffineForOp>()){
              if((loop->hasAttrOfType<UnitAttr>("top_loop"))){
                allLatencyMap[loop] = tempLatencyMap[clonedLoop];
              }
            }
            // funcLatencyMap[func] = allLatencyMap[loop];
          }
        }
      }    
    }
    

    
    // for (auto func : module.getOps<func::FuncOp>()){
    //   if (!hasTopFuncAttr(func)&&func->hasAttrOfType<UnitAttr>("conv_node")){
        
    //     for (auto loop : func.getOps<affine::AffineForOp>()){
    //       if((loop->hasAttrOfType<UnitAttr>("top_loop"))){
    //         estimateConvLoop(loop, allLatencyMap); 
            
    //         // auto latency = codo::getTiming(loop).getLatency();
    //         // llvm::outs()<<"latency: "+std::to_string(latency)<<"\n";
    //         // auto dspNum = codo::getResource(loop).getDsp();
    //         // llvm::outs()<<"dsp: "+std::to_string(dspNum)<<"\n";
    //       }
    //     }
    //   }
    // }
    llvm::DenseMap<affine::AffineForOp, int> parallelismMap;
    distributeParallelism(allLatencyMap, parallelismMap, MaxParallelismFactor, AdjustParallelismCnt, AdjustParallelismFactor); 
    llvm::outs()<<"size of parallelismMap: "<<parallelismMap.size()<<"\n";
    // for (auto func : module.getOps<func::FuncOp>()) {
      
    //   if (!hasTopFuncAttr(func)&&func->hasAttrOfType<UnitAttr>("conv_node")){
    //     // applyOptStrategy(func, parallelismMap);
    //     explorer.applyDesignSpaceExplore(func, 32);
    //     auto builder = Builder(func);
    //     updateTopFunc(func, builder);
    //     updateSubFuncs(func, builder);
    //   }    
    // }
    SmallVector<func::FuncOp> childFuncList;
    for (auto func : module.getOps<func::FuncOp>()) {
      childFuncList.push_back(func);
      
      // if (!hasTopFuncAttr(func)&&func->hasAttrOfType<UnitAttr>("conv_node")){
      //   applyOptStrategy(func, parallelismMap);
      //   // explorer.applyDesignSpaceExplore(func, 32);
      //   auto builder = Builder(func);
      //   updateTopFunc(func, builder);
      //   updateSubFuncs(func, builder);
      // }    
    }
    // Reverse the order of childFuncList
    std::reverse(childFuncList.begin(), childFuncList.end());

    for (auto func : childFuncList) {
      // childFuncList.push_back(func);
      
      if (!hasTopFuncAttr(func)&&func->hasAttrOfType<UnitAttr>("conv_node")){
        applyOptStrategy(func, parallelismMap);
        // explorer.applyDesignSpaceExplore(func, 32);
        auto builder = Builder(func);
        updateTopFunc(func, builder);
        updateSubFuncs(func, builder);
      }    
    }

    // for (auto &entry : allLatencyMap) {
    //     affine::AffineForOp loop = entry.first;
    //     long loopLatency = entry.second;
    //     int loopParallelism = parallelismMap[loop];
    //     estimateConvLoop(loop, allLatencyMap); 
        
    //     auto parentFunc = loop.getOperation()->getParentOfType<func::FuncOp>();
    //     llvm::outs() 
    //         << "function name: " << parentFunc.getName() 
    //         << ", Parallelism: " << loopParallelism 
    //         << ", Latency: " << loopLatency << " cycles\n";
    // }
    
    for (auto func : module.getOps<func::FuncOp>()) {
      
      if (hasTopFuncAttr(func)){
        // explorer.applyDesignSpaceExplore(func, directiveOnly, outputPath,
        //                                  csvPath);
        auto builder = Builder(func);
        updateTopFunc(func, builder);
        updateSubFuncs(func, builder);
        // func.dump();
      }
        
    }



  }
};
} // namespace

func::FuncOp codo::applyOptStrategy(func::FuncOp func, llvm::DenseMap<affine::AffineForOp, int> parallelismMap){
  // llvm::outs()<<"parallelismMap size: "<<parallelismMap.size()<<"\n";

  // TODO: if the factor = 1, we need to skip the tiling.
  // Then we need to turn to its child loop for smaller parallelism
  int factor = 0;
  for (auto loop : func.getOps<affine::AffineForOp>()){
    if((loop->hasAttrOfType<UnitAttr>("top_loop"))){
      // llvm::outs()<<"enter: "<<factor<<"\n";
          factor = parallelismMap[loop];
      }
  }
  
  // assert(factor>0 && "Tile factor should be greater than 0");
  // llvm::outs()<<"factor: "<<factor<<"\n";
  
  auto clonedFunc = func.clone();
  // clonedFunc.dump();
  // auto clonedFunc = originalFunc.clone();

  DenseMap<Value, Value> memrefMapping;
  SmallVector<Value> memref_func;
  SmallVector<Value> memref_cloned;

  // AffineLoopBands targetBands_func;
  // getLoopBands(func.front(), targetBands_func);
  // SmallVector<Block *, 4> targetBlocks_func;
  // for (auto &band : targetBands_func){
  //     targetBlocks_func.push_back(band.back().getBody());
  // }
  for (auto arg : func.getArguments()) {
    if (auto memrefType = arg.getType().dyn_cast<MemRefType>()) {
      memref_func.push_back(arg);
    }
  }

  func.walk([&](BufferOp bufferOp) {
    memref_func.push_back(bufferOp.getResult());
    // llvm::outs() << "Found BufferOp: " << bufferOp << "\n";
  });



  // AffineLoopBands targetBands_cloned;
  // getLoopBands(clonedFunc.front(), targetBands_cloned);
  // SmallVector<Block *, 4> targetBlocks_cloned;
  //   for (auto &band : targetBands_cloned){
  //     targetBlocks_cloned.push_back(band.back().getBody());
  // }
  for (auto arg : clonedFunc.getArguments()) {
    if (auto memrefType = arg.getType().dyn_cast<MemRefType>()) {
      memref_cloned.push_back(arg);
    }
  }
  clonedFunc.walk([&](BufferOp bufferOp) {

    memref_cloned.push_back(bufferOp.getResult());
  });


  assert(memref_func.size() == memref_cloned.size() && "Mismatch in sizes");

  for (size_t i = 0; i < memref_func.size(); ++i) {
      Value originalMemRef = memref_func[i];
      Value clonedMemRef = memref_cloned[i];
      memrefMapping[clonedMemRef] = originalMemRef;

  }

  

  // int tilesize = 4;



  DenseMap<Value, SmallVector<Partition, 4>> partitionsMap;
  clonedFunc.walk([&](AffineForOp forOp) {
    // if (isa<func::FuncOp>(forOp->getParentOp())||isa<codo::TaskOp>(forOp->getParentOp())) {
      AffineLoopBand band;
      getLoopBandFromOutermost(forOp, band);
      auto bandDepth = band.size();
      // llvm::outs()<<"band size: "<<bandDepth;
      if((forOp->hasAttrOfType<UnitAttr>("conv_loop")||forOp->hasAttrOfType<UnitAttr>("io_loop")) && !forOp->hasAttrOfType<UnitAttr>("opted")){
        forOp.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));

        bool is_depthConv = false;
        bool need_tile = true;
        if(forOp->hasAttrOfType<UnitAttr>("depth_conv_loop")){
          is_depthConv = true;
          
        }
        int tilesize = factor;
        // forOp.dump();
        // Example to apply tiling using MLIR utilities
        // applyAffineLoopTiling(band[0], 2);
        if(band[1].getConstantUpperBound()>=32){
            band[0]=band[1];
            // if(band[1].getConstantUpperBound()>=64){
            //   tilesize = 1;
            // }
            // else{
            //   tilesize = 1;
            // }
            // if(band[2].getConstantUpperBound()>=16){
            //   tilesize = 8;

            // }
              
            need_tile = false;
        }
        // else if(band[0].getConstantUpperBound()>=32){
        //     // tilesize = 32;
        // }
        band.resize(1);
        SmallVector<unsigned, 8> tileList({tilesize});
        AffineLoopBand tiledBand;

        tilePerfectlyNested(band, tileList, &tiledBand);
        (void)normalizeAffineFor(tiledBand[0]);
        (void)normalizeAffineFor(tiledBand[1]);

        // Now In order to keep FIFO read-write consistency, we need to 
        // perform the same tiling strategy to the consumers
        llvm::SmallVector<AffineStoreOp> storeOps;
        tiledBand[0].walk([&](AffineStoreOp storeOp) {
          storeOps.push_back(storeOp);

        });
        // tiledBand[0].dump();
        auto users = storeOps.back().getMemRef().getUsers();
        size_t userCount = std::distance(users.begin(), users.end());
        // TODO: if size>1, the consumer and the producer are in the same node
        // bool skipConv = true;
        if(userCount>1 && is_depthConv && factor!=1 || userCount>1 && need_tile && factor!=1){
          // TODO
          // tiledBand[0].dump();
          // skipConv = false;
          // llvm::outs() << "Found BufferOp: "<< "\n";
          for (auto user : users) {
            if (auto loadOp = dyn_cast<affine::AffineLoadOp>(user)) {
                // llvm::outs() << "This user is a LoadOp: " <<"\n";
                auto currentOp = loadOp.getOperation();
                auto parentFor = currentOp->getParentOfType<mlir::affine::AffineForOp>();
                getLoopBandFromOutermost(parentFor, band);
                SmallVector<unsigned, 8> tileList2({tilesize});
                AffineLoopBand tiledBand2;

                tilePerfectlyNested(band, tileList2, &tiledBand2);
                (void)normalizeAffineFor(tiledBand2[0]);
                (void)normalizeAffineFor(tiledBand2[1]);
                applyLoopPipelining(tiledBand2,0,1);
                applyFullyLoopUnrolling(*tiledBand2[0].getBody()); 
                

                // tiledBand2[0].dump();
            }
          }

        }

        if(userCount==1 || userCount>1 && factor!=1 && is_depthConv || userCount>1 && need_tile && factor!=1){
          //FIXME:其实这里逻辑不正确，这个分支应该只适用于resnetNode33以及后面的pooling
          //正确的逻辑是如果并行的维度会影响后续的read，则后面应该做相同的优化。这个分析方法待补充，眼下是按照模型结构
          //设置的，不够general
          for (const auto &dependency : producerToConsumers[func]) {
            func::FuncOp consumerFunc = dependency.consumer;
            int consumerIndex = dependency.consumerArgIndex;
            auto consumerArg = consumerFunc.getArgument(consumerIndex);
            auto clonedConsumerFunc = consumerFunc.clone();
            auto currentSize = memref_func.size();
            if(consumerFunc->hasAttrOfType<UnitAttr>("conv_node") && !func->hasAttrOfType<UnitAttr>("conv_node")  ){
              return WalkResult::interrupt();
            }
            for (auto arg : consumerFunc.getArguments()) {
              if (auto memrefType = arg.getType().dyn_cast<MemRefType>()) {
                memref_func.push_back(arg);
              }
            }
            consumerFunc.walk([&](BufferOp bufferOp) {
              memref_func.push_back(bufferOp.getResult());
              // llvm::outs() << "Found BufferOp: " << bufferOp << "\n";
            });

            for (auto arg : clonedConsumerFunc.getArguments()) {
              if (auto memrefType = arg.getType().dyn_cast<MemRefType>()) {
                memref_cloned.push_back(arg);
              }
            }
            clonedConsumerFunc.walk([&](BufferOp bufferOp) {
              memref_cloned.push_back(bufferOp.getResult());
            });

            assert(memref_func.size() == memref_cloned.size() && "Mismatch in sizes");

            for (size_t i = currentSize; i < memref_func.size(); ++i) {
                Value originalMemRef = memref_func[i];
                Value clonedMemRef = memref_cloned[i];
                memrefMapping[clonedMemRef] = originalMemRef;
            }
            clonedConsumerFunc.walk([&](AffineLoadOp op) {
              if (auto loadOp = llvm::dyn_cast<mlir::affine::AffineLoadOp>(&op)) {
                // 找到 store 操作的目标
                auto target = loadOp->getMemRef();
                // llvm::outs()<<"target: "<<consumerArg<<"\n";
                // llvm::outs()<<"current: "<<target<<"\n";
                if (target == clonedConsumerFunc.getArgument(consumerIndex)) {
                  // llvm::outs()<<"entenr : "<<consumerArg<<"\n";
                  auto currentOp = loadOp->getOperation();
                  auto topLevelFor = currentOp->getParentOfType<mlir::affine::AffineForOp>();
                  // topLevelFor.dump();
                  AffineLoopBand topband;
                  getLoopBandFromInnermost(topLevelFor,topband);
                  if(!topLevelFor->hasAttrOfType<UnitAttr>("opted")){
                    AffineLoopBand consumerBand;
                    AffineLoopBand consumerTiledBand;
                    
                    consumerBand.push_back(topLevelFor);

                    tilePerfectlyNested(consumerBand, tileList, &consumerTiledBand);
                    (void)normalizeAffineFor(consumerTiledBand[0]);
                    (void)normalizeAffineFor(consumerTiledBand[1]);
                    // if(consumerTiledBand[0].getUpperBoundMap().getSingleConstantResult()==tilesize){
                      // applyLoopPipelining(consumerTiledBand,1,1);
                    // }else{
                      applyLoopPipelining(consumerTiledBand,0,1);
                    // }
                    // applyLoopPipelining(consumerTiledBand,0,1);
                    applyFullyLoopUnrolling(*consumerTiledBand[0].getBody()); 
                    consumerTiledBand[0].getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));
                    // topLevelFor.dump();

                    if(!topband[0].getOperation()->hasAttrOfType<UnitAttr>("top_loop")){
                      // llvm::outs()<<"current: "<<"\n";
                      bool opt1, opt2 = false;
                        clonedConsumerFunc.walk([&](AffineForOp consuforOp) {
                          if(consuforOp->hasAttrOfType<UnitAttr>("top_loop")){
                            // llvm::outs()<<"current: "<<"\n";
                            topLevelFor.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));
                            opt1= true;
                            AffineLoopBand consumerBand1;
                            AffineLoopBand consumerTiledBand1;

                            getLoopBandFromOutermost(consuforOp, consumerBand1);
                            consumerBand1[0]=consumerBand1[3];
                            consumerBand1.resize(1);
                            
                            // consumerBand1.push_back(consuforOp);

                            tilePerfectlyNested(consumerBand1, tileList, &consumerTiledBand1);
                            (void)normalizeAffineFor(consumerTiledBand1[0]);
                            (void)normalizeAffineFor(consumerTiledBand1[1]);
                            if(consumerTiledBand1[0].getUpperBoundMap().getSingleConstantResult()==tilesize){
                              applyLoopPipelining(consumerTiledBand1,1,1);
                            }else{
                              applyLoopPipelining(consumerTiledBand1,0,1);
                            }
                            
                            applyFullyLoopUnrolling(*consumerTiledBand1[0].getBody());

                          }else if(consuforOp->hasAttrOfType<UnitAttr>("wb_loop")){
                            topLevelFor.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));
                            opt2= true;
                            AffineLoopBand consumerBand1;
                            AffineLoopBand consumerTiledBand1;

                            getLoopBandFromOutermost(consuforOp, consumerBand1);
                            // consumerBand1[0]=consumerBand1[3];
                            consumerBand1.resize(1);
                            
                            // consumerBand1.push_back(consuforOp);

                            tilePerfectlyNested(consumerBand1, tileList, &consumerTiledBand1);
                            (void)normalizeAffineFor(consumerTiledBand1[0]);
                            (void)normalizeAffineFor(consumerTiledBand1[1]);
                            // if(consumerTiledBand1[0].getUpperBoundMap().getSingleConstantResult()==tilesize){
                            //   applyLoopPipelining(consumerTiledBand1,1,1);
                            // }else{
                              applyLoopPipelining(consumerTiledBand1,0,1);
                            // }
                            
                            applyFullyLoopUnrolling(*consumerTiledBand1[0].getBody());
                          }
                          // if(opt1==true&&opt2==true){
                          //   // return WalkResult::interrupt();
                          // }
                        });
                      
                    }else{
                      clonedConsumerFunc.walk([&](AffineForOp consuforOp) {
                          if(consuforOp->hasAttrOfType<UnitAttr>("wb_loop")){
                            topLevelFor.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));
                            // opt2= true;
                            AffineLoopBand consumerBand1;
                            AffineLoopBand consumerTiledBand1;

                            getLoopBandFromOutermost(consuforOp, consumerBand1);
                            // consumerBand1[0]=consumerBand1[3];
                            consumerBand1.resize(1);
                            
                            // consumerBand1.push_back(consuforOp);

                            tilePerfectlyNested(consumerBand1, tileList, &consumerTiledBand1);
                            (void)normalizeAffineFor(consumerTiledBand1[0]);
                            (void)normalizeAffineFor(consumerTiledBand1[1]);
                            if(consumerTiledBand1[0].getUpperBoundMap().getSingleConstantResult()==tilesize){
                              applyLoopPipelining(consumerTiledBand1,1,1);
                            }else{
                              applyLoopPipelining(consumerTiledBand1,0,1);
                            }
                            
                            applyFullyLoopUnrolling(*consumerTiledBand1[0].getBody());
                          }
                        });

                    }
                  
                  }
                  return WalkResult::interrupt();
                }
              }
            });
            applyAutoArrayPartition(clonedConsumerFunc, partitionsMap, 1024);
          }
   
        // }
        // for (auto *user : storeOps.back().getMemRef().getUsers()) {
        //       llvm::outs() << "User: " << *user << "\n";
        // }

      // clonedFunc.dump();
      } 
      applyLoopPipelining(tiledBand,0,1);
      applyFullyLoopUnrolling(*tiledBand[0].getBody()); 
      applyAutoArrayPartition(clonedFunc, partitionsMap, 1024);
   }
  });

  func.walk([&](AffineForOp forOp) {
    // if (isa<func::FuncOp>(forOp->getParentOp())||isa<codo::TaskOp>(forOp->getParentOp())) {
      AffineLoopBand band;
      getLoopBandFromOutermost(forOp, band);
      // auto bandDepth = band.size();
      // llvm::SmallVector<AffineStoreOp> storeOps;
      //   tiledBand[0].walk([&](AffineStoreOp storeOp) {
      //     storeOps.push_back(storeOp);

      // });

      if((forOp->hasAttrOfType<UnitAttr>("conv_loop")||forOp->hasAttrOfType<UnitAttr>("io_loop"))&& !forOp->hasAttrOfType<UnitAttr>("opted")){
        forOp.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));

        bool is_depthConv = false;
        bool need_tile = true;
        if(forOp->hasAttrOfType<UnitAttr>("depth_conv_loop")){
          is_depthConv = true;
        }

        AffineLoopBand innerBand;
        getLoopBandFromOutermost(forOp,innerBand);
        int tilesize = factor;
        // If input channel is large, we turn to optimize ci.
        // So the related FIFO array and the related loops shound 
        // have consistant opt strategy.
        bool resetConv = true;
        if(band[1].getConstantUpperBound()>=32){
          band[0]=band[1];
          resetConv = false;
          // if(band[1].getConstantUpperBound()>=64){
          //   tilesize = 1;
          // }
          // else{
          //   tilesize = 1;
          // }
          // if(band[2].getConstantUpperBound()>=16){
          //   tilesize = 8;

          // }
            
          need_tile = false;
        }
        // else if(band[0].getConstantUpperBound()>=32){
        //   tilesize = 32;
        // }
        band.resize(1);
        SmallVector<unsigned, 8> tileList({tilesize});
        AffineLoopBand tiledBand;
        
        tilePerfectlyNested(band, tileList, &tiledBand);
        (void)normalizeAffineFor(tiledBand[0]);
        (void)normalizeAffineFor(tiledBand[1]);
        applyLoopPipelining(tiledBand,0,1);

        if(resetConv == true){
          tiledBand[0].getOperation()->setAttr("conv_loop", UnitAttr::get(tiledBand[0]->getContext()));
        }
        // if(func.getName()=="main_graph_node33")
        //   tiledBand[0].dump();
        // Now In order to keep FIFO read-write consistency, we need to 
        // perform the same tiling strategy to the consumers
        llvm::SmallVector<AffineStoreOp> storeOps;
        tiledBand[0].walk([&](AffineStoreOp storeOp) {
          storeOps.push_back(storeOp);

        });
        auto users = storeOps.back().getMemRef().getUsers();
        size_t userCount = std::distance(users.begin(), users.end());
        // TODO: if size>1, the consumer and the producer are in the same node
        if(userCount>1 && is_depthConv && factor!=1  || userCount>1 && need_tile && factor!=1){
          // TODO
          // tiledBand[0].dump();
          // skipConv = false;
          // llvm::outs() << "Found BufferOp: "<< "\n";
          for (auto user : users) {
            if (auto loadOp = dyn_cast<affine::AffineLoadOp>(user)) {
                // llvm::outs() << "This user is a LoadOp: " <<"\n";
                auto currentOp = loadOp.getOperation();
                auto parentFor = currentOp->getParentOfType<mlir::affine::AffineForOp>();
                getLoopBandFromOutermost(parentFor, band);
                SmallVector<unsigned, 8> tileList2({tilesize});
                AffineLoopBand tiledBand2;

                tilePerfectlyNested(band, tileList2, &tiledBand2);
                (void)normalizeAffineFor(tiledBand2[0]);
                (void)normalizeAffineFor(tiledBand2[1]);
                applyLoopPipelining(tiledBand2,0,1);

                // tiledBand2[0].dump();
            }
          }

        }
        // else{
        //   func.walk([&](AffineForOp newforOp) {
        //     if((newforOp->hasAttrOfType<UnitAttr>("top_loop")||forOp->hasAttrOfType<UnitAttr>("wb_loop")) && !forOp->hasAttrOfType<UnitAttr>("opted")){
        //       newforOp.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));
        //       AffineLoopBand testband;
        //       getLoopBandFromOutermost(newforOp, testband);
        //       testband.resize(1);
        //       SmallVector<unsigned, 8> testtileList({8});
        //       AffineLoopBand testtiledBand;
        //       if(testband[3].getUpperBoundMap().getSingleConstantResult()>8){
        //           tilePerfectlyNested(band, testtileList, &testtiledBand);
        //           (void)normalizeAffineFor(testtiledBand[0]);
        //           (void)normalizeAffineFor(testtiledBand[1]);
        //           applyLoopPipelining(testtiledBand,0,1);
        //           applyFullyLoopUnrolling(*testtiledBand[0].getBody()); 
        //       }
        //     }
        //   });
        // }
        if(userCount==1 || userCount>1 && factor!=1 && is_depthConv || userCount>1 && need_tile && factor!=1){
          for (const auto &dependency : producerToConsumers[func]) {
            func::FuncOp consumerFunc = dependency.consumer;
            int consumerIndex = dependency.consumerArgIndex;
            auto consumerArg = consumerFunc.getArgument(consumerIndex);
            // consumerFunc.dump();
            if(consumerFunc->hasAttrOfType<UnitAttr>("conv_node") && !func->hasAttrOfType<UnitAttr>("conv_node")){
              return WalkResult::interrupt();
            }
            consumerFunc.walk([&](AffineLoadOp op) {
              if (auto loadOp = llvm::dyn_cast<mlir::affine::AffineLoadOp>(&op)) {
                auto target = loadOp->getMemRef();
                
                if (target == consumerArg) {
                  // llvm::outs()<<target<<"\n";
                  auto currentOp = loadOp->getOperation();
                  auto topLevelFor = currentOp->getParentOfType<mlir::affine::AffineForOp>();
                  // topLevelFor.dump();
                  AffineLoopBand topband;
                  getLoopBandFromInnermost(topLevelFor,topband);
                  if(!topLevelFor->hasAttrOfType<UnitAttr>("opted")){
                    AffineLoopBand consumerBand;
                    AffineLoopBand consumerTiledBand;
                    
                    consumerBand.push_back(topLevelFor);

                    tilePerfectlyNested(consumerBand, tileList, &consumerTiledBand);
                    (void)normalizeAffineFor(consumerTiledBand[0]);
                    (void)normalizeAffineFor(consumerTiledBand[1]);
                    // applyLoopPipelining(consumerTiledBand,0,1);
                    // if(consumerTiledBand[0].getUpperBoundMap().getSingleConstantResult()==tilesize){
                    //   applyLoopPipelining(consumerTiledBand,1,1);
                    // }else{
                      applyLoopPipelining(consumerTiledBand,0,1);
                    // }
                    // consumerTiledBand[0]->hasAttrOfType<UnitAttr>("opted");

                    if(!topband[0].getOperation()->hasAttrOfType<UnitAttr>("top_loop")){
                      // llvm::outs()<<"current: "<<"\n";
                      bool opt1, opt2 = false;
                        consumerFunc.walk([&](AffineForOp consuforOp) {
                          if(consuforOp->hasAttrOfType<UnitAttr>("top_loop")){
                            topLevelFor.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));
                            opt1 = true;
                            // llvm::outs()<<"current: "<<"\n";
                            AffineLoopBand consumerBand1;
                            AffineLoopBand consumerTiledBand1;

                            getLoopBandFromOutermost(consuforOp, consumerBand1);
                            consumerBand1[0]=consumerBand1[3];
                            consumerBand1.resize(1);
                            
                            // consumerBand1.push_back(consuforOp);

                            tilePerfectlyNested(consumerBand1, tileList, &consumerTiledBand1);
                            (void)normalizeAffineFor(consumerTiledBand1[0]);
                            (void)normalizeAffineFor(consumerTiledBand1[1]);
                            // applyLoopPipelining(consumerTiledBand1,0,1);
                            // if(consumerTiledBand1[0].getUpperBoundMap().getSingleConstantResult()==tilesize){
                            //   llvm::outs()<<"current: "<<"\n";
                            //   applyLoopPipelining(consumerTiledBand1,1,1);
                            // }else{
                              applyLoopPipelining(consumerTiledBand1,0,1);
                            // }
                            // return WalkResult::interrupt();
                            // applyFullyLoopUnrolling(*consumerTiledBand1[0].getBody());

                          }else if(consuforOp->hasAttrOfType<UnitAttr>("wb_loop")){
                            topLevelFor.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));
                            opt2 = true;
                            AffineLoopBand consumerBand1;
                            AffineLoopBand consumerTiledBand1;

                            getLoopBandFromOutermost(consuforOp, consumerBand1);
                            // consumerBand1[0]=consumerBand1[3];
                            consumerBand1.resize(1);
                            
                            // consumerBand1.push_back(consuforOp);

                            tilePerfectlyNested(consumerBand1, tileList, &consumerTiledBand1);
                            (void)normalizeAffineFor(consumerTiledBand1[0]);
                            (void)normalizeAffineFor(consumerTiledBand1[1]);
                            // if(consumerTiledBand1[0].getUpperBoundMap().getSingleConstantResult()==tilesize){
                            //   applyLoopPipelining(consumerTiledBand1,1,1);
                            // }else{
                              applyLoopPipelining(consumerTiledBand1,0,1);
                            // }
                            // return WalkResult::interrupt();
                            
                            // applyFullyLoopUnrolling(*consumerTiledBand1[0].getBody());
                          }
                          // if(opt1==true&&opt2==true){
                          //   return WalkResult::interrupt();
                          // }
                        });
                      
                    }else{
                      consumerFunc.walk([&](AffineForOp consuforOp) {
                          if(consuforOp->hasAttrOfType<UnitAttr>("wb_loop")){
                            topLevelFor.getOperation()->setAttr("opted", UnitAttr::get(forOp->getContext()));
                            // opt2 = true;
                            AffineLoopBand consumerBand1;
                            AffineLoopBand consumerTiledBand1;

                            getLoopBandFromOutermost(consuforOp, consumerBand1);
                            // consumerBand1[0]=consumerBand1[3];
                            consumerBand1.resize(1);
                            
                            // consumerBand1.push_back(consuforOp);

                            tilePerfectlyNested(consumerBand1, tileList, &consumerTiledBand1);
                            (void)normalizeAffineFor(consumerTiledBand1[0]);
                            (void)normalizeAffineFor(consumerTiledBand1[1]);
                            // if(consumerTiledBand1[0].getUpperBoundMap().getSingleConstantResult()==tilesize){
                            //   applyLoopPipelining(consumerTiledBand1,1,1);
                            // }else{
                              applyLoopPipelining(consumerTiledBand1,0,1);
                            // }
                            // return WalkResult::interrupt();
                            
                            // applyFullyLoopUnrolling(*consumerTiledBand1[0].getBody());
                          }
                          // if(opt1==true&&opt2==true){
                          //   return WalkResult::interrupt();
                          // }
                        });

                    }
                  }

                  return WalkResult::interrupt();
                  // applyFullyLoopUnrolling(*consumerTiledBand[0].getBody()); 
                  // while (topLevelFor) {
                  //   auto parentFor = topLevelFor->getParentOfType<mlir::affine::AffineForOp>();
                  //   if (!parentFor) {
                  //       break;
                  //   }
                  //   topLevelFor = parentFor;
                  // }
                }
              }
            });
            // applyAutoArrayPartition(clonedConsumerFunc, partitionsMap, 128);
          }
   
        }
      } 
  // }
  });


  auto builder = Builder(func);
  for (auto [memref, partitions] : partitionsMap) {
    SmallVector<PartitionKind, 4> kinds;
    SmallVector<unsigned, 4> factors;
    for (auto [kind, factor] : partitions) {
      kinds.push_back(kind);
      if(factor>=96){
        factor = 32;
      }
      factors.push_back(factor);
    }
    if (llvm::any_of(kinds, [](PartitionKind kind) {
          return kind != PartitionKind::NONE;
        }))
    { 
      applyArrayPartition(memrefMapping[memref], factors, kinds, false, 1024);
    }
  }
  // Align function type with entry block argument types.
  if(!hasTopFuncAttr(func)){
    auto resultTypes = func.front().getTerminator()->getOperandTypes();
    auto inputTypes = clonedFunc.front().getArgumentTypes();
    func.setType(builder.getFunctionType(inputTypes, resultTypes));

    updateParentFunc(func, builder);
  }else{

  }
    return clonedFunc;

}

std::unique_ptr<Pass>
codo::createDesignSpaceExplorePass(std::string dseTargetSpec, int dseMaxParallelismFactor, int dseAdjustParallelismCnt, float dseAdjustParallelismFactor) {
  return std::make_unique<DesignSpaceExplore>(dseTargetSpec, dseMaxParallelismFactor, dseAdjustParallelismCnt, dseAdjustParallelismFactor);
}
