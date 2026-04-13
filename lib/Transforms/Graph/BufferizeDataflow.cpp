#include "mlir/IR/Dominance.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "codo/Transforms/Passes.h"
#include "codo/Support/Utils.h"
#include "codo/Dialect/CodoOps.h"
// Add headers
#include "mlir/Dialect/Tensor/IR/Tensor.h"
#include "mlir/Dialect/Bufferization/IR/Bufferization.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"

using namespace mlir;
using namespace codo;


// tensor->memref
namespace {
template <typename OpType>
struct BufferizeDispatchOrTask : public OpRewritePattern<OpType> {
  using OpRewritePattern<OpType>::OpRewritePattern;

  LogicalResult matchAndRewrite(OpType op,
                                PatternRewriter &rewriter) const override {
    bool hasChanged = false;

    for (auto result : op->getResults()) {
      if (auto tensorType = result.getType().template dyn_cast<TensorType>()) {
        auto memrefType =
            MemRefType::get(tensorType.getShape(), tensorType.getElementType());
        result.setType(memrefType);

        auto loc = rewriter.getUnknownLoc();
        rewriter.setInsertionPointAfter(op);
        auto tensor = rewriter.template create<bufferization::ToTensorOp>(
            loc, tensorType, result);
        result.replaceAllUsesExcept(tensor, tensor);

        rewriter.setInsertionPoint(op.getYieldOp());
        auto output = op.getYieldOp().getOperand(result.getResultNumber());
        auto memref = rewriter.template create<bufferization::ToMemrefOp>(
            loc, memrefType, output);
        op.getYieldOp()->getOpOperand(result.getResultNumber()).set(memref);
        hasChanged = true;
      }
    }
    return success(hasChanged);
  }
};
} // namespace

namespace {
struct BufferizeTensorEmpty : public OpRewritePattern<tensor::EmptyOp> {
  using OpRewritePattern<tensor::EmptyOp>::OpRewritePattern;

  LogicalResult matchAndRewrite(tensor::EmptyOp op,
                                PatternRewriter &rewriter) const override {
    auto tensorType = op.getType();
    auto memrefType =
        MemRefType::get(tensorType.getShape(), tensorType.getElementType());
    rewriter.setInsertionPoint(op);
    auto buffer = rewriter.create<BufferOp>(op.getLoc(), memrefType);
    rewriter.replaceOpWithNewOp<bufferization::ToTensorOp>(op, tensorType,
                                                           buffer);
    return success();
  }
};
} // namespace

namespace {
template <typename OpType>
struct HoistBuffer : public OpRewritePattern<OpType> {
  using OpRewritePattern<OpType>::OpRewritePattern;

  LogicalResult matchAndRewrite(OpType op,
                                PatternRewriter &rewriter) const override {
    for (auto &result : op.getYieldOp()->getOpOperands())
    { 
      // result.dump();
      if (auto buffer = result.get().template getDefiningOp<BufferLikeInterface>())
      {   

          if (op == buffer->getParentOp() && op.getBody().front().getOperations().size()>2) {
            buffer->moveBefore(op);
            op.getResult(result.getOperandNumber())
                .replaceAllUsesWith(buffer.getMemref());
            // rewriter.eraseOp(op.getYieldOp());
            // llvm::outs() << op.getBody().front().getOperations().size();
            // llvm::outs() << '\n';
            
            // llvm::SetVector<Value> outputValues;

            // auto loc = rewriter.getUnknownLoc();
            // rewriter.setInsertionPoint(op);
            
            // auto task =
            //     rewriter.create<TaskOp>(loc, ValueRange(outputValues.getArrayRef()));
            // auto taskBlock = rewriter.createBlock(&task.getBody());
            // rewriter.setInsertionPointToEnd(taskBlock);
            // auto yield = rewriter.create<YieldOp>(loc, outputValues.getArrayRef());
            // op.replaceAllUsesWith(task);
            // task.dump();
            // buffer.dump();
            return success();
            
          } 
      }

  

        // for (Value value : outputValues) {
        //     value.print(llvm::outs());
        //     llvm::outs() << '\n';
        //     llvm::outs() << outputValues.size();
        // }
        // llvm::outs() << "finish output";
        // llvm::outs() << '\n';
    } 
    

    // Move each targeted op into the new graph task.
    // rewriter.setInsertionPointToEnd(taskBlock);
    // auto yield = rewriter.create<YieldOp>(loc, outputValues.getArrayRef());
    // for (auto op : ops)
    // op->moveBefore(yield);
    // if (result.get().use_empty()) {
    //       result.dump();
    //       if (isa<DispatchOp>(op) || isa<TaskOp>(op)) {  // 如果 Op 的类型是 DispatchOp 或者 TaskOp
    //           rewriter.eraseOp(op);  // 删除 Op
    //           return success();
    //       } 
    // }  
    return failure();
  }
};
} // namespace

