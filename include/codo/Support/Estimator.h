#ifndef CODO_TRANSFORMS_ESTIMATOR_H
#define CODO_TRANSFORMS_ESTIMATOR_H

#include "mlir/Dialect/Affine/Analysis/AffineAnalysis.h"
#include "mlir/IR/Dominance.h"
#include "codo/Dialect/Visitor.h"
#include "codo/Support/Utils.h"
#include "codo/Init_All_Dialects.h"
#include "llvm/Support/JSON.h"

namespace mlir {
namespace codo {

// Get the operator name to latency/DSP usage mapping.
void getLatencyMap(llvm::json::Object *config,
                   llvm::StringMap<int64_t> &latencyMap);
void getDspUsageMap(llvm::json::Object *config,
                    llvm::StringMap<int64_t> &dspUsageMap);

//===----------------------------------------------------------------------===//
// codoEstimator Class Declaration
//===----------------------------------------------------------------------===//

class codoEstimator
    : public HLSCppVisitorBase<codoEstimator, bool, int64_t> {
public:
  explicit codoEstimator(llvm::StringMap<int64_t> &latencyMap,
                             llvm::StringMap<int64_t> &dspUsageMap,
                             bool depAnalysis)
      : latencyMap(latencyMap), dspUsageMap(dspUsageMap),
        depAnalysis(depAnalysis) {}

  // Entry for estimating function and loop.
  void estimateFunc(func::FuncOp func);
  void estimateLoop(affine::AffineForOp loop, func::FuncOp func);

  using HLSCppVisitorBase::visitOp;
  bool visitUnhandledOp(Operation *op, int64_t begin) {
    // Default latency of any unhandled operation is 0.
    return setTiming(op, begin, begin, 0, 0), true;
  }

  bool visitOp(affine::AffineForOp op, int64_t begin);
  bool visitOp(affine::AffineIfOp op, int64_t begin);
  bool visitOp(scf::IfOp op, int64_t begin);
  bool visitOp(func::CallOp op, int64_t begin);
  bool visitOp(affine::AffineLoadOp op, int64_t begin) {
    return estimateLoadStoreTiming(op, begin), true;
  }
  bool visitOp(affine::AffineStoreOp op, int64_t begin) {
    return estimateLoadStoreTiming(op, begin), true;
  }
  bool visitOp(memref::LoadOp op, int64_t begin) {
    return setTiming(op, begin, begin + 2, 2, 1), true;
  }
  bool visitOp(memref::StoreOp op, int64_t begin) {
    return setTiming(op, begin, begin + 1, 1, 1), true;
  }
  bool visitOp(memref::CopyOp op, int64_t begin) {
    auto type = op.getTarget().getType().cast<MemRefType>();
    return setTiming(op, begin, begin + type.getNumElements(), 1, 1), true;
  }

  /// Handle operations with profiled latency.
#define HANDLE(OPTYPE, KEYNAME)                                                \
  bool visitOp(OPTYPE op, int64_t begin) {                                     \
    auto latency = latencyMap[KEYNAME] + 1;                                    \
    setTiming(op, begin, begin + latency, latency, 1);                         \
    for (unsigned i = 0; i < latency; ++i)                                     \
      ++numOperatorMap[begin + i][KEYNAME];                                    \
    ++totalNumOperatorMap[KEYNAME];                                            \
    return true;                                                               \
  }
  HANDLE(arith::AddFOp, "fadd");
  HANDLE(arith::SubFOp, "fadd");
  HANDLE(arith::MulFOp, "fmul");
  HANDLE(arith::DivFOp, "fdiv");
  HANDLE(arith::CmpFOp, "fcmp");
  HANDLE(math::ExpOp, "fexp");
#undef HANDLE

private:
  /// LoadOp and StoreOp related methods.
  void getPartitionIndices(Operation *op);
  void estimateLoadStoreTiming(Operation *op, int64_t begin);

  /// AffineForOp related methods.
  int64_t getResMinII(int64_t begin, int64_t end, MemAccessesMap &map);
  int64_t getDepMinII(int64_t II, func::FuncOp func, MemAccessesMap &map);
  int64_t getDepMinII(int64_t II, affine::AffineForOp forOp, MemAccessesMap &map);

  /// Block scheduler and estimator.
  ResourceAttr calculateResource(Operation *funcOrLoop);
  TimingAttr estimateBlock(Block &block, int64_t begin = 0);
  void reverseTiming(Block &block);
  void initEstimator(Block &block);

  // Hold the memory ports information.
  struct MemPortInfo {
    unsigned rdPort = 0;
    unsigned wrPort = 0;
    unsigned rdwrPort = 0;

    SmallVector<affine::MemRefAccess, 2> rdAccesses;
  };

  // For storing memory port information of all partitions indexed by the
  // {schedule_level, memref}.
  using MemPortInfos = std::vector<MemPortInfo>;
  using MemPortInfosMap = DenseMap<int64_t, DenseMap<Value, MemPortInfos>>;
  MemPortInfosMap memPortInfosMap;

  // For storing the number of each operator indexed by the schedule level.
  using NumOperatorMap = DenseMap<int64_t, llvm::StringMap<int64_t>>;
  NumOperatorMap numOperatorMap;
  llvm::StringMap<int64_t> totalNumOperatorMap;

  // Store the operator name to latency/DSP usage mapping.
  llvm::StringMap<int64_t> &latencyMap;
  llvm::StringMap<int64_t> &dspUsageMap;

  DominanceInfo DT;
  bool depAnalysis = true;
};

} // namespace codo
} // namespace mlir

#endif // CODO_TRANSFORMS_ESTIMATOR_H
