#include "codo/Support/Utils.h"

#include "codo/Dialect/CodoAttributes.h"
#include "codo/Dialect/CodoOps.h"
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/Affine/Utils.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/Affine/Analysis/LoopAnalysis.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/IntegerSet.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/Support/raw_ostream.h" 
#include "codo/Init_All_Dialects.h"
#include "codo/Transforms/Passes.h"
using namespace mlir;
using namespace mlir::affine;
using namespace codo;

// static void addMemoryOptsPipeline(PassManager &pm) {
//   // To factor out the redundant affine operations.
//   // pm.addPass(createAffineLoopNormalizePass());
//   // pm.addPass(createSimplifyAffineStructuresPass());
//   pm.addPass(createCanonicalizerPass());

//   // // To simplify the memory accessing. Note that the store forwarding is
//   // // non-trivial and has a worst case complexity of O(n^2).
//   // pm.addPass(createSimplifyAffineIfPass());
//   // pm.addPass(createAffineStoreForwardPass());

//   // // Generic common sub expression elimination.
//   // pm.addPass(createCSEPass());
//   // pm.addPass(createReduceInitialIntervalPass());
// }

/// Apply loop pipelining to the input loop, all inner loops are automatically
/// fully unrolled.
bool codo::applyLoopPipelining(AffineLoopBand &band, unsigned pipelineLoc,
                                   unsigned targetII) {
  auto targetLoop = band[pipelineLoc];

  if (auto directive = getLoopDirective(targetLoop))
    if (directive.getDataflow())
      return false;

  if (!targetLoop.getOps<func::CallOp>().empty())
    return false;

  // // All inner loops of the pipelined loop are automatically unrolled.
  // if (!applyFullyLoopUnrolling(*targetLoop.getBody()))
  //   return false;

  // Erase all loops in loop band that are inside of the pipelined loop.
  // band.resize(pipelineLoc + 1);

  setLoopDirective(targetLoop, true, targetII, false, false);

  // All outer loops that perfect nest the pipelined loop can be flattened.
  auto currentLoop = targetLoop;
  while (true) {
    if (auto outerLoop = currentLoop->getParentOfType<AffineForOp>()) {
      // Only if the current loop is the only child loop of the outer loop, the
      // outer loop can be flattened into the current loop.
      bool canFlatten = true;
      for (auto &op : outerLoop)
        if (&op != currentLoop && !isa<AffineApplyOp, AffineYieldOp>(op)) {
          canFlatten = false;
          break;
        }

      if (canFlatten) {
        currentLoop = outerLoop;
        setLoopDirective(outerLoop, false, 1, false, true);
        continue;
      }
    }
    break;
  }

  return true;
}
/// Apply memory optimizations.
// bool codo::applyMemoryOpts(func::FuncOp func) {
//   PassManager optPM(func.getContext(), "func.func");
//   // addMemoryOptsPipeline(optPM);
//   if (failed(optPM.run(func)))
//     return false;
//   return true;
// }
// Calculate partition factors through analyzing the "memrefType" and return
// them in "factors". Meanwhile, the overall partition number is calculated and
// returned as well.
int64_t codo::getPartitionFactors(MemRefType memrefType,
                                      SmallVectorImpl<int64_t> *factors) {
  int64_t accumFactor = 1;
  if (auto attr = memrefType.getLayout().dyn_cast<PartitionLayoutAttr>())
    for (auto factor : attr.getActualFactors(memrefType.getShape())) {
      accumFactor *= factor;
      if (factors)
        factors->push_back(factor);
    }
  else if (factors)
    factors->assign(memrefType.getRank(), 1);
  return accumFactor;
}

bool codo::isFullyPartitioned(MemRefType memrefType) {
  if (memrefType.getRank() == 0)
    return true;

  bool fullyPartitioned = false;
  SmallVector<int64_t, 8> factors;
  // getPartitionFactors(memrefType, &factors);

  auto shapes = memrefType.getShape();
  fullyPartitioned =
      factors == SmallVector<int64_t, 8>(shapes.begin(), shapes.end());

  return fullyPartitioned;
}

// Check if the lhsOp and rhsOp are in the same block. If so, return their
// ancestors that are located at the same block. Note that in this check,
// AffineIfOp is transparent.
std::optional<std::pair<Operation *, Operation *>>
codo::checkSameLevel(Operation *lhsOp, Operation *rhsOp) {
  // If lhsOp and rhsOp are already at the same level, return true.
  if (lhsOp->getBlock() == rhsOp->getBlock())
    return std::pair<Operation *, Operation *>(lhsOp, rhsOp);

  // Helper to get all surrounding AffineIfOps.
  auto getSurroundIfs =
      ([&](Operation *op, SmallVector<Operation *, 4> &nests) {
        nests.push_back(op);
        auto currentOp = op;
        while (true) {
          auto parentOp = currentOp->getParentOp();
          if (isa<AffineIfOp, scf::IfOp>(parentOp)) {
            nests.push_back(parentOp);
            currentOp = parentOp;
          } else
            break;
        }
      });

  SmallVector<Operation *, 4> lhsNests;
  SmallVector<Operation *, 4> rhsNests;

  getSurroundIfs(lhsOp, lhsNests);
  getSurroundIfs(rhsOp, rhsNests);

  // If any parent of lhsOp and any parent of rhsOp are at the same level,
  // return true.
  for (auto lhs : lhsNests)
    for (auto rhs : rhsNests)
      if (lhs->getBlock() == rhs->getBlock())
        return std::pair<Operation *, Operation *>(lhs, rhs);

  return std::optional<std::pair<Operation *, Operation *>>();
}


/// Returns the number of surrounding loops common to 'loopsA' and 'loopsB',
/// where each lists loops from outer-most to inner-most in loop nest.
unsigned codo::getCommonSurroundingLoops(Operation *A, Operation *B,
                                             AffineLoopBand *band) {
  SmallVector<AffineForOp, 4> loopsA, loopsB;
  getAffineForIVs(*A, &loopsA);
  getAffineForIVs(*B, &loopsB);

  unsigned minNumLoops = std::min(loopsA.size(), loopsB.size());
  unsigned numCommonLoops = 0;
  for (unsigned i = 0; i < minNumLoops; ++i) {
    if (loopsA[i] != loopsB[i])
      break;
    ++numCommonLoops;
    if (band != nullptr)
      band->push_back(loopsB[i]);
  }
  return numCommonLoops;
}

// Calculate partition factors through analyzing the "memrefType" and return
// them in "factors". Meanwhile, the overall partition number is calculated and
// returned as well.
// int64_t codo::getPartitionFactors(MemRefType memrefType,
//                                       SmallVectorImpl<int64_t> *factors) {
//   int64_t accumFactor = 1;
//   if (auto attr = memrefType.getLayout().dyn_cast<PartitionLayoutAttr>())
//     for (auto factor : attr.getActualFactors(memrefType.getShape())) {
//       accumFactor *= factor;
//       if (factors)
//         factors->push_back(factor);
//     }
//   else if (factors)
//     factors->assign(memrefType.getRank(), 1);
//   return accumFactor;
// }

/// This is method for finding the number of child loops which immediatedly
/// contained by the input operation.
unsigned codo::getChildLoopNum(Operation *op) {
  unsigned childNum = 0;
  for (auto &region : op->getRegions())
    for (auto &block : region)
      for (auto &op : block)
        if (isa<affine::AffineForOp>(op))
          ++childNum;

  return childNum;
}


/// Given a tiled loop band, return true and get the tile (tile-space) loop band
/// and the point (intra-tile) loop band. If failed, return false.
bool codo::getTileAndPointLoopBand(const AffineLoopBand &band,
                                       AffineLoopBand &tileBand,
                                       AffineLoopBand &pointBand) {
  tileBand.clear();
  pointBand.clear();
  bool isPointLoop = false;

  for (auto loop : band) {
    if (!isPointLoop && !hasPointAttr(loop))
      tileBand.push_back(loop);

    else if (isPointLoop && hasPointAttr(loop))
      pointBand.push_back(loop);

    else if (!isPointLoop && hasPointAttr(loop)) {
      isPointLoop = true;
      pointBand.push_back(loop);

    } else {
      tileBand.clear();
      pointBand.clear();
      return false;
    }
  }
  return true;
}

/// Given a loop band, return true and get the parallel loop band outsides and
/// the reduction loop band inside. If failed, return false.
bool codo::getParallelAndReductionLoopBand(const AffineLoopBand &band,
                                               AffineLoopBand &parallelBand,
                                               AffineLoopBand &reductionBand) {
  parallelBand.clear();
  reductionBand.clear();
  bool isReductionLoop = false;

  for (auto loop : band) {
    if (!isReductionLoop && (hasParallelAttr(loop) || isLoopParallel(loop)))
      parallelBand.push_back(loop);

    else if (isReductionLoop &&
             !(hasParallelAttr(loop) || isLoopParallel(loop)))
      reductionBand.push_back(loop);

    else if (!isReductionLoop &&
             !(hasParallelAttr(loop) || isLoopParallel(loop))) {
      isReductionLoop = true;
      reductionBand.push_back(loop);

    } else {
      parallelBand.clear();
      reductionBand.clear();
      return false;
    }
  }
  return true;
}


/// Collect all load and store operations in the block and return them in "map".
void codo::getMemAccessesMap(Block &block, MemAccessesMap &map,
                                 bool includeVectorTransfer) {
  for (auto &op : block) {
    if (auto load = dyn_cast<affine::AffineReadOpInterface>(op))
      map[load.getMemRef()].push_back(&op);

    else if (auto store = dyn_cast<affine::AffineWriteOpInterface>(op))
      map[store.getMemRef()].push_back(&op);

    else if (auto read = dyn_cast<vector::TransferReadOp>(op)) {
      if (includeVectorTransfer)
        map[read.getSource()].push_back(&op);

    } else if (auto write = dyn_cast<vector::TransferWriteOp>(op)) {
      if (includeVectorTransfer)
        map[write.getSource()].push_back(&op);

    } else if (op.getNumRegions()) {
      // Recursively collect memory access operations in each block.
      for (auto &region : op.getRegions())
        for (auto &block : region)
          getMemAccessesMap(block, map);
    }
  }
}

mlir::Value codo::getMemRefWrite(affine::AffineForOp forOp) {
    // get the first store operation in the loop body
    for (auto &op : *forOp.getBody()) {
      if (auto storeOp = dyn_cast<affine::AffineStoreOp>(&op)) {
        return storeOp.getMemRef();
      }
    }
    return nullptr;
}

// // Check if two loops can be fused
// bool codo::canFuseLoops(affine::AffineForOp outerLoop, affine::AffineForOp innerLoop) {
//     auto memref1 = getMemRefWrite(outerLoop);
//     auto memref2 = getMemRefWrite(innerLoop);
//     // TODO: we need more extensions
//     // For example, we can fuse two independent loops
//     return (memref1 && memref2 && memref1 == memref2);
//     // return true; 
// }

// // // Perform loop fusion
// // void codo::fuseLoops(AffineForOp outerLoop, AffineForOp innerLoop) {
// //     // ...
// // }

// void codo::fuseLoops(AffineForOp outerLoop, AffineForOp innerLoop) {
  
// }

bool codo::areLoopsWritingToSameArray(AffineForOp loop1, AffineForOp loop2) {
  // Helper function to extract all AffineStoreOps in a loop
  auto getStoreOps = [](AffineForOp loop) {
    SmallVector<AffineStoreOp, 4> storeOps;
    loop.getBody()->walk([&](AffineStoreOp storeOp) {
      storeOps.push_back(storeOp);
    });
    return storeOps;
  };
  // llvm::outs()<<"test"<<"\n";

  // Get all store operations from both loops
  SmallVector<AffineStoreOp, 4> storeOps1 = getStoreOps(loop1);
  SmallVector<AffineStoreOp, 4> storeOps2 = getStoreOps(loop2);

  // Compare the store operations to see if they target the same memory location
  for (AffineStoreOp store1 : storeOps1) {
    Value memref1 = store1.getMemRef();
    // memref1.dump();
    for (AffineStoreOp store2 : storeOps2) {
      Value memref2 = store2.getMemRef();
      // memref2.dump();
      if (memref1 == memref2) {
        return true; // Found matching memory locations
      }
    }
  }

  return false; // No matching memory locations found
}


