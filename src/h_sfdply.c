#include "Kernel/Kwln/kwln.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Script/scrTraceCode.h"
#include "h_dbprt.h"
#include "h_fade.h"
#include "h_cdvd.h"
#include "h_sfdply.h"
#include "rw/rwplcore.h"
#include "temporary.h"
#pragma alias rwGlobals_abs rwGlobals
extern u8 rwGlobals_abs[];
extern u8 D_0077e4e0[];
extern u8 D_00803640[];
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
extern f32 D_00960088;
extern void (*D_00960090)(u32 state, u32 value);
extern void (*D_00960094)(u32 state, void* value);
extern void (*D_009600A0)(u32 primitive, void* vertices, s32 count);
extern void* (*D_00960178)(u32 size, u32 flags);
extern void* (*D_00960184)(u32 count, u32 size, u32 flags);
extern void (*D_0096017c)(void* memory);
#pragma alias D_00960178_abs D_00960178
extern void* (*D_00960178_abs[])(u32 size, u32 flags);
#pragma alias D_0096017c_abs D_0096017c
extern void (*D_0096017c_abs[])(void* memory);
extern u16 DAT_007e094e;
extern void* D_0077e4f0;
extern s16 D_005D4B70[];
extern u8 D_005D4B74[];
extern u8 D_005D4B7C[];
extern u8 D_005D4B80[];
extern u8 D_005D4B84[];
extern u8 D_005D4B8C[];
extern u8 D_005D4B90[];
extern u8 D_005D4B92[];
extern u8 D_005D4B94[];
extern const char D_005D5250[];
extern const char D_005D5260[];
extern const char D_005D5280[];
extern void* uGpffffb220;
extern s16 uGpffffb228;
extern s16 uGpffffb218;
extern s32 uGpffffb230;
extern s32 uGpffffb22c;
extern u32 _mips_gp0_value;
extern char uGpffff8840[];
#pragma alias gp0xffff8840 uGpffff8840
extern char gp0xffff8840;
extern void H_Pad_IgnoreRumbleCallback(s32 a, s32 b, s32 c, s32 d);
extern void func_004b6500(void);
extern void func_004aa5c0(void);
extern void func_001cd8e0(void);
extern void adminiForcePassedCheck(void);
extern void func_003b5ab0(void);
extern s32 func_004c2120(void* value);
extern void K_Assert(const char* message, s32 line);
extern void func_004b7690(void* value);
extern void func_004faec0(void* stream, s32 a, s32 b);
extern void func_004f1780(void* target, s32 mode);
extern void func_00191d70(void* target, void* pixels, s32 width, s32 height);
extern void* func_004fa8f0(s32 mode);
extern int printf(const char* format, ...);
extern void* memcpy(void* destination, const void* source, u32 size);
#define HSFD_TABLE(base, index) ((u8*)(base) + ((index) * 0x28))
extern f32 gUnk_007cadd0;
extern void func_004aa390(f32 nearPlane);
extern void func_004aa3d0(f32 farPlane);
extern void func_004a9f20(f32 x, f32 y, f32 z, f32 w);
extern void func_004aa410(RwCamera* camera);
extern void* func_004a5470(void);
extern void func_004a5dd0(void* image, const s8* c0, const s8* c1,
                          const s8* c2, const s8* c3);
extern void func_004cb270(void* value);
extern void* func_004cc5c0(const char* path);
extern void* func_004d1260(const char* path, s32 mode);
extern void* func_00490050(const char* path);
extern void* func_004b7760(const char* message);
extern void* func_004920a0(const char* path);
extern void* func_004b69b0(const char* path);
extern void* func_00464540(const char* path);
extern void* func_0048d960(const char* path);
extern void* func_004b79d0(u32 size, const void* source);
extern void* func_004c8680(const char* path);
extern void* func_004b45b0(s32 mode, const void* source);
extern void func_00100ec0(void* request);
extern void func_00503080(void);
extern void* func_004ac570(void);
extern void func_004ac5f0(void* image);
extern void func_004ab1b0(void* image);
extern void func_004a62e0(void* image, void* data);
extern void func_004a6200(void* image, s32* out0, f32* out1,
                          f32* out2, s32* out3);
extern void func_004ab6a0(void* image);
extern void func_004ac710(void* image);
extern void func_004ace70(void* image, void* quad);
extern void func_004a6600(void* image, void* quad);
extern void func_004aaa60(void);
extern void func_004a9bf0(void);
extern void func_004aae00(f32 x, f32 y);
extern void func_004aad50(void);
extern void func_004ab200(void* image, f32 x, f32 y);
extern void func_004ab2c0(void* image, f32 x, f32 y);
extern void func_004ab410(void* image, f32 x0, f32 y0, f32 x1, f32 y1,
                          f32 x2, f32 y2);
extern void func_00110650(void* view, s32 from, s32 to);
extern s8 fGpffff7788[];
extern void* func_0050B690(s32 arg1, u32 size, s32 arg3);
extern void func_0050B710(void* ptr);
extern void func_00521250(void* dst, const void* src, u32 size);
extern void func_8051DBC0(s32 a0, void* a1, void* a2, u32 a3);
extern s32 func_0051DC70(s32 a0, s32 a1, ...);
extern s32 func_0051DDF0(s32 a0, s32 a1, ...);
extern u8 D_00823650[];

#define HSFD_ENTRY_COUNT 256
#define HSFD_QUEUE_COUNT 1
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
    u32 padding1D8;
};
typedef struct HSfdPoolEntry
{
    s32 state;
    u8 entry[0x1d8];
} HSfdPoolEntry;
typedef struct HSfdQueueEntry
{
    HSfdAsyncEntry* next;
    HSfdQueueSlot* queue;
    u8 reserved08[0x1d0];
} HSfdQueueEntry;

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
static HSfdQueueEntry sSfdQueueEntries[HSFD_QUEUE_COUNT];
static s32 sSfdThreadIds[HSFD_QUEUE_COUNT];
static HSfdQueueSlot sSfdQueue[HSFD_QUEUE_COUNT];
static HSfdAsyncEntry sSfdEntries[HSFD_ENTRY_COUNT];
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
extern u32 FUN_00512868(void);
extern u32 FUN_0051d5b0(u32 base, u32 stride, u32 count);
extern u64 FUN_0051da48(u32 value);
extern u64 FUN_0051da50(u64 size);
extern void FUN_0051db00(u32 a0, u32 a1, u32 a2, ...);
extern u32 FUN_0051d6f8(s32 size);
extern void FUN_0051deb0(u32 channel, void* handle);
extern void FUN_0051dd48(u32 channel, void* handle);
extern s32 FUN_0050d3f0(void);
extern s32 func_00502f60(void* threadParam);
extern s32 func_005042a0(s32 threadId, void* arg);
extern s32 FUN_0050d3a0(void);
extern void func_005030f0(s32 threadId);

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

extern void func_00503060(s32 threadId, EeThreadStatus* status);
extern void func_005030d0(s32 threadId);

extern void* func_0057c680(void* descriptor);
extern void* func_0057d5d8(void* descriptor);
extern void func_0057e378(void* decoder, s32 mode);
extern s32 func_0057e530(void* decoder, s32* status);
extern void func_0057ee50(void* decoder);
extern s32 func_00581840(void* decoder);
extern void func_00584338(void* streamAux);
extern void func_0057db58(void* decoder);
extern void* func_004ce0f0(s32 width, s32 height, s32 format, s32 flags);
extern void* func_004cdf30(void* raster, s32 palette);
extern void* func_004ce200(void* raster, void* mipData, s32 level);
extern void* func_004cde00(void* raster);
extern void FUN_004d5e90(void);
extern void func_004cde40(void* raster);
extern void func_004cde90(void* renderTarget);
extern void* func_004c58a0(s32 source, s32 mode, void* stream);
extern s32 func_004c5250(void* stream, void* dst, u32 bytes);
extern void func_004c5780(void* stream, s32 mode);
extern HSfdImage* func_004cbe00(u32 width, u32 height, u32 bits);
extern void func_0010c7d0(HSfdQueueSlot* slot);
extern void func_004cbf20(HSfdImage* image);
extern void FlushCache(s32 mode);

extern void func_0010d950(s16 index);
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

