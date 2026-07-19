#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern u32 DAT_006a2660;
extern s32 DAT_006a2680[];
extern u8 DAT_006a26b0[];
extern char DAT_006a26f0[];
extern u32 DAT_007cd4e8;
extern u32 DAT_007cd500;
extern u32 DAT_007ce648;
extern u32 DAT_0095abe0;
extern u32 DAT_0095abe4;
extern u32 DAT_0095abe8;
extern u32 DAT_0095abec;
extern u32 DAT_0095abf0;
extern u32 DAT_0095ac70;
extern u32 DAT_0095ad0c;
extern u32 DAT_0095ae10;
extern u32 DAT_0095ae14;
extern u32 DAT_0095ae18;
extern u32 DAT_0095ae1c;
extern u32 DAT_0095ae20;
extern u32 DAT_0095ae2c;
extern u32 DAT_0095ae30;
extern u32 DAT_0095ae34;
extern u32 DAT_0095ae38;
extern u32 DAT_0095ae3c;
extern u32 DAT_0095ae40;
extern u32 DAT_0095ae60;
extern u8 * PTR_s_Go_home_006a25c0;

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
u64 FUN_003ae420(u64 param_1,int param_2);
u64 FUN_003ae560(u64 param_1,u64 param_2);
u64 FUN_003ae650(u64 param_1,int param_2);
u64 FUN_003ae750(u64 param_1,int param_2);
u64 FUN_003ae870(u64 param_1,u64 param_2);
u64 FUN_003ae8d0(u64 param_1,u64 param_2);
u64 FUN_003ae930(void);
u64 FUN_003ae970(void);
u64 FUN_003ae9b0(u64 param_1,u64 param_2);
u64 FUN_003aea50(u64 param_1,int param_2);
u64 FUN_003aec20(u64 param_1,u64 param_2);
u64 FUN_003aed10(u64 param_1,u64 param_2);
u64 FUN_003aee20(u64 param_1,int param_2);
u64 FUN_003af110(u64 param_1,int param_2);
u32 FUN_003af360(void);
u32 FUN_003af370(void);
u32 FUN_003af380(void);
u32 FUN_003af390(void);
u64 FUN_003af520(void);
u64 FUN_003af560(void);
u64 FUN_003af660(u32 param_1,int param_2);
void FUN_003af770(u64 param_1,u64 param_2);
void FUN_003af7a0(long param_1,u64 param_2);

/* Region call-cast macros */
#define FUN_003ae420(...) ((u64 (*)(...))FUN_003ae420)(__VA_ARGS__)
#define FUN_003ae560(...) ((u64 (*)(...))FUN_003ae560)(__VA_ARGS__)
#define FUN_003ae650(...) ((u64 (*)(...))FUN_003ae650)(__VA_ARGS__)
#define FUN_003ae750(...) ((u64 (*)(...))FUN_003ae750)(__VA_ARGS__)
#define FUN_003ae870(...) ((u64 (*)(...))FUN_003ae870)(__VA_ARGS__)
#define FUN_003ae8d0(...) ((u64 (*)(...))FUN_003ae8d0)(__VA_ARGS__)
#define FUN_003ae930(...) ((u64 (*)(...))FUN_003ae930)(__VA_ARGS__)
#define FUN_003ae970(...) ((u64 (*)(...))FUN_003ae970)(__VA_ARGS__)
#define FUN_003ae9b0(...) ((u64 (*)(...))FUN_003ae9b0)(__VA_ARGS__)
#define FUN_003aea50(...) ((u64 (*)(...))FUN_003aea50)(__VA_ARGS__)
#define FUN_003aec20(...) ((u64 (*)(...))FUN_003aec20)(__VA_ARGS__)
#define FUN_003aed10(...) ((u64 (*)(...))FUN_003aed10)(__VA_ARGS__)
#define FUN_003aee20(...) ((u64 (*)(...))FUN_003aee20)(__VA_ARGS__)
#define FUN_003af110(...) ((u64 (*)(...))FUN_003af110)(__VA_ARGS__)
#define FUN_003af360(...) ((u32 (*)(...))FUN_003af360)(__VA_ARGS__)
#define FUN_003af370(...) ((u32 (*)(...))FUN_003af370)(__VA_ARGS__)
#define FUN_003af380(...) ((u32 (*)(...))FUN_003af380)(__VA_ARGS__)
#define FUN_003af390(...) ((u32 (*)(...))FUN_003af390)(__VA_ARGS__)
#define FUN_003af520(...) ((u64 (*)(...))FUN_003af520)(__VA_ARGS__)
#define FUN_003af560(...) ((u64 (*)(...))FUN_003af560)(__VA_ARGS__)
#define FUN_003af660(...) ((u64 (*)(...))FUN_003af660)(__VA_ARGS__)
#define FUN_003af770(...) ((void (*)(...))FUN_003af770)(__VA_ARGS__)
#define FUN_003af7a0(...) ((void (*)(...))FUN_003af7a0)(__VA_ARGS__)

