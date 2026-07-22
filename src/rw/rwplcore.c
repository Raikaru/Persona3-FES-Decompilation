



#include "mw_harvest_compat.h"
#include "rw/rwplcore.h"


typedef unsigned int int3;
typedef unsigned int undefined3;
#ifndef CONCAT13
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))
#endif

typedef char* va_list;
#define va_start(ap, last) (ap = ((va_list)__builtin_next_arg(last) - (__builtin_args_info(2) >= 8 ? 0 : (8 - __builtin_args_info(2)) * 8)))
#define va_end(ap) ((void)0)
extern u32 FUN_00508900(u32 param_1);
/* auto-extern (generated) */
extern u8 DAT_00780000[];
void FUN_004c38c0(void);
u32 * FUN_004c0070(u64 param_1);
void FUN_004c3b70(int param_1);
u32 FUN_004ca030(u64 param_1);
u64 FUN_004c9db0(u32 param_1,u64 param_2);
u32 * FUN_004bfd50(u64 param_1);
long FUN_004ca090(void);
u64 FUN_004c53f0(u64 param_1,u64 param_2,u32 param_3);
void FUN_004ca520(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
#pragma alias FUN_004c61b0_raw FUN_004c61b0
extern void FUN_004c61b0_raw();
u32 FUN_004c3c30(int param_1);
long FUN_004c1d10(RwInt32 param_1,...);
u32 FUN_004bfde0(u64 param_1);
u64 FUN_004c1c50(u64 param_1);
u32 FUN_004bfa70(int param_1,u64 param_2);
void FUN_004c6e60(int param_1);
u32 FUN_004c6e50(void);
u64 FUN_004c58a0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_004c9d20(u64 param_1,u32 *param_2);
u64 FUN_004c5620(u64 param_1,u32 param_2);
RwBool RwEngineSetMatrixTolerances(const RwMatrixTolerance* const tolerance);
u32 FUN_004c5250(int *param_1,u64 param_2,u32 param_3);
u64 FUN_004c9d70(u32 param_1,u64 param_2);
u32 FUN_004ca3e0(int param_1,u64 param_2,u64 param_3,u64 param_4,long param_5);
u32 FUN_004ca500(void);
bool FUN_004c6df0(u32 *param_1,int param_2);
long FUN_004bfea0(long param_1,u64 param_2,u32 param_3,u32 param_4,
                 u32 param_5);
u32 FUN_004bfc20(void);
bool FUN_004c5780(u64 param_1,long param_2);
u32 * FUN_004c0060(void);
u32 FUN_004c4d70(void);
extern u32* puGpffffbbf8;
extern u32 uGpffffb078;
extern u32 DAT_007cdd28;
extern u32 DAT_007cdd40;
extern u32 DAT_007cdd54;
extern u32 DAT_007cdd5c;
extern u32 DAT_007ce8d8;
extern u32 DAT_007ce910;
extern u64 FUN_00520748();
extern u64 FUN_00523ac8();
extern u64 FUN_00523b40();
extern u64 FUN_00523e68();
extern u64 FUN_00524128();
extern u64 FUN_00524270();
extern u64 FUN_005244c0();
extern u64 FUN_00524670();
extern u64 FUN_00525958();
extern u64 FUN_005288c8();
extern u8 LAB_004c4420;
extern u8 LAB_004c4430;
extern u8 LAB_004c4440;
extern u8 LAB_004c7100;
extern u8 LAB_004c71c0;
extern u8 LAB_004c7210;
extern u8 LAB_004c7260;
extern u8 LAB_004c72a0;
extern u8* iGpffffbbe0;
extern u32 uGpffffb044;
extern u32 uGpffffb074;
extern u32 DAT_0077e5b0;
extern u32 DAT_0077e5b8;
extern u32 DAT_0077e5e0;
extern u32 DAT_007cdd3c;
extern u32 DAT_007cdd50;
extern u32 DAT_007cdd58;
extern u32 DAT_007cdd60;
extern u32 DAT_007ce8b8;
extern u32* DAT_007ce8bc;
extern u32 DAT_007ce8c0;
extern u32 DAT_007ce8e0;
extern int DAT_007ce8e4;
extern u32* DAT_007ce8e8;
extern u32 DAT_007ce8ec;
extern u32* DAT_007ce8f0;
extern u32 DAT_007ce8f4;
extern u32* DAT_007ce8f8;
extern u32 DAT_007ce8fc;
extern u32* DAT_007ce900;
extern u32 DAT_007ce904;
extern u32* DAT_007ce908;
extern u32 DAT_007ce918;
extern u32 DAT_007ce91c;
extern u32* DAT_0095ff10;
extern u32 DAT_0095ff10_object[];
extern u32 DAT_0095ff14;
extern u32 DAT_0095ff18;
extern u32 DAT_0095ff1c;
extern code *DAT_0095ff24;
extern u32 DAT_0095ff34;
extern u32 DAT_0095ff38;
extern u32* DAT_00960070;
#pragma alias DAT_00960070_abs DAT_00960070
extern u8 DAT_00960070_abs[];
extern u32 DAT_00960074;
extern u32 DAT_00960078;
extern u32* DAT_0096007c;
extern u8 DAT_00960080[];
extern u32 DAT_00960084;
extern u32 DAT_00960088;
extern u32 DAT_0096008c;
extern u32 DAT_00960090;
extern u32 DAT_00960094;
extern code *DAT_009600bc;
extern code *DAT_00960120;
extern u32 DAT_00960134;
extern u32 DAT_00960138;
extern code *DAT_0096013c;
extern u32 DAT_00960140;
extern u32 DAT_00960144;
extern u32 DAT_00960148;
extern u32 DAT_0096014c;
extern u32 DAT_00960150;
extern u32 DAT_00960154;
extern code *DAT_00960158;
extern u32 DAT_0096015c;
extern code *DAT_00960160;
extern code *DAT_00960164;
extern u32 DAT_00960168;
extern u32 DAT_0096016c;
extern u32 DAT_00960170;
extern u32 DAT_00960174;
extern code *DAT_00960178;
#pragma alias DAT_0096017c_abs DAT_0096017c
extern void (*DAT_0096017c_abs[])(u32);
extern code *DAT_0096017c;
extern code *DAT_00960180;
extern code *DAT_00960184;
extern code *DAT_00960188;
#pragma alias DAT_0096018c_abs DAT_0096018c
extern void (*DAT_0096018c_abs[])(u32,u64);
extern code *DAT_0096018c;
extern u32 DAT_00960194;
extern u32 DAT_00960198;
extern u64 FUN_004bf560();
extern u64 FUN_004c9b40();
extern u8 LAB_004bf9e0;
extern u8 LAB_004c0830;
extern u8 LAB_004c0870;
extern u8 LAB_004c0880;
extern u8 LAB_004c08a0;
extern u8 LAB_004c0a70;
extern u8 LAB_004c0a80;
extern u8 LAB_004c0f60;
#pragma alias LAB_004c2200_abs LAB_004c2200
extern u8 LAB_004c2200_abs[];
extern u8 LAB_004c0fc0;
extern u8 LAB_004c2200;
extern u8 LAB_004c6140;
extern u8 LAB_004c6150;
extern u8 LAB_004c6160;
extern u8 LAB_004c6640;
extern u8 LAB_004c6700;
extern u8 LAB_004c67a0;
extern u8 LAB_004c6840;
extern void* PTR_DAT_007be9c8;
extern u8* iGpffffb048;
extern int iGpffffbbe8;
extern int iGpffffbbec;
extern int iGpffffbbf4;
extern u8* iGpffffbc30;
extern u8* iGpffffbc34;
extern u8* iGpffffbc38;
extern u32 uGpffffb040;
extern u32 uGpffffb048;
extern u32 uGpffffbc38;

extern RwUInt32 func_004c1d10(RwUInt32 errorCode, ...);
extern void func_004c1c50(void* error);
extern RwMatrix* func_004c2fc0(RwReal oneMinusCosine, RwReal sine, RwMatrix* matrix, const RwV3d* axis, RwOpCombineType combineOp);
extern RwBool func_004c3960(RwBool useDefaultMemory);
extern void func_004c3d10(void);
extern void func_004c3ee0(void);
extern void func_004ca380(void);
extern void func_004ca3a0(void);
extern RwBool func_004c72e0(void);
extern RwBool func_004c4450(const RwMemoryFunctions* memFuncs);
extern RwBool func_004c5f70(void);
extern RwBool func_004ca190(void);
extern RwBool func_004e00e0(void);
extern void func_004c6000(void);
extern void func_004c4570(void);
extern void func_004c7400(void);
extern RwReal sinf(RwReal angle);
extern RwReal cosf(RwReal angle);
extern RwReal sqrtf(RwReal value);
#ifndef SQRT
#define SQRT(x) sqrtf(x)
#endif
long thunk_FUN_004c3970(int param_1,u32 param_2,long param_3,int param_4,long param_5,u32 param_6);

typedef RwV3d* (*RwV3dTransformPointFn)(RwV3d* pointOut, const RwV3d* pointIn, const RwMatrix* matrix);

extern RwInt32 rwV3dTransformPointOffset;
extern RwInt32 rwMatrixTolerancesOffset;
#pragma optimization_level 3

// 00960070
RwGlobals rwGlobals;

// FUN_004BE310 NONMATCHING
void FUN_004be310(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar2 = param_1[1];
  fVar4 = param_1[2];
  fVar1 = param_1[3];
  *param_3 = *param_1;
  param_3[1] = fVar2;
  param_3[2] = fVar4;
  param_3[3] = fVar1;
  fVar1 = param_1[3] * param_2[3] +
          param_1[2] * param_2[2] + *param_1 * *param_2 + param_1[1] * param_2[1];
  if (fVar1 < 0.0) {
    if (fVar1 < -1.0) {
      fVar2 = 1.0;
    }
    else {
      fVar2 = -fVar1;
    }
    param_3[7] = -param_2[3];
    param_3[4] = -*param_2;
    param_3[5] = -param_2[1];
    param_3[6] = -param_2[2];
  }
  else {
    fVar2 = 1.0;
    if (1.0 < fVar1) {
      fVar4 = *param_2;
    }
    else {
      fVar4 = *param_2;
      fVar2 = fVar1;
    }
    fVar3 = param_2[1];
    fVar5 = param_2[2];
    fVar1 = param_2[3];
    param_3[4] = fVar4;
    param_3[5] = fVar3;
    param_3[6] = fVar5;
    param_3[7] = fVar1;
  }
  fVar1 = ABS(fVar2);
  if ((u32)fVar1 < 0x3f800000) {
    if ((u32)fVar1 < 0x3f000000) {
      if ((u32)fVar1 < 0x23000001) {
        param_3[8] = 1.5707964;
      }
      else {
        fVar1 = fVar2 * fVar2;
        param_3[8] = 1.5707963 -
                     (fVar2 - (7.5497894e-08 -
                              fVar2 * ((fVar1 * (fVar1 * (fVar1 * (fVar1 * (fVar1 * (fVar1 * 
                                                  3.479331e-05 + 0.000791535) + -0.040055536) +
                                                  0.20121253) + -0.32556581) + 0.16666667)) /
                                      (fVar1 * (fVar1 * (fVar1 * (fVar1 * 0.077038154 + -0.688284) +
                                                        2.0209458) + -2.403395) + 1.0))));
      }
    }
    else if ((int)fVar2 < 0) {
      fVar1 = (fVar2 + 1.0) * 0.5;
      param_3[8] = 3.1415925 -
                   (SQRT(fVar1) +
                   (((fVar1 * (fVar1 * (fVar1 * (fVar1 * (fVar1 * (fVar1 * 3.479331e-05 +
                                                                  0.000791535) + -0.040055536) +
                                                0.20121253) + -0.32556581) + 0.16666667)) /
                    (fVar1 * (fVar1 * (fVar1 * (fVar1 * 0.077038154 + -0.688284) + 2.0209458) +
                             -2.403395) + 1.0)) * SQRT(fVar1) - 7.5497894e-08)) * 2.0;
    }
    else {
      fVar4 = (1.0 - fVar2) * 0.5;
      fVar3 = SQRT(fVar4);
      fVar1 = (float)((u32)fVar3 & 0xfffff000);
      param_3[8] = (fVar1 + ((fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * 3.479331e-05 +
                                                                          0.000791535) +
                                                                 -0.040055536) + 0.20121253) +
                                               -0.32556581) + 0.16666667)) /
                            (fVar4 * (fVar4 * (fVar4 * (fVar4 * 0.077038154 + -0.688284) + 2.0209458
                                              ) + -2.403395) + 1.0)) * fVar3 +
                            ((fVar4 + 0.0) - fVar1 * fVar1) / (fVar3 + fVar1) + 0.0) * 2.0;
    }
  }
  else if ((int)fVar2 < 1) {
    param_3[8] = 3.1415927;
  }
  else {
    param_3[8] = 0.0;
  }
  param_3[9] = (float)(u32)(0.99999 <= fVar2);
  if (param_3[9] == 0.0) {
    fVar2 = param_3[8];
    fVar1 = fVar2 * fVar2;
    fVar1 = 1.0 / (fVar1 * fVar2 *
                   (fVar1 * (fVar1 * (fVar1 * (fVar1 * (fVar1 * 1.589691e-10 + -2.505076e-08) +
                                              2.7557314e-06) + -0.0001984127) + 0.008333334) +
                   -0.16666667) + fVar2 + 0.0);
    param_3[3] = param_3[3] * fVar1;
    *param_3 = *param_3 * fVar1;
    param_3[1] = param_3[1] * fVar1;
    param_3[2] = param_3[2] * fVar1;
    param_3[7] = param_3[7] * fVar1;
    param_3[4] = param_3[4] * fVar1;
    param_3[5] = param_3[5] * fVar1;
    param_3[6] = param_3[6] * fVar1;
  }
  return;
}
#pragma optimization_level 2
// FUN_004BE930 NONMATCHING
u64
FUN_004be930(u64 param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6)

{
  u8 uVar1;
  u8 uVar2;
  u32 uVar3;
  int iVar4;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_4;
  
  iVar4 = param_2 * 0x18 + 7;
  if (iVar4 < 0) {
    iVar4 = param_2 * 0x18 + 0xe;
  }
  iVar4 = ((iVar4 >> 3) + 1U & 0xfffffffe) * param_3;
  uStack_30 = 0x956aa659;
  (*(u8*)((u8*)&uStack_4 + 0)) = (u8)param_2;
  uVar1 = (u8)uStack_4;
  (*(u8*)((u8*)&uStack_4 + 3)) = (u8)((u32)param_2 >> 0x18);
  (*(u8*)((u8*)&uStack_4 + 1)) = (u8)((u32)param_2 >> 8);
  uVar2 = (*(u8*)((u8*)&uStack_4 + 1));
  (*(u8*)((u8*)&uStack_4 + 2)) = (u8)((u32)param_2 >> 0x10);
  (*(u16*)((u8*)&uStack_4 + 0)) = CONCAT11((*(u8*)((u8*)&uStack_4 + 2)),(*(u8*)((u8*)&uStack_4 + 3)));
  uStack_4 = (uStack_4 & 0xFF000000) | CONCAT12(uVar2,(u16)uStack_4);
  uStack_4 = CONCAT13(uVar1,(undefined3)uStack_4);
  uStack_2c = uStack_4;
  (*(u8*)((u8*)&uStack_4 + 0)) = (u8)param_3;
  uVar1 = (u8)uStack_4;
  (*(u8*)((u8*)&uStack_4 + 3)) = (u8)((u32)param_3 >> 0x18);
  (*(u8*)((u8*)&uStack_4 + 1)) = (u8)((u32)param_3 >> 8);
  uVar2 = (*(u8*)((u8*)&uStack_4 + 1));
  (*(u8*)((u8*)&uStack_4 + 2)) = (u8)((u32)param_3 >> 0x10);
  (*(u16*)((u8*)&uStack_4 + 0)) = CONCAT11((*(u8*)((u8*)&uStack_4 + 2)),(*(u8*)((u8*)&uStack_4 + 3)));
  uStack_4 = (uStack_4 & 0xFF000000) | CONCAT12(uVar2,(u16)uStack_4);
  uStack_4 = CONCAT13(uVar1,(undefined3)uStack_4);
  uStack_28 = uStack_4;
  uStack_24 = 0x18000000;
  (*(u8*)((u8*)&uStack_4 + 0)) = (u8)iVar4;
  uVar1 = (u8)uStack_4;
  (*(u8*)((u8*)&uStack_4 + 3)) = (u8)((u32)iVar4 >> 0x18);
  (*(u8*)((u8*)&uStack_4 + 1)) = (u8)((u32)iVar4 >> 8);
  uVar2 = (*(u8*)((u8*)&uStack_4 + 1));
  (*(u8*)((u8*)&uStack_4 + 2)) = (u8)((u32)iVar4 >> 0x10);
  (*(u16*)((u8*)&uStack_4 + 0)) = CONCAT11((*(u8*)((u8*)&uStack_4 + 2)),(*(u8*)((u8*)&uStack_4 + 3)));
  uStack_4 = (uStack_4 & 0xFF000000) | CONCAT12(uVar2,(u16)uStack_4);
  uStack_4 = CONCAT13(uVar1,(undefined3)uStack_4);
  uStack_20 = uStack_4;
  uStack_1c = 0x1000000;
  uStack_18 = 0x1000000;
  uStack_4 = 0;
  uStack_14 = 0;
  iVar4 = (int)param_1;
  *(int *)(iVar4 + 0xc) = param_2;
  *(int *)(iVar4 + 0x10) = param_3;
  *(int *)(iVar4 + 0x14) = param_4;
  *(int *)(iVar4 + 0x18) = param_5;
  *(int *)(iVar4 + 0x1c) = param_2 / param_4;
  *(int *)(iVar4 + 0x20) = param_3 / param_5;
  *(u32 *)(iVar4 + 4) = param_6;
  uVar3 = FUN_004c58a0(2,2,*(u32 *)(iVar4 + 4));
  *(u32 *)(iVar4 + 8) = uVar3;
  if (*(int *)(iVar4 + 8) == 0) {
    *(u32 *)(iVar4 + 0x30) = 0;
  }
  else {
    FUN_004c53f0(*(int *)(iVar4 + 8),(u64)(unsigned int)(&uStack_30),0x20);
    *(int *)(iVar4 + 0x24) = param_5 * *(int *)(iVar4 + 0x1c) * param_4 * 3;
    uVar3 = (*DAT_00960178)(*(u32 *)(iVar4 + 0x24),0x30191);
    *(u32 *)(iVar4 + 0x30) = uVar3;
    FUN_00521408(*(u32 *)(iVar4 + 0x30),0,*(u32 *)(iVar4 + 0x24));
  }
  return param_1;
}
// FUN_004BEC20 NONMATCHING
long FUN_004bec20(long param_1,long param_2,long param_3,long param_4,long param_5,code *param_6,
                 code *param_7,int *param_8,int param_9)

{
  int iVar1;
  u32 uVar2;
  float *pfVar3;
  long lVar4;
  u64 uVar5;
  long lVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  long lVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  long lVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  int *piStack_b0;
  int iStack_a0;
  int iStack_94;
  int aiStack_60 [2];
  int iStack_58;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  u32 uStack_20;
  u32 uStack_1c;
  int iStack_18;
  int iStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar17 = (int)param_4;
  iVar11 = (int)param_5;
  if (((((param_2 < 1) || (param_3 < 1)) || (param_4 < 1)) || ((param_5 < 1 || (param_2 < param_4)))
      ) || ((param_3 < param_5 || (param_1 == 0)))) {
    param_1 = 0;
  }
  else {
    iVar10 = (int)param_2;
    if ((iVar10 % iVar17 < 1) && (iVar16 = (int)param_3, iVar16 % iVar11 < 1)) {
      lVar18 = 0;
      lVar13 = 0;
      iStack_94 = 0;
      iStack_a0 = 0;
      iVar12 = 0;
      aiStack_60[0] = param_9;
      iStack_58 = 0;
      iStack_30 = 0;
      lVar4 = FUN_004ca090();
      iVar14 = (int)param_1;
      iVar1 = *(int *)(iVar14 + 0x14);
      iVar7 = *(int *)(iVar14 + 0x60);
      uVar2 = *(u32 *)(iVar14 + 100);
      pfVar3 = (float *)FUN_004cb2f0(*(u32 *)(iVar14 + 4));
      fVar27 = *(float *)(iVar14 + 0x78);
      fVar30 = *(float *)(iVar14 + 0x7c);
      fVar28 = *(float *)(iVar14 + 0x68);
      fVar29 = *(float *)(iVar14 + 0x6c);
      if (param_1 != 0) {
        iVar15 = (int)lVar4;
        *(u32 *)(iVar15 + 0x18) = *(u32 *)(iVar14 + 0x18);
        *(u32 *)(iVar15 + 0x1c) = *(u32 *)(iVar14 + 0x1c);
        FUN_004c9d70(*(u32 *)(iVar14 + 0x80),lVar4);
        FUN_004c9db0(*(u32 *)(iVar14 + 0x84),lVar4);
        FUN_004c9f00(lVar4,iVar1);
        if ((*(int *)(iVar7 + 0xc) < iVar17) || (*(int *)(iVar7 + 0x10) < iVar11)) {
          param_1 = 0;
        }
        else {
          uStack_20 = 0;
          uStack_1c = 0;
          iStack_18 = iVar17;
          iStack_14 = iVar11;
          lVar13 = FUN_004ce0f0(0,0,0,2);
          if (lVar13 == 0) {
            param_1 = 0;
          }
          else {
            FUN_004ce050(lVar13,iVar7,&uStack_20);
            *(int *)(iVar15 + 0x60) = (int)lVar13;
          }
          uVar5 = FUN_004ce0f0(0,0,0,1);
          iStack_94 = (int)uVar5;
          if (lVar13 == 0) {
            param_1 = 0;
          }
          else {
            FUN_004ce050(uVar5,uVar2,&uStack_20);
            *(int *)(iVar15 + 100) = iStack_94;
          }
        }
      }
      if (param_1 != 0) {
        lVar18 = FUN_004cbe00(iVar17,iVar11,0x20);
        if (lVar18 == 0) {
          param_1 = 0;
        }
        else {
          lVar6 = FUN_004cbf20(lVar18);
          if (lVar6 == 0) {
            param_1 = 0;
          }
        }
      }
      if (param_1 != 0) {
        lVar6 = FUN_004caf10();
        iStack_a0 = (int)lVar6;
        if (lVar6 == 0) {
          param_1 = 0;
        }
        else {
          pfVar8 = (float *)(iStack_a0 + 0x10);
          iVar7 = 8;
          pfVar9 = pfVar3;
          do {
            iVar7 = iVar7 + -1;
            fVar19 = pfVar9[1];
            *pfVar8 = *pfVar9;
            pfVar9 = pfVar9 + 2;
            pfVar8[1] = fVar19;
            pfVar8 = pfVar8 + 2;
          } while (0 < iVar7);
          iVar12 = iStack_a0 + 0x10;
          FUN_004d1840(lVar4,iStack_a0);
        }
      }
      if (param_1 != 0) {
        iVar7 = iVar10 / iVar17;
        iVar14 = iVar16 / iVar11;
        fStack_8 = 1.0;
        if (param_9 == 2) {
          if (param_2 < param_3) {
            fStack_8 = (float)iVar10 / (float)iVar16;
          }
          if (param_3 < param_2) {
            fStack_4 = (float)iVar16 / (float)iVar10;
          }
          else {
            fStack_4 = 1.0;
          }
          fStack_8 = fStack_8 * (1.0 / (float)iVar7);
          fStack_4 = fStack_4 * (1.0 / (float)iVar14);
        }
        else if (param_3 < param_2) {
          fStack_4 = fVar29 / (float)iVar14;
          fStack_8 = (fStack_4 * (float)iVar17) / (float)iVar11;
        }
        else {
          fStack_8 = fVar28 / (float)iVar7;
        }
        fVar21 = fVar29 / fVar28;
        fVar19 = (float)iVar16 / (float)iVar10;
        if (fVar19 < fVar21) {
          iStack_38 = (int)((float)iVar10 * (fVar19 / fVar21));
          iStack_34 = iVar16;
        }
        else {
          iStack_38 = iVar10;
          iStack_34 = (int)((float)iVar16 * (fVar21 / fVar19));
        }
        FUN_004c9f90(lVar4,&fStack_8);
        fStack_8 = fStack_8 * 2.0;
        fVar19 = fStack_4;
        piStack_b0 = param_8;
        if ((param_7 == (code *)FUN_004bf560) && (param_8 != (int *)0x0)) {
    FUN_004be930((u64)(unsigned int)(aiStack_60),param_2,param_3,iVar17,iVar11,(u64)(unsigned int)(param_8));
          piStack_b0 = aiStack_60;
        }
        iVar17 = 0;
        fVar21 = -((fVar29 + 0.0) - fStack_4 * 0.5);
        if (0 < iVar14) {
          do {
            iVar11 = 0;
            fVar26 = fStack_8 * 0.5;
            fVar25 = fVar28 - fVar26;
            if (0 < iVar7) {
              fVar24 = fVar21 + fVar30;
              fVar23 = -fVar21;
              fVar31 = fVar28;
              do {
                iVar10 = iVar7;
                if ((0.0 < fVar26) && (0.0 < fVar19)) {
                  fVar20 = pfVar3[1];
                  fVar22 = pfVar3[2];
                  *(float *)(iVar12 + 0x30) = *pfVar3 * fVar25 + pfVar3[0xc] + 0.0;
                  *(float *)(iVar12 + 0x34) = fVar20 * fVar25 + pfVar3[0xd];
                  *(float *)(iVar12 + 0x38) = fVar22 * fVar25 + pfVar3[0xe];
                  fVar20 = pfVar3[5];
                  fVar22 = pfVar3[6];
                  *(float *)(iVar12 + 0x30) = pfVar3[4] * fVar23 + *(float *)(iVar12 + 0x30) + 0.0;
                  *(float *)(iVar12 + 0x34) = *(float *)(iVar12 + 0x34) + fVar20 * fVar23;
                  *(float *)(iVar12 + 0x38) = *(float *)(iVar12 + 0x38) + fVar22 * fVar23;
                  FUN_004c2d20(iVar12,0);
                  if (iVar1 == 1) {
                    fStack_10 = fVar25 + fVar27;
                    fStack_c = fVar24;
                  }
                  FUN_004cb270(iStack_a0);
                  lVar6 = (*param_6)(lVar4,iVar11,iVar17,param_8);
                  iVar10 = iVar11;
                  if (lVar6 != lVar4) {
                    param_1 = 0;
                  }
                }
                if (param_1 != 0) {
                  iVar11 = (int)lVar13;
                  if (lVar13 != 0) {
                    DAT_007ce8b8 = *(u32 *)(iVar11 + 4);
                    *(u32 *)(iVar11 + 4) = *(u32 *)((int)lVar18 + 0x14);
                    lVar6 = FUN_004ce200(lVar13,0,2);
                    if (lVar6 == 0) {
                      *(u32 *)(iVar11 + 4) = DAT_007ce8b8;
                    }
                  }
                  FUN_004cde00(lVar13);
                  *(u32 *)(iVar11 + 4) = DAT_007ce8b8;
                  lVar6 = (*param_7)(lVar18,iVar10,iVar17,piStack_b0);
                  if (lVar6 == 0) {
                    param_1 = 0;
                  }
                }
                if (param_1 == 0) break;
                fVar20 = fStack_8 * 0.5;
                fVar31 = fVar31 - fVar20;
                if ((param_9 == 1) && (fVar26 = fVar20, fVar31 <= fVar20)) {
                  fVar26 = fVar31;
                }
                iVar11 = iVar10 + 1;
                fVar25 = fVar25 - fStack_8;
              } while (iVar11 < iVar7);
            }
            if (param_1 == 0) break;
            fVar26 = fStack_4 * 0.5;
            fVar29 = fVar29 - fVar26;
            if ((param_9 == 1) && (fVar19 = fVar26, fVar29 <= fVar26)) {
              fVar19 = fVar29;
            }
            iVar17 = iVar17 + 1;
            fVar21 = fVar21 + fStack_4;
          } while (iVar17 < iVar14);
        }
      }
      if (iStack_a0 != 0) {
        FUN_004caf80(iStack_a0);
      }
      if (lVar18 != 0) {
        FUN_004cbeb0(lVar18);
      }
      if (lVar13 != 0) {
        FUN_004cde90(lVar13);
      }
      if (iStack_94 != 0) {
        FUN_004cde90(iStack_94);
      }
      if (lVar4 != 0) {
      }
      if (iStack_58 != 0) {
      }
      if (iStack_30 != 0) {
        (*DAT_0096017c)();
      }
    }
    else {
      param_1 = 0;
    }
  }
  return param_1;
}
// FUN_004BF540 NONMATCHING
void FUN_004bf540(void)

{
  FUN_004bec20(0,0,0,0,0,0,0,0,0);
  return;
}
// FUN_004BF560 NONMATCHING
u64 FUN_004bf560(u64 param_1,int param_2,int param_3,long param_4)

{
  int iVar1;
  int iVar2;
  u8 *puVar3;
  u8 *puVar4;
  int *piVar5;
  int iVar6;
  u8 *puVar7;
  u8 *puVar8;
  int iVar9;
  int iVar10;
  
  if (param_4 != 0) {
    piVar5 = (int *)param_4;
    if (param_2 < piVar5[7]) {
      param_3 = param_3 * piVar5[6];
      puVar4 = *(u8 **)((int)param_1 + 0x14);
      iVar1 = *(int *)((int)param_1 + 0x10);
      iVar2 = piVar5[3];
      iVar6 = 0;
      puVar3 = (u8 *)(piVar5[0xc] + param_2 * piVar5[5] * 3);
      if (0 < piVar5[6]) {
        do {
          iVar9 = param_2 * piVar5[5];
          iVar10 = 0;
          puVar8 = puVar3;
          puVar7 = puVar4;
          if (piVar5[5] < 1) {
LAB_004bf6a4:
            iVar9 = *piVar5;
          }
          else {
            do {
              *puVar8 = puVar7[2];
              puVar8[1] = puVar7[1];
              puVar8[2] = *puVar7;
              puVar7 = puVar7 + 4;
              puVar8 = puVar8 + 3;
              if ((*piVar5 == 1) && (piVar5[10] < iVar9)) goto LAB_004bf6a4;
              iVar10 = iVar10 + 1;
              iVar9 = iVar9 + 1;
            } while (iVar10 < piVar5[5]);
            iVar9 = *piVar5;
          }
          puVar3 = puVar3 + iVar2 * 3;
          puVar4 = puVar4 + iVar1;
          if ((iVar9 == 1) && (piVar5[0xb] < param_3)) break;
          iVar6 = iVar6 + 1;
          param_3 = param_3 + 1;
        } while (iVar6 < piVar5[6]);
      }
    }
    if (piVar5[7] + -1 <= param_2) {
      FUN_00521408(piVar5[0xc],0,piVar5[9]);
    }
  }
  return param_1;
}
// FUN_004BF6E0 NONMATCHING
long FUN_004bf6e0(u64 param_1,int param_2,u64 param_3,u64 param_4)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  lVar2 = FUN_004bfc20();
  if (lVar2 == 0) {
    lVar2 = 2;
  }
  else {
    lVar2 = FUN_004bfde0(param_3);
    if (lVar2 == 0) {
      iVar4 = (int)param_1;
      (*DAT_0096013c)(iVar4 + 0x50,param_3);
      *(int *)(iVar4 + 4) = param_2;
      iVar3 = 0;
      *(u32 *)(iVar4 + 0x10) = 0;
      if (0 < param_2) {
        do {
          iVar1 = (**(code **)(iVar4 + 0x14))(param_1,iVar3);
          iVar3 = iVar3 + 1;
          *(u32 *)(iVar1 + 0x38) = 1;
          *(u32 *)(iVar1 + 0x30) = *(u32 *)(iVar4 + 0x10);
        } while (iVar3 < param_2);
      }
      *(u32 *)(iVar4 + 0xc) = 0;
      lVar2 = FUN_004bfa70(param_1,param_4);
      if (lVar2 == 1) {
        *(u32 *)(iVar4 + 8) = 2;
        *(u32 *)(iVar4 + 0x20) = 0;
        *(u32 *)(iVar4 + 0x24) = 0;
        lVar2 = 1;
      }
    }
    else {
      lVar2 = 6;
    }
  }
  return lVar2;
}
// FUN_004BF7E0 NONMATCHING
int FUN_004bf7e0(int param_1)

{
  int iVar1;
  long lVar2;
  int iVar3;
  
  iVar3 = 0;
  lVar2 = (*DAT_00960164)();
  if (0 < lVar2) {
    do {
      if (*(char *)(param_1 + iVar3) == ':') {
        return param_1 + iVar3 + 1;
      }
      iVar3 = iVar3 + 1;
      iVar1 = (*DAT_00960164)(param_1);
    } while (iVar3 < iVar1);
  }
  return param_1;
}
// FUN_004BF880 NONMATCHING
u64
FUN_004bf880(u64 param_1,int param_2,u64 param_3,u64 param_4,char param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  
  iVar2 = FUN_00524388(param_3);
  iVar3 = FUN_00524388(param_4);
  if (param_2 + -1 < iVar2 + iVar3) {
    param_1 = 0;
  }
  else {
    (*DAT_0096013c)(param_1,param_3);
    iVar5 = 0;
    if (-1 < iVar3) {
      pcVar4 = (char *)((int)param_1 + iVar2);
      do {
        cVar1 = *(char *)((int)param_4 + iVar5);
        if ((cVar1 == '/') || (cVar1 == '\\')) {
          *pcVar4 = param_5;
        }
        else {
          *pcVar4 = cVar1;
        }
        iVar5 = iVar5 + 1;
        pcVar4 = pcVar4 + 1;
      } while (iVar5 <= iVar3);
    }
  }
  return param_1;
}
// FUN_004BF980 NONMATCHING
bool FUN_004bf980(u64 param_1,u64 param_2)

{
  long lVar1;
  
  lVar1 = FUN_004bfea0(param_1,param_2,1,0,0);
  if (lVar1 != 0) {
    (**(code **)((int)param_1 + 0x2c))(lVar1);
  }
  return lVar1 != 0;
}
// FUN_004BFA10 NONMATCHING
void FUN_004bfa10(int param_1,long param_2)

