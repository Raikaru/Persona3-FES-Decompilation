#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern u32 DAT_007ce64c;
extern u32 DAT_007ce650;
extern u32 DAT_007ce654;
extern u32 DAT_0095aea0;
extern u32 DAT_0095aea4;
extern u32 DAT_0095aea8;
extern u32 DAT_0095aeac;
extern u32 DAT_0095aeb0;
extern u32 DAT_0095aeb4;
extern u32 DAT_0095aeb8;
extern u32 DAT_0095aebc;
extern u32 DAT_0095aec0;
extern u32 DAT_0095aec4;
extern u32 DAT_0095aec8;
extern u32 DAT_0095aed8;
extern u32 DAT_0095aee0;
extern u32 DAT_0095aee4;
extern u32 DAT_0095aee8;
extern u32 DAT_0095aeec;
extern u32 DAT_00960088;
extern code DAT_00960090;
extern code DAT_009600a0;
extern code DAT_00960178;
#pragma alias DAT_00960178_abs DAT_00960178
extern code DAT_00960178_abs[];
extern code DAT_0096017c;
extern u32 DAT_007cd530;
extern u32 DAT_007cd538;
extern char DAT_006a2a40[];
extern void FUN_003cfe50(void);
extern u64 FUN_003b18c0(void);
extern void FUN_003afa40(void);
#pragma alias FUN_00194e10_fmgsl FUN_00194e10
extern u32 FUN_00194e10_fmgsl(void*, u32, u32, u32, code, code, void*);
#pragma alias FUN_00100d80_fmgsl FUN_00100d80
extern u32 FUN_00100d80_fmgsl(void*, u32);
#pragma alias FUN_001023a0_fmgsl FUN_001023a0
extern void FUN_001023a0_fmgsl(u32);
#pragma alias FUN_00112370_fmgsl FUN_00112370
extern u32 FUN_00112370_fmgsl(void*);

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
u32  FUN_003b41a0(u64 param_1,int param_2,int param_3,int param_4,int param_5,long param_6);
u8 FUN_003b44a0(void);
int * FUN_003b4520(void);
void FUN_003b4580(int param_1);
int * FUN_003b45f0(int param_1,int param_2);
int * FUN_003b46b0(int param_1);
u32 FUN_003b46f0(int *param_1,int param_2);
u32 FUN_003b4740(int param_1);
void FUN_003b4770(int *param_1,int *param_2);
int FUN_003b47b0(int param_1,int param_2,u64 param_3,int *param_4);
void FUN_003b4920(u32 *param_1,u32 *param_2,int param_3,int param_4);
int * FUN_003b49a0(int *param_1);
void FUN_003b4a20(int *param_1,u32 *param_2);
void FUN_003b4a90(int *param_1,int param_2,int param_3,int param_4,int param_5,int *param_6,  int param_7);
void FUN_003b4b40(int param_1,int param_2,u8 *param_3,u8 *param_4);
void FUN_003b4d10(int *param_1,u32 *param_2,u64 param_3,int param_4,u64 param_5  );
void FUN_003b4e90(void);
void FUN_003b4ea0(void);
void FUN_003b4eb0(void);
void FUN_003b4ec0(void);
void FUN_003b4ed0(void);
void FUN_003b4ee0(void);

