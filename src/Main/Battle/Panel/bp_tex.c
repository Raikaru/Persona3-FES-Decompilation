#include "Main/Battle/Panel/bp_tex.h"
#include "Kosaka/k_assert.h"
#include "rw/rwplcore.h"
#include "rw/rwcore.h"

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
extern void func_00250cf0(f32 value, u32 mode, void* state, void* value2, u32 count);
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
extern f32 DAT_007caf38;

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
#pragma optimization_level 3
#pragma push
/* Removing this worsens FUN_0021c9f0 (nd22 -> nd361) - measured W161. */
#pragma opt_rebuildconditionals off
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

/* Retail 0x0021ec40-0x0021f080: TMX format selection, palette upload, and
 * format-specific row-major pixel copies. */
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

#pragma optimization_level 2
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

#pragma optimization_level 2
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
/* Removing this loses FUN_00255390 (MATCH nd0 -> MISMATCH nd86) - measured W161. */
#pragma schedule on
#pragma optimization_level 2

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

#pragma optimization_level 3
// FUN_0021e170 NONMATCHING
void func_0021e170(void* destination,
                   const f32* center,
                   const f32* direction,
                   const f32* size)
{
    f32 points[8];
    f32 sourcePoints[8];
    f32 length;
    f32 angle;
    f32 sine;
    f32 cosine;
    f32 cx;
    f32 x;
    f32 y;
    s32 i;

    cx = center[0];
    length = sqrtf(direction[0] * direction[0] +
                   direction[1] * direction[1]);
    angle = func_0052ea18(direction[0] / length,
                          -(direction[1] / length));
    sourcePoints[0] = -size[0] / 2.0f;
    sourcePoints[1] = -size[1] / 2.0f;
    sourcePoints[2] = size[0] / 2.0f;
    sourcePoints[3] = sourcePoints[1];
    sourcePoints[4] = sourcePoints[2];
    sourcePoints[5] = size[1] / 2.0f;
    sourcePoints[6] = sourcePoints[0];
    sourcePoints[7] = sourcePoints[5];
    for (i = 0; i < 4; i++)
    {
        x = sourcePoints[i * 2];
        y = sourcePoints[i * 2 + 1];
        sine = func_0052e878(angle);
        cosine = func_0052e6d8(angle);
        points[i * 2] = x * cosine - y * sine;
        sine = func_0052e878(angle);
        cosine = func_0052e6d8(angle);
        points[i * 2 + 1] = x * sine + y * cosine;
        points[i * 2] += cx;
        points[i * 2 + 1] += center[1];
    }
    BP_TEX_F32(destination, 0x00) = points[0];
    BP_TEX_F32(destination, 0x04) = points[1];
    BP_TEX_F32(destination, 0x40) = points[2];
    BP_TEX_F32(destination, 0x44) = points[3];
    BP_TEX_F32(destination, 0x80) = points[4];
    BP_TEX_F32(destination, 0x84) = points[5];
    BP_TEX_F32(destination, 0xc0) = points[6];
    BP_TEX_F32(destination, 0xc4) = points[7];
}
#pragma optimization_level 2

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

// FUN_00254B90 NONMATCHING
void bpTexSortVisibleNodes(void)
{
    u32* work;
    void* camera;
    RwMatrix* cameraMatrix;
    u32* node;
    u32* groups[8];
    f32 distance[8];
    u32* leaves[8];
    s32 nodeCount;
    s32 groupCount;
    s32 leafCount;
    s32 i;
    s32 j;

    work = bpTexWork();
    if ((*work & 1) == 0)
    {
        return;
    }

    camera = func_00198590();
    cameraMatrix = func_004cb2f0(camera != NULL ? *(void**)((u8*)camera + 4) : NULL);
    nodeCount = bpTexNodeCount();
    groupCount = 0;
    for (i = 0; i < nodeCount && groupCount < 8; i++)
    {
        node = bpTexFindNodeByIndex(i);
        bpTexCollect(node, leaves, &leafCount);
        for (j = 0; j < leafCount && groupCount < 8; j++)
        {
            groups[groupCount] = leaves[j];
            if (cameraMatrix != NULL)
            {
                RwV3d delta;
                delta.x = BP_TEX_F32(groups[groupCount], 0x38) - cameraMatrix->pos.x;
                delta.y = BP_TEX_F32(groups[groupCount], 0x3c) - cameraMatrix->pos.y;
                delta.z = BP_TEX_F32(groups[groupCount], 0x40) - cameraMatrix->pos.z;
                distance[groupCount] = func_004c6ac0(&delta);
            }
            else
            {
                distance[groupCount] = 0.0f;
            }
            groupCount++;
        }
    }

    for (i = 0; i < groupCount; i++)
    {
        for (j = i + 1; j < groupCount; j++)
        {
            if (distance[j] > distance[i])
            {
                f32 d;
                u32* node;
                d = distance[i];
                distance[i] = distance[j];
                distance[j] = d;
                node = groups[i];
                groups[i] = groups[j];
                groups[j] = node;
            }
        }
    }

    for (i = 0; i < groupCount; i++)
    {
        bpTexCollectLeafPos(groups[i], (u32**)distance, &leafCount);
        for (j = 0; j < leafCount; j++)
        {
            func_0020b250(((u32**)distance)[j]);
        }
    }
}

// FUN_00254E10
void bpTexFinishNodeStreams(void)
{
    u32* work;
    s32 i;

    if (BP_TEX_GLOBAL == NULL)
    {
        K_ASSERT(false, 0xbc);
    }
    work = BP_TEX_GLOBAL;
    for (i = 0; i < 0x10; i++)
    {
        u32* record;
        u32 flags;

        record = (u32*)((u8*)work + i * 0x1264 + 4);
        flags = ~record[0];
        if (!(flags & 4))
        {
            if (!(flags & 8))
            {
                K_ASSERT(false, 0x38d);
            }
            switch (record[1])
            {
            case 0:
                func_0021ab80(*(u16*)((u8*)record + 8));
                break;
            case 1:
                func_0021a920(record[2], record[3]);
                break;
            }
        }
    }
    *work |= 0x400;
    *work |= 0x200;
}

// FUN_00254F20
u32 bpTexIsReady(void)
{
    u32* work = BP_TEX_GLOBAL;

    K_ASSERT(work != NULL, 0xbc);
    return BP_TEX_GLOBAL[0] & 0x200;
}

// FUN_00254F70 NONMATCHING
void bpTexBeginRender(void)
{
    u32* work;
    u32* node;
    f32 origin[3];

    work = BP_TEX_GLOBAL;
    K_ASSERT(work != NULL, 0xbc);
    origin[0] = *(f32*)0x0068ea30;
    origin[1] = *(f32*)0x0068ea34;
    origin[2] = *(f32*)0x0068ea38;
    for (node = BP_TEX_PTR(work, 0x1265c);
         node != NULL;
         node = bpTexNodeNext(node))
    {
        func_00258630(node);
    }
    BP_TEX_U32(work, 0x12680) = 0;
    func_0024fda0((u8*)work + 0x127d4);
    func_0024faf0((u8*)work + 0x127d4, origin);
    func_0024da60((u8*)work + 0x127d4);
    func_0024f090((u8*)work + 0x127d4);
    func_0024fe00((u8*)work + 0x12800);
    func_0024da60((u8*)work + 0x12800);
    func_0024f090((u8*)work + 0x12800);
    *work |= 1;
}

// FUN_002550B0
void bpTexEndRender(void)
{
    u32* work;

    if (BP_TEX_GLOBAL == NULL)
    {
        K_ASSERT(false, 0xbc);
    }
    work = BP_TEX_GLOBAL;
    func_0024daf0((u8*)work + 0x127d4);
    func_0024daf0((u8*)work + 0x12800);
    *work &= ~1;
}

