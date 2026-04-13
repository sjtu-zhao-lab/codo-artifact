/*
 * Original code by StreamHLS Team, 2024)
 * Copyright (c) 2024 Suhail Basalama
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "codo/Transforms/Passes.h"

#include "codo/Support/Utils.h"
// #include "codo/Support/AffineMemAccess.h"

#include "mlir/IR/IntegerSet.h"
using namespace mlir;
using namespace codo;
// using namespace dataflow;

#define DEBUG_TYPE "codo-create-weight-bins"

namespace {
  struct ConvertWeightsToBins : public OpRewritePattern<arith::ConstantOp> {
    ConvertWeightsToBins(MLIRContext *context, bool keepWeights = true) 
      : OpRewritePattern(context), keepWeights(keepWeights) {}

    using OpRewritePattern<arith::ConstantOp>::OpRewritePattern;

    LogicalResult matchAndRewrite(
      arith::ConstantOp op,
      PatternRewriter &rewriter
    ) const override {
      LLVM_DEBUG(llvm::dbgs() << "ConvertWeightsToBins\n");
      LLVM_DEBUG(
        llvm::dbgs() << "Running on constant op: ";
        op.print(llvm::dbgs());
        llvm::dbgs() << "\n";
      );
      auto tensor = op.getValueAttr().dyn_cast_or_null<DenseElementsAttr>();
      
      if(!tensor) return failure();
      if(tensor.isSplat()) {
        return failure();
      }
      auto func = op->getParentOfType<func::FuncOp>();
      auto loc = rewriter.getUnknownLoc();
      auto argNum = func.getNumArguments();
      if(keepWeights){
        StringRef nameForBlob = "weight";
        ShapedType type = tensor.getType().cast<ShapedType>();
        // cast tensor to memref
        auto memrefType = MemRefType::get(type.getShape(), type.getElementType());
        // auto attr = DenseElementsAttr::getFromRawBuffer(memrefType, tensor.getRawData());
        auto attr = DenseResourceElementsAttr::get(memrefType, nameForBlob, UnmanagedAsmResourceBlob::allocateInferAlign(tensor.getRawData()));
        op.setValueAttr(attr);
        func.insertArgument(argNum, op.getType(), {}, loc);
        func.setArgAttr(argNum, "builtin.dense_resource", attr);
      } else {
        func.insertArgument(argNum, op.getType(), {}, loc);
      }
      rewriter.replaceAllUsesWith(op, func.getArgument(argNum));
      return success();
    }
    private:
      bool keepWeights;
  };
}

// This pass takes creates the weight bins for the host function
namespace {
struct CreateWeightBins : public CreateWeightBinsBase<CreateWeightBins> {
  CreateWeightBins() = default;
  CreateWeightBins(bool argKeepWeights, std::string argTopFuncName) {
    keepWeights = argKeepWeights;
    topFuncName = argTopFuncName;
  }
  void runOnOperation() override {
    auto module = getOperation();
    auto context = module.getContext();
    auto func = module.lookupSymbol<func::FuncOp>(topFuncName);
    mlir::RewritePatternSet patterns(context);
    patterns.add<ConvertWeightsToBins>(context, keepWeights);
    (void)applyPatternsAndFoldGreedily(func, std::move(patterns));
  }
};
} // end anonymous namespace

std::unique_ptr<Pass> codo::createCreateWeightBinsPass(bool keepWeights, std::string topFuncName) {
  return std::make_unique<CreateWeightBins>(
    keepWeights,
    topFuncName
  );
}