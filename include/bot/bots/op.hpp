#pragma once
#include "bot/bot_base.hpp"
class OP : public BotBase {
public:
    OP() : BotBase("/play duels_op_duel") {}
    std::string getName() override { return "OP"; }
};
