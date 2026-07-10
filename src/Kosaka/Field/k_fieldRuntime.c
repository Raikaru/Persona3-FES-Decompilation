#include "Utils.h"
#include "h_cdvd.h"
typedef struct Model Model;
#define MDL_READASYNC 0
#define MODEL_TYPE_FLD 4
extern Model* mdlCreateFromPath(u16 type, u16 id, const char* path, u32 readMode);
extern Model* mdlCreateAndResolvePath(u16 type, u16 id, u32 readMode);

typedef struct RuntimeTask RuntimeTask;
typedef struct RuntimeWork RuntimeWork;
typedef struct RuntimeListNode RuntimeListNode;

typedef struct RuntimeVec3
{
    f32 x;
    f32 y;
    f32 z;
} RuntimeVec3;

struct RuntimeTask
{
    u8 reserved[0x3c];
    RuntimeWork* workData;
};

struct RuntimeWork
{
    u32 flags;
    u32 requestFlags;
    u32 completedFlags;
    u32 state;
    u32 phase;
    u32 selection;
    u32 currentIndex;
    u32 count;
    void* owner;
    void* resource;
    void* renderData;
    void* childTask;
    RuntimeListNode* previous;
    RuntimeListNode* next;
    RuntimeVec3* positions;
    RuntimeVec3* normals;
    u32 slots[1024];
};

struct RuntimeListNode
{
    u32 flags;
    RuntimeWork* work;
    void* vertices;
    void* renderObjects;
    RuntimeListNode* previous;
    RuntimeListNode* next;
};
typedef struct FieldRuntimeResourceNode FieldRuntimeResourceNode;
typedef struct FieldRuntimeTaskNode FieldRuntimeTaskNode;

struct FieldRuntimeResourceNode
{
    u8 reserved0[8];
    u16 resourceId;
    u8 reserved1[0x5e];
    FieldRuntimeResourceNode* previous;
    FieldRuntimeResourceNode* next;
};

struct FieldRuntimeTaskNode
{
    void* task;
    u8 reserved0[0x4c];
    u16 resourceId;
    u8 reserved1[2];
    FieldRuntimeTaskNode* previous;
    FieldRuntimeTaskNode* next;
};

extern void* RwCalloc(u32 count, u32 size, u32 hint);
extern void RwFree(void* memory);
extern void* kwlnTaskCreateWithAutoPriority(void* parent, s32 priority, const char* name, void* update, void* destroy, void* work);
extern void kwlnTaskDestroyWithHierarchy(void* task);
extern s32 kwlnTaskExists(void* task);
extern HCdvd* K_Fldrc_GetFldPacCdvd(void);
extern char D_00684020[];
extern char D_00684410[];
extern char D_00684430[];
extern char D_006844B0[];
extern char D_00684060[];
extern char D_00684040[];
extern void* (*DAT_00960184)(u32, ...);
extern FieldRuntimeResourceNode* D_006845C8;
extern FieldRuntimeTaskNode* D_006845CC;
extern void* func_001b83f0(void);
extern void* func_001b85a0(void* record);
extern void* func_001b8d60(void);
extern void* func_001b8db0(void* record);
extern void func_003b78b0(u16 resourceId, void* position, void* angles);
extern u16 func_003b5e90(u16 resourceId);
extern f32 func_001a5aa0(void* matrix);
extern f32 func_001a5bc0(void* matrix);
extern f32 func_001a5b30(void* matrix);
extern s32 H_Fade_IsFadeOutDone(void);
extern void H_Fade_FadeOut(void);
extern void H_Fade_FadeIn(void);
extern void H_Fade_SetType(s32 type);
extern void H_Fade_SetDuration(s32 duration);
extern void func_001e2430(RuntimeTask* task);
extern void* kwlnGetMainCamera(void);
extern void func_001e0510(void* task, void* camera);
extern void* func_001e4b40(void* task);
extern void* func_001e5850(void* task);
extern void* func_001e6030(void* task);
extern void* func_001e6a70(void* task);
extern void func_001e2930(s32 value);
extern void func_001e2b10(s32 value);
extern s32 func_001e2bd0(s32 value);
extern void func_001e9a90(void* work);
extern s32 func_001ed9e0(void* work);
extern void func_001edbe0(void* work);
extern void func_001edf10(void* work);
extern void func_001eba50(RuntimeWork* work);
extern void func_001eba80(RuntimeWork* work, u32* result);
extern s32 func_00236340(void);
extern void func_002362e0(void);
extern void func_003c7430(s32 mode);
extern s32 func_003c7850(void);
extern void func_003c7650(s32 mode);
extern void func_003c72d0(void* work);
extern void* func_002345d0(s32 mode);
extern void func_003c77a0(void);
extern void func_003c7990(s32 mode);
extern void func_003c7c20(s32 group, s32 id, s32 kind);
extern void func_0010a4e0(s32 a0, s32 a1, s32 a2, s32 a3);
extern void H_Snd_PlayBgm(s32 id, s32 restart);
extern void func_0010a370(s32 mode, const char* name);
extern void func_00234070(void);
extern void func_00235010(void);
extern void func_00263170(void);
extern void func_00272810(void);
extern void func_00275bc0(void);
extern void func_00276930(void);
extern void func_002770f0(void);

