#pragma once

#include <string>
#include <memory>
#include <atomic>
#include <map>
#include <vector>
#include <chrono>

class MinecraftClient;

class BotBase {
protected:
    std::atomic<bool> toggled{false};
    std::map<std::string, std::string> statKeys;
    
public:
    BotBase(const std::string& queueCommand) {}
    virtual ~BotBase() = default;
    
    virtual std::string getName() = 0;
    virtual void onTick() {}
    
    void toggle() { toggled = !toggled; }
    bool isToggled() const { return toggled; }
    
protected:
    void setStatKeys(const std::map<std::string, std::string>& keys) { 
        statKeys = keys; 
    }
};
