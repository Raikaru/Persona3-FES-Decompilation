#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))
#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif
typedef u8 bool;
typedef struct {
  short f0;
  short f1;
  short f2;
  short f3;
} MtEvtHalf4;

typedef struct {
  f32 x;
  f32 y;
  f32 z;
} MtEvtVec3;

typedef struct {
  f32 x;
  f32 y;
  f32 z;
  f32 w;
} MtEvtVec4;

extern u32 LAB_00391290;
extern u32 DAT_007cca68;
extern u32 DAT_007cca6c;
extern u32 DAT_006a0bf8;
extern u32 DAT_006a0c00;
#pragma alias DAT_006a0bf8_vec_abs DAT_006a0bf8
extern MtEvtVec3 DAT_006a0bf8_vec_abs[];
extern u32 LAB_00392bb0;



/* Region 0x390000-0x3CFFFF recovered prototypes */
void FUN_0038dad0(u32 param_1,int param_2,int param_3);
void FUN_0038e660(int param_1,int param_2,int param_3);
u32 FUN_0038e860(u32 param_1,u32 param_2);
void FUN_0038f0f0(u32 param_1);
void FUN_0038f440(u8 *param_1,void *param_2,int param_3);
void FUN_0038f8c0(int param_1,u64 param_2,int param_3,u16 param_4);
#pragma alias FUN_00361350_direct FUN_00361350
extern u32 FUN_00361350_direct(int param_1,u16 param_2,u64 param_3);
#pragma alias FUN_0038f440_direct FUN_0038f440
extern void FUN_0038f440_direct(u8 *param_1,void *param_2,int param_3);
#pragma alias FUN_00391080_wide FUN_00391080
extern void FUN_00391080_wide(u64 param_1,u64 param_2);
#pragma alias FUN_005225a8_evt FUN_005225a8
extern void FUN_005225a8_evt(const char *format,...);
#pragma alias FUN_004c0420_evt FUN_004c0420
extern void FUN_004c0420_evt(void *data,int size,int count,int arg);
#pragma alias FUN_00361ca0_evt FUN_00361ca0
extern u32 FUN_00361ca0_evt(int param_1,u64 param_2);
#pragma alias FUN_00530da0_evt FUN_00530da0
extern u32 FUN_00530da0_evt(f32 param_1);
void FUN_0038fa10(int param_1,u32 param_2);
void FUN_0038ffb0(int param_1,int param_2);
void FUN_003902c0(int param_1,int param_2);
void FUN_003905f0(int param_1,int param_2);
void FUN_00390920(int param_1,int param_2);
void FUN_00390c90(int param_1,int param_2);
void FUN_00390ef0(int param_1,int param_2);
void FUN_00391080(u32 param_1,u32 param_2);
u32 FUN_003912f0(u32 param_1,u32 param_2);


/* Region call-cast macros */
#define FUN_0038dad0(...) ((void (*)(...))FUN_0038dad0)(__VA_ARGS__)
#define FUN_0038e660(...) ((void (*)(...))FUN_0038e660)(__VA_ARGS__)
#define FUN_0038e860(...) ((u32 (*)(...))FUN_0038e860)(__VA_ARGS__)
#define FUN_0038f0f0(...) ((void (*)(...))FUN_0038f0f0)(__VA_ARGS__)
#define FUN_0038f440(...) ((void (*)(...))FUN_0038f440)(__VA_ARGS__)
#define FUN_0038f8c0(...) ((void (*)(...))FUN_0038f8c0)(__VA_ARGS__)
#define FUN_0038fa10(...) ((void (*)(...))FUN_0038fa10)(__VA_ARGS__)
#define FUN_0038ffb0(...) ((void (*)(...))FUN_0038ffb0)(__VA_ARGS__)
#define FUN_003902c0(...) ((void (*)(...))FUN_003902c0)(__VA_ARGS__)
#define FUN_003905f0(...) ((void (*)(...))FUN_003905f0)(__VA_ARGS__)
#define FUN_00390920(...) ((void (*)(...))FUN_00390920)(__VA_ARGS__)
#define FUN_00390c90(...) ((void (*)(...))FUN_00390c90)(__VA_ARGS__)
#define FUN_00390ef0(...) ((void (*)(...))FUN_00390ef0)(__VA_ARGS__)
#define FUN_00391080(...) ((void (*)(...))FUN_00391080)(__VA_ARGS__)
#define FUN_003912f0(...) ((u32 (*)(...))FUN_003912f0)(__VA_ARGS__)

#undef FUN_0038dad0
// FUN_0038DAD0 NONMATCHING


void FUN_0038dad0(u32 param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  long lVar5;

  long lVar6;

  long lVar7;

  int *piVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  int iVar13;

  int iVar14;

  int iVar15;

  int iVar16;

  int iStack_b0;

  int iStack_a0;

  int iStack_90;

  int iStack_80;

  int iStack_70;

  int iStack_60;

  int iStack_50;

  int iStack_30;

  int iStack_2c;

  int iStack_28;

  int iStack_24;

  u8 uStack_20;

  u8 uStack_1f;

  u16 uStack_1e;

  int iStack_1c;

  u8 uStack_18;

  u8 uStack_17;

  u8 uStack_16;

  char cStack_15;

  u32 uStack_14;

  int iStack_10;

  u32 uStack_c;

  u32 uStack_8;

  u32 uStack_4;
  volatile /* Removing this qualifier worsens FUN_0038dad0 (NONMATCHING nd1389 -> NONMATCHING nd1581, size 2420 -> 2064) - measured W170. */ u64 aSize[15];

  

  iVar12 = 0;

  iStack_50 = 0;

  if (param_2 == 1) {

    FUN_0019d3f0("mt_evtLoadSave.c",0x1fe);

  }

  else {

    iVar2 = FUN_00361ee0(0,param_3);

    iVar3 = FUN_00361ee0(1,param_3);

    iVar4 = FUN_00361f60(param_2,param_3);
    aSize[1] = iVar4 * 0x3c;

    iVar11 = (int)param_3;

    iVar1 = *(int *)(iVar11 + 0x50);
    aSize[0] = iVar1 * 0x20;

    lVar5 = FUN_00361ee0(2,param_3);
    aSize[2] = lVar5 * 0x10;

    iVar15 = 0;

    for (piVar8 = *(int **)(iVar11 + 0x84); piVar8 != (int *)0x0; piVar8 = (int *)piVar8[0x25]) {

      if (*piVar8 == 10) {

        for (iVar16 = piVar8[0x1b]; iVar16 != 0; iVar16 = *(int *)(iVar16 + 0x4c)) {

          *(short *)(iVar16 + 0x1a) = (short)iVar15;

          iVar15 = iVar15 + 1;

        }

      }

    }
    aSize[3] = iVar15 * 0x30;

    iStack_60 = 0;

    for (piVar8 = *(int **)(iVar11 + 0x84); piVar8 != (int *)0x0; piVar8 = (int *)piVar8[0x25]) {

      if (*piVar8 == 0xb) {

        for (iVar16 = piVar8[0x1b]; iVar16 != 0; iVar16 = *(int *)(iVar16 + 0x4c)) {

          *(short *)(iVar16 + 2) = (short)iStack_60;

          iStack_60 = iStack_60 + 1;

        }

      }

    }
    aSize[4] = iStack_60 * 0x20;

    iVar16 = 0;

    for (piVar8 = *(int **)(iVar11 + 0x84); piVar8 != (int *)0x0; piVar8 = (int *)piVar8[0x25]) {

      if (*piVar8 == 0xd) {

        for (iVar10 = piVar8[0x1b]; iVar10 != 0; iVar10 = *(int *)(iVar10 + 0x4c)) {

          *(short *)(iVar10 + 0x12) = (short)iVar16;

          iVar16 = iVar16 + 1;

        }

      }

    }
    aSize[5] = iVar16 * 0x28;

    iVar10 = 0;

    for (piVar8 = *(int **)(iVar11 + 0x84); piVar8 != (int *)0x0; piVar8 = (int *)piVar8[0x25]) {

      if (*piVar8 == 0xe) {

        for (iVar13 = piVar8[0x1b]; iVar13 != 0; iVar13 = *(int *)(iVar13 + 0x4c)) {

          *(short *)(iVar13 + 0x12) = (short)iVar10;

          iVar10 = iVar10 + 1;

        }

      }

    }
    aSize[6] = iVar10 * 0x2c;

    iVar13 = 0;

    for (piVar8 = *(int **)(iVar11 + 0x84); piVar8 != (int *)0x0; piVar8 = (int *)piVar8[0x25]) {

      if (*piVar8 == 0xf) {

        for (iVar14 = piVar8[0x1b]; iVar14 != 0; iVar14 = *(int *)(iVar14 + 0x4c)) {

          *(short *)(iVar14 + 0x12) = (short)iVar13;

          iVar13 = iVar13 + 1;

        }

      }

    }
    aSize[7] = iVar13 * 0x2c;

    iStack_70 = 0;

    for (piVar8 = *(int **)(iVar11 + 0x84); piVar8 != (int *)0x0; piVar8 = (int *)piVar8[0x25]) {

      if (*piVar8 == 0x10) {

        for (iVar14 = piVar8[0x1b]; iVar14 != 0; iVar14 = *(int *)(iVar14 + 0x4c)) {

          *(short *)(iVar14 + 0x12) = (short)iStack_70;

          iStack_70 = iStack_70 + 1;

        }

      }

    }
    aSize[8] = iStack_70 * 0x18;

    iStack_80 = 0;

    for (piVar8 = *(int **)(iVar11 + 0x84); piVar8 != (int *)0x0; piVar8 = (int *)piVar8[0x25]) {

      if (*piVar8 == 0x11) {

        for (iVar14 = piVar8[0x1b]; iVar14 != 0; iVar14 = *(int *)(iVar14 + 0x4c)) {

          *(short *)(iVar14 + 0x12) = (short)iStack_80;

          iStack_80 = iStack_80 + 1;

        }

      }

    }
    aSize[9] = iStack_80 * 0x24;

    iVar14 = 0;

    for (piVar8 = *(int **)(iVar11 + 0x84); piVar8 != (int *)0x0; piVar8 = (int *)piVar8[0x25]) {

      if (*piVar8 == 0x17) {

        for (iVar9 = piVar8[0x1b]; iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x4c)) {

          *(short *)(iVar9 + 0x12) = (short)iVar14;

          iVar14 = iVar14 + 1;

        }

      }

    }
    aSize[10] = iVar14 * 0x2c;

    iStack_90 = 0;

    for (piVar8 = *(int **)(iVar11 + 0x84); piVar8 != (int *)0x0; piVar8 = (int *)piVar8[0x25]) {

      if (*piVar8 == 0x1b) {

        for (iVar9 = piVar8[0x1b]; iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x4c)) {

          *(short *)(iVar9 + 0x12) = (short)iStack_90;

          iStack_90 = iStack_90 + 1;

        }

      }

    }
    aSize[12] = iStack_90 * 0x28;

    lVar6 = FUN_00361f20(param_3);
    aSize[11] = lVar6 * 0x14;

    iStack_a0 = 0;

    for (piVar8 = *(int **)(iVar11 + 0x84); piVar8 != (int *)0x0; piVar8 = (int *)piVar8[0x25]) {

      if (*piVar8 == 0x19) {

        for (iVar9 = piVar8[0x1b]; iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x4c)) {

          *(short *)(iVar9 + 0x12) = (short)iStack_a0;

          iStack_a0 = iStack_a0 + 1;

        }

      }

    }
    aSize[13] = iStack_a0 * 0x40;

    iVar9 = 0;

    for (iStack_b0 = *(int *)(iVar11 + 0x84); iStack_b0 != 0; iStack_b0 = *(int *)(iStack_b0 + 0x94)

        ) {

      for (iVar11 = *(int *)(iStack_b0 + 0x6c); iVar11 != 0; iVar11 = *(int *)(iVar11 + 0x4c)) {

        lVar7 = FUN_0038da10((u16 *)iVar11);

        if (lVar7 != 0) {

          *(int *)(iVar11 + 0x3c) = iVar9;

          iVar9 = iVar9 + 1;

        }

      }

    }
    aSize[14] = iVar9 * 0x130;

    FUN_005225a8(0x6a0ae0,iVar9);

    iStack_1c = 0x20;

    if (param_2 == 3) {

      iVar12 = 1;

      iStack_50 = 0x30;

      iStack_1c = iVar4 * 0x3c + 0x30;

    }

    else {

      iVar11 = 2;

      if (param_2 == 2) {

        if (0 < iVar1) {

          iVar11 = 3;

        }

        if (0 < lVar5) {

          iVar11 = iVar11 + 1;

        }

        if (0 < iVar15) {

          iVar11 = iVar11 + 1;

        }

        if (0 < iStack_60) {

          iVar11 = iVar11 + 1;

        }

        if (0 < iVar16) {

          iVar11 = iVar11 + 1;

        }

        if (0 < iVar10) {

          iVar11 = iVar11 + 1;

        }

        if (0 < iVar13) {

          iVar11 = iVar11 + 1;

        }

        if (0 < iStack_70) {

          iVar11 = iVar11 + 1;

        }

        if (0 < iStack_80) {

          iVar11 = iVar11 + 1;

        }

        if (0 < iVar14) {

          iVar11 = iVar11 + 1;

        }

        if (0 < iStack_90) {

          iVar11 = iVar11 + 1;

        }

        if (0 < lVar6) {

          iVar11 = iVar11 + 1;

        }

        if (0 < iStack_a0) {

          iVar11 = iVar11 + 1;

        }

        iVar12 = iVar11;

        if (0 < iVar9) {

          iVar12 = iVar11 + 1;

        }

        iStack_50 = iVar12 * 0x10 + 0x20;

        iStack_1c = iStack_50 + (int)aSize[0] + 0x24 + (int)aSize[1] + (int)aSize[2] +

                    (int)aSize[3] + (int)aSize[4] + (int)aSize[5] + (int)aSize[6] + (int)aSize[7]

                    + (int)aSize[8] + (int)aSize[9] + (int)aSize[10] + (int)aSize[11] +

                    (int)aSize[12] + (int)aSize[13] + (int)aSize[14];

      }

    }

    uStack_20 = 0;

    uStack_1f = 0;

    uStack_1e = 0;

    uStack_18 = 0x50;

    uStack_17 = 0x4d;

    uStack_16 = 0x44;

    cStack_15 = (char)param_2 + '0';

    uStack_14 = 0;

    uStack_c = 0xc;

    uStack_8 = 0;

    uStack_4 = 0;

    iStack_10 = iVar12;

    FUN_004c0420(&uStack_20,0x20,1,param_1);

    for (iVar12 = 0; iVar12 < 0x1c; iVar12 = iVar12 + 1) {

      iStack_2c = 0;

      iStack_28 = 0;

      iStack_24 = 0;

      iStack_30 = iVar12;

      switch(iVar12) {

      case 0:

        if (param_2 == 2) {

          iStack_2c = 0x24;

          iStack_28 = 1;

        }

        break;

      case 1:

        if ((0 < iVar1) && (param_2 != 3)) {

          iStack_2c = 0x20;

          iStack_28 = iVar1;

        }

        break;

      case 2:

        if (param_2 == 1) {

          iStack_2c = 0x10;

          iStack_28 = iVar2;

        }

        break;

      case 3:

        if (param_2 == 1) {

          iStack_2c = 0x20;

          iStack_28 = iVar3;

        }

        break;

      case 4:

        if ((int)param_2 - 2U < 2) {

          iStack_2c = 0x3c;

          iStack_28 = iVar4;

        }

        break;

      case 5:

        if ((0 < lVar5) && (param_2 == 2)) {

          iStack_2c = 0x10;

          iStack_28 = (int)lVar5;

        }

        break;

      case 6:

      case 7:

      case 8:

      case 9:

      case 10:

      case 0xb:

      case 0xc:

      case 0x16:

      case 0x17:

      case 0x1b:

        break;

      case 0xd:

        if ((0 < iVar15) && (param_2 == 2)) {

          iStack_2c = 0x30;

          iStack_28 = iVar15;

        }

        break;

      case 0xe:

        if ((0 < iStack_60) && (param_2 == 2)) {

          iStack_2c = 0x20;

          iStack_28 = iStack_60;

        }

        break;

      case 0xf:

        if ((0 < iVar16) && (param_2 == 2)) {

          iStack_2c = 0x28;

          iStack_28 = iVar16;

        }

        break;

      case 0x10:

        if ((0 < iVar10) && (param_2 == 2)) {

          iStack_2c = 0x2c;

          iStack_28 = iVar10;

        }

        break;

      case 0x11:

        if ((0 < iVar13) && (param_2 == 2)) {

          iStack_2c = 0x2c;

          iStack_28 = iVar13;

        }

        break;

      case 0x12:

        if ((0 < iStack_70) && (param_2 == 2)) {

          iStack_2c = 0x18;

          iStack_28 = iStack_70;

        }

        break;

      case 0x13:

        if ((0 < iStack_80) && (param_2 == 2)) {

          iStack_2c = 0x24;

          iStack_28 = iStack_80;

        }

        break;

      case 0x14:

        if ((0 < iVar14) && (param_2 == 2)) {

          iStack_2c = 0x2c;

          iStack_28 = iVar14;

        }

        break;

      case 0x15:

        if ((0 < lVar6) && (param_2 == 2)) {

          iStack_2c = 0x14;

          iStack_28 = (int)lVar6;

        }

        break;

      case 0x18:

        if ((0 < iStack_90) && (param_2 == 2)) {

          iStack_2c = 0x28;

          iStack_28 = iStack_90;

        }

        break;

      case 0x19:

        if ((0 < iStack_a0) && (param_2 == 2)) {

          iStack_2c = 0x40;

          iStack_28 = iStack_a0;

        }

        break;

      case 0x1a:

        if ((0 < iVar9) && (param_2 == 2)) {

          iStack_2c = 0x130;

          iStack_28 = iVar9;

        }

        break;

      default:

        FUN_0019d3f0("mt_evtLoadSave.c",0x324);

      }

      if ((iStack_2c != 0) || (iStack_28 != 0)) {

        iStack_24 = iStack_50;

        iStack_50 = iStack_50 + iStack_2c * iStack_28;

        FUN_004c0420(&iStack_30,0x10,1,param_1);

      }

    }

  }

  return;

}