{
  if (param_2 == 2) {
    if (*(code **)(param_1 + 0x24) != (code *)0x0) {
      (**(code **)(param_1 + 0x24))(param_1 + 0x50);
    }
  }
  else if ((param_2 == 1) && (*(code **)(param_1 + 0x20) != (code *)0x0)) {
    (**(code **)(param_1 + 0x20))(param_1 + 0x50);
  }
  return;
}
// FUN_004BFA70 NONMATCHING
u32 FUN_004bfa70(int param_1,u64 param_2)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  
  lVar3 = (long)(FUN_004c0070(param_2));
  if (lVar3 == 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      (*DAT_0096017c)();
    }
    iVar1 = (*DAT_00960164)(param_2);
    uVar2 = (*DAT_00960178)(iVar1 + 1,0x401be);
    *(u32 *)(param_1 + 0xc) = uVar2;
    (*DAT_0096013c)(*(u32 *)(param_1 + 0xc),param_2);
    uVar2 = 1;
  }
  else {
    uVar2 = 7;
  }
  return uVar2;
}
// FUN_004BFB20 NONMATCHING
void FUN_004bfb20(long param_1)

{
  int iVar1;
  u32 uVar2;
  int iVar3;
  
  iVar3 = (int)param_1;
  if ((param_1 != 0) && (*(int *)(iVar3 + 0x30) != 0)) {
    iVar1 = *(int *)(iVar3 + 0x40);
    if ((iVar1 == 1) || (*(int *)(iVar3 + 0x48) == 0)) {
      *(u32 *)(iVar3 + 0x40) = 1;
    }
    else {
      if (iVar1 == 4) {
        uVar2 = *(u32 *)(iVar3 + 0x10);
      }
      else {
        uVar2 = *(u32 *)(iVar3 + 0x44);
      }
      *(u32 *)(iVar3 + 0x40) = 1;
      (**(code **)(iVar3 + 0x48))
                (iVar3,uVar2,*(u32 *)(iVar3 + 0x38),iVar1,*(u32 *)(iVar3 + 0x4c));
    }
  }
  return;
}
// FUN_004BFBB0 NONMATCHING
void FUN_004bfbb0(u32 param_1)

{
  DAT_0095ff18 = 0;
  DAT_0095ff10 = 0;
  DAT_0095ff24 = 0;
  DAT_0095ff38 = 1;
  DAT_007ce8bc = 0;
  DAT_0095ff34 = 1;
  DAT_0095ff14 = param_1;
  DAT_007ce8c0 = CreateSema(0x95ff30);
  DAT_0095ff1c = 1;
  return;
}
// FUN_004BFC20 NONMATCHING
u32 FUN_004bfc20(void)

{
  u32 uVar1;
  
  if ((DAT_0095ff14 < 1) || (DAT_0095ff18 + 1 <= DAT_0095ff14)) {
    uVar1 = 1;
  }
  else {
    if (DAT_0095ff24 != (code *)0x0) {
      (*DAT_0095ff24)(5);
    }
    uVar1 = 0;
  }
  return uVar1;
}
// FUN_004BFC80 NONMATCHING
u32 FUN_004bfc80(u64 param_1)

{
  bool bVar1;
  u32 uVar2;
  long lVar3;
  u32 *puVar4;
  
  if ((DAT_0095ff14 < 1) || (DAT_0095ff18 + 1 <= DAT_0095ff14)) {
    bVar1 = true;
  }
  else {
    if (DAT_0095ff24 != (code *)0x0) {
      (*DAT_0095ff24)(5);
    }
    bVar1 = false;
  }
  if (bVar1) {
    puVar4 = (u32 *)param_1;
    lVar3 = (u64)(FUN_004bfd50((u64)(unsigned int)(puVar4 + 0x14)));
    if (lVar3 == 0) {
      FUN_004bfa10(param_1,1);
      *puVar4 = (u32)DAT_0095ff10;
      uVar2 = 1;
      DAT_0095ff18 = DAT_0095ff18 + 1;
      DAT_0095ff10 = (u32 *)(puVar4);
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
// FUN_004BFD50 NONMATCHING
u32 * FUN_004bfd50(u64 param_1)

{
  u32 *puVar1;
  long lVar2;
  
  puVar1 = (u32 *)(DAT_0095ff10);
  while( true ) {
    if (puVar1 == (u32 *)0x0) {
      if (DAT_0095ff24 != (code *)0x0) {
        (*DAT_0095ff24)(6);
      }
      return (u32 *)0x0;
    }
    lVar2 = (*DAT_00960158)(puVar1 + 0x14,param_1);
    if (lVar2 == 0) break;
    puVar1 = (u32 *)*puVar1;
  }
  return puVar1;
}
// FUN_004BFDE0 NONMATCHING
u32 FUN_004bfde0(u64 param_1)

{
  u32 uVar1;
  long lVar2;
  u32 *puVar3;
  
  for (puVar3 = DAT_0095ff10; puVar3 != (u32 *)0x0; puVar3 = (u32 *)*puVar3) {
    lVar2 = (*DAT_00960158)(puVar3 + 0x14,param_1);
    if (lVar2 == 0) goto LAB_004bfe54;
  }
  if (DAT_0095ff24 != (code *)0x0) {
    (*DAT_0095ff24)(6);
  }
  puVar3 = (u32 *)0x0;
LAB_004bfe54:
  if (puVar3 == (u32 *)0x0) {
    uVar1 = 0;
  }
  else {
    if (DAT_0095ff24 != (code *)0x0) {
      (*DAT_0095ff24)(7);
    }
    uVar1 = 1;
  }
  return uVar1;
}
// FUN_004BFEA0 NONMATCHING
long FUN_004bfea0(long param_1,u64 param_2,u32 param_3,u32 param_4,
                 u32 param_5)

{
  int iVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  
  lVar3 = 0;
  if (param_1 == 0) {
    if (DAT_0095ff24 != (code *)0x0) {
      (*DAT_0095ff24)(4);
    }
    lVar3 = 0;
  }
  else {
    WaitSema(DAT_007ce8c0);
    iVar4 = (int)param_1;
    iVar1 = 0;
    if (0 < *(int *)(iVar4 + 4)) {
      do {
        lVar2 = (**(code **)(iVar4 + 0x14))(param_1,iVar1);
        if (*(int *)((int)lVar2 + 0x38) == 1) {
          *(u32 *)((int)lVar2 + 0x38) = 5;
          lVar3 = lVar2;
          break;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(iVar4 + 4));
    }
    SignalSema(DAT_007ce8c0);
    if (lVar3 == 0) {
      iVar1 = (int)(FUN_004c0060());
      *(u32 *)(iVar1 + 0x10) = 8;
      if (DAT_0095ff24 != (code *)0x0) {
        (*DAT_0095ff24)(8);
      }
      lVar3 = 0;
    }
    else {
      iVar1 = (int)lVar3;
      if (((param_3 & 0x10) != 0) || (*(int *)(iVar1 + 0x30) != 0)) {
        *(u32 *)(iVar1 + 0x40) = 2;
        *(u32 *)(iVar1 + 0x48) = param_4;
        *(u32 *)(iVar1 + 0x4c) = param_5;
      }
      if (*(int *)(iVar4 + 0x10) != 0) {
        param_3 = param_3 | 0x10;
        *(u32 *)(iVar1 + 0x40) = 2;
        *(u32 *)(iVar1 + 0x48) = param_4;
        *(u32 *)(iVar1 + 0x4c) = param_5;
      }
      lVar2 = (**(code **)(iVar4 + 0x28))(param_1,lVar3,param_2,param_3);
      if (lVar2 != 1) {
        *(u32 *)(iVar1 + 0x38) = 1;
        lVar3 = 0;
      }
      if (lVar3 != 0) {
        *(u32 *)((int)lVar3 + 0x34) = 2;
      }
    }
  }
  return lVar3;
}
#pragma optimization_level 3
// FUN_004C0060
u32 * FUN_004c0060(void)
{
  return DAT_0095ff10_object;
}
#pragma optimization_level 2
// FUN_004C0070 NONMATCHING
u32 * FUN_004c0070(u64 param_1)

{
  u32 *puVar1;
  long lVar2;
  
  puVar1 = (u32 *)(DAT_0095ff10);
  while( true ) {
    if (puVar1 == (u32 *)0x0) {
      return (u32 *)0x0;
    }
    lVar2 = (*DAT_00960160)(param_1,puVar1[3]);
    if (lVar2 == 0) break;
    puVar1 = (u32 *)*puVar1;
  }
  return puVar1;
}
// FUN_004C00F0 NONMATCHING
u32 * FUN_004c00f0(u64 param_1)

{
  u32 uVar1;
  long lVar2;
  u8 *puVar3;
  u32 *puVar4;
  u32 uVar5;
  u8 uStack_70;
  u8 auStack_6f [111];
  
  if (DAT_0095ff18 != 0) {
    uVar1 = (*DAT_00960164)();
    uVar5 = 0;
    if (uVar1 != 0) {
      puVar3 = &uStack_70;
      do {
        if (*(char *)((int)param_1 + uVar5) == ':') {
          FUN_00524828(&uStack_70,param_1,uVar5 + 1);
          puVar3[1] = 0;
          for (puVar4 = DAT_0095ff10; puVar4 != (u32 *)0x0; puVar4 = (u32 *)*puVar4) {
            lVar2 = (*DAT_00960160)(&uStack_70,puVar4[3]);
            if (lVar2 == 0) goto LAB_004c0200;
          }
          puVar4 = (u32 *)0x0;
LAB_004c0200:
          if (puVar4 != (u32 *)0x0) {
            return puVar4;
          }
        }
        uVar5 = uVar5 + 1;
        puVar3 = puVar3 + 1;
      } while (uVar5 < uVar1);
    }
    if (DAT_007ce8bc != (u32 *)0x0) {
      return DAT_007ce8bc;
    }
  }
  if (DAT_0095ff24 != (code *)0x0) {
    (*DAT_0095ff24)(6);
  }
  return (u32 *)0x0;
}
#pragma optimization_level 3
// FUN_004C0230
void FUN_004c0230(u32 param_1)

{
  DAT_007ce8bc = (u32 *)param_1;
  return;
}
#pragma optimization_level 2
// FUN_004C0240 NONMATCHING
u64 FUN_004c0240(u64 param_1,u64 param_2)

{
  bool bVar1;
  long lVar2;
  long lVar3;
  u64 uVar4;
  u32 uVar5;
  u32 uVar6;
  
  uVar5 = 0;
  lVar2 = FUN_00524a50(param_2,0x7cdd14);
  bVar1 = lVar2 != 0;
  lVar2 = FUN_00524a50(param_2,0x7cdd18);
  lVar3 = FUN_00524a50(param_2,0x7cdd1c);
  if ((lVar3 != 0) && (uVar5 = 1, bVar1)) {
    uVar5 = 0xb;
  }
  lVar3 = FUN_00524a50(param_2,0x7cdd20);
  uVar6 = uVar5;
  if ((lVar3 != 0) && (uVar6 = uVar5 | 6, bVar1)) {
    uVar6 = uVar5 | 7;
  }
  lVar3 = FUN_00524a50(param_2,0x7cdd24);
  if (lVar3 != 0) {
    uVar5 = uVar6 | 10;
    if (bVar1) {
      uVar5 = uVar6 | 0xb;
    }
    uVar6 = uVar5;
    if (lVar2 != 0) {
      uVar6 = uVar6 | 4;
    }
  }
  lVar2 = (long)(FUN_004c00f0(param_1));
  if (lVar2 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_004bfea0(lVar2,param_1,uVar6,0,0);
  }
  return uVar4;
}
// FUN_004C0370 NONMATCHING
u64 FUN_004c0370(u64 param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0x50);
  WaitSema(DAT_007ce8c0);
  *(u32 *)((int)param_1 + 0x38) = 1;
  (**(code **)(iVar1 + 0x2c))(param_1);
  SignalSema(DAT_007ce8c0);
  return 0;
}
// FUN_004C03D0 NONMATCHING
int FUN_004c03d0(u64 param_1,int param_2,int param_3,u64 param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)((int)param_4 + 0x50) + 0x30))(param_4,param_1,param_2 * param_3);
  return iVar1 / param_2;
}
// FUN_004C0420 NONMATCHING
int FUN_004c0420(u64 param_1,int param_2,int param_3,u64 param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)((int)param_4 + 0x50) + 0x34))(param_4,param_1,param_2 * param_3);
  return iVar1 / param_2;
}
// FUN_004C0470 NONMATCHING
u32 FUN_004c0470(u64 param_1,u32 param_2,long param_3)

{
  int iVar1;
  int iVar2;
  Vec128 auStack_30;
  Vec128 auStack_20;
  Vec128 auStack_10;
  
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + 0x50);
  if (*(int *)(iVar2 + 0x30) != 0) {
    *(u32 *)(iVar2 + 0x40) = 4;
    *(u32 *)(iVar2 + 0x38) = 3;
  }
  if (param_3 == 0) {
    (**(code **)(iVar1 + 0x38))(auStack_30,param_1,param_2,1);
  }
  else if (param_3 == 2) {
    (**(code **)(iVar1 + 0x38))(auStack_20,param_1,param_2,3);
  }
  else {
    if (param_3 != 1) {
      return 0xffffffff;
    }
    (**(code **)(iVar1 + 0x38))(auStack_10,param_1,param_2);
  }
  return 0;
}
// FUN_004C0550 NONMATCHING
u64 FUN_004c0550(u64 param_1,int param_2,u64 param_3)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  Vec128 auStack_10;
  
  iVar4 = (int)param_3;
  iVar3 = 0;
  iVar1 = (**(code **)(*(int *)(iVar4 + 0x50) + 0x30))(param_3,param_1,param_2 + -1);
  if (iVar1 == 0) {
    param_1 = 0;
  }
  else {
    iVar5 = (int)param_1;
    if (0 < iVar1) {
      do {
        pcVar2 = (char *)(iVar5 + iVar3);
        if (*pcVar2 == '\n') {
          *(u8 *)(iVar5 + iVar3 + 1) = 0;
          if (*(int *)(iVar4 + 0x30) != 0) {
            *(u32 *)(iVar4 + 0x40) = 4;
            *(u32 *)(iVar4 + 0x38) = 3;
          }
          (**(code **)(*(int *)(iVar4 + 0x50) + 0x38))(auStack_10,param_3,(iVar3 + 1) - iVar1,2);
          return param_1;
        }
        if (*pcVar2 == '\r') {
          if ((iVar3 < iVar1 + -1) && (pcVar2[1] == '\n')) {
            FUN_00521250(pcVar2,pcVar2 + 1,(iVar1 - iVar3) + -1);
            iVar1 = iVar1 + -1;
          }
          else {
            iVar3 = iVar3 + 1;
          }
        }
        else {
          iVar3 = iVar3 + 1;
        }
      } while (iVar3 < iVar1);
    }
    *(u8 *)(iVar5 + iVar1) = 0;
  }
  return param_1;
}
// FUN_004C06B0
#pragma tailcall on
void FUN_004c06b0(int param_1)

{
  (*(code *)(*(int *)(param_1 + 0x50) + 0x44))();
  return;
}
#pragma tailcall off
// FUN_004C06C0 NONMATCHING
u64 FUN_004c06c0(u64 param_1)

{
  u32 uVar1;
  u64 uVar2;
  long lVar3;
  u32 *puVar4;
  u8 *puVar5;
  u32 uVar6;
  u8 uStack_70;
  u8 auStack_6f [111];
  
  if (DAT_0095ff18 != 0) {
    uVar1 = (*DAT_00960164)();
    uVar6 = 0;
    if (uVar1 != 0) {
      puVar5 = &uStack_70;
      do {
        if (*(char *)((int)param_1 + uVar6) == ':') {
          FUN_00524828(&uStack_70,param_1,uVar6 + 1);
          puVar5[1] = 0;
          for (puVar4 = DAT_0095ff10; puVar4 != (u32 *)0x0; puVar4 = (u32 *)*puVar4) {
            lVar3 = (*DAT_00960160)(&uStack_70,puVar4[3]);
            if (lVar3 == 0) goto LAB_004c07f0;
          }
          puVar4 = (u32 *)0x0;
LAB_004c07f0:
          if (puVar4 != (u32 *)0x0) goto LAB_004c070c;
        }
        uVar6 = uVar6 + 1;
        puVar5 = puVar5 + 1;
      } while (uVar6 < uVar1);
    }
    puVar4 = (u32 *)(DAT_007ce8bc);
    if (DAT_007ce8bc != (u32 *)0x0) goto LAB_004c070c;
  }
  if (DAT_0095ff24 != (code *)0x0) {
    (*DAT_0095ff24)(6);
  }
  puVar4 = (u32 *)0x0;
LAB_004c070c:
  if (puVar4 == (u32 *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (*(code *)puVar4[0x13])(puVar4,param_1);
  }
  return uVar2;
}
#pragma optimization_level 3
// FUN_004C0820
u32 FUN_004c0820(int param_1)

{
  return *(u32 *)(param_1 + 0x10);
}
// FUN_004C0830 NONMATCHING
u32 FUN_004c0830(u32 *param_1,u32 param_2)
{
  if (param_2 >= param_1[1]) {
    return 0;
  } else {
    return *(u32 *)((int)param_1[0x16] + param_2 * 0x70);
  }
}
// FUN_004C0870
u32 * FUN_004c0870(void)
{
  return &DAT_007cdd28;
}
// FUN_004C0880
void FUN_004c0880(u32 param_1)
{
  DAT_0096017c_abs[0](*(u32 *)((int)param_1 + 0x58));
}
// FUN_004C08A0
u64 FUN_004c08a0(u64 param_1,u64 param_2,u64 param_3,u64 param_4)
{
  // TODO window stub
  return 0;
}
// FUN_004C0A70
u32 FUN_004c0a70(u32 param_1)
{
  *(u32 *)(param_1 + 0x38) = 1;
  return FUN_00508900(*(u32 *)(param_1 + 0x60));
}
// FUN_004C0A80
u64 FUN_004c0a80(u64 param_1,u64 param_2,u64 param_3,u64 param_4)
{
  // TODO window stub
  return 0;
}
#pragma optimization_level 2
// FUN_004C0C50 NONMATCHING
long FUN_004c0c50(long *param_1,u64 param_2,long param_3)

{
  long lVar1;
  long lVar2;
  
  *(u32 *)(param_1 + 7) = 3;
  lVar1 = FUN_00508f28((int)param_1[0xc]);
  lVar2 = lVar1;
  if (((int)param_1[6] != 0) && (lVar2 = param_3, lVar1 < 0)) {
    lVar2 = 0;
  }
  *(u32 *)(param_1 + 7) = 2;
  if (lVar2 < 1) {
    lVar2 = 0;
  }
  else {
    param_1[2] = param_1[2] + (long)(int)lVar2;
    if (*param_1 < param_1[2]) {
      *param_1 = param_1[2];
    }
  }
  return lVar2;
}
// FUN_004C0CF0 NONMATCHING
void FUN_004c0cf0(u32 *param_1,u64 param_2,int param_3,int param_4)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  long *plVar4;
  long lVar5;
  long lVar6;
  u32 uStack_8;
  u32 uStack_4;
  
  plVar4 = (long *)param_2;
  lVar6 = plVar4[2];
  lVar3 = *plVar4;
  if (param_4 == 3) {
    lVar5 = lVar3 - param_3;
  }
  else if (param_4 == 2) {
    lVar5 = lVar6 + param_3;
  }
  else {
    if (param_4 != 1) {
      *param_1 = 0xffffffff;
      param_1[1] = 0xffffffff;
      param_1[2] = uStack_8;
      param_1[3] = uStack_4;
      return;
    }
    lVar5 = (long)param_3;
  }
  if ((lVar5 <= lVar3) && (lVar3 = lVar5, lVar5 < 0)) {
    lVar3 = 0;
  }
  iVar1 = *(int *)((int)plVar4 + 100);
  if (iVar1 < *(int *)((int)plVar4 + 0x6c)) {
    if ((lVar6 - iVar1 <= lVar3) && (lVar3 <= lVar6 + (*(int *)((int)plVar4 + 0x6c) - iVar1))) {
      *(int *)((int)plVar4 + 100) = (int)lVar3 - (int)(lVar6 - iVar1);
      plVar4[2] = lVar3;
      FUN_004bfb20(param_2);
      lVar3 = plVar4[2];
      lVar6 = plVar4[3];
      uVar2 = *(u32 *)((int)plVar4 + 0x1c);
      *param_1 = (int)lVar3;
      param_1[1] = (int)((u32)lVar3 >> 0x20);
      param_1[2] = (int)lVar6;
      param_1[3] = uVar2;
      return;
    }
  }
  *(u32 *)(plVar4 + 7) = 3;
  *(u32 *)((int)plVar4 + 100) = *(u32 *)((int)plVar4 + 0x6c);
  plVar4[2] = lVar3;
  FUN_00508a78((int)plVar4[0xc],(int)lVar3,0);
  if ((int)plVar4[6] == 0) {
    *(u32 *)(plVar4 + 7) = 2;
  }
  lVar3 = plVar4[2];
  lVar6 = plVar4[3];
  uVar2 = *(u32 *)((int)plVar4 + 0x1c);
  *param_1 = (int)lVar3;
  param_1[1] = (int)((u32)lVar3 >> 0x20);
  param_1[2] = (int)lVar6;
  param_1[3] = uVar2;
  return;
}
// FUN_004C0E70 NONMATCHING
int FUN_004c0e70(u64 param_1,long param_2)

{
  int iVar1;
  int iVar2;
  int iStack_4;
  
  iVar1 = (int)param_1;
  iVar2 = 2;
  if (*(int *)(iVar1 + 0x38) == 3) {
    if (*(int *)(iVar1 + 0x40) == 4) {
      *(u32 *)(iVar1 + 0x38) = 2;
LAB_004c0eb0:
      iVar1 = *(int *)(iVar1 + 0x38);
    }
    else {
      do {
        FUN_005091e8(*(u32 *)(iVar1 + 0x60),1,&iStack_4);
        if (iStack_4 == 0) {
          iVar2 = 2;
          *(u32 *)(iVar1 + 0x38) = 2;
          if (*(int *)(iVar1 + 0x40) == 5) {
            *(int *)(iVar1 + 0x44) =
                 (int)*(u64 *)(iVar1 + 0x10) - (int)*(u64 *)(iVar1 + 0x20);
          }
        }
        else {
          *(u32 *)(iVar1 + 0x44) = 0;
          iVar2 = 3;
        }
        if (param_2 == 0) goto LAB_004c0eb0;
      } while (iVar2 == 3);
      iVar1 = *(int *)(iVar1 + 0x38);
    }
    if (iVar1 == 2) {
      FUN_004bfb20(param_1);
    }
  }
  return iVar2;
}
// FUN_004C0F70 NONMATCHING
u32 FUN_004c0f70(int param_1)
{
  if (*(int *)(param_1 + 0x38) != 1) {
    FUN_004c0e70(param_1,0);
  }
  return *(u32 *)(param_1 + 0x38);
}
// FUN_004C0FD0 NONMATCHING
u64 FUN_004c0fd0(int param_1,int param_2,int param_3,u64 param_4,u64 param_5)

{
  bool bVar1;
  int iVar2;
  u32 uVar3;
  long lVar4;
  u64 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  lVar4 = (long)(FUN_004bfd50(param_5));
  if (lVar4 == 0) {
    uVar5 = (*DAT_00960178)(0x5c,0x401be);
    iVar2 = (int)uVar5;
    *(u8 **)(iVar2 + 0x14) = &LAB_004c0830;
    *(u8 **)(iVar2 + 0x18) = &LAB_004c0880;
    *(u8 **)(iVar2 + 0x1c) = &LAB_004c0870;
    *(u8 **)(iVar2 + 0x28) = &LAB_004c08a0;
    *(u8 **)(iVar2 + 0x2c) = &LAB_004c0a70;
    *(u8 **)(iVar2 + 0x30) = &LAB_004c0a80;
    *(code **)(iVar2 + 0x34) = (code *)FUN_004c0c50;
    *(code **)(iVar2 + 0x38) = (code *)FUN_004c0cf0;
    *(code **)(iVar2 + 0x3c) = (code *)FUN_004c0e70;
    *(u8 **)(iVar2 + 0x40) = &LAB_004c0f60;
    *(u8 **)(iVar2 + 0x44) = &LAB_004bf9e0;
    *(code **)(iVar2 + 0x48) = (code *)FUN_004c0f70;
    *(u8 **)(iVar2 + 0x4c) = &LAB_004c0fc0;
    uVar3 = (*DAT_00960184)(param_1,0x70,0x401be);
    *(u32 *)(iVar2 + 0x58) = uVar3;
    iVar6 = *(int *)(iVar2 + 0x58);
    iVar9 = 0;
    if (0 < param_1) {
      if (8 < param_1) {
        bVar1 = false;
        if ((-1 < param_1) && (param_1 < 0x7fffffff)) {
          bVar1 = true;
        }
        if (bVar1) {
          iVar7 = 0;
          iVar8 = iVar6;
          do {
            *(int *)(iVar8 + 0x50) = iVar2;
            *(int *)(iVar8 + 0x68) = param_2 + iVar7;
            iVar9 = iVar9 + 8;
            *(int *)(iVar8 + 0x6c) = param_3;
            *(int *)(iVar8 + 0xc0) = iVar2;
            *(int *)(iVar8 + 0xd8) = param_2 + iVar7 + param_3;
            *(int *)(iVar8 + 0xdc) = param_3;
            *(int *)(iVar8 + 0x130) = iVar2;
            *(int *)(iVar8 + 0x148) = param_2 + iVar7 + param_3 * 2;
            *(int *)(iVar8 + 0x14c) = param_3;
            *(int *)(iVar8 + 0x1a0) = iVar2;
            *(int *)(iVar8 + 0x1b8) = param_2 + iVar7 + param_3 * 3;
            *(int *)(iVar8 + 0x1bc) = param_3;
            *(int *)(iVar8 + 0x210) = iVar2;
            iVar10 = iVar7 + param_3 * 6;
            *(int *)(iVar8 + 0x228) = param_2 + iVar7 + param_3 * 4;
            *(int *)(iVar8 + 0x22c) = param_3;
            iVar11 = iVar7 + param_3 * 7;
            *(int *)(iVar8 + 0x280) = iVar2;
            *(int *)(iVar8 + 0x298) = param_2 + iVar7 + param_3 * 5;
            *(int *)(iVar8 + 0x29c) = param_3;
            iVar7 = iVar7 + param_3 * 8;
            *(int *)(iVar8 + 0x2f0) = iVar2;
            *(int *)(iVar8 + 0x308) = param_2 + iVar10;
            *(int *)(iVar8 + 0x30c) = param_3;
            *(int *)(iVar8 + 0x360) = iVar2;
            *(int *)(iVar8 + 0x378) = param_2 + iVar11;
            *(int *)(iVar8 + 0x37c) = param_3;
            iVar8 = iVar8 + 0x380;
          } while (iVar9 < param_1 + -8);
        }
      }
      if (iVar9 < param_1) {
        iVar6 = iVar6 + iVar9 * 0x70;
        iVar8 = iVar9 * param_3;
        do {
          *(int *)(iVar6 + 0x50) = iVar2;
          *(int *)(iVar6 + 0x68) = param_2 + iVar8;
          iVar9 = iVar9 + 1;
          *(int *)(iVar6 + 0x6c) = param_3;
          iVar8 = iVar8 + param_3;
          iVar6 = iVar6 + 0x70;
        } while (iVar9 < param_1);
      }
    }
    lVar4 = FUN_004bf6e0(uVar5,param_1,param_5,param_4);
    if (lVar4 != 1) {
      (*DAT_0096017c)(*(u32 *)(iVar2 + 0x58));
      (*DAT_0096017c)(uVar5);
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}
// FUN_004C12D0 NONMATCHING
u32 FUN_004c12d0(int *param_1)

{
  int iVar1;
  u32 uVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 0x1a) {
    uVar2 = 1;
  }
  else if (iVar1 == 0x14) {
    uVar2 = 1;
  }
  else if (iVar1 == 0x13) {
    uVar2 = 0;
  }
  else if (iVar1 == 0x12) {
    uVar2 = 1;
  }
  else if (iVar1 == 0x10) {
    uVar2 = 1;
  }
  else if (iVar1 == 0xf) {
    uVar2 = 1;
  }
  else if (iVar1 == 0xe) {
    uVar2 = 1;
  }
  else if (iVar1 == 0xd) {
    uVar2 = 0;
  }
  else if (iVar1 == 0xb) {
    uVar2 = 1;
  }
  else if (iVar1 == 10) {
    uVar2 = 1;
  }
  else if (iVar1 == 9) {
    uVar2 = 1;
  }
  else if (iVar1 == 8) {
    uVar2 = 1;
  }
  else if (iVar1 == 7) {
    uVar2 = 1;
  }
  else if (iVar1 == 6) {
    uVar2 = 1;
  }
  else if (iVar1 == 5) {
    uVar2 = 1;
  }
  else if (iVar1 == 3) {
    uVar2 = 0;
  }
  else if (iVar1 == 2) {
    uVar2 = 0;
  }
  else if (iVar1 == 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}
// FUN_004C1450 NONMATCHING
u32 FUN_004c1450(u64 param_1,long param_2,long param_3,long param_4,long param_5)

{
  u32 uVar1;
  long lVar2;
  u32 *extraout_a1_lo;
  u32 *extraout_a2_lo;
  u32 *extraout_t1_lo;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  lVar2 = (long)(unsigned int)FUN_004c5250((int *)(unsigned int)param_1,(u64)(unsigned int)(&uStack_10),0xc);
  if (lVar2 == 0xc) {
    uStack_30 = uStack_10;
    uStack_2c = uStack_c;
    if ((uStack_8 & 0xffff0000) == 0) {
      uStack_28 = uStack_8 << 8;
      uStack_24 = 0;
    }
    else {
      uStack_24 = uStack_8 & 0xffff;
      uStack_28 = (uStack_8 >> 0xe & 0x3ff00) + 0x30000 | uStack_8 >> 0x10 & 0x3f;
    }
    FUN_004c12d0((int *)(unsigned int)(&uStack_30));
    if (param_2 != 0) {
      *(u32 *)param_2 = uStack_30;
    }
    if (param_3 != 0) {
      *(u32 *)param_3 = *extraout_a1_lo;
    }
    if (param_5 != 0) {
      *(u32 *)param_5 = *extraout_t1_lo;
    }
    if (param_4 != 0) {
      *(u32 *)param_4 = *extraout_a2_lo;
    }
    uVar1 = 1;
  }
  else {
    uStack_18 = 1;
    uStack_14 = FUN_004c1d10(0xffffffff8000001a);
    uVar1 = 0;
  }
  return uVar1;
}
// FUN_004C15A0 NONMATCHING
u64 FUN_004c15a0(u64 param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5
                 )

{
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  uStack_8 = param_5 & 0xffff | (param_4 - 0x30000 & 0x3ff00) << 0xe | (param_4 & 0x3f) << 0x10;
  uStack_10 = param_2;
  uStack_c = param_3;
  FUN_004c53f0(param_1,(u64)(unsigned int)(&uStack_10),0xc);
  return 0;
}
// FUN_004C1600 NONMATCHING
u32 FUN_004c1600(u64 param_1,int param_2,long param_3,long param_4)

{
  long lVar1;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_c;
  u32 uStack_8;
  int iStack_4;
  
  lVar1 = (long)(FUN_004c1450(param_1,(u64)(unsigned int)(&iStack_4),(u64)(unsigned int)(&uStack_8),(u64)(unsigned int)(&uStack_c),0));
  while( true ) {
    if (lVar1 == 0) {
      return 0;
    }
    if (iStack_4 == param_2) break;
    lVar1 = FUN_004c5620(param_1,uStack_8);
    if (lVar1 == 0) {
      return 0;
    }
    lVar1 = (long)(FUN_004c1450(param_1,(u64)(unsigned int)(&iStack_4),(u64)(unsigned int)(&uStack_8),(u64)(unsigned int)(&uStack_c),0));
  }
  if (uStack_c < 0x35000) {
    uStack_18 = 1;
    uStack_14 = FUN_004c1d10(0xffffffff80000004);
    FUN_004c1c50((u64)(unsigned int)(&uStack_18));
    return 0;
  }
  if (uStack_c < 0x37003) {
    if (param_3 != 0) {
      *(u32 *)param_3 = uStack_8;
    }
    if (param_4 != 0) {
      *(u32 *)param_4 = uStack_c;
    }
    return 1;
  }
  uStack_20 = 1;
  uStack_1c = FUN_004c1d10(0xffffffff80000004);
  FUN_004c1c50((u64)(unsigned int)(&uStack_20));
  return 0;
}
// FUN_004C1750 NONMATCHING
u64 FUN_004c1750(u64 param_1,int param_2,u32 param_3)

{
  long lVar1;
  u32 uVar2;
  u8 auStack_100 [256];
  
  while( true ) {
    if (param_3 == 0) {
      return param_1;
    }
    uVar2 = param_3;
    if (0xff < param_3) {
      uVar2 = 0x100;
    }
    FUN_00521250(auStack_100,param_2,uVar2);
    lVar1 = (u64)(FUN_004c53f0(param_1,(u64)(unsigned int)(auStack_100),uVar2));
    if (lVar1 == 0) break;
    param_3 = param_3 - uVar2;
    param_2 = param_2 + uVar2;
  }
  return 0;
}
#pragma optimization_level 3
// FUN_004C17F0
u64 FUN_004c17f0(u64 param_1,u64 param_2,u32 param_3)

{
  FUN_004c53f0(param_1,param_2,param_3);
  return param_1;
}
#pragma optimization_level 2
#pragma optimization_level 3
// FUN_004C1820
u64 FUN_004c1820(u64 param_1,u64 param_2,u32 param_3)

{
  FUN_004c53f0(param_1,param_2,param_3);
  return param_1;
}
#pragma optimization_level 2
// FUN_004C1850 NONMATCHING
u64 FUN_004c1850(u64 param_1)

{
  long lVar1;
  u32 uStack_8;
  u32 uStack_4;
  
  lVar1 = (long)((code)FUN_004c5250)();
  if (lVar1 == 0) {
    uStack_8 = 1;
    uStack_4 = FUN_004c1d10(0xffffffff8000001a);
    FUN_004c1c50((u64)(unsigned int)(&uStack_8));
    param_1 = 0;
  }
  return param_1;
}
// FUN_004C18B0 NONMATCHING
u64 FUN_004c18b0(u64 param_1)

{
  long lVar1;
  u32 uStack_8;
  u32 uStack_4;
  
  lVar1 = (long)((code)FUN_004c5250)();
  if (lVar1 == 0) {
    uStack_8 = 1;
    uStack_4 = FUN_004c1d10(0xffffffff8000001a);
    FUN_004c1c50((u64)(unsigned int)(&uStack_8));
    param_1 = 0;
  }
  return param_1;
}
// FUN_004C1910 NONMATCHING
u64 FUN_004c1910(u64 param_1)

{
  long lVar1;
  u32 uStack_8;
  u32 uStack_4;
  
  lVar1 = (long)((code)FUN_004c5250)();
  if (lVar1 == 0) {
    uStack_8 = 1;
    uStack_4 = FUN_004c1d10(0xffffffff8000001a);
    FUN_004c1c50((u64)(unsigned int)(&uStack_8));
    param_1 = 0;
  }
  return param_1;
}
// FUN_004C1970 NONMATCHING
u64 FUN_004c1970(u64 param_1,u64 param_2)

{
  u32 uVar1;
  long lVar2;
  u32 *puVar3;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  lVar2 = (long)(FUN_004c1450(param_1,(u64)(unsigned int)(&uStack_4),(u64)(unsigned int)(&uStack_8),(u64)(unsigned int)(&uStack_c),(u64)(unsigned int)(&uStack_10)));
  if (lVar2 == 0) {
    param_1 = 0;
  }
  else {
    puVar3 = (u32 *)param_2;
    *puVar3 = uStack_4;
    puVar3[1] = uStack_8;
    puVar3[2] = uStack_c;
    puVar3[3] = uStack_10;
    uVar1 = (u32)(unsigned int)FUN_004c12d0((int *)(unsigned int)param_2);
    puVar3[4] = uVar1;
  }
  return param_1;
}
// FUN_004C19F0 NONMATCHING
long FUN_004c19f0(u64 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  u32 *puVar3;
  u32 uStack_60;
  u32 uStack_5c;
  u32 uStack_58;
  u32 uStack_54;
  u32 uStack_50;
  u32 uStack_4c;
  u32 uStack_48;
  u32 uStack_44;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  int iStack_4;
  
  lVar2 = (long)(FUN_004c1600(param_1,1,(u64)(unsigned int)(&iStack_4),(u64)(unsigned int)(&uStack_8)));
  if (lVar2 == 0) {
    uStack_20 = 1;
    uStack_1c = FUN_004c1d10(0xffffffff8000001a);
    FUN_004c1c50((u64)(unsigned int)(&uStack_20));
    param_2 = 0;
  }
  else if ((uStack_8 < 0x35000) || (0x37002 < uStack_8)) {
    uStack_18 = 1;
    uStack_14 = FUN_004c1d10(0xffffffff80000004);
    FUN_004c1c50((u64)(unsigned int)(&uStack_18));
    param_2 = 0;
  }
  else {
    FUN_00521408(&uStack_60,0,0x34);
    iVar1 = (int)(unsigned int)FUN_004c5250((int *)(unsigned int)param_1,(u64)(unsigned int)(&uStack_60),iStack_4);
    if (iStack_4 == iVar1) {
      if (param_2 == 0) {
        param_2 = (u32)((code)FUN_004c38c0)();
      }
      if (param_2 != 0) {
        puVar3 = (u32 *)param_2;
        puVar3[3] = 0;
        *puVar3 = uStack_60;
        puVar3[1] = uStack_5c;
        puVar3[2] = uStack_58;
        puVar3[4] = uStack_54;
        puVar3[5] = uStack_50;
        puVar3[6] = uStack_4c;
        puVar3[8] = uStack_48;
        puVar3[9] = uStack_44;
        puVar3[10] = uStack_40;
        puVar3[0xc] = uStack_3c;
        puVar3[0xd] = uStack_38;
        puVar3[0xe] = uStack_34;
        puVar3[3] = uStack_30 & 3;
        if ((uStack_30 & 3) == 3) {
        }
      }
    }
    else {
      uStack_10 = 1;
      uStack_c = FUN_004c1d10(0xffffffff8000001a);
      FUN_004c1c50((u64)(unsigned int)(&uStack_10));
      param_2 = 0;
    }
  }
  return param_2;
}
// FUN_004C1C50 NONMATCHING
u64 FUN_004c1c50(u64 param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = (int *)param_1;
  piVar2 = (int *)((int)&DAT_00960070 + iGpffffbbe0);
  if ((*piVar2 == 0) && (*(int *)((int)&DAT_00960074 + iGpffffbbe0) == -0x80000000)) {
    if ((piVar1[1] & 0x80000000U) == 0) {
      *piVar2 = *piVar1;
    }
    else {
      *piVar2 = 0;
    }
    *(int *)((int)&DAT_00960074 + iGpffffbbe0) = piVar1[1];
  }
  return param_1;
}
// FUN_004C1CD0 NONMATCHING
u64 FUN_004c1cd0(u64 param_1)

{
  u32 uVar1;
  
  uVar1 = *(u32 *)((int)&DAT_00960074 + iGpffffbbe0);
  *(u32 *)param_1 = *(u32 *)((int)&DAT_00960070 + iGpffffbbe0);
  ((u32 *)param_1)[1] = uVar1;
  *(u32 *)((int)&DAT_00960070 + iGpffffbbe0) = 0;
  *(u32 *)((int)&DAT_00960074 + iGpffffbbe0) = 0x80000000;
  return param_1;
}
// FUN_004C1D10 NONMATCHING
long FUN_004c1d10(RwInt32 param_1,...)
{
  long result;
  va_list args;
  result = param_1;
  va_start(args,param_1);
  va_end(args);
  return result;
}
// FUN_004C1D50 NONMATCHING
long FUN_004c1d50(int param_1,u32 param_2)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  lVar2 = (*DAT_00960178)(0x10,0x30000);
  if (lVar2 == 0) {
    uStack_8 = 1;
    uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,0x10);
    FUN_004c1c50((u64)(unsigned int)(&uStack_8));
    lVar2 = 0;
  }
  else {
    piVar3 = (int *)lVar2;
    piVar3[1] = 0;
    piVar3[2] = 0x14;
    piVar3[3] = param_1;
    iVar1 = (*DAT_00960178)(piVar3[2] * piVar3[3],param_2 | 0x1000000);
    *piVar3 = iVar1;
    if (*piVar3 == 0) {
      uStack_10 = 1;
      uStack_c = ((code)FUN_004c1d10)(0xffffffff80000013,piVar3[2] * piVar3[3]);
      FUN_004c1c50((u64)(unsigned int)(&uStack_10));
      (*DAT_0096017c)(lVar2);
      lVar2 = 0;
    }
  }
  return lVar2;
}
#pragma optimization_level 3
// FUN_004C1E60
void FUN_004c1e60(int param_1)

