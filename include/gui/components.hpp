#pragma once

#include "gui/frame.hpp"
#include <functional>

class Button : public Component {
private:
    std::string text;
    std::function<void()> onClick;
    
public:
    Button(const std::string& buttonText, std::function<void()> callback)
        : text(buttonText), onClick(callback) {}
    
    void render() override {
        // Implementation in ImGui is handled in gui.cpp
    }
};

class Slider : public Component {
private:
    std::string label;
    float* value;
    float min, max;
    
public:
    Slider(const std::string& sliderLabel, float* val, float minVal, float maxVal)
        : label(sliderLabel), value(val), min(minVal), max(maxVal) {}
    
    void render() override {
        // Implementation in ImGui is handled in gui.cpp
    }
};

// Add other component types as needed
