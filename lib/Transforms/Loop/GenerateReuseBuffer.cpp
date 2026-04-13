//===----------------------------------------------------------------------===//
//
// Copyright 2020-2021 The codo Authors.
//
//===----------------------------------------------------------------------===//
#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/Value.h"
#include "mlir/Support/LogicalResult.h"
#include "mlir/Transforms/DialectConversion.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "mlir/Dialect/MemRef/IR/MemRef.h"
#include "mlir/Dialect/Bufferization/Transforms/Passes.h"
#include "mlir/IR/IntegerSet.h"
#include "mlir/Dialect/Affine/Analysis/LoopAnalysis.h"
#include "mlir/Dialect/Affine/LoopUtils.h"
#include "mlir/Dialect/Affine/Utils.h"
#include "codo/Dialect/CodoOps.h"
#include "codo/Transforms/Passes.h"
#include "codo/Support/Utils.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/ADT/APFloat.h" 

#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "codo/Transforms/Passes.h"
#include "codo/Support/Utils.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"

using namespace mlir;
using namespace mlir::affine;
using namespace codo;

int countLoopDepth(Operation *op) {
  int maxDepth = 0;
  if (isa<mlir::affine::AffineForOp>(op)) {
    maxDepth = 1;
    for (auto &region : op->getRegions()) {
      for (auto &block : region) {
        for (auto &nestedOp : block) {
          if (isa<affine::AffineForOp>(nestedOp));
          // ++childmaxDepthNum;
          maxDepth = std::max(maxDepth, 1 + countLoopDepth(&nestedOp));
        }
      }
    }
  }
  return maxDepth;
}


