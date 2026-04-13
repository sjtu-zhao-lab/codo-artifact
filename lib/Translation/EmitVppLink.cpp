

#include "codo/Translation/EmitVppLink.h"
#include "codo/Dialect/Visitor.h"
#include "codo/Support/Utils.h"
#include "codo/Translation/Utils.h"
#include "codo/Init_All_Dialects.h"

#include "mlir/Analysis/CallGraph.h"
#include "mlir/Dialect/Affine/IR/AffineValueMap.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "mlir/IR/AffineExprVisitor.h"
#include "mlir/IR/IntegerSet.h"
#include "mlir/InitAllDialects.h"
#include "mlir/Tools/mlir-translate/Translation.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/ADT/PostOrderIterator.h"

#include "codo/Dialect/CodoDialect.h"
#include "codo/Dialect/CodoOps.h"

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Utils
std::string format_str(const std::string& str, int indent = 0, bool strip = true) {
    std::string result;
    std::string indent_str(indent, ' ');
    result = indent_str + str;
    if (strip) {
        result.erase(result.find_last_not_of(" \n\r\t") + 1);
    }
    return result;
}


namespace {
    /// This class maintains the mutable state that cross-cuts and is shared by the
    /// various emitters.
    class codoEmitterState {
    public:
        explicit codoEmitterState(raw_ostream &os) : os(os) {}
    
        // The stream to emit to.
        raw_ostream &os;
    
        bool encounteredError = false;
        unsigned currentIndent = 0;
    
        // This table contains all declared values.
        DenseMap<Value, SmallString<8>> nameTable;
    
    private:
        codoEmitterState(const codoEmitterState &) = delete;
        void operator=(const codoEmitterState &) = delete;
    };
    } // namespace
    
    namespace {
    /// This is the base class for all of the Host Emitter components.
    class codoEmitterBase {
    public:
        explicit codoEmitterBase(codoEmitterState &state)
            : state(state), os(state.os) {}
    
        InFlightDiagnostic emitError(Operation *op, const Twine &message) {
            state.encounteredError = true;
            return op->emitError(message);
        }
    
        raw_ostream &indent() { return os.indent(state.currentIndent); }
    
        void addIndent() { state.currentIndent += 2; }
        void reduceIndent() { state.currentIndent -= 2; }
    
        // All of the mutable state we are maintaining.
        codoEmitterState &state;
    
        // The stream to emit to.
        raw_ostream &os;
    
    
    private:
        codoEmitterBase(const codoEmitterBase &) = delete;
        void operator=(const codoEmitterBase &) = delete;
    };
    } // namespace

//===----------------------------------------------------------------------===//
// VppLinkEmitter Class Declaration
//===----------------------------------------------------------------------===//

namespace {
class VppLinkEmitter : public codoEmitterBase {
public:
    using operand_range = Operation::operand_range;
    explicit VppLinkEmitter(codoEmitterState &state)
      : codoEmitterBase(state) {}

    /// vpplink main emitter.
    void emitMain(ModuleOp module);

private:
    void emitMainBody(ModuleOp module);
};
} // namespace


void VppLinkEmitter::emitMainBody(ModuleOp module) {
    std::string kernel_name;
    func::FuncOp topfunc;
    module.walk([&](func::FuncOp func) {
        if (func->hasAttr("top_func")) {
            topfunc = func;
            kernel_name = func.getName().str();
            return WalkResult::interrupt();
        }
        return WalkResult::advance();
    });
    // get topfunc argument
    std::vector<std::pair<std::string, std::vector<int>>> inputs;
    std::vector<std::pair<std::string, std::vector<int>>> outputs;
    int totalInputArgNum = topfunc.getNumArguments();
    for (int i = 0; i < totalInputArgNum; ++i) {
        auto arg = topfunc.getArgument(i);
        auto argType = arg.getType().cast<MemRefType>();
        if (!argType) {
            llvm::errs() << "Argument " << i << " is not a MemRefType\n";
            continue; 
        }
        std::string dtype;
        if (auto intType = argType.getElementType().dyn_cast<mlir::IntegerType>()) {
            dtype = (intType.getWidth() == 32) ? "int_32" : "int_8";
        } else if (auto floatType = argType.getElementType().dyn_cast<mlir::FloatType>()) {
            dtype = (floatType.getWidth() == 32) ? "float_32" : "float_64";
        } else {
            llvm::errs() << "Unsupported element type for argument " << i << "\n";
            continue;
        }
        std::vector<int> shape;
        for (size_t j = 0; j < argType.getShape().size(); ++j) {
            shape.push_back(argType.getShape()[j]);
        }
        if (topfunc.getArgAttr(i, "codo.io") == StringAttr::get(topfunc.getContext(), "h2d")) {
            inputs.push_back({dtype, shape});
        } else {
            outputs.push_back({dtype, shape});
        }
    }


    
    size_t global_i = 0;
    // Generate in/out buffers
    for (size_t i = 0; i < inputs.size(); ++i) {
        std::string in_dtype = inputs[i].first;
        std::vector<int> in_shape = inputs[i].second;

        std::string in_shape_str;
        for (const auto &dim : in_shape) {
            if (!in_shape_str.empty()) in_shape_str += " * ";
            in_shape_str += std::to_string(dim);
        }

        os << format_str("sp=" + kernel_name + "_1.input" + std::to_string(i) + ":HBM[" + std::to_string(global_i%32) + "]\n", 3, false);
        global_i ++;
    }

    for (size_t i = 0; i < outputs.size(); ++i) {
        std::string out_dtype = outputs[i].first;
        std::vector<int> out_shape = outputs[i].second;

        std::string out_shape_str;
        for (const auto &dim : out_shape) {
            if (!out_shape_str.empty()) out_shape_str += " * ";
            out_shape_str += std::to_string(dim);
        }

        os << format_str("sp=" + kernel_name + "_1.output" + std::to_string(i) + ":HBM[" + std::to_string(global_i%32) + "]\n", 3, false);
        global_i ++;
    }
}


/// Top-level Host main emitter.
void VppLinkEmitter::emitMain(ModuleOp module) {
    os << "[connectivity]\n";
    emitMainBody(module);
}

//===----------------------------------------------------------------------===//
// Entry of codo-translate
//===----------------------------------------------------------------------===//
LogicalResult codo::emitVppLink(ModuleOp module, llvm::raw_ostream &os) {
  codoEmitterState state(os);
  VppLinkEmitter(state).emitMain(module);
  return failure(state.encounteredError);
}

void codo::registerEmitVppLinkTranslation() {
  static TranslateFromMLIRRegistration toVppLink(
      "emit-vpp-link", "Emit Vpp Link cfg file", emitVppLink,
      [&](DialectRegistry &registry) {
        // clang-format off
        registry.insert<
          mlir::codo::CodoDialect,
          mlir::func::FuncDialect,
          mlir::arith::ArithDialect,
          mlir::tensor::TensorDialect,
          mlir::scf::SCFDialect,
          mlir::affine::AffineDialect,
          mlir::math::MathDialect,
          mlir::memref::MemRefDialect,
          mlir::linalg::LinalgDialect,
          mlir::ml_program::MLProgramDialect,
          mlir::cf::ControlFlowDialect
        >();
        // clang-format on
      });
}