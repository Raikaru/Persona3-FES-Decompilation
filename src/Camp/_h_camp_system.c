#include "Camp/_h_camp_system.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rwplcore.h"

void FUN_004d0f00();
void FUN_001124b0();
void H_Cdvd_Destroy();
void FUN_003c7dd0();

// FUN_00154770. Destroy callback of the "H_CampSystemMenuDraw" task
void h_campSystemDestroyMenuDrawTask(KwlnTask* task)
{
    int* workData;
    int i;

    workData = (int*)task->workData;
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
            H_Cdvd_Destroy(*(int*)((int)workData + i * 4 + 0x24));
        }
        *(int*)((int)workData + i * 4 + 0x24) = 0;
    }
    RwFree(workData);
}
