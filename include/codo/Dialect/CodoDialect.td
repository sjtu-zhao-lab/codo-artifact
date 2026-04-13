#ifndef CODO_DIALECT
#define CODO_DIALECT

include "mlir/IR/OpBase.td"

//===----------------------------------------------------------------------===//
// codo dialect definition.
//===----------------------------------------------------------------------===//

def Codo_Dialect : Dialect {
    let name = "codo";
    let summary = "An out-of-tree MLIR dialect: codo dialect.";
    let description = [{
        The codo dialect is designed for large-scale ML model acceleration on
        Multi-FPGA back-ends.
    }];
    let cppNamespace = "::mlir::codo";

    let useDefaultTypePrinterParser = 1;
    let useDefaultAttributePrinterParser = 1;
    // let extraClassDeclaration = [{
    //     void registerTypes();
    // }];
}

//===----------------------------------------------------------------------===//
// Base codo operation definition.
//===----------------------------------------------------------------------===//

class Codo_Op<string mnemonic, list<Trait> traits = []> :
        Op<Codo_Dialect, mnemonic, traits>;


class Codo_Type<string mnemonic, list<Trait> traits = []> : 
        TypeDef<Codo_Dialect, mnemonic, traits>;

// class Codo_Attr<string mnemonic, list<Trait> traits = []> : 
//         AttrDef<Codo_Dialect, mnemonic, traits>;
// class Codo_Attr<string name> : AttrDef<Codo_Dialect, name>;
class Codo_Attr<string name, list<Trait> traits = []> :
    AttrDef<Codo_Dialect, name, traits>;
#endif // Codo_DIALECT
