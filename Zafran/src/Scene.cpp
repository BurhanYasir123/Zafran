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

    void Scene::PushObject(Object object)
    {

    }

    System::Vector<Object, Scene::Object_count> Scene::GetObjects()
    {
        return System::Vector<Object, Object_count>();
    }
}