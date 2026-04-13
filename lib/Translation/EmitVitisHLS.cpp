//===----------------------------------------------------------------------===//
//
// Copyright 2020-2021 The codo Authors.
//
//===----------------------------------------------------------------------===//

#include "codo/Translation/EmitVitisHLS.h"
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

#include <fstream>
#include "mlir/IR/DialectResourceBlobManager.h"
#include "mlir/IR/BuiltinAttributes.h"

// #include "mlir/IR/DialectResourceBlobManager.h" // 修复 DenseResourceElementsHandle 报错
// #include "mlir/IR/AffineExpr.h"                // 修复 Affine 表达式报错
// #include "llvm/ADT/TypeSwitch.h"               // 推荐包含，用于后续可能的 API 转换

#define DEBUG_TYPE "codo-emit-vitis-hls"

using namespace mlir;
using namespace codo;

static llvm::cl::opt<std::string> weightsPath(
  "vitis-hls-weights-dir",
  llvm::cl::desc("Directory of DNN weight binaries"),
  llvm::cl::value_desc("path"),
  llvm::cl::init(".")
);
static llvm::cl::opt<bool> isHost(
  "vitis-hls-is-host",
  llvm::cl::desc("Mark true if the target is host"),
  llvm::cl::value_desc("bool"),
  llvm::cl::init(false)
);

static llvm::cl::opt<bool> emitVitisDirectives("emit-vitis-directives",
                                               llvm::cl::init(true));
static llvm::cl::opt<bool> enforceFalseDependency("enforce-false-dependency",
                                                  llvm::cl::init(false));
static llvm::cl::opt<int64_t> limitDspNumber("limit-dsp-number",
                                             llvm::cl::init(240));
int count=0;
//===----------------------------------------------------------------------===//
// Utils
//===----------------------------------------------------------------------===//

// Type peelAxiType(Type type) {
//   if (auto axiType = type.dyn_cast<AxiType>())
//     return axiType.getElementType();
//   return type;
// }

static std::string getDataTypeName(Type type) {
  auto valType = type;

  // Handle aggregated types, including memref, vector, and stream.
  if (auto arrayType = valType.dyn_cast<MemRefType>())
    return getDataTypeName(arrayType.getElementType());
  else if (auto streamType = valType.dyn_cast<StreamType>()) {
    std::string streamName = "hls::stream<";
    streamName += getDataTypeName(streamType.getElementType());
    streamName += ">";
    return streamName;
  } else if (auto vectorType = valType.dyn_cast<VectorType>()) {
    std::string vectorName = "hls::vector<";
    vectorName += getDataTypeName(vectorType.getElementType());
    vectorName += ", " + std::to_string(vectorType.getNumElements()) + ">";
    return vectorName;
  }

  // Handle scalar types, including float and integer.
  if (valType.isa<Float32Type>())
    return "float";
  else if (valType.isa<Float64Type>())
    return "double";
  else if (valType.isa<IndexType>())
    return "int";
  else if (auto intType = valType.dyn_cast<IntegerType>()) {
    unsigned width = intType.getWidth();
    if (width == 1)
      return "bool";
    if (isHost) {
      // 在 Host 模式下，将常见位宽映射为原生 C++ 类型
      if (width <= 8) return intType.isUnsigned() ? "unsigned char" : "char";
      if (width <= 16) return intType.isUnsigned() ? "unsigned short" : "short";
      if (width <= 32) return intType.isUnsigned() ? "unsigned int" : "int" + std::to_string(width) + "_t";
      if (width <= 64) return intType.isUnsigned() ? "unsigned long long" : "long long";
      // 对于非标准位宽，在 Host 上通常也只能映射到最接近的 int
      return intType.isUnsigned() ? "unsigned int" : "int";
    }
    std::string intName = "ap_";
    intName += intType.isUnsigned() ? "u" : "";
    intName += "int<" + std::to_string(width) + ">";
    return intName;
  }
  return "unknown_type";
}

static std::string getStorageTypeAndImpl(MemoryKind kind, std::string typeStr,
                                         std::string implStr) {
  switch (kind) {
  case MemoryKind::LUTRAM_1P:
    return typeStr + "=ram_1p " + implStr + "=lutram";
  case MemoryKind::LUTRAM_2P:
    return typeStr + "=ram_2p " + implStr + "=lutram";
  case MemoryKind::LUTRAM_S2P:
    return typeStr + "=ram_s2p " + implStr + "=lutram";
  case MemoryKind::BRAM_1P:
    return typeStr + "=ram_1p " + implStr + "=bram";
  case MemoryKind::BRAM_2P:
    return typeStr + "=ram_2p " + implStr + "=bram";
  case MemoryKind::BRAM_S2P:
    return typeStr + "=ram_s2p " + implStr + "=bram";
  case MemoryKind::BRAM_T2P:
    return typeStr + "=ram_t2p " + implStr + "=bram";
  case MemoryKind::URAM_1P:
    return typeStr + "=ram_1p " + implStr + "=uram";
  case MemoryKind::URAM_2P:
    return typeStr + "=ram_2p " + implStr + "=uram";
  case MemoryKind::URAM_S2P:
    return typeStr + "=ram_s2p " + implStr + "=uram";
  case MemoryKind::URAM_T2P:
    return typeStr + "=ram_t2p " + implStr + "=uram";
  default:
    return typeStr + "=ram_t2p " + implStr + "=bram";
  }
}

static std::string getVivadoStorageTypeAndImpl(MemoryKind kind) {
  switch (kind) {
  case MemoryKind::LUTRAM_1P:
    return "ram_1p_lutram";
  case MemoryKind::LUTRAM_2P:
    return "ram_2p_lutram";
  case MemoryKind::LUTRAM_S2P:
    return "ram_s2p_lutram";
  case MemoryKind::BRAM_1P:
    return "ram_1p_bram";
  case MemoryKind::BRAM_2P:
    return "ram_2p_bram";
  case MemoryKind::BRAM_S2P:
    return "ram_s2p_bram";
  case MemoryKind::BRAM_T2P:
    return "ram_t2p_bram";
  case MemoryKind::URAM_1P:
    return "ram_1p_uram";
  case MemoryKind::URAM_2P:
    return "ram_2p_uram";
  case MemoryKind::URAM_S2P:
    return "ram_s2p_uram";
  case MemoryKind::URAM_T2P:
    return "ram_t2p_uram";
  default:
    return "ram_t2p_bram";
  }
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
/// This is the base class for all of the HLSCpp Emitter components.
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

  /// Value name management methods.
  SmallString<8> addName(Value val, bool isPtr = false);

  SmallString<8> addAlias(Value val, Value alias);

  SmallString<8> getName(Value val);

  bool isDeclared(Value val) {
    if (getName(val).empty()) {
      return false;
    } else
      return true;
  }

private:
  codoEmitterBase(const codoEmitterBase &) = delete;
  void operator=(const codoEmitterBase &) = delete;
};
} // namespace

// TODO: update naming rule.
SmallString<8> codoEmitterBase::addName(Value val, bool isPtr) {
  assert(!isDeclared(val) && "has been declared before.");

  SmallString<8> valName;
  if (isPtr)
    valName += "*";

  valName += StringRef("v" + std::to_string(state.nameTable.size()));
  state.nameTable[val] = valName;

  return valName;
}

SmallString<8> codoEmitterBase::addAlias(Value val, Value alias) {
  assert(!isDeclared(alias) && "has been declared before.");
  assert(isDeclared(val) && "hasn't been declared before.");

  auto valName = getName(val);
  state.nameTable[alias] = valName;

  return valName;
}

static SmallString<8> getConstantString(Type type, Attribute attr) {
  SmallString<8> string;
  if (type.isInteger(1)) {
    auto value = attr.cast<BoolAttr>().getValue();
    string.append(value ? "true" : "false");

  } else if (type.isIndex()) {
    string.append("(int)");
    auto value = attr.cast<IntegerAttr>().getInt();
    string.append(std::to_string(value));

  } else if (auto floatType = type.dyn_cast<FloatType>()) {
    if (floatType.getWidth() == 32) {
      string.append("(float)");
      auto value = attr.cast<FloatAttr>().getValue().convertToFloat();
      string.append(std::isfinite(value)
                        ? std::to_string(value)
                        : (value > 0 ? "INFINITY" : "-INFINITY"));
    } else if (floatType.getWidth() == 64) {
      string.append("(double)");
      auto value = attr.cast<FloatAttr>().getValue().convertToDouble();
      string.append(std::isfinite(value)
                        ? std::to_string(value)
                        : (value > 0 ? "INFINITY" : "-INFINITY"));
    }
  } else if (auto intType = type.dyn_cast<IntegerType>()) {
    std::string signedness = "";
    if (intType.getSignedness() == IntegerType::SignednessSemantics::Unsigned)
      signedness = "u";

    string.append("(");
    string.append("ap_" + signedness + "int<" +
                  std::to_string(intType.getWidth()) + ">)");

    if (intType.isSigned()) {
      auto value = attr.cast<IntegerAttr>().getValue().getSExtValue();
      string.append(std::to_string(value));
    } else if (intType.isUnsigned()) {
      auto value = attr.cast<IntegerAttr>().getValue().getZExtValue();
      string.append(std::to_string(value));
    } else {
      auto value = attr.cast<IntegerAttr>().getInt();
      string.append(std::to_string(value));
    }
  }
  return string;
}

SmallString<8> codoEmitterBase::getName(Value val) {
  // For constant scalar operations, the constant number will be returned rather
  // than the value name.
  if (auto constOp = val.getDefiningOp<arith::ConstantOp>())
    if (!constOp.getType().isa<ShapedType>()) {
      auto string = getConstantString(constOp.getType(), constOp.getValue());
      if (string.empty())
        constOp.emitOpError("constant has invalid value");
      return string;
    }
  return state.nameTable.lookup(val);
}

//===----------------------------------------------------------------------===//
// ModuleEmitter Class Declaration
//===----------------------------------------------------------------------===//

namespace {
class ModuleEmitter : public codoEmitterBase {
public:
  using operand_range = Operation::operand_range;
  explicit ModuleEmitter(codoEmitterState &state)
      : codoEmitterBase(state) {}

  /// HLS dialect operation emitters.
  void emitConstBuffer(ConstBufferOp op);
  void emitStreamChannel(StreamOp op);
  void emitStreamRead(StreamReadOp op);
  void emitStreamWrite(StreamWriteOp op);
  // void emitAxiPort(AxiPortOp op);
  // void emitPrimMul(PrimMulOp op);
  template <typename AssignOpType> void emitAssign(AssignOpType op);
  // void emitAffineSelect(hls::AffineSelectOp op);

  /// Control flow operation emitters.
  void emitCall(func::CallOp op);
  void emitReturnOp(func::ReturnOp op);

  /// SCF statement emitters.
  void emitScfFor(scf::ForOp op);
  void emitScfIf(scf::IfOp op);
  void emitScfYield(scf::YieldOp op);

