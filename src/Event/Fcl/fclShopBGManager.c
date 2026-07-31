#include "temporary.h"
typedef int (*code)();
typedef void (*FclShopBgCallback)(float, float, float, int, int, int, int, int, int, int, int);
typedef struct {
    u32 *callbacks;
    int count;
} FclShopBgCallbackPair;

typedef union {
    float floats[4];
    u32 words[4];
} FclShopBgHeader;
typedef struct {
    FclShopBgHeader header;
    s16 table2[24];
    s16 table1[40];
} FclShopBgLocal;
u32 H_Maestro_CreateTask(u32 parent,u32 priority,u32 path);
u32 H_Maestro_FinishedInit(u32 task);
void H_Maestro_SetShouldLoop(u32 task,u32 shouldLoop);
void H_Maestro_00111f20(u32 task,u32 value);
void H_Maestro_00111c50(u32 task);
void H_Maestro_00111cb0(u32 task);
void H_Maestro_SetAlphaMult(float alpha,u32 task);
void func_00111f10(u32 task,u32 value);
void func_00111ca0(u32 task,u32 value);
float fGpffff80d0;
float fGpffff8110;
float fGpffff8168;
float fGpffff81f8;
float fGpffff81fc;
float fGpffff8204;
float fGpffffad18;
u32 uGpffff8208;
u32 uGpffffad1c;
#pragma alias sinf_fclShop sinf
extern f32 sinf_fclShop(f32);
#pragma alias cosf_fclShop cosf
extern f32 cosf_fclShop(f32);
/* FUSION_EXACT_PROTOS */
void FUN_0040e3c0(float, s32, s32, u8, s32, s32);
#pragma alias FUN_0040e3c0_i FUN_0040e3c0
void FUN_0040e3c0_i(s32, s32, float, u8, s32, s32);
#pragma alias FUN_0040e3f0_typed FUN_0040e3f0
void FUN_0040e3f0_typed(float, float, float, float, s32, s32, u8, s32, s32, s32, s32);
#pragma alias FUN_003b2cb0_typed FUN_003b2cb0
void FUN_003b2cb0_typed(float, s32, s32, u32, u32, u32, u32, u32, u32);
#pragma alias FUN_003b2cb0_i FUN_003b2cb0
void FUN_003b2cb0_i(s32, s32, float, u32, u32, u32, u32, u32, u32);
void FUN_003eec60(s32);
u64 FUN_004101b0(u64 param_1,int param_2);
u32 FUN_004105e0(int param_1, int param_2, int param_3);
u64 FUN_00410a10(u64 param_1,int param_2);
u32 FUN_00410d30(int param_1,int param_2);
u32 FUN_00410e70(u32 param_1,int param_2,int param_3);
u32 FUN_004110f0(u64 param_1,u64 param_2,int param_3);
u32 FUN_00411190(u64 param_1,u64 param_2,u32 param_3);
u32 FUN_00411340(u64 param_1,u64 param_2,s16 *param_3);
u32 FUN_004113f0(u64 param_1,int param_2,int param_3);
u64 FUN_00411710(u64 param_1,int param_2);
u32 FUN_00411790(u64 param_1,int param_2,long param_3);
u64 FUN_00411ee0(u64 param_1,int param_2);
u32 FUN_004120a0(u64 param_1, int param_2, int param_3);
u64 FUN_00412580(u64 param_1,int param_2);
u32 FUN_00412610(u64 param_1, int param_2, long param_3);
u64 FUN_00412af0(u64 param_1,int param_2);
u32 FUN_00412bc0(u64 param_1, int param_2, long param_3);
u64 FUN_00413010(u64 param_1,int param_2);
u32 FUN_004131a0(u64 param_1, int param_2, int param_3);
u64 FUN_00413680(u64 param_1,int param_2);
u64 FUN_004138e0(u64 param_1,int param_2,long param_3);
u64 FUN_00413b10(u64 param_1,int param_2);
u32 FUN_00413b70(u64 param_1, int param_2, int param_3);
void FUN_00414100(u64 param_1,u64 param_2,int param_3,int param_4,u64 param_5, u32 param_6);
void FUN_004141e0(u64 param_1,u64 param_2,int param_3,int param_4, int param_5,u32 param_6);
void FUN_00414280(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_00414320(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_00414500(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_004145f0(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_004146b0(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_00414770(u64 param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6);
void FUN_004148b0(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_00414950(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_004149f0(u64 param_1,u64 param_2,int param_3,int param_4,u64 param_5, u32 param_6);
void FUN_00414ad0(u64 param_1,u64 param_2,int param_3,int param_4,u64 param_5, u32 param_6);
void FUN_00414bd0(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_00414c70(u64 param_1,u64 param_2,int param_3,int param_4,u64 param_5, u32 param_6);
void FUN_00414d70(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
u64 FUN_00414e10(int param_1,int param_2);
u32 FUN_00414fe0(u64 param_1,int param_2,long param_3);
void FUN_004154e0(u64 param_1,u64 param_2,int param_3,int param_4, int param_5,int param_6);
void FUN_00415650(u64 param_1,u64 param_2,int param_3,int param_4, int param_5,int param_6);
void FUN_004157c0(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_00415880(u64 param_1,u64 param_2,int param_3,int param_4, int param_5,int param_6);
void FUN_00415a70(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_00415b30(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u8 param_6);
void FUN_00415b70(u64 param_1,u64 param_2,int param_3,int param_4,int param_5, u32 param_6);
u64 FUN_00415c30(int param_1, int param_2);
u64 FUN_00415dc0(u64 param_1,int param_2,u8 *param_3);
void FUN_00416240(u64 param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6);
void FUN_004163f0(u64 param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6);
void FUN_004166d0(u64 param_1,int param_2,int param_3,int param_4,int param_5, u32 param_6);
void FUN_004167d0(u64 param_1,int param_2,int param_3,int param_4,int param_5, u8 param_6);
void FUN_00416b90(u64 param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6);
void FUN_00416d20(u64 param_1,int param_2,int param_3,int param_4,int param_5, u8 param_6);
u64 FUN_00417030(int param_1, int param_2);
/* FUSION_GLOBALS */
float DAT_007cadc0;
u32 DAT_006afb90;
u32 DAT_006b0020;
u32 DAT_006b0050;
u32 DAT_006b0450;
u32 DAT_006b04d0;
u32 DAT_006b0a00;
u32 DAT_006b0a60;
float DAT_006b0ac0;
float DAT_006b0ac4;
float DAT_006b0ac8;
float DAT_006b0acc;
#pragma alias DAT_006b0ac0_abs DAT_006b0ac0
extern u8 DAT_006b0ac0_abs[];
#pragma alias DAT_006b0ac4_abs DAT_006b0ac4
extern u8 DAT_006b0ac4_abs[];
#pragma alias DAT_006b0ac8_abs DAT_006b0ac8
extern u8 DAT_006b0ac8_abs[];
#pragma alias DAT_006b0acc_abs DAT_006b0acc
extern u8 DAT_006b0acc_abs[];
u32 DAT_006b0ad0;
u32 DAT_006b0cb0;
u32 DAT_006b0dd4;
u32 DAT_006b0ddc;
u32 DAT_006b0de0;
#pragma alias DAT_006b0de0_abs DAT_006b0de0
extern u8 DAT_006b0de0_abs[];
u32 DAT_006b0e30;
#pragma alias DAT_006b0e30_abs DAT_006b0e30
extern u8 DAT_006b0e30_abs[];

u32 DAT_006b0e64;
u32 DAT_006b0e6c;
#pragma alias DAT_006b0e64_abs DAT_006b0e64
extern u8 DAT_006b0e64_abs[];
u32 DAT_006b10e0;
u32 DAT_006b1130;
u32 DAT_006b1178;
u32 DAT_006b1190;
u32 DAT_006b1220;
u32 DAT_006b1340;
u32 DAT_006b1370;
u32 DAT_006b13a0;
u32 DAT_006b1400;
u32 DAT_006b1460;
u32 DAT_006b14c0;
u32 DAT_006b14f0;
u32 DAT_006b1520;
u32 DAT_006b1580;
u32 DAT_006b1610;
u32 DAT_006b1640;
u32 DAT_006b16a0;
u32 DAT_006b16e0;
u32 DAT_006b1710;
float DAT_007cada4;
float DAT_007caee8;
float DAT_007caef0;
u32 DAT_007cda4c;
u32 DAT_007cda58;
u32 DAT_007cda5a;
u32 DAT_007cda5c;
u32 DAT_007cda5e;
u32 DAT_007cda64;
#pragma alias DAT_007cda64_f DAT_007cda64
extern float DAT_007cda64_f;
u8 *DAT_007ce420;
u8 *DAT_007ce4e4;
code DAT_00960090;
u32 PTR_FUN_006b1490[];
u32 PTR_FUN_006b1494[];
u32 PTR_FUN_006b1498[];
u32 PTR_FUN_006b14a0[];
u32 PTR_FUN_006b16c8[];
u32 PTR_FUN_006b16cc[];
u32 PTR_FUN_006b16d0[];
u32 PTR_FUN_006b1830[];
u32 PTR_FUN_007cda10[];
u32 PTR_FUN_007cda14[];
u32 PTR_FUN_007cda18[];
u32 PTR_FUN_007cda1c[];
u32 PTR_FUN_007cda20[];
u32 PTR_FUN_007cda24[];
u32 PTR_FUN_007cda28[];
u32 PTR_FUN_007cda30[];
u32 PTR_FUN_007cda34[];
u32 PTR_FUN_007cda38[];
u32 PTR_FUN_007cda40[];
u32 PTR_FUN_007cda44[];
#include "Kosaka/k_assert.h"














// FUN_004101B0 NONMATCHING
u64 FUN_004101b0(u64 param_1,int param_2)



{

  int sVar1;

  int sVar2;

  u32 *puVar3;


  int iVar5;

  int iVar6;
  int iVar7;

  float fVar7;

  float fVar8;

  

  puVar3 = *(u32 **)(param_2 + 0xc);

  if ((*puVar3 & 2) == 0) {
    return 0;
  }

  {

    sVar1 = (short)puVar3[2];

    sVar2 = *(short *)((int)puVar3 + 10);

    fVar8 = *(float *)((int)puVar3 + 0x10);

    iVar5 = (int)(fVar8 * 252.0f);

    iVar6 = (int)(fVar8 * 233.0f);

    fVar7 = (float)(int)(short)puVar3[3];

    FUN_0040e3f0_typed(0,DAT_007cadc0 *
                   ((DAT_007caee8 * (float)*(u16 *)((int)puVar3 + 0x16)) / 65535.0f),fVar8,fVar8,
                 sVar1 - iVar5,sVar2 - iVar6,
                 ((fVar7 < 2147483648.0f)
                  ? (s32)fVar7
                  : ((s32)(fVar7 - 2147483648.0f) | 0x80000000)) & 0xff,
                 0x56,0,iVar5,iVar6);

    FUN_0040e3f0_typed(0,DAT_007cadc0 *
                   ((DAT_007caee8 * (float)*(u16 *)((int)puVar3 + 0x16)) / 65535.0f),fVar8,fVar8,
                 sVar1 - iVar5,sVar2,
                 ((fVar7 < 2147483648.0f)
                  ? (s32)fVar7
                  : ((s32)(fVar7 - 2147483648.0f) | 0x80000000)) & 0xff,
                 0x57,0,iVar5,0);

    FUN_0040e3f0_typed(0,DAT_007cadc0 *
                   ((DAT_007caee8 * (float)*(u16 *)((int)puVar3 + 0x16)) / 65535.0f),fVar8,fVar8,
                 sVar1,sVar2 - iVar6,
                 ((fVar7 < 2147483648.0f)
                  ? (s32)fVar7
                  : ((s32)(fVar7 - 2147483648.0f) | 0x80000000)) & 0xff,
                 0x58,0,0,iVar6);

    FUN_0040e3f0_typed(0,DAT_007cadc0 *
                   ((DAT_007caee8 * (float)*(u16 *)((int)puVar3 + 0x16)) / 65535.0f),fVar8,fVar8,
                 sVar1,sVar2,
                 ((fVar7 < 2147483648.0f)
                  ? (s32)fVar7
                  : ((s32)(fVar7 - 2147483648.0f) | 0x80000000)) & 0xff,
                 0x59,0,0,0);

  }

  return 0;

}

#pragma opt_loop_invariants on
// FUN_004105E0 NONMATCHING


u32 FUN_004105e0(int param_1, int param_2, int param_3) { u16 *puVar1;

u32 uVar2;

u8 bVar3;

short sVar4;

u32 uVar5;

long lVar6;

int iVar7;

short *psVar8;

int iVar9;

u32 *puVar10;

int unaff_s2_lo;

short asStack_60050 [4];

float afStack_60048 [7];

short asStack_6002c [4];

float afStack_60024 [98289];

short asStack_50 [2];

float afStack_4c [8];

float afStack_2c [11];



puVar1 = *(u16 **)(param_2 + 0xc);

puVar10 = &DAT_006afb90;

psVar8 = asStack_50;

iVar7 = 9;

do {

  uVar5 = *puVar10;

  uVar2 = puVar10[1];

  puVar10 = puVar10 + 2;

  iVar7 = iVar7 + -1;

  *(u32 *)psVar8 = uVar5;

  *(u32 *)(psVar8 + 2) = uVar2;

  psVar8 = psVar8 + 4;

} while (0 < iVar7);

if (param_3 == 0) {

  sVar4 = puVar1[6];

  if (sVar4 == 3) {

    sVar4 = puVar1[7];

    puVar1[7] = sVar4 + 1;

    puVar1[2] = (short)(int)(255.0f - (float)((short)(sVar4 + 1) * 0xff) / 10.0f);

    if (9 < (short)puVar1[7]) {

      puVar1[7] = 0;

      return 2;

    }

  }

  else if (sVar4 == 2) {

    sVar4 = puVar1[7];

    puVar1[7] = sVar4 + 1;

    puVar1[9] = sVar4 + 1;

    if (0x4af < (short)puVar1[7]) {

      puVar1[7] = 0;

    }

  }

  else if ((sVar4 == 1) || (sVar4 == 0)) {

    sVar4 = puVar1[7] + 1;

    puVar1[7] = sVar4;

    bVar3 = 0;

    if ((short)puVar1[3] <= sVar4) {

      iVar7 = (int)sVar4 - (int)(short)puVar1[3];

      iVar9 = (int)(short)puVar1[8];

      psVar8 = (short *)((int)afStack_2c + (iVar9 * 6 + 3) * 2);

      if ((long)*psVar8 < (long)iVar7) {

        bVar3 = 1;

      }

      else {

        *puVar1 = (short)(int)((float)(int)asStack_50[iVar9 * 6] +

                              (float)(iVar7 * ((int)*(short *)(afStack_2c + iVar9 * 3) -

                                              (int)asStack_50[iVar9 * 6])) / (float)(int)*psVar8);

        puVar1[1] = (short)(int)((float)(int)asStack_50[iVar9 * 6 + 1] +

                                (float)(iVar7 * ((int)*(short *)((int)afStack_2c +

                                                                (iVar9 * 6 + 1) * 2) -

                                                (int)asStack_50[iVar9 * 6 + 1])) /

                                (float)(int)*psVar8);

        puVar1[2] = (short)(int)((float)(int)*(short *)(afStack_4c + iVar9 * 3) +

                                (float)(iVar7 * ((int)*(short *)(afStack_2c + iVar9 * 3 + 1) -

                                                (int)*(short *)(afStack_4c + iVar9 * 3))) /

                                (float)(int)*psVar8);

        *(float *)(puVar1 + 4) =

             afStack_4c[iVar9 * 3 + 1] +

             ((float)iVar7 * (afStack_2c[iVar9 * 3 + 2] - afStack_4c[iVar9 * 3 + 1])) /

             (float)(int)*psVar8;

      }

    }

    if (bVar3) {

      if (puVar1[6] == 1) {

        return 2;

      }

      puVar1[6] = 2;

      puVar1[7] = puVar1[9];

    }

    return 0;

  }

  uVar5 = 1;

}

else {

  sVar4 = *(short *)((int)param_3 + 6);

  if ((sVar4 == 6) || (sVar4 == 5)) {

    lVar6 = FUN_003c4b50(*(int *)(param_1 + 8),*(int *)(param_1 + 8) + 4,4);

    if (lVar6 != 0) {

      unaff_s2_lo = *(int *)((int)lVar6 + 0x14);

    }

    iVar7 = *(short *)((int)param_3 + 6) + -4;

    memcpy(puVar1,asStack_50 + iVar7 * 6,0xc);

    puVar1[6] = 0;

    puVar1[7] = 0;

    puVar1[8] = (short)iVar7;

    if (unaff_s2_lo != 0) {

      puVar1[9] = *(u16 *)(*(int *)(unaff_s2_lo + 0xc) + 0x12);

    }

  }

  else if (sVar4 == 4) {

    puVar1[6] = 3;

    puVar1[7] = 0;

  }

  else if (sVar4 == 1) {

    memcpy(puVar1,asStack_50,0xc);

    puVar1[6] = 0;

    puVar1[7] = 0;

    puVar1[8] = 0;

  }

  uVar5 = 0;

}

return uVar5; }
#pragma opt_loop_invariants off

// FUN_00410A10 NONMATCHING


u64 FUN_00410a10(u64 param_1,int param_2)



{

  short *psVar1;

  float fVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  

  psVar1 = *(short **)(param_2 + 0xc);

  fVar7 = *(float *)(psVar1 + 4);

  iVar3 = (int)((float)(int)*psVar1 - fVar7 * 252.0f);

  iVar4 = (int)((float)(int)psVar1[1] - fVar7 * 252.0f);

  iVar5 = (int)(fVar7 * 251.0f);

  iVar6 = (int)(fVar7 * 249.0f);

  fVar9 = (float)(int)psVar1[2];

  fVar8 = (fGpffff81f8 * (float)(int)psVar1[9]) / 1200.0f;

  fVar2 = fVar9;

  if (2.1474836e+09f <= fVar9) {

    fVar2 = fVar9 - 2.1474836e+09f;

  }

  FUN_0040e3f0_typed(0.0f,fGpffff80d0 * -fVar8,fVar7,fVar7,iVar3,iVar4,(int)fVar2 & 0xff,0x55,0,iVar5,iVar6);

  fVar2 = fVar9;

  if (2.1474836e+09f <= fVar9) {

    fVar2 = fVar9 - 2.1474836e+09f;

  }

  FUN_0040e3f0_typed(0.0f,fGpffff80d0 * (fGpffff8110 - fVar8),fVar7,fVar7,iVar3,iVar4,(int)fVar2 & 0xff,0x55,

                    0,iVar5,iVar6);

  fVar2 = fVar9;

  if (2.1474836e+09f <= fVar9) {

    fVar2 = fVar9 - 2.1474836e+09f;

  }

  FUN_0040e3f0_typed(0.0f,fGpffff80d0 * (fGpffff81fc - fVar8),fVar7,fVar7,iVar3,iVar4,(int)fVar2 & 0xff,0x55,

                    0,iVar5,iVar6);

  if (2.1474836e+09f <= fVar9) {

    fVar9 = fVar9 - 2.1474836e+09f;

  }

  FUN_0040e3f0_typed(0.0f,fGpffff80d0 * (fGpffff8168 - fVar8),fVar7,fVar7,iVar3,iVar4,(int)fVar9 & 0xff,0x55,

                    0,iVar5,iVar6);

  return 0;

}

// FUN_00410D30


u32 FUN_00410d30(int param_1,int param_2)


{

  int iVar1;

  u32 uVar2;

  u32 uVar3;

  u32 lVar4;

  

  iVar1 = *(int *)(param_2 + 0xc);

  if (*(int *)(iVar1 + 0xc) == 0) {

    uVar3 = H_Maestro_CreateTask(*(u32 *)(param_1 + 0xc),0x18b4,

                         *(u32 *)(*(int *)(param_2 + 8) + 0x18));

    *(u32 *)(iVar1 + 0xc) = uVar3;

  }

  lVar4 = H_Maestro_FinishedInit(*(u32 *)(iVar1 + 0xc));

  if (lVar4 != 0) {

    H_Maestro_SetShouldLoop(*(u32 *)(iVar1 + 0xc),0);

    func_00111f10(*(u32 *)(iVar1 + 0xc),0);

    H_Maestro_00111f20(*(u32 *)(iVar1 + 0xc),1);

    func_00111ca0(*(u32 *)(iVar1 + 0xc),1);

    uVar2 = *(u32 *)(*(int *)(param_2 + 8) + 0xc);

    if ((uVar2 & 1) != 0) {

      if ((uVar2 & 2) != 0) {

        H_Maestro_SetShouldLoop(*(u32 *)(iVar1 + 0xc),1);

      }

      if ((uVar2 & 4) != 0) {

        func_00111f10(*(u32 *)(iVar1 + 0xc),1);

      }

      if ((uVar2 & 8) != 0) {

        H_Maestro_00111f20(*(u32 *)(iVar1 + 0xc),0);

      }

      if ((uVar2 & 0x10) != 0) {

        func_00111ca0(*(u32 *)(iVar1 + 0xc),0);

      }

    }

    uVar3 = 1;

  }

  else {

    uVar3 = 0;

  }

  return uVar3;

}

/* W327 measured: opt_common_subs off normalized_diff 431 -> 409; object 640/640 -> 616/640 (without/with). */
#pragma opt_common_subs off
// FUN_00410E70 NONMATCHING


u32 FUN_00410e70(u32 param_1,int param_2,int param_3)



{

  u32 *puVar1;

  short sVar2;

  u32 uVar3;

  long lVar4;

  

  puVar1 = *(u32 **)(param_2 + 0xc);

  if (param_3 == 0) {

    if (puVar1[3] == 0) {

      uVar3 = 1;

    }

    else {

      lVar4 = kwlnTaskGetState();

      if (lVar4 == 3) {

        K_Assert((const char *)0x6afbe0,0x33c);

      }

      if ((*puVar1 & 1) == 0) {

        if ((*puVar1 & 2) != 0) {

          sVar2 = *(short *)((int)puVar1 + 6) + 1;

          *(short *)((int)puVar1 + 6) = sVar2;

          H_Maestro_SetAlphaMult(1.0f - (float)(int)sVar2 / (float)(int)*(short *)((int)puVar1 + 10),puVar1[3])

          ;

          if (*(short *)((int)puVar1 + 10) <= *(short *)((int)puVar1 + 6)) {

            *puVar1 = *puVar1 & 0xfffffffd;

            H_Maestro_00111c50(puVar1[3]);

            return 2;

          }

        }

      }

      else {

        sVar2 = *(short *)((int)puVar1 + 6) + 1;

        *(short *)((int)puVar1 + 6) = sVar2;

        H_Maestro_SetAlphaMult((float)(int)sVar2 / (float)(int)(short)puVar1[2],puVar1[3]);

        if ((short)puVar1[2] <= *(short *)((int)puVar1 + 6)) {

          *puVar1 = *puVar1 & 0xfffffffe;

        }

      }

      H_Maestro_00111cb0(puVar1[3]);

      uVar3 = 1;

    }

  }

  else {

    lVar4 = FUN_00401600(param_1,puVar1[3],*(u16 *)((int)param_3 + 6));

    if (lVar4 == 4) {

      H_Maestro_SetAlphaMult(0x3f800000,puVar1[3]);

      *puVar1 = *puVar1 | 2;

      *(u16 *)((int)puVar1 + 10) = 10;

      *(u16 *)((int)puVar1 + 6) = 0;

    }

    else if (lVar4 == 3) {

      H_Maestro_SetAlphaMult(0,puVar1[3]);

      *puVar1 = *puVar1 | 1;

      *(u16 *)(puVar1 + 2) = 10;

      *(u16 *)((int)puVar1 + 6) = 0;

    }

    else if ((lVar4 != 2) && (lVar4 == 1)) {

      H_Maestro_SetAlphaMult(0x3f800000,puVar1[3]);

    }

    uVar3 = 0;

  }

  return uVar3;

}

#pragma opt_common_subs reset
// FUN_004110F0


u32 FUN_004110f0(u64 param_1,u64 param_2,int param_3)



{

  if (param_3 != 0) {

    switch(*(s16 *)(param_3 + 6)) {
    case 0:
      break;
    case 2:
    case 4:
      FUN_003eec60(1);
      break;
    case 1:
    case 3:
      FUN_003eec60(0);
      break;
    case 5:
      FUN_003eec60(2);
      break;
    case 6:
      FUN_003eec60(3);
    }

  }

  return 1;

}

// FUN_00411190


u32 FUN_00411190(u64 param_1,u64 param_2,u32 param_3)



{

  if (param_3 != 0) {

    switch(*(s16 *)((int)param_3 + 6)) {

    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      break;
    case 5:

      FUN_003ef970(0);

      break;

    case 10:

      FUN_003ef970(1);

      break;

    case 6:

      FUN_003ef970(2);

      break;

    case 0xb:

      FUN_003ef970(3);

      break;

    case 7:

      FUN_003ef970(4);

      break;

    case 0xc:

      FUN_003ef970(5);

      break;

    case 8:

      FUN_003ef970(6);

      break;

    case 0xd:

      FUN_003ef970(7);

      break;

    case 9:

      FUN_003ef970(8);

      break;

    case 0xe:

      FUN_003ef970(9);

      break;

    case 0xf:

      FUN_003ef970(10);

      break;

    case 0x10:

      FUN_003ef970(0xb);

      break;

    case 0x11:

      FUN_003ef970(0xc);

      break;

    case 0x12:

      FUN_003ef970(0xd);

      break;

    case 0x13:

      FUN_003ef970(0xe);

      break;

    case 0x14:

      FUN_003ef970(0xf);

      break;

    case 0x15:

      FUN_003ef970(0x10);

      break;

    case 0x16:

      FUN_003ef970(0x11);

    }

  }

  return 1;

}

// FUN_00411340


u32 FUN_00411340(u64 param_1,u64 param_2,s16 *param_3)



{

  if (param_3 != 0) {

    switch(param_3[3]) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      break;

    case 5:

      FUN_003e9790(0);

      break;

    case 6:

      FUN_003ea560(0);

      break;

    case 7:

      FUN_003eacb0(0);

      break;

    case 8:

      FUN_003eb9b0(0);

      break;

    case 9:

      FUN_003ec030(0);

    }

  }

  return 1;

}

// FUN_004113F0 NONMATCHING


u32 FUN_004113f0(u64 param_1,int param_2,int param_3)



{

  u32 *puVar1;

  u32 uVar2;

  u32 *puVar3;

  int iVar4;

  int iVar5;

  short sVar6;

  

  puVar1 = *(u32 **)(param_2 + 0xc);

  if (param_3 != 0) {

    sVar6 = *(short *)((int)param_3 + 6);

    if (sVar6 == 4) {

      uVar2 = *puVar1;

      *puVar1 = uVar2 | 2;

      *puVar1 = uVar2 | 10;

      uVar2 = puVar1[5];

      puVar1[5] = uVar2 | 2;

      puVar1[5] = uVar2 | 10;

      uVar2 = puVar1[10];

      puVar1[10] = uVar2 | 2;

      puVar1[10] = uVar2 | 10;

      uVar2 = puVar1[0xf];

      puVar1[0xf] = uVar2 | 2;

      puVar1[0xf] = uVar2 | 10;

    }

    else if ((sVar6 != 2) && (sVar6 == 1)) {

      memset(puVar1,0,0x50);

      *(u16 *)((int)puVar1 + 0xe) = 0xff;

      uVar2 = *puVar1;

      *puVar1 = uVar2 | 1;

      *puVar1 = uVar2 & 0xfffffff7 | 1;

      *(u16 *)((int)puVar1 + 0x22) = 0xff;

      uVar2 = puVar1[5];

      puVar1[5] = uVar2 | 1;

      puVar1[5] = uVar2 & 0xfffffff7 | 1;

      *(u16 *)((int)puVar1 + 0x36) = 0xff;

      uVar2 = puVar1[10];

      puVar1[10] = uVar2 | 1;

      puVar1[10] = uVar2 & 0xfffffff7 | 1;

      *(u16 *)((int)puVar1 + 0x4a) = 0xff;

      uVar2 = puVar1[0xf];

      puVar1[0xf] = uVar2 | 1;

      puVar1[0xf] = uVar2 & 0xfffffff7 | 1;

      *(u16 *)(puVar1 + 0x14) = 0;

    }

  }

  sVar6 = (short)puVar1[0x14];

  if (((sVar6 != 2) && (sVar6 != 1)) && (sVar6 == 0)) {

    *(short *)((int)puVar1 + 0x52) = *(short *)((int)puVar1 + 0x52) + 1;

    iVar4 = 0;

    for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {

      puVar3 = puVar1 + iVar5 * 5;

      uVar2 = *puVar3;

      if ((uVar2 & 4) == 0) {

        if ((uVar2 & 1) == 0) {

          if ((uVar2 & 2) != 0) {

            sVar6 = *(short *)((int)puVar3 + 0x12) + 1;

            *(short *)((int)puVar3 + 0x12) = sVar6;

            *(short *)(puVar3 + 3) =

                 *(short *)((int)puVar3 + 0xe) -

                 (short)(((int)*(short *)((int)puVar3 + 0xe) * (int)sVar6) / 10);

            if (9 < *(short *)((int)puVar3 + 0x12)) {

              uVar2 = *puVar3;

              *puVar3 = uVar2 & 0xfffffffd;

              *puVar3 = uVar2 & 0xfffffffd | 4;

              *(u16 *)(puVar3 + 3) = 0;

              *(u16 *)((int)puVar3 + 0x12) = 0;

              *(u16 *)(puVar3 + 4) = 0x7e;

            }

          }

        }

        else {

          sVar6 = *(short *)((int)puVar3 + 0x12) + 1;

          *(short *)((int)puVar3 + 0x12) = sVar6;

          *(short *)(puVar3 + 3) = (short)(((int)*(short *)((int)puVar3 + 0xe) * (int)sVar6) / 10);

          if (9 < *(short *)((int)puVar3 + 0x12)) {

            *puVar3 = *puVar3 & 0xfffffffe;

            *(u16 *)(puVar3 + 3) = *(u16 *)((int)puVar3 + 0xe);

            *(u16 *)((int)puVar3 + 0x12) = 0;

          }

        }

      }

      else if ((uVar2 & 8) == 0) {

        sVar6 = (short)puVar3[4] + -1;

        *(short *)(puVar3 + 4) = sVar6;

        if (sVar6 < 1) {

          *(u16 *)(puVar3 + 4) = 0xff9c;

          uVar2 = *puVar3;

          *puVar3 = uVar2 & 0xfffffffb;

          *puVar3 = uVar2 & 0xfffffffb | 1;

        }

      }

      else {

        iVar4 = iVar4 + 1;

      }

    }

    if (3 < iVar4) {

      *(u16 *)(puVar1 + 0x14) = 1;

      return 2;

    }

  }

  return 1;

}

// FUN_00411710
u64 FUN_00411710(u64 param_1, int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar1 = *(int *)(param_2 + 0xc);
  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
    f32 zero;
    s16 valueA;
    s16 valueB;
    u8 flag;
    int code;

    iVar2 = iVar1 + iVar3 * 0x14;
    zero = 0.0f;
    valueA = *(s16 *)(iVar2 + 4);
    valueB = *(s16 *)(iVar2 + 6);
    asm volatile("" : "+r" (valueA), "+r" (valueB));
    code = iVar3 + 0x61;
    FUN_0040e3c0(zero, valueA, valueB, *(volatile u8 *)(iVar2 + 0xc), code, 0);
  }
  return 0;
}

// FUN_00411790 NONMATCHING


u32 FUN_00411790(u64 param_1,int param_2,long param_3)



{

  u32 *puVar1;

  float fVar2;

  u32 uVar3;

  short sVar4;

  short sVar5;

  int iVar6;

  float *pfVar7;

  float *pfVar8;

  u32 *puVar9;

  int iVar10;

  float fVar11;

  float afStack_30 [12];

  

  puVar1 = *(u32 **)(param_2 + 0xc);

  pfVar8 = (float *)&DAT_006b0020;

  pfVar7 = afStack_30;

  iVar6 = 5;

  do {

    fVar11 = *pfVar8;

    fVar2 = pfVar8[1];

    pfVar8 = pfVar8 + 2;

    iVar6 = iVar6 + -1;

    *pfVar7 = fVar11;

    pfVar7[1] = fVar2;

    pfVar7 = pfVar7 + 2;

  } while (0 < iVar6);

  if (param_3 != 0) {

    sVar4 = *(short *)((int)param_3 + 6);

    if (sVar4 == 0xc) {

      uVar3 = puVar1[0xf];

      puVar1[0xf] = uVar3 | 2;

      puVar1[0xf] = uVar3 | 10;

      uVar3 = puVar1[0x14];

      puVar1[0x14] = uVar3 | 2;

      puVar1[0x14] = uVar3 | 10;

    }

    else if (sVar4 == 7) {

      *(u16 *)(puVar1 + 0x19) = 0;

      *(u16 *)((int)puVar1 + 0x66) = 0;

      memset(puVar1,0,100);

      uVar3 = *puVar1;

      *puVar1 = uVar3 | 4;

      *puVar1 = uVar3 & 0xfffffff7 | 4;

      uVar3 = puVar1[5];

      puVar1[5] = uVar3 | 4;

      puVar1[5] = uVar3 & 0xfffffff7 | 4;

      uVar3 = puVar1[10];

      puVar1[10] = uVar3 | 4;

      puVar1[10] = uVar3 & 0xfffffff7 | 4;

      *(u16 *)(puVar1 + 0x11) = 0x19a0;

      *(u16 *)(puVar1 + 0x10) = 0x19a0;

      *(u16 *)((int)puVar1 + 0x46) = 0x2a0;

      *(u16 *)((int)puVar1 + 0x42) = 0x2a0;

      *(u16 *)((int)puVar1 + 0x4a) = 0xff;

      *(u16 *)(puVar1 + 0x13) = 2;

      uVar3 = puVar1[0xf];

      puVar1[0xf] = uVar3 | 4;

      puVar1[0xf] = uVar3 | 5;

      puVar1[0xf] = uVar3 & 0xfffffff7 | 5;

      *(u16 *)(puVar1 + 0x16) = 0x740;

      *(u16 *)(puVar1 + 0x15) = 0x740;

      *(u16 *)((int)puVar1 + 0x5a) = 0x1730;

      *(u16 *)((int)puVar1 + 0x56) = 0x1730;

      *(u16 *)((int)puVar1 + 0x5e) = 0xff;

      *(u16 *)(puVar1 + 0x18) = 6;

      uVar3 = puVar1[0x14];

      puVar1[0x14] = uVar3 | 4;

      puVar1[0x14] = uVar3 | 5;

      puVar1[0x14] = uVar3 & 0xfffffff7 | 5;

    }

    else if (sVar4 == 0xb) {

      uVar3 = puVar1[0xf];

      puVar1[0xf] = uVar3 | 2;

      puVar1[0xf] = uVar3 | 10;

      uVar3 = puVar1[0x14];

      puVar1[0x14] = uVar3 | 2;

      puVar1[0x14] = uVar3 | 10;

    }

    else if (sVar4 == 6) {

      *(u16 *)(puVar1 + 0x19) = 0;

      *(u16 *)((int)puVar1 + 0x66) = 0;

      memset(puVar1,0,100);

      uVar3 = *puVar1;

      *puVar1 = uVar3 | 4;

      *puVar1 = uVar3 & 0xfffffff7 | 4;

      uVar3 = puVar1[5];

      puVar1[5] = uVar3 | 4;

      puVar1[5] = uVar3 & 0xfffffff7 | 4;

      uVar3 = puVar1[10];

      puVar1[10] = uVar3 | 4;

      puVar1[10] = uVar3 & 0xfffffff7 | 4;

      *(u16 *)(puVar1 + 0x11) = 0x1ae0;

      *(u16 *)(puVar1 + 0x10) = 0x1ae0;

      *(u16 *)((int)puVar1 + 0x46) = 0x270;

      *(u16 *)((int)puVar1 + 0x42) = 0x270;

      *(u16 *)((int)puVar1 + 0x4a) = 0xff;

      *(u16 *)(puVar1 + 0x13) = 2;

      uVar3 = puVar1[0xf];

      puVar1[0xf] = uVar3 | 4;

      puVar1[0xf] = uVar3 | 5;

      puVar1[0xf] = uVar3 & 0xfffffff7 | 5;

      *(u16 *)(puVar1 + 0x16) = 0x740;

      *(u16 *)(puVar1 + 0x15) = 0x740;

      *(u16 *)((int)puVar1 + 0x5a) = 0x16f0;

      *(u16 *)((int)puVar1 + 0x56) = 0x16f0;

      *(u16 *)((int)puVar1 + 0x5e) = 0xff;

      *(u16 *)(puVar1 + 0x18) = 6;

      uVar3 = puVar1[0x14];

      puVar1[0x14] = uVar3 | 4;

      puVar1[0x14] = uVar3 | 5;

      puVar1[0x14] = uVar3 & 0xfffffff7 | 5;

    }

    else if (sVar4 == 10) {

      uVar3 = *puVar1;

      *puVar1 = uVar3 | 2;

      *puVar1 = uVar3 | 10;

      uVar3 = puVar1[5];

      puVar1[5] = uVar3 | 2;

      puVar1[5] = uVar3 | 10;

      uVar3 = puVar1[10];

      puVar1[10] = uVar3 | 2;

      puVar1[10] = uVar3 | 10;

    }

    else if (sVar4 == 5) {

      *(u16 *)(puVar1 + 0x19) = 0;

      *(u16 *)((int)puVar1 + 0x66) = 0;

      memset(puVar1,0,100);

      *(u16 *)(puVar1 + 2) = 0x1bf0;

      *(u16 *)(puVar1 + 1) = 0x1bf0;

      *(u16 *)((int)puVar1 + 10) = 0x3d0;

      *(u16 *)((int)puVar1 + 6) = 0x3d0;

      *(u16 *)((int)puVar1 + 0xe) = 0xff;

      *(u16 *)(puVar1 + 4) = 2;

      uVar3 = *puVar1;

      *puVar1 = uVar3 | 4;

      *puVar1 = uVar3 | 5;

      *puVar1 = uVar3 & 0xfffffff7 | 5;

      *(u16 *)(puVar1 + 7) = 0xb10;

      *(u16 *)(puVar1 + 6) = 0xb10;

      *(u16 *)((int)puVar1 + 0x1e) = 0x310;

      *(u16 *)((int)puVar1 + 0x1a) = 0x310;

      *(u16 *)((int)puVar1 + 0x22) = 0xff;

      *(u16 *)(puVar1 + 9) = 6;

      uVar3 = puVar1[5];

      puVar1[5] = uVar3 | 4;

      puVar1[5] = uVar3 | 5;

      puVar1[5] = uVar3 & 0xfffffff7 | 5;

      *(u16 *)(puVar1 + 0xc) = 0x1fe0;

      *(u16 *)(puVar1 + 0xb) = 0x1fe0;

      *(u16 *)((int)puVar1 + 0x32) = 0xfe0;

      *(u16 *)((int)puVar1 + 0x2e) = 0xfe0;

      *(u16 *)((int)puVar1 + 0x36) = 0xff;

      *(u16 *)(puVar1 + 0xe) = 0;

      uVar3 = puVar1[10];

      puVar1[10] = uVar3 | 4;

      puVar1[10] = uVar3 | 5;

      puVar1[10] = uVar3 & 0xfffffff7 | 5;

    }

  }

  sVar4 = (short)puVar1[0x19];

  if (((sVar4 != 2) && (sVar4 != 1)) && (sVar4 == 0)) {

    iVar6 = 0;

    for (iVar10 = 0; iVar10 < 5; iVar10 = iVar10 + 1) {

      puVar9 = puVar1 + iVar10 * 5;

      if ((*puVar9 & 4) == 0) {

        sVar4 = (short)puVar9[4] + 1;

        *(short *)(puVar9 + 4) = sVar4;

        if ((0x4f < sVar4) && ((*puVar9 & 2) == 0)) {

          *puVar9 = *puVar9 | 2;

        }

        *(short *)(puVar9 + 1) =

             (short)(int)((float)(int)(short)puVar9[1] +

                         ((float)(0xff - (short)puVar9[3]) * afStack_30[iVar10 * 2] * 64.0f) / 255.0f)

        ;

        *(short *)((int)puVar9 + 6) =

             (short)(int)((float)(int)*(short *)((int)puVar9 + 6) +

                         ((float)(0xff - (short)puVar9[3]) * afStack_30[iVar10 * 2 + 1] * 64.0f) /

                         255.0f);

        if ((*puVar9 & 1) == 0) {

          if ((*puVar9 & 2) != 0) {

            sVar5 = *(short *)((int)puVar9 + 0x12) + 1;

            *(short *)((int)puVar9 + 0x12) = sVar5;

            sVar4 = *(short *)((int)puVar9 + 0xe);

            fVar11 = (float)sinf_fclShop((fGpffff8110 * (float)(int)sVar5) / 14.0f);

            *(short *)(puVar9 + 3) =

                 (short)(int)(((float)(int)sVar4 + 0.0f) - (float)(int)sVar4 * fVar11);

            if (0xd < *(short *)((int)puVar9 + 0x12)) {

              uVar3 = *puVar9;

              *puVar9 = uVar3 & 0xfffffffd;

              *puVar9 = uVar3 & 0xfffffffd | 4;

              *(u16 *)(puVar9 + 3) = 0;

              *(u16 *)((int)puVar9 + 0x12) = 0;

              *(u16 *)(puVar9 + 4) = 0x19;

            }

          }

        }

        else {

          sVar4 = *(short *)((int)puVar9 + 0x12) + 1;

          *(short *)((int)puVar9 + 0x12) = sVar4;

          *(short *)(puVar9 + 3) = (short)(((int)*(short *)((int)puVar9 + 0xe) * (int)sVar4) / 10);

          if (9 < *(short *)((int)puVar9 + 0x12)) {

            *puVar9 = *puVar9 & 0xfffffffe;

            *(u16 *)(puVar9 + 3) = *(u16 *)((int)puVar9 + 0xe);

            *(u16 *)((int)puVar9 + 0x12) = 0;

          }

        }

      }

      else if ((*puVar9 & 8) == 0) {

        sVar4 = (short)puVar9[4] + -1;

        *(short *)(puVar9 + 4) = sVar4;

        if (sVar4 < 1) {

          *(u16 *)(puVar9 + 4) = 0;

          uVar3 = *puVar9;

          *puVar9 = uVar3 & 0xfffffffb;

          *puVar9 = uVar3 & 0xfffffffb | 1;

          *(short *)(puVar9 + 1) = (short)puVar9[2];

          *(u16 *)((int)puVar9 + 6) = *(u16 *)((int)puVar9 + 10);

        }

      }

      else {

        iVar6 = iVar6 + 1;

      }

    }

    if (4 < iVar6) {

      *(u16 *)(puVar1 + 0x19) = 1;

      return 2;

    }

  }

  return 1;

}

// FUN_00411EE0 NONMATCHING


u64 FUN_00411ee0(u64 param_1,int param_2)



{

  int iVar1;

  u32 uVar2;

  int iVar3;

  u32 *puVar4;

  u32 *puVar5;

  int iVar6;

  u32 auStack_20 [8];

  

  iVar1 = *(int *)(param_2 + 0xc);

  puVar5 = &DAT_006b0050;

  puVar4 = auStack_20;

  iVar3 = 5;

  do {

    uVar2 = *puVar5;

    puVar5 = puVar5 + 1;

    iVar3 = iVar3 + -1;

    *puVar4 = uVar2;

    puVar4 = puVar4 + 1;

  } while (0 < iVar3);

  for (iVar3 = 0; iVar3 < 5; iVar3 = iVar3 + 1) {

    iVar6 = iVar1 + iVar3 * 0x14;

    if (*(short *)(iVar6 + 0xc) != 0) {

      if (iVar3 == 3) {

        (*DAT_00960090)(8,1);

        (*DAT_00960090)(6,0);

        RpSkyRenderStateSet(3,(void *)0x3200d);

        FUN_0040d610(0,0x102,0x1d,0x80,2,0,1);

        (*DAT_00960090)(8,0);

        (*DAT_00960090)(6,1);

        RpSkyRenderStateSet(3,(void *)0x7000d);

      }

      FUN_0040e420(0x3f800000,0,uGpffff8208,uGpffff8208,*(short *)(iVar6 + 4) >> 4,

                   *(short *)(iVar6 + 6) >> 4,*(u8 *)(iVar6 + 0xc),auStack_20[iVar3],0,0,0);

    }

  }

  RpSkyRenderStateSet(2,(void *)0x44);

  RpSkyRenderStateSet(3,(void *)0x717fb);

  return 0;

}

/* W327 measured: opt_loop_invariants on normalized_diff 804 -> 786; object 1172/1248 -> 1164/1248 (without/with). */
#pragma opt_loop_invariants on
// FUN_004120A0 NONMATCHING


u32 FUN_004120a0(u64 param_1, int param_2, int param_3) { short sVar1;

int iVar2;

u32 uVar3;

u32 uVar4;

int iVar5;

int iVar6;

short *psVar7;

u16 *puVar8;

u32 *puVar9;

int iVar10;

int iVar11;

short asStack_100 [2];

float afStack_fc [14];

short asStack_c4 [4];

float afStack_bc [15];

short asStack_80 [2];

float afStack_7c [14];

short asStack_44 [4];

float afStack_3c [15];



iVar2 = *(int *)(param_2 + 0xc);

puVar9 = &DAT_006b0450;

psVar7 = asStack_80;

iVar5 = 0xf;

do {

  uVar4 = *puVar9;

  uVar3 = puVar9[1];

  puVar9 = puVar9 + 2;

  iVar5 = iVar5 + -1;

  *(u32 *)psVar7 = uVar4;

  *(u32 *)(psVar7 + 2) = uVar3;

  psVar7 = psVar7 + 4;

} while (0 < iVar5);

puVar9 = &DAT_006b04d0;

psVar7 = asStack_100;

iVar5 = 0xf;

do {

  uVar4 = *puVar9;

  uVar3 = puVar9[1];

  puVar9 = puVar9 + 2;

  iVar5 = iVar5 + -1;

  *(u32 *)psVar7 = uVar4;

  *(u32 *)(psVar7 + 2) = uVar3;

  psVar7 = psVar7 + 4;

} while (0 < iVar5);

if (param_3 != 0) {

  sVar1 = *(short *)((int)param_3 + 6);

  if (sVar1 == 4) {

    memcpy((void *)iVar2,asStack_100,0x3c);

    *(u16 *)(iVar2 + 0x3c) = 2;

    *(u16 *)(iVar2 + 0x3e) = 0;

  }

  else if ((sVar1 != 2) && (sVar1 == 1)) {

    memcpy((void *)iVar2,asStack_80,0x3c);

    *(u16 *)(iVar2 + 0x3c) = 0;

    *(u16 *)(iVar2 + 0x3e) = 0;

  }

}

sVar1 = *(short *)(iVar2 + 0x3c);

if (sVar1 == 2) {

  *(short *)(iVar2 + 0x3e) = *(short *)(iVar2 + 0x3e) + 1;

  iVar10 = 0;

  for (iVar5 = 0; iVar5 < 5; iVar5 = iVar5 + 1) {

    iVar11 = iVar5 * 0xc;

    puVar8 = (u16 *)(iVar2 + iVar11);

    if ((short)puVar8[3] <= *(short *)(iVar2 + 0x3e)) {

      iVar6 = (int)*(short *)(iVar2 + 0x3e) - (int)(short)puVar8[3];

      psVar7 = (short *)((int)afStack_bc + iVar11 + -2);

      sVar1 = *(short *)((int)afStack_bc + iVar11 + -2);

      if ((long)sVar1 < (long)iVar6) {

        iVar10 = iVar10 + 1;

      }

      else {

        *puVar8 = (short)(int)((float)(int)asStack_100[iVar5 * 6] +

                              (float)(iVar6 * ((int)asStack_c4[iVar5 * 6] -

                                              (int)asStack_100[iVar5 * 6])) / (float)(int)sVar1);

        puVar8[1] = (short)(int)((float)(int)asStack_100[iVar5 * 6 + 1] +

                                (float)(iVar6 * ((int)asStack_c4[iVar5 * 6 + 1] -

                                                (int)asStack_100[iVar5 * 6 + 1])) /

                                (float)(int)*psVar7);

        puVar8[2] = (short)(int)((float)(int)*(short *)(afStack_fc + iVar5 * 3) +

                                (float)(iVar6 * ((int)asStack_c4[iVar5 * 6 + 2] -

                                                (int)*(short *)(afStack_fc + iVar5 * 3))) /

                                (float)(int)*psVar7);

        *(float *)(puVar8 + 4) =

             afStack_fc[iVar5 * 3 + 1] +

             ((float)iVar6 * (afStack_bc[iVar5 * 3] - afStack_fc[iVar5 * 3 + 1])) /

             (float)(int)*psVar7;

      }

    }

  }

  if (iVar10 < 5) {

    uVar4 = 0;

  }

  else {

    *(u16 *)(iVar2 + 0x3c) = 1;

    *(u16 *)(iVar2 + 0x3e) = 0;

    uVar4 = 2;

  }

}

else if ((sVar1 == 1) || (sVar1 != 0)) {

  uVar4 = 1;

}

else {

  *(short *)(iVar2 + 0x3e) = *(short *)(iVar2 + 0x3e) + 1;

  iVar5 = 0;

  for (iVar10 = 0; iVar10 < 5; iVar10 = iVar10 + 1) {

    iVar11 = iVar10 * 0xc;

    puVar8 = (u16 *)(iVar2 + iVar11);

    if ((short)puVar8[3] <= *(short *)(iVar2 + 0x3e)) {

      iVar6 = (int)*(short *)(iVar2 + 0x3e) - (int)(short)puVar8[3];

      psVar7 = (short *)((int)afStack_3c + iVar11 + -2);

      sVar1 = *(short *)((int)afStack_3c + iVar11 + -2);

      if ((long)sVar1 < (long)iVar6) {

        iVar5 = iVar5 + 1;

      }

      else {

        *puVar8 = (short)(int)((float)(int)asStack_80[iVar10 * 6] +

                              (float)(iVar6 * ((int)asStack_44[iVar10 * 6] -

                                              (int)asStack_80[iVar10 * 6])) / (float)(int)sVar1);

        puVar8[1] = (short)(int)((float)(int)asStack_80[iVar10 * 6 + 1] +

                                (float)(iVar6 * ((int)asStack_44[iVar10 * 6 + 1] -

                                                (int)asStack_80[iVar10 * 6 + 1])) /

                                (float)(int)*psVar7);

        puVar8[2] = (short)(int)((float)(int)*(short *)(afStack_7c + iVar10 * 3) +

                                (float)(iVar6 * ((int)asStack_44[iVar10 * 6 + 2] -

                                                (int)*(short *)(afStack_7c + iVar10 * 3))) /

                                (float)(int)*psVar7);

        *(float *)(puVar8 + 4) =

             afStack_7c[iVar10 * 3 + 1] +

             ((float)iVar6 * (afStack_3c[iVar10 * 3] - afStack_7c[iVar10 * 3 + 1])) /

             (float)(int)*psVar7;

      }

    }

  }

  if (4 < iVar5) {

    *(u16 *)(iVar2 + 0x3c) = 1;

    *(u16 *)(iVar2 + 0x3e) = 0;

  }

  uVar4 = 0;

}

return uVar4; }

#pragma opt_loop_invariants reset
// FUN_00412580
#pragma push
#pragma opt_propagation off
u64 FUN_00412580(u64 param_1,int param_2)
{
  int work;
  s16 *entry;
  int i;
  float scale;
  float zero;
  s32 x;
  s32 y;
  u8 alpha;
  s32 extra0;
  s32 extra1;
  s32 extra2;
  s32 spriteId;

  work = *(int *)(param_2 + 0xc);
  for (i = 0; i < 5; i = i + 1) {
    entry = (s16 *)(work + i * 0xc);
    scale = *(float *)(entry + 4);
    x = *entry;
    y = entry[1];
    zero = 0.0f;
    alpha = *(u8 *)(entry + 2);
    spriteId = i + 0x51;
    extra0 = 0;
    extra1 = 0;
    extra2 = 0;
    FUN_0040e3f0_typed(zero,zero,scale,scale,x,y,alpha,spriteId,extra0,extra1,extra2);
  }
  return 0;
}
#pragma pop

// FUN_00412610 NONMATCHING


u32 FUN_00412610(u64 param_1, int param_2, long param_3) { short sVar1;

int iVar2;

u32 uVar3;

u32 uVar4;

int iVar5;

int iVar6;

short *psVar7;

u16 *puVar8;

u32 *puVar9;

int iVar10;

short asStack_c0 [2];
float afStack_bc [11];
float afStack_90 [12];
short asStack_60 [2];
float afStack_5c [11];
float afStack_30 [12];



iVar2 = *(int *)(param_2 + 0xc);

puVar9 = &DAT_006b0a00;

psVar7 = asStack_60;

iVar5 = 0xc;

do {

  uVar4 = *puVar9;

  uVar3 = puVar9[1];

  puVar9 = puVar9 + 2;

  iVar5 = iVar5 + -1;

  *(u32 *)psVar7 = uVar4;

  *(u32 *)(psVar7 + 2) = uVar3;

  psVar7 = psVar7 + 4;

} while (0 < iVar5);

puVar9 = &DAT_006b0a60;

psVar7 = asStack_c0;

iVar5 = 0xc;

do {

  uVar4 = *puVar9;

  uVar3 = puVar9[1];

  puVar9 = puVar9 + 2;

  iVar5 = iVar5 + -1;

  *(u32 *)psVar7 = uVar4;

  *(u32 *)(psVar7 + 2) = uVar3;

  psVar7 = psVar7 + 4;

} while (0 < iVar5);

if (param_3 != 0) {

  sVar1 = *(short *)((int)param_3 + 6);

  if (sVar1 == 4) {

    memcpy((void *)iVar2,asStack_c0,0x30);

    *(u16 *)(iVar2 + 0x30) = 2;

    *(u16 *)(iVar2 + 0x32) = 0;

  }

  else if ((sVar1 != 2) && (sVar1 == 1)) {

    memcpy((void *)iVar2,asStack_60,0x30);

    *(u16 *)(iVar2 + 0x30) = 0;

    *(u16 *)(iVar2 + 0x32) = 0;

  }

}

sVar1 = *(short *)(iVar2 + 0x30);

if (sVar1 == 2) {

  *(short *)(iVar2 + 0x32) = *(short *)(iVar2 + 0x32) + 1;

  iVar10 = 0;

  for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {

    puVar8 = (u16 *)(iVar2 + iVar5 * 0xc);

    if ((short)puVar8[3] <= *(short *)(iVar2 + 0x32)) {

      iVar6 = (int)*(short *)(iVar2 + 0x32) - (int)(short)puVar8[3];

      psVar7 = (short *)((int)afStack_90 + (iVar5 * 6 + 3) * 2);

      sVar1 = *(short *)((int)afStack_90 + (iVar5 * 6 + 3) * 2);

      if ((long)sVar1 < (long)iVar6) {

        iVar10 = iVar10 + 1;

      }

      else {

        *puVar8 = (short)(int)((float)(int)asStack_c0[iVar5 * 6] +

                              (float)(iVar6 * ((int)*(short *)(afStack_90 + iVar5 * 3) -

                                              (int)asStack_c0[iVar5 * 6])) / (float)(int)sVar1);

        puVar8[1] = (short)(int)((float)(int)asStack_c0[iVar5 * 6 + 1] +

                                (float)(iVar6 * ((int)*(short *)((int)afStack_90 +

                                                                (iVar5 * 6 + 1) * 2) -

                                                (int)asStack_c0[iVar5 * 6 + 1])) /

                                (float)(int)*psVar7);

        puVar8[2] = (short)(int)((float)(int)*(short *)(afStack_bc + iVar5 * 3) +

                                (float)(iVar6 * ((int)*(short *)(afStack_90 + iVar5 * 3 + 1) -

                                                (int)*(short *)(afStack_bc + iVar5 * 3))) /

                                (float)(int)*psVar7);

        *(float *)(puVar8 + 4) =

             afStack_bc[iVar5 * 3 + 1] +

             ((float)iVar6 * (afStack_90[iVar5 * 3 + 2] - afStack_bc[iVar5 * 3 + 1])) /

             (float)(int)*psVar7;

      }

    }

  }

  if (iVar10 < 4) {

    uVar4 = 0;

  }

  else {

    *(u16 *)(iVar2 + 0x30) = 1;

    *(u16 *)(iVar2 + 0x32) = 0;

    uVar4 = 2;

  }

}

else if ((sVar1 == 1) || (sVar1 != 0)) {

  uVar4 = 1;

}

else {

  *(short *)(iVar2 + 0x32) = *(short *)(iVar2 + 0x32) + 1;

  iVar5 = 0;

  for (iVar10 = 0; iVar10 < 4; iVar10 = iVar10 + 1) {

    puVar8 = (u16 *)(iVar2 + iVar10 * 0xc);

    if ((short)puVar8[3] <= *(short *)(iVar2 + 0x32)) {

      iVar6 = (int)*(short *)(iVar2 + 0x32) - (int)(short)puVar8[3];

      psVar7 = (short *)((int)afStack_30 + (iVar10 * 6 + 3) * 2);

      sVar1 = *(short *)((int)afStack_30 + (iVar10 * 6 + 3) * 2);

      if ((long)sVar1 < (long)iVar6) {

        iVar5 = iVar5 + 1;

      }

      else {

        *puVar8 = (short)(int)((float)(int)asStack_60[iVar10 * 6] +

                              (float)(iVar6 * ((int)*(short *)(afStack_30 + iVar10 * 3) -

                                              (int)asStack_60[iVar10 * 6])) / (float)(int)sVar1);

        puVar8[1] = (short)(int)((float)(int)asStack_60[iVar10 * 6 + 1] +

                                (float)(iVar6 * ((int)*(short *)((int)afStack_30 +

                                                                (iVar10 * 6 + 1) * 2) -

                                                (int)asStack_60[iVar10 * 6 + 1])) /

                                (float)(int)*psVar7);

        puVar8[2] = (short)(int)((float)(int)*(short *)(afStack_5c + iVar10 * 3) +

                                (float)(iVar6 * ((int)*(short *)(afStack_30 + iVar10 * 3 + 1) -

                                                (int)*(short *)(afStack_5c + iVar10 * 3))) /

                                (float)(int)*psVar7);

        *(float *)(puVar8 + 4) =

             afStack_5c[iVar10 * 3 + 1] +

             ((float)iVar6 * (afStack_30[iVar10 * 3 + 2] - afStack_5c[iVar10 * 3 + 1])) /

             (float)(int)*psVar7;

      }

    }

  }

  if (3 < iVar5) {

    *(u16 *)(iVar2 + 0x30) = 1;

    *(u16 *)(iVar2 + 0x32) = 0;

  }

  uVar4 = 0;

}

return uVar4; }

// FUN_00412AF0
#pragma push
#pragma opt_propagation off
u64 FUN_00412af0(u64 param_1,int param_2)



{

  int iVar1;
  s16 *puVar2;
  int iVar3;
  float fVar3;
  float fVar2;
  float fVar1;
  float fVar0;
  float afStack_10[4];
  float scale;
  float zero;
  s32 x;
  s32 y;
  u8 alpha;
  s32 spriteId;
  s32 extra0;
  s32 extra1;
  s32 extra2;

  

  iVar1 = *(int *)(param_2 + 0xc);

  fVar3 = *(float *)DAT_006b0ac0_abs;
  fVar2 = *(float *)DAT_006b0ac4_abs;
  fVar1 = *(float *)DAT_006b0ac8_abs;
  fVar0 = *(float *)DAT_006b0acc_abs;
  afStack_10[0] = fVar3;
  afStack_10[1] = fVar2;
  afStack_10[2] = fVar1;
  afStack_10[3] = fVar0;

  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
    puVar2 = (s16 *)(iVar1 + iVar3 * 0xc);
    scale = *(float *)(puVar2 + 4);
    x = *puVar2;
    y = puVar2[1];
    zero = 0.0f;
    alpha = *(u8 *)(puVar2 + 2);
    spriteId = *(s32 *)&afStack_10[iVar3];
    extra0 = 0;
    extra1 = 0;
    extra2 = 0;
    FUN_0040e3f0_typed(zero,zero,scale,scale,x,y,alpha,spriteId,extra0,extra1,extra2);
  }

  return 0;
}
#pragma pop


// FUN_00412BC0 NONMATCHING


u32 FUN_00412bc0(u64 param_1, int param_2, long param_3) { short sVar1;

int iVar2;

u32 uVar3;

u32 uVar4;

u32 uVar5;

u32 in_v0_lo;

short *psVar6;

int iVar7;

int iVar8;

u16 *puVar9;

u32 *puVar10;

u32 *puVar11;

u32 uVar12;

int iVar13;

int iVar14;

short *psVar15;

float fVar16;

u32 *puStack_310;

u32 uStack_30c;

u32 *puStack_308;

u32 uStack_304;

u32 auStack_300 [72];

u32 auStack_1e0 [120];



iVar2 = *(int *)(param_2 + 0xc);

puVar11 = &DAT_006b0ad0;

puVar10 = auStack_1e0;

iVar8 = 0x3c;

do {

  uVar3 = *puVar11;

  uVar4 = puVar11[1];

  puVar11 = puVar11 + 2;

  iVar8 = iVar8 + -1;

  *puVar10 = uVar3;

  puVar10[1] = uVar4;

  puVar10 = puVar10 + 2;

} while (0 < iVar8);

puVar11 = &DAT_006b0cb0;

puVar10 = auStack_300;

iVar8 = 0x24;

do {

  uVar3 = *puVar11;

  uVar4 = puVar11[1];

  puVar11 = puVar11 + 2;

  iVar8 = iVar8 + -1;

  *puVar10 = uVar3;

  puVar10[1] = uVar4;

  puVar10 = puVar10 + 2;

} while (0 < iVar8);

uStack_30c = DAT_006b0dd4;

uStack_304 = DAT_006b0ddc;

puStack_310 = auStack_1e0;

puStack_308 = auStack_300;

if (param_3 != 0) {

  sVar1 = *(short *)((int)param_3 + 6);

  if (sVar1 == 10) {

    in_v0_lo = 3;

  }

  else if (sVar1 == 5) {

    in_v0_lo = 2;

  }

  else if (sVar1 == 4) {

    in_v0_lo = 1;

  }

  else if (sVar1 == 1) {

    in_v0_lo = 0;

  }

  *(u32 *)(iVar2 + 0x7c) = in_v0_lo;

  memcpy((void *)iVar2,(&puStack_310)[((int)in_v0_lo >> 1) * 2] +
                     (in_v0_lo & 1) * 2 * ((&uStack_30c)[((int)in_v0_lo >> 1) * 2] >> 2) * 3,
               ((&uStack_30c)[((int)in_v0_lo >> 1) * 2] >> 2) * 0xc);

  *(u16 *)(iVar2 + 0x78) = 0;

  *(u16 *)(iVar2 + 0x7a) = 0;

}

uVar5 = *(u32 *)(iVar2 + 0x7c);

iVar8 = (int)uVar5 >> 1;

if (*(short *)(iVar2 + 0x78) == 1) {

  puVar10 = (&puStack_310)[iVar8 * 2];

  uVar12 = (&uStack_30c)[iVar8 * 2];

  for (iVar8 = 0; iVar8 < (int)(uVar12 >> 2); iVar8 = iVar8 + 1) {

    iVar13 = iVar2 + iVar8 * 0xc;

    fVar16 = *(float *)(iVar13 + 8) +

             (float)puVar10[((uVar5 & 1) * 2 + 1) * (uVar12 >> 2) * 3 + iVar8 * 3 + 2];

    *(float *)(iVar13 + 8) = fVar16;

    if (fVar16 < 0.0f) {

      *(float *)(iVar13 + 8) = fVar16 + fGpffff8110;

    }

  }

}

else if (*(short *)(iVar2 + 0x78) == 0) {

  puVar10 = (&puStack_310)[iVar8 * 2];

  uVar12 = (&uStack_30c)[iVar8 * 2] >> 2;

  *(short *)(iVar2 + 0x7a) = *(short *)(iVar2 + 0x7a) + 1;

  iVar13 = 0;

  iVar8 = (uVar5 & 1) * 2;

  for (iVar14 = 0; iVar14 < (int)uVar12; iVar14 = iVar14 + 1) {

    puVar9 = (u16 *)(iVar2 + iVar14 * 0xc);

    if ((short)puVar9[3] <= *(short *)(iVar2 + 0x7a)) {

      iVar7 = (int)*(short *)(iVar2 + 0x7a) - (int)(short)puVar9[3];

      psVar6 = (short *)(puVar10 + (iVar8 + 1) * uVar12 * 3 + iVar14 * 3);

      if ((long)psVar6[3] < (long)iVar7) {

        iVar13 = iVar13 + 1;

      }

      else {

        psVar15 = (short *)(puVar10 + iVar8 * uVar12 * 3 + iVar14 * 3);

        *puVar9 = (short)(int)((float)(int)*psVar15 +

                              (float)(iVar7 * ((int)*psVar6 - (int)*psVar15)) /

                              (float)(int)psVar6[3]);

        puVar9[1] = (short)(int)((float)(int)psVar15[1] +

                                (float)(iVar7 * ((int)psVar6[1] - (int)psVar15[1])) /

                                (float)(int)psVar6[3]);

        puVar9[2] = (short)(int)((float)(int)psVar15[2] +

                                (float)(iVar7 * ((int)psVar6[2] - (int)psVar15[2])) /

                                (float)(int)psVar6[3]);

      }

    }

  }

  if ((int)uVar12 <= iVar13) {

    *(u16 *)(iVar2 + 0x78) = 1;

    *(u16 *)(iVar2 + 0x7a) = 0;

    if ((uVar5 & 1) != 0) {

      return 2;

    }

  }

  return 0;

}

return 1; }

#pragma opt_propagation off
/* Measured normalized_diff 154 -> 153; object_size remains 400B. */
#pragma opt_lifetimes on
// FUN_00413010 NONMATCHING


u64 FUN_00413010(u64 param_1,int param_2)



{

  s16 uVar1;

  s16 uVar2;

  short sVar3;

  int iVar4;

  int iVar5;

  s16 *puVar6;



  int iVar10;

  int iVar11;

  FclShopBgLocal stack;

  float fStack_0;
  float fStack_4;
  float fStack_8;
  float fStack_c;




  

  iVar4 = *(int *)(param_2 + 0xc);

  {
    s16 *src;
    s16 *dst;
    int count;

    src = (s16 *)DAT_006b0de0_abs;
    dst = stack.table1;
    count = 0x14;

    do {
      uVar1 = *src;
      uVar2 = src[1];
      src = src + 2;
      count = count + -1;
      *dst = uVar1;
      dst[1] = uVar2;
      dst = dst + 2;
    } while (0 < count);
  }

  {
    s16 *src;
    s16 *dst;
    int count;

    src = (s16 *)DAT_006b0e30_abs;
    dst = stack.table2;
    count = 0xc;

    do {
      uVar1 = *src;
      uVar2 = src[1];
      src = src + 2;
      count = count + -1;
      *dst = uVar1;
      dst[1] = uVar2;
      dst = dst + 2;
    } while (0 < count);
  }

  fStack_0 = *(float *)((u8 *)DAT_006b0e64_abs - 4);
  fStack_4 = *(float *)DAT_006b0e64_abs;
  fStack_8 = *(float *)((u8 *)DAT_006b0e64_abs + 4);
  fStack_c = *(float *)((u8 *)DAT_006b0e64_abs + 8);
  *(float *)((u8 *)&stack + 0) = fStack_0;
  *(float *)((u8 *)&stack + 4) = fStack_4;
  *(float *)((u8 *)&stack + 8) = fStack_8;
  *(float *)((u8 *)&stack + 0xc) = fStack_c;

  *(u32 *)((u8 *)&stack + 0) = (u32)stack.table1;

  *(u32 *)((u8 *)&stack + 8) = (u32)stack.table2;

  iVar5 = *(int *)(iVar4 + 0x7c) >> 1;

  puVar6 = (s16 *)*(u32 *)((u8 *)&stack + iVar5 * 8);

  iVar5 = *(int *)((u8 *)&stack + iVar5 * 8 + 4);


  for (iVar11 = 0; iVar11 < iVar5; iVar11 = iVar11 + 1) {
    short *psVar9;
    s16 *psVar8;

    psVar9 = (short *)(iVar4 + iVar11 * 0xc);

    psVar8 = (s16 *)(puVar6 + iVar11 * 4);

    sVar3 = psVar8[2];
    iVar10 = (int)sVar3 >> 1;

    FUN_0040e3f0_typed(0.0f,fGpffff80d0 * *(float *)(psVar9 + 4),1.0f,1.0f,

                 ((int)*psVar9 + (int)*psVar8) - (int)sVar3,

                 ((int)psVar9[1] + (int)psVar8[1]) - (int)sVar3,(char)psVar9[2],psVar8[3],0,iVar10,

                 iVar10);

  }

  return 0;

}

#pragma opt_propagation on
/* W327 measured: opt_loop_invariants on normalized_diff 792 -> 780; object 1172/1248 -> 1164/1248 (without/with). */
#pragma opt_loop_invariants on
#pragma opt_lifetimes reset
// FUN_004131A0 NONMATCHING


u32 FUN_004131a0(u64 param_1, int param_2, int param_3) { short sVar1;

int iVar2;

u32 uVar3;

u32 uVar4;

int iVar5;

int iVar6;

short *psVar7;

u16 *puVar8;

u32 *puVar9;

int iVar10;

int iVar11;

short asStack_a0 [2];

float afStack_9c [8];

short asStack_7c [4];

float afStack_74 [9];

short asStack_50 [2];

float afStack_4c [8];

short asStack_2c [4];

float afStack_24 [9];



iVar2 = *(int *)(param_2 + 0xc);

puVar9 = &DAT_006b10e0;

psVar7 = asStack_50;

iVar5 = 9;

do {

  uVar4 = *puVar9;

  uVar3 = puVar9[1];

  puVar9 = puVar9 + 2;

  iVar5 = iVar5 + -1;

  *(u32 *)psVar7 = uVar4;

  *(u32 *)(psVar7 + 2) = uVar3;

  psVar7 = psVar7 + 4;

} while (0 < iVar5);

puVar9 = &DAT_006b1130;

psVar7 = asStack_a0;

iVar5 = 9;

do {

  uVar4 = *puVar9;

  uVar3 = puVar9[1];

  puVar9 = puVar9 + 2;

  iVar5 = iVar5 + -1;

  *(u32 *)psVar7 = uVar4;

  *(u32 *)(psVar7 + 2) = uVar3;

  psVar7 = psVar7 + 4;

} while (0 < iVar5);

if (param_3 != 0) {

  sVar1 = *(short *)((int)param_3 + 6);

  if (sVar1 == 4) {

    memcpy((void *)iVar2,asStack_a0,0x24);

    *(u16 *)(iVar2 + 0x24) = 2;

    *(u16 *)(iVar2 + 0x26) = 0;

  }

  else if ((sVar1 != 2) && (sVar1 == 1)) {

    memcpy((void *)iVar2,asStack_50,0x24);

    *(u16 *)(iVar2 + 0x24) = 0;

    *(u16 *)(iVar2 + 0x26) = 0;

  }

}

sVar1 = *(short *)(iVar2 + 0x24);

if (sVar1 == 2) {

  *(short *)(iVar2 + 0x26) = *(short *)(iVar2 + 0x26) + 1;

  iVar10 = 0;

  for (iVar5 = 0; iVar5 < 3; iVar5 = iVar5 + 1) {

    iVar11 = iVar5 * 0xc;

    puVar8 = (u16 *)(iVar2 + iVar11);

    if ((short)puVar8[3] <= *(short *)(iVar2 + 0x26)) {

      iVar6 = (int)*(short *)(iVar2 + 0x26) - (int)(short)puVar8[3];

      psVar7 = (short *)((int)afStack_74 + iVar11 + -2);

      sVar1 = *(short *)((int)afStack_74 + iVar11 + -2);

      if ((long)sVar1 < (long)iVar6) {

        iVar10 = iVar10 + 1;

      }

      else {

        *puVar8 = (short)(int)((float)(int)asStack_a0[iVar5 * 6] +

                              (float)(iVar6 * ((int)asStack_7c[iVar5 * 6] -

                                              (int)asStack_a0[iVar5 * 6])) / (float)(int)sVar1);

        puVar8[1] = (short)(int)((float)(int)asStack_a0[iVar5 * 6 + 1] +

                                (float)(iVar6 * ((int)asStack_7c[iVar5 * 6 + 1] -

                                                (int)asStack_a0[iVar5 * 6 + 1])) /

                                (float)(int)*psVar7);

        puVar8[2] = (short)(int)((float)(int)*(short *)(afStack_9c + iVar5 * 3) +

                                (float)(iVar6 * ((int)asStack_7c[iVar5 * 6 + 2] -

                                                (int)*(short *)(afStack_9c + iVar5 * 3))) /

                                (float)(int)*psVar7);

        *(float *)(puVar8 + 4) =

             afStack_9c[iVar5 * 3 + 1] +

             ((float)iVar6 * (afStack_74[iVar5 * 3] - afStack_9c[iVar5 * 3 + 1])) /

             (float)(int)*psVar7;

      }

    }

  }

  if (iVar10 < 3) {

    uVar4 = 0;

  }

  else {

    *(u16 *)(iVar2 + 0x24) = 1;

    *(u16 *)(iVar2 + 0x26) = 0;

    uVar4 = 2;

  }

}

else if ((sVar1 == 1) || (sVar1 != 0)) {

  uVar4 = 1;

}

else {

  *(short *)(iVar2 + 0x26) = *(short *)(iVar2 + 0x26) + 1;

  iVar5 = 0;

  for (iVar10 = 0; iVar10 < 3; iVar10 = iVar10 + 1) {

    iVar11 = iVar10 * 0xc;

    puVar8 = (u16 *)(iVar2 + iVar11);

    if ((short)puVar8[3] <= *(short *)(iVar2 + 0x26)) {

      iVar6 = (int)*(short *)(iVar2 + 0x26) - (int)(short)puVar8[3];

      psVar7 = (short *)((int)afStack_24 + iVar11 + -2);

      sVar1 = *(short *)((int)afStack_24 + iVar11 + -2);

      if ((long)sVar1 < (long)iVar6) {

        iVar5 = iVar5 + 1;

      }

      else {

        *puVar8 = (short)(int)((float)(int)asStack_50[iVar10 * 6] +

                              (float)(iVar6 * ((int)asStack_2c[iVar10 * 6] -

                                              (int)asStack_50[iVar10 * 6])) / (float)(int)sVar1);

        puVar8[1] = (short)(int)((float)(int)asStack_50[iVar10 * 6 + 1] +

                                (float)(iVar6 * ((int)asStack_2c[iVar10 * 6 + 1] -

                                                (int)asStack_50[iVar10 * 6 + 1])) /

                                (float)(int)*psVar7);

        puVar8[2] = (short)(int)((float)(int)*(short *)(afStack_4c + iVar10 * 3) +

                                (float)(iVar6 * ((int)asStack_2c[iVar10 * 6 + 2] -

                                                (int)*(short *)(afStack_4c + iVar10 * 3))) /

                                (float)(int)*psVar7);

        *(float *)(puVar8 + 4) =

             afStack_4c[iVar10 * 3 + 1] +

             ((float)iVar6 * (afStack_24[iVar10 * 3] - afStack_4c[iVar10 * 3 + 1])) /

             (float)(int)*psVar7;

      }

    }

  }

  if (2 < iVar5) {

    *(u16 *)(iVar2 + 0x24) = 1;

    *(u16 *)(iVar2 + 0x26) = 0;

  }

  uVar4 = 0;

}

return uVar4; }

#pragma opt_loop_invariants reset
// FUN_00413680 NONMATCHING


u64 FUN_00413680(u64 param_1,int param_2)



{

  short sVar1;

  short sVar2;

  short sVar3;

  int iVar4;

  int iVar5;

  short *psVar6;

  short *psVar7;

  short *psVar8;

  float fVar9;

  float fVar10;

  int iVar11;

  int iVar12;

  float fVar13;

  float fVar14;

  short asStack_10 [8];

  

  iVar4 = *(int *)(param_2 + 0xc);

  psVar7 = (short *)0x006b1178;

  psVar6 = asStack_10;

  iVar5 = 3;

  do {

    sVar1 = *psVar7;

    sVar2 = psVar7[1];

    psVar7 = psVar7 + 2;

    iVar5 = iVar5 + -1;

    *psVar6 = sVar1;

    psVar6[1] = sVar2;

    psVar6 = psVar6 + 2;

  } while (0 < iVar5);

  for (iVar5 = 0; iVar5 < 3; iVar5 = iVar5 + 1) {

    psVar8 = (short *)(iVar4 + iVar5 * 0xc);

    if (iVar5 < 2) {

      fVar14 = fGpffff8204 * *(float *)(psVar8 + 4);

      sVar3 = *psVar8;

      fVar9 = (float)cosf_fclShop(fVar14);

      fVar13 = (float)(int)sVar3;

      fVar10 = (float)sinf_fclShop(fVar14);

      iVar11 = (int)((float)(int)sVar3 - (fVar13 * fVar9 + (float)(int)psVar8[1] * fVar10));

      fVar9 = (float)sinf_fclShop(fVar14);

      fVar13 = (float)-(int)*psVar8;

      fVar10 = (float)cosf_fclShop(fVar14);

      iVar12 = (int)((float)(int)psVar8[1] - (fVar13 * fVar9 + (float)(int)psVar8[1] * fVar10));

      FUN_0040e3c0(0,iVar11,iVar12,*(u8 *)(psVar8 + 2),asStack_10[iVar5],0);

      FUN_0040e3c0(0,iVar11,iVar12,*(u8 *)(psVar8 + 2),asStack_10[iVar5 + 3],0);

    }

    else {

      FUN_0040e3f0(0,0,*(u32 *)(psVar8 + 4),*(u32 *)(psVar8 + 4),*psVar8,psVar8[1],

                   (char)psVar8[2],asStack_10[iVar5],0,0,0);

      FUN_0040e3f0(0,0,*(u32 *)(psVar8 + 4),*(u32 *)(psVar8 + 4),*psVar8,psVar8[1],

                   (char)psVar8[2],asStack_10[iVar5 + 3],0,0,0);

    }

  }

  return 0;

}

// FUN_004138E0 NONMATCHING


u64 FUN_004138e0(u64 param_1,int param_2,long param_3)



{

  short *psVar1;

  short sVar2;

  u64 uVar3;

  float afStack_8 [2];

  

  psVar1 = *(short **)(param_2 + 0xc);

  afStack_8[0] = fGpffffad18;

  afStack_8[1] = (float)uGpffffad1c;

  if ((param_3 != 0) && (sVar2 = *(short *)((int)param_3 + 6), sVar2 != 2)) {

    if (sVar2 == 10) {

      psVar1[5] = 0;

      *(u32 *)(psVar1 + 2) = uGpffffad1c;

      psVar1[4] = 0xff;

      *psVar1 = 2;

      psVar1[1] = 0;

    }

    else if (sVar2 == 5) {

      psVar1[5] = 0;

      *(float *)(psVar1 + 2) = fGpffffad18;

      psVar1[4] = 0;

      *psVar1 = 0;

      psVar1[1] = 0;

    }

  }

  sVar2 = *psVar1;

  uVar3 = 2;

  if (sVar2 == 2) {

    sVar2 = psVar1[1] + 1;

    psVar1[1] = sVar2;

    *(float *)(psVar1 + 2) =

         afStack_8[psVar1[5] * 2] +

         ((float)(int)sVar2 * (afStack_8[psVar1[5] * 2 + 1] - afStack_8[psVar1[5] * 2])) / 6.0f;

    psVar1[4] = (short)(int)((float)((int)sVar2 + sVar2 * -0x100) / 6.0f + 255.0f);

    if (sVar2 < 6) {

      uVar3 = 0;

    }

    else {

      *psVar1 = 1;

      psVar1[1] = 0;

    }

  }

  else if ((sVar2 == 1) || (sVar2 != 0)) {

    uVar3 = 1;

  }

  else {

    sVar2 = psVar1[1] + 1;

    psVar1[1] = sVar2;

    *(float *)(psVar1 + 2) =

         afStack_8[psVar1[5] * 2] +

         ((float)(int)sVar2 * (afStack_8[psVar1[5] * 2 + 1] - afStack_8[psVar1[5] * 2])) / 8.0f;

    psVar1[4] = (short)(int)((float)(sVar2 * 0x100 - (int)sVar2) / 8.0f);

    if (7 < sVar2) {

      *psVar1 = 1;

      psVar1[1] = 0;

    }

    uVar3 = 0;

  }

  return uVar3;

}

// FUN_00413B10
#pragma push
#pragma opt_propagation off


u64 FUN_00413b10(u64 param_1,int param_2)
{
  volatile u8 *puVar1;
  float zero;
  float fVar3;
  float one;
  s32 x;
  s32 y;
  s32 a3;
  s32 t0;
  s32 t1;
  s32 t2;
  u8 bVar2;

  puVar1 = *(u8 **)(param_2 + 0xc);
  zero = 0.0f;
  bVar2 = puVar1[8];
  fVar3 = fGpffff80d0 * *(float *)(puVar1 + 4);
  one = 1.0f;
  x = 0;
  y = 0;
  a3 = 0x68;
  t0 = 0;
  t1 = 0x74;
  t2 = 0x7d;
  FUN_0040e3f0_typed(zero, fVar3, one, one, x, y, bVar2,
                     a3, t0, t1, t2);
  return 0;
}
#pragma pop




/* W327 measured: opt_loop_invariants on normalized_diff 1006 -> 986; object 1404/1424 -> 1404/1424 (without/with). */
#pragma opt_loop_invariants on
// FUN_00413B70 NONMATCHING


u32 FUN_00413b70(u64 param_1, int param_2, int param_3) { int iVar1;

u32 uVar2;

u32 *puVar3;

int iVar4;

short *psVar5;

u32 uVar6;

u64 uVar7;

short *psVar8;

int iVar9;

short *psVar10;

u32 *puVar11;

u32 **ppuVar12;

int iVar13;

u32 *puVar14;

u16 *puVar15;

u32 uVar16;

int iVar17;

u32 uVar18;

long lVar19;

u32 *puStack_20360;

u32 auStack_2035c [32787];

u32 *puStack_300;

u32 uStack_2fc;

u32 *puStack_2f8;

u32 *puStack_2f0;

u32 *puStack_2e8;

u32 *puStack_2e0;

u32 *puStack_2d8;

u32 auStack_2d0 [24];

u32 auStack_270 [24];

u32 auStack_210 [12];

u32 auStack_1e0 [12];

u32 auStack_1b0 [72];

u32 auStack_90 [36];



lVar19 = (long)param_3;

iVar1 = *(int *)(param_2 + 0xc);

puVar14 = &DAT_006b1190;

puVar11 = auStack_90;

iVar9 = 0x12;

do {

  uVar6 = *puVar14;

  uVar2 = puVar14[1];

  puVar14 = puVar14 + 2;

  iVar9 = iVar9 + -1;

  *puVar11 = uVar6;

  puVar11[1] = uVar2;

  puVar11 = puVar11 + 2;

} while (0 < iVar9);

puVar14 = &DAT_006b1220;

puVar11 = auStack_1b0;

iVar9 = 0x24;

do {

  uVar6 = *puVar14;

  uVar2 = puVar14[1];

  puVar14 = puVar14 + 2;

  iVar9 = iVar9 + -1;

  *puVar11 = uVar6;

  puVar11[1] = uVar2;

  puVar11 = puVar11 + 2;

} while (0 < iVar9);

puVar14 = &DAT_006b1340;

puVar11 = auStack_1e0;

iVar9 = 6;

do {

  uVar6 = *puVar14;

  uVar2 = puVar14[1];

  puVar14 = puVar14 + 2;

  iVar9 = iVar9 + -1;

  *puVar11 = uVar6;

  puVar11[1] = uVar2;

  puVar11 = puVar11 + 2;

} while (0 < iVar9);

puVar14 = &DAT_006b1370;

puVar11 = auStack_210;

iVar9 = 6;

do {

  uVar6 = *puVar14;

  uVar2 = puVar14[1];

  puVar14 = puVar14 + 2;

  iVar9 = iVar9 + -1;

  *puVar11 = uVar6;

  puVar11[1] = uVar2;

  puVar11 = puVar11 + 2;

} while (0 < iVar9);

puVar14 = &DAT_006b13a0;

puVar11 = auStack_270;

iVar9 = 0xc;

do {

  uVar6 = *puVar14;

  uVar2 = puVar14[1];

  puVar14 = puVar14 + 2;

  iVar9 = iVar9 + -1;

  *puVar11 = uVar6;

  puVar11[1] = uVar2;

  puVar11 = puVar11 + 2;

} while (0 < iVar9);

puVar14 = &DAT_006b1400;

puVar11 = auStack_2d0;

iVar9 = 0xc;

do {

  uVar6 = *puVar14;

  uVar2 = puVar14[1];

  puVar14 = puVar14 + 2;

  iVar9 = iVar9 + -1;

  *puVar11 = uVar6;

  puVar11[1] = uVar2;

  puVar11 = puVar11 + 2;

} while (0 < iVar9);

puVar11 = &DAT_006b1460;

ppuVar12 = &puStack_300;

iVar9 = 6;

do {

  puVar14 = (u32 *)*puVar11;

  puVar3 = (u32 *)puVar11[1];

  puVar11 = puVar11 + 2;

  iVar9 = iVar9 + -1;

  *ppuVar12 = puVar14;

  ppuVar12[1] = puVar3;

  ppuVar12 = ppuVar12 + 2;

} while (0 < iVar9);

puStack_300 = auStack_90;

puStack_2f8 = auStack_1b0;

puStack_2f0 = auStack_1e0;

puStack_2e8 = auStack_210;

puStack_2e0 = auStack_270;

puStack_2d8 = auStack_2d0;

if (lVar19 != 0) {

  iVar9 = (int)lVar19;

  uVar18 = (int)*(short *)(iVar9 + 6) - 0x17;

  *(u32 *)(iVar1 + 0x98) = uVar18;

  if ((*(short *)(iVar9 + 6) == 0x19) || (*(short *)(iVar9 + 6) == 0x1a)) {

    uVar7 = FUN_003e0940();

    iVar4 = FUN_003c5460(uVar7);

    iVar4 = FUN_003c5470(*(u32 *)(iVar4 + 0x28));

    memcpy((void *)(iVar1 + 0x78),
                 (const void *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar4 + 0xc) + 0xc) + 0x14) + 0x1c) + 4),0x1c)
    ;

  }

  if ((int)*(short *)(iVar9 + 6) - 0x17U < 0xc) {

    iVar4 = (int)uVar18 >> 1;

    switch(*(short *)(iVar9 + 6)) {

    default:

      memcpy((void *)iVar1,(&puStack_300)[iVar4 * 2] +
                         (uVar18 & 1) * 2 * ((&uStack_2fc)[iVar4 * 2] >> 2) * 3,
                   ((&uStack_2fc)[iVar4 * 2] >> 2) * 0xc);

      *(u16 *)(iVar1 + 0x94) = 0;

      *(u16 *)(iVar1 + 0x96) = 0;

      break;

    case 0x18:

    case 0x1a:

    case 0x1c:

    case 0x1e:

    case 0x20:

    case 0x22:

      memcpy((void *)iVar1,(&puStack_300)[iVar4 * 2] +
                         (uVar18 & 1) * 2 * ((&uStack_2fc)[iVar4 * 2] >> 2) * 3,
                   ((&uStack_2fc)[iVar4 * 2] >> 2) * 0xc);

      *(u16 *)(iVar1 + 0x94) = 0;

      *(u16 *)(iVar1 + 0x96) = 0;

    }

  }

}

if ((*(short *)(iVar1 + 0x94) == 1) || (*(short *)(iVar1 + 0x94) != 0)) {

  uVar6 = 1;

}

else {

  iVar9 = (int)*(u32 *)(iVar1 + 0x98) >> 1;

  puVar11 = (&puStack_300)[iVar9 * 2];

  uVar16 = (&uStack_2fc)[iVar9 * 2] >> 2;

  *(short *)(iVar1 + 0x96) = *(short *)(iVar1 + 0x96) + 1;

  iVar4 = 0;

  uVar18 = *(u32 *)(iVar1 + 0x98) & 1;

  iVar9 = uVar18 * 2;

  for (iVar17 = 0; iVar17 < (int)uVar16; iVar17 = iVar17 + 1) {

    puVar15 = (u16 *)(iVar1 + iVar17 * 0xc);

    if ((short)puVar15[3] <= *(short *)(iVar1 + 0x96)) {

      iVar13 = (int)*(short *)(iVar1 + 0x96) - (int)(short)puVar15[3];

      psVar10 = (short *)(puVar11 + (iVar9 + 1) * uVar16 * 3 + iVar17 * 3);

      psVar8 = psVar10 + 3;

      if ((long)psVar10[3] < (long)iVar13) {

        iVar4 = iVar4 + 1;

      }

      else {

        psVar5 = (short *)(puVar11 + iVar9 * uVar16 * 3 + iVar17 * 3);

        *puVar15 = (short)(int)((float)(int)*psVar5 +

                               (float)(iVar13 * ((int)*psVar10 - (int)*psVar5)) /

                               (float)(int)psVar10[3]);

        puVar15[1] = (short)(int)((float)(int)psVar5[1] +

                                 (float)(iVar13 * ((int)psVar10[1] - (int)psVar5[1])) /

                                 (float)(int)*psVar8);

        puVar15[2] = (short)(int)((float)(int)psVar5[2] +

                                 (float)(iVar13 * ((int)psVar10[2] - (int)psVar5[2])) /

                                 (float)(int)*psVar8);

        *(float *)(puVar15 + 4) =

             *(float *)(psVar5 + 4) +

             ((float)iVar13 * (*(float *)(psVar10 + 4) - *(float *)(psVar5 + 4))) /

             (float)(int)*psVar8;

      }

    }

  }

  if ((int)uVar16 <= iVar4) {

    *(u16 *)(iVar1 + 0x94) = 1;

    *(u16 *)(iVar1 + 0x96) = 0;

    if (uVar18 != 0) {

      return 2;

    }

  }

  uVar6 = 0;

}

return uVar6; }

#pragma opt_loop_invariants reset
#pragma push
#pragma opt_common_subs off
// FUN_00414100


void FUN_00414100(u64 param_1,u64 param_2,int param_3,int param_4,u64 param_5,

                 u32 param_6)



{

  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x23, 0);
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x24, 0);
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x25, 0);
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x27, 0);
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x29, 0);
  return;

}

