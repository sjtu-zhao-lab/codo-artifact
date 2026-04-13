// #include "mlir/Dialect/Affine/Analysis/AffineAnalysis.h"
// #include "mlir/Dialect/LLVMIR/LLVMDialect.h"
// #include "mlir/Dialect/MemRef/IR/MemRef.h"
// #include "mlir/Dialect/Vector/IR/VectorOps.h"
// #include "mlir/Transforms/GreedyPatternRewriteDriver.h"
// #include "codo/Transforms/Passes.h"
// #include "codo/Support/Utils.h"

// Add headers
#include "mlir/Dialect/Tensor/IR/Tensor.h"


// Original headers
#include "mlir/IR/Dominance.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "codo/Transforms/Passes.h"
#include "codo/Support/Utils.h"
using namespace mlir;
using namespace codo;

namespace {
struct GraphPartition
    : public GraphPartitionBase<GraphPartition> {

  void runOnOperation() override {

    auto func_op = getOperation();
    assert(mlir::isa<func::FuncOp>(func_op));

    // Commenting out these two lines of code allows the compilation to succeed, 
    // but it will throw an error when executing codo-opt for unknown reasons.
    auto context = func_op.getContext();
    // context->getOrLoadDialect<codoDialect>();
    auto builder = OpBuilder(context);

    // ***************************************************************************************
    // This code snippet is sourced from ScaleHLS-HIDA: https://github.com/hanchenye/scalehls
    // ***************************************************************************************
    // Collect all empty tensors in the function and localize them to uses.
    // According to my understanding, the purpose of this code segment is to ensure a proper 
    // single producer-consumer relationship.
    // SmallVector<Operation *, 16> empties;
    // func_op.walk([&](tensor::EmptyOp op) { empties.push_back(op); });
    // for (auto empty : empties) {
    //   for (auto &use : llvm::make_early_inc_range(empty->getUses())) {
    //     builder.setInsertionPoint(use.getOwner());
    //     auto cloneEmpty = cast<tensor::EmptyOp>(builder.clone(*empty));
    //     use.set(cloneEmpty.getResult());
    //   }
    //   empty->erase();
    // }
    // ***************************************************************************************


    func_op.setSymName("main_graph");
    setFPGADeviceInfo(func_op, 1);
    // func_op.print(llvm::outs());
    if (!func_op)
      return signalPassFailure();
  }
};

} // namespace

// std::unique_ptr<Pass>
// codo::createGraphPartitionPass() {
//   return std::make_unique<GraphPartition>();
// }

namespace mlir {
namespace codo {

std::unique_ptr<Pass> createGraphPartitionPass() {
  return std::make_unique<GraphPartition>();
}

} // namespace hcl
} // namespace codo