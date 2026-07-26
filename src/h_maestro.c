#include "h_maestro.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "rw/rt2danim.h"
#include "h_cdvd.h"
#include "rw/rwcore.h"
#include "temporary.h"

extern u32 FUN_004c2090(void* param_1);
extern f32 FUN_004b1a70(u32 param_1);
extern f32 FUN_004b1a60(u32 param_1);
extern void FUN_004b1870(u32 param_1, u32 param_2, u32 param_3);
extern f32 fGpffff80e4;
extern f32 gPI;
extern f32 gUnk_007cadd0;
extern RwCamera* kwlnGetMainCamera();
extern void H_Maestro_00111c50(KwlnTask* hmaestroTask);
extern void* func_004aa390(f32 param_1);
extern void* func_004aa3d0(f32 param_1);
extern void* func_004a9f20(f32 param_1, f32 param_2, f32 param_3, f32 param_4);
extern void* func_004aa410(RwCamera* camera);
extern void func_004a9d80(RwV2d* param_1, RwV2d* param_2, RwV2d* param_3);
extern void* func_004a9bf0();
extern void* func_004aaa60();
extern void* func_004aad50();
extern void* func_004aef60(Rt2dObject* scene);
extern void* func_004ae060(Rt2dObject* scene);
extern void* func_004ae070(Rt2dObject* scene, f32 param_2, f32 param_3);
extern void* func_004ae0c0(Rt2dObject* scene, f32 param_2, f32 param_3);
extern void* func_004ae110(Rt2dObject* scene, RwRGBAReal* color);
extern void* func_004b45b0(void* param_1, RwStream* stream);
extern void* func_004b4c70(Rt2dMaestro* maestro);
extern void* func_004b3cc0(Rt2dMaestro* maestro);
extern void* func_004b5000(Rt2dMaestro* maestro, f32 time);
extern void* func_004b5330(Rt2dMaestro* maestro);
extern void* func_004b4d60(Rt2dMaestro* maestro);
extern void* func_004c1600(RwStream* stream, u32 param_2, u32 param_3, u32 param_4);
extern RwStream* func_004c58a0(u32 param_1, u32 param_2, const char* path);
extern void* func_004c5780(RwStream* stream, void* param_2);
extern void* func_004c9d70(RwCamera* camera, f32 nearPlane);
extern const char D_005D6B80[];
extern const char D_005D6BA0[];
extern RwMatrix* func_004c38c0(void);
extern void func_004c3880(RwMatrix* matrix);
extern RwMatrix* func_004c2fc0(RwReal oneMinusCosine, RwReal sine, RwMatrix* matrix, const RwV3d* axis, RwOpCombineType combineOp);
extern RwV3d* func_004c6c20(RwV3d* pointsOut, const RwV3d* pointsIn, RwUInt32 pointCount, const RwMatrix* matrix);
extern f32 sinf(f32 angle);
extern f32 cosf(f32 angle);

typedef struct MaestroResourceWork
{
    s32 state;
    s32 resourceIndex;
    void* resources[40];
    void* parsedResources[40];
    void* effectResources[40];
    s32 recordIndices[40];
    u8 reserved0[0xA0];
    void* runtimeResources[40];
    u8 reserved1[0x10];
    f32 x;
    f32 y;
    u8 reserved2[8];
    s32 completedRecords;
    u8 reserved3[4];
    s16 coordinates0[40];
    s16 coordinates1[40];
    s16 coordinates2[40];
    u32 resourceCount;
    u32 renderFlags;
    u32 cancelRequested;
} MaestroResourceWork;

typedef struct MaestroStreamWork
{
    s32 state;
    s32 resourceIndex;
    void* resources[40];
    s16 dimensions[4];
    KwlnTask* resourceTask;
    s32 frameIndex;
    s32 recordCount;
    s32 complete;
    s32 stopAtFrame;
    void* stream;
    HCdvd* cdvd;
    u8 archiveHeader[0x2A];
    u8* records;
    char path[256];
    char basePath[256];
    f32 x;
    f32 y;
    u32 renderFlags;
    u32 createCustomPriorityTask;
    u32 resourceTaskPriority;
    u32 useCdvd;
} MaestroStreamWork;

typedef struct MaestroBlobNode
{
    s16 state;
    char path[0x102];
    void* resources[32];
    void* output;
    HCdvd* cdvd;
    u8* source;
    u32 sourceOffset;
    s16 resourceIndex;
    s16 outputCount;
    u8 header[0x20];
    struct MaestroBlobNode* next;
    struct MaestroBlobNode* prev;
} MaestroBlobNode;

typedef struct MaestroRenderNode
{
    struct MaestroRenderNode* next; // 0x00
    void* unused4;                  // 0x04
    MaestroBlobNode* blob;          // 0x08
    s32 outputIndex;                // 0x0c
    f32 x;                          // 0x10
    f32 y;                          // 0x14
    u8 alphaCutoff;                 // 0x18
    u8 alphaLoss;                   // 0x19
    u8 reserved1A[2];               // 0x1a
    s16 extraWidth;                 // 0x1c
    s16 extraHeight;                // 0x1e
    f32 angle;                      // 0x20
    s16 pivotX;                     // 0x24
    s16 pivotY;                     // 0x26
    u16 xScale;                     // 0x28
    u16 yScale;                     // 0x2a
    f32 depth;                      // 0x2c
    u8 red;                         // 0x30
    u8 green;                       // 0x31
    u8 blue;                        // 0x32
} MaestroRenderNode;

typedef struct MaestroOutputRecord
{
    u8 reserved0[0x14];
    s32 resourceIndex;              // 0x14
    u32 flags;                      // 0x18
    u8 reserved1[0x10];
    u32 renderStateFlags;           // 0x2c
    s32 topExtension;               // 0x34
    s32 bottomExtension;            // 0x38
    s32 leftExtension;              // 0x3c
    s32 rightExtension;             // 0x40
    s32 x;                          // 0x44
    s32 y;                          // 0x48
    u8 reserved2[12];
    s32 left;                       // 0x54
    s32 top;                        // 0x58
    s32 right;                      // 0x5c
    s32 bottom;                     // 0x60
    u32 colors[4];                  // 0x64
    s16 overrideX;                  // 0x74
    s16 overrideY;                  // 0x76
} MaestroOutputRecord;

extern u32 D_00960184[];
#pragma alias D_00960184_abs D_00960184
extern u8 D_00960184_abs[];
extern u32 jtbl_0096017C[];
extern void (*D_00960090)(u32 state, u32 value);
 #pragma alias D_00960090_abs D_00960090
 extern u8 D_00960090_abs[];
extern void (*D_009600A0)(RwPrimitiveType primitiveType, RwIm2DVertex* vertices, s32 vertexCount);
extern f32 D_00960088;
extern RwV3d D_005D6C28;
extern MaestroRenderNode* DAT_00833a4c;
extern MaestroBlobNode* DAT_00833a50;
extern int* DAT_007cdf3c;
extern const char* D_005D66E0[];
#define MAESTRO_ALLOC(count, size, flags) (*(void* (**)(u32, u32, u32))D_00960184_abs)(count, size, flags)
#define MAESTRO_FREE(memory) (*(void (**)(void*))jtbl_0096017C)(memory)
extern const s8 D_005D53E0[];
extern const char D_005D5880[];
extern const char D_005D5898[];
extern const char D_005D58A8[];
extern const char D_005D58C0[];
extern const char D_005D6A68[];
extern const char D_005D6A80[];
extern const char D_005D6AA0[];
extern const char D_005D6AB8[];
extern const char D_005D6AD0[];
extern const char D_005D6AF0[];
extern const char D_005D6B10[];
extern const char D_005D6B30[];
extern const char D_005D6B50[];
extern const char D_005D6B60[];
extern const char D_005D6BC0[];
extern const char D_005D6BD0[];
extern const char D_005D6BF0[];
extern const char D_005D6C10[];
extern const char D_005D6CD0[];
extern const char D_005D6E10[];
extern void* func_0010f6c0(KwlnTask* task);
extern const char* func_001022e0(HCdvd* cdvd, s32 entryIndex);
extern void* func_0010c1a0(void* param_1, const char* path, ...);
extern void func_00102720(const char* path, const void* archive);
extern void* func_0010c3a0(void* stream, u32* finished, u32 param_3);
extern void func_0010a4e0(u32 param_1, u32 param_2, s8 param_3, s8 param_4);
extern void* func_0010e880(const void* entry);
extern void func_00133d30(void* stream, HCdvd* cdvd);
extern u32 func_004a5540(void* resource);
extern void func_004a6200(void* resource, const f32* uv0, const f32* uv1, const f32* uv2, const f32* uv3);
extern void func_004ac120(void* resource, f32* output);
extern u32 func_004ac390(void* resource);
extern void func_004cde90(void* resource);
extern void func_004d0f00(void* resource);
extern void func_0010ec50(KwlnTask* task);

static s16 Maestro_Dimension(u64 dimensions, s32 index)
{
    return ((s16*)&dimensions)[index];
}


// FUN_001102E0
void func_001102e0(KwlnTask* task)
{
    MaestroResourceWork* work;
    s32 i;
    void** resourceSlot;

    work = (MaestroResourceWork*)task->workData;

    for (i = 0; i < (s32)work->resourceCount; i++)
    {
        resourceSlot = &work->parsedResources[i];
        if (*resourceSlot != NULL)
        {
            if (func_004ac390(*resourceSlot) == 0)
            {
                printf(D_005D5880);
            }
            *resourceSlot = NULL;
        }
    }

    for (i = 0; i < (s32)work->resourceCount; i++)
    {
        resourceSlot = &work->effectResources[i];
        if (*resourceSlot != NULL)
        {
            if (func_004a5540(*resourceSlot) == 0)
            {
                printf(D_005D5880);
            }
            *resourceSlot = NULL;
        }
    }

    MAESTRO_FREE(work);
}

// FUN_001103E0
KwlnTask* func_001103e0(KwlnTask* parent, u32 priority, u32 param_3, u32 resourceCount)
{
    MaestroResourceWork* work;
    KwlnTask* task;

    work = (MaestroResourceWork*)MAESTRO_ALLOC(1, sizeof(MaestroResourceWork), 0x40000);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreate(parent, D_005D5898, priority, func_0010f6c0, func_001102e0, work);
    if (task == NULL)
    {
        return NULL;
    }

    work->resourceIndex = param_3;
    work->resourceCount = resourceCount;
    return task;
}

// FUN_001104B0
u32 func_001104b0(KwlnTask* task)
{
    return ((MaestroResourceWork*)task->workData)->state >= 2;
}

// FUN_001104D0
u32 func_001104d0(KwlnTask* task)
{
    MaestroResourceWork* work;

    work = (MaestroResourceWork*)task->workData;
    if (work->state == 2)
    {
        work->state = 3;
        return true;
    }

    return false;
}

// FUN_00110510 NONMATCHING
u32 func_00110510(KwlnTask* task)
{
    s32 i;
    MaestroResourceWork* work;

    work = (MaestroResourceWork*)task->workData;
    if (work->state == 3)
    {
        for (i = 0; i < (s32)work->resourceCount; i++)
        {
            s8 recordType;

            for (;;)
            {
                recordType = ((s8*)work->resources[i])[work->recordIndices[i] * 18 + 1];
                if (recordType != -1)
                {
                    if (recordType == -2)
                    {
                        return false;
                    }
                    work->recordIndices[i]++;
                    continue;
                }
                work->recordIndices[i]++;
                work->completedRecords++;
                break;
            }
        }
    }

    return true;
}

// FUN_001105D0
void func_001105d0(KwlnTask* task, s32 index, void* resource)
{
    MaestroResourceWork* work;
    void** resourceSlot;

    work = (MaestroResourceWork*)task->workData;
    if (index < 40)
    {
        index *= sizeof(void*);
        work = (MaestroResourceWork*)(index + (int)work);
        resourceSlot = work->runtimeResources;
        *resourceSlot = resource;
        if (resource != NULL)
        {
            u32* flags;

            resource = *resourceSlot;
            flags = (u32*)((u8*)resource + 0x50);
            *flags = (*flags & 0xFFFFFF00) | 2;
        }
    }
}

// FUN_00110620
void func_00110620(KwlnTask* task, s16 index, s16 param_3, s16 param_4, s16 param_5)
{
    MaestroResourceWork* work;

    work = (MaestroResourceWork*)task->workData;
    work->coordinates0[index] = param_3;
    work->coordinates1[index] = param_4;
    work->coordinates2[index] = param_5;
}

// FUN_00110650 NONMATCHING
void func_00110650(void* param_1, s32 sourceIndex, s32 destinationIndex)
{
    MaestroResourceWork* work;
    struct
    {
        u8 pad[0x10];
        f32 destination[4];
        f32 source[4];
        f32 uv[8];
    } locals;
    void* texture;
    s32* dimensions;

    work = (MaestroResourceWork*)param_1;
    func_004ac120(work->parsedResources[sourceIndex], locals.source);
    func_004ac120(work->parsedResources[destinationIndex], locals.destination);

    texture = *(void**)((u8*)work->effectResources[destinationIndex] + 0x68);
    if (texture == NULL)
    {
        return;
    }

    dimensions = *(s32**)texture;
    locals.uv[0] = (locals.source[0] - locals.destination[0]) * (f32)dimensions[3] / locals.source[2] / locals.source[2];
    locals.uv[1] = ((448.0f - (locals.destination[1] + locals.destination[3])) - (448.0f - (locals.source[1] + locals.source[3]))) * (f32)dimensions[4] / locals.source[3] / locals.source[3];
    locals.uv[2] = ((locals.source[0] + locals.source[2]) - locals.destination[0]) * (f32)dimensions[3] / locals.source[2] / locals.source[2] + 1.0f;
    locals.uv[3] = locals.uv[1] + 1.0f;
    locals.uv[4] = locals.uv[2];
    locals.uv[5] = ((448.0f - locals.destination[1]) - (448.0f - (locals.source[1] + locals.source[3]))) * (f32)dimensions[4] / locals.source[3] / locals.source[3];
    locals.uv[6] = locals.uv[0];
    locals.uv[7] = locals.uv[5];
    func_004a6200(work->effectResources[destinationIndex], &locals.uv[0], &locals.uv[2], &locals.uv[4], &locals.uv[6]);
}

// FUN_001107D0 NONMATCHING
void* func_001107d0(KwlnTask* task)
{
    MaestroStreamWork* work;

    work = (MaestroStreamWork*)task->workData;
    switch (work->state)
    {
        case 0:
            if (work->useCdvd != 0)
            {
                work->cdvd = H_Cdvd_Request(work->path, HCDVD_FILEARCHIVE);
            }
            work->state = 1;
            break;

        case 1:
            if (work->useCdvd != 0 && !H_Cdvd_IsFileLoaded(work->cdvd))
            {
                break;
            }
            work->resourceIndex = 0;
            work->state = 2;
            break;

        case 2:
        {
            const char* externalPath;
            s32 i;
            s8 recordType;

            externalPath = func_001022e0(work->cdvd, work->resourceIndex + 1);
            if (externalPath != NULL)
            {
                char fullPath[256];

                strcpy(fullPath, work->basePath);
                strcat(fullPath, (char*)externalPath);
                printf(D_005D58A8, fullPath);
                work->stream = func_0010c1a0(NULL, fullPath, NULL, NULL, NULL, NULL, NULL, NULL,
                                             NULL, NULL, D_005D58A8, 0x506);
                work->state = 4;
                break;
            }

            work->records = (u8*)H_Cdvd_ArchiveGetFile(work->cdvd, 0, NULL);
            memcpy(work->archiveHeader, work->records, sizeof(work->archiveHeader));
            work->records += sizeof(work->archiveHeader);
            work->recordCount = 0;
            for (i = 0; i < 1000; i++)
            {
                recordType = ((s8*)work->records)[i * 18 + 1];
                if (recordType == -2)
                {
                    work->recordCount--;
                }
                else if (recordType == -1)
                {
                    work->recordCount++;
                }
            }
            work->state = 5;
            break;
        }
        case 3:
            break;

        case 4:
        {
            u32 finished;
            void* resource;

            finished = false;
            resource = func_0010c3a0(work->stream, &finished, 0);
            work->resources[work->resourceIndex] = resource;
            if (finished == 0)
            {
                break;
            }
            work->stream = NULL;
            *(u32*)((u8*)resource + 0x50) = (*(u32*)((u8*)resource + 0x50) & 0xFFFF00FF) | 0x3300;
            work->resourceIndex++;
            work->state = 2;
            break;
        }

        case 5:
        {
            MaestroResourceWork* resourceWork;
            KwlnTask* resourceTask;
            s32 i;
            s32 destinationIndex;

            if (work->createCustomPriorityTask != 0)
            {
                resourceWork = (MaestroResourceWork*)MAESTRO_ALLOC(1, sizeof(MaestroResourceWork), 0x40000);
                resourceTask = NULL;
                if (resourceWork != NULL)
                {
                    resourceTask = kwlnTaskCreate(task, D_005D5898, work->resourceTaskPriority,
                                                  func_0010f6c0, func_001102e0, resourceWork);
                    if (resourceTask != NULL)
                    {
                        resourceWork->resourceIndex = (u32)work->records;
                        resourceWork->resourceCount = (u32)work->recordCount;
                    }
                }
                work->resourceTask = resourceTask;
            }
            else
            {
                resourceWork = (MaestroResourceWork*)MAESTRO_ALLOC(1, sizeof(MaestroResourceWork), 0x40000);
                resourceTask = NULL;
                if (resourceWork != NULL)
                {
                    resourceTask = kwlnTaskCreate(task, D_005D5898, 0x14A6,
                                                  func_0010f6c0, func_001102e0, resourceWork);
                    if (resourceTask != NULL)
                    {
                        resourceWork->resourceIndex = (u32)work->records;
                        resourceWork->resourceCount = (u32)work->recordCount;
                    }
                }
                work->resourceTask = resourceTask;
            }
            if (work->resourceTask != NULL)
            {
                resourceWork = (MaestroResourceWork*)work->resourceTask->workData;
                *(u32*)((u8*)resourceWork + 0x4E4) = work->renderFlags;
                *(f32*)((u8*)resourceWork + 0x3D8) = work->x;
                *(f32*)((u8*)resourceWork + 0x3DC) = work->y;
                *(void**)((u8*)resourceWork + 0x328) = work->resources[0];
                if (work->resources[0] != NULL)
                {
                    *(u32*)((u8*)work->resources[0] + 0x50) =
                        (*(u32*)((u8*)work->resources[0] + 0x50) & 0xFFFFFF00) | 2;
                }
                *(void**)((u8*)resourceWork + 0x32C) = work->resources[1];
                if (work->resources[1] != NULL)
                {
                    *(u32*)((u8*)work->resources[1] + 0x50) =
                        (*(u32*)((u8*)work->resources[1] + 0x50) & 0xFFFFFF00) | 2;
                }
                for (i = 0; i < 3; i++)
                {
                    destinationIndex = i == 2 ? 1 : (i == 0 ? 3 : 4);
                    *(s16*)((u8*)resourceWork + 0x3E8 + destinationIndex * 2) =
                        *(s16*)(work->archiveHeader + 0xA + i * 2);
                    *(s16*)((u8*)resourceWork + 0x438 + destinationIndex * 2) =
                        *(s16*)(work->archiveHeader + 0x12 + i * 2);
                    *(s16*)((u8*)resourceWork + 0x488 + destinationIndex * 2) =
                        *(s16*)(work->archiveHeader + 0x1A + i * 2);
                }
            }
            work->state = 7;
            break;
        }
        case 6:
            break;
        case 7:
        {
            MaestroResourceWork* resourceWork;
            s32 i;

            resourceWork = (MaestroResourceWork*)work->resourceTask->workData;
            if (resourceWork->state < 2)
            {
                break;
            }
            for (i = 0; i < 0x100; i++)
            {
                const s8* action;

                action = &D_005D53E0[i * 6];
                if (action[0] == 0)
                {
                    break;
                }
                if (work->dimensions[0] == action[0] && work->dimensions[1] == action[1] && work->dimensions[2] == action[2] && work->dimensions[3] == action[3])
                {
                    func_0010a4e0(0, 1, action[4], action[5]);
                }
            }
            if (resourceWork->state == 2)
            {
                resourceWork->state = 3;
            }
            resourceWork->x = work->x;
            resourceWork->y = work->y;
            work->state = 8;
            break;
        }

        case 8:
        {
            s16 stopFrame;

            ((MaestroResourceWork*)work->resourceTask->workData)->x = work->x;
            ((MaestroResourceWork*)work->resourceTask->workData)->y = work->y;
            stopFrame = *(s16*)(work->archiveHeader + 6);
            if (work->stopAtFrame == 0 && stopFrame != 0 && work->frameIndex == stopFrame)
            {
                work->complete = true;
                break;
            }
            work->frameIndex++;
            func_00110510(work->resourceTask);
            if (work->frameIndex >= work->recordCount)
            {
                return KWLNTASK_STOP;
            }
            break;
        }
    }

    return KWLNTASK_CONTINUE;
}

