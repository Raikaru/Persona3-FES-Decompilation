#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBcmPanel; // puGpffffb618
u32 FUN_0021c3f0();
u32 FUN_0021cca0();
void FUN_0021d3b0();
u32 FUN_0021cce0();
extern u32 D_00960090[];
extern u32 D_0096009C[];
extern void RpSkyRenderStateSet(u32, void*);
extern void* FUN_00198590(void);
void FUN_00226320();
void FUN_00222d60();
void FUN_0021e380();
void FUN_0022c210();
void FUN_00222b90();
void FUN_002230e0();
u32 FUN_0021c450();
u32 FUN_0021cd00();
void FUN_0021d890();
void FUN_0021d950(void* destination, const u8* color);
void FUN_0021d8e0(void* destination, const f32* rect);
void FUN_0022c210();
void FUN_00224860();
void FUN_00225670();
void FUN_00227d10();
void FUN_00238980();
void bpIFont00238bf0(void* glyphs, s32 capacity, const char* text, s32 font, const float* origin);
void FUN_00238dc0(void* destination, s32 count, u32 value, s32 mode, const f32* layout);
void FUN_0022e780(u32*, u32);
void FUN_0022e900(u32*, s32);
void FUN_0022e9a0(u32*, s32);
void FUN_0022ea40(u32*, u32);
void FUN_0022ecb0(u8*, u8*, f32);
extern void FUN_003b1360();
extern u32 FUN_00239140(s32);
extern void FUN_003b0d70(u32 resource, s32 x, s32 y);
extern void FUN_003b0e20(u32 resource, u32 color);
extern u32 RpRandom(void);
extern void bppPanelDrawParameterLayout(void* work);
u32 FUN_0022e850(u32);
void FUN_0022f1c0(u32*, u64);
void FUN_0022f3b0(u32*);
void FUN_0022fa80(u32*);
void FUN_0022C210();
static u8* bcm_panel_record(u32 index);

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
/*
 * The command panel stores all of its render records in one work area.  The
 * retail code uses the records as packed byte arrays; keeping the addressing
 * in these small helpers makes the state-machine routines below considerably
 * easier to audit than a collection of magic pointer casts.
 */
static u8* bcm_panel_bytes(void)
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

static void bcm_panel_set_resource(u8* dst, u32 resource, u32 id)
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

static void bcm_panel_update_overlays(void)
{
    u32 i;
    u32 count = bcm_panel_read(0x6070);
    for (i = 0; i < count; ++i) {
        u8* overlay = bcm_panel_overlay(i);
        if (*(u32*)overlay != 0) {
            bcm_panel_set_resource(overlay + 0x10, 0, 0x29);
        }
    }
}

// FUN_002230e0 NONMATCHING
void FUN_002230e0(void)
{
    u8* work;
    u8* records;
    u8* record;
    u32 table0;
    s32 i;
    s32 j;

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

// FUN_00223290 NONMATCHING
void FUN_00223290(void)
{
    u32 i;
    u32 count;
    u32 alpha;
    u32 state;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    count = bcm_panel_read(0x6070);
    state = bcm_panel_read(0x463c);
    alpha = bcm_panel_read(0x4658);
    if (state == 0) {
        alpha = (3u - (bcm_panel_read(0x4650) & 3u)) * 0x55u;
    } else if (state == 3) {
        alpha = (bcm_panel_read(0x4658) < 6u)
                    ? bcm_panel_read(0x4658) * 0x2au
                    : bcm_panel_read(0x4650);
    } else {
        alpha = bcm_panel_read(0x4650);
    }
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        u32 kind = *(u32*)record;
        bcm_panel_layout_record(record, i, alpha);
        if (kind == 1) {
            bcm_panel_layout_record(record + 0x100, i, alpha);
            bcm_panel_layout_record(record + 0x200, i, alpha);
            bcm_panel_layout_record(record + 0x300, i, alpha);
        }
        *(u32*)record |= 4;
    }
    if (bcm_panel_read(0) & 4) {
        bcm_panel_set_resource(bcm_panel_bytes() + 0x18f0, 0, 0x2f);
    }
}

// FUN_00224150 NONMATCHING
void FUN_00224150(void)
{
    u32 i;
    u32 count;
    u32 table;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    table = FUN_0021c3f0(0);
    count = bcm_panel_read(0x6070);
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        u32 state = *(u32*)record;
        if (state == 0 || state == 2) {
            FUN_0021d3b0(record + 0x10, FUN_0021cca0(table, 0x2f));
        } else {
            FUN_0021d3b0(record + 0x10, FUN_0021cca0(table, 0x29));
            FUN_0021d3b0(record + 0x110, FUN_0021cca0(table, 0x2a));
        }
        *(u32*)(record + 0x560) = 1;
        *(u32*)(record + 0x564) = 1;
    }
}

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

    if (*(u32*)(work + 0x463c) == 0) {
        alphaF = (f32)(3 - *(s32*)(work + 0x4650)) / 3.0f;
    } else if (*(u32*)(work + 0x463c) == 4) {
        alphaF = (f32)*(s32*)(work + 0x4650) / 3.0f;
    } else {
        K_ASSERT(0, 0x8b3);
    }
    alphaByte = (u8)(u32)(255.0f * alphaF * weight);

    basePos = (f32*)(work + 0x6050);

    frame = (void*)FUN_0021cca0(table0, 0x24);
    rect[0] = 188.0f + basePos[0];
    rect[1] = 19.0f + basePos[1] +
              (f32)(*(s32*)(work + 0x6068) - *(s32*)(work + 0x606c)) * 26.0f;
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(work + 0x4230, rect);

    frame = (void*)FUN_0021cca0(table0, 0x24);
    rect[0] = 188.0f + basePos[0] + (f32)*(s32*)((u8*)frame + 0xc);
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

