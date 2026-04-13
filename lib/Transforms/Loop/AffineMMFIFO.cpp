#include "mlir/IR/Builders.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Operation.h"
#include "mlir/IR/IntegerSet.h"
#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/Func/IR/FuncOps.h" // For func::FuncOp
#include "mlir/Dialect/Arith/IR/Arith.h" // For arith::ConstantOp
#include "mlir/Pass/Pass.h"             // For Pass
#include "mlir/Support/LogicalResult.h"
#include "mlir/Transforms/DialectConversion.h" // For OpRewritePattern, PatternRewriter
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/DenseSet.h"
#include "llvm/Support/raw_ostream.h"
#include "mlir/IR/IRMapping.h"          // For cloning and value mapping
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "mlir/Dialect/Utils/StaticValueUtils.h" // For getConstantIntValue
#include "mlir/Dialect/MemRef/IR/MemRef.h" 
#include "codo/Support/Utils.h"
#include "codo/Transforms/Passes.h"
#include "codo/Dialect/CodoOps.h"
#include <iomanip>
#include <optional>
#include <sstream>

#include <mutex>


static std::mutex g_llvmOutsMutex;

#define DEBUG_TYPE "affine-loop-fusion"

using namespace mlir;
using namespace mlir::affine;
using namespace codo;

void getIrrelativeLoops(Operation *op, SmallVector<AffineForOp> &IrrelativeLoops){
  if(!dyn_cast<AffineLoadOp>(op) && !dyn_cast<AffineStoreOp>(op))
  {return ;}

  // op->dump();
  // get all loops enclosing op
  SmallVector<AffineForOp> enclosingLoops;
  AffineForOp parentLoop = op->getParentOfType<AffineForOp>();
  while (parentLoop) {
      enclosingLoops.push_back(parentLoop);
      parentLoop = parentLoop->getParentOfType<AffineForOp>();
  }
  ValueRange mapOperands;
  AffineMap OpMap;
  if (AffineLoadOp loadop = dyn_cast<AffineLoadOp>(op))
  {
    mapOperands = loadop.getMapOperands();
    OpMap = loadop.getAffineMap();
  }
  if (AffineStoreOp storeop = dyn_cast<AffineStoreOp>(op))
  {
    mapOperands = storeop.getMapOperands();
    OpMap = storeop.getAffineMap();
  }
  

  SmallVector<Value> dependentIVs;
  for (Value operand : mapOperands) {
      if (auto forOp = operand.getDefiningOp<AffineForOp>()) {
          dependentIVs.push_back(forOp.getInductionVar());
      }
  }
  for (AffineForOp loop : enclosingLoops) {
    Value iv = loop.getInductionVar();
    if (std::count(mapOperands.begin(), mapOperands.end(), iv) == 0) {

        IrrelativeLoops.push_back(loop);
      }
  }
  return ;
}

void set_no_fifo(Value &array, OpBuilder &builder){
  auto savedIP = builder.saveInsertionPoint();
  builder.setInsertionPoint(array.getDefiningOp());
  MemRefType oldType = array.getType().cast<MemRefType>();
  auto new_type = MemRefType::get(
    oldType.getShape(), oldType.getElementType(),oldType.getLayout().getAffineMap(),
    MemoryKindAttr::get(oldType.getContext(), MemoryKind::BRAM_2P));
  auto new_array = builder.create<BufferOp>(builder.getUnknownLoc(), new_type);
  new_array.setStringAttr(StringRef("non_fifo"));
  array.replaceAllUsesWith(dyn_cast<Value>(new_array.getResult()));
  array.getDefiningOp()->erase();
  array = new_array;
  builder.restoreInsertionPoint(savedIP);
  return;
}
void set_no_fifo(Value &array, PatternRewriter &rewriter){
  auto savedIP = rewriter.saveInsertionPoint();
  rewriter.setInsertionPoint(array.getDefiningOp());
  MemRefType oldType = array.getType().cast<MemRefType>();
  auto new_type = MemRefType::get(
    oldType.getShape(), oldType.getElementType(),oldType.getLayout().getAffineMap(),
    MemoryKindAttr::get(oldType.getContext(), MemoryKind::BRAM_2P));
  auto new_array = rewriter.create<BufferOp>(rewriter.getUnknownLoc(), new_type);
  new_array.setStringAttr(StringRef("non_fifo"));
  array.replaceAllUsesWith(dyn_cast<Value>(new_array.getResult()));
  array.getDefiningOp()->erase();
  array = new_array;
  rewriter.restoreInsertionPoint(savedIP);
  return;
}

