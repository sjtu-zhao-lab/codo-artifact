set(LLVM_LINK_COMPONENTS
  Core
  Support
  nativecodegen
  OrcJIT
  )
get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(conversion_libs GLOBAL PROPERTY MLIR_CONVERSION_LIBS)
set(LIBS
        ${dialect_libs}
        ${conversion_libs}
        MLIRExecutionEngine
        MLIRLLVMCommonConversion
        MLIRLLVMDialect
        MLIRLLVMToLLVMIRTranslation
        MLIRTargetLLVMIRExport
        MLIRIR
        MLIROptLib
        MLIRArithDialect
        MLIRIR
        MLIRPass
        MLIRPluginsLib
        MLIRCodo
        MLIRCodoSupport
        MLIRCodoPasses
        )
add_llvm_executable(codo-opt codo-opt.cpp)

llvm_update_compile_flags(codo-opt)
target_link_libraries(codo-opt PRIVATE ${LIBS})

mlir_check_all_link_libraries(codo-opt)
