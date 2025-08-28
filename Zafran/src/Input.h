#pragma once

#include "Core.h"

//[========================[]=========================]
//[==============[TODO--------------]=================]
//[==============[--IMPLEMENT INPUTS]=================]
//[=======================[]==========================]

namespace Zafran
{
    class ZF_API Input
    {
        static Input m_Instance;
        static SDL_Window* m_window;
        bool IsKeyPressedImpl(int key);
        bool IsMouseButtonPressedImpl(int button);
        Vec2f GetMousePostionImpl();
    public:
        static inline void SetWindow(SDL_Window* window) { m_window = window; }
        static inline bool IsKeyPressed(int key) { return m_Instance.IsKeyPressedImpl(key); }
        static inline bool IsMouseButtonPressed(int button) { return m_Instance.IsMouseButtonPressedImpl(button); }
        static inline Vec2f GetMousePostion() { return m_Instance.GetMousePostionImpl(); }
    };
}