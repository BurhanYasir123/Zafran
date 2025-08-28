#include "Window.h"

namespace Zafran
{
    Vec2i Window::m_size = Vec2i(0,0);
    Window::Window()
    {
    }

    Window::~Window()
    {
    }

    Window Window::Init(Vec2i size, const char* title)
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            SDL_Log("SDL_Init failed: %s", SDL_GetError());
            SDL_Quit();
        }
        SDL_Window* window = SDL_CreateWindow(title, size.x, size.y, SDL_WINDOW_OPENGL);
        m_size = size;
        if (!window) {
            SDL_Log("SDL_CreateWindow failed: %s", SDL_GetError());
            SDL_Quit();
        }

        SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
        if (!renderer) {
            SDL_Log("SDL_CreateRenderer failed: %s", SDL_GetError());
            SDL_DestroyWindow(window);
            SDL_Quit();
        }

        Window _window = Window();
        _window.SetSDL3Window(window);
        _window.Renderer = renderer;
        
        return _window;
    }
}
