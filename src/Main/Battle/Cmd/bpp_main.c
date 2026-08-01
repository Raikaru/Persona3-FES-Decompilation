#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Panel/bpp_panel.h"
#include "Main/Battle/Cmd/bpp_main.h"



static u32* sBppMain; // DAT_007ce2f4
void bppMain0020f680(void);
u8* bppMain0020f720(s16 pcId);
#pragma alias bppMain0020f720_u16 bppMain0020f720
extern u8* bppMain0020f720_u16(u16 pcId);

extern void* btlOrderGetActionPlaying(void);
extern u32 func_0029b0c0(void* action);
extern s32 bpMisc001ff5b0(void);
extern s16 func_001ff630(s32 index);
extern void* func_001ff430(u32 id);
extern u16 datGetHp(s16 pcId);
extern u16 datGetMaxHp(s16 pcId);
extern u32 datGetBadStatusNoDown(s16 pcId);
extern u16 datGetSp(s16 pcId);
extern u16 func_0016c670(s16 pcId);
extern u16 datGetPhysicalCondition(s16 pcId);
extern void func_0022c720(void* panel, u16 pcId);
extern void func_0022c850(void* panel);
extern void func_0022c8a0(void* panel);
extern void func_0022df10(void* panel);
extern void func_0022e780(void* panel);
extern void func_0022e900(void* panel, u32 value);
extern void func_0022e9a0(void* panel, u32 value);
extern void func_0022f1c0(void* panel, u32 value);

#define BPP_MAIN_ENTRY_STRIDE 0x1690
#define BPP_MAIN_ENTRY_BASE 0x10

static u8* bppMainEntry(s32 index)
{
    return (u8*)sBppMain + index * BPP_MAIN_ENTRY_STRIDE;
}

static u8* bppMainFindEntry(s16 pcId)
{
    s32 i;
    u8* entry;

    K_ASSERT(sBppMain != NULL, 0x43);
    for (i = 0; i < (s32)sBppMain[0x1694]; i++) {
        entry = bppMainEntry(i);
        if (*(s16*)(entry + 0x14) == pcId) {
            return entry + BPP_MAIN_ENTRY_BASE;
        }
    }
    K_ASSERT(0, 0x19c);
    return NULL;
}

static void bppMainSetDetailForUnit(u32* work, void* unit)
{
    s16 pcId;
    u8* entry;

    if (unit == NULL || *(u8*)((u8*)unit + 0xa2) != 0) {
        return;
    }
    pcId = *(s16*)((u8*)unit + 0xa2c + 2);
    entry = bppMainFindEntry(pcId);
    bppPanelActivateDetail((BppPanelWork*)(entry + 0x20));
    work[0x1696] = (u32)(u16)pcId;
    *work |= 4;
}

static void bppMainClearDetailForUnit(u32* work, void* unit)
{
    s16 pcId;
    u8* entry;

    if (unit == NULL || *(u8*)((u8*)unit + 0xa2) != 0) {
        return;
    }
    pcId = *(s16*)((u8*)unit + 0xa2c + 2);
    entry = bppMainFindEntry(pcId);
    bppPanelDeactivateDetail((BppPanelWork*)(entry + 0x20));
    *work &= ~4u;
}


// FUN_0020ed70
void bppMain0020ed70(void)
{
    K_ASSERT(sBppMain != NULL, 0x43);
    *sBppMain |= 0x80;
}

// FUN_0020edc0
void bppMain0020edc0(void)
{
    bppMain0020f680();
    sBppMain = NULL;
}

