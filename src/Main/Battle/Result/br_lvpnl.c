#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBrLvpnl; // DAT_007ce3c8

// FUN_002767e0
void brLvpnl002767e0(void)
{
    u32* work;

    K_ASSERT(sBrLvpnl != NULL, 0x3b);
    work = sBrLvpnl;
    if (*work & 4) {
        work[0x185] = 1;
        work[0x184] = 0;
        *work |= 2;
    } else {
        work[0x185] = 0;
        work[0x184] = 0;
        *work |= 2;
        *work |= 4;
    }
}

// FUN_00276870
void brLvpnl00276870(void)
{
    K_ASSERT(sBrLvpnl != NULL, 0x3b);
    *sBrLvpnl |= 8;
}

// FUN_002768c0
void brLvpnl002768c0(void)
{
    K_ASSERT(sBrLvpnl != NULL, 0x3b);
    *sBrLvpnl &= 0xfffffff7;
}
