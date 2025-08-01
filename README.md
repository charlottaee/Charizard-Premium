# Charizard Premium C++

Advanced Minecraft PvP bot converted from Kotlin to C++ for better performance and stealth.

## Features

- Multiple bot types: Sumo, Boxing, Classic, OP, Combo
- Advanced combat AI with W-tapping, strafing, and combo management
- Queue dodging system with stat checking
- Auto-requeue and webhook integration
- ImGui-based configuration interface
- Cross-platform support (Windows/Linux)

## Building

### Prerequisites
- CMake 3.15+
- C++17 compatible compiler
- Boost libraries
- libcurl
- OpenSSL
- GLFW3
- OpenGL

### Ubuntu/Debian
```bash
sudo apt install cmake g++ libboost-all-dev libcurl4-openssl-dev libssl-dev libglfw3-dev libgl1-mesa-dev
```

### Build Steps
```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
```

## Usage

1. Run the executable: `./charizard`
2. Configure settings via the GUI
3. Set your Hypixel API key
4. Toggle the bot with the configured keybind

## Configuration

The bot creates a config file at `config/charizard.json` with all settings.

## Disclaimer

This software is for educational purposes only. Use at your own risk.
