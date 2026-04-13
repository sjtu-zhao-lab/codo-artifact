add_mlir_dialect_library(MLIRCodo
        # CodoTypes.cpp
        CodoDialect.cpp
        CodoOps.cpp
        # CodoPasses.cpp

        ADDITIONAL_HEADER_DIRS
        ${PROJECT_SOURCE_DIR}/include/codo

        DEPENDS
        MLIRCodoOpsIncGen
        MLIRCodoPassesIncGen
        MLIRCodoAttributesIncGen
        MLIRCodoEnumsIncGen
        MLIRCodoInterfacesIncGen

        LINK_LIBS PUBLIC
        MLIRIR
        )
