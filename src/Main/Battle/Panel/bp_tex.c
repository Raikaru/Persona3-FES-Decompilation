#include "Main/Battle/Panel/bp_tex.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"
#include "rw/rwcore.h"

static u32* sBcmPanel;
extern u8 D_00960090_abs[];
extern u8 D_0096009C_abs[];
extern void (*D_0096009C)(u32*, u32, u32, u32, u32);
#pragma alias D_0096009C_u32 D_0096009C
extern u32 D_0096009C_u32[];
u32 FUN_0021c3f0();
u32 FUN_0021cca0();
void FUN_0021d3b0();
u32 FUN_0021cce0();
void FUN_00226320();
void FUN_00222d60();
void FUN_0021e380();
void FUN_00222b90();
void FUN_002230e0();
u32 FUN_0021c450();
void FUN_0021d950(void* destination, const u8* color);
void FUN_0021d8e0(void* destination, const f32* rect);
void FUN_00224860();
void FUN_00225670();
void FUN_00227d10();
void FUN_00238980();
void bpIFont00238bf0(void* glyphs, s32 capacity, const char* text, s32 font, const float* origin);
void FUN_00238dc0(void* destination, s32 count, u32 value, s32 mode, const f32* layout);
extern void FUN_003b1360();
extern u32 FUN_00239140(s32);
extern void FUN_003b0d70(u32 resource, s32 x, s32 y);
extern void FUN_003b0e20(u32 resource, u32 color);
extern void FUN_0021dd60(void* destination, const u8* colors);
extern f32 fGpffff83e8;
void FUN_0022C210();
static u8* bcm_panel_record(u32 index);
#define BCM_29_STATE(...) (*setStatePtr)(__VA_ARGS__)
#define BCM_29_QUAD(...) (*setQuadPtr)(__VA_ARGS__)
#define BCM_29_STATE2(...) (*setStatePtr2)(__VA_ARGS__)
#define BCM_2AE_STATE(...) (*pRender)(__VA_ARGS__)
#define BCM_2AE_QUAD(...) (*pQuad)(__VA_ARGS__)


typedef struct RtQuat RtQuat;

extern u32* DAT_007ce354;
#define BP_TEX_GLOBAL DAT_007ce354
#define BP_TEX_U32(base, offset) (*(u32*)((u8*)(base) + (offset)))
#define BP_TEX_S32(base, offset) (*(s32*)((u8*)(base) + (offset)))
#define BP_TEX_F32(base, offset) (*(f32*)((u8*)(base) + (offset)))
#define BP_TEX_PTR(base, offset) (*(u32**)((u8*)(base) + (offset)))
#define BP_TEX_NODE_FLAGS(node) ((node)[0])
#define BP_TEX_NODE_NEXT(node) ((u32*)(node)[0x3f1])
#define BP_TEX_NODE_PREV(node) ((u32*)(node)[0x3f0])
#define BP_TEX_NODE_OWNER(node) ((u32*)(node)[0x3f2])

extern void* func_00198590(void);
extern RwMatrix* func_004cb2f0(void* frame);
extern f32 func_004c6ac0(const RwV3d* value);
extern void func_0021a920(u32 value, u32 arg);
extern void func_0021ab80(u16 value);
extern void func_0020b250(void* value);
extern void func_0020cc80(void* value, const void* color);
extern void func_0020ac90(void* value);
extern void func_0024dc90(void* value);
extern void func_0024f090(void* value);
extern void func_0024f2c0(void* state, f32 value);
extern void func_0024f960(void* state, void* value);
extern void func_0024f9f0(void* state, void* value);
extern void func_0024faf0(void* state, void* value);
extern void func_0024fba0(void* state, void* value);
extern void func_0024fc40(void* state, void* value);
extern void func_0024fda0(void* value);
extern void func_0024fe00(void* value);
extern void func_00250ef0(f32 value, void* state);
extern void func_0024da60(void* state);
extern void func_0024daf0(void* state);
extern u32 func_00250b90(void* state);
extern void func_00251030(void* state);
extern f32 func_0020c660(u32 index, s32 count);
extern void func_00250cf0(u32* work, void* target, f32 startAngle, f32 endAngle, s32 frames);
extern void func_002505b0(void* state, void* value, s32 duration, const f32* offsets);
extern void func_005225a8(u32 id, ...);
extern void func_004bdde0(s32 mode, void* value, void* pos, s32 flags);
extern u32 func_00488f30(void);
extern s32 func_0051e0e0(s32 value);
extern f32 func_0052e878(f32 value);
extern f32 func_0052e6d8(f32 value);
extern f32 func_0020c500(void* object, f32 value);
extern void func_0020c400(void* object, const f32* position, f32 scale, void* output);
extern void func_00259190(void* node, void* values, s32* count);
extern void func_00258f80(void* node);
extern void func_00258630(void* node);
extern void func_00257d00(void* out, u32 index, void* source, s32 count);
extern void func_00257d90(void* out, void* source);
extern void func_00256f20(void* node, void* values, s32* count);
extern void func_00256fa0(void* node, void* values, s32* count);
extern void func_002564c0(void* node);
extern void func_00250a30(void* state, void* value, u32 duration);
extern void func_002508c0(void* state, void* value, s32 duration);
extern void func_00255b20(void);
extern void func_0025b300(void);
extern void func_0025b3b0(void);
extern void FUN_0010a4e0(u32, u32, u32, u32);
extern void func_0019d3f0(const char* file, s32 line);
extern void func_004c69f0(void* output, const void* input);
extern void func_0034ff90(void* resource, const void* color);
extern void func_0034ff70(void* resource, f32 scalar);
extern void func_0034fdf0(void* resource, const void* position);
extern void func_0034fe30(void* resource, u32 a, u32 b, u32 c);
extern void func_0034fd30(void* resource);
extern void func_0034fd70(void* resource, u32 layer);
extern f32 DAT_007cad60;
extern f32 DAT_007cc470;
extern f32 DAT_007caf38;
extern u64 D_0068EA30;
#pragma alias D_0068EA30_abs D_0068EA30
extern volatile u8 D_0068EA30_abs[];
extern f32 D_0068EA38;
#pragma alias D_0068EA38_abs D_0068EA38
extern volatile u8 D_0068EA38_abs[];
extern u8 D_0068EA00;
#pragma alias D_0068EA00_abs D_0068EA00
extern volatile u8 D_0068EA00_abs[];
extern u64 D_0068EA90;
#pragma alias D_0068EA90_abs D_0068EA90
extern volatile u8 D_0068EA90_abs[];
extern f32 D_0068EA98;
#pragma alias D_0068EA98_abs D_0068EA98
extern volatile u8 D_0068EA98_abs[];

extern u32 jtbl_00960178[];
extern void (*jtbl_0096017C)(void* memory);
#pragma alias jtbl_0096017C_abs jtbl_0096017C
extern u32 jtbl_0096017C_abs[];
extern void func_004cde90(void* resource);
extern RwCamera* kwlnGetMainCamera(void);
extern f32 func_0052ea18(f32 x, f32 y);
extern f32 D_00960088;
#pragma alias D_00960088_abs D_00960088
extern volatile /* Removing this file's qualifier batch loses 0 MATCH(es) and worsens 1 other function(s) - measured W170. */ f32 D_00960088_abs[];
extern f32 sqrtf(f32 value);
extern RwRaster* func_004ce0f0(u32 width, u32 height, u32 depth, u32 flags);
extern void* func_004cdf30(RwRaster* raster, u32 palette);
extern void* func_004ce200(RwRaster* raster, void* mipData, u32 level);
extern void func_004cde40(RwRaster* raster);
extern void func_004cde00(RwRaster* raster);
extern void* memcpy(void* destination, const void* source, u32 size);
typedef struct BpTexFrameData
{
    u32 texture;
    u32 id;
    u32 rasterIndex;
    s32 width;
    s32 height;
    s32 x;
    s32 y;
    u8 color[16];
} BpTexFrameData;

typedef struct BpTexTexture
{
    u32 unused;
    BpTexFrameData* frames;
    u32* rasters;
    u32 rasterCount;
    u32 frameCount;
} BpTexTexture;




static inline u32 bpTexByteToFloatBits(u8 value)
{
    f32 converted;

    converted = (f32)value;
    return *(u32*)&converted;
}

static void bpTexWriteColor(void* destination, const u8* color)
{
    BP_TEX_U32(destination, 0x20) = bpTexByteToFloatBits(color[0]);
    BP_TEX_U32(destination, 0x24) = bpTexByteToFloatBits(color[1]);
    BP_TEX_U32(destination, 0x28) = bpTexByteToFloatBits(color[2]);
    BP_TEX_U32(destination, 0x2c) = bpTexByteToFloatBits(color[3]);
}

static void bpTexWriteVertex(void* destination,
                             f32 u,
                             f32 v,
                             const u8* color,
                             f32 depth,
                             f32 reciprocalDepth)
{
    BP_TEX_F32(destination, 0x10) = u;
    BP_TEX_F32(destination, 0x14) = v;
    BP_TEX_F32(destination, 0x18) = reciprocalDepth;
    BP_TEX_F32(destination, 0x08) = depth;
    bpTexWriteColor(destination, color);
}
#define BP_TEX_WRITE_COLOR_INLINE(destination, baseOffset, color) do { \
    f32 converted; \
    converted = (f32)(color)[0]; \
    BP_TEX_F32(destination, (baseOffset) + 0x20) = converted; \
    converted = (f32)(color)[1]; \
    BP_TEX_F32(destination, (baseOffset) + 0x24) = converted; \
    converted = (f32)(color)[2]; \
    BP_TEX_F32(destination, (baseOffset) + 0x28) = converted; \
    converted = (f32)(color)[3]; \
    BP_TEX_F32(destination, (baseOffset) + 0x2c) = converted; \
} while (0)
#define BP_TEX_WRITE_VERTEX_INLINE(destination, baseOffset, u, v, color, depth, reciprocalDepth) do { \
    BP_TEX_F32(destination, (baseOffset) + 0x10) = (u); \
    BP_TEX_F32(destination, (baseOffset) + 0x14) = (v); \
    BP_TEX_F32(destination, (baseOffset) + 0x18) = (reciprocalDepth); \
    BP_TEX_F32(destination, (baseOffset) + 0x08) = (depth); \
    BP_TEX_WRITE_COLOR_INLINE(destination, baseOffset, color); \
} while (0)
/* W357 measured bpTex0021c9f0: optimization_level 3 nd121/556B -> nd0/556B. */

extern u8* DAT_007ce308;
extern u8* DAT_007ce408;
#define BP_PANEL_GLOBAL DAT_007ce308
extern void* func_0021c3f0(s32 texture);
extern void* func_0021cca0(void* texture, s32 frame);
extern u32 func_0021cce0(void* frame);
extern void func_0021d3b0(void* destination, void* frame);
extern void func_0021d8e0(void* destination, const f32* rect);
extern void func_0021d890(void* destination, const f32* vertices);
extern void func_0021d950(void* destination, const u8* color);
extern u32 func_002d1a70(void);
extern void bcmPanel0022b580(void);
extern void func_0022b630(void);
extern void func_002265d0(void);
extern void func_00227f30(void);
extern void func_0022c2d0(void);
extern void func_00228e40(void);
extern void func_0022a2b0(void);
extern void func_00224940(void);
extern void func_00223290(void);
extern void func_002257f0(void);
extern void func_0022bcf0(void);
extern void func_00227800(void);
extern void func_0022c5a0(void);
extern void func_00229b40(void);
extern void func_0022ae80(void);
extern void func_00225040(void);
extern void func_00224150(void);
extern void func_002289b0(void);
extern void func_00226040(void);
extern void (*D_00960090)(u32, u32);
extern u8 D_00960090_abs[];
extern void (*D_0096009C)(u32*, u32, u32, u32, u32);
extern u8 D_0096009C_abs[];

static void bpTexSetUvAxis(f32 start,
                            f32 end,
                            s32 size,
                            u32 flip,
                            u32 mode,
                            f32* first,
                            f32* second)
{
    f32 extent;

    extent = (f32)size;
    if (mode == 2)
    {
        if ((flip & 1) != 0)
        {
            *first = (start + 1.0f) / extent;
            *second = start / extent;
        }
        else
        {
            *first = (end - 1.0f) / extent;
            *second = end / extent;
        }
    }
    else if (mode == 1)
    {
        if ((flip & 1) != 0)
        {
            *first = end / extent;
            *second = (end - 1.0f) / extent;
        }
        else
        {
            *first = start / extent;
            *second = (start + 1.0f) / extent;
        }
    }
    else if ((flip & 1) != 0)
    {
        *first = end / extent;
        *second = start / extent;
    }
    else
    {
        *first = start / extent;
        *second = end / extent;
    }
}
static u32* bpTexWork(void)
{
    u32* work;

    work = BP_TEX_GLOBAL;
    K_ASSERT(work != NULL, 0xbc);
    return work;
}
static inline u32* bpTexNodeNext(u32* node)
{
    return (u32*)node[0x3f1];
}
static u32* bpTexFindNode(u32 ordinal)
{
    u32* node;

    for (node = BP_TEX_PTR(bpTexWork(), 0x1265c);
         node != NULL;
         node = bpTexNodeNext(node))
    {
        if ((node[0] & 2) == 0 && node[4] == ordinal)
        {
            return node;
        }
    }

    K_ASSERT(false, 0x47a);
    return NULL;
}
static s32 bpTexNodeCount(void)
{
    s32 count;
    u32* node;

    count = 0;
    for (node = BP_TEX_PTR(bpTexWork(), 0x1265c);
         node != NULL;
         node = bpTexNodeNext(node))
    {
        if ((node[0] & 2) == 0)
        {
            count++;
        }
    }
    return count;
}
static inline void bpTexCollect(void* node, u32** values, s32* count)
{
    func_00256fa0(node, values, count);
}
static u32* bpTexActionRecord(void)
{
    u32* work;
    u32 index;

    work = bpTexWork();
    index = BP_TEX_U32(work, 0x127a8);
    return (u32*)((u8*)work + 0x12688 + index * 0x24);
}
static void bpTexQueueNodeAction(u32 type, u32* node, u32 duration)
{
    u32* work;
    u32* action;

    work = bpTexWork();
    action = bpTexActionRecord();
    action[0] = type;
    action[1] = duration;
    action[2] = (u32)node;
    action[3] = 0;
    BP_TEX_U32(work, 0x127a8)++;
}
static inline u8* bcm_panel_bytes(void)
{
    return (u8*)sBcmPanel;
}
static u32 bcm_panel_read(u32 offset)
{
    return *(u32*)(bcm_panel_bytes() + offset);
}
static void bcm_panel_write(u32 offset, u32 value)
{
    *(u32*)(bcm_panel_bytes() + offset) = value;
}
static u8* bcm_panel_record(u32 index)
{
    return bcm_panel_bytes() + 0x4660 + index * 0x420;
}
static u8* bcm_panel_overlay(u32 index)
{
    return bcm_panel_bytes() + 0x6080 + index * 0x110;
}
static inline void bcm_panel_set_resource(u8* dst, u32 resource, u32 id)
{
    u32 table;
    table = FUN_0021c3f0(resource);
    FUN_0021d3b0(dst, FUN_0021cca0(table, id));
}
static void bcm_panel_set_colour(u8* dst, u32 colour)
{
    *(u32*)(dst + 0x18c4) = colour;
    *(u32*)(dst + 0x18c8) = (colour ^ 0xffffffffu) & 0x00ffffffu;
    *(u32*)(dst + 0x18cc) = ((colour ^ 0xffffffffu) & 0x00ffffffu) | 0xff000000u;
}
static void bcm_panel_layout_record(u8* record, u32 row, u32 alpha)
{
    /* The four command quads are laid out on a 48-pixel baseline. */
    *(u32*)(record + 0x18d0) = 0x424c0000u + row * 48u;
    *(u32*)(record + 0x18d4) = 0x41980000u;
    *(u32*)(record + 0x18d8) = 0x432b0000u + row * 48u;
    *(u32*)(record + 0x18dc) = 0x41980000u;
    bcm_panel_set_colour(record, (alpha & 0xffu) | 0xffffff00u);
}
static void bcm_panel_refresh_records(void)
{
    u32 i;
    u32 count = bcm_panel_read(0x6070);
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        u32 state = *(u32*)record;
        if (state == 0 || state == 2) {
            bcm_panel_set_resource(record + 0x10, 0, 0x2f);
        } else if (state == 1) {
            bcm_panel_set_resource(record + 0x10, 0, 0x29);
            bcm_panel_set_resource(record + 0x110, 0, 0x29);
            bcm_panel_set_resource(record + 0x210, 0, 0x2a);
            bcm_panel_set_resource(record + 0x310, 0, 0x2a);
        }
    }
}
static inline s32 bpPanelFrameWidth(void* frame)
{
    return *(s32*)((u8*)frame + 0x0c);
}
static inline s32 bpPanelFrameHeight(void* frame)
{
    return *(s32*)((u8*)frame + 0x10);
}
static inline int bpPanelInTransition(u32 value)
{
    return value >= 1 && value <= 4;
}
static inline u8 bpPanelColor(f32 value)
{
    return (u8)value;
}
static inline void bpPanelSetRect(void* destination, f32 x, f32 y, void* frame)
{
    f32 rect[4];

    rect[0] = x;
    rect[1] = y;
    rect[2] = (f32)bpPanelFrameWidth(frame);
    rect[3] = (f32)bpPanelFrameHeight(frame);
    func_0021d8e0(destination, rect);
}
static inline void bpPanelSetColor(void* destination, u8 red, u8 green, u8 blue, f32 alpha)
{
    u8 color[4];

    color[0] = red;
    color[1] = green;
    color[2] = blue;
    color[3] = bpPanelColor(alpha);
    func_0021d950(destination, color);
}
static inline void bpPanelSetColorUnsigned(void* destination, u8* color,
                                           u8 red, u8 green, u8 blue, f32 alpha)
{

    color[0] = red;
    color[1] = green;
    color[2] = blue;
    color[3] = (u8)alpha;
    func_0021d950(destination, color);
}
static inline void bpPanelGetCenter(u8* work, u32 mode, u32 sub, f32 timer, f32* x, f32* y)
{
    if (sub != 0 && !bpPanelInTransition(sub))
    {
        K_ASSERT(false, 0x185);
        *x = 103.0f;
        *y = 361.0f;
    }
    else if (mode == 3)
    {
        if (sub == 0)
        {
            *x = 61.5f + 41.5f * timer / 3.0f;
            *y = 388.5f - 27.5f * timer / 3.0f;
        }
        else
        {
            *x = 103.0f - 41.5f * timer / 3.0f;
            *y = 361.0f + 27.5f * timer / 3.0f;
        }
    }
    else if (sub == 0)
    {
        *x = 103.0f;
        *y = 361.0f;
    }
    else
    {
        *x = 61.5f;
        *y = 388.5f;
    }
    (void)work;
}
static inline void bpPanelGetCommandPosition(u32 mode, u32 sub, f32 timer, f32* x, f32* y)
{
    if (mode == 3)
    {
        if (sub == 0)
        {
            *x = 82.0f - 68.0f * timer / 3.0f;
            *y = 369.0f - 23.0f * timer / 3.0f;
        }
        else if (bpPanelInTransition(sub))
        {
            *x = 14.0f + 68.0f * timer / 3.0f;
            *y = 346.0f + 23.0f * timer / 3.0f;
        }
        else
        {
            *x = 14.0f;
            *y = 346.0f;
        }
    }
    else if (sub == 0)
    {
        *x = 14.0f;
        *y = 346.0f;
    }
    else
    {
        *x = 82.0f;
        *y = 369.0f;
    }
}
static void bpPanelSetCenteredRect(void* destination, f32 x, f32 y, void* frame)
{
    f32 halfWidth;
    f32 halfHeight;

    halfWidth = (f32)(bpPanelFrameWidth(frame) / 2);
    halfHeight = (f32)(bpPanelFrameHeight(frame) / 2);
    bpPanelSetRect(destination, x - halfWidth, y - halfHeight, frame);
}
static inline void bpPanelSetRotatedQuad(void* destination,
                                  f32 centerX,
                                  f32 centerY,
                                  f32 left,
                                  f32 top,
                                  void* frame,
                                  f32 angle)
{
    f32 vertices[8];
    f32 width;
    f32 height;
    f32 sine;
    f32 cosine;
    f32 sourceX[4];
    f32 sourceY[4];
    s32 i;

    width = (f32)bpPanelFrameWidth(frame);
    height = (f32)bpPanelFrameHeight(frame);
    sourceX[0] = left;
    sourceY[0] = top;
    sourceX[1] = left + width;
    sourceY[1] = top;
    sourceX[2] = left + width;
    sourceY[2] = top + height;
    sourceX[3] = left;
    sourceY[3] = top + height;
    for (i = 0; i < 4; i += 2)
    {
        sine = func_0052e878(angle);
        cosine = func_0052e6d8(angle);
        vertices[i * 2] = centerX + (sourceX[i] - centerX) * cosine -
                          (sourceY[i] - centerY) * sine;
        vertices[i * 2 + 1] = centerY + (sourceX[i] - centerX) * sine +
                              (sourceY[i] - centerY) * cosine;
        sine = func_0052e878(angle);
        cosine = func_0052e6d8(angle);
        vertices[(i + 1) * 2] = centerX + (sourceX[i + 1] - centerX) * cosine -
                                (sourceY[i + 1] - centerY) * sine;
        vertices[(i + 1) * 2 + 1] =
            centerY + (sourceX[i + 1] - centerX) * sine +
            (sourceY[i + 1] - centerY) * cosine;
    }
    func_0021d890(destination, vertices);
}
static inline void bpPanelBindAndDraw(u8* work, u32 offset, void* frame)
{
    D_00960090(1, func_0021cce0(frame));
    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    D_0096009C((u32*)(work + offset), 4, 0, 1, 2);
    D_0096009C((u32*)(work + offset), 4, 0, 2, 3);
}
static void bpPanelDrawBridgeQuad(u8* work, u32 offset, void* texture, s32 frameId)
{
    void* frame;

    frame = func_0021cca0(texture, frameId);
    bpPanelBindAndDraw(work, offset, frame);
}

#pragma optimization_level 3
#pragma push
#pragma schedule off
/*
 * Retail orders the raster/frame pointer arithmetic differently from MWCCPS2.
 * The reconstructed allocation, raster loop, frame fields, and color loop are complete.
 */
// FUN_0021c9f0
void* bpTex0021c9f0(void* sprMemory)
{
    u8* source;
    u8* texture;
    u8* frameBase;
    u8* rasterTable;
    u8* frameTable;
    s32 i;
    u32 allocationSize;

    source = (u8*)sprMemory;
    allocationSize = 0;
    allocationSize += 0x14;
    allocationSize +=
        (u32)*(u16*)(source + 0x16) * sizeof(BpTexFrameData);
    allocationSize += (u32)*(u16*)(source + 0x14) * 4;
    texture = (u8*)(*(void* (**)(u32, u32))jtbl_00960178)(
        allocationSize, 0x40000);
    frameBase = texture + 0x14;
    BP_TEX_U32(texture, 4) = (u32)frameBase;
    BP_TEX_U32(texture, 8) =
        (u32)(frameBase +
              (u32)*(u16*)(source + 0x16) * sizeof(BpTexFrameData));
    BP_TEX_U32(texture, 0x10) = *(u16*)(source + 0x16);
    BP_TEX_U32(texture, 0x0c) = *(u16*)(source + 0x14);

    rasterTable = source + *(u32*)(source + 0x18);
    for (i = 0; i < *(u16*)(source + 0x14); i++)
    {
        u8* entry;
        void* raster;

        entry = rasterTable + i * 8;
        raster = bpTexCreateTmxRaster(source + *(u32*)(entry + 4));
        ((BpTexTexture*)texture)->rasters[i] = (u32)raster;
    }

    frameTable = source + *(u32*)(source + 0x1c);
    for (i = 0; i < *(u16*)(source + 0x16); i++)
    {
        u8* entry;
        BpTexFrameData* frame;
        u8* frameSource;
        u32 color;
        s32 j;

        entry = frameTable + i * 8;
        frameSource = source + *(u32*)(entry + 4);
        frame = (BpTexFrameData*)(*(u32*)(texture + 4)) + i;
        frame->texture = (u32)texture;
        frame->rasterIndex = *(u32*)(frameSource + 0x14);
        frame->id = *(u32*)(frameSource + 0x18);
        frame->width = *(s32*)(frameSource + 0x5c) -
                       *(s32*)(frameSource + 0x54);
        frame->height = *(s32*)(frameSource + 0x60) -
                        *(s32*)(frameSource + 0x58);
        frame->x = *(s32*)(frameSource + 0x54);
        frame->y = *(s32*)(frameSource + 0x58);
        j = 0;
        goto color_check;
color_body:
        color = *(u32*)(frameSource + 0x64 + j * 4);
        frame->color[j * 4 + 0] = (u8)(((color >> 24) * 0xff) >> 7);
        frame->color[j * 4 + 1] =
            (u8)((((color >> 16) & 0xff) * 0xff) >> 7);
        frame->color[j * 4 + 2] =
            (u8)((((color >> 8) & 0xff) * 0xff) >> 7);
        frame->color[j * 4 + 3] =
            (u8)(((color & 0xff) * 0xff) >> 7);
        j++;
color_check:
        if (j < 4)
            goto color_body;
    }

    return texture;
}
#pragma pop
#pragma optimization_level 2
#pragma opt_common_subs on


