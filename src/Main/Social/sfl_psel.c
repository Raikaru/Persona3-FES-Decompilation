#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sSflPsel; // puGpffffb688
u32 FUN_0020ec50();
u32 FUN_0021cca0();
void FUN_0021d3b0();
float FUN_0021ea00();
void FUN_0021eac0(void*, float);
void FUN_00260c20();
void FUN_00261480();

// FUN_00260a10
void sflPsel00260a10(void)
{
    K_ASSERT(sSflPsel != NULL, 0x57);
    sSflPsel = NULL;
}

// FUN_00260bd0
void sflPsel00260bd0(void)
{
    K_ASSERT(sSflPsel != NULL, 0x57);
    *sSflPsel &= 0xfffffffe;
}

// FUN_00260c20
void sflPsel00260c20(void)
{
    u32* work;

    K_ASSERT(sSflPsel != NULL, 0x57);
    work = sSflPsel;
    work[2] = 0;
    work[1] = 0;
    *work |= 2;
}

// FUN_00260c70
void sflPsel00260c70(void)
{
    u32* work;

    K_ASSERT(sSflPsel != NULL, 0x57);
    work = sSflPsel;
    work[2] = 0;
    work[1] = 1;
    *work |= 2;
}

// FUN_00260cd0
u32 sflPsel00260cd0(void)
{
    K_ASSERT(sSflPsel != NULL, 0x57);
    return *sSflPsel & 2;
}

// FUN_00260a50
void sflPsel00260a50(void)
{
    u32* puVar1;
    u32 uVar2;
    u32 uVar3;
    float fVar4;
    float fVar5;

    K_ASSERT(sSflPsel != NULL, 0x57);
    puVar1 = sSflPsel;
    uVar2 = FUN_0020ec50();
    uVar3 = FUN_0021cca0(uVar2, 0x34);
    FUN_0021d3b0(puVar1 + 0x104, uVar3);
    fVar4 = FUN_0021ea00(0x1e);
    FUN_0021eac0(puVar1 + 0x104, fVar4);
    uVar3 = FUN_0021cca0(uVar2, 0x35);
    FUN_0021d3b0(puVar1 + 0x144, uVar3);
    fVar4 = FUN_0021ea00(0x1e);
    FUN_0021eac0(puVar1 + 0x144, fVar4);
    uVar3 = FUN_0021cca0(uVar2, 0x36);
    FUN_0021d3b0(puVar1 + 0x184, uVar3);
    fVar4 = FUN_0021ea00(0x1e);
    FUN_0021eac0(puVar1 + 0x184, fVar4);
    uVar3 = FUN_0021cca0(uVar2, 0x3a);
    FUN_0021d3b0(puVar1 + 0x1c4, uVar3);
    fVar4 = FUN_0021ea00(0x32);
    FUN_0021eac0(puVar1 + 0x1c4, fVar4);
    fVar5 = FUN_0021ea00(0x32);
    ((float*)puVar1)[0x206] = fVar5;
    ((float*)puVar1)[0x216] = fVar5;
    ((float*)puVar1)[0x226] = fVar5;
    FUN_00260c20();
    FUN_00261480();
    *puVar1 |= 1;
}
