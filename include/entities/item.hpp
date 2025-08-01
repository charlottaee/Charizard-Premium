#pragma once

#include <string>

class Item {
private:
    std::string name;
    int damage;
    
public:
    Item(const std::string& itemName, int itemDamage = 0) 
        : name(itemName), damage(itemDamage) {}
    
    std::string getName() const { return name; }
    int getDamage() const { return damage; }
};