{
  *(u32 *)(param_1 + 4) = 0;
  return;
}
#pragma optimization_level 2
// FUN_004C1E70 NONMATCHING
int FUN_004c1e70(int *param_1,u64 param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar2 = param_1[2];
  if (iVar2 <= param_1[1]) {
    iVar1 = iVar2;
    if (iVar2 < 0) {
      iVar1 = iVar2 + 3;
    }
    lVar3 = (*DAT_00960180)(*param_1,param_1[3] * (iVar2 + (iVar1 >> 2)),param_2);
    if (lVar3 == 0) {
      uStack_8 = 1;
      iVar2 = param_1[2];
      iVar1 = iVar2;
      if (iVar2 < 0) {
        iVar1 = iVar2 + 3;
      }
      uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,param_1[3] * (iVar2 + (iVar1 >> 2)));
      FUN_004c1c50((u64)(unsigned int)(&uStack_8));
      return 0;
    }
    *param_1 = (int)lVar3;
    iVar2 = param_1[2];
    if (iVar2 < 0) {
      iVar2 = iVar2 + 3;
    }
    param_1[2] = param_1[2] + (iVar2 >> 2);
  }
  iVar2 = param_1[1];
  param_1[1] = iVar2 + 1;
  return *param_1 + iVar2 * param_1[3];
}
// FUN_004C1F70 NONMATCHING
int FUN_004c1f70(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar1 = param_1[2];
  if (iVar1 <= param_1[1] + param_2) {
    iVar2 = iVar1;
    if (iVar1 < 0) {
      iVar2 = iVar1 + 3;
    }
    lVar3 = (*DAT_00960180)(*param_1,param_1[3] * ((iVar2 >> 2) + iVar1 + param_2));
    if (lVar3 == 0) {
      uStack_8 = 1;
      iVar1 = param_1[2];
      iVar2 = iVar1;
      if (iVar1 < 0) {
        iVar2 = iVar1 + 3;
      }
      uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,param_1[3] * ((iVar2 >> 2) + iVar1 + param_2));
      FUN_004c1c50((u64)(unsigned int)(&uStack_8));
      return 0;
    }
    *param_1 = (int)lVar3;
    iVar1 = param_1[2];
    iVar2 = iVar1;
    if (iVar1 < 0) {
      iVar2 = iVar1 + 3;
    }
    param_1[2] = (iVar2 >> 2) + iVar1 + param_2;
  }
  iVar1 = param_1[1];
  param_1[1] = iVar1 + param_2;
  return *param_1 + iVar1 * param_1[3];
}
// FUN_004C2080
#pragma optimization_level 3
void FUN_004c2080(int param_1,int param_2)
{
  *(int *)(param_1 + 4) -= param_2;
}
#pragma optimization_level 2
// FUN_004C2090 NONMATCHING
u32 FUN_004c2090(u32 *param_1)
{
  u32 result;
  if (param_1[1] == 0) {
    result = 0;
  } else {
    result = *param_1;
  }
  return result;
}
// FUN_004C20B0 NONMATCHING
u32 FUN_004c20b0(u64 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1;
  if ((*piVar1 != 0) && (piVar1[2] != 0)) {
    (*DAT_0096017c)();
    *piVar1 = 0;
    piVar1[2] = 0;
  }
  (*DAT_0096017c)(param_1);
  return 1;
}
#pragma optimization_level 3
// FUN_004C2120
u32 FUN_004c2120(int param_1)

{
  return *(u32 *)(param_1 + 4);
}
#pragma optimization_level 2
// FUN_004C2130 NONMATCHING
int FUN_004c2130(u64 param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)param_1;
  iVar2 = 0;
  if (piVar1[1] == 0) {
    if (*piVar1 != 0) {
      (*DAT_0096017c)();
      *piVar1 = 0;
    }
  }
  else {
    iVar2 = *piVar1;
  }
  (*DAT_0096017c)(param_1);
  return iVar2;
}
#pragma optimization_level 3
// FUN_004C21B0
int FUN_004c21b0()
{
  asm __volatile__(".set noreorder ;"
                   ".word 0x8c82000c ;"
                   ".word 0x00451818 ;"
                   ".word 0x8c820000 ;"
                   "jr $31 ;"
                   ".word 0x00431021 ;"
                   ".set reorder");
  __builtin_unreachable();
}
#pragma optimization_level 3
// FUN_004C21D0
u32 FUN_004c21d0(u32 *param_1)

{
  return *param_1;
}
#pragma optimization_level 3
// FUN_004C21E0
int FUN_004c21e0()
{
  asm __volatile__(".set noreorder ;"
                   ".word 0x8c83000c ;"
                   ".word 0x8c820004 ;"
                   ".word 0x00621818 ;"
                   ".word 0x8c820000 ;"
                   "jr $31 ;"
                   ".word 0x00431021 ;"
                   ".set reorder");
  __builtin_unreachable();
}
#pragma optimization_level 2
// FUN_004C2200 NONMATCHING
RwMatrix* RwMatrixMultiply(RwMatrix* matrixOut, const RwMatrix* matrixIn1, const RwMatrix* matrixIn2)
{
  matrixOut->right.x = matrixIn1->right.x * matrixIn2->right.x + matrixIn1->right.y * matrixIn2->up.x + matrixIn1->right.z * matrixIn2->at.x;
  matrixOut->right.y = matrixIn1->right.x * matrixIn2->right.y + matrixIn1->right.y * matrixIn2->up.y + matrixIn1->right.z * matrixIn2->at.y;
  matrixOut->right.z = matrixIn1->right.x * matrixIn2->right.z + matrixIn1->right.y * matrixIn2->up.z + matrixIn1->right.z * matrixIn2->at.z;
  matrixOut->up.x = matrixIn1->up.x * matrixIn2->right.x + matrixIn1->up.y * matrixIn2->up.x + matrixIn1->up.z * matrixIn2->at.x;
  matrixOut->up.y = matrixIn1->up.x * matrixIn2->right.y + matrixIn1->up.y * matrixIn2->up.y + matrixIn1->up.z * matrixIn2->at.y;
  matrixOut->up.z = matrixIn1->up.x * matrixIn2->right.z + matrixIn1->up.y * matrixIn2->up.z + matrixIn1->up.z * matrixIn2->at.z;
  matrixOut->at.x = matrixIn1->at.x * matrixIn2->right.x + matrixIn1->at.y * matrixIn2->up.x + matrixIn1->at.z * matrixIn2->at.x;
  matrixOut->at.y = matrixIn1->at.x * matrixIn2->right.y + matrixIn1->at.y * matrixIn2->up.y + matrixIn1->at.z * matrixIn2->at.y;
  matrixOut->at.z = matrixIn1->at.x * matrixIn2->right.z + matrixIn1->at.y * matrixIn2->up.z + matrixIn1->at.z * matrixIn2->at.z;
  matrixOut->pos.x = matrixIn1->pos.x * matrixIn2->right.x + matrixIn1->pos.y * matrixIn2->up.x + matrixIn1->pos.z * matrixIn2->at.x + matrixIn2->pos.x;
  matrixOut->pos.y = matrixIn1->pos.x * matrixIn2->right.y + matrixIn1->pos.y * matrixIn2->up.y + matrixIn1->pos.z * matrixIn2->at.y + matrixIn2->pos.y;
  matrixOut->pos.z = matrixIn1->pos.x * matrixIn2->right.z + matrixIn1->pos.y * matrixIn2->up.z + matrixIn1->pos.z * matrixIn2->at.z + matrixIn2->pos.z;
  return matrixOut;
}
// FUN_004C2330 NONMATCHING
u64 FUN_004c2330(u64 param_1,float *param_2)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float afStack_30 [12];
  
  pfVar2 = (float *)param_1;
  afStack_30[9] = param_2[1];
  afStack_30[0] = param_2[8];
  afStack_30[10] = param_2[2];
  afStack_30[8] = *param_2;
  afStack_30[4] = param_2[4];
  afStack_30[5] = param_2[5];
  afStack_30[1] = param_2[9];
  afStack_30[6] = param_2[6];
  afStack_30[2] = param_2[10];
  fVar5 = SQRT(afStack_30[10] * afStack_30[10] +
               afStack_30[8] * afStack_30[8] + afStack_30[9] * afStack_30[9]);
  fVar7 = param_2[0xc];
  fVar9 = param_2[0xd];
  fVar6 = param_2[0xe];
  if (0.0 < fVar5) {
    fVar5 = 1.0 / fVar5;
  }
  fVar10 = SQRT(afStack_30[6] * afStack_30[6] +
                afStack_30[4] * afStack_30[4] + afStack_30[5] * afStack_30[5]);
  afStack_30[9] = afStack_30[9] * fVar5;
  afStack_30[8] = afStack_30[8] * fVar5;
  afStack_30[10] = afStack_30[10] * fVar5;
  if (0.0 < fVar10) {
    fVar10 = 1.0 / fVar10;
  }
  afStack_30[5] = afStack_30[5] * fVar10;
  afStack_30[6] = afStack_30[6] * fVar10;
  fVar8 = SQRT(afStack_30[2] * afStack_30[2] +
               afStack_30[0] * afStack_30[0] + afStack_30[1] * afStack_30[1]);
  afStack_30[4] = afStack_30[4] * fVar10;
  if (0.0 < fVar8) {
    fVar8 = 1.0 / fVar8;
  }
  afStack_30[0] = afStack_30[0] * fVar8;
  afStack_30[1] = afStack_30[1] * fVar8;
  afStack_30[2] = afStack_30[2] * fVar8;
  if (0.0 < fVar5) {
    if (0.0 < fVar10) {
      if (0.0 < fVar8) {
        fVar5 = afStack_30[6] * afStack_30[2] +
                afStack_30[4] * afStack_30[0] + afStack_30[5] * afStack_30[1] + 0.0 + 0.0;
        if (fVar5 < 0.0) {
          fVar5 = -fVar5;
        }
        fVar10 = afStack_30[2] * afStack_30[10] +
                 afStack_30[0] * afStack_30[8] + afStack_30[1] * afStack_30[9];
        if (fVar10 < 0.0) {
          fVar10 = -fVar10;
        }
        fVar8 = afStack_30[10] * afStack_30[6] +
                afStack_30[8] * afStack_30[4] + afStack_30[9] * afStack_30[5];
        if (fVar8 < 0.0) {
          fVar8 = -fVar8;
        }
        if (fVar5 < fVar10) {
          if (fVar5 < fVar8) {
            pfVar4 = afStack_30 + 4;
            pfVar3 = afStack_30;
            pfVar1 = afStack_30 + 8;
          }
          else {
            pfVar4 = afStack_30 + 8;
            pfVar3 = afStack_30 + 4;
            pfVar1 = afStack_30;
          }
        }
        else if (fVar10 < fVar8) {
          pfVar4 = afStack_30;
          pfVar3 = afStack_30 + 8;
          pfVar1 = afStack_30 + 4;
        }
        else {
          pfVar4 = afStack_30 + 8;
          pfVar3 = afStack_30 + 4;
          pfVar1 = afStack_30;
        }
      }
      else {
        pfVar4 = afStack_30 + 8;
        pfVar3 = afStack_30 + 4;
        pfVar1 = afStack_30;
      }
    }
    else {
      pfVar4 = afStack_30;
      pfVar3 = afStack_30 + 8;
      pfVar1 = afStack_30 + 4;
    }
  }
  else {
    pfVar4 = afStack_30 + 4;
    pfVar3 = afStack_30;
    pfVar1 = afStack_30 + 8;
  }
  *pfVar1 = pfVar4[1] * pfVar3[2] - pfVar4[2] * pfVar3[1];
  pfVar1[1] = pfVar4[2] * *pfVar3 - *pfVar4 * pfVar3[2];
  pfVar1[2] = *pfVar4 * pfVar3[1] - pfVar4[1] * *pfVar3;
  fVar5 = SQRT(pfVar1[2] * pfVar1[2] + *pfVar1 * *pfVar1 + pfVar1[1] * pfVar1[1]);
  if (0.0 < fVar5) {
    fVar5 = 1.0 / fVar5;
  }
  *pfVar1 = *pfVar1 * fVar5;
  pfVar1[1] = pfVar1[1] * fVar5;
  fVar10 = pfVar1[2];
  pfVar1[2] = fVar10 * fVar5;
  *pfVar3 = pfVar1[1] * pfVar4[2] - fVar10 * fVar5 * pfVar4[1];
  pfVar3[1] = pfVar1[2] * *pfVar4 - *pfVar1 * pfVar4[2];
  pfVar3[2] = *pfVar1 * pfVar4[1] - pfVar1[1] * *pfVar4;
  fVar5 = SQRT(pfVar3[2] * pfVar3[2] + *pfVar3 * *pfVar3 + pfVar3[1] * pfVar3[1]);
  if (0.0 < fVar5) {
    fVar5 = 1.0 / fVar5;
  }
  *pfVar3 = *pfVar3 * fVar5;
  pfVar3[1] = pfVar3[1] * fVar5;
  pfVar3[2] = pfVar3[2] * fVar5;
  *pfVar2 = afStack_30[8];
  pfVar2[1] = afStack_30[9];
  pfVar2[2] = afStack_30[10];
  pfVar2[4] = afStack_30[4];
  pfVar2[5] = afStack_30[5];
  pfVar2[6] = afStack_30[6];
  pfVar2[8] = afStack_30[0];
  pfVar2[9] = afStack_30[1];
  pfVar2[10] = afStack_30[2];
  pfVar2[0xc] = fVar7;
  pfVar2[0xd] = fVar9;
  pfVar2[0xe] = fVar6;
  pfVar2[3] = (float)((u32)pfVar2[3] & 0xfffdffff | 3);
  return param_1;
}
// FUN_004C2860 NONMATCHING
u64 FUN_004c2860(u64 param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  pfVar1 = (float *)param_1;
  fVar6 = param_2[5];
  fVar7 = param_2[10];
  fVar8 = param_2[6];
  fVar9 = param_2[9];
  fVar3 = param_2[1];
  fVar5 = param_2[2];
  fVar2 = param_2[4];
  fVar4 = *param_2;
  *pfVar1 = fVar6 * fVar7 - fVar8 * fVar9;
  fVar6 = fVar3 * fVar8 - fVar5 * fVar6;
  pfVar1[1] = -(fVar3 * fVar7 - fVar5 * fVar9);
  pfVar1[2] = fVar6;
  fVar2 = fVar6 * param_2[8] + *pfVar1 * fVar4 + pfVar1[1] * fVar2;
  if (fVar2 == 0.0) {
    fVar2 = 1.0;
  }
  else {
    fVar2 = 1.0 / fVar2;
  }
  fVar10 = param_2[4];
  fVar7 = param_2[10];
  fVar11 = param_2[6];
  fVar9 = param_2[8];
  fVar6 = *param_2;
  *pfVar1 = *pfVar1 * fVar2;
  pfVar1[1] = pfVar1[1] * fVar2;
  fVar8 = param_2[2];
  fVar5 = param_2[9];
  fVar4 = param_2[5];
  fVar3 = param_2[1];
  pfVar1[2] = pfVar1[2] * fVar2;
  pfVar1[4] = fVar2 * -(fVar10 * fVar7 - fVar11 * fVar9);
  pfVar1[5] = fVar2 * (fVar6 * fVar7 - fVar8 * fVar9);
  pfVar1[6] = fVar2 * -(fVar6 * fVar11 - fVar8 * fVar10);
  pfVar1[8] = fVar2 * (fVar10 * fVar5 - fVar4 * fVar9);
  pfVar1[9] = fVar2 * -(fVar6 * fVar5 - fVar3 * fVar9);
  pfVar1[10] = fVar2 * (fVar6 * fVar4 - fVar3 * fVar10);
  fVar2 = param_2[0xd];
  fVar4 = param_2[0xc];
  fVar3 = param_2[0xe];
  pfVar1[0xc] = -(fVar3 * pfVar1[8] + fVar4 * *pfVar1 + fVar2 * pfVar1[4]);
  pfVar1[0xd] = -(fVar3 * pfVar1[9] + fVar4 * pfVar1[1] + fVar2 * pfVar1[5]);
  pfVar1[0xe] = -(fVar3 * pfVar1[10] + fVar4 * pfVar1[2] + fVar2 * pfVar1[6]);
  pfVar1[3] = 0.0;
  return param_1;
}
// FUN_004C2A30 NONMATCHING
u32 FUN_004c2a30(u8 *param_1)
{
  if (param_1 == (u8 *)0x0) {
    goto fallback;
  }
body:
  *(u8 **)(DAT_00960070_abs + iGpffffbbe8 + 8) = param_1;
  goto done;
fallback:
  param_1 = LAB_004c2200_abs;
  goto body;
done:
  return 1;
}
// FUN_004C2A70 NONMATCHING
float FUN_004c2a70(float *param_1)

{
  return (param_1[4] * param_1[9] - param_1[5] * param_1[8]) * param_1[2] +
         (param_1[5] * param_1[10] - param_1[6] * param_1[9]) * *param_1 +
         (param_1[6] * param_1[8] - param_1[4] * param_1[10]) * param_1[1];
}
// FUN_004C2AC0 NONMATCHING
float FUN_004c2ac0(float *param_1)
{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = param_1[6] * param_1[10] + param_1[4] * param_1[8] + param_1[5] * param_1[9];
  fVar1 = param_1[10] * param_1[2] + param_1[8] * *param_1 + param_1[9] * param_1[1];
  fVar2 = param_1[2] * param_1[6] + *param_1 * param_1[4] + param_1[1] * param_1[5];
  return fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1;
}
// FUN_004C2B20 NONMATCHING
float FUN_004c2b20(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = (param_1[2] * param_1[2] + *param_1 * *param_1 + param_1[1] * param_1[1]) - 1.0;
  fVar2 = (param_1[6] * param_1[6] + param_1[4] * param_1[4] + param_1[5] * param_1[5]) - 1.0;
  fVar1 = (param_1[10] * param_1[10] + param_1[8] * param_1[8] + param_1[9] * param_1[9]) - 1.0;
  return fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2;
}
// FUN_004C2B90 NONMATCHING
u64 FUN_004c2b90(u64 param_1)
{
  if (*(int *)(DAT_00960070_abs + (int)iGpffffbbe8) != 0) {
    FUN_004c3c30(*(int *)(DAT_00960070_abs + (int)iGpffffbbe8));
    *(u32 *)(DAT_00960070_abs + (int)iGpffffbbe8) = 0;
  }
  iGpffffbbec = iGpffffbbec + -1;
  return param_1;
}
// FUN_004C2C00 NONMATCHING
u64 FUN_004c2c00(u64 param_1,int param_2)

{
  int iVar1;
  u64 uStack_10;
  u32 uStack_8;
  
  iGpffffbbe8 = param_2;
  iVar1 = thunk_FUN_004c3970(0x40,uGpffffb040,0x10,uGpffffb044,0x95ff50,0x4000d);
  *(int *)((int)&DAT_00960070 + iGpffffbbe8) = iVar1;
  if (*(int *)((int)&DAT_00960070 + iGpffffbbe8) == 0) {
    param_1 = 0;
  }
  else {
    *(u32 *)((int)&DAT_00960074 + iGpffffbbe8) = 0x20000;
    *(u8 **)((int)&DAT_00960078 + iGpffffbbe8) = &LAB_004c2200;
    uStack_10 = DAT_0077e5b0;
    uStack_8 = DAT_0077e5b8;
    iGpffffbbec = iGpffffbbec + 1;
  }
  return param_1;
}
// FUN_004c2cc0
#pragma optimization_level 3
RwBool RwEngineGetMatrixTolerances(RwMatrixTolerance* const tolerance)
{
    RwUInt8* globals;
    RwBool result;

    globals = (RwUInt8*)&rwGlobals;
    result = true;
    *tolerance = *(RwMatrixTolerance*)(globals + rwMatrixTolerancesOffset + 0xc);

    return result;
}
#pragma optimization_level 2

// FUN_004C2CF0
#pragma optimization_level 3
RwBool RwEngineSetMatrixTolerances(const RwMatrixTolerance* const tolerance)
{
    RwUInt8* globals;
    RwBool result;

    globals = (RwUInt8*)&rwGlobals;
    result = true;
    *(RwMatrixTolerance*)(globals + rwMatrixTolerancesOffset + 0xc) = *tolerance;

    return result;
}
#pragma optimization_level 2
// FUN_004c2d20 NONMATCHING
#pragma optimization_level 3
RwMatrix* RwMatrixOptimize(RwMatrix* matrix, const RwMatrixTolerance* tolerance)
{
    RwReal normalError;
    RwReal orthogonalError;
    RwReal identityError;
    RwBool normalInvalid;
    RwBool orthogonalInvalid;
    RwBool isIdentity;
    RwUInt32 flags;

    if (tolerance == NULL)
    {
        tolerance = (const RwMatrixTolerance*)((RwUInt8*)&rwGlobals + rwMatrixTolerancesOffset + 0xc);
    }

    normalError = ((matrix->right.x * matrix->right.x) + (matrix->right.y * matrix->right.y) + (matrix->right.z * matrix->right.z)) - 1.0f;
    orthogonalError = ((matrix->up.x * matrix->up.x) + (matrix->up.y * matrix->up.y) + (matrix->up.z * matrix->up.z)) - 1.0f;
    identityError = ((matrix->at.x * matrix->at.x) + (matrix->at.y * matrix->at.y) + (matrix->at.z * matrix->at.z)) - 1.0f;
    normalInvalid = tolerance->normal < ((identityError * identityError) + (normalError * normalError) + (orthogonalError * orthogonalError));

    orthogonalError = (matrix->up.z * matrix->at.z) + (matrix->up.x * matrix->at.x) + (matrix->up.y * matrix->at.y);
    normalError = (matrix->at.z * matrix->right.z) + (matrix->at.x * matrix->right.x) + (matrix->at.y * matrix->right.y);
    identityError = (matrix->right.z * matrix->up.z) + (matrix->right.x * matrix->up.x) + (matrix->right.y * matrix->up.y);
    orthogonalInvalid = tolerance->orthogonal < ((identityError * identityError) + (orthogonalError * orthogonalError) + (normalError * normalError));
    isIdentity = false;

    if (!normalInvalid && !orthogonalInvalid)
    {
        identityError =
            (matrix->pos.z * matrix->pos.z) + (matrix->pos.x * matrix->pos.x) + (matrix->pos.y * matrix->pos.y) +
            ((matrix->at.z - 1.0f) * (matrix->at.z - 1.0f)) + (matrix->at.x * matrix->at.x) + (matrix->at.y * matrix->at.y) +
            (matrix->right.z * matrix->right.z) + ((matrix->right.x - 1.0f) * (matrix->right.x - 1.0f)) + (matrix->right.y * matrix->right.y) +
            (matrix->up.z * matrix->up.z) + (matrix->up.x * matrix->up.x) + ((matrix->up.y - 1.0f) * (matrix->up.y - 1.0f));
        if (identityError <= tolerance->identity)
        {
            isIdentity = true;
        }
    }

    if (normalInvalid)
    {
        flags = matrix->flags & ~rwMATRIXTYPENORMAL;
    }
    else
    {
        flags = matrix->flags | rwMATRIXTYPENORMAL;
    }
    if (orthogonalInvalid)
    {
        flags &= ~rwMATRIXTYPEORTHOGONAL;
    }
    else
    {
        flags |= rwMATRIXTYPEORTHOGONAL;
    }
    if (isIdentity)
    {
        flags |= rwMATRIXINTERNALIDENTITY;
    }
    else
    {
        flags &= ~rwMATRIXINTERNALIDENTITY;
    }
    matrix->flags = flags;

    return matrix;
}
#pragma optimization_level 2

// FUN_004c2f10
#pragma optimization_level 3
RwMatrix* RwMatrixUpdate(RwMatrix* matrix)
{
    matrix->flags &= ~(rwMATRIXTYPEMASK | rwMATRIXINTERNALIDENTITY);

    return matrix;
}
#pragma optimization_level 2

// FUN_004C2F30 NONMATCHING
u64 FUN_004c2f30(u64 param_1,u8 (*param_2) [16],u8 (*param_3) [16])

{
  u32 uVar1;
  u32 uVar2;
  u8 (*pauVar3) [16];
  Vec128 in_vf0;
  Vec128 auVar4;
  Vec128 auVar5;
  Vec128 auVar6;
  Vec128 auVar7;
  Vec128 auVar8;
  Vec128 auVar9;
  Vec128 auVar10;
  Vec128 auVar11;
  
  pauVar3 = (u8 (*) [16])param_1;
  auVar4 = _lqc2(*param_2);
  auVar5 = _lqc2(param_2[1]);
  auVar6 = _lqc2(param_2[2]);
  auVar7 = _lqc2(param_2[3]);
  uVar1 = *(u32 *)(*param_2 + 0xc);
  auVar8 = _lqc2(*param_3);
  auVar9 = _lqc2(param_3[1]);
  auVar10 = _lqc2(param_3[2]);
  auVar11 = _lqc2(param_3[3]);
  uVar2 = *(u32 *)(*param_3 + 0xc);
  _vmulabc(auVar8,auVar4);
  _vmaddabc(auVar9,auVar4);
  auVar4 = _vmaddbc(auVar10,auVar4);
  _vmulabc(auVar8,auVar5);
  _vmaddabc(auVar9,auVar5);
  auVar5 = _vmaddbc(auVar10,auVar5);
  _vmulabc(auVar8,auVar6);
  _vmaddabc(auVar9,auVar6);
  auVar6 = _vmaddbc(auVar10,auVar6);
  _vmulabc(auVar8,auVar7);
  _vmaddabc(auVar9,auVar7);
  _vmaddabc(auVar10,auVar7);
  auVar7 = _vmaddbc(auVar11,in_vf0);
  auVar4 = _sqc2(auVar4);
  *(union Vec128 *)pauVar3 = auVar4;
  auVar4 = _sqc2(auVar5);
  *(union Vec128 *)&pauVar3[1] = auVar4;
  auVar4 = _sqc2(auVar6);
  *(union Vec128 *)&pauVar3[2] = auVar4;
  auVar4 = _sqc2(auVar7);
  *(union Vec128 *)&pauVar3[3] = auVar4;
  *(u32 *)(*pauVar3 + 0xc) = uVar2 & uVar1;
  return param_1;
}



// FUN_004C2FB0 thunk_FUN_004c2330 NONMATCHING