// FUN_00225040 NONMATCHING
void FUN_00225040(void)
{
    u32 i;
    u32 count;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    count = bcm_panel_read(0x6070);
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        if (*(u32*)record != 1) {
            *(u32*)(record + 0x10) = 0;
            continue;
        }
        bcm_panel_set_resource(record + 0x10, 0, 0x44);
        bcm_panel_set_resource(record + 0x110, 0, 0x44);
        bcm_panel_set_resource(record + 0x210, 0, 0x44);
        bcm_panel_set_resource(record + 0x310, 0, 0x44);
    }
}

// FUN_002254A0 NONMATCHING
void FUN_002254A0(void)
{
    u32 current;
    u8* base;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = bcm_panel_bytes();
    current = bcm_panel_read(0x6068) - bcm_panel_read(0x606c);
    bcm_panel_write(0x18c0, current);
    bcm_panel_write(0x18e0, *(u32*)(base + 0x4660 + current * 0x420 + 0xc));
    bcm_panel_write(0x4630, 4);
    bcm_panel_write(0x4658, 0);
    bcm_panel_write(0, bcm_panel_read(0) | 8);
    bcm_panel_write(0x4644, 1);
    FUN_00227d10();
    bcm_panel_set_resource(base + 0x4430, 0, 0x25);
    FUN_0021e380(base + 0x4530,
                 FUN_0021cca0(FUN_0021c3f0(0), 0x25), 1);
    bcm_panel_set_resource(base + 0x18f0, 0, 0x2f);
    FUN_00225670();
}

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

// FUN_00225670 NONMATCHING
void FUN_00225670(void)
{
    u32 i;
    u32 count;
    u32 progress;
    u8* overlay;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    count = bcm_panel_read(0x55c);
    progress = bcm_panel_read(0x550);
    for (i = 0; i < count; ++i) {
        overlay = bcm_panel_overlay(i);
        bcm_panel_set_resource(overlay + 0x10, 0, 0x29);
    }
    overlay = bcm_panel_bytes() + 0x3730;
    if (count < progress) {
        u32 delta = progress - count;
        u32 fade = bcm_panel_read(0x558);
        fade = 0x41000000u + (fade * 0x425c0000u) / (delta ? delta : 1);
        *(u32*)(overlay + 0x0) = 0x42700000u;
        *(u32*)(overlay + 0x4) = fade;
    } else {
        *(u32*)(overlay + 0x0) = 0x42700000u;
        *(u32*)(overlay + 0x4) = 0x42100000u;
    }
    *(u32*)(overlay + 0x8) = 0;
    *(u32*)(overlay + 0xc) = 0;
    FUN_0021d8e0(overlay, (const f32*)overlay);
}

// FUN_002257F0 NONMATCHING
void FUN_002257F0(void)
{
    u32 i;
    u32 j;
    u32 count;
    u32 alpha;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    count = bcm_panel_read(0x6070);
    alpha = bcm_panel_read(0x4658) & 0xff;
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        u32 state = *(u32*)record;
        if (state == 0 || state == 2) {
            bcm_panel_set_resource(record + 0x10, 0, 0x2f);
        } else if (state == 1) {
            for (j = 0; j < 4; ++j) {
                bcm_panel_set_resource(record + 0x10 + j * 0x100,
                                       0, (j < 2) ? 0x29 : 0x2a);
            }
        }
        bcm_panel_layout_record(record, i, alpha);
        *(u32*)record |= 4;
    }
    bcm_panel_update_overlays();
}

// FUN_00226040 NONMATCHING
void FUN_00226040(void)
{
    u32 i;
    u32 count;
    u32 table;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    table = FUN_0021c3f0(0);
    count = bcm_panel_read(0x6070);
    bcm_panel_write(0, bcm_panel_read(0) | 2);
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        if (*(u32*)record == 0) {
            FUN_0021d3b0(record + 0x10, FUN_0021cca0(table, 0x2f));
        } else {
            FUN_0021d3b0(record + 0x10, FUN_0021cca0(table, 0x29));
        }
        *(u32*)(record + 0x550) = i;
        *(u32*)(record + 0x55c) = 1;
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
    u32 i;
    u32 count;
    u32 state;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    state = bcm_panel_read(0x463c);
    count = bcm_panel_read(0x6070);
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        u32 kind = *(u32*)record;
        bcm_panel_set_colour(record, (state == 4) ? 0xffu : 0x80u);
        if (kind == 1) {
            bcm_panel_set_colour(record + 0x100, 0xffu);
            bcm_panel_set_colour(record + 0x200, 0xffu);
            bcm_panel_set_colour(record + 0x300, 0xffu);
        }
        *(u32*)record |= 4;
    }
    bcm_panel_set_resource(bcm_panel_bytes() + 0x18f0, 0, 0x2f);
}

