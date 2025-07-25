#include "ImGuiRenderer.h"

namespace Zafran
{
    void ImGuiRenderer::InitImGui(Application& app)
    {
        app.ImGui = true;

        IMGUI_CHECKVERSION();
        
        ImGui::CreateContext();

        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        
        ImGui_ImplGlfw_InitForOpenGL(app.GetWindow().GetGlfwWindow(), true);
        ImGui_ImplOpenGL3_Init("#version 130");

    }

    void ImGuiRenderer::InitFrame()
    {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        
        ImGui::NewFrame();
    }

    void ImGuiRenderer::RenderFrame()
    {
        ImGui::Render();
     
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void ImGuiRenderer::EndImGui()
    {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        
        ImGui::DestroyContext();
    }
}