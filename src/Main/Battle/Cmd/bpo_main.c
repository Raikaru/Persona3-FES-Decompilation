#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"

#include "Battle/btlUnit.h"
typedef int (*code)(...);
void FUN_00252e80(void);
void FUN_00252f30(void);
void FUN_002532b0(void);
void FUN_002534d0(void *param_1);
extern code DAT_00960090_y2;
extern code DAT_0096009c_y2;
#pragma alias DAT_00960090_abs DAT_00960090_y2
#pragma alias DAT_0096009c_abs DAT_0096009c_y2
extern code DAT_00960090_abs[];
extern code DAT_0096009c_abs[];
extern int iGpffffb6fc;
extern u32 uGpffffb660;
static u32* sBpd660; // puGpffffb660
static u32* sBpd664;
s32 FUN_0021c3f0_y2();
#pragma alias FUN_0021c3f0_u64 FUN_0021c3f0_y2
extern u64 FUN_0021c3f0_u64(u32 param_1);
s32 FUN_0021cca0_y2();
s32 FUN_0021cce0();
#pragma alias FUN_0021cce0_u32 FUN_0021cce0
#pragma alias FUN_0021cca0_u64_u32 FUN_0021cca0_y2
extern u32 FUN_0021cca0_u64_u32(u64 param_1, u32 param_2);
extern u32 FUN_0021cce0_u32(u32 param_1);
extern void FUN_002807a0(u32 param_1, RwV3d *position);
extern u32 FUN_002d20a0(const RwV3d *projected, RwV2d *screen);
extern u32 FUN_00300580(u32 param_1, u32 param_2);
extern s32 FUN_0027f930(s32 param_1);
extern f32 FUN_0052e878_y2(f32 param_1);
extern void FUN_0021d8e0_y2(void *destination, const RwV4d *rect);
extern void FUN_0021d950_y2(void *destination, const RwRGBA *color);


#pragma alias FUN_0021cce0_y2 FUN_0021cce0
#pragma alias DAT_00960090_y2 DAT_00960090
#pragma alias DAT_0096009c_y2 DAT_0096009c
#pragma alias FUN_0021c3f0_y2 FUN_0021c3f0
#pragma alias FUN_0021cca0_y2 FUN_0021cca0
#pragma alias FUN_0052e878_y2 FUN_0052e878
#pragma alias FUN_0021d8e0_y2 FUN_0021d8e0
#pragma alias FUN_0021d950_y2 FUN_0021d950



/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_00251f40(s32 param_1);
void FUN_002520f0(void);
void FUN_00252340(void);
extern code DAT_00960090[];
extern code DAT_0096009c[];
extern f32 fGpffff8070;
extern f32 fGpffff8248;
extern f32 fGpffff83e0;

static u32* sBpo65c; // puGpffffb65c

void func_00252340(void);

static inline f32 bpoMul(f32 left, f32 right)
{
    return left * right;
}



// FUN_00251F40


void FUN_00251f40(s32 param_1)
{
    u32 uVar1;
    u32 *puVar2;
    s32 iVar3;
    s32 iVar4;

    K_ASSERT(sBpo65c != NULL, 0x36);
    puVar2 = sBpo65c;
    iVar3 = FUN_0021c3f0(1);
    *puVar2 = 0;
    puVar2[2] = param_1;
    switch (param_1) {
    case 0:
        iVar4 = FUN_0021cca0(iVar3, 0x39);
        break;
    case 1:
        iVar4 = FUN_0021cca0(iVar3, 0x3a);
        break;
    }
    FUN_0021d3b0(puVar2 + 4, iVar4);
    FUN_0021d3b0(puVar2 + 0x44, iVar4);
    FUN_0021d3b0(puVar2 + 0x84, iVar4);
    FUN_0010a4e0(1, 0xf, 2, 0xf);
    puVar2[1] = 0;
    uVar1 = *puVar2 | 1;
    *puVar2 = uVar1;
    *puVar2 = uVar1 | 2;
}

/* Recovered battle-misc harvest: 0x00251F40-0x00252340 */
// FUN_00252060
void bpo00252060(void)
{
    u32* p;

    K_ASSERT(sBpo65c != NULL, 0x36);
    p = sBpo65c;
    if ((~p[0] & 1) == 0)
    {
        if ((int)p[1] < 0x1e)
        {
            p[1] = p[1] + 1;
        }
        else
        {
            p[0] &= 0xfffffffe;
        }
        func_00252340();
    }
}