  /// Affine statement emitters.
  void emitAffineFor(affine::AffineForOp op);
  void emitAffineIf(affine::AffineIfOp op);
  void emitAffineParallel(affine::AffineParallelOp op);
  void emitAffineApply(affine::AffineApplyOp op);
  template <typename OpType>
  void emitAffineMaxMin(OpType op, const char *syntax);
  void emitAffineLoad(affine::AffineLoadOp op);
  void emitAffineStore(affine::AffineStoreOp op);
  void emitAffineYield(affine::AffineYieldOp op);

  /// Vector-related statement emitters.
  // void emitVectorInit(hls::VectorInitOp op);
  // void emitInsert(vector::InsertOp op);
  // void emitExtract(vector::ExtractOp op);
  // void emitExtractElement(vector::ExtractElementOp op);
  // void emitTransferRead(vector::TransferReadOp op);
  // void emitTransferWrite(vector::TransferWriteOp op);
  // void emitBroadcast(vector::BroadcastOp);

  // Control Flow
  void emitAssertOp(cf::AssertOp op);

  /// Memref-related statement emitters.
  template <typename OpType> void emitAlloc(OpType op);
  void emitLoad(memref::LoadOp op);
  void emitStore(memref::StoreOp op);
  void emitMemCpy(memref::CopyOp op);
  template <typename OpType> void emitReshape(OpType op);

  /// Standard expression emitters.
  void emitUnary(Operation *op, const char *syntax);
  void emitBinary(Operation *op, const char *syntax);
  template <typename OpType> void emitMaxMin(OpType op, const char *syntax);

  /// Special expression emitters.
  void emitSelect(arith::SelectOp op);
  template <typename OpType> void emitConstant(OpType op);

  /// Top-level MLIR module emitter.
  void emitModule(ModuleOp module);

private:
  /// Helper to get the string indices of TransferRead/Write operations.
  template <typename TransferOpType>
  SmallVector<SmallString<8>, 4> getTransferIndices(TransferOpType op);

  /// C++ component emitters.
  void emitValue(Value val, unsigned rank = 0, bool isPtr = false,
                 bool isRef = false);
  void emitArrayDecl(Value array);
  void emitTopFuncArrayDecl(Value array);
  unsigned emitNestedLoopHeader(Value val);
  void emitNestedLoopFooter(unsigned rank);
  void emitInfoAndNewLine(Operation *op);

  /// MLIR component and HLS C++ pragma emitters.
  void emitBlock(Block &block);
  void emitLoopDirectives(Operation *op);
  void emitArrayDirectives(Value memref, bool isInterface = false);
  void emitFunctionDirectives(func::FuncOp func, ArrayRef<Value> portList);
  void emitFunction(func::FuncOp func);

  unsigned numDSPs = 0;
};
} // namespace

//===----------------------------------------------------------------------===//
// AffineEmitter Class
//===----------------------------------------------------------------------===//

namespace {
class AffineExprEmitter : public codoEmitterBase,
                          public AffineExprVisitor<AffineExprEmitter> {
public:
  using operand_range = Operation::operand_range;
  explicit AffineExprEmitter(codoEmitterState &state, unsigned numDim,
                             operand_range operands)
      : codoEmitterBase(state), numDim(numDim), operands(operands) {}

  void visitAddExpr(AffineBinaryOpExpr expr) { emitAffineBinary(expr, "+"); }
  void visitMulExpr(AffineBinaryOpExpr expr) { emitAffineBinary(expr, "*"); }
  void visitModExpr(AffineBinaryOpExpr expr) { emitAffineBinary(expr, "%"); }
  void visitFloorDivExpr(AffineBinaryOpExpr expr) {
    emitAffineBinary(expr, "/");
  }
  void visitCeilDivExpr(AffineBinaryOpExpr expr) {
    // This is super inefficient.
    os << "(";
    visit(expr.getLHS());
    os << " + ";
    visit(expr.getRHS());
    os << " - 1) / ";
    visit(expr.getRHS());
    os << ")";
  }

  void visitConstantExpr(AffineConstantExpr expr) { os << expr.getValue(); }

  void visitDimExpr(AffineDimExpr expr) {
    os << getName(operands[expr.getPosition()]);
  }
  void visitSymbolExpr(AffineSymbolExpr expr) {
    os << getName(operands[numDim + expr.getPosition()]);
  }

  /// Affine expression emitters.
  void emitAffineBinary(AffineBinaryOpExpr expr, const char *syntax) {
    os << "(";
    if (auto constRHS = expr.getRHS().dyn_cast<AffineConstantExpr>()) {
      if ((unsigned)*syntax == (unsigned)*"*" && constRHS.getValue() == -1) {
        os << "-";
        visit(expr.getLHS());
        os << ")";
        return;
      }
      if ((unsigned)*syntax == (unsigned)*"+" && constRHS.getValue() < 0) {
        visit(expr.getLHS());
        os << " - ";
        os << -constRHS.getValue();
        os << ")";
        return;
      }
    }
    if (auto binaryRHS = expr.getRHS().dyn_cast<AffineBinaryOpExpr>()) {
      if (auto constRHS = binaryRHS.getRHS().dyn_cast<AffineConstantExpr>()) {
        if ((unsigned)*syntax == (unsigned)*"+" && constRHS.getValue() == -1 &&
            binaryRHS.getKind() == AffineExprKind::Mul) {
          visit(expr.getLHS());
          os << " - ";
          visit(binaryRHS.getLHS());
          os << ")";
          return;
        }
      }
    }
    visit(expr.getLHS());
    os << " " << syntax << " ";
    visit(expr.getRHS());
    os << ")";
  }

  void emitAffineExpr(AffineExpr expr) { visit(expr); }

private:
  unsigned numDim;
  operand_range operands;
};
} // namespace

//===----------------------------------------------------------------------===//
// StmtVisitor, ExprVisitor, and PragmaVisitor Classes
//===----------------------------------------------------------------------===//

namespace {
class StmtVisitor : public HLSCppVisitorBase<StmtVisitor, bool> {
public:
  StmtVisitor(ModuleEmitter &emitter) : emitter(emitter) {}
  using HLSCppVisitorBase::visitOp;

  /// HLS dialect operations.
  bool visitOp(BufferOp op) {
    // llvm::outs() << "emitBufferOp";
    // llvm::outs() << '\n';
    if (op.getDepth() == 1)
      return emitter.emitAlloc(op), true;
    return op.emitOpError("only support depth of 1"), false;
  }
  bool visitOp(ConstBufferOp op) { return emitter.emitConstBuffer(op), true; }
  bool visitOp(StreamOp op) { return emitter.emitStreamChannel(op), true; }
  bool visitOp(StreamReadOp op) { return emitter.emitStreamRead(op), true; }
  bool visitOp(StreamWriteOp op) { return emitter.emitStreamWrite(op), true; }
  // bool visitOp(AxiBundleOp op) { return true; }
  // bool visitOp(AxiPortOp op) { return emitter.emitAxiPort(op), true; }
  // bool visitOp(AxiPackOp op) { return false; }
  // bool visitOp(PrimMulOp op) { return emitter.emitPrimMul(op), true; }
  // bool visitOp(PrimCastOp op) { return emitter.emitAssign(op), true; }
  // bool visitOp(hls::AffineSelectOp op) {
  //   return emitter.emitAffineSelect(op), true;
  // }

  /// Function operations.
  bool visitOp(func::CallOp op) { return emitter.emitCall(op), true; }
  bool visitOp(func::ReturnOp op) { return emitter.emitReturnOp(op), true; }

  /// SCF statements.
  bool visitOp(scf::ForOp op) { return emitter.emitScfFor(op), true; };
  bool visitOp(scf::IfOp op) { return emitter.emitScfIf(op), true; };
  bool visitOp(scf::ParallelOp op) { return false; };
  bool visitOp(scf::ReduceOp op) { return false; };
  bool visitOp(scf::ReduceReturnOp op) { return false; };
  bool visitOp(scf::YieldOp op) { return emitter.emitScfYield(op), true; };

  /// Affine statements.
  bool visitOp(affine::AffineForOp op) { return emitter.emitAffineFor(op), true; }
  bool visitOp(affine::AffineIfOp op) { return emitter.emitAffineIf(op), true; }
  bool visitOp(affine::AffineParallelOp op) {
    return emitter.emitAffineParallel(op), true;
  }
  bool visitOp(affine::AffineApplyOp op) { return emitter.emitAffineApply(op), true; }
  bool visitOp(affine::AffineMaxOp op) {
    return emitter.emitAffineMaxMin(op, "max"), true;
  }
  bool visitOp(affine::AffineMinOp op) {
    return emitter.emitAffineMaxMin(op, "min"), true;
  }
  bool visitOp(affine::AffineLoadOp op) { return emitter.emitAffineLoad(op), true; }
  bool visitOp(affine::AffineStoreOp op) { return emitter.emitAffineStore(op), true; }
  bool visitOp(affine::AffineVectorLoadOp op) { return false; }
  bool visitOp(affine::AffineVectorStoreOp op) { return false; }
  bool visitOp(affine::AffineYieldOp op) { return emitter.emitAffineYield(op), true; }

  // /// Vector statements.
  // bool visitOp(hls::VectorInitOp op) {
  //   return emitter.emitVectorInit(op), true;
  // }
  // bool visitOp(vector::InsertOp op) { return emitter.emitInsert(op), true; };
  // bool visitOp(vector::ExtractOp op) { return emitter.emitExtract(op), true; };
  // bool visitOp(vector::ExtractElementOp op) {
  //   return emitter.emitExtractElement(op), true;
  // };
  // bool visitOp(vector::TransferReadOp op) {
  //   return emitter.emitTransferRead(op), true;
  // };
  // bool visitOp(vector::TransferWriteOp op) {
  //   return emitter.emitTransferWrite(op), true;
  // };
  // bool visitOp(vector::BroadcastOp op) {
  //   return emitter.emitBroadcast(op), true;
  // };

  /// Memref statements.
  bool visitOp(memref::AllocOp op) { return emitter.emitAlloc(op), true; }
  bool visitOp(memref::AllocaOp op) { return emitter.emitAlloc(op), true; }
  bool visitOp(memref::LoadOp op) { return emitter.emitLoad(op), true; }
  bool visitOp(memref::StoreOp op) { return emitter.emitStore(op), true; }
  bool visitOp(memref::DeallocOp op) { return true; }
  bool visitOp(memref::CopyOp op) { return emitter.emitMemCpy(op), true; }
  // bool visitOp(memref::ReshapeOp op) { return emitter.emitReshape(op), true;
  // } bool visitOp(memref::CollapseShapeOp op) {
  //   return emitter.emitReshape(op), true;
  // }
  // bool visitOp(memref::ExpandShapeOp op) {
  //   return emitter.emitReshape(op), true;
  // }
  // bool visitOp(memref::ReinterpretCastOp op) {
  //   return emitter.emitReshape(op), true;
  // }

private:
  ModuleEmitter &emitter;
};
} // namespace

namespace {
class ExprVisitor : public HLSCppVisitorBase<ExprVisitor, bool> {
public:
  ExprVisitor(ModuleEmitter &emitter) : emitter(emitter) {}
  using HLSCppVisitorBase::visitOp;

