#pragma once
#include "Core.h"

namespace Zafran
{
    class ZF_API Window
    {
    public:
        Window();
        ~Window();

        static Window Init(Vec2i size, const char* title);

        GLFWwindow* GetGlfwWindow() { return m_window; };
        void SetGlfwWindow(GLFWwindow* window) { m_window = window; };
        Vec2i GetWindowSize() { return m_size; };

    private:
        GLFWwindow* m_window;
        static Vec2i m_size;
    };
}
