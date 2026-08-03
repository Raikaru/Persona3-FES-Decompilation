#include "h_dbprt.h"
#include "h_cdvd.h"
#include "Kernel/Kwln/kwln.h"
#include "temporary.h"

#pragma alias printf_y2 printf
#pragma alias D_009600A0_y2 D_009600A0


typedef char* va_list;
#define va_start(ap, last) (ap = ((va_list)__builtin_next_arg(last) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8)))
#define va_end(ap) ((void)0)
extern int vsprintf(char* buffer, const char* fmt, va_list args);

#define HDBPRT_LOG_MAXLINE 15
#define HDBPRT_LOG_MAXCHAR 256
#define HDBPRT_GRID_WIDTH  (640 / 12)
#define HDBPRT_GRID_HEIGHT (480 / 12)

const RwV2d sLogBoxPos = {28.0f, 42.0f};
const RwV2d sLogStringsPos = {36.0f, 50.0f};

static RwRaster* sFontRaster;
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
#pragma alias D_00960088_abs D_00960088
extern volatile /* Removing this file's qualifier batch loses 0 MATCH(es) and worsens 1 other function(s) - measured W170. */ f32 D_00960088_abs[];
extern RwIm2DRenderPrimitiveFunction D_009600A0_abs[];
#pragma alias hDbprtDrawPrimitiveSlot D_009600A0
extern RwIm2DRenderPrimitiveFunction hDbprtDrawPrimitiveSlot[];

extern void (*D_00960090)(u32 state, u32 value);
extern f32 D_00960088;
extern RwBool (*D_009600A0)(RwPrimitiveType primitiveType,
                            RwIm2DVertex* vertices, s32 vertexCount);
static RwImage* sFontImage;
static HDbText3D* sText3DList;
static s8 sLogLine;
static u32 sDrawLogEnabled;
static char sGrid[HDBPRT_GRID_HEIGHT][HDBPRT_GRID_WIDTH];
static char sLogs[HDBPRT_LOG_MAXLINE][HDBPRT_LOG_MAXCHAR];



static void H_Dbprt_DrawText3D(void);
static f32 H_Dbprt_CalculateScreenZ(f32 zOffset);
static void H_Dbprt_DrawLog(void);
static void H_Dbprt_AppendText3D(HDbText3D* text);


#include "h_chrdsp.h"
#include "Main/g_data.h"
#define HCHRDP_WORK_COUNT 3
#define HCHRDP_LAYER_COUNT 3
#define HCHRDP_QUAD_COUNT  5
#define rwTEXTUREADDRESSBORDER 4
typedef struct HChrdspTexture
{
    RwRaster* raster;
    u8 reserved04[0x4c];
    u32 renderFlags;
} HChrdspTexture;
extern HChrdspWork D_007E2680[HCHRDP_WORK_COUNT];
typedef void (*HChrdspDrawPrimitive)(s32 primitiveType, RwIm2DVertex* vertices,
                                     s32 vertexCount);
extern HChrdspDrawPrimitive hChrdspDrawPrimitiveSlot[];
extern void* D_007E2BA8[][0x19C];
extern void* D_007E2BC8[][0x19C];
extern s16 D_007E2684[][0x338];
extern s16 D_007E2688[][0x338];
extern s16 D_007E268A[][0x338];
extern s32 D_007E2BCC[][0x19C];
extern u8 D_007E2BA0[][0x670];
extern u8 D_007E2BA1[][0x670];
extern u8 D_007E2BA2[][0x670];
extern u8 D_007E2BA3[][0x670];
extern f32 D_007E2BAC[][0x19C];
extern f32 D_007E2BB0[][0x19C];
extern u32 D_007E2BE4[][0x19C];
extern const char* D_005D3350[];
extern const char D_005D3CB0[];
extern const char D_005D3CD0[];
extern const char D_005D3CF0[];
extern const char D_005D3D10[];
extern const char D_005D3D30[];
extern const char D_005D3D50[];
extern const char D_005D3D70[];
extern const char D_005D3D90[];
extern const char D_005D3DB0[];
extern const char D_005D3DD0[];
extern const char D_005D3DF0[];
extern const char D_005D3E10[];
extern const char D_005D3E30[];
extern const char D_005D3E50[];
extern const char D_005D3E70[];
extern const char* func_001022e0(HCdvd* cdvd, s32 entryIndex);
extern void* func_0010c1a0(s32 kind, const char* name, const char* path,
                            s32 requestFlags, void* source, void* buffer,
                            s32 byteCount, const char* cacheName,
                            void* result2, void* result3, void* result4);
extern void* func_0010c3a0(void* request, u32* isReady, s32* byteCount);
extern s32 sprintf(char* buffer, const char* format, ...);
extern s32 printf(const char* format, ...);
extern char* strcpy(char* destination, const char* source);
extern s32 strcmp(const char* lhs, const char* rhs);
extern void func_00133d30(void* stream, HCdvd* cdvd);
extern void func_004d0f00(void* resource);
#include "h_pad.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "Kernel/h_malloc.h"
#include "Kosaka/k_assert.h"
#define HPAD_PAD_STATE_FIND_CTP1 2
#define HPAD_PAD_STATE_STABLE    6
typedef struct HPadRwAllocation
{
    u32 size;
    u32 alignment;
    u32 serial;
    u32 hint;
} HPadRwAllocation;
extern s32 scePadGetState(s32 port, s32 slot);
extern s32 scePadSetMainMode(s32 port, s32 slot, s32 mode, s32 lock);
extern s32 scePadInfoAct(s32 port, s32 slot, s32 actuator, s32 command);
extern s32 scePadSetActAlign(s32 port, s32 slot, u8* align);
extern s32 scePadGetReqState(s32 port, s32 slot);
extern s32 scePadRead(s32 port, s32 slot, u8* data);
extern s32 scePadSetActDirect(s32 port, s32 slot, u8* data);
extern void* func_00520728(size_t size);
extern void func_00520748(void* memory);
extern const char D_005CEAE0[];
extern const char D_005CEAE0_sda[] __attribute__((section(".sdata")));
extern const char D_005CEAF0[];
extern const char D_005CEB10[];
extern const char D_005CEB30[];
HPad gWorkPads[HPAD_PORT_MAX]; // 007e09b0
HPad gPads[HPAD_PORT_MAX];     // 007e0940
static u_long128 sAddrPort1[scePadDmaBufferMax] __attribute__((aligned(64))); // 007e0840
static u_long128 sAddrPort2[scePadDmaBufferMax] __attribute__((aligned(64))); // 007e0740
static u8 sRDataPort2[32]; // 007e0720
static u8 sRDataPort1[32]; // 007e0700
extern u8 gWorkPads_abs[];
extern u8 gPads_abs[];
extern u8 sAddrPort1_abs[];
extern u8 sAddrPort2_abs[];
static s16 sRumbleState;
static union
{
    u16 h;
    u8 b;
} sRumbleIntensity;
static s16 sRumblePhase;
static s16 sRumbleOffFrames;
static s16 sRumbleOnFrames;
static s16 sRumbleCadence;
static s16 sRumbleDuration;
static s32 sRwAllocatedBytes;
static u32 sRwAllocationCount;
static u32 sRwCallocCount;
static u32 sRwReallocCount;
static u32 sRwAllocationHint;
static RwMemoryFunctions sRwMemoryFunctions;
#pragma alias sRwReallocCount_sda sRwReallocCount
extern u32 sRwReallocCount_sda __attribute__((section(".sdata")));

