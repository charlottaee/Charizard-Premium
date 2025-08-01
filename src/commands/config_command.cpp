#include "commands/config_command.hpp"
#include "gui/gui.hpp"
#include <iostream>

void ConfigCommand::register() {
    std::cout << "Config command registered" << std::endl;
}

void ConfigCommand::handle() {
    std::cout << "Opening config GUI..." << std::endl;
    // TODO: Open config GUI
}