extern s32 func_001ef7f0(RuntimeTask* task);
extern void func_001f07a0(RuntimeTask* task);
static void Runtime_Clear(RuntimeWork* work, u32 first, u32 count)
{
    u32 i;

    for (i = 0; i < count; i++)
    {
        work->slots[first + i] = 0;
    }
}

static void Runtime_Unlink(RuntimeListNode** head, RuntimeListNode** tail, RuntimeListNode* node)
{
    if (node->next != NULL)
    {
        node->next->previous = node->previous;
    }
    if (node->previous != NULL)
    {
        node->previous->next = node->next;
    }
    if (*head == node)
    {
        *head = node->next;
    }
    if (*tail == node)
    {
        *tail = node->previous;
    }
}

static u32 Runtime_RingIndex(const RuntimeWork* work, u32 index)
{
    s32 remaining;

    remaining = (s32)work->count - 1 - (s32)index;
    if (remaining < 0)
    {
        remaining += (s32)work->slots[0];
    }
    return (u32)remaining;
}

// FUN_001E1850 NONMATCHING
s32 func_001e1850(RuntimeTask* task)
{
    RuntimeWork* work;
    void* controller;

    work = task->workData;
    controller = NULL;
    switch (work->state)
    {
        case 0:
            work->resource = RwCalloc(1, 0x20, 2);
            work->selection = work->slots[5] & 0xff;
            work->state = 1;
            break;

        case 1:
            if ((work->requestFlags & 0x40) != 0)
            {
                switch (work->selection)
                {
                    case 0: controller = task; func_001e0510(task, kwlnGetMainCamera()); break;
                    case 1: controller = func_001e4b40(task); break;
                    case 2: controller = func_001e5850(task); break;
                    case 3: controller = func_001e6030(task); break;
                    case 4: controller = func_001e6a70(task); break;
                    default: break;
                }
                if (controller != NULL)
                {
                    work->childTask = controller;
                    work->state = 2;
                }
            }
            break;

        case 2:
            if (work->childTask == NULL || kwlnTaskExists(work->childTask) == 0)
            {
                if (work->resource != NULL)
                {
                    RwFree(work->resource);
                    work->resource = NULL;
                }
                work->state = 3;
            }
            break;

        case 3:
            if ((work->requestFlags & 0x20) != 0)
            {
                func_001e2930(0);
                func_001e2b10(1);
                Runtime_Clear(work, 0, 2);
                work->state = 4;
            }
            break;

        case 4:
            if ((work->requestFlags & 0x40) != 0)
            {
                work->selection = (work->selection + 1) & 0xff;
            }
            else if ((work->requestFlags & 0x20) != 0)
            {
                work->selection = (work->selection - 1) & 0xff;
            }
            else if ((work->requestFlags & 0x0a) != 0)
            {
                work->selection = (work->selection + 10) & 0xff;
            }
            else if ((work->requestFlags & 0x05) != 0)
            {
                work->selection = (work->selection - 10) & 0xff;
            }
            if ((work->requestFlags & 0x40) != 0 && func_001e2bd0((s32)work->selection) != 0)
            {
                work->completedFlags |= 1;
                work->state = 5;
            }
            break;

        default:
            return -1;
    }
    return 0;
}

// FUN_001E2300 NONMATCHING
void func_001e2300(RuntimeTask* task)
{
    RuntimeWork* work;

    work = task->workData;
    func_001e2930(0);
    func_001e2b10(0);
    Runtime_Clear(work, 0, 2);
    if (work->resource != NULL)
    {
        RwFree(work->resource);
        work->resource = NULL;
    }
}

// FUN_001E2370 NONMATCHING
RuntimeTask* func_001e2370(RuntimeTask* parent)
{
    RuntimeWork* work;
    RuntimeTask* task;

    work = RwCalloc(1, 0x18, 4);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent, 10, "field transition", func_001e1850, func_001e2300, work);
    if (task == NULL)
    {
        RwFree(work);
        return NULL;
    }
    func_001e2430(task);
    return task;
}

// FUN_001E2430 NONMATCHING
void func_001e2430(RuntimeTask* task)
{
    RuntimeWork* work;
    u32 i;

    work = task->workData;
    work->count = 0;
    work->currentIndex = 0;
    Runtime_Clear(work, 0, 24);
    for (i = 0; i < 8; i++)
    {
        work->slots[i * 3] = i;
        work->slots[i * 3 + 1] = 0;
        work->slots[i * 3 + 2] = 0;
    }
}

// FUN_001E2810 NONMATCHING
RuntimeWork* func_001e2810(RuntimeWork* head, u16 id)
{
    RuntimeWork* current;

    current = head;
    while (current != NULL)
    {
        if ((u16)current->slots[2] == id)
        {
            break;
        }
        current = (RuntimeWork*)current->resource;
    }
    return current;
}

