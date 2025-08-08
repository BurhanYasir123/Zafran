#pragma once

#include "Core.h"
#include "Scene.h"
#include "Window.h"

namespace Zafran
{
    class ZF_API Application
    {
    public:
        Application();
        ~Application();

        virtual void PreInit();
        virtual void Init();
        virtual void Update();
        virtual void OnEvent();
        virtual void SetScene(Scene scene);
        virtual bool ShouldExit();

        void SetWindow(Window window);
        Window GetWindow();
    
        Scene CurrentScene;
        Window m_window;
        bool ImGui;
        int deltatime;
        int time;
        bool WindowInitDone;
    };
}