/* Region call-cast macros */
#define FUN_003b41a0(...) ((u32 (*)(...))FUN_003b41a0)(__VA_ARGS__)
#define FUN_003b44a0(...) ((u8 (*)(...))FUN_003b44a0)(__VA_ARGS__)
#define FUN_003b4520(...) ((int * (*)(...))FUN_003b4520)(__VA_ARGS__)
#define FUN_003b4580(...) ((void (*)(...))FUN_003b4580)(__VA_ARGS__)
#define FUN_003b45f0(...) ((int * (*)(...))FUN_003b45f0)(__VA_ARGS__)
#define FUN_003b46b0(...) ((int * (*)(...))FUN_003b46b0)(__VA_ARGS__)
#define FUN_003b46f0(...) ((u32 (*)(...))FUN_003b46f0)(__VA_ARGS__)
#define FUN_003b4740(...) ((u32 (*)(...))FUN_003b4740)(__VA_ARGS__)
#define FUN_003b4770(...) ((void (*)(...))FUN_003b4770)(__VA_ARGS__)
#define FUN_003b47b0(...) ((int (*)(...))FUN_003b47b0)(__VA_ARGS__)
#define FUN_003b4920(...) ((void (*)(...))FUN_003b4920)(__VA_ARGS__)
#define FUN_003b49a0(...) ((int * (*)(...))FUN_003b49a0)(__VA_ARGS__)
#define FUN_003b4a20(...) ((void (*)(...))FUN_003b4a20)(__VA_ARGS__)
#define FUN_003b4a90(...) ((void (*)(...))FUN_003b4a90)(__VA_ARGS__)
#define FUN_003b4b40(...) ((void (*)(...))FUN_003b4b40)(__VA_ARGS__)
#define FUN_003b4d10(...) ((void (*)(...))FUN_003b4d10)(__VA_ARGS__)
#define FUN_003b4e90(...) ((void (*)(...))FUN_003b4e90)(__VA_ARGS__)
#define FUN_003b4ea0(...) ((void (*)(...))FUN_003b4ea0)(__VA_ARGS__)
#define FUN_003b4eb0(...) ((void (*)(...))FUN_003b4eb0)(__VA_ARGS__)
#define FUN_003b4ec0(...) ((void (*)(...))FUN_003b4ec0)(__VA_ARGS__)
#define FUN_003b4ed0(...) ((void (*)(...))FUN_003b4ed0)(__VA_ARGS__)
#define FUN_003b4ee0(...) ((void (*)(...))FUN_003b4ee0)(__VA_ARGS__)

#undef FUN_003b41a0
// FUN_003B41A0 NONMATCHING


u32

FUN_003b41a0(u64 param_1,int param_2,int param_3,int param_4,int param_5,long param_6)



