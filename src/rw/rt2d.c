#include "mw_harvest_compat.h"
#include "rw/rwplcore.h"

/* auto-extern (generated) */
extern u32 uGpffffbbc0;
u32 FUN_004b92d0(u64 param_1);
u64 FUN_004b1700(float param_1,u64 param_2,u64 param_3);
u64 FUN_004b3f50(u64 param_1,u64 param_2,int *param_3,int param_4,u64 param_5);
u64 FUN_004b4810(u64 param_1);
u64 FUN_004b1990(u64 param_1,code *param_2,u64 param_3,u64 param_4);
void FUN_004b22b0(u64 param_1);
u64 FUN_004b47d0(u64 param_1);
u32 FUN_004b8290(u32 param_1,u32 *param_2);
u64 FUN_004b62a0(int param_1,u64 param_2,u64 param_3,u64 param_4,
            u32 *param_5);
u32 FUN_004b97f0(int param_1);
u64 FUN_004b8630(u64 param_1,float *param_2);
u32 FUN_004b2ba0(int param_1);
int FUN_004b3440(int param_1);
u32 FUN_004b91b0(void);
long FUN_004b90a0(u64 param_1);
long FUN_004b6a40(u64 param_1);
u64 FUN_004b9140(u64 param_1,u64 param_2);
u64 FUN_004b2810(float param_1,u64 param_2,u64 param_3);
long FUN_004b43c0(void);
u64 FUN_004b4cc0(u64 param_1,u64 param_2);
long FUN_004b6040(void);
u32 FUN_004b6270(u32 param_1);
void FUN_004b5380(u64 param_1,u64 param_2);
u32 FUN_004b7240(float param_1,u64 param_2);
u64 FUN_004b2300(u64 param_1,u64 param_2);
long FUN_004b5ec0(u64 param_1,long param_2,u64 param_3);
#pragma alias FUN_004b9350_wide FUN_004b9350
extern u64 FUN_004b9350_wide(u64 param_1);
u32 FUN_004b9350(u32 param_1);
long FUN_004b91c0(u64 param_1,int param_2,u64 param_3,u64 param_4,long param_5);
u64 FUN_004b4860(u64 param_1,u64 param_2);
u32 FUN_004b96e0(int param_1);
long FUN_004b4ba0(long param_1,code *param_2,u64 param_3);
bool FUN_004b1c80(long param_1);
u32 FUN_004b5270(u64 param_1,long param_2);
u32 FUN_004b6190(u64 param_1);
int FUN_004b4a60(int param_1,int param_2);
#pragma alias FUN_004b65a0_abs FUN_004b65a0
extern u8 FUN_004b65a0_abs[];
#pragma alias FUN_004b6600_abs FUN_004b6600
extern u8 FUN_004b6600_abs[];
bool FUN_004b1b90(int param_1);

/* externs for implicitly called functions */
extern u32 FUN_004b1a30(u32 *param_1);
extern u32 FUN_004b1a40(u32 *param_1);
extern f32 FUN_004b1a60(f32 *param_1);
extern f32 FUN_004b1a70(int param_1);
extern int FUN_004b1a80(u32 *param_1);
extern f32 FUN_004b1ae0(int param_1);
extern f32 FUN_004b1b60(int param_1);
extern u64 FUN_004b1290(u64 param_1,u64 param_2);
extern u64 FUN_004b14c0(float param_1,u64 param_2);
extern void FUN_004b1870(u64 param_1,u64 param_2,int param_3);
extern int FUN_004b2ad0(int param_1,u32 param_2);
extern u64 FUN_004b2b40(u64 param_1);
extern u64 FUN_004b1240(u64 param_1,u64 param_2);
extern u32 FUN_004b42e0(u64 param_1);
extern u64 FUN_004b3de0(u64 param_1,u64 param_2,int param_3,int *param_4);
extern long FUN_004b4a70(long param_1,code *param_2,u64 param_3);
extern u64 FUN_004b4eb0(u64 param_1,u32 *param_2,long param_3);
extern u64 FUN_004b1500(u64 param_1,u64 param_2,int param_3);
extern int FUN_004b05c0(int, int);
extern long FUN_004b0df0(int *param_1);
extern void FUN_004b26a0(u32 *param_1);
extern void FUN_004b2bc0(void);
extern u64 FUN_004b2bf0(u64 param_1,long param_2,u64 param_3);
extern long FUN_004b2c80(int param_1,long param_2,u64 param_3);
extern u32 * FUN_004b30a0(u32 *param_1);
extern u32 * FUN_004b3100(u32 *param_1);
extern u64 FUN_004b5d80(u64 param_1,u64 param_2,u64 param_3);
extern u32 FUN_004b6ec0(u32 *param_1,int *param_2);
extern u64 FUN_004b6840(u32 param_1,int param_2,int param_3,u32 param_4);
extern long FUN_004b91c0(u64 param_1,int param_2,u64 param_3,u64 param_4,long param_5);
extern u32 FUN_004b0430(int param_1,int param_2,int param_3,int param_4);
extern u32 FUN_004b0560(int param_1,int param_2,int param_3,int param_4,int param_5);
extern int FUN_004b2230(int);

extern code pcGpffffbbac;
extern u32 uGpffffafec;
extern u32 uGpffffaff4;
extern u32 DAT_007cdcf0;
extern u32 DAT_007cdcf8;
extern u32 DAT_007cdd00;
extern u32 uGpffffafe8;
extern u32 uGpffffaff0;
extern u32 DAT_0077e4c0;
extern u32 DAT_0077e4c4;
extern u32 DAT_0077e4c8;
extern u8 DAT_0077e4e0[];
#pragma alias DAT_0077e4c0_abs DAT_0077e4c0
#pragma alias DAT_0077e4c4_abs DAT_0077e4c4
#pragma alias DAT_0077e4c8_abs DAT_0077e4c8
extern u32 DAT_0077e4c0_abs[];
extern u32 DAT_0077e4c4_abs[];
extern u32 DAT_0077e4c8_abs[];
#pragma alias FUN_004c31b0_typed FUN_004c31b0
extern void FUN_004c31b0_typed(float angle, int matrix, int axis, int combine);
#pragma alias DAT_007bcbc8_abs DAT_007bcbc8
#pragma alias DAT_007bcbd8_abs DAT_007bcbd8
extern u8 DAT_007bcbc8_abs[];
extern u8 DAT_007bcbd8_abs[];
extern u32 DAT_0077e4d0;
extern u32 DAT_0077e4d4;
extern u32 DAT_0077e4d8;
extern u32 DAT_0077e520;
extern u32 DAT_0077e550;
extern u32 DAT_0077e580;
extern u32 DAT_0077e584;
extern u32 DAT_0077e588;
extern u32* DAT_007cdce8;
extern u32 DAT_007cdcec;
extern u32 DAT_007cdcf4;
extern u32 DAT_007cdcfc;
extern u32 DAT_007ce898;
extern u32 DAT_007ce8a0;
extern u32 DAT_007ce8a4;
extern u32 DAT_007ce8ac;
extern u32 DAT_007ce8b0;
extern u32* DAT_0095ed94;
extern u32* DAT_0095ed98;
#pragma alias DAT_0095ed94_abs DAT_0095ed94
#pragma alias DAT_0095ed98_abs DAT_0095ed98
extern u32 DAT_0095ed94_abs[];
extern u32 DAT_0095ed98_abs[];
extern u32 DAT_0095ed9c;
extern u32 DAT_0095eda0;
extern u32 DAT_0095f034;
extern u32 DAT_0095f038;
extern u32 DAT_0095f03c;
extern u32 DAT_0095f040;
extern u32 DAT_0095f044;
extern u32 DAT_0095f048;
extern u32 DAT_0095f04c;
extern u32 DAT_0095f050;
#pragma alias DAT_0095f034_abs DAT_0095f034
#pragma alias DAT_0095f038_abs DAT_0095f038
#pragma alias DAT_0095f03c_abs DAT_0095f03c
#pragma alias DAT_0095f040_abs DAT_0095f040
#pragma alias DAT_0095f044_abs DAT_0095f044
#pragma alias DAT_0095f048_abs DAT_0095f048
#pragma alias DAT_0095f04c_abs DAT_0095f04c
#pragma alias DAT_0095f050_abs DAT_0095f050
extern u32 DAT_0095f034_abs[];
extern u32 DAT_0095f038_abs[];
extern u32 DAT_0095f03c_abs[];
extern u32 DAT_0095f040_abs[];
extern u32 DAT_0095f044_abs[];
extern u32 DAT_0095f048_abs[];
extern u32 DAT_0095f04c_abs[];
extern u32 DAT_0095f050_abs[];
extern u32 DAT_0095fbe0;
extern u32 DAT_0095fbe4;
extern u32 DAT_0095fbe8;
extern u32 DAT_0095fbec;
extern u32 DAT_0095fbf0;
extern u32 DAT_0095fbf4;
extern u32 DAT_0095fbf8;
extern u32 DAT_0095fbfc;
extern u32 DAT_0095fc00;
extern u32 DAT_0095fc04;
extern u32 DAT_0095fc08;
extern u32 DAT_0095fc0c;
extern code DAT_00960158;
extern code DAT_00960178;
#pragma alias DAT_00960178_abs DAT_00960178
extern code DAT_00960178_abs[];
#pragma alias DAT_0096018c_abs DAT_0096018c
extern void (*DAT_0096018c_abs[])(u32,u64);
extern code DAT_0096017c;
extern code DAT_00960188;
extern code DAT_0096018c;
#pragma alias DAT_0096017c_abs DAT_0096017c
extern void (*DAT_0096017c_abs[])(void);
extern u64 FUN_004b5b50(u64 param_1,u64 param_2);
extern u8 LAB_004b7f80;
#pragma alias LAB_004bcb20_abs LAB_004bcb20
extern u8 LAB_004bcb20_abs[];
#pragma alias FUN_004b91b0_arg FUN_004b91b0
extern u32 FUN_004b91b0_arg(u32 param_1);
#pragma alias FUN_004bca00_void FUN_004bca00
extern u64 FUN_004bca00_void(void);
extern u8 LAB_004bcb20;
extern void* PTR_LAB_0077e3f4;
extern u32 uRam00000000;
extern u32 uRam00000004;
extern u32 uRam00000008;
extern u32 uRam0000000c;
extern u8* iGpffffbbc4;

#ifndef ABS
#define ABS(x) ((x) < 0 ? -(x) : (x))
#endif
#ifndef SQRT
#define SQRT(x) sqrtf(x)
#endif


// FUN_004B0360 NONMATCHING
u32 FUN_004b0360(long param_1)

{
  u32 *puVar1;
  u32 *puVar2;
  u32 *puVar3;
  u32 *puVar4;
  
  if (param_1 != 0) {
    puVar4 = (u32 *)param_1;
    *puVar4 = 0;
    puVar1 = (u32 *)puVar4[1];
    puVar3 = puVar1;
    if (puVar1 != (u32 *)0x0) {
      do {
        puVar2 = (u32 *)*puVar3;
        if (puVar3 != (u32 *)0x0) {
          *puVar3 = 0;
          puVar3[1] = 0xffffffff;
          (*DAT_0096018c)(DAT_0095ed94);
        }
        puVar3 = puVar2;
      } while (puVar2 != puVar1);
    }
    if (puVar4[4] != 0) {
      (*DAT_0096017c)();
    }
    puVar4[1] = 0;
    puVar4[4] = 0;
    puVar4[3] = 0;
    (*DAT_0096018c)(DAT_0095ed98,param_1);
  }
  return 1;
}
// FUN_004B0430 NONMATCHING
u32 FUN_004b0430(int param_1,int param_2,int param_3,int param_4)

{
  u32 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fStack_8;
  float fStack_4;
  
  iVar3 = *(int *)(param_1 + 0x10) + 4;
  fStack_8 = *(float *)(iVar3 + *(int *)(param_4 + 4) * 8) -
             *(float *)(iVar3 + *(int *)(param_3 + 4) * 8);
  fStack_4 = *(float *)(*(int *)(param_1 + 0x10) + *(int *)(param_3 + 4) * 8) -
             *(float *)(*(int *)(param_1 + 0x10) + *(int *)(param_4 + 4) * 8);
  FUN_004c6b20(&fStack_8,&fStack_8);
  iVar3 = *(int *)(param_1 + 0x10);
  iVar4 = *(int *)(param_2 + 4) * 8;
  iVar2 = *(int *)(param_3 + 4) * 8;
  fVar5 = (*(float *)(iVar3 + iVar2) - *(float *)(iVar3 + iVar4)) * fStack_8 +
          (*(float *)(iVar3 + 4 + iVar2) - *(float *)(iVar3 + 4 + iVar4)) * fStack_4;
  if (fVar5 <= 0.0) {
    if (fVar5 < 0.0) {
      uVar1 = 2;
    }
    else {
      uVar1 = 4;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}
// FUN_004B0560 NONMATCHING
u32 FUN_004b0560(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  u32 uVar1;
  int iVar2;
  u32 uVar3;
  int iVar4;
  int iVar5;
  u32 uVar6;
  u32 uVar7;
  float fVar8;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar4 = *(int *)(param_1 + 0x10) + 4;
  fStack_8 = *(float *)(iVar4 + *(int *)(param_4 + 4) * 8) -
             *(float *)(iVar4 + *(int *)(param_3 + 4) * 8);
  fStack_4 = *(float *)(*(int *)(param_1 + 0x10) + *(int *)(param_3 + 4) * 8) -
             *(float *)(*(int *)(param_1 + 0x10) + *(int *)(param_4 + 4) * 8);
  FUN_004c6b20(&fStack_8,&fStack_8);
  iVar4 = *(int *)(param_1 + 0x10);
  iVar5 = *(int *)(param_2 + 4) * 8;
  iVar2 = *(int *)(param_3 + 4) * 8;
  fVar8 = (*(float *)(iVar4 + iVar2) - *(float *)(iVar4 + iVar5)) * fStack_8 +
          (*(float *)(iVar4 + 4 + iVar2) - *(float *)(iVar4 + 4 + iVar5)) * fStack_4;
  if (fVar8 <= 0.0) {
    if (fVar8 < 0.0) {
      uVar6 = 2;
    }
    else {
      uVar6 = 4;
    }
  }
  else {
    uVar6 = 1;
  }
  fStack_10 = *(float *)(iVar4 + 4 + *(int *)(param_5 + 4) * 8) -
              *(float *)(iVar4 + 4 + *(int *)(param_4 + 4) * 8);
  fStack_c = *(float *)(*(int *)(param_1 + 0x10) + *(int *)(param_4 + 4) * 8) -
             *(float *)(*(int *)(param_1 + 0x10) + *(int *)(param_5 + 4) * 8);
  FUN_004c6b20(&fStack_10,&fStack_10);
  iVar4 = *(int *)(param_1 + 0x10);
  iVar2 = *(int *)(param_4 + 4) * 8;
  iVar5 = *(int *)(param_2 + 4) * 8;
  fVar8 = (*(float *)(iVar4 + iVar2) - *(float *)(iVar4 + iVar5)) * fStack_10 +
          (*(float *)(iVar4 + 4 + iVar2) - *(float *)(iVar4 + 4 + iVar5)) * fStack_c;
  if (fVar8 <= 0.0) {
    if (fVar8 < 0.0) {
      uVar7 = 2;
    }
    else {
      uVar7 = 4;
    }
  }
  else {
    uVar7 = 1;
  }
  fStack_18 = *(float *)(iVar4 + 4 + *(int *)(param_3 + 4) * 8) -
              *(float *)(iVar4 + 4 + *(int *)(param_5 + 4) * 8);
  fStack_14 = *(float *)(*(int *)(param_1 + 0x10) + *(int *)(param_5 + 4) * 8) -
              *(float *)(*(int *)(param_1 + 0x10) + *(int *)(param_3 + 4) * 8);
  FUN_004c6b20(&fStack_18,&fStack_18);
  iVar4 = *(int *)(param_1 + 0x10);
  iVar5 = *(int *)(param_2 + 4) * 8;
  iVar2 = *(int *)(param_5 + 4) * 8;
  fVar8 = (*(float *)(iVar4 + iVar2) - *(float *)(iVar4 + iVar5)) * fStack_18 +
          (*(float *)(iVar4 + 4 + iVar2) - *(float *)(iVar4 + 4 + iVar5)) * fStack_14;
  if (fVar8 <= 0.0) {
    if (fVar8 < 0.0) {
      uVar3 = 2;
    }
    else {
      uVar3 = 4;
    }
  }
  else {
    uVar3 = 1;
  }
  if ((uVar3 & uVar6 & uVar7) == 1) {
    uVar1 = 8;
  }
  else if (((uVar3 | uVar6 | uVar7) & 4) == 0) {
    uVar1 = 0x10;
  }
  else {
    uVar1 = 4;
  }
  return uVar1;
}
// FUN_004B08C0 NONMATCHING
u32 * FUN_004b08c0(int param_1,u32 *param_2,u32 *param_3)

{
  u32 *puVar1;
  u32 *puVar2;
  long lVar3;
  u32 *puVar4;
  u32 *puVar5;
  u32 *puVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = 0;
  iVar7 = 0;
  lVar3 = (*DAT_00960188)(DAT_0095ed98,0x30190);
  puVar1 = (u32 *)lVar3;
  if (lVar3 != 0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[4] = 0;
    puVar1[3] = 0;
  }
  if (puVar1 != (u32 *)0x0) {
    puVar6 = (u32 *)0x0;
    puVar5 = (u32 *)0x0;
    for (puVar2 = *(u32 **)(param_1 + 4); puVar2 != param_2; puVar2 = (u32 *)*puVar2)
    {
    }
    while (puVar2 != param_3) {
      puVar4 = (u32 *)*puVar2;
      if (puVar6 == (u32 *)0x0) {
        *puVar2 = (u32)(puVar2);
      }
      else {
        *puVar2 = *puVar6;
        *puVar6 = (u32)(puVar2);
      }
      iVar7 = iVar7 + 1;
      puVar6 = puVar2;
      puVar2 = puVar4;
    }
    lVar3 = (*DAT_00960188)(DAT_0095ed94,0x30190);
    puVar4 = (u32 *)lVar3;
    if (lVar3 != 0) {
      *puVar4 = 0;
      puVar4[1] = 0xffffffff;
    }
    puVar4[1] = param_3[1];
    if (puVar6 == (u32 *)0x0) {
      *puVar4 = (u32)(puVar4);
    }
    else {
      *puVar4 = *puVar6;
      *puVar6 = (u32)(puVar4);
    }
    while (puVar2 != param_2) {
      puVar6 = (u32 *)*puVar2;
      if (puVar5 == (u32 *)0x0) {
        *puVar2 = (u32)(puVar2);
      }
      else {
        *puVar2 = *puVar5;
        *puVar5 = (u32)(puVar2);
      }
      iVar8 = iVar8 + 1;
      puVar5 = puVar2;
      puVar2 = puVar6;
    }
    lVar3 = (*DAT_00960188)(DAT_0095ed94,0x30190);
    puVar2 = (u32 *)lVar3;
    if (lVar3 != 0) {
      *puVar2 = 0;
      puVar2[1] = 0xffffffff;
    }
    puVar2[1] = param_2[1];
    if (puVar5 == (u32 *)0x0) {
      *puVar2 = (u32)(puVar2);
    }
    else {
      *puVar2 = *puVar5;
      *puVar5 = (u32)(puVar2);
    }
    *(u32 **)(param_1 + 4) = puVar4;
    puVar1[1] = (u32)(puVar2);
    *(int *)(param_1 + 0xc) = iVar7 + 1;
    puVar1[3] = iVar8 + 1;
    puVar1[4] = *(u32 *)(param_1 + 0x10);
    puVar1[2] = *(u32 *)(param_1 + 8);
  }
  return puVar1;
}
// FUN_004B0B10 NONMATCHING
u64 FUN_004b0b10(u64 param_1)

{
  bool bVar1;
  u32 *puVar2;
  u32 *puVar3;
  u32 *puVar4;
  float fVar5;
  u32 *puVar6;
  float *pfVar7;
  long lVar8;
  u64 uVar9;
  float *pfVar10;
  int iVar11;
  u32 *puVar12;
  u32 *puVar13;
  u32 *puVar14;
  float fVar15;
  float fStack_8;
  float fStack_4;
  
  iVar11 = (int)param_1;
  if (*(int *)(iVar11 + 0xc) == 3) {
    *(u32 *)((*(int **)(iVar11 + 8))[1] + **(int **)(iVar11 + 8) * 4) =
         *(u32 *)(*(int *)(iVar11 + 4) + 4);
    **(int **)(iVar11 + 8) = **(int **)(iVar11 + 8) + 1;
    *(u32 *)((*(int **)(iVar11 + 8))[1] + **(int **)(iVar11 + 8) * 4) =
         *(u32 *)(**(int **)(iVar11 + 4) + 4);
    **(int **)(iVar11 + 8) = **(int **)(iVar11 + 8) + 1;
    *(u32 *)((*(int **)(iVar11 + 8))[1] + **(int **)(iVar11 + 8) * 4) =
         *(u32 *)(*(int *)**(u32 **)(iVar11 + 4) + 4);
    **(int **)(iVar11 + 8) = **(int **)(iVar11 + 8) + 1;
  }
  else {
    puVar14 = (u32 *)0x0;
    puVar2 = (u32 *)**(u32 **)(iVar11 + 4);
    puVar3 = (u32 *)*puVar2;
    puVar13 = *(u32 **)(iVar11 + 4);
    do {
      puVar4 = puVar3;
      lVar8 = (int)(((code)FUN_004b0430)(param_1,puVar4,puVar13,puVar2));
      if (lVar8 == 1) {
        *(u32 **)(iVar11 + 4) = puVar13;
        puVar14 = puVar2;
        break;
      }
      bVar1 = puVar2 != *(u32 **)(iVar11 + 4);
      puVar3 = (u32 *)*puVar4;
      puVar13 = puVar2;
      puVar2 = puVar4;
    } while (bVar1);
    if (puVar14 != (u32 *)0x0) {
      puVar2 = *(u32 **)(iVar11 + 4);
      puVar3 = (u32 *)*puVar2;
      puVar13 = (u32 *)*puVar3;
      fVar5 = 0.0;
      puVar6 = (u32 *)0x0;
      for (puVar4 = (u32 *)*puVar13; puVar4 != puVar2; puVar4 = (u32 *)*puVar4) {
        lVar8 = (int)(((code)FUN_004b0560)(param_1,puVar4,puVar2,puVar3,puVar13));
        fVar15 = fVar5;
        puVar12 = puVar6;
        if (lVar8 == 8) {
          fStack_8 = *(float *)(*(int *)(iVar11 + 0x10) + puVar2[1] * 8 + 4) -
                     *(float *)(*(int *)(iVar11 + 0x10) + puVar13[1] * 8 + 4);
          fStack_4 = *(float *)(*(int *)(iVar11 + 0x10) + puVar13[1] * 8) -
                     *(float *)(*(int *)(iVar11 + 0x10) + puVar2[1] * 8);
          FUN_004c6b20(&fStack_8,&fStack_8);
          pfVar10 = (float *)(*(int *)(iVar11 + 0x10) + puVar4[1] * 8);
          pfVar7 = (float *)(*(int *)(iVar11 + 0x10) + puVar13[1] * 8);
          fVar15 = (*pfVar7 - *pfVar10) * fStack_8 + (pfVar7[1] - pfVar10[1]) * fStack_4;
          puVar12 = puVar4;
          if (fVar15 <= fVar5) {
            fVar15 = fVar5;
            puVar12 = puVar6;
          }
        }
        fVar5 = fVar15;
        puVar6 = puVar12;
      }
      if (puVar6 == (u32 *)0x0) {
        uVar9 = (u64)(int)FUN_004b08c0(param_1,*(u32 **)(iVar11 + 4),
                             *(u32 **)(iVar11 + 4));
      }
      else {
        uVar9 = (u64)(FUN_004b08c0(param_1,puVar14,puVar6));
      }
      FUN_004b0b10(uVar9);
      FUN_004b0b10(param_1);
      *(u32 *)((int)uVar9 + 0x10) = 0;
      FUN_004b0360(uVar9);
    }
  }
  return param_1;
}
// FUN_004B0DF0 NONMATCHING
long FUN_004b0df0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  u32 uVar4;
  u32 *puVar5;
  long lVar6;
  long lVar7;
  int iVar8;
  u32 *puVar9;
  long lVar10;
  int iVar11;
  
  if (param_1[1] == -1) {
    iVar2 = FUN_004c2090(*param_1);
  }
  else {
    iVar2 = *param_1;
  }
  iVar3 = param_1[1];
  if (iVar3 == -1) {
    iVar3 = FUN_004c2120(*param_1);
  }
  iVar3 = iVar3 + -1;
  lVar6 = (*DAT_00960188)(DAT_0095ed98,0x30190);
  puVar9 = (u32 *)lVar6;
  if (lVar6 != 0) {
    *puVar9 = 0;
    puVar9[1] = 0;
    puVar9[4] = 0;
    puVar9[3] = 0;
    uVar4 = (*DAT_00960178)(iVar3 * 8,0x30190);
    puVar9[4] = uVar4;
    if (puVar9[4] != 0) {
      iVar11 = 0;
      if (iVar3 < 1) {
        puVar9[1] = 0;
      }
      else {
        iVar8 = 0;
        lVar10 = 0;
        do {
          lVar7 = (*DAT_00960188)(DAT_0095ed94,0x30190);
          puVar5 = (u32 *)lVar7;
          if (lVar7 != 0) {
            *puVar5 = 0;
            puVar5[1] = 0xffffffff;
          }
          puVar5[1] = iVar11;
          iVar1 = puVar9[4];
          uVar4 = *(u32 *)(iVar2 + 8);
          *(u32 *)(iVar1 + iVar8) = *(u32 *)(iVar2 + 4);
          ((u32 *)(iVar1 + iVar8))[1] = uVar4;
          if (lVar10 == 0) {
            *puVar5 = (u32)(puVar5);
          }
          else {
            *puVar5 = *(u32 *)lVar10;
            *(u32 *)lVar10 = (u32)puVar5;
          }
          iVar11 = iVar11 + 1;
          iVar2 = iVar2 + 0x18;
          iVar8 = iVar8 + 8;
          lVar10 = lVar7;
        } while (iVar11 < iVar3);
        puVar9[1] = (u32)(puVar5);
      }
      puVar9[3] = iVar3;
    }
  }
  return lVar6;
}
// FUN_004B0FA0 NONMATCHING
u64 FUN_004b0fa0(u64 param_1,int *param_2,u32 param_3)

{
  long lVar1;
  
  lVar1 = ((code)FUN_004b0df0)();
  if (lVar1 != 0) {
    DAT_0095ed9c = 0;
    DAT_0095eda0 = param_3;
    *(int **)((int)lVar1 + 8) = (int *)&DAT_0095ed9c;
    FUN_004b0b10(lVar1);
    *param_2 = DAT_0095ed9c / 3;
    FUN_004b0360(lVar1);
  }
  return param_1;
}
#pragma schedule on
// FUN_004B1050
void FUN_004b1050(void)
{
  FUN_004c3c30(DAT_0095ed94_abs[0]);
  FUN_004c3c30(DAT_0095ed98_abs[0]);
  DAT_0095ed94_abs[0] = 0;
  DAT_0095ed98_abs[0] = 0;
}
#pragma schedule off
// FUN_004B1090 NONMATCHING
u32 FUN_004b1090(void)

{
  DAT_0095ed94 = (u32 *)(thunk_FUN_004c3970(8,uGpffffaff0,4,uGpffffaff4,0x95f9f0,0x40190));
  DAT_0095ed98 = (u32 *)(thunk_FUN_004c3970(0x14,uGpffffafe8,4,uGpffffafec,0x95fa20,0x40190));
  return 1;
}
#pragma schedule on
// FUN_004B1100
u32 FUN_004b1100(void)

{
  DAT_0095f034_abs[0] = 0;
  DAT_0095f038_abs[0] = 0;
  DAT_0095f03c_abs[0] = FUN_0046a890(0x1001a);
  DAT_0095f040_abs[0] = FUN_0046a890(0x1001a);
  DAT_0095f04c_abs[0] = FUN_0046a890(0x1001e);
  DAT_0095f050_abs[0] = FUN_0046a890(0x1001e);
  DAT_0095f044_abs[0] = FUN_0046a890(0x1001c);
  DAT_0095f048_abs[0] = FUN_0046a890(0x1001c);
  return 1;
}
#pragma schedule off
#pragma schedule on
// FUN_004B11A0
void FUN_004b11a0(void)

{
  DAT_0095f034_abs[0] = 0;
  DAT_0095f038_abs[0] = 0;
  DAT_0095f03c_abs[0] = 0;
  DAT_0095f040_abs[0] = 0;
  DAT_0095f04c_abs[0] = 0;
  DAT_0095f050_abs[0] = 0;
  DAT_0095f044_abs[0] = 0;
  DAT_0095f048_abs[0] = 0;
  return;
}
#pragma schedule off
// FUN_004B11F0 NONMATCHING
u64 FUN_004b11f0(u64 param_1,u64 param_2,u64 param_3,u32 *param_4)

{
  bool bVar1;
  long lVar2;
  
  lVar2 = FUN_004b1c80(param_3);
  bVar1 = false;
  if (lVar2 != 0) {
    bVar1 = *param_4 != 0;
  }
  *param_4 = (u32)bVar1;
  return param_3;
}
// FUN_004B1240 NONMATCHING
u64 FUN_004b1240(u64 param_1,u64 param_2)

{
  u32 uStack_4;
  
  uStack_4 = 1;
  FUN_004c20b0(*(u32 *)param_1);
  *(u32 *)param_1 = 0;
  return param_1;
}
// FUN_004B1290 NONMATCHING
u64 FUN_004b1290(u64 param_1,u64 param_2)

{
  int iVar1;
  u32 uVar2;
  float *pfVar3;
  long lVar4;
  u32 *puVar5;
  float *pfVar6;
  float fStack_8;
  int iStack_4;
  
  iStack_4 = 0;
  lVar4 = FUN_004c5250(param_2,&iStack_4,4);
  iVar1 = iStack_4;
  if (lVar4 == 4) {
    uVar2 = FUN_004c1d50(8,0x301b0);
    puVar5 = (u32 *)param_1;
    *puVar5 = uVar2;
    if (iVar1 != 0) {
      FUN_004c1f70(*puVar5,iVar1,0x301b0);
    }
    puVar5[1] = 0x3f800000;
    puVar5[2] = 0;
    puVar5[3] = 1;
    puVar5[4] = 0;
    puVar5[5] = 0;
    puVar5[6] = 0;
    pfVar3 = (float *)FUN_004c2090(*puVar5);
    pfVar6 = pfVar3 + iStack_4 * 2;
    for (; pfVar3 != pfVar6; pfVar3 = pfVar3 + 2) {
      lVar4 = FUN_004c5250(param_2,&fStack_8,4);
      if (lVar4 != 4) {
        return 0;
      }
      *pfVar3 = fStack_8;
      lVar4 = FUN_004c1600(param_2,0x1b0,0,0);
      if (lVar4 == 0) {
        return 0;
      }
      lVar4 = ((code)FUN_004b22b0)(param_2);
      if (lVar4 == 0) {
        return 0;
      }
      pfVar3[1] = (float)lVar4;
      uVar2 = FUN_004c2090(*puVar5);
      puVar5[5] = uVar2;
      if (((float *)puVar5[6] == (float *)0x0) || (*(float *)puVar5[6] < fStack_8)) {
        puVar5[6] = (u32)(pfVar3);
      }
    }
  }
  else {
    param_1 = 0;
  }
  return param_1;
}
// FUN_004B1420 NONMATCHING
u64 FUN_004b1420(u64 param_1,u64 param_2)

{
  u32 uVar1;
  long lVar2;
  u32 *puVar3;
  
  puVar3 = (u32 *)param_1;
  lVar2 = FUN_004c2120(*puVar3);
  puVar3[2] = 0;
  if (lVar2 < 1) {
    puVar3[4] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
  }
  else {
    puVar3[4] = 0;
    uVar1 = FUN_004c21b0(*puVar3,0);
    puVar3[5] = uVar1;
    uVar1 = FUN_004c21b0(*puVar3,(int)lVar2 + -1);
    puVar3[6] = uVar1;
    FUN_004b2300(*(u32 *)(puVar3[5] + 4),param_2);
  }
  return param_1;
}
// FUN_004B14C0 NONMATCHING
u64 FUN_004b14c0(float param_1,u64 param_2)

{
  ((code)FUN_004b1700)(param_1 * *(float *)((int)param_2 + 4) + *(float *)((int)param_2 + 8) + 0.0);
  return param_2;
}
// FUN_004B1500 NONMATCHING
u64 FUN_004b1500(u64 param_1,u64 param_2,int param_3)

{
  u32 uVar1;
  u32 *puVar2;
  
  puVar2 = (u32 *)param_1;
  uVar1 = FUN_004c2090(*puVar2);
  while ((0 < param_3 && ((u32 *)puVar2[5] != (u32 *)0x0))) {
    puVar2[2] = *(u32 *)puVar2[5];
    FUN_004b2300(*(u32 *)(puVar2[5] + 4),param_2);
    puVar2[4] = puVar2[5];
    if ((u32)puVar2[5] < (u32)puVar2[6]) {
      puVar2[5] = puVar2[5] + 8;
    }
    else {
      puVar2[5] = 0;
    }
    param_3 = param_3 + -1;
  }
  while ((param_3 < 0 && ((u32 *)puVar2[4] != (u32 *)0x0))) {
    puVar2[2] = *(u32 *)puVar2[4];
    FUN_004b2300(*(u32 *)(puVar2[4] + 4),param_2);
    puVar2[5] = puVar2[4];
    if (uVar1 < (u32)puVar2[4]) {
      puVar2[4] = puVar2[4] + -8;
    }
    else {
      puVar2[4] = 0;
    }
    param_3 = param_3 + -1;
  }
  return param_1;
}
// FUN_004B1620 NONMATCHING
u64 FUN_004b1620(u64 param_1,u64 param_2)

{
  int iVar1;
  long lVar2;
  int iVar3;
  float fVar4;
  
  lVar2 = ((code)FUN_004b1b90)();
  iVar3 = (int)param_1;
  if (lVar2 == 0) {
    fVar4 = 0.0;
  }
  else {
    if ((*(float **)(iVar3 + 0x10) == (float *)0x0) || (*(float **)(iVar3 + 0x14) == (float *)0x0))
    {
      fVar4 = 0.0;
      iVar1 = *(int *)(iVar3 + 0x14);
      goto LAB_004b1678;
    }
    fVar4 = **(float **)(iVar3 + 0x10);
    fVar4 = (*(float *)(iVar3 + 8) - fVar4) / (**(float **)(iVar3 + 0x14) - fVar4);
  }
  iVar1 = *(int *)(iVar3 + 0x14);
LAB_004b1678:
  if (iVar1 == 0) {
    if (*(int *)(iVar3 + 0x18) == 0) {
      return 0;
    }
    lVar2 = FUN_004b2810(fVar4,*(u32 *)(*(int *)(iVar3 + 0x18) + 4),param_2);
  }
  else {
    lVar2 = FUN_004b2810(fVar4,*(u32 *)(iVar1 + 4),param_2);
  }
  if (lVar2 == 0) {
    return 0;
  }
  return param_1;
}
// FUN_004B1700 NONMATCHING
u64 FUN_004b1700(float param_1,u64 param_2,u64 param_3)

{
  bool bVar1;
  float *pfVar2;
  int iVar3;
  u32 uVar4;
  float fVar5;
  float fVar6;
  
  iVar3 = (int)param_2;
  fVar6 = 0.0;
  bVar1 = false;
  if (param_1 <= *(float *)(iVar3 + 8)) {
    if (*(float *)(iVar3 + 8) <= param_1) {
      return param_2;
    }
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = 1;
  }
  if (param_1 < 0.0) {
    bVar1 = true;
    fVar6 = param_1 / *(float *)(iVar3 + 4);
    param_1 = 0.0;
  }
  else {
    fVar5 = **(float **)(iVar3 + 0x18);
    if (fVar5 < param_1) {
      bVar1 = true;
      fVar6 = (param_1 - fVar5) / *(float *)(iVar3 + 4);
      param_1 = fVar5;
    }
  }
  pfVar2 = *(float **)(iVar3 + 0x14);
  while (((pfVar2 != (float *)0x0 && (*pfVar2 <= param_1)) ||
         ((*(float **)(iVar3 + 0x10) != (float *)0x0 && (param_1 < **(float **)(iVar3 + 0x10)))))) {
    FUN_004b1500(param_2,param_3,uVar4);
    pfVar2 = *(float **)(iVar3 + 0x14);
  }
  *(float *)(iVar3 + 8) = param_1;
  if ((bVar1) && (pcGpffffbbac != 0)) {
    (*pcGpffffbbac)(fVar6,param_2,param_3);
  }
  return param_2;
}
// FUN_004B1870 NONMATCHING
void FUN_004b1870(u64 param_1,u64 param_2,int param_3)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  u32 *puVar4;
  u32 uVar5;
  
  puVar4 = (u32 *)param_1;
  iVar1 = FUN_004c2090(*puVar4);
  uVar5 = iVar1 + param_3 * 8;
  if (uVar5 < (u32)puVar4[4]) {
    lVar3 = FUN_004c2120(*puVar4);
    puVar4[2] = 0;
    if (lVar3 < 1) {
      puVar4[4] = 0;
      puVar4[5] = 0;
      puVar4[6] = 0;
    }
    else {
      puVar4[4] = 0;
      uVar2 = FUN_004c21b0(*puVar4,0);
      puVar4[5] = uVar2;
      uVar2 = FUN_004c21b0(*puVar4,(int)lVar3 + -1);
      puVar4[6] = uVar2;
      FUN_004b2300(*(u32 *)(puVar4[5] + 4),param_2);
    }
    FUN_004b1500(param_1,param_2,1);
    iVar1 = puVar4[4];
  }
  else {
    iVar1 = puVar4[4];
  }
  if (iVar1 != 0) {
    iVar1 = uVar5 - iVar1;
    param_3 = iVar1 >> 3;
    if (iVar1 < 0) {
      param_3 = iVar1 + 7 >> 3;
    }
  }
  FUN_004b1500(param_1,param_2,param_3);
  return;
}
// FUN_004B1990 NONMATCHING
u64 FUN_004b1990(u64 param_1,code *param_2,u64 param_3,u64 param_4)

