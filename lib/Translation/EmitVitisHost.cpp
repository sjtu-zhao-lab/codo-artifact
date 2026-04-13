

#include "codo/Translation/EmitVitisHost.h"
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
static std::string format_str(const std::string& str, int indent = 0, bool strip = true) {
    std::string result;
    std::string indent_str(indent, ' ');
    result = indent_str + str;
    if (strip) {
        result.erase(result.find_last_not_of(" \n\r\t") + 1);
    }
    return result;
}

//===----------------------------------------------------------------------===//
// Some Base Classes
//===----------------------------------------------------------------------===//

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
// VitisHostEmitter Class Declaration
//===----------------------------------------------------------------------===//

namespace {
class VitisHostEmitter : public codoEmitterBase {
public:
    using operand_range = Operation::operand_range;
    explicit VitisHostEmitter(codoEmitterState &state)
      : codoEmitterBase(state) {}

    /// host main emitter.
    void emitMain(ModuleOp module);

private:
    void emitDescAndHeader();
    void emitDeviceInfo();
    void emitMainBody(ModuleOp module);
};
} // namespace

void VitisHostEmitter::emitDescAndHeader() {
  os << R"XXX(
//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for Vitis Host.
//
//===----------------------------------------------------------------------===//

#include "xcl2.hpp"
#include <iostream>
#include <vector>
using namespace std;

  )XXX";
}

void VitisHostEmitter::emitDeviceInfo() {
    std::string kernel_name = "kernel";
    os << R"XXX(
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <XCLBIN File>" << std::endl;
        return EXIT_FAILURE;
    }

    std::string binaryFile = argv[1];
    cl_int err;
    cl::Context context;
    cl::CommandQueue q;
    cl::Program program;

    auto devices = xcl::get_xil_devices();
    auto fileBuf = xcl::read_binary_file(binaryFile);
    cl::Program::Binaries bins{{fileBuf.data(), fileBuf.size()}};
    bool valid_device = false;
    
    for (unsigned int i = 0; i < devices.size(); i++) {
        // for (auto device : devices) {
        auto device = devices[i];
        // Creating Context and Command Queue for selected Device
        OCL_CHECK(err, context = cl::Context(device, nullptr, nullptr, nullptr, &err));
        OCL_CHECK(err, q = cl::CommandQueue(context, device, CL_QUEUE_PROFILING_ENABLE, &err));
        std::cout << "Trying to program device[" << i << "]: " << device.getInfo<CL_DEVICE_NAME>() << std::endl;
        OCL_CHECK(err, program = cl::Program(context, {device}, bins, nullptr, &err));
        if (err != CL_SUCCESS) {
            std::cout << "Failed to program device[" << i << "] with xclbin file!\n";
        } else {
            std::cout << "Device[" << i << "]: program successful!\n";
            valid_device = true;
    )XXX";
    os << "\n";
    os << format_str("OCL_CHECK(err, kernel = cl::Kernel(program, \"" + kernel_name + "\", &err));", 12, false);
    os << R"XXX(
            break; // we break because we found a valid device
        }
    }
    if (!valid_device) {
        std::cout << "Failed to program any device found, exit!\n";
        exit(EXIT_FAILURE);
    }
    )XXX";
    
}

