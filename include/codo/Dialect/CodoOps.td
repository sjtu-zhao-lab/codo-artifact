#ifndef CODO_OPS
#define CODO_OPS

include "codo/Dialect/CodoTypes.td"
include "codo/Dialect/CodoInterfaces.td"
include "mlir/Interfaces/InferTypeOpInterface.td"
include "mlir/Interfaces/SideEffectInterfaces.td"

include "mlir/Interfaces/ControlFlowInterfaces.td"
include "mlir/Interfaces/SideEffectInterfaces.td"
include "mlir/Interfaces/ViewLikeInterface.td"
include "mlir/IR/BuiltinAttributeInterfaces.td"
include "mlir/IR/SymbolInterfaces.td"



class StreamOf<list<Type> allowedTypes> : Type<And<[
    CPred<"$_self.isa<mlir::codo::StreamType>()">,
    Concat<"[](mlir::Type elementType) { return ",
      SubstLeaves<"$_self", "elementType", AnyTypeOf<allowedTypes>.predicate>,
      "; }($_self.cast<mlir::codo::StreamType>().getElementType())">
  ]>,
  "stream of " # AnyTypeOf<allowedTypes>.summary # " values",
  "mlir::codo::StreamType"
>;


def AnyBuffer : StaticShapeMemRefOf<[AnyType]>;
def AnyStream : StreamOf<[AnyType]>;
def AnyBufferOrStream : Type<Or<[AnyBuffer.predicate, AnyStream.predicate]>,
    "memref or stream values">;


    

def Codo_FooOp : Codo_Op<"foo", [Pure,
                                             SameOperandsAndResultType]> {
    let summary = "Illustrates how to define an operation.";
    let description = [{
        The `codo.foo` operation illustrates how to define a new
        operation in a dialect. It uses an operation trait to declare that it
        has no side effects.

        This operation takes an integer argument and returns an integer.

        Example:

        ```mlir
        %0 = arith.constant 2 : i32
        // Apply the foo operation to %0
        %1 = standalone.foo %0 : i32
        ```
    }];

    let arguments = (ins I32:$input);
    let results = (outs I32:$res);

    let assemblyFormat = [{
        $input attr-dict `:` type($input)
    }];
}


def DispatchOp : Codo_Op<"dataflow.dispatch", [RecursiveMemoryEffects,
      SingleBlockImplicitTerminator<"YieldOp">,
      ParentOneOf<["func::FuncOp", "affine::AffineForOp"]>]> {
  let summary = "Represent a dataflow dispatch";
  let description = [{
    Dispatch op has a transparent region that contains a list of task ops to be
    dispatched. This op is designed to organize and manipulate task ops at a
    high level and will be lowered to schedule op for dataflow scheduling.
  }];

  let results = (outs Variadic<AnyType>:$results);
  let regions = (region SizedRegion<1>:$body);
  let assemblyFormat = "attr-dict-with-keyword ( `:` type($results)^ )? $body";

  let hasVerifier = 1;
  let hasCanonicalizer = 1;

  let extraClassDeclaration = [{
    /// Get the terminator yield op.
    YieldOp getYieldOp();
  }];
}

def TaskOp : Codo_Op<"dataflow.task", [
      DeclareOpInterfaceMethods<StageLikeInterface>, RecursiveMemoryEffects, 
      SingleBlockImplicitTerminator<"YieldOp">, HasParent<"DispatchOp">]> {
  let summary = "Represent a dataflow task";
  let description = [{
    Task op has a transparent region that contains a list of ops to be executed
    in the task. This op is designed to represent the task partition at a high
    level and will be lowered to node op for dataflow scheduling.
  }];

  let results = (outs Variadic<AnyType>:$results);
  let regions = (region SizedRegion<1>:$body);
  let assemblyFormat = "attr-dict-with-keyword ( `:` type($results)^ )? $body";

  let hasVerifier = 1;
  let hasCanonicalizer = 1;

  let extraClassDeclaration = [{
    /// Get the parent dispatch op.
    DispatchOp getDispatchOp();

    /// Get the terminator yield op.
    YieldOp getYieldOp();

    // TODO: not sure the usage of this function
    bool hasHierarchy() {
      return cast<StageLikeInterface>(this->getOperation()).hasHierarchy();
    }
  }];
}

