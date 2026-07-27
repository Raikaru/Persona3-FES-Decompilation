#include "temporary.h"
#ifndef SQRT
#define SQRT(x) sqrtf(x)
#endif
#pragma alias FUN_0052e878_f32 FUN_0052e878
extern f32 FUN_0052e878_f32(f32 value);
#pragma alias FUN_0052e9e8_f32 FUN_0052e9e8
extern f32 FUN_0052e9e8_f32(void);
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern u32 DAT_006a3e50;
#pragma alias DAT_006a3e50_abs DAT_006a3e50
extern u32 DAT_006a3e50_abs[];
extern u32 DAT_006a3e60;
#pragma alias DAT_006a3e60_abs DAT_006a3e60
extern u8 DAT_006a3e60_abs[];
#define DAT_006a3e60 (*(u32*)DAT_006a3e60_abs)
extern s32 DAT_006a3e90[];
extern s32 DAT_006a3eb0[];
extern u32 DAT_007cae18;
extern u32 DAT_007cb01c;
extern u16 DAT_007e094c;
extern u16 DAT_007e094e;
extern u16 DAT_007e0952;
extern u16 DAT_007e0956;
extern u16 DAT_007e0958;
extern u16 DAT_007e095a;
extern u32 DAT_0095be90;
extern u32 gp0xffffaa08;
extern char DAT_006a3e18[];
extern char DAT_006a3e30[];
#pragma alias DAT_0095be90_ptr DAT_0095be90
extern u32 DAT_0095be90_ptr[];
extern u32 DAT_0095be94;
extern u32 DAT_0095be95;
extern u32 DAT_0095be98;
extern u32 DAT_0095be9c;
extern u32 DAT_0095be9d;

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

extern void FUN_003b2cb0(float param_1,int param_2,int param_3,u32 param_4,
                         u32 param_5,u32 param_6,u32 param_7,u32 param_8,u32 param_9);
#pragma alias FUN_003c63f0_typed FUN_003c63f0
extern u64 FUN_003c63f0_typed(int param_1);
#pragma alias FUN_003c4e70_typed FUN_003c4e70
extern void FUN_003c4e70_typed(int param_1);
#pragma alias FUN_003c6f80_typed FUN_003c6f80
extern u32 FUN_003c6f80_typed(int param_1);
#pragma alias FUN_003c75b0_typed FUN_003c75b0
extern u64 FUN_003c75b0_typed(void);
#pragma alias FUN_003a4360_typed FUN_003a4360
extern u64 FUN_003a4360_typed(u64 param_1,long param_2);
#pragma alias FUN_003a27c0_typed FUN_003a27c0
extern void FUN_003a27c0_typed(int param_1,s16 param_2);
#pragma alias FUN_003a2830_nm_typed FUN_003a2830
extern u32 FUN_003a2830_nm_typed(int param_1);
#pragma alias FUN_003a2750_nm_typed FUN_003a2750
extern int FUN_003a2750_nm_typed(int param_1);
extern u8 DAT_0095be90_abs[];
#pragma alias FUN_003c7d50_ptr FUN_003c7d50
extern u8 *FUN_003c7d50_ptr(void);
#pragma alias FUN_003c6380_typed FUN_003c6380
extern u64 FUN_003c6380_typed(int param_1);
#pragma alias FUN_003c6900_typed FUN_003c6900
extern void FUN_003c6900_typed(int param_1);
#pragma alias FUN_003c69d0_typed FUN_003c69d0
extern void FUN_003c69d0_typed(int param_1);
#pragma alias FUN_003c6b70_typed FUN_003c6b70
extern u64 FUN_003c6b70_typed(int param_1);
#pragma alias FUN_003c6c50_typed FUN_003c6c50
extern u32 FUN_003c6c50_typed(int param_1);
#pragma alias FUN_003c6c80_typed FUN_003c6c80
extern u32 FUN_003c6c80_typed(int param_1);
#pragma alias FUN_003c7c90_typed FUN_003c7c90
extern void FUN_003c7c90_typed(int param_1);
#pragma alias FUN_005225a8_nm3 FUN_005225a8
extern void FUN_005225a8_nm3(const void *,const void *,int);
#pragma alias FUN_005225a8_nm1 FUN_005225a8
extern void FUN_005225a8_nm1(const void *);
#pragma alias FUN_001052b0_nm1 FUN_001052b0
extern void FUN_001052b0_nm1(const void *);
/* Region 0x390000-0x3CFFFF recovered prototypes */
void FUN_003c5e20(int param_1,u32 param_2);
void FUN_003c5e80(int param_1,u32 param_2);
void FUN_003c5ee0(int param_1,u32 param_2);
void FUN_003c5f40(int param_1,u32 param_2);
void FUN_003c5fa0(int param_1,int param_2);
u32 FUN_003c60c0(int param_1,int param_2);
u64 FUN_003c60f0(int param_1);
u32 FUN_003c6120(int param_1,int param_2);
u32 FUN_003c6270(int param_1);
u32 FUN_003c6380(int param_1);
u64 FUN_003c63f0(int param_1);
void FUN_003c6900(int param_1);
void FUN_003c69d0(int param_1);
u64 FUN_003c6b70(int param_1);
u32 FUN_003c6c50(int param_1);
u32 FUN_003c6c80(int param_1);
u32 FUN_003c6ca0(int param_1);
u32 FUN_003c6cc0(int param_1);
u32 FUN_003c6ce0(int param_1);
u32 FUN_003c6d10(int param_1);
void FUN_003c6d40(int param_1,u32 param_2,u32 param_3);
u64 FUN_003c6d60(int param_1,u32 param_2);
u32 FUN_003c6d80(int param_1);
u64 FUN_003c6e10(int param_1);
void FUN_003c6ea0(int param_1);
void FUN_003c6ec0(int param_1);
void FUN_003c6ee0(int param_1);
void FUN_003c6f10(int param_1);
void FUN_003c6f50(int param_1);
u32 FUN_003c6f80(int param_1);
int FUN_003c6fb0(int param_1);
void FUN_003c7000(int param_1);
void FUN_003c7070(float param_1,float *param_2,float *param_3,float *param_4);
void FUN_003c7270(void);
void FUN_003c72a0(int param_1);
#pragma alias FUN_003c72a0_typed FUN_003c72a0
extern void FUN_003c72a0_typed(u32 param_1);
u8 FUN_003c72d0(u64 param_1);
void FUN_003c7390(u64 param_1);
void FUN_003c73e0(u64 param_1);
u32 FUN_003c7430(u64 param_1);
u32 FUN_003c74e0(int param_1);
void FUN_003c7560(u8 param_1);
u32 FUN_003c75b0(void);
s8 FUN_003c7610(void);
u32 FUN_003c7650(int param_1);
u32 FUN_003c7700(void);
u32 FUN_003c77a0(void);
s8 FUN_003c7850(void);
u32 FUN_003c78d0(void);
void FUN_003c7990(long param_1);
#pragma alias FUN_003c7990_typed FUN_003c7990
extern void FUN_003c7990_typed(long param_1);
void FUN_003c7b90(void);
void FUN_003c7bc0(u64 param_1,u64 param_2);
void FUN_003c7c20(u64 param_1,u64 param_2,u64 param_3);
void FUN_003c7c90(int param_1);
u32 FUN_003c7d50(void);
u32 FUN_003c7d60(int param_1);
void FUN_003c7d80(int param_1,u64 param_2);
void FUN_003c7dd0(int param_1);
#pragma alias FUN_003a3060_typed FUN_003a3060
extern void FUN_003a3060_typed(s32 param_1);
void FUN_003c7e20(u32 p1,u64 p2,u64 p3,u64 p4,u64 p5,u64 p6,u64 p7);
u64  FUN_003c7e50(u32 param_1,u64 param_2,u64 param_3,u64 param_4,  u64 param_5,u64 param_6,u64 param_7,long param_8,u32 param_9);
u64 FUN_003c8230(s32 *param_1,int param_2);
u64 FUN_003c82e0(int param_1);
u8 FUN_003c83b0(void);

