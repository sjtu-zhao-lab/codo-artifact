#ifndef CODO_CODODIALECT_H
#define CODO_CODODIALECT_H

// #include "mlir/Bytecode/BytecodeOpInterface.h"
#include "mlir/IR/Dialect.h"

#include "codo/Dialect/CodoOpsDialect.h.inc"

namespace mlir {
namespace codo {

/// Kind of dataflow.node operands.
enum class OperandKind { INPUT, OUTPUT, PARAM };

}
}

#endif // codo_codoDIALECT_H
