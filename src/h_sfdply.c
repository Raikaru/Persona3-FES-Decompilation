#include "Kernel/Kwln/kwln.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Script/scrTraceCode.h"
#include "h_cdvd.h"
#include "h_sfdply.h"
#include "rw/rwplcore.h"
#include "temporary.h"
#pragma alias rwGlobals_abs rwGlobals
extern u8 rwGlobals_abs[];
extern u8 D_0077e4e0[];

#define HSFD_QUEUE_COUNT 256
#define HSFD_DECODE_SLOTS 6
#define HSFD_STREAM_HINT rwMEMHINTDUR_GLOBAL

typedef struct HSfdQueueSlot HSfdQueueSlot;
typedef struct HSfdAsyncEntry HSfdAsyncEntry;

typedef struct HSfdImage
{
    u32 type;
    u32 width;
    u32 height;
    u32 depth;
    u32 stride;
    u8* pixels;
    u8* palette;
} HSfdImage;

typedef struct HSfdTexture
{
    HSfdImage image;
    u8* palette;
    u32 paletteSize;
} HSfdTexture;

typedef struct HSfdDecodeSlot
{
    s16 state;
    s16 padding02;
    HCdvd* request;
    s16 fileIndex;
    s16 index;
    s32 queueHandle;       // 0x0C
    s32 outputHandle;      // 0x10
    s32 decodeHandle;      // 0x14
    s32 status;            // 0x18
    void* input;           // 0x1C
    u32 inputSize;         // 0x20
    void* intermediate;    // 0x24
    u32 intermediateSize;  // 0x28
    void* output;          // 0x2C
    u32 outputSize;        // 0x30
    void* resource;        // 0x34
    void* aux;             // 0x38
    void* sourceData;      // 0x3C
    void* completion;      // 0x40
} HSfdDecodeSlot;

struct HSfdQueueSlot
{
    s16 state;
    s16 padding02;
    HSfdAsyncEntry* entry;
};

struct HSfdAsyncEntry
{
    HSfdAsyncEntry* next;
    HSfdQueueSlot* queue;
    void* source;
    void* resultC;
    void* resultD;
    void* resultE;
    void* resultF;
    void* resultG;
    u8 reserved20[4];
    char name[128];
    char path[128];
    char cacheName[128];
    s32 state;
    s32 requestFlags;
    s32 kind;
    HCdvd* request;
    void* result0;
    void* result1;
    s32 byteCount;
    void* buffer;
    void* result2;
    void* result3;
    void* result4;
    s16 age;
    u16 padding1D2;
    void* result5;
};

typedef struct HSfdRenderFrame
{
    s8 type;
    s8 command;
    u16 colorR;
    u16 colorG;
    u16 colorB;
    u16 colorA;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
} HSfdRenderFrame;

typedef struct HSfdRenderView
{
    s32 type;
    void* commandSource;
    HSfdRenderFrame* frames;
    u8 reserved0C[0x9C];
    void* texture;
    u8 reservedAC[0x13C];
    s32 frameIndex;
    u8 reserved1EC[0x1EC];
    s32 currentCommand;
    u8 reserved28C[0x14C];
    float originX;
    float originY;
    u8 reserved3E0[0x100];
    s32 elementCount;
    s32 skyMode;
} HSfdRenderView;

static s32 sSfdFrameIndex;
static KwlnTask* sSfdPlayTask;
static HSfdQueueSlot sSfdQueue[HSFD_QUEUE_COUNT];
static HSfdAsyncEntry sSfdEntries[HSFD_QUEUE_COUNT];
static HSfdDecodeSlot sSfdDecodeSlots[HSFD_DECODE_SLOTS];

typedef struct HSfdCueEntry
{
    s32 active;
    s16 bank;
    s16 reserved6;
    s32 param;
} HSfdCueEntry;

static HSfdCueEntry sSfdCueTable[8];
#pragma alias sSfdDecodeSlots_abs sSfdDecodeSlots
extern HSfdDecodeSlot sSfdDecodeSlots_abs[];
#pragma alias sSfdCueTable_abs sSfdCueTable
extern HSfdCueEntry sSfdCueTable_abs[];
static u8* sSfdScratch;
static u8* sSfdDecodeBuffer;
static u8* sSfdFrameBuffers[4];
static const char* const sSfdDecodePaths[] =
{
    "sound/BSE.hd", "sound/BSE.bd", "sound/BSE.sq",
    "sound/spu/comse.hd", "sound/spu/comse.bd", "sound/spu/comse.sq",
    "sound/spu/bse.hd", "sound/spu/bse.bd", "sound/spu/bse.sq"
};

typedef struct HSfdDmaDescriptor
{
    const void* src;
    void* dst;
    u32 size;
    u32 mode;
} HSfdDmaDescriptor;

static HSfdDmaDescriptor sSfdDmaDescriptor;
extern void func_0051e028(s32 outputHandle, s32 channel, s32 count, s32 value);
extern s32 func_0051df58(s32 outputHandle, s32 channel, s32 count, s32 value, ...);
#pragma alias func_0051e028_t func_0051e028
extern void func_0051e028_t(s32 outputHandle, s32 channel, s32 count, s32 value);
#pragma alias func_0051df58_t func_0051df58
extern s32 func_0051df58_t(s32 outputHandle, s32 channel, s32 count, s32 value, ...);
extern s32 FUN_0050d3f0(void);
extern s32 FUN_0050d3a0(void);
extern void func_005030f0();