{

  int iVar1;

  u32 uVar2;

  long lVar3;

  int iVar4;

  int iVar5;

  u32 uVar6;

  int *piVar7;

  long lVar8;

  

  lVar8 = 0;

  if ((DAT_0095aebc == 0) || (DAT_007ce64c == '\0')) {

    iVar1 = param_4 * param_5;

    if (iVar1 < 0) {

      iVar1 = iVar1 + 1;

    }

    DAT_0095aeb0 = iVar1 >> 1;

    DAT_0095aeb4 = param_2 * param_3;

    DAT_0095aea8 = param_4;

    DAT_0095aeac = param_5;

    DAT_0095aeb8 = DAT_0095aeb4;

    lVar3 = (*DAT_00960178)(DAT_0095aeb4 * 0x20,0x40000);

    DAT_0095aea0 = (int)lVar3;

    DAT_0095aebc = DAT_0095aea0;

    if (lVar3 == 0) {

      FUN_0019d3f0("fmGslCont.c",0x51);

    }

    if (param_6 != 0) {

      lVar8 = (*DAT_00960178)((int)param_6 * DAT_0095aeb8,0x40000);

      DAT_0095aea4 = (u32)lVar8;

      if (lVar8 == 0) {

        FUN_0019d3f0("fmGslCont.c",0x57);

      }

    }

    uVar6 = 0;

    while (uVar6 < DAT_0095aeb8 - 1U) {

      *(u32 *)(DAT_0095aebc + uVar6 * 0x20 + 0x1c) = DAT_0095aebc + (uVar6 + 1) * 0x20;

      uVar6 = uVar6 + 1;

    }

    *(int *)(uVar6 * 0x20 + DAT_0095aebc + 0x1c) = DAT_0095aebc;

    iVar1 = DAT_0095aeb8 + -1;

    while (0 < iVar1) {

      *(int *)(DAT_0095aebc + iVar1 * 0x20 + 0x18) = DAT_0095aebc + (iVar1 + -1) * 0x20;

      iVar1 = iVar1 + -1;

    }

    *(int *)(DAT_0095aebc + 0x18) = DAT_0095aebc + (DAT_0095aeb8 + -1) * 0x20;

    iVar1 = 0;

    for (iVar4 = 0; iVar4 < param_3; iVar4 = iVar4 + 1) {

      for (iVar5 = 0; iVar5 < param_2; iVar5 = iVar5 + 1) {

        piVar7 = (int *)(DAT_0095aebc + iVar1 * 0x20);

        if (piVar7 == (int *)0x0) {

          FUN_003b44a0();

          return 0;

        }

        *piVar7 = iVar1;

        piVar7[1] = iVar5 * param_4 * 0x10;

        piVar7[2] = iVar4 * param_5 * 0x10;

        piVar7[3] = piVar7[1] + param_4 * 0x10;

        piVar7[4] = piVar7[2] + param_5 * 0x10;

        if (lVar8 == 0) {

          piVar7[5] = 0;

        }

        else {

          piVar7[5] = (int)lVar8 + iVar1 * (int)param_6;

        }

        iVar1 = iVar1 + 1;

      }

    }

    uVar2 = 1;

    DAT_007ce64c = '\x01';

  }

  else {

    uVar2 = 0;

  }

  return uVar2;

}
#define FUN_003b41a0(...) ((u32 (*)(...))FUN_003b41a0)(__VA_ARGS__)
#undef FUN_003b44a0
#pragma alias DAT_0095aebc_abs DAT_0095aebc
extern u8 DAT_0095aebc_abs[];
#pragma alias DAT_0095aeb8_abs DAT_0095aeb8
extern u8 DAT_0095aeb8_abs[];
#pragma alias DAT_0095aea0_abs DAT_0095aea0
extern u8 DAT_0095aea0_abs[];
#pragma alias DAT_0095aea4_abs DAT_0095aea4
extern u8 DAT_0095aea4_abs[];
#pragma alias DAT_0096017c_abs DAT_0096017c
extern u8 DAT_0096017c_abs[];
// FUN_003B44A0


u8 FUN_003b44a0(void)
{
  code* vt;

  if (*(u32*)DAT_0095aebc_abs != 0) goto work;
  return 0;
work:
  vt = (code*)DAT_0096017c_abs;
  (*vt)(*(u32*)DAT_0095aea0_abs);
  (*vt)(*(u32*)DAT_0095aea4_abs);
  *(u32*)DAT_0095aebc_abs = 0;
  return 1;
}
#define FUN_003b44a0(...) ((u8 (*)(...))FUN_003b44a0)(__VA_ARGS__)
#undef FUN_003b4520
// FUN_003B4520 NONMATCHING


int * FUN_003b4520(void)



{

  int *piVar1;

  

  piVar1 = *(int **)(DAT_0095aebc + 0x1c);

  if (*piVar1 == 0) {

    piVar1 = (int *)0x0;

  }

  else {

    *(int *)(piVar1[6] + 0x1c) = piVar1[7];

    *(int *)(piVar1[7] + 0x18) = piVar1[6];

    DAT_0095aeb8 = DAT_0095aeb8 + -1;

  }

  return piVar1;

}
#define FUN_003b4520(...) ((int * (*)(...))FUN_003b4520)(__VA_ARGS__)
#undef FUN_003b4580
// FUN_003B4580 NONMATCHING


void FUN_003b4580(int param_1)
{
  int iVar2;
  int iVar1;

  if (param_1 == 0) {
    FUN_0019d3f0("fmGslCont.c",0xc2);
  }
  iVar2 = *(int *)DAT_0095aebc_abs;
  iVar1 = *(int *)(*(int *)DAT_0095aebc_abs + 0x1c);
  *(int *)(param_1 + 0x18) = *(int *)DAT_0095aebc_abs;
  *(int *)(param_1 + 0x1c) = iVar1;
  *(int *)(iVar2 + 0x1c) = param_1;
  *(int *)(iVar1 + 0x18) = param_1;
  *(int *)DAT_0095aeb8_abs = *(int *)DAT_0095aeb8_abs + 1;
  return;


}
#define FUN_003b4580(...) ((void (*)(...))FUN_003b4580)(__VA_ARGS__)
#undef FUN_003b45f0
// FUN_003B45F0