// FUN_002520F0


void FUN_002520f0(void)
{
    u32 *puVar1;
    u32 uVar2;
    s32 iVar3;
    s32 iVar4;
    volatile /* Removing this qualifier loses FUN_002520f0 (MATCH nd0 -> MISMATCH nd332, size 584 -> 616) - measured W170. */ code *ppVar5;

    K_ASSERT(sBpo65c != NULL, 0x36);
    puVar1 = sBpo65c;
    iVar3 = FUN_0021c3f0(1);
    uVar2 = *puVar1;
    if ((~uVar2 & 1) == 0) {
        if ((uVar2 & 2) != 0) {
            FUN_00252340();
        }
        ppVar5 = DAT_00960090;
        (*ppVar5)(9, 2);
        (*ppVar5)(0x14, 2);
        (*ppVar5)(8, 0);
        (*ppVar5)(6, 0);
        switch (puVar1[2]) {
        case 0:
            iVar4 = FUN_0021cca0(iVar3, 0x39);
            break;
        case 1:
            iVar4 = FUN_0021cca0(iVar3, 0x3a);
            break;
        }
        (*ppVar5)(1, FUN_0021cce0_y2(iVar4));
        FUN_004d7f60(3, 0x71801);
        FUN_004d7f60(2, 0x48);
        ppVar5 = DAT_0096009c;
        (*ppVar5)(puVar1 + 4, 4, 0, 1, 2);
        (*ppVar5)(puVar1 + 4, 4, 0, 2, 3);
        (*ppVar5)(puVar1 + 0x44, 4, 0, 1, 2);
        (*ppVar5)(puVar1 + 0x44, 4, 0, 2, 3);
        (*ppVar5)(puVar1 + 0x84, 4, 0, 1, 2);
        (*ppVar5)(puVar1 + 0x84, 4, 0, 2, 3);
    }
}

