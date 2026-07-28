#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Cmd/bp_rush.h"
#pragma alias bpRushRequestHide FUN_0025d6c0
#pragma alias bpRushClearHideRequest FUN_0025d710
#pragma alias bpRushRequestSecondaryHide FUN_0025d760
#pragma alias bpRushClearSecondaryHideRequest FUN_0025d7b0
#pragma alias bpRushShowSpinner FUN_0025d800
#pragma alias bpRushHideSpinner FUN_0025d850
#pragma alias bpRushUpdate FUN_0025d020
#pragma alias bpRushDraw FUN_0025D470
#pragma alias bpRushUpdateGeometry FUN_0025D130



/* Recovered battle-misc support prelude */
typedef int (*code)(...);
extern f32 DAT_007caee8;
extern BpRushWork* DAT_007ce36c;
extern code DAT_00960090[];
extern code DAT_0096009c[];
extern const char DAT_0068ebe8[];
extern f32 FUN_0052e6d8(f32 angle);
extern f32 FUN_0052e878(f32 angle);
extern void* FUN_0021cca0_ptr(void* texture, s32 frame);
#pragma alias FUN_0021cca0_ptr FUN_0021cca0

static BpRushWork* sBpRush; // DAT_007ce36c


// FUN_0025d6c0
void bpRushRequestHide(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    sBpRush->flags |= 0x10;
}

// FUN_0025d710
void bpRushClearHideRequest(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    sBpRush->flags &= 0xffffffef;
}

// FUN_0025d760
void bpRushRequestSecondaryHide(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    sBpRush->flags |= 0x20;
}

// FUN_0025d7b0
void bpRushClearSecondaryHideRequest(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    sBpRush->flags &= 0xffffffdf;
}

// FUN_0025d800
void bpRushShowSpinner(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    sBpRush->flags |= 0x40;
}

// FUN_0025d850
void bpRushHideSpinner(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    sBpRush->flags &= 0xffffffbf;
}

// FUN_0025d020
void bpRushUpdate(void)
{
    BpRushWork* work;
    u32 v;

    K_ASSERT(sBpRush != NULL, 0x32);
    work = sBpRush;
    if ((~sBpRush->flags & 1) == 0) {
        v = work->spinFrame.unsignedValue;
        work->spinFrame.unsignedValue = v + 1;
        work->spinFrame.unsignedValue = (int)(v + 1) % 10;
        if ((work->flags & 0x10) != 0 || (work->flags & 0x20) != 0) {
            if (0 < (int)work->mainVisibility.unsignedValue) {
                work->mainVisibility.unsignedValue =
                    work->mainVisibility.unsignedValue - 1;
            }
        } else if ((int)work->mainVisibility.unsignedValue < 0x10) {
            work->mainVisibility.unsignedValue =
                work->mainVisibility.unsignedValue + 1;
        }
        if ((work->flags & 0x40) != 0) {
            if ((int)work->spinnerVisibility.unsignedValue < 10) {
                work->spinnerVisibility.unsignedValue =
                    work->spinnerVisibility.unsignedValue + 1;
            }
        } else if (0 < (int)work->spinnerVisibility.unsignedValue) {
            work->spinnerVisibility.unsignedValue =
                work->spinnerVisibility.unsignedValue - 1;
        }
        bpRushUpdateGeometry();
    }
}

