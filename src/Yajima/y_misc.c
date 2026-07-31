#include "Yajima/y_misc.h"
#include "Yajima/y_runtime.h"
typedef struct YajimaVec2 {
    f32 x;
    f32 y;
} YajimaVec2;
typedef struct YajimaVec3 {
    f32 x;
    f32 y;
    f32 z;
} YajimaVec3;
typedef struct YajimaVec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} YajimaVec4;
typedef struct YajimaColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} YajimaColor;
typedef struct YajimaVec16 {
    f32 lane[16];
} YajimaVec16;
typedef struct YajimaPackedRow {
    u8 pad[0x8c0];
    YajimaVec2 value;
} __attribute__((packed)) YajimaPackedRow;
typedef struct YajimaPackedEntry {
    u8 pad[0x8d8];
    s8 counter;
    u8 pad_8d9[0xe];
    s8 delay;
} __attribute__((packed)) YajimaPackedEntry;
typedef int (*code)(...);
char cGpffffb9d4;
char cGpffffb9d8;
char cGpffffb9ec;
int iGpffffb5c0;
int *piGpffffa850;
u8 uGpffffb9ec;
u32 uGpffffb9f4;
extern u8 cGpffffb9c0;
extern u8* iGpffffb9b8;
static inline uintptr_t Yajima_AddOffsetFirst(uintptr_t offset, uintptr_t base)
{
  return offset + base;
}
extern f32 sinf(f32 value);
extern f32 FUN_001126b0(u32 param_1);
extern f32 FUN_00112740(u32 param_1);

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
u32 FUN_00425d50(s8 param_1,s8 param_2);
void FUN_00426040(int param_1,u8 param_2);
void FUN_00426050(int param_1);
u8 FUN_00426070(int param_1);
u32 * FUN_00426090(void);
u64 FUN_004260a0(int param_1);
void FUN_004264a0(int param_1);
u32 FUN_004264d0(u64 param_1,s8 param_2);
u32 FUN_00426590(int param_1);
void FUN_00427640(int param_1);
u32 FUN_00427670(u32 param_3,u32 param_4, char param_5,u8 param_6, float param_1,float param_2);
#pragma alias FUN_00427670_typed FUN_00427670
extern u32 FUN_00427670_typed(float param_1,float param_2,int param_3,u32 param_4, char param_5,u8 param_6);
u32 FUN_00427830(int param_2, u32 param_3, YajimaVec2 param_4, u32 param_5,
                  float param_1, YajimaVec4 *param_6, YajimaVec4 *param_7, int param_8);
extern u32 FUN_00427830(int param_2, u32 param_3, YajimaVec2 param_4, u32 param_5, float param_1, YajimaVec4 *param_6, YajimaVec4 *param_7, int param_8);
u32 FUN_00427a10(int param_2, u32 param_3, YajimaVec2 param_4, u32 param_5,
                  float param_1, YajimaVec4 *param_6, YajimaVec4 *param_7, int param_8);
extern u32 FUN_00427a10(int param_2, u32 param_3, YajimaVec2 param_4, u32 param_5, float param_1, YajimaVec4 *param_6, YajimaVec4 *param_7, int param_8);
u32 FUN_00427bf0(u32 param_6, u32 param_7, YajimaVec2 param_8, u32 param_9,
                  float param_1, float param_2, float param_3, float param_4,
                  float param_5, YajimaVec4 *param_10);
void FUN_00427db0(int object, YajimaVec2 value);
void FUN_00427de0(int param_1,u8 param_2,u8 param_3,u8 param_4, u8 param_5);
void FUN_00427e20(float param_1,float param_2,int param_3);
void FUN_00427e50(int param_1,u8 param_2);
void FUN_00427e60(int param_1,u8 param_2);
void FUN_00427e70(float param_1,u32 param_4,float param_2,float param_3,int param_5,int param_6, u32 *param_7);
u32 FUN_004281f0(u32 param_1);
void FUN_00429c60(int param_1);
u32 FUN_00429d40(u32 param_1,u64 param_2);
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
void FUN_0042a550(int param_1,u32 param_2,u32 param_3,u32 param_4);
u8 FUN_0042aa40(int param_1,u32 param_2,u32 param_3);
void FUN_0042ac60(int param_1,int param_2);
void FUN_0042adb0(int param_1);
void FUN_0042b050(int param_1);
void FUN_0042b540(int param_1);
u8 FUN_0042ba30(void);
void FUN_0042ba50(u32 param_1);
void FUN_0042bc10(int param_1);
void FUN_0042bd80();
#pragma alias FUN_0042bd80_typed FUN_0042bd80
extern void FUN_0042bd80_typed(u64 param_1);
void FUN_0042bfd0(int param_1);
void FUN_0042c0a0(int param_1,char param_2,short param_3,short param_4,int param_5,int param_6);
void FUN_0042cd80(int param_1);
void FUN_0042cfc0(int param_1,u16 param_2,u16 param_3,int param_4,int param_5);
void FUN_0042dd90(int param_1,short param_2,u16 param_3,int param_4,int param_5);
void FUN_0042ea60(int param_1,u16 param_2,u16 param_3,int param_4,int param_5);
void FUN_0042f440(int param_1,short param_2,short param_3,int param_4,int param_5);
void FUN_0042fd80(float *param_1,int param_2);
#pragma alias FUN_004560d0_typed FUN_004560d0
extern u32 FUN_004560d0_typed(u32 param_1,float param_2,float param_3,float param_4,u32 param_5,u32 param_6);
#pragma alias FUN_00423fe0_vec2 FUN_00423fe0
extern void FUN_00423fe0_vec2(YajimaVec2 *param_1,int param_2,int param_3,int param_4,int param_5,int param_6);
#pragma alias FUN_004c31b0_ymisc FUN_004c31b0
extern void FUN_004c31b0_ymisc(void *matrix,const void *axis,f32 angle,s32 mode);
#pragma alias FUN_004c6be0_ymisc FUN_004c6be0
extern void FUN_004c6be0_ymisc(float *out,const float *in,u32 matrix);
void FUN_004563b0(f32 value, int object);
int FUN_0044f120();
int FUN_0044f170();
extern int FUN_00488f30(void);
extern void FUN_00430780(f32, YajimaVec2, s32, s32, s32);
#pragma alias DAT_006b4470_abs DAT_006b4470
extern char DAT_006b4470_abs[];
/* FUSION_GLOBALS */
u32 DAT_0087190c;
u32 DAT_0095c0e0;
u32 DAT_006b44c0;
u32 DAT_006b44c8;
u32 DAT_006b44d0;
u32 DAT_006b44d8;
u32 DAT_006b44e0;
u32 DAT_006b44e8;
#pragma alias DAT_006b44d0_abs DAT_006b44d0
extern u8 DAT_006b44d0_abs[];
#pragma alias DAT_006b44d8_abs DAT_006b44d8
extern u8 DAT_006b44d8_abs[];
#pragma alias DAT_006b44e0_abs DAT_006b44e0
extern u8 DAT_006b44e0_abs[];
#pragma alias DAT_006b44e8_abs DAT_006b44e8
extern u8 DAT_006b44e8_abs[];
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
#pragma alias DAT_007ce6cc_byte DAT_007ce6cc
#pragma alias DAT_007ce6d0_byte DAT_007ce6d0
#pragma alias DAT_007ce6d4_byte DAT_007ce6d4
extern u8 DAT_007ce6cc_byte;
extern u8 DAT_007ce6d0_byte;
extern u8 DAT_007ce6d4_byte;
u32 DAT_007ce6d8;
u32 DAT_007ce6dc;
u32 DAT_007ce6e4;
u32 DAT_007ce6ec;
#pragma alias DAT_007ce6ec_abs DAT_007ce6ec
extern u32 DAT_007ce6ec_abs;
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
float DAT_0086e684;
#pragma alias DAT_0086e684_abs DAT_0086e684
extern u8 DAT_0086e684_abs[];
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
#pragma alias DAT_008717a0_unit_rows DAT_008717a0
extern YRuntimeUnitRow DAT_008717a0_unit_rows[];
#pragma alias DAT_008717a0_unit_rows_abs DAT_008717a0
extern YRuntimeUnitRow DAT_008717a0_unit_rows_abs[];
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
#pragma alias DAT_008719a8_abs DAT_008719a8
#pragma alias DAT_008719b4_abs DAT_008719b4
#pragma alias DAT_00871b08_abs DAT_00871b08
#pragma alias DAT_00871b68_abs DAT_00871b68
#pragma alias DAT_00871b74_abs DAT_00871b74
#pragma alias DAT_00871cc8_abs DAT_00871cc8
#pragma alias DAT_00871d28_abs DAT_00871d28
#pragma alias DAT_00871d34_abs DAT_00871d34
#pragma alias DAT_00871e88_abs DAT_00871e88
extern u32 DAT_008719a8_abs[];
extern u32 DAT_008719b4_abs[];
extern u16 DAT_00871b08_abs[];
extern u32 DAT_00871b68_abs[];
extern u32 DAT_00871b74_abs[];
extern u16 DAT_00871cc8_abs[];
extern u32 DAT_00871d28_abs[];
extern u32 DAT_00871d34_abs[];
extern u16 DAT_00871e88_abs[];
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
#pragma alias DAT_0095bee0_abs DAT_0095bee0
extern u8 DAT_0095bee0_abs[];
extern u8 DAT_006b4490[];
extern u8 DAT_006b44b0[];
u32 DAT_0095bfe0;
#pragma alias DAT_0095bfe0_abs DAT_0095bfe0
extern u8 DAT_0095bfe0_abs[];
u8 DAT_0095c100[];
u8 DAT_0095c110[];
u8 DAT_0095c210[];
float DAT_00960088;
#pragma alias DAT_00960088_abs DAT_00960088
extern u8 DAT_00960088_abs[];
code DAT_00960090;
 #pragma alias DAT_00960090_abs DAT_00960090
 extern u8 DAT_00960090_abs[];
code DAT_009600a0;
#pragma alias DAT_009600a0_abs DAT_009600a0
extern u8 DAT_009600a0_abs[];
extern code DAT_0096017c;
 #pragma alias DAT_0096017c_abs DAT_0096017c
extern code DAT_0096017c_abs[];
#pragma alias FUN_004264d0_u32 FUN_004264d0
extern u32 FUN_004264d0_u32(u32 param_1,s8 param_2);
#pragma alias FUN_004d0f00_arg FUN_004d0f00
extern void FUN_004d0f00_arg(u32 param_1);
#pragma alias FUN_00115980_arg FUN_00115980
extern void FUN_00115980_arg(u32 param_1);
#pragma alias FUN_00194b80_u32 FUN_00194b80
extern u32 FUN_00194b80_u32(u32, u32, u8 *, u32 (*)(int), void (*)(int), u32);
#pragma alias FUN_00194b20_u32 FUN_00194b20
extern u32 FUN_00194b20_u32(u32, u8 *, u32, u32 (*)(int), void (*)(int), u32);
code DAT_00960184;
extern char DAT_006b4400[];
extern u8 DAT_006b4430[];
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

// FUN_00424730


u32 FUN_00424730(void)
{
  s32 result = -1;
  s32 type = scrGetIntPara(0);
  s32 index = scrGetIntPara(1);
  s32 count;
  s32 i;

  if ((type > 0) && (type < 12)) {
    count = func_0016f490((s16)(type + 0x100));
    if ((index < count) && (count > 0)) {
      scrSetIntReturnVal(1);
      return 1;
    } else {
      for (i = 0; i < 20; i++) {
        if (func_00170ab0((s16)type, (s16)i) > 0) {
          if (index == count) {
            result = func_00170ab0((s16)type, (s16)i);
          }
          count++;
        }
      }
      scrSetIntReturnVal(result);
    }
  } else {
    scrSetIntReturnVal(0);
  }
  return 1;
}

// MWCC b210 register-colouring floor: retail swaps $s1/$s2 throughout the function.
// Moving the result declaration after the type initializer regressed nd10 -> nd19 and was reverted.
// FUN_00424880 NONMATCHING


