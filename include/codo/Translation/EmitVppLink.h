/*
 * Copyright HeteroCL authors. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef CODO_TRANSLATION_EMITVPPLINK_H
#define CODO_TRANSLATION_EMITVPPLINK_H

#include "mlir/IR/BuiltinOps.h"

namespace mlir {
namespace codo {

LogicalResult emitVppLink(ModuleOp module, llvm::raw_ostream &os);
void registerEmitVppLinkTranslation();

} // namespace codo
} // namespace mlir

#endif // CODO_TRANSLATION_EMITVPPLINK_H