#undef FUN_003ae420
// FUN_003AE420 NONMATCHING


u64 FUN_003ae420(u64 param_1,int param_2)



{

  char cVar1;

  u8 bVar2;

  u32 uVar3;

  u8 *pbVar4;

  int iVar5;

  u16 uVar6;

  

  pbVar4 = (u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18));

  bVar2 = pbVar4[1];

  if (bVar2 == 0xff) {

    uVar3 = 0;

  }

  else {

    uVar3 = (u32)(u8)(bVar2 - 1);

  }

  uVar3 = uVar3 << 8 | *pbVar4 - 1 & 0xff;

  iVar5 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

  cVar1 = *(char *)(iVar5 + 3);

  if (cVar1 == -1) {

    bVar2 = 0;

  }

  else {

    bVar2 = cVar1 - 1;

  }

  uVar6 = (u16)bVar2 << 8 | *(u8 *)(iVar5 + 2) - 1 & 0xff;

  if (7 < uVar3) {

    FUN_0019d3f0("frTagTable.c",0x2d1);

  }

  if (((short)uVar6 < 0) || (3 < (short)uVar6)) {

    FUN_0019d3f0("frTagTable.c",0x2d2);

  }

  FUN_0017c7f0(uVar3,uVar6);

  return 0;

}
#define FUN_003ae420(...) ((u64 (*)(...))FUN_003ae420)(__VA_ARGS__)
#undef FUN_003ae560
// FUN_003AE560 NONMATCHING


u64 FUN_003ae560(u64 param_1,u64 param_2)



{

  u8 bVar1;

  u32 uVar2;

  u8 *pbVar3;

  

  pbVar3 = (u8 *)(*(int *)((int)param_2 + 0x10) + *(int *)((int)param_2 + 0x18));

  bVar1 = pbVar3[1];

  if (bVar1 == 0xff) {

    bVar1 = 0;

  }

  else {

    bVar1 = bVar1 - 1;

  }

  uVar2 = FUN_0016e190((u16)bVar1 << 8 | *pbVar3 - 1 & 0xff);

  if (((long)uVar2 < 0) || (6 < uVar2)) {

    FUN_0019d3f0("frTagTable.c",0x2eb);

  }

  FUN_003b22a0(param_2);

  FUN_003b2020((&PTR_s_Go_home_006a25c0)[(int)uVar2],param_2);

  return 0;

}
#define FUN_003ae560(...) ((u64 (*)(...))FUN_003ae560)(__VA_ARGS__)
#undef FUN_003ae650
// FUN_003AE650 NONMATCHING


u64 FUN_003ae650(u64 param_1,int param_2)



{

  u32 uVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = 0;

  while( 1 ) {

    iVar2 = iVar3;

    iVar3 = iVar2 + 1;

    uVar1 = (u32)*(u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18) + iVar2);

    if (uVar1 == 10) break;

    if ((uVar1 & 0xf0) == 0xf0) {

      iVar3 = iVar3 + ((uVar1 & 0xf) - 1) * 2 + 1;

    }

    else if (0x7f < uVar1) {

      iVar3 = iVar2 + 2;

    }

  }

  FUN_00521408(0x95abf0,0,0x80);

  FUN_00521250(0x95abf0,*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18),iVar3);

  (&DAT_0095abf0)[iVar2] = 0;

  DAT_007cd4e8 = DAT_007cd4e8 | 0x10;

  *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + iVar3;

  return 0;

}
#define FUN_003ae650(...) ((u64 (*)(...))FUN_003ae650)(__VA_ARGS__)
#undef FUN_003ae750
// FUN_003AE750 NONMATCHING


