#!/bin/bash

# Exit immediately if a command exits with a non-zero status
set -e

# Capture the start time in seconds
START_TIME=$(date +%s)
echo "-------------------------------------------"
echo "Build started at: $(date)"
echo "-------------------------------------------"

# Define paths for dependencies
# Adjust these paths if your directory structure changes
TORCH_MLIR_BUILD_DIR="/home/devuser/workspace/third-party/torch-mlir/build"
MLIR_CMAKE_DIR="$TORCH_MLIR_BUILD_DIR/lib/cmake/mlir"
LLVM_LIT_PATH="$TORCH_MLIR_BUILD_DIR/bin/llvm-lit"

# Step 1: Create and enter the build directory
# Use -p to avoid errors if the directory already exists
echo "[1/3] Creating build directory..."
mkdir -p build 
cd build

# Step 2: Configure the project using CMake and Ninja
echo "[2/3] Configuring project with CMake..."
/usr/local/bin/cmake -G Ninja .. \
   -DMLIR_DIR="$MLIR_CMAKE_DIR" \
   -DLLVM_EXTERNAL_LIT="$LLVM_LIT_PATH"

# Step 3: Compile the project
echo "[3/3] Compiling project..."
/usr/local/bin/cmake --build . 

# Capture the end time
END_TIME=$(date +%s)

# Calculate duration
DURATION=$((END_TIME - START_TIME))
MINUTES=$((DURATION / 60))
SECONDS=$((DURATION % 60))

echo "-------------------------------------------"
echo "Build completed successfully!"
echo "Total Execution Time: ${MINUTES}m ${SECONDS}s"
echo "-------------------------------------------"