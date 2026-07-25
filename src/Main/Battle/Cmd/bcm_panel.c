#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

static u32* sBcmPanel; // puGpffffb618
u32 FUN_0021c3f0();
u32 FUN_0021cca0();
void FUN_0021d3b0();
u32 FUN_0021cce0();
extern u32 D_00960090[];
#pragma alias D_00960090_abs D_00960090
extern u8 D_00960090_abs[];
extern u32 D_0096009C[];
#pragma alias D_0096009C_abs D_0096009C
extern u8 D_0096009C_abs[];
#pragma alias D_00960090_fn D_00960090
#pragma alias D_0096009C_fn D_0096009C
extern void (*D_00960090_fn)(u32, u32);
extern void (*D_0096009C_fn)(u32*, u32, u32, u32, u32);
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
extern void FUN_0021dd60(void* destination, const u8* colors);
extern f32 fGpffff83e8;
extern u32 RpRandom(void);
extern void bppPanelDrawParameterLayout(void* work);
u32 FUN_0022e850(u32);
void FUN_0022eb30(u32* object, u32 value, u32 colour);
extern s32 sprintf(char* buffer, const char* format, ...);
extern s32 strlen(const char* string);
extern void K_Assert(const char* file, s32 line);
extern f32 D_0068E380[];
extern f32 D_0068E3BC[];
extern u8 D_0068E4B0[];
extern u8 D_0068E4D8[];
extern f32 D_007CB0D4;
extern f32 sinf(f32 angle);
extern f32 cosf(f32 angle);
extern f32 D_0068E4F0[];
extern f32 D_0068E460[];
extern f32 D_0068E490[];
void FUN_0021e170(u8*, const f32*, const f32*, const f32*);
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

// FUN_002230e0 NONMATCHING
void FUN_002230e0(void)
{
    s32 j;
    s32 i;
    u32 table0;
    u8* record;
    u8* records;
    u8* work;

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
    u32 colourA, colourB, colourC, colourD;
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
        colourA = (alphaByte & 0xff) | 0xffffff00u;
        *(u32*)(records + 0x18c4) = colourA;
        colourB = 0xff - (alphaByte & 0xff);
        *(u32*)(records + 0x18c8) = colourB | 0xff9d9d00u;
        *(u32*)(records + 0x18cc) = colourB | 0xffffff00u;
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
        frame = (void*)FUN_0021cca0(table0, 0x2f);
        FUN_0021d3b0(records + 0x18f0, frame);
        layout[0] = 178.0f + *(f32*)(pos + 0);
        layout[1] = 55.0f + *(f32*)(pos + 4);
        layout[2] = (f32)*(s32*)((u8*)frame + 0xc);
        layout[3] = (f32)*(s32*)((u8*)frame + 0x10);
        FUN_0021d8e0(records + 0x18f0, layout);
        colour[0] = 0xff;
        colour[1] = 0xff;
        colour[2] = 0xff;
        colour[3] = 0xff - (alphaByte & 0xff);
        FUN_0021d950(records + 0x18f0, colour);
    }

    colourA = (alphaByte & 0xff) | 0xffffff00u;
    colourB = (alphaByte & 0xff) | 0xbeffd200u;
    colourC = (alphaByte & 0xff) | 0xcccccc00u;
    colourD = (alphaByte & 0xff) | 0x64cc6400u;
    scaledAlphaColour = ((alphaByte & 0xff) << 7) / 0xff;
    scaledAlphaColour = 0xffffff00u | scaledAlphaColour;
    for (i = 0; i < *(u32*)(base + 0x6070); i++) {
        u8* record = records + i * 0x420;
        kind = *(u32*)record;
        if (kind == 1) goto loop_kind1;
        if (kind == 2) goto loop_kind02;
        if (kind == 0) goto loop_kind02;
        goto loop_next;
    loop_kind02:
        handle = (u32)*(void**)(record + 8);
        layout[0] = 51.0f + *(f32*)(pos + 0);
        layout[1] = 19.0f + *(f32*)(pos + 4) + (f32)(i * 26);
        if (i == (u32)(*(s32*)(base + 0x6068) - *(s32*)(base + 0x606c))) {
            if (*(u32*)(record + 0x410) != 0) {
                selColour = scaledAlphaColour;
            } else if (kind == 2) {
                selColour = colourB;
            } else if (kind == 0) {
                selColour = colourA;
            }
        } else {
            if (*(u32*)(record + 0x410) != 0) {
                selColour = scaledAlphaColour;
            } else if (kind == 2) {
                selColour = colourD;
            } else if (kind == 0) {
                selColour = colourC;
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
            selColour = colourA;
        } else {
            selColour = colourC;
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
    loop_next:
        ;
    }
}

// Previous body was a wrong-helper stub unrelated to retail (1296B window).
// Rewritten from disasm: retail dispatches per-record state via a switch
// (case 0/2 shared, case 1 loops 4 quad slots), using the same
// D_00960090_abs/D_0096009C_abs vtable style as this file's other draw
// functions. Key finding: D_0096009C_abs must be re-cast to a fresh local
// inside both the state==1 loop and the case 0/2 body, matching retail's
// per-branch re-materialization (its cache register doubles as the loop
// counter on the other switch arm). nd 198->6 (obj 1292B/1296B); residual
// is a 2-variable register-bank swap (slot0/setQuad), unfixable per the
// usual declaration/statement-order floor.
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
    void (**setState2)(u32, u32);
    void (**setQuad2)(u32*, u32, u32, u32, u32);
    void (**setQuad3)(u32*, u32, u32, u32, u32);
    void (**setState4)(u32, u32);
    void (**setQuad4)(u32*, u32, u32, u32, u32);

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    table1 = FUN_0021c3f0(1);
    table3 = FUN_0021c3f0(3);
    records = work + 0x4660;

    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);

    resource = FUN_0021cca0(table0, 0x23);
    texture = FUN_0021cce0(resource);
    setState = (void (**)(u32, u32))D_00960090_abs;
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
        setState2 = (void (**)(u32, u32))D_00960090_abs;
        (*setState2)(1, texture);

        setQuad2 = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
        (*setQuad2)((u32*)record, 4, 0, 1, 2);
        (*setQuad2)((u32*)record, 4, 0, 2, 3);

        texture = FUN_00239140(1);
        (*setState2)(1, texture);
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);

        for (j = 0; j < 2; ++j) {
            quadTarget = record + j * 0x100 + 0x100;
            setQuad3 = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
            (*setQuad3)((u32*)quadTarget, 4, 0, 1, 2);
            (*setQuad3)((u32*)quadTarget, 4, 0, 2, 3);
        }
    }

    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);

    resource = FUN_0021cca0(table3, 0x13);
    texture = FUN_0021cce0(resource);
    setState4 = (void (**)(u32, u32))D_00960090_abs;
    (*setState4)(1, texture);

    setQuad4 = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
    (*setQuad4)((u32*)(records + 0xf50), 4, 0, 1, 2);
    (*setQuad4)((u32*)(records + 0xf50), 4, 0, 2, 3);

    resource = FUN_0021cca0(table1, 0x4b);
    texture = FUN_0021cce0(resource);
    (*setState4)(1, texture);

    (*setQuad4)((u32*)(records + 0x1050), 4, 0, 1, 2);
    (*setQuad4)((u32*)(records + 0x1050), 4, 0, 2, 3);
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