static s32 sSfdResumePending;
static s32 sSfdResumeThreadId;
extern void datSetFlag(s32 bit, u8 enabled);
extern void FUN_004aa550(void* param1);
extern void FUN_004b6350(void);
extern void FUN_004b7630(void* param1);

typedef struct EeThreadStatus
{
    s32 status;
    u8 reserved4[0x2C];
} EeThreadStatus;

extern void func_00503060();
extern void func_005030d0();

extern void* func_0057c680(void* descriptor);
extern void* func_0057d5d8(void* descriptor);
extern void func_0057e378(void* decoder, s32 mode);
extern s32 func_0057e530(void* decoder, s32* status);
extern void func_0057ee50(void* decoder);
extern s32 func_00581840(void* decoder);
extern void func_00584338(void* streamAux);
extern void func_0057db58(void* decoder);
extern void* func_004ce0f0(s32 width, s32 height, s32 format, s32 flags);
extern void func_004cde90(void* renderTarget);
extern void* func_004c58a0(s32 source, s32 mode, void* stream);
extern s32 func_004c5250(void* stream, void* dst, u32 bytes);
extern void func_004c5780(void* stream, s32 mode);
extern HSfdImage* func_004cbe00(u32 width, u32 height, u32 bits);
extern void func_004cbf20(HSfdImage* image);
extern void FlushCache(s32 mode);

static void H_SfdPlay_ResetTaskResources(HSfd* work)
{
    if (work->decoder != NULL)
    {
        if (work->streamAux != NULL)
        {
            func_00584338(work->streamAux);
            work->streamAux = NULL;
        }

        func_0057db58(work->decoder);
        work->decoder = NULL;
    }

    if (work->compressedFrameBuffer != NULL)
    {
        RwFree(work->compressedFrameBuffer);
        work->compressedFrameBuffer = NULL;
    }

    if (work->displayBuffer != NULL)
    {
        RwFree(work->displayBuffer);
        work->displayBuffer = NULL;
    }

    if (work->renderTarget != NULL)
    {
        func_004cde90(work->renderTarget);
        work->renderTarget = NULL;
    }

    work->streamDescriptor = NULL;
    work->decodeResult = 0;
    work->frameWidth = 0;
    work->frameHeight = 0;
}

static void H_SfdPlay_BeginStream(HSfd* work)
{
    u32 descriptor[12];
    s32 renderHeight;

    memset(descriptor, 0, sizeof(descriptor));
    descriptor[0] = 1;
    descriptor[1] = 0x4C4B40;
    descriptor[5] = 0x11;
    descriptor[8] = 2;
    descriptor[9] = 1;

    work->decoder = func_0057c680(descriptor);
    if (work->decoder == NULL)
    {
        work->state = HSFD_STATE_CLEANUP;
        return;
    }

    work->compressedFrameBuffer = RwCalloc(1, 0x118000, HSFD_STREAM_HINT);
    work->displayBuffer = RwCalloc(1, 0x118000, HSFD_STREAM_HINT);
    if ((work->compressedFrameBuffer == NULL) || (work->displayBuffer == NULL))
    {
        work->state = HSFD_STATE_CLEANUP;
        return;
    }

    work->streamDescriptor = func_0057d5d8(descriptor);
    if (work->streamDescriptor == NULL)
    {
        work->state = HSFD_STATE_CLEANUP;
        return;
    }

    func_0057e378(work->streamDescriptor, 0);
    work->decoder = work->streamDescriptor;
    work->frameWidth = 640;
    renderHeight = 448;
    if ((work->id == 5) || (work->id == 6))
    {
        renderHeight = 368;
    }
    work->frameHeight = renderHeight;
    work->renderTarget = func_004ce0f0(work->frameWidth, renderHeight, 0x20, 0x584);
    if (work->renderTarget == NULL)
    {
        work->state = HSFD_STATE_CLEANUP;
        return;
    }

    work->state = HSFD_STATE_PLAYING;
}

