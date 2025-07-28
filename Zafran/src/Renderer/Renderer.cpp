#include "Renderer.h"
#include "Core.h"

namespace Zafran
{
    int Renderer::DefaultShaderProgram = 0;

    void Renderer::Init()
    {
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
    void Renderer::DrawObject(Object object)
    {
        ZF_INFO("Drawing... Mode:OpenGL type:" << object.GetType())

        if(object.GetType() == ZF_TRIANGLE)
        {
            //ZF_WARN((object.m_numVerticies));
            if(object.m_numVerticies != 3) { ZF_CORE_ERROR("Object Dosent Have Enough Vertcies for a Triangle");return; }

            glEnableVertexAttribArray(0);
            glBindBuffer(GL_ARRAY_BUFFER, object.GetVB());
            glVertexAttribPointer(
                0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                3,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                0,                  // stride
                (void*)0            // array buffer offset
            );
            
        
            glUseProgram(object.GetProgramID());
    
            int ColorLocation = glGetUniformLocation(object.GetProgramID(), "ourColor");        
            glUniform4f(ColorLocation, object.material.color.r, object.material.color.g, object.material.color.b, object.material.color.a);  
            ZF_INFO(object.material.color.r << " " << object.material.color.g << " " << object.material.color.b);          

            ZF_INFO("Loaded ID: " << object.GetProgramID());
            // Draw the triangle !
            glDrawArrays(GL_TRIANGLES, 0, 3);
            glDisableVertexAttribArray(0);
        }
    }
#endif
}
