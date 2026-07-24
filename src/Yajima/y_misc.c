#include "Yajima/y_misc.h"
typedef struct YajimaVec2 {
    f32 x;
    f32 y;
} YajimaVec2;
typedef struct YajimaVec3 {
    f32 x;
    f32 y;
    f32 z;
} YajimaVec3;
typedef int (*code)(...);
char cGpffffb9d4;
char cGpffffb9d8;
char cGpffffb9ec;
int iGpffffb5c0;
int *piGpffffa850;
u32 uGpffffb9ec;
u32 uGpffffb9f4;
extern u8 cGpffffb9c0;
extern u8* iGpffffb9b8;
static inline uintptr_t Yajima_AddOffsetFirst(uintptr_t offset, uintptr_t base)
{
  return offset + base;
}

/* FUSION_EXACT_PROTOS */
u16 func_00170a40(s16 pcId, s16 index);
s16 func_00170ab0(s16 pcId, s16 index);
void func_00170b20(s16 pcId, s16 index, u16 value);
void func_00170b90(s16 pcId, s16 index, u16 value);
s32 func_0016f490(s16 pcId);
u16 datGetEquipmentId(s16 pcId, s32 equipmentIdx);
u32 FUN_00421de0(s8 param_1, s8 param_2, s8 param_3, s8 param_4, s8 param_5);
u32 FUN_00424230(void);
u8 FUN_004242b0(void);
u32 FUN_00424310(void);
u32 FUN_00424370(void);
u32 FUN_004243d0(void);
u32 FUN_00424470(void);
u32 FUN_00424480(void);
u32 FUN_004244a0(void);
u32 FUN_004244e0(void);
u32 FUN_004245c0(void);
u32 FUN_00424730(void);
u32 FUN_00424880(void);
u32 FUN_004249b0(void);
u32 FUN_00424b60(void);
u32 FUN_00424f10(void);
void FUN_00424f80(void);
u32 FUN_00425020(void);
u32 FUN_00425070(void);
u32 FUN_004250b0(void);
u32 FUN_004250e0(void);
u32 FUN_00425190(void);
u32 FUN_00425220(void);
u32 FUN_00425270(void);
u32 FUN_004252a0(void);
u32 FUN_004252d0(void);
u32 FUN_00425320(void);
u32 FUN_00425360(void);
u32 FUN_004253d0(void);
u32 FUN_00425480(void);
u32 FUN_004254c0(void);
u32 FUN_00425530(void);
u32 FUN_00425580(void);
u32 FUN_004255d0(void);
u32 FUN_00425640(void);
u32 FUN_00425690(int param_1);
void FUN_00425ba0(int param_1);
u32 FUN_00425c60(u64 param_1,u8 param_2);
void FUN_00425d10(int param_1,u8 param_2);
void FUN_00425d30(int param_1,u8 param_2,u8 param_3);
u32 FUN_00425d50(u8 param_1,u8 param_2);
void FUN_00426040(int param_1,u8 param_2);
void FUN_00426050(int param_1);
u8 FUN_00426070(int param_1);
u32 * FUN_00426090(void);
u64 FUN_004260a0(int param_1);
void FUN_004264a0(int param_1);
u32 FUN_004264d0(u64 param_1,s8 param_2);
u32 FUN_00426590(int param_1);
void FUN_00427640(int param_1);
u32 FUN_00427670(u32 param_1,u32 param_2,u64 param_3,u32 param_4, char param_5,u8 param_6);
u64 FUN_00427830(u32 param_1,u64 param_2,u32 param_3,u64 param_4, u32 param_5,int param_6,u32 *param_7,u8 param_8);
u64 FUN_00427a10(u32 param_1,u64 param_2,u32 param_3,u64 param_4, u32 param_5,int param_6,u32 *param_7,u8 param_8);
u64 FUN_00427bf0(u32 param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u64 param_6,u32 param_7,u64 param_8, u32 param_9,u32 *param_10);
void FUN_00427db0(int object, YajimaVec2 value);
void FUN_00427de0(int param_1,u8 param_2,u8 param_3,u8 param_4, u8 param_5);
void FUN_00427e20(float param_1,float param_2,int param_3);
void FUN_00427e50(int param_1,u8 param_2);
void FUN_00427e60(int param_1,u8 param_2);
void FUN_00427e70(float param_1,float param_2,float param_3,u32 param_4,int param_5,int param_6, u32 *param_7);
u32 FUN_004281f0(u32 param_1);
void FUN_00429c60(int param_1);
u64 FUN_00429d40(u64 param_1,u64 param_2);
void FUN_00429e80(int param_1,u8 param_2);
void FUN_00429e90(int param_1,u8 param_2);
float FUN_00429ef0(float param_1,char param_2);
float FUN_00429fe0(float param_1,char param_2);
float FUN_0042a0d0(float param_1,float *param_2);
float FUN_0042a180(float param_1,u32 *param_2);
float FUN_0042a230(float param_1,char param_2);
float FUN_0042a310(float param_1,char param_2);
float FUN_0042a3f0(float param_1,float *param_2);
float FUN_0042a4a0(float param_1,u32 *param_2);
void FUN_0042a550(int param_1,u64 param_2,u64 param_3,u64 param_4);
u8 FUN_0042aa40(int param_1,u32 param_2,u32 param_3);
void FUN_0042ac60(int param_1,u64 param_2);
void FUN_0042adb0(int param_1);
void FUN_0042b050(int param_1);
void FUN_0042b540(int param_1);
u8 FUN_0042ba30(void);
void FUN_0042ba50(u64 param_1);
void FUN_0042bc10(u64 param_1);
void FUN_0042bd80(u64 param_1);
#pragma alias FUN_0042bd80_typed FUN_0042bd80
extern void FUN_0042bd80_typed(u64 param_1);
void FUN_0042bfd0(u64 param_1);
void FUN_0042c0a0(int param_1,char param_2,short param_3,short param_4,int param_5,int param_6);
void FUN_0042cd80(int param_1);
void FUN_0042cfc0(int param_1,u16 param_2,u16 param_3,int param_4,int param_5);
void FUN_0042dd90(int param_1,short param_2,u16 param_3,int param_4,int param_5);
void FUN_0042ea60(int param_1,u16 param_2,u16 param_3,int param_4,int param_5);
void FUN_0042f440(int param_1,short param_2,short param_3,int param_4,int param_5);
void FUN_0042fd80(u32 *param_1,int param_2);
void FUN_004563b0(f32 value, int object);
int FUN_0044f120();
int FUN_0044f170();
/* FUSION_GLOBALS */
u32 DAT_0087190c;
u32 DAT_0095c0e0;
u32 DAT_006b44c0;
u32 DAT_006b44c8;
u32 DAT_006b44d0;
u32 DAT_006b44d8;
u32 DAT_006b44e0;
u32 DAT_006b44e8;
float DAT_007cb134;
float DAT_007cb138;
u32 DAT_007ce0cc;
u8 *DAT_007ce6a8;
u32 DAT_007ce6ac;
u8 DAT_007ce6b0;
u32 DAT_007ce6b4;
u32 DAT_007ce6b8;
u32 DAT_007ce6c4;
u32 DAT_007ce6c8;
u32 DAT_007ce6cc;
u32 DAT_007ce6d0;
u32 DAT_007ce6d4;
u32 DAT_007ce6d8;
u32 DAT_007ce6dc;
u32 DAT_007ce6e4;
u8 *DAT_007ce6ec;
#pragma alias DAT_007ce6ec_abs DAT_007ce6ec
extern u8 *DAT_007ce6ec_abs;
#pragma alias DAT_0086be00_abs DAT_0086be00
extern u8 DAT_0086be00_abs[];
#pragma alias DAT_0086be04_abs DAT_0086be04
extern u8 DAT_0086be04_abs[];
#pragma alias DAT_0086be0c_abs DAT_0086be0c
extern u8 DAT_0086be0c_abs[];
u32 DAT_007ce6f8;
u32 DAT_007e094c;
u32 DAT_007e0988;
u32 DAT_0086be00;
u32 DAT_0086be04;
u32 DAT_0086be08;
u32 DAT_0086be0c;
u32 DAT_0086be80;
u32 DAT_0086bf8c;
u32 DAT_0086bf90;
u32 DAT_0086bf94;
u32 DAT_0086e580;
u32 DAT_0086e684;
u32 DAT_0086e688;
u32 DAT_0086e68c;
extern u8 DAT_0086e6a0[];
u32 DAT_0086e80c;
u32 DAT_0086eda0;
#pragma alias DAT_0086eda0_abs DAT_0086eda0
extern u8 DAT_0086eda0_abs[];
u32 DAT_0086ede8;
u32 DAT_0086edf4;
#pragma alias DAT_0086edf4_abs DAT_0086edf4
extern u8 DAT_0086edf4_abs[];
u32 DAT_0086ef2c;
u32 DAT_008717a0;
u32 DAT_008717e8[];
#pragma alias DAT_008717e8_abs DAT_008717e8
extern u8 DAT_008717e8_abs[];
int DAT_008717f4[];
#pragma alias DAT_008717f4_abs DAT_008717f4
extern u8 DAT_008717f4_abs[];
u32 DAT_00871948;
u32 DAT_008719a8;
u32 DAT_008719b4;
u32 DAT_00871b08;
u32 DAT_00871b68;
u32 DAT_00871b74;
u32 DAT_00871cc8;
u32 DAT_00871d28;
u32 DAT_00871d34;
u32 DAT_00871e88;
u32 DAT_0095be9c;
u32 DAT_0095bea0;
u32 DAT_0095bea4;
u32 DAT_0095bea8;
u32 DAT_0095beac;
u32 DAT_0095beb0;
u32 DAT_0095beb4;
u32 DAT_0095bec0;
#pragma alias DAT_0095bea0_abs DAT_0095bea0
extern u8 DAT_0095bea0_abs[];
#pragma alias DAT_0095bec0_abs DAT_0095bec0
extern u8 DAT_0095bec0_abs[];
u32 DAT_0095bec4;
u32 DAT_0095bec8;
u32 DAT_0095becc;
u32 DAT_0095bed0;
u32 DAT_0095bed4;
u32 DAT_0095bee0;
u32 DAT_0095bfe0;
u8 DAT_0095c100[];
u8 DAT_0095c110[];
u8 DAT_0095c210[];
u32 DAT_00960088;
code DAT_00960090;
 #pragma alias DAT_00960090_abs DAT_00960090
 extern u8 DAT_00960090_abs[];
code DAT_009600a0;
extern code DAT_0096017c;
 #pragma alias DAT_0096017c_abs DAT_0096017c
extern code DAT_0096017c_abs[];
#pragma alias FUN_004264d0_u32 FUN_004264d0
extern u32 FUN_004264d0_u32(u32 param_1,s8 param_2);
code DAT_00960184;
extern char DAT_006b4400[];
#pragma alias DAT_00960184_abs DAT_00960184
extern code DAT_00960184_abs[];
u32 LAB_00425aec[];
u8 *PTR_DAT_007cd540;
/* FUSION_PROTOS */
#include "sce/eeregs.h"

// FUN_004241d0
u32 Y_Misc_GetT0Count()
{
    return DGET_T0_COUNT();
}

// HARVESTED 3D-42FF

// FUN_004241E0


void FUN_004241e0(u64 param_1,s8 *param_2)
{
  u32 uVar1;
  u32 *puVar2;
  uVar1 = FUN_00421de0(*param_2,param_2[1],param_2[2],param_2[3],param_2[4]);
  puVar2 = (u32 *)FUN_00421760();
  *puVar2 = uVar1;
  return;
}

// FUN_00424230


u32 FUN_00424230(void)
{
  int *piVar1;
  u32 *puVar2;
  u32 uVar3;
  piVar1 = (int *)FUN_00421760();
  if (*piVar1 != 0) {
    puVar2 = (u32 *)FUN_00421760();
    uVar3 = FUN_00421ef0(*puVar2);
    if (uVar3 == 1) {
      puVar2 = (u32 *)FUN_00421760();
      kwlnTaskDestroyWithHierarchy(*puVar2);
      puVar2 = (u32 *)FUN_00421760();
      *puVar2 = 0;
      return 0;
    }
  }
  return 0xffffffff;
}

// FUN_004242B0


u8 FUN_004242b0(void)
{
  u32 *puVar1;
  u32 uVar2;
  puVar1 = (u32 *)FUN_00421760();
  uVar2 = kwlnTaskExists(*puVar1);
  if (uVar2 == 1) {
    return 0;
  }
  puVar1 = (u32 *)FUN_00421760();
  *puVar1 = 0;
  return 1;
}

// FUN_00424310


u32 FUN_00424310(void)



{

  u8 auStack_8 [8];

  

  auStack_8[0] = scrGetIntPara(0);

  func_00109f60(4,0);

  adminiChangeSeq(4,auStack_8,5,0);

  return 1;

}

// FUN_00424370


u32 FUN_00424370(void)
{
  u8 uVar1;
  u32 uVar2;
  u32 *puVar3;

  uVar1 = scrGetIntPara(0);
  *(u8 *)(DAT_007ce6a8 + 6) = uVar1;
  uVar2 = FUN_004264d0_u32(0, *(s8 *)((u8 *)DAT_007ce6a8 + 6));
  puVar3 = FUN_00426090();
  *puVar3 = uVar2;
  return 1;
}

// FUN_004243D0


u32 FUN_004243d0(void)



{

  u8 uVar1;

  

  uVar1 = scrGetIntPara(0);

  *DAT_007ce6a8 = uVar1;

  uVar1 = scrGetIntPara(1);

  DAT_007ce6a8[1] = uVar1;

  uVar1 = scrGetIntPara(2);

  DAT_007ce6a8[2] = uVar1;

  uVar1 = scrGetIntPara(3);

  DAT_007ce6a8[3] = uVar1;

  uVar1 = scrGetIntPara(4);

  DAT_007ce6a8[4] = uVar1;

  uVar1 = scrGetIntPara(5);

  DAT_007ce6a8[5] = uVar1;

  DAT_007ce6b0 = 0;

  return 1;

}

// FUN_00424470
u32 FUN_00424470(void)
{
  u32 uVar1;

  uVar1 = 1;
  cGpffffb9c0 = uVar1;
  return uVar1;
}

// FUN_00424480
u32 FUN_00424480(void)
{
  return *(char *)(iGpffffb9b8 + 8) == 1;
}

// FUN_004244A0
u32 FUN_004244a0(void)
{
  u8 uVar1;

  uVar1 = scrGetIntPara(0);
  *(u8 *)(DAT_007ce6a8 + 10) = uVar1;
  iGpffffb9b8[9] = 1;
  return 1;
}

// FUN_004244E0


u32 FUN_004244e0(void)



{

  short sVar1;

  int iVar4;

  int lVar3;

  int iVar2;

  

  lVar3 = scrGetIntPara(0);

  if ((0 < lVar3) && (lVar3 < 0xc)) {

    iVar2 = func_0016f490((short)(lVar3 + 0x100));

    for (iVar4 = 0; iVar4 < 0x14; iVar4 = iVar4 + 1) {

      sVar1 = func_00170ab0((short)lVar3,(short)iVar4);

      if (0 < sVar1) {

        iVar2 = iVar2 + 1;

      }

    }

    scrSetIntReturnVal(iVar2);

  }
  else {
    scrSetIntReturnVal(0);
  }

  return 1;

}

// FUN_004245C0


u32 FUN_004245c0(void)
{
  int iVar4;
  int iVar5;
  int lVar6;
  int iVar8;
  u32 uVar7;
  u16 uVar2;
  short sVar3;

  uVar7 = 0xffffffffffffffff;
  lVar6 = scrGetIntPara(0);
  iVar4 = scrGetIntPara(1);
  if ((0 < lVar6) && (lVar6 < 0xc)) {
    iVar5 = func_0016f490(lVar6 + 0x100);
    if ((iVar4 < iVar5) && (0 < iVar5)) {
      uVar2 = datGetEquipmentId(lVar6 + 0x100,iVar4);
      scrSetIntReturnVal(uVar2);
      return 1;
    } else {
      for (iVar8 = 0; iVar8 < 0x14; iVar8 = iVar8 + 1) {
        sVar3 = func_00170ab0(lVar6,(short)iVar8);
        if (0 < sVar3) {
          if (iVar4 == iVar5) {
            uVar7 = func_00170a40(lVar6,(short)iVar8);
            uVar7 = uVar7 & 0xffff;
          }
          iVar5 = iVar5 + 1;
        }
      }
      scrSetIntReturnVal(uVar7);
    }
  } else {
    scrSetIntReturnVal(0);
  }
  return 1;
}

// FUN_00424730 NONMATCHING


u32 FUN_00424730(void)



{

  short sVar1;

  short sVar2;

  u16 uVar3;

  int iVar4;

  int iVar5;

  int lVar6;

  int iVar7;

  

  uVar3 = 0xffff;

  lVar6 = scrGetIntPara(0);

  iVar4 = scrGetIntPara(1);

  if ((lVar6 < 1) || (0xb < lVar6)) {

    scrSetIntReturnVal(0);

  }

  else {

    sVar1 = (short)lVar6;

    iVar5 = func_0016f490(sVar1 + 0x100);

    if ((iVar4 < iVar5) && (0 < iVar5)) {

      scrSetIntReturnVal(1);

    }

    else {

      for (iVar7 = 0; iVar7 < 0x14; iVar7 = iVar7 + 1) {

        sVar2 = func_00170ab0(sVar1,(short)iVar7);

        if (0 < sVar2) {

          if (iVar4 == iVar5) {

            uVar3 = func_00170ab0(sVar1,(short)iVar7);

          }

          iVar5 = iVar5 + 1;

        }

      }

      scrSetIntReturnVal(uVar3);

    }

  }

  return 1;

}

// FUN_00424880 NONMATCHING


u32 FUN_00424880(void)



{

  short sVar1;

  u8 uVar2;

  long lVar3;

  long lVar4;

  int iVar5;

  

  lVar3 = scrGetIntPara(0);

  lVar4 = scrGetIntPara(1);

  if ((lVar3 < 1) || (0xb < lVar3)) {

    scrSetIntReturnVal(0);

  }

  else {

    sVar1 = (short)lVar3;

    lVar3 = func_0016f490(sVar1 + 0x100);

    if ((lVar4 < lVar3) && (0 < lVar3)) {

      uVar2 = func_0016f810(sVar1 + 0x100,lVar4);

      scrSetIntReturnVal(uVar2);

    }

    else {

      for (iVar5 = 0; iVar5 < 0x14; iVar5 = iVar5 + 1) {

        func_00170ab0(sVar1,(short)iVar5);

      }

      scrSetIntReturnVal(0);

    }

  }

  return 1;

}

// FUN_004249B0 NONMATCHING


u32 FUN_004249b0(void)



{

  u8 bVar1;

  u32 uVar2;

  short sVar3;

  int iVar4;

  

  bVar1 = 0;

  uVar2 = scrGetIntPara(0);

  if ((0 < (long)uVar2) && ((long)uVar2 < 0xc)) {

    for (iVar4 = 0; iVar4 < 0x14; iVar4 = iVar4 + 1) {

      sVar3 = (short)uVar2;

      func_00170b20(sVar3,(short)iVar4,0);

      func_00170b90(sVar3,(short)iVar4,0);

      func_0016fea0(sVar3 + 0x100,iVar4,0);

    }

    bVar1 = 0;

    if ((DAT_008719a8 != 0 && DAT_008719b4 != 0) && (DAT_00871b08 == uVar2)) {

      DAT_007ce6cc = 0;

      bVar1 = 1;

    }

    if ((DAT_00871b68 != 0 && DAT_00871b74 != 0) && (DAT_00871cc8 == uVar2)) {

      DAT_007ce6d0 = 0;

      bVar1 = 1;

    }

    if ((DAT_00871d28 != 0 && DAT_00871d34 != 0) && (DAT_00871e88 == uVar2)) {

      DAT_007ce6d4 = 0;

      bVar1 = 1;

    }

  }

  if (!bVar1) {

    DAT_007ce6cc = 0;

    DAT_007ce6d0 = 0;

    DAT_007ce6d4 = 0;

  }

  return 1;

}

// FUN_00424B60 NONMATCHING


u32 FUN_00424b60(void)



{

  u8 bVar1;

  u8 bVar2;

  short sVar3;

  int iVar4;

  long lVar5;

  int iVar6;

  int iVar7;

  short sVar8;

  short unaff_s5_lo;

  u32 uStack_20;

  u32 uStack_1c;

  u32 uStack_18;

  u32 uStack_10;

  u32 uStack_c;

  u32 uStack_8;

  char acStack_4 [4];

  

  sVar8 = 2;

  bVar2 = 0;

  iVar7 = 0;

  FUN_0016f3e0(0,0);

  sVar3 = scrGetIntPara(0);

  for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {

    acStack_4[iVar6] = '\0';

    bVar1 = 0;

    if ((DAT_008717e8[iVar6 * 0x70] != 0) && (DAT_008717f4[iVar6 * 0x70] != 0)) {

      bVar1 = 1;

    }

    if ((bVar1) && ((long)sVar3 == (u32)*(u16 *)(&DAT_00871948 + iVar6 * 0x1c0))) {

      unaff_s5_lo = (short)iVar6;

    }

  }

  for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {

    bVar1 = 0;

    if ((DAT_008717e8[iVar6 * 0x70] != 0) && (DAT_008717f4[iVar6 * 0x70] != 0)) {

      bVar1 = 1;

    }

    if ((bVar1) &&

       (lVar5 = K_FldEvent_AreUnitsWithinDist(0x43fa0000,&DAT_008717a0 + unaff_s5_lo * 0x1c0), lVar5 == 1)) {

      sVar3 = FUN_0043a9d0((char)unaff_s5_lo,(char)iVar6,0);

      if (sVar3 != 2) {

        sVar8 = sVar3;

      }

      if ((sVar3 == 0) || (sVar3 == 1)) {

        bVar2 = 1;

        acStack_4[iVar6] = '\x01';

      }

      else if (sVar3 == 5) {

        for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {

          bVar1 = 0;

          if ((DAT_008717e8[iVar4 * 0x70] != 0) && (DAT_008717f4[iVar4 * 0x70] != 0)) {

            bVar1 = 1;

          }

          if ((bVar1) &&

             (lVar5 = K_FldEvent_AreUnitsWithinDist(0x43fa0000,&DAT_008717a0 + unaff_s5_lo * 0x1c0), lVar5 == 1)) {

            acStack_4[iVar4] = '\x01';

            bVar2 = 1;

          }

        }

      }

    }

  }

  for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {

    if (acStack_4[iVar6] == '\x01') {

      iVar7 = iVar7 + 1;

      K_FldFrame_CtlCopyPos(&uStack_20,*(u32 *)(DAT_008717f4[iVar6 * 0x70] + 0x1e0));

      uStack_10 = uStack_20;

      uStack_c = uStack_1c;

      uStack_8 = uStack_18;

      iVar4 = K_Field_Get();

      func_001a9760(*(u32 *)(iVar4 + 0x10),6,&uStack_10,3,1);

      FUN_0016f3e0(0,iVar7);

    }

  }

  if ((bVar2) && (sVar8 == 4)) {

    sVar8 = 0;

  }

  if (sVar8 == 5) {

    sVar8 = 1;

  }

  scrSetIntReturnVal(sVar8);

  return 1;

}

// FUN_00424F10


u32 FUN_00424f10(void)
{
  s16 uVar1;
  int iVar2;

  iVar2 = scrGetUnkF0();
  if (*(u16 *)(iVar2 + 0x1aa) == 0xfb5) {
    uVar1 = 0;
    goto done;
  }
  if ((*(u16 *)(iVar2 + 0x1ac) & 1) != 0) {
    uVar1 = 1;
    goto done;
  }
  uVar1 = 2;
done:
  scrSetIntReturnVal(uVar1);
  return 1;
}

// FUN_00424F80


void FUN_00424f80(void)



{
  u8 *entry;
  u32 bVar1;
  int iVar2;

  for (iVar2 = 1; iVar2 < 4; iVar2 = iVar2 + 1) {
    bVar1 = 0;
    entry = DAT_008717e8_abs + iVar2 * 0x1c0;
    if ((*(u32 *)(entry + 0x48) != 0) && (*(u32 *)(entry + 0x54) != 0)) {
      bVar1 = 1;
    }
    bVar1 = bVar1 > 0;
    if (bVar1 == 1) {
      func_001b00c0(*(u32 *)
                    (*(int *)(*(int *)(*(int *)(entry + 0x16c) + 0x3c) + 0x24) +
                    0x170));
    }
  }

  return;

}

// FUN_00425020


u32 FUN_00425020(void)



{

  if (DAT_007ce6ac != 0) {

    DAT_007ce6ac = 0;

  }

  DAT_007ce6ac = FUN_00447e70(0,1,0);

  return 1;

}

// FUN_00425070


u32 FUN_00425070(void)
{
  if (DAT_007ce6ac != 0) {
    return 0;
  }
  FUN_00449fa0();
  return 1;
}

// FUN_004250B0


u32 FUN_004250b0(void)



{

  u8 uVar1;

  

  uVar1 = scrGetIntPara(0);

  *(u8 *)(DAT_007ce6ec + 0xad) = uVar1;

  return 1;

}

// FUN_004250E0


u32 FUN_004250e0(void)



{

  char cVar1;

  char uVar2;

  u16 uVar3;

  int iVar4;

  

  cVar1 = scrGetIntPara(0);

  uVar2 = scrGetIntPara(1);

  uVar3 = scrGetIntPara(2);

  iVar4 = (char)(cVar1 + -1) * 6;

  *(u16 *)((u8 *)(uintptr_t)Yajima_AddOffsetFirst(
      (uintptr_t)iVar4, (uintptr_t)DAT_007ce6ec_abs) + 0x7c) = uVar3;

  *(u16 *)((u8 *)(uintptr_t)Yajima_AddOffsetFirst(
      (uintptr_t)iVar4, (uintptr_t)DAT_007ce6ec_abs) + 0x7e) = 0;

  *(u16 *)((u8 *)(uintptr_t)Yajima_AddOffsetFirst(
      (uintptr_t)iVar4, (uintptr_t)DAT_007ce6ec_abs) + 0x80) = 0;

  *(u8 *)((u8 *)(uintptr_t)Yajima_AddOffsetFirst(
      (uintptr_t)(char)(cVar1 + -1), (uintptr_t)DAT_007ce6ec_abs) + 0xa6) = uVar2;

  return 1;

}

// FUN_00425190


u32 FUN_00425190(void)



{

  int iVar1;

  u8 uVar2;

  u16 uVar3;

  int lVar4;

  

  lVar4 = scrGetIntPara(0);


  if (lVar4 != 0) {
    iVar1 = (int)DAT_007ce6ec_abs;

    uVar2 = scrGetIntPara(0);

    *(u8 *)((u8 *)(uintptr_t)Yajima_AddOffsetFirst(
        (u32)*(s8 *)(iVar1 + 0xa0) * 4, (uintptr_t)iVar1) + 4) = uVar2;

    iVar1 = (int)DAT_007ce6ec_abs;

    uVar3 = scrGetIntPara(1);

    *(u16 *)((u8 *)(uintptr_t)Yajima_AddOffsetFirst(
        (u32)*(s8 *)(iVar1 + 0xa0) * 4, (uintptr_t)iVar1) + 6) = uVar3;

    *(char *)(DAT_007ce6ec_abs + 0xa0) = *(char *)(DAT_007ce6ec_abs + 0xa0) + '\x01';

  }

  return 1;

}

// FUN_00425220


