#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"


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

// FUN_00251f20
void bpo00251f20(u32* param_1)
{
    *param_1 = 0;
    sBpo65c = param_1;
}

// FUN_00251f30
void bpo00251f30(void)
{
    sBpo65c = NULL;
}

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

/* Recovered battle-misc harvest: 0x00251F40-0x00252340 */
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

// FUN_002520F0


void FUN_002520f0(void)
{
    u32 *puVar1;
    u32 uVar2;
    s32 iVar3;
    s32 iVar4;
    volatile code *ppVar5;

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
        (*ppVar5)(1, FUN_0021cce0(iVar4));
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
    s32 iVar4;
    u8* unaff_s2_lo;
    float *pfVar5;
    float *pfVar6;
    float fVar7;
    float fVar8;
    float in_f21;
    float fVar9;
    float fVar10;
    float fVar11;
    float fVar12;
    float fVar13;
    float afStack_30[8];
    float fStack_1c;
    u32 uStack_18;
    float fStack_14;
    u8 uStack_4;
    u8 uStack_3;
    u8 uStack_2;
    u8 uStack_1;

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

    fVar13 = 1.5f;
    afStack_30[0] = ((float)*(int *)(unaff_s2_lo + 0xc) * -0.5f) / 2.0f + 133.0f;
    afStack_30[1] = ((float)*(int *)(unaff_s2_lo + 0x10) * -0.5f) / 2.0f + 146.0f;
    afStack_30[2] = (float)*(int *)(unaff_s2_lo + 0xc) * 1.5f;
    afStack_30[3] = (float)*(int *)(unaff_s2_lo + 0x10) * 1.5f;
    FUN_0021d8e0(puVar2 + 4, afStack_30);

    if (puVar2[2] == 1) {
        uStack_4 = *(u8 *)(unaff_s2_lo + 0x1c);
        uStack_3 = *(u8 *)(unaff_s2_lo + 0x1d);
        uStack_2 = *(u8 *)(unaff_s2_lo + 0x1e);
    } else if (puVar2[2] == 0) {
        uStack_4 = 0x66;
        uStack_3 = 0x99;
        uStack_2 = 0xff;
    }

    fVar11 = fVar11 * 255.0f;
    if (fVar11 < 2.1474836e+09f) {
        uStack_1 = (u8)(int)fVar11;
    } else {
        uStack_1 = (u8)(int)(fVar11 - 2.1474836e+09f);
    }
    FUN_0021d950(puVar2 + 4, &uStack_4);

    uVar1 = puVar2[2];
    if (uVar1 == 1) {
        fVar13 = fGpffff8070 * ((float)(int)puVar2[1] / 30.0f) + fGpffff83e0 + 0.0f;
    } else if (uVar1 == 0) {
        fVar13 = fGpffff8070 * (1.0f - (float)(int)puVar2[1] / 30.0f) + fGpffff83e0 + 0.0f;
    }
    if (uVar1 == 1) {
        in_f21 = ((float)(int)puVar2[1] / 30.0f) * -20.0f + 10.0f;
    } else if (uVar1 == 0) {
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
    fStack_1c = (float)*(int *)(unaff_s2_lo + 0x10);
    uStack_18 = 0;
    fStack_14 = (float)*(int *)(unaff_s2_lo + 0x10);

    for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
        afStack_30[iVar4 * 2] = afStack_30[iVar4 * 2] - 127.0f;
        afStack_30[iVar4 * 2 + 1] = afStack_30[iVar4 * 2 + 1] - 61.0f;
    }
    for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
        afStack_30[iVar4 * 2] = afStack_30[iVar4 * 2] * fVar13;
        afStack_30[iVar4 * 2 + 1] = afStack_30[iVar4 * 2 + 1] * fVar13;
    }

    fVar13 = fGpffff8248 * (in_f21 / 360.0f) * 2.0f;
    for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
        pfVar6 = afStack_30 + iVar4 * 2;
        pfVar5 = afStack_30 + iVar4 * 2 + 1;
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

    if (puVar2[2] == 1) {
        uStack_4 = 0x99;
        uStack_3 = 0;
        uStack_2 = 0;
    } else if (puVar2[2] == 0) {
        uStack_4 = 0;
        uStack_3 = 0;
        uStack_2 = 0xcc;
    }
    fVar11 = fVar11 * 255.0f * 0.5f;
    if (fVar11 < 2.1474836e+09f) {
        uStack_1 = (u8)(int)fVar11;
    } else {
        uStack_1 = (u8)(int)(fVar11 - 2.1474836e+09f);
    }
    FUN_0021d950(puVar2 + 0x44, &uStack_4);

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
            fVar12 = (1.0f - (float)(int)uVar1 / 4.0f) * -1.0f + 1.5f;
        } else {
            fVar12 = 1.5f;
        }
    } else if (puVar2[2] == 0) {
        if ((int)uVar1 < 0) {
            fVar12 = 1.0f;
        } else if ((int)uVar1 < 4) {
            fVar12 = (1.0f - (float)(int)uVar1 / 4.0f) + 1.5f;
        } else {
            fVar12 = 1.5f;
        }
    }

    afStack_30[0] = ((float)*(int *)(unaff_s2_lo + 0xc) * -(fVar12 - 1.0f)) / 2.0f + 133.0f;
    afStack_30[1] = ((float)*(int *)(unaff_s2_lo + 0x10) * -(fVar12 - 1.0f)) / 2.0f + 146.0f;
    afStack_30[2] = (float)*(int *)(unaff_s2_lo + 0xc) * fVar12;
    afStack_30[3] = (float)*(int *)(unaff_s2_lo + 0x10) * fVar12;
    FUN_0021d8e0(puVar2 + 0x84, afStack_30);

    if (puVar2[2] == 1) {
        uStack_4 = *(u8 *)(unaff_s2_lo + 0x1c);
        uStack_3 = *(u8 *)(unaff_s2_lo + 0x1d);
        uStack_2 = *(u8 *)(unaff_s2_lo + 0x1e);
    } else if (puVar2[2] == 0) {
        uStack_4 = 0x66;
        uStack_3 = 0x99;
        uStack_2 = 0xff;
    }
    fVar11 = fVar11 * 255.0f;
    if (fVar11 < 2.1474836e+09f) {
        uStack_1 = (u8)(int)fVar11;
    } else {
        uStack_1 = (u8)(int)(fVar11 - 2.1474836e+09f);
    }
    FUN_0021d950(puVar2 + 0x84, &uStack_4);
    *puVar2 = *puVar2 & 0xfffffffd;
}
