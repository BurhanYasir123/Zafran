#pragma once

#include "Core.h"
#include "Object.h"

namespace Zafran
{
    class ZF_API Scene
    {
    private:
        static constexpr int Object_count = 1;
        System::Vector<Object, 1> m_Objects;
    public:
        Scene();
        ~Scene();

        void PushObject(Object object);
        System::Vector<Object, Object_count> GetObjects();

    };
}