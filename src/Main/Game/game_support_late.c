#include "Main/g_data.h"
#include "Main/Game/game_support.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "h_cdvd.h"
#include "libm.h"

/* Retail interfaces whose headers use a different (decompiler-friendly) ABI. */
extern void* func_0010c1a0(void* owner, const char* path, ...);
extern void* func_0010c3a0(void* stream, u32* finished, s32 byteCount);
extern KwlnTask* func_00111380(KwlnTask* parent, u32 priority, u64 dimensions, void* archive);
extern KwlnTask* func_00111150(KwlnTask* parent, u64 dimensions);
extern u32 func_001114b0(KwlnTask* task);
extern void func_00111500(KwlnTask* task);
extern void func_00111520(KwlnTask* task, s16 count);
extern u32 func_00111530(KwlnTask* task);
extern void func_001115b0(KwlnTask* task);
extern void func_001115e0(KwlnTask* task);
extern void func_001120c0(void);
extern void* func_00112420(void* source);
extern f32 func_001126b0(void* sprite);
extern f32 func_00112740(void* sprite);
extern void func_001127d0(void* sprite, u32 enabled);
extern void* func_001158b0(void* unused, void* atlas, s32 tile);
extern void func_00115980(void* sprite);
extern void func_001159f0(void* unused, void* atlas, s32 tile, u32 alpha,
                          f32 x, f32 y, f32 depth);
#pragma alias gsDrawSpritePositionFirst func_001159f0
extern void gsDrawSpritePositionFirst(f32 x, f32 y, void* unused,
                                      void* atlas, s32 tile, u32 alpha,
                                      f32 depth);
extern void func_00115ad0(void* unused, void* atlas, s32 tile,
                          f32 x, f32 y, u32 alpha, u32 extraAlpha, f32 depth);
extern void func_00113a30(f32 depth, f32 x, f32 y, u32 color,
                          s32 width, s32 height);
extern void func_00113d80(f32 depth, f32 x, f32 y, u32 color,
                          s32 width, s32 height);
extern void func_00114af0(f32 depth, f32 x, f32 y, u32 color,
                          s32 width, s32 height, void* texture);
extern void func_003b2cb0(f32 depth, s32 x, s32 y, u32 color,
                          u32 font, u32 align, const void* text,
                          u32 width, u32 flags);
extern void func_004d0f00(void* resource);
extern void* kwlnGetMainCamera(void);
extern u32 RpRandom(void);
extern f32 DAT_007caf38;
extern u16 func_0016c670(s16 pcId);
extern s32 func_00530da0(f32 value);
extern s32 sprintf(char* buffer, const char* format, ...);
extern char* strcpy(char* destination, const char* source);
#pragma alias gsConfigureTransition func_0018bc10
extern void gsConfigureTransition(void* transition, s32 drawMode,
                                  s32 positionMode, s32 alphaMode,
                                  u64 start, u64 end, s32 param0, s32 tile,
                                  s32 startFrame, s32 endFrame, f32 depth);

/* Runtime allocator/free-function tables. */
extern u32 D_00960184[];
#pragma alias D_00960184_abs D_00960184
extern u8 D_00960184_abs[];
extern u32 jtbl_0096017C[];
#define GS_ALLOC(count, size, flags) \
    (*(void* (**)(u32, u32, u32))D_00960184_abs)((count), (size), (flags))
#define GS_FREE(ptr) (*(void (**)(void*))jtbl_0096017C)((ptr))

/* Render-state callback table and data resources. */
extern void (*D_00960090)(u32 state, u32 value);
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
extern void* D_00846730[0x12];
extern void* DAT_007ce008;

extern const char D_005E4320[];
extern const char D_005E4340[];
extern const char D_005E4360[];
extern const char D_005E4380[];
extern const char D_005E43A0[];
extern const char D_005E43C0[];
extern const char D_005E43E0[];
extern const char D_005E43F0[];
extern const char D_005E4418[];
extern const char D_005E4430[];
extern const char D_005E4450[];
extern const char D_005E4480[];
extern const char D_005E44B0[];
extern const char D_005E44D0[];
extern const char D_005E44E0[];
extern const char D_005E4500[];
extern const char D_005E4520[];
extern const char D_005E4540[];
extern const char D_005E4560[];
extern const char D_005E4580[];
extern const char D_005E45A0[];
extern const char D_005E45C0[];
extern const char D_005E45E0[];
extern const char D_005E4600[];
extern const char D_005E4620[];
extern const char D_005E4640[];
extern const char D_005E4660[];
extern const char D_005E4680[];
extern const char D_005E46A0[];



/* Target work blocks use the retail 32-bit offsets. */
#define GS_U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define GS_S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define GS_U16(p, o) (*(u16*)((u8*)(p) + (o)))
#define GS_S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define GS_U32(p, o) (*(u32*)((u8*)(p) + (o)))
#define GS_S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define GS_F32(p, o) (*(f32*)((u8*)(p) + (o)))
#define GS_PTR(p, o) (*(void**)((u8*)(p) + (o)))
#define GS_TASK(p, o) (*(KwlnTask**)((u8*)(p) + (o)))

typedef struct GsCdvdWork
{
    u32 reserved00;
    HCdvd* cdvd;
} GsCdvdWork;
typedef struct GsLargeCdvdWork
{
    u8 reserved00[0x20];
    HCdvd* cdvd;
} GsLargeCdvdWork;
typedef struct GsResourceWork
{
    u8 reserved00[0x28];
    void* resources[0x12];
    void* allocation;
} GsResourceWork;
typedef struct GsAnimationWork
{
    u32 reserved00;
    HCdvd* cdvd;
    u8 reserved08[0x200];
    u32 transitionInitialized;
    u32 visible;
    void* transitions;
    void* atlas;
} GsAnimationWork;
typedef struct GsB270Entry
{
    u8 reserved00[0x154];
    void* cache;
    u8 reserved158[0x20c];
} GsB270Entry;

typedef struct GsB270Header
{
    u8 reserved00[0x30];
    void* resources[4];
    HCdvd* cdvd;
} GsB270Header;

typedef union GsB270Work
{
    GsB270Header header;
    GsB270Entry entries[3];
} GsB270Work;
typedef struct GsArchiveTaskWork
{
    u32 state;
    u32 reserved04;
    s32 argument;
    KwlnTask* tasks[4];
    void* resources[0x12];
} GsArchiveTaskWork;






typedef union GsPackedPosition
{
    u64 value;
    f32 valueF[2];
} GsPackedPosition;

typedef struct GsPosition
{
    f32 valueF[2];
} GsPosition;

typedef struct GsTransition
{
    void* sprite;
    u32 enabled;
    s32 positionMode;
    s32 activePositionMode;
    s32 alphaMode;
    s32 tile;
    s32 elapsed;
    s32 start;
    s32 end;
    f32 depth;
    f32 startX;
    f32 startY;
    f32 endX;
    f32 endY;
    GsPosition position;
    u32 alpha;
} GsTransition;



typedef union GsPackedDimensions
{
    u64 value;
    s16 valueS[4];
} GsPackedDimensions;

typedef struct GsSprite
{
    u8 reserved00[0x10];
    f32 x;
    f32 y;
    u8 alpha;
    u8 reserved19[7];
    f32 angle;
    s16 centerX;
    s16 centerY;
    s16 scaleX;
    s16 scaleY;
    f32 depth;
} GsSprite;

static inline void gsDrawSprite(void* atlas, s32 tile, u32 alpha,
                                f32 x, f32 y, f32 depth)
{
    func_001159f0(NULL, atlas, tile, alpha, x, y, depth);
}

static inline void gsDrawSpriteAlt(void* atlas, s32 tile, u32 alpha,
                                   u32 extraAlpha, f32 x, f32 y, f32 depth)
{
    func_00115ad0(NULL, atlas, tile, x, y, alpha, extraAlpha, depth);
}

static inline s16 gsMappedPcId(s16 pcId)
{
    if (datGetScenarioMode() != 0)
    {
        if (pcId == 1)
        {
            pcId = 11;
        }
        if (pcId == 9)
        {
            pcId = 12;
        }
        if (pcId == 3)
        {
            pcId = 11;
        }
    }
    return pcId;
}

static inline void* gsPcAtlas(void* object, s16 pcId)
{
    if (datGetScenarioMode() != 0)
    {
        if (pcId == 1)
        {
            pcId = 11;
        }
        if (pcId == 9)
        {
            pcId = 12;
        }
        if (pcId == 3)
        {
            pcId = 11;
        }
    }
    return GS_PTR(object, 0x3c + (pcId * 4));
}