u32 FUN_00425220(void)



{

  u8 uVar1;

  u16 uVar2;

  

  uVar1 = scrGetIntPara(0);

  *(u8 *)(DAT_007ce6ec + 0xa4) = uVar1;

  uVar2 = scrGetIntPara(1);

  *(u16 *)(DAT_007ce6ec + 0xa2) = uVar2;

  return 1;

}

// FUN_00425270


u32 FUN_00425270(void)



{

  u8 uVar1;

  

  uVar1 = scrGetIntPara(0);

  *(u8 *)(DAT_007ce6ec + 0xae) = uVar1;

  return 1;

}

// FUN_004252A0


u32 FUN_004252a0(void)



{

  u8 uVar1;

  

  uVar1 = scrGetIntPara(0);

  *(u8 *)(DAT_007ce6ec + 0xaf) = uVar1;

  return 1;

}

// FUN_004252D0


u32 FUN_004252d0(void)



{

  if (DAT_007ce6ac != 0) {

    DAT_007ce6ac = 0;

  }

  DAT_007ce6ac = FUN_00447e70(0,0,0);

  return 1;

}

// FUN_00425320


u32 FUN_00425320(void)
{
  if (DAT_007ce6ac != 0) {
    return 0;
  }
  FUN_00449fa0();
  return 1;
}

// FUN_00425360


u32 FUN_00425360(void)
{
  int iVar1;
  for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
    FUN_00458850(*(u32 *)(DAT_0086e6a0 + iVar1 * 0x1c0 + 0x16c));
  }
  return 1;
}

// FUN_004253D0


u32 FUN_004253d0(void)



{

  short sVar1;

  u32 uVar2;

  int iVar3;

  int iVar4;

  

  sVar1 = scrGetIntPara(0);

  iVar4 = sVar1 * 0x10;

  uVar2 = scrGetIntPara(1);

  *(u32 *)(DAT_0086be00_abs + iVar4) = uVar2;

  iVar3 = scrGetIntPara(2);

  *(float *)(DAT_0086be04_abs + iVar4) = (float)iVar3;

  iVar3 = scrGetIntPara(3);

  *(float *)(DAT_0086be0c_abs + iVar4) = (float)iVar3;

  return 1;

}

// FUN_00425480


u32 FUN_00425480(void)



{

  u32 uVar1;

  

  uVar1 = scrGetIntPara(0);

  FUN_0045a280(0,uVar1);

  return 1;

}

// FUN_004254C0


u32 FUN_004254c0(void)
{
  u32 uVar1;
  uVar1 = 0;
  if (DAT_007ce6f8 == 0) {
    scrSetIntReturnVal(-1);
  }
  if (FUN_0045a3b0() == 1) {
    uVar1 = 1;
  }
  scrSetIntReturnVal(uVar1);
  return 1;
}

// FUN_00425530


u32 FUN_00425530(void)



{

  if (DAT_007ce6f8 == 0) {

    scrSetIntReturnVal(-1);

  }

  FUN_0045a3e0();

  scrSetIntReturnVal(0);

  return 1;

}

// FUN_00425580


u32 FUN_00425580(void)



{

  if (DAT_007ce6f8 == 0) {

    scrSetIntReturnVal(-1);

  }

  Y_TimeLimit_Stop();

  scrSetIntReturnVal(0);

  return 1;

}

// FUN_004255D0


u32 FUN_004255d0(void)



{

  int iVar1;

  

  iVar1 = scrGetIntPara(0);

  if (DAT_007ce6f8 == 0) {

    scrSetIntReturnVal(-1);

  }

  FUN_0045a430((s8)iVar1);

  scrSetIntReturnVal(0);

  return 1;

}

// FUN_00425640


u32 FUN_00425640(void)
{
  u32 uVar1;
  if (DAT_007ce6f8 == 0) {
    scrSetIntReturnVal(-1);
  }
  uVar1 = FUN_0045af40();
  scrSetIntReturnVal(uVar1);
  return 1;
}

// FUN_00425690 NONMATCHING


u32 FUN_00425690(int param_1)



{

  char cVar1;

  char *pcVar2;

  u32 uVar3;

  int iVar4;

  int iVar5;

  u32 *puVar6;

  u32 uVar7;

  u32 uVar8;

  u32 uVar9;

  int lVar10;

  float ambientColor[4];

  float directionalColor[4];

  float auStack_70[16];

  float *puVar6f;

  float *puVar11;
  u32 uStack_4;

  

  pcVar2 = *(char **)(param_1 + 0x3c);

  iVar4 = MT_Scene_GetResListHead(4);

  iVar5 = kwlnGetAmbientLight();

  ambientColor[0] = *(float *)(iVar5 + 0x18);
  ambientColor[1] = *(float *)(iVar5 + 0x1c);
  ambientColor[2] = *(float *)(iVar5 + 0x20);
  ambientColor[3] = *(float *)(iVar5 + 0x24);

  iVar5 = kwlnGetDirectionalLight();

  directionalColor[0] = *(float *)(iVar5 + 0x18);
  directionalColor[1] = *(float *)(iVar5 + 0x1c);
  directionalColor[2] = *(float *)(iVar5 + 0x20);
  directionalColor[3] = *(float *)(iVar5 + 0x24);

  iVar5 = kwlnGetDirectionalLight();

  puVar11 = (float *)(*(int *)(iVar5 + 4) + 0x10);

  puVar6f = auStack_70;
  iVar5 = 8;

  do {
    *puVar6f = *puVar11;
    puVar6f[1] = puVar11[1];
    puVar11 = puVar11 + 2;
    iVar5 = iVar5 + -1;
    puVar6f = puVar6f + 2;
  } while (0 < iVar5);

  uVar8 = kwlnGetWorld(DAT_007ce0cc);

  uVar9 = func_00198580();

  FUN_0049c480(uVar8,uVar9);

  uVar8 = kwlnGetAmbientLight();

  uVar9 = K_Scene_GetFldAmbLightColor();

  FUN_004944b0(uVar8,uVar9);

  uVar8 = kwlnGetDirectionalLight();

  FUN_004944b0(uVar8,iVar4 + 0x110);

  iVar5 = kwlnGetDirectionalLight();

  FUN_004cb7f0(*(u32 *)(iVar5 + 4),iVar4 + 0x120,0);

  uVar8 = kwlnGetMainCamera();

  lVar10 = RwCameraBeginUpdate(uVar8);

  if (lVar10 != 0) {

    cVar1 = *pcVar2;

    if (cVar1 == '\x04') {

      FUN_00317a20((&DAT_0095bec0)[pcVar2[2]]);

    }

    else if (cVar1 == '\x03') {

      FUN_00317a20((&DAT_0095bea0)[pcVar2[3]]);

    }

    else {

      if (cVar1 != '\x02') {

        if (cVar1 != '\x01') {

          if (cVar1 != '\0') goto LAB_00425aec;

          puVar6 = (u32 *)FUN_00421760();

          uVar8 = FUN_00421f10(*puVar6);

          for (iVar4 = 1; iVar4 < 7; iVar4 = iVar4 + 1) {

            uVar9 = H_Cdvd_ArchiveGetFile(uVar8,iVar4 + -1,&uStack_4);

            uVar7 = mdlCreateFromRmdMemory(0,0,uVar9,uStack_4,0);

            *(u32 *)(&DAT_0095be9c + iVar4 * 4) = uVar7;

          }

          for (iVar4 = 0; iVar4 < 6; iVar4 = iVar4 + 1) {

            uVar9 = H_Cdvd_ArchiveGetFile(uVar8,iVar4 + 6,&uStack_4);

            uVar7 = mdlCreateFromRmdMemory(0,0,uVar9,uStack_4,0);

            (&DAT_0095bec0)[iVar4] = uVar7;

          }

          *pcVar2 = '\x01';

        }

        lVar10 = mdlStreamRead(DAT_0095bec0);

        if (((((lVar10 == 0) || (lVar10 = mdlStreamRead(DAT_0095bec4), lVar10 == 0)) ||

             (lVar10 = mdlStreamRead(DAT_0095bec8), lVar10 == 0)) ||

            ((((lVar10 = mdlStreamRead(DAT_0095becc), lVar10 == 0 ||

               (lVar10 = mdlStreamRead(DAT_0095bed0), lVar10 == 0)) ||

              ((lVar10 = mdlStreamRead(DAT_0095bed4), lVar10 == 0 ||

               ((lVar10 = mdlStreamRead(DAT_0095bea0), lVar10 == 0 ||

                (lVar10 = mdlStreamRead(DAT_0095bea4), lVar10 == 0)))))) ||

             (lVar10 = mdlStreamRead(DAT_0095bea8), lVar10 == 0)))) ||

           (((lVar10 = mdlStreamRead(DAT_0095beac), lVar10 == 0 ||

             (lVar10 = mdlStreamRead(DAT_0095beb0), lVar10 == 0)) ||

            (lVar10 = mdlStreamRead(DAT_0095beb4), lVar10 == 0)))) goto LAB_00425aec;

        mdlAnimSet((&DAT_0095bec0)[pcVar2[1]],0,0,0,1);

        *pcVar2 = '\x02';

      }

      FUN_00317a20((&DAT_0095bec0)[pcVar2[1]]);

      FUN_00317a20((&DAT_0095bea0)[pcVar2[3]]);

    }

  }

LAB_00425aec:

  uVar8 = kwlnGetMainCamera();

  RwCameraEndUpdate(uVar8);

  uVar8 = kwlnGetWorld(DAT_007ce0cc);

  uVar9 = func_00198580();

  FUN_0049c3d0(uVar8,uVar9);

  uVar8 = kwlnGetAmbientLight();

  FUN_004944b0(uVar8,&ambientColor);

  uVar8 = kwlnGetDirectionalLight();

  FUN_004944b0(uVar8,&directionalColor);

  iVar4 = kwlnGetDirectionalLight();

  FUN_004cb7f0(*(u32 *)(iVar4 + 4),auStack_70,0);

  return 0;

}

// FUN_00425BA0 NONMATCHING


void FUN_00425ba0(int param_1)



{

  int object = param_1;
  int iVar1;

  

  for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
    if (((u32 *)DAT_0095bec0_abs)[iVar1] != 0) {
      mdlDestroy(((u32 *)DAT_0095bec0_abs)[iVar1]);
    }
  }
  for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
    if (((u32 *)DAT_0095bea0_abs)[iVar1] != 0) {
      mdlDestroy(((u32 *)DAT_0095bea0_abs)[iVar1]);
    }
  }
  (DAT_0096017c_abs[0x5f])(*(u32 *)(object + 0x3c));

  return;

}

// FUN_00425C60


u32 FUN_00425c60(u64 param_1,u8 param_2)
{
  u8 *lVar1;
  u32 uVar2;

  lVar1 = (u8 *)(uintptr_t)(*DAT_00960184_abs)(1,4,0x40000);

  if (lVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = kwlnTaskCreate(param_1, DAT_006b4400, 0x831,
                           (void *)FUN_00425690, (void *)FUN_00425ba0,
                           lVar1);

    lVar1[0] = 0;
    lVar1[1] = param_2;
    lVar1[2] = 0;
  }

  return uVar2;
}

// FUN_00425D10


void FUN_00425d10(int param_1,u8 param_2)



{

  u8 *puVar1;

  

  puVar1 = *(u8 **)(param_1 + 0x3c);

  puVar1[1] = param_2;

  *puVar1 = 1;

  return;

}

// FUN_00425D30

void FUN_00425d30(int param_1,u8 param_2,u8 param_3)
{
  u8 *work;

  work = *(u8 **)(param_1 + 0x3c);
  work[1] = param_2;
  work[2] = param_3;
  *(u8 *)&DAT_007ce6b4 = param_2;
}

// FUN_00425D50 NONMATCHING


u32 FUN_00425d50(u8 param_1,u8 param_2)



{

  u32 uVar1;

  

  uVar1 = 0;

  switch(param_1) {

  case 0:

    switch(param_2) {

    case 0:

      break;

    case 1:

      uVar1 = 1;

      break;

    case 2:

      uVar1 = 2;

      break;

    case 3:

      uVar1 = 3;

      break;

    case 4:

      uVar1 = 4;

      break;

    case 5:

      uVar1 = 5;

    }

    break;

  case 1:

    switch(param_2) {

    case 0:

      uVar1 = 1;

      break;

    case 1:

      break;

    case 2:

      uVar1 = 2;

      break;

    case 3:

      uVar1 = 3;

      break;

    case 4:

      uVar1 = 4;

      break;

    case 5:

      uVar1 = 5;

    }

    break;

  case 2:

    switch(param_2) {

    case 0:

      uVar1 = 1;

      break;

    case 1:

      uVar1 = 2;

      break;

    case 2:

      break;

    case 3:

      uVar1 = 3;

      break;

    case 4:

      uVar1 = 4;

      break;

    case 5:

      uVar1 = 5;

    }

    break;

  case 3:

    switch(param_2) {

    case 0:

      uVar1 = 1;

      break;

    case 1:

      uVar1 = 2;

      break;

    case 2:

      uVar1 = 3;

      break;

    case 3:

      break;

    case 4:

      uVar1 = 4;

      break;

    case 5:

      uVar1 = 5;

    }

    break;

  case 4:

    switch(param_2) {

    case 0:

      uVar1 = 1;

      break;

    case 1:

      uVar1 = 2;

      break;

    case 2:

      uVar1 = 3;

      break;

    case 3:

      uVar1 = 4;

      break;

    case 4:

      break;

    case 5:

      uVar1 = 5;

    }

    break;

  case 5:

    switch(param_2) {

    case 0:

      uVar1 = 1;

      break;

    case 1:

      uVar1 = 2;

      break;

    case 2:

      uVar1 = 3;

      break;

    case 3:

      uVar1 = 4;

      break;

    case 4:

      uVar1 = 5;

    }

  }

  return uVar1;

}

// FUN_00426040


void FUN_00426040(int param_1,u8 param_2)



{

  *(u8 *)(*(int *)(param_1 + 0x3c) + 3) = param_2;

  return;

}

// FUN_00426050


void FUN_00426050(int param_1)



{

  **(u8 **)(param_1 + 0x3c) = 3;

  return;

}

// FUN_00426070


u8 FUN_00426070(int param_1)



{

  return **(char **)(param_1 + 0x3c) != '\x02';

}

// FUN_00426090


u32 * FUN_00426090(void)



{

  return &DAT_007ce6b8;

}

// FUN_004260A0 NONMATCHING


u64 FUN_004260a0(int param_1)



{

  char *pcVar1;

  u32 uVar2;

  u32 uVar3;

  u8 uVar4;

  char cVar5;

  int iVar6;

  int iVar7;

  u64 uVar8;

  u64 uVar9;

  long lVar10;

  u32 *puVar11;

  u32 *puVar12;

  u32 auStack_60 [16];

  u32 uStack_20;

  u32 uStack_1c;

  u32 uStack_18;

  u32 uStack_14;

  u32 uStack_10;

  u32 uStack_c;

  u32 uStack_8;

  u32 uStack_4;

  

  iVar6 = MT_Scene_GetResListHead(4);

  pcVar1 = *(char **)(param_1 + 0x3c);

  iVar7 = kwlnGetAmbientLight();

  uStack_10 = *(u32 *)(iVar7 + 0x18);

  uStack_c = *(u32 *)(iVar7 + 0x1c);

  uStack_8 = *(u32 *)(iVar7 + 0x20);

  uStack_4 = *(u32 *)(iVar7 + 0x24);

  iVar7 = kwlnGetDirectionalLight();

  uStack_20 = *(u32 *)(iVar7 + 0x18);

  uStack_1c = *(u32 *)(iVar7 + 0x1c);

  uStack_18 = *(u32 *)(iVar7 + 0x20);

  uStack_14 = *(u32 *)(iVar7 + 0x24);

  iVar7 = kwlnGetDirectionalLight();

  puVar12 = (u32 *)(*(int *)(iVar7 + 4) + 0x10);

  puVar11 = auStack_60;

  iVar7 = 8;

  do {

    uVar2 = *puVar12;

    uVar3 = puVar12[1];

    puVar12 = puVar12 + 2;

    iVar7 = iVar7 + -1;

    *puVar11 = uVar2;

    puVar11[1] = uVar3;

    puVar11 = puVar11 + 2;

  } while (0 < iVar7);

  uVar8 = kwlnGetWorld(DAT_007ce0cc);

  uVar9 = func_00198580();

  FUN_0049c480(uVar8,uVar9);

  uVar8 = kwlnGetAmbientLight();

  uVar9 = K_Scene_GetFldAmbLightColor();

  FUN_004944b0(uVar8,uVar9);

  uVar8 = kwlnGetDirectionalLight();

  FUN_004944b0(uVar8,iVar6 + 0x110);

  iVar7 = kwlnGetDirectionalLight();

  FUN_004cb7f0(*(u32 *)(iVar7 + 4),iVar6 + 0x120,0);

  uVar8 = kwlnGetMainCamera();

  lVar10 = RwCameraBeginUpdate(uVar8);

  if (lVar10 != 0) {

    cVar5 = *pcVar1;

    if (cVar5 == '\x02') {

      FUN_00317a20((&DAT_0095bec0)[DAT_007ce6b4]);

      *(u8 *)(DAT_007ce6a8 + 8) = 1;

    }

    else if (cVar5 == '\x01') {

      FUN_00317a20((&DAT_0095bec0)[DAT_007ce6b4]);

      if ((DAT_007e094c & 0x20) == 0) {

        mdlAnimSetSpeed(0x3f800000,(&DAT_0095bec0)[DAT_007ce6b4],0);

      }

      else {

        mdlAnimSetSpeed(0x40000000,(&DAT_0095bec0)[DAT_007ce6b4],0);

      }

      if (*(char *)((&DAT_0095bec0)[DAT_007ce6b4] + 0xee) == '\x01') {

        *pcVar1 = '\x02';

        DAT_007ce6b4 = pcVar1[1];

        mdlAnimSet((&DAT_0095bec0)[DAT_007ce6b4],0,0,0,0);

      }

    }

    else if (cVar5 == '\0') {


      mdlAnimSet((&DAT_0095bec0)[DAT_007ce6b4],0,uVar4,0,0);

      *pcVar1 = '\x01';


      if (cVar5 == '\0') {

        DAT_007ce6b4 = pcVar1[1];

        mdlAnimSet((&DAT_0095bec0)[DAT_007ce6b4],0,0,0,0);

        *pcVar1 = '\x02';

      }

    }

  }

  uVar8 = kwlnGetMainCamera();

  RwCameraEndUpdate(uVar8);

  uVar8 = kwlnGetWorld(DAT_007ce0cc);

  uVar9 = func_00198580();

  FUN_0049c3d0(uVar8,uVar9);

  uVar8 = kwlnGetAmbientLight();

  FUN_004944b0(uVar8,&uStack_10);

  uVar8 = kwlnGetDirectionalLight();

  FUN_004944b0(uVar8,&uStack_20);

  iVar6 = kwlnGetDirectionalLight();

  FUN_004cb7f0(*(u32 *)(iVar6 + 4),auStack_60,0);

  return 0;

}

// FUN_004264A0


void FUN_004264a0(int param_1)



{

  DAT_0096017c_abs[0](*(u32 *)(param_1 + 0x3c));

  return;

}

// FUN_004264D0 NONMATCHING


u32 FUN_004264d0(u64 param_1,s8 param_2)



{

  long lVar1;

  u32 uVar2;

  

  memset(0x7ce6b8,0,4);

  lVar1 = (*DAT_00960184)(1,2,0x40000);

  if (lVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = kwlnTaskCreate(param_1,0x6b4420,0x831,0x4260a0,0x4264a0,lVar1);

    *(u8 *)lVar1 = 0;

    ((u8 *)lVar1)[1] = param_2;

    DAT_007ce6b8 = (u32)uVar2;

    *(u8 *)(DAT_007ce6a8 + 8) = 0;

  }

  return uVar2;

}

// FUN_00426590 NONMATCHING
 #define DAT_00960090 Yajima_setState


u32 FUN_00426590(int param_1)