#define FUN_0038dad0(...) ((void (*)(...))FUN_0038dad0)(__VA_ARGS__)
#undef FUN_0038e660
// FUN_0038E660 NONMATCHING


void FUN_0038e660(int param_1,int param_2,int param_3)
{
  extern u8 DAT_006a0b50[];
  int iVar1;
  int iVar2;
  int iVar4;
  int *piVar3;
  s16 *psVar2;
  s16 c3;
  s16 c2;
  s16 c1;
  s16 c0;
  struct {
    u16 uStack_40;
    u16 sStack_3e;
    u16 sStack_3c;
    u16 uStack_3a;
    u16 uStack_38;
    volatile /* Removing this function's qualifier batch worsens FUN_0038e660 (NONMATCHING nd15 -> NONMATCHING nd48, size 504 -> 504) - measured W170. */ s16 uStack_36;
    s16 sStack_34;
    s16 sStack_32;
    s16 sStack_30;
    s16 sStack_2e;
    f32 auStack_2c[10];
  } stack;

  piVar3 = *(int **)(param_3 + 0x84);
  while (piVar3 != (int *)0x0) {
    psVar2 = (s16 *)piVar3[0x1b];
    if (param_2 == 2) {
      if (*piVar3 != 5) {
        if (*piVar3 == 0x13) {
        }
        else {
          goto process_node;
        }
      }
    }
    else if ((param_2 == 3) && (*piVar3 != 5)) {
      if (*piVar3 == 0x13) {
        goto process_node;
      }
    }
    else {
process_node:
    for (; psVar2 != (s16 *)0x0; psVar2 = *(s16 **)(psVar2 + 0x26)) {
      stack.uStack_40 = (u16)*piVar3;
      stack.sStack_3e = *(u16 *)(psVar2 + 0);
      stack.sStack_3c = *(u16 *)(psVar2 + 1);
      stack.uStack_3a = (u16)*(u32 *)(psVar2 + 2);
      stack.uStack_38 = *(volatile /* Removing this function's qualifier batch worsens FUN_0038e660 (NONMATCHING nd15 -> NONMATCHING nd48, size 504 -> 504) - measured W170. */ u16 *)((u8 *)piVar3 + 0xc);
      stack.uStack_36 = (s16)*(u32 *)(psVar2 + 0x1e);
      c0 = ((volatile /* Removing this function's qualifier batch worsens FUN_0038e660 (NONMATCHING nd15 -> NONMATCHING nd48, size 504 -> 504) - measured W170. */ s16 *)psVar2)[4];
      c1 = ((volatile /* Removing this function's qualifier batch worsens FUN_0038e660 (NONMATCHING nd15 -> NONMATCHING nd48, size 504 -> 504) - measured W170. */ s16 *)psVar2)[5];
      c2 = ((volatile /* Removing this function's qualifier batch worsens FUN_0038e660 (NONMATCHING nd15 -> NONMATCHING nd48, size 504 -> 504) - measured W170. */ s16 *)psVar2)[6];
      c3 = ((volatile /* Removing this function's qualifier batch worsens FUN_0038e660 (NONMATCHING nd15 -> NONMATCHING nd48, size 504 -> 504) - measured W170. */ s16 *)psVar2)[7];
      (stack.sStack_34 = c0, stack.sStack_32 = c1, stack.sStack_30 = c2, stack.sStack_2e = c3);
      FUN_005225a8_evt((const char *)DAT_006a0b50,*(u16 *)((u8 *)piVar3 + 0xc),stack.uStack_36);
      for (iVar1 = 0; iVar1 < 10; iVar1 = iVar1 + 1) {
        iVar4 = (int)psVar2 + iVar1 * 4;
        iVar2 = (int)&stack.auStack_2c[iVar1];
        *(f32 *)iVar2 = *(f32 *)(iVar4 + 0x10);
      }
      switch (*piVar3) {
      case 8:
        if ((psVar2[8] == 0) && (psVar2[9] == 0)) {
          stack.sStack_3c = 0;
        }
        else if (*(u16 **)(psVar2 + 0x26) != (u16 *)0x0) {
          stack.sStack_3c = **(u16 **)(psVar2 + 0x26) - *(u16 *)psVar2;
        }
        else {
          iVar2 = *(int *)(param_3 + 0x14);
          stack.sStack_3c = iVar2 - *(u16 *)psVar2;
        }
        break;
      default:
        break;
      }
      FUN_004c0420_evt(&stack,0x3c,1,param_1);
    }
    }
next_node:
    piVar3 = (int *)piVar3[0x25];
  }
  return;
}


#define FUN_0038e660(...) ((void (*)(...))FUN_0038e660)(__VA_ARGS__)
#undef FUN_0038e860
// FUN_0038E860 NONMATCHING


u32 FUN_0038e860(u32 param_1,u32 param_2)



{

  int iVar1;

  long lVar2;

  long lVar3;

  long lVar4;

  int iVar5;

  int *piVar6;

  int iVar7;

  int *piVar8;

  int iVar9;

  u32 *puVar10;

  u8 uStack_120;

  u8 uStack_11f;

  u16 uStack_11e;

  u16 uStack_11c;

  u8 uStack_11a;

  u8 uStack_119;

  u16 uStack_118;

  int aiStack_100 [8];

  u32 uStack_e0;

  u32 uStack_dc;

  u8 auStack_c0 [64];

  u8 auStack_80 [64];

  u8 auStack_40 [64];

  

  iVar7 = (int)param_2;

  for (iVar9 = *(int *)(iVar7 + 0x84); iVar9 != 0; iVar9 = *(int *)(iVar9 + 0x94)) {

  }

  if (param_1 != 0) {

    FUN_00394e70(DAT_007cca68,DAT_007cca6c,auStack_c0,auStack_40,auStack_80);

    lVar2 = FUN_004c0240(auStack_40,0x7cd450);

    lVar3 = FUN_004c0240(auStack_80,0x7cd450);

    if ((lVar2 == 0) || (lVar3 == 0)) {

      FUN_0019d3f0("mt_evtLoadSave.c",0x536);

    }

    FUN_0038dad0(lVar2,2,param_2);

    for (iVar9 = 0; iVar9 < 0x1c; iVar9 = iVar9 + 1) {

      if (iVar9 == 0x1a) {

        for (iVar5 = *(int *)(iVar7 + 0x84); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x94)) {

          for (iVar1 = *(int *)(iVar5 + 0x6c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x4c)) {

            lVar4 = FUN_0038da10((u16 *)iVar1);

            if (lVar4 != 0) {

              FUN_004c0420(*(u32 *)(iVar1 + 0x40),0x130,1,lVar2);

            }

          }

        }

        FUN_005225a8(0x6a0bb0);

      }

      else if (iVar9 == 0x19) {

        for (piVar6 = *(int **)(iVar7 + 0x84); piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x25]) {

          if (*piVar6 == 0x19) {

            for (iVar5 = piVar6[0x1b]; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x4c)) {

              FUN_004c0420(*(u32 *)(iVar5 + 0x48),0x40,1,lVar2);

            }

          }

        }

        FUN_005225a8(0x6a0ba0);

      }

      else if (iVar9 == 0x15) {

        for (puVar10 = *(u32 **)(iVar7 + 0x84); puVar10 != (u32 *)0x0;

            puVar10 = (u32 *)puVar10[0x25]) {

          FUN_00521408(&uStack_120,0,0x14);

          uStack_120 = (u8)*puVar10;

          uStack_11f = (u8)puVar10[1];

          uStack_11e = (u16)puVar10[2];

          uStack_11c = *(u16 *)(puVar10 + 8);

          uStack_11a = *(u8 *)((int)puVar10 + 0x22);

          uStack_119 = *(u8 *)((int)puVar10 + 0x23);

          uStack_118 = *(u16 *)(puVar10 + 9);

          FUN_004c0420(&uStack_120,0x14,1,lVar2);

        }

        FUN_005225a8(0x6a0b80);

      }

      else if (iVar9 == 0x18) {

        for (piVar6 = *(int **)(iVar7 + 0x84); piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x25]) {

          if (*piVar6 == 0x1b) {

            for (iVar5 = piVar6[0x1b]; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x4c)) {

              FUN_004c0420(*(u32 *)(iVar5 + 0x48),0x28,1,lVar2);

            }

          }

        }

      }

      else if (iVar9 == 0x14) {

        for (piVar6 = *(int **)(iVar7 + 0x84); piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x25]) {

          if (*piVar6 == 0x17) {

            for (iVar5 = piVar6[0x1b]; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x4c)) {

              FUN_004c0420(*(u32 *)(iVar5 + 0x48),0x2c,1,lVar2);

            }

          }

        }

      }

      else if (iVar9 == 0x13) {

        for (piVar6 = *(int **)(iVar7 + 0x84); piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x25]) {

          if (*piVar6 == 0x11) {

            for (iVar5 = piVar6[0x1b]; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x4c)) {

              FUN_004c0420(*(u32 *)(iVar5 + 0x48),0x24,1,lVar2);

            }

          }

        }

      }

      else if (iVar9 == 0x12) {

        for (piVar6 = *(int **)(iVar7 + 0x84); piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x25]) {

          if (*piVar6 == 0x10) {

            for (iVar5 = piVar6[0x1b]; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x4c)) {

              FUN_004c0420(*(u32 *)(iVar5 + 0x48),0x18,1,lVar2);

            }

          }

        }

      }

      else if (iVar9 == 0x11) {

        for (piVar6 = *(int **)(iVar7 + 0x84); piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x25]) {

          if (*piVar6 == 0xf) {

            for (iVar5 = piVar6[0x1b]; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x4c)) {

              FUN_004c0420(*(u32 *)(iVar5 + 0x48),0x2c,1,lVar2);

            }

          }

        }

      }

      else if (iVar9 == 0x10) {

        for (piVar6 = *(int **)(iVar7 + 0x84); piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x25]) {

          if (*piVar6 == 0xe) {

            for (iVar5 = piVar6[0x1b]; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x4c)) {

              FUN_004c0420(*(u32 *)(iVar5 + 0x48),0x2c,1,lVar2);

            }

          }

        }

      }

      else if (iVar9 == 0xf) {

        for (piVar6 = *(int **)(iVar7 + 0x84); piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x25]) {

          if (*piVar6 == 0xd) {

            for (iVar5 = piVar6[0x1b]; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x4c)) {

              FUN_004c0420(*(u32 *)(iVar5 + 0x48),0x28,1,lVar2);

            }

          }

        }

      }

      else if (iVar9 == 0xe) {

        for (piVar6 = *(int **)(iVar7 + 0x84); piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x25]) {

          if (*piVar6 == 0xb) {

            for (iVar5 = piVar6[0x1b]; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x4c)) {

              FUN_004c0420(*(u32 *)(iVar5 + 0x48),0x20,1,lVar2);

            }

          }

        }

      }

      else if (iVar9 == 0xd) {

        for (piVar6 = *(int **)(iVar7 + 0x84); piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x25]) {

          if (*piVar6 == 10) {

            for (iVar5 = piVar6[0x1b]; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x4c)) {

              FUN_004c0420(*(u32 *)(iVar5 + 0x48),0x30,1,lVar2);

            }

          }

        }

      }

      else if (iVar9 == 5) {

        for (piVar6 = *(int **)(iVar7 + 0x84); piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x25]) {

          if (*piVar6 == 2) {

            aiStack_100[0] = piVar6[2];

            aiStack_100[1] = 0;

            aiStack_100[2] = 0;

            aiStack_100[3] = 0;

            FUN_004c0420(aiStack_100,0x10,1,lVar2);

          }

        }

      }

      else if (iVar9 == 4) {

        FUN_0038e660(lVar2,2,param_2);

      }

      else if (iVar9 == 1) {

        for (iVar5 = 0; iVar5 < *(int *)(iVar7 + 0x50); iVar5 = iVar5 + 1) {

          FUN_004c0420(iVar7 + iVar5 * 0x20 + 0x54,0x20,1,lVar2);

        }

      }

      else if (iVar9 == 0) {

        piVar8 = (int *)(iVar7 + 0x2c);

        piVar6 = aiStack_100 + 4;

        iVar5 = 9;

        do {

          iVar1 = *piVar8;

          piVar8 = piVar8 + 1;

          iVar5 = iVar5 + -1;

          *piVar6 = iVar1;

          piVar6 = piVar6 + 1;

        } while (0 < iVar5);

        aiStack_100[4] = *(u32 *)(iVar7 + 0x10);

        aiStack_100[5] = *(u32 *)(iVar7 + 0x14);

        aiStack_100[6] = *(u32 *)(iVar7 + 0xc);

        aiStack_100[7] = *(u32 *)(iVar7 + 0x2a4);

        FUN_005225a8(0x6a0b20,uStack_e0,uStack_dc);

        FUN_004c0420(aiStack_100 + 4,0x24,1,lVar2);

      }

    }

    if (lVar2 != 0) {

      FUN_004c0370(lVar2);

    }

    FUN_0038dad0(lVar3,3,param_2);

    for (iVar9 = 0; iVar9 < 0x1c; iVar9 = iVar9 + 1) {

      if (iVar9 == 4) {

        FUN_0038e660(lVar3,3,param_2);

      }

    }

    if (lVar3 != 0) {

      FUN_004c0370(lVar3);

    }

    FUN_005225a8(0x6a0bc0);

  }

  return 1;

}


