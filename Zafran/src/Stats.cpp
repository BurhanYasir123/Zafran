#include "Stats.h"

bool Status::PreInitPassed;
bool Status::InitPassed;
bool Status::RayTracingEnabled;
bool Status::IsAppControling;
int Status::Global_WindowSizeX;
int Status::Global_WindowSizeY;
bool Status::PreInitStarted;

void Status::Init()
{
    PreInitPassed = false;
    InitPassed = false;
    RayTracingEnabled = false;
    IsAppControling = false;
    Global_WindowSizeX = 0;
    Global_WindowSizeY = 0;
    PreInitStarted = false;
}