{

  char cVar1;

  char *pcVar2;

  int iVar3;

  u32 uVar4;

  float fVar5;

  float fVar6;
  code *Yajima_setState;

  

  pcVar2 = *(char **)(param_1 + 0x3c);

  cVar1 = pcVar2[0x18c];
  Yajima_setState = (code *)&DAT_00960090_abs;

  if (cVar1 == '\0') {

    (*DAT_00960090)(6,1);

    (*DAT_00960090)(7,2);

    (*DAT_00960090)(8,1);

    (*DAT_00960090)(10,5);

    (*DAT_00960090)(0xb,6);

    (*DAT_00960090)(9,1);

    (*DAT_00960090)(0xc,1);

    (*DAT_00960090)(1,**(u32 **)(pcVar2 + 0x13c));

    (*DAT_00960090)(2,3);

    RpSkyRenderStateSet(2,0x44);

    RpSkyRenderStateSet(3,0x717fb);

  }

  else if (cVar1 == '\x01') {

    (*DAT_00960090)(6);

    (*DAT_00960090)(7,2);

    (*DAT_00960090)(8,1);

    (*DAT_00960090)(10,5);

    (*DAT_00960090)(0xb,6);

    (*DAT_00960090)(9,2);

    (*DAT_00960090)(0xc,1);

    (*DAT_00960090)(1,**(u32 **)(pcVar2 + 0x13c));

    (*DAT_00960090)(2,3);

    RpSkyRenderStateSet(2,0x44);

    RpSkyRenderStateSet(3,0x717fb);

  }

  else if (cVar1 == '\x02') {

    (*DAT_00960090)(6);

    (*DAT_00960090)(7,2);

    (*DAT_00960090)(8,1);

    (*DAT_00960090)(10,5);

    (*DAT_00960090)(0xb,6);

    (*DAT_00960090)(9,2);

    (*DAT_00960090)(0xc,1);

    (*DAT_00960090)(1,**(u32 **)(pcVar2 + 0x13c));

    (*DAT_00960090)(2,3);

    RpSkyRenderStateSet(2,0x48);

    RpSkyRenderStateSet(3,0x71801);

  }

  if (pcVar2[0x150] == '\x01') {

    uVar4 = 0;

  }

  else {

    cVar1 = *pcVar2;

    if (cVar1 == '\x02') {

      uVar4 = 0xffffffff;

    }

    else {

      if ((cVar1 == '\x01') || (cVar1 == '\0')) {

        iVar3 = kwlnGetMainCamera();

        fVar5 = 1.0f / *(float *)(iVar3 + 0x80);

        cVar1 = pcVar2[0x141];

        switch (cVar1) { case '\0': if (pcVar2[0x150] == '\0') {
        
          for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
        
            *(float *)(pcVar2 + iVar3 * 0x40 + 0x18) = DAT_00960088 - *(float *)(pcVar2 + 0x130);
        
            *(float *)(pcVar2 + iVar3 * 0x40 + 0x28) = fVar5;
        
            *(float *)(pcVar2 + iVar3 * 0x40 + 0x30) = (float)(u8)pcVar2[iVar3 * 4 + 0x110];
        
            *(float *)(pcVar2 + iVar3 * 0x40 + 0x34) = (float)(u8)pcVar2[iVar3 * 4 + 0x111];
        
            *(float *)(pcVar2 + iVar3 * 0x40 + 0x38) = (float)(u8)pcVar2[iVar3 * 4 + 0x112];
        
            *(float *)(pcVar2 + iVar3 * 0x40 + 0x3c) = (float)(u8)pcVar2[iVar3 * 4 + 0x113];
        
          }
        
        }
        
        else if (pcVar2[0x150] == '\x01') {
        
          return 0;
        
        }
        
        *(u32 *)(pcVar2 + 0x20) = *(u32 *)(pcVar2 + 0x17c);
        
        *(u32 *)(pcVar2 + 0x24) = *(u32 *)(pcVar2 + 0x180);
        
        *(u32 *)(pcVar2 + 0x60) = *(u32 *)(pcVar2 + 0x174);
        
        *(u32 *)(pcVar2 + 100) = *(u32 *)(pcVar2 + 0x180);
        
        *(u32 *)(pcVar2 + 0xa0) = *(u32 *)(pcVar2 + 0x17c);
        
        *(u32 *)(pcVar2 + 0xa4) = *(u32 *)(pcVar2 + 0x178);
        
        *(u32 *)(pcVar2 + 0xe0) = *(u32 *)(pcVar2 + 0x174);
        
        *(u32 *)(pcVar2 + 0xe4) = *(u32 *)(pcVar2 + 0x178);
        
        cVar1 = pcVar2[0x140];
        
        if (cVar1 == '\x03') {
        
          *(u32 *)(pcVar2 + 0x90) = *(u32 *)(pcVar2 + 0x134);
        
          *(u32 *)(pcVar2 + 0x94) = *(u32 *)(pcVar2 + 0x138);
        
          *(float *)(pcVar2 + 0x10) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(u32 *)(pcVar2 + 0x14) = *(u32 *)(pcVar2 + 0x138);
        
          *(u32 *)(pcVar2 + 0xd0) = *(u32 *)(pcVar2 + 0x134);
        
          *(float *)(pcVar2 + 0xd4) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
          *(float *)(pcVar2 + 0x50) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(float *)(pcVar2 + 0x54) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
        }
        
        else if (cVar1 == '\x02') {
        
          *(u32 *)(pcVar2 + 0xd0) = *(u32 *)(pcVar2 + 0x134);
        
          *(u32 *)(pcVar2 + 0xd4) = *(u32 *)(pcVar2 + 0x138);
        
          *(float *)(pcVar2 + 0x90) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(u32 *)(pcVar2 + 0x94) = *(u32 *)(pcVar2 + 0x138);
        
          *(u32 *)(pcVar2 + 0x50) = *(u32 *)(pcVar2 + 0x134);
        
          *(float *)(pcVar2 + 0x54) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
          *(float *)(pcVar2 + 0x10) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(float *)(pcVar2 + 0x14) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
        }
        
        else if (cVar1 == '\x01') {
        
          *(u32 *)(pcVar2 + 0x50) = *(u32 *)(pcVar2 + 0x134);
        
          *(u32 *)(pcVar2 + 0x54) = *(u32 *)(pcVar2 + 0x138);
        
          *(float *)(pcVar2 + 0xd0) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(u32 *)(pcVar2 + 0xd4) = *(u32 *)(pcVar2 + 0x138);
        
          *(u32 *)(pcVar2 + 0x10) = *(u32 *)(pcVar2 + 0x134);
        
          *(float *)(pcVar2 + 0x14) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
          *(float *)(pcVar2 + 0x90) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(float *)(pcVar2 + 0x94) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
        }
        
        else if (cVar1 == '\0') {
        
          *(u32 *)(pcVar2 + 0x10) = *(u32 *)(pcVar2 + 0x134);
        
          *(u32 *)(pcVar2 + 0x14) = *(u32 *)(pcVar2 + 0x138);
        
          *(float *)(pcVar2 + 0x50) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(u32 *)(pcVar2 + 0x54) = *(u32 *)(pcVar2 + 0x138);
        
          *(u32 *)(pcVar2 + 0x90) = *(u32 *)(pcVar2 + 0x134);
        
          *(float *)(pcVar2 + 0x94) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
          *(float *)(pcVar2 + 0xd0) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(float *)(pcVar2 + 0xd4) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
        }
        
        (*DAT_009600a0)(4,pcVar2 + 0x10,4); break; case '\x01': for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x18) = DAT_00960088 - *(float *)(pcVar2 + 0x130);
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x28) = fVar5;
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x30) = (float)(u8)pcVar2[iVar3 * 4 + 0x110];
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x34) = (float)(u8)pcVar2[iVar3 * 4 + 0x111];
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x38) = (float)(u8)pcVar2[iVar3 * 4 + 0x112];
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x3c) = (float)(u8)pcVar2[iVar3 * 4 + 0x113];
        
        }
        
        pcVar2[0x20] = '\0';
        
        pcVar2[0x21] = '\0';
        
        pcVar2[0x22] = '\0';
        
        pcVar2[0x23] = '\0';
        
        pcVar2[0x24] = '\0';
        
        pcVar2[0x25] = '\0';
        
        pcVar2[0x26] = '\0';
        
        pcVar2[0x27] = '\0';
        
        *(float *)(pcVar2 + 0x10) =
        
             *(float *)(pcVar2 + 0x134) -
        
             ((float)*(int *)(pcVar2 + 0x128) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        *(float *)(pcVar2 + 0x14) =
        
             *(float *)(pcVar2 + 0x138) -
        
             ((float)*(int *)(pcVar2 + 300) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        pcVar2[0x60] = '\0';
        
        pcVar2[0x61] = '\0';
        
        pcVar2[0x62] = -0x80;
        
        pcVar2[99] = '?';
        
        pcVar2[100] = '\0';
        
        pcVar2[0x65] = '\0';
        
        pcVar2[0x66] = '\0';
        
        pcVar2[0x67] = '\0';
        
        *(float *)(pcVar2 + 0x50) =
        
             *(float *)(pcVar2 + 0x134) +
        
             ((float)*(int *)(pcVar2 + 0x128) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        *(float *)(pcVar2 + 0x54) =
        
             *(float *)(pcVar2 + 0x138) -
        
             ((float)*(int *)(pcVar2 + 300) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        pcVar2[0xa0] = '\0';
        
        pcVar2[0xa1] = '\0';
        
        pcVar2[0xa2] = '\0';
        
        pcVar2[0xa3] = '\0';
        
        pcVar2[0xa4] = '\0';
        
        pcVar2[0xa5] = '\0';
        
        pcVar2[0xa6] = -0x80;
        
        pcVar2[0xa7] = '?';
        
        *(float *)(pcVar2 + 0x90) =
        
             *(float *)(pcVar2 + 0x134) -
        
             ((float)*(int *)(pcVar2 + 0x128) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        *(float *)(pcVar2 + 0x94) =
        
             *(float *)(pcVar2 + 0x138) +
        
             ((float)*(int *)(pcVar2 + 300) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        pcVar2[0xe0] = '\0';
        
        pcVar2[0xe1] = '\0';
        
        pcVar2[0xe2] = -0x80;
        
        pcVar2[0xe3] = '?';
        
        pcVar2[0xe4] = '\0';
        
        pcVar2[0xe5] = '\0';
        
        pcVar2[0xe6] = -0x80;
        
        pcVar2[0xe7] = '?';
        
        *(float *)(pcVar2 + 0xd0) =
        
             *(float *)(pcVar2 + 0x134) +
        
             ((float)*(int *)(pcVar2 + 0x128) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        *(float *)(pcVar2 + 0xd4) =
        
             *(float *)(pcVar2 + 0x138) +
        
             ((float)*(int *)(pcVar2 + 300) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        (*DAT_009600a0)(4,pcVar2 + 0x10,4); break; case '\x02': for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x18) = DAT_00960088 - *(float *)(pcVar2 + 0x130);
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x28) = fVar5;
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x30) = (float)(u8)pcVar2[iVar3 * 4 + 0x110];
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x34) = (float)(u8)pcVar2[iVar3 * 4 + 0x111];
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x38) = (float)(u8)pcVar2[iVar3 * 4 + 0x112];
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x3c) = (float)(u8)pcVar2[iVar3 * 4 + 0x113];
        
        }
        
        pcVar2[0x20] = '\0';
        
        pcVar2[0x21] = '\0';
        
        pcVar2[0x22] = '\0';
        
        pcVar2[0x23] = '\0';
        
        pcVar2[0x24] = '\0';
        
        pcVar2[0x25] = '\0';
        
        pcVar2[0x26] = '\0';
        
        pcVar2[0x27] = '\0';
        
        *(u32 *)(pcVar2 + 0x10) = *(u32 *)(pcVar2 + 0x134);
        
        *(u32 *)(pcVar2 + 0x14) = *(u32 *)(pcVar2 + 0x138);
        
        pcVar2[0x60] = '\0';
        
        pcVar2[0x61] = '\0';
        
        pcVar2[0x62] = -0x80;
        
        pcVar2[99] = '?';
        
        pcVar2[100] = '\0';
        
        pcVar2[0x65] = '\0';
        
        pcVar2[0x66] = '\0';
        
        pcVar2[0x67] = '\0';
        
        *(float *)(pcVar2 + 0x50) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128);
        
        *(u32 *)(pcVar2 + 0x54) = *(u32 *)(pcVar2 + 0x138);
        
        pcVar2[0xa0] = '\0';
        
        pcVar2[0xa1] = '\0';
        
        pcVar2[0xa2] = '\0';
        
        pcVar2[0xa3] = '\0';
        
        pcVar2[0xa4] = '\0';
        
        pcVar2[0xa5] = '\0';
        
        pcVar2[0xa6] = -0x80;
        
        pcVar2[0xa7] = '?';
        
        *(u32 *)(pcVar2 + 0x90) = *(u32 *)(pcVar2 + 0x134);
        
        *(float *)(pcVar2 + 0x94) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
        pcVar2[0xe0] = '\0';
        
        pcVar2[0xe1] = '\0';
        
        pcVar2[0xe2] = -0x80;
        
        pcVar2[0xe3] = '?';
        
        pcVar2[0xe4] = '\0';
        
        pcVar2[0xe5] = '\0';
        
        pcVar2[0xe6] = -0x80;
        
        pcVar2[0xe7] = '?';
        
        *(float *)(pcVar2 + 0xd0) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128);
        
        *(float *)(pcVar2 + 0xd4) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
        (*DAT_009600a0)(4,pcVar2 + 0x10,4); break; case '\x03': for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x18) = DAT_00960088 - *(float *)(pcVar2 + 0x130);
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x28) = fVar5;
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x30) = (float)(u8)pcVar2[iVar3 * 4 + 0x110];
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x34) = (float)(u8)pcVar2[iVar3 * 4 + 0x111];
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x38) = (float)(u8)pcVar2[iVar3 * 4 + 0x112];
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x3c) = (float)(u8)pcVar2[iVar3 * 4 + 0x113];
        
        }
        
        pcVar2[0x20] = '\0';
        
        pcVar2[0x21] = '\0';
        
        pcVar2[0x22] = '\0';
        
        pcVar2[0x23] = '\0';
        
        pcVar2[0x24] = '\0';
        
        pcVar2[0x25] = '\0';
        
        pcVar2[0x26] = '\0';
        
        pcVar2[0x27] = '\0';
        
        *(u32 *)(pcVar2 + 0x10) = *(u32 *)(pcVar2 + 0x134);
        
        *(u32 *)(pcVar2 + 0x14) = *(u32 *)(pcVar2 + 0x138);
        
        *(u32 *)(pcVar2 + 0x60) = *(u32 *)(pcVar2 + 0x174);
        
        pcVar2[100] = '\0';
        
        pcVar2[0x65] = '\0';
        
        pcVar2[0x66] = '\0';
        
        pcVar2[0x67] = '\0';
        
        *(float *)(pcVar2 + 0x50) = *(float *)(pcVar2 + 0x134) + *(float *)(pcVar2 + 0x184);
        
        *(u32 *)(pcVar2 + 0x54) = *(u32 *)(pcVar2 + 0x138);
        
        pcVar2[0xa0] = '\0';
        
        pcVar2[0xa1] = '\0';
        
        pcVar2[0xa2] = '\0';
        
        pcVar2[0xa3] = '\0';
        
        *(u32 *)(pcVar2 + 0xa4) = *(u32 *)(pcVar2 + 0x178);
        
        *(u32 *)(pcVar2 + 0x90) = *(u32 *)(pcVar2 + 0x134);
        
        *(float *)(pcVar2 + 0x94) = *(float *)(pcVar2 + 0x138) + *(float *)(pcVar2 + 0x188);
        
        *(u32 *)(pcVar2 + 0xe0) = *(u32 *)(pcVar2 + 0x174);
        
        *(u32 *)(pcVar2 + 0xe4) = *(u32 *)(pcVar2 + 0x178);
        
        *(float *)(pcVar2 + 0xd0) = *(float *)(pcVar2 + 0x134) + *(float *)(pcVar2 + 0x184);
        
        *(float *)(pcVar2 + 0xd4) = *(float *)(pcVar2 + 0x138) + *(float *)(pcVar2 + 0x188);
        
        (*DAT_009600a0)(4,pcVar2 + 0x10,4); break; case '\x04': for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x18) = DAT_00960088 - *(float *)(pcVar2 + 0x130);
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x28) = fVar5;
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x30) = (float)(u8)pcVar2[iVar3 * 4 + 0x110];
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x34) = (float)(u8)pcVar2[iVar3 * 4 + 0x111];
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x38) = (float)(u8)pcVar2[iVar3 * 4 + 0x112];
        
          *(float *)(pcVar2 + iVar3 * 0x40 + 0x3c) = (float)(u8)pcVar2[iVar3 * 4 + 0x113];
        
        }
        
        for (iVar3 = 0; iVar3 < *(int *)(pcVar2 + 300); iVar3 = iVar3 + 1) {
        
          pcVar2[0x20] = '\0';
        
          pcVar2[0x21] = '\0';
        
          pcVar2[0x22] = '\0';
        
          pcVar2[0x23] = '\0';
        
          fVar5 = (float)iVar3;
        
          *(float *)(pcVar2 + 0x24) = (1.0f / (float)*(int *)(pcVar2 + 300)) * fVar5;
        
          pcVar2[0x60] = '\0';
        
          pcVar2[0x61] = '\0';
        
          pcVar2[0x62] = -0x80;
        
          pcVar2[99] = '?';
        
          *(float *)(pcVar2 + 100) = (1.0f / (float)*(int *)(pcVar2 + 300)) * fVar5;
        
          pcVar2[0xa0] = '\0';
        
          pcVar2[0xa1] = '\0';
        
          pcVar2[0xa2] = '\0';
        
          pcVar2[0xa3] = '\0';
        
          fVar6 = (float)(iVar3 + 1);
        
          *(float *)(pcVar2 + 0xa4) = (1.0f / (float)*(int *)(pcVar2 + 300)) * fVar6;
        
          pcVar2[0xe0] = '\0';
        
          pcVar2[0xe1] = '\0';
        
          pcVar2[0xe2] = -0x80;
        
          pcVar2[0xe3] = '?';
        
          *(float *)(pcVar2 + 0xe4) = (1.0f / (float)*(int *)(pcVar2 + 300)) * fVar6;
        
          *(u32 *)(pcVar2 + 0x10) = *(u32 *)(pcVar2 + 0x134);
        
          *(float *)(pcVar2 + 0x14) = *(float *)(pcVar2 + 0x138) + fVar5;
        
          *(float *)(pcVar2 + 0x50) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(float *)(pcVar2 + 0x54) = *(float *)(pcVar2 + 0x138) + fVar5;
        
          *(u32 *)(pcVar2 + 0x90) = *(u32 *)(pcVar2 + 0x134);
        
          *(float *)(pcVar2 + 0x94) = *(float *)(pcVar2 + 0x138) + fVar6;
        
          *(float *)(pcVar2 + 0xd0) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(float *)(pcVar2 + 0xd4) = *(float *)(pcVar2 + 0x138) + fVar6;
        
          (*DAT_009600a0)(4,pcVar2 + 0x10,4);
        
        } break; }

        *pcVar2 = '\x01';

      }

      uVar4 = 0;

    }

  }

  return uVar4;

}
 #undef DAT_00960090

// FUN_00427640


void FUN_00427640(int param_1)



{

  DAT_0096017c_abs[0](*(u32 *)(param_1 + 0x3c));

  return;

}

// FUN_00427670 NONMATCHING


u32
FUN_00427670(u32 param_1,u32 param_2,u64 param_3,u32 param_4,
            char param_5,u8 param_6)



{

  long lVar1;

  u32 uVar2;

  int iVar3;

  u8 *puVar4;

  

  lVar1 = (*DAT_00960184)(1,400,0x40000);

  if (lVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = kwlnTaskCreate(param_3,0x6b4430,0x18a7,0x426590,0x427640,lVar1);

    puVar4 = (u8 *)lVar1;

    *puVar4 = 0;

    for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

      puVar4[iVar3 * 4 + 0x111] = 0xff;

      puVar4[iVar3 * 4 + 0x112] = 0xff;

      puVar4[iVar3 * 4 + 0x110] = 0xff;

      puVar4[iVar3 * 4 + 0x113] = 0xff;

      *(u32 *)(puVar4 + iVar3 * 8 + 0x158) = 0;

      *(u32 *)(puVar4 + iVar3 * 8 + 0x154) = 0;

    }

    *(u32 *)(puVar4 + 0x134) = 0x42c80000;

    *(u32 *)(puVar4 + 0x138) = 0x42c80000;

    if (param_5 < '\x05') {

      *(u32 *)(puVar4 + 0x17c) = 0x3d000000;

      *(u32 *)(puVar4 + 0x180) = 0x3d000000;

      *(u32 *)(puVar4 + 0x178) = 0x3f180000;

      *(u32 *)(puVar4 + 0x174) = 0x3f180000;

      *(u32 *)(puVar4 + 300) = 0x13;

      *(u32 *)(puVar4 + 0x128) = 0x13;

    }

    else {

      *(u32 *)(puVar4 + 0x17c) = 0x3c800000;

      *(u32 *)(puVar4 + 0x180) = 0x3c800000;

      *(u32 *)(puVar4 + 0x178) = 0x3f140000;

      *(u32 *)(puVar4 + 0x174) = 0x3f140000;

      *(u32 *)(puVar4 + 300) = 0x25;

      *(u32 *)(puVar4 + 0x128) = 0x25;

    }

    *(u32 *)(puVar4 + 0x130) = 0x40a00000;

    *(u32 *)(puVar4 + 0x14c) = 0x3f800000;

    *(u32 *)(puVar4 + 0x174) = param_1;

    *(u32 *)(puVar4 + 0x178) = param_2;

    *(u32 *)(puVar4 + 0x13c) = param_4;

    puVar4[0x140] = param_6;

    puVar4[0x141] = 0;

    puVar4[0x150] = 1;

    puVar4[0x18c] = 0;

  }

  return uVar2;

}

// FUN_00427830 NONMATCHING


u64

FUN_00427830(u32 param_1,u64 param_2,u32 param_3,u64 param_4,

            u32 param_5,int param_6,u32 *param_7,u8 param_8)



{

  long lVar1;

  u64 uVar2;

  int iVar3;

  u8 *puVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  u32 uVar9;

  u32 uVar10;

  u32 uStack_30;

  u32 uStack_2c;

  u8 uStack_24;

  u8 uStack_23;

  u8 uStack_22;

  u8 uStack_21;

  

  iVar5 = *(int *)(param_6 + 8);

  iVar7 = *(int *)(param_6 + 0xc);

  uVar9 = *param_7;

  uVar10 = param_7[1];

  iVar6 = param_7[2];

  iVar8 = param_7[3];

  lVar1 = (*DAT_00960184)(1,400,0x40000);

  if (lVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = kwlnTaskCreateWithAutoPriority(param_2,0x106f,0x6b4440,0x426590,0x427640,lVar1);

    puVar4 = (u8 *)lVar1;

    *puVar4 = 0;

    for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

      uStack_24 = (u8)param_5;

      uStack_23 = (u8)((u32)param_5 >> 8);

      uStack_22 = (u8)((u32)param_5 >> 0x10);

      uStack_21 = (u8)((u32)param_5 >> 0x18);

      puVar4[iVar3 * 4 + 0x110] = uStack_24;

      puVar4[iVar3 * 4 + 0x111] = uStack_23;

      puVar4[iVar3 * 4 + 0x112] = uStack_22;

      puVar4[iVar3 * 4 + 0x113] = uStack_21;

      *(u32 *)(puVar4 + iVar3 * 8 + 0x158) = 0;

      *(u32 *)(puVar4 + iVar3 * 8 + 0x154) = 0;

    }

    uStack_30 = (u32)param_4;

    uStack_2c = (u32)((u32)param_4 >> 0x20);

    *(u32 *)(puVar4 + 0x134) = uStack_30;

    *(u32 *)(puVar4 + 0x138) = uStack_2c;

    *(u32 *)(puVar4 + 0x120) = uVar9;

    *(u32 *)(puVar4 + 0x124) = uVar10;

    *(int *)(puVar4 + 0x128) = iVar6;

    *(int *)(puVar4 + 300) = iVar8;

    *(u32 *)(puVar4 + 0x130) = param_1;

    *(u32 *)(puVar4 + 0x13c) = param_3;

    puVar4[0x141] = param_8;

    *(u32 *)(puVar4 + 0x14c) = 0x3f800000;

    *(float *)(puVar4 + 0x144) = (1.0 / (float)iVar5) * (float)iVar6;

    *(float *)(puVar4 + 0x148) = (1.0 / (float)iVar7) * (float)iVar8;

    puVar4[0x150] = 0;

    puVar4[0x18c] = 0;

  }

  return uVar2;

}

// FUN_00427A10 NONMATCHING


u64

FUN_00427a10(u32 param_1,u64 param_2,u32 param_3,u64 param_4,

            u32 param_5,int param_6,u32 *param_7,u8 param_8)



{

  long lVar1;

  u64 uVar2;

  int iVar3;

  u8 *puVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  u32 uVar9;

  u32 uVar10;

  u32 uStack_30;

  u32 uStack_2c;

  u8 uStack_24;

  u8 uStack_23;

  u8 uStack_22;

  u8 uStack_21;

  

  iVar5 = *(int *)(param_6 + 8);

  iVar7 = *(int *)(param_6 + 0xc);

  uVar9 = *param_7;

  uVar10 = param_7[1];

  iVar6 = param_7[2];

  iVar8 = param_7[3];

  lVar1 = (*DAT_00960184)(1,400,0x40000);

  if (lVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = kwlnTaskCreate(param_2,0x6b4440,0x18a6,0x426590,0x427640,lVar1);

    puVar4 = (u8 *)lVar1;

    *puVar4 = 0;

    for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

      uStack_24 = (u8)param_5;

      uStack_23 = (u8)((u32)param_5 >> 8);

      uStack_22 = (u8)((u32)param_5 >> 0x10);

      uStack_21 = (u8)((u32)param_5 >> 0x18);

      puVar4[iVar3 * 4 + 0x110] = uStack_24;

      puVar4[iVar3 * 4 + 0x111] = uStack_23;

      puVar4[iVar3 * 4 + 0x112] = uStack_22;

      puVar4[iVar3 * 4 + 0x113] = uStack_21;

      *(u32 *)(puVar4 + iVar3 * 8 + 0x158) = 0;

      *(u32 *)(puVar4 + iVar3 * 8 + 0x154) = 0;

    }

    uStack_30 = (u32)param_4;

    uStack_2c = (u32)((u32)param_4 >> 0x20);

    *(u32 *)(puVar4 + 0x134) = uStack_30;

    *(u32 *)(puVar4 + 0x138) = uStack_2c;

    *(u32 *)(puVar4 + 0x120) = uVar9;

    *(u32 *)(puVar4 + 0x124) = uVar10;

    *(int *)(puVar4 + 0x128) = iVar6;

    *(int *)(puVar4 + 300) = iVar8;

    *(u32 *)(puVar4 + 0x130) = param_1;

    *(u32 *)(puVar4 + 0x13c) = param_3;

    puVar4[0x141] = param_8;

    *(u32 *)(puVar4 + 0x14c) = 0x3f800000;

    *(float *)(puVar4 + 0x144) = (1.0 / (float)iVar5) * (float)iVar6;

    *(float *)(puVar4 + 0x148) = (1.0 / (float)iVar7) * (float)iVar8;

    puVar4[0x150] = 0;

    puVar4[0x18c] = 0;

  }

  return uVar2;

}

// FUN_00427BF0 NONMATCHING


u64

FUN_00427bf0(u32 param_1,u32 param_2,u32 param_3,u32 param_4,

            u32 param_5,u64 param_6,u32 param_7,u64 param_8,

            u32 param_9,u32 *param_10)



{

  long lVar1;

  u64 uVar2;

  int iVar3;

  u8 *puVar4;

  u32 uVar5;

  u32 uVar6;

  u32 uVar7;

  u32 uVar8;

  u32 uStack_20;

  u32 uStack_1c;

  u8 uStack_14;

  u8 uStack_13;

  u8 uStack_12;

  u8 uStack_11;

  

  uVar7 = *param_10;

  uVar8 = param_10[1];

  uVar5 = param_10[2];

  uVar6 = param_10[3];

  lVar1 = (*DAT_00960184)(1,400,0x40000);

  if (lVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = kwlnTaskCreate(param_6,0x6b4440,0x18a7,0x426590,0x427640,lVar1);

    puVar4 = (u8 *)lVar1;

    *puVar4 = 0;

    for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

      uStack_14 = (u8)param_9;

      uStack_13 = (u8)((u32)param_9 >> 8);

      uStack_12 = (u8)((u32)param_9 >> 0x10);

      uStack_11 = (u8)((u32)param_9 >> 0x18);

      puVar4[iVar3 * 4 + 0x110] = uStack_14;

      puVar4[iVar3 * 4 + 0x111] = uStack_13;

      puVar4[iVar3 * 4 + 0x112] = uStack_12;

      puVar4[iVar3 * 4 + 0x113] = uStack_11;

      *(u32 *)(puVar4 + iVar3 * 8 + 0x158) = 0;

      *(u32 *)(puVar4 + iVar3 * 8 + 0x154) = 0;

    }

    uStack_20 = (u32)param_8;

    uStack_1c = (u32)((u32)param_8 >> 0x20);

    *(u32 *)(puVar4 + 0x134) = uStack_20;

    *(u32 *)(puVar4 + 0x138) = uStack_1c;

    *(u32 *)(puVar4 + 0x120) = uVar7;

    *(u32 *)(puVar4 + 0x124) = uVar8;

    *(u32 *)(puVar4 + 0x128) = uVar5;

    *(u32 *)(puVar4 + 300) = uVar6;

    *(u32 *)(puVar4 + 0x130) = param_1;

    *(u32 *)(puVar4 + 0x13c) = param_7;

    puVar4[0x141] = 3;

    *(u32 *)(puVar4 + 0x14c) = 0x3f800000;

    puVar4[0x150] = 1;

    *(u32 *)(puVar4 + 0x174) = param_4;

    *(u32 *)(puVar4 + 0x178) = param_5;

    *(u32 *)(puVar4 + 0x184) = param_2;

    *(u32 *)(puVar4 + 0x188) = param_3;

    puVar4[0x18c] = 0;

  }

  return uVar2;

}

// FUN_00427DB0


void FUN_00427db0(int object, YajimaVec2 value)
{
    YajimaVec2* destination = (YajimaVec2*)(*(int*)(object + 0x3c) + 0x134);

    *destination = value;
}

// FUN_00427DE0


void FUN_00427de0(int param_1,u8 param_2,u8 param_3,u8 param_4,

                 u8 param_5)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

    iVar2 = iVar1 + iVar3 * 4;

    *(u8 *)(iVar2 + 0x110) = param_2;

    *(u8 *)(iVar2 + 0x112) = param_4;

    *(u8 *)(iVar2 + 0x111) = param_3;

    *(u8 *)(iVar2 + 0x113) = param_5;

  }

  return;

}

// FUN_00427E20


void FUN_00427e20(float param_1,float param_2,int param_3)



{

  int iVar1;

  

  iVar1 = *(int *)(param_3 + 0x3c);

  *(int *)(iVar1 + 0x128) = (int)param_1;

  *(int *)(iVar1 + 300) = (int)param_2;

  return;

}

// FUN_00427E50


void FUN_00427e50(int param_1,u8 param_2)



{

  *(u8 *)(*(int *)(param_1 + 0x3c) + 0x150) = param_2;

  return;

}

// FUN_00427E60


void FUN_00427e60(int param_1,u8 param_2)



{

  *(u8 *)(*(int *)(param_1 + 0x3c) + 0x18c) = param_2;

  return;

}

// FUN_00427E70 NONMATCHING


void FUN_00427e70(float param_1,float param_2,float param_3,u32 param_4,int param_5,int param_6,

                 u32 *param_7)



{

  int iVar1;

  float fVar2;

  float afStack_120 [5];

  float fStack_10c;

  float fStack_108;

  float fStack_104;

  float afStack_100 [4];

  u32 uStack_f0;

  u32 uStack_ec;

  u32 uStack_b0;

  u32 uStack_ac;

  u32 uStack_70;

  u32 uStack_6c;

  u32 uStack_30;

  u32 uStack_2c;

  

  iVar1 = kwlnGetMainCamera();

  fVar2 = *(float *)(iVar1 + 0x80);

  (*DAT_00960090)(6,1);

  (*DAT_00960090)(7,2);

  (*DAT_00960090)(8,1);

  (*DAT_00960090)(9,2);

  (*DAT_00960090)(0xc,1);

  (*DAT_00960090)(0xb,6);

  (*DAT_00960090)(10,5);

  (*DAT_00960090)(2,4);

  RpSkyRenderStateSet(2,0x48);

  RpSkyRenderStateSet(3,0x71801);

  afStack_120[0] = param_2;

  afStack_120[1] = param_3;

  fStack_108 = param_2 + (float)param_5;

  fStack_104 = param_3 + (float)param_6;

  afStack_120[2] = param_2 + (float)param_5;

  afStack_120[3] = param_3;

  afStack_120[4] = param_2;

  fStack_10c = param_3 + (float)param_6;

  for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {

    afStack_100[iVar1 * 0x10 + 2] = DAT_00960088 - param_1;

    afStack_100[iVar1 * 0x10 + 6] = 1.0 / fVar2;

    afStack_100[iVar1 * 0x10 + 8] = (float)(param_4 >> 0x18);

    afStack_100[iVar1 * 0x10 + 9] = (float)((param_4 & 0xff0000) >> 0x10);

    afStack_100[iVar1 * 0x10 + 10] = (float)((param_4 & 0xff00) >> 8);

    afStack_100[iVar1 * 0x10 + 0xb] = (float)(param_4 & 0xff);

    afStack_100[iVar1 * 0x10] = afStack_120[iVar1 * 2];

    afStack_100[iVar1 * 0x10 + 1] = afStack_120[iVar1 * 2 + 1];

  }

  uStack_f0 = 0;

  uStack_ec = 0;

  uStack_b0 = 0x3f800000;

  uStack_ac = 0;

  uStack_70 = 0;

  uStack_6c = 0x3f800000;

  uStack_30 = 0x3f800000;

  uStack_2c = 0x3f800000;

  (*DAT_00960090)(1,*param_7);

  (*DAT_009600a0)(4,afStack_100,4);

  return;

}

// FUN_004281F0 NONMATCHING


u32 FUN_004281f0(u32 param_1)



