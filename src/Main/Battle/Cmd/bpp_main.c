#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Panel/bpp_panel.h"
#include "Main/Battle/Cmd/bpp_main.h"
static u32* sBppMain; // DAT_007ce2f4
void bppMain0020f680(void);

extern void* btlOrderGetActionPlaying(void);
extern u32 func_0029b0c0(void* action);
extern s32 bpMisc001ff5b0(void);
extern s16 func_001ff630(s32 index);
extern void* func_001ff430(u32 id);
extern u16 datGetHp(s16 pcId);
extern u16 datGetMaxHp(s16 pcId);
extern u16 datGetBadStatusNoDown(s16 pcId);
extern u16 datGetSp(s16 pcId);
extern u16 func_0016c670(s16 pcId);
extern u16 datGetPhysicalCondition(s16 pcId);
extern void func_0022c720(void* panel, s16 pcId);
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

// FUN_0020edf0 NONMATCHING
void bppMain0020edf0(void)
{
    u32* work;
    void* action;
    void* unit;
    u8* entry;
    u32 value;
    s16 pcId;
    s32 i;

    K_ASSERT(sBppMain != NULL, 0x43);
    work = sBppMain;
    if ((*work & 0x80) == 0) {
        return;
    }

    if ((*work & 0x30) == 0 && (*work & 0x40) == 0) {
        if ((s32)work[0x1697] < (s32)work[0x1698]) {
            work[0x1697]++;
        }
    } else if ((s32)work[0x1697] > 0) {
        work[0x1697]--;
    }

    if ((*work & 2) != 0) {
        action = btlOrderGetActionPlaying();
        unit = action != NULL ? *(void**)((u8*)action + 0x30) : NULL;
        if (action == NULL || (*work & 1) == 0 ||
            (unit != NULL && *(u32*)((u8*)unit + 0xa8) != work[0x1695]) ||
            func_0029b0c0(action) != 0) {
            if (action == NULL || (*work & 1) == 0 ||
                (unit != NULL && *(u32*)((u8*)unit + 0xa8) == work[0x1695])) {
                if (action != NULL && (*work & 1) == 0 &&
                    func_0029b0c0(action) != 0) {
                    bppMainSetDetailForUnit(work, unit);
                }
                if (unit != NULL) {
                    work[0x1695] = *(u32*)((u8*)unit + 0xa8);
                    *work |= 1;
                }
            } else {
                if ((*work & 4) != 0) {
                    bppMainClearDetailForUnit(work,
                                              func_001ff430(work[0x1695]));
                }
                *work &= ~1u;
                if (func_0029b0c0(action) != 0) {
                    bppMainSetDetailForUnit(work, unit);
                    if (unit != NULL) {
                        work[0x1695] = *(u32*)((u8*)unit + 0xa8);
                        *work |= 1;
                    }
                }
            }
        } else {
            unit = func_001ff430(work[0x1695]);
            if (unit != NULL && *(u8*)((u8*)unit + 0xa2) == 0) {
                K_ASSERT((*work & 4) != 0, 0x93);
                bppMainClearDetailForUnit(work, unit);
            }
            *work &= ~4u;
            *work &= ~1u;
        }
    }

    for (i = 0; i < (s32)work[0x1694]; i++) {
        entry = bppMainEntry(i);
        pcId = *(s16*)(entry + 0x14);
        value = datGetHp(pcId);
        if (*(u32*)(entry + 0x20) != (value & 0xffff)) {
            *(u32*)(entry + 0x20) = value & 0xffff;
            func_0022e900(entry + 0x30, value);
        }
        value = datGetSp(pcId);
        if (*(u32*)(entry + 0x24) != (value & 0xffff)) {
            *(u32*)(entry + 0x24) = value & 0xffff;
            func_0022e9a0(entry + 0x30, value);
        }
        value = datGetBadStatusNoDown(pcId);
        if (*(u32*)(entry + 0x28) != (value & 0xfffff)) {
            *(u32*)(entry + 0x28) = value & 0xfffff;
            func_0022f1c0(entry + 0x30, value);
        }
        value = datGetPhysicalCondition(pcId);
        if (*(u32*)(entry + 0x2c) != (value & 0xffff)) {
            *(u32*)(entry + 0x2c) = value & 0xffff;
            func_0022e780(entry + 0x30);
        }
    }
}

// FUN_0020f260 NONMATCHING
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
    if ((*work & 0x80) == 0) {
        return;
    }
    for (i = 0; i < (s32)work[0x1694]; i++) {
        reverse = (s32)work[0x1694] - 1 - i;
        transition = work[0x1697];
        if ((s32)transition < reverse * 2) {
            alpha = 0.0f;
        } else if ((s32)transition < reverse * 2 + 6) {
            alpha = (f32)((s32)transition - reverse * 2) / 6.0f;
        } else {
            alpha = 1.0f;
        }
        entry = bppMainEntry(i);
        bppPanelSetPrimaryAnimation(alpha, (BppPanelWork*)(entry + 0x30));
        bppPanelSetSecondaryAnimation(1.0f, (BppPanelWork*)(entry + 0x30));
        func_0022c8a0(entry + 0x30);
        func_0022df10(entry + 0x30);
    }
}

