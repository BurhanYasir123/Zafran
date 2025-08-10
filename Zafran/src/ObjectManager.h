#pragma once

#include "Core.h"

#include "Object.h"

namespace Zafran
{

    class ObjectManager
    {
    public:
        static void EvaluateQueue_Init();
        static void QueueObject(Object* object);
        
    private:
        static void InitObjectManual(Object* object);
        static std::vector<Object*> Queue;
        static bool InitQueueEvaluated;
    };
}