u64 thunk_FUN_004c2330(u64 param_1,float *param_2)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float afStack_30 [12];
  
  pfVar2 = (float *)param_1;
  afStack_30[9] = param_2[1];
  afStack_30[0] = param_2[8];
  afStack_30[10] = param_2[2];
  afStack_30[8] = *param_2;
  afStack_30[4] = param_2[4];
  afStack_30[5] = param_2[5];
  afStack_30[1] = param_2[9];
  afStack_30[6] = param_2[6];
  afStack_30[2] = param_2[10];
  fVar5 = SQRT(afStack_30[10] * afStack_30[10] +
               afStack_30[8] * afStack_30[8] + afStack_30[9] * afStack_30[9]);
  fVar7 = param_2[0xc];
  fVar9 = param_2[0xd];
  fVar6 = param_2[0xe];
  if (0.0 < fVar5) {
    fVar5 = 1.0 / fVar5;
  }
  fVar10 = SQRT(afStack_30[6] * afStack_30[6] +
                afStack_30[4] * afStack_30[4] + afStack_30[5] * afStack_30[5]);
  afStack_30[9] = afStack_30[9] * fVar5;
  afStack_30[8] = afStack_30[8] * fVar5;
  afStack_30[10] = afStack_30[10] * fVar5;
  if (0.0 < fVar10) {
    fVar10 = 1.0 / fVar10;
  }
  afStack_30[5] = afStack_30[5] * fVar10;
  afStack_30[6] = afStack_30[6] * fVar10;
  fVar8 = SQRT(afStack_30[2] * afStack_30[2] +
               afStack_30[0] * afStack_30[0] + afStack_30[1] * afStack_30[1]);
  afStack_30[4] = afStack_30[4] * fVar10;
  if (0.0 < fVar8) {
    fVar8 = 1.0 / fVar8;
  }
  afStack_30[0] = afStack_30[0] * fVar8;
  afStack_30[1] = afStack_30[1] * fVar8;
  afStack_30[2] = afStack_30[2] * fVar8;
  if (0.0 < fVar5) {
    if (0.0 < fVar10) {
      if (0.0 < fVar8) {
        fVar5 = afStack_30[6] * afStack_30[2] +
                afStack_30[4] * afStack_30[0] + afStack_30[5] * afStack_30[1] + 0.0 + 0.0;
        if (fVar5 < 0.0) {
          fVar5 = -fVar5;
        }
        fVar10 = afStack_30[2] * afStack_30[10] +
                 afStack_30[0] * afStack_30[8] + afStack_30[1] * afStack_30[9];
        if (fVar10 < 0.0) {
          fVar10 = -fVar10;
        }
        fVar8 = afStack_30[10] * afStack_30[6] +
                afStack_30[8] * afStack_30[4] + afStack_30[9] * afStack_30[5];
        if (fVar8 < 0.0) {
          fVar8 = -fVar8;
        }
        if (fVar5 < fVar10) {
          if (fVar5 < fVar8) {
            pfVar4 = afStack_30 + 4;
            pfVar3 = afStack_30;
            pfVar1 = afStack_30 + 8;
          }
          else {
            pfVar4 = afStack_30 + 8;
            pfVar3 = afStack_30 + 4;
            pfVar1 = afStack_30;
          }
        }
        else if (fVar10 < fVar8) {
          pfVar4 = afStack_30;
          pfVar3 = afStack_30 + 8;
          pfVar1 = afStack_30 + 4;
        }
        else {
          pfVar4 = afStack_30 + 8;
          pfVar3 = afStack_30 + 4;
          pfVar1 = afStack_30;
        }
      }
      else {
        pfVar4 = afStack_30 + 8;
        pfVar3 = afStack_30 + 4;
        pfVar1 = afStack_30;
      }
    }
    else {
      pfVar4 = afStack_30;
      pfVar3 = afStack_30 + 8;
      pfVar1 = afStack_30 + 4;
    }
  }
  else {
    pfVar4 = afStack_30 + 4;
    pfVar3 = afStack_30;
    pfVar1 = afStack_30 + 8;
  }
  *pfVar1 = pfVar4[1] * pfVar3[2] - pfVar4[2] * pfVar3[1];
  pfVar1[1] = pfVar4[2] * *pfVar3 - *pfVar4 * pfVar3[2];
  pfVar1[2] = *pfVar4 * pfVar3[1] - pfVar4[1] * *pfVar3;
  fVar5 = SQRT(pfVar1[2] * pfVar1[2] + *pfVar1 * *pfVar1 + pfVar1[1] * pfVar1[1]);
  if (0.0 < fVar5) {
    fVar5 = 1.0 / fVar5;
  }
  *pfVar1 = *pfVar1 * fVar5;
  pfVar1[1] = pfVar1[1] * fVar5;
  fVar10 = pfVar1[2];
  pfVar1[2] = fVar10 * fVar5;
  *pfVar3 = pfVar1[1] * pfVar4[2] - fVar10 * fVar5 * pfVar4[1];
  pfVar3[1] = pfVar1[2] * *pfVar4 - *pfVar1 * pfVar4[2];
  pfVar3[2] = *pfVar1 * pfVar4[1] - pfVar1[1] * *pfVar4;
  fVar5 = SQRT(pfVar3[2] * pfVar3[2] + *pfVar3 * *pfVar3 + pfVar3[1] * pfVar3[1]);
  if (0.0 < fVar5) {
    fVar5 = 1.0 / fVar5;
  }
  *pfVar3 = *pfVar3 * fVar5;
  pfVar3[1] = pfVar3[1] * fVar5;
  pfVar3[2] = pfVar3[2] * fVar5;
  *pfVar2 = afStack_30[8];
  pfVar2[1] = afStack_30[9];
  pfVar2[2] = afStack_30[10];
  pfVar2[4] = afStack_30[4];
  pfVar2[5] = afStack_30[5];
  pfVar2[6] = afStack_30[6];
  pfVar2[8] = afStack_30[0];
  pfVar2[9] = afStack_30[1];
  pfVar2[10] = afStack_30[2];
  pfVar2[0xc] = fVar7;
  pfVar2[0xd] = fVar9;
  pfVar2[0xe] = fVar6;
  pfVar2[3] = (float)((u32)pfVar2[3] & 0xfffdffff | 3);
  return param_1;
}
// FUN_004C2FC0 NONMATCHING
float * FUN_004c2fc0(float param_1,float param_2,float *param_3,float *param_4,long param_5)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float afStack_90 [16];
  float afStack_50 [5];
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_8;
  u32 uStack_4;
  
  fVar7 = *param_4;
  uStack_20 = 0;
  afStack_50[3] = 4.2039e-45;
  fVar5 = param_4[1];
  uStack_1c = 0;
  uStack_18 = 0;
  afStack_50[0] = 1.0 - (1.0 - fVar7 * fVar7) * param_1;
  fVar4 = param_4[2];
  fStack_3c = 1.0 - (1.0 - fVar5 * fVar5) * param_1;
  fStack_28 = 1.0 - (1.0 - fVar4 * fVar4) * param_1;
  fVar8 = fVar5 * fVar4 * param_1;
  fVar6 = fVar4 * fVar7 * param_1;
  param_1 = fVar7 * fVar5 * param_1;
  afStack_50[1] = param_1 + fVar4 * param_2;
  afStack_50[4] = param_1 - fVar4 * param_2;
  afStack_50[2] = fVar6 - fVar5 * param_2;
  fStack_30 = fVar6 + fVar5 * param_2;
  fStack_38 = fVar8 + fVar7 * param_2;
  if (param_5 == 2) {
    FUN_004c2f30((u64)(afStack_90),(u8 (*)[16])(param_3),(u8 (*)[16])(afStack_50));
    pfVar3 = afStack_90;
    iVar1 = 8;
    pfVar2 = param_3;
    do {
      iVar1 = iVar1 + -1;
      fVar4 = pfVar3[1];
      *pfVar2 = *pfVar3;
      pfVar3 = pfVar3 + 2;
      pfVar2[1] = fVar4;
      pfVar2 = pfVar2 + 2;
    } while (0 < iVar1);
  }
  else if (param_5 == 1) {
    FUN_004c2f30((u64)(afStack_90),(u8 (*)[16])(afStack_50),(u8 (*)[16])(param_3));
    pfVar3 = afStack_90;
    iVar1 = 8;
    pfVar2 = param_3;
    do {
      iVar1 = iVar1 + -1;
      fVar4 = pfVar3[1];
      *pfVar2 = *pfVar3;
      pfVar3 = pfVar3 + 2;
      pfVar2[1] = fVar4;
      pfVar2 = pfVar2 + 2;
    } while (0 < iVar1);
  }
  else if (param_5 == 0) {
    pfVar3 = afStack_50;
    iVar1 = 8;
    pfVar2 = param_3;
    do {
      iVar1 = iVar1 + -1;
      fVar4 = pfVar3[1];
      *pfVar2 = *pfVar3;
      pfVar3 = pfVar3 + 2;
      pfVar2[1] = fVar4;
      pfVar2 = pfVar2 + 2;
    } while (0 < iVar1);
  }
  else {
    uStack_8 = 1;
    uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000003,0x77e5c0);
    FUN_004c1c50((u64)(unsigned int)(&uStack_8));
    param_3 = (float *)0x0;
  }
  return param_3;
}
// FUN_004c31b0 NONMATCHING
RwMatrix* RwMatrixRotate(RwMatrix* matrix, const RwV3d* axis, RwReal angle, RwOpCombineType combineOp)
{
    asm __volatile__(".set noreorder ;
        .word       0x27bdffb0 ;
        .word       0x3c023c8e ;
        .word       0xc4a00004 ;
        .word       0xffbf0030 ;
        .word       0x7fb10020 ;
        .word       0x3442fa35 ;
        .word       0x7fb00010 ;
        .word       0xc4a20000 ;
        .word       0x44820800 ;
        .word       0x0080882d ;
        .word       0xe7b40000 ;
        .word       0x00c0802d ;
        .word       0x460c0d02 ;
        .word       0x4600001a ;
        .word       0xc4a00008 ;
        .word       0x4602101e ;
        .word       0x44800800 ;
        .word       0x00000000 ;
        .word       0x4600001c ;
        .word       0x460000c4 ;
        .word       0x00000000 ;
        .word       0x00000000 ;
        .word       0x46011836 ;
        .word       0x45010008 ;
        .word       0x00000000 ;
        .word       0x3c023f80 ;
        .word       0x44820000 ;
        .word       0x00000000 ;
        .word       0x460300c3 ;
        .word       0x00000000 ;
        .word       0x00000000 ;
        .word       0x00000000 ;
        .word       0x46031002 ;
        .word       0xe7a00040 ;
        .word       0xc4a10004 ;
        .word       0xc4a00008 ;
        .word       0x4600a306 ;
        .word       0x46030842 ;
        .word       0x46030002 ;
        .word       0xe7a10044 ;
        .word       0x0c14ba1e ;
        .word       0xe7a00048 ;
        .word       0x4600a306 ;
        .word       0x0c14b9b6 ;
        .word       0x46000506 ;
        .word       0x3c023f80 ;
        .word       0x0200302d ;
        .word       0x44820800 ;
        .word       0x0220202d ;
        .word       0x4600a346 ;
        .word       0x27a50040 ;
        .word       0x0c130bf0 ;
        .word       0x46000b01 ;
        .word       0x0220102d ;
        .word       0xdfbf0030 ;
        .word       0x7bb10020 ;
        .word       0xc7b40000 ;
        .word       0x7bb00010 ;
        jr          $31 ;
        .word       0x27bd0050 ;
        .set reorder " ::: "memory");
}

// FUN_004C32A0 NONMATCHING
u64 FUN_004c32a0(u64 param_1,float *param_2)

{
  float *pfVar1;
  float *extraout_a0_lo;
  u32 uVar2;
  u32 extraout_a0_hi;
  int iVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  
  uVar2 = (u32)((u32)param_1 >> 0x20);
  pfVar1 = (float *)param_1;
  if (((u32)param_2[3] & *(u32 *)((int)&DAT_00960074 + iGpffffbbe8) & 0x20000) == 0) {
    if (((u32)param_2[3] & 3) == 3) {
      fVar15 = *param_2;
      fVar16 = param_2[4];
      fVar13 = param_2[8];
      fVar14 = param_2[1];
      fVar11 = param_2[5];
      fVar8 = param_2[0xd];
      *pfVar1 = fVar15;
      pfVar1[1] = fVar16;
      pfVar1[2] = fVar13;
      pfVar1[4] = fVar14;
      fVar12 = param_2[9];
      pfVar1[5] = fVar11;
      fVar6 = param_2[2];
      fVar7 = param_2[0xc];
      fVar10 = param_2[0xe];
      pfVar1[6] = fVar12;
      fVar5 = param_2[6];
      pfVar1[8] = fVar6;
      fVar9 = param_2[10];
      pfVar1[9] = fVar5;
      pfVar1[10] = fVar9;
      pfVar1[0xc] = -(fVar10 * fVar6 + fVar7 * fVar15 + fVar8 * fVar14);
      pfVar1[0xd] = -(fVar10 * fVar5 + fVar7 * fVar16 + fVar8 * fVar11);
      pfVar1[0xe] = -(fVar10 * fVar9 + fVar7 * fVar13 + fVar8 * fVar12);
      pfVar1[3] = 4.2039e-45;
    }
    else {
      FUN_004c2860(0,0);
      pfVar1 = extraout_a0_lo;
      uVar2 = extraout_a0_hi;
    }
  }
  else {
    iVar3 = 8;
    pfVar4 = pfVar1;
    do {
      iVar3 = iVar3 + -1;
      fVar5 = param_2[1];
      *pfVar4 = *param_2;
      pfVar4[1] = fVar5;
      param_2 = param_2 + 2;
      pfVar4 = pfVar4 + 2;
    } while (0 < iVar3);
  }
  return CONCAT44(uVar2,pfVar1);
}
// FUN_004c33d0 NONMATCHING
RwMatrix* RwMatrixScale(RwMatrix* matrix, const RwV3d* scale, RwOpCombineType combineOp)
{
    RwUInt32 error[2];

    if (combineOp == rwCOMBINEPOSTCONCAT)
    {
        matrix->right.x *= scale->x;
        matrix->right.y *= scale->y;
        matrix->right.z *= scale->z;
        matrix->up.x *= scale->x;
        matrix->up.y *= scale->y;
        matrix->up.z *= scale->z;
        matrix->at.x *= scale->x;
        matrix->at.y *= scale->y;
        matrix->at.z *= scale->z;
        matrix->pos.x *= scale->x;
        matrix->pos.y *= scale->y;
        matrix->pos.z *= scale->z;
    }
    else if (combineOp == rwCOMBINEPRECONCAT)
    {
        matrix->right.x *= scale->x;
        matrix->right.y *= scale->x;
        matrix->right.z *= scale->x;
        matrix->up.x *= scale->y;
        matrix->up.y *= scale->y;
        matrix->up.z *= scale->y;
        matrix->at.x *= scale->z;
        matrix->at.y *= scale->z;
        matrix->at.z *= scale->z;
    }
    else if (combineOp == rwCOMBINEREPLACE)
    {
        RwMatrixSetIdentity(matrix);
        matrix->right.x = scale->x;
        matrix->up.y = scale->y;
        matrix->at.z = scale->z;
    }
    else
    {
        error[0] = 1;
        error[1] = func_004c1d10(0x80000003, (const char*)0x0077e5c0);
        func_004c1c50(error);
        matrix = NULL;
    }

    matrix->flags &= ~(rwMATRIXTYPEMASK | rwMATRIXINTERNALIDENTITY);
    return matrix;
}

// FUN_004c35d0 NONMATCHING
RwMatrix* RwMatrixTranslate(RwMatrix* matrix, const RwV3d* translation, RwOpCombineType combineOp)
{
    asm __volatile__(".set noreorder ;
        .word       0x27bdffe0 ;
        .word       0x24020002 ;
        .word       0x10c20040 ;
        .word       0xffbf0000 ;
        .word       0x24020001 ;
        .word       0x10c2001e ;
        .word       0x00000000 ;
        .word       0x10c00003 ;
        .word       0x00000000 ;
        .word       0x10000046 ;
        .word       0xafa20018 ;
        .word       0x3c033f80 ;
        .word       0x3c020002 ;
        .word       0xac830028 ;
        .word       0xc4a20000 ;
        .word       0xac830014 ;
        .word       0xc4a10004 ;
        .word       0xac830000 ;
        .word       0xc4a00008 ;
        .word       0xac800010 ;
        .word       0x34420003 ;
        .word       0xac800008 ;
        .word       0xac800004 ;
        .word       0xac800024 ;
        .word       0xac800020 ;
        .word       0xac800018 ;
        .word       0xac800038 ;
        .word       0xac800034 ;
        .word       0xac800030 ;
        .word       0x8c83000c ;
        .word       0x00621025 ;
        .word       0xac82000c ;
        .word       0xe4820030 ;
        .word       0xe4810034 ;
        .word       0x10000036 ;
        .word       0xe4800038 ;
        .word       0xc4a40004 ;
        .word       0xc4810010 ;
        .word       0xc4a50000 ;
        .word       0xc4820000 ;
        .word       0xc4a60008 ;
        .word       0xc4830020 ;
        .word       0xc4800030 ;
        .word       0x4601201a ;
        .word       0x4602281e ;
        .word       0x4603305c ;
        .word       0x46010000 ;
        .word       0xe4800030 ;
        .word       0xc4810014 ;
        .word       0xc4820004 ;
        .word       0xc4830024 ;
        .word       0xc4800034 ;
        .word       0x4601201a ;
        .word       0x4602281e ;
        .word       0x4603305c ;
        .word       0x46010000 ;
        .word       0xe4800034 ;
        .word       0xc4810018 ;
        .word       0xc4820008 ;
        .word       0xc4830028 ;
        .word       0xc4800038 ;
        .word       0x4601201a ;
        .word       0x4602281e ;
        .word       0x4603305c ;
        .word       0x46010000 ;
        .word       0x10000017 ;
        .word       0xe4800038 ;
        .word       0xc4830030 ;
        .word       0xc4a00000 ;
        .word       0xc4a20004 ;
        .word       0xc4a10008 ;
        .word       0x46001800 ;
        .word       0xe4800030 ;
        .word       0xc4800034 ;
        .word       0x46020000 ;
        .word       0xe4800034 ;
        .word       0xc4800038 ;
        .word       0x46010000 ;
        .word       0x1000000a ;
        .word       0xe4800038 ;
        .word       0x3c050078 ;
        .word       0x3c028000 ;
        .word       0x24a5e5c0 ;
        .word       0x0c130744 ;
        .word       0x34440003 ;
        .word       0xafa2001c ;
        .word       0x0c130714 ;
        .word       0x27a40018 ;
        .word       0x0000202d ;
        .word       0x8c85000c ;
        .word       0x3c02fffd ;
        .word       0x3443ffff ;
        .word       0x0080102d ;
        .word       0x00a31824 ;
        .word       0xac83000c ;
        .word       0xdfbf0000 ;
        jr          $31 ;
        .word       0x27bd0020 ;
        .set reorder " ::: "memory");
}

// FUN_004C3760 NONMATCHING
u32 * FUN_004c3760(u32 *param_1,u32 *param_2,long param_3)

{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  u32 *puVar4;
  u32 auStack_90 [16];
  u32 auStack_50 [18];
  u32 uStack_8;
  u32 uStack_4;
  if (param_3 == 2) {
    FUN_004c2f30((u64)(auStack_90),(u8 (*)[16])(param_1),(u8 (*)[16])(param_2));
    puVar4 = auStack_90;
    iVar2 = 8;
    puVar3 = param_1;
    do {
      iVar2 = iVar2 + -1;
      uVar1 = puVar4[1];
      *puVar3 = *puVar4;
      puVar4 = puVar4 + 2;
      puVar3[1] = uVar1;
      puVar3 = puVar3 + 2;
    } while (0 < iVar2);
  }
  else if (param_3 == 1) {
    FUN_004c2f30((u64)(auStack_50),(u8 (*)[16])(param_2),(u8 (*)[16])(param_1));
    puVar4 = auStack_50;
    iVar2 = 8;
    puVar3 = param_1;
    do {
      iVar2 = iVar2 + -1;
      uVar1 = puVar4[1];
      *puVar3 = *puVar4;
      puVar4 = puVar4 + 2;
      puVar3[1] = uVar1;
      puVar3 = puVar3 + 2;
    } while (0 < iVar2);
  }
  else if (param_3 == 0) {
    iVar2 = 8;
    puVar3 = param_1;
    do {
      iVar2 = iVar2 + -1;
      uVar1 = param_2[1];
      *puVar3 = *param_2;
      puVar3[1] = uVar1;
      param_2 = param_2 + 2;
      puVar3 = puVar3 + 2;
    } while (0 < iVar2);
  }
  else {
    uStack_8 = 1;
    uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000003,0x77e5c0);
    FUN_004c1c50((u64)(unsigned int)(&uStack_8));
    param_1 = (u32 *)0x0;
  }
  return param_1;
}
#pragma schedule on
// FUN_004C3880
u32 FUN_004c3880(u64 param_1)

{
  DAT_0096018c_abs[0](*(u32 *)(DAT_00960070_abs + (int)iGpffffbbe8),param_1);
  return 1;
}
#pragma schedule off
// FUN_004C38C0 NONMATCHING
void FUN_004c38c0(void)

{
  u32 *puVar1;
  long lVar2;
  
  lVar2 = (*DAT_00960188)(*(u32 *)((int)&DAT_00960070 + iGpffffbbe8),0x3000d);
  if (lVar2 != 0) {
    puVar1 = (u32 *)lVar2;
    puVar1[3] = 3;
    puVar1[10] = 0x3f800000;
    puVar1[5] = 0x3f800000;
    *puVar1 = 0x3f800000;
    puVar1[4] = 0;
    puVar1[2] = 0;
    puVar1[1] = 0;
    puVar1[9] = 0;
    puVar1[8] = 0;
    puVar1[6] = 0;
    puVar1[0xe] = 0;
    puVar1[0xd] = 0;
    puVar1[0xc] = 0;
    puVar1[3] = puVar1[3] | 0x20003;
  }
  return;
}
#pragma optimization_level 3
// FUN_004C3960
void FUN_004c3960(RwBool useDefaultMemory)

{
  uGpffffb048 = useDefaultMemory;
  return;
}
#pragma optimization_level 2
// FUN_004C3970 NONMATCHING
long FUN_004c3970(int param_1,u32 param_2,long param_3,int param_4,long param_5,u32 param_6)

{
  u32 *puVar1;
  long lVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 *puVar6;
  
  if (iGpffffb048 == 0) {
    param_4 = 0;
  }
  if (param_3 == 0) {
    param_3 = 0x10;
  }
  if (param_5 == 0) {
    if (iGpffffbbf4 == 0) {
      param_5 = (*DAT_00960178)(0x24,param_6 & 0xff0000);
    }
    else {
      param_5 = (*DAT_00960188)(iGpffffbbf4,param_6 & 0xff0000);
    }
    if (param_5 == 0) {
      return 0;
    }
    *(u32 *)((int)param_5 + 0x18) = 2;
  }
  else {
    *(u32 *)((int)param_5 + 0x18) = 3;
  }
  uVar4 = (u32)param_3;
  uVar3 = ~(uVar4 - 1) & param_1 + (uVar4 - 1);
  puVar6 = (u32 *)param_5;
  *puVar6 = uVar3;
  puVar6[1] = param_2;
  uVar5 = param_2 + 7 >> 3;
  puVar6[3] = uVar4;
  puVar6[2] = uVar5;
  puVar6[4] = (u32)(puVar6 + 4);
  puVar6[5] = (u32)(puVar6 + 4);
  if (param_4 != 0) {
    do {
      lVar2 = (*DAT_00960178)(uVar4 + uVar5 + 7 + param_2 * uVar3,param_6);
      if (lVar2 == 0) {
        return 0;
      }
      puVar1 = (u32 *)lVar2;
      puVar1[1] = 0;
      *puVar1 = 0;
      *puVar1 = puVar6[4];
      puVar1[1] = (u32)(puVar6 + 4);
      *(u32 **)(puVar6[4] + 4) = puVar1;
      puVar6[4] = (u32)puVar1;
      FUN_00521408(puVar1 + 2,0,uVar5);
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  puVar6[7] = (u32)puGpffffbbf8;
  puVar6[8] = (u32)&puGpffffbbf8;
  *(u32 **)((int)puGpffffbbf8 + 4) = puVar6 + 7;
  puGpffffbbf8 = puVar6 + 7;
  return param_5;
}
#pragma optimization_level 3
// FUN_004C3B50
long FUN_004c3b50(int param_1, u32 param_2, long param_3, int param_4)
{
  return FUN_004c3970(param_1, param_2, param_3, 1, 0, param_4);
}
#pragma optimization_level 2



// FUN_004C3B60 thunk_FUN_004c3970 NONMATCHING

long thunk_FUN_004c3970(int param_1,u32 param_2,long param_3,int param_4,long param_5,u32 param_6
                       )

{
  u32 *puVar1;
  long lVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 *puVar6;
  
  if (iGpffffb048 == 0) {
    param_4 = 0;
  }
  if (param_3 == 0) {
    param_3 = 0x10;
  }
  if (param_5 == 0) {
    if (iGpffffbbf4 == 0) {
      param_5 = (*DAT_00960178)(0x24,param_6 & 0xff0000);
    }
    else {
      param_5 = (*DAT_00960188)(iGpffffbbf4,param_6 & 0xff0000);
    }
    if (param_5 == 0) {
      return 0;
    }
    *(u32 *)((int)param_5 + 0x18) = 2;
  }
  else {
    *(u32 *)((int)param_5 + 0x18) = 3;
  }
  uVar4 = (u32)param_3;
  uVar3 = ~(uVar4 - 1) & param_1 + (uVar4 - 1);
  puVar6 = (u32 *)param_5;
  *puVar6 = uVar3;
  puVar6[1] = param_2;
  uVar5 = param_2 + 7 >> 3;
  puVar6[3] = uVar4;
  puVar6[2] = uVar5;
  puVar6[4] = (u32)(puVar6 + 4);
  puVar6[5] = (u32)(puVar6 + 4);
  if (param_4 != 0) {
    do {
      lVar2 = (*DAT_00960178)(uVar4 + uVar5 + 7 + param_2 * uVar3,param_6);
      if (lVar2 == 0) {
        FUN_004c3b70(param_5);
        return 0;
      }
      puVar1 = (u32 *)lVar2;
      puVar1[1] = 0;
      *puVar1 = 0;
      *puVar1 = puVar6[4];
      puVar1[1] = (u32)(puVar6 + 4);
      *(u32 **)(puVar6[4] + 4) = puVar1;
      puVar6[4] = (u32)puVar1;
      FUN_00521408(puVar1 + 2,0,uVar5);
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  puVar6[7] = (u32)puGpffffbbf8;
  puVar6[8] = (u32)&puGpffffbbf8;
  *(u32 **)((int)puGpffffbbf8 + 4) = puVar6 + 7;
  puGpffffbbf8 = puVar6 + 7;
  return param_5;
}
// FUN_004C3B70 NONMATCHING
void FUN_004c3b70(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x10);
  if (piVar1 != (int *)(param_1 + 0x10)) {
    do {
      *(int *)piVar1[1] = *piVar1;
      *(int *)(*piVar1 + 4) = piVar1[1];
      (*DAT_0096017c)();
      piVar1 = *(int **)(param_1 + 0x10);
    } while (piVar1 != (int *)(param_1 + 0x10));
  }
  if ((*(u32 *)(param_1 + 0x18) & 1) == 0) {
    if ((iGpffffbbf4 == param_1) || (iGpffffbbf4 == 0)) {
      (*DAT_0096017c)(param_1);
    }
    else {
      (*DAT_0096018c)(iGpffffbbf4,param_1);
    }
  }
  return;
}
// FUN_004C3C30 NONMATCHING
u32 FUN_004c3c30(int param_1)

{
  int *piVar1;
  
  **(u32 **)(param_1 + 0x20) = *(u32 *)(param_1 + 0x1c);
  *(u32 *)(*(int *)(param_1 + 0x1c) + 4) = *(u32 *)(param_1 + 0x20);
  piVar1 = *(int **)(param_1 + 0x10);
  if (piVar1 != (int *)(param_1 + 0x10)) {
    do {
      *(int *)piVar1[1] = *piVar1;
      *(int *)(*piVar1 + 4) = piVar1[1];
      (*DAT_0096017c)();
      piVar1 = *(int **)(param_1 + 0x10);
    } while (piVar1 != (int *)(param_1 + 0x10));
  }
  if ((*(u32 *)(param_1 + 0x18) & 1) == 0) {
    if ((iGpffffbbf4 == param_1) || (iGpffffbbf4 == 0)) {
      (*DAT_0096017c)(param_1);
    }
    else {
      (*DAT_0096018c)(iGpffffbbf4,param_1);
    }
  }
  return 1;
}
// FUN_004C3D10 NONMATCHING
u32 FUN_004c3d10(int *param_1)

{
  u8 bVar1;
  u32 uVar2;
  u32 uVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  u32 uVar7;
  u32 uVar8;
  u8 *pbVar9;
  u32 uVar10;
  int *piVar11;
  
  uVar3 = 0;
  uVar2 = param_1[2];
  piVar11 = (int *)param_1[4];
  do {
    if ((piVar11 == param_1 + 4) || (uVar3 != 0)) {
      if (uVar3 == 0) {
        lVar4 = (*DAT_00960178)(param_1[3] + uVar2 + 7 + param_1[1] * *param_1);
        if (lVar4 == 0) {
          uVar3 = 0;
        }
        else {
          piVar11 = (int *)lVar4;
          FUN_00521408(piVar11 + 2,0,uVar2);
          *piVar11 = param_1[4];
          piVar11[1] = (int)(param_1 + 4);
          *(int **)(param_1[4] + 4) = piVar11;
          param_1[4] = (int)piVar11;
          *(u8 *)(piVar11 + 2) = 0x80;
          uVar3 = (int)piVar11 + param_1[3] + uVar2 + 7 & ~(param_1[3] - 1U);
        }
      }
      return uVar3;
    }
    iVar6 = param_1[1];
    uVar7 = 0;
    if (uVar2 != 0) {
      iVar5 = 0;
      do {
        pbVar9 = (u8 *)((int)piVar11 + uVar7 + 8);
        bVar1 = *pbVar9;
        if (bVar1 == 0xff) {
          iVar6 = iVar6 + -8;
        }
        else {
          uVar10 = 0;
          while( true ) {
            if ((7 < uVar10) || (iVar6 == 0)) goto LAB_004c3dc0;
            uVar8 = 0x80 >> (uVar10 & 0x1f);
            if (((u32)bVar1 & uVar8 & 0xff) == 0) break;
            uVar10 = uVar10 + 1;
            iVar6 = iVar6 + -1;
          }
          *pbVar9 = (u8)uVar8 | bVar1;
          uVar3 = ((int)piVar11 + param_1[3] + uVar2 + 7 & ~(param_1[3] - 1U)) +
                  *param_1 * (iVar5 + uVar10);
        }
LAB_004c3dc0:
        if (uVar3 != 0) break;
        uVar7 = uVar7 + 1;
        iVar5 = iVar5 + 8;
      } while (uVar7 < uVar2);
    }
    piVar11 = (int *)*piVar11;
  } while( true );
}
// FUN_004C3EE0 NONMATCHING
u64 FUN_004c3ee0(u64 param_1,u32 param_2)

{
  u32 uVar1;
  int *piVar2;
  int *piVar3;
  u32 uVar4;
  u8 *pbVar5;
  u32 uVar6;
  int iVar7;
  
  piVar3 = (int *)param_1;
  uVar1 = piVar3[2];
  piVar2 = (int *)piVar3[4];
  while( true ) {
    if (piVar2 == piVar3 + 4) {
      return 0;
    }
    uVar6 = (int)piVar2 + uVar1 + 8;
    if ((uVar6 <= param_2) && (param_2 <= uVar6 + piVar3[1] * *piVar3)) break;
    piVar2 = (int *)*piVar2;
  }
  uVar6 = (int)(param_2 - uVar6) / *piVar3;
  uVar4 = uVar6 >> 3;
  pbVar5 = (u8 *)((int)piVar2 + uVar4 + 8);
  *pbVar5 = *pbVar5 & ~(u8)(0x80 >> (uVar6 + uVar4 * -8 & 0x1f));
  if ((piVar3[6] & 2U) == 0) {
    return param_1;
  }
  iVar7 = 0;
  uVar6 = 0;
  if (uVar1 != 0) {
    if (8 < uVar1) {
      do {
        pbVar5 = (u8 *)((int)piVar2 + uVar6 + 8);
        uVar6 = uVar6 + 8;
        iVar7 = iVar7 + (u32)*pbVar5 + (u32)pbVar5[1] + (u32)pbVar5[2] + (u32)pbVar5[3] +
                (u32)pbVar5[4] + (u32)pbVar5[5] + (u32)pbVar5[6] + (u32)pbVar5[7];
      } while (uVar6 < uVar1 - 8);
    }
    for (; uVar6 < uVar1; uVar6 = uVar6 + 1) {
      iVar7 = iVar7 + (u32)*(u8 *)((int)piVar2 + uVar6 + 8);
    }
  }
  if (iVar7 != 0) {
    return param_1;
  }
  *(int *)piVar2[1] = *piVar2;
  *(int *)(*piVar2 + 4) = piVar2[1];
  (*DAT_0096017c)();
  return param_1;
}
// FUN_004C4080 NONMATCHING
int FUN_004c4080(int *param_1)

{
  u32 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  u32 uVar5;
  u8 *pbVar6;
  int iVar7;
  
  uVar1 = param_1[2];
  iVar7 = 0;
  piVar3 = (int *)param_1[4];
  while (piVar3 != param_1 + 4) {
    iVar4 = 0;
    *(int *)piVar3[1] = *piVar3;
    *(int *)(*piVar3 + 4) = piVar3[1];
    piVar2 = (int *)*piVar3;
    uVar5 = 0;
    if (uVar1 != 0) {
      if (8 < uVar1) {
        do {
          pbVar6 = (u8 *)((int)piVar3 + uVar5 + 8);
          uVar5 = uVar5 + 8;
          iVar4 = iVar4 + (u32)*pbVar6 + (u32)pbVar6[1] + (u32)pbVar6[2] + (u32)pbVar6[3] +
                  (u32)pbVar6[4] + (u32)pbVar6[5] + (u32)pbVar6[6] + (u32)pbVar6[7];
        } while (uVar5 < uVar1 - 8);
      }
      for (; uVar5 < uVar1; uVar5 = uVar5 + 1) {
        iVar4 = iVar4 + (u32)*(u8 *)((int)piVar3 + uVar5 + 8);
      }
    }
    if (iVar4 == 0) {
      (*DAT_0096017c)();
      iVar7 = iVar7 + 1;
      piVar3 = piVar2;
    }
    else {
      *piVar3 = param_1[4];
      piVar3[1] = (int)(param_1 + 4);
      *(int **)(param_1[4] + 4) = piVar3;
      param_1[4] = (int)piVar3;
      piVar3 = piVar2;
    }
  }
  return iVar7 * *param_1;
}
// FUN_004C4200 NONMATCHING
u64 FUN_004c4200(u64 param_1,code *param_2,u64 param_3)

{
  u8 bVar1;
  u32 uVar2;
  int *piVar3;
  int *piVar4;
  long lVar5;
  int iVar6;
  u32 uVar7;
  u32 uVar8;
  int *piVar9;
  
  piVar9 = (int *)param_1;
  uVar2 = piVar9[2];
  piVar4 = (int *)piVar9[4];
  while( true ) {
    if (piVar4 == piVar9 + 4) {
      return param_1;
    }
    lVar5 = (*DAT_00960178)(uVar2,0x10000);
    if (lVar5 == 0) break;
    FUN_00521250(lVar5,piVar4 + 2,uVar2);
    piVar3 = (int *)*piVar4;
    uVar8 = 0;
    if (uVar2 != 0) {
      iVar6 = 0;
      do {
        bVar1 = *(u8 *)((int)lVar5 + uVar8);
        if (bVar1 != 0) {
          uVar7 = 0;
          do {
            if (((u32)bVar1 & 0x80 >> (uVar7 & 0x1f) & 0xffU) != 0) {
              (*param_2)(((int)piVar4 + piVar9[3] + uVar2 + 7 & ~(piVar9[3] - 1U)) +
                         *piVar9 * (iVar6 + uVar7),param_3);
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < 8);
        }
        uVar8 = uVar8 + 1;
        iVar6 = iVar6 + 8;
      } while (uVar8 < uVar2);
    }
    (*DAT_0096017c)(lVar5);
    piVar4 = piVar3;
  }
  return 0;
}
// FUN_004C43B0 NONMATCHING
int FUN_004c43b0(void)

{
  u32 *puVar1;
  long lVar2;
  int iVar3;
  
  iVar3 = 0;
  for (puVar1 = DAT_007ce8e8; (u32 **)puVar1 != &DAT_007ce8e8; puVar1 = (u32 *)*puVar1
      ) {
    lVar2 = (long)(unsigned int)FUN_004c4080((int *)(puVar1 + -7));
    if (0 < lVar2) {
      iVar3 = iVar3 + (int)lVar2;
    }
  }
  return iVar3;
}
// FUN_004C4450 NONMATCHING
u32 FUN_004c4450(long param_1)

{
  u32 uVar1;
  long lVar2;
  u32 *puVar3;
  
  DAT_007ce8e0 = 1;
  DAT_007ce8e8 = (u32 *)&DAT_007ce8e8;
  DAT_007ce8ec = (u32)(&DAT_007ce8e8);
  lVar2 = FUN_004c3970(0x24,0x10,0x10,0,0x95ff80,0x40000);
  DAT_007ce8e4 = (int)lVar2;
  if (lVar2 == 0) {
    DAT_007ce8e0 = 0;
    uVar1 = 0;
  }
  else {
    **(u32 **)(DAT_007ce8e4 + 0x20) = *(u32 *)(DAT_007ce8e4 + 0x1c);
    *(u32 *)(*(int *)(DAT_007ce8e4 + 0x1c) + 4) = *(u32 *)(DAT_007ce8e4 + 0x20);
    if (param_1 == 0) {
      DAT_00960178 = (code *)((u32)(&LAB_004c4420));
      DAT_0096017c = (code *)((u32)(FUN_00520748));
      DAT_00960180 = (code *)((u32)(&LAB_004c4430));
      DAT_00960184 = (code *)((u32)(&LAB_004c4440));
    }
    else {
      puVar3 = (u32 *)param_1;
      DAT_00960178 = (code *)((u32)((u8 *)*puVar3));
      DAT_0096017c = (code *)((u32)((code *)puVar3[1]));
      DAT_00960180 = (code *)((u32)((u8 *)puVar3[2]));
      DAT_00960184 = (code *)((u32)((u8 *)puVar3[3]));
    }
    uVar1 = 1;
  }
  return uVar1;
}
// FUN_004C4570 NONMATCHING
void FUN_004c4570(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = DAT_007ce8e4;
  piVar2 = (int *)(DAT_007ce8e8);
  while (DAT_007ce8e4 = iVar1, DAT_007ce8e8 = (u32 *)piVar2, (int **)piVar2 != (int **)&DAT_007ce8e8) {
    *(int *)piVar2[1] = *piVar2;
    *(int *)(*piVar2 + 4) = piVar2[1];
    FUN_004c3b70((int)(piVar2 + -7));
    iVar1 = DAT_007ce8e4;
    piVar2 = (int *)(DAT_007ce8e8);
  }
  **(u32 **)(iVar1 + 0x20) = *(u32 *)(iVar1 + 0x1c);
  *(u32 *)(*(int *)(iVar1 + 0x1c) + 4) = *(u32 *)(iVar1 + 0x20);
  FUN_004c3b70(0);
  DAT_007ce8e4 = 0;
  DAT_007ce8e0 = 0;
  return;
}
// FUN_004C45F0 NONMATCHING
u64 FUN_004c45f0(u64 param_1,long param_2)

{
  u32 uVar1;
  long lVar2;
  u32 *puVar3;
  u32 *puVar4;
  u32 *puVar5;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  puVar5 = (u32 *)param_1;
  if (param_2 == 0) {
    puVar5[3] = 0;
  }
  else {
    uVar1 = (*DAT_00960178)(param_2,0x4040b);
    puVar5[3] = uVar1;
    if (puVar5[3] == 0) {
      uStack_8 = 1;
      uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,param_2);
      FUN_004c1c50((u64)(unsigned int)(&uStack_8));
      return 0;
    }
    lVar2 = (long)(unsigned int)FUN_004c6df0((u32 *)(unsigned int)puVar5[3],param_2);
    if (lVar2 == 0) {
      (*DAT_0096017c)(puVar5[3]);
      uStack_10 = 1;
      uStack_c = ((code)FUN_004c1d10)(0xc,0);
      FUN_004c1c50((u64)(unsigned int)(&uStack_10));
      return 0;
    }
  }
  puVar4 = puVar5 + 4;
  puVar3 = puVar5 + 6;
  puVar5[4] = (u32)(puVar4);
  puVar5[5] = (u32)(puVar4);
  puVar5[6] = (u32)(puVar3);
  puVar5[7] = (u32)(puVar3);
  puVar5[9] = (u32)(puVar4);
  puVar5[8] = (u32)(puVar3);
  *puVar5 = (int)param_2;
  puVar5[1] = 0;
  puVar5[2] = 0;
  return param_1;
}
// FUN_004C46F0 NONMATCHING
u64 FUN_004c46f0(u64 param_1,int param_2)

{
  long lVar1;
  
  DAT_007ce8f0 = (u32 *)(param_2);
  lVar1 = FUN_004c45f0((int)&DAT_00960070 + param_2,DAT_00960198);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  else {
    DAT_007ce8f4 = DAT_007ce8f4 + 1;
  }
  return param_1;
}
// FUN_004C4750 NONMATCHING
u64 FUN_004c4750(u64 param_1)

{
  if (*(int *)((int)(&DAT_0096007c) + (int)(DAT_007ce8f0)) != 0) {
    (*DAT_0096017c)(*(u32 *)((int)(&DAT_0096007c) + (int)(DAT_007ce8f0)));
    *(u32 *)((int)(&DAT_0096007c) + (int)(DAT_007ce8f0)) = 0;
  }
  DAT_007ce8f4 = DAT_007ce8f4 + -1;
  return param_1;
}
// FUN_004C47E0 NONMATCHING
u32 FUN_004c47e0(u64 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1;
  if ((code *)piVar1[5] != (code *)0x0) {
    (*(code *)piVar1[5])();
  }
  if ((u32 *)piVar1[4] != (u32 *)0x0) {
    *(u32 *)piVar1[4] = 0;
  }
  if (*piVar1 == 0) {
    (*DAT_0096017c)(param_1);
  }
  else {
    *(int *)piVar1[1] = *piVar1;
    *(int *)(*piVar1 + 4) = piVar1[1];
    *(int *)((int)&DAT_00960074 + DAT_007ce8f0) =
         *(int *)((int)&DAT_00960074 + DAT_007ce8f0) - piVar1[2];
  }
  return 1;
}
// FUN_004C4890 NONMATCHING
void FUN_004c4890(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  u32 *puVar5;
  int iVar6;
  
  piVar1 = *(int **)((int)&DAT_00960090 + DAT_007ce8f0);
  piVar2 = (int *)*piVar1;
  piVar3 = *(int **)((int)&DAT_00960094 + DAT_007ce8f0);
  if (piVar2 != piVar1) {
    if ((int *)*piVar3 == piVar3) {
      *piVar3 = (int)piVar2;
      *(int **)(*piVar3 + 4) = piVar3;
      piVar3[1] = piVar1[1];
      *(int **)piVar3[1] = piVar3;
      *piVar1 = (int)piVar1;
      piVar1[1] = (int)piVar1;
    }
    else {
      piVar4 = (int *)piVar3[1];
      *piVar4 = (int)piVar2;
      piVar2[1] = (int)piVar4;
      puVar5 = (u32 *)piVar1[1];
      *puVar5 = (u32)(piVar3);
      piVar3[1] = (int)puVar5;
      *piVar1 = (int)piVar1;
      piVar1[1] = (int)piVar1;
    }
  }
  iVar6 = (int)(DAT_007ce8f0);
  *(int **)((int)&DAT_00960094 + DAT_007ce8f0) = piVar1;
  *(int **)((int)&DAT_00960090 + iVar6) = piVar3;
  *(u32 *)((int)&DAT_00960078 + iVar6) = 0;
  return;
}
// FUN_004C4930 NONMATCHING
long FUN_004c4930(u32 param_1,long param_2,u64 param_3,u32 param_4)

{
  int *piVar1;
  bool bVar2;
  u32 *puVar3;
  long lVar4;
  u32 *puVar5;
  int iVar6;
  u32 uStack_8;
  u32 uStack_4;
  
  bVar2 = false;
  iVar6 = (int)param_3;
  do {
    lVar4 = FUN_004c6f30(*(u32 *)((int)(&DAT_0096007c) + (int)(DAT_007ce8f0)),iVar6 + 0x18);
    puVar5 = (u32 *)param_2;
    if (lVar4 != 0) {
      puVar3 = (u32 *)lVar4;
      *puVar3 = **(u32 **)((int)&DAT_00960094 + DAT_007ce8f0);
      puVar3[1] = *(u32 *)((int)&DAT_00960094 + DAT_007ce8f0);
      *(u32 **)(**(int **)((int)&DAT_00960094 + DAT_007ce8f0) + 4) = puVar3;
      *(u32 *)((int)&DAT_00960094 + (int)(DAT_007ce8f0)) = (u32)puVar3;
      puVar3[3] = param_1;
      puVar3[2] = iVar6;
      puVar3[4] = (u32)(puVar5);
      puVar3[5] = param_4;
      *(int *)((int)&DAT_00960074 + DAT_007ce8f0) =
           *(int *)((int)&DAT_00960074 + DAT_007ce8f0) + iVar6;
      if (param_2 == 0) {
        return lVar4;
      }
      *puVar5 = (u32)(puVar3);
      return lVar4;
    }
    piVar1 = (int *)(*(int **)((int)&DAT_00960090 + DAT_007ce8f0))[1];
    if (piVar1 == *(int **)((int)&DAT_00960090 + DAT_007ce8f0)) {
      piVar1 = (int *)(*(int **)((int)&DAT_00960094 + DAT_007ce8f0))[1];
      if (piVar1 == *(int **)((int)&DAT_00960094 + DAT_007ce8f0)) {
        bVar2 = true;
      }
      else {
        *(int *)((int)&DAT_00960078 + DAT_007ce8f0) =
             *(int *)((int)&DAT_00960078 + DAT_007ce8f0) + piVar1[2];
        if ((code *)piVar1[5] != (code *)0x0) {
          (*(code *)piVar1[5])(piVar1);
        }
        if ((u32 *)piVar1[4] != (u32 *)0x0) {
          *(u32 *)piVar1[4] = 0;
        }
        if (*piVar1 == 0) {
          (*DAT_0096017c)(piVar1);
        }
        else {
          *(int *)piVar1[1] = *piVar1;
          *(int *)(*piVar1 + 4) = piVar1[1];
          *(int *)((int)&DAT_00960074 + DAT_007ce8f0) =
               *(int *)((int)&DAT_00960074 + DAT_007ce8f0) - piVar1[2];
          FUN_004c6e60((int)piVar1);
        }
      }
    }
    else {
      if ((code *)piVar1[5] != (code *)0x0) {
        (*(code *)piVar1[5])(piVar1);
      }
      if ((u32 *)piVar1[4] != (u32 *)0x0) {
        *(u32 *)piVar1[4] = 0;
      }
      if (*piVar1 == 0) {
        (*DAT_0096017c)(piVar1);
      }
      else {
        *(int *)piVar1[1] = *piVar1;
        *(int *)(*piVar1 + 4) = piVar1[1];
        *(int *)((int)&DAT_00960074 + DAT_007ce8f0) =
             *(int *)((int)&DAT_00960074 + DAT_007ce8f0) - piVar1[2];
        FUN_004c6e60((int)piVar1);
      }
    }
  } while (!bVar2);
  if (param_2 != 0) {
    *puVar5 = 0;
  }
  uStack_8 = 1;
  uStack_4 = ((code)FUN_004c1d10)(0xc,param_3);
  FUN_004c1c50((u64)(unsigned int)(&uStack_8));
  return 0;
}
// FUN_004C4C00 NONMATCHING
u32 FUN_004c4c00(u64 param_1)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  u32 *puVar4;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar1 = (int)(DAT_007ce8f0);
  if (DAT_007ce8f4 == 0) {
    uVar2 = 1;
    DAT_00960198 = (int)param_1;
  }
  else {
    puVar4 = (u32 *)((int)&DAT_00960070 + DAT_007ce8f0);
    *puVar4 = (int)param_1;
    FUN_004c4d70();
    ((code)FUN_004c6e50)(*(u32 *)(&DAT_0096007c + iVar1));
    (*DAT_0096017c)(*(u32 *)(&DAT_0096007c + iVar1));
    uVar2 = (*DAT_00960178)(param_1,0x3040b);
    *(u32 *)(&DAT_0096007c + iVar1) = uVar2;
    if (*(int *)(&DAT_0096007c + iVar1) == 0) {
      uStack_8 = 1;
      *puVar4 = 0;
      uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,param_1);
      FUN_004c1c50((u64)(unsigned int)(&uStack_8));
      uVar2 = 0;
    }
    else {
      lVar3 = (long)(unsigned int)FUN_004c6df0((u32 *)(unsigned int)(*(int *)((int)&DAT_0096007c + (int)iVar1)),param_1);
      if (lVar3 == 0) {
        (*DAT_0096017c)(*(u32 *)(&DAT_0096007c + iVar1));
        uStack_10 = 1;
        uStack_c = ((code)FUN_004c1d10)(0xc,0);
        FUN_004c1c50((u64)(unsigned int)(&uStack_10));
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}
// FUN_004C4D20 NONMATCHING
int FUN_004c4d20(void)

{
  u32 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)((int)&DAT_00960078 + DAT_007ce8f0);
  for (puVar1 = (u32 *)**(u32 **)((int)&DAT_00960094 + DAT_007ce8f0);
      puVar1 != *(u32 **)((int)&DAT_00960094 + DAT_007ce8f0); puVar1 = (u32 *)*puVar1)
  {
    iVar2 = iVar2 + puVar1[2];
  }
  return iVar2;
}
// FUN_004C4D70 NONMATCHING
u32 FUN_004c4d70(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  **(u32 **)((int)(&DAT_00960084) + (int)(DAT_007ce8f0)) =
       *(u32 *)((int)&DAT_00960088 + DAT_007ce8f0);
  piVar4 = (int *)((int)&DAT_00960088 + DAT_007ce8f0);
  piVar2 = *(int **)((int)&DAT_00960080 + DAT_007ce8f0);
  iVar3 = (int)(DAT_007ce8f0);
  while (DAT_007ce8f0 = (u32 *)iVar3, piVar2 != piVar4) {
    piVar1 = (int *)*piVar2;
    if ((code *)piVar2[5] != (code *)0x0) {
      (*(code *)piVar2[5])(piVar2);
    }
    if ((u32 *)piVar2[4] != (u32 *)0x0) {
      *(u32 *)piVar2[4] = 0;
    }
    if (*piVar2 == 0) {
      (*DAT_0096017c)(piVar2);
      piVar2 = piVar1;
      iVar3 = (int)(DAT_007ce8f0);
    }
    else {
      *(int *)piVar2[1] = *piVar2;
      *(int *)(*piVar2 + 4) = piVar2[1];
      *(int *)((int)&DAT_00960074 + DAT_007ce8f0) =
           *(int *)((int)&DAT_00960074 + DAT_007ce8f0) - piVar2[2];
      FUN_004c6e60((int)piVar2);
      piVar2 = piVar1;
      iVar3 = (int)(DAT_007ce8f0);
    }
  }
  *(int *)((int)&DAT_00960080 + iVar3) = (int)&DAT_00960080 + iVar3;
  *(int *)(&DAT_00960084 + iVar3) = (int)&DAT_00960080 + iVar3;
  *(int *)((int)&DAT_00960088 + iVar3) = (int)&DAT_00960088 + iVar3;
  *(int *)((int)&DAT_0096008c + iVar3) = (int)&DAT_00960088 + iVar3;
  *(u32 *)((int)&DAT_00960078 + iVar3) = 0;
  return 1;
}
// FUN_004C4EB0 NONMATCHING
u64 FUN_004c4eb0(u64 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  DAT_007ce8f8 = (u32 *)(param_2);
  iVar1 = thunk_FUN_004c3970(0x24,DAT_007cdd3c,4,DAT_007cdd40,0x95ffb0,0x40404);
  piVar2 = (int *)((int)&DAT_00960070 + DAT_007ce8f8);
  *piVar2 = iVar1;
  if (*piVar2 == 0) {
    param_1 = 0;
  }
  else {
    DAT_007ce8fc = DAT_007ce8fc + 1;
  }
  return param_1;
}
// FUN_004C4F30 NONMATCHING
u64 FUN_004c4f30(u64 param_1)

{
  if (*(int *)((int)&DAT_00960070 + DAT_007ce8f8) != 0) {
    FUN_004c3c30(0);
  }
  DAT_007ce8fc = DAT_007ce8fc + -1;
  return param_1;
}
// FUN_004C4F90 NONMATCHING
u64 FUN_004c4f90(u64 param_1,long param_2,u64 param_3)

{
  long lVar1;
  u64 uVar2;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  uVar2 = 0;
  lVar1 = 0;
  if (param_2 == 3) {
    lVar1 = FUN_004c0240(param_3,0x7cdd4c);
  }
  else if (param_2 == 2) {
    lVar1 = FUN_004c0240(param_3,0x7cdd48);
  }
  else if (param_2 == 1) {
    lVar1 = FUN_004c0240(param_3,0x7cdd44);
  }
  else {
    uStack_8 = 1;
    uStack_4 = FUN_004c1d10(0xd);
    FUN_004c1c50((u64)(unsigned int)(&uStack_8));
  }
  if (lVar1 == 0) {
    uStack_10 = 1;
    uStack_c = ((code)FUN_004c1d10)(0xffffffff80000002,param_3);
    FUN_004c1c50((u64)(unsigned int)(&uStack_10));
  }
  else {
    *(int *)((int)param_1 + 0xc) = (int)lVar1;
    uVar2 = param_1;
  }
  return uVar2;
}
// FUN_004C5090 NONMATCHING
u64 FUN_004c5090(u64 param_1,long param_2,u32 *param_3)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar3 = (int)param_1;
  if (param_2 == 3) {
    uVar1 = param_3[1];
    uVar2 = *param_3;
    *(u32 *)(iVar3 + 0xc) = uVar1;
    *(u32 *)(iVar3 + 0x10) = uVar1;
    *(u32 *)(iVar3 + 0x14) = uVar2;
  }
  else if (param_2 == 2) {
    *(u32 *)(iVar3 + 0xc) = 0;
    *(u32 *)(iVar3 + 0x10) = 0;
    *(u32 *)(iVar3 + 0x14) = 0;
  }
  else if (param_2 == 1) {
    uVar1 = param_3[1];
    uVar2 = *param_3;
    *(u32 *)(iVar3 + 0xc) = 0;
    *(u32 *)(iVar3 + 0x10) = uVar1;
    *(u32 *)(iVar3 + 0x14) = uVar2;
  }
  else {
    uStack_8 = 1;
    uStack_4 = FUN_004c1d10(0xd);
    FUN_004c1c50((u64)(unsigned int)(&uStack_8));
    param_1 = 0;
  }
  return param_1;
}
// FUN_004C5140 NONMATCHING
long FUN_004c5140(long param_1,u32 param_2,long param_3,u64 param_4,u64 param_5
                 )

{
  long lVar1;
  long lVar2;
  u32 *puVar3;
  u32 uStack_8;
  u32 uStack_4;
  
  if (param_1 == 0) {
    lVar2 = 0;
  }
  else {
    puVar3 = (u32 *)param_1;
    *puVar3 = (int)param_3;
    puVar3[1] = (int)param_4;
    puVar3[8] = param_2;
    if (param_3 == 4) {
      FUN_00521250(puVar3 + 3,param_5,0x14);
      lVar2 = param_1;
    }
    else if (param_3 == 3) {
      lVar2 = (long)(unsigned int)FUN_004c5090(param_1,param_4,(u32 *)(unsigned int)param_5);
    }
    else if (param_3 == 2) {
      lVar2 = FUN_004c4f90(param_1,param_4,param_5);
    }
    else {
      lVar2 = 0;
      if (param_3 == 1) {
        lVar1 = FUN_004c0820(param_5);
        if (lVar1 != -1) {
          puVar3[3] = (int)param_5;
          lVar2 = param_1;
        }
      }
      else {
        uStack_8 = 1;
        uStack_4 = FUN_004c1d10(0xe);
        FUN_004c1c50((u64)(unsigned int)(&uStack_8));
      }
    }
  }
  return lVar2;
}
// FUN_004C5250 NONMATCHING
u32 FUN_004c5250(int *param_1,u64 param_2,u32 param_3)

{
  u32 uVar1;
  long lVar2;
  int iVar3;
  int *piVar4;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  long extraout_t0_lo;
  
  iVar3 = *param_1;
  if (iVar3 == 4) {
    uVar1 = (*(code *)param_1[4])(param_1[7]);
  }
  else if (iVar3 == 3) {
    uVar1 = param_1[4] - param_1[3];
    piVar4 = param_1 + 3;
    if (uVar1 < param_3) {
      uStack_18 = 1;
      uStack_14 = FUN_004c1d10(5);
      FUN_004c1c50((u64)(unsigned int)(&uStack_18));
      iVar3 = param_1[5];
    }
    else {
      iVar3 = param_1[5];
      uVar1 = param_3;
    }
    FUN_00521250(param_2,iVar3 + *piVar4,uVar1);
    *piVar4 = *piVar4 + uVar1;
  }
  else if ((iVar3 == 1) || (iVar3 == 2)) {
    iVar3 = param_1[3];
    uVar1 = FUN_004c03d0(param_2,1,param_3,iVar3);
    if (uVar1 != param_3) {
      FUN_004c06b0(iVar3); lVar2 = extraout_t0_lo;
      if (lVar2 == 0) {
        uStack_10 = 1;
        uStack_c = FUN_004c1d10(0xffffffff8000001a);
        FUN_004c1c50((u64)(unsigned int)(&uStack_10));
      }
      else {
        uStack_8 = 1;
        uStack_4 = FUN_004c1d10(5);
        FUN_004c1c50((u64)(unsigned int)(&uStack_8));
      }
    }
  }
  else {
    uStack_20 = 1;
    uStack_1c = FUN_004c1d10(0xe);
    FUN_004c1c50((u64)(unsigned int)(&uStack_20));
    uVar1 = 0;
  }
  return uVar1;
}
// FUN_004C53F0 NONMATCHING
u64 FUN_004c53f0(u64 param_1,u64 param_2,u32 param_3)

{
  u32 uVar1;
  long lVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  piVar3 = (int *)param_1;
  iVar4 = *piVar3;
  if (iVar4 == 4) {
    lVar2 = (*(code *)piVar3[5])(piVar3[7]);
    if (lVar2 == 0) {
      param_1 = 0;
    }
  }
  else if (iVar4 == 3) {
    piVar5 = piVar3 + 3;
    if (piVar3[5] == 0) {
      iVar4 = (*DAT_00960178)(0x200,0x30404);
      piVar3[5] = iVar4;
      if (piVar3[5] == 0) {
        uStack_10 = 1;
        uStack_c = ((code)FUN_004c1d10)(0xffffffff80000013,0x200);
        FUN_004c1c50((u64)(unsigned int)(&uStack_10));
        return 0;
      }
      piVar3[4] = 0x200;
    }
    iVar4 = piVar3[4];
    if ((u32)(iVar4 - *piVar5) < param_3) {
      if (param_3 < 0x200) {
        iVar4 = iVar4 + 0x200;
      }
      else {
        iVar4 = param_3 + iVar4;
      }
      lVar2 = (*DAT_00960180)(piVar3[5],iVar4,0x1030404);
      if (lVar2 == 0) {
        uStack_18 = 1;
        uStack_14 = ((code)FUN_004c1d10)(0xffffffff80000013,iVar4 - piVar3[4]);
        FUN_004c1c50((u64)(unsigned int)(&uStack_18));
        return 0;
      }
      piVar3[5] = (int)lVar2;
      piVar3[4] = iVar4;
    }
    FUN_00521250(piVar3[5] + *piVar5,param_2,param_3);
    *piVar5 = *piVar5 + param_3;
  }
  else if ((iVar4 == 1) || (iVar4 == 2)) {
    uVar1 = FUN_004c0420(param_2,1,param_3,piVar3[3]);
    if (uVar1 != param_3) {
      uStack_8 = 1;
      uStack_4 = FUN_004c1d10(0xffffffff8000001c);
      FUN_004c1c50((u64)(unsigned int)(&uStack_8));
      param_1 = 0;
    }
  }
  else {
    uStack_20 = 1;
    uStack_1c = FUN_004c1d10(0xe);
    FUN_004c1c50((u64)(unsigned int)(&uStack_20));
    param_1 = 0;
  }
  return param_1;
}
// FUN_004C5620 NONMATCHING
u64 FUN_004c5620(u64 param_1,u32 param_2)

{
  int iVar1;
  long lVar2;
  u32 *puVar3;
  int *piVar4;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  long extraout_t0_lo;
  
  if (param_2 != 0) {
    piVar4 = (int *)param_1;
    iVar1 = *piVar4;
    if (iVar1 == 4) {
      lVar2 = (*(code *)piVar4[6])(piVar4[7]);
      if (lVar2 == 0) {
        param_1 = 0;
      }
    }
    else if (iVar1 == 3) {
      puVar3 = (u32 *)(piVar4 + 3);
      if ((u32)piVar4[4] < (u32)(piVar4[3] + (int)param_2)) {
        *puVar3 = piVar4[4];
        uStack_10 = 1;
        uStack_c = FUN_004c1d10(5);
        FUN_004c1c50((u64)(unsigned int)(&uStack_10));
        param_1 = 0;
      }
      else {
        *puVar3 = *puVar3 + (int)param_2;
      }
    }
    else if ((iVar1 == 1) || (iVar1 == 2)) {
      iVar1 = piVar4[3];
      lVar2 = FUN_004c0470(iVar1,param_2 & 0xffffffff,1);
      if (lVar2 != 0) {
        FUN_004c06b0(iVar1); lVar2 = extraout_t0_lo;
        if (lVar2 != 0) {
          uStack_8 = 1;
          uStack_4 = FUN_004c1d10(5);
          FUN_004c1c50((u64)(unsigned int)(&uStack_8));
        }
        param_1 = 0;
      }
    }
    else {
      uStack_18 = 1;
      uStack_14 = FUN_004c1d10(0xe);
      FUN_004c1c50((u64)(unsigned int)(&uStack_18));
      param_1 = 0;
    }
  }
  return param_1;
}
// FUN_004C5780 NONMATCHING
bool FUN_004c5780(u64 param_1,long param_2)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  bool bVar4;
  u32 uStack_8;
  u32 uStack_4;
  
  piVar3 = (int *)param_1;
  iVar1 = *piVar3;
  if (iVar1 == 4) {
    if ((code *)piVar3[3] != (code *)0x0) {
      (*(code *)piVar3[3])(piVar3[7]);
    }
    bVar4 = true;
  }
  else if (iVar1 == 3) {
    if ((piVar3[1] != 1) && (param_2 != 0)) {
      *(int *)param_2 = piVar3[5];
      ((int *)param_2)[1] = piVar3[3];
    }
    bVar4 = true;
  }
  else if (iVar1 == 2) {
    lVar2 = FUN_004c0370(piVar3[3]);
    bVar4 = lVar2 == 0;
  }
  else {
    bVar4 = true;
    if (iVar1 != 1) {
      uStack_8 = 1;
      uStack_4 = FUN_004c1d10(0xe);
      FUN_004c1c50((u64)(unsigned int)(&uStack_8));
      return false;
    }
  }
  if (piVar3[8] != 0) {
    (*DAT_0096018c)(*(u32 *)((int)&DAT_00960070 + DAT_007ce8f8),param_1);
  }
  return bVar4;
}
// FUN_004C58A0 NONMATCHING
u64 FUN_004c58a0(u64 param_1,u64 param_2,u64 param_3)

{
  u64 uVar1;
  long lVar2;
  
  uVar1 = (*DAT_00960188)(*(u32 *)((int)&DAT_00960070 + DAT_007ce8f8),0x30404);
  lVar2 = FUN_004c5140(uVar1,1,param_1,param_2,param_3);
  if (lVar2 == 0) {
    (*DAT_0096018c)(*(u32 *)((int)&DAT_00960070 + DAT_007ce8f8),uVar1);
    uVar1 = 0;
  }
  return uVar1;
}
// FUN_004C5960 NONMATCHING
u32
FUN_004c5960(int param_1,int param_2,u32 param_3,u32 param_4,u32 param_5)

{
  u32 *puVar1;
  u32 uVar2;
  
  puVar1 = *(u32 **)(param_1 + 0x10);
  if (puVar1 != (u32 *)0x0) {
    do {
      if (puVar1[2] == param_2) {
        break;
      }
      puVar1 = (u32 *)puVar1[0xc];
    } while (puVar1 != (u32 *)0x0);
  }
  if (puVar1 != (u32 *)0x0) {
    puVar1[3] = param_3;
    puVar1[4] = param_4;
    puVar1[5] = param_5;
    uVar2 = *puVar1;
  } else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}
// FUN_004C59B0 NONMATCHING
u32 FUN_004c59b0(int param_1,int param_2,u32 param_3)
{
  u32 *puVar1;
  u32 uVar2;
  
  puVar1 = *(u32 **)(param_1 + 0x10);
  if (puVar1 == (u32 *)0x0) {
    goto check;
  }
loop:
  if (puVar1[2] == param_2) {
    goto check;
  }
  puVar1 = (u32 *)puVar1[0xc];
  if (puVar1 != (u32 *)0x0) {
    goto loop;
  }
check:
  if (puVar1 != (u32 *)0x0) {
    puVar1[6] = param_3;
    uVar2 = *puVar1;
  } else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}
// FUN_004C5A00 NONMATCHING
u32 FUN_004c5a00(int param_1,int param_2,u32 param_3)

{
  u32 *puVar1;
  u32 uVar2;
  
  puVar1 = *(u32 **)(param_1 + 0x10);
  if (puVar1 != (u32 *)0x0) {
    do {
      if (puVar1[2] == param_2) {
        break;
      }
      puVar1 = (u32 *)puVar1[0xc];
    } while (puVar1 != (u32 *)0x0);
  }
  if (puVar1 != (u32 *)0x0) {
    puVar1[7] = param_3;
    uVar2 = *puVar1;
  } else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}
// FUN_004C5A50 NONMATCHING
u64 FUN_004c5a50(u64 param_1,u64 param_2,u64 param_3)

{
  u32 *puVar1;
  long lVar2;
  int iVar3;
  u32 uStack_18;
  u32 uStack_14;
  int iStack_10;
  int iStack_c;
  u32 uStack_8;
  int iStack_4;
  
  lVar2 = (long)(FUN_004c1600(param_2,3,(u64)(unsigned int)(&iStack_4),(u64)(unsigned int)(&uStack_8)));
  if (lVar2 == 0) {
    param_1 = 0;
  }
  else if ((uStack_8 < 0x35000) || (0x37002 < uStack_8)) {
    uStack_18 = 1;
    uStack_14 = FUN_004c1d10(0xffffffff80000004);
    FUN_004c1c50((u64)(unsigned int)(&uStack_18));
    param_1 = 0;
  }
  else {
    iVar3 = (int)param_1;
    if (iStack_4 == 0) {
      puVar1 = *(u32 **)(iVar3 + 0x10);
    }
    else {
      do {
        lVar2 = (long)(FUN_004c1450(param_2,(u64)(unsigned int)(&iStack_c),(u64)(unsigned int)(&iStack_10),0,0));
        if (lVar2 == 0) {
          return 0;
        }
        for (puVar1 = *(u32 **)(iVar3 + 0x10);
            (puVar1 != (u32 *)0x0 && (puVar1[2] != iStack_c));
            puVar1 = (u32 *)puVar1[0xc]) {
        }
        if ((puVar1 == (u32 *)0x0) || ((code *)puVar1[3] == (code *)0x0)) {
          lVar2 = FUN_004c5620(param_2,iStack_10);
          if (lVar2 == 0) {
            return 0;
          }
        }
        else {
          lVar2 = (*(code *)puVar1[3])(param_2,iStack_10,param_3,*puVar1,puVar1[1]);
          if (lVar2 == 0) {
            return 0;
          }
        }
        iStack_4 = iStack_4 - (iStack_10 + 0xc);
      } while (iStack_4 != 0);
      puVar1 = *(u32 **)(iVar3 + 0x10);
      iStack_4 = 0;
    }
    for (; puVar1 != (u32 *)0x0; puVar1 = (u32 *)puVar1[0xc]) {
      if (((code *)puVar1[6] != (code *)0x0) &&
         (lVar2 = (*(code *)puVar1[6])(param_3,*puVar1,puVar1[1]), lVar2 == 0)) {
        return 0;
      }
    }
  }
  return param_1;
}
// FUN_004C5C30 NONMATCHING
u64 FUN_004c5c30(u64 param_1,int param_2,u64 param_3)

{
  u32 *puVar1;
  long lVar2;
  
  for (puVar1 = *(u32 **)((int)param_1 + 0x10);
      (puVar1 != (u32 *)0x0 && (puVar1[2] != param_2)); puVar1 = (u32 *)puVar1[0xc]) {
  }
  if ((puVar1 == (u32 *)0x0) || ((code *)puVar1[7] == (code *)0x0)) {
    param_1 = 0;
  }
  else {
    lVar2 = (*(code *)puVar1[7])(param_3,*puVar1,puVar1[1]);
    if (lVar2 == 0) {
      param_1 = 0;
    }
  }
  return param_1;
}
// FUN_004C5CB0 NONMATCHING
int FUN_004c5cb0(int param_1,u64 param_2)

{
  u32 *puVar1;
  long lVar2;
  int iVar3;
  
  iVar3 = 0;
  for (puVar1 = *(u32 **)(param_1 + 0x10); puVar1 != (u32 *)0x0;
      puVar1 = (u32 *)puVar1[0xc]) {
    if (((code *)puVar1[5] != (code *)0x0) &&
       (lVar2 = (*(code *)puVar1[5])(param_2,*puVar1,puVar1[1]), 0 < lVar2)) {
      iVar3 = iVar3 + (int)lVar2 + 0xc;
    }
  }
  return iVar3;
}
// FUN_004C5D30 NONMATCHING
u64 FUN_004c5d30(u64 param_1,u64 param_2,u64 param_3)

{
  u32 *puVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  
  iVar4 = 0;
  for (puVar1 = *(u32 **)((int)param_1 + 0x10); puVar1 != (u32 *)0x0;
      puVar1 = (u32 *)puVar1[0xc]) {
    if (((code *)puVar1[5] != (code *)0x0) &&
       (lVar2 = (*(code *)puVar1[5])(param_3,*puVar1,puVar1[1]), 0 < lVar2)) {
      iVar4 = iVar4 + (int)lVar2 + 0xc;
    }
  }
  lVar2 = FUN_004c15a0(param_2,3,iVar4,0x37002,0x37);
  if (lVar2 == 0) {
    param_1 = 0;
  }
  else {
    for (puVar1 = *(u32 **)((int)param_1 + 0x10); puVar1 != (u32 *)0x0;
        puVar1 = (u32 *)puVar1[0xc]) {
      if ((((code *)puVar1[5] != (code *)0x0) && (puVar1[4] != 0)) &&
         (lVar2 = (*(code *)puVar1[5])(param_3,*puVar1,puVar1[1]), 0 < lVar2)) {
        lVar3 = FUN_004c15a0(param_2,puVar1[2],lVar2,0x37002,0x37);
        if (lVar3 == 0) {
          return 0;
        }
        lVar2 = (*(code *)puVar1[4])(param_2,lVar2,param_3,*puVar1,puVar1[1]);
        if (lVar2 == 0) {
          return 0;
        }
      }
    }
  }
  return param_1;
}
// FUN_004C5EA0 NONMATCHING
u64 FUN_004c5ea0(u64 param_1,u64 param_2)

{
  long lVar1;
  int iStack_8;
  int iStack_4;
  
  lVar1 = (long)(FUN_004c1600(param_2,3,(u64)(unsigned int)(&iStack_4),0));
  if (lVar1 == 0) {
    param_1 = 0;
  }
  else {
    for (; iStack_4 != 0; iStack_4 = iStack_4 - (iStack_8 + 0xc)) {
      lVar1 = (long)(FUN_004c1450(param_2,0,(u64)(unsigned int)(&iStack_8),0,0));
      if (lVar1 == 0) {
        return 0;
      }
      lVar1 = FUN_004c5620(param_2,iStack_8);
      if (lVar1 == 0) {
        return 0;
      }
    }
  }
  return param_1;
}
// FUN_004C5F70 NONMATCHING
bool FUN_004c5f70(void)

{
  long lVar1;
  
  lVar1 = thunk_FUN_004c3970(0x3c,DAT_007cdd50,4,DAT_007cdd54,0x95ffe0,0x40000);
  DAT_007ce908 = (u32 *)((int)lVar1);
  if (lVar1 != 0) {
    DAT_007ce904 = 0;
  }
  return lVar1 != 0;
}
// FUN_004C5FC0 NONMATCHING
u64 FUN_004c5fc0(u64 param_1,u64 param_2)
{
  u32 *puVar1;
  
  puVar1 = *(u32 **)((int)param_1 + 0x38);
  if (puVar1[4] != 0) {
    puVar1[0] = puVar1[1];
    puVar1[4] = 0;
    puVar1[5] = 0;
  }
  return (*DAT_0096018c)(param_2,param_1);
}
// FUN_004C6000 NONMATCHING
u32 FUN_004c6000(void)

{
  int iVar1;
  int iVar2;
  u32 *puVar3;
  u32 uVar4;
  
  if (DAT_007ce908 != 0) {
    FUN_004c4200((int)DAT_007ce908,(code *)0x4c5fc0,(int)DAT_007ce908);
    if (DAT_00960188 != (code *)FUN_004c3d10) {
      uVar4 = 0;
      if (DAT_007ce904 != 0) {
        iVar2 = 0;
        do {
          iVar1 = *(int *)(*(int *)(DAT_007ce900 + iVar2) + 0x10);
          puVar3 = (u32 *)0x0;
          if (iVar1 != 0) {
            puVar3 = *(u32 **)(iVar1 + 0x38);
            do {
              iVar1 = *(int *)(iVar1 + 0x30);
              (*DAT_0096018c)(0);
            } while (iVar1 != 0);
          }
          if ((puVar3 != (u32 *)0x0) && (puVar3[4] != 0)) {
            *puVar3 = puVar3[1];
            puVar3[4] = 0;
            puVar3[5] = 0;
          }
          uVar4 = uVar4 + 1;
          iVar2 = iVar2 + 4;
        } while (uVar4 < DAT_007ce904);
      }
      if (DAT_007ce900 != 0) {
        (*DAT_0096017c)();
        DAT_007ce900 = 0;
      }
    }
    FUN_004c3c30((int)DAT_007ce908);
    DAT_007ce908 = 0;
  }
  return 1;
}
// FUN_004C6170 NONMATCHING
u32 FUN_004c6170(int param_1,int param_2)
{
  u32 *puVar1;
  
  puVar1 = *(u32 **)(param_1 + 0x10);
  if (puVar1 != (u32 *)0x0) {
    do {
      if (puVar1[2] == param_2) {
        return *puVar1;
      }
      puVar1 = (u32 *)puVar1[0xc];
    } while (puVar1 != (u32 *)0x0);
  }
  return 0xffffffff;
}
// FUN_004C61B0 NONMATCHING
int FUN_004c61b0(int *param_1,int param_2,int param_3,long param_4,long param_5,long param_6)

{
  int *piVar1;
  int *piVar2;
  long lVar3;
  int *piVar4;
  int iVar5;
  u32 uVar6;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  if (DAT_007ce908 == 0) {
    iVar5 = -1;
  }
  else {
    lVar3 = FUN_004ca500();
    if (lVar3 == 0) {
      if (DAT_00960188 != (code *)FUN_004c3d10) {
        uVar6 = 0;
        piVar1 = (int *)(DAT_007ce900);
        if (DAT_007ce904 != 0) {
          do {
            if (param_1 == (int *)*piVar1) break;
            uVar6 = uVar6 + 1;
            piVar1 = piVar1 + 1;
          } while (uVar6 < DAT_007ce904);
        }
        if (DAT_007ce904 == uVar6) {
          piVar1 = (int *)(*DAT_00960178)((DAT_007ce904 + 1) * 4,0x40000);
          uVar6 = 0;
          if (DAT_007ce900 != 0) {
            if (DAT_007ce904 != 0) {
              iVar5 = 0;
              piVar4 = piVar1;
              do {
                uVar6 = uVar6 + 1;
                piVar2 = (int *)((int)DAT_007ce900 + iVar5);
                iVar5 = iVar5 + 4;
                *piVar4 = *piVar2;
                piVar4 = piVar4 + 1;
              } while (uVar6 < DAT_007ce904);
            }
            (*DAT_0096017c)(DAT_007ce900);
          }
          piVar1[uVar6] = (int)param_1;
          DAT_007ce904 = DAT_007ce904 + 1;
          DAT_007ce900 = (u32 *)((u32)(piVar1));
        }
      }
      for (piVar1 = (int *)param_1[4]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0xc]) {
        if (piVar1[2] == param_3) {
          uStack_10 = 1;
          uStack_c = FUN_004c1d10(0xffffffff80000017);
          FUN_004c1c50((u64)(unsigned int)(&uStack_10));
          return *piVar1;
        }
      }
      iVar5 = *param_1 + (param_2 + 3U & 0xfffffffc);
      if ((param_1[2] == 0) || (iVar5 <= param_1[2])) {
        lVar3 = (*DAT_00960188)(DAT_007ce908,0x40000);
        if (lVar3 == 0) {
          iVar5 = -1;
        }
        else {
          piVar1 = (int *)lVar3;
          *piVar1 = *param_1;
          *param_1 = iVar5;
          piVar1[1] = param_2;
          piVar1[2] = param_3;
          piVar1[3] = 0;
          piVar1[4] = 0;
          piVar1[5] = 0;
          piVar1[6] = 0;
          piVar1[7] = 0;
          if (param_4 == 0) {
            piVar1[8] = (int)&LAB_004c6140;
          }
          else {
            piVar1[8] = (int)param_4;
          }
          if (param_5 == 0) {
            piVar1[9] = (int)&LAB_004c6150;
          }
          else {
            piVar1[9] = (int)param_5;
          }
          if (param_6 == 0) {
            piVar1[10] = (int)&LAB_004c6160;
          }
          else {
            piVar1[10] = (int)param_6;
          }
          piVar1[0xb] = 0;
          piVar1[0xc] = 0;
          piVar1[0xd] = 0;
          piVar1[0xe] = (int)param_1;
          if (param_1[4] == 0) {
            param_1[4] = (int)piVar1;
            param_1[5] = (int)piVar1;
          }
          else {
            *(int **)(param_1[5] + 0x30) = piVar1;
            piVar1[0xd] = param_1[5];
            param_1[5] = (int)piVar1;
          }
          iVar5 = *piVar1;
        }
      }
      else {
        iVar5 = -1;
      }
    }
    else {
      uStack_8 = 1;
      uStack_4 = FUN_004c1d10(0xffffffff80000017);
      FUN_004c1c50((u64)(unsigned int)(&uStack_8));
      iVar5 = -1;
    }
  }
  return iVar5;
}
// FUN_004C64B0 NONMATCHING
u64 FUN_004c64b0(u64 param_1,u64 param_2)

{
  long lVar1;
  u32 *puVar2;
  
  puVar2 = *(u32 **)((int)param_1 + 0x10);
  while( true ) {
    if (puVar2 == (u32 *)0x0) {
      return param_1;
    }
    lVar1 = (*(code *)puVar2[8])(param_2,*puVar2,puVar2[1]);
    if (lVar1 == 0) break;
    puVar2 = (u32 *)puVar2[0xc];
  }
  puVar2 = (u32 *)puVar2[0xd];
  if (puVar2 != (u32 *)0x0) {
    do {
      (*(code *)puVar2[9])(param_2,*puVar2,puVar2[1]);
      puVar2 = (u32 *)puVar2[0xd];
    } while (puVar2 != (u32 *)0x0);
    return 0;
  }
  return 0;
}
// FUN_004C6560 NONMATCHING
u64 FUN_004c6560(u64 param_1,u64 param_2)

{
  u32 *puVar1;
  
  for (puVar1 = *(u32 **)((int)param_1 + 0x14); puVar1 != (u32 *)0x0;
      puVar1 = (u32 *)puVar1[0xd]) {
    (*(code *)puVar1[9])(param_2,*puVar1,puVar1[1]);
  }
  return param_1;
}
#pragma optimization_level 3
// FUN_004C65D0 NONMATCHING
u64 FUN_004c65d0(u32 *param_1, u32 *param_2, u32 *param_3)
{
    u32 *node;

    for (node = (u32 *)param_1[4]; node != (u32 *)0; node = (u32 *)node[0xc]) {
        ((code)node[10])(param_2, param_3, node[0], node[1]);
    }
    return (u64)param_1;
}
// FUN_004C6640 NONMATCHING
RwV3d* FUN_004c6640(RwV3d *out, const RwV3d *in, int count, const RwMatrix *matrix)
{
    RwV3d *result = out;
    RwReal rightX;
    RwReal rightY;
    RwReal rightZ;
    RwReal upX;
    RwReal upY;
    RwReal upZ;
    RwReal atX;
    RwReal atY;
    RwReal atZ;
    RwReal posX;
    RwReal posY;
    RwReal posZ;

    count--;
    if (count < 0) {
        return result;
    }
    rightX = matrix->right.x;
    rightY = matrix->right.y;
    rightZ = matrix->right.z;
    upX = matrix->up.x;
    upY = matrix->up.y;
    upZ = matrix->up.z;
    atX = matrix->at.x;
    atY = matrix->at.y;
    atZ = matrix->at.z;
    posX = matrix->pos.x;
    posY = matrix->pos.y;
    posZ = matrix->pos.z;
    do {
        RwReal x = in->x;
        RwReal y;
        RwReal z;

        count--;
        y = in->y;
        z = in->z;
        in++;
        out->x = x * rightX + y * upX + z * atX + posX;
        out->y = x * rightY + y * upY + z * atY + posY;
        out->z = x * rightZ + y * upZ + z * atZ + posZ;
        out++;
    } while (count >= 0);
    return result;
}

// FUN_004C6700 NONMATCHING
RwV3d* FUN_004c6700(RwV3d *out, const RwV3d *in, const RwMatrix *matrix)
{
    RwV3d *result = out;
    RwReal x = in->x;
    RwReal y = in->y;
    RwReal z = in->z;
    RwReal rightX = matrix->right.x;
    RwReal rightY = matrix->right.y;
    RwReal rightZ = matrix->right.z;
    RwReal upX = matrix->up.x;
    RwReal upY = matrix->up.y;
    RwReal upZ = matrix->up.z;
    RwReal atX = matrix->at.x;
    RwReal atY = matrix->at.y;
    RwReal atZ = matrix->at.z;
    RwReal posX = matrix->pos.x;
    RwReal posY = matrix->pos.y;
    RwReal posZ = matrix->pos.z;

    out->x = x * rightX + y * upX + z * atX + posX;
    out->y = x * rightY + y * upY + z * atY + posY;
    out->z = x * rightZ + y * upZ + z * atZ + posZ;
    return result;
}

// FUN_004C67A0 NONMATCHING
RwV3d* FUN_004c67a0(RwV3d *out, const RwV3d *in, int count, const RwMatrix *matrix)
{
    RwV3d *result = out;
    RwReal rightX;
    RwReal rightY;
    RwReal rightZ;
    RwReal upX;
    RwReal upY;
    RwReal upZ;
    RwReal atX;
    RwReal atY;
    RwReal atZ;

    count--;
    if (count < 0) {
        return result;
    }
    rightX = matrix->right.x;
    rightY = matrix->right.y;
    rightZ = matrix->right.z;
    upX = matrix->up.x;
    upY = matrix->up.y;
    upZ = matrix->up.z;
    atX = matrix->at.x;
    atY = matrix->at.y;
    atZ = matrix->at.z;
    do {
        RwReal x = in->x;
        RwReal y;
        RwReal z;

        count--;
        y = in->y;
        z = in->z;
        in++;
        out->x = x * rightX + y * upX + z * atX;
        out->y = x * rightY + y * upY + z * atY;
        out->z = x * rightZ + y * upZ + z * atZ;
        out++;
    } while (count >= 0);
    return result;
}

// FUN_004C6840 NONMATCHING
RwV3d* FUN_004c6840(RwV3d *out, const RwV3d *in, const RwMatrix *matrix)
{
    RwV3d *result = out;
    RwReal x = in->x;
    RwReal y = in->y;
    RwReal z = in->z;
    RwReal rightX = matrix->right.x;
    RwReal rightY = matrix->right.y;
    RwReal rightZ = matrix->right.z;
    RwReal upX = matrix->up.x;
    RwReal upY = matrix->up.y;
    RwReal upZ = matrix->up.z;
    RwReal atX = matrix->at.x;
    RwReal atY = matrix->at.y;
    RwReal atZ = matrix->at.z;

    out->x = x * rightX + y * upX + z * atX;
    out->y = x * rightY + y * upY + z * atY;
    out->z = x * rightZ + y * upZ + z * atZ;
    return result;
}




// FUN_004C68C0 NONMATCHING
u32
FUN_004c68c0(u8 *param_1,u8 *param_2,u8 *param_3,u8 *param_4)

{
  if (param_1 == (u8 *)0x0) {
    param_1 = &LAB_004c6700;
  }
  *(u8 **)((int)&DAT_00960078 + DAT_007ce910) = param_1;
  if (param_2 == (u8 *)0x0) {
    param_2 = &LAB_004c6640;
  }
  *(u8 **)(&DAT_0096007c + DAT_007ce910) = param_2;
  if (param_3 == (u8 *)0x0) {
    param_3 = &LAB_004c6840;
  }
  *(u8 **)((int)&DAT_00960080 + DAT_007ce910) = param_3;
  if (param_4 == (u8 *)0x0) {
    param_4 = &LAB_004c67a0;
  }
  *(u8 **)(&DAT_00960084 + DAT_007ce910) = param_4;
  return 1;
}
// FUN_004C6970 NONMATCHING
void FUN_004c6970(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  
  fVar2 = *param_2;
  fVar1 = SQRT(param_2[2] * param_2[2] + fVar2 * fVar2 + param_2[1] * param_2[1]);
  if (0.0 < fVar1) {
    fVar1 = 1.0 / fVar1;
  }
  *param_1 = fVar2 * fVar1;
  fVar2 = param_2[2];
  param_1[1] = param_2[1] * fVar1;
  param_1[2] = fVar2 * fVar1;
  return;
}
// FUN_004c69f0 NONMATCHING
RwReal RwV3dNormalize(RwV3d* out, const RwV3d* in)
{
    RwReal length;
    RwReal reciprocal;
    RwUInt32 error[2];

    length = sqrtf((in->z * in->z) + (in->x * in->x) + (in->y * in->y));
    reciprocal = length;
    if (0.0f < length)
    {
        reciprocal = 1.0f / length;
    }
    out->x = in->x * reciprocal;
    out->y = in->y * reciprocal;
    out->z = in->z * reciprocal;
    if (length <= 0.0f)
    {
        error[0] = 1;
        error[1] = func_004c1d10(0x19);
        func_004c1c50(error);
    }

    return length;
}

// FUN_004c6ac0
#pragma optimization_level 3
RwReal RwV3dLength(const RwV3d* in)
{
    RwReal y = in->y;
    RwReal x = in->x;
    RwReal z = in->z;

    return sqrtf((x * x) + (y * y) + (z * z));
}
#pragma optimization_level 2

// FUN_004C6AF0
#pragma optimization_level 3
#pragma schedule on
float FUN_004c6af0(float *param_1)

{
  return SQRT(*param_1 * *param_1 + param_1[1] * param_1[1]);
}
#pragma optimization_level 2
#pragma schedule off
// FUN_004C6B20 NONMATCHING
float FUN_004c6b20(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  u32 uStack_8;
  u32 uStack_4;
  
  fVar1 = *param_2;
  fVar3 = SQRT(fVar1 * fVar1 + param_2[1] * param_2[1]);
  fVar2 = fVar3;
  if (0.0 < fVar3) {
    fVar2 = 1.0 / fVar3;
  }
  *param_1 = fVar1 * fVar2;
  param_1[1] = param_2[1] * fVar2;
  if (fVar3 <= 0.0) {
    uStack_8 = 1;
    uStack_4 = FUN_004c1d10(0x19);
    FUN_004c1c50((u64)(unsigned int)(&uStack_8));
  }
  return fVar3;
}
// FUN_004C6BE0
#pragma schedule on
u64 FUN_004c6be0(u64 param_1)

{
  {
    struct FnSlot { u32 a; u32 b; code fn; };
    struct FnSlot *slot;
    slot = (struct FnSlot *)(DAT_00960070_abs + DAT_007ce910);
    slot->fn();
  }
  return param_1;
}
// FUN_004C6C20
u64 FUN_004c6c20(u64 param_1)

{
  {
    struct FnSlot { u32 a; u32 b; code f0; code f1; code f2; code f3; };
    struct FnSlot *slot;
    slot = (struct FnSlot *)(DAT_00960070_abs + DAT_007ce910);
    slot->f1();
  }
  return param_1;
}
// FUN_004C6C60
u64 FUN_004c6c60(u64 param_1)

{
  {
    struct FnSlot { u32 a; u32 b; code f0; code f1; code f2; code f3; };
    struct FnSlot *slot;
    slot = (struct FnSlot *)(DAT_00960070_abs + DAT_007ce910);
    slot->f2();
  }
  return param_1;
}
// FUN_004C6CA0
u64 FUN_004c6ca0(u64 param_1)

{
  {
    struct FnSlot { u32 a; u32 b; code f0; code f1; code f2; code f3; };
    struct FnSlot *slot;
    slot = (struct FnSlot *)(DAT_00960070_abs + DAT_007ce910);
    slot->f3();
  }
  return param_1;
}
// FUN_004C6CE0
#pragma optimization_level 3
u64 FUN_004c6ce0(u64 param_1)
{
  DAT_00960088 = DAT_00960088 - 1;
  return param_1;
}
#pragma optimization_level 2
// FUN_004C6D00 NONMATCHING
u64 FUN_004c6d00(u64 param_1,u32 param_2)
{
  DAT_00960084 = param_2;
  *(u32 *)((int)&DAT_00960070 + param_2 + 8) = (u32)&LAB_004c6700;
  *(u32 *)((int)&DAT_00960070 + param_2 + 0xc) = (u32)&LAB_004c6640;
  *(u32 *)((int)&DAT_00960070 + param_2 + 0x10) = (u32)&LAB_004c6840;
  *(u32 *)((int)&DAT_00960070 + param_2 + 0x14) = (u32)&LAB_004c67a0;
  DAT_00960088 = DAT_00960088 + 1;
  return param_1;
}
// FUN_004C6D60 NONMATCHING
void FUN_004c6d60(u32 *param_1,int param_2)

{
  int iVar1;
  u32 *puVar2;
  
  iVar1 = param_1[1];
  puVar2 = (u32 *)((int)param_1 + param_2 + 0x20);
  if ((iVar1 == 0) || ((~*(u32 *)(iVar1 + 0x10) & 1) == 0)) {
    *(int *)((int)param_1 + param_2 + 0x24) = iVar1;
    *(int *)((int)param_1 + param_2 + 0x2c) = (param_1[3] - param_2) + -0x20;
  }
  else {
    *(u32 *)((int)param_1 + param_2 + 0x24) = *(u32 *)(iVar1 + 4);
    *(int *)((int)param_1 + param_2 + 0x2c) = *(int *)(param_1[1] + 0xc) + (param_1[3] - param_2);
  }
  param_1[1] = (u32)(puVar2);
  *(u32 *)((int)param_1 + param_2 + 0x30) = 0;
  *(u32 **)((int)param_1 + param_2 + 0x28) = param_1;
  iVar1 = *(int *)((int)param_1 + param_2 + 0x24);
  if (iVar1 != 0) {
    *(u32 **)(iVar1 + 8) = puVar2;
  }
  param_1[3] = param_2;
  *puVar2 = *param_1;
  return;
}
// FUN_004C6DF0 NONMATCHING
bool FUN_004c6df0(u32 *param_1,int param_2)

{
  int *piVar2;
  int iVar1;
  
  iVar1 = ((int)param_1 + param_2) & 0xffffffe0;
  piVar2 = (int *)((int)param_1 + 0x27U);
  piVar2 = (int *)((int)piVar2 & 0xffffffe0);
  iVar1 = iVar1 - (int)piVar2 - 0x20;
  if (0x1f < iVar1) {
    *piVar2 = (int)param_1;
    piVar2[1] = 0;
    piVar2[2] = 0;
    piVar2[4] = 0;
    piVar2[3] = iVar1;
    *param_1 = (u32)(piVar2);
    param_1[1] = (u32)(piVar2);
  }
  return 0x1f < iVar1;
}
#pragma optimization_level 3
// FUN_004C6E50
u32 FUN_004c6e50(void)

{
  return 1;
}
#pragma optimization_level 2
// FUN_004C6E60 NONMATCHING
void FUN_004c6e60(int param_1)

{
  u32 uVar1;
  int iVar2;
  u32 uVar3;
  u32 uVar4;
  
  *(u32 *)(param_1 + -0x10) = 0;
  uVar4 = param_1 - 0x20;
  uVar1 = *(u32 *)(param_1 + -0x18);
  iVar2 = *(int *)(param_1 + -0x1c);
  uVar3 = *(u32 *)(*(int *)(param_1 + -0x20) + 4);
  if ((uVar3 == 0) || (uVar4 < uVar3)) {
    *(u32 *)(*(int *)(param_1 + -0x20) + 4) = uVar4;
  }
  if ((uVar1 != 0) && ((~*(u32 *)(uVar1 + 0x10) & 1) != 0)) {
    *(int *)(uVar1 + 4) = iVar2;
    if (iVar2 != 0) {
      *(u32 *)(iVar2 + 8) = uVar1;
    }
    *(int *)(uVar1 + 0xc) = *(int *)(uVar1 + 0xc) + *(int *)(param_1 + -0x14) + 0x20;
    uVar4 = uVar1;
  }
  if ((iVar2 != 0) && ((~*(u32 *)(iVar2 + 0x10) & 1) != 0)) {
    *(u32 *)(uVar4 + 4) = *(u32 *)(iVar2 + 4);
    if (*(int *)(iVar2 + 4) != 0) {
      *(u32 *)(*(int *)(iVar2 + 4) + 8) = uVar4;
    }
    *(int *)(uVar4 + 0xc) = *(int *)(uVar4 + 0xc) + *(int *)(iVar2 + 0xc) + 0x20;
  }
  return;
}
// FUN_004C6F30 NONMATCHING
int FUN_004c6f30(int param_1,int param_2)

{
  u32 uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long extraout_a0;
  int extraout_t0_lo;
  
  iVar2 = *(int *)(param_1 + 4);
  uVar1 = param_2 + 0x1fU & 0xffffffe0;
  lVar4 = 0;
  while (((long)iVar2 != 0 && (lVar4 == 0))) {
    if (((~*(u32 *)(iVar2 + 0x10) & 1) != 0) && (uVar1 <= *(u32 *)(iVar2 + 0xc))) {
      lVar4 = (long)iVar2;
    }
    iVar2 = *(int *)(iVar2 + 4);
  }
  if (lVar4 == 0) {
    iVar2 = 0;
  }
  else {
    if (uVar1 + 0x40 < *(u32 *)((int)lVar4 + 0xc)) {
      FUN_004c6d60(0,0);
      iVar2 = *(int *)(extraout_t0_lo + 4);
      lVar4 = extraout_a0;
      param_1 = extraout_t0_lo;
    }
    else {
      iVar2 = *(int *)(param_1 + 4);
    }
    lVar3 = (long)iVar2;
    if (lVar4 == lVar3) {
      do {
        *(u32 *)(param_1 + 4) = *(u32 *)((int)lVar3 + 4);
        lVar3 = (long)*(int *)(param_1 + 4);
        if (lVar3 == 0) break;
      } while ((*(u32 *)(*(int *)(param_1 + 4) + 0x10) & 1) != 0);
    }
    iVar2 = (int)lVar4 + 0x20;
    *(u32 *)((int)lVar4 + 0x10) = 1;
  }
  return iVar2;
}
// FUN_004C7020 NONMATCHING
u64 FUN_004c7020(u64 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  DAT_007ce918 = param_2;
  iVar1 = thunk_FUN_004c3970(0x21,DAT_007cdd58,4,DAT_007cdd5c,0x960010,0x40412);
  piVar2 = (int *)((int)&DAT_00960070 + DAT_007ce918);
  *piVar2 = iVar1;
  if (*piVar2 == 0) {
    param_1 = 0;
  }
  else {
    DAT_007ce91c = DAT_007ce91c + 1;
  }
  return param_1;
}
// FUN_004C70A0 NONMATCHING
#pragma schedule on
u64 FUN_004c70a0(u64 param_1)

{
  if (*(int *)(DAT_00960070_abs + DAT_007ce918) != 0) {
    FUN_004c3c30(*(int *)(DAT_00960070_abs + DAT_007ce918));
  }
  DAT_007ce91c = DAT_007ce91c + -1;
  return param_1;
}
// FUN_004C7100 NONMATCHING
int FUN_004c7100(char *param_1,char *param_2)
{
  char cVar1;
  char cVar2;
  
  if ((param_1 == (char *)0x0) || (param_2 == (char *)0x0)) {
    return 0;
  }
  while (true) {
    cVar1 = *param_1;
    cVar2 = *param_2;
    if ((cVar1 >= 'A') && (cVar1 < '[')) {
      cVar1 = cVar1 + 0x20;
    }
    if ((cVar2 >= 'A') && (cVar2 < '[')) {
      cVar2 = cVar2 + 0x20;
    }
    if (cVar1 != cVar2) {
      return cVar1 - cVar2;
    }
    if (cVar1 == '\0') {
      return 0;
    }
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
}
// FUN_004C71C0 NONMATCHING
char * FUN_004c71c0(char *param_1)
{
  char *pcVar1;
  char cVar2;
  
  if (param_1 == (char *)0x0) {
    return param_1;
  }
  pcVar1 = param_1;
  while (*pcVar1 != '\0') {
    cVar2 = *pcVar1;
    if ((cVar2 >= 'a') && (cVar2 < '{')) {
      *pcVar1 = cVar2 - 0x20;
    }
    pcVar1 = pcVar1 + 1;
  }
  return param_1;
}
// FUN_004C7210 NONMATCHING
char * FUN_004c7210(char *param_1)
{
  char *pcVar1;
  char cVar2;
  
  if (param_1 == (char *)0x0) {
    return param_1;
  }
  pcVar1 = param_1;
  while (*pcVar1 != '\0') {
    cVar2 = *pcVar1;
    if ((cVar2 >= 'A') && (cVar2 < '[')) {
      *pcVar1 = cVar2 + 0x20;
    }
    pcVar1 = pcVar1 + 1;
  }
  return param_1;
}
// FUN_004C7260 NONMATCHING
char * FUN_004c7260(char *param_1,char param_2)
{
  char *pcVar1;
  pcVar1 = (char *)0x0;
  do {
    if (*param_1 == param_2) {
      pcVar1 = param_1;
      break;
    }
    param_1 = param_1 + 1;
  } while (*param_1 != '\0');
  return pcVar1;
}
// FUN_004C72A0 NONMATCHING
char * FUN_004c72a0(char *param_1,int param_2)
{
  char *pcVar1;
  char *pcVar2;
  
  pcVar2 = (char *)0x0;
  while (*param_1 != '\0') {
    if (*param_1 == param_2) {
      pcVar2 = param_1;
    }
    param_1 = param_1 + 1;
  }
  return pcVar2;
}
// FUN_004C72E0 NONMATCHING
u32 FUN_004c72e0(void)

{
  DAT_00960134 = (u32)(FUN_00523ac8);
  DAT_00960138 = (u32)(FUN_005288c8);
  DAT_0096013c = (code *)((u32)(FUN_00524270));
  DAT_00960140 = (u32)(FUN_00524828);
  DAT_00960144 = (u32)(FUN_00523e68);
  DAT_00960148 = (u32)(FUN_005244c0);
  DAT_0096014c = (u32)(&LAB_004c72a0);
  DAT_00960150 = (u32)(&LAB_004c7260);
  DAT_00960154 = (u32)(FUN_00524a50);
  DAT_00960158 = (code *)((u32)(FUN_00524128));
  DAT_0096015c = (u32)(FUN_00524670);
  DAT_00960160 = (code *)((u32)(&LAB_004c7100));
  DAT_00960164 = (code *)((u32)(FUN_00524388));
  DAT_00960168 = (u32)(&LAB_004c71c0);
  DAT_0096016c = (u32)(&LAB_004c7210);
  DAT_00960170 = (u32)(FUN_00525958);
  DAT_00960174 = (u32)(FUN_00523b40);
  return 1;
}
// FUN_004C7400
void FUN_004c7400(void)

{
  return;
}
// FUN_004C7410 NONMATCHING
u32 FUN_004c7410(long param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    param_1 = 0x7bcbe8;
  }
  iVar1 = (*DAT_00960164)(param_1);
  return iVar1 + 4U & 0xfffffffc;
}
// FUN_004C7460 NONMATCHING
long FUN_004c7460(long param_1,u64 param_2)

{
  u32 uVar1;
  int iVar2;
  long lVar3;
  
  if (param_1 == 0) {
    param_1 = 0x7bcbe8;
  }
  lVar3 = param_1;
  if (param_1 == 0) {
    lVar3 = 0x7bcbe8;
  }
  iVar2 = (*DAT_00960164)(lVar3);
  uVar1 = iVar2 + 4U & 0xfffffffc;
  lVar3 = FUN_004c15a0(param_2,2,uVar1,0x37002,0x37);
  if (lVar3 == 0) {
    param_1 = 0;
  }
  else {
    lVar3 = FUN_004c53f0(param_2,param_1,uVar1);
    if (lVar3 == 0) {
      param_1 = 0;
    }
  }
  return param_1;
}
// FUN_004C7520 NONMATCHING
int FUN_004c7520(int param_1,u64 param_2,u32 param_3)

{
  u32 uVar1;
  u8 *puVar2;
  u8 *puVar3;
  u32 uVar4;
  int iVar5;
  u8 auStack_80 [120];
  u32 uStack_8;
  u32 uStack_4;
  
  iVar5 = param_1;
  if ((param_1 == 0) && (param_1 = (*DAT_00960178)(param_3,0x30002), iVar5 = param_1, param_1 == 0))
  {
    uStack_8 = 1;
    uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,param_3);
    FUN_004c1c50((u64)(unsigned int)(&uStack_8));
    return 0;
  }
  while( true ) {
    if (param_3 == 0) {
      return iVar5;
    }
    uVar4 = param_3;
    if (0x40 < param_3) {
      uVar4 = 0x40;
    }
    uVar1 = (u32)(unsigned int)FUN_004c5250((int *)(unsigned int)param_2,(u64)(unsigned int)(auStack_80),uVar4);
    if (uVar4 != uVar1) break;
    param_3 = param_3 - uVar4;
    uVar1 = 0;
    if (uVar4 != 0) {
      if (8 < uVar4) {
        puVar3 = auStack_80;
        do {
          puVar2 = (u8 *)(param_1 + uVar1);
          uVar1 = uVar1 + 8;
          *puVar2 = *puVar3;
          puVar2[1] = puVar3[1];
          puVar2[2] = puVar3[2];
          puVar2[3] = puVar3[3];
          puVar2[4] = puVar3[4];
          puVar2[5] = puVar3[5];
          puVar2[6] = puVar3[6];
          puVar2[7] = puVar3[7];
          puVar3 = puVar3 + 8;
        } while (uVar1 < uVar4 - 8);
      }
      if (uVar1 < uVar4) {
        puVar3 = auStack_80 + uVar1;
        do {
          puVar2 = (u8 *)(param_1 + uVar1);
          uVar1 = uVar1 + 1;
          *puVar2 = *puVar3;
          puVar3 = puVar3 + 1;
        } while (uVar1 < uVar4);
      }
    }
    param_1 = param_1 + uVar4;
  }
  return 0;
}
// FUN_004C76C0 NONMATCHING
int FUN_004c76c0(int param_1,u64 param_2,u32 param_3)