/* Region call-cast macros */
#define FUN_003c5e20(...) ((void (*)(...))FUN_003c5e20)(__VA_ARGS__)
#define FUN_003c5e80(...) ((void (*)(...))FUN_003c5e80)(__VA_ARGS__)
#define FUN_003c5ee0(...) ((void (*)(...))FUN_003c5ee0)(__VA_ARGS__)
#define FUN_003c5f40(...) ((void (*)(...))FUN_003c5f40)(__VA_ARGS__)
#define FUN_003c5fa0(...) ((void (*)(...))FUN_003c5fa0)(__VA_ARGS__)
#define FUN_003c60f0(...) ((u64 (*)(...))FUN_003c60f0)(__VA_ARGS__)
#define FUN_003c6120(...) ((u32 (*)(...))FUN_003c6120)(__VA_ARGS__)
#define FUN_003c6270(...) ((u32 (*)(...))FUN_003c6270)(__VA_ARGS__)
#define FUN_003c6380(...) ((u64 (*)(...))FUN_003c6380)(__VA_ARGS__)
#define FUN_003c63f0(...) ((u64 (*)(...))FUN_003c63f0)(__VA_ARGS__)
#define FUN_003c6900(...) ((void (*)(...))FUN_003c6900)(__VA_ARGS__)
#define FUN_003c69d0(...) ((void (*)(...))FUN_003c69d0)(__VA_ARGS__)
#define FUN_003c6b70(...) ((u64 (*)(...))FUN_003c6b70)(__VA_ARGS__)
#define FUN_003c6c50(...) ((u32 (*)(...))FUN_003c6c50)(__VA_ARGS__)
#define FUN_003c6c80(...) ((u32 (*)(...))FUN_003c6c80)(__VA_ARGS__)
#define FUN_003c6ca0(...) ((u32 (*)(...))FUN_003c6ca0)(__VA_ARGS__)
#define FUN_003c6cc0(...) ((u32 (*)(...))FUN_003c6cc0)(__VA_ARGS__)
#define FUN_003c6ce0(...) ((u32 (*)(...))FUN_003c6ce0)(__VA_ARGS__)
#define FUN_003c6d10(...) ((u32 (*)(...))FUN_003c6d10)(__VA_ARGS__)
#define FUN_003c6d40(...) ((void (*)(...))FUN_003c6d40)(__VA_ARGS__)
#define FUN_003c6d60(...) ((u64 (*)(...))FUN_003c6d60)(__VA_ARGS__)
#define FUN_003c6d80(...) ((u32 (*)(...))FUN_003c6d80)(__VA_ARGS__)
#define FUN_003c6e10(...) ((u64 (*)(...))FUN_003c6e10)(__VA_ARGS__)
#define FUN_003c6ea0(...) ((void (*)(...))FUN_003c6ea0)(__VA_ARGS__)
#define FUN_003c6ec0(...) ((void (*)(...))FUN_003c6ec0)(__VA_ARGS__)
#define FUN_003c6ee0(...) ((void (*)(...))FUN_003c6ee0)(__VA_ARGS__)
#define FUN_003c6f10(...) ((void (*)(...))FUN_003c6f10)(__VA_ARGS__)
#define FUN_003c6f50(...) ((void (*)(...))FUN_003c6f50)(__VA_ARGS__)
#define FUN_003c6f80(...) ((u32 (*)(...))FUN_003c6f80)(__VA_ARGS__)
#define FUN_003c6fb0(...) ((int (*)(...))FUN_003c6fb0)(__VA_ARGS__)
#define FUN_003c7000(...) ((void (*)(...))FUN_003c7000)(__VA_ARGS__)
#define FUN_003c7070(...) ((void (*)(...))FUN_003c7070)(__VA_ARGS__)
#define FUN_003c7270(...) ((void (*)(...))FUN_003c7270)(__VA_ARGS__)
#define FUN_003c72a0(...) ((void (*)(...))FUN_003c72a0)(__VA_ARGS__)
#define FUN_003c72d0(...) ((u8 (*)(...))FUN_003c72d0)(__VA_ARGS__)
#define FUN_003c7390(...) ((void (*)(...))FUN_003c7390)(__VA_ARGS__)
#define FUN_003c73e0(...) ((void (*)(...))FUN_003c73e0)(__VA_ARGS__)
#define FUN_003c7430(...) ((u32 (*)(...))FUN_003c7430)(__VA_ARGS__)
#define FUN_003c74e0(...) ((u32 (*)(...))FUN_003c74e0)(__VA_ARGS__)
#define FUN_003c7560(...) ((void (*)(...))FUN_003c7560)(__VA_ARGS__)
#define FUN_003c75b0(...) ((u64 (*)(...))FUN_003c75b0)(__VA_ARGS__)
#define FUN_003c7610(...) ((s8 (*)(...))FUN_003c7610)(__VA_ARGS__)
#define FUN_003c7650(...) ((u32 (*)(...))FUN_003c7650)(__VA_ARGS__)
#define FUN_003c7700(...) ((u32 (*)(...))FUN_003c7700)(__VA_ARGS__)
#define FUN_003c77a0(...) ((u32 (*)(...))FUN_003c77a0)(__VA_ARGS__)
#define FUN_003c7850(...) ((s8 (*)(...))FUN_003c7850)(__VA_ARGS__)
#define FUN_003c78d0(...) ((u32 (*)(...))FUN_003c78d0)(__VA_ARGS__)
#define FUN_003c7990(...) ((void (*)(...))FUN_003c7990)(__VA_ARGS__)
#define FUN_003c7b90(...) ((void (*)(...))FUN_003c7b90)(__VA_ARGS__)
#define FUN_003c7bc0(...) ((void (*)(...))FUN_003c7bc0)(__VA_ARGS__)
#define FUN_003c7c20(...) ((void (*)(...))FUN_003c7c20)(__VA_ARGS__)
#define FUN_003c7c90(...) ((void (*)(...))FUN_003c7c90)(__VA_ARGS__)
#define FUN_003c7d50(...) ((u32 (*)(...))FUN_003c7d50)(__VA_ARGS__)
#define FUN_003c7d60(...) ((u32 (*)(...))FUN_003c7d60)(__VA_ARGS__)
#define FUN_003c7d80(...) ((void (*)(...))FUN_003c7d80)(__VA_ARGS__)
#define FUN_003c7dd0(...) ((void (*)(...))FUN_003c7dd0)(__VA_ARGS__)
#define FUN_003c7e20(...) ((void (*)(...))FUN_003c7e20)(__VA_ARGS__)
#define FUN_003c7e50(...) ((u64 (*)(...))FUN_003c7e50)(__VA_ARGS__)
#define FUN_003c8230(...) ((u64 (*)(...))FUN_003c8230)(__VA_ARGS__)
#define FUN_003c82e0(...) ((u64 (*)(...))FUN_003c82e0)(__VA_ARGS__)
#define FUN_003c83b0(...) ((u8 (*)(...))FUN_003c83b0)(__VA_ARGS__)

#undef FUN_003c5e20
// FUN_003C5E20


void FUN_003c5e20(int param_1,u32 param_2)



{

  if (param_2 == 0) {

    FUN_0019d3f0("nmCmdList.c",0x144);

  }

  *(int *)(*(int *)(param_1 + 0x24) + 0x34) = (int)param_2;

  return;

}
#define FUN_003c5e20(...) ((void (*)(...))FUN_003c5e20)(__VA_ARGS__)
#undef FUN_003c5e80
// FUN_003C5E80


void FUN_003c5e80(int param_1,u32 param_2)



{

  if (param_2 == 0) {

    FUN_0019d3f0("nmCmdList.c",0x153);

  }

  *(int *)(*(int *)(param_1 + 0x24) + 0x38) = (int)param_2;

  return;

}
#define FUN_003c5e80(...) ((void (*)(...))FUN_003c5e80)(__VA_ARGS__)
#undef FUN_003c5ee0
// FUN_003C5EE0


void FUN_003c5ee0(int param_1,u32 param_2)



{

  if (param_2 == 0) {

    FUN_0019d3f0("nmCmdList.c",0x172);

  }

  *(int *)(*(int *)(param_1 + 0x24) + 0x30) = (int)param_2;

  return;

}
#define FUN_003c5ee0(...) ((void (*)(...))FUN_003c5ee0)(__VA_ARGS__)
#undef FUN_003c5f40
// FUN_003C5F40


void FUN_003c5f40(int param_1,u32 param_2)



{

  if (param_2 == 0) {

    FUN_0019d3f0("nmCmdList.c",0x181);

  }

  *(int *)(*(int *)(param_1 + 0x24) + 0x40) = (int)param_2;

  return;

}
#define FUN_003c5f40(...) ((void (*)(...))FUN_003c5f40)(__VA_ARGS__)
#undef FUN_003c5fa0
// FUN_003C5FA0 NONMATCHING