// FUN_00110E70 MATCHING
void func_00110e70(KwlnTask* task)
{
    MaestroStreamWork* work;
    s32 i;
    u8* entry;
    void** slot;
    work = (MaestroStreamWork*)task->workData;
    if (work->stream != NULL)
    {
        if (work->useCdvd != 0)
        {
            func_00133d30(work->stream, work->cdvd);
        }
        else
        {
            func_00133d30(work->stream, NULL);
        }
        work->cdvd = NULL;
    }
    else if (work->useCdvd != 0 && work->cdvd != NULL)
    {
        H_Cdvd_Destroy(work->cdvd);
        work->cdvd = NULL;
    }

    for (i = 0; i < 40; i++)
    {
        entry = (u8*)work + i * 4;
        slot = (void**)(entry + 8);
        if (*(void**)(entry + 8) != NULL)
        {
            func_004d0f00(*(void**)(entry + 8));
            *slot = NULL;
        }
    }

    printf(D_005D58C0, work->path);
    MAESTRO_FREE(work);
}

// FUN_00110F80 NONMATCHING
KwlnTask* func_00110f80(KwlnTask* parent, u64 dimensions)
{
    MaestroStreamWork* work;
    KwlnTask* task;
    char name[256];
    s32 i;

    work = (MaestroStreamWork*)MAESTRO_ALLOC(1, sizeof(MaestroStreamWork), 0x40000);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parent, 0x106F, D_005D6A68, func_001107d0, func_00110e70, work);
    if (task == NULL)
    {
        return NULL;
    }

    for (i = 0; i < 4; i++)
    {
        work->dimensions[i] = Maestro_Dimension(dimensions, i);
    }
    sprintf(name, D_005D6A80, work->dimensions[0], work->dimensions[1], work->dimensions[2], work->dimensions[3]);
    printf(D_005D6AA0, name);
    strcpy(work->basePath, D_005D6AB8);
    work->useCdvd = true;

    for (i = 0; i < 10000 && D_005D66E0[i][0] != '\0'; i++)
    {
        if (strcmp(name, D_005D66E0[i]) == 0)
        {
            sprintf(work->path, D_005D6AD0, work->dimensions[0], work->dimensions[1], work->dimensions[2], work->dimensions[3]);
            return task;
        }
    }

    printf(D_005D6AF0);
    sprintf(work->path, D_005D6B10);
    return task;
}

// FUN_00111150 NONMATCHING
KwlnTask* func_00111150(KwlnTask* parent, u64 dimensions)
{
    MaestroStreamWork* work;
    KwlnTask* task;
    s32 i;

    work = (MaestroStreamWork*)MAESTRO_ALLOC(1, sizeof(MaestroStreamWork), 0x40000);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parent, 0x106F, D_005D6A68, func_001107d0, func_00110e70, work);
    if (task == NULL)
    {
        return NULL;
    }

    for (i = 0; i < 4; i++)
    {
        work->dimensions[i] = Maestro_Dimension(dimensions, i);
    }
    sprintf(work->path, D_005D6B30, work->dimensions[0], work->dimensions[1], work->dimensions[2], work->dimensions[3]);
    strcpy(work->basePath, D_005D6B50);
    work->useCdvd = true;
    return task;
}

// FUN_00111260
KwlnTask* func_00111260(KwlnTask* parent, u64 dimensions, void* archive)
{
    KwlnTask* task;
    MaestroStreamWork* work;
    s16 dim2;
    s16 dim0;
    s16 dim1;
    s16 dim3;

    work = (MaestroStreamWork*)MAESTRO_ALLOC(1, sizeof(MaestroStreamWork), 0x40000);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreateWithAutoPriority(parent, 0x106F, D_005D6A68, func_001107d0, func_00110e70, work);
    if (task == NULL)
    {
        return NULL;
    }

    dim0 = ((volatile s16*)&dimensions)[0];
    dim1 = ((volatile s16*)&dimensions)[1];
    dim2 = ((volatile s16*)&dimensions)[2];
    dim3 = ((volatile s16*)&dimensions)[3];
    work->dimensions[0] = dim0;
    work->dimensions[1] = dim1;
    work->dimensions[2] = dim2;
    work->dimensions[3] = dim3;
    sprintf(work->path, D_005D6B30, work->dimensions[0], work->dimensions[1], work->dimensions[2], work->dimensions[3]);
    strcpy(work->basePath, D_005D6B50);
    work->cdvd = (HCdvd*)archive;
    work->useCdvd = false;
    return task;
}

// FUN_00111380
KwlnTask* func_00111380(KwlnTask* parent, u32 priority, u64 dimensions, void* archive)
{
    KwlnTask* task;
    MaestroStreamWork* work;
    s16 dim2;
    s16 dim0;
    s16 dim1;
    s16 dim3;

    work = (MaestroStreamWork*)MAESTRO_ALLOC(1, sizeof(MaestroStreamWork), 0x40000);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreate(parent, D_005D6A68, priority, func_001107d0, func_00110e70, work);
    if (task == NULL)
    {
        return NULL;
    }

    dim0 = ((volatile s16*)&dimensions)[0];
    dim1 = ((volatile s16*)&dimensions)[1];
    dim2 = ((volatile s16*)&dimensions)[2];
    dim3 = ((volatile s16*)&dimensions)[3];
    work->dimensions[0] = dim0;
    work->dimensions[1] = dim1;
    work->dimensions[2] = dim2;
    work->dimensions[3] = dim3;
    sprintf(work->path, D_005D6B30, work->dimensions[0], work->dimensions[1], work->dimensions[2], work->dimensions[3]);
    strcpy(work->basePath, D_005D6B50);
    work->createCustomPriorityTask = true;
    work->resourceTaskPriority = priority;
    work->useCdvd = false;
    work->cdvd = (HCdvd*)archive;
    *(volatile u32*)&work->useCdvd = false;
    return task;
}

// FUN_001114B0
u32 func_001114b0(KwlnTask* task)
{
    MaestroStreamWork* work;

    work = (MaestroStreamWork*)task->workData;
    if (work->state == 5)
    {
        printf(D_005D6B60, work->path);
        return true;
    }

    return false;
}
#pragma optimization_level 1


// FUN_00111500 NONMATCHING
void func_00111500(KwlnTask* task)
{
    MaestroStreamWork* work;
    KwlnTask* taskCopy;
    s32 value;

    taskCopy = task;
    work = (MaestroStreamWork*)taskCopy->workData;
    value = 1;
    work->stopAtFrame = value;
    work->complete = 0;
}

// FUN_00111520
void func_00111520(KwlnTask* task, s16 count)
{
    *((s16*)((MaestroStreamWork*)task->workData)->archiveHeader + 3) = count;
}

// FUN_00111530
u32 func_00111530(KwlnTask* task)
{
    MaestroStreamWork* work;

    work = (MaestroStreamWork*)task->workData;
    if (work->state == 5)
    {
        work->state = 6;
        return true;
    }

    return false;
}

// FUN_00111570
void func_00111570(KwlnTask* task, u32 value)
{
    ((MaestroStreamWork*)task->workData)->renderFlags = value;
}

#pragma optimization_level 1
// FUN_00111580
void func_00111580(KwlnTask* task, u64 packedCoordinates)
{
    KwlnTask* task_p = task;
    f32 x;
    f32 y;
    MaestroStreamWork* work;
    MaestroStreamWork* work_c;

    work = (MaestroStreamWork*)task_p->workData;
    x = ((f32*)&packedCoordinates)[0];
    y = ((f32*)&packedCoordinates)[1];
    (work_c = work)->x = x;
    work->y = y;
}
#pragma optimization_level 2

// FUN_001115B0
void func_001115b0(KwlnTask* task)
{
    MaestroStreamWork* work;

    work = (MaestroStreamWork*)task->workData;
    if (work->resourceTask != NULL)
    {
        ((MaestroResourceWork*)work->resourceTask->workData)->cancelRequested = true;
    }
}

// FUN_001115E0
void func_001115e0(KwlnTask* task)
{
    MaestroStreamWork* work;

    work = (MaestroStreamWork*)task->workData;
    if (work->resourceTask != NULL)
    {
        func_0010ec50(work->resourceTask);
    }
}

// FUN_00111610 NONMATCHING
void* H_Maestro_UpdateTask(KwlnTask* hmaestroTask)
{
    HMaestro* work;
    RwCamera* camera;
    Rt2dMaestro* maestro;
    RwRGBAReal color;
    f32 savedNearPlane;
    RwV2d animOutput[3];
    f32 animEnd;
    f32 animCurrent;
    u32 anim;
    u32 finished;

    work = (HMaestro*)hmaestroTask->workData;
    camera = kwlnGetMainCamera();
    savedNearPlane = camera->nearPlane;
    RwCameraEndUpdate(camera);
    func_004c9d70(camera, 50.0f);
    RwCameraBeginUpdate(camera);
    func_004aa390(0.5f);
    camera = kwlnGetMainCamera();
    func_004aa3d0(gUnk_007cadd0 * camera->nearPlane);
    func_004a9f20(0.0f, 0.0f, 640.0f, 448.0f);
    func_004aa410(kwlnGetMainCamera());

    if (work->state == HMAESTRO_STATE_INITCDVD)
    {
        if (work->useCdvd != 0)
        {
            work->cdvd = H_Cdvd_Request(work->path, HCDVD_FILENORMAL);
        }
        work->state = HMAESTRO_STATE_INITSTREAM;
        work->deltaTime = 0.0f;
    }

    if (work->state == HMAESTRO_STATE_INITSTREAM)
    {
        if (work->useCdvd != 0 && H_Cdvd_IsFileLoaded(work->cdvd) == 0)
        {
            goto restore_continue;
        }

        work->rws = func_004c58a0(2, 1, work->path);
        if (work->rws == NULL)
        {
            printf(D_005D6B80);
            goto restore_stop;
        }
        if (func_004c1600(work->rws, 0x1B1, 0, 0) == 0)
        {
            printf(D_005D6BA0);
            goto restore_stop;
        }
        work->maestro = func_004b45b0(NULL, work->rws);
        work->state = HMAESTRO_STATE_INITSCENE;
        goto restore_continue;
    }

    if (work->state == HMAESTRO_STATE_INITSCENE)
    {
        func_004c5780(work->rws, NULL);
        work->rws = NULL;
        func_004a9d80(&animOutput[0], &animOutput[1], &animOutput[2]);
        work->scene = func_004b4d60(work->maestro);
        func_004ae070(work->scene, 1.0f, 1.0f);
        func_004ae0c0(work->scene, 0.0f, 448.0f);
        func_004aef60(work->scene);
        func_004a9bf0();
        work->state = HMAESTRO_STATE_IDLE;
        goto restore_continue;
    }

    if (work->state != HMAESTRO_STATE_DRAW)
    {
        goto restore_continue;
    }

    camera = kwlnGetMainCamera();
    func_004aa3d0(gUnk_007cadd0 * camera->nearPlane);
    func_004aa410(camera);
    maestro = work->maestro;
    anim = FUN_004c2090(*(void**)((u8*)maestro + 8));
    animEnd = FUN_004b1a70(anim + 4);
    animCurrent = FUN_004b1a60(anim + 4);
    finished = false;

    if (work->noDeltaTime != 0)
    {
        func_004b5000(maestro, 0.0f);
    }
    else if (work->shouldLoop != 0)
    {
        work->deltaTime += 1.0f;
        func_004b5000(maestro, fGpffff80e4);
    }
    else if (animEnd > fGpffff80e4 + animCurrent)
    {
        work->deltaTime += 1.0f;
        func_004b5000(maestro, fGpffff80e4);
    }
    else
    {
        func_004b5000(maestro, 0.0f);
        if (work->unk_120 == 0)
        {
            finished = true;
        }
    }

    func_004b4c70(maestro);
    func_004b3cc0(maestro);
    RwRenderStateSet(rwRENDERSTATEZWRITEENABLE, (void*)false);
    RwRenderStateSet(rwRENDERSTATEZTESTENABLE, (void*)false);
    RwRenderStateSet(rwRENDERSTATESHADEMODE, (void*)rwSHADEMODEGOURAUD);
    RwRenderStateSet(rwRENDERSTATETEXTUREFILTER, (void*)rwFILTERLINEAR);
    RwRenderStateSet(rwRENDERSTATEVERTEXALPHAENABLE, (void*)true);
    RwRenderStateSet(rwRENDERSTATESRCBLEND, (void*)rwBLENDSRCALPHA);
    RwRenderStateSet(rwRENDERSTATEDESTBLEND, (void*)rwBLENDINVSRCALPHA);
    RwRenderStateSet(rwRENDERSTATETEXTUREFILTER, (void*)rwFILTERLINEAR);
    RwRenderStateSet(rwRENDERSTATEVERTEXALPHAENABLE, (void*)true);
    color.r = 1.0f;
    color.g = 1.0f;
    color.b = 1.0f;
    color.a = work->alphaMult;
    func_004ae110(work->scene, &color);
    func_004aaa60();
    func_004a9bf0();
    func_004aaa60();
    func_004ae060(work->scene);
    func_004b5330(maestro);
    func_004aad50();
    func_004aad50();

    if (finished != 0)
    {
        if (work->unk_124 != 0)
        {
            H_Maestro_00111c50(hmaestroTask);
            goto restore_continue;
        }
        goto restore_stop;
    }

restore_continue:
    camera = kwlnGetMainCamera();
    RwCameraEndUpdate(camera);
    camera = kwlnGetMainCamera();
    func_004c9d70(camera, savedNearPlane);
    camera = kwlnGetMainCamera();
    RwCameraBeginUpdate(camera);
    return KWLNTASK_CONTINUE;

restore_stop:
    camera = kwlnGetMainCamera();
    RwCameraEndUpdate(camera);
    camera = kwlnGetMainCamera();
    func_004c9d70(camera, savedNearPlane);
    camera = kwlnGetMainCamera();
    RwCameraBeginUpdate(camera);
    return KWLNTASK_STOP;
}

// FUN_00111c50
void H_Maestro_00111c50(KwlnTask* hmaestroTask)
{
    HMaestro* work;
    u32 anim;

    work = (HMaestro*)hmaestroTask->workData;
    anim = FUN_004c2090(*(void**)((u8*)work->maestro + 8));
    FUN_004b1870(anim + 4, anim + 0x20, 0);
    work->state = HMAESTRO_STATE_IDLE;
}

// FUN_00111CA0
void func_00111ca0(KwlnTask* task, u32 value)
{
    ((HMaestro*)task->workData)->unk_124 = value;
}

// FUN_00111cb0
u32 H_Maestro_00111cb0(KwlnTask* hmaestroTask)
{
    HMaestro* work;
    u32 anim;
    f32 animEnd;
    f32 animCurrent;

    work = (HMaestro*)hmaestroTask->workData;
    if (work->state == HMAESTRO_STATE_DRAW)
    {
        anim = FUN_004c2090(*(void**)((u8*)work->maestro + 8));
        animEnd = FUN_004b1a70(anim + 4);
        animCurrent = FUN_004b1a60(anim + 4);

        return !(animEnd > fGpffff80e4 + animCurrent);
    }

    return true;
}

// FUN_00111d50
void H_Maestro_SetAlphaMult(KwlnTask* hmaestroTask, f32 alphaMult)
{
    ((HMaestro*)hmaestroTask->workData)->alphaMult = alphaMult;
}

// FUN_00111d60
void H_Maestro_DestroyTask(KwlnTask* hmaestroTask)
{
    HMaestro* work;

    work = (HMaestro*)hmaestroTask->workData;

    if (work->cdvd != NULL)
    {
        H_Cdvd_Destroy(work->cdvd);
        work->cdvd = NULL;
    }

    if (work->maestro != NULL)
    {
        Rt2dMaestroDestroy(work->maestro);
        work->maestro = NULL;
    }

    RwFree(work);
}

// FUN_00111dd0
KwlnTask* H_Maestro_CreateTask(KwlnTask* parent, u32 priority, const char* path)
{
    KwlnTask* task;
    HMaestro* work;

    work = RwCalloc(1, sizeof(HMaestro), rwMEMHINTDUR_GLOBAL);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreate(parent,
                          "H_DrawMaestro",
                          priority,
                          H_Maestro_UpdateTask,
                          H_Maestro_DestroyTask,
                          work);
    if (task == NULL)
    {
        return NULL;
    }

    strcpy(work->path, path);
    work->noDeltaTime = false;
    work->shouldLoop = false;
    work->alphaMult = 1.0f;
    work->useCdvd = false;

    return task;
}

// FUN_00111ec0
u32 H_Maestro_FinishedInit(KwlnTask* hmaestroTask)
{
    return ((HMaestro*)hmaestroTask->workData)->state > HMAESTRO_STATE_INITSCENE;
}

// FUN_00111ee0
void H_Maestro_RequestDraw(KwlnTask* hmaestroTask)
{
    ((HMaestro*)hmaestroTask->workData)->state = HMAESTRO_STATE_DRAW;
}

// FUN_00111f00
void H_Maestro_SetShouldLoop(KwlnTask* hmaestroTask, u32 shouldLoop)
{
    ((HMaestro*)hmaestroTask->workData)->shouldLoop = shouldLoop;
}

// FUN_00111F10
void func_00111f10(KwlnTask* task, u32 noDeltaTime)
{
    ((HMaestro*)task->workData)->noDeltaTime = noDeltaTime;
}

// FUN_00111f20
void H_Maestro_00111f20(KwlnTask* hmaestroTask, u32 param_2)
{
    ((HMaestro*)hmaestroTask->workData)->unk_120 = param_2;
}

// FUN_00111f30
u32 H_Maestro_00111f30(s16* param_1)
{
    return *param_1 == 5;
}

extern void* D_00833a40[];
#pragma alias D_00833a40_abs D_00833a40
extern void* D_00833a40_abs[];

// FUN_00111F50
void func_00111f50(void)
{
    HCdvd* requests[3];

    requests[0] = H_Cdvd_Request(D_005D6BD0, HCDVD_FILENORMAL);
    requests[1] = H_Cdvd_Request(D_005D6BF0, HCDVD_FILENORMAL);
    requests[2] = H_Cdvd_Request(D_005D6C10, HCDVD_FILENORMAL);
    H_Cdvd_ReadSync(requests[0]);
    H_Cdvd_ReadSync(requests[1]);
    H_Cdvd_ReadSync(requests[2]);

    D_00833a40_abs[0] = func_00112370(D_005D6BD0);
    D_00833a40_abs[1] = func_00112370(D_005D6BF0);
    D_00833a40_abs[2] = func_00112370(D_005D6C10);
    for (;;)
    {
        func_001120c0();
        if (((MaestroBlobNode*)D_00833a40_abs[0])->state == 5 &&
            ((MaestroBlobNode*)D_00833a40_abs[1])->state == 5 &&
            ((MaestroBlobNode*)D_00833a40_abs[2])->state == 5)
        {
            break;
        }
    }

    H_Cdvd_Destroy(requests[0]);
    H_Cdvd_Destroy(requests[1]);
    H_Cdvd_Destroy(requests[2]);
}

