#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
extern f32 DAT_007caee8;
extern u32* DAT_007ce36c;
extern code DAT_00960090[];
extern code DAT_0096009c[];
extern const char DAT_0068ebe8[];
extern void FUN_0025d130(void);
extern f32 FUN_0052e6d8(f32 angle);
extern f32 FUN_0052e878(f32 angle);
extern void* FUN_0021cca0_ptr(void* texture, s32 frame);
#pragma alias FUN_0021cca0_ptr FUN_0021cca0

static u32* sBpRush; // DAT_007ce36c


// FUN_0025d6c0
void bpRush0025d6c0(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    *sBpRush |= 0x10;
}

// FUN_0025d710
void bpRush0025d710(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    *sBpRush &= 0xffffffef;
}

// FUN_0025d760
void bpRush0025d760(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    *sBpRush |= 0x20;
}

// FUN_0025d7b0
void bpRush0025d7b0(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    *sBpRush &= 0xffffffdf;
}

// FUN_0025d800
void bpRush0025d800(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    *sBpRush |= 0x40;
}

// FUN_0025d850
void bpRush0025d850(void)
{
    K_ASSERT(sBpRush != NULL, 0x32);
    *sBpRush &= 0xffffffbf;
}

// FUN_0025d020
void bpRush0025d020(void)
{
    u32* work;
    u32 v;

    K_ASSERT(sBpRush != NULL, 0x32);
    work = sBpRush;
    if ((~*sBpRush & 1) == 0) {
        v = work[0x206];
        work[0x206] = v + 1;
        work[0x206] = (int)(v + 1) % 10;
        if ((*work & 0x10) != 0 || (*work & 0x20) != 0) {
            if (0 < (int)work[0x204]) {
                work[0x204] = work[0x204] - 1;
            }
        } else if ((int)work[0x204] < 0x10) {
            work[0x204] = work[0x204] + 1;
        }
        if ((*work & 0x40) != 0) {
            if ((int)work[0x205] < 10) {
                work[0x205] = work[0x205] + 1;
            }
        } else if (0 < (int)work[0x205]) {
            work[0x205] = work[0x205] - 1;
        }
        FUN_0025d130();
    }
}

/* Recovered battle-misc harvest: 0x0025D470-0x0025D470 */
// FUN_0025D470
void FUN_0025d470(void)
{
    extern void* FUN_00267390(void);
    extern void* FUN_0021cca0(void* texture, s32 frame);
    extern void* FUN_0021cce0(void* frame);
    extern void FUN_0021d8e0(void* destination, const f32* layout);
    extern void FUN_0021d950(void* destination, const u8* color);
    extern void FUN_004d7f60(s32 state, u32 value);
    volatile code *state;
    volatile code *quad;
    u32* puVar1;
    void* uVar2;
    void* uVar3;
    int iVar4;
    u32* pQuad;

    if (DAT_007ce36c == (u32*)0x0) {
        K_Assert(DAT_0068ebe8, 0x32);
    }
    puVar1 = DAT_007ce36c;
    uVar2 = FUN_00267390();
    if ((~*puVar1 & 1) == 0) {
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
            pQuad = puVar1 + iVar4 * 0x40 + 0x44;
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
        (*quad)(puVar1 + 4, 4, 0, 1, 2);
        (*quad)(puVar1 + 4, 4, 0, 2, 3);
    }
}

/* Recovered battle-misc harvest: 0x0025D130-0x0025D130 */
// FUN_0025D130
void FUN_0025d130(void)
{
    u8* work;
    void* texture;
    void* frame;
    s32 i;
    u8* quad;
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
    if (DAT_007ce36c == (u32*)0x0) {
        K_Assert(DAT_0068ebe8, 0x32);
    }
    work = (u8*)DAT_007ce36c;
    texture = (void*)(uintptr_t)FUN_00267390();
    scaleX = (f32)*(s32*)(work + 0x810) / 16.0f;
    scaleY = (f32)*(s32*)(work + 0x814) / 10.0f;

    frame = FUN_0021cca0_ptr(texture, 0);
    rect[0] = 41.0f;
    rect[1] = 379.0f;
    rect[2] = (f32)*(s32*)((u8*)frame + 0xc);
    rect[3] = (f32)*(s32*)((u8*)frame + 0x10);
    FUN_0021d8e0(work + 0x10, rect);

    color.r = 0xff;
    color.g = 0xff;
    color.b = 0xff;
    colorValue = scaleX * 255.0f;
    color.a = (u8)colorValue;
    FUN_0021d950(work + 0x10, &color);
    spin = (f32)*(s32*)(work + 0x818) / 10.0f;
    frame = FUN_0021cca0_ptr(texture, 1);
    i = 0;
    angleBase = DAT_007caee8 * spin;
    width = scaleX * scaleY * 20.0f;
    alpha = colorValue * scaleY;
    while (i < 7) {
        quad = work + i * 0x100 + 0x110;
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
