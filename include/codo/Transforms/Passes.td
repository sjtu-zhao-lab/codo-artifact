#ifndef CODO_MLIR_PASSES
#define CODO_MLIR_PASSES

include "mlir/Pass/PassBase.td"

// Graph-level passes

def CreateDataflowFromLinalg :
      Pass<"codo-create-dataflow-from-linalg", "func::FuncOp"> {
  let summary = "Create dataflow hierarchy from linalg";
  let constructor = "mlir::codo::createCreateDataflowFromLinalgPass()";
  let options = [
    Option<"topFunc", "top-func", "std::string", /*default=*/"\"main\"",
           "The top function for HLS synthesis">
  ];
}
def CreateDataflowFromAffine :
      Pass<"codo-create-dataflow-from-affine", "func::FuncOp"> {
  let summary = "Create dataflow hierarchy from affine loops";
  let constructor = "mlir::codo::createCreateDataflowFromAffinePass()";
}
def BalanceDataflowNode :
      Pass<"codo-balance-dataflow-node", "func::FuncOp"> {
  let summary = "Balance dataflow nodes";
  let constructor = "mlir::codo::createBalanceDataflowNodePass()";
}
def BufferizeDataflow : Pass<"codo-bufferize-dataflow", "func::FuncOp"> {
  let summary = "Bufferize dataflow operations";
  let constructor = "mlir::codo::createBufferizeDataflowPass()";
}


def GraphPartition : Pass<"codo-graph-partition", "func::FuncOp"> {
  let summary = "Graph partition pass";
  let constructor = "mlir::codo::createGraphPartitionPass()";
}

def LowerCopyToAffine : Pass<"codo-lower-copy-to-affine", "func::FuncOp"> {
  let summary = "Convert copy and assign to affine loops";
  let constructor = "mlir::codo::createLowerCopyToAffinePass()";

  let options = [
    Option<"internalCopyOnly", "internal-copy-only", "bool",
           /*default=*/"false", "only convert copy between internal buffers">
  ];
}

def StreamDataflowTask : Pass<"codo-stream-dataflow-task", "func::FuncOp"> {
  let summary = "Stream dataflow tasks";
  let constructor = "mlir::codo::createStreamDataflowTaskPass()";
}

def LowerDataflow : Pass<"codo-lower-dataflow", "func::FuncOp"> {
  let summary = "Lower dataflow from task level to node level";
  let constructor = "mlir::codo::createLowerDataflowPass()";

  let options = [
    Option<"splitExternalAccess", "split-external-access", "bool",
           /*default=*/"true", "whether split external memory accesses">
  ];
}
def ScheduleDataflowNode :
      Pass<"codo-schedule-dataflow-node", "func::FuncOp"> {
  let summary = "Schedule dataflow nodes";
  let constructor = "mlir::codo::createScheduleDataflowNodePass()";

  let options = [
    Option<"ignoreViolations", "ignore-violations", "bool",
           /*default=*/"false", "Ignore multi-consumer or producer violations">
  ];
}

def EliminateTopfuncargMultiConsumer :
      Pass<"codo-eliminate-topfuncarg-multi-consumer", "func::FuncOp"> {
  let summary = "Eliminate topfuncarg-multi-consumer violations";
  let description = [{
    This pass will insert explicit fork nodes to eliminate topfuncarg-multi-consumers.
  }];
  let constructor = "mlir::codo::createEliminateTopfuncargMultiConsumerPass()";
}


def EliminateMultiConsumer :
      Pass<"codo-eliminate-multi-consumer", "func::FuncOp"> {
  let summary = "Eliminate multi-consumer violations";
  let description = [{
    This pass will insert explicit fork nodes to eliminate multi-consumers.
  }];
  let constructor = "mlir::codo::createEliminateMultiConsumerPass()";
}

def EliminateMultiProducer :
      Pass<"codo-eliminate-multi-producer", "func::FuncOp"> {
  let summary = "Try to eliminate multi-producer violations";
  let constructor = "mlir::codo::createEliminateMultiProducerPass()";
}

def EliminateViolation :
      Pass<"codo-eliminate-violation", "func::FuncOp"> {
  let summary = "Try to eliminate fine-grained read-write violations";
  let constructor = "mlir::codo::createEliminateViolationPass()";
}

