#pragma once

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