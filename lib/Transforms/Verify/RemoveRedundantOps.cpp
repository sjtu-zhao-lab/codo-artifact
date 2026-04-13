/*
 * Original code by StreamHLS Team, 2024)
 * Copyright (c) 2024 Suhail Basalama
 *
 * This software is released under the MIT License.
 * https://opensource.org/licenses/MIT
 */
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "codo/Transforms/Passes.h"

using namespace mlir;
using namespace codo;
// using namespace dataflow;

#define DEBUG_TYPE "codo-remove-redundant-ops"

namespace {
  struct RemoveGlobalSeed : public OpRewritePattern<ml_program::GlobalOp> {
    using OpRewritePattern<ml_program::GlobalOp>::OpRewritePattern;
    LogicalResult matchAndRewrite(
      ml_program::GlobalOp op,
      PatternRewriter &rewriter
    ) const override {
      // TODO: This is a hack to remove the global seed
      // make sure it is not used anywhere
      if(op.use_empty()) {
        rewriter.eraseOp(op);
        return success();
      }else{
        return failure();
      }
    }
  };
} // end anonymous namespace
// This pass takes creates the weight bins for the host function
namespace {
struct RemoveRedundantOps : public RemoveRedundantOpsBase<RemoveRedundantOps> {
  void runOnOperation() override {
    auto module = getOperation();
    auto context = module.getContext();
    // auto func = module.lookupSymbol<func::FuncOp>("forward");
    RewritePatternSet patterns(context);
    patterns.add<RemoveGlobalSeed>(context);
    (void)applyPatternsAndFoldGreedily(module, std::move(patterns));
  }
};
} // end anonymous namespace

std::unique_ptr<Pass> codo::createRemoveRedundantOpsPass() {
  return std::make_unique<RemoveRedundantOps>();
}