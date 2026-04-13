/*
 * Copyright HeteroCL authors. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef CODO_TRANSLATION_EMITVITISHOST_H
#define CODO_TRANSLATION_EMITVITISHOST_H

#include "mlir/IR/BuiltinOps.h"

namespace mlir {
namespace codo {
LogicalResult emitVitisHost(ModuleOp module, llvm::raw_ostream &os);
void registerEmitVitisHostTranslation();

} // namespace codo
} // namespace mlir

#endif // CODO_TRANSLATION_EMITVITISHOST_H