int * FUN_003b45f0(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  int *piVar5;

  int iVar4;

  int *iStack_4;

  

  iStack_4 = (int *)(*DAT_00960178_abs)((param_1 + 8) * (param_2 + 1) + 4,0x40000);

  iVar1 = (int)iStack_4;

  FUN_00521250(iVar1,&iStack_4,4);

  piVar5 = (int *)(iVar1 + 4);

  for (iVar4 = 0; iVar4 < param_2; iVar4 = iVar4 + 1) {

    *piVar5 = iVar4;

    piVar2 = (int *)((int)piVar5 + param_1 + 8);

    piVar5[1] = (int)piVar2;

    piVar5 = piVar2;

  }

  *piVar5 = param_2;

  piVar5[1] = iVar1 + 4;

  return (int *)piVar5[1];

}
#define FUN_003b45f0(...) ((void (*)(...))FUN_003b45f0)(__VA_ARGS__)
#undef FUN_003b46b0
// FUN_003B46B0


int * FUN_003b46b0(int param_1)



{

  int *piVar1;

  int *piVar2;

  

  piVar2 = (int *)param_1;

  piVar1 = (int *)piVar2[1];

  if (*piVar1 == 0) {

    piVar1 = (int *)0x0;

  }

  else {

    piVar2[1] = piVar1[1];

    piVar1[1] = 0;

    piVar1 = piVar1 + 2;

  }

  return piVar1;

}
#define FUN_003b46b0(...) ((int * (*)(...))FUN_003b46b0)(__VA_ARGS__)
#undef FUN_003b46f0
// FUN_003B46F0


u32 FUN_003b46f0(int *param_1,int param_2)



{

  u32 uVar1;

  int *piVar1;

  


  if (param_1 == 0) {

    uVar1 = 0;

  }

  else {

    piVar1 = param_1 - 2;

    if (piVar1[1] != 0) {

      uVar1 = 0;

    }

    else {

      piVar1[1] = *(u32 *)(param_2 + 4);

      *(int *)(param_2 + 4) = (int)piVar1;

      uVar1 = 1;

    }

  }

  return uVar1;

}
#define FUN_003b46f0(...) ((u32 (*)(...))FUN_003b46f0)(__VA_ARGS__)
#undef FUN_003b4740
// FUN_003B4740


u32 FUN_003b4740(int param_1)



{

  (*(void (**)(...))0x0096017c)(*(u32 *)(param_1 + -4));

  return 1;

}
#define FUN_003b4740(...) ((u32 (*)(...))FUN_003b4740)(__VA_ARGS__)
#undef FUN_003b4770
// FUN_003B4770


void FUN_003b4770(int *param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = *param_1 + param_1[1];

  iVar1 = param_1[6];
  iVar3 = iVar2 + iVar1;

  *param_2 = (int)param_1 + *param_1;

  param_2[1] = (int)param_1 + iVar2;

  param_2[2] = (int)param_1 + iVar3;

  return;

}
#define FUN_003b4770(...) ((void (*)(...))FUN_003b4770)(__VA_ARGS__)
#undef FUN_003b47b0
// FUN_003B47B0 NONMATCHING