u32 FUN_00424880(void)
{
  s32 result = 0;
  s32 type = scrGetIntPara(0);
  s32 index = scrGetIntPara(1);
  s32 count;

  if ((type > 0) && (type < 12)) {
    count = func_0016f490((s16)(type + 0x100));
    if ((index < count) && (count > 0)) {
      result = func_0016f810((s16)(type + 0x100), index);
      scrSetIntReturnVal((u8)result);
      return 1;
    }
    for (index = 0; index < 20; index++) {
      if (func_00170ab0((s16)type, (s16)index) > 0) {
        result = 0;
      }
    }
    scrSetIntReturnVal(result);
  } else {
    scrSetIntReturnVal(0);
  }
  return 1;
}

// FUN_004249B0


u32 FUN_004249b0(void)



{

  char bVar1;

  int uVar2;

  u32 active;

  int iVar4;

  

  bVar1 = 0;

  uVar2 = scrGetIntPara(0);

  if ((0 < uVar2) && (uVar2 < 0xc)) {

    for (iVar4 = 0; iVar4 < 0x14; iVar4 = iVar4 + 1) {


      func_00170b20((short)uVar2,(short)iVar4,0);

      func_00170b90((short)uVar2,(short)iVar4,0);

      func_0016fea0((short)(uVar2 + 0x100),iVar4,0);

    }


    active = (0 != DAT_008719a8_abs[0]);
    if (active) {
      active = (0 != DAT_008719b4_abs[0]);
    }
    if (active && DAT_00871b08_abs[0] == uVar2) {
      DAT_007ce6cc_byte = 0;
      bVar1 = 1;
    }

    active = (0 != DAT_00871b68_abs[0]);
    if (active) {
      active = (0 != DAT_00871b74_abs[0]);
    }
    if (active && DAT_00871cc8_abs[0] == uVar2) {
      DAT_007ce6d0_byte = 0;
      bVar1 = 1;
    }

    active = (0 != DAT_00871d28_abs[0]);
    if (active) {
      active = (0 != DAT_00871d34_abs[0]);
    }
    if (active && DAT_00871e88_abs[0] == uVar2) {
      DAT_007ce6d4_byte = 0;
      bVar1 = 1;
    }

  }

  if ((s8)bVar1 == 0) {

    DAT_007ce6cc_byte = 0;

    DAT_007ce6d0_byte = 0;

    DAT_007ce6d4_byte = 0;

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
  int lVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  short unaff_s5_lo;
  YRuntimeUnitRow *selectedRow;
  YajimaVec3 pos;
  YajimaVec3 copiedPos;
  char acStack_4 [4];

  sVar8 = 2;
  bVar2 = 0;
  iVar7 = 0;
  FUN_0016f3e0(0,0);
  sVar3 = scrGetIntPara(0);
  {
    int scanIndex;
    YRuntimeUnitRow *rows = DAT_008717a0_unit_rows_abs;
    for (scanIndex = 0; scanIndex < 4; scanIndex = scanIndex + 1) {
      YRuntimeUnitRow *row = &rows[scanIndex];
      acStack_4[scanIndex] = '\0';
      bVar1 = 0;
      if ((row->unk_048 != 0) && (row->unk_054 != 0)) {
        bVar1 = 1;
      }
      if ((bVar1) && ((long)sVar3 == row->unit_id)) {
        unaff_s5_lo = (short)scanIndex;
      }
    }
  }
  selectedRow = &DAT_008717a0_unit_rows_abs[unaff_s5_lo];
  for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {
    YRuntimeUnitRow *row = &DAT_008717a0_unit_rows_abs[iVar6];
    bVar1 = 0;
    if ((row->unk_048 != 0) && (row->unk_054 != 0)) {
      bVar1 = 1;
    }
    if ((bVar1) &&
       (lVar5 = K_FldEvent_AreUnitsWithinDist(0x43fa0000,selectedRow), lVar5 == 1)) {
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
          YRuntimeUnitRow *row = &DAT_008717a0_unit_rows_abs[iVar4];
          bVar1 = 0;
          if ((row->unk_048 != 0) && (row->unk_054 != 0)) {
            bVar1 = 1;
          }
          if ((bVar1) &&
             (lVar5 = K_FldEvent_AreUnitsWithinDist(0x43fa0000,selectedRow), lVar5 == 1)) {
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
      K_FldFrame_CtlCopyPos(&pos,*(u32 *)((u8 *)DAT_008717a0_unit_rows_abs[iVar6].unk_054 + 0x1e0));
      copiedPos = pos;
      iVar4 = K_Field_Get();
      func_001a9760(*(u32 *)(iVar4 + 0x10),6,&copiedPos,3,1);
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

  YajimaVec4 ambientColor;

  YajimaVec4 directionalColor;

  float auStack_70[16];

  float *puVar6f;

  float *puVar11;
  u32 uStack_4;

  

  pcVar2 = *(char **)(param_1 + 0x3c);

  iVar4 = MT_Scene_GetResListHead(4);

  iVar5 = kwlnGetAmbientLight();

  ambientColor = *(YajimaVec4 *)(iVar5 + 0x18);

  iVar5 = kwlnGetDirectionalLight();

  directionalColor = *(YajimaVec4 *)(iVar5 + 0x18);

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

// FUN_00425BA0


void FUN_00425ba0(int param_1)



{

  int object = param_1;
  {
    int iVar1;
    for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
      if (((u32 *)DAT_0095bec0_abs)[iVar1] != 0) {
        mdlDestroy(((u32 *)DAT_0095bec0_abs)[iVar1]);
      }
    }
  }
  {
    int iVar1;
    for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
      if (((u32 *)DAT_0095bea0_abs)[iVar1] != 0) {
        mdlDestroy(((u32 *)DAT_0095bea0_abs)[iVar1]);
      }
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


u32 FUN_00425d50(s8 param_1,s8 param_2)



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

  u32 uVar8;

  u32 uVar9;

  int lVar10;

  u32 *puVar11;

  u32 *puVar12;

  u32 auStack_60 [16];

  YajimaVec4 directionalColor;

  YajimaVec4 ambientColor;

  

  iVar6 = MT_Scene_GetResListHead(4);

  pcVar1 = *(char **)(param_1 + 0x3c);

  iVar7 = kwlnGetAmbientLight();

  ambientColor = *(YajimaVec4 *)(iVar7 + 0x18);

  iVar7 = kwlnGetDirectionalLight();

  directionalColor = *(YajimaVec4 *)(iVar7 + 0x18);

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
      uVar4 = FUN_00425d50(1,(u8)pcVar1[1]);

      FUN_00317a20((&DAT_0095bec0)[DAT_007ce6b4]);

      if ((DAT_007e094c & 0x20) != 0) {

        mdlAnimSetSpeed((&DAT_0095bec0)[DAT_007ce6b4],0,2.0f);

      }

      else {

        mdlAnimSetSpeed((&DAT_0095bec0)[DAT_007ce6b4],0,1.0f);

      }

      if (*(char *)((&DAT_0095bec0)[DAT_007ce6b4] + 0xee) == '\x01') {

        *pcVar1 = '\x02';

        DAT_007ce6b4 = pcVar1[1];

        mdlAnimSet((&DAT_0095bec0)[DAT_007ce6b4],0,0,0,0);

      }

    }

    else if (cVar5 == '\0') {

      uVar4 = FUN_00425d50(0,(u8)pcVar1[1]);

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

  FUN_004944b0(uVar8,&ambientColor);

  uVar8 = kwlnGetDirectionalLight();

  FUN_004944b0(uVar8,&directionalColor);

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

// FUN_004264D0


u32 FUN_004264d0(u64 param_1,s8 param_2)



{

  u32 lVar1;

  u32 uVar2;

  

  memset(&DAT_007ce6b8,0,4);

  lVar1 = (*DAT_00960184_abs)(1,2,0x40000);

  if (lVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = kwlnTaskCreate(param_1,DAT_006b4400 + 0x20,0x831,FUN_004260a0,FUN_004264a0,lVar1);

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
  char *entry;
  char *color;

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

  if (pcVar2[0x150] != '\x01') {

    cVar1 = *pcVar2;

    if (cVar1 != '\x02') {

      if ((cVar1 == '\x01') || (cVar1 == '\0')) {

        iVar3 = kwlnGetMainCamera();

        fVar5 = 1.0f / *(float *)(iVar3 + 0x80);

        cVar1 = pcVar2[0x141];

        switch (cVar1) { case '\0': if (pcVar2[0x150] == '\0') {
        
          for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
            entry = pcVar2 + iVar3 * 0x40;
            color = pcVar2 + iVar3 * 4 + 0x110;
        
            *(float *)(entry + 0x18) = DAT_00960088 - *(float *)(pcVar2 + 0x130);
        
            *(float *)(entry + 0x28) = fVar5;
        
            *(float *)(entry + 0x30) = (float)(u8)color[0];
        
            *(float *)(entry + 0x34) = (float)(u8)color[1];
        
            *(float *)(entry + 0x38) = (float)(u8)color[2];
        
            *(float *)(entry + 0x3c) = (float)(u8)color[3];
        
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
          entry = pcVar2 + iVar3 * 0x40;
          color = pcVar2 + iVar3 * 4 + 0x110;
        
          *(float *)(entry + 0x18) = DAT_00960088 - *(float *)(pcVar2 + 0x130);
        
          *(float *)(entry + 0x28) = fVar5;
        
          *(float *)(entry + 0x30) = (float)(u8)color[0];
        
          *(float *)(entry + 0x34) = (float)(u8)color[1];
        
          *(float *)(entry + 0x38) = (float)(u8)color[2];
        
          *(float *)(entry + 0x3c) = (float)(u8)color[3];
        
        }
        
        *(u32 *)(pcVar2 + 0x20) = 0;
        
        *(u32 *)(pcVar2 + 0x24) = 0;
        
        *(float *)(pcVar2 + 0x10) =
        
             *(float *)(pcVar2 + 0x134) -
        
             ((float)*(int *)(pcVar2 + 0x128) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        *(float *)(pcVar2 + 0x14) =
        
             *(float *)(pcVar2 + 0x138) -
        
             ((float)*(int *)(pcVar2 + 300) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        *(float *)(pcVar2 + 0x60) = 1.0f;
        
        *(u32 *)(pcVar2 + 0x64) = 0;
        
        *(float *)(pcVar2 + 0x50) =
        
             *(float *)(pcVar2 + 0x134) +
        
             ((float)*(int *)(pcVar2 + 0x128) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        *(float *)(pcVar2 + 0x54) =
        
             *(float *)(pcVar2 + 0x138) -
        
             ((float)*(int *)(pcVar2 + 300) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        *(u32 *)(pcVar2 + 0xa0) = 0;
        
        *(float *)(pcVar2 + 0xa4) = 1.0f;
        
        *(float *)(pcVar2 + 0x90) =
        
             *(float *)(pcVar2 + 0x134) -
        
             ((float)*(int *)(pcVar2 + 0x128) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        *(float *)(pcVar2 + 0x94) =
        
             *(float *)(pcVar2 + 0x138) +
        
             ((float)*(int *)(pcVar2 + 300) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        *(float *)(pcVar2 + 0xe0) = 1.0f;
        
        *(float *)(pcVar2 + 0xe4) = 1.0f;
        
        *(float *)(pcVar2 + 0xd0) =
        
             *(float *)(pcVar2 + 0x134) +
        
             ((float)*(int *)(pcVar2 + 0x128) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        *(float *)(pcVar2 + 0xd4) =
        
             *(float *)(pcVar2 + 0x138) +
        
             ((float)*(int *)(pcVar2 + 300) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        (*DAT_009600a0)(4,pcVar2 + 0x10,4); break; case '\x02': for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
          entry = pcVar2 + iVar3 * 0x40;
          color = pcVar2 + iVar3 * 4 + 0x110;
        
          *(float *)(entry + 0x18) = DAT_00960088 - *(float *)(pcVar2 + 0x130);
        
          *(float *)(entry + 0x28) = fVar5;
        
          *(float *)(entry + 0x30) = (float)(u8)color[0];
        
          *(float *)(entry + 0x34) = (float)(u8)color[1];
        
          *(float *)(entry + 0x38) = (float)(u8)color[2];
        
          *(float *)(entry + 0x3c) = (float)(u8)color[3];
        
        }
        
        *(u32 *)(pcVar2 + 0x20) = 0;
        
        *(u32 *)(pcVar2 + 0x24) = 0;
        
        *(u32 *)(pcVar2 + 0x10) = *(u32 *)(pcVar2 + 0x134);
        
        *(u32 *)(pcVar2 + 0x14) = *(u32 *)(pcVar2 + 0x138);
        
        *(float *)(pcVar2 + 0x60) = 1.0f;
        
        *(u32 *)(pcVar2 + 0x64) = 0;
        
        *(float *)(pcVar2 + 0x50) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128);
        
        *(u32 *)(pcVar2 + 0x54) = *(u32 *)(pcVar2 + 0x138);
        
        *(u32 *)(pcVar2 + 0xa0) = 0;
        
        *(float *)(pcVar2 + 0xa4) = 1.0f;
        
        *(u32 *)(pcVar2 + 0x90) = *(u32 *)(pcVar2 + 0x134);
        
        *(float *)(pcVar2 + 0x94) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
        *(float *)(pcVar2 + 0xe0) = 1.0f;
        
        *(float *)(pcVar2 + 0xe4) = 1.0f;
        
        *(float *)(pcVar2 + 0xd0) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128);
        
        *(float *)(pcVar2 + 0xd4) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
        (*DAT_009600a0)(4,pcVar2 + 0x10,4); break; case '\x03': for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
          entry = pcVar2 + iVar3 * 0x40;
          color = pcVar2 + iVar3 * 4 + 0x110;
        
          *(float *)(entry + 0x18) = DAT_00960088 - *(float *)(pcVar2 + 0x130);
        
          *(float *)(entry + 0x28) = fVar5;
        
          *(float *)(entry + 0x30) = (float)(u8)color[0];
        
          *(float *)(entry + 0x34) = (float)(u8)color[1];
        
          *(float *)(entry + 0x38) = (float)(u8)color[2];
        
          *(float *)(entry + 0x3c) = (float)(u8)color[3];
        
        }
        
        *(u32 *)(pcVar2 + 0x20) = 0;
        
        *(u32 *)(pcVar2 + 0x24) = 0;
        
        *(u32 *)(pcVar2 + 0x10) = *(u32 *)(pcVar2 + 0x134);
        
        *(u32 *)(pcVar2 + 0x14) = *(u32 *)(pcVar2 + 0x138);
        
        *(u32 *)(pcVar2 + 0x60) = *(u32 *)(pcVar2 + 0x174);
        
        *(u32 *)(pcVar2 + 0x64) = 0;
        
        *(float *)(pcVar2 + 0x50) = *(float *)(pcVar2 + 0x134) + *(float *)(pcVar2 + 0x184);
        
        *(u32 *)(pcVar2 + 0x54) = *(u32 *)(pcVar2 + 0x138);
        
        *(u32 *)(pcVar2 + 0xa0) = 0;
        
        *(u32 *)(pcVar2 + 0xa4) = *(u32 *)(pcVar2 + 0x178);
        
        *(u32 *)(pcVar2 + 0x90) = *(u32 *)(pcVar2 + 0x134);
        
        *(float *)(pcVar2 + 0x94) = *(float *)(pcVar2 + 0x138) + *(float *)(pcVar2 + 0x188);
        
        *(u32 *)(pcVar2 + 0xe0) = *(u32 *)(pcVar2 + 0x174);
        
        *(u32 *)(pcVar2 + 0xe4) = *(u32 *)(pcVar2 + 0x178);
        
        *(float *)(pcVar2 + 0xd0) = *(float *)(pcVar2 + 0x134) + *(float *)(pcVar2 + 0x184);
        
        *(float *)(pcVar2 + 0xd4) = *(float *)(pcVar2 + 0x138) + *(float *)(pcVar2 + 0x188);
        
        (*DAT_009600a0)(4,pcVar2 + 0x10,4); break; case '\x04': for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
          entry = pcVar2 + iVar3 * 0x40;
          color = pcVar2 + iVar3 * 4 + 0x110;
        
          *(float *)(entry + 0x18) = DAT_00960088 - *(float *)(pcVar2 + 0x130);
        
          *(float *)(entry + 0x28) = fVar5;
        
          *(float *)(entry + 0x30) = (float)(u8)color[0];
        
          *(float *)(entry + 0x34) = (float)(u8)color[1];
        
          *(float *)(entry + 0x38) = (float)(u8)color[2];
        
          *(float *)(entry + 0x3c) = (float)(u8)color[3];
        
        }
        
        for (iVar3 = 0; iVar3 < *(int *)(pcVar2 + 300); iVar3 = iVar3 + 1) {
        
          *(u32 *)(pcVar2 + 0x20) = 0;
        
          fVar5 = (float)iVar3;
        
          *(float *)(pcVar2 + 0x24) = (1.0f / (float)*(int *)(pcVar2 + 300)) * fVar5;
        
          *(float *)(pcVar2 + 0x60) = 1.0f;
        
          *(float *)(pcVar2 + 100) = (1.0f / (float)*(int *)(pcVar2 + 300)) * fVar5;
        
          *(u32 *)(pcVar2 + 0xa0) = 0;
        
          fVar6 = (float)(iVar3 + 1);
        
          *(float *)(pcVar2 + 0xa4) = (1.0f / (float)*(int *)(pcVar2 + 300)) * fVar6;
        
          *(float *)(pcVar2 + 0xe0) = 1.0f;
        
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

    else {

      uVar4 = 0xffffffff;

    }

  }

  else {

    uVar4 = 0;

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

#pragma push
#pragma opt_loop_invariants on
// FUN_00427670


u32 FUN_00427670(u32 param_3, u32 param_4, char param_5, u8 param_6,
                 float param_1, float param_2)
{
  u32 allocation;
  u32 result;
  int i;
  u8 *work;

  allocation = DAT_00960184_abs[0](1, 400, 0x40000);
  if (allocation == 0) {
    return 0;
  }

  result = FUN_00194b20_u32(param_3, DAT_006b4430, 0x18a7,
                           FUN_00426590, FUN_00427640, allocation);
  work = (u8 *)allocation;
  work[0] = 0;
  for (i = 0; i < 4; i++) {
    work[i * 4 + 0x111] = 0xff;
    work[i * 4 + 0x112] = 0xff;
    work[i * 4 + 0x110] = 0xff;
    work[i * 4 + 0x113] = 0xff;
    *(u32 *)(work + i * 8 + 0x158) = 0;
    *(u32 *)(work + i * 8 + 0x154) = 0;
  }
  *(float *)(work + 0x134) = 100.0f;
  *(float *)(work + 0x138) = 100.0f;
  if (param_5 >= 5) {
    *(float *)(work + 0x17c) = 0.015625f;
    *(float *)(work + 0x180) = 0.015625f;
    *(float *)(work + 0x178) = 0.578125f;
    *(float *)(work + 0x174) = 0.578125f;
    *(u32 *)(work + 0x12c) = 0x25;
    *(u32 *)(work + 0x128) = 0x25;
  }
  else {
    *(float *)(work + 0x17c) = 0.03125f;
    *(float *)(work + 0x180) = 0.03125f;
    *(float *)(work + 0x178) = 0.59375f;
    *(float *)(work + 0x174) = 0.59375f;
    *(u32 *)(work + 0x12c) = 0x13;
    *(u32 *)(work + 0x128) = 0x13;
  }
  *(float *)(work + 0x130) = 5.0f;
  *(float *)(work + 0x14c) = 1.0f;
  *(float *)(work + 0x174) = param_1;
  *(float *)(work + 0x178) = param_2;
  *(u32 *)(work + 0x13c) = param_4;
  work[0x140] = param_6;
  work[0x141] = 0;
  work[0x150] = 1;
  work[0x18c] = 0;
  return result;
}
#pragma pop

// FUN_00427830


u32
FUN_00427830(int param_2, u32 param_3, YajimaVec2 param_4, u32 param_5,
             float param_1, YajimaVec4 *param_6, YajimaVec4 *param_7, int param_8)
{
  int iVar1;
  u32 uVar2;
  u8 *puVar3;
  YajimaVec4 size;
  YajimaVec4 rect;

  size = *param_6;
  rect = *param_7;
  puVar3 = (u8 *)(*DAT_00960184_abs)(1, 400, 0x40000);
  if (puVar3 == 0) {
    return 0;
  }
  uVar2 = FUN_00194b80_u32(param_2, 0x106f, (u8 *)DAT_006b4400 + 0x40,
                           FUN_00426590, FUN_00427640, (u32)puVar3);
  *puVar3 = 0;
  for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
    u8 *entry = puVar3 + iVar1 * 4;
    *(YajimaColor *)(entry + 0x110) = *(YajimaColor *)&param_5;
    *(u32 *)(puVar3 + iVar1 * 8 + 0x158) = 0;
    *(u32 *)(puVar3 + iVar1 * 8 + 0x154) = 0;
  }
  *(YajimaVec2 *)(puVar3 + 0x134) = param_4;
  *(YajimaVec4 *)(puVar3 + 0x120) = rect;
  *(float *)(puVar3 + 0x130) = param_1;
  *(u32 *)(puVar3 + 0x13c) = param_3;
  puVar3[0x141] = param_8;
  *(float *)(puVar3 + 0x14c) = 1.0f;
  *(float *)(puVar3 + 0x144) =
      (1.0f / (float)*(s32 *)&size.z) * (float)*(s32 *)&rect.z;
  *(float *)(puVar3 + 0x148) =
      (1.0f / (float)*(s32 *)&size.w) * (float)*(s32 *)&rect.w;
  puVar3[0x150] = 0;
  puVar3[0x18c] = 0;
  return uVar2;
}

// FUN_00427A10


u32
FUN_00427a10(int param_2, u32 param_3, YajimaVec2 param_4, u32 param_5,
             float param_1, YajimaVec4 *param_6, YajimaVec4 *param_7, int param_8)
{
  int iVar1;
  u32 uVar2;
  u8 *puVar3;
  YajimaVec4 size;
  YajimaVec4 rect;

  size = *param_6;
  rect = *param_7;
  puVar3 = (u8 *)(*DAT_00960184_abs)(1, 400, 0x40000);
  if (puVar3 == 0) {
    return 0;
  }
  uVar2 = FUN_00194b20_u32(param_2, (u8 *)DAT_006b4400 + 0x40, 0x18a6,
                           FUN_00426590, FUN_00427640, (u32)puVar3);
  *puVar3 = 0;
  for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
    u8 *entry = puVar3 + iVar1 * 4;
    *(YajimaColor *)(entry + 0x110) = *(YajimaColor *)&param_5;
    *(u32 *)(puVar3 + iVar1 * 8 + 0x158) = 0;
    *(u32 *)(puVar3 + iVar1 * 8 + 0x154) = 0;
  }
  *(YajimaVec2 *)(puVar3 + 0x134) = param_4;
  *(YajimaVec4 *)(puVar3 + 0x120) = rect;
  *(float *)(puVar3 + 0x130) = param_1;
  *(u32 *)(puVar3 + 0x13c) = param_3;
  puVar3[0x141] = param_8;
  *(float *)(puVar3 + 0x14c) = 1.0f;
  *(float *)(puVar3 + 0x144) =
      (1.0f / (float)*(s32 *)&size.z) * (float)*(s32 *)&rect.z;
  *(float *)(puVar3 + 0x148) =
      (1.0f / (float)*(s32 *)&size.w) * (float)*(s32 *)&rect.w;
  puVar3[0x150] = 0;
  puVar3[0x18c] = 0;
  return uVar2;
}

// FUN_00427BF0


u32
FUN_00427bf0(u32 param_6, u32 param_7, YajimaVec2 param_8, u32 param_9,
             float param_1, float param_2, float param_3, float param_4,
             float param_5, YajimaVec4 *param_10)
{
  int iVar1;
  u32 uVar2;
  u8 *puVar3;
  YajimaVec4 rect;

  rect = *param_10;
  puVar3 = (u8 *)(*DAT_00960184_abs)(1, 400, 0x40000);
  if (puVar3 == 0) {
    return 0;
  }
  uVar2 = FUN_00194b20_u32(param_6, (u8 *)DAT_006b4400 + 0x40, 0x18a7,
                           FUN_00426590, FUN_00427640, (u32)puVar3);
  *puVar3 = 0;
  for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
    u8 *entry = puVar3 + iVar1 * 4;
    *(YajimaColor *)(entry + 0x110) = *(YajimaColor *)&param_9;
    *(u32 *)(puVar3 + iVar1 * 8 + 0x158) = 0;
    *(u32 *)(puVar3 + iVar1 * 8 + 0x154) = 0;
  }
  *(YajimaVec2 *)(puVar3 + 0x134) = param_8;
  *(YajimaVec4 *)(puVar3 + 0x120) = rect;
  *(float *)(puVar3 + 0x130) = param_1;
  *(u32 *)(puVar3 + 0x13c) = param_7;
  puVar3[0x141] = 3;
  *(float *)(puVar3 + 0x14c) = 1.0f;
  puVar3[0x150] = 1;
  *(float *)(puVar3 + 0x174) = param_4;
  *(float *)(puVar3 + 0x178) = param_5;
  *(float *)(puVar3 + 0x184) = param_2;
  *(float *)(puVar3 + 0x188) = param_3;
  puVar3[0x18c] = 0;
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

#define DAT_00960090 Yajima_setState

/* W327 measured: opt_loop_invariants on reduces normalized_diff 574 -> 566 (object 896/896 -> 872/896). */
#pragma opt_loop_invariants on
// FUN_00427E70 NONMATCHING


void FUN_00427e70(float depth, u32 color, float x, float y, int width, int height,
                  u32 *raster)
{
  YajimaVec16 vertices[4];
  float positions[4][2];
  code *Yajima_setState;
  int camera;
  int i;
  u32 red;
  u32 green;
  u32 blue;
  u32 alpha;
  float reciprocalZ;

  camera = kwlnGetMainCamera();
  reciprocalZ = 1.0f / *(float *)(camera + 0x80);
  alpha = ((color & 0xff000000) >> 24) & 0xff;
  blue = ((color & 0xff0000) >> 16) & 0xff;
  green = ((color & 0xff00) >> 8) & 0xff;
  red = color & 0xff;
  Yajima_setState = (code *)&DAT_00960090_abs;

  (*DAT_00960090)(6, 1);
  (*DAT_00960090)(7, 2);
  (*DAT_00960090)(8, 1);
  (*DAT_00960090)(9, 2);
  (*DAT_00960090)(0xc, 1);
  (*DAT_00960090)(0xb, 6);
  (*DAT_00960090)(10, 5);
  (*DAT_00960090)(2, 4);
  RpSkyRenderStateSet(2, 0x48);
  RpSkyRenderStateSet(3, 0x71801);

  positions[0][0] = x;
  positions[0][1] = y;
  positions[3][0] = x + (float)width;
  positions[3][1] = y + (float)height;
  positions[1][0] = x + (float)width;
  positions[1][1] = y;
  positions[2][0] = x;
  positions[2][1] = y + (float)height;

  for (i = 0; i < 4; i++) {
    vertices[i].lane[2] = *(float *)DAT_00960088_abs - depth;
    vertices[i].lane[6] = reciprocalZ;
    vertices[i].lane[8] = (float)alpha;
    vertices[i].lane[9] = (float)blue;
    vertices[i].lane[10] = (float)green;
    vertices[i].lane[11] = (float)red;
    vertices[i].lane[0] = positions[i][0];
    vertices[i].lane[1] = positions[i][1];
  }

  vertices[0].lane[4] = 0.0f;
  vertices[0].lane[5] = 0.0f;
  vertices[1].lane[4] = 1.0f;
  vertices[1].lane[5] = 0.0f;
  vertices[2].lane[4] = 0.0f;
  vertices[2].lane[5] = 1.0f;
  vertices[3].lane[4] = 1.0f;
  vertices[3].lane[5] = 1.0f;
  (*DAT_00960090)(1, *raster);
  (*(code *)DAT_009600a0_abs)(4, vertices, 4);
}
#pragma opt_loop_invariants reset

#undef DAT_00960090

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

  int lVar11;

  u32 uVar12;

  int iVar13;

  int lVar14;

  int iVar15;


  int iVar17;


  int iVar19;

  char *pcVar20;

  int lVar21;

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


  u8 auStack_80 [8];


  u32 uStack_68;

  u32 uStack_64;

  u32 uStack_60;

  u32 uStack_58;

  u32 uStack_54;

  u32 uStack_50;

  float fStack_40;

  float fStack_3c;
  float fStack_38;

  float fStack_34;

  u64 uStack_30;
  YajimaVec2 packedCoord;

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

  if (pcVar1[0x864] != '\0') {

    for (iVar15 = 0; iVar15 < 4; iVar15 = iVar15 + 1) {

      if (*(int *)(pcVar1 + iVar15 * 4 + 0x4c) != 0) {

        *(u8 *)(*(int *)(pcVar1 + iVar15 * 4 + 0x4c) + 0x18) = 0;

      }

    }

  }

  else {

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

        if (lVar14 != 1) {

          *pcVar1 = '\x0f';

        }

        else {

          *pcVar1 = '\x01';

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

    FUN_0042fd80((float *)&vec,param_1);
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

              if (*(char *)(iVar13 * 0x10 + iVar7 + 0x95c10e) != '\x01') {

                iVar7 = *(int *)(*piVar9 + 0x3c);

                for (iVar8 = 0; iVar8 < 4; iVar8 = iVar8 + 1) {

                  iVar10 = iVar7 + iVar8 * 4;

                  *(u8 *)(iVar10 + 0x110) = 0xff;

                  *(u8 *)(iVar10 + 0x112) = 0xff;

                  *(u8 *)(iVar10 + 0x111) = 0xff;

                  *(u8 *)(iVar10 + 0x113) = 0;

                }

              }

              else {

                iVar7 = *(int *)(*piVar9 + 0x3c);

                for (iVar8 = 0; iVar8 < 4; iVar8 = iVar8 + 1) {

                  iVar10 = iVar7 + iVar8 * 4;

                  *(u8 *)(iVar10 + 0x110) = 0xff;

                  *(u8 *)(iVar10 + 0x112) = 0xff;

                  *(u8 *)(iVar10 + 0x111) = 0xff;

                  *(u8 *)(iVar10 + 0x113) = 0xff;

                }

              }

              if (pcVar1[0x865] != '\0') {
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
              else {
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









          if (((DAT_007ce6c4 == '\x01') &&

              (iVar13 = K_Field_Get(), *(char *)(iVar13 + iVar22 + iVar23 + 0x4a) == '\b')) &&

             (iVar13 = K_Field_Get(), *(char *)(iVar13 + iVar22 + iVar23 + 0x49) == '\x01')) {

            FUN_00430270(auStack_a0,*(u32 *)(pcVar1 + 0xb1c));

            if (pcVar1[0x865] != '\0') {
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
              packedCoord.x = (float)(iVar13 >> 1) + fVar27 - 6.0f;

              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_0042a180((float)cVar6,(u32 *)(pcVar1 + 0x868));
              fVar27 = *(float *)(pcVar1 + 0x860) +
                       (float)(cVar6 * iVar15) + fVar24;
              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_0042a4a0((float)cVar6,(u32 *)(pcVar1 + 0xb10));
              fVar27 = fVar27 - fVar24 - (float)((int)cVar6 << 1);
              iVar13 = (int)cVar6;
              if (cVar6 < '\0') iVar13 = iVar13 + 1;
              packedCoord.y = (float)(iVar13 >> 1) + fVar27;
            }
            else {
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
              packedCoord.x = (float)(iVar13 >> 1) + fVar27 - 6.0f;

              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_00429fe0((float)cVar6,0);
              fVar27 = *(float *)(pcVar1 + 0x860) +
                       (float)(cVar6 * iVar15) + fVar24;
              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_0042a4a0((float)cVar6,(u32 *)(pcVar1 + 0xb10));
              fVar27 = fVar27 - fVar24 - (float)((int)cVar6 << 1);
              iVar13 = (int)cVar6;
              if (cVar6 < '\0') iVar13 = iVar13 + 1;
              packedCoord.y = (float)(iVar13 >> 1) + fVar27;
            }

            packedCoord.y = packedCoord.y - 6.0f;

            FUN_00430220(*(u32 *)(pcVar1 + 0xb1c),*(u64 *)&packedCoord);

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

// FUN_00429C60


void FUN_00429c60(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  for (iVar3 = 0; iVar3 < 9; iVar3 = iVar3 + 1) {

    iVar2 = iVar1 + iVar3 * 4 + 0x28;
    if (*(int *)iVar2 != 0) {
      FUN_004d0f00_arg(*(u32 *)iVar2);
      *(u32 *)iVar2 = 0;
    }


  }

  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

    iVar2 = iVar1 + iVar3 * 4 + 0x4c;
    if (*(int *)iVar2 != 0) {
      FUN_00115980_arg(*(u32 *)iVar2);
      *(u32 *)iVar2 = 0;
    }


  }

  DAT_0096017c_abs[0](*(u32 *)(param_1 + 0x3c));

  return;

}

// FUN_00429D40 NONMATCHING


u32 FUN_00429d40(u32 param_1,u64 param_2)



{

  u32 lVar1;

  u32 uVar2;


  short sVar3;
  u8 *puVar4;


  

  lVar1 = func_001ddd30();

  if (lVar1 == 0) {

    uVar2 = 0;

  }

  else {

    lVar1 = (*DAT_00960184_abs)(1,0xbb4,0x40000);

    if (lVar1 == 0) {

      uVar2 = 0;

    }

    else {

      uVar2 = kwlnTaskCreateWithAutoPriority(param_1,0x106f,DAT_006b4470_abs,FUN_004281f0,FUN_00429c60,lVar1);
      puVar4 = (u8 *)lVar1;

      *(YajimaVec2 *)(puVar4 + 0x85c) = *(YajimaVec2 *)&param_2;
      *puVar4 = 0;

      puVar4[0x9fe] = 0;

      puVar4[0x9ff] = 0;

      puVar4[0xb28] = 7;
      puVar4[0xb29] = 0x12;

      *(s16 *)(puVar4 + 0xb90) = -1;

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
  YajimaVec3 saved;
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
  base = (float)iVar1;
  grid = base * 800.0f;
  base = grid - 400.0f;
  delta = saved.x - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return (float)(int)(half + 0.0f - delta * ratio);
}

// FUN_00429FE0


float FUN_00429fe0(float param_1,char param_2)
{
  int iVar1;
  YajimaVec3 saved;
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
  base = (float)iVar1;
  grid = base * 800.0f;
  base = grid - 400.0f;
  delta = saved.z - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return (float)(int)(half + 0.0f - delta * ratio);
}

// FUN_0042A0D0


float FUN_0042a0d0(float param_1,float *param_2)
{
  int iVar1;
  YajimaVec3 pos = *(YajimaVec3 *)param_2;
  float grid;
  float base;
  float delta;
  float ratio;
  float half;

  iVar1 = FUN_0044f120(&pos);
  base = (float)iVar1;
  grid = base * 800.0f;
  base = grid - 400.0f;
  delta = pos.x - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return (float)(int)(half + 0.0f - delta * ratio);
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
  base = (float)iVar1;
  grid = base * 800.0f;
  base = grid - 400.0f;
  delta = pos.z - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return (float)(int)(half + 0.0f - delta * ratio);
}

// FUN_0042A230


float FUN_0042a230(float param_1,char param_2)
{
  int iVar1;
  YajimaVec3 saved;
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
  base = (float)iVar1;
  grid = base * 800.0f;
  base = grid - 400.0f;
  delta = saved.x - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return half + 0.0f - delta * ratio;
}

// FUN_0042A310


float FUN_0042a310(float param_1,char param_2)
{
  int iVar1;
  YajimaVec3 saved;
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
  base = (float)iVar1;
  grid = base * 800.0f;
  base = grid - 400.0f;
  delta = saved.z - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return half + 0.0f - delta * ratio;
}

// FUN_0042A3F0


float FUN_0042a3f0(float param_1,float *param_2)
{
  int iVar1;
  YajimaVec3 pos = *(YajimaVec3 *)param_2;
  float grid;
  float base;
  float delta;
  float ratio;
  float half;

  iVar1 = FUN_0044f120(&pos);
  base = (float)iVar1;
  grid = base * 800.0f;
  base = grid - 400.0f;
  delta = pos.x - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return half + 0.0f - delta * ratio;
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
  base = (float)iVar1;
  grid = base * 800.0f;
  base = grid - 400.0f;
  delta = pos.z - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return half + 0.0f - delta * ratio;
}

// FUN_0042A550 NONMATCHING


void FUN_0042a550(int param_1,u32 param_2,u32 param_3,u32 param_4)



{

  char cVar1;

  YRuntimeUnitRow *row;
  char cVar2;

  u32 uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int lVar7;

  char cVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  

  iVar5 = *(int *)(param_1 + 0x3c);

  uVar3 = FUN_00433810(param_3,param_4);

  cVar8 = (char)param_3;

  cVar1 = (char)param_4;

  if ((uVar3 & 0xff) != 0) {

    DAT_0095c110[uVar3 & 0xff] = 1;

  }

  else {

    DAT_0095c110[cVar1 * 0x10 + (int)cVar8] = 1;

  }

  iVar10 = cVar1 * 0x100;

  iVar11 = cVar8 * 0x10;

  iVar4 = K_Field_Get();

  iVar6 = (int)cVar8;

  if ((*(u8 *)(iVar4 + iVar10 + iVar11 + 0x53) & 8) != 0) {

    uVar3 = FUN_00433810(cVar8 + '\x01',param_4);

    if ((uVar3 & 0xff) != 0) {

      DAT_0095c110[uVar3 & 0xff] = 1;

    }

    else {

      *(u8 *)(cVar1 * 0x10 + iVar6 + 0x95c111) = 1;

    }

  }

  iVar4 = K_Field_Get();

  iVar9 = (int)cVar1;

  if ((*(u8 *)(iVar4 + iVar10 + iVar11 + 0x53) & 2) != 0) {

    uVar3 = FUN_00433810(cVar8 + -1,param_4);

    if ((uVar3 & 0xff) != 0) {

      DAT_0095c110[uVar3 & 0xff] = 1;

    }

    else {

      *(u8 *)(iVar9 * 0x10 + iVar6 + 0x95c10f) = 1;

    }

  }

  iVar4 = K_Field_Get();

  if ((*(u8 *)(iVar4 + iVar10 + iVar11 + 0x53) & 1) != 0) {

    uVar3 = FUN_00433810(param_3,cVar1 + -1);

    if ((uVar3 & 0xff) != 0) {

      DAT_0095c110[uVar3 & 0xff] = 1;

    }

    else {

      *(u8 *)((int)&DAT_0095c100 + iVar9 * 0x10 + iVar6) = 1;

    }

  }

  iVar4 = K_Field_Get();

  if ((*(u8 *)(iVar4 + iVar10 + iVar11 + 0x53) & 4) != 0) {

    uVar3 = FUN_00433810(param_3,cVar1 + '\x01');

    if ((uVar3 & 0xff) != 0) {

      DAT_0095c110[uVar3 & 0xff] = 1;

    }

    else {

      *(u8 *)(iVar9 * 0x10 + iVar6 + 0x95c120) = 1;

    }

  }

  cVar8 = (char)param_2;

  if (cVar8 != '\0') {
    row = (YRuntimeUnitRow *)&DAT_008717a0 + cVar8;

    cVar1 = FUN_00435260(param_2);

    if (cVar1 == '\0') {

      cVar1 = FUN_004353f0(row);

      if (((cVar1 != '\x01') && (cGpffffb9d8 == '\0')) &&

         (DAT_0095c110[*(char *)(iVar5 + 0xb09) * 0x10 + (int)*(char *)(iVar5 + 0xb08)] == '\x01'

         )) {

        FUN_00456490(param_2);

        cGpffffb9d8 = '\x01';

      }

      if (cGpffffb9d4 == '\0') {

        cVar1 = *(char *)(iVar5 + 0xb0b);

        cVar2 = K_FldFrame_CtlGetXGrid(*(u32 *)((u8 *)row->unk_054 + 0x1e0));

        if ((cVar1 == cVar2) &&

           (cVar1 = *(char *)(iVar5 + 0xb0c),

           cVar2 = K_FldFrame_CtlGetZGrid(*(u32 *)((u8 *)row->unk_054 + 0x1e0)),

           cVar1 == cVar2)) {

          lVar7 = FUN_0043c730(param_2);

          if (lVar7 == 1) {

            cVar8 = FUN_004353f0(row);

            if (cVar8 != '\x01') {

              FUN_00456450(param_2);

            }

            cGpffffb9d4 = '\x01';

          }

        }

        else {

          iVar5 = K_FldFrame_CtlGetZGrid(*(u32 *)((u8 *)row->unk_054 + 0x1e0));

          iVar4 = K_Field_Get();

          iVar6 = K_FldFrame_CtlGetXGrid(*(u32 *)((u8 *)row->unk_054 + 0x1e0));

          if (*(char *)(iVar4 + iVar5 * 0x100 + iVar6 * 0x10 + 0x4a) == '\b') {

            cGpffffb9d4 = '\x01';

          }

        }

      }

    }

  }

  else {

    lVar7 = FUN_004352e0();

    if (((lVar7 == 0) && (cGpffffb9d8 == '\0')) &&

       (DAT_0095c110[*(char *)(iVar5 + 0xb09) * 0x10 + (int)*(char *)(iVar5 + 0xb08)] == '\x01'))

    {

      cGpffffb9d8 = '\x01';

    }

  }

  return;

}

// FUN_0042AA40 NONMATCHING


u8 FUN_0042aa40(int param_1, u32 param_2, u32 param_3)
{
  struct FileEntry {
    int count;
    int category;
    u16 primary;
    u16 secondary;
    u8 padding[0x1c];
  };
  int work;
  char group;
  struct FileEntry *table;
  int i;
  short selected;
  char category;
  char result;
  int clearIndex;
  u32 request;

  work = *(int *)(param_1 + 0x3c);
  group = (char)param_2 - 0x1f;
  for (i = 0; i < 10; i++) {
    *(short *)(work + i * 2 + 0xb7c) = -1;
  }
  *(short *)(work + 0xb90) = -1;

  table = (struct FileEntry *)(iGpffffb5c0 +
      (((group * 0xf0 + group) * 4)));
  for (i = 0; i < table->count; i++) {
    if ((param_2 == table[i].primary) &&
        (param_3 == table[i].secondary)) {
      *(short *)(work + 0xb90) = i;
    }
  }
  selected = *(short *)(work + 0xb90);
  if (selected == -1) {
    return 0;
  }

  category = *(char *)&table[selected].category;
  result = 0;
  for (i = 0; i < table->count; i++) {
    if (category == table[i].category) {
      for (clearIndex = 0; clearIndex < 0xff; clearIndex++) {
        DAT_0095bee0_abs[clearIndex] = 0;
      }
      *(short *)(work + result * 2 + 0xb7c) = i;
      sprintf(DAT_0095bee0_abs, DAT_006b4490, param_2,
              table[i].secondary);
      request = H_Cdvd_Request(DAT_0095bee0_abs, 0);
      *(u32 *)(work + result * 4 + 4) = request;
      result++;
    }
  }
  return result;
}

// FUN_0042AC60 NONMATCHING


void FUN_0042ac60(int param_1,int param_2)
{
  int iVar1;
  int cVar2;
  u32 uVar3;
  int *piVar4;
  u8 *puVar5;
  int iVar5;
  int iVar6;
  int iVar8;
  int iVar7;

  iVar1 = *(int *)(param_1 + 0x3c);
  cVar2 = (s8)(param_2 - 0x1f);
  iVar6 = (cVar2 * 0xf0 + (int)cVar2) * 4;
  piVar4 = (int *)(iVar6 + iGpffffb5c0);
  cVar2 = *(char *)((int)piVar4 + *(short *)(iVar1 + 0xb90) * 0x28 + 4);
  iVar8 = 0;
  iVar7 = 0;
  for (; iVar8 < *(int *)(iVar6 + iGpffffb5c0); ) {
    piVar4 = (int *)(iVar6 + iGpffffb5c0 + iVar8 * 0x28);
    if (cVar2 == piVar4[1]) {
      iVar5 = 0;
      puVar5 = DAT_0095bfe0_abs;
      for (; iVar5 < 0xff; iVar5 = iVar5 + 1) {
        puVar5[iVar5] = 0;
      }
      sprintf(DAT_0095bfe0_abs,DAT_006b44b0,param_2,*(u16 *)((int)piVar4 + 10));
      uVar3 = FUN_004d1260(DAT_0095bfe0_abs,0);
      *(u32 *)(iVar1 + iVar7 * 4 + 0x28) = uVar3;
      iVar7 = iVar7 + 1;
    }
    iVar8 = iVar8 + 1;
  }
  return;
}

// FUN_0042ADB0 NONMATCHING


void FUN_0042adb0(int param_1)



{

  int iVar1;

  u32 *puVar2;

  u32 uVar3;

  int iVar4;

  long lVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  YajimaVec3 posCamera;

  YajimaVec3 transformed;

  YajimaVec3 delta;

  YajimaVec3 posTarget;
  YajimaVec4 rotScratch;

  u32 uStack_20;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_8;

  float fStack_4;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  K_FldFrame_CtlCopyPos(&posCamera,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

  posTarget = posCamera;



  ((u32 *)&rotScratch)[0] = DAT_006b44c0;

  ((u32 *)&rotScratch)[1] = 0;

  ((u32 *)&rotScratch)[2] = DAT_006b44c8;

  if (*(char *)(iVar1 + 0x865) == '\x01') {

    posTarget = *(YajimaVec3 *)(iVar1 + 0x868);



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

  FUN_004c31b0_ymisc((void *)uVar3,(const void *)&rotScratch,
                 *(float *)(*(short *)(iVar1 + 0xb90) * 0x28 +
                            *piGpffffa850 * 0x3c4 + iGpffffb5c0 - 0x74a0),2);

  delta.x = *(float *)(iVar1 + 0xba4) - posTarget.x;

  delta.y = *(float *)(iVar1 + 0xba8) - posTarget.y;

  delta.z = *(float *)(iVar1 + 0xbac) - posTarget.z;

  FUN_004c6be0_ymisc((float *)&transformed,(const float *)&delta,uVar3);

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

               ((63.0f - (((fVar6 - transformed.x) - fVar8) * 2.25f) / 100.0f) - fVar9);

    fStack_4 = *(float *)(iVar4 + 0xb30) +

               ((63.0f - (((fVar7 - transformed.z) - fVar10) * 2.25f) / 100.0f) - fVar11);

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
  YRuntimeUnitRow *row;

  int iVar4;

  u32 uVar5;

  u32 uVar6;

  int iVar7;

  float fVar8;


  float fVar10;

  float fVar11;

  float fVar12;

  float fStack_50;

  u32 uStack_4c;

  float fStack_48;

  float afStack_40 [4];

  u64 uStack_30;


  float afStack_20 [2];
  float fStack_18;

  float fStack_10;


  float fStack_8;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  K_FldFrame_CtlCopyPos(&fStack_50,*(u32 *)(DAT_008717f4 + 0x1e0));

  fStack_10 = fStack_50;


  fStack_8 = fStack_48;

  uStack_30 = DAT_006b44d0;


  if (*(char *)(iVar1 + 0x865) == '\x01') {

    fStack_10 = *(float *)(iVar1 + 0x868);


    fStack_8 = *(float *)(iVar1 + 0x870);

  }


  for (iVar7 = 1; iVar7 < 4; iVar7 = iVar7 + 1) {
    row = (YRuntimeUnitRow *)&DAT_008717a0 + iVar7;

    bVar2 = 0;

    if ((row->unk_048 != 0) && (row->unk_054 != 0)) {

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

      K_FldFrame_CtlCopyPos(afStack_20,*(u32 *)((u8 *)row->unk_054 + 0x1e0));

      FUN_004c31b0_ymisc((void *)uVar5,(const void *)&uStack_30,
                     *(float *)(iGpffffb5c0 + *piGpffffa850 * 0x3c4 +
                                *(short *)(iVar1 + 0xb90) * 0x28 - 0x74a0),2);

      iVar4 = iGpffffb5c0 + *piGpffffa850 * 0x3c4 + *(short *)(iVar1 + 0xb90) * 0x28;

      fVar11 = 63.0f - ((((*(float *)(iVar1 + 0xba4) - (*(float *)(iVar4 + -0x749c) - afStack_20[0]))

                        * 2.25f) / 100.0f) * 2.25f) / 100.0f;

      fVar12 = 63.0f - ((((*(float *)(iVar1 + 0xbac) - (*(float *)(iVar4 + -0x7494) - fStack_18)) *

                        2.25f) / 100.0f) * 2.25f) / 100.0f;

      afStack_40[0] = ((afStack_20[0] - fStack_10) * 2.25f) / 100.0f;
      afStack_40[2] = ((fStack_18 - fStack_8) * 2.25f) / 100.0f;

      afStack_40[1] = 0.0f;

      FUN_004c6be0_ymisc(afStack_40,afStack_40,uVar5);

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
  YRuntimeUnitRow *row;

  u32 uVar4;

  u32 uVar5;

  int iVar6;

  int iVar7;

  float fVar8;

  float fVar10;

  float fVar11;

  float fVar12;

  float fStack_50;

  u32 uStack_4c;

  float fStack_48;

  float afStack_40 [4];

  u64 uStack_30;


  float afStack_20 [2];

  float fStack_18;

  float fStack_10;


  float fStack_8;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  K_FldFrame_CtlCopyPos(&fStack_50,*(u32 *)(DAT_008717f4 + 0x1e0));

  fStack_10 = fStack_50;


  fStack_8 = fStack_48;

  uStack_30 = DAT_006b44e0;


  if (*(char *)(iVar1 + 0x865) == '\x01') {

    fStack_10 = *(float *)(iVar1 + 0x868);


    fStack_8 = *(float *)(iVar1 + 0x870);

  }

  for (iVar7 = 0; iVar7 < 0x18; iVar7 = iVar7 + 1) {

    bVar2 = 0;

    row = (YRuntimeUnitRow *)DAT_0086e6a0 + iVar7 + 4;
    if ((row->unk_048 != 0) && (row->unk_054 != 0)) {

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

      K_FldFrame_CtlCopyPos(afStack_20,*(u32 *)((u8 *)row->unk_054 + 0x1e0));

      FUN_004c31b0_ymisc((void *)uVar4,(const void *)&uStack_30,
                     *(float *)(iGpffffb5c0 + *piGpffffa850 * 0x3c4 +
                                *(short *)(iVar1 + 0xb90) * 0x28 - 0x74a0),2);

      iVar6 = iGpffffb5c0 + *piGpffffa850 * 0x3c4 + *(short *)(iVar1 + 0xb90) * 0x28;

      fVar11 = 63.0f - ((((*(float *)(iVar1 + 0xba4) - (*(float *)(iVar6 + -0x749c) - afStack_20[0]))

                        * 2.25f) / 100.0f) * 2.25f) / 100.0f;

      fVar12 = 63.0f - ((((*(float *)(iVar1 + 0xbac) - (*(float *)(iVar6 + -0x7494) - fStack_18)) *

                        2.25f) / 100.0f) * 2.25f) / 100.0f;

      afStack_40[0] = ((afStack_20[0] - fStack_10) * 2.25f) / 100.0f;

      afStack_40[2] = ((fStack_18 - fStack_8) * 2.25f) / 100.0f;

      afStack_40[1] = 0.0f;

      FUN_004c6be0_ymisc(afStack_40,afStack_40,uVar4);

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


void FUN_0042ba50(u32 param_1)



{

  int iVar1;
  int *piVar2;

  u32 uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int lVar8;

  float fVar9;

  float fVar10;

  YajimaVec4 result;

  int iStack_18;

  int iStack_14;

  YajimaColor color;

  

  iVar1 = *(int *)((int)param_1 + 0x3c);

  lVar8 = 0;

  while (lVar8 < *(char *)(iVar1 + 0xb2a)) {

    iVar7 = lVar8;

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

    color.a = 0xff;
    color.g = 0xff;
    color.b = 0xff;
    color.r = 0xff;

    iVar5 = iGpffffb5c0 + *piGpffffa850 * 0x3c4 + *(short *)(iVar4 + 0xb7c) * 0x28;

    fVar10 = *(float *)(iVar5 + -0x74ac);

    fVar9 = *(float *)(iVar5 + -0x74b0);

    uVar3 = FUN_00427bf0(param_1, (u32)piVar2, *(YajimaVec2 *)(iVar6 + 0xb2c),
                         *(u32 *)&color, 5.0f, fVar9, fVar10,
                         fVar9 / (float)iStack_18, fVar10 / (float)iStack_14,
                         &result);

    *(u32 *)(iVar6 + 0x5c) = uVar3;

    lVar8 = iVar7 + 1;

  }

  return;

}

/* W327 measured: opt_common_subs off reduces normalized_diff 240 -> 218 (object 360/368 -> 364/368). */
#pragma opt_common_subs off
// FUN_0042BC10 NONMATCHING


void FUN_0042bc10(int param_1)



{

  int iVar1;

  u32 uVar2;

  long lVar3;

  float fStack_8;

  float fStack_4;

  

  iVar1 = *(int *)((int)param_1 + 0x3c);

  if (*(u32 *)DAT_008717e8_abs != 0) {

    if (*(int *)(iVar1 + 0x898) != 0) {

      *(u32 *)(iVar1 + 0x898) = 0;

    }

    FUN_00423fe0(&fStack_8,0,0x7e,0x7e,0x20,0x20);

    *(float *)(iVar1 + 0x89c) = *(float *)(iVar1 + 0x85c) + fStack_8;

    uVar2 = FUN_004560d0_typed(param_1,*(float *)(iVar1 + 0x89c),
                               *(float *)(iVar1 + 0x8a0),1.0f,0x20,0x20);


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
#pragma opt_common_subs reset

/* W212: first divergence is the prologue (ours 0xc0-byte frame, retail 0xb0),
 * followed by different nested-loop induction lifetimes.  FUN_0042fd80 has a
 * grid scan but no per-cell allocation/update body, so its template is not transferable. */
// FUN_0042BD80 NONMATCHING


void FUN_0042bd80(int param_1)



{

  u8 uVar1;

  u8 bVar2;

  u8 *work;

  int iVar4;

  int *piVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  u8 *row;

  

  work = *(u8 **)((int)param_1 + 0x3c);

  for (iVar7 = 0; iVar7 < 0x10; iVar7 = iVar7 + 1) {

    iVar6 = iVar7 * 0x100;

    row = work + iVar7 * 0x80;

    for (iVar8 = 0; iVar8 < 0x10; iVar8 = iVar8 + 1) {

      iVar4 = K_Field_Get();

      if (*(char *)(iVar6 + iVar4 + iVar8 * 0x10 + 0x48) == '\x01') {

        iVar4 = K_Field_Get();

        if (*(char *)(iVar6 + iVar4 + iVar8 * 0x10 + 0x49) == '\x01') {

          piVar5 = (int *)(row + iVar8 * 8 + 0x5c);

          if (*piVar5 != 0) {

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

            iVar4 = FUN_00427670_typed(0.625f,0.625f,param_1,(&DAT_0095c0e0)[bVar2],uVar1,

                                 *(u8 *)(iVar6 + iVar4 + iVar9 + 0x4e));

            *piVar5 = iVar4;

          }

          else {

            iVar4 = K_Field_Get();

            bVar2 = *(u8 *)(iVar6 + iVar4 + iVar9 + 0x4a);

            iVar4 = K_Field_Get();

            uVar1 = *(u8 *)(iVar6 + iVar4 + iVar9 + 0x4a);

            iVar4 = K_Field_Get();

            iVar4 = FUN_00427670_typed(0.59375f,0.59375f,param_1,(&DAT_0095c0e0)[bVar2],uVar1,

                                 *(u8 *)(iVar6 + iVar4 + iVar9 + 0x4e));

            *piVar5 = iVar4;

          }

          *(u8 *)(*(int *)(*piVar5 + 0x3c) + 0x150) = 1;

          *(u8 *)(row + iVar8 * 8 + 0x60) = 0;

        }

      }

    }

  }

  return;

}

// FUN_0042BFD0


void FUN_0042bfd0(int param_1)



{

  char *iVar1;
  int ready;
  u32 oldHandle;

  u32 uVar2;

  YajimaVec2 offset;

  

  iVar1 = *(char **)((int)param_1 + 0x3c);
  ready = *(u32 *)DAT_008717e8_abs != 0;
  if (ready) {
    ready = *(u32 *)DAT_008717f4_abs != 0;
  }
  if (ready) {

    oldHandle = *(u32 *)(iVar1 + 0x898);
    if (oldHandle != 0) {

      *(u32 *)(iVar1 + 0x898) = 0;

    }

    FUN_00423fe0_vec2(&offset,0,0x7e,0x7e,0x20,0x20);

    *(float *)(iVar1 + 0x89c) = *(float *)(iVar1 + 0x85c) + offset.x;
    *(float *)(iVar1 + 0x8a0) = *(float *)(iVar1 + 0x860) + offset.y;
    uVar2 = FUN_004560d0_typed(param_1,*(float *)(iVar1 + 0x89c),
                               *(float *)(iVar1 + 0x8a0),1.0f,0x20,0x20);
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

  u32 uVar9;

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
  YRuntimeUnitRow *row;
  float *paramSlot;



  iVar10 = *(int *)(param_1 + 0x3c);
  paramSlot = (float *)(iVar10 + (int)param_2 * 8 + 0x8b8);

  bVar11 = 0;

  iVar7 = (int)param_2;
  row = &DAT_008717a0_unit_rows[iVar7];

  if ((row->unk_048 != 0) && (row->unk_054 != 0)) {

    bVar11 = 1;

  }

  if (bVar11) {

    sVar4 = K_FldFrame_CtlGetXGrid(*(u32 *)((u8 *)row->unk_054 + 0x1e0));

    if ((param_3 == sVar4) &&

       (sVar4 = K_FldFrame_CtlGetZGrid(*(u32 *)((u8 *)row->unk_054 + 0x1e0)),

       param_4 == sVar4)) {

      if (*(char *)(iVar10 + 0x865) == '\0') {
        YajimaVec3 savedMain;

        YajimaVec3 posMain;

        YajimaVec3 savedObj;

        YajimaVec3 posObj;


        cVar1 = *(char *)(iVar10 + 0xb29);
        K_FldFrame_CtlCopyPos(&posMain,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

        savedMain = *(YajimaVec3 *)&posMain;

        iVar5 = K_FldFrame_CtlGetXGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

        fVar17 = savedMain.x - ((float)iVar5 * 800.0f - 400.0f);

        uVar18 = 0x40000000;

        cVar2 = *(char *)(iVar10 + 0xb29);

        piVar12 = DAT_008717f4 + param_2 * 0x70;

        K_FldFrame_CtlCopyPos(&posObj,*(u32 *)(*piVar12 + 0x1e0));

        savedObj = *(YajimaVec3 *)&posObj;

        iVar6 = K_FldFrame_CtlGetXGrid(*(u32 *)(*piVar12 + 0x1e0));

        cVar3 = *(char *)(iVar10 + 0xb29);

        pfVar15 = paramSlot;

        iVar5 = (int)cVar3;

        if (cVar3 < '\0') {

          iVar5 = iVar5 + 1;

        }

        *pfVar15 = ((float)(iVar5 >> 1) +

                   ((((*(float *)(iVar10 + 0x85c) + (float)(cVar3 * param_5)) -

                     (float)(int)(((float)(int)cVar2 / 2.0f + 0.0f) -

                                 (savedObj.x - ((float)iVar6 * 800.0f - 400.0f)) *

                                 ((float)(int)cVar2 / 800.0f))) +

                    (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -

                                fVar17 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar3 << 1)))

                   - 8.0f;

        cVar1 = *(char *)(iVar10 + 0xb29);

        K_FldFrame_CtlCopyPos(&posMain,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

        savedMain = *(YajimaVec3 *)&posMain;

        iVar5 = K_FldFrame_CtlGetZGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

        fVar17 = savedMain.z - ((float)iVar5 * 800.0f - 400.0f);

        fVar19 = (float)(int)*(char *)(iVar10 + 0xb29);

        K_FldFrame_CtlCopyPos(&posObj,*(u32 *)(*piVar12 + 0x1e0));

        savedObj = *(YajimaVec3 *)&posObj;

        iVar6 = K_FldFrame_CtlGetZGrid(*(u32 *)(*piVar12 + 0x1e0));

        cVar2 = *(char *)(iVar10 + 0xb29);

        pfVar13 = paramSlot + 1;

        iVar5 = (int)cVar2;

        if (cVar2 < '\0') {

          iVar5 = iVar5 + 1;

        }

        *pfVar13 = ((float)(iVar5 >> 1) +

                   ((((*(float *)(iVar10 + 0x860) + (float)(cVar2 * param_6)) -

                     (float)(int)((fVar19 / 2.0f + 0.0f) -

                                 (savedObj.z - ((float)iVar6 * 800.0f - 400.0f)) *

                                 (fVar19 / 800.0f))) +

                    (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -

                                fVar17 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar2 << 1)))

                   - 8.0f;

      }

      else {
        YajimaVec3 savedObj1;

        YajimaVec3 posObj1;

        YajimaVec3 worldPos1;

        YajimaVec3 savedObj2;

        YajimaVec3 posObj2;

        YajimaVec3 worldPos2;

        cVar1 = *(char *)(iVar10 + 0xb29);

        worldPos1 = *(YajimaVec3 *)(iVar10 + 0x868);

        iVar5 = FUN_0044f120(&worldPos1);

        fVar17 = worldPos1.x - ((float)iVar5 * 800.0f - 400.0f);

        uVar18 = 0x40000000;

        cVar2 = *(char *)(iVar10 + 0xb29);

        piVar12 = DAT_008717f4 + param_2 * 0x70;

        K_FldFrame_CtlCopyPos(&posObj1,*(u32 *)(*piVar12 + 0x1e0));

        savedObj1 = *(YajimaVec3 *)&posObj1;

        iVar6 = K_FldFrame_CtlGetXGrid(*(u32 *)(*piVar12 + 0x1e0));

        cVar3 = *(char *)(iVar10 + 0xb29);

        pfVar15 = paramSlot;

        iVar5 = (int)cVar3;

        if (cVar3 < '\0') {

          iVar5 = iVar5 + 1;

        }

        *pfVar15 = ((float)(iVar5 >> 1) +

                   ((((*(float *)(iVar10 + 0x85c) + (float)(cVar3 * param_5)) -

                     (float)(int)(((float)(int)cVar2 / 2.0f + 0.0f) -

                                 (savedObj1.x - ((float)iVar6 * 800.0f - 400.0f)) *

                                 ((float)(int)cVar2 / 800.0f))) +

                    (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -

                                fVar17 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar3 << 1)))

                   - 8.0f;

        cVar1 = *(char *)(iVar10 + 0xb29);

        worldPos2 = *(YajimaVec3 *)(iVar10 + 0x868);

        iVar5 = FUN_0044f170(&worldPos2);

        fVar17 = worldPos2.z - ((float)iVar5 * 800.0f - 400.0f);

        fVar19 = (float)(int)*(char *)(iVar10 + 0xb29);

        K_FldFrame_CtlCopyPos(&posObj2,*(u32 *)(*piVar12 + 0x1e0));

        savedObj2 = *(YajimaVec3 *)&posObj2;

        iVar6 = K_FldFrame_CtlGetZGrid(*(u32 *)(*piVar12 + 0x1e0));

        cVar2 = *(char *)(iVar10 + 0xb29);

        pfVar13 = paramSlot + 1;

        iVar5 = (int)cVar2;

        if (cVar2 < '\0') {

          iVar5 = iVar5 + 1;

        }

        *pfVar13 = ((float)(iVar5 >> 1) +

                   ((((*(float *)(iVar10 + 0x860) + (float)(cVar2 * param_6)) -

                     (float)(int)((fVar19 / 2.0f + 0.0f) -

                                 (savedObj2.z - ((float)iVar6 * 800.0f - 400.0f)) *

                                 (fVar19 / 800.0f))) +

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
          if ((uVar8 & 0x80) != 0) {
            iVar7 = param_2 * 2 + iVar10;
            psVar14 = (short *)(iVar7 + 0x930);
            fVar17 = (float)sinf(DAT_007cb134 * (float)(int)*psVar14);
            fVar17 = fVar17 * -128.0f + 128.0f;
            sVar4 = *psVar14;
            *psVar14 = sVar4 + 1;
            if (0x28 < (short)(sVar4 + 1)) {
              *psVar14 = 0;
            }
            uVar9 = FUN_001158b0(0,DAT_007ce6e4,10);
            iVar7 = (int)uVar9;
            *(u32 *)(iVar7 + 0x2c) = 0x40400000;
            *(float *)(iVar7 + 0x10) = paramSlot[0] + 3.0f;
            *(float *)(iVar7 + 0x14) = paramSlot[1] + 3.0f;
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
          else {
            uVar8 = datGetBadStatusNoDown(*(u16 *)(&DAT_00871948 + iVar7 * 0x1c0));
            if ((uVar8 & 0x80000) != 0) {
              iVar7 = param_2 * 2 + iVar10;
              psVar14 = (short *)(iVar7 + 0x930);
              fVar17 = (float)sinf(DAT_007cb134 * (float)(int)*psVar14);
              fVar17 = fVar17 * -128.0f + 128.0f;
              sVar4 = *psVar14;
              *psVar14 = sVar4 + 1;
              if (0x28 < (short)(sVar4 + 1)) {
                *psVar14 = 0;
              }
              uVar9 = FUN_001158b0(0,DAT_007ce6e4,10);
              iVar7 = (int)uVar9;
              *(u32 *)(iVar7 + 0x2c) = 0x40400000;
              *(float *)(iVar7 + 0x10) = paramSlot[0] + 3.0f;
              *(float *)(iVar7 + 0x14) = paramSlot[1] + 3.0f;
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
            else {
              uVar9 = FUN_001158b0(0,DAT_007ce6e4,7);
              iVar10 = (int)uVar9;
              *(u32 *)(iVar10 + 0x2c) = uVar18;
              *(float *)(iVar10 + 0x10) = *pfVar15;
              *(float *)(iVar10 + 0x14) = *pfVar13;
              *(u8 *)(iVar10 + 0x18) = 0;
              func_001127d0(uVar9,1);
              FUN_00115980(uVar9);
            }
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
  u8 *work;
  YajimaPackedRow *row;
  YajimaPackedEntry *entry;
  s8 *counter;
  s8 *delay;
  s16 *offsetX;
  s16 *offsetY;
  u32 random;
  s8 count;
  s32 outer;
  s32 inner;
  s32 end;

  work = *(u8 **)(param_1 + 0x3c);
  for (outer = 0; outer < 3; outer++) {
    if ((*(s8 *)(work + outer + 0x938) == 1) &&
        (FUN_0043a230((s8)(outer + 1)) == 1)) {
      inner = outer * 5;
      row = (YajimaPackedRow *)(work + outer * 8);
      end = (outer + 1) * 5;
      for (; inner < end; inner++) {
        entry = (YajimaPackedEntry *)(work + inner);
        counter = &entry->counter;
        offsetY = (s16 *)(work + inner * 2 + 0x914);
        offsetX = (s16 *)(work + inner * 2 + 0x8f6);
        FUN_00430780(8.0f, row->value,
                     *(s8 *)offsetX, *(s8 *)offsetY, entry->counter);
        delay = &entry->delay;
        if (entry->delay < 1) {
          count = entry->counter + 1;
          entry->counter = count;
          if (count > 20) {
            random = FUN_00488f30();
            *offsetX = (s16)(8.0f - (f32)(random & 0xf));
            random = FUN_00488f30();
            *offsetY = (s16)(8.0f - (f32)(random & 0xf));
            *counter = 0;
            *delay = 4;
          }
        }
        else {
          (*delay)--;
        }
        }
      }
    }
  }

/* W327 measured: opt_loop_invariants on reduces normalized_diff 2541 -> 2533 (object 3304/3536 -> 3328/3536). */
#pragma opt_loop_invariants on
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

  int lVar8;

  u32 uVar9;

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
  YajimaVec3 savedMain0;
  YajimaVec3 posObj0;
  YajimaVec3 savedObj0;
  YajimaVec3 worldPos1;
  YajimaVec3 posObj1;
  YajimaVec3 savedObj1;
  YajimaVec3 worldPos2;
  YajimaVec3 posObj2;
  YajimaVec3 savedObj2;
  YajimaVec3 posObj3;
  YajimaVec3 savedObj3;
  YajimaVec3 posMain3;
  YajimaVec3 savedMain3;
  YajimaVec3 posObj4;
  YajimaVec3 savedObj4;
  YajimaVec3 posMain4;
  YajimaVec3 savedMain4;

  iVar4 = *(int *)(param_1 + 0x3c);

  for (iVar15 = 0; iVar15 < 0x18; iVar15 = iVar15 + 1) {

    iVar10 = (iVar15 * 7) << 6;

    if ((*(int *)(DAT_0086eda0_abs + iVar10 + 0x48) != 0) &&
        (*(int *)(DAT_0086eda0_abs + iVar10 + 0x54) != 0)) {

      lVar8 = K_FldFrame_CtlGetXGrid(*(u32 *)(*(int *)(DAT_0086eda0_abs + iVar10 + 0x54) + 0x1e0));

      if (((short)param_2 == lVar8) &&
         (lVar8 = K_FldFrame_CtlGetZGrid(*(u32 *)(*(int *)(DAT_0086eda0_abs + iVar10 + 0x54) + 0x1e0)),
         (short)param_3 == lVar8)) {

        cVar3 = (char)iVar15;

        if (*(char *)(iVar4 + 0x865) == '\0') {

          cVar1 = *(char *)(iVar4 + 0xb29);

          K_FldFrame_CtlCopyPos(&posMain0,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          savedMain0 = posMain0;

          iVar6 = K_FldFrame_CtlGetXGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

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

          K_FldFrame_CtlCopyPos(&posMain0,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          savedMain0 = posMain0;

          iVar6 = K_FldFrame_CtlGetZGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

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

          K_FldFrame_CtlCopyPos(&posMain3,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          savedMain3 = posMain3;

          iVar6 = K_FldFrame_CtlGetXGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

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

          K_FldFrame_CtlCopyPos(&posMain4,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          savedMain4 = posMain4;

          iVar6 = K_FldFrame_CtlGetZGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

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
#pragma opt_loop_invariants reset

/*
 * The retail routine keeps collision positions as contiguous three-float
 * temporaries before deriving grid coordinates and distance checks.
 * Reconstruct those aggregate copies here so all vector components remain
 * live across helper calls instead of being eliminated as unrelated scalars.
 */
// FUN_0042DD90 NONMATCHING


void FUN_0042dd90(int param_1,short param_2,u16 param_3,int param_4,int param_5)



{

  char cVar1;

  int iVar2;

  char cVar3;


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

      lVar8 = FUN_0044f120(&DAT_0086be04 + iVar15 * 0x10);

      if (((short)param_2 == lVar8) &&

         (lVar8 = FUN_0044f170(&DAT_0086be04 + iVar15 * 0x10),

         (short)param_3 == lVar8)) {

        if (*(char *)(iVar2 + 0x865) == '\0') {
          YajimaVec3 savedMain;
          YajimaVec3 posMain;
          YajimaVec3 worldPos1;
          YajimaVec3 worldPos2;




          cVar3 = *(char *)(iVar2 + 0xb29);

          K_FldFrame_CtlCopyPos(&posMain,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          savedMain = *(YajimaVec3 *)&posMain;



          iVar5 = K_FldFrame_CtlGetXGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          fVar17 = savedMain.x - ((float)iVar5 * 800.0f - 400.0f);



          fVar18 = (float)(int)*(char *)(iVar2 + 0xb29);

          iVar10 = iVar15 * 0x10;

          pfVar14 = (float *)(&DAT_0086be04 + iVar10);

          worldPos1 = *(YajimaVec3 *)(&DAT_0086be04 + iVar10);

          iVar6 = FUN_0044f120(&worldPos1);


          cVar1 = *(char *)(iVar2 + 0xb29);

          iVar11 = (int)cVar1;

          iVar5 = iVar11;

          if (cVar1 < '\0') {

            iVar5 = iVar11 + 1;

          }

          fVar18 = ((float)(iVar5 >> 1) +

                   ((((*(float *)(iVar2 + 0x85c) + (float)(cVar1 * param_4)) -

                     ((fVar18 / 2.0f + 0.0f) -

                     (worldPos1.x - ((float)iVar6 * 800.0f - 400.0f)) * (fVar18 / 800.0f))) +


                    (float)(int)(((float)(int)cVar3 / 2.0f + 0.0f) -

                                fVar17 * ((float)(int)cVar3 / 800.0f))) - (float)((int)cVar1 << 1)))

                   - 8.0f;

          K_FldFrame_CtlCopyPos(&posMain,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          savedMain = *(YajimaVec3 *)&posMain;



          iVar5 = K_FldFrame_CtlGetZGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          fVar17 = savedMain.z - ((float)iVar5 * 800.0f - 400.0f);


          cVar3 = *(char *)(iVar2 + 0xb29);

          worldPos2 = *(YajimaVec3 *)(&DAT_0086be04 + iVar10);

          iVar6 = FUN_0044f170(&worldPos2);


          cVar1 = *(char *)(iVar2 + 0xb29);

          iVar5 = (int)cVar1;

          if (cVar1 < '\0') {

            iVar5 = iVar5 + 1;

          }

          fVar17 = (float)(iVar5 >> 1) +

                   ((((*(float *)(iVar2 + 0x860) + (float)(cVar1 * param_5)) -

                     (((float)(int)cVar3 / 2.0f + 0.0f) -

                     (worldPos2.z - ((float)iVar6 * 800.0f - 400.0f)) * ((float)(int)cVar3 / 800.0f))) +


                    (float)(int)(((float)iVar11 / 2.0f + 0.0f) - fVar17 * ((float)iVar11 / 800.0f))) -

                   (float)((int)cVar1 << 1));

        }

        else {
          YajimaVec3 worldPos1;
          YajimaVec3 worldPos2;


          cVar3 = *(char *)(iVar2 + 0xb29);

          worldPos1 = *(YajimaVec3 *)(iVar2 + 0x868);

          iVar5 = FUN_0044f120(&worldPos1);


          fVar17 = worldPos1.x - ((float)iVar5 * 800.0f - 400.0f);


          fVar18 = (float)(int)*(char *)(iVar2 + 0xb29);

          iVar10 = iVar15 * 0x10;

          pfVar14 = (float *)(&DAT_0086be04 + iVar10);

          worldPos2 = *(YajimaVec3 *)(&DAT_0086be04 + iVar10);

          iVar6 = FUN_0044f120(&worldPos2);


          cVar1 = *(char *)(iVar2 + 0xb29);

          iVar11 = (int)cVar1;

          iVar5 = iVar11;

          if (cVar1 < '\0') {

            iVar5 = iVar11 + 1;

          }

          fVar18 = ((float)(iVar5 >> 1) +

                   ((((*(float *)(iVar2 + 0x85c) + (float)(cVar1 * param_4)) -

                     ((fVar18 / 2.0f + 0.0f) -

                     (worldPos2.x - ((float)iVar6 * 800.0f - 400.0f)) * (fVar18 / 800.0f))) +


                    (float)(int)(((float)(int)cVar3 / 2.0f + 0.0f) -

                                fVar17 * ((float)(int)cVar3 / 800.0f))) - (float)((int)cVar1 << 1)))

                   - 8.0f;

          worldPos1 = *(YajimaVec3 *)(iVar2 + 0x868);

          iVar5 = FUN_0044f170(&worldPos1);


          fVar17 = worldPos1.z - ((float)iVar5 * 800.0f - 400.0f);


          cVar3 = *(char *)(iVar2 + 0xb29);

          worldPos2 = *(YajimaVec3 *)(&DAT_0086be04 + iVar10);

          iVar6 = FUN_0044f170(&worldPos2);


          cVar1 = *(char *)(iVar2 + 0xb29);

          iVar5 = (int)cVar1;

          if (cVar1 < '\0') {

            iVar5 = iVar5 + 1;

          }

          fVar17 = (float)(iVar5 >> 1) +

                   ((((*(float *)(iVar2 + 0x860) + (float)(cVar1 * param_5)) -
                     (((float)(int)cVar3 / 2.0f + 0.0f) -

                     (worldPos2.z - ((float)iVar6 * 800.0f - 400.0f)) * ((float)(int)cVar3 / 800.0f))) +

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

            if (cVar3 != '\0') {

              uVar7 = FUN_00433810(uVar12,uVar13);

              if (DAT_0095c110[uVar7 & 0xff] == '\x01') {

                *(u8 *)(iVar5 + 0x18) = 0;

              }

            }

            else {

              if (DAT_0095c110[(short)param_3 * 0x10 + (int)param_2] == '\x01') {

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

            if (cVar3 != '\0') {

              uVar7 = FUN_00433810(uVar12,uVar13);

              if (DAT_0095c110[uVar7 & 0xff] == '\x01') {

                *(u8 *)(iVar5 + 0x18) = 0;

              }

            }

            else {

              if (DAT_0095c110[(short)param_3 * 0x10 + (int)param_2] == '\x01') {

                *(u8 *)(iVar5 + 0x18) = 0;

              }

            }

          }

          func_001127d0(uVar9,1);

          FUN_00115980(uVar9);

        }

        else if (iVar5 == 2) {
          YajimaVec3 posMain;
          YajimaVec3 posY;
          YajimaVec3 posZ;
          YajimaVec3 delta;


          K_FldFrame_CtlCopyPos(&posMain,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          delta.x = *pfVar14 - posMain.x;

          K_FldFrame_CtlCopyPos(&posY,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          delta.y = *(float *)(&DAT_0086be08 + iVar15 * 0x10) - posY.y;

          K_FldFrame_CtlCopyPos(&posZ,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          delta.z = *(float *)(&DAT_0086be0c + iVar15 * 0x10) - posZ.z;

          fVar16 = (float)RwV3dLength(&delta);

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

/* W327 measured: opt_loop_invariants on reduces normalized_diff 1890 -> 1837 (object 2468/2528 -> 2468/2528). */
#pragma opt_loop_invariants on
// FUN_0042EA60 NONMATCHING


void FUN_0042ea60(int param_1,u16 param_2,u16 param_3,int param_4,int param_5)



{

  char cVar1;

  int iVar2;

  char cVar3;

  int iVar4;

  u32 uVar5;

  int lVar6;

  u32 uVar7;

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

  YajimaVec3 mainPosZ;

  YajimaVec3 savedMainZ;

  float fStack_30;

  u32 uStack_2c;

  u32 uStack_28;

  YajimaVec3 mainPosX;

  YajimaVec3 savedMainX;

  

  iVar2 = *(int *)(param_1 + 0x3c);

  for (iVar9 = 0; iVar9 < 0x20; iVar9 = iVar9 + 1) {

    if (*(int *)(&DAT_0086be80 + iVar9 * 0x138) != 0) {


      lVar6 = FUN_0044f120(&DAT_0086bf8c + iVar9 * 0x138);

      if (((short)param_2 == lVar6) &&

         (lVar6 = FUN_0044f170(&DAT_0086bf8c + iVar9 * 0x138),

         (short)param_3 == lVar6)) {

        uVar7 = FUN_001158b0(0,DAT_007ce6e4,0xc);

        if (*(char *)(iVar2 + 0x865) != '\0') {

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

        else {

          cVar3 = *(char *)(iVar2 + 0xb29);

          iVar8 = iVar9 * 0x138;

          fStack_30 = *(float *)(&DAT_0086bf8c + iVar8);

          uStack_2c = *(u32 *)(&DAT_0086bf90 + iVar8);

          uStack_28 = *(u32 *)(&DAT_0086bf94 + iVar8);

          iVar4 = FUN_0044f120(&fStack_30);

          fVar14 = fStack_30 - ((float)iVar4 * 800.0f - 400.0f);

          fVar16 = (float)(int)*(char *)(iVar2 + 0xb29);

          K_FldFrame_CtlCopyPos(&mainPosX,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          savedMainX = mainPosX;

          iVar4 = K_FldFrame_CtlGetXGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          fVar15 = savedMainX.x - ((float)iVar4 * 800.0f - 400.0f);

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

          K_FldFrame_CtlCopyPos(&mainPosZ,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          savedMainZ = mainPosZ;

          iVar4 = K_FldFrame_CtlGetZGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          fVar15 = savedMainZ.z - ((float)iVar4 * 800.0f - 400.0f);

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
#pragma opt_loop_invariants reset

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

  YajimaVec3 mainPosX;

  YajimaVec3 savedMainX;

  

  iVar2 = *(int *)(param_1 + 0x3c);

  if (((DAT_0086e580 == 1) && (sVar4 = FUN_0044f120(DAT_0086e684_abs), param_2 == sVar4)) &&

     (sVar4 = FUN_0044f170(DAT_0086e684_abs), param_3 == sVar4)) {

    uVar7 = FUN_001158b0(0,DAT_007ce6e4,5);

    if (*(char *)(iVar2 + 0x865) != '\0') {

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

    else {

      cVar3 = *(char *)(iVar2 + 0xb29);

      fStack_30 = DAT_0086e684;

      uStack_2c = DAT_0086e688;

      fStack_28 = DAT_0086e68c;

      iVar5 = FUN_0044f120(&fStack_30);

      fVar10 = fStack_30 - ((float)iVar5 * 800.0f - 400.0f);

      fVar12 = (float)(int)*(char *)(iVar2 + 0xb29);

      K_FldFrame_CtlCopyPos(&mainPosX,*(u32 *)(DAT_008717f4 + 0x1e0));

      savedMainX = mainPosX;

      iVar5 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

      fVar11 = savedMainX.x - ((float)iVar5 * 800.0f - 400.0f);

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

// FUN_0042FD80


void FUN_0042fd80(float *param_1,int param_2)



{

  u8 *fieldData;

  int iVar2;

  int iVar3;

  int scanColumn;

  int scanRow;

  u32 unaff_s5_lo;

  u32 unaff_s4_lo;

  int rowOffset;

  int columnOffset;

  int uVar5;

  int uVar4;

  YajimaVec3 position;

  

  iVar3 = *(int *)(param_2 + 0x3c);

  for (scanRow = 0; scanRow < 0x10; scanRow = scanRow + 1) {

    scanColumn = 0;

    rowOffset = scanRow * 0x100;

    for (; scanColumn < 0x10; scanColumn = scanColumn + 1) {

      columnOffset = scanColumn * 0x10;

      fieldData = (u8 *)(rowOffset + K_Field_Get());

      if (*(u8 *)(fieldData + columnOffset + 0x4a) == '\b') {

        fieldData = (u8 *)(rowOffset + K_Field_Get());

        if (*(u8 *)(fieldData + columnOffset + 0x49) == '\x01') {

          unaff_s5_lo = scanColumn;

          unaff_s4_lo = scanRow;

        }

      }

    }

  }

  *(u8 *)(iVar3 + 0xbb0) = (char)unaff_s5_lo;

  *(u8 *)(iVar3 + 0xbb1) = (char)unaff_s4_lo;

  *(float *)(iVar3 + 0xb10) = (float)(int)unaff_s5_lo * 800.0f;

  *(float *)(iVar3 + 0xb14) = (float)(int)unaff_s4_lo * 800.0f;

  for (uVar5 = unaff_s5_lo; (int)uVar5 < (int)(unaff_s5_lo + 2); uVar5 = uVar5 + 1) {

    uVar4 = unaff_s4_lo;

    iVar3 = uVar5 * 0x10;

    for (; (int)uVar4 < (int)(unaff_s4_lo + 2); uVar4 = uVar4 + 1) {

      iVar2 = uVar4 * 0x100;

      fieldData = (u8 *)(iVar3 + K_Field_Get());

      if (((*(u8 *)(fieldData + iVar2 + 0x53) & 1) != 0) &&

         (fieldData = (u8 *)(iVar3 + K_Field_Get()), *(u8 *)(fieldData + iVar2 + -0xb6) != '\b')) {

        func_001bf220(&position.x,uVar5 & 0xffff,uVar4 - 1 & 0xffff);

      }

      fieldData = (u8 *)(iVar3 + K_Field_Get());

      if (((*(u8 *)(fieldData + iVar2 + 0x53) & 2) != 0) &&

         (fieldData = (u8 *)(iVar3 + K_Field_Get()), *(u8 *)(fieldData + iVar2 + 0x3a) != '\b')) {

        func_001bf220(&position.x,uVar5 - 1 & 0xffff,uVar4 & 0xffff);

      }

      fieldData = (u8 *)(iVar3 + K_Field_Get());

      if (((*(u8 *)(fieldData + iVar2 + 0x53) & 4) != 0) &&

         (fieldData = (u8 *)(iVar3 + K_Field_Get()), *(u8 *)(fieldData + iVar2 + 0x14a) != '\b')) {

        func_001bf220(&position.x,uVar5 & 0xffff,uVar4 + 1 & 0xffff);

      }

      fieldData = (u8 *)(iVar3 + K_Field_Get());

      if (((*(u8 *)(fieldData + iVar2 + 0x53) & 8) != 0) &&

         (fieldData = (u8 *)(iVar3 + K_Field_Get()), *(u8 *)(fieldData + iVar2 + 0x5a) != '\b')) {

        func_001bf220(&position.x,uVar5 + 1 & 0xffff,uVar4 & 0xffff);

      }

    }

  }

  *(YajimaVec3 *)param_1 = position;

  return;

}
