#include "Camp/_h_camp_system.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rwplcore.h"

void FUN_004d0f00();
void FUN_001124b0();
void FUN_00100ec0();
void FUN_003c7dd0();

// FUN_00154770
void h_campSystem00154770(int param_1)
{
    int* workData;
    int i;

    workData = *(int**)(param_1 + 0x3c);
    if (workData[8] != 0) {
        FUN_004d0f00(workData[8]);
    }
    if (workData[5] != 0) {
        FUN_001124b0(workData[5]);
    }
    workData[5] = 0;
    if (workData[6] != 0) {
        FUN_001124b0(workData[6]);
    }
    workData[6] = 0;
    if (workData[3] != 0) {
        RwFree((void*)workData[3]);
    }
    workData[3] = 0;
    if (workData[4] != 0) {
        RwFree((void*)workData[4]);
    }
    workData[4] = 0;
    FUN_003c7dd0(8);
    FUN_003c7dd0(0xc);
    for (i = 0; i < 3; i++) {
        if (*(int*)((int)workData + i * 4 + 0x24) != 0) {
            FUN_00100ec0(*(int*)((int)workData + i * 4 + 0x24));
        }
        *(int*)((int)workData + i * 4 + 0x24) = 0;
    }
    RwFree(workData);
}