{
  u32 *puVar1;
  int iVar2;
  u32 *puVar3;
  
  puVar1 = (u32 *)FUN_004c2090(*(u32 *)param_1);
  iVar2 = FUN_004c2120(*(u32 *)param_1);
  puVar3 = puVar1 + iVar2 * 2;
  for (; puVar1 != puVar3; puVar1 = puVar1 + 2) {
    (*param_2)(*puVar1,param_1,param_3,puVar1[1],param_4);
  }
  return param_1;
}
#pragma optimization_level 3
// FUN_004B1A30
u32 FUN_004b1a30(u32 *param_1)

{
  return FUN_004c2120(*param_1);
}
#pragma optimization_level 2
#pragma schedule on
// FUN_004B1A40
u32 FUN_004b1a40(u32 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_004c21b0(*param_1);
  return *(u32 *)(iVar1 + 4);
}
#pragma schedule off
// FUN_004B1A60
#pragma optimization_level 3
f32 FUN_004b1a60(f32 *param_1)
{
  return param_1[2];
}
#pragma optimization_level 3
// FUN_004B1A70
f32 FUN_004b1a70(int param_1)

{
  return **(f32 **)(param_1 + 0x18);
}
#pragma optimization_level 2
// FUN_004B1A80 NONMATCHING
int FUN_004b1a80(u32 *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1[4] == 0) {
    iVar2 = -1;
  }
  else {
    iVar1 = FUN_004c2090(*param_1);
    iVar1 = param_1[4] - iVar1;
    iVar2 = iVar1 >> 3;
    if (iVar1 < 0) {
      iVar2 = iVar1 + 7 >> 3;
    }
  }
  return iVar2;
}
#pragma schedule on
// FUN_004B1AE0
f32 FUN_004b1ae0(int param_1)
{
  f32 *pfVar1;
  
  pfVar1 = *(f32 **)(param_1 + 0x10);
  if (pfVar1 != (f32 *)0x0) {
    return *pfVar1;
  }
  return 0.0f;
}
#pragma schedule off
#pragma optimization_level 3
#pragma schedule on
// FUN_004B1B00 NONMATCHING
int FUN_004b1b00(u32 *param_1)
{
  int iVar1;
  int iVar2;
  
  if (param_1[5] != 0) {
    iVar1 = FUN_004c2090(*param_1);
    iVar1 = param_1[5] - iVar1;
    iVar2 = iVar1 >> 3;
    if (iVar1 < 0) {
      iVar2 = iVar1 + 7 >> 3;
    }
  }
  else {
    iVar2 = FUN_004c2120(*param_1);
  }
  return iVar2;
}
#pragma schedule off
#pragma optimization_level 2
#pragma schedule on
// FUN_004B1B60 NONMATCHING
f32 FUN_004b1b60(int param_1)
{
  f32 *ptr;

  ptr = *(f32 **)(param_1 + 0x14);
  if (ptr == (f32 *)0x0) {
    ptr = *(f32 **)(param_1 + 0x18);
  }
  return *ptr;
}
#pragma schedule off
// FUN_004B1B90
#pragma optimization_level 3
bool FUN_004b1b90(int param_1)
{
  return (*(u32 *)(param_1 + 0xc) & 2) != 0;
}
#pragma optimization_level 2
// FUN_004B1BA0 NONMATCHING
u64 FUN_004b1ba0(int param_1)

{
  u32 *puVar1;
  int iVar2;
  u32 *puVar3;
  u64 uVar4;
  long lVar5;
  u64 uVar6;
  u32 *puVar7;
  
  uVar4 = FUN_004c1d50(0xa0,0x301a9);
  lVar5 = FUN_004c2120(*(u32 *)(param_1 + 4));
  if (lVar5 != 0) {
    uVar6 = FUN_004c2120(*(u32 *)(param_1 + 4));
    FUN_004c1f70(uVar4,uVar6,0x301a9);
    puVar1 = (u32 *)FUN_004c2090(uVar4);
    iVar2 = FUN_004c2120(uVar4);
    puVar7 = puVar1 + iVar2 * 0x28;
    puVar3 = (u32 *)FUN_004c2090(*(u32 *)(param_1 + 4));
    for (; puVar1 != puVar7; puVar1 = puVar1 + 0x28) {
      *puVar1 = 0;
      puVar1[2] = 0;
      puVar1[0x14] = 0;
      puVar1[0x19] = 0;
      puVar1[0x1e] = 0;
      puVar1[0x23] = 0;
      puVar1[1] = *puVar3;
      puVar3 = puVar3 + 1;
    }
  }
  return uVar4;
}
// FUN_004B1C80 NONMATCHING
bool FUN_004b1c80(long param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = (int)param_1;
    if (*(int *)(iVar1 + 4) == 0) {
      (*DAT_0096017c)(*(u32 *)(iVar1 + 8));
    }
    else {
      FUN_004c20b0(*(u32 *)(iVar1 + 8));
    }
    (*DAT_0096018c)(0x95fb4c,param_1);
  }
  return param_1 != 0;
}
// FUN_004B1D00 NONMATCHING
u64 FUN_004b1d00(u64 param_1,u64 param_2)

{
  u32 *puVar1;
  u32 *puVar2;
  long lVar3;
  u32 *puVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 *puVar9;
  u32 *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  u32 *puVar14;
  u32 *puVar15;
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
  u32 uStack_2c;
  int iStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u8 auStack_10 [4];
  u32 uStack_c;
  int iStack_8;
  
  puVar1 = (u32 *)0x0;
  lVar3 = FUN_004c5250(param_1,auStack_10,0xc);
  if (lVar3 == 0xc) {
    puVar9 = (u32 *)param_2;
    *puVar9 = uStack_c;
    iVar13 = 0;
    if (iStack_8 != 0) {
      puVar1 = (u32 *)(*DAT_00960178)(iStack_8 * 0xa0,0x101a9);
      if (puVar1 == (u32 *)0x0) {
        return 0;
      }
      iVar11 = 0;
      iVar12 = iVar13;
      puVar10 = puVar1;
      if (0 < iStack_8) {
        do {
          lVar3 = FUN_004c5250(param_1,&uStack_18,8);
          if (lVar3 == 8) {
            uStack_30 = uStack_18;
            puVar15 = &uStack_30;
            uStack_2c = uStack_14;
          }
          else {
            puVar15 = (u32 *)0x0;
          }
          if (puVar15 == (u32 *)0x0) {
            (*DAT_0096017c)(puVar1);
            return 0;
          }
          iVar13 = iVar12 + 0x10;
          puVar10[1] = uStack_2c;
          *puVar10 = 1;
          puVar10[2] = 0;
          puVar10[0x14] = 0;
          puVar10[0x19] = 0;
          puVar10[0x1e] = 0;
          puVar10[0x23] = 0;
          if ((uStack_30 & 1) != 0) {
            lVar3 = FUN_004c1600(param_1,0xd,0,0);
            if (lVar3 == 0) {
              puVar4 = (u32 *)0x0;
            }
            else {
              lVar3 = FUN_004c19f0(param_1,puVar10 + 4);
              if (lVar3 == 0) {
                puVar4 = (u32 *)0x0;
              }
              else {
                puVar4 = puVar10 + 4;
              }
            }
            if (puVar4 == (u32 *)0x0) {
              (*DAT_0096017c)(puVar1);
              return 0;
            }
            iVar13 = iVar12 + 0x50;
            puVar10[2] = 1;
          }
          if ((uStack_30 & 2) != 0) {
            lVar3 = FUN_004c5250(param_1,&uStack_40,0x10);
            if (lVar3 == 0x10) {
              puVar4 = puVar10 + 0x15;
              puVar10[0x15] = uStack_40;
              puVar10[0x16] = uStack_3c;
              puVar10[0x17] = uStack_38;
              puVar10[0x18] = uStack_34;
            }
            else {
              puVar4 = (u32 *)0x0;
            }
            if (puVar4 == (u32 *)0x0) {
              (*DAT_0096017c)(puVar1);
              return 0;
            }
            iVar13 = iVar13 + 0x10;
            puVar10[0x14] = 1;
          }
          if ((uStack_30 & 4) != 0) {
            lVar3 = FUN_004c5250(param_1,&uStack_50,0x10);
            if (lVar3 == 0x10) {
              puVar4 = puVar10 + 0x1a;
              puVar10[0x1a] = uStack_50;
              puVar10[0x1b] = uStack_4c;
              puVar10[0x1c] = uStack_48;
              puVar10[0x1d] = uStack_44;
            }
            else {
              puVar4 = (u32 *)0x0;
            }
            if (puVar4 == (u32 *)0x0) {
              (*DAT_0096017c)(puVar1);
              return 0;
            }
            iVar13 = iVar13 + 0x10;
            puVar10[0x19] = 1;
          }
          if ((uStack_30 & 8) != 0) {
            lVar3 = FUN_004c5250(param_1,&iStack_20,8);
            if (lVar3 == 8) {
              puVar4 = puVar10 + 0x1f;
              puVar10[0x1f] = (u32)(iStack_20 != 0);
              puVar10[0x20] = uStack_1c;
            }
            else {
              puVar4 = (u32 *)0x0;
            }
            if (puVar4 == (u32 *)0x0) {
              (*DAT_0096017c)(puVar1);
              return 0;
            }
            iVar13 = iVar13 + 0x10;
            puVar10[0x1e] = 1;
          }
          if ((uStack_30 & 0x10) != 0) {
            lVar3 = FUN_004c5250(param_1,&uStack_60,0x10);
            if (lVar3 == 0x10) {
              puVar4 = puVar10 + 0x24;
              puVar10[0x24] = uStack_60;
              puVar10[0x25] = uStack_5c;
              puVar10[0x26] = uStack_58;
              puVar10[0x27] = uStack_54;
            }
            else {
              puVar4 = (u32 *)0x0;
            }
            if (puVar4 == (u32 *)0x0) {
              (*DAT_0096017c)(puVar1);
              return 0;
            }
            iVar13 = iVar13 + 0x10;
            puVar10[0x23] = 1;
          }
          iVar11 = iVar11 + 1;
          iVar12 = iVar13;
          puVar10 = puVar10 + 0x28;
        } while (iVar11 < iStack_8);
      }
    }
    puVar2 = (u32 *)(*DAT_00960178)(iVar13 + 0x10,0x301a9);
    iVar13 = 0;
    puVar15 = puVar2;
    puVar10 = puVar1;
    puVar14 = puVar2;
    if (0 < iStack_8) {
      do {
        uVar8 = 2;
        uVar7 = 4;
        uVar6 = 8;
        uVar5 = 0x10;
        if (puVar10[0x14] == 0) {
          uVar8 = 0;
        }
        if (puVar10[0x19] == 0) {
          uVar7 = 0;
        }
        if (puVar10[0x1e] == 0) {
          uVar6 = 0;
        }
        if (puVar10[0x23] == 0) {
          uVar5 = 0;
        }
        *puVar14 = uVar5 | uVar6 | uVar7 | puVar10[2] != 0 | uVar8;
        puVar14[1] = puVar10[1];
        puVar15 = puVar14 + 4;
        if (puVar10[2] != 0) {
          FUN_00521250(puVar15,puVar10 + 4,0x40);
          puVar15 = puVar14 + 0x14;
        }
        if (puVar10[0x14] != 0) {
          FUN_00521250(puVar15,puVar10 + 0x15,0x10);
          puVar15 = puVar15 + 4;
        }
        if (puVar10[0x19] != 0) {
          FUN_00521250(puVar15,puVar10 + 0x1a,0x10);
          puVar15 = puVar15 + 4;
        }
        if (puVar10[0x1e] != 0) {
          FUN_00521250(puVar15,puVar10 + 0x1f,0x10);
          puVar15 = puVar15 + 4;
        }
        if (puVar10[0x23] != 0) {
          FUN_00521250(puVar15,puVar10 + 0x24,0x10);
          puVar15 = puVar15 + 4;
        }
        iVar13 = iVar13 + 1;
        puVar10 = puVar10 + 0x28;
        puVar14 = puVar15;
      } while (iVar13 < iStack_8);
    }
    *puVar15 = 0x20;
    puVar9[1] = 0;
    puVar9[2] = (u32)(puVar2);
    if (puVar1 != (u32 *)0x0) {
      (*DAT_0096017c)(puVar1);
    }
  }
  else {
    param_2 = 0;
  }
  return param_2;
}
// FUN_004B22B0 NONMATCHING
void FUN_004b22b0(u64 param_1)

{
  u64 uVar1;
  
  uVar1 = (*DAT_00960188)(0x95fb4c,0x301b0);
  FUN_004b1d00(param_1,uVar1);
  return;
}
// FUN_004B2300 NONMATCHING
u64 FUN_004b2300(u64 param_1,u64 param_2)

{
  u32 *puVar1;
  u32 uVar2;
  u32 *puVar3;
  u32 uVar4;
  u32 *puVar5;
  
  puVar1 = *(u32 **)((int)param_1 + 8);
  uVar2 = *puVar1;
  while ((uVar2 & 0x20) == 0) {
    puVar3 = (u32 *)FUN_004c21b0(*(u32 *)((int)param_2 + 0xc),puVar1[1]);
    puVar5 = puVar1 + 4;
    if ((*puVar1 & 1) != 0) {
      FUN_00521250(puVar3 + 4,puVar5,0x40);
      puVar5 = puVar1 + 0x14;
      puVar3[2] = 1;
      *puVar3 = 1;
    }
    if ((*puVar1 & 2) != 0) {
      FUN_00521250(puVar3 + 0x15,puVar5,0x10);
      puVar5 = puVar5 + 4;
      puVar3[0x14] = 1;
      *puVar3 = 1;
    }
    if ((*puVar1 & 4) != 0) {
      FUN_00521250(puVar3 + 0x1a,puVar5,0x10);
      puVar5 = puVar5 + 4;
      puVar3[0x19] = 1;
      *puVar3 = 1;
    }
    if ((*puVar1 & 8) != 0) {
      FUN_00521250(puVar3 + 0x1f,puVar5,0x10);
      puVar5 = puVar5 + 4;
      puVar3[0x1e] = 1;
      *puVar3 = 1;
    }
    if ((*puVar1 & 0x10) != 0) {
      FUN_00521250(puVar3 + 0x24,puVar5,0x10);
      puVar3[0x23] = 1;
      *puVar3 = 1;
      uVar4 = ((code)FUN_004b2ba0)(param_2,puVar3[0x24]);
      puVar3[0x24] = uVar4;
      uVar4 = ((code)FUN_004b2ba0)(param_2,puVar3[0x25]);
      puVar3[0x25] = uVar4;
      puVar5 = puVar5 + 4;
    }
    puVar1 = puVar5;
    uVar2 = *puVar5;
  }
  return param_1;
}
// FUN_004B24C0 NONMATCHING
u64 FUN_004b24c0(float param_1,u64 param_2,float *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)param_2;
  iVar1 = *(int *)(iVar2 + 4);
  *(float *)(iVar1 + 0x40) = param_3[0xc] - *(float *)(iVar2 + 0x40);
  *(float *)(iVar1 + 0x44) = param_3[0xd] - *(float *)(iVar2 + 0x44);
  *(float *)(iVar1 + 0x48) = param_3[0xe] - *(float *)(iVar2 + 0x48);
  *(float *)(iVar1 + 0x40) = *(float *)(iVar1 + 0x40) * param_1;
  *(float *)(iVar1 + 0x44) = *(float *)(iVar1 + 0x44) * param_1;
  *(float *)(iVar1 + 0x48) = *(float *)(iVar1 + 0x48) * param_1;
  *(float *)(iVar1 + 0x40) = *(float *)(iVar1 + 0x40) + *(float *)(iVar2 + 0x40);
  *(float *)(iVar1 + 0x44) = *(float *)(iVar1 + 0x44) + *(float *)(iVar2 + 0x44);
  *(float *)(iVar1 + 0x48) = *(float *)(iVar1 + 0x48) + *(float *)(iVar2 + 0x48);
  iVar1 = *(int *)(iVar2 + 4);
  *(float *)(iVar1 + 0x10) = *param_3 - *(float *)(iVar2 + 0x10);
  *(float *)(iVar1 + 0x14) = param_3[1] - *(float *)(iVar2 + 0x14);
  *(float *)(iVar1 + 0x18) = param_3[2] - *(float *)(iVar2 + 0x18);
  *(float *)(iVar1 + 0x10) = *(float *)(iVar1 + 0x10) * param_1;
  *(float *)(iVar1 + 0x14) = *(float *)(iVar1 + 0x14) * param_1;
  *(float *)(iVar1 + 0x18) = *(float *)(iVar1 + 0x18) * param_1;
  *(float *)(iVar1 + 0x10) = *(float *)(iVar1 + 0x10) + *(float *)(iVar2 + 0x10);
  *(float *)(iVar1 + 0x14) = *(float *)(iVar1 + 0x14) + *(float *)(iVar2 + 0x14);
  *(float *)(iVar1 + 0x18) = *(float *)(iVar1 + 0x18) + *(float *)(iVar2 + 0x18);
  iVar1 = *(int *)(iVar2 + 4);
  *(float *)(iVar1 + 0x20) = param_3[4] - *(float *)(iVar2 + 0x20);
  *(float *)(iVar1 + 0x24) = param_3[5] - *(float *)(iVar2 + 0x24);
  *(float *)(iVar1 + 0x28) = param_3[6] - *(float *)(iVar2 + 0x28);
  *(float *)(iVar1 + 0x20) = *(float *)(iVar1 + 0x20) * param_1;
  *(float *)(iVar1 + 0x24) = *(float *)(iVar1 + 0x24) * param_1;
  *(float *)(iVar1 + 0x28) = *(float *)(iVar1 + 0x28) * param_1;
  *(float *)(iVar1 + 0x20) = *(float *)(iVar1 + 0x20) + *(float *)(iVar2 + 0x20);
  *(float *)(iVar1 + 0x24) = *(float *)(iVar1 + 0x24) + *(float *)(iVar2 + 0x24);
  *(float *)(iVar1 + 0x28) = *(float *)(iVar1 + 0x28) + *(float *)(iVar2 + 0x28);
  FUN_004c2f10(*(int *)(iVar2 + 4) + 0x10);
  FUN_004ae060(*(u32 *)(iVar2 + 4));
  *(u32 *)(iVar2 + 8) = 0;
  return param_2;
}
// FUN_004B26A0 NONMATCHING
void FUN_004b26a0(u32 *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = FUN_004c2120(param_1[3]);
  piVar2 = (int *)FUN_004c2090(param_1[3]);
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      if (*piVar2 == 1) {
        if (piVar2[2] != 0) {
          FUN_004ae020(piVar2[1],piVar2 + 4);
          piVar2[2] = 0;
        }
        if (piVar2[0x14] != 0) {
          FUN_004ae150(piVar2[1],piVar2 + 0x15);
          piVar2[0x14] = 0;
        }
        if (piVar2[0x19] != 0) {
          FUN_004ae110(piVar2[1],piVar2 + 0x1a);
          piVar2[0x19] = 0;
        }
        if (piVar2[0x1e] != 0) {
          if (*(int *)(piVar2[1] + 4) != piVar2[0x20]) {
            FUN_004ae1d0();
            FUN_004aef50(*param_1);
          }
          FUN_004adfd0(piVar2[1],piVar2[0x1f]);
          piVar2[0x1e] = 0;
        }
        if ((piVar2[0x23] != 0) && (piVar2[0x24] != 0)) {
          piVar2[0x23] = 0;
        }
        *piVar2 = 0;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 0x28;
    } while (iVar3 < iVar1);
  }
  return;
}
// FUN_004B2810 NONMATCHING
u64 FUN_004b2810(float param_1,u64 param_2,u64 param_3)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  u64 uVar4;
  float *pfVar5;
  int iVar6;
  
  if ((0.0 < param_1) && (param_1 < 1.0)) {
    pfVar2 = *(float **)((int)param_2 + 8);
    fVar3 = *pfVar2;
    while (((u32)fVar3 & 0x20) == 0) {
      uVar4 = FUN_004c21b0(*(u32 *)((int)param_3 + 0xc),pfVar2[1]);
      pfVar5 = pfVar2 + 4;
      if (((u32)*pfVar2 & 1) != 0) {
        FUN_004b24c0(param_1,uVar4,pfVar5);
        pfVar5 = pfVar2 + 0x14;
      }
      iVar6 = (int)uVar4;
      if (((u32)*pfVar2 & 2) != 0) {
        *(float *)(*(int *)(iVar6 + 4) + 0xa0) =
             (param_1 * (*pfVar5 - *(float *)(iVar6 + 0x54)) + *(float *)(iVar6 + 0x54) + 0.0) *
             255.0;
        *(float *)(*(int *)(iVar6 + 4) + 0xa4) =
             (param_1 * (pfVar5[1] - *(float *)(iVar6 + 0x58)) + *(float *)(iVar6 + 0x58) + 0.0) *
             255.0;
        *(float *)(*(int *)(iVar6 + 4) + 0xa8) =
             (param_1 * (pfVar5[2] - *(float *)(iVar6 + 0x5c)) + *(float *)(iVar6 + 0x5c) + 0.0) *
             255.0;
        pfVar1 = pfVar5 + 3;
        pfVar5 = pfVar5 + 4;
        *(float *)(*(int *)(iVar6 + 4) + 0xac) =
             (param_1 * (*pfVar1 - *(float *)(iVar6 + 0x60)) + *(float *)(iVar6 + 0x60) + 0.0) *
             255.0;
        *(u32 *)(*(int *)(iVar6 + 4) + 8) = *(u32 *)(*(int *)(iVar6 + 4) + 8) | 8;
        *(u32 *)(iVar6 + 0x50) = 0;
      }
      if (((u32)*pfVar2 & 4) != 0) {
        *(float *)(*(int *)(iVar6 + 4) + 0x90) =
             param_1 * (*pfVar5 - *(float *)(iVar6 + 0x68)) + *(float *)(iVar6 + 0x68) + 0.0;
        *(float *)(*(int *)(iVar6 + 4) + 0x94) =
             param_1 * (pfVar5[1] - *(float *)(iVar6 + 0x6c)) + *(float *)(iVar6 + 0x6c) + 0.0;
        *(float *)(*(int *)(iVar6 + 4) + 0x98) =
             param_1 * (pfVar5[2] - *(float *)(iVar6 + 0x70)) + *(float *)(iVar6 + 0x70) + 0.0;
        pfVar1 = pfVar5 + 3;
        pfVar5 = pfVar5 + 4;
        *(float *)(*(int *)(iVar6 + 4) + 0x9c) =
             param_1 * (*pfVar1 - *(float *)(iVar6 + 0x74)) + *(float *)(iVar6 + 0x74) + 0.0;
        *(u32 *)(*(int *)(iVar6 + 4) + 8) = *(u32 *)(*(int *)(iVar6 + 4) + 8) | 8;
        *(u32 *)(iVar6 + 100) = 0;
      }
      if (((u32)*pfVar2 & 8) != 0) {
        pfVar5 = pfVar5 + 4;
      }
      if (((u32)*pfVar2 & 0x10) != 0) {
        *(u32 *)(iVar6 + 0x8c) = 0;
        pfVar5 = pfVar5 + 4;
      }
      pfVar2 = pfVar5;
      fVar3 = *pfVar5;
    }
  }
  ((code)FUN_004b26a0)(param_3);
  return param_2;
}
#pragma schedule on
// FUN_004B2A90
u32 FUN_004b2a90(u32 param_1,u64 param_2,u64 param_3)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)FUN_004c1e70(param_3,0x301a9);
  *puVar1 = param_1;
  return param_1;
}
#pragma schedule off
#pragma schedule on
// FUN_004B2AD0 NONMATCHING
int FUN_004b2ad0(int param_1,u32 param_2)

{
  u32 uVar1;
  u32 *puVar2;
  
  puVar2 = (u32 *)param_1;
  *puVar2 = param_2;
  uVar1 = FUN_004c1d50(4,0x301a9);
  puVar2[1] = uVar1;
  if (puVar2[1] == 0) {
    param_1 = 0;
  }
  else {
    FUN_004aeb60(*puVar2,0x4b2a90);
    puVar2[2] = 0;
    uVar1 = FUN_004b1ba0(param_1);
    puVar2[3] = uVar1;
  }
  return param_1;
}
#pragma schedule off
// FUN_004B2B40 NONMATCHING
u64 FUN_004b2b40(u64 param_1)

{
  u32 *puVar1;
  
  puVar1 = (u32 *)param_1;
  *puVar1 = 0;
  if (puVar1[1] != 0) {
    FUN_004c20b0();
  }
  puVar1[1] = 0;
  if (puVar1[3] != 0) {
    FUN_004c20b0();
  }
  puVar1[3] = 0;
  return param_1;
}
#pragma schedule on
// FUN_004B2BA0
u32 FUN_004b2ba0(int param_1)

{
  u32 *puVar1;
  
  puVar1 = (u32 *)FUN_004c21b0(*(u32 *)(param_1 + 4));
  return *puVar1;
}
#pragma schedule off
#pragma optimization_level 3
// FUN_004B2BC0
void FUN_004b2bc0(void)
{
  FUN_004c1d50(1,0x301a9);
}
#pragma optimization_level 2
#pragma schedule on
// FUN_004B2BD0
u32 FUN_004b2bd0(void)
{
  FUN_004c20b0();
  return 1;
}
#pragma schedule off
// FUN_004B2BF0 NONMATCHING
u64 FUN_004b2bf0(u64 param_1,long param_2,u64 param_3)

{
  u64 uVar1;
  long lVar2;
  
  uVar1 = FUN_004c2120();
  lVar2 = FUN_004c1f70(param_1,param_3,0x301a9);
  if (lVar2 == 0) {
    uVar1 = 0xffffffffffffffff;
  }
  else if (param_2 != 0) {
    FUN_00521250(lVar2,param_2,param_3);
  }
  return uVar1;
}



// FUN_004B2C70
#pragma optimization_level 3
int thunk_FUN_004c21b0(int *param_1,int param_2)

{
  extern int FUN_004c21b0(int *param_1,int param_2);
  return FUN_004c21b0(param_1,param_2);
}
#pragma optimization_level 2
// FUN_004B2C80 NONMATCHING
long FUN_004b2c80(int param_1,long param_2,u64 param_3)

{
  int iVar1;
  u32 *puVar2;
  int iVar3;
  long lVar4;
  u64 uVar5;
  int iVar6;
  int iStack_4;
  
  if (param_2 == 0) {
    param_2 = (*DAT_00960188)(0x95fabc,0x301a9);
    if (param_2 == 0) {
      param_2 = 0;
    }
    else {
      puVar2 = (u32 *)param_2;
      *puVar2 = 0;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0;
      puVar2[3] = 0;
      if (param_2 == 0) {
        uRam00000000 = 0;
        uRam00000004 = 0xffffffff;
        uRam00000008 = 0;
        uRam0000000c = 0;
        (*DAT_0096018c)(0x95fabc,0);
        param_2 = 0;
      }
    }
    if (param_2 == 0) {
      return 0;
    }
  }
  lVar4 = FUN_004c1910(param_3,&iStack_4,4);
  if (lVar4 == 0) {
    return 0;
  }
  iVar6 = (int)param_2;
  if (iStack_4 < 1) {
    *(u32 *)(iVar6 + 4) = 0xffffffff;
  }
  else {
    lVar4 = ((code)FUN_004b2bf0)(*(u32 *)(param_1 + 0x1c),0);
    iVar1 = iStack_4;
    if (lVar4 == -1) {
      return 0;
    }
    uVar5 = (u64)thunk_FUN_004c21b0((int *)*(u32 *)(param_1 + 0x1c),lVar4);
    iVar3 = FUN_004c5250(param_3,uVar5,iStack_4);
    if (iVar1 != iVar3) {
      return 0;
    }
    *(int *)(iVar6 + 4) = (int)lVar4;
  }
  lVar4 = FUN_004c1910(param_3,param_2,4);
  if (lVar4 == 0) {
    param_2 = 0;
  }
  else {
    lVar4 = FUN_004c1910(param_3,iVar6 + 8,4);
    if (lVar4 == 0) {
      param_2 = 0;
    }
  }
  return param_2;
}
#pragma optimization_level 3
// FUN_004B2E20 NONMATCHING
#pragma push
#pragma opt_rebuildconditionals off
int FUN_004b2e20(int param_1)
{
  u32 uVar1;

  uVar1 = FUN_004c1d50(0x10,0x301a9);
  *(volatile u32 *)((int)param_1 + 0xc) = uVar1;
  if (*(volatile int *)((int)param_1 + 0xc) != 0) goto done;
  param_1 = 0;
done:
  return param_1;
}
#pragma pop
#pragma optimization_level 2
#pragma schedule off
// FUN_004B2E70 NONMATCHING
u64 FUN_004b2e70(u64 param_1)

{
  u32 *puVar1;
  long lVar2;
  int iVar3;
  u32 *puVar4;
  
  iVar3 = (int)param_1;
  if (*(int *)(iVar3 + 0xc) != 0) {
    lVar2 = FUN_004c2120();
    if (0 < lVar2) {
      puVar1 = (u32 *)FUN_004c2090(*(u32 *)(iVar3 + 0xc));
      puVar4 = puVar1 + (int)lVar2 * 4;
      for (; puVar1 != puVar4; puVar1 = puVar1 + 4) {
        *puVar1 = 0;
        puVar1[1] = 0xffffffff;
        puVar1[2] = 0;
        puVar1[3] = 0;
      }
    }
    FUN_004c20b0(*(u32 *)(iVar3 + 0xc));
    *(u32 *)(iVar3 + 0xc) = 0;
  }
  return param_1;
}
// FUN_004B2F10 NONMATCHING
u64 FUN_004b2f10(u64 param_1,u64 param_2)

{
  u32 *puVar1;
  u32 uVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  u32 *puVar6;
  int iStack_4;
  
  lVar3 = FUN_004c1910(param_2,&iStack_4,4);
  if (lVar3 == 0) {
    param_1 = 0;
  }
  else if (0 < iStack_4) {
    iVar5 = (int)param_1;
    iVar4 = *(int *)(iVar5 + 0xc);
    if (iVar4 == 0) {
      uVar2 = FUN_004c1d50(0x10,0x301a9);
      *(u32 *)(iVar5 + 0xc) = uVar2;
      iVar4 = *(int *)(iVar5 + 0xc);
    }
    if (iVar4 == 0) {
      param_1 = 0;
    }
    else {
      puVar1 = (u32 *)FUN_004c1f70(iVar4,iStack_4,0x301a9);
      if (puVar1 == (u32 *)0x0) {
        param_1 = 0;
      }
      else {
        puVar6 = puVar1 + iStack_4 * 4;
        for (; puVar1 != puVar6; puVar1 = puVar1 + 4) {
          *puVar1 = 0;
          puVar1[1] = 0xffffffff;
          puVar1[2] = 0;
          puVar1[3] = 0;
          lVar3 = (long)(((code)FUN_004b2c80)(param_1,puVar1,param_2));
          if (lVar3 == 0) {
            return 0;
          }
        }
      }
    }
  }
  return param_1;
}
// FUN_004B3030 NONMATCHING
int FUN_004b3030(int param_1,long param_2)

{
  int iVar1;
  long lVar2;
  
  iVar1 = 0;
  if (((*(int *)(param_1 + 0xc) != 0) && (lVar2 = FUN_004c2120(), 0 < lVar2)) && (param_2 < lVar2))
  {
    iVar1 = FUN_004c2090(*(u32 *)(param_1 + 0xc));
    iVar1 = iVar1 + (int)param_2 * 0x10;
  }
  return iVar1;
}
#pragma optimization_level 3
// FUN_004B30A0
u32 * FUN_004b30a0(u32 *param_1)

{
  int iVar2;
  u32 *puVar1;
  
  iVar2 = 0;
  puVar1 = (u32 *)param_1;
  *puVar1 = 0xffffffff;
  puVar1[1] = 0xffffffff;
  puVar1[2] = 0;
  puVar1[3] = 0;
  do {
    puVar1[4] = 0xffffffff;
    iVar2 = iVar2 + 8;
    puVar1[5] = 0xffffffff;
    puVar1[6] = 0xffffffff;
    puVar1[7] = 0xffffffff;
    puVar1[8] = 0xffffffff;
    puVar1[9] = 0xffffffff;
    puVar1[10] = 0xffffffff;
    puVar1[0xb] = 0xffffffff;
    puVar1 = puVar1 + 8;
  } while (iVar2 < 0x20);
  return param_1;
}
// FUN_004B3100
u32 * FUN_004b3100(u32 *param_1)