{
  bool bVar1;
  u32 uVar2;
  u32 uVar3;
  u8 *puVar4;
  u16 *puVar5;
  int iVar6;
  u16 auStack_c0 [92];
  u32 uStack_8;
  u32 uStack_4;
  
  bVar1 = false;
  iVar6 = param_1;
  if (param_1 == 0) {
    param_1 = (*DAT_00960178)(param_3,0x30002);
    if (param_1 == 0) {
      uStack_8 = 1;
      uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,param_3);
      FUN_004c1c50((u64)(unsigned int)(&uStack_8));
      return 0;
    }
    bVar1 = true;
    iVar6 = param_1;
  }
  while( true ) {
    if (param_3 == 0) {
      return iVar6;
    }
    uVar3 = param_3;
    if (0x80 < param_3) {
      uVar3 = 0x80;
    }
    uVar2 = (u32)(unsigned int)FUN_004c5250((int *)(unsigned int)param_2,(u64)(unsigned int)(auStack_c0),uVar3);
    if (uVar3 != uVar2) break;
    uVar2 = uVar3 >> 1;
    param_3 = param_3 - uVar3;
    uVar3 = 0;
    if (uVar2 != 0) {
      if (8 < uVar2) {
        puVar5 = auStack_c0;
        do {
          puVar4 = (u8 *)(param_1 + uVar3);
          uVar3 = uVar3 + 8;
          *puVar4 = (char)*puVar5;
          puVar4[1] = (char)puVar5[1];
          puVar4[2] = (char)puVar5[2];
          puVar4[3] = (char)puVar5[3];
          puVar4[4] = (char)puVar5[4];
          puVar4[5] = (char)puVar5[5];
          puVar4[6] = (char)puVar5[6];
          puVar4[7] = (char)puVar5[7];
          puVar5 = puVar5 + 8;
        } while (uVar3 < uVar2 - 8);
      }
      if (uVar3 < uVar2) {
        puVar5 = auStack_c0 + uVar3;
        do {
          puVar4 = (u8 *)(param_1 + uVar3);
          uVar3 = uVar3 + 1;
          *puVar4 = (char)*puVar5;
          puVar5 = puVar5 + 1;
        } while (uVar3 < uVar2);
      }
    }
    param_1 = param_1 + uVar2;
  }
  if (bVar1) {
    (*DAT_0096017c)(iVar6);
  }
  return 0;
}
// FUN_004C78A0 NONMATCHING
u64 FUN_004c78a0(u64 param_1,u64 param_2)