void buildNewLoopStructureForDepthConv(PatternRewriter &rewriter, mlir::affine::AffineForOp outerFor, 
                    llvm::SmallVector<affine::AffineLoadOp, 8> loadOps, llvm::SmallVector<affine::AffineStoreOp, 8> storeOps) {

  assert(loadOps.size() == 3 && storeOps.size()==1 && "GenerateReuseBuffer: unexpected estimation result");
  // Get loop bounds
  llvm::SmallVector<int, 7> convLoopBounds;
  llvm::SmallVector<int, 4> inputLoopBounds;
  int batch, co, ho, wo, ci, kh, kw, ho2, wo2;

  // outerFor.dump();

  outerFor.walk([&](mlir::affine::AffineForOp affineForOp) {
      convLoopBounds.push_back(affineForOp.getUpperBoundMap().getSingleConstantResult());
  });
  // if(convLoopBounds.size()==6){
  //   outerFor.dump();
  //   return;
  // }
  kw = convLoopBounds[0];
  kh = convLoopBounds[1];
  ci = convLoopBounds[2];
  wo2 = convLoopBounds[3];
  ho2 = convLoopBounds[4];
  // co = convLoopBounds[5];
  batch = convLoopBounds[5];

  mlir::Value input = loadOps[0].getMemRef();
  // input.dump();
  auto func = outerFor->getParentOfType<func::FuncOp>();
  
  func.walk([&](affine::AffineStoreOp op) {
    if (op.getMemref() == input){
      // llvm::outs()<<"found the input"<<"\n";
      auto parentForOp = op->getParentOfType<affine::AffineForOp>();
      AffineLoopBand band;
      auto topParentForOp = getLoopBandFromInnermost(parentForOp, band);
      topParentForOp.walk([&](mlir::affine::AffineForOp affineForOp) {
          inputLoopBounds.push_back(affineForOp.getUpperBoundMap().getSingleConstantResult());
      });
      

      return WalkResult::interrupt();
    }
  });

  mlir::Value temp_value_3;
  mlir::Value temp_value_1;
  int convFactor=1;
  if(inputLoopBounds.size()==0){
    // llvm::outs()<<"func name: "<<func.getName()<<"\n";
    // func.setStringAttr(StringRef("unbalanced"));
    func.getOperation()->setAttr("unbalanced", UnitAttr::get(func->getContext()));
    // input = loadOps[0].getMemRef();
    // input.dump();
    // auto func = outerFor->getParentOfType<func::FuncOp>();
    // llvm::outs()<<"func name: "<<func.getName()<<"\n";
    auto memrefType = input.getType().dyn_cast<mlir::MemRefType>();
    auto cinDim = memrefType.getShape()[1];
    // llvm::outs()<<"cinDim name: "<<cinDim<<"\n";
    // func.walk([&](affine::AffineStoreOp op) {
    //   if (op.getMemref() == loadOps[2].getMemRef()){
    //     // llvm::outs()<<"found the input"<<"\n";
    //     auto parentForOp = op->getParentOfType<affine::AffineForOp>();
    //     AffineLoopBand band;
    //     auto topParentForOp = getLoopBandFromInnermost(parentForOp, band);
    //     topParentForOp.walk([&](mlir::affine::AffineForOp affineForOp) {
    //         inputLoopBounds.push_back(affineForOp.getUpperBoundMap().getSingleConstantResult());
    //     });

    //     return WalkResult::interrupt();
    //   }
    // });
    for(int i=0; i<memrefType.getShape().size(); i++){
      inputLoopBounds.push_back(memrefType.getShape()[i]);
      //  llvm::outs()<<"cinDim name: "<<memrefType.getShape()[i]<<"\n";
    }
    std::reverse(inputLoopBounds.begin(), inputLoopBounds.end());
    convFactor = memrefType.getShape()[3]/inputLoopBounds[1];
    // inputLoopBounds[2]=cinDim;
    // llvm::outs()<<"inputLoopBounds[2]: "<<inputLoopBounds[2]<<"\n";

    temp_value_3 = loadOps[2].getMemRef();
    temp_value_1 = loadOps[0].getMemRef();
    func.walk([&](affine::AffineStoreOp op) {
      if (op.getMemref().getType() == temp_value_3.getType()) {
          auto tempType = temp_value_3.getType().dyn_cast<mlir::MemRefType>();
          auto storeMemRefType = op.getMemref().getType().dyn_cast<mlir::MemRefType>();
          auto parentForOp = op->getParentOfType<affine::AffineForOp>();
          AffineLoopBand band;
          auto topParentForOp = getLoopBandFromInnermost(parentForOp, band);
          setReduntantAttr(topParentForOp);

          return WalkResult::interrupt();
      }
      return WalkResult::advance();
    });
  }else{
    // FIXME: This part can be simplified 
    temp_value_3 = loadOps[2].getMemRef();
    temp_value_1 = loadOps[0].getMemRef();
    func.walk([&](affine::AffineStoreOp op) {
      if (op.getMemref().getType() == temp_value_3.getType()) {
          auto tempType = temp_value_3.getType().dyn_cast<mlir::MemRefType>();
          auto storeMemRefType = op.getMemref().getType().dyn_cast<mlir::MemRefType>();
          auto parentForOp = op->getParentOfType<affine::AffineForOp>();
          AffineLoopBand band;
          auto topParentForOp = getLoopBandFromInnermost(parentForOp, band);
          setReduntantAttr(topParentForOp);

          return WalkResult::interrupt();
      }
      return WalkResult::advance();
    });
  }
  
  // llvm::outs()<<inputLoopBounds.size()<<"\n";
  // assert(inputLoopBounds.size()==4 && "GenerateReuseBuffer: wrong parent loop size");
  if(inputLoopBounds.size()==4){

  wo = inputLoopBounds[0];
  ho = inputLoopBounds[1];
  ci = inputLoopBounds[2];
  batch = inputLoopBounds[3];

  auto loc = outerFor.getLoc();
  // Create line buffer and window buffer
  auto line_buffer_type = mlir::MemRefType::get({batch, ci, kh, wo}, rewriter.getF32Type());
  auto new_line_buffer_type = MemRefType::get(
        line_buffer_type.getShape(), line_buffer_type.getElementType(),line_buffer_type.getLayout().getAffineMap(),
        MemoryKindAttr::get(line_buffer_type.getContext(), MemoryKind::BRAM_2P));
  auto line_buffer = rewriter.create<BufferOp>(loc, new_line_buffer_type);
  line_buffer.setStringAttr(StringRef("reuse_buffer"));

  auto window_buffer_type = mlir::MemRefType::get({batch, ci, kh, kw}, rewriter.getF32Type());
  auto new_window_buffer_type = MemRefType::get(
        window_buffer_type.getShape(), window_buffer_type.getElementType(),window_buffer_type.getLayout().getAffineMap(),
        MemoryKindAttr::get(window_buffer_type.getContext(), MemoryKind::BRAM_2P));
  auto window_buffer = rewriter.create<BufferOp>(loc, new_window_buffer_type);
  window_buffer.setStringAttr(StringRef("reuse_buffer"));

  // Create top-level loops: b, ho, wo
  rewriter.setInsertionPointAfter(outerFor);
  auto forOp0 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, batch);
  rewriter.setInsertionPointToStart(forOp0.getBody());
  Value arg0 = forOp0.getInductionVar();
  // forOp0.setStringAttr(StringRef("conv_loop"));
  forOp0.getOperation()->setAttr("top_loop", UnitAttr::get(forOp0->getContext()));

  // int counter = 0;
  func.walk([&](affine::AffineStoreOp op) {
    if (op.getMemref().getType() == temp_value_1.getType()) {
        auto tempType = temp_value_1.getType().dyn_cast<mlir::MemRefType>();
        auto storeMemRefType = op.getMemref().getType().dyn_cast<mlir::MemRefType>();
        auto parentForOp = op->getParentOfType<affine::AffineForOp>();
        AffineLoopBand band;
        auto topParentForOp = getLoopBandFromInnermost(parentForOp, band);
        // topParentForOp.getOperation()->setAttr(StringRef("init_loop"));
        if(!topParentForOp.getOperation()->hasAttrOfType<UnitAttr>("top_loop"))
          topParentForOp.getOperation()->setAttr("init_loop", UnitAttr::get(op->getContext()));

        // return WalkResult::interrupt();
  
    }
    return WalkResult::advance();
  });

  auto forOp1 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, ho);
  rewriter.setInsertionPointToStart(forOp1.getBody());
  Value arg1 = forOp1.getInductionVar();

  auto forOp2 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, wo);
  rewriter.setInsertionPointToStart(forOp2.getBody());
  Value arg2 = forOp2.getInductionVar();

  // Create line buffer inner loop: ci
  auto forOp3 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, ci);
  rewriter.setInsertionPointToStart(forOp3.getBody());
  Value arg3 = forOp3.getInductionVar();
  forOp3.getOperation()->setAttr("lb_loop", UnitAttr::get(forOp3->getContext()));

  // Update the value of linebuffer 
  for(int i = 0; i < kh; i++){
    if(i == kh-1){
      mlir::Value storeIndex = rewriter.create<mlir::arith::ConstantIndexOp>(loc, i);
      AffineExpr expr0 = rewriter.getAffineDimExpr(0);  // arg0
      // AffineExpr expr1 = rewriter.getAffineDimExpr(1);  // arg3
      AffineExpr expr1 = rewriter.getAffineDimExpr(1).floorDiv(convFactor);  // arg3
      AffineExpr expr2 = rewriter.getAffineDimExpr(2) * convFactor;  // arg1 * 2
      AffineExpr expr3 = rewriter.getAffineDimExpr(3) * convFactor;  // arg2 * 2

      AffineMap map = AffineMap::get(4, 0, {expr0, expr1, expr2, expr3},rewriter.getContext());
      auto loadOp = rewriter.create<mlir::affine::AffineLoadOp>(
          loc, input, map, ValueRange({arg0, arg3, arg1, arg2}));
      auto storeOp = rewriter.create<mlir::affine::AffineStoreOp>(
          loc, loadOp, line_buffer, ValueRange({arg0, arg3, storeIndex, arg2}));
    }else{
      mlir::Value loadIndex = rewriter.create<mlir::arith::ConstantIndexOp>(loc, i+1);
      mlir::Value storeIndex = rewriter.create<mlir::arith::ConstantIndexOp>(loc, i);
      auto loadOp = rewriter.create<mlir::affine::AffineLoadOp>(
          loc, line_buffer, ValueRange({arg0, arg3, loadIndex, arg2}));
      auto storeOp = rewriter.create<mlir::affine::AffineStoreOp>(
          loc, loadOp, line_buffer, ValueRange({arg0, arg3, storeIndex, arg2}));
    }    
  }

  // Create control statements for window buffer and conv
  rewriter.setInsertionPointAfter(forOp3);
  SmallVector<AffineExpr, 4> ifExprsBand1, ifExprsBand2;
  SmallVector<Value, 4> ifOperandsBand1, ifOperandsBand2;
  SmallVector<bool, 4> ifEqFlags1, ifEqFlags2;

  ifExprsBand1.push_back(rewriter.getAffineDimExpr(0) - (ho-ho2));
  ifEqFlags1.push_back(false);
  ifOperandsBand1.push_back(forOp1.getInductionVar());
  auto ifCondition1 = IntegerSet::get(ifOperandsBand1.size(), 0, ifExprsBand1, ifEqFlags1);
  auto ifOp1 = rewriter.create<affine::AffineIfOp>(loc, ifCondition1, ifOperandsBand1,/*withElseRegion=*/false);
  rewriter.setInsertionPointToStart(ifOp1.getThenBlock());

  // Create window buffer inner loops: ci, kh
  auto forOp4 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, ci);
  rewriter.setInsertionPointToStart(forOp4.getBody());
  Value arg4 = forOp4.getInductionVar();
  forOp4.getOperation()->setAttr("wb_loop", UnitAttr::get(forOp4->getContext()));

  auto forOp5 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, kh);
  rewriter.setInsertionPointToStart(forOp5.getBody());
  Value arg5 = forOp5.getInductionVar();

  // Update the value of window bufer
  for(int i = 0; i < kw; i++){
    if(i == kw-1){
      mlir::Value loadIndex = rewriter.create<mlir::arith::ConstantIndexOp>(loc, i);
      mlir::Value storeIndex = rewriter.create<mlir::arith::ConstantIndexOp>(loc, i);
      // auto tempop = input.getDefiningOp();
      auto loadOp = rewriter.create<mlir::affine::AffineLoadOp>(
          loc, line_buffer, ValueRange({arg0, arg4, arg5, arg2}));
      auto storeOp = rewriter.create<mlir::affine::AffineStoreOp>(
          loc, loadOp, window_buffer, ValueRange({arg0, arg4, arg5, storeIndex}));
    }else{
      mlir::Value loadIndex = rewriter.create<mlir::arith::ConstantIndexOp>(loc, i+1);
      mlir::Value storeIndex = rewriter.create<mlir::arith::ConstantIndexOp>(loc, i);
      auto loadOp = rewriter.create<mlir::affine::AffineLoadOp>(
          loc, window_buffer, ValueRange({arg0, arg4, arg5, loadIndex}));
      auto storeOp = rewriter.create<mlir::affine::AffineStoreOp>(
          loc, loadOp, window_buffer, ValueRange({arg0, arg4, arg5, storeIndex}));
    }    
  }

  // Create control statements for conv
  rewriter.setInsertionPointAfter(forOp4);
  // rewriter.setInsertionPointToStart(ifOp1.getThenBlock());
  ifExprsBand2.push_back(rewriter.getAffineDimExpr(0) - (wo-wo2));
  ifEqFlags2.push_back(false);
  ifOperandsBand2.push_back(forOp2.getInductionVar());
  auto ifCondition2 = IntegerSet::get(ifOperandsBand2.size(), 0, ifExprsBand2, ifEqFlags2);
  auto ifOp2 = rewriter.create<affine::AffineIfOp>(loc, ifCondition2, ifOperandsBand2,/*withElseRegion=*/false);
  rewriter.setInsertionPointToStart(ifOp2.getThenBlock());

    // Create the temp buffer which stores the conv results
  FloatAttr floatZero = rewriter.getFloatAttr(rewriter.getF32Type(), 0.0);
  auto initValue = rewriter.create<mlir::arith::ConstantOp>(loc, floatZero);
  // auto loadInitValue = rewriter.create<mlir::affine::AffineLoadOp>(
  //         loc, initValue, ValueRange({arg0, arg6, arg1, arg2}));

  auto temp_buffer_type = mlir::MemRefType::get({ci}, rewriter.getF32Type());
  auto new_temp_buffer_type = MemRefType::get(
        temp_buffer_type.getShape(), temp_buffer_type.getElementType(),temp_buffer_type.getLayout().getAffineMap(),
        MemoryKindAttr::get(temp_buffer_type.getContext(), MemoryKind::BRAM_2P));
  auto temp_buffer = rewriter.create<BufferOp>(loc, new_temp_buffer_type);

    // TODO: Add a new class
  temp_buffer.setStringAttr(StringRef("reuse_buffer"));
  
  // Create conv inner loop: co
  auto forOp6 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, ci);
  rewriter.setInsertionPointToStart(forOp6.getBody());
  Value arg6 = forOp6.getInductionVar();
  forOp6.getOperation()->setAttr("conv_loop", UnitAttr::get(forOp6->getContext()));
  forOp6.getOperation()->setAttr("depth_conv_loop", UnitAttr::get(forOp6->getContext()));
  

  int tripCount = batch*ho*wo*ci/kw/kh;
  IntegerAttr tripCountAttr = IntegerAttr::get(IntegerType::get(func.getContext(), 64), tripCount);
  
  // func.setAttr("tripcount", tripCountAttr);
  func.getOperation()->setAttr("tripcount", tripCountAttr);



  auto storeInitValue = rewriter.create<mlir::affine::AffineStoreOp>(
        loc, initValue, temp_buffer, ValueRange({arg6}));

  // Create conv inner loops: ci, kh, kw
  // auto forOp7 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, ci);
  // rewriter.setInsertionPointToStart(forOp7.getBody());
  // Value arg7 = forOp7.getInductionVar();

  auto forOp8 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, kh);
  rewriter.setInsertionPointToStart(forOp8.getBody());
  Value arg8 = forOp8.getInductionVar();

  auto forOp9 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, kw);
  rewriter.setInsertionPointToStart(forOp9.getBody());
  Value arg9 = forOp9.getInductionVar();
  
  auto loadInput = rewriter.create<mlir::affine::AffineLoadOp>(
          loc, window_buffer, ValueRange({arg0, arg6, arg8, arg9}));

  mlir::Value weight = loadOps[1].getMemRef();
  auto loadWeight = rewriter.create<mlir::affine::AffineLoadOp>(
          loc, weight, ValueRange({arg6, arg8, arg9}));
  auto mulResult = rewriter.create<arith::MulFOp>(loc, loadInput, loadWeight);
  auto loadtemp = rewriter.create<mlir::affine::AffineLoadOp>(
          loc, temp_buffer, ValueRange({arg6}));

  auto addResult = rewriter.create<arith::AddFOp>(loc, loadtemp, mulResult);

  auto storetemp = rewriter.create<mlir::affine::AffineStoreOp>(
        loc, addResult, temp_buffer, ValueRange({arg6}));
  auto output = storeOps[0].getMemref();

  // Write back the results to the output array
  rewriter.setInsertionPointAfter(forOp8);
  SmallVector<AffineExpr, 4> indexList = {rewriter.getAffineDimExpr(0), //
        rewriter.getAffineDimExpr(1), // 
        rewriter.getAffineDimExpr(2) - (ho-ho2), // ho - 2
        rewriter.getAffineDimExpr(3) - (ho-ho2)};
  AffineMap map = AffineMap::get(4, 0, ArrayRef<mlir::AffineExpr> (indexList), rewriter.getContext());

  auto loadtemp2 = rewriter.create<mlir::affine::AffineLoadOp>(
          loc, temp_buffer, ValueRange({arg6}));
  auto storeOp = rewriter.create<mlir::affine::AffineStoreOp>(
        loc, loadtemp2, output, map, ValueRange({arg0, arg6, arg1, arg2}));

  rewriter.replaceOp(outerFor, forOp0);
  }

  // if(storeOps.size()==2){
  //   llvm::outs()<<"checking convolution loops"<<"\n";
  //   auto parentStoreForOp = storeOps[1]->getParentOp();
  // }

  func.walk([&](affine::AffineLoadOp op) {
    if (op.getMemref() == storeOps[0].getMemref()){
      // llvm::outs()<<"found the output"<<"\n";
      // llvm::outs()<<"function name: "<<func.getName()<<"\n";
      auto parentStoreForOp = op->getParentOfType<affine::AffineForOp>();
      // parentForOp.set
      AffineLoopBand band;
      auto topParentStoreForOp = getLoopBandFromInnermost(parentStoreForOp, band);
      topParentStoreForOp.getOperation()->setAttr("store_loop", UnitAttr::get(topParentStoreForOp->getContext()));

      // topParentStoreForOp.walk([&](mlir::affine::AffineForOp affineForOp) {
      //     inputLoopBounds.push_back(affineForOp.getUpperBoundMap().getSingleConstantResult());
      // });

      return WalkResult::interrupt();
    }
  });

  func.getOperation()->setAttr("conv_node", UnitAttr::get(func->getContext()));
  func.getOperation()->setAttr("depth_conv_node", UnitAttr::get(func->getContext()));

}