  /// Unary expressions.
  bool visitOp(math::AbsIOp op) { return emitter.emitUnary(op, "abs"), true; }
  bool visitOp(math::AbsFOp op) { return emitter.emitUnary(op, "abs"), true; }
  bool visitOp(math::CeilOp op) { return emitter.emitUnary(op, "ceil"), true; }
  bool visitOp(math::CosOp op) { return emitter.emitUnary(op, "cos"), true; }
  bool visitOp(math::SinOp op) { return emitter.emitUnary(op, "sin"), true; }
  bool visitOp(math::TanhOp op) { return emitter.emitUnary(op, "tanh"), true; }
  bool visitOp(math::SqrtOp op) { return emitter.emitUnary(op, "sqrt"), true; }
  bool visitOp(math::RsqrtOp op) {
    return emitter.emitUnary(op, "1.0 / sqrt"), true;
  }
  bool visitOp(math::ExpOp op) { return emitter.emitUnary(op, "exp"), true; }
  bool visitOp(math::Exp2Op op) { return emitter.emitUnary(op, "exp2"), true; }
  bool visitOp(math::LogOp op) { return emitter.emitUnary(op, "log"), true; }
  bool visitOp(math::Log2Op op) { return emitter.emitUnary(op, "log2"), true; }
  bool visitOp(math::Log10Op op) {
    return emitter.emitUnary(op, "log10"), true;
  }
  bool visitOp(arith::NegFOp op) { return emitter.emitUnary(op, "-"), true; }
  bool visitOp(math::ErfOp op) { return emitter.emitUnary(op, "erf"), true; }

  /// Float binary expressions.
  bool visitOp(arith::CmpFOp op);
  bool visitOp(arith::AddFOp op) { return emitter.emitBinary(op, "+"), true; }
  bool visitOp(arith::SubFOp op) { return emitter.emitBinary(op, "-"), true; }
  bool visitOp(arith::MulFOp op) { return emitter.emitBinary(op, "*"), true; }
  bool visitOp(arith::DivFOp op) { return emitter.emitBinary(op, "/"), true; }
  bool visitOp(arith::RemFOp op) { return emitter.emitBinary(op, "%"), true; }
  bool visitOp(arith::MaximumFOp op) { return emitter.emitMaxMin(op, "max"), true; }
  bool visitOp(arith::MinimumFOp op) { return emitter.emitMaxMin(op, "min"), true; }
  bool visitOp(math::PowFOp op) { return emitter.emitMaxMin(op, "pow"), true; }
  
  // Control Flow
  bool visitOp(cf::AssertOp op) { return emitter.emitAssertOp(op), true; }

  /// Integer binary expressions.
  bool visitOp(arith::CmpIOp op);
  bool visitOp(arith::AddIOp op) { return emitter.emitBinary(op, "+"), true; }
  bool visitOp(arith::SubIOp op) { return emitter.emitBinary(op, "-"), true; }
  bool visitOp(arith::MulIOp op) { return emitter.emitBinary(op, "*"), true; }
  bool visitOp(arith::DivSIOp op) { return emitter.emitBinary(op, "/"), true; }
  bool visitOp(arith::RemSIOp op) { return emitter.emitBinary(op, "%"), true; }
  bool visitOp(arith::DivUIOp op) { return emitter.emitBinary(op, "/"), true; }
  bool visitOp(arith::RemUIOp op) { return emitter.emitBinary(op, "%"), true; }
  bool visitOp(arith::XOrIOp op) { return emitter.emitBinary(op, "^"), true; }
  bool visitOp(arith::AndIOp op) { return emitter.emitBinary(op, "&"), true; }
  bool visitOp(arith::OrIOp op) { return emitter.emitBinary(op, "|"), true; }
  bool visitOp(arith::ShLIOp op) { return emitter.emitBinary(op, "<<"), true; }
  bool visitOp(arith::ShRSIOp op) { return emitter.emitBinary(op, ">>"), true; }
  bool visitOp(arith::ShRUIOp op) { return emitter.emitBinary(op, ">>"), true; }
  bool visitOp(arith::MaxSIOp op) {
    return emitter.emitMaxMin(op, "max"), true;
  }
  bool visitOp(arith::MinSIOp op) {
    return emitter.emitMaxMin(op, "min"), true;
  }
  bool visitOp(arith::MaxUIOp op) {
    return emitter.emitMaxMin(op, "max"), true;
  }
  bool visitOp(arith::MinUIOp op) {
    return emitter.emitMaxMin(op, "min"), true;
  }

  /// Special expressions.
  bool visitOp(arith::SelectOp op) { return emitter.emitSelect(op), true; }
  bool visitOp(arith::ConstantOp op) { return emitter.emitConstant(op), true; }
  bool visitOp(arith::IndexCastOp op) { return emitter.emitAssign(op), true; }
  bool visitOp(arith::UIToFPOp op) { return emitter.emitAssign(op), true; }
  bool visitOp(arith::SIToFPOp op) { return emitter.emitAssign(op), true; }
  bool visitOp(arith::FPToUIOp op) { return emitter.emitAssign(op), true; }
  bool visitOp(arith::FPToSIOp op) { return emitter.emitAssign(op), true; }

  /// TODO: Figure out whether these ops need to be separately handled.
  bool visitOp(arith::TruncIOp op) { return emitter.emitAssign(op), true; }
  bool visitOp(arith::TruncFOp op) { return emitter.emitAssign(op), true; }
  bool visitOp(arith::ExtUIOp op) { return emitter.emitAssign(op), true; }
  bool visitOp(arith::ExtSIOp op) { return emitter.emitAssign(op), true; }
  bool visitOp(arith::ExtFOp op) { return emitter.emitAssign(op), true; }

private:
  ModuleEmitter &emitter;
};
} // namespace

bool ExprVisitor::visitOp(arith::CmpFOp op) {
  switch (op.getPredicate()) {
  case arith::CmpFPredicate::OEQ:
  case arith::CmpFPredicate::UEQ:
    return emitter.emitBinary(op, "=="), true;
  case arith::CmpFPredicate::ONE:
  case arith::CmpFPredicate::UNE:
    return emitter.emitBinary(op, "!="), true;
  case arith::CmpFPredicate::OLT:
  case arith::CmpFPredicate::ULT:
    return emitter.emitBinary(op, "<"), true;
  case arith::CmpFPredicate::OLE:
  case arith::CmpFPredicate::ULE:
    return emitter.emitBinary(op, "<="), true;
  case arith::CmpFPredicate::OGT:
  case arith::CmpFPredicate::UGT:
    return emitter.emitBinary(op, ">"), true;
  case arith::CmpFPredicate::OGE:
  case arith::CmpFPredicate::UGE:
    return emitter.emitBinary(op, ">="), true;
  default:
    op.emitError("has unsupported compare type.");
    return false;
  }
}

bool ExprVisitor::visitOp(arith::CmpIOp op) {
  switch (op.getPredicate()) {
  case arith::CmpIPredicate::eq:
    return emitter.emitBinary(op, "=="), true;
  case arith::CmpIPredicate::ne:
    return emitter.emitBinary(op, "!="), true;
  case arith::CmpIPredicate::slt:
  case arith::CmpIPredicate::ult:
    return emitter.emitBinary(op, "<"), true;
  case arith::CmpIPredicate::sle:
  case arith::CmpIPredicate::ule:
    return emitter.emitBinary(op, "<="), true;
  case arith::CmpIPredicate::sgt:
  case arith::CmpIPredicate::ugt:
    return emitter.emitBinary(op, ">"), true;
  case arith::CmpIPredicate::sge:
  case arith::CmpIPredicate::uge:
    return emitter.emitBinary(op, ">="), true;
  }
}

//===----------------------------------------------------------------------===//
// ModuleEmitter Class Definition
//===----------------------------------------------------------------------===//

/// HLS dialect operation emitters.
void ModuleEmitter::emitConstBuffer(ConstBufferOp op) {
  emitConstant(op);
  emitArrayDirectives(op.getResult(), true);
}

void ModuleEmitter::emitStreamChannel(StreamOp op) {
  indent();
  emitValue(op.getChannel());
  os << ";";
  emitInfoAndNewLine(op);
}

void ModuleEmitter::emitStreamRead(StreamReadOp op) {
  indent();
  if (op.getResult()) {
    emitValue(op.getResult());
    os << " = ";
  }
  emitValue(op.getChannel());
  os << ".read(";
  os << ");";
  emitInfoAndNewLine(op);
}

void ModuleEmitter::emitStreamWrite(StreamWriteOp op) {
  indent();
  emitValue(op.getChannel());
  os << ".write(";
  emitValue(op.getValue());
  os << ");";
  emitInfoAndNewLine(op);
}

// void ModuleEmitter::emitAxiPort(AxiPortOp op) {
//   addAlias(op.getAxi(), op.getElement());

//   // if (op.getType().isa<MemRefType, StreamType>()) {
//   indent() << "#pragma HLS interface";

//   if (op.getBundleType().getKind() == AxiKind::MM) {
//     if (isExtBuffer(op.getElement()))
//       os << " m_axi offset=slave";
//     else {
//       os << " bram ";
//       auto kind = getMemoryKind(op.getElement().getType().cast<MemRefType>());
//       os << getStorageTypeAndImpl(kind, "storage_type", "storage_impl");
//     }
//   } else if (op.getBundleType().getKind() == AxiKind::STREAM)
//     os << " axis";
//   else
//     llvm_unreachable("AXI element type must be a memref or stream");

//   os << " port=";
//   emitValue(op.getElement());
//   os << " bundle=" << op.getBundleName();
//   os << "\n";

//   if (op.getElement().getType().isa<MemRefType>())
//     emitArrayDirectives(op.getElement(), true);
//   // } else {
//   //   indent() << "#pragma HLS interface s_axilite";
//   //   os << " port=";

//   //   // TODO: This is a temporary solution.
//   //   auto name = getName(op.getElement());
//   //   if (name.front() == "*"[0])
//   //     name.erase(name.begin());
//   //   os << name;
//   //   os << " bundle=" << op.getBundleName() << "\n";
//   // }
//   // An empty line.
//   os << "\n";
// }

// void ModuleEmitter::emitPrimMul(PrimMulOp op) {
//   if (op.isPackMul()) {
//     // Declare the result C array.
//     if (!isDeclared(op.getC())) {
//       indent();
//       emitArrayDecl(op.getC());
//       os << ";\n";

//       indent() << "#pragma HLS array_partition variable=";
//       emitValue(op.getC());
//       os << " complete dim=0\n";
//     }

//     auto AIsVector = op.getA().getType().isa<VectorType>();
//     indent() << "pack_mul(";
//     emitValue(AIsVector ? op.getA() : op.getB());
//     os << ", ";
//     emitValue(AIsVector ? op.getB() : op.getA());
//     os << ", ";
//     emitValue(op.getC());
//     os << ");";
//     emitInfoAndNewLine(op);

//   } else {
//     // To ensure DSP is utilized, the two operands are casted to 16-bits integer
//     // before the multiplication.
//     auto rank = emitNestedLoopHeader(op.getC());
//     indent();
//     emitValue(op.getC(), rank);
//     os << " = (ap_int<8>)";
//     emitValue(op.getA(), rank);
//     os << " * (ap_int<8>)";
//     emitValue(op.getB(), rank);
//     os << ";";
//     emitInfoAndNewLine(op);
//     emitNestedLoopFooter(rank);