// FUN_00227800 NONMATCHING
void FUN_00227800(void)
{
    u32 i;
    u32 count;
    u8* base;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = bcm_panel_bytes();
    count = bcm_panel_read(0x6070);
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        if (*(u32*)record == 1) {
            bcm_panel_set_resource(record + 0x10, 0, 0x29);
        } else {
            bcm_panel_set_resource(record + 0x10, 0, 0x2f);
        }
        *(u32*)(record + 0x40) = i;
    }
    *(u32*)(base + 0x7210) = count;
}

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
    u32 i;
    u32 count;
    u32 alpha;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    count = bcm_panel_read(0x6070);
    alpha = bcm_panel_read(0x4650) & 0xff;
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        bcm_panel_layout_record(record, i, alpha);
        if (*(u32*)record == 1) {
            bcm_panel_layout_record(record + 0x100, i, alpha);
            bcm_panel_layout_record(record + 0x200, i, alpha);
            bcm_panel_layout_record(record + 0x300, i, alpha);
        }
    }
}

// FUN_002289B0 NONMATCHING
void FUN_002289B0(void)
{
    u32 i;
    u32 count;
    u8* base;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = bcm_panel_bytes();
    count = bcm_panel_read(0x6070);
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        bcm_panel_set_resource(record + 0x10, 0, 0x44);
        *(u32*)(record + 0x50) = i;
    }
    FUN_0021d3b0(base + 0x4230,
                 FUN_0021cca0(FUN_0021c3f0(0), 0x24));
}

// FUN_00228E40 NONMATCHING
void FUN_00228E40(void)
{
    u32 i;
    u32 j;
    u32 count;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    count = bcm_panel_read(0x6070);
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        for (j = 0; j < 4; ++j) {
            u8* quad = record + j * 0x100;
            bcm_panel_set_colour(quad, 0xffffffffu);
            if (j < 2) {
                bcm_panel_set_resource(quad + 0x10, 0, 0x29);
            }
        }
        *(u32*)record |= 4;
    }
}

