// this file is adapted from the MLIR BufferResultsToOutParams.cpp file, aiming to implement the data transfer between DRAM and SRAM

#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/Value.h"
#include "mlir/Support/LogicalResult.h"
#include "mlir/Transforms/DialectConversion.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "mlir/Dialect/Bufferization/Transforms/Passes.h"
#include "codo/Dialect/CodoOps.h"
#include "codo/Transforms/Passes.h"
#include "codo/Support/Utils.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/Support/raw_ostream.h"


using namespace mlir;
using namespace codo;

static LogicalResult createInputBuffer(func::FuncOp func, PatternRewriter &rewriter) {

  mlir::ElementsAttr value;
  auto functionType = func.getFunctionType();
  SmallVector<Type, 4> argTypes = llvm::to_vector<4>(functionType.getInputs());
  SmallVector<Type, 4> newTypes;

  Block &entryBlock = func.front();

  int argIndex = 0;
  for (auto argType : argTypes) {
    auto memrefType = dyn_cast<MemRefType>(argType);
    auto newType = MemRefType::get(
        memrefType.getShape(), memrefType.getElementType(),memrefType.getLayout().getAffineMap(),
        MemoryKindAttr::get(memrefType.getContext(), MemoryKind::DRAM));
    rewriter.setInsertionPointToStart(&entryBlock);
    auto newInputBuffer = rewriter.create<BufferOp>(rewriter.getUnknownLoc(), func.getFunctionType().getInput(0).cast<MemRefType>());
    newInputBuffer.setStringAttr(StringRef("non_fifo"));

    func.walk([&](Operation *op) {
      for (unsigned i = 0, e = op->getNumOperands(); i < e; ++i) {
        if (op->getOperand(i) == entryBlock.getArgument(argIndex)) {
          op->setOperand(i, newInputBuffer.getResult());
        }
      }
    });

    newTypes.push_back(newType);
    entryBlock.getArgument(argIndex).setType(newType);

    rewriter.setInsertionPoint(func);
    FunctionType funcType = rewriter.getFunctionType({newType, newInputBuffer.getType()}, {});
    auto subFunc = rewriter.create<func::FuncOp>(
      rewriter.getUnknownLoc(), "input_arg_to_bram" + std::to_string(argIndex),
      funcType);
    auto entry = subFunc.addEntryBlock();
    auto srcArg = entry->getArgument(0);
    auto dstArg = entry->getArgument(1);
    rewriter.setInsertionPointToEnd(entry);

    auto srcMemType = dstArg.getType().cast<MemRefType>();
    SmallVector<Value, 4> ivs;
    int counter = 0;
    for (auto dimSize : srcMemType.getShape()) {
      auto loop = rewriter.create<mlir::affine::AffineForOp>(rewriter.getUnknownLoc(), 0, dimSize);
      if(counter==0){
          // loop.getOperation()->setAttr("io_loop", UnitAttr::get(loop->getContext()));
      }
      counter++;
      rewriter.setInsertionPointToStart(loop.getBody());
      ivs.push_back(loop.getInductionVar());
    }

    auto value = rewriter.create<mlir::affine::AffineLoadOp>(rewriter.getUnknownLoc(), srcArg, ivs);
    rewriter.create<mlir::affine::AffineStoreOp>(rewriter.getUnknownLoc(), value, dstArg, ivs);
    rewriter.setInsertionPointToEnd(entry);

    rewriter.create<func::ReturnOp>(rewriter.getUnknownLoc());

    rewriter.setInsertionPointAfter(newInputBuffer);

    SmallVector<Value, 6> subFuncArg = {entryBlock.getArgument(argIndex), newInputBuffer.getResult()};
    rewriter.create<func::CallOp>(rewriter.getUnknownLoc(), subFunc, subFuncArg);
    ++argIndex;
  }

  auto newFunctionType = FunctionType::get(func.getContext(), newTypes, functionType.getResults());
  func.setType(newFunctionType);

  return success();
}