// Previous body used bcm_panel_read/write's wrong work-relative base for
// the 0x55c/0x550 count/progress fields (should be overlay0-relative,
// same bug class as FUN_00224150/FUN_00225040) and fabricated the
// interpolated y-offset via raw integer bit-pattern arithmetic instead
// of retail's genuine float divide. The enlarged local rectangle preserves
// retail's 0x70-byte frame, while explicit temporaries preserve mul ordering.
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
    s32 alphaI;
    u8 alphaByte;
    u8 color[4];
    void* frame;
    f32 rect[4];
    u32 colour0;
    u32 colour1;
    u32 colour2;
    u32 colour3;
    u32 colour4;
    u32 resource1;
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
    if (2147483648.0f <= alphaF) {
        alphaI = (s32)(alphaF - 2147483648.0f) | 0x80000000;
    } else {
        alphaI = (s32)alphaF;
    }
    alphaByte = (u8)alphaI;

    frame = (void*)FUN_0021cca0(table0, 0x24);
    rect[0] = 47.0f + posB[0];
    rect[1] = 19.0f + posB[1] +
              (f32)((*(s32*)(overlay0 + 0x554) - *(s32*)(overlay0 + 0x558)) * 26);
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(work + 0x4430, rect);

    frame = (void*)FUN_0021cca0(table0, 0x24);
    rect[0] = 47.0f + posB[0] + (f32)*(s32*)((u8*)frame + 0xc);
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

    colour0 = (u32)alphaByte | 0xffffff00u;
    colour1 = (u32)alphaByte | 0xcccccc00u;
    colour2 = (u32)alphaByte | 0xbeffd200u;
    colour3 = (u32)alphaByte | 0x64cc6400u;
    colour4 = ((u32)alphaByte * 50 / 100) | 0xffffff00u;

    for (i = 0; i < *(s32*)(overlay0 + 0x55c); ++i) {
        overlayI = overlay0 + i * 0x110;
        resource1 = *(u32*)(overlayI + 4);

        diffY = i * 26;
        rect[0] = 103.0f + posB[0];
        rect[1] = 19.0f + posB[1] + (f32)diffY;
        FUN_003b0d70(resource1, (s32)rect[0] << 4, (s32)rect[1] << 3);

        state = *(u32*)overlayI;
        switch (state) {
        case 0:
            colour = (i == *(s32*)(overlay0 + 0x554) - *(s32*)(overlay0 + 0x558))
                         ? colour0
                         : colour1;
            break;
        case 2:
            colour = (i == *(s32*)(overlay0 + 0x554) - *(s32*)(overlay0 + 0x558))
                         ? colour2
                         : colour3;
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
        case 2:
        case 1:
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

#pragma push
#pragma opt_common_subs off
// FUN_002265D0 NONMATCHING
void FUN_002265D0(void)
{
    u8* work;
    u32 table0;
    void* resource;
    f32 posX;
    f32 posY;
    f32 rowY;
    f32 rect[4];
    u8 color[4];
    s32 i;
    s32 j;
    f32 stateAlpha;
    f32 transAlpha;
    f32 rowOffset;
    f32 rowStep;

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    stateAlpha = *(f32*)(work + 0x7214);
    rowOffset = -26.0f * (f32)*(s32*)(work + 0x7210);
    rowStep = 26.0f * (f32)*(s32*)(work + 0x7210);

    if (*(u32*)(work + 0x463c) == 3) {
        if (*(u32*)(work + 0x4644) == 1 || *(u32*)(work + 0x4644) == 2) {
            transAlpha = (f32)*(s32*)(work + 0x4658) / 6.0f;
            posX = 38.0f + -191.0f * transAlpha;
            posY = 237.0f + -66.0f * transAlpha;
        } else if (*(u32*)(work + 0x4644) == 0 &&
                   (*(u32*)(work + 0x4648) == 1 || *(u32*)(work + 0x4648) == 2) &&
                   *(s32*)(work + 0x4658) < 6) {
            transAlpha = (f32)*(s32*)(work + 0x4658) / 6.0f;
            posX = -153.0f + 191.0f * transAlpha;
            posY = 171.0f + 66.0f * transAlpha;
        } else {
            f32 f2 = (f32)*(s32*)(work + 0x4650);
            posX = (38.0f * f2) / 3.0f;
            posY = 277.0f + (-40.0f * f2) / 3.0f;
        }
    } else if (*(u32*)(work + 0x463c) == 0) {
        f32 f3 = (f32)*(s32*)(work + 0x4650);
        posX = 38.0f + (-38.0f * f3) / 3.0f;
        posY = 237.0f + (40.0f * f3) / 3.0f;
    } else if (*(u32*)(work + 0x463c) == 4 || *(u32*)(work + 0x463c) == 1 ||
               *(u32*)(work + 0x463c) == 2) {
        f32 f2 = (f32)*(s32*)(work + 0x4650);
        posX = (38.0f * f2) / 3.0f;
        posY = 277.0f + (-40.0f * f2) / 3.0f;
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
        posY = posY + complement * negRowOffset;
        rowY = posY + rowOffset;
        posY = rowY;
    }
    *(f32*)(work + 0x6050) = posX;
    *(f32*)(work + 0x6054) = rowY;

    {
        f32 y150 = 150.0f + rowStep;
        for (i = 0; i < 9; ++i) {
            switch (i) {
            case 0: case 1: case 2: case 3:
                resource = (void*)FUN_0021cca0(table0, i + 0x1e);
                break;
            case 4: case 5:
                resource = (void*)FUN_0021cca0(table0, i + 0x1a);
                break;
            }
            rect[0] = posX;
            rect[1] = rowY;
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
                rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
                rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
                break;
            case 4: case 5:
                rect[2] = 82.0f;
                rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
                break;
            case 6: case 7:
                rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
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

    color[0] = (u8)(u32)(40.0f + 215.0f * transAlpha);
    color[1] = (u8)(u32)(40.0f + 215.0f * transAlpha);
    color[2] = (u8)(u32)(30.0f + 225.0f * transAlpha);
    color[3] = (u8)(u32)(stateAlpha * (255.0f * (80.0f + 20.0f * transAlpha) / 100.0f) *
                          *(f32*)(work + 0x7214));
    for (i = 0; i < 9; ++i) {
        FUN_0021d950(work + i * 0x100 + 0x1530, color);
    }

    resource = (void*)FUN_0021cca0(table0, 0x26);
    {
        f32 baseX = 20.0f + posX;
        f32 baseY = 32.0f + rowY;

        rect[0] = baseX;
        rect[1] = baseY - 4.0f;
        rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
        rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
        FUN_0021d8e0(work + 0x1e30, rect);

        resource = (void*)FUN_0021cca0(table0, 0x27);
        rect[0] = baseX;
        rect[1] = 102.0f + rowY + rowStep;
        rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
        rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
        FUN_0021d8e0(work + 0x1f30, rect);

        resource = (void*)FUN_0021cca0(table0, 0x26);
        rect[0] = baseX;
        rect[1] = 16.0f + baseY - 4.0f;
        rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
        rect[3] = 57.0f + rowStep;
        FUN_0021d8e0(work + 0x2030, rect);

        resource = (void*)FUN_0021cca0(table0, 0x1d);
        {
            f32 top = (36.0f + rowY + rowOffset) - 4.0f;
            f32 bottom = 91.0f + rowY + rowOffset;
            rect[0] = 22.0f + posX;
            if (*(s32*)(work + 0x6074) >= 5) {
                f32 t = (f32)*(s32*)(work + 0x606c);
                f32 range = bottom - top;
                f32 denom = (f32)(*(s32*)(work + 0x6074) - 4);
                rect[1] = top + (t * range) / denom;
            } else {
                rect[1] = top;
            }
            rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
            rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
            FUN_0021d8e0(work + 0x2130, rect);
        }
    }

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(u32)(255.0f * stateAlpha * *(f32*)(work + 0x7214));
    for (i = 0; i < 3; ++i) {
        FUN_0021d950(work + i * 0x100 + 0x1e30, color);
    }
    FUN_0021d950(work + 0x2130, color);

    resource = (void*)FUN_0021cca0(table0, 0x2c);
    {
        f32 quadX = 47.0f + posX;
        f32 rowBaseY = 43.0f + rowY;
        for (j = 0; j < 6; ++j) {
            u8* slot = work + j * 0x200;
            f32 quadY = rowBaseY + (f32)(j * 26);
            rect[0] = quadX;
            rect[1] = quadY;
            rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
            rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
            FUN_0021d8e0(slot + 0x2230, rect);

            rect[0] = quadX + (f32)*(s32*)((u8*)resource + 0xc);
            rect[1] = quadY;
            rect[2] = 311.0f;
            rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
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
    color[3] = (u8)(u32)((f32)((s32)(30.0f + 225.0f * transAlpha) & 0xff) * 2.0f *
                          stateAlpha * *(f32*)(work + 0x7214));
    for (j = 0; j < 2; ++j) {
        u8* slot = work + j * 0x200;
        FUN_0021d950(slot + 0x2230, color);
        FUN_0021d950(slot + 0x2330, color);
    }

    color[3] = (u8)(u32)(255.0f * transAlpha);
    for (j = 2; j < 6; ++j) {
        u8* slot = work + j * 0x200;
        FUN_0021d950(slot + 0x2230, color);
        FUN_0021d950(slot + 0x2330, color);
    }
}
#pragma pop

// Previous body was a wrong-helper stub (232B) unrelated to retail (1296B
// window). Rewritten from disasm: retail does a 9-entry jump-table
// resource dispatch + per-slot D_00960090/D_0096009C indirect-vtable
// quad-draw calls (matching FUN_00229B40's style), not the guessed
// bcm_panel_* helpers. obj now 1292B/1296B; residual is a single
// register-bank choice (retail s3/mine s4 for `work`) cascading through
// the whole body - 2 declaration-order attempts had no effect (floor).
// FUN_00227800 NONMATCHING
void FUN_00227800(void)
{
    u8* work;
    u32 table0;
    u32 resource;
    u32 texture;
    u8* record;
    s32 i;
    s32 j;
    s32 loopCount;
    void (**setState)(u32, u32);
    void (**setQuad)(u32*, u32, u32, u32, u32);

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
    setState = (void (**)(u32, u32))D_00960090_abs;
    (*setState)(1, FUN_0021cce0(resource));
    setQuad = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
    (*setQuad)((u32*)(work + 0x1e30), 4, 0, 1, 2);
    (*setQuad)((u32*)(work + 0x1e30), 4, 0, 2, 3);

    resource = FUN_0021cca0(table0, 0x27);
    (*setState)(1, FUN_0021cce0(resource));
    (*setQuad)((u32*)(work + 0x1f30), 4, 0, 1, 2);
    (*setQuad)((u32*)(work + 0x1f30), 4, 0, 2, 3);

    resource = FUN_0021cca0(table0, 0x26);
    (*setState)(1, FUN_0021cce0(resource));
    (*setQuad)((u32*)(work + 0x2030), 4, 0, 1, 2);
    (*setQuad)((u32*)(work + 0x2030), 4, 0, 2, 3);

    if (*(u32*)(work + 0x463c) == 3 && *(s32*)(work + 0x6074) < 5) {
        resource = FUN_0021cca0(table0, 0x1d);
        (*setState)(1, FUN_0021cce0(resource));
        (*setQuad)((u32*)(work + 0x2130), 4, 0, 1, 2);
        (*setQuad)((u32*)(work + 0x2130), 4, 0, 2, 3);
    }

    resource = FUN_0021cca0(table0, 0x2c);
    (*setState)(1, FUN_0021cce0(resource));

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

    for (j = 0; j < loopCount; j++) {
        record = work + (j << 9);
        (*setQuad)((u32*)(record + 0x2230), 4, 0, 1, 2);
        (*setQuad)((u32*)(record + 0x2230), 4, 0, 2, 3);
        (*setQuad)((u32*)(record + 0x2330), 4, 0, 1, 2);
        (*setQuad)((u32*)(record + 0x2330), 4, 0, 2, 3);
    }
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

#pragma push
#pragma opt_common_subs off
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
#pragma pop

// Previous body was a wrong-helper stub unrelated to retail (1168B window).
// Rewritten from disasm: retail sets a fixed initial vtable state(9,2),
// draws a 6-slot resource strip, then 4 single quads reusing/refreshing
// the vtable casts per retail's own re-materialization points, a 4-slot
// double-quad loop, then a final 2-quad pair - all via the established
// D_00960090_abs/D_0096009C_abs style. nd 198->16 (obj 1156B/1168B);
// residual is a table0/loop-counter register-bank swap, unfixable per
// the usual declaration-order floor (2 attempts tried).
// FUN_002289B0 NONMATCHING
void FUN_002289B0(void)
{
    u8* work;
    u8* target;
    u8* base;
    u32 table0;
    u32 resource;
    u32 texture;
    s32 i;
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
        target = base + 0x3830;
        setQuadB = (void (**)(u32*, u32, u32, u32, u32))D_0096009C_abs;
        (*setQuadB)((u32*)target, 4, 0, 1, 2);
        (*setQuadB)((u32*)target, 4, 0, 2, 3);

        target = base + 0x3930;
        (*setQuadB)((u32*)target, 4, 0, 1, 2);
        (*setQuadB)((u32*)target, 4, 0, 2, 3);
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
#pragma opt_common_subs off
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
    f32 rawScaled;
    f32 blend;
    f32 weight;
    u8 alphaByte;
    s32 rawInt;
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
    rawScaled = alpha1 * alpha2;
    blend = 1.0f - rawScaled;

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
    alphaByte = (u8)(u32)(255.0f * rawScaled * weight);
    color[3] = alphaByte;
    FUN_0021d950(work + 0x4230, color);
    FUN_0021d950(work + 0x4330, color);

    percentColour = ((u8)(u32)(255.0f * rawScaled * weight) * 50 / 100) | 0xffffff00u;
    rawInt = (s32)(255.0f * rawScaled * weight);
    signedColour = (u32)rawInt | 0xffffff00u;
    greyColour = (u32)rawInt | 0xcccccc00u;

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
        color[3] = (u8)(u32)(255.0f * rawScaled * weight);
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
        alphaByte = (u8)(u32)(255.0f * rawScaled * weight);
        color[3] = alphaByte;
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
        color[3] = (u8)(u32)(255.0f * rawScaled * weight);
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

    colour = (u8)(u32)(255.0f * blend * weight) | 0xffffff00u;
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
    color[3] = (u8)(u32)(255.0f * blend * weight);
    FUN_0021d950(overlay + 0x10, color);

    rect[0] = 281.0f + basePos[0];
    rect[1] = 31.0f + basePos[1] + 77.0f;
    bpIFont00238bf0(overlay + 0x110, 3, (const char*)(size_t)*(u32*)(overlay + 0xc), 1, rect);

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    alphaByte = (u8)(u32)(255.0f * blend * weight);
    color[3] = alphaByte;
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
    color[3] = (u8)(u32)(255.0f * blend * weight);
    FUN_0021d950(overlay + 0x410, color);
}
#pragma pop

// FUN_00229B40 NONMATCHING
void FUN_00229B40(void)
{
    u8* base;
    u8* records;
    u8* record;
    u32 table0;
    u32 table6;
    u32 resource;
    u32 i;
    u32 state;
    void (*setState)(u32, u32);
    void (*setQuad)(u32*, u32, u32, u32, u32);

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    base = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    table6 = FUN_0021c3f0(6);
    records = base + 0x4660;
    resource = FUN_0021cca0(table0, 0x23);
    setState = D_00960090_fn;
    setState(1, FUN_0021cce0(resource));
    setQuad = D_0096009C_fn;
    setQuad((u32*)(base + 0x4230), 4, 0, 1, 2);
    setQuad((u32*)(base + 0x4230), 4, 0, 2, 3);
    setQuad((u32*)(base + 0x4330), 4, 0, 1, 2);
    setQuad((u32*)(base + 0x4330), 4, 0, 2, 3);
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
        setState(1, FUN_0021cce0(resource));
        if (i == *(u32*)(base + 0x6068) - *(u32*)(base + 0x606c)) {
            RpSkyRenderStateSet(3, (void*)0x71801);
            RpSkyRenderStateSet(2, (void*)0x48);
        } else {
            RpSkyRenderStateSet(3, (void*)0x717fb);
            RpSkyRenderStateSet(2, (void*)0x44);
        }
        setQuad((u32*)(record + 0x10), 4, 0, 1, 2);
        setQuad((u32*)(record + 0x10), 4, 0, 2, 3);
        setState = D_00960090_fn;
        setState(1, FUN_00239140(1));
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        setQuad((u32*)(record + 0x110), 4, 0, 1, 2);
        setQuad((u32*)(record + 0x110), 4, 0, 2, 3);
        setQuad((u32*)(record + 0x210), 4, 0, 1, 2);
        setQuad((u32*)(record + 0x210), 4, 0, 2, 3);
        setQuad((u32*)(record + 0x310), 4, 0, 1, 2);
        setQuad((u32*)(record + 0x310), 4, 0, 2, 3);
        resource = FUN_0021cca0(table6, 0x2b);
        setState(1, FUN_0021cce0(resource));
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        setQuad((u32*)(record + 0x410), 4, 0, 1, 2);
        setQuad((u32*)(record + 0x410), 4, 0, 2, 3);
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
        setState = D_00960090_fn;
        setState(1, FUN_0021cce0(resource));
        RpSkyRenderStateSet(3, (void*)0x71801);
        RpSkyRenderStateSet(2, (void*)0x48);
        setQuad = D_0096009C_fn;
        setQuad((u32*)(record + 0x10), 4, 0, 1, 2);
        setQuad((u32*)(record + 0x10), 4, 0, 2, 3);
        setState(1, FUN_00239140(1));
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        setQuad((u32*)(record + 0x110), 4, 0, 1, 2);
        setQuad((u32*)(record + 0x110), 4, 0, 2, 3);
        setQuad((u32*)(record + 0x210), 4, 0, 1, 2);
        setQuad((u32*)(record + 0x210), 4, 0, 2, 3);
        setQuad((u32*)(record + 0x310), 4, 0, 1, 2);
        setQuad((u32*)(record + 0x310), 4, 0, 2, 3);
        resource = FUN_0021cca0(table6, 0x2b);
        setState(1, FUN_0021cce0(resource));
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        setQuad((u32*)(record + 0x410), 4, 0, 1, 2);
        setQuad((u32*)(record + 0x410), 4, 0, 2, 3);
    }
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
    }
}
// Previous body was a wrong-helper stub unrelated to retail (624B window).
// Rewritten from disasm: retail loops 3 quad-setter calls, then computes a
// flag from state fields 0x463c/0x4644, gating func_003b1360 + a resource
// draw, matching FUN_0022C5A0's D_00960090_abs/D_0096009C_abs style.
// nd 89->7 (obj 612B/624B); residual is the state-1 loop's register-bank
// Fixed: swapping i and record declaration order resolved the s3/s4 register coloring.
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

// Previous body was a wrong-helper stub unrelated to retail (720B window).
// Rewritten from disasm: retail draws 3 rects (2 sharing a resource fetch)
// with a shared alpha255=255*weight computed once and reused, matching
// the doubled-alpha idiom used by the other draw functions in this file.
// obj 228B->572B/720B; residual is register caching for resourceA offset
// derefs and frame-size (retail keeps 3 s-regs live, this keeps 5).
// FUN_0022C2D0 NONMATCHING
void FUN_0022C2D0(void)
{
    u8* work;
    u32 table0;
    void* resourceA;
    f32 weight;
    f32 rect[4];
    u8 color[4];

    K_ASSERT(sBcmPanel != NULL, 0xe6);
    work = (u8*)sBcmPanel;
    table0 = FUN_0021c3f0(0);
    weight = *(f32*)(work + 0x7214);

    resourceA = (void*)FUN_0021cca0(table0, 0x42);
    rect[0] = 57.0f;
    rect[1] = (f32)0x13d;
    rect[2] = (f32)*(s32*)((u8*)resourceA + 0xc);
    rect[3] = (f32)*(s32*)((u8*)resourceA + 0x10);
    FUN_0021d8e0(work + 0x6a00, rect);

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    weight = 255.0f * weight;
    color[3] = (u8)(u32)weight;
    FUN_0021d950(work + 0x6a00, color);

    rect[0] = 57.0f + (f32)*(s32*)((u8*)resourceA + 0xc);
    rect[1] = (f32)0x13d;
    rect[2] = 133.0f;
    rect[3] = (f32)*(s32*)((u8*)resourceA + 0x10);
    FUN_0021d8e0(work + 0x6b00, rect);

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(u32)weight;
    FUN_0021d950(work + 0x6b00, color);

    resourceA = (void*)FUN_0021cca0(table0, 0x43);
    rect[0] = 400.0f;
    rect[1] = (f32)0x13d;
    rect[2] = (f32)*(s32*)((u8*)resourceA + 0xc);
    rect[3] = (f32)*(s32*)((u8*)resourceA + 0x10);
    FUN_0021d8e0(work + 0x6c00, rect);

    color[0] = 0xff;
    color[1] = 0xff;
    color[2] = 0xff;
    color[3] = (u8)(u32)weight;
    FUN_0021d950(work + 0x6c00, color);
}

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
    setColour = (void (**)(u32*, u32, u32, u32, u32))D_0096009C;
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

// FUN_0022C850
void FUN_0022c850(u32* object)
{
    K_ASSERT((object[0] & 1) != 0, 0x1b3);
    object[0] = 0;
}


// The retail routine keeps separate color paths for each animation flag.
// Preserve the bounded-index fixed colors before the interpolated paths.
// The fixed colors still pass through the source's float conversion idiom.
// This restores the missing flag-0x100 interpolation and color snapshots.
// MWCCPS2 retains a different branch layout, so the function stays pending.
// FUN_0022C8A0 NONMATCHING
void FUN_0022c8a0(u32* object_param)
{
    u8* object;
    u32 table3;
    u32 table5;
    f32 rect[4];
    u8 color[4];
    u32 color1;
    u32 color2;
    u32 color3;
    u8 colorTmp[4];
    s32 s0;
    f32 pos1X, pos1Y;
    f32 pos2X, pos2Y;
    f32 pos3X, pos3Y;
    f32 colorF;
    s32 colorI;

    object = (u8*)object_param;
    K_ASSERT((*(u32*)object & 1) != 0, 0x1cd);
    table3 = FUN_0021c3f0(3);
    table5 = FUN_0021c3f0(5);
    {
        u32 styleTable = FUN_0021c450(*(u16*)(object + 4));

    if (*(u32*)object & 0x20) {
        if (*(s32*)(object + 0x844) < 0x10) {
            *(s32*)(object + 0x844) += 1;
        } else {
            *(u32*)object &= ~0x20u;
        }
    }
    if (*(u32*)object & 0x40) {
        if (*(s32*)(object + 0x848) < 8) {
            *(s32*)(object + 0x848) += 1;
        } else {
            *(u32*)object &= ~0x40u;
        }
    } else if (*(u32*)object & 0x80) {
        if (*(s32*)(object + 0x848) < 8) {
            *(s32*)(object + 0x848) += 1;
        } else {
            *(u32*)object &= ~0x80u;
        }
    }
    if (!(*(u32*)object & 8) && (*(u32*)object & 0x100)) {
        if (*(s32*)(object + 0x84c) < 0x14) {
            *(s32*)(object + 0x84c) += 1;
        } else {
            *(u32*)object &= ~0x100u;
        }
    }

    if (*(u32*)object & 0x10) {
        if (*(u32*)object & 0x40) {
            f32 t = (f32)*(s32*)(object + 0x848) / 8.0f;
            *(f32*)(object + 0x518) = -60.0f * t + 30.0f * t * t;
        } else {
            *(f32*)(object + 0x518) = -30.0f;
        }
        *(s32*)(object + 0x51c) = 0;
    } else if (*(u32*)object & 0x80) {
        f32 t = (f32)*(s32*)(object + 0x848) / 8.0f;
        f32 f3 = t * *(f32*)(object + 0x854);
        *(f32*)(object + 0x518) = 60.0f * f3 - 30.0f * f3 * f3 - 30.0f;
        *(s32*)(object + 0x51c) = 0;
    } else {
        *(f32*)(object + 0x518) = 0.0f;
        *(s32*)(object + 0x51c) = 0;
    }

    {
        f32 f3 = *(f32*)(object + 0x850);
        f32 g = 1.0f - (2.0f * f3 - f3 * f3);
        *(f32*)(object + 0x520) = 180.0f * g;
        *(f32*)(object + 0x524) = -80.0f * g;
    }

    pos1X = *(f32*)(object + 0x520) + *(f32*)(object + 0x510) + *(f32*)(object + 0x518);
    pos1Y = *(f32*)(object + 0x524) + *(f32*)(object + 0x514) + *(f32*)(object + 0x51c);

    pos2X = 0.0f;
    pos2Y = 0.0f;
    pos3X = 0.0f;
    pos3Y = 0.0f;
    if (*(u32*)object & 0x20) {
        if (*(s32*)(object + 0x844) < 0xb) {
            f32 magA = D_0068E380[*(s32*)(object + 0x844)];
            pos2X = magA * cosf(D_007CB0D4);
            pos2Y = -magA * sinf(D_007CB0D4);
        } else {
            K_ASSERT((*(s32*)(object + 0x844) - 1) < 0x10, 0x233);
        }
        {
            f32 magB = D_0068E3BC[*(s32*)(object + 0x844)];
            pos3X = magB * cosf(D_007CB0D4);
            pos3Y = -magB * sinf(D_007CB0D4);
        }
    }
    pos2X += pos1X;
    pos2Y += pos1Y;
    pos3X += pos1X;
    pos3Y += pos1Y;

    if ((*(u32*)object & 4) && *(s32*)(object + 0x830) == 8) {
        color[0] = 0xff;
        color[1] = 0xe1;
        color[2] = 0xb9;
        color[3] = 0xff;
    } else if (*(u32*)object & 0x20) {
        if (*(s32*)(object + 0x844) < 0xb) {
            color[0] = (u8)(u32)50.0f;
            color[1] = (u8)(u32)0.0f;
            color[2] = (u8)(u32)0.0f;
            color[3] = 0xff;
        } else {
            f32 t2 = (f32)(*(s32*)(object + 0x844) - 0xa) / 6.0f;
            f32 f3 = 1.0f - t2;
            colorF = 255.0f + -205.0f * f3;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[0] = (u8)colorI;
            colorF = 255.0f + -255.0f * f3;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[1] = (u8)colorI;
            colorF = 255.0f + -255.0f * f3;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[2] = (u8)colorI;
            color[3] = 0xff;
        }
    } else if (*(u32*)object & 8) {
        color[0] = 0xff;
        color[1] = 0x8c;
        color[2] = 0x46;
        color[3] = 0xff;
    } else if (*(u32*)object & 0x100) {
        f32 t3 = (f32)*(s32*)(object + 0x84c) / 20.0f;
        f32 f3 = 1.0f - t3;
        color[0] = 0xff;
        colorF = 255.0f + -115.0f * f3;
        if (2147483648.0f <= colorF) {
            colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
        } else {
            colorI = (s32)colorF;
        }
        color[1] = (u8)colorI;
        colorF = 255.0f + -185.0f * f3;
        if (2147483648.0f <= colorF) {
            colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
        } else {
            colorI = (s32)colorF;
        }
        color[2] = (u8)colorI;
        color[3] = 0xff;
    } else {
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = 0xff;
    }
    color1 = *(u32*)color;

    if (*(u32*)object & 8) {
        color[0] = 0xff;
        color[1] = 0x8c;
        color[2] = 0x46;
        color[3] = 0xff;
    } else if ((*(u32*)object & 4) && *(s32*)(object + 0x830) == 8) {
        /* reuse color[] as computed for color1 */
    } else if (*(u32*)object & 0x20) {
        if (*(s32*)(object + 0x844) < 0xb) {
            colorF = 50.0f;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[0] = (u8)colorI;
            colorF = 0.0f;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[1] = (u8)colorI;
            colorF = 0.0f;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[2] = (u8)colorI;
            color[3] = 0xff;
        } else {
            color[0] = 0x32;
            color[1] = 0;
            color[2] = 0;
            color[3] = 0xff;
        }
    } else if (*(u32*)object & 0x100) {
        f32 t = (f32)*(s32*)(object + 0x84c) / 20.0f;
        f32 f3 = 1.0f - t;
        color[0] = 0xff;
        colorF = 255.0f + -65.0f * f3;
        if (2147483648.0f <= colorF) {
            colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
        } else {
            colorI = (s32)colorF;
        }
        color[1] = (u8)colorI;
        colorF = 255.0f + -125.0f * f3;
        if (2147483648.0f <= colorF) {
            colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
        } else {
            colorI = (s32)colorF;
        }
        color[2] = (u8)colorI;
        colorF = 255.0f * f3;
        if (2147483648.0f <= colorF) {
            colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
        } else {
            colorI = (s32)colorF;
        }
        color[3] = (u8)colorI;
    } else {
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = 0xff;
    }
    color2 = *(u32*)color;
    if (*(u32*)object & 0x20) {
        if (*(s32*)(object + 0x844) < 0xb) {
            colorF = 200.0f;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[0] = (u8)colorI;
            colorF = 0.0f;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[1] = (u8)colorI;
            colorF = 0.0f;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[2] = (u8)colorI;
            color[3] = 0xff;
        } else {
            f32 t = (f32)(*(s32*)(object + 0x844) - 0xa) / 6.0f;
            f32 f3 = 1.0f - t;
            colorF = 255.0f + -55.0f * f3;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[0] = (u8)colorI;
            colorF = 255.0f + -255.0f * f3;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[1] = (u8)colorI;
            colorF = 255.0f + -255.0f * f3;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[2] = (u8)colorI;
            colorF = 255.0f * f3;
            if (2147483648.0f <= colorF) {
                colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
            } else {
                colorI = (s32)colorF;
            }
            color[3] = (u8)colorI;
        }
    } else if (*(u32*)object & 8) {
        color[0] = 0xff;
        color[1] = 0xbe;
        color[2] = 0x82;
        color[3] = 0xff;
    } else if (*(u32*)object & 0x100) {
        f32 t = (f32)*(s32*)(object + 0x84c) / 20.0f;
        f32 f3 = 1.0f - t;
        color[0] = 0xff;
        colorF = 255.0f + -65.0f * f3;
        if (2147483648.0f <= colorF) {
            colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
        } else {
            colorI = (s32)colorF;
        }
        color[1] = (u8)colorI;
        colorF = 255.0f + -125.0f * f3;
        if (2147483648.0f <= colorF) {
            colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
        } else {
            colorI = (s32)colorF;
        }
        color[2] = (u8)colorI;
        colorF = 255.0f * f3;
        if (2147483648.0f <= colorF) {
            colorI = (s32)(colorF - 2147483648.0f) | 0x80000000;
        } else {
            colorI = (s32)colorF;
        }
        color[3] = (u8)colorI;
    } else {
        color[0] = 0xff;
        color[1] = 0xff;
        color[2] = 0xff;
        color[3] = 0xff;
    }
    color3 = *(u32*)color;
    {
        void* resource = (void*)FUN_0021cca0(styleTable, 0);
        rect[0] = 30.0f + pos2X;
        rect[1] = 15.0f + pos2Y;
        rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
        rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
        FUN_0021d8e0(object + 0x10, rect);
    }

    if (*(u32*)object & 4) {
        s32 idx = *(s32*)(object + 0x830);
        colorTmp[0] = D_0068E4B0[idx * 3 + 0];
        colorTmp[1] = D_0068E4B0[idx * 3 + 1];
        colorTmp[2] = D_0068E4B0[idx * 3 + 2];
        colorTmp[3] = 0xff;
    } else {
        colorTmp[0] = 0xff;
        colorTmp[1] = 0xff;
        colorTmp[2] = 0xff;
        colorTmp[3] = 0xff;
    }
    if (*(u32*)object & 0x200) {
        colorTmp[3] = (u8)(colorTmp[3] * 80 / 100);
    }
    FUN_0021d950(object + 0x10, colorTmp);

    {
        void* resource = (void*)FUN_0021cca0(styleTable, 1);
        rect[0] = pos2X;
        rect[1] = pos2Y;
        rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
        rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
        FUN_0021d8e0(object + 0x110, rect);
        FUN_0021d8e0(object + 0x210, rect);
        rect[0] = 30.0f + pos3X;
        rect[1] = 15.0f + pos3Y;
        rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
        rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
        FUN_0021d8e0(object + 0x310, rect);
        FUN_0021d8e0(object + 0x410, rect);
    }
    }

    FUN_0021d950(object + 0x110, (u8*)&color1);
    FUN_0021d950(object + 0x310, (u8*)&color2);
    FUN_0021d950(object + 0x210, (u8*)&color3);
    FUN_0021d950(object + 0x410, (u8*)&color3);


    rect[0] = 102.0f + pos1X + 2.0f;
    rect[1] = 72.0f + pos1Y;
    FUN_0022eb30((u32*)(object + 0x860), *(u32*)(object + 0x834), (u32)(size_t)rect);

    if ((*(u32*)object & 4) && *(s32*)(object + 0x830) == 8) {
        colorTmp[0] = 0x78;
        colorTmp[1] = 0x78;
        colorTmp[2] = 0x78;
        colorTmp[3] = 0xff;
    } else {
        colorTmp[0] = 0xff;
        colorTmp[1] = 0xff;
        colorTmp[2] = 0xff;
        colorTmp[3] = 0xff;
    }
    {
        s32 j;
        for (j = 0; j < 3; ++j) {
            FUN_0021d950(object + j * 0x100 + 0x860, colorTmp);
        }
    }

    rect[0] = pos3X;
    rect[1] = 22.0f + pos3Y;
    FUN_0022eb30((u32*)(object + 0xb60), *(u32*)(object + 0x83c), (u32)(size_t)rect);

    if ((*(u32*)object & 4) && *(s32*)(object + 0x830) == 8) {
        colorTmp[0] = 0x78;
        colorTmp[1] = 0x78;
        colorTmp[2] = 0x78;
        colorTmp[3] = 0xff;
    } else {
        colorTmp[0] = 0xff;
        colorTmp[1] = 0xff;
        colorTmp[2] = 0xff;
        colorTmp[3] = 0xff;
    }
    {
        s32 j;
        for (j = 0; j < 3; ++j) {
            FUN_0021d950(object + j * 0x100 + 0xb60, colorTmp);
        }
    }

    {
        void* resource = (void*)FUN_0021cca0(table5, 2);
        rect[0] = 65.0f + pos1X;
        rect[1] = 83.0f + pos1Y;
        rect[2] = (f32)((*(s32*)((u8*)resource + 0xc) * *(s32*)(object + 0x834)) /
                         *(s32*)(object + 0x838));
        rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
        FUN_0021d8e0(object + 0xe60, rect);
    }

    {
        void* resource = (void*)FUN_0021cca0(table5, 3);
        rect[0] = pos1X;
        rect[1] = 89.0f + pos1Y;
        rect[2] = (f32)((*(s32*)((u8*)resource + 0xc) * *(s32*)(object + 0x83c)) /
                         *(s32*)(object + 0x840));
        rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
        FUN_0021d8e0(object + 0xf60, rect);
    }

    if ((*(u32*)object & 4) && *(s32*)(object + 0x830) == 8) {
        colorTmp[0] = 0xd7;
        colorTmp[1] = 0xff;
        colorTmp[2] = 0x91;
        colorTmp[3] = 0xff;
    } else {
        colorTmp[0] = 0xff;
        colorTmp[1] = 0xff;
        colorTmp[2] = 0xff;
        colorTmp[3] = 0xff;
    }
    FUN_0021d950(object + 0xf60, colorTmp);

    if (*(u32*)object & 2) {
        u32 resourceId = FUN_0022e850(*(u32*)(object + 0x528));
        {
            void* resource = (void*)FUN_0021cca0(table3, resourceId);
            rect[0] = 116.0f + pos1X;
            rect[1] = 43.0f + pos1Y;
            rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
            rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
            FUN_0021d8e0(object + 0x530, rect);
        }

        s0 = 0;
        if ((*(u32*)object & 4) && *(s32*)(object + 0x830) == 8) {
            if (*(s32*)(object + 0x528) < 6) {
                switch (*(s32*)(object + 0x528)) {
                case 0:
                    K_ASSERT(0, 0x369);
                    s0 = 0;
                    break;
                case 1:
                    s0 = 0;
                    break;
                case 2:
                    s0 = 1;
                    break;
                case 3:
                    s0 = 2;
                    break;
                case 4:
                    s0 = 3;
                    break;
                case 5:
                    s0 = 4;
                    break;
                }
            }
            colorTmp[0] = D_0068E4D8[s0 * 3 + 0];
            colorTmp[1] = D_0068E4D8[s0 * 3 + 1];
            colorTmp[2] = D_0068E4D8[s0 * 3 + 2];
            colorTmp[3] = 0xff;
        } else {
            colorTmp[0] = 0xff;
            colorTmp[1] = 0xff;
            colorTmp[2] = 0xff;
            colorTmp[3] = 0xff;
        }
        FUN_0021d950(object + 0x530, colorTmp);
    }
    {
        void* resource = (void*)FUN_0021cca0(table3, 0xa);
        rect[0] = 60.0f + pos1X;
        rect[1] = 79.0f + pos1Y;
        rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
        rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
        FUN_0021d8e0(object + 0x630, rect);
        FUN_0021d8e0(object + 0x730, rect);
    }
    FUN_0021d950(object + 0x630, (u8*)&color1);
    FUN_0021d950(object + 0x730, (u8*)&color3);

    if (*(u32*)object & 4) {
        FUN_0022fa80((u32*)object);
    }
}

// FUN_0022DF10 NONMATCHING
void FUN_0022df10(u32* object)
{
    void (*setState)(u32, u32);
    void (*setQuad)(u32*, u32, u32, u32, u32);
    u32 table3;
    u32 table5;
    u32 text;
    u32 resource;

    K_ASSERT((object[0] & 1) != 0, 0x390);
    table3 = FUN_0021c3f0(3);
    table5 = FUN_0021c3f0(5);
    text = FUN_0021c450(*(u16*)((u8*)object + 4));
    setState = (void (*)(u32, u32))D_00960090;
    setQuad = (void (*)(u32*, u32, u32, u32, u32))D_0096009C;
    setState(0x14, 2);
    setState(8, 0);
    setState(6, 0);
    setState(1, FUN_0021cce0(FUN_0021cca0(text, 1)));

    if ((object[0] & 0x20) != 0) {
        RpSkyRenderStateSet(3, (void*)0x717fb);
        RpSkyRenderStateSet(2, (void*)0x44);
        setQuad((u32*)((u8*)object + 0x310), 4, 0, 1, 2);
        setQuad((u32*)((u8*)object + 0x310), 4, 0, 2, 3);

        if (!((object[0] & 4) != 0 && object[0x20c] == 8)) {
            RpSkyRenderStateSet(3, (void*)0x717fb);
            RpSkyRenderStateSet(2, (void*)0x44);
            setQuad((u32*)((u8*)object + 0x410), 4, 0, 1, 2);
            setQuad((u32*)((u8*)object + 0x410), 4, 0, 2, 3);
        }
    }
    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    setQuad((u32*)((u8*)object + 0x110), 4, 0, 1, 2);
    setQuad((u32*)((u8*)object + 0x110), 4, 0, 2, 3);

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
    setQuad((u32*)((u8*)object + 0x210), 4, 0, 1, 2);
    setQuad((u32*)((u8*)object + 0x210), 4, 0, 2, 3);
skip210:

    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    setState(1, FUN_0021cce0(FUN_0021cca0(text, 0)));
    setQuad((u32*)((u8*)object + 0x10), 4, 0, 1, 2);
    setQuad((u32*)((u8*)object + 0x10), 4, 0, 2, 3);

    resource = FUN_0021cca0(table3, 0xa);
    setState(1, FUN_0021cce0(resource));
    setQuad((u32*)((u8*)object + 0x630), 4, 0, 1, 2);
    setQuad((u32*)((u8*)object + 0x630), 4, 0, 2, 3);

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
    setQuad((u32*)((u8*)object + 0x730), 4, 0, 1, 2);
    setQuad((u32*)((u8*)object + 0x730), 4, 0, 2, 3);
skip730:

    RpSkyRenderStateSet(3, (void*)0x717fb);
    RpSkyRenderStateSet(2, (void*)0x44);
    resource = FUN_0021cca0(table3, 0);
    setState(1, FUN_0021cce0(resource));
    setQuad((u32*)((u8*)object + 0x860), 4, 0, 1, 2);
    setQuad((u32*)((u8*)object + 0x860), 4, 0, 2, 3);
    setQuad((u32*)((u8*)object + 0x960), 4, 0, 1, 2);
    setQuad((u32*)((u8*)object + 0x960), 4, 0, 2, 3);
    setQuad((u32*)((u8*)object + 0xa60), 4, 0, 1, 2);
    setQuad((u32*)((u8*)object + 0xa60), 4, 0, 2, 3);
    setQuad((u32*)((u8*)object + 0xb60), 4, 0, 1, 2);
    setQuad((u32*)((u8*)object + 0xb60), 4, 0, 2, 3);
    setQuad((u32*)((u8*)object + 0xc60), 4, 0, 1, 2);
    setQuad((u32*)((u8*)object + 0xc60), 4, 0, 2, 3);
    setQuad((u32*)((u8*)object + 0xd60), 4, 0, 1, 2);
    setQuad((u32*)((u8*)object + 0xd60), 4, 0, 2, 3);

    resource = FUN_0021cca0(table5, 2);
    setState(1, FUN_0021cce0(resource));
    setQuad((u32*)((u8*)object + 0xe60), 4, 0, 1, 2);
    setQuad((u32*)((u8*)object + 0xe60), 4, 0, 2, 3);

    resource = FUN_0021cca0(table5, 3);
    setState(1, FUN_0021cce0(resource));
    setQuad((u32*)((u8*)object + 0xf60), 4, 0, 1, 2);
    setQuad((u32*)((u8*)object + 0xf60), 4, 0, 2, 3);

    if ((object[0] & 2) != 0) {
        resource = FUN_0021cca0(table3, FUN_0022e850(object[0x14a]));
        setState(1, FUN_0021cce0(resource));
        setQuad((u32*)((u8*)object + 0x530), 4, 0, 1, 2);
        setQuad((u32*)((u8*)object + 0x530), 4, 0, 2, 3);
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

// FUN_0022EB30
void FUN_0022eb30(u32* object, u32 value, u32 colour)
{
    f32 rect[4];
    char text[0x100];
    u32 table;
    s32 i;
    s32 length;

    table = FUN_0021c3f0(3);
    sprintf(text, "%d", value);
    length = strlen(text);
    if (length > 3) {
        K_Assert("bpp_panel.c", 0x471);
    }
    for (i = 0; i < length; ++i) {
        u32 resource;

        resource = FUN_0021cca0(table, text[length - 1 - i] - '0');
        rect[0] = *(f32*)colour + (f32)((2 - i) * 16);
        rect[1] = *(f32*)(colour + 4);
        rect[2] = (f32)*(s32*)((u8*)resource + 0xc);
        rect[3] = (f32)*(s32*)((u8*)resource + 0x10);
        FUN_0021d8e0((u8*)object + i * 0x100, rect);
    }
    for (; length < 3; ++length) {
        rect[0] = *(f32*)colour;
        rect[1] = *(f32*)(colour + 4);
        rect[2] = 0.0f;
        rect[3] = 0.0f;
        FUN_0021d8e0((u8*)object + length * 0x100, rect);
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

// Partially reconstructed. Retail dispatches on the state at byte 0x830
// (object[0x20c]) through an 11-entry jump table at 0x7b77e0, decoded from the
// retail ELF as [0x22fb44, 0x230078, 0x2305e4, 0x230bf0, 0x231108, 0x2316d8,
// 0x231c7c, 0x2328a4, 0x232d70, 0x232dd8, 0x231108] - ten distinct bodies with
// cases 4 and 10 sharing one. Each case opens by bumping its own animation
// counter or fetching its own panel resource; those verified openings are
// implemented here. The case bodies themselves (panel layout, sinf/cosf corner
// rotation, alpha threshold chains) are still unrecovered and are the bulk of
// the 13344-byte window.
// FUN_0022FA80 NONMATCHING
void FUN_0022fa80(u32* object)
{
    u8* bytes;
    u32 i;
    u32 table;
    u32 state;
    f32 offset_x;
    f32 offset_y;
    f32 rect_work[12];

    bytes = (u8*)object;
    offset_x = *(f32*)(bytes + 0x510) + *(f32*)(bytes + 0x518) + *(f32*)(bytes + 0x520);
    offset_y = *(f32*)(bytes + 0x514) + *(f32*)(bytes + 0x51c) + *(f32*)(bytes + 0x524);
    table = FUN_0021c3f0(4);
    state = object[0x20c];
    switch (state) {
    case 0:
    {
        u8* base;
        u8 colour[4];
        u32 resource;

        base = bytes + 0x1060;
        *(u32*)(bytes + 0x136c) = *(u32*)(bytes + 0x136c) + 1;

        // Initialize 3 slot counters
        for (i = 0; i < 3; i++) {
            u32 val = *(u32*)(base + 0x30c) + i * 10;
            *(u32*)(base + i * 4 + 0x300) = val % 30;
        }

        // Alpha threshold chain for 3 slots
        colour[0] = 0xFF;
        colour[1] = 0xFF;
        colour[2] = 0xFF;
        colour[3] = 0xFF;
        for (i = 0; i < 3; i++) {
            f32 val = (f32)*(u32*)(base + i * 4 + 0x300);
            f32 t = val / 30.0f;
            f32 alpha;

            if (t <= 0.6f) {
                alpha = t / 0.6f;
                if (alpha > 1.0f) {
                    alpha = 1.0f;
                }
            } else if (t <= 0.7f) {
                alpha = 1.0f;
            } else {
                alpha = (1.0f - t) / (1.0f - 0.7f);
            }

            if (alpha < 0.0f) {
                alpha = 0.0f;
            }
            colour[3] = (u8)(s32)(alpha * 255.0f);
            FUN_0021d950(base + i * 256, colour);
        }

        // Corner rotation and draw
        resource = FUN_0021cca0(table, 0);
        {
            f32 pos_x = 66.0f + offset_x;
            f32 pos_y = 11.0f + offset_y;
            for (i = 0; i < 3; i++) {
                f32 t = (f32)*(u32*)(base + i * 4 + 0x300);
                f32 angle;
                f32 s, c;
                f32 x0, y0, x1, y1, x2, y2, x3, y3;
                f32 w, h;

                t = t / 30.0f;
                angle = (1.0f - t) * 3.14159265f;
                s = sinf(angle);
                c = cosf(angle);

                x0 = D_0068E4F0[i * 4 + 0];
                y0 = D_0068E4F0[i * 4 + 1];
                x1 = D_0068E4F0[i * 4 + 2];
                y1 = D_0068E4F0[i * 4 + 3];
                x2 = D_0068E4F0[i * 4 + 2];
                y2 = D_0068E4F0[i * 4 + 3];
                x3 = D_0068E4F0[i * 4 + 0];
                y3 = D_0068E4F0[i * 4 + 1];

                rect_work[0] = pos_x + x0 * c - y0 * s;
                rect_work[1] = pos_y + x0 * s + y0 * c;
                rect_work[2] = pos_x + x1 * c - y1 * s;
                rect_work[3] = pos_y + x1 * s + y1 * c;
                rect_work[4] = pos_x + x2 * c - y2 * s;
                rect_work[5] = pos_y + x2 * s + y2 * c;
                rect_work[6] = pos_x + x3 * c - y3 * s;
                rect_work[7] = pos_y + x3 * s + y3 * c;

                w = (f32)((u32*)resource)[3];
                h = (f32)((u32*)resource)[4];
                rect_work[8] = 255.0f * x1;
                rect_work[9] = 255.0f * y1;
                rect_work[10] = 255.0f * x0;
                rect_work[11] = 255.0f * y0;

                FUN_0021e170(base + i * 256, rect_work, rect_work + 4, rect_work + 8);
            }
        }
        break;
    }
    case 1:
    {
        u8* base;
        u32 resource;
        u32 s3, s4;
        u8 colour[4];

        base = bytes + 0x1060;
        *(u32*)(bytes + 0x166c) = *(u32*)(bytes + 0x166c) + 1;

        // First loop: process 3 slots (counter at base + t0*4 + 0x600)
        for (i = 0; i < 3; i++) {
            u32 cnt = *(u32*)(base + i * 4 + 0x600) + 1;
            *(u32*)(base + i * 4 + 0x600) = cnt % 10;
        }

        colour[0] = 0xFF;
        colour[1] = 0xFF;
        colour[2] = 0xFF;
        colour[3] = 0xFF;

        // Alpha write for 3 slots with 2 sub-slots each
        for (s3 = 0; s3 < 3; s3++) {
            for (s4 = 0; s4 < 2; s4++) {
                f32 cnt_f = (f32)*(u32*)(base + s3 * 4 + 0x600);
                f32 t = cnt_f / 10.0f;
                f32 alpha;

                if (t <= 0.6f) {
                    alpha = t / 0.6f;
                } else if (t <= 0.7f) {
                    alpha = 1.0f;
                } else {
                    alpha = (1.0f - t) / (1.0f - 0.7f);
                }
                if (alpha < 0.0f) {
                    alpha = 0.0f;
                }
                if (s4 == 1) {
                    alpha = alpha * 15.0f / 100.0f;
                }
                colour[3] = (u8)(s32)(alpha * 255.0f);
                FUN_0021d950(base + (s3 * 2 + s4) * 256, colour);
            }
        }

        // Draw phase with rotation for 3 slots
        {
            f32 pos_x = 66.0f + offset_x;
            f32 pos_y = 11.0f + offset_y;
            resource = FUN_0021cca0(table, 1);
            for (s3 = 0; s3 < 3; s3++) {
                f32 rect0[4], rect1[4], rect2[4];
                f32 t, angle, s, c;
                f32 x0, y0, x1, y1, x2, y2, x3, y3;
                f32 w, h;

                w = (f32)((u32*)resource)[3];
                h = (f32)((u32*)resource)[4];

                t = (f32)*(u32*)(base + s3 * 4 + 0x600);
                t = (t + 1.0f) / 10.0f;
                angle = (1.0f - t) * 3.14159265f;
                s = sinf(angle);
                c = cosf(angle);

                x0 = D_0068E490[s3 * 4 + 0];
                y0 = D_0068E490[s3 * 4 + 1];
                x1 = D_0068E490[s3 * 4 + 2];
                y1 = D_0068E490[s3 * 4 + 3];
                x2 = x1;
                y2 = y1;
                x3 = x0;
                y3 = y0;

                rect0[0] = pos_x + x0 * c - y0 * s;
                rect0[1] = pos_y + x0 * s + y0 * c;
                rect0[2] = pos_x + x1 * c - y1 * s;
                rect0[3] = pos_y + x1 * s + y1 * c;
                rect1[0] = pos_x + x2 * c - y2 * s;
                rect1[1] = pos_y + x2 * s + y2 * c;
                rect1[2] = pos_x + x3 * c - y3 * s;
                rect1[3] = pos_y + x3 * s + y3 * c;
                rect2[0] = 255.0f * x1;
                rect2[1] = 255.0f * y1;
                rect2[2] = 255.0f * x0;
                rect2[3] = 255.0f * y0;

                FUN_0021e170(base + s3 * 512, rect0, rect1, rect2);
            }
        }

        // Second draw phase
        {
            f32 pos_x = 66.0f + offset_x;
            f32 pos_y = 11.0f + offset_y;
            resource = FUN_0021cca0(table, 2);
            for (s3 = 0; s3 < 3; s3++) {
                f32 rect0[4], rect1[4], rect2[4];
                f32 t, angle, s, c;
                f32 x0, y0, x1, y1, x2, y2, x3, y3;
                f32 w, h;

                w = (f32)((u32*)resource)[3];
                h = (f32)((u32*)resource)[4];

                t = (f32)*(u32*)(base + s3 * 4 + 0x600);
                t = (t + 1.0f) / 10.0f;
                angle = (1.0f - t) * 3.14159265f;
                s = sinf(angle);
                c = cosf(angle);

                x0 = D_0068E460[s3 * 4 + 0];
                y0 = D_0068E460[s3 * 4 + 1];
                x1 = D_0068E460[s3 * 4 + 2];
                y1 = D_0068E460[s3 * 4 + 3];
                x2 = x1;
                y2 = y1;
                x3 = x0;
                y3 = y0;

                rect0[0] = pos_x + x0 * c - y0 * s;
                rect0[1] = pos_y + x0 * s + y0 * c;
                rect0[2] = pos_x + x1 * c - y1 * s;
                rect0[3] = pos_y + x1 * s + y1 * c;
                rect1[0] = pos_x + x2 * c - y2 * s;
                rect1[1] = pos_y + x2 * s + y2 * c;
                rect1[2] = pos_x + x3 * c - y3 * s;
                rect1[3] = pos_y + x3 * s + y3 * c;
                rect2[0] = 255.0f * x1;
                rect2[1] = 255.0f * y1;
                rect2[2] = 255.0f * x0;
                rect2[3] = 255.0f * y0;

                FUN_0021e170(base + s3 * 512 + 256, rect0, rect1, rect2);
            }
        }
        break;
    }
    case 2:
    {
        u8* base;
        u8 colour[4];
        u32 resource;
        u32 i;

        base = bytes + 0x1060;
        *(u32*)(bytes + 0x1374) = *(u32*)(bytes + 0x1374) + 1;

        // Initialize 3 slot counters (same pattern as case 0)
        for (i = 0; i < 3; i++) {
            u32 val = *(u32*)(base + 0x30c) + i * 10;
            *(u32*)(base + i * 4 + 0x300) = val % 30;
        }

        // Alpha threshold chain for 3 slots
        colour[0] = 0xFF;
        colour[1] = 0xFF;
        colour[2] = 0xFF;
        colour[3] = 0xFF;
        for (i = 0; i < 3; i++) {
            f32 val = (f32)*(u32*)(base + i * 4 + 0x300);
            f32 t = val / 30.0f;
            f32 alpha;

            if (t <= 0.6f) {
                alpha = t / 0.6f;
                if (alpha > 1.0f) {
                    alpha = 1.0f;
                }
            } else if (t <= 0.7f) {
                alpha = 1.0f;
            } else {
                alpha = (1.0f - t) / (1.0f - 0.7f);
            }
            if (alpha < 0.0f) {
                alpha = 0.0f;
            }
            colour[3] = (u8)(s32)(alpha * 255.0f);
            FUN_0021d950(base + i * 256, colour);
        }

        // Corner rotation and draw
        resource = FUN_0021cca0(table, 0);
        {
            f32 pos_x = 66.0f + offset_x;
            f32 pos_y = 11.0f + offset_y;
            for (i = 0; i < 3; i++) {
                f32 rect0[4], rect1[4], rect2[4];
                f32 t, angle, s, c;
                f32 x0, y0, x1, y1, x2, y2, x3, y3;
                f32 w, h;

                t = (f32)*(u32*)(base + i * 4 + 0x300);
                t = t / 30.0f;
                angle = (1.0f - t) * 3.14159265f;
                s = sinf(angle);
                c = cosf(angle);

                x0 = D_0068E4F0[i * 4 + 0];
                y0 = D_0068E4F0[i * 4 + 1];
                x1 = D_0068E4F0[i * 4 + 2];
                y1 = D_0068E4F0[i * 4 + 3];
                x2 = D_0068E4F0[i * 4 + 2];
                y2 = D_0068E4F0[i * 4 + 3];
                x3 = D_0068E4F0[i * 4 + 0];
                y3 = D_0068E4F0[i * 4 + 1];

                rect0[0] = pos_x + x0 * c - y0 * s;
                rect0[1] = pos_y + x0 * s + y0 * c;
                rect0[2] = pos_x + x1 * c - y1 * s;
                rect0[3] = pos_y + x1 * s + y1 * c;
                rect1[0] = pos_x + x2 * c - y2 * s;
                rect1[1] = pos_y + x2 * s + y2 * c;
                rect1[2] = pos_x + x3 * c - y3 * s;
                rect1[3] = pos_y + x3 * s + y3 * c;

                w = (f32)((u32*)resource)[3];
                h = (f32)((u32*)resource)[4];
                rect2[0] = 255.0f * x1;
                rect2[1] = 255.0f * y1;
                rect2[2] = 255.0f * x0;
                rect2[3] = 255.0f * y0;

                FUN_0021e170(base + i * 256, rect0, rect1, rect2);
            }
        }
        break;
    }
    case 3:
    {
        u8* base = bytes + 0x1060;
        u32 resource;
        u32 i;
        u32 j;
        f32 pos_x0, pos_y0;
        f32 pos_x1, pos_y1;
        f32 size_w, size_h;
        u8 colour[4];

        resource = FUN_0021cca0(table, 8);
        *(u32*)(bytes + 0x126c) = *(u32*)(bytes + 0x126c) + 1;

        // First loop: initialize 2 slots with counters at base + i*4 + 0x200
        for (i = 0; i < 2; i++) {
            u32 cnt = *(u32*)(base + i * 4 + 0x200) + 1;
            *(u32*)(base + i * 4 + 0x200) = cnt;
            if (cnt >= 30) {
                *(base + i + 0x208) = (u8)RpRandom();
                cnt = cnt % 30;
                *(u32*)(base + i * 4 + 0x200) = cnt;
            }
        }

        // Position constants
        pos_x0 = 80.0f + offset_x;  // f22
        pos_y0 = 15.0f + offset_y;  // f21
        pos_x1 = 40.0f + offset_x;  // f20
        pos_y1 = 10.0f + offset_y;  // f31

        // Outer loop: two slots
        for (i = 0; i < 2; i++) {
            f32 rect[8]; // 4 corners x,y pairs at [0..7]
            f32 cnt_f;
            f32 t;
            f32 scale_x, scale_y;
            f32 cx, cy;
            f32 f26, f25;
            f32 angle;
            f32 s, c;
            f32 tmp;

            cnt_f = (f32)*(u32*)(base + i * 4 + 0x200);
            t = cnt_f / 30.0f;

            if (i == 0) {
                rect[0] = pos_x0; rect[1] = pos_y0;
                f26 = pos_x0;
                f25 = pos_y0 + (f32)((u32*)resource)[4];
            } else {
                rect[0] = pos_x1; rect[1] = pos_y1;
                f26 = pos_x1 + (f32)((u32*)resource)[3];
                f25 = pos_y1 + (f32)((u32*)resource)[4];
            }
            size_w = (f32)((u32*)resource)[3];
            size_h = (f32)((u32*)resource)[4];
            rect[2] = rect[0] + size_w; rect[3] = rect[1];
            rect[4] = rect[2]; rect[5] = rect[1] + size_h;
            rect[6] = rect[0]; rect[7] = rect[5];

            // Make relative to (f26, f25)
            cx = f26;
            cy = f25;
            for (j = 0; j < 4; j++) {
                rect[j * 2 + 0] -= cx;
                rect[j * 2 + 1] -= cy;
            }

            // Scale
            if (i == 0) {
                scale_x = cnt_f + cnt_f * t * 0.5f;
                scale_y = scale_x;
            } else {
                scale_x = cnt_f + cnt_f * t * 0.25f;
                scale_y = scale_x;
            }
            for (j = 0; j < 4; j++) {
                rect[j * 2 + 0] *= scale_x;
                rect[j * 2 + 1] *= scale_y;
            }

            // Rotation angle from random byte
            {
                f32 rand_f = (f32)(s32)(s8)*(base + i + 0x208);
                angle = rand_f * 40.0f / 256.0f / 360.0f;
                angle = angle * 2.0f * 3.14159265f;
            }

            // Rotate 4 corners
            s = sinf(angle);
            c = cosf(angle);
            for (j = 0; j < 4; j++) {
                f32 x = rect[j * 2 + 0];
                f32 y = rect[j * 2 + 1];
                rect[j * 2 + 0] = x * c - y * s;
                rect[j * 2 + 1] = x * s + y * c;
            }

            // Add back (cx, cy)
            for (j = 0; j < 4; j++) {
                rect[j * 2 + 0] += cx;
                rect[j * 2 + 1] += cy;
            }

            // Draw rect
            FUN_0021d890(base + i * 256, rect);

            // Alpha computation based on counter
            {
                f32 alpha;
                if (cnt_f < 7.0f) {
                    alpha = cnt_f / 7.0f;
                } else if (cnt_f < 20.0f) {
                    alpha = 1.0f;
                } else {
                    alpha = 1.0f - (cnt_f - 20.0f) / 10.0f;
                }
                colour[0] = 0xFF;
                colour[1] = 0xFF;
                colour[2] = 0xFF;
                colour[3] = (u8)(s32)(alpha * 255.0f);
                FUN_0021d950(base + i * 256, colour);
            }
        }
        break;
    }
    case 4:
    case 10:
    {
        u8* base;
        u32 i;
        u8 colour[4];
        u32 resource;

        base = bytes + 0x1060;
        *(u32*)(bytes + 0x126c) = *(u32*)(bytes + 0x126c) + 1;

        // 2-slot resource assignment
        for (i = 0; i < 2; i++) {
            u32 cnt = *(u32*)(base + i * 4 + 0x200) + 1;
            *(u32*)(base + i * 4 + 0x200) = cnt;
            if (cnt >= 12) {
                u32 rtype;
                u32 flag;
                u32 inner;

                flag = RpRandom() & 1;
                *(base + i + 0x208) = (u8)flag;
                rtype = RpRandom() % 3;

                // Collision avoidance: ensure unique type among slots
                for (inner = 0; inner < 2; inner++) {
                    if (inner == i) continue;
                    if (*(base + inner + 0x20a) == rtype) {
                        rtype++;
                        inner = 0xFFFFFFFF; // restart search
                        continue;
                    }
                }

                *(base + i + 0x20a) = (u8)rtype;
                if (flag == 1) {
                    resource = FUN_0021cca0(table, 9);
                    FUN_0021d3b0(base + i * 256, (u8*)(uintptr_t)resource);
                } else if (flag == 0) {
                    resource = FUN_0021cca0(table, 10);
                    FUN_0021d3b0(base + i * 256, (u8*)(uintptr_t)resource);
                }

                cnt = cnt % 12;
                *(u32*)(base + i * 4 + 0x200) = cnt;
            }
        }

        // Color setup
        if (object[0x20c] == 4) {
            colour[0] = 0xFF; colour[1] = 0xFF;
            colour[2] = 0xFF; colour[3] = 0xFF;
        } else {
            colour[0] = 120; colour[1] = 30;
            colour[2] = 30;  colour[3] = 0xFF;
        }

        // Draw loop with alpha
        {
            f32 pos_x = 66.0f + offset_x;
            f32 pos_y = 11.0f + offset_y;
            for (i = 0; i < 2; i++) {
                f32 val = (f32)*(u32*)(base + i * 4 + 0x200);
                f32 t = val / 12.0f;
                f32 alpha;

                if (t <= 0.6f) {
                    alpha = t / 0.6f;
                    if (alpha > 1.0f) alpha = 1.0f;
                } else if (t <= 0.7f) {
                    alpha = 1.0f;
                } else {
                    alpha = (1.0f - t) / (1.0f - 0.7f);
                }
                if (alpha < 0.0f) alpha = 0.0f;
                colour[3] = (u8)(s32)(alpha * 255.0f);
                FUN_0021d950(base + i * 256, colour);
            }
        }
        break;
    }
    case 5:
    {
        u8* base;
        u32 i;
        u8 colour[4];
        u32 resource;
        u32 slot_resource;
        f32 rect[4];

        base = bytes + 0x1060;
        *(u32*)(bytes + 0x1570) = *(u32*)(bytes + 0x1570) + 1;

        // Initial resource and rect draw
        resource = FUN_0021cca0(table, 11);
        rect[0] = 80.0f + offset_x;
        rect[1] = 19.0f + offset_y;
        rect[2] = (f32)((u32*)resource)[3];
        rect[3] = (f32)((u32*)resource)[4];
        FUN_0021d8e0(base, rect);
        FUN_0021d8e0(base + 256, rect);

        // Pre-fetch resource for slot copies
        slot_resource = FUN_0021cca0(table, 12);

        // 3-slot resource assignment
        for (i = 0; i < 3; i++) {
            u32 cnt = *(u32*)(base + i * 4 + 0x500) + 1;
            *(u32*)(base + i * 4 + 0x500) = cnt;
            if (cnt >= 40) {
                u32 rtype;
                u32 inner;

                rtype = RpRandom() % 6;

                // Collision avoidance
                for (inner = 0; inner < 3; inner++) {
                    if (inner == i) continue;
                    if (*(base + inner + 0x50c) == rtype) {
                        rtype++;
                        inner = 0xFFFFFFFF;
                        continue;
                    }
                }

                *(base + i + 0x50c) = (u8)rtype;

                FUN_0021d3b0(base + i * 256 + 0x200, (u8*)(uintptr_t)slot_resource);

                cnt = cnt % 40;
                *(u32*)(base + i * 4 + 0x500) = cnt;
            }
        }

        // Colour write with alpha computation
        colour[0] = 0xFF; colour[1] = 0xFF;
        colour[2] = 0xFF; colour[3] = 0xFF;
        for (i = 0; i < 3; i++) {
            f32 val = (f32)*(u32*)(base + i * 4 + 0x500);
            f32 t = val / 40.0f;
            f32 alpha;

            if (t <= 0.6f) {
                alpha = t / 0.6f;
                if (alpha > 1.0f) alpha = 1.0f;
            } else if (t <= 0.7f) {
                alpha = 1.0f;
            } else {
                alpha = (1.0f - t) / (1.0f - 0.7f);
            }
            if (alpha < 0.0f) alpha = 0.0f;
            colour[3] = (u8)(s32)(alpha * 255.0f);
            FUN_0021d950(base + i * 256, colour);
        }
        break;
    }
    case 6:
    {
        u8* base;
        u32 resource;
        u32 i;
        u8 colour[4];
        f32 counter_f;
        f32 pos_x, pos_y;
        f32 rect[8];
        f32 cx, cy;
        f32 angle;
        f32 s0, c0;
        f32 t_val;
        f32 size_w, size_h;
        f32 alpha;

        base = bytes + 0x1060;
        *(u32*)(bytes + 0x1360) = *(u32*)(bytes + 0x1360) + 1;
        *(u32*)(bytes + 0x1360) = *(u32*)(bytes + 0x1360) % 20;
        counter_f = (f32)*(u32*)(bytes + 0x1360);

        resource = FUN_0021cca0(table, 13);
        size_w = (f32)((u32*)resource)[3];
        size_h = (f32)((u32*)resource)[4];

        // -- Slot 0 position --
        if ((u32)counter_f < 2) {
            pos_x = 80.0f + 5.0f + offset_x;
            pos_y = 6.0f + offset_y;
        } else if ((u32)counter_f < 12) {
            pos_x = 80.0f + offset_x;
            pos_y = 13.0f + offset_y;
        } else {
            pos_x = 80.0f + offset_x;
            pos_y = 13.0f + offset_y;
        }

        rect[0] = pos_x; rect[1] = pos_y;
        rect[2] = pos_x + size_w; rect[3] = pos_y;
        rect[4] = pos_x + size_w; rect[5] = pos_y + size_h;
        rect[6] = pos_x; rect[7] = pos_y + size_h;

        cx = (rect[0] + rect[2]) * 0.5f;
        cy = (rect[1] + rect[5]) * 0.5f;
        for (i = 0; i < 4; i++) {
            rect[i * 2 + 0] -= cx;
            rect[i * 2 + 1] -= cy;
        }

        // Angle from counter
        if ((u32)counter_f < 2) {
            t_val = 0.0f;
        } else if ((u32)counter_f < 12) {
            t_val = (f32)((u32)counter_f - 2) / 10.0f;
        } else if ((u32)counter_f < 18) {
            t_val = 1.0f;
        } else {
            t_val = 1.0f - (f32)((u32)counter_f - 18) / 2.0f;
        }

        angle = (1.0f - t_val) * 3.14159265f;

        // Corner pair 0-1
        s0 = sinf(angle);
        c0 = cosf(angle);
        {
            f32 x0 = rect[0] * c0 - rect[1] * s0;
            f32 y0 = rect[0] * s0 + rect[1] * c0;
            f32 x1 = rect[2] * c0 - rect[3] * s0;
            f32 y1 = rect[2] * s0 + rect[3] * c0;
            rect[0] = x0; rect[1] = y0;
            rect[2] = x1; rect[3] = y1;
        }

        // Corner pair 2-3
        s0 = sinf(angle);
        c0 = cosf(angle);
        // Corner pair 2-3
        {
            f32 x2 = rect[4] * c0 - rect[5] * s0;
            f32 y2 = rect[4] * s0 + rect[5] * c0;
            f32 x3 = rect[6] * c0 - rect[7] * s0;
            f32 y3 = rect[6] * s0 + rect[7] * c0;
            rect[4] = x2; rect[5] = y2;
            rect[6] = x3; rect[7] = y3;
        }

        for (i = 0; i < 4; i++) {
            rect[i * 2 + 0] += cx;
            rect[i * 2 + 1] += cy;
        }

        FUN_0021d890(base, rect);

        // Slot 0 alpha
        if ((u32)counter_f < 2) {
            alpha = 0.0f;
        } else if ((u32)counter_f < 12) {
            alpha = 1.0f - (f32)((u32)counter_f - 2) / 10.0f;
        } else if ((u32)counter_f < 18) {
            alpha = 1.0f;
        } else {
            alpha = 1.0f - (f32)((u32)counter_f - 18) / 2.0f;
        }
        if (alpha < 0.0f) alpha = 0.0f;
        colour[0] = 0xFF;
        colour[1] = 0xFF;
        colour[2] = 0xFF;
        colour[3] = (u8)(s32)(alpha * 255.0f);
        FUN_0021d950(base, colour);

        // -- Slots 1 and 2 --
        resource = FUN_0021cca0(table, 14);
        size_w = (f32)((u32*)resource)[3];
        size_h = (f32)((u32*)resource)[4];

        // Slot 1
        {
            f32 t_s1;
            if ((u32)counter_f < 6) {
                t_s1 = 0.0f;
            } else if ((u32)counter_f < 15) {
                t_s1 = (f32)((u32)counter_f - 6) / 9.0f;
            } else if ((u32)counter_f < 18) {
                t_s1 = 1.0f;
            } else {
                t_s1 = 1.0f - (f32)((u32)counter_f - 18) / 2.0f;
            }

            angle = (1.0f - t_s1) * 3.14159265f;
            pos_x = 100.0f + offset_x;
            pos_y = 30.0f + offset_y;

            rect[0] = pos_x; rect[1] = pos_y;
            rect[2] = pos_x + size_w; rect[3] = pos_y;
            rect[4] = pos_x + size_w; rect[5] = pos_y + size_h;
            rect[6] = pos_x; rect[7] = pos_y + size_h;

            cx = (rect[0] + rect[2]) * 0.5f;
            cy = (rect[1] + rect[5]) * 0.5f;
            for (i = 0; i < 4; i++) {
                rect[i * 2 + 0] -= cx;
                rect[i * 2 + 1] -= cy;
            }

            // Corner pair 0-1
            s0 = sinf(angle);
            c0 = cosf(angle);
            {
                f32 x0 = rect[0] * c0 - rect[1] * s0;
                f32 y0 = rect[0] * s0 + rect[1] * c0;
                f32 x1 = rect[2] * c0 - rect[3] * s0;
                f32 y1 = rect[2] * s0 + rect[3] * c0;
                rect[0] = x0; rect[1] = y0;
                rect[2] = x1; rect[3] = y1;
            }

            // Corner pair 2-3
            s0 = sinf(angle);
            c0 = cosf(angle);
            {
                f32 x2 = rect[4] * c0 - rect[5] * s0;
                f32 y2 = rect[4] * s0 + rect[5] * c0;
                f32 x3 = rect[6] * c0 - rect[7] * s0;
                f32 y3 = rect[6] * s0 + rect[7] * c0;
                rect[4] = x2; rect[5] = y2;
                rect[6] = x3; rect[7] = y3;
            }

            for (i = 0; i < 4; i++) {
                rect[i * 2 + 0] += cx;
                rect[i * 2 + 1] += cy;
            }

            FUN_0021d890(base + 0x100, rect);

            if ((u32)counter_f < 6) {
                alpha = 0.0f;
            } else if ((u32)counter_f < 15) {
                alpha = 1.0f - (f32)((u32)counter_f - 6) / 9.0f;
            } else if ((u32)counter_f < 18) {
                alpha = 1.0f;
            } else {
                alpha = 1.0f - (f32)((u32)counter_f - 18) / 2.0f;
            }
            if (alpha < 0.0f) alpha = 0.0f;
            colour[0] = 0xFF;
            colour[1] = 0xFF;
            colour[2] = 0xFF;
            colour[3] = (u8)(s32)(alpha * 255.0f);
            FUN_0021d950(base + 0x100, colour);
        }
        // Fetch resource again for slot 2 (retail fetches id 14 twice)
        resource = FUN_0021cca0(table, 14);
        size_w = (f32)((u32*)resource)[3];
        size_h = (f32)((u32*)resource)[4];

        // Slot 2
        {
            f32 t_s2;
            if ((u32)counter_f < 7) {
                t_s2 = 0.0f;
            } else if ((u32)counter_f < 16) {
                t_s2 = (f32)((u32)counter_f - 7) / 9.0f;
            } else if ((u32)counter_f < 18) {
                t_s2 = 1.0f;
            } else {
                t_s2 = 1.0f - (f32)((u32)counter_f - 18) / 2.0f;
            }

            angle = (1.0f - t_s2) * 3.14159265f;
            pos_x = 100.0f + offset_x;
            pos_y = 30.0f + offset_y + (5.0f * ((f32)((u32)counter_f) / 20.0f));

            rect[0] = pos_x; rect[1] = pos_y;
            rect[2] = pos_x + size_w; rect[3] = pos_y;
            rect[4] = pos_x + size_w; rect[5] = pos_y + size_h;
            rect[6] = pos_x; rect[7] = pos_y + size_h;

            cx = (rect[0] + rect[2]) * 0.5f;
            cy = (rect[1] + rect[5]) * 0.5f;
            for (i = 0; i < 4; i++) {
                rect[i * 2 + 0] -= cx;
                rect[i * 2 + 1] -= cy;
            }

            // Corner pair 0-1
            s0 = sinf(angle);
            c0 = cosf(angle);
            {
                f32 x0 = rect[0] * c0 - rect[1] * s0;
                f32 y0 = rect[0] * s0 + rect[1] * c0;
                f32 x1 = rect[2] * c0 - rect[3] * s0;
                f32 y1 = rect[2] * s0 + rect[3] * c0;
                rect[0] = x0; rect[1] = y0;
                rect[2] = x1; rect[3] = y1;
            }

            // Corner pair 2-3
            s0 = sinf(angle);
            c0 = cosf(angle);
            {
                f32 x2 = rect[4] * c0 - rect[5] * s0;
                f32 y2 = rect[4] * s0 + rect[5] * c0;
                f32 x3 = rect[6] * c0 - rect[7] * s0;
                f32 y3 = rect[6] * s0 + rect[7] * c0;
                rect[4] = x2; rect[5] = y2;
                rect[6] = x3; rect[7] = y3;
            }

            for (i = 0; i < 4; i++) {
                rect[i * 2 + 0] += cx;
                rect[i * 2 + 1] += cy;
            }

            FUN_0021d890(base + 0x200, rect);

            if ((u32)counter_f < 7) {
                alpha = 0.0f;
            } else if ((u32)counter_f < 16) {
                alpha = 1.0f - (f32)((u32)counter_f - 7) / 9.0f;
            } else if ((u32)counter_f < 18) {
                alpha = 1.0f;
            } else {
                alpha = 1.0f - (f32)((u32)counter_f - 18) / 2.0f;
            }
            if (alpha < 0.0f) alpha = 0.0f;
            colour[0] = 0xFF;
            colour[1] = 0xFF;
            colour[2] = 0xFF;
            colour[3] = (u8)(s32)(alpha * 255.0f);
            FUN_0021d950(base + 0x200, colour);
        }
        break;
    }
    case 7:
    {
        u32 i;
        u8 colour[4];
        u8* base = bytes + 0x1060;
        f32 pos_x;
        f32 pos_y;

        *(u32*)(bytes + 0x147c) = *(u32*)(bytes + 0x147c) + 1;
        // First loop: counter management and random resource assignment
        for (i = 0; i < 4; i++) {
            u32* slot = (u32*)(base + i * 4);
            u32 cnt = slot[0x100] + 1;
            slot[0x100] = cnt;
            if (cnt >= 40) {
                u8* record = base + i;
                record[0x410] = RpRandom() & 1;
                record[0x414] = (u8)RpRandom();
                record[0x418] = RpRandom() & 1;
                {
                    u32 res;
                    if (record[0x410] == 0) {
                        res = FUN_0021cca0(table, 0x0f);
                    } else if (record[0x410] == 1) {
                        res = FUN_0021cca0(table, 0x10);
                    } else {
                        res = 0;
                    }
                    FUN_0021d3b0(base + i * 256, (u8*)(uintptr_t)res);
                }
                slot[0x100] = cnt % 40;
            }
        }
        // Second loop: colour write with alpha computation
        colour[0] = 0xFF;
        colour[1] = 0xFF;
        colour[2] = 0xFF;
        colour[3] = 0xFF;
        for (i = 0; i < 4; i++) {
            f32 val = (f32)((u32*)(base + i * 4))[0x100];
            f32 alpha;
            u32 alpha_bits;

            alpha = val / 40.0f;
            if (alpha <= 0.0f) {
                alpha = 0.0f;
            } else if (alpha <= 0.6f) {
                alpha = alpha / 0.6f;
            } else if (alpha <= 0.7f) {
                alpha = 1.0f;
            } else {
                alpha = (1.0f - alpha) / (1.0f - 0.7f);
            }
            colour[3] = (u8)(s32)(alpha * 255.0f);
            FUN_0021d950(base + i * 256, colour);
        }
        // Third loop: corner rotation and draw
        pos_x = 66.0f + offset_x;
        pos_y = 11.0f + offset_y;
        for (i = 0; i < 4; i++) {
            f32 rect0[4], rect1[4], rect2[4];
            f32 angle;
            f32 s, c;
            f32 x0, y0, x1, y1, x2, y2, x3, y3;
            f32 t;

            t = (f32)((u32*)(base + i * 4))[0x100];
            t = (t + 1.0f) / 40.0f;
            angle = (1.0f - t) * 3.14159f;
            s = sinf(angle);
            c = cosf(angle);
            x0 = D_0068E4F0[i * 4 + 0];
            y0 = D_0068E4F0[i * 4 + 1];
            x1 = D_0068E4F0[i * 4 + 2];
            y1 = D_0068E4F0[i * 4 + 3];
            x2 = D_0068E4F0[i * 4 + 2];
            y2 = D_0068E4F0[i * 4 + 3];
            x3 = D_0068E4F0[i * 4 + 0];
            y3 = D_0068E4F0[i * 4 + 1];
            rect0[0] = pos_x + x0 * c - y0 * s;
            rect0[1] = pos_y + x0 * s + y0 * c;
            rect0[2] = pos_x + x1 * c - y1 * s;
            rect0[3] = pos_y + x1 * s + y1 * c;
            rect1[0] = pos_x + x2 * c - y2 * s;
            rect1[1] = pos_y + x2 * s + y2 * c;
            rect1[2] = pos_x + x3 * c - y3 * s;
            rect1[3] = pos_y + x3 * s + y3 * c;
            rect2[0] = 255.0f * D_0068E4F0[i * 4 + 2];
            rect2[1] = 255.0f * D_0068E4F0[i * 4 + 3];
            rect2[2] = 255.0f * D_0068E4F0[i * 4 + 0];
            rect2[3] = 255.0f * D_0068E4F0[i * 4 + 1];
            FUN_0021e170(base + i * 256, rect0, rect1, rect2);
        }
        break;
    }
    case 8:
    {
        u32 resource;
        f32 rect[4];

        resource = FUN_0021cca0(table, 0x11);
        rect[0] = 39.0f + offset_x;
        rect[1] = 13.0f + offset_y;
        rect[2] = (f32)((u32*)resource)[3];
        rect[3] = (f32)((u32*)resource)[4];
        FUN_0021d8e0(bytes + 0x1060, rect);
        break;
    }
    case 9:
    {
        u32 resource;
        f32 rect[4];

        resource = FUN_0021cca0(table, 0);
        rect[0] = 60.0f + offset_x;
        rect[1] = 41.0f + offset_y;
        rect[2] = (f32)((u32*)resource)[3];
        rect[3] = (f32)((u32*)resource)[4];
        FUN_0021d8e0(bytes + 0x1060, rect);
        break;
    }
    }
}