def YieldOp : Codo_Op<"dataflow.yield", [NoMemoryEffect, ReturnLike, Terminator,
      ParentOneOf<["DispatchOp", "TaskOp"]>]> {
  let summary = "Terminate and yield results of a dispatch or task op";

  let arguments = (ins Variadic<AnyType>:$results);
  let assemblyFormat = "$results attr-dict `:` type($results)";

  let builders = [OpBuilder<(ins), "build($_builder, $_state, std::nullopt);">];
}

def ToStreamOp : Codo_Op<"dataflow.to_stream", [NoMemoryEffect]> {
  let summary = "Convert a scalar value to a stream channel";

  let arguments = (ins AnyType:$value);
  let results = (outs AnyStream:$stream);
  let assemblyFormat = "$value attr-dict `:` functional-type($value, $stream)";

  let hasVerifier = 1;
  let hasFolder = 1;
}

def ToValueOp : Codo_Op<"dataflow.to_value", [NoMemoryEffect]> {
  let summary = "Convert a stream to a scalar value";

  let arguments = (ins AnyStream:$stream);
  let results = (outs AnyType:$value);
  let assemblyFormat = "$stream attr-dict `:` functional-type($stream, $value)";

  let hasVerifier = 1;
  let hasFolder = 1;
}
//===----------------------------------------------------------------------===//
// Low Dataflow Operations
//===----------------------------------------------------------------------===//

def ScheduleOp : Codo_Op<"dataflow.schedule", [
      DeclareOpInterfaceMethods<MemoryEffectsOpInterface>, IsolatedFromAbove,
      AffineScope, SingleBlock, NoTerminator,
      ParentOneOf<["func::FuncOp", "affine::AffineForOp"]>]> {
  let summary = "Represent a dataflow schedule";
  let description = [{
    Schedule op has an isolated region to contain a list of dataflow node ops to
    be scheduled. This op can be explicitly marked as legal when all the
    dataflow violations have been resolved and all the nodes has been scheduled.
  }];

  let arguments = (ins Variadic<AnyType>:$operands, UnitAttr:$isLegal);
  let regions = (region SizedRegion<1>:$body);
  let assemblyFormat = [{
    ( `legal` $isLegal^ )? ( `(` $operands^ `)` )? attr-dict-with-keyword
    ( `:` type($operands)^ )? $body
  }];

  let hasVerifier = 1;
  let hasCanonicalizer = 1;

  let extraClassDeclaration = [{
    /// FIXME: Check whether the schedule is dependence free.
    bool isDependenceFree();

    /// Update the signature of the schedule op recursively.
    void updateSignatureRecursively();
  }];
}