def ConvertDataflowToFunc :
      Pass<"codo-convert-dataflow-to-func", "ModuleOp"> {
  let summary = "Convert dataflow to function dialect";
  let constructor = "mlir::codo::createConvertDataflowToFuncPass()";

  let options = [
    Option<"splitExternalAccess", "split-external-access", "bool",
           /*default=*/"true", "whether split external memory accesses">
  ];
}


def FuncPreprocess : Pass<"codo-func-preprocess", "func::FuncOp"> {
  let summary = "Preprocess the functions subsequent codo optimizations";
  let constructor = "mlir::codo::createFuncPreprocessPass()";

  let options = [
    Option<"topFunc", "top-func", "std::string", /*default=*/"\"main\"",
           "The top function for HLS synthesis">
  ];
}

def LegalizeDataflow :
      Pass<"codo-legalize-dataflow", "func::FuncOp"> {
  let summary = "Legalize Dataflow";
  let description = [{
    This pass will guarantee that all the stream buffers are written and read only once.
  }];
  let constructor = "mlir::codo::createLegalizeDataflowPass()";
}

// def FuncArgPlacement : Pass<"codo-func-arg-opt", "func::FuncOp"> {
//   let summary = "Efficiently internalizes inout function arguments used as channels in a dataflow region.";

//   let description = [{
//     This pass identifies top-level function arguments that are used as both
//     an input and an output (a channel) within an `hls.dataflow` operation.
//     It refactors the function by:
//     1. Creating a local `memref.alloca` for each such channel.
//     2. Replacing all uses of the function argument with the new alloca.
//     3. Erasing the argument from the function's signature.

//     This makes the code compliant with HLS tools that forbid using top-level
//     arguments as internal dataflow channels. 
//   }];

//   let constructor = "mlir::codo::createFuncArgPlacementPass()";
// }

// Loop-level passes
//===----------------------------------------------------------------------===//
// Loop-related Passes
//===----------------------------------------------------------------------===//

// def AffineLoopFusion : Pass<"codo-affine-loop-fusion", "func::FuncOp"> {
//   let summary = "Fuse affine loop nests";
//   let description = [{
//     This pass performs fusion of loop nests using a slicing-based approach. It
//     combines two fusion strategies: producer-consumer fusion and sibling fusion.
//     Producer-consumer fusion is aimed at fusing pairs of loops where the first
//     one writes to a memref that the second reads. Sibling fusion targets pairs
//     of loops that share no dependences between them but that load from the same
//     memref. The fused loop nests, when possible, are rewritten to access
//     significantly smaller local buffers instead of the original memref's, and
//     the latter are often either completely optimized away or contracted. This
//     transformation leads to enhanced locality and lower memory footprint through
//     the elimination or contraction of temporaries/intermediate memref's. These
//     benefits are sometimes achieved at the expense of redundant computation
//     through a cost model that evaluates available choices such as the depth at
//     which a source slice should be materialized in the designation slice.
//   }];
//   let constructor = "mlir::codo::createAffineLoopFusionPass()";

//   let options = [
//     Option<"computeToleranceThreshold", "fusion-compute-tolerance", "double",
//            /*default=*/"0.30f", "Fractional increase in additional computation "
//                                 "tolerated while fusing">,
//     Option<"fastMemorySpace", "fusion-fast-mem-space", "unsigned",
//            /*default=*/"0",
//            "Faster memory space number to promote fusion buffers to">,
//     Option<"localBufSizeThreshold", "fusion-local-buf-threshold", "uint64_t",
//            /*default=*/"0", "Threshold size (KiB) for promoting local buffers "
//                             "to fast memory space">,
//     Option<"maximalFusion", "fusion-maximal", "bool", /*default=*/"false",
//            "Enables maximal loop fusion">,
//     Option<"affineFusionMode", "mode", "enum AffineFusionMode",
//            "AffineFusionMode::Greedy", "fusion mode to attempt",
//            "llvm::cl::values(clEnumValN(AffineFusionMode::Greedy,"
//            " \"greedy\", \"Perform greedy fusion\"), "
//            "clEnumValN( AffineFusionMode::ProducerConsumer, "
//            "\"producer\", \"Perform only producer-consumer fusion\"), "
//            "clEnumValN( AffineFusionMode::Sibling, "
//            "\"sibling\", \"Perform only sibling fusion\"))">,
//     ];
// }

