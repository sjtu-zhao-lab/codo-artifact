set(LLVM_TARGET_DEFINITIONS Passes.td)
mlir_tablegen(Passes.h.inc -gen-pass-decls)
add_public_tablegen_target(MLIRCodoPassesIncGen)

add_mlir_doc(CodoPass CodoPass Dialect/ -gen-pass-doc)