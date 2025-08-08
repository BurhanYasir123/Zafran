#include "Renderer.h"
#include "Core.h"

namespace Zafran
{
    int Renderer::DefaultShaderProgram = 0;
    Vec2i Renderer::m_WindowSize = Vec2i(0,0);

    void Renderer::Init(Vec2i WindowSize)
    {
        m_WindowSize = WindowSize;
        std::filesystem::path shaderDir = std::filesystem::current_path() / "Shaders";
        std::string vertPath = (shaderDir / "Simple.vert").string();
        std::string fragPath = (shaderDir / "Simple.frag").string();

        DefaultShaderProgram = OpenGL::Loadshaders(vertPath.c_str(), fragPath.c_str());
        ZF_INFO("Made ID: " << DefaultShaderProgram);
    }
#ifdef ZF_API_VULKAN
    void Renderer::DrawObject(Object object)
    {
        ZF_INFO("Drawing... Mode:VULKAN type:" << object.GetType())
    }
#else
    void Renderer::DrawTriangle(int VertexBufferID, int ShaderProgramID, Color UniformColor)
    {
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, VertexBufferID);
        glVertexAttribPointer(
            0,
            3,
            GL_FLOAT,
            GL_FALSE,
            0,
            (void*)0            
        );
            
        
        glUseProgram(ShaderProgramID);
    
        int ColorLocation = glGetUniformLocation(ShaderProgramID, "ourColor");        
        ZF_INFO("Uniform location for 'ourColor': " << ColorLocation << " SHADER_ID: " << ShaderProgramID);
        glUniform4f(ColorLocation, UniformColor.r, UniformColor.g, UniformColor.b, UniformColor.a);

        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableVertexAttribArray(0);
    }
    
    void Renderer::DrawObject(Object object)
    {
        ZF_INFO("Drawing... Mode:OpenGL type:" << object.GetType())
     
        if(object.GetType() == ZF_TRIANGLE)
        {
            DrawTriangle(object.GetVB().x, object.GetProgramID(), object.material.color);
        }
        if(object.GetType() == ZF_RECTANGLE) 
        {
            ZF_INFO("Drawing with color: r=" << object.material.color.r << ", g=" << object.material.color.g << ", b=" << object.material.color.b);
            DrawTriangle(object.GetVB().x, object.GetProgramID(), object.material.color);
            DrawTriangle(object.GetVB().y, object.GetProgramID(), object.material.color);
        }
    }
#endif
}
