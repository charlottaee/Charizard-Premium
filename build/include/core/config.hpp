#pragma once

#include <string>
#include <map>
#include <memory>
#include <fstream>
#include <iostream>

class BotBase;

class Config {
private:
    static std::unique_ptr<Config> instance;
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
    
    // AutoGG settings
    bool sendAutoGG = true;
    std::string ggMessage = "gg";
    int ggDelay = 100;
    bool sendStartMessage = false;
    std::string startMessage = "GL HF!";
    int startMessageDelay = 100;
    
    // Dodging settings
    bool enableDodging = true;
    int dodgeWins = 4000;
    int dodgeWS = 15;
    float dodgeWLR = 3.0f;
    bool dodgeLostTo = true;
    bool dodgeNoStats = true;
    bool strictDodging = false;
    
    // Webhook settings
    bool sendWebhookMessages = false;
    std::string webhookURL = "";
    bool sendWebhookStats = false;
    bool sendWebhookDodge = false;
    
    // Misc settings
    bool boxingFish = false;
    
    void load();
    void save();
    void preload() { load(); }
    void writeData() { save(); }
    
    std::map<int, std::unique_ptr<BotBase>> createBots();
    
private:
    void loadSimpleFormat();
    void saveSimpleFormat();
    std::string trim(const std::string& str);
};