bool codo::areLoopsWithSameLoopBounds(AffineForOp loop1, AffineForOp loop2, 
                                AffineLoopBand band1, AffineLoopBand band2) {

  SmallVector<int, 4> lblist1, ublist1, lblist2, ublist2;

  for (auto loop : band1) {
    assert(loop.hasConstantBounds() && "Cannot handle variable loop bounds!");
    lblist1.push_back(loop.getConstantLowerBound());
    ublist1.push_back(loop.getConstantUpperBound());
  }

  for (auto loop : band2) {
    assert(loop.hasConstantBounds() && "Cannot handle variable loop bounds!");
    lblist2.push_back(loop.getConstantLowerBound());
    ublist2.push_back(loop.getConstantUpperBound());
  }

  if(lblist1.size() != lblist2.size()){
    return false;
  }
  assert(lblist1.size() == lblist2.size() && "Loop bounds operand sizes must match");

  OpBuilder builder(band1[0]);
  builder.setInsertionPointAfter(band1[0]);

  for (size_t i = 0; i < lblist1.size(); ++i) {
    if(lblist1[i]!=lblist2[i] || ublist1[i]!=ublist2[i]){
      return false;
    }
  }

  // Helper function to extract all AffineStoreOps in a loop
  auto getStoreOps = [](AffineForOp loop) {
    SmallVector<AffineStoreOp, 4> storeOps;
    loop.getBody()->walk([&](AffineStoreOp storeOp) {
      storeOps.push_back(storeOp);
    });
    return storeOps;
  };

  // Get all store operations from both loops
  SmallVector<AffineStoreOp, 4> storeOps1 = getStoreOps(loop1);
  SmallVector<AffineStoreOp, 4> storeOps2 = getStoreOps(loop2);

  // Compare the store operations to see if they target the same memory location
  for (AffineStoreOp store1 : storeOps1) {
    Value memref1 = store1.getMemRef();
    for (AffineStoreOp store2 : storeOps2) {
      Value memref2 = store2.getMemRef();
      if (memref1 == memref2) {
        return false; // Found matching memory locations
      }
    }
  }

  return true; 
}

// void codo::replaceSymbolsWithInductionVars(Operation *op, ValueMapping &ivMap) {
//   op->walk([&](AffineStoreOp storeOp) {
//     auto map = storeOp.getAffineMap();
//     SmallVector<AffineExpr, 4> newExprs;

//     // Iterate over the original map expressions
//     for (auto expr : map.getResults()) {
//       // Check if the expression is a symbol plus a constant (e.g., symbol(%arg5) + 3)
//       if (auto symExpr = expr.dyn_cast<AffineSymbolExpr>()) {
//         auto symValue = storeOp.getOperand(map.getNumDims() + symExpr.getPosition());
        
//         // If the symbol is an induction variable, replace it
//         if (ivMap.contains(symValue)) {
//           AffineExpr newExpr = ivMap.lookup(symValue);

//           // If there is any additional arithmetic operation, handle it (e.g., +3)
//           if (auto binExpr = expr.dyn_cast<AffineBinaryOpExpr>()) {
//             newExpr = binExpr.clone(binExpr.getLHS(), binExpr.getRHS());
//           }

//           newExprs.push_back(newExpr);
//         } else {
//           newExprs.push_back(expr);
//         }
//       } else {
//         newExprs.push_back(expr);
//       }
//     }

//     // Create a new map with the updated expressions
//     auto newMap = AffineMap::get(map.getNumDims(), map.getNumSymbols(), newExprs, op->getContext());
//     storeOp.setAffineMap(newMap);
//   });
// }

void codo::replaceSymbolsWithInductionVars(AffineStoreOp storeOp) {
  // Get the AffineMap from the store operation.
  AffineMap map = storeOp.getAffineMap();

  // Get the operands used by the store operation.
  SmallVector<Value, 4> operands(storeOp.getMapOperands());

  // Create a builder to insert new operations.
  OpBuilder builder(storeOp);

  // Get the surrounding loop nest for the store operation.
  AffineLoopBand surroundingLoops;
  auto loop = storeOp.getOperation()->getParentOfType<AffineForOp>();
  getLoopBandFromInnermost(loop, surroundingLoops);

  // Create a new list of indices for the updated store operation.
  // SmallVector<Value, 4> newIndices;

  SmallVector<mlir::Value> newIndices;
  SmallVector<mlir::AffineExpr> newArgs;
  for(auto loop: surroundingLoops){
    newIndices.push_back(loop.getInductionVar());
  }

  // Iterate through each of the map's results.
  for (unsigned i = 0, e = map.getNumResults(); i < e; ++i) {
    AffineExpr expr = map.getResult(i);
    // Check if it's a binary operation.
    if (auto binExpr = expr.dyn_cast<AffineBinaryOpExpr>()) {
      AffineExpr leftValue, rightValue;
      bool leftIsIndVar = false;
      // Handle the left-hand side.
      if (auto symExpr = binExpr.getLHS().dyn_cast<AffineSymbolExpr>()) {
        Value symValue = operands[map.getNumDims() + symExpr.getPosition()];
        for(int j =0; j<surroundingLoops.size(); j++){
          if (surroundingLoops[j].getInductionVar() == symValue) {
            leftValue = builder.getAffineDimExpr(j);
            leftIsIndVar = true;
            break;
          }
        }
        if (!leftIsIndVar) leftValue = builder.getAffineDimExpr(i);
      } else {
        leftValue = builder.getAffineDimExpr(i); // Original left value.
      }

      // Handle the right-hand side if it's a constant.
      if (auto constExpr = binExpr.getRHS().dyn_cast<AffineConstantExpr>()) {
        int64_t constantValue = constExpr.getValue();
        // Add the constant to the left value (which could be an induction variable).
        newArgs.push_back(leftValue+constExpr);
      } 

    } else {
      // If it's not a symbol or binary expression, just use the original expression result.
      newArgs.push_back(builder.getAffineDimExpr(i));
    }
  }

  // Now create a new AffineStoreOp with the updated indices.
  builder.setInsertionPoint(storeOp);

  auto placeholder_map = mlir::AffineMap::get(newIndices.size(), 0, ArrayRef<mlir::AffineExpr> (newArgs),builder.getContext());
  mlir::ValueRange placeholder_vr=ValueRange(newIndices);
  builder.create<AffineStoreOp>(storeOp.getLoc(), storeOp.getValueToStore(),
                                storeOp.getMemRef(), placeholder_map, placeholder_vr);
// auto store1 = builder.create<mlir::AffineStoreOp>(builder.getUnknownLoc(), arg_1, mem, placeholder_map, placeholder_vr);
  // Erase the old store operation.
  storeOp.erase();
}


