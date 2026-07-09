#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

void memcpy();

// FUN_003fb290
void fclShopMisc003fb290(void* param_1, void* param_2)
{
    K_ASSERT(param_1 != NULL, 0x1018);
    memcpy((int)param_1 + 0xc, param_2, 0x1c);
}
