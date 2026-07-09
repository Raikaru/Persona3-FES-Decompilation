#include "Camp/_h_camp_item.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rwplcore.h"

extern u32 DAT_00833a50[];
void FUN_001124b0();
void FUN_00100ec0();

// FUN_0014ed20
void h_campItem0014ed20(int param_1)
{
    int* workData;
    int i;

    workData = *(int**)(param_1 + 0x3c);
    for (i = 0; i < 3; i++) {
        if (*(int*)((int)workData + i * 4 + 0xb0) != 0) {
            FUN_001124b0(*(int*)((int)workData + i * 4 + 0xb0));
            *(int*)((int)workData + i * 4 + 0xb0) = 0;
            DAT_00833a50[i] = 0;
        }
    }
    if (workData[2] != 0) {
        FUN_00100ec0(workData[2]);
        workData[2] = 0;
    }
    if (workData[0x29] != 0) {
        RwFree((void*)workData[0x29]);
    }
    if (workData[0x2a] != 0) {
        RwFree((void*)workData[0x2a]);
    }
    if (workData[0x2b] != 0) {
        RwFree((void*)workData[0x2b]);
    }
    if (workData[0x2f] != 0) {
        RwFree((void*)workData[0x2f]);
    }
    if (workData[0x30] != 0) {
        RwFree((void*)workData[0x30]);
    }
    if (workData[0x31] != 0) {
        RwFree((void*)workData[0x31]);
    }
    RwFree(workData);
}
