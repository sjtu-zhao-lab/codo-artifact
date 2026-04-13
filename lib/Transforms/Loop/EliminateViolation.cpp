#include "mlir/IR/Builders.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Operation.h"
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/Func/IR/FuncOps.h" // For func::FuncOp
#include "mlir/Dialect/Arith/IR/Arith.h" // For arith::ConstantOp
#include "mlir/Pass/Pass.h"             // For Pass
#include "mlir/Support/LogicalResult.h"
#include "mlir/Transforms/DialectConversion.h" // For OpRewritePattern, PatternRewriter
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/DenseSet.h"
#include "llvm/Support/raw_ostream.h"
#include "mlir/IR/IRMapping.h"          // For cloning and value mapping
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "mlir/Dialect/Utils/StaticValueUtils.h" // For getConstantIntValue
#include "mlir/Dialect/MemRef/IR/MemRef.h" 

#include "codo/Transforms/Passes.h" // For the new pass base
#include "codo/Support/Utils.h"   // For getLoopBandFromOutermost
#include "codo/Init_All_Dialects.h" // Include if codo dialects are used directly in this pass

// Your original TableGen include style:
// // This will be generated from Passes.td based on the 'EliminateViolation' definition
// #define GEN_PASS_DEF_ELIMINATEVIOLATION  // --> This line defines the macro
// #include "codo/Transforms/Passes.h.inc" // --> This line includes the generated header
#define DEBUG_TYPE "eliminate-violation" // For LLVM_DEBUG
using namespace mlir;
using namespace mlir::func;
using namespace mlir::affine;
using namespace codo;

////////////////////////////////////////////////////////////////

// Forward declaration
static bool canFuseLoopsWithSameBoundAndCommonLoad(const SmallVector<affine::AffineForOp, 4>& sequence,
                                                   Value& commonLoadMemref);

// Helper function to find the single AffineLoadOp and AffineStoreOp in the innermost loop
// Returns true if successful, false otherwise.
bool getInnermostLoadStore(affine::AffineForOp outermostLoop,
                           affine::AffineLoadOp &loadOp,
                           affine::AffineStoreOp &storeOp) {
    affine::AffineForOp currentLoop = outermostLoop;
    // Traverse to the innermost loop of a potentially perfectly nested band
    while (true) {
        auto innerForOpsRange = currentLoop.getBody()->getOps<affine::AffineForOp>();
        if (innerForOpsRange.empty()) {
            break; // currentLoop is the innermost
        }
        // Assuming a single AffineForOp for perfectly nested loops, consistent with getLoopBandFromOutermost
        if (std::next(innerForOpsRange.begin()) != innerForOpsRange.end()) {
             return false; // More than one loop at this level, not a simple band.
        }
        currentLoop = *innerForOpsRange.begin();
    }

    Block *innermostBody = currentLoop.getBody();
    SmallVector<affine::AffineLoadOp, 2> loads;
    SmallVector<affine::AffineStoreOp, 2> stores;

    for (Operation &op : innermostBody->getOperations()) {
        if (auto l = dyn_cast<affine::AffineLoadOp>(op)) {
            loads.push_back(l);
        } else if (auto s = dyn_cast<affine::AffineStoreOp>(op)) {
            stores.push_back(s);
        } else if (!isa<affine::AffineYieldOp>(op)) {
            // Allow other ops; previous strictness might have been an issue
        }
    }

    if (loads.size() != 1 || stores.size() != 1) {
        return false;
    }
    loadOp = loads.front();
    storeOp = stores.front();
    return true;
}


// Checks if loops load a common argument (memref) and use the same access pattern (AffineMap and operand count).
static bool canFuseLoopsWithSameBoundAndCommonLoad(const SmallVector<affine::AffineForOp, 4>& sequence,
                                                   Value& commonLoadMemref) {
    if (sequence.empty()) return false;

    affine::AffineLoadOp firstLoadOp;
    affine::AffineStoreOp firstStoreOp; // Dummy, only load is checked for commonality

    if (!getInnermostLoadStore(sequence.front(), firstLoadOp, firstStoreOp)) {
        return false;
    }
    commonLoadMemref = firstLoadOp.getMemRef();
    AffineMap firstLoadMap = firstLoadOp.getAffineMap();
    unsigned firstLoadMapNumOperands = firstLoadOp.getMapOperands().size();

    for (size_t i = 1; i < sequence.size(); ++i) {
        affine::AffineForOp currentLoop = sequence[i];
        affine::AffineLoadOp currentLoadOp;
        affine::AffineStoreOp currentStoreOp; // Dummy

        if (!getInnermostLoadStore(currentLoop, currentLoadOp, currentStoreOp)) {
            return false;
        }

        if (currentLoadOp.getMemRef() != commonLoadMemref ||
            currentLoadOp.getAffineMap() != firstLoadMap ||
            currentLoadOp.getMapOperands().size() != firstLoadMapNumOperands) {
            return false;
        }
    }
    return true;
}


