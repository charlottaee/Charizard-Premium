#pragma once

#include <vector>
#include <memory>
#include <functional>

class PacketHandler {
private:
    std::vector<std::function<void(const std::vector<uint8_t>&)>> handlers;
    
public:
    PacketHandler();
    ~PacketHandler();
    
    void registerHandler(std::function<void(const std::vector<uint8_t>&)> handler);
    void handlePacket(const std::vector<uint8_t>& packet);
    
    // Specific packet handlers
    void handleEntityStatus(const std::vector<uint8_t>& packet);
    void handleTeams(const std::vector<uint8_t>& packet);
    void handleTitle(const std::vector<uint8_t>& packet);
};