{
  int iVar2;
  u32 *puVar1;
  
  iVar2 = 0;
  puVar1 = (u32 *)param_1;
  *puVar1 = 0xffffffff;
  puVar1[1] = 0xffffffff;
  puVar1[2] = 0;
  puVar1[3] = 0;
  do {
    puVar1[4] = 0xffffffff;
    iVar2 = iVar2 + 8;
    puVar1[5] = 0xffffffff;
    puVar1[6] = 0xffffffff;
    puVar1[7] = 0xffffffff;
    puVar1[8] = 0xffffffff;
    puVar1[9] = 0xffffffff;
    puVar1[10] = 0xffffffff;
    puVar1[0xb] = 0xffffffff;
    puVar1 = puVar1 + 8;
  } while (iVar2 < 0x20);
  return param_1;
}
#pragma optimization_level 2
// FUN_004B3160 NONMATCHING
long FUN_004b3160(long param_1,u64 param_2)

{
  u32 *puVar1;
  u32 *puVar2;
  long lVar3;
  int iVar4;
  u32 *puVar5;
  int iVar6;
  int iStack_c;
  u8 auStack_8 [4];
  int iStack_4;
  
  if (param_1 == 0) {
    param_1 = FUN_004b43c0();
  }
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    lVar3 = FUN_004c1910(param_2,&iStack_4,4);
    if (lVar3 == 0) {
      param_1 = 0;
    }
    else {
      lVar3 = FUN_004c1910(param_2,auStack_8,4);
      if (lVar3 == 0) {
        param_1 = 0;
      }
      else {
        lVar3 = FUN_004c1910(param_2,&iStack_c,4);
        if (lVar3 == 0) {
          param_1 = 0;
        }
        else if (0 < iStack_4) {
          iVar6 = (int)param_1;
          if (*(int *)(iVar6 + 0x10) == 0) {
            iVar6 = *(int *)(iVar6 + 0x10);
          }
          else {
            iVar6 = *(int *)(iVar6 + 0x10);
          }
          if (iVar6 == 0) {
            param_1 = 0;
          }
          else {
            puVar1 = (u32 *)FUN_004c1f70(iVar6,iStack_4,0x301b1);
            if (puVar1 == (u32 *)0x0) {
              param_1 = 0;
            }
            else {
              puVar5 = puVar1 + iStack_4 * 0x24;
              iVar6 = iStack_c;
              for (; puVar1 != puVar5; puVar1 = puVar1 + 0x24) {
                iVar4 = 0;
                *puVar1 = 0xffffffff;
                puVar1[1] = 0xffffffff;
                puVar1[2] = 0;
                puVar1[3] = 0;
                puVar2 = puVar1;
                do {
                  puVar2[4] = 0xffffffff;
                  puVar2[5] = 0xffffffff;
                  iVar4 = iVar4 + 8;
                  puVar2[6] = 0xffffffff;
                  puVar2[7] = 0xffffffff;
                  puVar2[8] = 0xffffffff;
                  puVar2[9] = 0xffffffff;
                  puVar2[10] = 0xffffffff;
                  puVar2[0xb] = 0xffffffff;
                  puVar2 = puVar2 + 8;
                } while (iVar4 < 0x20);
                iStack_c = iVar6;
                puVar2 = puVar1;
                if (puVar1 == (u32 *)0x0) {
                  puVar2 = (u32 *)(*DAT_00960188)(0x95fa74,0x301a9);
                  if (puVar2 == (u32 *)0x0) {
                    puVar2 = (u32 *)0x0;
                  }
                  else {
                    lVar3 = (u64)(((code)FUN_004b30a0)(puVar2));
                    if (lVar3 == 0) {
                      ((code)FUN_004b3100)(puVar2);
                      (*DAT_0096018c)(0x95fa74,puVar2);
                      puVar2 = (u32 *)0x0;
                    }
                  }
                  if (puVar2 != (u32 *)0x0) goto LAB_004b32a8;
                  puVar2 = (u32 *)0x0;
                }
                else {
LAB_004b32a8:
                  lVar3 = FUN_004c1910(param_2,puVar2,4);
                  if (lVar3 == 0) {
                    puVar2 = (u32 *)0x0;
                  }
                  else {
                    lVar3 = FUN_004c1910(param_2,puVar2 + 1,4);
                    if (lVar3 == 0) {
                      puVar2 = (u32 *)0x0;
                    }
                    else {
                      lVar3 = FUN_004c1910(param_2,puVar2 + 2,4);
                      if (lVar3 == 0) {
                        puVar2 = (u32 *)0x0;
                      }
                      else {
                        lVar3 = FUN_004c1910(param_2,puVar2 + 4,iVar6 << 2);
                        if (lVar3 == 0) {
                          puVar2 = (u32 *)0x0;
                        }
                      }
                    }
                  }
                }
                if (puVar2 == (u32 *)0x0) {
                  return 0;
                }
                iVar6 = iStack_c;
              }
            }
          }
        }
      }
    }
  }
  return param_1;
}
#pragma optimization_level 3
// FUN_004B3440 NONMATCHING
int FUN_004b3440(int param_1)

{
  u32 uVar1;
  
  uVar1 = FUN_004c1d50(0x90,0x301b1);
  *(volatile u32 *)((int)param_1 + 0x10) = uVar1;
  if (*(volatile int *)((int)param_1 + 0x10) == 0) {
    param_1 = 0;
  }
  return param_1;
}
#pragma optimization_level 2
// FUN_004B3490 NONMATCHING
int FUN_004b3490(int param_1)

{
  volatile int *ptr;

  ptr = (volatile int *)param_1;
  if (ptr[4] != 0) {
    FUN_004c20b0();
    ptr[4] = 0;
  }
  return param_1;
}
#pragma optimization_level 3
// FUN_004B34D0
int FUN_004b34d0(int param_1,int param_2)

{
  return FUN_004c21b0(*(u32 *)(param_1 + 0x10));
}
#pragma optimization_level 2
// FUN_004B34E0 NONMATCHING
u32 * FUN_004b34e0(u32 *param_1)

{
  *param_1 = 0;
  param_1[1] = 1;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 1;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0x10;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 1;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 1;
  param_1[0xf] = 0;
  param_1[0x10] = 0x400;
  param_1[0x11] = 1;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 1;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 1;
  param_1[0x1c] = 0xa00;
  param_1[0x1d] = 0;
  param_1[0x1e] = 1;
  param_1[0x1f] = 0;
  param_1[0x20] = 0x20;
  param_1[0x21] = 1;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 1;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 1;
  param_1[0x2c] = 0x40;
  param_1[0x2d] = 0;
  param_1[0x2e] = 1;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 1;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0x1100;
  param_1[0x35] = 1;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0x80;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 1;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 1;
  param_1[0x3f] = 0;
  return param_1 + 0x78;
}
// FUN_004B3610 NONMATCHING
u64 FUN_004b3610(u64 param_1,u64 param_2)

{
  u64 uVar1;
  u64 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (int)param_1;
  if ((*(u32 *)(iVar3 + 8) & 1) != 0) {
    uVar1 = FUN_004ae900(param_2,*(u32 *)(iVar3 + 4));
    iVar4 = 1;
    if ((*(u32 *)(iVar3 + 8) & 2) != 0) {
      uVar2 = FUN_004ae900(uVar1,1);
      FUN_004adfd0(uVar2,1);
      iVar4 = 2;
    }
    if ((*(u32 *)(iVar3 + 8) & 4) != 0) {
      uVar2 = FUN_004ae900(uVar1,iVar4);
      FUN_004adfd0(uVar2,0);
      iVar4 = iVar4 + 1;
    }
    if ((*(u32 *)(iVar3 + 8) & 8) != 0) {
      uVar1 = FUN_004ae900(uVar1,iVar4);
      FUN_004adfd0(uVar1,0);
    }
  }
  return param_1;
}
// FUN_004B3730 NONMATCHING
u64 FUN_004b3730(u64 param_1)

{
  long lVar1;
  
  lVar1 = FUN_004c1d50(4,0x301a9);
  *(int *)((int)param_1 + 0x18) = (int)lVar1;
  if (lVar1 == 0) {
    param_1 = 0;
  }
  else {
    lVar1 = FUN_004c1d50(0x10,0x301a9);
    *(int *)((int)param_1 + 0x14) = (int)lVar1;
    if (lVar1 == 0) {
      param_1 = 0;
    }
  }
  return param_1;
}
// FUN_004B3790 NONMATCHING
u64 FUN_004b3790(u64 param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  u32 *puVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = (int)param_1;
  if (*(int *)(iVar5 + 0x18) != 0) {
    FUN_004c20b0();
  }
  *(u32 *)(iVar5 + 0x18) = 0;
  iVar1 = *(int *)(iVar5 + 0x14);
  if (iVar1 != 0) {
    iVar3 = FUN_004c2120(iVar1);
    if (0 < iVar3) {
      puVar4 = (u32 *)FUN_004c2090(iVar1);
      iVar6 = 0;
      if (0 < iVar3) {
        if (8 < iVar3) {
          bVar2 = false;
          if ((-1 < iVar3) && (iVar3 < 0x7fffffff)) {
            bVar2 = true;
          }
          if (bVar2) {
            do {
              *puVar4 = 0;
              iVar6 = iVar6 + 8;
              puVar4[1] = 0xffffffff;
              puVar4[2] = 0;
              puVar4[4] = 0;
              puVar4[5] = 0xffffffff;
              puVar4[6] = 0;
              puVar4[8] = 0;
              puVar4[9] = 0xffffffff;
              puVar4[10] = 0;
              puVar4[0xc] = 0;
              puVar4[0xd] = 0xffffffff;
              puVar4[0xe] = 0;
              puVar4[0x10] = 0;
              puVar4[0x11] = 0xffffffff;
              puVar4[0x12] = 0;
              puVar4[0x14] = 0;
              puVar4[0x15] = 0xffffffff;
              puVar4[0x16] = 0;
              puVar4[0x18] = 0;
              puVar4[0x19] = 0xffffffff;
              puVar4[0x1a] = 0;
              puVar4[0x1c] = 0;
              puVar4[0x1d] = 0xffffffff;
              puVar4[0x1e] = 0;
              puVar4 = puVar4 + 0x20;
            } while (iVar6 < iVar3 + -8);
          }
        }
        for (; iVar6 < iVar3; iVar6 = iVar6 + 1) {
          *puVar4 = 0;
          puVar4[1] = 0xffffffff;
          puVar4[2] = 0;
          puVar4 = puVar4 + 4;
        }
      }
    }
    FUN_004c20b0(iVar1);
  }
  *(u32 *)(iVar5 + 0x14) = 0;
  return param_1;
}
// FUN_004B3900 NONMATCHING
u64 FUN_004b3900(u64 param_1,u64 param_2)

{
  u32 uVar1;
  long lVar2;
  int iVar3;
  int iStack_4;
  
  lVar2 = FUN_004c1910(param_2,&iStack_4,4);
  if (lVar2 == 0) {
    param_1 = 0;
  }
  else if (0 < iStack_4) {
    iVar3 = (int)param_1;
    if (*(int *)(iVar3 + 0x18) == 0) {
      lVar2 = FUN_004c1d50(4,0x301a9);
      *(int *)(iVar3 + 0x18) = (int)lVar2;
      if (lVar2 != 0) {
        uVar1 = FUN_004c1d50(0x10,0x301a9);
        *(u32 *)(iVar3 + 0x14) = uVar1;
      }
    }
    if (*(int *)(iVar3 + 0x18) == 0) {
      param_1 = 0;
    }
    else {
      lVar2 = FUN_004c1f70(*(int *)(iVar3 + 0x18),iStack_4,0x301a9);
      if (lVar2 == 0) {
        param_1 = 0;
      }
      else {
        lVar2 = FUN_004c1910(param_2,lVar2,iStack_4 << 2);
        if (lVar2 == 0) {
          param_1 = 0;
        }
      }
    }
  }
  return param_1;
}
// FUN_004B39F0 NONMATCHING
u64 FUN_004b39f0(u64 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  u64 uVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = (int)param_1;
  iVar2 = FUN_004c2090(*(u32 *)(iVar6 + 0x18));
  iVar2 = *(int *)(iVar2 + param_2 * 4);
  uVar4 = FUN_004c21b0(*(u32 *)(iVar6 + 0x14),iVar2);
  iVar7 = 0;
  iVar1 = *(int *)uVar4;
  while (iVar1 != 0) {
    iVar2 = iVar2 + 1;
    iVar7 = iVar7 + 1;
    piVar3 = (int *)FUN_004c21b0(*(u32 *)(iVar6 + 0x14),iVar2);
    iVar1 = *piVar3;
  }
  if ((0 < iVar7) &&
     (lVar5 = FUN_004b3f50(param_1,*(u32 *)(iVar6 + 0x20),(int *)(int)uVar4,iVar7,
                           (u64)*(u32 *)(iVar6 + 0x44)), lVar5 == 0)) {
    param_1 = 0;
  }
  return param_1;
}
// FUN_004B3AC0 NONMATCHING
long FUN_004b3ac0(long param_1,u64 param_2)

{
  int *piVar1;
  int *piVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  int iStack_4;
  
  lVar3 = FUN_004c1910(param_2,&iStack_4,4);
  if (lVar3 == 0) {
    param_1 = 0;
  }
  else if (0 < iStack_4) {
    iVar5 = (int)param_1;
    if (*(int *)(iVar5 + 0x14) == 0) {
      lVar3 = FUN_004c1d50(4,0x301a9);
      *(int *)(iVar5 + 0x18) = (int)lVar3;
      if (lVar3 == 0) {
        lVar3 = 0;
      }
      else {
        lVar4 = FUN_004c1d50(0x10,0x301a9);
        *(int *)(iVar5 + 0x14) = (int)lVar4;
        lVar3 = param_1;
        if (lVar4 == 0) {
          lVar3 = 0;
        }
      }
      if (lVar3 == 0) {
        return 0;
      }
    }
    piVar1 = (int *)FUN_004c1f70(*(u32 *)(iVar5 + 0x14),iStack_4,0x301a9);
    if (piVar1 == (int *)0x0) {
      param_1 = 0;
    }
    else {
      iVar5 = 0;
      if (0 < iStack_4) {
        do {
          *piVar1 = 0;
          piVar1[1] = -1;
          piVar1[2] = 0;
          lVar3 = FUN_004c1910(param_2,piVar1,4);
          if (lVar3 == 0) {
            piVar2 = (int *)0x0;
          }
          else {
            lVar3 = FUN_004c1910(param_2,piVar1 + 1,4);
            if (lVar3 == 0) {
              piVar2 = (int *)0x0;
            }
            else {
              lVar3 = FUN_004c1910(param_2,piVar1 + 2,4);
              if (lVar3 == 0) {
                piVar2 = (int *)0x0;
              }
              else {
                lVar3 = FUN_004c1910(param_2,piVar1 + 3,4);
                if (lVar3 == 0) {
                  piVar2 = (int *)0x0;
                }
                else {
                  lVar3 = (*(code *)(&PTR_LAB_0077e3f4)[*piVar1 * 3])(param_1,piVar1,param_2);
                  piVar2 = piVar1;
                  if (lVar3 == 0) {
                    piVar2 = (int *)0x0;
                  }
                }
              }
            }
          }
          if (piVar2 == (int *)0x0) {
            return 0;
          }
          iVar5 = iVar5 + 1;
          piVar1 = piVar1 + 4;
        } while (iVar5 < iStack_4);
      }
    }
  }
  return param_1;
}
// FUN_004B3CC0 NONMATCHING
u64 FUN_004b3cc0(u64 param_1)

{
  u32 uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  u32 *puVar5;
  int iVar6;
  
  puVar5 = (u32 *)param_1;
  if ((*puVar5 & 2) == 0) {
    *puVar5 = *puVar5 | 2;
    lVar3 = FUN_004aa540();
    if (lVar3 == 0) {
      puVar5[0xf] = 0;
      puVar5[0xe] = 0;
      puVar5[0x10] = 0;
    }
    else {
      iVar2 = (int)lVar3;
      iVar6 = *(int *)(*(int *)(iVar2 + 0x60) + 0x10);
      puVar5[0xf] = (u32)(1.0 / (float)*(int *)(*(int *)(iVar2 + 0x60) + 0xc));
      puVar5[0xe] = (u32)(1.0 / (float)iVar6);
      puVar5[0x10] = (u32)(*(float *)(iVar2 + 0x68) / *(float *)(iVar2 + 0x6c));
    }
    uVar1 = puVar5[8];
    lVar3 = FUN_004b4090(uVar1);
    while (lVar3 != 0) {
      lVar4 = (*(code *)puVar5[10])(param_1,lVar3);
      if (lVar4 != lVar3) {
        *puVar5 = *puVar5 & 0xfffffffd;
        return 0;
      }
      lVar3 = FUN_004b4090(uVar1);
    }
    *puVar5 = *puVar5 & 0xfffffffd;
  }
  return param_1;
}
// FUN_004B3DE0 NONMATCHING
u64 FUN_004b3de0(u64 param_1,u64 param_2,int param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = (int)param_2;
  if (*(int *)(iVar1 + 4) < 0) {
    iVar3 = *(int *)(iVar1 + 8);
    if (iVar3 < 1) {
      if (iVar3 == 0) {
        param_3 = param_3 + *(int *)(iVar1 + 0xc);
      }
      else if (iVar3 == -1) {
        param_3 = *(int *)(iVar1 + 0xc);
      }
    }
    else {
      iVar3 = iVar3 + -1;
      iVar2 = ((code)FUN_004b4a60)(param_1,param_3);
      if (iVar3 < 1) {
        param_3 = *(int *)(iVar2 + 0x34);
      }
      else {
        do {
          iVar2 = ((code)FUN_004b4a60)(param_1,*(u32 *)(iVar2 + 0x34));
          iVar3 = iVar3 + -1;
        } while (0 < iVar3);
        param_3 = *(int *)(iVar2 + 0x34);
      }
      param_3 = param_3 + *(int *)(iVar1 + 0xc);
    }
  }
  else {
    iVar3 = *(int *)(iVar1 + 8);
    if (iVar3 < 1) {
      if (iVar3 == 0) {
        iVar1 = ((code)FUN_004b3030)(param_1,*(u32 *)(iVar1 + 0xc));
        param_3 = param_3 + *(int *)(iVar1 + 8);
      }
      else if (iVar3 == -1) {
        iVar1 = ((code)FUN_004b3030)(param_1,*(u32 *)(iVar1 + 0xc));
        param_3 = *(int *)(iVar1 + 8);
      }
    }
    else {
      iVar2 = ((code)FUN_004b4a60)(param_1,param_3);
      while (iVar3 = iVar3 + -1, 0 < iVar3) {
        iVar2 = ((code)FUN_004b4a60)(param_1,*(u32 *)(iVar2 + 0x34));
      }
      iVar1 = ((code)FUN_004b3030)(param_1,*(u32 *)(iVar1 + 0xc));
      param_3 = *(int *)(iVar2 + 0x34) + *(int *)(iVar1 + 8);
    }
  }
  *param_4 = param_3;
  return param_2;
}
// FUN_004B3F50 NONMATCHING
u64
FUN_004b3f50(u64 param_1,u64 param_2,int *param_3,int param_4,u64 param_5)

{
  long lVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iStack_4;
  
  piVar2 = (int *)param_2;
  if ((u32)piVar2[3] < (u32)(piVar2[2] + param_4)) {
    param_2 = 0;
  }
  else {
    iVar4 = 0;
    piVar3 = (int *)(*piVar2 + piVar2[2] * 0x10);
    iStack_4 = (int)param_5;
    if (0 < param_4) {
      do {
        if (*param_3 == 0xc) {
          lVar1 = (u64)(FUN_004b3de0(param_1,(u64)(int)param_3,param_5,&iStack_4));
          if (lVar1 == 0) {
            return 0;
          }
        }
        else {
          iVar7 = param_3[1];
          iVar5 = param_3[2];
          iVar6 = param_3[3];
          *piVar3 = *param_3;
          piVar3[1] = iVar7;
          piVar3[2] = iVar5;
          piVar3[3] = iVar6;
          piVar2[2] = piVar2[2] + 1;
          if (piVar3[1] < 0) {
            piVar3[1] = iStack_4;
          }
          else {
            iVar5 = ((code)FUN_004b3030)(param_1);
            piVar3[1] = *(int *)(iVar5 + 8);
          }
          piVar3 = piVar3 + 4;
        }
        iVar4 = iVar4 + 1;
        param_3 = param_3 + 4;
      } while (iVar4 < param_4);
    }
  }
  return param_2;
}
// FUN_004B4090 NONMATCHING
int FUN_004b4090(int *param_1)
{
  int iVar1;
  
  iVar1 = 0;
  if (param_1[2] == 0) {
    goto done;
  }
  iVar1 = *param_1 + param_1[1] * 0x10;
  param_1[1] = param_1[1] + 1;
  if (param_1[2] <= param_1[1]) {
    param_1[1] = 0;
    param_1[2] = 0;
  }
done:
  return iVar1;
}
// FUN_004B40F0 NONMATCHING
u64 FUN_004b40f0(u64 param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  int *piVar4;
  
  lVar2 = (*DAT_00960188)(0x95fb04,0x301a9);
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  else {
    iVar1 = (*DAT_00960178)((u32)DAT_007cdce8 << 4,0x301a9);
    piVar4 = (int *)lVar2;
    *piVar4 = iVar1;
    if (*piVar4 == 0) {
      lVar3 = 0;
    }
    else {
      piVar4[1] = 0;
      piVar4[2] = 0;
      piVar4[3] = (int)(DAT_007cdce8);
      lVar3 = lVar2;
    }
    if (lVar3 == 0) {
      lVar2 = 0;
    }
  }
  *(int *)((int)param_1 + 0x20) = (int)lVar2;
  if (lVar2 == 0) {
    param_1 = 0;
  }
  return param_1;
}
// FUN_004B41B0 NONMATCHING
u64 FUN_004b41b0(u64 param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)((int)param_1 + 0x20);
  if (piVar1 != (int *)0x0) {
    piVar1[1] = 0;
    piVar1[2] = 0;
    if (*piVar1 != 0) {
      (*DAT_0096017c)();
    }
    (*DAT_0096018c)(0x95fb04,piVar1);
  }
  *(u32 *)((int)param_1 + 0x20) = 0;
  return param_1;
}
// FUN_004B4230 NONMATCHING
u64 FUN_004b4230(u64 param_1)