// FUN_001E2850 NONMATCHING
RuntimeWork* func_001e2850(void)
{
    RuntimeWork* work;

    work = RwCalloc(1, 0x68, 4);
    if (work != NULL)
    {
        work->flags = 1;
        work->count = 1;
    }
    return work;
}

// FUN_001E28A0 NONMATCHING
void func_001e28a0(RuntimeWork* work)
{
    if (work != NULL)
    {
        Runtime_Clear(work, 0, 24);
        RwFree(work);
    }
}

// FUN_001E2930
void func_001e2930(s32 enabled)
{
    FieldRuntimeResourceNode* node;

    node = D_006845C8;
    while (node != NULL)
    {
        if (enabled == 1)
        {
            func_003b7090(node->resourceId);
        }
        if (node->previous != NULL)
        {
            node->previous->next = node->next;
        }
        else
        {
            D_006845C8 = node->next;
        }
        if (node->next != NULL)
        {
            node->next->previous = node->previous;
        }
        (*(void (**)(void*))0x0096017C)(node);
        node = node->next;
    }
}

// FUN_001E29E0 NONMATCHING
void func_001e29e0(RuntimeWork* work, s32 value)
{
    if (work != NULL)
    {
        work->flags = (work->flags & ~1) | (value != 0);
    }
}

// FUN_001E2A20 NONMATCHING
RuntimeWork* func_001e2a20(void)
{
    RuntimeWork* work;

    work = RwCalloc(1, 0x70, 4);
    if (work != NULL)
    {
        work->flags = 3;
    }
    return work;
}

// FUN_001E2A70 NONMATCHING
void func_001e2a70(RuntimeWork* work)
{
    if (work != NULL)
    {
        work->flags &= ~3;
        RwFree(work);
    }
}

// FUN_001E2B10
void func_001e2b10(s32 enabled)
{
    FieldRuntimeTaskNode* node;

    node = D_006845CC;
    while (node != NULL)
    {
        if (enabled == 1)
        {
            func_003b7090(node->resourceId);
        }
        kwlnTaskDestroyWithHierarchy(node->task);
        if (node->previous != NULL)
        {
            node->previous->next = node->next;
        }
        else
        {
            D_006845CC = node->next;
        }
        if (node->next != NULL)
        {
            node->next->previous = node->previous;
        }
        (*(void (**)(void*))0x0096017C)(node);
        node = node->next;
    }
}

// FUN_001E2BD0 NONMATCHING
s32 func_001e2bd0(s32 value)
{
    return value >= 0 && value < 256;
}

// FUN_001E2DA0 NONMATCHING
HCdvd* func_001e2da0(u16 majorId, u16 minorId, s16 variant)
{
    char path[128];

    if (K_Fldrc_GetFldPacCdvd() != NULL)
    {
        return (HCdvd*)1;
    }
    sprintf(path, D_00684020, majorId, minorId, (s32)variant);
    if (H_Cdvd_FileExists(path) == 0)
    {
        return NULL;
    }
    return H_Cdvd_Request(path, HCDVD_FILENORMAL);
}

// FUN_001E2E50 NONMATCHING
u32 func_001e2e50(void* request, void** outFileMemory,
                  u16 majorId, u16 minorId, s16 variant)
{
    u8* field;
    u8* fileMemory;
    u32 fileSize;
    u32 modelCount;
    u32 placementCount;
    u32 i;
    u32 modelIndex;
    u32* metadata;
    Model** models;

    if (outFileMemory != NULL)
    {
        *outFileMemory = NULL;
    }
    if (request == NULL)
    {
        return true;
    }

    fileMemory = NULL;
    fileSize = 0;
    if (K_Fldrc_GetFldPacCdvd() != NULL)
    {
        char path[128];

        sprintf(path, D_00684060, majorId, minorId, (s32)variant);
        fileMemory = (u8*)H_Cdvd_CacheFindFile(path, &fileSize);
        if (fileMemory == NULL)
        {
            return false;
        }
    }
    else
    {
        if (H_Cdvd_IsFileLoaded((HCdvd*)request) == 0)
        {
            return false;
        }
        fileMemory = (u8*)((HCdvd*)request)->fileMemory;
        fileSize = ((HCdvd*)request)->fileSize;
    }
    if (outFileMemory != NULL)
    {
        *outFileMemory = fileMemory;
    }

    field = (u8*)K_Field_Get();
    modelCount = *(u32*)(fileMemory + 0x08);
    *(u32*)(field + 0x10c0) = modelCount;
    models = (Model**)RwCalloc(1, modelCount * sizeof(Model*), 0x40000);
    metadata = (u32*)RwCalloc(1, modelCount * 9 * sizeof(u32), 0x40000);
    *(Model***)(field + 0x10c4) = models;
    *(u32**)(field + 0x10c8) = metadata;
    if (modelCount != 0 && (models == NULL || metadata == NULL))
    {
        return false;
    }

    modelIndex = 0;
    for (i = 0; i < modelCount; i++)
    {
        u8* record = fileMemory + 0x18 + i * 0x70;
        u16 type = *(u16*)(record + 0x04);
        u16 id = *(u16*)(record + 0x06);
        Model* model;

        if (type == MODEL_TYPE_FLD && id == 0xffff &&
            (*(u32*)0x007ce200 == 1))
        {
            model = mdlCreateFromPath(type, id, D_00684040, MDL_READASYNC);
        }
        else
        {
            model = mdlCreateAndResolvePath(type, id, MDL_READASYNC);
        }
        if (model != NULL)
        {
            models[modelIndex] = model;
            metadata[modelIndex * 9 + 2] = i;
            modelIndex++;
        }
    }

    placementCount = *(u32*)(fileMemory + 0x10);
    for (i = 0; i < placementCount; i++)
    {
        u8* record = fileMemory + 0x18 + i * 0x60;
        u16 resourceId = (u16)(*(u16*)(record + 0x50) & 0x3ff);
        f32 angles[3];

        resourceId = func_003b5e90(resourceId);
        angles[0] = func_001a5b30(record + 0x10);
        angles[1] = func_001a5aa0(record + 0x10);
        angles[2] = func_001a5bc0(record + 0x10);
        func_003b78b0(resourceId, record + 0x40, angles);
    }
    (void)fileSize;
    return true;
}