int FUN_003b47b0(int param_1,int param_2,u64 param_3,int *param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  u32 uVar6;

  int iVar7;

  u32 uVar8;

  int iStack_8;

  u32 uStack_4;

  

  iVar1 = *param_4;

  iVar7 = 0;

  FUN_00521250(&uStack_4,param_4[1] + param_2 * 4,4);

  FUN_00521250(&iStack_8,param_4[1] + (param_2 + 1) * 4,4);

  iVar5 = iVar1 + 2;

  iVar2 = param_4[2];

  uVar6 = uStack_4 >> 4;

  uVar8 = (int)(*(u16 *)(iVar2 + uVar6 * 2) | 0x10000) >> (uStack_4 & 0xf);

  iStack_8 = iStack_8 - uStack_4;

  iVar3 = iVar5;

  do {

    iVar4 = iVar1 + (u32)*(u16 *)(iVar3 + (uVar8 & 1) * 2) * 6;

    iVar3 = iVar4 + 2;

    if (*(short *)(iVar4 + 2) == 0) {

      FUN_00521250(param_1 + iVar7,iVar4 + 4,1);

      iVar7 = iVar7 + 1;

      iVar3 = iVar5;

    }

    uVar8 = uVar8 >> 1;

    if (uVar8 == 1) {

      uVar6 = uVar6 + 1;

      uVar8 = *(u16 *)(iVar2 + uVar6 * 2) | 0x10000;

    }

    iStack_8 = iStack_8 + -1;

  } while (iStack_8 != 0);

  DAT_007ce650 = iVar7;

  return iVar7;

}
#define FUN_003b47b0(...) ((int (*)(...))FUN_003b47b0)(__VA_ARGS__)
#undef FUN_003b4920
// FUN_003B4920 NONMATCHING


void FUN_003b4920(u32 *param_1,u32 *param_2,int param_3,int param_4)



{

  u32 *puVar1;

  u32 *puVar2;

  u32 *puVar3;

  char cVar4;

  

  cVar4 = '\0';

  puVar2 = (u32 *)0x0;

  puVar1 = param_2;

  do {

    puVar3 = puVar1;

    *puVar3 = (u32)puVar2;

    puVar1 = (u32 *)((int)puVar3 + param_4);

    puVar3[1] = (u32)puVar1;

    puVar3[2] = (int)cVar4;

    param_3 = param_3 + -1;

    cVar4 = cVar4 + '\x01';

    puVar2 = puVar3;

  } while (1 < param_3);

  *puVar1 = (u32)puVar3;

  puVar1[1] = 0;

  puVar1[2] = (int)cVar4;

  *param_1 = 0;

  param_1[1] = 0;

  param_1[2] = (u32)param_2;

  param_1[3] = (u32)puVar1;

  return;

}
#define FUN_003b4920(...) ((void (*)(...))FUN_003b4920)(__VA_ARGS__)
#undef FUN_003b49a0
// FUN_003B49A0


int * FUN_003b49a0(int *param_1)



{

  u32 *puVar1;

  int *piVar2;

  

  piVar2 = (int *)param_1[2];

  if (piVar2 == (int *)0x0) {

    piVar2 = (int *)0x0;

  }

  else {

    puVar1 = (u32 *)piVar2[1];

    if (*param_1 != 0) {

      *piVar2 = param_1[1];

      *(int **)(param_1[1] + 4) = piVar2;

    }

    else {

      *piVar2 = 0;

      *param_1 = (int)piVar2;

    }

    piVar2[1] = 0;

    param_1[1] = (int)piVar2;

    if (puVar1 != (u32 *)0x0) {

      *puVar1 = 0;

    }

    else {

      param_1[3] = 0;

    }

    param_1[2] = (int)puVar1;

  }

  return piVar2;

}
#define FUN_003b49a0(...) ((int * (*)(...))FUN_003b49a0)(__VA_ARGS__)
#undef FUN_003b4a20
// FUN_003B4A20


void FUN_003b4a20(int *param_1,u32 *param_2)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = *param_1;

  piVar2 = (int *)param_1[1];

  if (iVar1 != 0) {

    *(int **)(iVar1 + 4) = piVar2;

  }

  else {

    *param_2 = (u32)piVar2;

  }

  if (piVar2 != (int *)0x0) {

    *piVar2 = iVar1;

  }

  else {

    param_2[1] = iVar1;

  }

  param_1[1] = 0;

  iVar1 = param_2[3];

  *param_1 = iVar1;

  if (iVar1 != 0) {

    *(int **)(iVar1 + 4) = param_1;

  }

      param_2[3] = (u32)param_1;

  if (param_2[2] == 0) {

    param_2[2] = (u32)param_1;

  }

  return;

}
#define FUN_003b4a20(...) ((void (*)(...))FUN_003b4a20)(__VA_ARGS__)
#undef FUN_003b4a90
// FUN_003B4A90 NONMATCHING


