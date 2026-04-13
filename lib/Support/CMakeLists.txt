file(GLOB globbed *.cpp)

add_mlir_library(MLIRCodoSupport
  ${globbed}

  DEPENDS
  MLIRCodoOpsIncGen
  MLIRCodoPassesIncGen
  MLIRCodoAttributesIncGen
  MLIRCodoEnumsIncGen

  LINK_LIBS PUBLIC
  MLIRIR
  MLIRParser
  MLIRPass
  MLIRSPIRVDialect
  MLIRTranslateLib
  MLIRCodo
  MLIRMemRefDialect
  MLIRAnalysis
  MLIRAffineAnalysis
  )