// FUN_0021cc20
void func_0021cc20(void* texture)
{
    s32 i;

    for (i = 0; i < BP_TEX_S32(texture, 0x0c); i++)
    {
        func_004cde90((void*)BP_TEX_PTR(texture, 8)[i]);
    }
    (*(void (**)(void*))jtbl_0096017C_abs)(texture);
}
// FUN_0021cca0
void* func_0021cca0(void* texture, s32 index)
{
    if (texture == NULL)
    {
        return NULL;
    }
    return (u8*)BP_TEX_PTR(texture, 4) + index * (s32)sizeof(BpTexFrameData);
}

// FUN_0021cce0
u32 func_0021cce0(void* frameData)
{
    u8* frame;
    u8* texture;
    u32* rasterList;

    frame = (u8*)frameData;
    texture = (u8*)(uintptr_t)BP_TEX_U32(frame, 0);
    rasterList = BP_TEX_PTR(texture, 8);
    return rasterList[BP_TEX_U32(frame, 8)];
}

// FUN_0021cd00
void func_0021cd00(void* frameData, f32* uv)
{
    BpTexFrameData* frame;
    u8* texture;
    u32* rasterList;
    u8* raster;

    frame = (BpTexFrameData*)frameData;
    texture = (u8*)(uintptr_t)frame->texture;
    rasterList = BP_TEX_PTR(texture, 8);
    raster = (u8*)(uintptr_t)rasterList[frame->rasterIndex];
    {
        f32 xRange[2] = {0};

        xRange[0] = (f32)frame->x;
        xRange[1] = (f32)(frame->x + frame->width);
        {
            f32 yRange[2] = {0};
            s32 rasterWidth;
            s32 rasterHeight;

            yRange[0] = (f32)frame->y;
            yRange[1] = (f32)(frame->y + frame->height);
            rasterWidth = *(s32*)(raster + 0x0c);
            rasterHeight = *(s32*)(raster + 0x10);

            if ((~frame->id & 1) != 0)
            {
                uv[0] = xRange[0] / (f32)rasterWidth;
                uv[2] = xRange[1] / (f32)rasterWidth;
            }
            else
            {
                uv[0] = xRange[1] / (f32)rasterWidth;
                uv[2] = xRange[0] / (f32)rasterWidth;
            }

            if ((~frame->id & 2) != 0)
            {
                uv[1] = yRange[0] / (f32)rasterHeight;
                uv[3] = yRange[1] / (f32)rasterHeight;
            }
            else
            {
                uv[1] = yRange[1] / (f32)rasterHeight;
                uv[3] = yRange[0] / (f32)rasterHeight;
            }
        }
    }
}


// FUN_0021cec0
void func_0021cec0(void* frameData, f32* uv, u32 mode)
{
    BpTexFrameData* frame;
    u8* texture;
    u32* rasterList;
    u8* raster;

    frame = (BpTexFrameData*)frameData;
    texture = (u8*)(uintptr_t)frame->texture;
    rasterList = BP_TEX_PTR(texture, 8);
    raster = (u8*)(uintptr_t)rasterList[frame->rasterIndex];
    {
        f32 xRange[2] = {0};

        xRange[0] = (f32)frame->x;
        xRange[1] = (f32)(frame->x + frame->width);
        {
            f32 yRange[2] = {0};
            s32 rasterWidth;
            s32 rasterHeight;
            u32 xMode;
            u32 yMode;

            yRange[0] = (f32)frame->y;
            yRange[1] = (f32)(frame->y + frame->height);
            rasterWidth = *(s32*)(raster + 0x0c);
            rasterHeight = *(s32*)(raster + 0x10);

            switch (mode)
            {
            case 0:
                xMode = 0;
                yMode = 1;
                break;
            case 1:
                xMode = 2;
                yMode = 0;
                break;
            case 2:
                xMode = 0;
                yMode = 2;
                break;
            case 3:
                xMode = 1;
                yMode = 0;
                break;
            case 4:
                xMode = 2;
                yMode = 1;
                break;
            case 5:
                xMode = 2;
                yMode = 2;
                break;
            case 6:
                xMode = 2;
                yMode = 1;
                break;
            case 7:
                xMode = 1;
                yMode = 1;
                break;
            }

            switch (xMode)
            {
            case 0:
                if ((~frame->id & 1) != 0)
                {
                    uv[0] = xRange[0] / (f32)rasterWidth;
                    uv[2] = xRange[1] / (f32)rasterWidth;
                }
                else
                {
                    uv[0] = xRange[1] / (f32)rasterWidth;
                    uv[2] = xRange[0] / (f32)rasterWidth;
                }
                break;
            case 1:
                if ((~frame->id & 1) != 0)
                {
                    uv[0] = xRange[0] / (f32)rasterWidth;
                    uv[2] = (xRange[0] + 1.0f) / (f32)rasterWidth;
                }
                else
                {
                    uv[0] = xRange[1] / (f32)rasterWidth;
                    uv[2] = (xRange[1] - 1.0f) / (f32)rasterWidth;
                }
                break;
            case 2:
                if ((~frame->id & 1) != 0)
                {
                    uv[0] = (xRange[1] - 1.0f) / (f32)rasterWidth;
                    uv[2] = xRange[1] / (f32)rasterWidth;
                }
                else
                {
                    uv[0] = (xRange[0] + 1.0f) / (f32)rasterWidth;
                    uv[2] = xRange[0] / (f32)rasterWidth;
                }
                break;
            }

            switch (yMode)
            {
            case 0:
                if ((~frame->id & 2) != 0)
                {
                    uv[1] = yRange[0] / (f32)rasterHeight;
                    uv[3] = yRange[1] / (f32)rasterHeight;
                }
                else
                {
                    uv[1] = yRange[1] / (f32)rasterHeight;
                    uv[3] = yRange[0] / (f32)rasterHeight;
                }
                break;
            case 1:
                if ((~frame->id & 2) != 0)
                {
                    uv[1] = yRange[0] / (f32)rasterHeight;
                    uv[3] = (yRange[0] + 1.0f) / (f32)rasterHeight;
                }
                else
                {
                    uv[1] = yRange[1] / (f32)rasterHeight;
                    uv[3] = (yRange[1] - 1.0f) / (f32)rasterHeight;
                }
                break;
            case 2:
                if ((~frame->id & 2) != 0)
                {
                    uv[1] = (yRange[1] - 1.0f) / (f32)rasterHeight;
                    uv[3] = yRange[1] / (f32)rasterHeight;
                }
                else
                {
                    uv[1] = (yRange[0] + 1.0f) / (f32)rasterHeight;
                    uv[3] = yRange[0] / (f32)rasterHeight;
                }
                break;
            }
        }
    }
}

// FUN_0021d3b0
void func_0021d3b0(void* destination, void* frameData)
{
    BpTexFrameData* frame;
    RwCamera* camera;
    f32 uv[4];
    f32 reciprocalDepth;
    u32 depthAddress;

    frame = (BpTexFrameData*)frameData;
    camera = kwlnGetMainCamera();
    reciprocalDepth = 1.0f / *(f32*)((u8*)camera + 0x80);
    func_0021cd00(frame, uv);
    BP_TEX_F32(destination, 0x10) = uv[0];
    BP_TEX_F32(destination, 0x14) = uv[1];
    BP_TEX_F32(destination, 0x18) = reciprocalDepth;
    depthAddress = (u32)D_00960088_abs;
    BP_TEX_F32(destination, 0x08) = *(f32*)depthAddress;
    BP_TEX_WRITE_COLOR_INLINE(destination, 0, frame->color);
    BP_TEX_WRITE_VERTEX_INLINE(destination, 0x40, uv[2], uv[1], frame->color + 4,
                               *(f32*)depthAddress, reciprocalDepth);
    BP_TEX_WRITE_VERTEX_INLINE(destination, 0x80, uv[2], uv[3], frame->color + 8,
                               *(f32*)depthAddress, reciprocalDepth);
    BP_TEX_WRITE_VERTEX_INLINE(destination, 0xc0, uv[0], uv[3], frame->color + 12,
                               *(f32*)depthAddress, reciprocalDepth);
}

// FUN_0021d890
void func_0021d890(void* destination, const f32* vertices)
{
    BP_TEX_F32(destination, 0) = vertices[0];
    BP_TEX_F32(destination, 4) = vertices[1];
    BP_TEX_F32(destination, 0x40) = vertices[2];
    BP_TEX_F32(destination, 0x44) = vertices[3];
    BP_TEX_F32(destination, 0x80) = vertices[4];
    BP_TEX_F32(destination, 0x84) = vertices[5];
    BP_TEX_F32(destination, 0xc0) = vertices[6];
    BP_TEX_F32(destination, 0xc4) = vertices[7];
}

// FUN_0021d8e0
void func_0021d8e0(void* destination, const f32* rect)
{
    BP_TEX_F32(destination, 0) = rect[0];
    BP_TEX_F32(destination, 4) = rect[1];
    BP_TEX_F32(destination, 0x40) = rect[0] + rect[2];
    BP_TEX_F32(destination, 0x44) = rect[1];
    BP_TEX_F32(destination, 0x80) = rect[0] + rect[2];
    BP_TEX_F32(destination, 0x84) = rect[1] + rect[3];
    BP_TEX_F32(destination, 0xc0) = rect[0];
    BP_TEX_F32(destination, 0xc4) = rect[1] + rect[3];
}

// FUN_0021d950
void func_0021d950(void* destination, const u8* color)
{
    f32 converted;

    converted = (f32)color[0];
    BP_TEX_F32(destination, 0x20) = converted;
    converted = (f32)color[1];
    BP_TEX_F32(destination, 0x24) = converted;
    converted = (f32)color[2];
    BP_TEX_F32(destination, 0x28) = converted;
    converted = (f32)color[3];
    BP_TEX_F32(destination, 0x2c) = converted;

    converted = (f32)color[0];
    BP_TEX_F32(destination, 0x60) = converted;
    converted = (f32)color[1];
    BP_TEX_F32(destination, 0x64) = converted;
    converted = (f32)color[2];
    BP_TEX_F32(destination, 0x68) = converted;
    converted = (f32)color[3];
    BP_TEX_F32(destination, 0x6c) = converted;

    converted = (f32)color[0];
    BP_TEX_F32(destination, 0xa0) = converted;
    converted = (f32)color[1];
    BP_TEX_F32(destination, 0xa4) = converted;
    converted = (f32)color[2];
    BP_TEX_F32(destination, 0xa8) = converted;
    converted = (f32)color[3];
    BP_TEX_F32(destination, 0xac) = converted;

    converted = (f32)color[0];
    BP_TEX_F32(destination, 0xe0) = converted;
    converted = (f32)color[1];
    BP_TEX_F32(destination, 0xe4) = converted;
    converted = (f32)color[2];
    BP_TEX_F32(destination, 0xe8) = converted;
    converted = (f32)color[3];
    BP_TEX_F32(destination, 0xec) = converted;
}

// FUN_0021dd60
void func_0021dd60(void* destination, const u8* colors)
{
    f32 converted;

    converted = (f32)colors[0];
    BP_TEX_F32(destination, 0x20) = converted;
    converted = (f32)colors[1];
    BP_TEX_F32(destination, 0x24) = converted;
    converted = (f32)colors[2];
    BP_TEX_F32(destination, 0x28) = converted;
    converted = (f32)colors[3];
    BP_TEX_F32(destination, 0x2c) = converted;

    converted = (f32)colors[4];
    BP_TEX_F32(destination, 0x60) = converted;
    converted = (f32)colors[5];
    BP_TEX_F32(destination, 0x64) = converted;
    converted = (f32)colors[6];
    BP_TEX_F32(destination, 0x68) = converted;
    converted = (f32)colors[7];
    BP_TEX_F32(destination, 0x6c) = converted;

    converted = (f32)colors[8];
    BP_TEX_F32(destination, 0xa0) = converted;
    converted = (f32)colors[9];
    BP_TEX_F32(destination, 0xa4) = converted;
    converted = (f32)colors[10];
    BP_TEX_F32(destination, 0xa8) = converted;
    converted = (f32)colors[11];
    BP_TEX_F32(destination, 0xac) = converted;

    converted = (f32)colors[12];
    BP_TEX_F32(destination, 0xe0) = converted;
    converted = (f32)colors[13];
    BP_TEX_F32(destination, 0xe4) = converted;
    converted = (f32)colors[14];
    BP_TEX_F32(destination, 0xe8) = converted;
    converted = (f32)colors[15];
    BP_TEX_F32(destination, 0xec) = converted;
}

// FUN_0021e170
void func_0021e170(void* destination,
                   const f32* center,
                   const f32* direction,
                   const f32* size)
{
    f32 sourcePoints[4][2];
    f32* nextPoint;
    f32* point;
    f32 length;
    f32 angle;
    f32 sine;
    f32 cosine;
    f32 y;
    f32 x;
    f32 rotatedX;
    f32 rotatedY;
    f32 cx;
    f32 cy;
    s32 i;
    s32 j;

    length = sqrtf(direction[0] * direction[0] +
                   direction[1] * direction[1]);
    angle = func_0052ea18(direction[0] / length,
                          -(direction[1] / length));
    sourcePoints[0][0] = -size[0] / 2.0f;
    sourcePoints[0][1] = -size[1] / 2.0f;
    sourcePoints[1][0] = size[0] / 2.0f;
    sourcePoints[1][1] = sourcePoints[0][1];
    sourcePoints[2][0] = sourcePoints[1][0];
    sourcePoints[2][1] = size[1] / 2.0f;
    sourcePoints[3][0] = sourcePoints[0][0];
    sourcePoints[3][1] = sourcePoints[2][1];
    for (i = 0; i < 4; i++)
    {
        point = sourcePoints[i];
        nextPoint = point + 1;
        y = *nextPoint;
        x = *point;
        sine = func_0052e878(angle);
        cosine = func_0052e6d8(angle);
        rotatedX = x * cosine - y * sine;
        sine = func_0052e878(angle);
        cosine = func_0052e6d8(angle);
        rotatedY = x * sine + y * cosine;
        nextPoint[0] = (point[0] = rotatedX, rotatedY);
    }
    j = 0;
    cx = center[0];
    cy = center[1];
    while (j < 4)
    {
        point = sourcePoints[j];
        point[0] += cx;
        point[1] += cy;
        j++;
    }
    BP_TEX_F32(destination, 0x00) = sourcePoints[0][0];
    BP_TEX_F32(destination, 0x04) = sourcePoints[0][1];
    BP_TEX_F32(destination, 0x40) = sourcePoints[1][0];
    BP_TEX_F32(destination, 0x44) = sourcePoints[1][1];
    BP_TEX_F32(destination, 0x80) = sourcePoints[2][0];
    BP_TEX_F32(destination, 0x84) = sourcePoints[2][1];
    BP_TEX_F32(destination, 0xc0) = sourcePoints[3][0];
    BP_TEX_F32(destination, 0xc4) = sourcePoints[3][1];
}

// FUN_0021e380
void func_0021e380(void* destination, void* frameData, u32 mode)
{
    BpTexFrameData* frame;
    RwCamera* camera;
    const u8* firstColor;
    const u8* secondColor;
    const u8* thirdColor;
    const u8* fourthColor;
    f32 uv[4];
    f32 reciprocalDepth;
    u32 depthAddress;

    camera = kwlnGetMainCamera();
    frame = (BpTexFrameData*)frameData;
    reciprocalDepth = 1.0f / *(f32*)((u8*)camera + 0x80);
    switch (mode)
    {
        case 0:
            func_0021cec0(frame, uv, 0);
            firstColor = frame->color;
            secondColor = frame->color + 4;
            thirdColor = frame->color + 4;
            fourthColor = frame->color;
            break;
        case 1:
            func_0021cec0(frame, uv, 1);
            firstColor = frame->color + 4;
            secondColor = frame->color + 4;
            thirdColor = frame->color + 8;
            fourthColor = frame->color + 8;
            break;
        case 2:
            func_0021cec0(frame, uv, 2);
            firstColor = frame->color + 12;
            secondColor = frame->color + 8;
            thirdColor = frame->color + 8;
            fourthColor = frame->color + 12;
            break;
        case 3:
            func_0021cec0(frame, uv, 3);
            firstColor = frame->color;
            secondColor = frame->color;
            thirdColor = frame->color + 12;
            fourthColor = frame->color + 12;
            break;
        case 4:
            func_0021cec0(frame, uv, 4);
            firstColor = frame->color + 4;
            secondColor = frame->color + 4;
            thirdColor = frame->color + 4;
            fourthColor = frame->color + 4;
            break;
        case 5:
            func_0021cec0(frame, uv, 5);
            firstColor = frame->color + 8;
            secondColor = frame->color + 8;
            thirdColor = frame->color + 8;
            fourthColor = frame->color + 8;
            break;
        case 6:
            func_0021cec0(frame, uv, 6);
            firstColor = frame->color + 12;
            secondColor = frame->color + 12;
            thirdColor = frame->color + 12;
            fourthColor = frame->color + 12;
            break;
        case 7:
            func_0021cec0(frame, uv, 7);
            firstColor = frame->color;
            secondColor = frame->color;
            thirdColor = frame->color;
            fourthColor = frame->color;
            break;
    }
    BP_TEX_F32(destination, 0x10) = uv[0];
    BP_TEX_F32(destination, 0x14) = uv[1];
    BP_TEX_F32(destination, 0x18) = reciprocalDepth;
    depthAddress = (u32)D_00960088_abs;
    BP_TEX_F32(destination, 0x08) = *(f32*)depthAddress;
    BP_TEX_WRITE_COLOR_INLINE(destination, 0, firstColor);
    BP_TEX_WRITE_VERTEX_INLINE(destination, 0x40, uv[2], uv[1], secondColor,
                               *(f32*)depthAddress, reciprocalDepth);
    BP_TEX_WRITE_VERTEX_INLINE(destination, 0x80, uv[2], uv[3], thirdColor,
                               *(f32*)depthAddress, reciprocalDepth);
    BP_TEX_WRITE_VERTEX_INLINE(destination, 0xc0, uv[0], uv[3], fourthColor,
                               *(f32*)depthAddress, reciprocalDepth);
}

// FUN_0021ea00
f32 func_0021ea00(s32 duration)
{
    RwCamera* camera;
    f32 nearPlane;
    f32 maxDepth;
    f32 farPlane;
    f32 value;
    u32 unsignedDuration;

    camera = kwlnGetMainCamera();
    nearPlane = *(f32*)((u8*)camera + 0x80);
    camera = kwlnGetMainCamera();
    farPlane = *(f32*)((u8*)camera + 0x84);
    unsignedDuration = (u32)duration;
    maxDepth = 65535.0f;
    value = (f32)unsignedDuration;
    return ((-maxDepth * nearPlane) * farPlane) /
           ((-maxDepth * farPlane) -
            (value - maxDepth) * (farPlane - nearPlane));
}

// FUN_0021eac0
void func_0021eac0(void* destination, f32 value)
{
    BP_TEX_F32(destination, 8) = value;
    BP_TEX_F32(destination, 0x48) = value;
    BP_TEX_F32(destination, 0x88) = value;
    BP_TEX_F32(destination, 0xc8) = value;
}

// FUN_0021eae0
void func_0021eae0(void* destination, const f32* rect)
{
    RwCamera* camera;
    f32 reciprocalDepth;

    camera = kwlnGetMainCamera();
    reciprocalDepth = 1.0f / *(f32*)((u8*)camera + 0x80);
    BP_TEX_F32(destination, 0x10) = rect[0];
    BP_TEX_F32(destination, 0x14) = rect[1];
    BP_TEX_F32(destination, 0x18) = reciprocalDepth;
    BP_TEX_F32(destination, 0x50) = rect[2];
    BP_TEX_F32(destination, 0x54) = rect[1];
    BP_TEX_F32(destination, 0x58) = reciprocalDepth;
    BP_TEX_F32(destination, 0x90) = rect[2];
    BP_TEX_F32(destination, 0x94) = rect[3];
    BP_TEX_F32(destination, 0x98) = reciprocalDepth;
    BP_TEX_F32(destination, 0xd0) = rect[0];
    BP_TEX_F32(destination, 0xd4) = rect[3];
    BP_TEX_F32(destination, 0xd8) = reciprocalDepth;
}

// FUN_0021eb80
void func_0021eb80(void* destination, const f32* rect)
{
    RwCamera* camera;
    f32 reciprocalDepth;

    camera = kwlnGetMainCamera();
    reciprocalDepth = 1.0f / *(f32*)((u8*)camera + 0x80);
    BP_TEX_F32(destination, 0x10) = rect[0];
    BP_TEX_F32(destination, 0x14) = rect[1];
    BP_TEX_F32(destination, 0x18) = reciprocalDepth;
    BP_TEX_F32(destination, 0x50) = rect[0] + rect[2];
    BP_TEX_F32(destination, 0x54) = rect[1];
    BP_TEX_F32(destination, 0x58) = reciprocalDepth;
    BP_TEX_F32(destination, 0x90) = rect[0] + rect[2];
    BP_TEX_F32(destination, 0x94) = rect[1] + rect[3];
    BP_TEX_F32(destination, 0x98) = reciprocalDepth;
    BP_TEX_F32(destination, 0xd0) = rect[0];
    BP_TEX_F32(destination, 0xd4) = rect[1] + rect[3];
    BP_TEX_F32(destination, 0xd8) = reciprocalDepth;
}


/* Retail 0x0021ec40-0x0021f080: TMX format selection, palette upload, and
 * format-specific row-major pixel copies. */
/* W310 measured: opt_common_subs off nd599->583, object 1140/1152; reset nd599. */
#pragma opt_common_subs off
// FUN_0021ec40 NONMATCHING
RwRaster* bpTexCreateTmxRaster(void* tmxMemory)
{
    RwRaster* raster;
    u8* source;
    u8* pixelSource;
    u8* paletteSource;
    u8* destination;
    u32 depth;
    u32 paletteFlag;
    u32 flags;
    s32 paletteRow;
    s32 paletteRow4;
    s32 pixelRow32;
    s32 pixelColumn32;
    s32 pixelRow24;
    s32 pixelColumn24;
    s32 pixelRow8;
    s32 pixelColumn8;
    s32 pixelRow4;
    s32 pixelColumn4;
    u8 format;

    source = (u8*)tmxMemory;
    pixelSource = source;
    paletteSource = 0;
    depth = 0;
    paletteFlag = 0;
    format = source[0x16];
    switch (format)
    {
    case 0:
        depth = 0x20;
        break;
    case 1:
        depth = 0x18;
        break;
    case 2:
    case 0x0a:
        depth = 0x10;
        break;
    case 0x13:
    case 0x1b:
        depth = 8;
        break;
    case 0x14:
    case 0x24:
    case 0x2c:
        depth = 4;
        break;
    }

    if (depth == 0)
    {
        K_ASSERT(false, 0x65);
    }

    pixelSource = (u8*)tmxMemory + 0x40;
    switch (depth)
    {
    case 8:
        paletteSource = pixelSource;
        pixelSource += (u32)source[0x10] << 10;
        paletteFlag = 1;
        break;
    case 4:
        paletteSource = pixelSource;
        pixelSource += (u32)source[0x10] << 6;
        paletteFlag = 1;
        break;
    }

    flags = 4;
    switch (depth)
    {
    case 0x20:
        flags |= 0x500;
        break;
    case 0x18:
        flags |= 0x600;
        break;
    case 8:
        flags |= 0x2500;
        break;
    case 4:
        flags |= 0x4500;
        break;
    default:
        K_ASSERT(false, 0x8d);
        break;
    }

    raster = func_004ce0f0(*(u16*)(source + 0x12),
                           *(u16*)(source + 0x14),
                           depth,
                           flags);
    if ((paletteFlag & 1) != 0)
    {
        destination = (u8*)func_004cdf30(raster, 1);
        switch (depth)
        {
        case 8:
            paletteRow = 0;
            while (paletteRow < 0x100)
            {
                *(u32*)destination = *(u32*)paletteSource;
                paletteSource += 4;
                destination += 4;
                paletteRow++;
            }
            break;
        case 4:
            paletteRow4 = 0;
            while (paletteRow4 < 0x10)
            {
                *(u32*)destination = *(u32*)paletteSource;
                paletteSource += 4;
                destination += 4;
                paletteRow4++;
            }
            break;
        }
        func_004cde40(raster);
    }

    destination = (u8*)func_004ce200(raster, NULL, 1);
    switch (depth)
    {
    case 0x20:
        pixelRow32 = 0;
        while (pixelRow32 < (s32)*(u16*)(source + 0x14))
        {
            pixelColumn32 = 0;
            while (pixelColumn32 < (s32)*(u16*)(source + 0x12))
            {
                *(u32*)destination = *(u32*)pixelSource;
                pixelSource += 4;
                destination += 4;
                pixelColumn32++;
            }
            pixelRow32++;
        }
        break;
    case 0x18:
        pixelRow24 = 0;
        while (pixelRow24 < (s32)*(u16*)(source + 0x14))
        {
            pixelColumn24 = 0;
            while (pixelColumn24 < (s32)*(u16*)(source + 0x12) * 3)
            {
                *destination = *pixelSource;
                pixelSource++;
                destination++;
                pixelColumn24++;
            }
            pixelRow24++;
        }
        break;
    case 8:
        pixelRow8 = 0;
        while (pixelRow8 < (s32)*(u16*)(source + 0x14))
        {
            pixelColumn8 = 0;
            while (pixelColumn8 < (s32)*(u16*)(source + 0x12))
            {
                *destination = *pixelSource;
                pixelSource++;
                destination++;
                pixelColumn8++;
            }
            pixelRow8++;
        }
        break;
    case 4:
        pixelRow4 = 0;
        while (pixelRow4 < ((s32)*(u16*)(source + 0x12) >> 3))
        {
            pixelColumn4 = 0;
            while (pixelColumn4 < (s32)*(u16*)(source + 0x14))
            {
                *(u32*)destination = *(u32*)pixelSource;
                pixelSource += 4;
                destination += 4;
                pixelColumn4++;
            }
            pixelRow4++;
        }
        break;
    default:
        break;
    }

    func_004cde00(raster);
    return raster;
}
#pragma opt_common_subs on