// FUN_00229B40 NONMATCHING
void FUN_00229B40(void)
{
    u32 i;
    u32 count;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    count = bcm_panel_read(0x6070);
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        if (*(u32*)record == 1) {
            FUN_0021d3b0(record + 0x10,
                         FUN_0021cca0(FUN_0021c3f0(0), 0x29));
        }
        *(u32*)(record + 0x20) = bcm_panel_read(0x4644);
    }
    bcm_panel_write(0x4644, 0);
}

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
    f32 weight;
    f32 alpha1;
    f32 alpha2;
    f32 blend;
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

    if (*(u32*)(work + 0x463c) == 0) {
        alpha1 = (f32)(3 - *(s32*)(work + 0x4650)) / 3.0f;
    } else if (*(u32*)(work + 0x463c) == 1) {
        alpha1 = (f32)*(s32*)(work + 0x4650) / 3.0f;
    } else {
        K_ASSERT(0, 0xfb4);
    }

    if (*(u32*)(work + 0x4644) == 4) {
        alpha2 = 0.0f;
    } else if (*(u32*)(work + 0x4644) == 0) {
        alpha2 = 1.0f;
    }
    scaled = alpha1 * alpha2;
    blend = 1.0f - scaled;

    frame = (void*)FUN_0021cca0(table0, 0x23);
    rect[0] = 188.0f + basePos[0];
    rect[1] = 19.0f + basePos[1] +
              (f32)(*(s32*)(work + 0x6068) - *(s32*)(work + 0x606c)) * 26.0f;
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(work + 0x4230, rect);

    frame = (void*)FUN_0021cca0(table0, 0x23);
    rect[0] = 188.0f + basePos[0] + (f32)*(s32*)((u8*)frame + 0xc);
    rect[1] = 19.0f + basePos[1] +
              (f32)(*(s32*)(work + 0x6068) - *(s32*)(work + 0x606c)) * 26.0f;
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

    whiteColour = alphaByte | 0xffffff00u;
    greyColour = alphaByte | 0xccccccu | 0xcc000000u;

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
    color[3] = alphaByte;
    FUN_0021d950(overlay + 0x10, color);

    rect[0] = 315.0f + basePos[0];
    rect[1] = 158.0f + basePos[1];
    bpIFont00238bf0(overlay + 0x110, 2, (const char*)(size_t)*(u32*)(overlay + 4), 1, rect);

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
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
    color[3] = alphaByte;
    FUN_0021d950(overlay + 0x310, color);
}

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
    void (*pRender)(u32, u32);
    void (*pQuad)(u32*, u32, u32, u32, u32);

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    table6 = FUN_0021c3f0(6);
    records = work + 0x4660;

    texture = FUN_0021cce0(FUN_0021cca0(table0, 0x23));
    pRender = (void (*)(u32, u32))D_00960090;
    pRender(1, texture);
    pQuad = (void (*)(u32*, u32, u32, u32, u32))D_0096009C;
    pQuad((u32*)(work + 0x4230), 4, 0, 1, 2);
    pQuad((u32*)(work + 0x4230), 4, 0, 2, 3);
    pQuad((u32*)(work + 0x4330), 4, 0, 1, 2);
    pQuad((u32*)(work + 0x4330), 4, 0, 2, 3);

    for (i = 0; i < *(s32*)(work + 0x6070); ++i) {
        record = records + i * 0x410;

        FUN_003b1360(*(u32*)record, 1, 0);

        texture = FUN_0021cce0(FUN_0021cca0(table0, 0x28));
        pRender = (void (*)(u32, u32))D_00960090;
        pRender(1, texture);
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        pQuad = (void (*)(u32*, u32, u32, u32, u32))D_0096009C;
        pQuad((u32*)(record + 0x10), 4, 0, 1, 2);
        pQuad((u32*)(record + 0x10), 4, 0, 2, 3);

        texture = FUN_00239140(1);
        pRender(1, texture);
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        pQuad((u32*)(record + 0x110), 4, 0, 1, 2);
        pQuad((u32*)(record + 0x110), 4, 0, 2, 3);
        pQuad((u32*)(record + 0x210), 4, 0, 1, 2);
        pQuad((u32*)(record + 0x210), 4, 0, 2, 3);
        pQuad((u32*)(record + 0x310), 4, 0, 1, 2);
        pQuad((u32*)(record + 0x310), 4, 0, 2, 3);

        texture = FUN_0021cce0(FUN_0021cca0(table6, 0x1a));
        pRender(1, texture);
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        pQuad((u32*)(record + 0x310), 4, 0, 1, 2);
        pQuad((u32*)(record + 0x310), 4, 0, 2, 3);
    }

    if (*(u32*)(work + 0x4644) != 4) {
        return;
    }

    overlay = work + 0x6d00;

    FUN_003b1360(*(u32*)overlay, 1, 0);

    texture = FUN_0021cce0(FUN_0021cca0(table0, 0x28));
    pRender = (void (*)(u32, u32))D_00960090;
    pRender(1, texture);
    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    pQuad = (void (*)(u32*, u32, u32, u32, u32))D_0096009C;
    pQuad((u32*)(overlay + 0x10), 4, 0, 1, 2);
    pQuad((u32*)(overlay + 0x10), 4, 0, 2, 3);

    texture = FUN_00239140(1);
    pRender(1, texture);
    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    pQuad((u32*)(overlay + 0x110), 4, 0, 1, 2);
    pQuad((u32*)(overlay + 0x110), 4, 0, 2, 3);
    pQuad((u32*)(overlay + 0x210), 4, 0, 1, 2);
    pQuad((u32*)(overlay + 0x210), 4, 0, 2, 3);
    pQuad((u32*)(overlay + 0x310), 4, 0, 1, 2);
    pQuad((u32*)(overlay + 0x310), 4, 0, 2, 3);

    texture = FUN_0021cce0(FUN_0021cca0(table6, 0x1a));
    pRender(1, texture);
    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    pQuad((u32*)(overlay + 0x310), 4, 0, 1, 2);
    pQuad((u32*)(overlay + 0x310), 4, 0, 2, 3);
}

// FUN_0022B630 NONMATCHING
void FUN_0022B630(void)
{
    u32 i;
    u32 count;
    u8* base;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = bcm_panel_bytes();
    count = bcm_panel_read(0x6070);
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        bcm_panel_set_resource(record + 0x10, 0, 0x42);
        *(u32*)(record + 0x90) = i;
        *(u32*)(record + 0x94) = 0;
        *(u32*)(record + 0x98) = 0;
        *(u32*)(record + 0x9c) = 0;
    }
    bcm_panel_write(0x463c, 3);
}
// FUN_0022BCF0 NONMATCHING
void FUN_0022BCF0(void)
{
    u32 i;
    u32 count;
    u8* base;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = bcm_panel_bytes();
    count = bcm_panel_read(0x6070);
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        bcm_panel_set_colour(record, 0xffffffffu);
        *(u32*)(record + 0x68f0) = i;
    }
    *(u32*)(base + 0x463c) = 3;
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

// FUN_0022C2D0 NONMATCHING
void FUN_0022C2D0(void)
{
    u8* base;
    u32 table;
    u32 alpha;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = bcm_panel_bytes();
    table = FUN_0021c3f0(0);
    alpha = bcm_panel_read(0x4650) & 0xff;
    bcm_panel_set_resource(base + 0x6a00, 0, 0x42);
    bcm_panel_set_colour(base + 0x6a00, alpha | 0xffffff00u);
    bcm_panel_set_resource(base + 0x6b00, 0, 0x42);
    bcm_panel_set_colour(base + 0x6b00, alpha | 0xffffff00u);
    bcm_panel_set_resource(base + 0x6c00, 0, 0x43);
    bcm_panel_set_colour(base + 0x6c00, alpha | 0xffffff00u);
    (void)table;
}

