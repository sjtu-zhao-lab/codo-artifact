#ifndef CODO_CODOOPS_H
#define CODO_CODOOPS_H

#include "mlir/IR/BuiltinTypes.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/OpDefinition.h"
#include "mlir/Interfaces/InferTypeOpInterface.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"

#include "mlir/Dialect/Affine/IR/AffineOps.h"
#include "mlir/Dialect/Func/IR/FuncOps.h"
#include "codo/Dialect/CodoInterfaces.h"
#include "codo/Dialect/CodoDialect.h"
#include "codo/Dialect/CodoTypes.h"


#define GET_OP_CLASSES
#include "codo/Dialect/CodoOps.h.inc"


#endif // CODO_CODOOPS_H