static inline void H_Dbprt_AppendText3D(HDbText3D* text)
{
    HDbText3D* last;

    if (sText3DList == NULL)
    {
        sText3DList = text;
        return;
    }

    last = sText3DList;
    for (;;)
    {
        if (last->next == NULL)
        {
            last->next = text;
            break;
        }
        last = last->next;
    }
}
static void H_Chrdsp_BuildQuad(RwIm2DVertex* vertices, f32 x, f32 y, f32 width,
                                f32 height, f32 z, f32 recipZ, const RwRGBA* color)
{
    s32 vertexIndex;

    for (vertexIndex = 0; vertexIndex < 4; vertexIndex++)
    {
        vertices[vertexIndex].u.els.scrVertex.z = z;
        vertices[vertexIndex].u.els.recipZ = recipZ;
        vertices[vertexIndex].u.els.color.r = (f32)color->r;
        vertices[vertexIndex].u.els.color.g = (f32)color->g;
        vertices[vertexIndex].u.els.color.b = (f32)color->b;
        vertices[vertexIndex].u.els.color.a = (f32)color->a;
    }

    vertices[0].u.els.scrVertex.x = x;
    vertices[0].u.els.scrVertex.y = y;
    vertices[0].u.els.u = 0.0f;
    vertices[0].u.els.v = 0.0f;

    vertices[1].u.els.scrVertex.x = x + width;
    vertices[1].u.els.scrVertex.y = y;
    vertices[1].u.els.u = 1.0f;
    vertices[1].u.els.v = 0.0f;

    vertices[2].u.els.scrVertex.x = x;
    vertices[2].u.els.scrVertex.y = y + height;
    vertices[2].u.els.u = 0.0f;
    vertices[2].u.els.v = 1.0f;

    vertices[3].u.els.scrVertex.x = x + width;
    vertices[3].u.els.scrVertex.y = y + height;
    vertices[3].u.els.u = 1.0f;
    vertices[3].u.els.v = 1.0f;
}
static void H_Chrdsp_RenderTexture(HChrdspTexture* texture, RwIm2DVertex* vertices)
{
    RwRenderStateSet(rwRENDERSTATETEXTURERASTER, texture->raster);
    RwIm2DRenderPrimitive(rwPRIMTYPETRISTRIP, vertices, 4);
}
static s32 H_Chrdsp_GetFadeFrames(s32 index)
{
    switch (index)
    {
    case 0:
        return 3;
    case 1:
        return 100;
    case 2:
    case 3:
    case 4:
        return 2;
    default:
        return 80;
    }
}
static f32 H_Chrdsp_GetOverlayYOffset(const HChrdspWork* work)
{
    switch (work->characterId)
    {
    case 15:
        return 189.0f;
    case 10:
        return 149.0f;
    case 39:
        return 81.0f;
    case 30:
        return 100.0f;
    case 42:
        return 76.0f;
    case 48:
        return 97.0f;
    case 12:
        return 134.0f;
    case 9:
        return 122.0f;
    case 5:
        if ((work->variant == 4) || (work->variant == 5) || (work->variant == 6))
        {
            return 101.0f;
        }
        return 111.0f;
    case 8:
        return 130.0f;
    case 6:
        return 116.0f;
    case 13:
        return 119.0f;
    case 27:
        return 136.0f;
    default:
        return 111.0f;
    }
}
static void H_Chrdsp_AdvanceAlphaTimer(HChrdspWork* work)
{
    work->alphaTimer--;
    if (work->alphaTimer > 0)
    {
        return;
    }

    work->alphaPhase = work->alphaPhase == 0;
    work->alphaIndex++;
    if (work->alphaIndex >= 6)
    {
        work->alphaIndex = 0;
    }
    work->alphaTimer = H_Chrdsp_GetFadeFrames(work->alphaIndex);
}
static void H_Chrdsp_Draw(HChrdspWork* work)
{
    RwIm2DVertex overlayVertices[4];
    RwCamera* camera;
    RwV2d position;
    f32 recipZ;
    f32 z;
    f32 primaryWidth;
    f32 primaryHeight;
    f32 overlayWidth;
    f32 overlayHeight;
    f32 overlayYOffset;
    s32 quadIndex;

    camera = kwlnGetMainCamera();
    recipZ = 1.0f / camera->nearPlane;
    z = RwIm2DGetNearScreenZ() - work->zOffset;
    position = work->position;
    if (work->characterId == 39)
    {
        position.y += 48.0f;
    }

    primaryWidth = work->layerWidth * 4.0f;
    primaryHeight = work->layerHeight * 4.0f;
    for (quadIndex = 0; quadIndex < HCHRDP_QUAD_COUNT; quadIndex++)
    {
        H_Chrdsp_BuildQuad(work->vertices[quadIndex],
                            position.x + 256.0f - primaryWidth / 2.0f,
                            position.y + 256.0f - primaryHeight / 2.0f,
                            primaryWidth - 1.0f, primaryHeight - 1.0f,
                            z, recipZ, &work->color);
    }
    H_Chrdsp_RenderTexture((HChrdspTexture*)work->resources[0], work->vertices[0]);

    if ((work->resourceIndex < 2) || (work->color.a != 255) || (work->drawMiddleLayer == 0))
    {
        return;
    }

    H_Chrdsp_AdvanceAlphaTimer(work);

    overlayWidth = work->layerWidth * 4.0f;
    overlayHeight = work->layerHeight * 128.0f;
    overlayYOffset = H_Chrdsp_GetOverlayYOffset(work);
    H_Chrdsp_BuildQuad(overlayVertices,
                        position.x + 256.0f - overlayWidth / 2.0f,
                        position.y + 32.0f - overlayHeight / 2.0f + overlayYOffset,
                        overlayWidth - 1.0f, overlayHeight - 1.0f,
                        z, recipZ, &work->color);
    H_Chrdsp_RenderTexture((HChrdspTexture*)work->resources[1], overlayVertices);

    if ((work->resourceIndex < HCHRDP_LAYER_COUNT) || (work->color.a != 255) ||
        (work->drawTopLayer == 0))
    {
        return;
    }

    H_Chrdsp_BuildQuad(overlayVertices,
                        position.x + 256.0f - overlayWidth / 2.0f,
                        position.y + 32.0f - overlayHeight / 2.0f + overlayYOffset + 155.0f,
                        overlayWidth - 1.0f, overlayHeight - 1.0f,
                        z, recipZ, &work->color);
    H_Chrdsp_RenderTexture((HChrdspTexture*)work->resources[2], overlayVertices);
}
static void H_Chrdsp_LoadArchiveLayer(HChrdspWork* work)
{
    char archivePath[256];
    const char* archiveEntry;

    if (H_Cdvd_IsFileLoaded(work->archive) == 0)
    {
        return;
    }

    if (work->usesCustomPath == 0)
    {
        if ((datGetScenarioMode() != 0) && (work->characterId == 9))
        {
            sprintf(archivePath, "test/char/i_bust29_%1d", work->resourceIndex);
        }
        else
        {
            sprintf(archivePath, "test/char/i_bust%02d_%1d", work->characterId,
                    work->resourceIndex);
        }
    }

    archiveEntry = func_001022e0(work->archive, work->resourceIndex);
    if (archiveEntry == NULL)
    {
        H_Cdvd_Destroy(work->archive);
        work->archive = NULL;
        work->state = HCHRDP_STATE_UNAVAILABLE;
        return;
    }

    sprintf(work->texturePath, "bustup/%s", archiveEntry);
    work->asyncRequest = func_0010c1a0(0, work->texturePath, NULL, 0, NULL, NULL, 0,
                                       NULL, "h_chrdsp.c", NULL, (void*)0x9F);
    work->state = HCHRDP_STATE_PARSE_LAYER;
}
static void H_Chrdsp_ParseLayer(HChrdspWork* work)
{
    HChrdspTexture* texture;
    u32 isReady;

    isReady = false;
    texture = (HChrdspTexture*)func_0010c3a0(work->asyncRequest, &isReady, NULL);
    work->resources[work->resourceIndex] = texture;
    if (isReady == false)
    {
        return;
    }

    texture->renderFlags = (texture->renderFlags & 0xFFFF00FF) | 0x00003300;
    work->asyncRequest = NULL;
    work->resourceIndex++;
    work->state = HCHRDP_STATE_LOAD_ARCHIVE;
}

// FUN_00103DA0
void* H_Pad_RwAllocateRaw(size_t size, RwUInt32 hint)
{
    HPadRwAllocation* allocation;
    s32 intrState;

    if (size == 0xAC)
    {
        printf(D_005CEAE0_sda);
    }

    sRwAllocatedBytes += size;
    intrState = func_0050d3a0();
    allocation = (HPadRwAllocation*)func_00520728(size + sizeof(HPadRwAllocation));
    if (intrState != 0)
    {
        func_0050d3f0();
    }

    if (allocation == (HPadRwAllocation*)0x014CCBC8)
    {
        printf(D_005CEAE0);
    }
    if (allocation == NULL)
    {
        printf(D_005CEAF0);
        printf(D_005CEAF0);
        printf(D_005CEAF0);
        printf(D_005CEAF0);
        printf(D_005CEB10, size, sRwAllocatedBytes);
        printf(D_005CEAF0);
        printf(D_005CEAF0);
        printf(D_005CEAF0);
        printf(D_005CEAF0);
        if (datGetFlag(0x141A) != 0)
        {
            return NULL;
        }

        K_Assert(D_005CEB30, 671);
        return NULL;
    }

    allocation->size = size;
    sRwAllocationCount++;
    allocation->serial = sRwAllocationCount;
    allocation->hint = sRwAllocationHint;
    return allocation + 1;
}