// FUN_004141E0


void FUN_004141e0(u64 param_1,u64 param_2,int param_3,int param_4,
                  int param_5,u32 param_6)
{
  FUN_0040e3c0((float)param_5, param_3, param_4, param_6 & 0xff, 0x81, 0);
  FUN_0040e3c0((float)param_5, param_3, param_4, param_6 & 0xff, 0x82, 0);
  return;
}


// FUN_00414280


void FUN_00414280(u64 param_1,u64 param_2,int param_3,int param_4,int param_5,

                 u32 param_6)



{

  FUN_0040e3c0((float)param_5, param_3 + 0xf9, param_4 + 0x12a, param_6, 0x2f, 0);

  FUN_0040e3c0((float)param_5, param_3 + 0xf9, param_4 + 0x12a, param_6 & 0xff, 0x30, 0);

  return;

}

// FUN_00414320 NONMATCHING


void FUN_00414320(u64 param_1,u64 param_2,int param_3,int param_4,int param_5,

                 u32 param_6)



{

  float fVar2;

  

  FUN_0040e3c0((float)param_5,param_3 + 0x20,param_4 + 0x65,param_6 & 0xff,0x92,0);

  FUN_0040e3c0((float)param_5,param_3 + 0x20,param_4 + 0x65,param_6 & 0xff,0x8d,0);

  fVar2 = DAT_007cada4 * (float)(int)param_6;


  FUN_0040e3c0((float)param_5,param_3 + 0x20,param_4 + 0x65,(u32)fVar2 & 0xff,0x8e,0);


  FUN_0040e3c0((float)param_5,param_3 + 0x20,param_4 + 0x65,(u32)fVar2 & 0xff,0x8f,0);

  FUN_0040e3c0((float)param_5,param_3 + 0x20,param_4 + 0x65,param_6 & 0xff,0x90,0);

  FUN_0040e3c0((float)param_5,param_3 + 0x20,param_4 + 0x65,param_6 & 0xff,0x91,0);

  return;

}

