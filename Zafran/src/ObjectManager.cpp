#include "ObjectManager.h"

namespace Zafran
{
    std::vector<Object*> ObjectManager::Queue = {};
    bool ObjectManager::InitQueueEvaluated = false;
    Vec2i ObjectManager::m_window_size = Vec2i();
    
    void ObjectManager::EvaluateQueue_Init(Vec2i window_size)
    {
        if(InitQueueEvaluated) { return; }
        for(int i=0;i!=Queue.size();)
        {
            m_window_size = window_size;
            Queue[i]->Window_Size = window_size;
            Queue[i]->SetScale(Vec2f(400, 400));
            Queue[i]->SetTransform(Vec2f(0,0));
            Queue.erase(Queue.begin() + i);
        }
        InitQueueEvaluated = true;
    }
    
    void ObjectManager::QueueObject(Object* object)
    {
        if(InitQueueEvaluated)
        { 
            InitObjectManual(object);
            return;
        }
        Queue.push_back(object); 
    }
    
    void ObjectManager::InitObjectManual(Object* object)
    {
        if(!InitQueueEvaluated) { return; }
        object->Window_Size = m_window_size;
        object->SetScale(Vec2f(400, 400));
        object->SetTransform(Vec2f(0,0));
    }
}
