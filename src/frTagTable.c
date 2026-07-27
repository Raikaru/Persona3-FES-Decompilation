#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern u8 D_007CD524;
extern u32 D_0095ABE0[];
extern u32 D_0095ABE4[];
extern u32 D_0095ABE8[];
extern u32 D_0095ABEC[];
#pragma alias DAT_006a2660_abs DAT_006a2660
extern u32 DAT_006a2660_abs[];
extern s32 DAT_006a2680[];
extern u8 DAT_006a26b0[];
extern char DAT_006a26f0[];
extern u32 DAT_007cd4e8;
extern void FUN_0019d3f0(const char *file, s32 line);
extern void FUN_0017c7f0(s32 index, s64 value);
extern u32 uGpffffa7f8;
extern u32 DAT_007cd500;
extern u32 DAT_007ce648;
extern u32 DAT_0095abe0;
extern u32 DAT_0095abe4;
extern u32 DAT_0095abe8;
extern u32 DAT_0095abec;
extern u32 DAT_0095abf0;
#pragma alias DAT_0095abf0_abs DAT_0095abf0
extern u8 DAT_0095abf0_abs[];
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
#pragma alias DAT_007ce648_abs DAT_007ce648
extern u8 DAT_007ce648_abs[];
#pragma alias DAT_0095ac70_abs DAT_0095ac70
extern u8 DAT_0095ac70_abs[];
#pragma alias DAT_0095ad0c_abs DAT_0095ad0c
extern u8 DAT_0095ad0c_abs[];
#pragma alias DAT_0095ae10_abs DAT_0095ae10
extern u8 DAT_0095ae10_abs[];
#pragma alias DAT_0095ae14_abs DAT_0095ae14
extern u8 DAT_0095ae14_abs[];
#pragma alias DAT_0095ae18_abs DAT_0095ae18
extern u8 DAT_0095ae18_abs[];
#pragma alias DAT_0095ae1c_abs DAT_0095ae1c
extern u8 DAT_0095ae1c_abs[];
#pragma alias DAT_0095ae20_abs DAT_0095ae20
extern u8 DAT_0095ae20_abs[];
#pragma alias DAT_0095ae2c_abs DAT_0095ae2c
extern u8 DAT_0095ae2c_abs[];
#pragma alias DAT_0095ae30_abs DAT_0095ae30
extern u8 DAT_0095ae30_abs[];
#pragma alias DAT_0095ae34_abs DAT_0095ae34
extern u8 DAT_0095ae34_abs[];
#pragma alias DAT_0095ae38_abs DAT_0095ae38
extern u8 DAT_0095ae38_abs[];
#pragma alias DAT_0095ae3c_abs DAT_0095ae3c
extern u8 DAT_0095ae3c_abs[];
#pragma alias DAT_0095ae40_abs DAT_0095ae40
extern u8 DAT_0095ae40_abs[];
#pragma alias DAT_0095ae60_abs DAT_0095ae60
extern u8 DAT_0095ae60_abs[];
extern u8 * PTR_s_Go_home_006a25c0;
#pragma alias PTR_s_Go_home_006a25c0_abs PTR_s_Go_home_006a25c0
extern u8 PTR_s_Go_home_006a25c0_abs[];

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
u64 FUN_003ae420(u64 param_1,int param_2);
u64 FUN_003ae560(u64 param_1,int param_2);
u64 FUN_003ae650(u64 param_1,int param_2);
u64 FUN_003ae750(u64 param_1,int param_2);
u64 FUN_003ae870(u64 param_1,u64 param_2);
u64 FUN_003ae8d0(u64 param_1,u64 param_2);
u64 FUN_003ae930(void);
u64 FUN_003ae970(void);
u64 FUN_003ae9b0(u64 param_1,u64 param_2);
u64 FUN_003aea50(u64 param_1,int param_2);
u64 FUN_003aec20(u64 param_1,int param_2);
u64 FUN_003aed10(u64 param_1,int param_2);
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
void FUN_003af7a0(int param_1,u64 param_2);

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