// FUN_00414500


void FUN_00414500(u64 param_1,u64 param_2,int param_3,int param_4,int param_5,

                 u32 param_6)



{

  FUN_0040e3c0((float)param_5, param_3 + 0x178, param_4 + 0x5c, param_6, 0x99, 0);

  FUN_0040e3c0((float)param_5, param_3 + 0x178, param_4 + 0x5c, param_6, 0x9a, 0);

  FUN_0040e3c0((float)param_5, param_3 + 0x178, param_4 + 0x5c, param_6, 0x9b, 0);

  FUN_0040e3c0((float)param_5, param_3 + 0x178, param_4 + 0x5c, param_6, 0x9c, 0);

  return;

}

// FUN_004145F0


void FUN_004145f0(u64 param_1,u64 param_2,int param_3,int param_4,int param_5,

                 u32 param_6)



{

  FUN_0040e3c0((float)param_5, param_3 + -0xc, param_4 + -0xe, param_6, 0x93, 0);

  FUN_0040e3c0((float)param_5, param_3 + -0xc, param_4 + -0xe, param_6, 0x94, 0);

  FUN_0040e3c0((float)param_5, param_3 + -0xc, param_4 + -0xe, param_6, 0x95, 0);

  return;

}

// FUN_004146B0


void FUN_004146b0(u64 param_1,u64 param_2,int param_3,int param_4,int param_5,

                 u32 param_6)



