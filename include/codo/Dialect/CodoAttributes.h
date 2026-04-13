#ifndef CODO_ATTRIBUTES_H
#define CODO_ATTRIBUTES_H

#include "mlir/IR/BuiltinAttributes.h"

#include "codo/Dialect/CodoEnums.h.inc"

#define GET_ATTRDEF_CLASSES
#include "codo/Dialect/CodoAttributes.h.inc"

#endif // CODO_ATTRIBUTES_H