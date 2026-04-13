#ifndef CODO_TRANSFORMS_PASSES_H
#define CODO_TRANSFORMS_PASSES_H

#include "mlir/IR/BuiltinOps.h"
#include "mlir/Pass/Pass.h"
#include "codo/Init_All_Dialects.h"
// #include "codo/Dialect/CodoOps.h"
#include <memory>
namespace mlir {
class Pass;
namespace func {
class FuncOp;
} // namespace func
} // namespace mlir

namespace mlir {
namespace codo {

// struct FuncDependency {
//     func::FuncOp consumer; // 被依赖的函数
//     unsigned producerArgIndex;          // 当前函数的参数索引
//     unsigned consumerArgIndex;       // 依赖函数的参数索引
// };

// extern llvm::DenseMap<func::FuncOp, SmallVector<FuncDependency, 4>> producerToConsumers;
// extern llvm::DenseMap<func::FuncOp, SmallVector<FuncDependency, 4>> consumerToProducers;
/// Fusion mode to attempt. The default mode `Greedy` does both
/// producer-consumer and sibling fusion.
enum AffineFusionMode { Greedy, ProducerConsumer, Sibling };
// Linalg-level passes
std::unique_ptr<Pass> createCreateDataflowFromLinalgPass(std::string topFunc = "top_func");
std::unique_ptr<Pass> createCreateDataflowFromAffinePass();

// Graph-level passes
std::unique_ptr<Pass> createGraphPartitionPass();
std::unique_ptr<Pass> createBalanceDataflowNodePass();
std::unique_ptr<Pass> createBufferizeDataflowPass();


std::unique_ptr<Pass> createStreamDataflowTaskPass();

std::unique_ptr<Pass> createLowerDataflowPass(bool splitExternalAccess = true);


std::unique_ptr<Pass> createEliminateTopfuncargMultiConsumerPass();
std::unique_ptr<Pass> createEliminateMultiConsumerPass();
std::unique_ptr<Pass> createEliminateMultiProducerPass();
std::unique_ptr<Pass> createLegalizeDataflowPass();
std::unique_ptr<Pass> createFuncArgPlacementPass();

std::unique_ptr<Pass> createEliminateViolationPass();

std::unique_ptr<Pass> createEliminateRedundantArrayPass();

std::unique_ptr<Pass>
createScheduleDataflowNodePass(bool ignoreViolations = false);

std::unique_ptr<Pass> createConvertDataflowToFuncPass(bool splitExternalAccess = true);

std::unique_ptr<Pass> createFuncPreprocessPass(std::string topFunc = "top_func");

/// Loop-level passes.
std::unique_ptr<Pass> createAffineLoopTransformationPass();

std::unique_ptr<Pass> createAffineLoopOrderOptPass();

std::unique_ptr<Pass> createAffineLoopReorderPass();

std::unique_ptr<Pass> createAffineLoopPerfectionPass();
std::unique_ptr<Pass> createAffineMMFIFOPass();
std::unique_ptr<Pass> createLoopLevelDSEPass(int dseMaxLoopParallelismFactor = 4);
std::unique_ptr<Pass> createLoopLevelDSE_v1Pass(int dseMaxLoopParallelismFactor = 4, int balance_degree = 0, int downscale_degree = 0);
std::unique_ptr<Pass> createFIFOornotPass();

std::unique_ptr<Pass> createAffineLoopTilingPass(unsigned loopTileSize = 1);

// /// Creates a loop fusion pass which fuses affine loop nests at the top-level of
// /// the operation the pass is created on according to the type of fusion
// /// specified in `fusionMode`. Buffers of size less than or equal to
// /// `localBufSizeThreshold` are promoted to memory space `fastMemorySpace`.
std::unique_ptr<Pass> createAffineLoopFusionPass(
    double computeToleranceThreshold = 0.3, unsigned fastMemorySpace = 0,
    uint64_t localBufSizeThreshold = 0, bool maximalFusion = false,
    enum AffineFusionMode fusionMode = AffineFusionMode::Greedy);

/// Creates a loop fusion pass which fuses affine loop nests at the top-level of
/// the operation the pass is created on according to the type of fusion
/// specified in `fusionMode`. Buffers of size less than or equal to
/// `localBufSizeThreshold` are promoted to memory space `fastMemorySpace`.
// std::unique_ptr<Pass>
// createAffineLoopFusionPass(unsigned fastMemorySpace = 0,
//                      uint64_t localBufSizeThreshold = 0,
//                      bool maximalFusion = false,
//                      enum affineFusionMode fusionMode = affineFusionMode::Greedy);

std::unique_ptr<Pass>
createAffineLoopUnrollJamPass(unsigned loopUnrollFactor = 1,
                              bool unrollPointLoopOnly = false);

std::unique_ptr<Pass>
createGenerateReuseBufferPass();

// std::unique_ptr<Pass> createFuseSoftmaxAttentionPass();

// Memory-level passes

std::unique_ptr<Pass> createArrayPartitionPass(unsigned threshold = 1024);

std::unique_ptr<Pass>
createSpecifyBufferTypePass(unsigned threshold = 1024,
                              bool placeExternalBuffer = true);

std::unique_ptr<Pass>
createLowerCopyToAffinePass(bool internalCopyOnly = false);

std::unique_ptr<Pass> createMemoryTransferBetweenDRAMAndSRAMPass();
std::unique_ptr<Pass> createQuantizationPass();

// std::unique_ptr<Pass> createStreamOptPass();

std::unique_ptr<Pass>
createDesignSpaceExplorePass(std::string dseTargetSpec = "", int dseMaxParallelismFactor = 32, int dseAdjustParallelismCnt = 3, float dseAdjustParallelismFactor = 1.8);

std::unique_ptr<Pass> createQoREstimationPass(std::string qorTargetSpec = "");



// verify passes
std::unique_ptr<Pass> createCreateWeightBinsPass(
  bool keepWeights = true,
  std::string topFuncName = "forward"
);
std::unique_ptr<Pass> createCreateHostPass();
std::unique_ptr<Pass> createRemoveRedundantOpsPass();

/// Registers all codo passes
void registerCodoGraphPasses();
void registerCodoMMPasses();
void registerCodoCppPasses();
void registerCodoLLMPasses();
void registerVerifyPasses();
void registerCodoPasses();

#define GEN_PASS_CLASSES
#include "codo/Transforms/Passes.h.inc"

} // namespace codo
} // namespace mlir

#endif // CODO_TRANSFORMS_PASSES_H