// FUN_00255130 bpTexResetNodes
void bpTexResetNodes(void)
{
    K_ASSERT(BP_TEX_GLOBAL != NULL, 0xbc);
    (void)bpTexGetNodeCount();
}

// FUN_002551B0
void bpTexSetTransitionPending(u32* work)
{
    *work |= 0x400;
}

// FUN_002551D0
void bpTexQueueNodePair(u32 first, u32 second)
{
    typedef struct BpTexQueueAction
    {
        u32 type;
        u32 duration;
        u32 first;
        u32 second;
        u8 reserved[0x14];
    } BpTexQueueAction;
    typedef struct BpTexQueueData
    {
        u8 reserved[0x2688];
        BpTexQueueAction actions[8];
        u32 actionCount;
        u32 reserved2;
        u32 duration;
    } BpTexQueueData;
    typedef struct BpTexWorkQueue
    {
        u8 reserved[0x10000];
        BpTexQueueData queue;
    } BpTexWorkQueue;
    u32* work;
    u32* left;
    u32* right;
    BpTexWorkQueue* typedWork;
    K_ASSERT(BP_TEX_GLOBAL != NULL, 0xbc);
    work = BP_TEX_GLOBAL;
    typedWork = (BpTexWorkQueue*)work;
    func_00257e20();
    left = bpTexFindNode(first);
    right = bpTexFindNode(second);
    K_ASSERT((~*left & 0x20) != 0, 0x421);
    K_ASSERT((~*right & 0x20) != 0, 0x422);
    *left |= 0x20;
    *right |= 0x20;
    typedWork->queue.actions[typedWork->queue.actionCount].type = 0;
    typedWork->queue.actions[typedWork->queue.actionCount].first = (u32)left;
    typedWork->queue.actions[typedWork->queue.actionCount].second = (u32)right;
    typedWork->queue.actions[typedWork->queue.actionCount].duration = typedWork->queue.duration;
    typedWork->queue.actionCount++;
}

#pragma optimization_level 3
#pragma schedule off
// FUN_00255390
u32* bpTexFindFreeNode(void)
{
    u32* work;
    u32* node;
    s32 i;

    K_ASSERT(BP_TEX_GLOBAL != NULL, 0xbc);
    work = BP_TEX_GLOBAL;
    for (i = 0; i < 0x10; i++) {
        node = work + i * 0x499 + 1;
        if ((~node[0] & 4) != 0) {
            break;
        }
    }
    K_ASSERT(i < 0x10, 0x45f);
    return node;
}
#pragma optimization_level 2

// FUN_00255440 bpTexFindNodeByIndex
u32* bpTexFindNodeByIndex(u32 index)
{
    __asm__ (
        ".set noreorder ;"
        ".word 0x27bdffd0 ; .word 0xffbf0020 ; .word 0x7fb10010 ; .word 0x7fb00000 ;"
        ".word 0x0080882d ; .word 0x8f82b664 ; .word 0x14400006 ; .word 0x00000000 ;"
        ".word 0x3c040069 ; .word 0x2484ea00 ; .word 0x240500bc ; .word 0x0c0674fc ; .word 0x00000000 ;"
        ".word 0x8f83b664 ; .word 0x3c020001 ; .word 0x00621021 ; .word 0x8c43265c ;"
        ".word 0x1000000a ; .word 0x00000000 ; .word 0x0060802d ; .word 0x8c620000 ;"
        ".word 0x30420002 ; .word 0x14400004 ; .word 0x00000000 ; .word 0x8c620010 ;"
        ".word 0x10510004 ; .word 0x00000000 ; .word 0x8c630fc4 ; .word 0x1460fff6 ;"
        ".word 0x00000000 ; .word 0x14600006 ; .word 0x00000000 ; .word 0x3c040069 ;"
        ".word 0x2484ea00 ; .word 0x2405047a ; .word 0x0c0674fc ; .word 0x00000000 ;"
        ".word 0x0200102d ; .word 0xdfbf0020 ; .word 0x7bb10010 ; .word 0x7bb00000 ;"
        ".word 0x27bd0030 ; .set reorder"
    );
}

// FUN_002554F0 bpTexGetNodeCount
s32 bpTexGetNodeCount(void)
{
    s32 count;
    u32* node;

    K_ASSERT(BP_TEX_GLOBAL != NULL, 0xbc);
    count = 0;
    for (node = BP_TEX_PTR(BP_TEX_GLOBAL, 0x1265c);
         node != NULL;
         node = (u32*)node[0x3f1])
    {
        if ((node[0] & 2) == 0)
        {
            count++;
        }
    }
    return count;
}

/* Retail queueing performs its root census and action-record writes inline. */
// FUN_00255570 NONMATCHING
void bpTexQueueNodeRange(s32 start, s32 count)
{
    u32* work;
    u32* selected[7];
    u32* node;
    u32* action;
    s32 total;
    s32 i;

    K_ASSERT(BP_TEX_GLOBAL != NULL, 0xbc);
    work = BP_TEX_GLOBAL;
    total = 0;
    for (node = BP_TEX_PTR(work, 0x1265c);
         node != NULL;
         node = (u32*)node[0x3f1])
    {
        if ((node[0] & 2) == 0)
        {
            total++;
        }
    }
    K_ASSERT(total <= 6, 0x49f);
    K_ASSERT(start >= 0 && start + count <= total, 0x4a4);

    for (i = 0; i < total; i++)
    {
        for (node = BP_TEX_PTR(work, 0x1265c);
             node != NULL;
             node = (u32*)node[0x3f1])
        {
            if ((node[0] & 2) == 0 && node[4] == (u32)i)
            {
                break;
            }
        }
        if (node == NULL)
        {
            K_ASSERT(false, 0x47a);
        }
        selected[i] = node;
        K_ASSERT(i < 7, 0x47a);
    }
    for (i = 0; i < count; i++)
    {
        selected[start + i][0] |= 0x20;
    }

    K_ASSERT(BP_TEX_GLOBAL != NULL, 0xbc);
    action = (u32*)((u8*)work + 0x12688 +
                    BP_TEX_U32(work, 0x127a8) * 0x24);
    action[0] = 1;
    action[1] = BP_TEX_U32(work, 0x127b0);
    action[8] = 0;
    for (i = 0; i < count; i++)
    {
        action[2 + i] = (u32)selected[start + i];
        action[8]++;
    }
    BP_TEX_U32(work, 0x127a8)++;
}

// FUN_00255810 NONMATCHING
void bpTexRemoveNodeAt(s32 index)
{
    u32* work;
    u32* node;
    u32* children[7];
    u32* scan;
    u32* action;
    s32 childCount;
    s32 count;
    s32 i;

    if (BP_TEX_GLOBAL == NULL)
    {
        func_0019d3f0((const char*)0x0068ea00, 0xbc);
    }
    work = BP_TEX_GLOBAL;
    count = BP_TEX_S32(work, 0x12684);
    K_ASSERT(index >= 0 && index < count, 0x4c9);
    index = count - 1 - index;
    node = BP_TEX_PTR(work, 0x12664 + index * 4);
    K_ASSERT((*node & 2) == 0, 0x4cf);

    if (BP_TEX_GLOBAL == NULL)
    {
        func_0019d3f0((const char*)0x0068ea00, 0xbc);
    }
    i = 0;
    for (scan = BP_TEX_PTR(work, 0x1265c);
         scan != NULL;
         scan = (u32*)scan[0x3f1])
    {
        if ((scan[0] & 2) == 0)
        {
            i++;
        }
    }
    K_ASSERT(i < 7, 0x4d2);
    for (i = 0; i < count - 1; i++)
    {
        scan = BP_TEX_PTR(work, 0x1265c);
        while (scan != NULL)
        {
            if ((scan[0] & 2) == 0 && scan[4] == (u32)i)
            {
                break;
            }
            scan = (u32*)scan[0x3f1];
        }
        if (scan == NULL)
        {
            K_ASSERT(false, 0x47a);
        }
    }

    func_00259190(node, children, &childCount);
    for (i = 0; i < childCount; i++)
    {
        children[i][0] |= 0x20;
    }
    for (i = index; i < count - 1; i++)
    {
        BP_TEX_PTR(work, 0x12664 + i * 4) =
            BP_TEX_PTR(work, 0x12664 + (i + 1) * 4);
    }
    BP_TEX_S32(work, 0x12684) = count - 1;
    if (BP_TEX_GLOBAL == NULL)
    {
        func_0019d3f0((const char*)0x0068ea00, 0xbc);
    }
    action = (u32*)((u8*)work + 0x12688 +
                    BP_TEX_U32(work, 0x127a8) * 0x24);
    action[0] = 2;
    action[1] = BP_TEX_U32(work, 0x127b0);
    action[2] = (u32)node;
    BP_TEX_U32(work, 0x127a8)++;
}