// FUN_0022C5A0 NONMATCHING
void FUN_0022C5A0(void)
{
    u8* base;
    u32 resource;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = (u8*)sBcmPanel;
    resource = FUN_0021cca0(FUN_0021c3f0(0), 0x42);
    ((void (*)(u32, u32))D_00960090)(1, FUN_0021cce0(resource));
    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)(base + 0x6a00), 4, 0, 1, 2);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)(base + 0x6a00), 4, 0, 2, 3);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)(base + 0x6b00), 4, 0, 1, 2);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)(base + 0x6b00), 4, 0, 2, 3);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)(base + 0x6c00), 4, 0, 1, 2);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)(base + 0x6c00), 4, 0, 2, 3);
}

// FUN_0022C720
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

// FUN_0022C850
void FUN_0022c850(u32* object)
{
    K_ASSERT((object[0] & 1) != 0, 0x1b3);
    object[0] = 0;
}

// FUN_0022C8A0 NONMATCHING
void FUN_0022c8a0(u32* object)
{
    u8* bytes;
    u32 table;
    u32 i;
    u32 count;

    if (object == NULL) {
        return;
    }
    bytes = (u8*)object;
    table = FUN_0021c3f0(3);
    object[0] |= 1;
    count = *(u32*)(bytes + 0x55c);
    if (count > 6) {
        count = 6;
    }
    for (i = 0; i < count; ++i) {
        u8* slot = bytes + 0x510 + i * 0x10;
        *(u32*)slot = i;
        *(u32*)(slot + 4) = *(u32*)(bytes + 0x528);
        FUN_0021d3b0(slot + 0x10, FUN_0021cca0(table, 0x29));
    }
    *(u32*)(bytes + 0x830) = 0;
    *(u32*)(bytes + 0x834) = 0;
}

// FUN_0022DF10 NONMATCHING
void FUN_0022df10(u32* object)
{
    u32 table3;
    u32 table5;
    u32 text;
    u32 resource;

    K_ASSERT((object[0] & 1) != 0, 0x390);
    table3 = FUN_0021c3f0(3);
    table5 = FUN_0021c3f0(5);
    text = FUN_0021c450(*(u16*)((u8*)object + 4));
    ((void (*)(u32, u32))D_00960090)(0x14, 2);
    ((void (*)(u32, u32))D_00960090)(8, 0);
    ((void (*)(u32, u32))D_00960090)(6, 0);
    ((void (*)(u32, u32))D_00960090)(1, FUN_0021cce0(FUN_0021cca0(text, 1)));

    if ((object[0] & 0x20) != 0) {
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
            ((u32*)((u8*)object + 0x310), 4, 0, 1, 2);
        ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
            ((u32*)((u8*)object + 0x310), 4, 0, 2, 3);

        if (!((object[0] & 4) != 0 && object[0x20c] == 8)) {
            RpSkyRenderStateSet(3, (void*)0x717fb);
            RpSkyRenderStateSet(2, (void*)0x44);
            ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
                ((u32*)((u8*)object + 0x410), 4, 0, 1, 2);
            ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
                ((u32*)((u8*)object + 0x410), 4, 0, 2, 3);
        }
    }
    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0x110), 4, 0, 1, 2);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0x110), 4, 0, 2, 3);

    if ((object[0] & 0x20) == 0) {
        goto check210_flag8;
    }
    if ((object[0] & 4) == 0) {
        goto draw210;
    }
    if (object[0x20c] != 8) {
        goto draw210;
    }
check210_flag8:
    if ((object[0] & 8) != 0) {
        goto draw210;
    }
    if ((object[0] & 0x100) == 0) {
        goto skip210;
    }
draw210:
    RpSkyRenderStateSet(3, (void*)0x71801);
    RpSkyRenderStateSet(2, (void*)0x48);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0x210), 4, 0, 1, 2);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0x210), 4, 0, 2, 3);
skip210:

    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    ((void (*)(u32, u32))D_00960090)(1, FUN_0021cce0(FUN_0021cca0(text, 0)));
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0x10), 4, 0, 1, 2);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0x10), 4, 0, 2, 3);

    resource = FUN_0021cca0(table3, 0xa);
    ((void (*)(u32, u32))D_00960090)(1, FUN_0021cce0(resource));
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0x630), 4, 0, 1, 2);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0x630), 4, 0, 2, 3);

    if ((object[0] & 0x20) == 0) {
        goto check730_flag8;
    }
    if ((object[0] & 4) == 0) {
        goto draw730;
    }
    if (object[0x20c] != 8) {
        goto draw730;
    }
check730_flag8:
    if ((object[0] & 8) != 0) {
        goto draw730;
    }
    if ((object[0] & 0x100) == 0) {
        goto skip730;
    }
draw730:
    RpSkyRenderStateSet(3, (void*)0x71801);
    RpSkyRenderStateSet(2, (void*)0x48);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0x730), 4, 0, 1, 2);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0x730), 4, 0, 2, 3);