#pragma push
#pragma opt_rebuildconditionals off
 
#undef FUN_003ae420
// FUN_003AE420


u64 FUN_003ae420(u64 param_1, int param_2)
{
  u8 *data;
  u8 low;
  u8 high;
  int base;
  int offset;
  s32 first;
  s16 second;

  offset = *(volatile int *)(param_2 + 0x18);
  base = *(volatile int *)(param_2 + 0x10);
  data = (u8 *)(base + offset);
  low = data[0] - 1;
  if (data[1] == 0xff) {
    high = 0;
  } else {
    high = data[1] - 1;
  }
  first = (u32)high << 8 | low;

  offset = *(volatile int *)(param_2 + 0x18);
  base = *(volatile int *)(param_2 + 0x10);
  data = (u8 *)(offset + base);
  low = data[2] - 1;
  if (data[3] == 0xff) {
    high = 0;
  } else {
    high = data[3] - 1;
  }
  second = (u32)high << 8 | low;

  if (first < 0) goto first_error;
  if (first >= 8) goto first_error;
  goto first_done;
first_error:
  FUN_0019d3f0("frTagTable.c",0x2d1);
first_done:
  if ((s16)second < 0) goto second_error;
  if ((s16)second >= 4) goto second_error;
  goto second_done;
second_error:
  FUN_0019d3f0("frTagTable.c",0x2d2);
second_done:
  FUN_0017c7f0(first, (s16)second);
  return 0;
}
#pragma pop
#define FUN_003ae420(...) ((u64 (*)(...))FUN_003ae420)(__VA_ARGS__)
#undef FUN_003ae560
// FUN_003AE560


u64 FUN_003ae560(u64 param_1,int param_2)
{
  s32 lVar1;
  u32 uVar3;
  u8 bVar1;
  u8 **table;
  u32 offset;
  u32 base;
  u8 *pbVar3;

  offset = *(volatile int *)(param_2 + 0x18);
  base = *(volatile int *)(param_2 + 0x10);
  pbVar3 = (u8 *)(base + offset);
  bVar1 = pbVar3[0] - 1;
  uVar3 = pbVar3[1];
  if (uVar3 == 0xff) {
    uVar3 = 0;
  } else {
    uVar3 = (u8)(uVar3 - 1);
  }
  uVar3 = uVar3 & 0xff;
  lVar1 = FUN_0016e190((short)((uVar3 << 8) | (bVar1 & 0xff)));
  if (lVar1 < 0 || (u32)lVar1 >= 7) {
    FUN_0019d3f0("frTagTable.c",0x2eb);
  }
  FUN_003b22a0(param_2);
  offset = lVar1 << 2;
  asm volatile("" : "+m"(offset));
  table = (u8 **)&PTR_s_Go_home_006a25c0_abs;
  table = (u8 **)((u8 *)table + offset);
  FUN_003b2020(*table,param_2);
  return 0;
}
#define FUN_003ae560(...) ((u64 (*)(...))FUN_003ae560)(__VA_ARGS__)
#undef FUN_003ae650
// FUN_003AE650 NONMATCHING


