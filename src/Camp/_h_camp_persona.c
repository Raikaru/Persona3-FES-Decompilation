#include "Camp/_h_camp_persona.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rwplcore.h"

void* FUN_00122940(KwlnTask*);

// FUN_00122fd0
void h_campPersona00122fd0(int param_1)
{
    RwFree(*(void**)(param_1 + 0x3c));
}

// FUN_00123000
KwlnTask* h_campPersona00123000(KwlnTask* parent, u32 param_2)
{
    u32* workData;
    KwlnTask* task;

    workData = (u32*)RwCalloc(1, 0x1c, 0x40000);
    if (workData == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "h_camp_persona_kani_control", 0x18c1, FUN_00122940, (KwlnTaskDestroyFunc)h_campPersona00122fd0, workData);
    if (task == NULL) {
        return NULL;
    }
    workData[3] = 0;
    workData[4] = param_2;
    *(u16*)((int)workData + 0x18) = 1;
    return task;
}
