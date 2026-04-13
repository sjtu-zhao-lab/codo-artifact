#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/Arith/IR/Arith.h"
#include "mlir/IR/PatternMatch.h"
#include "codo/Transforms/Passes.h"
#include "codo/Support/Utils.h"
#include "codo/Init_All_Dialects.h"

using namespace mlir;
using namespace mlir::affine;
using namespace codo;

namespace {
struct EliminateRedundant : public OpRewritePattern<func::FuncOp> {
  EliminateRedundant(MLIRContext *context) : OpRewritePattern<func::FuncOp>(context) {}

  bool isPureCopyLoop(Operation *op) const {
    bool hasComputation = false;
    op->walk([&](Operation *inner) {
      if (isa<arith::ArithDialect>(inner->getDialect())) {
        hasComputation = true;
        return WalkResult::interrupt();
      }
      return WalkResult::advance();
    });
    return !hasComputation;
  }

  LogicalResult matchAndRewrite(func::FuncOp func, PatternRewriter &rewriter) const override {
    llvm::SetVector<Operation *> opsToDelete;
    bool changed = false;

    struct Substitution {
      Value srcMemref;
      SmallVector<int, 4> dimMapping; 
    };
    llvm::DenseMap<Value, Substitution> bufferSubstitutionMap;

    func.walk([&](Operation *op) {
      auto bufferOp = dyn_cast<codo::BufferOp>(op);
      if (!bufferOp) return;

      Value bufferValue = bufferOp.getResult();
      AffineStoreOp copyStore = nullptr;
      AffineLoadOp copyLoadSource = nullptr;
      AffineForOp outermostLoop = nullptr;

      for (auto &use : bufferValue.getUses()) {
        if (auto storeOp = dyn_cast<AffineStoreOp>(use.getOwner())) {
          if (auto loadOp = storeOp.getValueToStore().getDefiningOp<AffineLoadOp>()) {
            copyStore = storeOp;
            copyLoadSource = loadOp;
            Operation *curr = storeOp;
            while (auto parentFor = curr->getParentOfType<AffineForOp>()) {
              outermostLoop = parentFor;
              curr = parentFor;
            }
            break; 
          }
        }
      }

      if (!copyStore || !copyLoadSource) return;

      Value srcMemref = copyLoadSource.getMemRef();
      auto bufferType = bufferValue.getType().cast<MemRefType>();
      auto srcType = srcMemref.getType().cast<MemRefType>();

      if (bufferType.getRank() != srcType.getRank() + 1) return;
      auto blockArg = srcMemref.dyn_cast<BlockArgument>();
      if (!blockArg || blockArg.getOwner() != &func.getBody().front()) return;

      auto bufferIndices = copyStore.getMapOperands();
      auto srcIndices = copyLoadSource.getMapOperands();
      SmallVector<int, 4> dimMapping;
      for (Value srcIdx : srcIndices) {
        for (int i = 0; i < (int)bufferIndices.size(); ++i) {
          if (bufferIndices[i] == srcIdx) {
            dimMapping.push_back(i);
            break;
          }
        }
      }

      if (dimMapping.size() == srcType.getRank()) {
        bufferSubstitutionMap[bufferValue] = {srcMemref, dimMapping};
        
        if (outermostLoop && isPureCopyLoop(outermostLoop)) {
          opsToDelete.insert(outermostLoop);
        } else {
          opsToDelete.insert(copyStore);
        }
        opsToDelete.insert(bufferOp);
      }
    });

    if (bufferSubstitutionMap.empty()) return failure();

    for (auto const& [bufferVal, sub] : bufferSubstitutionMap) {
      for (auto &use : llvm::make_early_inc_range(bufferVal.getUses())) {
        Operation *user = use.getOwner();
        
        if (llvm::any_of(opsToDelete, [&](Operation *del) { return del->isAncestor(user); }))
          continue;

        if (auto loadOp = dyn_cast<AffineLoadOp>(user)) {
          rewriter.setInsertionPoint(loadOp);
          auto oldIndices = loadOp.getMapOperands();
          SmallVector<Value, 4> newIndices;
          for (int bufferDimIdx : sub.dimMapping) 
            newIndices.push_back(oldIndices[bufferDimIdx]);

          auto newLoad = rewriter.create<AffineLoadOp>(
              loadOp.getLoc(), sub.srcMemref, 
              AffineMap::getMultiDimIdentityMap(newIndices.size(), rewriter.getContext()),
              newIndices);
          rewriter.replaceOp(loadOp, newLoad.getResult());
          changed = true;
        }
      }
    }

    for (auto op : llvm::reverse(opsToDelete)) {
      if (op->use_empty() || !isa<codo::BufferOp>(op)) {
        rewriter.eraseOp(op);
      }
    }

    return changed ? success() : failure();
  }
};
}

namespace {
struct EliminateRedundantArray : public EliminateRedundantArrayBase<EliminateRedundantArray> {
  EliminateRedundantArray() = default;
  
  void runOnOperation() override {
    auto func = getOperation();
    auto context = func.getContext();
    
    mlir::RewritePatternSet patterns(context);
    patterns.add<EliminateRedundant>(context);
    
    (void)applyOpPatternsAndFold({func}, std::move(patterns));
  }
};
} // namespace

std::unique_ptr<Pass> codo::createEliminateRedundantArrayPass() {
  return std::make_unique<EliminateRedundantArray>();
}