u64 FUN_003ae650(u64 param_1,int param_2)
{
  int index;
  int base;
  int offset;
  u8 *data;
  u32 value;
  u32 mask;
  u32 newline;

  index = 0;
  offset = *(volatile int *)(param_2 + 0x18);
  base = *(volatile int *)(param_2 + 0x10);
  data = (u8 *)(base + offset);
  mask = 0xf0;
  newline = 10;
  do {
    value = data[index];
    index++;
    if (value != newline) {
      if ((value & mask) == mask) {
        index += ((value & 0xf) - 1) * 2 + 1;
      } else if (value >= 0x80) {
        index++;
      }
    }
  } while (value != newline);

  FUN_00521408(DAT_0095abf0_abs,0,0x80);
  FUN_00521250(DAT_0095abf0_abs,*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18),index);
  DAT_0095abf0_abs[index] = 0;
  DAT_007cd4e8 = DAT_007cd4e8 | 0x10;
  *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + index;
  return 0;
}
#define FUN_003ae650(...) ((u64 (*)(...))FUN_003ae650)(__VA_ARGS__)
#undef FUN_003ae750
// FUN_003AE750
#pragma push
#pragma opt_propagation off
u64 FUN_003ae750(u64 param_1, int param_2)
{
  u8* data;
  u8 low;
  u8 high;
  int base;
  int offset;
  u32 first;
  u32 second;

  offset = *(volatile int *)(param_2 + 0x18);
  base = *(volatile int *)(param_2 + 0x10);
  data = (u8 *)(base + offset);
  low = data[0] - 1;
  if (data[1] == 0xff)
  {
    high = 0;
  }
  else
  {
    high = data[1] - 1;
  }
  first = (u32)high << 8 | low;

  offset = *(volatile int *)(param_2 + 0x18);
  base = *(volatile int *)(param_2 + 0x10);
  data = (u8 *)(offset + base);
  low = data[2] - 1;
  if (data[3] == 0xff)
  {
    high = 0;
  }
  else
  {
    high = data[3] - 1;
  }
  second = (u32)high << 8 | low;

  FUN_00170c00(1, (s16)first, (s16)second);
  return 0;
}
#pragma pop

// FUN_003AE820
u64 FUN_003ae820(u64 param_1,u64 param_2)
{
  DAT_007cd4e8 = DAT_007cd4e8 | 3;
  return 1;
}
// FUN_003AE840
u64 FUN_003ae840(u64 param_1,u64 param_2)
{
  return 0;
}
// FUN_003AE850
u64 FUN_003ae850(u64 param_1,u64 param_2)
{
  return 0;
}
// FUN_003AE860
u64 FUN_003ae860(u64 param_1,u64 param_2)
{
  return 0;
}

#define FUN_003ae750(...) ((u64 (*)(...))FUN_003ae750)(__VA_ARGS__)
#undef FUN_003ae870
// FUN_003AE870


u64 FUN_003ae870(u64 param_1,u64 param_2)



{

  u32 uVar1;

  u8 auStack_8 [8];

  

  uVar1 = FUN_0017d920();

  FUN_00523ac8(auStack_8,&D_007CD524,uVar1);

  FUN_003b22a0(param_2);

  FUN_003b2020(auStack_8,param_2);

  return 0;

}

#define FUN_003ae870(...) ((u64 (*)(...))FUN_003ae870)(__VA_ARGS__)
#undef FUN_003ae8d0
// FUN_003AE8D0


u64 FUN_003ae8d0(u64 param_1,u64 param_2)



{

  u32 uVar1;

  u8 auStack_8 [8];

  

  uVar1 = FUN_0017da40();

  FUN_00523ac8(auStack_8,&D_007CD524,uVar1);

  FUN_003b22a0(param_2);

  FUN_003b2020(auStack_8,param_2);

  return 0;

}

#define FUN_003ae8d0(...) ((u64 (*)(...))FUN_003ae8d0)(__VA_ARGS__)
#undef FUN_003ae930
// FUN_003AE930


u64 FUN_003ae930(void)



{

  s16 uVar1;

  

  uVar1 = FUN_0016dd40();

  FUN_00171c40(uVar1,1);

  return 0;

}

#define FUN_003ae930(...) ((u64 (*)(...))FUN_003ae930)(__VA_ARGS__)
#undef FUN_003ae970
// FUN_003AE970


u64 FUN_003ae970(void)