{

  FUN_0040e3c0((float)param_5, param_3 + 0xf8, param_4 + -1, param_6, 0x96, 0);

  FUN_0040e3c0((float)param_5, param_3 + 0xf8, param_4 + -1, param_6, 0x97, 0);

  FUN_0040e3c0((float)param_5, param_3 + 0xf8, param_4 + -1, param_6, 0x98, 0);

  return;

}

// FUN_00414770


void FUN_00414770(u64 param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6)



{

  u32 uVar2;
  u8 *puVar1;

  

  puVar1 = *(u8 **)(param_2 + 0xc);

  FUN_0040e3c0((float)param_5,param_3 + 0x139,param_4 + 0x27,param_6 & 0xff,0x8a,0);

  FUN_0040e3c0((float)param_5,param_3 + 0x139,param_4 + 0x27,param_6 & 0xff,0x8b,0);

  FUN_0040e3c0((float)param_5,param_3 + 0x139,param_4 + 0x27,param_6 & 0xff,0x8c,0);

  FUN_0040e3c0_i(param_3 + 0x16a,param_4 + 0x2a,0.0f,param_6 & 0xff,0,
                 (u32)puVar1[0x7c] * 2 + 1);

  uVar2 = func_00171110(*(s16 *)(puVar1 + 0x78),2);

  FUN_003b2cb0_i(param_3 + 0x18a,param_4 + 0x2c,0.0f,param_6 | 0xffffff00,6,1,uVar2,0,0);

  return;

}

