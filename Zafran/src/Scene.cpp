#include "Object.h"


#include "Scene.h"

namespace Zafran
{
    Scene::Scene()
    {
    }

    Scene::~Scene()
    {
    }

    void Scene::Update()
    {
        for(int i=0;i!=m_Objects.size();i++)
        {
            m_Objects[i].Update();
        }
    }

    void Scene::PushObject(Object& object)
    {
        m_Objects.push_back(object);
    }

    std::vector<Object>& Scene::GetObjects()
    {
        return m_Objects;
    }
}
