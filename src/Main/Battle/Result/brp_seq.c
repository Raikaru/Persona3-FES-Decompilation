#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBrpSeq; // puGpffffb6d0 / iGpffffb6d0

void FUN_0024b8a0();
void FUN_00279750();
void FUN_0010a4e0();
void FUN_003c7430();

// FUN_002737a0
void brpSeq002737a0(void)
{
    K_ASSERT(sBrpSeq != NULL, 0xb0);
    if ((*sBrpSeq & 0x40) != 0) {
        FUN_0024b8a0();
    }
}

// FUN_00273980
void brpSeq00273980(void)
{
    u32* puVar1;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    puVar1 = sBrpSeq;
    K_ASSERT((~*puVar1 & 2) != 0, 0x3a8);
    puVar1[4] = 6;
    *puVar1 &= 0xfffffffe;
}

// FUN_00273c00
void brpSeq00273c00(void)
{
    int iVar1;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    iVar1 = (int)sBrpSeq;
    FUN_00279750();
    FUN_0010a4e0(1, 0, 8, 2);
    *(u32*)(iVar1 + 0x18) = 0;
    *(u32*)(iVar1 + 0x10) = 3;
}

// FUN_00273e10
void brpSeq00273e10(void)
{
    int iVar1;

    K_ASSERT(sBrpSeq != NULL, 0xb0);
    iVar1 = (int)sBrpSeq;
    K_ASSERT(*(int*)(iVar1 + 0x74) == 9, 0x40e);
    FUN_003c7430(3);
    *(u32*)(iVar1 + 0x18) = 2;
}