// FUN_001E3940 NONMATCHING
void* func_001e3940(RuntimeTask* parent)
{
    RuntimeWork* work;

    work = RwCalloc(1, 0x120, 4);
    if (work != NULL)
    {
        work->owner = parent;
        work->state = 0;
    }
    return work;
}

// FUN_001E3F10 NONMATCHING
void func_001e3f10(RuntimeWork* work)
{
    if (work != NULL)
    {
        if (work->childTask != NULL)
        {
            kwlnTaskDestroyWithHierarchy(work->childTask);
        }
        RwFree(work);
    }
}

// FUN_001E4B10 NONMATCHING
void func_001e4b10(RuntimeWork* work, u32 request)
{
    if (work != NULL)
    {
        work->requestFlags = request;
        work->state = 0;
    }
}

// FUN_001E4B40 NONMATCHING
void* func_001e4b40(void* parent)
{
    RuntimeWork* work;

    work = RwCalloc(1, 0x58, 4);
    if (work == NULL)
    {
        return NULL;
    }
    work->owner = parent;
    work->state = 0;
    return work;
}

// FUN_001E4BC0 NONMATCHING
s32 func_001e4bc0(RuntimeWork* work)
{
    if (work == NULL)
    {
        return 0;
    }
    if (work->state == 0)
    {
        work->state = 1;
        return 0;
    }
    return work->state == 2;
}

// FUN_001E5820 NONMATCHING
void func_001e5820(RuntimeWork* work, u32 request)
{
    if (work != NULL)
    {
        work->requestFlags = request;
        work->state = 0;
    }
}

// FUN_001E5850 NONMATCHING
void* func_001e5850(void* parent)
{
    RuntimeWork* work;

    work = RwCalloc(1, 0x58, 4);
    if (work != NULL)
    {
        work->owner = parent;
        work->state = 0;
    }
    return work;
}

// FUN_001E58D0 NONMATCHING
s32 func_001e58d0(RuntimeWork* work)
{
    if (work == NULL)
    {
        return 0;
    }
    if ((work->requestFlags & 0x40) != 0)
    {
        work->completedFlags |= 1;
        work->state = 2;
    }
    return work->state == 2;
}

// FUN_001E6000 NONMATCHING
void func_001e6000(RuntimeWork* work, u32 request)
{
    if (work != NULL)
    {
        work->requestFlags = request;
        work->state = 0;
    }
}

// FUN_001E6030 NONMATCHING
void* func_001e6030(void* parent)
{
    RuntimeWork* work;

    work = RwCalloc(1, 0x58, 4);
    if (work != NULL)
    {
        work->owner = parent;
        work->state = 0;
    }
    return work;
}

// FUN_001E60B0 NONMATCHING
s32 func_001e60b0(RuntimeWork* work)
{
    if (work == NULL)
    {
        return 0;
    }
    if ((work->requestFlags & 0x20) != 0)
    {
        work->completedFlags |= 1;
    }
    return work->completedFlags != 0;
}

// FUN_001E6A40 NONMATCHING
void func_001e6a40(RuntimeWork* work, u32 request)
{
    if (work != NULL)
    {
        work->requestFlags = request;
        work->state = 0;
    }
}

// FUN_001E6A70 NONMATCHING
void* func_001e6a70(void* parent)
{
    RuntimeWork* work;

    work = RwCalloc(1, 0x58, 4);
    if (work != NULL)
    {
        work->owner = parent;
        work->state = 0;
    }
    return work;
}

// FUN_001E6AF0 NONMATCHING
s32 func_001e6af0(RuntimeWork* work)
{
    if (work == NULL)
    {
        return 0;
    }
    if ((work->requestFlags & 0x40) != 0)
    {
        work->completedFlags |= 1;
    }
    return (s32)(work->completedFlags & 1);
}