/* W419 probe: moving copySize into the else block stayed nd6,obj228/window240 (same as baseline). */
/* W421 row classification: verify nd6, object228/window240, rate0.026316.
 * Offsets 0x30/0x58/0x5c/0x68/0x88/0xac are respectively
 * move $s0,$v0 / move $s1,$v0; lw $s1,-4($s4) / lw $s0,-4($s4);
 * sltu $at,$s3,$s1 / sltu $at,$s3,$s0; move $s1,$s3 / move $s0,$s3;
 * move $a2,$s1 / move $a2,$s0; and beqz $s0,0x10400c / beqz $s1,0x10400c
 * (candidate / retail): register-role colouring only. */

// FUN_00103F50 NONMATCHING
void* H_Pad_RwRealloc(void* memory, RwUInt32 newSize, RwUInt32 hint)
{
    void* reallocated;
    size_t copySize;
    s32 intrState;
    RwUInt32 mallocHint;
    mallocHint = hint;
    intrState = func_0050d3a0();
    if (memory == NULL)
    {
        reallocated = H_Pad_RwMalloc(newSize, mallocHint);
    }
    else
    {
        copySize = *(RwUInt32*)((u8*)memory - sizeof(void*));
        if (newSize < copySize)
        {
            copySize = newSize;
        }
        reallocated = H_Pad_RwMalloc(newSize, mallocHint);
        memcpy(reallocated, memory, copySize);
        H_Pad_RwFree(memory);
        sRwReallocCount_sda++;
    }

    if (intrState != 0)
    {
        func_0050d3f0();
    }
    return reallocated;
}

#pragma optimization_level 2
// FUN_00104040 MATCHING
void* H_Pad_RwCalloc(RwUInt32 elementCount, RwUInt32 elementSize, RwUInt32 hint)
{
    void* memory;
    RwUInt32 size;
    s32 intrState;

    intrState = func_0050d3a0();
    size = elementSize * elementCount;
    if ((memory = H_Pad_RwMalloc(size, hint)) != NULL)
    {
        memset(memory, 0, size);
        sRwCallocCount++;
    }
    if (intrState != 0)
    {
        func_0050d3f0();
    }
    return memory;
}



/* W389 pragma: opt_propagation off; without nd=1000/object=1500, with nd=966/object=1468; window=1536. */
// FUN_001040F0
RwMemoryFunctions* H_Pad_GetRwMemoryFunctions(void)
{
    sRwMemoryFunctions.RwMalloc = H_Pad_RwMalloc;
    sRwMemoryFunctions.RwFree = H_Pad_RwFree;
    sRwMemoryFunctions.RwRealloc = H_Pad_RwRealloc;
    sRwMemoryFunctions.RwCalloc = H_Pad_RwCalloc;
    return &sRwMemoryFunctions;
}

/* W389 residual: stack-address scheduling (candidate materializes sp+0x60 then adds character; retail adds character to sp then applies +0x60). Baseline nd=7/object=416 at the window; loop-invariants/common-subs exceeded the window (nd=314/424 and 261/428), other singles and all pairs were neutral. Volatile-cast and integer-address spellings stayed nd=7; array indexing regressed to nd=125/object=412 and was reverted. */
// FUN_00104140
void* H_Pad_RwMalloc(RwUInt32 size, RwUInt32 hint)
{
    HPadRwAllocation* allocation;
    u8* alignmentBase;
    u8* alignedMemory;
    s32 intrState;

    if (kwlnTaskGetUpdating() != NULL) {
        if (strcmp("H_CutInDraw", (const char*)kwlnTaskGetUpdating()) == 0) {
            if (size == 0x27d8) goto pr;
            if (size == 0x1fe0) goto pr;
            if (size == 0x27d8) {
pr:
                printf(D_005CEAE0_sda);
            }
        }
    }

    intrState = func_0050d3a0();
    allocation = (HPadRwAllocation*)H_Pad_RwAllocateRaw(size + 0x14, hint);
    if (allocation == NULL) {
        if (intrState != 0) {
            func_0050d3f0();
        }
        return NULL;
    }

    allocation[-1].alignment = 16;
    alignmentBase = (u8*)allocation + 4;
    alignedMemory = alignmentBase + (16 - ((uintptr_t)alignmentBase & 0xF));
    *(void**)(alignedMemory - sizeof(void*)) = allocation;

    if (intrState != 0) {
        func_0050d3f0();
    }

    if (kwlnTaskGetUpdating() != NULL) {
        if (size == 0x50) {
            strcmp("\n", (const char*)kwlnTaskGetUpdating());
        }
    }

    return alignedMemory;
}


// FUN_00104280
void H_Pad_RwFree(void* memory)
{
    s32 intrState;

    if (memory != NULL)
    {
        intrState = func_0050d3a0();
        H_Pad_RwFreeRaw(*(void**)((u8*)memory - sizeof(void*)));
        if (intrState != 0)
        {
            func_0050d3f0();
        }
    }
}

// FUN_001042E0
void H_Dbprt_Init()
{
    HCdvd* cdvd;
    RwRaster* raster;

    cdvd = H_Cdvd_Request("font/size12/f11_001.tmx", HCDVD_FILENORMAL);
    H_Cdvd_ReadSync(cdvd);

    sFontImage = RwImageRead("font/size12/f11_001.tmx");

    H_Cdvd_Destroy(cdvd);

    raster = RwRasterCreate(sFontImage->width,
                            sFontImage->height,
                            4,
                            rwRASTERTYPETEXTURE |
                            rwRASTERFORMATPAL4 |
                            rwRASTERFORMAT8888);
    sFontRaster = raster;
    RwRasterSetFromImage(raster, sFontImage);

    RwImageDestroy(sFontImage);
    sFontImage = NULL;

    H_Cdvd_001007f0();

    memset(sGrid, ' ', sizeof(sGrid));
    sText3DList = NULL;
}

// FUN_001043B0
void H_Dbprt_Flush()
{
    HDbText3D* curr;
    HDbText3D* next;

    memset(sGrid, ' ', sizeof(sGrid));

    curr = sText3DList;
    sText3DList = NULL;
    while (true)
    {
        if (curr == NULL)
        {
            break;
        }

        next = curr->next;
        RwFree(curr);
        curr = next;
    }
}