void codo::fuseLoopsWritingToSameArray(AffineLoopBand band1, AffineLoopBand band2) {

  // FIXME:Currently only support loops that only contains one store operation;

  SmallVector<int, 8> lblist1, ublist1, lblist2, ublist2;

  for (auto loop : band1) {
    assert(loop.hasConstantBounds() && "Cannot handle variable loop bounds!");
    lblist1.push_back(loop.getConstantLowerBound());
    ublist1.push_back(loop.getConstantUpperBound());
  }

  for (auto loop : band2) {
    assert(loop.hasConstantBounds() && "Cannot handle variable loop bounds!");
    lblist2.push_back(loop.getConstantLowerBound());
    ublist2.push_back(loop.getConstantUpperBound());
  }

  assert(lblist1.size() == lblist2.size() && "Loop bounds operand sizes must match");

  OpBuilder builder(band1[0]);
  builder.setInsertionPointAfter(band1[0]);
  

  SmallVector<AffineForOp, 8> fusedLoops;
  for (size_t i = 0; i < lblist1.size(); ++i) {
    int minLowerBound = std::min(lblist1[i], lblist2[i]);
    int maxUpperBound = std::max(ublist1[i], ublist2[i]);

    auto fusedLoop = builder.create<AffineForOp>(
        builder.getUnknownLoc(), minLowerBound, maxUpperBound);
    fusedLoops.push_back(fusedLoop);

    builder.setInsertionPointToStart(fusedLoop.getBody());
  }

  bool needIfOpBand1 = false, needIfOpBand2 = false;
  SmallVector<AffineExpr, 8> ifExprsBand1, ifExprsBand2;
  SmallVector<Value, 8> ifOperandsBand1, ifOperandsBand2;
  SmallVector<bool, 8> ifEqFlags1, ifEqFlags2;
  AffineIfOp ifOp1, ifOp2;

  for (size_t i = 0; i < band1.size(); ++i) {
    if (lblist1[i] > fusedLoops[i].getConstantLowerBound() || ublist1[i] < fusedLoops[i].getConstantUpperBound()) {
      // llvm::outs()<<"iteration level: "<<i<<"\n";
      needIfOpBand1 = true;
      ifExprsBand1.push_back(ublist1[i] - builder.getAffineDimExpr(i) - 1);
      ifEqFlags1.push_back(false);
    }
    ifOperandsBand1.push_back(fusedLoops[i].getInductionVar());
  }

  // Handle band2
  for (size_t i = 0; i < band2.size(); ++i) {
    if (lblist2[i] > fusedLoops[i].getConstantLowerBound() || ublist2[i] < fusedLoops[i].getConstantUpperBound()) {
      needIfOpBand2 = true;
      ifExprsBand2.push_back(ublist2[i] - builder.getAffineDimExpr(i)  - 1);
      ifEqFlags2.push_back(false);
    }
    ifOperandsBand2.push_back(fusedLoops[i].getInductionVar());
  }

  if (needIfOpBand1) {

    auto ifCondition = IntegerSet::get(ifOperandsBand1.size(), 0, ifExprsBand1, ifEqFlags1);
    ifOp1 = builder.create<AffineIfOp>(builder.getUnknownLoc(), ifCondition, ifOperandsBand1,/*withElseRegion=*/false);
    // ifOp1.dump();
    builder.setInsertionPointToStart(ifOp1.getThenBlock());
  }

  

  // Map to track old to new induction variables and operations
  DenseMap<Operation *, Operation *> oldToNewOpMap; 
  SmallVector<Operation *> targetStoreOp;
  // AffineMap theMap;

  // Populate newOperands
  SmallVector<Value, 8> newOperands;
  SmallVector<Value, 8> oldOperandsBand1;
  SmallVector<Value, 8> oldOperandsBand2;

  // Create the temp buffer which stores the conv results
  // FloatAttr floatZero = builder.getFloatAttr(builder.getF32Type(), 0.0);
  // auto initValue = builder.create<mlir::arith::ConstantOp>(builder.getUnknownLoc(), floatZero);
  if(needIfOpBand1||needIfOpBand2){
    auto temp_buffer_type = mlir::MemRefType::get({}, builder.getF32Type());
    auto new_temp_buffer_type = MemRefType::get(
          temp_buffer_type.getShape(), temp_buffer_type.getElementType(),temp_buffer_type.getLayout().getAffineMap(),
          MemoryKindAttr::get(temp_buffer_type.getContext(), MemoryKind::BRAM_2P));
    auto temp_buffer = builder.create<BufferOp>(builder.getUnknownLoc(), new_temp_buffer_type);

    // auto storeInitValue = builder.create<mlir::affine::AffineStoreOp>(
    //       builder.getUnknownLoc(), initValue, temp_buffer, ValueRange());
    
    temp_buffer.setStringAttr(StringRef("reuse_buffer"));
    
    for (size_t i = 0; i < band1.size(); ++i) {
      oldOperandsBand1.push_back(band1[i].getInductionVar());
      oldOperandsBand2.push_back(band2[i].getInductionVar());
      newOperands.push_back(fusedLoops[i].getInductionVar());
    }



    for (auto &op : band1.back().getBody()->getOperations()) {
      if (auto loadOp = dyn_cast<AffineLoadOp>(&op)) {
        AffineMap oldMap = loadOp.getAffineMap();
        SmallVector<Value, 8> oldOperands = loadOp.getMapOperands();
        SmallVector<Value, 8> newOperandsUsed;
        // llvm::outs()<<"oldOperands:"<<oldOperands.size()<<"\n";
        for (unsigned i = 0; i < oldOperands.size(); ++i) {
          for (int j = 0; j < oldOperandsBand1.size(); ++j) {
              if (oldOperands[i] == oldOperandsBand1[j]) {
                  newOperandsUsed.push_back(newOperands[j]);
              }
          }
        }
        auto newLoad = builder.create<AffineLoadOp>(builder.getUnknownLoc(), loadOp.getMemRef(), oldMap, ValueRange(newOperandsUsed));
        oldToNewOpMap[&op] = newLoad;
      } else if (auto storeOp = dyn_cast<AffineStoreOp>(&op)) {
        Value newValueToStore = storeOp.getValueToStore();

        // Check if the value being stored was produced by a previous operation and needs to be replaced
        if (oldToNewOpMap.count(newValueToStore.getDefiningOp())) {
          newValueToStore = oldToNewOpMap[newValueToStore.getDefiningOp()]->getResult(0);
        }

        AffineMap oldMap = storeOp.getAffineMap();
        SmallVector<Value, 8> oldOperands = storeOp.getMapOperands();
        SmallVector<Value, 8> newOperandsUsed;
        for (unsigned i = 0; i < oldOperands.size(); ++i) {
          if (auto iv = oldOperands[i].dyn_cast<BlockArgument>()) {
            if (iv.getOwner() == band1[0].getBody()) {
              unsigned position = iv.getArgNumber();
              newOperandsUsed.push_back(fusedLoops[position].getInductionVar());
            } else {
              newOperandsUsed.push_back(oldOperands[i]);  // Non-induction variable operand
            }
          } else {
            newOperandsUsed.push_back(oldOperands[i]);  // Non-induction variable operand
          }
        }
        auto newStore = builder.create<AffineStoreOp>(builder.getUnknownLoc(), newValueToStore, temp_buffer,
                    ValueRange({}));
        targetStoreOp.push_back(storeOp);
        // theMap = oldMap;
        oldToNewOpMap[&op] = newStore;
      }else if (auto divOp = dyn_cast<arith::DivFOp>(&op)) {
        // llvm::outs()<<"===============\n";
        Value dividend = op.getOperand(0);
        Value divisor = op.getOperand(1);
        
        // Replace old operands with new ones if they exist
        if (oldToNewOpMap.count(dividend.getDefiningOp()))
            dividend = oldToNewOpMap[dividend.getDefiningOp()]->getResult(0);
        if (oldToNewOpMap.count(divisor.getDefiningOp()))
            divisor = oldToNewOpMap[divisor.getDefiningOp()]->getResult(0);
        
        auto newDivOp = builder.create<arith::DivFOp>(builder.getUnknownLoc(), dividend, divisor);
        oldToNewOpMap[&op] = newDivOp;
      }
    }
    if(needIfOpBand1==true){
      builder.setInsertionPointAfter(ifOp1);
    }
    

    
    if (needIfOpBand2) {
      auto ifCondition = IntegerSet::get(ifOperandsBand2.size(), 0, ifExprsBand2, ifEqFlags2);
      ifOp2 = builder.create<AffineIfOp>(builder.getUnknownLoc(), ifCondition, ifOperandsBand2,/*withElseRegion=*/false);
      // ifOp2.dump();
      builder.setInsertionPointToStart(ifOp2.getThenBlock());
    }

    // Repeat the same process for band2...
    for (auto &op : band2.back().getBody()->getOperations()) {
      if (auto loadOp = dyn_cast<AffineLoadOp>(&op)) {
        AffineMap oldMap = loadOp.getAffineMap();
        SmallVector<Value, 8> oldOperands = loadOp.getMapOperands();
        SmallVector<Value, 8> newOperandsUsed;
        // llvm::outs()<<"oldOperands:"<<oldOperands.size()<<"\n";
        for (unsigned i = 0; i < oldOperands.size(); ++i) {
          for (int j = 0; j < oldOperandsBand2.size(); ++j) {
              if (oldOperands[i] == oldOperandsBand2[j]) {
                  newOperandsUsed.push_back(newOperands[j]);
              }
          }
        }
        auto newLoad = builder.create<AffineLoadOp>(builder.getUnknownLoc(), loadOp.getMemRef(), oldMap, ValueRange(newOperandsUsed));
        oldToNewOpMap[&op] = newLoad;
      } else if (auto storeOp = dyn_cast<AffineStoreOp>(&op)) {
        Value newValueToStore = storeOp.getValueToStore();

        // Check if the value being stored was produced by a previous operation and needs to be replaced
        if (oldToNewOpMap.count(newValueToStore.getDefiningOp())) {
          newValueToStore = oldToNewOpMap[newValueToStore.getDefiningOp()]->getResult(0);
        }

        AffineMap oldMap = storeOp.getAffineMap();
        SmallVector<Value, 8> oldOperands = storeOp.getMapOperands();
        SmallVector<Value, 8> newOperandsUsed;
        for (unsigned i = 0; i < oldOperands.size(); ++i) {
          if (auto iv = oldOperands[i].dyn_cast<BlockArgument>()) {
            if (iv.getOwner() == band2[0].getBody()) {
              unsigned position = iv.getArgNumber();
              newOperandsUsed.push_back(fusedLoops[position].getInductionVar());
            } else {
              newOperandsUsed.push_back(oldOperands[i]);  // Non-induction variable operand
            }
          } else {
            newOperandsUsed.push_back(oldOperands[i]);  // Non-induction variable operand
          }
        }
        auto newStore = builder.create<AffineStoreOp>(builder.getUnknownLoc(), newValueToStore, temp_buffer, 
                    ValueRange({}));
        // auto newStore2 = builder.create<AffineStoreOp>(builder.getUnknownLoc(), newValueToStore, storeOp.getMemref(), oldMap,
        //       ValueRange(newOperands));
        oldToNewOpMap[&op] = newStore;
      }else if (auto divOp = dyn_cast<arith::DivFOp>(&op)) {
        // llvm::outs()<<"===============\n";
        Value dividend = op.getOperand(0);
        Value divisor = op.getOperand(1);
        
        // Replace old operands with new ones if they exist
        if (oldToNewOpMap.count(dividend.getDefiningOp()))
            dividend = oldToNewOpMap[dividend.getDefiningOp()]->getResult(0);
        if (oldToNewOpMap.count(divisor.getDefiningOp()))
            divisor = oldToNewOpMap[divisor.getDefiningOp()]->getResult(0);
        
        auto newDivOp = builder.create<arith::DivFOp>(builder.getUnknownLoc(), dividend, divisor);
        oldToNewOpMap[&op] = newDivOp;
      }
    }
    if(needIfOpBand2==true){
      builder.setInsertionPointAfter(ifOp2);
    }
    auto newLoadOp = builder.create<AffineLoadOp>(builder.getUnknownLoc(), temp_buffer, ValueRange({}));
    // newLoadOp.dump();
    // fusedLoops[0].dump();
    auto storeOp = dyn_cast<AffineStoreOp>(targetStoreOp[0]);
    auto newStore = builder.create<AffineStoreOp>(builder.getUnknownLoc(), newLoadOp, dyn_cast<AffineStoreOp>(targetStoreOp[0]).getMemref(), 
                    ValueRange(newOperands));
  }else{
    for (size_t i = 0; i < band1.size(); ++i) {
      oldOperandsBand1.push_back(band1[i].getInductionVar());
      oldOperandsBand2.push_back(band2[i].getInductionVar());
      newOperands.push_back(fusedLoops[i].getInductionVar());
    }

    for (auto &op : band1.back().getBody()->getOperations()) {
      if (auto loadOp = dyn_cast<AffineLoadOp>(&op)) {
        AffineMap oldMap = loadOp.getAffineMap();
        SmallVector<Value, 8> oldOperands = loadOp.getMapOperands();
        SmallVector<Value, 8> newOperandsUsed;
        // llvm::outs()<<"oldOperands:"<<oldOperands.size()<<"\n";
        for (unsigned i = 0; i < oldOperands.size(); ++i) {
          for (int j = 0; j < oldOperandsBand1.size(); ++j) {
              if (oldOperands[i] == oldOperandsBand1[j]) {
                  newOperandsUsed.push_back(newOperands[j]);
              }
          }
        }
        auto newLoad = builder.create<AffineLoadOp>(builder.getUnknownLoc(), loadOp.getMemRef(), oldMap, ValueRange(newOperandsUsed));
        oldToNewOpMap[&op] = newLoad;
      } else if (auto storeOp = dyn_cast<AffineStoreOp>(&op)) {
        Value newValueToStore = storeOp.getValueToStore();

        // Check if the value being stored was produced by a previous operation and needs to be replaced
        if (oldToNewOpMap.count(newValueToStore.getDefiningOp())) {
          newValueToStore = oldToNewOpMap[newValueToStore.getDefiningOp()]->getResult(0);
        }

        AffineMap oldMap = storeOp.getAffineMap();
        SmallVector<Value, 8> oldOperands = storeOp.getMapOperands();
        SmallVector<Value, 8> newOperandsUsed;
        for (unsigned i = 0; i < oldOperands.size(); ++i) {
          if (auto iv = oldOperands[i].dyn_cast<BlockArgument>()) {
            if (iv.getOwner() == band1[0].getBody()) {
              unsigned position = iv.getArgNumber();
              newOperandsUsed.push_back(fusedLoops[position].getInductionVar());
            } else {
              newOperandsUsed.push_back(oldOperands[i]);  // Non-induction variable operand
            }
          } else {
            newOperandsUsed.push_back(oldOperands[i]);  // Non-induction variable operand
          }
        }
        auto newStore = builder.create<AffineStoreOp>(builder.getUnknownLoc(), newValueToStore, storeOp.getMemref(), oldMap, 
                    ValueRange(newOperands));
        oldToNewOpMap[&op] = newStore;
      }else if (auto divOp = dyn_cast<arith::DivFOp>(&op)) {
        // llvm::outs()<<"===============\n";
        Value dividend = op.getOperand(0);
        Value divisor = op.getOperand(1);
        
        // Replace old operands with new ones if they exist
        if (oldToNewOpMap.count(dividend.getDefiningOp()))
            dividend = oldToNewOpMap[dividend.getDefiningOp()]->getResult(0);
        if (oldToNewOpMap.count(divisor.getDefiningOp()))
            divisor = oldToNewOpMap[divisor.getDefiningOp()]->getResult(0);
        
        auto newDivOp = builder.create<arith::DivFOp>(builder.getUnknownLoc(), dividend, divisor);
        oldToNewOpMap[&op] = newDivOp;
      }
    }
    if(needIfOpBand1==true){
      builder.setInsertionPointAfter(ifOp1);
    }
    
    // Handle band2
    for (size_t i = 0; i < band2.size(); ++i) {
      if (lblist2[i] > fusedLoops[i].getConstantLowerBound() || ublist2[i] < fusedLoops[i].getConstantUpperBound()) {
        needIfOpBand2 = true;
        ifExprsBand2.push_back(builder.getAffineDimExpr(i) - ublist2[i] + 1);
        ifEqFlags2.push_back(false);
      }
      ifOperandsBand2.push_back(fusedLoops[i].getInductionVar());
    }
    
    if (needIfOpBand2) {
      auto ifCondition = IntegerSet::get(ifOperandsBand2.size(), 0, ifExprsBand2, ifEqFlags2);
      ifOp2 = builder.create<AffineIfOp>(builder.getUnknownLoc(), ifCondition, ifOperandsBand2,/*withElseRegion=*/false);
      // ifOp2.dump();
      builder.setInsertionPointToStart(ifOp2.getThenBlock());
    }

    // Repeat the same process for band2...
    for (auto &op : band2.back().getBody()->getOperations()) {
      if (auto loadOp = dyn_cast<AffineLoadOp>(&op)) {
        AffineMap oldMap = loadOp.getAffineMap();
        SmallVector<Value, 8> oldOperands = loadOp.getMapOperands();
        SmallVector<Value, 8> newOperandsUsed;
        // llvm::outs()<<"oldOperands:"<<oldOperands.size()<<"\n";
        for (unsigned i = 0; i < oldOperands.size(); ++i) {
          for (int j = 0; j < oldOperandsBand2.size(); ++j) {
              if (oldOperands[i] == oldOperandsBand2[j]) {
                  newOperandsUsed.push_back(newOperands[j]);
              }
          }
        }
        auto newLoad = builder.create<AffineLoadOp>(builder.getUnknownLoc(), loadOp.getMemRef(), oldMap, ValueRange(newOperandsUsed));
        oldToNewOpMap[&op] = newLoad;
      } else if (auto storeOp = dyn_cast<AffineStoreOp>(&op)) {
        Value newValueToStore = storeOp.getValueToStore();

        // Check if the value being stored was produced by a previous operation and needs to be replaced
        if (oldToNewOpMap.count(newValueToStore.getDefiningOp())) {
          newValueToStore = oldToNewOpMap[newValueToStore.getDefiningOp()]->getResult(0);
        }

        AffineMap oldMap = storeOp.getAffineMap();
        SmallVector<Value, 8> oldOperands = storeOp.getMapOperands();
        SmallVector<Value, 8> newOperandsUsed;
        for (unsigned i = 0; i < oldOperands.size(); ++i) {
          if (auto iv = oldOperands[i].dyn_cast<BlockArgument>()) {
            if (iv.getOwner() == band2[0].getBody()) {
              unsigned position = iv.getArgNumber();
              newOperandsUsed.push_back(fusedLoops[position].getInductionVar());
            } else {
              newOperandsUsed.push_back(oldOperands[i]);  // Non-induction variable operand
            }
          } else {
            newOperandsUsed.push_back(oldOperands[i]);  // Non-induction variable operand
          }
        }
        auto newStore = builder.create<AffineStoreOp>(builder.getUnknownLoc(), newValueToStore, storeOp.getMemref(), oldMap, 
                    ValueRange(newOperands));
        oldToNewOpMap[&op] = newStore;
      }else if (auto divOp = dyn_cast<arith::DivFOp>(&op)) {
        // llvm::outs()<<"===============\n";
        Value dividend = op.getOperand(0);
        Value divisor = op.getOperand(1);
        
        // Replace old operands with new ones if they exist
        if (oldToNewOpMap.count(dividend.getDefiningOp()))
            dividend = oldToNewOpMap[dividend.getDefiningOp()]->getResult(0);
        if (oldToNewOpMap.count(divisor.getDefiningOp()))
            divisor = oldToNewOpMap[divisor.getDefiningOp()]->getResult(0);
        
        auto newDivOp = builder.create<arith::DivFOp>(builder.getUnknownLoc(), dividend, divisor);
        oldToNewOpMap[&op] = newDivOp;
      }
    }
  }
  // fusedLoops[0].dump();
}


