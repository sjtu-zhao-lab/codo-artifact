#include "mlir/Dialect/Affine/Analysis/LoopAnalysis.h"
#include "mlir/Dialect/Affine/LoopUtils.h"
#include "mlir/Dialect/Affine/Utils.h"
#include "codo/Transforms/Passes.h"
#include "codo/Support/Utils.h"

using namespace mlir;
using namespace codo;

/// Apply loop tiling to the input loop band and sink all intra-tile loops to
/// the innermost loop with the original loop order.
bool codo::applyLoopTiling(AffineLoopBand &band, FactorList tileList,
                               bool loopNormalize, bool annotatePointLoop) {
  assert(!band.empty() && "no loops provided");
  if (!isPerfectlyNested(band))
    return false;

  // If all tile sizes are one, we don't need to do anything but annotating all
  // loops as point loop.
  if (llvm::all_of(tileList, [](unsigned size) { return size == 1; })) {
    for (auto loop : band)
      if (annotatePointLoop)
        setPointAttr(loop);
    return true;
  }

  // llvm::outs() << "input loop band: " << "\n";
  // for (auto loop : band)
  //   loop.dump();

  // Record the original band size and attributes to make use of later.
  auto originalBandSize = band.size();
  SmallVector<std::pair<bool, bool>, 8> flags;
  for (auto loop : band)
    flags.push_back({hasParallelAttr(loop), hasPointAttr(loop)});

  // Apply loop tiling.
  AffineLoopBand tiledBand;
  if (failed(tilePerfectlyNested(band, tileList, &tiledBand)))
    return false;
  
  // llvm::outs() << "tiledBand before resize: " << "\n";
  // for (auto loop : tiledBand)
  //   loop.dump();

  // Get the tile loop band and point loop band.
  AffineLoopBand pointBand(std::next(tiledBand.begin(), originalBandSize),
                           tiledBand.end());

  
  tiledBand.resize(originalBandSize);

  for (auto zip : llvm::zip(tiledBand, pointBand, flags)) {
    auto tileLoop = std::get<0>(zip);
    auto pointLoop = std::get<1>(zip);
    auto flag = std::get<2>(zip);

    // If a tile loop is parallel, the corresponding point loop should also be
    // a parallel loop.
    if (flag.first) {
      setParallelAttr(tileLoop);
      setParallelAttr(pointLoop);
    }

    // Re-annotate the point attribute to the tile loop if required.
    if (flag.second)
      setPointAttr(tileLoop);

    // Annotate the point attribute to the point loop.
    if (annotatePointLoop)
      setPointAttr(pointLoop);
  }

  // llvm::outs() << "pointBand: " << "\n";
  // for (auto loop : pointBand)
  //   loop.dump();

  // Always normalize point loop band.
  std::reverse(pointBand.begin(), pointBand.end());
  for (auto loop : pointBand){
    // if loop trip count = 1, optimize the loop with mlir's api, else, fully unroll the loop
    // promoteIfSingleIteration(loop);
    (void)normalizeAffineFor(loop);
    loopUnrollFull(loop);

  }
  

  // llvm::outs() << "pointBand after opt: " << "\n";
  // for (auto loop : pointBand)
  //   loop.dump();

  // llvm::outs() << "tiledBand final: " << "\n";
  // for (auto loop : tiledBand){
  //   (void)normalizeAffineFor(loop);
  //   // loop.dump();
  // }
    // loop.dump();
  
  // for (auto loop : tiledBand)
  //   loop.dump();

  // llvm::outs() << "tiledBand loopNormalize: " << "\n";

  // Normalize tiled loop band if required.
  if (loopNormalize) {
    band.clear();
    for (auto loop : tiledBand){
      if (failed(promoteIfSingleIteration(loop))) {
        (void)normalizeAffineFor(loop);
        
        band.push_back(loop);
        // loop.dump();
      }
    }
      
  } else
    band = tiledBand;
  
  // llvm::outs() << "tiledBand size: " <<band.size()<< "\n";
  return true;
}

/// Reduces each tile size to the largest divisor of the corresponding trip
/// count (if the trip count is known).
void codo::adjustToDivisorsOfTripCounts(
    ArrayRef<affine::AffineForOp> band, SmallVectorImpl<unsigned> *tileSizes) {
  assert(band.size() == tileSizes->size() && "invalid tile size count");
  for (unsigned i = 0, e = band.size(); i < e; i++) {
    unsigned &tSizeAdjusted = (*tileSizes)[i];
    std::optional<uint64_t> mayConst = getConstantTripCount(band[i]);
    if (!mayConst)
      continue;
    // llvm::outs() << "getConstantTripCount: " << mayConst << "\n";
    // Adjust the tile size to largest factor of the trip count less than
    // tSize.
    uint64_t constTripCount = mayConst.value();
    // llvm::outs() << "getConstantTripCount: " << constTripCount << "\n";
    if (constTripCount > 1 && tSizeAdjusted > constTripCount / 2)
      tSizeAdjusted = constTripCount / 2;
    while (constTripCount % tSizeAdjusted != 0)
      tSizeAdjusted--;
    // llvm::outs() << "Element max: " << tSizeAdjusted << " " <<(*tileSizes)[i] << "\n";
  }
}

namespace {
/// A pass to perform loop tiling on all suitable loop nests of a Function.
struct AffineLoopTiling : public AffineLoopTilingBase<AffineLoopTiling> {
  AffineLoopTiling() = default;
  explicit AffineLoopTiling(unsigned loopTileSize) { tileSize = loopTileSize; }

  void runOnOperation() override {
    // Bands of loops to tile.
    std::vector<SmallVector<affine::AffineForOp, 8>> bands;
    getLoopBands(getOperation().front(), bands);

    // Tile each band.
    // The design of avoidMaxMinBounds can avoid invalid tile sizes 
    // that introduce min/max to the loop bound.
    for (auto &band : bands) {
      SmallVector<unsigned, 8> tileSizes(band.size(), tileSize);
      if (avoidMaxMinBounds){
        adjustToDivisorsOfTripCounts(band, &tileSizes);
      }
      // for (unsigned i = 0, e = tileSizes.size(); i < e; ++i) {
      //     llvm::outs() << "Element " << i << ": " << tileSizes[i] << "\n";
      applyLoopTiling(band, tileSizes, /*loopNormalize=*/true);
    }
  }

  // If true, tile sizes are set to avoid max/min in bounds if possible.
  bool avoidMaxMinBounds = true;
};
} // namespace

/// Creates a pass to perform loop tiling on all suitable loop nests of a
/// Function.
std::unique_ptr<Pass>
codo::createAffineLoopTilingPass(unsigned loopTileSize) {
  return std::make_unique<AffineLoopTiling>(loopTileSize);
}