skip730:

    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    resource = FUN_0021cca0(table3, 0);
    ((void (*)(u32, u32))D_00960090)(1, FUN_0021cce0(resource));
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0x860), 4, 0, 1, 2);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0x860), 4, 0, 2, 3);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0x960), 4, 0, 1, 2);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0x960), 4, 0, 2, 3);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0xa60), 4, 0, 1, 2);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0xa60), 4, 0, 2, 3);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0xb60), 4, 0, 1, 2);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0xb60), 4, 0, 2, 3);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0xc60), 4, 0, 1, 2);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0xc60), 4, 0, 2, 3);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0xd60), 4, 0, 1, 2);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0xd60), 4, 0, 2, 3);

    resource = FUN_0021cca0(table5, 2);
    ((void (*)(u32, u32))D_00960090)(1, FUN_0021cce0(resource));
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0xe60), 4, 0, 1, 2);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0xe60), 4, 0, 2, 3);

    resource = FUN_0021cca0(table5, 3);
    ((void (*)(u32, u32))D_00960090)(1, FUN_0021cce0(resource));
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0xf60), 4, 0, 1, 2);
    ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
        ((u32*)((u8*)object + 0xf60), 4, 0, 2, 3);

    if ((object[0] & 2) != 0) {
        resource = FUN_0021cca0(table3, FUN_0022e850(object[0x14a]));
        ((void (*)(u32, u32))D_00960090)(1, FUN_0021cce0(resource));
        ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
            ((u32*)((u8*)object + 0x530), 4, 0, 1, 2);
        ((void (*)(u32*, u32, u32, u32, u32))D_0096009C)
            ((u32*)((u8*)object + 0x530), 4, 0, 2, 3);
    }
    if ((object[0] & 4) != 0) {
        bppPanelDrawParameterLayout((void*)object);
    }
}

// FUN_0022E780
void FUN_0022e780(u32* object, u32 command)
{
    u32* panel;
    u32 table;
    u32 mapped;
    u32 style;

    panel = object;
    style = command;
    panel[0x14a] = style;
    table = FUN_0021c3f0(3);
    switch (style) {
    case 0:
        panel[0] &= ~2u;
        break;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        mapped = FUN_0022e850(panel[0x14a]);
        FUN_0021d3b0(panel + 0x14c,
                     FUN_0021cca0(table, mapped));
        panel[0] |= 2;
        break;
    }
}

// FUN_0022E850
u32 FUN_0022e850(u32 command)
{
    switch (command) {
    case 1:
        return 0xd;
    case 2:
        return 0xc;
    case 3:
        return 0xe;
    case 4:
        return 0xf;
    case 5:
        return 0x10;
    default:
        K_ASSERT(0, 0x42d);
        return 0;
    }
}

// FUN_0022E900
void FUN_0022e900(u32* object, s32 value)
{
    u8* resource;
    f32 denominator;
    f32 scale;

    resource = (u8*)FUN_0021cca0(FUN_0021c3f0(5), 2);
    *(u32*)((u8*)object + 0x834) = value;
    FUN_0022ea40((u32*)((u8*)object + 0x860), value);
    denominator = (f32)*(s32*)((u8*)object + 0x838);
    scale = (f32)value / denominator;
    FUN_0022ecb0((u8*)object + 0xe60, resource, scale);
}

// FUN_0022E9A0
void FUN_0022e9a0(u32* object, s32 value)
{
    u8* resource;
    f32 denominator;
    f32 scale;

    resource = (u8*)FUN_0021cca0(FUN_0021c3f0(5), 3);
    *(u32*)((u8*)object + 0x83c) = value;
    FUN_0022ea40((u32*)((u8*)object + 0xb60), value);
    denominator = (f32)*(s32*)((u8*)object + 0x840);
    scale = (f32)value / denominator;
    FUN_0022ecb0((u8*)object + 0xf60, resource, scale);
}

// FUN_0022EA40 NONMATCHING
void FUN_0022ea40(u32* object, u32 value)
{
    u8* bytes;
    u32 i;
    u32 table;

    if (object == NULL) {
        return;
    }
    bytes = (u8*)object;
    table = FUN_0021c3f0(3);
    for (i = 0; i < 3; ++i) {
        u8* dst = bytes + 0x50 + i * 0x10;
        *(u32*)dst = value + i;
        FUN_0021d3b0(dst, FUN_0021cca0(table, 0x42 + i));
    }
}

// FUN_0022EB30 NONMATCHING
void FUN_0022eb30(u32* object, u32 value, u32 colour)
{
    u8* bytes;
    u32 i;
    u32 table;

    if (object == NULL) {
        return;
    }
    bytes = (u8*)object;
    table = FUN_0021c3f0(3);
    for (i = 0; i < 3; ++i) {
        u8* dst = bytes + 0x60 + i * 0x10;
        *(u32*)dst = value + i;
        *(u32*)(dst + 4) = colour;
        FUN_0021d3b0(dst, FUN_0021cca0(table, 0x43 + i));
    }
}