#pragma opt_lifetimes on
/* Removing this worsens FUN_00104420 (nd244 -> nd268) - measured W161. */
#pragma opt_loop_invariants on
// FUN_00104420 NONMATCHING
void H_Dbprt_Main()
{
    RwIm2DVertex vertices[4];
    f32 recipZ;
    f32 z;
    f32 rowOffset;
    f32 rowY;
    s32 column;
    s32 row;
    s32 vertex;
    s32 glyphIndex;
    u8 glyphByte;
    u8* line;
    RwRenderStateSetFunc* setRenderState;

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;

    setRenderState = (RwRenderStateSetFunc*)D_00960090_abs;
    (*setRenderState)(rwRENDERSTATEZTESTENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATESHADEMODE, (void*)rwSHADEMODEGOURAUD);
    (*setRenderState)(rwRENDERSTATEZWRITEENABLE, (void*)true);
    (*setRenderState)(rwRENDERSTATETEXTUREFILTER, (void*)rwFILTERNEAREST);
    (*setRenderState)(rwRENDERSTATEVERTEXALPHAENABLE, (void*)true);

    kwlnPushCommonRenderStates();
    (*setRenderState)(rwRENDERSTATETEXTURERASTER, (void*)sFontRaster);

    z = *(f32*)D_00960088_abs;

    for (vertex = 0; vertex < 4; vertex++)
    {
        RwIm2DVertex* vertexPtr = &vertices[vertex];

        vertexPtr->u.els.recipZ = recipZ;
        vertexPtr->u.els.color.r = 255.0f;
        vertexPtr->u.els.color.g = 255.0f;
        vertexPtr->u.els.color.b = 255.0f;
        vertexPtr->u.els.color.a = 255.0f;
        vertexPtr->u.els.scrVertex.z = z;
    }

    for (row = 0; row < HDBPRT_GRID_HEIGHT; row++)
    {
        column = 0;
        line = (u8*)sGrid[row];
        rowOffset = 12.0f * (f32)row;
        rowY = 11.0f + rowOffset;
        for (; column < HDBPRT_GRID_WIDTH; column++)
        {
            if (line[column] != ' ')
            {
                vertices[0].u.els.scrVertex.x = 12.0f * (f32)column;
                vertices[0].u.els.scrVertex.y = rowOffset;
                vertices[1].u.els.scrVertex.x =
                    vertices[0].u.els.scrVertex.x + 11.0f;
                vertices[1].u.els.scrVertex.y = rowOffset;
                vertices[2].u.els.scrVertex.x =
                    vertices[0].u.els.scrVertex.x;
                vertices[2].u.els.scrVertex.y = rowY;
                vertices[3].u.els.scrVertex.x =
                    vertices[1].u.els.scrVertex.x;
                vertices[3].u.els.scrVertex.y = rowY;
                glyphIndex = (s32)line[column] - ' ';
                glyphByte = (u8)glyphIndex;
                {
                    const f32 inv16 = 0.0625f;
                    f32 u0 = inv16 * (f32)(glyphByte % 16);
                    f32 v0 = inv16 * (f32)(glyphByte / 16);
                    f32 u1 = u0 + 0.03125f;
                    f32 v1 = v0 + 0.03125f;
                    vertices[0].u.els.u = u0;
                    vertices[0].u.els.v = v0;
                    vertices[1].u.els.u = u1;
                    vertices[1].u.els.v = v0;
                    vertices[2].u.els.u = u0;
                    vertices[2].u.els.v = v1;
                    vertices[3].u.els.u = u1;
                    vertices[3].u.els.v = v1;
                }
                D_009600A0_abs[0](rwPRIMTYPETRISTRIP, vertices, 4);
            }
        }
    }

    H_Dbprt_DrawText3D();
    H_Dbprt_DrawLog();
}

#pragma opt_loop_invariants reset
#pragma opt_lifetimes reset
#pragma push
#pragma opt_propagation off
// FUN_00104710 NONMATCHING
static void H_Dbprt_DrawText3D(void)
{
    HDbText3D* text;
    RwV2d uv[4];
    RwIm2DVertex vertices[4];
    f32 recipZ;
    f32 z;
    f32 u;
    f32 v;
    s32 character;
    s32 vertex;
    s8 glyph;

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;
    kwlnGetMainCamera();
    kwlnGetMainCamera();
    kwlnGetMainCamera();

    kwlnPushCommonRenderStates();
    RwRenderStateSet(rwRENDERSTATETEXTURERASTER, sFontRaster);

    text = sText3DList;
    while (true)
    {
        if (text == NULL)
        {
            break;
        }
        kwlnGetMainCamera();
        kwlnGetMainCamera();
        if (text->pos.z != 0.0f)
        {
            z = H_Dbprt_CalculateScreenZ(text->pos.z);
        }

        for (character = 0; character < HDBPRT_LOG_MAXCHAR; character++)
        {
            glyph = (s8)text->text[character];
            if (glyph == '\0')
            {
                break;
            }

            if (glyph != ' ')
            {
                if (text->pos.z == 0.0f)
                {
                    vertices[0].u.els.scrVertex.x = text->pos.x + 12.0f * (f32)character;
                    vertices[0].u.els.scrVertex.y = text->pos.y;
                    vertices[1].u.els.scrVertex.x = vertices[0].u.els.scrVertex.x + 12.0f;
                    vertices[1].u.els.scrVertex.y = vertices[0].u.els.scrVertex.y;
                    vertices[2].u.els.scrVertex.x = vertices[0].u.els.scrVertex.x;
                    vertices[2].u.els.scrVertex.y = vertices[0].u.els.scrVertex.y + 12.0f;
                    vertices[3].u.els.scrVertex.x = vertices[1].u.els.scrVertex.x;
                    vertices[3].u.els.scrVertex.y = vertices[2].u.els.scrVertex.y;

                    u = 0.0625f * (f32)((glyph - ' ') % 16);
                    v = 0.0625f * (f32)((glyph - ' ') / 16);
                    uv[0].x = u;
                    uv[0].y = v;
                    uv[1].x = u + 0.046875f;
                    uv[1].y = v;
                    uv[2].x = u;
                    uv[2].y = v + 0.046875f;
                    uv[3].x = u + 0.046875f;
                    uv[3].y = v + 0.046875f;

                    z = RwIm2DGetNearScreenZ() - text->zOffset;
                    for (vertex = 0; vertex < 4; vertex++)
                    {
                        vertices[vertex].u.els.scrVertex.z = z;
                        vertices[vertex].u.els.color.r = text->color.r;
                        vertices[vertex].u.els.color.g = text->color.g;
                        vertices[vertex].u.els.color.b = text->color.b;
                        vertices[vertex].u.els.color.a = text->color.a;
                        vertices[vertex].u.els.recipZ = recipZ;
                        vertices[vertex].u.els.u = uv[vertex].x;
                        vertices[vertex].u.els.v = uv[vertex].y;
                    }
                }
                else
                {
                    vertices[0].u.els.scrVertex.x = text->pos.x + 12.0f * (f32)character;
                    vertices[0].u.els.scrVertex.y = text->pos.y;
                    vertices[1].u.els.scrVertex.x = vertices[0].u.els.scrVertex.x + 12.0f;
                    vertices[1].u.els.scrVertex.y = vertices[0].u.els.scrVertex.y;
                    vertices[2].u.els.scrVertex.x = vertices[0].u.els.scrVertex.x;
                    vertices[2].u.els.scrVertex.y = vertices[0].u.els.scrVertex.y + 12.0f;
                    vertices[3].u.els.scrVertex.x = vertices[1].u.els.scrVertex.x;
                    vertices[3].u.els.scrVertex.y = vertices[2].u.els.scrVertex.y;

                    u = 0.0625f * (f32)((glyph - ' ') % 16);
                    v = 0.0625f * (f32)((glyph - ' ') / 16);
                    uv[0].x = u;
                    uv[0].y = v;
                    uv[1].x = u + 0.046875f;
                    uv[1].y = v;
                    uv[2].x = u;
                    uv[2].y = v + 0.046875f;
                    uv[3].x = u + 0.046875f;
                    uv[3].y = v + 0.046875f;

                    for (vertex = 0; vertex < 4; vertex++)
                    {
                        vertices[vertex].u.els.scrVertex.z = z;
                        vertices[vertex].u.els.color.r = text->color.r;
                        vertices[vertex].u.els.color.g = text->color.g;
                        vertices[vertex].u.els.color.b = text->color.b;
                        vertices[vertex].u.els.color.a = text->color.a;
                        vertices[vertex].u.els.recipZ = recipZ;
                        vertices[vertex].u.els.u = uv[vertex].x;
                        vertices[vertex].u.els.v = uv[vertex].y;
                    }
                }
                RwIm2DRenderPrimitive(rwPRIMTYPETRISTRIP, vertices, 4);

            }

        }
        text = text->next;
    }
}
#pragma pop
#pragma opt_propagation reset

/* W421 row classification: verify nd7, object416/window416, rate0.016827.
 * Offsets 0xf0 and 0xf4 are:
 * 0xf0 addiu $v1,$sp,0x60 / addu $v1,$s3,$sp;
 * 0xf4 addu $v1,$s3,$v1 / addiu $v1,$v1,0x60 (candidate / retail):
 * stack-address scheduling. */

