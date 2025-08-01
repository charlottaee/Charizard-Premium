#!/bin/bash
set -e

echo "Building Charizard C++..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake
cmake ..

# Build
make -j$(nproc)

echo "Build complete! Executable: ./build/charizard"
