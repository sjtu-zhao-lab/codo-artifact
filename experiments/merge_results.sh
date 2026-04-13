#!/bin/bash

set -euo pipefail

SCRIPT_PATH="$(realpath "$0")"
SCRIPT_DIR="$(dirname "$SCRIPT_PATH")"
OUTPUT_FILE="$SCRIPT_DIR/all_result.csv"

resolve_dir() {
    local primary="$1"
    local fallback="$2"
    if [[ -d "$SCRIPT_DIR/$primary" ]]; then
        echo "$SCRIPT_DIR/$primary"
    elif [[ -d "$SCRIPT_DIR/$fallback" ]]; then
        echo "$SCRIPT_DIR/$fallback"
    else
        echo ""
    fi
}

FIG_DIR="$(resolve_dir "fig11" "fig-11")"
TABLE2_DIR="$(resolve_dir "table-2" "table-2")"
TABLE34_DIR="$(resolve_dir "table-3_and_table-4" "table-3_and_table-4")"

{
    for dir in "$FIG_DIR" "$TABLE2_DIR" "$TABLE34_DIR"; do
        if [[ -n "$dir" && -f "$dir/result.csv" ]]; then
            printf "[%s]\n" "$(basename "$dir")"
            cat "$dir/result.csv"
            printf "\n\n"
        fi
    done
} > "$OUTPUT_FILE"

echo "Merged results saved to $OUTPUT_FILE"