/* Removing this worsens bppMain0020edf0 (nd135 -> nd794) - measured W161. */
#pragma optimization_level 1
// FUN_0020edf0
void bppMain0020edf0(void)
{
    s32 i;
    void* action;
    u32* work;
    u8* entry;
    u32 value;
    u32 badStatus;
    s32 masked;
    u32 actionId;
    u32 flags;
    u32 initialFlags;
    s32 transition;

    K_ASSERT(sBppMain != NULL, 0x43);
    work = sBppMain;
    initialFlags = *work;
    if ((~initialFlags & 0x80) != 0) {
        return;
    }

    if ((initialFlags & 0x10) != 0 || (initialFlags & 0x20) != 0 ||
        (initialFlags & 0x40) != 0) {
        s32 decrement;

        decrement = (s32)work[0x1697];
        if (decrement > 0) {
            work[0x1697] = decrement - 1;
        }
    } else {
        transition = (s32)work[0x1697];
        if (transition < (s32)work[0x1698]) {
            work[0x1697] = transition + 1;
        }
    }

    if ((*work & 2) != 0) {
        action = btlOrderGetActionPlaying();
        if (action != NULL && (*work & 1) != 0 &&
            *(u32*)((u8*)*(void**)((u8*)action + 0x30) + 0xa8) ==
                work[0x1695] &&
            func_0029b0c0(action) == 0) {
            action = func_001ff430(work[0x1695]);
            switch (*(u8*)((u8*)action + 0xa2)) {
            case 0:
                K_ASSERT((*work & 4) != 0, 0x93);
                bppPanelDeactivateDetail((BppPanelWork*)(
                    bppMain0020f720_u16(
                        *(u16*)((u8*)*(void**)((u8*)action + 0xa2c) + 2)) + 0x20));
                break;
            }
            *work &= ~4u;
            *work &= ~1u;
        } else if (action != NULL && ((flags = *work) & 1) != 0 &&
                   ((actionId = work[0x1695]),
                    *(u32*)((u8*)*(void**)((u8*)action + 0x30) + 0xa8) != actionId)) {
            if ((flags & 4) != 0) {
                void* unit;
                unit = func_001ff430(actionId);

                switch (*(u8*)((u8*)unit + 0xa2)) {
                case 0:
                    K_ASSERT((*work & 4) != 0, 0xad);
                    bppPanelDeactivateDetail((BppPanelWork*)(
                        bppMain0020f720_u16(
                            *(u16*)((u8*)*(void**)((u8*)unit + 0xa2c) + 2)) + 0x20));
                    break;
                }
                *work &= ~4u;
            }
            *work &= ~1u;
            if (func_0029b0c0(action) != 0) {
                void* actionUnit;

                actionUnit = *(void**)((u8*)action + 0x30);
                switch (*(u8*)((u8*)actionUnit + 0xa2)) {
                case 0:
                    bppPanelActivateDetail((BppPanelWork*)(
                        bppMain0020f720_u16(
                            *(u16*)((u8*)*(void**)((u8*)actionUnit + 0xa2c) + 2)) + 0x20));
                    *(u16*)((u8*)work + 0x5a58) =
                        *(u16*)((u8*)*(void**)((u8*)*(void**)((u8*)action + 0x30) + 0xa2c) + 2);
                    *work |= 4;
                    break;
                }
                work[0x1695] =
                    *(u32*)((u8*)*(void**)((u8*)action + 0x30) + 0xa8);
                *work |= 1;
            }
        } else if (action != NULL && (~*work & 1) != 0 &&
                   func_0029b0c0(action) != 0) {
            void* actionUnit;

            actionUnit = *(void**)((u8*)action + 0x30);
            switch (*(u8*)((u8*)actionUnit + 0xa2)) {
            case 0:
                bppPanelActivateDetail((BppPanelWork*)(
                    bppMain0020f720_u16(
                        *(u16*)((u8*)*(void**)((u8*)actionUnit + 0xa2c) + 2)) + 0x20));
                *(u16*)((u8*)work + 0x5a58) =
                    *(u16*)((u8*)*(void**)((u8*)*(void**)((u8*)action + 0x30) + 0xa2c) + 2);
                *work |= 4;
                break;
            }
            work[0x1695] =
                *(u32*)((u8*)*(void**)((u8*)action + 0x30) + 0xa8);
            *work |= 1;
        }
    }

    for (i = 0; i < (s32)work[0x1694]; i++) {
        entry = (u8*)work + i * BPP_MAIN_ENTRY_STRIDE + BPP_MAIN_ENTRY_BASE;
        value = datGetHp(*(s16*)(entry + 4));
        if (*(u32*)(entry + 0x10) != value) {
            *(u32*)(entry + 0x10) = value;
            func_0022e900(entry + 0x20, value);
        }
        value = datGetSp(*(s16*)(entry + 4));
        if (*(u32*)(entry + 0x14) != value) {
            *(u32*)(entry + 0x14) = value;
            func_0022e9a0(entry + 0x20, value);
        }
        badStatus = datGetBadStatusNoDown(*(s16*)(entry + 4));
        masked = badStatus & 0xfffff;
        if (*(u32*)(entry + 0x18) != masked) {
            *(u32*)(entry + 0x18) = masked;
            func_0022f1c0(entry + 0x20, badStatus);
        }
        value = datGetPhysicalCondition(*(s16*)(entry + 4));
        if (*(u32*)(entry + 0x1c) != value) {
            *(u32*)(entry + 0x1c) = value;
            func_0022e780(entry + 0x20);
        }
    }
}
#pragma optimization_level 2

