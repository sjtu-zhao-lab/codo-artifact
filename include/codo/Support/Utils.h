#ifndef CODO_UTILS_H
#define CODO_UTILS_H

// #include "mlir/Dialect/Affine/Analysis/AffineAnalysis.h"
// #include "mlir/Dialect/Affine/Analysis/LoopAnalysis.h"
// #include "mlir/Dialect/Affine/Analysis/Utils.h"
// #include "mlir/Dialect/Affine/IR/AffineOps.h"
// #include "mlir/Dialect/Affine/IR/AffineValueMap.h"
// #include "mlir/Dialect/Func/IR/FuncOps.h"
// #include "mlir/Dialect/MemRef/IR/MemRef.h"
// #include "mlir/IR/Builders.h"
// #include "mlir/IR/DialectImplementation.h"
// #include "llvm/ADT/TypeSwitch.h"
// #include "llvm/ADT/StringExtras.h"
// #include "mlir/Transforms/InliningUtils.h"

// #include "mlir/Dialect/Linalg/IR/Linalg.h"
// #include "mlir/IR/OpBuilder.h"

#include "mlir/Dialect/Affine/Analysis/AffineAnalysis.h"
#include "mlir/Dialect/Affine/Analysis/Utils.h"
#include "mlir/Dialect/Affine/IR/AffineValueMap.h"
#include "mlir/Dialect/Linalg/IR/Linalg.h"
#include "mlir/IR/IRMapping.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/DenseMap.h"
// #include "mlir/IR/Function.h"


#include "codo/Dialect/CodoDialect.h"
#include "codo/Dialect/CodoAttributes.h"
#include "codo/Dialect/CodoOps.h"

