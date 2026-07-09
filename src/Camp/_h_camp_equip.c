#include "Camp/_h_camp_equip.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rwplcore.h"

typedef struct
{
    f32 x;
    f32 y;
} CampVec2;

void* FUN_0012c430(KwlnTask*);
void FUN_001124b0();
void FUN_00100ec0();

// FUN_00130e40
void h_campEquip00130e40(int param_1)
{
    int* workData;

    workData = *(int**)(param_1 + 0x3c);
    if (workData[0xae] != 0) {
        RwFree((void*)workData[0xae]);
    }
    workData[0xae] = 0;
    if (workData[0xaf] != 0) {
        RwFree((void*)workData[0xaf]);
    }
    workData[0xaf] = 0;
    if (workData[0xb0] != 0) {
        RwFree((void*)workData[0xb0]);
    }
    workData[0xb0] = 0;
    if (workData[0xac] != 0) {
        FUN_001124b0(workData[0xac]);
    }
    workData[0xac] = 0;
    if (workData[0xad] != 0) {
        FUN_001124b0(workData[0xad]);
    }
    workData[0xad] = 0;
    if (workData[0] != 0) {
        FUN_00100ec0(workData[0]);
    }
    workData[0] = 0;
    RwFree(workData);
}

// FUN_00130f20
KwlnTask* h_campEquip00130f20(KwlnTask* parent, u32 priority, CampVec2 param_3, u16 param_4)
{
    u32* workData;
    KwlnTask* task;

    workData = (u32*)RwCalloc(1, 0x2c4, 0x40000);
    if (workData == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "H_CampSoubi1Draw", priority, FUN_0012c430, (KwlnTaskDestroyFunc)h_campEquip00130e40, workData);
    if (task == NULL) {
        return NULL;
    }
    *(CampVec2*)((int)workData + 8) = param_3;
    workData[5] = 1;
    *(u16*)((int)workData + 0x12) = param_4;
    return task;
}