u64 FUN_003ae750(u64 param_1,int param_2)



{

  char cVar1;

  u8 bVar2;

  u8 bVar3;

  u8 *pbVar4;

  int iVar5;

  

  pbVar4 = (u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18));

  bVar2 = pbVar4[1];

  if (bVar2 == 0xff) {

    bVar2 = 0;

  }

  else {

    bVar2 = bVar2 - 1;

  }

  iVar5 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

  cVar1 = *(char *)(iVar5 + 3);

  if (cVar1 == -1) {

    bVar3 = 0;

  }

  else {

    bVar3 = cVar1 - 1;

  }

  FUN_00170c00(1,(u16)bVar2 << 8 | *pbVar4 - 1 & 0xff,

               (u16)bVar3 << 8 | *(u8 *)(iVar5 + 2) - 1 & 0xff);

  return 0;

}
#define FUN_003ae750(...) ((u64 (*)(...))FUN_003ae750)(__VA_ARGS__)
#undef FUN_003ae870
// FUN_003AE870 NONMATCHING


u64 FUN_003ae870(u64 param_1,u64 param_2)



{

  u64 uVar1;

  u8 auStack_8 [8];

  

  uVar1 = FUN_0017d920();

  FUN_00523ac8(auStack_8,0x7cd524,uVar1);

  FUN_003b22a0(param_2);

  FUN_003b2020(auStack_8,param_2);

  return 0;

}
#define FUN_003ae870(...) ((u64 (*)(...))FUN_003ae870)(__VA_ARGS__)
#undef FUN_003ae8d0
// FUN_003AE8D0 NONMATCHING


u64 FUN_003ae8d0(u64 param_1,u64 param_2)



{

  u64 uVar1;

  u8 auStack_8 [8];

  

  uVar1 = FUN_0017da40();

  FUN_00523ac8(auStack_8,0x7cd524,uVar1);

  FUN_003b22a0(param_2);

  FUN_003b2020(auStack_8,param_2);

  return 0;

}
#define FUN_003ae8d0(...) ((u64 (*)(...))FUN_003ae8d0)(__VA_ARGS__)
#undef FUN_003ae930
// FUN_003AE930 NONMATCHING


u64 FUN_003ae930(void)



{

  u16 uVar1;

  

  uVar1 = FUN_0016dd40();

  FUN_00171c40(uVar1,1);

  return 0;

}
#define FUN_003ae930(...) ((u64 (*)(...))FUN_003ae930)(__VA_ARGS__)
#undef FUN_003ae970
// FUN_003AE970 NONMATCHING


u64 FUN_003ae970(void)



{

  u16 uVar1;

  

  uVar1 = FUN_0016dd40();

  FUN_00171c40(uVar1,0);

  return 0;

}
#define FUN_003ae970(...) ((u64 (*)(...))FUN_003ae970)(__VA_ARGS__)
#undef FUN_003ae9b0
// FUN_003AE9B0


u64 FUN_003ae9b0(u64 param_1,u64 param_2)



{

  char cVar1;

  char cVar2;

  char *pcVar3;
  u8 *puVar4;
  int iVar3;


  u8 auStack_40 [64];

  

  pcVar3 = (char *)DAT_006a26b0;
  puVar4 = auStack_40;

  iVar3 = 0x1c;

  do {

    cVar1 = *pcVar3;

    cVar2 = pcVar3[1];

    pcVar3 = pcVar3 + 2;

    iVar3 = iVar3 + -1;

    *puVar4 = cVar1;

    puVar4[1] = cVar2;
    puVar4 = puVar4 + 2;

  } while (0 < iVar3);

  iVar3 = FUN_0017db00();

  FUN_003b22a0(param_2);

  FUN_003b2020(auStack_40 + iVar3 * 8,param_2);

  return 0;

}
#define FUN_003ae9b0(...) ((u64 (*)(...))FUN_003ae9b0)(__VA_ARGS__)
#undef FUN_003aea50
// FUN_003AEA50 NONMATCHING


u64 FUN_003aea50(u64 param_1,int param_2)



