#include "mlir/Dialect/Affine/Analysis/AffineAnalysis.h"
#include "mlir/Dialect/Affine/Analysis/Utils.h"
#include "mlir/Dialect/Affine/Utils.h"
#include "mlir/Dialect/Affine/LoopUtils.h"
#include "codo/Transforms/Passes.h"
#include "codo/Support/Utils.h"
#include "codo/Dialect/CodoOps.h"
#include "codo/Support/Explorer.h"
#include "codo/Support/Utils.h"
#include "codo/Support/Estimator.h"
#include "codo/Transforms/Passes.h"
#include "codo/Init_All_Dialects.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/raw_ostream.h"
#include "codo/Init_All_Dialects.h"

#include <mutex>


static std::mutex g_llvmOutsMutex;
// #define DEBUG_TYPE "codo"

using namespace mlir;
using namespace mlir::affine;
using namespace codo;

static void updateTopFunc(func::FuncOp topFunc, Builder builder) {
    topFunc.walk([&](func::CallOp callOp) {
        auto callee = SymbolTable::lookupNearestSymbolFrom(callOp, callOp.getCalleeAttr());
        auto subFunc = dyn_cast<func::FuncOp>(callee);
        if (!subFunc) return;

        DenseMap<Value, Value> argMapping;
        for (unsigned index = 0; index < callOp.getNumOperands(); ++index) {
            auto operand = callOp.getOperand(index);
            auto subArg = subFunc.getArgument(index);
            argMapping[operand] = subArg;
        }

        for (auto &mapping : argMapping) {
            auto operand = mapping.first;
            auto subArgType = mapping.second.getType();
            int temp = -1;
            for (unsigned index = 0; index < topFunc.getNumArguments(); ++index)
            {
              if (operand == topFunc.getArgument(index))
              {
                temp = index;
              }
            }
            if (temp == -1) {
                operand.setType(subArgType);
            }
            if(temp!=-1){
              topFunc.getArgument(temp).setType(subArgType);
            }
        }
        auto resultTypes = topFunc.front().getTerminator()->getOperandTypes();
        auto inputTypes = topFunc.front().getArgumentTypes();
        topFunc.setType(builder.getFunctionType(inputTypes, resultTypes));


    });
}
// static void set_no_fifo(Value &array, OpBuilder &builder){
//   auto savedIP = builder.saveInsertionPoint();
//   builder.setInsertionPoint(array.getDefiningOp());
//   MemRefType oldType = array.getType().cast<MemRefType>();
//   auto new_type = MemRefType::get(
//     oldType.getShape(), oldType.getElementType(),oldType.getLayout().getAffineMap(),
//     MemoryKindAttr::get(oldType.getContext(), MemoryKind::BRAM_2P));
//   auto new_array = builder.create<BufferOp>(builder.getUnknownLoc(), new_type);
//   new_array.setStringAttr(StringRef("non_fifo"));
//   array.replaceAllUsesWith(dyn_cast<Value>(new_array.getResult()));
//   array.getDefiningOp()->erase();
//   array = new_array;
//   builder.restoreInsertionPoint(savedIP);
//   return;
// }

bool is_initialization(AffineStoreOp storeop, AffineLoopBand store_band)
{
  auto op = storeop.getOperation();
  SmallVector<AffineForOp> enclosingLoops;
  AffineForOp parentLoop = op->getParentOfType<AffineForOp>();
  while (parentLoop)
  {
    enclosingLoops.push_back(parentLoop);
    parentLoop = parentLoop->getParentOfType<AffineForOp>();
  }
  ValueRange mapOperands;
  AffineMap OpMap;

  mapOperands = storeop.getMapOperands();
  OpMap = storeop.getAffineMap();
  SmallVector<Value> dependentIVs;
  for (Value operand : mapOperands) {
    for(auto forOp: store_band)
    {
      if(operand == forOp.getInductionVar())
      {
        dependentIVs.push_back(forOp.getInductionVar());
      }
    }
  }
  bool is_initialization = dependentIVs.size() == enclosingLoops.size();
  return is_initialization;
}