// Updates all ReturnOps in the scope of the given func::FuncOp by either
// keeping them as return values or copying the associated buffer contents into
// the given out-params.
static LogicalResult updateReturnOps(func::FuncOp func, PatternRewriter &rewriter) {
  auto functionType = func.getFunctionType();
  SmallVector<Type, 4> resTypes = llvm::to_vector<4>(functionType.getResults());
  SmallVector<Type, 4> argTypes = llvm::to_vector<4>(functionType.getInputs());

  for (auto &resultType : resTypes) {
    auto memrefType = dyn_cast<MemRefType>(resultType);
    unsigned totalSize = 1;
    for (auto dimSize : memrefType.getShape()) {
      totalSize *= dimSize;
    }
    auto newType = MemRefType::get(
      memrefType.getShape(), memrefType.getElementType(), memrefType.getLayout().getAffineMap(),
      MemoryKindAttr::get(memrefType.getContext(), MemoryKind::DRAM));

    resultType = newType;
    argTypes.push_back(newType);
  }

  // Add the new arguments to the entry block
  SmallVector<BlockArgument, 6> appendedReturnToEntryArgs;
  Location loc = func.getLoc();
  for (Type type : resTypes) {
    appendedReturnToEntryArgs.push_back(func.front().addArgument(type, loc));
  }

  // update the return ops
  int returnIdx=0;
  auto res = func.walk([&](func::ReturnOp op) {
    SmallVector<Value, 6> copyIntoOutParams = llvm::to_vector<6>(op.getOperands());
    rewriter.setInsertionPoint(func);
    auto loc = op.getLoc();
    for (auto t : llvm::zip(copyIntoOutParams, appendedReturnToEntryArgs)) {
      FunctionType funcType = rewriter.getFunctionType({std::get<0>(t).getType(), std::get<1>(t).getType()}, {});
      auto subFunc = rewriter.create<func::FuncOp>(
        op.getLoc(), "return_to_args" + std::to_string(returnIdx++),
        funcType);
      auto entry = subFunc.addEntryBlock();
      auto srcArg = entry->getArgument(0);
      auto dstArg = entry->getArgument(1);
      rewriter.setInsertionPointToEnd(entry);

      // affine loop to copy the buffer content
      auto srcMemType = std::get<0>(t).getType().cast<MemRefType>();
      SmallVector<Value, 4> ivs;
      int counter = 0;
      for (auto dimSize : srcMemType.getShape()) {
        auto loop = rewriter.create<mlir::affine::AffineForOp>(rewriter.getUnknownLoc(), 0, dimSize);
        if(counter==0){
          // loop.getOperation()->setAttr("io_loop", UnitAttr::get(loop->getContext()));
        }
        counter++;
        // setParallelAttr(loop);
        // setPointAttr(loop);
        rewriter.setInsertionPointToStart(loop.getBody());
        ivs.push_back(loop.getInductionVar());
      }
    
      auto value = rewriter.create<mlir::affine::AffineLoadOp>(rewriter.getUnknownLoc(), srcArg, ivs);
      rewriter.create<mlir::affine::AffineStoreOp>(rewriter.getUnknownLoc(), value, dstArg, ivs);
      rewriter.setInsertionPointToEnd(entry);

      rewriter.create<func::ReturnOp>(rewriter.getUnknownLoc());

      rewriter.setInsertionPoint(op);
      SmallVector<Value, 6> subFuncArg = {std::get<0>(t), std::get<1>(t)};
      rewriter.create<func::CallOp>(loc, subFunc, subFuncArg);
    }
    op->eraseOperands(0, op->getNumOperands());
    return WalkResult::advance();
  });

  // Update the function type.
  resTypes.clear();
  auto newFunctionType = FunctionType::get(func.getContext(), argTypes, resTypes);
  func.setType(newFunctionType);

  // Transfer the result attributes to arg attributes.
  for (int i = 0, e = resTypes.size(); i < e; ++i) {
    func.setArgAttrs(functionType.getNumInputs() + i,
                     func.getResultAttrs(i));
  }

  return failure(res.wasInterrupted());
}

