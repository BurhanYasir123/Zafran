#pragma once

#include "Core.h"
#include "Color.h"

struct ZF_API Material
{
    Material() {}

    Material(Color _color) { color = _color; }

    Color color;
};

