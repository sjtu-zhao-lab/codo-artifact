#include "mlir/Dialect/Affine/Analysis/AffineAnalysis.h"
#include "mlir/Dialect/Affine/Analysis/Utils.h"
#include "mlir/Dialect/Affine/LoopUtils.h"
#include "codo/Transforms/Passes.h"
#include "codo/Support/Utils.h"
#include "llvm/Support/Debug.h"
#include "codo/Init_All_Dialects.h"


#define DEBUG_TYPE "codo"

using namespace mlir;
using namespace mlir::affine;
using namespace codo;


bool codo::applyAffineLoopOrderOpt(AffineLoopBand &band,
                                       ArrayRef<unsigned> permMap,
                                       bool reverse) {
  LLVM_DEBUG(llvm::dbgs() << "Loop order opt ";);
  assert(!band.empty() && "no loops provided");
  if (!isPerfectlyNested(band))
    return false;

  auto &loopBlock = *band.back().getBody();
  auto bandDepth = band.size();

  if (!permMap.empty() && isValidLoopInterchangePermutation(band, permMap)) {
    llvm::outs() << "Loop order opt 2";
    auto newRoot = band[permuteLoops(band, permMap)];
    band.clear();
    getLoopBandFromOutermost(newRoot, band);
    band.resize(bandDepth);
    return true;
  }

  // Collect all loops with dependencies. These are candidates for reordering.
  SmallVector<affine::AffineForOp, 6> targetLoops;
  for (auto loop : band)
    if (!isLoopParallel(loop))
      targetLoops.push_back(loop);

  // If there are no loops with dependencies, there's nothing to reorder.
  if (targetLoops.empty()) {
    LLVM_DEBUG(llvm::dbgs() << "no dependent loops to reorder.\n";);
    return true; // No change, but optimization is considered successful.
  }

  // --- MODIFICATION START ---
  // The original code tried to move loops as far as possible.
  // The new logic attempts to move a dependent loop by only one level,
  // either outwards or inwards, if the transformation is valid.

  // Iterate through each loop that has dependencies.
  for (auto loop : targetLoops) {
    // Find the current location (depth) of the target loop in the band.
    auto it = std::find(band.begin(), band.end(), loop);
    // If the loop is somehow not in the band (should not happen), skip.
    if (it == band.end())
      continue;
    unsigned targetLoopLoc = std::distance(band.begin(), it);

    unsigned dstLoc; // The destination location for the swap.
    
    if (!reverse) {
      // --- Move Outwards by One Level ---
      // If the loop is already the outermost, we can't move it further out.
      if (targetLoopLoc == 0)
        continue;
      
      // The destination is the next outer loop.
      dstLoc = targetLoopLoc - 1;
    } else {
      // --- Move Inwards by One Level ---
      // If the loop is already the innermost, we can't move it further in.
      if (targetLoopLoc >= bandDepth - 1)
        continue;
        
      // The destination is the next inner loop.
      dstLoc = targetLoopLoc + 1;
    }

    // --- Simplified Permutation Map Construction for Swapping ---
    // Create an identity permutation map {0, 1, 2, ...}
    SmallVector<unsigned, 4> currentPermMap;
    currentPermMap.reserve(bandDepth);
    for (unsigned i = 0; i < bandDepth; ++i)
      currentPermMap.push_back(i);
    
    // Swap the elements at the target and destination locations to create
    // the permutation for an adjacent loop interchange.
    std::swap(currentPermMap[targetLoopLoc], currentPermMap[dstLoc]);

    // Check if this single-level interchange is valid.
    if (isValidLoopInterchangePermutation(band, currentPermMap)) {
      LLVM_DEBUG(llvm::dbgs() << "(swapping " << targetLoopLoc << " and " << dstLoc << ": ";);
      LLVM_DEBUG(for (unsigned i = 0, e = currentPermMap.size(); i < e; ++i) {
        llvm::dbgs() << currentPermMap[i];
        if (i != e - 1)
          llvm::dbgs() << ",";
      });
      LLVM_DEBUG(llvm::dbgs() << ") ";);

      // Apply the valid permutation.
      auto newRoot = band[permuteLoops(band, currentPermMap)];
      band.clear();
      getLoopBandFromOutermost(newRoot, band);
      band.resize(bandDepth);

      // After a successful interchange, the locations of other target loops
      // have changed. We break and will restart the process if needed in a
      // subsequent pass. A more advanced strategy could continue, but this
      // is safer and simpler.
      break; 
    }
  }
  // --- MODIFICATION END ---

  LLVM_DEBUG(llvm::dbgs() << "\n";);
  return true;
}

namespace {
struct AffineLoopOrderOpt : public AffineLoopOrderOptBase<AffineLoopOrderOpt> {
  void runOnOperation() override {
    // Collect all target loop bands.
    AffineLoopBands targetBands;
    getLoopBands(getOperation().front(), targetBands);
    auto func = getOperation();
    SmallVector<Operation*, 4> loopsToDelete;

    func.walk([&](AffineForOp forOp) {
      // Check if the forOp is a top-level loop
      if (isa<func::FuncOp>(forOp->getParentOp())||isa<codo::TaskOp>(forOp->getParentOp())) {
        // Check if the next operation is also an affine for loop
        auto nextOp = forOp.getOperation()->getNextNode();
        if (!nextOp || !isa<AffineForOp>(nextOp))
          return;

        auto nextForOp = cast<AffineForOp>(nextOp);
        AffineLoopBand band1, band2;
        getLoopBandFromOutermost(forOp, band1);
        getLoopBandFromOutermost(nextForOp, band2);

        if(areLoopsWithSameLoopBounds(forOp, nextForOp, band1, band2) && !nextForOp->hasAttrOfType<UnitAttr>("store_loop")){
            // forOp.dump();
            // nextForOp.dump();
            // llvm::outs()<<"fused function name: "<<forOp->getParentOp()->getName()<<"\n";
            fuseLoopsWithSameBounds(band1, band2);
            loopsToDelete.push_back(forOp);
            loopsToDelete.push_back(nextForOp);
        }
        // Check if two loops have the same loop bounds
      }
    });
    // Now, safely delete the loops
    for (auto *loop : loopsToDelete) {
        loop->erase();
    }

    // if(forOp->hasAttrOfType<UnitAttr>("conv_loop"))




    // Apply loop order optimization to each loop band.
    // for (auto &band : targetBands) {
    //   AffineLoopBand tileBand;
    //   AffineLoopBand pointBand;

    //   // If the current loop band can be split into a tile band and point band,
    //   // apply to these two partial bands separately. Otherwise, apply to the
    //   // whole loop band.
    //   if (getTileAndPointLoopBand(band, tileBand, pointBand)) {
    //     if (!tileBand.empty())
    //       applyAffineLoopOrderOpt(tileBand);
    //     if (!pointBand.empty())
    //       applyAffineLoopOrderOpt(pointBand);
    //   } else
    //     applyAffineLoopOrderOpt(band);
    // }
  }
};
} // namespace

std::unique_ptr<Pass> codo::createAffineLoopOrderOptPass() {
  return std::make_unique<AffineLoopOrderOpt>();
}