def AffineLoopFusion : Pass<"codo-affine-loop-fusion"> {
  let summary = "Fuse affine loop nests";
  let description = [{
    This pass performs fusion of loop nests using a slicing-based approach. The
    transformation works on an MLIR `Block` granularity and applies to all
    blocks of the pass is run on. It combines two fusion strategies:
    producer-consumer fusion and sibling fusion. Producer-consumer fusion is
    aimed at fusing pairs of loops where the first one writes to a memref that
    the second reads. Sibling fusion targets pairs of loops that share no
    dependences between them but that load from the same memref. The fused loop
    nests, when possible, are rewritten to access significantly smaller local
    buffers instead of the original memref's, and the latter are often either
    completely optimized away or contracted. This transformation leads to
    enhanced locality and lower memory footprint through the elimination or
    contraction of temporaries/intermediate memref's. These benefits are
    sometimes achieved at the expense of redundant computation through a cost
    model that evaluates available choices such as the depth at which a source
    slice should be materialized in the designation slice.

    Example 1: Producer-consumer fusion.
    Input:
    ```mlir
    func.func @producer_consumer_fusion(%arg0: memref<10xf32>, %arg1: memref<10xf32>) {
      %0 = memref.alloc() : memref<10xf32>
      %1 = memref.alloc() : memref<10xf32>
      %cst = arith.constant 0.000000e+00 : f32
      affine.for %arg2 = 0 to 10 {
        affine.store %cst, %0[%arg2] : memref<10xf32>
        affine.store %cst, %1[%arg2] : memref<10xf32>
      }
      affine.for %arg2 = 0 to 10 {
        %2 = affine.load %0[%arg2] : memref<10xf32>
        %3 = arith.addf %2, %2 : f32
        affine.store %3, %arg0[%arg2] : memref<10xf32>
      }
      affine.for %arg2 = 0 to 10 {
        %2 = affine.load %1[%arg2] : memref<10xf32>
        %3 = arith.mulf %2, %2 : f32
        affine.store %3, %arg1[%arg2] : memref<10xf32>
      }
      return
    }
    ```
    Output:
    ```mlir
    func.func @producer_consumer_fusion(%arg0: memref<10xf32>, %arg1: memref<10xf32>) {
      %0 = memref.alloc() : memref<1xf32>
      %1 = memref.alloc() : memref<1xf32>
      %cst = arith.constant 0.000000e+00 : f32
      affine.for %arg2 = 0 to 10 {
        affine.store %cst, %0[0] : memref<1xf32>
        affine.store %cst, %1[0] : memref<1xf32>
        %2 = affine.load %1[0] : memref<1xf32>
        %3 = arith.mulf %2, %2 : f32
        affine.store %3, %arg1[%arg2] : memref<10xf32>
        %4 = affine.load %0[0] : memref<1xf32>
        %5 = arith.addf %4, %4 : f32
        affine.store %5, %arg0[%arg2] : memref<10xf32>
      }
      return
    }
    ```

    Example 2: Sibling fusion.
    Input:
    ```mlir
    func.func @sibling_fusion(%arg0: memref<10x10xf32>, %arg1: memref<10x10xf32>,
                         %arg2: memref<10x10xf32>, %arg3: memref<10x10xf32>,
                         %arg4: memref<10x10xf32>) {
      affine.for %arg5 = 0 to 3 {
        affine.for %arg6 = 0 to 3 {
          %0 = affine.load %arg0[%arg5, %arg6] : memref<10x10xf32>
          %1 = affine.load %arg1[%arg5, %arg6] : memref<10x10xf32>
          %2 = arith.mulf %0, %1 : f32
          affine.store %2, %arg3[%arg5, %arg6] : memref<10x10xf32>
        }
      }
      affine.for %arg5 = 0 to 3 {
        affine.for %arg6 = 0 to 3 {
          %0 = affine.load %arg0[%arg5, %arg6] : memref<10x10xf32>
          %1 = affine.load %arg2[%arg5, %arg6] : memref<10x10xf32>
          %2 = arith.addf %0, %1 : f32
          affine.store %2, %arg4[%arg5, %arg6] : memref<10x10xf32>
        }
      }
      return
    }
    ```
    Output:
    ```mlir
    func.func @sibling_fusion(%arg0: memref<10x10xf32>, %arg1: memref<10x10xf32>,
                         %arg2: memref<10x10xf32>, %arg3: memref<10x10xf32>,
                         %arg4: memref<10x10xf32>) {
      affine.for %arg5 = 0 to 3 {
        affine.for %arg6 = 0 to 3 {
          %0 = affine.load %arg0[%arg5, %arg6] : memref<10x10xf32>
          %1 = affine.load %arg1[%arg5, %arg6] : memref<10x10xf32>
          %2 = arith.mulf %0, %1 : f32
          affine.store %2, %arg3[%arg5, %arg6] : memref<10x10xf32>
          %3 = affine.load %arg0[%arg5, %arg6] : memref<10x10xf32>
          %4 = affine.load %arg2[%arg5, %arg6] : memref<10x10xf32>
          %5 = arith.addf %3, %4 : f32
          affine.store %5, %arg4[%arg5, %arg6] : memref<10x10xf32>
        }
      }
      return
    }
    ```
  }];
  let constructor = "mlir::codo::createAffineLoopFusionPass()";
  let options = [
    Option<"computeToleranceThreshold", "fusion-compute-tolerance", "double",
           /*default=*/"0.30f", "Fractional increase in additional computation "
                                "tolerated while fusing">,
    Option<"fastMemorySpace", "fusion-fast-mem-space", "unsigned",
           /*default=*/"0",
           "Faster memory space number to promote fusion buffers to">,
    Option<"localBufSizeThreshold", "fusion-local-buf-threshold", "uint64_t",
           /*default=*/"0", "Threshold size (KiB) for promoting local buffers "
                            "to fast memory space">,
    Option<"maximalFusion", "fusion-maximal", "bool", /*default=*/"false",
           "Enables maximal loop fusion">,
    Option<"affineFusionMode", "mode", "enum AffineFusionMode",
           "AffineFusionMode::Greedy", "fusion mode to attempt",
           "llvm::cl::values(clEnumValN(AffineFusionMode::Greedy,"
           " \"greedy\", \"Perform greedy (both producer-consumer and sibling)  fusion\"), "
           "clEnumValN( AffineFusionMode::ProducerConsumer, "
           "\"producer\", \"Perform only producer-consumer fusion\"), "
           "clEnumValN( AffineFusionMode::Sibling, "
           "\"sibling\", \"Perform only sibling fusion\"))">,
    ];
  let dependentDialects = ["memref::MemRefDialect"];
}