{

  char cVar1;

  u8 bVar2;

  u8 bVar3;

  u32 uVar4;

  u8 *pbVar5;

  int iVar6;

  u8 bVar7;

  int iVar8;

  int iVar9;

  int iVar10;

  u8 bVar11;

  

  pbVar5 = (u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18));

  bVar2 = pbVar5[1];

  if (bVar2 == 0xff) {

    uVar4 = 0;

  }

  else {

    uVar4 = (u32)(u8)(bVar2 - 1);

  }

  iVar6 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

  cVar1 = *(char *)(iVar6 + 3);

  if (cVar1 == -1) {

    bVar2 = 0;

  }

  else {

    bVar2 = cVar1 - 1;

  }

  iVar8 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

  cVar1 = *(char *)(iVar8 + 5);

  if (cVar1 == -1) {

    bVar3 = 0;

  }

  else {

    bVar3 = cVar1 - 1;

  }

  iVar10 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

  cVar1 = *(char *)(iVar10 + 7);

  if (cVar1 == -1) {

    bVar7 = 0;

  }

  else {

    bVar7 = cVar1 - 1;

  }

  iVar9 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

  cVar1 = *(char *)(iVar9 + 9);

  if (cVar1 == -1) {

    bVar11 = 0;

  }

  else {

    bVar11 = cVar1 - 1;

  }

  FUN_003b93c0(uVar4 << 8 | *pbVar5 - 1 & 0xff,(u16)bVar2 << 8 | *(u8 *)(iVar6 + 2) - 1 & 0xff,

               (u16)bVar3 << 8 | *(u8 *)(iVar8 + 4) - 1 & 0xff,

               (u16)bVar7 << 8 | *(u8 *)(iVar10 + 6) - 1 & 0xff,

               (u16)bVar11 << 8 | *(u8 *)(iVar9 + 8) - 1 & 0xff);

  return 0;

}
#define FUN_003aea50(...) ((u64 (*)(...))FUN_003aea50)(__VA_ARGS__)
#undef FUN_003aec20
// FUN_003AEC20 NONMATCHING


u64 FUN_003aec20(u64 param_1,u64 param_2)



{

  char cVar1;

  u8 bVar2;

  short sVar3;

  u32 uVar4;

  u8 *pbVar5;

  int iVar6;

  char *pcVar7;

  char *pcVar8;

  char acStack_20 [28];

  u8 uStack_4;

  char cStack_3;

  u8 uStack_2;

  

  pbVar5 = (u8 *)(*(int *)((int)param_2 + 0x10) + *(int *)((int)param_2 + 0x18));

  bVar2 = pbVar5[1];

  if (bVar2 == 0xff) {

    uVar4 = 0;

  }

  else {

    uVar4 = (u32)(u8)(bVar2 - 1);

  }

  sVar3 = FUN_003082f0(0,uVar4 << 8 | *pbVar5 - 1 & 0xff);

  pcVar8 = DAT_006a26f0;

  pcVar7 = acStack_20;

  iVar6 = 0x13;

  do {

    cVar1 = *pcVar8;

    pcVar8 = pcVar8 + 1;

    iVar6 = iVar6 + -1;

    *pcVar7 = cVar1;

    pcVar7 = pcVar7 + 1;

  } while (0 < iVar6);

  uStack_4 = 0x8d;

  cStack_3 = acStack_20[sVar3] + -0x5a;

  uStack_2 = 0;

  FUN_003b22a0(param_2);

  FUN_003b2020(&uStack_4,param_2);

  return 0;

}
#define FUN_003aec20(...) ((u64 (*)(...))FUN_003aec20)(__VA_ARGS__)
#undef FUN_003aed10
// FUN_003AED10 NONMATCHING


u64 FUN_003aed10(u64 param_1,u64 param_2)



{

  char cVar1;

  short sVar2;

  u64 uVar3;

  char *pcVar4;

  

  pcVar4 = (char *)(*(int *)((int)param_2 + 0x10) + *(int *)((int)param_2 + 0x18));

  cVar1 = pcVar4[1];

  if (cVar1 == -1) {

    cVar1 = '\0';

  }

  else {

    cVar1 = cVar1 + -1;

  }

  if (cVar1 == '\0' && *pcVar4 == '\x01') {

    sVar2 = FUN_0016dd40();

    if (sVar2 == 0) {

      FUN_0019d3f0("frTagTable.c",0x38c);

    }

    uVar3 = FUN_003c3f80(sVar2);

  }

  else {

    uVar3 = FUN_003c3f80();

  }

  FUN_003b22a0(param_2);

  FUN_003b2020(uVar3,param_2);

  return 0;

}
#define FUN_003aed10(...) ((u64 (*)(...))FUN_003aed10)(__VA_ARGS__)
#undef FUN_003aee20
// FUN_003AEE20 NONMATCHING


