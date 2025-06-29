#include "Zafran.h"

class MyApp : public Zafran::Application
{
    void Init()
    {
        count = 0;
    }

    void Update()
    {
        count++;
        ZF_INFO(count);
    }

    bool ShouldExit()
    {
        if(count > 10) return true;
        return false;
    }

    int count;
};

int main()
{
    MyApp app;
    Zafran::RunApplication(app);
}