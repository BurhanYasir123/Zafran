#pragma once

#include "Core.h"
#include "Material.h"




namespace Zafran
{
    class ZF_API Object
    {
    public:
        Object();
        ~Object();

        void ApplyMaterial(Material material);
        void ApplyTransform(Vec2f transform);
        void ApplyScale(Vec2f scale);
        Material GetMaterial();
        Vec2f GetTransform();
        Vec2f GetScale();
    private:
        Material m_material;
        Vec2f m_transform;
        Vec2f m_scale;
    };
}