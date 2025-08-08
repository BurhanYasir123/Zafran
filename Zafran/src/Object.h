#pragma once

#include "Core.h"
#include "Material.h"

namespace Zafran
{
    enum ZF_API Object_Type
    {
        ZF_TRIANGLE,
        ZF_RECTANGLE
    };

    class ZF_API Object
    {
    public:
        Object(Object_Type type);
        Object();
        ~Object();

        void Update();
        void SetInvisible(bool Invisible);
        bool IsInvisible();
        void SetTransform(Vec2f transform);
        void SetScale(Vec2f scale);
        Vec2f GetTransform();
        Vec2f GetScale();
        Object_Type GetType();
        void SetVerticies(const GLfloat* Verticies, int count);
        const float* GetVerticies();
        Vec2ui GetVB();
        int GetProgramID();
        int m_numVerticies;

        Material material;
        Vec2i Window_Size;
    private:
        Object_Type m_type;
        Vec2f m_transform;
        Vec2f m_scale;
        bool show = true;
        const GLfloat* m_Verticies;
        Vec2ui VB;
        int m_ProgramID;
    };
}

