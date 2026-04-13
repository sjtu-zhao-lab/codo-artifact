#!/bin/bash

set -e

BIN_DIR="/home/devuser/workspace/build/bin"
CODO_OPT="$BIN_DIR/codo-opt"
CODO_TRANSLATE="$BIN_DIR/codo-translate"
CSV_FILE="./CompilationTime.csv"
DATASET_NAMES_32=()
COMPILATION_TIMES_32=()
DATASET_NAMES_224=()
COMPILATION_TIMES_224=()

process_model() {
    local DIR=$1
    local NAME=$2
    local PARALLEL=$3
    local EXTRA_OPTS=$4
    local GROUP=$5
    local start_time
    start_time=$(date +%s.%N)

    echo "--------------------------------------"
    echo "Processing: $NAME in $DIR (Parallelism: $PARALLEL)"
    
    # 1.  codo-opt
    $CODO_OPT -codo-graph-opt="top-func=main_graph debug-point=12 max-parallelism=$PARALLEL $EXTRA_OPTS" \
        "$DIR/$NAME.mlir" -o "$DIR/${NAME}_12.mlir"

    # 2.  codo-translate
    $CODO_TRANSLATE -emit-vitis-hls "$DIR/${NAME}_12.mlir" -o "$DIR/$NAME.cpp"

    local end_time
    end_time=$(date +%s.%N)
    local compilation_time
    compilation_time=$(awk -v s="$start_time" -v e="$end_time" 'BEGIN { printf "%.1f", (e - s) }')
    if [[ "$GROUP" == "3_32_32" ]]; then
        DATASET_NAMES_32+=("$NAME")
        COMPILATION_TIMES_32+=("$compilation_time")
    else
        DATASET_NAMES_224+=("$NAME")
        COMPILATION_TIMES_224+=("$compilation_time")
    fi
    
    echo "Done: $NAME, CompilationTime=${compilation_time}s"
}


process_model "./codo/3_32_32/mobilenet-small" "mobilenet" 16 "" "3_32_32"
process_model "./codo/3_32_32/resnet-small"    "resnet18"  8  "" "3_32_32"
process_model "./codo/3_32_32/vgg-small"       "vgg16"     8  "" "3_32_32"


process_model "./codo/3_224_224/mobilenet-large" "mobilenet" 32 "adjust-cnt=2" "3_224_224"
process_model "./codo/3_224_224/resnet-large"    "resnet18"  8  ""             "3_224_224"
process_model "./codo/3_224_224/vgg-large"       "vgg16"     16 ""             "3_224_224"
process_model "./codo/3_224_224/yolo"            "yolo"      32 ""             "3_224_224"
process_model "./codo/3_224_224/zfnet"           "zfnet"     16 ""             "3_224_224"

width_32=15
for dataset in "${DATASET_NAMES_32[@]}"; do
    if (( ${#dataset} > width_32 )); then
        width_32=${#dataset}
    fi
done
for t in "${COMPILATION_TIMES_32[@]}"; do
    if (( ${#t} > width_32 )); then
        width_32=${#t}
    fi
done
width_32=$((width_32 + 2))

width_224=15
for dataset in "${DATASET_NAMES_224[@]}"; do
    if (( ${#dataset} > width_224 )); then
        width_224=${#dataset}
    fi
done
for t in "${COMPILATION_TIMES_224[@]}"; do
    if (( ${#t} > width_224 )); then
        width_224=${#t}
    fi
done
width_224=$((width_224 + 2))

{
    printf "3_32_32\n"
    printf "%-*s" "$width_32" "dataset"
    for dataset in "${DATASET_NAMES_32[@]}"; do
        printf "%-*s" "$width_32" "$dataset"
    done
    printf "\n"
    printf "%-*s" "$width_32" "CompilationTime"
    for t in "${COMPILATION_TIMES_32[@]}"; do
        printf "%-*s" "$width_32" "$t"
    done
    printf "\n\n"
    printf "3_224_224\n"
    printf "%-*s" "$width_224" "dataset"
    for dataset in "${DATASET_NAMES_224[@]}"; do
        printf "%-*s" "$width_224" "$dataset"
    done
    printf "\n"
    printf "%-*s" "$width_224" "CompilationTime"
    for t in "${COMPILATION_TIMES_224[@]}"; do
        printf "%-*s" "$width_224" "$t"
    done
    printf "\n"
} > "$CSV_FILE"

python3 replace_float_with_int8_t.py

echo "======================================"
echo "CompilationTime tables saved to $CSV_FILE"
echo "all done!"
