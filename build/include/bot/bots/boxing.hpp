#pragma once
#include "bot/bot_base.hpp"
class Boxing : public BotBase {
public:
    Boxing() : BotBase("/play duels_boxing_duel") {}
    std::string getName() override { return "Boxing"; }
};