#define FUN_0038e860(...) ((u32 (*)(...))FUN_0038e860)(__VA_ARGS__)
#undef FUN_0038f0f0
// FUN_0038F0F0 NONMATCHING



void FUN_0038f0f0(u32 param_1)

{

  u8 uVar1;

  u8 uVar2;

  u8 uVar3;

  u8 *puVar4;

  int iVar5;

  u16 *puVar6;

  int iVar7;

  u32 lVar8;
  u32 lVar9;
  u32 finalData;

  u32 uVar10;

  u32 uVar11;

  u32 uVar12;

  u32 *puVar13;

  u32 *puVar14;

  int iVar15;
  int copyCount;

  u32 uVar16;

  u32 uVar17;

  u32 uVar18;

  

  lVar8 = FUN_003b5d00();

  if (lVar8 != 0) {

    lVar9 = FUN_003b5d10(0x400);

    if (lVar9 != 0) {

      uVar10 = FUN_00361ca0(1,param_1);

      FUN_00361d60(uVar10,0x400,lVar9);

      iVar5 = (int)uVar10;

      *(u32 *)(iVar5 + 8) = 0xffffffff;

      *(u32 *)(iVar5 + 0x14) = 0;

      iVar15 = (int)lVar9;

      *(MtEvtVec3 *)(iVar5 + 0x3c) = *(MtEvtVec3 *)(iVar15 + 4);
      *(MtEvtVec3 *)(iVar5 + 0x48) = *(MtEvtVec3 *)(iVar15 + 0x10);
      uVar10 = FUN_00530da0_evt(((MtEvtVec3 *)(iVar15 + 4))->x);
      uVar11 = FUN_00530da0_evt(((MtEvtVec3 *)(iVar15 + 4))->y);
      uVar12 = FUN_00530da0_evt(((MtEvtVec3 *)(iVar15 + 4))->z);

      FUN_005225a8(0x6a0bd0,uVar10,uVar11,uVar12);

      puVar4 = (u8 *)FUN_00318b00(*(u32 *)(iVar15 + 0x128));

      uVar1 = puVar4[1];

      uVar2 = puVar4[2];

      uVar3 = puVar4[3];

      *(u8 *)(iVar5 + 0x54) = *puVar4;

      *(u8 *)(iVar5 + 0x55) = uVar1;

      *(u8 *)(iVar5 + 0x56) = uVar2;

      *(u8 *)(iVar5 + 0x57) = uVar3;

    }

    else {

      uVar10 = FUN_00361ca0(1,param_1);

      FUN_00361d60(uVar10,0x400,0);

    }

    iVar5 = FUN_003b5550(lVar8,3);

    puVar6 = (u16 *)FUN_003b5430(lVar8,3);

    FUN_005225a8(0x6a0be0,iVar5);

    for (iVar15 = 0; iVar15 < iVar5; iVar15 = iVar15 + 1) {

      FUN_0038d910(puVar6);

      iVar7 = FUN_00361dd0(1,param_1,*puVar6,(u32)puVar6);

      *(u32 *)(iVar7 + 8) = 0xffffffff;

      *(u32 *)(iVar7 + 0x14) = 0;

      *(MtEvtVec3 *)(iVar7 + 0x3c) = *(MtEvtVec3 *)(puVar6 + 2);
      *(MtEvtVec3 *)(iVar7 + 0x48) = *(MtEvtVec3 *)(puVar6 + 8);
      uVar10 = FUN_00530da0_evt(((MtEvtVec3 *)(puVar6 + 2))->x);
      uVar11 = FUN_00530da0_evt(((MtEvtVec3 *)(puVar6 + 2))->y);
      uVar12 = FUN_00530da0_evt(((MtEvtVec3 *)(puVar6 + 2))->z);

      FUN_005225a8(0x6a0bd0,uVar10,uVar11,uVar12);

      puVar4 = (u8 *)FUN_00318b00(*(u32 *)(puVar6 + 0x94));

      uVar1 = puVar4[1];

      uVar2 = puVar4[2];

      uVar3 = puVar4[3];

      *(u8 *)(iVar7 + 0x54) = *puVar4;

      *(u8 *)(iVar7 + 0x55) = uVar1;

      *(u8 *)(iVar7 + 0x56) = uVar2;

      *(u8 *)(iVar7 + 0x57) = uVar3;

      puVar6 = *(u16 **)(puVar6 + 0x7c);

    }

    finalData = FUN_003b5430(lVar8,5);

    if (finalData != 0) {

      iVar5 = (int)finalData;

      *(MtEvtVec4 *)(param_1 + 0x870) = *(MtEvtVec4 *)(iVar5 + 0x100);
      *(MtEvtVec4 *)(param_1 + 0x880) = *(MtEvtVec4 *)(iVar5 + 0x110);

      puVar14 = (u32 *)(iVar5 + 0x120);

      puVar13 = (u32 *)(param_1 + 0x890);

      copyCount = 8;

      do {

        uVar16 = *puVar14;

        uVar17 = puVar14[1];

        puVar14 = puVar14 + 2;

        copyCount = copyCount + -1;

        *puVar13 = uVar16;

        puVar13[1] = uVar17;

        puVar13 = puVar13 + 2;

      } while (0 < copyCount);

    }

  }

  return;

}


#define FUN_0038f0f0(...) ((void (*)(...))FUN_0038f0f0)(__VA_ARGS__)
#undef FUN_0038f440
// FUN_0038F440 NONMATCHING


void FUN_0038f440(u8 *param_1,void *param_2,int param_3)



{

  u16 uVar1;

  u16 uVar2;

  u16 uVar3;

  short sVar4;

  int iVar5;

  char *puVar6;

  int iVar7;

  int iVar8;
  volatile /* Removing this qualifier worsens FUN_0038f440 (NONMATCHING nd225 -> NONMATCHING nd806, size 1140 -> 1112) - measured W170. */ MtEvtHalf4 half4;

  

  iVar5 = param_3 * 0x3c;

  iVar8 = iVar5 + *(int *)(param_1 + 0x9c);

  iVar7 = (int)param_2;

  half4 = *(MtEvtHalf4 *)(iVar8 + 0xc);


  *(MtEvtHalf4 *)(iVar7 + 8) = half4;

  if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) == 4) {

    puVar6 = (char *)(*(int *)(param_1 + 0x98) + param_3 * 0x10 + 8);

  }

  else {

    puVar6 = (char *)(*(int *)(param_1 + 0x9c) + iVar5 + 0x14);

  }

  *(u8 *)(iVar7 + 0x10) = *puVar6;

  if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) == 4) {

    iVar8 = *(int *)(param_1 + 0x98) + param_3 * 0x10 + 8;

  }

  else {

    iVar8 = *(int *)(param_1 + 0x9c) + iVar5 + 0x14;

  }

  *(u32 *)(iVar7 + 0x14) = *(u32 *)(iVar8 + 4);

  if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) == 4) {

    iVar8 = *(int *)(param_1 + 0x98) + param_3 * 0x10 + 8;

  }

  else {

    iVar8 = *(int *)(param_1 + 0x9c) + iVar5 + 0x14;

  }

  *(u32 *)(iVar7 + 0x18) = *(u32 *)(iVar8 + 8);

  if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) == 4) {

    iVar8 = *(int *)(param_1 + 0x98) + param_3 * 0x10 + 8;

  }

  else {

    iVar8 = *(int *)(param_1 + 0x9c) + iVar5 + 0x14;

  }

  *(u32 *)(iVar7 + 0x1c) = *(u32 *)(iVar8 + 0xc);

  if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) == 4) {

    iVar8 = *(int *)(param_1 + 0x98) + param_3 * 0x10 + 8;

  }

  else {

    iVar8 = *(int *)(param_1 + 0x9c) + iVar5 + 0x14;

  }

  *(u32 *)(iVar7 + 0x20) = *(u32 *)(iVar8 + 0x10);

  if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) == 4) {

    iVar8 = *(int *)(param_1 + 0x98) + param_3 * 0x10 + 8;

  }

  else {

    iVar8 = *(int *)(param_1 + 0x9c) + iVar5 + 0x14;

  }

  *(u32 *)(iVar7 + 0x24) = *(u32 *)(iVar8 + 0x14);

  if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) == 4) {

    iVar8 = *(int *)(param_1 + 0x98) + param_3 * 0x10 + 8;

  }

  else {

    iVar8 = *(int *)(param_1 + 0x9c) + iVar5 + 0x14;

  }

  *(u32 *)(iVar7 + 0x28) = *(u32 *)(iVar8 + 0x18);

  if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) == 4) {

    iVar8 = *(int *)(param_1 + 0x98) + param_3 * 0x10 + 8;

  }

  else {

    iVar8 = *(int *)(param_1 + 0x9c) + iVar5 + 0x14;

  }

  *(u32 *)(iVar7 + 0x2c) = *(u32 *)(iVar8 + 0x1c);

  if (*(int *)(iVar7 + 0x38) == 1) {

    *(u32 *)(iVar7 + 0x30) = 0;

  }

  else if (*(int *)(iVar7 + 0x38) == 0x30) {

    if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) == 4) {

      iVar8 = *(int *)(param_1 + 0x98) + param_3 * 0x10 + 8;

    }

    else {

      iVar8 = *(int *)(param_1 + 0x9c) + iVar5 + 0x14;

    }

    *(u32 *)(iVar7 + 0x30) = *(u32 *)(iVar8 + 0x20);

  }

  iVar8 = *(int *)(*(int *)(param_1 + 0x84) + 0x14);

  if (iVar8 < 0xc) {

    if (*(int *)(iVar7 + 0x38) == 1) {

      if (iVar8 == 4) {

        iVar8 = *(int *)(param_1 + 0x98) + param_3 * 0x10 + 8;

      }

      else {

        iVar8 = *(int *)(param_1 + 0x9c) + iVar5 + 0x14;

      }

      *(u32 *)(iVar7 + 0x34) = *(u32 *)(iVar8 + 0x20);

    }

  }

  else {

    if (iVar8 == 4) {

      iVar8 = *(int *)(param_1 + 0x98) + param_3 * 0x10 + 8;

    }

    else {

      iVar8 = *(int *)(param_1 + 0x9c) + iVar5 + 0x14;

    }

    *(u32 *)(iVar7 + 0x34) = *(u32 *)(iVar8 + 0x24);

  }

  *(u32 *)(iVar7 + 4) = 0xffffffff;

  if (*(char *)(iVar7 + 0x10) == '\x02') {

    if ((*(short *)(iVar7 + 0x28) < 10) || (500 < *(short *)(iVar7 + 0x28))) {

      *(u16 *)(iVar7 + 0x28) = 100;

    }

    if ((*(short *)(iVar7 + 0x2a) < 10) || (500 < *(short *)(iVar7 + 0x2a))) {

      *(u16 *)(iVar7 + 0x2a) = 100;

    }

  }

  else if ((*(char *)(iVar7 + 0x10) == '\x01') && (*(char *)(iVar7 + 0x14) == '\x01')) {

    sVar4 = *(short *)(iVar5 + *(int *)(param_1 + 0x9c) + 10);

    FUN_0038d790(param_2);

    if (*(int *)(iVar7 + 0x40) == 0) {

      FUN_0019d3f0("mt_evtLoadSave.c",0x6e1);

    }

    FUN_00521250(*(u32 *)(iVar7 + 0x40),

                 *(int *)(param_1 + 100) + (sVar4 * 0x12 + (int)sVar4) * 0x10,0x130);

  }

  return;

}


#define FUN_0038f440(...) ((void (*)(...))FUN_0038f440)(__VA_ARGS__)

#undef FUN_0038f8c0
// FUN_0038F8C0


void FUN_0038f8c0(int param_1,u64 param_2,int param_3,u16 param_4)
{
  u16 sVar1;
  u32 uVar2;
  int iVar3;
  u32 uVar4;
  int iVar5;
  int iVar6;

  if (param_1 == 0) {
    goto no_work;
  }
  if (param_3 != 0) {
    goto start;
  }
no_work:
  goto done;
done:
  return;
start:
  if (param_4 == 0) {
    return;
  }
  for (iVar6 = 0; iVar6 < *(int *)(param_1 + 0xb0); iVar6 = iVar6 + 1) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x84) + 0x14);
    if (iVar3 == 4) {
      sVar1 = *(u16 *)(*(int *)(param_1 + 0x98) + iVar6 * 0x10);
    }
    else {
      sVar1 = *(u16 *)(*(int *)(param_1 + 0x9c) + iVar6 * 0x3c);
    }
    if (sVar1 == 1) {
      iVar5 = *(int *)(param_1 + 0x9c);
      iVar5 += iVar6 * 0x3c;
      if (param_4 == *(u16 *)(iVar5 + 8)) {
        if (iVar3 == 4) {
          uVar2 = *(u16 *)(*(int *)(param_1 + 0x98) + iVar6 * 0x10 + 2);
        }
        else {
          uVar2 = *(u16 *)(iVar5 + 2);
        }
        uVar4 = FUN_00361350_direct(param_3,uVar2,param_2);
        FUN_0038f440_direct((u8 *)param_1,(void *)uVar4,iVar6);
      }
    }
  }
  return;
}


#define FUN_0038f8c0(...) ((void (*)(...))FUN_0038f8c0)(__VA_ARGS__)
#undef FUN_0038fa10
// FUN_0038FA10 NONMATCHING


void FUN_0038fa10(int param_1,u32 param_2)



