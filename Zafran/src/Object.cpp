#include "Color.h"


#include "Object.h"

namespace Zafran
{
    Object::Object()
    {
        ZF_INFO("HI");
    }

    Object::~Object()
    {
    }

    void Object::Update()
    {
        ZF_INFO(".")
    }

    void Object::ApplyMaterial(Material material)
    {

    }

    void Object::ApplyTransform(Vec2f transform)
    {

    }

    void Object::ApplyScale(Vec2f scale)
    {

    }

    Material Object::GetMaterial()
    {
        return Material();
    }

    Vec2f Object::GetTransform()
    {
        return Vec2f();
    }

    Vec2f Object::GetScale()
    {
        return Vec2f();
    }
}