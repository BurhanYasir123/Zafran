#pragma once

#include "Core.h"
#include "Scene.h"

namespace Zafran
{
    class ZF_API Application
    {
    public:
        Application();
        ~Application();

        virtual void Init();
        virtual void Update();
        virtual void OnEvent();
        virtual void SetScene(Scene scene);
        virtual bool ShouldExit();
        GLFWwindow* GetGlfwWindow();
        void SetGlfwWindow(GLFWwindow* window);
    
        Scene CurrentScene;
        GLFWwindow* m_window;
        bool ImGui;
        int deltatime;
    };
}