// FUN_004148B0


void FUN_004148b0(u64 param_1,u64 param_2,int param_3,int param_4,int param_5,

                 u32 param_6)



{

  FUN_0040e3c0((float)param_5, param_3 + 0xf9, param_4 + 0x11d, param_6, 0x2d, 0);

  FUN_0040e3c0((float)param_5, param_3 + 0xf9, param_4 + 0x11d, param_6 & 0xff, 0x2e, 0);

  return;

}

// FUN_00414950


void FUN_00414950(u64 param_1,u64 param_2,int param_3,int param_4,int param_5,

                 u32 param_6)



{

  FUN_0040e3c0((float)param_5, param_3 + 0xf9, param_4 + 0x12f, param_6, 0x2b, 0);

  FUN_0040e3c0((float)param_5, param_3 + 0xf9, param_4 + 0x12f, param_6 & 0xff, 0x2c, 0);

  return;

}

#pragma push
#pragma opt_common_subs off
// FUN_004149F0


void FUN_004149f0(u64 param_1,u64 param_2,int param_3,int param_4,u64 param_5,
                 u32 param_6)
{
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x23, 0);
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x24, 0);
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x26, 0);
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x28, 0);
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x29, 0);
  return;
}
#pragma pop

// FUN_00414AD0


void FUN_00414ad0(u64 param_1,u64 param_2,int param_3,int param_4,u64 param_5,

                 u32 param_6)



