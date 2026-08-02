#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Result/br_res.h"
#include "rw/rwplcore.h"

#pragma alias brRes00234570_y2 brRes00234570

#pragma alias datGetScenarioMode_y2 datGetScenarioMode


extern int H_Cdvd_IsFileLoaded(u32 request);
extern void H_Cdvd_Destroy(u32 request);
extern void* H_Cdvd_ArchiveGetFile(u32 archive, s32 index, u32* size);
extern u32 bpTex0021c9f0(void* data);
extern u32 bpTexCreateTmxRaster(void* data);
extern void func_0021cc20(u32 texture);
extern void func_004cde90(u32 resource);
extern void* memcpy(void* dest, const void* src, u32 size);
extern void (*jtbl_0096017C)(void* memory);

static u32* sBrRes; // puGpffffb61c
extern char DAT_0068e6b0[];
extern char DAT_0068e6d0[];
extern char DAT_0068e6f0[];
extern char DAT_0068e710[];
extern char DAT_0068e730[];
extern char DAT_0068e750[];
extern char DAT_0068e770[];
int datGetScenarioMode();
u32 datGetFlag(s32 bit);
u32 H_Cdvd_Request(const char* path, u32 fileMode);

// FUN_00233970
void brRes00233970(u32* param_1)
{
    K_ASSERT(sBrRes == NULL, 0x58);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    sBrRes = param_1;
}


// FUN_002339d0
void brRes002339d0(void)
{
    u32* puVar1;
    int lVar3;

    K_ASSERT(sBrRes != NULL, 0x52);
    puVar1 = sBrRes;
    K_ASSERT((~*puVar1 & 1) != 0, 0x65);
    lVar3 = datGetScenarioMode();
    if (lVar3 != 0) {
        lVar3 = datGetFlag(0x2f0);
        if (lVar3 != 0) {
            puVar1[3] = H_Cdvd_Request(DAT_0068e6b0, 1);
        } else {
            puVar1[3] = H_Cdvd_Request(DAT_0068e6d0, 1);
        }
    } else {
        puVar1[3] = H_Cdvd_Request(DAT_0068e6f0, 1);
    }
    *puVar1 |= 1;
}

// FUN_00233ad0
u32 brRes00233ad0(void)
{
    K_ASSERT(sBrRes != NULL, 0x52);
    return *sBrRes & 1;
}

// FUN_00233b20
void brRes00233b20(void)
{
    u32* puVar1;

    K_ASSERT(sBrRes != NULL, 0x52);
    puVar1 = sBrRes;
    K_ASSERT((~*puVar1 & 2) != 0, 0x7e);
    puVar1[4] = H_Cdvd_Request(DAT_0068e710, 1);
    *puVar1 |= 2;
}

// FUN_00233bb0
u32 brRes00233bb0(void)
{
    K_ASSERT(sBrRes != NULL, 0x52);
    return *sBrRes & 2;
}

// FUN_00233c00
void brRes00233c00(void)
{
    u32* puVar1;
    int lVar3;

    K_ASSERT(sBrRes != NULL, 0x52);
    puVar1 = sBrRes;
    K_ASSERT((~*puVar1 & 4) != 0, 0x8c);
    K_ASSERT((~puVar1[1] & 0x10) != 0, 0x8d);
    lVar3 = datGetScenarioMode();
    if (lVar3 != 0) {
        lVar3 = datGetFlag(0x2f0);
        if (lVar3 != 0) {
            puVar1[5] = H_Cdvd_Request(DAT_0068e730, 1);
        } else {
            puVar1[5] = H_Cdvd_Request(DAT_0068e750, 1);
        }
    } else {
        puVar1[5] = H_Cdvd_Request(DAT_0068e770, 1);
    }
    *puVar1 |= 4;
}

// FUN_00233d20
u32 brRes00233d20(void)
{
    K_ASSERT(sBrRes != NULL, 0x52);
    return sBrRes[0] & 4;
}

// FUN_00233d70
u32 brRes00233d70(s32 index)
{
    u32* work;

    K_ASSERT(sBrRes != NULL, 0x52);
    work = sBrRes;
    K_ASSERT(work[1] & 0x10, 0xb3);
    return work[index + 0xe];
}

