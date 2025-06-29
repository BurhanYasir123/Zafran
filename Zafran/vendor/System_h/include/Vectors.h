#pragma once


#include "Console.h"

namespace System
{
    template<typename T, int size>
    class Vector
    {
        public:

        operator T*() { return array; }
        operator const T*() const { return array; }

        int m_size = size;
        T* array = nullptr;
        int full = 0;

        Vector() {
            array = new T[m_size];
        }

        ~Vector() {
            delete[] array;
        }

        void reserve(int amount)
        {
            int old_size = m_size;
            m_size = m_size + amount;
            T* newArray = new T[m_size];
            for (int i = 0; i < old_size; ++i)
            {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
        void push(T item)
        {
            if (full == m_size) { Console::out("Reserve to add mpre space, Vector full"); return; }
            array[full] = item;
            full++;
        }

        void display()
        {
            Console::print("[");
            for(int i=0;i!=m_size;i++)
            {
                Console::print(array[i]);
                if(i != m_size-1) Console::print(",");
            }
            Console::out("]");
        }
    };

}
#ifdef MACROS
class Vec4f : public System::Vector<float, 4> {};
class Vec4i : public System::Vector<int, 4>   {};
class Vec3f : public System::Vector<float, 3> {};
class Vec3i : public System::Vector<int, 3>   {};
class Vec2f : public System::Vector<float, 2> {};
class Vec2i : public System::Vector<int, 2>   {};
#endif