void buildNewLoopStructureForConv(PatternRewriter &rewriter, mlir::affine::AffineForOp outerFor, 
                    llvm::SmallVector<affine::AffineLoadOp, 8> loadOps, llvm::SmallVector<affine::AffineStoreOp, 8> storeOps) {

  assert(loadOps.size() == 3 && storeOps.size()==1 && "GenerateReuseBuffer: unexpected estimation result");
  // Get loop bounds
  llvm::SmallVector<int, 7> convLoopBounds;
  llvm::SmallVector<int, 4> inputLoopBounds;
  int batch, co, ho, wo, ci, kh, kw, ho2, wo2;

  // outerFor.dump();

  outerFor.walk([&](mlir::affine::AffineForOp affineForOp) {
      convLoopBounds.push_back(affineForOp.getUpperBoundMap().getSingleConstantResult());
  });
  if(convLoopBounds.size()==6){
    // outerFor.dump();
    return;
  }
  kw = convLoopBounds[0];
  kh = convLoopBounds[1];
  ci = convLoopBounds[2];
  wo2 = convLoopBounds[3];
  ho2 = convLoopBounds[4];
  co = convLoopBounds[5];
  batch = convLoopBounds[6];

  mlir::Value input = loadOps[0].getMemRef();
  // input.dump();
  auto func = outerFor->getParentOfType<func::FuncOp>();
  
  func.walk([&](affine::AffineStoreOp op) {
    if (op.getMemref() == input){
      // llvm::outs()<<"found the input"<<"\n";
      auto parentForOp = op->getParentOfType<affine::AffineForOp>();
      AffineLoopBand band;
      auto topParentForOp = getLoopBandFromInnermost(parentForOp, band);
      topParentForOp.walk([&](mlir::affine::AffineForOp affineForOp) {
          inputLoopBounds.push_back(affineForOp.getUpperBoundMap().getSingleConstantResult());
      });
      

      return WalkResult::interrupt();
    }
  });

  mlir::Value temp_value_3;
  mlir::Value temp_value_1;
  int convFactor=1;
  if(inputLoopBounds.size()==0){
    // llvm::outs()<<"func name: "<<func.getName()<<"\n";
    // func.setStringAttr(StringRef("unbalanced"));
    func.getOperation()->setAttr("unbalanced", UnitAttr::get(func->getContext()));
    // input = loadOps[0].getMemRef();
    // input.dump();
    // auto func = outerFor->getParentOfType<func::FuncOp>();
    // llvm::outs()<<"func name: "<<func.getName()<<"\n";
    auto memrefType = input.getType().dyn_cast<mlir::MemRefType>();
    auto cinDim = memrefType.getShape()[1];
    // llvm::outs()<<"cinDim name: "<<cinDim<<"\n";
    // func.walk([&](affine::AffineStoreOp op) {
    //   if (op.getMemref() == loadOps[2].getMemRef()){
    //     // llvm::outs()<<"found the input"<<"\n";
    //     auto parentForOp = op->getParentOfType<affine::AffineForOp>();
    //     AffineLoopBand band;
    //     auto topParentForOp = getLoopBandFromInnermost(parentForOp, band);
    //     topParentForOp.walk([&](mlir::affine::AffineForOp affineForOp) {
    //         inputLoopBounds.push_back(affineForOp.getUpperBoundMap().getSingleConstantResult());
    //     });

    //     return WalkResult::interrupt();
    //   }
    // });
    for(int i=0; i<memrefType.getShape().size(); i++){
      inputLoopBounds.push_back(memrefType.getShape()[i]);
      //  llvm::outs()<<"cinDim name: "<<memrefType.getShape()[i]<<"\n";
    }
    std::reverse(inputLoopBounds.begin(), inputLoopBounds.end());
    convFactor = memrefType.getShape()[3]/inputLoopBounds[1];
    // inputLoopBounds[2]=cinDim;
    // llvm::outs()<<"inputLoopBounds[2]: "<<inputLoopBounds[2]<<"\n";

    temp_value_3 = loadOps[2].getMemRef();
    temp_value_1 = loadOps[0].getMemRef();
    func.walk([&](affine::AffineStoreOp op) {
      if (op.getMemref().getType() == temp_value_3.getType()) {
          auto tempType = temp_value_3.getType().dyn_cast<mlir::MemRefType>();
          auto storeMemRefType = op.getMemref().getType().dyn_cast<mlir::MemRefType>();
          auto parentForOp = op->getParentOfType<affine::AffineForOp>();
          AffineLoopBand band;
          auto topParentForOp = getLoopBandFromInnermost(parentForOp, band);
          setReduntantAttr(topParentForOp);

          return WalkResult::interrupt();
      }
      return WalkResult::advance();
    });
  }else{
    // FIXME: This part can be simplified 
    temp_value_3 = loadOps[2].getMemRef();
    temp_value_1 = loadOps[0].getMemRef();
    func.walk([&](affine::AffineStoreOp op) {
      if (op.getMemref().getType() == temp_value_3.getType()) {
          auto tempType = temp_value_3.getType().dyn_cast<mlir::MemRefType>();
          auto storeMemRefType = op.getMemref().getType().dyn_cast<mlir::MemRefType>();
          auto parentForOp = op->getParentOfType<affine::AffineForOp>();
          AffineLoopBand band;
          auto topParentForOp = getLoopBandFromInnermost(parentForOp, band);
          setReduntantAttr(topParentForOp);

          return WalkResult::interrupt();
      }
      return WalkResult::advance();
    });
  }
  
  // llvm::outs()<<inputLoopBounds.size()<<"\n";
  // assert(inputLoopBounds.size()==4 && "GenerateReuseBuffer: wrong parent loop size");
  if(inputLoopBounds.size()==4){

  wo = inputLoopBounds[0];
  ho = inputLoopBounds[1];
  ci = inputLoopBounds[2];
  batch = inputLoopBounds[3];

  auto loc = outerFor.getLoc();
  // Create line buffer and window buffer
  auto line_buffer_type = mlir::MemRefType::get({batch, ci, kh, wo}, rewriter.getF32Type());
  auto new_line_buffer_type = MemRefType::get(
        line_buffer_type.getShape(), line_buffer_type.getElementType(),line_buffer_type.getLayout().getAffineMap(),
        MemoryKindAttr::get(line_buffer_type.getContext(), MemoryKind::BRAM_2P));
  auto line_buffer = rewriter.create<BufferOp>(loc, new_line_buffer_type);
  line_buffer.setStringAttr(StringRef("reuse_buffer"));

  auto window_buffer_type = mlir::MemRefType::get({batch, ci, kh, kw}, rewriter.getF32Type());
  auto new_window_buffer_type = MemRefType::get(
        window_buffer_type.getShape(), window_buffer_type.getElementType(),window_buffer_type.getLayout().getAffineMap(),
        MemoryKindAttr::get(window_buffer_type.getContext(), MemoryKind::BRAM_2P));
  auto window_buffer = rewriter.create<BufferOp>(loc, new_window_buffer_type);
  window_buffer.setStringAttr(StringRef("reuse_buffer"));

  // Create top-level loops: b, ho, wo
  rewriter.setInsertionPointAfter(outerFor);
  auto forOp0 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, batch);
  rewriter.setInsertionPointToStart(forOp0.getBody());
  Value arg0 = forOp0.getInductionVar();
  // forOp0.setStringAttr(StringRef("conv_loop"));
  forOp0.getOperation()->setAttr("top_loop", UnitAttr::get(forOp0->getContext()));

  // int counter = 0;
  func.walk([&](affine::AffineStoreOp op) {
    if (op.getMemref().getType() == temp_value_1.getType()) {
        auto tempType = temp_value_1.getType().dyn_cast<mlir::MemRefType>();
        auto storeMemRefType = op.getMemref().getType().dyn_cast<mlir::MemRefType>();
        auto parentForOp = op->getParentOfType<affine::AffineForOp>();
        AffineLoopBand band;
        auto topParentForOp = getLoopBandFromInnermost(parentForOp, band);
        // topParentForOp.getOperation()->setAttr(StringRef("init_loop"));
        if(!topParentForOp.getOperation()->hasAttrOfType<UnitAttr>("top_loop"))
          topParentForOp.getOperation()->setAttr("init_loop", UnitAttr::get(op->getContext()));

        // return WalkResult::interrupt();
  
    }
    return WalkResult::advance();
  });

  auto forOp1 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, ho);
  rewriter.setInsertionPointToStart(forOp1.getBody());
  Value arg1 = forOp1.getInductionVar();

  auto forOp2 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, wo);
  rewriter.setInsertionPointToStart(forOp2.getBody());
  Value arg2 = forOp2.getInductionVar();

  // Create line buffer inner loop: ci
  auto forOp3 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, ci);
  rewriter.setInsertionPointToStart(forOp3.getBody());
  Value arg3 = forOp3.getInductionVar();
  forOp3.getOperation()->setAttr("lb_loop", UnitAttr::get(forOp3->getContext()));


  // Update the value of linebuffer 
  for(int i = 0; i < kh; i++){
    if(i == kh-1){
      mlir::Value storeIndex = rewriter.create<mlir::arith::ConstantIndexOp>(loc, i);
      AffineExpr expr0 = rewriter.getAffineDimExpr(0);  // arg0
      // AffineExpr expr1 = rewriter.getAffineDimExpr(1);  // arg3
      AffineExpr expr1 = rewriter.getAffineDimExpr(1).floorDiv(convFactor);  // arg3
      AffineExpr expr2 = rewriter.getAffineDimExpr(2) * convFactor;  // arg1 * 2
      AffineExpr expr3 = rewriter.getAffineDimExpr(3) * convFactor;  // arg2 * 2

      AffineMap map = AffineMap::get(4, 0, {expr0, expr1, expr2, expr3},rewriter.getContext());
      auto loadOp = rewriter.create<mlir::affine::AffineLoadOp>(
          loc, input, map, ValueRange({arg0, arg3, arg1, arg2}));
      auto storeOp = rewriter.create<mlir::affine::AffineStoreOp>(
          loc, loadOp, line_buffer, ValueRange({arg0, arg3, storeIndex, arg2}));
    }else{
      mlir::Value loadIndex = rewriter.create<mlir::arith::ConstantIndexOp>(loc, i+1);
      mlir::Value storeIndex = rewriter.create<mlir::arith::ConstantIndexOp>(loc, i);
      auto loadOp = rewriter.create<mlir::affine::AffineLoadOp>(
          loc, line_buffer, ValueRange({arg0, arg3, loadIndex, arg2}));
      auto storeOp = rewriter.create<mlir::affine::AffineStoreOp>(
          loc, loadOp, line_buffer, ValueRange({arg0, arg3, storeIndex, arg2}));
    }    
  }

  // Create control statements for window buffer and conv
  rewriter.setInsertionPointAfter(forOp3);
  SmallVector<AffineExpr, 4> ifExprsBand1, ifExprsBand2;
  SmallVector<Value, 4> ifOperandsBand1, ifOperandsBand2;
  SmallVector<bool, 4> ifEqFlags1, ifEqFlags2;

  ifExprsBand1.push_back(rewriter.getAffineDimExpr(0) - (ho-ho2));
  ifEqFlags1.push_back(false);
  ifOperandsBand1.push_back(forOp1.getInductionVar());
  auto ifCondition1 = IntegerSet::get(ifOperandsBand1.size(), 0, ifExprsBand1, ifEqFlags1);
  auto ifOp1 = rewriter.create<affine::AffineIfOp>(loc, ifCondition1, ifOperandsBand1,/*withElseRegion=*/false);
  rewriter.setInsertionPointToStart(ifOp1.getThenBlock());

  // Create window buffer inner loops: ci, kh
  auto forOp4 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, ci);
  rewriter.setInsertionPointToStart(forOp4.getBody());
  Value arg4 = forOp4.getInductionVar();
  forOp4.getOperation()->setAttr("wb_loop", UnitAttr::get(forOp4->getContext()));

  auto forOp5 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, kh);
  rewriter.setInsertionPointToStart(forOp5.getBody());
  Value arg5 = forOp5.getInductionVar();

  // Update the value of window bufer
  for(int i = 0; i < kw; i++){
    if(i == kw-1){
      mlir::Value loadIndex = rewriter.create<mlir::arith::ConstantIndexOp>(loc, i);
      mlir::Value storeIndex = rewriter.create<mlir::arith::ConstantIndexOp>(loc, i);
      // auto tempop = input.getDefiningOp();
      auto loadOp = rewriter.create<mlir::affine::AffineLoadOp>(
          loc, line_buffer, ValueRange({arg0, arg4, arg5, arg2}));
      auto storeOp = rewriter.create<mlir::affine::AffineStoreOp>(
          loc, loadOp, window_buffer, ValueRange({arg0, arg4, arg5, storeIndex}));
    }else{
      mlir::Value loadIndex = rewriter.create<mlir::arith::ConstantIndexOp>(loc, i+1);
      mlir::Value storeIndex = rewriter.create<mlir::arith::ConstantIndexOp>(loc, i);
      auto loadOp = rewriter.create<mlir::affine::AffineLoadOp>(
          loc, window_buffer, ValueRange({arg0, arg4, arg5, loadIndex}));
      auto storeOp = rewriter.create<mlir::affine::AffineStoreOp>(
          loc, loadOp, window_buffer, ValueRange({arg0, arg4, arg5, storeIndex}));
    }    
  }

  // Create control statements for conv
  rewriter.setInsertionPointAfter(forOp4);
  // rewriter.setInsertionPointToStart(ifOp1.getThenBlock());
  ifExprsBand2.push_back(rewriter.getAffineDimExpr(0) - (wo-wo2));
  ifEqFlags2.push_back(false);
  ifOperandsBand2.push_back(forOp2.getInductionVar());
  auto ifCondition2 = IntegerSet::get(ifOperandsBand2.size(), 0, ifExprsBand2, ifEqFlags2);
  auto ifOp2 = rewriter.create<affine::AffineIfOp>(loc, ifCondition2, ifOperandsBand2,/*withElseRegion=*/false);
  rewriter.setInsertionPointToStart(ifOp2.getThenBlock());

    // Create the temp buffer which stores the conv results
  FloatAttr floatZero = rewriter.getFloatAttr(rewriter.getF32Type(), 0.0);
  auto initValue = rewriter.create<mlir::arith::ConstantOp>(loc, floatZero);
  // auto loadInitValue = rewriter.create<mlir::affine::AffineLoadOp>(
  //         loc, initValue, ValueRange({arg0, arg6, arg1, arg2}));

  auto temp_buffer_type = mlir::MemRefType::get({co}, rewriter.getF32Type());
  auto new_temp_buffer_type = MemRefType::get(
        temp_buffer_type.getShape(), temp_buffer_type.getElementType(),temp_buffer_type.getLayout().getAffineMap(),
        MemoryKindAttr::get(temp_buffer_type.getContext(), MemoryKind::BRAM_2P));
  auto temp_buffer = rewriter.create<BufferOp>(loc, new_temp_buffer_type);

    // TODO: Add a new class
  temp_buffer.setStringAttr(StringRef("reuse_buffer"));
  
  // Create conv inner loop: co
  auto forOp6 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, co);
  rewriter.setInsertionPointToStart(forOp6.getBody());
  Value arg6 = forOp6.getInductionVar();
  forOp6.getOperation()->setAttr("conv_loop", UnitAttr::get(forOp6->getContext()));


  // kw = convLoopBounds[0];
  // kh = convLoopBounds[1];
  // ci = convLoopBounds[2];
  // wo2 = convLoopBounds[3];
  // ho2 = convLoopBounds[4];
  // co = convLoopBounds[5];
  // batch = convLoopBounds[6];

  // int tripCount = batch*ho*wo*(ci+ci*kh+co*ci*kh*kw);
  // int tripCount = batch*ho*wo+batch*ho2*wo*ci*kh+batch*ho2*wo2*co*ci*kh*kw;

  int tripCount = batch*ho*wo*co*ci/kw/kh;
  IntegerAttr tripCountAttr = IntegerAttr::get(
        IntegerType::get(func.getContext(), 64), tripCount);
  // Add the tripCount attribute to FuncOp
  if(kh*kw<=4){
    func.getOperation()->setAttr("special_node", UnitAttr::get(func->getContext()));
  }
  func.getOperation()->setAttr("tripcount", tripCountAttr);

  // auto result= func.getOperation()->getAttrOfType<IntegerAttr>("tripcount");
  // llvm::outs()<<"tripCountAttr: "<<result.getInt()<<"\n";


  auto storeInitValue = rewriter.create<mlir::affine::AffineStoreOp>(
        loc, initValue, temp_buffer, ValueRange({arg6}));

  // Create conv inner loops: ci, kh, kw
  auto forOp7 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, ci);
  rewriter.setInsertionPointToStart(forOp7.getBody());
  Value arg7 = forOp7.getInductionVar();

  auto forOp8 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, kh);
  rewriter.setInsertionPointToStart(forOp8.getBody());
  Value arg8 = forOp8.getInductionVar();

  auto forOp9 = rewriter.create<mlir::affine::AffineForOp>(loc, 0, kw);
  rewriter.setInsertionPointToStart(forOp9.getBody());
  Value arg9 = forOp9.getInductionVar();

  auto loadInput = rewriter.create<mlir::affine::AffineLoadOp>(
          loc, window_buffer, ValueRange({arg0, arg7, arg8, arg9}));

  mlir::Value weight = loadOps[1].getMemRef();
  auto loadWeight = rewriter.create<mlir::affine::AffineLoadOp>(
          loc, weight, ValueRange({arg6, arg7, arg8, arg9}));
  auto mulResult = rewriter.create<arith::MulFOp>(loc, loadInput, loadWeight);
  auto loadtemp = rewriter.create<mlir::affine::AffineLoadOp>(
          loc, temp_buffer, ValueRange({arg6}));

  auto addResult = rewriter.create<arith::AddFOp>(loc, loadtemp, mulResult);

  auto storetemp = rewriter.create<mlir::affine::AffineStoreOp>(
        loc, addResult, temp_buffer, ValueRange({arg6}));
  auto output = storeOps[0].getMemref();

  // Write back the results to the output array
  rewriter.setInsertionPointAfter(forOp7);
  SmallVector<AffineExpr, 4> indexList = {rewriter.getAffineDimExpr(0), // 
        rewriter.getAffineDimExpr(1), //
        rewriter.getAffineDimExpr(2) - (ho-ho2), // ho - 2
        rewriter.getAffineDimExpr(3) - (ho-ho2)};
  AffineMap map = AffineMap::get(4, 0, ArrayRef<mlir::AffineExpr> (indexList), rewriter.getContext());

  auto loadtemp2 = rewriter.create<mlir::affine::AffineLoadOp>(
          loc, temp_buffer, ValueRange({arg6}));
  auto storeOp = rewriter.create<mlir::affine::AffineStoreOp>(
        loc, loadtemp2, output, map, ValueRange({arg0, arg6, arg1, arg2}));

  rewriter.replaceOp(outerFor, forOp0);
  }

  // if(storeOps.size()==2){
  //   llvm::outs()<<"checking convolution loops"<<"\n";
  //   auto parentStoreForOp = storeOps[1]->getParentOp();
  // }

  func.walk([&](affine::AffineLoadOp op) {
    if (op.getMemref() == storeOps[0].getMemref()){
      // llvm::outs()<<"found the output"<<"\n";
      // llvm::outs()<<"function name: "<<func.getName()<<"\n";
      auto parentStoreForOp = op->getParentOfType<affine::AffineForOp>();
      // parentForOp.set
      AffineLoopBand band;
      auto topParentStoreForOp = getLoopBandFromInnermost(parentStoreForOp, band);
      topParentStoreForOp.getOperation()->setAttr("store_loop", UnitAttr::get(topParentStoreForOp->getContext()));

      // topParentStoreForOp.walk([&](mlir::affine::AffineForOp affineForOp) {
      //     inputLoopBounds.push_back(affineForOp.getUpperBoundMap().getSingleConstantResult());
      // });

      return WalkResult::interrupt();
    }
  });

  func.getOperation()->setAttr("conv_node", UnitAttr::get(func->getContext()));

}


