#include "Main/main.h"
#include "Kernel/Kwln/kwln.h"
#include "temporary.h"

// FUN_00193980
int main(int argc, char* argv[])
{
    printf("jpx235\n");

    initAndLoop(0);

    /* kwlnMain owns the runtime loop and does not return. */
}

// FUN_001939b0
void initAndLoop(s32 unusedStartupArgument)
{
    /* The retail entry ABI supplies this argument; kwlnMain does not use it. */
    kwlnMain();
}