// FUN_00104D10 NONMATCHING
void H_Dbprt_FmtAt(volatile /* Removing this qualifier worsens H_Dbprt_FmtAt (NONMATCHING nd170 -> NONMATCHING nd290, size 412 -> 424) - measured W170. */ RwV2d pos, const char* fmt, ...)
{
    char buffer[HDBPRT_LOG_MAXCHAR];
    s32 character;
    s32 x;
    s32 y;
    s32 baseX;
    f32 posY;
    char glyph;
    va_list args;
    posY = pos.y;

    va_start(args, fmt);
    vsprintf(buffer, fmt, args);

    x = (s32)pos.x;
    y = (s32)posY;
    character = 0;
    baseX = x;
    while (character < HDBPRT_LOG_MAXCHAR)
    {
        if (pos.x >= HDBPRT_GRID_WIDTH || posY >= HDBPRT_GRID_HEIGHT ||
            x >= HDBPRT_GRID_WIDTH || y >= HDBPRT_GRID_HEIGHT)
        {
            break;
        }
        glyph = *(char*)((u8*)(uintptr_t)character +
                         (uintptr_t)buffer);
        if (glyph == '\0')
        {
            break;
        }

        if (glyph == '\n')
        {
            x = baseX;
            y++;
        }
        else
        {
            if (y == HDBPRT_GRID_HEIGHT - 1 && x >= HDBPRT_GRID_WIDTH)
            {
                printf_y2("ERROR \n");
            }
            else
            {
                sGrid[y][x] = glyph;
            }
            x++;
        }
        character++;
    }
}










#pragma alias hChrdspDrawPrimitiveSlot D_009600A0_y2










/* Removing this loses FUN_00105800 (MATCH nd0 -> MISMATCH nd42) - measured W161. */
// FUN_00104EB0
void H_Dbprt_FmtCol3D(RwV2d pos, RwRGBA color, const char* fmt, ...)
{
    HDbText3D* text;
    va_list args;

    text = RwCalloc(1, sizeof(HDbText3D), rwMEMHINTDUR_GLOBAL);
    va_start(args, fmt);
    vsprintf(text->text, fmt, args);

    text->pos.x = pos.x;
    text->pos.y = pos.y;
    text->pos.z = 0.0f;
    text->color = color;
    text->zOffset = 0.0f;

    H_Dbprt_AppendText3D(text);
}
// FUN_00104FD0
void H_Dbprt_Fmt3D(RwV2d pos, const char* fmt, ...)
{
    HDbText3D* text;
    va_list args;

    text = RwCalloc(1, sizeof(HDbText3D), rwMEMHINTDUR_GLOBAL);
    va_start(args, fmt);
    vsprintf(text->text, fmt, args);

    text->pos.x = pos.x;
    text->pos.y = pos.y;
    text->pos.z = 0.0f;
    text->zOffset = 0.0f;
    text->color.a = 255;
    text->color.b = 255;
    text->color.g = 255;
    text->color.r = 255;

    H_Dbprt_AppendText3D(text);
}

/* Removing this worsens FUN_001059b0 (nd2207 -> nd2247) - measured W161. */
// FUN_001050E0
void H_Dbprt_FmtZOff3D(RwV2d pos, f32 zOffset, RwRGBA color, const char* fmt, ...)
{
    HDbText3D* text;
    va_list args;

    text = RwCalloc(1, sizeof(HDbText3D), rwMEMHINTDUR_GLOBAL);
    va_start(args, fmt);
    vsprintf(text->text, fmt, args);

    text->pos.x = pos.x;
    text->pos.y = pos.y;
    text->pos.z = 0.0f;
    text->zOffset = zOffset;
    text->color = color;

    H_Dbprt_AppendText3D(text);
}

// FUN_00105210
static f32 H_Dbprt_CalculateScreenZ(f32 zOffset)
{
    f32 zBufferFar;
    f32 zBufferNear;
    f32 farPlane;
    f32 nearPlane;
    f32 z;

    zBufferFar = rwGlobals.device.zBufferFar;
    zBufferNear = rwGlobals.device.zBufferNear;
    farPlane = kwlnGetMainCamera()->farPlane;
    nearPlane = kwlnGetMainCamera()->nearPlane;

    z = 0.0f + zBufferFar + (nearPlane / zOffset) *
                                ((zOffset - farPlane) * ((zBufferNear - zBufferFar) / (nearPlane - farPlane)));
    if (z < 0.0f)
    {
        z = 0.0f;
    }

    return z;
}

// FUN_001052B0
void H_Dbprt_FmtLog(const char* fmt, ...)
{
    char buffer[HDBPRT_LOG_MAXCHAR];
    s32 i;
    s32 line;
    va_list args;

    for (line = 0; line < HDBPRT_LOG_MAXCHAR; line++)
    {
        buffer[line] = 0;
    }

    va_start(args, fmt);
    vsprintf(buffer, fmt, args);

    if (sLogLine == HDBPRT_LOG_MAXLINE)
    {
        for (i = 1; i < HDBPRT_LOG_MAXLINE; i++)
        {
            memcpy(sLogs[i - 1], sLogs[i], HDBPRT_LOG_MAXCHAR);
        }
        sLogLine--;
    }

    memcpy(sLogs[sLogLine], buffer, HDBPRT_LOG_MAXCHAR);
    sLogLine++;
}

// FUN_001053F0 NONMATCHING
static void H_Dbprt_DrawLog(void)
{
    RwIm2DVertex vertices[4];
    RwV2d textureCoords[4];
    RwRGBA color;
    f32 recipZ;
    f32 z;
    f32 x;
    f32 y;
    f32 u;
    f32 v;
    RwIm2DRenderPrimitiveFunction* drawPrimitive;
    void (**setState)(u32 state, u32 value);
    s32 vertex;
    s32 row;
    s32 column;
    u8 glyph;

    recipZ = 1.0f / kwlnGetMainCamera()->nearPlane;

    if (sDrawLogEnabled == 0)
    {
        return;
    }
    setState = (void (**)(u32, u32))D_00960090_abs;


    (*setState)(rwRENDERSTATEZTESTENABLE, true);
    (*setState)(rwRENDERSTATESHADEMODE, rwSHADEMODEGOURAUD);
    (*setState)(rwRENDERSTATEZWRITEENABLE, true);
    (*setState)(rwRENDERSTATETEXTUREFILTER, rwFILTERNEAREST);
    (*setState)(rwRENDERSTATEVERTEXALPHAENABLE, true);

    kwlnPushCommonRenderStates();
    (*setState)(rwRENDERSTATETEXTURERASTER, (u32)NULL);

    color.r = 64;
    color.g = 64;
    color.b = 64;
    color.a = 128;
    z = RwIm2DGetNearScreenZ();

    for (vertex = 0; vertex < 4; vertex++)
    {
        vertices[vertex].u.els.scrVertex.z = z;
        vertices[vertex].u.els.recipZ = recipZ;
        vertices[vertex].u.els.color.r = (f32)color.r;
        vertices[vertex].u.els.color.g = (f32)color.g;
        vertices[vertex].u.els.color.b = (f32)color.b;
        vertices[vertex].u.els.color.a = (f32)color.a;
    }

    vertices[0].u.els.scrVertex.x = sLogBoxPos.x;
    vertices[0].u.els.scrVertex.y = sLogBoxPos.y;
    vertices[1].u.els.scrVertex.x = sLogBoxPos.x + 480.0f;
    vertices[1].u.els.scrVertex.y = sLogBoxPos.y;
    vertices[2].u.els.scrVertex.x = sLogBoxPos.x;
    vertices[2].u.els.scrVertex.y = sLogBoxPos.y + 196.0f;
    vertices[3].u.els.scrVertex.x = sLogBoxPos.x + 480.0f;
    vertices[3].u.els.scrVertex.y = sLogBoxPos.y + 196.0f;
    drawPrimitive = hDbprtDrawPrimitiveSlot;
    (*drawPrimitive)(rwPRIMTYPETRISTRIP, vertices, 4);

    kwlnPushCommonRenderStates();
    (*setState)(rwRENDERSTATETEXTURERASTER, (u32)sFontRaster);

    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 255;
    for (vertex = 0; vertex < 4; vertex++)
    {
        vertices[vertex].u.els.scrVertex.z = z;
        vertices[vertex].u.els.recipZ = recipZ;
        vertices[vertex].u.els.color.r = (f32)color.r;
        vertices[vertex].u.els.color.g = (f32)color.g;
        vertices[vertex].u.els.color.b = (f32)color.b;
        vertices[vertex].u.els.color.a = (f32)color.a;
    }
    for (row = 0; row < sLogLine; row++)
    {
        for (column = 0; column < HDBPRT_GRID_WIDTH; column++)
        {
            glyph = (u8)sLogs[row][column];
            if (glyph == '\0')
            {
                break;
            }

            if (glyph != ' ')
            {
                x = sLogStringsPos.x + 12.0f * (f32)column;
                y = sLogStringsPos.y + 12.0f * (f32)row;

                vertices[0].u.els.scrVertex.x = x;
                vertices[0].u.els.scrVertex.y = y;
                vertices[1].u.els.scrVertex.x = x + 12.0f;
                vertices[1].u.els.scrVertex.y = y;
                vertices[2].u.els.scrVertex.x = x;
                vertices[2].u.els.scrVertex.y = y + 12.0f;
                vertices[3].u.els.scrVertex.x = x + 12.0f;
                vertices[3].u.els.scrVertex.y = y + 12.0f;

                glyph -= ' ';
                u = 0.0625f * (f32)(glyph % 16);
                v = 0.0625f * (f32)(glyph / 16);
                textureCoords[0].x = u;
                textureCoords[0].y = v;
                textureCoords[1].x = u + 0.0625f;
                textureCoords[1].y = v;
                textureCoords[2].x = u;
                textureCoords[2].y = v + 0.0625f;
                textureCoords[3].x = u + 0.0625f;
                textureCoords[3].y = v + 0.0625f;
                for (vertex = 0; vertex < 4; vertex++)
                {
                    vertices[vertex].u.els.u = textureCoords[vertex].x;
                    vertices[vertex].u.els.v = textureCoords[vertex].y;
                }
                (*drawPrimitive)(rwPRIMTYPETRISTRIP, vertices, 4);
            }
        }
    }
}