void FUN_003c5fa0(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar2 = (int)param_1;

  iVar1 = *(int *)(iVar2 + 0x24);

  iVar4 = *(int *)(iVar2 + 8);

  iVar2 = FUN_003c49e0(param_1,iVar2 + 4,param_2);

  if (iVar4 != param_2) {

    if (param_2 == *(int *)(iVar1 + 0x2c)) {

      *(int *)(iVar1 + 0x2c) = iVar2;

    }

    for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {

      *(int *)(*(int *)(iVar2 + 0x14) + 0xc) = *(int *)(*(int *)(iVar2 + 0x14) + 0xc) + -1;

    }

  }

  iVar3 = *(int *)(iVar1 + 0x2c);

  iVar2 = iVar3;

  for (iVar4 = *(int *)(iVar1 + 0x20); (iVar2 != 0 && (iVar4 != 0)); iVar4 = iVar4 + -1) {

    iVar2 = *(int *)(iVar2 + 0x10);

  }

  if ((iVar2 == 0) && (iVar4 != 0)) {

    while ((iVar4 != 0 && (iVar3 != 0))) {

      iVar3 = *(int *)(iVar3 + 0xc);

      if (iVar3 != 0) {

        *(int *)(iVar1 + 0x2c) = iVar3;

      }

      iVar4 = iVar4 + -1;

    }

  }

  return;

}
#define FUN_003c5fa0(...) ((void (*)(...))FUN_003c5fa0)(__VA_ARGS__)
#undef FUN_003c60c0
// FUN_003C60C0
u32 FUN_003c60c0(int param_1,int param_2)
{
  u32 *puVar1;
  u32 *puVar2;
  u32 uVar3;

  puVar1 = *(u32 **)(param_1 + 0x24);
  puVar2 = *(u32 **)(param_2 + 0x14);
  uVar3 = puVar1[4] + 1;
  puVar1[4] = uVar3;
  puVar2[3] = uVar3;
  return 0;
}
#define FUN_003c60c0(...) ((u32 (*)(...))FUN_003c60c0)(__VA_ARGS__)
#undef FUN_003c60f0
// FUN_003C60F0


u64 FUN_003c60f0(int param_1)



{

  (*(code *)(*(int *)(param_1 + 0x24) + 0x40))();

  return 0;

}
#define FUN_003c60f0(...) ((u64 (*)(...))FUN_003c60f0)(__VA_ARGS__)
#undef FUN_003c6120
// FUN_003C6120 NONMATCHING

u32 FUN_003c6120(int param_1,int param_2)
{
  u32 *puVar1;
  u32 *puVar2;
  int iVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  int iVar5;
  u32 uVar7;
  u32 uVar8;
  u32 uVar9;
  u32 uVar10;
  u32 uVar11;

  puVar1 = *(u32 **)(param_1 + 0x24);
  puVar2 = *(u32 **)(param_2 + 0x14);
  iVar3 = *(int *)(*(int *)(puVar1[0xb] + 0x14) + 0xc);
  uVar4 = puVar2[3];
  if ((int)uVar4 < iVar3) {
    return 0;
  }
  uVar11 = (u32)((int)uVar4 < (int)(puVar1[8] + iVar3));
  if (uVar11 == 0) {
    return 0;
  }
  uVar5 = puVar1[5];
  uVar6 = puVar1[6];
  iVar5 = puVar1[3] * ((int)uVar4 - iVar3);
  puVar2[4] = puVar1[7];
  if ((*puVar1 & 0x800) != 0) {
    puVar2[0] = uVar5 + iVar5;
    puVar2[1] = uVar6;
  } else {
    puVar2[0] = uVar5;
    puVar2[1] = uVar6 + iVar5;
  }
  if (puVar2[2] != 0) {
    FUN_003b2cb0(0.0f,puVar2[0],puVar2[1],puVar2[4] | 0xffffff00,
                 (u32)(param_2 == *(int *)(param_1 + 0xc)),4,puVar2[2],0x10,0);
  }
  ((code)puVar1[0xc])(puVar2[0],puVar2[1],puVar2[4],param_1,param_2);
  return 0;
}
#define FUN_003c6120(...) ((u32 (*)(...))FUN_003c6120)(__VA_ARGS__)
#undef FUN_003c6270
// FUN_003C6270

u32 FUN_003c6270(int param_1)
{
  u32 *puVar1;
  u32 uVar2;
  u32 uVar3;

  puVar1 = *(u32 **)(param_1 + 0x24);
  FUN_003c63f0_typed(param_1);
  FUN_003c6900_typed(param_1);
  FUN_003c69d0_typed(param_1);
  FUN_003c6b70_typed(param_1);
  ((code)puVar1[0xe])(param_1);
  if ((*puVar1 & 0x1000) == 0) {
    FUN_003c6380_typed(param_1);
  }
  if ((*puVar1 & 0x200) != 0) {
    uVar3 = FUN_003c6c50_typed(param_1);
    if (uVar3 != 0) {
      return *(u32 *)uVar3;
    }
    uVar3 = FUN_003c6c80_typed(param_1);
    if (uVar3 != 0) {
      return 1;
    }
  }
  if ((*puVar1 & 2) == 0) {
    uVar2 = ((*puVar1 & 1) != 0) ? 3 : 2;
  } else {
    uVar2 = 0;
  }
  return uVar2;
}
#define FUN_003c6270(...) ((u32 (*)(...))FUN_003c6270)(__VA_ARGS__)
#undef FUN_003c6380
// FUN_003C6380 NONMATCHING


u32 FUN_003c6380(int param_1)
{
  int iVar2;
  u32 *puVar1;

  iVar2 = param_1;
  puVar1 = *(u32 **)((int)param_1 + 0x24);

  (*(code *)puVar1[0xd])(puVar1[5],puVar1[6],puVar1[7],iVar2);

  if ((*puVar1 & 0x40) != 0) {
    FUN_003c4e70(puVar1);
  }

  return 0;
}
#define FUN_003c6380(...) ((u32 (*)(...))FUN_003c6380)(__VA_ARGS__)
#undef FUN_003c63f0
// FUN_003C63F0 NONMATCHING

u64 FUN_003c63f0(int param_1)



{

  u32 *puVar1;

  int iVar2;

  u8 bVar3;

  int iVar4;

  long lVar5;


  u32 uVar7;

  int iVar8;

  


  puVar1 = *(u32 **)(param_1 + 0x24);

  uVar7 = *puVar1;

  *puVar1 = uVar7 & 0xffffffef;
  *puVar1 = uVar7 & 0xffffffcf;
  *puVar1 = uVar7 & 0xffffbfcf;
  *puVar1 = uVar7 & 0xffff9fcf;
  *puVar1 = uVar7 & 0xfffe9fcf;
  *puVar1 = uVar7 & 0xfffe1fcf;

  if (((uVar7 & 4) != 0) && ((uVar7 & 0x400) == 0)) {

    if ((uVar7 & 0x800) == 0) {

      if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {

        if (((DAT_007e0952 & 0x4000) != 0) || ((DAT_007e095a & 0x4000) != 0)) {

          iVar2 = *(int *)(param_1 + 0x24);

          iVar4 = FUN_003c4c80(param_1,param_1 + 4);

          if (iVar4 != 0) {

            uVar7 = (*(int *)(iVar2 + 0x20) +

                    *(int *)(*(int *)(*(int *)(iVar2 + 0x2c) + 0x14) + 0xc)) - 1;

            if (*(u32 *)(*(int *)(iVar4 + 0x14) + 0xc) < uVar7) {

              if (iVar4 == *(int *)(param_1 + 4)) {

                *(int *)(iVar2 + 0x2c) = iVar4;

              }

            }

            else if (uVar7 != *(u16 *)(param_1 + 0x10)) {

              *(u32 *)(iVar2 + 0x2c) = *(u32 *)(*(int *)(iVar2 + 0x2c) + 0x10);

            }

          }

          if (iVar4 != 0) {

            *puVar1 = *puVar1 | 0x2000;

          }

        }

      }

      else {

        lVar5 = FUN_003c5af0(param_1);

        if (lVar5 != 0) {

          *puVar1 = *puVar1 | 0x4000;

        }

      }

    }

    else if (((DAT_007e0952 & 0x8000) == 0) && ((DAT_007e095a & 0x8000) == 0)) {

      if (((DAT_007e0952 & 0x2000) != 0) || ((DAT_007e095a & 0x2000) != 0)) {

        iVar2 = *(int *)(param_1 + 0x24);

        iVar4 = FUN_003c4c80(param_1,param_1 + 4);

        if (iVar4 != 0) {

          uVar7 = (*(int *)(iVar2 + 0x20) + *(int *)(*(int *)(*(int *)(iVar2 + 0x2c) + 0x14) + 0xc))

                  - 1;

          if (*(u32 *)(*(int *)(iVar4 + 0x14) + 0xc) < uVar7) {

            if (iVar4 == *(int *)(param_1 + 4)) {

              *(int *)(iVar2 + 0x2c) = iVar4;

            }

          }

          else if (uVar7 != *(u16 *)(param_1 + 0x10)) {

            *(u32 *)(iVar2 + 0x2c) = *(u32 *)(*(int *)(iVar2 + 0x2c) + 0x10);

          }

        }

        if (iVar4 != 0) {

          *puVar1 = *puVar1 | 0x2000;

        }

      }

    }

    else {

      lVar5 = FUN_003c5af0(param_1);

      if (lVar5 != 0) {

        *puVar1 = *puVar1 | 0x4000;

      }

    }

    uVar7 = *puVar1;

    if (((uVar7 & 0x4000) == 0) && ((uVar7 & 0x2000) == 0)) {

      if (((DAT_007e0952 & 1) == 0) && ((DAT_007e095a & 1) == 0)) {

        if (((DAT_007e0952 & 2) == 0) && ((DAT_007e095a & 2) == 0)) {

          if (((DAT_007e094e & 0x40) == 0) && ((DAT_007e0958 & 0x40) == 0)) {

            if (((DAT_007e094e & 0x20) == 0) && ((DAT_007e0958 & 0x20) == 0)) {

              if ((uVar7 & 0x800) == 0) {

                bVar3 = 1;

                if (((DAT_007e094c & 0x1000) == 0) && ((DAT_007e0956 & 0x1000) == 0)) {

                  bVar3 = 0;

                }

                if ((!bVar3) && ((DAT_007e094c & 0x4000) == 0 && (DAT_007e0956 & 0x4000) == 0)) {

                  FUN_003c4dc0(param_1,param_1 + 4);

                }

              }

              else {

                bVar3 = 1;

                if (((DAT_007e094c & 0x8000) == 0) && ((DAT_007e0956 & 0x8000) == 0)) {

                  bVar3 = 0;

                }

                if ((!bVar3) && ((DAT_007e094c & 0x2000) == 0 && (DAT_007e0956 & 0x2000) == 0)) {

                  FUN_003c4dc0(param_1,param_1 + 4);

                }

              }

            }

            else {

              *puVar1 = *puVar1 | 0x20;

            }

          }

          else {

            *puVar1 = *puVar1 | 0x10;

          }

        }

        else {

          lVar5 = FUN_003c5c50(param_1);

          if (lVar5 != 0) {

            *puVar1 = *puVar1 | 0x8000;

          }

        }

      }

      else {

        lVar5 = 0;

        iVar2 = *(int *)(param_1 + 0x24);

        iVar4 = *(int *)(iVar2 + 0x20);

        iVar8 = 0;

        while ((iVar8 < iVar4 && (*(int *)(iVar2 + 0x2c) != *(int *)(param_1 + 4)))) {

          *(u32 *)(iVar2 + 0x2c) = *(u32 *)(*(int *)(iVar2 + 0x2c) + 0xc);

          lVar5 = FUN_003c4d20(param_1,param_1 + 4);

          iVar8 = iVar8 + 1;

        }

        if (lVar5 != 0) {

          *puVar1 = *puVar1 | 0x10000;

        }

      }

    }

  }

  (*(code *)puVar1[0xf])(param_1);

  return 0;

}
#define FUN_003c63f0(...) ((u64 (*)(...))FUN_003c63f0)(__VA_ARGS__)
#undef FUN_003c6900
// FUN_003C6900


