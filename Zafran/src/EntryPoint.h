#pragma once

#include "Application.h"
#include "Object.h"

#include "Renderer/Renderer.h"
#include "Input.h"
#include "ObjectManager.h"

namespace Zafran
{
    void RunApplication(Application& app)
    {
        Status::PreInitStarted = true;

        app.PreInit();

        app.renderer = app.GetWindow().Renderer;

        Status::PreInitPassed = true;
        Status::PreInitStarted = false;

        Status::Global_WindowSizeX = app.GetWindow().GetWindowSize().x;
        Status::Global_WindowSizeY = app.GetWindow().GetWindowSize().y;
        
        app.Init();
        app.deltatime = 1000/60;

        Status::InitPassed = true;

        Input::SetWindow(app.GetWindow().GetSDL3Window());   

        bool Running = true;

        while(Running)
        {
            // Deltatime calculation
            auto start = std::chrono::high_resolution_clock::now();
            
            SDL_PollEvent(&app.m_event);

            if(app.m_event.type == SDL_EVENT_QUIT) { Running = false; return; }

            // Per-Frame Status 

            app.Update();
            
            SDL_RenderPresent(app.renderer);
            
            // Deltatime and Time Calcualtion
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> duration = end - start;
            app.deltatime = duration.count() * 1000;
            app.time += app.deltatime;
        }
        
        SDL_DestroyRenderer(app.renderer);
        SDL_DestroyWindow(app.GetWindow().GetSDL3Window());
        SDL_Quit();
    }
}