// FUN_0020f260
void bppMain0020f260(void)
{
    u32* work;
    u8* entry;
    f32 alpha;
    u32 transition;
    s32 i;
    s32 reverse;

    K_ASSERT(sBppMain != NULL, 0x43);
    work = sBppMain;
    if ((~*work & 0x80) != 0) {
        return;
    }
    for (i = 0; i < (s32)work[0x1694]; i++) {
        entry = (u8*)work + i * BPP_MAIN_ENTRY_STRIDE + BPP_MAIN_ENTRY_BASE;
        reverse = ((s32)work[0x1694] - 1 - i) * 2;
        transition = work[0x1697];
        if ((s32)transition < reverse) {
            alpha = 0.0f;
        } else if ((s32)transition < reverse + 6) {
            alpha = (f32)((s32)transition - reverse) / 6.0f;
        } else {
            alpha = 1.0f;
        }
        bppPanelSetPrimaryAnimation(alpha, (BppPanelWork*)(entry + 0x20));
        bppPanelSetSecondaryAnimation(1.0f, (BppPanelWork*)(entry + 0x20));
        func_0022c8a0(entry + 0x20);
        func_0022df10(entry + 0x20);
    }
}

// FUN_0020f3b0
void bppMain0020f3b0(void)
{
    u32* work;
    u8* entry;
    s32 count;
    s32 oldDuration;
    s32 transition;
    s32 i;

    K_ASSERT(sBppMain != NULL, 0x43);
    work = sBppMain;
    count = bpMisc001ff5b0();
    for (i = 0; i < count; i++) {
        entry = (u8*)work + i * BPP_MAIN_ENTRY_STRIDE + BPP_MAIN_ENTRY_BASE;
        *(u32*)entry = 0;
        *(s16*)(entry + 4) = func_001ff630(i);
        *(u32*)(entry + 0x10) = 0xffffffff;
        *(u32*)(entry + 0x14) = 0xffffffff;
        *(u32*)(entry + 0x18) = 0xffffffff;
        *(u32*)(entry + 0x1c) = 0xffffffff;
    }
    oldDuration = work[0x1698];
    transition = work[0x1697];
    work[0x1698] = (count - 1) * 2 + 6;
    if (oldDuration != 0) {
        work[0x1697] =
            (transition * (s32)work[0x1698]) / oldDuration;
    } else {
        work[0x1697] = 0;
    }
    work[0x1694] = count;
    for (i = 0; i < (s32)work[0x1694]; i++) {
        entry = (u8*)work + i * BPP_MAIN_ENTRY_STRIDE + BPP_MAIN_ENTRY_BASE;
        func_0022c720(entry + 0x20, *(u16*)(entry + 4));
        *(u32*)(entry + 0x530) = 0x43ee0000;
        *(f32*)(entry + 0x534) = (f32)i * 100.0f + 4.0f;
        *(u32*)(entry + 0x858) =
            datGetMaxHp(*(s16*)(entry + 4)) & 0xffff;
        *(u32*)(entry + 0x860) =
            func_0016c670(*(s16*)(entry + 4)) & 0xffff;
    }
    *work |= 2;
}