// Deep reconstruction pass restored per-state HSFD_TABLE lookups to use
// work->id directly (matching retail) instead of a cached movieId local,
// removed several dead/duplicate locals (decoder, rasterTarget, redundant
// config declaration, unused state local), and typed the render-state
// function pointer table access explicitly. object_size grew toward the
// retail window as genuine logic was restored; normalized_diff moved
// slightly worse, which is expected for this class of fix.
// FUN_0010A860 NONMATCHING
void* H_SfdPlay_UpdateTask(KwlnTask* sfdPlayTask)
{
    register HSfd* work;
    u8* camera;
    u8* raster;
    u8 frameInfo[0x30];
    u8* source;
    u8* destination;
    u32 savedState;
    s16 movieType;
    s16 movieLimit;
    s32 i;
    s32 width;
    s32 height;
    s32 powerWidth;
    s32 powerHeight;
    s32 alpha;
    s32 fadeValue;
    s32 frameResult;
    f32 reciprocalNear;
    f32 cameraWidth;
    f32 cameraHeight;
    f32 topBottom;
    void* framePixels;
    void (**setRenderState)(u32, u32);
    register u8* config;
    work = (HSfd*)sfdPlayTask->workData;

    switch (work->state)
    {
        case HSFD_STATE_IDLE:
            if (work->ownsCamera != 0)
            {
                work->ownsCamera = 0;
                func_004aa550(kwlnGetMainCamera());
                func_004b6350();
                func_004b7630(D_0077e4e0);
            }
        case 1:
            if (work->isStart != 0)
            {
                work->fadeFrame = 0;
                work->playbackFrame = 0;
                work->state = HSFD_STATE_WAIT_FOR_FADE;
            }
            break;

        case HSFD_STATE_WAIT_FOR_FADE:
            camera = (u8*)kwlnGetMainCamera();
            reciprocalNear = 1.0f / *(f32*)(camera + 0x80);
            uGpffffb228 = -1;
            if (H_Fade_IsFadeOutDone() == 0)
                return KWLNTASK_CONTINUE;
            work->stateTimer++;
            if (work->stateTimer == 1)
            {
                func_004b6500();
                func_004aa5c0();
                work->ownsCamera = 1;
                func_001cd8e0();
                adminiForcePassedCheck();
            }
            if (work->stateTimer == 3)
                func_003b5ab0();
            if (work->stateTimer == 6)
            {
                if (func_004c2120(D_0077e4f0) != 0)
                    K_Assert(D_005D5250, 0x180);
                func_004b7690(D_0077e4e0);
            }
            if (work->stateTimer != 10)
                break;

            printf(D_005D5260);
            H_Pad_IgnoreRumbleCallback(0, -1, 0, -1);
            datSetFlag(0x1407, 1);
            work->streamAux = *(void**)HSFD_TABLE(D_005D4B84, work->id);
            config = work->streamConfig;
            memset(config, 0, 0x30);
            *(s32*)(config + 0x20) = 0x11;
            *(s32*)(config + 0x00) = 1;
            *(s32*)(config + 0x04) = 0x4C4B40;
            *(s32*)(config + 0x08) =
                *(s32*)HSFD_TABLE(D_005D4B7C, work->id);
            *(s32*)(config + 0x0C) =
                *(s32*)HSFD_TABLE(D_005D4B80, work->id);
            *(s32*)(config + 0x10) = 2;
            *(s32*)(config + 0x14) = 1;
            *(s32*)(config + 0x24) = 2;
            work->decoder = func_0057c680(config);
            datSetFlag(0x141A, 1);
            work->compressedFrameBuffer =
                D_00960178((u32)((u8*)work->decoder + 0x40), 0x40000);
            work->displayBuffer = D_00960184(1, 0x118000, 0x40000);
            datSetFlag(0x141A, 0);
            if (work->compressedFrameBuffer == NULL ||
                work->displayBuffer == NULL)
            {
                if (work->isStart != 0)
                    return KWLNTASK_STOP;
                if (work->decoder != NULL)
                {
                    if (work->streamAux != NULL)
                        func_00584338(work->decoder);
                    func_0057db58(work->decoder);
                    work->decoder = NULL;
                }
                if (work->compressedFrameBuffer != NULL)
                {
                    D_0096017c(work->compressedFrameBuffer);
                    work->compressedFrameBuffer = NULL;
                }
                if (work->displayBuffer != NULL)
                {
                    D_0096017c(work->displayBuffer);
                    work->displayBuffer = NULL;
                    uGpffffb220 = NULL;
                }
                if (work->renderTarget != NULL)
                {
                    func_004cde90(work->renderTarget);
                    work->renderTarget = NULL;
                }
                datSetFlag(0x1407, 0);
                work->stateTimer = 0;
                work->state = HSFD_STATE_IDLE;
                return KWLNTASK_CONTINUE;
            }
            *(void**)(config + 0x18) = work->compressedFrameBuffer;
            work->streamDescriptor = func_0057d5d8(config);
            if (work->streamDescriptor == NULL)
            {
                D_0096017c(work->compressedFrameBuffer);
                work->compressedFrameBuffer = NULL;
                if (work->displayBuffer != NULL)
                {
                    D_0096017c(work->displayBuffer);
                    work->displayBuffer = NULL;
                    uGpffffb220 = NULL;
                }
            }
            func_0057e378(work->streamDescriptor, 0);
            work->decoder = work->streamDescriptor;
            if (work->streamAux != NULL)
                func_001023f0(work->streamDescriptor,
                              *(const char**)HSFD_TABLE(D_005D4B74, work->id), 1);
            else
                func_001023f0(work->streamDescriptor,
                              *(const char**)HSFD_TABLE(D_005D4B74, work->id), 0);
            datSetFlag(0x141A, 1);
            movieType = *(s16*)HSFD_TABLE(D_005D4B70, work->id);
            if (movieType == 5)
                work->renderTarget = func_004ce0f0(0x280, 0x1C0, 0x20, 0x584);
            else if (movieType == 6)
                work->renderTarget = func_004ce0f0(0x280, 0x170, 0x20, 0x584);
            datSetFlag(0x141A, 0);
            if (work->renderTarget == NULL)
            {
                if (work->isStart != 0)
                    return KWLNTASK_STOP;
                if (work->decoder != NULL)
                {
                    if (work->streamAux != NULL)
                        func_00584338(work->decoder);
                    func_0057db58(work->decoder);
                    work->decoder = NULL;
                }
                if (work->compressedFrameBuffer != NULL)
                {
                    D_0096017c(work->compressedFrameBuffer);
                    work->compressedFrameBuffer = NULL;
                }
                if (work->displayBuffer != NULL)
                {
                    D_0096017c(work->displayBuffer);
                    work->displayBuffer = NULL;
                    uGpffffb220 = NULL;
                }
                if (work->renderTarget != NULL)
                {
                    func_004cde90(work->renderTarget);
                    work->renderTarget = NULL;
                }
                datSetFlag(0x1407, 0);
                work->stateTimer = 0;
                work->state = HSFD_STATE_IDLE;
                return KWLNTASK_CONTINUE;
            }

            for (i = 0; i < 4; i++)
            {
                *(f32*)(work->quads[i].data + 8) = D_00960088;
                *(f32*)(work->quads[i].data + 0x18) = reciprocalNear;
                *(u32*)(work->quads[i].data + 0x20) = 0x437F0000;
                *(u32*)(work->quads[i].data + 0x24) = 0x437F0000;
                *(u32*)(work->quads[i].data + 0x28) = 0x437F0000;
                if (*(s32*)HSFD_TABLE(D_005D4B8C, work->id) != 0)
                    *(u32*)(work->quads[i].data + 0x2C) = 0;
                else
                    *(u32*)(work->quads[i].data + 0x2C) = 0x437F0000;
            }
            if (*(s32*)HSFD_TABLE(D_005D4B8C, work->id) != 0)
            {
                work->movieFrame = *(s16*)HSFD_TABLE(D_005D4B90, work->id);
                work->unknown1E8 = 0;
                work->state = HSFD_STATE_CREATE_STREAM;
            }
            else
                work->state = HSFD_STATE_CREATE_STREAM;

            camera = (u8*)kwlnGetMainCamera();
            raster = *(u8**)(camera + 0x60);
            cameraWidth = (f32)*(s32*)(raster + 0x0C);
            camera = (u8*)kwlnGetMainCamera();
            raster = *(u8**)(camera + 0x60);
            cameraHeight = (f32)*(s32*)(raster + 0x10);
            camera = (u8*)kwlnGetMainCamera();
            reciprocalNear = 1.0f / *(f32*)(camera + 0x80);
            movieType = *(s16*)HSFD_TABLE(D_005D4B70, work->id);
            if (movieType == 5)
            {
                *(s32*)((u8*)work + 0xE0) = 0;
                *(s32*)((u8*)work + 0x120) = 0;
                *(f32*)((u8*)work + 0x160) = cameraWidth;
                *(f32*)((u8*)work + 0x1A0) = cameraWidth;
                *(s32*)((u8*)work + 0x124) = 0;
                *(f32*)((u8*)work + 0x124) = cameraHeight;
                *(s32*)((u8*)work + 0x164) = 0;
                *(f32*)((u8*)work + 0x1A4) = cameraHeight;
            }
            else
            {
                *(s32*)((u8*)work + 0xE0) = 0;
                *(s32*)((u8*)work + 0x120) = 0;
                *(f32*)((u8*)work + 0x160) = cameraWidth;
                *(f32*)((u8*)work + 0x1A0) = cameraWidth;
                *(s32*)((u8*)work + 0xE4) = 0x42200000;
                topBottom = cameraHeight - 40.0f;
                *(f32*)((u8*)work + 0x124) = topBottom;
                *(s32*)((u8*)work + 0x164) = 0x42200000;
                *(f32*)((u8*)work + 0x1A4) = topBottom;
            }
            *(f32*)((u8*)work + 0xE8) = D_00960088;
            *(f32*)((u8*)work + 0x128) = D_00960088;
            *(f32*)((u8*)work + 0x168) = D_00960088;
            *(f32*)((u8*)work + 0x1A8) = D_00960088;
            powerWidth = 0x10;
            powerHeight = 0x10;
            width = *(s32*)HSFD_TABLE(D_005D4B7C, work->id) + 1;
            height = *(s32*)HSFD_TABLE(D_005D4B80, work->id) + 1;
            while (powerWidth < width)
                powerWidth <<= 1;
            while (powerHeight < height)
                powerHeight <<= 1;
            *(s32*)((u8*)work + 0xF0) = 0;
            *(s32*)((u8*)work + 0x130) = 0;
            *(f32*)((u8*)work + 0x170) = (f32)width / (f32)powerWidth;
            *(f32*)((u8*)work + 0x1B0) = (f32)width / (f32)powerWidth;
            *(s32*)((u8*)work + 0xF4) = 0;
            *(f32*)((u8*)work + 0x134) = (f32)height / (f32)powerHeight;
            *(s32*)((u8*)work + 0x174) = 0;
            *(f32*)((u8*)work + 0x1B4) = (f32)height / (f32)powerHeight;
            *(f32*)((u8*)work + 0xF8) = reciprocalNear;
            *(f32*)((u8*)work + 0x138) = reciprocalNear;
            *(f32*)((u8*)work + 0x178) = reciprocalNear;
            *(f32*)((u8*)work + 0x1B8) = reciprocalNear;
            break;

        case HSFD_STATE_CREATE_STREAM:
        case HSFD_STATE_PLAYING:
        case HSFD_STATE_FADE_OUT:
            if (work->id == 1 || work->id == 0x23)
            {
                if ((DAT_007e094e & 0x9FF) != 0)
                    work->state = HSFD_STATE_CLEANUP;
            }
            else if (work->id != 0x20 && work->id != 0x21 &&
                     work->id != 0x2A && (DAT_007e094e & 0x800) != 0)
                work->state = HSFD_STATE_CLEANUP;

            func_0057e530(work->decoder, (s32*)frameInfo);
            framePixels = *(void**)frameInfo;
            if (framePixels != NULL)
            {
                if (work->state == HSFD_STATE_FADE_OUT &&
                    *(s32*)HSFD_TABLE(D_005D4B8C, work->id) != 0 &&
                    *(s32*)frameInfo >= *(s16*)HSFD_TABLE(D_005D4B90, work->id))
                {
                    if (work->id == 0x18 || work->id == 0x1C || work->id == 0x29)
                    {
                        H_Fade_SetType(8);
                        H_Fade_SetCustomColor(0xFF, 0xFF, 0xFF);
                    }
                    else if (work->id == 0x17 || work->id == 0x0A || work->id == 0x0F)
                    {
                        H_Fade_SetType(8);
                        H_Fade_SetCustomColor(0x0F, 0x1F, 0x28);
                    }
                    work->fadeFrame = 0;
                    work->state = HSFD_STATE_CLEANUP;
                    if (uGpffffb228 != -1)
                    {
                        uGpffffb218 = uGpffffb228;
                        uGpffffb228 = -1;
                    }
                }
                work->frameWidth = *(s32*)(frameInfo + 0x0C);
                work->frameHeight = *(s32*)(frameInfo + 0x10);
                uGpffffb230 = *(s32*)(frameInfo + 0x14);
                uGpffffb22c = *(s32*)(frameInfo + 0x18);
                func_004faec0(func_004fa8f0(2), 0, 0);
                memcpy(work->displayBuffer, framePixels,
                       work->frameWidth * work->frameHeight * 4);
                uGpffffb220 = work->displayBuffer;
                source = framePixels;
                destination = (u8*)work + 0x40;
                for (i = 0; i < 9; i++)
                {
                    *(u64*)destination = *(u64*)source;
                    *(u64*)(destination + 8) = *(u64*)(source + 8);
                    source += 0x10;
                    destination += 0x10;
                }
                if (work->state == HSFD_STATE_CREATE_STREAM)
                {
                    if (*(s16*)HSFD_TABLE(D_005D4B94, work->id) == 0)
                        alpha = 0xFF;
                    else
                    {
                        work->playbackFrame++;
                        movieLimit = *(s16*)HSFD_TABLE(D_005D4B94, work->id);
                        alpha = (work->playbackFrame * 0xFF) / movieLimit;
                        if (work->playbackFrame == movieLimit)
                            work->state = HSFD_STATE_PLAYING;
                    }
                    for (i = 0; i < 4; i++)
                    {
                        *(u32*)(work->quads[i].data + 0x20) = 0x437F0000;
                        *(u32*)(work->quads[i].data + 0x24) = 0x437F0000;
                        *(u32*)(work->quads[i].data + 0x28) = 0x437F0000;
                        *(f32*)(work->quads[i].data + 0x2C) =
                            (f32)(u8)alpha;
                    }
                }
                if (work->state == HSFD_STATE_FADE_OUT)
                {
                    work->fadeFrame++;
                    movieLimit = *(s16*)HSFD_TABLE(D_005D4B92, work->id);
                    fadeValue = 0xFF -
                        ((work->fadeFrame * 0xFF) / movieLimit & 0xFF);
                    if (work->fadeFrame >= movieLimit)
                        work->state = HSFD_STATE_CLEANUP;
                    for (i = 0; i < 4; i++)
                    {
                        *(u32*)(work->quads[i].data + 0x20) = 0x437F0000;
                        *(u32*)(work->quads[i].data + 0x24) = 0x437F0000;
                        *(u32*)(work->quads[i].data + 0x28) = 0x437F0000;
                        *(f32*)(work->quads[i].data + 0x2C) =
                            (f32)(u8)fadeValue;
                    }
                }
            }
            func_0057ee50(work->decoder);
            frameResult = func_00581840(work->decoder);
            if (frameResult == 3 || frameResult == 4)
                work->state = HSFD_STATE_CLEANUP;
            if (RwCameraBeginUpdate(kwlnGetMainCamera()) != NULL)
            {
                D_00960094(0x0E, &savedState);
                setRenderState = (void (**)(u32, u32))D_00960090_abs;
                (*setRenderState)(0x0E, 0);
                func_004f1780(work->renderTarget, 1);
                if (uGpffffb220 != NULL)
                {
                    func_00191d70(work->renderTarget, uGpffffb220,
                                  uGpffffb230, uGpffffb22c);
                    (*setRenderState)(0x14, 1);
                    *(s32*)((u8*)work + 0x38) = frameResult;
                    (*setRenderState)(6, 0);
                    (*setRenderState)(7, 2);
                    (*setRenderState)(8, 0);
                    (*setRenderState)(0x0A, 5);
                    (*setRenderState)(0x0B, 9);
                    (*setRenderState)(9, 1);
                    (*setRenderState)(0x0C, 1);
                    (*setRenderState)(2, 3);
                    (*setRenderState)(1, (u32)work->renderTarget);
                    D_009600A0(4, (u8*)work + 0xE0, 4);
                }
                func_004f1780(work->renderTarget, 0);
                (*setRenderState)(0x0E, savedState);
                RwCameraEndUpdate(kwlnGetMainCamera());
            }
            break;

        case HSFD_STATE_CLEANUP:
            if (uGpffffb228 != -1)
            {
                uGpffffb218 = uGpffffb228;
                uGpffffb228 = -1;
            }
            if (work->id == 0x18 || work->id == 0x1C)
            {
                H_Fade_SetType(8);
                H_Fade_SetCustomColor(0xFF, 0xFF, 0xFF);
            }
            {
                if (work->isStart != 0)
                    return KWLNTASK_STOP;
                if (work->decoder != NULL)
                {
                    if (work->streamAux != NULL)
                        func_00584338(work->decoder);
                    func_0057db58(work->decoder);
                    work->decoder = NULL;
                }
                if (work->compressedFrameBuffer != NULL)
                {
                    D_0096017c(work->compressedFrameBuffer);
                    work->compressedFrameBuffer = NULL;
                }
                if (work->displayBuffer != NULL)
                {
                    D_0096017c(work->displayBuffer);
                    work->displayBuffer = NULL;
                    uGpffffb220 = NULL;
                }
                if (work->renderTarget != NULL)
                {
                    func_004cde90(work->renderTarget);
                    work->renderTarget = NULL;
                }
                datSetFlag(0x1407, 0);
                work->stateTimer = 0;
                work->state = HSFD_STATE_IDLE;
                return KWLNTASK_CONTINUE;
            }

        case 7:
            work->stateTimer = 0x1E;
            work->state = 8;
        case 8:
            work->state = 9;
        case 9:
            work->state = 10;
        case 10:
            work->stateTimer--;
            if (work->stateTimer == 0)
            {
                if (work->isStart != 0)
                    return KWLNTASK_STOP;
                if (work->decoder != NULL)
                {
                    if (work->streamAux != NULL)
                        func_00584338(work->decoder);
                    func_0057db58(work->decoder);
                    work->decoder = NULL;
                }
                if (work->compressedFrameBuffer != NULL)
                {
                    D_0096017c(work->compressedFrameBuffer);
                    work->compressedFrameBuffer = NULL;
                }
                if (work->displayBuffer != NULL)
                {
                    D_0096017c(work->displayBuffer);
                    work->displayBuffer = NULL;
                    uGpffffb220 = NULL;
                }
                if (work->renderTarget != NULL)
                {
                    func_004cde90(work->renderTarget);
                    work->renderTarget = NULL;
                }
                datSetFlag(0x1407, 0);
                work->stateTimer = 0;
                work->state = HSFD_STATE_IDLE;
                return KWLNTASK_CONTINUE;
            }
            break;

        case 11:
            H_Dbprt_FmtAt((RwV2d){2.0f, 10.0f}, D_005D5280);
            H_Dbprt_FmtAt((RwV2d){2.0f, 11.0f}, uGpffff8840);
            if ((DAT_007e094e & 0x10) != 0)
            {
                if (work->isStart != 0)
                    return KWLNTASK_STOP;
                if (work->decoder != NULL)
                {
                    if (work->streamAux != NULL)
                        func_00584338(work->decoder);
                    func_0057db58(work->decoder);
                    work->decoder = NULL;
                }
                if (work->compressedFrameBuffer != NULL)
                {
                    D_0096017c(work->compressedFrameBuffer);
                    work->compressedFrameBuffer = NULL;
                }
                if (work->displayBuffer != NULL)
                {
                    D_0096017c(work->displayBuffer);
                    work->displayBuffer = NULL;
                    uGpffffb220 = NULL;
                }
                if (work->renderTarget != NULL)
                {
                    func_004cde90(work->renderTarget);
                    work->renderTarget = NULL;
                }
                datSetFlag(0x1407, 0);
                work->stateTimer = 0;
                work->state = HSFD_STATE_IDLE;
                return KWLNTASK_CONTINUE;
            }
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

// FUN_0010C050
void func_0010c050(void)
{
    typedef struct HSfdThreadParam
    {
        s32 status;
        void (*function)(HSfdQueueSlot*);
        void* stack;
        s32 stackSize;
        void* gpReg;
        s32 initialPriority;
        s32 currentPriority;
        u32 attributes;
        u32 option;
    } HSfdThreadParam;
    HSfdAsyncEntry* entries;
    HSfdQueueEntry* queueEntry;
    s16 entryIndex;
    s16 queueIndex;
    s32* threadIdSlot;
    HSfdThreadParam thread;

    entryIndex = 0;
    entries = sSfdEntries;
    while (entryIndex < HSFD_ENTRY_COUNT)
    {
        entries[entryIndex].next = NULL;
        entryIndex++;
    }

    for (queueIndex = 0; queueIndex < HSFD_QUEUE_COUNT; queueIndex++)
    {
        queueEntry = &sSfdQueueEntries[queueIndex];
        queueEntry->next = NULL;
        queueEntry->queue = NULL;
        sSfdQueue[queueIndex].state = 0;
        thread.function = func_0010c7d0;
        thread.stack = D_00803640;
        thread.stackSize = 0x20000;
        thread.gpReg = &_mips_gp0_value;
        thread.initialPriority = 0x1C;
        threadIdSlot = &sSfdThreadIds[queueIndex];
        *threadIdSlot = func_00502f60(&thread);
        func_005042a0(*threadIdSlot, &sSfdQueue[queueIndex]);
    }
    uGpffffb230 = 1;
}

// FUN_0010C1A0 NONMATCHING
HSfdAsyncEntry* func_0010c1a0(s32 kind, const char* name, const char* path,
                               s32 requestFlags, void* source, void* buffer,
                               s32 byteCount, const char* cacheName,
                               void* result2, void* result3, void* result4)
{
    HSfdAsyncEntry** link;
    HSfdAsyncEntry* entry;
    s16 index;
    s32 enabled;

    link = &sSfdQueueEntries[0].next;
    enabled = FUN_0050d3a0();
link_check:
    if (*link != NULL)
    {
        goto link_next;
    }

    index = 0;
    goto pool_check;
pool_body:
    if (((HSfdPoolEntry*)sSfdEntries)[index].state == 0)
    {
        ((HSfdPoolEntry*)sSfdEntries)[index].state = 1;
        entry = (HSfdAsyncEntry*)((HSfdPoolEntry*)sSfdEntries)[index].entry;
        memset(entry, 0, 0x1d8);
        goto entry_found;
    }
    index++;
pool_check:
    if (index < HSFD_ENTRY_COUNT)
    {
        goto pool_body;
    }
    entry = NULL;

entry_found:
    entry->next = NULL;
    entry->name[0] = '\0';
    if (name != NULL)
    {
        strcpy(entry->name, name);
    }
    entry->path[0] = '\0';
    if (path != NULL)
    {
        strcpy(entry->path, path);
    }
    entry->source = source;
    entry->state = 0;
    entry->requestFlags = requestFlags;
    entry->kind = kind;
    entry->buffer = buffer;
    entry->byteCount = byteCount;
    entry->cacheName[0] = '\0';
    *(void**)((u8*)entry + 0x20) = result2;
    entry->result3 = result3;
    entry->age = 0;
    if (cacheName != NULL)
    {
        strcpy(entry->cacheName, cacheName);
    }
    entry->queue = (HSfdQueueSlot*)link;
    *link = entry;
    if (enabled != 0)
    {
        FUN_0050d3f0();
    }
    return entry;
link_next:
    link = &(*link)->next;
    goto link_check;
}

// FUN_0010C3A0 NONMATCHING
void* func_0010c3a0(HSfdAsyncEntry* entry, u32* wasReady, s32* byteCount)
{
    HSfdQueueSlot* queue;
    HSfdAsyncEntry* next;
    u8* header;
    void* result;
    s32 wasEnabled;
    s32 i;

    wasEnabled = FUN_0050d3a0();
    if ((entry != NULL) && (entry->state == 3) && (entry->queue != NULL))
    {
        queue = entry->queue;
        next = entry->next;
        queue->entry = next;
        if (next != NULL)
            next->queue = queue;
        entry->queue = NULL;

        switch (entry->kind)
        {
            case 0:
                result = entry->result0;
                break;
            case 1:
                result = entry->resultD;
                if (byteCount != NULL)
                    *byteCount = (s32)entry->source;
                break;
            case 2:
                func_004cb270(entry->source);
                result = entry->resultC;
                break;
            case 3:
                result = entry->resultE;
                break;
            case 4:
                result = entry->result1;
                if (byteCount != NULL)
                    *byteCount = (s32)entry->source;
                break;
            case 5:
                result = entry->resultF;
                if (byteCount != NULL)
                    *byteCount = (s32)entry->source;
                break;
            case 6:
                result = entry->resultG;
                break;
            case 7:
                result = entry->result2;
                if (byteCount != NULL)
                    *byteCount = (s32)entry->source;
                break;
            case 8:
                result = entry->result3;
                if (byteCount != NULL)
                    *byteCount = (s32)entry->source;
                break;
            default:
                result = entry->result5;
                break;
        }

        header = (u8*)sSfdEntries;
        for (i = 0; i < HSFD_ENTRY_COUNT; i++)
        {
            if (*(void**)header != NULL &&
                entry == (HSfdAsyncEntry*)(header + 4))
                *(void**)header = NULL;
            header += 0x1DC;
        }
        if (wasReady != NULL)
            *wasReady = true;
        if (wasEnabled == 0)
            FUN_0050d3f0();
        return result;
    }

    if (wasReady != NULL)
        *wasReady = false;
    if (wasEnabled == 0)
        FUN_0050d3f0();
    return NULL;
}

// FUN_0010C5F0 NONMATCHING
void func_0010c5f0(void)
{
    HSfdAsyncEntry* entry;
    s16 i;
    s32 enabled;

    for (i = 0; i < HSFD_QUEUE_COUNT; i++)
    {
        entry = sSfdQueueEntries[i].next;
        while (entry != NULL)
        {
            switch (entry->state)
            {
                case 0:
                    if (entry->path[0] != '\0')
                    {
                        enabled = FUN_0050d3a0();
                        entry->request =
                            H_Cdvd_Request(entry->path, entry->requestFlags);
                        if (enabled != 0)
                            FUN_0050d3f0();
                        entry->state = 1;
                        goto request_done;
                    }
                    entry->request = NULL;
                    enabled = 0;
                    goto request_ready;
                case 1:
                    enabled = FUN_0050d3a0();
                    if (!H_Cdvd_IsFileLoaded(entry->request))
                        goto request_restore;
                    if (enabled != 0)
                        FUN_0050d3f0();
                    enabled = 0;
request_ready:
                    sSfdQueue[i].state = 1;
                    sSfdQueue[i].entry = entry;
                    entry->state = 2;
                    func_00503090(sSfdThreadIds[i]);
request_restore:
                    if (enabled != 0)
                        FUN_0050d3f0();
                    break;
                case 2:
                    entry->age++;
                    break;
                case 3:
                    break;
            }
request_done:
            entry = entry->next;
        }
    }
}

// FUN_0010C7D0 NONMATCHING
void func_0010c7d0(HSfdQueueSlot* slot)
{
    HSfdAsyncEntry* entry;
    s32 enabled;

    func_00503080();
    if (slot == NULL)
    {
        FUN_0050d3f0();
        return;
    }
    entry = slot->entry;
    if (entry == NULL)
    {
        slot->state = 0;
        FUN_0050d3f0();
        return;
    }

    switch (entry->kind)
    {
        case 0:
            if (entry->cacheName[0] != '\0')
                func_004cc5c0(entry->cacheName);
            entry->result0 = func_004d1260(entry->name + 0x24, 0);
            func_004cc5c0(uGpffff8840);
            break;
        case 1:
            if (entry->cacheName[0] != '\0')
                func_004cc5c0(entry->cacheName);
            entry->resultC = func_00490050(entry->source);
            func_004cc5c0(uGpffff8840);
            break;
        case 2:
            if (entry->cacheName[0] != '\0')
                func_004cc5c0(entry->cacheName);
            if (entry->result3 != NULL)
                func_004b7760(entry->result3);
            entry->resultD = func_004920a0(entry->source);
            func_004cc5c0(uGpffff8840);
            break;
        case 3:
            entry->resultE = func_004b69b0(entry->name + 0x24);
            break;
        case 4:
            entry->result1 = (void*)func_004c5250(entry->source,
                                                 (void*)entry->buffer,
                                                 entry->byteCount);
            entry->resultF = func_00464540(entry->source);
            break;
        case 5:
            entry->resultG = func_0048d960(entry->name + 0x24);
            break;
        case 6:
            entry->result2 = func_004b79d0((u32)entry->buffer,
                                           entry->source);
            break;
        case 7:
            entry->result3 = func_004c8680(entry->source);
            break;
        default:
            entry->result5 = func_004b45b0(0, entry->source);
            if (entry->request != NULL)
            {
                enabled = FUN_0050d3a0();
                func_00100ec0(entry->request);
                entry->request = NULL;
                if (enabled != 0)
                    FUN_0050d3f0();
            }
            break;
    }

    enabled = FUN_0050d3a0();
    entry->state = 3;
    slot->state = 0;
    if (enabled != 0)
        FUN_0050d3f0();
    FUN_0050d3f0();
}

// FUN_0010CAC0 NONMATCHING
void func_0010cac0(void)
{
    HSfdDecodeSlot* slot;
    HSfdDecodeSlot* slots;
    s16 i;

    FUN_00512868();
    FUN_0051da48(0);
    FUN_0051da50(0x20);
    FUN_0051d5b0((u32)sSfdDecodeSlots, 0x20, 0);
    FUN_0051db00(0, 0x8F, 0);
    FUN_0051db00(3, 0x83, 0x105, 0x3C, 0);
    FUN_0051db00(3, 0x84, 0x3C, 0x3C);
    FUN_0051db00(3, 0x82, 1);
    FUN_005129c0(1, 0x8010, 0x800, 0xFC0);
    FUN_005129c0(1, 0x8010, 0x801, 0xFCC);
    FUN_0051db00(3, 0x80, 0x7F, 0x7F);

    slots = sSfdDecodeSlots_abs;
    for (i = 0; i < HSFD_DECODE_SLOTS; i++)
    {
        slot = &slots[i];
        slot->state = 0;
        slot->request = NULL;
        slot->status = 0;
        slot->index = i;
    }
    for (i = 0; i < 16; i++)
        ;
    sSfdFrameIndex = 0;

    sSfdDecodeSlots[0].intermediate = (u8*)FUN_0051d6f8(0x96000);
    sSfdDecodeSlots[1].intermediate = (u8*)FUN_0051d6f8(0xAF000);
    sSfdDecodeSlots[2].intermediate = (u8*)FUN_0051d6f8(0x19000);
    sSfdDecodeSlots[3].intermediate = (u8*)FUN_0051d6f8(0x19000);
    sSfdDecodeSlots[4].intermediate = (u8*)FUN_0051d6f8(0x19000);
    sSfdDecodeSlots[5].intermediate = (u8*)FUN_0051d6f8(0x19000);
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
    u32 size[1];
    s32 copySize;
    s16 i;
    s16 pathIndex;

    for (i = 0; i < HSFD_DECODE_SLOTS; i++)
    {
        slot = &sSfdDecodeSlots[i];
        switch (slot->state)
        {
            case 0:
                slot->state = 1;
                break;

            case 1:
                break;

            case 2:
                pathIndex = slot->fileIndex * 3;
                slot->request = H_Cdvd_Request(sSfdDecodePaths[pathIndex], 0);
                slot->state = 3;
                break;

            case 3:
                if ((slot->request != NULL) && H_Cdvd_IsFileLoaded(slot->request))
                {
                    void* fileData;
                    void* allocBuf;

                    pathIndex = slot->fileIndex * 3;
                    fileData = H_Cdvd_CacheFindFile(sSfdDecodePaths[pathIndex], &size[0]);
                    allocBuf = (void*)func_0050B690(0, size[0], 0);
                    if (allocBuf == NULL) { K_Assert("h_sndcom.c", 0x144); }
                    func_00521250(D_00823650, fileData, size[0]);
                    func_0010cce0(allocBuf, D_00823650, size[0]);
                    slot->input = allocBuf;
                    slot->inputSize = size[0];
                    H_Cdvd_Destroy(slot->request);
                    slot->request = NULL;
                    slot->state = 4;
                }
                break;

            case 4:
                pathIndex = slot->fileIndex * 3;
                slot->request = H_Cdvd_Request(sSfdDecodePaths[pathIndex + 1], 0);
                slot->state = 5;
                break;

            case 5:
                if ((slot->request != NULL) && H_Cdvd_IsFileLoaded(slot->request))
                {
                    void* fileData;
                    void* chunkBuf;
                    void* intermediate;
                    s32 remaining;

                    pathIndex = slot->fileIndex * 3;
                    fileData = H_Cdvd_CacheFindFile(sSfdDecodePaths[pathIndex + 1], &size[0]);
                    chunkBuf = (void*)func_0050B690(0, 0x1000, 0);
                    if (chunkBuf == NULL) { K_Assert("h_sndcom.c", 0x177); }
                    intermediate = slot->intermediate;
                    slot->intermediateSize = size[0];
                    remaining = size[0];

                    do {
                        s32 chunkSize;
                        if (remaining > 0x1000) {
                            chunkSize = 0x1000;
                            remaining -= 0x1000;
                        } else {
                            chunkSize = remaining;
                            remaining = 0;
                        }
                        func_0010cce0(chunkBuf, fileData, chunkSize);
                        func_8051DBC0(1, chunkBuf, intermediate, chunkSize);
                        fileData = (void*)((u8*)fileData + chunkSize);
                        intermediate = (void*)((u8*)intermediate + chunkSize);
                    } while (remaining != 0);

                    H_Cdvd_Destroy(slot->request);
                    slot->request = NULL;
                    func_0050B710(chunkBuf);
                    slot->state = 6;
                }
                break;

            case 6:
                pathIndex = slot->fileIndex * 3;
                slot->request = H_Cdvd_Request(sSfdDecodePaths[pathIndex + 2], 0);
                slot->state = 7;
                break;

            case 7:
            {
                void* fileData;
                void* allocBuf;
                void* input;
                void* intermediate;
                s32 inputSize;
                s32 intermediateSize;
                s32 queueHandle;
                s32 decodeHandle;
                s32 auxHandle;

                input = slot->input;
                inputSize = slot->inputSize;
                intermediate = slot->intermediate;
                intermediateSize = slot->intermediateSize;

                if ((slot->request != NULL) && H_Cdvd_IsFileLoaded(slot->request))
                {
                    pathIndex = slot->fileIndex * 3;
                    fileData = H_Cdvd_CacheFindFile(sSfdDecodePaths[pathIndex + 2], &size[0]);
                    allocBuf = (void*)func_0050B690(0, size[0], 0);
                    if (allocBuf == NULL) { K_Assert("h_sndcom.c", 0x1A2); }
                    func_0010cce0(allocBuf, fileData, size[0]);
                    slot->output = allocBuf;
                    slot->outputSize = size[0];
                    H_Cdvd_Destroy(slot->request);
                    slot->request = NULL;

                    queueHandle = func_0051DC70(3, -1, (s32)input,
                                                inputSize, (s32)intermediate,
                                                intermediateSize);
                    if (queueHandle < 0) { K_Assert("h_sndcom.c", 0x1AE); }
                    slot->queueHandle = queueHandle;

                    decodeHandle = func_0051DC70(5, -1, queueHandle, 0);
                    if (decodeHandle < 0) { K_Assert("h_sndcom.c", 0x1B3); }
                    slot->decodeHandle = decodeHandle;

                    auxHandle = func_0051DDF0(0, -1, (s32)slot->output,
                                              slot->outputSize);
                    if (auxHandle < 0) { K_Assert("h_sndcom.c", 0x1B7); }
                    slot->aux = (void*)(s32)auxHandle;

                    slot->completion = (void*)(s32)func_0051DDF0(
                        5, slot->decodeHandle, (s32)slot->aux);
                    slot->status = 1;
                    slot->state = 1;
                }
                break;
            }

            case 8:
            {
                void* input;
                void* intermediate;
                void* output;
                s32 inputSize;
                s32 intermediateSize;
                s32 outputSize;
                void* resourceData;
                void* sourceData;
                void* inputBuf;
                void* auxBuf;
                void* outputData;
                void* outputBuf;
                s32 chunkSize;
                s32 remaining;
                s32 queueHandle;
                s32 decodeHandle;
                s32 auxHandle;
                u32* intermediateSizePtr;
                void** inputPtr;

                input = slot->input;
                inputSize = slot->inputSize;
                intermediate = slot->intermediate;
                intermediateSize = slot->intermediateSize;
                intermediateSizePtr = &slot->intermediateSize;
                inputPtr = &slot->input;
                output = slot->output;
                outputSize = slot->outputSize;
                resourceData = slot->resource;

                copySize = inputSize;
                inputBuf = (void*)func_0050B690(0, copySize, 0);
                if (inputBuf == NULL) { K_Assert("h_sndcom.c", 0x1C8); }
                func_0010cce0(inputBuf, resourceData, copySize);
                slot->input = inputBuf;
                slot->inputSize = copySize;

                remaining = intermediateSize;
                auxBuf = (void*)func_0050B690(0, 0x10000, 0);
                if (auxBuf == NULL) { K_Assert("h_sndcom.c", 0x1DF); }
                outputData = intermediate;

                do {
                    if (remaining > 0x10000) {
                        chunkSize = 0x10000;
                        remaining -= 0x10000;
                    } else {
                        chunkSize = (remaining + 0x7F) & ~0x7F;
                        remaining = 0;
                    }
                    func_0010cce0(auxBuf, inputBuf, chunkSize);
                    func_8051DBC0(1, auxBuf, outputData, chunkSize);
                    inputBuf = (void*)((u8*)inputBuf + chunkSize);
                    outputData = (void*)((u8*)outputData + chunkSize);
                } while (remaining != 0);

                func_0050B710(auxBuf);

                sourceData = slot->sourceData;
                copySize = outputSize;
                outputBuf = (void*)func_0050B690(0, copySize, 0);
                if (outputBuf == NULL) { K_Assert("h_sndcom.c", 0x1FB); }
                func_0010cce0(outputBuf, sourceData, copySize);
                slot->output = outputBuf;

                queueHandle = func_0051DC70(3, -1, (s32)*inputPtr,
                                            slot->inputSize,
                                            (s32)slot->intermediate,
                                            *intermediateSizePtr);
                slot->queueHandle = queueHandle;
                decodeHandle = func_0051DC70(5, -1, queueHandle, 0);
                auxHandle = func_0051DDF0(0, -1, (s32)slot->output,
                                          slot->outputSize);
                slot->aux = (void*)(s32)auxHandle;
                slot->completion = (void*)(s32)func_0051DDF0(
                    5, slot->decodeHandle, (s32)slot->aux);
                slot->status = 1;
                slot->state = 1;
                break;
            }
        }
    }
}

// FUN_0010D6F0
void func_0010d6f0(s16 index, s16 fileIndex)
{
    if (sSfdDecodeSlots[index].state == 1)
    {
        if (sSfdDecodeSlots[index].status != 0)
        {
            func_0010d950(index);
        }
        sSfdDecodeSlots[index].fileIndex = fileIndex;
        sSfdDecodeSlots[index].state = 2;
    }
}

// FUN_0010D7B0 NONMATCHING
void func_0010d7b0(s16 index, s16 fileIndex, void* data0, u32 data0Size,
                   void* data1, u32 data1Size, void* data2, u32 data2Size)
{
    if (sSfdDecodeSlots[index].status != 0)
    {
        func_0010d950(index);
    }

    sSfdDecodeSlots[index].fileIndex = fileIndex;
    sSfdDecodeSlots[index].state = 8;
    sSfdDecodeSlots[index].resource = data0;
    sSfdDecodeSlots[index].aux = data1;
    sSfdDecodeSlots[index].sourceData = data2;
    sSfdDecodeSlots[index].inputSize = data0Size;
    sSfdDecodeSlots[index].intermediateSize = data1Size;
    sSfdDecodeSlots[index].outputSize = data2Size;
}

// FUN_0010D910
u32 func_0010d910(s16 index)
{
    return sSfdDecodeSlots[index].state == 1;
}

// FUN_0010D950
void func_0010d950(s16 index)
{
    u32* slot;

    if (sSfdDecodeSlots_abs[index].state != 1)
    {
        return;
    }
    slot = (u32*)((u8*)sSfdDecodeSlots_abs + 0x18) + index * 17;
    if (*slot != 0)
    {
        FUN_0051deb0(5, (void*)sSfdDecodeSlots_abs[index].completion);
        FUN_0051deb0(0, (void*)sSfdDecodeSlots_abs[index].decodeHandle);
        FUN_0051dd48(5, (void*)sSfdDecodeSlots_abs[index].outputHandle);
        FUN_0051dd48(3, (void*)sSfdDecodeSlots_abs[index].queueHandle);
        *slot = 0;
        func_0050B710(sSfdDecodeSlots_abs[index].output);
        func_0050B710(sSfdDecodeSlots_abs[index].sourceData);
    }
    *slot = 0;
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
        /* Removing this barrier loses func_0010db60 (MATCH nd0 -> MISMATCH nd15) - measured W164. */
        asm ("" : "+m"(outputHandle));
        sSfdCueTable_abs[cue].param = func_0051df58_t(outputHandle, 0, 10, param3, param4);
    }
}
// FUN_0010DD10 NONMATCHING
void func_0010dd10(HSfdImage* image, const u8* source)
{
    u8* dst;
    s32 height;
    s32 width;
    s32 x;
    s32 y;
    u32 alpha;
    u32 opaque;
    dst = image->pixels;
    width = image->width;
    height = image->height;
    opaque = 0xFF;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            u8* pixel = dst + (x * 4);

            pixel[0] = source[0];
            pixel[1] = source[1];
            pixel[2] = source[2];
            alpha = source[3];
            if ((s32)alpha >= 0x7F)
            {
                pixel[3] = opaque;
            }
            else
            {
                pixel[3] = (u8)((u32)(u16)((alpha * 0x100) - alpha) >> 7);
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
    s32 x;
    s32 y;
    u8* dst;
    u8* pixel;
    s32 width;
    s32 height;

    dst = image->pixels;
    width = image->width;
    height = image->height;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            pixel = dst + (x * 4);
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
    s32 width;
    s32 height;
    const u16* pixels;
    s32 y;
    s32 x;
    u32 opaque;
    dst = image->pixels;
    width = image->width;
    height = image->height;
    pixels = (const u16*)source;
    opaque = 0xFF;
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < width)
        {
            u8* pixel = dst + (x * 4);

            pixel[0] = (u8)((pixels[0] & 0x1F) << 3);
            pixel[1] = (u8)(((pixels[0] >> 5) & 0x1F) << 3);
            pixel[2] = (u8)(((pixels[0] >> 10) & 0x1F) << 3);
            pixel[3] = opaque;
            pixels++;
            x++;
        }
        dst += image->stride;
        y++;
    }
}