#pragma opt_loop_invariants on
// FUN_00105800
void H_Chrdsp_Init(void)
{
    s16 workIndex;
    s16 resourceIndex;
    s32 offset;
    HChrdspWork* work;

    for (workIndex = 0; workIndex < HCHRDP_WORK_COUNT; workIndex++)
    {
        offset = (long)workIndex;
        offset *= 0x670;
        work = (HChrdspWork*)((u8*)D_007E2680 + offset);
        work->state = HCHRDP_STATE_IDLE;
        work->drawMiddleLayer = 0;
        work->drawTopLayer = 0;

        for (resourceIndex = 0; resourceIndex < HCHRDP_LAYER_COUNT; resourceIndex++)
        {
            work->resources[resourceIndex] = NULL;
        }
    }
}
#pragma opt_loop_invariants reset

// FUN_001058A0
void H_Chrdsp_Main(void)
{
    s16 workIndex;
    void (**setRenderState)(u32 state, u32 value);
    setRenderState = (void (**)(u32, u32))D_00960090_abs;
    (*setRenderState)(6, 1);
    (*setRenderState)(7, 2);
    (*setRenderState)(8, 1);
    (*setRenderState)(0xB, 6);
    (*setRenderState)(0xA, 5);
    (*setRenderState)(9, 1);
    (*setRenderState)(0xC, 1);
    (*setRenderState)(2, 4);

    for (workIndex = 0; workIndex < HCHRDP_WORK_COUNT; workIndex++)
    {
        H_Chrdsp_UpdateWork(&D_007E2680[workIndex]);
    }
}

