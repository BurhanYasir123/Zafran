#pragma once

#include "System.h"

#ifdef ZAFRAN_BUILD_DLL
    #define ZF_API __attribute__((visibility("default")))
#else
    #define ZF_API
#endif

#define UID int

#define ZF_INFO(...)        std::cout << "[APP :: INFO]"   << __VA_ARGS__ << std::endl;
#define ZF_WARN(...)        std::cout << "[APP :: WARN]"   << __VA_ARGS__ << std::endl;
#define ZF_ERROR(...)       std::cout << "[APP :: ERROR]"  << __VA_ARGS__ << std::endl;

#define ZF_CORE_INFO(...)   std::cout << "[CORE :: INFO]"  << __VA_ARGS__ << std::endl;
#define ZF_CORE_WARN(...)   std::cout << "[CORE :: WARN]"  << __VA_ARGS__ << std::endl;
#define ZF_CORE_ERROR(...)  std::cout << "[CORE :: ERROR]" << __VA_ARGS__ << std::endl;