// FUN_0010A860 NONMATCHING
void* H_SfdPlay_UpdateTask(KwlnTask* sfdPlayTask)
{
    HSfd* work;
    s32 decodeStatus;

    work = (HSfd*)sfdPlayTask->workData;
    if (work == NULL)
    {
        return KWLNTASK_CONTINUE;
    }

    switch (work->state)
    {
        case HSFD_STATE_IDLE:
            if (work->ownsCamera != 0)
            {
                work->ownsCamera = 0;
            }
            if (work->isStart != 0)
            {
                work->fadeFrame = 0;
                work->playbackFrame = 0;
                work->state = HSFD_STATE_WAIT_FOR_FADE;
            }
            break;

        case HSFD_STATE_WAIT_FOR_FADE:
            work->stateTimer++;
            if (work->stateTimer >= 3)
            {
                work->stateTimer = 0;
                work->ownsCamera = 1;
                work->state = HSFD_STATE_CREATE_STREAM;
            }
            break;

        case HSFD_STATE_CREATE_STREAM:
            H_SfdPlay_BeginStream(work);
            break;

        case HSFD_STATE_PLAYING:
            if (work->decoder == NULL)
            {
                work->state = HSFD_STATE_CLEANUP;
                break;
            }

            decodeStatus = 0;
            if (func_0057e530(work->decoder, &decodeStatus) != 0)
            {
                func_0057ee50(work->decoder);
                work->decodeResult = func_00581840(work->decoder);
                work->playbackFrame++;
                if ((work->decodeResult == 3) || (work->decodeResult == 4))
                {
                    work->state = HSFD_STATE_FADE_OUT;
                    work->fadeFrame = 0;
                }
            }
            break;

        case HSFD_STATE_FADE_OUT:
            work->fadeFrame++;
            if (work->fadeFrame >= 30)
            {
                work->state = HSFD_STATE_CLEANUP;
            }
            break;

        case HSFD_STATE_CLEANUP:
            H_SfdPlay_ResetTaskResources(work);
            work->stateTimer = 0;
            work->state = HSFD_STATE_IDLE;
            if (work->isStart != 0)
            {
                return KWLNTASK_STOP;
            }
            break;

        default:
            work->state = HSFD_STATE_CLEANUP;
            break;
    }

    return KWLNTASK_CONTINUE;
}

// FUN_0010BB00
void H_SfdPlay_DestroyTask(KwlnTask* sfdPlayTask)
{
    HSfd* work;

    work = (HSfd*)sfdPlayTask->workData;

    if (work->decoder != NULL)
    {
        if (work->streamAux != NULL)
        {
            func_00584338(work->decoder);
        }
        func_0057db58(work->decoder);
        work->decoder = NULL;
    }

    if (work->compressedFrameBuffer != NULL)
    {
        (*(void (**)(void*))((u8*)rwGlobals_abs + 0x17c))(work->compressedFrameBuffer);
        work->compressedFrameBuffer = NULL;
    }

    if (work->displayBuffer != NULL)
    {
        (*(void (**)(void*))((u8*)rwGlobals_abs + 0x17c))(work->displayBuffer);
        work->displayBuffer = NULL;
        sSfdFrameIndex = 0;
    }

    if (work->renderTarget != NULL)
    {
        func_004cde90(work->renderTarget);
        work->renderTarget = NULL;
    }

    datSetFlag(0x1407, 0);

    if (work->isStart == 0)
    {
        sSfdPlayTask = NULL;
    }

    if (work->ownsCamera != 0)
    {
        work->ownsCamera = 0;
        FUN_004aa550(kwlnGetMainCamera());
        FUN_004b6350();
        FUN_004b7630(D_0077e4e0);
    }

    (*(void (**)(void*))((u8*)rwGlobals_abs + 0x17c))(work);
}

// FUN_0010BC20
KwlnTask* func_0010bc20(KwlnTask* parent, s32 id)
{
    HSfd* work;
    KwlnTask* task;

    work = RwCalloc(1, sizeof(HSfd), HSFD_STREAM_HINT);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreate(parent, "H_SfdPlay", 7383, H_SfdPlay_UpdateTask,
                          H_SfdPlay_DestroyTask, work);
    if (task == NULL)
    {
        return NULL;
    }

    work->isStart = true;
    work->id = id;
    return task;
}

// FUN_0010BCE0
KwlnTask* func_0010bce0(KwlnTask* parent, s32 id)
{
    HSfd* work;
    KwlnTask* task;

    work = RwCalloc(1, sizeof(HSfd), HSFD_STREAM_HINT);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreate(parent, "H_SfdPlay", 7383, H_SfdPlay_UpdateTask,
                          H_SfdPlay_DestroyTask, work);
    if (task == NULL)
    {
        return NULL;
    }

    work->isStart = true;
    work->id = id;
    work->ownsCamera = false;
    return task;
}

// FUN_0010BDA0
KwlnTask* H_SfdPlay_CreateTaskIdle(KwlnTask* parent)
{
    HSfd* work;
    KwlnTask* task;

    work = RwCalloc(1, sizeof(HSfd), HSFD_STREAM_HINT);
    if (work == NULL)
    {
        return NULL;
    }

    task = kwlnTaskCreate(parent, "H_SfdPlay", 7383, H_SfdPlay_UpdateTask,
                          H_SfdPlay_DestroyTask, work);
    if (task == NULL)
    {
        return NULL;
    }

    work->id = HSFD_ORPHEUSAWAKENING;
    work->isStart = false;
    work->ownsCamera = false;
    sSfdPlayTask = task;
    return task;
}