u64 FUN_003aee20(u64 param_1,int param_2)



{

  u8 bVar1;

  char cVar2;

  u32 uVar3;

  u8 bVar4;

  short sVar5;

  u32 uVar6;

  u32 uVar7;

  long lVar8;

  u8 *pbVar9;

  u32 uVar10;

  int iVar11;

  u32 *puVar12;

  u32 *puVar13;

  u64 unaff_s0;

  u32 uVar14;

  u64 unaff_s1;

  int aiStack_84 [13];
  u32 stack_ffffffe0[5];
  u32 stack_ffffffb0[32];
  u32 stack_ffffffc0[5];

  u8 auStack_4 [2];

  u8 auStack_2 [2];

  

  aiStack_84[9] = (int)unaff_s1;

  aiStack_84[10] = (int)((u32)unaff_s1 >> 0x20);

  aiStack_84[5] = (int)unaff_s0;

  aiStack_84[6] = (int)((u32)unaff_s0 >> 0x20);

  pbVar9 = (u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18));

  bVar1 = pbVar9[1];

  if (bVar1 == 0xff) {

    uVar6 = 0;

  }

  else {

    uVar6 = (u32)(u8)(bVar1 - 1);

  }

  uVar6 = uVar6 << 8 | *pbVar9 - 1 & 0xff;

  iVar11 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

  cVar2 = *(char *)(iVar11 + 3);

  if (cVar2 == -1) {

    uVar10 = 0;

  }

  else {

    uVar10 = (u32)(u8)(cVar2 - 1);

  }

  uVar14 = (long)(int)(uVar10 << 8) | (long)(int)(*(u8 *)(iVar11 + 2) - 1) & 0xffU;

  bVar4 = 0;

  switch(uVar6) {

  case 0:

    sVar5 = FUN_0016c6f0(1);

    if ((long)sVar5 < (long)uVar14) {

      bVar4 = 1;

    }

    break;

  case 1:

    sVar5 = FUN_0016c740(1);

    if ((long)sVar5 < (long)uVar14) {

      bVar4 = 1;

    }

    break;

  case 2:

    sVar5 = FUN_0016c790(1);

    if ((long)sVar5 < (long)uVar14) {

      bVar4 = 1;

    }

    break;

  case 3:

  case 4:

  case 5:

  case 6:

  case 7:

    uVar7 = FUN_001738d0(1,uVar6 - 3 & 0xffff);

    if ((uVar7 & 0xff) < uVar14) {

      bVar4 = 1;

    }

    break;

  case 8:

    uVar7 = FUN_0016c920(1);

    if (uVar14 == (uVar7 & 0xffff)) {

      bVar4 = 1;

    }

    break;

  case 9:

    uVar7 = FUN_0016c920(1);

    if (uVar14 != (uVar7 & 0xffff)) {

      bVar4 = 1;

    }

    break;

  case 10:

    lVar8 = FUN_00172c50(auStack_2);

    if (lVar8 == 0) {

      bVar4 = 1;

    }

    break;

  case 0xb:

    lVar8 = FUN_00172c50(auStack_4);

    if (lVar8 != 0) {

      bVar4 = 1;

    }

    break;

  case 0xc:

  case 0xd:

  case 0xe:

  case 0xf:

  case 0x10:

    puVar13 = &DAT_006a2660;

      puVar12 = stack_ffffffe0;

    iVar11 = 5;

    do {

      uVar3 = *puVar13;

      puVar13 = puVar13 + 1;

      iVar11 = iVar11 + -1;

      *puVar12 = uVar3;

      puVar12 = puVar12 + 1;

    } while (0 < iVar11);

    lVar8 = FUN_0016f190((int)uVar14 + stack_ffffffb0[uVar6]);

    if (lVar8 == 1) {

      bVar4 = 1;

    }

    break;

  case 0x11:

  case 0x12:

  case 0x13:

  case 0x14:

  case 0x15:

    puVar13 = &DAT_006a2660;

    puVar12 = stack_ffffffc0;

    iVar11 = 5;

    do {

      uVar3 = *puVar13;

      puVar13 = puVar13 + 1;

      iVar11 = iVar11 + -1;

      *puVar12 = uVar3;

      puVar12 = puVar12 + 1;

    } while (0 < iVar11);

    lVar8 = FUN_0016f190((int)uVar14 + aiStack_84[uVar6]);

    if (lVar8 == 0) {

      bVar4 = 1;

    }

  }

  if (bVar4) {

    DAT_007cd4e8 = DAT_007cd4e8 | 0x20;

  }

  return 0;

}
#define FUN_003aee20(...) ((u64 (*)(...))FUN_003aee20)(__VA_ARGS__)
#undef FUN_003af110
// FUN_003AF110 NONMATCHING