//     indent();
//     os << "#pragma HLS bind_op op=mul variable=";
//     emitValue(op.getC(), rank);
//     if (numDSPs < limitDspNumber) {
//       numDSPs++;
//       os << " impl=dsp";
//     } else
//       os << " impl=fabric";
//     os << "\n";
//   }
// }

template <typename AssignOpType>
void ModuleEmitter::emitAssign(AssignOpType op) {
  unsigned rank = emitNestedLoopHeader(op.getResult());
  indent();
  emitValue(op.getResult(), rank);
  os << " = ";
  emitValue(op.getOperand(), rank);
  os << ";";
  emitInfoAndNewLine(op);
  emitNestedLoopFooter(rank);
}

// void ModuleEmitter::emitAffineSelect(hls::AffineSelectOp op) {
//   indent();
//   emitValue(op.getResult());
//   os << " = (";
//   auto constrSet = op.getIntegerSet();
//   AffineExprEmitter constrEmitter(state, constrSet.getNumDims(),
//                                   op.getOperands());

//   // Emit all constraints.
//   unsigned constrIdx = 0;
//   for (auto &expr : constrSet.getConstraints()) {
//     constrEmitter.emitAffineExpr(expr);
//     if (constrSet.isEq(constrIdx))
//       os << " == 0";
//     else
//       os << " >= 0";

//     if (constrIdx++ != constrSet.getNumConstraints() - 1)
//       os << " && ";
//   }
//   os << ") ? ";
//   emitValue(op.getTrueValue());
//   os << " : ";
//   emitValue(op.getFalseValue());
//   os << ";";
//   emitInfoAndNewLine(op);
// }

// Control Flow Ops
void ModuleEmitter::emitAssertOp(cf::AssertOp op) {
  indent();
  os << "assert(";
  emitValue(op.getArg());
  os << " && \"" << op.getMsg() << "\");";
  emitInfoAndNewLine(op);
}

void ModuleEmitter::emitReturnOp(func::ReturnOp op) {
  indent();
  os << "return ";

  // 1. 检查操作数数量
  if (op.getNumOperands() > 1) {
    os << ";";
    // emitError(op, "cannot return more than one operand.");
    return;
  }

  // 2. 处理返回逻辑
  if (op.getNumOperands() == 1) {
    Value result = op.getOperand(0);
    auto func = op->getParentOfType<func::FuncOp>();

    // 如果当前在 main 函数里，我们通常希望返回纯粹的数字 0
    if (func.getName() == "main") {
      // 检查返回的是否是一个常量
      if (auto constOp = result.getDefiningOp<arith::ConstantOp>()) {
        if (auto intAttr = constOp.getValue().dyn_cast<IntegerAttr>()) {
          os << intAttr.getValue(); // 只输出数字，例如 "0"
        } else {
          // 如果不是整数常量，回退到原始逻辑
          emitValue(result);
        }
      } else {
        // 如果返回的是一个变量，只输出变量名（例如 v18）
        os << getName(result);
      }
    } 
  }

  os << ";";
  emitInfoAndNewLine(op);
}

/// Control flow operation emitters.
void ModuleEmitter::emitCall(func::CallOp op) {
  // Handle returned value by the callee.
  for (auto result : op.getResults()) {
    if (!isDeclared(result)) {
      indent();
      if (result.getType().isa<MemRefType>())
        emitArrayDecl(result);
      else
        emitValue(result);
      os << ";\n";
    }
  }

  // Emit the function call.
  indent() << op.getCallee() << "(";

  // Handle input arguments.
  unsigned argIdx = 0;
  for (auto arg : op.getOperands()) {
    emitValue(arg);

    if (argIdx++ != op.getNumOperands() - 1)
      os << ", ";
  }

  // Handle output arguments.
  for (auto result : op.getResults()) {
    // The address should be passed in for scalar result arguments.
    if (result.getType().isa<ShapedType>())
      os << ", ";
    else
      os << ", &";

    emitValue(result);
  }

  os << ");";
  emitInfoAndNewLine(op);
}

/// SCF statement emitters.
void ModuleEmitter::emitScfFor(scf::ForOp op) {
  indent() << "for (";
  auto iterVar = op.getInductionVar();

  // Emit lower bound.
  emitValue(iterVar);
  os << " = ";
  emitValue(op.getLowerBound());
  os << "; ";

  // Emit upper bound.
  emitValue(iterVar);
  os << " < ";
  emitValue(op.getUpperBound());
  os << "; ";

  // Emit increase step.
  emitValue(iterVar);
  os << " += ";
  emitValue(op.getStep());
  os << ") {";
  emitInfoAndNewLine(op);

  addIndent();

  emitLoopDirectives(op);
  emitBlock(*op.getBody());
  reduceIndent();

  indent() << "}\n";
}

void ModuleEmitter::emitScfIf(scf::IfOp op) {
  // Declare all values returned by scf::YieldOp. They will be further handled
  // by the scf::YieldOp emitter.
  for (auto result : op.getResults()) {
    if (!isDeclared(result)) {
      indent();
      if (result.getType().isa<MemRefType>())
        emitArrayDecl(result);
      else
        emitValue(result);
      os << ";\n";
    }
  }

  indent() << "if (";
  emitValue(op.getCondition());
  os << ") {";
  emitInfoAndNewLine(op);

  addIndent();
  emitBlock(op.getThenRegion().front());
  reduceIndent();

  if (!op.getElseRegion().empty()) {
    indent() << "} else {\n";
    addIndent();
    emitBlock(op.getElseRegion().front());
    reduceIndent();
  }

  indent() << "}\n";
}

void ModuleEmitter::emitScfYield(scf::YieldOp op) {
  if (op.getNumOperands() == 0)
    return;

  // For now, only and scf::If operations will use scf::Yield to return
  // generated values.
  if (auto parentOp = dyn_cast<scf::IfOp>(op->getParentOp())) {
    unsigned resultIdx = 0;
    for (auto result : parentOp.getResults()) {
      unsigned rank = emitNestedLoopHeader(result);
      indent();
      emitValue(result, rank);
      os << " = ";
      emitValue(op.getOperand(resultIdx++), rank);
      os << ";";
      emitInfoAndNewLine(op);
      emitNestedLoopFooter(rank);
    }
  }
}

/// Affine statement emitters.
void ModuleEmitter::emitAffineFor(affine::AffineForOp op) {
  indent() << "for (";
  auto iterVar = op.getInductionVar();

  // Emit lower bound.
  emitValue(iterVar);
  os << " = ";
  auto lowerMap = op.getLowerBoundMap();
  AffineExprEmitter lowerEmitter(state, lowerMap.getNumDims(),
                                 op.getLowerBoundOperands());
  if (lowerMap.getNumResults() == 1)
    lowerEmitter.emitAffineExpr(lowerMap.getResult(0));
  else {
    for (unsigned i = 0, e = lowerMap.getNumResults() - 1; i < e; ++i)
      os << "max(";
    lowerEmitter.emitAffineExpr(lowerMap.getResult(0));
    for (auto &expr : llvm::drop_begin(lowerMap.getResults(), 1)) {
      os << ", ";
      lowerEmitter.emitAffineExpr(expr);
      os << ")";
    }
  }
  os << "; ";

  // Emit upper bound.
  emitValue(iterVar);
  os << " < ";
  auto upperMap = op.getUpperBoundMap();
  AffineExprEmitter upperEmitter(state, upperMap.getNumDims(),
                                 op.getUpperBoundOperands());
  if (upperMap.getNumResults() == 1)
    upperEmitter.emitAffineExpr(upperMap.getResult(0));
  else {
    for (unsigned i = 0, e = upperMap.getNumResults() - 1; i < e; ++i)
      os << "min(";
    upperEmitter.emitAffineExpr(upperMap.getResult(0));
    for (auto &expr : llvm::drop_begin(upperMap.getResults(), 1)) {
      os << ", ";
      upperEmitter.emitAffineExpr(expr);
      os << ")";
    }
  }
  os << "; ";

  // Emit increase step.
  emitValue(iterVar);
  os << " += " << op.getStep() << ") {";
  emitInfoAndNewLine(op);

  addIndent();

  emitLoopDirectives(op);
  emitBlock(*op.getBody());
  reduceIndent();

  indent() << "}\n";
}

void ModuleEmitter::emitAffineIf(affine::AffineIfOp op) {
  // Declare all values returned by AffineYieldOp. They will be further
  // handled by the AffineYieldOp emitter.
  for (auto result : op.getResults()) {
    if (!isDeclared(result)) {
      indent();
      if (result.getType().isa<MemRefType>())
        emitArrayDecl(result);
      else
        emitValue(result);
      os << ";\n";
    }
  }

  indent() << "if (";
  auto constrSet = op.getIntegerSet();
  AffineExprEmitter constrEmitter(state, constrSet.getNumDims(),
                                  op.getOperands());

  // Emit all constraints.
  unsigned constrIdx = 0;
  for (auto &expr : constrSet.getConstraints()) {
    constrEmitter.emitAffineExpr(expr);
    if (constrSet.isEq(constrIdx))
      os << " == 0";
    else
      os << " >= 0";

    if (constrIdx++ != constrSet.getNumConstraints() - 1)
      os << " && ";
  }
  os << ") {";
  emitInfoAndNewLine(op);

  addIndent();
  emitBlock(*op.getThenBlock());
  reduceIndent();

  if (op.hasElse()) {
    indent() << "} else {\n";
    addIndent();
    emitBlock(*op.getElseBlock());
    reduceIndent();
  }

  indent() << "}\n";
}

void ModuleEmitter::emitAffineParallel(affine::AffineParallelOp op) {
  // Declare all values returned by AffineParallelOp. They will be further
  // handled by the AffineYieldOp emitter.
  for (auto result : op.getResults()) {
    if (!isDeclared(result)) {
      indent();
      if (result.getType().isa<MemRefType>())
        emitArrayDecl(result);
      else
        emitValue(result);
      os << ";\n";
    }
  }

  auto steps = getIntArrayAttrValue(op, op.getStepsAttrName());
  for (unsigned i = 0, e = op.getNumDims(); i < e; ++i) {
    indent() << "for (";
    auto iterVar = op.getBody()->getArgument(i);

    // Emit lower bound.
    emitValue(iterVar);
    os << " = ";
    auto lowerMap = op.getLowerBoundsValueMap().getAffineMap();
    AffineExprEmitter lowerEmitter(state, lowerMap.getNumDims(),
                                   op.getLowerBoundsOperands());
    lowerEmitter.emitAffineExpr(lowerMap.getResult(i));
    os << "; ";

    // Emit upper bound.
    emitValue(iterVar);
    os << " < ";
    auto upperMap = op.getUpperBoundsValueMap().getAffineMap();
    AffineExprEmitter upperEmitter(state, upperMap.getNumDims(),
                                   op.getUpperBoundsOperands());
    upperEmitter.emitAffineExpr(upperMap.getResult(i));
    os << "; ";

    // Emit increase step.
    emitValue(iterVar);
    os << " += " << steps[i] << ") {";
    emitInfoAndNewLine(op);

    addIndent();
  }

  emitBlock(*op.getBody());

  for (unsigned i = 0, e = op.getNumDims(); i < e; ++i) {
    reduceIndent();

    indent() << "}\n";
  }
}

