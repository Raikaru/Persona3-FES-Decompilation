#include "Camp/_h_camp_persona.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rwplcore.h"

void* FUN_00122940(KwlnTask*);
void FUN_00133d30();
void H_Cdvd_Destroy();
void FUN_004d0f00();

// FUN_00122fd0. Destroy callback of the "h_camp_persona_kani_control" task
void h_campPersonaDestroyKaniControlTask(KwlnTask* task)
{
    RwFree(task->workData);
}

// FUN_00123000
KwlnTask* h_campPersonaCreateKaniControlTask(KwlnTask* parent, u32 param_2)
{
    u32* workData;
    KwlnTask* task;

    workData = (u32*)RwCalloc(1, 0x1c, 0x40000);
    if (workData == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "h_camp_persona_kani_control", 0x18c1, FUN_00122940, h_campPersonaDestroyKaniControlTask, workData);
    if (task == NULL) {
        return NULL;
    }
    workData[3] = 0;
    workData[4] = param_2;
    *(u16*)((int)workData + 0x18) = 1;
    return task;
}

// FUN_00133900. Destroy callback of the "CampPersonaDispCtlDraw" task
void h_campPersonaDestroyDispCtlDrawTask(KwlnTask* task)
{
    int* workData;

    workData = (int*)task->workData;
    if (workData[8] != 0) {
        FUN_00133d30(workData[8], workData[9]);
        workData[8] = 0;
        workData[9] = 0;
        workData[0xa] = 0;
    } else {
        if (workData[9] != 0) {
            H_Cdvd_Destroy(workData[9]);
            workData[9] = 0;
        }
        if (workData[0xa] != 0) {
            FUN_004d0f00(workData[0xa]);
            workData[0xa] = 0;
        }
    }
    RwFree(workData);
}