u64 FUN_003af110(u64 param_1,int param_2)



{

  u8 bVar1;

  char cVar2;

  u8 bVar3;

  int iVar4;

  u16 uVar5;

  u32 uVar6;

  u32 uVar7;

  u32 uVar8;

  u64 uVar9;

  u8 *pbVar10;

  int iVar11;

  u32 uVar12;

  int *piVar13;

  int *piVar14;

  int aiStack_20 [8];

  

  if ((DAT_007cd500 & 0x80) != 0) {

    pbVar10 = (u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18));

    bVar1 = pbVar10[1];

    if (bVar1 == 0xff) {

      uVar6 = 0;

    }

    else {

      uVar6 = (u32)(u8)(bVar1 - 1);

    }

    uVar6 = uVar6 << 8 | *pbVar10 - 1 & 0xff;

    iVar11 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

    bVar1 = *(u8 *)(iVar11 + 2);

    cVar2 = *(char *)(iVar11 + 3);

    if (cVar2 == -1) {

      uVar7 = 0;

    }

    else {

      uVar7 = (u32)(u8)(cVar2 - 1);

    }

    iVar11 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

    bVar3 = *(u8 *)(iVar11 + 4);

    cVar2 = *(char *)(iVar11 + 5);

    if (cVar2 == -1) {

      uVar8 = 0;

    }

    else {

      uVar8 = (u32)(u8)(cVar2 - 1);

    }

    iVar11 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

    cVar2 = *(char *)(iVar11 + 7);

    if (cVar2 == -1) {

      uVar12 = 0;

    }

    else {

      uVar12 = (u32)(u8)(cVar2 - 1);

    }

    uVar12 = uVar12 << 8 | *(u8 *)(iVar11 + 6) - 1 & 0xff;

    if (uVar6 != 6) {

      if ((uVar6 == 3) || (uVar6 == 2)) {

        FUN_0017db00();

        uVar9 = FUN_0016dd40();

        FUN_0016e2b0(uVar9,uVar12);

      }

      else if (uVar6 == 1) {

        uVar5 = FUN_0016dd40();

        FUN_00171c40(uVar5,uVar12);

      }

      else if (uVar6 == 0) {

        piVar14 = DAT_006a2680;

        piVar13 = aiStack_20;

        iVar11 = 5;

        do {

          iVar4 = *piVar14;

          piVar14 = piVar14 + 1;

          iVar11 = iVar11 + -1;

          *piVar13 = iVar4;

          piVar13 = piVar13 + 1;

        } while (0 < iVar11);

        FUN_0016f1f0((uVar8 << 8 | bVar3 - 1 & 0xff) + aiStack_20[uVar7 << 8 | bVar1 - 1 & 0xff],

                     uVar12);

      }

    }

  }

  return 0;

}
#define FUN_003af110(...) ((u64 (*)(...))FUN_003af110)(__VA_ARGS__)
#undef FUN_003af360
// FUN_003AF360


u32 FUN_003af360(void)



{

  return *(u32 *)0x0095abe0;
}
#define FUN_003af360(...) ((u32 (*)(...))FUN_003af360)(__VA_ARGS__)
#undef FUN_003af370
// FUN_003AF370


u32 FUN_003af370(void)