// FUN_00233df0
u32 brRes00233df0(s32 index)
{
    u32* work;

    K_ASSERT(sBrRes != NULL, 0x52);
    work = sBrRes;
    K_ASSERT(work[1] & 0x10, 0xba);
    return work[index + 0x12];
}

// FUN_00233e70
void brRes00233e70(void)
{
    s32 i;
    u32* work;

    K_ASSERT(sBrRes != NULL, 0x52);
    work = sBrRes;
    if (work[1] & 1) {
        func_0021cc20(work[7]);
    }
    if (work[1] & 2) {
        func_0021cc20(work[8]);
    }
    if (work[1] & 4) {
        for (i = 0; i < 2; i++) {
            (*(void (**)(void*))0x0096017C)(*(void**)((u8*)work + i * 4 + 0x24));
        }
    }
    if (work[1] & 0x40) {
        for (i = 0; i < 2; i++) {
            func_0021cc20(*(u32*)((u8*)work + i * 4 + 0x30));
        }
    }
    if (work[1] & 0x20) {
        (*(void (**)(void*))0x0096017C)((void*)work[11]);
    }
    if (work[1] & 0x10) {
        K_ASSERT(sBrRes != NULL, 0x52);
        work = sBrRes;
        K_ASSERT(work[1] & 0x10, 0xa5);
        for (i = 0; i < 4; i++) {
            func_0021cc20(*(u32*)((u8*)work + i * 4 + 0x38));
        }
        for (i = 0; i < 2; i++) {
            func_004cde90(*(u32*)((u8*)work + i * 4 + 0x48));
        }
        work[1] &= ~0x10;
    }
    sBrRes = NULL;
}

// FUN_00234070
void brRes00234070(void)
{
    u32* work;
    void* data;
    s32 i;
    u32 flags;
    u32 size;

    K_ASSERT(sBrRes != NULL, 0x52);
    work = sBrRes;
    if (work[0] & 1) {
        flags = work[1];
        if (~flags & 1) {
            K_ASSERT((~flags & 2) != 0, 0xea);
            if (H_Cdvd_IsFileLoaded(work[3])) {
                for (i = 0; i < 2; i++) {
                    switch (i) {
                    case 0:
                        work[7] = bpTex0021c9f0(H_Cdvd_ArchiveGetFile(work[3], i, &size));
                        work[1] |= 1;
                        break;
                    case 1:
                        work[8] = bpTex0021c9f0(H_Cdvd_ArchiveGetFile(work[3], i, &size));
                        work[1] |= 2;
                        break;
                    default:
                        K_ASSERT(0, 0xfe);
                    }
                }
                H_Cdvd_Destroy(work[3]);
            }
        } else {
            K_ASSERT((flags & 1) && (flags & 2), 0x109);
        }
        if ((work[1] & 1) && (work[1] & 2)) {
            work[0] &= ~1;
        }
    }
    if ((work[0] & 2) && H_Cdvd_IsFileLoaded(work[4])) {
        for (i = 0; i < 5; i++) {
            switch (i) {
            case 0:
            {
                void* copy;
                data = H_Cdvd_ArchiveGetFile(work[4], i, &size);
                copy = (*(void* (**)(u32, u32))0x00960178)(size, 0x40000);
                work[9] = (u32)copy;
                memcpy(copy, data, *(volatile /* Removing this function's qualifier batch loses brRes00234070 (MATCH nd0 -> MISMATCH nd28, size 1276 -> 1276) - measured W170. */ u32*)&size);
                break;
            }
            case 1:
            {
                void* copy;
                data = H_Cdvd_ArchiveGetFile(work[4], i, &size);
                copy = (*(void* (**)(u32, u32))0x00960178)(size, 0x40000);
                work[10] = (u32)copy;
                memcpy(copy, data, *(volatile /* Removing this function's qualifier batch loses brRes00234070 (MATCH nd0 -> MISMATCH nd28, size 1276 -> 1276) - measured W170. */ u32*)&size);
                break;
            }
            case 2:
                brRes00234710(H_Cdvd_ArchiveGetFile(work[4], i, &size), *(volatile /* Removing this function's qualifier batch loses brRes00234070 (MATCH nd0 -> MISMATCH nd28, size 1276 -> 1276) - measured W170. */ u32*)&size);
                break;
            case 3:
                brRes00234690(0, H_Cdvd_ArchiveGetFile(work[4], i, &size));
                break;
            case 4:
                brRes00234690(1, H_Cdvd_ArchiveGetFile(work[4], i, &size));
                break;
            default:
                K_ASSERT(0, 0x132);
            }
        }
        work[1] |= 4;
        H_Cdvd_Destroy(work[4]);
        work[0] &= ~2;
    }
    if ((work[0] & 4) && H_Cdvd_IsFileLoaded(work[5])) {
        for (i = 0; i < 6; i++) {
            void* archiveData;
            archiveData = H_Cdvd_ArchiveGetFile(work[5], i, &size);
            switch (i) {
            case 0:
                work[0xe] = bpTex0021c9f0(archiveData);
                break;
            case 1:
                work[0x12] = bpTexCreateTmxRaster(archiveData);
                break;
            case 2:
                work[0x13] = bpTexCreateTmxRaster(archiveData);
                break;
            case 4:
                work[0xf] = bpTex0021c9f0(archiveData);
                break;
            case 5:
                work[0x10] = bpTex0021c9f0(archiveData);
                break;
            case 3:
                work[0x11] = bpTex0021c9f0(archiveData);
                break;
            default:
                K_ASSERT(0, 0x159);
            }
        }
        H_Cdvd_Destroy(work[5]);
        work[1] |= 0x10;
        work[0] &= ~4;
    }
}

