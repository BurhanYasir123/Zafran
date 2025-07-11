#include "Input.h"

namespace Zafran
{
    bool Input::IsKeyPressedImpl(int key)
    {
        auto state = glfwGetKey(m_window, key);
        ZF_INFO("Key state:" << state);
        return state == GLFW_PRESS;
    }

    bool Input::IsMouseButtonPressedImpl(int button)
    {
        auto state = glfwGetMouseButton(m_window, button);
        return state == GLFW_PRESS;
    } 

    Vec2f Input::GetMousePostionImpl()
    {
        double xpos, ypos;
        glfwGetCursorPos(m_window, &xpos, &ypos);
        return Vec2f(xpos, ypos);
    }
}

Zafran::Input Zafran::Input::m_Instance;
GLFWwindow* Zafran::Input::m_window = nullptr;