// FUN_0020f570
void bppMain0020f570(void)
{
    u32* work;
    s32 count;
    s32 i;
    u8* bppMain0020f720();

    K_ASSERT(sBppMain != NULL, 0x43);
    work = sBppMain;
    bppMain0020f680();
    bppMain0020f3b0();
    if ((*work & 4) != 0) {
        count = bpMisc001ff5b0();
        for (i = 0; i < count; i++) {
            if ((u16)work[0x1696] == (u16)func_001ff630(i)) {
                break;
            }
        }
        if (i == count) {
            *work &= ~4u;
            *work &= ~1u;
        } else {
            bppPanelShow((BppPanelWork*)(
                bppMain0020f720((u16)work[0x1696]) + 0x20));
        }
    }
}

// FUN_0020f680
void bppMain0020f680(void)
{
    u32* work;
    s32 i;

    K_ASSERT(sBppMain != NULL, 0x43);
    work = sBppMain;
    for (i = 0; i < (s32)work[0x1694]; i++) {
        func_0022c850((u8*)work + i * BPP_MAIN_ENTRY_STRIDE + 0x30);
    }
    work[0x1694] = 0;
    *work &= ~2u;
}

static inline u8* bppMainLookupEntry(s16 pcId)
{
    s32 i;
    u8* entry;
    u32* work;
    u32 id;
    u8* result;
    s32 count;
    s32 stride;

    K_ASSERT(sBppMain != NULL, 0x43);
    work = sBppMain;
    i = 0;
    id = (u16)pcId;
    count = (s32)work[0x1694];
    stride = BPP_MAIN_ENTRY_STRIDE;
    for (; i < count; i++) {
        entry = (u8*)work + i * stride;
        result = entry + BPP_MAIN_ENTRY_BASE;
        if (*(u16*)(entry + 0x14) == id) {
            return result;
        }
    }
    K_ASSERT(0, 0x19c);
    return NULL;
}

/* Removing this loses bppMain0020f720 (MATCH nd0 -> MISMATCH nd23); loses bppMain0020f7d0 (MATCH nd0 -> MISMATCH nd28); loses bppMain0020f8b0 (MATCH nd0 -> MISMATCH nd28); loses bppMain0020f9a0 (MATCH nd0 -> MISMATCH nd24); loses bppMain0020fa80 (MATCH nd0 -> MISMATCH nd24); loses bppMain0020fb60 (MATCH nd0 -> MISMATCH nd24) - measured W161. */
// FUN_0020f720
#pragma optimization_level 1
u8* bppMain0020f720(s16 pcId)
{
    return bppMainLookupEntry(pcId);
}

// FUN_0020f7d0
void bppMain0020f7d0(s16 pcId)
{
    u8* entry;

    K_ASSERT(sBppMain != NULL, 0x43);
    entry = bppMainLookupEntry(pcId);
    *(u32*)entry |= 1;
    bppPanelRequestStatusRefresh((BppPanelWork*)(entry + 0x20));
}

// FUN_0020f8b0
void bppMain0020f8b0(s16 pcId)
{
    u8* entry;

    K_ASSERT(sBppMain != NULL, 0x43);
    entry = bppMainLookupEntry(pcId);
    *(u32*)entry &= ~1u;
    bppPanelCancelStatusRefresh((BppPanelWork*)(entry + 0x20));
}

// FUN_0020f9a0
void bppMain0020f9a0(s16 pcId)
{
    K_ASSERT(sBppMain != NULL, 0x43);
    bppPanelRequestHide((BppPanelWork*)(bppMainLookupEntry(pcId) + 0x20));
}

