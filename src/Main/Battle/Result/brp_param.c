#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Result/bp_ifont.h"

typedef struct
{
    u8 unused[0x3730];
    u32 unlockedSkillIndex;
    u32 unlockedSkillLevel;
    u8 unlockedSkillLevelGlyphs[1];
} BrpParamWork;

static BrpParamWork* sBrpParam; // iGpffffb6e0

// FUN_00279450
void brpParamSetUnlockedSkillLevel(u32 level)
{
    int workBase;

    K_ASSERT(sBrpParam != NULL, 0x61);
    /* MWCC requires this address form to retain the retail call setup. */
    workBase = (int)sBrpParam;
    *(u32*)(workBase + 0x3734) = level;
    bpIFont00238980((void*)(workBase + 0x3750), 2, level, 2);
}

// FUN_002794c0
void brpParamSetUnlockedSkillIndex(u32 index)
{
    K_ASSERT(sBrpParam != NULL, 0x61);
    sBrpParam->unlockedSkillIndex = index;
}