// FUN_0010DEE0
void func_0010dee0(HSfdImage* image, const u8* source)
{
    u8* dst;
    s32 height;
    s32 width;
    s32 x;
    s32 y;
    s32 count;

    dst = image->pixels;
    width = image->width;
    /* Removing this barrier loses func_0010dee0 (MATCH nd0 -> MISMATCH nd10) - measured W164. */
    asm ("" : "+r"(width));
    height = image->height;
    y = 0;
    count = width >> 1;
    while (y < height)
    {
        x = 0;
        while (x < count)
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
    s32 i;
    s32 count;
    s32 alpha;
    s32 opaque;

    dst = image->palette;
    count = 1 << image->depth;
    opaque = 0xff;
    for (i = 0; i < count; i++)
    {
        dst[i * 4] = source[i * 4];
        dst[i * 4 + 1] = source[i * 4 + 1];
        dst[i * 4 + 2] = source[i * 4 + 2];
        dst[i * 4 + 3] = source[i * 4 + 3];
        alpha = dst[i * 4 + 3];
        if (alpha >= 0x7f)
        {
            dst[i * 4 + 3] = opaque;
        }
        else
        {
            dst[i * 4 + 3] = (u16)((alpha * 0x100 - alpha) / 0x80);
        }
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
    s32 bits;
    const u8* payload;

    payload = stream + 0x40;
    if ((stream[0] != 2) || (stream[1] != 0) ||
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
        case 0x0A:
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
    if (stream[0x10] != 0)
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
            if (stream[0x10] != 0)
                func_0010df60(image, payload);
            func_0010e010(image, bits);
            break;
        case 1:
            func_0010e010(image, bits);
            func_0010ddc0(image, payload);
            break;
        case 2:
        case 0x0A:
            if (stream[0x10] != 0)
                func_0010de40(image, payload);
            func_0010dd10(image, payload);
            func_0010e010(image, bits);
            break;
        case 0x13:
        case 0x1B:
            func_0010e010(image, bits);
            func_0010dee0(image, payload);
            break;
        case 0x14:
        case 0x24:
        case 0x2C:
            func_0010e010(image, bits);
            func_0010df60(image, payload);
            break;
        default:
            if (image->pixels != NULL)
            {
                u8* dst = image->pixels;
                u32 y;
                u32 x;
                y = 0;
                while (y < image->height)
                {
                    x = 0;
                    while (x < image->width)
                    {
                        dst[x] = payload[0];
                        payload++;
                        x++;
                    }
                    dst += image->stride;
                    y++;
                }
            }
            func_0010e010(image, bits);
            break;
    }
    return image;
}

// FUN_0010E500
HSfdImage* func_0010e500(void* stream)
{
    u8 header[0x40];
    void* handle;
    HSfdImage* image;
    u8* buffer;

    image = NULL;
    handle = func_004c58a0(2, 1, stream);
    if (handle != NULL)
    {
        func_004c5250(handle, header, sizeof(header));
        buffer = (*D_00960178_abs)(*(u32*)(header + 4), HSFD_STREAM_HINT);
        func_004c5250(handle, buffer + sizeof(header),
                      *(u32*)(header + 4) - sizeof(header));
        func_00521250(buffer, header, sizeof(header));
        image = func_0010e0d0(buffer);
        (*D_0096017c_abs)(buffer);
        func_004c5780(handle, 0);
    }
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
    volatile u32* regs;
    u8* dst;
    const u8* src;
    u32 count;
    u32 value;

    regs = (volatile u32*)0x10010000;
    dst = (u8*)destination;
    src = (const u8*)source;
    count = size >> 4;
    FUN_004d5e90();

    while (count >= 0x401)
    {
        regs[-0x7F8] = (u32)-0x400;
        regs[-0x7FC] = 0x200;
        regs[-0xAFC] = (u32)src;
        regs[-0xAF8] = 0x400;
        regs[-0xAE0] = 0x70000000;
        value = regs[-0x7F8] | 0x200;
        regs[-0x7F8] = value;
        regs[-0xB00] = 0x101;
        while ((regs[-0xB00] & 0x100) != 0)
            ;

        regs[-0x7F8] = (u32)-0x400;
        regs[-0x7FC] = 0x100;
        regs[-0xBFC] = (u32)dst;
        regs[-0xBF8] = 0x400;
        regs[-0xBE0] = 0x70000000;
        value = regs[-0x7F8] | 0x100;
        regs[-0x7F8] = value;
        regs[-0xC00] = 0x100;
        while ((regs[-0xC00] & 0x100) != 0)
            ;

        src += 0x4000;
        dst += 0x4000;
        count -= 0x400;
    }

    regs[-0x7F8] = (u32)-0x400;
    regs[-0x7FC] = 0x200;
    regs[-0xAFC] = (u32)src;
    regs[-0xAF8] = count;
    regs[-0xAE0] = 0x70000000;
    value = regs[-0x7F8] | 0x200;
    regs[-0x7F8] = value;
    regs[-0xB00] = 0x101;
    while ((regs[-0xB00] & 0x100) != 0)
        ;

    regs[-0x7F8] = (u32)-0x400;
    regs[-0x7FC] = 0x100;
    regs[-0xBFC] = (u32)dst;
    regs[-0xBF8] = count;
    regs[-0xBE0] = 0x70000000;
    value = regs[-0x7F8] | 0x100;
    regs[-0x7F8] = value;
    regs[-0xC00] = 0x101;
    while ((regs[-0xC00] & 0x100) != 0)
        ;

    if ((regs[-0xB00] & 0x100) != 0)
    {
        regs[-0x7F8] = (u32)-0x400;
        regs[-0x7FC] = 0x100;
        regs[-0xBFC] = (u32)dst;
        regs[-0xBF8] = count;
        regs[-0xBE0] = 0x70000000;
        value = regs[-0x7F8] | 0x100;
        regs[-0x7F8] = value;
        regs[-0xC00] = 0x101;
        while ((regs[-0xC00] & 0x100) != 0)
            ;
    }
}

// Retail reconstruction covers TMX validation, raster setup, pixel decode, and palette upload from offsets 0x00-0x3C8; all non-padding retail logic is represented, with only register/relocation differences remaining.
// FUN_0010E880 NONMATCHING
void* func_0010e880(const u8* stream)
{
    s32 bits;
    s32 flags = 0;
    s32 paletteFormat = 0;
    const u8* source;
    const u8* pixelSource;
    s32 pixelsPerPalette;
    void* raster;
    void* pixels;
    void* palette;

    if (stream == NULL)
    {
        K_Assert(&gp0xffff8840, 0x454);
    }
    if (stream[0] != 2)
    {
        K_Assert(&gp0xffff8840, 0x458);
    }
    if (stream[1] != 0)
    {
        K_Assert(&gp0xffff8840, 0x459);
    }
    if (((stream[8] != 'T') || (stream[9] != 'M') || (stream[10] != 'X')) &&
        (stream[11] != '0'))
    {
        K_Assert(&gp0xffff8840, 0x45A);
    }

    switch (stream[0x16])
    {
        case 0:
            bits = 0x20;
            break;
        case 1:
            bits = 0x18;
            break;
        case 0x0A:
        case 2:
            bits = 0x10;
            break;
        case 0x1B:
        case 0x13:
            bits = 8;
            flags = 0x2000;
            break;
        case 0x24:
        case 0x2C:
        case 0x14:
            bits = 4;
            flags = 0x4000;
            break;
        default:
            bits = 0;
            break;
    }

    if (stream[0x10] != 0)
    {
        switch (stream[0x11])
        {
            case 0:
                paletteFormat = 0x20;
                break;
            case 2:
            case 0x0A:
                paletteFormat = 0x10;
                break;
            default:
                paletteFormat = 0;
                break;
        }
    }

    source = stream + 0x40;
    pixelsPerPalette = 1 << bits;
    pixelSource = source +
                  ((paletteFormat * (stream[0x10] * pixelsPerPalette)) >> 3);
    raster = func_004ce0f0(*(const u16*)(stream + 0x12),
                           *(const u16*)(stream + 0x14), bits, flags | 0x504);
    if (raster == NULL)
    {
        K_Assert(&gp0xffff8840, 0x48E);
    }

    pixels = func_004ce200(raster, NULL, 1);
    if (pixels == NULL)
    {
        K_Assert(&gp0xffff8840, 0x490);
    }

    switch (bits)
    {
        case 0x20:
        case 0x18:
            func_0010e630(pixels, pixelSource,
                          *(const u16*)(stream + 0x12) *
                              *(const u16*)(stream + 0x14) * 4);
            break;
        case 0x10:
            func_0010e630(pixels, pixelSource,
                          *(const u16*)(stream + 0x12) *
                              *(const u16*)(stream + 0x14) * 2);
            break;
        case 8:
            func_0010e630(pixels, pixelSource,
                          *(const u16*)(stream + 0x12) *
                              *(const u16*)(stream + 0x14));
            break;
        case 4:
            func_0010e630(pixels, pixelSource,
                          ((s32)*(const u16*)(stream + 0x12) >> 1) *
                              *(const u16*)(stream + 0x14));
            break;
    }

    func_004cde00(raster);
    if (stream[0x10] != 0)
    {
        palette = func_004cdf30(raster, 1);
        if (palette == NULL)
        {
        K_Assert(&gp0xffff8840, 0x4BB);
        }
        func_0010e630(palette, source, pixelsPerPalette * 4);
        func_004cde40(raster);
    }
    return raster;
}

// Reconstructed from the retail window. The opening is the same render-state
// prologue the sibling func_0010f6c0 already carries: two indirect calls
// through the D_00960090 render-state hook, near/far plane setup, a full
// 640x448 viewport, camera bind, then the 0x4e4 flag selecting between two
// RpSkyRenderStateSet pairs. Retail then gates the whole body on work[0] == 3
// (bne $a0, 3 branches to the tail); that body is fully reconstructed here
// as an element-loop over frame commands with color processing.
// FUN_0010EC50 NONMATCHING
void func_0010ec50(KwlnTask* task)
{
    u8* work;
    u8* entry;
    u8* frames;
    HSfdRenderFrame* record;
    void* resource;
    unsigned __int128 quad;
    void (**setRenderState)(u32, u32);
    RwCamera* camera;
    s32 element;
    s32 frame;
    s32 type;
    s32 mode;
    s32 found;
    s32 draw;
    s32 colorReady;
    s32 layer;
    s32 i;
    s32 j;
    s32 baseX;
    s32 baseY;
    s64 screenX;
    s16 screenY;
    s64 red;
    s64 green;
    s64 blue;
    s64 alpha;
    unsigned __int128 colorBase;
    u64 frameOffset;
    u8 colorBytes[4];
    s32 colorState;
    f32 zero;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    f32 x2;
    f32 y2;
    s32 out0;
    f32 out1;
    f32 out2;
    f32 out3;
    f32 out4;
    s32 out5;
    s32 out6;
    s32 out7;

    work = (u8*)task->workData;
    setRenderState = (void (**)(u32, u32))D_00960090_abs;
    (*setRenderState)(8, 0);
    (*setRenderState)(6, 0);
    func_004aa390(0.5f);
    camera = kwlnGetMainCamera();
    func_004aa3d0(gUnk_007cadd0 * camera->nearPlane);
    func_004a9f20(0.0f, 0.0f, 640.0f, 448.0f);
    func_004aa410(kwlnGetMainCamera());

    if (*(s32*)(work + 0x4e4) != 0)
    {
        RpSkyRenderStateSet(2, (void*)0x48);
        RpSkyRenderStateSet(3, (void*)0x71801);
    }
    else
    {
        RpSkyRenderStateSet(2, (void*)0x44);
        RpSkyRenderStateSet(3, (void*)0x717fb);
    }

    type = *(s32*)work;
    if (type != 3)
    {
        return;
    }

    func_004aaa60();
    func_004a9bf0();
    func_004aaa60();
    colorState = 0;
    element = 0;
    for (; element < *(s32*)(work + 0x4e0); element++)
    {
        colorReady = 0;
        layer = 0;
        found = 0;
        draw = 0;
        entry = work + element * 4;
        frame = *(s32*)(entry + 0x1e8);
        resource = *(void**)(entry + 0xa8);
        func_004ac5f0(resource);
        func_004ab1b0(resource);
        colorBase = (unsigned __int128)(work + element * 2);
        quad = (unsigned __int128)(work + colorState * 4);
        while (draw == 0)
        {
            if (colorReady == 0)
            {
                frames = *(u8**)(entry + 8);
                frameOffset = (unsigned __int128)(frame * 0x12);
                record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                if (record->command != -1)
                {
                    red = (record->colorR < 0x100) ?
                          (s8)(record->colorR & 0xff) : 0xff;
                    green = (record->colorG < 0x100) ?
                            (s8)(record->colorG & 0xff) : 0xff;
                    blue = (record->colorB < 0x100) ?
                           (s8)(record->colorB & 0xff) : 0xff;
                    alpha = (record->colorA < 0x100) ?
                            (record->colorA & 0xff) : 0xff;
                    red += *(s16*)((u8*)colorBase + 0x3f0);
                    green += *(s16*)((u8*)colorBase + 0x440);
                    blue += *(s16*)((u8*)colorBase + 0x490);
                    if (red < 0)
                        red = 0;
                    if (red >= 0x100)
                        red = 0xff;
                    if (green < 0)
                        green = 0;
                    if (green >= 0x100)
                        green = 0xff;
                    if (blue < 0)
                        blue = 0;
                    if (blue >= 0x100)
                        blue = 0xff;
                    colorBytes[0] = (u8)red;
                    colorBytes[1] = (u8)green;
                    colorBytes[2] = (u8)blue;
                    colorBytes[3] = (u8)alpha;
                    colorReady = 1;
                }
            }

            frames = *(u8**)(entry + 8);
            frameOffset = (unsigned __int128)(frame * 0x12);
            record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
            if (record->command != -1)
            {
                if ((record->command == 2) && (draw == 0))
                {
                    draw = 1;
                    func_004a62e0(*(void**)(entry + 0x148),
                                  *(void**)((u8*)quad + 0x328));
                    out0 = 0;
                    zero = *(f32*)((u8*)work - 0x7cf8);
                    out1 = zero;
                    out2 = zero;
                    out3 = zero;
                    out4 = zero;
                    out5 = 0;
                    out6 = 0;
                    out7 = 0;
                    func_004a6200(*(void**)(entry + 0x148),
                                  &out0, &out2, &out4, &out6);
                }

                frames = *(u8**)(entry + 8);
                record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                switch (record->command)
                {
                    case 0:
                        if (layer != 0)
                        {
                            if (layer >= 3)
                                func_004ab6a0(resource);
                            func_004ac710(resource);
                            func_004aaa60();
                            func_004aae00(0.0f, 0.0f);
                            if (layer < 3)
                                func_004ace70(resource, *(void**)(entry + 0x148));
                            else
                                func_004a6600(resource, *(void**)(entry + 0x148));
                            func_004aad50();
                            func_004ac5f0(resource);
                            func_004ab1b0(resource);
                            layer = 0;
                        }
                        record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                        *(s32*)(entry + 0x288) = record->type;
                        func_004ab200(
                            resource,
                            (f32)((s32)*(f32*)(work + 0x3d8) + record->x0),
                            (f32)(448 - ((s32)*(f32*)(work + 0x3dc) + record->y0)));
                        frames = *(u8**)(entry + 8);
                        frameOffset = (u64)(frame * 0x12);
                        record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                        screenX = (s64)(s16)((s32)*(f32*)(work + 0x3d8) +
                                             record->x0);
                        screenY = (s16)(448 -
                                        ((s32)*(f32*)(work + 0x3dc) +
                                         record->y0));
                        func_004a5dd0(*(void**)(entry + 0x148),
                                      (s8*)colorBytes, (s8*)colorBytes,
                                      (s8*)colorBytes, (s8*)colorBytes);
                        layer++;
                        found = 1;
                        break;

                    case 1:
                        *(s32*)(entry + 0x288) = record->type;
                        if (layer == 0)
                        {
                            frames = *(u8**)(entry + 8);
                            frameOffset = (u64)(frame * 0x12);
                            record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                            func_004ab200(
                                resource,
                                (f32)((s32)*(f32*)(work + 0x3d8) +
                                      record->x0),
                                (f32)(448 -
                                      ((s32)*(f32*)(work + 0x3dc) +
                                       record->y0)));
                        }
                        else
                        {
                            frames = *(u8**)(entry + 8);
                            frameOffset = (u64)(frame * 0x12);
                            record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                            func_004ab2c0(
                                resource,
                                (f32)((s32)*(f32*)(work + 0x3d8) +
                                      record->x0),
                                (f32)(448 -
                                      ((s32)*(f32*)(work + 0x3dc) +
                                       record->y0)));
                        }
                        frames = *(u8**)(entry + 8);
                        frameOffset = (u64)(frame * 0x12);
                        record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                        screenX = (s64)(s16)((s32)*(f32*)(work + 0x3d8) +
                                             record->x0);
                        screenY = (s16)(448 -
                                        ((s32)*(f32*)(work + 0x3dc) +
                                         record->y0));
                        func_004a5dd0(*(void**)(entry + 0x148),
                                      (s8*)colorBytes, (s8*)colorBytes,
                                      (s8*)colorBytes, (s8*)colorBytes);
                        found = 1;
                        layer++;
                        break;

                    case 2:
                        *(s32*)(entry + 0x288) = record->type;
                        frames = *(u8**)(entry + 8);
                        frameOffset = (unsigned __int128)(frame * 0x12);
                        record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                        baseX = (s32)*(f32*)(work + 0x3d8);
                        baseY = (s32)*(f32*)(work + 0x3dc);
                        x0 = (f32)(s32)screenX;
                        y0 = (f32)screenY;
                        x1 = (f32)(baseX + record->x0);
                        y1 = (f32)(448 - (baseY + record->y0));
                        x2 = (f32)(baseX + record->x1);
                        y2 = (f32)(448 - (baseY + record->y1));
                        func_004ab410(resource, x0, y0, x1, y1,
                                      x2, y2);
                        frames = *(u8**)(entry + 8);
                        frameOffset = (u64)(frame * 0x12);
                        record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                        screenX = (s64)(s16)(baseX + record->x1);
                        screenY = (s16)(448 - (baseY + record->y1));
                        func_004a5dd0(*(void**)(entry + 0x148),
                                      (s8*)colorBytes, (s8*)colorBytes,
                                      (s8*)colorBytes, (s8*)colorBytes);
                        layer++;
                        found = 1;
                        break;
                }
                frame++;
            }
                    else
                    {
                        break;
                    }
        }

        if (found != 0)
        {
            if (layer >= 3)
                func_004ab6a0(resource);
            func_004ac710(resource);
            func_004aaa60();
            func_004aae00(0.0f, 0.0f);
            mode = *(s32*)(entry + 0x288);
            if (mode == 1)
            {
                if (layer < 3)
                    func_004ace70(resource, *(void**)(entry + 0x148));
                else
                    func_004a6600(resource, *(void**)(entry + 0x148));
            }
            else if (mode == 2)
            {
                j = 0;
                for (i = element - 1; i >= 0; i--)
                {
                    quad = (unsigned __int128)(work + i * 4);
                    if (*(s32*)((u8*)quad + 0x288) == 0)
                    {
                        func_00110650(work, i, element);
                        if (layer >= 3)
                            func_004a6600(*(void**)((u8*)quad + 0xa8),
                                          *(void**)(entry + 0x148));
                        j = 1;
                        break;
                    }
                }
                if ((j == 0) && (layer >= 3))
                    func_004a6600(resource, *(void**)(entry + 0x148));
            }
            func_004aad50();
        }
        else
        {
            func_004ac710(resource);
        }
        if ((draw != 0) && (colorState != 1))
            colorState++;
    }
    func_004aad50();
    func_004aad50();
}

// Retail 0x10fbe4-0x110250 re-fetches command pointers and carries the prior
// endpoint into command-2 rectangles; preserve those conversions and spill slots.
// FUN_0010F6C0 NONMATCHING
void func_0010f6c0(KwlnTask* task)
{
    u8* work;
    u8* entry;
    u8* frames;
    HSfdRenderFrame* record;
    void* resource;
    unsigned __int128 quad;
    void (**setRenderState)(u32, u32);
    RwCamera* camera;
    s32 element;
    s32 frame;
    s32 type;
    s32 mode;
    s32 found;
    s32 draw;
    s32 colorReady;
    s32 layer;
    s32 i;
    s32 j;
    s32 baseX;
    s32 baseY;
    s64 screenX;
    s16 screenY;
    s64 red;
    s64 green;
    s64 blue;
    s64 alpha;
    unsigned __int128 colorBase;
    u64 frameOffset;
    u8 colorBytes[4];
    s32 colorState;
    f32 zero;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    f32 x2;
    f32 y2;
    s32 out0;
    f32 out1;
    f32 out2;
    f32 out3;
    f32 out4;
    s32 out5;
    s32 out6;
    s32 out7;

    work = (u8*)task->workData;
    setRenderState = (void (**)(u32, u32))D_00960090_abs;
    (*setRenderState)(8, 0);
    (*setRenderState)(6, 0);
    func_004aa390(0.5f);
    camera = kwlnGetMainCamera();
    func_004aa3d0(gUnk_007cadd0 * camera->nearPlane);
    func_004a9f20(0.0f, 0.0f, 640.0f, 448.0f);
    func_004aa410(kwlnGetMainCamera());

    if (*(s32*)(work + 0x4e4) != 0)
    {
        RpSkyRenderStateSet(2, (void*)0x48);
        RpSkyRenderStateSet(3, (void*)0x71801);
    }
    else
    {
        RpSkyRenderStateSet(2, (void*)0x44);
        RpSkyRenderStateSet(3, (void*)0x717fb);
    }

    type = *(s32*)work;
    switch (type)
    {
        case 0:
            for (element = 0; element < *(s32*)(work + 0x4e0); element++)
            {
                entry = work + element * 4;
                resource = func_004a5470();
                *(void**)(entry + 0x148) = resource;
                func_004a5dd0(resource, fGpffff7788, fGpffff7788,
                              fGpffff7788, fGpffff7788);
                *(s32*)(entry + 0x288) = -1;
            }
            for (element = 0; element < *(s32*)(work + 0x4e0); element++)
            {
                entry = work + element * 4;
                resource = func_004ac570();
                *(void**)(entry + 0xa8) = resource;
                func_004ac5f0(resource);
                func_004ab1b0(resource);
                func_004ac5f0(resource);
                *(s32*)(entry + 0x1e8) = 0;
            }
            frames = *(u8**)(work + 4);
            *(void**)(work + 8) = *(void**)(work + 4);
            j = 0;
            i = 1;
            for (; i < *(s32*)(work + 0x4e0); i++)
            {
                while (*(s8*)(frames + j * 0x12 + 1) != -2)
                {
                    j++;
                }
                j++;
                *(void**)(work + i * 4 + 8) = frames + j * 0x12;
            }
            *(s32*)work = 1;
            break;

        case 1:
            *(s32*)work = 2;
            break;

        case 2:
            return;

        case 3:
            if (*(s32*)(work + 0x4e8) != 0)
            {
                return;
            }
            func_004aaa60();
            func_004a9bf0();
            func_004aaa60();
            colorState = 0;
            element = 0;
            for (; element < *(s32*)(work + 0x4e0); element++)
            {
                colorReady = 0;
                layer = 0;
                found = 0;
                draw = 0;
                entry = work + element * 4;
                frame = *(s32*)(entry + 0x1e8);
                resource = *(void**)(entry + 0xa8);
                func_004ac5f0(resource);
                func_004ab1b0(resource);
                colorBase = (unsigned __int128)(work + element * 2);
                quad = (unsigned __int128)(work + colorState * 4);
                while (draw == 0)
                {
                    if (colorReady == 0)
                    {
                        frames = *(u8**)(entry + 8);
                        frameOffset = (unsigned __int128)(frame * 0x12);
                        record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                        if (record->command != -1)
                        {
                            red = (record->colorR < 0x100) ?
                                  (s8)(record->colorR & 0xff) : 0xff;
                            green = (record->colorG < 0x100) ?
                                    (s8)(record->colorG & 0xff) : 0xff;
                            blue = (record->colorB < 0x100) ?
                                  (s8)(record->colorB & 0xff) : 0xff;
                            alpha = (record->colorA < 0x100) ?
                                    (record->colorA & 0xff) : 0xff;
                            red += *(s16*)((u8*)colorBase + 0x3f0);
                            green += *(s16*)((u8*)colorBase + 0x440);
                            blue += *(s16*)((u8*)colorBase + 0x490);
                            if (red < 0)
                                red = 0;
                            if (red >= 0x100)
                                red = 0xff;
                            if (green < 0)
                                green = 0;
                            if (green >= 0x100)
                                green = 0xff;
                            if (blue < 0)
                                blue = 0;
                            if (blue >= 0x100)
                                blue = 0xff;
                            colorBytes[0] = (u8)red;
                            colorBytes[1] = (u8)green;
                            colorBytes[2] = (u8)blue;
                            colorBytes[3] = (u8)alpha;
                            colorReady = 1;
                        }
                    }

                    frames = *(u8**)(entry + 8);
                    frameOffset = (unsigned __int128)(frame * 0x12);
                    record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                    if (record->command != -1)
                    {
                        if ((record->command == 2) && (draw == 0))
                        {
                            draw = 1;
                            func_004a62e0(*(void**)(entry + 0x148),
                                          *(void**)((u8*)quad + 0x328));
                            out0 = 0;
                            zero = *(f32*)((u8*)work - 0x7cf8);
                            out1 = zero;
                            out2 = zero;
                            out3 = zero;
                            out4 = zero;
                            out5 = 0;
                            out6 = 0;
                            out7 = 0;
                            func_004a6200(*(void**)(entry + 0x148),
                                          &out0, &out2, &out4, &out6);
                        }
                        frames = *(u8**)(entry + 8);
                        record = (HSfdRenderFrame*)(frames + (u32)frameOffset);

                        switch (record->command)
                        {
                            case 0:
                                if (layer != 0)
                                {
                                    if (layer >= 3)
                                        func_004ab6a0(resource);
                                    func_004ac710(resource);
                                    func_004aaa60();
                                    func_004aae00(0.0f, 0.0f);
                                    if (layer < 3)
                                        func_004ace70(resource, *(void**)(entry + 0x148));
                                    else
                                        func_004a6600(resource, *(void**)(entry + 0x148));
                                    func_004aad50();
                                    func_004ac5f0(resource);
                                    func_004ab1b0(resource);
                                }
                                record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                                *(s32*)(entry + 0x288) = record->type;
                                func_004ab200(
                                    resource,
                                    (f32)((s32)*(f32*)(work + 0x3d8) + record->x0),
                                    (f32)(448 - ((s32)*(f32*)(work + 0x3dc) + record->y0)));
                                frames = *(u8**)(entry + 8);
                                frameOffset = (u64)(frame * 0x12);
                                record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                                screenX = (s64)(s16)((s32)*(f32*)(work + 0x3d8) +
                                                     record->x0);
                                screenY = (s16)(448 -
                                                ((s32)*(f32*)(work + 0x3dc) +
                                                 record->y0));
                                func_004a5dd0(*(void**)(entry + 0x148),
                                              (s8*)colorBytes, (s8*)colorBytes,
                                              (s8*)colorBytes, (s8*)colorBytes);
                                layer++;
                                found = 1;
                                break;

                            case 1:
                                *(s32*)(entry + 0x288) = record->type;
                                if (layer == 0)
                                {
                                    frames = *(u8**)(entry + 8);
                                    frameOffset = (u64)(frame * 0x12);
                                    record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                                    func_004ab200(
                                        resource,
                                        (f32)((s32)*(f32*)(work + 0x3d8) +
                                              record->x0),
                                        (f32)(448 -
                                              ((s32)*(f32*)(work + 0x3dc) +
                                               record->y0)));
                                }
                                else
                                {
                                    frames = *(u8**)(entry + 8);
                                    frameOffset = (u64)(frame * 0x12);
                                    record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                                    func_004ab2c0(
                                        resource,
                                        (f32)((s32)*(f32*)(work + 0x3d8) +
                                              record->x0),
                                        (f32)(448 -
                                              ((s32)*(f32*)(work + 0x3dc) +
                                               record->y0)));
                                }
                                frames = *(u8**)(entry + 8);
                                frameOffset = (u64)(frame * 0x12);
                                record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                                screenX = (s64)(s16)((s32)*(f32*)(work + 0x3d8) +
                                                     record->x0);
                                screenY = (s16)(448 -
                                                ((s32)*(f32*)(work + 0x3dc) +
                                                 record->y0));
                                func_004a5dd0(*(void**)(entry + 0x148),
                                              (s8*)colorBytes, (s8*)colorBytes,
                                              (s8*)colorBytes, (s8*)colorBytes);
                                found = 1;
                                layer++;
                                break;
 
                            case 2:
                                *(s32*)(entry + 0x288) = record->type;
                                frames = *(u8**)(entry + 8);
                                frameOffset = (unsigned __int128)(frame * 0x12);
                                record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                                x0 = (f32)(s32)screenX;
                                y0 = (f32)screenY;
                                x1 = (f32)((s32)*(f32*)(work + 0x3d8) +
                                           record->x0);
                                y1 = (f32)(448 -
                                           ((s32)*(f32*)(work + 0x3dc) +
                                            record->y0));
                                x2 = (f32)((s32)*(f32*)(work + 0x3d8) +
                                           record->x1);
                                y2 = (f32)(448 -
                                           ((s32)*(f32*)(work + 0x3dc) +
                                            record->y1));
                                func_004ab410(resource, x0, y0, x1, y1,
                                              x2, y2);
                                frames = *(u8**)(entry + 8);
                                frameOffset = (u64)(frame * 0x12);
                                record = (HSfdRenderFrame*)(frames + (u32)frameOffset);
                                screenX = (s64)(s16)((s32)*(f32*)(work + 0x3d8) +
                                                     record->x1);
                                screenY = (s16)(448 -
                                                ((s32)*(f32*)(work + 0x3dc) +
                                                 record->y1));
                                func_004a5dd0(*(void**)(entry + 0x148),
                                              (s8*)colorBytes, (s8*)colorBytes,
                                              (s8*)colorBytes, (s8*)colorBytes);
                                layer++;
                                found = 1;
                                break;
                        }
                        frame++;
                    }
                    else
                    {
                        break;
                    }
                }

                if (found != 0)
                {
                    if (layer >= 3)
                        func_004ab6a0(resource);
                    func_004ac710(resource);
                    func_004aaa60();
                    func_004aae00(0.0f, 0.0f);
                    mode = *(s32*)(entry + 0x288);
                    if (mode == 1)
                    {
                        if (layer < 3)
                            func_004ace70(resource, *(void**)(entry + 0x148));
                        else
                            func_004a6600(resource, *(void**)(entry + 0x148));
                    }
                    else if (mode == 2)
                    {
                        j = 0;
                        for (i = element - 1; i >= 0; i--)
                        {
                            quad = (unsigned __int128)(work + i * 4);
                            if (*(s32*)((u8*)quad + 0x288) == 0)
                            {
                                func_00110650(work, i, element);
                                if (layer >= 3)
                                    func_004a6600(*(void**)((u8*)quad + 0xa8),
                                                  *(void**)(entry + 0x148));
                                j = 1;
                                break;
                            }
                        }
                        if ((j == 0) && (layer >= 3))
                            func_004a6600(resource, *(void**)(entry + 0x148));
                    }
                    func_004aad50();
                }
                else
                {
                    func_004ac710(resource);
                }
                if ((draw != 0) && (colorState != 1))
                    colorState++;
            }
            func_004aad50();
            func_004aad50();
            break;
    }
}
