#pragma once

#include "Core.h"

namespace Zafran
{
    class ZF_API Input
    {
        static Input m_Instance;
        static GLFWwindow* m_window;
        bool IsKeyPressedImpl(int key);
        bool IsMouseButtonPressedImpl(int button);
        Vec2f GetMousePostionImpl();
    public:
        static inline void SetWindow(GLFWwindow* window) { m_window = window; }
        static inline bool IsKeyPressed(int key) { return m_Instance.IsKeyPressedImpl(key); }
        static inline bool IsMouseButtonPressed(int button) { return m_Instance.IsMouseButtonPressedImpl(button); }
        static inline Vec2f GetMousePostion() { return m_Instance.GetMousePostionImpl(); }
    };
}