#pragma once

#include <memory>
#include <string>
#include <atomic>

class MinecraftClient {
private:
    std::atomic<bool> running{false};
    
public:
    MinecraftClient() = default;
    ~MinecraftClient() = default;
    
    bool connect(const std::string& server, int port) {
        running = true;
        return true;
    }
    
    void disconnect() {
        running = false;
    }
    
    void tick() {
        // Game update logic
    }
    
    void sendChatMessage(const std::string& message) {
        std::cout << "Chat: " << message << std::endl;
    }
    
    bool isConnected() const { return running; }
};
