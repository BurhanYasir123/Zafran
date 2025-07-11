#include "Zafran.h"

class MyApp : public Zafran::Application
{
    public:
    void Init()
    {
        SetGlfwWindow(Zafran::Window::Init(Vec2i(800,600), "Window"));
        Zafran::ImGuiRenderer::InitImGui(*this);

        count = 0;
        
        box = Zafran::Object(Zafran::ZF_TRIANGLE);
        box.SetVerticies([
            -1.0f, -1.0f,
            1.0f, -1.0f,
            0.0f,  1.0f,
        ]);
        
        CurrentScene.PushObject(box);
    }

    void Update()
    {
        glClearColor(0,0,0,1.0);

        Vec2f pos = Zafran::Input::GetMousePostion();
        if(Zafran::Input::IsKeyPressed(GLFW_KEY_SPACE))glClearColor(0.1,pos.y/600,pos.x/800, 1.0);
        
        // if(glfwVulkanSupported()) ZF_CORE_WARN("VULKAN SUPPORTED THIMBS UP");
        // if(!glfwVulkanSupported()) ZF_CORE_WARN("VULKAN NOT SUPPORTED THIMBS DOWN");
        
        count++;
        ZF_INFO(count);
        
        CurrentScene.Update();
        
        if(ImGui::Begin("Main"))
        {
            ImGui::Button("hi");
            ZF_INFO(deltatime);
            if(count%20 == 0) FPS = 1000.0f/deltatime;
            ImGui::Text("FPS: %.2f", FPS);
        }ImGui::End();

    }

    bool ShouldExit()
    {
        return glfwWindowShouldClose(GetGlfwWindow());
    }

    int count;
    
    Zafran::Object box = Zafran::Object(Zafran::ZF_RECTANGLE);
    
    double FPS;
};

int main()
{
    MyApp app;

    app.SetScene(app.CurrentScene);
    
    Zafran::RunApplication(app);
}