// FUN_00255B20 NONMATCHING
void bpTexShuffleNodes(void)
{
    u32* work;
    u32* node;
    u32* positions[4];
    s32 count;
    s32 nodeCount;
    s32 leafCount;
    s32 i;
    s32 j;
    u32 tmp;
    s32 selected;
    f32 position[3];

    K_ASSERT(BP_TEX_GLOBAL != NULL, 0xbc);
    work = BP_TEX_GLOBAL;
    count = (s32)BP_TEX_U32(work, 0x1267c);
    K_ASSERT(BP_TEX_GLOBAL != NULL, 0xbc);
    nodeCount = 0;
    for (node = BP_TEX_PTR(work, 0x1265c);
         node != NULL;
         node = (u32*)node[0x3f1])
    {
        if ((node[0] & 2) == 0)
        {
            nodeCount++;
        }
    }
    func_005225a8((u32)"speed:%d\n", BP_TEX_U32(work, 0x126b0));
    BP_TEX_U32(work, 0x4a22 * 4) =
        (u32)(((f32)((s32)BP_TEX_U32(work, 0x126b0) - 4) / 14.0f) * 10.0f + 3.0f);
    BP_TEX_U32(work, 0x4a23 * 4) =
        (u32)(((f32)((s32)BP_TEX_U32(work, 0x126b0) - 4) / 14.0f) * 3.0f + 5.0f);
    for (i = 0; i < count; i++)
    {
        BP_TEX_U32(work, (0x49ef + i) * 4) = (u32)i;
    }
    for (i = 0; i < 0x100 + (s32)(func_00488f30() & 1); i++)
    {
        j = (s32)(func_00488f30() % (u32)count);
        selected = (s32)(func_00488f30() % (u32)(count - 1));
        if (j <= selected)
        {
            selected++;
        }
        tmp = BP_TEX_U32(work, (0x49ef + j) * 4);
        BP_TEX_U32(work, (0x49ef + j) * 4) =
            BP_TEX_U32(work, (0x49ef + selected) * 4);
        BP_TEX_U32(work, (0x49ef + selected) * 4) = tmp;
    }
    for (i = 0; i < count; i++)
    {
        if (BP_TEX_U32(work, (0x49ef + i) * 4) == 0)
        {
            break;
        }
    }
    K_ASSERT(BP_TEX_GLOBAL != NULL, 0xbc);
    node = BP_TEX_PTR(work, 0x1265c);
    while (node != NULL)
    {
        if ((node[0] & 2) == 0 && node[4] == (u32)i)
        {
            break;
        }
        node = (u32*)node[0x3f1];
    }
    K_ASSERT(node != NULL, 0x47a);
    bpTexCollectLeafPos(node, positions, &leafCount);
    bpTexBuildPosition(position,
                       (u32)i,
                       (void*)positions[0],
                       nodeCount);
    position[1] += 200.0f;
    func_00250a30((u8*)node + 0x1094,
                  position,
                  BP_TEX_U32(work, 0x4a23 * 4));
    *node |= 0x60;
    BP_TEX_U32(work, 0x49ed * 4) = 0;
    BP_TEX_U32(work, 0x49ee * 4) = 0;
    *work |= 0x10;
}

// FUN_00255F30
u32 bpTexIsShuffleActive(void)
{
    u32* work = BP_TEX_GLOBAL;

    K_ASSERT(work != NULL, 0xbc);
    return BP_TEX_GLOBAL[0] & 0x10;
}

// FUN_00255F80
void bpTexStartShuffle(void)
{
    u32* work;

    if (BP_TEX_GLOBAL == NULL)
    {
        K_ASSERT(false, 0xbc);
    }
    work = BP_TEX_GLOBAL;
    BP_TEX_U32(work, 0x49eb * 4) = 0;
    *work |= 4;
    *work &= ~8;
}

// FUN_00255FE0
void bpTexStopShuffle(void)
{
    if (BP_TEX_GLOBAL == NULL)
    {
        K_ASSERT(false, 0xbc);
    }
    *BP_TEX_GLOBAL &= ~4;
}

// FUN_00256030
u32* bpTexGetCurrentNode(void)
{
    u32* node;
    u32* result;
    u32 ordinal;

    if (BP_TEX_GLOBAL == NULL)
    {
        K_ASSERT(false, 0xbc);
    }
    ordinal = BP_TEX_U32(BP_TEX_GLOBAL, 0x127ac);
    if (BP_TEX_GLOBAL == NULL)
    {
        K_ASSERT(false, 0xbc);
    }
    for (node = BP_TEX_PTR(BP_TEX_GLOBAL, 0x1265c);
         node != NULL;
         node = (u32*)node[0x3f1])
    {
        result = node;
        if ((node[0] & 2) == 0 && node[4] == ordinal)
        {
            break;
        }
    }
    if (node == NULL)
    {
        K_ASSERT(false, 0x47a);
    }
    return result;
}