// FUN_00234570
u32 brRes00234570_y2(s32 index)
{
    K_ASSERT(sBrRes != NULL, 0x52);
    return sBrRes[index + 7];
}

// FUN_002345d0
u32 brRes002345d0(s32 index)
{
    K_ASSERT(sBrRes != NULL, 0x52);
    return sBrRes[index + 9];
}

// FUN_00234630
u32 brRes00234630(s32 index)
{
    K_ASSERT(sBrRes != NULL, 0x52);
    return sBrRes[index + 0xc];
}

// FUN_00234690
void brRes00234690(s32 index, void* data)
{
    u32* work;
    u32 texture;

    K_ASSERT(sBrRes != NULL, 0x52);
    work = sBrRes;
    texture = bpTex0021c9f0(data);
    work[index + 0xc] = texture;
    work[1] |= 0x40;
}

// FUN_00234710
void brRes00234710(void* data, u32 size)
{
    u32* work;
    void* copy;

    K_ASSERT(sBrRes != NULL, 0x52);
    work = sBrRes;
    K_ASSERT((~work[1] & 0x20) != 0, 0x182);
    copy = (*(void* (**)(u32, u32))0x00960178)(size, 0x40000);
    memcpy(copy, data, size);
    work[11] = (u32)copy;
    work[1] |= 0x20;
}

// FUN_002347e0
u32 brRes002347e0(void)
{
    K_ASSERT(sBrRes != NULL, 0x52);
    return sBrRes[11];
}


#include "Main/Battle/Result/br_panel.h"

#define BR_PANEL_WORD(offset) (*(u32*)((u8*)sBrPanel + (offset)))
#define BR_PANEL_ENTRY(index) ((u8*)sBrPanel + 0xe20 + (index) * 0x510)

static u32* sBrPanel; // puGpffffb620

extern void func_003b0170(u32 resource);
extern void func_003b0e20(u32 resource, u32 color);
extern void func_003b0e70(s32 state);
extern void func_003b0e90(s32 state);
extern u32 func_003b0970(u32 type, s32 a, s32 b, s32 c, s32 d);
extern u32 func_00177790(s16 pcId);
extern u8 datGetLevel(s16 pcId);
extern const char* func_00171110(s16 id, s16 field);
extern void bpIFont00238980(void* glyphs, s32 capacity, s32 value, s32 style);
extern void func_003b1360(u32 resource, s32 visible, s32 flags);
extern void func_003b2c60(u32 resource, float value);
extern float func_0021ea00(s32 duration);
extern void func_0021eac0(void* animation, float value);
extern void* func_0021cca0(u32 texture, s32 frame);
extern void func_0021d3b0(void* panel, void* source);
extern void func_0021e380(void* panel, void* source, s32 mode);
extern void func_0021d8e0(void* panel, const float* rect);
extern void func_0021d950(void* panel, const u8* color);
extern int sprintf(char* buffer, const char* format, ...);
extern u32 strlen(const char* string);
extern void (*D_00960090)(u32 state, u32 value);
extern void (*D_0096009C)(u32* quad, u32 primitive, u32 offset, u32 first, u32 second);
/* Retail +0x84/+0x114 materialize the state/quad callback-table addresses. */
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
#pragma alias D_0096009C_abs D_0096009C
extern u8 D_0096009C_abs[];
#pragma alias brPanelSetStateRaw D_00960090
#pragma alias brPanelSetQuadRaw D_0096009C
extern void (*brPanelSetStateRaw)(u32 state, u32 value);
extern void (*brPanelSetQuadRaw)(u32* quad, u32 primitive, u32 offset, u32 first, u32 second);
extern void RpSkyRenderStateSet(s32 state, u32 value);
extern u32 func_0021cce0(void* frame);
extern u32 func_00239140(s32 index);
#pragma alias brPanelResRaw brRes00234570
extern u32 brPanelResRaw(s32 type);
extern void func_003b0d70(u32 resource, s32 offset, s32 flags);
extern u32 datGetScenarioMode_y2(void);
extern f32 sqrtf(f32 value);
extern f32 DAT_007caff0;
extern void bpIFont00238a50(void* glyphs, s32 capacity, s32 value, s32 style, const float* origin);

