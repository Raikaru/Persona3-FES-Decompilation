#include "Camp/_h_camp_skill.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rwplcore.h"

extern u32 DAT_00833a50[];
void FUN_001124b0();
void H_Cdvd_Destroy();

// workData[0xc] holds the "camp/camp_skil.pak" cdvd handle.
// FUN_001616d0. Destroy callback of the "H_NewCampSkillDraw" (skill screen) task
void h_campSkillDestroySkillDrawTask(KwlnTask* task)
{
    int* workData;
    int i;

    workData = (int*)task->workData;
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
        H_Cdvd_Destroy(workData[0xc]);
    }
    workData[0xc] = 0;
    RwFree(workData);
}
