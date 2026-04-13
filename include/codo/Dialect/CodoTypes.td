/*
 * Copyright codo authors. All Rights Reserved.
 */

#ifndef CODO_TYPES
#define CODO_TYPES

// include "mlir/IR/AttrTypeBase.td"
include "mlir/IR/BuiltinTypeInterfaces.td"
include "codo/Dialect/CodoDialect.td"

//===----------------------------------------------------------------------===//
// codo type definitions
//===----------------------------------------------------------------------===//
def Type : Codo_Type<"Type", [MemRefElementTypeInterface]> {
  let summary = "generic type";
  let mnemonic = "Type";
}

def StreamType : Codo_Type<"Stream"> {
  let summary = "An HLS stream type";
  let description = [{
    Represents a stream of any type that can be transfered between HLS modules.
    This type is equal to the hls::stream<> type in Xilinx Vivado HLS.
  }];
  let mnemonic = "stream";

  let parameters = (ins "mlir::Type":$elementType, "unsigned":$depth);
  let assemblyFormat = "`<` qualified($elementType) `,` $depth `>`";
}


#endif // CODO_TYPES