static bool isConvolutionLoop(Operation *op) {
  // llvm::outs()<<"checking convolution loops"<<"\n";
  auto affineFor = dyn_cast<mlir::affine::AffineForOp>(op);
  AffineLoopBand band; 
  getLoopBandFromOutermost(affineFor, band);
  if (auto affineFor = dyn_cast<mlir::affine::AffineForOp>(op)) {
    if (countLoopDepth(affineFor) == 7) {
      return true;
    }
  }
  return false;
}

static bool isDepthConvolutionLoop(Operation *op) {
  // llvm::outs()<<"checking convolution loops"<<"\n";
  auto affineFor = dyn_cast<mlir::affine::AffineForOp>(op);
  AffineLoopBand band; 
  getLoopBandFromOutermost(affineFor, band);
  if (auto affineFor = dyn_cast<mlir::affine::AffineForOp>(op)) {
    if(countLoopDepth(affineFor) == 6){
      // check if loadops = 3 and storeops = 1;
      llvm::SmallVector<affine::AffineLoadOp, 8> loadOps;
      llvm::SmallVector<affine::AffineStoreOp, 8> storeOps;
      affineFor.getBody()->walk([&](mlir::Operation *op) {
        if (auto loadOp = llvm::dyn_cast<affine::AffineLoadOp>(op)) {
            loadOps.push_back(loadOp);
            // loadOp.dump();
        } else if (auto storeOp = llvm::dyn_cast<affine::AffineStoreOp>(op)) {
            storeOps.push_back(storeOp);
            // storeOp.dump();
        }
      });

      if(loadOps.size()==3 && storeOps.size()==1){
        return true;
      }

    }
  }
  return false;
}