#pragma opt_loop_invariants on
/* W377 six-knob/pair probe: opt_dead_assignments off improved H_Chrdsp_UpdateWork from nd2476/object3180 to nd2469/object3160; window=3456. */
#pragma opt_dead_assignments off
// FUN_001059B0 NONMATCHING
void H_Chrdsp_UpdateWork(HChrdspWork* work)
{
    char archivePath[256];
    RwIm2DVertex overlayVertices[4];
    const char* archiveEntry;
    HChrdspTexture* texture;
    RwCamera* camera;
    void (**setRenderState)(u32 state, u32 value);
    HChrdspDrawPrimitive* drawPrimitive;
    RwV2d position;
    f32 recipZ;
    f32 z;
    f32 overlayYOffset;
    s32 quadIndex;
    s32 vertexIndex;
    u32 isReady;
    switch (work->state)
    {

    case HCHRDP_STATE_IDLE:
        break;
    case HCHRDP_STATE_LOAD_ARCHIVE:
        if (H_Cdvd_IsFileLoaded(work->archive) == 0)
        {
            break;
        }
        if (work->usesCustomPath == 0)
        {
            if (datGetScenarioMode() == 0)
            {
                sprintf(archivePath, "test/char/i_bust%02d_%1d",
                        work->characterId, work->resourceIndex);
            }
            else if (work->characterId == 9)
            {
                sprintf(archivePath, "test/char/i_bust29_%1d",
                        work->resourceIndex);
            }
            else
            {
                sprintf(archivePath, "test/char/i_bust%02d_%1d",
                        work->characterId, work->resourceIndex);
            }
        }
        archiveEntry = func_001022e0(work->archive, work->resourceIndex);
        if (archiveEntry == NULL)
        {
            H_Cdvd_Destroy(work->archive);
            work->archive = NULL;
            work->state = HCHRDP_STATE_UNAVAILABLE;
            break;
        }
        archiveEntry = func_001022e0(work->archive, work->resourceIndex);
        sprintf(work->texturePath, "bustup/%s", archiveEntry);
        work->asyncRequest = func_0010c1a0(0, work->texturePath, NULL, 0, NULL,
                                           NULL, 0, NULL, "h_chrdsp.c", NULL,
                                           (void*)0x9F);
        work->state = HCHRDP_STATE_PARSE_LAYER;
        break;

    case HCHRDP_STATE_PARSE_LAYER:
        work->resources[work->resourceIndex] =
            (HChrdspTexture*)func_0010c3a0(work->asyncRequest, &isReady, NULL);
        if (isReady == false)
        {
            break;
        }
        ((HChrdspTexture*)work->resources[work->resourceIndex])->renderFlags =
            (((HChrdspTexture*)work->resources[work->resourceIndex])->renderFlags &
             0xFFFF00FF) | 0x00003300;
        work->asyncRequest = NULL;
        work->resourceIndex++;
        work->state = HCHRDP_STATE_LOAD_ARCHIVE;
        break;

    case HCHRDP_STATE_UNAVAILABLE:
        break;
    case HCHRDP_STATE_DRAW:
    {
        setRenderState = (void (**)(u32, u32))D_00960090_abs;
        drawPrimitive = hChrdspDrawPrimitiveSlot;
        camera = kwlnGetMainCamera();
        recipZ = 1.0f / camera->nearPlane;
        z = RwIm2DGetNearScreenZ() - work->zOffset;
        position = work->position;
        if (work->characterId == 39)
        {
            position.y += 48.0f;
        }

        for (quadIndex = 0; quadIndex < HCHRDP_QUAD_COUNT; quadIndex++)
        {
            for (vertexIndex = 0; vertexIndex < 4; vertexIndex++)
            {
                work->vertices[quadIndex][vertexIndex].u.els.color.r =
                    (f32)work->color.r;
                work->vertices[quadIndex][vertexIndex].u.els.color.g =
                    (f32)work->color.g;
                work->vertices[quadIndex][vertexIndex].u.els.color.b =
                    (f32)work->color.b;
                work->vertices[quadIndex][vertexIndex].u.els.color.a =
                    (f32)work->color.a;
                work->vertices[quadIndex][vertexIndex].u.els.scrVertex.z =
                    z;
                work->vertices[quadIndex][vertexIndex].u.els.recipZ = recipZ;
            }

            work->vertices[quadIndex][0].u.els.scrVertex.x =
                position.x + 256.0f - work->layerWidth * 512.0f / 2.0f;
            work->vertices[quadIndex][0].u.els.scrVertex.y =
                position.y + 256.0f - work->layerHeight * 512.0f / 2.0f;
            work->vertices[quadIndex][0].u.els.u = 0.0f;
            work->vertices[quadIndex][0].u.els.v = 0.0f;
            work->vertices[quadIndex][1].u.els.scrVertex.x =
                position.x + 256.0f + work->layerWidth * 512.0f / 2.0f - 1.0f;
            work->vertices[quadIndex][1].u.els.scrVertex.y =
                position.y + 256.0f - work->layerHeight * 512.0f / 2.0f;
            work->vertices[quadIndex][1].u.els.u = 1.0f;
            work->vertices[quadIndex][1].u.els.v = 0.0f;
            work->vertices[quadIndex][2].u.els.scrVertex.x =
                position.x + 256.0f - work->layerWidth * 512.0f / 2.0f;
            work->vertices[quadIndex][2].u.els.scrVertex.y =
                position.y + 256.0f + work->layerHeight * 512.0f / 2.0f - 1.0f;
            work->vertices[quadIndex][2].u.els.u = 0.0f;
            work->vertices[quadIndex][2].u.els.v = 1.0f;
            work->vertices[quadIndex][3].u.els.scrVertex.x =
                position.x + 256.0f + work->layerWidth * 512.0f / 2.0f - 1.0f;
            work->vertices[quadIndex][3].u.els.scrVertex.y =
                position.y + 256.0f + work->layerHeight * 512.0f / 2.0f - 1.0f;
            work->vertices[quadIndex][3].u.els.u = 1.0f;
            work->vertices[quadIndex][3].u.els.v = 1.0f;
        }
        (*setRenderState)(1, (u32)((HChrdspTexture*)work->resources[0])->raster);
        (*drawPrimitive)(rwPRIMTYPETRISTRIP, work->vertices[0], 4);

        if ((work->resourceIndex < 2) || (work->color.a != 255) ||
            (work->drawMiddleLayer == 0))
        {
            break;
        }


        switch (work->characterId)
        {
        case 15:
            overlayYOffset = 189.0f;
            break;
        case 10:
            overlayYOffset = 149.0f;
            break;
        case 39:
            overlayYOffset = 81.0f;
            break;
        case 30:
            overlayYOffset = 100.0f;
            break;
        case 42:
            overlayYOffset = 76.0f;
            break;
        case 48:
            overlayYOffset = 97.0f;
            break;
        case 12:
            overlayYOffset = 134.0f;
            break;
        case 9:
            overlayYOffset = 122.0f;
            break;
        case 5:
            if ((work->variant == 4) || (work->variant == 5) ||
                (work->variant == 6))
            {
                overlayYOffset = 101.0f;
            }
            else
            {
                overlayYOffset = 111.0f;
            }
            break;
        case 8:
            overlayYOffset = 130.0f;
            break;
        case 6:
            overlayYOffset = 116.0f;
            break;
        case 13:
            overlayYOffset = 119.0f;
            break;
        case 27:
            overlayYOffset = 136.0f;
            break;
        default:
            overlayYOffset = 111.0f;
            break;
        }

        for (vertexIndex = 0; vertexIndex < 4; vertexIndex++)
        {
            overlayVertices[vertexIndex].u.els.scrVertex.z =
                z;
            overlayVertices[vertexIndex].u.els.recipZ = recipZ;
            overlayVertices[vertexIndex].u.els.color.r = (f32)work->color.r;
            overlayVertices[vertexIndex].u.els.color.g = (f32)work->color.g;
            overlayVertices[vertexIndex].u.els.color.b = (f32)work->color.b;
            overlayVertices[vertexIndex].u.els.color.a = (f32)work->color.a;
        }
        overlayVertices[0].u.els.scrVertex.x =
            position.x + 256.0f - work->layerWidth * 512.0f / 2.0f;
        overlayVertices[0].u.els.scrVertex.y =
            position.y + 32.0f - work->layerHeight * 64.0f / 2.0f +
            overlayYOffset;
        overlayVertices[0].u.els.u = 0.0f;
        overlayVertices[0].u.els.v = 0.0f;
        overlayVertices[1].u.els.scrVertex.x =
            position.x + 256.0f + work->layerWidth * 512.0f / 2.0f - 1.0f;
        overlayVertices[1].u.els.scrVertex.y =
            position.y + 32.0f - work->layerHeight * 64.0f / 2.0f +
            overlayYOffset;
        overlayVertices[1].u.els.u = 1.0f;
        overlayVertices[1].u.els.v = 0.0f;
        overlayVertices[2].u.els.scrVertex.x =
            position.x + 256.0f - work->layerWidth * 512.0f / 2.0f;
        overlayVertices[2].u.els.scrVertex.y =
            position.y + 32.0f + work->layerHeight * 64.0f / 2.0f - 1.0f +
            overlayYOffset;
        overlayVertices[2].u.els.u = 0.0f;
        overlayVertices[2].u.els.v = 1.0f;
        overlayVertices[3].u.els.scrVertex.x =
            position.x + 256.0f + work->layerWidth * 512.0f / 2.0f - 1.0f;
        overlayVertices[3].u.els.scrVertex.y =
            position.y + 32.0f + work->layerHeight * 64.0f / 2.0f - 1.0f +
            overlayYOffset;
        overlayVertices[3].u.els.u = 1.0f;
        overlayVertices[3].u.els.v = 1.0f;
        (*setRenderState)(1, (u32)((HChrdspTexture*)work->resources[1])->raster);
        (*drawPrimitive)(rwPRIMTYPETRISTRIP, overlayVertices, 4);
        work->alphaTimer--;
        if (work->alphaTimer <= 0)
        {
            work->alphaPhase = work->alphaPhase == 0;
            work->alphaIndex++;
            if (work->alphaIndex >= 6)
            {
                work->alphaIndex = 0;
            }
            switch (work->alphaIndex)
            {
            case 0:
                work->alphaTimer = 3;
                break;
            case 1:
                work->alphaTimer = 100;
                break;
            case 2:
            case 3:
            case 4:
                work->alphaTimer = 2;
                break;
            default:
                work->alphaTimer = 80;
                break;
            }
        }

        if ((work->resourceIndex < HCHRDP_LAYER_COUNT) ||
            (work->color.a != 255) || (work->drawTopLayer == 0))
        {
            break;
        }

        for (vertexIndex = 0; vertexIndex < 4; vertexIndex++)
        {
            overlayVertices[vertexIndex].u.els.scrVertex.z =
                z;
            overlayVertices[vertexIndex].u.els.recipZ = recipZ;
            overlayVertices[vertexIndex].u.els.color.r = (f32)work->color.r;
            overlayVertices[vertexIndex].u.els.color.g = (f32)work->color.g;
            overlayVertices[vertexIndex].u.els.color.b = (f32)work->color.b;
            overlayVertices[vertexIndex].u.els.color.a = (f32)work->color.a;
        }
        overlayVertices[0].u.els.scrVertex.x =
            position.x + 256.0f - work->layerWidth * 512.0f / 2.0f;
        overlayVertices[0].u.els.scrVertex.y =
            position.y + 32.0f - work->layerHeight * 64.0f / 2.0f +
            overlayYOffset + 155.0f;
        overlayVertices[0].u.els.u = 0.0f;
        overlayVertices[0].u.els.v = 0.0f;
        overlayVertices[1].u.els.scrVertex.x =
            position.x + 256.0f + work->layerWidth * 512.0f / 2.0f - 1.0f;
        overlayVertices[1].u.els.scrVertex.y =
            position.y + 32.0f - work->layerHeight * 64.0f / 2.0f +
            overlayYOffset + 155.0f;
        overlayVertices[1].u.els.u = 1.0f;
        overlayVertices[1].u.els.v = 0.0f;
        overlayVertices[2].u.els.scrVertex.x =
            position.x + 256.0f - work->layerWidth * 512.0f / 2.0f;
        overlayVertices[2].u.els.scrVertex.y =
            position.y + 32.0f + work->layerHeight * 64.0f / 2.0f - 1.0f +
            overlayYOffset + 155.0f;
        overlayVertices[2].u.els.u = 0.0f;
        overlayVertices[2].u.els.v = 1.0f;
        overlayVertices[3].u.els.scrVertex.x =
            position.x + 256.0f + work->layerWidth * 512.0f / 2.0f - 1.0f;
        overlayVertices[3].u.els.scrVertex.y =
            position.y + 32.0f + work->layerHeight * 64.0f / 2.0f - 1.0f +
            overlayYOffset + 155.0f;
        overlayVertices[3].u.els.u = 1.0f;
        overlayVertices[3].u.els.v = 1.0f;
        (*setRenderState)(1, (u32)((HChrdspTexture*)work->resources[2])->raster);
        (*drawPrimitive)(rwPRIMTYPETRISTRIP, overlayVertices, 4);
        break;

    }
    default:
        break;
    }
}
#pragma opt_dead_assignments reset
#pragma opt_loop_invariants reset

