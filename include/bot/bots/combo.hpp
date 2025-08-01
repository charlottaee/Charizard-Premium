#pragma once
#include "bot/bot_base.hpp"
class Combo : public BotBase {
public:
    Combo() : BotBase("/play duels_combo_duel") {}
    std::string getName() override { return "Combo"; }
};
