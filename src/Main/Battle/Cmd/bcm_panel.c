#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBcmPanel; // puGpffffb618
u32 FUN_0021c3f0();
u32 FUN_0021cca0();
void FUN_0021d3b0();
u32 FUN_0021cce0();
extern void (*D_00960090)(u32, u32);
extern void (*D_0096009C)(u32*, u32, u32, u32, u32);
extern void RpSkyRenderStateSet(u32, void*);
void FUN_00226320();
void FUN_00222d60();
void FUN_0021e380();
void FUN_0022c210();
void FUN_00222b90();
void FUN_002230e0();
u32 FUN_0021c450();
u32 FUN_0021cd00();
void FUN_0021d890();
void FUN_0021d950();
void FUN_0021d8e0();
void FUN_0022c210();
void FUN_00224860();
void FUN_00225670();
void FUN_00227d10();
void FUN_00238980();
void FUN_00238bf0();
void FUN_00238dc0();
void FUN_0022e780(u32*, u32);
void FUN_0022e900(u32*, u32);
void FUN_0022e9a0(u32*, u32);
void FUN_0022ea40(u32*, u32);
void FUN_0022eb30(u32*, u32, u32);
void FUN_0022ecb0(u8*, u8*, f32);
u32 FUN_0022e850(u32);
void FUN_0022f1c0(u32*, u32);
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
// FUN_00222b90 NONMATCHING
void FUN_00222b90(void)
{
    u32* work;
    u32 table0;
    u32 table6;
    u8* record;
    u32 i;
    u32 state;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = sBcmPanel;
    table0 = FUN_0021c3f0(0);
    table6 = FUN_0021c3f0(6);
    K_ASSERT((work[1] & 2) != 0, 0x60d);
    for (i = 0; i < work[0x181c]; i++)
    {
        record = bcm_panel_record(i);
        state = *(u32*)(record + 8);
        if (state == 0)
            FUN_0021d3b0(record + 0x10, FUN_0021cca0(table0, 0x30));
        else if (state == 1)
            FUN_0021d3b0(record + 0x10, FUN_0021cca0(table0, 0x31));
        else
            continue;
        FUN_00238980(record + 0x110, 3, *(u32*)(record + 0x0c), 1);
        FUN_0021d3b0(record + 0x410, FUN_0021cca0(table6, 0x2b));
    }
    if (*(u32*)((u8*)work + 0x68f8) != 0)
        FUN_0021d3b0((u8*)work + 0x6900,
                     FUN_0021cca0(table6, *(u32*)((u8*)work + 0x68f4) + 0x20));
}
// FUN_00222d60 NONMATCHING
void FUN_00222d60(void)
{
    u32* work;
    u32 table0;
    u32 table6;
    u8* record;
    u32 i;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = sBcmPanel;
    table0 = FUN_0021c3f0(0);
    table6 = FUN_0021c3f0(6);
    K_ASSERT((work[1] & 1) != 0, 0x63c);
    for (i = 0; i < work[0x181c]; i++)
    {
        record = bcm_panel_record(i);
        FUN_0021d3b0(record + 0x10, FUN_0021cca0(table0, 0x28));
        FUN_00238980(record + 0x110, 2, *(u32*)(record + 4), 1);
        FUN_0021d3b0(record + 0x310, FUN_0021cca0(table6, 0x1a));
    }
    if (*(u32*)((u8*)work + 0x68f8) != 0)
        FUN_0021d3b0((u8*)work + 0x6900,
                     FUN_0021cca0(table6, *(u32*)((u8*)work + 0x68f4) + 0x20));
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
    u32 i;
    u32 j;
    u32 count;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    count = bcm_panel_read(0x6070);
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        u32 state = *(u32*)record;
        if (state == 0 || state == 2) {
            bcm_panel_set_resource(record + 0x10, 0, 0x2f);
        } else if (state == 1) {
            for (j = 0; j < 2; ++j) {
                bcm_panel_set_resource(record + 0x10 + j * 0x100, 0, 0x29);
            }
            for (j = 2; j < 4; ++j) {
                bcm_panel_set_resource(record + 0x10 + j * 0x100, 0, 0x2a);
            }
        }
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

// FUN_00224660 NONMATCHING
void FUN_00224660(void)
{
    u32 i;
    u32 table;
    u32 count;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    table = FUN_0021c3f0(0);
    bcm_panel_write(0, bcm_panel_read(0) | 2);
    bcm_panel_write(4, 8);
    bcm_panel_write(0x4630, 3);
    bcm_panel_write(0x4640, bcm_panel_read(0x463c));
    bcm_panel_write(0x463c, 4);
    bcm_panel_write(0x4650, 0);
    FUN_00226320();
    bcm_panel_set_resource(bcm_panel_bytes() + 0x1230, 0, bcm_panel_read(0x4634));
    bcm_panel_set_resource(bcm_panel_bytes() + 0x1330, 0, bcm_panel_read(0x4634) + 7);
    FUN_0021d3b0(bcm_panel_bytes() + 0x4230, FUN_0021cca0(table, 0x24));
    FUN_0021e380(bcm_panel_bytes() + 0x4330,
                 FUN_0021cca0(table, 0x24), 1);
    bcm_panel_set_resource(bcm_panel_bytes() + 0x4f50, 0, 0x13);
    bcm_panel_set_resource(bcm_panel_bytes() + 0x5050, 0, 0x4b);
    count = bcm_panel_read(0x6070);
    for (i = 0; i < count; ++i) {
        bcm_panel_set_resource(bcm_panel_record(i) + 0x10, 0, 0x44);
    }
    FUN_00224860();
}

// FUN_00224860 NONMATCHING
void FUN_00224860(void)
{
    u32 i;
    u32 count;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    count = bcm_panel_read(0x6070);
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        FUN_00238980(record + 0x100, 2, *(u32*)(record + 0x304), 1);
    }
}

