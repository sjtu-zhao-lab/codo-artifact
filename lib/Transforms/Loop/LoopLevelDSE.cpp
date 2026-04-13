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
#include "codo/Init_All_Dialects.h"

#include <mutex>


static std::mutex g_llvmOutsMutex;
// #define DEBUG_TYPE "codo"

using namespace mlir;
using namespace mlir::affine;
using namespace codo;

// func::FuncOp LoopDSE(func::FuncOp topfunc){
//   auto clonedfunc = func.clone();
  
// }
static void updateParentFunc(func::FuncOp func, Builder builder) {

  auto parentFunc = func.getOperation()->getParentOfType<func::FuncOp>();
  if (!parentFunc) return; 


  auto subResultTypes = func.getResultTypes();
  auto subInputTypes = func.getArgumentTypes();
  auto newType = builder.getFunctionType(subInputTypes, subResultTypes);


  if (parentFunc.getFunctionType() != newType) {
    parentFunc.setType(newType);

    unsigned index = 0;
    for (auto inputType : subInputTypes) {
      if (index < parentFunc.getNumArguments()) {
        parentFunc.getArgument(index).setType(inputType);
      }
      index++;
    }


    auto returnOp = cast<func::ReturnOp>(parentFunc.front().getTerminator());
    index = 0;
    for (auto resultType : subResultTypes) {
      if (index < returnOp.getNumOperands()) {
        returnOp.getOperand(index).setType(resultType);
      }
      index++;
    }


    updateParentFunc(parentFunc, builder);
  }
}
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

            // llvm::outs() << "\n---------------------\n" << subFunc.getName()<<"\n";
            // operand.dump();
            // operand.getType().dump();
            // mapping.second.dump();
            // subArgType.dump();``` `3 `23 `23 `23 `23 `23 `23`23 `
            // llvm::outs() << "\n";
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
            // operand.getType().dump();
            // subArgType.dump();
        }
        auto resultTypes = topFunc.front().getTerminator()->getOperandTypes();
        auto inputTypes = topFunc.front().getArgumentTypes();
        topFunc.setType(builder.getFunctionType(inputTypes, resultTypes));

    });
}
static void updateSubFuncs(func::FuncOp func, Builder builder) {
  func.walk([&](func::CallOp op) {
    auto callee = SymbolTable::lookupNearestSymbolFrom(op, op.getCalleeAttr());
    auto subFunc = dyn_cast<func::FuncOp>(callee);

    // Set sub-function type.
    auto subResultTypes = op.getResultTypes();
    auto subInputTypes = op.getOperandTypes();
    auto newType = builder.getFunctionType(subInputTypes, subResultTypes);

    if (subFunc.getFunctionType() != newType) {
      subFunc.setType(newType);

      // Set arguments type.
      unsigned index = 0;
      for (auto inputType : op.getOperandTypes())
        subFunc.getArgument(index++).setType(inputType);

      // Set results type.
      auto returnOp = cast<func::ReturnOp>(subFunc.front().getTerminator());
      index = 0;
      for (auto resultType : op.getResultTypes())
        returnOp.getOperand(index++).setType(resultType);

      // Recursively apply array partition strategy.
      updateSubFuncs(subFunc, builder);
    }
  });
}
namespace {
struct LoopLevelDSE : public LoopLevelDSEBase<LoopLevelDSE> {