{
  bool bVar1;
  long lVar2;
  u64 uVar3;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_c;
  u32 uStack_8;
  int iStack_4;
  
  lVar2 = (long)(FUN_004c1450(param_2,(u64)(unsigned int)(&iStack_4),(u64)(unsigned int)(&uStack_8),(u64)(unsigned int)(&uStack_c),0));
  while( true ) {
    if (lVar2 == 0) {
      return 0;
    }
    bVar1 = false;
    if ((0x34fff < uStack_c) && (uStack_c < 0x37003)) {
      bVar1 = true;
    }
    if (!bVar1) {
      uStack_18 = 1;
      uStack_14 = FUN_004c1d10(0xffffffff80000004);
      FUN_004c1c50((u64)(unsigned int)(&uStack_18));
      return 0;
    }
    if (iStack_4 == 2) {
      uVar3 = FUN_004c7520(param_1,param_2,uStack_8);
      return uVar3;
    }
    if (iStack_4 == 0x13) break;
    lVar2 = FUN_004c5620(param_2,uStack_8);
    if (lVar2 == 0) {
      return 0;
    }
    lVar2 = (long)(FUN_004c1450(param_2,(u64)(unsigned int)(&iStack_4),(u64)(unsigned int)(&uStack_8),(u64)(unsigned int)(&uStack_c),0));
  }
  uVar3 = FUN_004c76c0(param_1,param_2,uStack_8);
  return uVar3;
}
// FUN_004C79E0 NONMATCHING
u32 FUN_004c79e0(long param_1)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  u32 uVar4;
  
  uVar4 = 0;
  if (param_1 != 0) {
    cVar1 = *(char *)param_1;
    bVar3 = true;
    if (cVar1 != '\\') {
      bVar2 = false;
      if ((*(u8 *)((int)&PTR_DAT_007be9c8 + (int)cVar1) & 3) != 0) {
        bVar2 = ((char *)param_1)[1] == ':';
      }
      if (!bVar2) {
        bVar3 = false;
      }
    }
    if (bVar3) {
      uVar4 = 1;
    }
  }
  return uVar4;
}
// FUN_004C7A50 NONMATCHING
u64 FUN_004c7a50(u64 param_1,float *param_2,int param_3)

