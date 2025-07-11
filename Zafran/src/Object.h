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
        ~Object();

        void Update();
        void ToggleInvisible();
        bool IsInvisible();
        void ApplyMaterial(Material material);
        void AddTransform(Vec2f transform);
        void AddScale(Vec2f scale);
        Material GetMaterial();
        Vec2f GetTransform();
        Vec2f GetScale();
        Object_Type GetType();
        void SetVerticies(float[] Verticies);
        float[] GetVerticies();
        GLuint GetVB();
    private:
        Object_Type m_type;
        Material m_material;
        Vec2f m_transform;
        Vec2f m_scale;
        bool show = true;
        float[] m_Verticies;
        GLuint VB;
    };
}