#include "Kernel/Kwln/kwlnTask.h"
#include "Kosaka/k_assert.h"


/* Recovered battle-misc support prelude */
typedef int (*code)(...);
void FUN_0025b4f0(void);
void FUN_0025b690(void);
void FUN_0025bbf0(void);
extern code DAT_00960090;
#pragma alias DAT_00960090_abs DAT_00960090
extern u8 DAT_00960090_abs[];
extern code DAT_0096009c;
#pragma alias DAT_0096009c_abs DAT_0096009c
extern u8 DAT_0096009c_abs[];
extern f32 fGpffff83c4;
extern void* FUN_0020e610(s32 index);
extern void FUN_0021eb80(void* work, const f32* values);
extern void FUN_0010a4e0(s32, s32, s32, s32);
extern void FUN_0021d890(void* work, const f32* values);
extern void FUN_0021d8e0(void* work, const f32* values);
extern void FUN_0021d950(void* work, const u8* color);

typedef struct {
    f32 sp80;
    f32 sp84;
    f32 sp88;
    f32 sp8C;
    f32 sp90;
    f32 sp94;
    f32 sp98;
    f32 sp9C;
    u8 padA0[0xc];
    u8 spAC;
    u8 spAD;
    u8 spAE;
    u8 spAF;
} SflCountStack;
static u32* sSflCount; // puGpffffb674

// FUN_0025b4a0
void sflCount0025b4a0(u32* param_1)
{
    *param_1 = 0;
    sSflCount = param_1;
}

// FUN_0025b5f0
void sflCount0025b5f0(void)
{
    u32* work;

    K_ASSERT(sSflCount != NULL, 0x2b);
    work = sSflCount;
    work[2] = 0;
    *work |= 2;
}

// FUN_0025b4b0
void sflCount0025b4b0(void)
{
    K_ASSERT(sSflCount != NULL, 0x2b);
    sSflCount = NULL;
}

// FUN_0025b640
u32 sflCount0025b640(void)
{
    K_ASSERT(sSflCount != NULL, 0x2b);
    return *sSflCount & 1;
}

/* Recovered battle-misc harvest: 0x0025B4F0-0x0025BBF0 */
// FUN_0025B4F0


void FUN_0025b4f0(void)
{
    u32* work;
    s32 i;
    void* resource;
    f32 width;
    f32 height;
    f32 transform[4];

    K_ASSERT(sSflCount != NULL, 0x2b);
    work = sSflCount;
    for (i = 0; i < 3; i++) {
        resource = FUN_0020e610(i);
        width = (f32)*(s32*)((u8*)resource + 0xc);
        height = (f32)*(s32*)((u8*)resource + 0x10);
        transform[0] = 0.0f / width;
        transform[1] = 0.0f / height;
        transform[2] = width / width;
        transform[3] = height / height;
        FUN_0021eb80(work + i * 0x40 + 4, transform);
        FUN_0021eb80(work + i * 0x40 + 0xc4, transform);
    }
    work[1] = 0;
    work[2] = 0;
    *work &= ~2;
    *work |= 1;
}