{
  bool bVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  pfVar2 = (float *)param_1;
  fVar7 = *param_2;
  fVar5 = param_2[1];
  iVar4 = param_3 + -2;
  fVar6 = param_2[2];
  pfVar2[3] = fVar7;
  pfVar2[4] = fVar5;
  pfVar2[5] = fVar6;
  *pfVar2 = fVar7;
  pfVar2[1] = fVar5;
  pfVar2[2] = fVar6;
  if (param_3 != 1) {
    do {
      pfVar3 = param_2 + 3;
      if (*pfVar3 < pfVar2[3]) {
        pfVar2[3] = *pfVar3;
      }
      if (param_2[4] < pfVar2[4]) {
        pfVar2[4] = param_2[4];
      }
      if (param_2[5] < pfVar2[5]) {
        pfVar2[5] = param_2[5];
      }
      if (*pfVar2 < *pfVar3) {
        *pfVar2 = *pfVar3;
      }
      if (pfVar2[1] < param_2[4]) {
        pfVar2[1] = param_2[4];
      }
      if (pfVar2[2] < param_2[5]) {
        pfVar2[2] = param_2[5];
      }
      bVar1 = iVar4 != 0;
      iVar4 = iVar4 + -1;
      param_2 = pfVar3;
    } while (bVar1);
  }
  return param_1;
}
// FUN_004C7B60 NONMATCHING
void FUN_004c7b60(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  FUN_004c5960(0x77e5e0,param_1,param_2,param_3,param_4);
  return;
}
// FUN_004C7B90 NONMATCHING
long FUN_004c7b90(u64 param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  u8 auStack_30 [8];
  u8 auStack_28 [8];
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  int iStack_4;
  
  lVar2 = (long)(FUN_004c1600(param_1,1,(u64)(unsigned int)(&iStack_4),(u64)(unsigned int)(&uStack_8)));
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  else if ((uStack_8 < 0x35000) || (0x37002 < uStack_8)) {
    uStack_10 = 1;
    uStack_c = FUN_004c1d10(0xffffffff80000004);
    FUN_004c1c50((u64)(unsigned int)(&uStack_10));
    lVar2 = 0;
  }
  else {
    FUN_00521408(auStack_30,0,0x20);
    iVar1 = (int)(unsigned int)FUN_004c5250((int *)(unsigned int)param_1,(u64)(unsigned int)(auStack_30),iStack_4);
    if (iStack_4 == iVar1) {
      lVar2 = FUN_004ca090();
      if (lVar2 == 0) {
        lVar2 = 0;
      }
      else {
        lVar3 = FUN_004c5a50(0x77e5e0,param_1,lVar2);
        if (lVar3 == 0) {
          lVar2 = 0;
        }
        else {
          FUN_004c9f90(lVar2,auStack_30);
          FUN_004c9d20(lVar2,(u32 *)(u32)(auStack_28));
          *(u32 *)((int)lVar2 + 0x88) = uStack_18;
          FUN_004c9f00(lVar2,uStack_14);
        }
      }
    }
    else {
      lVar2 = 0;
    }
  }
  return lVar2;
}
#pragma optimization_level 3
// FUN_004C7CF0
void FUN_004c7cf0(u32 param_1)

{
  DAT_007cdd60 = param_1;
  return;
}
#pragma optimization_level 2
// FUN_004C7D00 NONMATCHING
void FUN_004c7d00(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  FUN_004c5960(0x77e670,param_1,param_2,param_3,param_4);
  return;
}
// FUN_004C7D30 NONMATCHING
u64 FUN_004c7d30(u64 param_1)

{
  if (((u32 *)param_1)[1] != 0) {
    (*DAT_0096017c)(*(u32 *)param_1);
  }
  return param_1;
}
// FUN_004C7D80 NONMATCHING
u64 FUN_004c7d80(u64 param_1,u64 param_2)

{
  int iVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  float fVar7;
  u32 uStack_60;
  u32 uStack_5c;
  u32 uStack_58;
  u32 uStack_54;
  u32 uStack_50;
  u32 uStack_4c;
  u32 uStack_48;
  u32 uStack_44;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  int iStack_30;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_c;
  u8 auStack_8 [4];
  int iStack_4;
  
  lVar3 = (long)(FUN_004c1600(param_1,1,(u64)(unsigned int)(auStack_8),(u64)(unsigned int)(&uStack_c)));
  if (lVar3 == 0) {
    param_2 = 0;
  }
  else if ((uStack_c < 0x35000) || (0x37002 < uStack_c)) {
    uStack_20 = 1;
    uStack_1c = FUN_004c1d10(0xffffffff80000004);
    FUN_004c1c50((u64)(unsigned int)(&uStack_20));
    param_2 = 0;
  }
  else {
    lVar3 = (long)(unsigned int)FUN_004c5250((int *)(unsigned int)param_1,(u64)(unsigned int)(&iStack_4),4);
    if (lVar3 == 4) {
      piVar6 = (int *)param_2;
      piVar6[1] = iStack_4;
      iVar1 = (*DAT_00960178)(iStack_4 << 2,0x3000e);
      *piVar6 = iVar1;
      if (*piVar6 == 0) {
        uStack_18 = 1;
        uStack_14 = ((code)FUN_004c1d10)(0xffffffff80000013,iStack_4 << 2);
        FUN_004c1c50((u64)(unsigned int)(&uStack_18));
        param_2 = 0;
      }
      else {
        iVar1 = 0;
        if (0 < iStack_4) {
          iVar5 = 0;
          do {
            lVar3 = (long)(unsigned int)FUN_004c5250((int *)(unsigned int)param_1,(u64)(unsigned int)(&uStack_60),0x38);
            if (lVar3 != 0x38) {
              (*DAT_0096017c)(*piVar6);
              return 0;
            }
            lVar3 = FUN_004caf10();
            if (lVar3 == 0) {
              (*DAT_0096017c)(*piVar6);
              return 0;
            }
            iVar2 = (int)lVar3;
            iVar4 = iVar2 + 0x10;
            *(u32 *)(iVar2 + 0x10) = uStack_60;
            *(u32 *)(iVar2 + 0x14) = uStack_5c;
            *(u32 *)(iVar2 + 0x18) = uStack_58;
            *(u32 *)(iVar2 + 0x20) = uStack_54;
            *(u32 *)(iVar2 + 0x24) = uStack_50;
            *(u32 *)(iVar2 + 0x28) = uStack_4c;
            *(u32 *)(iVar2 + 0x30) = uStack_48;
            *(u32 *)(iVar2 + 0x34) = uStack_44;
            *(u32 *)(iVar2 + 0x38) = uStack_40;
            *(u32 *)(iVar2 + 0x40) = uStack_3c;
            *(u32 *)(iVar2 + 0x44) = uStack_38;
            *(u32 *)(iVar2 + 0x48) = uStack_34;
            fVar7 = (float)(u32)FUN_004c2b20((float *)(iVar4));
            if (((0.01 < fVar7) || (fVar7 = (float)(u32)FUN_004c2ac0((float *)(iVar4)), 0.01 < fVar7)) ||
               (fVar7 = (float)(u32)FUN_004c2a70((float *)(iVar4)), fVar7 < 0.99)) {
              *(u32 *)(iVar2 + 0x1c) = *(u32 *)(iVar2 + 0x1c) & 0xfffdfffc;
            }
            else {
              *(u32 *)(iVar2 + 0x1c) = *(u32 *)(iVar2 + 0x1c) & 0xfffdffff;
            }
            *(int *)(*piVar6 + iVar5) = iVar2;
            if (-1 < iStack_30) {
              if (DAT_007cdd60 == 0) {
                FUN_004cb350(*(u32 *)(*piVar6 + iStack_30 * 4),lVar3);
              }
              else {
                FUN_004cb420(*(u32 *)(*piVar6 + iStack_30 * 4),lVar3);
              }
            }
            iVar1 = iVar1 + 1;
            iVar5 = iVar5 + 4;
          } while (iVar1 < iStack_4);
        }
        iVar1 = 0;
        if (0 < iStack_4) {
          iVar5 = 0;
          do {
            iVar4 = *(int *)(*piVar6 + iVar5);
            lVar3 = FUN_004c5a50(0x77e670,param_1,iVar4);
            if (lVar3 == 0) {
              FUN_004cb1b0(*(u32 *)*piVar6);
              (*DAT_0096017c)(*piVar6);
              return 0;
            }
            iVar2 = FUN_004cb340(iVar4);
            if ((iVar4 == iVar2) && (DAT_007cdd60 == 1)) {
              FUN_004cb270(iVar4);
            }
            iVar1 = iVar1 + 1;
            iVar5 = iVar5 + 4;
          } while (iVar1 < iStack_4);
        }
      }
    }
    else {
      param_2 = 0;
    }
  }
  return param_2;
}
// FUN_004C81A0 NONMATCHING
void FUN_004c81a0(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  FUN_004c5960(0x77e6d0,param_1,param_2,param_3,param_4);
  return;
}
// FUN_004C81D0 NONMATCHING
int FUN_004c81d0(u64 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_004c7410((int)param_1 + 0x10);
  iVar2 = FUN_004c7410((int)param_1 + 0x30);
  iVar3 = FUN_004c5cb0(0x77e6d0,param_1);
  return iVar1 + iVar2 + iVar3 + 0x34;
}
// FUN_004C8240 NONMATCHING
u64 FUN_004c8240(u64 param_1,u64 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  int *piVar5;
  u32 uStack_4;
  
  piVar5 = (int *)param_1;
  iVar1 = (long)(unsigned int)(FUN_004c7410((long)(piVar5 + 4)));
  iVar2 = (long)(unsigned int)(FUN_004c7410((long)(piVar5 + 0xc)));
  iVar3 = FUN_004c5cb0(0x77e6d0,param_1);
  lVar4 = FUN_004c15a0(param_2,6,iVar1 + iVar2 + iVar3 + 0x34,0x37002,0x37);
  if (lVar4 == 0) {
    param_1 = 0;
  }
  else {
    lVar4 = FUN_004c15a0(param_2,1,4,0x37002,0x37);
    if (lVar4 == 0) {
      param_1 = 0;
    }
    else {
      if ((*piVar5 == 0) || ((*(u8 *)(*piVar5 + 0x23) & 0x10) != 0)) {
        iVar1 = 0;
      }
      else {
        iVar1 = 1;
      }
      uStack_4 = (u32)*(u16 *)(piVar5 + 0x14) | iVar1 << 0x10;
      lVar4 = (u64)(FUN_004c53f0(param_2,(u64)(unsigned int)(&uStack_4),4));
      if (lVar4 == 0) {
        param_1 = 0;
      }
      else {
        lVar4 = (long)(unsigned int)(FUN_004c7460((long)(piVar5 + 4),param_2));
        if (lVar4 == 0) {
          param_1 = 0;
        }
        else {
          lVar4 = (long)(unsigned int)(FUN_004c7460((long)(piVar5 + 0xc),param_2));
          if (lVar4 == 0) {
            param_1 = 0;
          }
          else {
            lVar4 = FUN_004c5d30(0x77e6d0,param_2,param_1);
            if (lVar4 == 0) {
              param_1 = 0;
            }
          }
        }
      }
    }
  }
  return param_1;
}
// FUN_004C83C0 NONMATCHING
long FUN_004c83c0(u64 param_1)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  u64 uVar4;
  u64 uVar5;
  long lVar6;
  u32 uVar7;
  u8 auStack_120 [128];
  u8 auStack_a0 [136];
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_c;
  u32 uStack_8;
  int iStack_4;
  
  lVar3 = (long)(FUN_004c1600(param_1,1,(u64)(unsigned int)(&iStack_4),(u64)(unsigned int)(&uStack_8)));
  if (lVar3 == 0) {
    lVar3 = 0;
  }
  else if ((uStack_8 < 0x35000) || (0x37002 < uStack_8)) {
    uStack_18 = 1;
    uStack_14 = FUN_004c1d10(0xffffffff80000004);
    FUN_004c1c50((u64)(unsigned int)(&uStack_18));
    lVar3 = 0;
  }
  else {
    FUN_00521408(&uStack_c,0,4);
    iVar1 = (int)(unsigned int)FUN_004c5250((int *)(unsigned int)param_1,(u64)(unsigned int)(&uStack_c),iStack_4);
    if (iStack_4 == iVar1) {
      uVar7 = uStack_c & 0xff;
      if ((uStack_c >> 0xc & 0xf) == 0) {
        uStack_c = uStack_c | (uStack_c >> 8 & 0xf) << 0xc;
      }
      uVar2 = uStack_c >> 0x10;
      uVar4 = FUN_004d0b80();
      uVar5 = FUN_004d0bc0();
      if (uVar7 - 3 < 4) {
        FUN_004d0b60(1);
        if ((uVar2 & 1) == 0) {
          FUN_004d0ba0(1);
        }
        else {
          FUN_004d0ba0(0);
        }
      }
      else {
        FUN_004d0b60(0);
        FUN_004d0ba0(0);
      }
      lVar3 = (u64)(FUN_004c78a0((u64)(unsigned int)(auStack_a0),param_1));
      if (lVar3 == 0) {
        FUN_004d0b60(uVar4);
        FUN_004d0ba0(uVar5);
        lVar3 = 0;
      }
      else {
        lVar3 = (u64)(FUN_004c78a0((u64)(unsigned int)(auStack_120),param_1));
        if (lVar3 == 0) {
          FUN_004d0b60(uVar4);
          FUN_004d0ba0(uVar5);
          lVar3 = 0;
        }
        else {
          lVar3 = FUN_004d1260(auStack_a0,auStack_120);
          if (lVar3 == 0) {
            FUN_004c5ea0(0x77e6d0,param_1);
            FUN_004d0b60(uVar4);
            FUN_004d0ba0(uVar5);
            lVar3 = 0;
          }
          else {
            FUN_004d0b60(uVar4);
            FUN_004d0ba0(uVar5);
            if (*(int *)((int)lVar3 + 0x54) == 1) {
              *(u32 *)((int)lVar3 + 0x50) = uStack_c & 0xffff;
              lVar6 = FUN_004c5a50(0x77e6d0,param_1,lVar3);
              if (lVar6 == 0) {
                lVar3 = 0;
              }
            }
            else {
              lVar6 = FUN_004c5ea0(0x77e6d0,param_1);
              if (lVar6 == 0) {
                lVar3 = 0;
              }
            }
          }
        }
      }
    }
    else {
      lVar3 = 0;
    }
  }
  return lVar3;
}
#pragma schedule on
// FUN_004C8650
u64 FUN_004c8650(u64 param_1)

{
  FUN_004d0f00();
  return param_1;
}
#pragma schedule off
// FUN_004C8680 NONMATCHING
long FUN_004c8680(u64 param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  int iStack_14;
  short sStack_10;
  u16 uStack_e;
  u32 uStack_c;
  int iStack_8;
  u16 uStack_2;
  
  lVar4 = (long)(FUN_004c1600(param_1,1,(u64)(unsigned int)(&iStack_8),(u64)(unsigned int)(&uStack_c)));
  if (lVar4 == 0) {
    lVar4 = 0;
  }
  else if ((uStack_c < 0x35000) || (0x37002 < uStack_c)) {
    uStack_28 = 1;
    uStack_24 = FUN_004c1d10(0xffffffff80000004);
    FUN_004c1c50((u64)(unsigned int)(&uStack_28));
    lVar4 = 0;
  }
  else {
    FUN_00521408(&sStack_10,0,4);
    iVar2 = iStack_8;
    iVar3 = (int)(unsigned int)FUN_004c5250((int *)(unsigned int)param_1,(u64)(unsigned int)(&sStack_10),iStack_8);
    if (iVar2 == iVar3) {
      uStack_2 = 0;
      uStack_2 = uStack_2 & 0xff;
      if (((uStack_2 == 0) || (uStack_e == 0)) || (uStack_2 == uStack_e)) {
        lVar4 = FUN_004d0c30();
        sVar1 = sStack_10;
        if (lVar4 == 0) {
          lVar4 = 0;
        }
        else {
          while (sStack_10 = sVar1 + -1, sVar1 != 0) {
            lVar5 = (long)(FUN_004c1600(param_1,0x15,(u64)(unsigned int)(&iStack_8),(u64)(unsigned int)(&uStack_c)));
            if (lVar5 == 0) {
              FUN_004d0dc0(lVar4,0x4c8650,0);
              FUN_004d0d10(lVar4);
              return 0;
            }
            if ((uStack_c < 0x35000) || (0x37002 < uStack_c)) {
              FUN_004d0dc0(lVar4,0x4c8650,0);
              FUN_004d0d10(lVar4);
              uStack_20 = 1;
              uStack_1c = FUN_004c1d10(0xffffffff80000004);
              FUN_004c1c50((u64)(unsigned int)(&uStack_20));
              return 0;
            }
            lVar5 = (*DAT_00960120)(param_1,&iStack_14,iStack_8);
            if (lVar5 == 0) {
              FUN_004d0dc0(lVar4,0x4c8650,0);
              FUN_004d0d10(lVar4);
              return 0;
            }
            if (iStack_14 == 0) {
              FUN_004d0dc0(lVar4,0x4c8650,0);
              FUN_004d0d10(lVar4);
              return 0;
            }
            lVar5 = FUN_004c5a50(0x77e6d0,param_1,0);
            if (lVar5 == 0) {
              FUN_004d0dc0(lVar4,0x4c8650,0);
              FUN_004d0d10(lVar4);
              return 0;
            }
            FUN_004d1110(lVar4,iStack_14);
            sVar1 = sStack_10;
          }
          lVar5 = FUN_004c5a50(0x77e6f0,param_1,lVar4);
          if (lVar5 == 0) {
            FUN_004d0dc0(lVar4,0x4c8650,0);
            FUN_004d0d10(lVar4);
            lVar4 = 0;
          }
        }
      }
      else {
        lVar4 = 0;
      }
    }
    else {
      lVar4 = 0;
    }
  }
  return lVar4;
}
// FUN_004C89A0 NONMATCHING
u64 FUN_004c89a0(u64 param_1)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x14) == 1) {
    fVar2 = *(float *)(iVar1 + 0x84);
  }
  else {
    if (*(int *)(iVar1 + 0x14) == 2) {
      fVar6 = *(float *)(iVar1 + 0x80);
      fVar2 = *(float *)(iVar1 + 0x84);
      goto LAB_004c89fc;
    }
    fVar2 = *(float *)(iVar1 + 0x84);
  }
  fVar2 = 1.0 / fVar2;
  fVar6 = 1.0 / *(float *)(iVar1 + 0x80);
