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

// FUN_0021b670 NONMATCHING
void bseMain0021b670(u32 request)
{
    u32 flags;

    K_ASSERT(sBseWork != NULL, 0x1e);
    sBseWork[1] = request;
    bpRoot001fe510(request);
    flags = *sBseWork;
    *sBseWork = flags | 1;
    *sBseWork = (flags & ~2u) | 1;
}

// FUN_0021b6f0
u32 bseMain0021b6f0(void)
{
    K_ASSERT(sBseWork != NULL, 0x1e);
    return *sBseWork & 1;
}

// FUN_0021b740 NONMATCHING
u32 bseMain0021b740(void)
{
    u32 flags;

    K_ASSERT(sBseWork != NULL, 0x1e);
    flags = *sBseWork;
    K_ASSERT((flags & 1) == 0, 0x47);
    return flags & 2;
}

// FUN_0021b7c0 NONMATCHING
u32 bseMain0021b7c0(void)
{
    u32 flags;

    K_ASSERT(sBseWork != NULL, 0x1e);
    flags = *sBseWork;
    K_ASSERT((flags & 1) == 0, 0x4f);
    return sBseWork[2];
}

// FUN_0021b830 NONMATCHING
void bseMain0021b830(void)
{
    u32 flags;

    K_ASSERT(sBseWork != NULL, 0x1e);
    FUN_0010a4e0(0, 0, 0, 2);
    flags = *sBseWork;
    *sBseWork = flags | 2;
    *sBseWork = (flags & ~1u) | 2;
}

// FUN_0021b8b0 NONMATCHING
void bseMain0021b8b0(void* result)
{
    K_ASSERT(sBseWork != NULL, 0x1e);
    printf((const char*)0x7cc444);
    sBseWork[2] = (u32)result;
    sBseWork[0] &= ~1u;
}
