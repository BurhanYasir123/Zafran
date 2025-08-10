#include "ObjectManager.h"

namespace Zafran
{
    std::vector<Object*> ObjectManager::Queue = {};
    bool ObjectManager::InitQueueEvaluated = false;
    
    void ObjectManager::EvaluateQueue_Init()
    {
        if(InitQueueEvaluated) { return; }
        for(int i=0;i!=Queue.size();)
        {
            Queue[i]->Window_Size = Vec2i(Status::Global_WindowSizeX, Status::Global_WindowSizeY);
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
        object->Window_Size = Vec2i(Status::Global_WindowSizeX, Status::Global_WindowSizeY);
        object->SetScale(Vec2f(400, 400));
        object->SetTransform(Vec2f(0,0));
    }
}
