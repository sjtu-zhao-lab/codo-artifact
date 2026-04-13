#!/bin/bash

set -euo pipefail

SCRIPT_PATH="$(realpath "$0")"
SCRIPT_DIR="$(dirname "$SCRIPT_PATH")"

run_step() {
    local dir="$1"
    local cmd="$2"
    echo "===================================================="
    echo "[RUN] $dir :: $cmd"
    echo "===================================================="
    (
        cd "$SCRIPT_DIR/$dir"
        eval "$cmd"
    )
}

run_step "fig-11" "bash run_hls.sh"
run_step "fig-11" "python3 extract_rpt_metrics.py"

run_step "table-2" "bash run_codo.sh"
run_step "table-2" "bash run_syn.sh"
run_step "table-2" "python3 batch_extract_rpt_metrics.py"

run_step "table-3_and_table-4" "bash run_ae.sh"
run_step "table-3_and_table-4" "bash run_hls.sh"
run_step "table-3_and_table-4" "python3 batch_extract_rpt_metrics.py"

echo "===================================================="
echo "All experiments finished."
