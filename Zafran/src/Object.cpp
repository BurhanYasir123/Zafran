#include "Color.h"
#include "Object.h"
#include "Renderer/Renderer.h"
#include "ObjectManager.h"

namespace Zafran
{
    Object::Object(Object_Type type) : m_type(type)
    {
        if(Status::PreInitStarted) {ZF_ERROR("Objects shall not be Initialized in PreInit"); return;}

        ZF_INFO("HI");
        
        m_ProgramID = NULL;
        VB.x = NULL;
        VB.y = NULL;
        
        ObjectManager::QueueObject(this);
    }

    Object::Object()
    {
       
    }
    Object::~Object()
    {
    }

    void Object::Update()
    {
        // if(Status::RayTracingEnabled) return;

        // ZF_INFO("Window_Size: " << Window_Size.x << " " << Window_Size.y);

        // if(m_type == ZF_RECTANGLE)
        // {
        //     GLfloat Verticies[] = {
        //         (m_transform.x - m_scale.x/2)/(Window_Size.x/2), (m_transform.y - m_scale.y / 2)/(Window_Size.y/2), 0.0f,
        //         (m_transform.x + m_scale.x/2)/(Window_Size.x/2), (m_transform.y - m_scale.y / 2)/(Window_Size.y/2), 0.0f,
        //         (m_transform.x - m_scale.x/2)/(Window_Size.x/2), (m_transform.y + m_scale.y / 2)/(Window_Size.y/2), 0.0f,
        //         (m_transform.x + m_scale.x/2)/(Window_Size.x/2), (m_transform.y + m_scale.y / 2)/(Window_Size.y/2), 0.0f,
        //     };

        //     ZF_INFO("transform:" << m_transform.x << " " << m_transform.y);
        //     SetVerticies(Verticies, 4);
        // }
        // if(m_type == ZF_TRIANGLE)
        // {
        //     GLfloat Verticies[] = {
        //         (m_transform.x - m_scale.x/2)/(Window_Size.x/2), (m_transform.y - m_scale.y / 2)/(Window_Size.y/2), 0.0f,
        //         (m_transform.x + m_scale.x/2)/(Window_Size.x/2), (m_transform.y - m_scale.y / 2)/(Window_Size.y/2), 0.0f,
        //         ( m_transform.x )  /  (Window_Size.x / 2 )     , (m_transform.y + m_scale.y / 2)/(Window_Size.y/2), 0.0f
        //     };
        //     SetVerticies(Verticies, 3);
        // }

        // ZF_WARN("WindowSize: x=" << Window_Size.x << " y=" << Window_Size.y);

        // if(show) Renderer::DrawObject(*this);
    }

    void Object::SetInvisible(bool Invisible)
    {
        show = Invisible;
    }

    bool Object::IsInvisible()
    {
        return show;
    }

    void Object::SetTransform(Vec2f transform)
    {
        if(m_ProgramID == NULL) m_ProgramID = Renderer::GetDefaultShaderProgram();
        m_transform = transform;
    }

    void Object::SetScale(Vec2f scale)
    {
        m_scale = scale;
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

    void Object::SetVerticies(const float* Verticies, int NumOfVerticies)
    {
        // if(VB.x == NULL) glGenBuffers(1, &VB.x);
        // if(VB.y == NULL && m_type == ZF_RECTANGLE) glGenBuffers(1, &VB.y);

        // if(NumOfVerticies < 3 && m_type == ZF_TRIANGLE)  ZF_WARN("Too few Verticies for a Triangle, This may result in a glitch, VertexCount: "  << NumOfVerticies);
        // if(NumOfVerticies < 4 && m_type == ZF_RECTANGLE) ZF_WARN("Too few Verticies for a Rectangle, This may result in a glitch, VertexCount: " << NumOfVerticies);

        // if(NumOfVerticies > 3 && m_type == ZF_TRIANGLE)  ZF_WARN("Too many Verticies for a Triangle, VertexCount: "  << NumOfVerticies);
        // if(NumOfVerticies > 4 && m_type == ZF_RECTANGLE) ZF_WARN("Too many Verticies for a Rectangle, VertexCount: " << NumOfVerticies);

        // m_numVerticies = NumOfVerticies;
        // m_Verticies = Verticies;

        // if(m_type == ZF_TRIANGLE)
        // {
        //     glBindBuffer(GL_ARRAY_BUFFER, VB.x);
        //     glBufferData(GL_ARRAY_BUFFER, sizeof(float) * NumOfVerticies * 3, Verticies, GL_STREAM_DRAW);
        // }
        // if(m_type == ZF_RECTANGLE)
        // {
        //     float V1[] = {
        //         Verticies[0], Verticies[1], Verticies[2],
        //         Verticies[3], Verticies[4], Verticies[5],
        //         Verticies[6], Verticies[7], Verticies[8]
        //     };
        //     float V2[] = {
        //         Verticies[3], Verticies[4], Verticies[5],  
        //         Verticies[9], Verticies[10], Verticies[11], 
        //         Verticies[6], Verticies[7], Verticies[8]
        //     };

        //     glBindBuffer(GL_ARRAY_BUFFER, VB.x);
        //     glBufferData(GL_ARRAY_BUFFER, sizeof(V1), V1, GL_STREAM_DRAW);
            
        //     glBindBuffer(GL_ARRAY_BUFFER, VB.y);
        //     glBufferData(GL_ARRAY_BUFFER, sizeof(V2), V2, GL_STREAM_DRAW);
        // }
    }

    const float* Object::GetVerticies()
    {
        return m_Verticies;
    }

    Vec2ui Object::GetVB()
    {
        return VB;
    }

    int Object::GetProgramID()
    {
        return m_ProgramID;
    }
}
