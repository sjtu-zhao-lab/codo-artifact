#include "mlir/Support/LogicalResult.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/DenseMap.h"
#include "llvm/Support/raw_ostream.h"
#include "codo/Transforms/Passes.h"
#include "codo/Support/Utils.h"
#include "codo/Init_All_Dialects.h"

#include "mlir/IR/Builders.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Operation.h"

using namespace mlir;
using namespace mlir::affine;
using namespace codo;

namespace {

struct LegalizeDataflow : public LegalizeDataflowBase<LegalizeDataflow> {
  void getDependentDialects(DialectRegistry &registry) const override {
    registry.insert<AffineDialect>();
  }
  // TODO: Currently we support two kinds of loop fusion methods:
  // 1. Fuse loops with the same loop bound (without dependence) (Moved to AffineLoopOrderOpt)
  // 2. Fuse loops that writes to the same array
  void runOnOperation() override {
    auto func = getOperation();

    // llvm::outs()<<"function name: "<<func.getName()<<"\n";
    SmallVector<Operation*, 4> loopsToDelete;
    func.walk([&](AffineForOp forOp) {
      // Check if the forOp is a top-level loop
      // forOp.dump();
      if (isa<func::FuncOp>(forOp->getParentOp())||isa<codo::TaskOp>(forOp->getParentOp())) {
        // This is a top-level AffineForOp
         
        // Check if the next operation is also an affine for loop
        auto nextOp = forOp.getOperation()->getNextNode();
        if (!nextOp || !isa<AffineForOp>(nextOp))
          return;

        auto nextForOp = cast<AffineForOp>(nextOp);
        AffineLoopBand band1, band2;
        getLoopBandFromOutermost(forOp, band1);
        getLoopBandFromOutermost(nextForOp, band2);

        // Check if two loops write to the same memory
        if (areLoopsWritingToSameArray(forOp, nextForOp)) {
          if (band1.size() == band2.size()) {
            auto funcName = forOp.getOperation()->getParentOfType<func::FuncOp>().getName();
            // llvm::outs()<<"test: "<<funcName<<"\n";
            fuseLoopsWritingToSameArray(band1, band2);
            loopsToDelete.push_back(forOp);
            loopsToDelete.push_back(nextForOp);
          }
        }
      }
    });
    func.walk([&](AffineStoreOp storeOp) {
      // llvm::outs()<<"test"<<"\n";
      replaceSymbolsWithInductionVars(storeOp);
    });

    // Now, safely delete the loops
    for (auto *loop : loopsToDelete) {
        loop->erase();
    }
    llvm::SmallDenseMap<AffineForOp, func::FuncOp> conflictMap;
    detectReadWriteConflicts(func, conflictMap);
    // func.dump();


  }

};

} // end anonymous namespace

std::unique_ptr<Pass> codo::createLegalizeDataflowPass() {
  return std::make_unique<LegalizeDataflow>();
}