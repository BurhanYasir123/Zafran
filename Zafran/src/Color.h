#pragma once

#include "Core.h"


struct ZF_API Color
{
    Color() { }

    Color(float _r, float _g, float _b, float _a) 
        : r(_r), g(_g), b(_b), a(_a) { }

    Color(float _r, float _g, float _b)
        : r(_r), g(_g), b(_b) { }

    float r = 0.2;
    float g = 0.2;
    float b = 0.2;
    float a = 1;
};

