#pragma once

#include <string>
#include <map>
#include <memory>
#include <nlohmann/json.hpp>

class BotBase;

class Config {
private:
    static std::unique_ptr<Config> instance;
    nlohmann::json config_data;
    std::string config_file_path;
    
public:
    static Config& getInstance();
    
    // Bot settings
    int currentBot = 0;
    std::string apiKey = "";
    bool lobbyMovement = true;
    bool disableChatMessages = false;
    
    // Combat settings
    int minCPS = 10;
    int maxCPS = 14;
    int lookSpeedHorizontal = 10;
    int lookSpeedVertical = 5;
    float lookRand = 0.3f;
    int maxDistanceLook = 150;
    int maxDistanceAttack = 5;
    
    // More settings...
    
    void load();
    void save();
    void preload() { load(); }
    void writeData() { save(); }
    
    std::map<int, std::unique_ptr<BotBase>> createBots();
};
