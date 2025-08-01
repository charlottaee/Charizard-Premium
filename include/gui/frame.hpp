#pragma once

#include <string>
#include <vector>
#include <memory>

// For now, we're using ImGui directly, so these are placeholder classes
// In the original Kotlin version, these were custom GUI components

class Component {
public:
    virtual ~Component() = default;
    virtual void render() = 0;
};

class Frame {
private:
    std::string title;
    std::vector<std::unique_ptr<Component>> components;
    
public:
    Frame(const std::string& frameTitle) : title(frameTitle) {}
    
    void addComponent(std::unique_ptr<Component> component) {
        components.push_back(std::move(component));
    }
    
    void render() {
        // TODO: Implement frame rendering
        // For now, we use ImGui directly in gui.cpp
    }
};
