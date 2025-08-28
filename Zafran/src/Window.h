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

        SDL_Window* GetSDL3Window() { return m_window; };
        void SetSDL3Window(SDL_Window* window) { m_window = window; };
        Vec2i GetWindowSize() { return m_size; };

        SDL_Renderer* Renderer;

    private:
        SDL_Window* m_window;
        static Vec2i m_size;
    };
}
