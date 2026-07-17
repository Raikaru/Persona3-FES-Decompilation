#include "temporary.h"
typedef int (*code)();
/* FUSION_EXACT_PROTOS */
void FUN_0040e300(u64 param_1,u32 param_2);
void FUN_0040e360(void);
void FUN_0040e390(void);
void FUN_0040e3c0(u32 param_1,int param_2,int param_3,char param_4,int param_5,int param_6,int param_7);
void FUN_0040e3f0(float param_1,float param_2,float param_3,float param_4,int param_5,int param_6,
                   char param_7,int param_8,int param_9,int param_10,int param_11);
void FUN_0040e420(float param_1,float param_2,float param_3,float param_4,int param_5,int param_6,
                   char param_7,int param_8,int param_9,int param_10,int param_11);
u64 FUN_0040e450(int param_1);
u32 FUN_0040e4f0(int *param_1);
void FUN_0040e580(long param_1);
u64 FUN_0040e610(u32 param_1,int param_2,int param_3,char param_4,int param_5, int param_6, int param_7);
u64 FUN_0040e710(u32 param_1,u32 param_2,float param_3,float param_4,int param_5, int param_6,char param_7,int param_8,int param_9,int param_10,u16 param_11, u16 param_12);
u64 FUN_0040e930(u32 param_1,u32 param_2,float param_3,float param_4,int param_5, int param_6,char param_7,int param_8,int param_9,int param_10,u16 param_11, u16 param_12);
void FUN_0040eb50(u64 param_1,u64 param_2,u32 param_3);
void FUN_0040ebc0(void);
void FUN_0040ec20(u32 param_1,int param_2,u32 param_3,u32 param_4,u32 param_5,u64 param_6,u32 param_7,int param_8);
u32 FUN_0040ec50();
void FUN_0040eef0(u32 param_1,int param_2,int param_3,u64 param_4,int param_5, int param_6);
u32 FUN_0040f030(int param_1,int param_2,long param_3);
u32 FUN_0040f430(int param_1,int param_2);
u32 FUN_0040f5d0(u64 param_1,int param_2,long param_3);
u64 FUN_0040fab0(u64 param_1,int param_2);
u64 FUN_0040fb90(u64 param_1,int param_2,long param_3);
/* FUSION_GLOBALS */
u32 DAT_006af960;
u32 DAT_006af980;
u32 DAT_006af9a0;
u16 DAT_006af9c0[];
u32 DAT_006af9d8;
u32 DAT_006af9dc;
u32 DAT_006af9e0;
u32 DAT_006af9f0;
u32 DAT_006afa70;
int DAT_006afaf0[];
u32 DAT_006afb10;
u32 DAT_007ce69c;
s32 DAT_007ce6a0;
code DAT_00960178;
code DAT_0096017c;
#include "Kosaka/k_assert.h"


// FUN_0040E300 NONMATCHING


void FUN_0040e300(u64 param_1,u32 param_2)
{
  if (DAT_007ce6a0 != 0) {
    FUN_0040e580(param_1);
  }
  DAT_007ce6a0 = FUN_0040e450(param_1);
  DAT_007ce69c = param_2;
}

// FUN_0040E360


void FUN_0040e360(void)



{


  FUN_0040e580(DAT_007ce6a0);
  DAT_007ce6a0 = 0;

  DAT_007ce69c = 0;

  return;

}



// FUN_0040E390
void FUN_0040e390(void)
{
  FUN_0040e4f0((int *)DAT_007ce6a0);
}

// FUN_0040E3C0


void FUN_0040e3c0(u32 param_1,int param_2,int param_3,char param_4,int param_5,int param_6,
                   int param_7)
{
  FUN_0040e610(param_1,param_2,param_3,param_4,param_5,DAT_007ce6a0,param_7);
}

// FUN_0040E3F0
void FUN_0040e3f0(float param_1,float param_2,float param_3,float param_4,int param_5,int param_6,
                   char param_7,int param_8,int param_9,int param_10,int param_11)
{
  __asm__ volatile (
      ".set noreorder ;"
      ".word 0x27bdfff0 ;"
      ".word 0xffbf0000 ;"
      ".word 0x0120102d ;"
      ".word 0x0140582d ;"
      ".word 0x8f89b9b0 ;"
      ".word 0x0040502d ;"
      ".word 0x0c1039c4 ;"
      ".word 0x00000000 ;"
      ".word 0xdfbf0000 ;"
      ".word 0x27bd0010 ;"
      ".set reorder");
}

