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
