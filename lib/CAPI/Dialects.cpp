#include "codo-c/Dialects.h"

#include "codo/Dialect/CodoDialect.h"
#include "mlir/CAPI/Registration.h"

MLIR_DEFINE_CAPI_DIALECT_REGISTRATION(CODO, codo, mlir::codo::CodoDialect)