def AffineLoopOrderOpt :
      Pass<"codo-affine-loop-order-opt", "func::FuncOp"> {
  let summary = "Optimize the order of affine loop nests";
  let description = [{
    This pass will optimize the order of perfect affine loop nests through
    polyhedral-based dependency analysis. The objective of this pass is to
    maximize the distance of loop-carried dependencies.
  }];
  let constructor = "mlir::codo::createAffineLoopOrderOptPass()";
}

def EliminateRedundantArray :
      Pass<"codo-eliminate-redundant-array", "func::FuncOp"> {
  let summary = "Try to eliminate redundant arrays in dataflow regions";
  let constructor = "mlir::codo::createEliminateRedundantArrayPass()";
}


def AffineLoopReorder :
      Pass<"codo-affine-loop-reorder", "func::FuncOp"> {
  let summary = "Optimize the order of affine loop nests";
  let description = [{
    This pass will optimize the order of perfect affine loop nests through
    polyhedral-based dependency analysis. The objective of this pass is to
    maximize the distance of loop-carried dependencies.
  }];
  let constructor = "mlir::codo::createAffineLoopReorderPass()";
}

def AffineLoopTransformation : Pass<"codo-affine-loop-transformation", "ModuleOp"> {
  let summary = "Loop transformation pass";
  let constructor = "mlir::codo::createAffineLoopTransformationPass()";
}

def AffineLoopPerfection :
      Pass<"codo-affine-loop-perfection", "func::FuncOp"> {
  let summary = "Try to perfect a nested loop";
  let description = [{
    This pass will try to perfect all affine loops. Specifically, this pass will
    move operations under non-innermost loops into innermost loop and create if
    statements to ensure the correctness of the transformation.
  }];
  let constructor = "mlir::codo::createAffineLoopPerfectionPass()";
}

def AffineMMFIFO:
      Pass<"codo-affine-mm-fifo", "func::FuncOp"> {
  let summary = "Try to fifo mm";
  let description = [{
    This pass will try to create reuse buffer for mms and fifo them.
  }];
  let constructor = "mlir::codo::createAffineMMFIFOPass()";
}