// Helper function to check if all loops in a band have constant bounds
bool allLoopsHaveConstantBounds(const AffineLoopBand &band) {
  if (band.empty()) {
    return false;
  }
  for (AffineForOp loop : band) {
    if (!loop.hasConstantBounds()) {
      return false;
    }
  }
  return true;
}

// Helper function to compare two loop bands for identical structure and bounds
bool areLoopBandsIdentical(const AffineLoopBand &band1, const AffineLoopBand &band2) {
  if (band1.size() != band2.size()) {
    return false;
  }
  if (band1.empty()) { // Both must be non-empty if sizes are equal and >0
    return false;
  }
  // Caller (runOnOperation) ensures allLoopsHaveConstantBounds for both bands.
  for (size_t i = 0; i < band1.size(); ++i) {
    AffineForOp loop1 = band1[i];
    AffineForOp loop2 = band2[i];
    // Constant bounds are pre-checked by the caller.
    if (loop1.getConstantLowerBound() != loop2.getConstantLowerBound() ||
        loop1.getConstantUpperBound() != loop2.getConstantUpperBound() ||
        loop1.getStep() != loop2.getStep()) {
      return false;
    }
  }
  return true;
}


namespace {

struct FuseInitThenComputePattern : public OpRewritePattern<affine::AffineForOp> {
  using OpRewritePattern<affine::AffineForOp>::OpRewritePattern;

  bool isInitializationLoop(affine::AffineForOp loop,
                            affine::AffineStoreOp &foundStoreOp,
                            Value &constantValResult) const {
    AffineLoopBand band;
    affine::AffineForOp innermostLoop = getLoopBandFromOutermost(loop, band);
    // getInnermostLoopFromOuter(loop);
    if (!innermostLoop) return false;

    Block *body = innermostLoop.getBody();
    affine::AffineStoreOp storeOp;
    bool hasYield = false;
    int nonYieldOpCount = 0;
    for (Operation &op : body->getOperations()) {
        if (auto sOp = dyn_cast<affine::AffineStoreOp>(op)) {
            if (storeOp) return false;
            storeOp = sOp;
            nonYieldOpCount++;
        } else if (isa<affine::AffineYieldOp>(op)) {
            hasYield = true;
        } else { // Any other op means it's not a simple init loop (e.g. no other loads/computations)
            return false;
        }
    }

    if (!storeOp || !hasYield || nonYieldOpCount != 1) {
        return false;
    }

    Value valToStore = storeOp.getValueToStore();
    if (valToStore.getDefiningOp<arith::ConstantOp>()) {
        foundStoreOp = storeOp;
        constantValResult = valToStore;
        return true;
    }
    return false;
  }

  struct ReductionInfo {
    affine::AffineForOp innermostReductionLoop;
    affine::AffineLoadOp loadOp;    // Load from targetMemref
    affine::AffineStoreOp storeOp;  // Store to targetMemref
    Operation* reductionOp;         // The binary op like arith.addf
    Value otherOperand;             // The other operand to reductionOp (not from targetMemref)
    SmallVector<Operation*, 4> nonReductionOpsInBody; // Other ops in the loop body to be cloned
    SmallVector<affine::AffineForOp, 1> reductionDimensionLoops;
    SmallVector<affine::AffineForOp, 2> parallelDimensionLoops;
  };

