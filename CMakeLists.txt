cmake_minimum_required(VERSION 3.15)
project(Charizard VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find required packages
find_package(Boost REQUIRED COMPONENTS system thread)
find_package(PkgConfig REQUIRED)
pkg_check_modules(CURL REQUIRED libcurl)
find_package(OpenSSL REQUIRED)

# Include directories
include_directories(include)
include_directories(third_party/nlohmann_json/include)
include_directories(third_party/imgui)

# Source files
set(SOURCES
    src/main.cpp
    src/core/config.cpp
    src/core/minecraft_client.cpp
    src/core/key_bindings.cpp
    
    src/network/packet_handler.cpp
    src/network/network_connection.cpp
    src/network/minecraft_protocol.cpp
    
    src/bot/bot_base.cpp
    src/bot/state_manager.cpp
    src/bot/session.cpp
    
    src/bot/bots/sumo.cpp
    src/bot/bots/boxing.cpp
    src/bot/bots/classic.cpp
    src/bot/bots/op.cpp
    src/bot/bots/combo.cpp
    
    src/bot/features/bow.cpp
    src/bot/features/rod.cpp
    src/bot/features/gap.cpp
    src/bot/features/potion.cpp
    src/bot/features/move_priority.cpp
    
    src/bot/player/mouse.cpp
    src/bot/player/movement.cpp
    src/bot/player/inventory.cpp
    src/bot/player/combat.cpp
    src/bot/player/lobby_movement.cpp
    
    src/utils/chat_utils.cpp
    src/utils/entity_utils.cpp
    src/utils/world_utils.cpp
    src/utils/http_utils.cpp
    src/utils/random_utils.cpp
    src/utils/time_utils.cpp
    src/utils/webhook.cpp
    src/utils/extensions.cpp
    
    src/gui/gui.cpp
    src/gui/frame.cpp
    src/gui/components.cpp
    src/gui/gl_utils.cpp
    
    src/commands/config_command.cpp
)

# ImGui sources
set(IMGUI_SOURCES
    third_party/imgui/imgui.cpp
    third_party/imgui/imgui_demo.cpp
    third_party/imgui/imgui_draw.cpp
    third_party/imgui/imgui_tables.cpp
    third_party/imgui/imgui_widgets.cpp
    third_party/imgui/backends/imgui_impl_glfw.cpp
    third_party/imgui/backends/imgui_impl_opengl3.cpp
)

# Create executable
add_executable(charizard ${SOURCES} ${IMGUI_SOURCES})

# Link libraries
target_link_libraries(charizard 
    ${Boost_LIBRARIES}
    ${CURL_LIBRARIES}
    OpenSSL::SSL
    OpenSSL::Crypto
    glfw
    GL
    pthread
)

# Compiler flags
target_compile_options(charizard PRIVATE -Wall -Wextra -O2)