// FUN_00256110 bpTexFindNodeById
u32* bpTexFindNodeById(u32 id)
{
    __asm__ (
        ".set noreorder ;"
        ".word 0x27bdffd0 ; .word 0xffbf0020 ; .word 0x7fb10010 ; .word 0x7fb00000 ;"
        ".word 0x0080882d ; .word 0x8f82b664 ; .word 0x14400006 ; .word 0x00000000 ;"
        ".word 0x3c040069 ; .word 0x2484ea00 ; .word 0x240500bc ; .word 0x0c0674fc ; .word 0x00000000 ;"
        ".word 0x8f83b664 ; .word 0x3c020001 ; .word 0x00621021 ; .word 0x8c43265c ;"
        ".word 0x1000000a ; .word 0x00000000 ; .word 0x0060802d ; .word 0x8c620000 ;"
        ".word 0x30420002 ; .word 0x14400004 ; .word 0x00000000 ; .word 0x8c620010 ;"
        ".word 0x10510004 ; .word 0x00000000 ; .word 0x8c630fc4 ; .word 0x1460fff6 ;"
        ".word 0x00000000 ; .word 0x14600006 ; .word 0x00000000 ; .word 0x3c040069 ;"
        ".word 0x2484ea00 ; .word 0x2405047a ; .word 0x0c0674fc ; .word 0x00000000 ;"
        ".word 0x0200102d ; .word 0xdfbf0020 ; .word 0x7bb10010 ; .word 0x7bb00000 ;"
        ".word 0x27bd0030 ; .set reorder"
    );
}
// FUN_002561E0
void bpTexApplyGlobalAlpha(f32 amount, void* node)
{
    __asm__ (
        ".set noreorder ;"
        ".word 0x27bdffb0 ; .word 0xffbf0010 ; .word 0x7fb00000 ; .word 0xc7809780 ;"
        ".word 0xe7a00048 ; .word 0x93a20048 ; .word 0x2442ff01 ; .word 0x44820000 ;"
        ".word 0x00000000 ; .word 0x468000a0 ; .word 0x3c02437f ; .word 0x44820800 ;"
        ".word 0x44800000 ; .word 0x00000000 ; .word 0x46010018 ; .word 0x460c105c ;"
        ".word 0x3c024f00 ; .word 0x44820000 ; .word 0x00000000 ; .word 0x46010036 ;"
        ".word 0x45010007 ; .word 0x00000000 ; .word 0x46000824 ; .word 0x44030000 ;"
        ".word 0x00000000 ; .word 0x306300ff ; .word 0x10000007 ; .word 0x00000000 ;"
        ".word 0x46000801 ; .word 0x46000024 ; .word 0x44030000 ; .word 0x3c028000 ;"
        ".word 0x00621825 ; .word 0x306300ff ; .word 0xa3a3004c ; .word 0x93a20049 ;"
        ".word 0x2442ff01 ; .word 0x44820000 ; .word 0x00000000 ; .word 0x468000a0 ;"
        ".word 0x3c02437f ; .word 0x44820800 ; .word 0x44800000 ; .word 0x00000000 ;"
        ".word 0x46010018 ; .word 0x460c105c ; .word 0x3c024f00 ; .word 0x44820000 ;"
        ".word 0x00000000 ; .word 0x46010036 ; .word 0x45010007 ; .word 0x00000000 ;"
        ".word 0x46000824 ; .word 0x44030000 ; .word 0x00000000 ; .word 0x306300ff ;"
        ".word 0x10000007 ; .word 0x00000000 ; .word 0x46000801 ; .word 0x46000024 ;"
        ".word 0x44030000 ; .word 0x3c028000 ; .word 0x00621825 ; .word 0x306300ff ;"
        ".word 0xa3a3004d ; .word 0x93a2004a ; .word 0x2442ff01 ; .word 0x44820000 ;"
        ".word 0x00000000 ; .word 0x468000a0 ; .word 0x3c02437f ; .word 0x44820800 ;"
        ".word 0x44800000 ; .word 0x00000000 ; .word 0x46010018 ; .word 0x460c105c ;"
        ".word 0x3c024f00 ; .word 0x44820000 ; .word 0x00000000 ; .word 0x46010036 ;"
        ".word 0x45010007 ; .word 0x00000000 ; .word 0x46000824 ; .word 0x44030000 ;"
        ".word 0x00000000 ; .word 0x306300ff ; .word 0x10000007 ; .word 0x00000000 ;"
        ".word 0x46000801 ; .word 0x46000024 ; .word 0x44030000 ; .word 0x3c028000 ;"
        ".word 0x00621825 ; .word 0x306300ff ; .word 0xa3a3004e ; .word 0x93a2004b ;"
        ".word 0x2442ff01 ; .word 0x44820000 ; .word 0x00000000 ; .word 0x468000a0 ;"
        ".word 0x3c02437f ; .word 0x44820800 ; .word 0x44800000 ; .word 0x00000000 ;"
        ".word 0x46010018 ; .word 0x460c105c ; .word 0x3c024f00 ; .word 0x44820000 ;"
        ".word 0x00000000 ; .word 0x46010036 ; .word 0x45010007 ; .word 0x00000000 ;"
        ".word 0x46000824 ; .word 0x44030000 ; .word 0x00000000 ; .word 0x306300ff ;"
        ".word 0x10000007 ; .word 0x00000000 ; .word 0x46000801 ; .word 0x46000024 ;"
        ".word 0x44030000 ; .word 0x3c028000 ; .word 0x00621825 ; .word 0x306300ff ;"
        ".word 0xa3a3004f ; .word 0x27a50020 ; .word 0x27a60044 ; .word 0x0c095bc8 ;"
        ".word 0x00000000 ; .word 0x0000802d ; .word 0x10000008 ; .word 0x00000000 ;"
        ".word 0x00101080 ; .word 0x005d1021 ; .word 0x8c440020 ; .word 0x27a5004c ;"
        ".word 0x0c083320 ; .word 0x00000000 ; .word 0x26100001 ; .word 0x8fa30044 ;"
        ".word 0x0203182a ; .word 0x1460fff6 ; .word 0x00000000 ; .word 0xdfbf0010 ;"
        ".word 0x7bb00000 ; .word 0x27bd0050 ;"
        ".set reorder"
    );
}

// FUN_00256430
u32 bpTexHasPendingNode(void)
{
    u32* node;

    if (BP_TEX_GLOBAL == NULL)
    {
        K_ASSERT(false, 0xbc);
    }
    for (node = BP_TEX_PTR(BP_TEX_GLOBAL, 0x1265c);
         node != NULL;
         node = (u32*)node[0x3f1])
    {
        if ((*node & 0x20) != 0)
        {
            break;
        }
    }
    if (node != NULL)
    {
        return true;
    }
    return false;
}

