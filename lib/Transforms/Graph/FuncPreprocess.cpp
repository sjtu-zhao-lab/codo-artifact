//===----------------------------------------------------------------------===//
//
// Copyright 2020-2021 The codo Authors.
//
//===----------------------------------------------------------------------===//

#include "mlir/Dialect/Affine/Analysis/AffineAnalysis.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "codo/Transforms/Passes.h"
#include "codo/Support/Utils.h"

using namespace mlir;
using namespace codo;

bool codo::applyFuncPreprocess(func::FuncOp func, bool isTopFunc) {
  // auto builder = OpBuilder(func);
  auto context = func.getContext();

  // We constrain functions to only contain one block.
  if (!llvm::hasSingleElement(func))
    func.emitError("has more than one basic blocks.");

  // Set top function attribute.
  if (isTopFunc)
    setTopFuncAttr(func);

  
  // Set parallel attribute to each loop that is applicable. Meanwhile, strip
  // all loop directives.
  func.walk([&](affine::AffineForOp loop) {
    // loop->removeAttr("loop_directive");
    if (isLoopParallel(loop))
      setParallelAttr(loop);
  });

  return true;
}

namespace {
struct FuncPreprocess : public FuncPreprocessBase<FuncPreprocess> {
  FuncPreprocess() = default;
  FuncPreprocess(std::string hlsTopFunc) { topFunc = hlsTopFunc; }

  void runOnOperation() override {
    // FIXME: If the input does not contain a "top function", all the 
    // functions will be named as hlsTopFunc.
    auto func = getOperation();
    auto isTop = func.getName() == topFunc;
    applyFuncPreprocess(func, isTop);
  }
};
} // namespace

std::unique_ptr<Pass>
codo::createFuncPreprocessPass(std::string hlsTopFunc) {
  return std::make_unique<FuncPreprocess>(hlsTopFunc);
}