// FUN_0040E420
void FUN_0040e420(float param_1,float param_2,float param_3,float param_4,int param_5,int param_6,
                   char param_7,int param_8,int param_9,int param_10,int param_11)
{
  __asm__ volatile (
      ".set noreorder ;"
      ".word 0x27bdfff0 ;"
      ".word 0xffbf0000 ;"
      ".word 0x0120102d ;"
      ".word 0x0140582d ;"
      ".word 0x8f89b9b0 ;"
      ".word 0x0040502d ;"
      ".word 0x0c103a4c ;"
      ".word 0x00000000 ;"
      ".word 0xdfbf0000 ;"
      ".word 0x27bd0010 ;"
      ".set reorder");
}

// FUN_0040E450 NONMATCHING
u64 FUN_0040e450(int param_1)
{
  u64 uVar1;
  int iVar2;
  u32 *puVar3;
  iVar2 = *(int *)(param_1 + 4) * 4 + 0x14;

  uVar1 = (*DAT_00960178)(iVar2,0x40000);

  memset((void *)uVar1,0,iVar2);

  puVar3 = (u32 *)uVar1;

  puVar3[1] = param_1;

  puVar3[2] = (u32)(puVar3 + 5);

  puVar3[3] = *(u32 *)(param_1 + 8);

  puVar3[4] = *(u32 *)(param_1 + 0xc);

  *puVar3 = 0;

  return uVar1;

}

// FUN_0040E4F0 NONMATCHING


u32 FUN_0040e4f0(int *param_1)



{

  int iVar1;

  u32 uVar2;

  u64 uVar3;

  u8 auStack_4 [4];

  

  do {

    iVar1 = *param_1;

    uVar3 = H_Cdvd_CacheFindFile(*(u32 *)(*(int *)param_1[1] + iVar1 * 4),auStack_4);

    uVar2 = func_00112420(uVar3);

    *(u32 *)(param_1[2] + iVar1 * 4) = uVar2;

    iVar1 = *param_1;

    *param_1 = iVar1 + 1;

  } while (iVar1 + 1 < *(int *)(param_1[1] + 4));

  return 1;

}

// FUN_0040E580 NONMATCHING


void FUN_0040e580(long param_1)



{

  int iVar1;

  

  if (param_1 != 0) {

    for (iVar1 = 0; iVar1 < *(int *)(*(int *)((int)param_1 + 4) + 4); iVar1 = iVar1 + 1) {

      func_001124b0(*(u32 *)(*(int *)((int)param_1 + 8) + iVar1 * 4));

    }

    (*DAT_0096017c)(param_1);

  }

  return;

}

// FUN_0040E610 NONMATCHING


u64

FUN_0040e610(u32 param_1,int param_2,int param_3,char param_4,int param_5,int param_6,

            int param_7)



{

  int iVar1;

  u64 uVar2;

  char *pcVar3;

  

  pcVar3 = (char *)(*(int *)(param_7 + 0xc) + param_5 * 8);

  uVar2 = FUN_001158b0(0,*(u32 *)(*(int *)(param_7 + 8) + *pcVar3 * 4),

                       *(short *)(pcVar3 + 2) + param_6);

  iVar1 = (int)uVar2;

  *(float *)(iVar1 + 0x10) = (float)(param_2 + *(short *)(pcVar3 + 4));

  *(float *)(iVar1 + 0x14) = (float)(param_3 + *(short *)(pcVar3 + 6));

  *(u32 *)(iVar1 + 0x2c) = param_1;

  *(char *)(iVar1 + 0x19) = -1 - param_4;

  func_001127d0(uVar2,1);

  FUN_00115980(uVar2);

  return 0;

}

// FUN_0040E710 NONMATCHING


u64


FUN_0040e710(u32 param_1,u32 param_2,float param_3,float param_4,int param_5,

            int param_6,char param_7,int param_8,int param_9,int param_10,u16 param_11,

            u16 param_12)



