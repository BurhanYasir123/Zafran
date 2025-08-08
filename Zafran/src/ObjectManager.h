#pragma once

#include "Core.h"

#include "Object.h"

namespace Zafran
{

    class ObjectManager
    {
    public:
        static void EvaluateQueue_Init(Vec2i window_size);
        static void QueueObject(Object* object);
        
    private:
        static void InitObjectManual(Object* object);
        static std::vector<Object*> Queue;
        static bool InitQueueEvaluated;
        static Vec2i m_window_size;
    };
}