#include "mlir/IR/Dominance.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"

#include "codo/Transforms/Passes.h"
#include "codo/Support/Utils.h"
#include "codo/Dialect/CodoOps.h"
#include "codo/Init_All_Dialects.h"


using namespace mlir;
using namespace mlir::affine;
using namespace codo;


namespace {
struct Quantization : public QuantizationBase<Quantization> {
  Quantization() = default;

  void runOnOperation() override {
    auto func = getOperation();
    SmallVector<Operation*, 4> loopsToDelete;
     func.walk([&](AffineForOp forOp) {
      if (isa<func::FuncOp>(forOp->getParentOp())||isa<codo::TaskOp>(forOp->getParentOp())) {
        AffineLoopBand band;
        getLoopBandFromOutermost(forOp, band);
        if (hasReduntantAttr(forOp)) {
            loopsToDelete.push_back(forOp);
        }
    }
    });

    // Now, safely delete the loops
    for (auto *loop : loopsToDelete) {
        loop->erase();
    }

  }

};
} // namespace

// Registration of the pass in MLIR
std::unique_ptr<Pass> codo::createQuantizationPass() {
  return std::make_unique<Quantization>();
}