{

  int iVar1;

  u64 uVar2;

  char *pcVar3;

  u16 uVar4;

  

  pcVar3 = (char *)(*(int *)(param_10 + 0xc) + param_8 * 8);

  uVar2 = FUN_001158b0(0,*(u32 *)(*(int *)(param_10 + 8) + *pcVar3 * 4),

                       *(short *)(pcVar3 + 2) + param_9);

  iVar1 = (int)uVar2;
  *(float *)(iVar1 + 0x10) = (float)(int)*(short *)(pcVar3 + 4) * param_3 + (float)param_5 + 0.0;

  *(float *)(iVar1 + 0x14) = (float)(int)*(short *)(pcVar3 + 6) * param_4 + (float)param_6 + 0.0;

  *(u32 *)(iVar1 + 0x2c) = param_1;


  *(u16 *)(iVar1 + 0x24) = param_11;

  *(u16 *)(iVar1 + 0x26) = param_12;

  *(u32 *)(iVar1 + 0x20) = param_2;

  param_3 = param_3 * 4096.0;

  if (param_3 < 2.1474836e+09) {

    uVar4 = (u16)(int)param_3;

  }

  else {

    uVar4 = (u16)(int)(param_3 - 2.1474836e+09);

  }

  *(u16 *)(iVar1 + 0x28) = uVar4;

  param_4 = param_4 * 4096.0;

  if (param_4 < 2.1474836e+09) {

    uVar4 = (u16)(int)param_4;

  }

  else {

    uVar4 = (u16)(int)(param_4 - 2.1474836e+09);

  }

  *(u16 *)(iVar1 + 0x2a) = uVar4;

  func_001127d0(uVar2,1);

  FUN_00115980(uVar2);

  return 0;

}

// FUN_0040E930 NONMATCHING


u64


FUN_0040e930(u32 param_1,u32 param_2,float param_3,float param_4,int param_5,

            int param_6,char param_7,int param_8,int param_9,int param_10,u16 param_11,

            u16 param_12)



{

  int iVar1;

  u64 uVar2;

  char *pcVar3;

  u16 uVar4;

  

  pcVar3 = (char *)(*(int *)(param_10 + 0xc) + param_8 * 8);

  uVar2 = FUN_001158b0(0,*(u32 *)(*(int *)(param_10 + 8) + *pcVar3 * 4),

                       *(short *)(pcVar3 + 2) + param_9);

  iVar1 = (int)uVar2;
  *(float *)(iVar1 + 0x10) = (float)(int)*(short *)(pcVar3 + 4) * param_3 + (float)param_5 + 0.0;

  *(float *)(iVar1 + 0x14) = (float)(int)*(short *)(pcVar3 + 6) * param_4 + (float)param_6 + 0.0;

  *(u32 *)(iVar1 + 0x2c) = param_1;


  *(u16 *)(iVar1 + 0x24) = param_11;

  *(u16 *)(iVar1 + 0x26) = param_12;

  *(u32 *)(iVar1 + 0x20) = param_2;

  param_3 = param_3 * 4096.0;

  if (param_3 < 2.1474836e+09) {

    uVar4 = (u16)(int)param_3;

  }

  else {

    uVar4 = (u16)(int)(param_3 - 2.1474836e+09);

  }

  *(u16 *)(iVar1 + 0x28) = uVar4;

  param_4 = param_4 * 4096.0;

  if (param_4 < 2.1474836e+09) {

    uVar4 = (u16)(int)param_4;

  }

  else {

    uVar4 = (u16)(int)(param_4 - 2.1474836e+09);

  }

  *(u16 *)(iVar1 + 0x2a) = uVar4;

  func_001127d0(uVar2,0);

  FUN_00115980(uVar2);

  return 0;

}

// FUN_0040EB50 NONMATCHING


void FUN_0040eb50(u64 param_1,u64 param_2,u32 param_3)



{

  u32 uVar1;

  int iVar2;

  u32 *puVar3;

  u32 *puVar4;

  u32 auStack_20 [8];

  

  puVar4 = &DAT_006af960;

  puVar3 = auStack_20;

  iVar2 = 5;

  do {

    uVar1 = *puVar4;

    puVar4 = puVar4 + 1;

    iVar2 = iVar2 + -1;

    *puVar3 = uVar1;

    puVar3 = puVar3 + 1;

  } while (0 < iVar2);


  return;

}

// FUN_0040EBC0 NONMATCHING


void FUN_0040ebc0(void)



