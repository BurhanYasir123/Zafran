#pragma once

#include "Core.h"
#include "Color.h"

namespace Zafran
{
    class ZF_API Material
    {
    public:
        Material();
        ~Material();

        void ApplyColor(Color color);
        Color GetColor();

    private:
        Color m_color;
    };
}