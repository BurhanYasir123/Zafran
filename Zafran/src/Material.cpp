#include "Color.h"
#include "Material.h"

namespace Zafran
{
    Material::Material()
    {
    }

    Material::~Material()
    {
    }

    void Material::ApplyColor(Color color)
    {
        m_color = color;
    }

    Color Material::GetColor()
    {
        return m_color;
    }
}