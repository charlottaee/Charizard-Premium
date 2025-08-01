#!/bin/bash
set -e

echo "🏗️  Building Charizard C++ (Minimal Version)..."

# Create build directory
mkdir -p build
cd build

# Configure with CMake (minimal dependencies)
echo "📋 Configuring with CMake (minimal mode)..."
cmake .. -DCMAKE_BUILD_TYPE=Release

# Build
echo "⚙️  Compiling..."
make -j$(nproc)

echo "✅ Minimal build complete!"

if [ -f bin/charizard ]; then
    echo "🎯 Executable created: ./build/bin/charizard"
    echo "🚀 Run with: ./build/bin/charizard"
else
    echo "❌ Build failed - executable not found"
    exit 1
fi
