#include "Zafran.h"

class MyApp : public Zafran::Application
{
    public:

    void PreInit()
    {
        SetWindow(Zafran::Window::Init(Vec2i(1000,600), "Window"));
        Zafran::Renderer::Init(GetWindow().GetWindowSize());
    }

    void Init()
    {
        //box.SetScale(Vec2f(450,350));
        //box2.SetScale(Vec2f(500,300));

        count = 0;
    }

    void Update()
    {
        //Zafran::Renderer::ColorBackground(Color(0,0,0,1.0));

        //Vec2f pos = Zafran::Input::GetMousePostion();
        Zafran::Renderer::ColorBackground(Color(0.3, 0.2, 0.4, 1.0), renderer);
        
        count++;
        ZF_INFO(count);

        //box.material = Material(Color(1,pos.y/600,0)); 
        //box2.material = Material(Color(0.4,0.3, 0.7));
        
        //box.SetTransform(Vec2f(Box_x, box.GetTransform().y));
        //ZF_WARN("TRANSFORM X " << box.GetTransform().x);

        //box2.Update();
        //box.Update();
        //CurrentScene.Update();

    }

    bool ShouldExit()
    {
        return false;
    }

    int count;
    
    //Zafran::Object box = Zafran::Object(Zafran::ZF_TRIANGLE);
    //Zafran::Object box2 = Zafran::Object(Zafran::ZF_RECTANGLE);
    
    //float Box_x;
    
    double FPS;
};

int main()
{
    MyApp app;

    app.SetScene(app.CurrentScene);
    
    Zafran::RunApplication(app);
}
