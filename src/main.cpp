#include <iostream>
#include "core/config.hpp"

int main() {
    std::cout << "Charizard C++ v0.1.0 starting..." << std::endl;
    
    Config& config = Config::getInstance();
    std::cout << "Config loaded successfully!" << std::endl;
    
    // TODO: Initialize full application
    
    return 0;
}
