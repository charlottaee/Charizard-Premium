// include/bot/bots/op.hpp
#pragma once

#include "bot/bot_base.hpp"
#include "bot/features/bow.hpp"
#include "bot/features/rod.hpp"
#include "bot/features/move_priority.hpp"
#include "bot/features/potion.hpp"
#include "bot/features/gap.hpp"

class OP : public BotBase, public Bow, public Rod, public MovePriority, public Potion, public Gap {
private:
    int shotsFired = 0;
    int maxArrows = 20;
    
    int speedDamage = 16386;
    int regenDamage = 16385;
    
    int speedPotsLeft = 2;
    int regenPotsLeft = 2;
    int gapsLeft = 6;
    
    std::chrono::steady_clock::time_point lastSpeedUse;
    std::chrono::steady_clock::time_point lastRegenUse;
    
    bool tapping = false;
    
public:
    OP();
    
    std::string getName() override { return "OP"; }
    
    void onGameStart() override;
    void onGameEnd() override;
    void onAttack() override;
    void onTick() override;
};