// erase the constant ops and map the constant buffer to the entry block
static LogicalResult updateConstantOps(func::FuncOp func, PatternRewriter &rewriter) {
  IRMapping mapper;
  FunctionType funcType = func.getFunctionType();

  std::vector<Type> newArgTypes(funcType.getInputs().begin(), funcType.getInputs().end());
  std::vector<Value> newArgs;

  // collect the information of the constant ops
  func.walk([&](codo::ConstBufferOp op) {
    if (op.getValue()) {
      auto newType = MemRefType::get(
        op.getResult().getType().getShape(), op.getResult().getType().getElementType(), op.getResult().getType().getLayout().getAffineMap(),
        MemoryKindAttr::get(op.getResult().getType().getContext(), MemoryKind::DRAM));
      newArgTypes.push_back(newType);
      newArgs.push_back(op.getResult());
    }
  });

  // Add the new arguments to the function type.
  FunctionType newFuncType = FunctionType::get(func.getContext(), newArgTypes, funcType.getResults());
  func.setType(newFuncType);

  // Add the new arguments to the entry block
  unsigned argIndex = funcType.getNumInputs();
  Block &entryBlock = func.front();
  for (auto constantValue : newArgs) {
    auto type = constantValue.getType().cast<MemRefType>();
    auto newType = MemRefType::get(
        type.getShape(), type.getElementType(),type.getLayout().getAffineMap(),
        MemoryKindAttr::get(type.getContext(), MemoryKind::DRAM));
    entryBlock.insertArgument(argIndex, newType, constantValue.getLoc());
    mapper.map(constantValue, entryBlock.getArgument(argIndex));
    argIndex++;
  }

  // update the constant ops
  unsigned constantIndex = 0;
  func.walk([&](codo::ConstBufferOp op) {
    rewriter.setInsertionPoint(func);
    auto loc = op.getLoc();
    FunctionType funcType = rewriter.getFunctionType({mapper.lookup(op.getResult()).getType(), op.getResult().getType()}, {});
    auto subFunc = rewriter.create<func::FuncOp>(
        op.getLoc(), "constant_to_bram" + std::to_string(constantIndex++),
        funcType);
    auto entry = subFunc.addEntryBlock();
    auto srcArg = entry->getArgument(0);
    auto dstArg = entry->getArgument(1);
    rewriter.setInsertionPointToEnd(entry);
    // affine loop to copy the buffer content
    auto srcMemType = mapper.lookup(op.getResult()).getType().cast<MemRefType>();
    SmallVector<Value, 4> ivs;
    int counter = 0;
    for (auto dimSize : srcMemType.getShape()) {
      auto loop = rewriter.create<mlir::affine::AffineForOp>(rewriter.getUnknownLoc(), 0, dimSize);
      if(counter==0 && srcMemType.getShape().size()>=3){
          // loop.getOperation()->setAttr("io_loop", UnitAttr::get(loop->getContext()));
          // loop.dump();
      }
      counter++;
      // setParallelAttr(loop);
      // setPointAttr(loop);
      rewriter.setInsertionPointToStart(loop.getBody());
      ivs.push_back(loop.getInductionVar());
    }
  
    auto value = rewriter.create<mlir::affine::AffineLoadOp>(rewriter.getUnknownLoc(), srcArg, ivs);
    rewriter.create<mlir::affine::AffineStoreOp>(rewriter.getUnknownLoc(), value, dstArg, ivs);
    rewriter.setInsertionPointToEnd(entry);

    rewriter.create<func::ReturnOp>(rewriter.getUnknownLoc());

    rewriter.setInsertionPointAfter(op);
    // auto newInputBuffer = rewriter.create<BufferOp>(rewriter.getUnknownLoc(), op.getResult().getType());
    // rewriter.replaceOp(op, newInputBuffer);
    SmallVector<Value, 6> subFuncArg = {mapper.lookup(op.getResult()), op.getResult()};
    rewriter.create<func::CallOp>(loc, subFunc, subFuncArg);

    return WalkResult::advance();
  });

  func.walk([&](codo::ConstBufferOp op) {
    rewriter.setInsertionPoint(op);
    auto newInputBuffer = rewriter.create<BufferOp>(op.getLoc(), op.getResult().getType());
    newInputBuffer.setStringAttr(StringRef("non_fifo"));
    func.walk([&](Operation *op1) {
      for (unsigned i = 0, e = op1->getNumOperands(); i < e; ++i) {
        if (op1->getOperand(i) == op.getResult()) {
          op1->setOperand(i, newInputBuffer.getResult());
        }
      }
    });
    rewriter.replaceOp(op, newInputBuffer);
  });

  return success();
}

