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
extern s32 func_00111500(KwlnTask* task);
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
extern void func_00114af0(f32 depth, u32 color, f32 x, f32 y,
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

typedef struct GsEb40WorkView
{
    u8 reserved00[0x60];
    s32 frame;
    u32 reserved64;
    u32 release;
} GsEb40WorkView;

typedef struct GsDb20WorkView
{
    u8 reserved00[0xc];
    s32 state;
    u8 reserved10[4];
    s16 pcId;
    u8 reserved16[0xe];
    s32 visible;
    u8 reserved28[4];
    void* sprite2c;
    u8 reserved30[4];
    void* sprite34;
    u8 reserved38[4];
    void* atlases[13];
    void* transition;
} GsDb20WorkView;






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


















/* Removing this loses FUN_0018bd90 (MATCH nd0 -> MISMATCH nd24) - measured W161. */































