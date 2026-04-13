set(LLVM_LINK_COMPONENTS
  Support
  )

get_property(dialect_libs GLOBAL PROPERTY MLIR_DIALECT_LIBS)
get_property(translation_libs GLOBAL PROPERTY MLIR_TRANSLATION_LIBS)

add_llvm_executable(codo-translate
codo-translate.cpp
  )
llvm_update_compile_flags(codo-translate)
target_link_libraries(codo-translate
  PRIVATE
  ${dialect_libs}
  ${translation_libs}
  MLIRIR
  MLIRParser
  MLIRPass
  MLIRSPIRVDialect
  MLIRTranslateLib
  MLIRSupport
  MLIRCodo
  MLIRCodoSupport
  MLIRCodoPasses
  MLIRCodoEmitHLSCpp
  )

mlir_check_link_libraries(codo-translate)
