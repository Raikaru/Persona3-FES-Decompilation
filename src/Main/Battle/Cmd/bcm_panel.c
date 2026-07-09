#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBcmPanel; // puGpffffb618
u32 FUN_0021c3f0();
u32 FUN_0021cca0();
void FUN_0021d3b0();
void FUN_00226320();
void FUN_00222d60();
void FUN_0021e380();
void FUN_0022c210();
void FUN_00238980();
void FUN_00222b90();
void FUN_002230e0();

// FUN_0022b4e0
u32 bcmPanel0022b4e0(void)
{
    K_ASSERT(sBcmPanel != NULL, 0xe6);
    return *sBcmPanel & 2;
}

// FUN_0022b530
u32 bcmPanel0022b530(void)
{
    K_ASSERT(sBcmPanel != NULL, 0xe6);
    return *sBcmPanel & 8;
}

// FUN_0022b580
void bcmPanel0022b580(void)
{
    int iVar1;
    u32 uVar2;
    u32 uVar3;
    int iVar4;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    iVar1 = (int)sBcmPanel;
    uVar2 = FUN_0021c3f0(0);
    for (iVar4 = 0; iVar4 < 3; iVar4++) {
        uVar3 = FUN_0021cca0(uVar2, iVar4 + 0x3e);
        FUN_0021d3b0(iVar1 + iVar4 * 0x100 + 0x65f0, uVar3);
    }
}

// FUN_00222870
void bcmPanel00222870(void)
{
    int iVar1;
    u32 uVar2;
    u32 uVar3;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    iVar1 = (int)sBcmPanel;
    uVar2 = FUN_0021c3f0(0);
    *(u32*)(iVar1 + 0x4630) = 8;
    *(u32*)(iVar1 + 0x4638) = *(u32*)(iVar1 + 0x4634);
    *(u32*)(iVar1 + 0x4634) = 0;
    *(u32*)(iVar1 + 0x464c) = 0;
    uVar3 = FUN_0021cca0(uVar2, *(u32*)(iVar1 + 0x4634));
    FUN_0021d3b0(iVar1 + 0x1230, uVar3);
    uVar3 = FUN_0021cca0(uVar2, *(u32*)(iVar1 + 0x4638));
    FUN_0021d3b0(iVar1 + 0x1330, uVar3);
}

// FUN_002226f0
void bcmPanel002226f0(u32 param_1)
{
    int iVar1;
    u32 uVar2;
    u32 uVar3;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    iVar1 = (int)sBcmPanel;
    uVar2 = FUN_0021c3f0(0);
    *(u32*)(iVar1 + 0x4630) = 1;
    *(u32*)(iVar1 + 0x4638) = *(u32*)(iVar1 + 0x4634);
    *(u32*)(iVar1 + 0x4634) = param_1;
    *(u32*)(iVar1 + 0x464c) = 0;
    uVar3 = FUN_0021cca0(uVar2, *(u32*)(iVar1 + 0x4634));
    FUN_0021d3b0(iVar1 + 0x1230, uVar3);
    uVar3 = FUN_0021cca0(uVar2, *(u32*)(iVar1 + 0x4638));
    FUN_0021d3b0(iVar1 + 0x1330, uVar3);
}

// FUN_002227b0
void bcmPanel002227b0(u32 param_1)
{
    int iVar1;
    u32 uVar2;
    u32 uVar3;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    iVar1 = (int)sBcmPanel;
    uVar2 = FUN_0021c3f0(0);
    *(u32*)(iVar1 + 0x4630) = 2;
    *(u32*)(iVar1 + 0x4638) = *(u32*)(iVar1 + 0x4634);
    *(u32*)(iVar1 + 0x4634) = param_1;
    *(u32*)(iVar1 + 0x464c) = 0;
    uVar3 = FUN_0021cca0(uVar2, *(u32*)(iVar1 + 0x4634));
    FUN_0021d3b0(iVar1 + 0x1230, uVar3);
    uVar3 = FUN_0021cca0(uVar2, *(u32*)(iVar1 + 0x4638));
    FUN_0021d3b0(iVar1 + 0x1330, uVar3);
}

