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

void* FUN_0011b420(KwlnTask*);
void FUN_0011d3a0(float, u32*);
void FUN_0011cc80(float, u32*);

// FUN_0011baa0
void h_camp0011baa0(int param_1)
{
    RwFree(*(void**)(param_1 + 0x3c));
    uGpffffb26c = 0;
}

// FUN_0011b9a0
u32 h_camp0011b9a0(int param_1)
{
    return *(u32*)(*(int*)(param_1 + 0x3c) + 0xc);
}

// FUN_0011b9b0
void h_camp0011b9b0(int param_1)
{
    u32* workData;

    workData = *(u32**)(param_1 + 0x3c);
    FUN_0011d3a0(100.0f, workData);
    workData[0] = 7;
    workData[1] = 0x16;
}

// FUN_0011ba00
void h_camp0011ba00(int param_1)
{
    u32* workData;

    workData = *(u32**)(param_1 + 0x3c);
    FUN_0011d3a0(100.0f, workData);
    workData[0] = 8;
    workData[1] = 0x16;
}

// FUN_0011ba50
void h_camp0011ba50(int param_1)
{
    u32* workData;

    workData = *(u32**)(param_1 + 0x3c);
    FUN_0011cc80(100.0f, workData);
    workData[0] = 5;
    workData[1] = 0;
    workData[3] = 0xffffffff;
}

// FUN_0011bad0
KwlnTask* h_camp0011bad0(KwlnTask* parent, u32 param_2, u32 param_3)
{
    u32* workData;
    KwlnTask* task;

    workData = (u32*)RwCalloc(1, 0x2c, 0x40000);
    if (workData == NULL) {
        return NULL;
    }
    task = kwlnTaskCreate(parent, "H_CampRootDraw", 0x18bf, FUN_0011b420, (KwlnTaskDestroyFunc)h_camp0011baa0, workData);
    if (task == NULL) {
        return NULL;
    }
    workData[9] = param_2;
    workData[3] = 0xffffffff;
    workData[2] = param_3;
    return task;
}