{

  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x23, 0);
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x24, 0);
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x25, 0);
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x27, 0);
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x29, 0);
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0xd7, 0);

  return;

}

// FUN_00414BD0


void FUN_00414bd0(u64 param_1,u64 param_2,int param_3,int param_4,int param_5,

                 u32 param_6)



{

  FUN_0040e3c0((float)param_5, param_3 + 0x122, param_4 + 0xde, param_6, 0x2b, 0);

  FUN_0040e3c0((float)param_5, param_3 + 0x122, param_4 + 0xde, param_6 & 0xff, 0x2c, 0);

  return;

}

// FUN_00414C70


void FUN_00414c70(u64 param_1,u64 param_2,int param_3,int param_4,u64 param_5,

                 u32 param_6)



{

  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x23, 0);
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x24, 0);
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x25, 0);
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x27, 0);
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0x2a, 0);
  FUN_0040e3c0_i(param_3 + -6, param_4 + -10, 0.0f, param_6 & 0xff, 0xd7, 0);

  return;

}
#pragma pop

// FUN_00414D70


void FUN_00414d70(u64 param_1,u64 param_2,int param_3,int param_4,int param_5,

                 u32 param_6)



{

  FUN_0040e3c0((float)param_5, param_3 + 0x122, param_4 + 0xde, param_6, 0x2b, 0);

  FUN_0040e3c0((float)param_5, param_3 + 0x122, param_4 + 0xde, param_6 & 0xff, 0x2c, 0);

  return;

}

// FUN_00414E10 NONMATCHING


u64 FUN_00414e10(int param_1,int param_2)



{

  int iVar1;

  u8 *puVar2;

  u8 *puVar3;

  u8 **ppuVar4;

  u16 *puVar5;

  int iVar6;

  u8 ***pppuVar7;

  u8 **ppuVar8;

  u32 *puVar9;

  u8 **appuStack_70 [6];

  u8 **ppuStack_58;

  u8 **ppuStack_50;

  u8 **ppuStack_48;

  u32 auStack_40 [6];

  u8 *puStack_28;

  u8 *puStack_24;

  u8 *puStack_20;

  u8 *puStack_1c;

  u8 *puStack_18;

  u8 *puStack_14;

  u8 *puStack_10;

  u8 *puStack_8;

  u8 *puStack_4;

  

  iVar1 = *(int *)((int)param_2 + 0xc);

  puStack_18 = (u8 *)(PTR_FUN_006b1490);

  puStack_14 = (u8 *)(PTR_FUN_006b1494);

  puStack_10 = (u8 *)(PTR_FUN_006b1498);

  ppuVar8 = (u8 **)&PTR_FUN_006b14a0;

  puVar9 = auStack_40;

  iVar6 = 3;

  do {

    puVar2 = *ppuVar8;

    puVar3 = ppuVar8[1];

    ppuVar8 = ppuVar8 + 2;

    iVar6 = iVar6 + -1;

    *puVar9 = (u32)(puVar2);

    puVar9[1] = (u32)(puVar3);

    puVar9 = puVar9 + 2;

  } while (0 < iVar6);

  puStack_4 = (u8 *)(PTR_FUN_007cda10);

  puStack_8 = (u8 *)(PTR_FUN_007cda14);

  puStack_20 = (u8 *)(PTR_FUN_007cda18);

  puStack_1c = (u8 *)(PTR_FUN_007cda1c);

  puStack_28 = (u8 *)(PTR_FUN_007cda20);

  puStack_24 = (u8 *)(PTR_FUN_007cda24);

  puVar9 = &DAT_006b14c0;

  pppuVar7 = appuStack_70;

  iVar6 = 6;

  do {

    ppuVar8 = (u8 **)*puVar9;

    ppuVar4 = (u8 **)puVar9[1];

    puVar9 = puVar9 + 2;

    iVar6 = iVar6 + -1;

    *pppuVar7 = ppuVar8;

    pppuVar7[1] = ppuVar4;

    pppuVar7 = pppuVar7 + 2;

  } while (0 < iVar6);

  appuStack_70[0] = &puStack_18;

  appuStack_70[2] = (u8 **)auStack_40;

  appuStack_70[4] = &puStack_4;

  ppuStack_58 = &puStack_8;

  ppuStack_50 = &puStack_20;

  ppuStack_48 = &puStack_28;

  iVar6 = *(int *)(iVar1 + 0x98) >> 1;

  ppuVar8 = appuStack_70[iVar6 * 2];

  ppuVar4 = appuStack_70[iVar6 * 2 + 1];

  for (iVar6 = 0; iVar6 < (int)ppuVar4; iVar6 = iVar6 + 1) {

    puVar5 = (u16 *)(iVar1 + iVar6 * 0xc);

    (*(code *)ppuVar8[iVar6])
              (0,*(u32 *)(puVar5 + 4),*(u32 *)(puVar5 + 4),param_1,param_2,*puVar5,
               puVar5[1],0,puVar5[2],0,0);

  }

  return 0;

}

/* W327 measured: opt_loop_invariants on normalized_diff 719 -> 672; object 1252/1280 -> 1252/1280 (without/with). */
#pragma opt_loop_invariants on
// FUN_00414FE0 NONMATCHING


u32 FUN_00414fe0(u64 param_1,int param_2,long param_3)