void FUN_003c6900(int param_1)



{
  u32 *puVar1;
  int uVar2;

  puVar1 = *(u32 **)(param_1 + 0x24);
  uVar2 = *puVar1;
  if ((uVar2 & 8) != 0) {
    if ((uVar2 & 0x100000) != 0) {
      uVar2 = uVar2 & 0xfffffffb;
      *puVar1 = uVar2;
      uVar2 = uVar2 & 0xffefffff;
      *puVar1 = uVar2;
      uVar2 = uVar2 & 0xfffffffe;
      *puVar1 = uVar2;
      *(u16 *)((int)puVar1 + 10) = 1;
    } else if ((uVar2 & 0x200000) != 0) {
      uVar2 = uVar2 & 0xfffffffb;
      *puVar1 = uVar2;
      uVar2 = uVar2 & 0xffdfffff;
      *puVar1 = uVar2;
      *(u16 *)((int)puVar1 + 10) = 3;
    }
    uVar2 = *puVar1;
    if ((uVar2 & 0x400000) != 0) {
      uVar2 = uVar2 & 0xfffffffb;
      *puVar1 = uVar2;
      uVar2 = uVar2 & 0xffbfffff;
      *puVar1 = uVar2;
      uVar2 = uVar2 | 1;
      *puVar1 = uVar2;
  }
}
}
#define FUN_003c6900(...) ((void (*)(...))FUN_003c6900)(__VA_ARGS__)
#undef FUN_003c69d0


typedef struct {
  u32 flags;
  short counter;
  short duration1;
  short duration2;
  short state;
  u8 pad[0x10];
  u32 value;
} NmCmdState;

// FUN_003C69D0 NONMATCHING
void FUN_003c69d0(int param_1)
{
  NmCmdState *puVar1;
  short sVar2;
  u32 uVar3;

  puVar1 = *(NmCmdState **)(param_1 + 0x24);
  switch (puVar1->state) {
  case 0:
    break;
  case 1:
    uVar3 = puVar1->flags & 0xfffffff7;
    puVar1->flags = uVar3;
    uVar3 |= 2;
    puVar1->flags = uVar3;
    uVar3 |= 0x40;
    puVar1->flags = uVar3;
    uVar3 |= 0x80;
    puVar1->flags = uVar3;
    puVar1->state = 2;
    puVar1->counter = 0;
  case 2:
    sVar2 = puVar1->counter + 1;
    puVar1->counter = sVar2;
    puVar1->value = (sVar2 * 0xff) / (int)puVar1->duration1;
    if (sVar2 < puVar1->duration1) {
      break;
    }
    puVar1->value = 0xff;
    puVar1->counter = 0;
    uVar3 = puVar1->flags;
    uVar3 |= 8;
    puVar1->flags = uVar3;
    uVar3 |= 4;
    puVar1->flags = uVar3;
    uVar3 &= 0xffffff7f;
    puVar1->flags = uVar3;
    puVar1->state = 5;
    break;
  case 3:
    uVar3 = puVar1->flags & 0xfffffff7;
    puVar1->flags = uVar3;
    uVar3 &= 0xfffffffb;
    puVar1->flags = uVar3;
    uVar3 |= 0x100;
    puVar1->flags = uVar3;
    puVar1->state = 4;
    puVar1->counter = 0;
  case 4:
    sVar2 = puVar1->counter + 1;
    puVar1->counter = sVar2;
    puVar1->value = 0xff - (sVar2 * 0xff) / (int)puVar1->duration2;
    if (sVar2 < puVar1->duration2) {
      break;
    }
    puVar1->value = 0;
    puVar1->counter = 0;
    uVar3 = puVar1->flags;
    uVar3 |= 8;
    puVar1->flags = uVar3;
    uVar3 &= 0xfffffffd;
    puVar1->flags = uVar3;
    uVar3 |= 0x40;
    puVar1->flags = uVar3;
    uVar3 &= 0xfffffeff;
    puVar1->flags = uVar3;
    puVar1->state = 0;
    break;
  case 5:
    break;
  default:
    break;
  }
  return;
}
#define FUN_003c69d0(...) ((void (*)(...))FUN_003c69d0)(__VA_ARGS__)
#undef FUN_003c6b70
// FUN_003C6B70 NONMATCHING


u64 FUN_003c6b70(int param_1)



{

  u16 uVar1;

  int iVar2;

  int iVar3;

  int iVar4;
  int iVar6;

  int *piVar5;

  

  iVar2 = *(int *)(param_1 + 0x24);

  piVar5 = (int *)(iVar2 + 0x24);

  if (*(u16 *)(param_1 + 0x10) == 0) {

    *piVar5 = 0;

    *(u32 *)(iVar2 + 0x28) = 0;

  }

  else {

    iVar4 = *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x14) + 0xc) - 1;
    iVar6 = *(u16 *)(param_1 + 0x10) - 1;
    iVar3 = *(int *)(*(int *)(*(int *)(iVar2 + 0x2c) + 0x14) + 0xc);
    if (iVar6 < 1) {

      *piVar5 = 0;

    }

    else {

      *piVar5 = (iVar4 * 0xffff) / iVar6;

    }

    uVar1 = *(u16 *)(param_1 + 0x10);

    iVar6 = FUN_003c6f80_typed(param_1);

    iVar6 = (u32)uVar1 - iVar6;

    if (iVar6 < 1) {

      *(u32 *)(iVar2 + 0x28) = 0;

    }

    else {

      *(int *)(iVar2 + 0x28) = ((iVar3 + -1) * 0xffff) / iVar6;

    }

  }

  return 0;

}
#define FUN_003c6b70(...) ((u64 (*)(...))FUN_003c6b70)(__VA_ARGS__)
#undef FUN_003c6c50
// FUN_003C6C50


u32 FUN_003c6c50(int param_1)