  // Function to populate these:
  void identifyReductionDimensions(affine::AffineForOp computeLoopCandidate,
                                   ReductionInfo &info)  const{
    if (!info.innermostReductionLoop || !info.loadOp) {
        // Not a valid reduction or info not populated
        return;
    }

    SmallVector<affine::AffineForOp, 3> currentLoopNest;
    affine::AffineForOp currentLoop = computeLoopCandidate;
    while (currentLoop) {
        currentLoopNest.push_back(currentLoop);
        if (currentLoop == info.innermostReductionLoop) break;

        auto innerLoops = currentLoop.getBody()->getOps<affine::AffineForOp>();
        if (innerLoops.empty() || std::next(innerLoops.begin()) != innerLoops.end()) {
            // Not a simple perfect nest or structure not handled for this analysis
            // Or reached innermost without it being the info.innermostReductionLoop yet (should not happen if info is correct)
            currentLoopNest.clear(); // Invalid path
            break;
        }
        currentLoop = *innerLoops.begin();
    }
    if (currentLoopNest.empty() || currentLoopNest.back() != info.innermostReductionLoop) {
        LLVM_DEBUG(llvm::dbgs() << "FuseInitThenCompute: Could not reconstruct loop nest for dimension analysis.\n");
        return;
    }


    DenseSet<Value> accumulatorIndexOperands;
    AffineMap map = info.loadOp.getAffineMap();
    ValueRange mapOperands = info.loadOp.getMapOperands();

    // Collect operands that are used for dimension indexing of the accumulator
    for (unsigned i = 0; i < map.getNumDims(); ++i) {
        if (i < mapOperands.size()) { // Should always be true for valid IR
             // We are interested in the actual Value used as a map dimension input.
             // The map itself might have d0, d1, ... but mapOperands provides the actual Values.
            accumulatorIndexOperands.insert(mapOperands[i]);
        }
    }
    // A more robust way might be to analyze the AffineApplyOp for the load/store.
    // Or, if getMapOperands() gives IVs directly that match map.getDim(i), that's easier.
    // For simplicity, assuming mapOperands[0...map.getNumDims()-1] are the dimension inputs.

    for (affine::AffineForOp loopOp : currentLoopNest) {
        Value iv = loopOp.getInductionVar();
        bool isReductionDim = true;
        // Check if this IV is used to index the accumulator
        if (accumulatorIndexOperands.count(iv)) {
            isReductionDim = false;
        }

        // Alternative check: Iterate through map.getResults()
        // and see if the IV (or an expression of it) forms part of any result.
        // This is more complex as it involves analyzing AffineExprs.
        // The check against mapOperands is usually sufficient if the IR is well-formed
        // and mapOperands directly list the IVs used for indexing.

        if (isReductionDim) {
            info.reductionDimensionLoops.push_back(loopOp);
        } else {
            info.parallelDimensionLoops.push_back(loopOp);
        }
    }
     LLVM_DEBUG(llvm::dbgs() << "FuseInitThenCompute: Identified "
                           << info.reductionDimensionLoops.size() << " reduction dims and "
                           << info.parallelDimensionLoops.size() << " parallel dims.\n");
  }