{

  u16 uVar1;

  u16 uVar2;

  short sVar3;

  u16 *puVar4;

  u8 *puVar5;

  u16 uVar6;

  u8 *puVar7;

  u32 uVar8;

  int iVar9;

  int iVar10;

  int lVar11;

  u32 uVar12;

  u8 *puVar13;

  int iVar14;

  u32 *puVar15;

  int iVar16;

  MtEvtVec3 uStack_30;

  u8 auStack_20 [16];

  MtEvtVec3 uStack_10;

  

  puVar7 = (u8 *)0xc;

  puVar13 = auStack_20;

  puVar5 = puVar13;

  while (puVar5 != (u8 *)0x0) {

    *puVar13 = 0;

    puVar13 = puVar13 + 1;

    puVar7 = puVar7 + -1;

    puVar5 = puVar7;

  }

  uStack_30 = DAT_006a0bf8_vec_abs[0];

  lVar11 = FUN_003b5d00();

  if (lVar11 != 0) {

    lVar11 = FUN_003b5d10(0x1e58);

    if (lVar11 == 0) {

      uVar6 = FUN_003b5f70(600);

      lVar11 = FUN_003b5d10(uVar6);

    }

    else {

      uVar6 = *(u16 *)lVar11;

    }

    FUN_003b78b0(uVar6,auStack_20,&uStack_30);

    *(u32 *)((int)lVar11 + 0x104) = 0;

    uVar8 = FUN_003b5d10(uVar6);

    *(u32 *)((int)param_2 + 0x324) = uVar8;

    FUN_003bb450(0x44610000,0x42340000,0,0,auStack_20,&uStack_10);

    FUN_003b78b0(uVar6,&uStack_10,&uStack_30);

    lVar11 = FUN_003b5d10(0x1e59);

    if (lVar11 == 0) {

      uVar6 = FUN_003b5f70(0x259);

      FUN_003b5d10(uVar6);

    }

    else {

      uVar6 = *(u16 *)lVar11;

    }

    FUN_003b78b0(uVar6,&uStack_10,&uStack_30);

    iVar9 = FUN_003b5d10(uVar6);

    *(u32 *)(iVar9 + 0x104) = 0;

    FUN_0038a0c0(param_2,0);

    puVar4 = *(u16 **)((int)param_2 + 0x324);

    if (puVar4 != (u16 *)0x0) {

      uVar12 = FUN_00361dd0(0x21,param_2,*puVar4,0);

      iVar9 = (int)uVar12;

      *(u32 *)(iVar9 + 8) = 0xffffffff;

      *(u32 *)(iVar9 + 0x14) = 0;

      *(MtEvtVec3 *)(iVar9 + 0x3c) = uStack_10;

      *(MtEvtVec3 *)(iVar9 + 0x48) = uStack_30;

      for (iVar9 = 0; iVar9 < *(int *)(param_1 + 0xb0); iVar9 = iVar9 + 1) {

        iVar10 = *(int *)(*(int *)(param_1 + 0x84) + 0x14);

        if (iVar10 != 4) {

          sVar3 = *(short *)(*(int *)(param_1 + 0x9c) + iVar9 * 0x3c);

        }

        else {

          sVar3 = *(short *)(*(int *)(param_1 + 0x98) + iVar9 * 0x10);

        }

        if (sVar3 == 0x21) {

          if (iVar10 != 4) {

            uVar6 = *(u16 *)(*(int *)(param_1 + 0x9c) + iVar9 * 0x3c + 2);

          }

          else {

            uVar6 = *(u16 *)(*(int *)(param_1 + 0x98) + iVar9 * 0x10 + 2);

          }

          iVar10 = FUN_00361350(uVar12,uVar6,param_2);

          iVar14 = iVar9 * 0x3c;

          iVar16 = *(int *)(param_1 + 0x9c) + iVar14;

          uVar6 = *(u16 *)(iVar16 + 0xe);

          uVar1 = *(u16 *)(iVar16 + 0x10);

          uVar2 = *(u16 *)(iVar16 + 0x12);

          *(u16 *)(iVar10 + 8) = *(u16 *)(iVar16 + 0xc);

          *(u16 *)(iVar10 + 10) = uVar6;

          *(u16 *)(iVar10 + 0xc) = uVar1;

          *(u16 *)(iVar10 + 0xe) = uVar2;

          if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

            uVar6 = *(u16 *)(*(int *)(param_1 + 0x9c) + iVar14 + 4);

          }

          else {

            uVar6 = *(u16 *)(*(int *)(param_1 + 0x98) + iVar9 * 0x10 + 4);

          }

          *(u16 *)(iVar10 + 2) = uVar6;

          if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

            puVar15 = (u32 *)(*(int *)(param_1 + 0x9c) + iVar14 + 0x14);

          }

          else {

            puVar15 = (u32 *)(*(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8);

          }

          *(u32 *)(iVar10 + 0x10) = *puVar15;

          if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

            iVar16 = *(int *)(param_1 + 0x9c) + iVar14 + 0x14;

          }

          else {

            iVar16 = *(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8;

          }

          *(u32 *)(iVar10 + 0x14) = *(u32 *)(iVar16 + 4);

          if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

            iVar16 = *(int *)(param_1 + 0x9c) + iVar14 + 0x14;

          }

          else {

            iVar16 = *(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8;

          }

          *(u32 *)(iVar10 + 0x18) = *(u32 *)(iVar16 + 8);

          if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

            iVar16 = *(int *)(param_1 + 0x9c) + iVar14 + 0x14;

          }

          else {

            iVar16 = *(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8;

          }

          *(u32 *)(iVar10 + 0x1c) = *(u32 *)(iVar16 + 0xc);

          if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

            iVar16 = *(int *)(param_1 + 0x9c) + iVar14 + 0x14;

          }

          else {

            iVar16 = *(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8;

          }

          *(u32 *)(iVar10 + 0x20) = *(u32 *)(iVar16 + 0x10);

          if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

            iVar16 = *(int *)(param_1 + 0x9c) + iVar14 + 0x14;

          }

          else {

            iVar16 = *(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8;

          }

          *(u32 *)(iVar10 + 0x24) = *(u32 *)(iVar16 + 0x14);

          if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

            iVar16 = *(int *)(param_1 + 0x9c) + iVar14 + 0x14;

          }

          else {

            iVar16 = *(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8;

          }

          *(u32 *)(iVar10 + 0x28) = *(u32 *)(iVar16 + 0x18);

          if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

            iVar16 = *(int *)(param_1 + 0x9c) + iVar14 + 0x14;

          }

          else {

            iVar16 = *(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8;

          }

          *(u32 *)(iVar10 + 0x2c) = *(u32 *)(iVar16 + 0x1c);

          if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

            iVar14 = *(int *)(param_1 + 0x9c) + iVar14 + 0x14;

          }

          else {

            iVar14 = *(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8;

          }

          *(u32 *)(iVar10 + 0x30) = *(u32 *)(iVar14 + 0x20);

        }

      }

    }

  }

  return;

}


#define FUN_0038fa10(...) ((void (*)(...))FUN_0038fa10)(__VA_ARGS__)
#undef FUN_0038ffb0
// FUN_0038FFB0 NONMATCHING


void FUN_0038ffb0(int param_1,int param_2)



{

  u16 uVar1;

  u16 uVar2;

  u16 sVar3;

  u16 uVar4;

  int iVar5;

  int iVar6;

  u32 *puVar7;

  int iVar8;

  int iVar9;

  u64 pad[3];
  u32 aiStack_8[2];

  

  for (iVar9 = 0; iVar9 < 2; iVar9 = iVar9 + 1) {

    iVar6 = FUN_00361ca0_evt(0x23,param_2);

    aiStack_8[iVar9] = iVar6;

    *(u32 *)(iVar6 + 8) = 0xffffffff;

    *(u32 *)(iVar6 + 0x14) = 0;

    *(u32 *)(iVar6 + 0x38) = 0;

    *(int *)(iVar6 + 4) = iVar9;

  }

  for (iVar9 = 0; iVar9 < *(int *)(param_1 + 0xb0); iVar9 = iVar9 + 1) {

    iVar6 = *(int *)(*(int *)(param_1 + 0x84) + 0x14);

    if (iVar6 == 4) {

      sVar3 = *(short *)(*(int *)(param_1 + 0x98) + iVar9 * 0x10);

    }

    else {

      sVar3 = *(short *)(*(int *)(param_1 + 0x9c) + iVar9 * 0x3c);

    }

    if (sVar3 == 0x23) {

      if (iVar6 == 4) {

        iVar5 = *(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8;

      }

      else {

        iVar5 = *(int *)(param_1 + 0x9c) + iVar9 * 0x3c + 0x14;

      }

      if (iVar6 == 4) {

        uVar4 = *(u16 *)(*(int *)(param_1 + 0x98) + iVar9 * 0x10 + 2);

      }

      else {

        uVar4 = *(u16 *)(*(int *)(param_1 + 0x9c) + iVar9 * 0x3c + 2);

      }

      iVar6 = FUN_00361350_direct(aiStack_8[*(char *)(iVar5 + 1)],uVar4,param_2);

      iVar8 = *(int *)(param_1 + 0x9c) + iVar5;

      uVar4 = *(u16 *)(iVar8 + 0xe);

      uVar1 = *(u16 *)(iVar8 + 0x10);

      uVar2 = *(u16 *)(iVar8 + 0x12);

      *(u16 *)(iVar6 + 8) = *(u16 *)(iVar8 + 0xc);

      *(u16 *)(iVar6 + 10) = uVar4;

      *(u16 *)(iVar6 + 0xc) = uVar1;

      *(u16 *)(iVar6 + 0xe) = uVar2;

      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) == 4) {

        puVar7 = (u32 *)(*(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8);

      }

      else {

        puVar7 = (u32 *)(*(int *)(param_1 + 0x9c) + iVar5 + 0x14);

      }

      *(u32 *)(iVar6 + 0x10) = *puVar7;

      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) == 4) {

        iVar8 = *(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8;

      }

      else {

        iVar8 = *(int *)(param_1 + 0x9c) + iVar5 + 0x14;

      }

      *(u32 *)(iVar6 + 0x14) = *(u32 *)(iVar8 + 4);

      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) == 4) {

        iVar8 = *(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8;

      }

      else {

        iVar8 = *(int *)(param_1 + 0x9c) + iVar5 + 0x14;

      }

      *(u32 *)(iVar6 + 0x18) = *(u32 *)(iVar8 + 8);

      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) == 4) {

        iVar5 = *(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8;

      }

      else {

        iVar5 = *(int *)(param_1 + 0x9c) + iVar5 + 0x14;

      }

      *(u32 *)(iVar6 + 0x1c) = *(u32 *)(iVar5 + 0xc);

      if ('\x03' < *(char *)(iVar6 + 0x10)) {

        *(u32 *)(iVar6 + 0x10) = 0;

        *(u32 *)(iVar6 + 0x14) = 0;

        *(u32 *)(iVar6 + 0x18) = 0;

        *(u32 *)(iVar6 + 0x1c) = 0;

      }

    }

  }

  return;

}

#define FUN_0038ffb0(...) ((void (*)(...))FUN_0038ffb0)(__VA_ARGS__)
#undef FUN_003902c0
 
// FUN_003902C0 NONMATCHING


void FUN_003902c0(int param_1,int param_2)



{

  u16 uVar1;

  u16 uVar2;

  short sVar3;

  u16 uVar4;

  int iVar5;

  int iVar6;

  u32 *puVar7;

  int iVar8;

  int iVar9;

  int aiStack_10 [4];

  

  for (iVar9 = 0; iVar9 < 3; iVar9 = iVar9 + 1) {

    iVar6 = FUN_00361ca0(0x24,param_2);

    aiStack_10[iVar9] = iVar6;

    *(u32 *)(iVar6 + 8) = 0xffffffff;

    *(u32 *)(iVar6 + 0x14) = 0;

    *(u32 *)(iVar6 + 0x38) = 0;

    *(int *)(iVar6 + 4) = iVar9;

  }

  for (iVar9 = 0; iVar9 < *(int *)(param_1 + 0xb0); iVar9 = iVar9 + 1) {

    iVar6 = *(int *)(*(int *)(param_1 + 0x84) + 0x14);

    if (iVar6 != 4) {

      sVar3 = *(short *)(*(int *)(param_1 + 0x9c) + iVar9 * 0x3c);

    }

    else {

      sVar3 = *(short *)(*(int *)(param_1 + 0x98) + iVar9 * 0x10);

    }

    if (sVar3 == 0x24) {

      if (iVar6 != 4) {

        iVar5 = *(int *)(param_1 + 0x9c) + iVar9 * 0x3c + 0x14;

      }

      else {

        iVar5 = *(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8;

      }

      if (iVar6 != 4) {

        uVar4 = *(u16 *)(*(int *)(param_1 + 0x9c) + iVar9 * 0x3c + 2);

      }

      else {

        uVar4 = *(u16 *)(*(int *)(param_1 + 0x98) + iVar9 * 0x10 + 2);

      }

      iVar6 = FUN_00361350(aiStack_10[*(char *)(iVar5 + 1)],uVar4,param_2);

      iVar5 = iVar9 * 0x3c;

      iVar8 = *(int *)(param_1 + 0x9c) + iVar5;

      uVar1 = *(u16 *)(iVar8 + 0xc);

      uVar2 = *(u16 *)(iVar8 + 0xe);

      sVar3 = *(u16 *)(iVar8 + 0x10);

      uVar4 = *(u16 *)(iVar8 + 0x12);

      *(u16 *)(iVar6 + 8) = uVar1;
      *(u16 *)(iVar6 + 10) = uVar2;

      *(u16 *)(iVar6 + 0xc) = sVar3;

      *(u16 *)(iVar6 + 0xe) = uVar4;

      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

        puVar7 = (u32 *)(*(int *)(param_1 + 0x9c) + iVar5 + 0x14);

      }

      else {

        puVar7 = (u32 *)(*(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8);

      }

      *(u32 *)(iVar6 + 0x10) = *puVar7;

      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

        iVar8 = *(int *)(param_1 + 0x9c) + iVar5 + 0x14;

      }

      else {

        iVar8 = *(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8;

      }

      *(u32 *)(iVar6 + 0x14) = *(u32 *)(iVar8 + 4);

      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

        iVar8 = *(int *)(param_1 + 0x9c) + iVar5 + 0x14;

      }

      else {

        iVar8 = *(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8;

      }

      *(u32 *)(iVar6 + 0x18) = *(u32 *)(iVar8 + 8);

      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

        iVar8 = *(int *)(param_1 + 0x9c) + iVar5 + 0x14;

      }

      else {

        iVar8 = *(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8;

      }

      *(u32 *)(iVar6 + 0x1c) = *(u32 *)(iVar8 + 0xc);

      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

        iVar5 = *(int *)(param_1 + 0x9c) + iVar5 + 0x14;

      }

      else {

        iVar5 = *(int *)(param_1 + 0x98) + iVar9 * 0x10 + 8;

      }

      *(u32 *)(iVar6 + 0x20) = *(u32 *)(iVar5 + 0x10);

    }

  }

  return;

}
#define FUN_003902c0(...) ((void (*)(...))FUN_003902c0)(__VA_ARGS__)
#undef FUN_003905f0
// FUN_003905F0 NONMATCHING


void FUN_003905f0(int param_1,int param_2)