namespace {
struct ReuseBufferGen : public OpRewritePattern<AffineForOp> {
  using OpRewritePattern<AffineForOp>::OpRewritePattern;

  LogicalResult matchAndRewrite(AffineForOp op,
                                PatternRewriter &rewriter) const override {
    // llvm::outs()<<"start matchAndRewrite"<<"\n";
    if (isConvolutionLoop(op)==true){
      // llvm::outs()<<"matchAndRewrite"<<"\n";
      llvm::SmallVector<affine::AffineLoadOp, 8> loadOps;
      llvm::SmallVector<affine::AffineStoreOp, 8> storeOps;
      op.getBody()->walk([&](mlir::Operation *op) {
        if (auto loadOp = llvm::dyn_cast<affine::AffineLoadOp>(op)) {
            loadOps.push_back(loadOp);
            // loadOp.dump();
        } else if (auto storeOp = llvm::dyn_cast<affine::AffineStoreOp>(op)) {
            storeOps.push_back(storeOp);
            // storeOp.dump();
        }
      });
      buildNewLoopStructureForConv(rewriter, op, loadOps, storeOps);
    }else if(isDepthConvolutionLoop(op)==true){
      llvm::SmallVector<affine::AffineLoadOp, 8> loadOps;
      llvm::SmallVector<affine::AffineStoreOp, 8> storeOps;
      op.getBody()->walk([&](mlir::Operation *op) {
        if (auto loadOp = llvm::dyn_cast<affine::AffineLoadOp>(op)) {
            loadOps.push_back(loadOp);
            // loadOp.dump();
        } else if (auto storeOp = llvm::dyn_cast<affine::AffineStoreOp>(op)) {
            storeOps.push_back(storeOp);
            // storeOp.dump();
        }
      });
      // op.dump();
      buildNewLoopStructureForDepthConv(rewriter, op, loadOps, storeOps);

    }
    return success();
  }
};
} // namespace