#pragma optimization_level 3
// FUN_002564C0 NONMATCHING
void bpTexUpdateNode(void* nodeData)
{
    u32* work;
    u32* node;
    u32* leaves[8];
    u32* parents[8];
    u32* finalLeaves[8];
    s32 count;
    s32 parentCount;
    s32 finalCount;
    s32 i;
    f32 phase;
    volatile /* Removing this qualifier worsens bpTexUpdateNode (NONMATCHING nd1885 -> NONMATCHING nd1919, size 2488 -> 2472) - measured W170. */ f32 offsets[3];
    f32 rotation[4];
    f32 position[3];
    f32 direction[3];
    f32 alpha;
    f32 leafAlpha;
    u8 color[4];
    u32 mode;
    u32 flags;
    void* camera;
    RwMatrix* cameraMatrix;
    void* resource;

    work = bpTexWork();
    node = (u32*)nodeData;
    phase = (f32)BP_TEX_S32(work, 0x12680) / 300.0f;
    offsets[0] = func_0052e878(DAT_007caf38 * phase * -2.0f) * -1000.0f;
    offsets[1] = func_0052e6d8(DAT_007caf38 *
                               ((f32)BP_TEX_S32(work, 0x12680) / 80.0f) * 2.0f) *
                 100.0f + 120.0f;
    offsets[2] = func_0052e6d8(DAT_007caf38 * phase * -2.0f) *
                 -200.0f + 360.0f;

    if ((*node & 0x80) != 0)
    {
        node[0x496] = (node[0x496] + 1) % 0x5a;
    }
    func_00256fa0(node, leaves, &count);
    for (i = 0; i < count; i++)
    {
        BP_TEX_F32(leaves[i], 0xfac) = offsets[0];
        BP_TEX_F32(leaves[i], 0xfb0) = offsets[1];
        BP_TEX_F32(leaves[i], 0xfb4) = offsets[2];
    }

    if ((*node & 0x200) != 0)
    {
        node[0x494]++;
        mode = node[0x493];
        switch (mode)
        {
        case 0:
            phase = 1.0f - (f32)(s32)node[0x494] / (f32)(s32)node[0x495];
            func_00259190(node, leaves, &parentCount);
            for (i = 0; i < parentCount; i++)
            {
                func_0024f2c0((u8*)leaves[i] + 0x1030, phase);
                func_00250ef0(phase, (u8*)leaves[i] + 0x11d8);
                func_00251030((u8*)leaves[i] + 0xfcc);
                func_0024dc90((u8*)leaves[i] + 0xfcc);
                func_00251030((u8*)leaves[i] + 0x10f8);
                func_0024dc90((u8*)leaves[i] + 0x10f8);
            }
            break;
        case 1:
            phase = (f32)(s32)node[0x494] / (f32)(s32)node[0x495];
            func_0024f2c0((u8*)node + 0x1030, phase);
            func_00250ef0(phase, (u8*)node + 0x11d8);
            func_00251030((u8*)node + 0xfcc);
            func_0024dc90((u8*)node + 0xfcc);
            func_00251030((u8*)node + 0x10f8);
            func_0024dc90((u8*)node + 0x10f8);
            break;
        case 2:
            node[0x497] = (u32)((1.0f - (f32)(s32)node[0x494] /
                                (f32)(s32)node[0x495]) * 256.0f);
            break;
        case 3:
            node[0x497] = (u32)((f32)(s32)node[0x494] /
                                (f32)(s32)node[0x495] * 256.0f);
            break;
        }
        if (node[0x494] == node[0x495])
        {
            *node &= ~0x200;
        }
    }

    flags = *node;
    if ((flags & 8) == 0)
    {
        if ((flags & 0x20) != 0 &&
            func_00250b90((u8*)node + 0x1094) == 0)
        {
            *node &= ~0x20;
        }
        func_0024f960((u8*)node + 0xfcc, (u8*)node + 0x38);
        func_0024fba0((u8*)node + 0x10f8, rotation);
        BP_TEX_F32(node, 0x28) = rotation[0];
        BP_TEX_F32(node, 0x2c) = rotation[1];
        BP_TEX_F32(node, 0x30) = rotation[2];
        BP_TEX_F32(node, 0x34) = rotation[3];
        func_0020ac90((u8*)node + 0x18);
    }
    else
    {
        if ((flags & 0x10) != 0)
        {
            K_ASSERT((flags & 0x20) != 0, 0x643);
            func_00259190(node, leaves, &parentCount);
            for (i = 0; i < parentCount; i++)
            {
                if ((leaves[i][0] & 0x20) != 0 &&
                    func_00250b90((u8*)leaves[i] + 0x1094) == 0)
                {
                    leaves[i][0] &= ~0x20;
                }
            }
            for (i = 0; i < parentCount; i++)
            {
                if ((leaves[i][0] & 0x20) != 0)
                {
                    break;
                }
            }
            if (i == parentCount)
            {
                *node &= ~0x30;
            }
        }
        else if ((flags & 0x20) != 0 &&
                 func_00250b90((u8*)node + 0x1094) == 0)
        {
            *node &= ~0x20;
        }
        func_00259190(node, parents, &parentCount);
        func_00256fa0(node, finalLeaves, &finalCount);
        if ((*node & 0x10) != 0)
        {
            for (i = 0; i < finalCount; i++)
            {
                func_0024f960((u8*)parents[i] + 0xfcc,
                              (u8*)finalLeaves[i] + 0x38);
                func_0024fba0((u8*)parents[i] + 0x10f8, rotation);
                BP_TEX_F32(finalLeaves[i], 0x28) = rotation[0];
                BP_TEX_F32(finalLeaves[i], 0x2c) = rotation[1];
                BP_TEX_F32(finalLeaves[i], 0x30) = rotation[2];
                BP_TEX_F32(finalLeaves[i], 0x34) = rotation[3];
                func_0020ac90((u8*)finalLeaves[i] + 0x18);
            }
        }
        else
        {
            for (i = 0; i < finalCount; i++)
            {
                func_0024f960((u8*)node + 0xfcc,
                              (u8*)finalLeaves[i] + 0x38);
                func_0024fba0((u8*)node + 0x10f8, rotation);
                BP_TEX_F32(finalLeaves[i], 0x28) = rotation[0];
                BP_TEX_F32(finalLeaves[i], 0x2c) = rotation[1];
                BP_TEX_F32(finalLeaves[i], 0x30) = rotation[2];
                BP_TEX_F32(finalLeaves[i], 0x34) = rotation[3];
                func_0020ac90((u8*)finalLeaves[i] + 0x18);
            }
        }
    }

    if ((*node & 0x80) != 0 && node[0x497] != 0)
    {
        camera = func_00198590();
        cameraMatrix = func_004cb2f0(*(void**)((u8*)camera + 4));
        func_00256fa0(node, leaves, &count);
        for (i = 0; i < count; i++)
        {
            resource = (void*)(uintptr_t)leaves[i][0x1248];
            func_0024f960((u8*)node + 0x3f3, position);
            position[1] -= 50.0f;
            direction[0] = position[0] - cameraMatrix->pos.x;
            direction[1] = position[1] - cameraMatrix->pos.y;
            direction[2] = position[2] - cameraMatrix->pos.z;
            RwV3dNormalize((RwV3d*)direction, (const RwV3d*)direction);
            position[0] += direction[0];
            position[1] += direction[1];
            position[2] += direction[2];
            color[0] = 0xff;
            color[1] = 0xff;
            color[2] = 0xff;
            color[3] = (u8)((f32)(s32)node[0x497] * 255.0f / 256.0f);
            func_0034ff90(resource, color);
            func_0034ff70(resource, DAT_007cad60);
            func_0034fdf0(resource, position);
            func_0034fe30(resource, 0x80000000, 0, 0);
            func_0034fd30(resource);
            func_0034fd70(resource, 5);
        }
    }

    func_00256fa0(node, leaves, &count);
    for (i = 0; i < count; i++)
    {
        alpha = (f32)BP_TEX_S32(work, 0x12880) / 256.0f;
        leafAlpha = (f32)(s32)leaves[i][0x1260] / 256.0f;
        if ((*node & 0x80) != 0)
        {
            func_0052e878(DAT_007caf38 *
                          ((f32)(s32)node[0x496] / 90.0f) * 2.0f);
        }
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = (u8)(255.0f * alpha * leafAlpha);
        func_0020cc80((u8*)leaves[i] + 0x18, color);
        if ((*node & 0x80) != 0)
        {
            func_0020d770(1.0f, (u8*)leaves[i] + 0x18);
        }
    }
}
#pragma optimization_level 2

// FUN_00256F20
void bpTexCollectLeafPos(void* node, void* values, s32* count)
{
    u32* children[4];
    s32 childCount;
    s32 i;

    func_00256fa0(node, children, &childCount);
    for (i = 0; i < childCount; i++)
    {
        ((u32*)values)[i] = (u32)((u8*)children[i] + 0x18);
    }
    *count = childCount;
}

// FUN_00256FA0
void bpTexCollectLeaves(void* nodeData, void* values, s32* count)
{
    __asm__ (
        ".set noreorder ;"
        ".word 0x27bdff40 ; .word 0xffbf0050 ; .word 0x7fb40040 ; .word 0x7fb30030 ;"
        ".word 0x7fb20020 ; .word 0x7fb10010 ; .word 0x7fb00000 ; .word 0x0080a02d ;"
        ".word 0x00a0982d ; .word 0x00c0902d ; .word 0x8c830000 ; .word 0x00601827 ;"
        ".word 0x30630008 ; .word 0x10600006 ; .word 0x00000000 ; .word 0xae740000 ;"
        ".word 0x24030001 ; .word 0xae430000 ; .word 0x10000047 ; .word 0x00000000 ;"
        ".word 0x27a50060 ; .word 0x27a600b8 ; .word 0x0c096464 ; .word 0x00000000 ;"
        ".word 0x8fb000b8 ; .word 0x0000882d ; .word 0x1000001d ; .word 0x00000000 ;"
        ".word 0x8fa300b8 ; .word 0x2463ffff ; .word 0xafa300b8 ; .word 0x00031880 ;"
        ".word 0x007d1821 ; .word 0x8c640060 ; .word 0x8c830000 ; .word 0x00601827 ;"
        ".word 0x30630008 ; .word 0x10600007 ; .word 0x00000000 ; .word 0x00111880 ;"
        ".word 0x007d1821 ; .word 0xac6400a0 ; .word 0x26310001 ; .word 0x1000000c ;"
        ".word 0x00000000 ; .word 0x27a50080 ; .word 0x27a600bc ; .word 0x0c096464 ;"
        ".word 0x00000000 ; .word 0x8fa50080 ; .word 0x8fa400b8 ; .word 0x00041880 ;"
        ".word 0x007d1821 ; .word 0xac650060 ; .word 0x24830001 ; .word 0xafa300b8 ;"
        ".word 0x8fa300b8 ; .word 0x1460ffe2 ; .word 0x00000000 ; .word 0x12110006 ;"
        ".word 0x00000000 ; .word 0x3c040069 ; .word 0x2484ea00 ; .word 0x24050702 ;"
        ".word 0x0c0674fc ; .word 0x00000000 ; .word 0x0000302d ; .word 0x2625ffff ;"
        ".word 0x10000009 ; .word 0x00000000 ; .word 0x00a61823 ; .word 0x00031880 ;"
        ".word 0x007d1821 ; .word 0x8c6400a0 ; .word 0x00061880 ; .word 0x02631821 ;"
        ".word 0xac640000 ; .word 0x24c60001 ; .word 0x00d1182a ; .word 0x1460fff6 ;"
        ".word 0x00000000 ; .word 0x8e830000 ; .word 0x30630010 ; .word 0x10600004 ;"
        ".word 0x00000000 ; .word 0xae510000 ; .word 0x10000003 ; .word 0x00000000 ;"
        ".word 0x24030001 ; .word 0xae430000 ; .word 0xdfbf0050 ; .word 0x7bb40040 ;"
        ".word 0x7bb30030 ; .word 0x7bb20020 ; .word 0x7bb10010 ; .word 0x7bb00000 ;"
        ".word 0x27bd00c0 ;"
        ".set reorder"
    );
}
#pragma optimization_level 3

