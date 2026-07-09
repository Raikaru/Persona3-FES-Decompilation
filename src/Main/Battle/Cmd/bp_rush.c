#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBpRush; // DAT_007ce36c

void FUN_0025d130();

// FUN_0025d6c0
void bpRush0025d6c0(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    *sBpRush |= 0x10;
}

// FUN_0025d710
void bpRush0025d710(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    *sBpRush &= 0xffffffef;
}

// FUN_0025d760
void bpRush0025d760(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    *sBpRush |= 0x20;
}

// FUN_0025d7b0
void bpRush0025d7b0(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    *sBpRush &= 0xffffffdf;
}

// FUN_0025d800
void bpRush0025d800(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    *sBpRush |= 0x40;
}

// FUN_0025d850
void bpRush0025d850(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    *sBpRush &= 0xffffffbf;
}

// FUN_0025d020
void bpRush0025d020(void)
{
    u32* work;
    u32 v;

    K_ASSERT(sBpRush != NULL, 0x32);
    work = sBpRush;
    if ((~*sBpRush & 1) == 0) {
        v = work[0x206];
        work[0x206] = v + 1;
        work[0x206] = (int)(v + 1) % 10;
        if ((*work & 0x10) != 0 || (*work & 0x20) != 0) {
            if (0 < (int)work[0x204]) {
                work[0x204] = work[0x204] - 1;
            }
        } else if ((int)work[0x204] < 0x10) {
            work[0x204] = work[0x204] + 1;
        }
        if ((*work & 0x40) != 0) {
            if ((int)work[0x205] < 10) {
                work[0x205] = work[0x205] + 1;
            }
        } else if (0 < (int)work[0x205]) {
            work[0x205] = work[0x205] - 1;
        }
        FUN_0025d130();
    }
}