{

  u32 uVar1;

  int iVar2;

  u32 *puVar3;

  u32 *puVar4;

  u32 auStack_20 [8];

  

  puVar4 = &DAT_006af980;

  puVar3 = auStack_20;

  iVar2 = 5;

  do {

    uVar1 = *puVar4;

    puVar4 = puVar4 + 1;

    iVar2 = iVar2 + -1;

    *puVar3 = uVar1;

    puVar3 = puVar3 + 1;

  } while (0 < iVar2);


  return;

}

// FUN_0040EC20


void FUN_0040ec20(u32 param_1,int param_2,u32 param_3,u32 param_4,u32 param_5,u64 param_6,
                   u32 param_7,int param_8)
{
  FUN_0040ec50(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,0);
}

// FUN_0040EC50 NONMATCHING


u32 FUN_0040ec50(u32 param_1,int param_2,u32 param_3,u32 param_4,

                 u32 param_5,u64 param_6,u32 param_7,int param_8,code *param_9,

                 u32 param_10)



{

  char cVar1;

  u32 uVar2;

  char *pcVar3;

  u32 uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  char acStack_20 [32];

  

  iVar6 = 0;

  iVar5 = 0;

  memset(acStack_20,0,0x20);

  uVar2 = strlen((char *)param_6);

  uVar4 = 0;

  iVar7 = 0;

  do {

    pcVar3 = (char *)((int)param_6 + uVar4);

    if (*pcVar3 == ' ') {

      acStack_20[iVar7] = -1;

    }

    else {

      if (((((param_7 & 8) != 0) && (3 < uVar2)) && (uVar4 != 0)) && ((int)(uVar2 - uVar4) % 3 == 0)

         ) {

        acStack_20[iVar7] = '\n';

        iVar5 = iVar5 + 1;

        iVar7 = iVar7 + 1;

      }

      cVar1 = *pcVar3 + -0x30;

      acStack_20[iVar7] = cVar1;

      if (cVar1 < '\0') {

        K_Assert((const char *)0x6af950,0x115);

      }

      if ('\t' < acStack_20[iVar7]) {

        K_Assert((const char *)0x6af950,0x116);

      }

    }

    uVar4 = uVar4 + 1;

    iVar7 = iVar7 + 1;

  } while (uVar4 < uVar2);

  uVar2 = uVar2 * param_8 + iVar5 * 6;

  if ((param_7 & 1) == 0) {

    if ((param_7 & 2) != 0) {

      param_2 = param_2 - (uVar2 >> 1);

    }

  }

  else {

    param_2 = param_2 - uVar2;

  }

  for (iVar5 = 0; iVar5 < iVar7; iVar5 = iVar5 + 1) {

    cVar1 = acStack_20[iVar5];

    if (cVar1 != -1) {

      (*param_9)(param_1,param_2 + iVar6,param_3,param_4,param_5,cVar1,iVar5,iVar7,param_10);

    }

    if (acStack_20[iVar5] == '\n') {

      iVar6 = iVar6 + 5;

    }

    else {

      if (acStack_20[iVar5 + 1] == '\n') {

        iVar6 = iVar6 + 1;

      }

      iVar6 = iVar6 + param_8;

    }

  }

  return uVar2;

}

// FUN_0040EEF0 NONMATCHING


void FUN_0040eef0(u32 param_1,int param_2,int param_3,u64 param_4,int param_5,

                 int param_6)



{

  u32 uVar1;

  u64 uVar2;

  int iVar3;

  u32 *puVar4;

  u32 *puVar5;

  u32 auStack_20 [8];

  

  puVar5 = &DAT_006af9a0;

  puVar4 = auStack_20;

  iVar3 = 5;

  do {

    uVar1 = *puVar5;

    puVar5 = puVar5 + 1;

    iVar3 = iVar3 + -1;

    *puVar4 = uVar1;

    puVar4 = puVar4 + 1;

  } while (0 < iVar3);

  uVar2 = H_Maestro_001120a0(auStack_20[param_5]);

  if (param_5 - 3U < 2) {

    param_6 = param_6 + 0xb;

  }

  uVar2 = FUN_001158b0(0,uVar2,param_6);

  iVar3 = (int)uVar2;

  *(float *)(iVar3 + 0x10) = (float)param_2;

  *(float *)(iVar3 + 0x14) = (float)param_3;

  *(u32 *)(iVar3 + 0x2c) = param_1;

  *(char *)(iVar3 + 0x19) = -1 - (char)param_4;

  *(char *)(iVar3 + 0x30) = (char)((u32)param_4 >> 0x18);

  *(char *)(iVar3 + 0x31) = (char)((u32)param_4 >> 0x10);

  *(char *)(iVar3 + 0x32) = (char)((u32)param_4 >> 8);

  func_001127d0(uVar2,1);

  FUN_00115980(uVar2);

  return;

}