void set_fifo(Value &array, OpBuilder &builder){
  auto savedIP = builder.saveInsertionPoint();
  builder.setInsertionPoint(array.getDefiningOp());
  MemRefType oldType = array.getType().cast<MemRefType>();
  auto new_type = MemRefType::get(
    oldType.getShape(), oldType.getElementType(),oldType.getLayout().getAffineMap(),
    MemoryKindAttr::get(oldType.getContext(), MemoryKind::BRAM_2P));
  auto new_array = builder.create<BufferOp>(builder.getUnknownLoc(), new_type);
  array.replaceAllUsesWith(dyn_cast<Value>(new_array.getResult()));
  array.getDefiningOp()->erase();
  array = new_array;
  builder.restoreInsertionPoint(savedIP);
  return;
}

// namespace {
//   struct MultiLoad : public OpRewritePattern<AffineLoadOp> {
//     using OpRewritePattern<AffineLoadOp>::OpRewritePattern;
//     LogicalResult matchAndRewrite(
//       AffineLoadOp loadOp,
//       PatternRewriter &rewriter
//     ) const override {
//       auto memref = loadOp.getOperand(0);
//       AffineForOp forOp = loadOp->getParentOfType<AffineForOp>();
//       if (forOp) {
//         bool hasStoreInLoop = false;
//         forOp.walk([&](AffineStoreOp storeOp) {
//           if (storeOp.getMemRef() == memref) {
//             hasStoreInLoop = true;
//           }
//         });

//         if (!hasStoreInLoop) {

//           SmallVector<AffineForOp> irrelative_load_loops;

//           getIrrelativeLoops(loadOp.getOperation(), irrelative_load_loops);

//           if(irrelative_load_loops.size() > 0){
//             Operation *defOp = memref.getDefiningOp();
//             bool isFunctionArg = !defOp;

//             auto memrefType = memref.getType().cast<MemRefType>();
//             Value newMemRef;

//             if (isFunctionArg)
//             {
//               Block *entryBlock = &loadOp->getParentOfType<func::FuncOp>().getBody().front();
//               rewriter.setInsertionPointToStart(entryBlock);
//               newMemRef = rewriter.create<memref::AllocOp>(rewriter.getUnknownLoc(), memrefType);
//             }
//             else
//             {
//               rewriter.setInsertionPointAfter(defOp);
//               newMemRef = rewriter.create<memref::AllocOp>(rewriter.getUnknownLoc(), memrefType);
//             }

//             set_no_fifo(newMemRef, rewriter);
//             Value iv = forOp.getInductionVar();
//             AffineMap lbMap = forOp.getLowerBoundMap();
//             ValueRange lbOperands = forOp.getLowerBoundOperands();
            

//             AffineExpr dim0 = rewriter.getAffineDimExpr(0);
//             AffineExpr lbExpr = lbMap.getResult(0);
//             AffineExpr eqExpr = dim0 - lbExpr;
            

//             SmallVector<AffineExpr> exprs = {eqExpr};
//             SmallVector<bool> eqFlags = {true}; 
//             auto integerSet = IntegerSet::get(
//                 /*dimCount=*/1,  
//                 /*symbolCount=*/lbMap.getNumInputs(),
//                 exprs, 
//                 eqFlags
//             );
//             SmallVector<Value> ifOperands = {iv};
//             llvm::append_range(ifOperands, lbOperands);

//             rewriter.setInsertionPoint(loadOp.getOperation());