// FUN_0021f0c0
void func_0021f0c0(void* work)
{
    u32* words;
    s32 i;

    K_ASSERT(BP_PANEL_GLOBAL == NULL, 0xee);
    words = (u32*)work;
    words[0] = 0;
    words[1] = 0;
    for (i = 0; i < 7; i++)
    {
        *(u32*)((u8*)work + 0x1210 + i * 4) = 0;
    }
    BP_PANEL_GLOBAL = (u8*)work;
}

// FUN_0021F140
void func_0021f140(void)
{
    DAT_007ce408 = NULL;
}



// FUN_0021f150
void func_0021f150(u32 selection)
{
    u8* work;
    void* texture;
    void* frame;
    u32* words;
    s32 i;

    K_ASSERT(BP_PANEL_GLOBAL != NULL, 0xe6);
    work = BP_PANEL_GLOBAL;
    words = (u32*)work;
    texture = func_0021c3f0(0);
    K_ASSERT((~words[0]) & 1, 0x103);
    words[0] &= ~0x10;
    if (func_002d1a70() == 0)
    {
        words[0] |= 0x10;
    }
    frame = func_0021cca0(texture, 0x10);
    func_0021d3b0(work + 0x10, frame);
    frame = func_0021cca0(texture, 0x1b);
    func_0021d3b0(work + 0x110, frame);
    frame = func_0021cca0(texture, 0x1c);
    func_0021d3b0(work + 0x210, frame);
    frame = func_0021cca0(texture, 0x22);
    func_0021d3b0(work + 0x1430, frame);
    frame = func_0021cca0(texture, 0x0e);
    func_0021d3b0(work + 0x310, frame);
    frame = func_0021cca0(texture, (s32)selection);
    func_0021d3b0(work + 0x1230, frame);
    for (i = 0; i < 7; i++)
    {
        if (*(u32*)(work + 0x1210 + i * 4) & 1)
        {
            frame = func_0021cca0(texture, 0x11);
        }
        else
        {
            frame = func_0021cca0(texture, 0x41);
        }
        func_0021d3b0(work + 0x410 + i * 0x100, frame);
    }
    for (i = 0; i < 7; i++)
    {
        frame = func_0021cca0(texture, i + 0x14);
        func_0021d3b0(work + 0xb10 + i * 0x100, frame);
    }
    bcmPanel0022b580();
    *(u32*)(work + 0x4634) = selection;
    *(u32*)(work + 0x4638) = 0xffffffff;
    *(u32*)(work + 0x463c) = 0;
    *(u32*)(work + 0x4640) = 0xffffffff;
    *(u32*)(work + 0x4630) = 0;
    words[0] |= 1;
}

// FUN_0021f3c0
void func_0021f3c0(void)
{
    u32* words;

    K_ASSERT(BP_PANEL_GLOBAL != NULL, 0xe6);
    words = (u32*)BP_PANEL_GLOBAL;
    words[0] &= ~1;
}

/* W419 prologue diagnosis: ours frame 0x1f0/496B saves s0-s7 and f20-f27;
 * retail frame 0xd0/208B saves s0-s4 and f20-f31. Whole-body
 * reconstruction; scoped-temporary probe stayed nd7333/10000B, window
 * 10064B, rate 0.733300 (no code change). */
// FUN_0021f410 NONMATCHING
void func_0021f410(void)
{
    u8* work;
    u8 color[4];
    void* texture;
    void* frame;
    u32 mode;
    u32 sub;
    u32 previous;
    s32 timerA;
    s32 timerB;
    s32 timerC;
    f32 dt;
    f32 centerX;
    f32 centerY;
    f32 commandX;
    f32 commandY;
    f32 alpha;
    f32 factor;
    f32 angle;
    f32 phase;
    f32 arcX;
    f32 arcY;
    f32 arrowFactor;
    f32 slotFactor;
    f32 baseX;
    f32 baseY;
    f32 pi;
    u32 flags;
    s32 i;

    K_ASSERT(BP_PANEL_GLOBAL != NULL, 0xe6);
    work = BP_PANEL_GLOBAL;
    texture = func_0021c3f0(0);
    K_ASSERT((*(u32*)work & 1) != 0, 0x151);
    dt = *(f32*)(work + 0x7214);
    func_0022b630();

    mode = *(u32*)(work + 0x4630);
    timerA = *(u32*)(work + 0x464c);
    timerB = *(u32*)(work + 0x4650);
    timerC = *(u32*)(work + 0x4658);
    switch (mode)
    {
    case 0:
    case 6:
    case 7:
        break;
    case 1:
    case 2:
    case 8:
        if (timerA < 4)
        {
            timerA++;
            *(u32*)(work + 0x464c) = timerA;
        }
        break;
    case 3:
        if (timerB < 3)
        {
            timerB++;
            *(u32*)(work + 0x4650) = timerB;
            if (timerB == 3)
            {
                *(u32*)work &= ~2;
            }
        }
        break;
    case 4:
    case 5:
        if (timerC < 6)
        {
            timerC++;
            *(u32*)(work + 0x4658) = timerC;
            if (timerC == 6)
            {
                *(u32*)work &= ~8;
            }
        }
        break;
    }

    mode = *(u32*)(work + 0x4630);
    sub = *(u32*)(work + 0x463c);
    timerB = *(u32*)(work + 0x4650);
    bpPanelGetCenter(work, mode, sub, (f32)timerB, &centerX, &centerY);
    baseX = centerX + 57.0f;
    baseY = centerY;

    frame = func_0021cca0(texture, 0x10);
    bpPanelSetRect(work + 0x10, centerX - 62.5f, centerY - 62.5f, frame);
    bpPanelSetColorUnsigned(work + 0x10, color, 0xff, 0xff, 0xff, 255.0f * dt);

    bpPanelGetCommandPosition(mode, sub, (f32)timerB, &commandX, &commandY);
    frame = func_0021cca0(texture, (s32)*(u32*)(work + 0x4634));
    bpPanelSetRect(work + 0x1230, commandX, commandY, frame);
    if ((mode == 1 || mode == 2 || mode == 8) && *(u32*)(work + 0x464c) == 4)
    {
        /* The old image is intentionally left untouched at the end of a fade. */
    }
    else if (mode == 1 || mode == 2 || mode == 8)
    {
        frame = func_0021cca0(texture, (s32)*(u32*)(work + 0x4638));
        bpPanelSetRect(work + 0x1330, commandX, commandY, frame);
    }
    else
    {
        frame = func_0021cca0(texture, (s32)*(u32*)(work + 0x4634));
        bpPanelSetRect(work + 0x1330, commandX, commandY, frame);
    }

    if (mode == 3)
    {
        switch (sub)
        {
        case 0:
            factor = (f32)timerB / 3.0f;
            alpha = (3.0f - (f32)timerB) / 3.0f;
            bpPanelSetColorUnsigned(work + 0x1230, color, 0xff, 0xff, 0xff, 255.0f * factor * dt);
            bpPanelSetColorUnsigned(work + 0x1330, color, 0xff, 0xff, 0xff, 255.0f * alpha * dt);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            factor = (3.0f - (f32)timerB) / 3.0f;
            alpha = (f32)timerB / 3.0f;
            bpPanelSetColorUnsigned(work + 0x1230, color, 0xff, 0xff, 0xff, 255.0f * factor * dt);
            bpPanelSetColorUnsigned(work + 0x1330, color, 0xff, 0xff, 0xff, 255.0f * alpha * dt);
            break;
        default:
            break;
        }
    }
    else if (mode == 1 || mode == 2 || mode == 8)
    {
        u32 selectedFlag;

        timerA = *(u32*)(work + 0x464c);
        selectedFlag = *(u32*)(work + 0x1210 + *(u32*)(work + 0x4634) * 4);
        factor = (f32)timerA / 4.0f;
        if ((selectedFlag & 1) == 0)
        {
            factor *= 0.5f;
        }
        bpPanelSetColorUnsigned(work + 0x1230, color, 0xff, 0xff, 0xff, 255.0f * factor * dt);
        bpPanelSetColorUnsigned(work + 0x1330, color, 0xff, 0xff, 0xff, 255.0f * (4.0f - (f32)timerA) / 4.0f * dt);
    }
    else if (sub == 0)
    {
        bpPanelSetColorUnsigned(work + 0x1230, color, 0xff, 0xff, 0xff, 255.0f * dt);
        alpha = 0.0f;
        bpPanelSetColorUnsigned(work + 0x1330, color, 0xff, 0xff, 0xff, alpha * dt);
    }
    else if (bpPanelInTransition(sub))
    {
        alpha = 0.0f;
        bpPanelSetColorUnsigned(work + 0x1230, color, 0xff, 0xff, 0xff, alpha * dt);
        bpPanelSetColorUnsigned(work + 0x1330, color, 0xff, 0xff, 0xff, 255.0f * dt);
    }

    frame = func_0021cca0(texture, 0x1b);
    if (mode == 3 && bpPanelInTransition(sub))
    {
        angle = (f32)timerB * 0.785398185f / 4.0f;
    }
    else if (mode == 3 && sub == 0)
    {
        angle = (3.0f - (f32)timerB) * 0.785398185f / 4.0f;
    }
    else if (bpPanelInTransition(sub))
    {
        angle = 0.785398185f;
    }
    else
    {
        angle = 0.0f;
    }
    bpPanelSetRotatedQuad(work + 0x110, centerX, centerY, centerX - 91.5f, centerY - 90.5f, frame, angle);
    bpPanelSetColorUnsigned(work + 0x110, color, 0xff, 0xff, 0xff, 255.0f * dt);

    frame = func_0021cca0(texture, 0x1c);
    bpPanelSetRotatedQuad(work + 0x210, centerX, centerY, centerX - 79.5f, centerY - 85.5f, frame, angle);
    if (mode == 3 && sub == 0)
    {
        factor = (f32)timerB / 3.0f;
    }
    else if (mode == 3 && bpPanelInTransition(sub))
    {
        factor = (3.0f - (f32)timerB) / 3.0f;
    }
    else if (sub == 0)
    {
        factor = 1.0f;
    }
    else
    {
        factor = 0.0f;
    }
    bpPanelSetColorUnsigned(work + 0x210, color, 0xff, 0xff, 0xff, 255.0f * factor * dt);

    frame = func_0021cca0(texture, 0x22);
    if (mode == 3 && bpPanelInTransition(sub))
    {
        angle = -0.1256637126f - 1.57079637f * (f32)timerB / 4.0f;
    }
    else if (mode == 3 && sub == 0)
    {
        angle = -0.1256637126f - 1.57079637f * (3.0f - (f32)timerB) / 4.0f;
    }
    else
    {
        angle = -0.1256637126f;
    }
    bpPanelSetRotatedQuad(work + 0x1430, centerX, centerY, centerX - 50.5f, centerY - 30.5f, frame, angle);
    if (mode == 3 && sub == 0)
    {
        factor = (3.0f - (f32)timerB) / 3.0f;
    }
    else if (mode == 3 && bpPanelInTransition(sub))
    {
        factor = (f32)timerB / 3.0f;
    }
    else if (sub == 0)
    {
        factor = 0.0f;
    }
    else
    {
        factor = 1.0f;
    }
    bpPanelSetColorUnsigned(work + 0x1430, color, 0xff, 0xff, 0xff, 255.0f * factor * dt);

    pi = 3.1415927f;
    arrowFactor = factor;
    *(f32*)(work + 0x7210) = -57.0f;
    for (i = 0; i < 7; i++)
    {
        s32 selected;
        f32 halfWidth;
        f32 halfHeight;
        u32 slotFlags;

        if (mode == 1)
        {
            phase = (1.0f + (f32)i - (f32)*(u32*)(work + 0x4634) -
                     (f32)*(u32*)(work + 0x464c) / 4.0f) / 7.0f;
        }
        else if (mode == 2)
        {
            phase = ((f32)*(u32*)(work + 0x464c) / 4.0f + (f32)i -
                     (f32)*(u32*)(work + 0x4634) - 1.0f) / 7.0f;
        }
        else
        {
            phase = ((f32)i - (f32)*(u32*)(work + 0x4634)) / 7.0f;
        }
        angle = 2.0f * pi * phase;
        arcX = -57.0f * func_0052e6d8(angle);
        arcY = -57.0f * func_0052e878(angle);
        slotFlags = *(u32*)(work + 0x1210 + i * 4);
        if ((slotFlags & 1) != 0)
        {
            frame = func_0021cca0(texture, i + 0x11);
        }
        else
        {
            frame = func_0021cca0(texture, i + 0x41);
        }
        halfWidth = (f32)(bpPanelFrameWidth(frame) / 2);
        halfHeight = (f32)(bpPanelFrameHeight(frame) / 2);
        bpPanelSetRect(work + 0x410 + i * 0x100,
                       arcX - halfWidth + baseX, arcY - halfHeight + baseY, frame);
        frame = func_0021cca0(texture, i + 0x14);
        halfWidth = (f32)(bpPanelFrameWidth(frame) / 2);
        halfHeight = (f32)(bpPanelFrameHeight(frame) / 2);
        bpPanelSetRect(work + 0xb10 + i * 0x100,
                       arcX - halfWidth + baseX, arcY - halfHeight + baseY, frame);
        selected = (i == (s32)*(u32*)(work + 0x4634));
        (void)selected;
    }

    if (bpPanelInTransition(sub))
    {
        arrowFactor = (3.0f - (f32)*(u32*)(work + 0x4650)) / 3.0f;
    }
    else if (sub == 0 &&
             bpPanelInTransition(*(u32*)(work + 0x4640)) &&
             *(u32*)(work + 0x4650) != 3)
    {
        arrowFactor = (f32)*(u32*)(work + 0x4650) / 3.0f;
    }
    else if (sub == 0)
    {
        arrowFactor = 1.0f;
    }
    frame = func_0021cca0(texture, 0x0e);
    bpPanelSetRect(work + 0x310, centerX + 23.0f, centerY - 9.0f, frame);
    bpPanelSetColorUnsigned(work + 0x310, color, 0xff, 0xff, 0xff, 255.0f * arrowFactor * dt);

    for (i = 0; i < 7; i++)
    {
        u32 slotFlags;
        f32 brightness;
        f32 selectionFactor;
        u8 red;
        u8 green;
        u8 blue;

        if (mode == 1)
        {
            selectionFactor = (f32)*(u32*)(work + 0x464c) / 4.0f;
            phase = (1.0f + (f32)i - (f32)*(u32*)(work + 0x4634) - selectionFactor) / 7.0f;
        }
        else if (mode == 2)
        {
            selectionFactor = (f32)*(u32*)(work + 0x464c) / 4.0f;
            phase = ((f32)i - (f32)*(u32*)(work + 0x4634) - 1.0f + selectionFactor) / 7.0f;
        }
        else
        {
            selectionFactor = 1.0f;
            phase = ((f32)i - (f32)*(u32*)(work + 0x4634)) / 7.0f;
        }
        angle = 2.0f * pi * phase;
        brightness = (65.0f + 25.0f * (114.0f -
                    (*(f32*)(work + 0x7210) * func_0052e6d8(angle) + 57.0f)) / 114.0f) / 100.0f;
        slotFlags = *(u32*)(work + 0x1210 + i * 4);
        if (i == *(u32*)(work + 0x4634))
        {
            if ((slotFlags & 1) != 0)
            {
                f32 q;

                q = 1.0f - selectionFactor;
                red = bpPanelColor(255.0f - 204.0f * q);
                green = bpPanelColor(120.0f - 37.0f * q);
                blue = bpPanelColor(175.0f - 85.0f * q);
            }
            else
            {
                red = 115;
                green = 116;
                blue = 116;
            }
            bpPanelSetColorUnsigned(work + 0xb10 + i * 0x100, color, red, green, blue, 255.0f * brightness * dt);
            bpPanelSetColorUnsigned(work + 0x410 + i * 0x100, color, 0xff, 0xff, 0xff, 255.0f * brightness * (1.0f - selectionFactor) * dt);
        }
        else if (i == *(u32*)(work + 0x4638))
        {
            if ((slotFlags & 1) != 0)
            {
                f32 q;

                q = 1.0f - selectionFactor;
                red = bpPanelColor(255.0f - 204.0f * q);
                green = bpPanelColor(120.0f - 37.0f * q);
                blue = bpPanelColor(175.0f - 85.0f * q);
            }
            else
            {
                red = 115;
                green = 116;
                blue = 116;
            }
            bpPanelSetColorUnsigned(work + 0xb10 + i * 0x100, color, red, green, blue, 255.0f * brightness * arrowFactor * dt);
            bpPanelSetColorUnsigned(work + 0x410 + i * 0x100, color, 0xff, 0xff, 0xff, 255.0f * arrowFactor * brightness * selectionFactor * dt);
        }
        else
        {
            if ((slotFlags & 1) != 0)
            {
                red = 0x3c;
                green = 0x5e;
                blue = 0x64;
            }
            else
            {
                red = 0x73;
                green = 0x74;
                blue = 0x74;
            }
            bpPanelSetColorUnsigned(work + 0xb10 + i * 0x100, color, red, green, blue, 255.0f * arrowFactor * dt);
            bpPanelSetColorUnsigned(work + 0x410 + i * 0x100, color, 0xff, 0xff, 0xff, 255.0f * arrowFactor * brightness * selectionFactor * dt);
        }
    }

    sub = *(u32*)(work + 0x463c);
    switch (sub)
    {
    case 0:
        break;
    case 2:
    case 1:
    case 3:
    case 4:
        func_002265d0();
        break;
    }
    previous = *(u32*)(work + 0x4640);
    switch (previous)
    {
    case 0:
        break;
    case 3:
        if (*(u32*)(work + 0x4650) == 3)
        {
            break;
        }
    case 4:
    case 1:
    case 2:
        func_002265d0();
        break;
    }
    sub = *(u32*)(work + 0x463c);
    if (sub == 3)
    {
        switch (*(u32*)(work + 0x4644))
        {
        case 2:
        case 3:
            break;
        case 1:
            func_00227f30();
            break;
        case 0:
            switch (*(u32*)(work + 0x4648))
            {
            case 0:
            case 2:
                break;
            case 1:
                if (*(u32*)(work + 0x4658) != 6)
                {
                    func_00227f30();
                }
                break;
            }
            break;
        }
    }
    sub = *(u32*)(work + 0x463c);
    switch (sub)
    {
    case 0:
    case 3:
    case 4:
        break;
    case 2:
    case 1:
        func_0022c2d0();
        break;
    }
    sub = *(u32*)(work + 0x463c);
    previous = *(u32*)(work + 0x4640);
    if (sub == 2 || (sub == 0 && previous == 2 && *(u32*)(work + 0x4650) < 3))
    {
        func_00228e40();
    }
    else if (sub == 1 || (sub == 0 && previous == 1 && *(u32*)(work + 0x4650) < 3))
    {
        func_0022a2b0();
    }
    else if (sub == 4 || (sub == 0 && previous == 4 && *(u32*)(work + 0x4650) < 3))
    {
        func_00224940();
    }
    else if (sub == 3 || (sub == 0 && previous == 3 && *(u32*)(work + 0x4650) < 3))
    {
        func_00223290();
    }
    sub = *(u32*)(work + 0x463c);
    if (sub == 3)
    {
        switch (*(u32*)(work + 0x4644))
        {
        case 3:
            break;
        case 0:
            switch (*(u32*)(work + 0x4648))
            {
            case 0:
                break;
            case 2:
            case 1:
                if (*(u32*)(work + 0x4658) < 6)
                {
                    func_002257f0();
                }
                break;
            }
            break;
        case 1:
        case 2:
            func_002257f0();
            break;
        }
    }
}