/* Removing this worsens FUN_0025b690 (nd14 -> nd133) - measured W161. */
#pragma opt_loop_invariants on
#pragma push
/* Removing this worsens FUN_0025b690 (nd14 -> nd74) - measured W161. */
#pragma opt_rebuildconditionals off
// FUN_0025B690 NONMATCHING
void FUN_0025b690(void)
{
    u32 uVar1;
    s32 uVar2;
    u32* puVar2;
    s32 iVar3;
    s32 iVar4;
    s32 iVar5;
    f32 fVar9;
    f32 fVar8;
    f32 fOne;
    f32 fVar6;
    f32 fVar7;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f1;
    f32 var_f1;
    s32 var_3;
    s32 var_3_2;
    s32 var_3_3;
    u32 var_3_4;
    u32 var_3_5;
    u8* resource;
    u8* temp_2_4;
    SflCountStack stack;
    u8* temp_2_6;
    u8* temp_2_8;

    K_ASSERT(sSflCount != NULL, 0x2b);
    puVar2 = sSflCount;
    if ((~puVar2[0] & 1) == 0) {
        uVar1 = puVar2[1] + 1;
        puVar2[1] = uVar1;
        if (uVar1 == 0xb4) {
            uVar1 = puVar2[0] & ~2;
            puVar2[0] = uVar1;
            puVar2[0] = uVar1 & ~1;
        }
        if (puVar2[0] & 2) {
            uVar1 = puVar2[2] + 1;
            puVar2[2] = uVar1;
            if (uVar1 == 0x14) {
                uVar1 = puVar2[0] & ~2;
                puVar2[0] = uVar1;
                puVar2[0] = uVar1 & ~1;
            }
            temp_f0 = (f32)(s32)puVar2[2];
            temp_f0 = temp_f0 / 20.0f;
            fOne = 1.0f;
            fVar8 = fOne - temp_f0;
        } else {
            fOne = 1.0f;
            fVar8 = fOne;
        }
        for (iVar5 = 0; iVar5 < 3; iVar5++) {
            resource = (u8*)FUN_0020e610(iVar5);
            temp_f0 = fGpffff83c4;
            fVar6 = (f32)*(s32*)(resource + 0xc);
            fVar7 = (f32)*(s32*)(resource + 0x10);
            fVar6 = fVar6 * temp_f0;
            fVar7 = fVar7 * temp_f0;
            stack.sp80 = 236.0f;
            stack.sp84 = 196.0f;
            stack.sp88 = 236.0f + fVar6;
            stack.sp8C = 196.0f;
            stack.sp90 = stack.sp88;
            stack.sp94 = 196.0f + fVar7;
            stack.sp98 = 236.0f;
            stack.sp9C = stack.sp94;
            iVar3 = (2 - iVar5) * 0x1e + 0x5a;
            uVar2 = puVar2[1];
            if (uVar2 < iVar3) {
                fVar9 = fOne;
            } else {
                iVar4 = uVar2 - iVar3;
                if (iVar4 < 0x14) {
                    fVar9 = 0.5f + ((f32)iVar4 / 20.0f);
                }
            }
            temp_f0_2 = 319.0f;
            temp_f0_3 = 279.0f;
            for (var_3 = 0; var_3 < 4; var_3++) {
                temp_2_4 = (u8*)&stack + var_3 * 8;
                *(f32*)temp_2_4 = *(f32*)temp_2_4 - temp_f0_2;
                *(f32*)(temp_2_4 + 4) = *(f32*)(temp_2_4 + 4) - temp_f0_3;
            }
            for (var_3_2 = 0; var_3_2 < 4; var_3_2++) {
                temp_2_6 = (u8*)&stack + var_3_2 * 8;
                *(f32*)temp_2_6 = *(f32*)temp_2_6 * fVar9;
                *(f32*)(temp_2_6 + 4) = *(f32*)(temp_2_6 + 4) * fVar9;
            }
            temp_f0_2 = 319.0f;
            temp_f0_3 = 279.0f;
            for (var_3_3 = 0; var_3_3 < 4; var_3_3++) {
                temp_2_8 = (u8*)&stack + var_3_3 * 8;
                *(f32*)temp_2_8 = *(f32*)temp_2_8 + temp_f0_2;
                *(f32*)(temp_2_8 + 4) = *(f32*)(temp_2_8 + 4) + temp_f0_3;
            }
            FUN_0021d890(puVar2 + iVar5 * 0x40 + 4, (f32*)&stack.sp80);
            stack.sp80 = 236.0f;
            stack.sp84 = 196.0f;
            stack.sp88 = fVar6;
            stack.sp8C = fVar7;
            FUN_0021d8e0(puVar2 + iVar5 * 0x40 + 0xc4, (f32*)&stack.sp80);
            uVar2 = puVar2[1];
            if (uVar2 < iVar3) {
                var_f1 = 0.0f;
            } else {
                iVar3 = uVar2 - iVar3;
                if (iVar3 == 0) {
                    FUN_0010a4e0(1, 1, 6, 5);
                }
                if (iVar3 < 0xa) {
                    var_f1 = (f32)iVar3 / 10.0f;
                } else if (iVar3 < 0xf) {
                    var_f1 = fOne;
                } else if (iVar3 < 0x14) {
                    var_f1 = 1.0f - ((f32)(iVar3 - 0xf) / 5.0f);
                } else {
                    var_f1 = 0.0f;
                }
            }
            stack.spAC = 0xff;
            stack.spAD = 0xff;
            stack.spAE = 0xff;
            fVar7 = 255.0f * var_f1 * fVar8;
            temp_f1 = 0.25f * fVar7;
            if (2147483648.0f <= temp_f1) goto alpha1_high;
            var_3_4 = (s32)temp_f1 & 0xff;
            goto alpha1_done;
alpha1_high:
            var_3_4 = ((s32)(temp_f1 - 2147483648.0f) | 0x80000000) & 0xff;
alpha1_done:
            stack.spAF = var_3_4;
            FUN_0021d950(puVar2 + iVar5 * 0x40 + 4, &stack.spAC);
            stack.spAC = 0xff;
            stack.spAD = 0xff;
            stack.spAE = 0xff;
            if (2147483648.0f <= fVar7) goto alpha2_high;
            var_3_5 = (s32)fVar7 & 0xff;
            goto alpha2_done;
alpha2_high:
            var_3_5 = ((s32)(fVar7 - 2147483648.0f) | 0x80000000) & 0xff;
alpha2_done:
            stack.spAF = var_3_5;
            FUN_0021d950(puVar2 + iVar5 * 0x40 + 0xc4, &stack.spAC);
        }
    }
}
#pragma pop

#pragma opt_loop_invariants off
// FUN_0025BBF0


void FUN_0025bbf0(void)
{
    code *draw;
    code *render;
    u32* work;
    u32 resource;
    s32 i;

    K_ASSERT(sSflCount != NULL, 0x2b);
    work = sSflCount;
    if ((~*work & 1) == 0) {
        render = (code *)&DAT_00960090_abs;
        (*render)(9, 2);
        (*render)(0x14, 2);
        (*render)(8, 0);
        (*render)(6, 0);
        FUN_004d7f60(3, 0x717fb);
        FUN_004d7f60(2, 0x44);
        FUN_004d7f60(3, 0x71801);
        FUN_004d7f60(2, 0x48);

        for (i = 0; i < 3; i++) {
            resource = (u32)FUN_0020e610(i);
            (*render)(1, resource);
            {
                u32* drawWork = work + i * 0x40 + 4;
                draw = (code *)&DAT_0096009c_abs;
                (*draw)(drawWork, 4, 0, 1, 2);
                (*draw)(drawWork, 4, 0, 2, 3);
            }
            {
                u32* drawWork = work + i * 0x40 + 0xc4;
                (*draw)(drawWork, 4, 0, 1, 2);
                (*draw)(drawWork, 4, 0, 2, 3);
            }
        }
    }
}
