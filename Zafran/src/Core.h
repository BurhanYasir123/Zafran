#pragma once

#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <sstream>
#include <filesystem>


#include <glad/glad.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#ifdef ZF_API_VULKAN
#define GLFW_INCLUDE_VULKAN
#endif

#include <GLFW/glfw3.h>

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