void FUN_003b4a90(int *param_1,int param_2,int param_3,int param_4,int param_5,int *param_6,

                 int param_7)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  iVar4 = 0xff0000;

  

  for (; 0 < param_7; param_7 = param_7 + -1) {

    iVar3 = param_2 * *param_6;

    iVar2 = param_3 * param_6[1];

    iVar1 = param_4 * param_6[2];

    if (iVar4 < iVar3) {
      iVar3 = iVar4;

    }

    if (iVar4 < iVar2) {
      iVar2 = iVar4;

    }

    if (iVar4 < iVar1) {
      iVar1 = iVar4;

    }

    *param_1 = iVar3 >> 0x10;

    param_1[1] = iVar2 >> 0x10;

    param_1[2] = iVar1 >> 0x10;

    param_1[3] = param_5;

    param_6 = param_6 + 4;

    param_1 = param_1 + 4;

  }

  return;

}
#define FUN_003b4a90(...) ((void (*)(...))FUN_003b4a90)(__VA_ARGS__)
#undef FUN_003b4b40
// FUN_003B4B40 NONMATCHING


void FUN_003b4b40(int param_1,int param_2,u8 *param_3,u8 *param_4)



{

  u32 uVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int *piVar5;

  float fVar6;

  

  iVar2 = FUN_00198590();

  uVar1 = DAT_00960088;

  fVar6 = *(float *)(iVar2 + 0x80);

  for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {

    piVar5 = (int *)(param_1 + (u32)*param_3 * 8);

    piVar4 = (int *)(param_2 + (u32)*param_4 * 0x10);

    iVar3 = iVar2 * 0x40;

    *(float *)(&DAT_0095aec0 + iVar3) = (float)(*piVar5 >> 4);

    *(float *)(&DAT_0095aec4 + iVar3) = (float)(piVar5[1] >> 3);

    *(u32 *)(&DAT_0095aec8 + iVar3) = uVar1;

    *(float *)(&DAT_0095aee0 + iVar3) = (float)*piVar4;

    *(float *)(&DAT_0095aee4 + iVar3) = (float)piVar4[1];

    *(float *)(&DAT_0095aee8 + iVar3) = (float)piVar4[2];

    *(float *)(&DAT_0095aeec + iVar3) = (float)piVar4[3];

    *(float *)(&DAT_0095aed8 + iVar3) = 1.0 / fVar6;

    param_3 = param_3 + 1;

    param_4 = param_4 + 1;

  }

  (*DAT_00960090)(1,0);

  (*DAT_00960090)(7,2);

  (*DAT_00960090)(0xc,1);

  (*DAT_00960090)(10,3);

  (*DAT_00960090)(0xb,6);

  FUN_004d7f60(2,0x44);

  FUN_004d7f60(3,0x717fb);

  (*DAT_009600a0)(5,0x95aec0,4);

  return;

}
#define FUN_003b4b40(...) ((void (*)(...))FUN_003b4b40)(__VA_ARGS__)
#undef FUN_003b4d10
// FUN_003B4D10 NONMATCHING


void FUN_003b4d10(int *param_1,u32 *param_2,u64 param_3,int param_4,u64 param_5

                 )