// FUN_0022ECB0
void FUN_0022ecb0(u8* destination, u8* source, f32 scale)
{
    f32 values[4];
    f32 factor;
    f32 converted;
    u32 value;
    volatile u8* depth;

    factor = 1.0f / *(f32*)((u8*)FUN_00198590() + 0x80);
    FUN_0021cd00(source, values);
    values[2] = values[0] + scale * (values[2] - values[0]);

    *(f32*)(destination + 0x10) = values[0];
    *(f32*)(destination + 0x14) = values[1];
    *(f32*)(destination + 0x18) = factor;
    depth = (u8*)D_00960090 - 8;
    *(f32*)(destination + 0x08) = *(f32*)depth;

    value = source[0x1c];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0x20) = converted;
    value = source[0x1d];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0x24) = converted;
    value = source[0x1e];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0x28) = converted;
    value = source[0x1f];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0x2c) = converted;

    *(f32*)(destination + 0x50) = values[2];
    *(f32*)(destination + 0x54) = values[1];
    *(f32*)(destination + 0x58) = factor;
    *(f32*)(destination + 0x48) = *(f32*)depth;

    value = source[0x20];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0x60) = converted;
    value = source[0x21];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0x64) = converted;
    value = source[0x22];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0x68) = converted;
    value = source[0x23];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0x6c) = converted;

    *(f32*)(destination + 0x90) = values[2];
    *(f32*)(destination + 0x94) = values[3];
    *(f32*)(destination + 0x98) = factor;
    *(f32*)(destination + 0x88) = *(f32*)depth;

    value = source[0x24];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0xa0) = converted;
    value = source[0x25];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0xa4) = converted;
    value = source[0x26];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0xa8) = converted;
    value = source[0x27];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0xac) = converted;

    *(f32*)(destination + 0xd0) = values[0];
    *(f32*)(destination + 0xd4) = values[3];
    *(f32*)(destination + 0xd8) = factor;
    *(f32*)(destination + 0xc8) = *(f32*)depth;

    value = source[0x28];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0xe0) = converted;
    value = source[0x29];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0xe4) = converted;
    value = source[0x2a];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0xe8) = converted;
    value = source[0x2b];
    if (value >= 0) {
        converted = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        converted = (f32)value;
        converted += converted;
    }
    *(f32*)(destination + 0xec) = converted;
}

// FUN_0022F1C0
void FUN_0022f1c0(u32* object, u64 event)
{
    u32 status;
    u64 code;

    status = object[0];
    if ((status & 4) != 0) {
        object[0] = status & ~4u;
    }
    if ((event & 0x80000) != 0) {
        object[0x20c] = 8;
        object[0] |= 4;
    } else {
        code = (event << 0x2c) >> 0x2c;
        switch (code) {
        case 1:
            object[0x20c] = 0;
            object[0] |= 4;
            break;
        case 2:
            object[0x20c] = 1;
            object[0] |= 4;
            break;
        case 4:
            object[0x20c] = 2;
            object[0] |= 4;
            break;
        case 8:
            object[0x20c] = 3;
            object[0] |= 4;
            break;
        case 0x10:
            object[0x20c] = 4;
            object[0] |= 4;
            break;
        case 0x20:
            object[0x20c] = 5;
            object[0] |= 4;
            break;
        case 0x40:
            object[0x20c] = 6;
            object[0] |= 4;
            break;
        case 0x80:
            object[0x20c] = 7;
            object[0] |= 4;
            break;
        case 0x200:
            object[0x20c] = 10;
            object[0] |= 4;
            break;
        }
    }
    if ((object[0] & 4) != 0) {
        FUN_0022f3b0(object);
    }
}