{
  u32 uVar1;
  u32 *puVar2;
  
  puVar2 = (u32 *)param_1;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[7] = 0;
  puVar2[9] = 0;
  puVar2[4] = 0;
  puVar2[0x11] = 0xffffffff;
  FUN_004b2e20(param_1);
  FUN_004b3440(param_1);
  FUN_004b3730(param_1);
  FUN_004b40f0(param_1);
  uVar1 = ((code)FUN_004b2bc0)();
  puVar2[7] = uVar1;
  puVar2[10] = (u32)(FUN_004b5b50);
  puVar2[0xb] = 0x4f800000;
  puVar2[0xc] = 0x4f800000;
  puVar2[0xd] = 0;
  puVar2[0x12] = 0;
  puVar2[0x13] = 0;
  puVar2[0x14] = 0;
  puVar2[0x15] = 0;
  FUN_004b34e0(puVar2 + 0x16);
  return param_1;
}
// FUN_004B42E0 NONMATCHING
u32 FUN_004b42e0(u64 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if (*(int *)(iVar2 + 8) == 0) {
    iVar1 = *(int *)(iVar2 + 0xc);
  }
  else {
    iVar1 = *(int *)(iVar2 + 0xc);
  }
  if (iVar1 == 0) {
    iVar1 = *(int *)(iVar2 + 0x10);
  }
  else {
    FUN_004b2e70(param_1);
    iVar1 = *(int *)(iVar2 + 0x10);
  }
  if (iVar1 == 0) {
    iVar1 = *(int *)(iVar2 + 0x18);
  }
  else {
    FUN_004b3490(param_1);
    iVar1 = *(int *)(iVar2 + 0x18);
  }
  if (iVar1 == 0) {
    iVar1 = *(int *)(iVar2 + 0x24);
  }
  else {
    FUN_004b3790(param_1);
    iVar1 = *(int *)(iVar2 + 0x24);
  }
  if (iVar1 != 0) {
    FUN_004ae5a0();
  }
  if (*(int *)(iVar2 + 0x20) == 0) {
    iVar1 = *(int *)(iVar2 + 0x1c);
  }
  else {
    FUN_004b41b0(param_1);
    iVar1 = *(int *)(iVar2 + 0x1c);
  }
  if (iVar1 != 0) {
    FUN_004b2bd0();
    *(u32 *)(iVar2 + 0x1c) = 0;
  }
  return 1;
}
// FUN_004B43C0 NONMATCHING
long FUN_004b43c0(void)
{
  long lVar1;
  
  lVar1 = (*DAT_00960188)(0x95fa98,0x301b1);
  if (lVar1 != 0) {
    FUN_004b4230(lVar1);
  }
  return lVar1;
}
#pragma schedule on
// FUN_004B4410
u32 FUN_004b4410(u64 param_1)
{
  FUN_004b42e0(param_1);
  DAT_0096018c_abs[0]((u32)((u8 *)DAT_0096018c_abs - 0x568),param_1);
  return 1;
}
#pragma schedule off
// FUN_004B4450 NONMATCHING
u64 FUN_004b4450(u64 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  u32 *puVar3;
  u32 uVar4;
  long lVar5;
  u64 uVar6;
  int iVar7;
  int iVar8;
  
  if ((*(int *)(param_2 + 0x34) == -1) && (*(int *)(param_2 + 0x38) == -1)) {
    uVar4 = *(u32 *)((int)param_1 + 0x24);
  }
  else {
    uVar6 = ((code)FUN_004b5270)(param_1);
    uVar4 = FUN_004ae900(uVar6,*(u32 *)(param_2 + 0x38));
    FUN_004adfd0(uVar4,0);
  }
    FUN_004b1a30((u32 *)(param_2 + 4));
  iVar8 = 0;
  if (0 < iVar1) {
    do {
      lVar5 = FUN_004b6000(*(u32 *)(param_2 + 0x30),iVar8);
      if (lVar5 != 0) {
        iVar2 = FUN_004c2120(*(u32 *)((int)lVar5 + 8));
        puVar3 = (u32 *)FUN_004c2090(*(u32 *)((int)lVar5 + 8));
        iVar7 = 0;
        if (0 < iVar2) {
          do {
            uVar6 = ((code)FUN_004b34d0)(param_1,*puVar3);
            FUN_004b3610(uVar6,uVar4);
            iVar7 = iVar7 + 1;
            puVar3 = puVar3 + 1;
          } while (iVar7 < iVar2);
        }
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < iVar1);
  }
  FUN_004b1420(param_2 + 4,param_2 + 0x20);
  FUN_004b1500(param_2 + 4,param_2 + 0x20,1);
  return param_1;
}
// FUN_004B45B0 NONMATCHING
long FUN_004b45b0(long param_1,u64 param_2)

{
  long lVar1;
  u8 auStack_4 [4];
  
  if ((param_1 == 0) && (param_1 = (*DAT_00960188)(0x95fa98,0x301b1), param_1 != 0)) {
    FUN_004b4230(param_1);
  }
  if (param_1 != 0) {
    lVar1 = FUN_004c1910(param_2,auStack_4,4);
    if (lVar1 == 0) {
      param_1 = 0;
    }
    else {
      lVar1 = FUN_004c18b0(param_2,(int)param_1 + 0x48,0x10);
      if (lVar1 == 0) {
        param_1 = 0;
      }
      else {
        lVar1 = FUN_004b2f10(param_1,param_2);
        if (lVar1 == 0) {
          param_1 = 0;
        }
        else {
          lVar1 = FUN_004b4cc0(param_1,param_2);
          if (lVar1 == 0) {
            param_1 = 0;
          }
          else {
            lVar1 = FUN_004b3160(param_1,param_2);
            if (lVar1 == 0) {
              param_1 = 0;
            }
            else {
              lVar1 = FUN_004b3900(param_1,param_2);
              if (lVar1 == 0) {
                param_1 = 0;
              }
              else {
                lVar1 = FUN_004b3ac0(param_1,param_2);
                if (lVar1 == 0) {
                  param_1 = 0;
                }
                else {
                  lVar1 = FUN_004b4860(param_1,param_2);
                  if (lVar1 == 0) {
                    param_1 = 0;
                  }
                  else {
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return param_1;
}
// FUN_004B4720 NONMATCHING
u64 FUN_004b4720(u64 param_1,u32 *param_2)

{
  FUN_004b1240((u64)(param_2 + 1),(u64)(param_2 + 8));
  *param_2 = 0;
  param_2[0xd] = 0xffffffff;
  param_2[0xe] = 0xffffffff;
  if (param_2[0xc] != 0) {
  }
  FUN_004b2b40((u64)(param_2 + 8));
  param_2[0xc] = 0;
  return param_1;
}
#pragma alias FUN_004b1620_ptr FUN_004b1620
extern u64 FUN_004b1620_ptr(u8 *param_1,u8 *param_2);
#pragma schedule on
// FUN_004B4790 NONMATCHING
u64 FUN_004b4790(u64 param_1,u8 *param_2)

{
  long lVar1;
  
  lVar1 = FUN_004b1620_ptr(param_2 + 4,param_2 + 0x20);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  return param_1;
}
#pragma schedule off
// FUN_004B47D0 NONMATCHING
u64 FUN_004b47d0(u64 param_1)

{
  long lVar1;
  
  lVar1 = FUN_004c1d50(0x3c,0x301a9);
  *(int *)((int)param_1 + 8) = (int)lVar1;
  if (lVar1 == 0) {
    param_1 = 0;
  }
  return param_1;
}
// FUN_004B4810 NONMATCHING
u64 FUN_004b4810(u64 param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 8) != 0) {
    FUN_004b4ba0(param_1,(code *)0x4b4720,0);
    FUN_004c20b0(*(u32 *)(iVar1 + 8));
    *(u32 *)(iVar1 + 8) = 0;
  }
  return param_1;
}
// FUN_004B4860 NONMATCHING
u64 FUN_004b4860(u64 param_1,u64 param_2)

{
  u32 *puVar1;
  u32 *puVar2;
  u32 uVar3;
  long lVar4;
  u64 uVar5;
  int iVar6;
  int iVar7;
  u8 auStack_20 [28];
  int iStack_4;
  
  lVar4 = FUN_004c1910(param_2,&iStack_4,4);
  if (lVar4 == 0) {
    param_1 = 0;
  }
  else if (0 < iStack_4) {
    iVar7 = (int)param_1;
    if (*(int *)(iVar7 + 8) == 0) {
      uVar3 = FUN_004c1d50(0x3c,0x301a9);
      *(u32 *)(iVar7 + 8) = uVar3;
    }
    if (*(int *)(iVar7 + 8) == 0) {
      param_1 = 0;
    }
    else {
      puVar1 = (u32 *)FUN_004c1f70(*(int *)(iVar7 + 8),iStack_4,0x301a9);
      if (puVar1 == (u32 *)0x0) {
        param_1 = 0;
      }
      else {
        iVar6 = 0;
        if (0 < iStack_4) {
          do {
            *puVar1 = 2;
            puVar1[0xd] = 0xffffffff;
            puVar1[0xe] = 0xffffffff;
            lVar4 = FUN_004b6040();
            puVar1[0xc] = (int)lVar4;
            puVar2 = puVar1;
            if (lVar4 == 0) {
              puVar2 = (u32 *)0x0;
            }
            if (puVar2 == (u32 *)0x0) {
              return 0;
            }
            lVar4 = FUN_004b5ec0(param_1,puVar1[0xc],param_2);
            if (lVar4 == 0) {
              return 0;
            }
            lVar4 = FUN_004c1910(param_2,puVar1 + 0xd,4);
            if (lVar4 == 0) {
              return 0;
            }
            lVar4 = FUN_004c1910(param_2,puVar1 + 0xe,4);
            if (lVar4 == 0) {
              return 0;
            }
            lVar4 = FUN_004c1970(param_2,auStack_20);
            if (lVar4 == 0) {
              return 0;
            }
            uVar5 = ((code)FUN_004b5270)(param_1,iVar6);
            lVar4 = (u64)(FUN_004b2ad0((u64)(puVar1 + 8),uVar5));
            if (lVar4 == 0) {
              return 0;
            }
            lVar4 = (u64)(FUN_004b1290((u64)(puVar1 + 1),param_2));
            if (lVar4 == 0) {
              return 0;
            }
            iVar6 = iVar6 + 1;
            puVar1 = puVar1 + 0xf;
          } while (iVar6 < iStack_4);
        }
        FUN_004c21b0(*(u32 *)(iVar7 + 8),0);
      }
    }
  }
  return param_1;
}
#pragma optimization_level 3
// FUN_004B4A60
int FUN_004b4a60(int param_1,int param_2)

{
  return FUN_004c21b0(*(u32 *)(param_1 + 8));
}
#pragma optimization_level 2
// FUN_004B4A70 NONMATCHING
long FUN_004b4a70(long param_1,code *param_2,u64 param_3)

{
  bool bVar1;
  int iVar2;
  u32 *puVar3;
  u32 *puVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = (int)param_1;
  iVar2 = FUN_004c2120(*(u32 *)(iVar6 + 8));
  if (0 < iVar2) {
    puVar3 = (u32 *)FUN_004c2090(*(u32 *)(iVar6 + 8));
    iVar7 = 0;
    if (0 < iVar2) {
      do {
        bVar1 = true;
        if ((puVar3[0xd] != 0xffffffff) &&
           (puVar4 = (u32 *)FUN_004c21b0(*(u32 *)(iVar6 + 8)), (*puVar4 | 4) == 0)) {
          bVar1 = false;
        }
        *(int *)(iVar6 + 0x44) = iVar7;
        if ((bVar1) && (lVar5 = FUN_004ae010(puVar3[8]), lVar5 != 0)) {
          *puVar3 = *puVar3 | 4;
          lVar5 = (*param_2)(param_1,puVar3,param_3);
          if (lVar5 != param_1) {
            return 0;
          }
        }
        else {
          *puVar3 = *puVar3 & 0xfffffffb;
        }
        iVar7 = iVar7 + 1;
        puVar3 = puVar3 + 0xf;
      } while (iVar7 < iVar2);
    }
  }
  *(u32 *)(iVar6 + 0x44) = 0xffffffff;
  return param_1;
}
// FUN_004B4BA0 NONMATCHING
long FUN_004b4ba0(long param_1,code *param_2,u64 param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = (int)param_1;
  iVar1 = FUN_004c2120(*(u32 *)(iVar4 + 8));
  if (0 < iVar1) {
    iVar2 = FUN_004c2090(*(u32 *)(iVar4 + 8));
    iVar5 = 0;
    if (0 < iVar1) {
      do {
        *(int *)(iVar4 + 0x44) = iVar5;
        lVar3 = (*param_2)(param_1,iVar2,param_3);
        if (lVar3 != param_1) {
          return 0;
        }
        iVar5 = iVar5 + 1;
        iVar2 = iVar2 + 0x3c;
      } while (iVar5 < iVar1);
    }
  }
  *(u32 *)(iVar4 + 0x44) = 0xffffffff;
  return param_1;
}
// FUN_004B4C70 NONMATCHING
u64 FUN_004b4c70(u64 param_1)

{
  long lVar1;
  
  if ((*(int *)((int)param_1 + 8) != 0) &&
     (lVar1 = FUN_004b4a70((int)param_1,(code *)0x4b4790,0), lVar1 == 0)) {
    param_1 = 0;
  }
  return param_1;
}
// FUN_004B4CC0 NONMATCHING
u64 FUN_004b4cc0(u64 param_1,u64 param_2)

{
  long lVar1;
  u8 auStack_c [4];
  u8 auStack_8 [4];
  int iStack_4;
  
  lVar1 = FUN_004c1910(param_2,&iStack_4,4);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  else if (0 < iStack_4) {
    lVar1 = FUN_004c1600(param_2,0x1a5,auStack_8,auStack_c);
    if (lVar1 == 0) {
      param_1 = 0;
    }
    else {
      lVar1 = FUN_004aeea0(param_2);
      *(int *)((int)param_1 + 0x24) = (int)lVar1;
      if (lVar1 == 0) {
        param_1 = 0;
      }
    }
  }
  return param_1;
}
#pragma optimization_level 3
// FUN_004B4D60
u32 FUN_004b4d60(int param_1)

{
  return *(u32 *)(param_1 + 0x24);
}
#pragma optimization_level 2
// FUN_004B4D70 NONMATCHING
u64 FUN_004b4d70(u64 param_1,u32 *param_2,u32 *param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  u32 uVar4;
  
  uVar4 = *param_3;
  lVar2 = FUN_004b1a80(param_2 + 1);
  if ((*param_2 & 2) != 0) {
    *param_2 = *param_2 & 0xfffffffd;
    iVar1 = FUN_004c2090(*(u32 *)param_2[0xc]);
    if (-1 < *(int *)(iVar1 + (int)lVar2 * 0x10 + 0xc)) {
      ((code)FUN_004b39f0)(param_1);
    }
    FUN_004b3cc0(param_1);
    FUN_004b5380(param_1,(int)param_1 + 0x2c);
  }
  lVar3 = FUN_004ae010(param_2[8]);
  if ((lVar3 != 0) && ((*param_2 & 1) == 0)) {
    lVar3 = (u64)(FUN_004b14c0(uVar4,(u64)(param_2 + 1)));
    if (lVar3 == 0) {
      param_1 = 0;
    }
    else {
      lVar3 = FUN_004b1a80(param_2 + 1);
      if ((lVar2 != lVar3) &&
         (iVar1 = FUN_004c2090(*(u32 *)param_2[0xc]),
         -1 < *(int *)(iVar1 + (int)lVar3 * 0x10 + 0xc))) {
        ((code)FUN_004b39f0)(param_1);
      }
    }
  }
  return param_1;
}
// FUN_004B4EB0 NONMATCHING
u64 FUN_004b4eb0(u64 param_1,u32 *param_2,long param_3)

{
  u32 *puVar1;
  u32 *puVar2;
  int iVar3;
  u64 uVar4;
  u32 *puVar5;
  float fVar6;
  
  if ((((*param_2 & 1) == 0) &&
      (fVar6 = (float)FUN_004b1a70((int)(param_2 + 1)), fVar6 <= (float)param_2[3])) || (param_3 != 0)) {
    puVar2 = (u32 *)FUN_004c21e0(*(u32 *)((int)param_1 + 8));
    iVar3 = FUN_004c2090(*(u32 *)((int)param_1 + 8));
    FUN_004b1870((u64)(param_2 + 1),(u64)(param_2 + 8),0);
    *param_2 = *param_2 | 2;
    puVar5 = param_2;
    while (puVar1 = puVar5, puVar5 = puVar1 + 0xf, puVar5 != puVar2) {
      if (puVar1[0x1c] == ((int)param_2 - iVar3) / 0x3c) {
        uVar4 = ((code)FUN_004b5270)(param_1);
        uVar4 = FUN_004ae900(uVar4,puVar1[0x1d]);
        FUN_004b4eb0(param_1,puVar5,1);
        FUN_004adfd0(uVar4,0);
      }
    }
  }
  return param_1;
}
// FUN_004B5000 NONMATCHING
long FUN_004b5000(float param_1,long param_2)

{
  bool bVar1;
  u32 *puVar2;
  u32 *puVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fStack_4;
  
  iVar8 = (int)param_2;
  fVar13 = 0.0;
  fVar10 = 0.0;
  fVar11 = 0.0;
  puVar2 = (u32 *)FUN_004c21e0(*(u32 *)(iVar8 + 8));
  for (puVar3 = (u32 *)FUN_004c2090(*(u32 *)(iVar8 + 8)); puVar3 != puVar2;
      puVar3 = puVar3 + 0xf) {
    if ((*puVar3 & 1) == 0) {
      if (puVar3[6] != 0) {
        fVar11 = (int)((float)FUN_004b1ae0((int)(puVar3 + 1)));
        fVar13 = (int)((float)FUN_004b1a60((f32 *)(puVar3 + 1)));
        fVar10 = (int)((float)FUN_004b1b60((int)(puVar3 + 1)));
        fVar11 = fVar10 - fVar11;
        break;
      }
      lVar7 = FUN_004b1a80(puVar3 + 1);
      if (0 < lVar7) {
        pfVar4 = (float *)FUN_004b1a40(puVar3 + 1);
        fVar11 = *pfVar4;
        fVar10 = (int)((float)FUN_004b1ae0((int)(puVar3 + 1)));
        fVar11 = fVar10 - fVar11;
        fVar13 = (int)((float)FUN_004b1a60((f32 *)(puVar3 + 1)));
        fVar13 = fVar13 - fVar11;
        break;
      }
    }
  }
  if (fVar11 != 0.0) {
joined_r0x004b511c:
    if (0.0001 < param_1) {
      fStack_4 = fVar10 - fVar13;
      bVar1 = fStack_4 < param_1;
      if (bVar1) {
        fVar12 = param_1 - fStack_4;
        fVar13 = fVar13 + fStack_4;
        fVar10 = fVar10 + fVar11;
      }
      else {
        fVar12 = 0.0;
        fStack_4 = param_1;
      }
      lVar7 = FUN_004b4a70(param_2,(code *)0x4b4d70,(u64)(int)&fStack_4);
      if (lVar7 == 0) {
        return 0;
      }
      if (bVar1) {
        FUN_004b3cc0(param_2);
      }
      iVar5 = FUN_004c2120(*(u32 *)(iVar8 + 8));
      if (0 < iVar5) {
        iVar6 = FUN_004c2090(*(u32 *)(iVar8 + 8));
        iVar9 = 0;
        if (0 < iVar5) {
          do {
            *(int *)(iVar8 + 0x44) = iVar9;
            lVar7 = FUN_004b4eb0(param_2,(u32 *)(int)iVar6,0);
            param_1 = fVar12;
            if (lVar7 != param_2) goto joined_r0x004b511c;
            iVar9 = iVar9 + 1;
            iVar6 = iVar6 + 0x3c;
          } while (iVar9 < iVar5);
        }
      }
      *(u32 *)(iVar8 + 0x44) = 0xffffffff;
      param_1 = fVar12;
      goto joined_r0x004b511c;
    }
  }
  return param_2;
}
// FUN_004B5270 NONMATCHING
u32 FUN_004b5270(u64 param_1,long param_2)

{
  int iVar1;
  u32 uVar2;
  int iVar3;
  int iVar4;
  u64 uVar5;
  
  iVar4 = (int)param_1;
  if (param_2 < 1) {
    uVar2 = *(u32 *)(iVar4 + 0x24);
  }
  else {
    iVar1 = FUN_004c21b0(*(u32 *)(iVar4 + 8));
    if (*(int *)(iVar1 + 0x34) < 1) {
      uVar2 = *(u32 *)(iVar4 + 0x24);
    }
    else {
      iVar3 = FUN_004c21b0(*(u32 *)(iVar4 + 8));
      if (*(int *)(iVar3 + 0x34) < 1) {
        uVar2 = *(u32 *)(iVar4 + 0x24);
      }
      else {
        iVar4 = FUN_004c21b0(*(u32 *)(iVar4 + 8));
        uVar5 = ((code)FUN_004b5270)(param_1,*(u32 *)(iVar4 + 0x34));
        uVar2 = FUN_004ae900(uVar5,*(u32 *)(iVar4 + 0x38));
      }
      uVar2 = FUN_004ae900(uVar2,*(u32 *)(iVar3 + 0x38));
    }
    uVar2 = FUN_004ae900(uVar2,*(u32 *)(iVar1 + 0x38));
  }
  return uVar2;
}
// FUN_004B5330 NONMATCHING
u32 FUN_004b5330(u32 param_1)
{
  if (*(u32 *)(param_1 + 0x24) == 0 || FUN_004ae940() == 0) {
    return 0;
  }
  return param_1;
}
// FUN_004B5380 NONMATCHING
void FUN_004b5380(u64 param_1,u64 param_2)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  int iVar4;
  u32 uVar5;
  int iVar6;
  int iVar7;
  long lVar8;
  u64 uVar9;
  u64 uVar10;
  u64 uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  u32 uVar15;
  u32 uVar16;
  int iVar17;
  u32 *puStack_20;
  int iStack_10;
  
  iVar13 = (int)param_1;
  iVar3 = FUN_004c2120(*(u32 *)(iVar13 + 8));
  iVar4 = FUN_004c2090(*(u32 *)(iVar13 + 8));
  uVar1 = *(u32 *)(iVar13 + 0x44);
  iVar17 = 0;
  if (0 < iVar3) {
    do {
      *(int *)(iVar13 + 0x44) = iVar17;
      uVar5 = ((code)FUN_004b5270)(param_1,iVar17);
      lVar8 = (long)(int)FUN_004b1a80((u32 *)(iVar4 + 4));
      if (-1 < lVar8) {
        iVar6 = FUN_004b6000(*(u32 *)(iVar4 + 0x30));
        iVar7 = FUN_004c2120(*(u32 *)(iVar6 + 8));
        puStack_20 = (u32 *)FUN_004c2090(*(u32 *)(iVar6 + 8));
        iStack_10 = 0;
        if (0 < iVar7) {
          do {
            iVar6 = ((code)FUN_004b34d0)(param_1,*puStack_20);
            if ((*(u32 *)(iVar6 + 8) & 1) != 0) {
              uVar9 = FUN_004ae900(uVar5,*(u32 *)(iVar6 + 4));
              uVar10 = FUN_004ae900(uVar9,0);
              uVar16 = 0;
              iVar12 = 0;
              lVar8 = FUN_004ae8f0(uVar10);
              if (lVar8 < 1) {
                uVar2 = *(u32 *)(iVar6 + 0xc);
              }
              else {
                do {
                  uVar11 = FUN_004ae900(uVar10,iVar12);
                  uVar16 = (u32)(uVar16 != 0);
                  if (uVar16 == 0) {
                    lVar8 = FUN_004ae1f0(uVar11,param_2);
                    uVar16 = (u32)(lVar8 != 0);
                  }
                  iVar12 = iVar12 + 1;
                  iVar14 = FUN_004ae8f0(uVar10);
                } while (iVar12 < iVar14);
                uVar2 = *(u32 *)(iVar6 + 0xc);
              }
              iVar14 = 1;
              iVar12 = iVar13 + (u32)((uVar2 & 1) != 0) * 0x80 + *(int *)(iVar13 + 0x34) * 0x50 +
                       uVar16 * 0x20;
              uVar2 = *(u32 *)(iVar12 + 0x58);
              if ((*(u32 *)(iVar6 + 8) & 2) != 0) {
                uVar10 = FUN_004ae900(uVar9,1);
                FUN_004adfd0(uVar10,*(u32 *)(iVar12 + 0x5c));
                iVar14 = 2;
              }
              if ((*(u32 *)(iVar6 + 8) & 4) != 0) {
                uVar10 = FUN_004ae900(uVar9,iVar14);
                FUN_004adfd0(uVar10,*(u32 *)(iVar12 + 0x60));
                iVar14 = iVar14 + 1;
              }
              if ((*(u32 *)(iVar6 + 8) & 8) == 0) {
                uVar15 = *(u32 *)(iVar6 + 8);
              }
              else {
                uVar9 = FUN_004ae900(uVar9,iVar14);
                FUN_004adfd0(uVar9,*(u32 *)(iVar12 + 100));
                uVar15 = *(u32 *)(iVar6 + 8);
              }
              if ((uVar15 & uVar2) != 0) {
                uVar15 = uVar15 >> 4;
                iVar14 = -1;
                for (iVar12 = (int)uVar2 >> 4; iVar12 != 0; iVar12 = iVar12 >> 1) {
                  if ((uVar15 & 1) != 0) {
                    iVar14 = iVar14 + 1;
                  }
                  uVar15 = (int)uVar15 >> 1;
                }
                if (-1 < *(int *)(iVar6 + iVar14 * 4 + 0x10)) {
                  ((code)FUN_004b39f0)(param_1);
                }
              }
              if (uVar16 == 0) {
                *(u32 *)(iVar6 + 0xc) = *(u32 *)(iVar6 + 0xc) & 0xfffffffe;
              }
              else {
                *(u32 *)(iVar6 + 0xc) = *(u32 *)(iVar6 + 0xc) | 1;
              }
            }
            puStack_20 = puStack_20 + 1;
            iStack_10 = iStack_10 + 1;
          } while (iStack_10 < iVar7);
        }
      }
      iVar17 = iVar17 + 1;
      iVar4 = iVar4 + 0x3c;
    } while (iVar17 < iVar3);
  }
  *(u32 *)(iVar13 + 0x44) = uVar1;
  return;
}
// FUN_004B56D0 NONMATCHING
int FUN_004b56d0(u64 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  u32 uVar3;
  int iVar4;
  int iVar5;
  u32 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  u64 uVar10;
  u64 uVar11;
  int iVar12;
  u32 uVar13;
  u32 uVar14;
  int iVar15;
  int iVar16;
  u32 *puStack_30;
  int iStack_20;
  
  iVar12 = (int)param_1;
  iVar1 = *(int *)(iVar12 + 0x34);
  iVar2 = *(int *)(param_2 + 8);
  iVar4 = FUN_004c2120(*(u32 *)(iVar12 + 8));
  iVar5 = FUN_004c2090(*(u32 *)(iVar12 + 8));
  uVar3 = *(u32 *)(iVar12 + 0x44);
  iVar16 = 0;
  if (0 < iVar4) {
    do {
      *(int *)(iVar12 + 0x44) = iVar16;
      uVar6 = ((code)FUN_004b5270)(param_1,iVar16);
      uVar10 = (u64)(int)FUN_004b1a80((u32 *)(iVar5 + 4));
      iVar7 = FUN_004b6000(*(u32 *)(iVar5 + 0x30),uVar10);
      iVar8 = FUN_004c2120(*(u32 *)(iVar7 + 8));
      puStack_30 = (u32 *)FUN_004c2090(*(u32 *)(iVar7 + 8));
      iStack_20 = 0;
      if (0 < iVar8) {
        do {
          iVar7 = ((code)FUN_004b34d0)(param_1,*puStack_30);
          if ((*(u32 *)(iVar7 + 8) & 1) != 0) {
            uVar10 = FUN_004ae900(uVar6,*(u32 *)(iVar7 + 4));
            iVar15 = 1;
            uVar14 = (u32)((*(u32 *)(iVar7 + 0xc) & 1) != 0);
            iVar9 = iVar12 + uVar14 * 0x80 + iVar1 * 0x40 + uVar14 * 0x20 + iVar2 * 0x10;
            uVar14 = *(u32 *)(iVar9 + 0x58);
            if ((*(u32 *)(iVar7 + 8) & 2) != 0) {
              uVar11 = FUN_004ae900(uVar10,1);
              FUN_004adfd0(uVar11,*(u32 *)(iVar9 + 0x5c));
              iVar15 = 2;
            }
            if ((*(u32 *)(iVar7 + 8) & 4) != 0) {
              uVar11 = FUN_004ae900(uVar10,iVar15);
              FUN_004adfd0(uVar11,*(u32 *)(iVar9 + 0x60));
              iVar15 = iVar15 + 1;
            }
            if ((*(u32 *)(iVar7 + 8) & 8) == 0) {
              uVar13 = *(u32 *)(iVar7 + 8);
            }
            else {
              uVar10 = FUN_004ae900(uVar10,iVar15);
              FUN_004adfd0(uVar10,*(u32 *)(iVar9 + 100));
              uVar13 = *(u32 *)(iVar7 + 8);
            }
            if ((uVar13 & uVar14) != 0) {
              uVar13 = uVar13 >> 4;
              iVar9 = -1;
              for (; uVar14 != 0; uVar14 = (int)uVar14 >> 1) {
                if ((uVar13 & 1) != 0) {
                  iVar9 = iVar9 + 1;
                }
                uVar13 = (int)uVar13 >> 1;
              }
              if (-1 < *(int *)(iVar7 + iVar9 * 4 + 0x10)) {
                ((code)FUN_004b39f0)(param_1);
              }
            }
            if (iVar2 == 0) {
              *(u32 *)(iVar7 + 0xc) = *(u32 *)(iVar7 + 0xc) & 0xfffffffd;
            }
            else {
              *(u32 *)(iVar7 + 0xc) = *(u32 *)(iVar7 + 0xc) | 2;
            }
          }
          puStack_30 = puStack_30 + 1;
          iStack_20 = iStack_20 + 1;
        } while (iStack_20 < iVar8);
      }
      iVar16 = iVar16 + 1;
      iVar5 = iVar5 + 0x3c;
    } while (iVar16 < iVar4);
  }
  *(u32 *)(iVar12 + 0x44) = uVar3;
  *(int *)(iVar12 + 0x34) = iVar2;
  return param_2;
}
// FUN_004B59B0 NONMATCHING
u64 FUN_004b59b0(u64 param_1,u64 param_2)

{
  u32 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  u32 *puVar5;
  int iVar6;
  u64 uVar7;
  u32 uVar8;
  int iVar9;
  u32 uVar10;
  int iVar11;
  int iVar12;
  int iStack_4;
  
  iVar9 = (int)param_2;
  iVar2 = ((code)FUN_004b4a60)(param_1,*(u32 *)(iVar9 + 4));
  iVar6 = *(int *)(iVar9 + 8);
  if (iVar6 < 0) {
    param_2 = 0;
  }
  else {
    uVar7 = (u64)(int)FUN_004b1a80((u32 *)(iVar2 + 4));
    iVar3 = FUN_004b6000(*(u32 *)(iVar2 + 0x30),uVar7);
    iVar4 = FUN_004c2120(*(u32 *)(iVar3 + 8));
    iVar11 = 0;
    iVar12 = -1;
    if (0 < iVar4) {
      do {
        FUN_004b62a0(param_1,*(u32 *)(iVar2 + 0x30),uVar7,iVar11,(u32 *)&iStack_4);
        iVar12 = iVar11;
        if (iStack_4 == iVar6) break;
        iVar11 = iVar11 + 1;
        iVar12 = -1;
      } while (iVar11 < iVar4);
    }
    if (-1 < iVar12) {
      puVar5 = (u32 *)FUN_004c21b0(*(u32 *)(iVar3 + 8),iVar12);
      uVar10 = *(u32 *)(iVar9 + 0xc);
      iVar6 = ((code)FUN_004b34d0)(param_1,*puVar5);
      if ((*(u32 *)(iVar6 + 8) & uVar10) != 0) {
        uVar8 = *(u32 *)(iVar6 + 8) >> 4;
        iVar2 = -1;
        for (; uVar10 != 0; uVar10 = uVar10 >> 1) {
          if ((uVar8 & 1) != 0) {
            iVar2 = iVar2 + 1;
          }
          uVar8 = uVar8 >> 1;
        }
        iVar6 = iVar2 * 4 + iVar6;
        if (-1 < *(int *)(iVar6 + 0x10)) {
          iVar2 = (int)param_1;
          uVar1 = *(u32 *)(iVar2 + 0x44);
          *(u32 *)(iVar2 + 0x44) = *(u32 *)(iVar9 + 4);
          ((code)FUN_004b39f0)(param_1,*(u32 *)(iVar6 + 0x10));
          *(u32 *)(iVar2 + 0x44) = uVar1;
        }
      }
    }
  }
  return param_2;
}
// FUN_004B5B50 NONMATCHING
u64 FUN_004b5b50(u64 param_1,u64 param_2)

{
  u32 *puVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  u32 *puVar5;
  
  puVar5 = (u32 *)param_2;
  switch(*puVar5) {
  default:
    param_2 = 0;
    break;
  case 1:
    puVar1 = (u32 *)((code)FUN_004b4a60)(param_1,puVar5[1]);
    *puVar1 = *puVar1 & 0xfffffffe;
    break;
  case 2:
    puVar1 = (u32 *)((code)FUN_004b4a60)(param_1,puVar5[1]);
    *puVar1 = *puVar1 | 1;
    break;
  case 3:
    puVar1 = (u32 *)((code)FUN_004b4a60)(param_1,puVar5[1]);
    lVar3 = FUN_004b1b00(puVar1 + 1);
    FUN_004b1a30(puVar1 + 1);
    if (lVar3 < lVar4) {
      FUN_004b1870((u64)(puVar1 + 1),(u64)(puVar1 + 8),lVar3);
      *puVar1 = *puVar1 | 2;
    }
    break;
  case 4:
    puVar1 = (u32 *)((code)FUN_004b4a60)(param_1,puVar5[1]);
    iVar2 = FUN_004b1a80(puVar1 + 1);
    if (-1 < iVar2 + -1) {
      FUN_004b1870((u64)(puVar1 + 1),(u64)(puVar1 + 8),0);
      *puVar1 = *puVar1 | 2;
    }
    break;
  case 5:
    puVar1 = (u32 *)((code)FUN_004b4a60)(param_1,puVar5[1]);
    FUN_004b1870((u64)(puVar1 + 1),(u64)(puVar1 + 8),puVar5[2]);
    *puVar1 = *puVar1 | 2;
    break;
  case 6:
    puVar1 = (u32 *)((code)FUN_004b4a60)(param_1,puVar5[1]);
    iVar2 = ((code)FUN_004b3030)(param_1,puVar5[2]);
    FUN_004b1870((u64)(puVar1 + 1),(u64)(puVar1 + 8),*(u32 *)(iVar2 + 8));
    *puVar1 = *puVar1 | 2;
    break;
  case 7:
    break;
  case 8:
    ((code)FUN_004b39f0)(param_1,puVar5[2]);
    break;
  case 9:
    break;
  case 10:
    iVar2 = (int)param_1;
    *(float *)(iVar2 + 0x2c) =
         *(float *)(iVar2 + 0x40) * (float)(int)puVar5[2] * *(float *)(iVar2 + 0x3c);
    *(float *)(iVar2 + 0x30) = 1.0 - (float)(int)puVar5[3] * *(float *)(iVar2 + 0x38);
    FUN_004b5380(param_1,iVar2 + 0x2c);
    break;
  case 0xb:
    param_2 = FUN_004b56d0(param_1,param_2);
    break;
  case 0xd:
    param_2 = FUN_004b59b0(param_1,param_2);
  }
  return param_2;
}
// FUN_004B5D80 NONMATCHING
u64 FUN_004b5d80(u64 param_1,u64 param_2,u64 param_3)

{
  u32 uVar1;
  long lVar2;
  int iVar3;
  int iStack_4;
  
  lVar2 = FUN_004c1910(param_3,param_2,4);
  if (lVar2 == 0) {
    param_2 = 0;
  }
  else {
    iVar3 = (int)param_2;
    lVar2 = FUN_004c1910(param_3,iVar3 + 4,4);
    if (lVar2 == 0) {
      param_2 = 0;
    }
    else {
      lVar2 = FUN_004c1910(param_3,&iStack_4,4);
      if (lVar2 == 0) {
        param_2 = 0;
      }
      else {
        if (0 < iStack_4) {
          if (*(int *)(iVar3 + 8) == 0) {
            uVar1 = FUN_004c1d50(4,0x301a9);
            *(u32 *)(iVar3 + 8) = uVar1;
          }
          if (*(int *)(iVar3 + 8) == 0) {
            return 0;
          }
          lVar2 = FUN_004c1f70(*(int *)(iVar3 + 8),iStack_4,0x301a9);
          if (lVar2 == 0) {
            return 0;
          }
          lVar2 = FUN_004c1910(param_3,lVar2,iStack_4 << 2);
          if (lVar2 == 0) {
            return 0;
          }
        }
        lVar2 = FUN_004c1910(param_3,iVar3 + 0xc,4);
        if (lVar2 == 0) {
          param_2 = 0;
        }
      }
    }
  }
  return param_2;
}
// FUN_004B5EC0 NONMATCHING
long FUN_004b5ec0(u64 param_1,long param_2,u64 param_3)

{
  u32 *puVar1;
  u32 uVar2;
  long lVar3;
  int iVar4;
  int iStack_4;
  
  if (param_2 == 0) {
    param_2 = FUN_004b6040();
    if (param_2 == 0) {
      return 0;
    }
  }
  lVar3 = FUN_004c1910(param_3,&iStack_4,4);
  if (lVar3 == 0) {
    param_2 = 0;
  }
  else if (0 < iStack_4) {
    puVar1 = (u32 *)FUN_004c1f70(*(u32 *)param_2,iStack_4,0x301a9);
    if (puVar1 == (u32 *)0x0) {
      param_2 = 0;
    }
    else {
      iVar4 = 0;
      if (0 < iStack_4) {
        do {
          *puVar1 = 0xffffffff;
          puVar1[1] = 0xffffffff;
          puVar1[3] = 0xffffffff;
          uVar2 = FUN_004c1d50(4,0x301a9);
          puVar1[2] = uVar2;
          lVar3 = (u64)(((code)FUN_004b5d80)(param_1,puVar1,param_3));
          if (lVar3 == 0) {
            return 0;
          }
          iVar4 = iVar4 + 1;
          puVar1 = puVar1 + 4;
        } while (iVar4 < iStack_4);
      }
    }
  }
  return param_2;
}
#pragma schedule on
// FUN_004B6000
int FUN_004b6000(int *param_1,int param_2)
{
  int iVar1;
  
  if (*param_1 != 0) {
    iVar1 = FUN_004c2090(*param_1);
    iVar1 = iVar1 + param_2 * 0x10;
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}
#pragma schedule off
// FUN_004B6040 NONMATCHING
long FUN_004b6040(void)

{
  int iVar1;
  u32 *puVar2;
  long lVar3;
  long lVar4;
  int *piVar5;
  int iVar6;
  
  lVar3 = (*DAT_00960188)(0x95fb94,0x301a9);
  if (lVar3 == 0) {
    lVar3 = 0;
  }
  else {
    lVar4 = FUN_004c1d50(0x10,0x301a9);
    piVar5 = (int *)lVar3;
    *piVar5 = (int)lVar4;
    if (lVar4 == 0) {
      lVar4 = 0;
    }
    else {
      piVar5[1] = 1;
      lVar4 = lVar3;
    }
    if (lVar4 == 0) {
      if (*piVar5 != 0) {
        iVar1 = FUN_004c2120();
        puVar2 = (u32 *)FUN_004c2090(*piVar5);
        if (((0 < iVar1) && (puVar2 != (u32 *)0x0)) && (iVar6 = 0, 0 < iVar1)) {
          do {
            if (puVar2[2] != 0) {
              FUN_004c20b0();
            }
            puVar2[2] = 0;
            iVar6 = iVar6 + 1;
            *puVar2 = 0xffffffff;
            puVar2[1] = 0xffffffff;
            puVar2[3] = 0xffffffff;
            puVar2 = puVar2 + 4;
          } while (iVar6 < iVar1);
        }
        FUN_004c20b0(*piVar5);
        *piVar5 = 0;
      }
      piVar5[1] = 0;
      (*DAT_0096018c)(0x95fb94,lVar3);
      lVar3 = 0;
    }
  }
  return lVar3;
}
// FUN_004B6190 NONMATCHING
u32 FUN_004b6190(u64 param_1)

{
  int iVar1;
  u32 *puVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)param_1;
  if (*piVar3 != 0) {
    iVar1 = FUN_004c2120();
    puVar2 = (u32 *)FUN_004c2090(*piVar3);
    if (((0 < iVar1) && (puVar2 != (u32 *)0x0)) && (iVar4 = 0, 0 < iVar1)) {
      do {
        if (puVar2[2] != 0) {
          FUN_004c20b0();
        }
        puVar2[2] = 0;
        iVar4 = iVar4 + 1;
        *puVar2 = 0xffffffff;
        puVar2[1] = 0xffffffff;
        puVar2[3] = 0xffffffff;
        puVar2 = puVar2 + 4;
      } while (iVar4 < iVar1);
    }
    FUN_004c20b0(*piVar3);
    *piVar3 = 0;
  }
  piVar3[1] = 0;
  (*DAT_0096018c)(0x95fb94,param_1);
  return 1;
}
// FUN_004B6270 NONMATCHING
u32 FUN_004b6270(u32 param_1)
{
  u32 flags;
  u32 *ptr;

  ptr = (u32 *)param_1;
  flags = ptr[1];
  if ((flags & 1) == 0) {
    return param_1;
  }
  ptr[1] = flags & 0xfffffffe;
  return param_1;
}
// FUN_004B62A0 NONMATCHING
u64
FUN_004b62a0(int param_1,u64 param_2,u64 param_3,u64 param_4,
            u32 *param_5)

{
  long lVar1;
  
  lVar1 = FUN_004c21b0(*(u32 *)param_2,param_3);
  if (lVar1 == 0) {
    param_2 = 0;
  }
  else {
    lVar1 = FUN_004c21b0(*(u32 *)((int)lVar1 + 8),param_4);
    if (lVar1 == 0) {
      param_2 = 0;
    }
    else {
      lVar1 = FUN_004c21b0(*(u32 *)(param_1 + 0x10),*(u32 *)lVar1);
      if (lVar1 == 0) {
        param_2 = 0;
      }
      else {
        *param_5 = *(u32 *)lVar1;
      }
    }
  }
  return param_2;
}
// FUN_004B6350 NONMATCHING
void FUN_004b6350(void)

{
  thunk_FUN_004c3970(0x1c,DAT_007cdcec,4,DAT_007cdcf0,0x95fa50,0x401a9);
  thunk_FUN_004c3970(0x90,DAT_007cdcec,4,DAT_007cdcf0,0x95fa74,0x401a9);
  thunk_FUN_004c3970(0x158,DAT_007cdcec,4,DAT_007cdcf0,0x95fa98,0x401b1);
  thunk_FUN_004c3970(0x10,DAT_007cdcec,4,DAT_007cdcf0,0x95fabc,0x401a9);
  thunk_FUN_004c3970(0x10,DAT_007cdcec,4,DAT_007cdcf0,0x95fae0,0x401a9);
  thunk_FUN_004c3970(0x10,DAT_007cdcec,4,DAT_007cdcf0,0x95fb04,0x401a9);
  thunk_FUN_004c3970(0xa0,DAT_007cdcec,4,DAT_007cdcf0,0x95fb28,0x401a9);
  thunk_FUN_004c3970(0xc,DAT_007cdcec,4,DAT_007cdcf0,0x95fb4c,0x401b0);
  thunk_FUN_004c3970(0x10,DAT_007cdcec,4,DAT_007cdcf0,0x95fb70,0x401a9);
  thunk_FUN_004c3970(8,DAT_007cdcec,4,DAT_007cdcf0,0x95fb94,0x401a9);
  thunk_FUN_004c3970(0x10,DAT_007cdcec,4,DAT_007cdcf0,0x95fbb8,0x401a9);
  DAT_007ce898 = 1;
  return;
}
// FUN_004B6500 NONMATCHING
void FUN_004b6500(void)

{
  FUN_004c3c30(0x95fa50);
  FUN_004c3c30(0x95fa74);
  FUN_004c3c30(0x95fa98);
  FUN_004c3c30(0x95fabc);
  FUN_004c3c30(0x95fae0);
  FUN_004c3c30(0x95fb04);
  FUN_004c3c30(0x95fb28);
  FUN_004c3c30(0x95fb4c);
  FUN_004c3c30(0x95fb70);
  FUN_004c3c30(0x95fb94);
  FUN_004c3c30(0x95fbb8);
  return;
}
// FUN_004B65A0 NONMATCHING
u64 FUN_004b65a0(u64 param_1)

{
  long lVar1;
  
  lVar1 = thunk_FUN_004c3970(0x18,DAT_007cdcf4,4,DAT_007cdcf8,0x95fee0,0x4001b);
  DAT_007ce8a4 = (int)lVar1;
  if (lVar1 == 0) {
    param_1 = 0;
  }
  return param_1;
}
#pragma schedule on
// FUN_004B6600 NONMATCHING
u64 FUN_004b6600(u64 param_1)
{
  u64 uVar2;

  uVar2 = param_1;
  DAT_007ce8a0 = 0;
  if (DAT_007ce8a4 != 0) {
    FUN_004c3c30();
    DAT_007ce8a4 = 0;
  }
  return uVar2;
}
#pragma schedule on
// FUN_004B6640
bool FUN_004b6640(void)
{
  int iVar1;

  iVar1 = FUN_004ca520(0,0x1b7,(u8 *)FUN_004b65a0_abs,(u8 *)FUN_004b6600_abs);
  return 0 < iVar1;
}
#pragma schedule off
// FUN_004B6680 NONMATCHING
u32 FUN_004b6680(int *param_1)

{
  u32 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  if (DAT_007ce8a0 < 0x10) {
    iVar4 = 0;
    if (0 < DAT_007ce8a0) {
      piVar3 = (int *)(&DAT_0095fbe0);
      do {
        if (*param_1 == *piVar3) {
          uStack_8 = 0x1b7;
          uStack_4 = FUN_004c1d10(0);
          FUN_004c1c50(&uStack_8);
          return 0;
        }
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 0xc;
      } while (iVar4 < DAT_007ce8a0);
    }
    iVar7 = param_1[1];
    iVar5 = param_1[2];
    iVar2 = DAT_007ce8a0 * 0x30;
    iVar4 = DAT_007ce8a0 * 0xc;
    iVar6 = param_1[3];
    uVar1 = 1;
    DAT_007ce8a0 = DAT_007ce8a0 + 1;
    (&DAT_0095fbe0)[iVar4] = *param_1;
    *(int *)(&DAT_0095fbe4 + iVar2) = iVar7;
    *(int *)(&DAT_0095fbe8 + iVar2) = iVar5;
    *(int *)(&DAT_0095fbec + iVar2) = iVar6;
    iVar6 = param_1[5];
    iVar4 = param_1[6];
    iVar5 = param_1[7];
    *(int *)(&DAT_0095fbf0 + iVar2) = param_1[4];
    *(int *)(&DAT_0095fbf4 + iVar2) = iVar6;
    *(int *)(&DAT_0095fbf8 + iVar2) = iVar4;
    *(int *)(&DAT_0095fbfc + iVar2) = iVar5;
    iVar6 = param_1[9];
    iVar4 = param_1[10];
    iVar5 = param_1[0xb];
    *(int *)(&DAT_0095fc00 + iVar2) = param_1[8];
    *(int *)(&DAT_0095fc04 + iVar2) = iVar6;
    *(int *)(&DAT_0095fc08 + iVar2) = iVar4;
    *(int *)(&DAT_0095fc0c + iVar2) = iVar5;
  }
  else {
    uStack_10 = 0x1b7;
    uStack_c = FUN_004c1d10(1);
    FUN_004c1c50(&uStack_10);
    uVar1 = 0;
  }
  return uVar1;
}
// FUN_004B67B0 NONMATCHING
u32 * FUN_004b67b0(int param_1)

{
  int *piVar1;
  int iVar2;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar2 = 0;
  if (0 < DAT_007ce8a0) {
    piVar1 = (int *)(&DAT_0095fbe0);
    do {
      if (param_1 == *piVar1) {
        return &DAT_0095fbe0 + iVar2 * 0xc;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 0xc;
    } while (iVar2 < DAT_007ce8a0);
  }
  uStack_8 = 0x1b7;
  uStack_4 = FUN_004c1d10(2);
  FUN_004c1c50(&uStack_8);
  return (u32 *)0x0;
}
// FUN_004B6840 NONMATCHING
u64 FUN_004b6840(u32 param_1,int param_2,int param_3,u32 param_4)

{
  u32 *puVar1;
  u64 uVar2;
  int *piVar3;
  int iVar4;
  u32 *puVar5;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar4 = 0;
  if (0 < DAT_007ce8a0) {
    piVar3 = (int *)(&DAT_0095fbe0);
    do {
      if (param_2 == *piVar3) {
        puVar5 = &DAT_0095fbe0 + iVar4 * 0xc;
        goto LAB_004b68d8;
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 0xc;
    } while (iVar4 < DAT_007ce8a0);
  }
  uStack_8 = 0x1b7;
  uStack_4 = FUN_004c1d10(2);
  FUN_004c1c50(&uStack_8);
  puVar5 = (u32 *)0x0;
LAB_004b68d8:
  if (puVar5 == (u32 *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (*DAT_00960178)(puVar5[0xb] + param_3 * puVar5[2] + 0x18,0x3001b);
    puVar1 = (u32 *)uVar2;
    puVar1[1] = param_3;
    puVar1[3] = param_1;
    puVar1[2] = param_4;
    *puVar1 = (u32)(puVar5);
    puVar1[4] = (u32)(puVar1 + 6);
    if ((int)puVar5[0xb] < 1) {
      puVar1[5] = 0;
    }
    else {
      puVar1[5] = puVar1[4] + param_3 * puVar5[2];
    }
  return uVar2;
  }
}
#pragma schedule on
// FUN_004B6980
u32 FUN_004b6980(void)
{
  DAT_0096017c_abs[0]();
  return 1;
}
#pragma schedule off
// FUN_004B69B0 NONMATCHING
u64 FUN_004b69b0(u64 param_1)

{
  long lVar1;
  long lVar2;
  u64 uVar3;
  
  lVar1 = FUN_004c58a0(2,1,param_1);
  if (lVar1 == 0) {
    uVar3 = 0;
  }
  else {
    lVar2 = FUN_004c1600(lVar1,0x1b,0,0);
    if (lVar2 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = FUN_004b6a40(lVar1);
      FUN_004c5780(lVar1,0);
    }
  }
  return uVar3;
}
// FUN_004B6A40 NONMATCHING
long FUN_004b6a40(u64 param_1)

{
  long lVar1;
  int *piVar2;
  int iVar3;
  u32 *puVar4;
  u32 uStack_20;
  u32 uStack_1c;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  lVar1 = FUN_004c1910(param_1,&iStack_4,4);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else if (iStack_4 == 0x100) {
    lVar1 = FUN_004c1910(param_1,&iStack_8,4);
    if (lVar1 == 0) {
      lVar1 = 0;
    }
    else {
      iVar3 = 0;
      if (0 < DAT_007ce8a0) {
        piVar2 = (int *)(&DAT_0095fbe0);
        do {
          if (iStack_8 == *piVar2) {
            puVar4 = &DAT_0095fbe0 + iVar3 * 0xc;
            goto LAB_004b6b28;
          }
          iVar3 = iVar3 + 1;
          piVar2 = piVar2 + 0xc;
        } while (iVar3 < DAT_007ce8a0);
      }
      uStack_20 = 0x1b7;
      uStack_1c = FUN_004c1d10(2);
      FUN_004c1c50(&uStack_20);
      puVar4 = (u32 *)0x0;
LAB_004b6b28:
      if (puVar4 == (u32 *)0x0) {
        lVar1 = 0;
      }
      else {
        lVar1 = FUN_004c1910(param_1,&iStack_c,4);
        if (lVar1 == 0) {
          lVar1 = 0;
        }
        else {
          lVar1 = FUN_004c1910(param_1,&iStack_10,4);
          if (lVar1 == 0) {
            lVar1 = 0;
          }
          else {
            lVar1 = FUN_004c18b0(param_1,&iStack_14,4);
            if (lVar1 == 0) {
              lVar1 = 0;
            }
            else {
              lVar1 = (long)(FUN_004b67b0(iStack_8));
              if (lVar1 == 0) {
                lVar1 = 0;
              }
              else {
                iVar3 = (int)lVar1;
                lVar1 = (*DAT_00960178)(*(int *)(iVar3 + 0x2c) +
                                        iStack_c * *(int *)(iVar3 + 8) + 0x18,0x3001b);
                piVar2 = (int *)lVar1;
                piVar2[1] = iStack_c;
                piVar2[3] = iStack_14;
                piVar2[2] = iStack_10;
                *piVar2 = iVar3;
                piVar2[4] = (int)(piVar2 + 6);
                if (*(int *)(iVar3 + 0x2c) < 1) {
                  piVar2[5] = 0;
                }
                else {
                  piVar2[5] = piVar2[4] + iStack_c * *(int *)(iVar3 + 8);
                }
              }
              if (lVar1 == 0) {
                lVar1 = 0;
              }
              else {
                (*(code *)puVar4[8])(param_1,lVar1);
              }
            }
          }
        }
      }
    }
  }
  else {
    lVar1 = 0;
  }
  return lVar1;
}
// FUN_004B6C80 NONMATCHING
u32 FUN_004b6c80(u64 param_1,u64 param_2)

{
  u32 uVar1;
  u64 uVar2;
  long lVar3;
  int *piVar4;
  u32 uStack_4;
  
  uStack_4 = 0x100;
  uVar2 = FUN_004b6d90();
  FUN_004c15a0(param_2,0x1b,uVar2,0x37002,0x37);
  lVar3 = FUN_004c17f0(param_2,&uStack_4,4);
  if (lVar3 == 0) {
    uVar1 = 0;
  }
  else {
    piVar4 = (int *)param_1;
    lVar3 = FUN_004c17f0(param_2,*piVar4,4);
    if (lVar3 == 0) {
      uVar1 = 0;
    }
    else {
      lVar3 = FUN_004c17f0(param_2,piVar4 + 1,4);
      if (lVar3 == 0) {
        uVar1 = 0;
      }
      else {
        lVar3 = FUN_004c17f0(param_2,piVar4 + 2,4);
        if (lVar3 == 0) {
          uVar1 = 0;
        }
        else {
          lVar3 = FUN_004c1750(param_2,piVar4 + 3,4);
          if (lVar3 == 0) {
            uVar1 = 0;
          }
          else {
            (**(code **)(*piVar4 + 0x24))(param_1,param_2);
            uVar1 = 1;
          }
        }
      }
    }
  }
  return uVar1;
}
#pragma optimization_level 3
#pragma schedule on
// FUN_004B6D90 NONMATCHING
int FUN_004b6d90(int *param_1)
{
  int iVar1;

  iVar1 = 0;
  iVar1 = iVar1 + 0x14;
  iVar1 = iVar1 + (**(code **)(*param_1 + 0x28))();
  return iVar1;
}
#pragma optimization_level 2
// FUN_004B6DD0 NONMATCHING
int FUN_004b6dd0(int *param_1)
{
  u32 *vtable;
  u32 *puVar1;
  u32 *puVar2;
  int iVar3;
  u32 *puVar4;
  int stride;

  vtable = (u32 *)*param_1;
  puVar1 = (u32 *)param_1[4];
  stride = (int)vtable[2];
  iVar3 = 0;
  puVar2 = (u32 *)*puVar1;
  puVar4 = puVar1;
  while (puVar2 != puVar1) {
    puVar4 = (u32 *)((int)puVar4 + stride);
    iVar3 = iVar3 + 1;
    puVar2 = (u32 *)*puVar4;
  }
  return iVar3;
}
// FUN_004B6E10 NONMATCHING
void FUN_004b6e10(int param_1,int param_2)

{
  u32 *puVar1;
  u32 minusOne;

  puVar1 = (u32 *)(*DAT_00960178_abs)(param_1 * param_2 + 0x4c,0x3001b);
  minusOne = 0xffffffff;
  puVar1[0xb] = param_1;
  *puVar1 = 0;
  puVar1[2] = 0;
  puVar1[1] = 0;
  puVar1[0xc] = 0;
  puVar1[5] = 0xbf800000;
  puVar1[4] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[9] = param_2;
  puVar1[10] = minusOne;
  puVar1[8] = param_2;
  puVar1[0xd] = 0;
  puVar1[0xe] = (u32)(puVar1);
  puVar1[0xf] = 0;
  puVar1[0x11] = 0;
  puVar1[0x10] = 0;
  puVar1[0x12] = 0;
  return;
}
#pragma alias DAT_0096017c_abs DAT_0096017c
extern void (*DAT_0096017c_abs[])(void);

#pragma optimization_level 3
// FUN_004B6EB0
void FUN_004b6eb0(void)
{
  DAT_0096017c_abs[0]();
}
#pragma optimization_level 2
// FUN_004B6EC0 NONMATCHING
u32 FUN_004b6ec0(u32 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  *param_1 = (u32)(param_2);
  param_1[1] = 0;
  iVar4 = *param_2;
  param_1[9] = *(u32 *)(iVar4 + 4);
  param_1[10] = *(u32 *)(iVar4 + 8);
  param_1[0xf] = *(u32 *)(iVar4 + 0xc);
  param_1[0x10] = *(u32 *)(iVar4 + 0x10);
  param_1[0x11] = *(u32 *)(iVar4 + 0x14);
  param_1[0x12] = *(u32 *)(iVar4 + 0x18);
  iVar4 = param_1[0xb];
  iVar6 = 0;
  if (iVar4 < 1) {
    iVar6 = param_1[10];
  }
  else {
    do {
      (*(code *)param_1[0x11])
                (0,(int)param_1 + iVar6 * param_1[9] + 0x4c,param_2[4] + iVar6 * param_1[10],
                 param_2[4] + param_1[10] * (iVar6 + iVar4),param_2[5]);
      iVar4 = param_1[0xb];
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar4);
    iVar6 = param_1[10];
  }
  piVar2 = (int *)(param_1 + 0x13);
  iVar5 = param_2[4];
  iVar1 = 0;
  iVar3 = iVar5 + iVar4 * iVar6;
  if (iVar4 < 1) {
    iVar4 = iVar4 * iVar6;
  }
  else {
    do {
      *piVar2 = iVar5;
      iVar1 = iVar1 + 1;
      piVar2[1] = iVar3;
      iVar4 = param_1[10];
      piVar2 = (int *)((int)piVar2 + param_1[9]);
      iVar5 = iVar5 + iVar4;
      iVar3 = iVar3 + iVar4;
    } while (iVar1 < (int)param_1[0xb]);
    iVar4 = param_1[0xb] * iVar4;
  }
  param_1[2] = param_2[4] + iVar4 * 2;
  return 1;
}
#pragma optimization_level 3
// FUN_004B7010
void FUN_004b7010(int param_1,u32 param_2,u32 param_3)

{
  *(u32 *)(param_1 + 0x18) = param_2;
  *(u32 *)(param_1 + 0x1c) = param_3;
  return;
}
#pragma optimization_level 2
#pragma schedule off
// FUN_004B7020 NONMATCHING
u32 FUN_004b7020(int param_1,int param_2)
{
  FUN_00521250((param_1 + 0x4c),(param_2 + 0x4c),
               *(int *)(param_1 + 0x24) * *(int *)(param_1 + 0x2c));
  return 1;
}
// FUN_004B7050 NONMATCHING
u32 FUN_004b7050(float param_1,u64 param_2)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  long lVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  
  bVar3 = false;
  piVar6 = (int *)param_2;
  bVar2 = false;
  if (((float)piVar6[5] < (float)piVar6[1]) && ((float)piVar6[1] - param_1 <= (float)piVar6[5])) {
    bVar3 = true;
  }
  piVar6[1] = (int)((float)piVar6[1] - param_1);
  fVar11 = (float)piVar6[1];
  if (0.0 <= fVar11) {
    iVar9 = piVar6[0xb];
    piVar8 = piVar6 + 0x13;
    while (bVar1 = iVar9 != 0, iVar9 = iVar9 + -1, bVar1) {
      iVar7 = *piVar8;
      if ((float)piVar6[1] < *(float *)(iVar7 + 4)) {
        do {
          piVar8[1] = iVar7;
          *piVar8 = *(int *)*piVar8;
          iVar7 = *piVar8;
        } while ((float)piVar6[1] < *(float *)(iVar7 + 4));
        iVar5 = *piVar6;
      }
      else {
        iVar5 = *piVar6;
      }
      (*(code *)piVar6[0x11])(piVar8,iVar7,piVar8[1],*(u32 *)(iVar5 + 0x14));
      piVar8 = (int *)((int)piVar8 + piVar6[9]);
    }
    piVar6[2] = 0;
  }
  else {
    fVar10 = *(float *)(*piVar6 + 0xc);
    while (fVar11 < 0.0) {
      fVar11 = (float)piVar6[1] + fVar10;
      piVar6[1] = (int)fVar11;
    }
    FUN_004b6ec0((u32 *)(int)param_2,0);
    bVar3 = (bool)(bVar3 | (float)piVar6[1] < (float)piVar6[5]);
    bVar2 = true;
  }
  if (((bVar3) && ((code *)piVar6[3] != (code *)0x0)) &&
     (lVar4 = (*(code *)piVar6[3])(param_2,piVar6[4]), lVar4 == 0)) {
    piVar6[3] = 0;
  }
  if (((bVar2) && ((code *)piVar6[6] != (code *)0x0)) &&
     (lVar4 = (*(code *)piVar6[6])(param_2,piVar6[7]), lVar4 == 0)) {
    piVar6[6] = 0;
  }
  return 1;
}
// FUN_004B7240 NONMATCHING
u32 FUN_004b7240(float param_1,u64 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  bool bVar6;
  long lVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  float fVar12;
  int iVar13;
  
  if (0.0 < param_1) {
    piVar9 = (int *)param_2;
    iVar11 = *piVar9;
    iVar1 = piVar9[0xb];
    bVar6 = false;
    fVar12 = *(float *)(iVar11 + 0xc);
    bVar5 = false;
    if (((float)piVar9[1] < (float)piVar9[5]) && ((float)piVar9[5] <= (float)piVar9[1] + param_1)) {
      bVar5 = true;
    }
    param_1 = (float)piVar9[1] + param_1;
    piVar9[1] = (int)param_1;
    if (fVar12 < param_1) {
      if (fVar12 < param_1) {
        bVar6 = true;
        while (fVar12 < param_1) {
          param_1 = (float)piVar9[1] - fVar12;
          piVar9[1] = (int)param_1;
          bVar5 = (bool)(bVar5 | (float)piVar9[5] <= param_1);
        }
      }
      FUN_004b6ec0((u32 *)(int)param_2,(int *)iVar11);
      piVar9[1] = (int)param_1;
    }
    if (piVar9[2] == 0) {
      iVar13 = piVar9[1];
      FUN_004b6ec0((u32 *)(int)param_2,(int *)iVar11);
      piVar9[1] = iVar13;
    }
    iVar13 = *(int *)(iVar11 + 4);
    iVar2 = piVar9[10];
    iVar11 = *(int *)(iVar11 + 0x10);
    iVar8 = 0;
    piVar10 = (int *)piVar9[2];
    while ((piVar10 < (int *)(iVar11 + iVar13 * iVar2) &&
           (*(float *)(*piVar10 + 4) <= (float)piVar9[1]))) {
      do {
        iVar4 = iVar8 * piVar9[9];
        iVar8 = iVar8 + 1;
        if (iVar1 <= iVar8) {
          iVar8 = 0;
        }
        iVar3 = *(int *)((int)piVar9 + iVar4 + 0x50);
      } while (iVar3 != *piVar10);
      *(int *)((int)piVar9 + iVar4 + 0x4c) = iVar3;
      *(int *)((int)piVar9 + iVar4 + 0x50) = piVar9[2];
      piVar9[2] = piVar9[2] + piVar9[10];
      piVar10 = (int *)piVar9[2];
    }
    piVar10 = piVar9 + 0x13;
    iVar11 = 0;
    if (0 < iVar1) {
      do {
        (*(code *)piVar9[0x11])
                  (piVar9[1],piVar10,*piVar10,piVar10[1],*(u32 *)(*piVar9 + 0x14));
        iVar11 = iVar11 + 1;
        piVar10 = (int *)((int)piVar10 + piVar9[9]);
      } while (iVar11 < iVar1);
    }
    if (((bVar5) && ((code *)piVar9[3] != (code *)0x0)) &&
       (lVar7 = (*(code *)piVar9[3])(param_2,piVar9[4]), lVar7 == 0)) {
      piVar9[3] = 0;
    }
    if (((bVar6) && ((code *)piVar9[6] != (code *)0x0)) &&
       (lVar7 = (*(code *)piVar9[6])(param_2,piVar9[7]), lVar7 == 0)) {
      piVar9[6] = 0;
    }
  }
  return 1;
}
// FUN_004B74C0 NONMATCHING
u32 FUN_004b74c0(float param_1,int param_2)

{
  param_1 = param_1 - *(float *)(param_2 + 4);
  if (param_1 < 0.0) {
    FUN_004b7050(-param_1,0);
  }
  else {
    FUN_004b7240(0,0);
  }
  return 1;
}
// FUN_004B7510 NONMATCHING
u32 FUN_004b7510(u32 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_2 + 0x2c)) {
    do {
      (**(code **)(param_2 + 0x40))
                (param_1,iVar1 * *(int *)(param_2 + 0x24) + param_2 + 0x4c,
                 iVar1 * *(int *)(param_3 + 0x24) + param_3 + 0x4c,
                 iVar1 * *(int *)(param_4 + 0x24) + param_4 + 0x4c);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_2 + 0x2c));
  }
  return 1;
}
// FUN_004B75D0 NONMATCHING
void FUN_004b75d0(int param_1,u32 param_2,u64 param_3,int param_4)

{
  int iVar1;
  
  if (param_4 == -1) {
    param_4 = *(int *)(param_1 + 0x20);
  }
  FUN_004b6e10(param_3,param_4);
  *(int *)(iVar1 + 0x38) = param_1;
  *(u32 *)(iVar1 + 0x34) = param_2;
  *(u32 *)(iVar1 + 0x30) = 1;
  return;
}
// FUN_004B7630 NONMATCHING
u64 FUN_004b7630(u64 param_1)

{
  u32 uVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  uVar1 = FUN_004c1d50(4,*(u32 *)(iVar2 + 4) | 0x40000);
  *(u32 *)(iVar2 + 0x10) = uVar1;
  if (*(int *)(iVar2 + 0x10) == 0) {
    param_1 = 0;
  }
  else {
    *(u32 *)(iVar2 + 0x14) = 0;
  }
  return param_1;
}
#pragma schedule on
// FUN_004B7690
u32 FUN_004b7690(int param_1)

{
  FUN_004c20b0(*(u32 *)(param_1 + 0x10));
  return 1;
}
#pragma schedule off
// FUN_004B76B0 NONMATCHING
u64 FUN_004b76b0(u64 param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = (int)param_1;
  piVar1 = (int *)FUN_004c21d0(*(u32 *)(iVar4 + 0x10));
  piVar2 = (int *)FUN_004c21e0(*(u32 *)(iVar4 + 0x10));
  while( true ) {
    if (piVar1 == piVar2) {
      return 0;
    }
    if (param_2 == *piVar1) break;
    piVar1 = piVar1 + 1;
  }
  iVar3 = FUN_004c2120(*(u32 *)(iVar4 + 0x10));
  piVar2 = (int *)FUN_004c21b0(*(u32 *)(iVar4 + 0x10),iVar3 + -1);
  *piVar1 = *piVar2;
  FUN_004c2080(*(u32 *)(iVar4 + 0x10),1);
  return param_1;
}
#pragma optimization_level 3
// FUN_004B7750
u32 FUN_004b7750(int param_1)

{
  return *(u32 *)(param_1 + 0x14);
}
#pragma optimization_level 2
// FUN_004B7760
#pragma schedule on
u32 FUN_004b7760(u32 param_1,u32 param_2)

{
  *(u32 *)((int)param_1 + 0x14) = param_2;
  return param_1;
}
#pragma schedule off
// FUN_004B7770 NONMATCHING
u32 FUN_004b7770(int *param_1)

{
  u32 *puVar1;
  u32 *puVar2;
  
  puVar1 = (u32 *)FUN_004c21e0(param_1[1]);
  for (puVar2 = (u32 *)FUN_004c21d0(param_1[1]); puVar2 != puVar1; puVar2 = puVar2 + 1) {
    (**(code **)(*param_1 + 0x1c))(*puVar2);
  }
  FUN_004c20b0(param_1[1]);
  return 1;
}
// FUN_004B77F0 NONMATCHING
u32 FUN_004b77f0(int *param_1,u64 param_2)

{
  code *pcVar1;
  u32 uVar2;
  u32 *puVar3;
  u32 *puVar4;
  u64 uVar5;
  long lVar6;
  
  pcVar1 = *(code **)(*param_1 + 0x20);
  puVar3 = (u32 *)FUN_004c21e0(param_1[1]);
  puVar4 = (u32 *)FUN_004c21d0(param_1[1]);
  while( true ) {
    if (puVar4 == puVar3) {
      return 0;
    }
    uVar2 = *puVar4;
    uVar5 = (*pcVar1)(uVar2);
    lVar6 = (*DAT_00960158)(uVar5,param_2);
    if (lVar6 == 0) break;
    puVar4 = puVar4 + 1;
  }
  return uVar2;
}
// FUN_004B78B0 NONMATCHING
u32 FUN_004b78b0(int *param_1)

{
  int iVar1;
  u32 uVar2;
  u32 *puVar3;
  u32 *puVar4;
  int iVar5;
  
  if (param_1 == *(int **)(*param_1 + 0x14)) {
    *(u32 *)(*param_1 + 0x14) = 0;
  }
  iVar1 = *param_1;
  puVar3 = (u32 *)FUN_004c21d0(*(u32 *)(iVar1 + 0x10));
  puVar4 = (u32 *)FUN_004c21e0(*(u32 *)(iVar1 + 0x10));
  do {
    if (puVar3 == puVar4) {
LAB_004b7948:
      puVar3 = (u32 *)FUN_004c21e0(param_1[1]);
      puVar4 = (u32 *)FUN_004c21d0(param_1[1]);
      if (puVar4 == puVar3) {
        iVar1 = param_1[1];
      }
      else {
        do {
          uVar2 = *puVar4;
          puVar4 = puVar4 + 1;
          (**(code **)(*param_1 + 0x1c))(uVar2);
        } while (puVar4 != puVar3);
        iVar1 = param_1[1];
      }
      FUN_004c20b0(iVar1);
      (*DAT_0096017c)(param_1);
      return 1;
    }
    if (param_1 == (int *)*puVar3) {
      iVar5 = FUN_004c2120(*(u32 *)(iVar1 + 0x10));
      puVar4 = (u32 *)FUN_004c21b0(*(u32 *)(iVar1 + 0x10),iVar5 + -1);
      *puVar3 = *puVar4;
      FUN_004c2080(*(u32 *)(iVar1 + 0x10),1);
      goto LAB_004b7948;
    }
    puVar3 = puVar3 + 1;
  } while( true );
}
// FUN_004B79D0 NONMATCHING
int * FUN_004b79d0(long param_1,u64 param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  u32 *puVar4;
  long lVar5;
  int iVar6;
  u32 uStack_18;
  u32 uStack_14;
  int iStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  lVar5 = FUN_004c1600(param_2,1,&uStack_4,&uStack_8);
  if (lVar5 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    iVar6 = (int)param_1;
    if (uStack_8 < *(u32 *)(iVar6 + 0xc)) {
      piVar1 = (int *)(**(code **)(iVar6 + 0x2c))(param_2);
    }
    else {
      lVar5 = FUN_004c5250(param_2,&iStack_c,uStack_4);
      if (lVar5 == 0) {
        piVar1 = (int *)0x0;
      }
      else {
        piVar1 = (int *)(*DAT_00960178)(8,*(u32 *)(iVar6 + 4) | 0x30000);
        if (piVar1 == (int *)0x0) {
          uStack_18 = 0x1bf;
          uStack_14 = FUN_004c1d10(0xffffffff80000013,8);
          FUN_004c1c50(&uStack_18);
          piVar1 = (int *)0x0;
        }
        else {
          iVar2 = FUN_004c1d50(4,*(u32 *)(iVar6 + 4) | 0x30000);
          piVar1[1] = iVar2;
          if (piVar1[1] == 0) {
            piVar3 = (int *)0x0;
          }
          else {
            *piVar1 = iVar6;
            lVar5 = FUN_004c1e70(*(u32 *)(iVar6 + 0x10),*(u32 *)(iVar6 + 4) | 0x30000);
            if (lVar5 == 0) {
              param_1 = 0;
            }
            else {
              *(u32 *)lVar5 = (u32)piVar1;
            }
            piVar3 = piVar1;
            if (param_1 == 0) {
              FUN_004c20b0(piVar1[1]);
              piVar3 = (int *)0x0;
            }
          }
          if (piVar3 == (int *)0x0) {
            (*DAT_0096017c)(piVar1);
            piVar1 = (int *)0x0;
          }
        }
        if (piVar1 == (int *)0x0) {
          piVar1 = (int *)0x0;
        }
        else {
          while (iStack_c != 0) {
            iStack_c = iStack_c + -1;
            lVar5 = FUN_004c1600(param_2,*(u32 *)(iVar6 + 8),&uStack_4,&uStack_8);
            if ((lVar5 == 0) || (lVar5 = (**(code **)(iVar6 + 0x28))(param_2), lVar5 == 0)) {
              if (piVar1 == *(int **)(*piVar1 + 0x14)) {
                *(u32 *)(*piVar1 + 0x14) = 0;
              }
              FUN_004b76b0(*piVar1,(int)(int)piVar1);
              FUN_004b7770(piVar1);
              (*DAT_0096017c)(piVar1);
              return (int *)0x0;
            }
            puVar4 = (u32 *)FUN_004c1e70(piVar1[1],*(u32 *)(*piVar1 + 4) | 0x30000);
            *puVar4 = (int)lVar5;
            (**(code **)(*piVar1 + 0x18))(lVar5);
            (**(code **)(iVar6 + 0x1c))(lVar5);
          }
        }
      }
    }
  }
  return piVar1;
}
// FUN_004B7C60 NONMATCHING
u64
FUN_004b7c60(u32 param_1,u32 *param_2,u32 *param_3,u32 param_4,
            u64 param_5)

{
  int *piVar1;
  long lVar2;
  
  piVar1 = (int *)*param_2;
  *param_3 = param_4;
  param_3[1] = param_1;
  if (((*piVar1 != DAT_0077e520) || (lVar2 = FUN_004b8290((u64)(int)(param_3 + 2),(u32 *)(int)param_5), lVar2 == 0)) &&
     (*(int *)*param_2 == DAT_0077e550)) {
  }
  return 0;
}
// FUN_004B7D00 NONMATCHING
u64 FUN_004b7d00(u64 param_1,u64 param_2)

{
  int *piVar1;
  long lVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iStack_8;
  u8 auStack_4 [4];
  
  lVar2 = FUN_004c1910(param_1,auStack_4,4);
  if (lVar2 == 0) {
    param_2 = 0;
  }
  else {
    lVar2 = FUN_004b90a0(param_1);
    if (lVar2 == 0) {
      param_2 = 0;
    }
    else {
      iVar5 = (int)param_2;
      *(int *)(iVar5 + 0x14) = (int)lVar2;
      piVar1 = *(int **)(iVar5 + 0x10);
      iVar4 = 0;
      piVar3 = piVar1;
      if (0 < *(int *)(iVar5 + 4)) {
        do {
          lVar2 = FUN_004c18b0(param_1,piVar3 + 1,0x1c);
          if (lVar2 == 0) {
            return 0;
          }
          lVar2 = FUN_004c1910(param_1,&iStack_8,4);
          if (lVar2 == 0) {
            return 0;
          }
          iVar4 = iVar4 + 1;
          *piVar3 = (int)(piVar1 + iStack_8 * 8);
          piVar3 = piVar3 + 8;
        } while (iVar4 < *(int *)(iVar5 + 4));
      }
    }
  }
  return param_2;
}
// FUN_004B7E10 NONMATCHING
u32 FUN_004b7e10(int param_1,u64 param_2)

{
  int *piVar1;
  u32 uVar2;
  long lVar3;
  int *piVar4;
  int iVar5;
  int aiStack_8 [2];
  
  aiStack_8[1] = 0;
  lVar3 = FUN_004c17f0(param_2,aiStack_8 + 1,4);
  if (lVar3 == 0) {
    uVar2 = 0;
  }
  else {
    lVar3 = FUN_004b9140(*(u32 *)(param_1 + 0x14),param_2);
    if (lVar3 == 0) {
      uVar2 = 0;
    }
    else {
      piVar1 = *(int **)(param_1 + 0x10);
      iVar5 = 0;
      piVar4 = piVar1;
      if (0 < *(int *)(param_1 + 4)) {
        do {
          lVar3 = FUN_004c1750(param_2,piVar4 + 1,0x1c);
          if (lVar3 == 0) {
            return 0;
          }
          aiStack_8[0] = *piVar4 - (int)piVar1;
          if (aiStack_8[0] < 0) {
            aiStack_8[0] = aiStack_8[0] + 0x1f;
          }
          aiStack_8[0] = aiStack_8[0] >> 5;
          lVar3 = FUN_004c17f0(param_2,aiStack_8,4);
          if (lVar3 == 0) {
            return 0;
          }
          iVar5 = iVar5 + 1;
          piVar4 = piVar4 + 8;
        } while (iVar5 < *(int *)(param_1 + 4));
      }
      uVar2 = 1;
    }
  }
  return uVar2;
}
// FUN_004B7F30 NONMATCHING
int FUN_004b7f30(int param_1)
{
  int iVar1;
  int iVar2;

  iVar1 = 4;
  iVar2 = FUN_004b91b0_arg(*(u32 *)(param_1 + 0x14));
  return iVar1 + iVar2 + (*(int *)(param_1 + 4) << 5);
}
#pragma optimization_level 3
// FUN_004B7F80
void FUN_004b7f80(RwMatrix *matrix, const f32 *src)
{
  matrix->right.x = src[2];
  matrix->right.y = src[3];
  matrix->right.z = 0.0f;
  matrix->up.x = src[4];
  matrix->up.y = src[5];
  matrix->up.z = 0.0f;
  matrix->at.x = 0.0f;
  matrix->at.y = 0.0f;
  matrix->at.z = 0.0f;
  matrix->pos.x = src[6];
  matrix->pos.y = src[7];
  matrix->pos.z = 0.0f;
  RwMatrixUpdate(matrix);
}
#pragma optimization_level 2
// FUN_004B7FD0 NONMATCHING
void FUN_004b7fd0(f32 t, f32 *out, const f32 *a, const f32 *b)
{
  f32 ratio;

  ratio = (t - a[1]) / (b[1] - a[1]);
  out[2] = a[2] + ratio * (b[2] - a[2]);
  out[3] = a[3] + ratio * (b[3] - a[3]);
  out[4] = a[4] + ratio * (b[4] - a[4]);
  out[5] = a[5] + ratio * (b[5] - a[5]);
  out[6] = a[6] + ratio * (b[6] - a[6]);
  out[7] = a[7] + ratio * (b[7] - a[7]);
}
// FUN_004B8080 NONMATCHING
void FUN_004b8080(f32 t, f32 *out, const f32 *a, const f32 *b)
{
  out[2] = a[2] + t * (b[2] - a[2]);
  out[3] = a[3] + t * (b[3] - a[3]);
  out[4] = a[4] + t * (b[4] - a[4]);
  out[5] = a[5] + t * (b[5] - a[5]);
  out[6] = a[6] + t * (b[6] - a[6]);
  out[7] = a[7] + t * (b[7] - a[7]);
}
// FUN_004B8120 NONMATCHING
void FUN_004b8120(f32 *out, const f32 *matrix)
{
  f32 a;
  f32 b;
  f32 c;
  f32 d;
  f32 det;
  f32 x0;
  f32 x1;
  f32 x2;
  f32 x3;

  a = matrix[2];
  b = matrix[3];
  c = matrix[4];
  d = matrix[5];
  det = a * d - b * c;
  if (det == 0.0f) {
    out[6] = out[6] - matrix[6];
    out[7] = out[7] - matrix[7];
  }
  else {
    x0 = out[0];
    x1 = out[1];
    x2 = out[2];
    x3 = out[3];
    out[0] = (d * x0 - c * x1) / det;
    out[1] = (d * x2 - c * x3) / det;
    out[2] = (-b * x0 + a * x1) / det;
    out[3] = (-b * x2 + a * x3) / det;
  }
}
// FUN_004B81F0
#pragma schedule on
void FUN_004b81f0(f32 *out, const f32 *a, const f32 *b)
{
  out[2] = a[2] * b[2] + a[3] * b[4];
  out[3] = a[2] * b[3] + a[3] * b[5];
  out[4] = a[4] * b[2] + a[5] * b[4];
  out[5] = a[4] * b[3] + a[5] * b[5];
  out[6] = a[6] + b[6];
  out[7] = a[7] + b[7];
}
#pragma schedule off
// FUN_004B8290 NONMATCHING
u32 FUN_004b8290(u32 param_1,u32 *param_2)
{
  f32 *puVar1;
  f32 *src;
  f32 fVar1;
  f32 fVar2;
  f32 fVar3;
  f32 fVar4;
  f32 fVar5;
  f32 fVar6;
  puVar1 = (f32 *)param_1;
  src = (f32 *)param_2;
  fVar4 = src[0];
  fVar3 = src[1];
  fVar2 = src[4];
  fVar1 = src[5];
  fVar6 = src[0xc];
  fVar5 = src[0xd];
  puVar1[0] = fVar4;
  puVar1[1] = fVar3;
  puVar1[2] = fVar2;
  puVar1[3] = fVar1;
  puVar1[4] = fVar6;
  puVar1[5] = fVar5;
  return param_1;
}
#pragma schedule on
// FUN_004B82D0 NONMATCHING
void FUN_004b82d0(RwMatrix *matrix, const f32 *src)
{
  RwV3d axis;

  axis.x = *(f32 *)DAT_0077e4c0_abs;
  axis.y = *(f32 *)DAT_0077e4c4_abs;
  axis.z = *(f32 *)DAT_0077e4c8_abs;
  matrix->right.x = src[3];
  matrix->right.y = src[5];
  matrix->right.z = 0.0f;
  matrix->up.x = 0.0f;
  matrix->up.y = src[4];
  matrix->up.z = 0.0f;
  matrix->at.x = 0.0f;
  matrix->at.y = 0.0f;
  matrix->at.z = 0.0f;
  matrix->pos.x = src[6];
  matrix->pos.y = src[7];
  matrix->pos.z = 0.0f;
  FUN_004c2f10((int)matrix);
  FUN_004c35d0((int)matrix,(int)DAT_007bcbc8_abs,2);
  FUN_004c31b0_typed(src[2] / 3.1415927f * 180.0f,(int)matrix,(int)&axis,2);
  FUN_004c35d0((int)matrix,(int)DAT_007bcbd8_abs,2);
}
#pragma schedule off
// FUN_004B83D0 NONMATCHING
void FUN_004b83d0(f32 t, f32 *out, const f32 *a, const f32 *b)
{
  f32 ratio;
  f32 delta;

  ratio = (t - a[1]) / (b[1] - a[1]);
  delta = b[2] - a[2];
  if (delta < -180.0f)
    delta += 360.0f;
  else if (delta > 180.0f)
    delta -= 360.0f;
  out[2] = a[2] + ratio * delta;
  delta = b[3] - a[3];
  out[3] = a[3] + ratio * delta;
  delta = b[4] - a[4];
  out[4] = a[4] + ratio * delta;
  delta = b[5] - a[5];
  out[5] = a[5] + ratio * delta;
  delta = b[6] - a[6];
  out[6] = a[6] + ratio * delta;
  delta = b[7] - a[7];
  out[7] = a[7] + ratio * delta;
}
// FUN_004B8500 NONMATCHING
void FUN_004b8500(f32 t, f32 *out, const f32 *a, const f32 *b)
{
  f32 delta;

  delta = b[2] - a[2];
  if (delta < -180.0f)
    delta += 360.0f;
  else if (delta > 180.0f)
    delta -= 360.0f;
  out[2] = a[2] + t * delta;
  out[3] = a[3] + t * (b[3] - a[3]);
  out[4] = a[4] + t * (b[4] - a[4]);
  out[5] = a[5] + t * (b[5] - a[5]);
  out[6] = a[6] + t * (b[6] - a[6]);
  out[7] = a[7] + t * (b[7] - a[7]);
}
// FUN_004B8610
void FUN_004b8610(void)
{
}
// FUN_004B8620
void FUN_004b8620(void)
{
}
// FUN_004B8630 NONMATCHING
u64 FUN_004b8630(u64 param_1,float *param_2)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float fStack_50;
  float fStack_4c;
  float fStack_40;
  float fStack_3c;
  float fStack_20;
  float fStack_1c;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  pfVar2 = &fStack_50;
  iVar1 = 8;
  do {
    iVar1 = iVar1 + -1;
    fVar3 = param_2[1];
    *pfVar2 = *param_2;
    pfVar2[1] = fVar3;
    param_2 = param_2 + 2;
    pfVar2 = pfVar2 + 2;
  } while (0 < iVar1);
  uStack_10 = DAT_0077e4d0;
  uStack_c = DAT_0077e4d4;
  uStack_8 = DAT_0077e4d8;
  fVar3 = (float)FUN_0052ea18(-fStack_40,fStack_50);
  pfVar2 = (float *)param_1;
  *pfVar2 = fVar3;
  FUN_004c35d0(&fStack_50,0x7bcbc8,2);
  FUN_004c31b0((-*pfVar2 / 3.1415927) * 180.0,&fStack_50,&uStack_10,2);
  FUN_004c35d0(&fStack_50,0x7bcbd8,2);
  pfVar2[1] = fStack_50;
  pfVar2[3] = fStack_4c;
  pfVar2[2] = fStack_3c;
  pfVar2[4] = fStack_20;
  pfVar2[5] = fStack_1c;
  return param_1;
}
// FUN_004B8740 NONMATCHING
u64 FUN_004b8740(u64 param_1)

{
  long lVar1;
  
  lVar1 = thunk_FUN_004c3970(0x44,DAT_007cdcfc,4,DAT_007cdd00,DAT_007ce8b0,0x40135);
  DAT_007ce8b0 = (u32)lVar1;
  if (lVar1 == 0) {
    param_1 = 0;
  }
  FUN_004b7630(0x77e4e0);
  FUN_004b6680((int *)0x77e520);
  FUN_004b6680((int *)0x77e550);
  DAT_007ce8ac = DAT_007ce8ac + 1;
  return param_1;
}
#pragma schedule on
// FUN_004B87D0 NONMATCHING
u64 FUN_004b87d0(u64 param_1)
{
  DAT_007ce8ac = DAT_007ce8ac + -1;
  FUN_004b7690((int)DAT_0077e4e0);
  if (DAT_007ce8b0 != 0) {
    FUN_004c3c30(DAT_007ce8b0);
    DAT_007ce8b0 = 0;
  }
  return param_1;
}
#pragma schedule off
// FUN_004B8830 NONMATCHING
bool FUN_004b8830(void)

{
  bool bVar1;
  long lVar2;
  
  lVar2 = FUN_004ca520(0,0x135,0x4b8740,0x4b87d0);
  if (lVar2 < 0) {
    bVar1 = false;
  }
  else {
    iGpffffbbc4 = (u8 *)(FUN_00494db0(0x30,0x135,0x4b88e0,0x4b8920,0x4b89d0));
    lVar2 = FUN_00494de0(0x135,0x4b8e70,0x4b8c30,0x4b9030);
    bVar1 = false;
    if (-1 < lVar2) {
      bVar1 = -1 < (int)iGpffffbbc4;
    }
  }
  return bVar1;
}
// FUN_004B88E0 NONMATCHING
u64 FUN_004b88e0(u64 param_1)

{
  FUN_00521408((int)param_1 + iGpffffbbc4,0,0x30);
  return param_1;
}
// FUN_004B8920 NONMATCHING
u64 FUN_004b8920(u64 param_1)

{
  u32 *puVar1;
  int *piVar2;
  int *piVar3;
  u32 uVar4;
  
  uVar4 = 0;
  piVar2 = (int *)((int)param_1 + iGpffffbbc4);
  piVar3 = piVar2;
  do {
    if (*piVar3 != 0) {
      FUN_004c3880();
    }
    uVar4 = uVar4 + 1;
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  } while (uVar4 < 2);
  uVar4 = 0;
  do {
    puVar1 = (u32 *)piVar2[2];
    if (puVar1 != (u32 *)0x0) {
      FUN_004b6eb0();
    }
    uVar4 = uVar4 + 1;
    piVar2 = piVar2 + 1;
  } while (uVar4 < 8);
  return param_1;
}
// FUN_004B89D0 NONMATCHING
u64 FUN_004b89d0(u64 param_1,int param_2)

{
  u32 *puVar1;
  int *piVar2;
  bool bVar3;
  int iVar4;
  u64 uVar5;
  int *piVar6;
  u32 uVar7;
  u32 uVar8;
  int iVar9;
  int iVar10;
  
  bVar3 = true;
  uVar8 = 0;
  iVar9 = (int)param_1 + (int)iGpffffbbc4;
  param_2 = (int)(param_2 + iGpffffbbc4);
  iVar10 = iVar9;
  do {
    puVar1 = *(u32 **)(param_2 + 8);
    piVar6 = (int *)(iVar10 + 8);
    if (puVar1 == (u32 *)0x0) {
      *piVar6 = 0;
    }
    else {
      piVar2 = (int *)*puVar1;
      uVar5 = FUN_004b6dd0(piVar2);
      FUN_004b6e10(uVar5,*(u32 *)(*piVar2 + 4));
      *piVar6 = iVar4;
      if (*piVar6 == 0) {
        bVar3 = false;
        break;
      }
      FUN_004b7020(*piVar6,(int)(int)puVar1);
    }
    uVar8 = uVar8 + 1;
    param_2 = param_2 + 4;
    iVar10 = iVar10 + 4;
  } while (uVar8 < 8);
  if (!bVar3) {
    uVar7 = 0;
    if (uVar8 != 0) {
      do {
        if (*(u32 **)(iVar9 + 8) != (u32 *)0x0) {
          FUN_004b92d0(**(u32 **)(iVar9 + 8));
          FUN_004b6eb0();
        }
        uVar7 = uVar7 + 1;
        iVar9 = iVar9 + 4;
      } while (uVar7 < uVar8);
    }
    param_1 = 0;
  }
  return param_1;
}
// FUN_004B8B10 NONMATCHING
int * FUN_004b8b10(int *param_1)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  u32 uVar4;
  u32 uVar5;
  int *piVar6;
  u32 uVar7;
  
  uVar7 = 0;
  piVar6 = param_1;
  do {
    uVar5 = 0;
    uVar4 = 0;
    bVar3 = false;
    do {
      piVar1 = (int *)param_1[uVar5 + 2];
      if (piVar1 == (int *)0x0) {
        uVar5 = uVar5 + 1;
      }
      else {
        if (uVar7 == *(u32 *)(*(int *)(*piVar1 + 0x14) + uVar4 * 4 + 0x20)) {
          bVar3 = true;
          break;
        }
        uVar4 = uVar4 + 1;
        if ((u32)piVar1[0xb] <= uVar4) {
          uVar4 = 0;
          uVar5 = uVar5 + 1;
        }
      }
    } while (uVar5 < 8);
    if ((bVar3) && (*piVar6 == 0)) {
      iVar2 = FUN_004c38c0();
      *piVar6 = iVar2;
      if (*piVar6 == 0) {
        return (int *)0x0;
      }
    }
    else if ((!bVar3) && (*piVar6 != 0)) {
      FUN_004c3880();
      *piVar6 = 0;
    }
    uVar7 = uVar7 + 1;
    piVar6 = piVar6 + 1;
    if (1 < uVar7) {
      return param_1;
    }
  } while( true );
}
// FUN_004B8C30 NONMATCHING
u64 FUN_004b8c30(u64 param_1,u64 param_2,int param_3)

{
  u32 uVar1;
  long lVar2;
  u64 uVar3;
  int iVar4;
  int iVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uStack_4;
  
  uVar6 = 0;
  uStack_4 = 0;
  param_3 = (int)(param_3 + iGpffffbbc4);
  iVar5 = 4;
  iVar4 = param_3;
  uVar7 = 0;
  do {
    uVar1 = uVar7;
    if (*(int *)(iVar4 + 8) != 0) {
      uStack_4 = 1 << (uVar6 & 0x1f);
      iVar5 = iVar5 + 0x20;
      uVar1 = uVar7 | uStack_4;
      uStack_4 = uVar7 | uStack_4;
    }
    uVar6 = uVar6 + 1;
    iVar4 = iVar4 + 4;
    uVar7 = uVar1;
  } while (uVar6 < 8);
  lVar2 = FUN_004c15a0(param_1,1,iVar5,0x37002,0x37);
  if (lVar2 == 0) {
    param_1 = 0;
  }
  else {
    lVar2 = FUN_004c17f0(param_1,&uStack_4,4);
    if (lVar2 == 0) {
      param_1 = 0;
    }
    else {
      uVar7 = 0;
      do {
        if (*(u32 **)(param_3 + 8) != (u32 *)0x0) {
          uVar3 = FUN_004b96e0(**(u32 **)(param_3 + 8));
          FUN_004c53f0(param_1,uVar3,0x20);
        }
        uVar7 = uVar7 + 1;
        param_3 = param_3 + 4;
      } while (uVar7 < 8);
    }
  }
  return param_1;
}
// FUN_004B8D50 NONMATCHING
long FUN_004b8d50(u64 param_1)

{
  int iVar1;
  int iVar2;
  u8 *puVar3;
  u8 *puVar4;
  long lVar5;
  u8 *puVar6;
  u32 uStack_50;
  u32 uStack_4c;
  u32 uStack_48;
  u32 uStack_44;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u8 auStack_4 [4];
  
  puVar4 = (u8 *)0x4;
  puVar6 = auStack_4;
  puVar3 = puVar6;
  while (puVar3 != (u8 *)0x0) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
    puVar4 = puVar4 + -1;
    puVar3 = puVar4;
  }
  lVar5 = (long)(((code)FUN_004b91c0)(0x3f800000,param_1,1,2,auStack_4,0));
  if (lVar5 == 0) {
    lVar5 = 0;
  }
  else {
    iVar1 = ((int *)lVar5)[4];
    iVar2 = *(int *)(*(int *)lVar5 + 8);
    uStack_44 = uStack_44 | 0x20003;
    uStack_28 = 0x3f800000;
    uStack_3c = 0x3f800000;
    uStack_50 = 0x3f800000;
    uStack_40 = 0;
    uStack_48 = 0;
    uStack_4c = 0;
    uStack_2c = 0;
    uStack_30 = 0;
    uStack_38 = 0;
    uStack_18 = 0;
    uStack_1c = 0;
    uStack_20 = 0;
    FUN_004b7c60((u32)0,(u32 *)lVar5,(u32 *)iVar1,0,(u64)(int)&uStack_50);
    FUN_004b7c60((u32)0x3f800000,(u32 *)lVar5,(u32 *)(iVar1 + iVar2),iVar1,(u64)(int)&uStack_50);
  }
  return lVar5;
}
// FUN_004B8E70 NONMATCHING
long FUN_004b8e70(long param_1,u64 param_2,int param_3)

{
  long lVar1;
  u64 uVar2;
  int iVar3;
  long unaff_s3;
  u32 uVar4;
  u8 auStack_30 [44];
  u32 uStack_4;
  
  param_3 = (int)(param_3 + iGpffffbbc4);
  lVar1 = FUN_004c1600(param_1,1,0,0);
  if ((lVar1 == 0) || (lVar1 = FUN_004c1910(param_1,&uStack_4,4), lVar1 == 0)) {
    param_1 = 0;
  }
  else {
    uVar4 = 0;
    iVar3 = param_3;
    do {
      if ((uStack_4 & 1 << (uVar4 & 0x1f)) != 0) {
        lVar1 = FUN_004c5250(param_1,auStack_30,0x20);
        if (lVar1 == 0) {
          lVar1 = 0;
        }
        else {
          lVar1 = FUN_004b7750(0x77e4e0);
          if (lVar1 == 0) {
            unaff_s3 = (u64)(FUN_004b8d50((u64)(int)(u8 *)auStack_30));
          }
          else {
            unaff_s3 = (long)FUN_004b77f0((int *)(int)lVar1,(u64)(int)(u8 *)auStack_30);
            if (unaff_s3 == 0) {
              unaff_s3 = (u64)(FUN_004b8d50((u64)(int)(u8 *)auStack_30));
            }
            else {
              FUN_004b9350_wide(unaff_s3);
            }
          }
          lVar1 = param_1;
          if (unaff_s3 == 0) {
            lVar1 = 0;
          }
        }
        if (lVar1 == 0) {
          return 0;
        }
        if (unaff_s3 != 0) {
          uVar2 = (u64)(int)FUN_004b6dd0((int *)(int)unaff_s3);
          FUN_004b6e10(uVar2,*(u32 *)(*(int *)unaff_s3 + 4));
          *(u32 *)(iVar3 + 8) = (int)lVar1;
          if ((lVar1 == 0) ||
             (lVar1 = FUN_004b6ec0((u32 *)(int)*(u32 *)(iVar3 + 8),(int *)(int)unaff_s3), lVar1 == 0)) {
            FUN_004b92d0(unaff_s3);
            return 0;
          }
        }
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 4;
    } while (uVar4 < 8);
    lVar1 = (long)FUN_004b8b10((int *)(int)param_3);
    if (lVar1 == 0) {
      param_1 = 0;
    }
  }
  return param_1;
}
// FUN_004B9030 NONMATCHING
int FUN_004b9030(int param_1)

{
  int iVar1;
  long lVar2;
  u32 uVar3;
  
  lVar2 = FUN_004b97f0(0);
  if (lVar2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = 0x10;
    uVar3 = 0;
    param_1 = (int)(param_1 + iGpffffbbc4);
    do {
      if (*(int *)(param_1 + 8) != 0) {
        iVar1 = iVar1 + 0x20;
      }
      uVar3 = uVar3 + 1;
      param_1 = param_1 + 4;
    } while (uVar3 < 8);
  }
  return iVar1;
}
// FUN_004B90A0 NONMATCHING
long FUN_004b90a0(u64 param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = (*DAT_00960188)(uGpffffbbc0,0x30135);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else {
    lVar2 = FUN_004c5250(param_1,lVar1,0x20);
    if (lVar2 == 0) {
      lVar1 = 0;
    }
    else {
      lVar2 = FUN_004c1910(param_1,(int)lVar1 + 0x20,0x20);
      if (lVar2 == 0) {
        lVar1 = 0;
      }
      else {
        *(u32 *)((int)lVar1 + 0x40) = 1;
      }
    }
  }
  return lVar1;
}
// FUN_004B9140 NONMATCHING
u64 FUN_004b9140(u64 param_1,u64 param_2)

{
  long lVar1;
  
  lVar1 = FUN_004c53f0(param_2,param_1,0x20);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  else {
    lVar1 = FUN_004c17f0(param_2,(int)param_1 + 0x20,0x20);
    if (lVar1 == 0) {
      param_1 = 0;
    }
  }
  return param_1;
}
#pragma optimization_level 3
// FUN_004B91B0
u32 FUN_004b91b0(void)

{
  return 0x40;
}
#pragma optimization_level 2
// FUN_004B91C0 NONMATCHING
long FUN_004b91c0(u64 param_1,int param_2,u64 param_3,u64 param_4,long param_5)

{
  long lVar1;
  long lVar2;
  int iVar3;
  
  lVar2 = 0;
  if (param_5 == 1) {
    lVar2 = ((code)FUN_004b6840)(DAT_0077e550,param_3,0);
  }
  else if (param_5 == 0) {
    lVar2 = ((code)FUN_004b6840)(DAT_0077e520,param_3,0);
  }
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  else {
    lVar1 = (*DAT_00960188)(uGpffffbbc0,0x30135);
    if (lVar1 == 0) {
      lVar2 = 0;
    }
    else {
      FUN_00524828(lVar1,param_1,0x20);
      iVar3 = (int)lVar1;
      *(u8 *)(iVar3 + 0x1f) = 0;
      FUN_00521250(iVar3 + 0x20,param_4,param_2 << 2);
      *(u32 *)(iVar3 + 0x40) = 1;
      *(int *)((int)lVar2 + 0x14) = iVar3;
    }
  }
  return lVar2;
}
// FUN_004B92D0 NONMATCHING
u32 FUN_004b92d0(u64 param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0x14);
  *(int *)(iVar1 + 0x40) = *(int *)(iVar1 + 0x40) + -1;
  if (*(int *)(iVar1 + 0x40) == 0) {
    (*DAT_0096018c)(uGpffffbbc0,*(u32 *)((int)param_1 + 0x14));
    FUN_004b6980();
  }
  return 1;
}
#pragma schedule on
// FUN_004B9350
u32 FUN_004b9350(u32 param_1)

{
  u32 *puVar1;
  
  puVar1 = *(u32 **)(param_1 + 0x14);
  puVar1[0x10] = puVar1[0x10] + 1;
  return param_1;
}
#pragma schedule off
// FUN_004B9370 NONMATCHING
int FUN_004b9370(int param_1)

{
  u32 *puVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  u32 *puVar6;
  u32 *puVar7;
  u32 uVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  u32 *puVar12;
  int iStack_50;
  int iStack_4c;
  u32 uStack_48;
  int iStack_40;
  int iStack_3c;
  u32 uStack_38;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  int iStack_20;
  int iStack_1c;
  u32 uStack_18;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  uVar8 = 0;
  puVar6 = (u32 *)(param_1 + iGpffffbbc4);
  puVar7 = puVar6;
  do {
    puVar1 = (u32 *)*puVar7;
    if (puVar1 != (u32 *)0x0) {
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
    uVar8 = uVar8 + 1;
    puVar7 = puVar7 + 1;
  } while (uVar8 < 2);
  iVar11 = 0;
  puVar7 = puVar6;
  do {
    piVar2 = (int *)puVar7[2];
    if (piVar2 != (int *)0x0) {
      iVar3 = piVar2[9];
      piVar9 = piVar2 + 0x13;
      iVar10 = 0;
      pcVar4 = (code *)piVar2[0xf];
      puVar12 = (u32 *)(*(int *)(*piVar2 + 0x14) + 0x20);
      if (0 < piVar2[0xb]) {
        do {
          if ((*puVar12 < 2) && (iVar5 = puVar6[*puVar12], iVar5 != 0)) {
            if (pcVar4 == (code *)&LAB_004b7f80) {
              iStack_50 = piVar9[2];
              iStack_4c = piVar9[3];
              uStack_48 = 0;
              iStack_40 = piVar9[4];
              iStack_3c = piVar9[5];
              uStack_38 = 0;
              uStack_30 = 0;
              uStack_2c = 0;
              uStack_28 = 0;
              iStack_20 = piVar9[6];
              iStack_1c = piVar9[7];
              uStack_18 = 0;
              FUN_004c2f10(&iStack_50);
            }
            else if (pcVar4 == (int (**)(...))FUN_004b82d0) {
              uStack_10 = DAT_0077e580;
              uStack_c = DAT_0077e584;
              uStack_8 = DAT_0077e588;
              iStack_50 = piVar9[3];
              iStack_4c = piVar9[5];
              uStack_48 = 0;
              iStack_40 = 0;
              iStack_3c = piVar9[4];
              uStack_38 = 0;
              uStack_30 = 0;
              uStack_2c = 0;
              uStack_28 = 0;
              iStack_20 = piVar9[6];
              iStack_1c = piVar9[7];
              uStack_18 = 0;
              FUN_004c2f10(&iStack_50);
              FUN_004c35d0(&iStack_50,0x7bcbc8,2);
              FUN_004c31b0(((float)piVar9[2] / 3.1415927) * 180.0,&iStack_50,&uStack_10,2);
              FUN_004c35d0(&iStack_50,0x7bcbd8,2);
            }
            else {
              (*pcVar4)(&iStack_50,piVar9);
            }
            FUN_004c3760(iVar5,&iStack_50,1);
            piVar9 = (int *)((int)piVar9 + iVar3);
          }
          iVar10 = iVar10 + 1;
          puVar12 = puVar12 + 1;
        } while (iVar10 < piVar2[0xb]);
      }
    }
    iVar11 = iVar11 + 1;
    puVar7 = puVar7 + 1;
  } while (iVar11 < 8);
  FUN_004699b0(param_1,*puVar6,puVar6[1]);
  return param_1;
}
#pragma optimization_level 3
// FUN_004B96E0
u32 FUN_004b96e0(int param_1)

{
  return *(u32 *)(param_1 + 0x14);
}
#pragma optimization_level 2
// FUN_004B96F0 NONMATCHING
u64 FUN_004b96f0(u64 param_1,u64 param_2,int param_3)

{
  int iVar1;
  u64 uVar2;
  long lVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = (int)param_1 + (int)iGpffffbbc4;
  piVar5 = (int *)(iVar4 + param_3 * 4 + 8);
  uVar2 = (u64)(int)FUN_004b6dd0((int *)(int)param_2);
  FUN_004b6e10(uVar2,*(u32 *)(*(int *)param_2 + 4));
  *piVar5 = iVar1;
  if (*piVar5 == 0) {
    param_1 = 0;
  }
  else {
    FUN_004b6ec0((u32 *)*piVar5,(int *)(int)param_2);
    lVar3 = (long)FUN_004b8b10((int *)(int)iVar4);
    if (lVar3 == 0) {
      FUN_004b6eb0();
      param_1 = 0;
    }
    else {
      iVar1 = ((int *)param_2)[5];
      *(int *)(iVar1 + 0x40) = *(int *)(iVar1 + 0x40) + 1;
    }
  }
  return param_1;
}
#pragma schedule on
// FUN_004B97B0
u32 FUN_004b97b0(int param_1,int param_2)
{
  u32 *ptr;
  
  ptr = (u32 *)(param_1 + (int)iGpffffbbc4);
  return ptr[param_2 + 2];
}
#pragma schedule on
// FUN_004B97D0
u32 FUN_004b97d0(int param_1,u32 param_2,int param_3)
{
  u32 *ptr;

  ptr = (u32 *)(param_1 + (int)iGpffffbbc4);
  ptr[param_3 + 2] = param_2;
  return param_1;
}
#pragma schedule off
// FUN_004B97F0 NONMATCHING
u32 FUN_004b97f0(int param_1)
{
  u32 count;
  u32 *ptr;

  ptr = (u32 *)(param_1 + (int)iGpffffbbc4);
  count = 0;
  do {
    if (ptr[2] != 0) {
      return 1;
    }
    count = count + 1;
    ptr = ptr + 1;
  } while (count < 8);
  return 0;
}
// FUN_004B9840 NONMATCHING
int FUN_004b9840(u32 param_1)
{
  if (param_1 < 9) {
    return (1 << param_1) << 2;
  }
  return 0;
}
// FUN_004B9870 NONMATCHING
u32 FUN_004b9870(u64 param_1,u32 param_2,int param_3)

{
  int iVar1;
  u32 uVar2;
  int iStack_10;
  int iStack_c;
  u16 uStack_6;
  u16 uStack_4;
  u8 uStack_2;
  u8 uStack_1;
  
  uStack_1 = 0x42;
  FUN_004c53f0(param_1,&uStack_1,1);
  uStack_2 = 0x4d;
  FUN_004c53f0(param_1,&uStack_2,1);
  uVar2 = (u32)param_2;
  if (param_2 < 9) {
    iVar1 = (1 << (uVar2 & 0x1f)) << 2;
  }
  else {
    iVar1 = 0;
  }
  iStack_c = iVar1 + 0x36 +
             *(int *)(param_3 + 8) * ((*(int *)(param_3 + 4) * uVar2 + 0x1f & 0xffffffe0) >> 3);
  FUN_004c17f0(param_1,&iStack_c,4);
  uStack_4 = 0;
  FUN_004c1820(param_1,&uStack_4,2);
  uStack_6 = 0;
  FUN_004c1820(param_1,&uStack_6,2);
  if (param_2 < 9) {
    iStack_10 = (1 << (uVar2 & 0x1f)) << 2;
  }
  else {
    iStack_10 = 0;
  }
  iStack_10 = iStack_10 + 0x36;
  FUN_004c17f0(param_1,&iStack_10,4);
  return 0xe;
}
// FUN_004B99A0 NONMATCHING
int FUN_004b99a0(u64 param_1,u32 param_2,int param_3)

{
  int iVar1;
  u8 *puVar2;
  int iVar3;
  int iVar4;
  u32 uStack_34;
  u32 uStack_30;
  int iStack_2c;
  int iStack_28;
  u8 uStack_24;
  u8 uStack_23;
  u8 uStack_22;
  u8 uStack_21;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u16 uStack_4;
  u16 uStack_2;
  
  iVar4 = 0x28;
  uStack_8 = 0x28;
  FUN_004c17f0(param_1,&uStack_8,4);
  uStack_c = *(u32 *)(param_3 + 4);
  FUN_004c17f0(param_1,&uStack_c,4);
  uStack_10 = *(u32 *)(param_3 + 8);
  FUN_004c17f0(param_1,&uStack_10,4);
  uStack_2 = 1;
  FUN_004c1820(param_1,&uStack_2,2);
  uStack_4 = (u16)param_2;
  FUN_004c1820(param_1,&uStack_4,2);
  uStack_14 = 0;
  FUN_004c17f0(param_1,&uStack_14,4);
  uStack_18 = 0;
  FUN_004c17f0(param_1,&uStack_18,4);
  uStack_1c = 0;
  FUN_004c17f0(param_1,&uStack_1c,4);
  uStack_20 = 0;
  FUN_004c17f0(param_1,&uStack_20,4);
  if (param_2 < 9) {
    puVar2 = *(u8 **)(param_3 + 0x18);
    iVar1 = 1 << ((u32)param_2 & 0x1f);
    iStack_28 = iVar1;
    FUN_004c17f0(param_1,&iStack_28,4);
    iStack_2c = iVar1;
    FUN_004c17f0(param_1,&iStack_2c,4);
    iVar3 = 0;
    if (0 < iVar1) {
      do {
        uStack_24 = puVar2[2];
        uStack_23 = puVar2[1];
        uStack_22 = *puVar2;
        uStack_21 = 0xff;
        FUN_004c53f0(param_1,&uStack_24,4);
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 4;
        puVar2 = puVar2 + 4;
      } while (iVar3 < iVar1);
    }
  }
  else {
    uStack_30 = 0;
    FUN_004c17f0(param_1,&uStack_30,4);
    uStack_34 = 0;
    FUN_004c17f0(param_1,&uStack_34,4);
  }
  return iVar4;
}
// FUN_004B9BA0 NONMATCHING
u32 FUN_004b9ba0(u64 param_1,int param_2,int param_3,long param_4,u8 *param_5)

{
  int iVar1;
  u8 *puVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  u8 *puVar6;
  int iVar7;
  int iVar8;
  u32 uVar9;
  u8 uStack_1;
  
  if (param_4 == 4) {
    iVar5 = *(int *)(param_2 + 0x10);
    iVar4 = *(int *)(param_2 + 4);
    iVar8 = 0;
    iVar1 = *(int *)(param_2 + 0x14);
    if (0 < iVar4) {
      iVar7 = 0;
      do {
        pcVar3 = (char *)(iVar1 + param_3 * iVar5 + iVar8);
        iVar8 = iVar8 + 2;
        param_5[iVar7] = *pcVar3 << 4 | pcVar3[1];
        iVar4 = *(int *)(param_2 + 4);
        iVar7 = iVar7 + 1;
      } while (iVar8 < iVar4);
    }
    uVar9 = iVar4 >> 1;
  }
  else if (param_4 == 8) {
    FUN_00521250(param_5,*(int *)(param_2 + 0x14) + param_3 * *(int *)(param_2 + 0x10),
                 *(u32 *)(param_2 + 4));
    uVar9 = *(u32 *)(param_2 + 4);
  }
  else {
    iVar5 = *(int *)(param_2 + 4);
    iVar4 = 0;
    puVar6 = (u8 *)(*(int *)(param_2 + 0x14) + param_3 * *(int *)(param_2 + 0x10));
    puVar2 = param_5;
    if (0 < iVar5) {
      do {
        iVar4 = iVar4 + 1;
        puVar2[2] = *puVar6;
        puVar2[1] = puVar6[1];
        *puVar2 = puVar6[2];
        puVar6 = puVar6 + 4;
        iVar5 = *(int *)(param_2 + 4);
        puVar2 = puVar2 + 3;
      } while (iVar4 < iVar5);
    }
    uVar9 = iVar5 * 3;
  }
  FUN_004c53f0(param_1,param_5,uVar9);
  for (; (uVar9 & 3) != 0; uVar9 = uVar9 + 1) {
    uStack_1 = 0;
    FUN_004c53f0(param_1,&uStack_1,1);
  }
  return uVar9;
}
// FUN_004B9D40 NONMATCHING
int FUN_004b9d40(u64 param_1,u64 param_2,u64 param_3)

{
  int iVar1;
  int iVar2;
  u64 uVar3;
  int iVar4;
  
  iVar4 = 0;
  uVar3 = (*DAT_00960178)(*(int *)((int)param_3 + 4) * 3,0x10000);
  iVar1 = *(int *)((int)param_3 + 8);
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    iVar2 = (int)FUN_004b9ba0(param_1,param_3,iVar1,param_2,(u8 *)(int)uVar3);
    iVar4 = iVar4 + iVar2;
  }
  (*DAT_0096017c)(uVar3);
  return iVar4;
}
// FUN_004B9E00 NONMATCHING
u32 FUN_004b9e00(int param_1,int param_2,u16 *param_3,int param_4,long param_5)

{
  u8 bVar1;
  u8 bVar2;
  u8 bVar3;
  int iVar4;
  u32 uVar5;
  u16 uVar6;
  int iVar7;
  u8 *pbVar8;
  u8 *pbVar9;
  u32 uVar10;
  u8 *pbVar11;
  u32 uVar12;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar7 = *(int *)(param_1 + 4);
  iVar4 = *(int *)(param_1 + 0x18);
  uVar10 = param_4 << 8 | *(u32 *)(param_1 + 0xc);
  pbVar8 = (u8 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x10) * param_2);
  if (uVar10 == 0x2020) {
    for (; iVar7 != 0; iVar7 = iVar7 + -1) {
      *pbVar8 = (u8)*param_3;
      pbVar8[1] = *(u8 *)((int)param_3 + 1);
      pbVar8[2] = (u8)param_3[1];
      param_3 = param_3 + 2;
      pbVar8[3] = 0xff;
      pbVar8 = pbVar8 + 4;
    }
  }
  else if (uVar10 == 0x1820) {
    if (param_5 == 0) {
      for (; iVar7 != 0; iVar7 = iVar7 + -1) {
        pbVar8[2] = (u8)*param_3;
        pbVar8[1] = *(u8 *)((int)param_3 + 1);
        *pbVar8 = (u8)param_3[1];
        param_3 = (u16 *)((int)param_3 + 3);
        pbVar8[3] = 0xff;
        pbVar8 = pbVar8 + 4;
      }
    }
    else {
      for (; iVar7 != 0; iVar7 = iVar7 + -1) {
        *pbVar8 = (u8)*param_3;
        pbVar8[1] = *(u8 *)((int)param_3 + 1);
        pbVar8[2] = (u8)param_3[1];
        param_3 = (u16 *)((int)param_3 + 3);
        pbVar8[3] = 0xff;
        pbVar8 = pbVar8 + 4;
      }
    }
  }
  else if (uVar10 == 0x1020) {
    for (; iVar7 != 0; iVar7 = iVar7 + -1) {
      uVar6 = *param_3;
      param_3 = param_3 + 1;
      *pbVar8 = (u8)(uVar6 >> 8) & 0xf8;
      pbVar8[1] = (u8)((int)(u32)uVar6 >> 3) & 0xfc;
      pbVar8[2] = (char)uVar6 << 3;
      pbVar8[3] = 0xff;
      pbVar8 = pbVar8 + 4;
    }
  }
  else if (uVar10 == 0xf20) {
    for (; iVar7 != 0; iVar7 = iVar7 + -1) {
      uVar6 = *param_3;
      param_3 = param_3 + 1;
      *pbVar8 = (u8)((int)(u32)uVar6 >> 7) & 0xf8;
      pbVar8[1] = (u8)((int)(u32)uVar6 >> 2) & 0xf8;
      pbVar8[2] = (char)uVar6 << 3;
      pbVar8[3] = 0xff;
      pbVar8 = pbVar8 + 4;
    }
  }
  else if (uVar10 == 0x820) {
    for (; iVar7 != 0; iVar7 = iVar7 + -1) {
      uVar6 = *param_3;
      param_3 = (u16 *)((int)param_3 + 1);
      pbVar9 = (u8 *)(iVar4 + (u32)(u8)uVar6 * 4);
      bVar1 = pbVar9[1];
      bVar2 = pbVar9[2];
      bVar3 = pbVar9[3];
      *pbVar8 = *pbVar9;
      pbVar8[1] = bVar1;
      pbVar8[2] = bVar2;
      pbVar8[3] = bVar3;
      pbVar8 = pbVar8 + 4;
    }
  }
  else if (uVar10 == 0x420) {
    uVar12 = (u32)(u8)*param_3;
    uVar10 = 4;
    pbVar9 = (u8 *)((int)param_3 + 1);
    while (iVar7 != 0) {
      iVar7 = iVar7 + -1;
      uVar5 = uVar10 & 0x1f;
      uVar10 = uVar10 - 4;
      pbVar11 = (u8 *)(iVar4 + ((int)uVar12 >> uVar5 & 0xfU) * 4);
      bVar1 = pbVar11[1];
      bVar2 = pbVar11[2];
      bVar3 = pbVar11[3];
      *pbVar8 = *pbVar11;
      pbVar8[1] = bVar1;
      pbVar8[2] = bVar2;
      pbVar8[3] = bVar3;
      pbVar8 = pbVar8 + 4;
      if ((int)uVar10 < 0) {
        uVar12 = (u32)*pbVar9;
        uVar10 = 4;
        pbVar9 = pbVar9 + 1;
      }
    }
  }
  else if (uVar10 == 0x120) {
    uVar12 = (u32)(u8)*param_3;
    uVar10 = 7;
    pbVar9 = (u8 *)((int)param_3 + 1);
    while (iVar7 != 0) {
      iVar7 = iVar7 + -1;
      uVar5 = uVar10 & 0x1f;
      uVar10 = uVar10 - 1;
      pbVar11 = (u8 *)(iVar4 + ((int)uVar12 >> uVar5 & 1U) * 4);
      bVar1 = pbVar11[1];
      bVar2 = pbVar11[2];
      bVar3 = pbVar11[3];
      *pbVar8 = *pbVar11;
      pbVar8[1] = bVar1;
      pbVar8[2] = bVar2;
      pbVar8[3] = bVar3;
      pbVar8 = pbVar8 + 4;
      if ((int)uVar10 < 0) {
        uVar12 = (u32)*pbVar9;
        uVar10 = 7;
        pbVar9 = pbVar9 + 1;
      }
    }
  }
  else if (uVar10 == 0x808) {
    FUN_00521250(pbVar8,param_3,iVar7);
  }
  else if ((uVar10 == 0x408) || (uVar10 == 0x404)) {
    uVar12 = (u32)(u8)*param_3;
    uVar10 = 4;
    pbVar9 = (u8 *)((int)param_3 + 1);
    while (iVar7 != 0) {
      iVar7 = iVar7 + -1;
      uVar5 = uVar10 & 0x1f;
      uVar10 = uVar10 - 4;
      *pbVar8 = (u8)((int)uVar12 >> uVar5) & 0xf;
      pbVar8 = pbVar8 + 1;
      if ((int)uVar10 < 0) {
        uVar12 = (u32)*pbVar9;
        uVar10 = 4;
        pbVar9 = pbVar9 + 1;
      }
    }
  }
  else {
    if ((uVar10 != 0x108) && (uVar10 != 0x104)) {
      uStack_8 = 0x19d;
      uStack_4 = FUN_004c1d10(0xffffffff80000008);
      FUN_004c1c50(&uStack_8);
      return 0;
    }
    uVar12 = (u32)(u8)*param_3;
    uVar10 = 7;
    pbVar9 = (u8 *)((int)param_3 + 1);
    while (iVar7 != 0) {
      iVar7 = iVar7 + -1;
      uVar5 = uVar10 & 0x1f;
      uVar10 = uVar10 - 1;
      *pbVar8 = (u8)((int)uVar12 >> uVar5) & 1;
      pbVar8 = pbVar8 + 1;
      if ((int)uVar10 < 0) {
        uVar12 = (u32)*pbVar9;
        uVar10 = 7;
        pbVar9 = pbVar9 + 1;
      }
    }
  }
  return 1;
}
// FUN_004BA2A0 NONMATCHING
long FUN_004ba2a0(u64 param_1)

{
  u32 uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  u32 uVar5;
  long lVar6;
  long lVar7;
  long lVar8;
  long lVar9;
  u32 uVar10;
  int iVar11;
  u8 *puVar12;
  u32 *puVar13;
  u8 *puVar14;
  u64 uVar15;
  u32 uVar16;
  int iVar17;
  long lVar18;
  long lVar19;
  int iStack_460;
  short sStack_450;
  int iStack_440;
  u32 uStack_430;
  u32 uStack_42c;
  u32 uStack_428;
  u32 uStack_424;
  u8 auStack_420 [12];
  u32 uStack_414;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u8 bStack_8;
  u8 bStack_7;
  short asStack_4 [2];
  
  lVar6 = FUN_004c58a0(2,1,param_1);
  if (lVar6 == 0) {
    lVar7 = 0;
  }
  else {
    lVar7 = FUN_004c5250(lVar6,asStack_4,4);
    if (lVar7 == 4) {
      if (asStack_4[0] == 0x4d42) {
        lVar7 = FUN_004c5250(lVar6,(int)&uStack_430 + 2,0xe);
        iVar4 = uStack_424;
        iVar11 = uStack_428;
        if (lVar7 == 0xe) {
          iVar17 = uStack_424 + -4;
          iVar3 = FUN_004c5250(lVar6,&uStack_430,iVar17);
          if (iVar17 == iVar3) {
            iVar3 = iVar4 + 0xe;
            if (iVar4 == 0xc) {
              uStack_414 = 0;
              lVar18 = (long)(*(u16*)((u8*)&uStack_430 + 2));
              iStack_440 = 0;
              iStack_460 = (int)(short)uStack_430;
              sStack_450 = (*(u16*)((u8*)&uStack_42c + 2));
            }
            else {
              iStack_440 = uStack_424;
              iStack_460 = uStack_430;
              sStack_450 = (*(u16*)((u8*)&uStack_428 + 2));
              lVar18 = (long)uStack_42c;
              if (uStack_424 == 2) {
                uStack_10 = 0x19d;
                uStack_c = FUN_004c1d10(0xffffffff80000009);
                FUN_004c1c50(&uStack_10);
                FUN_004c5780(lVar6,0);
                return 0;
              }
            }
            if ((uStack_414 < 1) ||
               (iVar17 = uStack_414, 1 << ((int)sStack_450 & 0x1fU) < uStack_414)) {
              iVar17 = 1 << ((int)sStack_450 & 0x1fU);
            }
            if ((((sStack_450 == 0x20) || (sStack_450 == 0x18)) || (sStack_450 == 0x10)) ||
               (sStack_450 == 0xf)) {
              uVar15 = 0x20;
            }
            else {
              uVar15 = 8;
              if (sStack_450 != 8) {
                if ((sStack_450 == 4) || (sStack_450 == 1)) {
                  uVar15 = 4;
                }
                else {
                  uVar15 = 0x20;
                }
              }
            }
            lVar7 = FUN_004cbe00(iStack_460,lVar18,uVar15);
            if (lVar7 == 0) {
              FUN_004c5780(lVar6,0);
              lVar7 = 0;
            }
            else {
              lVar8 = FUN_004cbf20(lVar7);
              if (lVar8 == 0) {
                FUN_004cbeb0(lVar7);
                FUN_004c5780(lVar6,0);
                lVar7 = 0;
              }
              else {
                if (sStack_450 < 9) {
                  puVar14 = *(u8 **)((int)lVar7 + 0x18);
                  if (iVar4 == 0xc) {
                    iVar3 = iVar17 * 3;
                    iVar4 = FUN_004c5250(lVar6,&uStack_430,iVar3);
                    if (iVar3 != iVar4) {
                      FUN_004c5780(lVar6,0);
                      return 0;
                    }
                    iVar3 = iVar3 + 0x1a;
                    iVar4 = 0;
                    if (0 < iVar17) {
                      if (8 < iVar17) {
                        bVar2 = false;
                        if ((-1 < iVar17) && (iVar17 < 0x7fffffff)) {
                          bVar2 = true;
                        }
                        if (bVar2) {
                          puVar13 = &uStack_430;
                          puVar12 = puVar14;
                          do {
                            iVar4 = iVar4 + 8;
                            *puVar12 = *(u8 *)((int)puVar13 + 2);
                            puVar12[1] = *(u8 *)((int)puVar13 + 1);
                            puVar12[2] = *(u8 *)puVar13;
                            puVar12[3] = 0xff;
                            puVar12[4] = *(u8 *)((int)puVar13 + 5);
                            puVar12[5] = *(u8 *)(puVar13 + 1);
                            puVar12[6] = *(u8 *)((int)puVar13 + 3);
                            puVar12[7] = 0xff;
                            puVar12[8] = *(u8 *)(puVar13 + 2);
                            puVar12[9] = *(u8 *)((int)puVar13 + 7);
                            puVar12[10] = *(u8 *)((int)puVar13 + 6);
                            puVar12[0xb] = 0xff;
                            puVar12[0xc] = *(u8 *)((int)puVar13 + 0xb);
                            puVar12[0xd] = *(u8 *)((int)puVar13 + 10);
                            puVar12[0xe] = *(u8 *)((int)puVar13 + 9);
                            puVar12[0xf] = 0xff;
                            puVar12[0x10] = *(u8 *)((int)puVar13 + 0xe);
                            puVar12[0x11] = *(u8 *)((int)puVar13 + 0xd);
                            puVar12[0x12] = *(u8 *)(puVar13 + 3);
                            puVar12[0x13] = 0xff;
                            puVar12[0x14] = *(u8 *)((int)puVar13 + 0x11);
                            puVar12[0x15] = *(u8 *)(puVar13 + 4);
                            puVar12[0x16] = *(u8 *)((int)puVar13 + 0xf);
                            puVar12[0x17] = 0xff;
                            puVar12[0x18] = *(u8 *)(puVar13 + 5);
                            puVar12[0x19] = *(u8 *)((int)puVar13 + 0x13);
                            puVar12[0x1a] = *(u8 *)((int)puVar13 + 0x12);
                            puVar12[0x1b] = 0xff;
                            puVar12[0x1c] = *(u8 *)((int)puVar13 + 0x17);
                            puVar12[0x1d] = *(u8 *)((int)puVar13 + 0x16);
                            puVar12[0x1e] = *(u8 *)((int)puVar13 + 0x15);
                            puVar13 = puVar13 + 6;
                            puVar12[0x1f] = 0xff;
                            puVar12 = puVar12 + 0x20;
                          } while (iVar4 < iVar17 + -8);
                        }
                      }
                      if (iVar4 < iVar17) {
                        puVar14 = puVar14 + iVar4 * 4;
                        puVar12 = (u8 *)((int)&uStack_430 + iVar4 * 3);
                        do {
                          iVar4 = iVar4 + 1;
                          *puVar14 = puVar12[2];
                          puVar14[1] = puVar12[1];
                          puVar14[2] = *puVar12;
                          puVar12 = puVar12 + 3;
                          puVar14[3] = 0xff;
                          puVar14 = puVar14 + 4;
                        } while (iVar4 < iVar17);
                      }
                    }
                  }
                  else {
                    if (iVar4 != 0x28) {
                      uStack_18 = 0x19d;
                      uStack_14 = FUN_004c1d10(0xffffffff80000009);
                      FUN_004c1c50(&uStack_18);
                      FUN_004c5780(lVar6,0);
                      return 0;
                    }
                    iVar3 = iVar17 * 4;
                    iVar4 = FUN_004c5250(lVar6,&uStack_430,iVar3);
                    if (iVar3 != iVar4) {
                      FUN_004c5780(lVar6,0);
                      return 0;
                    }
                    iVar3 = iVar3 + 0x36;
                    iVar4 = 0;
                    if (0 < iVar17) {
                      if (8 < iVar17) {
                        bVar2 = false;
                        if ((-1 < iVar17) && (iVar17 < 0x7fffffff)) {
                          bVar2 = true;
                        }
                        if (bVar2) {
                          puVar13 = &uStack_430;
                          puVar12 = puVar14;
                          do {
                            iVar4 = iVar4 + 8;
                            *puVar12 = *(u8 *)((int)puVar13 + 2);
                            puVar12[1] = *(u8 *)((int)puVar13 + 1);
                            puVar12[2] = *(u8 *)puVar13;
                            puVar12[3] = 0xff;
                            puVar12[4] = *(u8 *)((int)puVar13 + 6);
                            puVar12[5] = *(u8 *)((int)puVar13 + 5);
                            puVar12[6] = *(u8 *)(puVar13 + 1);
                            puVar12[7] = 0xff;
                            puVar12[8] = *(u8 *)((int)puVar13 + 10);
                            puVar12[9] = *(u8 *)((int)puVar13 + 9);
                            puVar12[10] = *(u8 *)(puVar13 + 2);
                            puVar12[0xb] = 0xff;
                            puVar12[0xc] = *(u8 *)((int)puVar13 + 0xe);
                            puVar12[0xd] = *(u8 *)((int)puVar13 + 0xd);
                            puVar12[0xe] = *(u8 *)(puVar13 + 3);
                            puVar12[0xf] = 0xff;
                            puVar12[0x10] = *(u8 *)((int)puVar13 + 0x12);
                            puVar12[0x11] = *(u8 *)((int)puVar13 + 0x11);
                            puVar12[0x12] = *(u8 *)(puVar13 + 4);
                            puVar12[0x13] = 0xff;
                            puVar12[0x14] = *(u8 *)((int)puVar13 + 0x16);
                            puVar12[0x15] = *(u8 *)((int)puVar13 + 0x15);
                            puVar12[0x16] = *(u8 *)(puVar13 + 5);
                            puVar12[0x17] = 0xff;
                            puVar12[0x18] = *(u8 *)((int)puVar13 + 0x1a);
                            puVar12[0x19] = *(u8 *)((int)puVar13 + 0x19);
                            puVar12[0x1a] = *(u8 *)(puVar13 + 6);
                            puVar12[0x1b] = 0xff;
                            puVar12[0x1c] = *(u8 *)((int)puVar13 + 0x1e);
                            puVar12[0x1d] = *(u8 *)((int)puVar13 + 0x1d);
                            puVar12[0x1e] = *(u8 *)(puVar13 + 7);
                            puVar13 = puVar13 + 8;
                            puVar12[0x1f] = 0xff;
                            puVar12 = puVar12 + 0x20;
                          } while (iVar4 < iVar17 + -8);
                        }
                      }
                      if (iVar4 < iVar17) {
                        puVar14 = puVar14 + iVar4 * 4;
                        puVar13 = &uStack_430 + iVar4;
                        do {
                          iVar4 = iVar4 + 1;
                          *puVar14 = *(u8 *)((int)puVar13 + 2);
                          puVar14[1] = *(u8 *)((int)puVar13 + 1);
                          puVar14[2] = *(u8 *)puVar13;
                          puVar13 = puVar13 + 1;
                          puVar14[3] = 0xff;
                          puVar14 = puVar14 + 4;
                        } while (iVar4 < iVar17);
                      }
                    }
                  }
                }
                lVar8 = FUN_004c5620(lVar6,iVar11 - iVar3);
                if (lVar8 == 0) {
                  FUN_004cbeb0(lVar7);
                  FUN_004c5780(lVar6,0);
                  lVar7 = 0;
                }
                else {
                  iVar4 = (int)sStack_450;
                  iVar11 = iStack_460 * iVar4 + 7;
                  if (iVar11 < 0) {
                    iVar11 = iStack_460 * iVar4 + 0xe;
                  }
                  uVar1 = (iVar11 >> 3) + 3U & 0xfffffffc;
                  iVar11 = iVar4 + 7;
                  if (iVar11 < 0) {
                    iVar11 = iVar4 + 0xe;
                  }
                  iVar11 = (iStack_460 + 7U & 0xfffffff8) * (iVar11 >> 3);
                  lVar8 = (*DAT_00960178)(iVar11,0x10000);
                  if (lVar8 == 0) {
                    uStack_20 = 0x19d;
                    uStack_1c = FUN_004c1d10(0xffffffff80000013,iVar11);
                    FUN_004c1c50(&uStack_20);
                    FUN_004cbeb0(lVar7);
                    FUN_004c5780(lVar6,0);
                    lVar7 = 0;
                  }
                  else {
                    iVar11 = (int)lVar18;
                    if (((iStack_440 == 0) || (sStack_450 == 0x18)) || (sStack_450 == 0x20)) {
                      lVar19 = 0;
                      if (0 < lVar18) {
                        do {
                          uVar5 = FUN_004c5250(lVar6,lVar8,uVar1);
                          if (uVar1 != uVar5) {
                            (*DAT_0096017c)(lVar8);
                            FUN_004cbeb0(lVar7);
                            FUN_004c5780(lVar6,0);
                            return 0;
                          }
                          FUN_004b9e00(lVar7,(iVar11 + -1) - (int)lVar19,(u16 *)lVar8,sStack_450,0);
                          lVar19 = (long)((int)lVar19 + 1);
                        } while (lVar19 < lVar18);
                      }
                    }
                    else {
                      if (iStack_440 != 1) {
                        uStack_28 = 0x19d;
                        uStack_24 = FUN_004c1d10(0xffffffff80000009);
                        FUN_004c1c50(&uStack_28);
                        (*DAT_0096017c)(lVar8);
                        FUN_004cbeb0(lVar7);
                        FUN_004c5780(lVar6,0);
                        return 0;
                      }
                      lVar19 = 0;
                      if (0 < lVar18) {
                        do {
                          iVar4 = 0;
                          bVar2 = false;
                          do {
                            lVar9 = FUN_004c5250(lVar6,&bStack_8,2);
                            if (lVar9 != 2) {
                              (*DAT_0096017c)(lVar8);
                              FUN_004cbeb0(lVar7);
                              FUN_004c5780(lVar6,0);
                              return 0;
                            }
                            if (bStack_8 == 0) {
                              uVar16 = (u32)bStack_7;
                              if (uVar16 < 3) {
                                if (uVar16 == 0) {
                                  bVar2 = true;
                                }
                                else {
                                  bVar2 = true;
                                  if (uVar16 != 1) {
                                    (*DAT_0096017c)(lVar8);
                                    FUN_004cbeb0(lVar7);
                                    FUN_004c5780(lVar6,0);
                                    return 0;
                                  }
                                  lVar19 = (long)(iVar11 + -1);
                                }
                              }
                              else {
                                uVar10 = FUN_004c5250(lVar6,(int)lVar8 + iVar4,uVar16);
                                if (uVar16 != uVar10) {
                                  (*DAT_0096017c)(lVar8);
                                  FUN_004cbeb0(lVar7);
                                  FUN_004c5780(lVar6,0);
                                  return 0;
                                }
                                iVar4 = iVar4 + (u32)bStack_7;
                                if (((bStack_7 & 1) != 0) &&
                                   (lVar9 = FUN_004c5250(lVar6,&bStack_8,1), lVar9 != 1)) {
                                  (*DAT_0096017c)(lVar8);
                                  FUN_004cbeb0(lVar7);
                                  FUN_004c5780(lVar6,0);
                                  return 0;
                                }
                              }
                            }
                            else {
                              FUN_00521408((int)lVar8 + iVar4,bStack_7);
                              iVar4 = iVar4 + (u32)bStack_8;
                            }
                          } while (!bVar2);
                          FUN_004b9e00(lVar7,(iVar11 + -1) - (int)lVar19,(u16 *)lVar8,sStack_450,1);
                          lVar19 = (long)((int)lVar19 + 1);
                        } while (lVar19 < lVar18);
                      }
                    }
                    (*DAT_0096017c)(lVar8);
                    FUN_004c5780(lVar6,0);
                  }
                }
              }
            }
          }
          else {
            FUN_004c5780(lVar6,0);
            lVar7 = 0;
          }
        }
        else {
          FUN_004c5780(lVar6,0);
          lVar7 = 0;
        }
      }
      else {
        FUN_004c5780(lVar6,0);
        lVar7 = 0;
      }
    }
    else {
      FUN_004c5780(lVar6,0);
      lVar7 = 0;
    }
  }
  return lVar7;
}
// FUN_004BAD50 NONMATCHING
u64 FUN_004bad50(u64 param_1,u64 param_2)

{
  long lVar1;
  u32 uVar2;
  
  lVar1 = FUN_004c58a0(2,2,param_2);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  else {
    uVar2 = 0x18;
    if (*(int *)((int)param_1 + 0x18) != 0) {
      uVar2 = *(u32 *)((int)param_1 + 0xc);
    }
    FUN_004b9870(lVar1,uVar2,param_1);
    FUN_004b99a0(lVar1,uVar2,param_1);
    FUN_004b9d40(lVar1,uVar2,param_1);
    FUN_004b9840(uVar2);
    FUN_004c5780(lVar1,0);
  }
  return param_1;
}
// FUN_004BAE00 NONMATCHING
u32
FUN_004bae00(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
            float *param_6)

{
  u32 uVar1;
  int iVar2;
  float fVar3;
  float fVar4;
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
  float fVar17;
  
  fVar14 = *param_1;
  fVar16 = param_1[1];
  fVar6 = *param_2 - fVar14;
  fVar10 = param_1[2];
  fVar8 = param_2[1] - fVar16;
  fVar4 = *param_3 - fVar14;
  fVar3 = param_2[2] - fVar10;
  fVar12 = param_3[1] - fVar16;
  fVar14 = *param_4 - fVar14;
  fVar16 = param_4[1] - fVar16;
  fVar5 = param_4[2] - fVar10;
  iVar2 = ((int)fVar14 >> 0x1f) + ((int)fVar6 >> 0x1f) + ((int)fVar4 >> 0x1f);
  fVar10 = param_3[2] - fVar10;
  if (iVar2 == 0) {
    fVar7 = param_1[3];
    if (-1 < (int)((u32)(fVar14 - fVar7) | (u32)(fVar6 - fVar7) | (u32)(fVar4 - fVar7))) {
      return 0;
    }
  }
  else if ((iVar2 == -3) &&
          (fVar7 = param_1[3],
          (int)((u32)(fVar14 + fVar7) & (u32)(fVar6 + fVar7) & (u32)(fVar4 + fVar7)) < 0)) {
    return 0;
  }
  iVar2 = ((int)fVar16 >> 0x1f) + ((int)fVar8 >> 0x1f) + ((int)fVar12 >> 0x1f);
  if (iVar2 == 0) {
    fVar7 = param_1[3];
    if (-1 < (int)((u32)(fVar16 - fVar7) | (u32)(fVar8 - fVar7) | (u32)(fVar12 - fVar7))) {
      return 0;
    }
  }
  else if ((iVar2 == -3) &&
          (fVar7 = param_1[3],
          (int)((u32)(fVar16 + fVar7) & (u32)(fVar8 + fVar7) & (u32)(fVar12 + fVar7)) < 0)) {
    return 0;
  }
  iVar2 = ((int)fVar5 >> 0x1f) + ((int)fVar3 >> 0x1f) + ((int)fVar10 >> 0x1f);
  if (iVar2 == 0) {
    fVar7 = param_1[3];
    if (-1 < (int)((u32)(fVar5 - fVar7) | (u32)(fVar3 - fVar7) | (u32)(fVar10 - fVar7))) {
      return 0;
    }
  }
  else if ((iVar2 == -3) &&
          (fVar7 = param_1[3],
          (int)((u32)(fVar5 + fVar7) & (u32)(fVar3 + fVar7) & (u32)(fVar10 + fVar7)) < 0)) {
    return 0;
  }
  fVar17 = *param_3 - *param_2;
  fVar11 = param_3[2] - param_2[2];
  fVar13 = *param_4 - *param_2;
  fVar15 = param_3[1] - param_2[1];
  fVar9 = param_4[1] - param_2[1];
  fVar7 = param_4[2] - param_2[2];
  *param_5 = fVar15 * fVar7 - fVar11 * fVar9;
  param_5[1] = fVar11 * fVar13 - fVar17 * fVar7;
  param_5[2] = fVar17 * fVar9 - fVar15 * fVar13;
  fVar7 = param_5[2] * param_5[2] + *param_5 * *param_5 + param_5[1] * param_5[1];
  if (fVar7 <= 0.0) {
    uVar1 = 0;
  }
  else {
    fVar7 = SQRT(fVar7);
    if (0.0 < fVar7) {
      fVar7 = 1.0 / fVar7;
    }
    fVar11 = param_1[3];
    *param_5 = *param_5 * fVar7;
    param_5[1] = param_5[1] * fVar7;
    fVar9 = param_5[2];
    param_5[2] = fVar9 * fVar7;
    fVar7 = fVar3 * fVar9 * fVar7 + fVar6 * *param_5 + fVar8 * param_5[1];
    if ((fVar7 < -fVar11) || (fVar11 < fVar7)) {
      uVar1 = 0;
    }
    else {
      *param_6 = -fVar7;
      fVar11 = fVar11 * fVar11;
      fVar7 = fVar3 * fVar3 + fVar6 * fVar6 + fVar8 * fVar8 + 0.0 + 0.0;
      if (fVar11 < fVar7) {
        fVar9 = fVar10 * fVar10 + fVar4 * fVar4 + fVar12 * fVar12 + 0.0 + 0.0;
        if (fVar11 < fVar9) {
          fVar13 = fVar5 * fVar5 + fVar14 * fVar14 + fVar16 * fVar16 + 0.0 + 0.0;
          if (fVar11 < fVar13) {
            if (fVar7 < fVar9) {
              if (fVar13 < fVar7) {
                if ((fVar13 < fVar5 * fVar3 + fVar14 * fVar6 + fVar16 * fVar8 + 0.0 + 0.0) &&
                   (fVar13 < fVar5 * fVar10 + fVar14 * fVar4 + fVar16 * fVar12 + 0.0 + 0.0)) {
                  return 0;
                }
              }
              else if ((fVar7 < fVar3 * fVar10 + fVar6 * fVar4 + fVar8 * fVar12 + 0.0 + 0.0) &&
                      (fVar7 < fVar3 * fVar5 + fVar6 * fVar14 + fVar8 * fVar16 + 0.0 + 0.0)) {
                return 0;
              }
            }
            else if (fVar13 < fVar9) {
              if ((fVar13 < fVar5 * fVar3 + fVar14 * fVar6 + fVar16 * fVar8 + 0.0 + 0.0) &&
                 (fVar13 < fVar5 * fVar10 + fVar14 * fVar4 + fVar16 * fVar12 + 0.0 + 0.0)) {
                return 0;
              }
            }
            else if ((fVar9 < fVar10 * fVar3 + fVar4 * fVar6 + fVar12 * fVar8 + 0.0 + 0.0) &&
                    (fVar9 < fVar10 * fVar5 + fVar4 * fVar14 + fVar12 * fVar16 + 0.0 + 0.0)) {
              return 0;
            }
            fVar17 = fVar12 - fVar8;
            fVar15 = fVar10 - fVar3;
            fVar7 = fVar4 - fVar6;
            fVar9 = (fVar15 * fVar3 + fVar7 * fVar6 + fVar17 * fVar8) /
                    (fVar15 * fVar15 + fVar7 * fVar7 + fVar17 * fVar17);
            fVar13 = (fVar6 + 0.0) - fVar7 * fVar9;
            fVar7 = (fVar8 + 0.0) - fVar17 * fVar9;
            fVar15 = (fVar3 + 0.0) - fVar15 * fVar9;
            fVar9 = fVar15 * fVar15 + fVar13 * fVar13 + fVar7 * fVar7;
            if ((fVar9 <= fVar11) ||
               (fVar15 * fVar5 + fVar13 * fVar14 + fVar7 * fVar16 + 0.0 + 0.0 <= fVar9)) {
              fVar17 = fVar16 - fVar12;
              fVar13 = fVar5 - fVar10;
              fVar7 = fVar14 - fVar4;
              fVar9 = (fVar13 * fVar10 + fVar7 * fVar4 + fVar17 * fVar12) /
                      (fVar13 * fVar13 + fVar7 * fVar7 + fVar17 * fVar17);
              fVar15 = (fVar4 + 0.0) - fVar7 * fVar9;
              fVar7 = (fVar12 + 0.0) - fVar17 * fVar9;
              fVar13 = (fVar10 + 0.0) - fVar13 * fVar9;
              fVar9 = fVar13 * fVar13 + fVar15 * fVar15 + fVar7 * fVar7;
              if ((fVar9 <= fVar11) ||
                 (fVar13 * fVar3 + fVar15 * fVar6 + fVar7 * fVar8 + 0.0 + 0.0 <= fVar9)) {
                fVar8 = fVar8 - fVar16;
                fVar3 = fVar3 - fVar5;
                fVar6 = fVar6 - fVar14;
                fVar7 = (fVar3 * fVar5 + fVar6 * fVar14 + fVar8 * fVar16) /
                        (fVar3 * fVar3 + fVar6 * fVar6 + fVar8 * fVar8);
                fVar6 = (fVar14 + 0.0) - fVar6 * fVar7;
                fVar16 = (fVar16 + 0.0) - fVar8 * fVar7;
                fVar5 = (fVar5 + 0.0) - fVar3 * fVar7;
                fVar3 = fVar5 * fVar5 + fVar6 * fVar6 + fVar16 * fVar16;
                if ((fVar3 <= fVar11) ||
                   (fVar5 * fVar10 + fVar6 * fVar4 + fVar16 * fVar12 + 0.0 + 0.0 <= fVar3)) {
                  uVar1 = 1;
                }
                else {
                  uVar1 = 0;
                }
              }
              else {
                uVar1 = 0;
              }
            }
            else {
              uVar1 = 0;
            }
          }
          else {
            uVar1 = 1;
          }
        }
        else {
          uVar1 = 1;
        }
      }
      else {
        uVar1 = 1;
      }
    }
  }
  return uVar1;
}
// FUN_004BB5D0 NONMATCHING
u32 FUN_004bb5d0(float *param_1,float *param_2,float *param_3,float *param_4)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
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
  float fVar17;
  float fVar18;
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
  
  fVar17 = param_1[1];
  fVar12 = param_2[1];
  if (fVar17 < fVar12) {
    uVar5 = 4;
  }
  else if (fVar12 < param_1[4]) {
    uVar5 = 8;
  }
  else {
    uVar5 = 0;
  }
  fVar18 = *param_1;
  fVar11 = *param_2;
  if (fVar18 < fVar11) {
    uVar1 = 1;
  }
  else if (fVar11 < param_1[3]) {
    uVar1 = 2;
  }
  else {
    uVar1 = 0;
  }
  fVar15 = param_1[2];
  fVar9 = param_2[2];
  if (fVar15 < fVar9) {
    uVar3 = 0x10;
  }
  else if (fVar9 < param_1[5]) {
    uVar3 = 0x20;
  }
  else {
    uVar3 = 0;
  }
  uVar3 = uVar3 | uVar1 | uVar5;
  if (uVar3 == 0) {
    uVar2 = 1;
  }
  else {
    fVar7 = param_3[1];
    if (fVar17 < fVar7) {
      uVar5 = 4;
    }
    else if (fVar7 < param_1[4]) {
      uVar5 = 8;
    }
    else {
      uVar5 = 0;
    }
    fVar10 = *param_3;
    if (fVar18 < fVar10) {
      uVar1 = 1;
    }
    else if (fVar10 < param_1[3]) {
      uVar1 = 2;
    }
    else {
      uVar1 = 0;
    }
    fVar8 = param_3[2];
    if (fVar15 < fVar8) {
      uVar4 = 0x10;
    }
    else if (fVar8 < param_1[5]) {
      uVar4 = 0x20;
    }
    else {
      uVar4 = 0;
    }
    uVar4 = uVar4 | uVar1 | uVar5;
    if (uVar4 == 0) {
      uVar2 = 1;
    }
    else {
      fVar16 = param_4[1];
      if (fVar17 < fVar16) {
        uVar5 = 4;
      }
      else if (fVar16 < param_1[4]) {
        uVar5 = 8;
      }
      else {
        uVar5 = 0;
      }
      fVar13 = *param_4;
      if (fVar18 < fVar13) {
        uVar1 = 1;
      }
      else if (fVar13 < param_1[3]) {
        uVar1 = 2;
      }
      else {
        uVar1 = 0;
      }
      fVar14 = param_4[2];
      if (fVar15 < fVar14) {
        uVar6 = 0x10;
      }
      else if (fVar14 < param_1[5]) {
        uVar6 = 0x20;
      }
      else {
        uVar6 = 0;
      }
      uVar6 = uVar6 | uVar1 | uVar5;
      if (uVar6 == 0) {
        uVar2 = 1;
      }
      else if ((uVar6 & uVar3 & uVar4) == 0) {
        if ((uVar3 & uVar4) == 0) {
          uVar5 = uVar3 ^ uVar4;
          fVar26 = fVar10 - fVar11;
          fVar24 = fVar12 - param_1[4];
          fVar23 = fVar9 - param_1[5];
          fVar25 = fVar7 - fVar12;
          fVar27 = fVar8 - fVar9;
          fVar20 = fVar11 - fVar18;
          fVar21 = fVar11 - param_1[3];
          fVar19 = fVar12 - fVar17;
          fVar22 = fVar9 - fVar15;
          if ((uVar5 & 1) != 0) {
            fVar28 = fVar20 * fVar25;
            if (fVar26 < 0.0) {
              if ((((fVar28 < fVar19 * fVar26) && (fVar24 * fVar26 < fVar28)) &&
                  (fVar20 * fVar27 < fVar22 * fVar26)) && (fVar23 * fVar26 < fVar20 * fVar27)) {
                return 1;
              }
            }
            else if (((fVar19 * fVar26 < fVar28) && (fVar28 < fVar24 * fVar26)) &&
                    ((fVar22 * fVar26 < fVar20 * fVar27 && (fVar20 * fVar27 < fVar23 * fVar26)))) {
              return 1;
            }
          }
          if ((uVar5 & 2) != 0) {
            fVar28 = fVar21 * fVar25;
            if (fVar26 < 0.0) {
              if (((fVar28 < fVar19 * fVar26) && (fVar24 * fVar26 < fVar28)) &&
                 ((fVar21 * fVar27 < fVar22 * fVar26 && (fVar23 * fVar26 < fVar21 * fVar27)))) {
                return 1;
              }
            }
            else if ((((fVar19 * fVar26 < fVar28) && (fVar28 < fVar24 * fVar26)) &&
                     (fVar22 * fVar26 < fVar21 * fVar27)) && (fVar21 * fVar27 < fVar23 * fVar26)) {
              return 1;
            }
          }
          if ((uVar5 & 4) != 0) {
            fVar28 = fVar19 * fVar27;
            if (fVar25 < 0.0) {
              if (((fVar28 < fVar22 * fVar25) && (fVar23 * fVar25 < fVar28)) &&
                 ((fVar19 * fVar26 < fVar20 * fVar25 && (fVar21 * fVar25 < fVar19 * fVar26)))) {
                return 1;
              }
            }
            else if (((fVar22 * fVar25 < fVar28) && (fVar28 < fVar23 * fVar25)) &&
                    ((fVar20 * fVar25 < fVar19 * fVar26 && (fVar19 * fVar26 < fVar21 * fVar25)))) {
              return 1;
            }
          }
          if ((uVar5 & 8) != 0) {
            fVar28 = fVar24 * fVar27;
            if (fVar25 < 0.0) {
              if ((((fVar28 < fVar22 * fVar25) && (fVar23 * fVar25 < fVar28)) &&
                  (fVar24 * fVar26 < fVar20 * fVar25)) && (fVar21 * fVar25 < fVar24 * fVar26)) {
                return 1;
              }
            }
            else if (((fVar22 * fVar25 < fVar28) && (fVar28 < fVar23 * fVar25)) &&
                    ((fVar20 * fVar25 < fVar24 * fVar26 && (fVar24 * fVar26 < fVar21 * fVar25)))) {
              return 1;
            }
          }
          if ((uVar5 & 0x10) != 0) {
            fVar28 = fVar22 * fVar26;
            if (fVar27 < 0.0) {
              if (((fVar28 < fVar20 * fVar27) && (fVar21 * fVar27 < fVar28)) &&
                 ((fVar22 * fVar25 < fVar19 * fVar27 && (fVar24 * fVar27 < fVar22 * fVar25)))) {
                return 1;
              }
            }
            else if ((((fVar20 * fVar27 < fVar28) && (fVar28 < fVar21 * fVar27)) &&
                     (fVar19 * fVar27 < fVar22 * fVar25)) && (fVar22 * fVar25 < fVar24 * fVar27)) {
              return 1;
            }
          }
          if ((uVar5 & 0x20) != 0) {
            fVar26 = fVar23 * fVar26;
            if (fVar27 < 0.0) {
              if (((fVar26 < fVar20 * fVar27) && (fVar21 * fVar27 < fVar26)) &&
                 ((fVar23 * fVar25 < fVar19 * fVar27 && (fVar24 * fVar27 < fVar23 * fVar25)))) {
                return 1;
              }
            }
            else if (((fVar20 * fVar27 < fVar26) && (fVar26 < fVar21 * fVar27)) &&
                    ((fVar19 * fVar27 < fVar23 * fVar25 && (fVar23 * fVar25 < fVar24 * fVar27)))) {
              return 1;
            }
          }
        }
        if ((uVar3 & uVar6) == 0) {
          uVar3 = uVar3 ^ uVar6;
          fVar26 = fVar13 - fVar11;
          fVar24 = fVar12 - param_1[4];
          fVar23 = fVar9 - param_1[5];
          fVar25 = fVar16 - fVar12;
          fVar27 = fVar14 - fVar9;
          fVar20 = fVar11 - fVar18;
          fVar21 = fVar11 - param_1[3];
          fVar19 = fVar12 - fVar17;
          fVar22 = fVar9 - fVar15;
          if ((uVar3 & 1) != 0) {
            fVar28 = fVar20 * fVar25;
            if (fVar26 < 0.0) {
              if ((((fVar28 < fVar19 * fVar26) && (fVar24 * fVar26 < fVar28)) &&
                  (fVar20 * fVar27 < fVar22 * fVar26)) && (fVar23 * fVar26 < fVar20 * fVar27)) {
                return 1;
              }
            }
            else if (((fVar19 * fVar26 < fVar28) && (fVar28 < fVar24 * fVar26)) &&
                    ((fVar22 * fVar26 < fVar20 * fVar27 && (fVar20 * fVar27 < fVar23 * fVar26)))) {
              return 1;
            }
          }
          if ((uVar3 & 2) != 0) {
            fVar28 = fVar21 * fVar25;
            if (fVar26 < 0.0) {
              if (((fVar28 < fVar19 * fVar26) && (fVar24 * fVar26 < fVar28)) &&
                 ((fVar21 * fVar27 < fVar22 * fVar26 && (fVar23 * fVar26 < fVar21 * fVar27)))) {
                return 1;
              }
            }
            else if ((((fVar19 * fVar26 < fVar28) && (fVar28 < fVar24 * fVar26)) &&
                     (fVar22 * fVar26 < fVar21 * fVar27)) && (fVar21 * fVar27 < fVar23 * fVar26)) {
              return 1;
            }
          }
          if ((uVar3 & 4) != 0) {
            fVar28 = fVar19 * fVar27;
            if (fVar25 < 0.0) {
              if (((fVar28 < fVar22 * fVar25) && (fVar23 * fVar25 < fVar28)) &&
                 ((fVar19 * fVar26 < fVar20 * fVar25 && (fVar21 * fVar25 < fVar19 * fVar26)))) {
                return 1;
              }
            }
            else if (((fVar22 * fVar25 < fVar28) && (fVar28 < fVar23 * fVar25)) &&
                    ((fVar20 * fVar25 < fVar19 * fVar26 && (fVar19 * fVar26 < fVar21 * fVar25)))) {
              return 1;
            }
          }
          if ((uVar3 & 8) != 0) {
            fVar28 = fVar24 * fVar27;
            if (fVar25 < 0.0) {
              if ((((fVar28 < fVar22 * fVar25) && (fVar23 * fVar25 < fVar28)) &&
                  (fVar24 * fVar26 < fVar20 * fVar25)) && (fVar21 * fVar25 < fVar24 * fVar26)) {
                return 1;
              }
            }
            else if (((fVar22 * fVar25 < fVar28) && (fVar28 < fVar23 * fVar25)) &&
                    ((fVar20 * fVar25 < fVar24 * fVar26 && (fVar24 * fVar26 < fVar21 * fVar25)))) {
              return 1;
            }
          }
          if ((uVar3 & 0x10) != 0) {
            fVar28 = fVar22 * fVar26;
            if (fVar27 < 0.0) {
              if (((fVar28 < fVar20 * fVar27) && (fVar21 * fVar27 < fVar28)) &&
                 ((fVar22 * fVar25 < fVar19 * fVar27 && (fVar24 * fVar27 < fVar22 * fVar25)))) {
                return 1;
              }
            }
            else if ((((fVar20 * fVar27 < fVar28) && (fVar28 < fVar21 * fVar27)) &&
                     (fVar19 * fVar27 < fVar22 * fVar25)) && (fVar22 * fVar25 < fVar24 * fVar27)) {
              return 1;
            }
          }
          if ((uVar3 & 0x20) != 0) {
            fVar26 = fVar23 * fVar26;
            if (fVar27 < 0.0) {
              if (((fVar26 < fVar20 * fVar27) && (fVar21 * fVar27 < fVar26)) &&
                 ((fVar23 * fVar25 < fVar19 * fVar27 && (fVar24 * fVar27 < fVar23 * fVar25)))) {
                return 1;
              }
            }
            else if (((fVar20 * fVar27 < fVar26) && (fVar26 < fVar21 * fVar27)) &&
                    ((fVar19 * fVar27 < fVar23 * fVar25 && (fVar23 * fVar25 < fVar24 * fVar27)))) {
              return 1;
            }
          }
        }
        if ((uVar4 & uVar6) == 0) {
          uVar4 = uVar4 ^ uVar6;
          fVar18 = fVar10 - fVar18;
          fVar17 = fVar7 - fVar17;
          fVar15 = fVar8 - fVar15;
          fVar21 = fVar13 - fVar10;
          fVar24 = fVar16 - fVar7;
          fVar23 = fVar14 - fVar8;
          fVar20 = fVar10 - param_1[3];
          fVar19 = fVar7 - param_1[4];
          fVar22 = fVar8 - param_1[5];
          if ((uVar4 & 1) != 0) {
            fVar25 = fVar18 * fVar24;
            if (fVar21 < 0.0) {
              if ((((fVar25 < fVar17 * fVar21) && (fVar19 * fVar21 < fVar25)) &&
                  (fVar18 * fVar23 < fVar15 * fVar21)) && (fVar22 * fVar21 < fVar18 * fVar23)) {
                return 1;
              }
            }
            else if (((fVar17 * fVar21 < fVar25) && (fVar25 < fVar19 * fVar21)) &&
                    ((fVar15 * fVar21 < fVar18 * fVar23 && (fVar18 * fVar23 < fVar22 * fVar21)))) {
              return 1;
            }
          }
          if ((uVar4 & 2) != 0) {
            fVar25 = fVar20 * fVar24;
            if (fVar21 < 0.0) {
              if (((fVar25 < fVar17 * fVar21) && (fVar19 * fVar21 < fVar25)) &&
                 ((fVar20 * fVar23 < fVar15 * fVar21 && (fVar22 * fVar21 < fVar20 * fVar23)))) {
                return 1;
              }
            }
            else if ((((fVar17 * fVar21 < fVar25) && (fVar25 < fVar19 * fVar21)) &&
                     (fVar15 * fVar21 < fVar20 * fVar23)) && (fVar20 * fVar23 < fVar22 * fVar21)) {
              return 1;
            }
          }
          if ((uVar4 & 4) != 0) {
            fVar25 = fVar17 * fVar23;
            if (fVar24 < 0.0) {
              if (((fVar25 < fVar15 * fVar24) && (fVar22 * fVar24 < fVar25)) &&
                 ((fVar17 * fVar21 < fVar18 * fVar24 && (fVar20 * fVar24 < fVar17 * fVar21)))) {
                return 1;
              }
            }
            else if (((fVar15 * fVar24 < fVar25) && (fVar25 < fVar22 * fVar24)) &&
                    ((fVar18 * fVar24 < fVar17 * fVar21 && (fVar17 * fVar21 < fVar20 * fVar24)))) {
              return 1;
            }
          }
          if ((uVar4 & 8) != 0) {
            fVar25 = fVar19 * fVar23;
            if (fVar24 < 0.0) {
              if ((((fVar25 < fVar15 * fVar24) && (fVar22 * fVar24 < fVar25)) &&
                  (fVar19 * fVar21 < fVar18 * fVar24)) && (fVar20 * fVar24 < fVar19 * fVar21)) {
                return 1;
              }
            }
            else if (((fVar15 * fVar24 < fVar25) && (fVar25 < fVar22 * fVar24)) &&
                    ((fVar18 * fVar24 < fVar19 * fVar21 && (fVar19 * fVar21 < fVar20 * fVar24)))) {
              return 1;
            }
          }
          if ((uVar4 & 0x10) != 0) {
            fVar25 = fVar15 * fVar21;
            if (fVar23 < 0.0) {
              if (((fVar25 < fVar18 * fVar23) && (fVar20 * fVar23 < fVar25)) &&
                 ((fVar15 * fVar24 < fVar17 * fVar23 && (fVar19 * fVar23 < fVar15 * fVar24)))) {
                return 1;
              }
            }
            else if ((((fVar18 * fVar23 < fVar25) && (fVar25 < fVar20 * fVar23)) &&
                     (fVar17 * fVar23 < fVar15 * fVar24)) && (fVar15 * fVar24 < fVar19 * fVar23)) {
              return 1;
            }
          }
          if ((uVar4 & 0x20) != 0) {
            fVar21 = fVar22 * fVar21;
            if (fVar23 < 0.0) {
              if (((fVar21 < fVar18 * fVar23) && (fVar20 * fVar23 < fVar21)) &&
                 ((fVar22 * fVar24 < fVar17 * fVar23 && (fVar19 * fVar23 < fVar22 * fVar24)))) {
                return 1;
              }
            }
            else if (((fVar18 * fVar23 < fVar21) && (fVar21 < fVar20 * fVar23)) &&
                    ((fVar17 * fVar23 < fVar22 * fVar24 && (fVar22 * fVar24 < fVar19 * fVar23)))) {
              return 1;
            }
          }
        }
        fVar7 = fVar7 - fVar12;
        fVar14 = fVar14 - fVar9;
        fVar10 = fVar10 - fVar11;
        fVar16 = fVar16 - fVar12;
        fVar8 = fVar8 - fVar9;
        fVar12 = fVar7 * fVar14 - fVar8 * fVar16;
        fVar13 = fVar13 - fVar11;
        fVar17 = fVar8 * fVar13 - fVar10 * fVar14;
        fVar11 = fVar10 * fVar16 - fVar7 * fVar13;
        fVar9 = *param_1 - param_1[3];
        fVar18 = param_1[3] - *param_2;
        if ((int)((u32)fVar12 ^ (u32)fVar17) < 0) {
          fVar19 = param_1[4] - param_1[1];
          fVar15 = param_1[1] - param_2[1];
        }
        else {
          fVar19 = param_1[1] - param_1[4];
          fVar15 = param_1[4] - param_2[1];
        }
        if ((int)((u32)fVar12 ^ (u32)fVar11) < 0) {
          fVar20 = param_1[2] - param_2[2];
          fVar21 = param_1[5] - param_1[2];
        }
        else {
          fVar20 = param_1[5] - param_2[2];
          fVar21 = param_1[2] - param_1[5];
        }
        fVar22 = -(fVar21 * fVar11 + fVar9 * fVar12 + fVar19 * fVar17);
        fVar12 = fVar20 * fVar11 + fVar18 * fVar12 + fVar15 * fVar17;
        if (fVar22 < 0.0) {
          if ((fVar12 < 0.0) && (fVar22 < fVar12)) {
            fVar11 = (fVar15 * fVar21 + 0.0) - fVar20 * fVar19;
            fVar20 = (fVar20 * fVar9 + 0.0) - fVar18 * fVar21;
            fVar17 = (fVar18 * fVar19 + 0.0) - fVar15 * fVar9;
            fVar12 = fVar14 * fVar17 + fVar13 * fVar11 + fVar16 * fVar20 + 0.0 + 0.0;
            if ((fVar12 < 0.0) &&
               (((fVar22 < fVar12 &&
                 (fVar17 = -(fVar8 * fVar17 + fVar10 * fVar11 + fVar7 * fVar20 + 0.0 + 0.0),
                 fVar17 < 0.0)) && (fVar22 < fVar12 + fVar17)))) {
              return 1;
            }
          }
        }
        else if ((0.0 < fVar12) && (fVar12 < fVar22)) {
          fVar11 = (fVar15 * fVar21 + 0.0) - fVar20 * fVar19;
          fVar20 = (fVar20 * fVar9 + 0.0) - fVar18 * fVar21;
          fVar17 = (fVar18 * fVar19 + 0.0) - fVar15 * fVar9;
          fVar12 = fVar14 * fVar17 + fVar13 * fVar11 + fVar16 * fVar20 + 0.0 + 0.0;
          if (((0.0 < fVar12) &&
              ((fVar12 < fVar22 &&
               (fVar17 = -(fVar8 * fVar17 + fVar10 * fVar11 + fVar7 * fVar20 + 0.0 + 0.0),
               0.0 < fVar17)))) && (fVar12 + fVar17 < fVar22)) {
            return 1;
          }
        }
        uVar2 = 0;
      }
      else {
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}
// FUN_004BC830 NONMATCHING
void FUN_004bc830(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  pfVar4 = (float *)(param_3 * 8 + param_1);
  pfVar3 = (float *)(param_1 + param_4 * 8);
  pfVar2 = (float *)(param_5 * 8 + param_1);
  fVar6 = *pfVar4;
  fVar9 = pfVar3[1];
  fVar10 = pfVar4[1];
  fVar8 = *pfVar3;
  fVar7 = pfVar2[1];
  iVar1 = **(int **)(param_6 + 8);
  fVar5 = *pfVar2;
  fVar6 = (float)FUN_0052e788(((fVar5 * fVar10 +
                               ((fVar8 * fVar7 + (fVar6 * fVar9 - fVar8 * fVar10)) - fVar5 * fVar9))
                              - fVar6 * fVar7) * 0.5);
  pfVar4 = (float *)(param_2 + param_3 * 0xc);
  pfVar3 = (float *)(param_2 + param_4 * 0xc);
  fVar6 = fVar6 * (float)(*(int *)(iVar1 + 0xc) * *(int *)(iVar1 + 0x10));
  pfVar2 = (float *)(param_2 + param_5 * 0xc);
  fVar11 = *pfVar3 - *pfVar4;
  fVar7 = *pfVar2 - *pfVar4;
  fVar9 = pfVar3[2] - pfVar4[2];
  fVar10 = pfVar3[1] - pfVar4[1];
  fVar8 = pfVar2[1] - pfVar4[1];
  fVar5 = pfVar2[2] - pfVar4[2];
  fStack_10 = fVar10 * fVar5 - fVar9 * fVar8;
  fStack_c = fVar9 * fVar7 - fVar11 * fVar5;
  fStack_8 = fVar11 * fVar8 - fVar10 * fVar7;
  fVar5 = (float)FUN_004c6ac0(&fStack_10);
  if ((0.0 < fVar5 * 0.5) && (1.0 < fVar6)) {
    *(float *)(param_6 + 0xc) =
         *(float *)(param_6 + 0xc) + SQRT((fVar5 * 0.5 * *(float *)(param_6 + 0x14)) / fVar6);
    *(int *)(param_6 + 0x10) = *(int *)(param_6 + 0x10) + 1;
  }
  return;
}
// FUN_004BCA00 NONMATCHING
u64 FUN_004bca00(u64 param_1,u64 param_2)

{
  long lVar1;
  int iVar2;
  u16 *puVar3;
  int iVar4;
  u32 uVar5;
  int iVar6;
  
  iVar2 = (int)param_1;
  uVar5 = 0;
  if (*(short *)(iVar2 + 0x84) != 0) {
    iVar4 = 0;
    do {
      iVar6 = (int)param_2;
      puVar3 = (u16 *)(*(int *)(iVar2 + 4) + iVar4);
      lVar1 = (**(code **)(iVar6 + 0x18))
                        (*(u32 *)
                          (*(int *)(*(int *)(iVar6 + 4) + 0x10) + (u32)(u16)puVar3[3] * 4),
                         *(u32 *)(iVar6 + 8));
      if (lVar1 != 0) {
        FUN_004bc830(*(u32 *)(iVar2 + 0x10),*(u32 *)(iVar2 + 8),*puVar3,puVar3[1],
                     puVar3[2],param_2);
      }
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 8;
    } while (uVar5 < *(u16 *)(iVar2 + 0x84));
  }
  return param_1;
}
#pragma schedule on
// FUN_004BCAE0
u64 FUN_004bcae0(u64 param_1,int param_2)

{
  *(u8 **)(param_2 + 0x18) = LAB_004bcb20_abs;
  FUN_004bca00_void();
  return param_1;
}
#pragma schedule off
#pragma schedule on
// FUN_004BCB20
bool FUN_004bcb20(u32 *param_1,int param_2)
{
  return *param_1 == (u32)param_2;
}
#pragma schedule off
// FUN_004BCB30 NONMATCHING
u64 FUN_004bcb30(u64 param_1,u64 param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  
  iVar1 = (int)param_2;
  *(int *)(iVar1 + 8) = (int)param_1;
  *(u32 *)(iVar1 + 0xc) = 0;
  *(u32 *)(iVar1 + 0x10) = 0;
  FUN_0049a870(*(u32 *)(iVar1 + 4),0x4bcae0,param_2);
  if (0 < *(int *)(iVar1 + 0x10)) {
    fVar2 = (float)FUN_0052ea30(*(float *)(iVar1 + 0xc) / (float)*(int *)(iVar1 + 0x10));
    fVar3 = (float)FUN_0052ea30(0x40000000);
    FUN_004d8320(-(fVar2 / fVar3),param_1);
  }
  return param_1;
}
// FUN_004BCBF0 NONMATCHING
void FUN_004bcbf0(int param_1,int param_2)

{
  u64 uVar1;
  long lVar2;
  int iStack_40;
  int iStack_3c;
  u32 uStack_20;
  int iStack_1c;
  float fStack_c;
  
  if (((*(u32 *)(param_1 + 8) & 0x1000000) != 0x1000000) && ((*(u32 *)(param_1 + 8) & 0x84) != 0))
  {
    uVar1 = FUN_004ca5b0();
    FUN_004ca560(&iStack_40,uVar1);
    uStack_20 = 0;
    fStack_c = (float)(iStack_40 * iStack_3c) /
               (*(float *)(param_2 + 0x68) * 2.0 * *(float *)(param_2 + 0x6c) * 2.0);
    iStack_1c = param_1;
    lVar2 = FUN_004d11f0();
    if (lVar2 != 0) {
      uVar1 = FUN_004d11f0();
      FUN_004d0dc0(uVar1,0x4bcb30,&uStack_20);
    }
  }
  return;
}
// FUN_004BCCD0 NONMATCHING
u32 FUN_004bccd0(u64 param_1,u32 *param_2)

{
  u8 bVar1;
  int *piVar2;
  int iVar3;
  u32 uVar4;
  long lVar5;
  long lVar6;
  u32 uVar7;
  u32 uVar8;
  int *piVar9;
  int iVar10;
  u32 uVar11;
  int iVar12;
  int iVar13;
  u8 auStack_60 [32];
  u8 auStack_40 [32];
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  int iStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  bVar1 = 0;
  lVar5 = FUN_004c5250(param_1,auStack_60,0x48);
  if (lVar5 == 0x48) {
    piVar2 = (int *)(*DAT_00960178)(uStack_20 << 2,0x101b3);
    if (piVar2 == (int *)0x0) {
      uStack_18 = 0x1b3;
      uStack_14 = FUN_004c1d10(0xffffffff80000013,uStack_20 << 2);
      FUN_004c1c50(&uStack_18);
      uVar4 = 0;
    }
    else {
      iVar12 = 0;
      piVar9 = piVar2;
      if ((int)uStack_20 < 1) {
        iVar12 = *piVar2;
      }
      else {
        do {
          lVar5 = FUN_004c1600(param_1,0x18,0,0);
          if (lVar5 == 0) {
            return 0;
          }
          iVar10 = FUN_004cd750(param_1);
          *piVar9 = iVar10;
          if ((u32 *)*piVar9 == (u32 *)0x0) {
            return 0;
          }
          if ((*(u32 *)*piVar9 & 2) == 0) {
            FUN_004cd940();
          }
          iVar12 = iVar12 + 1;
          piVar9 = piVar9 + 1;
        } while (iVar12 < (int)uStack_20);
        iVar12 = *piVar2;
      }
      uVar11 = 4;
      uStack_4 = *(u32 *)(iVar12 + 4);
      uStack_8 = *(u32 *)(*piVar2 + 8);
      iStack_c = *(int *)(*piVar2 + 0xc);
      if ((int)uStack_20 < 2) {
        if (((uStack_1c & 0xff) != 1) && ((uStack_1c & 0xff) != 2)) {
          uVar11 = 0x9004;
        }
      }
      else {
        uVar11 = 0x8004;
      }
      FUN_004cdd50(*piVar2,uVar11,&uStack_4,&uStack_8,&iStack_c,&uStack_10);
      lVar5 = FUN_004ce0f0(uStack_4,uStack_8,iStack_c,uVar11 | uStack_10);
      if (lVar5 == 0) {
        iVar12 = 0;
        piVar9 = piVar2;
        if (0 < (int)uStack_20) {
          do {
            FUN_004cbeb0(*piVar9);
            iVar12 = iVar12 + 1;
            piVar9 = piVar9 + 1;
          } while (iVar12 < (int)uStack_20);
        }
        (*DAT_0096017c)(piVar2);
        uVar4 = 0;
      }
      else {
        iVar10 = (int)lVar5;
        iVar12 = *(int *)(iVar10 + 0xc);
        if ((*(int *)(*piVar2 + 4) != iVar12) || (*(int *)(*piVar2 + 8) != *(int *)(iVar10 + 0x10)))
        {
          iVar10 = *(int *)(iVar10 + 0x10);
          if (iStack_c == 8) {
            FUN_004cde90(lVar5);
            lVar5 = FUN_004ce0f0(iVar12,iVar10,0x20,uVar11 | 0x500);
            if (lVar5 == 0) {
              lVar5 = FUN_004ce0f0(iVar12,iVar10,0x10,uVar11 | 0x100);
            }
          }
          iVar3 = FUN_004cdf80(lVar5);
          iVar13 = 0;
          piVar9 = piVar2;
          if (0 < iVar3) {
            do {
              lVar6 = FUN_004cee30(*piVar9,iVar12,iVar10);
              if (lVar6 == 0) {
                return 0;
              }
              FUN_004cbeb0(*piVar9);
              *piVar9 = (int)lVar6;
              if (1 < iVar12) {
                iVar12 = iVar12 >> 1;
              }
              if (1 < iVar10) {
                iVar10 = iVar10 >> 1;
              }
              iVar13 = iVar13 + 1;
              piVar9 = piVar9 + 1;
            } while (iVar13 < iVar3);
          }
        }
        iVar12 = (int)lVar5;
        if (1 < (int)uStack_20) {
          bVar1 = *(u8 *)(iVar12 + 0x23) & 0x10;
          *(u8 *)(iVar12 + 0x23) = *(u8 *)(iVar12 + 0x23) & ~bVar1;
        }
        iVar10 = FUN_004cdf80(lVar5);
        uVar11 = 0;
        piVar9 = piVar2;
        if (0 < iVar10) {
          do {
            if (uVar11 == uStack_20) break;
            lVar6 = FUN_004ce200(lVar5,uVar11 & 0xff,1);
            if (lVar6 == 0) {
              return 0;
            }
            lVar6 = FUN_004cdce0(lVar5,*piVar9);
            if (lVar6 == 0) {
              return 0;
            }
            lVar6 = FUN_004cde00(lVar5);
            if (lVar6 == 0) {
              return 0;
            }
            FUN_004cbeb0(*piVar9);
            uVar11 = uVar11 + 1;
            piVar9 = piVar9 + 1;
          } while ((int)uVar11 < iVar10);
        }
        if (1 < (int)uStack_20) {
          *(u8 *)(iVar12 + 0x23) = *(u8 *)(iVar12 + 0x23) | bVar1;
        }
        if ((int)uVar11 < (int)uStack_20) {
          piVar9 = piVar2 + uVar11;
          do {
            FUN_004cbeb0(*piVar9);
            uVar11 = uVar11 + 1;
            piVar9 = piVar9 + 1;
          } while ((int)uVar11 < (int)uStack_20);
        }
        (*DAT_0096017c)(piVar2);
        lVar5 = FUN_004d0e40(lVar5);
        if (lVar5 == 0) {
          uVar4 = 0;
        }
        else {
          FUN_004d0fd0(lVar5,auStack_60);
          FUN_004d1070(lVar5,auStack_40);
          iVar12 = (int)lVar5;
          *(u32 *)(iVar12 + 0x50) = *(u32 *)(iVar12 + 0x50) & 0xffffff00 | uStack_1c & 0xff;
          uVar7 = (uStack_1c & 0xf00) >> 8;
          uVar11 = (uStack_1c & 0xf000) >> 0xc;
          if ((uVar7 == 0) && (uVar11 == 0)) {
            uVar11 = 1;
            uVar8 = 1;
          }
          else if (((uVar7 != 0) || (uVar8 = uVar11, uVar11 == 0)) &&
                  ((uVar8 = uVar7, uVar7 != 0 && (uVar11 == 0)))) {
            uVar11 = uVar7;
          }
          *(u32 *)(iVar12 + 0x50) = *(u32 *)(iVar12 + 0x50) & 0xfffff0ff | uVar8 << 8;
          *(u32 *)(iVar12 + 0x50) = *(u32 *)(iVar12 + 0x50) & 0xffff0fff | uVar11 << 0xc;
          FUN_004d1110(*param_2,lVar5);
          uVar4 = *param_2;
        }
      }
    }
  }
  else {
    uVar4 = 0;
  }
  return uVar4;
}
// FUN_004BD260 NONMATCHING
long FUN_004bd260(u64 param_1)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  u64 uVar4;
  u64 uVar5;
  int iVar6;
  u32 uVar7;
  u8 auStack_120 [128];
  u8 auStack_a0 [136];
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_c;
  u32 uStack_8;
  int iStack_4;
  
  lVar3 = FUN_004c1600(param_1,1,&iStack_4,&uStack_8);
  if (lVar3 == 0) {
    lVar3 = 0;
  }
  else if ((uStack_8 < 0x35000) || (0x37002 < uStack_8)) {
    uStack_18 = 0x1b3;
    uStack_14 = FUN_004c1d10(0xffffffff80000004);
    FUN_004c1c50(&uStack_18);
    lVar3 = 0;
  }
  else {
    FUN_00521408(&uStack_c,0,4);
    iVar1 = FUN_004c5250(param_1,&uStack_c,iStack_4);
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
      lVar3 = FUN_004c78a0(auStack_a0,param_1);
      if (lVar3 == 0) {
        FUN_004d0b60(uVar4);
        FUN_004d0ba0(uVar5);
        lVar3 = 0;
      }
      else {
        lVar3 = FUN_004c78a0(auStack_120,param_1);
        if (lVar3 == 0) {
          FUN_004d0b60(uVar4);
          FUN_004d0ba0(uVar5);
          lVar3 = 0;
        }
        else {
          lVar3 = FUN_004d0e40(0);
          if (lVar3 == 0) {
            FUN_004c5ea0(0x77e6d0,param_1);
            FUN_004d0b60(uVar4);
            FUN_004d0ba0(uVar5);
            lVar3 = 0;
          }
          else {
            FUN_004d0fd0(lVar3,auStack_a0);
            iVar1 = (int)lVar3;
            if ((void *)0 == (u8 *)0x120) {
              FUN_004d1070(lVar3,0x7cdd10);
              iVar6 = *(int *)(iVar1 + 0x54);
            }
            else {
              FUN_004d1070(lVar3);
              iVar6 = *(int *)(iVar1 + 0x54);
            }
            if (iVar6 == 1) {
              *(u32 *)(iVar1 + 0x50) = uStack_c & 0xffff;
            }
            FUN_004d0b60(uVar4);
            FUN_004d0ba0(uVar5);
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
// FUN_004BD4E0 NONMATCHING
u32 FUN_004bd4e0(u64 param_1)

{
  u8 bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  u32 uVar5;
  long lVar6;
  long lVar7;
  int *piVar8;
  int iVar9;
  u32 uVar10;
  int iVar11;
  int iStack_40;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_14;
  int iStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  bVar1 = 0;
  lVar6 = FUN_004c5250(param_1,&uStack_4,4);
  if (lVar6 == 4) {
    piVar2 = (int *)(*DAT_00960178)(uStack_4 << 2,0x101b3);
    if (piVar2 == (int *)0x0) {
      uStack_20 = 0x1b3;
      uStack_1c = FUN_004c1d10(0xffffffff80000013,uStack_4 << 2);
      FUN_004c1c50(&uStack_20);
      uVar5 = 0;
    }
    else {
      iVar9 = 0;
      piVar8 = piVar2;
      if (0 < (int)uStack_4) {
        do {
          lVar6 = FUN_004c1600(param_1,0x18,0,0);
          if (lVar6 == 0) {
            return 0;
          }
          iVar3 = FUN_004cd750(param_1);
          *piVar8 = iVar3;
          if ((u32 *)*piVar8 == (u32 *)0x0) {
            return 0;
          }
          if ((*(u32 *)*piVar8 & 2) == 0) {
            FUN_004cd940();
          }
          iVar9 = iVar9 + 1;
          piVar8 = piVar8 + 1;
        } while (iVar9 < (int)uStack_4);
      }
      lVar6 = FUN_004c1600(param_1,6,0,0);
      if (lVar6 == 0) {
        uVar5 = 0;
      }
      else {
        lVar6 = FUN_004bd260(param_1);
        iStack_40 = (int)lVar6;
        if (lVar6 == 0) {
          uVar5 = 0;
        }
        else {
          uVar10 = 4;
          uStack_8 = *(u32 *)(*piVar2 + 4);
          uStack_c = *(u32 *)(*piVar2 + 8);
          iStack_10 = *(int *)(*piVar2 + 0xc);
          if ((int)uStack_4 < 2) {
            if ((*(char *)(iStack_40 + 0x50) != '\x01') && (*(char *)(iStack_40 + 0x50) != '\x02'))
            {
              uVar10 = 0x9004;
            }
          }
          else {
            uVar10 = 0x8004;
          }
          FUN_004cdd50(*piVar2,uVar10,&uStack_8,&uStack_c,&iStack_10,&uStack_14);
          lVar6 = FUN_004ce0f0(uStack_8,uStack_c,iStack_10,uVar10 | uStack_14);
          if (lVar6 == 0) {
            iVar9 = 0;
            piVar8 = piVar2;
            if (0 < (int)uStack_4) {
              do {
                FUN_004cbeb0(*piVar8);
                iVar9 = iVar9 + 1;
                piVar8 = piVar8 + 1;
              } while (iVar9 < (int)uStack_4);
            }
            (*DAT_0096017c)(piVar2);
            uVar5 = 0;
          }
          else {
            iVar3 = (int)lVar6;
            iVar9 = *(int *)(iVar3 + 0xc);
            if ((*(int *)(*piVar2 + 4) != iVar9) ||
               (*(int *)(*piVar2 + 8) != *(int *)(iVar3 + 0x10))) {
              iVar3 = *(int *)(iVar3 + 0x10);
              if (iStack_10 == 8) {
                FUN_004cde90(lVar6);
                lVar6 = FUN_004ce0f0(iVar9,iVar3,0x20,uVar10 | 0x500);
                if (lVar6 == 0) {
                  lVar6 = FUN_004ce0f0(iVar9,iVar3,0x10,uVar10 | 0x100);
                }
              }
              iVar4 = FUN_004cdf80(lVar6);
              iVar11 = 0;
              piVar8 = piVar2;
              if (0 < iVar4) {
                do {
                  lVar7 = FUN_004cee30(*piVar8,iVar9,iVar3);
                  if (lVar7 == 0) {
                    return 0;
                  }
                  FUN_004cbeb0(*piVar8);
                  *piVar8 = (int)lVar7;
                  if (1 < iVar9) {
                    iVar9 = iVar9 >> 1;
                  }
                  if (1 < iVar3) {
                    iVar3 = iVar3 >> 1;
                  }
                  iVar11 = iVar11 + 1;
                  piVar8 = piVar8 + 1;
                } while (iVar11 < iVar4);
              }
            }
            iVar9 = (int)lVar6;
            if (1 < (int)uStack_4) {
              bVar1 = *(u8 *)(iVar9 + 0x23) & 0x10;
              *(u8 *)(iVar9 + 0x23) = *(u8 *)(iVar9 + 0x23) & ~bVar1;
            }
            iVar3 = FUN_004cdf80(lVar6);
            uVar10 = 0;
            piVar8 = piVar2;
            if (0 < iVar3) {
              do {
                if (uVar10 == uStack_4) break;
                lVar7 = FUN_004ce200(lVar6,uVar10 & 0xff,1);
                if (lVar7 == 0) {
                  return 0;
                }
                lVar7 = FUN_004cdce0(lVar6,*piVar8);
                if (lVar7 == 0) {
                  return 0;
                }
                lVar7 = FUN_004cde00(lVar6);
                if (lVar7 == 0) {
                  return 0;
                }
                FUN_004cbeb0(*piVar8);
                uVar10 = uVar10 + 1;
                piVar8 = piVar8 + 1;
              } while ((int)uVar10 < iVar3);
            }
            if (1 < (int)uStack_4) {
              *(u8 *)(iVar9 + 0x23) = *(u8 *)(iVar9 + 0x23) | bVar1;
            }
            if ((int)uVar10 < (int)uStack_4) {
              piVar8 = piVar2 + uVar10;
              do {
                FUN_004cbeb0(*piVar8);
                uVar10 = uVar10 + 1;
                piVar8 = piVar8 + 1;
              } while ((int)uVar10 < (int)uStack_4);
            }
            (*DAT_0096017c)(piVar2);
            FUN_004d0be0(iStack_40,lVar6);
            lVar6 = FUN_004c5a50(0x77e6d0,param_1,iStack_40);
            if (lVar6 == 0) {
              iStack_40 = 0;
            }
            else {
              lVar6 = FUN_004d11f0();
              if (lVar6 != 0) {
                FUN_004d1110(lVar6,iStack_40);
              }
            }
            if (iStack_40 == 0) {
              uVar5 = 0;
            }
            else {
              uVar5 = 1;
            }
          }
        }
      }
    }
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}
// FUN_004BDA10 NONMATCHING
u32 FUN_004bda10(u64 param_1)

{
  u32 uVar1;
  long lVar2;
  u64 uVar3;
  u32 uVar4;
  u16 uStack_8;
  short sStack_6;
  u32 uStack_4;
  
  uVar1 = FUN_004c5250(param_1,&uStack_8,4);
  if (uVar1 < 4) {
    uStack_4 = 0;
  }
  else {
    lVar2 = FUN_004d0c30();
    uStack_4 = (u32)lVar2;
    if (lVar2 == 0) {
      uStack_4 = 0;
    }
    else if (sStack_6 == 0) {
      uVar4 = 0;
      if (uStack_8 != 0) {
        do {
          FUN_004bccd0(param_1,&uStack_4);
          uVar4 = uVar4 + 1;
        } while (uVar4 < uStack_8);
      }
    }
    else {
      uVar3 = FUN_004d11f0();
      FUN_004d11d0(uStack_4);
      uVar4 = 0;
      if (uStack_8 != 0) {
        do {
          lVar2 = FUN_004bd4e0(param_1);
          if (lVar2 == 0) {
            FUN_004d11d0(uVar3);
            return 0;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < uStack_8);
      }
      FUN_004d11d0(uVar3);
    }
  }
  return uStack_4;
}
// FUN_004BDBB0 NONMATCHING
u64 FUN_004bdbb0(u64 param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  pfVar1 = (float *)param_1;
  fVar4 = param_2[8];
  fVar7 = param_2[2];
  fVar5 = SQRT((param_2[5] - (param_2[10] + *param_2)) + 1.0);
  fVar2 = param_2[6];
  fVar3 = param_2[9];
  fVar6 = 0.5 / fVar5;
  pfVar1[1] = fVar5 * 0.5;
  pfVar1[3] = fVar6 * (fVar4 - fVar7);
  pfVar1[2] = fVar6 * (fVar2 + fVar3);
  *pfVar1 = fVar6 * (param_2[4] + param_2[1]);
  return param_1;
}
// FUN_004BDC30 NONMATCHING
u64 FUN_004bdc30(u64 param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  pfVar1 = (float *)param_1;
  fVar4 = param_2[1];
  fVar7 = param_2[4];
  fVar5 = SQRT((param_2[10] - (*param_2 + param_2[5])) + 1.0);
  fVar2 = param_2[8];
  fVar3 = param_2[2];
  fVar6 = 0.5 / fVar5;
  pfVar1[2] = fVar5 * 0.5;
  pfVar1[3] = fVar6 * (fVar4 - fVar7);
  *pfVar1 = fVar6 * (fVar2 + fVar3);
  pfVar1[1] = fVar6 * (param_2[9] + param_2[6]);
  return param_1;
}
