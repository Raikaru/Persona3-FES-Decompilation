#include "Kosaka/k_assert.h"
#include "Utils.h"

static u32* sBseWork; // DAT_007ce300

extern void bpRoot001fe510(u32 request);
extern void FUN_0010a4e0(u32 arg0, u32 arg1, u32 arg2, u32 arg3);
extern int printf(const char* format, ...);

// FUN_0021b650
void bseMain0021b650(u32* param_1)
{
    *param_1 = 0;
    sBseWork = param_1;
}

// FUN_0021b660
void bseMain0021b660(void)
{
    sBseWork = NULL;
}

// FUN_0021b670
void bseMain0021b670(u32 request)
{
    u32* work;
    K_ASSERT(sBseWork != NULL, 0x1e);
    work = sBseWork;
    work[1] = request;
    bpRoot001fe510(request);
    *work |= 1;
    *work &= ~2u;
}

// FUN_0021b6f0
u32 bseMain0021b6f0(void)
{
    K_ASSERT(sBseWork != NULL, 0x1e);
    return *sBseWork & 1;
}

// FUN_0021b740
u32 bseMain0021b740(void)
{
    u32* work;

    K_ASSERT(sBseWork != NULL, 0x1e);
    work = sBseWork;
    K_ASSERT(~*work & 1, 0x47);
    return *work & 2;
}

// FUN_0021b7c0
u32 bseMain0021b7c0(void)
{
    u32* work;

    K_ASSERT(sBseWork != NULL, 0x1e);
    work = sBseWork;
    K_ASSERT(~*work & 1, 0x4f);
    return work[2];
}

// FUN_0021b830
void bseMain0021b830(void)
{
    u32* work;

    K_ASSERT(sBseWork != NULL, 0x1e);
    work = sBseWork;
    FUN_0010a4e0(0, 0, 0, 2);
    *work |= 2;
    *work &= ~1u;
}

// FUN_0021b8b0
void bseMain0021b8b0(void* result)
{
    u32* work;
    K_ASSERT(sBseWork != NULL, 0x1e);
    work = sBseWork;
    printf("");
    work[2] = (u32)result;
    *work &= ~1u;
}
