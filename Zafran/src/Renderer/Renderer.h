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

        static int GetDefaultShaderProgram() { return DefaultShaderProgram; };
    private:
        static int DefaultShaderProgram;
        static Vec2i m_WindowSize;
    };
}