// FUN_00221b60
void func_00221b60(void)
{
    u8* work;
    void* texture;
    s32 mask;
    void* currentFrame;
    void* previousFrame;
    void* frame;
    void (**setState)(u32, u32);
    u32 mode;
    u32 sub;
    u32 previousSub;
    u32 timer;
    u32 i;

    K_ASSERT(BP_PANEL_GLOBAL != NULL, 0xe6);
    work = BP_PANEL_GLOBAL;
    texture = func_0021c3f0(0);
    K_ASSERT((*(u32*)work & 1) != 0, 0x47b);

    mask = 0;
    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(9, 2);
    (*setState)(0x14, 2);
    (*setState)(8, 0);
    (*setState)(6, 1);
    (*setState)(0x0e, 0);
    (*setState)(0x0c, 1);
    func_0022bcf0();

    {
        void (**setQuad)(u32*, u32, u32, u32, u32);

        frame = func_0021cca0(texture, 0x10);
        (*setState)(1, func_0021cce0(frame));
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        setQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
        (*setQuad)((u32*)(work + 0x10), 4, 0, 1, 2);
        (*setQuad)((u32*)(work + 0x10), 4, 0, 2, 3);

        frame = func_0021cca0(texture, 0x1b);
        (*setState)(1, func_0021cce0(frame));
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        (*setQuad)((u32*)(work + 0x110), 4, 0, 1, 2);
        (*setQuad)((u32*)(work + 0x110), 4, 0, 2, 3);

        frame = func_0021cca0(texture, 0x1c);
        (*setState)(1, func_0021cce0(frame));
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        (*setQuad)((u32*)(work + 0x210), 4, 0, 1, 2);
        (*setQuad)((u32*)(work + 0x210), 4, 0, 2, 3);

        frame = func_0021cca0(texture, 0x22);
        (*setState)(1, func_0021cce0(frame));
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        (*setQuad)((u32*)(work + 0x1430), 4, 0, 1, 2);
        (*setQuad)((u32*)(work + 0x1430), 4, 0, 2, 3);
    }

    mode = *(u32*)(work + 0x4630);
    switch (mode)
    {
    case 1:
    case 2:
        frame = texture;
        currentFrame = func_0021cca0(frame, *(s32*)(work + 0x4634));
        previousFrame = func_0021cca0(texture, *(s32*)(work + 0x4638));
        mask |= 1;
        if (*(u32*)(work + 0x464c) != 4)
        {
            mask |= 2;
        }
        break;
    case 3:
        currentFrame = func_0021cca0(texture, *(s32*)(work + 0x4634));
        previousFrame = func_0021cca0(texture, (s32)*(u32*)(work + 0x4634) + 7);
        sub = *(u32*)(work + 0x463c);
        switch (sub)
        {
        case 0:
            mask |= 1;
            if (*(u32*)(work + 0x4650) != 3)
            {
                mask |= 2;
            }
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            mask |= 2;
            if (*(u32*)(work + 0x4650) != 3)
            {
                mask |= 1;
            }
            break;
        }
        break;
    default:
        sub = *(u32*)(work + 0x463c);
        switch (sub)
        {
        case 0:
            currentFrame = func_0021cca0(texture, *(s32*)(work + 0x4634));
            mask |= 1;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            previousFrame = func_0021cca0(texture, (s32)*(u32*)(work + 0x4634) + 7);
            mask |= 2;
            break;
        }
        break;
    }

    if ((mask & 1) != 0)
    {
        void (**setQuad)(u32*, u32, u32, u32, u32);

        (*setState)(1, func_0021cce0(currentFrame));
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        setQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
        (*setQuad)((u32*)(work + 0x1230), 4, 0, 1, 2);
        (*setQuad)((u32*)(work + 0x1230), 4, 0, 2, 3);
    }
    if ((mask & 2) != 0)
    {
        void (**setQuad)(u32*, u32, u32, u32, u32);

        (*setState)(1, func_0021cce0(previousFrame));
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        setQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
        (*setQuad)((u32*)(work + 0x1330), 4, 0, 1, 2);
        (*setQuad)((u32*)(work + 0x1330), 4, 0, 2, 3);
    }
    if ((~*(u32*)work & 0x10) != 0)
    {
        void (**setQuad)(u32*, u32, u32, u32, u32);

        frame = func_0021cca0(texture, 0x0e);
        (*setState)(1, func_0021cce0(frame));
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        setQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
        (*setQuad)((u32*)(work + 0x310), 4, 0, 1, 2);
        (*setQuad)((u32*)(work + 0x310), 4, 0, 2, 3);
    }

    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    {
        void (**setQuad)(u32*, u32, u32, u32, u32);
        u32* destination;

        for (mask = 0; mask < 7; mask++)
        {
            if ((*(u32*)(work + 0x1210 + mask * 4) & 1) != 0)
            {
                frame = func_0021cca0(texture, 0x11);
            }
            else
            {
                frame = func_0021cca0(texture, 0x41);
            }
            (*setState)(1, func_0021cce0(frame));
            destination = (u32*)(work + 0x410 + mask * 0x100);
            setQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
            (*setQuad)(destination, 4, 0, 1, 2);
            (*setQuad)(destination, 4, 0, 2, 3);
        }
    }
    {
        void (**setQuad)(u32*, u32, u32, u32, u32);
        u32* destination;
        s32 j;

        for (j = 0; j < 7; j++)
        {
            frame = func_0021cca0(texture, (s32)(j + 0x14));
            (*setState)(1, func_0021cce0(frame));
            RpSkyRenderStateSet(3, (void*)0x717fb);
            RpSkyRenderStateSet(2, (void*)0x44);
            destination = (u32*)(work + 0xb10 + j * 0x100);
            setQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
            (*setQuad)(destination, 4, 0, 1, 2);
            (*setQuad)(destination, 4, 0, 2, 3);
        }
    }

    sub = *(u32*)(work + 0x463c);
    switch (sub)
    {
    case 3:
    case 4:
        goto bpTexSubOuterBody;
    case 0:
        goto bpTexSubPreviousPath;
    }
    goto bpTexSubAfter;
bpTexSubOuterBody:
    func_00227800();
    goto bpTexSubAfter;
bpTexSubPreviousPath:
    previousSub = *(u32*)(work + 0x4640);
    if (previousSub == 4)
    {
        goto bpTexSubTimerPath;
    }
    if (previousSub != 3)
    {
        goto bpTexSubAfter;
    }
bpTexSubTimerPath:
    if (*(u32*)(work + 0x4650) == 3)
    {
        goto bpTexSubAfter;
    }
    func_00227800();
bpTexSubAfter:

    sub = *(u32*)(work + 0x463c);
    if (sub == 2 ||
        (sub == 0 && *(u32*)(work + 0x4640) == 2 &&
         *(s32*)(work + 0x4650) < 3))
    {
        switch (*(u32*)(work + 0x4644))
        {
        case 0:
            func_00227800();
            break;
        case 3:
            func_0022c5a0();
            break;
        }
        func_00229b40();
    }
    else if (sub == 1 ||
             (sub == 0 && *(u32*)(work + 0x4640) == 1 &&
              *(s32*)(work + 0x4650) < 3))
    {
        switch (*(u32*)(work + 0x4644))
        {
        case 0:
            func_00227800();
            break;
        case 4:
            func_0022c5a0();
            break;
        }
        func_0022ae80();
    }
    else if (sub == 4 ||
             (sub == 0 && *(u32*)(work + 0x4640) == 4 &&
              *(s32*)(work + 0x4650) < 3))
    {
        func_00225040();
    }

    sub = *(u32*)(work + 0x463c);
    switch (sub)
    {
    case 3:
        goto bpTexSub3Body;
    }
    if (sub != 0)
    {
        goto bpTexSub3After;
    }
    previousSub = *(u32*)(work + 0x4640);
    if (previousSub != 3)
    {
        goto bpTexSub3After;
    }
    if (*(s32*)(work + 0x4650) >= 3)
    {
        goto bpTexSub3After;
    }
bpTexSub3Body:
    func_00224150();
bpTexSub3After:

    sub = *(u32*)(work + 0x463c);
    switch (sub)
    {
    case 3:
        goto bpTexMode3FrameBody;
    }
    goto bpTexMode3FrameAfter;
bpTexMode3FrameBody:
    switch (*(u32*)(work + 0x4644))
    {
    case 1:
        func_002289b0();
        break;
    case 0:
        if (*(u32*)(work + 0x4648) == 1 &&
            *(u32*)(work + 0x4658) != 6)
        {
            func_002289b0();
        }
        break;
    }
bpTexMode3FrameAfter:

    sub = *(u32*)(work + 0x463c);
    switch (sub)
    {
    case 3:
        goto bpTexFinalSub3;
    default:
        goto bpTexFinalAfter;
    }
bpTexFinalSub3:
    switch (*(u32*)(work + 0x4644))
    {
    case 0:
        goto bpTexFinalFrame0;
    case 1:
    case 2:
        goto bpTexFinalFrame12;
    default:
        goto bpTexFinalAfter;
    }
bpTexFinalFrame0:
    if (*(u32*)(work + 0x4648) != 1 &&
        *(u32*)(work + 0x4648) != 2)
    {
        goto bpTexFinalAfter;
    }
    if (*(s32*)(work + 0x4658) >= 6)
    {
        goto bpTexFinalAfter;
    }
    func_00226040();
    goto bpTexFinalAfter;
bpTexFinalFrame12:
    func_00226040();
bpTexFinalAfter:
    return;
}

// FUN_002226f0
void bcmPanel002226f0(u32 param_1)
{
    int iVar1;
    u32 uVar2;
    u32 uVar3;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    iVar1 = (int)sBcmPanel;
    uVar2 = FUN_0021c3f0(0);
    *(u32*)(iVar1 + 0x4630) = 1;
    *(u32*)(iVar1 + 0x4638) = *(u32*)(iVar1 + 0x4634);
    *(u32*)(iVar1 + 0x4634) = param_1;
    *(u32*)(iVar1 + 0x464c) = 0;
    uVar3 = FUN_0021cca0(uVar2, *(u32*)(iVar1 + 0x4634));
    FUN_0021d3b0(iVar1 + 0x1230, uVar3);
    uVar3 = FUN_0021cca0(uVar2, *(u32*)(iVar1 + 0x4638));
    FUN_0021d3b0(iVar1 + 0x1330, uVar3);
}
/*
 * The command panel stores all of its render records in one work area.  The
 * retail code uses the records as packed byte arrays; keeping the addressing
 * in these small helpers makes the state-machine routines below considerably
 * easier to audit than a collection of magic pointer casts.
 */









/* Removing this loses FUN_002230e0 (MATCH nd0 -> MISMATCH nd19) - measured W302. */



// FUN_002227b0
void bcmPanel002227b0(u32 param_1)
{
    int iVar1;
    u32 uVar2;
    u32 uVar3;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    iVar1 = (int)sBcmPanel;
    uVar2 = FUN_0021c3f0(0);
    *(u32*)(iVar1 + 0x4630) = 2;
    *(u32*)(iVar1 + 0x4638) = *(u32*)(iVar1 + 0x4634);
    *(u32*)(iVar1 + 0x4634) = param_1;
    *(u32*)(iVar1 + 0x464c) = 0;
    uVar3 = FUN_0021cca0(uVar2, *(u32*)(iVar1 + 0x4634));
    FUN_0021d3b0(iVar1 + 0x1230, uVar3);
    uVar3 = FUN_0021cca0(uVar2, *(u32*)(iVar1 + 0x4638));
    FUN_0021d3b0(iVar1 + 0x1330, uVar3);
}

// FUN_00222870
void bcmPanel00222870(void)
{
    int iVar1;
    u32 uVar2;
    u32 uVar3;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    iVar1 = (int)sBcmPanel;
    uVar2 = FUN_0021c3f0(0);
    *(u32*)(iVar1 + 0x4630) = 8;
    *(u32*)(iVar1 + 0x4638) = *(u32*)(iVar1 + 0x4634);
    *(u32*)(iVar1 + 0x4634) = 0;
    *(u32*)(iVar1 + 0x464c) = 0;
    uVar3 = FUN_0021cca0(uVar2, *(u32*)(iVar1 + 0x4634));
    FUN_0021d3b0(iVar1 + 0x1230, uVar3);
    uVar3 = FUN_0021cca0(uVar2, *(u32*)(iVar1 + 0x4638));
    FUN_0021d3b0(iVar1 + 0x1330, uVar3);
}

// FUN_00222930
void bcmPanel00222930(void)
{
    u32* puVar1;
    u32 uVar2;
    u32 uVar3;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    puVar1 = sBcmPanel;
    uVar2 = FUN_0021c3f0(0);
    *puVar1 |= 2;
    puVar1[1] = 0;
    puVar1[1] |= 1;
    puVar1[0x118c] = 3;
    puVar1[0x1190] = puVar1[0x118f];
    puVar1[0x118f] = 1;
    puVar1[0x1194] = 0;
    puVar1[0x1191] = 0;
    uVar3 = FUN_0021cca0(uVar2, puVar1[0x118d]);
    FUN_0021d3b0(puVar1 + 0x48c, uVar3);
    uVar3 = FUN_0021cca0(uVar2, puVar1[0x118d] + 7);
    FUN_0021d3b0(puVar1 + 0x4cc, uVar3);
    FUN_00226320();
    uVar3 = FUN_0021cca0(uVar2, 0x23);
    FUN_0021d3b0(puVar1 + 0x108c, uVar3);
    uVar3 = FUN_0021cca0(uVar2, 0x23);
    FUN_0021e380(puVar1 + 0x10cc, uVar3, 1);
    FUN_00222d60();
}
// FUN_00222a60
void bcmPanel00222a60(void)
{
    u32* puVar1;
    u32 uVar2;
    u32 uVar3;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    puVar1 = sBcmPanel;
    uVar2 = FUN_0021c3f0(0);
    *puVar1 |= 2;
    puVar1[1] = 0;
    puVar1[1] |= 2;
    puVar1[0x118c] = 3;
    puVar1[0x1190] = puVar1[0x118f];
    puVar1[0x118f] = 2;
    puVar1[0x1194] = 0;
    puVar1[0x1191] = 0;
    uVar3 = FUN_0021cca0(uVar2, puVar1[0x118d]);
    FUN_0021d3b0(puVar1 + 0x48c, uVar3);
    uVar3 = FUN_0021cca0(uVar2, puVar1[0x118d] + 7);
    FUN_0021d3b0(puVar1 + 0x4cc, uVar3);
    FUN_00226320();
    uVar3 = FUN_0021cca0(uVar2, 0x23);
    FUN_0021d3b0(puVar1 + 0x108c, uVar3);
    uVar3 = FUN_0021cca0(uVar2, 0x23);
    FUN_0021e380(puVar1 + 0x10cc, uVar3, 1);
    FUN_00222b90();
}

// Previous body was a wrong-helper stub unrelated to retail (1296B window).
// Rewritten from disasm: retail dispatches per-record state via a switch
// (case 0/2 shared, case 1 loops 4 quad slots), using the same
// D_00960090_abs/D_0096009C_abs vtable style as this file's other draw
// functions. Key finding: D_0096009C_abs must be re-cast to a fresh local
// inside both the state==1 loop and the case 0/2 body, matching retail's
// W389 measured first-use swap (slot0 before records): nd11/1292B -> nd16/1292B
// (window 1296B), reverted. Residual is the 2-variable register-bank swap
// (slot0/setQuad), unfixable per the declaration/statement-order floor.
// FUN_00222b90
void FUN_00222b90(void)
{
    u32 table0;
    u32 resource;
    s32 i;
    u32 table6;
    u32 state;
    u8* record;
    u8* records;
    u8* work;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    records = work + 0x4660;
    table6 = FUN_0021c3f0(6);
    K_ASSERT((*(u32*)(work + 4) & 2) != 0, 0x60d);
    i = 0;
    while (i < *(s32*)(work + 0x6070)) {
        record = records + i * 0x510;
        state = *(u32*)(record + 8);
        switch (state) {
        case 0:
            resource = FUN_0021cca0(table0, 0x30);
            break;
        case 1:
            resource = FUN_0021cca0(table0, 0x31);
            break;
        }
        FUN_0021d3b0(record + 0x10, resource);
        FUN_00238980(record + 0x110, 3, *(u32*)(record + 0xc), 1);
        resource = FUN_0021cca0(table6, 0x2b);
        FUN_0021d3b0(record + 0x410, resource);
        i++;
    }
    if (*(u32*)(work + 0x68f8) != 0) {
        resource = FUN_0021cca0(table6, *(u32*)(work + 0x68f4) + 0x20);
        FUN_0021d3b0(work + 0x6900, resource);
    }
}

// FUN_00222d60
void FUN_00222d60(void)
{
    u32 table0;
    u32 table6;
    s32 i;
    u8* work;
    u8* records;
    u8* record;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    table6 = FUN_0021c3f0(6);
    records = work + 0x4660;
    K_ASSERT((*(u32*)(work + 4) & 1) != 0, 0x63c);
    i = 0;
    while (i < *(s32*)(work + 0x6070)) {
        record = records + i * 0x410;
        FUN_0021d3b0(record + 0x10, FUN_0021cca0(table0, 0x28));
        FUN_00238980(record + 0x110, 2, *(u32*)(record + 4), 1);
        FUN_0021d3b0(record + 0x310, FUN_0021cca0(table6, 0x1a));
        i++;
    }
    if (*(u32*)(work + 0x68f8) != 0) {
        FUN_0021d3b0(work + 0x6900,
                     FUN_0021cca0(table6, *(u32*)(work + 0x68f4) + 0x20));
    }
}

// FUN_00222ed0
void bcmPanel00222ed0(void)
{
    u32* puVar1;
    u32 uVar2;
    u32 uVar3;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    puVar1 = sBcmPanel;
    uVar2 = FUN_0021c3f0(0);
    *puVar1 |= 2;
    puVar1[0x118c] = 3;
    puVar1[0x1190] = puVar1[0x118f];
    puVar1[0x118f] = 0;
    puVar1[0x1194] = 0;
    uVar3 = FUN_0021cca0(uVar2, puVar1[0x118d]);
    FUN_0021d3b0(puVar1 + 0x48c, uVar3);
    uVar3 = FUN_0021cca0(uVar2, puVar1[0x118d] + 7);
    FUN_0021d3b0(puVar1 + 0x4cc, uVar3);
}

/* W389 measured opt_dead_assignments off: nd1212/1760B -> nd1211/1748B (window 1792B). */
// FUN_00222fa0
void bcmPanel00222fa0(void)
{
    u32* puVar1;
    u32 uVar2;
    u32 uVar3;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    puVar1 = sBcmPanel;
    uVar2 = FUN_0021c3f0(0);
    *puVar1 |= 2;
    puVar1[1] = 0;
    puVar1[1] |= 4;
    puVar1[0x118c] = 3;
    puVar1[0x1190] = puVar1[0x118f];
    puVar1[0x118f] = 3;
    puVar1[0x1191] = 0;
    puVar1[0x1192] = 0xffffffff;
    puVar1[0x1194] = 0;
    puVar1[0x1196] = 0;
    uVar3 = FUN_0021cca0(uVar2, puVar1[0x118d]);
    FUN_0021d3b0(puVar1 + 0x48c, uVar3);
    uVar3 = FUN_0021cca0(uVar2, puVar1[0x118d] + 7);
    FUN_0021d3b0(puVar1 + 0x4cc, uVar3);
    FUN_00226320();
    uVar3 = FUN_0021cca0(uVar2, 0x24);
    FUN_0021d3b0(puVar1 + 0x108c, uVar3);
    uVar3 = FUN_0021cca0(uVar2, 0x24);
    FUN_0021e380(puVar1 + 0x10cc, uVar3, 1);
    FUN_002230e0();
}

// Previous body was a wrong-helper stub unrelated to retail (1120B window).
// Rewritten from disasm: retail draws each record's icon then 2 status
// quads (state==1 draws 4), then a table3 and table1 resource pair,
// using the same D_00960090_abs/D_0096009C_abs vtable style as this
// file's other draw functions; table3 is stack-spilled (not register-
// resident) since it's needed after many intervening calls.
// nd 153->705 raw obj-growth artifact (obj 1104B/1120B, was 248B wrong
// stub); content-diff (register-agnostic) confirms 100% correct call
// sequence/offsets/constants. Residual is that MWCC does not allocate a
// persistent register to the D_00960090_abs/D_0096009C_abs casts at any
// of the 4 sites here (recomputes transiently in $v0 instead), unlike
// the otherwise-identical pattern in FUN_00224150 above - 6 declaration/
// statement-reorder attempts confirmed this is unfixable from C source.
// FUN_002230e0
/* W357 measured FUN_002230e0: optimization_level 1 nd19/432B -> nd0/432B. */
#pragma optimization_level 1
void FUN_002230e0(void)
{
    s32 j;
    u8* work;
    u8* records;
    u8* record;
    u32 table0;
    s32 i;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    records = work + 0x4660;
    K_ASSERT((*(u32*)(work + 4) & 4) != 0, 0x699);
    i = 0;
    while (i < *(s32*)(work + 0x6070)) {
        record = records + i * 0x420;
        switch (*(u32*)record) {
        case 0:
        case 2:
            FUN_0021d3b0(record + 0x10,
                         FUN_0021cca0(table0, 0x2f));
            break;
        case 1:
            j = 0;
            while (j < 2) {
                FUN_0021d3b0(record + 0x10 + (j << 8),
                             FUN_0021cca0(table0, 0x29));
                j++;
            }
            j = 2;
            while (j < 4) {
                FUN_0021d3b0(record + 0x10 + (j << 8),
                             FUN_0021cca0(table0, 0x2a));
                j++;
            }
            break;
        }
        i++;
    }
}

#pragma optimization_level 2

/* W357 measured FUN_00223290: opt_propagation off nd2166/3392B -> nd2127/3224B,
 * window 3776B. W419 coordinate-store recovery: nd2127/3224B ->
 * nd2128/3240B, window 3776B, rate 0.659739 -> 0.656790. Moving
 * coordinates plus colours before the frame call was rejected: nd2148/3268B,
 * window 3776B, rate 0.657895. */
#pragma opt_propagation off
// FUN_00223290 NONMATCHING
void FUN_00223290(void)
{
    u8 alphaByte;
    s32 alphaInt;
    u32 handle;
    u32 table0;
    u8* base;
    u8* records;
    f32 alpha1;
    f32 weight;
    u8* pos;
    void* frame;
    f32 layout[4];
    u8 colour[36];
    u32 dispatch;
    u32 secondaryDispatch;
    u32 selIndex;
    u8* selRecord;
    u32 kind;
    s32 halfWidth;
    u32 colours[4];
    u32 scaledAlphaColour;
    s32 i;
    u32 selColour;
    s32 x, y;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    records = base + 0x4660;
    weight = *(f32*)(base + 0x7214);
    dispatch = *(u32*)(base + 0x463c);
    if (dispatch == 0) goto alpha_case0;
    switch (dispatch) {
    case 3: goto alpha_case3;
    }
    goto alpha_assert;
alpha_case3:
    secondaryDispatch = *(u32*)(base + 0x4644);
    switch (secondaryDispatch) {
    case 0:
        goto alpha_secondary0;
    case 1:
        goto alpha_ratio;
    case 2:
        goto alpha_ratio;
    default:
        goto alpha_done;
    }
alpha_secondary0:
    if (*(u32*)(base + 0x4648) == 1) goto alpha_check_timer;
    if (*(u32*)(base + 0x4648) == 2) goto alpha_check_timer;
    goto alpha_frac;
alpha_check_timer:
    if (*(s32*)(base + 0x4658) >= 6) goto alpha_frac;
    alpha1 = (f32)*(s32*)(base + 0x4658) / 6.0f;
    goto alpha_done;
alpha_frac:
    alpha1 = (f32)*(s32*)(base + 0x4650) / 3.0f;
    goto alpha_done;
alpha_ratio:
    alpha1 = (f32)((6 - *(s32*)(base + 0x4658)) / 6);
    goto alpha_done;
alpha_case0:
    alpha1 = (f32)((3 - *(s32*)(base + 0x4650)) / 3);
    goto alpha_done;
alpha_assert:
    K_ASSERT(0, 0x6e5);
alpha_done:
    ;
    alphaInt = (s32)(255.0f * alpha1 * weight);
    alphaByte = (u8)alphaInt;
    pos = base + 0x6050;

    frame = (void*)FUN_0021cca0(table0, 0x24);
    layout[0] = *(f32*)(pos + 0) + 47.0f;
    layout[1] = 19.0f + *(f32*)(pos + 4) +
                (f32)((*(s32*)(base + 0x6068) - *(s32*)(base + 0x606c)) * 26);
    layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
    layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(base + 0x4230, layout);

    frame = (void*)FUN_0021cca0(table0, 0x24);
    layout[0] = *(f32*)(pos + 0) + 47.0f +
                (f32)*(s32*)((u8*)frame + 0xc);
    layout[1] = 19.0f + *(f32*)(pos + 4) +
                (f32)((*(s32*)(base + 0x6068) - *(s32*)(base + 0x606c)) * 26);
    layout[2] = 312.0f;
    layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(base + 0x4330, layout);

    colour[0] = 0xff;
    colour[1] = 0xff;
    colour[2] = 0xff;
    colour[3] = (u8)alphaByte;
    FUN_0021d950(base + 0x4230, colour);
    FUN_0021d950(base + 0x4330, colour);

    *(u32*)base &= ~4;
    if (*(u32*)(base + 0x463c) == 3) {
        secondaryDispatch = *(u32*)(base + 0x4644);
        if (secondaryDispatch == 2) goto sel;
        if (secondaryDispatch == 1) goto sel;
        if (secondaryDispatch == 0) {
            if (*(u32*)(base + 0x4648) == 1) goto sel_check_timer;
            if (*(u32*)(base + 0x4648) == 2) goto sel_check_timer;
        }
        goto sel_done;
    sel_check_timer:
        if (*(s32*)(base + 0x4658) >= 6) goto sel_done;
        K_ASSERT((*(u32*)base & 4) != 0, 0x711);
    sel:
        colours[0] = (alphaByte & 0xff) | 0xffffff00u;
        *(u32*)(records + 0x18c4) = colours[0];
        colours[1] = 0xff - (alphaByte & 0xff);
        *(u32*)(records + 0x18c8) = colours[1] | 0xff9d9d00u;
        *(u32*)(records + 0x18cc) = colours[1] | 0xffffff00u;
        selIndex = *(u32*)(records + 0x18c0);
        selRecord = records + selIndex * 0x420;
        kind = *(u32*)selRecord;
        if (kind == 1) goto sel_kind1;
        if (kind == 2) goto sel_kind02;
        if (kind == 0) goto sel_kind02;
        goto sel_join;
    sel_kind1:
        handle = (u32)*(void**)(selRecord + 8);
        halfWidth = FUN_003b19d0((u32)handle);
        halfWidth = (halfWidth >= 0) ? (halfWidth >> 1) : ((halfWidth + 1) >> 1);
        *(f32*)(records + 0x18d0) = 112.0f + *(f32*)(pos + 0) - ((f32)halfWidth - 70.5f);
        *(f32*)(records + 0x18d4) = 19.0f + *(f32*)(pos + 4) + (f32)(selIndex * 26);
        goto sel_join;
    sel_kind02:
        *(f32*)(records + 0x18d0) = 51.0f + *(f32*)(pos + 0);
        *(f32*)(records + 0x18d4) = 19.0f + *(f32*)(pos + 4) + (f32)(selIndex * 26);
    sel_join:
        *(f32*)(records + 0x18d8) = 171.0f + *(f32*)(pos + 0);
        *(f32*)(records + 0x18dc) = 19.0f + *(f32*)(pos + 4);
        *(u32*)base |= 4;
    sel_done:
        ;
    }
    if (*(u32*)base & 4) {
        handle = (u32)*(void**)(selRecord + 8);
        halfWidth = FUN_003b19d0((u32)handle);
        halfWidth = (halfWidth >= 0) ? (halfWidth >> 1) : ((halfWidth + 1) >> 1);
        layout[0] = 112.0f + *(f32*)(pos + 0) - ((f32)halfWidth - 70.5f);
        layout[1] = 19.0f + *(f32*)(pos + 4) + (f32)(selIndex * 26);
        *(f32*)(records + 0x18d0) = layout[0];
        *(f32*)(records + 0x18d4) = layout[1];
        frame = (void*)FUN_0021cca0(table0, 0x2f);
        FUN_0021d3b0(records + 0x18f0, frame);
        layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
        layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
        FUN_0021d8e0(records + 0x18f0, layout);
        colour[0] = 0xff;
        colour[1] = 0xff;
        colour[2] = 0xff;
        colour[3] = 0xff - (alphaByte & 0xff);
        FUN_0021d950(records + 0x18f0, colour);
    }

    colours[0] = (alphaByte & 0xff) | 0xffffff00u;
    colours[1] = (alphaByte & 0xff) | 0xbeffd200u;
    colours[2] = (alphaByte & 0xff) | 0xcccccc00u;
    colours[3] = (alphaByte & 0xff) | 0x64cc6400u;
    scaledAlphaColour = ((alphaByte & 0xff) << 7) / 0xff;
    scaledAlphaColour = 0xffffff00u | scaledAlphaColour;
    for (i = 0; i < *(u32*)(base + 0x6070); i++) {
        u8* record = records + i * 0x420;
        kind = *(u32*)record;
        switch (kind) {
        case 0:
        case 2:
            goto loop_kind02;
        case 1:
            goto loop_kind1;
        default:
            goto loop_next;
        }
    loop_kind02:
        handle = (u32)*(void**)(record + 8);
        layout[0] = 51.0f + *(f32*)(pos + 0);
        layout[1] = 19.0f + *(f32*)(pos + 4) + (f32)(i * 26);
        if (i == (u32)(*(s32*)(base + 0x6068) - *(s32*)(base + 0x606c))) {
            if (*(u32*)(record + 0x410) != 0) {
                selColour = scaledAlphaColour;
            } else if (kind == 2) {
                selColour = colours[1];
            } else if (kind == 0) {
                selColour = colours[0];
            }
        } else {
            if (*(u32*)(record + 0x410) != 0) {
                selColour = scaledAlphaColour;
            } else if (kind == 2) {
                selColour = colours[3];
            } else if (kind == 0) {
                selColour = colours[2];
            }
        }
        x = (s32)layout[0] << 4;
        y = (s32)layout[1] << 3;
        FUN_003b0d70((u32)handle, x, y);
        FUN_003b0e20((u32)handle, selColour);
        handle = (u32)*(void**)(record + 0xc);
        layout[0] = 182.0f + *(f32*)(pos + 0);
        layout[1] = 19.0f + *(f32*)(pos + 4) + (f32)(i * 26);
        x = (s32)layout[0] << 4;
        y = (s32)layout[1] << 3;
        FUN_003b0d70((u32)handle, x, y);
        FUN_003b0e20((u32)handle, selColour);
        frame = (void*)FUN_0021cca0(table0, 0x2f);
        layout[0] = 171.0f + *(f32*)(pos + 0);
        layout[1] = 28.0f + *(f32*)(pos + 4);
        layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
        layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
        FUN_0021d8e0(record + 0x10, layout);
        colour[0] = 0xff;
        colour[1] = 0xff;
        colour[2] = 0xff;
        colour[3] = (u8)alphaByte;
        FUN_0021d950(record + 0x10, colour);
        goto loop_next;
    loop_kind1:
        handle = (u32)*(void**)(record + 8);
        halfWidth = FUN_003b19d0((u32)handle);
        halfWidth = (halfWidth >= 0) ? (halfWidth >> 1) : ((halfWidth + 1) >> 1);
        layout[0] = 112.0f + *(f32*)(pos + 0) - ((f32)halfWidth - 70.5f);
        layout[1] = 19.0f + *(f32*)(pos + 4) + (f32)(i * 26);
        if (i == (u32)(*(s32*)(base + 0x6068) - *(s32*)(base + 0x606c))) {
            selColour = colours[0];
        } else {
            selColour = colours[2];
        }
        x = (s32)layout[0] << 4;
        y = (s32)layout[1] << 3;
        FUN_003b0d70((u32)handle, x, y);
        FUN_003b0e20((u32)handle, selColour);
        frame = (void*)FUN_0021cca0(table0, 0x29);
        layout[0] = 79.0f + *(f32*)(pos + 0);
        layout[1] = 29.0f + *(f32*)(pos + 4);
        layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
        layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
        FUN_0021d8e0(record + 0x10, layout);
        layout[0] = 99.0f + *(f32*)(pos + 0);
        layout[1] = 29.0f + *(f32*)(pos + 4);
        layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
        layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
        FUN_0021d8e0(record + 0x110, layout);
        frame = (void*)FUN_0021cca0(table0, 0x2a);
        layout[0] = 253.0f + *(f32*)(pos + 0);
        layout[1] = 29.0f + *(f32*)(pos + 4);
        layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
        layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
        FUN_0021d8e0(record + 0x210, layout);
        layout[0] = 273.0f + *(f32*)(pos + 0);
        layout[1] = 29.0f + *(f32*)(pos + 4);
        layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
        layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
        FUN_0021d8e0(record + 0x310, layout);
        {
            s32 j;
            for (j = 0; j < 4; j++) {
                colour[0] = 0xff;
                colour[1] = 0xff;
                colour[2] = 0xff;
                colour[3] = (u8)alphaByte;
                FUN_0021d950(record + j * 0x100 + 0x10, colour);
            }
        }
        goto loop_next;
    loop_next:
        ;
    }
}
#pragma opt_propagation reset