{

  int iVar1;

  u32 uVar2;

  u32 *puVar3;

  short *psVar4;

  u32 uVar5;

  short *psVar6;

  int iVar7;

  short *psVar8;

  u32 *puVar9;

  u32 **ppuVar10;

  int iVar11;

  u16 *puVar12;

  u32 *puVar13;

  u32 uVar14;

  u32 uVar15;

  int iVar16;

  int iVar17;

  u32 *apuStack_1e0 [6];

  u32 *puStack_1c8;

  u32 *puStack_1c0;

  u32 auStack_1b0 [24];

  u32 auStack_150 [12];

  u32 auStack_120 [36];

  u32 auStack_90 [24];

  u32 auStack_30 [12];

  

  iVar1 = *(int *)(param_2 + 0xc);

  puVar13 = &DAT_006b14f0;

  puVar9 = auStack_30;

  iVar7 = 6;

  do {

    uVar5 = *puVar13;

    uVar2 = puVar13[1];

    puVar13 = puVar13 + 2;

    iVar7 = iVar7 + -1;

    *puVar9 = uVar5;

    puVar9[1] = uVar2;

    puVar9 = puVar9 + 2;

  } while (0 < iVar7);

  puVar13 = &DAT_006b1520;

  puVar9 = auStack_90;

  iVar7 = 0xc;

  do {

    uVar5 = *puVar13;

    uVar2 = puVar13[1];

    puVar13 = puVar13 + 2;

    iVar7 = iVar7 + -1;

    *puVar9 = uVar5;

    puVar9[1] = uVar2;

    puVar9 = puVar9 + 2;

  } while (0 < iVar7);

  puVar13 = &DAT_006b1580;

  puVar9 = auStack_120;

  iVar7 = 0x12;

  do {

    uVar5 = *puVar13;

    uVar2 = puVar13[1];

    puVar13 = puVar13 + 2;

    iVar7 = iVar7 + -1;

    *puVar9 = uVar5;

    puVar9[1] = uVar2;

    puVar9 = puVar9 + 2;

  } while (0 < iVar7);

  puVar13 = &DAT_006b1610;

  puVar9 = auStack_150;

  iVar7 = 6;

  do {

    uVar5 = *puVar13;

    uVar2 = puVar13[1];

    puVar13 = puVar13 + 2;

    iVar7 = iVar7 + -1;

    *puVar9 = uVar5;

    puVar9[1] = uVar2;

    puVar9 = puVar9 + 2;

  } while (0 < iVar7);

  puVar13 = &DAT_006b1640;

  puVar9 = auStack_1b0;

  iVar7 = 0xc;

  do {

    uVar5 = *puVar13;

    uVar2 = puVar13[1];

    puVar13 = puVar13 + 2;

    iVar7 = iVar7 + -1;

    *puVar9 = uVar5;

    puVar9[1] = uVar2;

    puVar9 = puVar9 + 2;

  } while (0 < iVar7);

  puVar9 = &DAT_006b16a0;

  ppuVar10 = apuStack_1e0;

  iVar7 = 5;

  do {

    puVar13 = (u32 *)*puVar9;

    puVar3 = (u32 *)puVar9[1];

    puVar9 = puVar9 + 2;

    iVar7 = iVar7 + -1;

    *ppuVar10 = puVar13;

    ppuVar10[1] = puVar3;

    ppuVar10 = ppuVar10 + 2;

  } while (0 < iVar7);

  apuStack_1e0[0] = auStack_30;

  apuStack_1e0[2] = auStack_90;

  apuStack_1e0[4] = auStack_120;

  puStack_1c8 = auStack_150;

  puStack_1c0 = auStack_1b0;

  if (param_3 != 0) {

    *(u16 *)(iVar1 + 0x94) = 0;

    *(u16 *)(iVar1 + 0x96) = 0;

    switch(*(u16 *)((int)param_3 + 6)) {

    case 5:

      *(u32 *)(iVar1 + 0x98) = 0;

      break;

    case 6:

      *(u32 *)(iVar1 + 0x98) = 2;

      break;

    case 7:

      *(u32 *)(iVar1 + 0x98) = 4;

      break;

    case 8:

      *(u32 *)(iVar1 + 0x98) = 6;

      break;

    case 9:

      *(u32 *)(iVar1 + 0x98) = 8;

      break;

    case 10:

      *(u32 *)(iVar1 + 0x98) = 1;

      break;

    case 0xb:

      *(u32 *)(iVar1 + 0x98) = 3;

      break;

    case 0xc:

      *(u32 *)(iVar1 + 0x98) = 5;

      break;

    case 0xd:

      *(u32 *)(iVar1 + 0x98) = 7;

      break;

    case 0xe:

      *(u32 *)(iVar1 + 0x98) = 9;

    }

    iVar7 = (int)*(u32 *)(iVar1 + 0x98) >> 1;

    memcpy((void *)iVar1,apuStack_1e0[iVar7 * 2] +
                       (*(u32 *)(iVar1 + 0x98) & 1) * 2 * ((u32)apuStack_1e0[iVar7 * 2 + 1] >> 2)
                       * 3,((u32)apuStack_1e0[iVar7 * 2 + 1] >> 2) * 0xc);

  }

  if ((*(short *)(iVar1 + 0x94) == 1) || (*(short *)(iVar1 + 0x94) != 0)) {

    uVar5 = 1;

  }

  else {

    iVar7 = (int)*(u32 *)(iVar1 + 0x98) >> 1;

    puVar9 = apuStack_1e0[iVar7 * 2];

    uVar15 = (u32)apuStack_1e0[iVar7 * 2 + 1] >> 2;

    *(short *)(iVar1 + 0x96) = *(short *)(iVar1 + 0x96) + 1;

    iVar16 = 0;

    uVar14 = *(u32 *)(iVar1 + 0x98) & 1;

    iVar7 = uVar14 * 2;

    for (iVar17 = 0; iVar17 < (int)uVar15; iVar17 = iVar17 + 1) {

      puVar12 = (u16 *)(iVar1 + iVar17 * 0xc);

      if ((short)puVar12[3] <= *(short *)(iVar1 + 0x96)) {

        iVar11 = (int)*(short *)(iVar1 + 0x96) - (int)(short)puVar12[3];

        psVar8 = (short *)(puVar9 + (iVar7 + 1) * uVar15 * 3 + iVar17 * 3);

        psVar6 = psVar8 + 3;

        if ((long)psVar8[3] < (long)iVar11) {

          iVar16 = iVar16 + 1;

        }

        else {

          psVar4 = (short *)(puVar9 + iVar7 * uVar15 * 3 + iVar17 * 3);

          *puVar12 = (short)(int)((float)(int)*psVar4 +

                                 (float)(iVar11 * ((int)*psVar8 - (int)*psVar4)) /

                                 (float)(int)psVar8[3]);

          puVar12[1] = (short)(int)((float)(int)psVar4[1] +

                                   (float)(iVar11 * ((int)psVar8[1] - (int)psVar4[1])) /

                                   (float)(int)*psVar6);

          puVar12[2] = (short)(int)((float)(int)psVar4[2] +

                                   (float)(iVar11 * ((int)psVar8[2] - (int)psVar4[2])) /

                                   (float)(int)*psVar6);

          *(float *)(puVar12 + 4) =

               *(float *)(psVar4 + 4) +

               ((float)iVar11 * (*(float *)(psVar8 + 4) - *(float *)(psVar4 + 4))) /

               (float)(int)*psVar6;

        }

      }

    }

    if ((int)uVar15 <= iVar16) {

      *(u16 *)(iVar1 + 0x94) = 1;

      *(u16 *)(iVar1 + 0x96) = 0;

      if (uVar14 != 0) {

        return 2;

      }

    }

    uVar5 = 0;

  }

  return uVar5;

}

#pragma opt_loop_invariants reset
// FUN_004154E0 NONMATCHING
void FUN_004154e0(u64 param_1,u64 param_2,int param_3,int param_4,
                 int param_5,int param_6)
{
  float fVar2;
  u32 uVar1;
  fVar2 = (float)param_6 * 0.5f;
  if (2147483648.0f <= fVar2) {
    uVar1 = (u32)((s32)(fVar2 - 2147483648.0f) | 0x80000000);
  }
  else {
    uVar1 = (u32)(s32)fVar2;
  }
  FUN_0040e3f0_typed((float)param_5,0.0f,2.5f,2.5f,param_3,param_4,
                    uVar1 & 0xff,0x5a,0,0,0);
  if (2147483648.0f <= fVar2) {
    uVar1 = (u32)((s32)(fVar2 - 2147483648.0f) | 0x80000000);
  }
  else {
    uVar1 = (u32)(s32)fVar2;
  }
  FUN_0040e3f0_typed((float)param_5,0.0f,2.5f,2.5f,param_3,(int)param_4 + 0xd8,
                    uVar1 & 0xff,0x5b,0,0,0);
}
// FUN_00415650 NONMATCHING
void FUN_00415650(u64 param_1,u64 param_2,int param_3,int param_4,
                 int param_5,int param_6)
{
  float fVar2;
  u32 uVar1;

  fVar2 = (float)param_6 * 0.5f;
  if (2147483648.0f <= fVar2) goto convert_high_15650;
  uVar1 = (u32)(s32)fVar2;
  goto convert_done_15650;
convert_high_15650:
  uVar1 = (u32)((s32)(fVar2 - 2147483648.0f) | 0x80000000);
convert_done_15650:
  FUN_0040e3f0_typed((float)param_5,0.0f,2.5f,2.5f,param_3,param_4,
                    uVar1 & 0xff,0x5c,0,0,0);
  if (2147483648.0f <= fVar2) goto convert_high_15650_b;
  uVar1 = (u32)(s32)fVar2;
  goto convert_done_15650_b;
convert_high_15650_b:
  uVar1 = (u32)((s32)(fVar2 - 2147483648.0f) | 0x80000000);
convert_done_15650_b:
  FUN_0040e3f0_typed((float)param_5,0.0f,2.5f,2.5f,param_3,(int)param_4 + 0x196,
                    uVar1 & 0xff,0x5d,0,0,0);
}


// FUN_004157C0


void FUN_004157c0(u64 param_1,u64 param_2,int param_3,int param_4,int param_5,

                 u32 param_6)



{

  FUN_0040e3c0((float)param_5, param_3 + 0x2c, param_4 + 100, param_6, 0x5e, 0);

  FUN_0040e3c0((float)param_5, param_3 + -0x14, param_4 + 0x32, param_6, 0x5f, 0);

  FUN_0040e3c0((float)param_5, param_3 + -0x1a, param_4 + 0xb8, param_6, 0x60, 0);

  return;

}

// FUN_00415880 NONMATCHING
void FUN_00415880(u64 param_1,u64 param_2,int param_3,int param_4,
                 int param_5,int param_6)
{
  float fVar2;

  fVar2 = (float)param_6 * 0.5f;

  FUN_0040e3f0_typed((float)param_5,0.0f,2.5f,2.5f,param_3,param_4,
                    ((fVar2 < 2147483648.0f)
                     ? (s32)fVar2
                     : ((s32)(fVar2 - 2147483648.0f) | 0x80000000)) & 0xff,
                    0x61,0,0,0);

  FUN_0040e3f0_typed((float)param_5,0.0f,2.5f,2.5f,param_3,(int)param_4 + 0x132,
                    ((fVar2 < 2147483648.0f)
                     ? (s32)fVar2
                     : ((s32)(fVar2 - 2147483648.0f) | 0x80000000)) & 0xff,
                    0x62,0,0,0);

  FUN_0040e3f0_typed((float)param_5,0.0f,2.5f,2.5f,param_3,(int)param_4 + 0x197,
                    ((fVar2 < 2147483648.0f)
                     ? (s32)fVar2
                     : ((s32)(fVar2 - 2147483648.0f) | 0x80000000)) & 0xff,
                    99,0,0,0);
}

// FUN_00415A70


void FUN_00415a70(u64 param_1,u64 param_2,int param_3,int param_4,int param_5,

                 u32 param_6)



{

  FUN_0040e3c0((float)param_5, param_3 + 0x5b, param_4 + 0x31, param_6, 0x65, 0);

  FUN_0040e3c0((float)param_5, param_3 + -0x14, param_4 + 0x2f, param_6, 0x66, 0);

  FUN_0040e3c0((float)param_5, param_3 + -0x26, param_4 + 0x95, param_6, 0x67, 0);

  return;

}

// FUN_00415B30


void FUN_00415b30(u64 param_1,u64 param_2,int param_3,int param_4,int param_5,

                 u8 param_6)



{

  FUN_0040e3c0((float)param_5, param_3 + 0x191, param_4 + 0x96, param_6 & 0xff, 100, 0);

  return;

}

// FUN_00415B70


void FUN_00415b70(u64 param_1,u64 param_2,int param_3,int param_4,int param_5,

                 u32 param_6)



{

  FUN_0040e3c0((float)param_5, param_3 + 0x160, param_4 + 0x5c, param_6, 0x69, 0);

  FUN_0040e3c0((float)param_5, param_3 + 0x160, param_4 + 0x5c, param_6, 0x6a, 0);

  FUN_0040e3c0((float)param_5, param_3 + 0x160, param_4 + 0x5c, param_6, 0x6b, 0);

  return;

}

// FUN_00415C30 NONMATCHING


u64 FUN_00415c30(int param_1, int param_2) { int iVar1;

u8 **ppuVar2;

u8 **ppuVar3;

u16 *puVar4;

int iVar5;

u8 ***pppuVar6;

u32 *puVar7;

u8 **appuStack_50 [6];

u8 **ppuStack_38;

u8 **ppuStack_30;

u8 *puStack_28;

u8 *puStack_24;

u8 *puStack_20;

u8 *puStack_1c;

u8 *puStack_18;

u8 *puStack_10;

u8 *puStack_c;

u8 *puStack_8;

u8 *puStack_4;



iVar1 = *(int *)((int)param_2 + 0xc);

puStack_4 = (u8 *)(PTR_FUN_007cda28);

puStack_10 = (u8 *)(PTR_FUN_007cda30);

puStack_c = (u8 *)(PTR_FUN_007cda34);

puStack_20 = (u8 *)(PTR_FUN_006b16c8);

puStack_1c = (u8 *)(PTR_FUN_006b16cc);

puStack_18 = (u8 *)(PTR_FUN_006b16d0);

puStack_8 = (u8 *)(PTR_FUN_007cda38);

puStack_28 = (u8 *)(PTR_FUN_007cda40);

puStack_24 = (u8 *)(PTR_FUN_007cda44);

puVar7 = &DAT_006b16e0;

pppuVar6 = appuStack_50;

iVar5 = 5;

do {

  ppuVar2 = (u8 **)*puVar7;

  ppuVar3 = (u8 **)puVar7[1];

  puVar7 = puVar7 + 2;

  iVar5 = iVar5 + -1;

  *pppuVar6 = ppuVar2;

  pppuVar6[1] = ppuVar3;

  pppuVar6 = pppuVar6 + 2;

} while (0 < iVar5);

appuStack_50[0] = &puStack_4;

appuStack_50[2] = &puStack_10;

appuStack_50[4] = &puStack_20;

ppuStack_38 = &puStack_8;

ppuStack_30 = &puStack_28;

iVar5 = *(int *)(iVar1 + 0x98) >> 1;

ppuVar2 = appuStack_50[iVar5 * 2];

ppuVar3 = appuStack_50[iVar5 * 2 + 1];

for (iVar5 = 0; iVar5 < (int)ppuVar3; iVar5 = iVar5 + 1) {

  puVar4 = (u16 *)(iVar1 + iVar5 * 0xc);

  (*(code *)ppuVar2[iVar5])

            (0,*(u32 *)(puVar4 + 4),*(u32 *)(puVar4 + 4),param_1,param_2,*puVar4,

             puVar4[1],0,puVar4[2],0,0);

}

return 0; }

/* W327 measured: opt_loop_invariants on normalized_diff 573 -> 524; object 1116/1152 -> 1116/1152 (without/with). */
#pragma opt_loop_invariants on
// FUN_00415DC0 NONMATCHING


u64 FUN_00415dc0(u64 param_1,int param_2,u8 *param_3)



{

  short sVar1;

  int iVar2;

  u32 uVar3;

  u32 uVar4;

  short *psVar5;

  u64 uVar6;

  short *psVar7;

  int iVar8;

  short *psVar9;

  u32 *puVar10;

  int iVar11;

  u16 *puVar12;

  u32 *puVar13;

  u32 uVar14;

  u32 uVar15;

  int iVar16;

  int iVar17;

  u32 auStack_130 [74];

  u32 *puStack_8;

  u32 uStack_4;

  

  iVar2 = *(int *)(param_2 + 0xc);

  puVar13 = &DAT_006b1710;

  puVar10 = auStack_130;

  iVar8 = 0x24;

  do {

    uVar3 = *puVar13;

    uVar4 = puVar13[1];

    puVar13 = puVar13 + 2;

    iVar8 = iVar8 + -1;

    *puVar10 = uVar3;

    puVar10[1] = uVar4;

    puVar10 = puVar10 + 2;

  } while (0 < iVar8);

  uStack_4 = DAT_007cda4c;

  puStack_8 = auStack_130;

  if (param_3 != 0) {

    sVar1 = *(short *)(param_3 + 6);

    if (sVar1 == 1) {

      *(u32 *)(iVar2 + 0x4c) = 0;

    }

    else if (sVar1 == 4) {

      *(u32 *)(iVar2 + 0x4c) = 1;

    }

    sVar1 = *(short *)(param_3 + 6);

    if (sVar1 != 2) {

      if (sVar1 == 4) {

        *(u16 *)(iVar2 + 0x48) = 0;

        *(u16 *)(iVar2 + 0x4a) = 0;

      }

      else if (sVar1 == 1) {

        *(u16 *)(iVar2 + 0x48) = 0;

        *(u16 *)(iVar2 + 0x4a) = 0;

        uVar6 = FUN_003e0940();

        iVar8 = FUN_003c5460(uVar6);

        iVar8 = FUN_003c5470(*(u32 *)(iVar8 + 0x28));

        memcpy((void *)(iVar2 + 0xa0),(const void *)(iVar8 + 0x34),0x1c);

        memcpy((void *)(iVar2 + 0xbc),(const void *)(iVar8 + 0x18),0x1c);

        memcpy((void *)(iVar2 + 0x6c),
                     (const void *)(*(u32 *)
                      (*(int *)(*(int *)(*(int *)(*(int *)(iVar8 + 0x10) + 0xc) + 0x14) + 0x1c) +
                      0x14)),0x34);

        memcpy((void *)(iVar2 + 0x50),
                     (const void *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar8 + 0xc) + 0xc) + 0x14) + 0x1c) + 4),
                     0x1c);

      }

    }

    uVar14 = *(u32 *)(iVar2 + 0x4c);

    iVar8 = (int)uVar14 >> 1;

    puVar10 = (&puStack_8)[iVar8 * 2];

    uVar15 = (&uStack_4)[iVar8 * 2];

    for (iVar8 = 0; iVar8 < (int)(uVar15 >> 2); iVar8 = iVar8 + 1) {

      memcpy((void *)(iVar2 + iVar8 * 0xc),(const void *)(puVar10 + (iVar8 + (uVar14 & 1) * 2 * (uVar15 >> 2)) * 3),0xc);

    }

  }

  sVar1 = *(short *)(iVar2 + 0x48);

  uVar6 = 2;

  if (((sVar1 != 2) && (uVar6 = 1, sVar1 != 1)) && (sVar1 == 0)) {

    iVar8 = (int)*(u32 *)(iVar2 + 0x4c) >> 1;

    puVar10 = (&puStack_8)[iVar8 * 2];

    uVar15 = (&uStack_4)[iVar8 * 2] >> 2;

    *(short *)(iVar2 + 0x4a) = *(short *)(iVar2 + 0x4a) + 1;

    iVar17 = 0;

    uVar14 = *(u32 *)(iVar2 + 0x4c) & 1;

    iVar8 = uVar14 * 2;

    for (iVar16 = 0; iVar16 < (int)uVar15; iVar16 = iVar16 + 1) {

      puVar12 = (u16 *)(iVar2 + iVar16 * 0xc);

      if ((short)puVar12[3] <= *(short *)(iVar2 + 0x4a)) {

        iVar11 = (int)*(short *)(iVar2 + 0x4a) - (int)(short)puVar12[3];

        psVar9 = (short *)(puVar10 + (iVar8 + 1) * uVar15 * 3 + iVar16 * 3);

        psVar7 = psVar9 + 3;

        if ((long)psVar9[3] < (long)iVar11) {

          iVar17 = iVar17 + 1;

        }

        else {

          psVar5 = (short *)(puVar10 + iVar8 * uVar15 * 3 + iVar16 * 3);

          *puVar12 = (short)(int)((float)(int)*psVar5 +

                                 (float)(iVar11 * ((int)*psVar9 - (int)*psVar5)) /

                                 (float)(int)psVar9[3]);

          puVar12[1] = (short)(int)((float)(int)psVar5[1] +

                                   (float)(iVar11 * ((int)psVar9[1] - (int)psVar5[1])) /

                                   (float)(int)*psVar7);

          puVar12[2] = (short)(int)((float)(int)psVar5[2] +

                                   (float)(iVar11 * ((int)psVar9[2] - (int)psVar5[2])) /

                                   (float)(int)*psVar7);

          *(float *)(puVar12 + 4) =

               *(float *)(psVar5 + 4) +

               ((float)iVar11 * (*(float *)(psVar9 + 4) - *(float *)(psVar5 + 4))) /

               (float)(int)*psVar7;

        }

      }

    }

    if ((int)uVar15 <= iVar17) {

      *(u16 *)(iVar2 + 0x48) = 1;

      *(u16 *)(iVar2 + 0x4a) = 0;

      if (uVar14 != 0) {

        return 2;

      }

    }

    uVar6 = 0;

  }

  return uVar6;

}

