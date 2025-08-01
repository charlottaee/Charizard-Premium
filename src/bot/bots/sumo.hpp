#pragma once

#include "bot/bot_base.hpp"

class Sumo : public BotBase {
private:
    bool tapping = false;
    bool opponentOffEdge = false;
    bool tap50 = false;
    
public:
    Sumo();
    
    std::string getName() override { return "Sumo"; }
    
    void onJoinGame() override;
    void beforeStart() override;
    void beforeLeave() override;
    void onGameStart() override;
    void onGameEnd() override;
    void onAttack() override;
    void onFoundOpponent() override;
    void onTick() override;
};