static void brPanel002361d0(void* glyph, s32 digit, s32 style);
static void brPanel00236390(void);

static void brPanelSetQuad(void* quad, float x, float y, float width, float height)
{
    float rect[4];

    rect[0] = x;
    rect[1] = y;
    rect[2] = width;
    rect[3] = height;
    func_0021d8e0(quad, rect);
}

static void brPanelSetColor(void* quad, u8 red, u8 green, u8 blue, u8 alpha)
{
    u8 color[4];

    color[0] = red;
    color[1] = green;
    color[2] = blue;
    color[3] = alpha;
    func_0021d950(quad, color);
}

// FUN_00234820
void brPanel00234820(u32* work)
{
    float rect[4];
    u8 color[4];

    work[0] = 0;
    work[0x1d50 / 4] = 0;
    func_003b0e70(1);
    func_003b0e90(2);
    work[0x310 / 4] = func_003b0970(func_00177790(1), 1, 6, 0, 0);
    func_003b0e90(1);
    func_003b0e70(2);
    func_003b0e20(work[0x310 / 4], 0xffffff);
    func_003b2c60(work[0x310 / 4],
                  *(f32*)(uintptr_t)0x00960088 - func_0021ea00(0x28));
    rect[0] = 0.0f;
    rect[1] = 0.0f;
    rect[2] = 640.0f;
    rect[3] = 448.0f;
    func_0021d8e0((u8*)work + 0x2560, rect);
    func_0021eac0(work + 0x958, func_0021ea00(10));
    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = 0;
    func_0021d950((void*)((uintptr_t)work + 0x2560), color);
    work[0x2660 / 4] = datGetLevel(1) & 0xff;
    sBrPanel = work;
}




/* Retail +0x84 and +0x114 reload these callback tables before their jalr sites. */
#define D_00960090 (*brPanelSetState)
#define D_0096009C (*brPanelSetQuad)
#pragma opt_loop_invariants off
#undef D_00960090
#undef D_0096009C
#pragma optimization_level 2







#pragma optimization_level 3
#define brRes00234570(x) ((x) == 0 ? texture : digitTexture)
#define BR_PANEL_SET_RECT(dst, x, y, w, h) \
    do { \
        rect[0] = (x); \
        rect[1] = (y); \
        rect[2] = (w); \
        rect[3] = (h); \
        func_0021d8e0((dst), rect); \
    } while (0)
#define BR_PANEL_SET_VERTICES(dst) \
    do { func_0021d890((dst), rect); } while (0)
#define BR_PANEL_ANIMATE(dst, duration) \
    do { anim = func_0021ea00((duration)); \
         func_0021eac0((dst), anim); } while (0)
#define BR_PANEL_SET_COLOR(dst, alpha) \
    do { \
        color[0] = 0xff; \
        color[1] = 0xff; \
        color[2] = 0xff; \
        color[3] = (u8)(u32)(255.0f * (alpha)); \
        func_0021d950((dst), color); \
    } while (0)
#undef brRes00234570
#undef BR_PANEL_SET_RECT
#undef BR_PANEL_SET_VERTICES
#undef BR_PANEL_ANIMATE
#undef BR_PANEL_SET_COLOR
#pragma optimization_level 2
