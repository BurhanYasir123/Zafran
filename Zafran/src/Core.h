#pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <sstream>
#include <filesystem>


#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#include <SDL3/SDL.h>

#ifndef ZAFRAN_PLATFORM_LINUX
#define ZAFRAN_PLATFORM_LINUX
#endif

#ifdef ZAFRAN_PLATFORM_LINUX
#ifdef ZAFRAN_BUILD_DLL
    #define ZF_API __attribute__((visibility("default")))
#else
    #define ZF_API
#endif
#endif

//#define UID int

#include "Log.h"
#include "Vectors.h"
#include "Timer.h"
#include "Stats.h"

