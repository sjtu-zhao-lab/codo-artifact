//===----------------------------------------------------------------------===//
//
// Copyright 2020-2021 The codo Authors.
//
//===----------------------------------------------------------------------===//

#include "mlir/Dialect/Affine/Analysis/LoopAnalysis.h"
#include "mlir/Dialect/Affine/Analysis/Utils.h"
#include "mlir/Support/FileUtilities.h"
#include "mlir/Dialect/Affine/LoopUtils.h"
#include "mlir/Dialect/Affine/Utils.h"
#include "codo/Support/Explorer.h"
#include "codo/Support/Estimator.h"
#include "codo/Transforms/Passes.h"
#include "codo/Init_All_Dialects.h"
// #include "llvm/Support/Debug.h"
#include "llvm/Support/MemoryBuffer.h"
#include "llvm/Support/ToolOutputFile.h"
#include <numeric>
// #include <pthread.h>

#define DEBUG_TYPE "codo"

using namespace mlir;
using namespace mlir::affine;
using namespace codo;

// llvm::DenseMap<func::FuncOp, SmallVector<FuncDependency, 4>> producerToConsumers;
// llvm::DenseMap<func::FuncOp, SmallVector<FuncDependency, 4>> consumerToProducers;


namespace {
struct StreamOpt : public StreamOptBase<StreamOpt> {
  StreamOpt() = default;