def AffineLoopTiling : Pass<"codo-affine-loop-tiling", "func::FuncOp"> {
  let summary = "Tile affine loop nests and annotate point loops";
  let description = [{
    Apply the same "tile-size" to each affine loop in the nests.
  }];
  let constructor = "mlir::codo::createAffineLoopTilingPass()";

  let options = [
    Option<"tileSize", "tile-size", "unsigned", /*default=*/"1",
           "Use this tile size for all loops">
  ];
}


def AffineLoopUnrollJam :
      Pass<"codo-affine-loop-unroll-jam", "func::FuncOp"> {
  let summary = "Unroll and jam affine loop nests";
  let description = [{
    Unroll and jam from the outermost loop until the overall unroll factor
    reaches the specified "unroll-factor". Optionally, optimize the loop order
    after the unrolling.
  }];
  let constructor = "mlir::codo::createAffineLoopUnrollJamPass()";

  let options = [
    Option<"unrollFactor", "unroll-factor", "unsigned", /*default=*/"1",
           "Positive number: the factor of unrolling">,
    Option<"pointLoopOnly", "point-loop-only", "bool", /*default=*/"false",
           "Only apply unroll and jam to point loop band">
  ];
}

// def FuseSoftmaxAttention : Pass<"codo-fuse-softmax-attention", "func::FuncOp"> {
//   let summary = "fues softmax attention";
//   let description = [{
//     fues softmax attention.
//   }];
//   let constructor = "mlir::codo::createFuseSoftmaxAttentionPass()";
// }

def GenerateReuseBuffer : Pass<"codo-generate-reuse-buffer", "func::FuncOp"> {
  let summary = "Generate reuse buffer for affine loop nests";
  let constructor = "mlir::codo::createGenerateReuseBufferPass()";
}

def LoopLevelDSE :
      Pass<"codo-loop-level-dse", "ModuleOp"> {
  let summary = "Loop level DSE";
  let description = [{
    This pass will perform a simple dse for small-scale kernels
  }];
  let constructor = "mlir::codo::createLoopLevelDSEPass()";
  let options = [
    Option<"MaxLoopParallelismFactor", "max-loop-parallelism", "int",
           /*default=*/"4",
           "Max loop parallelism factor">
  ];
}

def LoopLevelDSE_v1 :
      Pass<"codo-loop-level-dse-v1", "ModuleOp"> {
  let summary = "Loop level DSE v1";
  let description = [{
    This pass will perform a simple dse for small-scale kernels
  }];
  let constructor = "mlir::codo::createLoopLevelDSE_v1Pass()";
  let options = [
    Option<"MaxLoopParallelismFactor", "dseMax-Loop-ParallelismFactor", "int",
           /*default=*/"4",
           "Max loop parallelism factor">,
    Option<"balanceDegree", "balance-degree", "int",
           /*default=*/"0",
           "Balance degree for loop parallelism adjustment, 0 means no balance, 1 means balance once, etc.">,
    Option<"downscaleDegree", "downscale-degree", "int",
           /*default=*/"0",
           "Downscale degree for loop parallelism adjustment, 0 means no downscale, 1 means downscale once, etc.">
  ];
}

  

def FIFOornot :
      Pass<"codo-loop-level-fifoornot", "ModuleOp"> {
  let summary = "Loop level FIFOornot";
  let description = [{
    3mm, attention, feedforward
  }];
  let constructor = "mlir::codo::createFIFOornotPass()";
}


// memory
def SpecifyBufferType :
      Pass<"codo-specify-buffer-type", "func::FuncOp"> {
  let summary = "Assign dataflow buffer types";
  let constructor = "mlir::codo::createSpecifyBufferTypePass()";

  let options = [
    Option<"threshold", "threshold", "unsigned", /*default=*/"1024",
           "Positive number: the threshold of placing external buffers">,
    Option<"placeExternalBuffer", "place-external-buffer", "bool",
           /*default=*/"true", "Place buffers in external buffers">
  ];
}

def MemoryTransferBetweenDRAMAndSRAM :
      Pass<"momery-transfer-between-DRAM-and-SRAM", "func::FuncOp"> {
  let summary = "Transfer memory between DRAM and SRAM";
  let constructor = "mlir::codo::createMemoryTransferBetweenDRAMAndSRAMPass()";
}