// FUN_0020fa80
void bppMain0020fa80(s16 pcId)
{
    K_ASSERT(sBppMain != NULL, 0x43);
    bppPanelEnableActionOverlay((BppPanelWork*)(bppMainLookupEntry(pcId) + 0x20));
}

// FUN_0020fb60
void bppMain0020fb60(s16 pcId)
{
    K_ASSERT(sBppMain != NULL, 0x43);
    bppPanelDisableActionOverlay((BppPanelWork*)(bppMainLookupEntry(pcId) + 0x20));
}
#pragma optimization_level 2


// FUN_0020fc40
void bppMain0020fc40(void)
{
    K_ASSERT(sBppMain != NULL, 0x43);
    *sBppMain |= 0x10;
}

// FUN_0020fc90
void bppMain0020fc90(void)
{
    K_ASSERT(sBppMain != NULL, 0x43);
    *sBppMain &= 0xffffffef;
}
// FUN_0020fce0
void bppMain0020fce0(void)
{
    K_ASSERT(sBppMain != NULL, 0x43);
    *sBppMain |= 0x20;
}

// FUN_0020fd30
void bppMain0020fd30(void)
{
    K_ASSERT(sBppMain != NULL, 0x43);
    *sBppMain &= 0xffffffdf;
}

// FUN_0020fd80
void bppMain0020fd80(void)
{
    K_ASSERT(sBppMain != NULL, 0x43);
    *sBppMain |= 0x40;
}

// FUN_0020fdd0
void bppMain0020fdd0(void)
{
    K_ASSERT(sBppMain != NULL, 0x43);
    *sBppMain &= 0xffffffbf;
}


#include "Utils.h"
#include "Main/Battle/Result/bp_ifont.h"
#include "Main/Battle/Data/datUnit.h"

/*
 * Battle status/analyze (BSA) owns one large, contiguous panel work area.  The
 * retail code addresses this area as an array of words; keeping that view here
 * makes the offsets explicit and also documents the shared layout used by the
 * panel renderer.
 */
typedef struct BsaWork
{
    u32 words[0x29b0];
} BsaWork;

typedef int (*code)(...);

extern u32 DAT_007ce4e8;
extern u8* DAT_007ce410;
extern code D_00960090;
#pragma alias D_00960090_abs D_00960090
#pragma alias D_0096009C_abs D_0096009C
extern u8 D_00960090_abs[];
extern u8 D_0096009C_abs[];
extern code D_0096009C;

extern void func_0017b1e0(u16 id);
extern s32 func_0017d2e0(void);
extern u32 func_0010a4e0(s32 a, s32 b, s32 c, s32 d);

extern u32 func_0021c3f0(s32 texture);
extern u32 func_0021cca0(u32 texture, s32 frame);
extern u32 func_0021cce0(u32 frame);
extern void* func_00239140(s32 index);
extern void func_0021d3b0(void* destination, u32 frame);
extern void func_0021d8e0(void* destination, const f32* rect);
extern void func_0021d950(void* destination, const u8* color);
extern void func_0021dd60(void* destination, const u8* color);
extern void func_0021e380(void* destination, u32 frame, s32 mode);
extern void func_0021eac0(void* destination, f32 value);
extern void func_00238980(void* glyphs, s32 capacity, s32 value, s32 style);
u32 bsaMain00215830(u32 type);
void bsaMain00215770(BsaWork* work);

extern u32 func_00306e80(u32 calc, s16 mode);
extern s16 func_003082f0(u32 calc, s16 id);
extern u16* func_00308bb0(u32 calc);
extern u32 func_0030bb40(u16 id);
extern u32 func_003b0970(u32 resource, s32 mode, s32 group, s32 a, s32 b);
extern void func_003b0d70(u32 resource, s32 x, s32 y);
extern void func_003b0e70(s32 mode);
extern void func_003b0e90(s32 mode);
extern void func_003b1360(u32 resource, s32 mode, s32 value);
extern void func_003b0170(u32 resource);
extern void frFontSetTextScale(u32 resource, f32 value);
extern void func_003b0e20(u32 resource, u32 value);
extern void func_004d7f60(s32 state, u32 value);