  void runOnOperation() override {
    auto module = getOperation();
    // TODO: Node FIFO Read-Write Balance
    std::vector<func::FuncOp> funcList;
    std::vector<codo::BufferOp> bufferList;
    // for (auto func : module.getOps<func::FuncOp>()) {
    //   if(!hasTopFuncAttr(func))
    //     funcList.push_back(func);
    //   else{
    //       for (auto op : func.getOps<BufferOp>()) {
    //          bufferList.push_back(op);
    //       }
    //   }
    // }
    // module.walk([&](func::FuncOp func) {
    // if (!hasTopFuncAttr(func)) {
    //     funcList.push_back(func);
    // } else {
    //     // 对 func 内部的所有 BufferOp 使用 walk 遍历
    //     func.walk([&](BufferOp op) {
    //         bufferList.push_back(op);
    //     });
    //   }
    // });
    module.walk([&](func::FuncOp topFunc) {
    if (hasTopFuncAttr(topFunc)) { 
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
              if (!childFunc->hasAttrOfType<UnitAttr>("conv_node")) {
                // TODO: Fine-grained Conflict detection between Loops
                childFunc.walk([&](BufferOp op) {
                  op.setStringAttr(StringRef("non_fifo"));
                    // bufferList.push_back(op);
                });
              }
              // llvm::outs() << "Child function: " << childFunc.getName() << "\n";
            });
          }
        });
      }
    });


    // std::reverse(funcList.begin(), funcList.end());
    llvm::outs() << "Function list size" << funcList.size()<<"\n";
    
    llvm::DenseMap<func::FuncOp, SmallVector<func::FuncOp, 4>> funcToDeps;
    llvm::DenseMap<func::FuncOp, SmallVector<func::FuncOp, 4>> depsToFunc;
    for (size_t i = 0; i < funcList.size(); ++i) {
      auto func = funcList[i];
      llvm::outs()<< "Function name: " << func.getName()
                                <<"\n";
      // if (func->hasAttrOfType<UnitAttr>("conv_node")) {
        for (size_t j = i + 1; j < funcList.size(); ++j) {
          auto nextFunc = funcList[j];
          for(auto buffer: bufferList){
            for (auto *user : buffer.getResult().getUsers()) {
              if (auto callOp = llvm::dyn_cast<mlir::func::CallOp>(user)) {
                auto callee = SymbolTable::lookupNearestSymbolFrom(callOp, callOp.getCalleeAttr());
                auto subFunc = dyn_cast<func::FuncOp>(callee);
                // Check if the current func is the callee
                if (subFunc == func) {
                  // Iterate over all other users of the buffer and create a mapping.
                  for (auto *otherUser : buffer.getResult().getUsers()) {
                    if (otherUser != user) { 
                      if (auto otherCallOp = llvm::dyn_cast<mlir::func::CallOp>(otherUser)) {
                        auto otherCallee = SymbolTable::lookupNearestSymbolFrom(otherCallOp, otherCallOp.getCalleeAttr());
                        auto otherSubFunc = dyn_cast<func::FuncOp>(otherCallee);
                        if(otherSubFunc==nextFunc){
                          // if(otherSubFunc.getOperation()->hasAttrOfType<UnitAttr>("unbalanced"))
                            // buffer.setStringAttr(StringRef("non_fifo"));
                          if(!func->hasAttrOfType<UnitAttr>("conv_node") && !otherSubFunc->hasAttrOfType<UnitAttr>("conv_node"))
                            buffer.setStringAttr(StringRef("non_fifo"));
                          funcToDeps[func].push_back(otherSubFunc);
                          depsToFunc[otherSubFunc].push_back(func);
                          // llvm::outs()<< "Function " << nextFunc.getName()
                          //       << " is dependent on " << func.getName() 
                          //       << "\n";
                          // FIXME: Add an assertion
                          int producerIndex = -1;
                          int consumerIndex = -1;
                          for (unsigned index = 0; index < callOp.getNumOperands(); ++index) {
                            auto operand = callOp.getOperand(index);
                            if(buffer.getResult()==operand){
                              producerIndex = index;
                              // llvm::outs()<<"find the producer target value at index "<<index<<"\n";
                            }
                          }
                          for (unsigned index = 0; index < otherCallOp.getNumOperands(); ++index) {
                            auto operand = otherCallOp.getOperand(index);
                            if(buffer.getResult()==operand){
                              consumerIndex = index;
                              // llvm::outs()<<"find the consumer target value at index "<<index<<"\n";
                            }
                          }
                          assert(producerIndex >= 0 && "Producer index should be valid");
                          assert(consumerIndex >= 0 && "Consumer index should be valid");
                          producerToConsumers[func].push_back({nextFunc, producerIndex, consumerIndex});
                        }
                        
                      }
                    }   
                  }
                }
              }
            }
          }   
        }
      // }
    }

    for (const auto &entry : producerToConsumers) {
      func::FuncOp producerFunc = entry.first;
      // if (producerFunc->hasAttrOfType<UnitAttr>("conv_node")) {
        for (const auto &dependency : entry.second) {
          func::FuncOp consumerFunc = dependency.consumer;
          int producerIndex = dependency.producerArgIndex;
          int consumerIndex = dependency.consumerArgIndex;
          auto producerArg = producerFunc.getArgument(producerIndex);
          // llvm::outs()<<producerArg<<"\n";
          auto consumerArg = consumerFunc.getArgument(consumerIndex);

          // find the store operation in the producer argument list
          std::map<int, std::vector<int>> producerRankMap;
         
          // std::vector<int> consumerRanks;
          mlir::affine::AffineForOp  proFor;
          producerFunc.walk([&](AffineStoreOp op) {
            if (auto storeOp = llvm::dyn_cast<mlir::affine::AffineStoreOp>(&op)) {
              // 找到 store 操作的目标
              auto target = storeOp->getMemRef();
              // llvm::outs()<<target<<"\n";
              if (target == producerArg) {
                auto currentOp = storeOp->getOperation();
                auto topLevelFor = currentOp->getParentOfType<mlir::affine::AffineForOp>();
                while (topLevelFor) {
                  auto parentFor = topLevelFor->getParentOfType<mlir::affine::AffineForOp>();
                  if (!parentFor) {
                      break;
                  }
                  topLevelFor = parentFor;
                   proFor = topLevelFor;
                  
                }
                if (topLevelFor) {
                  std::vector<int> loopdepth;
                  auto indices = storeOp->getIndices();
                  // FIXME: We need a function to analysis indics like in the consumerFunc part
                  for (auto operand : indices) { 
                    int level = 0;
                    topLevelFor.walk([&](affine::AffineForOp op) {
                        level+=1;
                        auto inductionVar = op.getInductionVar();
                        if (operand == inductionVar) {
                            // llvm::outs() << "Found matching induction variable: " << inductionVar << "\n";
                            loopdepth.push_back(level);
                        }
                    });
                  }

                  // std::vector<std::pair<int, int>> indexedArr(loopdepth.size());
                  // for (int i = 0; i < loopdepth.size(); ++i) {
                  //     indexedArr[i] = {loopdepth[i], i}; 
                  //     llvm::outs()<<"index: "<<loopdepth[i]<<"\n";
                  // }
                  std::vector<int> indices1(loopdepth.size());
                  for (int i = 0; i < loopdepth.size(); ++i) {
                      indices1[i] = i; // 填充索引
                  }
                  std::sort(indices1.begin(), indices1.end(), [&](int a, int b) {
                      return loopdepth[a] > loopdepth[b]; // 从大到小排序
                  });
                  std::vector<int> indexOrder(loopdepth.size());
                  for (int i = 0; i < loopdepth.size(); ++i) {
                      indexOrder[indices1[i]] = i; // 填充原数组位置的大小次序
                  }
                  // for (int i = 0; i < loopdepth.size(); ++i) {
                  //     llvm::outs()<<"indexedArr: "<<indexOrder[i]<<"\n";
                  // }
                  // std::sort(indexedArr.begin(), indexedArr.end(), [](const auto& a, const auto& b) {
                  //     return a.first > b.first; 
                  // });
                  // std::vector<int> ranks(loopdepth.size());
                  // for (int i = 0; i < loopdepth.size(); ++i) {
                  //     ranks[i] = indexedArr[i].second ; 
                  //     llvm::outs()<<"indexedArr: "<<ranks[i]<<"\n";
                  // }
                  for (int i = 0; i < indexOrder.size(); ++i) {
                    producerRankMap[i].push_back(indexOrder[i]);
                  }
                  // for (int key = 0; key < producerRankMap.size(); ++key) {
                  //   llvm::outs() << "Key: " << key << " -> Values: ";
                  //   for (int value : producerRankMap[key]) {
                  //       llvm::outs()  << value << " ";
                  //   }
                  //   llvm::outs()  << "\n";
                  // }
                  return WalkResult::interrupt();
                }
              }
              
            }
            
          });
          
          // Consumer index access order
          std::map<int, std::vector<int>> consumerRankMap;
          consumerFunc.walk([&](AffineLoadOp op) {
            if (auto loadOp = llvm::dyn_cast<mlir::affine::AffineLoadOp>(&op)) {
              // 找到 store 操作的目标
              auto target = loadOp->getMemRef();
              // llvm::outs()<<target<<"\n";
              if (target == consumerArg) {
                auto currentOp = loadOp->getOperation();
                auto topLevelFor = currentOp->getParentOfType<mlir::affine::AffineForOp>();
                while (topLevelFor) {
                  auto parentFor = topLevelFor->getParentOfType<mlir::affine::AffineForOp>();
                  if (!parentFor) {
                      break;
                  }
                  topLevelFor = parentFor;
                }
                if (topLevelFor) {
                  std::vector<int> loopdepth;
                  auto indices = loadOp->getIndices();
                  auto affineMap = loadOp->getAffineMap();
                  auto exprs = loadOp->getAffineMap().getResults();
                  int indexDims = exprs.size();
                  std::vector<int> numberOfArgs(indexDims, 0);
                  
                  for (int dimIndex=0; dimIndex<indexDims; dimIndex++) {
                    // FIXME:Encapsulate the following code in a function
                    if (auto dimExpr = exprs[dimIndex].dyn_cast<AffineDimExpr>()) {
                      unsigned dimPosition = dimExpr.getPosition();
                      numberOfArgs[dimIndex]=1;
                    }else if (auto dimExpr = exprs[dimIndex].dyn_cast<AffineConstantExpr>()) {
                      // unsigned dimPosition = dimExpr.getPosition();
                      numberOfArgs[dimIndex]=1;
                    }
                    else if(auto dimExpr = exprs[dimIndex].dyn_cast<AffineBinaryOpExpr>()){
                      // TODO:This method needs extension, it should be a recursive function
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
                  // llvm::outs() << "indices size: " << indices.size() << "\n";
                  // llvm::outs() << "affinemap size: " << affineMap.getNumResults() << "\n";
                  // FIXME: This case indicates that there is a "0" index
                  if(indices.size()<affineMap.getNumResults()){
                      loopdepth.push_back(20);
                  }

                  for (auto operand : indices) {
                    int level = 0;
                    topLevelFor.walk([&](affine::AffineForOp op) {
                        level+=1;
                        auto inductionVar = op.getInductionVar();
                        if (operand == inductionVar) {
                            
                            loopdepth.push_back(level);
                        }
                        // else if(operand.getDefiningOp() == 0){
                        //   llvm::outs() << "Found matching induction variable: " << inductionVar << "\n";
                        //   // Else it is a "0", Normally the batch size dim
                        //   loopdepth.push_back(20);
                        //   return WalkResult::interrupt();
                        // }
                        // llvm::outs() << "Found matching induction variable: " << operand.getDefiningOp() << "\n";
                    });
                  }

                  std::vector<int> indices2(loopdepth.size());
                  for (int i = 0; i < loopdepth.size(); ++i) {
                      indices2[i] = i; // 
                  }
                  std::sort(indices2.begin(), indices2.end(), [&](int a, int b) {
                      return loopdepth[a] > loopdepth[b]; //
                  });
                  std::vector<int> indexOrder2(loopdepth.size());
                  for (int i = 0; i < loopdepth.size(); ++i) {
                      indexOrder2[indices2[i]] = i; // 
                  }
                  // for (int i = 0; i < loopdepth.size(); ++i) {
                  //     llvm::outs()<<"indexedArr: "<<indexOrder2[i]<<"\n";
                  // }
                  // llvm::outs()<<"numberOfArgs.size(): "<<numberOfArgs.size()<<"\n";
                  int currentIndex = 0; 
                  for (int key = 0; key < numberOfArgs.size(); ++key) {
                      int count = numberOfArgs[key]; 
                      for (int i = 0; i < count && currentIndex < indexOrder2.size(); ++i) {
                          consumerRankMap[key].push_back(indexOrder2[currentIndex]);
                          currentIndex++;
                      }
                  }
                  // for (int key = 0; key < consumerRankMap.size(); ++key) {
                  //   llvm::outs() << "Key: " << key << " -> Values: ";
                  //   for (int value : consumerRankMap[key]) {
                  //       llvm::outs()  << value << " ";
                  //   }
                  //   llvm::outs()  << "\n";
                  // }
                  
                  
                  std::map<int, bool> opted;
                  int optSize=0;
                  int bias = 0;
                  int counter = 0;
                  while(optSize<producerRankMap.size()){
                    // llvm::outs()<<"iteration: "  << "\n";
                    for(int key = 0; key < producerRankMap.size(); ++key){
                    // We assume producerRankMap.second.size()==1
                      // assert(producerRankMap[key].size()==1 && "producerRankMap.second.size() is not 1!");
                      
                      if(opted[key]!=true){
                        for (int value : producerRankMap[key]) {
                          
                          // FIXME:Currently we only support small dims mapping to the same or larger dims
                            if(value==counter){
                              // llvm::outs()<<"value: "<<value<< "\n";
                              int cuIndex = 0;
                              int count = numberOfArgs[key]; 
                              // llvm::outs()<<"count: "<<count<< "\n";
                              producerRankMap[key].clear();
                              producerRankMap[key].push_back(value+bias);
                              // llvm::outs()<<"value+bias: "<<value+bias<< "\n";
                              for (int i = 0; i < count-1; ++i) {
                                  producerRankMap[key].push_back(value+bias+i+1);
                                  currentIndex++;
                                  
                              }
                              bias+=count-1;
                              counter++; 
                              opted[key]=true;
                             
                              optSize+=1;
                              break;
                            }  
                        }
                      }
                    }
                    
                    // // optSize = opted.size();
                    // llvm::outs()<<"optSize: "<<optSize  << "\n";
                    // llvm::outs()<<"counter: "<<counter  << "\n";
                  }
                  std::vector<int> targetOrder;
                  std::vector<int> currentOrder;
                  std::map<int, int> permMap;
                  std::map<int, int> rePermMap;
                  SmallVector<unsigned, 6> targetPerm;
                  SmallVector<unsigned, 6> targetRePerm;
                  
                  for (int key = 0; key < producerRankMap.size(); ++key) {
                    // llvm::outs() << "Key: " << key << " -> Values: ";
                    for (int value : producerRankMap[key]) {
                        targetOrder.push_back(value);
                        // llvm::outs()  << value << " ";
                    }
                    // llvm::outs()  << "\n";

                  }

                  for (int key = 0; key < consumerRankMap.size(); ++key) {
                    // llvm::outs() << "Key: " << key << " -> Values: ";
                    for (int value : consumerRankMap[key]) {
                        currentOrder.push_back(value);
                        // llvm::outs()  << value << " ";
                    }
                    // llvm::outs()  << "\n";

                  }
                  

                                      
                  for(int i=0; i<targetOrder.size(); i++){
                    permMap[currentOrder[i]]=targetOrder[i];
                    rePermMap[targetOrder[i]]=currentOrder[i];
                  }
                  for (int key = 0; key < permMap.size(); ++key) {
                    // llvm::outs() << "Key: " << key << " -> Values: ";
                    // for (int value : permMap[key]) {
                    targetPerm.push_back(permMap[key]);
                    targetRePerm.push_back(rePermMap[key]);
                    // llvm::outs() << permMap[key] << "\n";
                    // llvm::outs() << rePermMap[key] << "\n";
                    // }
                  }

                  // SmallVector<unsigned, 6> permMap = {0,5,3,1,2,4};
                  // SmallVector<unsigned, 6> permMap = {0,1,3,2,4,5};
                  AffineLoopBand band;
                  if(producerFunc->hasAttrOfType<UnitAttr>("conv_node")&&!consumerFunc->hasAttrOfType<UnitAttr>("conv_node")){
                      topLevelFor.getOperation()->setAttr("conv_guided_opt", UnitAttr::get(topLevelFor->getContext()));
                      getLoopBandFromOutermost(topLevelFor, band);
                      permuteLoops(band, targetPerm);
                  }
                  if(!producerFunc->hasAttrOfType<UnitAttr>("conv_node")&&consumerFunc->hasAttrOfType<UnitAttr>("conv_node")){
                      // llvm::outs()<<"func name:"<<producerFunc.getName()<<"\n";
                      // llvm::outs()<<"func name:"<<consumerFunc.getName()<<"\n";
                       proFor.getOperation()->setAttr("conv_guided_opt", UnitAttr::get( proFor->getContext()));
                      getLoopBandFromOutermost( proFor, band);
                      // band[0].dump();
                      // SmallVector<unsigned, 6> permMap2 = {3,0,1,2};
                      permuteLoops(band, targetRePerm);
                  }
                  // if(!producerFunc->hasAttrOfType<UnitAttr>("conv_node")&&!consumerFunc->hasAttrOfType<UnitAttr>("conv_node")){
                  //     getLoopBandFromOutermost(topLevelFor, band);
                  //     band[0].dump();
                  //     // permuteLoops(band, targetPerm);
                  // }
                  
                  // forOp.dump();
                  
                  // permuteLoops(band, targetPerm);
                  // band[0].dump();
                  return WalkResult::interrupt();
                }
              }
            }
          });
          
        }
      // }
    }

    for (const auto &entry : producerToConsumers) {
      func::FuncOp producerFunc = entry.first;
      // if (producerFunc->hasAttrOfType<UnitAttr>("conv_node")) {
        for (const auto &dependency : entry.second) {
          func::FuncOp consumerFunc = dependency.consumer;
          int producerIndex = dependency.producerArgIndex;
          int consumerIndex = dependency.consumerArgIndex;
          auto producerArg = producerFunc.getArgument(producerIndex);
          // llvm::outs()<<producerArg<<"\n";
          auto consumerArg = consumerFunc.getArgument(consumerIndex);

          // find the store operation in the producer argument list
          std::map<int, std::vector<int>> producerRankMap;
         
          // std::vector<int> consumerRanks;
          mlir::affine::AffineForOp  proFor;
          producerFunc.walk([&](AffineStoreOp op) {
            if (auto storeOp = llvm::dyn_cast<mlir::affine::AffineStoreOp>(&op)) {
              auto target = storeOp->getMemRef();
              // llvm::outs()<<target<<"\n";
              if (target == producerArg) {
                auto currentOp = storeOp->getOperation();
                auto topLevelFor = currentOp->getParentOfType<mlir::affine::AffineForOp>();
                while (topLevelFor) {
                  auto parentFor = topLevelFor->getParentOfType<mlir::affine::AffineForOp>();
                  if (!parentFor) {
                      break;
                  }
                  topLevelFor = parentFor;
                   proFor = topLevelFor;
                  
                }
                if (topLevelFor) {
                  std::vector<int> loopdepth;
                  auto indices = storeOp->getIndices();
                  // FIXME: We need a function to analysis indics like in the consumerFunc part
                  for (auto operand : indices) { 
                    int level = 0;
                    topLevelFor.walk([&](affine::AffineForOp op) {
                        level+=1;
                        auto inductionVar = op.getInductionVar();
                        if (operand == inductionVar) {
                            // llvm::outs() << "Found matching induction variable: " << inductionVar << "\n";
                            loopdepth.push_back(level);
                        }
                    });
                  }

                  // std::vector<std::pair<int, int>> indexedArr(loopdepth.size());

                  std::vector<int> indices1(loopdepth.size());
                  for (int i = 0; i < loopdepth.size(); ++i) {
                      indices1[i] = i; // 
                  }
                  std::sort(indices1.begin(), indices1.end(), [&](int a, int b) {
                      return loopdepth[a] > loopdepth[b]; // 
                  });
                  std::vector<int> indexOrder(loopdepth.size());
                  for (int i = 0; i < loopdepth.size(); ++i) {
                      indexOrder[indices1[i]] = i; // 
                  }
                  // for (int i = 0; i < loopdepth.size(); ++i) {
                  //     llvm::outs()<<"indexedArr: "<<indexOrder[i]<<"\n";
                  // }
                  // std::sort(indexedArr.begin(), indexedArr.end(), [](const auto& a, const auto& b) {
                  //     return a.first > b.first; 
                  // });
                  // std::vector<int> ranks(loopdepth.size());
                  // for (int i = 0; i < loopdepth.size(); ++i) {
                  //     ranks[i] = indexedArr[i].second ; 
                  //     llvm::outs()<<"indexedArr: "<<ranks[i]<<"\n";
                  // }
                  for (int i = 0; i < indexOrder.size(); ++i) {
                    producerRankMap[i].push_back(indexOrder[i]);
                  }
                  // for (int key = 0; key < producerRankMap.size(); ++key) {
                  //   llvm::outs() << "Key: " << key << " -> Values: ";
                  //   for (int value : producerRankMap[key]) {
                  //       llvm::outs()  << value << " ";
                  //   }
                  //   llvm::outs()  << "\n";
                  // }
                  return WalkResult::interrupt();
                }
              }
              
            }
            
          });
          
          // Consumer index access order
          std::map<int, std::vector<int>> consumerRankMap;
          consumerFunc.walk([&](AffineLoadOp op) {
            if (auto loadOp = llvm::dyn_cast<mlir::affine::AffineLoadOp>(&op)) {
              auto target = loadOp->getMemRef();
              // llvm::outs()<<target<<"\n";
              if (target == consumerArg) {
                auto currentOp = loadOp->getOperation();
                auto topLevelFor = currentOp->getParentOfType<mlir::affine::AffineForOp>();
                while (topLevelFor) {
                  auto parentFor = topLevelFor->getParentOfType<mlir::affine::AffineForOp>();
                  if (!parentFor) {
                      break;
                  }
                  topLevelFor = parentFor;
                }
                if (topLevelFor) {
                  std::vector<int> loopdepth;
                  auto indices = loadOp->getIndices();
                  auto affineMap = loadOp->getAffineMap();
                  auto exprs = loadOp->getAffineMap().getResults();
                  int indexDims = exprs.size();
                  std::vector<int> numberOfArgs(indexDims, 0);
                  
                  for (int dimIndex=0; dimIndex<indexDims; dimIndex++) {
                    // FIXME:Encapsulate the following code in a function
                    if (auto dimExpr = exprs[dimIndex].dyn_cast<AffineDimExpr>()) {
                      unsigned dimPosition = dimExpr.getPosition();
                      numberOfArgs[dimIndex]=1;
                    }else if (auto dimExpr = exprs[dimIndex].dyn_cast<AffineConstantExpr>()) {
                      // unsigned dimPosition = dimExpr.getPosition();
                      numberOfArgs[dimIndex]=1;
                    }
                    else if(auto dimExpr = exprs[dimIndex].dyn_cast<AffineBinaryOpExpr>()){
                      // TODO:This method needs extension, it should be a recursive function
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
                  // llvm::outs() << "indices size: " << indices.size() << "\n";
                  // llvm::outs() << "affinemap size: " << affineMap.getNumResults() << "\n";
                  // FIXME: This case indicates that there is a "0" index
                  if(indices.size()<affineMap.getNumResults()){
                      loopdepth.push_back(65536);
                  }

                  for (auto operand : indices) {
                    int level = 0;
                    topLevelFor.walk([&](affine::AffineForOp op) {
                        level+=1;
                        auto inductionVar = op.getInductionVar();
                        if (operand == inductionVar) {
                            
                            loopdepth.push_back(level);
                        }
                        // else if(operand.getDefiningOp() == 0){
                        //   llvm::outs() << "Found matching induction variable: " << inductionVar << "\n";
                        //   // Else it is a "0", Normally the batch size dim
                        //   loopdepth.push_back(20);
                        //   return WalkResult::interrupt();
                        // }
                        // llvm::outs() << "Found matching induction variable: " << operand.getDefiningOp() << "\n";
                    });
                  }

                  
                  

                  std::vector<int> indices2(loopdepth.size());
                  for (int i = 0; i < loopdepth.size(); ++i) {
                      indices2[i] = i; 
                  }
                  std::sort(indices2.begin(), indices2.end(), [&](int a, int b) {
                      return loopdepth[a] > loopdepth[b]; 
                  });
                  std::vector<int> indexOrder2(loopdepth.size());
                  for (int i = 0; i < loopdepth.size(); ++i) {
                      indexOrder2[indices2[i]] = i; 
                  }
    
                  // llvm::outs()<<"numberOfArgs.size(): "<<numberOfArgs.size()<<"\n";
                  int currentIndex = 0; 
                  for (int key = 0; key < numberOfArgs.size(); ++key) {
                      int count = numberOfArgs[key]; 
                      for (int i = 0; i < count && currentIndex < indexOrder2.size(); ++i) {
                          consumerRankMap[key].push_back(indexOrder2[currentIndex]);
                          currentIndex++;
                      }
                  }
                  // for (int key = 0; key < consumerRankMap.size(); ++key) {
                  //   llvm::outs() << "Key: " << key << " -> Values: ";
                  //   for (int value : consumerRankMap[key]) {
                  //       llvm::outs()  << value << " ";
                  //   }
                  //   llvm::outs()  << "\n";
                  // }
                  
                  
                  std::map<int, bool> opted;
                  int optSize=0;
                  int bias = 0;
                  int counter = 0;
                  while(optSize<producerRankMap.size()){
                    // llvm::outs()<<"iteration: "  << "\n";
                    for(int key = 0; key < producerRankMap.size(); ++key){
                    // We assume producerRankMap.second.size()==1
                      // assert(producerRankMap[key].size()==1 && "producerRankMap.second.size() is not 1!");
                      
                      if(opted[key]!=true){
                        for (int value : producerRankMap[key]) {
                          
                          // FIXME:Currently we only support small dims mapping to the same or larger dims
                            if(value==counter){
                              // llvm::outs()<<"value: "<<value<< "\n";
                              int cuIndex = 0;
                              int count = numberOfArgs[key]; 
                              // llvm::outs()<<"count: "<<count<< "\n";
                              producerRankMap[key].clear();
                              producerRankMap[key].push_back(value+bias);
                              // llvm::outs()<<"value+bias: "<<value+bias<< "\n";
                              for (int i = 0; i < count-1; ++i) {
                                  producerRankMap[key].push_back(value+bias+i+1);
                                  currentIndex++;
                                  
                              }
                              bias+=count-1;
                              counter++; 
                              opted[key]=true;
                             
                              optSize+=1;
                              break;
                            }  
                        }
                      }
                    }
                    
                    // // optSize = opted.size();
                    // llvm::outs()<<"optSize: "<<optSize  << "\n";
                    // llvm::outs()<<"counter: "<<counter  << "\n";
                  }
                  std::vector<int> targetOrder;
                  std::vector<int> currentOrder;
                  std::map<int, int> permMap;
                  std::map<int, int> rePermMap;
                  SmallVector<unsigned, 6> targetPerm;
                  SmallVector<unsigned, 6> targetRePerm;
                  
                  for (int key = 0; key < producerRankMap.size(); ++key) {
                    // llvm::outs() << "Key: " << key << " -> Values: ";
                    for (int value : producerRankMap[key]) {
                        targetOrder.push_back(value);
                        // llvm::outs()  << value << " ";
                    }
                    // llvm::outs()  << "\n";

                  }

                  for (int key = 0; key < consumerRankMap.size(); ++key) {
                    // llvm::outs() << "Key: " << key << " -> Values: ";
                    for (int value : consumerRankMap[key]) {
                        currentOrder.push_back(value);
                        // llvm::outs()  << value << " ";
                    }
                    // llvm::outs()  << "\n";

                  }
                  

                                      
                  for(int i=0; i<targetOrder.size(); i++){
                    permMap[currentOrder[i]]=targetOrder[i];
                    rePermMap[targetOrder[i]]=currentOrder[i];
                  }
                  for (int key = 0; key < permMap.size(); ++key) {
                    // llvm::outs() << "Key: " << key << " -> Values: ";
                    // for (int value : permMap[key]) {
                    targetPerm.push_back(permMap[key]);
                    targetRePerm.push_back(rePermMap[key]);
                    // llvm::outs() << permMap[key] << "\n";
                    // llvm::outs() << rePermMap[key] << "\n";
                    // }
                  }

                  // SmallVector<unsigned, 6> permMap = {0,5,3,1,2,4};
                  // SmallVector<unsigned, 6> permMap = {0,1,3,2,4,5};
                  AffineLoopBand band;

                  if(!producerFunc->hasAttrOfType<UnitAttr>("conv_node")&&!consumerFunc->hasAttrOfType<UnitAttr>("conv_node")){
                      if(topLevelFor->hasAttrOfType<UnitAttr>("conv_guided_opt")){
                          getLoopBandFromOutermost( proFor, band);
                          llvm::outs()<<"optimize producer:"<<producerFunc.getName()<<"\n";
                          // band[0].dump();
                          for (int i = 0; i < loopdepth.size(); ++i) {
                              llvm::outs()<<"indexedArr: "<<loopdepth[i]<<"\n";
                          }
                          // permuteLoops(band, targetRePerm);
                      }
                      // else{
                      //     getLoopBandFromOutermost(topLevelFor, band);
                      //     // permuteLoops(band, targetPerm);
                      //     llvm::outs()<<"optimize consumer:"<<consumerFunc.getName()<<"\n";
                      //     band[0].dump();
                      // }
                      
                      // 
                  }
                  
                  // forOp.dump();
                  
                  // permuteLoops(band, targetPerm);
                  // band[0].dump();
                  return WalkResult::interrupt();
                }
              }
            }
          });
          
        }
      // }
    }

  }
};
} // namespace

std::unique_ptr<Pass>
codo::createStreamOptPass() {
  return std::make_unique<StreamOpt>();
}