void codo::fuseLoopsWithSameBounds(AffineLoopBand band1, AffineLoopBand band2){
  SmallVector<int, 4> lbList, ubList;
  SmallVector<affine::AffineForOp, 4> fusedLoops;

  OpBuilder builder(band1[0]);
  builder.setInsertionPointAfter(band1[0]);

  for (auto loop : band1) {
    assert(loop.hasConstantBounds() && "Cannot handle variable loop bounds!");
    auto lowerBound = loop.getConstantLowerBound();
    auto upperBound = loop.getConstantUpperBound();
    lbList.push_back(lowerBound);
    ubList.push_back(upperBound);
    auto fusedLoop = builder.create<AffineForOp>(
        builder.getUnknownLoc(), lowerBound, upperBound);
    fusedLoops.push_back(fusedLoop);
    builder.setInsertionPointToStart(fusedLoop.getBody());
  }

  SmallVector<Value, 4> newOperandsBand1;
  SmallVector<Value, 4> newOperandsBand2;
  for (size_t i = 0; i < band1.size(); ++i) {
    newOperandsBand1.push_back(fusedLoops[i].getInductionVar());
    newOperandsBand2.push_back(fusedLoops[i].getInductionVar());
  }
  // Map to track old to new induction variables and operations
  DenseMap<Operation *, Operation *> oldToNewOpMap;
  // fusedLoops[0].dump();
  for (auto &op : band1.back().getBody()->getOperations()) {
    if (auto loadOp = dyn_cast<AffineLoadOp>(&op)) {
      AffineMap oldMap = loadOp.getAffineMap();
      auto newLoad = builder.create<AffineLoadOp>(builder.getUnknownLoc(), loadOp.getMemRef(), oldMap, ValueRange(newOperandsBand1));
      oldToNewOpMap[&op] = newLoad;
    } else if (auto storeOp = dyn_cast<AffineStoreOp>(&op)) {
      Value newValueToStore = storeOp.getValueToStore();
      // Check if the value being stored was produced by a previous operation and needs to be replaced
      if (oldToNewOpMap.count(newValueToStore.getDefiningOp())) {
        newValueToStore = oldToNewOpMap[newValueToStore.getDefiningOp()]->getResult(0);
      }
      AffineMap oldMap = storeOp.getAffineMap();
      SmallVector<Value, 4> oldOperands = storeOp.getMapOperands();
      SmallVector<Value, 4> newOperandsUsed;
      auto newStore = builder.create<AffineStoreOp>(builder.getUnknownLoc(), newValueToStore, storeOp.getMemref(), oldMap, 
                  ValueRange(newOperandsBand1));   
    }
  }
  for (auto &op : band2.back().getBody()->getOperations()) {
    if (auto loadOp = dyn_cast<AffineLoadOp>(&op)) {
      AffineMap oldMap = loadOp.getAffineMap();
      auto newLoad = builder.create<AffineLoadOp>(builder.getUnknownLoc(), loadOp.getMemRef(), oldMap, ValueRange(newOperandsBand2));
      oldToNewOpMap[&op] = newLoad;
    } else if (auto storeOp = dyn_cast<AffineStoreOp>(&op)) {
      Value newValueToStore = storeOp.getValueToStore();
      // Check if the value being stored was produced by a previous operation and needs to be replaced
      if (oldToNewOpMap.count(newValueToStore.getDefiningOp())) {
        newValueToStore = oldToNewOpMap[newValueToStore.getDefiningOp()]->getResult(0);
      }
      AffineMap oldMap = storeOp.getAffineMap();
      SmallVector<Value, 4> oldOperands = storeOp.getMapOperands();
      SmallVector<Value, 4> newOperandsUsed;
      auto newStore = builder.create<AffineStoreOp>(builder.getUnknownLoc(), newValueToStore, storeOp.getMemref(), oldMap, 
                  ValueRange(newOperandsBand2));   
    }
  }
}


void codo::detectReadWriteConflicts(func::FuncOp func, 
                                     llvm::SmallDenseMap<affine::AffineForOp, func::FuncOp> &conflictMap) {
  llvm::DenseMap<Value, llvm::SmallVector<affine::AffineStoreOp, 4>> producerMap; // memref -> list of producer store operations
  llvm::DenseMap<Value, llvm::SmallVector<affine::AffineLoadOp, 4>> consumerMap;  // memref -> list of consumer load operations
  llvm::SmallDenseSet<Value, 4> conflictMemrefSet;
  llvm::DenseMap<Value, Value> bufferMap; // memref -> new buffer
  llvm::DenseMap<Value, affine::AffineStoreOp> conflictStoreMap; // memref -> conflict store operation


  // Define a set to keep track of already visited operations
  llvm::SmallDenseSet<Operation *> visitedOps;
  func.walk([&](affine::AffineForOp forOp) -> WalkResult {
    llvm::SmallDenseSet<Value> readSet;
    llvm::SmallDenseSet<Value> writeSet;
    llvm::SmallDenseSet<Value> reuseSet;

    forOp.getBody()->walk([&](Operation *op) {
      // Skip the operation if it has already been visited
      if (visitedOps.count(op) > 0)
        return WalkResult::advance();

      visitedOps.insert(op);

      if(auto buffer = dyn_cast<BufferOp>(op)){
        if(buffer.getStringAttr()==StringRef("reuse_buffer")){
          // llvm::outs()<<"emitArrayDirectives\n";
          reuseSet.insert(buffer.getResult());
          // buffer.getResult().dump();
          // isInterface = true;
        }
          
      }

      if (auto loadOp = dyn_cast<affine::AffineLoadOp>(op)) {
        Value memref = loadOp.getMemRef();
        readSet.insert(memref);
        consumerMap[memref].push_back(loadOp);
      } else if (auto storeOp = dyn_cast<affine::AffineStoreOp>(op)) {
        Value memref = storeOp.getMemRef();
        writeSet.insert(memref);
        producerMap[memref].push_back(storeOp);
      }
      return WalkResult::advance();
    });

    for (Value memref : writeSet) {
      if(reuseSet.size()!=0){
         if (readSet.contains(memref)&& !reuseSet.contains(memref)) {
          conflictMemrefSet.insert(memref);
          conflictStoreMap[memref] = producerMap[memref].back();
        }
      }else{
        if (readSet.contains(memref)) {
          conflictMemrefSet.insert(memref);
          conflictStoreMap[memref] = producerMap[memref].back();
        }
      }

    }

    return WalkResult::advance();
  });

  OpBuilder builder(func.getBody());
  // llvm::outs()<<"size: "<<conflictMemrefSet.size()<<;
  for (const auto &memref : conflictMemrefSet) {
    // memref.dump();
    auto bufferType = memref.getType().cast<MemRefType>();
    auto newBuffer = builder.create<BufferOp>(builder.getUnknownLoc(), bufferType);
    bufferMap[memref] = newBuffer;
  }

  for (const auto memref : conflictMemrefSet) {
    auto &stores = producerMap[memref];
    auto &loads = consumerMap[memref];

    int index = 0;
    for (int i = 0; i < stores.size(); i++) {
      if (stores[i] == conflictStoreMap[memref]) {
        index = i;
        break;
      }
    }
    auto storeOp = stores[index - 1];
    auto loadOp = loads[index - 1];

    builder.setInsertionPoint(storeOp);
    auto newStore = builder.create<affine::AffineStoreOp>(
        storeOp.getLoc(), storeOp.getValueToStore(), bufferMap[memref], storeOp.getMapOperands());
    storeOp->replaceAllUsesWith(newStore);
    storeOp.erase();
    builder.setInsertionPoint(loadOp);
    auto newLoad = builder.create<affine::AffineLoadOp>(
        loadOp.getLoc(), bufferMap[memref], loadOp.getMapOperands());
    loadOp->replaceAllUsesWith(newLoad);
    loadOp.erase();
  }
}

/// Calculate the lower and upper bound of the affine map if possible.
std::optional<std::pair<int64_t, int64_t>>
codo::getBoundOfAffineMap(AffineMap map, ValueRange operands) {
  if (map.isSingleConstant()) {
    auto constBound = map.getSingleConstantResult();
    return std::pair<int64_t, int64_t>(constBound, constBound);
  }

  // For now, we can only handle one result value map.
  if (map.getNumResults() != 1)
    return std::optional<std::pair<int64_t, int64_t>>();

  auto context = map.getContext();
  SmallVector<int64_t, 4> lbs;
  SmallVector<int64_t, 4> ubs;
  for (auto operand : operands) {
    // Only if the affine map operands are induction variable, the calculation
    // is possible.
    if (!isAffineForInductionVar(operand))
      return std::optional<std::pair<int64_t, int64_t>>();

    // Only if the owner for op of the induction variable has constant bound,
    // the calculation is possible.
    auto forOp = getForInductionVarOwner(operand);
    if (!forOp.hasConstantBounds())
      return std::optional<std::pair<int64_t, int64_t>>();

    int lb = forOp.getConstantLowerBound();
    int ub = forOp.getConstantUpperBound();
    int step = forOp.getStep().getSExtValue();

    lbs.push_back(lb);
    ubs.push_back(ub - 1 - (ub - 1 - lb) % step);
  }

  // TODO: maybe a more efficient algorithm.
  auto operandNum = operands.size();
  SmallVector<int64_t, 16> results;
  for (unsigned i = 0, e = pow(2, operandNum); i < e; ++i) {
    SmallVector<AffineExpr, 4> replacements;
    for (unsigned pos = 0; pos < operandNum; ++pos) {
      if (i >> pos % 2 == 0)
        replacements.push_back(getAffineConstantExpr(lbs[pos], context));
      else
        replacements.push_back(getAffineConstantExpr(ubs[pos], context));
    }
    auto newExpr = map.getResult(0).replaceDimsAndSymbols(replacements, {});

    if (auto constExpr = newExpr.dyn_cast<AffineConstantExpr>())
      results.push_back(constExpr.getValue());
    else
      return std::optional<std::pair<int64_t, int64_t>>();
  }

  auto minmax = std::minmax_element(results.begin(), results.end());
  return std::pair<int64_t, int64_t>(*minmax.first, *minmax.second);
}


// Estimate the latency of target loop using profiling-based information
void codo::estimateConvLoop(affine::AffineForOp forOp, llvm::DenseMap<affine::AffineForOp, long> &latencyMap){
  // Currently we directly use the profiling results:
  // lb loop: 3 cycles
  // wb loop: 2 cycles
  // conv loop: 9 cycles
  // All the other latency overhead: 7 cycles
  int lbLatency = 3;
  int wbLatency = 2;
  int convLatency = 9;
  int otherLatencyOverhead = 7;
  forOp.walk([&](AffineForOp childForOp) {
    if(childForOp->hasAttrOfType<UnitAttr>("lb_loop")){
      // Step 1: collect all the loops in between the childForOp and the forOp
      AffineLoopBand outerBand;
      getLoopBandFromOutermost(childForOp, outerBand);
      outerBand.resize(1);
      assert(outerBand.size() > 0 && "No loop band found for the conv loop");

      // Step 2: calculate the trip count of each loop and multiply them
      // The total trip count is already computed in `tripCount`
      long tripCount = 1;

      for(auto subLoop: outerBand){
        // if (auto loopDirect = getLoopDirective(subLoop)) {
          // if (loopDirect.getPipeline()){
            int loopTripCount = getAverageTripCount(subLoop).value();
            tripCount *= loopTripCount;
          // }
        // }
      }
      // Step 3: the latency of the forOp is the product of the overall trip count + latency overhead
      lbLatency = tripCount + lbLatency;
      // llvm::outs() << "Lb loop latency: " << lbLatency << " cycles\n";
    }
  });

  forOp.walk([&](AffineForOp childForOp) {
    if(childForOp->hasAttrOfType<UnitAttr>("wb_loop")){
      // op->setAttr("parallel", UnitAttr::get(op->getContext()));
      // Step 1: collect all the loops in between the childForOp and the forOp
      AffineLoopBand outerBand;
      getLoopBandFromOutermost(childForOp, outerBand);
      outerBand.resize(1);
      assert(outerBand.size() > 0 && "No loop band found for the conv loop");

      // Step 2: calculate the trip count of each loop and multiply them
      // The total trip count is already computed in `tripCount`
      int tripCount = 1;

      for(auto subLoop: outerBand){
        // if (auto loopDirect = getLoopDirective(subLoop)) {
          // if (loopDirect.getPipeline()){
            int loopTripCount = getAverageTripCount(subLoop).value();
            tripCount *= loopTripCount;
          // }
        // }
      }
      // Step 3: the latency of the forOp is the product of the overall trip count + latency overhead
      wbLatency = tripCount + wbLatency;
      // llvm::outs() << "Wb loop latency: " << wbLatency << " cycles\n";
    }
  });


  // Locate the position of linebuffer loop, calculate the trip count
  forOp.walk([&](AffineForOp childForOp) {
    if(childForOp->hasAttrOfType<UnitAttr>("conv_loop")){
      // Step 1: collect all the loops in between the childForOp and the forOp
      AffineLoopBand outerBand;
      int tripCount = 1;
      childForOp.walk([&](AffineForOp tempForOp) {
        if (auto loopDirect = getLoopDirective(tempForOp)) {
          if (loopDirect.getPipeline()){
            getLoopBandFromInnermost(tempForOp, outerBand);
            // llvm::outs()<<"Found conv buffer loops!!!!!!!"<<"\n";
            // tempForOp->dump();
            if(!tempForOp->hasAttrOfType<UnitAttr>("conv_loop")){
              tripCount*= getAverageTripCount(childForOp).value();
            }
          }
        }
      });
      
      // assert(outerBand.size() > 0 && "No loop band found for the conv loop");

      // Step 2: calculate the trip count of each loop and multiply them
      // The total trip count is already computed in `tripCount`
      
      if(outerBand.size() != 0){
        for(auto subLoop: outerBand){
          if (auto loopDirect = getLoopDirective(subLoop)) {
            if (loopDirect.getPipeline()){
              int loopTripCount = getAverageTripCount(subLoop).value();
              tripCount *= loopTripCount;
            }
          }
        }
      }else{
        childForOp.walk([&](AffineForOp tempForOp) {
          // getLoopBandFromInnermost(tempForOp, outerBand);
          // llvm::outs()<<"Found conv buffer loops!!!!!!!"<<"\n";
          // tempForOp->dump();
          // if(!tempForOp->hasAttrOfType<UnitAttr>("conv_loop")){
          tripCount*= getAverageTripCount(childForOp).value();
          // }
        });
      }
      
      // Multiply the trip count of Conv Loop

      // Step 3: the latency of the forOp is the product of the overall trip count + latency overhead
      convLatency = tripCount + convLatency;
      // llvm::outs() << "Conv loop latency: " << convLatency << " cycles\n";
    }
  });

  AffineLoopBand parentBand;
  getLoopBandFromOutermost(forOp, parentBand);
  parentBand.resize(3);
  long tripCount = 1;

  for(auto subLoop: parentBand){
    // if (auto loopDirect = getLoopDirective(subLoop)) {
      // if (loopDirect.getPipeline()){
        long loopTripCount = getAverageTripCount(subLoop).value();
        tripCount *= loopTripCount;
      // }
    // }
  }
  long overallLatency = (lbLatency + wbLatency + convLatency + otherLatencyOverhead) * tripCount;
  // llvm::outs() << "Overall loop latency: " << overallLatency << " cycles\n\n";

   // Fill the DenseMap with the calculated latency for the current AffineForOp
  latencyMap[forOp] = overallLatency;
  // llvm::outs() << "Stored latency for: " << overallLatency << " cycles\n";

  
}