// FUN_00224940 NONMATCHING
void FUN_00224940(void)
{
    u32 i;
    u32 j;
    u32 count;
    u32 alpha;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    count = bcm_panel_read(0x6070);
    alpha = bcm_panel_read(0x4650);
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        u32 kind = *(u32*)record;
        bcm_panel_layout_record(record, i, alpha);
        if (kind == 1) {
            for (j = 0; j < 4; ++j) {
                bcm_panel_layout_record(record + j * 0x100, i, alpha);
            }
        }
        *(u32*)record |= 4;
    }
    bcm_panel_set_resource(bcm_panel_bytes() + 0xf50, 0, 0x13);
    bcm_panel_set_resource(bcm_panel_bytes() + 0x1050, 0, 0x4b);
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

// FUN_002255F0 NONMATCHING
void FUN_002255F0(void)
{
    K_ASSERT(sBcmPanel != NULL, 0xe6);
    bcm_panel_write(0x4630, 5);
    bcm_panel_write(0x4658, 0);
    bcm_panel_write(0, bcm_panel_read(0) | 8);
    bcm_panel_write(0x4644, 0);
    bcm_panel_write(0x4648, 1);
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
    FUN_0021d8e0(overlay, overlay);
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

// FUN_00226320 NONMATCHING
void FUN_00226320(void)
{
    u32 i;
    u32 table;
    u8* base;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = bcm_panel_bytes();
    table = FUN_0021c3f0(0);
    for (i = 0; i < 6; ++i) {
        u8* slot = base + 0x6050 + i * 0x10;
        FUN_0021d3b0(slot, FUN_0021cca0(table, 0x24));
        *(u32*)(slot + 0xc) = i;
    }
    bcm_panel_write(0x7210, 0);
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

// FUN_00227D10 NONMATCHING
void FUN_00227D10(void)
{
    u32 i;
    u32 count;
    u32 table;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    table = FUN_0021c3f0(0);
    count = bcm_panel_read(0x6070);
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        FUN_0021d3b0(record + 0x10, FUN_0021cca0(table, 0x2f));
        FUN_0021e380(record + 0x110,
                     FUN_0021cca0(table, 0x29), 1);
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
    u32 i;
    u32 j;
    u32 count;
    u32 colour;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    count = bcm_panel_read(0x6070);
    colour = bcm_panel_read(0x4650) & 0xff;
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        bcm_panel_set_colour(record, colour | 0xffffff00u);
        for (j = 0; j < 4 && *(u32*)record == 1; ++j) {
            bcm_panel_set_colour(record + j * 0x100,
                                 colour | 0xffffff00u);
        }
    }
}

// FUN_0022AE80 NONMATCHING
void FUN_0022AE80(void)
{
    u32 i;
    u32 count;
    u8* base;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = bcm_panel_bytes();
    count = bcm_panel_read(0x6070);
    for (i = 0; i < count; ++i) {
        u8* record = bcm_panel_record(i);
        bcm_panel_set_resource(record + 0x10, 0, 0x2f);
        *(u32*)(record + 0x50) = i * 0x30;
        *(u32*)(record + 0x60) = bcm_panel_read(0x4644);
    }
    FUN_0021d3b0(base + 0x6d00,
                 FUN_0021cca0(FUN_0021c3f0(0), 0x13));
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
    *(u32*)(base + 0x68f0) = count;
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

// FUN_0022BF60 NONMATCHING
void FUN_0022BF60(void)
{
    u32 table;
    u8* base;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = bcm_panel_bytes();
    table = FUN_0021c3f0(0);
    FUN_0022C210();
    FUN_0021d3b0(base + 0x6d00, FUN_0021cca0(table, 0x42));
    bcm_panel_write(0x4644, 3);
}

// FUN_0022C0A0
void FUN_0022C0A0(void)
{
    K_ASSERT(sBcmPanel != NULL, 0xe6);
    *(u32*)((int)sBcmPanel + 0x4644) = 0;
}

// FUN_0022C0E0 NONMATCHING
void FUN_0022C0E0(void)
{
    u32* base;
    u32 table0;
    u32 table6;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = sBcmPanel;
    table0 = FUN_0021c3f0(0);
    table6 = FUN_0021c3f0(6);
    FUN_0022C210();
    FUN_0021d3b0((u8*)base + 0x6d10,
                 FUN_0021cca0(table0, 0x28));
    FUN_00238980((u8*)base + 0x6e10, 2,
                 *(u32*)((u8*)base + 0x6d04), 1);
    FUN_0021d3b0((u8*)base + 0x6f10,
                 FUN_0021cca0(table6, 0x1a));
    *(u32*)((u8*)base + 0x4644) = 4;
}

// FUN_0022C1D0
void FUN_0022C1D0(void)
{
    K_ASSERT(sBcmPanel != NULL, 0xe6);
    *(u32*)((int)sBcmPanel + 0x4644) = 0;
}

// FUN_0022C210 NONMATCHING
void FUN_0022C210(void)
{
    u8* base;
    u32 table;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = bcm_panel_bytes();
    table = FUN_0021c3f0(0);
    bcm_panel_set_resource(base + 0x6a00, 0, 0x42);
    FUN_0021e380(base + 0x6b00,
                 FUN_0021cca0(table, 0x42), 1);
    bcm_panel_set_resource(base + 0x6c00, 0, 0x43);
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
    (*D_00960090)(1, FUN_0021cce0(resource));
    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    (*D_0096009C)((u32*)(base + 0x6a00), 4, 0, 1, 2);
    (*D_0096009C)((u32*)(base + 0x6a00), 4, 0, 2, 3);
    (*D_0096009C)((u32*)(base + 0x6b00), 4, 0, 1, 2);
    (*D_0096009C)((u32*)(base + 0x6b00), 4, 0, 2, 3);
    (*D_0096009C)((u32*)(base + 0x6c00), 4, 0, 1, 2);
    (*D_0096009C)((u32*)(base + 0x6c00), 4, 0, 2, 3);
}

// FUN_0022C720 NONMATCHING
void FUN_0022c720(u32* object, u32 style)
{
    u32 resource;
    u32 table;

    object[0] = 0;
    *(f32*)((u8*)object + 0x510) = 100.0f;
    *(f32*)((u8*)object + 0x514) = 100.0f;
    *(u16*)((u8*)object + 4) = (u16)style;
    table = FUN_0021c3f0(3);
    resource = FUN_0021c450(style);
    FUN_0021d3b0((u8*)object + 0x10,
                 FUN_0021cca0(resource, 0));
    resource = FUN_0021cca0(resource, 1);
    FUN_0021d3b0((u8*)object + 0x110, resource);
    FUN_0021d3b0((u8*)object + 0x210, resource);
    FUN_0021d3b0((u8*)object + 0x310, resource);
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
    u8* bytes;
    u32 table;
    u32 i;

    if (object == NULL) {
        return;
    }
    bytes = (u8*)object;
    if ((object[0] & 1) == 0) {
        return;
    }
    table = FUN_0021c3f0(3);
    for (i = 0; i < 6; ++i) {
        u8* slot = bytes + 0x510 + i * 0x10;
        if (*(u32*)slot != 0) {
            FUN_0021d3b0(slot + 0x10,
                         FUN_0021cca0(table, 0x2f));
        }
    }
}

// FUN_0022E780 NONMATCHING
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
    if (style < 6) {
        switch (style) {
        case 0:
            panel[0] &= ~3u;
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

// FUN_0022E900 NONMATCHING
void FUN_0022e900(u32* object, u32 value)
{
    u8* resource;
    f32 denominator;
    f32 scale;

    resource = (u8*)FUN_0021cca0(FUN_0021c3f0(5), 2);
    *(u32*)((u8*)object + 0x834) = value;
    FUN_0022ea40((u32*)((u8*)object + 0x860), value);
    denominator = (f32)*(u32*)((u8*)object + 0x838);
    scale = (f32)value / denominator;
    FUN_0022ecb0((u8*)object + 0xe60, resource, scale);
}

// FUN_0022E9A0 NONMATCHING
void FUN_0022e9a0(u32* object, u32 value)
{
    u8* resource;
    f32 denominator;
    f32 scale;

    resource = (u8*)FUN_0021cca0(FUN_0021c3f0(5), 3);
    *(u32*)((u8*)object + 0x83c) = value;
    FUN_0022ea40((u32*)((u8*)object + 0xf60), value);
    denominator = (f32)*(u32*)((u8*)object + 0x840);
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

// FUN_0022ECB0 NONMATCHING
void FUN_0022ecb0(u8* destination, u8* source, f32 scale)
{
    u32 i;
    if (destination == NULL || source == NULL) {
        return;
    }
    for (i = 0; i < 4; ++i) {
        f32 value = *(f32*)(source + i * 4);
        *(f32*)(destination + i * 4) = value * scale;
    }
}

// FUN_0022F1C0 NONMATCHING
void FUN_0022f1c0(u32* object, u32 event)
{
    u32 code;
    if (object == NULL) {
        return;
    }
    if ((object[0] & 4) != 0) {
        object[0] &= ~4u;
    }
    if ((event & 0x80000u) != 0) {
        object[0x20c] = 8;
        object[0] |= 4;
    } else {
        code = event & 0xfffu;
        switch (code) {
        case 0:
            object[0x20c] = 0;
            break;
        case 1:
            object[0x20c] = 0;
            break;
        case 2:
            object[0x20c] = 1;
            break;
        case 4:
            object[0x20c] = 2;
            break;
        case 8:
            object[0x20c] = 3;
            break;
        case 0x10:
            object[0x20c] = 4;
            break;
        case 0x20:
            object[0x20c] = 5;
            break;
        case 0x40:
            object[0x20c] = 6;
            break;
        case 0x80:
            object[0x20c] = 7;
            break;
        case 0x200:
            object[0x20c] = 10;
            break;
        default:
            return;
        }
        object[0] |= 4;
    }
    if ((object[0] & 4) != 0) {
        FUN_0022f3b0(object);
    }
}

// FUN_0022F3B0 NONMATCHING
void FUN_0022f3b0(u32* object)
{
    u8* bytes;
    u32 table;
    u32 state;
    u32 resource;

    if (object == NULL) {
        return;
    }
    bytes = (u8*)object;
    table = FUN_0021c3f0(4);
    state = object[0x20c];
    resource = (state < 0xb) ? state + 0x20 : 0x20;
    FUN_0021d3b0(bytes + 0x400,
                 FUN_0021cca0(table, resource));
    *(u32*)(bytes + 0x500) = state;
    *(u32*)(bytes + 0x50c) = state * 2;
    object[0] &= ~4u;
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

