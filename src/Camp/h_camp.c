#include "Camp/h_camp.h"
#include "rw/rwplcore.h"
#include "Kernel/Kwln/kwlnTask.h"


// TODO

static const char* courageLevelString[] =
{
    "Timid", "Ordinary", "Determined", "Though", "Fearless", "Badass"
};

static const char* charmLevelString[] =
{   
    "Plain", "Unpolished", "Confident", "Smooth", "Popular", "Charismatic"
};

static const char* academicLevelString[] = 
{
    "Slacker", "Average", "Above Average", "Smart", "Intelligent", "Genius"
};

// FUN_0011a810
const char* h_camp_getAcademicLevelString(s16 idx)
{
    return academicLevelString[idx];
}

// FUN_0011a840
const char* h_camp_getCharmLevelString(s16 idx)
{
    return charmLevelString[idx];
}

// FUN_0011a870
const char* h_camp_getCourageLevelString(s16 idx)
{
    return courageLevelString[idx];
}

void FUN_0016f1f0();

static u32 uGpffffb260;
static u32 uGpffffb264;
static u32 uGpffffb268;
static u32 uGpffffb26c;

// FUN_0011a710
void h_camp0011a710(int param_1)
{
    void* workData;

    workData = *(void**)(param_1 + 0x3c);
    uGpffffb264 = 0;
    uGpffffb268 = 0;
    uGpffffb260 = 0;
    uGpffffb26c = 0;
    FUN_0016f1f0(0x1407, 0);
    RwFree(workData);
}

void* FUN_0011a050(KwlnTask*);

// FUN_0011a770
KwlnTask* h_camp0011a770(KwlnTask* parent)
{
    void* workData;
    KwlnTask* task;

    workData = RwCalloc(1, 0x48, 0x40000);
    if (workData == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "H_CampDraw", 0x18bf, FUN_0011a050, (KwlnTaskDestroyFunc)h_camp0011a710, workData);
    if (task == NULL) {
        return NULL;
    }
    return task;
}