// FUN_0020f3b0 NONMATCHING
void bppMain0020f3b0(void)
{
    u32* work;
    u32 count;
    u32 oldDuration;
    u32 newDuration;
    u8* entry;
    s16 pcId;
    s32 i;

    K_ASSERT(sBppMain != NULL, 0x43);
    work = sBppMain;
    count = (u32)bpMisc001ff5b0();
    for (i = 0; i < (s32)count; i++) {
        entry = bppMainEntry(i);
        *(u32*)(entry + 0x10) = 0;
        pcId = func_001ff630(i);
        *(s16*)(entry + 0x14) = pcId;
        *(u32*)(entry + 0x20) = 0xffffffff;
        *(u32*)(entry + 0x24) = 0xffffffff;
        *(u32*)(entry + 0x28) = 0xffffffff;
        *(u32*)(entry + 0x2c) = 0xffffffff;
    }
    oldDuration = work[0x1698];
    newDuration = (count - 1) * 2 + 6;
    work[0x1698] = newDuration;
    if (oldDuration == 0) {
        work[0x1697] = 0;
    } else {
        work[0x1697] = (work[0x1697] * newDuration) / oldDuration;
    }
    work[0x1694] = count;
    for (i = 0; i < (s32)count; i++) {
        entry = bppMainEntry(i);
        pcId = *(s16*)(entry + 0x14);
        func_0022c720(entry + 0x30, pcId);
        *(u32*)(entry + 0x540) = 0x43ee0000;
        *(u32*)(entry + 0x544) = (u32)i * 100 + 4;
        *(u32*)(entry + 0x868) = datGetMaxHp(pcId) & 0xffff;
        *(u32*)(entry + 0x870) = func_0016c670(pcId) & 0xffff;
    }
    *work |= 2;
}

// FUN_0020f570 NONMATCHING
void bppMain0020f570(void)
{
    u32* work;
    s16 selected;
    s32 count;
    s32 i;

    K_ASSERT(sBppMain != NULL, 0x43);
    work = sBppMain;
    bppMain0020f680();
    bppMain0020f3b0();
    if ((*work & 4) != 0) {
        count = bpMisc001ff5b0();
        for (i = 0; i < count; i++) {
            if ((s16)work[0x1696] == func_001ff630(i)) {
                break;
            }
        }
        if (i == count) {
            *work &= ~4u;
            *work &= ~2u;
        } else {
            selected = (s16)work[0x1696];
            bppPanelShow((BppPanelWork*)(bppMainFindEntry(selected) + 0x20));
        }
    }
}

// FUN_0020f680 NONMATCHING
void bppMain0020f680(void)
{
    u32* work;
    s32 i;

    K_ASSERT(sBppMain != NULL, 0x43);
    work = sBppMain;
    for (i = 0; i < (s32)work[0x1694]; i++) {
        func_0022c850(bppMainEntry(i) + 0x30);
    }
    work[0x1694] = 0;
    *work &= ~2u;
}

// FUN_0020f720 NONMATCHING
u8* bppMain0020f720(s16 pcId)
{
    return bppMainFindEntry(pcId);
}

// FUN_0020f7d0 NONMATCHING
void bppMain0020f7d0(s16 pcId)
{
    u8* entry;

    entry = bppMainFindEntry(pcId);
    *(u32*)entry |= 1;
    bppPanelRequestStatusRefresh((BppPanelWork*)(entry + 0x20));
}

// FUN_0020f8b0 NONMATCHING
void bppMain0020f8b0(s16 pcId)
{
    u8* entry;

    entry = bppMainFindEntry(pcId);
    *(u32*)entry &= ~1u;
    bppPanelCancelStatusRefresh((BppPanelWork*)(entry + 0x20));
}

// FUN_0020f9a0 NONMATCHING
void bppMain0020f9a0(s16 pcId)
{
    bppPanelRequestHide((BppPanelWork*)(bppMain0020f720(pcId) + 0x20));
}

// FUN_0020fa80 NONMATCHING
void bppMain0020fa80(s16 pcId)
{
    bppPanelEnableActionOverlay((BppPanelWork*)(bppMain0020f720(pcId) + 0x20));
}

// FUN_0020fb60 NONMATCHING
void bppMain0020fb60(s16 pcId)
{
    bppPanelDisableActionOverlay((BppPanelWork*)(bppMain0020f720(pcId) + 0x20));
}


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
