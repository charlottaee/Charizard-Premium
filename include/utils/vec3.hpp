#pragma once

#include <cmath>

struct Vec3 {
    double x, y, z;
    
    Vec3() : x(0), y(0), z(0) {}
    Vec3(double x, double y, double z) : x(x), y(y), z(z) {}
    
    Vec3 operator+(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }
    
    Vec3 operator-(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }
    
    Vec3 operator*(double scalar) const {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }
    
    double lengthVector() const {
        return std::sqrt(x * x + y * y + z * z);
    }
    
    double distanceTo(const Vec3& other) const {
        return (*this - other).lengthVector();
    }
    
    Vec3 scale(double scalar) const {
        return *this * scalar;
    }
    
    Vec3 rotateYaw(float yaw) const {
        float radians = yaw * M_PI / 180.0f;
        float cos_yaw = std::cos(radians);
        float sin_yaw = std::sin(radians);
        
        return Vec3(
            x * cos_yaw - z * sin_yaw,
            y,
            x * sin_yaw + z * cos_yaw
        );
    }
};