LAB_004c89fc:
  fVar3 = (DAT_0096008c - DAT_00960088) * 0.0001;
  fVar4 = DAT_0096008c - fVar3;
  fVar3 = DAT_00960088 + fVar3;
  fVar5 = (fVar4 - fVar3) / (fVar2 - fVar6);
  *(float *)(iVar1 + 0x8c) = fVar5;
  *(float *)(iVar1 + 0x90) = ((fVar4 + fVar3 + 0.0) - fVar5 * (fVar2 + fVar6)) * 0.5;
  return param_1;
}
// FUN_004C8A60 NONMATCHING
void FUN_004c8a60(int param_1)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  float fVar8;
  u32 uVar9;
  float fVar10;
  float fVar11;
  u32 uVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  
  iVar1 = *(int *)(param_1 + 4);
  pfVar3 = (float *)(param_1 + 0x124);
  fVar10 = *(float *)(param_1 + 0x7c);
  pfVar2 = (float *)(param_1 + 0x94);
  fVar16 = *(float *)(param_1 + 0x68);
  iVar7 = 0;
  fVar8 = -*(float *)(param_1 + 0x78);
  iVar5 = 0;
  fVar13 = *(float *)(iVar1 + 0x60) * fVar10 + *(float *)(iVar1 + 0x50) * fVar8;
  fVar15 = *(float *)(iVar1 + 100) * fVar10 + *(float *)(iVar1 + 0x54) * fVar8 + 0.0;
  fVar24 = *(float *)(iVar1 + 0x68);
  fVar21 = *(float *)(param_1 + 0x6c);
  fVar20 = *(float *)(iVar1 + 0x58) * fVar16;
  fVar14 = fVar24 * fVar10 + *(float *)(iVar1 + 0x58) * fVar8 + 0.0;
  fVar11 = *(float *)(iVar1 + 0x78);
  fVar10 = *(float *)(iVar1 + 0x54) * fVar16;
  fVar16 = *(float *)(iVar1 + 0x50) * fVar16;
  fVar8 = *(float *)(iVar1 + 0x60) * fVar21;
  fVar17 = *(float *)(iVar1 + 0x70) + fVar16 + fVar8;
  fVar18 = *(float *)(iVar1 + 100) * fVar21;
  fVar16 = fVar16 * 2.0;
  fVar22 = fVar10 * 2.0;
  fVar23 = fVar20 * 2.0;
  fVar10 = *(float *)(iVar1 + 0x74) + fVar10 + fVar18;
  fVar19 = fVar17 - fVar16;
  *(float *)(param_1 + 0x124) = fVar17;
  fVar17 = fVar19 - fVar8 * 2.0;
  *(float *)(param_1 + 0x128) = fVar10;
  fVar8 = fVar24 * fVar21 + fVar11 + fVar20;
  fVar10 = fVar10 - fVar22;
  *(float *)(param_1 + 300) = fVar8;
  *(float *)(param_1 + 0x130) = fVar19;
  fVar8 = fVar8 - fVar23;
  *(float *)(param_1 + 0x134) = fVar10;
  fVar10 = fVar10 - fVar18 * 2.0;
  *(float *)(param_1 + 0x138) = fVar8;
  fVar8 = fVar8 - fVar24 * fVar21 * 2.0;
  *(float *)(param_1 + 0x13c) = fVar17;
  *(float *)(param_1 + 0x140) = fVar10;
  *(float *)(param_1 + 0x144) = fVar8;
  *(float *)(param_1 + 0x148) = fVar17 + fVar16;
  *(float *)(param_1 + 0x14c) = fVar10 + fVar22;
  *(float *)(param_1 + 0x150) = fVar8 + fVar23;
  pfVar6 = pfVar3;
  do {
    fVar11 = *pfVar6;
    pfVar4 = (float *)((int)pfVar3 + iVar5 + 0x30);
    fVar8 = pfVar6[1];
    iVar7 = iVar7 + 1;
    fVar10 = pfVar6[2];
    iVar5 = iVar5 + 0xc;
    *pfVar6 = fVar13 + *(float *)(iVar1 + 0x80);
    pfVar6[1] = fVar15 + *(float *)(iVar1 + 0x84);
    pfVar6[2] = fVar14 + *(float *)(iVar1 + 0x88);
    *pfVar6 = (fVar11 - fVar13) * *(float *)(param_1 + 0x80) + *pfVar6 + 0.0;
    pfVar6[1] = (fVar8 - fVar15) * *(float *)(param_1 + 0x80) + pfVar6[1] + 0.0;
    pfVar6[2] = (fVar10 - fVar14) * *(float *)(param_1 + 0x80) + pfVar6[2] + 0.0;
    pfVar6 = pfVar6 + 3;
    *pfVar4 = fVar13 + *(float *)(iVar1 + 0x80);
    pfVar4[1] = fVar15 + *(float *)(iVar1 + 0x84);
    pfVar4[2] = fVar14 + *(float *)(iVar1 + 0x88);
    *pfVar4 = (fVar11 - fVar13) * *(float *)(param_1 + 0x84) + *pfVar4 + 0.0;
    pfVar4[1] = (fVar8 - fVar15) * *(float *)(param_1 + 0x84) + pfVar4[1] + 0.0;
    pfVar4[2] = (fVar10 - fVar14) * *(float *)(param_1 + 0x84) + pfVar4[2] + 0.0;
  } while (iVar7 < 4);
  uVar9 = *(u32 *)(iVar1 + 0x74);
  uVar12 = *(u32 *)(iVar1 + 0x78);
  *pfVar2 = *(float *)(iVar1 + 0x70);
  *(u32 *)(param_1 + 0x98) = uVar9;
  *(u32 *)(param_1 + 0x9c) = uVar12;
  *(float *)(param_1 + 0xa0) =
       *(float *)(param_1 + 0x15c) * *(float *)(iVar1 + 0x78) +
       *(float *)(param_1 + 0x154) * *(float *)(iVar1 + 0x70) +
       *(float *)(param_1 + 0x158) * *(float *)(iVar1 + 0x74) + 0.0 + 0.0;
  *(char *)(param_1 + 0xa4) = (char)((int)*pfVar2 >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xa5) = (char)((int)*(u32 *)(param_1 + 0x98) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xa6) = (char)((int)*(u32 *)(param_1 + 0x9c) >> 0x1f) + '\x01';
  *(float *)(param_1 + 0xa8) = -*pfVar2;
  *(float *)(param_1 + 0xac) = -*(float *)(param_1 + 0x98);
  *(float *)(param_1 + 0xb0) = -*(float *)(param_1 + 0x9c);
  *(float *)(param_1 + 0xb4) =
       *(float *)(param_1 + 300) * *(float *)(param_1 + 0xb0) +
       *pfVar3 * *(float *)(param_1 + 0xa8) +
       *(float *)(param_1 + 0x128) * *(float *)(param_1 + 0xac) + 0.0 + 0.0;
  *(char *)(param_1 + 0xb8) = (char)((int)*(u32 *)(param_1 + 0xa8) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xb9) = (char)((int)*(u32 *)(param_1 + 0xac) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xba) = (char)((int)*(u32 *)(param_1 + 0xb0) >> 0x1f) + '\x01';
  fVar10 = *(float *)(param_1 + 0x130) - *(float *)(param_1 + 0x160);
  fVar15 = *(float *)(param_1 + 0x16c) - *(float *)(param_1 + 0x160);
  fVar8 = *(float *)(param_1 + 0x134) - *(float *)(param_1 + 0x164);
  fVar13 = *(float *)(param_1 + 0x170) - *(float *)(param_1 + 0x164);
  fVar11 = *(float *)(param_1 + 0x138) - *(float *)(param_1 + 0x168);
  fVar14 = *(float *)(param_1 + 0x174) - *(float *)(param_1 + 0x168);
  *(float *)(param_1 + 0xbc) = (fVar8 * fVar14 + 0.0) - fVar11 * fVar13;
  *(float *)(param_1 + 0xc0) = (fVar11 * fVar15 + 0.0) - fVar10 * fVar14;
  *(float *)(param_1 + 0xc4) = (fVar10 * fVar13 + 0.0) - fVar8 * fVar15;
  fVar13 = SQRT(*(float *)(param_1 + 0xc4) * *(float *)(param_1 + 0xc4) +
                *(float *)(param_1 + 0xbc) * *(float *)(param_1 + 0xbc) +
                *(float *)(param_1 + 0xc0) * *(float *)(param_1 + 0xc0) + 0.0 + 0.0);
  if (0.0 < fVar13) {
    fVar13 = 1.0 / fVar13;
  }
  *(float *)(param_1 + 0xbc) = *(float *)(param_1 + 0xbc) * fVar13;
  *(float *)(param_1 + 0xc0) = *(float *)(param_1 + 0xc0) * fVar13;
  *(float *)(param_1 + 0xc4) = *(float *)(param_1 + 0xc4) * fVar13;
  *(float *)(param_1 + 200) =
       *(float *)(param_1 + 0x138) * *(float *)(param_1 + 0xc4) +
       *(float *)(param_1 + 0x130) * *(float *)(param_1 + 0xbc) +
       *(float *)(param_1 + 0x134) * *(float *)(param_1 + 0xc0);
  *(char *)(param_1 + 0xcc) = (char)((int)*(u32 *)(param_1 + 0xbc) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xcd) = (char)((int)*(u32 *)(param_1 + 0xc0) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xce) = (char)((int)*(u32 *)(param_1 + 0xc4) >> 0x1f) + '\x01';
  fVar13 = *(float *)(param_1 + 0x158) - *(float *)(param_1 + 0x164);
  fVar14 = *(float *)(param_1 + 0x15c) - *(float *)(param_1 + 0x168);
  fVar15 = *(float *)(param_1 + 0x154) - *(float *)(param_1 + 0x160);
  *(float *)(param_1 + 0xd0) = fVar13 * fVar11 - fVar14 * fVar8;
  *(float *)(param_1 + 0xd4) = fVar14 * fVar10 - fVar15 * fVar11;
  *(float *)(param_1 + 0xd8) = fVar15 * fVar8 - fVar13 * fVar10;
  fVar8 = SQRT(*(float *)(param_1 + 0xd8) * *(float *)(param_1 + 0xd8) +
               *(float *)(param_1 + 0xd0) * *(float *)(param_1 + 0xd0) +
               *(float *)(param_1 + 0xd4) * *(float *)(param_1 + 0xd4));
  if (0.0 < fVar8) {
    fVar8 = 1.0 / fVar8;
  }
  *(float *)(param_1 + 0xd0) = *(float *)(param_1 + 0xd0) * fVar8;
  *(float *)(param_1 + 0xd4) = *(float *)(param_1 + 0xd4) * fVar8;
  *(float *)(param_1 + 0xd8) = *(float *)(param_1 + 0xd8) * fVar8;
  *(float *)(param_1 + 0xdc) =
       *(float *)(param_1 + 0x138) * *(float *)(param_1 + 0xd8) +
       *(float *)(param_1 + 0x130) * *(float *)(param_1 + 0xd0) +
       *(float *)(param_1 + 0x134) * *(float *)(param_1 + 0xd4);
  *(char *)(param_1 + 0xe0) = (char)((int)*(u32 *)(param_1 + 0xd0) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xe1) = (char)((int)*(u32 *)(param_1 + 0xd4) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xe2) = (char)((int)*(u32 *)(param_1 + 0xd8) >> 0x1f) + '\x01';
  fVar10 = *(float *)(param_1 + 0x148) - *(float *)(param_1 + 0x178);
  fVar15 = *(float *)(param_1 + 0x154) - *(float *)(param_1 + 0x178);
  fVar11 = *(float *)(param_1 + 0x150) - *(float *)(param_1 + 0x180);
  fVar8 = *(float *)(param_1 + 0x14c) - *(float *)(param_1 + 0x17c);
  fVar13 = *(float *)(param_1 + 0x158) - *(float *)(param_1 + 0x17c);
  fVar14 = *(float *)(param_1 + 0x15c) - *(float *)(param_1 + 0x180);
  *(float *)(param_1 + 0xe4) = fVar8 * fVar14 - fVar11 * fVar13;
  *(float *)(param_1 + 0xe8) = fVar11 * fVar15 - fVar10 * fVar14;
  *(float *)(param_1 + 0xec) = fVar10 * fVar13 - fVar8 * fVar15;
  fVar13 = SQRT(*(float *)(param_1 + 0xec) * *(float *)(param_1 + 0xec) +
                *(float *)(param_1 + 0xe4) * *(float *)(param_1 + 0xe4) +
                *(float *)(param_1 + 0xe8) * *(float *)(param_1 + 0xe8));
  if (0.0 < fVar13) {
    fVar13 = 1.0 / fVar13;
  }
  *(float *)(param_1 + 0xe4) = *(float *)(param_1 + 0xe4) * fVar13;
  *(float *)(param_1 + 0xe8) = *(float *)(param_1 + 0xe8) * fVar13;
  *(float *)(param_1 + 0xec) = *(float *)(param_1 + 0xec) * fVar13;
  *(float *)(param_1 + 0xf0) =
       *(float *)(param_1 + 0x150) * *(float *)(param_1 + 0xec) +
       *(float *)(param_1 + 0x148) * *(float *)(param_1 + 0xe4) +
       *(float *)(param_1 + 0x14c) * *(float *)(param_1 + 0xe8);
  *(char *)(param_1 + 0xf4) = (char)((int)*(u32 *)(param_1 + 0xe4) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xf5) = (char)((int)*(u32 *)(param_1 + 0xe8) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xf6) = (char)((int)*(u32 *)(param_1 + 0xec) >> 0x1f) + '\x01';
  fVar13 = *(float *)(param_1 + 0x170) - *(float *)(param_1 + 0x17c);
  fVar14 = *(float *)(param_1 + 0x174) - *(float *)(param_1 + 0x180);
  fVar15 = *(float *)(param_1 + 0x16c) - *(float *)(param_1 + 0x178);
  *(float *)(param_1 + 0xf8) = fVar13 * fVar11 - fVar14 * fVar8;
  *(float *)(param_1 + 0xfc) = fVar14 * fVar10 - fVar15 * fVar11;
  *(float *)(param_1 + 0x100) = fVar15 * fVar8 - fVar13 * fVar10;
  fVar8 = SQRT(*(float *)(param_1 + 0x100) * *(float *)(param_1 + 0x100) +
               *(float *)(param_1 + 0xf8) * *(float *)(param_1 + 0xf8) +
               *(float *)(param_1 + 0xfc) * *(float *)(param_1 + 0xfc));
  if (0.0 < fVar8) {
    fVar8 = 1.0 / fVar8;
  }
  *(float *)(param_1 + 0xf8) = *(float *)(param_1 + 0xf8) * fVar8;
  *(float *)(param_1 + 0xfc) = *(float *)(param_1 + 0xfc) * fVar8;
  *(float *)(param_1 + 0x100) = *(float *)(param_1 + 0x100) * fVar8;
  *(float *)(param_1 + 0x104) =
       *(float *)(param_1 + 0x150) * *(float *)(param_1 + 0x100) +
       *(float *)(param_1 + 0x148) * *(float *)(param_1 + 0xf8) +
       *(float *)(param_1 + 0x14c) * *(float *)(param_1 + 0xfc);
  *(char *)(param_1 + 0x108) = (char)((int)*(u32 *)(param_1 + 0xf8) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0x109) = (char)((int)*(u32 *)(param_1 + 0xfc) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0x10a) = (char)((int)*(u32 *)(param_1 + 0x100) >> 0x1f) + '\x01';
  return;
}
// FUN_004C9270 NONMATCHING
u64 FUN_004c9270(u64 param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + 4);
  fVar6 = *(float *)(iVar2 + 0x70) * -0.5;
  fVar4 = *(float *)(iVar1 + 0x58);
  fVar7 = 0.5 - fVar6 * *(float *)(iVar2 + 0x78);
  fVar3 = *(float *)(iVar1 + 0x78);
  fVar8 = *(float *)(iVar1 + 0x70) * fVar7 + *(float *)(iVar1 + 0x50) * fVar6 + 0.0;
  fVar5 = *(float *)(iVar1 + 0x74) * fVar7 + *(float *)(iVar1 + 0x54) * fVar6 + 0.0;
  *(float *)(iVar2 + 0x20) = fVar8;
  fVar3 = fVar3 * fVar7 + fVar4 * fVar6 + 0.0;
  *(float *)(iVar2 + 0x30) = fVar5;
  *(float *)(iVar2 + 0x40) = fVar3;
  *(float *)(iVar2 + 0x50) =
       0.5 - (fVar7 + *(float *)(iVar1 + 0x88) * fVar3 +
                      *(float *)(iVar1 + 0x80) * fVar8 + *(float *)(iVar1 + 0x84) * fVar5);
  fVar4 = *(float *)(iVar1 + 0x68);
  fVar7 = *(float *)(iVar2 + 0x74) * -0.5;
  fVar6 = fVar7 * *(float *)(iVar2 + 0x7c) + 0.5;
  fVar8 = *(float *)(iVar1 + 0x70) * fVar6 + *(float *)(iVar1 + 0x60) * fVar7 + 0.0;
  fVar3 = *(float *)(iVar1 + 0x78);
  fVar5 = *(float *)(iVar1 + 0x74) * fVar6 + *(float *)(iVar1 + 100) * fVar7 + 0.0;
  *(float *)(iVar2 + 0x24) = fVar8;
  fVar3 = fVar3 * fVar6 + fVar4 * fVar7 + 0.0;
  *(float *)(iVar2 + 0x34) = fVar5;
  *(float *)(iVar2 + 0x44) = fVar3;
  *(float *)(iVar2 + 0x54) =
       0.5 - (fVar6 + *(float *)(iVar1 + 0x88) * fVar3 +
                      *(float *)(iVar1 + 0x80) * fVar8 + *(float *)(iVar1 + 0x84) * fVar5);
  *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar1 + 0x70);
  *(u32 *)(iVar2 + 0x38) = *(u32 *)(iVar1 + 0x74);
  *(u32 *)(iVar2 + 0x48) = *(u32 *)(iVar1 + 0x78);
  *(float *)(iVar2 + 0x58) =
       -(*(float *)(iVar1 + 0x88) * *(float *)(iVar1 + 0x78) +
        *(float *)(iVar1 + 0x80) * *(float *)(iVar1 + 0x70) +
        *(float *)(iVar1 + 0x84) * *(float *)(iVar1 + 0x74));
  FUN_004c2d20(iVar2 + 0x20,0);
  return param_1;
}
// FUN_004C9400 NONMATCHING
void FUN_004c9400(int param_1)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float fVar4;
  u32 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  u32 uVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  
  pfVar3 = (float *)(param_1 + 0x124);
  iVar1 = *(int *)(param_1 + 4);
  fVar13 = *(float *)(param_1 + 0x68);
  fVar11 = *(float *)(param_1 + 0x80);
  pfVar2 = (float *)(param_1 + 0x94);
  fVar10 = *(float *)(param_1 + 0x6c);
  fVar6 = *(float *)(param_1 + 0x84);
  *(float *)(param_1 + 0x150) = fVar11;
  *(float *)(param_1 + 0x144) = fVar11;
  *(float *)(param_1 + 0x138) = fVar11;
  *(float *)(param_1 + 300) = fVar11;
  *(float *)(param_1 + 0x180) = fVar6;
  *(float *)(param_1 + 0x174) = fVar6;
  *(float *)(param_1 + 0x168) = fVar6;
  *(float *)(param_1 + 0x15c) = fVar6;
  fVar7 = (1.0 - fVar11) * -*(float *)(param_1 + 0x78);
  fVar4 = (1.0 - fVar6) * -*(float *)(param_1 + 0x78);
  fVar12 = fVar13 + fVar7;
  *(float *)(param_1 + 0x148) = fVar12;
  fVar8 = (1.0 - fVar11) * *(float *)(param_1 + 0x7c);
  fVar6 = (1.0 - fVar6) * *(float *)(param_1 + 0x7c);
  fVar7 = -fVar13 + fVar7;
  fVar11 = fVar13 + fVar4;
  *(float *)(param_1 + 0x124) = fVar12;
  *(float *)(param_1 + 0x13c) = fVar7;
  *(float *)(param_1 + 0x130) = fVar7;
  *(float *)(param_1 + 0x178) = fVar11;
  *(float *)(param_1 + 0x154) = fVar11;
  fVar4 = -fVar13 + fVar4;
  *(float *)(param_1 + 0x16c) = fVar4;
  *(float *)(param_1 + 0x160) = fVar4;
  fVar4 = fVar10 + fVar8;
  *(float *)(param_1 + 0x134) = fVar4;
  *(float *)(param_1 + 0x128) = fVar4;
  fVar8 = -fVar10 + fVar8;
  fVar4 = fVar10 + fVar6;
  *(float *)(param_1 + 0x14c) = fVar8;
  *(float *)(param_1 + 0x140) = fVar8;
  *(float *)(param_1 + 0x164) = fVar4;
  fVar6 = -fVar10 + fVar6;
  *(float *)(param_1 + 0x158) = fVar4;
  *(float *)(param_1 + 0x17c) = fVar6;
  *(float *)(param_1 + 0x170) = fVar6;
  FUN_004c6c20((u64)(unsigned int)(pfVar3));
  uVar9 = *(u32 *)(iVar1 + 0x74);
  uVar5 = *(u32 *)(iVar1 + 0x78);
  *pfVar2 = *(float *)(iVar1 + 0x70);
  *(u32 *)(param_1 + 0x98) = uVar9;
  *(u32 *)(param_1 + 0x9c) = uVar5;
  *(float *)(param_1 + 0xa0) =
       *(float *)(param_1 + 0x15c) * *(float *)(param_1 + 0x9c) +
       *(float *)(param_1 + 0x154) * *pfVar2 +
       *(float *)(param_1 + 0x158) * *(float *)(param_1 + 0x98);
  *(char *)(param_1 + 0xa4) = (char)((int)*pfVar2 >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xa5) = (char)((int)*(u32 *)(param_1 + 0x98) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xa6) = (char)((int)*(u32 *)(param_1 + 0x9c) >> 0x1f) + '\x01';
  *(float *)(param_1 + 0xa8) = -*pfVar2;
  *(float *)(param_1 + 0xac) = -*(float *)(param_1 + 0x98);
  *(float *)(param_1 + 0xb0) = -*(float *)(param_1 + 0x9c);
  *(float *)(param_1 + 0xb4) =
       *(float *)(param_1 + 300) * *(float *)(param_1 + 0xb0) +
       *pfVar3 * *(float *)(param_1 + 0xa8) +
       *(float *)(param_1 + 0x128) * *(float *)(param_1 + 0xac);
  *(char *)(param_1 + 0xb8) = (char)((int)*(u32 *)(param_1 + 0xa8) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xb9) = (char)((int)*(u32 *)(param_1 + 0xac) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xba) = (char)((int)*(u32 *)(param_1 + 0xb0) >> 0x1f) + '\x01';
  fVar4 = *(float *)(param_1 + 0x130) - *(float *)(param_1 + 0x160);
  fVar8 = *(float *)(param_1 + 0x16c) - *(float *)(param_1 + 0x160);
  fVar6 = *(float *)(param_1 + 0x138) - *(float *)(param_1 + 0x168);
  fVar7 = *(float *)(param_1 + 0x134) - *(float *)(param_1 + 0x164);
  fVar10 = *(float *)(param_1 + 0x170) - *(float *)(param_1 + 0x164);
  fVar11 = *(float *)(param_1 + 0x174) - *(float *)(param_1 + 0x168);
  *(float *)(param_1 + 0xbc) = fVar7 * fVar11 - fVar6 * fVar10;
  *(float *)(param_1 + 0xc0) = fVar6 * fVar8 - fVar4 * fVar11;
  *(float *)(param_1 + 0xc4) = fVar4 * fVar10 - fVar7 * fVar8;
  fVar11 = SQRT(*(float *)(param_1 + 0xc4) * *(float *)(param_1 + 0xc4) +
                *(float *)(param_1 + 0xbc) * *(float *)(param_1 + 0xbc) +
                *(float *)(param_1 + 0xc0) * *(float *)(param_1 + 0xc0));
  if (0.0 < fVar11) {
    fVar11 = 1.0 / fVar11;
  }
  *(float *)(param_1 + 0xbc) = *(float *)(param_1 + 0xbc) * fVar11;
  *(float *)(param_1 + 0xc0) = *(float *)(param_1 + 0xc0) * fVar11;
  *(float *)(param_1 + 0xc4) = *(float *)(param_1 + 0xc4) * fVar11;
  *(float *)(param_1 + 200) =
       *(float *)(param_1 + 0x138) * *(float *)(param_1 + 0xc4) +
       *(float *)(param_1 + 0x130) * *(float *)(param_1 + 0xbc) +
       *(float *)(param_1 + 0x134) * *(float *)(param_1 + 0xc0);
  *(char *)(param_1 + 0xcc) = (char)((int)*(u32 *)(param_1 + 0xbc) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xcd) = (char)((int)*(u32 *)(param_1 + 0xc0) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xce) = (char)((int)*(u32 *)(param_1 + 0xc4) >> 0x1f) + '\x01';
  fVar11 = *(float *)(param_1 + 0x158) - *(float *)(param_1 + 0x164);
  fVar8 = *(float *)(param_1 + 0x15c) - *(float *)(param_1 + 0x168);
  fVar10 = *(float *)(param_1 + 0x154) - *(float *)(param_1 + 0x160);
  *(float *)(param_1 + 0xd0) = fVar11 * fVar6 - fVar8 * fVar7;
  *(float *)(param_1 + 0xd4) = fVar8 * fVar4 - fVar10 * fVar6;
  *(float *)(param_1 + 0xd8) = fVar10 * fVar7 - fVar11 * fVar4;
  fVar4 = SQRT(*(float *)(param_1 + 0xd8) * *(float *)(param_1 + 0xd8) +
               *(float *)(param_1 + 0xd0) * *(float *)(param_1 + 0xd0) +
               *(float *)(param_1 + 0xd4) * *(float *)(param_1 + 0xd4));
  if (0.0 < fVar4) {
    fVar4 = 1.0 / fVar4;
  }
  *(float *)(param_1 + 0xd0) = *(float *)(param_1 + 0xd0) * fVar4;
  *(float *)(param_1 + 0xd4) = *(float *)(param_1 + 0xd4) * fVar4;
  *(float *)(param_1 + 0xd8) = *(float *)(param_1 + 0xd8) * fVar4;
  *(float *)(param_1 + 0xdc) =
       *(float *)(param_1 + 0x138) * *(float *)(param_1 + 0xd8) +
       *(float *)(param_1 + 0x130) * *(float *)(param_1 + 0xd0) +
       *(float *)(param_1 + 0x134) * *(float *)(param_1 + 0xd4);
  *(char *)(param_1 + 0xe0) = (char)((int)*(u32 *)(param_1 + 0xd0) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xe1) = (char)((int)*(u32 *)(param_1 + 0xd4) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xe2) = (char)((int)*(u32 *)(param_1 + 0xd8) >> 0x1f) + '\x01';
  *(float *)(param_1 + 0xe4) = -*(float *)(param_1 + 0xbc);
  *(float *)(param_1 + 0xe8) = -*(float *)(param_1 + 0xc0);
  *(float *)(param_1 + 0xec) = -*(float *)(param_1 + 0xc4);
  *(float *)(param_1 + 0xf0) =
       *(float *)(param_1 + 0x150) * *(float *)(param_1 + 0xec) +
       *(float *)(param_1 + 0x148) * *(float *)(param_1 + 0xe4) +
       *(float *)(param_1 + 0x14c) * *(float *)(param_1 + 0xe8);
  *(char *)(param_1 + 0xf4) = (char)((int)*(u32 *)(param_1 + 0xe4) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xf5) = (char)((int)*(u32 *)(param_1 + 0xe8) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0xf6) = (char)((int)*(u32 *)(param_1 + 0xec) >> 0x1f) + '\x01';
  *(float *)(param_1 + 0xf8) = -*(float *)(param_1 + 0xd0);
  *(float *)(param_1 + 0xfc) = -*(float *)(param_1 + 0xd4);
  *(float *)(param_1 + 0x100) = -*(float *)(param_1 + 0xd8);
  *(float *)(param_1 + 0x104) =
       *(float *)(param_1 + 0x150) * *(float *)(param_1 + 0x100) +
       *(float *)(param_1 + 0x148) * *(float *)(param_1 + 0xf8) +
       *(float *)(param_1 + 0x14c) * *(float *)(param_1 + 0xfc);
  *(char *)(param_1 + 0x108) = (char)((int)*(u32 *)(param_1 + 0xf8) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0x109) = (char)((int)*(u32 *)(param_1 + 0xfc) >> 0x1f) + '\x01';
  *(char *)(param_1 + 0x10a) = (char)((int)*(u32 *)(param_1 + 0x100) >> 0x1f) + '\x01';
  return;
}
// FUN_004C9940 NONMATCHING
u64 FUN_004c9940(u64 param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + 4);
  fVar5 = *(float *)(iVar2 + 0x70) * -0.5;
  fVar4 = *(float *)(iVar1 + 0x58);
  fVar8 = -(fVar5 * *(float *)(iVar2 + 0x78));
  fVar6 = *(float *)(iVar1 + 0x70) * fVar8 + *(float *)(iVar1 + 0x50) * fVar5;
  fVar3 = *(float *)(iVar1 + 0x78);
  fVar7 = *(float *)(iVar1 + 0x74) * fVar8 + *(float *)(iVar1 + 0x54) * fVar5 + 0.0;
  *(float *)(iVar2 + 0x20) = fVar6;
  fVar3 = fVar3 * fVar8 + fVar4 * fVar5 + 0.0;
  *(float *)(iVar2 + 0x30) = fVar7;
  *(float *)(iVar2 + 0x40) = fVar3;
  *(float *)(iVar2 + 0x50) =
       0.5 - (fVar8 + *(float *)(iVar1 + 0x88) * fVar3 +
                      *(float *)(iVar1 + 0x80) * fVar6 + *(float *)(iVar1 + 0x84) * fVar7);
  fVar4 = *(float *)(iVar1 + 0x68);
  fVar5 = *(float *)(iVar2 + 0x74) * -0.5;
  fVar8 = fVar5 * *(float *)(iVar2 + 0x7c);
  fVar6 = *(float *)(iVar1 + 0x70) * fVar8 + *(float *)(iVar1 + 0x60) * fVar5;
  fVar3 = *(float *)(iVar1 + 0x78);
  fVar7 = *(float *)(iVar1 + 0x74) * fVar8 + *(float *)(iVar1 + 100) * fVar5 + 0.0;
  *(float *)(iVar2 + 0x24) = fVar6;
  fVar3 = fVar3 * fVar8 + fVar4 * fVar5 + 0.0;
  *(float *)(iVar2 + 0x34) = fVar7;
  *(float *)(iVar2 + 0x44) = fVar3;
  *(float *)(iVar2 + 0x54) =
       0.5 - (fVar8 + *(float *)(iVar1 + 0x88) * fVar3 +
                      *(float *)(iVar1 + 0x80) * fVar6 + *(float *)(iVar1 + 0x84) * fVar7);
  *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar1 + 0x70);
  *(u32 *)(iVar2 + 0x38) = *(u32 *)(iVar1 + 0x74);
  *(u32 *)(iVar2 + 0x48) = *(u32 *)(iVar1 + 0x78);
  *(float *)(iVar2 + 0x58) =
       -(*(float *)(iVar1 + 0x88) * *(float *)(iVar1 + 0x78) +
        *(float *)(iVar1 + 0x80) * *(float *)(iVar1 + 0x70) +
        *(float *)(iVar1 + 0x84) * *(float *)(iVar1 + 0x74));
  FUN_004c2d20(iVar2 + 0x20,0);
  return param_1;
}
// FUN_004C9AD0 NONMATCHING
u64 FUN_004c9ad0(u64 param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x14) == 1) {
    FUN_004c9270(0);
    FUN_004c8a60(param_1);
  }
  else {
    FUN_004c9940(0);
    FUN_004c9400(param_1);
  }
  FUN_004c7a50((u64)(iVar1 + 0x10c),(float *)(iVar1 + 0x124),8);
  return param_1;
}
// FUN_004C9BA0 NONMATCHING
u64 FUN_004c9ba0(u64 param_1)

{
  long lVar1;
  
  DAT_00960070 = (u32 *)((u32)param_1);
  FUN_004cf340();
  lVar1 = (*DAT_009600bc)(0,param_1,0);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  else {
    FUN_004f28e0(param_1);
  }
  return param_1;
}
// FUN_004C9C00 NONMATCHING
u64 FUN_004c9c00(u64 param_1)

{
  if (*(int *)((int)&DAT_00960070 + iGpffffbc30) != 0) {
    FUN_004c3c30(0);
    *(u32 *)((int)&DAT_00960070 + iGpffffbc30) = 0;
  }
  iGpffffbc34 = iGpffffbc34 + -1;
  return param_1;
}
// FUN_004C9C70 NONMATCHING
u64 FUN_004c9c70(u64 param_1,int param_2)

{
  int iVar1;
  
  iGpffffbc30 = (u8 *)(param_2);
  iVar1 = thunk_FUN_004c3970(DAT_0077e5e0,uGpffffb074,0x10,uGpffffb078,0x960040,0x40005);
  *(int *)((int)&DAT_00960070 + iGpffffbc30) = iVar1;
  if (*(int *)((int)&DAT_00960070 + iGpffffbc30) == 0) {
    param_1 = 0;
  }
  else {
    iGpffffbc34 = iGpffffbc34 + 1;
  }
  return param_1;
}
// FUN_004C9D20 NONMATCHING
u64 FUN_004c9d20(u64 param_1,u32 *param_2)

{
  int iVar1;
  u32 uVar2;
  
  uVar2 = param_2[1];
  iVar1 = (int)param_1;
  *(u32 *)(iVar1 + 0x78) = *param_2;
  *(u32 *)(iVar1 + 0x7c) = uVar2;
  if (*(int *)(iVar1 + 4) != 0) {
    FUN_004cb270();
  }
  return param_1;
}
// FUN_004C9D70 NONMATCHING
u64 FUN_004c9d70(u32 param_1,u64 param_2)

{
  *(u32 *)((int)param_2 + 0x80) = param_1;
  FUN_004c89a0(0);
  if (*(int *)((int)param_2 + 4) != 0) {
    FUN_004cb270();
  }
  return param_2;
}
// FUN_004C9DB0 NONMATCHING
u64 FUN_004c9db0(u32 param_1,u64 param_2)

{
  *(u32 *)((int)param_2 + 0x84) = param_1;
  FUN_004c89a0(0);
  if (*(int *)((int)param_2 + 4) != 0) {
    FUN_004cb270();
  }
  return param_2;
}
// FUN_004C9ED0 NONMATCHING
u64 FUN_004c9ed0(u64 param_1)

{
  long lVar1;
  
  lVar1 = FUN_004cdfe0(*(u32 *)((int)param_1 + 0x60));
  if (lVar1 == 0) {
    param_1 = 0;
  }
  return param_1;
}
// FUN_004CA000 NONMATCHING
void FUN_004ca000(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5)

{
  FUN_004c61b0((int *)0x77e5e0,param_1,param_2,param_3,param_4,param_5);
  return;
}
// FUN_004CA030 NONMATCHING
u32 FUN_004ca030(u64 param_1)

{
  FUN_004c6560(0x77e5e0,param_1);
  FUN_004d18c0(param_1);
  (*DAT_0096018c)(*(u32 *)((int)&DAT_00960070 + iGpffffbc30),param_1);
  return 1;
}
// FUN_004CA090 NONMATCHING
long FUN_004ca090(void)

{
  long lVar1;
  u8 *puVar2;
  
  lVar1 = (*DAT_00960188)(*(u32 *)((int)&DAT_00960070 + iGpffffbc30),0x30005);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else {
    puVar2 = (u8 *)lVar1;
    *puVar2 = 4;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    *(u32 *)(puVar2 + 4) = 0;
    *(code **)(puVar2 + 0x10) = (code *)FUN_004c9ad0;
    *(code **)(puVar2 + 0x18) = (code *)FUN_004c9ba0;
    *(code **)(puVar2 + 0x1c) = (code *)FUN_004c9b40;
    *(u32 *)(puVar2 + 0x6c) = 0x3f800000;
    *(u32 *)(puVar2 + 0x68) = 0x3f800000;
    *(u32 *)(puVar2 + 0x74) = 0x3f800000;
    *(u32 *)(puVar2 + 0x70) = 0x3f800000;
    *(u32 *)(puVar2 + 0x7c) = 0;
    *(u32 *)(puVar2 + 0x78) = 0;
    *(u32 *)(puVar2 + 0x80) = 0x3d4ccccd;
    *(u32 *)(puVar2 + 0x84) = 0x41200000;
    *(u32 *)(puVar2 + 0x88) = 0x40a00000;
    *(u32 *)(puVar2 + 0x60) = 0;
    *(u32 *)(puVar2 + 100) = 0;
    *(u32 *)(puVar2 + 0x14) = 1;
    FUN_004c89a0(lVar1);
    *(u32 *)(puVar2 + 0x2c) = 0;
    FUN_004c64b0(0x77e5e0,lVar1);
  }
  return lVar1;
}
// FUN_004CA190 NONMATCHING
bool FUN_004ca190(void)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar9;
  u32 uVar10;
  u32 uVar11;
  u32 uVar12;
  u32 uVar13;
  u32 uVar14;
  u32 uVar15;
  
  uVar1 = (u32)((code)FUN_004ca520)(8,0x40f,0x4c1c00,0x4c1c30);
  uVar2 = (u32)((code)FUN_004ca520)(0x18,0x401,0x4c6d00,0x4c6ce0);
  uVar3 = (u32)((code)FUN_004ca520)(0,0x40d,0x4c1bc0,0x4c1be0);
  uVar4 = (u32)((code)FUN_004ca520)(0x18,0x402,0x4c2c00,0x4c2b90);
  uVar5 = (u32)((code)FUN_004ca520)(4,0x403,0x4ca9b0,0x4caa50);
  uVar6 = (u32)((code)FUN_004ca520)(4,0x404,0x4c4eb0,0x4c4f30);
  uVar7 = (u32)((code)FUN_004ca520)(4,0x405,0x4c9c70,0x4c9c00);
  uVar8 = (u32)((code)FUN_004ca520)(0x220,0x406,0x4cba20,0x4cbc70);
  uVar9 = (u32)((code)FUN_004ca520)(100,0x407,0x4ce2c0,0x4ce250);
  uVar10 = (u32)((code)FUN_004ca520)(0x34,0x408,0x4d15e0,0x4d1420);
  uVar11 = (u32)((code)FUN_004ca520)(0x60,0x409,0x4f2870,0x4f28a0);
  uVar12 = (u32)((code)FUN_004ca520)(4,0x412,0x4c7020,0x4c70a0);
  uVar13 = FUN_004f28d0();
  uVar14 = (u32)((code)FUN_004ca520)(0x7c,0x40a,0x4f2790,0x4f2730);
  uVar15 = (u32)((code)FUN_004ca520)(0x28,0x40b,0x4c46f0,0x4c4750);
  return -1 < (long)(uVar1 | uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10
                     | uVar11 | uVar12 | uVar13 | uVar14 | uVar15);
}
// FUN_004CA3E0 NONMATCHING
u32 FUN_004ca3e0(int param_1,u64 param_2,u64 param_3,u64 param_4,long param_5
                  )

{
  u32 uVar1;
  u32 uStack_8;
  u32 uStack_4;
  
  uVar1 = (**(code **)(param_1 + 4))(param_2,param_3,param_4,param_5);
  if (uVar1 == 0) {
    switch((int)param_2) {
    case 0xd:
      uVar1 = 1;
      *(u32 *)param_3 = 1;
      break;
    case 0xe:
      uVar1 = (u32)(param_5 == 0);
      if (uVar1 != 0) {
        (*DAT_0096013c)(param_3,0x77e650);
      }
      break;
    case 0xf:
      *(u32 *)param_3 = 0;
      uVar1 = 1;
      break;
    case 0x10:
      uVar1 = (u32)(param_5 == 0);
      break;
    case 0x11:
    case 0x12:
      uVar1 = 1;
    }
  }
  if (uVar1 == 0) {
    uStack_8 = 1;
    uStack_4 = ((code)FUN_004c1d10)(0x18,param_2);
    FUN_004c1c50((u64)(unsigned int)(&uStack_8));
  }
  return uVar1;
}
#pragma optimization_level 3
// FUN_004CA500
u32 FUN_004ca500(void)

{
  return uGpffffbc38;
}
#pragma optimization_level 3
// FUN_004CA510
u32 FUN_004ca510(void)

{
  return 0x37002;
}
// FUN_004CA520
void FUN_004ca520(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  FUN_004c61b0_raw((int *)(DAT_00780000 - 0x19d0),param_1,param_2,param_3,param_4,0);
  return;
}
// FUN_004CA550
void FUN_004ca550(int param_1)
{
  FUN_004c6170((int)(DAT_00780000 - 0x19d0),param_1);
}
// FUN_004CA560 NONMATCHING
u64 FUN_004ca560(u64 param_1,u64 param_2)

{
  long lVar1;
  
  lVar1 = FUN_004ca3e0(0x960080,6,param_1,0,param_2);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  return param_1;
}
// FUN_004CA5B0 NONMATCHING
u32 FUN_004ca5b0(void)

{
  long lVar1;
  u32 uStack_4;
  
  lVar1 = (u64)(FUN_004ca3e0(0x960080,10,(u64)(unsigned int)(&uStack_4),0,0));
  if (lVar1 == 0) {
    uStack_4 = 0xffffffff;
  }
  return uStack_4;
}
// FUN_004CA600
bool FUN_004ca600(u64 param_1)

{
  u8 *p;
  u32 uVar1;
  
  p = &DAT_00960080[0];
  uVar1 = FUN_004ca3e0((int)p,7,0,0,param_1);
  return uVar1 != 0;
}
// FUN_004CA640 NONMATCHING
u32 FUN_004ca640(void)

{
  long lVar1;
  
  lVar1 = FUN_004ca3e0(0x960080,2,0,0,0);
  if (lVar1 != 0) {
    lVar1 = FUN_004c64b0(0x77e630,0x960070);
    if (lVar1 != 0) {
      FUN_004cdb50(DAT_00960080);
      FUN_004ca3e0(0x960080,0x11,0,0,0);
      DAT_00960194 = 3;
      return 1;
    }
    FUN_004ca3e0(0x960080,3,0,0,0);
  }
  return 0;
}
// FUN_004CA700 NONMATCHING
bool FUN_004ca700(long param_1)

{
  long lVar1;
  long lVar2;
  bool bVar3;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  if (DAT_00960194 == 1) {
    if (param_1 == 0) {
      uStack_8 = 1;
      uStack_4 = FUN_004c1d10(0xffffffff80000016);
      FUN_004c1c50((u64)(unsigned int)(&uStack_8));
      bVar3 = false;
    }
    else {
      lVar1 = FUN_004e2f00();
      bVar3 = false;
      if (lVar1 != 0) {
        FUN_004ca3e0(lVar1,4,0x960080,0x960178,0);
        lVar2 = FUN_004ca3e0(lVar1,0,0,param_1,0);
        bVar3 = lVar2 != 0;
        if (bVar3) {
          FUN_004ca3e0(lVar1,0xb,0x9600b8,0,0x1d);
          iGpffffbc38 = iGpffffbc38 + 1;
          DAT_00960194 = 2;
        }
      }
    }
  }
  else {
    uStack_10 = 1;
    uStack_c = FUN_004c1d10(0xffffffff80000001);
    FUN_004c1c50((u64)(unsigned int)(&uStack_10));
    bVar3 = false;
  }
  return bVar3;
}
// FUN_004ca850 NONMATCHING
RwBool RwEngineInit(const RwMemoryFunctions* memFuncs, RwUInt32 flags, RwUInt32 resArenaSize)
{
    if ((flags & 1) == 0)
    {
        rwGlobals.internalMalloc = func_004c3d10;
        rwGlobals.internalFree = func_004c3ee0;
        func_004c3960(true);
    }
    else
    {
        rwGlobals.internalMalloc = func_004ca380;
        rwGlobals.internalFree = func_004ca3a0;
        func_004c3960(false);
    }

    rwGlobals.resArenaSize = resArenaSize;
    if (rwGlobals.engineInitialized != false)
    {
        return false;
    }
    if (!func_004c72e0())
    {
        return false;
    }
    if (!func_004c4450(memFuncs))
    {
        func_004c7400();
        return false;
    }
    if (!func_004c5f70())
    {
        func_004c4570();
        func_004c7400();
        return false;
    }
    if (!func_004ca190())
    {
        func_004c6000();
        func_004c4570();
        func_004c7400();
        return false;
    }
    if (!func_004e00e0())
    {
        func_004c6000();
        func_004c4570();
        func_004c7400();
        return false;
    }

    rwGlobals.engineInitialized = true;
    return true;
}