{

  int iVar1;

  u32 uStack_40;

  u32 uStack_3c;

  u32 uStack_38;

  u32 uStack_34;

  u32 uStack_30;

  u32 uStack_2c;

  u32 uStack_28;

  u32 uStack_24;

  int iStack_20;

  int iStack_1c;

  int iStack_18;

  int iStack_14;

  int iStack_10;

  int iStack_c;

  int iStack_8;

  int iStack_4;

  

  iStack_20 = *param_1;

  iVar1 = (param_1[2] - iStack_20) + param_4 * -2;

  uStack_40 = *param_2;

  uStack_3c = param_2[1];

  uStack_38 = param_2[2];

  uStack_34 = 0;

  uStack_24 = param_2[3];

  iStack_1c = param_1[1];

  iStack_18 = iStack_20 + param_4;

  iStack_c = param_1[3];

  uStack_30 = uStack_40;

  uStack_2c = uStack_3c;

  uStack_28 = uStack_38;

  iStack_14 = iStack_1c;

  iStack_10 = iStack_18;

  iStack_8 = iStack_20;

  iStack_4 = iStack_c;

  FUN_003b4b40(&iStack_20,&uStack_40,0x7cd52c,0x6a2a28,param_3,param_5);

  iStack_20 = iStack_20 + param_4;

  iStack_18 = iStack_18 + iVar1;

  iStack_10 = iStack_10 + iVar1;

  iStack_8 = iStack_8 + param_4;

  FUN_003b4b40(&iStack_20,&uStack_40,0x7cd52c,0x6a2a2c,param_3,param_5);

  iStack_20 = iStack_20 + iVar1;

  iStack_18 = iStack_18 + param_4;

  iStack_10 = iStack_10 + param_4;

  iStack_8 = iStack_8 + iVar1;

  FUN_003b4b40(&iStack_20,&uStack_40,0x7cd52c,0x6a2a30,param_3,param_5);

  return;

}
#define FUN_003b4d10(...) ((void (*)(...))FUN_003b4d10)(__VA_ARGS__)
#undef FUN_003b4e90
// FUN_003B4E90


void FUN_003b4e90(void)



{

  return;

}
#define FUN_003b4e90(...) ((void (*)(...))FUN_003b4e90)(__VA_ARGS__)
#undef FUN_003b4ea0
// FUN_003B4EA0


void FUN_003b4ea0(void)



{

  return;

}
#define FUN_003b4ea0(...) ((void (*)(...))FUN_003b4ea0)(__VA_ARGS__)
#undef FUN_003b4eb0
// FUN_003B4EB0


void FUN_003b4eb0(void)



{

  return;

}
#define FUN_003b4eb0(...) ((void (*)(...))FUN_003b4eb0)(__VA_ARGS__)
#undef FUN_003b4ec0
// FUN_003B4EC0


void FUN_003b4ec0(void)



{

  return;

}
#define FUN_003b4ec0(...) ((void (*)(...))FUN_003b4ec0)(__VA_ARGS__)
#undef FUN_003b4ed0
// FUN_003B4ED0


void FUN_003b4ed0(void)



{

  return;

}
#define FUN_003b4ed0(...) ((void (*)(...))FUN_003b4ed0)(__VA_ARGS__)
#undef FUN_003b4ee0
// FUN_003B4EE0


void FUN_003b4ee0(void)



{

  u32 uVar1;

  u32 *puVar2;

  u32 uVar3;

  

  FUN_003c7270();

  puVar2 = (u32 *)FUN_003cf120();

  uVar3 = FUN_00194e10_fmgsl((void*)&DAT_007cd530,0x18b0,0,0,
                             (code)FUN_003cfe50,0,0);

  *puVar2 = uVar3;

  FUN_003af7a0(0x100,0x100);

  FUN_00194e10_fmgsl((void*)&DAT_007cd538,0x1064,0,0,
                      (code)FUN_003b18c0,
                      (code)FUN_003afa40,0);

  FUN_003a4ce0();

  FUN_003c88d0();

  uVar1 = FUN_00100d80_fmgsl(DAT_006a2a40,0);
  FUN_001023a0_fmgsl(uVar1);

  DAT_007ce654 = FUN_00112370_fmgsl(DAT_006a2a40);

}
#define FUN_003b4ee0(...) ((void (*)(...))FUN_003b4ee0)(__VA_ARGS__)