static inline void gsDrawHeader(void* object, s32 tile0, s32 tile1, s32 tile2)
{
    void* atlas;
    void* transition;

    transition = GS_PTR(object, 0x70);
    atlas = gsPcAtlas(object, GS_S16(object, 0x14));
    gsDrawSprite(atlas, tile0, GS_U8(transition, 0x40),
                 GS_F32(transition, 0x38) + 20.0f,
                 GS_F32(transition, 0x3c) + 18.0f,
                 GS_F32(transition, 0x24));
    gsDrawSprite(atlas, tile1, GS_U8(transition, 0x40),
                 GS_F32(transition, 0x38) + 20.0f,
                 GS_F32(transition, 0x3c) + 18.0f,
                 GS_F32(transition, 0x24));
    gsDrawSprite(GS_PTR(object, 0x2c), tile2, GS_U8(transition, 0x40),
                 GS_F32(transition, 0x38) + 44.0f,
                 GS_F32(transition, 0x3c) + 39.0f,
                 GS_F32(transition, 0x24));
}

static inline void gsDrawStatusBars(void* object)
{
    s16 pcId;
    s32 value;
    s32 maxValue;
    s32 width;
    void* transition;

    transition = GS_PTR(object, 0x70);
    pcId = GS_S16(object, 0x14);

    value = datGetHp(pcId);
    maxValue = datGetMaxHp(pcId);
    width = ((value & 0xffff) << 5) / (maxValue & 0xffff);
    if (width != 0x20)
    {
        func_00113a30(GS_F32(transition, 0x24) - 1.0f,
                      GS_F32(transition, 0x38) + (f32)width + 50.0f,
                      GS_F32(transition, 0x3c) + 46.0f,
                      0xffffff00, 0x20 - width, 0x14);
    }
    gsDrawSprite(GS_PTR(object, 0x2c), 1, GS_U8(transition, 0x40),
                 GS_F32(transition, 0x38) + 50.0f,
                 GS_F32(transition, 0x3c) + 46.0f,
                 GS_F32(transition, 0x24));

    value = datGetSp(pcId);
    maxValue = func_0016c670(pcId);
    width = ((value & 0xffff) << 5) / (maxValue & 0xffff);
    if (width != 0x20)
    {
        func_00113a30(GS_F32(transition, 0x24) - 3.0f,
                      GS_F32(transition, 0x38) + (f32)width + 50.0f,
                      GS_F32(transition, 0x3c) + 51.0f,
                      0xffffff00, 0x20 - width, 0x14);
    }
    gsDrawSprite(GS_PTR(object, 0x2c), 2, GS_U8(transition, 0x40),
                 GS_F32(transition, 0x38) + 50.0f,
                 GS_F32(transition, 0x3c) + 51.0f,
                 GS_F32(transition, 0x24) - 2.0f);
}

static inline void gsDrawAnimatedSprite(void* object, s32 atlasOffset,
                                        s32 tile, s32 timer, s32 maxTimer,
                                        s32 xOffset, s32 yOffset,
                                        u32 alpha, s16 scale)
{
    void* transition;
    void* sprite;
    f32 width;
    f32 height;
    GsSprite* node;

    transition = GS_PTR(object, 0x70);
    sprite = func_001158b0(NULL, GS_PTR(object, atlasOffset), tile);
    node = (GsSprite*)sprite;
    node->depth = GS_F32(transition, 0x24) - 4.0f;
    node->scaleX = scale;
    node->scaleY = scale;
    width = func_001126b0(sprite);
    node->centerX = (s16)(s32)(width / 2.0f);
    height = func_00112740(sprite);
    node->centerY = (s16)(s32)(height / 2.0f);
    width = func_001126b0(sprite);
    node->x = GS_F32(transition, 0x38) + 6.0f + (f32)xOffset - width / 2.0f;
    height = func_00112740(sprite);
    node->y = GS_F32(transition, 0x3c) + 22.0f + (f32)yOffset - height / 2.0f;
    node->alpha = (u8)alpha;
    func_001127d0(sprite, 1);
    func_00115980(sprite);
    (void)timer;
    (void)maxTimer;
}


