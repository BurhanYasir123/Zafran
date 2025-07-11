#pragma once

#include "Core.h"

#include "Application.h"

namespace Zafran
{
    class ZF_API ImGuiRenderer
    {
    public:
        static void InitImGui(Application& app);
        static void InitFrame();
        static void RenderFrame();
        static void EndImGui();
    };
}