#include <llvm/Support/MathExtras.h>

void codo::distributeParallelism(llvm::DenseMap<affine::AffineForOp, long> &allLatencyMap, 
                                  llvm::DenseMap<affine::AffineForOp, int> &parallelismMap,  
                                  int maxParallelism, int adjust_parallelism_cnt, float adjust_parallelism_factor) {
    // Step 1: Reorder the loops by latency (from max to min)
    llvm::outs() << "distributeParallelism\n";
    llvm::SmallVector<std::pair<affine::AffineForOp, long>, 16> sortedLoops;
    for (auto &entry : allLatencyMap) {
        sortedLoops.push_back(entry);
    }
    
    std::sort(sortedLoops.begin(), sortedLoops.end(), [](const auto &lhs, const auto &rhs) {
        return lhs.second > rhs.second; // Max to Min latency
    });

    // Step 2: Allocate parallelism factor to each loop
    long minLatency = sortedLoops.back().second; // minLatency
    long maxLatency = sortedLoops.front().second; // maxLatency
    llvm::outs() << "Step 3: Adjust parallelism\n";

    llvm::outs() << "minLatency: "<<minLatency<<"\n";
    
    // Step 3: Adjust parallelism for each loop
    llvm::DenseMap<affine::AffineForOp, long> tempLatencyMap;
    for (auto &entry : sortedLoops) {
        affine::AffineForOp loop = entry.first;
        long loopLatency = entry.second;

        // Step 3.1: Calculate parallelism, ensuring a minimum of 2
        int calculatedParallelism = std::max(1, int((double)loopLatency * maxParallelism / maxLatency));

        // Step 3.2: Adjust parallelism to be a power of 2 (upward rounding)
        int parallelismPow2 = llvm::PowerOf2Ceil(calculatedParallelism);

        // Ensure parallelism doesn't exceed the maximum allowed
        parallelismPow2 = std::min(parallelismPow2, maxParallelism);

        parallelismMap[loop] = parallelismPow2;

        auto parentFunc = loop.getOperation()->getParentOfType<func::FuncOp>();
        auto clonedFunc = parentFunc.clone();
        // explorer.applyOptStrategy(clonedFunc, parallelismMap);
        for (auto clonedLoop : clonedFunc.getOps<affine::AffineForOp>()){
          if((clonedLoop->hasAttrOfType<UnitAttr>("top_loop"))){
            // estimateConvLoop(clonedLoop, tempLatencyMap); 
            // for (auto loop : func.getOps<affine::AffineForOp>()){
            //   if((loop->hasAttrOfType<UnitAttr>("top_loop"))){
                parallelismMap[clonedLoop] = parallelismPow2;
                applyOptStrategy(clonedFunc, parallelismMap);
                estimateConvLoop(clonedLoop, tempLatencyMap); 
                allLatencyMap[loop] = tempLatencyMap[clonedLoop];
            //   }
            // }
            // funcLatencyMap[func] = allLatencyMap[loop];
          }
        }
        // auto parentFunc = loop.getOperation()->getParentOfType<func::FuncOp>();
        llvm::outs() 
            << "function name: " << parentFunc.getName()<<" cycles\n"
            << "loopLatency: " << loopLatency
            << ", Parallelism: " << parallelismPow2 
            << ", Latency: " << allLatencyMap[loop] << " cycles\n";

        // estimateConvLoop(clonedLoop, tempLatencyMap); 

        // Update the latency after applying the parallelism
        // long newLatency = loopLatency / parallelismPow2;
        // allLatencyMap[loop] = newLatency;
    }

    // Step 4: Debug step, check current state of latency and parallelism
    llvm::outs() << "Step 4: for debug\n";
    for (auto &entry : allLatencyMap) {
        affine::AffineForOp loop = entry.first;
        long loopLatency = entry.second;
        int loopParallelism = parallelismMap[loop];
        auto parentFunc = loop.getOperation()->getParentOfType<func::FuncOp>();
        llvm::outs() 
            << "function name: " << parentFunc.getName() 
            << ", Parallelism: " << loopParallelism 
            << ", Latency: " << loopLatency << " cycles\n";
    }

    // Step 5: Rebuild sorted loops based on the new latency map and apply additional parallelism adjustment
    llvm::outs() << "Step 5: Rebuild sorted loops and apply parallelism adjustments\n";

    // Step 5.1: Clear the sortedLoops and rebuild it with updated latency map
    int count = adjust_parallelism_cnt;
    for(int i=0; i<count; i++){
      sortedLoops.clear();
      for (auto &entry : allLatencyMap) {
          sortedLoops.push_back(entry);
      }
      std::sort(sortedLoops.begin(), sortedLoops.end(), [](const auto &lhs, const auto &rhs) {
          return lhs.second > rhs.second; // Max to Min latency
      });

      // // Step 5.2: Find the current minLatency after the adjustment
      long currentMinLatency = sortedLoops.back().second;
      long currentMaxLatency = sortedLoops.front().second;

      // Step 5.3: Traverse all loops and adjust parallelism if latency > 1.5 * minLatency
      for (auto &entry : sortedLoops) {
          affine::AffineForOp loop = entry.first;
          long loopLatency = entry.second;
          auto parentFunc = loop.getOperation()->getParentOfType<func::FuncOp>();
          if (loopLatency > adjust_parallelism_factor * currentMinLatency) {
              // If latency is greater than 1.5 times the minimum latency, double the parallelism
              int loopBound = loop.getConstantUpperBound() - loop.getConstantLowerBound();
              int currentParallelism = parallelismMap[loop];
              //TODO: Add a check to ensure parallelism doesn't exceed maxParallelism (16)
              // currentParallelism = std::min(16, loopBound/2);
              
              if (loopLatency > 3 * currentMinLatency)
                currentParallelism = std::min(currentParallelism * 4, maxParallelism); // Double the parallelism, but not exceeding maxParallelism
              else 
                currentParallelism = std::min(currentParallelism * 2, maxParallelism); // Double the parallelism, but not exceeding maxParallelism

              // if(currentParallelism == loopBound){
              //   currentParallelism = loopBound/2;
              // }
              parallelismMap[loop] = currentParallelism;
                
              llvm::outs() 
              << "function name: " << parentFunc.getName() 
                          << ", New Parallelism: " << currentParallelism 
                          << ", New Latency: " << " cycles "
                          << ", New count: " << i<<"\n";
          }
      }

      for (auto &entry : sortedLoops) {
          affine::AffineForOp loop = entry.first;
          long loopLatency = entry.second;
          int loopParallelism = parallelismMap[loop];

          auto parentFunc = loop.getOperation()->getParentOfType<func::FuncOp>();
          auto clonedFunc = parentFunc.clone();
          for (auto clonedLoop : clonedFunc.getOps<affine::AffineForOp>()){
            if((clonedLoop->hasAttrOfType<UnitAttr>("top_loop"))){
                  parallelismMap[clonedLoop] = loopParallelism;
                  applyOptStrategy(clonedFunc, parallelismMap);
                  estimateConvLoop(clonedLoop, tempLatencyMap); 
                  allLatencyMap[loop] = tempLatencyMap[clonedLoop];
            }
          }
      }
    }

    // Step 5.1: Clear the sortedLoops and rebuild it with updated latency map
    for (int i = 0; i < 1; i++) {
        sortedLoops.clear();
        for (auto &entry : allLatencyMap) {
            sortedLoops.push_back(entry);
        }
        std::sort(sortedLoops.begin(), sortedLoops.end(), [](const auto &lhs, const auto &rhs) {
            return lhs.second > rhs.second; // Max to Min latency
        });

        // Step 5.2: Find the current maxLatency and minLatency after the adjustment
        long currentMinLatency = sortedLoops.back().second;
        long currentMaxLatency = sortedLoops.front().second;

        // Step 5.3: Traverse all loops and adjust parallelism if latency is lower than 1/2 or 1/4 of max latency
        for (auto &entry : sortedLoops) {
            affine::AffineForOp loop = entry.first;
            long loopLatency = entry.second;
            auto parentFunc = loop.getOperation()->getParentOfType<func::FuncOp>();

            if (loopLatency < currentMaxLatency / adjust_parallelism_factor){
                // If latency is less than half of maxLatency, halve the parallelism
                int currentParallelism = parallelismMap[loop];
                currentParallelism = std::max(1, currentParallelism / 2); // Ensure parallelism doesn't drop below 1
                parallelismMap[loop] = currentParallelism;
                 llvm::outs() 
                  << "function name: " << parentFunc.getName() 
                          << ", Downscaling: " << currentParallelism << " \n";
            }

            if (loopLatency < currentMaxLatency / 4) {
                // If latency is less than a quarter of maxLatency, quarter the parallelism
                int currentParallelism = parallelismMap[loop];
                currentParallelism = std::max(1, currentParallelism / 4); // Ensure parallelism doesn't drop below 1
                parallelismMap[loop] = currentParallelism;
                llvm::outs() 
                  << "function name: " << parentFunc.getName() 
                          << ", Downscaling: " << currentParallelism << " \n";
            }
        }

        // Reapply the parallelism adjustments and estimate latency again
        for (auto &entry : sortedLoops) {
            affine::AffineForOp loop = entry.first;
            long loopLatency = entry.second;
            int loopParallelism = parallelismMap[loop];

            auto parentFunc = loop.getOperation()->getParentOfType<func::FuncOp>();
            auto clonedFunc = parentFunc.clone();
            for (auto clonedLoop : clonedFunc.getOps<affine::AffineForOp>()){
                if ((clonedLoop->hasAttrOfType<UnitAttr>("top_loop"))) {
                    parallelismMap[clonedLoop] = loopParallelism;
                    applyOptStrategy(clonedFunc, parallelismMap);
                    estimateConvLoop(clonedLoop, tempLatencyMap); 
                    allLatencyMap[loop] = tempLatencyMap[clonedLoop];
                }
            }
        }
    }
    

    llvm::outs() << "Step 6: for debug\n";
    for (auto &entry : allLatencyMap) {
        affine::AffineForOp loop = entry.first;
        long loopLatency = entry.second;
        int loopParallelism = parallelismMap[loop];
        auto parentFunc = loop.getOperation()->getParentOfType<func::FuncOp>();
        llvm::outs() 
            << "function name: " << parentFunc.getName() 
            << ", Parallelism: " << loopParallelism 
            << ", Latency: " << loopLatency << " cycles\n";
    }
}