// FUN_0010BE60
u32 H_SfdPlayCmd_CALL_MOVIE(void)
{
    HSfd* work;
    HSfd* newWork;
    KwlnTask* task;
    s32 id;

    id = scrGetIntPara(0);
    if (sSfdPlayTask == NULL)
    {
        newWork = RwCalloc(1, sizeof(HSfd), HSFD_STREAM_HINT);
        if (newWork != NULL)
        {
            task = kwlnTaskCreate(NULL, "H_SfdPlay", 7383, H_SfdPlay_UpdateTask,
                                  H_SfdPlay_DestroyTask, newWork);
            if (task != NULL)
            {
                newWork->id = HSFD_ORPHEUSAWAKENING;
                newWork->isStart = false;
                newWork->ownsCamera = false;
                sSfdPlayTask = task;
            }
        }
    }

    work = (HSfd*)sSfdPlayTask->workData;
    work->id = id;
    work->stateTimer = 0;
    work->fadeFrame = 0;
    work->playbackFrame = 0;
    work->state = HSFD_STATE_WAIT_FOR_FADE;
    work->streamFlags = 0;
    return true;
}

// FUN_0010BF40
u32 H_SfdPlayCmd_MOVIE_SYNC(void)
{
    if (sSfdPlayTask == NULL)
    {
        return true;
    }

    return ((HSfd*)sSfdPlayTask->workData)->state == HSFD_STATE_IDLE;
}

// FUN_0010BF70
void func_0010bf70(void)
{
    s32 wasEnabled;
    EeThreadStatus threadStatus;

    wasEnabled = FUN_0050d3f0();
    if (sSfdResumePending != 0)
    {
        func_00503060(sSfdResumeThreadId, &threadStatus);
        if ((threadStatus.status != 0xc) && (threadStatus.status != 8))
        {
            func_005030d0(sSfdResumeThreadId);
        }
    }
    if (wasEnabled == 0)
    {
        FUN_0050d3a0();
    }
}

// FUN_0010BFF0
void func_0010bff0(void)
{
    s32 wasEnabled;

    wasEnabled = FUN_0050d3f0();
    if (sSfdResumePending != 0)
    {
        func_005030f0(sSfdResumeThreadId);
    }
    if (wasEnabled == 0)
    {
        FUN_0050d3a0();
    }
}

// FUN_0010C050 NONMATCHING
void func_0010c050(void)
{
    s32 i;

    for (i = 0; i < HSFD_QUEUE_COUNT; i++)
    {
        sSfdQueue[i].state = 0;
        sSfdQueue[i].entry = NULL;
        memset(&sSfdEntries[i], 0, sizeof(HSfdAsyncEntry));
    }
}

// FUN_0010C1A0 NONMATCHING
HSfdAsyncEntry* func_0010c1a0(s32 kind, const char* name, const char* path,
                               s32 requestFlags, void* source, void* buffer,
                               s32 byteCount, const char* cacheName,
                               void* result2, void* result3, void* result4)
{
    HSfdAsyncEntry* entry;
    s32 i;

    entry = NULL;
    for (i = 0; i < HSFD_QUEUE_COUNT; i++)
    {
        if (sSfdQueue[i].entry == NULL)
        {
            entry = &sSfdEntries[i];
            sSfdQueue[i].entry = entry;
            sSfdQueue[i].state = 0;
            break;
        }
    }
    if (entry == NULL)
    {
        return NULL;
    }

    memset(entry, 0, sizeof(*entry));
    entry->queue = &sSfdQueue[i];
    entry->kind = kind;
    entry->requestFlags = requestFlags;
    entry->source = source;
    entry->byteCount = byteCount;
    entry->buffer = buffer;
    entry->result2 = result2;
    entry->result3 = result3;
    entry->result4 = result4;
    entry->state = 0;
    entry->age = 0;
    if (name != NULL)
    {
        strcpy(entry->name, name);
    }
    if (path != NULL)
    {
        strcpy(entry->path, path);
    }
    if (cacheName != NULL)
    {
        strcpy(entry->cacheName, cacheName);
    }
    return entry;
}

// FUN_0010C3A0 NONMATCHING
void* func_0010c3a0(HSfdAsyncEntry* entry, u32* wasReady, s32* byteCount)
{
    void* result;

    result = NULL;
    if ((entry == NULL) || (entry->state != 3) || (entry->queue == NULL))
    {
        if (wasReady != NULL)
        {
            *wasReady = false;
        }
        return NULL;
    }

    entry->queue->entry = entry->next;
    if (entry->next != NULL)
    {
        entry->next->queue = entry->queue;
    }
    entry->queue = NULL;

    switch (entry->kind)
    {
        case 0:
            result = entry->result0;
            break;
        case 1:
            result = entry->resultC;
            break;
        case 2:
            result = entry->resultD;
            break;
        case 3:
            result = entry->resultE;
            break;
        case 4:
            result = entry->result1;
            break;
        case 5:
            result = entry->resultF;
            break;
        case 6:
            result = entry->resultG;
            break;
        case 7:
            result = entry->result2;
            break;
        case 8:
            result = entry->result3;
            break;
        case 9:
            result = entry->result5;
            break;
    }

    if (byteCount != NULL)
    {
        *byteCount = entry->byteCount;
    }
    if (wasReady != NULL)
    {
        *wasReady = true;
    }
    return result;
}