/* W414 named D_0096009C_abs alias-placement probes (top-level and secondary declaration sites) stayed nd11/1292B (window 1296B); reverted. Residual is the documented slot0/setQuad register-bank floor. */
// FUN_00224150 NONMATCHING
void FUN_00224150(void)
{
    u8* work;
    u8* records;
    u8* slot0;
    u8* record;
    u8* quadTarget;
    u32 table0;
    u32 resource;
    u32 texture;
    u32 selected;
    u32 state;
    s32 current;
    s32 i;
    s32 j;
    void (**setState)(u32, u32);
    void (**setQuad)(u32*, u32, u32, u32, u32);
    void (**setQuad2)(u32*, u32, u32, u32, u32);
    void (**setQuad3)(u32*, u32, u32, u32, u32);

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    records = work + 0x4660;
    slot0 = work + 0x6080;

    resource = FUN_0021cca0(table0, 0x23);
    setState = (void (**)(u32, u32))D_00960090_abs;
    texture = FUN_0021cce0(resource);
    (*setState)(1, texture);

    setQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
    (*setQuad)((u32*)(work + 0x4230), 4, 0, 1, 2);
    (*setQuad)((u32*)(work + 0x4230), 4, 0, 2, 3);
    (*setQuad)((u32*)(work + 0x4330), 4, 0, 1, 2);
    (*setQuad)((u32*)(work + 0x4330), 4, 0, 2, 3);

    if ((*(u32*)work & 4) != 0) {
        selected = *(u32*)(records + 0x18c0);
        record = records + selected * 0x420;
        state = *(u32*)record;
        switch (state) {
        case 0:
            resource = FUN_0021cca0(table0, 0x2f);
            texture = FUN_0021cce0(resource);
            (*setState)(1, texture);
            RpSkyRenderStateSet(3, (void*)0x717fb);
            RpSkyRenderStateSet(2, (void*)0x44);
            (*setQuad)((u32*)(records + 0x18f0), 4, 0, 1, 2);
            (*setQuad)((u32*)(records + 0x18f0), 4, 0, 2, 3);
            break;
        case 1:
            break;
        }
        func_003b1360(*(u32*)(slot0 + 0x560), 1, 0);
        if (*(u32*)(slot0 + 0x564) != 0) {
            func_003b1360(*(u32*)(slot0 + 0x564), 1, 0);
        }
    }

    for (i = 0; i < *(s32*)(work + 0x6070); ++i) {
        record = records + i * 0x420;
        state = *(u32*)record;
        switch (state) {
        case 0:
        case 2:
            current = *(s32*)(work + 0x6068) - *(s32*)(work + 0x606c);
            if (i == current) {
                RpSkyRenderStateSet(3, (void*)0x717fb);
                RpSkyRenderStateSet(2, (void*)0x44);
            } else {
                RpSkyRenderStateSet(3, (void*)0x71801);
                RpSkyRenderStateSet(2, (void*)0x42);
            }
            func_003b1360(*(u32*)(record + 8), 1, 0);
            RpSkyRenderStateSet(3, (void*)0x717fb);
            RpSkyRenderStateSet(2, (void*)0x44);
            func_003b1360(*(u32*)(record + 0xc), 1, 0);

            resource = FUN_0021cca0(table0, 0x2f);
            texture = FUN_0021cce0(resource);
            (*setState)(1, texture);
            RpSkyRenderStateSet(3, (void*)0x717fb);
            RpSkyRenderStateSet(2, (void*)0x44);
            setQuad3 = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
            (*setQuad3)((u32*)(record + 0x10), 4, 0, 1, 2);
            (*setQuad3)((u32*)(record + 0x10), 4, 0, 2, 3);
            break;
        case 1:
            func_003b1360(*(u32*)(record + 8), 1, 0);
            for (j = 0; j < 4; ++j) {
                if (j < 2) {
                    resource = FUN_0021cca0(table0, 0x29);
                } else {
                    resource = FUN_0021cca0(table0, 0x2a);
                }
                texture = FUN_0021cce0(resource);
                (*setState)(1, texture);
                RpSkyRenderStateSet(3, (void*)0x717fb);
                RpSkyRenderStateSet(2, (void*)0x44);
                quadTarget = record + j * 0x100 + 0x10;
                setQuad2 = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
                (*setQuad2)((u32*)quadTarget, 4, 0, 1, 2);
                (*setQuad2)((u32*)quadTarget, 4, 0, 2, 3);
            }
            break;
        }
    }
}

// Previous body used bcm_panel_read/write's wrong work-relative base for
// the 0x55c/0x550 count/progress fields (should be overlay0-relative,
// same bug class as FUN_00224150/FUN_00225040) and fabricated the
// interpolated y-offset via raw integer bit-pattern arithmetic instead
// of retail's genuine float divide. The enlarged local rectangle preserves
// retail's 0x70-byte frame, while explicit temporaries preserve mul ordering.
// FUN_00224660
void FUN_00224660(void)
{
    u8* work;
    u8* records;
    u32 table0;
    u32 table1;
    u32 table3;
    s32 i;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    table1 = FUN_0021c3f0(1);
    table3 = FUN_0021c3f0(3);
    records = work + 0x4660;
    *(u32*)work |= 2;
    *(u32*)(work + 4) = 0;
    *(u32*)(work + 4) |= 8;
    *(u32*)(work + 0x4630) = 3;
    *(u32*)(work + 0x4640) = *(u32*)(work + 0x463c);
    *(u32*)(work + 0x463c) = 4;
    *(u32*)(work + 0x4650) = 0;
    FUN_00226320();
    FUN_0021d3b0(work + 0x1230,
                 FUN_0021cca0(table0, *(u32*)(work + 0x4634)));
    FUN_0021d3b0(work + 0x1330,
                 FUN_0021cca0(table0, *(u32*)(work + 0x4634) + 7));
    FUN_0021d3b0(work + 0x4230, FUN_0021cca0(table0, 0x24));
    FUN_0021e380(work + 0x4330, FUN_0021cca0(table0, 0x24), 1);
    FUN_0021d3b0(records + 0xf50, FUN_0021cca0(table3, 0x13));
    FUN_0021d3b0(records + 0x1050, FUN_0021cca0(table1, 0x4b));
    i = 0;
    while (i < *(s32*)(work + 0x6070)) {
        FUN_0021d3b0(records + i * 0x310,
                     FUN_0021cca0(table0, 0x44));
        i++;
    }
    FUN_00224860();
}

// Previous body was a wrong-helper stub unrelated to retail (2128B window).
// Rewritten from disasm: retail computes a safe float-to-byte alpha via
// a magic-2^31 overflow-guarded cast, draws two frame quads, an N-slot
// overlay strip with a per-record colour switch, then (mode==3 only) a
// pair of icon draws whose x/y scale differs between the mode-0 (shift)
// and mode-1/2 (float multiply) paths despite sharing constants. obj
// 356B->2096B/2128B (98.5%); register-agnostic content-diff confirms
// correct call sequence/offsets/constants throughout. Residual is a
// handful of register-bank/scheduling floors, the largest being that
// the alpha byte does not keep a persistent register as far into the
// function as retail's build does at the two mode==3 tail call sites.
// FUN_00224860
void FUN_00224860(void)
{
    u8* base;
    u8* records;
    s32 i;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = (u8*)sBcmPanel;
    FUN_0021c3f0(0);
    records = base + 0x4660;
    K_ASSERT((*(u32*)(base + 4) & 8) != 0, 0x88e);
    for (i = 0; i < *(s32*)(base + 0x6070); ++i) {
        u8* record = records + i * 0x310;
        FUN_00238980(record + 0x100, 2, *(u32*)(record + 0x304), 1);
    }
}

#pragma push
#pragma opt_dead_assignments off
// FUN_00224940 NONMATCHING
void FUN_00224940(void)
{
    u8* work;
    u8* records;
    u8* record;
    u8* sub;
    u32 table0;
    u32 table1;
    u32 table3;
    void* frame;
    f32* basePos;
    f32 weight;
    f32 alphaF;
    u8 alphaByte;
    u32 alphaU32;
    u32 defaultColour;
    u32 colour;
    f32 rect[4];
    u8 color[4];
    s32 i;
    s32 j;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    table1 = FUN_0021c3f0(1);
    table3 = FUN_0021c3f0(3);
    records = work + 0x4660;
    weight = *(f32*)(work + 0x7214);

    switch (*(u32*)(work + 0x463c)) {
    case 0:
        alphaF = (f32)(3 - *(s32*)(work + 0x4650)) / 3.0f;
        break;
    case 4:
        alphaF = (f32)*(s32*)(work + 0x4650) / 3.0f;
        break;
    default:
        K_ASSERT(0, 0x8b3);
        break;
    }
    alphaByte = (u8)(u32)(255.0f * alphaF * weight);

    basePos = (f32*)(work + 0x6050);

    frame = (void*)FUN_0021cca0(table0, 0x24);
    rect[0] = 47.0f + basePos[0];
    rect[1] = 19.0f + basePos[1] +
              (f32)(*(s32*)(work + 0x6068) - *(s32*)(work + 0x606c)) * 26.0f;
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(work + 0x4230, rect);

    frame = (void*)FUN_0021cca0(table0, 0x24);
    rect[0] = 47.0f + basePos[0] + (f32)*(s32*)((u8*)frame + 0xc);
    rect[1] = 19.0f + basePos[1] +
              (f32)(*(s32*)(work + 0x6068) - *(s32*)(work + 0x606c)) * 26.0f;
    rect[2] = 312.0f;
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(work + 0x4330, rect);

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = alphaByte;
    FUN_0021d950(work + 0x4230, color);
    FUN_0021d950(work + 0x4330, color);

    alphaU32 = (u32)alphaByte;
    defaultColour = 0xffffff00u | alphaU32;

    for (i = 0; i < *(s32*)(work + 0x6070); ++i) {
        record = records + i * 0x310;
        sub = *(u8**)(record + 0x300);

        rect[0] = 143.0f + basePos[0];
        rect[1] = 19.0f + basePos[1] + (f32)(i * 26);

        if (*(void**)(sub + 0x1c) != NULL) {
            colour = (*(u32*)(*(u8**)(sub + 0x1c) + 0x10) & 0xffffff00u) | alphaU32;
        } else {
            colour = defaultColour;
        }

        FUN_003b0d70((u32)sub, (s32)rect[0] << 4, (s32)rect[1] << 3);
        FUN_003b0e20((u32)sub, colour);

        frame = (void*)FUN_0021cca0(table0, 0x44);
        rect[0] = 59.0f + basePos[0];
        rect[1] = 30.0f + basePos[1] + (f32)(i * 26);
        rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
        rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
        FUN_0021d8e0(record, rect);

        if (i == *(s32*)(work + 0x6068) - *(s32*)(work + 0x606c)) {
            color[0] = 0xf5;
            color[1] = 0xf5;
            color[2] = 0xff;
        } else {
            color[0] = 0x5a;
            color[1] = 0x5a;
            color[2] = 0x5a;
        }
        color[3] = alphaByte;
        FUN_0021d950(record, color);

        rect[0] = 95.0f + basePos[0];
        rect[1] = 30.0f + basePos[1] + (f32)(i * 26);
        FUN_00238dc0(record + 0x100, 2, *(u32*)(record + 0x304), 1, rect);

        if (i == *(s32*)(work + 0x6068) - *(s32*)(work + 0x606c)) {
            color[0] = 0xff;
            color[1] = 0xff;
            color[2] = 0xff;
        } else {
            color[0] = 0x5a;
            color[1] = 0x5a;
            color[2] = 0x5a;
        }
        color[3] = alphaByte;

        for (j = 0; j < 2; ++j) {
            FUN_0021d950(record + j * 0x100 + 0x100, color);
        }
    }

    frame = (void*)FUN_0021cca0(table3, 0x13);
    rect[0] = 264.0f + basePos[0];
    rect[1] = 126.0f + basePos[1];
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(records + 0xf50, rect);
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = alphaByte;
    FUN_0021d950(records + 0xf50, color);

    frame = (void*)FUN_0021cca0(table1, 0x4b);
    rect[0] = 287.0f + basePos[0];
    rect[1] = 126.0f + basePos[1];
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(records + 0x1050, rect);
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = alphaByte;
    FUN_0021d950(records + 0x1050, color);
}
#pragma pop
#pragma opt_dead_assignments reset

// FUN_00225040 NONMATCHING
void FUN_00225040(void)
{
    u8* work;
    u8* records;
    u8* record;
    u8* quadTarget;
    u32 table0;
    u32 table1;
    u32 table3;
    u32 resource;
    u32 texture;
    s32 i;
    s32 j;
    void (**setState)(u32, u32);
    void (**setQuad)(u32*, u32, u32, u32, u32);

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    table1 = FUN_0021c3f0(1);
    table3 = FUN_0021c3f0(3);
    records = work + 0x4660;

    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);

    resource = FUN_0021cca0(table0, 0x23);
    setState = (void (**)(u32, u32))D_00960090_abs;
    texture = FUN_0021cce0(resource);
    (*setState)(1, texture);

    setQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
    (*setQuad)((u32*)(work + 0x4230), 4, 0, 1, 2);
    (*setQuad)((u32*)(work + 0x4230), 4, 0, 2, 3);
    (*setQuad)((u32*)(work + 0x4330), 4, 0, 1, 2);
    (*setQuad)((u32*)(work + 0x4330), 4, 0, 2, 3);

    for (i = 0; i < *(s32*)(work + 0x6070); ++i) {
        record = records + i * 0x310;
        func_003b1360(*(u32*)(record + 0x300), 1, 0);
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);

        resource = FUN_0021cca0(table0, 0x44);
        texture = FUN_0021cce0(resource);
        (*setState)(1, texture);

        (*setQuad)((u32*)record, 4, 0, 1, 2);
        (*setQuad)((u32*)record, 4, 0, 2, 3);

        texture = FUN_00239140(1);
        (*setState)(1, texture);
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);

        for (j = 0; j < 2; ++j) {
            quadTarget = record + j * 0x100 + 0x100;
            (*setQuad)((u32*)quadTarget, 4, 0, 1, 2);
            (*setQuad)((u32*)quadTarget, 4, 0, 2, 3);
        }
    }

    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);

    resource = FUN_0021cca0(table3, 0x13);
    texture = FUN_0021cce0(resource);
    (*setState)(1, texture);

    (*setQuad)((u32*)(records + 0xf50), 4, 0, 1, 2);
    (*setQuad)((u32*)(records + 0xf50), 4, 0, 2, 3);

    resource = FUN_0021cca0(table1, 0x4b);
    texture = FUN_0021cce0(resource);
    (*setState)(1, texture);

    (*setQuad)((u32*)(records + 0x1050), 4, 0, 1, 2);
    (*setQuad)((u32*)(records + 0x1050), 4, 0, 2, 3);
}

// FUN_002254A0
void FUN_002254A0(void)
{
    u8* work;
    u8* records;
    u32 table0;
    u32 current;
    u32 resource;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    records = work + 0x4660;
    table0 = FUN_0021c3f0(0);

    K_ASSERT((*(u32*)(work + 4) & 4) != 0, 0x973);

    current = *(u32*)(work + 0x6068) - *(u32*)(work + 0x606c);
    *(u32*)(records + 0x18c0) = current;
    *(u32*)(records + 0x18e0) = *(u32*)(records + current * 0x420 + 0xc);
    *(u32*)(work + 0x4630) = 4;
    *(u32*)(work + 0x4658) = 0;
    *(u32*)work |= 8;
    *(u32*)(work + 0x4644) = 1;
    FUN_00227d10();

    resource = FUN_0021cca0(table0, 0x25);
    FUN_0021d3b0(work + 0x4430, resource);

    resource = FUN_0021cca0(table0, 0x25);
    FUN_0021e380(work + 0x4530, resource, 1);

    resource = FUN_0021cca0(table0, 0x2f);
    FUN_0021d3b0(records + 0x18f0, resource);

    FUN_00225670();
}

// Previous body was a wrong-helper stub (232B) unrelated to retail (1296B
// window). Rewritten from disasm: retail does a 9-entry jump-table
// resource dispatch + per-slot D_00960090/D_0096009C_u32 indirect-vtable
// quad-draw calls (matching FUN_00229B40's style), not the guessed
// bcm_panel_* helpers. obj now 1292B/1296B; residual is a single
// register-bank choice (retail s3/mine s4 for `work`) cascading through
// the whole body - 2 declaration-order attempts had no effect (floor).
/* W389 measured opt_lifetimes on: nd562/1296B -> nd217/1280B (window 1296B). */
// FUN_002255F0
void FUN_002255F0(void)
{
    u32* puVar1;
    u32 uVar2;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    puVar1 = sBcmPanel;
    uVar2 = FUN_0021c3f0(0);
    puVar1[0x118c] = 5;
    puVar1[0x1196] = 0;
    puVar1[0] |= 8;
    puVar1[0x1191] = 0;
    puVar1[0x1192] = 1;
}

// FUN_00225670 MATCHING
void FUN_00225670(void)
{
    u8* work;
    u8* overlay0;
    u8* overlayI;
    u32 table0;
    u32 resource;
    void* frame;
    f32 rect[8];
    f32 scale;
    f32 value;
    f32 offsetY;
    s32 i;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    overlay0 = work + 0x6080;

    for (i = 0; i < *(s32*)(overlay0 + 0x55c); ++i) {
        resource = FUN_0021cca0(table0, 0x29);
        overlayI = overlay0 + i * 0x110;
        FUN_0021d3b0(overlayI + 0x10, resource);
    }

    frame = (void*)FUN_0021cca0(table0, 0x1d);
    {
        s32 count = *(s32*)(overlay0 + 0x55c);
        s32 progress = *(s32*)(overlay0 + 0x550);
        if (count < progress) {
            value = (f32)*(s32*)(overlay0 + 0x558);
            scale = 55.0f;
            offsetY = 36.0f + (value * scale) / (f32)(progress - count);
        } else {
            offsetY = 36.0f;
        }
    }
    rect[0] = 60.0f;
    rect[1] = 237.0f + offsetY;
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(work + 0x3730, rect);
}

// FUN_002257F0 NONMATCHING
void FUN_002257F0(void)
{
    u8* work;
    u8* overlay0;
    u8* overlayI;
    f32* posB;
    f32* posA;
    f32 weight;
    u32 table0;
    u32 mode;
    f32 ratio;
    f32 alphaF;
    u8 alphaByte;
    u8 color[4];
    void* frame;
    f32 rect[4];
    f32 baseX;
    u32 resource1;
    u32 colour0;
    u32 colour1;
    u32 colour2;
    u32 colour3;
    u32 colour4;
    u32 obj1;
    u32 obj2;
    s32 i;
    u32 state;
    u32 colour;
    s32 diffY;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    overlay0 = work + 0x6080;
    weight = *(f32*)(work + 0x7214);
    posB = (f32*)(work + 0x6058);
    posA = (f32*)(work + 0x6050);

    mode = *(u32*)(work + 0x4644);
    switch (mode) {
    case 1:
    case 2:
        ratio = (f32)*(s32*)(work + 0x4658) / 6.0f;
        break;
    case 0:
        ratio = (f32)(6 - *(s32*)(work + 0x4658)) / 6.0f;
        break;
    default:
        K_ASSERT(0, 0x9e0);
        break;
    }

    alphaF = 255.0f * ratio * weight;
    alphaByte = (u8)alphaF;

    frame = (void*)FUN_0021cca0(table0, 0x24);
    rect[0] = 47.0f + posB[0];
    rect[1] = 19.0f + posB[1] +
              (f32)((*(s32*)(overlay0 + 0x554) - *(s32*)(overlay0 + 0x558)) * 26);
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(work + 0x4430, rect);

    frame = (void*)FUN_0021cca0(table0, 0x24);
    baseX = 47.0f + posB[0];
    baseX += (f32)*(s32*)((u8*)frame + 0xc);
    rect[0] = baseX;
    rect[1] = 19.0f + posB[1] +
              (f32)((*(s32*)(overlay0 + 0x554) - *(s32*)(overlay0 + 0x558)) * 26);
    rect[2] = 276.0f;
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(work + 0x4530, rect);

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = alphaByte;
    FUN_0021d950(work + 0x4430, color);
    FUN_0021d950(work + 0x4530, color);

    i = 0;
    colour0 = (u32)alphaByte | 0xffffff00u;
    colour1 = (u32)alphaByte | 0xcccccc00u;
    colour2 = (u32)alphaByte | 0xbeffd200u;
    colour3 = (u32)alphaByte | 0x64cc6400u;
    colour4 = ((s32)((u32)alphaByte * 50) / 100) | 0xffffff00u;

    for (; i < *(s32*)(overlay0 + 0x55c); ++i) {
        overlayI = overlay0 + i * 0x110;
        resource1 = *(u32*)(overlayI + 4);

        rect[0] = 103.0f + posB[0];
        diffY = i * 26;
        rect[1] = 19.0f + posB[1] + (f32)diffY;
        FUN_003b0d70(resource1, (s32)rect[0] << 4, (s32)rect[1] << 3);

        state = *(u32*)overlayI;
        switch (state) {
        case 0:
            if (i == *(s32*)(overlay0 + 0x554) - *(s32*)(overlay0 + 0x558)) {
                colour = colour0;
            } else {
                colour = colour1;
            }
            break;
        case 2:
            if (i == *(s32*)(overlay0 + 0x554) - *(s32*)(overlay0 + 0x558)) {
                colour = colour2;
            } else {
                colour = colour3;
            }
            break;
        case 1:
            colour = colour4;
            break;
        }
        FUN_003b0e20(resource1, colour);

        frame = (void*)FUN_0021cca0(table0, 0x29);
        rect[0] = 86.0f + posB[0];
        rect[1] = 29.0f + posB[1] + (f32)diffY;
        rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
        rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
        FUN_0021d8e0(overlayI + 0x10, rect);

        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = alphaByte;
        FUN_0021d950(overlayI + 0x10, color);
    }

    switch (*(u32*)(work + 0x463c)) {
    case 3:
        mode = *(u32*)(work + 0x4644);
        switch (mode) {
        case 0:
            if (*(u32*)(work + 0x4648) == 1 || *(u32*)(work + 0x4648) == 2) {
                if (*(s32*)(work + 0x4658) < 6) {
                    K_ASSERT((*(u32*)(work + 4) & 4) != 0, 0xa38);

                    obj1 = *(u32*)(overlay0 + 0x560);
                    colour = (u32)alphaByte | 0xff9d9d00u;
                    FUN_003b0e20(obj1, colour);

                    rect[0] = 171.0f + posA[0];
                    rect[1] = 19.0f + posA[1];
                    FUN_003b0d70(obj1, (s32)rect[0] << 4, (s32)rect[1] << 3);

                    obj2 = *(u32*)(overlay0 + 0x564);
                    if (obj2 != 0) {
                        colour = (u32)alphaByte | 0xffffff00u;
                        FUN_003b0e20(obj2, colour);

                        rect[0] = 171.0f + posA[0] + 27.0f;
                        rect[1] = 19.0f + posA[1] + 26.0f;
                        FUN_003b0d70(obj2, (s32)rect[0] << 4, (s32)rect[1] << 3);
                    }
                }
            }
            break;
        case 1:
        case 2:
            obj1 = *(u32*)(overlay0 + 0x560);
            colour = (u32)alphaByte | 0xff9d9d00u;
            FUN_003b0e20(obj1, colour);

            rect[0] = 171.0f + posA[0];
            rect[1] = 19.0f + posA[1];
            FUN_003b0d70(obj1, (s32)(rect[0] * 16.0f), (s32)(rect[1] * 8.0f));

            obj2 = *(u32*)(overlay0 + 0x564);
            if (obj2 != 0) {
                colour = (u32)alphaByte | 0xffffff00u;
                FUN_003b0e20(obj2, colour);

                rect[0] = 171.0f + posA[0] + 27.0f;
                rect[1] = 19.0f + posA[1] + 26.0f;
                FUN_003b0d70(obj2, (s32)rect[0] << 4, (s32)rect[1] << 3);
            }
            break;
        }
        break;
    }
}

