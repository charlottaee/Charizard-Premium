#include "core/config.hpp"
#include "bot/bots/sumo.hpp"
#include "bot/bots/boxing.hpp"
#include "bot/bots/classic.hpp"
#include "bot/bots/op.hpp"
#include "bot/bots/combo.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>

std::unique_ptr<Config> Config::instance = nullptr;

Config& Config::getInstance() {
    if (!instance) {
        instance = std::make_unique<Config>();
        instance->load();
    }
    return *instance;
}

void Config::load() {
    config_file_path = "./config/charizard.conf";
    loadSimpleFormat();
}

void Config::save() {
    saveSimpleFormat();
}

void Config::loadSimpleFormat() {
    std::ifstream file(config_file_path);
    if (!file.is_open()) {
        std::cout << "Config file not found, creating default..." << std::endl;
        save();
        return;
    }
    
    std::string line;
    while (std::getline(file, line)) {
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;
        
        size_t pos = line.find('=');
        if (pos == std::string::npos) continue;
        
        std::string key = trim(line.substr(0, pos));
        std::string value = trim(line.substr(pos + 1));
        
        try {
            if (key == "currentBot") currentBot = std::stoi(value);
            else if (key == "apiKey") apiKey = value;
            else if (key == "lobbyMovement") lobbyMovement = (value == "true");
            else if (key == "disableChatMessages") disableChatMessages = (value == "true");
            else if (key == "minCPS") minCPS = std::stoi(value);
            else if (key == "maxCPS") maxCPS = std::stoi(value);
            else if (key == "lookSpeedHorizontal") lookSpeedHorizontal = std::stoi(value);
            else if (key == "lookSpeedVertical") lookSpeedVertical = std::stoi(value);
            else if (key == "lookRand") lookRand = std::stof(value);
            else if (key == "maxDistanceLook") maxDistanceLook = std::stoi(value);
            else if (key == "maxDistanceAttack") maxDistanceAttack = std::stoi(value);
            else if (key == "sendAutoGG") sendAutoGG = (value == "true");
            else if (key == "ggMessage") ggMessage = value;
            else if (key == "enableDodging") enableDodging = (value == "true");
            else if (key == "dodgeWins") dodgeWins = std::stoi(value);
            else if (key == "dodgeWS") dodgeWS = std::stoi(value);
            else if (key == "dodgeWLR") dodgeWLR = std::stof(value);
            else if (key == "webhookURL") webhookURL = value;
            else if (key == "boxingFish") boxingFish = (value == "true");
        } catch (const std::exception& e) {
            std::cerr << "Error parsing config key '" << key << "': " << e.what() << std::endl;
        }
    }
}

void Config::saveSimpleFormat() {
    system("mkdir -p config");
    
    std::ofstream file(config_file_path);
    if (!file.is_open()) {
        std::cerr << "Failed to create config file!" << std::endl;
        return;
    }
    
    file << "# Charizard C++ Configuration File\n";
    file << "currentBot=" << currentBot << "\n";
    file << "apiKey=" << apiKey << "\n";
    file << "lobbyMovement=" << (lobbyMovement ? "true" : "false") << "\n";
    file << "minCPS=" << minCPS << "\n";
    file << "maxCPS=" << maxCPS << "\n";
    file << "enableDodging=" << (enableDodging ? "true" : "false") << "\n";
    file << "dodgeWins=" << dodgeWins << "\n";
    file << "webhookURL=" << webhookURL << "\n";
    file << "boxingFish=" << (boxingFish ? "true" : "false") << "\n";
    
    std::cout << "Config saved to " << config_file_path << std::endl;
}

std::string Config::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

std::map<int, std::unique_ptr<BotBase>> Config::createBots() {
    std::map<int, std::unique_ptr<BotBase>> bots;
    bots[0] = std::make_unique<Sumo>();
    bots[1] = std::make_unique<Boxing>();
    bots[2] = std::make_unique<Classic>();
    bots[3] = std::make_unique<OP>();
    bots[4] = std::make_unique<Combo>();
    return bots;
}
