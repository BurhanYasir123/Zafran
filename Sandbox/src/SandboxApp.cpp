#include "Zafran.h"

class MyApp : public Zafran::Application
{
    public:

    void PreInit()
    {
        SetWindow(Zafran::Window::Init(Vec2i(1000,600), "Window"));
        Zafran::ImGuiRenderer::InitImGui(*this);
        Zafran::Renderer::Init(GetWindow().GetWindowSize());
        Zafran::Renderer::EnableRaytracing();
    }

    void Init()
    {
        box.SetScale(Vec2f(450,350));
        box2.SetScale(Vec2f(500,300));

        count = 0;
    }

    void Update()
    {
        glClearColor(0,0,0,1.0);



        Vec2f pos = Zafran::Input::GetMousePostion();
        if(Zafran::Input::IsKeyPressed(GLFW_KEY_SPACE))glClearColor(0.1,pos.y/600,pos.x/800, 1.0);
        
        count++;
        ZF_INFO(count);

        box.material = Material(Color(1,pos.y/600,0)); 
        box2.material = Material(Color(0.4,0.3, 0.7));
        
        box.SetTransform(Vec2f(Box_x, box.GetTransform().y));
        ZF_WARN("TRANSFORM X " << box.GetTransform().x);

        box2.Update();
        //box.Update();
        //CurrentScene.Update();
        
        if(ImGui::Begin("Main"))
        {
            ImGui::Button("hi");

            ZF_INFO(deltatime);
            
            if(count%10 == 0) FPS = 1000.0f/deltatime;
            
            ImGui::Text("FPS: %.2f", FPS);
            ImGui::Text("Average FPS: %.2f",  1000.0/(time/count));

            ImGui::SliderFloat("Position x", &Box_x, -400, 400);

        }ImGui::End();

    }

    bool ShouldExit()
    {
        return glfwWindowShouldClose(GetWindow().GetGlfwWindow());
    }

    int count;
    
    Zafran::Object box = Zafran::Object(Zafran::ZF_TRIANGLE);
    Zafran::Object box2 = Zafran::Object(Zafran::ZF_RECTANGLE);

    float Box_x;
    
    double FPS;
};

int main()
{
    MyApp app;

    app.SetScene(app.CurrentScene);
    
    Zafran::RunApplication(app);
}
