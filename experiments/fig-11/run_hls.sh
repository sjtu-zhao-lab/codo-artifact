#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

# Define the list of directories to process
DIRECTORIES=("1" "2" "4" "8" "16" "32")

# Capture the total start time
TOTAL_START=$(date +%s)
echo "-------------------------------------------------------"
echo "HLS Batch Processing started at: $(date)"
echo "-------------------------------------------------------"

# Loop through each directory and run vitis_hls
for DIR in "${DIRECTORIES[@]}"; do
    TCL_FILE="./$DIR/resnet18.tcl"
    
    if [ -f "$TCL_FILE" ]; then
        echo ">>> Processing: $TCL_FILE"
        
        # Capture start time for this specific task
        TASK_START=$(date +%s)
        
        # Execute Vitis HLS
        vitis_hls "$TCL_FILE"
        
        # Calculate time for this specific task
        TASK_END=$(date +%s)
        TASK_DIFF=$((TASK_END - TASK_START))
        echo ">>> Finished $DIR in $((TASK_DIFF / 60))m $((TASK_DIFF % 60))s."
    else
        echo "!!! Warning: $TCL_FILE not found, skipping..."
    fi
    echo "-------------------------------------------------------"
done

# Capture the total end time
TOTAL_END=$(date +%s)
TOTAL_DIFF=$((TOTAL_END - TOTAL_START))

# Calculate total hours, minutes, and seconds
HOURS=$((TOTAL_DIFF / 3600))
MINS=$(( (TOTAL_DIFF % 3600) / 60 ))
SECS=$((TOTAL_DIFF % 60))

echo "Batch Processing Completed!"
echo "Total Execution Time: ${HOURS}h ${MINS}m ${SECS}s"
echo "-------------------------------------------------------"