  LoopLevelDSE() = default;
  LoopLevelDSE(int dseMaxLoopParallelismFactor) { 
    MaxLoopParallelismFactor = dseMaxLoopParallelismFactor;
  }
  void runOnOperation() override {
    // Collect all target loop bands.
    // AffineLoopBands targetBands;
    // getLoopBands(getOperation().front(), targetBands);
    ModuleOp module = getOperation();

    std::vector<func::FuncOp> funcList;
    std::vector<codo::BufferOp> bufferList;
    func::FuncOp topFunction;
    module.walk([&](func::FuncOp topFunc) {
    if (hasTopFuncAttr(topFunc)) { 
      topFunction = topFunc;
      topFunc.walk([&](BufferOp op) {
          bufferList.push_back(op);
      });
      // llvm::outs() << "Processing top function: " << topFunc.getName() << "\n";
        topFunc.walk([&](Operation *op) {
          if (auto callOp = dyn_cast<func::CallOp>(op)) {
            StringRef callee = callOp.getCallee();
            // llvm::outs() << "Found call to function: " << callee << "\n";
            module.lookupSymbol<func::FuncOp>(callee).walk([&](func::FuncOp childFunc) {
              funcList.push_back(childFunc);
              // llvm::outs() << "Child function: " << childFunc.getName() << "\n";
            });
          }
        });
      }
    });
    for(auto func: funcList)
    {
    auto clonedfunc = func.clone();
    SmallVector<Value> memref_func, memref_cloned;
    DenseMap<Value, SmallVector<Partition, 4>> partitionsMap;
    DenseMap<Value, Value> memrefMapping;
    for (auto arg : func.getArguments())
    {
      if (auto memrefType = arg.getType().dyn_cast<MemRefType>()) {
        memref_func.push_back(arg);
      }
    }
    func.walk([&](BufferOp bufferOp) {
      memref_func.push_back(bufferOp.getResult());
      // llvm::outs() << "Found BufferOp: " << bufferOp << "\n";
    });
    func.walk([&](Operation *op) {
      if (auto allocOp = dyn_cast<memref::AllocOp>(op)) {
        memref_func.push_back(allocOp.getResult());
        allocOp.getResult().dump();
        // llvm::outs() << "Found memref.AllocOp: " << "\n";
        // allocOp.dump();
      }
    });
    // func.walk([&](BufferOp bufferOp) {
    //   memref_func.push_back(bufferOp.getResult());
    //   // llvm::outs() << "Found BufferOp: " << bufferOp << "\n";
    // });
    for (auto arg : clonedfunc.getArguments())
    {
      if (auto memrefType = arg.getType().dyn_cast<MemRefType>()) {
        memref_cloned.push_back(arg);
      }
    }

    clonedfunc.walk([&](BufferOp bufferOp) {
      memref_cloned.push_back(bufferOp.getResult());
      // llvm::outs() << "Found BufferOp: " << bufferOp << "\n";
    });
    clonedfunc.walk([&](Operation *op) {
      if (auto allocOp = dyn_cast<memref::AllocOp>(op)) {
        memref_cloned.push_back(allocOp.getResult());
        // llvm::outs() << "Found memref.AllocOp: " << allocOp->getResult() << "\n";
      }
    });

    int balance_degree = 1;
    int downscale_degree = 0;

    func.walk([&](AffineForOp forOp) {
      // Check if the forOp is a top-level loop
      if (isa<func::FuncOp>(forOp->getParentOp())) {
        
        AffineLoopBand band;
        getLoopBandFromOutermost(forOp, band);

        SmallVector<unsigned> factors;

        for (int i = 0; i < band.size();i++)
        {
          AffineForOp innermostLoop = band[i];
          auto lowerBound = innermostLoop.getLowerBoundMap().getSingleConstantResult();
          auto upperBound = innermostLoop.getUpperBoundMap().getSingleConstantResult();
          // llvm::outs()<<"lowerBound: "<<lowerBound<<"\n";
          // llvm::outs()<<"upperBound: "<<upperBound<<"\n";
          assert(lowerBound==0 && "Lower bound must be 0!");

          unsigned factor;
          if(upperBound == 1){
            factor = 1;
          }
          for (int i = 1; i < upperBound; ++i)
          {
            if (i != upperBound && upperBound % i == 0 && i <= MaxLoopParallelismFactor)
            {
              factor = i;
              if(balance_degree!=0){
                if(upperBound>=4096 && upperBound % (i*balance_degree*32) == 0){
                  factor = factor*balance_degree*2;
                }
                else if(upperBound>=1024 && upperBound % (i*balance_degree*32) == 0){
                  factor = factor*balance_degree*2;
                }
                else if(upperBound>=32 && upperBound % (i*balance_degree*4) == 0){
                  factor = factor*balance_degree*2;
                }
              }
              // else if(upperBound>=256 && upperBound % (i*balance_degree) == 0){
              //   factor = factor*balance_degree;
              // }
              // llvm::outs()<<"factor: "<<i<<"\n";
            }
            
          }
          if(downscale_degree == 1){
            // if (upperBound % MaxLoopParallelismFactor == 0){
              if(upperBound % (MaxLoopParallelismFactor-1) == 0){
                factor = MaxLoopParallelismFactor-1;
              }
              if(upperBound % (MaxLoopParallelismFactor-2) == 0){
                factor = MaxLoopParallelismFactor-2;
              }
              if (upperBound % (MaxLoopParallelismFactor-3) == 0){
                factor = MaxLoopParallelismFactor-3;
              }
              
            // }
          }
          factors.push_back(factor);
        }
        
        // band[0] = innermostLoop;
        // band.resize(1);
        // SmallVector<unsigned, 8> tileList({factors.back()});


        // SmallVector<unsigned, 8> tileList(factors);
        AffineLoopBand tiledBand;

        // std::unique_lock<std::mutex> lock(g_llvmOutsMutex);

        tilePerfectlyNested(band, factors, &tiledBand);
        

        for(auto forloop:tiledBand){(void)normalizeAffineFor(forloop);}
        // (void)normalizeAffineFor(tiledBand[0]);
        // (void)normalizeAffineFor(tiledBand[1]);
        // (void)normalizeAffineFor(tiledBand[2]);
        // sinkSequentialLoops(band[0]);
        
        
        // applyLoopPipelining(tiledBand,2,1);
        setLoopDirective(tiledBand[tiledBand.size() / 2 - 1], true, 1, false, false);
      }
    });


    clonedfunc.walk([&](AffineForOp forOp) {
      // Check if the forOp is a top-level loop
      if (isa<func::FuncOp>(forOp->getParentOp())) {
        
        AffineLoopBand band;
        getLoopBandFromOutermost(forOp, band);

        SmallVector<unsigned> factors;

        for (int i = 0; i < band.size();i++)
        {
          AffineForOp innermostLoop = band[i];
          auto lowerBound = innermostLoop.getLowerBoundMap().getSingleConstantResult();
          auto upperBound = innermostLoop.getUpperBoundMap().getSingleConstantResult();
          // llvm::outs()<<"lowerBound: "<<lowerBound<<"\n";
          // llvm::outs()<<"upperBound: "<<upperBound<<"\n";
          assert(lowerBound==0 && "Lower bound must be 0!");

          unsigned factor;
          if(upperBound == 1){
            factor = 1;
          }
          for (int i = 1; i < upperBound; ++i)
          {
            if (i != upperBound && upperBound % i == 0 && i <= MaxLoopParallelismFactor)
            {
              factor = i;
              if(balance_degree!=0){
                if(upperBound>=4096 && upperBound % (i*balance_degree*32) == 0){
                  factor = factor*balance_degree*2;
                }
                else if(upperBound>=1024 && upperBound % (i*balance_degree*32) == 0){
                  factor = factor*balance_degree*2;
                }
                else if(upperBound>=32 && upperBound % (i*balance_degree*4) == 0){
                  factor = factor*balance_degree*2;
                }
              }
              // else if(upperBound>=256 && upperBound % (i*balance_degree) == 0){
              //   factor = factor*balance_degree;
              // }
              // llvm::outs()<<"factor: "<<i<<"\n";
            }
          }
          if(downscale_degree == 1){
            // if (upperBound % MaxLoopParallelismFactor == 0){
              if(upperBound % (MaxLoopParallelismFactor-1) == 0){
                factor = MaxLoopParallelismFactor-1;
              }
              if(upperBound % (MaxLoopParallelismFactor-2) == 0){
                factor = MaxLoopParallelismFactor-2;
              }if (upperBound % (MaxLoopParallelismFactor-3) == 0){
                factor = MaxLoopParallelismFactor-3;
              }
              
            // }
          }
          factors.push_back(factor);
        }
        
        AffineLoopBand tiledBand;


        tilePerfectlyNested(band, factors, &tiledBand);
        

        for(auto forloop:tiledBand){(void)normalizeAffineFor(forloop);}
        
        
        // applyLoopPipelining(tiledBand,2,1);
        setLoopDirective(tiledBand[tiledBand.size() / 2 - 1], true, 1, false, false);
        // applyLoopPipelining(tiledBand,tiledBand.size() / 2 - 1,1);
        applyFullyLoopUnrolling(*tiledBand[tiledBand.size() / 2 - 1].getBody());
        // clonedfunc.dump();
        // llvm::outs()<<"\n-------------------------\n";
        
        // llvm::outs()<<"\n------------111-------------\n";
      
        
      }
    });
    // llvm::outs()<<"\n------------111-------------\n";
    applyAutoArrayPartition(clonedfunc, partitionsMap, 1024);


    // llvm::outs()<<"\n------------111-------------\n";
      
      
    for (size_t i = 0; i < memref_func.size(); ++i) {
              Value originalMemRef = memref_func[i];
              Value clonedMemRef = memref_cloned[i];
              memrefMapping[clonedMemRef] = originalMemRef;
              // originalMemRef.dump();
              // clonedMemRef.dump();
              // llvm::outs()<<"\n********\n";
    }
    // llvm::outs()<<"\n--------------222-----------\n";
    auto builder = Builder(func);
    for (auto [memref, partitions] : partitionsMap) {
      SmallVector<PartitionKind, 4> kinds;
      SmallVector<unsigned, 4> factors;
      for (auto [kind, factor] : partitions) {
        kinds.push_back(kind);
        if(factor>=96){
          factor = 32;
        }
        factors.push_back(factor);
      }
      if (llvm::any_of(kinds, [](PartitionKind kind) {
            return kind != PartitionKind::NONE;
          }))
      { 
        // memref.dump();
        // memrefMapping[memref].dump();
        // llvm::outs()<<factors.size()<<"    "<<kinds.size()<<"\n";
        if(memrefMapping[memref])
        {applyArrayPartition(memrefMapping[memref], factors, kinds, false, 1024);}
      }
    }
    // llvm::outs()<<"\n------------333-------------\n";
  if(!hasTopFuncAttr(func)){
    auto resultTypes = func.front().getTerminator()->getOperandTypes();
    auto inputTypes = clonedfunc.front().getArgumentTypes();
    func.setType(builder.getFunctionType(inputTypes, resultTypes));
    // updateParentFunc(func, builder);
  }}
  // llvm::outs()<<"\n-----------444--------------\n";


  topFunction.walk([&](BufferOp fifo_buffer){
    auto fifo_value = fifo_buffer.getResult();
    auto fifo_memref = fifo_value.getType().cast<MemRefType>(); 
    SmallVector<func::CallOp> users;
    for(auto user: fifo_value.getUsers()){if(dyn_cast<func::CallOp>(user)){
        users.push_back(dyn_cast<func::CallOp>(user));
      }
    }
    if(users.size() != 2){return WalkResult::advance();}

    auto callOp1 = users[0];
    auto callOp2 = users[1];

    auto callee1 = SymbolTable::lookupNearestSymbolFrom(callOp1, callOp1.getCalleeAttr());
    auto subFunc1 = dyn_cast<func::FuncOp>(callee1);
    auto callee2 = SymbolTable::lookupNearestSymbolFrom(callOp2, callOp2.getCalleeAttr());
    auto subFunc2 = dyn_cast<func::FuncOp>(callee2);



    int index1, index2;
    for (unsigned index = 0; index < callOp1.getNumOperands(); ++index)
    {
      auto operand = callOp1.getOperand(index);
      // operand.dump();
      // operand.getType().dump();
      // llvm::outs()<<"\n--------------\n";
      if(operand == fifo_value){
        index1 = index;
        break;
      }
      // auto subArg = subFunc.getArgument(index);
      // argMapping[operand] = subArg;
    }
    for (unsigned index = 0; index < callOp2.getNumOperands(); ++index)
    {
      auto operand = callOp2.getOperand(index);
      if(operand == fifo_value){
        index2 = index;
        break;
      }
    }
    MemRefType final_type;
    SmallVector<unsigned> final_factors;
    SmallVector<codo::PartitionKind> final_kinds;

    // llvm::outs()<<"\n-----------555--------------\n";

    auto attr1 = subFunc1.getArgument(index1).getType().dyn_cast<MemRefType>().getLayout().dyn_cast<PartitionLayoutAttr>();
    auto attr2 = subFunc2.getArgument(index2).getType().dyn_cast<MemRefType>().getLayout().dyn_cast<PartitionLayoutAttr>();

    if (attr1 || attr2) {
      // llvm::outs()<<"\n-----------21323--------------\n";
    



    SmallVector<int64_t> factors1(attr1.getFactors());
    SmallVector<int64_t> factors2(attr2.getFactors());
    SmallVector<codo::PartitionKind> kinds1(attr1.getKinds());
    SmallVector<codo::PartitionKind> kinds2(attr2.getKinds());

    assert(factors1.size() == factors2.size());

    for(int i=0;i<factors1.size();i++)
    {
      auto factor1 = factors1[i];
      auto factor2 = factors2[i];
      if(factor1 > factor2){final_factors.push_back(factor1);final_kinds.push_back(kinds1[i]);}
      else{final_factors.push_back(factor2);final_kinds.push_back(kinds2[i]);}
    }

    llvm::outs() << "Identify tilable buffers and dims:\n";
    // func.dump();
    // llvm::outs() << "After BufferizeDataflow Pass:\n";
    subFunc1.getArgument(index1).dump();
    subFunc2.getArgument(index2).dump();
    fifo_value.dump();
    // llvm::outs()<<"\n----------------------\n";
    // llvm::outs()<<"\n-----------666--------------\n";
    applyArrayPartition(subFunc1.getArgument(index1), final_factors, final_kinds, false, 1024);
    applyArrayPartition(subFunc2.getArgument(index2), final_factors, final_kinds, false, 1024);
    applyArrayPartition(fifo_value, final_factors, final_kinds, false, 1024);
    // llvm::outs()<<"\n-----------777--------------\n";

    auto builder1 = Builder(subFunc1);
    auto resultTypes1 = subFunc1.front().getTerminator()->getOperandTypes();
    auto inputTypes1 = subFunc1.front().getArgumentTypes();
    subFunc1.setType(builder1.getFunctionType(inputTypes1, resultTypes1));

    auto builder2 = Builder(subFunc2);
    auto resultTypes2 = subFunc2.front().getTerminator()->getOperandTypes();
    auto inputTypes2 = subFunc2.front().getArgumentTypes();
    subFunc2.setType(builder2.getFunctionType(inputTypes2, resultTypes2));

    }
  }
);




auto builder = Builder(topFunction);
updateTopFunc(topFunction, builder);
  



    // func.dump();
  // module.dump();
  }
};
} // namespace

std::unique_ptr<Pass> codo::createLoopLevelDSEPass(int dseMaxLoopParallelismFactor) {
  return std::make_unique<LoopLevelDSE>(dseMaxLoopParallelismFactor);
}