{

  char *pcVar1;

  u8 bVar2;

  u8 uVar3;

  u8 uVar4;

  char cVar5;

  char cVar6;

  int iVar7;

  int iVar8;

  int *piVar9;

  int iVar10;

  long lVar11;

  u64 uVar12;

  int iVar13;

  long lVar14;

  int iVar15;

  u16 uVar16;

  int iVar17;

  u16 uVar18;

  int iVar19;

  char *pcVar20;

  long lVar21;

  int iVar22;

  int iVar23;

  float fVar24;

  float fVar25;

  u32 uVar26;

  float fVar27;
  YajimaVec3 vec;

  YajimaVec3 vec2;

  u8 auStack_a0 [16];

  u8 auStack_90 [8];

  u32 uStack_88;

  u32 uStack_84;

  u8 auStack_80 [8];

  u32 uStack_78;

  u32 uStack_74;

  u32 uStack_68;

  u32 uStack_64;

  u32 uStack_60;

  u32 uStack_58;

  u32 uStack_54;

  u32 uStack_50;

  float fStack_48;

  float fStack_44;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  u64 uStack_30;

  u32 uStack_2c;

  u32 uStack_28;

  int iStack_24;

  int iStack_20;

  int iStack_1c;

  int iStack_18;

  int iStack_14;

  int iStack_10;

  int iStack_c;

  int iStack_8;

  int iStack_4;

  

  pcVar1 = *(char **)((int)param_1 + 0x3c);

  pcVar1[0x938] = '\0';

  pcVar1[0x939] = '\0';

  pcVar1[0x93a] = '\0';

  if (pcVar1[0x864] == '\0') {

    if ((*pcVar1 == '\x0e') || (*pcVar1 == '\x12')) {

      for (iVar15 = 0; iVar15 < 0x10; iVar15 = iVar15 + 1) {

        for (iVar17 = 0; iVar17 < 0x10; iVar17 = iVar17 + 1) {

          if (*(int *)(pcVar1 + iVar17 * 8 + iVar15 * 0x80 + 0x5c) != 0) {

            *(u8 *)

             (*(int *)(*(int *)(pcVar1 + iVar17 * 8 + iVar15 * 0x80 + 0x5c) + 0x3c) + 0x150) = 1;

          }

        }

      }

      if ((DAT_008717e8 != 0 && DAT_008717f4 != 0) && (*(int *)(pcVar1 + 0x898) != 0)) {

        FUN_00456400(*(int *)(pcVar1 + 0x898),0);

      }

      for (iVar15 = 0; iVar15 < 4; iVar15 = iVar15 + 1) {

        if (*(int *)(pcVar1 + iVar15 * 4 + 0x4c) != 0) {

          *(u8 *)(*(int *)(pcVar1 + iVar15 * 4 + 0x4c) + 0x18) = 0xff;

        }

      }

      if (*(int *)(pcVar1 + 0xb1c) != 0) {

        FUN_004302a0();

      }

      return 0;

    }

  }

  else {

    for (iVar15 = 0; iVar15 < 4; iVar15 = iVar15 + 1) {

      if (*(int *)(pcVar1 + iVar15 * 4 + 0x4c) != 0) {

        *(u8 *)(*(int *)(pcVar1 + iVar15 * 4 + 0x4c) + 0x18) = 0;

      }

    }

  }

  switch(*pcVar1) {

  case '\0':

    *pcVar1 = '\x13';

    lVar14 = func_001a01c0();

    if (lVar14 == 1) {

      lVar14 = K_Scene_001a0250();

      if (lVar14 == 1) {

        *pcVar1 = '\x01';

      }

      else {

        lVar14 = func_001a02c0();

        if (lVar14 == 1) {

          *pcVar1 = '\x01';

        }

        else {

          *pcVar1 = '\x0f';

        }

      }

    }

    break;

  case '\x01':

    *pcVar1 = '\x02';

  case '\x02':

    uVar26 = FUN_00431110(param_1,*(u64 *)(pcVar1 + 0x85c),pcVar1[0xb28],0);

    *(u32 *)(pcVar1 + 0xb24) = uVar26;

    *pcVar1 = '\r';

    break;

  case '\x03':

    uVar26 = func_0010c3a0(*(u32 *)(pcVar1 + 0x874),&iStack_4,0);

    *(u32 *)(pcVar1 + 0x28) = uVar26;

    if (iStack_4 != 0) {

      H_Cdvd_Destroy(*(u32 *)(pcVar1 + 4));

      *pcVar1 = '\x04';

    }

    break;

  case '\x04':

    uVar26 = func_0010c3a0(*(u32 *)(pcVar1 + 0x878),&iStack_8,0);

    *(u32 *)(pcVar1 + 0x2c) = uVar26;

    if (iStack_8 != 0) {

      H_Cdvd_Destroy(*(u32 *)(pcVar1 + 8));

      *pcVar1 = '\x05';

    }

    break;

  case '\x05':

    uVar26 = func_0010c3a0(*(u32 *)(pcVar1 + 0x87c),&iStack_c,0);

    *(u32 *)(pcVar1 + 0x30) = uVar26;

    if (iStack_c != 0) {

      H_Cdvd_Destroy(*(u32 *)(pcVar1 + 0xc));

      *pcVar1 = '\x06';

    }

    break;

  case '\x06':

    uVar26 = func_0010c3a0(*(u32 *)(pcVar1 + 0x880),&iStack_10,0);

    *(u32 *)(pcVar1 + 0x34) = uVar26;

    if (iStack_10 != 0) {

      H_Cdvd_Destroy(*(u32 *)(pcVar1 + 0x10));

      *pcVar1 = '\a';

    }

    break;

  case '\a':

    uVar26 = func_0010c3a0(*(u32 *)(pcVar1 + 0x884),&iStack_14,0);

    *(u32 *)(pcVar1 + 0x38) = uVar26;

    if (iStack_14 != 0) {

      H_Cdvd_Destroy(*(u32 *)(pcVar1 + 0x14));

      *pcVar1 = '\b';

    }

    break;

  case '\b':

    uVar26 = func_0010c3a0(*(u32 *)(pcVar1 + 0x888),&iStack_18,0);

    *(u32 *)(pcVar1 + 0x3c) = uVar26;

    if (iStack_18 != 0) {

      H_Cdvd_Destroy(*(u32 *)(pcVar1 + 0x18));

      *pcVar1 = '\t';

    }

    break;

  case '\t':

    uVar26 = func_0010c3a0(*(u32 *)(pcVar1 + 0x88c),&iStack_1c,0);

    *(u32 *)(pcVar1 + 0x40) = uVar26;

    if (iStack_1c != 0) {

      H_Cdvd_Destroy(*(u32 *)(pcVar1 + 0x1c));

      *pcVar1 = '\n';

    }

    break;

  case '\n':

    uVar26 = func_0010c3a0(*(u32 *)(pcVar1 + 0x890),&iStack_20,0);

    *(u32 *)(pcVar1 + 0x44) = uVar26;

    if (iStack_20 != 0) {

      H_Cdvd_Destroy(*(u32 *)(pcVar1 + 0x20));

      *pcVar1 = '\v';

    }

    break;

  case '\v':

    uVar26 = func_0010c3a0(*(u32 *)(pcVar1 + 0x894),&iStack_24,0);

    *(u32 *)(pcVar1 + 0x48) = uVar26;

    if (iStack_24 != 0) {

      H_Cdvd_Destroy(*(u32 *)(pcVar1 + 0x24));

      *pcVar1 = '\f';

    }

    break;

  case '\f':

    uStack_78 = 0x7e;

    uStack_74 = 0x7e;

    if (*(int *)(pcVar1 + 0xb20) != 0) {

      pcVar1[0xb20] = '\0';

      pcVar1[0xb21] = '\0';

      pcVar1[0xb22] = '\0';

      pcVar1[0xb23] = '\0';

    }

    uVar12 = FUN_004229d0(param_1,*(u64 *)(pcVar1 + 0x85c),2);

    *(int *)(pcVar1 + 0xb20) = (int)uVar12;

    FUN_00422c30(uVar12,*(u64 *)(pcVar1 + 0x85c),auStack_80);

    FUN_00422c10(*(u32 *)(pcVar1 + 0xb20),10);

    FUN_00422cd0(*(u32 *)(pcVar1 + 0xb20),1);

    uVar26 = FUN_00431110(param_1,*(u64 *)(pcVar1 + 0x85c),pcVar1[0xb28],0);

    *(u32 *)(pcVar1 + 0xb24) = uVar26;

    *pcVar1 = '\r';

    break;

  case '\r':


    if (*(int *)(pcVar1 + 0xb1c) != 0) {

      pcVar1[0xb1c] = '\0';

      pcVar1[0xb1d] = '\0';

      pcVar1[0xb1e] = '\0';

      pcVar1[0xb1f] = '\0';

    }

    FUN_0042bd80_typed(param_1);

    uVar26 = FUN_00430180(param_1);

    *(u32 *)(pcVar1 + 0xb1c) = uVar26;

    FUN_0042bfd0(param_1);

    for (iVar15 = 0; iVar15 < 3; iVar15 = iVar15 + 1) {
      bVar2 = 0;

      if (((&DAT_008719a8)[iVar15 * 0x70] != 0) &&
          ((&DAT_008719b4)[iVar15 * 0x70] != 0)) {
        bVar2 = 1;
      }

      if (bVar2) {
        cVar6 = pcVar1[0xb29];
        fVar24 = FUN_00429ef0((float)cVar6,0);
        fVar24 = *(float *)(pcVar1 + 0x85c) + fVar24;
        fVar25 = FUN_00429ef0((float)cVar6,(char)(iVar15 + 1));
        fVar24 = fVar24 - fVar25;

        iVar17 = (int)cVar6;
        if (cVar6 < '\0') {
          iVar17 = iVar17 + 3;
        }

        *(float *)(pcVar1 + iVar15 * 8 + 0x8c0) =
            (float)(iVar17 >> 2) + fVar24 + 2.0f;

        cVar6 = pcVar1[0xb29];
        fVar24 = FUN_00429fe0((float)cVar6,0);
        fVar24 = *(float *)(pcVar1 + 0x860) + fVar24;
        fVar25 = FUN_00429fe0((float)cVar6,(char)(iVar15 + 1));
        fVar24 = fVar24 - fVar25;

        iVar17 = (int)cVar6;
        if (cVar6 < '\0') {
          iVar17 = iVar17 + 3;
        }

        *(float *)(pcVar1 + iVar15 * 8 + 0x8c4) =
            (float)(iVar17 >> 2) + fVar24 + 2.0f;

        FUN_00430a40((char)(iVar15 + 1));
      }
    }

    for (iVar15 = 0; iVar15 < 0x18; iVar15 = iVar15 + 1) {
      bVar2 = 0;

      if ((*(int *)(&DAT_0086ede8 + iVar15 * 0x1c0) != 0) &&
          (*(int *)(&DAT_0086edf4 + iVar15 * 0x1c0) != 0)) {
        bVar2 = 1;
      }

      if (bVar2) {
        cVar6 = pcVar1[0xb29];
        fVar24 = FUN_00429ef0((float)cVar6,0);
        fVar24 = *(float *)(pcVar1 + 0x85c) + fVar24;
        fVar25 = FUN_0042a230((float)cVar6,(char)iVar15);
        fVar24 = fVar24 - fVar25;

        iVar17 = (int)cVar6;
        if (cVar6 < '\0') {
          iVar17 = iVar17 + 3;
        }

        *(float *)(pcVar1 + iVar15 * 8 + 0x93c) =
            (float)(iVar17 >> 2) + fVar24 + 2.0f - (float)((int)cVar6 << 1);

        cVar6 = pcVar1[0xb29];
        fVar24 = FUN_00429fe0((float)cVar6,0);
        fVar24 = *(float *)(pcVar1 + 0x860) + fVar24;
        fVar25 = FUN_0042a310((float)cVar6,(char)iVar15);
        fVar24 = fVar24 - fVar25;

        iVar17 = (int)cVar6;
        if (cVar6 < '\0') {
          iVar17 = iVar17 + 3;
        }

        *(float *)(pcVar1 + iVar15 * 8 + 0x940) =
            (float)(iVar17 >> 2) + fVar24 + 2.0f - (float)((int)cVar6 << 1);
      }

      DAT_0095c210[iVar15] = 0;
    }

    for (iVar15 = 0; iVar15 < 0x20; iVar15 = iVar15 + 1) {
      if (*(int *)(&DAT_0086be80 + iVar15 * 0x138) != 0) {
        cVar6 = pcVar1[0xb29];
        fVar24 = FUN_00429ef0((float)cVar6,0);
        fVar24 = *(float *)(pcVar1 + 0x85c) + fVar24;
        fVar25 = FUN_0042a3f0((float)cVar6,
            (float *)(&DAT_0086be80 + iVar15 * 0x138 + 0x10c));
        fVar24 = fVar24 - fVar25;

        iVar17 = (int)cVar6;
        if (cVar6 < '\0') {
          iVar17 = iVar17 + 3;
        }

        *(float *)(pcVar1 + iVar15 * 8 + 0xa00) =
            (float)(iVar17 >> 2) + fVar24 + 2.0f - (float)((int)cVar6 << 1);

        cVar6 = pcVar1[0xb29];
        fVar24 = FUN_00429fe0((float)cVar6,0);
        fVar24 = *(float *)(pcVar1 + 0x860) + fVar24;
        fVar25 = FUN_0042a4a0((float)cVar6,
            (u32 *)(&DAT_0086be80 + iVar15 * 0x138 + 0x10c));
        fVar24 = fVar24 - fVar25;

        iVar17 = (int)cVar6;
        if (cVar6 < '\0') {
          iVar17 = iVar17 + 3;
        }

        *(float *)(pcVar1 + iVar15 * 8 + 0xa04) =
            (float)(iVar17 >> 2) + fVar24 + 2.0f - (float)((int)cVar6 << 1);
      }
    }

    if (DAT_0086e580 == 1) {
      cVar6 = pcVar1[0xb29];
      fVar24 = FUN_00429ef0((float)cVar6,0);
      fVar24 = *(float *)(pcVar1 + 0x85c) + fVar24;
      fVar25 = FUN_0042a3f0((float)cVar6,(float *)0x86e684);
      fVar24 = fVar24 - fVar25;

      iVar15 = (int)cVar6;
      if (cVar6 < '\0') {
        iVar15 = iVar15 + 3;
      }

      *(float *)(pcVar1 + 0xb00) =
          (float)(iVar15 >> 2) + fVar24 + 2.0f - (float)((int)cVar6 << 1);

      cVar6 = pcVar1[0xb29];
      fVar24 = FUN_00429fe0((float)cVar6,0);
      fVar24 = *(float *)(pcVar1 + 0x860) + fVar24;
      fVar25 = FUN_0042a4a0((float)cVar6,(u32 *)0x86e684);
      fVar24 = fVar24 - fVar25;

      iVar15 = (int)cVar6;
      if (cVar6 < '\0') {
        iVar15 = iVar15 + 3;
      }

      *(float *)(pcVar1 + 0xb04) =
          (float)(iVar15 >> 2) + fVar24 + 2.0f - (float)((int)cVar6 << 1);

      cVar6 = FUN_0044f120(0x86e684);
      pcVar1[0xb08] = cVar6;

      cVar6 = FUN_0044f170(0x86e684);
      pcVar1[0xb09] = cVar6;
    }

    FUN_0042fd80((u32 *)&vec,param_1);
    vec2 = vec;

    cVar6 = FUN_0044f120(&vec2);
    pcVar1[0xb0b] = cVar6;

    cVar6 = FUN_0044f170(&vec2);
    pcVar1[0xb0c] = cVar6;

    FUN_00430630(param_1);

    *pcVar1 = '\x0e';

    DAT_007ce6dc = 1;

    break;

  case '\x0e':

    for (iVar15 = 0; iVar15 < 0x10; iVar15 = iVar15 + 1) {

      for (iVar17 = 0; iVar17 < 0x10; iVar17 = iVar17 + 1) {

        iVar13 = iVar17 * 8 + iVar15 * 0x80;

        lVar14 = kwlnTaskExists(*(u32 *)(pcVar1 + iVar13 + 0x5c));

        if (lVar14 == 1) {

          *(u8 *)(*(int *)(*(int *)(pcVar1 + iVar13 + 0x5c) + 0x3c) + 0x150) = 1;

        }

      }

    }

    if (DAT_008717e8 != 0 && DAT_008717f4 != 0) {

      FUN_00423fe0(&fStack_38,0,0x7e,0x7e,4,4);

      *(float *)(pcVar1 + 0x89c) = *(float *)(pcVar1 + 0x85c) + fStack_38;

      *(float *)(pcVar1 + 0x8a0) = *(float *)(pcVar1 + 0x860) + fStack_34;

      FUN_004561d0(*(u32 *)(pcVar1 + 0x89c),*(u32 *)(pcVar1 + 0x8a0),

                   *(u32 *)(pcVar1 + 0x898));

      FUN_00456400(*(u32 *)(pcVar1 + 0x898),1);

      uVar3 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

      uVar4 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4 + 0x1e0));
      FUN_0042a550(param_1,0,(s8)uVar3,(s8)uVar4);


      if (DAT_007ce6c4 == '\0') {

        cVar6 = pcVar1[0xb0b];

        cVar5 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

        if ((cVar6 == cVar5) &&

           (cVar6 = pcVar1[0xb0c], cVar5 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4 + 0x1e0)),

           cVar6 == cVar5)) {

          DAT_007ce6c4 = '\x01';

          DAT_007ce6d8 = 1;

        }

        else {

          iVar15 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

          iVar17 = K_Field_Get();

          iVar13 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

          if (*(char *)(iVar17 + iVar15 * 0x100 + iVar13 * 0x10 + 0x4a) == '\b') {

            DAT_007ce6c4 = '\x01';

            DAT_007ce6d8 = 1;

          }

        }

      }

      if (((DAT_007ce6c8 == '\0') &&

          (cVar6 = pcVar1[0xb08], cVar5 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4 + 0x1e0)),

          cVar6 == cVar5)) &&

         (cVar6 = pcVar1[0xb09], cVar5 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4 + 0x1e0)),

         cVar6 == cVar5)) {

        DAT_007ce6c8 = '\x01';

      }

    }

    if (DAT_008719a8 != 0 && DAT_008719b4 != 0) {

      uVar3 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008719b4 + 0x1e0));

      uVar4 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008719b4 + 0x1e0));
      FUN_0042a550(param_1,1,(s8)uVar3,(s8)uVar4);


    }

    if (DAT_00871b68 != 0 && DAT_00871b74 != 0) {

      uVar3 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_00871b74 + 0x1e0));

      uVar4 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_00871b74 + 0x1e0));
      FUN_0042a550(param_1,2,(s8)uVar3,(s8)uVar4);


    }

    if (DAT_00871d28 != 0 && DAT_00871d34 != 0) {

      uVar3 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_00871d34 + 0x1e0));

      uVar4 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_00871d34 + 0x1e0));
      FUN_0042a550(param_1,3,(s8)uVar3,(s8)uVar4);


    }

    for (iVar15 = 0; iVar15 < pcVar1[0xb28] + 4; iVar15 = iVar15 + 1) {

      for (iVar17 = 0; iVar17 < pcVar1[0xb28] + 4; iVar17 = iVar17 + 1) {

        iVar7 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

        iVar13 = (int)pcVar1[0xb28];

        if (pcVar1[0xb28] < '\0') {

          iVar13 = iVar13 + 1;

        }

        iVar7 = iVar17 + (iVar7 - (iVar13 >> 1));

        iVar19 = iVar7 + -2;

        iVar8 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

        iVar13 = (int)pcVar1[0xb28];

        if (pcVar1[0xb28] < '\0') {

          iVar13 = iVar13 + 1;

        }

        iVar13 = iVar15 + (iVar8 - (iVar13 >> 1)) + -2;

        if (((-1 < iVar19) && (-1 < iVar13)) && ((iVar19 < 0x10 && (iVar13 < 0x10)))) {

          iVar22 = iVar13 * 0x100;

          iVar23 = iVar19 * 0x10;

          iVar8 = K_Field_Get();

          if ((*(char *)(iVar8 + iVar22 + iVar23 + 0x48) == '\x01') &&

             (iVar8 = K_Field_Get(), *(char *)(iVar8 + iVar22 + iVar23 + 0x49) == '\x01')) {

            iVar8 = iVar19 + iVar13 * 0x10;

            piVar9 = (int *)(pcVar1 + iVar8 * 8 + 0x5c);

            lVar14 = kwlnTaskExists(*(u32 *)(pcVar1 + iVar8 * 8 + 0x5c));

            if (lVar14 == 1) {

              *(u8 *)(*(int *)(*piVar9 + 0x3c) + 0x150) = 0;

              if (*(char *)(iVar13 * 0x10 + iVar7 + 0x95c10e) == '\x01') {

                iVar7 = *(int *)(*piVar9 + 0x3c);

                for (iVar8 = 0; iVar8 < 4; iVar8 = iVar8 + 1) {

                  iVar10 = iVar7 + iVar8 * 4;

                  *(u8 *)(iVar10 + 0x110) = 0xff;

                  *(u8 *)(iVar10 + 0x112) = 0xff;

                  *(u8 *)(iVar10 + 0x111) = 0xff;

                  *(u8 *)(iVar10 + 0x113) = 0xff;

                }

              }

              else {

                iVar7 = *(int *)(*piVar9 + 0x3c);

                for (iVar8 = 0; iVar8 < 4; iVar8 = iVar8 + 1) {

                  iVar10 = iVar7 + iVar8 * 4;

                  *(u8 *)(iVar10 + 0x110) = 0xff;

                  *(u8 *)(iVar10 + 0x112) = 0xff;

                  *(u8 *)(iVar10 + 0x111) = 0xff;

                  *(u8 *)(iVar10 + 0x113) = 0;

                }

              }

              if (pcVar1[0x865] == '\0') {
                cVar6 = pcVar1[0xb29];
                fVar24 = FUN_00429ef0((float)cVar6,0);
                fStack_40 = (*(float *)(pcVar1 + 0x85c) +
                             (float)(cVar6 * iVar17) + fVar24) -
                            (float)((int)cVar6 << 1);

                cVar5 = pcVar1[0xb29];
                fVar24 = FUN_00429fe0((float)cVar5,0);
                fStack_3c = (*(float *)(pcVar1 + 0x860) +
                             (float)(cVar5 * iVar15) + fVar24) -
                            (float)((int)cVar5 << 1);
              }
              else {
                cVar6 = pcVar1[0xb29];
                fVar24 = FUN_0042a0d0((float)cVar6,(float *)(pcVar1 + 0x868));
                fStack_40 = (*(float *)(pcVar1 + 0x85c) +
                             (float)(cVar6 * iVar17) + fVar24) -
                            (float)((int)cVar6 << 1);

                cVar5 = pcVar1[0xb29];
                fVar24 = FUN_0042a180((float)cVar5,(u32 *)(pcVar1 + 0x868));
                fStack_3c = (*(float *)(pcVar1 + 0x860) +
                             (float)(cVar5 * iVar15) + fVar24) -
                            (float)((int)cVar5 << 1);
              }

              iVar7 = *(int *)(*piVar9 + 0x3c);

              *(float *)(iVar7 + 0x134) = fStack_40;

              *(float *)(iVar7 + 0x138) = fStack_3c;

            }

            FUN_0042c0a0(param_1,1,(s16)iVar19,(s16)iVar13,iVar17,iVar15);
            FUN_0042c0a0(param_1,2,(s16)iVar19,(s16)iVar13,iVar17,iVar15);
            FUN_0042c0a0(param_1,3,(s16)iVar19,(s16)iVar13,iVar17,iVar15);
            FUN_0042cfc0(param_1,(u16)iVar19,(u16)iVar13,iVar17,iVar15);
            FUN_0042dd90(param_1,(short)iVar19,(u16)iVar13,iVar17,iVar15);
            FUN_0042ea60(param_1,(u16)iVar19,(u16)iVar13,iVar17,iVar15);
            FUN_0042f440(param_1,(short)iVar19,(short)iVar13,iVar17,iVar15);
          }

          uVar16 = (u16)iVar19;

          uVar18 = (u16)iVar13;








          if (((DAT_007ce6c4 == '\x01') &&

              (iVar13 = K_Field_Get(), *(char *)(iVar13 + iVar22 + iVar23 + 0x4a) == '\b')) &&

             (iVar13 = K_Field_Get(), *(char *)(iVar13 + iVar22 + iVar23 + 0x49) == '\x01')) {

            FUN_00430270(auStack_a0,*(u32 *)(pcVar1 + 0xb1c));

            if (pcVar1[0x865] == '\0') {
              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_00429ef0((float)cVar6,0);
              fVar27 = *(float *)(pcVar1 + 0x85c) +
                       (float)(cVar6 * iVar17) + fVar24;
              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_0042a3f0((float)cVar6,(float *)(pcVar1 + 0xb10));
              fVar27 = fVar27 - fVar24 - (float)((int)cVar6 << 1);
              iVar7 = (int)cVar6;
              iVar13 = iVar7;
              if (cVar6 < '\0') iVar13 = iVar7 + 1;
              fStack_48 = (float)(iVar13 >> 1) + fVar27 - 6.0f;

              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_00429fe0((float)cVar6,0);
              fVar27 = *(float *)(pcVar1 + 0x860) +
                       (float)(cVar6 * iVar15) + fVar24;
              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_0042a4a0((float)cVar6,(u32 *)(pcVar1 + 0xb10));
              fVar27 = fVar27 - fVar24 - (float)((int)cVar6 << 1);
              iVar13 = (int)cVar6;
              if (cVar6 < '\0') iVar13 = iVar13 + 1;
              fStack_44 = (float)(iVar13 >> 1) + fVar27;
            }
            else {
              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_0042a0d0((float)cVar6,(float *)(pcVar1 + 0x868));
              fVar27 = *(float *)(pcVar1 + 0x85c) +
                       (float)(cVar6 * iVar17) + fVar24;
              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_0042a3f0((float)cVar6,(float *)(pcVar1 + 0xb10));
              fVar27 = fVar27 - fVar24 - (float)((int)cVar6 << 1);
              iVar7 = (int)cVar6;
              iVar13 = iVar7;
              if (cVar6 < '\0') iVar13 = iVar13 + 1;
              fStack_48 = (float)(iVar13 >> 1) + fVar27 - 6.0f;

              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_0042a180((float)cVar6,(u32 *)(pcVar1 + 0x868));
              fVar27 = *(float *)(pcVar1 + 0x860) +
                       (float)(cVar6 * iVar15) + fVar24;
              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_0042a4a0((float)cVar6,(u32 *)(pcVar1 + 0xb10));
              fVar27 = fVar27 - fVar24 - (float)((int)cVar6 << 1);
              iVar13 = (int)cVar6;
              if (cVar6 < '\0') iVar13 = iVar13 + 1;
              fStack_44 = (float)(iVar13 >> 1) + fVar27;
            }

            fStack_44 = fStack_44 - 6.0f;

            uStack_30 = ((u64)(*(u32 *)&fStack_44) << 32) | *(u32 *)&fStack_48;
            FUN_00430220(*(u32 *)(pcVar1 + 0xb1c),uStack_30);

          }

        }

      }

    }


    FUN_0042cd80(param_1);
    break;

  case '\x0f':

    cVar6 = FUN_0042aa40(param_1,*(u32 *)PTR_DAT_007cd540,

                         *(u32 *)(PTR_DAT_007cd540 + 4));

    pcVar1[0xb2a] = cVar6;

    *pcVar1 = '\x10';

    break;

  case '\x10':

    lVar21 = 0;

    for (lVar14 = 0; lVar14 < pcVar1[0xb2a]; lVar14 = (long)((int)lVar14 + 1)) {

      lVar11 = H_Cdvd_IsFileLoaded(*(u32 *)(pcVar1 + (int)lVar14 * 4 + 4));

      if (lVar11 == 1) {

        lVar21 = (long)((int)lVar21 + 1);

      }

    }

    if (lVar21 == pcVar1[0xb2a]) {


      uStack_88 = 0x7e;

      uStack_84 = 0x7e;

      if (*(int *)(pcVar1 + 0xb20) != 0) {

        pcVar1[0xb20] = '\0';

        pcVar1[0xb21] = '\0';

        pcVar1[0xb22] = '\0';

        pcVar1[0xb23] = '\0';

      }

      uVar12 = FUN_004229d0(param_1,*(u64 *)(pcVar1 + 0x85c),2);

      *(int *)(pcVar1 + 0xb20) = (int)uVar12;

      FUN_00422c30(uVar12,*(u64 *)(pcVar1 + 0x85c),auStack_90);

      FUN_00422c10(*(u32 *)(pcVar1 + 0xb20),10);

      FUN_00422cd0(*(u32 *)(pcVar1 + 0xb20),1);

      lVar14 = 0;

      while (lVar14 < pcVar1[0xb2a]) {

        iVar15 = (int)lVar14;

        pcVar20 = pcVar1 + iVar15 * 4 + 4;

        if (*(int *)(pcVar1 + iVar15 * 4 + 4) != 0) {

          H_Cdvd_Destroy();

          pcVar20[0] = '\0';

          pcVar20[1] = '\0';

          pcVar20[2] = '\0';

          pcVar20[3] = '\0';

        }

        lVar14 = (long)(iVar15 + 1);

      }

      FUN_0042ac60(param_1,*(u64 *)PTR_DAT_007cd540);
      *pcVar1 = '\x11';

    }

    break;

  case '\x11':

    FUN_0042ba50(param_1);

    uVar26 = FUN_00431110(param_1,*(u64 *)(pcVar1 + 0x85c),pcVar1[0xb28],1);

    *(u32 *)(pcVar1 + 0xb24) = uVar26;
    FUN_0042bc10(param_1);


    DAT_007ce6dc = 1;

    FUN_00430630(param_1);

    *pcVar1 = '\x12';

    break;

  case '\x12':

    FUN_00422cd0(*(u32 *)(pcVar1 + 0xb20),1);

    if (DAT_008717e8 != 0 && DAT_008717f4 != 0) {

      FUN_00456400(*(u32 *)(pcVar1 + 0x898),1);

    }

    for (lVar14 = 0; lVar14 < pcVar1[0xb2a]; lVar14 = (long)((int)lVar14 + 1)) {

      *(u8 *)(*(int *)(*(int *)(pcVar1 + (int)lVar14 * 8 + 0x5c) + 0x3c) + 0x150) = 0;

    }




    FUN_0042adb0(param_1);
    FUN_0042b050(param_1);
    FUN_0042b540(param_1);
    break;

  case '\x13':

    return 0xffffffff;

  }

  if ((DAT_007e0988 & 0x10) != 0) {

    uStack_58 = 0;

    uStack_54 = 0;

    uStack_50 = 0;

    uVar26 = RwV3dLength(&uStack_58);

    uVar12 = FUN_00530da0(uVar26);

    printf(0x6b4458,uVar12);

  }

  return 0;

}

