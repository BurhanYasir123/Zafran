#pragma once

#include "Core.h"
#include "Object.h"

namespace Zafran
{
    class ZF_API Renderer
    {
    public:
        Renderer();
        ~Renderer();

        #ifndef ZF_API_VULKAN

        static void DrawObject(Object object);
        
        #else
        
        static void DrawObject(Object object);
        
        #endif
        inline static int GetDefaultShaderProgram() { return DefaultShaderProgram; };
    private:
        static int DefaultShaderProgram;

        #ifndef ZF_API_VULKAN
       
        int Loadshaders();
       
        #else
       
        // VULKAN STUFF
      
        #endif
    };
}