{

  s16 uVar1;

  

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
  u8 cVar1;
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
  } else {
    uVar4 = (u32)(u8)(bVar2 - 1);
  }
  iVar6 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);
  cVar1 = *(u8 *)(iVar6 + 3);
  if (cVar1 == -1) {
    bVar2 = 0;
  } else {
    bVar2 = cVar1 - 1;
  }
  iVar8 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);
  cVar1 = *(u8 *)(iVar8 + 5);
  if (cVar1 == -1) {
    bVar3 = 0;
  } else {
    bVar3 = cVar1 - 1;
  }
  iVar10 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);
  cVar1 = *(u8 *)(iVar10 + 7);
  if (cVar1 == -1) {
    bVar7 = 0;
  } else {
    bVar7 = cVar1 - 1;
  }
  iVar9 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);
  cVar1 = *(u8 *)(iVar9 + 9);
  if (cVar1 == -1) {
    bVar11 = 0;
  } else {
    bVar11 = cVar1 - 1;
  }
  FUN_003b93c0(uVar4 << 8 | *pbVar5 - 1 & 0xff,
               (u16)bVar2 << 8 | *(u8 *)(iVar6 + 2) - 1 & 0xff,
               (u16)bVar3 << 8 | *(u8 *)(iVar8 + 4) - 1 & 0xff,
               (u16)bVar7 << 8 | *(u8 *)(iVar10 + 6) - 1 & 0xff,
               (u16)bVar11 << 8 | *(u8 *)(iVar9 + 8) - 1 & 0xff);
  return 0;
}

#define FUN_003aea50(...) ((u64 (*)(...))FUN_003aea50)(__VA_ARGS__)
#undef FUN_003aec20
// FUN_003AEC20 NONMATCHING