// FUN_00429C60 NONMATCHING


void FUN_00429c60(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  for (iVar3 = 0; iVar3 < 9; iVar3 = iVar3 + 1) {

    iVar2 = iVar1 + iVar3 * 4;

    if (*(int *)(iVar2 + 0x28) != 0) {

      FUN_004d0f00();

      *(u32 *)(iVar2 + 0x28) = 0;

    }

  }

  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

    iVar2 = iVar1 + iVar3 * 4;

    if (*(int *)(iVar2 + 0x4c) != 0) {

      FUN_00115980();

      *(u32 *)(iVar2 + 0x4c) = 0;

    }

  }

  (*DAT_0096017c)(*(u32 *)(param_1 + 0x3c));

  return;

}

// FUN_00429D40 NONMATCHING


u64 FUN_00429d40(u64 param_1,u64 param_2)



{

  long lVar1;

  u64 uVar2;

  short sVar3;

  u8 *puVar4;

  u32 uStack_8;

  u32 uStack_4;

  

  lVar1 = func_001ddd30();

  if (lVar1 == 0) {

    uVar2 = 0;

  }

  else {

    lVar1 = (*DAT_00960184)(1,0xbb4,0x40000);

    if (lVar1 == 0) {

      uVar2 = 0;

    }

    else {

      uVar2 = kwlnTaskCreateWithAutoPriority(param_1,0x106f,0x6b4470,0x4281f0,0x429c60,lVar1);

      uStack_8 = (u32)param_2;

      uStack_4 = (u32)((u32)param_2 >> 0x20);

      puVar4 = (u8 *)lVar1;

      *(u32 *)(puVar4 + 0x85c) = uStack_8;

      *(u32 *)(puVar4 + 0x860) = uStack_4;

      *puVar4 = 0;

      puVar4[0x9fe] = 0;

      puVar4[0x9ff] = 0;

      puVar4[0xb28] = 7;

      puVar4[0xb29] = 0x12;

      *(u16 *)(puVar4 + 0xb90) = 0xffff;

      puVar4[0xb0a] = 1;

      *(u16 *)(puVar4 + 0x9fc) = 0;

      for (sVar3 = 0; sVar3 < 3; sVar3 = sVar3 + 1) {

        *(u16 *)(puVar4 + sVar3 * 2 + 0x932) = 0;

      }

      puVar4[0x865] = 0;

      puVar4[0x864] = 0;

      uGpffffb9ec = 0;

    }

  }

  return uVar2;

}

// FUN_00429E80


void FUN_00429e80(int param_1,u8 param_2)



{

  *(u8 *)(*(int *)(param_1 + 0x3c) + 0x864) = param_2;

  return;

}

// FUN_00429E90


void FUN_00429e90(int param_1,u8 param_2)



{

  int iVar1;

  YajimaVec3 local_20;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  *(u8 *)(iVar1 + 0x865) = param_2;

  K_FldFrame_CtlCopyPos(&local_20,*(u32 *)(DAT_008717f4[0] + 0x1e0));

  *(YajimaVec3 *)(iVar1 + 0x868) = local_20;

  return;

}

// FUN_00429EF0


float FUN_00429ef0(float param_1,char param_2)
{
  int iVar1;
  volatile YajimaVec3 saved;
  YajimaVec3 pos;
  float x;
  float z;
  float y;
  float grid;
  float base;
  float delta;
  float ratio;
  float half;

  K_FldFrame_CtlCopyPos(&pos,
      *(u32 *)(*(u32 *)(DAT_008717f4_abs + (s32)(s8)param_2 * 0x1c0) + 0x1e0));
  saved = *(YajimaVec3 *)&pos;
  iVar1 = K_FldFrame_CtlGetXGrid(
      *(u32 *)(*(u32 *)(DAT_008717f4_abs + (s32)(s8)param_2 * 0x1c0) + 0x1e0));
  grid = (float)iVar1;
  asm volatile("" : "+f"(grid));
  base = grid * 800.0f;
  base = base - 400.0f;
  delta = saved.x - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return (float)(int)(half + 0.0f - delta * ratio);
}

// FUN_00429FE0


float FUN_00429fe0(float param_1,char param_2)
{
  int iVar1;
  volatile YajimaVec3 saved;
  YajimaVec3 pos;
  float x;
  float z;
  float y;
  float grid;
  float base;
  float delta;
  float ratio;
  float half;

  K_FldFrame_CtlCopyPos(&pos,
      *(u32 *)(*(u32 *)(DAT_008717f4_abs + (s32)(s8)param_2 * 0x1c0) + 0x1e0));
  saved = *(YajimaVec3 *)&pos;
  iVar1 = K_FldFrame_CtlGetZGrid(
      *(u32 *)(*(u32 *)(DAT_008717f4_abs + (s32)(s8)param_2 * 0x1c0) + 0x1e0));
  grid = (float)iVar1;
  asm volatile("" : "+f"(grid));
  base = grid * 800.0f;
  base = base - 400.0f;
  delta = saved.z - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return (float)(int)(half + 0.0f - delta * ratio);
}

// FUN_0042A0D0 NONMATCHING


float FUN_0042a0d0(float param_1,float *param_2)



{

  int iVar1;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  

  fStack_10 = *param_2;

  fStack_c = param_2[1];

  fStack_8 = param_2[2];

  iVar1 = FUN_0044f120(&fStack_10);

  return (float)(int)((param_1 / 2.0 + 0.0) -

                     (fStack_10 - ((float)iVar1 * 800.0 - 400.0)) * (param_1 / 800.0));

}

// FUN_0042A180


float FUN_0042a180(float param_1,u32 *param_2)
{
  int iVar1;
  YajimaVec3 pos = *(YajimaVec3 *)param_2;
  float grid;
  float base;
  float delta;
  float ratio;
  float half;

  iVar1 = FUN_0044f170(&pos);
  grid = (float)iVar1;
  asm volatile("" : "+f"(grid));
  base = grid * 800.0f;
  base = base - 400.0f;
  delta = pos.z - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return (float)(int)(half + 0.0f - delta * ratio);
}

// FUN_0042A230


float FUN_0042a230(float param_1,char param_2)
{
  int iVar1;
  volatile YajimaVec3 saved;
  YajimaVec3 pos;
  float z;
  float x;
  float y;
  float grid;
  float base;
  float delta;
  float ratio;
  float half;
  K_FldFrame_CtlCopyPos(&pos,
      *(u32 *)(*(u32 *)(DAT_0086edf4_abs + (s32)(s8)param_2 * 0x1c0) + 0x1e0));
  saved = *(YajimaVec3 *)&pos;
  iVar1 = K_FldFrame_CtlGetXGrid(
      *(u32 *)(*(u32 *)(DAT_0086edf4_abs + (s32)(s8)param_2 * 0x1c0) + 0x1e0));
  grid = (float)iVar1;
  asm volatile("" : "+f"(grid));
  base = grid * 800.0f;
  base = base - 400.0f;
  delta = saved.x - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return half + 0.0f - delta * ratio;
}

// FUN_0042A310


float FUN_0042a310(float param_1,char param_2)
{
  int iVar1;
  volatile YajimaVec3 saved;
  YajimaVec3 pos;
  float x;
  float z;
  float y;
  float grid;
  float base;
  float delta;
  float ratio;
  float half;

  K_FldFrame_CtlCopyPos(&pos,
      *(u32 *)(*(u32 *)(DAT_0086edf4_abs + (s32)(s8)param_2 * 0x1c0) + 0x1e0));
  saved = *(YajimaVec3 *)&pos;
  iVar1 = K_FldFrame_CtlGetZGrid(
      *(u32 *)(*(u32 *)(DAT_0086edf4_abs + (s32)(s8)param_2 * 0x1c0) + 0x1e0));
  grid = (float)iVar1;
  asm volatile("" : "+f"(grid));
  base = grid * 800.0f;
  base = base - 400.0f;
  delta = saved.z - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return half + 0.0f - delta * ratio;
}

// FUN_0042A3F0 NONMATCHING


float FUN_0042a3f0(float param_1,float *param_2)



{

  int iVar1;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  

  fStack_10 = *param_2;

  fStack_c = param_2[1];

  fStack_8 = param_2[2];

  iVar1 = FUN_0044f120(&fStack_10);

  return (param_1 / 2.0 + 0.0) - (fStack_10 - ((float)iVar1 * 800.0 - 400.0)) * (param_1 / 800.0);

}

// FUN_0042A4A0


float FUN_0042a4a0(float param_1,u32 *param_2)
{
  int iVar1;
  YajimaVec3 pos = *(YajimaVec3 *)param_2;
  float grid;
  float base;
  float delta;
  float ratio;
  float half;

  iVar1 = FUN_0044f170(&pos);
  grid = (float)iVar1;
  asm volatile("" : "+f"(grid));
  base = grid * 800.0f;
  base = base - 400.0f;
  delta = pos.z - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return half + 0.0f - delta * ratio;
}

// FUN_0042A550 NONMATCHING


void FUN_0042a550(int param_1,u64 param_2,u64 param_3,u64 param_4)



{

  char cVar1;

  char cVar2;

  u32 uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  long lVar7;

  char cVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  

  iVar5 = *(int *)(param_1 + 0x3c);

  uVar3 = FUN_00433810(param_3,param_4);

  cVar8 = (char)param_3;

  cVar1 = (char)param_4;

  if ((uVar3 & 0xff) == 0) {

    DAT_0095c110[cVar1 * 0x10 + (int)cVar8] = 1;

  }

  else {

    DAT_0095c110[uVar3 & 0xff] = 1;

  }

  iVar10 = cVar1 * 0x100;

  iVar11 = cVar8 * 0x10;

  iVar4 = K_Field_Get();

  iVar6 = (int)cVar8;

  if ((*(u8 *)(iVar4 + iVar10 + iVar11 + 0x53) & 8) != 0) {

    uVar3 = FUN_00433810(cVar8 + '\x01',param_4);

    if ((uVar3 & 0xff) == 0) {

      *(u8 *)(cVar1 * 0x10 + iVar6 + 0x95c111) = 1;

    }

    else {

      DAT_0095c110[uVar3 & 0xff] = 1;

    }

  }

  iVar4 = K_Field_Get();

  iVar9 = (int)cVar1;

  if ((*(u8 *)(iVar4 + iVar10 + iVar11 + 0x53) & 2) != 0) {

    uVar3 = FUN_00433810(cVar8 + -1,param_4);

    if ((uVar3 & 0xff) == 0) {

      *(u8 *)(iVar9 * 0x10 + iVar6 + 0x95c10f) = 1;

    }

    else {

      DAT_0095c110[uVar3 & 0xff] = 1;

    }

  }

  iVar4 = K_Field_Get();

  if ((*(u8 *)(iVar4 + iVar10 + iVar11 + 0x53) & 1) != 0) {

    uVar3 = FUN_00433810(param_3,cVar1 + -1);

    if ((uVar3 & 0xff) == 0) {

      *(u8 *)((int)&DAT_0095c100 + iVar9 * 0x10 + iVar6) = 1;

    }

    else {

      DAT_0095c110[uVar3 & 0xff] = 1;

    }

  }

  iVar4 = K_Field_Get();

  if ((*(u8 *)(iVar4 + iVar10 + iVar11 + 0x53) & 4) != 0) {

    uVar3 = FUN_00433810(param_3,cVar1 + '\x01');

    if ((uVar3 & 0xff) == 0) {

      *(u8 *)(iVar9 * 0x10 + iVar6 + 0x95c120) = 1;

    }

    else {

      DAT_0095c110[uVar3 & 0xff] = 1;

    }

  }

  cVar8 = (char)param_2;

  if (cVar8 == '\0') {

    lVar7 = FUN_004352e0();

    if (((lVar7 == 0) && (cGpffffb9d8 == '\0')) &&

       (DAT_0095c110[*(char *)(iVar5 + 0xb09) * 0x10 + (int)*(char *)(iVar5 + 0xb08)] == '\x01'))

    {

      cGpffffb9d8 = '\x01';

    }

  }

  else {

    cVar1 = FUN_00435260(param_2);

    if (cVar1 == '\0') {

      cVar1 = FUN_004353f0(&DAT_008717a0 + cVar8 * 0x1c0);

      if (((cVar1 != '\x01') && (cGpffffb9d8 == '\0')) &&

         (DAT_0095c110[*(char *)(iVar5 + 0xb09) * 0x10 + (int)*(char *)(iVar5 + 0xb08)] == '\x01'

         )) {

        FUN_00456490(param_2);

        cGpffffb9d8 = '\x01';

      }

      if (cGpffffb9d4 == '\0') {

        cVar1 = *(char *)(iVar5 + 0xb0b);

        cVar2 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4[cVar8 * 0x70] + 0x1e0));

        if ((cVar1 == cVar2) &&

           (cVar1 = *(char *)(iVar5 + 0xb0c),

           cVar2 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4[cVar8 * 0x70] + 0x1e0)),

           cVar1 == cVar2)) {

          lVar7 = FUN_0043c730(param_2);

          if (lVar7 == 1) {

            cVar8 = FUN_004353f0(&DAT_008717a0 + cVar8 * 0x1c0);

            if (cVar8 != '\x01') {

              FUN_00456450(param_2);

            }

            cGpffffb9d4 = '\x01';

          }

        }

        else {

          iVar5 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4[cVar8 * 0x70] + 0x1e0));

          iVar4 = K_Field_Get();

          iVar6 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4[cVar8 * 0x70] + 0x1e0));

          if (*(char *)(iVar4 + iVar5 * 0x100 + iVar6 * 0x10 + 0x4a) == '\b') {

            cGpffffb9d4 = '\x01';

          }

        }

      }

    }

  }

  return;

}

// FUN_0042AA40 NONMATCHING


u8 FUN_0042aa40(int param_1,u32 param_2,u32 param_3)



{

  int iVar1;

  char cVar2;

  u8 uVar3;

  u32 uVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  cVar2 = (char)param_2 + -0x1f;

  for (iVar7 = 0; iVar7 < 10; iVar7 = iVar7 + 1) {

    *(u16 *)(iVar1 + iVar7 * 2 + 0xb7c) = 0xffff;

  }

  *(u16 *)(iVar1 + 0xb90) = 0xffff;

  iVar9 = (cVar2 * 0xf0 + (int)cVar2) * 4;

  for (iVar7 = 0; piVar5 = (int *)(iVar9 + iGpffffb5c0), iVar7 < *piVar5; iVar7 = iVar7 + 1) {

    if ((param_2 == *(u16 *)(piVar5 + iVar7 * 10 + 2)) &&

       (param_3 == *(u16 *)((int)piVar5 + iVar7 * 0x28 + 10))) {

      *(short *)(iVar1 + 0xb90) = (short)iVar7;

    }

  }

  if (*(short *)(iVar1 + 0xb90) == -1) {

    uVar3 = 0;

  }

  else {

    iVar7 = piVar5[*(short *)(iVar1 + 0xb90) * 10 + 1];

    iVar10 = 0;

    for (iVar8 = 0; iVar8 < *(int *)(iVar9 + iGpffffb5c0); iVar8 = iVar8 + 1) {

      if ((long)(char)iVar7 == (long)((int *)(iVar9 + iGpffffb5c0))[iVar8 * 10 + 1]) {

        for (iVar6 = 0; iVar6 < 0xff; iVar6 = iVar6 + 1) {

          (&DAT_0095bee0)[iVar6] = 0;

        }

        *(short *)(iVar1 + iVar10 * 2 + 0xb7c) = (short)iVar8;

        sprintf(0x95bee0,0x6b4490,param_2,

                     *(u16 *)(iVar9 + iGpffffb5c0 + iVar8 * 0x28 + 10));

        uVar4 = H_Cdvd_Request(0x95bee0,0);

        *(u32 *)(iVar1 + iVar10 * 4 + 4) = uVar4;

        iVar10 = iVar10 + 1;

      }

    }

    uVar3 = (u8)iVar10;

  }

  return uVar3;

}

// FUN_0042AC60 NONMATCHING


void FUN_0042ac60(int param_1,u64 param_2)



{

  int iVar1;

  char cVar2;

  u32 uVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  cVar2 = (char)param_2 + -0x1f;

  iVar6 = (cVar2 * 0xf0 + (int)cVar2) * 4;

  cVar2 = *(char *)(*(short *)(iVar1 + 0xb90) * 0x28 + iVar6 + iGpffffb5c0 + 4);

  iVar7 = 0;

  for (iVar8 = 0; piVar4 = (int *)(iVar6 + iGpffffb5c0), iVar8 < *piVar4; iVar8 = iVar8 + 1) {

    if ((long)cVar2 == (long)piVar4[iVar8 * 10 + 1]) {

      for (iVar5 = 0; iVar5 < 0xff; iVar5 = iVar5 + 1) {

        (&DAT_0095bfe0)[iVar5] = 0;

      }

      sprintf(0x95bfe0,0x6b44b0,param_2,*(u16 *)((int)piVar4 + iVar8 * 0x28 + 10));

      uVar3 = FUN_004d1260(0x95bfe0,0);

      *(u32 *)(iVar1 + iVar7 * 4 + 0x28) = uVar3;

      iVar7 = iVar7 + 1;

    }

  }

  return;

}

// FUN_0042ADB0 NONMATCHING


void FUN_0042adb0(int param_1)



{

  int iVar1;

  u32 *puVar2;

  u64 uVar3;

  int iVar4;

  long lVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fStack_58;

  float fStack_54;

  float fStack_50;

  float afStack_48 [2];

  float fStack_40;

  float fStack_38;

  float fStack_34;

  float fStack_30;

  u64 uStack_28;

  u32 uStack_20;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_8;

  float fStack_4;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  K_FldFrame_CtlCopyPos(&fStack_58,*(u32 *)(DAT_008717f4 + 0x1e0));

  fStack_18 = fStack_58;

  fStack_14 = fStack_54;

  fStack_10 = fStack_50;

  uStack_28 = DAT_006b44c0;

  uStack_20 = DAT_006b44c8;

  if (*(char *)(iVar1 + 0x865) == '\x01') {

    fStack_18 = *(float *)(iVar1 + 0x868);

    fStack_14 = *(float *)(iVar1 + 0x86c);

    fStack_10 = *(float *)(iVar1 + 0x870);

  }

  uVar3 = FUN_004c38c0();

  puVar2 = (u32 *)uVar3;

  puVar2[10] = 0x3f800000;

  puVar2[5] = 0x3f800000;

  *puVar2 = 0x3f800000;

  puVar2[4] = 0;

  puVar2[2] = 0;

  puVar2[1] = 0;

  puVar2[9] = 0;

  puVar2[8] = 0;

  puVar2[6] = 0;

  puVar2[0xe] = 0;

  puVar2[0xd] = 0;

  puVar2[0xc] = 0;

  puVar2[3] = puVar2[3] | 0x20003;

  RwMatrixRotate(*(u32 *)

                (*(short *)(iVar1 + 0xb90) * 0x28 + *piGpffffa850 * 0x3c4 + iGpffffb5c0 + -0x74a0),

               uVar3,&uStack_28,2);

  fStack_38 = *(float *)(iVar1 + 0xba4) - fStack_18;

  fStack_34 = *(float *)(iVar1 + 0xba8) - fStack_14;

  fStack_30 = *(float *)(iVar1 + 0xbac) - fStack_10;

  RwV3dTransformPoint(afStack_48,&fStack_38,uVar3);

  fVar6 = *(float *)(iVar1 + 0xba4);

  iVar4 = *(short *)(iVar1 + 0xb90) * 0x28 + *piGpffffa850 * 0x3c4 + iGpffffb5c0;

  fVar8 = *(float *)(iVar4 + -0x749c);

  fVar9 = *(float *)(iVar4 + -0x74a8);

  fVar7 = *(float *)(iVar1 + 0xbac);

  fVar10 = *(float *)(iVar4 + -0x7494);

  fVar11 = *(float *)(iVar4 + -0x74a4);

  for (lVar5 = 0; lVar5 < *(char *)(iVar1 + 0xb2a); lVar5 = (long)((int)lVar5 + 1)) {

    iVar4 = iVar1 + (int)lVar5 * 8;

    fStack_8 = *(float *)(iVar4 + 0xb2c) +

               ((63.0 - (((fVar6 - afStack_48[0]) - fVar8) * 2.25) / 100.0) - fVar9);

    fStack_4 = *(float *)(iVar4 + 0xb30) +

               ((63.0 - (((fVar7 - fStack_40) - fVar10) * 2.25) / 100.0) - fVar11);

    iVar4 = *(int *)(*(int *)(iVar4 + 0x5c) + 0x3c);

    *(float *)(iVar4 + 0x134) = fStack_8;

    *(float *)(iVar4 + 0x138) = fStack_4;

  }

  FUN_004c3880(uVar3);

  return;

}

// FUN_0042B050 NONMATCHING


void FUN_0042b050(int param_1)



{

  int iVar1;

  u8 bVar2;

  u32 *puVar3;

  int iVar4;

  u64 uVar5;

  u64 uVar6;

  int iVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fStack_50;

  u32 uStack_4c;

  float fStack_48;

  float afStack_40 [4];

  u64 uStack_30;

  u32 uStack_28;

  float afStack_20 [2];

  float fStack_18;

  float fStack_10;

  u32 uStack_c;

  float fStack_8;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  K_FldFrame_CtlCopyPos(&fStack_50,*(u32 *)(DAT_008717f4 + 0x1e0));

  fStack_10 = fStack_50;

  uStack_c = uStack_4c;

  fStack_8 = fStack_48;

  uStack_30 = DAT_006b44d0;

  uStack_28 = DAT_006b44d8;

  if (*(char *)(iVar1 + 0x865) == '\x01') {

    fStack_10 = *(float *)(iVar1 + 0x868);

    uStack_c = *(u32 *)(iVar1 + 0x86c);

    fStack_8 = *(float *)(iVar1 + 0x870);

  }

  fVar9 = fStack_8;

  for (iVar7 = 1; iVar7 < 4; iVar7 = iVar7 + 1) {

    bVar2 = 0;

    if ((DAT_008717e8[iVar7 * 0x70] != 0) && (DAT_008717f4[iVar7 * 0x70] != 0)) {

      bVar2 = 1;

    }

    if (bVar2) {

      uVar5 = FUN_004c38c0();

      puVar3 = (u32 *)uVar5;

      puVar3[10] = 0x3f800000;

      puVar3[5] = 0x3f800000;

      *puVar3 = 0x3f800000;

      puVar3[4] = 0;

      puVar3[2] = 0;

      puVar3[1] = 0;

      puVar3[9] = 0;

      puVar3[8] = 0;

      puVar3[6] = 0;

      puVar3[0xe] = 0;

      puVar3[0xd] = 0;

      puVar3[0xc] = 0;

      puVar3[3] = puVar3[3] | 0x20003;

      K_FldFrame_CtlCopyPos(afStack_20,*(u32 *)(DAT_008717f4[iVar7 * 0x70] + 0x1e0));

      RwMatrixRotate(*(u32 *)

                    (iGpffffb5c0 + *piGpffffa850 * 0x3c4 + *(short *)(iVar1 + 0xb90) * 0x28 +

                    -0x74a0),uVar5,&uStack_30,2);

      iVar4 = iGpffffb5c0 + *piGpffffa850 * 0x3c4 + *(short *)(iVar1 + 0xb90) * 0x28;

      fVar11 = 63.0f - ((((*(float *)(iVar1 + 0xba4) - (*(float *)(iVar4 + -0x749c) - afStack_20[0]))

                        * 2.25f) / 100.0f) * 2.25f) / 100.0f;

      fVar12 = 63.0f - ((((*(float *)(iVar1 + 0xbac) - (*(float *)(iVar4 + -0x7494) - fStack_18)) *

                        2.25f) / 100.0f) * 2.25f) / 100.0f;

      afStack_40[0] = ((afStack_20[0] - fStack_10) * 2.25f) / 100.0f;

      afStack_40[2] = ((fStack_18 - fVar9) * 2.25f) / 100.0f;

      afStack_40[1] = 0.0f;

      RwV3dTransformPoint(afStack_40,afStack_40,uVar5);

      uVar6 = FUN_001158b0(0,uGpffffb9f4,7);

      iVar4 = (int)uVar6;

      *(u32 *)(iVar4 + 0x2c) = 0x40000000;

      fVar8 = (float)func_001126b0(uVar6);

      *(float *)(iVar4 + 0x10) = (afStack_40[0] + *(float *)(iVar1 + 0x85c) + fVar11) - fVar8 / 2.0f;

      fVar8 = (float)func_00112740(uVar6);

      *(float *)(iVar4 + 0x14) = (afStack_40[2] + *(float *)(iVar1 + 0x860) + fVar12) - fVar8 / 2.0f;

      *(u8 *)(iVar4 + 0x18) = 0xff;

      fVar10 = *(float *)(iVar1 + 0x85c);

      fVar8 = (float)func_001126b0(uVar6);

      if ((((fVar10 < ((afStack_40[0] + fVar10 + fVar11) - fVar8 / 2.0f) + 8.0f) &&

           (fVar10 = *(float *)(iVar1 + 0x860), fVar8 = (float)func_00112740(uVar6),

           fVar10 < ((afStack_40[2] + fVar10 + fVar12) - fVar8 / 2.0f) + 8.0f)) &&

          (fVar10 = *(float *)(iVar1 + 0x85c), fVar8 = (float)func_001126b0(uVar6),

          ((afStack_40[0] + fVar10 + fVar11) - fVar8 / 2.0f) + 12.0f < fVar10 + 126.0f)) &&

         (fVar10 = *(float *)(iVar1 + 0x860), fVar8 = (float)func_00112740(uVar6),

         ((afStack_40[2] + fVar10 + fVar12) - fVar8 / 2.0f) + 12.0f < fVar10 + 126.0f)) {

        *(u8 *)(iVar4 + 0x18) = 0;

      }

      func_001127d0(uVar6,1);

      FUN_00115980(uVar6);

      FUN_004c3880(uVar5);

    }

  }

  return;

}