  // ... inside FuseInitThenComputePattern struct ...

// (ReductionInfo struct and other helpers remain the same)

// ... inside FuseInitThenComputePattern struct ...

// (ReductionInfo struct and other helpers remain the same)

// This function is updated to recognize arith.maximumf/minimumf patterns.
bool isComputeLoopReduction(affine::AffineForOp computeLoopCandidate,
                              Value targetMemref,
                              ReductionInfo &info) const {
    AffineLoopBand band;
    info.innermostReductionLoop = getLoopBandFromOutermost(computeLoopCandidate, band);
    if (!info.innermostReductionLoop) {
        if (computeLoopCandidate.getBody() && computeLoopCandidate.getBody()->getOps<affine::AffineForOp>().empty()){
            info.innermostReductionLoop = computeLoopCandidate;
        } else {
            LLVM_DEBUG(llvm::dbgs() << "FuseInitThenCompute: computeLoopCandidate is not a simple band or structure not handled.\n");
            return false;
        }
    }

    Block *body = info.innermostReductionLoop.getBody();
    if (!body) return false;

    affine::AffineStoreOp foundStoreOp;
    // Find the single store to the target accumulator memref.
    body->walk([&](affine::AffineStoreOp store) {
        if (store.getMemRef() == targetMemref) {
            if (!foundStoreOp) {
                foundStoreOp = store;
            } else {
                // Found multiple stores, which we don't handle.
                foundStoreOp = nullptr;
                return WalkResult::interrupt();
            }
        }
    });

    if (!foundStoreOp) {
        LLVM_DEBUG(llvm::dbgs() << "FuseInitThenCompute: No single store to targetMemref found.\n");
        return false;
    }
    info.storeOp = foundStoreOp;

    Value valueStored = foundStoreOp.getValueToStore();
    Operation* defOfValueStored = valueStored.getDefiningOp();
    if (!defOfValueStored) return false;

    // --- START of REVISED MODIFICATION ---
    
    affine::AffineLoadOp foundLoadOp;
    
    // Check for a known reduction operation. This now includes max/min ops.
    if (defOfValueStored->getNumOperands() == 2 && defOfValueStored->getNumResults() == 1 &&
        isa<// Standard arithmetic reductions
            arith::AddFOp, arith::MulFOp, arith::AddIOp, arith::MulIOp,
            // Bitwise reductions
            arith::AndIOp, arith::OrIOp, arith::XOrIOp,
            // Max/Min reductions (the new part)
            arith::MaximumFOp, arith::MinimumFOp
            // arith::MaximumSIOp, arith::MaximumUIOp,
            // arith::MinimumSIOp, arith::MinimumUIOp
           >(defOfValueStored)) {

        info.reductionOp = defOfValueStored;
        Value operand0 = info.reductionOp->getOperand(0);
        Value operand1 = info.reductionOp->getOperand(1);

        auto load0 = dyn_cast_or_null<affine::AffineLoadOp>(operand0.getDefiningOp());
        auto load1 = dyn_cast_or_null<affine::AffineLoadOp>(operand1.getDefiningOp());

        if (load0 && load0.getMemRef() == targetMemref) {
            foundLoadOp = load0;
            info.otherOperand = operand1;
        } else if (load1 && load1.getMemRef() == targetMemref) {
            foundLoadOp = load1;
            info.otherOperand = operand0;
        }
    
    // We can keep the select(cmp) pattern for older IR or other lowering paths,
    // but the `arith.maximumf` pattern is now the primary path for this case.
    } else if (auto selectOp = dyn_cast<arith::SelectOp>(defOfValueStored)) {
        Operation* cmpOperation = selectOp.getCondition().getDefiningOp();
        if (!cmpOperation) return false;

        if (!isa<arith::CmpFOp, arith::CmpIOp>(cmpOperation)) {
            LLVM_DEBUG(llvm::dbgs() << "FuseInitThenCompute: Select condition is not a CmpF/CmpI op.\n");
            return false;
        }

        Value cmpLhs = cmpOperation->getOperand(0);
        Value cmpRhs = cmpOperation->getOperand(1);

        Value selectTrue = selectOp.getTrueValue();
        Value selectFalse = selectOp.getFalseValue();

        if (!((selectTrue == cmpLhs && selectFalse == cmpRhs) ||
              (selectTrue == cmpRhs && selectFalse == cmpLhs))) {
             LLVM_DEBUG(llvm::dbgs() << "FuseInitThenCompute: Select operands do not match Cmp operands.\n");
             return false;
        }

        auto loadLhs = dyn_cast_or_null<affine::AffineLoadOp>(cmpLhs.getDefiningOp());
        auto loadRhs = dyn_cast_or_null<affine::AffineLoadOp>(cmpRhs.getDefiningOp());

        if (loadLhs && loadLhs.getMemRef() == targetMemref) {
            foundLoadOp = loadLhs;
            info.otherOperand = cmpRhs;
        } else if (loadRhs && loadRhs.getMemRef() == targetMemref) {
            foundLoadOp = loadRhs;
            info.otherOperand = cmpLhs;
        }
        
        info.reductionOp = selectOp;
    }
    // --- END of REVISED MODIFICATION ---

    if (!foundLoadOp) {
        LLVM_DEBUG(llvm::dbgs() << "FuseInitThenCompute: Reduction pattern not recognized or does not use a load from targetMemref.\n");
        return false;
    }

    // Verify load and store access the same element (same map and operands)
    if (foundLoadOp.getAffineMap() != info.storeOp.getAffineMap() ||
        !std::equal(foundLoadOp.getMapOperands().begin(), foundLoadOp.getMapOperands().end(),
                    info.storeOp.getMapOperands().begin())) {
        LLVM_DEBUG(llvm::dbgs() << "FuseInitThenCompute: Load and store in reduction do not access the same element.\n");
        return false;
    }
    info.loadOp = foundLoadOp;

    // Collect other ops in the body. This logic is now simpler because we don't
    // need special handling for `maximumf`'s dependencies (it has none besides its operands).
    for (Operation &op : body->getOperations()) {
        Operation* conditionOp = nullptr;
        // This part is only relevant for the select(cmp) pattern.
        if (auto selOp = dyn_cast<arith::SelectOp>(info.reductionOp)) {
            conditionOp = selOp.getCondition().getDefiningOp();
        }

        if (&op == info.loadOp.getOperation() ||
            &op == info.storeOp.getOperation() ||
            &op == info.reductionOp ||
            (conditionOp && &op == conditionOp) || // Also exclude the CmpOp if it exists
            isa<affine::AffineYieldOp>(op)) {
            continue;
        }
        info.nonReductionOpsInBody.push_back(&op);
    }
    
    LLVM_DEBUG(llvm::dbgs() << "FuseInitThenCompute: Identified reduction pattern successfully.\n");
    return true;
}

// ... other includes remain the same

// ... inside the FuseInitThenComputePattern class

LogicalResult matchAndRewrite(affine::AffineForOp initLoopCandidate,
                                PatternRewriter &rewriter) const override {
    LLVM_DEBUG(llvm::dbgs() << "FuseInitThenCompute: Attempting match on: " << initLoopCandidate << "\n");

    // 1. Verify the pattern: an init loop followed by a compute loop.
    affine::AffineStoreOp initStoreOp;
    Value constantValResult;
    if (!isInitializationLoop(initLoopCandidate, initStoreOp, constantValResult)) {
        LLVM_DEBUG(llvm::dbgs() << "FuseInitThenCompute: Failed isInitializationLoop for " << initLoopCandidate << "\n");
        return failure();
    }

    Operation* nextOperation = initLoopCandidate->getNextNode();
    if (!nextOperation) return failure();
    auto computeLoopCandidate = dyn_cast<affine::AffineForOp>(nextOperation);
    if (!computeLoopCandidate) return failure();

    Value initializedMemref = initStoreOp.getMemRef();
    ReductionInfo reductionInfo;
    if (!isComputeLoopReduction(computeLoopCandidate, initializedMemref, reductionInfo)) {
        LLVM_DEBUG(llvm::dbgs() << "FuseInitThenCompute: Failed isComputeLoopReduction for " << computeLoopCandidate << "\n");
        return failure();
    }

    // 2. Analyze dimensions.
    identifyReductionDimensions(computeLoopCandidate, reductionInfo);
    // This pattern requires both parallel and reduction dimensions to apply the temp-array optimization.
    if (reductionInfo.reductionDimensionLoops.empty() || reductionInfo.parallelDimensionLoops.empty()) {
        LLVM_DEBUG(llvm::dbgs() << "FuseInitThenCompute: Pattern requires both parallel and reduction dimensions. Skipping.\n");
        return failure();
    }

    // 3. Start rewriting.
    Location loc = initLoopCandidate.getLoc();
    rewriter.setInsertionPoint(initLoopCandidate);

    // 4. Create a temporary accumulator (a memref).
    SmallVector<int64_t, 4> tempShape;
    for (auto parallelLoop : reductionInfo.parallelDimensionLoops) {
        if (!parallelLoop.hasConstantBounds()) return failure();
        tempShape.push_back(parallelLoop.getConstantUpperBound() - parallelLoop.getConstantLowerBound());
    }
    auto memrefType = initializedMemref.getType().cast<MemRefType>();
    auto tempMemRefType = MemRefType::get(tempShape, memrefType.getElementType());
    Value tempAccumulator = rewriter.create<memref::AllocOp>(loc, tempMemRefType);

    // 5. Build the new fused loop nest.
    IRMapping ivMap;
    SmallVector<Value, 4> parallelIVs;
    affine::AffineForOp outermostFusedLoop = nullptr;
    affine::AffineForOp innermostParallelLoop = nullptr;

    // Guard the insertion point. It will be restored when the guard goes out of scope.
    OpBuilder::InsertionGuard guard(rewriter);

    // 5.1 Manually create the outer parallel loops.
    for (auto parallelLoop : reductionInfo.parallelDimensionLoops) {
        auto newLoop = rewriter.create<affine::AffineForOp>(
            parallelLoop.getLoc(),
            parallelLoop.getConstantLowerBound(),
            parallelLoop.getConstantUpperBound(),
            parallelLoop.getStep().getSExtValue());

        if (!outermostFusedLoop) {
            outermostFusedLoop = newLoop;
        }
        innermostParallelLoop = newLoop; // Keep track of the innermost parallel loop.

        ivMap.map(parallelLoop.getInductionVar(), newLoop.getInductionVar());
        parallelIVs.push_back(newLoop.getInductionVar());
        
        rewriter.setInsertionPointToStart(newLoop.getBody());
    }

    // The rewriter's insertion point is now at the start of the innermostParallelLoop's body.

    // 5.2 Initialize the accumulator inside the parallel loops.
    rewriter.create<affine::AffineStoreOp>(loc, constantValResult, tempAccumulator, parallelIVs);
    
    // 5.3 Manually create the inner reduction loops.
    for (auto reductionLoop : reductionInfo.reductionDimensionLoops) {
        auto newLoop = rewriter.create<affine::AffineForOp>(
            reductionLoop.getLoc(),
            reductionLoop.getConstantLowerBound(),
            reductionLoop.getConstantUpperBound(),
            reductionLoop.getStep().getSExtValue());

        ivMap.map(reductionLoop.getInductionVar(), newLoop.getInductionVar());
        rewriter.setInsertionPointToStart(newLoop.getBody());
    }

    // The rewriter's insertion point is now at the start of the innermost reduction loop's body.

    // 5.4 Perform the reduction computation inside the innermost loop.
    Value currentAccumulatorValue = rewriter.create<affine::AffineLoadOp>(loc, tempAccumulator, parallelIVs);
    ivMap.map(reductionInfo.loadOp.getResult(), currentAccumulatorValue);

    for (Operation *op : reductionInfo.nonReductionOpsInBody) {
        rewriter.clone(*op, ivMap);
    }

    Operation *newReductionOp = rewriter.clone(*reductionInfo.reductionOp, ivMap);
    Value reducedValue = newReductionOp->getResult(0);
    rewriter.create<affine::AffineStoreOp>(loc, reducedValue, tempAccumulator, parallelIVs);

    // 6. Write the final result back to the target memref.
    // Set the insertion point before the terminator of the innermost parallel loop.
    rewriter.setInsertionPoint(innermostParallelLoop.getBody()->getTerminator());
    Value finalResult = rewriter.create<affine::AffineLoadOp>(loc, tempAccumulator, parallelIVs);

    SmallVector<Value> finalStoreOperands;
    for (Value operand : reductionInfo.storeOp.getMapOperands()) {
        finalStoreOperands.push_back(ivMap.lookupOrDefault(operand));
    }
    rewriter.create<affine::AffineStoreOp>(loc, finalResult, initializedMemref,
                                           reductionInfo.storeOp.getAffineMap(),
                                           finalStoreOperands);

    // 7. Clean up.
    // The InsertionGuard has restored the insertion point to be before initLoopCandidate.
    // Now, move it after the newly created fused loop to insert the dealloc.
    rewriter.setInsertionPointAfter(outermostFusedLoop);
    rewriter.create<memref::DeallocOp>(loc, tempAccumulator);

    rewriter.eraseOp(computeLoopCandidate);
    rewriter.eraseOp(initLoopCandidate);

    LLVM_DEBUG(llvm::dbgs() << "FuseInitThenCompute: Successfully fused init and compute loops.\n");
    return success();
}
};
}