// FUN_00106730
void func_00106730(s16 index)
{
    s16 originalIndex;
    s32 resourceIndex;
    HChrdspWork* work;

    originalIndex = index;
    printf(D_005D3CB0, originalIndex);
    if (*(void**)((u8*)D_007E2BC8 + originalIndex * 0x670) != NULL)
    {
        func_00133d30(*(void**)((u8*)D_007E2BC8 + originalIndex * 0x670),
                      *(void**)((u8*)D_007E2BA8 + originalIndex * 0x670));
        *(void**)((u8*)D_007E2BC8 + originalIndex * 0x670) = NULL;
        *(void**)((u8*)D_007E2BA8 + originalIndex * 0x670) = NULL;
    }
    else if (*(void**)((u8*)D_007E2BA8 + originalIndex * 0x670) != NULL)
    {
        H_Cdvd_Destroy(*(HCdvd**)((u8*)D_007E2BA8 + originalIndex * 0x670));
        *(void**)((u8*)D_007E2BA8 + originalIndex * 0x670) = NULL;
    }

    resourceIndex = 0;
    work = (HChrdspWork*)((u8*)D_007E2680 + originalIndex * 0x670);
    while (resourceIndex < HCHRDP_LAYER_COUNT)
    {
        void** resource;

        resource = (void**)((u8*)work + 0x14 + resourceIndex * 4);
        if (*resource != NULL)
        {
            func_004d0f00(*resource);
            *resource = NULL;
        }
        resourceIndex++;
    }
    work->state = HCHRDP_STATE_IDLE;
}

// FUN_00106860
void func_00106860(s16 index, s16 characterId, s16 layer, s16 variant)
{
    char path[256];
    s16 originalIndex;
    s32 signedIndex;
    s32 entryIndex;
    s32 offset;

    originalIndex = index;
    signedIndex = originalIndex;
    printf(D_005D3CD0, signedIndex);

    offset = signedIndex * 0x670;
    *(s32*)((u8*)D_007E2BCC + offset) = 0;
    *(s16*)((u8*)D_007E2684 + offset) = characterId;
    *(s16*)((u8*)D_007E2688 + offset) = layer;
    *(s16*)((u8*)D_007E268A + offset) = variant;
    func_00106730(originalIndex);

    if (layer < HCHRDP_LAYER_COUNT)
    {
        if (clndIsDateInRange(6, 1, 9, 30) != 0)
        {
            if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
            {
                sprintf(path, D_005D3CF0, characterId, layer, variant);
            }
            else if (characterId == 9)
            {
                sprintf(path, D_005D3D10, layer, variant);
            }
            else
            {
                sprintf(path, D_005D3CF0, characterId, layer, variant);
            }
        }
        else if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
        {
            sprintf(path, D_005D3D30, characterId, layer, variant);
        }
        else if (characterId == 9)
        {
            sprintf(path, D_005D3D50, layer, variant);
        }
        else
        {
            sprintf(path, D_005D3D30, characterId, layer, variant);
        }
    }
    else if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
    {
        sprintf(path, D_005D3D70, characterId, layer, variant);
    }
    else if (characterId == 9)
    {
        sprintf(path, D_005D3D90, layer, variant);
    }
    else
    {
        sprintf(path, D_005D3D70, characterId, layer, variant);
    }

    for (entryIndex = 0; entryIndex < 0x1388; entryIndex++)
    {
        if (D_005D3350[entryIndex][0] == '\0')
        {
            sprintf(path, D_005D3DB0);
            break;
        }

        if (strcmp(D_005D3350[entryIndex], path) == 0)
        {
            if (layer < HCHRDP_LAYER_COUNT)
            {
                if (clndIsDateInRange(6, 1, 9, 30) != 0)
                {
                    if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
                    {
                        sprintf(path, D_005D3DD0, characterId, layer, variant);
                    }
                    else if (characterId == 9)
                    {
                        sprintf(path, D_005D3DF0, layer, variant);
                    }
                    else
                    {
                        sprintf(path, D_005D3DD0, characterId, layer, variant);
                    }
                }
                else if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
                {
                    sprintf(path, D_005D3E10, characterId, layer, variant);
                }
                else if (characterId == 9)
                {
                    sprintf(path, D_005D3E30, layer, variant);
                }
                else
                {
                    sprintf(path, D_005D3E10, characterId, layer, variant);
                }
            }
            else if (datGetScenarioMode() == SCENARIO_MODE_JOURNEY)
            {
                sprintf(path, D_005D3E50, characterId, layer, variant);
            }
            else if (characterId == 9)
            {
                sprintf(path, D_005D3E70, layer, variant);
            }
            else
            {
                sprintf(path, D_005D3E50, characterId, layer, variant);
            }
            break;
        }
    }

    strcpy((char*)((u8*)D_007E2680 + originalIndex * 0x670 + 0x568), path);
    *(s16*)((u8*)D_007E2680 + originalIndex * 0x670) = HCHRDP_STATE_LOAD_ARCHIVE;
    *(void**)((u8*)D_007E2BA8 + originalIndex * 0x670) =
        H_Cdvd_Request((char*)((u8*)D_007E2680 + originalIndex * 0x670 + 0x568),
                       HCDVD_FILEARCHIVE);
    *(u8*)((u8*)D_007E2BA0 + originalIndex * 0x670) = 255;
    *(u8*)((u8*)D_007E2BA1 + originalIndex * 0x670) = 255;
    *(u8*)((u8*)D_007E2BA2 + originalIndex * 0x670) = 255;
    *(u8*)((u8*)D_007E2BA3 + originalIndex * 0x670) = 255;
    *(f32*)((u8*)D_007E2BAC + originalIndex * 0x670) = 1.0f;
    *(f32*)((u8*)D_007E2BB0 + originalIndex * 0x670) = 1.0f;
    *(u32*)((u8*)D_007E2BE4 + originalIndex * 0x670) = true;
}





#pragma alias D_005CEAE0_sda D_005CEAE0


#pragma alias gWorkPads_abs gWorkPads
#pragma alias gPads_abs gPads
#pragma alias sAddrPort1_abs sAddrPort1
#pragma alias sAddrPort2_abs sAddrPort2



/* Removing this loses FUN_00103000 (MATCH nd0 -> MISMATCH nd48) - measured W161. */











// FUN_00106e90
void func_00106e90(s16 index, u8 alpha)
{
    D_007E2680[index].color.a = alpha;
}

/* W389 residual: callee-saved register-coloring cycle (retail keeps intrState in $s1/copySize in $s0; candidate swaps them). Baseline nd=6/object=228/window=240; propagation off worsened nd=13, the other singles and all pairs were neutral; declaration and type swaps were neutral. */
// FUN_00106ec0
void func_00106ec0(s16 index, void* request)
{
    D_007E2680[index].asyncRequest = request;
    if (request != NULL)
    {
        D_007E2680[index].alphaPhase = 1;
        D_007E2680[index].alphaIndex = 0;
        D_007E2680[index].alphaTimer = 2;
    }
}
// FUN_00106f30
void func_00106f30(s16 index, s32 resourceIndex)
{
    D_007E2680[index].resourceIndex = resourceIndex;
}

// FUN_00106f60
void func_00106f60(s16 index, s16 value)
{
    if (D_007E2680[index].state == HCHRDP_STATE_UNAVAILABLE)
    {
        D_007E2680[index].state = HCHRDP_STATE_DRAW;
    }
    D_007E2680[index].reserved02 = value;
}

// Previous body omitted retail's debug-name checks (two kwlnTaskGetUpdating
// + strcmp guards bracketing the allocation) and the interrupt-disable
// pair around H_Pad_RwAllocateRaw. That callee was also missing its real
// second parameter (hint) - added as an unused param (its body never
// reads it) since the caller passes it in $a1 per retail. obj 88B->312B/
// 320B; residual is a small OR-condition register-choice floor.
// FUN_00106fb0
void func_00106fb0(s16 index, RwV2d position)
{
    D_007E2680[index].position = position;
}

// FUN_00106ff0
u32 func_00106ff0(s16 index)
{
    return D_007E2680[index].state == HCHRDP_STATE_UNAVAILABLE;
}
