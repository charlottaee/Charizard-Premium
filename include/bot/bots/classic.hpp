#pragma once
#include "bot/bot_base.hpp"
class Classic : public BotBase {
public:
    Classic() : BotBase("/play duels_classic_duel") {}
    std::string getName() override { return "Classic"; }
};
