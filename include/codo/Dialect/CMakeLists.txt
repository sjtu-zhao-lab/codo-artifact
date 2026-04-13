add_mlir_dialect(CodoOps codo)
add_mlir_doc(CodoDialect CodoDialect Dialect/ -gen-dialect-doc)
add_mlir_doc(CodoOps CodoOps Dialect/ -gen-op-doc)

set(LLVM_TARGET_DEFINITIONS CodoAttributes.td)
mlir_tablegen(CodoAttributes.h.inc -gen-attrdef-decls)
mlir_tablegen(CodoAttributes.cpp.inc -gen-attrdef-defs)
add_public_tablegen_target(MLIRCodoAttributesIncGen)

set(LLVM_TARGET_DEFINITIONS CodoAttributes.td)
mlir_tablegen(CodoEnums.h.inc -gen-enum-decls)
mlir_tablegen(CodoEnums.cpp.inc -gen-enum-defs)
add_public_tablegen_target(MLIRCodoEnumsIncGen)

set(LLVM_TARGET_DEFINITIONS CodoInterfaces.td)
mlir_tablegen(CodoInterfaces.h.inc -gen-op-interface-decls)
mlir_tablegen(CodoInterfaces.cpp.inc -gen-op-interface-defs)
add_public_tablegen_target(MLIRCodoInterfacesIncGen)