/* W419 negative probes: bpoMul on FUN_00252340 rotation products left nd1201/2820B, window2848B, rate42.59%; float SDA aliases also left nd1201/2820B, window2848B, rate42.59%; reverted. */
// FUN_00252340 NONMATCHING
void FUN_00252340(void)
{
    extern void* FUN_0021c3f0(s32 param_1);
    extern void* FUN_0021cca0(void* texture, s32 frame);
    extern void FUN_0021d8e0(void* destination, const f32* rect);
    extern void FUN_0021d890(void* destination, const f32* rect);
    extern void FUN_0021d950(void* destination, const u8* color);
    extern f32 FUN_0052e6d8(f32 angle);
    extern f32 FUN_0052e878(f32 angle);
    u32 uVar1;
    u32 *puVar2;
    void* uVar3;
    u8* unaff_s2_lo;
    s32 iVar4;
    s32 iVar8;
    float *pfVar5;
    float *pfVar6;
    float fVar13;
    float in_f21;
    float fVar11;
    float fVar7;
    float fVar8;
    float fVar9;
    float fVar10;
    float fVar12;
    float afStack_30[8];
    u8 auStack_20[4];
    K_ASSERT(sBpo65c != NULL, 0x36);
    puVar2 = sBpo65c;
    uVar3 = FUN_0021c3f0(1);
    switch (puVar2[2]) {
    case 0:
        unaff_s2_lo = FUN_0021cca0(uVar3, 0x39);
        break;
    case 1:
        unaff_s2_lo = FUN_0021cca0(uVar3, 0x3a);
        break;
    }

    if ((s32)puVar2[1] < 3) {
        fVar11 = (float)(s32)puVar2[1] / 3.0f;
    } else if ((s32)puVar2[1] < 0x14) {
        fVar11 = 1.0f;
    } else if ((s32)puVar2[1] < 0x1e) {
        fVar11 = 1.0f - (float)(s32)(puVar2[1] - 0x14) / 10.0f;
    } else {
        fVar11 = 0.0f;
    }

    fVar13 = 1.5f;
    afStack_30[0] = ((float)*(int *)(unaff_s2_lo + 0xc) * -(fVar13 - 1.0f)) / 2.0f + 133.0f;
    afStack_30[1] = ((float)*(int *)(unaff_s2_lo + 0x10) * -(fVar13 - 1.0f)) / 2.0f + 146.0f;
    afStack_30[2] = bpoMul((float)*(int *)(unaff_s2_lo + 0xc), fVar13);
    afStack_30[3] = bpoMul((float)*(int *)(unaff_s2_lo + 0x10), fVar13);
    FUN_0021d8e0(puVar2 + 4, afStack_30);

    switch (puVar2[2]) {
    case 0:
        auStack_20[0] = 0x66;
        auStack_20[1] = 0x99;
        auStack_20[2] = 0xff;
        break;
    case 1:
        auStack_20[0] = *(u8 *)(unaff_s2_lo + 0x1c);
        auStack_20[1] = *(u8 *)(unaff_s2_lo + 0x1d);
        auStack_20[2] = *(u8 *)(unaff_s2_lo + 0x1e);
        break;
    }
    fVar11 = fVar11 * 255.0f;
    auStack_20[3] = (u8)fVar11;
    FUN_0021d950(puVar2 + 4, auStack_20);

    switch (puVar2[2]) {
    case 0:
        fVar13 = fGpffff8070 * (1.0f - (float)(int)puVar2[1] / 30.0f) + fGpffff83e0 + 0.0f;
        break;
    case 1:
        fVar13 = fGpffff8070 * ((float)(int)puVar2[1] / 30.0f) + fGpffff83e0 + 0.0f;
        break;
    }
    if (puVar2[2] == 1) {
        in_f21 = ((float)(int)puVar2[1] / 30.0f) * -20.0f + 10.0f;
    } else if (puVar2[2] == 0) {
        in_f21 = ((float)(int)puVar2[1] / 30.0f) * 20.0f - 10.0f;
    }

    uVar1 = puVar2[1];
    if ((int)uVar1 < 3) {
        fVar11 = (float)(int)uVar1 / 3.0f;
    } else if ((int)uVar1 < 0x14) {
        fVar11 = 1.0f;
    } else if ((int)uVar1 < 0x1e) {
        fVar11 = 1.0f - (float)(int)(uVar1 - 0x14) / 10.0f;
    } else {
        fVar11 = 0.0f;
    }

    afStack_30[0] = 0.0f;
    afStack_30[1] = 0.0f;
    afStack_30[2] = (float)*(int *)(unaff_s2_lo + 0xc);
    afStack_30[3] = 0.0f;
    afStack_30[4] = (float)*(int *)(unaff_s2_lo + 0xc);
    afStack_30[5] = (float)*(int *)(unaff_s2_lo + 0x10);
    afStack_30[6] = 0.0f;
    afStack_30[7] = (float)*(int *)(unaff_s2_lo + 0x10);

    for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
        afStack_30[iVar4 * 2] = afStack_30[iVar4 * 2] - 127.0f;
        afStack_30[iVar4 * 2 + 1] = afStack_30[iVar4 * 2 + 1] - 61.0f;
    }
    for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
        afStack_30[iVar4 * 2] = bpoMul(afStack_30[iVar4 * 2], fVar13);
        afStack_30[iVar4 * 2 + 1] = bpoMul(afStack_30[iVar4 * 2 + 1], fVar13);
    }

    fVar13 = fGpffff8248 * (in_f21 / 360.0f) * 2.0f;
    for (iVar8 = 0; iVar8 < 4; iVar8 = iVar8 + 1) {
        pfVar6 = afStack_30 + iVar8 * 2;
        pfVar5 = afStack_30 + iVar8 * 2 + 1;
        fVar7 = (float)FUN_0052e878(fVar13);
        fVar9 = *pfVar5;
        fVar8 = (float)FUN_0052e6d8(fVar13);
        fVar12 = *pfVar6 * fVar8 - fVar9 * fVar7;
        fVar8 = (float)FUN_0052e878(fVar13);
        fVar10 = *pfVar6;
        fVar9 = (float)FUN_0052e6d8(fVar13);
        fVar7 = *pfVar5;
        *pfVar6 = fVar12;
        *pfVar5 = fVar10 * fVar8 + fVar7 * fVar9;
    }
    for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
        afStack_30[iVar4 * 2] = afStack_30[iVar4 * 2] + 127.0f;
        afStack_30[iVar4 * 2 + 1] = afStack_30[iVar4 * 2 + 1] + 61.0f;
    }
    for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
        afStack_30[iVar4 * 2] = afStack_30[iVar4 * 2] + 133.0f;
        afStack_30[iVar4 * 2 + 1] = afStack_30[iVar4 * 2 + 1] + 146.0f;
    }
    FUN_0021d890(puVar2 + 0x44, afStack_30);

    switch (puVar2[2]) {
    case 0:
        auStack_20[0] = 0;
        auStack_20[1] = 0;
        auStack_20[2] = 0xcc;
        break;
    case 1:
        auStack_20[0] = 0x99;
        auStack_20[1] = 0;
        auStack_20[2] = 0;
        break;
    }
    fVar11 = fVar11 * 255.0f * 0.5f;
    auStack_20[3] = (u8)fVar11;
    FUN_0021d950(puVar2 + 0x44, auStack_20);

    if (puVar2[2] == 1) {
        unaff_s2_lo = FUN_0021cca0(uVar3, 0x3a);
    } else if (puVar2[2] == 0) {
        unaff_s2_lo = FUN_0021cca0(uVar3, 0x39);
    }

    uVar1 = puVar2[1];
    if ((int)uVar1 < 0) {
        fVar11 = 0.0f;
    } else if ((int)uVar1 < 4) {
        fVar11 = (float)(int)uVar1 / 4.0f;
    } else if ((int)uVar1 < 0x14) {
        fVar11 = 1.0f;
    } else if ((int)uVar1 < 0x1e) {
        fVar11 = 1.0f - (float)(int)(uVar1 - 0x14) / 10.0f;
    } else {
        fVar11 = 0.0f;
    }

    fVar12 = 0.0f;
    if (puVar2[2] == 1) {
        if ((int)uVar1 < 0) {
            fVar12 = 1.0f;
        } else if ((int)uVar1 < 4) {
            fVar12 = 1.5f + (1.0f - (float)(int)uVar1 / 4.0f);
        } else {
            fVar12 = 1.5f;
        }
    } else if (puVar2[2] == 0) {
        if ((int)uVar1 < 0) {
            fVar12 = 1.0f;
        } else if ((int)uVar1 < 4) {
            fVar12 = 1.5f + -(1.0f - (float)(int)uVar1 / 4.0f);
        } else {
            fVar12 = 1.5f;
        }
    }

    afStack_30[0] = ((float)*(int *)(unaff_s2_lo + 0xc) * -(fVar12 - 1.0f)) / 2.0f + 133.0f;
    afStack_30[1] = ((float)*(int *)(unaff_s2_lo + 0x10) * -(fVar12 - 1.0f)) / 2.0f + 146.0f;
    afStack_30[2] = (float)*(int *)(unaff_s2_lo + 0xc) * fVar12;
    afStack_30[3] = (float)*(int *)(unaff_s2_lo + 0x10) * fVar12;
    FUN_0021d8e0(puVar2 + 0x84, afStack_30);

    switch (puVar2[2]) {
    case 0:
        auStack_20[0] = 0x66;
        auStack_20[1] = 0x99;
        auStack_20[2] = 0xff;
        break;
    case 1:
        auStack_20[0] = *(u8 *)(unaff_s2_lo + 0x1c);
        auStack_20[1] = *(u8 *)(unaff_s2_lo + 0x1d);
        auStack_20[2] = *(u8 *)(unaff_s2_lo + 0x1e);
        break;
    }
    fVar11 = fVar11 * 255.0f;
    auStack_20[3] = (u8)fVar11;
    FUN_0021d950(puVar2 + 0x84, auStack_20);
    *puVar2 = *puVar2 & 0xfffffffd;
}




/* Recovered battle-misc support prelude */


// FUN_00252e60
void bpd00252e60(u32* param_1)
{
    *param_1 = 0;
    param_1[0x2d5] = 0;
    sBpd660 = param_1;
}




/* Recovered battle-misc harvest: 0x00252E80-0x002534D0 */
// FUN_00252E80


void FUN_00252e80(void)



{

  uGpffffb660 = 0;

  return;

}



/* Removing this loses FUN_002534d0 (MATCH nd0 -> MISMATCH nd16) - measured W161. */
#pragma opt_loop_invariants off
