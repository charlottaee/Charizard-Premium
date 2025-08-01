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
