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
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/Operation.h"
#include "mlir/IR/PatternMatch.h"
#include "mlir/IR/IRMapping.h"
#include "llvm/ADT/STLExtras.h"

using namespace mlir;
using namespace codo;





using namespace mlir;

static LogicalResult createInputBuffer(func::FuncOp func, PatternRewriter &rewriter) {
    if (func.empty()) return failure();

    Block &entryBlock = func.getBody().front();
    
    bool hasMultiConsumer = false;
    for (BlockArgument arg : entryBlock.getArguments()) {
        if (!arg.use_empty() && !arg.hasOneUse()) {
            hasMultiConsumer = true;
            break;
        }
    }

    if (!hasMultiConsumer) {
        return failure();
    }

    unsigned oldNumArgs = entryBlock.getNumArguments();

    struct ArgUseInfo {
        BlockArgument originalArg;
        SmallVector<OpOperand *, 4> sortedUses;
    };
    SmallVector<ArgUseInfo, 8> argInfos;

    for (BlockArgument arg : entryBlock.getArguments()) {
        ArgUseInfo info;
        info.originalArg = arg;
        
        for (OpOperand &use : arg.getUses()) {
            info.sortedUses.push_back(&use);
        }

        llvm::sort(info.sortedUses, [&](OpOperand *a, OpOperand *b) {
            Operation *opA = entryBlock.findAncestorOpInBlock(*a->getOwner());
            Operation *opB = entryBlock.findAncestorOpInBlock(*b->getOwner());
            if (!opA || !opB) return false;

            if (opA != opB)
                return opA->isBeforeInBlock(opB);
            
            return a->getOperandNumber() < b->getOperandNumber();
        });
        
        argInfos.push_back(info);
    }

    SmallVector<Type, 16> newArgTypes;
    SmallVector<Location, 16> newArgLocs;
    
    for (auto &info : argInfos) {
        size_t numUses = info.sortedUses.size();
        size_t count = (numUses == 0) ? 1 : numUses;
        for (size_t i = 0; i < count; ++i) {
            newArgTypes.push_back(info.originalArg.getType());
            newArgLocs.push_back(info.originalArg.getLoc());
        }
    }

    auto newFuncType = rewriter.getFunctionType(newArgTypes, func.getResultTypes());
    rewriter.modifyOpInPlace(func, [&]() {
        func.setType(newFuncType);
    });

    entryBlock.addArguments(newArgTypes, newArgLocs);

    unsigned currentNewArgIdx = oldNumArgs; 
    for (auto &info : argInfos) {
        if (info.sortedUses.empty()) {
            currentNewArgIdx++; // 跳过占位参数
            continue;
        }
        for (OpOperand *use : info.sortedUses) {
            BlockArgument newArg = entryBlock.getArgument(currentNewArgIdx++);
            rewriter.modifyOpInPlace(use->getOwner(), [&]() {
                use->set(newArg);
            });
        }
    }

    entryBlock.eraseArguments(0, oldNumArgs);

    return success();
}

struct EliminateTopfuncarg : public OpRewritePattern<func::FuncOp> {
  EliminateTopfuncarg(MLIRContext *context) : OpRewritePattern<func::FuncOp>(context) {}

  LogicalResult matchAndRewrite(func::FuncOp func, PatternRewriter &rewriter) const override {
    if (!func->hasAttr("top_func")) {
      return failure();
    }
    if (failed(createInputBuffer(func, rewriter))) {
      return failure();
    }
    return success();
  }
};


namespace {
struct EliminateTopfuncargMultiConsumer : public EliminateTopfuncargMultiConsumerBase<EliminateTopfuncargMultiConsumer> {

  EliminateTopfuncargMultiConsumer() = default;
  void runOnOperation() override {
    auto func = getOperation();
    auto context = func.getContext();
    mlir::RewritePatternSet patterns(context);
    patterns.add<EliminateTopfuncarg>(context);
    (void)applyOpPatternsAndFold({func}, std::move(patterns));
  }
};
} // namespace
std::unique_ptr<Pass> codo::createEliminateTopfuncargMultiConsumerPass() {
  return std::make_unique<EliminateTopfuncargMultiConsumer>();
}