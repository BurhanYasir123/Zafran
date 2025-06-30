#pragma once

#include "Application.h"

namespace Zafran
{
    void RunApplication(Application& app)
    {
        app.Init();
        while(!app.ShouldExit() || !glfwWindowShouldClose(app.GetGlfwWindow()))
        {
            glClear(GL_COLOR_BUFFER_BIT);
            app.Update();
            glfwSwapBuffers(app.GetGlfwWindow());
            glfwPollEvents();
        }
        glfwTerminate();
    }
}