{

  if ((**(u32 **)(param_1 + 0x24) & 0x10) != 0) {
    return *(u32 *)(param_1 + 0xc);
  }
  return 0;

}
#define FUN_003c6c50(...) ((u32 (*)(...))FUN_003c6c50)(__VA_ARGS__)
#undef FUN_003c6c80
// FUN_003C6C80


u32 FUN_003c6c80(int param_1)



{

  return **(u32 **)(param_1 + 0x24) & 0x20;

}
#define FUN_003c6c80(...) ((u32 (*)(...))FUN_003c6c80)(__VA_ARGS__)
#undef FUN_003c6ca0
// FUN_003C6CA0


u32 FUN_003c6ca0(int param_1)



{

  return **(u32 **)(param_1 + 0x24) & 0x8000;

}
#define FUN_003c6ca0(...) ((u32 (*)(...))FUN_003c6ca0)(__VA_ARGS__)
#undef FUN_003c6cc0
// FUN_003C6CC0


u32 FUN_003c6cc0(int param_1)



{

  return **(u32 **)(param_1 + 0x24) & 0x10000;

}
#define FUN_003c6cc0(...) ((u32 (*)(...))FUN_003c6cc0)(__VA_ARGS__)
#undef FUN_003c6ce0
// FUN_003C6CE0


u32 FUN_003c6ce0(int param_1)



{

  if ((**(u32 **)(param_1 + 0x24) & 0x2000) != 0) {
    return *(u32 *)(param_1 + 0xc);
  }
  return 0;

}
#define FUN_003c6ce0(...) ((u32 (*)(...))FUN_003c6ce0)(__VA_ARGS__)
#undef FUN_003c6d10
// FUN_003C6D10


u32 FUN_003c6d10(int param_1)



{

  if ((**(u32 **)(param_1 + 0x24) & 0x4000) != 0) {
    return *(u32 *)(param_1 + 0xc);
  }
  return 0;

}
#define FUN_003c6d10(...) ((u32 (*)(...))FUN_003c6d10)(__VA_ARGS__)
#undef FUN_003c6d40
// FUN_003C6D40


void FUN_003c6d40(int param_1,u32 param_2,u32 param_3)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x24);

  *(u32 *)(iVar1 + 0x14) = param_2;

  *(u32 *)(iVar1 + 0x18) = param_3;

  return;

}
#define FUN_003c6d40(...) ((void (*)(...))FUN_003c6d40)(__VA_ARGS__)
#undef FUN_003c6d60
// FUN_003C6D60


u64 FUN_003c6d60(int param_1,u32 param_2)



{

  **(u32 **)(param_1 + 0x24) = **(u32 **)(param_1 + 0x24) | param_2;

  return 0;

}
#define FUN_003c6d60(...) ((u64 (*)(...))FUN_003c6d60)(__VA_ARGS__)
#undef FUN_003c6d80
// FUN_003C6D80


u32 FUN_003c6d80(int param_1)
{
  u32 flags;
  u32 result;

  result = 0;
  flags = **(u32 **)(param_1 + 0x24);
  if ((flags & 0x400) != 0) {
    result |= 0x80000000;
  }
  if ((flags & 4) != 0) {
    result |= 0x40000000;
  }
  if ((flags & 2) != 0) {
    if ((flags & 0x100) != 0) {
      return result | 0x14;
    }
    if ((flags & 0x80) != 0) {
      return result | 0xc;
    }
    return result | 1;
  }
  return result | 2;
}
#define FUN_003c6d80(...) ((u32 (*)(...))FUN_003c6d80)(__VA_ARGS__)
#undef FUN_003c6e10
// FUN_003C6E10
 
 
u64 FUN_003c6e10(int param_1)
{
  u32 flags;
  u32 result;
  u32 temp;

  result = 0;
  flags = **(u32 **)(param_1 + 0x24);
  if ((flags & 0x400) != 0) {
    result |= 0x80000000;
  }
  if ((flags & 4) != 0) {
    result |= 0x40000000;
  }
  if ((flags & 2) != 0) {
    if ((flags & 0x100) != 0) {
      temp = result | 0x14;
      goto ret;
    }
    if ((flags & 0x80) != 0) {
      temp = result | 0xc;
      goto ret;
    }
    temp = result | 1;
    goto ret;
  }
  temp = result | 2;
ret:
  return temp & 0xfffffff;
}
#define FUN_003c6e10(...) ((u64 (*)(...))FUN_003c6e10)(__VA_ARGS__)
#undef FUN_003c6ea0
// FUN_003C6EA0


void FUN_003c6ea0(int param_1)



{

  **(u32 **)(param_1 + 0x24) = **(u32 **)(param_1 + 0x24) | 0x400;

  return;

}
#define FUN_003c6ea0(...) ((void (*)(...))FUN_003c6ea0)(__VA_ARGS__)
#undef FUN_003c6ec0
// FUN_003C6EC0


void FUN_003c6ec0(int param_1)



{

  **(u32 **)(param_1 + 0x24) = **(u32 **)(param_1 + 0x24) & 0xfffffbff;

  return;

}
#define FUN_003c6ec0(...) ((void (*)(...))FUN_003c6ec0)(__VA_ARGS__)
#undef FUN_003c6ee0
// FUN_003C6EE0


void FUN_003c6ee0(int param_1)



{

  u32 uVar1;

  

  uVar1 = **(u32 **)(param_1 + 0x24);

  if ((uVar1 & 2) == 0) {

    **(u32 **)(param_1 + 0x24) = uVar1 | 0x100000;

  }

  return;

}
#define FUN_003c6ee0(...) ((void (*)(...))FUN_003c6ee0)(__VA_ARGS__)
#undef FUN_003c6f10
// FUN_003C6F10


void FUN_003c6f10(int param_1)



{

  u32 uVar1;

  

  uVar1 = **(u32 **)(param_1 + 0x24);

  if (((uVar1 & 2) != 0) && ((uVar1 & 0x100) == 0)) {

    **(u32 **)(param_1 + 0x24) = uVar1 | 0x200000;

  }

  return;

}
#define FUN_003c6f10(...) ((void (*)(...))FUN_003c6f10)(__VA_ARGS__)
#undef FUN_003c6f50
// FUN_003C6F50


void FUN_003c6f50(int param_1)



{

  u32 *puVar1;

  u32 uVar2;

  

  puVar1 = *(u32 **)(param_1 + 0x24);

  uVar2 = *puVar1;

  *puVar1 = uVar2 | 0x400000;
  *puVar1 |= 0x200000;

  return;

}
#define FUN_003c6f50(...) ((void (*)(...))FUN_003c6f50)(__VA_ARGS__)
#undef FUN_003c6f80
// FUN_003C6F80


u32 FUN_003c6f80(int param_1)



{
  u32 uVar1;
  u32 uVar2;


  uVar2 = (u32)*(u16 *)(param_1 + 0x10);
  uVar1 = *(u32 *)(*(int *)(param_1 + 0x24) + 0x20);
  if ((int)uVar1 < (int)uVar2) {
    return uVar1;
  }
  return uVar2;

}
#define FUN_003c6f80(...) ((u32 (*)(...))FUN_003c6f80)(__VA_ARGS__)
#undef FUN_003c6fb0
#pragma push
#pragma opt_rebuildconditionals off
// FUN_003C6FB0


int FUN_003c6fb0(int param_1)
{
    int count;
    int current;
    int targetOwner;
    u32 atEnd;

    count = 0;
    targetOwner = *(volatile int *)(param_1 + 0x24);
    current = *(volatile int *)(param_1 + 0xc);
    param_1 = *(int *)(targetOwner + 0x2c);
    if (param_1 == 0)
    {
        goto done;
    }
    goto check;
loop:
    current = *(int *)(current + 0xc);
    count++;
check:
    atEnd = (current != 0) ^ 1;
    if (atEnd)
    {
        goto done;
    }
    if (param_1 != current)
    {
        goto loop;
    }
done:
    return count;
}
#pragma pop

#define FUN_003c6fb0(...) ((int (*)(...))FUN_003c6fb0)(__VA_ARGS__)
#undef FUN_003c7000
// FUN_003C7000


void FUN_003c7000(int param_1)



{

  int iVar2;

  int iVar1;

  int iVar3;

  

  FUN_003c4fc0();

  iVar1 = 1;

  iVar3 = (int)param_1;

  iVar2 = *(int *)(iVar3 + 4);

  while (iVar2 != 0) {

    *(int *)(*(int *)(iVar2 + 0x14) + 0xc) = iVar1;

    iVar2 = *(int *)(iVar2 + 0x10);

    iVar1 = iVar1 + 1;

  }

  *(u32 *)(*(int *)(iVar3 + 0x24) + 0x2c) = *(u32 *)(iVar3 + 4);

  FUN_003c6b70_typed(param_1);

  return;

}
#define FUN_003c7000(...) ((void (*)(...))FUN_003c7000)(__VA_ARGS__)
#undef FUN_003c7070
// FUN_003C7070 NONMATCHING