// FUN_0040F030 NONMATCHING


u32 FUN_0040f030(int param_1,int param_2,long param_3)



{

  u16 uVar1;

  u16 uVar2;

  u32 *puVar3;

  u32 uVar4;

  int iVar5;

  u32 uVar6;

  long lVar7;

  int iVar8;

  u16 *puVar9;

  u16 *puVar10;

  u32 *puVar11;

  int iVar12;

  short sVar13;

  u16 auStack_20 [16];

  

  puVar3 = *(u32 **)(param_2 + 0xc);

  puVar10 = DAT_006af9c0;

  puVar9 = auStack_20;

  iVar8 = 6;

  do {

    uVar1 = *puVar10;

    uVar2 = puVar10[1];

    puVar10 = puVar10 + 2;

    iVar8 = iVar8 + -1;

    *puVar9 = uVar1;

    puVar9[1] = uVar2;

    puVar9 = puVar9 + 2;

  } while (0 < iVar8);

  lVar7 = FUN_003e6d70();

  if (lVar7 == 0) {

    uVar6 = 2;

  }

  else {

    if (param_3 != 0) {

      sVar13 = *(short *)((int)param_3 + 6);

      if (sVar13 == 4) {

        uVar4 = *puVar3;

        *puVar3 = uVar4 | 2;

        *puVar3 = uVar4 | 10;

        uVar4 = puVar3[5];

        puVar3[5] = uVar4 | 2;

        puVar3[5] = uVar4 | 10;

      }

      else if ((sVar13 != 2) && (sVar13 == 1)) {

        memset(puVar3,0,0x28);

        *(u16 *)(puVar3 + 2) = 0x140;

        *(u16 *)(puVar3 + 1) = 0x140;

        *(u16 *)((int)puVar3 + 6) = auStack_20[*(int *)(param_1 + 0x1c) * 4];

        *(u16 *)((int)puVar3 + 0xe) = auStack_20[*(int *)(param_1 + 0x1c) * 4 + 1];

        uVar4 = *puVar3;

        *puVar3 = uVar4 | 1;

        *puVar3 = uVar4 & 0xfffffff7 | 1;

        *(u16 *)(puVar3 + 7) = 0x280;

        *(u16 *)(puVar3 + 6) = 0x280;

        *(u16 *)((int)puVar3 + 0x1a) = auStack_20[*(int *)(param_1 + 0x1c) * 4];

        *(u16 *)(puVar3 + 9) = 0x30;

        *(u16 *)((int)puVar3 + 0x22) = auStack_20[*(int *)(param_1 + 0x1c) * 4 + 1];

        uVar4 = puVar3[5];

        puVar3[5] = uVar4 | 4;

        puVar3[5] = uVar4 & 0xfffffff7 | 4;

        puVar3[10] = 0;

      }

    }

    uVar4 = puVar3[10];

    if (((uVar4 != 2) && (uVar4 != 1)) && (uVar4 == 0)) {

      iVar8 = 0;

      for (iVar12 = 0; iVar12 < 2; iVar12 = iVar12 + 1) {

        puVar11 = puVar3 + iVar12 * 5;

        if ((*puVar11 & 4) == 0) {

          *(short *)(puVar11 + 4) = (short)puVar11[4] + 1;

          if (((short)puVar11[1] < 0x65) && ((*puVar11 & 2) == 0)) {

            *puVar11 = *puVar11 | 2;

          }

          iVar5 = (short)puVar11[4] * 5;

          sVar13 = (short)(iVar5 >> 1);

          if (iVar5 < 0) {

            sVar13 = (short)(iVar5 + 1 >> 1);

          }

          *(short *)(puVar11 + 1) = (short)puVar11[2] - sVar13;

          if ((*puVar11 & 1) == 0) {

            if ((*puVar11 & 2) != 0) {

              sVar13 = *(short *)((int)puVar11 + 0x12) + 1;

              *(short *)((int)puVar11 + 0x12) = sVar13;

              *(short *)(puVar11 + 3) =

                   *(short *)((int)puVar11 + 0xe) -

                   (short)(((int)*(short *)((int)puVar11 + 0xe) * (int)sVar13) / 10);

              if (9 < *(short *)((int)puVar11 + 0x12)) {

                uVar4 = *puVar11;

                *puVar11 = uVar4 & 0xfffffffd;

                *puVar11 = uVar4 & 0xfffffffd | 4;

                *(u16 *)(puVar11 + 3) = 0;

                *(u16 *)((int)puVar11 + 0x12) = 0;

                *(u16 *)(puVar11 + 4) = auStack_20[*(int *)(param_1 + 0x1c) * 4 + 2];

              }

            }

          }

          else {

            sVar13 = *(short *)((int)puVar11 + 0x12) + 1;

            *(short *)((int)puVar11 + 0x12) = sVar13;

            *(short *)(puVar11 + 3) =

                 (short)(((int)*(short *)((int)puVar11 + 0xe) * (int)sVar13) / 10);

            if (9 < *(short *)((int)puVar11 + 0x12)) {

              *puVar11 = *puVar11 & 0xfffffffe;

              *(u16 *)(puVar11 + 3) = *(u16 *)((int)puVar11 + 0xe);

              *(u16 *)((int)puVar11 + 0x12) = 0;

            }

          }

        }

        else if ((*puVar11 & 8) == 0) {

          sVar13 = (short)puVar11[4] + -1;

          *(short *)(puVar11 + 4) = sVar13;

          if (sVar13 < 1) {

            *(u16 *)(puVar11 + 4) = 0;

            uVar4 = *puVar11;

            *puVar11 = uVar4 & 0xfffffffb;

            *puVar11 = uVar4 & 0xfffffffb | 1;

            *(u16 *)(puVar11 + 2) = 0x280;

            *(u16 *)(puVar11 + 1) = 0x280;

          }

        }

        else {

          iVar8 = iVar8 + 1;

        }

      }

      if (1 < iVar8) {

        puVar3[10] = 1;

        return 2;

      }

    }

    uVar6 = 1;

  }

  return uVar6;

}