// Previous body was a wrong-helper stub unrelated to retail (1168B window).
// Rewritten from disasm: retail sets a fixed initial vtable state(9,2),
// draws a 6-slot resource strip, then 4 single quads reusing/refreshing
// the vtable casts per retail's own re-materialization points, a 4-slot
// double-quad loop, then a final 2-quad pair - all via the established
// D_00960090_abs/D_0096009C_abs style. nd 198->16 (obj 1156B/1168B);
// residual is a table0/loop-counter register-bank swap, unfixable per
// the usual declaration-order floor (2 attempts tried).
// FUN_00226040
void FUN_00226040(void)
{
    u8* work;
    u8* overlay0;
    u8* overlayI;
    u32 table0;
    u32 resource;
    u32 texture;
    s32 i;
    void (**setState)(u32, u32);
    void (**setQuad)(u32*, u32, u32, u32, u32);
    void (**setQuad2)(u32*, u32, u32, u32, u32);
    void (**setQuad3)(u32*, u32, u32, u32, u32);

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    overlay0 = work + 0x6080;

    resource = FUN_0021cca0(table0, 0x23);
    setState = (void (**)(u32, u32))D_00960090_abs;
    texture = FUN_0021cce0(resource);
    (*setState)(1, texture);

    setQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
    (*setQuad)((u32*)(work + 0x4430), 4, 0, 1, 2);
    (*setQuad)((u32*)(work + 0x4430), 4, 0, 2, 3);
    (*setQuad)((u32*)(work + 0x4530), 4, 0, 1, 2);
    (*setQuad)((u32*)(work + 0x4530), 4, 0, 2, 3);

    for (i = 0; i < *(s32*)(overlay0 + 0x55c); ++i) {
        overlayI = overlay0 + i * 0x110;
        func_003b1360(*(u32*)(overlayI + 4), 1, 0);

        resource = FUN_0021cca0(table0, 0x29);
        texture = FUN_0021cce0(resource);
        (*setState)(1, texture);
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);

        setQuad2 = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
        (*setQuad2)((u32*)(overlayI + 0x10), 4, 0, 1, 2);
        (*setQuad2)((u32*)(overlayI + 0x10), 4, 0, 2, 3);
    }

    if (*(s32*)(overlay0 + 0x55c) < *(s32*)(overlay0 + 0x550)) {
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);

        resource = FUN_0021cca0(table0, 0x1d);
        texture = FUN_0021cce0(resource);
        (*setState)(1, texture);

        setQuad3 = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
        (*setQuad3)((u32*)(work + 0x3730), 4, 0, 1, 2);
        (*setQuad3)((u32*)(work + 0x3730), 4, 0, 2, 3);
    }
}

// FUN_00226320
void FUN_00226320(void)
{
    u32 table;
    u8* base;
    u32 state;
    s32 i;
    u32 resource;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = (u8*)sBcmPanel;
    table = FUN_0021c3f0(0);
    state = *(u32*)(base + 0x7210);
    if (state == 2) {
        goto panel_setup;
    }
    if (state == 1) {
        goto panel_setup;
    }
    switch (state) {
    case 0:
        goto panel_setup;
    default:
        goto panel_tail;
    }
panel_setup:
    FUN_0021d3b0(base + 0x1530, FUN_0021cca0(table, 0x1e));
    FUN_0021d3b0(base + 0x1630, FUN_0021cca0(table, 0x1f));
    FUN_0021d3b0(base + 0x1730, FUN_0021cca0(table, 0x20));
    FUN_0021d3b0(base + 0x1830, FUN_0021cca0(table, 0x21));
    FUN_0021e380(base + 0x1930, FUN_0021cca0(table, 0x1e), 1);
    FUN_0021e380(base + 0x1a30, FUN_0021cca0(table, 0x1f), 1);
    FUN_0021e380(base + 0x1b30, FUN_0021cca0(table, 0x1f), 0);
    FUN_0021e380(base + 0x1c30, FUN_0021cca0(table, 0x21), 0);
    FUN_0021e380(base + 0x1d30, FUN_0021cca0(table, 0x1f), 4);
panel_tail:
    FUN_0021d3b0(base + 0x2130, FUN_0021cca0(table, 0x1d));
    FUN_0021d3b0(base + 0x1e30, FUN_0021cca0(table, 0x26));
    FUN_0021d3b0(base + 0x1f30, FUN_0021cca0(table, 0x27));
    FUN_0021e380(base + 0x2030, FUN_0021cca0(table, 0x26), 2);
    resource = FUN_0021cca0(table, 0x2c);
    for (i = 0; i < 6; ++i) {
        u8* slot = base + i * 0x200;
        FUN_0021d3b0(slot + 0x2230, resource);
        FUN_0021e380(slot + 0x2330, resource, 1);
    }
}


// FUN_002265D0 NONMATCHING
void FUN_002265D0(void)
{
    typedef struct {
        u8 pad_00[0xc];
        s32 width;
        s32 height;
    } BcmPanelResource;
    u8* work;
    u32 table0;
    BcmPanelResource* resource;
    f32 rect[4];
    u8 color[4];
    s32 i;
    s32 j;
    f32 stateAlpha;
    f32 transAlpha;
    f32 rowOffset;
    f32 rowStep;
    f32 ratio;
    f32 y150;
    f32 panelAlpha;
    f32 baseX;
    f32 baseY;
    f32 quadBaseX;
    f32 quadBaseY;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    panelAlpha = *(f32*)(work + 0x7214);
    rowOffset = -26.0f * (f32)*(s32*)(work + 0x7210);
    rowStep = 26.0f * (f32)*(s32*)(work + 0x7210);

    if (*(u32*)(work + 0x463c) == 3) {
        if (*(u32*)(work + 0x4644) == 1 || *(u32*)(work + 0x4644) == 2) {
            transAlpha = (f32)*(s32*)(work + 0x4658) / 6.0f;
            rect[0] = 38.0f + -191.0f * transAlpha;
            rect[1] = 237.0f + -66.0f * transAlpha;
        } else if (*(u32*)(work + 0x4644) == 0 &&
                   (*(u32*)(work + 0x4648) == 1 || *(u32*)(work + 0x4648) == 2) &&
                   *(s32*)(work + 0x4658) < 6) {
            transAlpha = (f32)*(s32*)(work + 0x4658) / 6.0f;
            rect[0] = -153.0f + 191.0f * transAlpha;
            rect[1] = 171.0f + 66.0f * transAlpha;
        } else {
            f32 f2 = (f32)*(s32*)(work + 0x4650);
            rect[0] = (38.0f * f2) / 3.0f;
            rect[1] = 277.0f + (-40.0f * f2) / 3.0f;
        }
    } else if (*(u32*)(work + 0x463c) == 0) {
        f32 f3 = (f32)*(s32*)(work + 0x4650);
        rect[0] = 38.0f + (-38.0f * f3) / 3.0f;
        rect[1] = 237.0f + (40.0f * f3) / 3.0f;
    } else if (*(u32*)(work + 0x463c) == 4 || *(u32*)(work + 0x463c) == 1 ||
               *(u32*)(work + 0x463c) == 2) {
        f32 f2 = (f32)*(s32*)(work + 0x4650);
        rect[0] = (38.0f * f2) / 3.0f;
        rect[1] = 277.0f + (-40.0f * f2) / 3.0f;
    }

    if (*(u32*)(work + 0x463c) == 3) {
        stateAlpha = (f32)*(s32*)(work + 0x4650) / 3.0f;
    } else if (*(u32*)(work + 0x463c) == 0) {
        stateAlpha = (f32)((3 - *(s32*)(work + 0x4650)) / 3);
    } else if (*(u32*)(work + 0x463c) == 4 || *(u32*)(work + 0x463c) == 1 ||
               *(u32*)(work + 0x463c) == 2) {
        stateAlpha = (f32)*(s32*)(work + 0x4650) / 3.0f;
    }

    if (*(u32*)(work + 0x463c) == 3) {
        if (*(u32*)(work + 0x4644) == 0) {
            if ((*(u32*)(work + 0x4648) == 1 || *(u32*)(work + 0x4648) == 2) &&
                *(s32*)(work + 0x4658) < 6) {
                transAlpha = (f32)*(s32*)(work + 0x4658) / 6.0f;
            } else {
                transAlpha = 1.0f;
            }
        } else if (*(u32*)(work + 0x4644) == 1 || *(u32*)(work + 0x4644) == 2) {
            transAlpha = (f32)(6 - *(s32*)(work + 0x4658)) / 6.0f;
        } else {
            transAlpha = 1.0f;
        }
    } else {
        transAlpha = 1.0f;
    }

    {
        f32 complement = 1.0f - transAlpha;
        f32 negRowOffset = -rowOffset;
        rect[1] = rect[1] + complement * negRowOffset;
        rect[1] = rect[1] + rowOffset;
    }
    baseX = rect[0];
    baseY = rect[1];
    *(f32*)(work + 0x6050) = rect[0];
    *(f32*)(work + 0x6054) = rect[1];

    {
        y150 = 150.0f + rowStep;
        for (i = 0; i < 9; ++i) {
            switch (i) {
            case 0: case 1: case 2: case 3:
                resource = (BcmPanelResource*)FUN_0021cca0(table0, i + 0x1e);
                break;
            case 4: case 5:
                resource = (BcmPanelResource*)FUN_0021cca0(table0, i + 0x1a);
                break;
            }
            rect[0] = baseX;
            rect[1] = baseY;
            switch (i) {
            case 0: rect[0] += 11.0f; rect[1] += 4.0f; break;
            case 1: rect[0] += 11.0f; rect[1] += y150; break;
            case 2: rect[0] += 241.0f; rect[1] += 4.0f; break;
            case 3: rect[0] += 241.0f; rect[1] += y150; break;
            case 4: rect[0] += 159.0f; rect[1] += 4.0f; break;
            case 5: rect[0] += 159.0f; rect[1] += y150; break;
            case 6: rect[0] += 11.0f; rect[1] += 75.0f; break;
            case 7: rect[0] += 241.0f; rect[1] += 75.0f; break;
            case 8: rect[0] += 159.0f; rect[1] += 75.0f; break;
            }
            switch (i) {
            case 0: case 1: case 2: case 3:
                rect[2] = (f32)resource->width;
                rect[3] = (f32)resource->height;
                break;
            case 4: case 5:
                rect[2] = 82.0f;
                rect[3] = (f32)resource->height;
                break;
            case 6: case 7:
                rect[2] = (f32)resource->width;
                rect[3] = rowStep;
                break;
            case 8:
                rect[2] = 82.0f;
                rect[3] = rowStep;
                break;
            }
            FUN_0021d8e0(work + i * 0x100 + 0x1530, rect);
        }
    }

    ratio = 40.0f + 215.0f * transAlpha;
    color[0] = (u8)ratio;
    color[1] = (u8)ratio;
    ratio = 30.0f + 225.0f * transAlpha;
    color[2] = (u8)ratio;
    ratio = stateAlpha * (255.0f * (80.0f + 20.0f * transAlpha) / 100.0f) * panelAlpha;
    color[3] = (u8)ratio;
    for (i = 0; i < 9; ++i) {
        FUN_0021d950(work + i * 0x100 + 0x1530, color);
    }

    resource = (BcmPanelResource*)FUN_0021cca0(table0, 0x26);
    {
        rect[0] = 20.0f + baseX;
        rect[1] = 32.0f + baseY - 4.0f;
        rect[2] = (f32)resource->width;
        rect[3] = (f32)resource->height;
        FUN_0021d8e0(work + 0x1e30, rect);

        resource = (BcmPanelResource*)FUN_0021cca0(table0, 0x27);
        rect[0] = 20.0f + baseX;
        rect[1] = 102.0f + baseY + rowStep;
        rect[2] = (f32)resource->width;
        rect[3] = (f32)resource->height;
        FUN_0021d8e0(work + 0x1f30, rect);

        resource = (BcmPanelResource*)FUN_0021cca0(table0, 0x26);
        rect[0] = 20.0f + baseX;
        rect[1] = 16.0f + (32.0f + baseY) - 4.0f;
        rect[2] = (f32)resource->width;
        rect[3] = 57.0f + rowStep;
        FUN_0021d8e0(work + 0x2030, rect);

        resource = (BcmPanelResource*)FUN_0021cca0(table0, 0x1d);
        {
            f32 top = (36.0f + baseY + rowOffset) - 4.0f;
            f32 bottom = 91.0f + baseY + rowOffset;
            rect[0] = 22.0f + baseX;
            if (*(s32*)(work + 0x6074) >= 5) {
                f32 t = (f32)*(s32*)(work + 0x606c);
                f32 range = bottom - top;
                f32 denom = (f32)(*(s32*)(work + 0x6074) - 4);
                rect[1] = top + (t * range) / denom;
            } else {
                rect[1] = top;
            }
            rect[2] = (f32)resource->width;
            rect[3] = (f32)resource->height;
            FUN_0021d8e0(work + 0x2130, rect);
        }
    }

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    ratio = 255.0f * stateAlpha * panelAlpha;
    color[3] = (u8)ratio;
    for (i = 0; i < 3; ++i) {
        FUN_0021d950(work + i * 0x100 + 0x1e30, color);
    }
    FUN_0021d950(work + 0x2130, color);

    resource = (BcmPanelResource*)FUN_0021cca0(table0, 0x2c);
    quadBaseX = 47.0f + baseX;
    quadBaseY = 43.0f + baseY;
    {
        for (j = 0; j < 6; ++j) {
            u8* slot = work + j * 0x200;
            f32 quadY = quadBaseY + (f32)(j * 26);
            rect[0] = quadBaseX;
            rect[1] = quadY;
            rect[2] = (f32)resource->width;
            rect[3] = (f32)resource->height;
            FUN_0021d8e0(slot + 0x2230, rect);

            rect[0] = quadBaseX + (f32)resource->width;
            rect[1] = quadY;
            rect[2] = 311.0f;
            rect[3] = (f32)resource->height;
            FUN_0021d8e0(slot + 0x2330, rect);
        }
    }
    if (*(u32*)(work + 0x463c) == 3) {
        if (*(u32*)(work + 0x4644) == 0) {
            if ((*(u32*)(work + 0x4648) == 1 || *(u32*)(work + 0x4648) == 2) &&
                *(s32*)(work + 0x4658) < 6) {
                transAlpha = (f32)*(s32*)(work + 0x4658) / 6.0f;
            } else {
                transAlpha = 1.0f;
            }
        } else if (*(u32*)(work + 0x4644) == 1 || *(u32*)(work + 0x4644) == 2) {
            transAlpha = (f32)(6 - *(s32*)(work + 0x4658)) / 6.0f;
        } else {
            transAlpha = 1.0f;
        }
    } else {
        transAlpha = 1.0f;
    }

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    ratio = (f32)(u8)(30.0f + 225.0f * transAlpha) * 2.0f *
            stateAlpha * panelAlpha;
    color[3] = (u8)ratio;
    for (j = 0; j < 2; ++j) {
        u8* slot = work + j * 0x200;
        FUN_0021d950(slot + 0x2230, color);
        FUN_0021d950(slot + 0x2330, color);
    }

    ratio = (f32)(u8)(255.0f * transAlpha) * 2.0f *
            stateAlpha * panelAlpha;
    color[3] = (u8)ratio;
    for (j = 2; j < 6; ++j) {
        u8* slot = work + j * 0x200;
        FUN_0021d950(slot + 0x2230, color);
        FUN_0021d950(slot + 0x2330, color);
    }
}

/* W389 measured opt_loop_invariants on: nd1997/2852B -> nd1941/2732B (window 3024B). */
#pragma push
#pragma opt_lifetimes on
// FUN_00227800 NONMATCHING
void FUN_00227800(void)
{
    void (**setState)(u32, u32);
    u32 table0;
    u8* work;
    u32 texture;
    u32 resource;
    s32 i;
    s32 j;
    s32 loopCount;
    u8* record;
    void (**setQuad)(u32*, u32, u32, u32, u32);
    void (**setState2)(u32, u32);
    void (**setQuad2)(u32*, u32, u32, u32, u32);
    void (**setQuad3)(u32*, u32, u32, u32, u32);

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);

    for (i = 0; i < 9; i++) {
        switch (i) {
        case 0: case 1: case 2: case 3:
            resource = FUN_0021cca0(table0, i + 0x1e);
            break;
        case 4: case 5:
            resource = FUN_0021cca0(table0, i + 0x1a);
            break;
        case 6:
            resource = FUN_0021cca0(table0, 0x1f);
            break;
        case 7:
            resource = FUN_0021cca0(table0, 0x21);
            break;
        case 8:
            resource = FUN_0021cca0(table0, 0x1f);
            break;
        }
        texture = FUN_0021cce0(resource);
        setState = (void (**)(u32, u32))D_00960090_abs;
        (*setState)(1, texture);
        record = work + i * 0x100 + 0x1530;
        setQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
        (*setQuad)((u32*)record, 4, 0, 1, 2);
        (*setQuad)((u32*)record, 4, 0, 2, 3);
    }

    resource = FUN_0021cca0(table0, 0x26);
    setState2 = (void (**)(u32, u32))D_00960090_abs;
    (*setState2)(1, FUN_0021cce0(resource));
    setQuad2 = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
    (*setQuad2)((u32*)(work + 0x1e30), 4, 0, 1, 2);
    (*setQuad2)((u32*)(work + 0x1e30), 4, 0, 2, 3);

    resource = FUN_0021cca0(table0, 0x27);
    (*setState2)(1, FUN_0021cce0(resource));
    (*setQuad2)((u32*)(work + 0x1f30), 4, 0, 1, 2);
    (*setQuad2)((u32*)(work + 0x1f30), 4, 0, 2, 3);

    resource = FUN_0021cca0(table0, 0x26);
    (*setState2)(1, FUN_0021cce0(resource));
    (*setQuad2)((u32*)(work + 0x2030), 4, 0, 1, 2);
    (*setQuad2)((u32*)(work + 0x2030), 4, 0, 2, 3);

    if (*(u32*)(work + 0x463c) != 3 && *(s32*)(work + 0x6074) >= 5) {
        resource = FUN_0021cca0(table0, 0x1d);
        (*setState2)(1, FUN_0021cce0(resource));
        (*setQuad2)((u32*)(work + 0x2130), 4, 0, 1, 2);
        (*setQuad2)((u32*)(work + 0x2130), 4, 0, 2, 3);
    }

    resource = FUN_0021cca0(table0, 0x2c);
    (*setState2)(1, FUN_0021cce0(resource));

    switch (*(u32*)(work + 0x7210)) {
    case 0:
        loopCount = 4;
        break;
    case 1:
        loopCount = 5;
        break;
    case 2:
        loopCount = 6;
        break;
    }

    setQuad3 = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
    for (j = 0; j < loopCount; j++) {
        record = work + (j << 9);
        (*setQuad3)((u32*)(record + 0x2230), 4, 0, 1, 2);
        (*setQuad3)((u32*)(record + 0x2230), 4, 0, 2, 3);
        (*setQuad3)((u32*)(record + 0x2330), 4, 0, 1, 2);
        (*setQuad3)((u32*)(record + 0x2330), 4, 0, 2, 3);
    }
}
#pragma pop
#pragma opt_lifetimes reset


// FUN_00227D10
void FUN_00227D10(void)
{
    s32 i;
    u8* base;
    u32 table;
    u32 resource;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = (u8*)sBcmPanel;
    table = FUN_0021c3f0(0);
    FUN_0021d3b0(base + 0x2e30, FUN_0021cca0(table, 0x1e));
    FUN_0021d3b0(base + 0x2f30, FUN_0021cca0(table, 0x1f));
    FUN_0021d3b0(base + 0x3030, FUN_0021cca0(table, 0x20));
    FUN_0021d3b0(base + 0x3130, FUN_0021cca0(table, 0x21));
    FUN_0021e380(base + 0x3230, FUN_0021cca0(table, 0x1e), 1);
    FUN_0021e380(base + 0x3330, FUN_0021cca0(table, 0x1f), 1);
    FUN_0021d3b0(base + 0x3730, FUN_0021cca0(table, 0x1d));
    FUN_0021d3b0(base + 0x3430, FUN_0021cca0(table, 0x26));
    FUN_0021d3b0(base + 0x3530, FUN_0021cca0(table, 0x27));
    FUN_0021e380(base + 0x3630, FUN_0021cca0(table, 0x26), 2);
    resource = FUN_0021cca0(table, 0x2c);
    for (i = 0; i < 5; ++i) {
        u8* record = base + (i << 9);
        FUN_0021d3b0(record + 0x3830, resource);
        FUN_0021e380(record + 0x3930, resource, 1);
    }
}




