void FUN_003c7070(float param_1,float *param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float in_f5;

  float fVar3;

  

  fVar3 = param_3[2] * param_4[2] +
          *param_3 * *param_4 + param_3[1] * param_4[1];

  if ((fVar3 <= DAT_007cb01c) || (DAT_007cae18 <= fVar3)) {

    fVar3 = 1.0f - param_1;

    *param_2 = *param_3 * fVar3 + *param_4 * param_1;
    param_2[1] = param_3[1] * fVar3 + param_4[1] * param_1;
    param_2[2] = param_3[2] * fVar3 + param_4[2] * param_1;
    param_2[3] = param_3[3] * fVar3 + param_4[3] * param_1;

    fVar2 = *param_2;

    fVar3 = SQRT(param_2[3] * param_2[3] +

                 param_2[2] * param_2[2] + fVar2 * fVar2 + param_2[1] * param_2[1]);

    *param_2 = fVar2 / fVar3;

    param_2[1] = param_2[1] / fVar3;

    param_2[2] = param_2[2] / fVar3;

    param_2[3] = param_2[3] / fVar3;

  }

  else {

    fVar3 = (float)FUN_0052e9e8_f32();

    fVar2 = (float)FUN_0052e878_f32(fVar3 * (1.0f - param_1));

    fVar1 = (float)FUN_0052e878_f32(fVar3 * param_1);

    fVar3 = (float)FUN_0052e878_f32(fVar3);

    *param_2 = (*param_3 * fVar2 + *param_4 * fVar1) / fVar3;

    param_2[1] = (param_3[1] * fVar2 + param_4[1] * fVar1) / fVar3;

    param_2[2] = (param_3[2] * fVar2 + param_4[2] * fVar1) / fVar3;

    param_2[3] = (param_3[3] * fVar2 + param_4[3] * fVar1) / fVar3;

  }

  return;

}
#define FUN_003c7070(...) ((void (*)(...))FUN_003c7070)(__VA_ARGS__)
#undef FUN_003c7270
// FUN_003C7270


void FUN_003c7270(void)



{

  FUN_003c72a0_typed((u32)DAT_0095be90_ptr);

  return;

}
#define FUN_003c7270(...) ((void (*)(...))FUN_003c7270)(__VA_ARGS__)
#undef FUN_003c72a0
// FUN_003C72A0


void FUN_003c72a0(int param_1)



{

  u32 *puVar1;

  

  puVar1 = (u32 *)param_1;

  if (param_1 != 0) {

    *puVar1 = 0xffffffff;

    *(u8 *)(puVar1 + 1) = 0;

    *(u8 *)((int)puVar1 + 5) = 0;

    puVar1[2] = 0xffffffff;

    *(u8 *)(puVar1 + 3) = 1;

    *(u8 *)((int)puVar1 + 0xd) = 1;

  }

  return;

}
#define FUN_003c72a0(...) ((void (*)(...))FUN_003c72a0)(__VA_ARGS__)
#undef FUN_003c72d0
// FUN_003C72D0 NONMATCHING


u8 FUN_003c72d0(u64 param_1)



{

  extern u8 *FUN_003c7d50_direct(void);
  u8 bVar1;

  int iVar2;

  u8 *uVar3;

  

  DAT_0095be90 = 0xffffffff;

  DAT_0095be94 = 0;

  DAT_0095be95 = 0;

  DAT_0095be98 = 0xffffffff;

  DAT_0095be9c = 1;

  DAT_0095be9d = 1;

  uVar3 = FUN_003c7d50_direct();

  bVar1 = *(int *)uVar3 < 0;

  if (bVar1) {

    iVar2 = FUN_003a2d80(param_1);

    *(int *)uVar3 = iVar2;

    FUN_003c8230(uVar3,0);

  }

  return bVar1;

}
#define FUN_003c72d0(...) ((u8 (*)(...))FUN_003c72d0)(__VA_ARGS__)
#undef FUN_003c7390
// FUN_003C7390


void FUN_003c7390(u64 param_1)



{
  extern u8 *FUN_003c7d50_direct(void);

  u8 *lVar1;

  

  lVar1 = FUN_003c7d50_direct();

  if (lVar1 == 0)
    return;

  if (*(int *)lVar1 < 0)
    return;

  FUN_003a3e10(*(int *)lVar1,param_1);

  return;

}
#define FUN_003c7390(...) ((void (*)(...))FUN_003c7390)(__VA_ARGS__)
#undef FUN_003c73e0
// FUN_003C73E0


void FUN_003c73e0(u64 param_1)



{
  extern u8 *FUN_003c7d50_direct(void);

  u8 *lVar1;

  

  lVar1 = FUN_003c7d50_direct();

  if (lVar1 == 0)
    return;

  if (*(int *)lVar1 < 0)
    return;

  FUN_003a3e90(*(int *)lVar1,param_1);

  return;

}
#define FUN_003c73e0(...) ((void (*)(...))FUN_003c73e0)(__VA_ARGS__)
#undef FUN_003c7430
// FUN_003C7430


u32 FUN_003c7430(u64 param_1)



{

  extern u8 *FUN_003c7d50_direct(void);
  u32 uVar1;

  u8 *lVar2;

  int *piVar3;

  

  lVar2 = FUN_003c7d50_direct();

  if (lVar2 == 0) {

    uVar1 = 0;

  }

  else {

    piVar3 = (int *)lVar2;

    if (*piVar3 < 0) {

      uVar1 = 0;

    }

    else {

      FUN_003a4360(*piVar3,4);

      FUN_003a3e10(*piVar3,0x200000);

      FUN_003a30c0(*piVar3,param_1,0);

      FUN_003a27c0_typed(*piVar3,-1);

      uVar1 = 1;

      *(u8 *)(piVar3 + 1) = 1;

    }

  }

  return uVar1;

}
#define FUN_003c7430(...) ((u32 (*)(...))FUN_003c7430)(__VA_ARGS__)
#undef FUN_003c74e0
// FUN_003C74E0


u32 FUN_003c74e0(int param_1)



{

  extern u8 *FUN_003c7d50_direct(void);
  u8 uVar1;

  u32 uVar2;

  u8 *lVar3;

  int *piVar4;

  

  lVar3 = FUN_003c7d50_direct();

  if (lVar3 == 0) {

    uVar2 = 0;

  }

  else {

    piVar4 = (int *)lVar3;

    if (*piVar4 < 0) {

      uVar2 = 0;

    }

    else {

      piVar4[2] = param_1;

      uVar1 = FUN_003c75b0_typed();

      *(u8 *)((int)piVar4 + 0xd) = uVar1;

      uVar2 = 1;

    }

  }

  return uVar2;

}
#define FUN_003c74e0(...) ((u32 (*)(...))FUN_003c74e0)(__VA_ARGS__)
#undef FUN_003c7560
// FUN_003C7560


void FUN_003c7560(u8 param_1)



{
  extern u8 *FUN_003c7d50_direct(void);

  u8 *lVar1;

  

  lVar1 = FUN_003c7d50_direct();

  if (lVar1 == 0)
    return;

  if (*(int *)lVar1 < 0)
    return;

  *(u8 *)(lVar1 + 0xc) = param_1;

  return;

}
#define FUN_003c7560(...) ((void (*)(...))FUN_003c7560)(__VA_ARGS__)
#undef FUN_003c75b0
// FUN_003C75B0


u32 FUN_003c75b0(void)
{
  extern u8 *FUN_003c7d50_direct(void);
  int *piVar1;
  u32 uVar2;
  piVar1 = (int *)FUN_003c7d50_direct();

  if (piVar1 == 0) {
    uVar2 = 0xffffffffffffffff;
  } else if (0 > *piVar1) {
    uVar2 = 0xffffffffffffffff;
  } else {
    uVar2 = FUN_003a2830_nm_typed(*piVar1);
  }

  return uVar2;
}
#define FUN_003c75b0(...) ((u64 (*)(...))FUN_003c75b0)(__VA_ARGS__)
#undef FUN_003c7610
// FUN_003C7610


s8 FUN_003c7610(void)
{
  s8 uVar1;

  u8 *lVar2;
  extern u8 *FUN_003c7d50_direct(void);

  

  lVar2 = FUN_003c7d50_direct();

  if (lVar2 == 0) {

    uVar1 = 1;

  }

  else {

    uVar1 = *(s8 *)(lVar2 + 0xd);

  }

  return uVar1;

}
#define FUN_003c7610(...) ((s8 (*)(...))FUN_003c7610)(__VA_ARGS__)
#undef FUN_003c7650
// FUN_003C7650


