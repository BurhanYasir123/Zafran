#pragma once

#include "Core.h"



namespace Zafran
{
    class ZF_API Color
    {
    public:
        Color();
        ~Color();
        void SetRGB(Vec3f RGB);

    private:
        Vec3f m_RGB;
    };
}