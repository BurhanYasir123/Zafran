#include "Color.h"
#include "Object.h"
#include "Renderer/Renderer.h"

namespace Zafran
{
    Object::Object(Object_Type type) : m_type(type)
    {
        ZF_INFO("HI");

        float[] Points = object.GetVerticies();
        int length = sizeof(Points) / sizeof(Points[0])
        
        GLuint vertexbuffer;
        glGenBuffers(1, &vertexbuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(Points), Points, GL_STATIC_DRAW);
        VB = vertexbuffer;
    }

    Object::~Object()
    {
    }

    void Object::Update()
    {
        //ZF_INFO("Object.Uodate");
        if(show) Renderer::DrawObject(*this);
    }

    void Object::ToggleInvisible()
    {
        if(show)  { show = false; return;}
        if(!show) { show = true;  return;}
    }

    bool Object::IsInvisible()
    {
        return show;
    }

    void Object::ApplyMaterial(Material material)
    {
        m_material = material;
    }

    void Object::AddTransform(Vec2f transform)
    {
        m_transform.x = m_transform.x + transform.x; 
        m_transform.y = m_transform.y + transform.y; 
    }

    void Object::AddScale(Vec2f scale)
    {
        m_scale.x = m_scale.x + scale.x; 
        m_scale.y = m_scale.y + scale.y; 
    }

    Material Object::GetMaterial()
    {
        return m_material;
    }

    Vec2f Object::GetTransform()
    {
        return m_transform;
    }

    Vec2f Object::GetScale()
    {
        return m_transform;
    }

    Object_Type Object::GetType()
    {
        return m_type;
    }

    void Object::SetVerticies(float[] Verticies)
    {
        m_Verticies = Verticies;
    }

    float[] Object::GetVerticies()
    {
        return m_Verticies;
    }

    GLuint Object::GetVB()
    {
        return VB;
    }
}