//             auto ifOp = rewriter.create<AffineIfOp>(
//             rewriter.getUnknownLoc(), integerSet, ifOperands, /*withElseRegion=*/false);
//             rewriter.setInsertionPointToStart(ifOp.getThenBlock());
//             auto newLoadOp = rewriter.create<AffineLoadOp>(
//               rewriter.getUnknownLoc(),
//               memref,
//               loadOp.getAffineMap(), 
//               loadOp.getMapOperands()
//             );
//             // new store to newAllocOp
//             rewriter.create<AffineStoreOp>(
//               rewriter.getUnknownLoc(), 
//               newLoadOp.getResult(), 
//               newMemRef, 
//               loadOp.getAffineMap(),
//               loadOp.getMapOperands()
//             );

//             rewriter.setInsertionPoint(loadOp.getOperation());
//             auto newLoadOp1 = rewriter.create<AffineLoadOp>(
//               rewriter.getUnknownLoc(),
//               newMemRef,
//               loadOp.getAffineMap(), 
//               loadOp.getMapOperands()
//             );
//             loadOp.getResult().replaceAllUsesWith(newLoadOp1.getResult());
//             loadOp.dump();
//             loadOp.erase();
//             return success();
//           }
//           return failure();
//                     }
//           return failure();
//         }
//         return failure();
//     }
//   };
// }

static bool isSingleIterationLoop(AffineForOp forOp) {
  auto lbMap = forOp.getLowerBoundMap();
  auto ubMap = forOp.getUpperBoundMap();

  // 只处理最安全、最常见的情况：常量上下界
  if (!lbMap.isSingleConstant() || !ubMap.isSingleConstant())
    return false; // 保守：不确定就当成多次

  int64_t lb = lbMap.getSingleConstantResult();
  int64_t ub = ubMap.getSingleConstantResult();
  int64_t step = forOp.getStep().getSExtValue();

  return (ub - lb) <= step;
}
void removeSingleIterationLoops(
    SmallVectorImpl<AffineForOp> &irrelativeLoops) {

  irrelativeLoops.erase(
      llvm::remove_if(irrelativeLoops,
                      [](AffineForOp loop) {
                        return isSingleIterationLoop(loop);
                      }),
      irrelativeLoops.end());
}


