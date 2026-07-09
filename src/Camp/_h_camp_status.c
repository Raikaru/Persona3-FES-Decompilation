#include "Camp/_h_camp_status.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rwplcore.h"

void* FUN_001230c0(KwlnTask*);
void* FUN_001311d0(KwlnTask*);
void FUN_001124b0();
void H_Cdvd_Destroy();

typedef struct
{
    f32 x;
    f32 y;
} CampVec2;

// FUN_00123540. Destroy callback of the "H_CampPcStatusRoot" task
void h_campStatusDestroyPcStatusRootTask(KwlnTask* task)
{
    RwFree(task->workData);
}

// FUN_00123570
KwlnTask* h_campStatusCreatePcStatusRootTask(KwlnTask* parent, u32 priority, short param_3)
{
    u32* workData;
    KwlnTask* task;

    workData = (u32*)RwCalloc(1, 0x24, 0x40000);
    if (workData == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "H_CampPcStatusRoot", priority, FUN_001230c0, h_campStatusDestroyPcStatusRootTask, workData);
    if (task == NULL) {
        return NULL;
    }
    workData[3] = param_3;
    return task;
}

// FUN_001335d0. Destroy callback of the "H_CampStatusPersonaDraw" task
void h_campStatusDestroyPersonaDrawTask(KwlnTask* task)
{
    int* workData;
    int i;

    workData = (int*)task->workData;
    for (i = 0; i < 3; i++) {
        if (*(int*)((int)workData + i * 4 + 0x58) != 0) {
            FUN_001124b0(*(int*)((int)workData + i * 4 + 0x58));
        }
        *(int*)((int)workData + i * 4 + 0x58) = 0;
    }
    if (workData[0x19] != 0) {
        RwFree((void*)workData[0x19]);
    }
    workData[0x19] = 0;
    if (workData[0x1a] != 0) {
        RwFree((void*)workData[0x1a]);
    }
    workData[0x1a] = 0;
    if (workData[0x14] != 0) {
        H_Cdvd_Destroy(workData[0x14]);
    }
    workData[0x14] = 0;
    RwFree(workData);
}

// FUN_001336b0
KwlnTask* h_campStatusCreatePersonaDrawTask(KwlnTask* parent, u32 priority, CampVec2 param_3, u16 param_4)
{
    u32* workData;
    KwlnTask* task;

    workData = (u32*)RwCalloc(1, 0x6c, 0x40000);
    if (workData == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "H_CampStatusPersonaDraw", priority, FUN_001311d0, h_campStatusDestroyPersonaDrawTask, workData);
    if (task == NULL) {
        return NULL;
    }
    *(CampVec2*)((int)workData + 0x10) = param_3;
    *(u16*)((int)workData + 0x18) = param_4;
    return task;
}

// FUN_001266e0. Destroy callback of the "H_PcStatusParts00" task
void h_campStatusDestroyPcStatusPartsTask(KwlnTask* task)
{
    RwFree(task->workData);
}
