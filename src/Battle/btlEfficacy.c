#include "Battle/btlEfficacy.h"
#include "Main/Battle/Data/datUnit.h"

extern int func_002d4e10(u32 genusMask, u32 excludedBadStatus);

enum
{
    BTL_EFFICACY_ENEMY_GENUS_MASK = 1 << UNIT_GENUS_EC,
    BTL_EFFICACY_NO_RESULT = -1,
    BTL_EFFICACY_ONE_TO_FOUR_ENEMY_COUNT_END = 5,
    BTL_EFFICACY_TWO_TO_FIVE_ENEMY_COUNT_START = 2,
    BTL_EFFICACY_TWO_TO_FIVE_ENEMY_COUNT_END = 6,
    BTL_EFFICACY_ONE_TO_FOUR_RESULT_BASE = 0x6C,
    BTL_EFFICACY_TWO_TO_FIVE_RESULT_BASE = 0x72
};

// FUN_002d8780
int btlEfficacyGetResultIndexForOneToFourEnemies(void)
{
    int activeEnemyCount;

    activeEnemyCount = func_002d4e10(BTL_EFFICACY_ENEMY_GENUS_MASK, UNIT_BADSTATUS_DEAD) & 0xffff;
    if (activeEnemyCount >= BTL_EFFICACY_ONE_TO_FOUR_ENEMY_COUNT_END)
    {
        return BTL_EFFICACY_NO_RESULT;
    }
    if (activeEnemyCount == 0)
    {
        return BTL_EFFICACY_NO_RESULT;
    }
    return BTL_EFFICACY_ONE_TO_FOUR_RESULT_BASE - activeEnemyCount;
}

// FUN_002d87e0
int btlEfficacyGetResultIndexForTwoToFiveEnemies(void)
{
    int activeEnemyCount;

    activeEnemyCount = func_002d4e10(BTL_EFFICACY_ENEMY_GENUS_MASK, UNIT_BADSTATUS_DEAD) & 0xffff;
    // Keep the retail comparison forms: this callback accepts enemy counts [2, 5].
    if (activeEnemyCount > 5)
    {
        return BTL_EFFICACY_NO_RESULT;
    }
    if (activeEnemyCount < 2)
    {
        return BTL_EFFICACY_NO_RESULT;
    }
    return BTL_EFFICACY_TWO_TO_FIVE_RESULT_BASE - activeEnemyCount;
}