void EliminateMultiLoad(func::FuncOp func, OpBuilder &builder){
  SmallVector<AffineLoadOp> violation_loadops;
    SmallVector<AffineForOp> corresponding_forops;

      func.walk([&](AffineLoadOp loadOp)
    {
      auto memref = loadOp.getOperand(0);
      auto context = builder.getContext();
      auto parentOp = loadOp->getParentOp();
      AffineForOp forOp;
      if (dyn_cast<AffineForOp>(parentOp))
      {
        forOp = dyn_cast<AffineForOp>(parentOp);
        bool hasStoreInLoop = false;
        forOp.walk([&](AffineStoreOp storeOp) {
          if (storeOp.getMemRef() == memref) {
            hasStoreInLoop = true;
          }
        });

        if (!hasStoreInLoop) {

          SmallVector<AffineForOp> irrelative_load_loops;

          getIrrelativeLoops(loadOp.getOperation(), irrelative_load_loops);

          removeSingleIterationLoops(irrelative_load_loops);

          if(irrelative_load_loops.size() > 0){
            violation_loadops.push_back(loadOp);
            corresponding_forops.push_back(irrelative_load_loops[0]);
          }
          
          }
      }
      
    }
    );
    if(violation_loadops.size() > 0){
      for (int i = 0; i < violation_loadops.size();i++)
      {

        auto loadOp = violation_loadops[i];
        auto memref = loadOp.getOperand(0);
        auto forOp = corresponding_forops[i];

        Operation *defOp = memref.getDefiningOp();
        bool isFunctionArg = !defOp;

        auto memrefType = memref.getType().cast<MemRefType>();
        Value newMemRef;

        if (isFunctionArg)
        {
          Block *entryBlock = &loadOp->getParentOfType<func::FuncOp>().getBody().front();
          builder.setInsertionPointToStart(entryBlock);
          newMemRef = builder.create<memref::AllocOp>(builder.getUnknownLoc(), memrefType);
        }
        else
        {
          builder.setInsertionPointAfter(defOp);
          newMemRef = builder.create<memref::AllocOp>(builder.getUnknownLoc(), memrefType);
        }

        set_no_fifo(newMemRef, builder);
        Value iv = forOp.getInductionVar();
        AffineMap lbMap = forOp.getLowerBoundMap();
        ValueRange lbOperands = forOp.getLowerBoundOperands();
        

        AffineExpr dim0 = builder.getAffineDimExpr(0);
        AffineExpr lbExpr = lbMap.getResult(0);
        AffineExpr eqExpr = dim0 - lbExpr;
        

        SmallVector<AffineExpr> exprs = {eqExpr};
        SmallVector<bool> eqFlags = {true}; 
        auto integerSet = IntegerSet::get(
            /*dimCount=*/1,  
            /*symbolCount=*/lbMap.getNumInputs(),
            exprs, 
            eqFlags
        );
        SmallVector<Value> ifOperands = {iv};
        llvm::append_range(ifOperands, lbOperands);

        builder.setInsertionPoint(loadOp.getOperation());


        auto ifOp = builder.create<AffineIfOp>(
        builder.getUnknownLoc(), integerSet, ifOperands, /*withElseRegion=*/false);
        builder.setInsertionPointToStart(ifOp.getThenBlock());
        auto newLoadOp = builder.create<AffineLoadOp>(
          builder.getUnknownLoc(),
          memref,
          loadOp.getAffineMap(), 
          loadOp.getMapOperands()
        );
        // new store to newAllocOp
        builder.create<AffineStoreOp>(
          builder.getUnknownLoc(), 
          newLoadOp.getResult(), 
          newMemRef, 
          loadOp.getAffineMap(),
          loadOp.getMapOperands()
        );

        builder.setInsertionPoint(loadOp.getOperation());
        auto newLoadOp1 = builder.create<AffineLoadOp>(
          builder.getUnknownLoc(),
          newMemRef,
          loadOp.getAffineMap(), 
          loadOp.getMapOperands()
        );
        loadOp.getResult().replaceAllUsesWith(newLoadOp1.getResult());
        loadOp.erase();
      }
    }
      
}