// match the top function and implement the data transfer between DRAM and SRAM
struct MemoryTransfer : public OpRewritePattern<func::FuncOp> {
  MemoryTransfer(MLIRContext *context) : OpRewritePattern<func::FuncOp>(context) {}

  LogicalResult matchAndRewrite(func::FuncOp func, PatternRewriter &rewriter) const override {
    if (!func->hasAttr("top_func")) {
      return failure();
    }
    int inputArgNum = func.getNumArguments();
    int outputArgNum = func.getNumResults();

    if (func.getFunctionType().getNumResults() == 0){
      return failure();
    }

    if (failed(createInputBuffer(func, rewriter))) {
      return failure();
    }

    if (failed(updateReturnOps(func, rewriter))) {
      return failure();
    }

    if (failed(updateConstantOps(func, rewriter))) {
      return failure();
    }
    int totalInputArgNum = func.getNumArguments();
    for (int i = 0; i < totalInputArgNum; ++i) {
      if (i < inputArgNum) {
        auto ioAttr = rewriter.getStringAttr("h2o");
        func.setArgAttr(i, "codo.io", ioAttr);
      } else if (i < inputArgNum + outputArgNum) {
        auto ioAttr = rewriter.getStringAttr("o2h");
        func.setArgAttr(i, "codo.io", ioAttr);
      } else {
        auto ioAttr = rewriter.getStringAttr("h2o");
        func.setArgAttr(i, "codo.io", ioAttr);
      }
    }
    // func.walk([&](Operation *op) {
    //   // 示例：处理 MemRefType
    //   for (auto result : op->getResults()) {
    //     if (auto memRefType = result.getType().dyn_cast<mlir::MemRefType>()) {
    //       auto newMemRefType = mlir::MemRefType::get(
    //           memRefType.getShape(), rewriter.getIntegerType(8),
    //           memRefType.getLayout().getAffineMap(), memRefType.getMemorySpace());

    //       // 重写操作
    //       result.setType(newMemRefType);
    //     }
    //   }
    // });

    return success();
  }
};

namespace {
struct MemoryTransferBetweenDRAMAndSRAM : public MemoryTransferBetweenDRAMAndSRAMBase<MemoryTransferBetweenDRAMAndSRAM> {

  MemoryTransferBetweenDRAMAndSRAM() = default;
  void runOnOperation() override {
    auto func = getOperation();
    auto context = func.getContext();
    mlir::RewritePatternSet patterns(context);
    patterns.add<MemoryTransfer>(context);
    (void)applyOpPatternsAndFold({func}, std::move(patterns));
  }
};
} // namespace
std::unique_ptr<Pass> codo::createMemoryTransferBetweenDRAMAndSRAMPass() {
  return std::make_unique<MemoryTransferBetweenDRAMAndSRAM>();
}