#include "codo/Dialect/CodoInterfaces.h"
namespace mlir {
namespace codo {



// MemoryKind getMemoryKind(MemRefType type);
MemoryKind getMemoryKind(MemRefType type);
bool isRam1P(MemRefType type);
bool isRam2P(MemRefType type);
bool isRamS2P(MemRefType type);
bool isRamT2P(MemRefType type);
bool isDram(MemRefType type);
bool isUnknown(MemRefType type);


using AffineLoopBand = SmallVector<affine::AffineForOp, 8>;
using AffineLoopBands = std::vector<AffineLoopBand>;
using FactorList = SmallVector<unsigned, 8>;
using Partition = std::pair<codo::PartitionKind, int64_t>;



std::vector<std::string> split_names(const std::string &arg_names);

/// Parse loop directives.
Attribute getLoopDirective(Operation *op, std::string name);

/// Parse other attributes.
SmallVector<int64_t, 8> getIntArrayAttrValue(Operation *op, StringRef name);

/// Return the layout map of "memrefType".
AffineMap getLayoutMap(MemRefType memrefType);

// void populateBufferConversionPatterns(RewritePatternSet &patterns);
//===----------------------------------------------------------------------===//
// Loop Analysis utils
//===----------------------------------------------------------------------===//

/// Check if the lhsOp and rhsOp are in the same block. If so, return their
/// ancestors that are located at the same block. Note that in this check,
/// AffineIfOp is transparent.
std::optional<std::pair<Operation *, Operation *>> checkSameLevel(Operation *lhsOp,
                                                             Operation *rhsOp);

unsigned getCommonSurroundingLoops(Operation *A, Operation *B,
                                   AffineLoopBand *band);

/// Calculate partition factors through analyzing the "memrefType" and return
/// them in "factors". Meanwhile, the overall partition number is calculated and
/// returned as well.
int64_t getPartitionFactors(MemRefType memrefType,
                            SmallVectorImpl<int64_t> *factors = nullptr);

bool isFullyPartitioned(MemRefType memrefType);

void estimateConvLoop(affine::AffineForOp forOp, llvm::DenseMap<affine::AffineForOp, long> &latencyMap);
void distributeParallelism(llvm::DenseMap<affine::AffineForOp, long> &allLatencyMap, llvm::DenseMap<affine::AffineForOp, int> &parallelismMap, int maxParallelism = 32, int adjust_parallelism_cnt = 3, float adjust_parallelism_factor = 1.8);
func::FuncOp applyOptStrategy(func::FuncOp func, llvm::DenseMap<affine::AffineForOp, int> parallelismMap);
// void estimateConvLoop(affine::AffineForOp forOp, llvm::SmallVector<long> latencyMap);

// *****************************************************************************
/// This is method for finding the number of child loops which immediatedly
/// contained by the input operation.
unsigned getChildLoopNum(Operation *op);

/// Calculate the upper and lower bound of the affine map if possible.
std::optional<std::pair<int64_t, int64_t>> getBoundOfAffineMap(AffineMap map,
                                                          ValueRange operands);
/// Get the whole loop band given the outermost or innermost loop and return it
/// in "band". Meanwhile, the return value is the innermost or outermost loop of
/// this loop band.
affine::AffineForOp getLoopBandFromOutermost(affine::AffineForOp forOp, AffineLoopBand &band);
affine::AffineForOp getLoopBandFromInnermost(affine::AffineForOp forOp, AffineLoopBand &band);

std::optional<unsigned> getAverageTripCount(affine::AffineForOp forOp);

/// Collect all loop bands in the "block" and return them in "bands". If
/// "allowHavingChilds" is true, loop bands containing more than 1 other loop
/// bands are also collected. Otherwise, only loop bands that contains no child
/// loops are collected.
void getLoopBands(Block &block, AffineLoopBands &bands,
                  bool allowHavingChilds = false);


/// Fully unroll all loops insides of a loop block.
bool applyFullyLoopUnrolling(Block &block, unsigned maxIterNum = 10);

/// Given a tiled loop band, return true and get the tile (tile-space) loop
/// band and the point (intra-tile) loop band. If failed, return false.
bool getTileAndPointLoopBand(const AffineLoopBand &band,
                             AffineLoopBand &tileBand,
                             AffineLoopBand &pointBand);
                             
bool getParallelAndReductionLoopBand(const AffineLoopBand &band,
                                     AffineLoopBand &parallelBand,
                                     AffineLoopBand &reductionBand);


void replaceSymbolsWithInductionVars(affine::AffineStoreOp storeOp);
// void replaceSymbolsWithInductionVars(Operation *op, ValueMapping &ivMap) 

mlir::Value getMemRefWrite(affine::AffineForOp forOp);
// // Check if two loops can be fused
// bool canFuseLoops(affine::AffineForOp outerLoop, affine::AffineForOp innerLoop);

// // Perform loop fusion
// void fuseLoops(affine::AffineForOp outerLoop, affine::AffineForOp innerLoop);

void detectReadWriteConflicts(func::FuncOp func, 
                            llvm::SmallDenseMap<affine::AffineForOp, func::FuncOp> &conflictMap);
/// For storing all affine memory access operations (including AffineLoadOp, and
/// AffineStoreOp) indexed by the corresponding memref.
using MemAccessesMap = DenseMap<Value, SmallVector<Operation *, 16>>;

/// Collect all load and store operations in the block and return them in "map".
void getMemAccessesMap(Block &block, MemAccessesMap &map,
                       bool includeVectorTransfer = false);

bool areLoopsWritingToSameArray(affine::AffineForOp loop1, affine::AffineForOp loop2);

bool areLoopsWithSameLoopBounds(affine::AffineForOp loop1, affine::AffineForOp loop2, 
                                    AffineLoopBand band1, AffineLoopBand band2);

void fuseLoopsWritingToSameArray(AffineLoopBand band1, AffineLoopBand band2);

void fuseLoopsWithSameBounds(AffineLoopBand band1, AffineLoopBand band2);
/// Optimize loop order. Loops associated with memory access dependencies are
/// moved to an as outer as possible location of the input loop band. If
/// "reverse" is true, as inner as possible.
bool applyAffineLoopOrderOpt(AffineLoopBand &band,
                             ArrayRef<unsigned> permMap = {},
                             bool reverse = false);

/// Apply loop tiling to the input loop band and sink all intra-tile loops to
/// the innermost loop with the original loop order.
bool applyLoopTiling(AffineLoopBand &band, FactorList tileList,
                     bool loopNormalize = true, bool annotatePointLoop = true);

/// Apply the specified array partition factors and kinds.
bool applyArrayPartition(Value array, ArrayRef<unsigned> factors,
                         ArrayRef<codo::PartitionKind> kinds,
                         bool updateFuncSignature = true,
                         unsigned threhold = 128);

bool applyAffineLoopPerfection(AffineLoopBand &band);
/// Find the suitable array partition factors and kinds for all arrays in the
/// targeted function.
bool applyAutoArrayPartition(func::FuncOp func, DenseMap<Value, SmallVector<Partition, 4>> &partitionsMap, unsigned threhold = 128);


bool applyFuncPreprocess(func::FuncOp func, bool topFunc);

/// Apply memory optimizations.
// bool applyMemoryOpts(func::FuncOp func);

/// Apply optimization strategy to a loop band. The ancestor function is also
/// passed in because the post-tiling optimizations have to take function as
/// target, e.g. canonicalizer and array partition.
bool applyOptStrategy(AffineLoopBand &band, func::FuncOp func,
                      FactorList tileList, unsigned targetII);
/// Apply memory optimizations.
// bool applyMemoryOpts(func::FuncOp func);
/// Apply optimization strategy to a function.
bool applyOptStrategy(func::FuncOp func, ArrayRef<FactorList> tileLists,
                      ArrayRef<unsigned> targetIIs);
/// Apply loop pipelining to the pipelineLoc of the input loop band, all inner
/// loops are automatically fully unrolled.
bool is_gemm(affine::AffineForOp outermostLoop);
// judge if a outermost loop is gemm
bool applyLoopPipelining(AffineLoopBand &band, unsigned pipelineLoc,
                         unsigned targetII);

/// Reduces each tile size to the largest divisor of the corresponding trip
/// count (if the trip count is known).
void adjustToDivisorsOfTripCounts(ArrayRef<affine::AffineForOp> band,
                                  SmallVectorImpl<unsigned> *tileSizes);
//===----------------------------------------------------------------------===//
// Graph Preprocess utils
//===----------------------------------------------------------------------===//

/// Wrap the operations in the block with dispatch op.
DispatchOp dispatchBlock(Block *block);


// Fuse the given operations into a new task. The new task will be created
// before the first operation or last operation and each operation will be
// inserted in order. This method always succeeds even if the resulting IR is
// invalid.
TaskOp fuseOpsIntoTask(ArrayRef<Operation *> ops, PatternRewriter &rewriter,
                       bool insertToLastOp = false);

/// Fuse multiple nodes into a new node.
NodeOp fuseNodeOps(ArrayRef<NodeOp> nodes, PatternRewriter &rewriter);

void updateFunctionWithConstants(func::FuncOp func);

/// Get the consumer/producer nodes of the given buffer expect the given op.
SmallVector<NodeOp> getConsumersExcept(Value buffer, NodeOp except);
SmallVector<NodeOp> getProducersExcept(Value buffer, NodeOp except);
SmallVector<NodeOp> getConsumers(Value buffer);
SmallVector<NodeOp> getProducers(Value buffer);
SmallVector<NodeOp> getDependentConsumers(Value buffer, NodeOp node);

/// Get the nested consumer/producer nodes of the given buffer expect the given
/// node. The corresponding buffer values are also returned.
SmallVector<std::pair<NodeOp, Value>> getNestedConsumersExcept(Value buffer,
                                                               NodeOp except);
SmallVector<std::pair<NodeOp, Value>> getNestedProducersExcept(Value buffer,
                                                               NodeOp except);
SmallVector<std::pair<NodeOp, Value>> getNestedConsumers(Value buffer);
SmallVector<std::pair<NodeOp, Value>> getNestedProducers(Value buffer);

/// Get the depth of a buffer or stream channel. Note that only if the defining
/// operation of the buffer is not a BufferOp or stream types, the returned
/// result will be 1.
unsigned getBufferDepth(Value memref);

/// Find buffer value or buffer op across the dataflow hierarchy.
Value findBuffer(Value memref);
codo::BufferLikeInterface findBufferOp(Value memref);

bool isExtBuffer(Value memref);

/// Check whether the given use has read/write semantics.
bool isRead(OpOperand &use);
bool isWritten(OpOperand &use);

void populateBufferConversionPatterns(RewritePatternSet &patterns);

//===----------------------------------------------------------------------===//
// Linalg analysis utils
//===----------------------------------------------------------------------===//

bool isElementwiseGenericOp(linalg::GenericOp op);


//===----------------------------------------------------------------------===//
// HLS resource and timing attributes
//===----------------------------------------------------------------------===//

// void loopOrderOpt();

/// Timing attribute utils.
TimingAttr getTiming(Operation *op);
void setTiming(Operation *op, TimingAttr timing);
void setTiming(Operation *op, int64_t begin, int64_t end, int64_t latency,
               int64_t interval);

/// Resource attribute utils.
ResourceAttr getResource(Operation *op);
void setResource(Operation *op, ResourceAttr resource);
void setResource(Operation *op, int64_t lut, int64_t dsp, int64_t bram);

/// Loop information attribute utils.
LoopInfoAttr getLoopInfo(Operation *op);
void setLoopInfo(Operation *op, LoopInfoAttr loopInfo);
void setLoopInfo(Operation *op, int64_t flattenTripCount, int64_t iterLatency,
                 int64_t minII);

//===----------------------------------------------------------------------===//
// codo utils
//===----------------------------------------------------------------------===//
/// Loop directives attribute utils.
LoopDirectiveAttr getLoopDirective(Operation *op);
void setLoopDirective(Operation *op, LoopDirectiveAttr loopDirective);
void setLoopDirective(Operation *op, bool pipeline, int64_t targetII,
                      bool dataflow, bool flatten);
/// Parrallel and point loop attribute utils.
bool hasParallelAttr(Operation *op);
void setParallelAttr(Operation *op);
bool hasPointAttr(Operation *op);
void setPointAttr(Operation *op);

bool hasReduntantAttr(Operation *op);
void setReduntantAttr(Operation *op);

/// Function directives attribute utils.
FuncDirectiveAttr getFuncDirective(Operation *op);
void setFuncDirective(Operation *op, FuncDirectiveAttr FuncDirective);
void setFuncDirective(Operation *op, bool pipeline, int64_t targetInterval,
                      bool dataflow);

/// Top and runtime function attribute utils.
bool hasTopFuncAttr(Operation *op);
void setTopFuncAttr(Operation *op);
bool hasRuntimeAttr(Operation *op);
void setRuntimeAttr(Operation *op);

bool is_gemm(affine::AffineForOp outermostLoop);

FPGADeviceInfoAttr getFPGADeviceInfo(Operation *op);
void setFPGADeviceInfo(Operation *op, FPGADeviceInfoAttr fpgadevice);
void setFPGADeviceInfo(Operation *op, int32_t number);

// FuncDirectiveAttr getFuncDirective(Operation *op);
// void setFuncDirective(Operation *op, FuncDirectiveAttr FuncDirective);
// void setFuncDirective(Operation *op, bool pipeline, int64_t targetInterval,
//                       bool dataflow);

} // namespace codo
} // namespace mlir

#endif // CODO_UTILS_H