// FUN_001120a0
void* H_Maestro_001120a0(int param_1)
{
    return D_00833a40[param_1];
}
// FUN_001120C0
void func_001120c0(void)
{
    MaestroBlobNode* node;

    node = DAT_00833a50;
    for (;;)
    {
        if (node == NULL)
        {
            break;
        }
        func_00112110(node);
        node = node->next;
    }
}

// FUN_00112110 NONMATCHING
void func_00112110(void* param_1)
{
    MaestroBlobNode* node;

    node = (MaestroBlobNode*)param_1;
    switch (node->state)
    {
        case 0:
            node->cdvd = H_Cdvd_Request(node->path, HCDVD_FILENORMAL);
            node->state = 1;
            break;

        case 1:
            if (node->cdvd != NULL && !H_Cdvd_IsFileLoaded(node->cdvd))
            {
                break;
            }
            if (node->cdvd != NULL)
            {
                node->source = (u8*)node->cdvd->fileMemory;
            }
            memcpy(node->header, node->source, sizeof(node->header));
            node->sourceOffset += sizeof(node->header);
            node->state = 2;
            node->resourceIndex = 0;
            if (*((u16*)(node->header + 0x14)) == 0)
            {
                node->state = 4;
            }
            break;

        case 2:
        {
            u32 record[2];

            memcpy(record, node->source + node->sourceOffset, sizeof(record));
            node->sourceOffset += sizeof(record);
            node->resources[node->resourceIndex++] = func_0010e880(node->source + record[1]);
            if (node->resourceIndex == (s16)*((u16*)(node->header + 0x14)))
            {
                node->state = 4;
            }
            break;
        }

        case 3:
            node->resourceIndex++;
            node->state = node->resourceIndex == (s16)*((u16*)(node->header + 0x14)) ? 4 : 2;
            break;

        case 4:
        {
            s32 i;

            node->output = MAESTRO_ALLOC(*((u16*)(node->header + 0x16)), 0x80, 0x40000);
            for (i = 0; i < (s32)*((u16*)(node->header + 0x16)); i++)
            {
                u32 record[2];

                memcpy(record, node->source + node->sourceOffset, sizeof(record));
                node->sourceOffset += sizeof(record);
                memcpy((u8*)node->output + i * 0x80, node->source + record[1], 0x80);
            }
            if (node->cdvd != NULL)
            {
                H_Cdvd_Destroy(node->cdvd);
            }
            node->cdvd = NULL;
            node->outputCount = (s16)*((u16*)(node->header + 0x16));
            node->state = 5;
            break;
        }
    }
}

// FUN_00112370
void* func_00112370(const char* path)
{
    MaestroBlobNode* node;
    MaestroBlobNode* tail;
    MaestroBlobNode* next;

    node = (MaestroBlobNode*)MAESTRO_ALLOC(1, sizeof(MaestroBlobNode), 0x40000);
    node->state = 0;
    strcpy(node->path, path);
    tail = DAT_00833a50;
    if (tail == NULL)
    {
        DAT_00833a50 = node;
    }
    else
    {
        for (;;)
        {
            next = tail->next;
            if (next == NULL)
            {
                tail->next = node;
                node->prev = tail;
                break;
            }
            tail = next;
        }
    }
    return node;
}

// FUN_00112420
void* func_00112420(void* source)
{
    MaestroBlobNode* node;
    MaestroBlobNode* tail;
    MaestroBlobNode* next;

    node = (MaestroBlobNode*)MAESTRO_ALLOC(1, sizeof(MaestroBlobNode), 0x40000);
    node->state = 1;
    node->source = (u8*)source;
    tail = DAT_00833a50;
    if (tail == NULL)
    {
        DAT_00833a50 = node;
    }
    else
    {
        for (;;)
        {
            next = tail->next;
            if (next == NULL)
            {
                tail->next = node;
                node->prev = tail;
                break;
            }
            tail = next;
        }
    }
    return node;
}

// FUN_001124B0 NONMATCHING
void func_001124b0(void* param_1)
{
    MaestroBlobNode* node;
    s32 i;

    node = (MaestroBlobNode*)param_1;
    if (node->prev != NULL)
    {
        node->prev->next = node->next;
    }
    else
    {
        DAT_00833a50 = node->next;
    }
    if (node->next != NULL)
    {
        node->next->prev = node->prev;
    }

    for (i = 0; i < 32; i++)
    {
        if (node->resources[i] != NULL)
        {
            func_004cde90(node->resources[i]);
            node->resources[i] = NULL;
        }
    }
    if (node->cdvd != NULL)
    {
        H_Cdvd_Destroy(node->cdvd);
        node->cdvd = NULL;
    }
    if (node->output != NULL)
    {
        MAESTRO_FREE(node->output);
        node->output = NULL;
    }
    MAESTRO_FREE(node);
}

// FUN_001125D0
void func_001125d0(void)
{
    MaestroRenderNode* node;
    void (**setState)(u32, u32);

    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(6, 1);
    (*setState)(7, 2);
    (*setState)(8, 1);
    (*setState)(9, 1);
    (*setState)(12, 1);
    (*setState)(11, 6);
    (*setState)(10, 5);

    node = DAT_00833a4c;
    for (;;)
    {
        if (node == NULL)
        {
            break;
        }
        func_001127d0(node, true);
        node = node->next;
    }
}

// FUN_001126B0
f32 func_001126b0(void* param_1)
{
    u32 value;
    u32 offset;
    u8* output;
    u8* overrideBase;
    MaestroRenderNode* sample;

    sample = (MaestroRenderNode*)param_1;

    offset = sample->outputIndex * 0x80;
    output = sample->blob->output;
    value = *(s32*)((uintptr_t)offset + (uintptr_t)output + 0x5c) -
            *(s32*)((uintptr_t)offset + (uintptr_t)output + 0x54);
    overrideBase = output + 0x74;
    if (*(s16*)(overrideBase + offset) != 0)
    {
        value = *(s16*)(overrideBase + offset);
    }
    if (sample->xScale != 0)
    {
        value = (s32)(((u32)value * sample->xScale) >> 12);
    }
    return (f32)value;
}

// FUN_00112740
f32 func_00112740(void* param_1)
{
    u32 value;
    u32 offset;
    u8* output;
    u8* overrideBase;
    MaestroRenderNode* sample;

    sample = (MaestroRenderNode*)param_1;

    offset = sample->outputIndex * 0x80;
    output = sample->blob->output;
    value = *(s32*)((uintptr_t)offset + (uintptr_t)output + 0x60) -
            *(s32*)((uintptr_t)offset + (uintptr_t)output + 0x58);
    overrideBase = output + 0x76;
    if (*(s16*)(overrideBase + offset) != 0)
    {
        value = *(s16*)(overrideBase + offset);
    }
    if (sample->yScale != 0)
    {
        value = (s32)(((u32)value * sample->yScale) >> 12);
    }
    return (f32)value;
}
#pragma push
#pragma opt_common_subs off
 
/* Retail's rotation path at 0x0508-0x0660 evaluates the sine/cosine
 * polynomials inline before the matrix calls.  Its repeated output-record
 * loads in UV, position, and color setup (0x0110-0x04d0) remain un-hoisted.
 * The extension dispatch at 0x0c54-0x1224 keeps each record direction as a
 * distinct render path: top, bottom, left, right, then node extraHeight and
 * extraWidth, each rebuilding the immediate-mode strip before returning.
 * The explicit branches below preserve those state transitions and duplicated
 * draw calls instead of folding them into one common tail. */
