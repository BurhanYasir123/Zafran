#pragma once
#include "Core.h"

namespace Zafran
{
    class ZF_API Window
    {
    public:
        Window();
        ~Window();

        static GLFWwindow* Init(Vec2i size, const char* title);
    };
}