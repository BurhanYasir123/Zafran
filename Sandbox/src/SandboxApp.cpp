#include "Zafran.h"

class MyApp : public Zafran::Application
{
    public:
    void Init()
    {
        SetGlfwWindow(Zafran::Window::Init(Vec2i(800,600), "Window"));
        count = 0;
        CurrentScene.PushObject(box);
    }

    void Update()
    {
        glClearColor(0.1,0.3,0.6,1);
        count++;
        ZF_INFO(count);
        CurrentScene.Update();
    }

    bool ShouldExit()
    {
        if(count > 10) return true;
        return false;
    }

    int count;
    Zafran::Object box;
};

int main()
{
    MyApp app;
    app.SetScene(app.CurrentScene);
    Zafran::RunApplication(app);
}