// FUN_0042B540 NONMATCHING


void FUN_0042b540(int param_1)



{

  int iVar1;

  u8 bVar2;

  u32 *puVar3;

  u64 uVar4;

  u64 uVar5;

  int iVar6;

  int iVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fStack_50;

  u32 uStack_4c;

  float fStack_48;

  float afStack_40 [4];

  u64 uStack_30;

  u32 uStack_28;

  float afStack_20 [2];

  float fStack_18;

  float fStack_10;

  u32 uStack_c;

  float fStack_8;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  K_FldFrame_CtlCopyPos(&fStack_50,*(u32 *)(DAT_008717f4 + 0x1e0));

  fStack_10 = fStack_50;

  uStack_c = uStack_4c;

  fStack_8 = fStack_48;

  uStack_30 = DAT_006b44e0;

  uStack_28 = DAT_006b44e8;

  if (*(char *)(iVar1 + 0x865) == '\x01') {

    fStack_10 = *(float *)(iVar1 + 0x868);

    uStack_c = *(u32 *)(iVar1 + 0x86c);

    fStack_8 = *(float *)(iVar1 + 0x870);

  }

  fVar9 = fStack_8;

  for (iVar7 = 0; iVar7 < 0x18; iVar7 = iVar7 + 1) {

    bVar2 = 0;

    iVar6 = iVar7 * 0x1c0;

    if ((*(int *)(&DAT_0086ede8 + iVar6) != 0) && (*(int *)(&DAT_0086edf4 + iVar6) != 0)) {

      bVar2 = 1;

    }

    if (bVar2) {

      uVar4 = FUN_004c38c0();

      puVar3 = (u32 *)uVar4;

      puVar3[10] = 0x3f800000;

      puVar3[5] = 0x3f800000;

      *puVar3 = 0x3f800000;

      puVar3[4] = 0;

      puVar3[2] = 0;

      puVar3[1] = 0;

      puVar3[9] = 0;

      puVar3[8] = 0;

      puVar3[6] = 0;

      puVar3[0xe] = 0;

      puVar3[0xd] = 0;

      puVar3[0xc] = 0;

      puVar3[3] = puVar3[3] | 0x20003;

      K_FldFrame_CtlCopyPos(afStack_20,*(u32 *)(*(int *)(&DAT_0086edf4 + iVar6) + 0x1e0));

      RwMatrixRotate(*(u32 *)

                    (iGpffffb5c0 + *piGpffffa850 * 0x3c4 + *(short *)(iVar1 + 0xb90) * 0x28 +

                    -0x74a0),uVar4,&uStack_30,2);

      iVar6 = iGpffffb5c0 + *piGpffffa850 * 0x3c4 + *(short *)(iVar1 + 0xb90) * 0x28;

      fVar11 = 63.0f - ((((*(float *)(iVar1 + 0xba4) - (*(float *)(iVar6 + -0x749c) - afStack_20[0]))

                        * 2.25f) / 100.0f) * 2.25f) / 100.0f;

      fVar12 = 63.0f - ((((*(float *)(iVar1 + 0xbac) - (*(float *)(iVar6 + -0x7494) - fStack_18)) *

                        2.25f) / 100.0f) * 2.25f) / 100.0f;

      afStack_40[0] = ((afStack_20[0] - fStack_10) * 2.25f) / 100.0f;

      afStack_40[2] = ((fStack_18 - fVar9) * 2.25f) / 100.0f;

      afStack_40[1] = 0.0f;

      RwV3dTransformPoint(afStack_40,afStack_40,uVar4);

      uVar5 = FUN_001158b0(0,uGpffffb9f4,0xb);

      iVar6 = (int)uVar5;

      *(u32 *)(iVar6 + 0x2c) = 0x40000000;

      fVar8 = (float)func_001126b0(uVar5);

      *(float *)(iVar6 + 0x10) = (afStack_40[0] + *(float *)(iVar1 + 0x85c) + fVar11) - fVar8 / 2.0f;

      fVar8 = (float)func_00112740(uVar5);

      *(float *)(iVar6 + 0x14) = (afStack_40[2] + *(float *)(iVar1 + 0x860) + fVar12) - fVar8 / 2.0f;

      *(u8 *)(iVar6 + 0x18) = 0xff;

      fVar10 = *(float *)(iVar1 + 0x85c);

      fVar8 = (float)func_001126b0(uVar5);

      if ((((fVar10 < ((afStack_40[0] + fVar10 + fVar11) - fVar8 / 2.0f) + 8.0f) &&

           (fVar10 = *(float *)(iVar1 + 0x860), fVar8 = (float)func_00112740(uVar5),

           fVar10 < ((afStack_40[2] + fVar10 + fVar12) - fVar8 / 2.0f) + 8.0f)) &&

          (fVar10 = *(float *)(iVar1 + 0x85c), fVar8 = (float)func_001126b0(uVar5),

          ((afStack_40[0] + fVar10 + fVar11) - fVar8 / 2.0f) + 12.0f < fVar10 + 126.0f)) &&

         (fVar10 = *(float *)(iVar1 + 0x860), fVar8 = (float)func_00112740(uVar5),

         ((afStack_40[2] + fVar10 + fVar12) - fVar8 / 2.0f) + 12.0f < fVar10 + 126.0f)) {

        *(u8 *)(iVar6 + 0x18) = 0;

      }

      func_001127d0(uVar5,1);

      FUN_00115980(uVar5);

      FUN_004c3880(uVar4);

    }

  }

  return;

}

// FUN_0042BA30


u8 FUN_0042ba30(void)



{

  return cGpffffb9ec == '\x01';

}

// FUN_0042BA50 NONMATCHING


void FUN_0042ba50(u64 param_1)



{

  int iVar1;

  int *piVar2;

  u32 uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  long lVar8;

  float fVar9;

  float fVar10;

  u8 auStack_20 [8];

  int iStack_18;

  int iStack_14;

  u32 uStack_4;

  

  iVar1 = *(int *)((int)param_1 + 0x3c);

  lVar8 = 0;

  while (lVar8 < *(char *)(iVar1 + 0xb2a)) {

    iVar7 = (int)lVar8;

    iVar4 = iVar1 + iVar7 * 2;

    iVar6 = iVar1 + iVar7 * 8;

    *(float *)(iVar6 + 0xb2c) =

         *(float *)(iVar1 + 0x85c) +

         *(float *)(iGpffffb5c0 + *piGpffffa850 * 0x3c4 + *(short *)(iVar4 + 0xb7c) * 0x28 + -0x74a8

                   );

    *(float *)(iVar6 + 0xb30) =

         *(float *)(iVar1 + 0x860) +

         *(float *)(iGpffffb5c0 + *piGpffffa850 * 0x3c4 + *(short *)(iVar4 + 0xb7c) * 0x28 + -0x74a4

                   );

    piVar2 = *(int **)(iVar1 + iVar7 * 4 + 0x28);

    iVar5 = *piVar2;

    iStack_14 = *(int *)(iVar5 + 0x10);

    iStack_18 = *(int *)(iVar5 + 0xc);

    uStack_4 = 0xffffffff;

    iVar5 = iGpffffb5c0 + *piGpffffa850 * 0x3c4 + *(short *)(iVar4 + 0xb7c) * 0x28;

    fVar10 = *(float *)(iVar5 + -0x74ac);

    fVar9 = *(float *)(iVar5 + -0x74b0);

    uVar3 = FUN_00427bf0(0x40a00000,fVar9,fVar10,fVar9 / (float)iStack_18,fVar10 / (float)iStack_14,

                         param_1,(u32)piVar2,*(u64 *)(iVar6 + 0xb2c),0xffffffff,(u32 *)auStack_20);

    *(u32 *)(iVar6 + 0x5c) = uVar3;

    lVar8 = (long)(iVar7 + 1);

  }

  return;

}

// FUN_0042BC10 NONMATCHING


void FUN_0042bc10(u64 param_1)



{

  int iVar1;

  u64 uVar2;

  long lVar3;

  float fStack_8;

  float fStack_4;

  

  iVar1 = *(int *)((int)param_1 + 0x3c);

  if (DAT_008717e8 != 0) {

    if (*(int *)(iVar1 + 0x898) != 0) {

      *(u32 *)(iVar1 + 0x898) = 0;

    }

    FUN_00423fe0(&fStack_8,0,0x7e,0x7e,0x20,0x20);

    *(float *)(iVar1 + 0x89c) = *(float *)(iVar1 + 0x85c) + fStack_8;

    *(float *)(iVar1 + 0x8a0) = *(float *)(iVar1 + 0x860) + fStack_4;

    uVar2 = FUN_004560d0(*(u32 *)(iVar1 + 0x89c),*(u32 *)(iVar1 + 0x8a0),0x3f800000,

                         param_1,0x20,0x20);

    *(int *)(iVar1 + 0x898) = (int)uVar2;

    FUN_004563c0(uVar2,*(u8 *)(iVar1 + 0xb90));

    FUN_004563d0(*(u32 *)(iVar1 + 0x898),*(u64 *)(iVar1 + 0x85c));

    FUN_004563b0(*(f32 *)

                  (*(short *)(iVar1 + 0xb90) * 0x28 + *piGpffffa850 * 0x3c4 + iGpffffb5c0 + -0x74a0)

                 ,*(u32 *)(iVar1 + 0x898));

    *(u32 *)(iVar1 + 0xba4) = 0;

    *(u32 *)(iVar1 + 0xbac) = 0;


    for (lVar3 = 0; lVar3 < *(char *)(iVar1 + 0xb2a); lVar3 = (long)((int)lVar3 + 1)) {

      *(u8 *)(*(int *)(*(int *)(iVar1 + (int)lVar3 * 8 + 0x5c) + 0x3c) + 0x150) = 1;

    }

  }

  return;

}

// FUN_0042BD80 NONMATCHING


void FUN_0042bd80(u64 param_1)



{

  u8 uVar1;

  u8 bVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  

  iVar3 = *(int *)((int)param_1 + 0x3c);

  for (iVar7 = 0; iVar7 < 0x10; iVar7 = iVar7 + 1) {

    iVar6 = iVar7 * 0x100;

    iVar10 = iVar3 + iVar7 * 0x80;

    for (iVar8 = 0; iVar8 < 0x10; iVar8 = iVar8 + 1) {

      iVar4 = K_Field_Get();

      if (*(char *)(iVar6 + iVar4 + iVar8 * 0x10 + 0x48) == '\x01') {

        iVar4 = K_Field_Get();

        if (*(char *)(iVar6 + iVar4 + iVar8 * 0x10 + 0x49) == '\x01') {

          iVar4 = iVar10 + iVar8 * 8;

          piVar5 = (int *)(iVar4 + 0x5c);

          if (*(int *)(iVar4 + 0x5c) != 0) {

            *piVar5 = 0;

          }

          iVar9 = iVar8 * 0x10;

          K_Field_Get();

          iVar4 = K_Field_Get();

          if (*(u8 *)(iVar6 + iVar4 + iVar9 + 0x4a) < 5) {

            iVar4 = K_Field_Get();

            bVar2 = *(u8 *)(iVar6 + iVar4 + iVar9 + 0x4a);

            iVar4 = K_Field_Get();

            uVar1 = *(u8 *)(iVar6 + iVar4 + iVar9 + 0x4a);

            iVar4 = K_Field_Get();

            iVar4 = FUN_00427670(0x3f200000,0x3f200000,param_1,(&DAT_0095c0e0)[bVar2],uVar1,

                                 *(u8 *)(iVar6 + iVar4 + iVar9 + 0x4e));

            *piVar5 = iVar4;

          }

          else {

            iVar4 = K_Field_Get();

            bVar2 = *(u8 *)(iVar6 + iVar4 + iVar9 + 0x4a);

            iVar4 = K_Field_Get();

            uVar1 = *(u8 *)(iVar6 + iVar4 + iVar9 + 0x4a);

            iVar4 = K_Field_Get();

            iVar4 = FUN_00427670(0x3f180000,0x3f180000,param_1,(&DAT_0095c0e0)[bVar2],uVar1,

                                 *(u8 *)(iVar6 + iVar4 + iVar9 + 0x4e));

            *piVar5 = iVar4;

          }

          *(u8 *)(*(int *)(*piVar5 + 0x3c) + 0x150) = 1;

          *(u8 *)(iVar10 + iVar8 * 8 + 0x60) = 0;

        }

      }

    }

  }

  return;

}

// FUN_0042BFD0 NONMATCHING


void FUN_0042bfd0(u64 param_1)



{

  int iVar1;

  u32 uVar2;

  float fStack_8;

  float fStack_4;

  

  iVar1 = *(int *)((int)param_1 + 0x3c);

  if (DAT_008717e8 != 0 && DAT_008717f4 != 0) {

    if (*(int *)(iVar1 + 0x898) != 0) {

      *(u32 *)(iVar1 + 0x898) = 0;

    }

    FUN_00423fe0(&fStack_8,0,0x7e,0x7e,0x20,0x20);

    *(float *)(iVar1 + 0x89c) = *(float *)(iVar1 + 0x85c) + fStack_8;

    *(float *)(iVar1 + 0x8a0) = *(float *)(iVar1 + 0x860) + fStack_4;

    uVar2 = FUN_004560d0(*(u32 *)(iVar1 + 0x89c),*(u32 *)(iVar1 + 0x8a0),0x3f800000,

                         param_1,0x20,0x20);

    *(u32 *)(iVar1 + 0x898) = uVar2;

  }

  return;

}

// FUN_0042C0A0 NONMATCHING


void FUN_0042c0a0(int param_1,char param_2,short param_3,short param_4,int param_5,int param_6)



