#pragma once

#include "Core.h"
#include "Material.h"




namespace Zafran
{
    enum ZF_API Object_Type
    {
        ZF_TRIANGLE,
        ZF_RECTANGLE,
        ZF_SQUARE
    };

    class ZF_API Object
    {
    public:
        Object(Object_Type type);
        Object();
        ~Object();

        void Update();
        void ToggleInvisible();
        bool IsInvisible();
        void AddTransform(Vec2f transform);
        void AddScale(Vec2f scale);
        Vec2f GetTransform();
        Vec2f GetScale();
        Object_Type GetType();
        void SetVerticies(const GLfloat* Verticies, int count);
        const float* GetVerticies();
        GLuint GetVB();
        int GetProgramID();
        int m_numVerticies;

        Material material;
    private:
        Object_Type m_type;
        Vec2f m_transform;
        Vec2f m_scale;
        bool show = true;
        const GLfloat* m_Verticies;
        GLuint VB;
        int m_ProgramID;
    };
}