u32 FUN_003c7650(int param_1)



{
  extern u8 *FUN_003c7d50_direct(void);

  u32 uVar1;

  u8 *lVar2;

  int *piVar3;

  

  lVar2 = FUN_003c7d50_direct();

  if (lVar2 == 0) {

    uVar1 = 0;

  }

  else {

    piVar3 = (int *)lVar2;

    if (*piVar3 < 0) {

      uVar1 = 0;

    }

    else {

      FUN_003a25f0(*piVar3,0);

      if (param_1 != 0) {

        FUN_003a2a30(*piVar3);

      }

      FUN_003a3420(*piVar3,0);

      FUN_003c7c90_typed(1);

      *(u8 *)(piVar3 + 1) = 0;

      uVar1 = 1;

    }

  }

  return uVar1;

}
#define FUN_003c7650(...) ((u32 (*)(...))FUN_003c7650)(__VA_ARGS__)
#undef FUN_003c7700
// FUN_003C7700


u32 FUN_003c7700(void)



{
  extern u8 *FUN_003c7d50_direct(void);

  u32 uVar1;

  u8 *lVar2;

  int *piVar3;

  

  lVar2 = FUN_003c7d50_direct();

  if (lVar2 == 0) {

    uVar1 = 0;

  }

  else {

    piVar3 = (int *)lVar2;

    if (*piVar3 < 0) {

      uVar1 = 0;

    }

    else {

      FUN_003a25f0(*piVar3,0);

      FUN_003a2a30(*piVar3);

      FUN_003a3420(*piVar3,0);

      FUN_003c7c90_typed(1);

      *(u8 *)(piVar3 + 1) = 0;

      uVar1 = 1;

    }

  }

  return uVar1;

}
#define FUN_003c7700(...) ((u32 (*)(...))FUN_003c7700)(__VA_ARGS__)
#undef FUN_003c77a0
// FUN_003C77A0


u32 FUN_003c77a0(void)



{

  u32 uVar1;
  extern u8 *FUN_003c7d50_direct(void);

  u8 *lVar2;

  int *piVar3;

  

  lVar2 = FUN_003c7d50_direct();

  FUN_005225a8_nm3(&gp0xffffaa08,&DAT_006a3e18[0],0x158);

  FUN_005225a8_nm1(&DAT_006a3e30[0]);

  FUN_001052b0_nm1(&DAT_006a3e30[0]);

  if (lVar2 == 0) {

    uVar1 = 0;

  }

  else {

    piVar3 = (int *)lVar2;

    if (*(int *)lVar2 >= 0) {

      FUN_003a3060_typed(*piVar3);

      *piVar3 = -1;

      *(u8 *)(piVar3 + 1) = 0;

      *(u8 *)((int)piVar3 + 5) = 0;

    }

    FUN_003cf440();

    uVar1 = 1;

  }

  return uVar1;

}
#define FUN_003c77a0(...) ((u32 (*)(...))FUN_003c77a0)(__VA_ARGS__)
#undef FUN_003c7850
// FUN_003C7850


s8 FUN_003c7850(void)
{
  extern u8 *FUN_003c7d50_ptr(void);
  s8 uVar1;
  int *piVar2;
  u8 *lVar3;

  lVar3 = FUN_003c7d50_ptr();
  if (lVar3 == 0) {
    uVar1 = 0;
  }
  else {
    piVar2 = (int *)lVar3;
    if (*piVar2 < 0) {
      uVar1 = 0;
    }
    else {
      if (*(char *)((int)piVar2 + 5) == '\0') {
        goto value;
      }
      if ((char)piVar2[1] != '\x02') {
        goto value;
      }
      uVar1 = 0;
      goto done;
value:
      uVar1 = *(s8 *)((int)piVar2 + 4);
done:
      ;
    }
  }
  return uVar1;
}
#define FUN_003c7850(...) ((u8 (*)(...))FUN_003c7850)(__VA_ARGS__)
#undef FUN_003c78d0
// FUN_003C78D0


u32 FUN_003c78d0(void)



{

  extern u8 *FUN_003c7d50_direct(void);
  u32 uVar1;

  u32 uVar2;

  u8 *lVar3;
  int lVar4;
  u8 *p;

  

  lVar3 = FUN_003c7d50_direct();

  if (lVar3 == 0) {

    uVar2 = 0;

  }

  else if (*(int *)lVar3 < 0) {

    uVar2 = 0;

  }

  else {

    lVar4 = FUN_003a2750_nm_typed(*(int *)lVar3);

    if (lVar4 < 0) {

      uVar2 = 0;

    }

    else {

      p = FUN_003c7d50_direct();

      if (p == 0) {

        uVar1 = -1;

      }

      else if (*(int *)p < 0) {

        uVar1 = -1;

      }

      else {

        uVar1 = FUN_003a2830_nm_typed(*(int *)p);

      }

      *(u8 *)((int)(int *)lVar3 + 0xd) = uVar1;

      uVar2 = 1;

    }

  }

  return uVar2;

}
#define FUN_003c78d0(...) ((u32 (*)(...))FUN_003c78d0)(__VA_ARGS__)
#undef FUN_003c7990
// FUN_003C7990 NONMATCHING


void FUN_003c7990(long param_1)



{

  char cVar1;

  u8 bVar2;

  u8 uVar3;
  extern u8 *FUN_003c7d50_direct(void);

  int *piVar4;

  int extraout_v0_hi;

  int extraout_v0_hi_00;

  u8 *lVar6;

  u8 *lVar5;

  

  lVar5 = FUN_003c7d50_direct();

  piVar4 = (int *)lVar5;

  if ((lVar5 != 0) && (-1 < *piVar4)) {

    cVar1 = (char)piVar4[1];

    if (cVar1 == '\x03') {

      lVar5 = FUN_003c7d50_direct();

      piVar4 = (int *)lVar5;

      if ((lVar5 != 0) && (-1 < *piVar4)) {

        FUN_003a25f0(*piVar4,0);

        if (param_1 != 0) {

          FUN_003a2a30(*piVar4);

        }

        FUN_003a3420(*piVar4,0);

        FUN_003c7c90_typed(1);

        *(u8 *)(piVar4 + 1) = 0;

      }

    }

    else if (cVar1 == '\x02') {

      if (-1 < piVar4[2]) {

        FUN_003a3c10(*piVar4,(char)piVar4[3]);

        FUN_003a37c0(*piVar4,piVar4[2]);

        piVar4[2] = -1;

      }

      if (*(char *)((int)piVar4 + 5) == '\0') {

        lVar5 = FUN_003c7d50_direct();

        if (lVar5 == 0) {

          bVar2 = 0;

        }

        else if (*(int *)lVar5 < 0) {

          bVar2 = 0;

        }

        else {

          FUN_003a2750();

          if (extraout_v0_hi_00 < 0) {

            bVar2 = 0;

          }

          else {

            lVar6 = FUN_003c7d50_direct();

            if (lVar6 == 0) {

              uVar3 = 0xff;

            }

            else if (*(int *)lVar6 < 0) {

              uVar3 = 0xff;

            }

            else {

              uVar3 = FUN_003a2830();

            }

            *(u8 *)((int)(int *)lVar5 + 0xd) = uVar3;

            bVar2 = 1;

          }

        }

        if (!bVar2) {

          *(u8 *)(piVar4 + 1) = 3;

        }

      }

    }

    else if ((cVar1 == '\x01') && (FUN_003a2580(), extraout_v0_hi < 0)) {

      *(u8 *)(piVar4 + 1) = 2;

    }

  }

  return;

}
#define FUN_003c7990(...) ((void (*)(...))FUN_003c7990)(__VA_ARGS__)
#undef FUN_003c7b90
// FUN_003C7B90


void FUN_003c7b90(void)



{

  FUN_003c7990_typed(1);

  return;

}
#define FUN_003c7b90(...) ((void (*)(...))FUN_003c7b90)(__VA_ARGS__)
#undef FUN_003c7bc0
// FUN_003C7BC0


void FUN_003c7bc0(u64 param_1,u64 param_2)



{
  extern u8 *FUN_003c7d50_direct(void);

  u8 *lVar1;

  

  lVar1 = FUN_003c7d50_direct();

  if (lVar1 != 0) {

    FUN_003a4220(*(u32 *)lVar1,param_1,param_2);

  }

  return;

}
#define FUN_003c7bc0(...) ((void (*)(...))FUN_003c7bc0)(__VA_ARGS__)
#undef FUN_003c7c20
// FUN_003C7C20


void FUN_003c7c20(u64 param_1,u64 param_2,u64 param_3)