def NodeOp : Codo_Op<"dataflow.node", [
      DeclareOpInterfaceMethods<MemoryEffectsOpInterface>,
      DeclareOpInterfaceMethods<StageLikeInterface>, IsolatedFromAbove,
      AffineScope, SingleBlock, NoTerminator, AttrSizedOperandSegments,
      HasParent<"ScheduleOp">]> {
  let summary = "Represent a dataflow node";
  let description = [{
    Node op has an isolated region to represent the ops contained by the node.
    The node can only take buffers or streams as inputs and outputs. Meanwhile,
    scalar values can be passed into a node as parameters, which will not be
    considered in the dataflow. An attribute "inputTaps" is used to represent
    the level of buffer or stream channel tap of each input.
  }];

  let arguments = (ins Variadic<AnyBufferOrStream>:$inputs,
      Variadic<AnyBufferOrStream>:$outputs, Variadic<AnyType>:$params,
      I32ArrayAttr:$inputTaps, OptionalAttr<I32Attr>:$level);
  let regions = (region SizedRegion<1>:$body);

  let assemblyFormat = [{
    `(` $inputs `)` `->` `(` $outputs `)` ( `[` $params^ `]` )? attr-dict `:`
    functional-type($inputs, $outputs) ( `[` type($params)^ `]` )? $body
  }];

  let hasVerifier = 1;
  let hasCanonicalizer = 1;
  let builders = [
    OpBuilder<(ins "mlir::ValueRange":$inputs, "mlir::ValueRange":$outputs,
        "mlir::ValueRange":$params, "ArrayRef<unsigned>":$inputTaps,
        "mlir::IntegerAttr":$level), [{
          auto newInputTaps = SmallVector<int32_t>(
            llvm::map_range(inputTaps, [](unsigned a) { return (int32_t)a; }));
          build($_builder, $_state, inputs, outputs, params,
                $_builder.getI32ArrayAttr(newInputTaps), level);
        }]>,

    OpBuilder<(ins "mlir::ValueRange":$inputs, "mlir::ValueRange":$outputs,
        "mlir::ValueRange":$params, "ArrayRef<unsigned>":$inputTaps), [{
          build($_builder, $_state, inputs, outputs, params, inputTaps, nullptr);
        }]>,
    OpBuilder<(ins "mlir::ValueRange":$inputs, "mlir::ValueRange":$outputs,
        "ArrayRef<unsigned>":$inputTaps), [{
          build($_builder, $_state, inputs, outputs, ValueRange(), inputTaps);
        }]>,

    OpBuilder<(ins "mlir::ValueRange":$inputs, "mlir::ValueRange":$outputs,
        "mlir::ValueRange":$params), [{
          build($_builder, $_state, inputs, outputs, params,
                SmallVector<unsigned>(inputs.size(), 0));
        }]>,
    OpBuilder<(ins "mlir::ValueRange":$inputs, "mlir::ValueRange":$outputs),
        "build($_builder, $_state, inputs, outputs, ValueRange());">
  ];

  let extraClassDeclaration = [{
    /// Get the parent schedule op.
    ScheduleOp getScheduleOp();

    /// Get input taps.
    void setInputTap(unsigned idx, unsigned tap);
    unsigned getInputTap(unsigned idx);
    SmallVector<unsigned> getInputTapsAsInt();

    /// Get the number of inputs, outputs, and params.
    unsigned getNumInputs();
    unsigned getNumOutputs();
    unsigned getNumParams();

    /// Get the type of operand: input, output, or param.
    OperandKind getOperandKind(OpOperand &operand);
    OperandKind getOperandKind(unsigned operandIdx);

    /// Get the input, output, and param arguments.
    iterator_range<Block::args_iterator> getInputArgs();
    iterator_range<Block::args_iterator> getOutputArgs();
    iterator_range<Block::args_iterator> getParamArgs();

    bool hasHierarchy() {
      return cast<StageLikeInterface>(this->getOperation()).hasHierarchy();
    }

    /// Update the signature of the node op recursively.
    void updateSignatureRecursively();
  }];
}

def BufferOp : Codo_Op<"dataflow.buffer", [
      DeclareOpInterfaceMethods<MemoryEffectsOpInterface>,
      DeclareOpInterfaceMethods<BufferLikeInterface>]> {
  let summary = "Represent a dataflow buffer";

  let arguments = (ins I32Attr:$depth,
                       OptionalAttr<TypedAttrInterface>:$init_value,
                       OptionalAttr<StrAttr>:$string_attr);
  let results = (outs AnyBuffer:$memref);
  let assemblyFormat = "attr-dict `:` type($memref)";

  let hasVerifier = 1;
  let hasCanonicalizer = 1;
  let builders = [
    OpBuilder<(ins "mlir::Type":$memref),
        "build($_builder, $_state, memref, 1, nullptr, nullptr);">,

    // OpBuilder<(ins "mlir::Type":$memref),
    //     "build($_builder, $_state, memref, 1, nullptr, nullptr);">

    OpBuilder<(ins "mlir::Type":$memref, "int":$depth, "mlir::TypedAttr":$init_value),
        "build($_builder, $_state, memref, depth, init_value, nullptr);">,

    // OpBuilder<(ins "mlir::Type":$memref, "mlir::StringAttr":$string_attr),
    //     "build($_builder, $_state, memref, 1, string_attr);">

    // OpBuilder<(ins "mlir::Type":$memref, "mlir::TypedAttr":$init_value, "mlir::StringAttr":$string_attr),
    //     "build($_builder, $_state, memref, 1, init_value, string_attr);">
  ];
}