static bool isPooling(Operation *op) {
  
  // TODO: AvgPool Vs MaxPool
  bool isPool = false;
  auto forOp = dyn_cast<mlir::affine::AffineForOp>(op);
  // Make sure this is a top-level forOp
  if (isa<func::FuncOp>(forOp->getParentOp())||isa<codo::TaskOp>(forOp->getParentOp())){
    // forOp.dump();
    forOp.walk([&](Operation *op) {
      // llvm::outs()<<*op<<"\n";
        // TODO: other types of maxOp: arith::MaxSIOp, arith::MaxUIOp,arith::MaximumFOp
        if (isa<arith::MaximumFOp>(op)) {
          // llvm::outs()<<"checking isPooling loops"<<"\n";
            isPool = true;
            return WalkResult::interrupt();  // 
        }
    });
    return isPool;

  }
  return isPool;
}


namespace {
struct SimplifyPool3 : public OpRewritePattern<AffineForOp> {
  using OpRewritePattern<AffineForOp>::OpRewritePattern;

  LogicalResult matchAndRewrite(AffineForOp op,
                                PatternRewriter &rewriter) const override {
    // llvm::outs()<<"matchAndRewrite"<<"\n";
    if (isPooling(op)==true && !op->hasAttrOfType<UnitAttr>("new_pool_loop")){
      // llvm::outs()<<"matchAndRewrite"<<"\n";
      // op.dump();
      auto func = op->getParentOfType<func::FuncOp>();
      auto args = func.getArguments(); // 
      bool loadFuncArg = false;
      bool storeFuncArg = false;
      llvm::SmallVector<affine::AffineLoadOp, 8> loadOps;
      llvm::SmallVector<affine::AffineStoreOp, 8> storeOps;

      // llvm::SmallVector<affine::AffineLoadOp, 8> loadOps;
      // llvm::SmallVector<affine::AffineStoreOp, 8> storeOps;
      op->walk([&](AffineForOp forOp) {
        forOp.walk([&](Operation *innerOp) {
          if (auto loadOp = dyn_cast<AffineLoadOp>(innerOp)) {
            MemRefType memRefType = loadOp.getMemRefType();
            Value memRef = loadOp.getMemRef();
            if (std::find(args.begin(), args.end(), memRef) != args.end()) {
                // llvm::errs() << "AffineLoadOp reads array which is a function argument.\n";
                loadFuncArg = true;
                loadOps.push_back(loadOp);
            }
          } 
          else if (auto storeOp = dyn_cast<AffineStoreOp>(innerOp)) {
            MemRefType memRefType = storeOp.getMemRefType();
            Value memRef = storeOp.getMemRef();
            if (std::find(args.begin(), args.end(), memRef) != args.end()) {
                // llvm::errs() << "AffineStoreOp writes to array which is a function argument.\n";
                storeFuncArg = true;
                storeOps.push_back(storeOp);
            }
          }
        });
      });
      

      if(loadFuncArg&&storeFuncArg){

        auto &block = func.getBody().front();
      rewriter.setInsertionPointToStart(&block);
      auto newLoop = op.clone();
      auto loc = op.getLoc();

      AffineLoopBand band;
      getLoopBandFromOutermost(op, band);
      SmallVector<Value, 4> inductionVars;
      auto memRef = loadOps[0].getMemRef();
      auto memRefType = memRef.getType().dyn_cast<MemRefType>().getShape();

      FloatAttr zero = rewriter.getFloatAttr(rewriter.getF32Type(), 0);
      auto initValue = rewriter.create<mlir::arith::ConstantOp>(loc, zero);
      auto temp_buffer_type = mlir::MemRefType::get(memRefType, rewriter.getF32Type());
      auto new_temp_buffer_type = MemRefType::get(
      temp_buffer_type.getShape(), temp_buffer_type.getElementType(),temp_buffer_type.getLayout().getAffineMap(),
      MemoryKindAttr::get(temp_buffer_type.getContext(), MemoryKind::BRAM_2P));
      auto temp_buffer = rewriter.create<BufferOp>(loc, new_temp_buffer_type);
      temp_buffer.setStringAttr(StringRef("reuse_buffer"));

        for (size_t i = 0; i < memRefType.size(); ++i) {
          // AffineForOp currentForOp = band[i];
          int64_t dimSize = memRefType[i];
          // auto bound = currentForOp.getUpperBoundMap().getSingleConstantResult();
          auto newFor = rewriter.create<mlir::affine::AffineForOp>(loc, 0, dimSize);
          inductionVars.push_back(newFor.getInductionVar());
          rewriter.setInsertionPointToStart(newFor.getBody());
        }

        
        auto newloadOp = rewriter.create<mlir::affine::AffineLoadOp>(
                  loc, loadOps[0].getMemRef(), ValueRange(inductionVars));
        // auto temp_value = loadOps[0].getMemRef();
        auto storeInitValue = rewriter.create<mlir::affine::AffineStoreOp>(
                                        loc, newloadOp, temp_buffer, ValueRange(inductionVars));

        op.getOperation()->setAttr("new_pool_loop", UnitAttr::get(op->getContext()));

        rewriter.setInsertionPointAfter(loadOps[0]);
      // auto newloadOp = rewriter.create<mlir::affine::AffineLoadOp>(
      //             loc, temp_buffer, ValueRange(inductionVars));

      Value oldMemRef = loadOps[0].getMemRef();
      AffineMap affineMap = loadOps[0].getAffineMap();
      
      SmallVector<Value, 4> indices(loadOps[0].getMapOperands());
    auto newLoadOp = rewriter.create<AffineLoadOp>(loc, temp_buffer, affineMap, indices);
    
    // rewriter.replaceOp(loadOp, newLoadOp.getResult());
      // loadOps[0].replace
      rewriter.replaceOp(loadOps[0], newLoadOp);
              // func
              // func.getOperation()->setAttr("pool_opted", UnitAttr::get(func->getContext()));
      }

      


      // func.dump();
      // return success();
    }
    return success();
  }
};
} 






