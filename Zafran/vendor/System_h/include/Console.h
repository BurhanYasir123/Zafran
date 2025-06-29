#pragma once

#include <iostream>

namespace System
{
    class Console {
        public:
            template<typename T>
            static inline void out(T msg)   { _instance().outImpl(msg);  }
            template<typename T>
            static inline void print(T msg) { _instance().printImpl(msg); }
        private:
            static Console& _instance() {
                static Console S_Instance;
                return S_Instance;
            }
            template<typename T>
            inline void outImpl(T msg)   { std::cout << msg << std::endl; }
            template<typename T>
            inline void printImpl(T msg) {       std::cout << msg;        }
    };
}

#ifdef MACROS
class Console : public System::Console {};
#endif