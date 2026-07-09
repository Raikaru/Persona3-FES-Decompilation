#include "Camp/_h_camp_status.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rwplcore.h"

void* FUN_001230c0(KwlnTask*);

// FUN_00123540
void h_campStatus00123540(int param_1)
{
    RwFree(*(void**)(param_1 + 0x3c));
}

// FUN_00123570
KwlnTask* h_campStatus00123570(KwlnTask* parent, u32 priority, short param_3)
{
    u32* workData;
    KwlnTask* task;

    workData = (u32*)RwCalloc(1, 0x24, 0x40000);
    if (workData == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "H_CampPcStatusRoot", priority, FUN_001230c0, (KwlnTaskDestroyFunc)h_campStatus00123540, workData);
    if (task == NULL) {
        return NULL;
    }
    workData[3] = param_3;
    return task;
}