namespace {
struct SimplifyPool : public OpRewritePattern<AffineForOp> {
  using OpRewritePattern<AffineForOp>::OpRewritePattern;

  LogicalResult matchAndRewrite(AffineForOp op,
                                PatternRewriter &rewriter) const override {
    // llvm::outs()<<"matchAndRewrite"<<"\n";
    if (isPooling(op)==true && !op->hasAttrOfType<UnitAttr>("pool_loop")){
      // llvm::outs()<<"matchAndRewrite"<<"\n";
      // op.dump();
      auto func = op->getParentOfType<func::FuncOp>();
      llvm::SmallVector<affine::AffineLoadOp, 8> loadOps;
      llvm::SmallVector<affine::AffineStoreOp, 8> storeOps;
      op.getBody()->walk([&](mlir::Operation *op) {
        if (auto loadOp = llvm::dyn_cast<affine::AffineLoadOp>(op)) {
            loadOps.push_back(loadOp);
            // loadOp.dump();
        } else if (auto storeOp = llvm::dyn_cast<affine::AffineStoreOp>(op)) {
            storeOps.push_back(storeOp);
            // storeOp.dump();
        }
      });

      auto loc = op.getLoc();
      auto temp_value = loadOps[1].getMemRef();
      auto oldmem = temp_value.getDefiningOp();
      auto storeValue = storeOps.back().getMemRef();
      // llvm::outs() << storeValue << "\n";
      auto &block = func.getBody().front();
      rewriter.setInsertionPointToStart(&block);
      llvm::APFloat negInf = llvm::APFloat::getInf(rewriter.getF32Type().getFloatSemantics(), true);  // true 表示负无穷
      FloatAttr floatNegInf = rewriter.getFloatAttr(rewriter.getF32Type(), negInf);
      auto initValue = rewriter.create<mlir::arith::ConstantOp>(loc, floatNegInf);
      auto temp_buffer_type = mlir::MemRefType::get({}, rewriter.getF32Type());
      auto new_temp_buffer_type = MemRefType::get(
        temp_buffer_type.getShape(), temp_buffer_type.getElementType(),temp_buffer_type.getLayout().getAffineMap(),
        MemoryKindAttr::get(temp_buffer_type.getContext(), MemoryKind::BRAM_2P));
      auto temp_buffer = rewriter.create<BufferOp>(loc, new_temp_buffer_type);
      auto storeInitValue = rewriter.create<mlir::affine::AffineStoreOp>(
                                        loc, initValue, temp_buffer, ValueRange({}));
      temp_buffer.setStringAttr(StringRef("reuse_buffer"));
      func.walk([&](affine::AffineStoreOp storeOp) {
          if (storeOp.getMemref() == temp_value) {
              // llvm::outs() << "matchAndRewrite\n";
              // llvm::outs() << temp_value << "\n";
              auto parentForOp = storeOp->getParentOfType<affine::AffineForOp>();
              AffineLoopBand band;
              auto topParentForOp = getLoopBandFromInnermost(parentForOp, band);
              // topParentForOp.dump();
              setReduntantAttr(topParentForOp);
              // topParentForOp->erase();
              // op.dump();
              // op.walk([&](affine::AffineLoadOp loadOp) {
              //   if (loadOp.getMemref() == temp_value) {
              //     rewriter.setInsertionPointAfter(loadOp);
              //     auto newloadOp = rewriter.create<mlir::affine::AffineLoadOp>(
              //     loc, temp_buffer, ValueRange({}));
              //     rewriter.replaceOp(loadOp, newloadOp);
              //     return WalkResult::interrupt();  
              //   }
              //             // return WalkResult::advance();
              // });
              rewriter.setInsertionPointAfter(loadOps[1]);
              auto newloadOp = rewriter.create<mlir::affine::AffineLoadOp>(
                  loc, temp_buffer, ValueRange({}));
              // op.dump();
              rewriter.replaceOp(loadOps[1], newloadOp);
              // op.dump();
              // rewriter.replaceOp(oldmem, temp_buffer);
              op.getOperation()->setAttr("pool_loop", UnitAttr::get(op->getContext()));
              // func
              func.getOperation()->setAttr("pool_opted", UnitAttr::get(func->getContext()));
              // op.dump();
              return WalkResult::interrupt();
          }

      });
    }
    return success();
  }
};
} 