// FUN_0010C5F0 NONMATCHING
void func_0010c5f0(void)
{
    HSfdAsyncEntry* entry;
    s32 i;

    for (i = 0; i < HSFD_QUEUE_COUNT; i++)
    {
        entry = sSfdQueue[i].entry;
        while (entry != NULL)
        {
            if (entry->state == 0)
            {
                if (entry->path[0] == '\0')
                {
                    sSfdQueue[i].state = 1;
                    entry->state = 2;
                }
                else
                {
                    entry->request = H_Cdvd_Request(entry->path, entry->requestFlags);
                    entry->state = 1;
                }
            }
            else if ((entry->state == 1) && H_Cdvd_IsFileLoaded(entry->request))
            {
                sSfdQueue[i].state = 1;
                entry->state = 2;
            }
            else if (entry->state == 2)
            {
                entry->age++;
            }
            entry = entry->next;
        }
    }
}

// FUN_0010C7D0 NONMATCHING
void func_0010c7d0(HSfdQueueSlot* slot)
{
    HSfdAsyncEntry* entry;
    u32 size;

    if ((slot == NULL) || (slot->state != 1))
    {
        return;
    }

    entry = slot->entry;
    if (entry == NULL)
    {
        slot->state = 0;
        return;
    }

    size = 0;
    if (entry->request != NULL)
    {
        entry->source = H_Cdvd_CacheFindFile(entry->path, &size);
        H_Cdvd_Destroy(entry->request);
        entry->request = NULL;
    }
    entry->byteCount = size;

    switch (entry->kind)
    {
        case 0:
            entry->result0 = entry->source;
            break;
        case 1:
            entry->resultC = entry->source;
            break;
        case 2:
            entry->resultD = entry->source;
            break;
        case 3:
            entry->resultE = entry->source;
            break;
        case 4:
            entry->result1 = entry->source;
            break;
        case 5:
            entry->resultF = entry->source;
            break;
        case 6:
            entry->resultG = entry->source;
            break;
        case 7:
            entry->result2 = entry->source;
            break;
        case 8:
            entry->result3 = entry->source;
            break;
        case 9:
            entry->result5 = entry->source;
            break;
    }

    entry->state = 3;
    slot->state = 0;
}

// FUN_0010CAC0 NONMATCHING
void func_0010cac0(void)
{
    s32 i;

    for (i = 0; i < HSFD_DECODE_SLOTS; i++)
    {
        memset(&sSfdDecodeSlots[i], 0, sizeof(HSfdDecodeSlot));
        sSfdDecodeSlots[i].index = i;
    }

    if (sSfdScratch == NULL)
    {
        sSfdScratch = RwCalloc(1, 0x96000, HSFD_STREAM_HINT);
    }
    if (sSfdDecodeBuffer == NULL)
    {
        sSfdDecodeBuffer = RwCalloc(1, 0xAF000, HSFD_STREAM_HINT);
    }
    for (i = 0; i < 4; i++)
    {
        if (sSfdFrameBuffers[i] == NULL)
        {
            sSfdFrameBuffers[i] = RwCalloc(1, 0x19000, HSFD_STREAM_HINT);
        }
    }
}

// FUN_0010CCE0
s32 func_0010cce0(void* dst, const void* src, s32 size)
{
    s32 dmaId;
    s32 status;

    if (size <= 0)
    {
        return 0;
    }

    sSfdDmaDescriptor.src = src;
    sSfdDmaDescriptor.dst = dst;
    sSfdDmaDescriptor.size = size;
    sSfdDmaDescriptor.mode = 0;

    FlushCache(0);
    dmaId = sceSifSetDma(&sSfdDmaDescriptor, 1);
    if (dmaId == 0)
    {
        K_Assert("h_sndcom.c", 0x107);
    }

    do
    {
        status = sceSifDmaStat(dmaId);
    } while (status >= 0);

    do
    {
        status = sceSifDmaStat(dmaId);
    } while (status > 0 || status == 0);

    return size;
}

// FUN_0010CDD0 NONMATCHING
void func_0010cdd0(void)
{
    HSfdDecodeSlot* slot;
    const char* path;
    u32 size;
    u32 copySize;
    s32 pathIndex;
    s32 i;

    for (i = 0; i < HSFD_DECODE_SLOTS; i++)
    {
        slot = &sSfdDecodeSlots[i];
        pathIndex = slot->fileIndex * 3;
        if ((pathIndex < 0) || ((u32)(pathIndex + 2) >= (sizeof(sSfdDecodePaths) / sizeof(sSfdDecodePaths[0]))))
        {
            continue;
        }

        switch (slot->state)
        {
            case 0:
                slot->state = 1;
                break;

            case 2:
                path = sSfdDecodePaths[pathIndex];
                slot->request = H_Cdvd_Request(path, 0);
                slot->state = 3;
                break;

            case 3:
                if ((slot->request != NULL) && H_Cdvd_IsFileLoaded(slot->request))
                {
                    path = sSfdDecodePaths[pathIndex];
                    slot->input = H_Cdvd_CacheFindFile(path, &size);
                    slot->inputSize = size;
                    H_Cdvd_Destroy(slot->request);
                    slot->request = NULL;
                    slot->state = 4;
                }
                break;

            case 4:
                path = sSfdDecodePaths[pathIndex + 1];
                slot->request = H_Cdvd_Request(path, 0);
                slot->state = 5;
                break;

            case 5:
                if ((slot->request != NULL) && H_Cdvd_IsFileLoaded(slot->request))
                {
                    path = sSfdDecodePaths[pathIndex + 1];
                    slot->intermediate = H_Cdvd_CacheFindFile(path, &size);
                    slot->intermediateSize = size;
                    H_Cdvd_Destroy(slot->request);
                    slot->request = NULL;
                    slot->state = 6;
                }
                break;

            case 6:
                path = sSfdDecodePaths[pathIndex + 2];
                slot->request = H_Cdvd_Request(path, 0);
                slot->state = 7;
                break;

            case 7:
                if ((slot->request != NULL) && H_Cdvd_IsFileLoaded(slot->request))
                {
                    path = sSfdDecodePaths[pathIndex + 2];
                    slot->output = H_Cdvd_CacheFindFile(path, &size);
                    slot->outputSize = size;
                    H_Cdvd_Destroy(slot->request);
                    slot->request = NULL;
                    slot->resource = slot->output;
                    slot->state = 1;
                }
                break;

            case 8:
                if ((slot->input != NULL) && (slot->output != NULL))
                {
                    copySize = slot->inputSize;
                    if (copySize > slot->outputSize)
                    {
                        copySize = slot->outputSize;
                    }
                    func_0010cce0(slot->output, slot->input, copySize);
                    slot->state = 1;
                }
                break;
        }
    }
}

