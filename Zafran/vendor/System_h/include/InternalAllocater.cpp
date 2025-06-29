#include "InternalAllocater.h"

namespace System
{
    Item<void*> memory[100];
    int allocated = -1;
}