void ModuleEmitter::emitAffineApply(affine::AffineApplyOp op) {
  indent();
  emitValue(op.getResult());
  os << " = ";
  auto affineMap = op.getAffineMap();
  AffineExprEmitter(state, affineMap.getNumDims(), op.getOperands())
      .emitAffineExpr(affineMap.getResult(0));
  os << ";";
  emitInfoAndNewLine(op);
}

template <typename OpType>
void ModuleEmitter::emitAffineMaxMin(OpType op, const char *syntax) {
  indent();
  emitValue(op.getResult());
  os << " = ";
  auto affineMap = op.getAffineMap();
  AffineExprEmitter affineEmitter(state, affineMap.getNumDims(),
                                  op.getOperands());
  for (unsigned i = 0, e = affineMap.getNumResults() - 1; i < e; ++i)
    os << syntax << "(";
  affineEmitter.emitAffineExpr(affineMap.getResult(0));
  for (auto &expr : llvm::drop_begin(affineMap.getResults(), 1)) {
    os << ", ";
    affineEmitter.emitAffineExpr(expr);
    os << ")";
  }
  os << ";";
  emitInfoAndNewLine(op);
}

void ModuleEmitter::emitAffineLoad(affine::AffineLoadOp op) {
  indent();
  emitValue(op.getResult());
  os << " = ";
  emitValue(op.getMemRef());
  auto affineMap = op.getAffineMap();
  AffineExprEmitter affineEmitter(state, affineMap.getNumDims(),
                                  op.getMapOperands());
  for (auto index : affineMap.getResults()) {
    os << "[";
    affineEmitter.emitAffineExpr(index);
    os << "]";
  }
  os << ";";
  emitInfoAndNewLine(op);
}

void ModuleEmitter::emitAffineStore(affine::AffineStoreOp op) {
  indent();
  emitValue(op.getMemRef());
  auto affineMap = op.getAffineMap();
  AffineExprEmitter affineEmitter(state, affineMap.getNumDims(),
                                  op.getMapOperands());
  for (auto index : affineMap.getResults()) {
    os << "[";
    affineEmitter.emitAffineExpr(index);
    os << "]";
  }
  os << " = ";
  emitValue(op.getValueToStore());
  os << ";";
  emitInfoAndNewLine(op);
}

// TODO: For now, all values created in the AffineIf region will be declared
// in the generated C++. However, values which will be returned by affine
// yield operation should not be declared again. How to "bind" the pair of
// values inside/outside of AffineIf region needs to be considered.
void ModuleEmitter::emitAffineYield(affine::AffineYieldOp op) {
  if (op.getNumOperands() == 0)
    return;

  // For now, only AffineParallel and AffineIf operations will use
  // AffineYield to return generated values.
  if (auto parentOp = dyn_cast<affine::AffineIfOp>(op->getParentOp())) {
    unsigned resultIdx = 0;
    for (auto result : parentOp.getResults()) {
      unsigned rank = emitNestedLoopHeader(result);
      indent();
      emitValue(result, rank);
      os << " = ";
      emitValue(op.getOperand(resultIdx++), rank);
      os << ";";
      emitInfoAndNewLine(op);
      emitNestedLoopFooter(rank);
    }
  } else if (auto parentOp = dyn_cast<affine::AffineParallelOp>(op->getParentOp())) {
    indent() << "if (";
    unsigned ivIdx = 0;
    for (auto iv : parentOp.getBody()->getArguments()) {
      emitValue(iv);
      os << " == 0";
      if (ivIdx++ != parentOp.getBody()->getNumArguments() - 1)
        os << " && ";
    }
    os << ") {\n";

    // When all induction values are 0, generated values will be directly
    // assigned to the current results, correspondingly.
    addIndent();
    unsigned resultIdx = 0;
    for (auto result : parentOp.getResults()) {
      unsigned rank = emitNestedLoopHeader(result);
      indent();
      emitValue(result, rank);
      os << " = ";
      emitValue(op.getOperand(resultIdx++), rank);
      os << ";";
      emitInfoAndNewLine(op);
      emitNestedLoopFooter(rank);
    }
    reduceIndent();

    indent() << "} else {\n";

    // Otherwise, generated values will be accumulated/reduced to the
    // current results with corresponding arith::AtomicRMWKind operations.
    addIndent();
    auto RMWAttrs =
        getIntArrayAttrValue(parentOp, parentOp.getReductionsAttrName());
    resultIdx = 0;
    for (auto result : parentOp.getResults()) {
      unsigned rank = emitNestedLoopHeader(result);
      indent();
      emitValue(result, rank);
      switch ((arith::AtomicRMWKind)RMWAttrs[resultIdx]) {
      case (arith::AtomicRMWKind::addf):
      case (arith::AtomicRMWKind::addi):
        os << " += ";
        emitValue(op.getOperand(resultIdx++), rank);
        break;
      case (arith::AtomicRMWKind::assign):
        os << " = ";
        emitValue(op.getOperand(resultIdx++), rank);
        break;
      case (arith::AtomicRMWKind::maximumf):
      case (arith::AtomicRMWKind::maxs):
      case (arith::AtomicRMWKind::maxu):
        os << " = max(";
        emitValue(result, rank);
        os << ", ";
        emitValue(op.getOperand(resultIdx++), rank);
        os << ")";
        break;
      case (arith::AtomicRMWKind::minimumf):
      case (arith::AtomicRMWKind::mins):
      case (arith::AtomicRMWKind::minu):
        os << " = min(";
        emitValue(result, rank);
        os << ", ";
        emitValue(op.getOperand(resultIdx++), rank);
        os << ")";
        break;
      case (arith::AtomicRMWKind::mulf):
      case (arith::AtomicRMWKind::muli):
        os << " *= ";
        emitValue(op.getOperand(resultIdx++), rank);
        break;
      case (arith::AtomicRMWKind::ori):
        os << " |= ";
        emitValue(op.getOperand(resultIdx++), rank);
        break;
      case (arith::AtomicRMWKind::andi):
        os << " &= ";
        emitValue(op.getOperand(resultIdx++), rank);
        break;
      }
      os << ";";
      emitInfoAndNewLine(op);
      emitNestedLoopFooter(rank);
    }
    reduceIndent();

    indent() << "}\n";
  }
}

/// Helper to get the string indices of TransferRead/Write operations.
template <typename TransferOpType>
SmallVector<SmallString<8>, 4>
ModuleEmitter::getTransferIndices(TransferOpType op) {
  // Get the head indices of the transfer read/write.
  SmallVector<SmallString<8>, 4> indices;
  for (auto index : op.getIndices()) {
    assert(isDeclared(index) && "index has not been declared");
    indices.push_back(getName(index));
  }
  // Construct the physical indices.
  for (unsigned i = 0, e = op.getPermutationMap().getNumResults(); i < e; ++i) {
    auto expr = op.getPermutationMap().getResult(i);
    if (auto dimExpr = expr.template dyn_cast<AffineDimExpr>())
      indices[dimExpr.getPosition()] += " + iv" + std::to_string(i);
  }
  return indices;
}

/// Helper to get the TransferRead/Write condition.
template <typename TransferOpType>
static SmallString<16>
getTransferCondition(TransferOpType op,
                     const SmallVector<SmallString<8>, 4> &indices) {
  // Figure out whether the transfer read/write could be out of bound.
  SmallVector<unsigned, 4> outOfBoundDims;
  for (unsigned i = 0, e = op.getVectorType().getRank(); i < e; ++i)
    if (!op.isDimInBounds(i))
      outOfBoundDims.push_back(i);

  // Construct the condition of transfer if required.
  SmallString<16> condition;
  for (auto i : outOfBoundDims) {
    auto expr = op.getPermutationMap().getResult(i);
    if (auto dimExpr = expr.template dyn_cast<AffineDimExpr>()) {
      auto pos = dimExpr.getPosition();
      condition += indices[pos];
      condition += " < " + std::to_string(op.getShapedType().getDimSize(pos));
      if (i != outOfBoundDims.back())
        condition += " && ";
    }
  }
  return condition;
}

// /// Vector-related statement emitters.
// void ModuleEmitter::emitVectorInit(hls::VectorInitOp op) {
//   indent();
//   emitValue(op.getResult());
//   os << ";";
//   emitInfoAndNewLine(op);
// }

// void ModuleEmitter::emitInsert(vector::InsertOp op) {
//   addAlias(op.getDest(), op.getResult());
//   indent();
//   emitValue(op.getDest());
//   // os << "[" << op.getPosition()[0].cast<IntegerAttr>().getInt() << "] = ";
//   emitValue(op.getSource());
//   os << ";";
//   emitInfoAndNewLine(op);
// }

// void ModuleEmitter::emitExtract(vector::ExtractOp op) {
//   indent();
//   emitValue(op.getResult());
//   os << " = ";
//   emitValue(op.getVector());
//   // os << "[" << op.getPosition()[0].cast<IntegerAttr>().getInt() << "];";
//   emitInfoAndNewLine(op);
// }

// void ModuleEmitter::emitExtractElement(vector::ExtractElementOp op) {
//   indent();
//   emitValue(op.getResult());
//   os << " = ";
//   emitValue(op.getVector());
//   os << "[";
//   emitValue(op.getPosition());
//   os << "];";
//   emitInfoAndNewLine(op);
// }

// void ModuleEmitter::emitTransferRead(vector::TransferReadOp op) {
//   auto rank = emitNestedLoopHeader(op.getVector());
//   auto indices = getTransferIndices(op);
//   auto condition = getTransferCondition(op, indices);

//   if (!condition.empty()) {
//     indent() << "if (" << condition << ")\n";
//     addIndent();
//   }

//   indent();
//   emitValue(op.getVector(), rank);
//   os << " = ";
//   emitValue(op.getSource());
//   for (auto index : indices)
//     os << "[" << index << "]";
//   os << ";";
//   emitInfoAndNewLine(op);

//   if (!condition.empty()) {
//     reduceIndent();
//     indent() << "else\n";
//     addIndent();

//     indent();
//     emitValue(op.getVector(), rank);
//     os << " = ";
//     emitValue(op.getPadding());
//     os << ";\n";
//     reduceIndent();
//   }
//   emitNestedLoopFooter(rank);
// }

// void ModuleEmitter::emitTransferWrite(vector::TransferWriteOp op) {
//   auto rank = emitNestedLoopHeader(op.getVector());
//   auto indices = getTransferIndices(op);
//   auto condition = getTransferCondition(op, indices);

//   if (!condition.empty()) {
//     indent() << "if (" << condition << ")\n";
//     addIndent();
//   }

//   indent();
//   emitValue(op.getSource());
//   for (auto index : indices)
//     os << "[" << index << "]";
//   os << " = ";
//   emitValue(op.getVector(), rank);
//   os << ";";
//   emitInfoAndNewLine(op);

