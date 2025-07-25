#include "Scene.h"
#include "Application.h"

namespace Zafran
{
    Application::Application()
    {
    }

    Application::~Application()
    {
        
    }

    void Application::Init()
    {

    }

    void Application::Update()
    {

    }

    void Application::OnEvent()
    {

    }

    void Application::SetScene(Scene scene)
    {   
        CurrentScene = scene;
    }

    bool Application::ShouldExit()
    {
        return false;
    }

    Window Application::GetWindow()
    {
        return m_window;
    }

    void Application::SetWindow(Window window)
    {
        m_window = window;
    }

}