// FUN_0040F430 NONMATCHING


u32 FUN_0040f430(int param_1,int param_2)



{

  int iVar1;

  u32 uVar2;

  int iVar3;

  long lVar4;

  int iVar5;

  u32 auStack_10 [4];

  

  iVar1 = *(int *)(param_2 + 0xc);

  auStack_10[0] = DAT_006af9d8;

  auStack_10[1] = DAT_006af9dc;

  auStack_10[2] = DAT_006af9e0;

  lVar4 = FUN_003e6d70();

  if (lVar4 == 0) {

    uVar2 = 2;

  }

  else {

    if (*(int *)(param_1 + 0x1c) == 2) {

      for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {

        iVar3 = iVar1 + iVar5 * 0x14;

        ((void (*)(...))FUN_0040e3c0)(0,*(u16 *)(iVar3 + 4),*(u16 *)(iVar3 + 6),

                     *(u8 *)(iVar3 + 0xc),0x56,0);

        ((void (*)(...))FUN_0040e3c0)(0,*(u16 *)(iVar3 + 4),*(u16 *)(iVar3 + 6),

                     *(u8 *)(iVar3 + 0xc),0x57,0);

        ((void (*)(...))FUN_0040e3c0)(0,*(u16 *)(iVar3 + 4),*(u16 *)(iVar3 + 6),

                     *(u8 *)(iVar3 + 0xc),0x58,0);

        ((void (*)(...))FUN_0040e3c0)(0,*(u16 *)(iVar3 + 4),*(u16 *)(iVar3 + 6),

                     *(u8 *)(iVar3 + 0xc),0x59,0);

      }

    }

    else {

      for (iVar5 = 0; iVar5 < 2; iVar5 = iVar5 + 1) {

        iVar3 = iVar1 + iVar5 * 0x14;

        ((void (*)(...))FUN_0040e3c0)(0,*(u16 *)(iVar3 + 4),*(u16 *)(iVar3 + 6),

                     *(u8 *)(iVar3 + 0xc),auStack_10[*(int *)(param_1 + 0x1c)],0);

      }

    }

    uVar2 = 0;

  }

  return uVar2;

}

// FUN_0040F5D0 NONMATCHING


u32 FUN_0040f5d0(u64 param_1,int param_2,long param_3)



{

  short sVar1;

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

  puVar9 = &DAT_006af9f0;

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

  puVar9 = &DAT_006afa70;

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

  return uVar4;

}