// FUN_00227F30 NONMATCHING
void FUN_00227F30(void)
{
    u8* work;
    u32 table0;
    void* resource;
    f32 baseX;
    f32 baseY;
    f32 x;
    f32 y;
    f32 rect[4];
    u8 color[4];
    s32 i;
    s32 j;
    f32 alpha1;
    u8 alphaByte;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    baseX = 38.0f;
    baseY = 237.0f;
    *(f32*)(work + 0x6058) = baseX;
    *(f32*)(work + 0x605c) = baseY;

    for (i = 0; i < 6; ++i) {
        switch (i) {
        case 0: case 1: case 2: case 3:
            resource = (void*)FUN_0021cca0(table0, i + 0x1e);
            break;
        case 4: case 5:
            resource = (void*)FUN_0021cca0(table0, i + 0x1a);
            break;
        }
        x = baseX;
        y = baseY;
        switch (i) {
        case 0: x += 11.0f; y += 4.0f; break;
        case 1: x += 11.0f; y += 75.0f; break;
        case 2: x += 201.0f; y += 4.0f; break;
        case 3: x += 201.0f; y += 75.0f; break;
        case 4: x += 11.0f + (f32)*(s32*)((u8*)resource + 0xc); y += 4.0f; break;
        case 5: x += 11.0f + (f32)*(s32*)((u8*)resource + 0xc); y += 75.0f; break;
        }
        rect[0] = x;
        rect[1] = y;
        switch (i) {
        case 0: case 1: case 2: case 3:
            rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
            rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
            break;
        case 4: case 5:
            rect[2] = 42.0f;
            rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
            break;
        }
        FUN_0021d8e0(work + i * 0x100 + 0x2e30, rect);
    }

    if (*(u32*)(work + 0x463c) == 0) {
        alpha1 = (f32)(3 - *(s32*)(work + 0x4650)) / 3.0f;
    } else if (*(u32*)(work + 0x463c) == 1 || *(u32*)(work + 0x463c) == 2) {
        alpha1 = (f32)*(s32*)(work + 0x4650) / 3.0f;
    } else if (*(u32*)(work + 0x463c) == 3) {
        if (*(u32*)(work + 0x4644) == 0) {
            if (*(s32*)(work + 0x4658) == 6) {
                alpha1 = 1.0f;
            } else {
                alpha1 = (f32)(6 - *(s32*)(work + 0x4658)) / 6.0f;
            }
        } else if (*(u32*)(work + 0x4644) == 1 || *(u32*)(work + 0x4644) == 2) {
            alpha1 = (f32)*(s32*)(work + 0x4658) / 6.0f;
        }
    }
    alphaByte = (u8)(u32)(255.0f * alpha1 * *(f32*)(work + 0x7214));

    if (*(u32*)(work + 0x4644) == 0) {
        u8 percent = (u8)((*(s32*)(work + 0x4658) * 255) / 6);
        color[0] = percent;
        color[1] = percent;
        color[2] = percent;
    } else if (*(u32*)(work + 0x4644) == 1 || *(u32*)(work + 0x4644) == 2) {
        u8 percent = (u8)(((6 - *(s32*)(work + 0x4658)) * 255) / 6);
        color[0] = percent;
        color[1] = percent;
        color[2] = percent;
    }
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = alphaByte;
    for (i = 0; i < 6; ++i) {
        FUN_0021d950(work + i * 0x100 + 0x2e30, color);
    }

    resource = (void*)FUN_0021cca0(table0, 0x26);
    x = 20.0f + baseX;
    y = 32.0f + baseY;
    rect[0] = x;
    rect[1] = y;
    rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
    rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
    FUN_0021d8e0(work + 0x3430, rect);

    resource = (void*)FUN_0021cca0(table0, 0x27);
    rect[0] = x;
    rect[1] = 102.0f + baseY;
    rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
    rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
    FUN_0021d8e0(work + 0x3530, rect);

    resource = (void*)FUN_0021cca0(table0, 0x26);
    rect[0] = x;
    rect[1] = 16.0f + y;
    rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
    rect[3] = 54.0f;
    FUN_0021d8e0(work + 0x3630, rect);

    resource = (void*)FUN_0021cca0(table0, 0x1d);
    {
        f32 top = (36.0f + baseY) - 3.0f;
        f32 bottom = (91.0f + baseY) - 3.0f;
        rect[0] = 22.0f + baseX;
        if (*(s32*)(work + 0x6074) >= 5) {
            f32 t = (f32)*(s32*)(work + 0x606c);
            f32 range = bottom - top;
            f32 denom = (f32)(*(s32*)(work + 0x6074) - 4);
            rect[1] = top + (t * range) / denom;
        } else {
            rect[1] = top;
        }
    }
    rect[2] = (f32)(*(s32*)((u8*)resource + 0xc) * 5);
    rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;

    if (*(u32*)(work + 0x463c) == 0) {
        alpha1 = (f32)(3 - *(s32*)(work + 0x4650)) / 3.0f;
    } else if (*(u32*)(work + 0x463c) == 1 || *(u32*)(work + 0x463c) == 2 ||
               *(u32*)(work + 0x463c) == 3) {
        alpha1 = (f32)*(s32*)(work + 0x4650) / 3.0f;
    }
    color[3] = (u8)(u32)(255.0f * alpha1 * *(f32*)(work + 0x7214));

    for (i = 0; i < 3; ++i) {
        FUN_0021d950(work + i * 0x100 + 0x3430, color);
    }
    FUN_0021d950(work + 0x3730, color);

    resource = (void*)FUN_0021cca0(table0, 0x2c);
    x = 47.0f + baseX;
    {
        f32 y0 = 43.0f + baseY;
        for (j = 0; j < 4; ++j) {
            u8* record2 = work + j * 0x200;
            y = y0 + (f32)(j * 26);
            rect[0] = x;
            rect[1] = y;
            rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
            rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
            FUN_0021d8e0(record2 + 0x3830, rect);

            rect[0] = x + (f32)*(s32*)((u8*)resource + 0xc);
            rect[1] = y;
            rect[2] = 276.0f;
            rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
            FUN_0021d8e0(record2 + 0x3930, rect);
        }
    }

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    if (*(u32*)(work + 0x463c) == 0) {
        alpha1 = (f32)(3 - *(s32*)(work + 0x4650)) / 3.0f;
    } else if (*(u32*)(work + 0x463c) == 1 || *(u32*)(work + 0x463c) == 2 ||
               *(u32*)(work + 0x463c) == 3) {
        alpha1 = (f32)*(s32*)(work + 0x4650) / 3.0f;
    }
    color[3] = (u8)(u32)(255.0f * alpha1 * *(f32*)(work + 0x7214));

    for (j = 0; j < 4; ++j) {
        u8* record2 = work + j * 0x200;
        FUN_0021d950(record2 + 0x3830, color);
        FUN_0021d950(record2 + 0x3930, color);
    }
}

// FUN_002289B0
void FUN_002289B0(void)
{
    u8* work;
    u8* base;
    u32 table0;
    s32 i;
    u8* target;
    u8* target2;
    u32 resource;
    u32 texture;
    s32 j;
    void (**setState)(u32, u32);
    void (**setState2)(u32, u32);
    void (**setQuad)(u32*, u32, u32, u32, u32);
    void (**setQuadA)(u32*, u32, u32, u32, u32);
    void (**setQuadB)(u32*, u32, u32, u32, u32);
    void (**setQuadC)(u32*, u32, u32, u32, u32);

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);

    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(9, 2);
    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);

    for (i = 0; i < 6; ++i) {
        if (i < 4) {
            resource = FUN_0021cca0(table0, i + 0x1e);
        } else {
            resource = FUN_0021cca0(table0, i + 0x1a);
        }
        texture = FUN_0021cce0(resource);
        (*setState)(1, texture);

        target = work + i * 0x100 + 0x2e30;
        setQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
        (*setQuad)((u32*)target, 4, 0, 1, 2);
        (*setQuad)((u32*)target, 4, 0, 2, 3);
    }

    resource = FUN_0021cca0(table0, 0x26);
    setState2 = (void (**)(u32, u32))D_00960090_abs;
    texture = FUN_0021cce0(resource);
    (*setState2)(1, texture);

    setQuadA = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
    (*setQuadA)((u32*)(work + 0x3430), 4, 0, 1, 2);
    (*setQuadA)((u32*)(work + 0x3430), 4, 0, 2, 3);

    resource = FUN_0021cca0(table0, 0x27);
    texture = FUN_0021cce0(resource);
    (*setState2)(1, texture);

    (*setQuadA)((u32*)(work + 0x3530), 4, 0, 1, 2);
    (*setQuadA)((u32*)(work + 0x3530), 4, 0, 2, 3);

    resource = FUN_0021cca0(table0, 0x26);
    texture = FUN_0021cce0(resource);
    (*setState2)(1, texture);

    (*setQuadA)((u32*)(work + 0x3630), 4, 0, 1, 2);
    (*setQuadA)((u32*)(work + 0x3630), 4, 0, 2, 3);

    resource = FUN_0021cca0(table0, 0x2c);
    texture = FUN_0021cce0(resource);
    (*setState2)(1, texture);

    for (j = 0; j < 4; ++j) {
        base = work + j * 0x200;
        target2 = base + 0x3830;
        setQuadB = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
        (*setQuadB)((u32*)target2, 4, 0, 1, 2);
        (*setQuadB)((u32*)target2, 4, 0, 2, 3);

        target2 = base + 0x3930;
        (*setQuadB)((u32*)target2, 4, 0, 1, 2);
        (*setQuadB)((u32*)target2, 4, 0, 2, 3);
    }

    resource = FUN_0021cca0(table0, 0x23);
    texture = FUN_0021cce0(resource);
    (*setState)(1, texture);

    setQuadC = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
    (*setQuadC)((u32*)(work + 0x4230), 4, 0, 1, 2);
    (*setQuadC)((u32*)(work + 0x4230), 4, 0, 2, 3);
    (*setQuadC)((u32*)(work + 0x4330), 4, 0, 1, 2);
    (*setQuadC)((u32*)(work + 0x4330), 4, 0, 2, 3);
}

#pragma push
/* W389 measured opt_lifetimes on: nd1910/3296B -> nd1908/3296B (window 3328B). */
#pragma opt_lifetimes on
// FUN_00228E40 NONMATCHING
void FUN_00228E40(void)
{
    u8* work;
    u8* records;
    u8* record;
    u8* overlay;
    u32 table0;
    u32 table6;
    void* frame;
    f32* basePos;
    f32 alpha1;
    f32 alpha2;
    f32 blend;
    f32 weight;
    u32 percentColour;
    u32 signedColour;
    u32 greyColour;
    u32 sub;
    u32 colour;
    f32 rect[4];
    u8 color[4];
    s32 i;
    s32 current;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    table6 = FUN_0021c3f0(6);
    records = work + 0x4660;
    basePos = (f32*)(work + 0x6050);
    weight = *(f32*)(work + 0x7214);

    switch (*(u32*)(work + 0x463c)) {
    case 2:
        alpha1 = (f32)*(s32*)(work + 0x4650) / 3.0f;
        break;
    case 0:
        alpha1 = (f32)(3 - *(s32*)(work + 0x4650)) / 3.0f;
        break;
    default:
        K_ASSERT(0, 0xe59);
        break;
    }

    switch (*(u32*)(work + 0x4644)) {
    case 0:
        alpha2 = 1.0f;
        break;
    case 3:
        alpha2 = 0.0f;
        break;
    default:
        break;
    }
    blend = 1.0f - alpha1 * alpha2;

    frame = (void*)FUN_0021cca0(table0, 0x23);
    rect[0] = 47.0f + basePos[0];
    rect[1] = 19.0f + basePos[1] +
              (f32)((*(s32*)(work + 0x6068) - *(s32*)(work + 0x606c)) * 26);
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(work + 0x4230, rect);

    frame = (void*)FUN_0021cca0(table0, 0x23);
    rect[0] = 47.0f + basePos[0] + (f32)*(s32*)((u8*)frame + 0xc);
    rect[1] = 19.0f + basePos[1] +
              (f32)((*(s32*)(work + 0x6068) - *(s32*)(work + 0x606c)) * 26);
    rect[2] = 312.0f;
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(work + 0x4330, rect);

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(u32)(255.0f * (alpha1 * alpha2) * weight);
    FUN_0021d950(work + 0x4230, color);
    FUN_0021d950(work + 0x4330, color);

    percentColour = ((u8)(u32)(255.0f * (alpha1 * alpha2) *
                               *(f32*)(work + 0x7214)) * 50 / 100) | 0xffffff00u;
    signedColour = (u32)(255.0f * (1.0f - blend) * weight) | 0xffffff00u;
    greyColour = (u32)(255.0f * (1.0f - blend) * weight) | 0xcccccc00u;

    for (i = 0; i < *(s32*)(work + 0x6070); ++i) {
        record = records + i * 0x510;

        frame = (void*)FUN_0021cca0(table6, 0x2b);
        sub = *(u32*)(record + 4);
        rect[0] = 65.0f + basePos[0] + (f32)*(s32*)((u8*)frame + 0xc);
        rect[1] = 19.0f + basePos[1] + (f32)(i * 26);
        FUN_003b0d70(sub, (s32)rect[0] << 4, (s32)rect[1] << 3);

        current = *(s32*)(work + 0x6068) - *(s32*)(work + 0x606c);
        if (*(u32*)record & 1) {
            colour = percentColour;
        } else if (i == current) {
            colour = signedColour;
        } else {
            colour = greyColour;
        }
        FUN_003b0e20(sub, colour);

        if (*(u32*)(record + 8) == 0) {
            frame = (void*)FUN_0021cca0(table0, 0x30);
        } else if (*(u32*)(record + 8) == 1) {
            frame = (void*)FUN_0021cca0(table0, 0x31);
        }
        rect[0] = 327.0f + basePos[0];
        rect[1] = 32.0f + basePos[1] + (f32)(i * 26);
        rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
        rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
        FUN_0021d8e0(record + 0x10, rect);

        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = (u8)(u32)(255.0f * (alpha1 * alpha2) *
                             *(f32*)(work + 0x7214));
        FUN_0021d950(record + 0x10, color);

        rect[0] = 281.0f + basePos[0];
        rect[1] = 30.0f + basePos[1] + (f32)(i * 26);
        bpIFont00238bf0(record + 0x110, 3, (const char*)(size_t)*(u32*)(record + 0xc), 1, rect);

        current = *(s32*)(work + 0x6068) - *(s32*)(work + 0x606c);
        if (i == current) {
            color[0] = 0xff;
            color[1] = 0xff;
            color[2] = 0xff;
        } else {
            color[0] = 0x5a;
            color[1] = 0x5a;
            color[2] = 0x5a;
        }
        color[3] = (u8)(u32)(255.0f * (alpha1 * alpha2) *
                             *(f32*)(work + 0x7214));
        FUN_0021d950(record + 0x110, color);
        FUN_0021d950(record + 0x210, color);
        FUN_0021d950(record + 0x310, color);

        frame = (void*)FUN_0021cca0(table6, 0x2b);
        rect[0] = 56.0f + basePos[0];
        rect[1] = 16.0f + basePos[1] + (f32)(i * 26);
        rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
        rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
        FUN_0021d8e0(record + 0x410, rect);

        current = *(s32*)(work + 0x6068) - *(s32*)(work + 0x606c);
        if (i == current) {
            color[0] = 0xc7;
            color[1] = 0xd3;
            color[2] = 0xe3;
        } else {
            color[0] = 0x44;
            color[1] = 0x4e;
            color[2] = 0x50;
        }
        color[3] = (u8)(u32)(255.0f * (alpha1 * alpha2) *
                             *(f32*)(work + 0x7214));
        FUN_0021d950(record + 0x410, color);
    }

    if (*(u32*)(work + 0x4644) != 3) {
        return;
    }

    overlay = work + 0x6d00;

    frame = (void*)FUN_0021cca0(table6, 0x2b);
    sub = *(u32*)(overlay + 4);
    rect[0] = 65.0f + basePos[0] + (f32)*(s32*)((u8*)frame + 0xc);
    rect[1] = 19.0f + basePos[1] + 77.0f;
    FUN_003b0d70(sub, (s32)rect[0] << 4, (s32)rect[1] << 3);

    colour = (u8)(u32)(255.0f * blend * *(f32*)(work + 0x7214)) | 0xffffff00u;
    FUN_003b0e20(sub, colour);

    if (*(u32*)(overlay + 8) == 0) {
        frame = (void*)FUN_0021cca0(table0, 0x30);
    } else if (*(u32*)(overlay + 8) == 1) {
        frame = (void*)FUN_0021cca0(table0, 0x31);
    }
    rect[0] = 327.0f + basePos[0];
    rect[1] = 33.0f + basePos[1] + 77.0f;
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(overlay + 0x10, rect);

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(u32)(255.0f * blend * *(f32*)(work + 0x7214));
    FUN_0021d950(overlay + 0x10, color);

    rect[0] = 281.0f + basePos[0];
    rect[1] = 31.0f + basePos[1] + 77.0f;
    bpIFont00238bf0(overlay + 0x110, 3, (const char*)(size_t)*(u32*)(overlay + 0xc), 1, rect);

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(u32)(255.0f * blend * *(f32*)(work + 0x7214));
    FUN_0021d950(overlay + 0x110, color);
    FUN_0021d950(overlay + 0x210, color);
    FUN_0021d950(overlay + 0x310, color);

    frame = (void*)FUN_0021cca0(table6, 0x2b);
    rect[0] = 56.0f + basePos[0];
    rect[1] = 16.0f + basePos[1] + 77.0f;
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(overlay + 0x410, rect);

    color[0] = *((u8*)frame + 0x1c);
    color[1] = *((u8*)frame + 0x1d);
    color[2] = *((u8*)frame + 0x1e);
    color[3] = (u8)(u32)(255.0f * blend * *(f32*)(work + 0x7214));
    FUN_0021d950(overlay + 0x410, color);
}
#pragma pop
#pragma opt_lifetimes reset

/* W389 measured opt_loop_invariants on: nd797/1676B -> nd716/1676B (window 1728B). */
// FUN_00229B40 NONMATCHING
void FUN_00229B40(void)
{
    u8* base;
    u8* records;
    u32 table0;
    u32 table6;
    u8* record;
    u32 resource;
    u32 i;
    u32 state;
    void (**setStatePtr)(u32, u32);
    void (**setStatePtr2)(u32, u32);
    void (**setQuadPtr)(u32*, u32, u32, u32, u32);

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    table6 = FUN_0021c3f0(6);
    records = base + 0x4660;
    resource = FUN_0021cca0(table0, 0x23);
    setStatePtr = (void (**)(u32, u32))D_00960090_abs;
    setQuadPtr = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
    BCM_29_STATE(1, FUN_0021cce0(resource));
    BCM_29_QUAD((u32*)(base + 0x4230), 4, 0, 1, 2);
    BCM_29_QUAD((u32*)(base + 0x4230), 4, 0, 2, 3);
    BCM_29_QUAD((u32*)(base + 0x4330), 4, 0, 1, 2);
    BCM_29_QUAD((u32*)(base + 0x4330), 4, 0, 2, 3);
    for (i = 0; i < *(u32*)(base + 0x6070); i++) {
        record = records + i * 0x510;
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        FUN_003b1360(*(u32*)(record + 4), 1, 0);
        state = *(u32*)(record + 8);
        if (state == 1) {
            resource = FUN_0021cca0(table0, 0x31);
        } else if (state == 0) {
            resource = FUN_0021cca0(table0, 0x30);
        }
        BCM_29_STATE(1, FUN_0021cce0(resource));
        if (i == *(u32*)(base + 0x6068) - *(u32*)(base + 0x606c)) {
            RpSkyRenderStateSet(3, (void*)0x71801);
            RpSkyRenderStateSet(2, (void*)0x48);
        } else {
            RpSkyRenderStateSet(3, (void*)0x717fb);
            RpSkyRenderStateSet(2, (void*)0x44);
        }
        BCM_29_QUAD((u32*)(record + 0x10), 4, 0, 1, 2);
        BCM_29_QUAD((u32*)(record + 0x10), 4, 0, 2, 3);
        setStatePtr = (void (**)(u32, u32))D_00960090_abs;
        BCM_29_STATE(1, FUN_00239140(1));
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        BCM_29_QUAD((u32*)(record + 0x110), 4, 0, 1, 2);
        BCM_29_QUAD((u32*)(record + 0x110), 4, 0, 2, 3);
        BCM_29_QUAD((u32*)(record + 0x210), 4, 0, 1, 2);
        BCM_29_QUAD((u32*)(record + 0x210), 4, 0, 2, 3);
        BCM_29_QUAD((u32*)(record + 0x310), 4, 0, 1, 2);
        BCM_29_QUAD((u32*)(record + 0x310), 4, 0, 2, 3);
        resource = FUN_0021cca0(table6, 0x2b);
        BCM_29_STATE(1, FUN_0021cce0(resource));
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        BCM_29_QUAD((u32*)(record + 0x410), 4, 0, 1, 2);
        BCM_29_QUAD((u32*)(record + 0x410), 4, 0, 2, 3);
    }
    if (*(u32*)(base + 0x4644) == 3) {
        record = base + 0x6d00;
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        FUN_003b1360(*(u32*)(record + 4), 1, 0);
        state = *(u32*)(record + 8);
        if (state == 1) {
            resource = FUN_0021cca0(table0, 0x31);
        } else if (state == 0) {
            resource = FUN_0021cca0(table0, 0x30);
        }
        setStatePtr2 = (void (**)(u32, u32))D_00960090_abs;
        BCM_29_STATE2(1, FUN_0021cce0(resource));
        RpSkyRenderStateSet(3, (void*)0x71801);
        RpSkyRenderStateSet(2, (void*)0x48);
        BCM_29_QUAD((u32*)(record + 0x10), 4, 0, 1, 2);
        BCM_29_QUAD((u32*)(record + 0x10), 4, 0, 2, 3);
        BCM_29_STATE(1, FUN_00239140(1));
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        BCM_29_QUAD((u32*)(record + 0x110), 4, 0, 1, 2);
        BCM_29_QUAD((u32*)(record + 0x110), 4, 0, 2, 3);
        BCM_29_QUAD((u32*)(record + 0x210), 4, 0, 1, 2);
        BCM_29_QUAD((u32*)(record + 0x210), 4, 0, 2, 3);
        BCM_29_QUAD((u32*)(record + 0x310), 4, 0, 1, 2);
        BCM_29_QUAD((u32*)(record + 0x310), 4, 0, 2, 3);
        resource = FUN_0021cca0(table6, 0x2b);
        BCM_29_STATE(1, FUN_0021cce0(resource));
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        BCM_29_QUAD((u32*)(record + 0x410), 4, 0, 1, 2);
        BCM_29_QUAD((u32*)(record + 0x410), 4, 0, 2, 3);
    }
}
#undef BCM_29_STATE
#undef BCM_29_STATE2
#undef BCM_29_QUAD
 

