#include "Renderer.h"
#include "Core.h"

namespace Zafran
{
    int Renderer::DefaultShaderProgram = 0;
    int Renderer::RayTraceShaderProgram = 0;
    Vec2i Renderer::m_WindowSize = Vec2i(0,0);
    GLuint Renderer::RayTraceSurfaceVB1 = 0;
    GLuint Renderer::RayTraceSurfaceVB2 = 0;

    void Renderer::Init(Vec2i WindowSize)
    {
        m_WindowSize = WindowSize;
        std::filesystem::path shaderDir = std::filesystem::current_path() / "Shaders";
        std::string vertPath = (shaderDir / "Simple.vert").string();
        std::string RayTracePath = (shaderDir / "RayTrace.frag").string();
        std::string fragPath = (shaderDir / "Simple.frag").string();

        DefaultShaderProgram = OpenGL::Loadshaders(vertPath.c_str(), fragPath.c_str());
        RayTraceShaderProgram = OpenGL::Loadshaders(vertPath.c_str(), RayTracePath.c_str());
        ZF_INFO("Made ID: " << DefaultShaderProgram);
        ZF_INFO("Made RayTraceID: " << RayTraceShaderProgram);
    }

    void Renderer::PrepareRayTracing()
    {
        if(Status::RayTracingEnabled) {ZF_ERROR("RayTracing can only be prepared when RayTracing is enabled"); return;};
        if(Status::IsAppControling) {ZF_ERROR("The App dosent need to tinker with Raytracing function except EnableRayTracing"); return;};

        float SurfaceVerts1[] = {
            -1.0f, 1.0f, 0.0f,
             1.0f, 1.0f, 0.0f,
            -1.0f,-1.0f, 0.0f
        };

        float SurfaceVerts2[] = {
             1.0f, 1.0f, 0.0f,
            -1.0f,-1.0f, 0.0f,
             1.0f,-1.0f, 0.0f
        };

        glGenBuffers(1, &RayTraceSurfaceVB1);
        glBindBuffer(GL_ARRAY_BUFFER, RayTraceSurfaceVB1);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * (3*3), &SurfaceVerts1, GL_STATIC_DRAW);

        glGenBuffers(1, &RayTraceSurfaceVB2);
        glBindBuffer(GL_ARRAY_BUFFER, RayTraceSurfaceVB2);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * (3*3), &SurfaceVerts2, GL_STATIC_DRAW);
    }

    void Renderer::EnableRaytracing()
    {
        if(Status::PreInitPassed) {ZF_ERROR("RayTracing can only be enabled in PreInit"); return;};
        Status::RayTracingEnabled = true;
    }


    void Renderer::RayTraceFrame()
    {
        if(!Status::RayTracingEnabled) return;

        int SizeLocation = glGetUniformLocation(RayTraceShaderProgram, "WindowSize");
        glUniform2f(SizeLocation, Status::Global_WindowSizeX, Status::Global_WindowSizeY);
        
        DrawTriangle(RayTraceSurfaceVB1, RayTraceShaderProgram, Color(0,0,0,0));
        DrawTriangle(RayTraceSurfaceVB2, RayTraceShaderProgram, Color(0,0,0,0));

    }

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
}