// FUN_0040FAB0 NONMATCHING


u64 FUN_0040fab0(u64 param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  short *psVar4;

  int iVar5;

  int *piVar6;

  int *piVar7;

  int aiStack_20 [8];

  

  iVar1 = *(int *)(param_2 + 0xc);

  piVar7 = (int *)&DAT_006afaf0;

  piVar6 = aiStack_20;

  iVar5 = 4;

  do {

    iVar2 = *piVar7;

    iVar3 = piVar7[1];

    piVar7 = piVar7 + 2;

    iVar5 = iVar5 + -1;

    *piVar6 = iVar2;

    piVar6[1] = iVar3;

    piVar6 = piVar6 + 2;

  } while (0 < iVar5);

  for (iVar5 = 0; iVar5 < 8; iVar5 = iVar5 + 1) {

    psVar4 = (short *)(iVar1 + aiStack_20[iVar5] * 0xc);

    ((void (*)(...))FUN_0040e3f0)(0,0,*(u32 *)(psVar4 + 4),*(u32 *)(psVar4 + 4),*psVar4 + 0x10,

                 psVar4[1] + 0xd,(char)psVar4[2],iVar5 + 0x5a,0,0,0);

  }

  return 0;

}

// FUN_0040FB90 NONMATCHING


u64 FUN_0040fb90(u64 param_1,int param_2,long param_3)



