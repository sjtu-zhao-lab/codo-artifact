/*
 * Copyright HeteroCL authors. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#include "codo/Transforms/Passes.h"
#include "mlir/Pass/PassManager.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Transforms/Passes.h"
#include "mlir/Conversion/Passes.h"
#include "mlir/Dialect/Affine/Passes.h"
#include "mlir/Dialect/Arith/Transforms/Passes.h"
#include "mlir/Dialect/Bufferization/Transforms/Passes.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/Dialect/Func/Transforms/Passes.h"
#include "mlir/Dialect/Linalg/Passes.h"
#include "mlir/Dialect/MemRef/Transforms/Passes.h"
#include "mlir/Dialect/Tensor/Transforms/Passes.h"
#include "mlir/Dialect/Tosa/Transforms/Passes.h"
#include "mlir/Conversion/TensorToLinalg/TensorToLinalgPass.h"
#include "mlir/Conversion/TensorToLinalg/TensorToLinalg.h"
////////////

#include "mlir/Conversion/ArithToLLVM/ArithToLLVM.h"
#include "mlir/Conversion/ControlFlowToLLVM/ControlFlowToLLVM.h"
#include "mlir/Conversion/FuncToLLVM/ConvertFuncToLLVMPass.h"
#include "mlir/Conversion/SCFToControlFlow/SCFToControlFlow.h"
#include "mlir/Conversion/TensorToLinalg/TensorToLinalgPass.h"
#include "mlir/Dialect/Bufferization/Pipelines/Passes.h"
#include "mlir/Dialect/Bufferization/Transforms/Passes.h"
#include "mlir/Dialect/Linalg/Passes.h"
#include "mlir/InitAllDialects.h"
#include "mlir/InitAllPasses.h"
#include "mlir/Pass/PassManager.h"
// #include "mlir/Pass/PassRegistry.h"
// #include "mlir/Tools/mlir-opt/MlirOptMain.h"
// #include "mlir/Transforms/Passes.h"
#include "codo/Transforms/Passes.h"
#include "codo/Support/Utils.h"
#include "codo/Dialect/CodoOps.h"
using namespace mlir;
using namespace codo;
//===----------------------------------------------------------------------===//
// Pass registration
//===----------------------------------------------------------------------===//

/// Generate the code for registering passes.
namespace {
#define GEN_PASS_REGISTRATION
#include "codo/Transforms/Passes.h.inc"
} // end namespace


namespace {
struct CodoGraphOptions
    : public PassPipelineOptions<CodoGraphOptions> {
  Option<std::string> hlsTopFunc{
      *this, "top-func", llvm::cl::init("main"),
      llvm::cl::desc("Specify the top function of the design")};

  Option<unsigned> debugPoint{
      *this, "debug-point", llvm::cl::init(0),
      llvm::cl::desc("Stop the pipeline at the given debug point")};
  Option<unsigned> externalBufferThreshold{
      *this, "external-buffer-threshold", llvm::cl::init(1024),
      llvm::cl::desc("The threshold of placing external buffers")};

  Option<bool> placeExternalBuffer{
      *this, "place-external-buffer", llvm::cl::init(true),
      llvm::cl::desc("Place buffers in external memories")};

  Option<double> fusionTolerance{
        *this, "fusion-tolerance", llvm::cl::init(100.0),
        llvm::cl::desc("Additional computation tolerated while loop fusing "
                      "(default is 100.0)")};
  Option<unsigned> loopTileSize{
      *this, "loop-tile-size", llvm::cl::init(2),
      llvm::cl::desc("The tile size of each loop (must larger equal to 1)")};
  Option<unsigned> loopUnrollFactor{
      *this, "loop-unroll-factor", llvm::cl::init(0),
      llvm::cl::desc("The overall loop unrolling factor (set 0 to disable)")};
  Option<bool> balanceDataflow{
      *this, "balance-dataflow", llvm::cl::init(true),
      llvm::cl::desc("Whether to balance the dataflow")};
  Option<std::string> dseTargetSpec{
      *this, "target-spec", llvm::cl::init("./config.json"),
      llvm::cl::desc(
          "File path: target backend specifications and configurations")};
  Option<int> dseMaxParallelismFactor{
      *this, "max-parallelism", llvm::cl::init(1),
      llvm::cl::desc(
          "Max parallelism factor")};
  Option<int> dseMaxLoopParallelismFactor{
      *this, "max-loop-parallelism", llvm::cl::init(4),
      llvm::cl::desc(
          "Max loop parallelism factor")};
  Option<int> balanceDegree{
      *this, "balance-degree", llvm::cl::init(0),
      llvm::cl::desc(
          "Balance degree for parallelism factor adjustment")};
  Option<int> downscaleDegree{
      *this, "downscale-degree", llvm::cl::init(0),
      llvm::cl::desc(
          "Downscale degree for parallelism factor adjustment")};
  Option<int> optTileFactor{
      *this, "tile_factor", llvm::cl::init(4),
      llvm::cl::desc(
          "tiling-based optimization factor")};
  Option<std::string> optTileMode{
      *this, "tile-mode", llvm::cl::init("reduction"),
      llvm::cl::desc(
          "Determine the tiling-based optimization mode, e.g., reduction, input, or all")};
  Option<int> dseAdjustParallelismCnt{
      *this, "adjust-cnt", llvm::cl::init(3),
      llvm::cl::desc(
          "count of parallelism factor adjustment")};
  Option<float> dseAdjustParallelismFactor{
      *this, "adjust-factor", llvm::cl::init(1.8),
      llvm::cl::desc(
          "Factor of parallelism factor adjustment")};
};
} // namespace
 
void codo::registerCodoGraphPasses() {
  PassPipelineRegistration<CodoGraphOptions>(
      "codo-graph-opt",
      "Perform graph optimization for input model",
      [](OpPassManager &pm, const CodoGraphOptions &opts) {

        // Currently, we suppose that the input algorithm is 
        // described with linalg dialect rather that TOSA dialect.
        // Linalg optimization.
        // pm.addPass(codo::createRemoveRedundantOpsPass());
        // pm.addPass(codo::createCreateWeightBinsPass(false, "forward"));
        // pm.addPass(mlir::createCanonicalizerPass());
        // if (opts.debugPoint == 0)
          // return;
        pm.addPass(mlir::createLinalgElementwiseOpFusionPass());
        pm.addPass(mlir::createConvertTensorToLinalgPass());
        if (opts.debugPoint == 0)
          return;
        pm.addPass(codo::createCreateDataflowFromLinalgPass(opts.hlsTopFunc));
        pm.addPass(mlir::createCanonicalizerPass());
        if (opts.debugPoint == 1)
          return;

        // Bufferization. (need to Bufferization befor linalg->affine )
        pm.addPass(mlir::createLinalgBufferizePass());
        pm.addPass(arith::createArithBufferizePass());
        pm.addPass(tensor::createTensorBufferizePass());
        pm.addPass(func::createFuncBufferizePass());
        // pm.addPass(bufferization::createBufferResultsToOutParamsPass());
        pm.addPass(codo::createBufferizeDataflowPass());
        pm.addPass(mlir::createCanonicalizerPass());

        if (opts.debugPoint == 2)
          return;


        // Linalg to Affine conversion.
        pm.addPass(mlir::createConvertLinalgToAffineLoopsPass());
        pm.addPass(codo::createFuncPreprocessPass(opts.hlsTopFunc));
        
        pm.addPass(codo::createLowerCopyToAffinePass());
        
        pm.addPass(memref::createFoldMemRefAliasOpsPass());
        // if (opts.loopTileSize != 1)
        
        // pm.addPass(codo::createAffineLoopFusionPass(opts.fusionTolerance));
        pm.addPass(mlir::createCanonicalizerPass());
        if (opts.debugPoint == 3)
          return;

        // Select buffer types.
        pm.addPass(codo::createSpecifyBufferTypePass(
            opts.externalBufferThreshold, opts.placeExternalBuffer));

        if (opts.debugPoint == 4)
          return;

        // TODO: This pass is not working.
        // pm.addPass(codo::createCreateDataflowFromAffinePass());
        // pm.addPass(codo::createStreamDataflowTaskPass());
        pm.addPass(codo::createLowerDataflowPass());

        if (opts.debugPoint == 5)
          return;


        pm.addPass(codo::createEliminateMultiProducerPass());
        pm.addPass(codo::createEliminateMultiConsumerPass());
        // pm.addPass(codo::createBalanceDataflowNodePass());
        // pm.addPass(codo::createScheduleDataflowNodePass());
        // pm.addPass(codo::createMemoryTransferBetweenDRAMAndSRAMPass());
        pm.addPass(codo::createConvertDataflowToFuncPass());   
        pm.addPass(codo::createLowerCopyToAffinePass());

        if (opts.debugPoint == 6)
          return;

        // 
        // pm.addPass(codo::createEliminateViolationPass());
        // pm.addPass(mlir::createCanonicalizerPass());
        // pm.addPass(mlir::createCSEPass());
        pm.addPass(codo::createLegalizeDataflowPass());

        if (opts.debugPoint == 7)
          return;
        pm.addPass(codo::createGenerateReuseBufferPass());
        // pm.addPass(codo::createArrayPartitionPass());
        // pm.addPass(codo::createQuantizationPass());
        // pm.addPass(mlir::createCanonicalizerPass());
        
        if (opts.debugPoint == 8)
          return;
        // pm.addPass(codo::createAffineLoopOrderOptPass());
        
        pm.addPass(codo::createAffineLoopOrderOptPass());
        // pm.addPass(codo::createAffineLoopTilingPass(opts.loopTileSize));
        // pm.addPass(codo::createArrayPartitionPass());
        pm.addPass(mlir::createCanonicalizerPass());
        if (opts.debugPoint == 9)
          return;
        // FIXIT: Conflicts between Arraypartition and legalizedataflow
        // pm.addPass(codo::createArrayPartitionPass());
        
        if (opts.debugPoint == 10)
          return;
        pm.addPass(memref::createFoldMemRefAliasOpsPass());
        pm.addPass(mlir::createCanonicalizerPass());
        // pm.addPass(codo::createStreamOptPass());
        if (opts.debugPoint == 11)
          return;

        
        // Apply the automatic design space exploration to the top function.
        pm.addPass(codo::createDesignSpaceExplorePass(opts.dseTargetSpec, opts.dseMaxParallelismFactor, opts.dseAdjustParallelismCnt, opts.dseAdjustParallelismFactor));
        // pm.addPass(codo::createArrayPartitionPass());
        pm.addPass(mlir::createCanonicalizerPass());
        if (opts.debugPoint == 12)
          return;


        // Legalize the input program.
        // pm.addPass(codo::createGraphPartitionPass());

      });
}
void codo::registerCodoMMPasses() {
  PassPipelineRegistration<CodoGraphOptions>(
      "codo-mm-opt",
      "Perform mm optimization for input model",
      [](OpPassManager &pm, const CodoGraphOptions &opts) {

        // Currently, we suppose that the input algorithm is 
        // described with linalg dialect rather that TOSA dialect.
        // Linalg optimization.
        pm.addPass(codo::createRemoveRedundantOpsPass());
        pm.addPass(codo::createCreateWeightBinsPass(false, "forward"));
        pm.addPass(mlir::createCanonicalizerPass());
        if (opts.debugPoint == 0)
          return;
        pm.addPass(mlir::createLinalgElementwiseOpFusionPass());
        pm.addPass(mlir::createConvertTensorToLinalgPass());
        if (opts.debugPoint == 0)
          return;
        pm.addPass(codo::createCreateDataflowFromLinalgPass(opts.hlsTopFunc));
        pm.addPass(mlir::createCanonicalizerPass());
        if (opts.debugPoint == 1)
          return;

        // Bufferization. (need to Bufferization befor linalg->affine )
        pm.addPass(mlir::createLinalgBufferizePass());
        pm.addPass(arith::createArithBufferizePass());
        pm.addPass(tensor::createTensorBufferizePass());
        pm.addPass(func::createFuncBufferizePass());
        // pm.addPass(bufferization::createBufferResultsToOutParamsPass());
        pm.addPass(codo::createBufferizeDataflowPass());
        pm.addPass(mlir::createCanonicalizerPass());

        if (opts.debugPoint == 2)
          return;


        // Linalg to Affine conversion.
        pm.addPass(mlir::createConvertLinalgToAffineLoopsPass());
        pm.addPass(codo::createFuncPreprocessPass(opts.hlsTopFunc));
        
        pm.addPass(codo::createLowerCopyToAffinePass());
        
        pm.addPass(memref::createFoldMemRefAliasOpsPass());
        // if (opts.loopTileSize != 1)
        
        // pm.addPass(codo::createAffineLoopFusionPass(opts.fusionTolerance));
        pm.addPass(mlir::createCanonicalizerPass());
        if (opts.debugPoint == 3)
          return;

        // Select buffer types.
        pm.addPass(codo::createSpecifyBufferTypePass(
            opts.externalBufferThreshold, opts.placeExternalBuffer));

        if (opts.debugPoint == 4)
          return;

        // TODO: This pass is not working.
        // pm.addPass(codo::createCreateDataflowFromAffinePass());
        // pm.addPass(codo::createStreamDataflowTaskPass());
        pm.addPass(codo::createLowerDataflowPass());

        if (opts.debugPoint == 5)
          return;

        pm.addPass(codo::createEliminateMultiProducerPass());
        pm.addPass(codo::createEliminateMultiConsumerPass());
        // pm.addPass(codo::createBalanceDataflowNodePass());
        // pm.addPass(codo::createScheduleDataflowNodePass());
        pm.addPass(codo::createConvertDataflowToFuncPass());   
        pm.addPass(codo::createEliminateTopfuncargMultiConsumerPass());
        // pm.addPass(codo::createMemoryTransferBetweenDRAMAndSRAMPass());
        pm.addPass(codo::createLowerCopyToAffinePass());
        // pm.addPass(codo::createAffineLoopPerfectionPass());
        // pm.addPass(codo::createAffineLoopOrderOptPass());
        

        if (opts.debugPoint == 6)
          return;
        
        pm.addPass(codo::createEliminateViolationPass());
        pm.addPass(mlir::createCanonicalizerPass());
        pm.addPass(mlir::createCSEPass());
        // pm.addPass(codo::createLegalizeDataflowPass());

        if (opts.debugPoint == 7)
          return;

        pm.addPass(codo::createAffineMMFIFOPass());
        pm.addPass(codo::createEliminateRedundantArrayPass());
        pm.addPass(mlir::createCanonicalizerPass());
        if (opts.debugPoint == 8)
          return;
        // pm.addPass(codo::createFIFOornotPass());
        pm.addPass(mlir::createCanonicalizerPass());
        

        if(opts.debugPoint == 9)
          return;
        pm.addPass(codo::createLoopLevelDSEPass(opts.dseMaxLoopParallelismFactor));
        // pm.addPass(codo::createDesignSpaceExplorePass(opts.dseTargetSpec, opts.dseMaxParallelismFactor, opts.dseAdjustParallelismCnt, opts.dseAdjustParallelismFactor));
        pm.addPass(mlir::createCanonicalizerPass());

        if (opts.debugPoint == 10)
          return;


        // Legalize the input program.
        // pm.addPass(codo::createGraphPartitionPass());

      });
}
void codo::registerCodoCppPasses() {
  // TODO: codoGraphOptions->CPPOptions
  PassPipelineRegistration<CodoGraphOptions>(
      "codo-cpp-opt",
      "Perform kernel-level optimization for input application",
      [](OpPassManager &pm, const CodoGraphOptions &opts) {

        pm.addPass(mlir::createLinalgElementwiseOpFusionPass());
        pm.addPass(mlir::createConvertTensorToLinalgPass());
        if (opts.debugPoint == 0)
          return;
        pm.addPass(codo::createCreateDataflowFromLinalgPass(opts.hlsTopFunc));
        pm.addPass(mlir::createCanonicalizerPass());
        if (opts.debugPoint == 1)
          return;

        // Bufferization. (need to Bufferization befor linalg->affine )
        pm.addPass(mlir::createLinalgBufferizePass());
        pm.addPass(arith::createArithBufferizePass());
        pm.addPass(tensor::createTensorBufferizePass());
        pm.addPass(func::createFuncBufferizePass());
        // pm.addPass(bufferization::createBufferResultsToOutParamsPass());
        pm.addPass(codo::createBufferizeDataflowPass());
        pm.addPass(mlir::createCanonicalizerPass());

        if (opts.debugPoint == 2)
          return;


        // Linalg to Affine conversion.
        pm.addPass(mlir::createConvertLinalgToAffineLoopsPass());
        pm.addPass(codo::createFuncPreprocessPass(opts.hlsTopFunc));
        
        pm.addPass(codo::createLowerCopyToAffinePass());
        
        pm.addPass(memref::createFoldMemRefAliasOpsPass());
        // if (opts.loopTileSize != 1)
        
        // pm.addPass(codo::createAffineLoopFusionPass(opts.fusionTolerance));
        pm.addPass(mlir::createCanonicalizerPass());
        if (opts.debugPoint == 3)
          return;

        // Select buffer types.
        pm.addPass(codo::createSpecifyBufferTypePass(
            opts.externalBufferThreshold, opts.placeExternalBuffer));

        if (opts.debugPoint == 4)
          return;

        // TODO: This pass is not working.
        // pm.addPass(codo::createCreateDataflowFromAffinePass());
        // pm.addPass(codo::createStreamDataflowTaskPass());
        pm.addPass(codo::createLowerDataflowPass());

        if (opts.debugPoint == 5)
          return;


        pm.addPass(codo::createEliminateMultiProducerPass());
        pm.addPass(codo::createEliminateMultiConsumerPass());
        // pm.addPass(codo::createBalanceDataflowNodePass());
        // pm.addPass(codo::createScheduleDataflowNodePass());
        // pm.addPass(codo::createMemoryTransferBetweenDRAMAndSRAMPass());

        
        pm.addPass(codo::createConvertDataflowToFuncPass());          
        pm.addPass(codo::createLowerCopyToAffinePass());
        pm.addPass(codo::createEliminateViolationPass());
        pm.addPass(mlir::createCanonicalizerPass());
        pm.addPass(mlir::createCSEPass());
        if (opts.debugPoint == 6)
          return;
        pm.addPass(codo::createAffineLoopPerfectionPass());
        pm.addPass(codo::createAffineLoopOrderOptPass());
        // pm.addPass(mlir::createCanonicalizerPass());
        pm.addPass(codo::createAffineMMFIFOPass());
        pm.addPass(codo::createEliminateRedundantArrayPass());
        pm.addPass(mlir::createCanonicalizerPass());
        pm.addPass(codo::createLoopLevelDSE_v1Pass(opts.dseMaxLoopParallelismFactor, opts.balanceDegree, opts.downscaleDegree));
        pm.addPass(mlir::createCanonicalizerPass());
        if (opts.debugPoint == 7)
          return;
      
      });
}

void codo::registerCodoLLMPasses() {
  // TODO: codoGraphOptions->CPPOptions
  PassPipelineRegistration<CodoGraphOptions>(
      "codo-llm-opt",
      "Perform llm optimization for input application",
      [](OpPassManager &pm, const CodoGraphOptions &opts) {

        pm.addPass(mlir::createLinalgElementwiseOpFusionPass());
        pm.addPass(mlir::createConvertTensorToLinalgPass());
        if (opts.debugPoint == 0)
          return;
        pm.addPass(codo::createCreateDataflowFromLinalgPass(opts.hlsTopFunc));
        pm.addPass(mlir::createCanonicalizerPass());
        if (opts.debugPoint == 1)
          return;

        // Bufferization. (need to Bufferization befor linalg->affine )
        pm.addPass(mlir::createLinalgBufferizePass());
        pm.addPass(arith::createArithBufferizePass());
        pm.addPass(tensor::createTensorBufferizePass());
        pm.addPass(func::createFuncBufferizePass());
        // pm.addPass(bufferization::createBufferResultsToOutParamsPass());
        pm.addPass(codo::createBufferizeDataflowPass());
        pm.addPass(mlir::createCanonicalizerPass());

        if (opts.debugPoint == 2)
          return;
      
      });
}



namespace {
struct VerifyPassesOptions
    : public PassPipelineOptions<VerifyPassesOptions> {
  Option<std::string> hlsTopFunc{
      *this, "top-func", llvm::cl::init("forward"),
      llvm::cl::desc("Specify the top function of the design")};
  // Option<unsigned> debugPoint{
  //     *this, "debug-point", llvm::cl::init(0),
  //     llvm::cl::desc("Stop the pipeline at the given debug point")};
};
} // namespace

void codo::registerVerifyPasses() {
  PassPipelineRegistration<VerifyPassesOptions>(
      "codo-verify-pipeline",
      "codo-verify-pipeline",
      [](OpPassManager &pm, const VerifyPassesOptions &opts) {

        pm.addPass(codo::createRemoveRedundantOpsPass());
        pm.addPass(codo::createCreateWeightBinsPass(true, opts.hlsTopFunc));
        pm.addPass(mlir::createCanonicalizerPass());

        pm.addPass(func::createFuncBufferizePass());
        pm.addPass(bufferization::createBufferResultsToOutParamsPass());
        pm.addPass(mlir::createCanonicalizerPass());

        pm.addPass(codo::createCreateHostPass());
        // pm.addPass(mlir::createCanonicalizerPass());

      });
}

void codo::registerCodoPasses() {
  registerCodoGraphPasses();
  registerCodoMMPasses();
  registerCodoCppPasses();
  registerCodoLLMPasses();
  registerVerifyPasses();
  registerPasses();
}