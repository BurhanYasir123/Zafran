#pragma once

#include "Core.h"
#include "Object.h"
#include "RendererBackend.h"
#include "Color.h"

namespace Zafran
{
    class ZF_API Renderer
    {
    public:
        Renderer();
        ~Renderer();

        static void Init(Vec2i WindowSize);

        static void DrawObject(Object object);
        static void DrawTriangle(int VertexBufferID, int ShaderProgramID, Color UniformColor);
        static void ColorBackground(Color color) { glClearColor(color.r, color.g, color.b, color.a); };
        static void EnableRaytracing();
        static void RayTraceFrame();
        static void PrepareRayTracing(); 

        static int GetDefaultShaderProgram() { return DefaultShaderProgram; };
    private:
        static int DefaultShaderProgram;
        static int RayTraceShaderProgram;
        static Vec2i m_WindowSize;
        static GLuint RayTraceSurfaceVB1;
        static GLuint RayTraceSurfaceVB2;
    };
}