namespace{
struct EliminateViolation: public EliminateViolationBase<EliminateViolation> {
  void getDependentDialects(DialectRegistry &registry) const override {
    registry.insert<AffineDialect, func::FuncDialect, arith::ArithDialect>(); // Added ArithDialect
    codo::registerAllDialects(registry); // Ensure CODO dialects are available
  }

  affine::AffineForOp fuseLoopsWithSameBound(OpBuilder& builder,
                                             const SmallVector<affine::AffineForOp, 4>& sequence,
                                             Value commonLoadMemrefToOptimize) {
    if (sequence.empty()) return nullptr;

    affine::AffineForOp firstLoopInSequence = sequence.front();
    OpBuilder::InsertionGuard guard(builder);
    builder.setInsertionPoint(firstLoopInSequence);

    AffineLoopBand firstBand;
    getLoopBandFromOutermost(firstLoopInSequence, firstBand);
    if (firstBand.empty()) return nullptr; // Should be caught by earlier checks

    SmallVector<affine::AffineForOp, 4> fusedLoopNest;
    OpBuilder::InsertionGuard bodyGuard(builder); // Not strictly needed with setInsertionPointToStart

    affine::AffineForOp outermostFusedLoop = nullptr;
    affine::AffineForOp innermostFusedLoop = nullptr;

    IRMapping ivMap; // Global IV map for the new fused loop structure

    // 1. Create the fused loop 
    for (size_t i = 0; i < firstBand.size(); ++i) {
        affine::AffineForOp originalLoopProto = firstBand[i];
        int64_t lb = originalLoopProto.getConstantLowerBound();
        int64_t ub = originalLoopProto.getConstantUpperBound();
        int64_t stepVal = originalLoopProto.getStep().getSExtValue();

        auto newLoop = builder.create<affine::AffineForOp>(
            originalLoopProto.getLoc(), lb, ub, stepVal);

        if (!outermostFusedLoop) outermostFusedLoop = newLoop;
        fusedLoopNest.push_back(newLoop);

        // Map IVs from ALL original loops in the sequence at this depth to the new fused IV
        for (const auto& seqLoopOp : sequence) {
            AffineLoopBand tempBand;
            getLoopBandFromOutermost(seqLoopOp, tempBand);
            if (i < tempBand.size()) { // tempBand might be shallower if there was an error earlier
                 ivMap.map(tempBand[i].getInductionVar(), newLoop.getInductionVar());
            }
        }

        builder.setInsertionPointToStart(newLoop.getBody()); // Prepare for next loop or body
        if (i == firstBand.size() - 1) {
            innermostFusedLoop = newLoop;
        }
    }
    if (!innermostFusedLoop) {
        if(outermostFusedLoop) outermostFusedLoop.erase(); // Clean up partially created shell
        return nullptr;
    }
    // Builder is now at the start of innermostFusedLoop's body

    Value commonLoadClonedResult = nullptr;
    AffineMap commonLoadOriginalAffineMap;

    // 2. If common load optimization is enabled, clone the common load ONCE.
    if (commonLoadMemrefToOptimize) {
        affine::AffineLoadOp firstOriginalLoadOpTemplate;
        affine::AffineStoreOp tempStore;

        if (getInnermostLoadStore(sequence.front(), firstOriginalLoadOpTemplate, tempStore) &&
            firstOriginalLoadOpTemplate.getMemRef() == commonLoadMemrefToOptimize) {

            commonLoadOriginalAffineMap = firstOriginalLoadOpTemplate.getAffineMap();
            SmallVector<Value> clonedMapOperands;
            for (Value originalMapOperand : firstOriginalLoadOpTemplate.getMapOperands()) {
                // Operands of the map should be remapped using ivMap (which contains IVs)
                clonedMapOperands.push_back(ivMap.lookupOrDefault(originalMapOperand));
            }

            auto clonedCommonLoad = builder.create<affine::AffineLoadOp>(
                firstOriginalLoadOpTemplate.getLoc(),
                commonLoadMemrefToOptimize, // This is the Value of the memref
                commonLoadOriginalAffineMap,
                clonedMapOperands);
            commonLoadClonedResult = clonedCommonLoad.getResult();
        } else {
            // Should not happen if canFuse... was true. Disable opt for safety.
            commonLoadMemrefToOptimize = nullptr;
        }
    }

    // 3. Clone the bodies of the original innermost loops into the fused innermost loop
    for (affine::AffineForOp originalOuterLoop : sequence) {
        AffineLoopBand currentOriginalBand;
        getLoopBandFromOutermost(originalOuterLoop, currentOriginalBand);
        if (currentOriginalBand.empty()) continue; // Should be caught by prior checks

        affine::AffineForOp originalInnermostLoop = currentOriginalBand.back();

        // Use a local map for body cloning, initialized with the global IV map.
        // This is crucial if ops within the body produce values used by other ops in the same body.
        IRMapping bodyCloneMap = ivMap;

        for (Operation &opToClone : originalInnermostLoop.getBody()->getOperations()) {
            if (isa<affine::AffineYieldOp>(opToClone)) continue;

            bool opReplacedByCommonLoad = false;
            if (commonLoadMemrefToOptimize && commonLoadClonedResult) {
                if (auto currentOriginalLoad = dyn_cast<affine::AffineLoadOp>(opToClone)) {
                    if (currentOriginalLoad.getMemRef() == commonLoadMemrefToOptimize &&
                        currentOriginalLoad.getAffineMap() == commonLoadOriginalAffineMap &&
                        currentOriginalLoad.getMapOperands().size() == firstBand.size()) { // Check if map operands match loop depth for safety
                        // This load matches the common load pattern.
                        // Map its result in bodyCloneMap to the single cloned load's result.
                        bodyCloneMap.map(currentOriginalLoad.getResult(), commonLoadClonedResult);
                        opReplacedByCommonLoad = true;
                    }
                }
            }

            if (!opReplacedByCommonLoad) {
                builder.clone(opToClone, bodyCloneMap);
            }
        }
    }

    // 4. Erase the original loops
    for (affine::AffineForOp loopToErase : sequence) {
        loopToErase.erase();
    }
    return outermostFusedLoop;
  }



