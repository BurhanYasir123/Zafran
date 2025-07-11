#pragma once

#include "Application.h"

#include "ImGui/ImGuiRenderer.h"
#include "Input.h"

namespace Zafran
{
    void RunApplication(Application& app)
    {
        app.Init();
        app.deltatime = 1000/60;

        Input::SetWindow(app.GetGlfwWindow());
        
        while(!(app.ShouldExit() || glfwWindowShouldClose(app.GetGlfwWindow())))
        {
            // Deltatime calculation
            auto start = std::chrono::high_resolution_clock::now();
            
            glfwPollEvents();
            
            // For ImGui Frames
            if(app.ImGui) ImGuiRenderer::InitFrame();
            
            app.Update();
            
            glClear(GL_COLOR_BUFFER_BIT);
            
            // For ImGui Render
            if(app.ImGui) ImGuiRenderer::RenderFrame();
            
            glfwSwapBuffers(app.GetGlfwWindow());
            
            // Deltatime Calcualtion
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> duration = end - start;
            app.deltatime = duration.count() * 1000;
        }
        // ImGui End 
        if(app.ImGui) ImGuiRenderer::EndImGui();
        
        glfwTerminate();
        glfwDestroyWindow(app.GetGlfwWindow());
    }
}