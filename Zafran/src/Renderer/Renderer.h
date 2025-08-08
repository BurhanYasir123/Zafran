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

        #ifndef ZF_API_VULKAN

        static void DrawObject(Object object);
        static void DrawTriangle(int VertexBufferID, int ShaderProgramID, Color UniformColor);
        static void ColorBackground(Color color) { glClearColor(color.r, color.g, color.b, color.a); };

        #else

        static void DrawObject(Object object);

        #endif
        static int GetDefaultShaderProgram() { return DefaultShaderProgram; };
    private:
        static int DefaultShaderProgram;
        static Vec2i m_WindowSize;

        #ifndef ZF_API_VULKAN


        #else

        // VULKAN STUFF

        #endif
    };
}