  void runOnOperation() override {
    func::FuncOp funcOp = getOperation();

    if (funcOp.getBody().empty() || funcOp.getBody().front().empty()) {
      return;
    }
    Block &bodyBlock = funcOp.getBody().front();
    // Apply loop order optimization to each loop band.

    AffineLoopBands targetBands;
    getLoopBands(getOperation().front(), targetBands);
    for (auto &band : targetBands) {
      AffineLoopBand tileBand;
      AffineLoopBand pointBand;

      // If the current loop band can be split into a tile band and point band,
      // apply to these two partial bands separately. Otherwise, apply to the
      // whole loop band.
      if (getTileAndPointLoopBand(band, tileBand, pointBand)) {
        if (!tileBand.empty())
          applyAffineLoopOrderOpt(tileBand);
        if (!pointBand.empty())
          applyAffineLoopOrderOpt(pointBand);
      } else
        applyAffineLoopOrderOpt(band);
    }
    
    funcOp.walk([&](affine::AffineForOp forOp) {
        if (!isa<affine::AffineForOp>(forOp->getParentOp())) {
            // llvm::outs()<<"Not Found"<<"\n";
            if (is_gemm(forOp)) {
                // llvm::outs()<<"Found"<<"\n";
            }
        }
    });
    

    bool changedOuterLoop = true;
    while(changedOuterLoop) {
        changedOuterLoop = false;
        SmallVector<affine::AffineForOp, 4> currentPotentialSequence;
        Operation *currentOp = &bodyBlock.front();

        while (currentOp) {
            auto forOp = dyn_cast<affine::AffineForOp>(currentOp);

            // Corrected isTopLevelLoop check:
            // An AffineForOp is considered "top-level" for this pass if its direct parent
            // operation (the op owning the region it's in) is a FuncOp or TaskOp.
            bool isTopLevelLoop = forOp &&
                                  (isa<func::FuncOp>(forOp->getParentOp()) ||
                                   isa<codo::TaskOp>(forOp->getParentOp()));

            bool sequenceBrokenOrEnded = false;

            if (isTopLevelLoop) {
                AffineLoopBand band;
                getLoopBandFromOutermost(forOp, band);
                if (!band.empty() && allLoopsHaveConstantBounds(band)) {
                    if (currentPotentialSequence.empty()) {
                        currentPotentialSequence.push_back(forOp);
                    } else {
                        AffineLoopBand prevBand;
                        getLoopBandFromOutermost(currentPotentialSequence.back(), prevBand);
                        // prevBand must also have constant bounds (which it should if it was added).
                        // allLoopsHaveConstantBounds(prevBand) is implicitly true by construction.
                        if (!prevBand.empty() && areLoopBandsIdentical(band, prevBand)) {
                            currentPotentialSequence.push_back(forOp);
                        } else { // Identical band sequence broken
                            sequenceBrokenOrEnded = true;
                        }
                    }
                } else { // Not a suitable loop for sequences (e.g., no constant bounds, empty band)
                    sequenceBrokenOrEnded = true;
                }
            } else { // Not an AffineForOp, or not a top-level one for this pass's purpose
                sequenceBrokenOrEnded = true;
            }

            Operation* nextOp = currentOp->getNextNode();

            if (sequenceBrokenOrEnded || nextOp == nullptr) {
                if (currentPotentialSequence.size() >= 2) {
                    Value commonLoadMemref;
                    if (canFuseLoopsWithSameBoundAndCommonLoad(currentPotentialSequence, commonLoadMemref)) {
                        OpBuilder builder(currentPotentialSequence.front());
                        affine::AffineForOp fusedLoop = fuseLoopsWithSameBound(builder, currentPotentialSequence, commonLoadMemref);
                        if (fusedLoop) {
                            changedOuterLoop = true;
                            // After fusion, the IR is modified. Restart scan from beginning of the block
                            // to correctly handle new/modified ops and re-evaluate sequences.
                            // 'fusedLoop' is the new first op in the sequence's original position.
                            // To restart from the beginning of the block:
                            // currentOp = &bodyBlock.front(); // This would be part of break logic
                            break; 
                        }
                    }
                }
                currentPotentialSequence.clear();
                // If sequence was broken, and 'forOp' itself is a valid start for a new sequence
                if (forOp && sequenceBrokenOrEnded) { // 'forOp' is the op that broke sequence or just after a processed one
                     AffineLoopBand band;
                     getLoopBandFromOutermost(forOp, band); // Re-evaluate forOp
                     // Re-check isTopLevelLoop criteria for forOp as it might start a new sequence
                     bool forOpIsTopLevel = forOp &&
                                           (isa<func::FuncOp>(forOp->getParentOp()) ||
                                            isa<codo::TaskOp>(forOp->getParentOp()));

                     if (forOpIsTopLevel && !band.empty() && allLoopsHaveConstantBounds(band)) {
                        currentPotentialSequence.push_back(forOp);
                     }
                }
            }
            if (changedOuterLoop) break; // If fusion happened, restart the outer while loop
            currentOp = nextOp;
        }
    }

    // Note: To use the new FuseInitThenComputePattern, you would typically do something like:
    //
    MLIRContext *context = &getContext();
    RewritePatternSet patterns(context);
    patterns.add<FuseInitThenComputePattern>(context);
    // (void)applyPatternsAndFoldGreedily(funcOp, std::move(patterns));
    // if (failed(applyPatternsAndFoldGreedily(funcOp, std::move(patterns)))) {
    //    signalPassFailure();
    // }
    
    // This could be run before or after the existing loop fusion logic,
    // or the existing logic could also be migrated to use OpRewritePatterns.
  }
};

} // end anonymous namespace

// Factory function for the pass
std::unique_ptr<Pass> codo::createEliminateViolationPass() {
  return std::make_unique<EliminateViolation>();
}