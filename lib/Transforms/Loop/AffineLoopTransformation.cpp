#include "mlir/Dialect/Affine/Analysis/AffineAnalysis.h"
#include "mlir/Dialect/Affine/Analysis/Utils.h"
#include "mlir/Dialect/Affine/LoopUtils.h"
#include "codo/Transforms/Passes.h"
#include "codo/Support/Utils.h"
#include "llvm/Support/Debug.h"
#include "codo/Init_All_Dialects.h"


#define DEBUG_TYPE "codo"

using namespace mlir;
using namespace codo;


bool applyLoopTransformation(ModuleOp &mod) {
  // std::map<std::string, hcl::CustomizationOp> customizationMap;
  // for (auto c : mod.getOps<hcl::CustomizationOp>()) {
  //   customizationMap[c.getName().str()] = c;
  // }
  // apply schedule
  for (func::FuncOp f : mod.getOps<func::FuncOp>()) {
    // applyLoopTransformationOnSingleFunction(mod, f, customizationMap);
  }
  return true;
}

namespace {
struct AffineLoopTransformation : public AffineLoopTransformationBase<AffineLoopTransformation> {
  void runOnOperation() override {
    auto mod = getOperation();
    if (!applyLoopTransformation(mod))
      return signalPassFailure();
  }
};
} // namespace

std::unique_ptr<Pass> codo::createAffineLoopTransformationPass() {
  return std::make_unique<AffineLoopTransformation>();
}