/* Recovered battle-misc harvest: 0x0025D470-0x0025D470 */
// FUN_0025D470
void bpRushDraw(void)
{
    extern void* FUN_00267390(void);
    extern void* FUN_0021cca0(void* texture, s32 frame);
    extern void* FUN_0021cce0(void* frame);
    extern void FUN_0021d8e0(void* destination, const f32* layout);
    extern void FUN_0021d950(void* destination, const u8* color);
    extern void FUN_004d7f60(s32 state, u32 value);
    volatile /* Removing this function's qualifier batch loses bpRushDraw (MATCH nd0 -> MISMATCH nd377, size 580 -> 592) - measured W170. */ code *state;
    volatile /* Removing this function's qualifier batch loses bpRushDraw (MATCH nd0 -> MISMATCH nd377, size 580 -> 592) - measured W170. */ code *quad;
    BpRushWork* puVar1;
    void* uVar2;
    void* uVar3;
    int iVar4;
    u32* pQuad;

    if (DAT_007ce36c == (BpRushWork*)0x0) {
        K_Assert(DAT_0068ebe8, 0x32);
    }
    puVar1 = DAT_007ce36c;
    uVar2 = FUN_00267390();
    if ((~puVar1->flags & 1) == 0) {
        state = DAT_00960090;
        (*state)(9, 2);
        (*state)(0x14, 2);
        (*state)(8, 0);
        (*state)(6, 0);
        uVar3 = FUN_0021cca0(uVar2, 1);
        uVar3 = FUN_0021cce0(uVar3);
        (*state)(1, uVar3);
        FUN_004d7f60(3, 0x71801);
        FUN_004d7f60(2, 0x48);
        for (iVar4 = 0; iVar4 < 7; iVar4 = iVar4 + 1) {
            pQuad = puVar1->spinnerQuads[iVar4].words;
            quad = DAT_0096009c;
            (*quad)(pQuad, 4, 0, 1, 2);
            (*quad)(pQuad, 4, 0, 2, 3);
        }
        uVar3 = FUN_0021cca0(uVar2, 0);
        uVar3 = FUN_0021cce0(uVar3);
        (*state)(1, uVar3);
        FUN_004d7f60(3, 0x717fb);
        FUN_004d7f60(2, 0x44);
        quad = DAT_0096009c;
        (*quad)(puVar1->mainQuad.words, 4, 0, 1, 2);
        (*quad)(puVar1->mainQuad.words, 4, 0, 2, 3);
    }
}

/* Recovered battle-misc harvest: 0x0025D130-0x0025D130 */
// FUN_0025D130
void bpRushUpdateGeometry(void)
{
    BpRushWork* work;
    void* texture;
    void* frame;
    s32 i;
    u32* quad;
    f32 scaleX;
    f32 scaleY;
    f32 angleBase;
    f32 spin;
    f32 alpha;
    f32 width;
    f32 cosine;
    f32 angle;
    f32 sine;
    f32 colorValue;
    f32 rect[8];
    struct {
        u8 r;
        u8 g;
        u8 b;
        u8 a;
    } color;
    if (DAT_007ce36c == (BpRushWork*)0x0) {
        K_Assert(DAT_0068ebe8, 0x32);
    }
    work = DAT_007ce36c;
    texture = (void*)(uintptr_t)FUN_00267390();
    scaleX = (f32)work->mainVisibility.signedValue / 16.0f;
    scaleY = (f32)work->spinnerVisibility.signedValue / 10.0f;

    frame = FUN_0021cca0_ptr(texture, 0);
    rect[0] = 41.0f;
    rect[1] = 379.0f;
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(work->mainQuad.words, rect);

    color.r = 0xff;
    color.g = 0xff;
    color.b = 0xff;
    colorValue = scaleX * 255.0f;
    color.a = (u8)colorValue;
    FUN_0021d950(work->mainQuad.words, &color);
    spin = (f32)work->spinFrame.signedValue / 10.0f;
    frame = FUN_0021cca0_ptr(texture, 1);
    i = 0;
    angleBase = DAT_007caee8 * spin;
    width = scaleX * scaleY * 20.0f;
    alpha = colorValue * scaleY;
    while (i < 7) {
        quad = work->spinnerQuads[i].words;
        angle = angleBase + (DAT_007caee8 * (f32)i) / 7.0f;
        cosine = width * FUN_0052e6d8(angle);
        sine = width * FUN_0052e878(angle);
        rect[0] = ((35.0f + cosine) + 6.0f) + 4.0f;
        rect[1] = ((366.0f + sine) + 13.0f) + 4.0f;
        rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
        rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
        FUN_0021d8e0(quad, rect);

        color.r = 0xff;
        color.g = 0xff;
        color.b = 0xff;
        color.a = (u8)alpha;
        FUN_0021d950(quad, &color);
        i = i + 1;
    }
}
