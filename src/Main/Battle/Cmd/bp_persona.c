#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBpPersona; // DAT_007ce398

void FUN_00267120();
long FUN_003c9ab0();
u32 FUN_001749a0(u32 param_1);
u32 FUN_003c9850(u32 param_1, u32 param_2, u32 param_3, u32 param_4);
void FUN_003c9b00(u32 param_1, u32 param_2, u32 param_3);
void FUN_003c9cd0(u32 param_1, s64 param_2);
void FUN_003c9d00(u32 param_1, u32 param_2);
s32 FUN_001756f0(void);
void FUN_003c9e00(u32 param_1, u32 param_2);


// FUN_00266eb0
void bpPersona00266eb0(u32* param_1)
{
    K_ASSERT(sBpPersona == NULL, 0x2b);
    *param_1 = 0;
    sBpPersona = param_1;
}

// FUN_00266f00
void bpPersona00266f00(void)
{
    K_ASSERT(sBpPersona != NULL, 0x24);
    if (*sBpPersona & 1) {
        FUN_00267120();
    }
    sBpPersona = NULL;
}
// FUN_00266F60
void bpPersona00266f60(u32 param_1)
{
    u32* work;
    u32 persona;

    K_ASSERT(sBpPersona != NULL, 0x24);
    work = sBpPersona;
    *(u16*)(work + 2) = (u16)param_1;
    persona = FUN_001749a0(param_1);
    work[1] = FUN_003c9850(0, 0, 5, 0);
    FUN_003c9b00(work[1], persona, 0);
    FUN_003c9cd0(work[1], (s64)-1);
    FUN_003c9d00(work[1], 8);
    if ((u16)FUN_001756f0() > 1)
    {
        FUN_003c9e00(work[1], 1);
    }
    else
    {
        FUN_003c9e00(work[1], 0);
    }
    *work |= 2;
    *work |= 1;
}

// FUN_00267120
void bpPersona00267120(void)
{
    u32* work;

    K_ASSERT(sBpPersona != NULL, 0x24);
    work = sBpPersona;
    kwlnTaskDestroyWithHierarchy((KwlnTask*)work[1]);
    *work &= 0xfffffffe;
}

// FUN_00267180
void bpPersona00267180(void)
{
    u32* work;

    K_ASSERT(sBpPersona != NULL, 0x24);
    work = sBpPersona;
    if ((~*work & 1) == 0 && (*work & 2) != 0 && FUN_003c9ab0(work[1]) != 0) {
        *work &= 0xfffffffd;
    }
}

// FUN_00267210
u32 bpPersona00267210(void)
{
    K_ASSERT(sBpPersona != NULL, 0x24);
    return *sBpPersona & 2;
}

u32 FUN_001749a0();
void FUN_003c9b00();

// FUN_00267070
void bpPersona00267070(u32 param_1)
{
    u32* work;
    u32 uVar2;

    K_ASSERT(sBpPersona != NULL, 0x24);
    work = sBpPersona;
    K_ASSERT((u16)sBpPersona[2] != (u16)param_1, 0x5c);
    *(u16*)(work + 2) = param_1;
    uVar2 = FUN_001749a0(param_1);
    FUN_003c9b00(work[1], uVar2, 0);
    *work |= 2;
}