bool is_consistent(BufferOp bufferop, AffineStoreOp storeop, AffineLoadOp loadop, bool isTopbuffer, bool change)
{
  std::vector<int> store_depth;
  std::vector<int> load_depth;
  std::vector<int> store_numberOfArgs, load_numberOfArgs;
  mlir::ArrayRef<mlir::AffineExpr> store_exprs, load_exprs;
  if (!storeop || !loadop) {
    if (change) {
        bufferop.setStringAttr(StringRef("non_fifo"));
        // auto builder = OpBuilder(bufferop.getOperation()->getParentOfType<func::FuncOp>());
        // auto buffer_val = bufferop.getResult();
        // set_no_fifo(buffer_val, builder);
    }
    return false; 
  }
  if (!storeop->getParentOp() || !loadop->getParentOp()) {
    if (change) {
        bufferop.setStringAttr(StringRef("non_fifo"));
        // auto builder = OpBuilder(bufferop.getOperation()->getParentOfType<func::FuncOp>());
        // auto buffer_val = bufferop.getResult();
        // set_no_fifo(buffer_val, builder);
    }
    return false;
  }
  AffineForOp store_inner_for = storeop.getOperation()->getParentOfType<AffineForOp>();
  AffineForOp load_inner_for = loadop.getOperation()->getParentOfType<AffineForOp>();
  if (!store_inner_for || !load_inner_for) {
    if (change) {
        bufferop.setStringAttr(StringRef("non_fifo"));
        // auto builder = OpBuilder(bufferop.getOperation()->getParentOfType<func::FuncOp>());
        // auto buffer_val = bufferop.getResult();
        // set_no_fifo(buffer_val, builder);
    }
    return false; 
  }
  AffineLoopBand store_band, load_band;
  getLoopBandFromInnermost(store_inner_for, store_band);
  getLoopBandFromInnermost(load_inner_for, load_band);
  if (store_band.empty() || load_band.empty()) {
        if (change) {
            bufferop.setStringAttr(StringRef("non_fifo"));
            // auto builder = OpBuilder(bufferop.getOperation()->getParentOfType<func::FuncOp>());
            // auto buffer_val = bufferop.getResult();
            // set_no_fifo(buffer_val, builder);
        }
        return false;
  }

  AffineForOp top_store_loop, top_load_loop;
  top_store_loop = store_band.front(); 
  top_load_loop = load_band.front();
  
    if(storeop){
  auto indices = storeop.getIndices();
  auto affinemap = storeop.getAffineMap();
  auto exprs = affinemap.getResults();
  store_exprs = exprs;
  int indexDims = exprs.size();
  std::vector<int> numberOfArgs(indexDims, 0);
  for (int dimIndex=0; dimIndex<indexDims; dimIndex++) {
  if (auto dimExpr = exprs[dimIndex].dyn_cast<AffineDimExpr>()) {
    unsigned dimPosition = dimExpr.getPosition();
    numberOfArgs[dimIndex]=1;
  }else if (auto dimExpr = exprs[dimIndex].dyn_cast<AffineConstantExpr>()) {
    numberOfArgs[dimIndex]=1;
  }
  else if(auto dimExpr = exprs[dimIndex].dyn_cast<AffineBinaryOpExpr>()){
    if (auto outerRHS = dimExpr.getRHS().dyn_cast<AffineBinaryOpExpr>()) {
      if (auto innerRHS = outerRHS.getRHS().dyn_cast<AffineDimExpr>()) {
        unsigned dimPosition = innerRHS.getPosition();
        numberOfArgs[dimIndex]+=1;
      }
      if(auto innerLHS = outerRHS.getLHS().dyn_cast<AffineDimExpr>()){
        unsigned dimPosition = innerLHS.getPosition();
        numberOfArgs[dimIndex]+=1;
      }
    }
    if (auto outerLHS = dimExpr.getLHS().dyn_cast<AffineBinaryOpExpr>()) {
      if (auto innerRHS = outerLHS.getRHS().dyn_cast<AffineDimExpr>()) {
        unsigned dimPosition = innerRHS.getPosition();
        numberOfArgs[dimIndex]+=1;
        // llvm::outs()<<"dimPosition: "<<dimPosition<<"\n";
      }
      if(auto innerLHS = outerLHS.getLHS().dyn_cast<AffineDimExpr>()){
        unsigned dimPosition = innerLHS.getPosition();
        numberOfArgs[dimIndex]+=1;
      }
    }if(auto outerRHS = dimExpr.getRHS().dyn_cast<AffineDimExpr>()){
        unsigned dimPosition = outerRHS.getPosition();
        numberOfArgs[dimIndex]+=1;
    }if(auto outerLHS = dimExpr.getLHS().dyn_cast<AffineDimExpr>()){
        unsigned dimPosition = outerLHS.getPosition();
        numberOfArgs[dimIndex]+=1;
      }
    }
  }

  for (auto operand : indices)
  {
    int level = 0;
    top_store_loop.walk([&](affine::AffineForOp op)
                        {
        auto inductionVar = op.getInductionVar();
        if (operand == inductionVar) {
            
            store_depth.push_back(store_band.size() - level - 1);
        }
        level+=1; });
  }
  store_numberOfArgs = numberOfArgs;
  }
  if(loadop){
  auto indices = loadop.getIndices();
  auto affinemap = loadop.getAffineMap();
  auto exprs = affinemap.getResults();
  load_exprs = exprs;
  int indexDims = exprs.size();
  std::vector<int> numberOfArgs(indexDims, 0);
  for (int dimIndex=0; dimIndex<indexDims; dimIndex++) {
  if (auto dimExpr = exprs[dimIndex].dyn_cast<AffineDimExpr>()) {
    unsigned dimPosition = dimExpr.getPosition();
    numberOfArgs[dimIndex]=1;
  }else if (auto dimExpr = exprs[dimIndex].dyn_cast<AffineConstantExpr>()) {
    numberOfArgs[dimIndex]=1;
  }
  else if(auto dimExpr = exprs[dimIndex].dyn_cast<AffineBinaryOpExpr>()){
    if (auto outerRHS = dimExpr.getRHS().dyn_cast<AffineBinaryOpExpr>()) {
      if (auto innerRHS = outerRHS.getRHS().dyn_cast<AffineDimExpr>()) {
        unsigned dimPosition = innerRHS.getPosition();
        numberOfArgs[dimIndex]+=1;
      }
      if(auto innerLHS = outerRHS.getLHS().dyn_cast<AffineDimExpr>()){
        unsigned dimPosition = innerLHS.getPosition();
        numberOfArgs[dimIndex]+=1;
      }
    }
    if (auto outerLHS = dimExpr.getLHS().dyn_cast<AffineBinaryOpExpr>()) {
      if (auto innerRHS = outerLHS.getRHS().dyn_cast<AffineDimExpr>()) {
        unsigned dimPosition = innerRHS.getPosition();
        numberOfArgs[dimIndex]+=1;
      }
      if(auto innerLHS = outerLHS.getLHS().dyn_cast<AffineDimExpr>()){
        unsigned dimPosition = innerLHS.getPosition();
        numberOfArgs[dimIndex]+=1;
      }
    }if(auto outerRHS = dimExpr.getRHS().dyn_cast<AffineDimExpr>()){
        unsigned dimPosition = outerRHS.getPosition();
        numberOfArgs[dimIndex]+=1;
    }if(auto outerLHS = dimExpr.getLHS().dyn_cast<AffineDimExpr>()){
        unsigned dimPosition = outerLHS.getPosition();
        numberOfArgs[dimIndex]+=1;
      }
    }
  }
  
  int num_erased = 0;
  
  if (store_exprs.size() != load_exprs.size()) {
      bufferop.setStringAttr(StringRef("non_fifo"));
      // auto builder = OpBuilder(bufferop.getOperation()->getParentOfType<func::FuncOp>());
      // auto buffer_val = bufferop.getResult();
      // set_no_fifo(buffer_val, builder);
      return false; 
  }

  
  for(int i = 0; i < store_exprs.size(); i++) {
     
      if(load_exprs[i].dyn_cast<AffineConstantExpr>() && !store_exprs[i].dyn_cast<AffineConstantExpr>())
      {
        store_depth.erase(store_depth.begin() + i - num_erased);
        num_erased ++;
        continue;
      }
  }
  
  int indices_index = 0;
  for (int i = 0; i<indices.size() ;i++) {
    
    auto operand = indices[i];
    int level = 0;
    top_load_loop.walk([&](affine::AffineForOp op) {
        
        auto inductionVar = op.getInductionVar();
        if (operand == inductionVar) {
            load_depth.push_back(load_band.size() - level - 1);
        }
        level+=1;
    });
  }

  load_numberOfArgs = numberOfArgs;
  }
  

  std::vector<int> indices1(store_depth.size());
  for (int i = 0; i < store_depth.size(); ++i) {
      indices1[i] = i; 
  }
  std::sort(indices1.begin(), indices1.end(), [&](int a, int b) {
      return store_depth[a] > store_depth[b]; // 从大到小排序
  });
  
  std::vector<int> indices2(load_depth.size());
  for (int i = 0; i < load_depth.size(); ++i) {
      indices2[i] = i; 
  }
  std::sort(indices2.begin(), indices2.end(), [&](int a, int b) {
      return load_depth[a] > load_depth[b]; // 从大到小排序
  });
  
  bool consistent = true;

  if (load_depth.size() != store_depth.size()) { 
      consistent = false;
  } else {
      
      for(int i = 0; i < load_depth.size(); ++i) {
          
          if(indices1[i] != indices2[i]) {
              consistent = false;
              break;
          }
      }
  }


  if(!consistent && change){
    
    
    if(isTopbuffer)
    {
      if(is_gemm(store_band[0]) && is_gemm(load_band[0]))
      {
        int depth = store_band.size();
        unsigned perm[depth];
        for (int i = 0; i < depth; ++i)
        {
          perm[i] = i;
        }
        for (int i = 0; i < load_depth.size(); ++i)
        {
          perm[store_depth[indices1[i]]] = store_depth[indices2[i]];
        }
        
        ArrayRef<unsigned> permMap(perm, depth);
        permuteLoops(store_band, permMap);
      }
      else
      {
        bufferop.setStringAttr(StringRef("non_fifo"));
        // auto builder = OpBuilder(bufferop.getOperation()->getParentOfType<func::FuncOp>());
        // auto buffer_val = bufferop.getResult();
        // set_no_fifo(buffer_val, builder);
      }
    }
    else{
      if (is_initialization(storeop, store_band) && is_gemm(load_band[0]))
      {
        int depth = store_band.size();
        unsigned perm[depth];
        for (int i = 0; i < depth; ++i)
        {
          perm[i] = i;
        }
        for (int i = 0; i < load_depth.size(); ++i)
        {
          perm[store_depth[indices1[i]]] = store_depth[indices2[i]];
        }
        
        ArrayRef<unsigned> permMap(perm, depth);
        auto newroot = store_band[permuteLoops(store_band, permMap)];
      }
      else
      {
        bufferop.setStringAttr(StringRef("non_fifo"));
        // auto builder = OpBuilder(bufferop.getOperation()->getParentOfType<func::FuncOp>());
        // auto buffer_val = bufferop.getResult();
        // set_no_fifo(buffer_val, builder);
      }
    }
  }
  return consistent;
}