void VitisHostEmitter::emitMainBody(ModuleOp module) {
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

    os << format_str("// Allocate Memory in Host Memory\n", 0, false);


    // TODO emit power

    os << format_str(R"(
    void query_power(xrt::device &dev) {
        while (keep_running) {
            auto dev_info = dev.get_info<xrt::info::device::electrical>();

            auto bdf = dev.get_info<xrt::info::device::bdf>();
            std::cout << bdf << std::endl;

            std::regex watts_regex(R"%%(\"power_consumption_watts\"\s*:\s*\"([0-9.]+)\")%%");
            std::smatch matches;

            if (std::regex_search(dev_info, matches, watts_regex)) {
                std::string power_consumption_watts = matches[1];
                std::cout << "Power consumption (watts): " << power_consumption_watts << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::nanoseconds(10));
        }
    }
    )", 0);


    // TODO emit HBM configs


    

    // Generate in/out buffers
    for (size_t i = 0; i < inputs.size(); ++i) {
        std::string in_dtype = inputs[i].first;
        std::vector<int> in_shape = inputs[i].second;

        std::string in_shape_str;
        for (const auto &dim : in_shape) {
            if (!in_shape_str.empty()) in_shape_str += " * ";
            in_shape_str += std::to_string(dim);
        }

        os << format_str("size_t size_bytes_in" + std::to_string(i) + " = sizeof(" + in_dtype + ") * " + in_shape_str + ";\n", 4, false);
        os << format_str("std::vector<" + in_dtype + ", aligned_allocator<" + in_dtype + "> > input" + std::to_string(i) + "(" + in_shape_str + ");\n", 4, false);
    }

    for (size_t i = 0; i < outputs.size(); ++i) {
        std::string out_dtype = outputs[i].first;
        std::vector<int> out_shape = outputs[i].second;

        std::string out_shape_str;
        for (const auto &dim : out_shape) {
            if (!out_shape_str.empty()) out_shape_str += " * ";
            out_shape_str += std::to_string(dim);
        }

        os << format_str("size_t size_bytes_out" + std::to_string(i) + " = sizeof(" + out_dtype + ") * " + out_shape_str + ";\n", 4, false);
        os << format_str("std::vector<" + out_dtype + ", aligned_allocator<" + out_dtype + "> > output" + std::to_string(i) + "(" + out_shape_str + ");\n", 4, false);
    }

    // allocate buffer in global memory
    os << "\n";
    os << format_str("// Allocate Buffer in Global Memory\n", 4, false);

    for (size_t i = 0; i < inputs.size(); ++i) {
        os << format_str("OCL_CHECK(err, cl::Buffer buffer_in" + std::to_string(i) + "(context, CL_MEM_USE_HOST_PTR | CL_MEM_READ_ONLY, size_bytes_in" + std::to_string(i) + ", input" + std::to_string(i) + ".data(), &err));\n", 4, false);
    }
    
    for (size_t i = 0; i < outputs.size(); ++i) {
        os << format_str("OCL_CHECK(err, cl::Buffer buffer_out" + std::to_string(i) + "(context, CL_MEM_USE_HOST_PTR | CL_MEM_WRITE_ONLY, size_bytes_out" + std::to_string(i) + ", output" + std::to_string(i) + ".data(), &err));\n", 4, false);
    }
    
    // set kernel arguments
    os << "\n";
    os << format_str("// Set kernel arguments\n", 4, false);

    for (size_t i = 0; i < inputs.size(); ++i) {
        os << format_str("OCL_CHECK(err, err = kernel.setArg(" + std::to_string(i) + ", buffer_in" + std::to_string(i) + "));\n", 4, false);
    }

    for (size_t i = 0; i < outputs.size(); ++i) {
        os << format_str("OCL_CHECK(err, err = kernel.setArg(" + std::to_string(inputs.size() + i) + ", buffer_out" + std::to_string(i) + "));\n", 4, false);
    }
    
    // copy input data to device global memory
    os << "\n";
    os << format_str("// Copy input data to device global memory\n", 4, false);
    std::string buf_str;
    for (size_t i = 0; i < inputs.size(); ++i) {
        if (!buf_str.empty()) buf_str += ", ";
        buf_str += "buffer_in" + std::to_string(i);
    }
    os << format_str("OCL_CHECK(err, err = q.enqueueMigrateMemObjects({" + buf_str + "}, 0 /* 0 means from host*/));\n", 4, false);
    os << format_str(R"(
    cl::Event event;
    uint64_t nstimestart, nstimeend;
    std::cout << "|-------------------------+-------------------------|"
              << "| Kernel                  |    Wall-Clock Time (ns) |"
              << "|-------------------------+-------------------------|";
    )", 0);

    os << "\n\n";
    os << format_str("// Launch the Kernel\n", 4, false);
    os << format_str("OCL_CHECK(err, err = q.enqueueTask(kernel, nullptr, &event));\n", 4, false);

    buf_str.clear();
    for (size_t i = 0; i < outputs.size(); ++i) {
        if (!buf_str.empty()) buf_str += ", ";
        buf_str += "buffer_out" + std::to_string(i);
    }
    if (!buf_str.empty()) {
        os << format_str("// Copy Result from Device Global Memory to Host Local Memory\n", 4, false);
        os << format_str("OCL_CHECK(err, err = q.enqueueMigrateMemObjects({" + buf_str + "}, CL_MIGRATE_MEM_OBJECT_HOST));\n", 4, false);
    }
    os << format_str("q.finish();\n", 4, false);

    // Timing
    os << format_str(
        R"(
    // Get the execution time
    OCL_CHECK(err, err = event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_START, &nstimestart));
    OCL_CHECK(err, err = event.getProfilingInfo<uint64_t>(CL_PROFILING_COMMAND_END, &nstimeend));
    auto exe_time = nstimeend - nstimestart;
        )", 0);

    os << format_str("std::cout << \"| \" << std::left << std::setw(24) << \"" + kernel_name + " \"\n", 0, false);
    os << format_str("<< \"|\" << std::right << std::setw(24) << exe_time << \" |\\n\";\n", 14, false);
    os << format_str(R"(
    std::cout << "|-------------------------+-------------------------|";
    std::cout << "Note: Wall Clock Time is meaningful for real hardware execution << only, not for emulation.";
    std::cout << "Please refer to profile summary for kernel execution time for << hardware emulation.";
    std::cout << "TEST PASSED";
        )", 0);
    os << "\n";
    os << format_str("return EXIT_SUCCESS;\n", 4, false);
}


/// Top-level Host main emitter.
void VitisHostEmitter::emitMain(ModuleOp module) {
    emitDescAndHeader();
    os << "int main(int argc, char** argv) {\n";
    emitDeviceInfo();
    emitMainBody(module);
    os << "}\n";
}

//===----------------------------------------------------------------------===//
// Entry of codo-translate
//===----------------------------------------------------------------------===//
LogicalResult codo::emitVitisHost(ModuleOp module, llvm::raw_ostream &os) {
  codoEmitterState state(os);
  VitisHostEmitter(state).emitMain(module);
  return failure(state.encounteredError);
}

void codo::registerEmitVitisHostTranslation() {
  static TranslateFromMLIRRegistration toVitisHost(
      "emit-vitis-host", "Emit Vitis Host C code", emitVitisHost,
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