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

// FUN_0020ed50
void bppMain0020ed50(u32* work)
{
    work[0] = 0;
    work[0x1694] = 0;
    work[0x1697] = 0;
    work[0x1698] = 0;
    sBppMain = work;
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
// FUN_0020edf0 NONMATCHING
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
        transition = (s32)work[0x1697];
        if (transition > 0) {
            work[0x1697] = transition - 1;
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
