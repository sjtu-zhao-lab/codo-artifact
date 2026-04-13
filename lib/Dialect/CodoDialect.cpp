/*
 * Copyright codo authors. All Rights Reserved.
 */
#include "mlir/IR/Builders.h"
#include "mlir/IR/DialectImplementation.h"
#include "llvm/ADT/TypeSwitch.h"
#include "llvm/ADT/StringExtras.h"
#include "mlir/Transforms/InliningUtils.h"

#include "codo/Dialect/CodoDialect.h"
#include "codo/Dialect/CodoOps.h"
#include "codo/Dialect/CodoTypes.h"
#include "codo/Dialect/CodoAttributes.h"
#include "codo/Support/Utils.h"
using namespace mlir;
using namespace codo;

#include "codo/Dialect/CodoOpsDialect.cpp.inc"

//===----------------------------------------------------------------------===//
// Tablegen Type Definitions
//===----------------------------------------------------------------------===//

#define GET_TYPEDEF_CLASSES
#include "codo/Dialect/CodoOpsTypes.cpp.inc"

#define GET_ATTRDEF_CLASSES
#include "codo/Dialect/CodoAttributes.cpp.inc"

#include "codo/Dialect/CodoEnums.cpp.inc"

//===----------------------------------------------------------------------===//
// codo dialect.
//===----------------------------------------------------------------------===//

void CodoDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "codo/Dialect/CodoOps.cpp.inc"
      >();
  addTypes<
#define GET_TYPEDEF_LIST
#include "codo/Dialect/CodoOpsTypes.cpp.inc"
      >();
  addAttributes< 
#define GET_ATTRDEF_LIST
#include "codo/Dialect/CodoAttributes.cpp.inc"
      >();
}


  
