#!/bin/bash
set -e

echo "🚀 Setting up Charizard C++ development environment..."

# Update submodules
git submodule update --init --recursive

# Install dependencies on Ubuntu/Debian
if command -v apt-get >/dev/null 2>&1; then
    echo "📦 Installing dependencies via apt..."
    sudo apt update
    sudo apt install -y cmake g++ libboost-all-dev libcurl4-openssl-dev \
                        libssl-dev libglfw3-dev libgl1-mesa-dev pkg-config
fi

# Install dependencies on macOS
if command -v brew >/dev/null 2>&1; then
    echo "📦 Installing dependencies via brew..."
    brew install cmake boost curl openssl glfw
fi

echo "✅ Development environment setup complete!"
echo "🏗️  Run './build.sh' to build the project"
echo "🔍 Run './compile_check.sh' to check compilation without full build"
