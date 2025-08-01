#!/bin/bash

mkdir -p include/network include/entities include/core src/network src/entities src/core src/bot/bots

cat > include/network/minecraft_protocol.hpp << 'EOF'
#ifndef MINECRAFT_PROTOCOL_HPP
#define MINECRAFT_PROTOCOL_HPP

#include <string>

namespace network {

    enum class PacketType {
        LOGIN,
        POSITION,
        CHAT
    };

    struct Packet {
        PacketType type;
        std::string data;
    };

    class MinecraftProtocol {
    public:
        static Packet parsePacket(const std::string& raw);
        static std::string createPacket(const Packet& packet);
    };

}

#endif // MINECRAFT_PROTOCOL_HPP
EOF

cat > src/network/minecraft_protocol.cpp << 'EOF'
#include "network/minecraft_protocol.hpp"

namespace network {

    Packet MinecraftProtocol::parsePacket(const std::string& raw) {
        // Dummy implementation
        return Packet{ PacketType::CHAT, raw };
    }

    std::string MinecraftProtocol::createPacket(const Packet& packet) {
        // Dummy implementation
        return packet.data;
    }

}
EOF

cat > include/entities/entity.hpp << 'EOF'
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
EOF

cat > src/entities/entity.cpp << 'EOF'
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
EOF
