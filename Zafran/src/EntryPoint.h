#pragma once

#include "Application.h"

namespace Zafran
{
    void RunApplication(Application& app)
    {
        app.Init();
        while(!app.ShouldExit())
        {
            app.Update();
        }
    }
}