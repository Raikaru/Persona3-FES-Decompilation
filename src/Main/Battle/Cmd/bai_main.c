#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

#define BAI_MAIN_ACTIVE 1

typedef struct
{
    u32 unk0;  // 0x00
    u32 flags; // 0x04. See BAI_MAIN_*
} BaiMainWork;

static BaiMainWork* sBaiMain; // DAT_007ce338

// FUN_0024d0c0
u32 baiMainIsActive(void)
{
    K_ASSERT(sBaiMain != NULL, 0x37);
    return sBaiMain->flags & BAI_MAIN_ACTIVE;
}