{
  extern u8 *FUN_003c7d50_direct(void);

  u8 *lVar1;

  

  lVar1 = FUN_003c7d50_direct();

  if (lVar1 != 0) {

    FUN_003a4010(*(u32 *)lVar1,param_1,param_2,param_3);

  }

  return;

}
#define FUN_003c7c20(...) ((void (*)(...))FUN_003c7c20)(__VA_ARGS__)
#undef FUN_003c7c90
// FUN_003C7C90


void FUN_003c7c90(int param_1)



{

  u32 lVar1;

  u32 *puVar2;

  

  lVar1 = FUN_003c7d50_direct();

  if (lVar1 != 0) {

    puVar2 = (u32 *)lVar1;

    if (param_1 != 0) {

      FUN_003a3e90(*puVar2,0x800000);

      FUN_003a3e10(*puVar2,0x100000);

      *(u8 *)((int)puVar2 + 5) = 0;

      FUN_003a25f0(*puVar2,1);

      *(u8 *)(puVar2 + 1) = 1;

    }

    else {

      FUN_003a3e10(*puVar2,0x800000);

      FUN_003a3e10(*puVar2,0x100000);

      *(u8 *)((int)puVar2 + 5) = 1;

    }

  }

  return;

}
#define FUN_003c7c90(...) ((void (*)(...))FUN_003c7c90)(__VA_ARGS__)
#undef FUN_003c7d50
// FUN_003C7D50


u32 FUN_003c7d50(void)
{
  return (u32)DAT_0095be90_ptr;
}
#define FUN_003c7d50(...) ((u32 (*)(...))FUN_003c7d50)(__VA_ARGS__)
#undef FUN_003c7d60
// FUN_003C7D60


u32 FUN_003c7d60(int param_1)



{

  return DAT_006a3e50_abs[param_1];

}
#define FUN_003c7d60(...) ((u32 (*)(...))FUN_003c7d60)(__VA_ARGS__)
#undef FUN_003c7d80
// FUN_003C7D80


void FUN_003c7d80(int param_1,u64 param_2)



{

  u32 uVar1;

  

  uVar1 = FUN_003a2d80(param_2);

  DAT_006a3e50_abs[param_1] = uVar1;

  return;

}
#define FUN_003c7d80(...) ((void (*)(...))FUN_003c7d80)(__VA_ARGS__)
#undef FUN_003c7dd0
// FUN_003C7DD0


void FUN_003c7dd0(int param_1)
{
  s32 value;

  value = DAT_006a3e50_abs[param_1];
  if (value >= 0) {
    FUN_003a3060_typed(value);
    DAT_006a3e50_abs[param_1] = -1;
  }
}
#define FUN_003c7dd0(...) ((void (*)(...))FUN_003c7dd0)(__VA_ARGS__)
#undef FUN_003c7e20
#undef FUN_003c7e50
extern u64 FUN_003c7e50();
// FUN_003C7E20


void FUN_003c7e20(u32 p1,u64 p2,u64 p3,u64 p4,u64 p5,u64 p6,u64 p7)
{
  FUN_003c7e50(p1,p2,p3,p4,p5,1,p6,p7);
}
#define FUN_003c7e50(...) ((u64 (*)(...))FUN_003c7e50)(__VA_ARGS__)
#define FUN_003c7e20(...) ((void (*)(...))FUN_003c7e20)(__VA_ARGS__)
#undef FUN_003c7e50
// FUN_003C7E50 NONMATCHING


u64

FUN_003c7e50(u32 param_1,u64 param_2,u64 param_3,u64 param_4,

            u64 param_5,u64 param_6,u64 param_7,long param_8,u32 param_9)



{

  int iVar1;

  int iVar2;

  u32 uVar3;

  short sVar4;

  u16 uVar5;

  u16 uVar6;

  u16 uVar7;

  u32 uVar8;

  u32 uVar9;

  u32 uVar10;

  int iVar11;

  int *piVar12;

  int *piVar13;

  int aiStack_50 [12];

  int aiStack_20 [8];

  

  piVar13 = DAT_006a3e90;

  piVar12 = aiStack_20;

  iVar11 = 3;

  do {

    iVar1 = *piVar13;

    iVar2 = piVar13[1];

    piVar13 = piVar13 + 2;

    iVar11 = iVar11 + -1;

    *piVar12 = iVar1;

    piVar12[1] = iVar2;

    piVar12 = piVar12 + 2;

  } while (0 < iVar11);

  piVar13 = DAT_006a3eb0;

  piVar12 = aiStack_50;

  iVar11 = 9;

  do {

    iVar1 = *piVar13;

    piVar13 = piVar13 + 1;

    iVar11 = iVar11 + -1;

    *piVar12 = iVar1;

    piVar12 = piVar12 + 1;

  } while (0 < iVar11);

  if (param_8 != 2) {

    uVar7 = (u16)param_9;

    if (param_8 != 1) {

      if (param_8 == 0) {

        if ((long)param_9 < 5000) {

          iVar11 = FUN_00171250(uVar7);

        }

        else {

          iVar11 = 5;

        }

        iVar11 = aiStack_20[iVar11];

        sVar4 = FUN_00171060(uVar7);

        param_9 = (u32)sVar4;

      }

      else {

        iVar11 = aiStack_50[(int)param_8];

      }

      uVar3 = DAT_006a3e50_abs[iVar11];

      uVar10 = FUN_003a51a0(uVar3);

      if (param_9 <= uVar10) {

        FUN_003a5570(param_1,param_2,param_3,param_4,param_5,param_6,param_7,uVar3,param_9);

      }

    }

    else {

      iVar11 = FUN_00171250(uVar7);

      uVar3 = DAT_006a3e50_abs[aiStack_20[iVar11]];

      uVar5 = FUN_00171060(uVar7);

      uVar6 = FUN_003a51a0(uVar3);

      if ((uVar5 <= uVar6) &&

         (uVar8 = FUN_003a51a0(DAT_006a3e60), (u32)((int)param_9 >> 0x10) <= uVar8)) {

        FUN_003a56f0(param_1,param_2,param_3,param_4,param_5,param_6,1,uVar3,uVar5);

      }

    }

  }

  else {

    uVar7 = FUN_0016f630(1,param_9);

    iVar11 = FUN_00171250(uVar7);

    uVar3 = DAT_006a3e50_abs[aiStack_20[iVar11]];

    uVar5 = FUN_00171060(uVar7);

    uVar6 = FUN_003a51a0(uVar3);

    if (uVar5 <= uVar6) {

      uVar10 = FUN_003a51a0(DAT_006a3e60);

      uVar9 = FUN_0016f900(1,param_9);

      if ((uVar9 & 0xff) <= uVar10) {

        FUN_0016f900(1,param_9);

        FUN_003a56f0(param_1,param_2,param_3,param_4,param_5,param_6,1,uVar3,uVar5);

      }

    }

  }

  return 0;

}
#define FUN_003c7e50(...) ((u64 (*)(...))FUN_003c7e50)(__VA_ARGS__)
#undef FUN_003c8230
// FUN_003C8230


u64 FUN_003c8230(s32 *param_1,int param_2)
{
  switch (param_2) {
  case 0:
    FUN_003a4360_typed(*param_1,4);
    break;
  case 1:
    FUN_003a4360_typed(*param_1,5);
    break;
  case 2:
    FUN_003a4360_typed(*param_1,6);
    break;
  case 3:
    FUN_003a4360_typed(*param_1,7);
    break;
  }
  return 0;
}
#define FUN_003c8230(...) ((u64 (*)(...))FUN_003c8230)(__VA_ARGS__)
#undef FUN_003c82e0
// FUN_003C82E0






u64 FUN_003c82e0(int param_1)
{
  u8* p;
  p = DAT_0095be90_abs;
  if (p == (u8*)0) {
    return 0;
  }
  switch (param_1) {
  case 0:
    FUN_003a4360_typed(*(s32 *)p,4);
    break;
  case 1:
    FUN_003a4360_typed(*(s32 *)p,5);
    break;
  case 2:
    FUN_003a4360_typed(*(s32 *)p,6);
    break;
  case 3:
    FUN_003a4360_typed(*(s32 *)p,7);
    break;
  }
  return 0;
}
#define FUN_003c82e0(...) ((u64 (*)(...))FUN_003c82e0)(__VA_ARGS__)
#undef FUN_003c83b0
// FUN_003C83B0
extern u8 DAT_0095be90_abs[];

u8 FUN_003c83b0(void)
{
  u32 uVar1;
  u8* p;
  p = DAT_0095be90_abs;
  if (p != (u8*)0) goto nonzero;
  return 0;
nonzero:
  uVar1 = FUN_003a3da0(*(u32*)p);
  return (uVar1 & 0x3300) != 0;
}
#define FUN_003c83b0(...) ((u8 (*)(...))FUN_003c83b0)(__VA_ARGS__)
