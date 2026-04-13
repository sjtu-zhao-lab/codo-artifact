#!/bin/bash

set -e

# 
SCRIPTS=(
    "./codo/3_32_32/mobilenet-small/run.tcl"
    "./codo/3_32_32/resnet-small/run.tcl"
    "./codo/3_32_32/vgg-small/run.tcl"
    "./codo/3_224_224/mobilenet-large/run.tcl"
    "./codo/3_224_224/resnet-large/run.tcl"
    "./codo/3_224_224/vgg-large/run.tcl"
    "./codo/3_224_224/yolo/run.tcl"
    "./codo/3_224_224/zfnet/run.tcl"
)

# 
START_TIME=$SECONDS

for i in "${!SCRIPTS[@]}"; do
    FILE=${SCRIPTS[$i]}
    echo "[$(date +%T)] processing $(($i+1))/${#SCRIPTS[@]} $FILE"
    
    #
    STEP_START=$SECONDS
    
    # 
    if vitis_hls "$FILE"; then
        DURATION=$(($SECONDS - $STEP_START))
        echo "Successfully finished $FILE in $DURATION seconds."
    else
        echo "Error: $FILE failed!"
        exit 1
    fi
    echo "----------------------------------------"
done

TOTAL_DURATION=$(($SECONDS - $START_TIME))
echo "done: $(($TOTAL_DURATION / 60)) min $(($TOTAL_DURATION % 60)) sec."