//   if (!condition.empty())
//     reduceIndent();
//   emitNestedLoopFooter(rank);
// }

// void ModuleEmitter::emitBroadcast(vector::BroadcastOp op) {
//   auto rank = emitNestedLoopHeader(op.getVector());
//   indent();
//   emitValue(op.getVector(), rank);
//   os << " = ";
//   emitValue(op.getSource());

//   // Figure out whether each dimision is broadcast or multicast.
//   if (auto type = op.getSource().getType().dyn_cast<ShapedType>())
//     for (unsigned dim = 0, e = type.getRank(); dim < e; ++dim) {
//       if (type.getDimSize(dim) == 1)
//         os << "[0]";
//       else
//         os << "[iv" << dim + op.getType().getRank() - type.getRank() << "]";
//     }

//   os << ";";
//   emitInfoAndNewLine(op);
//   emitNestedLoopFooter(rank);
// }

/// Memref-related statement emitters.
template <typename OpType> void ModuleEmitter::emitAlloc(OpType op) {
  // A declared result indicates that the memref is output of the function, and
  // has been declared in the function signature.
  if (isDeclared(op.getResult())){
    // llvm::outs()<<"the array is declared before\n";
    return;
  }
    

  // Vitis HLS only supports static shape on-chip memory.
  if (!op.getType().hasStaticShape())
    emitError(op, "is unranked or has dynamic shape.");

  indent();
  emitArrayDecl(op.getResult());
  os << ";";
  emitInfoAndNewLine(op);
  // llvm::outs()<<"emitArrayDirectives\n";
  bool isInterface = false;
  
  if(auto buffer = dyn_cast<BufferOp>(&op)){
    if(buffer->getStringAttr()==StringRef("reuse_buffer") || buffer->getStringAttr()==StringRef("non_fifo") ){
      // llvm::outs()<<"emitArrayDirectives\n";
      isInterface = true;
    }
  }
  emitArrayDirectives(op.getResult(), isInterface);
}

void ModuleEmitter::emitLoad(memref::LoadOp op) {
  indent();
  emitValue(op.getResult());
  os << " = ";
  emitValue(op.getMemRef());
  for (auto index : op.getIndices()) {
    os << "[";
    emitValue(index);
    os << "]";
  }
  os << ";";
  emitInfoAndNewLine(op);
}

void ModuleEmitter::emitStore(memref::StoreOp op) {
  indent();
  emitValue(op.getMemRef());
  for (auto index : op.getIndices()) {
    os << "[";
    emitValue(index);
    os << "]";
  }
  os << " = ";
  emitValue(op.getValueToStore());
  os << ";";
  emitInfoAndNewLine(op);
}

void ModuleEmitter::emitMemCpy(memref::CopyOp op) {
  indent() << "memcpy(";
  emitValue(op.getTarget());
  os << ", ";
  emitValue(op.getSource());
  os << ", ";

  auto type = op.getTarget().getType().cast<MemRefType>();
  os << type.getNumElements() << " * sizeof("
     << getDataTypeName(op.getTarget().getType()) << "));";
  emitInfoAndNewLine(op);
  os << "\n";
}

template <typename OpType> void ModuleEmitter::emitReshape(OpType op) {
  auto array = op->getResult(0);
  assert(!isDeclared(array) && "has been declared before.");

  auto arrayType = array.getType().template cast<ShapedType>();
  indent() << getTypeName(arrayType) << " (*";

  // Add the new value to nameTable and emit its name.
  os << addName(array, false);
  os << ")";

  for (auto &shape : llvm::drop_begin(arrayType.getShape(), 1))
    os << "[" << shape << "]";

  os << " = (" << getTypeName(arrayType) << "(*)";
  for (auto &shape : llvm::drop_begin(arrayType.getShape(), 1))
    os << "[" << shape << "]";
  os << ") ";

  emitValue(op->getOperand(0));
  os << ";";
  emitInfoAndNewLine(op);
}

/// Standard expression emitters.
void ModuleEmitter::emitUnary(Operation *op, const char *syntax) {
  auto rank = emitNestedLoopHeader(op->getResult(0));
  indent();
  emitValue(op->getResult(0), rank);
  os << " = " << syntax << "(";
  emitValue(op->getOperand(0), rank);
  os << ");";
  emitInfoAndNewLine(op);
  emitNestedLoopFooter(rank);
}

void ModuleEmitter::emitBinary(Operation *op, const char *syntax) {
  auto rank = emitNestedLoopHeader(op->getResult(0));
  indent();
  emitValue(op->getResult(0), rank);
  os << " = ";
  emitValue(op->getOperand(0), rank);
  os << " " << syntax << " ";
  emitValue(op->getOperand(1), rank);
  os << ";";
  emitInfoAndNewLine(op);
  emitNestedLoopFooter(rank);
}

template <typename OpType>
void ModuleEmitter::emitMaxMin(OpType op, const char *syntax) {
  auto rank = emitNestedLoopHeader(op.getResult());
  indent();
  emitValue(op.getResult());
  os << " = " << syntax << "(";
  emitValue(op.getLhs(), rank);
  os << ", ";
  emitValue(op.getRhs(), rank);
  os << ");";
  emitInfoAndNewLine(op);
  emitNestedLoopFooter(rank);
}

/// Special expression emitters.
void ModuleEmitter::emitSelect(arith::SelectOp op) {
  unsigned rank = emitNestedLoopHeader(op.getResult());
  unsigned conditionRank = rank;
  if (!op.getCondition().getType().isa<ShapedType>())
    conditionRank = 0;

  indent();
  emitValue(op.getResult(), rank);
  os << " = ";
  emitValue(op.getCondition(), conditionRank);
  os << " ? ";
  // os << "(" << getTypeName(op.getTrueValue()) << ")";
  emitValue(op.getTrueValue(), rank);
  os << " : ";
  // os << "(" << getTypeName(op.getFalseValue()) << ")";
  emitValue(op.getFalseValue(), rank);
  os << ";";
  emitInfoAndNewLine(op);
  emitNestedLoopFooter(rank);
}

// template <typename OpType> void ModuleEmitter::emitConstant(OpType op) {
//   // This indicates the constant type is scalar (float, integer, or bool).
//   if (isDeclared(op.getResult()))
//     return;

//   if (auto denseAttr = op.getValue().template dyn_cast<DenseElementsAttr>()) {
//     indent();
//     emitArrayDecl(op.getResult());
//     os << " = {";
//     auto type =
//         op.getResult().getType().template cast<MemRefType>().getElementType();

//     unsigned elementIdx = 0;
//     for (auto element : denseAttr.template getValues<Attribute>()) {
//       auto string = getConstantString(type, element);
//       if (string.empty())
//         op.emitOpError("constant has invalid value");
//       os << string;
//       if (elementIdx++ != denseAttr.getNumElements() - 1)
//         os << ", ";
//     }
//     os << "};";
//     emitInfoAndNewLine(op);
//   } else
//     emitError(op, "has unsupported constant type.");
// }

template <typename OpType> 
void ModuleEmitter::emitConstant(OpType op) {
  // 如果该常量已经声明过，直接返回
  if (isDeclared(op.getResult()))
    return;

  auto valueAttr = op.getValue();

  // --- 1. 处理 DenseResourceElementsAttr (即 MLIR 中的 dense_resource) ---
  if (auto resourceAttr = valueAttr.template dyn_cast<DenseResourceElementsAttr>()) {
    auto handle = resourceAttr.getRawHandle();
    auto key = handle.getKey();
    std::string keyStr = key.str();
    auto blob = handle.getBlob();
    if (!blob) {
      op.emitOpError("dense resource has no blob data");
      return;
    }
    auto data = blob->getData();

    // 计算元素总量
    uint64_t elementCount = 1;
    auto shapedType = op.getResult().getType().template cast<ShapedType>();
    for (auto dim : shapedType.getShape()) {
      elementCount *= dim;
    }
    Type elementType = shapedType.getElementType();


    bool isGoldenData = (keyStr.find("input") == 0 || keyStr.find("output") == 0);

    if (!isGoldenData) {
        std::string weightsFullPath = weightsPath + "/" + keyStr + ".bin";
        std::ofstream ofs(weightsFullPath, std::ios::binary);
        if (!ofs.is_open()) {
            op.emitOpError("failed to open file for writing weights: " + weightsFullPath);
        } else {
            ofs.write(reinterpret_cast<const char*>(data.data()), data.size());
            ofs.close();
        }
    }
    // A. 将权重数据 Dump 到本地二进制文件
    // weightsPath 是由命令行参数 vitis-hls-weights-dir 传入的路径
    // std::string weightsFullPath = weightsPath + "/" + key.str() + ".bin";
    
    // // 只有当名字包含 weight 或 input/output 时才导出 (或者你可以去掉 if 直接全部导出)
    // std::ofstream ofs(weightsFullPath, std::ios::binary);
    // if (!ofs.is_open()) {
    //   op.emitOpError("failed to open file for writing weights: " + weightsFullPath);
    // } else {
    //   ofs.write(reinterpret_cast<const char*>(data.data()), data.size());
    //   ofs.close();
    // }

    // B. 生成 C++ 代码中的数组声明
    indent();
    Value result = op.getResult();
    // 如果你的 Emitter 有这个函数就加上，没有就去掉
    // fixUnsignedType(result, op->hasAttr("unsigned")); 
    emitArrayDecl(result);
    os << ";\n";

    // C. 生成 C++ 代码中的文件读取逻辑
    // 注意：这里假设 prj_path_str 已经在生成的 main 函数中由 getenv("PRJ_PATH") 定义
    std::string weightPathInCpp = "/" + key.str() + ".bin";
    
    indent();
    os << "{\n"; // 开启局部作用域防止 ifs 变量名冲突
    addIndent();
    
    indent();
    os << "std::ifstream " << key.str() << "_ifs(prj_path_str + \"" << "/data/" << weightPathInCpp << "\", std::ios::binary);\n";
    
    indent();
    os << "if (" << key.str() << "_ifs.is_open()) {\n";
    addIndent();
    indent();
    os << key.str() << "_ifs.read(reinterpret_cast<char*>(" << getName(result) << "), " 
       << elementCount << " * sizeof(" << getDataTypeName(elementType) << "));\n";
    indent();
    os << key.str() << "_ifs.close();\n";
    reduceIndent();
    
    indent();
    os << "} else {\n";
    addIndent();
    indent();
    os << "std::cerr << \"Error: Cannot open file \" << prj_path_str << \"" << "/data/" << weightPathInCpp << "\" << std::endl;\n";
    reduceIndent();
    
    indent();
    os << "}\n";
    
    reduceIndent();
    indent();
    os << "}\n";
    emitInfoAndNewLine(op);

  } 
  // --- 2. 处理普通的 DenseElementsAttr (内联到代码中的常量) ---
  else if (auto denseAttr = valueAttr.template dyn_cast<DenseElementsAttr>()) {
    indent();
    Value result = op.getResult();
    emitArrayDecl(result);
    os << " = {";
    auto type = result.getType().template cast<ShapedType>().getElementType();

    unsigned elementIdx = 0;
    for (auto element : denseAttr.template getValues<Attribute>()) {
      if (type.isF32()) {
        auto value = element.template cast<FloatAttr>().getValue().convertToFloat();
        if (std::isfinite(value)) os << value;
        else if (value > 0) os << "INFINITY";
        else os << "-INFINITY";
      } else if (type.isF64()) {
        auto value = element.template cast<FloatAttr>().getValue().convertToDouble();
        if (std::isfinite(value)) os << value;
        else if (value > 0) os << "INFINITY";
        else os << "-INFINITY";
      } else if (type.isInteger(1)) {
        os << (element.template cast<BoolAttr>().getValue() ? "true" : "false");
      } else if (type.isIntOrIndex()) {
        os << element.template cast<IntegerAttr>().getValue();
      } else {
        op.emitOpError("array has unsupported element type.");
      }

      if (elementIdx++ != denseAttr.getNumElements() - 1)
        os << ", ";
    }
    os << "};";
    emitInfoAndNewLine(op);
  } 
  else {
    emitError(op, "has unsupported constant type.");
  }
}