// FUN_0010D6F0 NONMATCHING
void func_0010d6f0(s32 index, s16 fileIndex)
{
    HSfdDecodeSlot* slot;

    if ((index < 0) || (index >= HSFD_DECODE_SLOTS))
    {
        return;
    }

    slot = &sSfdDecodeSlots[index];
    if (slot->state == 1)
    {
        slot->fileIndex = fileIndex;
        slot->state = 2;
    }
}

// FUN_0010D7B0 NONMATCHING
void func_0010d7b0(s32 index, s16 fileIndex, void* input, void* output,
                   s32 inputSize, s32 outputSize, void* resource, void* callback)
{
    HSfdDecodeSlot* slot;

    if ((index < 0) || (index >= HSFD_DECODE_SLOTS))
    {
        return;
    }

    slot = &sSfdDecodeSlots[index];
    if (slot->state != 1)
    {
        return;
    }

    slot->fileIndex = fileIndex;
    slot->input = input;
    slot->output = output;
    slot->inputSize = inputSize;
    slot->outputSize = outputSize;
    slot->resource = resource;
    slot->decodeHandle = (s32)callback;
    slot->state = 8;
}

// FUN_0010D910
u32 func_0010d910(s16 index)
{
    return sSfdDecodeSlots[index].state == 1;
}

// FUN_0010D950 NONMATCHING
void func_0010d950(s32 index)
{
    HSfdDecodeSlot* slot;

    if ((index < 0) || (index >= HSFD_DECODE_SLOTS))
    {
        return;
    }

    slot = &sSfdDecodeSlots[index];
    if (slot->request != NULL)
    {
        H_Cdvd_Destroy(slot->request);
        slot->request = NULL;
    }
    slot->input = NULL;
    slot->intermediate = NULL;
    slot->output = NULL;
    slot->resource = NULL;
    slot->state = 0;
}

// FUN_0010DA70
void func_0010da70(s16 bank, s16 cue)
{
    if ((sSfdDecodeSlots[bank].state == 1) && (sSfdDecodeSlots[bank].status != 0))
    {
        if (sSfdCueTable[cue].active != 0)
        {
            func_0051e028(sSfdDecodeSlots[bank].outputHandle, 1, 10, sSfdCueTable[cue].param);
            func_0051df58(sSfdDecodeSlots[bank].outputHandle, 2, 10, sSfdCueTable[cue].param);
            sSfdCueTable[cue].active = 0;
        }
    }
}

// FUN_0010DB60
void func_0010db60(s16 bank, s16 cue, s16 param3, s16 param4)
{
    s32 outputHandle;

    if ((sSfdDecodeSlots_abs[bank].state == 1) && (sSfdDecodeSlots_abs[bank].status != 0))
    {
        if (sSfdCueTable_abs[cue].active != 0)
        {
            if ((sSfdDecodeSlots_abs[bank].state == 1) && (sSfdDecodeSlots_abs[bank].status != 0))
            {
                if (sSfdCueTable_abs[cue].active != 0)
                {
                    func_0051e028_t(sSfdDecodeSlots_abs[bank].outputHandle, 1, 10, sSfdCueTable_abs[cue].param);
                    func_0051df58_t(sSfdDecodeSlots_abs[bank].outputHandle, 2, 10, sSfdCueTable_abs[cue].param);
                    sSfdCueTable_abs[cue].active = 0;
                }
            }
        }

        sSfdCueTable_abs[cue].bank = bank;
        sSfdCueTable_abs[cue].active = 1;
        outputHandle = sSfdDecodeSlots_abs[bank].outputHandle;
        asm volatile("" : "+m"(outputHandle));
        sSfdCueTable_abs[cue].param = func_0051df58_t(outputHandle, 0, 10, param3, param4);
    }
}
void func_0010dd10(HSfdImage* image, const u8* source)
{
    u8* dst;
    s32 y;
    s32 x;
    u32 alpha;

    dst = image->pixels;
    y = 0;
    while (y < (s32)image->height)
    {
        x = 0;
        while (x < (s32)image->width)
        {
            u8* pixel = dst + (x * 4);

            pixel[0] = source[0];
            pixel[1] = source[1];
            pixel[2] = source[2];
            alpha = source[3];
            if ((s32)alpha >= 0x7F)
            {
                pixel[3] = 0xFF;
            }
            else
            {
                pixel[3] = (u8)(((alpha * 0xFF) - alpha) >> 7);
            }
            source += 4;
            x++;
        }
        dst += image->stride;
        y++;
    }
}
// FUN_0010DDC0 NONMATCHING
void func_0010ddc0(HSfdImage* image, const u8* source)
{
    u8* dst;
    s32 y;
    s32 x;

    dst = image->pixels;
    y = 0;
    while (y < (s32)image->height)
    {
        x = 0;
        while (x < (s32)image->width)
        {
            u8* pixel = dst + (x * 4);

            pixel[0] = source[0];
            pixel[1] = source[1];
            pixel[2] = source[2];
            pixel[3] = 0xFF;
            source += 3;
            x++;
        }
        dst += image->stride;
        y++;
    }
}


