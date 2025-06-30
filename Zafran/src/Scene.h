#pragma once

#include "Core.h"
#include "Object.h"

namespace Zafran
{
    class ZF_API Scene
    {
    private:
        std::vector<Object> m_Objects;
    public:
        Scene();
        ~Scene();

        void Update();
        void PushObject(Object& object);
        std::vector<Object>& GetObjects();

    };
}