// FUN_00222930
void bcmPanel00222930(void)
{
    u32* puVar1;
    u32 uVar2;
    u32 uVar3;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    puVar1 = sBcmPanel;
    uVar2 = FUN_0021c3f0(0);
    *puVar1 |= 2;
    puVar1[1] = 0;
    puVar1[1] |= 1;
    puVar1[0x118c] = 3;
    puVar1[0x1190] = puVar1[0x118f];
    puVar1[0x118f] = 1;
    puVar1[0x1194] = 0;
    puVar1[0x1191] = 0;
    uVar3 = FUN_0021cca0(uVar2, puVar1[0x118d]);
    FUN_0021d3b0(puVar1 + 0x48c, uVar3);
    uVar3 = FUN_0021cca0(uVar2, puVar1[0x118d] + 7);
    FUN_0021d3b0(puVar1 + 0x4cc, uVar3);
    FUN_00226320();
    uVar3 = FUN_0021cca0(uVar2, 0x23);
    FUN_0021d3b0(puVar1 + 0x108c, uVar3);
    uVar3 = FUN_0021cca0(uVar2, 0x23);
    FUN_0021e380(puVar1 + 0x10cc, uVar3, 1);
    FUN_00222d60();
}

// FUN_00222a60
void bcmPanel00222a60(void)
{
    u32* puVar1;
    u32 uVar2;
    u32 uVar3;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    puVar1 = sBcmPanel;
    uVar2 = FUN_0021c3f0(0);
    *puVar1 |= 2;
    puVar1[1] = 0;
    puVar1[1] |= 2;
    puVar1[0x118c] = 3;
    puVar1[0x1190] = puVar1[0x118f];
    puVar1[0x118f] = 2;
    puVar1[0x1194] = 0;
    puVar1[0x1191] = 0;
    uVar3 = FUN_0021cca0(uVar2, puVar1[0x118d]);
    FUN_0021d3b0(puVar1 + 0x48c, uVar3);
    uVar3 = FUN_0021cca0(uVar2, puVar1[0x118d] + 7);
    FUN_0021d3b0(puVar1 + 0x4cc, uVar3);
    FUN_00226320();
    uVar3 = FUN_0021cca0(uVar2, 0x23);
    FUN_0021d3b0(puVar1 + 0x108c, uVar3);
    uVar3 = FUN_0021cca0(uVar2, 0x23);
    FUN_0021e380(puVar1 + 0x10cc, uVar3, 1);
    FUN_00222b90();
}

// FUN_00222ed0
void bcmPanel00222ed0(void)
{
    u32* puVar1;
    u32 uVar2;
    u32 uVar3;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    puVar1 = sBcmPanel;
    uVar2 = FUN_0021c3f0(0);
    *puVar1 |= 2;
    puVar1[0x118c] = 3;
    puVar1[0x1190] = puVar1[0x118f];
    puVar1[0x118f] = 0;
    puVar1[0x1194] = 0;
    uVar3 = FUN_0021cca0(uVar2, puVar1[0x118d]);
    FUN_0021d3b0(puVar1 + 0x48c, uVar3);
    uVar3 = FUN_0021cca0(uVar2, puVar1[0x118d] + 7);
    FUN_0021d3b0(puVar1 + 0x4cc, uVar3);
}

// FUN_00222fa0
void bcmPanel00222fa0(void)
{
    u32* puVar1;
    u32 uVar2;
    u32 uVar3;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    puVar1 = sBcmPanel;
    uVar2 = FUN_0021c3f0(0);
    *puVar1 |= 2;
    puVar1[1] = 0;
    puVar1[1] |= 4;
    puVar1[0x118c] = 3;
    puVar1[0x1190] = puVar1[0x118f];
    puVar1[0x118f] = 3;
    puVar1[0x1191] = 0;
    puVar1[0x1192] = 0xffffffff;
    puVar1[0x1194] = 0;
    puVar1[0x1196] = 0;
    uVar3 = FUN_0021cca0(uVar2, puVar1[0x118d]);
    FUN_0021d3b0(puVar1 + 0x48c, uVar3);
    uVar3 = FUN_0021cca0(uVar2, puVar1[0x118d] + 7);
    FUN_0021d3b0(puVar1 + 0x4cc, uVar3);
    FUN_00226320();
    uVar3 = FUN_0021cca0(uVar2, 0x24);
    FUN_0021d3b0(puVar1 + 0x108c, uVar3);
    uVar3 = FUN_0021cca0(uVar2, 0x24);
    FUN_0021e380(puVar1 + 0x10cc, uVar3, 1);
    FUN_002230e0();
}