// FUN_001E6CB0 NONMATCHING
HCdvd* func_001e6cb0(u16 majorId, u16 minorId)
{
    char path[64];

    if (K_Fldrc_GetFldPacCdvd() != NULL)
    {
        return (HCdvd*)1;
    }
    sprintf(path, D_00684410, majorId, minorId);
    if (H_Cdvd_FileExists(path) == 0)
    {
        return NULL;
    }
    return H_Cdvd_Request(path, HCDVD_FILENORMAL);
}

// FUN_001E6D50 NONMATCHING
u32 func_001e6d50(HCdvd* request, void** outFile, u16 majorId,
                  u16 minorId)
{
    char path[64];
    void* cached;
    void* memory;
    u32 size;

    if (request == NULL)
    {
        return 1;
    }
    if (K_Fldrc_GetFldPacCdvd() == NULL)
    {
        if (H_Cdvd_IsFileLoaded(request) == 0)
        {
            return 0;
        }
        size = request->fileSize;
        memory = (*DAT_00960184)(1, size, 0x40000);
        if (outFile != NULL)
        {
            *outFile = memory;
        }
        if (memory != NULL)
        {
            memcpy(memory, request->fileMemory, size);
        }
        H_Cdvd_Destroy(request);
        return 1;
    }
    sprintf(path, D_00684430, majorId, minorId);
    size = 0;
    cached = H_Cdvd_CacheFindFile(path, &size);
    if (cached != NULL)
    {
        memory = (*DAT_00960184)(1, size, 0x40000);
        if (outFile != NULL)
        {
            *outFile = memory;
        }
        if (memory != NULL)
        {
            memcpy(memory, cached, size);
        }
    }
    return 1;
}

// FUN_001E6EA0 NONMATCHING
void func_001e6ea0(RuntimeWork* work)
{
    if (work != NULL)
    {
        work->requestFlags |= 1;
        work->completedFlags = 0;
    }
}

// FUN_001E7200 NONMATCHING
void* func_001e7200(u16 majorId)
{
    RuntimeWork* request;

    request = RwCalloc(1, 0x20, 4);
    if (request == NULL)
    {
        return NULL;
    }
    request->selection = majorId;
    request->resource = H_Cdvd_Request("field event archive", 0);
    if (request->resource == NULL)
    {
        RwFree(request);
        return NULL;
    }
    return request;
}

// FUN_001E7290 NONMATCHING
s32 func_001e7290(RuntimeWork* request, u16 majorId)
{
    if (request == NULL)
    {
        return 1;
    }
    if (request->selection != majorId)
    {
        return 0;
    }
    if (H_Cdvd_IsFileLoaded(request->resource) == 0)
    {
        return 0;
    }
    H_Cdvd_Destroy(request->resource);
    request->resource = NULL;
    RwFree(request);
    return 1;
}

// FUN_001E7410 NONMATCHING
void func_001e7410(RuntimeWork** request)
{
    if (request != NULL && *request != NULL)
    {
        if ((*request)->resource != NULL)
        {
            H_Cdvd_Destroy((*request)->resource);
        }
        RwFree(*request);
        *request = NULL;
    }
}

// FUN_001E7470
HCdvd* func_001e7470(u16 majorId, u16 minorId)
{
    char path[128];

    sprintf(path, D_006844B0, majorId, minorId);
    if (H_Cdvd_FileExists(path) == 0)
    {
        return NULL;
    }
    return H_Cdvd_Request(path, HCDVD_FILENORMAL);
}

// FUN_001E74E0
s32 func_001e74e0(void* request)
{
    if (request == NULL)
    {
        return 1;
    }
    return H_Cdvd_IsFileLoaded(request) != 0;
}

// FUN_001E7520 NONMATCHING
void func_001e7520(void* request)
{
    if (request != NULL)
    {
        H_Cdvd_Destroy(request);
    }
}

// FUN_001E7540 NONMATCHING
void* func_001e7540(void* file, const char* name, void* callback)
{
    RuntimeWork* work;

    work = RwCalloc(1, 0x30, 4);
    if (work != NULL)
    {
        work->owner = file;
        work->resource = (void*)name;
        work->renderData = callback;
    }
    return work;
}

// FUN_001E75B0 NONMATCHING
void* func_001e75b0(void* cameraBackup)
{
    RuntimeWork* backup;

    backup = RwCalloc(1, 0x140, 4);
    if (backup != NULL)
    {
        backup->resource = cameraBackup;
        backup->flags = 1;
    }
    return backup;
}

// FUN_001E7720 NONMATCHING
void func_001e7720(void)
{
    RuntimeWork* cameraState;

    cameraState = RwCalloc(1, 0x140, 4);
    if (cameraState != NULL)
    {
        cameraState->resource = kwlnGetMainCamera();
        cameraState->slots[0]++;
        RwFree(cameraState);
    }
}

// FUN_001E78C0 NONMATCHING
void* func_001e78c0(s32 width, s32 height)
{
    RuntimeWork* work;
    u32 i;

    work = RwCalloc(1, sizeof(RuntimeWork), 4);
    if (work == NULL)
    {
        return NULL;
    }
    work->count = (u32)width;
    work->currentIndex = (u32)height;
    for (i = 0; i < 12; i++)
    {
        work->slots[i] = i;
    }
    return work;
}

