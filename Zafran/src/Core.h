#pragma once

#include <iostream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#ifdef ZAFRAN_BUILD_DLL
    #define ZF_API __attribute__((visibility("default")))
#else
    #define ZF_API
#endif

#define UID int

#define ZF_INFO(...)        std::cout << "[APP :: INFO]"   << __VA_ARGS__ << std::endl;
#define ZF_WARN(...)        std::cout << "[APP :: WARN]"   << __VA_ARGS__ << std::endl;
#define ZF_ERROR(...)       std::cout << "[APP :: ERROR]"  << __VA_ARGS__ << std::endl;

#define ZF_CORE_INFO(...)   std::cout << "[CORE :: INFO]"  << __VA_ARGS__ << std::endl;
#define ZF_CORE_WARN(...)   std::cout << "[CORE :: WARN]"  << __VA_ARGS__ << std::endl;
#define ZF_CORE_ERROR(...)  std::cout << "[CORE :: ERROR]" << __VA_ARGS__ << std::endl;

//vecs
struct Vec3f {
    float x, y, z;
    Vec3f(float _x = 0.0f, float _y = 0.0f, float _z = 0.0f) : x(_x), y(_y), z(_z) {}
    Vec3f operator+(const Vec3f& other) const {
         return Vec3f(x + other.x, y + other.y, z + other.z);
    }
};

struct Vec2f {
    float x, y;
    Vec2f(float _x = 0.0f, float _y = 0.0f) : x(_x), y(_y) {}
    Vec2f operator+(const Vec2f& other) const {
         return Vec2f(x + other.x, y + other.y);
    }
};

struct Vec2i {
    int x, y;
    Vec2i(int _x = 0.0f, int _y = 0.0f) : x(_x), y(_y) {}
    Vec2i operator+(const Vec2f& other) const {
         return Vec2i(x + other.x, y + other.y);
    }
};

