

#include "Color.h"

namespace Zafran
{
    Color::Color()
    {
    }

    Color::~Color()
    {
    }

    void Color::SetRGB(Vec3f RGB)
    {
        m_RGB = RGB;
    }
}