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
        Status::Init();

        Status::PreInitStarted = true;

        app.PreInit();

        Status::PreInitPassed = true;
        Status::PreInitStarted = false;

        Status::Global_WindowSizeX = app.GetWindow().GetWindowSize().x;
        Status::Global_WindowSizeY = app.GetWindow().GetWindowSize().y;

        if(!Status::RayTracingEnabled) ObjectManager::EvaluateQueue_Init();
        
        app.Init();
        app.deltatime = 1000/60;

        Status::InitPassed = true;

        Input::SetWindow(app.GetWindow().GetGlfwWindow());   
   
        if(Status::RayTracingEnabled) Renderer::PrepareRayTracing();

        while(!(app.ShouldExit() || glfwWindowShouldClose(app.GetWindow().GetGlfwWindow())))
        {
            
            // Deltatime calculation
            auto start = std::chrono::high_resolution_clock::now();
            
            glfwPollEvents();
            
            // For ImGui Frames
            if(app.ImGui) ImGuiRenderer::InitFrame();
            
            glClear(GL_COLOR_BUFFER_BIT);

            // Per-Frame Status 

            Status::IsAppControling = false;
            
            app.Update();

            Status::IsAppControling = true;

            if(Status::RayTracingEnabled) Renderer::RayTraceFrame();
            
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