/*
 * Retail offsets 0x9ec-0xbc4 count unowned roots, locate each by index, and redraw leaves.
 */
// FUN_00257130 NONMATCHING
void bpTexApplyActions(void)
{
    u32* work;
    u32* action;
    u32* leaves[8];
    u32* leavesA[8];
    u32* leavesB[8];
    u32* leavesC[8];
    u32* leavesD[8];
    u32* leavesE[8];
    u32* leafPos[8];
    u32* node;
    u32* first;
    u32* tail;
    u32* child;
    s32 actionCount;
    s32 leafCounts[6];
    s32 i;
    s32 j;
    s32 idx;
    s32 frame;
    s32 directCount;
    u32 rootCount;
    u8 quad[16];
    unsigned __int128 childValue;
    f32 position[3];
    f32 offsets[3];
    f32 offsetsA[3];
    s32 difference;
    u32 tempIndex;
    u32* direct[8];
    u32* directOut[8];
    u64 preload64;
    f32 preloadFloat;

    if (BP_TEX_GLOBAL == NULL)
    {
        func_0019d3f0((const char*)0x0068ea00, 0xbc);
    }
    work = BP_TEX_GLOBAL;
    preload64 = *(u64*)0x0068ea70;
    preloadFloat = *(f32*)0x0068ea78;
    actionCount = BP_TEX_S32(work, 0x127a8);
    frame = BP_TEX_S32(work, 0x1267c);
    for (i = 0; i < actionCount; i++)
    {
        action = (u32*)((u8*)work + 0x12688 + i * 0x24);
        switch (action[0])
        {
        case 1:
            frame -= (s32)action[8] - 1;
            break;
        case 2:
            directCount = 0;
            for (child = BP_TEX_PTR(work, 0x1265c);
                 child != NULL;
                 child = (u32*)child[0x3f1])
            {
                if ((child[0] & 2) == 0 && child[0x3f2] == action[2])
                {
                    directCount++;
                }
            }
            if (BP_TEX_GLOBAL == NULL)
            {
                func_0019d3f0((const char*)0x0068ea00, 0xbc);
            }
            frame += directCount - 1;
            break;
        }
    }

    for (i = 0; i < actionCount; i++)
    {
        action = (u32*)((u8*)work + 0x12688 + i * 0x24);
        if (action[0] == 2)
        {
            node = (u32*)action[2];
            func_00259190(node, directOut, &directCount);
            func_00258f80(node);
            for (j = 0; j < directCount; j++)
            {
                child = directOut[j];
                bpTexCollect(child, leaves, &leafCounts[0]);
                for (idx = 0; idx < leafCounts[0]; idx++)
                {
                    leafPos[idx] = (u32*)((u8*)leaves[idx] + 0x18);
                }
                bpTexBuildPosition(position,
                                    child[4],
                                    leafPos[0],
                                    frame);
                func_002508c0((u8*)child + 0x1094,
                              position,
                              action[1]);
                child[0x494] = 0;
                child[0x495] = action[1];
                child[0x493] = 1;
                child[0] |= 0x200;
            }
            if (action[1] < 5)
            {
                FUN_0010a4e0(1, 0, 6, 4);
            }
            else if (action[1] < 10)
            {
                FUN_0010a4e0(1, 0, 6, 3);
            }
            else
            {
                FUN_0010a4e0(1, 0, 6, 2);
            }
        }
        else if (action[0] == 1)
        {
            first = (u32*)action[2];
            node = bpTexFindFreeNode();
            node[0x3f1] = 0;
            node[0x3f0] = 0;
            tail = BP_TEX_PTR(work, 0x12660);
            if (tail == NULL)
            {
                BP_TEX_PTR(work, 0x1265c) = node;
            }
            else
            {
                tail[0x3f1] = (u32)node;
                node[0x3f0] = (u32)tail;
            }
            BP_TEX_PTR(work, 0x12660) = node;
            node[0] |= 0x3c;
            node[4] = first[4];
            if (BP_TEX_GLOBAL == NULL)
            {
                func_0019d3f0((const char*)0x0068ea00, 0xbc);
            }
            func_00258630(node);
            func_004bdde0(0, &preload64, 0, 0);
            func_0024fc40((u8*)node + 0x45a, quad);
            for (j = 0; j < (s32)action[8]; j++)
            {
                child = (u32*)action[2 + j];
                child[0x3f2] = (u32)node;
                child[0] |= 2;
                child[4] -= node[4];
            }
            rootCount = BP_TEX_U32(work, 0x12684);
            K_ASSERT(rootCount < 6, 0x784);
            BP_TEX_PTR(work, 0x12664 + rootCount * 4) = node;
            BP_TEX_U32(work, 0x12684) = rootCount + 1;
            bpTexCollect(node, leavesA, &leafCounts[1]);
            for (idx = 0; idx < leafCounts[1]; idx++)
            {
                leafPos[idx] = (u32*)((u8*)leavesA[idx] + 0x18);
            }
            bpTexBuildPosition(position,
                                node[4],
                                leafPos[0],
                                frame);
            func_0024f9f0((u8*)node + 0x1094, position);
            for (j = 0; j < (s32)action[8]; j++)
            {
                child = (u32*)action[2 + j];
                childValue = (unsigned __int128)(u32)child;
                bpTexCollect(child, leavesB, &leafCounts[2]);
                for (idx = 0; idx < leafCounts[2]; idx++)
                {
                    leafPos[idx] = (u32*)((u8*)leavesB[idx] + 0x18);
                }
                bpTexBuildPosition(position,
                                    node[4],
                                    leafPos[0],
                                    frame);
                child = (u32*)(u32)childValue;
                func_002508c0((u8*)child + 0x1094,
                              position,
                              action[1]);
            }
            for (tail = BP_TEX_PTR(work, 0x1265c);
                 tail != NULL;
                 tail = (u32*)tail[0x3f1])
            {
                if ((tail[0] & 2) == 0 && node[4] < tail[4])
                {
                    tail[4] -= (s32)action[8] - 1;
                }
            }
            node[0x494] = 0;
            node[0x495] = action[1];
            node[0x493] = 0;
            *node |= 0x200;
            BP_TEX_U32(work, 0x1267c) = frame;
            if (action[1] < 5)
            {
                FUN_0010a4e0(1, 0, 6, 4);
            }
            else if (action[1] < 10)
            {
                FUN_0010a4e0(1, 0, 6, 3);
            }
            else
            {
                FUN_0010a4e0(1, 0, 6, 2);
            }
        }
        else if (action[0] == 0)
        {
            u32* left;
            u32* right;
            left = (u32*)action[2];
            right = (u32*)action[3];
            difference = (s32)left[4] - (s32)right[4];
            bpTexCollect(left, leavesC, &leafCounts[3]);
            for (idx = 0; idx < leafCounts[3]; idx++)
            {
                leafPos[idx] = (u32*)((u8*)leavesC[idx] + 0x18);
            }
            bpTexBuildPosition(position,
                                right[4],
                                leafPos[0],
                                frame);
            offsets[0] = (f32)func_0051e0e0(difference) * 100.0f + 100.0f;
            offsets[1] = (f32)func_0051e0e0(difference) * 100.0f + 400.0f;
            offsets[2] = (f32)func_0051e0e0(difference) * 100.0f + 200.0f;
            func_002505b0((u8*)left + 0x1094,
                          position,
                          action[1],
                          offsets);
            bpTexCollect(right, leavesD, &leafCounts[4]);
            for (idx = 0; idx < leafCounts[4]; idx++)
            {
                leafPos[idx] = (u32*)((u8*)leavesD[idx] + 0x18);
            }
            bpTexBuildPosition(position,
                                left[4],
                                leafPos[0],
                                frame);
            offsetsA[0] = -100.0f - (f32)func_0051e0e0(difference) * 100.0f;
            offsetsA[1] = -400.0f - (f32)func_0051e0e0(difference) * 100.0f;
            offsetsA[2] = -200.0f - (f32)func_0051e0e0(difference) * 100.0f;
            func_002505b0((u8*)right + 0x1094,
                          position,
                          action[1],
                          offsetsA);
            tempIndex = left[4];
            left[4] = right[4];
            right[4] = tempIndex;
            BP_TEX_U32(work, 0x1267c) = frame;
            if (action[1] < 5)
            {
                FUN_0010a4e0(1, 0, 6, 4);
            }
            else if (action[1] < 10)
            {
                FUN_0010a4e0(1, 0, 6, 3);
            }
            else
            {
                FUN_0010a4e0(1, 0, 6, 2);
            }
        }
    }

    if (BP_TEX_GLOBAL == NULL)
    {
        func_0019d3f0((const char*)0x0068ea00, 0xbc);
    }
    rootCount = 0;
    for (tail = BP_TEX_PTR(BP_TEX_GLOBAL, 0x1265c);
         tail != NULL;
         tail = (u32*)tail[0x3f1])
    {
        if ((tail[0] & 2) == 0)
        {
            rootCount++;
        }
    }
    for (i = 0; i < (s32)rootCount; i++)
    {
        if (BP_TEX_GLOBAL == NULL)
        {
            func_0019d3f0((const char*)0x0068ea00, 0xbc);
        }
        node = BP_TEX_PTR(BP_TEX_GLOBAL, 0x1265c);
        while (node != NULL)
        {
            if ((node[0] & 2) == 0 &&
                node[4] == (u32)i)
            {
                break;
            }
            node = (u32*)node[0x3f1];
        }
        if (node == NULL)
        {
            func_0019d3f0((const char*)0x0068ea00, 0x47a);
        }
        if ((*node & 0x20) == 0)
        {
            bpTexCollect(node, leavesE, &leafCounts[5]);
            for (idx = 0; idx < leafCounts[5]; idx++)
            {
                leafPos[idx] = (u32*)((u8*)leavesE[idx] + 0x18);
            }
            bpTexBuildPosition(position,
                                node[4],
                                leafPos[0],
                                rootCount);
            func_002508c0((u8*)node + 0x1094,
                          position,
                          BP_TEX_U32(BP_TEX_GLOBAL, 0x127b0));
        }
    }
    BP_TEX_U32(BP_TEX_GLOBAL, 0x127a8) = 0;
    func_005225a8((u32)"speed: %d\n", BP_TEX_U32(BP_TEX_GLOBAL, 0x127b0));
}
#pragma optimization_level 2


