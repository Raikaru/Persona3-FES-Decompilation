#include "Camp/_h_camp_skill.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rwplcore.h"

extern u32 DAT_00833a50[];
void FUN_001124b0();
void FUN_00100ec0();

// FUN_001616d0
void h_campSkill001616d0(int param_1)
{
    int* workData;
    int i;

    workData = *(int**)(param_1 + 0x3c);
    if (workData[0xe] != 0) {
        RwFree((void*)workData[0xe]);
    }
    workData[0xe] = 0;
    if (workData[0xa] != 0) {
        RwFree((void*)workData[0xa]);
    }
    workData[0xa] = 0;
    for (i = 0; i < 3; i++) {
        if (*(int*)((int)workData + i * 4 + 0x1c) != 0) {
            FUN_001124b0(*(int*)((int)workData + i * 4 + 0x1c));
        }
        *(int*)((int)workData + i * 4 + 0x1c) = 0;
        DAT_00833a50[i] = 0;
    }
    if (workData[0xc] != 0) {
        FUN_00100ec0(workData[0xc]);
    }
    workData[0xc] = 0;
    RwFree(workData);
}
