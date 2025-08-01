
// include/bot/bots/boxing.hpp
#pragma once

#include "bot/bot_base.hpp"
#include "bot/features/move_priority.hpp"
#include <memory>
#include <chrono>

class Boxing : public BotBase, public MovePriority {
private:
    bool tapping = false;
    std::shared_ptr<std::thread> fishTimer;
    
public:
    Boxing();
    
    std::string getName() override { return "Boxing"; }
    
    void onGameStart() override;
    void onGameEnd() override;
    void onAttack() override;
    void onTick() override;
    
private:
    void fishFunc(bool fish = true);
};