void EliminateStoreLoad(func::FuncOp func, OpBuilder &builder){


    SmallVector<AffineStoreOp> violation_stores;
    SmallVector<AffineLoadOp> violation_loads;
    SmallVector<AffineForOp> corresponding_forops;

    func.walk([&](AffineLoadOp loadOp)
              {
                auto memref = loadOp.getOperand(0);
                auto context = builder.getContext();
                AffineForOp forOp = loadOp->getParentOfType<AffineForOp>();
                AffineStoreOp storeOp;
                if (forOp)
                {
                  bool hasStoreInLoop = false;
                  forOp.walk([&](AffineStoreOp sOp)
                             {
          if (sOp.getMemRef() == memref) {
            storeOp = sOp;
            hasStoreInLoop = true;
          } });

                  if (hasStoreInLoop)
                  {

                    SmallVector<AffineForOp> irrelative_load_loops;

                    getIrrelativeLoops(loadOp.getOperation(), irrelative_load_loops);

                    if (irrelative_load_loops.size() > 0)
                    {
                      violation_stores.push_back(storeOp);
                      violation_loads.push_back(loadOp);
                      corresponding_forops.push_back(irrelative_load_loops[0]);
                    }
                  }
                }
              });
    if(violation_loads.size() == 0){
      return;
    }
    auto loadOp = violation_loads[0];
    auto storeOp = violation_stores[0];
    auto memref = loadOp.getOperand(0);
    auto forOp = corresponding_forops[0];
    AffineStoreOp store_init;

    for(auto op:memref.getUsers())
    {
      if(AffineStoreOp store = dyn_cast<AffineStoreOp>(op))
      {
        if(store != storeOp){
          store_init = store;
        }
      }
    }


    // std::unique_lock<std::mutex> lock(g_llvmOutsMutex);
    // loadOp.dump();
    // storeOp.dump();
    // lock.unlock();

    Operation *defOp = memref.getDefiningOp();
    bool isFunctionArg = !defOp;

    auto memrefType = memref.getType().cast<MemRefType>();
    Value newMemRef1, newMemRef2;

    if (isFunctionArg)
    {
      Block *entryBlock = &loadOp->getParentOfType<func::FuncOp>().getBody().front();
      builder.setInsertionPointToStart(entryBlock);
      newMemRef1 = builder.create<memref::AllocOp>(builder.getUnknownLoc(), memrefType);
      newMemRef2 = builder.create<memref::AllocOp>(builder.getUnknownLoc(), memrefType);
    }
    else
    {
      builder.setInsertionPointAfter(defOp);
      newMemRef1 = builder.create<memref::AllocOp>(builder.getUnknownLoc(), memrefType);
      newMemRef2 = builder.create<memref::AllocOp>(builder.getUnknownLoc(), memrefType);
    }

    
    set_fifo(newMemRef1, builder);
    set_no_fifo(newMemRef2, builder);

    store_init.setMemRef(newMemRef1);
    Value iv = forOp.getInductionVar();
    AffineMap lbMap = forOp.getLowerBoundMap();
    ValueRange lbOperands = forOp.getLowerBoundOperands();
    

    AffineExpr dim0 = builder.getAffineDimExpr(0);
    AffineExpr lbExpr = lbMap.getResult(0);
    AffineExpr eqExpr = dim0 - lbExpr;
    

    SmallVector<AffineExpr> exprs = {eqExpr};
    SmallVector<bool> eqFlags = {true}; 
    auto integerSet = IntegerSet::get(
        /*dimCount=*/1,  
        /*symbolCount=*/lbMap.getNumInputs(),
        exprs, 
        eqFlags
    );
    SmallVector<Value> ifOperands = {iv};
    llvm::append_range(ifOperands, lbOperands);

    builder.setInsertionPoint(loadOp.getOperation());


    auto ifOp = builder.create<AffineIfOp>(
    builder.getUnknownLoc(), integerSet, ifOperands, /*withElseRegion=*/false);
    builder.setInsertionPointToStart(ifOp.getThenBlock());
    auto newLoadOp = builder.create<AffineLoadOp>(
      builder.getUnknownLoc(),
      newMemRef1,
      loadOp.getAffineMap(), 
      loadOp.getMapOperands()
    );
    // new store to newAllocOp
    builder.create<AffineStoreOp>(
      builder.getUnknownLoc(), 
      newLoadOp.getResult(), 
      newMemRef2, 
      loadOp.getAffineMap(),
      loadOp.getMapOperands()
    );

    builder.setInsertionPoint(loadOp.getOperation());
    auto newLoadOp1 = builder.create<AffineLoadOp>(
      builder.getUnknownLoc(),
      newMemRef2,
      loadOp.getAffineMap(), 
      loadOp.getMapOperands()
    );
    loadOp.getResult().replaceAllUsesWith(newLoadOp1.getResult());
    loadOp.erase();



    AffineMap ubMap = forOp.getUpperBoundMap();
    ValueRange ubOperands = forOp.getUpperBoundOperands();
    AffineExpr ubExpr = ubMap.getResult(0);
    eqExpr = dim0 - ubExpr + 1;
    exprs = {eqExpr};
    eqFlags = {true}; 
    integerSet = IntegerSet::get(
        /*dimCount=*/1,  
        /*symbolCount=*/ubMap.getNumInputs(),
        exprs, 
        eqFlags
    );
    ifOperands = {iv};
    llvm::append_range(ifOperands, ubOperands);

    builder.setInsertionPointAfter(storeOp.getOperation());


    ifOp = builder.create<AffineIfOp>(
    builder.getUnknownLoc(), integerSet, ifOperands, /*withElseRegion=*/false);
    builder.setInsertionPointToStart(ifOp.getThenBlock());
    newLoadOp = builder.create<AffineLoadOp>(
      builder.getUnknownLoc(),
      newMemRef2,
      storeOp.getAffineMap(), 
      storeOp.getMapOperands()
    );
    // new store to newAllocOp
    auto new_storeOp = builder.create<AffineStoreOp>(
      builder.getUnknownLoc(), 
      newLoadOp.getResult(), 
      memref, 
      storeOp.getAffineMap(),
      storeOp.getMapOperands()
    );

    builder.setInsertionPoint(storeOp.getOperation());
    builder.create<AffineStoreOp>(
      builder.getUnknownLoc(),
      storeOp.getValueToStore(),
      newMemRef2,
      storeOp.getAffineMap(), 
      storeOp.getMapOperands()
    );
    storeOp.erase();




}