// FUN_0022F3B0 NONMATCHING
void FUN_0022f3b0(u32* object)
{
    u8* bytes;
    u8* dst;
    u32 table;
    u32 state;
    u32 resource;
    u32 randVal;
    s32 i;
    f32 rect[4];

    bytes = (u8*)object;
    table = FUN_0021c3f0(4);
    state = object[0x20c];

    switch (state) {
    case 0:
        dst = bytes + 0x1060;
        resource = FUN_0021cca0(table, 0);
        for (i = 0; i < 3; ++i) {
            FUN_0021d3b0(dst + i * 0x100, resource);
        }
        *(u32*)(dst + 0x30c) = 0;
        break;

    case 1:
        dst = bytes + 0x1060;
        for (i = 0; i < 3; ++i) {
            u8* slot = dst + i * 0x200;
            resource = FUN_0021cca0(table, 1);
            FUN_0021d3b0(slot, resource);
            resource = FUN_0021cca0(table, 2);
            FUN_0021d3b0(slot + 0x100, resource);
        }
        *(u32*)(dst + 0x60c) = 0;
        break;

    case 2:
        dst = bytes + 0x1060;
        for (i = 0; i < 3; ++i) {
            u8* slot = dst + i * 0x100;
            randVal = RpRandom() % 5;
            switch (randVal) {
            case 4: resource = FUN_0021cca0(table, 7); break;
            case 3: resource = FUN_0021cca0(table, 6); break;
            case 2: resource = FUN_0021cca0(table, 5); break;
            case 1: resource = FUN_0021cca0(table, 4); break;
            case 0: resource = FUN_0021cca0(table, 3); break;
            }
            FUN_0021d3b0(slot, resource);
            *(u32*)(dst + i * 4 + 0x300) = (i * 3 * 4) / 3;
        }
        *(u32*)(dst + 0x30c) = 0;
        break;

    case 3:
        dst = bytes + 0x1060;
        resource = FUN_0021cca0(table, 8);
        FUN_0021d3b0(dst, resource);
        FUN_0021d3b0(dst + 0x100, resource);
        FUN_0021cd00(resource, rect);
        {
            f32 tmp = rect[0];
            rect[0] = rect[2];
            rect[2] = tmp;
        }
        FUN_0021eae0(dst + 0x100, rect);
        randVal = RpRandom() % 30;
        *(u32*)(dst + 0x20c) = randVal;
        for (i = 0; i < 2; ++i) {
            u32 value = randVal + (i * 15 * 2) / 2;
            *(u32*)(dst + 0x200 + i * 4) = value;
            *(u32*)(dst + 0x200 + i * 4) = value % 30;
        }
        break;

    case 4:
    case 10:
        dst = bytes + 0x1060;
        for (i = 0; i < 2; ++i) {
            u8* slot = dst + i;
            u8 bit = (u8)(RpRandom() & 1);
            *slot = bit;
            if (bit == 1) {
                resource = FUN_0021cca0(table, 9);
            } else if (bit == 0) {
                resource = FUN_0021cca0(table, 9);
            }
            FUN_0021d3b0(dst + i * 0x100, resource);
            *(u32*)(dst + i * 4 + 0x200) = (i * 3 * 4) / 2;
        }
        *(u32*)(dst + 0x20c) = 0;
        break;

    case 5:
        dst = bytes + 0x1060;
        resource = FUN_0021cca0(table, 0xb);
        FUN_0021d3b0(dst, resource);
        FUN_0021d3b0(dst + 0x100, resource);
        resource = FUN_0021cca0(table, 0xc);
        for (i = 0; i < 3; ++i) {
            *(u8*)(dst + i) = (u8)i;
            FUN_0021d3b0(dst + i * 0x100 + 0x200, resource);
            *(u32*)(dst + i * 4 + 0x500) = (i * 5 * 8) / 3;
        }
        *(u32*)(dst + 0x510) = 0;
        break;

    case 6:
        dst = bytes + 0x1060;
        resource = FUN_0021cca0(table, 0xd);
        FUN_0021d3b0(dst, resource);
        resource = FUN_0021cca0(table, 0xe);
        FUN_0021d3b0(dst + 0x100, resource);
        resource = FUN_0021cca0(table, 0xe);
        FUN_0021d3b0(dst + 0x200, resource);
        randVal = RpRandom() % 20;
        *(u32*)(dst + 0x300) = randVal;
        break;

    case 7:
        dst = bytes + 0x1060;
        for (i = 0; i < 4; ++i) {
            u8* slot = dst + i;
            u8 bit1 = (u8)(RpRandom() & 1);
            u8 bit2 = (u8)(RpRandom() & 1);
            u8 bit3;
            *(slot + 0x410) = bit1;
            *(slot + 0x414) = bit2;
            bit3 = (u8)(RpRandom() & 1);
            *(slot + 0x418) = bit3;
            if (bit1 == 1) {
                resource = FUN_0021cca0(table, 0x10);
            } else if (bit1 == 0) {
                resource = FUN_0021cca0(table, 0xf);
            }
            FUN_0021d3b0(dst + i * 0x100, resource);
            *(u32*)(dst + i * 4 + 0x400) = (i * 5 * 8) / 4;
        }
        *(u32*)(dst + 0x41c) = 0;
        break;

    case 8:
        resource = FUN_0021cca0(table, 0x11);
        FUN_0021d3b0(bytes + 0x1060, resource);
        break;

    case 9:
        resource = FUN_0021cca0(table, 0);
        FUN_0021d3b0(bytes + 0x1060, resource);
        break;
    }
}

// FUN_0022FA80 NONMATCHING
void FUN_0022fa80(u32* object)
{
    u8* bytes;
    u32 i;
    u32 table;
    u32 count;
    u32 state;

    if (object == NULL) {
        return;
    }
    bytes = (u8*)object;
    table = FUN_0021c3f0(4);
    state = object[0x20c];
    count = *(u32*)(bytes + 0x6070);
    if (count > 8) {
        count = 8;
    }
    for (i = 0; i < count; ++i) {
        u8* record = bytes + 0x4660 + i * 0x420;
        u32 active = *(u32*)record;
        if (active == 0) {
            FUN_0021d3b0(record + 0x10,
                         FUN_0021cca0(table, 0x2f));
        } else {
            FUN_0021d3b0(record + 0x10,
                         FUN_0021cca0(table, 0x29 + (state & 1)));
        }
        bcm_panel_layout_record(record, i, *(u32*)(bytes + 0x4650));
        *(u32*)record |= 4;
    }
    if ((object[0] & 4) != 0) {
        bcm_panel_refresh_records();
    }
}

