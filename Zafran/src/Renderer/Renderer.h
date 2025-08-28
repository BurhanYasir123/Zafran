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
        static void ColorBackground(Color color, SDL_Renderer* renderer);
        static void EnableRaytracing();
        static void RayTraceFrame();
        static void PrepareRayTracing(); 

        static int GetDefaultShaderProgram();
    private:
        static int DefaultShaderProgram;
        static int RayTraceShaderProgram;
        static Vec2i m_WindowSize;
        static unsigned int RayTraceSurfaceVB1;
        static unsigned int RayTraceSurfaceVB2;
    };
}
