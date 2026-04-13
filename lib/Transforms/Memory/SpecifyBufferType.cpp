//===----------------------------------------------------------------------===//
//
// Copyright 2020-2021 The codo Authors.
//
//===----------------------------------------------------------------------===//

#include "mlir/Transforms/DialectConversion.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "codo/Transforms/Passes.h"
#include "codo/Support/Utils.h"

using namespace mlir;
using namespace codo;

namespace {
struct SpecifyBuffer : public OpRewritePattern<func::FuncOp> {
  SpecifyBuffer(MLIRContext *context, unsigned threshold, 
              bool placeExternalBuffer)
      : OpRewritePattern<func::FuncOp>(context), threshold(threshold),
        placeExternalBuffer(placeExternalBuffer) {}

  // TODO: we need a strategy to decide the storage type of each variable.
  MemRefType getPlacedType(MemRefType type, bool isConstBuffer) const {
    auto kind = MemoryKind::BRAM_T2P;
    if (placeExternalBuffer)
      kind = MemoryKind::BRAM_T2P;
      // kind = type.getNumElements() >= threshold ? MemoryKind::DRAM
      //                                           : MemoryKind::BRAM_T2P;
    auto newType = MemRefType::get(
        type.getShape(), type.getElementType(), type.getLayout().getAffineMap(),
        MemoryKindAttr::get(type.getContext(), kind));
    return newType;
  }

  MemRefType getPlacedOnDramType(MemRefType type) const {
    auto newType = MemRefType::get(
        type.getShape(), type.getElementType(), type.getLayout().getAffineMap(),
        MemoryKindAttr::get(type.getContext(), MemoryKind::DRAM));
    return newType;
  }

  LogicalResult matchAndRewrite(func::FuncOp func,
                                PatternRewriter &rewriter) const override {
    for (auto arg : func.getArguments())
      if (auto type = arg.getType().dyn_cast<MemRefType>())
        arg.setType(getPlacedType(type, false));

    func.walk([&](codo::BufferLikeInterface buffer) {
      buffer.getMemref().setType(getPlacedType(
          buffer.getMemrefType(), isa<ConstBufferOp>(buffer.getOperation())));
    });

    func.walk([](YieldOp yield) {
      for (auto t : llvm::zip(yield->getParentOp()->getResults(),
                              yield.getOperandTypes()))
        std::get<0>(t).setType(std::get<1>(t));
    });

    func.setType(rewriter.getFunctionType(
        func.front().getArgumentTypes(),
        func.front().getTerminator()->getOperandTypes()));
    return success();
  }

private:
  unsigned threshold;
  bool placeExternalBuffer;
};
} // namespace

namespace {
/// FIXME: This is super hacky for hoisting all buffers placed in dram to the
/// top level dispatch.
struct HoistDramBuffer
    : public OpInterfaceRewritePattern<codo::BufferLikeInterface> {
  using OpInterfaceRewritePattern<
      codo::BufferLikeInterface>::OpInterfaceRewritePattern;

  LogicalResult matchAndRewrite(codo::BufferLikeInterface buffer,
                                PatternRewriter &rewriter) const override {
    if (!isExtBuffer(buffer.getMemref()))
      return failure();
    // Alwasy move external buffer out of task.
    if (auto task = buffer->getParentOfType<TaskOp>()) {
      buffer->moveBefore(task);
      return success();
    }
    return failure();
  }
};
} // namespace

namespace {
struct SpecifyBufferType
    : public SpecifyBufferTypeBase<SpecifyBufferType> {
  SpecifyBufferType() = default;
  explicit SpecifyBufferType(unsigned argThreshold,
                               bool argPlaceExternalBuffer) {
    threshold = argThreshold;
    placeExternalBuffer = argPlaceExternalBuffer;
  }

  void runOnOperation() override {
    auto func = getOperation();
    auto context = func.getContext();

    mlir::RewritePatternSet patterns(context);
    patterns.add<SpecifyBuffer>(context, threshold, placeExternalBuffer);
    (void)applyOpPatternsAndFold({func}, std::move(patterns));

    patterns.clear();
    patterns.add<HoistDramBuffer>(context);
    (void)applyPatternsAndFoldGreedily(func, std::move(patterns));
  }
};
} // namespace

std::unique_ptr<Pass>
codo::createSpecifyBufferTypePass(unsigned threshold,
                                        bool placeExternalBuffer) {
  return std::make_unique<SpecifyBufferType>(threshold, placeExternalBuffer);
}
