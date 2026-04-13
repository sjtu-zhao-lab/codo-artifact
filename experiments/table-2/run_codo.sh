#!/bin/bash

BIN_DIR="/home/devuser/workspace/build/bin"
CODO_OPT="$BIN_DIR/codo-opt"
CODO_TRANS="$BIN_DIR/codo-translate"

if [[ ! -f "$CODO_OPT" || ! -f "$CODO_TRANS" ]]; then
    echo "Error: codo-opt or codo-translate not found in $BIN_DIR"
    exit 1
fi

CSV_FILE="./dsetime.csv"
DATASET_NAMES=()
DSETIME_VALUES=()


run_task() {
    local dataset=$1
    local type=$2
    local opt_args=$3
    local in_mlir=$4
    local mid_mlir=$5
    local out_cpp=$6
    local start_time
    start_time=$(date +%s.%N)

    echo "------------------------------------------------"
    echo "Processing: $in_mlir"
    
    #  codo-opt
    $CODO_OPT "-codo-$type-opt=$opt_args" "$in_mlir" -o "$mid_mlir"
    
    #  codo-translate
    $CODO_TRANS -emit-vitis-hls "$mid_mlir" -o "$out_cpp"

    local end_time
    end_time=$(date +%s.%N)
    local dsetime
    dsetime=$(awk -v s="$start_time" -v e="$end_time" 'BEGIN { printf "%.1f", (e - s) }')
    DATASET_NAMES+=("$dataset")
    DSETIME_VALUES+=("$dsetime")
    echo "Completed: $dataset, dsetime=${dsetime}s"
}


# Atax
run_task "Atax" "cpp" "top-func=main_graph debug-point=7 max-loop-parallelism=10" \
    "./codo/Atax/atax.mlir" "./codo/Atax/atax_7.mlir" "./codo/Atax/atax.cpp"

# Gesummv
run_task "Gesummv" "cpp" "top-func=main_graph debug-point=7 max-loop-parallelism=10" \
    "./codo/Gesummv/gesummv.mlir" "./codo/Gesummv/gesummv_7.mlir" "./codo/Gesummv/gesummv.cpp"

# Gemm
run_task "Gemm" "cpp" "top-func=main_graph debug-point=7 max-loop-parallelism=8 downscale-degree=1" \
    "./codo/Gemm/gemm.mlir" "./codo/Gemm/gemm_7.mlir" "./codo/Gemm/gemm.cpp"

# Mvt
run_task "Mvt" "cpp" "top-func=main_graph debug-point=7 max-loop-parallelism=10" \
    "./codo/Mvt/mvt.mlir" "./codo/Mvt/mvt_7.mlir" "./codo/Mvt/mvt.cpp"

# 3mm
run_task "3mm" "cpp" "top-func=main_graph debug-point=7 max-loop-parallelism=6 downscale-degree=1" \
    "./codo/3mm/3mm.mlir" "./codo/3mm/3mm_7.mlir" "./codo/3mm/3mm.cpp"

# Residualmlp
run_task "Residualmlp" "cpp" "top-func=main_graph debug-point=7 max-loop-parallelism=2 balance-degree=1" \
    "./codo/Residualmlp/residualmlp.mlir" "./codo/Residualmlp/residualmlp_7.mlir" "./codo/Residualmlp/residualmlp.cpp"

# Autoencoder
run_task "Autoencoder" "cpp" "top-func=main_graph debug-point=7 max-loop-parallelism=2 balance-degree=2" \
    "./codo/Autoencoder/autoencoder.mlir" "./codo/Autoencoder/autoencoder_7.mlir" "./codo/Autoencoder/autoencoder.cpp"

# ResidualBlock (Note: uses graph-opt)
run_task "ResidualBlock" "graph" "top-func=main_graph debug-point=12 max-parallelism=16" \
    "./codo/ResidualBlock/residualblock.mlir" "./codo/ResidualBlock/residualblock_12.mlir" "./codo/ResidualBlock/residualblock_nonaddertree.cpp"

# DwsConv (Note: uses graph-opt)
run_task "DwsConv" "graph" "top-func=main_graph debug-point=12 max-parallelism=64" \
    "./codo/DwsConv/dwsconv.mlir" "./codo/DwsConv/dwsconv_12.mlir" "./codo/DwsConv/dwsconv_nonaddertree.cpp"

# Feedforward
run_task "Feedforward" "cpp" "top-func=main_graph debug-point=7 max-loop-parallelism=4" \
    "./codo/Feedforward/feedforward.mlir" "./codo/Feedforward/feedforward_7.mlir" "./codo/Feedforward/feedforward.cpp"

# Attention
run_task "Attention" "cpp" "top-func=main_graph debug-point=7 max-loop-parallelism=2 balance-degree=1" \
    "./codo/Attention/attention.mlir" "./codo/Attention/attention_7.mlir" "./codo/Attention/attention.cpp"

run_task "3Conv" "graph" "top-func=main_graph debug-point=12 max-parallelism=16" \
    "./codo/3Conv/3conv.mlir" "./codo/3Conv/3conv_12.mlir" "./codo/3Conv/3conv_nonaddertree.cpp"

col_width=0
for dataset in "${DATASET_NAMES[@]}"; do
    if (( ${#dataset} > col_width )); then
        col_width=${#dataset}
    fi
done
for dsetime in "${DSETIME_VALUES[@]}"; do
    if (( ${#dsetime} > col_width )); then
        col_width=${#dsetime}
    fi
done
if (( 7 > col_width )); then
    col_width=7
fi
if (( 7 > col_width )); then
    col_width=7
fi
col_width=$((col_width + 2))

{
    printf "%-*s" "$col_width" "dataset"
    for dataset in "${DATASET_NAMES[@]}"; do
        printf "%-*s" "$col_width" "$dataset"
    done
    printf "\n"
    printf "%-*s" "$col_width" "dsetime"
    for dsetime in "${DSETIME_VALUES[@]}"; do
        printf "%-*s" "$col_width" "$dsetime"
    done
    printf "\n"
} > "$CSV_FILE"

echo "------------------------------------------------"
echo "dsetime table saved to $CSV_FILE"
echo "All tasks completed."