{

  char cVar1;

  char cVar2;

  char cVar3;

  short sVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  u32 uVar8;

  u64 uVar9;

  int iVar10;

  u8 bVar11;

  int *piVar12;

  float *pfVar13;

  short *psVar14;

  float *pfVar15;

  u8 uVar16;

  float fVar17;

  u32 uVar18;

  float fVar19;

  u32 uStack_e0;

  u32 uStack_dc;

  float fStack_d8;

  u32 uStack_d0;

  u32 uStack_cc;

  float fStack_c8;

  u32 uStack_c0;

  u32 uStack_bc;

  float fStack_b8;

  float fStack_b0;

  u32 uStack_ac;

  u32 uStack_a8;

  float fStack_a0;

  u32 uStack_9c;

  u32 uStack_98;

  float fStack_90;

  u32 uStack_8c;

  u32 uStack_88;

  u32 uStack_80;

  u32 uStack_7c;

  float fStack_78;

  u32 uStack_70;

  u32 uStack_6c;

  float fStack_68;

  u32 uStack_60;

  u32 uStack_5c;

  float fStack_58;

  u32 uStack_50;

  u32 uStack_4c;

  float fStack_48;

  float fStack_40;

  u32 uStack_3c;

  u32 uStack_38;

  float fStack_30;

  u32 uStack_2c;

  u32 uStack_28;

  float fStack_20;

  u32 uStack_1c;

  u32 uStack_18;

  float fStack_10;

  u32 uStack_c;

  u32 uStack_8;

  

  iVar10 = *(int *)(param_1 + 0x3c);

  bVar11 = 0;

  iVar7 = (int)param_2;

  if ((DAT_008717e8[iVar7 * 0x70] != 0) && (DAT_008717f4[iVar7 * 0x70] != 0)) {

    bVar11 = 1;

  }

  if (bVar11) {

    sVar4 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4[iVar7 * 0x70] + 0x1e0));

    if ((param_3 == sVar4) &&

       (sVar4 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4[iVar7 * 0x70] + 0x1e0)),

       param_4 == sVar4)) {

      if (*(char *)(iVar10 + 0x865) == '\0') {

        cVar1 = *(char *)(iVar10 + 0xb29);

        K_FldFrame_CtlCopyPos(&fStack_40,*(u32 *)(DAT_008717f4 + 0x1e0));

        fStack_30 = fStack_40;

        uStack_2c = uStack_3c;

        uStack_28 = uStack_38;

        iVar5 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

        fVar17 = fStack_30 - ((float)iVar5 * 800.0f - 400.0f);

        uVar18 = 0x40000000;

        cVar2 = *(char *)(iVar10 + 0xb29);

        piVar12 = DAT_008717f4 + param_2 * 0x70;

        K_FldFrame_CtlCopyPos(&fStack_20,*(u32 *)(*piVar12 + 0x1e0));

        fStack_10 = fStack_20;

        uStack_c = uStack_1c;

        uStack_8 = uStack_18;

        iVar6 = K_FldFrame_CtlGetXGrid(*(u32 *)(*piVar12 + 0x1e0));

        cVar3 = *(char *)(iVar10 + 0xb29);

        pfVar15 = (float *)(param_2 * 8 + iVar10 + 0x8b8);

        iVar5 = (int)cVar3;

        if (cVar3 < '\0') {

          iVar5 = iVar5 + 1;

        }

        *pfVar15 = ((float)(iVar5 >> 1) +

                   ((((*(float *)(iVar10 + 0x85c) + (float)(cVar3 * param_5)) -

                     (float)(int)(((float)(int)cVar2 / 2.0f + 0.0f) -

                                 (fStack_10 - ((float)iVar6 * 800.0f - 400.0f)) *

                                 ((float)(int)cVar2 / 800.0f))) +

                    (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -

                                fVar17 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar3 << 1)))

                   - 8.0f;

        cVar1 = *(char *)(iVar10 + 0xb29);

        K_FldFrame_CtlCopyPos(&uStack_80,*(u32 *)(DAT_008717f4 + 0x1e0));

        uStack_70 = uStack_80;

        uStack_6c = uStack_7c;

        fStack_68 = fStack_78;

        iVar5 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

        fVar17 = fStack_68 - ((float)iVar5 * 800.0f - 400.0f);

        fVar19 = (float)(int)*(char *)(iVar10 + 0xb29);

        K_FldFrame_CtlCopyPos(&uStack_60,*(u32 *)(*piVar12 + 0x1e0));

        uStack_50 = uStack_60;

        uStack_4c = uStack_5c;

        fStack_48 = fStack_58;

        iVar6 = K_FldFrame_CtlGetZGrid(*(u32 *)(*piVar12 + 0x1e0));

        cVar2 = *(char *)(iVar10 + 0xb29);

        pfVar13 = (float *)(param_2 * 8 + iVar10 + 0x8bc);

        iVar5 = (int)cVar2;

        if (cVar2 < '\0') {

          iVar5 = iVar5 + 1;

        }

        *pfVar13 = ((float)(iVar5 >> 1) +

                   ((((*(float *)(iVar10 + 0x860) + (float)(cVar2 * param_6)) -

                     (float)(int)((fVar19 / 2.0f + 0.0f) -

                                 (fStack_48 - ((float)iVar6 * 800.0f - 400.0f)) * (fVar19 / 800.0f))) +

                    (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -

                                fVar17 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar2 << 1)))

                   - 8.0f;

      }

      else {

        cVar1 = *(char *)(iVar10 + 0xb29);

        fStack_b0 = *(float *)(iVar10 + 0x868);

        uStack_ac = *(u32 *)(iVar10 + 0x86c);

        uStack_a8 = *(u32 *)(iVar10 + 0x870);

        iVar5 = FUN_0044f120(&fStack_b0);

        fVar17 = fStack_b0 - ((float)iVar5 * 800.0f - 400.0f);

        uVar18 = 0x40000000;

        cVar2 = *(char *)(iVar10 + 0xb29);

        piVar12 = DAT_008717f4 + param_2 * 0x70;

        K_FldFrame_CtlCopyPos(&fStack_a0,*(u32 *)(*piVar12 + 0x1e0));

        fStack_90 = fStack_a0;

        uStack_8c = uStack_9c;

        uStack_88 = uStack_98;

        iVar6 = K_FldFrame_CtlGetXGrid(*(u32 *)(*piVar12 + 0x1e0));

        cVar3 = *(char *)(iVar10 + 0xb29);

        pfVar15 = (float *)(param_2 * 8 + iVar10 + 0x8b8);

        iVar5 = (int)cVar3;

        if (cVar3 < '\0') {

          iVar5 = iVar5 + 1;

        }

        *pfVar15 = ((float)(iVar5 >> 1) +

                   ((((*(float *)(iVar10 + 0x85c) + (float)(cVar3 * param_5)) -

                     (float)(int)(((float)(int)cVar2 / 2.0f + 0.0f) -

                                 (fStack_90 - ((float)iVar6 * 800.0f - 400.0f)) *

                                 ((float)(int)cVar2 / 800.0f))) +

                    (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -

                                fVar17 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar3 << 1)))

                   - 8.0f;

        cVar1 = *(char *)(iVar10 + 0xb29);

        uStack_e0 = *(u32 *)(iVar10 + 0x868);

        uStack_dc = *(u32 *)(iVar10 + 0x86c);

        fStack_d8 = *(float *)(iVar10 + 0x870);

        iVar5 = FUN_0044f170(&uStack_e0);

        fVar17 = fStack_d8 - ((float)iVar5 * 800.0f - 400.0f);

        fVar19 = (float)(int)*(char *)(iVar10 + 0xb29);

        K_FldFrame_CtlCopyPos(&uStack_d0,*(u32 *)(*piVar12 + 0x1e0));

        uStack_c0 = uStack_d0;

        uStack_bc = uStack_cc;

        fStack_b8 = fStack_c8;

        iVar6 = K_FldFrame_CtlGetZGrid(*(u32 *)(*piVar12 + 0x1e0));

        cVar2 = *(char *)(iVar10 + 0xb29);

        pfVar13 = (float *)(param_2 * 8 + iVar10 + 0x8bc);

        iVar5 = (int)cVar2;

        if (cVar2 < '\0') {

          iVar5 = iVar5 + 1;

        }

        *pfVar13 = ((float)(iVar5 >> 1) +

                   ((((*(float *)(iVar10 + 0x860) + (float)(cVar2 * param_6)) -

                     (float)(int)((fVar19 / 2.0f + 0.0f) -

                                 (fStack_b8 - ((float)iVar6 * 800.0f - 400.0f)) * (fVar19 / 800.0f))) +

                    (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -

                                fVar17 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar2 << 1)))

                   - 8.0f;

      }

      if (*(float *)(iVar10 + 0x85c) < *pfVar15 + 8.0f) {
        if (((*(float *)(iVar10 + 0x860) < *pfVar13 + 8.0f) &&
            (*pfVar15 + 12.0f < *(float *)(iVar10 + 0x85c) + 126.0f)) &&
           (*pfVar13 + 12.0f < *(float *)(iVar10 + 0x860) + 126.0f)) {

          *(u8 *)(param_2 + iVar10 + 0x937) = 1;

          uVar8 = datGetBadStatusNoDown(*(u16 *)(&DAT_00871948 + iVar7 * 0x1c0));

          if ((uVar8 & 0x80) == 0) {

            uVar8 = datGetBadStatusNoDown(*(u16 *)(&DAT_00871948 + iVar7 * 0x1c0));

            if ((uVar8 & 0x80000) == 0) {

              uVar9 = FUN_001158b0(0,DAT_007ce6e4,7);

              iVar10 = (int)uVar9;

              *(u32 *)(iVar10 + 0x2c) = uVar18;

              *(float *)(iVar10 + 0x10) = *pfVar15;

              *(float *)(iVar10 + 0x14) = *pfVar13;

              *(u8 *)(iVar10 + 0x18) = 0;

              func_001127d0(uVar9,1);

              FUN_00115980(uVar9);

            }

            else {

              iVar7 = param_2 * 2 + iVar10;

              psVar14 = (short *)(iVar7 + 0x930);

              fVar17 = (float)sinf(DAT_007cb134 * (float)(int)*(short *)(iVar7 + 0x930));

              fVar17 = fVar17 * -128.0f + 128.0f;

              sVar4 = *psVar14;

              *psVar14 = sVar4 + 1;

              if (0x28 < (short)(sVar4 + 1)) {

                *psVar14 = 0;

              }

              uVar9 = FUN_001158b0(0,DAT_007ce6e4,10);

              iVar7 = (int)uVar9;

              *(u32 *)(iVar7 + 0x2c) = 0x40400000;

              iVar10 = param_2 * 8 + iVar10;

              *(float *)(iVar7 + 0x10) = *(float *)(iVar10 + 0x8b8) + 3.0f;
              *(float *)(iVar7 + 0x14) = *(float *)(iVar10 + 0x8bc) + 3.0f;
              if (fVar17 < 2.1474836e+09f) {

                uVar16 = (u8)(int)fVar17;

              }

              else {

                uVar16 = (u8)(int)(fVar17 - 2.1474836e+09f);

              }

              *(u8 *)(iVar7 + 0x18) = uVar16;

              func_001127d0(uVar9,1);

              FUN_00115980(uVar9);

              uVar9 = FUN_001158b0(0,DAT_007ce6e4,9);

              iVar7 = (int)uVar9;

              *(u32 *)(iVar7 + 0x2c) = uVar18;

              *(u32 *)(iVar7 + 0x10) = *(u32 *)(iVar10 + 0x8b8);

              *(u32 *)(iVar7 + 0x14) = *(u32 *)(iVar10 + 0x8bc);

              *(u8 *)(iVar7 + 0x18) = 0;

              func_001127d0(uVar9,1);

              FUN_00115980(uVar9);

            }

          }

          else {

            iVar7 = param_2 * 2 + iVar10;

            psVar14 = (short *)(iVar7 + 0x930);

            fVar17 = (float)sinf(DAT_007cb134 * (float)(int)*(short *)(iVar7 + 0x930));

            fVar17 = fVar17 * -128.0f + 128.0f;

            sVar4 = *psVar14;

            *psVar14 = sVar4 + 1;

            if (0x28 < (short)(sVar4 + 1)) {

              *psVar14 = 0;

            }

            uVar9 = FUN_001158b0(0,DAT_007ce6e4,10);

            iVar7 = (int)uVar9;

            *(u32 *)(iVar7 + 0x2c) = 0x40400000;

            iVar10 = param_2 * 8 + iVar10;

            *(float *)(iVar7 + 0x10) = *(float *)(iVar10 + 0x8b8) + 3.0f;
            *(float *)(iVar7 + 0x14) = *(float *)(iVar10 + 0x8bc) + 3.0f;
            if (fVar17 < 2.1474836e+09f) {

              uVar16 = (u8)(int)fVar17;

            }

            else {

              uVar16 = (u8)(int)(fVar17 - 2.1474836e+09f);

            }

            *(u8 *)(iVar7 + 0x18) = uVar16;

            func_001127d0(uVar9,1);

            FUN_00115980(uVar9);

            uVar9 = FUN_001158b0(0,DAT_007ce6e4,8);

            iVar7 = (int)uVar9;

            *(u32 *)(iVar7 + 0x2c) = uVar18;

            *(u32 *)(iVar7 + 0x10) = *(u32 *)(iVar10 + 0x8b8);

            *(u32 *)(iVar7 + 0x14) = *(u32 *)(iVar10 + 0x8bc);

            *(u8 *)(iVar7 + 0x18) = 0;

            func_001127d0(uVar9,1);

            FUN_00115980(uVar9);

          }

        }

      }

    }

  }

  return;

}

// FUN_0042CD80 NONMATCHING








void FUN_0042cd80(int param_1)



{

  int iVar1;

  u32 uVar2;

  long lVar3;

  char cVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  for (iVar8 = 0; iVar8 < 3; iVar8 = iVar8 + 1) {

    if ((*(char *)(iVar1 + iVar8 + 0x938) == '\x01') &&

       (lVar3 = FUN_0043a230((char)iVar8 + '\x01'), lVar3 == 1)) {

      for (iVar7 = iVar8 * 5; iVar7 < (iVar8 + 1) * 5; iVar7 = iVar7 + 1) {

        iVar6 = iVar1 + iVar7;

        iVar5 = iVar1 + iVar7 * 2;

        FUN_00430780(0x41000000,*(u64 *)(iVar1 + iVar8 * 8 + 0x8c0),

                     *(u8 *)(iVar5 + 0x8f6),*(u8 *)(iVar5 + 0x914),

                     *(u8 *)(iVar6 + 0x8d8));

        if (*(char *)(iVar6 + 0x8e7) < '\x01') {

          cVar4 = *(char *)(iVar6 + 0x8d8) + '\x01';

          *(char *)(iVar6 + 0x8d8) = cVar4;

          if ('\x14' < cVar4) {

            uVar2 = RpRandom();

            *(short *)(iVar5 + 0x8f6) = (short)(int)(8.0 - (float)(uVar2 & 0xf));

            uVar2 = RpRandom();

            *(short *)(iVar5 + 0x914) = (short)(int)(8.0 - (float)(uVar2 & 0xf));

            *(u8 *)(iVar6 + 0x8d8) = 0;

            *(char *)(iVar6 + 0x8e7) = '\x04';

          }

        }

        else {

          *(char *)(iVar6 + 0x8e7) = *(char *)(iVar6 + 0x8e7) + -1;

        }

      }

    }

  }

  return;

}

// FUN_0042CFC0 NONMATCHING


void FUN_0042cfc0(int param_1,u16 param_2,u16 param_3,int param_4,int param_5)



{

  char cVar1;

  char cVar2;

  char cVar3;

  int iVar4;

  short sVar5;

  int iVar6;

  int iVar7;

  long lVar8;

  u64 uVar9;

  int iVar10;

  u8 bVar11;

  int *piVar12;

  float *pfVar13;

  float *pfVar14;

  int iVar15;

  int iVar16;

  u8 uVar17;

  float fVar18;

  float fVar19;

  u32 uStack_160;

  u32 uStack_15c;

  float fStack_158;

  u32 uStack_150;

  u32 uStack_14c;

  float fStack_148;

  u32 uStack_140;

  u32 uStack_13c;

  float fStack_138;

  u32 uStack_130;

  u32 uStack_12c;

  float fStack_128;

  float fStack_120;

  u32 uStack_11c;

  u32 uStack_118;

  float fStack_110;

  u32 uStack_10c;

  u32 uStack_108;

  float fStack_100;

  u32 uStack_fc;

  u32 uStack_f8;

  float fStack_f0;

  u32 uStack_ec;

  u32 uStack_e8;

  u32 uStack_e0;

  u32 uStack_dc;

  float fStack_d8;

  u32 uStack_d0;

  u32 uStack_cc;

  float fStack_c8;

  u32 uStack_c0;

  u32 uStack_bc;

  float fStack_b8;

  float fStack_b0;

  u32 uStack_ac;

  u32 uStack_a8;

  float fStack_a0;

  u32 uStack_9c;

  u32 uStack_98;

  float fStack_90;

  u32 uStack_8c;

  u32 uStack_88;

  u32 uStack_80;

  u32 uStack_7c;

  float fStack_78;

  u32 uStack_70;

  u32 uStack_6c;

  float fStack_68;

  u32 uStack_60;

  u32 uStack_5c;

  float fStack_58;

  u32 uStack_50;

  u32 uStack_4c;

  float fStack_48;

  float fStack_40;

  u32 uStack_3c;

  u32 uStack_38;

  float fStack_30;

  u32 uStack_2c;

  u32 uStack_28;

  float fStack_20;

  u32 uStack_1c;

  u32 uStack_18;

  float fStack_10;

  u32 uStack_c;

  u32 uStack_8;

  
  YajimaVec3 posMain0;
  volatile YajimaVec3 savedMain0;
  YajimaVec3 posObj0;
  volatile YajimaVec3 savedObj0;
  YajimaVec3 worldPos1;
  YajimaVec3 posObj1;
  volatile YajimaVec3 savedObj1;
  YajimaVec3 worldPos2;
  YajimaVec3 posObj2;
  volatile YajimaVec3 savedObj2;
  YajimaVec3 posObj3;
  volatile YajimaVec3 savedObj3;
  YajimaVec3 posMain3;
  volatile YajimaVec3 savedMain3;
  YajimaVec3 posObj4;
  volatile YajimaVec3 savedObj4;
  YajimaVec3 posMain4;
  volatile YajimaVec3 savedMain4;

  iVar4 = *(int *)(param_1 + 0x3c);

  for (iVar15 = 0; iVar15 < 0x18; iVar15 = iVar15 + 1) {

    iVar10 = (iVar15 * 7) << 6;

    if ((*(int *)(DAT_0086eda0_abs + iVar10 + 0x48) != 0) &&
        (*(int *)(DAT_0086eda0_abs + iVar10 + 0x54) != 0)) {

      lVar8 = K_FldFrame_CtlGetXGrid(*(u32 *)(*(int *)(DAT_0086eda0_abs + iVar10 + 0x54) + 0x1e0));

      if ((CONCAT44((int)((long)((u32)param_2 << 0x30) >> 0x3f),(int)(short)param_2) == lVar8) &&
         (lVar8 = K_FldFrame_CtlGetZGrid(*(u32 *)(*(int *)(DAT_0086eda0_abs + iVar10 + 0x54) + 0x1e0)),
         CONCAT44((int)((long)((u32)param_3 << 0x30) >> 0x3f),(int)(short)param_3) == lVar8)) {

        cVar3 = (char)iVar15;

        if (*(char *)(iVar4 + 0x865) == '\0') {

          cVar1 = *(char *)(iVar4 + 0xb29);

          K_FldFrame_CtlCopyPos(&posMain0,*(u32 *)(DAT_008717f4 + 0x1e0));

          savedMain0 = posMain0;

          iVar6 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

          fVar18 = savedMain0.x - ((float)iVar6 * 800.0f - 400.0f);

          fVar19 = (float)(int)*(char *)(iVar4 + 0xb29);

          piVar12 = (int *)(DAT_0086eda0_abs + cVar3 * 0x1c0 + 0x54);

          K_FldFrame_CtlCopyPos(&posObj0,*(u32 *)(*piVar12 + 0x1e0));

          savedObj0 = posObj0;

          iVar7 = K_FldFrame_CtlGetXGrid(*(u32 *)(*piVar12 + 0x1e0));

          cVar2 = *(char *)(iVar4 + 0xb29);

          iVar16 = iVar4 + iVar15 * 8;

          pfVar14 = (float *)(iVar16 + 0x93c);

          iVar6 = (int)cVar2;

          if (cVar2 < '\0') {

            iVar6 = iVar6 + 1;

          }

          *pfVar14 = ((float)(iVar6 >> 1) +

                     ((((*(float *)(iVar4 + 0x85c) + (float)(cVar2 * param_4)) -

                       ((fVar19 / 2.0f + 0.0f) -

                       (savedObj0.x - ((float)iVar7 * 800.0f - 400.0f)) * (fVar19 / 800.0f))) +

                      (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -

                                  fVar18 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar2 << 1))

                     ) - 8.0f;

          cVar1 = *(char *)(iVar4 + 0xb29);

          K_FldFrame_CtlCopyPos(&posMain0,*(u32 *)(DAT_008717f4 + 0x1e0));

          savedMain0 = posMain0;

          iVar6 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

          fVar18 = savedMain0.z - ((float)iVar6 * 800.0f - 400.0f);

          fVar19 = (float)(int)*(char *)(iVar4 + 0xb29);

          K_FldFrame_CtlCopyPos(&posObj0,*(u32 *)(*piVar12 + 0x1e0));

          savedObj0 = posObj0;

          iVar7 = K_FldFrame_CtlGetZGrid(*(u32 *)(*piVar12 + 0x1e0));

          cVar2 = *(char *)(iVar4 + 0xb29);

          pfVar13 = (float *)(iVar16 + 0x940);

          iVar6 = (int)cVar2;

          if (cVar2 < '\0') {

            iVar6 = iVar6 + 1;

          }

          *pfVar13 = ((float)(iVar6 >> 1) +

                     ((((*(float *)(iVar4 + 0x860) + (float)(cVar2 * param_5)) -

                       ((fVar19 / 2.0f + 0.0f) -

                       (savedObj0.z - ((float)iVar7 * 800.0f - 400.0f)) * (fVar19 / 800.0f))) +

                      (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -
                                  fVar18 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar2 << 1))

                     ) - 8.0f;

        }

        else {

          cVar1 = *(char *)(iVar4 + 0xb29);

          worldPos1 = *(YajimaVec3 *)(iVar4 + 0x868);

          iVar6 = FUN_0044f120(&worldPos1);

          fVar18 = worldPos1.x - ((float)iVar6 * 800.0f - 400.0f);

          fVar19 = (float)(int)*(char *)(iVar4 + 0xb29);

          piVar12 = (int *)(DAT_0086eda0_abs + cVar3 * 0x1c0 + 0x54);

          K_FldFrame_CtlCopyPos(&posObj1,*(u32 *)(*piVar12 + 0x1e0));

          savedObj1 = posObj1;

          iVar7 = K_FldFrame_CtlGetXGrid(*(u32 *)(*piVar12 + 0x1e0));

          cVar2 = *(char *)(iVar4 + 0xb29);

          iVar16 = iVar4 + iVar15 * 8;

          pfVar14 = (float *)(iVar16 + 0x93c);

          iVar6 = (int)cVar2;

          if (cVar2 < '\0') {

            iVar6 = iVar6 + 1;

          }

          *pfVar14 = ((float)(iVar6 >> 1) +

                     ((((*(float *)(iVar4 + 0x85c) + (float)(cVar2 * param_4)) -

                       ((fVar19 / 2.0f + 0.0f) -

                       (savedObj1.x - ((float)iVar7 * 800.0f - 400.0f)) * (fVar19 / 800.0f))) +

                      (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -

                                  fVar18 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar2 << 1))

                     ) - 8.0f;

          cVar1 = *(char *)(iVar4 + 0xb29);

          worldPos2 = *(YajimaVec3 *)(iVar4 + 0x868);

          iVar6 = FUN_0044f170(&worldPos2);

          fVar18 = worldPos2.z - ((float)iVar6 * 800.0f - 400.0f);

          fVar19 = (float)(int)*(char *)(iVar4 + 0xb29);

          K_FldFrame_CtlCopyPos(&posObj2,*(u32 *)(*piVar12 + 0x1e0));

          savedObj2 = posObj2;

          iVar7 = K_FldFrame_CtlGetZGrid(*(u32 *)(*piVar12 + 0x1e0));

          cVar2 = *(char *)(iVar4 + 0xb29);

          pfVar13 = (float *)(iVar16 + 0x940);

          iVar6 = (int)cVar2;

          if (cVar2 < '\0') {

            iVar6 = iVar6 + 1;

          }

          *pfVar13 = ((float)(iVar6 >> 1) +

                     ((((*(float *)(iVar4 + 0x860) + (float)(cVar2 * param_5)) -

                       ((fVar19 / 2.0f + 0.0f) -

                       (savedObj2.z - ((float)iVar7 * 800.0f - 400.0f)) * (fVar19 / 800.0f))) +

                      (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -

                                  fVar18 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar2 << 1))

                     ) - 8.0f;

        }

        lVar8 = K_FldEvent_AreUnitsWithinDist(0x44fa0000,&DAT_0086eda0 + iVar10,0x8717a0);

        if (lVar8 == 1) {

          if (*(int *)(&DAT_0086ef2c + iVar10) == 4) {

            fVar18 = (float)sinf(DAT_007cb138 * (float)(int)*(short *)(iVar4 + 0x9fc));

            fVar18 = fVar18 * -100.0f + 100.0f;

            sVar5 = *(short *)(iVar4 + 0x9fc) + 1;

            *(short *)(iVar4 + 0x9fc) = sVar5;

            if (0x14 < sVar5) {

              *(u16 *)(iVar4 + 0x9fc) = 0;

            }

            uVar9 = FUN_001158b0(0,DAT_007ce6e4,0xb);

            iVar10 = (int)uVar9;

            *(u32 *)(iVar10 + 0x2c) = 0x40000000;

            *(float *)(iVar10 + 0x10) = *pfVar14;

            *(float *)(iVar10 + 0x14) = *pfVar13;

            if (fVar18 < 2.1474836e+09f) {

              uVar17 = (u8)(int)fVar18;

            }

            else {

              uVar17 = (u8)(int)(fVar18 - 2.1474836e+09f);

            }

            *(u8 *)(iVar10 + 0x18) = uVar17;

            func_001127d0(uVar9,1);

            FUN_00115980(uVar9);

          }

          else {

            uVar9 = FUN_001158b0(0,DAT_007ce6e4,0xb);

            iVar10 = (int)uVar9;

            *(u32 *)(iVar10 + 0x2c) = 0x40000000;

            *(float *)(iVar10 + 0x10) = *pfVar14;

            *(float *)(iVar10 + 0x14) = *pfVar13;

            *(u8 *)(iVar10 + 0x18) = 0;

            func_001127d0(uVar9,1);

            FUN_00115980(uVar9);

          }

        }

        else if (*(int *)(DAT_0086eda0_abs + iVar10 + 0x54) != 0) {

          cVar1 = *(char *)(iVar4 + 0xb29);

          piVar12 = (int *)(DAT_0086eda0_abs + cVar3 * 0x1c0 + 0x54);

          K_FldFrame_CtlCopyPos(&posObj3,*(u32 *)(*piVar12 + 0x1e0));

          savedObj3 = posObj3;

          iVar10 = K_FldFrame_CtlGetXGrid(*(u32 *)(*piVar12 + 0x1e0));

          fVar18 = savedObj3.x - ((float)iVar10 * 800.0f - 400.0f);

          fVar19 = (float)(int)*(char *)(iVar4 + 0xb29);

          K_FldFrame_CtlCopyPos(&posMain3,*(u32 *)(DAT_008717f4 + 0x1e0));

          savedMain3 = posMain3;

          iVar6 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

          cVar3 = *(char *)(iVar4 + 0xb29);

          iVar10 = (int)cVar3;

          if (cVar3 < '\0') {

            iVar10 = iVar10 + 3;

          }

          *pfVar14 = ((float)(iVar10 >> 2) +

                      ((*(float *)(iVar4 + 0x85c) +

                       (float)(int)((fVar19 / 2.0f + 0.0f) -

                                   (savedMain3.x - ((float)iVar6 * 800.0f - 400.0f)) * (fVar19 / 800.0f)))

                      - (((float)(int)cVar1 / 2.0f + 0.0f) - fVar18 * ((float)(int)cVar1 / 800.0f))) +

                     2.0f) - (float)((int)cVar3 << 1);

          cVar3 = *(char *)(iVar4 + 0xb29);

          K_FldFrame_CtlCopyPos(&posObj4,*(u32 *)(*piVar12 + 0x1e0));

          savedObj4 = posObj4;

          iVar10 = K_FldFrame_CtlGetZGrid(*(u32 *)(*piVar12 + 0x1e0));

          fVar18 = savedObj4.z - ((float)iVar10 * 800.0f - 400.0f);

          fVar19 = (float)(int)*(char *)(iVar4 + 0xb29);

          K_FldFrame_CtlCopyPos(&posMain4,*(u32 *)(DAT_008717f4 + 0x1e0));

          savedMain4 = posMain4;

          iVar6 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

          cVar1 = *(char *)(iVar4 + 0xb29);

          iVar10 = (int)cVar1;

          if (cVar1 < '\0') {

            iVar10 = iVar10 + 3;

          }

          *pfVar13 = ((float)(iVar10 >> 2) +

                      ((*(float *)(iVar4 + 0x860) +

                       (float)(int)((fVar19 / 2.0f + 0.0f) -

                                   (savedMain4.z - ((float)iVar6 * 800.0f - 400.0f)) * (fVar19 / 800.0f))

                       ) - (((float)(int)cVar3 / 2.0f + 0.0f) - fVar18 * ((float)(int)cVar3 / 800.0f)))

                     + 2.0f) - (float)((int)cVar1 << 1);

          DAT_0095c210[iVar15] = 0;

        }

      }

    }

  }

  return;

}

// FUN_0042DD90 NONMATCHING


void FUN_0042dd90(int param_1,short param_2,u16 param_3,int param_4,int param_5)



{

  char cVar1;

  int iVar2;

  char cVar3;

  short sVar4;

  int iVar5;

  int iVar6;

  u32 uVar7;

  long lVar8;

  u64 uVar9;

  int iVar10;

  int iVar11;

  u8 uVar12;

  u8 uVar13;

  float *pfVar14;

  int iVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  u32 uStack_e0;

  u32 uStack_dc;

  float fStack_d8;

  float fStack_d0;

  u32 uStack_cc;

  float fStack_c8;

  float fStack_c0;

  u32 uStack_bc;

  u32 uStack_b8;

  float fStack_b0;

  u32 uStack_ac;

  u32 uStack_a8;

  u32 uStack_a0;

  u32 uStack_9c;

  float fStack_98;

  u32 uStack_90;

  u32 uStack_8c;

  float fStack_88;

  float fStack_80;

  u32 uStack_7c;

  float fStack_78;

  float fStack_70;

  u32 uStack_6c;

  u32 uStack_68;

  float fStack_60;

  u32 uStack_5c;

  u32 uStack_58;

  float fStack_50;

  u32 uStack_4c;

  u32 uStack_48;

  u8 auStack_40 [8];

  float fStack_38;

  u8 auStack_30 [4];

  float fStack_2c;

  float afStack_20 [4];

  float fStack_10;

  float fStack_c;

  float fStack_8;

  

  iVar2 = *(int *)(param_1 + 0x3c);

  for (iVar15 = 0; iVar15 < 8; iVar15 = iVar15 + 1) {

    if (*(int *)(&DAT_0086be00 + iVar15 * 0x10) != 0) {

      sVar4 = FUN_0044f120(&DAT_0086be04 + iVar15 * 0x10);

      if ((param_2 == sVar4) &&

         (lVar8 = FUN_0044f170(&DAT_0086be04 + iVar15 * 0x10),

         CONCAT44((int)((long)((u32)param_3 << 0x30) >> 0x3f),(int)(short)param_3) == lVar8)) {

        if (*(char *)(iVar2 + 0x865) == '\0') {

          cVar3 = *(char *)(iVar2 + 0xb29);

          K_FldFrame_CtlCopyPos(&fStack_70,*(u32 *)(DAT_008717f4 + 0x1e0));

          fStack_60 = fStack_70;

          uStack_5c = uStack_6c;

          uStack_58 = uStack_68;

          iVar5 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

          fVar17 = fStack_60 - ((float)iVar5 * 800.0f - 400.0f);

          fVar18 = (float)(int)*(char *)(iVar2 + 0xb29);

          iVar10 = iVar15 * 0x10;

          pfVar14 = (float *)(&DAT_0086be04 + iVar10);

          fStack_50 = *(float *)(&DAT_0086be04 + iVar10);

          uStack_4c = *(u32 *)(&DAT_0086be08 + iVar10);

          uStack_48 = *(u32 *)(&DAT_0086be0c + iVar10);

          iVar6 = FUN_0044f120(&fStack_50);

          cVar1 = *(char *)(iVar2 + 0xb29);

          iVar11 = (int)cVar1;

          iVar5 = iVar11;

          if (cVar1 < '\0') {

            iVar5 = iVar11 + 1;

          }

          fVar18 = ((float)(iVar5 >> 1) +

                   ((((*(float *)(iVar2 + 0x85c) + (float)(cVar1 * param_4)) -

                     ((fVar18 / 2.0f + 0.0f) -

                     (fStack_50 - ((float)iVar6 * 800.0f - 400.0f)) * (fVar18 / 800.0f))) +

                    (float)(int)(((float)(int)cVar3 / 2.0f + 0.0f) -

                                fVar17 * ((float)(int)cVar3 / 800.0f))) - (float)((int)cVar1 << 1)))

                   - 8.0f;

          K_FldFrame_CtlCopyPos(&uStack_a0,*(u32 *)(DAT_008717f4 + 0x1e0));

          uStack_90 = uStack_a0;

          uStack_8c = uStack_9c;

          fStack_88 = fStack_98;

          iVar5 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

          fVar17 = fStack_88 - ((float)iVar5 * 800.0f - 400.0f);

          cVar3 = *(char *)(iVar2 + 0xb29);

          fStack_80 = *pfVar14;

          uStack_7c = *(u32 *)(&DAT_0086be08 + iVar10);

          fStack_78 = *(float *)(&DAT_0086be0c + iVar10);

          iVar6 = FUN_0044f170(&fStack_80);

          cVar1 = *(char *)(iVar2 + 0xb29);

          iVar5 = (int)cVar1;

          if (cVar1 < '\0') {

            iVar5 = iVar5 + 1;

          }

          fVar17 = (float)(iVar5 >> 1) +

                   ((((*(float *)(iVar2 + 0x860) + (float)(cVar1 * param_5)) -

                     (((float)(int)cVar3 / 2.0f + 0.0f) -

                     (fStack_78 - ((float)iVar6 * 800.0f - 400.0f)) * ((float)(int)cVar3 / 800.0f))) +

                    (float)(int)(((float)iVar11 / 2.0f + 0.0f) - fVar17 * ((float)iVar11 / 800.0f))) -

                   (float)((int)cVar1 << 1));

        }

        else {

          cVar3 = *(char *)(iVar2 + 0xb29);

          fStack_c0 = *(float *)(iVar2 + 0x868);

          uStack_bc = *(u32 *)(iVar2 + 0x86c);

          uStack_b8 = *(u32 *)(iVar2 + 0x870);

          iVar5 = FUN_0044f120(&fStack_c0);

          fVar17 = fStack_c0 - ((float)iVar5 * 800.0f - 400.0f);

          fVar18 = (float)(int)*(char *)(iVar2 + 0xb29);

          iVar10 = iVar15 * 0x10;

          pfVar14 = (float *)(&DAT_0086be04 + iVar10);

          fStack_b0 = *(float *)(&DAT_0086be04 + iVar10);

          uStack_ac = *(u32 *)(&DAT_0086be08 + iVar10);

          uStack_a8 = *(u32 *)(&DAT_0086be0c + iVar10);

          iVar6 = FUN_0044f120(&fStack_b0);

          cVar1 = *(char *)(iVar2 + 0xb29);

          iVar11 = (int)cVar1;

          iVar5 = iVar11;

          if (cVar1 < '\0') {

            iVar5 = iVar11 + 1;

          }

          fVar18 = ((float)(iVar5 >> 1) +

                   ((((*(float *)(iVar2 + 0x85c) + (float)(cVar1 * param_4)) -

                     ((fVar18 / 2.0f + 0.0f) -

                     (fStack_b0 - ((float)iVar6 * 800.0f - 400.0f)) * (fVar18 / 800.0f))) +

                    (float)(int)(((float)(int)cVar3 / 2.0f + 0.0f) -

                                fVar17 * ((float)(int)cVar3 / 800.0f))) - (float)((int)cVar1 << 1)))

                   - 8.0f;

          uStack_e0 = *(u32 *)(iVar2 + 0x868);

          uStack_dc = *(u32 *)(iVar2 + 0x86c);

          fStack_d8 = *(float *)(iVar2 + 0x870);

          iVar5 = FUN_0044f170(&uStack_e0);

          fVar17 = fStack_d8 - ((float)iVar5 * 800.0f - 400.0f);

          cVar3 = *(char *)(iVar2 + 0xb29);

          fStack_d0 = *pfVar14;

          uStack_cc = *(u32 *)(&DAT_0086be08 + iVar10);

          fStack_c8 = *(float *)(&DAT_0086be0c + iVar10);

          iVar6 = FUN_0044f170(&fStack_d0);

          cVar1 = *(char *)(iVar2 + 0xb29);

          iVar5 = (int)cVar1;

          if (cVar1 < '\0') {

            iVar5 = iVar5 + 1;

          }

          fVar17 = (float)(iVar5 >> 1) +

                   ((((*(float *)(iVar2 + 0x860) + (float)(cVar1 * param_5)) -

                     (((float)(int)cVar3 / 2.0f + 0.0f) -

                     (fStack_c8 - ((float)iVar6 * 800.0f - 400.0f)) * ((float)(int)cVar3 / 800.0f))) +

                    (float)(int)(((float)iVar11 / 2.0f + 0.0f) - fVar17 * ((float)iVar11 / 800.0f))) -

                   (float)((int)cVar1 << 1));

        }

        fVar17 = fVar17 - 8.0f;

        iVar5 = *(int *)(&DAT_0086be00 + iVar15 * 0x10);

        uVar12 = (u8)param_2;

        uVar13 = (u8)param_3;

        if (iVar5 == 4) {

          uVar9 = FUN_001158b0(0,DAT_007ce6e4,5);

          iVar5 = (int)uVar9;

          *(u32 *)(iVar5 + 0x2c) = 0x40400000;

          *(float *)(iVar5 + 0x10) = fVar18;

          *(float *)(iVar5 + 0x14) = fVar17;

          *(u8 *)(iVar5 + 0x18) = 0xff;

          if ((((*(float *)(iVar2 + 0x85c) < fVar18 + 8.0f) &&
               (*(float *)(iVar2 + 0x860) < fVar17 + 8.0f)) &&
              (fVar18 + 12.0f < *(float *)(iVar2 + 0x85c) + 126.0f)) &&
             (fVar17 + 12.0f < *(float *)(iVar2 + 0x860) + 126.0f)) {

            cVar3 = FUN_00433810(uVar12,uVar13);

            if (cVar3 == '\0') {

              if (DAT_0095c110[(short)param_3 * 0x10 + (int)param_2] == '\x01') {

                *(u8 *)(iVar5 + 0x18) = 0;

              }

            }

            else {

              uVar7 = FUN_00433810(uVar12,uVar13);

              if (DAT_0095c110[uVar7 & 0xff] == '\x01') {

                *(u8 *)(iVar5 + 0x18) = 0;

              }

            }

          }

          func_001127d0(uVar9,1);

          FUN_00115980(uVar9);

        }

        else if (iVar5 == 3) {

          uVar9 = FUN_001158b0(0,DAT_007ce6e4,0xc);

          iVar5 = (int)uVar9;

          *(u32 *)(iVar5 + 0x2c) = 0x40400000;

          *(float *)(iVar5 + 0x10) = fVar18;

          *(float *)(iVar5 + 0x14) = fVar17;

          *(u8 *)(iVar5 + 0x18) = 0xff;

          if (((*(float *)(iVar2 + 0x85c) < fVar18 + 8.0f) &&
              (*(float *)(iVar2 + 0x860) < fVar17 + 8.0f)) &&
             ((fVar18 + 12.0f < *(float *)(iVar2 + 0x85c) + 126.0f &&
              (fVar17 + 12.0f < *(float *)(iVar2 + 0x860) + 126.0f)))) {

            cVar3 = FUN_00433810(uVar12,uVar13);

            if (cVar3 == '\0') {

              if (DAT_0095c110[(short)param_3 * 0x10 + (int)param_2] == '\x01') {

                *(u8 *)(iVar5 + 0x18) = 0;

              }

            }

            else {

              uVar7 = FUN_00433810(uVar12,uVar13);

              if (DAT_0095c110[uVar7 & 0xff] == '\x01') {

                *(u8 *)(iVar5 + 0x18) = 0;

              }

            }

          }

          func_001127d0(uVar9,1);

          FUN_00115980(uVar9);

        }

        else if (iVar5 == 2) {

          K_FldFrame_CtlCopyPos(afStack_20,*(u32 *)(DAT_008717f4 + 0x1e0));

          fStack_10 = *pfVar14 - afStack_20[0];

          K_FldFrame_CtlCopyPos(auStack_30,*(u32 *)(DAT_008717f4 + 0x1e0));

          fStack_c = *(float *)(&DAT_0086be08 + iVar15 * 0x10) - fStack_2c;

          K_FldFrame_CtlCopyPos(auStack_40,*(u32 *)(DAT_008717f4 + 0x1e0));

          fStack_8 = *(float *)(&DAT_0086be0c + iVar15 * 0x10) - fStack_38;

          fVar16 = (float)RwV3dLength(&fStack_10);

          if (fVar16 < 2000.0f) {

            uVar9 = FUN_001158b0(0,DAT_007ce6e4,0xb);

            iVar5 = (int)uVar9;

            *(u32 *)(iVar5 + 0x2c) = 0x40000000;

            *(float *)(iVar5 + 0x10) = fVar18;

            *(float *)(iVar5 + 0x14) = fVar17;

            *(u8 *)(iVar5 + 0x18) = 0xff;

            if (((*(float *)(iVar2 + 0x85c) < fVar18 + 8.0f) &&
                (*(float *)(iVar2 + 0x860) < fVar17 + 8.0f)) &&
               ((fVar18 + 12.0f < *(float *)(iVar2 + 0x85c) + 126.0f &&
                (fVar17 + 12.0f < *(float *)(iVar2 + 0x860) + 126.0f)))) {

              *(u8 *)(iVar5 + 0x18) = 0;

            }

            func_001127d0(uVar9,1);

            FUN_00115980(uVar9);

          }

        }

        else if (iVar5 == 1) {

          uVar9 = FUN_001158b0(0,DAT_007ce6e4,7);

          iVar5 = (int)uVar9;

          *(u32 *)(iVar5 + 0x2c) = 0x40000000;

          *(float *)(iVar5 + 0x10) = fVar18;

          *(float *)(iVar5 + 0x14) = fVar17;

          *(u8 *)(iVar5 + 0x18) = 0xff;

          if ((((*(float *)(iVar2 + 0x85c) < fVar18 + 8.0f) &&
               (*(float *)(iVar2 + 0x860) < fVar17 + 8.0f)) &&
              (fVar18 + 12.0f < *(float *)(iVar2 + 0x85c) + 126.0f)) &&
             (fVar17 + 12.0f < *(float *)(iVar2 + 0x860) + 126.0f)) {

            *(u8 *)(iVar5 + 0x18) = 0;

          }

          func_001127d0(uVar9,1);

          FUN_00115980(uVar9);

        }

      }

    }

  }

  return;

}

// FUN_0042EA60 NONMATCHING


void FUN_0042ea60(int param_1,u16 param_2,u16 param_3,int param_4,int param_5)



{

  char cVar1;

  int iVar2;

  char cVar3;

  int iVar4;

  u32 uVar5;

  long lVar6;

  u64 uVar7;

  int iVar8;

  int iVar9;

  float *pfVar10;

  int iVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  u32 uStack_a0;

  u32 uStack_9c;

  float fStack_98;

  u32 uStack_90;

  u32 uStack_8c;

  float fStack_88;

  float fStack_80;

  u32 uStack_7c;

  u32 uStack_78;

  float fStack_70;

  u32 uStack_6c;

  u32 uStack_68;

  u32 uStack_60;

  u32 uStack_5c;

  float fStack_58;

  u32 uStack_50;

  u32 uStack_4c;

  float fStack_48;

  u32 uStack_40;

  u32 uStack_3c;

  float fStack_38;

  float fStack_30;

  u32 uStack_2c;

  u32 uStack_28;

  float fStack_20;

  u32 uStack_1c;

  u32 uStack_18;

  float fStack_10;

  u32 uStack_c;

  u32 uStack_8;

  

  iVar2 = *(int *)(param_1 + 0x3c);

  for (iVar9 = 0; iVar9 < 0x20; iVar9 = iVar9 + 1) {

    if (*(int *)(&DAT_0086be80 + iVar9 * 0x138) != 0) {

      lVar6 = FUN_0044f120(&DAT_0086bf8c + iVar9 * 0x138);

      if ((CONCAT44((int)((long)((u32)param_2 << 0x30) >> 0x3f),(int)(short)param_2) == lVar6) &&

         (lVar6 = FUN_0044f170(&DAT_0086bf8c + iVar9 * 0x138),

         CONCAT44((int)((long)((u32)param_3 << 0x30) >> 0x3f),(int)(short)param_3) == lVar6)) {

        uVar7 = FUN_001158b0(0,DAT_007ce6e4,0xc);

        if (*(char *)(iVar2 + 0x865) == '\0') {

          cVar3 = *(char *)(iVar2 + 0xb29);

          iVar8 = iVar9 * 0x138;

          fStack_30 = *(float *)(&DAT_0086bf8c + iVar8);

          uStack_2c = *(u32 *)(&DAT_0086bf90 + iVar8);

          uStack_28 = *(u32 *)(&DAT_0086bf94 + iVar8);

          iVar4 = FUN_0044f120(&fStack_30);

          fVar14 = fStack_30 - ((float)iVar4 * 800.0f - 400.0f);

          fVar16 = (float)(int)*(char *)(iVar2 + 0xb29);

          K_FldFrame_CtlCopyPos(&fStack_20,*(u32 *)(DAT_008717f4 + 0x1e0));

          fStack_10 = fStack_20;

          uStack_c = uStack_1c;

          uStack_8 = uStack_18;

          iVar4 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

          fVar15 = fStack_10 - ((float)iVar4 * 800.0f - 400.0f);

          cVar1 = *(char *)(iVar2 + 0xb29);

          iVar11 = iVar2 + iVar9 * 8;

          fVar12 = *(float *)(iVar2 + 0x85c);

          iVar4 = (int)cVar1;

          if (cVar1 < '\0') {

            iVar4 = iVar4 + 1;

          }

          fVar13 = (float)func_001126b0(uVar7);

          *(float *)(iVar11 + 0xa00) =

               ((float)(iVar4 >> 1) +

               (((fVar12 + (float)(cVar1 * param_4) +

                 (float)(int)((fVar16 / 2.0f + 0.0f) - fVar15 * (fVar16 / 800.0f))) -

                (((float)(int)cVar3 / 2.0f + 0.0f) - fVar14 * ((float)(int)cVar3 / 800.0f))) -

               (float)((int)cVar1 << 1))) - fVar13 / 2.0f;

          cVar3 = *(char *)(iVar2 + 0xb29);

          uStack_60 = *(u32 *)(&DAT_0086bf8c + iVar8);

          uStack_5c = *(u32 *)(&DAT_0086bf90 + iVar8);

          fStack_58 = *(float *)(&DAT_0086bf94 + iVar8);

          iVar4 = FUN_0044f170(&uStack_60);

          fVar14 = fStack_58 - ((float)iVar4 * 800.0f - 400.0f);

          fVar16 = (float)(int)*(char *)(iVar2 + 0xb29);

          K_FldFrame_CtlCopyPos(&uStack_50,*(u32 *)(DAT_008717f4 + 0x1e0));

          uStack_40 = uStack_50;

          uStack_3c = uStack_4c;

          fStack_38 = fStack_48;

          iVar4 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

          fVar15 = fStack_38 - ((float)iVar4 * 800.0f - 400.0f);

          cVar1 = *(char *)(iVar2 + 0xb29);

          pfVar10 = (float *)(iVar11 + 0xa04);

          fVar12 = *(float *)(iVar2 + 0x860);

          iVar4 = (int)cVar1;

          if (cVar1 < '\0') {

            iVar4 = iVar4 + 1;

          }

          fVar13 = (float)func_00112740(uVar7);

          *pfVar10 = ((float)(iVar4 >> 1) +

                     (((fVar12 + (float)(cVar1 * param_5) +

                       (float)(int)((fVar16 / 2.0f + 0.0f) - fVar15 * (fVar16 / 800.0f))) -

                      (((float)(int)cVar3 / 2.0f + 0.0f) - fVar14 * ((float)(int)cVar3 / 800.0f))) -

                     (float)((int)cVar1 << 1))) - fVar13 / 2.0f;

        }

        else {

          cVar3 = *(char *)(iVar2 + 0xb29);

          iVar8 = iVar9 * 0x138;

          fStack_80 = *(float *)(&DAT_0086bf8c + iVar8);

          uStack_7c = *(u32 *)(&DAT_0086bf90 + iVar8);

          uStack_78 = *(u32 *)(&DAT_0086bf94 + iVar8);

          iVar4 = FUN_0044f120(&fStack_80);

          fVar14 = fStack_80 - ((float)iVar4 * 800.0f - 400.0f);

          fVar16 = (float)(int)*(char *)(iVar2 + 0xb29);

          fStack_70 = *(float *)(iVar2 + 0x868);

          uStack_6c = *(u32 *)(iVar2 + 0x86c);

          uStack_68 = *(u32 *)(iVar2 + 0x870);

          iVar4 = FUN_0044f120(&fStack_70);

          fVar15 = fStack_70 - ((float)iVar4 * 800.0f - 400.0f);

          cVar1 = *(char *)(iVar2 + 0xb29);

          iVar11 = iVar2 + iVar9 * 8;

          fVar12 = *(float *)(iVar2 + 0x85c);

          iVar4 = (int)cVar1;

          if (cVar1 < '\0') {

            iVar4 = iVar4 + 1;

          }

          fVar13 = (float)func_001126b0(uVar7);

          *(float *)(iVar11 + 0xa00) =

               ((float)(iVar4 >> 1) +

               (((fVar12 + (float)(cVar1 * param_4) +

                 (float)(int)((fVar16 / 2.0f + 0.0f) - fVar15 * (fVar16 / 800.0f))) -

                (((float)(int)cVar3 / 2.0f + 0.0f) - fVar14 * ((float)(int)cVar3 / 800.0f))) -

               (float)((int)cVar1 << 1))) - fVar13 / 2.0f;

          cVar3 = *(char *)(iVar2 + 0xb29);

          uStack_a0 = *(u32 *)(&DAT_0086bf8c + iVar8);

          uStack_9c = *(u32 *)(&DAT_0086bf90 + iVar8);

          fStack_98 = *(float *)(&DAT_0086bf94 + iVar8);

          iVar4 = FUN_0044f170(&uStack_a0);

          fVar14 = fStack_98 - ((float)iVar4 * 800.0f - 400.0f);

          fVar16 = (float)(int)*(char *)(iVar2 + 0xb29);

          uStack_90 = *(u32 *)(iVar2 + 0x868);

          uStack_8c = *(u32 *)(iVar2 + 0x86c);

          fStack_88 = *(float *)(iVar2 + 0x870);

          iVar4 = FUN_0044f170(&uStack_90);

          fVar15 = fStack_88 - ((float)iVar4 * 800.0f - 400.0f);

          cVar1 = *(char *)(iVar2 + 0xb29);

          pfVar10 = (float *)(iVar11 + 0xa04);

          fVar12 = *(float *)(iVar2 + 0x860);

          iVar4 = (int)cVar1;

          if (cVar1 < '\0') {

            iVar4 = iVar4 + 1;

          }

          fVar13 = (float)func_00112740(uVar7);

          *pfVar10 = ((float)(iVar4 >> 1) +

                     (((fVar12 + (float)(cVar1 * param_5) +

                       (float)(int)((fVar16 / 2.0f + 0.0f) - fVar15 * (fVar16 / 800.0f))) -

                      (((float)(int)cVar3 / 2.0f + 0.0f) - fVar14 * ((float)(int)cVar3 / 800.0f))) -

                     (float)((int)cVar1 << 1))) - fVar13 / 2.0f;

        }

        iVar8 = (int)uVar7;

        *(u32 *)(iVar8 + 0x2c) = 0x40400000;

        iVar4 = iVar2 + iVar9 * 8;

        *(u32 *)(iVar8 + 0x10) = *(u32 *)(iVar4 + 0xa00);

        *(float *)(iVar8 + 0x14) = *pfVar10;

        *(u8 *)(iVar8 + 0x18) = 0xff;

        fVar12 = *(float *)(iVar4 + 0xa00);

        if (*(float *)(iVar2 + 0x85c) < fVar12 + 8.0f) {
          if (((*(float *)(iVar2 + 0x860) < *pfVar10 + 8.0f) &&
              (fVar12 + 12.0f < *(float *)(iVar2 + 0x85c) + 126.0f)) &&
             (*pfVar10 + 12.0f < *(float *)(iVar2 + 0x860) + 126.0f)) {

            cVar3 = FUN_00433810((char)param_2,(char)param_3);

            if (cVar3 == '\0') {

              if (DAT_0095c110[(short)param_3 * 0x10 + (int)(short)param_2] == '\x01') {

                *(u8 *)(iVar8 + 0x18) = 0;

              }

            }

            else {

              uVar5 = FUN_00433810((char)param_2,(char)param_3);

              if (DAT_0095c110[uVar5 & 0xff] == '\x01') {

                *(u8 *)(iVar8 + 0x18) = 0;

              }

            }

          }

        }

        func_001127d0(uVar7,1);

        FUN_00115980(uVar7);

      }

    }

  }

  return;

}

// FUN_0042F440 NONMATCHING


void FUN_0042f440(int param_1,short param_2,short param_3,int param_4,int param_5)



{

  char cVar1;

  int iVar2;

  char cVar3;

  short sVar4;

  int iVar5;

  u32 uVar6;

  u64 uVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fStack_a0;

  u32 uStack_9c;

  float fStack_98;

  u32 uStack_90;

  u32 uStack_8c;

  float fStack_88;

  float fStack_80;

  u32 uStack_7c;

  float fStack_78;

  float fStack_70;

  u32 uStack_6c;

  u32 uStack_68;

  float fStack_60;

  u32 uStack_5c;

  float fStack_58;

  u32 uStack_50;

  u32 uStack_4c;

  float fStack_48;

  u32 uStack_40;

  u32 uStack_3c;

  float fStack_38;

  float fStack_30;

  u32 uStack_2c;

  float fStack_28;

  float fStack_20;

  u32 uStack_1c;

  u32 uStack_18;

  float fStack_10;

  u32 uStack_c;

  u32 uStack_8;

  

  iVar2 = *(int *)(param_1 + 0x3c);

  if (((DAT_0086e580 == 1) && (sVar4 = FUN_0044f120(0x86e684), param_2 == sVar4)) &&

     (sVar4 = FUN_0044f170(0x86e684), param_3 == sVar4)) {

    uVar7 = FUN_001158b0(0,DAT_007ce6e4,5);

    if (*(char *)(iVar2 + 0x865) == '\0') {

      cVar3 = *(char *)(iVar2 + 0xb29);

      fStack_30 = DAT_0086e684;

      uStack_2c = DAT_0086e688;

      fStack_28 = DAT_0086e68c;

      iVar5 = FUN_0044f120(&fStack_30);

      fVar10 = fStack_30 - ((float)iVar5 * 800.0f - 400.0f);

      fVar12 = (float)(int)*(char *)(iVar2 + 0xb29);

      K_FldFrame_CtlCopyPos(&fStack_20,*(u32 *)(DAT_008717f4 + 0x1e0));

      fStack_10 = fStack_20;

      uStack_c = uStack_1c;

      uStack_8 = uStack_18;

      iVar5 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

      fVar11 = fStack_10 - ((float)iVar5 * 800.0f - 400.0f);

      cVar1 = *(char *)(iVar2 + 0xb29);

      fVar8 = *(float *)(iVar2 + 0x85c);

      iVar5 = (int)cVar1;

      if (cVar1 < '\0') {

        iVar5 = iVar5 + 1;

      }

      fVar9 = (float)func_001126b0(uVar7);

      *(float *)(iVar2 + 0xb00) =

           ((float)(iVar5 >> 1) +

           (((fVar8 + (float)(cVar1 * param_4) +

             (float)(int)((fVar12 / 2.0f + 0.0f) - fVar11 * (fVar12 / 800.0f))) -

            (((float)(int)cVar3 / 2.0f + 0.0f) - fVar10 * ((float)(int)cVar3 / 800.0f))) -

           (float)((int)cVar1 << 1))) - fVar9 / 2.0f;

      cVar3 = *(char *)(iVar2 + 0xb29);

      fStack_60 = DAT_0086e684;

      uStack_5c = DAT_0086e688;

      fStack_58 = DAT_0086e68c;

      iVar5 = FUN_0044f170(&fStack_60);

      fVar10 = fStack_58 - ((float)iVar5 * 800.0f - 400.0f);

      fVar12 = (float)(int)*(char *)(iVar2 + 0xb29);

      K_FldFrame_CtlCopyPos(&uStack_50,*(u32 *)(DAT_008717f4 + 0x1e0));

      uStack_40 = uStack_50;

      uStack_3c = uStack_4c;

      fStack_38 = fStack_48;

      iVar5 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

      fVar11 = fStack_38 - ((float)iVar5 * 800.0f - 400.0f);

      cVar1 = *(char *)(iVar2 + 0xb29);

      fVar8 = *(float *)(iVar2 + 0x860);

      iVar5 = (int)cVar1;

      if (cVar1 < '\0') {

        iVar5 = iVar5 + 1;

      }

      fVar9 = (float)func_00112740(uVar7);

      *(float *)(iVar2 + 0xb04) =

           ((float)(iVar5 >> 1) +

           (((fVar8 + (float)(cVar1 * param_5) +

             (float)(int)((fVar12 / 2.0f + 0.0f) - fVar11 * (fVar12 / 800.0f))) -

            (((float)(int)cVar3 / 2.0f + 0.0f) - fVar10 * ((float)(int)cVar3 / 800.0f))) -

           (float)((int)cVar1 << 1))) - fVar9 / 2.0f;

    }

    else {

      cVar3 = *(char *)(iVar2 + 0xb29);

      fStack_80 = DAT_0086e684;

      uStack_7c = DAT_0086e688;

      fStack_78 = DAT_0086e68c;

      iVar5 = FUN_0044f120(&fStack_80);

      fVar10 = fStack_80 - ((float)iVar5 * 800.0f - 400.0f);

      fVar12 = (float)(int)*(char *)(iVar2 + 0xb29);

      fStack_70 = *(float *)(iVar2 + 0x868);

      uStack_6c = *(u32 *)(iVar2 + 0x86c);

      uStack_68 = *(u32 *)(iVar2 + 0x870);

      iVar5 = FUN_0044f120(&fStack_70);

      fVar11 = fStack_70 - ((float)iVar5 * 800.0f - 400.0f);

      cVar1 = *(char *)(iVar2 + 0xb29);

      fVar8 = *(float *)(iVar2 + 0x85c);

      iVar5 = (int)cVar1;

      if (cVar1 < '\0') {

        iVar5 = iVar5 + 1;

      }

      fVar9 = (float)func_001126b0(uVar7);

      *(float *)(iVar2 + 0xb00) =

           ((float)(iVar5 >> 1) +

           (((fVar8 + (float)(cVar1 * param_4) +

             (float)(int)((fVar12 / 2.0f + 0.0f) - fVar11 * (fVar12 / 800.0f))) -

            (((float)(int)cVar3 / 2.0f + 0.0f) - fVar10 * ((float)(int)cVar3 / 800.0f))) -

           (float)((int)cVar1 << 1))) - fVar9 / 2.0f;

      cVar3 = *(char *)(iVar2 + 0xb29);

      fStack_a0 = DAT_0086e684;

      uStack_9c = DAT_0086e688;

      fStack_98 = DAT_0086e68c;

      iVar5 = FUN_0044f170(&fStack_a0);

      fVar10 = fStack_98 - ((float)iVar5 * 800.0f - 400.0f);

      fVar12 = (float)(int)*(char *)(iVar2 + 0xb29);

      uStack_90 = *(u32 *)(iVar2 + 0x868);

      uStack_8c = *(u32 *)(iVar2 + 0x86c);

      fStack_88 = *(float *)(iVar2 + 0x870);

      iVar5 = FUN_0044f170(&uStack_90);

      fVar11 = fStack_88 - ((float)iVar5 * 800.0f - 400.0f);

      cVar1 = *(char *)(iVar2 + 0xb29);

      fVar8 = *(float *)(iVar2 + 0x860);

      iVar5 = (int)cVar1;

      if (cVar1 < '\0') {

        iVar5 = iVar5 + 1;

      }

      fVar9 = (float)func_00112740(uVar7);

      *(float *)(iVar2 + 0xb04) =

           ((float)(iVar5 >> 1) +

           (((fVar8 + (float)(cVar1 * param_5) +

             (float)(int)((fVar12 / 2.0f + 0.0f) - fVar11 * (fVar12 / 800.0f))) -

            (((float)(int)cVar3 / 2.0f + 0.0f) - fVar10 * ((float)(int)cVar3 / 800.0f))) -

           (float)((int)cVar1 << 1))) - fVar9 / 2.0f;

    }

    iVar5 = (int)uVar7;

    *(u32 *)(iVar5 + 0x2c) = 0x40400000;

    *(u32 *)(iVar5 + 0x10) = *(u32 *)(iVar2 + 0xb00);

    *(u32 *)(iVar5 + 0x14) = *(u32 *)(iVar2 + 0xb04);

    *(u8 *)(iVar5 + 0x18) = 0xff;

    if (*(float *)(iVar2 + 0x85c) < *(float *)(iVar2 + 0xb00) + 8.0f) {

      if (((*(float *)(iVar2 + 0x860) < *(float *)(iVar2 + 0xb04) + 8.0f) &&

          (*(float *)(iVar2 + 0xb00) + 12.0f < *(float *)(iVar2 + 0x85c) + 126.0f)) &&

         (*(float *)(iVar2 + 0xb04) + 12.0f < *(float *)(iVar2 + 0x860) + 126.0f)) {

        cVar3 = FUN_00433810((char)param_2,(char)param_3);

        if (cVar3 == '\0') {

          if (DAT_0095c110[param_3 * 0x10 + (int)param_2] == '\x01') {

            *(u8 *)(iVar5 + 0x18) = 0;

          }

        }

        else {

          uVar6 = FUN_00433810((char)param_2,(char)param_3);

          if (DAT_0095c110[uVar6 & 0xff] == '\x01') {

            *(u8 *)(iVar5 + 0x18) = 0;

          }

        }

      }

    }

    func_001127d0(uVar7,1);

    FUN_00115980(uVar7);

  }

  return;

}

// FUN_0042FD80 NONMATCHING


void FUN_0042fd80(u32 *param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  u32 uVar4;

  u32 uVar5;

  u32 unaff_s4_lo;

  u32 unaff_s5_lo;

  u32 uStack_10;

  u32 uStack_c;

  u32 uStack_8;

  

  iVar3 = *(int *)(param_2 + 0x3c);

  for (uVar5 = 0; (int)uVar5 < 0x10; uVar5 = uVar5 + 1) {

    for (uVar4 = 0; (int)uVar4 < 0x10; uVar4 = uVar4 + 1) {

      iVar1 = K_Field_Get();

      if (*(char *)(uVar5 * 0x100 + iVar1 + uVar4 * 0x10 + 0x4a) == '\b') {

        iVar1 = K_Field_Get();

        if (*(char *)(uVar5 * 0x100 + iVar1 + uVar4 * 0x10 + 0x49) == '\x01') {

          unaff_s5_lo = uVar4;

          unaff_s4_lo = uVar5;

        }

      }

    }

  }

  *(char *)(iVar3 + 0xbb0) = (char)unaff_s5_lo;

  *(char *)(iVar3 + 0xbb1) = (char)unaff_s4_lo;

  *(float *)(iVar3 + 0xb10) = (float)(int)unaff_s5_lo * 800.0;

  *(float *)(iVar3 + 0xb14) = (float)(int)unaff_s4_lo * 800.0;

  for (uVar5 = unaff_s5_lo; (int)uVar5 < (int)(unaff_s5_lo + 2); uVar5 = uVar5 + 1) {

    iVar3 = uVar5 * 0x10;

    for (uVar4 = unaff_s4_lo; (int)uVar4 < (int)(unaff_s4_lo + 2); uVar4 = uVar4 + 1) {

      iVar2 = uVar4 * 0x100;

      iVar1 = K_Field_Get();

      if (((*(u8 *)(iVar3 + iVar1 + iVar2 + 0x53) & 1) != 0) &&

         (iVar1 = K_Field_Get(), *(char *)(iVar3 + iVar1 + iVar2 + -0xb6) != '\b')) {

        func_001bf220(&uStack_10,uVar5 & 0xffff,uVar4 - 1 & 0xffff);

      }

      iVar1 = K_Field_Get();

      if (((*(u8 *)(iVar3 + iVar1 + iVar2 + 0x53) & 2) != 0) &&

         (iVar1 = K_Field_Get(), *(char *)(iVar3 + iVar1 + iVar2 + 0x3a) != '\b')) {

        func_001bf220(&uStack_10,uVar5 - 1 & 0xffff,uVar4 & 0xffff);

      }

      iVar1 = K_Field_Get();

      if (((*(u8 *)(iVar3 + iVar1 + iVar2 + 0x53) & 4) != 0) &&

         (iVar1 = K_Field_Get(), *(char *)(iVar3 + iVar1 + iVar2 + 0x14a) != '\b')) {

        func_001bf220(&uStack_10,uVar5 & 0xffff,uVar4 + 1 & 0xffff);

      }

      iVar1 = K_Field_Get();

      if (((*(u8 *)(iVar3 + iVar1 + iVar2 + 0x53) & 8) != 0) &&

         (iVar1 = K_Field_Get(), *(char *)(iVar3 + iVar1 + iVar2 + 0x5a) != '\b')) {

        func_001bf220(&uStack_10,uVar5 + 1 & 0xffff,uVar4 & 0xffff);

      }

    }

  }

  *param_1 = uStack_10;

  param_1[1] = uStack_c;

  param_1[2] = uStack_8;

  return;

}
