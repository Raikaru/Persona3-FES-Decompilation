#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"
#include "Main/Battle/Cmd/bp_rush.h"

typedef int (*code)(...);
void FUN_0025be60(u32 param_1, u32 param_2, u32 param_3);
void FUN_0025c220(void);
void FUN_0025c9c0(void);
void FUN_0025cd30(void);
void FUN_0025cdb0(float param_1,float param_2,int param_3);
void FUN_0025ce30(float param_1,float param_2,int param_3);
int FUN_0025ceb0(int param_1);
s32 FUN_0021c3f0();
#pragma alias FUN_0021c3f0_u64 FUN_0021c3f0
extern u64 FUN_0021c3f0_u64(u32 param_1);
extern u32 FUN_003a52c0(float param_1, s32 param_2, s32 param_3,
                        s32 param_4, s32 param_5, s32 param_6,
                        u32 param_7, u32 param_8);
extern void func_003b0e20(u32 resource, u32 color);
void FUN_0025cf00(u32 *param_1);
void FUN_0025cf10(void);
void FUN_0025cf20(void);
static u32* sBpDialog678;
static u32* sBpDialog36c;
static u32* sBpDialog368; // 007ce368
#pragma alias DAT_007e094e_abs DAT_007e094e
extern u16 DAT_007e094e_abs[];
extern code DAT_00960090_y2;
#pragma alias DAT_00960090_abs DAT_00960090_y2
#pragma alias DAT_0096009c_abs DAT_0096009c_y2
extern code DAT_00960090_abs[];
extern code DAT_0096009c_abs[];
extern code DAT_0096009c_y2;
extern int iGpffffb6fc;
extern void FUN_0019d3f0(const char* file, s32 line);
extern const char DAT_0068ebd8[];
#define FUN_0019d3f0(file, line) FUN_0019d3f0((const char*)(file), line)
u64 FUN_003b0170(u64 param_1);


#pragma alias DAT_00960090_y2 DAT_00960090
#pragma alias DAT_0096009c_y2 DAT_0096009c

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


// FUN_0025CF20


void FUN_0025cf20(void)
{
    u32 flags;
    u32* dialog;
    int i;
    int resource;
    int image;

    if (sBpDialog36c == NULL)
    {
        FUN_0019d3f0(DAT_0068ebe8, 0x32);
    }
    dialog = sBpDialog36c;
    resource = FUN_00267390();
    image = FUN_0021cca0(resource, 0);
    FUN_0021d3b0(dialog + 4, image);
    resource = FUN_0021cca0(resource, 1);
    for (i = 0; i < 7; i++)
    {
        FUN_0021d3b0(dialog + i * 0x40 + 0x44, resource);
    }
    dialog[0x204] = 0;
    dialog[0x205] = 0;
    dialog[0x206] = 0;
    flags = *dialog;
    *dialog = flags & 0xfffffffd;
    *dialog = flags & 0xfffffffd | 4;
    FUN_0025d130();
    *dialog |= 1;
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

/* Recovered battle-misc harvest: 0x0025D470-0x0025D470 */
// FUN_0025d7b0
void bpRushClearSecondaryHideRequest(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    sBpRush->flags &= 0xffffffdf;
}

/* Recovered battle-misc harvest: 0x0025D130-0x0025D130 */
// FUN_0025d800
void bpRushShowSpinner(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    sBpRush->flags |= 0x40;
}




/* Recovered battle-misc support prelude */








/* Recovered from the battle-misc range 0x0025BE60-0x0025CF20.
 *
 * The remaining difference is the operand order of a commutative multiply:
 * this emits `mul.s $f20, $f20, $f0` where retail has
 * `mul.s $f20, $f0, $f20`. MWCCPS2 b210 canonicalizes the source form, so no
 * arrangement of the C expression reproduces retail's order.
 */








// FUN_0025d850
void bpRushHideSpinner(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    sBpRush->flags &= 0xffffffbf;
}
