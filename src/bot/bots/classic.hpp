// include/bot/bots/classic.hpp
#pragma once

#include "bot/bot_base.hpp"
#include "bot/features/bow.hpp"
#include "bot/features/rod.hpp"
#include "bot/features/move_priority.hpp"

class Classic : public BotBase, public Bow, public Rod, public MovePriority {
private:
    int shotsFired = 0;
    int maxArrows = 5;
    bool tapping = false;
    
public:
    Classic();
    
    std::string getName() override { return "Classic"; }
    
    void onGameStart() override;
    void onGameEnd() override;
    void onAttack() override;
    void onTick() override;
};