// def BufferOp : Codo_Op<"dataflow.buffer", [
//       DeclareOpInterfaceMethods<MemoryEffectsOpInterface>,
//       DeclareOpInterfaceMethods<BufferLikeInterface>]> {
//   let summary = "Represent a dataflow buffer";

//   let arguments = (ins I32Attr:$depth,
//                        OptionalAttr<TypedAttrInterface>:$init_value);
//   let results = (outs AnyBuffer:$memref);
//   let assemblyFormat = "attr-dict `:` type($memref)";

//   let hasVerifier = 1;
//   let hasCanonicalizer = 1;
//   let builders = [
//     OpBuilder<(ins "mlir::Type":$memref),
//         "build($_builder, $_state, memref, 1, nullptr);">
//   ];
// }


def ConstBufferOp : Codo_Op<"dataflow.const_buffer", [
      DeclareOpInterfaceMethods<MemoryEffectsOpInterface>,
      DeclareOpInterfaceMethods<BufferLikeInterface>]> {
  let summary = "Represent a constant dataflow buffer";

  let arguments = (ins ElementsAttr:$value);
  let results = (outs AnyBuffer:$memref);
  let assemblyFormat = "attr-dict `:` type($memref)";

  let hasVerifier = 1;
}

def StreamOp : Codo_Op<"dataflow.stream", [
      DeclareOpInterfaceMethods<MemoryEffectsOpInterface>]> {
  let summary = "Declare a stream channel";

  let arguments = (ins I32Attr:$depth);
  let results = (outs StreamOf<[AnyType]>:$channel);
  let assemblyFormat = "attr-dict `:` type($channel)";

  let hasVerifier = 1;
  let builders = [
    OpBuilder<(ins "mlir::Type":$channel),
        "build($_builder, $_state, channel, 1);">
  ];
}

def StreamReadOp : Codo_Op<"dataflow.stream_read", []> {
  let summary = "Read a stream channel";
  let description = [{
    Read/pop a value from a stream channel. The absence of the result indicates
    the popped value is dropped. Each stream channel can be read multiple times.
  }];

  let arguments = (ins StreamOf<[AnyType]>:$channel);
  let results = (outs Optional<AnyType>:$result);
  let assemblyFormat = [{
    $channel attr-dict `:` functional-type($channel, $result)
  }];

  let hasVerifier = 1;
}

def StreamWriteOp : Codo_Op<"dataflow.stream_write", []> {
  let summary = "Write a stream channel";
  let description = [{
    Write/push a value to a stream channel. Each stream channel can only be
    written once.
  }];

  let arguments = (ins StreamOf<[AnyType]>:$channel, AnyType:$value);
  let assemblyFormat = [{
    $channel `,` $value attr-dict `:` type($channel) `,` type($value)
  }];

  let hasVerifier = 1;
}


// def ExtReadOp : Codo_Op<"dataflow.stream_read", []> {
//   let summary = "Read from HBM/DDR in a burst manner";
//   let arguments = (ins StreamOf<[AnyType]>:$channel);
//   let results = (outs Optional<AnyType>:$result);
//   let assemblyFormat = [{
//     $channel attr-dict `:` functional-type($channel, $result)
//   }];

//   let hasVerifier = 1;
// }

// def ExtWriteOp : Codo_Op<"dataflow.stream_write", []> {
//   let summary = "Write to HBM/DDR";
//   // let description = [{
//   //   Write/push a value to a stream channel. Each stream channel can only be
//   //   written once.
//   // }];
//   let arguments = (ins StreamOf<[AnyType]>:$channel, AnyType:$value);
//   let assemblyFormat = [{
//     $channel `,` $value attr-dict `:` type($channel) `,` type($value)
//   }];

//   let hasVerifier = 1;
// }


#endif // Codo_OPS