{

  u16 uVar1;

  u16 uVar2;

  short sVar3;

  u16 uVar4;

  int iVar5;

  u32 uVar6;

  int iVar7;

  u32 *puVar8;

  int iVar9;

  int iVar10;

  

  if (0 < *(int *)(*(int *)((int)param_2 + 0x710) + 4)) {

    uVar6 = FUN_00361ca0(0x25);

    for (iVar10 = 0; iVar10 < *(int *)(param_1 + 0xb0); iVar10 = iVar10 + 1) {

      iVar5 = *(int *)(*(int *)(param_1 + 0x84) + 0x14);

      if (iVar5 != 4) {

        sVar3 = *(short *)(*(int *)(param_1 + 0x9c) + iVar10 * 0x3c);

      }

      else {

        sVar3 = *(short *)(*(int *)(param_1 + 0x98) + iVar10 * 0x10);

      }

      if (sVar3 == 0x25) {

        if (iVar5 != 4) {

          uVar4 = *(u16 *)(*(int *)(param_1 + 0x9c) + iVar10 * 0x3c + 2);

        }

        else {

          uVar4 = *(u16 *)(*(int *)(param_1 + 0x98) + iVar10 * 0x10 + 2);

        }

        iVar5 = FUN_00361350(uVar6,uVar4,param_2);

        iVar7 = iVar10 * 0x3c;

        iVar9 = *(int *)(param_1 + 0x9c) + iVar7;

        uVar4 = *(u16 *)(iVar9 + 0xe);

        uVar1 = *(u16 *)(iVar9 + 0x10);

        uVar2 = *(u16 *)(iVar9 + 0x12);

        *(u16 *)(iVar5 + 8) = *(u16 *)(iVar9 + 0xc);

        *(u16 *)(iVar5 + 10) = uVar4;

        *(u16 *)(iVar5 + 0xc) = uVar1;

        *(u16 *)(iVar5 + 0xe) = uVar2;

        if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

          puVar8 = (u32 *)(*(int *)(param_1 + 0x9c) + iVar7 + 0x14);

        }

        else {

          puVar8 = (u32 *)(*(int *)(param_1 + 0x98) + iVar10 * 0x10 + 8);

        }

        *(u32 *)(iVar5 + 0x10) = *puVar8;

        if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

          iVar9 = *(int *)(param_1 + 0x9c) + iVar7 + 0x14;

        }

        else {

          iVar9 = *(int *)(param_1 + 0x98) + iVar10 * 0x10 + 8;

        }

        *(u32 *)(iVar5 + 0x14) = *(u32 *)(iVar9 + 4);

        if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

          iVar9 = *(int *)(param_1 + 0x9c) + iVar7 + 0x14;

        }

        else {

          iVar9 = *(int *)(param_1 + 0x98) + iVar10 * 0x10 + 8;

        }

        *(u32 *)(iVar5 + 0x18) = *(u32 *)(iVar9 + 8);

        if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

          iVar9 = *(int *)(param_1 + 0x9c) + iVar7 + 0x14;

        }

        else {

          iVar9 = *(int *)(param_1 + 0x98) + iVar10 * 0x10 + 8;

        }

        *(u32 *)(iVar5 + 0x1c) = *(u32 *)(iVar9 + 0xc);

        if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

          iVar9 = *(int *)(param_1 + 0x9c) + iVar7 + 0x14;

        }

        else {

          iVar9 = *(int *)(param_1 + 0x98) + iVar10 * 0x10 + 8;

        }

        *(u32 *)(iVar5 + 0x20) = *(u32 *)(iVar9 + 0x10);

        if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

          iVar9 = *(int *)(param_1 + 0x9c) + iVar7 + 0x14;

        }

        else {

          iVar9 = *(int *)(param_1 + 0x98) + iVar10 * 0x10 + 8;

        }

        *(u32 *)(iVar5 + 0x24) = *(u32 *)(iVar9 + 0x14);

        if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

          iVar7 = *(int *)(param_1 + 0x9c) + iVar7 + 0x14;

        }

        else {

          iVar7 = *(int *)(param_1 + 0x98) + iVar10 * 0x10 + 8;

        }

        *(u32 *)(iVar5 + 0x28) = *(u32 *)(iVar7 + 0x18);

      }

    }

  }

  return;

}
#define FUN_003905f0(...) ((void (*)(...))FUN_003905f0)(__VA_ARGS__)
#undef FUN_00390920
#pragma push
/* Removing this worsens FUN_00390920 (nd373 -> nd467) - measured W161. */
#pragma opt_common_subs off
 
// FUN_00390920 NONMATCHING


void FUN_00390920(int param_1,int param_2)



{

  u16 uVar1;

  u16 uVar2;

  short sVar3;

  u16 uVar4;
  u16 eventType;

  int iVar5;

  u32 uVar6;

  u32 uVar7;

  int iVar8;

  u32 *puVar9;
  MtEvtHalf4 half4;

  int iVar10;

  int iVar11;

  

  uVar6 = FUN_00361ca0(0x29);

  for (iVar11 = 0; iVar11 < *(int *)(param_1 + 0xb0); iVar11 = iVar11 + 1) {

    iVar5 = *(int *)(*(int *)(param_1 + 0x84) + 0x14);

    if (iVar5 != 4) {

      eventType = *(u16 *)(*(int *)(param_1 + 0x9c) + iVar11 * 0x3c);

    }

    else {

      eventType = *(u16 *)(*(int *)(param_1 + 0x98) + iVar11 * 0x10);

    }

    if (eventType == 0x29) {

      if (iVar5 != 4) {

        uVar4 = *(u16 *)(*(int *)(param_1 + 0x9c) + iVar11 * 0x3c + 2);

      }

      else {

        uVar4 = *(u16 *)(*(int *)(param_1 + 0x98) + iVar11 * 0x10 + 2);

      }

      uVar7 = FUN_00361350(uVar6,uVar4,param_2);

      iVar8 = iVar11 * 0x3c;

      iVar10 = *(int *)(param_1 + 0x9c) + iVar8;

      iVar5 = (int)uVar7;

      half4 = *(MtEvtHalf4 *)(iVar10 + 0xc);
      /* Removing this barrier worsens FUN_00390920 (nd373 -> nd515) - measured W164. */
      asm ("" : "+m"(half4));
      *(MtEvtHalf4 *)(iVar5 + 8) = half4;

      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

        puVar9 = (u32 *)(*(int *)(param_1 + 0x9c) + iVar8 + 0x14);

      }

      else {

        puVar9 = (u32 *)(*(int *)(param_1 + 0x98) + iVar11 * 0x10 + 8);

      }

      *(u32 *)(iVar5 + 0x10) = *puVar9;

      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

        iVar10 = *(int *)(param_1 + 0x9c) + iVar8 + 0x14;

      }

      else {

        iVar10 = *(int *)(param_1 + 0x98) + iVar11 * 0x10 + 8;

      }

      *(u32 *)(iVar5 + 0x14) = *(u32 *)(iVar10 + 4);

      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

        iVar10 = *(int *)(param_1 + 0x9c) + iVar8 + 0x14;

      }

      else {

        iVar10 = *(int *)(param_1 + 0x98) + iVar11 * 0x10 + 8;

      }

      *(u32 *)(iVar5 + 0x18) = *(u32 *)(iVar10 + 8);

      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

        iVar10 = *(int *)(param_1 + 0x9c) + iVar8 + 0x14;

      }

      else {

        iVar10 = *(int *)(param_1 + 0x98) + iVar11 * 0x10 + 8;

      }

      *(u32 *)(iVar5 + 0x1c) = *(u32 *)(iVar10 + 0xc);

      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

        iVar10 = *(int *)(param_1 + 0x9c) + iVar8 + 0x14;

      }

      else {

        iVar10 = *(int *)(param_1 + 0x98) + iVar11 * 0x10 + 8;

      }

      *(u32 *)(iVar5 + 0x20) = *(u32 *)(iVar10 + 0x10);

      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) != 4) {

        iVar10 = *(int *)(param_1 + 0x9c) + iVar8 + 0x14;

      }

      else {

        iVar10 = *(int *)(param_1 + 0x98) + iVar11 * 0x10 + 8;

      }

      *(u32 *)(iVar5 + 0x24) = *(u32 *)(iVar10 + 0x14);

      if ((*(char *)(iVar5 + 0x10) == '\x05') || (*(char *)(iVar5 + 0x10) == '\0')) {

        sVar3 = *(short *)(*(int *)(param_1 + 0x9c) + iVar8 + 10);

        if (*(int *)(iVar5 + 0x40) == 0) {

          FUN_0038d790(uVar7);

        }

        FUN_00521250(*(u32 *)(iVar5 + 0x40),

                     *(int *)(param_1 + 100) + (sVar3 * 0x12 + sVar3) * 0x10,0x130);

      }

    }

  }

  return;

}
#pragma opt_common_subs on
#pragma pop
#define FUN_00390920(...) ((void (*)(...))FUN_00390920)(__VA_ARGS__)
#undef FUN_00390c90
// FUN_00390C90 NONMATCHING


void FUN_00390c90(int param_1,int param_2)



{

  u16 event_type;
  u16 event_id;
  u32 token;
  u8 *object;
  u8 *record;
  u32 *source_word;
  int i;
  int stride;
  s16 value_0;
  s16 value_1;
  s16 value_2;
  s16 value_3;
  struct {
    s16 value_0;
    s16 value_1;
    s16 value_2;
    s16 value_3;
  } stack;

  token = FUN_00361ca0(0x2f);
  for (i = 0; i < *(int *)(param_1 + 0xb0); i = i + 1) {
    if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) == 4) {
      event_type = *(u16 *)(*(int *)(param_1 + 0x98) + i * 0x10);
    }
    else {
      stride = i * 0x10 - i;
      event_type = *(u16 *)(*(int *)(param_1 + 0x9c) + stride * 4);
    }
    if ((event_type & 0xffff) == 0x2f) {
      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) == 4) {
        event_id = *(u16 *)(*(int *)(param_1 + 0x98) + i * 0x10 + 2);
      }
      else {
        event_id = *(u16 *)(*(int *)(param_1 + 0x9c) + stride * 4 + 2);
      }
      object = (u8 *)FUN_00361350_direct(token,event_id,param_2);
      stride = i * 0x3c;
      record = (u8 *)*(int *)(param_1 + 0x9c) + stride;
      value_0 = *(s16 *)(record + 0xc);
      value_1 = *(s16 *)(record + 0xe);
      value_2 = *(s16 *)(record + 0x10);
      value_3 = *(s16 *)(record + 0x12);
      stack.value_0 = value_0;
      stack.value_1 = value_1;
      stack.value_2 = value_2;
      stack.value_3 = value_3;
      *(s16 *)(object + 8) = stack.value_0;
      *(s16 *)(object + 10) = stack.value_1;
      *(s16 *)(object + 0xc) = stack.value_2;
      *(s16 *)(object + 0xe) = stack.value_3;
      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) == 4) {
        source_word = (u32 *)((u8 *)*(int *)(param_1 + 0x98) + i * 0x10 + 8);
      }
      else {
        source_word = (u32 *)((u8 *)*(int *)(param_1 + 0x9c) + stride + 0x14);
      }
      *(u32 *)(object + 0x10) = *source_word;
      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) == 4) {
        source_word = (u32 *)((u8 *)*(int *)(param_1 + 0x98) + i * 0x10 + 8);
      }
      else {
        source_word = (u32 *)((u8 *)*(int *)(param_1 + 0x9c) + stride + 0x14);
      }
      *(u32 *)(object + 0x14) = *(source_word + 1);
      if (*(int *)(*(int *)(param_1 + 0x84) + 0x14) == 4) {
        source_word = (u32 *)((u8 *)*(int *)(param_1 + 0x98) + i * 0x10 + 8);
      }
      else {
        source_word = (u32 *)((u8 *)*(int *)(param_1 + 0x9c) + stride + 0x14);
      }
      *(u32 *)(object + 0x18) = *(source_word + 2);
      if (*(s8 *)(object + 0x10) == 1) {
        if (*(s16 *)(object + 0x1a) < 10) {
          *(u16 *)(object + 0x1a) = 100;
        }
        else if (500 <= *(s16 *)(object + 0x1a)) {
          *(u16 *)(object + 0x1a) = 100;
        }
      }
    }
  }

  return;

}
#define FUN_00390c90(...) ((void (*)(...))FUN_00390c90)(__VA_ARGS__)
#undef FUN_00390ef0
// FUN_00390EF0


void FUN_00390ef0(int param_1,int param_2)
{
  extern u32 FUN_0039ec10(int,int,u32 *,u16 *);
  extern u32 FUN_00316bd0(int,u16,u32,u32,int);
  u8 c0;
  u8 c1;
  u8 c2;
  u8 c3;
  u8 d0;
  u8 d1;
  u8 d2;
  u8 d3;
  u16 uVar4;
  u8 *puVar5;
  u32 modelData;
  u32 modelRes;
  u32 uVar7;
  float afStack_18[3];
  volatile /* Removing this qualifier loses FUN_00390ef0 (MATCH nd0 -> MISMATCH nd6, size 392 -> 392) - measured W170. */ u16 auStack_4[2];
  u32 uStack_8;

  if (*(char *)(param_2 + 0x22) < 0) {
    return;
  }
  modelData = FUN_0039ec10(param_1,*(char *)(param_2 + 0x22),&uStack_8,(u16 *)auStack_4);
  if (modelData != 0) {
    uVar7 = FUN_00316bd0(5,auStack_4[0],modelData,uStack_8,1);
    uVar4 = FUN_0039ec60(*(u32 *)(param_2 + 4));
    uVar4 = FUN_003b6270(uVar4,3,uVar7);
    FUN_003b9550(uVar4,1);
    afStack_18[0] = (float)(*(int *)(param_2 + 4) * 0x1e);
    afStack_18[1] = 0.0f;
    afStack_18[2] = (float)(-(*(int *)(param_2 + 4) * 0x1e));
    FUN_003b78b0(uVar4,afStack_18,0);
    modelRes = FUN_003b5d10(uVar4);
    if (modelRes == 0) {
      FUN_0019d3f0("mt_evtLoadSave.c",0x9b7);
    }
    FUN_00361d60(param_2,uVar4,modelRes);
    puVar5 = (u8 *)FUN_00318b00(uVar7);
    c0 = puVar5[0];
    c1 = puVar5[1];
    c2 = puVar5[2];
    c3 = puVar5[3];
    d3 = c3;
    d2 = c2;
    d1 = c1;
    d0 = c0;
    *(u8 *)(param_2 + 0x54) = d0;
    *(u8 *)(param_2 + 0x55) = d1;
    *(u8 *)(param_2 + 0x56) = d2;
    *(u8 *)(param_2 + 0x57) = d3;
  }
  else {
    FUN_00361d60(param_2,0,0);
  }
  return;
}
#define FUN_00390ef0(...) ((void (*)(...))FUN_00390ef0)(__VA_ARGS__)
#undef FUN_00391080
#undef FUN_00390ef0
// FUN_00391080 NONMATCHING


void FUN_00391080(u32 param_1,u32 param_2)



{

  u32 uVar12;

  int iVar11;


  u16 sVar1;

  u16 uVar2;

  int iVar3;

  u32 uVar4;

  u32 *puVar5;

  u32 uVar6;
 
  u32 uVar7;

  int iVar8;

  u32 *puVar9;

  int iVar10;



  


  uVar12 = 0;

  while ((int)uVar12 < 8) {


    uVar6 = FUN_00361ca0(0x30,param_2);

    puVar5 = (u32 *)uVar6;

    puVar5[1] = uVar12;

    for (iVar11 = 0; iVar10 = (int)param_1, iVar11 < *(int *)(iVar10 + 0xb0); iVar11 = iVar11 + 1) {

      iVar3 = *(int *)(*(int *)(iVar10 + 0x84) + 0x14);

      if (iVar3 == 4) {

        sVar1 = *(short *)(*(int *)(iVar10 + 0x98) + iVar11 * 0x10);

      }

      else {

        sVar1 = *(short *)(*(int *)(iVar10 + 0x9c) + iVar11 * 0x3c);

      }

      if (sVar1 == 0x30) {

        if (iVar3 == 4) {

          iVar8 = *(int *)(iVar10 + 0x98) + iVar11 * 0x10 + 8;

        }

        else {

          iVar8 = *(int *)(iVar10 + 0x9c) + iVar11 * 0x3c + 0x14;

        }

        if ((long)(int)puVar5[1] == (long)*(char *)(iVar8 + 0x20)) {

          if (iVar3 == 4) {

            uVar2 = *(u16 *)(*(int *)(iVar10 + 0x98) + iVar11 * 0x10 + 2);

          }

          else {

            uVar2 = *(u16 *)(*(int *)(iVar10 + 0x9c) + iVar11 * 0x3c + 2);

          }

          uVar7 = FUN_00361350(uVar6,uVar2,param_2);

          FUN_0038f440_direct((u8 *)param_1,(void *)uVar7,iVar11);

        }

      }

    }

    if (*(int *)(iVar10 + 0x104) != 0) {

      for (iVar11 = 0; iVar11 < *(int *)(iVar10 + 0x108); iVar11 = iVar11 + 1) {

        puVar9 = (u32 *)(*(int *)(iVar10 + 0x104) + iVar11 * 0x14);

        if (*(short *)((int)puVar9 + 2) != -1) {

          FUN_0019d3f0("mt_evtLoadSave.c",0x7e7);

        }

        else {

          int copyCount;

          if ((*puVar5 != (u32)(u8)*puVar9) || (puVar5[1] != (u32)*(u8 *)((int)puVar9 + 1)))

          goto LAB_00391290;

          puVar5 = puVar5 + 7;

          copyCount = 5;

          do {

            uVar4 = *puVar9;

            puVar9 = puVar9 + 1;

            copyCount = copyCount + -1;

            *puVar5 = uVar4;

            puVar5 = puVar5 + 1;

          } while (0 < copyCount);

          break;

        }

LAB_00391290:
        ;

      }

    }

    FUN_00390ef0(param_2,uVar6);

    uVar12 = uVar12 + 1;

  }

}
#define FUN_00391080(...) ((void (*)(...))FUN_00391080)(__VA_ARGS__)
#undef FUN_003912f0
#undef FUN_0038dad0
#undef FUN_0038e660
#undef FUN_0038e860
#undef FUN_0038f0f0
#undef FUN_0038f440
#undef FUN_0038f8c0
#undef FUN_0038fa10
#undef FUN_0038ffb0
#undef FUN_003902c0
#undef FUN_003905f0
#undef FUN_00390920
#undef FUN_00390c90
#undef FUN_00390ef0
#undef FUN_00391080
// FUN_003912F0 NONMATCHING


