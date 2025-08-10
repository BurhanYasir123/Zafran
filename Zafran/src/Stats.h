#pragma once

class Status
{
public:
    static bool PreInitPassed;
    static bool InitPassed;
    static bool RayTracingEnabled;
    static bool IsAppControling;
    static int Global_WindowSizeX;
    static int Global_WindowSizeY;
    static bool PreInitStarted;

    static void Init();
};