#define BSA_FLAG_ACTIVE      0x00000001u
#define BSA_FLAG_RESOURCE    0x00000002u
#define BSA_FLAG_STATUS      0x00000004u
#define BSA_FLAG_PERSONA     0x00000008u
#define BSA_FLAG_AILMENT     0x00000010u
#define BSA_FLAG_TOP_LABEL   0x00000020u
#define BSA_FLAG_TRANSITION  0x00000040u
#define BSA_FLAG_BOSS        0x00000080u

#define BSA_FRAME_W(frame) ((f32)((s32*)(frame))[3])
#define BSA_FRAME_H(frame) ((f32)((s32*)(frame))[4])

#define bsaAlpha(value) ((u8)(u32)(value))

#define bsaPlaceQuad(work, destination, frame, x, y, width, height, alphaSource) \
    do { \
        s32* quadDestination = (work) + (destination); \
        u8 quadColor[4]; \
        rect[0] = (x); \
        rect[1] = (y); \
        rect[2] = (width) < 0.0f ? BSA_FRAME_W(frame) : (width); \
        rect[3] = (height) < 0.0f ? BSA_FRAME_H(frame) : (height); \
        func_0021d8e0(quadDestination, rect); \
        quadColor[0] = 0xff; \
        quadColor[1] = 0xff; \
        quadColor[2] = 0xff; \
        quadColor[3] = (u32)(alphaSource); \
        func_0021d950(quadDestination, quadColor); \
    } while (0)
#define bsaSetColor(destination, alpha) \
    do { \
        drawColor[0] = 0xff; \
        drawColor[1] = 0xff; \
        drawColor[2] = 0xff; \
        drawColor[3] = (alpha); \
        func_0021d950((destination), drawColor); \
    } while (0)




static inline s32 bsaSkillCategory(u32 flags)
{
    if ((flags & 0x100) != 0)
        return 1;
    if ((flags & 0x200) != 0)
        return 4;
    if ((flags & 0x400) != 0)
        return 3;
    if ((flags & 0x800) != 0)
        return 0;
    if ((flags & 0x1000) != 0)
        return 2;
    return 5;
}

// FUN_0020FE20
void bsaMain0020fe20(BsaWork* work)
{
    work->words[1] = 0;
}

#undef p

 
static inline void bsaTransition(s32* p, f32* alpha, f32* slide, f32* iconAlpha)
{
    s32 timer;
    timer = ((s32*)p)[0x29ac];
    if ((p[1] & BSA_FLAG_TRANSITION) == 0)
        return;
    if (((s32*)p)[0x29ad] == 1) {
        if (timer < 10) ((s32*)p)[0x29ac] = ++timer;
        else {
            p[1] &= ~BSA_FLAG_TRANSITION;
            bsaMain00215770((BsaWork*)p);
            p[1] &= ~BSA_FLAG_ACTIVE;
        }
        *alpha = 1.0f - (f32)((s32*)p)[0x29ac] / 10.0f;
    } else {
        if (timer < 10) ((s32*)p)[0x29ac] = ++timer;
        else p[1] &= ~BSA_FLAG_TRANSITION;
        *alpha = (f32)((s32*)p)[0x29ac] / 10.0f;
    }
    if ((p[1] & BSA_FLAG_TRANSITION) == 0) {
        *alpha = ((s32*)p)[0x29ad] == 1 ? 0.0f : 1.0f;
        return;
    }
    if (((s32*)p)[0x29ad] == 1) {
        *iconAlpha = 1.0f - (f32)((s32*)p)[0x29ac] / 10.0f;
    } else if (timer < 4) {
        *iconAlpha = 0.0f;
    } else if (timer < 8) {
        *iconAlpha = (f32)(timer - 4) / 4.0f;
        *slide = (1.0f - *iconAlpha) * -20.0f;
    }
}


#undef D_00960090_abs
#undef D_0096009C_abs
