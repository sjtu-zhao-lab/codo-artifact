#include "mlir/IR/Dominance.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"

#include "codo/Transforms/Passes.h"
#include "codo/Support/Utils.h"
#include "codo/Dialect/CodoOps.h"

using namespace mlir;
using namespace codo;

namespace {
struct LowerCopy : public OpRewritePattern<memref::CopyOp> {
  LowerCopy(MLIRContext *context, bool internalCopyOnly = true)
      : OpRewritePattern(context), internalCopyOnly(internalCopyOnly) {}

  using OpRewritePattern<memref::CopyOp>::OpRewritePattern;

  LogicalResult matchAndRewrite(memref::CopyOp copy,
                                PatternRewriter &rewriter) const override {
    // Check whether the copy op communicates with inputs or outputs.
    auto isExternalCopy =
        isExtBuffer(copy.getSource()) || isExtBuffer(copy.getTarget());

    // Return failure if we don't need to lower external copies.
    if (internalCopyOnly && isExternalCopy)
      return failure();

    rewriter.setInsertionPoint(copy);
    auto loc = copy.getLoc();
    auto memrefType = copy.getSource().getType().cast<MemRefType>();

    // Create explicit memory copy using an affine loop nest.
    SmallVector<Value, 4> ivs;
    auto constantZero = rewriter.create<arith::ConstantIndexOp>(loc, 0);
    for (auto dimSize : memrefType.getShape()) {
      // Comment out 
      // if (dimSize == 1) {
      //   ivs.push_back(constantZero);
      //   continue;
      // }
      auto loop = rewriter.create<mlir::affine::AffineForOp>(loc, 0, dimSize);
      setParallelAttr(loop);
      // If the copy op is not external, we consider the loop as point loop
      // that needs to be optimized later.
      if (!isExternalCopy)
        setPointAttr(loop);
      rewriter.setInsertionPointToStart(loop.getBody());
      ivs.push_back(loop.getInductionVar());
    }

    // Create affine load/store operations.
    auto value =
        rewriter.create<mlir::affine::AffineLoadOp>(loc, copy.getSource(), ivs);
    rewriter.create<mlir::affine::AffineStoreOp>(loc, value, copy.getTarget(), ivs);     
    rewriter.eraseOp(copy);
    return success();
  }

private:
  bool internalCopyOnly = true;
};
} // namespace


namespace {
struct LowerCopyToAffine : public LowerCopyToAffineBase<LowerCopyToAffine> {
  LowerCopyToAffine() = default;
  LowerCopyToAffine(bool argInternalCopyOnly) {
    internalCopyOnly = argInternalCopyOnly;
  }

  void runOnOperation() override {
    auto module = getOperation();
    auto context = module.getContext();
    // auto DT = DominanceInfo(module);
    

    // Lower copy operation.
    mlir::RewritePatternSet patterns(context);
    patterns.add<LowerCopy>(context, internalCopyOnly);
    // patterns.add<ReplaceSymbolInAffineStore>(context);
    (void)applyPatternsAndFoldGreedily(module, std::move(patterns));


  }
};
} // namespace

std::unique_ptr<Pass>
codo::createLowerCopyToAffinePass(bool internalCopyOnly) {
  return std::make_unique<LowerCopyToAffine>(internalCopyOnly);
}