{

  return *(u32 *)0x0095abe4;
}
#define FUN_003af370(...) ((u32 (*)(...))FUN_003af370)(__VA_ARGS__)
#undef FUN_003af380
// FUN_003AF380


u32 FUN_003af380(void)



{

  return *(u32 *)0x0095abe8;
}
#define FUN_003af380(...) ((u32 (*)(...))FUN_003af380)(__VA_ARGS__)
#undef FUN_003af390
// FUN_003AF390


u32 FUN_003af390(void)



{

  return *(u32 *)0x0095abec;
}
#define FUN_003af390(...) ((u32 (*)(...))FUN_003af390)(__VA_ARGS__)
// FUN_003AF3A0 NONMATCHING
u64 FUN_003af3a0(u64 unused, int context)
{
  u8 *data = (u8 *)(*(int *)(context + 0x10) + *(int *)(context + 0x18));
  u32 high = data[1] == 0xff ? 0 : (u8)(data[1] - 1);
  DAT_0095abe0 = high << 8 | (data[0] - 1) & 0xff;
  high = (s8)data[3] == -1 ? 0 : (u8)(data[3] - 1);
  DAT_0095abe4 = high << 8 | (data[2] - 1) & 0xff;
  return 0;
}

// FUN_003AF454 NONMATCHING
u64 FUN_003af454(u64 unused, int context)
{
  u8 *data = (u8 *)(*(int *)(context + 0x10) + *(int *)(context + 0x18));
  u32 high = data[1] == 0xff ? 0 : (u8)(data[1] - 1);
  DAT_0095abe8 = high << 8 | (data[0] - 1) & 0xff;
  high = (s8)data[3] == -1 ? 0 : (u8)(data[3] - 1);
  DAT_0095abec = high << 8 | (data[2] - 1) & 0xff;
  return 0;
}

#undef FUN_003af520
// FUN_003AF520 NONMATCHING


u64 FUN_003af520(void)



{

  u16 uVar1;

  

  uVar1 = FUN_0016dd40();

  FUN_00172200(uVar1,1);

  return 0;

}
#define FUN_003af520(...) ((u64 (*)(...))FUN_003af520)(__VA_ARGS__)
#undef FUN_003af560
// FUN_003AF560


u64 FUN_003af560(void)



{

  s16 sVar1;

  

  sVar1 = FUN_0016dd40();

  FUN_00172200(sVar1,0);

  return 0;

}
// FUN_003AF5A0 NONMATCHING
u64 FUN_003af5a0(u32 param_1,int param_2)
{
  u8 bVar1;
  u8 bVar2;
  short sVar5;
  u8 *pbVar4;
  int iVar6;
  int iVar7;
  u32 uVar8;

  iVar7 = *(int *)(param_2 + 0x18);
  iVar6 = *(int *)(param_2 + 0x10);
  iVar7 = iVar6 + iVar7;
  iVar7 = iVar7;
  pbVar4 = (u8 *)iVar7;
  bVar1 = *pbVar4 - 1;
  bVar2 = pbVar4[1];
  if (bVar2 == 0xff) {
    bVar2 = 0;
  }
  else {
    bVar2 = (bVar2 - 1) & 0xff;
  }
  sVar5 = (short)(((u16)bVar2 << 8) | (bVar1 & 0xff));
  if (*(int *)(*(int *)(param_2 + 0x14) + 0x34) != 0) {
    *(u32 *)(*(int *)(param_2 + 0x14) + 0x38) = 1;
  }
  *(u32 *)(*(int *)(param_2 + 0x14) + 0x30) = param_1;
  *(int *)(*(int *)(param_2 + 0x14) + 0x3c) = sVar5;
  if (*(int *)(*(int *)(param_2 + 0x14) + 0x3c) < 0) {
    *(u32 *)(*(int *)(param_2 + 0x14) + 0x3c) = 0;
  }
  DAT_007cd4e8 = DAT_007cd4e8 | 0x80;
  return 0;
}
#define FUN_003af560(...) ((u64 (*)(...))FUN_003af560)(__VA_ARGS__)
#undef FUN_003af660
// FUN_003AF660 NONMATCHING


u64 FUN_003af660(u32 param_1,int param_2)