/// C++ component emitters.
void ModuleEmitter::emitValue(Value val, unsigned rank, bool isPtr,
                              bool isRef) {
  assert(!(rank && isPtr) && "should be either an array or a pointer.");

  // Value has been declared before or is a constant number.
  if (isDeclared(val)) {
    os << getName(val);
    for (unsigned i = 0; i < rank; ++i)
      os << "[iv" << i << "]";
    return;
  }

  // Emit the type of the value.
  os << getDataTypeName(val.getType()) << " ";
  if (isRef)
    os << "&";

  // Add the new value to nameTable and emit its name.
  os << addName(val, isPtr);
  for (unsigned i = 0; i < rank; ++i)
    os << "[iv" << i << "]";
}

void ModuleEmitter::emitArrayDecl(Value array) {
  assert(!isDeclared(array) && "has been declared before.");
  auto arrayType = array.getType().dyn_cast<MemRefType>();

  if (arrayType.hasStaticShape()) {
    emitValue(array);
    for (auto &shape : arrayType.getShape())
      os << "[" << shape << "]";
  } else
    emitValue(array, /*rank=*/0, /*isPtr=*/true);
}


void ModuleEmitter::emitTopFuncArrayDecl(Value array) {
  assert(!isDeclared(array) && "has been declared before.");

  auto arrayType = array.getType().dyn_cast<MemRefType>();
  auto memSpace = arrayType.getMemorySpace().dyn_cast_or_null<MemoryKindAttr>();

  // DRAM → pointer
  if (memSpace && memSpace.getValue() == MemoryKind::DRAM) {
    emitValue(array, /*rank=*/0, /*isPtr=*/true);
    return;
  }

  // 非 DRAM → 保留多维数组
  if (arrayType.hasStaticShape()) {
    emitValue(array);
    for (auto dim : arrayType.getShape())
      os << "[" << dim << "]";
  } else {
    emitValue(array, /*rank=*/0, /*isPtr=*/true);
  }
}

unsigned ModuleEmitter::emitNestedLoopHeader(Value val) {
  unsigned rank = 0;

  if (auto type = val.getType().dyn_cast<MemRefType>()) {
    if (!type.hasStaticShape()) {
      emitError(val.getDefiningOp(), "is unranked or has dynamic shape.");
      return 0;
    }

    // Declare a new array.
    if (!isDeclared(val)) {
      indent();
      emitArrayDecl(val);
      os << ";\n";
      // TODO: More precise control here. Now we assume vectors are always
      // completely partitioned at all dimensions.
      if (type.isa<VectorType>()) {
        indent() << "#pragma HLS array_partition variable=";
        emitValue(val);
        os << " complete dim=0\n";
      }
    }

    // Create nested loop.
    unsigned dimIdx = 0;
    for (auto &shape : type.getShape()) {
      indent() << "for (int iv" << dimIdx << " = 0; ";
      os << "iv" << dimIdx << " < " << shape << "; ";
      os << "++iv" << dimIdx++ << ") {\n";

      addIndent();
      // TODO: More precise control here. Now we assume vectorization loops are
      // always fully unrolled.
      if (type.isa<VectorType>())
        indent() << "#pragma HLS unroll\n";
    }
    rank = type.getRank();
  }

  return rank;
}

void ModuleEmitter::emitNestedLoopFooter(unsigned rank) {
  for (unsigned i = 0; i < rank; ++i) {
    reduceIndent();

    indent() << "}\n";
  }
}

void ModuleEmitter::emitInfoAndNewLine(Operation *op) {
  os << "\t//";
  // Print line number.
  if (auto loc = op->getLoc().dyn_cast<FileLineColLoc>())
    os << " L" << loc.getLine();

  // // Print schedule information.
  // if (auto timing = getTiming(op))
  //   os << ", [" << timing.getBegin() << "," << timing.getEnd() << ")";

  // // Print loop information.
  // if (auto loopInfo = getLoopInfo(op))
  //   os << ", iterCycle=" << loopInfo.getIterLatency()
  //      << ", II=" << loopInfo.getMinII();

  os << "\n";
}

/// MLIR component and HLS C++ pragma emitters.
void ModuleEmitter::emitBlock(Block &block) {
  for (auto &op : block) {
    if (ExprVisitor(*this).dispatchVisitor(&op))
      continue;

    if (StmtVisitor(*this).dispatchVisitor(&op))
      continue;

    emitError(&op, "can't be correctly emitted.");
  }
}

void ModuleEmitter::emitLoopDirectives(Operation *loop) {
  auto loopDirect = getLoopDirective(loop);
  if (!loopDirect)
    return;

  if (!hasParallelAttr(loop) && !loopDirect.getDataflow() &&
      enforceFalseDependency.getValue())
    indent() << "#pragma HLS dependence false\n";

  if (loopDirect.getPipeline()) {
    indent() << "#pragma HLS pipeline II=" << loopDirect.getTargetII() << "\n";
    // if (enforceFalseDependency.getValue())
    //   indent() << "#pragma HLS dependence false\n";
  } else if (loopDirect.getDataflow())
    indent() << "#pragma HLS dataflow\n";
}

void ModuleEmitter::emitArrayDirectives(Value memref, bool isInterface) {
  // TODO: The current strategy is to add HLS stream pragmas to all BufferOps.
  // A more robust approach would be to analyze the data dependencies between 
  // sub-loops and add pragmas only for those arrays that are related as producer-consumer.
  bool emitPragmaFlag = false;
  auto type = memref.getType().cast<MemRefType>();

  // FIXME: We need to decide whether this memref is a FIFO or not.
  // For now, we assume all memrefs are FIFOs. This is not correct. 
  // FIFOs cannot be partitioned, so we need to handle this case.
  // TODO: We need to identify the reuse buffers and signal them as non-FIFOs.
  // Emit HLS stream pragma for stream type.              
  if (!isInterface && !isHost) {
    indent();
    os << "#pragma HLS stream variable=";
    emitValue(memref);
    os << " depth=10";
    os << " type=fifo";
    // int semicolon_index = attr_str.find(";");
    // os << attr_str.substr(7, semicolon_index - 7);
    os << "\n";
    os << "\n";
    // if the array is a FIFO, then it cannot be further partitioned
    // so directly return
    // return;
  }

  // Emit array_partition pragma(s).
  if (auto attr = type.getLayout().dyn_cast<PartitionLayoutAttr>()) {
    unsigned dim = 1;
    for (auto [kind, factor] :
         llvm::zip(attr.getKinds(), attr.getActualFactors(type.getShape()))) {
      if (factor != 1) {
        emitPragmaFlag = true;
        indent() << "#pragma HLS array_partition";
        os << " variable=";
        emitValue(memref);

        // Emit partition type.
        os << " " << stringifyPartitionKind(kind);
        os << " factor=" << factor;

        // Vitis HLS has a wierd feature/bug that will automatically collapse
        // the first dimension if its size is equal to one.
        auto directiveDim = dim ;
        if (emitVitisDirectives.getValue())
          if (type.getShape().front() == 1)
            directiveDim = dim;
        os << " dim=" << directiveDim << "\n";
      }
      ++dim;
    }
  }

  // Emit resource pragma when the array is not DRAM kind and is not fully
  // partitioned.
  // if (!isInterface) {
    auto kind = getMemoryKind(type);
    if (kind != MemoryKind::DRAM && !isFullyPartitioned(type) && !isHost) {
      emitPragmaFlag = true;

      if (emitVitisDirectives.getValue()) {
        indent() << "#pragma HLS bind_storage";
        os << " variable=";
        emitValue(memref);
        os << " " << getStorageTypeAndImpl(kind, "type", "impl");
      } else {
        indent() << "#pragma HLS resource";
        os << " variable=";
        emitValue(memref);
        os << " core=" << getVivadoStorageTypeAndImpl(kind);
      }
      // Emit a new line.
      os << "\n";
    }
  // }

  // Emit an empty line.
  if (emitPragmaFlag)
    os << "\n";


}

void ModuleEmitter::emitFunctionDirectives(func::FuncOp func,
                                           ArrayRef<Value> portList) {
  // Only top function should emit interface pragmas.
  if (hasTopFuncAttr(func)) {
    indent() << "#pragma HLS interface s_axilite port=return bundle=ctrl\n";
    for (auto &port : portList) {
      // Axi ports are handled separately.
      // if (port.getType().isa<AxiType>())
      //   continue;

      // Handle normal memref or stream types.
      if (port.getType().isa<MemRefType, StreamType>()) {
        indent() << "#pragma HLS interface";

        if (auto memrefPortType = port.getType().dyn_cast<MemRefType>()) {
          // Emit array_partition pragma(s).
          if (getMemoryKind(memrefPortType) == MemoryKind::DRAM)
            os << " m_axi offset=slave";
          else
            os << " bram";
          
        } else
          os << " axis";

        os << " port=";
        emitValue(port);
        os << " bundle=gmem";
        count++;
        os <<count;
        os << "\n";

        // if (auto memrefPortType = port.getType().dyn_cast<MemRefType>()) {
        //   if (auto attr = memrefPortType.getLayout().dyn_cast<PartitionLayoutAttr>()) {
        //       unsigned dim = 0;
        //       for (auto [kind, factor] :
        //           llvm::zip(attr.getKinds(), attr.getActualFactors(memrefPortType.getShape()))) {
        //         if (factor != 1) {
        //           indent() << "#pragma HLS array_partition";
        //           os << " variable=";
        //           emitValue(port);

        //           // Emit partition type.
        //           os << " " << stringifyPartitionKind(kind);
        //           os << " factor=" << factor;

        //           // Vitis HLS has a wierd feature/bug that will automatically collapse
        //           // the first dimension if its size is equal to one.
        //           auto directiveDim = dim + 1;

        //           if (emitVitisDirectives.getValue())
        //             if (memrefPortType.getShape().front() == 1)
        //               directiveDim = dim;
        //           os << " dim=" << directiveDim << "\n";
        //         }
        //         ++dim;
        //       }
        //   }
        // }

      } else {
        // For scalar types, we always emit them as AXI-Lite ports.
        auto name = getName(port);
        if (name.front() == "*"[0])
          name.erase(name.begin());
        indent() << "#pragma HLS interface s_axilite port=" << name
                 << " bundle=ctrl\n";
      }

      if (port.getType().isa<MemRefType>())
        emitArrayDirectives(port, true);
    }
  }

  // if (func->getAttr("inline"))
  //   indent() << "#pragma HLS inline\n";

  if (auto funcDirect = getFuncDirective(func)) {
    if (funcDirect.getPipeline()) {
      indent() << "#pragma HLS pipeline II=" << funcDirect.getTargetInterval()
               << "\n";
      // An empty line.
      os << "\n";
    } else if (funcDirect.getDataflow()) {
      indent() << "#pragma HLS dataflow\n";
      // An empty line.
      os << "\n";
    }
  }
}