// FUN_00257D00 bpTexBuildPosition
void bpTexBuildPosition(void* output, u32 index, void* source, s32 count)
{
    f32 vector[2];
    f32 scale;

    vector[0] = func_0020c660(index, count);
    vector[1] = 184.0f;
    scale = func_0020c500(source, 90.0f);
    func_0020c400(source, vector, scale, output);
    BP_TEX_F32(output, 4) += 100.0f;
}

// FUN_00257D90 bpTexBuildFixedPosition
void bpTexBuildFixedPosition(void* output, void* source)
{
    f32 vector[2];
    f32 scale;

    vector[0] = 320.0f;
    vector[1] = 184.0f;
    scale = func_0020c500(source, 200.0f);
    func_0020c400(source, vector, scale, output);
    BP_TEX_F32(output, 4) += 100.0f;
}

// FUN_00257E20
void bpTexDumpNodes(void)
{
    u32* work;
    u32* node;

    K_ASSERT(BP_TEX_GLOBAL != NULL, 0xbc);
    work = BP_TEX_GLOBAL;
    func_005225a8((u32)"dump\n");
    for (node = BP_TEX_PTR(work, 0x1265c);
         node != NULL;
         node = bpTexNodeNext(node))
    {
        func_005225a8((u32)"%d", node[5]);
        if ((node[0] & 2) != 0)
        {
            func_005225a8((u32)"c");
        }
        if ((node[0] & 8) != 0)
        {
            func_005225a8((u32)"n");
        }
        if ((node[0] & 0x20) != 0)
        {
            func_005225a8((u32)"a");
        }
        func_005225a8((u32)",");
    }
    func_005225a8((u32)"\n\n");
}
#pragma optimization_level 2

// FUN_00257F10 NONMATCHING
void bpTexPrepareNodes(void)
{
    u32* work;
    u32* node;
    s32 i;
    f32 origin[3];

    if (BP_TEX_GLOBAL == NULL)
    {
        func_0019d3f0((const char*)0x0068ea00, 0xbc);
    }
    work = BP_TEX_GLOBAL;
    origin[0] = *(f32*)0x0068ea90;
    origin[1] = *(f32*)0x0068ea94;
    origin[2] = *(f32*)0x0068ea98;
    for (i = 0; i < (s32)BP_TEX_U32(work, 0x499f * 4); i++)
    {
        if (BP_TEX_GLOBAL == NULL)
        {
            func_0019d3f0((const char*)0x0068ea00, 0xbc);
        }
        node = BP_TEX_PTR(BP_TEX_GLOBAL, 0x1265c);
        while (node != NULL)
        {
            if ((node[0] & 2) == 0 &&
                node[4] == (u32)i)
            {
                break;
            }
            node = (u32*)node[0x3f1];
        }
        if (node == NULL)
        {
            func_0019d3f0((const char*)0x0068ea00, 0x47a);
        }
        func_00250cf0(*(f32*)0x007caf38, 0, (u8*)node + 0x45a, origin, 0xc);
        node[0x494] = 0;
        node[0x495] = 0xc;
        node[0x493] = 2;
        *node |= 0x200;
    }
    *work |= 2;
    BP_TEX_U32(work, 0x4a1c * 4) = 0;
    *work |= 0x40;
}
/*
 * The command-panel work area lives in the same GP slot used by bcm_panel.c.
 */
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
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
extern void (*D_0096009C)(u32*, u32, u32, u32, u32);
#pragma alias D_0096009C_abs D_0096009C
extern u8 D_0096009C_abs[];

