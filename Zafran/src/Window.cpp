#include "Window.h"

namespace Zafran
{
    Window::Window()
    {
    }

    Window::~Window()
    {
    }

    GLFWwindow* Window::Init(Vec2i size, const char* title)
    {
        if(!glfwInit()) ZF_CORE_ERROR("Coudnt Initialize GLFW");
        GLFWwindow* window = glfwCreateWindow(size.x, size.y, title, NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            ZF_CORE_ERROR("Window coudnt be created");
        }
        glfwMakeContextCurrent(window);
        gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        return window;
    }
}