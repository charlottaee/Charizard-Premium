#include "entities/entity.hpp"
#include <iostream>

namespace entities {

    Entity::Entity(const std::string& name) : name(name) {}

    void Entity::update() {
        std::cout << "Updating entity: " << name << std::endl;
    }

    std::string Entity::getName() const {
        return name;
    }

}