// FUN_001E7A60 NONMATCHING
void func_001e7a60(void* renderData)
{
    RuntimeWork* work;

    work = (RuntimeWork*)renderData;
    if (work != NULL)
    {
        work->flags &= ~3;
        RwFree(work);
    }
}

// FUN_001E7AA0 NONMATCHING
void func_001e7aa0(RuntimeWork* work, s32 index, void* data)
{
    u32 offset;

    if (work == NULL)
    {
        return;
    }
    offset = (u32)index * 4;
    work->slots[offset] = (u32)data;
    work->slots[offset + 1] = (u32)data;
}

// FUN_001E7B10 NONMATCHING
void func_001e7b10(RuntimeVec3* vertices, f32 scale)
{
    u32 i;

    if (vertices == NULL)
    {
        return;
    }
    for (i = 0; i < 4; i++)
    {
        vertices[i].x *= scale;
        vertices[i].y *= scale;
        vertices[i].z = scale;
    }
}

// FUN_001E7C20 NONMATCHING
f32 func_001e7c20(s32 scale)
{
    f32 dimension;

    dimension = (f32)scale;
    if (dimension < 0.0f)
    {
        dimension = -dimension;
    }
    return dimension / 65535.0f;
}

// FUN_001E7CE0 NONMATCHING
RuntimeWork* func_001e7ce0(s32 columns, s32 rows)
{
    RuntimeWork* work;

    work = RwCalloc(1, sizeof(RuntimeWork), 4);
    if (work != NULL)
    {
        work->count = (u32)columns;
        work->currentIndex = (u32)rows;
        work->flags = 3;
    }
    return work;
}

// FUN_001E7DE0 NONMATCHING
void func_001e7de0(RuntimeWork* work)
{
    if (work != NULL)
    {
        RwFree(work->positions);
        RwFree(work);
    }
}

// FUN_001E7E30 NONMATCHING
f32 func_001e7e30(const RuntimeWork* work, u32 index)
{
    u32 next;
    RuntimeVec3 delta;

    if (work == NULL || work->positions == NULL || work->count == 0)
    {
        return 0.0f;
    }
    next = Runtime_RingIndex(work, index + 1);
    delta.x = work->positions[next].x - work->positions[index].x;
    delta.y = work->positions[next].y - work->positions[index].y;
    delta.z = work->positions[next].z - work->positions[index].z;
    return delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
}

// FUN_001E7F90 NONMATCHING
void func_001e7f90(const RuntimeWork* work, u32* section, f32* fraction, f32 distance)
{
    u32 i;
    f32 total;

    total = 0.0f;
    if (work == NULL || work->count < 2)
    {
        *section = 0;
        *fraction = 0.0f;
        return;
    }
    for (i = 0; i + 1 < work->count; i++)
    {
        total += func_001e7e30(work, i);
        if (distance <= total)
        {
            *section = i;
            *fraction = distance / total;
            return;
        }
    }
    *section = work->count - 1;
    *fraction = 1.0f;
}

// FUN_001E8330 NONMATCHING
u32 func_001e8330(const RuntimeWork* work, u32 index)
{
    return Runtime_RingIndex(work, index);
}

// FUN_001E8360 NONMATCHING
void* func_001e8360(RuntimeWork* work, u32 index)
{
    if (work == NULL || work->resource == NULL)
    {
        return NULL;
    }
    return ((void**)work->resource)[Runtime_RingIndex(work, index)];
}

// FUN_001E88F0 NONMATCHING
void func_001e88f0(RuntimeWork* work, u32 value)
{
    if (work != NULL)
    {
        work->currentIndex = value;
        work->flags |= 1;
    }
}

// FUN_001E8E80 NONMATCHING
s32 func_001e8e80(RuntimeWork* work)
{
    if (work == NULL)
    {
        return 0;
    }
    return work->currentIndex < work->count;
}

// FUN_001E9920 NONMATCHING
RuntimeListNode* func_001e9920(RuntimeWork* work)
{
    RuntimeListNode* node;

    node = RwCalloc(1, sizeof(RuntimeListNode), 4);
    if (node != NULL)
    {
        node->work = work;
        node->flags = 1;
    }
    return node;
}

// FUN_001E9A90 NONMATCHING
void func_001e9a90(void* workData)
{
    RuntimeWork* work;

    work = (RuntimeWork*)workData;
    if (work != NULL)
    {
        work->flags = 0;
        work->resource = NULL;
        work->renderData = NULL;
    }
}

// FUN_001E9AF0 NONMATCHING
void func_001e9af0(RuntimeListNode* node, RuntimeListNode** head, RuntimeListNode** tail)
{
    if (node == NULL)
    {
        return;
    }
    Runtime_Unlink(head, tail, node);
    if (node->work != NULL)
    {
        func_001e9a90(node->work);
        RwFree(node->work);
    }
    RwFree(node);
}

// FUN_001EB920 NONMATCHING
void func_001eb920(RuntimeWork* work, u32 value)
{
    if (work != NULL)
    {
        work->flags = value;
        work->state = 0;
    }
}