// FUN_0010DE40 NONMATCHING
void func_0010de40(HSfdImage* image, const u8* source)
{
    u8* dst;
    const u16* pixels;
    s32 y;
    s32 x;
    dst = image->pixels;
    pixels = (const u16*)source;
    y = 0;
    while (y < (s32)image->height)
    {
        x = 0;
        while (x < (s32)image->width)
        {
            u8* pixel = dst + (x * 4);

            pixel[0] = (u8)((pixels[0] & 0x1F) << 3);
            pixel[1] = (u8)(((pixels[0] >> 5) & 0x1F) << 3);
            pixel[2] = (u8)(((pixels[0] >> 10) & 0x1F) << 3);
            pixel[3] = 0xFF;
            pixels++;
            x++;
        }
        dst += image->stride;
        y++;
    }
}

// FUN_0010DEE0 NONMATCHING
void func_0010dee0(HSfdImage* image, const u8* source)
{
    u8* dst;
    s32 y;
    s32 x;

    dst = image->pixels;
    y = 0;
    while (y < (s32)image->height)
    {
        x = 0;
        while (x < ((s32)image->width >> 1))
        {
            u8* pixel = dst + (x * 2);

            pixel[0] = source[0] & 0x0F;
            pixel[1] = (source[0] >> 4) & 0x0F;
            source++;
            x++;
        }
        dst += image->stride;
        y++;
    }
}


// FUN_0010DF60 NONMATCHING
void func_0010df60(HSfdImage* image, const u8* source)
{
    u8* dst;
    u32 i;
    u32 count;
    u8 alpha;

    count = 1 << image->depth;
    dst = image->pixels;
    for (i = 0; i < count; i++)
    {
        dst[0] = source[0];
        dst[1] = source[1];
        dst[2] = source[2];
        alpha = source[3];
        dst[3] = (alpha >= 0x7F) ? 0xFF : (u8)((alpha * 255) / 127);
        dst += 4;
        source += 4;
    }
}

// FUN_0010E010
void func_0010e010(HSfdImage* image, s32 bitDepth)
{
    u8* pixels = image->palette;
    s32 count;
    s32 i;

    if (bitDepth != 8)
    {
        return;
    }

    i = 0;
    count = 1 << bitDepth;
    while (i < count)
    {
        if (((i % 0x20) >= 8) && ((i % 0x20) < 16))
        {
            u8* pixel = pixels + (i * 4);
            u8 r = pixel[0];
            u8 g = pixel[1];
            u8 b = pixel[2];
            u8 a = pixel[3];

            pixel[0] = pixel[0x20];
            pixel[1] = pixel[0x21];
            pixel[2] = pixel[0x22];
            pixel[3] = pixel[0x23];
            pixel[0x20] = r;
            pixel[0x21] = g;
            pixel[0x22] = b;
            pixel[0x23] = a;
        }
        i++;
    }
}

// FUN_0010E0D0 NONMATCHING
HSfdImage* func_0010e0d0(const u8* stream)
{
    HSfdImage* image;
    u8 bits;
    u8 encoding;
    u32 pixels;
    const u8* payload;

    if ((stream == NULL) || (stream[0] != 2) || (stream[1] != 0) ||
        (stream[8] != 'T') || (stream[9] != 'M') ||
        (stream[10] != 'X') || (stream[11] != '0'))
    {
        return NULL;
    }

    bits = 0;
    switch (stream[0x16])
    {
        case 0:
            bits = 0x20;
            break;
        case 1:
            bits = 0x18;
            break;
        case 2:
        case 10:
            bits = 0x10;
            break;
        case 0x13:
        case 0x1B:
            bits = 8;
            break;
        case 0x14:
        case 0x24:
        case 0x2C:
            bits = 4;
            break;
        default:
            return NULL;
    }

    image = func_004cbe00((u32)(stream[0x12] | (stream[0x13] << 8)),
                          (u32)(stream[0x14] | (stream[0x15] << 8)), bits);
    if (image == NULL)
    {
        return NULL;
    }

    func_004cbf20(image);
    image->stride = image->width * 4;
    pixels = image->width * image->height;
    payload = stream + 0x40;
    encoding = stream[0x10];

    if (encoding != 0)
    {
        if (bits == 4)
        {
            func_0010df60(image, payload);
        }
        else if (bits == 8)
        {
            func_0010de40(image, payload);
        }
    }

    switch (stream[0x16])
    {
        case 0:
            func_0010dd10(image, payload);
            break;
        case 1:
            func_0010ddc0(image, payload);
            break;
        case 2:
        case 10:
            func_0010de40(image, payload);
            break;
        case 0x13:
        case 0x1B:
            func_0010dee0(image, payload);
            break;
        default:
            if (image->pixels != NULL)
            {
                memcpy(image->pixels, payload, pixels);
            }
            break;
    }

    func_0010e010(image, bits);
    return image;
}

