#!/bin/bash
set -e

echo "🔍 Checking C++ compilation..."

# Create temporary build directory
mkdir -p build_check
cd build_check

# Configure with CMake
cmake .. -DCMAKE_BUILD_TYPE=Debug

# Try to compile (but don't link - we might be missing some implementations)
make -j$(nproc) 2>&1 | tee compile_output.txt

echo "✅ Compilation check complete. Check compile_output.txt for details."