// FUN_0018A9F0 NONMATCHING
void* func_0018a9f0(KwlnTask* task)
{
    struct GsLateTimerWork
    {
        u8 pad[0xa70];
        s32 timer;
    };
    s32 i;
    u32 done;
    u32 allDone;
    struct
    {
        u32 pad[4];
        char text[256];
    } pathBuffer;
    GsPackedDimensions dimensions;
    void* resource;
    u32 alpha;
    u8* work = (u8*)task->workData;

    switch (GS_U32(work, 0))
    {
    case 0:
        switch (GS_U32(work, 4))
        {
        case 0x110:
            GS_U32(work, 8) = 0;
            break;
        case 0x111:
            GS_U32(work, 8) = 1;
            break;
        case 0x112:
            GS_U32(work, 8) = 2;
            break;
        case 0x113:
            GS_U32(work, 8) = 3;
            break;
        case 0x114:
            GS_U32(work, 8) = 4;
            break;
        case 0x115:
            GS_U32(work, 8) = 5;
            break;
        case 0x116:
            GS_U32(work, 8) = 6;
            break;
        case 0x117:
            GS_U32(work, 8) = 7;
            break;
        case 0x118:
            GS_U32(work, 8) = 8;
            break;
        case 0x119:
            GS_U32(work, 8) = 9;
            break;
        case 0x11a:
            GS_U32(work, 8) = 10;
            break;
        case 0x11b:
            GS_U32(work, 8) = 11;
            break;
        case 0x11c:
            GS_U32(work, 8) = 12;
            break;
        case 0x11d:
            GS_U32(work, 8) = 13;
            break;
        case 0x11e:
            GS_U32(work, 8) = 14;
            break;
        case 0x11f:
            GS_U32(work, 8) = 15;
            break;
        case 0x120:
            GS_U32(work, 8) = 16;
            break;
        case 0x121:
            GS_U32(work, 8) = 17;
            break;
        default:
            break;
        }
        sprintf(pathBuffer.text, D_005E43C0, GS_U32(work, 8));
        GS_PTR(work, 0x40) = H_Cdvd_Request(pathBuffer.text, HCDVD_FILEARCHIVE);
        GS_U32(work, 0) = 1;
        break;
    case 1:
        if (H_Cdvd_IsFileLoaded((HCdvd*)GS_PTR(work, 0x40)) != 0)
        {
            for (i = 0; i < 3; i++)
            {
                u8* entry = work + i * 0x364;
                resource = H_Cdvd_ArchiveGetFile((HCdvd*)GS_PTR(work, 0x40),
                                                  i + 4, (u32*)(entry + 0x15c));
                GS_PTR(entry, 0x154) = resource;
                func_00102720(D_005E43E0, resource);
            }
            dimensions.valueS[0] = 0x29;
            dimensions.valueS[1] = 1;
            if (GS_S32(work, 8) < 9)
            {
                dimensions.valueS[2] = 10;
                dimensions.valueS[3] = (s16)(GS_S32(work, 8) + 1);
            }
            else
            {
                dimensions.valueS[2] = 11;
                dimensions.valueS[3] = (s16)(GS_S32(work, 8) - 9);
            }
            GS_TASK(work, 0x14) = func_00111380(task, 0x18bf,
                                                dimensions.value,
                                                work + 0x3a8);
            dimensions.valueS[1] = 2;
            GS_TASK(work, 0x18) = func_00111380(task, 0x18bf,
                                                dimensions.value,
                                                work + 0x70c);
            dimensions.valueS[0] = 0x29;
            dimensions.valueS[1] = 1;
            dimensions.valueS[2] = 10;
            dimensions.valueS[3] = 0;
            GS_TASK(work, 0x1c) = func_00111380(task, 0x18bf,
                                                dimensions.value,
                                                work + 0x44);
            GS_U32(work, 0) = 2;
        }
        break;
    case 2:
        allDone = 1;
        for (i = 0; i < 3; i++)
        {
            if (func_001114b0(GS_TASK(work, 0x14 + i * 4)) == 0)
            {
                allDone = 0;
            }
        }
        if (allDone != 0)
        {
            GS_PTR(work, 0x20) = func_0010c1a0(NULL, D_005E43F0,
                                                NULL, NULL, NULL, NULL,
                                                NULL, NULL, D_005E4418, 0x426);
            GS_PTR(work, 0x24) = func_0010c1a0(NULL, D_005E4430,
                                                NULL, NULL, NULL, NULL,
                                                NULL, NULL, D_005E4418, 0x427);
            GS_PTR(work, 0x28) = func_0010c1a0(NULL, D_005E4450,
                                                NULL, NULL, NULL, NULL,
                                                NULL, NULL, D_005E4418, 0x428);
            GS_PTR(work, 0x2c) = func_0010c1a0(NULL, D_005E4480,
                                                NULL, NULL, NULL, NULL,
                                                NULL, NULL, D_005E4418, 0x429);
            GS_U32(work, 0) = 3;
        }
        break;
    case 3:
        allDone = 1;
        for (i = 0; i < 4; i++)
        {
            void* stream = GS_PTR(work, 0x20 + i * 4);
            if (stream != NULL)
            {
                done = 0;
                GS_PTR(work, 0x30 + i * 4) = func_0010c3a0(stream, &done, 0);
                if (done == 0)
                {
                    allDone = 0;
                }
                else
                {
                    GS_PTR(work, 0x20 + i * 4) = NULL;
                }
            }
        }
        if (allDone != 0)
        {
            GS_U32(work, 0) = 4;
        }
        break;
    case 4:
        break;
    case 5:
        ((struct GsLateTimerWork*)work)->timer++;
        if (((struct GsLateTimerWork*)work)->timer == 0x46)
        {
            for (i = 0; i < 3; i++)
            {
                KwlnTask** child = &GS_TASK(work, 0x14 + i * 4);
                if (*child != NULL && kwlnTaskGetState(*child) == 3)
                {
                    *child = NULL;
                }
                if (*child != NULL)
                {
                    kwlnTaskDestroyWithHierarchy(*child);
                }
                *child = NULL;
            }
        }
        if (((struct GsLateTimerWork*)work)->timer < 6 || ((struct GsLateTimerWork*)work)->timer > 8)
        {
            if (((struct GsLateTimerWork*)work)->timer > 8 && ((struct GsLateTimerWork*)work)->timer < 0x41)
            {
                func_00113a30(100.0f, 0.0f, 0.0f, 0x0f3956ff, 0x280, 0x1c0);
            }
        }
        else
        {
            func_00113a30(100.0f, 0.0f, 0.0f, 0x0f395603, 0x280, 0x1c0);
        }
        for (i = 0; i < 2; i++)
        {
            KwlnTask** child = &GS_TASK(work, 0x14 + i * 4);
            if (*child != NULL && kwlnTaskGetState(*child) == 3)
            {
                *child = NULL;
            }
            if (*child != NULL)
            {
                func_001115b0(*child);
                func_001115e0(*child);
            }
        }
        if (((struct GsLateTimerWork*)work)->timer > 5 && ((struct GsLateTimerWork*)work)->timer < 0x46)
        {
            func_00114af0(99.0f, 0.0f, 0.0f, 0xffffffff,
                          0x280, 0x1c0, GS_PTR(work, 0x34));
        }
        if (GS_TASK(work, 0x1c) != NULL && kwlnTaskGetState(GS_TASK(work, 0x1c)) == 3)
        {
            GS_TASK(work, 0x1c) = NULL;
        }
        if (GS_TASK(work, 0x1c) != NULL)
        {
            func_001115b0(GS_TASK(work, 0x1c));
            func_001115e0(GS_TASK(work, 0x1c));
        }
        if (((struct GsLateTimerWork*)work)->timer > 0x31 && ((struct GsLateTimerWork*)work)->timer < 0x46)
        {
            alpha = (u32)(((((struct GsLateTimerWork*)work)->timer - 0x32) * 0xff) / 0xf);
            func_00114af0(98.0f, 0.0f, 0.0f,
                          alpha | 0xffffff00, 0x280, 0x1c0,
                          GS_PTR(work, 0x30));
        }
        if (((struct GsLateTimerWork*)work)->timer > 0x36 && ((struct GsLateTimerWork*)work)->timer < 0x50)
        {
            if (((struct GsLateTimerWork*)work)->timer < 0x41)
            {
                alpha = (u32)(((((struct GsLateTimerWork*)work)->timer - 0x37) * 0xff) / 10);
            }
            else if (((struct GsLateTimerWork*)work)->timer < 0x46)
            {
                alpha = 0xff;
            }
            else
            {
                alpha = 0xff - (u32)(((((struct GsLateTimerWork*)work)->timer - 0x46) * 0xff) / 10);
            }
            func_00113d80(97.0f, 0.0f, 0.0f,
                          alpha | 0xffffff00, 0x280, 0x1c0);
        }
        if (((struct GsLateTimerWork*)work)->timer > 0x4f)
        {
            return KWLNTASK_STOP;
        }
        break;
    default:
        break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_0018B270
void func_0018b270(KwlnTask* task)
{
    s32 cacheIndex;
    s32 resourceIndex;
    GsB270Work* work = (GsB270Work*)task->workData;

    for (cacheIndex = 0; cacheIndex < 3; cacheIndex++)
    {
        if (GS_PTR((u8*)work + cacheIndex * sizeof(GsB270Entry), 0x154) != NULL)
        {
            H_Cdvd_CacheRemove(
                GS_PTR((u8*)work + cacheIndex * sizeof(GsB270Entry), 0x154));
        }
        GS_PTR((u8*)work + cacheIndex * sizeof(GsB270Entry), 0x154) = NULL;
    }
    for (resourceIndex = 0; resourceIndex < 4; resourceIndex++)
    {
        if (GS_PTR((u8*)work + resourceIndex * sizeof(void*), 0x30) != NULL)
        {
            func_004d0f00(
                GS_PTR((u8*)work + resourceIndex * sizeof(void*), 0x30));
            GS_PTR((u8*)work + resourceIndex * sizeof(void*), 0x30) = NULL;
        }
    }
    if (work->header.cdvd != NULL)
    {
        H_Cdvd_Destroy(work->header.cdvd);
        work->header.cdvd = NULL;
    }
    GS_FREE(work);
}

// FUN_0018B360
s32 func_0018b360(KwlnTask* task)
{
    return GS_S32(task->workData, 0) > 3;
}


// FUN_0018B380 NONMATCHING
void* func_0018b380(KwlnTask* task)
{
    struct GsB380Work
    {
        u32 state;
        u8 pad04[0x10];
        KwlnTask* tasks[3];
        u8 pad20[0x18];
        u32 payload38;
        u32 payload3c;
        u8 pad40[0xa30];
        s32 status;
    };
    struct GsB380Work* work = (struct GsB380Work*)task->workData;
    void* (**allocator)(u32, u32, u32);

    if (work->state == 4)
    {
        func_00111530(work->tasks[0]);
        func_00111530(work->tasks[1]);
        func_00111530(work->tasks[2]);
        work->status = -2;
        allocator = (void* (**)(u32, u32, u32))D_00960184_abs;

        {
            u32 payload = work->payload38;
            void* allocation;
            allocation = (*allocator)(1, 0x10, 0x40000);
            if (allocation != NULL)
            {
                if (kwlnTaskCreate(NULL, D_005E4320, 0x18c0,
                                   func_00188c30, func_0018a9c0, allocation) != NULL)
                {
                    GS_U32(allocation, 0xc) = payload;
                }
            }
        }
        {
            u32 payload = work->payload38;
            void* allocation;
            allocation = (*allocator)(1, 0x10, 0x40000);
            if (allocation != NULL)
            {
                if (kwlnTaskCreate(NULL, D_005E4340, 0x18c0,
                                   func_00189230, func_0018a9c0, allocation) != NULL)
                {
                    GS_U32(allocation, 0xc) = payload;
                }
            }
        }
        {
            u32 payload = work->payload38;
            void* allocation;
            allocation = (*allocator)(1, 0x10, 0x40000);
            if (allocation != NULL)
            {
                if (kwlnTaskCreate(NULL, D_005E4360, 0x18c0,
                                   func_00189810, func_0018a9c0, allocation) != NULL)
                {
                    GS_U32(allocation, 0xc) = payload;
                }
            }
        }
        {
            u32 payload = work->payload3c;
            void* allocation;
            allocation = (*allocator)(1, 0x10, 0x40000);
            if (allocation != NULL)
            {
                if (kwlnTaskCreate(NULL, D_005E4380, 0x18c0,
                                   func_00189df0, func_0018a9c0, allocation) != NULL)
                {
                    GS_U32(allocation, 0xc) = payload;
                }
            }
        }
        {
            u32 payload = work->payload3c;
            void* allocation;
            allocation = (*allocator)(1, 0x10, 0x40000);
            if (allocation != NULL)
            {
                if (kwlnTaskCreate(NULL, D_005E43A0, 0x18c0,
                                   func_0018a3f0, func_0018a9c0, allocation) != NULL)
                {
                    GS_U32(allocation, 0xc) = payload;
                }
            }
        }
        work->state = 5;
    }
}

// FUN_0018B5F0
s32 func_0018b5f0(KwlnTask* task)
{
    u8* work = (u8*)task->workData;
    if (GS_U32(work, 0) == 5)
    {
        return GS_S32(work, 0xa70);
    }
    return 0;
}

// FUN_0018B620
KwlnTask* func_0018b620(KwlnTask* parent, s32 mode)
{
    void* work;
    KwlnTask* task;

    work = GS_ALLOC(1, 0xa74, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent, D_005E44B0, 0x18bf,
                          func_0018a9f0, func_0018b270, work);
    if (task == NULL)
    {
        return NULL;
    }
    GS_S32(work, 4) = mode;
    return task;
}

// FUN_0018B6D0
void* func_0018b6d0(s32 count)
{
    return GS_ALLOC((u32)count, 0x44, 0x40000);
}

// FUN_0018B700
u32 func_0018b700(void* transition)
{
    GsTransition* work = (GsTransition*)transition;

    if (work->enabled == 0)
    {
        return 0;
    }
    if (work->elapsed < work->end)
    {
        work->elapsed = work->elapsed + 1;
    }
    if (work->start > work->elapsed)
    {
        return 0;
    }

    switch (work->positionMode)
    {
    case 0:
        return func_0018bb20(transition);
    case 1:
        return func_0018bb80(transition);
    }
    return 0;
}

// FUN_0018B7B0
void func_0018b7b0(void* transition, f32* position)
{
    s32 total;
    s32 elapsed;
    s32 mode;
    f32 phase;

    total = GS_S32(transition, 0x20) - GS_S32(transition, 0x1c);
    elapsed = GS_S32(transition, 0x18) - GS_S32(transition, 0x1c);
    mode = GS_S32(transition, 0xc);
    switch (mode)
    {
    case 0:
        position[0] = GS_F32(transition, 0x30);
        position[1] = GS_F32(transition, 0x34);
        break;
    case 1:
        if (elapsed == total)
        {
            position[0] = GS_F32(transition, 0x30);
            position[1] = GS_F32(transition, 0x34);
        }
        else
        {
            phase = GS_F32(transition, 0x30) - GS_F32(transition, 0x28);
            position[0] = GS_F32(transition, 0x28) +
                          (phase * (f32)elapsed) / (f32)total;
            phase = GS_F32(transition, 0x34) - GS_F32(transition, 0x2c);
            position[1] = GS_F32(transition, 0x2c) +
                          (phase * (f32)elapsed) / (f32)total;
        }
        break;
    case 2:
        if (total != 0)
        {
            phase = (f32)((elapsed * 0x5a) / total);
        }
        else
        {
            phase = 90.0f;
        }
        phase = cosf((DAT_007caf38 * phase) / 180.0f);
        if (elapsed == total)
        {
            position[0] = GS_F32(transition, 0x30);
            position[1] = GS_F32(transition, 0x34);
        }
        else
        {
            position[0] = (GS_F32(transition, 0x30) - GS_F32(transition, 0x28)) * phase +
                          GS_F32(transition, 0x28);
            position[1] = (GS_F32(transition, 0x34) - GS_F32(transition, 0x2c)) * phase +
                          GS_F32(transition, 0x2c);
        }
        break;
    case 3:
        if (total != 0)
        {
            phase = (f32)((elapsed * 0x5a) / total);
        }
        else
        {
            phase = 90.0f;
        }
        phase = sinf((DAT_007caf38 * phase) / 180.0f);
        if (elapsed == total)
        {
            position[0] = GS_F32(transition, 0x28);
            position[1] = GS_F32(transition, 0x2c);
        }
        else
        {
            position[0] = GS_F32(transition, 0x30) -
                          (GS_F32(transition, 0x28) - GS_F32(transition, 0x30)) * phase;
            position[1] = GS_F32(transition, 0x34) -
                          (GS_F32(transition, 0x2c) - GS_F32(transition, 0x34)) * phase;
        }
        break;
    }
}

// FUN_0018BA60
void func_0018ba60(void* transition, u8* alpha)
{
    s32 total = GS_S32(transition, 0x20) - GS_S32(transition, 0x1c);
    s32 elapsed = GS_S32(transition, 0x18) - GS_S32(transition, 0x1c);
    s32 mode = GS_S32(transition, 0x10);
    s32 value;

    switch (mode)
    {
    case 0:
        *alpha = 0;
        break;
    case 1:
        value = total == 0 ? 0xff : (elapsed * 0xff) / total;
        *alpha = (u8)(0xff - value);
        break;
    case 2:
        value = total == 0 ? 0xff : (elapsed * 0xff) / total;
        *alpha = (u8)value;
        break;
    }
}

// FUN_0018BB20
u32 func_0018bb20(void* transition)
{
    GsPosition position;
    u8 alpha;

    func_0018b7b0(transition, position.valueF);
    func_0018ba60(transition, &alpha);
    *(GsPosition*)((u8*)transition + 0x38) = position;
    GS_U32(transition, 0x40) = alpha;
    return alpha != 0xff;
}

// FUN_0018BB80
u32 func_0018bb80(void* transition)
{
    GsPosition position;
    u8 alpha;

    func_0018b7b0(transition, position.valueF);
    func_0018ba60(transition, &alpha);
    *(GsPosition*)((u8*)transition + 0x38) = position;
    GS_U32(transition, 0x40) = alpha;
    {
        void* unused;
        func_00115ad0(unused, GS_PTR(transition, 0), GS_S32(transition, 0x14),
                      position.valueF[0], position.valueF[1], 0xff, alpha,
                      GS_F32(transition, 0x24));
    }
    return *(u32*)((u32)transition + 0x40) != 0xff;
}


// FUN_0018BC10
void func_0018bc10(f32 depth, void* transition, s32 drawMode,
                          s32 positionMode, s32 alphaMode,
                          u64 start, u64 end, s32 param0, s32 tile,
                          s32 startFrame, s32 endFrame)
{
    GsPackedPosition endPos;
    GsPackedPosition startPos;

    startPos.value = start;
    endPos.value = end;
    GS_U32(transition, 4) = 1;
    GS_S32(transition, 8) = drawMode;
    GS_S32(transition, 0xc) = positionMode;
    GS_S32(transition, 0x10) = alphaMode;
    *(GsPosition*)((u8*)transition + 0x28) = *(GsPosition*)&startPos;
    *(GsPosition*)((u8*)transition + 0x30) = *(GsPosition*)&endPos;
    GS_S32(transition, 0) = param0;
    GS_S32(transition, 0x14) = tile;
    GS_F32(transition, 0x24) = depth;
    GS_S32(transition, 0x1c) = startFrame;
    GS_S32(transition, 0x20) = endFrame;
    GS_S32(transition, 0x18) = 0;
}

// FUN_0018BC80
void func_0018bc80(void)
{
    HCdvd* cdvd;
    void* archiveEntry;
    u32 size;
    u32 ready;
    u32 allReady;
    s32 i;

    cdvd = H_Cdvd_Request(D_005E44D0, HCDVD_FILEARCHIVE);
    H_Cdvd_ReadSync(cdvd);
    for (i = 0; i < 0x12; i++)
    {
        archiveEntry = H_Cdvd_ArchiveGetFile(cdvd, i, &size);
        D_00846730[i] = func_00112420(archiveEntry);
    }
    do
    {
        func_001120c0();
        allReady = 1;
        for (i = 0; i < 0x12; i++)
        {
            ready = H_Maestro_00111f30((s16*)D_00846730[i]);
            if (ready == 0)
            {
                allReady = 0;
            }
        }
        ready = !(allReady != 0);
    } while (ready != 0);
    H_Cdvd_Destroy(cdvd);
}

/* Removing this loses FUN_0018bd90 (MATCH nd0 -> MISMATCH nd24) - measured W161. */
// FUN_0018BD90
#pragma opt_loop_invariants on
void* func_0018bd90(KwlnTask* task)
{
    GsArchiveTaskWork* work = (GsArchiveTaskWork*)task->workData;
    s32 copyIndex;
    s32 taskIndex;

    switch (work->state)
    {
    case 0:
        work->state = 1;
        break;
    case 1:
        for (copyIndex = 0; copyIndex < 0x12; copyIndex++)
        {
            work->resources[copyIndex] = D_00846730[copyIndex];
        }
        work->tasks[0] = func_0018e390(task, 0, work->resources);
        work->tasks[1] = func_0018e390(task, 1, work->resources);
        work->tasks[2] = func_0018e390(task, 2, work->resources);
        work->tasks[3] = func_0018e390(task, 3, work->resources);
        work->state = 2;
        break;
    case 2:
        break;
    }

    for (taskIndex = 0; taskIndex < 4; taskIndex++)
    {
        if (work->tasks[taskIndex] != NULL)
        {
            func_0018e490(work->tasks[taskIndex], work->argument);
        }
    }
    return KWLNTASK_CONTINUE;
}

#pragma opt_loop_invariants off
// FUN_0018BEE0
void func_0018bee0(KwlnTask* task, s32 pcId, s32 mode)
{
    GsArchiveTaskWork* work = (GsArchiveTaskWork*)task->workData;
    s16 partyId;
    s32 i;

    if (pcId == 1)
    {
        func_0018dde0(work->tasks[0], mode);
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            partyId = datGetPartyId(i);
            if (pcId == partyId)
            {
                func_0018dde0(work->tasks[i + 1], mode);
                return;
            }
        }
    }
}

// FUN_0018BFA0
void func_0018bfa0(KwlnTask* task)
{
    GsCdvdWork* work = (GsCdvdWork*)task->workData;

    if (work->cdvd != NULL)
    {
        H_Cdvd_Destroy(work->cdvd);
        work->cdvd = NULL;
    }
    GS_FREE(work);
}

// FUN_0018BFF0
KwlnTask* func_0018bff0(KwlnTask* parent)
{
    void* work;
    KwlnTask* task;

    work = GS_ALLOC(1, 0x64, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent, D_005E44E0, 0x18b3,
                          func_0018bd90, func_0018bfa0, work);
    if (task == NULL)
    {
        return NULL;
    }
    GS_U32(work, 8) = 1;
    return task;
}

// FUN_0018C0A0
u32 func_0018c0a0(KwlnTask* task)
{
    return GS_U32(task->workData, 0) == 2;
}

// FUN_0018C0C0
void func_0018c0c0(KwlnTask* task, s32 visible)
{
    u8* work = (u8*)task->workData;
    GS_S32(work, 8) = visible;
    if (GS_U32(task->workData, 0) == 2)
    {
        func_0018e490(GS_TASK(work, 0xc), visible);
        func_0018e490(GS_TASK(work, 0x10), visible);
        func_0018e490(GS_TASK(work, 0x14), visible);
        func_0018e490(GS_TASK(work, 0x18), visible);
    }
}

// FUN_0018C150 NONMATCHING
void func_0018c150(KwlnTask* task)
{
    void* object;
    GsTransition* transition;
    void* atlas;
    s16 pcId;
    s32 i;
    s32 phase;
    s32 radius;
    s32 alpha;
    f32 angle;
    f32 sine;
    f32 cosine;
    void* sprite;
    GsSprite* node;
    u32 hp;
    u32 maxHp;
    u32 sp;
    u32 maxSp;
    s32 width;

    object = (void*)task;
    transition = (GsTransition*)GS_PTR(object, 0x70);
    pcId = GS_S16(object, 0x14);
    atlas = gsPcAtlas(object, pcId);
    gsDrawSprite(atlas, 1, GS_U8(transition, 0x40), transition->position.valueF[0] + 20.0f, transition->position.valueF[1] + 18.0f, transition->depth);
    if ((datGetBadStatusNoDown(pcId) & 0x80) == 0)
    {
        gsDrawSprite(atlas, 0, GS_U8(transition, 0x40), transition->position.valueF[0] + 20.0f, transition->position.valueF[1] + 18.0f, transition->depth);
    }
    else
    {
        gsDrawSprite(atlas, 2, GS_U8(transition, 0x40), transition->position.valueF[0] + 20.0f, transition->position.valueF[1] + 18.0f, transition->depth);
    }
    gsDrawSprite(GS_PTR(object, 0x2c), 0, GS_U8(transition, 0x40), transition->position.valueF[0] + 44.0f, transition->position.valueF[1] + 39.0f, transition->depth);

    if ((datGetBadStatusNoDown(pcId) & 0x80) != 0)
    {
        GS_U32(object, 0x20)++;
        if (GS_U32(object, 0x20) >= 100)
        {
            GS_U32(object, 0x20) = 0;
        }
        for (i = 0; i < 12; i++)
        {
            phase = (GS_S32(object, 0x20) + i * 15) % 100;
            if (phase <= 50)
            {
                continue;
            }
            angle = DAT_007caf38 * ((f32)((i / 3) * 0x28 >> 2) + 40.0f) / 180.0f;
            sine = sinf(angle);
            cosine = cosf(angle);
            radius = ((phase - 50) * 50) / 50;
            if (phase - 50 < 10)
            {
                alpha = 0xff - (((phase - 50) * 0xff) / 10);
            }
            else if (phase - 50 < 0x28)
            {
                alpha = 0;
            }
            else
            {
                alpha = (((phase - 0x5a) * 0xff) / 10);
            }
            sprite = func_001158b0(NULL, GS_PTR(object, 0x30), (i % 3) + 1);
            node = (GsSprite*)sprite;
            node->depth = transition->depth;
            node->x = transition->position.valueF[0] + 44.0f +
                      (f32)(s32)((f32)radius * cosine);
            node->y = transition->position.valueF[1] + 34.0f -
                      (f32)(s32)((f32)radius * sine);
            node->alpha = (u8)alpha;
            func_001127d0(sprite, 1);
            func_00115980(sprite);
        }
    }

    hp = datGetHp(pcId);
    maxHp = datGetMaxHp(pcId);
    width = ((hp & 0xffff) << 5) / (maxHp & 0xffff);
    if (width != 0x20)
    {
        func_00113a30(transition->depth - 1.0f,
                      transition->position.valueF[0] + (f32)width + 50.0f,
                      transition->position.valueF[1] + 46.0f,
                      0xffffff00, 0x20 - width, 0x14);
    }
    gsDrawSprite(GS_PTR(object, 0x2c), 1, GS_U8(transition, 0x40), transition->position.valueF[0] + 50.0f, transition->position.valueF[1] + 46.0f, transition->depth);
    sp = datGetSp(pcId);
    maxSp = func_0016c670(pcId);
    width = ((sp & 0xffff) << 5) / (maxSp & 0xffff);
    if (width != 0x20)
    {
        func_00113a30(transition->depth - 3.0f,
                      transition->position.valueF[0] + (f32)width + 50.0f,
                      transition->position.valueF[1] + 51.0f,
                      0xffffff00, 0x20 - width, 0x14);
    }
    gsDrawSprite(GS_PTR(object, 0x2c), 2, GS_U8(transition, 0x40), transition->position.valueF[0] + 50.0f, transition->position.valueF[1] + 51.0f, transition->depth - 2.0f);
}

// FUN_0018C780 NONMATCHING
void func_0018c780(KwlnTask* task)
{
    void* object = (void*)task;
    void* transition = GS_PTR(object, 0x70);
    u32 alpha = GS_U8(transition, 0x40);
    s32 frame = GS_S32(object, 0x18);
    s32 fadeFrame;
    s16 scale;
    u8 fadeAlpha;
    void* sprite;
    f32 width;
    f32 height;
    f32 halfWidth;
    f32 halfHeight;

    gsDrawHeader(object, 8, 7, 6);
    gsDrawStatusBars(object);
    if (frame > 5)
    {
        frame = 5;
    }
    sprite = func_001158b0(NULL, GS_PTR(object, 0x3c), 1);
    ((GsSprite*)sprite)->depth = GS_F32(transition, 0x24) - 4.0f;
    scale = (s16)(((frame << 0xc) / 5) + 1);
    ((GsSprite*)sprite)->scaleX = scale;
    ((GsSprite*)sprite)->scaleY = scale;
    width = func_001126b0(sprite);
    halfWidth = width / 2.0f;
    ((GsSprite*)sprite)->centerX = (s16)(s32)halfWidth;
    height = func_00112740(sprite);
    halfHeight = height / 2.0f;
    ((GsSprite*)sprite)->centerY = (s16)(s32)halfHeight;
    ((GsSprite*)sprite)->angle = 90.0f;
    ((GsSprite*)sprite)->x = GS_F32(transition, 0x38) + 48.0f - halfWidth;
    ((GsSprite*)sprite)->y = GS_F32(transition, 0x3c) + 43.0f - halfHeight;
    ((GsSprite*)sprite)->alpha = (u8)(0xff - (frame * 0xff) / 5);
    func_001127d0(sprite, 1);
    func_00115980(sprite);

    fadeFrame = GS_S32(object, 0x18) - 5;
    if (fadeFrame >= 0 && fadeFrame < 8)
    {
        scale = (s16)((fadeFrame * 0x1000) >> 3);
        fadeAlpha = (u8)(0xff - ((fadeFrame * 0xff) >> 3));
        sprite = func_001158b0(NULL, GS_PTR(object, 0x3c), 0);
        ((GsSprite*)sprite)->depth = GS_F32(transition, 0x24) - 4.0f;
        ((GsSprite*)sprite)->scaleX = (s16)(scale + 1);
        ((GsSprite*)sprite)->scaleY = (s16)(scale + 1);
        width = func_001126b0(sprite);
        halfWidth = width / 2.0f;
        ((GsSprite*)sprite)->centerX = (s16)(s32)halfWidth;
        height = func_00112740(sprite);
        halfHeight = height / 2.0f;
        ((GsSprite*)sprite)->centerY = (s16)(s32)halfHeight;
        ((GsSprite*)sprite)->x = GS_F32(transition, 0x38) + 49.0f - halfWidth;
        ((GsSprite*)sprite)->y = GS_F32(transition, 0x3c) + 43.0f - halfHeight;
        ((GsSprite*)sprite)->alpha = fadeAlpha;
        func_001127d0(sprite, 1);
        func_00115980(sprite);
    }
    (void)alpha;
    GS_S32(object, 0x18)++;
    if (GS_S32(object, 0x18) > 0x11)
    {
        GS_S32(object, 0x18) = 0;
        GS_S32(object, 0xc) = 4;
    }
}

// FUN_0018CE50 NONMATCHING
void func_0018ce50(KwlnTask* task)
{
    void* object = (void*)task;
    void* transition = GS_PTR(object, 0x70);
    void* sprite;
    GsSprite* node;
    f32 width;
    f32 height;
    f32 halfWidth;
    f32 halfHeight;

    gsDrawHeader(object, 8, 7, 6);
    gsDrawStatusBars(object);
    sprite = func_001158b0(NULL, GS_PTR(object, 0x3c), 1);
    node = (GsSprite*)sprite;
    node->depth = GS_F32(transition, 0x24) - 4.0f;
    node->scaleX = 0x1000;
    node->scaleY = 0x1000;
    width = func_001126b0(sprite);
    halfWidth = width / 2.0f;
    node->centerX = (s16)(s32)halfWidth;
    height = func_00112740(sprite);
    halfHeight = height / 2.0f;
    node->centerY = (s16)(s32)halfHeight;
    node->angle = 90.0f;
    node->x = GS_F32(transition, 0x38) + 48.0f - halfWidth;
    node->y = GS_F32(transition, 0x3c) + 43.0f - halfHeight;
    node->alpha = 0x28;
    func_001127d0(sprite, 1);
    func_00115980(sprite);
}

// FUN_0018D320 NONMATCHING
void func_0018d320(KwlnTask* task)
{
    void* object = (void*)task;
    void* transition = GS_PTR(object, 0x70);
    void* sprite;
    GsSprite* node;
    f32 width;
    f32 height;
    f32 halfWidth;
    f32 halfHeight;
    s32 frame;
    s32 burstFrame;
    s32 i;
    u32 alpha;
    u32 burstAlpha;
    u32 randomFrame;
    gsDrawHeader(object, 6, 4, 5);
    gsDrawStatusBars(object);
    frame = GS_S32(object, 0x18);
    if (frame > 5)
    {
        frame = 5;
    }
    alpha = 0xff - (u32)((frame * 0xff) / 5);
    sprite = func_001158b0(NULL, GS_PTR(object, 0x38), 0);
    node = (GsSprite*)sprite;
    node->depth = GS_F32(transition, 0x24) - 4.0f;
    node->scaleX = (s16)((frame << 0xc) / 5);
    node->scaleY = (s16)((frame << 0xc) / 5);
    width = func_001126b0(sprite);
    halfWidth = width / 2.0f;
    node->centerX = (s16)(s32)halfWidth;
    height = func_00112740(sprite);
    halfHeight = height / 2.0f;
    node->centerY = (s16)(s32)halfHeight;
    node->x = GS_F32(transition, 0x38) + 64.0f - halfWidth;
    node->y = GS_F32(transition, 0x3c) + 60.0f - halfHeight;
    node->alpha = (u8)alpha;
    func_001127d0(sprite, 1);
    func_00115980(sprite);

    burstFrame = GS_S32(object, 0x18) - 5;
    if (burstFrame >= 0)
    {
        if (burstFrame < 5)
        {
            randomFrame = (u32)(burstFrame / 5);
        }
        else
        {
            randomFrame = RpRandom() % 0x99;
        }
        burstAlpha = randomFrame & 0xff;
        gsDrawSpriteAlt(GS_PTR(object, 0x38), 1, 0xff, burstAlpha, GS_F32(transition, 0x38) + 28.0f, GS_F32(transition, 0x3c) + 22.0f, GS_F32(transition, 0x24) - 4.0f);
        gsDrawSpriteAlt(GS_PTR(object, 0x38), 2, 0xff, burstAlpha, GS_F32(transition, 0x38) + 59.0f, GS_F32(transition, 0x3c) + 23.0f, GS_F32(transition, 0x24) - 4.0f);
        if (burstFrame < 5)
        {
            gsDrawSpriteAlt(GS_PTR(object, 0x38), 3, 0xff, burstAlpha, GS_F32(transition, 0x38) + 21.0f, GS_F32(transition, 0x3c) + 47.0f, GS_F32(transition, 0x24) - 4.0f);
        }
        if (burstFrame < 5)
        {
            randomFrame = (u32)(burstFrame / 5);
        }
        else
        {
            randomFrame = RpRandom() % 0x99;
        }
        gsDrawSpriteAlt(GS_PTR(object, 0x38), 4, 0xff, randomFrame & 0xff, GS_F32(transition, 0x38) + 49.0f, GS_F32(transition, 0x3c) + 43.0f, GS_F32(transition, 0x24) - 4.0f);
        if (burstFrame < 5)
        {
            randomFrame = (u32)(burstFrame / 5);
        }
        else
        {
            randomFrame = RpRandom() % 0x99;
        }
        gsDrawSpriteAlt(GS_PTR(object, 0x38), 5, 0xff, randomFrame & 0xff, GS_F32(transition, 0x38) + 67.0f, GS_F32(transition, 0x3c) + 62.0f, GS_F32(transition, 0x24) - 4.0f);
    }
    GS_S32(object, 0x18)++;
    if (GS_S32(object, 0x18) > 0x1e)
    {
        GS_S32(object, 0xc) = GS_S32(object, 0x10);
        GS_S32(object, 0x18) = 0;
    }
}

// FUN_0018DB20 NONMATCHING
void* func_0018db20(KwlnTask* task)
{
    u8* object = (u8*)task;
    void* transition = GS_PTR(object, 0x70);
    {
        switch (GS_S32(object, 0xc))
        {
        case 4:
            func_0018ce50(task);
            break;
        case 3:
            func_0018c780(task);
            break;
        case 2:
            func_0018d320(task);
            break;
        case 1:
            gsDrawHeader(object, 3, 1, 0);
            gsDrawSprite(GS_PTR(object, 0x2c), 3, GS_U8(transition, 0x40), GS_F32(transition, 0x38) + 50.0f, GS_F32(transition, 0x3c) + 51.0f, GS_F32(transition, 0x24));
            gsDrawSprite(GS_PTR(object, 0x34), 0, GS_U8(transition, 0x40), GS_F32(transition, 0x38) + 27.0f, GS_F32(transition, 0x3c) + 22.0f, GS_F32(transition, 0x24));
            break;
        case 0:
            func_0018c150(task);
            break;
        default:
            break;
        }
    }
    return KWLNTASK_CONTINUE;
}

// FUN_0018DDE0
void func_0018dde0(KwlnTask* transitionTask, s32 mode)
{
    void* transition = transitionTask->workData;

    switch (mode)
    {
    case 0:
        GS_S32(transition, 0xc) = 0;
        break;
    case 1:
        GS_S32(transition, 0xc) = 3;
        break;
    case 2:
        GS_S32(transition, 0xc) = 1;
        break;
    case 3:
        GS_S32(transition, 0x10) = GS_S32(transition, 0xc);
        GS_S32(transition, 0xc) = 2;
        break;
    }
    GS_S32(transition, 0x18) = 0;
}

// FUN_0018DE60 NONMATCHING
void* func_0018de60(KwlnTask* task)
{
    u8* work = (u8*)task->workData;
    s32 count = 1;
    s16 partyId;
    s32 i;
    f32 y;
    GsPackedPosition start;
    GsPackedPosition end;
    void* transition;

    if (GS_U32(work, 0) == 1)
    {
        for (i = 0; i < 3; i++)
        {
            partyId = datGetPartyId(i);
            if (partyId != 0)
            {
                count++;
            }
        }
        if (GS_S32(work, 8) != 0 && datGetPartyId(GS_S32(work, 8) - 1) == 0)
        {
            GS_S32(work, 4) = 0;
            transition = GS_TASK(work, 0x70)->workData;
            GS_S32(transition, 4) = 0;
        }
        if (GS_S32(work, 8) == 0)
        {
            GS_S32(work, 0x14) = 1;
        }
        else
        {
            partyId = datGetPartyId(GS_S32(work, 8) - 1);
            if (GS_S32(work, 0x14) != partyId)
            {
                GS_S32(work, 4) = 0;
                GS_S32(work, 0x14) = partyId;
            }
        }
        if (GS_S32(work, 4) == 3)
        {
            if (count != GS_S32(work, 0x1c))
            {
                GS_S32(work, 0x1c) = count;
                if (count == 4)
                {
                    y = (f32)(GS_S32(work, 8) * 0x35) + 195.0f;
                }
                else if (count == 3)
                {
                    y = (f32)(GS_S32(work, 8) * 0x3c) + 234.0f;
                }
                else if (count == 2)
                {
                    y = (f32)(GS_S32(work, 8) * 0x3c) + 294.0f;
                }
                else
                {
                    y = 324.0f;
                }
                printf(D_005E4500, GS_S32(work, 8), func_00530da0(y));
                transition = GS_TASK(work, 0x70)->workData;
                start.valueF[0] = GS_F32(transition, 0x38);
                start.valueF[1] = GS_F32(transition, 0x3c);
                end.valueF[0] = 834.0f;
                end.valueF[1] = y;
                func_0018bc10(110.0f, transition, 0, 2, 0,
                              start.value, end.value, 0, 0, 0, 0);
            }
        }
        else if (GS_S32(work, 4) == 2)
        {
            GS_S32(work, 4) = 0;
        }
        else if (GS_S32(work, 4) == 1)
        {
            transition = GS_TASK(work, 0x70)->workData;
            if (GS_S32(transition, 0x18) == GS_S32(transition, 0x20))
            {
                GS_S32(work, 4) = 3;
            }
        }
        else if (GS_S32(work, 4) == 0)
        {
            GS_S32(work, 0x1c) = count;
            if (GS_S32(work, 0x14) != 0)
            {
                if (count == 4)
                {
                    y = (f32)(GS_S32(work, 8) * 0x35) + 195.0f;
                }
                else if (count == 3)
                {
                    y = (f32)(GS_S32(work, 8) * 0x3c) + 234.0f;
                }
                else if (count == 2)
                {
                    y = (f32)(GS_S32(work, 8) * 0x3c) + 294.0f;
                }
                else
                {
                    y = 324.0f;
                }
                printf(D_005E4500, GS_S32(work, 8), func_00530da0(y));
                GS_S32(work, 4) = 1;
                transition = GS_TASK(work, 0x70)->workData;
                start.valueF[0] = 834.0f;
                start.valueF[1] = y;
                end.valueF[0] = 534.0f;
                end.valueF[1] = y;
                func_0018bc10(110.0f, transition, 0, 2, 1,
                              start.value, end.value, 0, 0, 0, 0);
            }
        }
        if (GS_S32(work, 4) == 1 || GS_S32(work, 4) == 3)
        {
            func_0018db20(GS_TASK(work, 0x70));
        }
    }
    else if (GS_U32(work, 0) == 0)
    {
        GS_TASK(work, 0x70) = (KwlnTask*)func_0018b6d0(1);
        GS_S32(work, 4) = 0;
        GS_TASK(work, 0xc) = NULL;
        GS_U32(work, 0) = 1;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_0018E330
void func_0018e330(KwlnTask* task)
{
    GsResourceWork* work = (GsResourceWork*)task->workData;

    if (work->allocation != NULL)
    {
        GS_FREE(work->allocation);
    }
    work->allocation = NULL;
    GS_FREE(work);
}

// FUN_0018E390
KwlnTask* func_0018e390(KwlnTask* parent, s32 index, void* resources)
{
    GsResourceWork* work;
    KwlnTask* task;
    s32 i;

    work = GS_ALLOC(1, 0x74, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent, D_005E4520, 0x18b4,
                          func_0018de60, func_0018e330, work);
    if (task == NULL)
    {
        return NULL;
    }
    for (i = 0; i < 0x12; i++)
    {
        GS_PTR((u8*)work + i * 4, 0x28) = ((void**)resources)[i];
    }
    GS_U32(work, 0x24) = 1;
    GS_S32(work, 8) = index;
    return task;
}

// FUN_0018E490
void func_0018e490(KwlnTask* task, s32 visible)
{
    GS_S32((u8*)task->workData, 0x24) = visible;
}

// FUN_0018E4A0
void func_0018e4a0(void)
{
    HCdvd* cdvd;
    void* entry;
    u32 size;

    cdvd = H_Cdvd_Request(D_005E4540, HCDVD_FILEARCHIVE);
    H_Cdvd_ReadSync(cdvd);
    entry = H_Cdvd_ArchiveGetFile(cdvd, 0, &size);
    DAT_007ce008 = func_00112420(entry);
    do
    {
        func_001120c0();
    } while (H_Maestro_00111f30((s16*)DAT_007ce008) ? 0 : 1);
    H_Cdvd_Destroy(cdvd);
}

// FUN_0018E540
void* func_0018e540(KwlnTask* task)
{
    u8* work = (u8*)task->workData;

    switch (GS_U32(work, 0))
    {
    case 0:
        GS_U32(work, 0) = 1;
        break;
    case 1:
        GS_PTR(work, 0x214) = DAT_007ce008;
        GS_U32(work, 0) = 2;
        break;
    case 2:
        func_0018e8e0(work);
        break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_0018E5C0
void func_0018e5c0(KwlnTask* task, void* record)
{
    GsAnimationWork* work = (GsAnimationWork*)task->workData;
    GsPackedPosition firstStart;
    GsPackedPosition end;
    GsPackedPosition commonStart;
    GsPackedPosition alternateStart;

    if (work->transitionInitialized != 0)
    {
        func_00524270((u8*)work + 0x108, (u8*)work + 8);
        end.valueF[0] = 40.0f;
        end.valueF[1] = 407.0f;
        firstStart = end;
        end.valueF[0] = end.valueF[0] + 200.0f;
        gsConfigureTransition((u8*)work->transitions + 0x88, 0, 2, 2,
                              firstStart.value, end.value, 0, 0, 0, 10,
                              100.0f);
    }
    else
    {
        end.valueF[0] = 194.0f;
        end.valueF[1] = 399.0f;
        alternateStart = end;
        alternateStart.valueF[0] = alternateStart.valueF[0] - 200.0f;
        gsConfigureTransition(work->transitions, 0, 2, 1,
                              alternateStart.value, end.value, 0, 0, 0, 10,
                              100.0f);
        work->transitionInitialized = 1;
    }
    func_00524270((u8*)work + 8, record);
    end.valueF[0] = 40.0f;
    end.valueF[1] = 407.0f;
    commonStart = end;
    commonStart.valueF[0] = commonStart.valueF[0] - 200.0f;
    gsConfigureTransition((u8*)work->transitions + 0x44, 0, 2, 1,
                          commonStart.value, end.value, 0, 0, 0, 10,
                          100.0f);
}

// FUN_0018E7A0
void func_0018e7a0(KwlnTask* task)
{
    GsAnimationWork* work = (GsAnimationWork*)task->workData;

    if (work->cdvd != NULL)
    {
        work->cdvd = NULL;
        H_Cdvd_Destroy(NULL);
    }
    if (work->transitions != NULL)
    {
        GS_FREE(work->transitions);
    }
    work->transitions = NULL;
    GS_FREE(work);
}

// FUN_0018E820
KwlnTask* func_0018e820(KwlnTask* parent)
{
    KwlnTask* task;
    void* work;

    work = GS_ALLOC(1, 0x218, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreate(parent, D_005E4560, 0x18b4,
                          func_0018e540, func_0018e7a0, work);
    if (task == NULL)
    {
        return NULL;
    }
    GS_PTR(work, 0x210) = func_0018b6d0(10);
    GS_U32(work, 0x20c) = 1;
    return task;
}

// FUN_0018E8E0
void func_0018e8e0(void* workData)
{
    GsAnimationWork* work = (GsAnimationWork*)workData;
    s32 i;
    void* unused;
    s32 transitionOffset;
    GsTransition* transition;

    for (i = 0; i < 3; i++)
    {
        transitionOffset = i * sizeof(GsTransition);
        if (func_0018b700((u8*)work->transitions + transitionOffset) != 0)
        {
            transition = (GsTransition*)((u8*)work->transitions + transitionOffset);
            if (work->visible != 0)
            {
                switch (i)
                {
                case 0:
                {
                    f32 x;
                    f32 y;

                    func_001159f0(unused, work->atlas, 0,
                                  *(u8*)&transition->alpha,
                                  transition->position.valueF[0],
                                  transition->position.valueF[1],
                                  transition->depth);
                    x = 21.0f + transition->position.valueF[0] - 174.0f - 27.0f;
                    y = 3.0f + (412.0f + transition->position.valueF[1] - 399.0f);
                    gsDrawSpritePositionFirst(x, y, unused, work->atlas, 2,
                                              *(u8*)&transition->alpha,
                                              transition->depth);
                    break;
                }
                case 1:
                {
                    u32 alpha;

                    alpha = transition->alpha;
                    alpha = 0xff - alpha;
                    func_003b2cb0(
                        transition->depth,
                        (s32)((f32)(s32)transition->position.valueF[0] - 10.0f),
                        (s32)transition->position.valueF[1] + 5,
                        alpha | 0xffffff00, 5, 1, (u8*)work + 8, 0x10, 0);
                    break;
                }
                case 2:
                {
                    u32 alpha;

                    alpha = transition->alpha;
                    alpha = 0xff - alpha;
                    func_003b2cb0(
                        transition->depth,
                        (s32)((f32)(s32)transition->position.valueF[0] - 10.0f),
                        (s32)transition->position.valueF[1] + 5,
                        alpha | 0xffffff00, 5, 1, (u8*)work + 0x108, 0x10, 0);
                    break;
                }
                }
            }
        }
    }
}

// FUN_0018EB30
void func_0018eb30(KwlnTask* task, u32 visible)
{
    GS_U32((u8*)task->workData, 0x20c) = visible;
}

// FUN_0018EB40 NONMATCHING
void* func_0018eb40(KwlnTask* task)
{
    u8* work = (u8*)task->workData;
    char path[264];
    GsPackedDimensions dimensions;
    KwlnTask* loader;
    void (**renderState)(u32, u32);
    u32 mode;

    kwlnGetMainCamera();
    renderState = (void (**)(u32, u32))D_00960090_abs;
    (*renderState)(6, 1);
    (*renderState)(7, 2);
    (*renderState)(8, 1);
    (*renderState)(9, 1);
    (*renderState)(0xc, 1);
    (*renderState)(0xb, 6);
    (*renderState)(10, 5);
    mode = GS_U32(work, 0);
    switch (mode)
    {
    case 0:
        switch (GS_U32(work, 4))
        {
        case 0:
        case 1:
        case 2:
        case 6:
        default:
            sprintf(path, (const char*)D_005E4580);
            break;
        case 3:
            sprintf(path, (const char*)D_005E45A0);
            break;
        case 4:
            sprintf(path, (const char*)D_005E45C0);
            break;
        case 5:
            sprintf(path, (const char*)D_005E45E0);
            break;
        case 7:
            sprintf(path, (const char*)D_005E4600);
            break;
        case 8:
            sprintf(path, (const char*)D_005E4620);
            break;
        case 9:
            sprintf(path, (const char*)(datGetScenarioMode() == 0 ? D_005E4660 : D_005E4640));
            break;
        case 10:
            sprintf(path, (const char*)D_005E4680);
            break;
        }
        GS_U32(work, 0) = 1;
        break;
    case 1:
        dimensions.valueS[0] = 0x29;
        dimensions.valueS[1] = 4;
        dimensions.valueS[2] = 0xb;
        switch (GS_U32(work, 4))
        {
        case 0: dimensions.valueS[3] = 0; break;
        case 1: dimensions.valueS[3] = 0; break;
        case 2: dimensions.valueS[3] = 0; break;
        case 3: dimensions.valueS[3] = 1; break;
        case 4: dimensions.valueS[3] = 2; break;
        case 5: dimensions.valueS[3] = 3; break;
        case 6: dimensions.valueS[3] = 0; break;
        case 7: dimensions.valueS[3] = 4; break;
        case 8: dimensions.valueS[3] = 5; break;
        case 9: dimensions.valueS[3] = datGetScenarioMode() == 0 ? 6 : 8; break;
        case 10: dimensions.valueS[3] = 7; break;
        default: dimensions.valueS[3] = 0; break;
        }
        loader = func_00111150(task, dimensions.value);
        GS_TASK(work, 8) = loader;
        GS_U32(work, 0) = 2;
        break;
    case 2:
        if (func_001114b0(GS_TASK(work, 8)) != 0)
        {
            func_00111520(GS_TASK(work, 8), 0x32);
            GS_U32(work, 0) = 3;
        }
        break;
    case 3:
        break;
    case 4:
        func_00111530(GS_TASK(work, 8));
        GS_U32(work, 0) = 5;
        break;
    case 5:
        if (GS_S32(work, 0x60) < 0x32)
        {
            GS_S32(work, 0x60)++;
        }
        else if (GS_U32(work, 0x68) != 0)
        {
            GS_S32(work, 0x60)++;
            func_00111500(GS_TASK(work, 8));
        }
        if (kwlnTaskGetState(GS_TASK(work, 8)) == 3)
        {
            return KWLNTASK_STOP;
        }
        break;
    default:
        break;
    }
    return KWLNTASK_CONTINUE;
}

// FUN_0018EF60
void func_0018ef60(KwlnTask* task)
{
    GsLargeCdvdWork* work = (GsLargeCdvdWork*)task->workData;

    if (work->cdvd != NULL)
    {
        H_Cdvd_Destroy(work->cdvd);
        work->cdvd = NULL;
    }
    GS_FREE(work);
}

// FUN_0018EFB0
KwlnTask* func_0018efb0(KwlnTask* parent, s32 mode)
{
    void* work;
    KwlnTask* task;

    work = GS_ALLOC(1, 0x3d0, 0x40000);
    if (work == NULL)
    {
        return NULL;
    }
    task = kwlnTaskCreateWithAutoPriority(parent, 0x106f, D_005E46A0,
                                          func_0018eb40,
                                          func_0018ef60, work);
    if (task == NULL)
    {
        return NULL;
    }
    GS_S32(work, 4) = mode;
    return task;
}

// FUN_0018F060
u32 func_0018f060(KwlnTask* task)
{
    return GS_U32(task->workData, 0) == 3;
}

// FUN_0018F080
void func_0018f080(KwlnTask* task)
{
    GS_U32(task->workData, 0) = 4;
}

// FUN_0018F0A0
u32 func_0018f0a0(void)
{
    return 0x3f;
}

// FUN_0018F0B0
u32 func_0018f0b0(KwlnTask* task)
{
    return GS_U32(task->workData, 0x60);
}

// FUN_0018F0C0
u32 func_0018f0c0(KwlnTask* task)
{
    return GS_S32(task->workData, 0x60) > 0x31;
}

// FUN_0018F0E0
void func_0018f0e0(KwlnTask* task)
{
    GS_U32(task->workData, 0x68) = 1;
}
