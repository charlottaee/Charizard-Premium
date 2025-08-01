#include <iostream>
#include <memory>
#include <chrono>
#include <thread>
#include <map>
#include "core/config.hpp"
#include "core/minecraft_client.hpp"
#include "bot/bot_base.hpp"

class Charizard {
private:
    std::shared_ptr<MinecraftClient> mc;
    std::map<int, std::unique_ptr<BotBase>> bots;
    std::unique_ptr<BotBase> currentBot;
    bool running = true;
    
public:
    Charizard() {
        mc = std::make_shared<MinecraftClient>();
        bots = Config::getInstance().createBots();
        
        // Set initial bot
        if (bots.find(Config::getInstance().currentBot) != bots.end()) {
            currentBot = std::move(bots[Config::getInstance().currentBot]);
        }
    }
    
    bool initialize() {
        std::cout << "Charizard C++ v0.1.0 initialized successfully!" << std::endl;
        std::cout << "Current bot: " << (currentBot ? currentBot->getName() : "None") << std::endl;
        std::cout << "Running in headless mode" << std::endl;
        std::cout << "Press Ctrl+C to exit" << std::endl;
        return true;
    }
    
    void run() {
        while (running) {
            // Update Minecraft client
            if (mc->isConnected()) {
                mc->tick();
                if (currentBot && currentBot->isToggled()) {
                    currentBot->onTick();
                }
            }
            
            // Small delay to prevent excessive CPU usage
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
    }
    
    void shutdown() {
        running = false;
        
        if (mc && mc->isConnected()) {
            mc->disconnect();
        }
        
        std::cout << "Charizard shutting down..." << std::endl;
    }
    
    void swapBot(int botId) {
        if (bots.find(botId) != bots.end()) {
            currentBot = std::move(bots[botId]);
            Config::getInstance().currentBot = botId;
            Config::getInstance().save();
            std::cout << "Switched to bot: " << currentBot->getName() << std::endl;
        }
    }
};

int main() {
    try {
        Charizard charizard;
        
        if (!charizard.initialize()) {
            return 1;
        }
        
        charizard.run();
        charizard.shutdown();
        
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
