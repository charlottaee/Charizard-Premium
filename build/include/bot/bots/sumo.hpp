#pragma once
#include "bot/bot_base.hpp"

class Sumo : public BotBase {
public:
    Sumo() : BotBase("/play duels_sumo_duel") {
        setStatKeys({
            {"wins", "player.stats.Duels.sumo_duel_wins"},
            {"losses", "player.stats.Duels.sumo_duel_losses"},
            {"ws", "player.stats.Duels.current_sumo_winstreak"}
        });
    }
    
    std::string getName() override { return "Sumo"; }
    
    void onTick() override {
        // Sumo bot logic here
    }
};