{

  u32 *puVar1;

  u32 uVar2;

  u32 uVar3;

  u32 uVar4;

  u8 bVar5;

  short sVar6;

  u64 uVar7;

  int iVar8;

  short *psVar9;

  u32 *puVar10;

  float fVar11;

  u16 uVar12;

  short asStack_80 [2];

  float afStack_7c [3];

  u8 auStack_70 [16];

  u8 auStack_60 [32];

  float afStack_40 [16];

  

  puVar1 = *(u32 **)(param_2 + 0xc);

  puVar10 = &DAT_006afb10;

  psVar9 = asStack_80;

  iVar8 = 0x10;

  do {

    uVar2 = *puVar10;

    uVar3 = puVar10[1];

    puVar10 = puVar10 + 2;

    iVar8 = iVar8 + -1;

    *(u32 *)psVar9 = uVar2;

    *(u32 *)(psVar9 + 2) = uVar3;

    psVar9 = psVar9 + 4;

  } while (0 < iVar8);

  if (param_3 == 0) {

    sVar6 = (short)puVar1[6];

    uVar7 = 2;

    if (sVar6 == 2) {

      sVar6 = *(short *)((int)puVar1 + 0x1a) + 1;

      *(short *)((int)puVar1 + 0x1a) = sVar6;

      puVar1[4] = (u32)((float)puVar1[4] - ((float)puVar1[4] * (float)(int)sVar6) / 10.0);

      *(short *)(puVar1 + 3) =

           (short)(int)((float)(int)(short)puVar1[3] -

                       (float)((int)(short)puVar1[3] * (int)*(short *)((int)puVar1 + 0x1a)) / 10.0);

      if (*(short *)((int)puVar1 + 0x1a) < 10) {

        uVar7 = 0;

      }

      else {

        *puVar1 = *puVar1 & 0xfffffffd;

        *(u16 *)((int)puVar1 + 0x1a) = 0;

      }

    }

    else {

      if (sVar6 == 1) {

        sVar6 = *(short *)((int)puVar1 + 0x1a) + 1;

        *(short *)((int)puVar1 + 0x1a) = sVar6;

        if (599 < sVar6) {

          *(u16 *)((int)puVar1 + 0x1a) = 0;

        }

        if ((*puVar1 & 1) == 0) {

          fVar11 = 65535.0 - (float)(*(short *)((int)puVar1 + 0x1a) * 0xffff) / 600.0;

          if (fVar11 < 2.1474836e+09) {

            uVar12 = (u16)(int)fVar11;

          }

          else {

            uVar12 = (u16)(int)(fVar11 - 2.1474836e+09);

          }

          *(u16 *)((int)puVar1 + 0x16) = uVar12;

        }

        else {

          fVar11 = (float)(*(short *)((int)puVar1 + 0x1a) * 0xffff) / 600.0;

          if (fVar11 < 2.1474836e+09) {

            uVar12 = (u16)(int)fVar11;

          }

          else {

            uVar12 = (u16)(int)(fVar11 - 2.1474836e+09);

          }

          *(u16 *)((int)puVar1 + 0x16) = uVar12;

        }

      }

      else if (sVar6 == 0) {

        sVar6 = *(short *)((int)puVar1 + 0x1a) + 1;

        *(short *)((int)puVar1 + 0x1a) = sVar6;

        uVar4 = puVar1[1];

        bVar5 = 0;

        if (*(short *)((int)puVar1 + 0xe) <= sVar6) {

          iVar8 = (int)sVar6 - (int)*(short *)((int)puVar1 + 0xe);

          psVar9 = (short *)((int)afStack_40 + (uVar4 * 8 + 3) * 2);

          bVar5 = 1;

          if ((long)iVar8 <= (long)*psVar9) {

            *puVar1 = *puVar1 | 2;

            *(short *)(puVar1 + 2) =

                 (short)(int)((float)(int)asStack_80[uVar4 * 8] +

                             (float)(iVar8 * ((int)*(short *)(afStack_40 + uVar4 * 4) -

                                             (int)asStack_80[uVar4 * 8])) / (float)(int)*psVar9);

            *(short *)((int)puVar1 + 10) =

                 (short)(int)((float)(int)asStack_80[uVar4 * 8 + 1] +

                             (float)(iVar8 * ((int)*(short *)((int)afStack_40 + (uVar4 * 8 + 1) * 2)

                                             - (int)asStack_80[uVar4 * 8 + 1])) /

                             (float)(int)*psVar9);

            *(short *)(puVar1 + 3) =

                 (short)(int)((float)(int)*(short *)(afStack_7c + uVar4 * 4) +

                             (float)(iVar8 * ((int)*(short *)(afStack_40 + uVar4 * 4 + 1) -

                                             (int)*(short *)(afStack_7c + uVar4 * 4))) /

                             (float)(int)*psVar9);

            puVar1[4] = (u32)(afStack_7c[uVar4 * 4 + 1] +

                              ((float)iVar8 *

                              (afStack_40[uVar4 * 4 + 2] - afStack_7c[uVar4 * 4 + 1])) /

                              (float)(int)*psVar9);

            bVar5 = 0;

          }

        }

        if (bVar5) {

          *(u16 *)(puVar1 + 6) = 1;

          if ((*puVar1 & 1) == 0) {

            *(short *)((int)puVar1 + 0x1a) =

                 (short)(int)(600.0 - (float)((u32)*(u16 *)((int)puVar1 + 0x16) * 600) / 65535.0

                             );

          }

          else {

            *(short *)((int)puVar1 + 0x1a) =

                 (short)(int)((float)((u32)*(u16 *)((int)puVar1 + 0x16) * 600) / 65535.0);

          }

        }

        return 0;

      }

      uVar7 = 1;

    }

  }

  else {

    switch(*(u16 *)((int)param_3 + 6)) {

    case 4:

      *puVar1 = *puVar1 | 1;

      *(u16 *)(puVar1 + 6) = 2;

      *(u16 *)((int)puVar1 + 0x1a) = 0;

      break;

    case 5:

      memcpy(puVar1 + 2,asStack_80,0x10);

      uVar4 = *puVar1;

      *puVar1 = uVar4 & 0xfffffffd;

      *puVar1 = uVar4 & 0xfffffffd | 1;

      puVar1[1] = 0;

      *(u16 *)(puVar1 + 6) = 0;

      *(u16 *)((int)puVar1 + 0x1a) = 0;

      break;

    case 6:

      memcpy(puVar1 + 2,auStack_70,0x10);

      uVar4 = *puVar1;

      *puVar1 = uVar4 & 0xfffffffd;

      *puVar1 = uVar4 & 0xfffffffd | 1;

      puVar1[1] = 1;

      *(u16 *)(puVar1 + 6) = 0;

      *(u16 *)((int)puVar1 + 0x1a) = 0;

      break;

    case 7:

      memcpy(puVar1 + 2,auStack_60,0x10);

      uVar4 = *puVar1;

      *puVar1 = uVar4 & 0xfffffffd;

      *puVar1 = uVar4 & 0xfffffffd | 1;

      puVar1[1] = 2;

      *(u16 *)(puVar1 + 6) = 0;

      *(u16 *)((int)puVar1 + 0x1a) = 0;

    }

    uVar7 = 0;

  }

  return uVar7;

}