/// Get the whole loop band given the outermost loop and return it in "band".
/// Meanwhile, the return value is the innermost loop of this loop band.
affine::AffineForOp codo::getLoopBandFromOutermost(affine::AffineForOp forOp,
                                               AffineLoopBand &band) {
  band.clear();
  auto currentLoop = forOp;
  while (true) {
    band.push_back(currentLoop);

    if (getChildLoopNum(currentLoop) == 1)
      currentLoop = *currentLoop.getOps<affine::AffineForOp>().begin();
    else
      break;
  }
  return band.back();
}
affine::AffineForOp codo::getLoopBandFromInnermost(affine::AffineForOp forOp,
                                               AffineLoopBand &band) {
  band.clear();
  AffineLoopBand reverseBand;

  auto currentLoop = forOp;
  while (true) {
    reverseBand.push_back(currentLoop);

    auto parentLoop = currentLoop->getParentOfType<affine::AffineForOp>();
    if (!parentLoop)
      break;

    if (getChildLoopNum(parentLoop) == 1)
      currentLoop = parentLoop;
    else
      break;
  }

  band.append(reverseBand.rbegin(), reverseBand.rend());
  return band.front();
}

std::optional<unsigned> codo::getAverageTripCount(affine::AffineForOp forOp) {
  if (auto optionalTripCount = getConstantTripCount(forOp))
    return optionalTripCount.value();
  else {
    // TODO: A temporary approach to estimate the trip count. For now, we take
    // the average of the upper bound and lower bound of trip count as the
    // estimated trip count.
    auto lowerBound = getBoundOfAffineMap(forOp.getLowerBoundMap(),
                                          forOp.getLowerBoundOperands());
    auto upperBound = getBoundOfAffineMap(forOp.getUpperBoundMap(),
                                          forOp.getUpperBoundOperands());

    if (lowerBound && upperBound) {
      auto lowerTripCount =
          upperBound.value().second - lowerBound.value().first;
      auto upperTripCount =
          upperBound.value().first - lowerBound.value().second;
      return (lowerTripCount + upperTripCount + 1) / 2;
    } else
      return std::optional<unsigned>();
  }
}

/// Collect all loop bands in the "block" and return them in "bands". If
/// "allowHavingChilds" is true, loop bands containing more than 1 other loop
/// bands are also collected. Otherwise, only loop bands that contains no child
/// loops are collected.
void codo::getLoopBands(Block &block, AffineLoopBands &bands,
                            bool allowHavingChilds) {
  bands.clear();
  block.walk([&](affine::AffineForOp loop) {
    auto childNum = getChildLoopNum(loop);

    if (childNum == 0 || (childNum > 1 && allowHavingChilds)) {
      AffineLoopBand band;
      getLoopBandFromInnermost(loop, band);
      bands.push_back(band);
    }
  });
}



/// Parse loop directives.
Attribute codo::getLoopDirective(Operation *op, std::string name) {
  return op->getAttr(name);
}

/// Parse other attributes.
SmallVector<int64_t, 8> codo::getIntArrayAttrValue(Operation *op,
                                                  StringRef name) {
  SmallVector<int64_t, 8> array;
  if (auto arrayAttr = op->getAttrOfType<ArrayAttr>(name)) {
    for (auto attr : arrayAttr)
      if (auto intAttr = attr.dyn_cast<IntegerAttr>())
        array.push_back(intAttr.getInt());
      else
        return SmallVector<int64_t, 8>();
    return array;
  } else
    return SmallVector<int64_t, 8>();
}

/// Return the layout map of "memrefType".
AffineMap codo::getLayoutMap(MemRefType memrefType) {
  // Check whether the memref has layout map.
  auto memrefMaps = memrefType.getLayout();
  if (memrefMaps.getAffineMap().isIdentity())
    return (AffineMap) nullptr;

  return memrefMaps.getAffineMap();
}


std::vector<std::string> codo::split_names(const std::string &arg_names) {
  std::stringstream ss(arg_names);
  std::vector<std::string> args;
  while (ss.good()) {
    std::string substr;
    getline(ss, substr, ',');
    args.push_back(substr);
  }
  return args;
}





//===----------------------------------------------------------------------===//
// Graph Preprocess utils
//===----------------------------------------------------------------------===//
// Wrap the operations in the block with dispatch op.
DispatchOp codo::dispatchBlock(Block *block) {
  if (!block->getOps<DispatchOp>().empty() ||
      !isa<func::FuncOp, affine::AffineForOp>(block->getParentOp()))
    return DispatchOp();

  OpBuilder builder(block, block->begin());
  // Capture the operands of the block's terminator into a ValueRange.
  ValueRange returnValues(block->getTerminator()->getOperands());
  auto loc = builder.getUnknownLoc();
  auto dispatch = builder.create<DispatchOp>(loc, returnValues);

  // Create a new block within the DispatchOp's body.
  auto &dispatchBlock = dispatch.getBody().emplaceBlock();
  // Set the OpBuilder's insertion point to the end of the new block.
  builder.setInsertionPointToEnd(&dispatchBlock);
  // Create a YieldOp at the end of the new block with the same return values.
  builder.create<YieldOp>(loc, returnValues);

  auto &dispatchOps = dispatchBlock.getOperations();
  auto &parentOps = block->getOperations();
  // Move the operations from the parent block into the new dispatch block.
  dispatchOps.splice(dispatchBlock.begin(), parentOps,
                     std::next(parentOps.begin()), std::prev(parentOps.end()));
  // Update the operands of the block's terminator to the results of the dispatch.
  block->getTerminator()->setOperands(dispatch.getResults());
  return dispatch;
}

// Fuse the given operations into a new task. The new task will be created
// before the first operation or last operation and each operation will be
// inserted in order. This method always succeeds even if the resulting IR is
// invalid.
TaskOp codo::fuseOpsIntoTask(ArrayRef<Operation *> ops,
                                 PatternRewriter &rewriter,
                                 bool insertToLastOp) {
  assert(!ops.empty() && "must fuse at least one op");
  // llvm::SmallDenseSet<Operation *, 4> opsSet(ops.begin(), ops.end());

  // Improvement by codo, now there will not be empty-used outputs
  // We improve it because we find that empty-used outputs can not be 
  // removed during canonicalization.
  // Note: potential bugs 
  llvm::SmallDenseSet<Operation *, 4> opsSet;
  for (auto *op : ops) {
    opsSet.insert(op);
    if (auto taskOp = llvm::dyn_cast<codo::TaskOp>(op)) {
      auto &subOps = taskOp.getBody().front().getOperations();
      for (auto &subOp : subOps) {
        opsSet.insert(&subOp); 
      }
    }
  }

  llvm::SetVector<Value> outputValues;
  for (auto op : ops)
    for (auto result : op->getResults())
      if (llvm::any_of(result.getUsers(),
                       [&](Operation *user) { return !opsSet.count(user); }))
        outputValues.insert(result);


  auto loc = rewriter.getUnknownLoc();
  if (!insertToLastOp)
    rewriter.setInsertionPoint(ops.front());
  else
    rewriter.setInsertionPoint(ops.back());
  auto task =
      rewriter.create<TaskOp>(loc, ValueRange(outputValues.getArrayRef()));
  auto taskBlock = rewriter.createBlock(&task.getBody());

  // Move each targeted op into the new graph task.
  rewriter.setInsertionPointToEnd(taskBlock);
  auto yield = rewriter.create<YieldOp>(loc, outputValues.getArrayRef());
  for (auto op : ops)
    op->moveBefore(yield);

  // Replace external output uses with the task results.
  unsigned idx = 0;
  for (auto output : outputValues)
    output.replaceUsesWithIf(task.getResult(idx++), [&](OpOperand &use) {
      return !task->isProperAncestor(use.getOwner());
    });

  // Inline all sub-tasks.
  for (auto subTask : llvm::make_early_inc_range(task.getOps<TaskOp>())) {
    auto &subTaskOps = subTask.getBody().front().getOperations();
    auto &taskOps = task.getBody().front().getOperations();
    taskOps.splice(subTask->getIterator(), subTaskOps, subTaskOps.begin(),
                   std::prev(subTaskOps.end()));
    rewriter.replaceOp(subTask, subTask.getYieldOp()->getOperands());
  }



  return task;
}


/// Fuse multiple nodes into a new node.
NodeOp codo::fuseNodeOps(ArrayRef<NodeOp> nodes,
                             PatternRewriter &rewriter) {
  assert((nodes.size() > 1) && "must fuse at least two nodes");

  // Collect inputs, outputs, and params of the new node.
  llvm::SetVector<Value> inputs;
  llvm::SmallVector<unsigned, 8> inputTaps;
  llvm::SmallVector<Location, 8> inputLocs;
  llvm::SetVector<Value> outputs;
  llvm::SmallVector<Location, 8> outputLocs;
  llvm::SetVector<Value> params;
  llvm::SmallVector<Location, 8> paramLocs;

  for (auto node : nodes) {
    for (auto output : node.getOutputs())
      if (outputs.insert(output))
        outputLocs.push_back(output.getLoc());
    for (auto param : node.getParams())
      if (params.insert(param))
        paramLocs.push_back(param.getLoc());
  }
  for (auto node : nodes)
    for (auto input : llvm::enumerate(node.getInputs())) {
      if (outputs.count(input.value()))
        continue;
      if (inputs.insert(input.value())) {
        inputLocs.push_back(input.value().getLoc());
        inputTaps.push_back(node.getInputTap(input.index()));
      }
    }

  // Construct the new node after the last node.
  rewriter.setInsertionPointAfter(nodes.back());
  auto newNode = rewriter.create<NodeOp>(
      rewriter.getUnknownLoc(), inputs.getArrayRef(), outputs.getArrayRef(),
      params.getArrayRef(), inputTaps);
  auto block = rewriter.createBlock(&newNode.getBody());
  block->addArguments(ValueRange(inputs.getArrayRef()), inputLocs);
  block->addArguments(ValueRange(outputs.getArrayRef()), outputLocs);
  block->addArguments(ValueRange(params.getArrayRef()), paramLocs);

  // Inline all nodes into the new node.
  for (auto node : nodes) {
    auto &nodeOps = node.getBody().front().getOperations();
    auto &newNodeOps = newNode.getBody().front().getOperations();
    newNodeOps.splice(newNode.end(), nodeOps);
    for (auto t : llvm::zip(node.getBody().getArguments(), node.getOperands()))
      std::get<0>(t).replaceAllUsesWith(std::get<1>(t));
    rewriter.eraseOp(node);
  }

  for (auto t : llvm::zip(newNode.getOperands(), block->getArguments()))
    std::get<0>(t).replaceUsesWithIf(std::get<1>(t), [&](OpOperand &use) {
      return newNode->isProperAncestor(use.getOwner());
    });
  return newNode;
}





void codo::updateFunctionWithConstants(func::FuncOp func) {
  IRMapping mapper;
  FunctionType funcType = func.getFunctionType();

  std::vector<Type> newArgTypes(funcType.getInputs().begin(), funcType.getInputs().end());
  std::vector<Value> newArgs;

  // Traverse all constant operations and add them to the new parameter list.
  func.walk([&](codo::ConstBufferOp op) {
    // Only choose the ConstBufferOps with specific values
    if (op.getValue()) {
      newArgTypes.push_back(op.getResult().getType());
      newArgs.push_back(op.getResult());
    }
  });

  // update the function type with new parameters
  FunctionType newFuncType = FunctionType::get(func.getContext(), newArgTypes, funcType.getResults());
  func.setType(newFuncType);

  unsigned argIndex = funcType.getNumInputs();
  Block &entryBlock = func.front();
  for (auto constantValue : newArgs) {
    entryBlock.insertArgument(argIndex, constantValue.getType(), constantValue.getLoc());
    mapper.map(constantValue, entryBlock.getArgument(argIndex));
    argIndex++;
  }

  for (auto &block : func) {
    for (auto &op : block) {
      for (auto &operand : op.getOpOperands()) {
        if (mapper.contains(operand.get())) {
          operand.set(mapper.lookup(operand.get()));
        }
      }
    }
  }


  std::vector<codo::ConstBufferOp> constantsToErase;
  func.walk([&](codo::ConstBufferOp op) {
    if (op.getValue()) {
      constantsToErase.push_back(op);
    }
  });
  for (auto op : constantsToErase) {
    op.erase();
  }
}













/// A helper to get all users of a buffer except the given node and with the
/// given kind (producer or consumer).
static auto getUsersExcept(Value buffer, OperandKind kind, NodeOp except) {
  SmallVector<NodeOp> nodes;
  for (auto &use : buffer.getUses())
    if (auto node = dyn_cast<NodeOp>(use.getOwner()))
      if (node != except && node.getOperandKind(use) == kind)
        nodes.push_back(node);
  return nodes;
}

