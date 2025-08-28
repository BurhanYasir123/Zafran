#include "Input.h"

//[========================[]=========================]
//[==============[TODO--------------]=================]
//[==============[--IMPLEMENT INPUTS]=================]
//[=======================[]==========================]

namespace Zafran
{
    bool Input::IsKeyPressedImpl(int key)
    {
        // auto state = glfwGetKey(m_window, key);
        // //ZF_INFO("Key state:" << state);
        // return state == GLFW_PRESS;
        return false;
    }

    bool Input::IsMouseButtonPressedImpl(int button)
    {
        // auto state = glfwGetMouseButton(m_window, button);
        // return state == GLFW_PRESS;
        return false;
    } 

    Vec2f Input::GetMousePostionImpl()
    {
        // double xpos, ypos;
        // glfwGetCursorPos(m_window, &xpos, &ypos);
        // return Vec2f(xpos, ypos);
        return Vec2f(0.0f,0.0f);
    }
}

Zafran::Input Zafran::Input::m_Instance;
SDL_Window* Zafran::Input::m_window = nullptr;
