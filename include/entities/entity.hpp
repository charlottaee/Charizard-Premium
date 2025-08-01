#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <memory>

namespace entities {

    class Entity {
    public:
        Entity(const std::string& name);
        virtual ~Entity() = default;

        virtual void update();
        std::string getName() const;

    protected:
        std::string name;
    };

}

#endif // ENTITY_HPP
