#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBrpBirthWork; // puGpffffb640

void FUN_00108570();
void FUN_00108670();
void FUN_001085c0();
void FUN_0024be40();
void FUN_0021a920();

// FUN_0024aa90
void brpBirth0024aa90(void)
{
    u32* work;

    K_ASSERT(sBrpBirthWork != NULL, 0x7f);
    work = sBrpBirthWork;
    FUN_00108570();
    FUN_00108670(2);
    FUN_001085c0();
    work[1] |= 1;
    work[2] = 8;
}

// FUN_0024abd0
void brpBirth0024abd0(void)
{
    u32* work;

    K_ASSERT(sBrpBirthWork != NULL, 0x7f);
    work = sBrpBirthWork;
    FUN_0024be40();
    FUN_0021a920(0, 0xe);
    *work = 1;
    work[1] |= 2;
}

// FUN_0024ac40
u32 brpBirth0024ac40(void)
{
    K_ASSERT(sBrpBirthWork != NULL, 0x7f);
    return sBrpBirthWork[1] & 2;
}

// FUN_0024b9e0
u32 brpBirth0024b9e0(void)
{
    K_ASSERT(sBrpBirthWork != NULL, 0x7f);
    return sBrpBirthWork[1] & 1;
}
