cmake_minimum_required(VERSION 3.10)
project(Charizard)

set(CMAKE_CXX_STANDARD 17)

# Source files
set(SOURCES
    src/main.cpp
    src/core/config.cpp
    src/core/minecraft_client.cpp
    src/bot/bot_base.cpp
    src/bot/bots/sumo.cpp
    src/bot/bots/boxing.cpp
    src/bot/bots/classic.cpp
    src/bot/bots/op.cpp
    src/bot/bots/combo.cpp
)

# Create executable
add_executable(charizard ${SOURCES})

# Include directories
target_include_directories(charizard PRIVATE include)

# Link pthread
target_link_libraries(charizard pthread)

# Output directory
set_target_properties(charizard PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

message(STATUS "=== Charizard C++ Build ===")
message(STATUS "Sources: ${SOURCES}")
message(STATUS "========================")