def Quantization :
      Pass<"codo-quantization", "func::FuncOp"> {
  let summary = "Quantization";
  let constructor = "mlir::codo::createQuantizationPass()";
}


def ArrayPartition : Pass<"codo-array-partition", "ModuleOp"> {
  let summary = "Apply optimized array partition strategy";
  let description = [{
    This pass will automatically search for the best array partition solution
    for each on-chip memory instance and apply the solution through changing the
    layout of the corresponding memref.
  }];
  let constructor = "mlir::codo::createArrayPartitionPass()";

  let options = [
    Option<"threshold", "threshold", "unsigned", /*default=*/"128",
           "Positive number: the threshold of using LUTRAM">
  ];
}


// def StreamOpt : Pass<"codo-stream-opt", "ModuleOp"> {
//   let summary = "Optimize stream";
//   let description = [{
//     TODO
//   }];
//   let constructor = "mlir::codo::createStreamOptPass()";
// }

def DesignSpaceExplore : Pass<"codo-dse", "ModuleOp"> {
  let summary = "Optimize HLS design at multiple abstraction level";
  let description = [{
    This pass will automatically conduct the design space exploration (DSE)
    across multiple abstraction levels. By calling methods provided by
    qor-estimation, this pass is able to rapidly obtain the QoR estimation of
    the current design point, and feed it back to the DSE engine for an
    efficient optimization convergence.
  }];
  let constructor = "mlir::codo::createDesignSpaceExplorePass()";

  let options = [
    Option<"outputPath", "output-path", "std::string",
           /*default=*/"\"./\"",
           "File path: the path for dumping the MLIR of pareto design points">,
    Option<"csvPath", "csv-path", "std::string",
           /*default=*/"\"./\"",
           "File path: the path for dumping the CSV of design spaces">,

    Option<"targetSpec", "target-spec", "std::string",
           /*default=*/"\"./config.json\"",
           "File path: target backend specifications and configurations">,


    Option<"MaxParallelismFactor", "max-parallelism", "int",
           /*default=*/"32",
           "Max parallelism factor">,
    Option<"AdjustParallelismCnt", "adjust-cnt", "int",
           /*default=*/"3",
           "Count of parallelism factor adjustment">,
    Option<"AdjustParallelismFactor", "adjust-factor", "float",
           /*default=*/"1.8",
           "Factor of parallelism factor adjustment">
  ];
}

def QoREstimation : Pass<"codo-qor-estimation", "ModuleOp"> {
  let summary = "Estimate the performance and resource utilization";
  let description = [{
    This pass will analyze the input IR and estimate the latency and resource
    utilization of HLS C++ synthesis. This pass will take all dependency and
    resource constraints and pragma settings into consideration, and conduct the
    estimation through an ALAP scheduling.
  }];
  let constructor = "mlir::codo::createQoREstimationPass()";

  let options = [
    Option<"targetSpec", "target-spec", "std::string",
           /*default=*/"\"./config.json\"",
           "File path: target backend specifications and configurations">
  ];
}

def RemoveRedundantOps : Pass<"codo-remove-redundant-ops", "ModuleOp"> {
  let summary = "Remove ml global seed";
  let constructor = "mlir::codo::createRemoveRedundantOpsPass()";
  // let dependentDialects = ["mlir::codo::dataflow::DataflowDialect"];
}


def CreateWeightBins : Pass<"codo-create-weight-bins", "ModuleOp"> {
  let summary = "Create weight bins for the DNN accelerator";
  let constructor = "mlir::codo::createCreateWeightBinsPass()";

  let options = [
    Option<"keepWeights", "keep-weights", "bool",
           /*default=*/"true", "wether to keep a DNN weights">,
    Option<"topFuncName", "top-func-name", "std::string",
           /*default=*/"\"forward\"", "name of the top function">,
  ];
  // let dependentDialects = ["mlir::codo::dataflow::DataflowDialect"];

}


def CreateHost :
      Pass<"codo-create-host", "func::FuncOp"> {
  let summary = "Creates Host file for the DNN accelerator";
  let constructor = "mlir::codo::createCreateHostPass()";
  let dependentDialects = [
    // "mlir::codo::dataflow::DataflowDialect",
    "mlir::scf::SCFDialect",
    "mlir::cf::ControlFlowDialect"
  ];
}



#endif // CODO_MLIR_PASSES