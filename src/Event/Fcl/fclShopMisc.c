#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

void FUN_00521250();

// FUN_003fb290
void fclShopMisc003fb290(void* param_1, void* param_2)
{
    K_ASSERT(param_1 != NULL, 0x1018);
    FUN_00521250((int)param_1 + 0xc, param_2, 0x1c);
}