// Previous body was a wrong-helper stub unrelated to retail (624B window).
// Rewritten from disasm: retail loops 3 quad-setter calls, then computes a
// flag from state fields 0x463c/0x4644, gating func_003b1360 + a resource
// draw, matching FUN_0022C5A0's D_00960090_abs/D_0096009C_abs style.
// nd 89->7 (obj 612B/624B); residual is the state-1 loop's register-bank
// Fixed: swapping i and record declaration order resolved the s3/s4 register coloring.
#pragma push
#pragma opt_loop_invariants on
// FUN_0022A2B0 NONMATCHING
void FUN_0022A2B0(void)
{
    u8* work;
    u8* records;
    u8* record;
    u8* overlay;
    u32 table0;
    u32 table6;
    void* frame;
    f32* basePos;
    f32 alpha1;
    f32 alpha2;
    f32 blend;
    f32 weight;
    f32 scaled;
    u8 alphaByte;
    u32 whiteColour;
    u32 greyColour;
    u32 sub;
    u32 colour;
    f32 rect[4];
    u8 color[4];
    s32 i;
    s32 current;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    table6 = FUN_0021c3f0(6);
    records = work + 0x4660;
    basePos = (f32*)(work + 0x6050);
    weight = *(f32*)(work + 0x7214);

    switch (*(u32*)(work + 0x463c)) {
    case 0:
        alpha1 = (f32)(3 - *(s32*)(work + 0x4650)) / 3.0f;
        break;
    case 1:
        alpha1 = (f32)*(s32*)(work + 0x4650) / 3.0f;
        break;
    default:
        K_ASSERT(0, 0xfb4);
        break;
    }

    switch (*(u32*)(work + 0x4644)) {
    case 0:
        alpha2 = 1.0f;
        break;
    case 4:
        alpha2 = 0.0f;
        break;
    }
    scaled = alpha1 * alpha2;
    blend = 1.0f - scaled;

    frame = (void*)FUN_0021cca0(table0, 0x23);
    rect[0] = 47.0f + basePos[0];
    rect[1] = 19.0f + basePos[1] +
              (f32)((*(s32*)(work + 0x6068) - *(s32*)(work + 0x606c)) * 26);
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(work + 0x4230, rect);

    frame = (void*)FUN_0021cca0(table0, 0x23);
    rect[0] = 47.0f + basePos[0] + (f32)*(s32*)((u8*)frame + 0xc);
    rect[1] = 19.0f + basePos[1] +
              (f32)((*(s32*)(work + 0x6068) - *(s32*)(work + 0x606c)) * 26);
    rect[2] = 312.0f;
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(work + 0x4330, rect);

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    scaled = 255.0f * blend * weight;
    alphaByte = (u8)(u32)scaled;
    color[3] = alphaByte;
    FUN_0021d950(work + 0x4230, color);
    FUN_0021d950(work + 0x4330, color);

    /* Retail offset 0x334: recompute alpha for the white/grey colour pair. */
    scaled = 255.0f * blend * weight;
    alphaByte = (u8)(u32)scaled;
    whiteColour = alphaByte | 0xffffff00u;
    greyColour = alphaByte | 0xcccccc00u;

    for (i = 0; i < *(s32*)(work + 0x6070); ++i) {
        record = records + i * 0x410;

        frame = (void*)FUN_0021cca0(table6, 0x1a);
        sub = *(u32*)record;
        rect[0] = 65.0f + basePos[0];
        rect[1] = 19.0f + basePos[1] + (f32)(i * 26);

        current = *(s32*)(work + 0x6068) - *(s32*)(work + 0x606c);
        colour = (i == current) ? whiteColour : greyColour;
        FUN_003b0d70(sub, (s32)rect[0] << 4, (s32)rect[1] << 3);
        FUN_003b0e20(sub, colour);

        frame = (void*)FUN_0021cca0(table0, 0x28);
        rect[0] = 147.0f + basePos[0];
        rect[1] = 19.5f + basePos[1] + (f32)(i * 26);
        rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
        rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
        FUN_0021d8e0(record + 0x10, rect);

        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        /* Retail offset 0x518: recompute alpha for each record icon draw. */
        scaled = 255.0f * blend * weight;
        alphaByte = (u8)(u32)scaled;
        color[3] = alphaByte;
        FUN_0021d950(record + 0x10, color);

        rect[0] = 315.0f + basePos[0];
        rect[1] = 29.0f + basePos[1] + (f32)(i * 26);
        bpIFont00238bf0(record + 0x110, 2, (const char*)(size_t)*(u32*)(record + 4), 1, rect);

        current = *(s32*)(work + 0x6068) - *(s32*)(work + 0x606c);
        if (i == current) {
            color[0] = 0xff;
            color[1] = 0xff;
            color[2] = 0xff;
        } else {
            color[0] = 0x5a;
            color[1] = 0x5a;
            color[2] = 0x5a;
        }
        /* Retail offset 0x610: recompute alpha for the record text colour draws. */
        scaled = 255.0f * blend * weight;
        alphaByte = (u8)(u32)scaled;
        color[3] = alphaByte;
        FUN_0021d950(record + 0x110, color);
        FUN_0021d950(record + 0x210, color);
        FUN_0021d950(record + 0x310, color);

        frame = (void*)FUN_0021cca0(table6, 0x1a);
        rect[0] = 96.5f + basePos[0];
        rect[1] = 16.0f + basePos[1] + (f32)(i * 26);
        rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
        rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
        FUN_0021d8e0(record + 0x310, rect);

        current = *(s32*)(work + 0x6068) - *(s32*)(work + 0x606c);
        if (i == current) {
            color[0] = 0xc7;
            color[1] = 0xd3;
            color[2] = 0xe3;
        } else {
            color[0] = 0x44;
            color[1] = 0x4e;
            color[2] = 0x50;
        }
        /* Retail offset 0x74c: recompute alpha for the record detail draw. */
        scaled = 255.0f * blend * weight;
        alphaByte = (u8)(u32)scaled;
        color[3] = alphaByte;
        FUN_0021d950(record + 0x310, color);
    }

    if (*(u32*)(work + 0x4644) != 4) {
        return;
    }

    overlay = work + 0x6d00;

    frame = (void*)FUN_0021cca0(table6, 0x1a);
    sub = *(u32*)overlay;
    rect[0] = 65.0f + basePos[0];
    rect[1] = 19.0f + basePos[1] + 77.0f;

    /* Retail offset 0x848: recompute alpha for the overlay icon draw. */
    scaled = 255.0f * blend * weight;
    alphaByte = (u8)(u32)scaled;
    colour = alphaByte | 0xffffff00u;
    FUN_003b0d70(sub, (s32)rect[0] << 4, (s32)rect[1] << 3);
    FUN_003b0e20(sub, colour);

    frame = (void*)FUN_0021cca0(table0, 0x28);
    rect[0] = 147.0f + basePos[0];
    rect[1] = 148.0f + basePos[1];
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(overlay + 0x10, rect);

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    /* Retail offset 0x960: recompute alpha for the overlay text icon draw. */
    scaled = 255.0f * blend * weight;
    alphaByte = (u8)(u32)scaled;
    color[3] = alphaByte;
    FUN_0021d950(overlay + 0x10, color);

    rect[0] = 315.0f + basePos[0];
    rect[1] = 158.0f + basePos[1];
    bpIFont00238bf0(overlay + 0x110, 2, (const char*)(size_t)*(u32*)(overlay + 4), 1, rect);

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    /* Retail offset 0xa20: recompute alpha for the overlay text colour draws. */
    scaled = 255.0f * blend * weight;
    alphaByte = (u8)(u32)scaled;
    color[3] = alphaByte;
    FUN_0021d950(overlay + 0x110, color);
    FUN_0021d950(overlay + 0x210, color);
    FUN_0021d950(overlay + 0x310, color);

    frame = (void*)FUN_0021cca0(table6, 0x1a);
    rect[0] = 96.5f + basePos[0];
    rect[1] = 16.0f + basePos[1];
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(overlay + 0x310, rect);

    color[0] = *((u8*)frame + 0x1c);
    color[1] = *((u8*)frame + 0x1d);
    color[2] = *((u8*)frame + 0x1e);
    /* Retail offset 0xb2c: recompute alpha for the overlay detail draw. */
    scaled = 255.0f * blend * weight;
    alphaByte = (u8)(u32)scaled;
    color[3] = alphaByte;
    FUN_0021d950(overlay + 0x310, color);
}
#pragma pop
#pragma opt_loop_invariants reset

// FUN_0022AE80 NONMATCHING
void FUN_0022AE80(void)
{
    u8* work;
    u8* records;
    u8* record;
    u8* overlay;
    u32 table0;
    u32 table6;
    u32 texture;
    s32 i;
    void (**pRender)(u32, u32);
    void (**pRenderInitial)(u32, u32);
    void (**pQuad)(u32*, u32, u32, u32, u32);

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    table6 = FUN_0021c3f0(6);
    records = work + 0x4660;
    texture = FUN_0021cce0(FUN_0021cca0(table0, 0x23));
    pRenderInitial = (void (**)(u32, u32))D_00960090_abs;
    (*pRenderInitial)(1, texture);
    pQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
    BCM_2AE_QUAD((u32*)(work + 0x4230), 4, 0, 1, 2);
    BCM_2AE_QUAD((u32*)(work + 0x4230), 4, 0, 2, 3);
    BCM_2AE_QUAD((u32*)(work + 0x4330), 4, 0, 1, 2);
    BCM_2AE_QUAD((u32*)(work + 0x4330), 4, 0, 2, 3);

    for (i = 0; i < *(s32*)(work + 0x6070); ++i) {
        record = records + i * 0x410;
        FUN_003b1360(*(u32*)record, 1, 0);

        texture = FUN_0021cce0(FUN_0021cca0(table0, 0x28));
        pRender = (void (**)(u32, u32))D_00960090_abs;
        BCM_2AE_STATE(1, texture);
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        BCM_2AE_QUAD((u32*)(record + 0x10), 4, 0, 1, 2);
        BCM_2AE_QUAD((u32*)(record + 0x10), 4, 0, 2, 3);

        texture = FUN_00239140(1);
        BCM_2AE_STATE(1, texture);
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        BCM_2AE_QUAD((u32*)(record + 0x110), 4, 0, 1, 2);
        BCM_2AE_QUAD((u32*)(record + 0x110), 4, 0, 2, 3);
        BCM_2AE_QUAD((u32*)(record + 0x210), 4, 0, 1, 2);
        BCM_2AE_QUAD((u32*)(record + 0x210), 4, 0, 2, 3);
        BCM_2AE_QUAD((u32*)(record + 0x310), 4, 0, 1, 2);
        BCM_2AE_QUAD((u32*)(record + 0x310), 4, 0, 2, 3);

        texture = FUN_0021cce0(FUN_0021cca0(table6, 0x1a));
        BCM_2AE_STATE(1, texture);
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        BCM_2AE_QUAD((u32*)(record + 0x310), 4, 0, 1, 2);
        BCM_2AE_QUAD((u32*)(record + 0x310), 4, 0, 2, 3);
    }

    if (*(u32*)(work + 0x4644) != 4) {
        return;
    }

    overlay = work + 0x6d00;
    FUN_003b1360(*(u32*)overlay, 1, 0);

    texture = FUN_0021cce0(FUN_0021cca0(table0, 0x28));
    pRender = (void (**)(u32, u32))D_00960090_abs;
    BCM_2AE_STATE(1, texture);
    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    BCM_2AE_QUAD((u32*)(overlay + 0x10), 4, 0, 1, 2);
    BCM_2AE_QUAD((u32*)(overlay + 0x10), 4, 0, 2, 3);

    texture = FUN_00239140(1);
    BCM_2AE_STATE(1, texture);
    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    (*pQuad)((u32*)(overlay + 0x110), 4, 0, 1, 2);
    (*pQuad)((u32*)(overlay + 0x110), 4, 0, 2, 3);
    (*pQuad)((u32*)(overlay + 0x210), 4, 0, 1, 2);
    (*pQuad)((u32*)(overlay + 0x210), 4, 0, 2, 3);
    (*pQuad)((u32*)(overlay + 0x310), 4, 0, 1, 2);
    (*pQuad)((u32*)(overlay + 0x310), 4, 0, 2, 3);

    texture = FUN_0021cce0(FUN_0021cca0(table6, 0x1a));
    BCM_2AE_STATE(1, texture);
    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    BCM_2AE_QUAD((u32*)(overlay + 0x310), 4, 0, 1, 2);
    BCM_2AE_QUAD((u32*)(overlay + 0x310), 4, 0, 2, 3);
}

#undef BCM_2AE_STATE
#undef BCM_2AE_QUAD
// FUN_0022b4e0
u32 bcmPanel0022b4e0(void)
{
    K_ASSERT(sBcmPanel != NULL, 0xe6);
    return *sBcmPanel & 2;
}

// FUN_0022b530
u32 bcmPanel0022b530(void)
{
    K_ASSERT(sBcmPanel != NULL, 0xe6);
    return *sBcmPanel & 8;
}

// FUN_0022b580
void bcmPanel0022b580(void)
{
    int iVar1;
    u32 uVar2;
    u32 uVar3;
    int iVar4;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    iVar1 = (int)sBcmPanel;
    uVar2 = FUN_0021c3f0(0);
    for (iVar4 = 0; iVar4 < 3; iVar4++) {
        uVar3 = FUN_0021cca0(uVar2, iVar4 + 0x3e);
        FUN_0021d3b0(iVar1 + iVar4 * 0x100 + 0x65f0, uVar3);
    }
}

#pragma push
#pragma opt_loop_invariants on
// FUN_0022B630 NONMATCHING
void FUN_0022B630(void)
{
    u8* base;
    u32 table0;
    u32 table6;
    f32 weight;
    u32 slot;
    u8* icon;
    u8* iconSlot;
    f32 layout[4];
    u8 colour[16];
    u32 i;
    u32 alpha;
    u8 overlayColour[4];
    u32 packedColour;
    u32 dispatch;
    u32 secondaryDispatch;
    u32 entry;
    u32 target;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    table6 = FUN_0021c3f0(6);
    weight = *(f32*)(base + 0x7214);
    for (slot = 0; slot < 3; slot++) {
        icon = (u8*)FUN_0021cca0(table0, slot + 0x3e);
        dispatch = *(u32*)(base + 0x463c);
        if (dispatch == 4) goto group_high;
        if (dispatch == 3) goto group_high;
        if (dispatch == 1) goto group_high;
        if (dispatch == 2) goto group_high;
        switch (dispatch) {
        case 0: goto group_low;
        }
        goto group_done;
    group_low:
        if (slot == 2) goto low_2;
        if (slot == 1) goto low_1;
        switch (slot) {
        case 0: goto low_0;
        }
        goto group_done;
    low_0:
        layout[0] = 233.0f; layout[1] = 379.0f;
        goto group_done;
    low_1:
        layout[0] = 98.0f; layout[1] = 379.0f;
        goto group_done;
    low_2:
        layout[0] = 485.0f; layout[1] = 379.0f;
        goto group_done;
    group_high:
        if (slot == 2) goto high_2;
        if (slot == 1) goto high_1;
        switch (slot) {
        case 0: goto high_0;
        }
        goto group_done;
    high_0:
        layout[0] = 193.0f; layout[1] = 379.0f;
        goto group_done;
    high_1:
        layout[0] = 58.0f; layout[1] = 379.0f;
        goto group_done;
    high_2:
        layout[0] = 445.0f; layout[1] = 379.0f;
    group_done:
        layout[2] = (f32)*(s32*)(icon + 0xc);
        layout[3] = (f32)*(s32*)(icon + 0x10);
        iconSlot = base + (slot << 8) + 0x65f0;
        FUN_0021d8e0(iconSlot, layout);
        for (i = 0; i < 4; i++) {
            u8* dst;
            u8* src;
            u8 r, g, b, a;
            src = icon + i * 4;
            r = src[0x1c];
            g = src[0x1d];
            b = src[0x1e];
            a = src[0x1f];
            dst = colour + i * 4;
            dst[0] = r;
            dst[1] = g;
            dst[2] = b;
            dst[3] = a;
            alpha = src[0x1f];
            dst[3] = (u8)(u32)((f32)alpha * weight);
        }
        FUN_0021dd60(iconSlot, colour);
    }
    overlayColour[0] = 0xc6;
    overlayColour[1] = 0xca;
    overlayColour[2] = 0xdb;
    overlayColour[3] = (u8)(u32)(fGpffff83e8 * weight);
    packedColour = ((u32)overlayColour[0] << 0x18) | ((u32)overlayColour[1] << 0x10) |
                   ((u32)overlayColour[2] << 8) | overlayColour[3];
    dispatch = *(u32*)(base + 0x463c);
    switch (dispatch) {
    case 0:
        entry = *(u32*)(base + 0x68f0);
        target = *(u32*)(entry + 0x24);
        if (target != 0) {
            FUN_003b0d70(target, 0x1020, 0xbe8);
            FUN_003b0d70(*(u32*)(base + 0x68f0), 0x1020, 0xc98);
            entry = *(u32*)(base + 0x68f0);
            FUN_003b0e20(*(u32*)(entry + 0x24), packedColour);
            FUN_003b0e20(*(u32*)(base + 0x68f0), packedColour);
        } else {
            FUN_003b0d70(entry, 0x1020, 0xbe8);
            FUN_003b0e20(*(u32*)(base + 0x68f0), packedColour);
        }
        break;
    case 1: case 2:
        entry = *(u32*)(base + 0x68f0);
        target = *(u32*)(entry + 0x24);
        if (target != 0) {
            FUN_003b0d70(target, 0xc60, 0xbe8);
            FUN_003b0d70(*(u32*)(base + 0x68f0), 0xc60, 0xc98);
            entry = *(u32*)(base + 0x68f0);
            FUN_003b0e20(*(u32*)(entry + 0x24), packedColour);
            FUN_003b0e20(*(u32*)(base + 0x68f0), packedColour);
        } else {
            FUN_003b0d70(entry, 0xc60, 0xbe8);
            FUN_003b0e20(*(u32*)(base + 0x68f0), packedColour);
        }
        if (*(u32*)(base + 0x68f8) != 0) {
            u32 frameId;
            u8* frame;
            frameId = *(u32*)(base + 0x68f4) + 0x20;
            frame = (u8*)FUN_0021cca0(table6, frameId);
            layout[0] = 161.0f;
            layout[1] = 190.0f;
            layout[2] = (f32)*(s32*)(frame + 0xc);
            layout[3] = (f32)*(s32*)(frame + 0x10);
            FUN_0021d8e0(base + 0x6900, layout);
            overlayColour[0] = 0x8c;
            overlayColour[1] = 0x96;
            overlayColour[2] = 0xb4;
            overlayColour[3] = (u8)(u32)(255.0f * weight);
            FUN_0021d950(base + 0x6900, overlayColour);
        }
        break;
    case 3:
        secondaryDispatch = *(u32*)(base + 0x4644);
        if (secondaryDispatch == 1 || secondaryDispatch == 2) {
            entry = *(u32*)(base + 0x68f0);
            target = *(u32*)(entry + 0x24);
            if (target != 0) {
                FUN_003b0d70(target, 0xc60, 0xbe8);
                FUN_003b0d70(*(u32*)(base + 0x68f0), 0xc60, 0xc98);
                entry = *(u32*)(base + 0x68f0);
                FUN_003b0e20(*(u32*)(entry + 0x24), packedColour);
                FUN_003b0e20(*(u32*)(base + 0x68f0), packedColour);
            } else {
                FUN_003b0d70(entry, 0xc60, 0xbe8);
                FUN_003b0e20(*(u32*)(base + 0x68f0), packedColour);
            }
        }
        break;
    }
}
#pragma pop
#pragma opt_loop_invariants reset

// Previous body was a wrong-helper stub unrelated to retail (720B window).
// Rewritten from disasm: retail draws 3 rects (2 sharing a resource fetch)
// with a shared alpha255=255*weight computed once and reused, matching
// FUN_0022BCF0
void FUN_0022BCF0(void)
{
    u8* work;
    u32 table6;
    u32 resource;
    u32 texture;
    s32 i;
    u32 state1;
    u32 state2;
    u32 flag;
    u8* record;
    void (**setState)(u32, u32);
    void (**setQuad)(u32*, u32, u32, u32, u32);

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    FUN_0021c3f0(0);
    table6 = FUN_0021c3f0(6);
    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(1, 0);
    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);

    for (i = 0; i < 3; i++) {
        record = work + i * 0x100 + 0x65f0;
        setQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
        (*setQuad)((u32*)record, 4, 0, 1, 2);
        (*setQuad)((u32*)record, 4, 0, 2, 3);
    }

    state1 = *(u32*)(work + 0x463c);
    flag = 0;
    switch (state1) {
    case 0:
    case 2:
    case 1:
        flag = 1;
        break;
    case 3:
        state2 = *(u32*)(work + 0x4644);
        switch (state2) {
        case 1:
            flag = 1;
            break;
        }
        break;
    }

    if (flag != 0) {
        func_003b1360(*(u32*)(work + 0x68f0), 1, 0);
        if (*(u32*)(work + 0x68f8) != 0) {
            resource = FUN_0021cca0(table6, *(u32*)(work + 0x68f4) + 0x20);
            texture = FUN_0021cce0(resource);
            (*setState)(1, texture);
            RpSkyRenderStateSet(3, (void*)0x717fb);
            RpSkyRenderStateSet(2, (void*)0x44);
            setQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
            (*setQuad)((u32*)(work + 0x6900), 4, 0, 1, 2);
            (*setQuad)((u32*)(work + 0x6900), 4, 0, 2, 3);
        }
    }
}

// FUN_0022BF60
void FUN_0022BF60(void)
{
    u8* base;
    u8* slot;
    u32 table0;
    u32 table6;
    u32 resource;
    u32 state;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    table6 = FUN_0021c3f0(6);
    FUN_0022C210();
    slot = base + 0x6d00;
    state = *(u32*)(slot + 8);
    if (state == 1) {
        goto panel_resource_31;
    }
    switch (state) {
    case 0:
        goto panel_resource_30;
    default:
        goto panel_resource_done;
    }
panel_resource_30:
    resource = FUN_0021cca0(table0, 0x30);
    goto panel_resource_done;
panel_resource_31:
    resource = FUN_0021cca0(table0, 0x31);
panel_resource_done:
    FUN_0021d3b0(slot + 0x10, resource);
    FUN_00238980(slot + 0x110, 3, *(u32*)(slot + 0xc), 1);
    resource = FUN_0021cca0(table6, 0x2b);
    FUN_0021d3b0(slot + 0x410, resource);
    *(u32*)(base + 0x4644) = 3;
}

// FUN_0022C0A0
void FUN_0022C0A0(void)
{
    K_ASSERT(sBcmPanel != NULL, 0xe6);
    *(u32*)((int)sBcmPanel + 0x4644) = 0;
}














/* W389 measured opt_lifetimes on: nd442/636B -> nd441/636B (window 640B). */



/* W310/W357 measured bpTexBeginRender: optimization_level 1 nd85/288B -> nd0/320B. */




/* W357 measured bpTexFindFreeNode: optimization_level 3 nd18/168B -> nd0/168B. */


/* Retail queueing performs its root census and action-record writes inline. */
/* W310 measured: opt_common_subs off nd434->407, object 668/672; reset nd434. */







/* W357 debt: bpTexUpdateNode at honest -O2 is 2860B vs 2656B window
 * (nd2145), 204B over. optimization_level 3 measures 2516B/2656
 * (nd1915) and preserves link layout; real repair needs retail frame
 * comparison, ordered helper call census, and the ABS_f32 stub sweep. */


/*
 * Retail offsets 0x9ec-0xbc4 count unowned roots, locate each by index, and redraw leaves.
 */
/* W310 measured: opt_loop_invariants on nd2267->2266, object 2908/3024; reset nd2267. */





/*
 * The command-panel work area lives in the same GP slot used by bcm_panel.c.
 */









// FUN_0022C0E0
void FUN_0022C0E0(void)
{
    u8* base;
    u8* slot;
    u32 table0;
    u32 table6;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    table6 = FUN_0021c3f0(6);
    FUN_0022C210();
    slot = base + 0x6d00;
    FUN_0021d3b0(slot + 0x10,
                 FUN_0021cca0(table0, 0x28));
    FUN_00238980(slot + 0x110, 2,
                 *(u32*)(slot + 4), 1);
    FUN_0021d3b0(slot + 0x310,
                 FUN_0021cca0(table6, 0x1a));
    *(u32*)(base + 0x4644) = 4;
}

// FUN_0022C1D0
void FUN_0022C1D0(void)
{
    K_ASSERT(sBcmPanel != NULL, 0xe6);
    *(u32*)((int)sBcmPanel + 0x4644) = 0;
}

// FUN_0022C210
void FUN_0022C210(void)
{
    u8* base;
    u32 table;
    u32 resource;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = (u8*)sBcmPanel;
    table = FUN_0021c3f0(0);
    resource = FUN_0021cca0(table, 0x42);
    FUN_0021d3b0(base + 0x6a00, resource);
    FUN_0021e380(base + 0x6b00, resource, 1);
    FUN_0021d3b0(base + 0x6c00,
                 FUN_0021cca0(table, 0x43));
}

// FUN_0022C2D0
void FUN_0022C2D0(void)
{
    u8* work;
    u32 table0;
    u32 resourceA;
    f32 weight;
    f32 alpha;
    s32 alphaInt;
    f32 rect[4];
    u8 color[4];

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    weight = *(f32*)(work + 0x7214);

    resourceA = FUN_0021cca0(table0, 0x42);
    rect[0] = 57.0f;
    rect[1] = (f32)0x13d;
    rect[2] = (f32)*(s32*)(resourceA + 0xc);
    rect[3] = (f32)*(s32*)(resourceA + 0x10);
    FUN_0021d8e0(work + 0x6a00, rect);

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(255.0f * weight);
    FUN_0021d950(work + 0x6a00, color);
 
    rect[0] = 57.0f + (f32)*(s32*)(resourceA + 0xc);
    rect[1] = (f32)0x13d;
    rect[2] = 133.0f;
    rect[3] = (f32)*(s32*)(resourceA + 0x10);
    FUN_0021d8e0(work + 0x6b00, rect);
 
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(255.0f * weight);
    FUN_0021d950(work + 0x6b00, color);
 
    resourceA = FUN_0021cca0(table0, 0x43);
    rect[0] = 400.0f;
    rect[1] = (f32)0x13d;
    rect[2] = (f32)*(s32*)(resourceA + 0xc);
    rect[3] = (f32)*(s32*)(resourceA + 0x10);
    FUN_0021d8e0(work + 0x6c00, rect);
 
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(255.0f * weight);
    FUN_0021d950(work + 0x6c00, color);
}
#pragma alias D_00960090_abs D_00960090
#pragma alias D_0096009C_abs D_0096009C







// FUN_0022C5A0
void FUN_0022C5A0(void)
{
    u8* base;
    u32 resource;
    void (**setColour)(u32*, u32, u32, u32, u32);
    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = (u8*)sBcmPanel;
    resource = FUN_0021cca0(FUN_0021c3f0(0), 0x42);
    (*(void (**)(u32, u32))D_00960090_abs)(1, FUN_0021cce0(resource));
    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    setColour = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_u32;
    (*setColour)((u32*)(base + 0x6a00), 4, 0, 1, 2);
    (*setColour)((u32*)(base + 0x6a00), 4, 0, 2, 3);
    (*setColour)((u32*)(base + 0x6b00), 4, 0, 1, 2);
    (*setColour)((u32*)(base + 0x6b00), 4, 0, 2, 3);
    (*setColour)((u32*)(base + 0x6c00), 4, 0, 1, 2);
    (*setColour)((u32*)(base + 0x6c00), 4, 0, 2, 3);
}



// FUN_0022c720
void FUN_0022c720(u32* object, u32 style)
{
    u32 table;
    u32 resource;

    object[0] = 0;
    table = FUN_0021c3f0(3);
    *(f32*)((u8*)object + 0x510) = 100.0f;
    *(f32*)((u8*)object + 0x514) = 100.0f;
    *(u16*)((u8*)object + 4) = (u16)style;
    resource = FUN_0021c450(style);
    FUN_0021d3b0((u8*)object + 0x10,
                 FUN_0021cca0(resource, 0));
    resource = FUN_0021cca0(resource, 1);
    FUN_0021d3b0((u8*)object + 0x110, resource);
    FUN_0021d3b0((u8*)object + 0x210, resource);
    FUN_0021d3b0((u8*)object + 0x310, resource);
    FUN_0021d3b0((u8*)object + 0x410, resource);
    resource = FUN_0021cca0(table, 0xa);
    FUN_0021d3b0((u8*)object + 0x630, resource);
    FUN_0021d3b0((u8*)object + 0x730, resource);
    *(u32*)((u8*)object + 0x850) = 0;
    *(u32*)((u8*)object + 0x854) = 0;
    object[0] |= 1;
}

#pragma opt_common_subs reset
