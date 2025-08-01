
// include/bot/bots/combo.hpp
#pragma once

#include "bot/bot_base.hpp"
#include "bot/features/gap.hpp"
#include "bot/features/potion.hpp"
#include "bot/features/move_priority.hpp"
#include <map>

class Combo : public BotBase, public MovePriority, public Gap, public Potion {
private:
    bool tapping = false;
    
    int strengthPots = 2;
    int gaps = 32;
    int pearls = 5;
    
    std::chrono::steady_clock::time_point lastPearl;
    bool dontStartLeftAC = false;
    
    enum class ArmorEnum {
        BOOTS, LEGGINGS, CHESTPLATE, HELMET
    };
    
    std::map<int, int> armor = {{0, 1}, {1, 1}, {2, 1}, {3, 1}};
    
public:
    Combo();
    
    std::string getName() override { return "Combo"; }
    
    void onGameStart() override;
    void onGameEnd() override;
    void onTick() override;
};