#pragma opt_loop_invariants reset
// FUN_00416240 NONMATCHING


void FUN_00416240(u64 param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6)



{

  int iVar1;

  u64 uVar2;

  

  iVar1 = *(int *)(param_2 + 0xc);

  FUN_0040e3c0((float)param_5,param_3 + 0x38,param_4 + 0x2b,param_6 & 0xff,0xa4,0);

  FUN_0040e3c0((float)param_5,param_3 + 0x38,param_4 + 0x2b,param_6 & 0xff,0xa5,0);

  FUN_0040e3c0(0,param_3 + 0x43,param_4 + 0x3d,param_6 & 0xff,0,(u32)*(u8 *)(iVar1 + 0x54) << 1);

  uVar2 = func_00171110(*(u16 *)(iVar1 + 0x50),*(u8 *)(iVar1 + 0x58));

  FUN_003b2cb0(0,param_3 + 99,param_4 + 0x3f,param_6 | 0xffffffffffffff00,5,1,uVar2,0,0);

  param_3 = param_3 + -0x15;

  param_4 = param_4 + -0x1a;

  FUN_0040e3c0((float)param_5,param_3,param_4,param_6 & 0xff,0xa1,0);

  FUN_0040e3c0((float)param_5,param_3,param_4,param_6 & 0xff,0xa2,0);

  FUN_0040e3c0((float)param_5,param_3,param_4,param_6 & 0xff,0xa3,0);

  return;

}

/* W327 measured: opt_common_subs off normalized_diff 555 -> 486; object 752/736 -> 736/736 (without/with). */
#pragma opt_common_subs off
// FUN_004163F0 NONMATCHING


void FUN_004163f0(u64 param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6)



{

  int iVar1;

  int iVar2;

  int iVar3;

  u8 auStack_8 [8];

  

  iVar1 = *(int *)(param_2 + 0xc);

  iVar3 = param_3 + 0x14e;

  iVar2 = param_4 + 0x2b;

  FUN_0040e3c0((float)param_5,iVar3,iVar2,param_6 & 0xff,0xa9,0);

  FUN_0040e3c0((float)param_5,iVar3,iVar2,param_6 & 0xff,0xaa,0);

  FUN_0040e3c0((float)param_5,iVar3,param_4 + 0x2c,param_6 & 0xff,0xab,0);

  FUN_0040e3c0((float)param_5,iVar3,param_4 + 0x2c,param_6 & 0xff,0xac,0);

  FUN_0040e3c0((float)param_5,iVar3,iVar2,param_6 & 0xff,0xad,0);

  FUN_0040e3c0((float)param_5,iVar3,iVar2,param_6 & 0xff,0xae,0);

  FUN_0040e3c0(0,param_3 + 0x1a6,param_4 + 0x32,param_6 & 0xff,3,

               (*(u8 *)((u32)*(u16 *)(iVar1 + 0x6e) * 0xe + DAT_007ce420 + 2) - 1) * 2 + 1);

  sprintf((char *)auStack_8,(const char *)0x7cda50,*(u8 *)(iVar1 + 0x70));

  if (*(u8 *)(iVar1 + 0x70) < 10) {

    FUN_0040eb50(0,param_3 + 0x195,param_4 + 0x4f,param_6 & 0xff,2,auStack_8,2);

  }

  else {

    FUN_0040eb50(0,param_3 + 400,param_4 + 0x4f,param_6 & 0xff,2,auStack_8,2);

  }

  FUN_003b32d0(0,param_3 + 0x1ae,param_4 + 0x46,param_6 | 0xffffffffffffff00,5,1,

               DAT_007ce4e4 + (u32)*(u16 *)(iVar1 + 0x6e) * 0x11,0,0x78);

  param_3 = param_3 + 0x143;

  param_4 = param_4 + 0xd;

  FUN_0040e3c0((float)param_5,param_3,param_4,param_6 & 0xff,0xa6,0);

  FUN_0040e3c0((float)param_5,param_3,param_4,param_6 & 0xff,0xa7,0);

  FUN_0040e3c0((float)param_5,param_3,param_4,param_6 & 0xff,0xa8,0);

  return;

}

#pragma opt_common_subs reset
// FUN_004166D0


void FUN_004166d0(u64 param_1,int param_2,int param_3,int param_4,int param_5,

                 u32 param_6)



{

  f32 zero;
  u32 uVar2;
  u8 *puVar1;
  s32 call_a0;
  s32 call_a1;

  

  zero = 0.0f;
  puVar1 = (u8 *)(*(int *)(param_2 + 0xc) + 0xa0);
  call_a0 = param_3 + 0x7b;
  call_a1 = param_4 + 100;
  asm volatile("" : "+r" (call_a0), "+r" (call_a1));
  FUN_0040e3c0(zero,call_a0,call_a1,param_6,0xaf,0);
  call_a0 = param_3 + 0x7b;
  call_a1 = param_4 + 100;
  asm volatile("" : "+r" (call_a0), "+r" (call_a1));
  FUN_0040e3c0(zero,call_a0,call_a1,param_6,0xb0,0);

  call_a0 = param_3 + 0xcb;
  call_a1 = param_4 + 0x76;
  asm volatile("" : "+r" (call_a0), "+r" (call_a1));
  FUN_0040e3c0(zero,call_a0,call_a1,param_6,4,
               (u32)puVar1[4] * 2 + 1);

  uVar2 = func_00171110(*(s16 *)puVar1,2);
  call_a0 = param_3 + 0xed;
  call_a1 = param_4 + 0x79;
  asm volatile("" : "+r" (call_a0), "+r" (call_a1));
  FUN_003b2cb0_typed(zero,call_a0,call_a1,param_6 | 0xffffff00,6,1,uVar2,0,0);

  return;

}

// FUN_004167D0 NONMATCHING


void FUN_004167d0(u64 param_1,int param_2,int param_3,int param_4,int param_5,

                 u8 param_6)



{

  int iVar1;

  int iVar2;

  int iVar3;

  u8 auStack_10 [8];

  short sStack_8;

  short sStack_6;

  short sStack_4;

  short sStack_2;

  

  iVar1 = *(int *)(param_2 + 0xc);

  sStack_8 = DAT_007cda58;

  sStack_6 = DAT_007cda5a;

  sStack_4 = DAT_007cda5c;

  sStack_2 = DAT_007cda5e;

  FUN_0040e3c0((float)param_5, param_3 + 0x17d, param_4 + 0x97, param_6, 0xb1, 0);

  FUN_0040e3c0((float)param_5, param_3 + 0x17d, param_4 + 0x97, param_6 & 0xff, 0xb2, 0);

  FUN_0040e3c0((float)param_5, param_3 + 0x17d, param_4 + 0x97, param_6 & 0xff, 0xb5, 0);

  FUN_0040e3c0((float)param_5, param_3 + 0x1ed, param_4 + 0x9f, param_6 & 0xff, 5, *(u8 *)(iVar1 + 0xa4));

  FUN_0040e3c0((float)param_5, param_3 + 0x17d, param_4 + 0x97, param_6 & 0xff, 0xb3, 0);

  FUN_0040e3c0((float)param_5, param_3 + 0x17d, param_4 + 0x97, param_6 & 0xff, 0xb4, 0);

  FUN_0040e3c0((float)param_5, param_3 + 0x17d, param_4 + 0xb3, param_6 & 0xff, 0xb5, 0);

  if (*(char *)(iVar1 + 0x54) == '\r') {

    FUN_0040e3c0((float)param_5, param_3 + 0x17d, param_4 + 0xb3, param_6 & 0xff, 0xb7, 0);

  }

  else {

    sprintf((char *)auStack_10,(const char *)0x7cda50,*(u16 *)(iVar1 + 0x60));

    FUN_0040eb50(0,param_3 + 0x17d + (int)sStack_8,param_4 + 0xb3 + (int)sStack_6,param_6,1,

                 auStack_10,2);

  }

  FUN_0040e3c0((float)param_5, param_3 + 0x17d, param_4 + 0xb3, param_6 & 0xff, 0xb6, 0);

  sprintf((char *)auStack_10,(const char *)0x7cda50,*(u16 *)(iVar1 + 0xb0));

  iVar2 = param_3 + 0x17d + (int)sStack_4;

  iVar3 = (int)sStack_2;

  FUN_0040eb50(0,iVar2,param_4 + 0xb3 + iVar3,param_6,1,auStack_10,2);

  FUN_0040e3c0((float)param_5, param_3 + 0x17d, param_4 + 0xcf, param_6 & 0xff, 0xb5, 0);

  if (*(char *)(iVar1 + 0x54) == '\r') {

    FUN_0040e3c0((float)param_5, param_3 + 0x17d, param_4 + 0xcf, param_6 & 0xff, 0xb7, 0);

  }

  else {

      sprintf((char *)auStack_10,(const char *)0x7cda50,*(u16 *)(iVar1 + 0x62));

    FUN_0040eb50(0,param_3 + 0x17d + (int)sStack_8,param_4 + 0xcf + (int)sStack_6,param_6,1,

                 auStack_10,2);

  }

  FUN_0040e3c0((float)param_5, param_3 + 0x17d, param_4 + 0xcf, param_6 & 0xff, 0xb6, 0);

  sprintf((char *)auStack_10,(const char *)0x7cda50,*(u16 *)(iVar1 + 0xb2));

  FUN_0040eb50(0,iVar2,param_4 + 0xcf + iVar3,param_6,1,auStack_10,2);

  return;

}

// FUN_00416B90 NONMATCHING


void FUN_00416b90(u64 param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6)



{

  int iVar1;

  float fVar2;

  float fVar3;

  

  iVar1 = *(int *)(param_2 + 0xc);

  fVar3 = DAT_007caef0 * (float)(int)param_6;

  fVar2 = fVar3;
  if (2147483648.0f <= fVar3) {
    fVar2 = fVar3;
  } else {
    fVar2 = fVar3 - 2147483648.0f;
  }
  FUN_0040e3c0((float)param_5,param_3 + 0x126,param_4 + 0xf5,
               ((2147483648.0f <= fVar3)
                ? (s32)fVar3
                : ((s32)(fVar3 - 2147483648.0f) | 0x80000000)) & 0xff,
               0xf8,0);
  FUN_0040e3c0((float)param_5,param_3 + 0x126,param_4 + 0xf5,
               ((2147483648.0f <= fVar3)
                ? (s32)fVar3
                : ((s32)(fVar3 - 2147483648.0f) | 0x80000000)) & 0xff,
               0xf9,0);

  FUN_003c7e20(0,param_3 + 0x148,param_4 + 0xf9,param_6 | 0xffffffffffffff00,1,5,1,
               (u32)CONCAT12(*(u8 *)(iVar1 + 0xa9),*(u16 *)(iVar1 + 0xa0)));

  return;

}

/* W327 measured: opt_common_subs off normalized_diff 582 -> 458; object 804/784 -> 784/784 (without/with). */
#pragma opt_common_subs off
// FUN_00416D20 NONMATCHING


void FUN_00416d20(u64 param_1,int param_2,int param_3,int param_4,int param_5,

                 u8 param_6)



{

  int iVar1;

  u64 uVar2;

  

  iVar1 = *(int *)(param_2 + 0xc);

  FUN_0040e3c0((float)param_5, param_3 + -7, param_4 + 0x47, param_6 & 0xff, 0xba, 0);

  FUN_0040e3c0((float)param_5, param_3 + -7, param_4 + 0x47, param_6 & 0xff, 0xbb, 0);

  FUN_0040e3c0((float)param_5, param_3 + -7, param_4 + 0x47, param_6 & 0xff, 0xbc, 0);

  FUN_0040e3c0((float)param_5, param_3 + -7, param_4 + 0x47, param_6 & 0xff, 0xbd, 0);

  FUN_0040e3c0((float)param_5, param_3 + -7, param_4 + 0x47, param_6 & 0xff, 0xbe, 0);

  FUN_0040e3c0((float)param_5, param_3 + -7, param_4 + 0x47, param_6 & 0xff, 0xbf, 0);

  FUN_0040e3c0((float)param_5, param_3 + -7, param_4 + 0x47, param_6 & 0xff, 0xc0, 0);

  if (*(char *)(iVar1 + 0xbe) < '\n') {

    FUN_0040e3c0((float)param_5, param_3 + 0x1d, param_4 + 0x9c, param_6 & 0xff, 6, 0);

  }

  else {

    FUN_0040e3c0((float)param_5, param_3 + 0xc, param_4 + 0x9c, param_6 & 0xff, 6, (int)*(char *)(iVar1 + 0xbe) / 10);

    FUN_0040e3c0((float)param_5, param_3 + 0x21, param_4 + 0x9c, param_6 & 0xff, 6, (int)*(char *)(iVar1 + 0xbe) % 10);

  }

  if (*(char *)(iVar1 + 0xbf) < '\n') {

    FUN_0040e3c0((float)param_5, param_3 + 0x5f, param_4 + 0x9f, param_6 & 0xff, 7, 0);

  }

  else {

    FUN_0040e3c0((float)param_5, param_3 + 0x50, param_4 + 0x9f, param_6 & 0xff, 7, (int)*(char *)(iVar1 + 0xbf) / 10);

    FUN_0040e3c0((float)param_5, param_3 + 0x6a, param_4 + 0x9f, param_6 & 0xff, 7, (int)*(char *)(iVar1 + 0xbf) % 10);

  }

  uVar2 = clndGetDaysSinceStartFromDate(*(u8 *)(iVar1 + 0xbe),*(u8 *)(iVar1 + 0xbf));

  iVar1 = clndGetWeekDay(uVar2);

  FUN_0040e3c0((float)param_5, param_3 + 0x6b, param_4 + 0xb9, param_6 & 0xff, 8, (iVar1 + 6) % 7);

  return;

}

#pragma opt_common_subs reset
// FUN_00417030 NONMATCHING


u64 FUN_00417030(int param_1, int param_2) { int call_param_1;

int call_param_2;

int iVar8;

int iVar1;

u8 *puVar2;

u8 *puVar3;

s16 *puVar4;

u8 **ppuVar7;

u32 *puVar6;

int iVar5;

u32 auStack_20 [6];

FclShopBgCallbackPair *puStack_8;
float fVar0;

float fVar1;



call_param_1 = param_1;

call_param_2 = param_2;
iVar1 = *(int *)((int)param_2 + 0xc);

ppuVar7 = (u8 **)&PTR_FUN_006b1830;

puVar6 = auStack_20;

iVar5 = 3;

do {

  puVar2 = *ppuVar7;

  puVar3 = ppuVar7[1];

  ppuVar7 = ppuVar7 + 2;

  iVar5 = iVar5 + -1;

  *puVar6 = (u32)(puVar2);

  puVar6[1] = (u32)(puVar3);

  puVar6 = puVar6 + 2;

} while (0 < iVar5);

puStack_8 = (FclShopBgCallbackPair *)(auStack_20 + 6);

fVar1 = DAT_007cda64_f;

fVar0 = *(float *)((u8 *)&DAT_007cda64_f + 4);

*(float *)(auStack_20 + 6) = fVar1;

*(float *)(auStack_20 + 7) = fVar0;

*(u32 *)(auStack_20 + 6) = (u32)auStack_20;

iVar5 = *(int *)(iVar1 + 0x4c) >> 1;

puVar6 = puStack_8[iVar5].callbacks;

iVar5 = puStack_8[iVar5].count;

for (iVar8 = 0; iVar8 < iVar5; iVar8 = iVar8 + 1) {
  puVar4 = (s16 *)(iVar1 + iVar8 * 0xc);

    ((FclShopBgCallback)puVar6[iVar8])
              (0,*(float *)(puVar4 + 4),*(float *)(puVar4 + 4),call_param_1,call_param_2,*puVar4,
               puVar4[1],0,puVar4[2],0,0);

}

return 0; }
