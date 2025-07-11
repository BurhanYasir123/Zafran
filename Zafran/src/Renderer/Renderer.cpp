#include "Renderer.h"
#include "Core.h"

namespace Zafran
{
    //int Renderer::DefaultShaderProgram = 0;
    Renderer::Renderer()
    {
        DefaultShaderProgram = glCreateProgram();
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
            float[] Points = object.GetVerticies();
            int length = sizeof(Points) / sizeof(Points[0])
            
            if(length != (3*2)) { ZF_CORE_ERROR("Object Dosent Have Enough Vertcies for a Triangle");return; }

            glBindBuffer(GL_ARRAY_BUFFER, object.GetVB());
            glVertexAttribPointer(
                0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                3,                  // size
                GL_FLOAT,           // type
                GL_FALSE,           // normalized?
                0,                  // stride
                (void*)0            // array buffer offset
            );
            // Draw the triangle !
            glDrawArrays(GL_TRIANGLES, 0, 3);
        }
    }
#endif
}