// void ModuleEmitter::emitFunction(func::FuncOp func) {
//   if (func.getBlocks().size() != 1)
//     emitError(func, "has zero or more than one basic blocks.");

//   if (hasTopFuncAttr(func))
//     os << "/// This is top function.\n";

//   // if (auto timing = getTiming(func)) {
//   //   os << "/// Latency=" << timing.getLatency();
//   //   os << ", interval=" << timing.getInterval();
//   //   os << "\n";
//   // }

//   // if (auto resource = getResource(func)) {
//   //   os << "/// DSP=" << resource.getDsp();
//   //   os << ", BRAM=" << resource.getBram();
//   //   // os << ", LUT=" << resource.getLut();
//   //   os << "\n";
//   // }

//   // Emit function signature.
//   os << "void " << func.getName() << "(\n";
//   addIndent();

//   // This vector is to record all ports of the function.
//   SmallVector<Value, 8> portList;

//   // Emit input arguments.
//   unsigned argIdx = 0;
  
//   if(hasTopFuncAttr(func)){
//     for (auto &arg : func.getArguments()) {
//     indent();
//     auto type = arg.getType();

//     if (type.isa<MemRefType>())
//       emitTopFuncArrayDecl(arg);
//     // else if (type.isa<StreamType>())
//     //   emitValue(arg, /*rank=*/0, /*isPtr=*/false, /*isRef=*/true);
//     else
//       emitValue(arg);

//     portList.push_back(arg);
//     if (argIdx++ != func.getNumArguments() - 1)
//       os << ",\n";
//   }
//   }else{
//     for (auto &arg : func.getArguments()) {
//     indent();
//     auto type = arg.getType();

//     if (type.isa<MemRefType>())
//       emitArrayDecl(arg);
//     // else if (type.isa<StreamType>())
//     //   emitValue(arg, /*rank=*/0, /*isPtr=*/false, /*isRef=*/true);
//     else
//       emitValue(arg);

//     portList.push_back(arg);
//     if (argIdx++ != func.getNumArguments() - 1)
//       os << ",\n";
//   }
//   }

  

//   // Emit results.
//   auto funcReturn = cast<func::ReturnOp>(func.front().getTerminator());
//   for (auto result : funcReturn.getOperands()) {
//     os << ",\n";
//     indent();
//     // TODO: a known bug, cannot return a value twice, e.g. return %0, %0 :
//     // index, index. However, typically this should not happen.
//     if (result.getType().isa<MemRefType>())
//       emitArrayDecl(result);
//     else
//       // In Vivado HLS, pointer indicates the value is an output.
//       emitValue(result, /*rank=*/0, /*isPtr=*/true);

//     portList.push_back(result);
//   }

//   reduceIndent();
//   os << "\n) {";
//   emitInfoAndNewLine(func);

//   // Emit function body.
//   addIndent();

//   emitFunctionDirectives(func, portList);
//   emitBlock(func.front());
//   reduceIndent();
//   os << "}\n";
//   // An empty line.
//   os << "\n";
// }

void ModuleEmitter::emitFunction(func::FuncOp func) {
  // 1. 基础检查：HLS 函数通常只有一个基本块
  if (func.getBlocks().size() > 1) {
    emitError(func, "has more than one basic blocks.");
    return;
  }
  uint argNum = 0;
  // 2. 处理函数声明（如果没有 Block，则只生成分号结尾的签名）
  if (func.getBlocks().empty()){
    // This is a declaration.
    os << "void " << func.getName() << "(\n";
    addIndent();
    for(auto argType : func.getArgumentTypes()){
      indent();
      if(auto arrayType = argType.dyn_cast<ShapedType>()){
        os << getDataTypeName(arrayType) << " ";
        if (arrayType.getShape().size() == 1 && arrayType.getShape()[0] == 1) {
            // do nothing;
        } else {
          for (auto &shape : arrayType.getShape())
            os << "[" << shape << "]";
        }
      }else if(argType.isa<FloatType, IntegerType>()){
        os << getDataTypeName(argType);
      }
      argNum++;
      if(argNum != func.getNumArguments())
        os << ",\n";
      else
        os << "\n";
    }    
    reduceIndent();
    os << ");\n";
    return;
  }

  if (hasTopFuncAttr(func))
    os << "/// This is top function.\n";

  // 用于记录端口，供后续 emitFunctionDirectives 使用
  SmallVector<Value, 8> portList;

  // 3. 特殊处理 main 函数
  if (func.getName() == "main") {
      // 修正：不使用 builder，直接从 func 的 context 获取 i32 类型
    Type returnType = func.getResultTypes().empty() ? 
                      IntegerType::get(func.getContext(), 32) : 
                      func.getResultTypes()[0];
    
    // 确保 getTypeName 在类中定义，或者在上方声明过
    os << getDataTypeName(returnType) << " " << func.getName() << "(int argc, char **argv) {";
    // // 假设 main 返回 i32
    // Type returnType = func.getResultTypes().empty() ? 
    //                   builder.getI32Type() : func.getResultTypes()[0];
    
    // os << getDataTypeName(returnType) << " " << func.getName() << "(int argc, char **argv) {";
    
    // 注入环境变量 PRJ_PATH 代码（用于定位权重二进制文件）
    std::string envVar = R"XXX(
  // get environment variable PRJ_PATH
  char* prj_path_c_str = getenv("PRJ_PATH");
  if (prj_path_c_str == NULL) {
    std::cerr << "Environment variable PRJ_PATH not set" << std::endl;
    return 1;
  }
  std::string prj_path_str(prj_path_c_str);
  std::cout << "PRJ_PATH: " << prj_path_str << std::endl;
)XXX";
    os << envVar;

  } else {
    // 4. 处理普通的内核函数签名
    os << "void " << func.getName() << "(\n";
    addIndent();

    unsigned argIdx = 0;
    // 处理输入参数
    for (auto &arg : func.getArguments()) {
      indent();
      auto type = arg.getType();

      if (type.isa<MemRefType>()) {
        if (hasTopFuncAttr(func))
          emitTopFuncArrayDecl(arg);
        else
          emitArrayDecl(arg);
      } else {
        emitValue(arg);
      }

      portList.push_back(arg);
      if (argIdx++ != func.getNumArguments() - 1 || !func.front().getTerminator()->getOperands().empty())
        os << ",\n";
    }

    // 将返回值处理为输出参数 (C/C++ 不支持多返回值，通常转为指针/引用)
    auto funcReturn = cast<func::ReturnOp>(func.front().getTerminator());
    unsigned resIdx = 0;
    for (auto result : funcReturn.getOperands()) {
      indent();
      if (result.getType().isa<MemRefType>())
        emitArrayDecl(result);
      else
        emitValue(result, /*rank=*/0, /*isPtr=*/true); // 标量作为输出指针

      portList.push_back(result);
      if (resIdx++ != funcReturn.getNumOperands() - 1)
        os << ",\n";
    }

    reduceIndent();
    os << "\n) {";
  }

  emitInfoAndNewLine(func);

  // 5. 生成函数体内容
  addIndent();

  // 如果是 Top 函数，通常需要注入 DATAFLOW 指令
  if (hasTopFuncAttr(func)) {
    indent();
    os << "#pragma HLS DATAFLOW\n";
  }

  // 发射 HLS 接口指令 (如 #pragma HLS INTERFACE)
  emitFunctionDirectives(func, portList);

  // 如果有 systolic 属性，添加 scop 标记
  if (func->hasAttr("systolic")) {
    indent();
    os << "#pragma scop\n";
  }

  // 递归发射 Block 内部的所有操作 (Constants, Loads, Stores, Calls...)
  emitBlock(func.front());

  if (func->hasAttr("systolic")) {
    indent();
    os << "#pragma endscop\n";
  }

  reduceIndent();
  os << "}\n";

  // 空行分隔
  os << "\n";
}

/// Top-level MLIR module emitter.
void ModuleEmitter::emitModule(ModuleOp module) {

  std::string device_header =  R"XXX(
//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for High-level Synthesis (HLS).
//
//===----------------------------------------------------------------------===//

#include <algorithm>
#include <ap_axi_sdata.h>
#include <ap_fixed.h>
#include <ap_int.h>
#include <hls_math.h>
#include <hls_stream.h>
#include <hls_vector.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

using namespace std;

)XXX";
  std::string host_header = R"XXX(
//===------------------------------------------------------------*- C++ -*-===//
//
// Automatically generated file for host
//
//===----------------------------------------------------------------------===//
// XRT includes
// #include "xrt/xrt_bo.h"
// #include <experimental/xrt_xclbin.h>
// #include "xrt/xrt_device.h"
// #include "xrt/xrt_kernel.h"

// standard C/C++ headers
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <time.h>

#include <math.h>
#include <stdint.h>
#include <fstream>
#include <iostream>
#include <cstring>

#include <hls_half.h>

using namespace std;

)XXX";
  if(isHost) {
    os << host_header;
  } else {
    os << device_header;
  }



  // Emit all functions in the call graph in a post order.
  CallGraph graph(module);
  llvm::SmallDenseSet<func::FuncOp> emittedFuncs;
  if(!isHost){ 
    for (auto node : llvm::post_order<const CallGraph *>(&graph)) {
    if (node->isExternal())
      continue;
    if (auto func = node->getCallableRegion()->getParentOfType<func::FuncOp>();
        !hasRuntimeAttr(func)) {
      emitFunction(func);
      emittedFuncs.insert(func);
    }
  }}

  // Emit remained functions accordingly.
  for (auto &op : *module.getBody()) {
    if (auto func = dyn_cast<func::FuncOp>(op)) {
      if (!emittedFuncs.count(func) && !hasRuntimeAttr(func))
        emitFunction(func);
    } else if (!isa<ml_program::GlobalOp>(op))
      emitError(&op, "is unsupported operation");
  }
}

//===----------------------------------------------------------------------===//
// Entry of codo-translate
//===----------------------------------------------------------------------===//
LogicalResult codo::emitVitisHLS(ModuleOp module, llvm::raw_ostream &os) {
  codoEmitterState state(os);
  ModuleEmitter(state).emitModule(module);
  return failure(state.encounteredError);
}

void codo::registerEmitVitisHLSTranslation() {
  static TranslateFromMLIRRegistration toVitisHLS(
      "emit-vitis-hls", "Emit Vitis HLS C code", emitVitisHLS,
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