namespace {
struct FIFOornot : public FIFOornotBase<FIFOornot> {
  void runOnOperation() override {
    ModuleOp module = getOperation();

    std::vector<func::FuncOp> funcList;
    std::vector<codo::BufferOp> TopFuncBufferList;
    std::vector<codo::BufferOp> SubFuncBufferList;
    std::vector<AffineStoreOp> TopStoreOps, SubStoreOps;
    std::vector<AffineLoadOp> TopLoadOps, SubLoadOps;
    func::FuncOp topFunction;
    module.walk([&](func::FuncOp topFunc) {
      if (hasTopFuncAttr(topFunc)) { 
        topFunction = topFunc;
        topFunc.walk([&](BufferOp op) {
            auto returnOp = dyn_cast<func::ReturnOp>(topFunction.getBody().front().getTerminator());
            bool isReturnValue = false;

            if (returnOp && returnOp.getNumOperands() > 0) {
                if (op.getResult() == returnOp.getOperand(0)) {
                    isReturnValue = true;
                }
            }

            if (!isReturnValue && op.getStringAttr() != StringRef("non_fifo")) {
                TopFuncBufferList.push_back(op);
            }
        });
        topFunc.walk([&](Operation *op) {
          if (auto callOp = dyn_cast<func::CallOp>(op)) {
            StringRef callee = callOp.getCallee();
            module.lookupSymbol<func::FuncOp>(callee).walk([&](func::FuncOp childFunc) {
              funcList.push_back(childFunc);
            });
          }
        });
      }
    });

    struct ValidBufferInfo {
    codo::BufferOp buffer;
    mlir::affine::AffineStoreOp storeOp;
    mlir::affine::AffineLoadOp loadOp;
    };

    std::vector<ValidBufferInfo> validBuffers; 

    for (auto bufferop : TopFuncBufferList) {
        SmallVector<AffineStoreOp, 3> associatedStores;
        SmallVector<AffineLoadOp, 3> associatedLoads;

        for (auto *opUser : bufferop.getResult().getUsers()) {
            if (auto callOp = dyn_cast<func::CallOp>(opUser)) {
                int argIndex = -1;
                for (unsigned i = 0; i < callOp.getNumOperands(); ++i) {
                    if (callOp.getOperand(i) == bufferop.getResult()) {
                        argIndex = i;
                        break;
                    }
                }
                if (argIndex == -1) continue;

                auto callee = module.lookupSymbol<func::FuncOp>(callOp.getCallee());
                if (!callee) continue;
                
                Value funcArg = callee.getArgument(argIndex);
                for (auto *funcArgUser : funcArg.getUsers()) {
                    if (auto store = dyn_cast<AffineStoreOp>(funcArgUser)) {
                        associatedStores.push_back(store);
                    }
                    if (auto load = dyn_cast<AffineLoadOp>(funcArgUser)) {
                        associatedLoads.push_back(load);
                    }
                }
            }
        }

        if (associatedStores.size() != 1 || associatedLoads.size() != 1) {
            bufferop.setStringAttr(StringRef("non_fifo"));
        } else {
            validBuffers.push_back({bufferop, associatedStores.front(), associatedLoads.front()});
        }
    }

    for (const auto& info : validBuffers) {
        bool consistent = is_consistent(info.buffer, info.storeOp, info.loadOp, true, true);
    }
    updateTopFunc(topFunction, OpBuilder(topFunction));



    std::vector<codo::BufferOp> subFuncBufferList;
    for (auto func : funcList) {
        func.walk([&](BufferOp op) {
            if (op.getStringAttr() != StringRef("non_fifo")) {
                subFuncBufferList.push_back(op);
            }
        });
    }


    std::vector<ValidBufferInfo> validSubFuncBuffers; 

    for (auto bufferop : subFuncBufferList) {
        SmallVector<AffineStoreOp, 2> associatedStores;
        SmallVector<AffineLoadOp, 2> associatedLoads;

        for (auto *user : bufferop.getResult().getUsers()) {
            if (auto store = dyn_cast<AffineStoreOp>(user)) {
                associatedStores.push_back(store);
            }
            if (auto load = dyn_cast<AffineLoadOp>(user)) {
                associatedLoads.push_back(load);
            }
        }

        if (associatedStores.size() != 1 || associatedLoads.size() != 1) {
            bufferop.setStringAttr(StringRef("non_fifo"));
        } else {
            validSubFuncBuffers.push_back({bufferop, associatedStores.front(), associatedLoads.front()});
        }
    }


    for (const auto& info : validSubFuncBuffers) {
        bool consistent = is_consistent(info.buffer, info.storeOp, info.loadOp, 0, 1);
    }

    llvm::outs() << "\n--- Final Read-Only Check for Top-level Buffers ---\n";
    std::vector<ValidBufferInfo> validTopBuffersForCheck;

    for (auto bufferop : TopFuncBufferList) {
        SmallVector<AffineStoreOp, 2> associatedStores;
        SmallVector<AffineLoadOp, 2> associatedLoads;

        for (auto *opUser : bufferop.getResult().getUsers()) {
            if (auto callOp = dyn_cast<func::CallOp>(opUser)) {
                int argIndex = -1;
                for (unsigned i = 0; i < callOp->getNumOperands(); ++i) {
                    if (callOp->getOperand(i) == bufferop.getResult()) {
                        argIndex = i;
                        break;
                    }
                }
                if (argIndex == -1) continue;
                auto callee = module.lookupSymbol<func::FuncOp>(callOp.getCallee());
                if (!callee) continue;
                Value funcArg = callee.getArgument(argIndex);

                for (auto *funcArgUser : funcArg.getUsers()) {
                    if (auto store = dyn_cast<AffineStoreOp>(funcArgUser)) associatedStores.push_back(store);
                    if (auto load = dyn_cast<AffineLoadOp>(funcArgUser)) associatedLoads.push_back(load);
                }
            }
        }

        if (associatedStores.size() == 1 && associatedLoads.size() == 1) {
            validTopBuffersForCheck.push_back({bufferop, associatedStores.front(), associatedLoads.front()});
        }
    }

    for (const auto& info : validTopBuffersForCheck) {
        bool consistent = is_consistent(info.buffer, info.storeOp, info.loadOp, 1, 0);
    }


    // ======================================
    llvm::outs() << "\n--- Final Read-Only Check for Sub-function Buffers ---\n";
    std::vector<ValidBufferInfo> validSubFuncBuffersForCheck;

    std::vector<codo::BufferOp> subFuncBufferCandidates;
    for (auto func : funcList) {
        func.walk([&](BufferOp op) {
            if (op.getStringAttr() != StringRef("non_fifo")) {
                subFuncBufferCandidates.push_back(op);
            }
        });
    }

    for (auto bufferop : subFuncBufferCandidates) {
        SmallVector<AffineStoreOp, 2> associatedStores;
        SmallVector<AffineLoadOp, 2> associatedLoads;
        for (auto *user : bufferop.getResult().getUsers()) {
            if (auto store = dyn_cast<AffineStoreOp>(user)) associatedStores.push_back(store);
            if (auto load = dyn_cast<AffineLoadOp>(user)) associatedLoads.push_back(load);
        }

        if (associatedStores.size() == 1 && associatedLoads.size() == 1) {
            validSubFuncBuffersForCheck.push_back({bufferop, associatedStores.front(), associatedLoads.front()});
        }
    }

    for (const auto& info : validSubFuncBuffersForCheck) {
        // 调用 is_consistent，isTopBuffer=0, change=false
        bool consistent = is_consistent(info.buffer, info.storeOp, info.loadOp, 0, 0);
    }

    // SubFuncBufferList.clear();
    // SubStoreOps.clear();
    // SubLoadOps.clear();
    // for(auto func:funcList)
    // {
    //     func.walk([&](BufferOp op){
    //         if(op.getStringAttr()!=StringRef("non_fifo"))
    //         SubFuncBufferList.push_back(op);
    //     });
    // }
    // for(auto bufferop:SubFuncBufferList){
    //     auto subfunc = bufferop.getOperation()->getParentOfType<func::FuncOp>();
    //     auto val = bufferop.getResult();
    //     AffineLoadOp loadop;
    //     AffineStoreOp storeop;
    //     for(auto op: val.getUsers())
    //     {
    //     if(dyn_cast<AffineLoadOp>(op)){
    //       SubLoadOps.push_back(dyn_cast<AffineLoadOp>(op));
    //     }
    //     if(dyn_cast<AffineStoreOp>(op)){
    //       SubStoreOps.push_back(dyn_cast<AffineStoreOp>(op));
    //     }
    // }
    // for(int i=0;i<TopFuncBufferList.size();i++)
    // {
    //   bool consistent = is_consistent(TopFuncBufferList[i], TopStoreOps[i], TopLoadOps[i], 1, 0);
    // }
    // for(int i=0;i<SubFuncBufferList.size();i++)
    // {
    //   bool consistent = is_consistent(SubFuncBufferList[i], SubStoreOps[i], SubLoadOps[i], 0, 0);
    // }
  }
};
};


std::unique_ptr<Pass> codo::createFIFOornotPass() {
  return std::make_unique<FIFOornot>();
}
