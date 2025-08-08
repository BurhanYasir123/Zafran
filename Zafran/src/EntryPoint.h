#pragma once

#include "Application.h"
#include "Object.h"

#include "ImGui/ImGuiRenderer.h"
#include "Renderer/Renderer.h"
#include "Input.h"
#include "ObjectManager.h"

namespace Zafran
{
    void RunApplication(Application& app)
    {
        app.PreInit();

        ObjectManager::EvaluateQueue_Init(app.GetWindow().GetWindowSize());
        
        app.Init();
        app.deltatime = 1000/60;
     
        Input::SetWindow(app.GetWindow().GetGlfwWindow());   
   
        while(!(app.ShouldExit() || glfwWindowShouldClose(app.GetWindow().GetGlfwWindow())))
        {
            // Deltatime calculation
            auto start = std::chrono::high_resolution_clock::now();
            
            glfwPollEvents();
            
            // For ImGui Frames
            if(app.ImGui) ImGuiRenderer::InitFrame();
            
            glClear(GL_COLOR_BUFFER_BIT);
            
            app.Update();
            
            // For ImGui Render
            if(app.ImGui) ImGuiRenderer::RenderFrame();
            
            glfwSwapBuffers(app.GetWindow().GetGlfwWindow());
            
            // Deltatime and Time Calcualtion
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> duration = end - start;
            app.deltatime = duration.count() * 1000;
            app.time += app.deltatime;
        }
        // ImGui End 
        if(app.ImGui) ImGuiRenderer::EndImGui();
        
        glfwTerminate();
        glfwDestroyWindow(app.GetWindow().GetGlfwWindow());
    }
}