// FUN_001EBA50 NONMATCHING
void func_001eba50(RuntimeWork* work)
{
    if (work != NULL)
    {
        work->completedFlags = 0;
        work->state = 0;
    }
}

// FUN_001EBA80 NONMATCHING
void func_001eba80(RuntimeWork* work, u32* result)
{
    if (result != NULL)
    {
        *result = work != NULL ? work->completedFlags : 0;
    }
}

// FUN_001EBD80 NONMATCHING
s32 func_001ebd80(RuntimeWork* work)
{
    if (work == NULL)
    {
        return 0;
    }
    return (work->flags & 1) != 0;
}

// FUN_001ECD90 NONMATCHING
void func_001ecd90(RuntimeWork* work)
{
    if (work != NULL)
    {
        work->flags |= 2;
    }
}

// FUN_001ECEC0 NONMATCHING
void func_001ecec0(RuntimeWork* work)
{
    if (work != NULL)
    {
        work->flags &= ~2;
    }
}

// FUN_001ED080 NONMATCHING
void func_001ed080(RuntimeWork* work, u32 flags)
{
    if (work != NULL)
    {
        work->requestFlags |= flags;
    }
}

// FUN_001ED0B0 NONMATCHING
void func_001ed0b0(RuntimeWork* work, u32 flags)
{
    if (work != NULL)
    {
        work->requestFlags &= ~flags;
    }
}

// FUN_001ED0D0 NONMATCHING
u32 func_001ed0d0(const RuntimeWork* work)
{
    return work != NULL ? work->requestFlags : 0;
}

// FUN_001ED0F0 NONMATCHING
s32 func_001ed0f0(const RuntimeWork* work, u32 flags)
{
    return work != NULL && (work->requestFlags & flags) == flags;
}

// FUN_001ED8A0 NONMATCHING
void func_001ed8a0(RuntimeWork* work)
{
    if (work != NULL)
    {
        work->completedFlags |= work->requestFlags;
    }
}

// FUN_001ED9E0 NONMATCHING
s32 func_001ed9e0(void* workData)
{
    RuntimeWork* work;

    work = (RuntimeWork*)workData;
    return work != NULL && (work->completedFlags & 1) != 0;
}

// FUN_001EDA00 NONMATCHING
void func_001eda00(RuntimeWork* work)
{
    if (work != NULL)
    {
        work->completedFlags = 0;
    }
}

// FUN_001EDA90 NONMATCHING
void func_001eda90(RuntimeWork* work, u32 value)
{
    if (work != NULL)
    {
        work->slots[0] = value;
    }
}

// FUN_001EDBE0 NONMATCHING
void func_001edbe0(void* workData)
{
    RuntimeWork* work;

    work = (RuntimeWork*)workData;
    if (work != NULL)
    {
        work->flags &= ~0x0a;
        work->completedFlags |= 1;
    }
}

// FUN_001EDED0 NONMATCHING
void func_001eded0(RuntimeWork* work)
{
    if (work != NULL)
    {
        work->flags |= 4;
    }
}

// FUN_001EDF10 NONMATCHING
void func_001edf10(void* workData)
{
    RuntimeWork* work;

    work = (RuntimeWork*)workData;
    if (work != NULL)
    {
        work->flags &= ~4;
        work->completedFlags |= 2;
    }
}

// FUN_001EE1D0 NONMATCHING
RuntimeWork* func_001ee1d0(RuntimeWork* owner, u32 count)
{
    RuntimeWork* work;

    work = RwCalloc(1, sizeof(RuntimeWork), 4);
    if (work != NULL)
    {
        work->owner = owner;
        work->count = count;
    }
    return work;
}

// FUN_001EE220 NONMATCHING
void func_001ee220(RuntimeWork* work)
{
    if (work != NULL)
    {
        Runtime_Clear(work, 0, 32);
    }
}

// FUN_001EE230 NONMATCHING
void func_001ee230(RuntimeWork* work, u32 index, u32 value)
{
    if (work != NULL && index < 1024)
    {
        work->slots[index] = value;
    }
}

// FUN_001EE2E0 NONMATCHING
u32 func_001ee2e0(const RuntimeWork* work, u32 index)
{
    if (work == NULL || index >= 1024)
    {
        return 0;
    }
    return work->slots[index];
}

// FUN_001EEB90 NONMATCHING
void func_001eeb90(RuntimeWork* work)
{
    if (work != NULL)
    {
        work->state = 0;
        work->phase = 0;
        work->currentIndex = 0;
    }
}

// FUN_001EEE40 NONMATCHING
void func_001eee40(RuntimeWork* work)
{
    u32 i;

    if (work == NULL)
    {
        return;
    }
    for (i = 0; i < work->count; i++)
    {
        work->slots[i] = i;
        func_001eba50((RuntimeWork*)((void**)work->resource)[i]);
    }
    work->flags |= 1;
}

// FUN_001EEF20 NONMATCHING
void func_001eef20(void)
{
    RuntimeWork* work;

    work = RwCalloc(1, sizeof(RuntimeWork), 4);
    if (work != NULL)
    {
        work->state = 0;
        work->count = 100;
    }
}

