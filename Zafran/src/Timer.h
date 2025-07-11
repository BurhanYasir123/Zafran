#pragma once

#include "Core.h"

namespace Zafran
{
    struct Time
    {
        Time() {}
        Time(const char* Origin, float time) { m_Origin = Origin; m_time = time; }
        const char* m_Origin;
        float m_time;
    };
    
    inline std::vector<Time> Times;

    class ZF_API Timer
    {
        const char* m_name;
        std::chrono::_V2::system_clock::time_point start;
        std::chrono::_V2::system_clock::time_point end;

    public:
        Timer(const char * name) { 
            m_name = name;
            start = std::chrono::high_resolution_clock::now();
        }

        ~Timer()
        {
            end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<float> duration = end - start;
            Zafran::Times.push_back(Zafran::Time(m_name, duration.count()*1000));
            //ZF_INFO(m_name << " " << (duration.count()*1000) << " " << Zafran::Times[0].m_time);
        }
    };
}