u64 FUN_003aec20(u64 param_1,int param_2)
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
  } else {
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
// FUN_003AED10


u64 FUN_003aed10(u64 param_1,int param_2)
{
  int offset;
  int base;
  int key;
  u8 low;
  u8 high;
  short sVar2;
  u32 uVar3;
  u8 *pcVar4;

  offset = *(volatile int *)((int)param_2 + 0x18);
  base = *(volatile int *)((int)param_2 + 0x10);
  pcVar4 = (u8 *)(base + offset);
  low = pcVar4[0] - 1;
  high = pcVar4[1];
  if (high == 0xff) {
    high = 0;
  } else {
    high = high - 1;
  }
  if (((key = (high << 8) | (low & 0xff))) != 0) goto normal_path;
  sVar2 = FUN_0016dd40();
  if (sVar2 == 0) {
    FUN_0019d3f0("frTagTable.c",0x38c);
  }
  uVar3 = FUN_003c3f80(sVar2);
  goto join_path;
normal_path:
  uVar3 = FUN_003c3f80(key);
join_path:
  FUN_003b22a0(param_2);
  FUN_003b2020(uVar3,param_2);
  return 0;
}
// FUN_003AEE00
u64 FUN_003aee00(u64 param_1, int param_2)
{
  *(u8 *)(param_2 + 0xf) = 0x14;
  *(u16 *)(param_2 + 0x1e) = 0x20;
  return 0;
}

#define FUN_003aed10(...) ((u64 (*)(...))FUN_003aed10)(__VA_ARGS__)
#undef FUN_003aee20
// FUN_003AEE20 NONMATCHING
u64 FUN_003aee20(u64 param_1, int param_2)
{
  u8 bVar1;
  u8 bVar2;
  u8 *pbVar9;
  u32 uVar6;
  u32 uVar7;
  u32 uVar14;
  int lVar8;
  int bVar4;
  u32 stack_50[5];
  u32 stack_30[5];
  u8 auStack_6c[4];
  u32 *puVar13;
  u32 *puVar12;
  int iVar11;
  iVar11 = *(int *)(param_2 + 0x18);
  lVar8 = *(int *)(param_2 + 0x10);
  pbVar9 = (u8 *)(lVar8 + iVar11);
  bVar1 = pbVar9[0] - 1;
  if (pbVar9[1] == 0xff) {
    bVar2 = 0;
  } else {
    bVar2 = pbVar9[1] - 1;
  }
  uVar6 = ((u32)bVar2 << 8) | bVar1;

  iVar11 = *(volatile int *)(param_2 + 0x18) + *(volatile int *)(param_2 + 0x10);
  bVar1 = *(u8 *)(iVar11 + 2) - 1;
  if (*(u8 *)(iVar11 + 3) == 0xff) {
    bVar2 = 0;
  } else {
    bVar2 = *(u8 *)(iVar11 + 3) - 1;
  }
  uVar14 = ((u32)bVar2 << 8) | bVar1;

  bVar4 = 0;
  switch (uVar6) {
  case 0:
    if ((s16)FUN_0016c6f0(1) < (s32)uVar14) bVar4 = 1;
    break;
  case 1:
    if ((s16)FUN_0016c740(1) < (s32)uVar14) bVar4 = 1;
    break;
  case 2:
    if ((s16)FUN_0016c790(1) < (s32)uVar14) bVar4 = 1;
    break;
  case 3:
  case 4:
  case 5:
  case 6:
  case 7:
    uVar7 = FUN_001738d0(1, (uVar6 - 3) & 0xffff);
    if ((s32)(uVar7 & 0xff) < (s32)uVar14) bVar4 = 1;
    break;
  case 8:
    uVar7 = FUN_0016c920(1);
    if (uVar14 == (uVar7 & 0xffff)) bVar4 = 1;
    break;
  case 9:
    uVar7 = FUN_0016c920(1);
    if (uVar14 != (uVar7 & 0xffff)) bVar4 = 1;
    break;
  case 10:
    lVar8 = FUN_00172c50(auStack_6c + 2);
    if (lVar8 == 0) bVar4 = 1;
    break;
  case 0xb:
    lVar8 = FUN_00172c50(auStack_6c);
    if (lVar8 != 0) bVar4 = 1;
    break;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
    puVar13 = DAT_006a2660_abs;
    puVar12 = stack_50;
    iVar11 = 5;
    do {
      uVar7 = *puVar13++;
      iVar11--;
      *puVar12++ = uVar7;
    } while (0 < iVar11);
    lVar8 = FUN_0016f190((int)uVar14 + stack_50[uVar6 - 0xc]);
    if (lVar8 == 1) bVar4 = 1;
    break;
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
    puVar13 = DAT_006a2660_abs;
    puVar12 = stack_30;
    iVar11 = 5;
    do {
      uVar7 = *puVar13++;
      iVar11--;
      *puVar12++ = uVar7;
    } while (0 < iVar11);
    lVar8 = FUN_0016f190((int)uVar14 + stack_30[uVar6 - 0x11]);
    if (lVar8 == 0) bVar4 = 1;
    break;
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x19:
    break;
  }
  if (bVar4) DAT_007cd4e8 |= 0x20;
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
// FUN_003AF3A0
u64 FUN_003af3a0(u64 unused, int context)
{
  u8* data;
  u8 low;
  u8 high;
  int base;
  int offset;

  offset = *(int *)(context + 0x18);
  base = *(int *)(context + 0x10);
  data = (u8 *)(base + offset);
  low = data[0] - 1;
  if (data[1] == 0xff)
  {
    high = 0;
  }
  else
  {
    high = data[1] - 1;
  }
  D_0095ABE0[0] = (u32)high << 8 | low;

  offset = *(int *)(context + 0x18);
  base = *(int *)(context + 0x10);
  data = (u8 *)(offset + base);
  low = data[2] - 1;
  if (data[3] == 0xff)
  {
    high = 0;
  }
  else
  {
    high = data[3] - 1;
  }
  D_0095ABE4[0] = (u32)high << 8 | low;
  return 0;
}
// FUN_003AF460
u64 FUN_003af460(u64 unused, int context)
{
  u8* data;
  u8 low;
  u8 high;
  int base;
  int offset;

  offset = *(int *)(context + 0x18);
  base = *(int *)(context + 0x10);
  data = (u8 *)(base + offset);
  low = data[0] - 1;
  if (data[1] == 0xff)
  {
    high = 0;
  }
  else
  {
    high = data[1] - 1;
  }
  D_0095ABE8[0] = (u32)high << 8 | low;

  offset = *(int *)(context + 0x18);
  base = *(int *)(context + 0x10);
  data = (u8 *)(offset + base);
  low = data[2] - 1;
  if (data[3] == 0xff)
  {
    high = 0;
  }
  else
  {
    high = data[3] - 1;
  }
  D_0095ABEC[0] = (u32)high << 8 | low;
  return 0;
}


#undef FUN_003af520
// FUN_003AF520


u64 FUN_003af520(void)



{

  s16 uVar1;

  

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
// FUN_003AF5A0
u64 FUN_003af5a0(u32 param_1,int param_2)
{
  u8 bVar1;
  u8 bVar2;
  short sVar5;
  u8 *pbVar4;
  int base;
  int offset;
  u32 uVar8;

  offset = *(volatile int *)(param_2 + 0x18);
  base = *(volatile int *)(param_2 + 0x10);
  pbVar4 = (u8 *)(base + offset);
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
  uGpffffa7f8 = uGpffffa7f8 | 0x80;
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
#pragma opt_loop_invariants on






void FUN_003af7a0(int param_1, u64 param_2)
{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  u32 *puVar6;

  *(u32 *)DAT_0095ae10_abs = 0;
  *(u32 *)DAT_0095ae14_abs = 0;
  *(u32 *)DAT_0095ae18_abs = 0;

  iVar5 = 0;
  puVar6 = (u32 *)DAT_0095ad0c_abs;
  for (; iVar5 < 9; iVar5++) {
    puVar6[iVar5 * 8 + 7] = 0;
  }

  iVar4 = (int)param_1 >> 4;
  if (param_1 < 0) {
    iVar4 = ((int)param_1 + 0xf) >> 4;
  }

  *(u32 *)DAT_0095ae2c_abs = 0x200;
  iVar3 = 0;
  for (uVar1 = 0x200; uVar1 != 0; uVar1 >>= 1) {
    iVar3++;
  }

  uVar1 = iVar4 << 5;
  uVar2 = 0;
  if (uVar1 != 0) {
    for (; uVar1 != 0; uVar1 >>= 1) {
      uVar2++;
    }
    uVar2 = (uVar2 - 1) & 0xff;
  }
  *(u32 *)DAT_0095ae34_abs = 1 << ((uVar2 + 1) & 0x1f);

  *(u32 *)DAT_0095ae38_abs = 0;
  uVar2 = *(u32 *)DAT_0095ae34_abs;
  if (uVar2 != 0) {
    for (; uVar2 != 0; uVar2 >>= 1) {
      (*(u32 *)DAT_0095ae38_abs)++;
    }
    (*(u32 *)DAT_0095ae38_abs)--;
    *(u32 *)DAT_0095ae38_abs &= 0xff;
  }

  iVar3 = 0;
  do {
    iVar3++;
  } while (iVar3 < 6);
  *(u32 *)DAT_0095ae40_abs = iVar3;

  FUN_003b41a0(*(u32 *)DAT_0095ae2c_abs, 0x10, iVar4, 0x20, 0x20, 0x10);

  *(u32 *)DAT_0095ae1c_abs = FUN_003b45f0(0x2c, (int)param_2 << 2);
  *(u32 *)DAT_0095ae20_abs = FUN_003b45f0(0x44, param_2);
  FUN_003afc70();
  FUN_003aff50();

  puVar6 = (u32 *)DAT_0095ad0c_abs;
  for (iVar3 = 0; iVar3 < 0x20; iVar3++) {
    puVar6[iVar3] = 0;
  }

  FUN_005225a8(0x6a2740, 0x6a2730);
  DAT_007ce648 = iVar4 << 4;
  FUN_003b35e0(param_2);
}
#pragma opt_loop_invariants off
#define FUN_003af7a0(...) ((void (*)(...))FUN_003af7a0)(__VA_ARGS__)
