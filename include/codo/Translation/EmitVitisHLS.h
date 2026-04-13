/*
 * Copyright HeteroCL authors. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef CODO_TRANSLATION_EMITVITISHLS_H
#define CODO_TRANSLATION_EMITVITISHLS_H

#include "mlir/IR/BuiltinOps.h"

namespace mlir {
namespace codo {

LogicalResult emitVitisHLS(ModuleOp module, llvm::raw_ostream &os);
void registerEmitVitisHLSTranslation();

} // namespace codo
} // namespace mlir

#endif // CODO_TRANSLATION_EMITVITISHLS_H