#pragma once

#include "System.h"
#include "Item.h"

namespace System
{

    extern Item<void*> memory[100];
    extern int allocated;

    class InternalAllocater {
        public:
        template<typename T>
        inline static int allocate(T data, int id) { 
            allocated++;
            memory[allocated] = Item((void*)data, id);
            return allocated; 
        }
        template<typename T>
        inline static T derefrencePtr(int ptr)
        {
            if(ptr > allocated) Console::out("Pointer out of range");
            return (T)memory[ptr].data;
        }

        template<typename T>
        inline static T derefrenceID(int id){
            if (allocated < 0) { Console::out("No Data In memory or Invalid ID");return T(); }
            for(int i=0;i!=allocated+1;i++)
            {
                if(memory[i].id == id)
                {
                    return static_cast<T>(memory[i].data);
                }
            }
            Console::out("Invalid ID, no Element in memory was found with this ID");
            return T();
        }
    };
}