namespace {
// If an alloc is filled before any other uses, the alloc can be converted to a
// buffer with initial value.
template <typename OpType>
struct ConvertAllocToBufferWithInitValue : public OpRewritePattern<OpType> {
  using OpRewritePattern<OpType>::OpRewritePattern;

  LogicalResult matchAndRewrite(OpType op,
                                PatternRewriter &rewriter) const override {
    DominanceInfo DT;
    SmallVector<Operation *> users(op->user_begin(), op->user_end());
    llvm::sort(users, [&](auto a, auto b) { return DT.dominates(a, b); });

    if (auto fill = dyn_cast<linalg::FillOp>(users.front()))
      if (auto constant = fill.value().getDefiningOp<arith::ConstantOp>()) {
        rewriter.replaceOpWithNewOp<BufferOp>(op, op.getType(),
                                              /*depth=*/1, constant.getValue());
        rewriter.eraseOp(fill);
        return success();
      }
    return failure();
  }
};
} // namespace

namespace {
template <typename OpType>
struct ConvertAllocToBuffer : public OpRewritePattern<OpType> {
  using OpRewritePattern<OpType>::OpRewritePattern;

  LogicalResult matchAndRewrite(OpType op,
                                PatternRewriter &rewriter) const override {
    rewriter.replaceOpWithNewOp<BufferOp>(op, op.getType());
    return success();
  }
};
} // namespace

namespace {
struct ConvertGetGlobalToConstBuffer
    : public OpRewritePattern<memref::GetGlobalOp> {
  using OpRewritePattern<memref::GetGlobalOp>::OpRewritePattern;

  LogicalResult matchAndRewrite(memref::GetGlobalOp op,
                                PatternRewriter &rewriter) const override {
    auto global = SymbolTable::lookupNearestSymbolFrom<memref::GlobalOp>(
        op, op.getNameAttr());
    rewriter.replaceOpWithNewOp<ConstBufferOp>(op, global.getType(),
                                               global.getConstantInitValue());
    return success();
  }
};
} // namespace
void codo::populateBufferConversionPatterns(RewritePatternSet &patterns) {
  auto context = patterns.getContext();
  patterns.add<ConvertAllocToBufferWithInitValue<memref::AllocOp>>(context);
  patterns.add<ConvertAllocToBufferWithInitValue<memref::AllocaOp>>(context);
  patterns.add<ConvertAllocToBuffer<memref::AllocOp>>(context);
  patterns.add<ConvertAllocToBuffer<memref::AllocaOp>>(context);
  patterns.add<ConvertGetGlobalToConstBuffer>(context);
}

namespace {
struct BufferizeDataflow : public BufferizeDataflowBase<BufferizeDataflow> {
  void runOnOperation() override {
    auto func = getOperation();
    auto context = func.getContext();
    

    mlir::RewritePatternSet patterns(context);
    
    populateBufferConversionPatterns(patterns);
    patterns.add<BufferizeDispatchOrTask<DispatchOp>>(context);
    patterns.add<BufferizeDispatchOrTask<TaskOp>>(context);
    patterns.add<HoistBuffer<DispatchOp>>(context);
    patterns.add<HoistBuffer<TaskOp>>(context);
    patterns.add<BufferizeTensorEmpty>(context);
    (void)applyPatternsAndFoldGreedily(func, std::move(patterns));

    
    // updateFunctionWithConstants(func);
    
  }
};
} // namespace

std::unique_ptr<Pass> codo::createBufferizeDataflowPass() {
  return std::make_unique<BufferizeDataflow>();
}