u32 FUN_003912f0(u32 param_1,u32 param_2)



{

  u16 uVar1;

  u16 uVar2;

  u16 uVar3;

  short sVar4;

  u8 uVar5;

  u16 uVar6;

  u32 uVar7;

  u32 uVar8;

  u32 *puVar9;

  u8 *puVar10;

  int iVar11;

  u64 uVar12;

  long lVar13;


  int iVar14;

  short *psVar15;

  u16 *puVar16;

  u32 *puVar17;

  u32 *puVar18;

  u32 *puVar19;

  int iVar20;

  int iVar21;

  int iVar22;

  long lVar23;

  int iVar24;

  u8 auStack_2 [2];

  

  FUN_005225a8(0x6a0c10);

  uVar7 = FUN_0016c920(1);

  iVar11 = (int)param_2;

  *(u32 *)(iVar11 + 0x8d4) = uVar7 & 0xffff;

  FUN_0038f0f0(param_2);

  FUN_0039e700(param_2);

  FUN_0039eaa0(param_2);

  for (iVar14 = 0; iVar24 = (int)param_1, iVar14 < *(int *)(iVar24 + 0x58); iVar14 = iVar14 + 1) {

    iVar20 = FUN_00361ca0(0x18,param_2);

    uVar8 = FUN_00361fe0(*(int *)(iVar24 + 0x18) +

                         *(int *)(*(int *)(iVar24 + 0x54) + iVar14 * 0x10) * 0x20,param_2);

    *(u32 *)(iVar20 + 8) = uVar8;

  }

  *(u32 *)(iVar11 + 0x74) = 0;

  FUN_005225a8(0x6a0c28);

  if (*(int *)(iVar24 + 0x94) != 0) {

    *(u32 *)(iVar11 + 0xc) = *(u32 *)(*(int *)(iVar24 + 0x94) + 8);

    *(u32 *)(iVar11 + 0x10) = **(u32 **)(iVar24 + 0x94);

    *(u32 *)(iVar11 + 0x14) = *(u32 *)(*(int *)(iVar24 + 0x94) + 4);

    *(u32 *)(iVar11 + 0x2a4) = *(u32 *)(*(int *)(iVar24 + 0x94) + 0xc);

    puVar18 = *(u32 **)(iVar24 + 0x94);

    puVar17 = (u32 *)(iVar11 + 0x2c);

    iVar14 = 9;

    do {

      uVar8 = *puVar18;

      puVar18 = puVar18 + 1;

      iVar14 = iVar14 + -1;

      *puVar17 = uVar8;

      puVar17 = puVar17 + 1;

    } while (0 < iVar14);

    *(u32 *)(iVar11 + 0x18) = *(u32 *)(iVar11 + 0x10);

    *(u32 *)(iVar11 + 0x1c) = 0xffffffff;

    if (*(int *)(iVar11 + 0x18) < 0) {

      *(u32 *)(iVar11 + 0x18) = 0;

    }

    iVar14 = *(int *)(iVar11 + 0xc) + -1;

    if (iVar14 < *(int *)(iVar11 + 0x18)) {

      *(int *)(iVar11 + 0x18) = iVar14;

    }

  }

  for (iVar14 = *(int *)(iVar11 + 0x84); iVar14 != 0; iVar14 = *(int *)(iVar14 + 0x94)) {

    FUN_0038f8c0(param_1,param_2,iVar14,*(u16 *)(iVar14 + 0xc));

  }

  FUN_00390c90(param_1,param_2);

  uVar12 = FUN_00361ca0(0x31,param_2);

  for (iVar14 = 0; iVar14 < *(int *)(iVar24 + 0xb0); iVar14 = iVar14 + 1) {

    iVar20 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

    if (iVar20 == 4) {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10);

    }

    else {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c);

    }

    if (sVar4 == 0x31) {

      if (iVar20 == 4) {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 2);

      }

      else {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 2);

      }

      iVar20 = FUN_00361350(uVar12,uVar6,param_2);

      iVar22 = iVar14 * 0x3c;

      iVar21 = *(int *)(iVar24 + 0x9c) + iVar22;

      uVar6 = *(u16 *)(iVar21 + 0xe);

      uVar1 = *(u16 *)(iVar21 + 0x10);

      uVar2 = *(u16 *)(iVar21 + 0x12);

      *(u16 *)(iVar20 + 8) = *(u16 *)(iVar21 + 0xc);
      *(u16 *)(iVar20 + 10) = uVar6;
      *(u16 *)(iVar20 + 0xc) = uVar1;
      *(u16 *)(iVar20 + 0xe) = uVar2;
      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8);

      }

      else {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x9c) + iVar22 + 0x14);

      }

      *(u32 *)(iVar20 + 0x10) = *puVar18;

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        iVar22 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

      }

      else {

        iVar22 = *(int *)(iVar24 + 0x9c) + iVar22 + 0x14;

      }

      *(u32 *)(iVar20 + 0x14) = *(u32 *)(iVar22 + 4);

    }

  }

  FUN_0038fa10(param_1,param_2);

  uVar12 = FUN_00361ca0(0x22,param_2);

  iVar14 = (int)uVar12;

  *(u32 *)(iVar14 + 8) = 0xffffffff;

  *(u32 *)(iVar14 + 0x14) = 0;

  *(u32 *)(iVar14 + 0x38) = 0;

  for (iVar14 = 0; iVar14 < *(int *)(iVar24 + 0xb0); iVar14 = iVar14 + 1) {

    iVar20 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

    if (iVar20 == 4) {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10);

    }

    else {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c);

    }

    if (sVar4 == 0x22) {

      if (iVar20 == 4) {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 2);

      }

      else {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 2);

      }

      iVar20 = FUN_00361350(uVar12,uVar6,param_2);

      iVar22 = *(int *)(iVar24 + 0x9c) + iVar14 * 0x3c;

      uVar6 = *(u16 *)(iVar22 + 0xe);

      uVar1 = *(u16 *)(iVar22 + 0x10);

      uVar2 = *(u16 *)(iVar22 + 0x12);

      *(u16 *)(iVar20 + 8) = *(u16 *)(iVar22 + 0xc);

      *(u16 *)(iVar20 + 10) = uVar6;

      *(u16 *)(iVar20 + 0xc) = uVar1;

      *(u16 *)(iVar20 + 0xe) = uVar2;

    }

  }

  FUN_0038ffb0(param_1,param_2);

  FUN_003902c0(param_1,param_2);

  FUN_003905f0(param_1,param_2);

  uVar12 = FUN_00361ca0(0x26,param_2);

  for (iVar14 = 0; iVar14 < *(int *)(iVar24 + 0xb0); iVar14 = iVar14 + 1) {

    iVar20 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

    if (iVar20 == 4) {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10);

    }

    else {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c);

    }

    if (sVar4 == 0x26) {

      if (iVar20 == 4) {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 2);

      }

      else {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 2);

      }

      iVar20 = FUN_00361350(uVar12,uVar6,param_2);

      iVar22 = iVar14 * 0x3c;

      iVar21 = *(int *)(iVar24 + 0x9c) + iVar22;

      uVar6 = *(u16 *)(iVar21 + 0xe);

      uVar1 = *(u16 *)(iVar21 + 0x10);

      uVar2 = *(u16 *)(iVar21 + 0x12);

      *(u16 *)(iVar20 + 8) = *(u16 *)(iVar21 + 0xc);

      *(u16 *)(iVar20 + 10) = uVar6;

      *(u16 *)(iVar20 + 0xc) = uVar1;

      *(u16 *)(iVar20 + 0xe) = uVar2;

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8);

      }

      else {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x9c) + iVar22 + 0x14);

      }

      *(u32 *)(iVar20 + 0x10) = *puVar18;

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        iVar22 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

      }

      else {

        iVar22 = *(int *)(iVar24 + 0x9c) + iVar22 + 0x14;

      }

      *(u32 *)(iVar20 + 0x14) = *(u32 *)(iVar22 + 4);

    }

  }

  uVar12 = FUN_00361ca0(0x27,param_2);

  for (iVar14 = 0; iVar14 < *(int *)(iVar24 + 0xb0); iVar14 = iVar14 + 1) {

    iVar20 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

    if (iVar20 == 4) {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10);

    }

    else {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c);

    }

    if (sVar4 == 0x27) {

      if (iVar20 == 4) {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 2);

      }

      else {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 2);

      }

      iVar20 = FUN_00361350(uVar12,uVar6,param_2);

      iVar22 = iVar14 * 0x3c;

      iVar21 = *(int *)(iVar24 + 0x9c) + iVar22;

      uVar6 = *(u16 *)(iVar21 + 0xe);

      uVar1 = *(u16 *)(iVar21 + 0x10);

      uVar2 = *(u16 *)(iVar21 + 0x12);

      *(u16 *)(iVar20 + 8) = *(u16 *)(iVar21 + 0xc);

      *(u16 *)(iVar20 + 10) = uVar6;

      *(u16 *)(iVar20 + 0xc) = uVar1;

      *(u16 *)(iVar20 + 0xe) = uVar2;

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8);

      }

      else {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x9c) + iVar22 + 0x14);

      }

      *(u32 *)(iVar20 + 0x10) = *puVar18;

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        iVar22 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

      }

      else {

        iVar22 = *(int *)(iVar24 + 0x9c) + iVar22 + 0x14;

      }

      *(u32 *)(iVar20 + 0x14) = *(u32 *)(iVar22 + 4);

    }

  }

  uVar12 = FUN_00361ca0(0x28,param_2);

  for (iVar14 = 0; iVar14 < *(int *)(iVar24 + 0xb0); iVar14 = iVar14 + 1) {

    iVar20 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

    if (iVar20 == 4) {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10);

    }

    else {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c);

    }

    if (sVar4 == 0x28) {

      if (iVar20 == 4) {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 2);

      }

      else {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 2);

      }

      iVar20 = FUN_00361350(uVar12,uVar6,param_2);

      iVar22 = iVar14 * 0x3c;

      iVar21 = *(int *)(iVar24 + 0x9c) + iVar22;

      uVar6 = *(u16 *)(iVar21 + 0xe);

      uVar1 = *(u16 *)(iVar21 + 0x10);

      uVar2 = *(u16 *)(iVar21 + 0x12);

      *(u16 *)(iVar20 + 8) = *(u16 *)(iVar21 + 0xc);

      *(u16 *)(iVar20 + 10) = uVar6;

      *(u16 *)(iVar20 + 0xc) = uVar1;

      *(u16 *)(iVar20 + 0xe) = uVar2;

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8);

      }

      else {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x9c) + iVar22 + 0x14);

      }

      *(u32 *)(iVar20 + 0x10) = *puVar18;

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        iVar21 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

      }

      else {

        iVar21 = *(int *)(iVar24 + 0x9c) + iVar22 + 0x14;

      }

      *(u32 *)(iVar20 + 0x14) = *(u32 *)(iVar21 + 4);

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        iVar21 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

      }

      else {

        iVar21 = *(int *)(iVar24 + 0x9c) + iVar22 + 0x14;

      }

      *(u32 *)(iVar20 + 0x18) = *(u32 *)(iVar21 + 8);

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        iVar22 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

      }

      else {

        iVar22 = *(int *)(iVar24 + 0x9c) + iVar22 + 0x14;

      }

      *(u32 *)(iVar20 + 0x1c) = *(u32 *)(iVar22 + 0xc);

    }

  }

  FUN_00390920(param_1,param_2);

  uVar12 = FUN_00361ca0(0x2a,param_2);

  for (iVar14 = 0; iVar14 < *(int *)(iVar24 + 0xb0); iVar14 = iVar14 + 1) {

    iVar20 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

    if (iVar20 == 4) {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10);

    }

    else {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c);

    }

    if (sVar4 == 0x2a) {

      if (iVar20 == 4) {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 2);

      }

      else {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 2);

      }

      iVar20 = FUN_00361350(uVar12,uVar6,param_2);

      iVar22 = iVar14 * 0x3c;

      iVar21 = *(int *)(iVar24 + 0x9c) + iVar22;

      uVar6 = *(u16 *)(iVar21 + 0xe);

      uVar1 = *(u16 *)(iVar21 + 0x10);

      uVar2 = *(u16 *)(iVar21 + 0x12);

      *(u16 *)(iVar20 + 8) = *(u16 *)(iVar21 + 0xc);

      *(u16 *)(iVar20 + 10) = uVar6;

      *(u16 *)(iVar20 + 0xc) = uVar1;

      *(u16 *)(iVar20 + 0xe) = uVar2;

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8);

      }

      else {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x9c) + iVar22 + 0x14);

      }

      *(u32 *)(iVar20 + 0x10) = *puVar18;

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        iVar21 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

      }

      else {

        iVar21 = *(int *)(iVar24 + 0x9c) + iVar22 + 0x14;

      }

      *(u32 *)(iVar20 + 0x14) = *(u32 *)(iVar21 + 4);

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        iVar22 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

      }

      else {

        iVar22 = *(int *)(iVar24 + 0x9c) + iVar22 + 0x14;

      }

      *(u32 *)(iVar20 + 0x18) = *(u32 *)(iVar22 + 8);

    }

  }

  uVar12 = FUN_00361ca0(0x2b,param_2);

  for (iVar14 = 0; iVar14 < *(int *)(iVar24 + 0xb0); iVar14 = iVar14 + 1) {

    iVar20 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

    if (iVar20 == 4) {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10);

    }

    else {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c);

    }

    if (sVar4 == 0x2b) {

      if (iVar20 == 4) {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 2);

      }

      else {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 2);

      }

      iVar20 = FUN_00361350(uVar12,uVar6,param_2);

      iVar22 = *(int *)(iVar24 + 0x9c) + iVar14 * 0x3c;

      uVar6 = *(u16 *)(iVar22 + 0xe);

      uVar1 = *(u16 *)(iVar22 + 0x10);

      uVar2 = *(u16 *)(iVar22 + 0x12);

      *(u16 *)(iVar20 + 8) = *(u16 *)(iVar22 + 0xc);

      *(u16 *)(iVar20 + 10) = uVar6;

      *(u16 *)(iVar20 + 0xc) = uVar1;

      *(u16 *)(iVar20 + 0xe) = uVar2;

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8);

      }

      else {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 0x14);

      }

      *(u32 *)(iVar20 + 0x10) = *puVar18;

    }

  }

  uVar12 = FUN_00361ca0(0x2c,param_2);

  for (iVar14 = 0; iVar14 < *(int *)(iVar24 + 0xb0); iVar14 = iVar14 + 1) {

    iVar20 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

    if (iVar20 == 4) {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10);

    }

    else {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c);

    }

    if (sVar4 == 0x2c) {

      if (iVar20 == 4) {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 2);

      }

      else {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 2);

      }

      iVar20 = FUN_00361350(uVar12,uVar6,param_2);

      iVar22 = *(int *)(iVar24 + 0x9c) + iVar14 * 0x3c;

      uVar6 = *(u16 *)(iVar22 + 0xe);

      uVar1 = *(u16 *)(iVar22 + 0x10);

      uVar2 = *(u16 *)(iVar22 + 0x12);

      *(u16 *)(iVar20 + 8) = *(u16 *)(iVar22 + 0xc);

      *(u16 *)(iVar20 + 10) = uVar6;

      *(u16 *)(iVar20 + 0xc) = uVar1;

      *(u16 *)(iVar20 + 0xe) = uVar2;

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8);

      }

      else {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 0x14);

      }

      *(u32 *)(iVar20 + 0x10) = *puVar18;

    }

  }

  uVar12 = FUN_00361ca0(0x2d,param_2);

  for (iVar14 = 0; iVar14 < *(int *)(iVar24 + 0xb0); iVar14 = iVar14 + 1) {

    iVar20 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

    if (iVar20 == 4) {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10);

    }

    else {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c);

    }

    if (sVar4 == 0x2d) {

      if (iVar20 == 4) {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 2);

      }

      else {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 2);

      }

      iVar20 = FUN_00361350(uVar12,uVar6,param_2);

      iVar22 = iVar14 * 0x3c;

      iVar21 = *(int *)(iVar24 + 0x9c) + iVar22;

      uVar6 = *(u16 *)(iVar21 + 0xe);

      uVar1 = *(u16 *)(iVar21 + 0x10);

      uVar2 = *(u16 *)(iVar21 + 0x12);

      *(u16 *)(iVar20 + 8) = *(u16 *)(iVar21 + 0xc);

      *(u16 *)(iVar20 + 10) = uVar6;

      *(u16 *)(iVar20 + 0xc) = uVar1;

      *(u16 *)(iVar20 + 0xe) = uVar2;

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8);

      }

      else {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x9c) + iVar22 + 0x14);

      }

      *(u32 *)(iVar20 + 0x10) = *puVar18;

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        iVar21 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

      }

      else {

        iVar21 = *(int *)(iVar24 + 0x9c) + iVar22 + 0x14;

      }

      *(u32 *)(iVar20 + 0x14) = *(u32 *)(iVar21 + 4);

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        iVar21 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

      }

      else {

        iVar21 = *(int *)(iVar24 + 0x9c) + iVar22 + 0x14;

      }

      *(u32 *)(iVar20 + 0x18) = *(u32 *)(iVar21 + 8);

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        iVar22 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

      }

      else {

        iVar22 = *(int *)(iVar24 + 0x9c) + iVar22 + 0x14;

      }

      *(u32 *)(iVar20 + 0x1c) = *(u32 *)(iVar22 + 0xc);

    }

  }

  uVar12 = FUN_00361ca0(0x2e,param_2);

  for (iVar14 = 0; iVar14 < *(int *)(iVar24 + 0xb0); iVar14 = iVar14 + 1) {

    iVar20 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

    if (iVar20 == 4) {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10);

    }

    else {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c);

    }

    if (sVar4 == 0x2e) {

      if (iVar20 == 4) {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 2);

      }

      else {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 2);

      }

      iVar20 = FUN_00361350(uVar12,uVar6,param_2);

      iVar22 = *(int *)(iVar24 + 0x9c) + iVar14 * 0x3c;

      uVar6 = *(u16 *)(iVar22 + 0xe);

      uVar1 = *(u16 *)(iVar22 + 0x10);

      uVar2 = *(u16 *)(iVar22 + 0x12);

      *(u16 *)(iVar20 + 8) = *(u16 *)(iVar22 + 0xc);

      *(u16 *)(iVar20 + 10) = uVar6;

      *(u16 *)(iVar20 + 0xc) = uVar1;

      *(u16 *)(iVar20 + 0xe) = uVar2;

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8);

      }

      else {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 0x14);

      }

      *(u32 *)(iVar20 + 0x10) = *puVar18;

    }

  }

  FUN_00391080_wide(param_1,param_2);

  uVar12 = FUN_00361ca0(0x32,param_2);

  for (iVar14 = 0; iVar14 < *(int *)(iVar24 + 0xb0); iVar14 = iVar14 + 1) {

    iVar20 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

    if (iVar20 == 4) {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10);

    }

    else {

      sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c);

    }

    if (sVar4 == 0x32) {

      if (iVar20 == 4) {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 2);

      }

      else {

        uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 2);

      }

      iVar20 = FUN_00361350(uVar12,uVar6,param_2);

      iVar22 = *(int *)(iVar24 + 0x9c) + iVar14 * 0x3c;

      uVar6 = *(u16 *)(iVar22 + 0xe);

      uVar1 = *(u16 *)(iVar22 + 0x10);

      uVar2 = *(u16 *)(iVar22 + 0x12);

      *(u16 *)(iVar20 + 8) = *(u16 *)(iVar22 + 0xc);

      *(u16 *)(iVar20 + 10) = uVar6;

      *(u16 *)(iVar20 + 0xc) = uVar1;

      *(u16 *)(iVar20 + 0xe) = uVar2;

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8);

      }

      else {

        puVar18 = (u32 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 0x14);

      }

      *(u32 *)(iVar20 + 0x10) = *puVar18;

    }

  }

  lVar23 = 0;

  do {

    uVar12 = FUN_00361ca0(10,param_2);

    puVar9 = (u32 *)uVar12;

    puVar9[1] = (u32)lVar23;

    for (iVar14 = 0; iVar14 < *(int *)(iVar24 + 0xb0); iVar14 = iVar14 + 1) {

      iVar20 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

      if (iVar20 == 4) {

        sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10);

      }

      else {

        sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c);

      }

      if (sVar4 == 10) {

        if (iVar20 == 4) {

          iVar22 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

        }

        else {

          iVar22 = *(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 0x14;

        }

        if (lVar23 == *(short *)(iVar22 + 8)) {

          if (iVar20 == 4) {

            uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 2);

          }

          else {

            uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 2);

          }

          iVar20 = FUN_00361350(uVar12,uVar6,param_2);

          iVar21 = iVar14 * 0x3c;

          iVar22 = *(int *)(iVar24 + 0x9c) + iVar21;

          uVar6 = *(u16 *)(iVar22 + 0xe);

          uVar1 = *(u16 *)(iVar22 + 0x10);

          uVar2 = *(u16 *)(iVar22 + 0x12);

          *(u16 *)(iVar20 + 8) = *(u16 *)(iVar22 + 0xc);

          *(u16 *)(iVar20 + 10) = uVar6;

          *(u16 *)(iVar20 + 0xc) = uVar1;

          *(u16 *)(iVar20 + 0xe) = uVar2;

          if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

            puVar18 = (u32 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8);

          }

          else {

            puVar18 = (u32 *)(*(int *)(iVar24 + 0x9c) + iVar21 + 0x14);

          }

          *(u32 *)(iVar20 + 0x10) = *puVar18;

          if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

            iVar22 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

          }

          else {

            iVar22 = *(int *)(iVar24 + 0x9c) + iVar21 + 0x14;

          }

          *(u32 *)(iVar20 + 0x14) = *(u32 *)(iVar22 + 4);

          if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

            iVar22 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

          }

          else {

            iVar22 = *(int *)(iVar24 + 0x9c) + iVar21 + 0x14;

          }

          *(u16 *)(iVar20 + 0x18) = *(u16 *)(iVar22 + 8);

          iVar22 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

          if (iVar22 < 7) {

            if (iVar22 == 4) {

              iVar22 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

            }

            else {

              iVar22 = *(int *)(iVar24 + 0x9c) + iVar21 + 0x14;

            }

            *(u16 *)(iVar20 + 2) = *(u16 *)(iVar22 + 10);

          }

          else {

            if (iVar22 == 4) {

              uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 4);

            }

            else {

              uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar21 + 4);

            }

            *(u16 *)(iVar20 + 2) = uVar6;

          }

          if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

            sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 6);

          }

          else {

            sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar21 + 6);

          }

          *(int *)(iVar20 + 4) = (int)sVar4;

          iVar22 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

          if (iVar22 < 7) {

            if (iVar22 == 4) {

              uVar3 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 4);

            }

            else {

              uVar3 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar21 + 4);

            }

            FUN_00521250(*(u32 *)(iVar20 + 0x48),*(int *)(iVar24 + 0xbc) + (u32)uVar3 * 0x30

                         ,0x30);

          }

          else {

            if (iVar22 == 4) {

              iVar22 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

            }

            else {

              iVar22 = *(int *)(iVar24 + 0x9c) + iVar21 + 0x14;

            }

            FUN_00521250(*(u32 *)(iVar20 + 0x48),

                         *(int *)(iVar24 + 0xbc) + *(short *)(iVar22 + 10) * 0x30,0x30);

          }

          if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

            iVar22 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

          }

          else {

            iVar22 = *(int *)(iVar24 + 0x9c) + iVar21 + 0x14;

          }

          *(u16 *)(iVar20 + 0x1c) = *(u16 *)(iVar22 + 0xc);

        }

      }

    }

    if (*(int *)(iVar24 + 0x104) != 0) {

      for (iVar14 = 0; iVar14 < *(int *)(iVar24 + 0x108); iVar14 = iVar14 + 1) {

        puVar19 = (u32 *)(*(int *)(iVar24 + 0x104) + iVar14 * 0x14);

        if (*(short *)((int)puVar19 + 2) == -1) {

          if ((*puVar9 != (u32)(u8)*puVar19) || (puVar9[1] != (u32)*(u8 *)((int)puVar19 + 1)))

          goto LAB_00392bb0;

          puVar9 = puVar9 + 7;

          iVar14 = 5;

          do {

            uVar7 = *puVar19;

            puVar19 = puVar19 + 1;

            iVar14 = iVar14 + -1;

            *puVar9 = uVar7;

            puVar9 = puVar9 + 1;

          } while (0 < iVar14);

          break;

        }

        FUN_0019d3f0(0x6a0b00,0x7e7);

LAB_00392bb0:
        ;

      }

    }

    if (2 < lVar23) {

      lVar23 = FUN_0039eee0(iVar11 + 0x82c);

      if ((lVar23 == 1) && (lVar23 = FUN_0039f710(iVar11 + 0x82c), 0 < lVar23)) {

        lVar23 = FUN_001729a0();

        if (lVar23 == 1) {

          puVar10 = (u8 *)FUN_00172990();

          uVar5 = puVar10[0x1e];

          lVar23 = FUN_003c3fe0(*puVar10);

          if (lVar23 != 0) {

            FUN_0039ef30(iVar11 + 0x82c,5,lVar23);

          }

          lVar23 = FUN_003c3f40(uVar5);

          if (lVar23 != 0) {

            FUN_0039ef30(iVar11 + 0x82c,6,lVar23);

          }

        }

        lVar23 = FUN_00386e10(param_2);

        if ((lVar23 == 0x328) && (lVar23 = FUN_00386e30(param_2), lVar23 == 1)) {

          lVar23 = FUN_00172c50(auStack_2);

          if (lVar23 != 0) {

            uVar12 = FUN_003c3fe0(*(u8 *)lVar23);

            FUN_0039ef30(iVar11 + 0x82c,0,uVar12);

          }

        }

        else {

          lVar23 = FUN_00386e10(param_2);

          if ((lVar23 == 0x329) && (lVar23 = FUN_00386e30(param_2), lVar23 == 1)) {

            lVar23 = FUN_003c3390();

            if (lVar23 != 0) {

              uVar6 = FUN_0016dd40();

              lVar13 = FUN_0016dce0(uVar6);

              if (lVar13 == 0) {

                FUN_0019d3f0(0x6a0b00,0xcd3);

              }

              uVar12 = FUN_003c3f80(uVar6);

              FUN_0039ef30(iVar11 + 0x82c,0,uVar12);

              uVar5 = FUN_0016df30(uVar6);

              uVar12 = FUN_0030bbb0(uVar5);

              FUN_0039ef30(iVar11 + 0x82c,1,uVar12);

              uVar5 = FUN_0016dba0(uVar6);

              FUN_0039eef0(iVar11 + 0x82c,2,uVar5);

              uVar12 = FUN_003c3f40(*(u8 *)((int)lVar23 + 0x2a));

              FUN_0039ef30(iVar11 + 0x82c,3,uVar12);

            }

          }

          else {

            lVar23 = FUN_00386e10(param_2);

            if ((lVar23 == 0x336) && (lVar23 = FUN_00386e30(param_2), lVar23 == 1)) {

              lVar23 = FUN_003c1430();

              if (lVar23 != 0) {

                uVar6 = FUN_0016dd40();

                lVar13 = FUN_0016dce0(uVar6);

                if (lVar13 == 0) {

                  FUN_0019d3f0(0x6a0b00,0xcf5);

                }

                uVar12 = FUN_003c3f80(uVar6);

                FUN_0039ef30(iVar11 + 0x82c,0,uVar12);

                uVar5 = FUN_0016df30(uVar6);

                uVar12 = FUN_0030bbb0(uVar5);

                FUN_0039ef30(iVar11 + 0x82c,1,uVar12);

                uVar5 = FUN_0016dba0(uVar6);

                FUN_0039eef0(iVar11 + 0x82c,2,uVar5);

                uVar12 = FUN_003c3f40(*(u8 *)((int)lVar23 + 0x1e));

                FUN_0039ef30(iVar11 + 0x82c,3,uVar12);

              }

            }

            else {

              lVar23 = FUN_00386e10(param_2);

              if ((lVar23 == 0x38e) && (lVar23 = FUN_00386e30(param_2), lVar23 == 1)) {

                uVar6 = FUN_0016dd40();

                lVar23 = FUN_0016dce0(uVar6);

                if (lVar23 == 0) {

                  FUN_0019d3f0(0x6a0b00,0xd14);

                }

                uVar12 = FUN_003c3f80(uVar6);

                FUN_0039ef30(iVar11 + 0x82c,0,uVar12);

                uVar5 = FUN_0016df30(uVar6);

                uVar12 = FUN_0030bbb0(uVar5);

                FUN_0039ef30(iVar11 + 0x82c,1,uVar12);

                uVar5 = FUN_0016dba0(uVar6);

                FUN_0039eef0(iVar11 + 0x82c,2,uVar5);

              }

            }

          }

        }

        uVar12 = FUN_00361ca0(4,param_2);

        for (iVar14 = 0; iVar14 < *(int *)(iVar24 + 0xb0); iVar14 = iVar14 + 1) {

          iVar11 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

          if (iVar11 == 4) {

            sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10);

          }

          else {

            sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c);

          }

          if (sVar4 == 4) {

            if (iVar11 == 4) {

              uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 2);

            }

            else {

              uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 2);

            }

            iVar11 = FUN_00361350(uVar12,uVar6,param_2);

            iVar20 = iVar14 * 0x3c;

            iVar22 = *(int *)(iVar24 + 0x9c) + iVar20;

            uVar6 = *(u16 *)(iVar22 + 0xe);

            uVar1 = *(u16 *)(iVar22 + 0x10);

            uVar2 = *(u16 *)(iVar22 + 0x12);

            *(u16 *)(iVar11 + 8) = *(u16 *)(iVar22 + 0xc);

            *(u16 *)(iVar11 + 10) = uVar6;

            *(u16 *)(iVar11 + 0xc) = uVar1;

            *(u16 *)(iVar11 + 0xe) = uVar2;

            if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

              uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 4);

            }

            else {

              uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar20 + 4);

            }

            *(u16 *)(iVar11 + 2) = uVar6;

            if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

              puVar16 = (u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8);

            }

            else {

              puVar16 = (u16 *)(*(int *)(iVar24 + 0x9c) + iVar20 + 0x14);

            }

            *(u16 *)(iVar11 + 0x10) = *puVar16;

            if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

              iVar22 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

            }

            else {

              iVar22 = *(int *)(iVar24 + 0x9c) + iVar20 + 0x14;

            }

            *(u16 *)(iVar11 + 0x12) = *(u16 *)(iVar22 + 2);

            if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

              iVar22 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

            }

            else {

              iVar22 = *(int *)(iVar24 + 0x9c) + iVar20 + 0x14;

            }

            *(u8 *)(iVar11 + 0x14) = *(u8 *)(iVar22 + 4);

            if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

              iVar22 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

            }

            else {

              iVar22 = *(int *)(iVar24 + 0x9c) + iVar20 + 0x14;

            }

            *(u8 *)(iVar11 + 0x15) = *(u8 *)(iVar22 + 5);

            if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

              iVar20 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

            }

            else {

              iVar20 = *(int *)(iVar24 + 0x9c) + iVar20 + 0x14;

            }

            *(u8 *)(iVar11 + 0x16) = *(u8 *)(iVar20 + 6);

          }

        }

      }

      uVar12 = FUN_00361ca0(5,param_2);

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) < 6) {

        iVar14 = *(int *)(iVar24 + 0xb0);

      }

      else {

        iVar14 = *(int *)(iVar24 + 0xac);

      }

      for (iVar11 = 0; iVar11 < iVar14; iVar11 = iVar11 + 1) {

        iVar20 = iVar11 * 0x3c;

        psVar15 = (short *)(*(int *)(iVar24 + 0xa8) + iVar20);

        if (*psVar15 == 5) {

          iVar22 = FUN_00361350(uVar12,psVar15[1],param_2);

          iVar21 = *(int *)(iVar24 + 0xa8) + iVar20;

          uVar6 = *(u16 *)(iVar21 + 0xe);

          uVar1 = *(u16 *)(iVar21 + 0x10);

          uVar2 = *(u16 *)(iVar21 + 0x12);

          *(u16 *)(iVar22 + 8) = *(u16 *)(iVar21 + 0xc);

          *(u16 *)(iVar22 + 10) = uVar6;

          *(u16 *)(iVar22 + 0xc) = uVar1;

          *(u16 *)(iVar22 + 0xe) = uVar2;

          *(u16 *)(iVar22 + 0x10) = *(u16 *)(*(int *)(iVar24 + 0xa8) + iVar20 + 0x14);

          *(u8 *)(iVar22 + 0x12) = *(u8 *)(*(int *)(iVar24 + 0xa8) + iVar20 + 0x16);

        }

      }

      uVar12 = FUN_00361ca0(0x13,param_2);

      if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) < 6) {

        iVar14 = *(int *)(iVar24 + 0xb0);

      }

      else {

        iVar14 = *(int *)(iVar24 + 0xac);

      }

      for (iVar11 = 0; iVar11 < iVar14; iVar11 = iVar11 + 1) {

        iVar20 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

        if (iVar20 < 6) {

          if (iVar20 == 4) {

            sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar11 * 0x10);

          }

          else {

            sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar11 * 0x3c);

          }

          if (sVar4 == 0x13) {

            FUN_0019d3f0(0x6a0b00,0xd8f);

            if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

              uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar11 * 0x10 + 2);

            }

            else {

              uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar11 * 0x3c + 2);

            }

            iVar20 = FUN_00361350(uVar12,uVar6,param_2);

            iVar22 = iVar11 * 0x3c;

            iVar21 = *(int *)(iVar24 + 0x9c) + iVar22;

            uVar6 = *(u16 *)(iVar21 + 0xe);

            uVar1 = *(u16 *)(iVar21 + 0x10);

            uVar2 = *(u16 *)(iVar21 + 0x12);

            *(u16 *)(iVar20 + 8) = *(u16 *)(iVar21 + 0xc);

            *(u16 *)(iVar20 + 10) = uVar6;

            *(u16 *)(iVar20 + 0xc) = uVar1;

            *(u16 *)(iVar20 + 0xe) = uVar2;

            if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

              puVar16 = (u16 *)(*(int *)(iVar24 + 0x98) + iVar11 * 0x10 + 8);

            }

            else {

              puVar16 = (u16 *)(*(int *)(iVar24 + 0x9c) + iVar22 + 0x14);

            }

            *(u16 *)(iVar20 + 0x10) = *puVar16;

            if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

              iVar21 = *(int *)(iVar24 + 0x98) + iVar11 * 0x10 + 8;

            }

            else {

              iVar21 = *(int *)(iVar24 + 0x9c) + iVar22 + 0x14;

            }

            *(u16 *)(iVar20 + 0x12) = *(u16 *)(iVar21 + 2);

            if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

              iVar22 = *(int *)(iVar24 + 0x98) + iVar11 * 0x10 + 8;

            }

            else {

              iVar22 = *(int *)(iVar24 + 0x9c) + iVar22 + 0x14;

            }

            *(u16 *)(iVar20 + 0x14) = *(u16 *)(iVar22 + 4);

          }

        }

        else {

          iVar20 = iVar11 * 0x3c;

          psVar15 = (short *)(*(int *)(iVar24 + 0xa8) + iVar20);

          if (*psVar15 == 0x13) {

            iVar22 = FUN_00361350(uVar12,psVar15[1],param_2);

            iVar21 = *(int *)(iVar24 + 0xa8) + iVar20;

            uVar6 = *(u16 *)(iVar21 + 0xe);

            uVar1 = *(u16 *)(iVar21 + 0x10);

            uVar2 = *(u16 *)(iVar21 + 0x12);

            *(u16 *)(iVar22 + 8) = *(u16 *)(iVar21 + 0xc);

            *(u16 *)(iVar22 + 10) = uVar6;

            *(u16 *)(iVar22 + 0xc) = uVar1;

            *(u16 *)(iVar22 + 0xe) = uVar2;

            *(u16 *)(iVar22 + 0x10) =

                 *(u16 *)(*(int *)(iVar24 + 0xa8) + iVar20 + 0x14);

            *(u16 *)(iVar22 + 0x12) =

                 *(u16 *)(*(int *)(iVar24 + 0xa8) + iVar20 + 0x16);

            *(u16 *)(iVar22 + 0x14) =

                 *(u16 *)(*(int *)(iVar24 + 0xa8) + iVar20 + 0x18);

          }

        }

      }

      uVar12 = FUN_00361ca0(6,param_2);

      for (iVar14 = 0; iVar14 < *(int *)(iVar24 + 0xb0); iVar14 = iVar14 + 1) {

        iVar11 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

        if (iVar11 == 4) {

          sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10);

        }

        else {

          sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c);

        }

        if (sVar4 == 6) {

          if (iVar11 == 4) {

            uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 2);

          }

          else {

            uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 2);

          }

          iVar11 = FUN_00361350(uVar12,uVar6,param_2);

          iVar20 = iVar14 * 0x3c;

          iVar22 = *(int *)(iVar24 + 0x9c) + iVar20;

          uVar6 = *(u16 *)(iVar22 + 0xe);

          uVar1 = *(u16 *)(iVar22 + 0x10);

          uVar2 = *(u16 *)(iVar22 + 0x12);

          *(u16 *)(iVar11 + 8) = *(u16 *)(iVar22 + 0xc);

          *(u16 *)(iVar11 + 10) = uVar6;

          *(u16 *)(iVar11 + 0xc) = uVar1;

          *(u16 *)(iVar11 + 0xe) = uVar2;

          if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

            uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 4);

          }

          else {

            uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar20 + 4);

          }

          *(u16 *)(iVar11 + 2) = uVar6;

          iVar22 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

          if (iVar22 < 0xb) {

            if (iVar22 == 4) {

              psVar15 = (short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8);

            }

            else {

              psVar15 = (short *)(*(int *)(iVar24 + 0x9c) + iVar20 + 0x14);

            }

            sVar4 = *psVar15;

            if (sVar4 < 1) {

              *(u16 *)(iVar11 + 0x10) = 0;

              *(u16 *)(iVar11 + 0x12) = 0xffff;

            }

            else {

              *(u16 *)(iVar11 + 0x10) = 1;

              *(short *)(iVar11 + 0x12) = sVar4 + -1;

            }

          }

          else {

            if (iVar22 == 4) {

              puVar16 = (u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8);

            }

            else {

              puVar16 = (u16 *)(*(int *)(iVar24 + 0x9c) + iVar20 + 0x14);

            }

            *(u16 *)(iVar11 + 0x10) = *puVar16;

            if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

              iVar20 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

            }

            else {

              iVar20 = *(int *)(iVar24 + 0x9c) + iVar20 + 0x14;

            }

            *(u16 *)(iVar11 + 0x12) = *(u16 *)(iVar20 + 2);

          }

        }

      }

      uVar12 = FUN_00361ca0(7,param_2);

      for (iVar14 = 0; iVar14 < *(int *)(iVar24 + 0xb0); iVar14 = iVar14 + 1) {

        iVar11 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

        if (iVar11 == 4) {

          sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10);

        }

        else {

          sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c);

        }

        if (sVar4 == 7) {

          if (iVar11 == 4) {

            uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 2);

          }

          else {

            uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 2);

          }

          iVar11 = FUN_00361350(uVar12,uVar6,param_2);

          iVar20 = iVar14 * 0x3c;

          iVar22 = *(int *)(iVar24 + 0x9c) + iVar20;

          uVar6 = *(u16 *)(iVar22 + 0xe);

          uVar1 = *(u16 *)(iVar22 + 0x10);

          uVar2 = *(u16 *)(iVar22 + 0x12);

          *(u16 *)(iVar11 + 8) = *(u16 *)(iVar22 + 0xc);

          *(u16 *)(iVar11 + 10) = uVar6;

          *(u16 *)(iVar11 + 0xc) = uVar1;

          *(u16 *)(iVar11 + 0xe) = uVar2;

          if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

            uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 4);

          }

          else {

            uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar20 + 4);

          }

          *(u16 *)(iVar11 + 2) = uVar6;

          if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

            puVar16 = (u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8);

          }

          else {

            puVar16 = (u16 *)(*(int *)(iVar24 + 0x9c) + iVar20 + 0x14);

          }

          *(u16 *)(iVar11 + 0x10) = *puVar16;

        }

      }

      uVar12 = FUN_00361ca0(0x1c,param_2);

      for (iVar14 = 0; iVar14 < *(int *)(iVar24 + 0xb0); iVar14 = iVar14 + 1) {

        iVar11 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

        if (iVar11 == 4) {

          sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10);

        }

        else {

          sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c);

        }

        if (sVar4 == 0x1c) {

          if (iVar11 == 4) {

            uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 2);

          }

          else {

            uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 2);

          }

          iVar11 = FUN_00361350(uVar12,uVar6,param_2);

          iVar20 = iVar14 * 0x3c;

          iVar22 = *(int *)(iVar24 + 0x9c) + iVar20;

          uVar6 = *(u16 *)(iVar22 + 0xe);

          uVar1 = *(u16 *)(iVar22 + 0x10);

          uVar2 = *(u16 *)(iVar22 + 0x12);

          *(u16 *)(iVar11 + 8) = *(u16 *)(iVar22 + 0xc);

          *(u16 *)(iVar11 + 10) = uVar6;

          *(u16 *)(iVar11 + 0xc) = uVar1;

          *(u16 *)(iVar11 + 0xe) = uVar2;

          if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

            uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 4);

          }

          else {

            uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar20 + 4);

          }

          *(u16 *)(iVar11 + 2) = uVar6;

          if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

            puVar18 = (u32 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8);

          }

          else {

            puVar18 = (u32 *)(*(int *)(iVar24 + 0x9c) + iVar20 + 0x14);

          }

          *(u32 *)(iVar11 + 0x10) = *puVar18;

          if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

            iVar22 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

          }

          else {

            iVar22 = *(int *)(iVar24 + 0x9c) + iVar20 + 0x14;

          }

          *(u32 *)(iVar11 + 0x14) = *(u32 *)(iVar22 + 4);

          if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

            iVar20 = *(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8;

          }

          else {

            iVar20 = *(int *)(iVar24 + 0x9c) + iVar20 + 0x14;

          }

          *(u32 *)(iVar11 + 0x18) = *(u32 *)(iVar20 + 8);

        }

      }

      uVar12 = FUN_00361ca0(0x1d,param_2);

      for (iVar14 = 0; iVar14 < *(int *)(iVar24 + 0xb0); iVar14 = iVar14 + 1) {

        iVar11 = *(int *)(*(int *)(iVar24 + 0x84) + 0x14);

        if (iVar11 == 4) {

          sVar4 = *(short *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10);

        }

        else {

          sVar4 = *(short *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c);

        }

        if (sVar4 == 0x1d) {

          if (iVar11 == 4) {

            uVar6 = *(u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 2);

          }

          else {

            uVar6 = *(u16 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 2);

          }

          iVar11 = FUN_00361350(uVar12,uVar6,param_2);

          iVar20 = *(int *)(iVar24 + 0x9c) + iVar14 * 0x3c;

          uVar6 = *(u16 *)(iVar20 + 0xe);

          uVar1 = *(u16 *)(iVar20 + 0x10);

          uVar2 = *(u16 *)(iVar20 + 0x12);

          *(u16 *)(iVar11 + 8) = *(u16 *)(iVar20 + 0xc);

          *(u16 *)(iVar11 + 10) = uVar6;

          *(u16 *)(iVar11 + 0xc) = uVar1;

          *(u16 *)(iVar11 + 0xe) = uVar2;

          if (*(int *)(*(int *)(iVar24 + 0x84) + 0x14) == 4) {

            puVar16 = (u16 *)(*(int *)(iVar24 + 0x98) + iVar14 * 0x10 + 8);

          }

          else {

            puVar16 = (u16 *)(*(int *)(iVar24 + 0x9c) + iVar14 * 0x3c + 0x14);

          }

          *(u16 *)(iVar11 + 0x10) = *puVar16;

        }

      }

      for (iVar14 = 0; iVar14 < 10; iVar14 = iVar14 + 1) {

        FUN_0038d6b0(iVar14,0xffffffffffffffff);

      }

      FUN_00362240(param_2);

      return 1;

    }


    lVar23 = (long)(int)((u32)lVar23 + 1);

  } while( 1 );

}
#define FUN_003912f0(...) ((u32 (*)(...))FUN_003912f0)(__VA_ARGS__)