{

  u8 bVar1;

  u8 bVar2;

  long lVar3;

  u8 *pbVar4;

  

  pbVar4 = (u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18));

  bVar1 = *pbVar4;

  bVar2 = pbVar4[1];

  if (bVar2 == 0xff) {

    bVar2 = 0;

  }

  else {

    bVar2 = bVar2 - 1;

  }

  lVar3 = FUN_0016f190(0x185);

  if (lVar3 != 0) {

    if (*(int *)(*(int *)(param_2 + 0x14) + 0x34) != 0) {

      *(u32 *)(*(int *)(param_2 + 0x14) + 0x38) = 1;

    }

    *(u32 *)(*(int *)(param_2 + 0x14) + 0x30) = param_1;

    *(int *)(*(int *)(param_2 + 0x14) + 0x3c) = (int)(short)((u16)bVar2 << 8 | bVar1 - 1 & 0xff);

    if (*(int *)(*(int *)(param_2 + 0x14) + 0x3c) < 0) {

      *(u32 *)(*(int *)(param_2 + 0x14) + 0x3c) = 0;

    }

    DAT_007cd4e8 = DAT_007cd4e8 | 0x40;

  }

  return 0;

}
#define FUN_003af660(...) ((u64 (*)(...))FUN_003af660)(__VA_ARGS__)
#undef FUN_003af770
// FUN_003AF770


void FUN_003af770(u64 param_1,u64 param_2)



{

  FUN_003afad0(param_1,0,param_2);

  return;

}
#define FUN_003af770(...) ((void (*)(...))FUN_003af770)(__VA_ARGS__)
#undef FUN_003af7a0
// FUN_003AF7A0 NONMATCHING






void FUN_003af7a0(long param_1,u64 param_2)



{

  u32 uVar1;

  u32 uVar2;

  int iVar3;

  int iVar4;

  

  DAT_0095ae10 = 0;

  DAT_0095ae14 = 0;

  DAT_0095ae18 = 0;

  for (iVar4 = 0; iVar4 < 9; iVar4 = iVar4 + 1) {

    (&DAT_0095ad0c)[iVar4 * 8] = 0;

  }

  iVar4 = (int)param_1;

  if (param_1 < 0) {

    iVar4 = iVar4 + 0xf;

  }

  iVar4 = iVar4 >> 4;

  DAT_0095ae2c = 0x200;

  iVar3 = 0;

  for (uVar2 = 0x200; uVar2 != 0; uVar2 = uVar2 >> 1) {

    iVar3 = iVar3 + 1;

  }

  DAT_0095ae30 = iVar3 - 1U & 0xff;

  uVar1 = iVar4 << 5;

  uVar2 = 0;

  if (uVar1 != 0) {

    for (; uVar1 != 0; uVar1 = uVar1 >> 1) {

      uVar2 = uVar2 + 1;

    }

    uVar2 = uVar2 - 1 & 0xff;

  }

  DAT_0095ae34 = 1 << (uVar2 + 1 & 0x1f);

  DAT_0095ae38 = 0;

  uVar2 = DAT_0095ae34;

  if (DAT_0095ae34 != 0) {

    for (; uVar2 != 0; uVar2 = uVar2 >> 1) {

      DAT_0095ae38 = DAT_0095ae38 + 1;

    }

    DAT_0095ae38 = DAT_0095ae38 - 1 & 0xff;

  }

  for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {

  }

  DAT_0095ae40 = 8;

  for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {

    (&DAT_0095ae60)[iVar3] = 0;

  }

  FUN_003b41a0(DAT_0095ae3c,0x10,iVar4,0x20,0x20,0x10);

  DAT_0095ae1c = FUN_003b45f0(0x2c,(int)param_2 << 2);

  DAT_0095ae20 = FUN_003b45f0(0x44,param_2);

  FUN_003afc70();

  FUN_003aff50();

  for (iVar3 = 0; iVar3 < 0x20; iVar3 = iVar3 + 1) {

    *(u32 *)(&DAT_0095ac70 + iVar3 * 4) = 0;

  }

  FUN_005225a8(0x6a2740,0x6a2730);

  DAT_007ce648 = iVar4 << 4;

  FUN_003b35e0(param_2);

  return;

}
#define FUN_003af7a0(...) ((void (*)(...))FUN_003af7a0)(__VA_ARGS__)
