#pragma once

#ifndef NO_LOG
#define ZF_INFO(...)        std::cout << "[APP :: INFO]"   << __VA_ARGS__ << std::endl;
#define ZF_WARN(...)        std::cout << "[APP :: WARN]"   << __VA_ARGS__ << std::endl;
#define ZF_ERROR(...)       std::cout << "[APP :: ERROR]"  << __VA_ARGS__ << std::endl;

#define ZF_CORE_INFO(...)   std::cout << "[CORE :: INFO]"  << __VA_ARGS__ << std::endl;
#define ZF_CORE_WARN(...)   std::cout << "[CORE :: WARN]"  << __VA_ARGS__ << std::endl;
#define ZF_CORE_ERROR(...)  std::cout << "[CORE :: ERROR]" << __VA_ARGS__ << std::endl;
#else
#define ZF_INFO(...)        
#define ZF_WARN(...)        
#define ZF_ERROR(...)       

#define ZF_CORE_INFO(...)   
#define ZF_CORE_WARN(...)   
#define ZF_CORE_ERROR(...)  
#endif