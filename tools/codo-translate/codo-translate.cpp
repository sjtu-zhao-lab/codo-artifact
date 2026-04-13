#include "codo/Translation/EmitVitisHLS.h"
#include "codo/Translation/EmitVitisHost.h"
#include "codo/Translation/EmitVppLink.h"
#include "mlir/InitAllTranslations.h"
#include "mlir/Support/LogicalResult.h"
#include "mlir/Tools/mlir-translate/MlirTranslateMain.h"


#include "codo/Dialect/CodoDialect.h"

int main(int argc, char **argv) {
  mlir::registerAllTranslations();
  mlir::codo::registerEmitVitisHLSTranslation();
  mlir::codo::registerEmitVitisHostTranslation();
  mlir::codo::registerEmitVppLinkTranslation();

  return failed(mlir::mlirTranslateMain(
      argc, argv, "codo MLIR Dialect Translation Tool"));
}