void EliminateDistribution(func::FuncOp func, OpBuilder &builder){


    // SmallVector<AffineStoreOp> violation_stores;
    // SmallVector<AffineLoadOp> violation_loads;
    // SmallVector<AffineForOp> corresponding_forops;

    func.walk([&](AffineLoadOp loadOp)
              {
    auto memref = loadOp.getOperand(0);
    auto context = builder.getContext();
    SmallVector<AffineStoreOp> allstores;
    AffineStoreOp storeOp;
    Operation *defOp = memref.getDefiningOp();
    bool isFunctionArg = !defOp;
    if(isFunctionArg){
      for(auto user: memref.getUsers())
      {
        if(dyn_cast<AffineStoreOp>(user)){allstores.push_back(dyn_cast<AffineStoreOp>(user));}
      }
      if(allstores.size()==1)
      {
        storeOp = allstores[0];
        auto memrefType = memref.getType().cast<MemRefType>();
        Value newMemRef1;
        Block *entryBlock = &loadOp->getParentOfType<func::FuncOp>().getBody().front();
        builder.setInsertionPointToStart(entryBlock);
        newMemRef1 = builder.create<memref::AllocOp>(builder.getUnknownLoc(), memrefType);
        auto store_res = storeOp.getValueToStore();
        builder.setInsertionPointAfter(storeOp.getOperation());
        builder.create<AffineStoreOp>(
            builder.getUnknownLoc(), 
            store_res, 
            newMemRef1, 
            storeOp.getAffineMap(),
            storeOp.getMapOperands()
          );
        builder.setInsertionPoint(loadOp.getOperation());
        auto newLoadOp = builder.create<AffineLoadOp>(
          builder.getUnknownLoc(),
          newMemRef1,
          loadOp.getAffineMap(), 
          loadOp.getMapOperands()
        );
        loadOp.getResult().replaceAllUsesWith(newLoadOp.getResult());
        loadOp.erase();

        
    }
  }}
);

}

namespace {
struct AffineMMFIFO
    : public AffineMMFIFOBase<AffineMMFIFO> {
  void runOnOperation() override {
    auto func = getOperation();
    auto context = func.getContext();
    mlir::RewritePatternSet patterns(context);
    mlir::Block &entryBlock = func.getBody().front();
    mlir::OpBuilder builder(&entryBlock, entryBlock.begin());

    // func.walk([&](affine::AffineForOp forOp) {
    //     if (!isa<affine::AffineForOp>(forOp->getParentOp())) {
    //         llvm::outs()<<"Not Found"<<"\n";
    //         if (is_gemm(forOp)) {
    //             llvm::outs()<<"Found"<<"\n";
    //         }
    //     }
    // });
   
    EliminateStoreLoad(func, builder);
    EliminateMultiLoad(func, builder);
    EliminateDistribution(func, builder);
    // patterns.clear();
    // patterns.add<MultiLoad>(context);
    // (void)applyPatternsAndFoldGreedily(func, std::move(patterns));
  }
};
}
std::unique_ptr<Pass> codo::createAffineMMFIFOPass() {
  return std::make_unique<AffineMMFIFO>();
}