// FUN_001127D0 NONMATCHING
void func_001127d0(void* param_1, u32 enabled)
{
    MaestroRenderNode* node;
    MaestroOutputRecord* record;
    RwV2d uv[4];
    RwV3d local[4];
    RwV3d transformed[4];
    RwV3d positions[4];
    RwIm2DVertex vertices[4];
    RwMatrix* matrix;
    RwCamera* camera;
    void* resource;
    s32* dimensions;
    s32 width;
    s32 height;
    s32 edge;
    f32 angle;
    f32 radians;
    f32 angleSquared;
    f32 polynomial;
    f32 cosine;
    f32 sine;
    f32 recipZ;
    u32 i;
    u32 packedColor;
    u32 red;
    u32 green;
    u32 blue;
    u32 alpha;

    node = (MaestroRenderNode*)param_1;
    /* Retail 0x2c-0x50 computes the camera reciprocal before any state or record work. */
    camera = kwlnGetMainCamera();
    recipZ = 1.0f / camera->nearPlane;

    if (enabled != 0)
    {
        D_00960090(6, 1);
        D_00960090(7, 2);
        D_00960090(8, 1);
        D_00960090(9, 2);
        D_00960090(12, 1);
        D_00960090(11, 6);
        D_00960090(10, 5);
        D_00960090(2, 4);
        D_00960090(14, 0);
    }

    record = (MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80);
    resource = node->blob->resources[record->resourceIndex];

    if (resource != NULL)
    {
        dimensions = (s32*)resource;
        uv[0].x = (f32)((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->left / (f32)dimensions[3];
        uv[0].y = (f32)((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->top / (f32)dimensions[4];
        uv[1].x = (f32)(((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->right - 1) / (f32)dimensions[3];
        uv[1].y = uv[0].y;
        uv[2].x = uv[0].x;
        uv[2].y = (f32)(((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->bottom - 1) / (f32)dimensions[4];
        uv[3].x = uv[1].x;
        uv[3].y = uv[2].y;
    }

    if (enabled != 0)
    {
        RpSkyRenderStateSet(2, (void*)0x44);
        RpSkyRenderStateSet(3, (void*)0x717FB);
        if ((record->renderStateFlags & 1) != 0)
        {
            RpSkyRenderStateSet(2, (void*)0x48);
            RpSkyRenderStateSet(3, (void*)0x71801);
        }
        if ((record->renderStateFlags & 2) != 0)
        {
            RpSkyRenderStateSet(2, (void*)0x42);
            RpSkyRenderStateSet(3, (void*)0x71801);
        }
    }

    if ((record->flags & 2) != 0)
    {
        RwV2d swap;

        swap = uv[0];
        uv[0] = uv[2];
        uv[2] = swap;
        swap = uv[1];
        uv[1] = uv[3];
        uv[3] = swap;
    }
    if ((record->flags & 1) != 0)
    {
        RwV2d swap;

        swap = uv[0];
        uv[0] = uv[1];
        uv[1] = swap;
        swap = uv[2];
        uv[2] = uv[3];
        uv[3] = swap;
    }

    width = record->right - record->left;
    if (record->overrideX != 0)
    {
        width = record->overrideX;
    }
    if (node->xScale != 0)
    {
        width = (width * (s32)node->xScale) >> 12;
    }
    height = record->bottom - record->top;
    if (record->overrideY != 0)
    {
        height = record->overrideY;
    }
    if (node->yScale != 0)
    {
        height = (height * (s32)node->yScale) >> 12;
    }

    local[0].x = -(f32)node->pivotX;
    local[0].y = -(f32)node->pivotY;
    local[0].z = 0.0f;
    local[1].x = (f32)(width - node->pivotX);
    local[1].y = local[0].y;
    local[1].z = 0.0f;
    local[2].x = local[0].x;
    local[2].y = (f32)(height - node->pivotY);
    local[2].z = 0.0f;
    local[3].x = local[1].x;
    local[3].y = local[2].y;
    local[3].z = 0.0f;

    angle = node->angle;
    if (angle != 0.0f)
    {
        while (angle >= 180.0f)
        {
            angle -= 360.0f;
        }
        while (angle < -180.0f)
        {
            angle += 360.0f;
        }
        radians = (angle * 3.1415927f) / 180.0f;
        angleSquared = radians * radians;
        matrix = func_004c38c0();
        polynomial = -1.1359648e-11f * angleSquared + 2.0875723e-9f;
        polynomial = polynomial * angleSquared - 2.7557314e-7f;
        polynomial = polynomial * angleSquared + 2.4801588e-5f;
        polynomial = polynomial * angleSquared - 0.0013888889f;
        polynomial = polynomial * angleSquared + 0.041666668f;
        polynomial = angleSquared * polynomial;
        cosine = 0.5f * angleSquared - angleSquared * polynomial;
        cosine = 1.0f - cosine;
        polynomial = 1.5896910e-10f * angleSquared - 2.5050760e-8f;
        polynomial = polynomial * angleSquared + 2.7557314e-6f;
        polynomial = polynomial * angleSquared - 0.0001984127f;
        polynomial = polynomial * angleSquared + 0.0083333338f;
        polynomial = polynomial * angleSquared - 0.16666667f;
        sine = radians + (angleSquared * radians) * polynomial;
        func_004c2fc0(1.0f - cosine, sine, matrix, &D_005D6C28, rwCOMBINEREPLACE);
        func_004c6c20(transformed, local, 4, matrix);
        func_004c3880(matrix);
    }
    else
    {
        for (i = 0; i < 4; i++)
        {
            transformed[i] = local[i];
        }
    }

    for (i = 0; i < 4; i++)
    {
        positions[i].x = (f32)node->pivotX + transformed[i].x + node->x + (f32)((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->x;
        positions[i].y = (f32)node->pivotY + transformed[i].y + node->y + (f32)((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->y;
        positions[i].z = 0.0f;
    }

    for (i = 0; i < 4; i++)
    {
        vertices[i].u.els.scrVertex.x = positions[i].x;
        vertices[i].u.els.scrVertex.y = positions[i].y;
        vertices[i].u.els.scrVertex.z = D_00960088 - node->depth;
        vertices[i].u.els.u = uv[i].x;
        vertices[i].u.els.v = uv[i].y;
        vertices[i].u.els.recipZ = recipZ;
    }

    for (i = 0; i < 4; i++)
    {
        packedColor = ((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->colors[i == 2 ? 3 : (i == 3 ? 2 : i)];
        red = ((packedColor >> 24) & 0xFF) * node->red / 255;
        green = ((packedColor >> 16) & 0xFF) * node->green / 255;
        blue = ((packedColor >> 8) & 0xFF) * node->blue / 255;
        alpha = packedColor & 0xFF;
        if ((((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->flags & 8) == 0)
        {
            red = red >= 0x81 ? 0xFF : red * 255 / 128;
            green = green >= 0x81 ? 0xFF : green * 255 / 128;
            blue = blue >= 0x81 ? 0xFF : blue * 255 / 128;
            alpha = alpha >= 0x81 ? 0xFF : alpha * 255 / 128;
        }
        alpha = (255 - node->alphaLoss) * alpha / 255;
        if (alpha > node->alphaCutoff)
        {
            alpha -= node->alphaCutoff;
        }
        else
        {
            alpha = 0;
        }

        vertices[i].u.els.color.r = (f32)red;
        vertices[i].u.els.color.g = (f32)green;
        vertices[i].u.els.color.b = (f32)blue;
        vertices[i].u.els.color.a = (f32)alpha;
    }

    D_00960090(1, (((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->flags & 8) != 0 ? 0 : (u32)resource);
    D_009600A0(rwPRIMTYPETRISTRIP, vertices, 4);

    edge = 0;
    if (((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->topExtension != 0)
    {
        edge = ((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->topExtension;
        vertices[0].u.els.scrVertex.x = positions[0].x;
        vertices[0].u.els.scrVertex.y = positions[0].y - edge;
        vertices[1].u.els.scrVertex.x = positions[1].x;
        vertices[1].u.els.scrVertex.y = positions[1].y - edge;
        vertices[2].u.els.scrVertex.x = positions[0].x;
        vertices[2].u.els.scrVertex.y = positions[0].y;
        vertices[3].u.els.scrVertex.x = positions[1].x;
        vertices[3].u.els.scrVertex.y = positions[1].y;
        vertices[0].u.els.u = vertices[2].u.els.u = uv[0].x;
        vertices[0].u.els.v = vertices[2].u.els.v = uv[0].y;
        vertices[1].u.els.u = vertices[3].u.els.u = uv[1].x;
        vertices[1].u.els.v = vertices[3].u.els.v = uv[1].y;
        D_00960090(1, (((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->flags & 8) != 0 ? 0 : (u32)resource);
        D_009600A0(rwPRIMTYPETRISTRIP, vertices, 4);
    }
    else if (((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->bottomExtension != 0)
    {
        edge = ((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->bottomExtension;
        vertices[0].u.els.scrVertex.x = positions[2].x;
        vertices[0].u.els.scrVertex.y = positions[2].y;
        vertices[1].u.els.scrVertex.x = positions[3].x;
        vertices[1].u.els.scrVertex.y = positions[3].y;
        vertices[2].u.els.scrVertex.x = positions[2].x;
        vertices[2].u.els.scrVertex.y = positions[2].y + edge;
        vertices[3].u.els.scrVertex.x = positions[3].x;
        vertices[3].u.els.scrVertex.y = positions[3].y + edge;
        vertices[0].u.els.u = vertices[2].u.els.u = uv[2].x;
        vertices[0].u.els.v = vertices[2].u.els.v = uv[2].y;
        vertices[1].u.els.u = vertices[3].u.els.u = uv[3].x;
        vertices[1].u.els.v = vertices[3].u.els.v = uv[3].y;
        D_00960090(1, (((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->flags & 8) != 0 ? 0 : (u32)resource);
        D_009600A0(rwPRIMTYPETRISTRIP, vertices, 4);
    }
    else if (((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->leftExtension != 0)
    {
        edge = ((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->leftExtension;
        vertices[0].u.els.scrVertex.x = positions[0].x - edge;
        vertices[0].u.els.scrVertex.y = positions[0].y;
        vertices[1].u.els.scrVertex.x = positions[0].x;
        vertices[1].u.els.scrVertex.y = positions[0].y;
        vertices[2].u.els.scrVertex.x = positions[2].x - edge;
        vertices[2].u.els.scrVertex.y = positions[2].y;
        vertices[3].u.els.scrVertex.x = positions[2].x;
        vertices[3].u.els.scrVertex.y = positions[2].y;
        vertices[0].u.els.u = vertices[1].u.els.u = uv[0].x;
        vertices[0].u.els.v = vertices[1].u.els.v = uv[0].y;
        vertices[2].u.els.u = vertices[3].u.els.u = uv[2].x;
        vertices[2].u.els.v = vertices[3].u.els.v = uv[2].y;
        D_00960090(1, (((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->flags & 8) != 0 ? 0 : (u32)resource);
        D_009600A0(rwPRIMTYPETRISTRIP, vertices, 4);
    }
    else if (((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->rightExtension != 0)
    {
        edge = ((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->rightExtension;
        vertices[0].u.els.scrVertex.x = positions[1].x;
        vertices[0].u.els.scrVertex.y = positions[1].y;
        vertices[1].u.els.scrVertex.x = positions[1].x + edge;
        vertices[1].u.els.scrVertex.y = positions[1].y;
        vertices[2].u.els.scrVertex.x = positions[3].x;
        vertices[2].u.els.scrVertex.y = positions[3].y;
        vertices[3].u.els.scrVertex.x = positions[3].x + edge;
        vertices[3].u.els.scrVertex.y = positions[3].y;
        vertices[0].u.els.u = vertices[1].u.els.u = uv[1].x;
        vertices[0].u.els.v = vertices[1].u.els.v = uv[1].y;
        vertices[2].u.els.u = vertices[3].u.els.u = uv[3].x;
        vertices[2].u.els.v = vertices[3].u.els.v = uv[3].y;
        D_00960090(1, (((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->flags & 8) != 0 ? 0 : (u32)resource);
        D_009600A0(rwPRIMTYPETRISTRIP, vertices, 4);
    }
    else if (node->extraHeight != 0)
    {
        edge = node->extraHeight;
        vertices[0].u.els.scrVertex.x = positions[2].x;
        vertices[0].u.els.scrVertex.y = positions[2].y;
        vertices[1].u.els.scrVertex.x = positions[3].x;
        vertices[1].u.els.scrVertex.y = positions[3].y;
        vertices[2].u.els.scrVertex.x = positions[2].x;
        vertices[2].u.els.scrVertex.y = positions[2].y + edge;
        vertices[3].u.els.scrVertex.x = positions[3].x;
        vertices[3].u.els.scrVertex.y = positions[3].y + edge;
        vertices[0].u.els.u = vertices[2].u.els.u = uv[2].x;
        vertices[0].u.els.v = vertices[2].u.els.v = uv[2].y;
        vertices[1].u.els.u = vertices[3].u.els.u = uv[3].x;
        vertices[1].u.els.v = vertices[3].u.els.v = uv[3].y;
        D_00960090(1, (((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->flags & 8) != 0 ? 0 : (u32)resource);
        D_009600A0(rwPRIMTYPETRISTRIP, vertices, 4);
    }
    else if (node->extraWidth != 0)
    {
        edge = node->extraWidth;
        vertices[0].u.els.scrVertex.x = positions[1].x;
        vertices[0].u.els.scrVertex.y = positions[1].y;
        vertices[1].u.els.scrVertex.x = positions[1].x + edge;
        vertices[1].u.els.scrVertex.y = positions[1].y;
        vertices[2].u.els.scrVertex.x = positions[3].x;
        vertices[2].u.els.scrVertex.y = positions[3].y;
        vertices[3].u.els.scrVertex.x = positions[3].x + edge;
        vertices[3].u.els.scrVertex.y = positions[3].y;
        vertices[0].u.els.u = vertices[1].u.els.u = uv[1].x;
        vertices[0].u.els.v = vertices[1].u.els.v = uv[1].y;
        vertices[2].u.els.u = vertices[3].u.els.u = uv[3].x;
        vertices[2].u.els.v = vertices[3].u.els.v = uv[3].y;
        D_00960090(1, (((MaestroOutputRecord*)((u8*)node->blob->output + node->outputIndex * 0x80))->flags & 8) != 0 ? 0 : (u32)resource);
        D_009600A0(rwPRIMTYPETRISTRIP, vertices, 4);
    }
}
#pragma pop

/* The following helpers are the pre-Camp Maestro immediate-mode renderer.  The
 * retail module keeps these entry points in this translation unit (the same
 * allocator/list globals are shared with the stream code above). */
static void Maestro_SetPrimitiveStates(u32 skyRasterState, u32 skyTextureState)
{
    (*D_00960090)(6, 1);
    (*D_00960090)(7, 2);
    (*D_00960090)(8, 1);
    (*D_00960090)(9, 2);
    (*D_00960090)(12, 1);
    (*D_00960090)(11, 6);
    (*D_00960090)(10, 5);
    (*D_00960090)(2, 4);
    RpSkyRenderStateSet(2, (void*)skyRasterState);
    RpSkyRenderStateSet(3, (void*)skyTextureState);
}

static void Maestro_SetVertex(RwIm2DVertex* vertex,
                              f32 x,
                              f32 y,
                              f32 z,
                              f32 recipZ,
                              f32 u,
                              f32 v,
                              u32 color)
{
    vertex->u.els.scrVertex.x = x;
    vertex->u.els.scrVertex.y = y;
    vertex->u.els.scrVertex.z = z;
    vertex->u.els.camVertex_z = 0.0f;
    vertex->u.els.u = u;
    vertex->u.els.v = v;
    vertex->u.els.recipZ = recipZ;
    vertex->u.els.color.r = (f32)((color >> 24) & 0xff);
    vertex->u.els.color.g = (f32)((color >> 16) & 0xff);
    vertex->u.els.color.b = (f32)((color >> 8) & 0xff);
    vertex->u.els.color.a = (f32)(color & 0xff);
}

static void Maestro_DrawQuad(RwIm2DVertex* vertices,
                             f32 x,
                             f32 y,
                             f32 width,
                             f32 height,
                             f32 z,
                             f32 recipZ,
                             u32 color,
                             f32 u0,
                             f32 v0,
                             f32 u1,
                             f32 v1)
{
    Maestro_SetVertex(&vertices[0], x, y, z, recipZ, u0, v0, color);
    Maestro_SetVertex(&vertices[1], x + width, y, z, recipZ, u1, v0, color);
    Maestro_SetVertex(&vertices[2], x, y + height, z, recipZ, u0, v1, color);
    Maestro_SetVertex(&vertices[3], x + width, y + height, z, recipZ, u1, v1, color);
    (*D_009600A0)(rwPRIMTYPETRISTRIP, vertices, 4);
}

static f32 Maestro_NearReciprocal(void)
{
    RwCamera* camera = kwlnGetMainCamera();
    return 1.0f / camera->nearPlane;
}

// FUN_00113A30 NONMATCHING
// Same reconstruction pattern as func_001140d0 below: retail inlines the
// state-set calls and per-vertex doubled-alpha color loop rather than
// delegating to Maestro_SetPrimitiveStates/DrawQuad/NearReciprocal.
void func_00113a30(f32 depth, f32 x, f32 y, u32 color, s32 width, s32 height)
{
    RwIm2DVertex vertices[4];
    f32 corners[4][2];
    f32 farX;
    f32 farY;
    f32 recipZ;
    f32 z;
    void (**setState)(u32, u32);
    s32 r;
    s32 g;
    s32 b;
    s32 a;
    s32 i;

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;

    r = (s32)((color & 0xff000000) >> 24);
    g = (s32)((color & 0xff0000) >> 16);
    b = (s32)((color & 0xff00) >> 8);
    a = (s32)(color & 0xff);

    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(6, 1);
    (*setState)(7, 2);
    (*setState)(8, 1);
    (*setState)(9, 1);
    (*setState)(0xc, 1);
    (*setState)(0xb, 6);
    (*setState)(0xa, 5);
    (*setState)(2, 4);
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x717fb);

    corners[0][0] = x;
    corners[0][1] = y;
    farX = x + (f32)width;
    corners[3][0] = farX;
    farY = y + (f32)height;
    corners[3][1] = farY;
    corners[1][0] = farX;
    corners[1][1] = y;
    corners[2][0] = x;
    corners[2][1] = farY;
    z = D_00960088 - depth;

    for (i = 0; i < 4; i++)
    {
        RwIm2DVertex* v = &vertices[i];
        v->u.els.scrVertex.z = z;
        v->u.els.recipZ = recipZ;
        v->u.els.color.r = r >= 0 ? (f32)r : (f32)(((u32)r >> 1) | (r & 1)) * 2.0f;
        v->u.els.color.g = g >= 0 ? (f32)g : (f32)(((u32)g >> 1) | (g & 1)) * 2.0f;
        v->u.els.color.b = b >= 0 ? (f32)b : (f32)(((u32)b >> 1) | (b & 1)) * 2.0f;
        v->u.els.color.a = a >= 0 ? (f32)a : (f32)(((u32)a >> 1) | (a & 1)) * 2.0f;
        v->u.els.scrVertex.x = corners[i][0];
        v->u.els.scrVertex.y = corners[i][1];
    }

    vertices[0].u.els.u = 0.0f;
    vertices[0].u.els.v = 0.0f;
    vertices[1].u.els.u = 1.0f;
    vertices[1].u.els.v = 0.0f;
    vertices[2].u.els.u = 0.0f;
    vertices[2].u.els.v = 1.0f;
    vertices[3].u.els.u = 1.0f;
    vertices[3].u.els.v = 1.0f;

    (*setState)(1, 0);

    (*D_009600A0)(rwPRIMTYPETRISTRIP, vertices, 4);
}

// FUN_00113D80 NONMATCHING
// Same reconstruction pattern as func_001140d0 below.
void func_00113d80(f32 depth, f32 x, f32 y, u32 color, s32 width, s32 height)
{
    RwIm2DVertex vertices[4];
    f32 corners[4][2];
    f32 farX;
    f32 farY;
    f32 recipZ;
    f32 z;
    void (**setState)(u32, u32);
    s32 r;
    s32 g;
    s32 b;
    s32 a;
    s32 i;

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;

    r = (s32)((color & 0xff000000) >> 24);
    g = (s32)((color & 0xff0000) >> 16);
    b = (s32)((color & 0xff00) >> 8);
    a = (s32)(color & 0xff);

    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(6, 1);
    (*setState)(7, 2);
    (*setState)(8, 1);
    (*setState)(9, 1);
    (*setState)(0xc, 1);
    (*setState)(0xb, 6);
    (*setState)(0xa, 5);
    (*setState)(2, 4);
    RpSkyRenderStateSet(2, (void*)0x48);
    RpSkyRenderStateSet(3, (void*)0x71801);

    corners[0][0] = x;
    corners[0][1] = y;
    farX = x + (f32)width;
    corners[3][0] = farX;
    farY = y + (f32)height;
    corners[3][1] = farY;
    corners[1][0] = farX;
    corners[1][1] = y;
    corners[2][0] = x;
    corners[2][1] = farY;
    z = D_00960088 - depth;

    for (i = 0; i < 4; i++)
    {
        RwIm2DVertex* v = &vertices[i];
        v->u.els.scrVertex.z = z;
        v->u.els.recipZ = recipZ;
        v->u.els.color.r = r >= 0 ? (f32)r : (f32)(((u32)r >> 1) | (r & 1)) * 2.0f;
        v->u.els.color.g = g >= 0 ? (f32)g : (f32)(((u32)g >> 1) | (g & 1)) * 2.0f;
        v->u.els.color.b = b >= 0 ? (f32)b : (f32)(((u32)b >> 1) | (b & 1)) * 2.0f;
        v->u.els.color.a = a >= 0 ? (f32)a : (f32)(((u32)a >> 1) | (a & 1)) * 2.0f;
        v->u.els.scrVertex.x = corners[i][0];
        v->u.els.scrVertex.y = corners[i][1];
    }

    vertices[0].u.els.u = 0.0f;
    vertices[0].u.els.v = 0.0f;
    vertices[1].u.els.u = 1.0f;
    vertices[1].u.els.v = 0.0f;
    vertices[2].u.els.u = 0.0f;
    vertices[2].u.els.v = 1.0f;
    vertices[3].u.els.u = 1.0f;
    vertices[3].u.els.v = 1.0f;

    (*setState)(1, 0);

    (*D_009600A0)(rwPRIMTYPETRISTRIP, vertices, 4);
}

// FUN_001140D0 NONMATCHING
// Reconstructed from retail disassembly: unlike the sibling Maestro_Draw*
// wrappers, retail does NOT call Maestro_SetPrimitiveStates/DrawQuad/
// NearReciprocal for this function - it inlines the state-set calls, the
// camera near-plane division, and a custom per-vertex loop with PS2 GS
// "doubled alpha" color-channel expansion (see k_sceneDraw.c func_0019f8f0
// for the same idiom). Residual: MWCC recomputes/partially duplicates the
// per-channel branch inside the loop differently from retail's single
// pass (object 1100B vs 896B window) - a register/CSE floor after
// extensive pragma and type experimentation; logic and call sequence are
// confirmed correct against the retail bytes.
void func_001140d0(f32 depth,
                   f32 x,
                   f32 y,
                   u32 color,
                   s32 width,
                   s32 height,
                   const u32* textureState)
{
    RwIm2DVertex vertices[4];
    f32 corners[4][2];
    f32 farX;
    f32 farY;
    f32 recipZ;
    f32 z;
    void (**setState)(u32, u32);
    s32 r;
    s32 g;
    s32 b;
    s32 a;
    s32 i;

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;

    r = (s32)((color & 0xff000000) >> 24);
    g = (s32)((color & 0xff0000) >> 16);
    b = (s32)((color & 0xff00) >> 8);
    a = (s32)(color & 0xff);

    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(6, 1);
    (*setState)(7, 2);
    (*setState)(8, 1);
    (*setState)(9, 2);
    (*setState)(0xc, 1);
    (*setState)(0xb, 6);
    (*setState)(0xa, 5);
    (*setState)(2, 4);
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x717fb);

    corners[0][0] = x;
    corners[0][1] = y;
    farX = x + (f32)width;
    corners[3][0] = farX;
    farY = y + (f32)height;
    corners[3][1] = farY;
    corners[1][0] = farX;
    corners[1][1] = y;
    corners[2][0] = x;
    corners[2][1] = farY;
    z = D_00960088 - depth;

    for (i = 0; i < 4; i++)
    {
        RwIm2DVertex* v = &vertices[i];
        v->u.els.scrVertex.z = z;
        v->u.els.recipZ = recipZ;
        v->u.els.color.r = r >= 0 ? (f32)r : (f32)(((u32)r >> 1) | (r & 1)) * 2.0f;
        v->u.els.color.g = g >= 0 ? (f32)g : (f32)(((u32)g >> 1) | (g & 1)) * 2.0f;
        v->u.els.color.b = b >= 0 ? (f32)b : (f32)(((u32)b >> 1) | (b & 1)) * 2.0f;
        v->u.els.color.a = a >= 0 ? (f32)a : (f32)(((u32)a >> 1) | (a & 1)) * 2.0f;
        v->u.els.scrVertex.x = corners[i][0];
        v->u.els.scrVertex.y = corners[i][1];
    }

    vertices[0].u.els.u = 0.0f;
    vertices[0].u.els.v = 0.0f;
    vertices[1].u.els.u = 1.0f;
    vertices[1].u.els.v = 0.0f;
    vertices[2].u.els.u = 0.0f;
    vertices[2].u.els.v = 1.0f;
    vertices[3].u.els.u = 1.0f;
    vertices[3].u.els.v = 1.0f;

    (*setState)(1, *textureState);

    (*D_009600A0)(rwPRIMTYPETRISTRIP, vertices, 4);
}

#pragma opt_loop_invariants on
// FUN_00114450 NONMATCHING
void func_00114450(f32 depth,
                   f32 x,
                   f32 y,
                   u32 color,
                   u32 colorAlpha,
                   s32 ignoredWidth,
                   s32 height,
                   const u32* textureState)
{
    RwIm2DVertex vertices[8];
    f32 corners[8][2];
    f32 farX;
    f32 farY;
    f32 recipZ;
    f32 z;
    f32 tmp;
    void (**setState)(u32, u32);
    s8 r;
    s8 g;
    s8 b;
    s8 a;
    s8 a2;
    s32 r1;
    s32 g1;
    s32 b1;
    s32 a1;
    s32 i;

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;

    r = (s8)(color >> 24);
    g = (s8)(color >> 16);
    b = (s8)(color >> 8);
    a = (s8)color;
    a2 = (s8)colorAlpha;

    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(6, 1);
    (*setState)(7, 2);
    (*setState)(8, 1);
    (*setState)(9, 2);
    (*setState)(0xc, 1);
    (*setState)(0xb, 6);
    (*setState)(0xa, 5);
    (*setState)(2, 4);
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x717fb);

    corners[0][0] = x;
    corners[0][1] = y;
    farX = x + 320.0f;
    farY = y + (f32)height;
    corners[1][0] = farX;
    corners[1][1] = y;
    corners[2][0] = x;
    corners[2][1] = farY;
    corners[3][0] = farX;
    corners[3][1] = farY;
    corners[4][0] = farX;
    corners[4][1] = y;
    corners[5][0] = farX + 320.0f;
    corners[5][1] = y;
    corners[6][0] = farX;
    corners[6][1] = farY;
    corners[7][0] = farX + 320.0f;
    corners[7][1] = farY;

    z = D_00960088 - depth;

    r1 = r & 1;
    g1 = g & 1;
    b1 = b & 1;
    a1 = a & 1;

    for (i = 0; i < 4; i++)
    {
        vertices[i].u.els.camVertex_z = z;
        vertices[i].u.els.recipZ = recipZ;
        if (r >= 0) {
            vertices[i].u.els.color.r = (f32)r;
        } else {
            tmp = (f32)(s32)(((u32)r >> 1) | r1);
            vertices[i].u.els.color.r = tmp + tmp;
        }
        if (g >= 0) {
            vertices[i].u.els.color.g = (f32)g;
        } else {
            tmp = (f32)(s32)(((u32)g >> 1) | g1);
            vertices[i].u.els.color.g = tmp + tmp;
        }
        if (b >= 0) {
            vertices[i].u.els.color.b = (f32)b;
        } else {
            tmp = (f32)(s32)(((u32)b >> 1) | b1);
            vertices[i].u.els.color.b = tmp + tmp;
        }
        if (a >= 0) {
            vertices[i].u.els.color.a = (f32)a;
        } else {
            tmp = (f32)(s32)(((u32)a >> 1) | a1);
            vertices[i].u.els.color.a = tmp + tmp;
        }
        vertices[i].u.els.scrVertex.x = corners[i][0];
        vertices[i].u.els.scrVertex.y = corners[i][1];

        vertices[i + 4].u.els.camVertex_z = z;
        vertices[i + 4].u.els.recipZ = recipZ;
        if (r >= 0) {
            vertices[i + 4].u.els.color.r = (f32)r;
        } else {
            tmp = (f32)(s32)(((u32)r >> 1) | r1);
            vertices[i + 4].u.els.color.r = tmp + tmp;
        }
        if (g >= 0) {
            vertices[i + 4].u.els.color.g = (f32)g;
        } else {
            tmp = (f32)(s32)(((u32)g >> 1) | g1);
            vertices[i + 4].u.els.color.g = tmp + tmp;
        }
        if (b >= 0) {
            vertices[i + 4].u.els.color.b = (f32)b;
        } else {
            tmp = (f32)(s32)(((u32)b >> 1) | b1);
            vertices[i + 4].u.els.color.b = tmp + tmp;
        }
        if (a >= 0) {
            vertices[i + 4].u.els.color.a = (f32)a;
        } else {
            tmp = (f32)(s32)(((u32)a >> 1) | a1);
            vertices[i + 4].u.els.color.a = tmp + tmp;
        }
        vertices[i + 4].u.els.scrVertex.x = corners[i + 4][0];
        vertices[i + 4].u.els.scrVertex.y = corners[i + 4][1];
    }

    if (r >= 0) {
        vertices[0].u.els.color.r = (f32)r;
    } else {
        tmp = (f32)(s32)(((u32)r >> 1) | r1);
        vertices[0].u.els.color.r = tmp + tmp;
    }
    if (g >= 0) {
        vertices[0].u.els.color.g = (f32)g;
    } else {
        tmp = (f32)(s32)(((u32)g >> 1) | g1);
        vertices[0].u.els.color.g = tmp + tmp;
    }
    if (b >= 0) {
        vertices[0].u.els.color.b = (f32)b;
    } else {
        tmp = (f32)(s32)(((u32)b >> 1) | b1);
        vertices[0].u.els.color.b = tmp + tmp;
    }
    if (a2 >= 0) {
        vertices[0].u.els.color.a = (f32)a2;
    } else {
        tmp = (f32)(s32)(((u32)a2 >> 1) | (a2 & 1));
        vertices[0].u.els.color.a = tmp + tmp;
    }

    if (r >= 0) {
        vertices[2].u.els.color.r = (f32)r;
    } else {
        tmp = (f32)(s32)(((u32)r >> 1) | r1);
        vertices[2].u.els.color.r = tmp + tmp;
    }
    if (g >= 0) {
        vertices[2].u.els.color.g = (f32)g;
    } else {
        tmp = (f32)(s32)(((u32)g >> 1) | g1);
        vertices[2].u.els.color.g = tmp + tmp;
    }
    if (b >= 0) {
        vertices[2].u.els.color.b = (f32)b;
    } else {
        tmp = (f32)(s32)(((u32)b >> 1) | b1);
        vertices[2].u.els.color.b = tmp + tmp;
    }
    if (a2 >= 0) {
        vertices[2].u.els.color.a = (f32)a2;
    } else {
        tmp = (f32)(s32)(((u32)a2 >> 1) | (a2 & 1));
        vertices[2].u.els.color.a = tmp + tmp;
    }

    vertices[0].u.els.u = 0.0f;
    vertices[0].u.els.v = 0.0f;
    vertices[1].u.els.u = 0.5f;
    vertices[1].u.els.v = 0.0f;
    vertices[2].u.els.u = 0.0f;
    vertices[2].u.els.v = 1.0f;
    vertices[3].u.els.u = 0.5f;
    vertices[3].u.els.v = 1.0f;
    vertices[4].u.els.u = 0.5f;
    vertices[4].u.els.v = 0.0f;
    vertices[5].u.els.u = 1.0f;
    vertices[5].u.els.v = 0.0f;
    vertices[6].u.els.u = 0.5f;
    vertices[6].u.els.v = 1.0f;
    vertices[7].u.els.u = 1.0f;
    vertices[7].u.els.v = 1.0f;

    (*setState)(1, *textureState);
    (*D_009600A0)(rwPRIMTYPETRISTRIP, vertices, 4);
    (*D_009600A0)(rwPRIMTYPETRISTRIP, &vertices[4], 4);
}
#pragma opt_loop_invariants off

// FUN_00114AF0 NONMATCHING
// Same reconstruction pattern as func_001140d0 above.
void func_00114af0(f32 depth,
                   f32 x,
                   f32 y,
                   u32 color,
                   s32 width,
                   s32 height,
                   const u32* textureState)
{
    RwIm2DVertex vertices[4];
    f32 corners[4][2];
    f32 farX;
    f32 farY;
    f32 recipZ;
    f32 z;
    void (**setState)(u32, u32);
    s32 r;
    s32 g;
    s32 b;
    s32 a;
    s32 i;

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;

    r = (s32)((color & 0xff000000) >> 24);
    g = (s32)((color & 0xff0000) >> 16);
    b = (s32)((color & 0xff00) >> 8);
    a = (s32)(color & 0xff);

    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(6, 1);
    (*setState)(7, 2);
    (*setState)(8, 1);
    (*setState)(9, 2);
    (*setState)(0xc, 1);
    (*setState)(0xb, 6);
    (*setState)(0xa, 5);
    (*setState)(2, 4);
    RpSkyRenderStateSet(2, (void*)0x48);
    RpSkyRenderStateSet(3, (void*)0x71801);

    corners[0][0] = x;
    corners[0][1] = y;
    farX = x + (f32)width;
    corners[3][0] = farX;
    farY = y + (f32)height;
    corners[3][1] = farY;
    corners[1][0] = farX;
    corners[1][1] = y;
    corners[2][0] = x;
    corners[2][1] = farY;
    z = D_00960088 - depth;

    for (i = 0; i < 4; i++)
    {
        RwIm2DVertex* v = &vertices[i];
        v->u.els.scrVertex.z = z;
        v->u.els.recipZ = recipZ;
        v->u.els.color.r = r >= 0 ? (f32)r : (f32)(((u32)r >> 1) | (r & 1)) * 2.0f;
        v->u.els.color.g = g >= 0 ? (f32)g : (f32)(((u32)g >> 1) | (g & 1)) * 2.0f;
        v->u.els.color.b = b >= 0 ? (f32)b : (f32)(((u32)b >> 1) | (b & 1)) * 2.0f;
        v->u.els.color.a = a >= 0 ? (f32)a : (f32)(((u32)a >> 1) | (a & 1)) * 2.0f;
        v->u.els.scrVertex.x = corners[i][0];
        v->u.els.scrVertex.y = corners[i][1];
    }

    vertices[0].u.els.u = 0.0f;
    vertices[0].u.els.v = 0.0f;
    vertices[1].u.els.u = 1.0f;
    vertices[1].u.els.v = 0.0f;
    vertices[2].u.els.u = 0.0f;
    vertices[2].u.els.v = 1.0f;
    vertices[3].u.els.u = 1.0f;
    vertices[3].u.els.v = 1.0f;

    (*setState)(1, *textureState);

    (*D_009600A0)(rwPRIMTYPETRISTRIP, vertices, 4);
}

// Retail reconstruction: camera/state setup (0x114e70-0x114fec), vertex/color loop (0x115030-0x115164), UV/orientation staging (0x115168-0x115294), and final draw (0x1152a0-0x115300).
// FUN_00114E70 NONMATCHING
void func_00114e70(f32 depth,
                   f32 x,
                   f32 y,
                   f32 textureX,
                   f32 textureY,
                   s32 orientation,
                   u32 color,
                   s32 width,
                   s32 height,
                   const s32* textureDimensions)
{
    RwIm2DVertex vertices[4];
    f32 corners[4][2];
    f32 textureCoordinates[4][2];
    u64 swap;
    f32 farX;
    f32 farY;
    f32 recipZ;
    f32 z;
    void (**setState)(u32, u32);
    RwCamera* camera;
    s8 r;
    s8 g;
    s8 b;
    s8 a;
    s32 i;

    camera = kwlnGetMainCamera();
    recipZ = 1.0f / camera->nearPlane;

    r = (s8)(color >> 24);
    g = (s8)(color >> 16);
    b = (s8)(color >> 8);
    a = (s8)color;

    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(6, 1);
    (*setState)(7, 2);
    (*setState)(8, 1);
    (*setState)(9, 2);
    (*setState)(0xc, 1);
    (*setState)(0xb, 6);
    (*setState)(0xa, 5);
    (*setState)(2, 4);
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x717fb);

    corners[0][0] = x;
    corners[0][1] = y;
    farX = x + (f32)width;
    corners[3][0] = farX;
    farY = y + (f32)height;
    corners[3][1] = farY;
    corners[1][0] = farX;
    corners[1][1] = y;
    corners[2][0] = x;
    corners[2][1] = farY;
    z = D_00960088 - depth;

    for (i = 0; i < 4; i++)
    {
        RwIm2DVertex* v = &vertices[i];
        v->u.els.scrVertex.z = z;
        v->u.els.recipZ = recipZ;
        v->u.els.color.r = (f32)(u32)r;
        v->u.els.color.g = (f32)(u32)g;
        v->u.els.color.b = (f32)(u32)b;
        v->u.els.color.a = (f32)(u32)a;
        v->u.els.scrVertex.x = corners[i][0];
        v->u.els.scrVertex.y = corners[i][1];
    }

    textureCoordinates[0][0] = textureX / (f32)textureDimensions[3];
    textureCoordinates[0][1] = textureY / (f32)textureDimensions[4];
    textureCoordinates[3][0] = (textureX + (f32)width) / (f32)textureDimensions[3];
    textureCoordinates[3][1] = (textureY + (f32)height) / (f32)textureDimensions[4];
    textureCoordinates[1][0] = textureCoordinates[3][0];
    textureCoordinates[1][1] = textureCoordinates[0][1];
    textureCoordinates[2][0] = textureCoordinates[0][0];
    textureCoordinates[2][1] = textureCoordinates[3][1];

    if (orientation == 2)
    {
        swap = *(u64*)&textureCoordinates[0][0];
        *(u64*)&textureCoordinates[0][0] = *(u64*)&textureCoordinates[2][0];
        *(u64*)&textureCoordinates[2][0] = swap;
        swap = *(u64*)&textureCoordinates[1][0];
        *(u64*)&textureCoordinates[1][0] = *(u64*)&textureCoordinates[3][0];
        *(u64*)&textureCoordinates[3][0] = swap;
    }

    if (orientation == 1)
    {
        swap = *(u64*)&textureCoordinates[0][0];
        *(u64*)&textureCoordinates[0][0] = *(u64*)&textureCoordinates[1][0];
        *(u64*)&textureCoordinates[1][0] = swap;
        swap = *(u64*)&textureCoordinates[2][0];
        *(u64*)&textureCoordinates[2][0] = *(u64*)&textureCoordinates[3][0];
        *(u64*)&textureCoordinates[3][0] = swap;
    }

    for (i = 0; i < 4; i++)
    {
        vertices[i].u.els.u = textureCoordinates[i][0];
        vertices[i].u.els.v = textureCoordinates[i][1];
    }

    (*setState)(1, 0);
    (*D_009600A0)(rwPRIMTYPETRISTRIP, vertices, 4);
}

/* Retail 0x115350-0x1158a0 builds a four-vertex strip with inline state setup,
 * point staging, doubled-alpha channel conversion, and a final draw.  The
 * corresponding logic is reconstructed below; remaining differences are
 * compiler frame/register layout across the same retail ranges. */
// FUN_00115350 NONMATCHING
void func_00115350(f32 depth,
                   u32 color,
                   u64 point0,
                   u64 point1,
                   u64 point2,
                   u64 point3,
                   s32 alpha0,
                   s32 alpha1,
                   s32 alpha2,
                   s32 alpha3)
{
    RwIm2DVertex vertices[4];
    f32 points[4][2];
    f32 recipZ;
    f32 z;
    f32 tmpR;
    f32 tmpG;
    f32 tmpB;
    f32 blue;
    f32 alpha0f;
    f32 alpha1f;
    f32 alpha2f;
    f32 alpha3f;
    void (**setState)(u32, u32);
    s32 r;
    s32 g;
    s32 b;
    s32 r1;
    s32 g1;
    s32 b1;
    u32 i;
    RwIm2DVertex* v;

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;
    r = color >> 24;
    g = color >> 16;
    b = color >> 8;

    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(6, 1);
    (*setState)(7, 2);
    (*setState)(8, 1);
    (*setState)(9, 1);
    (*setState)(0xc, 1);
    (*setState)(0xb, 6);
    (*setState)(0xa, 5);
    (*setState)(2, 4);
    RpSkyRenderStateSet(2, (void*)0x44);
    RpSkyRenderStateSet(3, (void*)0x717fb);

    points[0][0] = ((const f32*)&point0)[0];
    points[0][1] = ((const f32*)&point0)[1];
    points[1][0] = ((const f32*)&point1)[0];
    points[1][1] = ((const f32*)&point1)[1];
    points[2][0] = ((const f32*)&point2)[0];
    points[2][1] = ((const f32*)&point2)[1];
    points[3][0] = ((const f32*)&point3)[0];
    points[3][1] = ((const f32*)&point3)[1];

    r1 = r & 1;
    g1 = g & 1;
    b1 = b & 1;
    z = D_00960088 - depth;
    alpha3f = (f32)alpha3;
    alpha2f = (f32)alpha2;
    alpha1f = (f32)alpha1;
    alpha0f = (f32)alpha0;
    if (b >= 0)
        blue = (f32)b;
    else
    {
        tmpB = (f32)(s32)(((u32)b >> 1) | b1);
        blue = tmpB + tmpB;
    }

    for (i = 0; i < 4; i++)
    {
        v = &vertices[i];
        switch (i)
        {
        case 0:
            v->u.els.scrVertex.z = z;
            v->u.els.recipZ = recipZ;
            if (r >= 0)
                v->u.els.color.r = (f32)r;
            else
            {
                tmpR = (f32)(s32)(((u32)r >> 1) | r1);
                v->u.els.color.r = tmpR + tmpR;
            }
            if (g >= 0)
                v->u.els.color.g = (f32)g;
            else
            {
                tmpG = (f32)(s32)(((u32)g >> 1) | g1);
                v->u.els.color.g = tmpG + tmpG;
            }
            if (b >= 0)
                v->u.els.color.b = (f32)b;
            else
            {
                tmpB = (f32)(s32)(((u32)b >> 1) | b1);
                v->u.els.color.b = tmpB + tmpB;
            }
            v->u.els.color.a = alpha0f;
            v->u.els.scrVertex.x = points[0][0];
            v->u.els.scrVertex.y = points[0][1];
            break;
        case 1:
            v->u.els.scrVertex.z = z;
            v->u.els.recipZ = recipZ;
            if (r >= 0)
                v->u.els.color.r = (f32)r;
            else
            {
                tmpR = (f32)(s32)(((u32)r >> 1) | r1);
                v->u.els.color.r = tmpR + tmpR;
            }
            if (g >= 0)
                v->u.els.color.g = (f32)g;
            else
            {
                tmpG = (f32)(s32)(((u32)g >> 1) | g1);
                v->u.els.color.g = tmpG + tmpG;
            }
            if (b >= 0)
                v->u.els.color.b = (f32)b;
            else
            {
                tmpB = (f32)(s32)(((u32)b >> 1) | b1);
                v->u.els.color.b = tmpB + tmpB;
            }
            v->u.els.color.a = alpha1f;
            v->u.els.scrVertex.x = points[1][0];
            v->u.els.scrVertex.y = points[1][1];
            break;
        case 2:
            v->u.els.scrVertex.z = z;
            v->u.els.recipZ = recipZ;
            if (r >= 0)
                v->u.els.color.r = (f32)r;
            else
            {
                tmpR = (f32)(s32)(((u32)r >> 1) | r1);
                v->u.els.color.r = tmpR + tmpR;
            }
            if (g >= 0)
                v->u.els.color.g = (f32)g;
            else
            {
                tmpG = (f32)(s32)(((u32)g >> 1) | g1);
                v->u.els.color.g = tmpG + tmpG;
            }
            v->u.els.color.b = blue;
            v->u.els.color.a = alpha2f;
            v->u.els.scrVertex.x = points[2][0];
            v->u.els.scrVertex.y = points[2][1];
            break;
        case 3:
            v->u.els.scrVertex.z = z;
            v->u.els.recipZ = recipZ;
            if (r >= 0)
                v->u.els.color.r = (f32)r;
            else
            {
                tmpR = (f32)(s32)(((u32)r >> 1) | r1);
                v->u.els.color.r = tmpR + tmpR;
            }
            if (g >= 0)
                v->u.els.color.g = (f32)g;
            else
            {
                tmpG = (f32)(s32)(((u32)g >> 1) | g1);
                v->u.els.color.g = tmpG + tmpG;
            }
            v->u.els.color.b = blue;
            v->u.els.color.a = alpha3f;
            v->u.els.scrVertex.x = points[3][0];
            v->u.els.scrVertex.y = points[3][1];
            break;
    }
    }

    (*setState)(1, 0);
    (*D_009600A0)(rwPRIMTYPETRISTRIP, vertices, 4);
}
/* ------------------------------------------------------------------------- */
/* Pre-Camp sprite/effect task slice (retail 0x117440-0x119F10). */

extern const char D_005D6E48[];
extern const char D_005D6FD0[];
extern const char D_005D6FE0[];
extern const char D_005DAC00[];
extern const char D_005DAC20[];
extern const char D_005DAC40[];
extern const char D_005D7AE0[];
extern const char D_005D6E60[];
extern const char D_005D6E90[];
extern const char D_005D6EC0[];
extern const char D_005D6EE0[];
extern const char D_005D6F00[];
extern const char D_005D6F20[];
extern const char D_005D6F40[];
extern const char D_005D6F60[];
extern const char D_005D6F80[];
extern const char D_005D6F90[];
extern const char D_005D6FB8[];
extern void* D_00833B70[14];
extern KwlnTask* iGpffffb258;
extern void* iGpffffb25c;

extern void* func_00116f80();
extern void* func_001158b0();
extern void func_00115980();
extern void func_00195020(void* task);
extern void func_0018bc10(f32 duration, void* animation, s32 start,
                          s32 end, s32 mode, u64 startValues,
                          u64 endValues, u32 param8, u32 param9);
extern u32 func_0018b700(void* animation);
extern void* func_0018b6d0(s32 size);
extern u32 datGetScenarioMode(void);
extern void func_003c7b90(void);
extern void func_003c72d0(const void* message);
extern void func_003c77a0(void);
extern void* func_00117540(KwlnTask* task);
extern void func_001191c0(KwlnTask* task);
extern void* func_00119aa0(KwlnTask* task);
extern void* func_001193d0(KwlnTask* task);
extern void func_00119e00(KwlnTask* task);

typedef struct MaestroEffectAnim
{
    u8 reserved00[8];
    s32 frame;                       /* +0x08 */
    s32 startFrame;                  /* +0x0c */
    s32 endFrame;                    /* +0x10 */
    f32 depth;                       /* +0x14 */
    u8 reserved18[0x10];
    f32 x;                            /* +0x28 */
    f32 y;                            /* +0x2c */
    u8 reserved30[0x14];
} MaestroEffectAnim;

typedef struct MaestroMarkSpriteWork
{
    s32 state;
    s32 mode;
    s32 frame;
    u32 reserved0c;
    MaestroEffectAnim animation;
    void* blob;
} MaestroMarkSpriteWork;

typedef struct MaestroPerEffectWork
{
    s32 state;                       /* +0x000 */
    s32 effectCount;                 /* +0x004 */
    u32 effectIds[3];                 /* +0x008 */
    KwlnTask* streamTask;            /* +0x014 */
    u32 reserved018;
    KwlnTask* resourceTasks[3];      /* +0x01c */
    void* streams[6];                 /* +0x028 */
    void* loadedResources[6];         /* +0x040 */
    HCdvd* cdvd[9];                  /* +0x058 */
    void* recordPointers[3];         /* +0x07c */
    u8 recordData[3][0x2a];          /* +0x088 */
    u8 reserved104[2];
    s32 completionCounts[3];          /* +0x108 */
    s32 frame;                        /* +0x114 */
    u8 reserved118[0x11c];
    void* archiveCacheRequest;        /* +0x234 */
    u8 reserved238[0x5b4];
    MaestroBlobNode* blob;            /* +0x7ec */
    u8 reserved7f0[0x44];             /* +0x7f0, retail sizeof 0x834 */
} MaestroPerEffectWork;

typedef struct MaestroCampSpriteSetupWork
{
    s32 state;                        /* +0x00 */
    void* resources[14];              /* +0x04 */
    HCdvd* archive;                   /* +0x3c */
    u32 initializeMessages;           /* +0x40 */
    void* ownerPool;                  /* +0x44 */
} MaestroCampSpriteSetupWork;

// FUN_001158B0


void* func_001158b0(param_1,param_2,param_3)
int param_1;
int param_2;
int param_3;



{

  int *piVar1;

  int *piVar2;
  int *piVar3;


  

  piVar2 = (int *)(*(void* (**)(u32,u32,u32))D_00960184_abs)(1,0x34,0x40000);

  *(u8 *)(piVar2 + 0xc) = 0xff;

  *(u8 *)((int)piVar2 + 0x31) = 0xff;

  *(u8 *)((int)piVar2 + 0x32) = 0xff;

  piVar2[2] = param_2;

  piVar2[3] = param_3;

  if (param_1 == 0) {

    piVar1 = DAT_007cdf3c;

    if (DAT_007cdf3c == (int *)0x0) {
      DAT_007cdf3c = piVar2;

      piVar2[1] = 0;

    }

    else {
      while (1) {
        piVar3 = (int *)*piVar1;
        if (piVar3 == (int *)0x0) {
          *piVar1 = (int)piVar2;
          piVar2[1] = (int)piVar1;
          break;
        }
        piVar1 = piVar3;
      }
    }

  }

  else {

    *(u32 *)param_1 = (u32)piVar2;

    piVar2[1] = (int)(u32 *)param_1;

  }
  return (void *)piVar2;
}
// FUN_00115980


void func_00115980(int *param_1)



{

  int *piVar1;

  

  piVar1 = (int *)param_1[1];

  if (piVar1 == (int *)0x0) {

    DAT_007cdf3c = (int*)*param_1;

    if (DAT_007cdf3c != 0) {

      DAT_007cdf3c[1] = 0;

    }

  }

  else {

    *piVar1 = *param_1;

    if (*param_1 != 0) {

      *(int **)(*param_1 + 4) = piVar1;

    }

  }

  MAESTRO_FREE(param_1);

  return;

}
// FUN_001159F0


void func_001159f0(int unused0, int unused1, int unused2,
                   f32 param_1, f32 param_2, u8 param_4, f32 param_3)



{

  int *piVar1;

  int *piVar2;

  void* uVar3;


  

  uVar3 = func_001158b0(0);

  piVar2 = (int *)uVar3;

  ((f32 *)piVar2)[0xb] = param_3;

  ((f32 *)piVar2)[4] = param_1;

  ((f32 *)piVar2)[5] = param_2;
  *(u8 *)(piVar2 + 6) = param_4;
  FUN_001127d0(uVar3,1);

  piVar1 = (int *)piVar2[1];

  if (piVar1 == (int *)0x0) {

    DAT_007cdf3c = (int*)*piVar2;

    if (DAT_007cdf3c != 0) {

      DAT_007cdf3c[1] = 0;

    }

  }

  else {

    *piVar1 = *piVar2;

    if (*piVar2 != 0) {

      *(int **)(*piVar2 + 4) = piVar1;

    }

  }

  MAESTRO_FREE((void*)uVar3);

  return;

}
// FUN_00115AD0


void func_00115ad0(int unused0, int unused1, int unused2,
                   f32 param_1, f32 param_2, u8 param_4, u8 param_5,
                   f32 param_3)



{

  int *piVar1;

  int *piVar2;

  void* uVar3;


  

  uVar3 = func_001158b0(0);

  piVar2 = (int *)uVar3;

  ((f32 *)piVar2)[0xb] = param_3;

  ((f32 *)piVar2)[4] = param_1;

  ((f32 *)piVar2)[5] = param_2;

  *(u8 *)(piVar2 + 6) = param_4;

  *(u8 *)((int)piVar2 + 0x19) = param_5;

  FUN_001127d0(uVar3,1);

  piVar1 = (int *)piVar2[1];

  if (piVar1 == (int *)0x0) {

    DAT_007cdf3c = (int*)*piVar2;

    if (DAT_007cdf3c != 0) {

      DAT_007cdf3c[1] = 0;

    }

  }

  else {

    *piVar1 = *piVar2;

    if (*piVar2 != 0) {

      *(int **)(*piVar2 + 4) = piVar1;

    }

  }

  MAESTRO_FREE((void*)uVar3);

  return;

}
// FUN_00115BC0

void func_00115bc0(int unused0, int unused1, int unused2,
                   f32 param_1, f32 param_2, u8 param_4, u8 param_5,
                   u8 param_6, u8 param_7, f32 param_3)


{

  int *piVar2;

  int *piVar1;

  void* uVar3;




  uVar3 = func_001158b0(0);
  piVar2 = (int *)uVar3;


  ((f32 *)piVar2)[0xb] = param_3;

  ((f32 *)piVar2)[4] = param_1;

  ((f32 *)piVar2)[5] = param_2;

  *(u8 *)(piVar2 + 6) = param_4;

  *(u8 *)(piVar2 + 0xc) = param_5;

  *(u8 *)((int)piVar2 + 0x31) = param_6;

  *(u8 *)((int)piVar2 + 0x32) = param_7;

  FUN_001127d0(piVar2,1);
  piVar1 = (int *)piVar2[1];

  if (piVar1 == (int *)0x0) {

    DAT_007cdf3c = (int*)*piVar2;

    if (DAT_007cdf3c != 0) {


      DAT_007cdf3c[1] = 0;
    }

  }

  else {

    *piVar1 = *piVar2;

    if (*piVar2 != 0) {

      *(int **)(*piVar2 + 4) = piVar1;

    }

  }

  MAESTRO_FREE((void*)piVar2);

  return;

}
// FUN_00115CD0


void func_00115cd0(int unused0, int unused1, int unused2,
                   f32 param_1, f32 param_2, u8 param_4, u8 param_5,
                   u8 param_6, u8 param_7, f32 param_3)



{

  int *piVar1;

  int *piVar2;

  void* uVar3;


  

  uVar3 = func_001158b0(0);

  piVar2 = (int *)uVar3;

  ((f32 *)piVar2)[0xb] = param_3;

  ((f32 *)piVar2)[4] = param_1;

  ((f32 *)piVar2)[5] = param_2;

  *(u8 *)(piVar2 + 6) = param_4;

  *(u8 *)(piVar2 + 0xc) = param_5;

  *(u8 *)((int)piVar2 + 0x31) = param_6;

  *(u8 *)((int)piVar2 + 0x32) = param_7;

  FUN_001127d0(piVar2,0);

  piVar1 = (int *)piVar2[1];

  if (piVar1 == (int *)0x0) {

    DAT_007cdf3c = (int*)*piVar2;

    if (DAT_007cdf3c != 0) {

      DAT_007cdf3c[1] = 0;

    }

  }

  else {

    *piVar1 = *piVar2;

    if (*piVar2 != 0) {

      *(int **)(*piVar2 + 4) = piVar1;

    }

  }

  MAESTRO_FREE((void*)piVar2);

  return;

}
// FUN_00115DE0 NONMATCHING


void func_00115de0(int unused0, int unused1, int unused2,
                   f32 param_1, f32 param_2, s16 param_4, u8 param_5,
                   u8 param_6, u8 param_7, u8 param_8, f32 param_3)


{
  int *piVar1;

  int *piVar2;



  piVar1 = (int *)func_001158b0(0);
  ((f32 *)piVar1)[0xb] = param_3;

  ((f32 *)piVar1)[4] = param_1;

  ((f32 *)piVar1)[5] = param_2;

  *(u8 *)(piVar1 + 6) = param_5;

  *(u8 *)(piVar1 + 0xc) = param_6;

  *(u8 *)((int)piVar1 + 0x31) = param_7;

  *(u8 *)((int)piVar1 + 0x32) = param_8;

  ((u16 *)piVar1)[0x14] = param_4;
  ((u16 *)piVar1)[0x15] = param_4;

  FUN_001127d0(piVar1,1);

  piVar2 = (int *)piVar1[1];

  if (piVar2 == (int *)0x0) {

    DAT_007cdf3c = (int*)*piVar1;

    if (DAT_007cdf3c != 0) {
      DAT_007cdf3c[1] = 0;
    }

  }

  else {

    *piVar2 = *piVar1;

    if (*piVar1 != 0) {
      *(int **)(*piVar1 + 4) = piVar2;
    }

  }

  MAESTRO_FREE((void*)piVar1);
  return;

}
#pragma opt_loop_invariants on
// FUN_00115F00 NONMATCHING


u32 func_00115f00(KwlnTask* param_1)



{

  u32 *puVar1;

  u32 uVar2;

  u64 uVar3;

  int lVar4;

  int iVar5;

  u8 auStack_110 [256];

  u16 uStack_10;

  u16 uStack_e;

  u16 uStack_c;

  u16 uStack_a;

  u8 auStack_4 [4];

  

  puVar1 = *(u32 **)((int)param_1 + 0x3c);

  FUN_00198590();

  (*D_00960090)(6,1);

  (*D_00960090)(7,2);

  (*D_00960090)(8,1);

  (*D_00960090)(9,1);

  (*D_00960090)(0xc,1);

  (*D_00960090)(0xb,6);

  (*D_00960090)(10,5);

  switch(*puVar1) {

  case 0:

    lVar4 = FUN_0017d800();

    if ((lVar4 == 0) || (puVar1[1] != 9)) {

      lVar4 = FUN_0017d800();

      if ((lVar4 == 0) || (puVar1[1] != 1)) {

        FUN_00523ac8(auStack_110,0x5d6c90,puVar1[1]);

      }

      else {

        FUN_00523ac8(auStack_110,0x5d6c70);

      }

    }

    else {

      FUN_00523ac8(auStack_110,0x5d6c40);

    }

    uVar2 = FUN_00100d80(auStack_110,1);

    puVar1[9] = uVar2;

    *puVar1 = 1;

    break;

  case 1:

    lVar4 = FUN_001016b0(puVar1[9]);

    if (lVar4 != 0) {

      for (iVar5 = 0; iVar5 < 3; iVar5 = iVar5 + 1) {

        uVar3 = FUN_00102100(puVar1[9],iVar5,puVar1 + iVar5 * 0xd9 + 0x66);

        puVar1[iVar5 * 0xd9 + 100] = (int)uVar3;

        FUN_00102720(0x5d6cb8,uVar3);

      }

      uStack_10 = 0x28;

      uStack_e = 3;

      iVar5 = puVar1[1];

      if (iVar5 == 0xea) {

        uStack_c = 0xb;

        uStack_a = 6;

      }

      else if (iVar5 == 0xe9) {

        uStack_c = 0xb;

        uStack_a = 5;

      }

      else if (iVar5 == 0x67) {

        uStack_c = 0xb;

        uStack_a = 3;

      }

      else if (iVar5 == 0x11) {

        uStack_c = 0xb;

        uStack_a = 2;

      }

      else if (iVar5 == 0x10) {

        uStack_c = 0xb;

        uStack_a = 1;

      }

      else if (iVar5 == 0xf) {

        uStack_c = 0xb;

        uStack_a = 0;

      }

      else if (iVar5 == 10) {

        uStack_c = 10;

        uStack_a = 8;

      }

      else if (iVar5 == 9) {

        lVar4 = FUN_0017d800();

        if (lVar4 == 0) {

          uStack_c = 10;

          uStack_a = 7;

        }

        else {

          uStack_c = 0xb;

          uStack_a = 4;

        }

      }

      else if (iVar5 == 8) {

        uStack_c = 10;

        uStack_a = 6;

      }

      else if (iVar5 == 7) {

        uStack_c = 10;

        uStack_a = 5;

      }

      else if (iVar5 == 6) {

        uStack_c = 10;

        uStack_a = 9;

      }

      else if (iVar5 == 5) {

        uStack_c = 10;

        uStack_a = 4;

      }

      else if (iVar5 == 4) {

        uStack_c = 10;

        uStack_a = 3;

      }

      else if (iVar5 == 3) {

        uStack_c = 10;

        uStack_a = 2;

      }

      else if (iVar5 == 2) {

        uStack_c = 10;

        uStack_a = 1;

      }

      else if (iVar5 == 1) {

        lVar4 = FUN_0017d800();

        if (lVar4 == 0) {

          uStack_c = 10;

          uStack_a = 0;

        }

        else {

          uStack_c = 10;

          uStack_a = 2;

        }

      }

      uVar2 = FUN_00111260(param_1,CONCAT26(uStack_a,CONCAT24(uStack_c,CONCAT22(uStack_e,uStack_10))

                                           ),puVar1 + 0x1d2);

      puVar1[5] = uVar2;

      uStack_10 = 0x28;

      uStack_e = 3;

      uStack_c = 0xb;

      uStack_a = 9;

      uVar3 = FUN_00111260(param_1,0x9000b00030028,puVar1 + 0xf9);

      puVar1[4] = (int)uVar3;

      FUN_00111570(uVar3,1);

      uStack_10 = 0x28;

      uStack_e = 3;

      uStack_c = 0xb;

      uStack_a = 8;

      uVar3 = FUN_00111260(param_1,0x8000b00030028,puVar1 + 0x20);

      puVar1[3] = (int)uVar3;

      FUN_00111570(uVar3,1);

      uVar3 = FUN_00102100(puVar1[9],3,auStack_4);

      uVar2 = FUN_0034fcd0(uVar3);

      puVar1[0x2ab] = uVar2;

      uVar3 = FUN_00102100(puVar1[9],4,auStack_4);

      uVar2 = FUN_0034fcd0(uVar3);

      puVar1[0x2ac] = uVar2;

      *puVar1 = 2;

    }

    break;

  case 2:

    lVar4 = FUN_001114b0(puVar1[3]);

    if (((lVar4 != 0) && (lVar4 = FUN_001114b0(puVar1[4]), lVar4 != 0)) &&

       (lVar4 = FUN_001114b0(puVar1[5]), lVar4 != 0)) {

      *puVar1 = 3;

    }

    break;

  case 4:

    FUN_00111530(puVar1[3]);

    FUN_00111530(puVar1[4]);

    FUN_00111530(puVar1[5]);

    *puVar1 = 5;

    break;

  case 5:

    if (puVar1[5] != 0) {

      puVar1[0x1c] = puVar1[0x1c] + 1;

      lVar4 = FUN_00195290(puVar1[5]);

      if (lVar4 == 3) {

        puVar1[5] = 0;

      }

    }

    if (puVar1[0x1f] != 0) {

      iVar5 = puVar1[0x1d] + 1;

      puVar1[0x1d] = iVar5;

      if (((iVar5 != 0xf) && (0xf < iVar5)) && (puVar1[0x1b] + 0xf <= iVar5)) {

        return 0xffffffff;

      }

    }

    if (puVar1[0x1e] != 0) {

      puVar1[0x1e] = 0;

      puVar1[0x1f] = 1;

    }

  }

  return 0;

}
#pragma opt_loop_invariants off
// FUN_001165C0 NONMATCHING


void func_001165c0(int param_1)



{

  int iVar2;

  int *slot;

  int iVar1;

  int *p;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  if (*(int *)(iVar1 + 400) != 0) {

    FUN_00102870();

  }

  if (*(int *)(iVar1 + 0x4f4) != 0) {

    FUN_00102870();

  }

  if (*(int *)(iVar1 + 0x858) != 0) {

    FUN_00102870();

  }

  if (*(int *)(iVar1 + 0x24) != 0) {

    FUN_00100ec0();

    *(u32 *)(iVar1 + 0x24) = 0;

  }

  p = (int *)iVar1;
  for (iVar2 = 0; iVar2 < 2; iVar2 = iVar2 + 1) {
    slot = p + iVar2 + 0x2ab;
    if (*slot != 0) {
      FUN_0034fcf0();
      *slot = 0;
    }
  }

  MAESTRO_FREE((void*)iVar1);

  return;

}
// FUN_001166A0
void* func_001166a0(KwlnTask* parent, u32 param_2, u32 param_3)
{
    void* work;
    KwlnTask* task;

    work = MAESTRO_ALLOC(1, 0xab4, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = (KwlnTask*)FUN_00194b80(parent, 0x106f, D_005D6CD0,
                                   func_00115f00, func_001165c0, work);
    if (task == NULL)
    {
        return NULL;
    }
    *(u32*)((u8*)work + 4) = param_2;
    *(u32*)((u8*)work + 8) = param_3;
    return task;
}
// FUN_00116760


u8 func_00116760(int param_1)



{

  return **(int **)(param_1 + 0x3c) == 3;

}
// FUN_00116780


void func_00116780(int param_1)



{

  **(u32 **)(param_1 + 0x3c) = 4;

  return;

}
// FUN_001167A0


void func_001167a0(int param_1)



{

  *(u32 *)(*(int *)(param_1 + 0x3c) + 0x78) = 1;

  return;

}
// FUN_001167C0


u32 func_001167c0(int param_1,u32 param_2)



{

  u32 base;
  u32 idx;

  base = *(u32 *)(param_1 + 0x3c);

  if (param_2 == 0) {

    return 0x33;

  }

  idx = param_2 * 4;

  idx += base;

  return *(u32 *)(idx + 0x68);

}
#pragma opt_loop_invariants on
// FUN_001167F0 NONMATCHING


u32 func_001167f0(u64 param_1)



{

  u32 *puVar1;

  u32 uVar2;

  u64 uVar3;

  int lVar4;

  int iVar5;

  u8 auStack_110 [256];

  u16 uStack_10;

  u16 uStack_e;

  u16 uStack_c;

  u16 uStack_a;

  u8 auStack_4 [4];

  

  puVar1 = *(u32 **)((int)param_1 + 0x3c);

  FUN_00198590();

  (*D_00960090)(6,1);

  (*D_00960090)(7,2);

  (*D_00960090)(8,1);

  (*D_00960090)(9,1);

  (*D_00960090)(0xc,1);

  (*D_00960090)(0xb,6);

  (*D_00960090)(10,5);

  switch(*puVar1) {

  case 0:

    switch(puVar1[1]) {

    default:

      FUN_00523ac8(auStack_110,0x5d6ce0);

      break;

    case 2:

      FUN_00523ac8(auStack_110,0x5d6ce0);

      break;

    case 3:

      FUN_00523ac8(auStack_110,0x5d6d00);

      break;

    case 4:

      FUN_00523ac8(auStack_110,0x5d6d20);

      break;

    case 5:

      FUN_00523ac8(auStack_110,0x5d6d40);

      break;

    case 7:

      FUN_00523ac8(auStack_110,0x5d6d60);

      break;

    case 8:

      FUN_00523ac8(auStack_110,0x5d6d80);

      break;

    case 9:

      lVar4 = FUN_0017d800();

      if (lVar4 == 0) {

        FUN_00523ac8(auStack_110,0x5d6dc0);

      }

      else {

        FUN_00523ac8(auStack_110,0x5d6da0);

      }

      break;

    case 10:

      FUN_00523ac8(auStack_110,0x5d6de0);

    }

    uVar2 = FUN_00100d80(auStack_110,1);

    puVar1[9] = uVar2;

    *puVar1 = 1;

    break;

  case 1:

    lVar4 = FUN_001016b0(puVar1[9]);

    if (lVar4 != 0) {

      for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {

        uVar3 = FUN_00102100(puVar1[9],iVar5,puVar1 + iVar5 * 0xd9 + 0x62);

        puVar1[iVar5 * 0xd9 + 0x60] = (int)uVar3;

        FUN_00102720(0x5d6e00,uVar3);

      }

      uStack_10 = 0x29;

      uStack_e = 4;

      uStack_c = 10;

      switch(puVar1[1]) {

      default:

        uStack_a = 0;

        break;

      case 2:

        uStack_a = 0;

        break;

      case 3:

        uStack_a = 1;

        break;

      case 4:

        uStack_a = 2;

        break;

      case 5:

        uStack_a = 3;

        break;

      case 7:

        uStack_a = 4;

        break;

      case 8:

        uStack_a = 5;

        break;

      case 9:

        lVar4 = FUN_0017d800();

        if (lVar4 == 0) {

          uStack_a = 6;

        }

        else {

          uStack_a = 8;

        }

        break;

      case 10:

        uStack_a = 7;

      }

      uVar2 = FUN_00111260(param_1,CONCAT26(uStack_a,CONCAT24(uStack_c,CONCAT22(uStack_e,uStack_10))

                                           ),puVar1 + 0x1c);

      puVar1[2] = uVar2;

      uVar3 = FUN_00102100(puVar1[9],1,auStack_4);

      uVar2 = FUN_00112420(uVar3);

      puVar1[0x1ce] = uVar2;

      *puVar1 = 2;

    }

    break;

  case 2:

    lVar4 = FUN_001114b0(puVar1[2]);

    if ((lVar4 != 0) && (lVar4 = FUN_00111f30(puVar1[0x1ce]), lVar4 != 0)) {

      FUN_00111520(puVar1[2],0x32);

      *puVar1 = 3;

    }

    break;

  case 4:

    FUN_00111530(puVar1[2]);

    uVar2 = FUN_00117490(param_1,puVar1[0x1ce]);

    puVar1[4] = uVar2;

    *puVar1 = 5;

    break;

  case 5:

    iVar5 = puVar1[0x19];

    if (iVar5 < 0x32) {

      puVar1[0x19] = iVar5 + 1;

    }

    else if (puVar1[0x1b] != 0) {

      puVar1[0x19] = iVar5 + 1;

      FUN_00111500(puVar1[2]);

    }

    lVar4 = FUN_00195290(puVar1[2]);

    if (lVar4 == 3) {

      return 0xffffffff;

    }

  }

  return 0;

}
#pragma opt_loop_invariants off
// FUN_00116CF0 NONMATCHING


void func_00116cf0(int param_1)
{
    u8* work;
    s32 i;
    s32 j;

    work = *(u8**)(param_1 + 0x3c);
    func_001124b0(*(void**)(work + 0x738));

    for (i = 0; i < 2; i++)
    {
        u8* entry;
        u32* slot;

        entry = work + i * 0x364;
        slot = (u32*)(entry + 0x180);
        if (*(void**)(entry + 0x180) != NULL)
        {
            H_Cdvd_CacheRemove(*(void**)(entry + 0x180));
            *slot = 0;
        }
    }

    for (j = 0; j < 3; j++)
    {
        u8* entry;
        u32* slot;

        entry = work + j * 4;
        slot = (u32*)(entry + 0x24);
        if (*(void**)(entry + 0x24) != NULL)
        {
            FUN_00100ec0(*(void**)(entry + 0x24));
            *slot = 0;
        }
    }

    for (j = 0; j < 2; j++)
    {
        u8* entry;
        u32* slot;

        entry = work + j * 4;
        slot = (u32*)(entry + 0x1c);
        if (*(void**)(entry + 0x1c) != NULL)
        {
            func_004d0f00(*(void**)(entry + 0x1c));
            *slot = 0;
        }
    }

    MAESTRO_FREE(work);
}

// FUN_00116E20
void* func_00116e20(KwlnTask* parent, u32 param_2)
{
    void* work;
    KwlnTask* task;

    work = MAESTRO_ALLOC(1, 0x73c, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = (KwlnTask*)FUN_00194b80(parent, 0x106f, D_005D6E10,
                                   func_001167f0, func_00116cf0, work);
    if (task == NULL)
    {
        return NULL;
    }
    *(u32*)((u8*)work + 4) = param_2;
    return task;
}
// FUN_00116ED0


u8 func_00116ed0(int param_1)



{

  return **(int **)(param_1 + 0x3c) == 3;

}
// FUN_00116EF0


void func_00116ef0(int param_1)



{

  **(u32 **)(param_1 + 0x3c) = 4;

  return;

}
// FUN_00116F10


u32 func_00116f10(void)



{

  return 0x3f;

}
// FUN_00116F20


u32 func_00116f20(int param_1)



{

  return *(u32 *)(*(int *)(param_1 + 0x3c) + 100);

}
// FUN_00116F30


u32 func_00116f30(int param_1)



{

  return 0x31 < *(int *)(*(int *)(param_1 + 0x3c) + 100);

}
// FUN_00116F50


void func_00116f50(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  *(u32 *)(iVar1 + 0x6c) = 1;

  FUN_00117470(*(u32 *)(iVar1 + 0x10));

  return;

}
// FUN_00116F80 NONMATCHING


void* func_00116f80(KwlnTask* task)



{

  int param_1 = (int)task;

  int *piVar1;

  int iVar2;

  int lVar3;

  u32 uVar4;

  u32 uVar5;

  int iVar6;

  

  piVar1 = *(int **)(param_1 + 0x3c);

  iVar2 = *piVar1;

  if (iVar2 == 4) {

    lVar3 = FUN_0018b700(piVar1 + 5);

    if (lVar3 != 0) {

      if (piVar1[0xd] == piVar1[0xb]) {

        piVar1[1] = 0;

        return (void *)0xffffffff;

      }

      uVar4 = (u32)func_001158b0(0,piVar1[4],0);

      iVar2 = (int)uVar4;

      *(u32 *)(iVar2 + 0x2c) = 0x42c80000;

      *(int *)(iVar2 + 0x10) = piVar1[0x13];

      *(int *)(iVar2 + 0x14) = piVar1[0x14];

      *(u16 *)(iVar2 + 0x24) = 0x10;

      *(u16 *)(iVar2 + 0x26) = 0x60;

      *(char *)(iVar2 + 0x18) = (char)piVar1[0x15];

      FUN_001127d0(uVar4,1);

      func_00115980((int*)uVar4);

    }

  }

  else if (iVar2 == 3) {

    lVar3 = FUN_0018b700(piVar1 + 5);

    if (lVar3 != 0) {

      uVar4 = (u32)func_001158b0(0,piVar1[4],0);

      iVar2 = (int)uVar4;

      *(u32 *)(iVar2 + 0x2c) = 0x42c80000;

      *(int *)(iVar2 + 0x10) = piVar1[0x13];

      *(int *)(iVar2 + 0x14) = piVar1[0x14];

      *(u16 *)(iVar2 + 0x24) = 0x10;

      *(u16 *)(iVar2 + 0x26) = 0x60;

      *(u8 *)(iVar2 + 0x18) = 0;

      FUN_001127d0(uVar4,1);

      func_00115980((int*)uVar4);

    }

    if (piVar1[3] != 0) {

      FUN_0018bc10(0x42c80000,piVar1 + 5,0,2,2,0x42f00000433b0000,0x42f00000433b0000,0,0);

      *piVar1 = 4;

    }

  }

  else if (iVar2 == 2) {

    lVar3 = FUN_0018b700(piVar1 + 5);

    if (lVar3 != 0) {

      uVar4 = (u32)func_001158b0(0,piVar1[4],0);

      iVar2 = piVar1[1];

      iVar6 = iVar2 + 1;

      piVar1[1] = iVar6;

      if (iVar6 < 3) {

        iVar2 = (int)((u32)((long)(iVar6 * 0xf) << 0x21) >> 0x20);

        if (iVar6 * 0x1e < 0) {

          iVar2 = iVar6 * 0x1e + 1;

        }

        iVar2 = 0x14 - (iVar2 >> 1);

      }

      else if (iVar6 < 6) {

        iVar2 = iVar2 + -2;

        iVar6 = iVar2 * 10;

        iVar2 = (int)((u32)((long)(iVar2 * 5) << 0x21) >> 0x20);

        if (iVar6 < 0) {

          iVar2 = iVar6 + 1;

        }

        iVar2 = (iVar2 >> 1) + -10;

      }

      else {

        iVar2 = 0;

        *piVar1 = 3;

        piVar1[1] = 0;

      }

      iVar6 = (int)uVar4;

      *(float *)(iVar6 + 0x20) = (float)iVar2;

      *(u32 *)(iVar6 + 0x2c) = 0x42c80000;

      *(int *)(iVar6 + 0x10) = piVar1[0x13];

      *(int *)(iVar6 + 0x14) = piVar1[0x14];

      *(u16 *)(iVar6 + 0x24) = 0x10;

      *(u16 *)(iVar6 + 0x26) = 0x60;

      *(u8 *)(iVar6 + 0x18) = 0;

      FUN_001127d0(uVar4,1);

      func_00115980((int*)uVar4);

    }

  }

  else if (iVar2 == 1) {

    lVar3 = FUN_0018b700(piVar1 + 5);

    if (lVar3 != 0) {

      uVar4 = FUN_00530da0(piVar1[0x11]);

      uVar5 = FUN_00530da0(piVar1[0x13]);

      FUN_005225a8(0x5d6e20,uVar4,uVar5);

      if (piVar1[0xd] == piVar1[0xb]) {

        piVar1[1] = 0;

        *piVar1 = 2;

      }

      uVar4 = (u32)func_001158b0(0,piVar1[4],0);

      iVar6 = (int)uVar4;

      *(u32 *)(iVar6 + 0x2c) = 0x42c80000;

      *(int *)(iVar6 + 0x10) = piVar1[0x13];

      *(int *)(iVar6 + 0x14) = piVar1[0x14];

      *(u16 *)(iVar6 + 0x24) = 0x10;

      *(u16 *)(iVar6 + 0x26) = 0x60;

      iVar2 = (4 - (piVar1[0xd] - piVar1[0xb])) * 0x19;

      if (iVar2 < 0) {

        iVar2 = iVar2 + 3;

      }

      *(float *)(iVar6 + 0x20) = (float)((iVar2 >> 2) + -5);

      *(u8 *)(iVar6 + 0x18) = 0;

      FUN_001127d0(uVar4,1);

      func_00115980((int*)uVar4);

    }

  }

  else if (iVar2 == 0) {

    FUN_0018bc10(0x42c80000,piVar1 + 5,0,2,0,0x42f0000044268000,0x42f00000433b0000,0,0);

    *piVar1 = 1;

  }

  return (void *)0;

}
// FUN_00117440
void func_00117440(KwlnTask* task)
{
    MAESTRO_FREE(task->workData);
}

// FUN_00117470
void func_00117470(KwlnTask* task)
{
    *(u32*)((u8*)task->workData + 0x0c) = 1;
}

// FUN_00117490
KwlnTask* func_00117490(KwlnTask* parent, void* blob)
{
    void* work;
    KwlnTask* task;

    work = MAESTRO_ALLOC(1, 0x58, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent, D_005D6E48, 0x18b5,
                          func_00116f80, func_00117440, work);
    if (task == NULL)
    {
        return NULL;
    }
    *(void**)((u8*)work + 0x10) = blob;
    return task;
}

// FUN_001191C0
void func_001191c0(KwlnTask* task)
{
    MaestroPerEffectWork* work;
    void** entry;

    work = (MaestroPerEffectWork*)task->workData;
    if (work->archiveCacheRequest != NULL)
    {
        H_Cdvd_CacheRemove(work->archiveCacheRequest);
    }
    func_001124b0(work->blob);
    {
        s32 i;

        for (i = 0; i < 9; i++)
        {
            entry = (void**)&work->cdvd[i];
            if (work->cdvd[i] != NULL)
            {
                H_Cdvd_Destroy(work->cdvd[i]);
                *entry = NULL;
            }
        }
    }
    {
        s32 i;

        for (i = 0; i < 6; i++)
        {
            entry = &work->loadedResources[i];
            if (work->loadedResources[i] != NULL)
            {
                func_004d0f00(work->loadedResources[i]);
                *entry = NULL;
            }
        }
    }
    MAESTRO_FREE(work);
}

// FUN_001192B0
KwlnTask* func_001192b0(KwlnTask* parent, const u32* config)
{
    MaestroPerEffectWork* work;
    KwlnTask* task;

    work = (MaestroPerEffectWork*)MAESTRO_ALLOC(1, sizeof(MaestroPerEffectWork), 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent, D_005D6FD0, 0x18bf,
                          func_00117540, func_001191c0, work);
    if (task == NULL)
    {
        return NULL;
    }
    work->effectIds[0] = config[0];
    work->effectIds[1] = config[1];
    work->effectIds[2] = config[2];
    return task;
}

// FUN_00119380
u32 func_00119380(KwlnTask* task)
{
    return ((MaestroMarkSpriteWork*)task->workData)->state == 3;
}

// FUN_001193A0
void func_001193a0(KwlnTask* task)
{
    ((MaestroMarkSpriteWork*)task->workData)->state = 4;
}

// FUN_001193C0
u32 func_001193c0(void)
{
    return 0x28;
}

// FUN_00119930
void func_00119930(KwlnTask* task)
{
    MAESTRO_FREE(task->workData);
}

// FUN_00119960
KwlnTask* func_00119960(KwlnTask* parent, u32 effectType, void* blob)
{
    MaestroMarkSpriteWork* work;
    KwlnTask* task;

    work = (MaestroMarkSpriteWork*)MAESTRO_ALLOC(1, 0x58, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent, D_005D6FE0, 0x18c1,
                          func_001193d0, func_00119930, work);
    if (task == NULL)
    {
        return NULL;
    }
    work->blob = blob;
    work->mode = effectType;
    return task;
}

// FUN_00119A20
void func_00119a20(void)
{
    s32 i = 0;
    void** table = D_00833B70;

    for (; i < 14; i++)
    {
        table[i] = NULL;
    }
}

// FUN_00119A60
void* func_00119a60(s32 index)
{
    return D_00833B70[index];
}

// FUN_00119A80
void func_00119a80(s32 index, void* resource)
{
    D_00833B70[index] = resource;
}

// FUN_00119F10
KwlnTask* func_00119f10(KwlnTask* parent, u32 initializeMessages)
{
    MaestroCampSpriteSetupWork* work;
    KwlnTask* task;

    if (iGpffffb258 != NULL)
    {
        return NULL;
    }
    work = (MaestroCampSpriteSetupWork*)MAESTRO_ALLOC(1, 0x48, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent, D_005DAC00, 0x18bf,
                          func_00119aa0, func_00119e00, work);
    if (task == NULL)
    {
        return NULL;
    }
    iGpffffb258 = task;
    if (datGetScenarioMode() != 0)
    {
        work->archive = H_Cdvd_Request(D_005DAC20, 1);
    }
    else
    {
        work->archive = H_Cdvd_Request(D_005DAC40, 1);
    }
    work->initializeMessages = initializeMessages;
    if (initializeMessages != 0)
    {
        func_003c72d0(D_005D7AE0);
    }
    return task;
}
static void MaestroMarkSpriteDraw(MaestroMarkSpriteWork* work,
                                  s16 pivotX,
                                  s16 pivotY,
                                  f32 angle,
                                  u8 alphaCutoff)
{
    MaestroRenderNode* node;

    node = (MaestroRenderNode*)func_001158b0(NULL, work->blob, 0);
    node->depth = work->animation.depth;
    node->x = work->animation.x;
    node->y = work->animation.y;
    node->pivotX = pivotX;
    node->pivotY = pivotY;
    node->angle = angle;
    node->alphaCutoff = alphaCutoff;
    func_001127d0(node, true);
    func_00115980((int*)node);
}

// FUN_001193D0 NONMATCHING
void* func_001193d0(KwlnTask* task)
{
    MaestroMarkSpriteWork* work;
    s32 frame;
    s32 duration;
    s32 scale;

    work = (MaestroMarkSpriteWork*)task->workData;
    switch (work->state)
    {
    case 0:
        if (work->mode == 2)
        {
            func_0018bc10(100.0f, &work->animation, 0, 2, 0,
                          0xc298000043280000ULL,
                          0x430d000043840000ULL, 0, 0);
        }
        else if (work->mode == 1)
        {
            func_0018bc10(100.0f, &work->animation, 0, 2, 0,
                          0xc31e000042a80000ULL,
                          0x4298000043630000ULL, 0, 0);
        }
        else if (work->mode == 0)
        {
            func_0018bc10(100.0f, &work->animation, 0, 2, 0,
                          0xc298000043280000ULL,
                          0x430d000043840000ULL, 0, 0);
        }
        work->state = 1;
        break;

    case 1:
        if (func_0018b700(&work->animation) != 0)
        {
            frame = work->animation.frame - work->animation.startFrame;
            duration = work->animation.endFrame - work->animation.startFrame;
            scale = 0x34cc - (0x24cc * frame) / duration;
            {
                MaestroRenderNode* node;
                node = (MaestroRenderNode*)func_001158b0(NULL, work->blob, 0);
                node->depth = work->animation.depth;
                node->x = work->animation.x;
                node->y = work->animation.y;
                node->xScale = (u16)scale;
                node->yScale = (u16)scale;
                node->pivotX = (s16)((scale * 0x10) >> 12);
                node->pivotY = (s16)((scale * 0x60) >> 12);
                node->angle = (f32)((frame * 0x1e) / duration - 0x32);
                node->alphaCutoff = 0;
                func_001127d0(node, true);
                func_00115980((int*)node);
            }
            if (work->animation.frame == work->animation.endFrame)
            {
                work->frame = 0;
                work->state = 2;
            }
        }
        break;

    case 2:
        work->frame++;
        {
            MaestroRenderNode* node;
            node = (MaestroRenderNode*)func_001158b0(NULL, work->blob, 0);
            node->depth = work->animation.depth;
            node->x = work->animation.x;
            node->y = work->animation.y;
            node->pivotX = 0x10;
            node->pivotY = 0x60;
            node->angle = (f32)((work->frame * 0x1e) / 3 - 0x14);
            node->alphaCutoff = 0;
            func_001127d0(node, true);
            func_00115980((int*)node);
        }
        if (work->frame == 3)
        {
            work->frame = 0;
            work->state = 3;
        }
        break;

    case 3:
        work->frame++;
        {
            MaestroRenderNode* node;
            node = (MaestroRenderNode*)func_001158b0(NULL, work->blob, 0);
            node->depth = work->animation.depth;
            node->x = work->animation.x;
            node->y = work->animation.y;
            node->pivotX = 0x10;
            node->pivotY = 0x60;
            node->angle = (f32)(10 - (work->frame * 10) / 3);
            node->alphaCutoff = 0;
            func_001127d0(node, true);
            func_00115980((int*)node);
        }
        if (work->frame == 2)
        {
            work->frame = 0;
            work->state = 4;
        }
        break;

    case 4:
        work->frame++;
        {
            MaestroRenderNode* node;
            node = (MaestroRenderNode*)func_001158b0(NULL, work->blob, 0);
            node->depth = work->animation.depth;
            node->x = work->animation.x;
            node->y = work->animation.y;
            node->pivotX = 0x10;
            node->pivotY = 0x60;
            node->angle = 0.0f;
            node->alphaCutoff = work->frame < 0x0f
                              ? 0
                              : (u8)(((work->frame - 0x0f) * 0xff) / 3);
            func_001127d0(node, true);
            func_00115980((int*)node);
        }
        if (work->frame == 0x12)
        {
            return KWLNTASK_STOP;
        }
        break;
    }
    return KWLNTASK_CONTINUE;
}

static inline void MaestroEffectRequestFiles(
    MaestroPerEffectWork* work, char* path)
{
    s32 i;

    work->effectCount = 0;
    for (i = 0; i < 3; i++)
    {
        if (work->effectIds[i] != 0)
        {
            work->effectCount++;
        }
    }
    if (work->effectCount != 0)
    {
        work->effectCount--;
    }

    if (datGetScenarioMode() != 0)
    {
        if (work->effectCount == 0)
        {
            if (work->effectIds[0] == 9)
                sprintf(path, D_005D6E60, work->effectIds[0]);
            else
                sprintf(path, D_005D6E90, work->effectIds[0]);
            work->cdvd[1] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            work->cdvd[0] = H_Cdvd_Request(D_005D6EC0, HCDVD_FILEARCHIVE);
        }
        else if (work->effectCount == 1)
        {
            if (work->effectIds[0] == 9)
                sprintf(path, D_005D6E60, work->effectIds[0]);
            else
                sprintf(path, D_005D6E90, work->effectIds[0]);
            work->cdvd[1] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            if (work->effectIds[1] == 9)
                sprintf(path, D_005D6E60, work->effectIds[1]);
            else
                sprintf(path, D_005D6E90, work->effectIds[1]);
            work->cdvd[2] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            work->cdvd[0] = H_Cdvd_Request(D_005D6EE0, HCDVD_FILEARCHIVE);
        }
        else
        {
            if (work->effectIds[0] == 9)
                sprintf(path, D_005D6E60, work->effectIds[0]);
            else
                sprintf(path, D_005D6E90, work->effectIds[0]);
            work->cdvd[1] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            if (work->effectIds[1] == 9)
                sprintf(path, D_005D6E60, work->effectIds[1]);
            else
                sprintf(path, D_005D6E90, work->effectIds[1]);
            work->cdvd[2] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            if (work->effectIds[2] == 9)
                sprintf(path, D_005D6E60, work->effectIds[2]);
            else
                sprintf(path, D_005D6E90, work->effectIds[2]);
            work->cdvd[3] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            work->cdvd[0] = H_Cdvd_Request(D_005D6F00, HCDVD_FILEARCHIVE);
        }
    }
    else
    {
        if (work->effectCount == 0)
        {
            sprintf(path, D_005D6E90, work->effectIds[0]);
            work->cdvd[1] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            work->cdvd[0] = H_Cdvd_Request(D_005D6F20, HCDVD_FILEARCHIVE);
        }
        else if (work->effectCount == 1)
        {
            sprintf(path, D_005D6E90, work->effectIds[0]);
            work->cdvd[1] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            sprintf(path, D_005D6E90, work->effectIds[1]);
            work->cdvd[2] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            work->cdvd[0] = H_Cdvd_Request(D_005D6F40, HCDVD_FILEARCHIVE);
        }
        else
        {
            sprintf(path, D_005D6E90, work->effectIds[0]);
            work->cdvd[1] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            sprintf(path, D_005D6E90, work->effectIds[1]);
            work->cdvd[2] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            sprintf(path, D_005D6E90, work->effectIds[2]);
            work->cdvd[3] = H_Cdvd_Request(path, HCDVD_FILENORMAL);
            work->cdvd[0] = H_Cdvd_Request(D_005D6F60, HCDVD_FILEARCHIVE);
        }
    }
}

static inline void MaestroEffectLoadRecords(KwlnTask* task, MaestroPerEffectWork* work)
{
    u8* record;
    u32 size;
    s32 i;
    s32 j;

    for (i = 0; i <= work->effectCount; i++)
    {
        record = (u8*)H_Cdvd_ArchiveGetFile(work->cdvd[0], i + 1, &size);
        memcpy(work->recordData[i], record, 0x2a);
        record = (u8*)H_Cdvd_ArchiveGetFile(work->cdvd[0], i + 1, &size) + 0x2a;
        work->recordPointers[i] = record;
        work->completionCounts[i] = 0;
        for (j = 0; j < 1000; j++)
        {
            if (record[j * 0x12 + 1] == (u8)-2)
            {
                work->completionCounts[i]--;
                break;
            }
            if (record[j * 0x12 + 1] == (u8)-1)
            {
                work->completionCounts[i]++;
            }
        }
        work->resourceTasks[i] = func_001103e0(
            task, 0x18c0, (u32)(uintptr_t)record,
            *(s16*)(work->recordData[i] + 8));
        for (j = 0; j < 3; j++)
        {
            s16 slot = (s16)(j == 2 ? 1 : (j == 0 ? 3 : 4));
            func_00110620(work->resourceTasks[i], slot,
                          *(s16*)(work->recordData[i] + 0x0a + j * 2),
                          *(s16*)(work->recordData[i] + 0x12 + j * 2),
                          *(s16*)(work->recordData[i] + 0x1a + j * 2));
        }
    }
    work->blob = (MaestroBlobNode*)func_00112420(
        H_Cdvd_ArchiveGetFile(work->cdvd[0], 0, &size));
    work->state = 2;
}

static inline void MaestroEffectStartStreams(
    KwlnTask* task, MaestroPerEffectWork* work, char* path)
{
    s16 dimensions[4];
    u32 size;
    u32 scenario;
    scenario = datGetScenarioMode();
    if (scenario != 0)
    {
        if (work->effectCount == 0)
        {
            if (work->effectIds[0] == 9)
                sprintf(path, D_005D6E60, work->effectIds[0]);
            else
                sprintf(path, D_005D6E90, work->effectIds[0]);
            work->streams[0] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0xf6);
            work->streams[1] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0xf7);
            work->archiveCacheRequest = H_Cdvd_ArchiveGetFile(
                work->cdvd[0], 3, &size);
            func_00102720(D_005D6FB8, work->archiveCacheRequest);
            dimensions[0] = 0x28;
            dimensions[1] = 1;
            dimensions[2] = 0x0a;
            dimensions[3] = 5;
            work->streamTask = func_00111380(task, 0x18c0,
                ((u64)(u16)dimensions[0]) |
                ((u64)(u16)dimensions[1] << 16) |
                ((u64)(u16)dimensions[2] << 32) |
                ((u64)(u16)dimensions[3] << 48),
                (u8*)work + 0x124);
        }
        else if (work->effectCount == 1)
        {
            if (work->effectIds[0] == 9)
                sprintf(path, D_005D6E60, work->effectIds[0]);
            else
                sprintf(path, D_005D6E90, work->effectIds[0]);
            work->streams[0] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x10c);
            work->streams[1] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x10d);
            if (work->effectIds[1] == 9)
                sprintf(path, D_005D6E60, work->effectIds[1]);
            else
                sprintf(path, D_005D6E90, work->effectIds[1]);
            work->streams[2] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x113);
            work->streams[3] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x115);
            work->archiveCacheRequest = H_Cdvd_ArchiveGetFile(
                work->cdvd[0], 4, &size);
            func_00102720(D_005D6FB8, work->archiveCacheRequest);
            dimensions[0] = 0x28;
            dimensions[1] = 1;
            dimensions[2] = 0x0b;
            dimensions[3] = 5;
            work->streamTask = func_00111380(task, 0x18c0,
                ((u64)(u16)dimensions[0]) |
                ((u64)(u16)dimensions[1] << 16) |
                ((u64)(u16)dimensions[2] << 32) |
                ((u64)(u16)dimensions[3] << 48),
                (u8*)work + 0x124);
        }
        else
        {
            if (work->effectIds[0] == 9)
                sprintf(path, D_005D6E60, work->effectIds[0]);
            else
                sprintf(path, D_005D6E90, work->effectIds[0]);
            work->streams[0] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x12b);
            work->streams[1] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x12c);
            if (work->effectIds[1] == 9)
                sprintf(path, D_005D6E60, work->effectIds[1]);
            else
                sprintf(path, D_005D6E90, work->effectIds[1]);
            work->streams[2] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x132);
            work->streams[3] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x133);
            if (work->effectIds[2] == 9)
                sprintf(path, D_005D6E60, work->effectIds[2]);
            else
                sprintf(path, D_005D6E90, work->effectIds[2]);
            work->streams[4] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x139);
            work->streams[5] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x13a);
            work->archiveCacheRequest = H_Cdvd_ArchiveGetFile(
                work->cdvd[0], 5, &size);
            func_00102720(D_005D6FB8, work->archiveCacheRequest);
            dimensions[0] = 0x28;
            dimensions[1] = 2;
            dimensions[2] = 0x0a;
            dimensions[3] = 5;
            work->streamTask = func_00111380(task, 0x18c0,
                ((u64)(u16)dimensions[0]) |
                ((u64)(u16)dimensions[1] << 16) |
                ((u64)(u16)dimensions[2] << 32) |
                ((u64)(u16)dimensions[3] << 48),
                (u8*)work + 0x124);
        }
    }
    else
    {
        if (work->effectCount == 0)
        {
            sprintf(path, D_005D6E90, work->effectIds[0]);
            work->streams[0] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x14d);
            work->streams[1] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x14e);
            work->archiveCacheRequest = H_Cdvd_ArchiveGetFile(
                work->cdvd[0], 3, &size);
            func_00102720(D_005D6FB8, work->archiveCacheRequest);
            dimensions[0] = 0x28;
            dimensions[1] = 1;
            dimensions[2] = 0x0a;
            dimensions[3] = 0;
            work->streamTask = func_00111380(task, 0x18c0,
                ((u64)(u16)dimensions[0]) |
                ((u64)(u16)dimensions[1] << 16) |
                ((u64)(u16)dimensions[2] << 32) |
                ((u64)(u16)dimensions[3] << 48),
                (u8*)work + 0x124);
        }
        else if (work->effectCount == 1)
        {
            sprintf(path, D_005D6E90, work->effectIds[0]);
            work->streams[0] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x15e);
            work->streams[1] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x15f);
            sprintf(path, D_005D6E90, work->effectIds[1]);
            work->streams[2] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x161);
            work->streams[3] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x162);
            work->archiveCacheRequest = H_Cdvd_ArchiveGetFile(
                work->cdvd[0], 4, &size);
            func_00102720(D_005D6FB8, work->archiveCacheRequest);
            dimensions[0] = 0x28;
            dimensions[1] = 1;
            dimensions[2] = 0x0a;
            dimensions[3] = 0;
            work->streamTask = func_00111380(task, 0x18c0,
                ((u64)(u16)dimensions[0]) |
                ((u64)(u16)dimensions[1] << 16) |
                ((u64)(u16)dimensions[2] << 32) |
                ((u64)(u16)dimensions[3] << 48),
                (u8*)work + 0x124);
        }
        else
        {
            sprintf(path, D_005D6E90, work->effectIds[0]);
            work->streams[0] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x172);
            work->streams[1] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x174);
            sprintf(path, D_005D6E90, work->effectIds[1]);
            work->streams[2] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x176);
            work->streams[3] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x178);
            sprintf(path, D_005D6E90, work->effectIds[2]);
            work->streams[4] = func_0010c1a0(NULL, path,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x17a);
            work->streams[5] = func_0010c1a0(NULL, D_005D6F90,
                                              0, 0, 0, 0, 0, 0,
                                              D_005D6FB8, 0x17c);
            work->archiveCacheRequest = H_Cdvd_ArchiveGetFile(
                work->cdvd[0], 5, &size);
            func_00102720(D_005D6FB8, work->archiveCacheRequest);
            dimensions[0] = 0x28;
            dimensions[1] = 2;
            dimensions[2] = 0x0a;
            dimensions[3] = 0;
            work->streamTask = func_00111380(task, 0x18c0,
                ((u64)(u16)dimensions[0]) |
                ((u64)(u16)dimensions[1] << 16) |
                ((u64)(u16)dimensions[2] << 32) |
                ((u64)(u16)dimensions[3] << 48),
                (u8*)work + 0x124);
        }
    }

}

static inline void MaestroEffectSetReady(MaestroPerEffectWork* work)
{
    s32 i;

    for (i = 0; i < 3; i++)
    {
        if (work->resourceTasks[i] != NULL)
        {
            func_001104d0(work->resourceTasks[i]);
        }
    }
    func_00111530(work->streamTask);
    work->state = 4;
}

#pragma push
#pragma opt_common_subs off
// FUN_00117540 NONMATCHING
void* func_00117540(KwlnTask* task)
{
    MaestroPerEffectWork* work;
    char path[0x140];
    void (**stateFn)(u32, u32);
    u32 ready;
    u32 size;
    s32 i;
    s32 j;
    s32 frame;
    s32 segment;
    s32 radius;

    work = (MaestroPerEffectWork*)task->workData;
    kwlnGetMainCamera();
    stateFn = (void (**)(u32, u32))D_00960090_abs;
    (*stateFn)(6, 1);
    (*stateFn)(7, 2);
    (*stateFn)(8, 1);
    (*stateFn)(9, 1);
    (*stateFn)(12, 1);
    (*stateFn)(11, 6);
    (*stateFn)(10, 5);

    switch (work->state)
    {
    case 0:
        MaestroEffectRequestFiles(work, path + 0x30);
        work->state = 1;
        break;
    case 3:
        break;
    case 1:
        ready = true;
        for (i = 0; i < 9; i++)
        {
            if (work->cdvd[i] != NULL &&
                H_Cdvd_IsFileLoaded(work->cdvd[i]) == 0)
            {
                ready = false;
            }
        }
        if (ready)
        {
            MaestroEffectLoadRecords(task, work);
            MaestroEffectStartStreams(task, work, path + 0x30);
        }
        break;
    case 2:
        ready = H_Maestro_00111f30((s16*)work->blob);
        for (i = 0; i < 6; i++)
        {
            if (work->loadedResources[i] == NULL && work->streams[i] != NULL)
            {
                work->loadedResources[i] = func_0010c3a0(work->streams[i],
                                                         &size, 0);
                if (size == 0)
                {
                    ready = false;
                }
                else
                {
                    work->streams[i] = NULL;
                }
            }
        }
        for (i = 0; i < 3; i++)
        {
            if (work->resourceTasks[i] != NULL &&
                func_001104b0(work->resourceTasks[i]) == 0)
            {
                ready = false;
            }
        }
        if (ready != 0 && func_001114b0(work->streamTask) != 0)
        {
            if (work->effectCount == 0)
            {
                if (work->loadedResources[0] != NULL)
                    *(u32*)((u8*)work->loadedResources[0] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[0] + 0x50) &
                         0xffff00ff) | 0x3300;
                if (work->loadedResources[1] != NULL)
                    *(u32*)((u8*)work->loadedResources[1] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[1] + 0x50) &
                         0xffff00ff) | 0x3300;
                func_001105d0(work->resourceTasks[0], 0,
                              work->loadedResources[1]);
                func_001105d0(work->resourceTasks[0], 1,
                              work->loadedResources[0]);
            }
            else if (work->effectCount == 1)
            {
                if (work->loadedResources[0] != NULL)
                    *(u32*)((u8*)work->loadedResources[0] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[0] + 0x50) &
                         0xffff00ff) | 0x3300;
                if (work->loadedResources[1] != NULL)
                    *(u32*)((u8*)work->loadedResources[1] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[1] + 0x50) &
                         0xffff00ff) | 0x3300;
                func_001105d0(work->resourceTasks[0], 0,
                              work->loadedResources[1]);
                func_001105d0(work->resourceTasks[0], 1,
                              work->loadedResources[0]);
                if (work->loadedResources[2] != NULL)
                    *(u32*)((u8*)work->loadedResources[2] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[2] + 0x50) &
                         0xffff00ff) | 0x3300;
                if (work->loadedResources[3] != NULL)
                    *(u32*)((u8*)work->loadedResources[3] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[3] + 0x50) &
                         0xffff00ff) | 0x3300;
                func_001105d0(work->resourceTasks[1], 0,
                              work->loadedResources[3]);
                func_001105d0(work->resourceTasks[1], 1,
                              work->loadedResources[2]);
            }
            else
            {
                if (work->loadedResources[0] != NULL)
                    *(u32*)((u8*)work->loadedResources[0] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[0] + 0x50) &
                         0xffff00ff) | 0x3300;
                if (work->loadedResources[1] != NULL)
                    *(u32*)((u8*)work->loadedResources[1] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[1] + 0x50) &
                         0xffff00ff) | 0x3300;
                func_001105d0(work->resourceTasks[0], 0,
                              work->loadedResources[1]);
                func_001105d0(work->resourceTasks[0], 1,
                              work->loadedResources[0]);
                if (work->loadedResources[2] != NULL)
                    *(u32*)((u8*)work->loadedResources[2] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[2] + 0x50) &
                         0xffff00ff) | 0x3300;
                if (work->loadedResources[3] != NULL)
                    *(u32*)((u8*)work->loadedResources[3] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[3] + 0x50) &
                         0xffff00ff) | 0x3300;
                func_001105d0(work->resourceTasks[1], 0,
                              work->loadedResources[3]);
                func_001105d0(work->resourceTasks[1], 1,
                              work->loadedResources[2]);
                if (work->loadedResources[4] != NULL)
                    *(u32*)((u8*)work->loadedResources[4] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[4] + 0x50) &
                         0xffff00ff) | 0x3300;
                if (work->loadedResources[5] != NULL)
                    *(u32*)((u8*)work->loadedResources[5] + 0x50) =
                        (*(u32*)((u8*)work->loadedResources[5] + 0x50) &
                         0xffff00ff) | 0x3300;
                func_001105d0(work->resourceTasks[2], 0,
                              work->loadedResources[5]);
                func_001105d0(work->resourceTasks[2], 1,
                              work->loadedResources[4]);
            }
            work->state = 3;
        }
        break;
    case 4:
        MaestroEffectSetReady(work);
        func_00119960(task, work->effectCount, work->blob);
        work->state = 5;
        break;
    case 5:
        frame = work->frame;
        if (frame >= 10)
        {
            segment = frame - 10;
            if (segment < 30)
            {
                u32 alpha;

                if (segment < 5)
                    alpha = (u32)(segment * 0xff / 5);
                else
                    alpha = 0xff;
                func_00113a30(100.0f, 0.0f, 0.0f,
                              0x0f395600 | alpha, 0x280, 0x1c0);
            }
            else
            {
                segment -= 30;
                if (segment >= 0x29)
                    return KWLNTASK_STOP;
                {
                    f32 points[4][2];
                    u64 point0;
                    u64 point1;
                    u64 point2;
                    u64 point3;
                    radius = segment * 36;
                    for (i = 0; i < 24; i++)
                    {
                        f32 angle0;
                        f32 angle1;

                        angle0 = gPI * (f32)(i * 400 / 24) / 180.0f;
                        angle1 = gPI * (f32)((i + 1) * 400 / 24) / 180.0f;
                        points[0][0] = cosf(angle0) * 1000.0f;
                        points[0][1] = sinf(angle0) * 1000.0f;
                        points[1][0] = cosf(angle1) * 1000.0f;
                        points[1][1] = sinf(angle1) * 1000.0f;
                        points[2][0] = cosf(angle0) * (f32)radius;
                        points[2][1] = sinf(angle0) * (f32)radius;
                        points[3][0] = cosf(angle1) * (f32)radius;
                        points[3][1] = sinf(angle1) * (f32)radius;
                        for (j = 0; j < 4; j++)
                        {
                            points[j][0] += 320.0f;
                            points[j][1] += 224.0f;
                        }
                        point0 = *(u64*)&points[0][0];
                        point1 = *(u64*)&points[1][0];
                        point2 = *(u64*)&points[2][0];
                        point3 = *(u64*)&points[3][0];
                        func_00115350(100.0f, 0x0f3956ff,
                                      point0, point1, point2, point3,
                                      0xff, 0xff, 0xff, 0xff);
                    }
                }
                }
            }
        work->frame = frame + 1;
        for (i = 0; i < 3; i++)
        {
            if (work->resourceTasks[i] != NULL)
            {
                func_00110510(work->resourceTasks[i]);
            }
        }
        if (work->completionCounts[0] <= work->frame)
        {
            for (i = 0; i < 3; i++)
            {
                if (work->resourceTasks[i] != NULL)
                {
                    func_00195020(work->resourceTasks[i]);
                    work->resourceTasks[i] = NULL;
                }
            }
        }
        break;
    }
    return KWLNTASK_CONTINUE;
}
#pragma pop

// Retail unrolls the state-0 resource-load loop (14 literal calls, not a
// runtime loop) and dispatches via switch, not if/else-if. Rewritten from
// disasm; nd 261->10. Residual: 1 addu operand-order floor + 1 hoisted
// D_00833B70 pointer register-bank floor in the state-3-promote loop.
#pragma push
#pragma opt_loop_invariants on
// FUN_00119AA0
void* func_00119aa0(KwlnTask* task)
{
    MaestroCampSpriteSetupWork* work;
    u32 size;
    s32 i;
    u32 ready;

    work = (MaestroCampSpriteSetupWork*)task->workData;
    switch (work->state)
    {
    case 0:
        if (H_Cdvd_IsFileLoaded(work->archive) != 0)
        {
            work->resources[0] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 0, &size));
            work->resources[1] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 1, &size));
            work->resources[2] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 2, &size));
            work->resources[3] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 3, &size));
            work->resources[4] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 4, &size));
            work->resources[5] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 5, &size));
            work->resources[6] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 6, &size));
            work->resources[7] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 7, &size));
            work->resources[8] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 8, &size));
            work->resources[9] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 9, &size));
            work->resources[10] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 10, &size));
            work->resources[11] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 11, &size));
            work->resources[12] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 12, &size));
            work->resources[13] = func_00112420(H_Cdvd_ArchiveGetFile(work->archive, 13, &size));
            work->ownerPool = func_0018b6d0(0xc8);
            iGpffffb25c = work->ownerPool;
            work->state = 1;
        }
        break;
    case 1:
        ready = true;
        for (i = 0; i < 14; i++)
        {
            if (work->resources[i] != NULL &&
                H_Maestro_00111f30((s16*)work->resources[i]) == 0)
            {
                ready = false;
            }
        }
        if (ready != 0)
        {
            {
                s32 j = 0;

                for (; j < 14; j++)
                {
                    D_00833B70[j] = work->resources[j];
                }
            }
            work->state = 3;
        }
        break;
    case 2:
        if (H_Cdvd_IsFileLoaded(work->archive) != 0)
        {
            work->state = 3;
        }
        break;
    case 3:
        break;
    }
    func_003c7b90();
    return KWLNTASK_CONTINUE;
}
#pragma pop

// FUN_00119E00
void func_00119e00(KwlnTask* task)
{
    MaestroCampSpriteSetupWork* work;
    s32 i;

    work = (MaestroCampSpriteSetupWork*)task->workData;
    for (i = 0; i < 14; i++)
    {
        if (*(void**)((int)work + i * 4 + 4) != NULL)
        {
            func_001124b0(*(void**)((int)work + i * 4 + 4));
        }
        *(void**)((int)work + i * 4 + 4) = NULL;
    }
    if (work->archive != NULL)
    {
        H_Cdvd_Destroy(work->archive);
    }
    if (work->ownerPool != NULL)
    {
        MAESTRO_FREE(work->ownerPool);
        iGpffffb25c = NULL;
    }
    {
        s32 j = 0;
        void** table = D_00833B70;

        for (; j < 14; j++)
        {
            table[j] = NULL;
        }
    }
    MAESTRO_FREE(work);
    if (work->initializeMessages != 0)
    {
        func_003c77a0();
    }
    iGpffffb258 = NULL;
}