// FUN_001EEFC0 NONMATCHING
void func_001eefc0(RuntimeListNode** head, RuntimeListNode** tail, RuntimeListNode* node)
{
    if (*tail == NULL)
    {
        node->previous = NULL;
        node->next = NULL;
        *head = node;
        *tail = node;
        return;
    }
    node->previous = *tail;
    node->next = NULL;
    (*tail)->next = node;
    *tail = node;
}

// FUN_001EF000 NONMATCHING
s32 func_001ef000(RuntimeListNode* head, const RuntimeListNode* node)
{
    RuntimeListNode* current;

    for (current = head; current != NULL; current = current->next)
    {
        if (current == node)
        {
            return (current->flags & 8) == 0;
        }
    }
    return 0;
}

// FUN_001EF060 NONMATCHING
s32 func_001ef060(RuntimeListNode** head, RuntimeListNode** tail)
{
    RuntimeListNode* node;

    for (node = *head; node != NULL; node = node->next)
    {
        if ((node->flags & 0x0a) != 0)
        {
            func_001edbe0(node->work);
        }
    }
    for (node = *head; node != NULL; node = node->next)
    {
        if (node->work != NULL && func_001ed9e0(node->work) != 0)
        {
            func_001e9af0(node, head, tail);
        }
    }
    return 0;
}

// FUN_001EF340 NONMATCHING
void func_001ef340(void* owner)
{
    RuntimeListNode* node;
    RuntimeListNode* next;

    node = NULL;
    next = node;
    while (next != NULL)
    {
        node = next;
        next = next->next;
        if (node->work != NULL && node->work->owner == owner)
        {
            func_001e9a90(node->work);
            RwFree(node->work);
            RwFree(node);
        }
    }
}

// FUN_001EF500 NONMATCHING
RuntimeTask* func_001ef500(RuntimeTask* parent)
{
    RuntimeWork* work;
    RuntimeTask* task;

    work = RwCalloc(1, sizeof(RuntimeWork), 4);
    if (work == NULL)
    {
        return NULL;
    }
    work->count = 100;
    task = kwlnTaskCreateWithAutoPriority(parent, 10, "field root", func_001ef7f0, func_001f07a0, work);
    if (task == NULL)
    {
        RwFree(work);
        return NULL;
    }
    return task;
}

// FUN_001EF7F0 NONMATCHING
s32 func_001ef7f0(RuntimeTask* task)
{
    RuntimeWork* work;

    work = task->workData;
    func_00234070();
    func_00235010();
    func_00263170();
    func_00272810();
    func_00275bc0();
    func_00276930();
    func_002770f0();
    if ((work->flags & 0x40) != 0)
    {
        work->flags &= ~0x40;
        return 0;
    }
    if ((work->requestFlags & 7) != 0)
    {
        work->completedFlags |= work->requestFlags & 7;
        work->requestFlags &= ~7;
    }
    switch (work->state)
    {
        case 0:
            if ((work->flags & 0x2000) == 0)
            {
                H_Snd_PlayBgm((work->flags & 2) != 0 ? 78 : 60, 1);
                work->state = 1;
            }
            break;

        case 1:
            if (func_00236340() == 0)
            {
                work->flags &= ~0x2000;
                work->state = 2;
            }
            break;

        case 2:
            func_003c7650(1);
            if ((work->flags & 0x2c) != 0)
            {
                work->phase = 4;
            }
            else
            {
                work->phase = 6;
            }
            work->state = 3;
            break;

        case 3:
            if (func_00236340() == 0)
            {
                if ((work->flags & 0x200000) != 0)
                {
                    H_Fade_FadeOut();
                    H_Fade_SetType(5);
                    H_Fade_SetDuration(1);
                    func_002362e0();
                    work->flags &= ~0x200000;
                }
                work->state = 4;
            }
            break;

        case 4:
            if (H_Fade_IsFadeOutDone() != 0)
            {
                func_003c77a0();
                work->state = 5;
            }
            break;

        case 5:
            if ((work->flags & 0x200000) != 0)
            {
                func_002362e0();
                work->flags &= ~0x200000;
            }
            else
            {
                H_Fade_SetType(2);
                H_Fade_FadeIn();
            }
            work->state = 6;
            break;

        case 6:
            if (H_Fade_IsFadeOutDone() != 0)
            {
                work->state = 7;
            }
            break;

        case 7:
            func_003c7990(1);
            if (func_003c7850() == 0)
            {
                func_003c7650(1);
                work->state = 0;
            }
            break;

        default:
            work->state = 0;
            break;
    }
    return 0;
}

// FUN_001F07A0 NONMATCHING
void func_001f07a0(RuntimeTask* task)
{
    RuntimeWork* work;

    work = task->workData;
    if ((work->flags & 1) != 0)
    {
        work->flags &= ~1;
        work->requestFlags = 0;
        work->completedFlags = 0;
    }
    if (work->childTask != NULL)
    {
        kwlnTaskDestroyWithHierarchy(work->childTask);
    }
    RwFree(work);
}