/// Get the consumer/producer nodes of the given buffer expect the given node.
SmallVector<NodeOp> codo::getConsumersExcept(Value buffer, NodeOp except) {
  return getUsersExcept(buffer, OperandKind::INPUT, except);
}
SmallVector<NodeOp> codo::getProducersExcept(Value buffer, NodeOp except) {
  return getUsersExcept(buffer, OperandKind::OUTPUT, except);
}
SmallVector<NodeOp> codo::getConsumers(Value buffer) {
  return getConsumersExcept(buffer, NodeOp());
}
SmallVector<NodeOp> codo::getProducers(Value buffer) {
  return getProducersExcept(buffer, NodeOp());
}
SmallVector<NodeOp> codo::getDependentConsumers(Value buffer, NodeOp node) {
  // If the buffer is defined outside of a dependence free schedule op, we can
  // ignore back dependences.
  bool ignoreBackDependence =
      buffer.isa<BlockArgument>() && node.getScheduleOp().isDependenceFree();

  DominanceInfo domInfo;
  SmallVector<NodeOp> nodes;
  for (auto consumer : getConsumersExcept(buffer, node))
    if (!ignoreBackDependence || domInfo.properlyDominates(node, consumer))
      nodes.push_back(consumer);
  return nodes;
}


//===----------------------------------------------------------------------===//
// PartitionLayoutAttr
//===----------------------------------------------------------------------===//

AffineMap PartitionLayoutAttr::getAffineMap() const {
  auto b = Builder(getContext());
  assert(getKinds().size() == getFactors().size() &&
         "invalid partition layout");
  auto rank = getKinds().size();

  SmallVector<AffineExpr, 4> partitionIndices;
  SmallVector<AffineExpr, 4> addressIndices;

  // Compute the partition and address indices.
  for (unsigned dim = 0; dim < rank; ++dim) {
    auto kind = getKinds()[dim];
    auto factor = getFactors()[dim];

    if (kind == PartitionKind::NONE) {
      partitionIndices.push_back(b.getAffineConstantExpr(0));
      addressIndices.push_back(b.getAffineDimExpr(dim));

    } else if (kind == PartitionKind::CYCLIC) {
      partitionIndices.push_back(b.getAffineDimExpr(dim) % factor);
      addressIndices.push_back(b.getAffineDimExpr(dim).floorDiv(factor));

    } else if (kind == PartitionKind::BLOCK) {
      partitionIndices.push_back(b.getAffineDimExpr(dim).floorDiv(factor));
      addressIndices.push_back(b.getAffineDimExpr(dim) % factor);

    } else {
      partitionIndices.push_back(b.getAffineDimExpr(dim));
      addressIndices.push_back(b.getAffineConstantExpr(0));
    }
  }

  // Construct layout affine map.
  partitionIndices.append(addressIndices);
  return AffineMap::get(rank, 0, partitionIndices, getContext());
}

LogicalResult PartitionLayoutAttr::verifyLayout(
    ArrayRef<int64_t> shape,
    function_ref<InFlightDiagnostic()> emitError) const {
  if (shape.size() != getKinds().size() || shape.size() != getFactors().size())
    return emitError() << "number of memref dimensions must be equal to "
                          "number of partition kinds and factors";

  for (auto [size, kind, factor] : llvm::zip(shape, getKinds(), getFactors())) {
    // TODO: Is it really necessary?
    // if ((kind == PartitionKind::CYCLIC && size % factor != 0) ||
    //     (kind == PartitionKind::BLOCK && size % factor != 0))
    //   return emitError() << "cyclic or block partition factor must be a "
    //                         "divisor of memref dimension size";
    if (kind == PartitionKind::NONE && factor != 1)
      return emitError() << "none partition factor must be 1";
    if (kind == PartitionKind::COMPLETE && factor != size)
      return emitError() << "complete partition factor must be equal to "
                            "memref dimension size";
  }
  return success();
}

LogicalResult
PartitionLayoutAttr::verify(function_ref<InFlightDiagnostic()> emitError,
                            ArrayRef<PartitionKind> kinds,
                            ArrayRef<int64_t> factors) {
  if (kinds.size() != factors.size())
    return emitError() << "number of partition kinds and factors must be equal";
  if (llvm::any_of(factors, [](int64_t factor) { return factor <= 0; }))
    return emitError() << "partition factor must be positive";
  return success();
}

/// The affine map of "block" partition needs array shape to be inferenced. For
/// example, if the partition factor is [2] and the shape of the array is [16],
/// the affine map should be (d0) -> (d0 / 8, d0 % 8), where 8 is equal to 16
/// / 2. However, as the shape information is not known at the time of attribute
/// construction, we can only encode factor [8] in the attribute instead of the
/// actual factor [2]. This method returns the actual partition factor with the
/// given array shape.
SmallVector<int64_t>
PartitionLayoutAttr::getActualFactors(ArrayRef<int64_t> shape) {
  SmallVector<int64_t> actualFactors;
  for (auto [size, kind, factor] : llvm::zip(shape, getKinds(), getFactors())) {
    if (kind == PartitionKind::BLOCK)
      actualFactors.push_back((size + factor - 1) / factor);
    else
      actualFactors.push_back(factor);
  }
  return actualFactors;
}

/// This method construct a PartitionLayoutAttr with the given partition kinds,
/// actual partition factors, and array shape.
PartitionLayoutAttr PartitionLayoutAttr::getWithActualFactors(
    MLIRContext *context, ArrayRef<PartitionKind> kinds,
    ArrayRef<int64_t> actualFactors, ArrayRef<int64_t> shape) {
  SmallVector<int64_t, 4> factors;
  for (auto [size, kind, factor] : llvm::zip(shape, kinds, actualFactors)) {
    if (kind == PartitionKind::BLOCK)
      factors.push_back((size + factor - 1) / factor);
    else
      factors.push_back(factor);
  }
  return get(context, kinds, actualFactors);
}


MemoryKind codo::getMemoryKind(MemRefType type) {
  if (auto memorySpace = type.getMemorySpace())
    if (auto kindAttr = memorySpace.dyn_cast<MemoryKindAttr>())
      return kindAttr.getValue();
  return MemoryKind::UNKNOWN;
}

bool codo::isRam1P(MemRefType type) {
  auto kind = getMemoryKind(type);
  return kind == MemoryKind::LUTRAM_1P || kind == MemoryKind::BRAM_1P ||
         kind == MemoryKind::URAM_1P;
}
bool codo::isRam2P(MemRefType type) {
  auto kind = getMemoryKind(type);
  return kind == MemoryKind::LUTRAM_2P || kind == MemoryKind::BRAM_2P ||
         kind == MemoryKind::URAM_2P;
}
bool codo::isRamS2P(MemRefType type) {
  auto kind = getMemoryKind(type);
  return kind == MemoryKind::LUTRAM_S2P || kind == MemoryKind::BRAM_S2P ||
         kind == MemoryKind::URAM_S2P;
}
bool codo::isRamT2P(MemRefType type) {
  auto kind = getMemoryKind(type);
  return kind == MemoryKind::BRAM_T2P || kind == MemoryKind::URAM_T2P;
}
bool codo::isDram(MemRefType type) {
  auto kind = getMemoryKind(type);
  return kind == MemoryKind::DRAM;
}
bool codo::isUnknown(MemRefType type) {
  auto kind = getMemoryKind(type);
  return kind == MemoryKind::UNKNOWN;
}

/// Get the depth of a buffer or stream channel. Note that only if the defining
/// operation of the buffer is not a BufferOp or stream types, the returned
/// result will be 1.
unsigned codo::getBufferDepth(Value memref) {
  if (auto streamType = memref.getType().dyn_cast<StreamType>()) {
    return streamType.getDepth();
  } else if (auto bufferOp = findBufferOp(memref))
    return bufferOp.getBufferDepth();
  return 1;
}

/// Find buffer value or buffer op across the dataflow hierarchy.
Value codo::findBuffer(Value memref) {
  if (auto arg = memref.dyn_cast<BlockArgument>()) {
    if (auto node = dyn_cast<NodeOp>(arg.getParentBlock()->getParentOp()))
      return findBuffer(node->getOperand(arg.getArgNumber()));
    else if (auto schedule =
                 dyn_cast<ScheduleOp>(arg.getParentBlock()->getParentOp()))
      return findBuffer(schedule->getOperand(arg.getArgNumber()));
    return memref;
  } else if (auto viewOp = memref.getDefiningOp<ViewLikeOpInterface>())
    return findBuffer(viewOp.getViewSource());
  else if (auto buffer = memref.getDefiningOp<codo::BufferLikeInterface>())
    return buffer.getMemref();
  return Value();
}
codo::BufferLikeInterface codo::findBufferOp(Value memref) {
  if (auto buffer = findBuffer(memref))
    return buffer.getDefiningOp<codo::BufferLikeInterface>();
  return codo::BufferLikeInterface();
}


bool codo::isExtBuffer(Value memref) {
  if (auto type = memref.getType().dyn_cast<MemRefType>())
    return isDram(type);
  return false;
}


/// Check whether the given use has read/write semantics.
bool codo::isRead(OpOperand &use) {
  // For NodeOp and ScheduleOp, we don't rely on memory effect interface.
  // Instead, we delve into its region to figure out the effect.
  if (auto node = dyn_cast<NodeOp>(use.getOwner()))
    return llvm::any_of(
        node.getBody().getArgument(use.getOperandNumber()).getUses(),
        [](OpOperand &argUse) { return isRead(argUse); });
  else if (auto schedule = dyn_cast<ScheduleOp>(use.getOwner()))
    return llvm::any_of(
        schedule.getBody().getArgument(use.getOperandNumber()).getUses(),
        [](OpOperand &argUse) { return isRead(argUse); });
  else if (auto view = dyn_cast<ViewLikeOpInterface>(use.getOwner()))
    return llvm::any_of(view->getUses(),
                        [](OpOperand &viewUse) { return isRead(viewUse); });
  return hasEffect<MemoryEffects::Read>(use.getOwner(), use.get()) ||
         isa<StreamReadOp>(use.getOwner());
}

// TODO
bool codo::isWritten(OpOperand &use) {
  // For ScheduleOp, we don't rely on memory effect interface. Instead, we delve
  // into its region to figure out the effect. However, for NodeOp, we don't
  // need this recursive approach any more.
  if (auto node = dyn_cast<NodeOp>(use.getOwner()))
    return node.getOperandKind(use) == OperandKind::OUTPUT;
  else if (auto schedule = dyn_cast<ScheduleOp>(use.getOwner()))
    return llvm::any_of(
        schedule.getBody().getArgument(use.getOperandNumber()).getUses(),
        [](OpOperand &argUse) { return isWritten(argUse); });
  else if (auto view = dyn_cast<ViewLikeOpInterface>(use.getOwner()))
    return llvm::any_of(view->getUses(),
                        [](OpOperand &viewUse) { return isWritten(viewUse); });
  return hasEffect<MemoryEffects::Write>(use.getOwner(), use.get()) ||
         isa<StreamWriteOp>(use.getOwner());
}
//===----------------------------------------------------------------------===//
// Linalg analysis utils
//===----------------------------------------------------------------------===//

bool codo::isElementwiseGenericOp(linalg::GenericOp op) {
  // All loops must be parallel loop.
  if (op.getNumParallelLoops() != op.getNumLoops())
    return false;

  for (auto valueMap : llvm::zip(op.getOperands(), op.getIndexingMapsArray())) {
    auto type = std::get<0>(valueMap).getType().dyn_cast<ShapedType>();
    auto map = std::get<1>(valueMap);

    // If the operand doens't have static shape, the index map must be identity.
    if (!type || !type.hasStaticShape()) {
      if (!map.isIdentity())
        return false;
      continue;
    }

    // Otherwise, each dimension must either have a size of one or have identity
    // access index.
    unsigned index = map.getNumDims() - type.getRank();
    for (auto shapeExpr : llvm::zip(type.getShape(), map.getResults())) {
      auto dimSize = std::get<0>(shapeExpr);
      auto expr = std::get<1>(shapeExpr);
      if (expr != getAffineDimExpr(index++, expr.getContext()) && dimSize != 1)
        return false;
    }
  }
  return true;
}



//===----------------------------------------------------------------------===//
// HLS resource and timing attributes
//===----------------------------------------------------------------------===//

/// Timing attribute utils.
TimingAttr codo::getTiming(Operation *op) {
  return op->getAttrOfType<TimingAttr>("timing");
}
void codo::setTiming(Operation *op, TimingAttr timing) {
  assert(timing.getBegin() <= timing.getEnd() && "invalid timing attribute");
  op->setAttr("timing", timing);
}
void codo::setTiming(Operation *op, int64_t begin, int64_t end, int64_t latency,
                    int64_t minII) {
  auto timing = TimingAttr::get(op->getContext(), begin, end, latency, minII);
  setTiming(op, timing);
}

/// Resource attribute utils.
ResourceAttr codo::getResource(Operation *op) {
  return op->getAttrOfType<ResourceAttr>("resource");
}
void codo::setResource(Operation *op, ResourceAttr resource) {
  op->setAttr("resource", resource);
}
void codo::setResource(Operation *op, int64_t lut, int64_t dsp, int64_t bram) {
  auto resource = ResourceAttr::get(op->getContext(), lut, dsp, bram);
  setResource(op, resource);
}