// FUN_0010E500 NONMATCHING
HSfdImage* func_0010e500(void* stream)
{
    u8 header[0x40];
    u8* buffer;
    u32 payloadSize;
    HSfdImage* image;

    if (stream == NULL)
    {
        return NULL;
    }

    func_004c5250(stream, header, sizeof(header));
    payloadSize = (u32)(header[4] | (header[5] << 8) | (header[6] << 16) |
                        (header[7] << 24));
    if (payloadSize < sizeof(header))
    {
        return NULL;
    }

    buffer = RwCalloc(1, payloadSize, HSFD_STREAM_HINT);
    if (buffer == NULL)
    {
        return NULL;
    }

    memcpy(buffer, header, sizeof(header));
    func_004c5250(stream, buffer + sizeof(header), payloadSize - sizeof(header));
    image = func_0010e0d0(buffer);
    RwFree(buffer);
    return image;
}

// FUN_0010E5F0
void* func_0010e5f0(void* stream, void* output)
{
    func_004c58a0(2, 1, output);
    return stream;
}

// FUN_0010E630 NONMATCHING
void func_0010e630(void* destination, const void* source, u32 size)
{
    u8* dst;
    const u8* src;
    u32 blockSize;

    if ((destination == NULL) || (source == NULL) || (size == 0))
    {
        return;
    }

    dst = (u8*)destination;
    src = (const u8*)source;
    while (size > 0x400)
    {
        memcpy(dst, src, 0x400);
        dst += 0x400;
        src += 0x4000;
        size -= 0x400;
    }

    blockSize = size;
    if (blockSize != 0)
    {
        memcpy(dst, src, blockSize);
    }
}

// FUN_0010E880 NONMATCHING
HSfdTexture* func_0010e880(const u8* stream)
{
    HSfdTexture* texture;
    HSfdImage* image;
    u32 paletteSize;

    image = func_0010e0d0(stream);
    if (image == NULL)
    {
        return NULL;
    }

    texture = RwCalloc(1, sizeof(HSfdTexture), HSFD_STREAM_HINT);
    if (texture == NULL)
    {
        RwFree(image);
        return NULL;
    }

    texture->image = *image;
    RwFree(image);
    if (stream[0x10] != 0)
    {
        paletteSize = 1U << texture->image.depth;
        texture->palette = RwCalloc(paletteSize, 4, HSFD_STREAM_HINT);
        if (texture->palette == NULL)
        {
            RwFree(texture);
            return NULL;
        }
        texture->paletteSize = paletteSize * 4;
        func_0010e630(texture->palette, stream + 0x40, texture->paletteSize);
    }
    return texture;
}

// FUN_0010EC50 NONMATCHING
void func_0010ec50(KwlnTask* task)
{
    HSfdRenderView* view;
    HSfdRenderFrame* frame;
    s32 element;
    s32 frameIndex;
    s32 command;
    s32 component;

    if ((task == NULL) || (task->workData == NULL))
    {
        return;
    }

    view = (HSfdRenderView*)task->workData;
    if ((view->type != 3) || (view->frames == NULL))
    {
        return;
    }

    for (element = 0; element < view->elementCount; element++)
    {
        frameIndex = view->frameIndex;
        for (;;)
        {
            frame = &view->frames[frameIndex];
            command = frame->command;
            if (command == -1)
            {
                break;
            }

            switch (command)
            {
                case 0:
                    view->currentCommand = frame->type;
                    break;
                case 1:
                    view->currentCommand = 1;
                    break;
                case 2:
                    for (component = element - 1; component >= 0; component--)
                    {
                        if (component == 0)
                        {
                            break;
                        }
                    }
                    view->currentCommand = 2;
                    break;
            }
            frameIndex++;
        }
    }
}

// FUN_0010F6C0 NONMATCHING
void func_0010f6c0(KwlnTask* task)
{
    HSfdRenderView* view;
    s32 element;

    if ((task == NULL) || (task->workData == NULL))
    {
        return;
    }

    view = (HSfdRenderView*)task->workData;
    if (view->type == 3)
    {
        for (element = 0; element < view->elementCount; element++)
        {
            view->currentCommand = -1;
        }
    }
    else if (view->type == 1)
    {
        view->type = 0;
    }
}
