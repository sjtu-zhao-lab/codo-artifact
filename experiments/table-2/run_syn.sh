#!/bin/bash

# 定义包含 run.tcl 的目录列表
PROJECTS=(
    # "Atax"
    # "Gesummv"
    # "Gemm"
    # "Mvt"
    # "3mm"
    # "Residualmlp"
    "Autoencoder"
    # "ResidualBlock"
    "DwsConv"
    # "Feedforward"
    # "Attention"
    # "3Conv"
)

# 基础路径
BASE_DIR="./codo"

# 检查 vitis_hls 命令是否存在
if ! command -v vitis_hls &> /dev/null; then
    echo "Error: vitis_hls command could not be found. Please check your Xilinx environment settings."
    exit 1
fi

echo "Starting Vitis HLS synthesis tasks..."
script_start=$SECONDS

# 循环执行
for proj in "${PROJECTS[@]}"; do
    TCL_FILE="$BASE_DIR/$proj/run.tcl"
    
    if [ -f "$TCL_FILE" ]; then
        echo "===================================================="
        echo "Running: vitis_hls $TCL_FILE"
        echo "===================================================="
        
        proj_start=$SECONDS
        vitis_hls "$TCL_FILE"
        vitis_status=$?
        proj_elapsed=$((SECONDS - proj_start))
        echo "Elapsed: $proj ${proj_elapsed}s"
        
        if [ $vitis_status -ne 0 ]; then
            echo "Error: vitis_hls failed on $proj"
            # 如果你想在某个任务失败时停止整个脚本，可以取消下面这一行的注释
            # exit 1
        fi
    else
        echo "Warning: $TCL_FILE not found, skipping..."
    fi
done

total_elapsed=$((SECONDS - script_start))
echo "Total elapsed: ${total_elapsed}s"
echo "All Vitis HLS tasks completed."
