add_mlir_library(MLIRCodoPasses
    Passes.cpp
    Graph/GraphPartition.cpp
    Graph/GraphPreprocess.cpp
    Graph/CreateDataflowFromAffine.cpp
    Graph/BufferizeDataflow.cpp
    Graph/StreamDataflowTask.cpp
    Graph/LowerDataflow.cpp
    Graph/ConvertDataflowToFunc.cpp
    Graph/FuncPreprocess.cpp
    Graph/EliminateTopfuncargMultiConsumer.cpp
    Graph/EliminateMultiConsumer.cpp
    Graph/EliminateMultiProducer.cpp
    Graph/ScheduleDataflowNode.cpp
    Graph/BalanceDataflowNode.cpp
    Graph/LegalizeDataflow.cpp
    Graph/EliminateRedundantArray.cpp
    # Graph/FuseSoftmaxAttention.cpp
    Loop/AffineLoopOrderOpt.cpp
    Loop/AffineLoopReorder.cpp
    Loop/AffineLoopTransformation.cpp
    Loop/AffineLoopFusion.cpp
    Loop/AffineLoopPerfection.cpp
    Loop/AffineMMFIFO.cpp
    Loop/AffineLoopTiling.cpp
    Loop/EliminateViolation.cpp
    Loop/AffineLoopUnrollJam.cpp
    Loop/GenerateReuseBuffer.cpp
    Loop/LoopLevelDSE.cpp
    Loop/LoopLevelDSE_v1.cpp
    Loop/FIFOornot.cpp
    Memory/Quantization.cpp
    Memory/LowerCopyToAffine.cpp
    Memory/SpecifyBufferType.cpp
    Memory/MemoryTransferBetweenDRAMAndSRAM.cpp

    Hardware/ArrayPartition.cpp
    Hardware/QoREstimation.cpp
    DesignSpaceExplore.cpp

    Verify/CreateHost.cpp
    Verify/CreateWeightBins.cpp
    Verify/RemoveRedundantOps.cpp
    
    ADDITIONAL_HEADER_DIRS
    ${PROJECT_SOURCE_DIR}/include/codo

    DEPENDS
    MLIRCodoOpsIncGen
    MLIRCodoAttributesIncGen
    MLIRCodoPassesIncGen
    MLIRCodoInterfacesIncGen

    LINK_COMPONENTS
    Core

    LINK_LIBS PUBLIC
    MLIRIR
    MLIRExecutionEngine
    MLIRLLVMCommonConversion
    MLIRLLVMDialect
    MLIRLLVMToLLVMIRTranslation
    MLIRTargetLLVMIRExport
    # MLIRIR
    MLIRTensorToLinalg
    MLIROptLib
    MLIRPass
    MLIRCodo
    MLIRCodoSupport
)