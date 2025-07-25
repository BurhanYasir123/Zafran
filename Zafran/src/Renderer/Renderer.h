#pragma once

#include "Core.h"
#include "Object.h"
#include "RendererBackend.h"

namespace Zafran
{
    class ZF_API Renderer
    {
    public:
        Renderer();
        ~Renderer();

        static void Init();

        #ifndef ZF_API_VULKAN

        static void DrawObject(Object object);
        #else
        
        static void DrawObject(Object object);
        
        #endif
        static int GetDefaultShaderProgram() { return DefaultShaderProgram; };
    private:
        static int DefaultShaderProgram;

        #ifndef ZF_API_VULKAN
       
       
        #else
       
        // VULKAN STUFF
      
        #endif
    };
}