namespace {
struct SimplifyPool2 : public OpRewritePattern<AffineForOp> {
  using OpRewritePattern<AffineForOp>::OpRewritePattern;

  LogicalResult matchAndRewrite(AffineForOp op,
                                PatternRewriter &rewriter) const override {

    if(isPooling(op)&& !op->hasAttrOfType<UnitAttr>("pool_loop_opted")){
      auto loc = op.getLoc();
      auto func = op->getParentOfType<func::FuncOp>();
      op.walk([&](affine::AffineStoreOp storeOp) {
          mlir::Value memref = storeOp.getMemref();
          if(auto blockArg = memref.dyn_cast<mlir::BlockArgument>()){
              // llvm::outs() << "enter\n";
              // llvm::outs()<< storeOp << "enter: \n";
              // llvm::outs()<< storeOp.getIndices().size() << "enter: \n";
              // op.dump();
              // auto parentForOp = storeOp->getParentOfType<affine::AffineForOp>();
              AffineLoopBand band;
              
              getLoopBandFromOutermost(op, band);
              // auto topParentForOp = getLoopBandFromInnermost(parentForOp, band);
              // TODO: general design
              // if(storeOp.getIndices().size()==4){
                // band.resize(4);
                rewriter.setInsertionPoint(band[4]);


                FloatAttr floatZero = rewriter.getFloatAttr(rewriter.getF32Type(), 0.0);
                auto initValue2 = rewriter.create<mlir::arith::ConstantOp>(loc, floatZero);
                auto temp_type = mlir::MemRefType::get({}, rewriter.getF32Type());
                auto new_temp_type = MemRefType::get(
                  temp_type.getShape(), temp_type.getElementType(),temp_type.getLayout().getAffineMap(),
                  MemoryKindAttr::get(temp_type.getContext(), MemoryKind::BRAM_2P));
                auto temp_buffer2 = rewriter.create<BufferOp>(loc, new_temp_type);
                temp_buffer2.setStringAttr(StringRef("reuse_buffer"));
                auto storeInitValue2 = rewriter.create<mlir::affine::AffineStoreOp>(
                                          loc, initValue2, temp_buffer2, ValueRange({}));
                
                // storeOp.setMemref(temp_buffer);
                rewriter.setInsertionPointAfter(storeOp);
                Value valueToStore = storeOp.getValue();
                AffineMap map = storeOp.getAffineMap();
                // SmallVector<Value> indices = storeOp.getIndices();

                auto newTempStoreOp = rewriter.create<AffineStoreOp>(loc, valueToStore, temp_buffer2, ValueRange({}));
                // op.dump();
                // AffineStoreOp
                rewriter.setInsertionPointAfter(band[4]);
                // rewriter.setInsertionPointAfter(band[4]);
                auto newloadOp = rewriter.create<mlir::affine::AffineLoadOp>(
                    loc, temp_buffer2, ValueRange({}));
                // op.dump();
                auto newStoreOp = rewriter.create<AffineStoreOp>(loc, newloadOp, memref, 
                                              ValueRange({
                                                band[0].getInductionVar(),
                                                band[1].getInductionVar(),
                                                band[2].getInductionVar(),
                                                band[3].getInductionVar()}));
                // rewriter.replaceOp(storeOp, newTempStoreOp);
                storeOp.erase();
                // op.dump();
                op.getOperation()->setAttr("pool_loop_opted", UnitAttr::get(op->getContext()));
                func.getOperation()->setAttr("pool_opted", UnitAttr::get(func->getContext()));
                return WalkResult::interrupt();

              // }
              

          }
      });
    }
    return success();
  }
};
} 

namespace {
struct EraseRedundantLoop : public OpRewritePattern<AffineForOp> {
  using OpRewritePattern<AffineForOp>::OpRewritePattern;

  LogicalResult matchAndRewrite(AffineForOp forOp,
                                PatternRewriter &rewriter) const override {
    
  }
};
} // namespace

namespace {
struct GenerateReuseBuffer
    : public GenerateReuseBufferBase<GenerateReuseBuffer> {
  GenerateReuseBuffer() = default;

  void runOnOperation() override {
    auto func = getOperation();
    
    auto context = func.getContext();
    mlir::RewritePatternSet patterns(context);
    patterns.add<ReuseBufferGen>(context);
    (void)applyPatternsAndFoldGreedily(func, std::move(patterns));
    patterns.clear();
    patterns.add<SimplifyPool3>(context);
    (void)applyPatternsAndFoldGreedily(func, std::move(patterns));
    patterns.clear();
    patterns.add<SimplifyPool>(context);
    (void)applyPatternsAndFoldGreedily(func, std::move(patterns));
    patterns.clear();
    patterns.add<SimplifyPool2>(context);
    (void)applyPatternsAndFoldGreedily(func, std::move(patterns));
    // llvm::outs()<<"func name:"<<func.getName()<<"\n";
    SmallVector<Operation*, 4> loopsToDelete;
    func.walk([&](AffineForOp forOp) {
      if (isa<func::FuncOp>(forOp->getParentOp())||isa<codo::TaskOp>(forOp->getParentOp())) {
        AffineLoopBand band;
        getLoopBandFromOutermost(forOp, band);
        auto bandDepth = band.size();
        if (hasReduntantAttr(forOp)) {
            loopsToDelete.push_back(forOp);
        }
        // FIXME: A more general implementation
        else if(forOp->hasAttrOfType<UnitAttr>("init_loop")||forOp->hasAttrOfType<UnitAttr>("store_loop")){
          SmallVector<unsigned, 4> permMap = {0,3,1,2};
          // forOp.dump();
          // llvm::outs()<<"func name:"<<func.getName()<<"\n";
          permuteLoops(band, permMap);
          // llvm::outs()<<"finished"<<func.getName()<<"\n";
          // auto newRoot = band[permuteLoops(band, permMap)];
          // band.clear();
          // getLoopBandFromOutermost(newRoot, band);
          // band.resize(bandDepth);
          // if (isValidLoopInterchangePermutation(band, permMap)){
          //   llvm::outs()<<"succeed"<<func.getName()<<"\n";
          //   auto newRoot = band[permuteLoops(band, permMap)];
          //   band.clear();
          //   getLoopBandFromOutermost(newRoot, band);
          //   band.resize(bandDepth);
          //   // break;
          // }
        } 
    }
    });

    // Now, safely delete the loops
    for (auto *loop : loopsToDelete) {
        loop->erase();
    }
    
  }
};
} // namespace

std::unique_ptr<Pass>
codo::createGenerateReuseBufferPass() {
  return std::make_unique<GenerateReuseBuffer>();
}