/// Loop information attribute utils.
LoopInfoAttr codo::getLoopInfo(Operation *op) {
  return op->getAttrOfType<LoopInfoAttr>("loop_info");
}
void codo::setLoopInfo(Operation *op, LoopInfoAttr loopInfo) {
  op->setAttr("loop_info", loopInfo);
}
void codo::setLoopInfo(Operation *op, int64_t flattenTripCount,
                      int64_t iterLatency, int64_t minII) {
  auto loopInfo =
      LoopInfoAttr::get(op->getContext(), flattenTripCount, iterLatency, minII);
  setLoopInfo(op, loopInfo);
}



//===----------------------------------------------------------------------===//
// codo attribute utils
//===----------------------------------------------------------------------===//
/// Loop directives attribute utils.
LoopDirectiveAttr codo::getLoopDirective(Operation *op) {
  return op->getAttrOfType<LoopDirectiveAttr>("loop_directive");
}
void codo::setLoopDirective(Operation *op, LoopDirectiveAttr loopDirective) {
  op->setAttr("loop_directive", loopDirective);
}
void codo::setLoopDirective(Operation *op, bool pipeline, int64_t targetII,
                           bool dataflow, bool flatten) {
  auto loopDirective = LoopDirectiveAttr::get(op->getContext(), pipeline,
                                              targetII, dataflow, flatten);
  setLoopDirective(op, loopDirective);
}

/// Parrallel and point loop attribute utils.
void codo::setParallelAttr(Operation *op) {
  op->setAttr("parallel", UnitAttr::get(op->getContext()));
}
bool codo::hasParallelAttr(Operation *op) {
  return op->hasAttrOfType<UnitAttr>("parallel");
}
void codo::setPointAttr(Operation *op) {
  op->setAttr("point", UnitAttr::get(op->getContext()));
}
bool codo::hasPointAttr(Operation *op) {
  return op->hasAttrOfType<UnitAttr>("point");
}

bool codo::hasReduntantAttr(Operation *op) {
  return op->hasAttrOfType<UnitAttr>("reduntant");
}
void codo::setReduntantAttr(Operation *op) {
  op->setAttr("reduntant", UnitAttr::get(op->getContext()));
}


/// Function directives attribute utils.
FuncDirectiveAttr codo::getFuncDirective(Operation *op) {
  return op->getAttrOfType<FuncDirectiveAttr>("func_directive");
}
void codo::setFuncDirective(Operation *op, FuncDirectiveAttr funcDirective) {
  op->setAttr("func_directive", funcDirective);
}
void codo::setFuncDirective(Operation *op, bool pipeline, int64_t targetInterval,
                           bool dataflow) {
  auto funcDirective = FuncDirectiveAttr::get(op->getContext(), pipeline,
                                              targetInterval, dataflow);
  setFuncDirective(op, funcDirective);
}


/// Top and runtime function attribute utils.
void codo::setTopFuncAttr(Operation *op) {
  op->setAttr("top_func", UnitAttr::get(op->getContext()));
}
bool codo::hasTopFuncAttr(Operation *op) {
  return op->hasAttrOfType<UnitAttr>("top_func");
}
// TODO: remove this function
void codo::setRuntimeAttr(Operation *op) {
  op->setAttr("runtime", UnitAttr::get(op->getContext()));
}
// TODO: remove this function
bool codo::hasRuntimeAttr(Operation *op) {
  return op->hasAttrOfType<UnitAttr>("runtime");
}


/// Apply optimization strategy to a loop band. The ancestor function is also
/// passed in because the post-tiling optimizations have to take function as
/// target, e.g. canonicalizer and array partition.
bool codo::applyOptStrategy(AffineLoopBand &band, func::FuncOp func,
                                FactorList tileList, unsigned targetII) {
  // By design the input function must be the ancestor of the input loop band.
  if (!func->isProperAncestor(band.front()))
    return false;

  // Apply loop tiling.
  if (!applyLoopTiling(band, tileList))
    return false;

  // Apply loop pipelining.
  if (!applyLoopPipelining(band, band.size() - 1, targetII))
    return false;

  // Apply memory access optimizations and the best suitable array partition
  // strategy to the function.
  // applyMemoryOpts(func);
  // applyAutoArrayPartition(func);
  return true;
}

/// Apply optimization strategy to a function.
bool codo::applyOptStrategy(func::FuncOp func,
                                ArrayRef<FactorList> tileLists,
                                ArrayRef<unsigned> targetIIs) {
  AffineLoopBands bands;
  getLoopBands(func.front(), bands);
  assert(bands.size() == tileLists.size() && bands.size() == targetIIs.size() &&
         "unexpected size of tile lists or target IIs");

  // Apply loop tiling to all loop bands.
  for (unsigned i = 0, e = bands.size(); i < e; ++i)
    if (!applyLoopTiling(bands[i], tileLists[i]))
      return false;

  for (unsigned i = 0, e = bands.size(); i < e; ++i)
    if (!applyLoopPipelining(bands[i], bands[i].size() - 1, targetIIs[i]))
      return false;

  // Apply memory access optimizations and the best suitable array partition
  // strategy to the function.
  // applyMemoryOpts(func);
  // applyAutoArrayPartition(func);
  return true;
}

bool codo::is_gemm(affine::AffineForOp outermostLoop) {
  // 1. Check for a valid loop structure.
  AffineLoopBand band;
  affine::AffineForOp innermostLoop =
      getLoopBandFromOutermost(outermostLoop, band);
  if (!innermostLoop) {
    return false;
  }
  size_t depth = band.size();
  if (depth != 3 && depth != 4) {
    return false;
  }
  Block *body = innermostLoop.getBody();

  // 2. Check operation counts using a "bag of ops" approach.
  SmallVector<affine::AffineLoadOp, 3> loads;
  SmallVector<Operation *, 1> muls;
  SmallVector<Operation *, 1> adds;
  SmallVector<affine::AffineStoreOp, 1> stores;

  for (auto &op : body->getOperations()) {
    if (auto load = dyn_cast<affine::AffineLoadOp>(op))
      loads.push_back(load);
    else if (isa<arith::MulFOp, arith::MulIOp>(op))
      muls.push_back(&op);
    else if (isa<arith::AddFOp, arith::AddIOp>(op))
      adds.push_back(&op);
    else if (auto store = dyn_cast<affine::AffineStoreOp>(op))
      stores.push_back(store);
  }

  if (loads.size() != 3 || muls.size() != 1 || adds.size() != 1 ||
      stores.size() != 1) {
    return false;
  }

  auto storeOp = stores.front();
  auto addOp = adds.front();
  auto mulOp = muls.front();

  // 3. Verify the dataflow connections for C += A * B.
  // The store must get its value from the add operation.
  if (storeOp.getValue() != addOp->getResult(0)) return false;

  // The add must get one operand from the mul, and the other from a load (loadC).
  affine::AffineLoadOp loadC = nullptr;
  if (addOp->getOperand(0) == mulOp->getResult(0)) {
    loadC = addOp->getOperand(1).getDefiningOp<affine::AffineLoadOp>();
  } else if (addOp->getOperand(1) == mulOp->getResult(0)) {
    loadC = addOp->getOperand(0).getDefiningOp<affine::AffineLoadOp>();
  }
  if (!loadC) return false;

  // The store and the load for C must access the same element.
  if (storeOp.getMemRef() != loadC.getMemRef() ||
      storeOp.getAffineMap() != loadC.getAffineMap()) {
    return false;
  }

  // The mul must get its operands from the other two loads (loadA, loadB).
  affine::AffineLoadOp loadA = nullptr, loadB = nullptr;
  for (auto load : loads) {
    if (load != loadC) { // Find the two loads that are not loadC.
      if (!loadA) loadA = load;
      else loadB = load;
    }
  }
  if (!loadA || !loadB) return false; // A and B loads not found.

  llvm::outs()<<"Here 1"<<"\n";

  // Check that mul's operands are indeed from loadA and loadB.
  if (!((mulOp->getOperand(0) == loadA.getResult() &&
         mulOp->getOperand(1) == loadB.getResult()) ||
        (mulOp->getOperand(0) == loadB.getResult() &&
         mulOp->getOperand(1) == loadA.getResult()))) {
    return false;
  }
  // llvm::outs()<<"Here 2"<<"\n";
  // // 4. Identify the unique reduction dimension.
  // AffineMap mapA = loadA.getAffineMap();
  // AffineMap mapB = loadB.getAffineMap();
  // AffineMap mapC = storeOp.getAffineMap();

  // llvm::outs()<<"Here 3"<<"\n";
  // llvm::outs()<<mapA.getNumDims()<<"\n";
  // llvm::outs()<<mapB.getNumDims()<<"\n";
  // llvm::outs()<<mapC.getNumDims()<<"\n";
  // llvm::outs()<<depth<<"\n";

  // if (mapA.getNumDims() != depth-1 || mapB.getNumDims() != depth-1 ||
  //     mapC.getNumDims() != depth-1) {
  //   return false;
  // }
  // llvm::outs()<<"Here 4"<<"\n";
  // auto getUsedDims = [&](AffineMap map) {
  //   llvm::SmallBitVector dims(depth);
  //   map.walkExprs([&](AffineExpr expr) {
  //     if (auto dimExpr = expr.dyn_cast<AffineDimExpr>())
  //       dims.set(dimExpr.getPosition());
  //   });
  //   return dims;
  // };

  // llvm::SmallBitVector dimsA = getUsedDims(mapA);
  // llvm::SmallBitVector dimsB = getUsedDims(mapB);
  // llvm::SmallBitVector dimsC = getUsedDims(mapC);
  

  // // A reduction dimension must appear in A and B, but NOT in C.
  // llvm::SmallBitVector reductionCandidates = dimsA; // Start with dims from A.
  // reductionCandidates &= dimsB;                   // Find common dims in A and B.
  // // --- CORRECTED LINE ---
  // reductionCandidates &= ~dimsC;                  // Remove any dims that are also in C.

  // // There must be exactly one reduction dimension.
  // if (reductionCandidates.count() != 1) {
  //   return false;
  // }
  // llvm::outs()<<"Here 5"<<"\n";

  // 5. Success! The pattern is a GEMM. Tag the outermost loop.
  outermostLoop->setAttr("gemm_loop",
                         UnitAttr::get(outermostLoop->getContext()));

  return true;
}

FPGADeviceInfoAttr codo::getFPGADeviceInfo(Operation *op) {
  return op->getAttrOfType<FPGADeviceInfoAttr>("FPGADeviceInfo");
}
void codo::setFPGADeviceInfo(Operation *op, FPGADeviceInfoAttr fpgadevice) {
  op->setAttr("FPGADeviceInfo", fpgadevice);
}
void codo::setFPGADeviceInfo(Operation *op, int32_t number) {
  auto fpgadevice = FPGADeviceInfoAttr::get(op->getContext(), number);
  setFPGADeviceInfo(op, fpgadevice);
}
  
// #define GET_TYPEDEF_CLASSES
// #include "codo/Dialect/codoOpsTypes.cpp.inc"

// #define GET_ATTRDEF_CLASSES
// #include "codo/Dialect/codoAttributes.cpp.inc"

// #include "codo/Dialect/codoEnums.cpp.inc"

// FPGADeviceEnum codo::getFPGADevice(Operation *op) {
//   return op->getAttrOfType<FPGADeviceEnum>("FPGADeviceEnum");
// }
// void codo::setResource(Operation *op, ResourceAttr resource) {
//   op->setAttr("resource", resource);
// }
// void codo::setResource(Operation *op, int64_t lut, int64_t dsp, int64_t bram) {
//   auto resource = ResourceAttr::get(op->getContext(), lut, dsp, bram);
//   setResource(op, resource);
// }
  
// FPGADeviceInfoAttr codo::getFPGADeviceInfo(Operation *op) {
//   return op->getAttrOfType<FPGADeviceInfoAttr>("FPGADeviceInfo");
// }
// void codo::setFPGADeviceInfo(Operation *op, FPGADeviceInfoAttr fpgadevice) {
//   op->setAttr("FPGADeviceInfo", fpgadevice);
// }
// void codo::setFPGADeviceInfo(Operation *op, int32_t number) {
//   auto fpgadevice = FPGADeviceInfoAttr::get(op->getContext(), number);
//   setFPGADeviceInfo(op, fpgadevice);
// }


// FuncDirectiveAttr codo::getFuncDirective(Operation *op) {
//   return op->getAttrOfType<FuncDirectiveAttr>("func_directive");
// }
// void codo::setFuncDirective(Operation *op, FuncDirectiveAttr funcDirective) {
//   op->setAttr("func_directive", funcDirective);
// }
// void codo::setFuncDirective(Operation *op, bool pipeline, int64_t targetInterval,
//                            bool dataflow) {
//   auto funcDirective = FuncDirectiveAttr::get(op->getContext(), pipeline,
//                                               targetInterval, dataflow);
//   setFuncDirective(op, funcDirective);
// }