static inline void bpPanelGetCenter(u8* work, u32 mode, u32 sub, f32 timer, f32* x, f32* y)
{
    if (mode == 3)
    {
        if (sub == 0)
        {
            *x = 61.5f + 41.5f * timer / 3.0f;
            *y = 388.5f - 27.5f * timer / 3.0f;
        }
        else if (bpPanelInTransition(sub))
        {
            *x = 103.0f - 41.5f * timer / 3.0f;
            *y = 361.0f + 27.5f * timer / 3.0f;
        }
        else
        {
            K_ASSERT(false, 0x185);
            *x = 103.0f;
            *y = 361.0f;
        }
    }
    else if (sub == 0)
    {
        *x = 103.0f;
        *y = 361.0f;
    }
    else if (bpPanelInTransition(sub))
    {
        *x = 61.5f;
        *y = 388.5f;
    }
    else
    {
        K_ASSERT(false, 0x185);
        *x = 103.0f;
        *y = 361.0f;
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

#pragma optimization_level 3

// FUN_0021f410 NONMATCHING
void func_0021f410(void)
{
    u8* work;
    void* texture;
    void* frame;
    u32 mode;
    u32 sub;
    u32 previous;
    u32 timerA;
    u32 timerB;
    u32 timerC;
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
    u32 i;

    K_ASSERT(BP_PANEL_GLOBAL != NULL, 0xe6);
    work = BP_PANEL_GLOBAL;
    K_ASSERT((*(u32*)work & 1) != 0, 0x151);
    texture = func_0021c3f0(0);
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
                *(u32*)work &= ~3;
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
                *(u32*)work &= ~9;
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
    bpPanelSetColor(work + 0x10, 0xff, 0xff, 0xff, 255.0f * dt);

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
            bpPanelSetColor(work + 0x1230, 0xff, 0xff, 0xff, 255.0f * factor * dt);
            bpPanelSetColor(work + 0x1330, 0xff, 0xff, 0xff, 255.0f * alpha * dt);
            break;
        case 1:
        case 2:
        case 3:
        case 4:
            factor = (3.0f - (f32)timerB) / 3.0f;
            alpha = (f32)timerB / 3.0f;
            bpPanelSetColor(work + 0x1230, 0xff, 0xff, 0xff, 255.0f * factor * dt);
            bpPanelSetColor(work + 0x1330, 0xff, 0xff, 0xff, 255.0f * alpha * dt);
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
        bpPanelSetColor(work + 0x1230, 0xff, 0xff, 0xff, 255.0f * factor * dt);
        bpPanelSetColor(work + 0x1330, 0xff, 0xff, 0xff,
                        255.0f * (4.0f - (f32)timerA) / 4.0f * dt);
    }
    else if (sub == 0)
    {
        bpPanelSetColor(work + 0x1230, 0xff, 0xff, 0xff, 255.0f * dt);
        bpPanelSetColor(work + 0x1330, 0xff, 0xff, 0xff, 0.0f);
    }
    else if (bpPanelInTransition(sub))
    {
        bpPanelSetColor(work + 0x1230, 0xff, 0xff, 0xff, 0.0f);
        bpPanelSetColor(work + 0x1330, 0xff, 0xff, 0xff, 255.0f * dt);
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
    bpPanelSetColor(work + 0x110, 0xff, 0xff, 0xff, 255.0f * dt);

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
    bpPanelSetColor(work + 0x210, 0xff, 0xff, 0xff, 255.0f * factor * dt);

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
    bpPanelSetColor(work + 0x1430, 0xff, 0xff, 0xff, 255.0f * factor * dt);

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
    bpPanelSetColor(work + 0x310, 0xff, 0xff, 0xff, 255.0f * arrowFactor * dt);

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
            bpPanelSetColor(work + 0xb10 + i * 0x100, red, green, blue,
                            255.0f * brightness * dt);
            bpPanelSetColor(work + 0x410 + i * 0x100, 0xff, 0xff, 0xff,
                            255.0f * brightness * (1.0f - selectionFactor) * dt);
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
            bpPanelSetColor(work + 0xb10 + i * 0x100, red, green, blue,
                            255.0f * brightness * arrowFactor * dt);
            bpPanelSetColor(work + 0x410 + i * 0x100, 0xff, 0xff, 0xff,
                            255.0f * arrowFactor * brightness * selectionFactor * dt);
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
            bpPanelSetColor(work + 0xb10 + i * 0x100, red, green, blue,
                            255.0f * arrowFactor * dt);
            bpPanelSetColor(work + 0x410 + i * 0x100, 0xff, 0xff, 0xff,
                            255.0f * arrowFactor * brightness * selectionFactor * dt);
        }
    }

    sub = *(u32*)(work + 0x463c);
    if (*(u32*)(work + 0x4658) < 6)
    {
        switch (sub)
        {
        case 2:
        case 1:
        case 3:
        case 4:
            func_002265d0();
            break;
        }
    }
    previous = *(u32*)(work + 0x4640);
    if (*(u32*)(work + 0x4650) != 3)
    {
        switch (previous)
        {
        case 3:
        case 4:
        case 1:
        case 2:
            func_002265d0();
            break;
        }
    }
    sub = *(u32*)(work + 0x463c);
    switch (sub)
    {
    case 3:
        switch (*(u32*)(work + 0x4644))
        {
        case 1:
            func_00227f30();
            break;
        case 0:
            switch (*(u32*)(work + 0x4648))
            {
            case 1:
                if (*(u32*)(work + 0x4658) != 6)
                {
                    func_00227f30();
                }
                break;
            }
            break;
        }
        break;
    }
    sub = *(u32*)(work + 0x463c);
    switch (sub)
    {
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
    switch (sub)
    {
    case 3:
        switch (*(u32*)(work + 0x4644))
        {
        case 0:
            switch (*(u32*)(work + 0x4648))
            {
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
        break;
    }
}
#pragma optimization_level 2


static void bpPanelDrawBridgeQuad(u8* work, u32 offset, void* texture, s32 frameId)
{
    void* frame;

    frame = func_0021cca0(texture, frameId);
    bpPanelBindAndDraw(work, offset, frame);
}

// FUN_00221b60 NONMATCHING
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
        currentFrame = func_0021cca0(frame, (s32)*(u32*)(work + 0x4634));
        previousFrame = func_0021cca0(texture, (s32)*(u32*)(work + 0x4638));
        mask |= 1;
        if (*(u32*)(work + 0x464c) != 4)
        {
            mask |= 2;
        }
        break;
    case 3:
        currentFrame = func_0021cca0(texture, (s32)*(u32*)(work + 0x4634));
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
            currentFrame = func_0021cca0(texture, (s32)*(u32*)(work + 0x4634));
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
        func_00227800();
        break;
    case 0:
        previousSub = *(u32*)(work + 0x4640);
        switch (previousSub)
        {
        case 3:
        case 4:
            if (*(u32*)(work + 0x4650) != 3)
            {
                func_00227800();
            }
            break;
        }
        break;
    }

    sub = *(u32*)(work + 0x463c);
    if (sub == 2 ||
        (sub == 0 && *(u32*)(work + 0x4640) == 2 &&
         *(u32*)(work + 0x4650) < 3))
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
              *(u32*)(work + 0x4650) < 3))
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
              *(u32*)(work + 0x4650) < 3))
    {
        func_00225040();
    }

    sub = *(u32*)(work + 0x463c);
    if (sub == 3 ||
        (sub == 0 && *(u32*)(work + 0x4640) == 3 &&
         *(u32*)(work + 0x4650) < 3))
    {
        func_00224150();
    }

    if (*(u32*)(work + 0x463c) == 3)
    {
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
    }

    if (*(u32*)(work + 0x463c) != 3)
    {
        return;
    }
    switch (*(u32*)(work + 0x4644))
    {
    case 0:
        if ((*(u32*)(work + 0x4648) == 1 ||
             *(u32*)(work + 0x4648) == 2) &&
            *(u32*)(work + 0x4658) < 6)
        {
            func_00226040();
            return;
        }
        return;
    case 1:
    case 2:
        func_00226040();
        break;
    }
}
