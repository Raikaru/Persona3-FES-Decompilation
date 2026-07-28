#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern u32 DAT_006a11d0;
extern char D_006A1200[];
extern char DAT_006a12b0[];
extern char DAT_006a12d0[];
extern char DAT_006a1380[];
extern char DAT_006a13a0[];
extern char DAT_006a1500[];
extern char DAT_006a1520[];
extern char DAT_006a15e0[];
extern char DAT_006a1600[];
extern char DAT_006a15a0[];
extern char DAT_006a15c0[];
#pragma alias FUN_0016df30_u64 FUN_0016df30
extern u64 FUN_0016df30_u64(short);
extern char DAT_006a1400[];
extern char DAT_006a1420[];
extern char DAT_006a1620[];
extern char DAT_006a1640[];
extern u32 DAT_006a11d4;
extern u32 DAT_007cd488;
extern u32 DAT_007ce420;
extern u32 DAT_007ce618;
extern u32 DAT_007e0952;
extern code DAT_00960178;
extern code DAT_0096017c;
extern u32 LAB_00398d80;
extern u32 LAB_00399518;
extern u8 * PTR_s_;
extern u8 * PTR_s_Academics_006a1320[];
extern u32 iGpffffb730;
extern u8 *PTR_s_It_seems_further_power_lies_hi_007cd6f4;
extern u8 *PTR_s_No_further_power_is_available__007cd6f0;
 
#pragma alias DAT_00960178_abs DAT_00960178
extern code DAT_00960178_abs[];
#pragma alias DAT_0096017c_abs DAT_0096017c
extern code DAT_0096017c_abs[];
#pragma alias FUN_003c77a0_b830 FUN_003c77a0
extern void FUN_003c77a0_b830(void);
#pragma alias FUN_00100ec0_b830 FUN_00100ec0
extern void FUN_00100ec0_b830(void);
#pragma alias FUN_0039ee80_b830 FUN_0039ee80
extern void FUN_0039ee80_b830(void *);
#pragma alias FUN_00521408_b8b0 FUN_00521408
extern void FUN_00521408_b8b0(void *,int,int);
#pragma alias FUN_00194b20_b8b0 FUN_00194b20
extern void FUN_00194b20_b8b0(u64,const char *,u32,u64 (*)(int),void *,void *);
extern char DAT_006a1430[];
#pragma alias FUN_00100ec0_b830_arg FUN_00100ec0
extern void FUN_00100ec0_b830_arg(void *);
#pragma alias FUN_0039a8a0_b8b0 FUN_0039a8a0
extern u64 FUN_0039a8a0_b8b0(int);
#pragma alias FUN_0039b830_b8b0 FUN_0039b830
extern void FUN_0039b830_b8b0(int);
#pragma alias FUN_0039ea20_e820 FUN_0039ea20
extern void FUN_0039ea20_e820(u64,u32);
#pragma alias FUN_003196f0_ea20 FUN_003196f0
extern void FUN_003196f0_ea20(int,u32);
#pragma alias FUN_005225a8_eaa0 FUN_005225a8
extern void FUN_005225a8_eaa0(const char *,...);
#pragma alias FUN_00388000_d1c0 FUN_00388000
extern void FUN_00388000_d1c0(f64, u32, void *, void *, void *, void *, u32, void *, long);
#pragma alias FUN_003b91c0_a5c0 FUN_003b91c0
extern u64 FUN_003b91c0_a5c0(float,u16,u32,u32,u32,u32,u32);

extern char DAT_006a1820[];
#pragma alias FUN_003b5d10_eb90 FUN_003b5d10
extern u32 FUN_003b5d10_eb90(u32);
#pragma alias FUN_003b7090_eb90 FUN_003b7090
extern void FUN_003b7090_eb90(u32);
#pragma alias FUN_0016dd40_d010 FUN_0016dd40
extern s16 FUN_0016dd40_d010(void);
#pragma alias FUN_0016dce0_d010 FUN_0016dce0
extern u32 FUN_0016dce0_d010(s16);
#pragma alias FUN_003a2090_d010 FUN_003a2090
extern u32 FUN_003a2090_d010(u32,int,s8,u16);
#pragma alias kwlnTaskExists_d010 kwlnTaskExists
extern u32 kwlnTaskExists_d010(u32);

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
int FUN_003983e0(int param_1,int param_2);
u32 FUN_00398530(int param_1);
void FUN_00399830(int param_1);
u32 FUN_003998b0(int param_1);
void FUN_00399be0(int param_1);
u32 FUN_00399c40(int param_1);
void FUN_0039a560(int param_1);
u32 FUN_0039a5c0(int param_1);
void FUN_0039a840(int param_1);
u32 FUN_0039a8a0(int param_1);
void FUN_0039b830(int param_1);
void FUN_0039b8b0(u64 param_1,u16 param_2);
u32 FUN_0039b950(u64 param_1);
void FUN_0039c090(int param_1);
u32 FUN_0039c0f0(int param_1);
void FUN_0039c3e0(int param_1);
u32 FUN_0039c440(int param_1);
void FUN_0039cd60(int param_1);
u32 FUN_0039cdc0(int param_1);
void FUN_0039cfb0(int param_1);
u32 FUN_0039d010(int param_1);
void FUN_0039d190(int param_1);
void FUN_0039d1c0(int param_1);
u32 FUN_0039d550(int param_1);
void FUN_0039d880(int param_1);
u32 FUN_0039d8e0(int param_1);
void FUN_0039db00(int param_1);
u32 FUN_0039db60(int param_1);
void FUN_0039dd30(int param_1);
u32 FUN_0039dd90(int param_1);
void FUN_0039e130(int param_1);
u32 FUN_0039e1b0(int param_1,int param_2);
u32 FUN_0039e6f0(void);
void FUN_0039e700(u8 *param_1);
void FUN_0039e7c0(void);
void FUN_0039e820(u64 param_1);
u32 FUN_0039e880(int param_1,int param_2,int param_3,int param_4,int param_5);
void FUN_0039ea20(int param_1,int param_2);
void FUN_0039eaa0(int param_1);
void FUN_0039eb90(void);
u32 FUN_0039ec10(int param_1,int param_2,u32 *param_3,u32 *param_4);
int FUN_0039ec60(int param_1);


/* Region call-cast macros */
#define FUN_003983e0(...) ((int (*)(...))FUN_003983e0)(__VA_ARGS__)
#define FUN_00398530(...) ((u32 (*)(...))FUN_00398530)(__VA_ARGS__)
#define FUN_00399830(...) ((void (*)(...))FUN_00399830)(__VA_ARGS__)
#define FUN_003998b0(...) ((u32 (*)(...))FUN_003998b0)(__VA_ARGS__)
#define FUN_00399be0(...) ((void (*)(...))FUN_00399be0)(__VA_ARGS__)
#define FUN_00399c40(...) ((u32 (*)(...))FUN_00399c40)(__VA_ARGS__)
#define FUN_0039a560(...) ((void (*)(...))FUN_0039a560)(__VA_ARGS__)
#define FUN_0039a5c0(...) ((u32 (*)(...))FUN_0039a5c0)(__VA_ARGS__)
#define FUN_0039a840(...) ((void (*)(...))FUN_0039a840)(__VA_ARGS__)
#define FUN_0039a8a0(...) ((u32 (*)(...))FUN_0039a8a0)(__VA_ARGS__)
#define FUN_0039b830(...) ((void (*)(...))FUN_0039b830)(__VA_ARGS__)
#define FUN_0039b8b0(...) ((void (*)(...))FUN_0039b8b0)(__VA_ARGS__)
#define FUN_0039b950(...) ((u32 (*)(...))FUN_0039b950)(__VA_ARGS__)
#define FUN_0039c090(...) ((void (*)(...))FUN_0039c090)(__VA_ARGS__)
#define FUN_0039c0f0(...) ((u32 (*)(...))FUN_0039c0f0)(__VA_ARGS__)
#define FUN_0039c3e0(...) ((void (*)(...))FUN_0039c3e0)(__VA_ARGS__)
#define FUN_0039c440(...) ((u32 (*)(...))FUN_0039c440)(__VA_ARGS__)
#define FUN_0039cd60(...) ((void (*)(...))FUN_0039cd60)(__VA_ARGS__)
#define FUN_0039cdc0(...) ((u32 (*)(...))FUN_0039cdc0)(__VA_ARGS__)
#define FUN_0039cfb0(...) ((void (*)(...))FUN_0039cfb0)(__VA_ARGS__)
#define FUN_0039d010(...) ((u32 (*)(...))FUN_0039d010)(__VA_ARGS__)
#define FUN_0039d190(...) ((void (*)(...))FUN_0039d190)(__VA_ARGS__)
#define FUN_0039d1c0(...) ((void (*)(...))FUN_0039d1c0)(__VA_ARGS__)
#define FUN_0039d550(...) ((u32 (*)(...))FUN_0039d550)(__VA_ARGS__)
#define FUN_0039d880(...) ((void (*)(...))FUN_0039d880)(__VA_ARGS__)
#define FUN_0039d8e0(...) ((u32 (*)(...))FUN_0039d8e0)(__VA_ARGS__)
#define FUN_0039db00(...) ((void (*)(...))FUN_0039db00)(__VA_ARGS__)
#define FUN_0039db60(...) ((u32 (*)(...))FUN_0039db60)(__VA_ARGS__)
#define FUN_0039dd30(...) ((void (*)(...))FUN_0039dd30)(__VA_ARGS__)
#define FUN_0039dd90(...) ((u32 (*)(...))FUN_0039dd90)(__VA_ARGS__)
#define FUN_0039e130(...) ((void (*)(...))FUN_0039e130)(__VA_ARGS__)
#define FUN_0039e1b0(...) ((u32 (*)(...))FUN_0039e1b0)(__VA_ARGS__)
#define FUN_0039e6f0(...) ((u32 (*)(...))FUN_0039e6f0)(__VA_ARGS__)
#define FUN_0039e700(...) ((void (*)(...))FUN_0039e700)(__VA_ARGS__)
#define FUN_0039e7c0(...) ((void (*)(...))FUN_0039e7c0)(__VA_ARGS__)
#define FUN_0039e820(...) ((void (*)(...))FUN_0039e820)(__VA_ARGS__)
#define FUN_0039e880(...) ((u32 (*)(...))FUN_0039e880)(__VA_ARGS__)
#define FUN_0039ea20(...) ((void (*)(...))FUN_0039ea20)(__VA_ARGS__)
#define FUN_0039eaa0(...) ((void (*)(...))FUN_0039eaa0)(__VA_ARGS__)
#define FUN_0039eb90(...) ((void (*)(...))FUN_0039eb90)(__VA_ARGS__)
#define FUN_0039ec10(...) ((u32 (*)(...))FUN_0039ec10)(__VA_ARGS__)
#define FUN_0039ec60(...) ((int (*)(...))FUN_0039ec60)(__VA_ARGS__)

#undef FUN_003983e0
// FUN_003983E0


int FUN_003983e0(int param_1,int param_2)
{
  int iVar1;
  int iVar2;

  iVar1 = 0;
  iVar2 = 0;
  if (FUN_00172160(param_2) == 1) {
    iVar1 = 2;
  }
  else {
    if (FUN_001717c0(param_2) == 1) {
      iVar1 = 1;
    }
  }
  switch (param_1) {
  case 0:
    iVar2 = iVar1 + param_2 * 0xc;
    break;
  case 1:
    iVar2 = iVar1 + ((param_2 * 0xc) + 3);
    break;
  case 2:
    iVar2 = iVar1 + ((param_2 * 0xc) + 6);
    break;
  case 3:
    iVar2 = iVar1 + ((param_2 * 0xc) + 9);
    break;
  }
  if ((iVar2 + 5 >= 0x16d) || (iVar2 + 5 < 0)) {
    FUN_0019d3f0(D_006A1200,0x110);
  }
  return iVar2 + 5;
}
#define FUN_003983e0(...) ((int (*)(...))FUN_003983e0)(__VA_ARGS__)
#undef FUN_00398530
// FUN_00398530 NONMATCHING


u32 FUN_00398530(int param_1)



{
  extern float FUN_0038d840(u32 param_1,char *param_2,int param_3);
  extern void FUN_0019d3f0(const char *param_1,int param_2,...);
  u8 bVar1;

  u16 uVar2;

  int *puVar15;

  char cVar4;

  u16 uVar5;

  short sVar6;

  int iVar7;

  u32 uVar8;

  u32 uVar9;

  int lVar10;

  int iVar11;

  int iVar12;

  int iVar13;

  int iVar14;

  int *puVar3;

  u32 uVar16;

  u64 unaff_s1;

  u32 uVar17;

  char acStack_140 [316];

  u8 auStack_4 [4];

  

  puVar3 = (int *)(*(u32 **)(param_1 + 0x3c));
  puVar15 = puVar3 + 0x16;

  switch(*puVar3) {

  case 0:

    if ((*(u32 *)(puVar3[0x12] + 4) & 8) == 0) {

      FUN_00172890();

      FUN_0016dfb0(0xb);

      FUN_0016dfb0(8);

      cVar4 = FUN_0016dba0(0xb);

      FUN_001723a0(0xb,cVar4 + 1,1);

      FUN_001723a0(8,cVar4 + 1,1);

      uVar9 = FUN_00172e40();

      iVar12 = FUN_00172e40();

      FUN_003c2630(1,uVar9,*(u32 *)(iVar12 + 0x18));

    }

    for (iVar12 = 0; iVar12 < 0x1e; iVar12 = iVar12 + 1) {

      FUN_003951a0(iVar12 + 0x9b0);

    }

    uVar8 = FUN_003c2770();

    puVar3[0x14] = uVar8;

    *(u16 *)(puVar3 + 2) = *(u16 *)(puVar3[0x13] + 0x14);

    puVar3[0x20] = 0;

    puVar3[1] = 0;

    *puVar3 = 1;

    break;

  case 1:

    uVar8 = FUN_00100d80(0x6a1220,1);

    puVar3[0x15] = uVar8;

    *puVar3 = 2;

    break;

  case 2:

    lVar10 = FUN_001016b0(puVar3[0x15]);

    if (lVar10 == 1) {

      *puVar3 = 3;

      uVar9 = FUN_001021c0(0x6a1240,auStack_4);

      puVar3[0x1e] = (int)uVar9;

      FUN_0039ec70(puVar15,uVar9);

    }

    break;

  case 3:

    iVar12 = puVar3[1];

    if ((iVar12 < *(int *)puVar3[0x14]) && (puVar3[0x20] != 1)) {

      *(char *)(puVar3 + 4) = (char)((int *)puVar3[0x14])[iVar12 * 0xe + 1];

      lVar10 = FUN_0016dce0(*(u8 *)(puVar3 + 4));

      if (lVar10 == 0) {

        FUN_0019d3f0("mt_evtCustomEvent.c",399);

      }

      FUN_00395170(*(u8 *)(puVar3 + 4) + 0x9b0);

      if ((*(u32 *)(puVar3[0x12] + 4) & 8) != 0) {

        FUN_00395170(*(u8 *)(puVar3 + 4) + 0x990);

      }

      uVar8 = FUN_003c2780(*(u8 *)(puVar3 + 4));

      puVar3[0x21] = uVar8;

      iVar13 = iVar12 * 0x38;

      puVar3[5] = *(u32 *)(iVar13 + puVar3[0x14] + 8);

      *(u8 *)((int)puVar3 + 0x12) = *(u8 *)(iVar13 + puVar3[0x14] + 6);

      for (iVar14 = 0; iVar14 < (int)puVar3[5]; iVar14 = iVar14 + 1) {

        iVar11 = iVar14 * 6;

        iVar7 = iVar13 + puVar3[0x14] + iVar11;

        uVar5 = *(u16 *)(iVar7 + 0x24);

        uVar2 = *(u16 *)(iVar7 + 0x26);

        *(u16 *)((int)puVar3 + iVar11 + 0x2e) = *(u16 *)(iVar7 + 0x22);

        *(u16 *)((int)puVar3 + iVar11 + 0x30) = uVar5;

        *(u16 *)((int)puVar3 + iVar11 + 0x32) = uVar2;

      }

      bVar1 = *(u8 *)(iVar12 * 0x38 + puVar3[0x14] + 0x22);

      if (bVar1 < 0x2a) {

        uVar9 = FUN_003c3f40(bVar1);

        FUN_0039ef30(puVar15,0,uVar9);

      }

      puVar3[3] = 0;

      *puVar3 = 4;

    }

    else {

      *puVar3 = 0x28;

    }

    break;

  case 4:

    lVar10 = FUN_003c40f0(*(u8 *)(puVar3 + 4));

    if (lVar10 == 2) {

      uVar5 = FUN_003c4110(*(u8 *)(puVar3 + 4));

      uVar8 = FUN_00316e00(5,uVar5,0);

      puVar3[0x26] = uVar8;

      *puVar3 = 5;

    }

    else if (lVar10 == 1) {

      *puVar3 = 0x16;

    }

    else if (lVar10 == 0) {

      FUN_0019d3f0("mt_evtCustomEvent.c",0x1b4);

    }

    break;

  case 5:

    lVar10 = FUN_00316f70(puVar3[0x26]);

    if (lVar10 == 1) {

      uVar5 = FUN_003b6270(0x389,3,puVar3[0x26]);

      *(u16 *)(puVar3 + 0x25) = uVar5;

      FUN_0038d840(*(u32 *)(puVar3[0x13] + 0x40),acStack_140,0);

      uVar8 = FUN_0038a900(5);

      lVar10 = FUN_003bc8f0(acStack_140);

      iVar12 = (int)lVar10;

      if (lVar10 < 0) {

        iVar12 = iVar12 + 1;

      }

      uVar17 = FUN_003bc730(acStack_140,(iVar12 >> 1) + 1);

      puVar3[0x24] = uVar17;

      uVar9 = FUN_00530da0(uVar17);

      FUN_005225a8(0x6a1260,uVar9);

      if (acStack_140[0] >= '\x01') {

        FUN_003bb1d0(*(u16 *)(puVar3 + 0x25),1,1,0xd,6);

        FUN_003b89f0(uVar8,*(u16 *)(puVar3 + 0x25),acStack_140,0);

        FUN_003b91c0(0x3f800000,*(u16 *)(puVar3 + 0x25),0,1,0,1,0);

      }

      else {

        FUN_0019d3f0("mt_evtCustomEvent.c",0x1df);

      }

      FUN_003b9550(*(u16 *)(puVar3 + 0x25),1);

      *puVar3 = 6;

    }

    break;

  case 6:

    iVar12 = FUN_003b5d10(*(u16 *)(puVar3 + 0x25));

    if ((float)puVar3[0x24] <= *(float *)(iVar12 + 0x5c)) {

      FUN_005225a8(0x6a1278);

      FUN_003b8310(*(u16 *)(puVar3 + 0x25),1);

      *puVar3 = 7;

      FUN_003b91c0(0x3f800000,*(u16 *)(puVar3 + 0x25),0,0,5,1,0);

    }

    break;

  case 7:

    FUN_0039f210(puVar15,*(u16 *)(puVar3[0x21] + 4),*(u16 *)(puVar3[0x21] + 6),

                 0xffffffffffffffff);

    *puVar3 = 8;

    break;

  case 8:

    lVar10 = FUN_0039f6e0(puVar15);

    if (lVar10 == 1) {

      uVar8 = FUN_0039f800(puVar15);

      puVar3[0x1f] = uVar8;

      *puVar3 = 9;

    }

    break;

  case 9:

    if (puVar3[0x1f] != 0) {

      FUN_0039f210(puVar15,*(u16 *)(puVar3[0x21] + 10),0xffffffffffffffff,0xffffffffffffffff)

      ;

    }

    else {

      FUN_0039f210(puVar15,*(u16 *)(puVar3[0x21] + 8),0xffffffffffffffff,0xffffffffffffffff);

    }

    *puVar3 = 10;

    break;

  case 10:

    lVar10 = FUN_0039f6e0(puVar15);

    if (lVar10 == 1) {

      *puVar3 = 0x13;

    }

    break;

  case 0xb:

    uVar9 = FUN_003983e0(0,*(u8 *)(puVar3 + 4));

    FUN_0039f210(puVar15,uVar9,0xffffffffffffffff,0xffffffffffffffff);

    FUN_003b91c0(0x3f800000,*(u16 *)(puVar3 + 0x25),0,3,0,0,0);

    FUN_003b9320(0x3f800000,*(u16 *)(puVar3 + 0x25),0,0,0,1,0);

    *puVar3 = 0xc;

    break;

  case 0xc:

    lVar10 = FUN_0039f6e0(puVar15);

    if (lVar10 == 1) {

      *puVar3 = 0xd;

    }

    break;

  case 0xd:

    FUN_0039f210(puVar15,0,1,0xffffffffffffffff);

    sVar6 = FUN_0016c920(1);

    if ((sVar6 != 5) && (sVar6 != 4)) {

      FUN_0039f7c0(puVar15);

    }

    *puVar3 = 0xe;

    break;

  case 0xe:

    lVar10 = FUN_0039f6e0(puVar15);

    if (lVar10 == 1) {

      uVar16 = (u32)*(u8 *)(puVar3 + 4);

      lVar10 = FUN_00172160(uVar16);

      if (lVar10 != 1) {

        lVar10 = FUN_001717c0(uVar16);

        if (lVar10 != 1) {

          for (iVar12 = 0; iVar12 < 5; iVar12 = iVar12 + 1) {

            if (uVar16 == *(u32 *)(&DAT_006a11d0 + iVar12 * 8)) {

              uVar8 = *(u32 *)(&DAT_006a11d4 + iVar12 * 8);

              goto LAB_00398d80;

            }

          }

          uVar8 = 10;

        }

        else {

          uVar8 = 0;

        }

      }

      else {

        uVar8 = 0;

      }

LAB_00398d80:

      lVar10 = FUN_0039f800(puVar15);

      puVar3[0x1f] = (int)lVar10;

      if ((lVar10 == 1) && (lVar10 = FUN_00395230(uVar8), lVar10 == 1)) {

        puVar3[3] = 1;

      }

      *puVar3 = 0xf;

    }

    break;

  case 0xf:

    iVar12 = puVar3[0x1f];

    if (iVar12 == 2) {

      unaff_s1 = FUN_003983e0(3,*(u8 *)(puVar3 + 4));

      FUN_003b91c0(0x3f800000,*(u16 *)(puVar3 + 2),0,5,0,0,0);

      FUN_003b9320(0x3f800000,*(u16 *)(puVar3 + 2),0,0,0,1,0);

      FUN_003b91c0(0x3f800000,*(u16 *)(puVar3 + 0x25),0,6,0,0,0);

      FUN_003b9320(0x3f800000,*(u16 *)(puVar3 + 0x25),0,0,0,1,0);

    }

    else if (iVar12 == 1) {

      unaff_s1 = FUN_003983e0(2,*(u8 *)(puVar3 + 4));

      FUN_003b91c0(0x3f800000,*(u16 *)(puVar3 + 2),0,5,0,0,0);

      FUN_003b9320(0x3f800000,*(u16 *)(puVar3 + 2),0,0,0,1,0);

      FUN_003b91c0(0x3f800000,*(u16 *)(puVar3 + 0x25),0,6,0,0,0);

      FUN_003b9320(0x3f800000,*(u16 *)(puVar3 + 0x25),0,0,0,1,0);

    }

    else if (iVar12 == 0) {

      puVar3[0x20] = 1;

      unaff_s1 = FUN_003983e0(1,*(u8 *)(puVar3 + 4));

      FUN_003b91c0(0x3f800000,*(u16 *)(puVar3 + 2),0,7,0,0,0);

      FUN_003b9320(0x3f800000,*(u16 *)(puVar3 + 2),0,0,0,1,0);

      FUN_003b91c0(0x3f800000,*(u16 *)(puVar3 + 0x25),0,7,0,0,0);

      FUN_003b9320(0x3f800000,*(u16 *)(puVar3 + 0x25),0,0,0,1,0);

    }

    FUN_0039f210(puVar15,unaff_s1,0xffffffffffffffff,0xffffffffffffffff);

    *puVar3 = 0x10;

    break;

  case 0x10:

    lVar10 = FUN_0039f6e0(puVar15);

    if (lVar10 == 1) {

      if (puVar3[3] != 1) {

        *puVar3 = 0x13;

      }

      else {

        *puVar3 = 0x11;

      }

    }

    break;

  case 0x11:

    FUN_0039f210(puVar15,3,0xffffffffffffffff,0xffffffffffffffff);

    *puVar3 = 0x12;

    break;

  case 0x12:

    lVar10 = FUN_0039f6e0(puVar15);

    if (lVar10 == 1) {

      *puVar3 = 0x13;

    }

    break;

  case 0x13:

    FUN_003b8310(*(u16 *)(puVar3 + 0x25),0);

    FUN_003b91c0(0x3f800000,*(u16 *)(puVar3 + 0x25),0,1,0,1,0);

    *puVar3 = 0x14;

    break;

  case 0x14:

    lVar10 = FUN_003b95a0(*(u16 *)(puVar3 + 0x25));

    if (lVar10 == 0) {

      *puVar3 = 0x15;

    }

    break;

  case 0x15:

    *puVar3 = 3;

    FUN_003b7090(*(u16 *)(puVar3 + 0x25));

    *(u16 *)(puVar3 + 0x25) = 0;

    puVar3[1] = puVar3[1] + 1;

    break;

  case 0x16:

    FUN_003bb010(*(u16 *)(puVar3 + 2),0x11);

    FUN_003952d0(0,0x65,3);

    *puVar3 = 0x17;

    puVar3[0x22] = 0;

    puVar3[0x23] = 0x3c;

    break;

  case 0x17:

    if ((int)puVar3[0x22] >= (int)puVar3[0x23]) {

      *puVar3 = 0x18;

    }

    else {

      puVar3[0x22] = puVar3[0x22] + 1;

    }

    break;

  case 0x18:

    FUN_0039f210(puVar15,*(u16 *)(puVar3[0x21] + 4),*(u16 *)(puVar3[0x21] + 6),

                 0xffffffffffffffff);

    *puVar3 = 0x19;

    break;

  case 0x19:

    lVar10 = FUN_0039f6e0(puVar15);

    if (lVar10 == 1) {

      uVar8 = FUN_0039f800(puVar15);

      puVar3[0x1f] = uVar8;

      *puVar3 = 0x1a;

    }

    break;

  case 0x1a:

    if (puVar3[0x1f] != 0) {

      FUN_0039f210(puVar15,*(u16 *)(puVar3[0x21] + 10),0xffffffffffffffff,0xffffffffffffffff)

      ;

    }

    else {

      FUN_0039f210(puVar15,*(u16 *)(puVar3[0x21] + 8),0xffffffffffffffff,0xffffffffffffffff);

    }

    *puVar3 = 10;

    break;

  case 0x1b:

    *puVar3 = 0x1c;

    break;

  case 0x1c:

    *puVar3 = 0x1d;

    FUN_003b91c0(0x3f800000,*(u16 *)(puVar3 + 2),0,0xe,0,0,0);

    FUN_003b9320(0x3f800000,*(u16 *)(puVar3 + 2),0,0xd,0,1,0);

    FUN_003bb010(*(u16 *)(puVar3 + 2),0x11);

    FUN_003952d0(0,0x65,3);

    break;

  case 0x1d:

    FUN_0039f210(puVar15,2,0xffffffffffffffff,0xffffffffffffffff);

    *puVar3 = 0x1e;

    break;

  case 0x1e:

    lVar10 = FUN_0039f6e0(puVar15);

    if (lVar10 == 1) {

      *puVar3 = 0x1f;

    }

    break;

  case 0x1f:

    uVar9 = FUN_003983e0(0,*(u8 *)(puVar3 + 4));

    FUN_0039f210(puVar15,uVar9,0xffffffffffffffff,0xffffffffffffffff);

    *puVar3 = 0x20;

    break;

  case 0x20:

    lVar10 = FUN_0039f6e0(puVar15);

    if (lVar10 == 1) {

      *puVar3 = 0x21;

    }

    break;

  case 0x21:

    FUN_0039f210(puVar15,0,1,0xffffffffffffffff);

    sVar6 = FUN_0016c920(1);

    if ((sVar6 != 5) && (sVar6 != 4)) {

      FUN_0039f7c0(puVar15);

    }

    *puVar3 = 0x22;

    break;

  case 0x22:

    lVar10 = FUN_0039f6e0(puVar15);

    if (lVar10 == 1) {

      uVar16 = (u32)*(u8 *)(puVar3 + 4);

      lVar10 = FUN_00172160(uVar16);

      if (lVar10 != 1) {

        lVar10 = FUN_001717c0(uVar16);

        if (lVar10 != 1) {

          for (iVar12 = 0; iVar12 < 5; iVar12 = iVar12 + 1) {

            if (uVar16 == *(u32 *)(&DAT_006a11d0 + iVar12 * 8)) {

              uVar8 = *(u32 *)(&DAT_006a11d4 + iVar12 * 8);

              goto LAB_00399518;

            }

          }

          uVar8 = 10;

        }

        else {

          uVar8 = 0;

        }

      }

      else {

        uVar8 = 0;

      }

LAB_00399518:

      lVar10 = FUN_0039f800(puVar15);

      puVar3[0x1f] = (int)lVar10;

      if ((lVar10 == 1) && (lVar10 = FUN_00395230(uVar8), lVar10 == 1)) {

        puVar3[3] = 1;

      }

      *puVar3 = 0x23;

    }

    break;

  case 0x23:

    iVar12 = puVar3[0x1f];

    if (iVar12 == 2) {

      unaff_s1 = FUN_003983e0(3,*(u8 *)(puVar3 + 4));

      FUN_003b91c0(0x3f800000,*(u16 *)(puVar3 + 2),0,5,0,0,0);

      FUN_003b9320(0x3f800000,*(u16 *)(puVar3 + 2),0,0xd,0,1,0);

    }

    else if (iVar12 == 1) {

      unaff_s1 = FUN_003983e0(2,*(u8 *)(puVar3 + 4));

      FUN_003b91c0(0x3f800000,*(u16 *)(puVar3 + 2),0,5,0,0,0);

      FUN_003b9320(0x3f800000,*(u16 *)(puVar3 + 2),0,0xd,0,1,0);

    }

    else if (iVar12 == 0) {

      puVar3[0x20] = 1;

      unaff_s1 = FUN_003983e0(1,*(u8 *)(puVar3 + 4));

      FUN_003b91c0(0x3f800000,*(u16 *)(puVar3 + 2),0,7,0,0,0);

      FUN_003b9320(0x3f800000,*(u16 *)(puVar3 + 2),0,0xd,0,1,0);

    }

    FUN_0039f210(puVar15,unaff_s1,0xffffffffffffffff,0xffffffffffffffff);

    *puVar3 = 0x24;

    break;

  case 0x24:

    lVar10 = FUN_0039f6e0(puVar15);

    if (lVar10 == 1) {

      if (puVar3[3] != 0) {

        *puVar3 = 0x25;

      }

      else {

        *puVar3 = 0x27;

      }

    }

    break;

  case 0x25:

    FUN_0039f210(puVar15,3,0xffffffffffffffff,0xffffffffffffffff);

    *puVar3 = 0x26;

    break;

  case 0x26:

    lVar10 = FUN_0039f6e0(puVar15);

    if (lVar10 == 1) {

      *puVar3 = 0x27;

    }

    break;

  case 0x27:

    *puVar3 = 3;

    puVar3[1] = puVar3[1] + 1;

    break;

  case 0x28:

    if (puVar3[0x20] == 1) {

      FUN_001728d0(puVar3 + 4);

      FUN_005225a8(0x6a1290);

    }

    *puVar3 = 0x29;

    break;

  case 0x29:

    return 0xffffffff;

  }

  FUN_0039f410(puVar15);

  return 0;

}
#define FUN_00398530(...) ((u32 (*)(...))FUN_00398530)(__VA_ARGS__)
#undef FUN_00399830
// FUN_00399830


void FUN_00399830(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  if (*(void **)(iVar1 + 0x54) != (void *)0) {

    FUN_00100ec0(*(void **)(iVar1 + 0x54));

    *(u32 *)(iVar1 + 0x54) = 0;

  }

  FUN_0039ee80(iVar1 + 0x58);

  if (*(u16 *)(iVar1 + 0x94) != 0) {

    FUN_003b7090(*(u16 *)(iVar1 + 0x94));

    *(u16 *)(iVar1 + 0x94) = 0;

  }

  FUN_00386b70(iVar1,2,0x9c);

  return;

}
#define FUN_00399830(...) ((void (*)(...))FUN_00399830)(__VA_ARGS__)
#undef FUN_003998b0
// FUN_003998B0


u32 FUN_003998b0(int param_1)



{

  u32 *puVar1;

  u8 cVar2;

  int sVar3;

  u32 uVar4;

  u32 uVar5;

  int lVar6;

  u32 *puVar7;

  u8 auStack_4 [4];

  

  puVar1 = *(u32 **)(param_1 + 0x3c);

  puVar7 = puVar1 + 4;

  switch(*puVar1) {

  case 0:

    if ((*(u32 *)(puVar1[1] + 4) & 8) != 0) {

      lVar6 = FUN_001729a0();

      if (lVar6 == 0) {

        return 0xffffffff;

      }

      cVar2 = FUN_00172a10();

      if (cVar2 != '\0') {

        return 0xffffffff;

      }

      lVar6 = FUN_001729d0(puVar1 + 0xe);

      if (lVar6 == 0) {

        return 0xffffffff;

      }

    }

    uVar4 = FUN_00100d80(DAT_006a12b0,1);

    puVar1[3] = uVar4;

    *puVar1 = 1;

    break;

  case 1:

    lVar6 = FUN_001016b0(puVar1[3]);

    if (lVar6 == 1) {

      uVar5 = FUN_001021c0(DAT_006a12d0,auStack_4);

      puVar1[0xc] = (int)uVar5;

      FUN_0039ec70(puVar7,uVar5);

      if ((int)puVar1[0xe] < 0x2a) {

        uVar5 = FUN_003c3f40(puVar1[0xe] & 0xff);

        FUN_0039ef30(puVar7,0,uVar5);

      }

      *puVar1 = 2;

    }

    break;

  case 2:

    if ((*(u32 *)(puVar1[1] + 4) & 8) != 0) {

      FUN_0039f210(puVar7,1,-1,-1);

    }

    else {

      FUN_0039f210(puVar7,0,-1,-1);

    }

    *puVar1 = 3;

    break;

  case 3:

    lVar6 = FUN_0039f6e0(puVar7);

    if (lVar6 == 1) {

      *puVar1 = 4;

    }

    break;

  case 4:

    FUN_0039f210(puVar7,2,3,-1);

    *puVar1 = 5;

    break;

  case 5:

    lVar6 = FUN_0039f6e0(puVar7);

    if (lVar6 == 1) {

      uVar4 = FUN_0039f800(puVar7);

      puVar1[0xd] = uVar4;

      *puVar1 = 6;

    }

    break;

  case 6:

    sVar3 = FUN_0016dd40_d010();

    if (puVar1[0xd] == 0) {

      FUN_00172a20(1);

      FUN_0039f210(puVar7,sVar3 * 2 + 5,-1,-1);

    }

    else {

      FUN_00172a20(0);

      FUN_0039f210(puVar7,sVar3 * 2 + 6,-1,-1);

    }

    *puVar1 = 7;

    break;

  case 7:

    lVar6 = FUN_0039f6e0(puVar7);

    if (lVar6 == 1) {

      *puVar1 = 8;

    }

    break;

  case 8:

    return 0xffffffff;

  }

  FUN_0039f410(puVar7);

  return 0;

}
#define FUN_003998b0(...) ((u32 (*)(...))FUN_003998b0)(__VA_ARGS__)
#undef FUN_00399be0
// FUN_00399BE0


void FUN_00399be0(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  if (*(int *)(iVar1 + 0xc) != 0) {

    FUN_00100ec0(*(int *)(iVar1 + 0xc));

    *(u32 *)(iVar1 + 0xc) = 0;

  }

  FUN_0039ee80(iVar1 + 0x10);

  FUN_00386b70(iVar1,2,0x3c);

  return;

}
#define FUN_00399be0(...) ((void (*)(...))FUN_00399be0)(__VA_ARGS__)
#undef FUN_00399c40
// FUN_00399C40 NONMATCHING


u32 FUN_00399c40(int param_1)



{

  char cVar1;

  u32 *puVar2;

  short sVar3;

  short sVar4;

  u16 uVar5;

  u32 uVar6;

  u32 uVar7;
 
  int lVar8;

  u8 uVar9;

  u32 *puVar10;

  int iVar11;

  u8 auStack_4 [4];

  

  puVar2 = *(u32 **)(param_1 + 0x3c);

  puVar10 = puVar2 + 4;

  switch(*puVar2) {

  case 0:

    lVar8 = FUN_00395200(100);

    if (lVar8 < 0x28) {

      iVar11 = 0;

    }

    else if (lVar8 < 0x46) {

      iVar11 = 1;

    }

    else if (lVar8 < 0x5a) {

      iVar11 = 2;

    }

    else {

      iVar11 = 3;

    }

    cVar1 = *(char *)(iVar11 + puVar2[2] + 0x18);

    puVar2[0xf] = (int)cVar1;

    if (cVar1 == '\0') {

      return 0xffffffff;

    }

    puVar2[0xe] = (int)*(char *)(puVar2[2] + 0x14);

    cVar1 = *(char *)(puVar2[2] + 0x15);

    puVar2[0xd] = (int)cVar1;

    puVar2[0x14] = (u32)PTR_s_Academics_006a1320[cVar1];

    *(u16 *)(puVar2 + 0x13) = *(u16 *)(puVar2[2] + 0x1c);

    if ((puVar2[0xe] == 1) &&

       ((((iVar11 = puVar2[0xd], iVar11 == 7 || (iVar11 == 6)) || (iVar11 == 5)) ||

        ((iVar11 == 4 || (iVar11 == 3)))))) {

      return 0xffffffff;

    }

    switch(puVar2[0xd]) {

    case 0:

    case 1:

    case 2:

      puVar2[0x10] = puVar2[0xf];

      break;

    case 3:

    case 4:

    case 5:

    case 6:

    case 7:

      puVar2[0x10] = puVar2[0xf];

    }

    if (puVar2[0xe] == 0) {

      FUN_0016c920(1);

      iVar11 = puVar2[0x10];

      puVar2[0x10] = (int)(float)iVar11;

      if ((int)(float)iVar11 < 1) {

        return 0xffffffff;

      }

      FUN_00395170(0x98b);

    }

    iVar11 = puVar2[0xd];

    if (iVar11 == 2) {

      sVar3 = FUN_0016c790(1);

      sVar4 = FUN_00177360(sVar3);

      puVar2[0x11] = (int)sVar4;

      sVar3 = FUN_00177360(sVar3 + (short)puVar2[0x10]);

      puVar2[0x12] = (int)sVar3;

      uVar6 = FUN_0011a870(*(u16 *)(puVar2 + 0x11));

      puVar2[0x15] = uVar6;

      uVar6 = FUN_0011a870(*(u16 *)(puVar2 + 0x12));

      puVar2[0x16] = uVar6;

    }

    else if (iVar11 == 1) {

      sVar3 = FUN_0016c740();

      sVar4 = FUN_001772f0(sVar3);

      puVar2[0x11] = (int)sVar4;

      sVar3 = FUN_001772f0(sVar3 + (short)puVar2[0x10]);

      puVar2[0x12] = (int)sVar3;

      uVar6 = FUN_0011a840(*(u16 *)(puVar2 + 0x11));

      puVar2[0x15] = uVar6;

      uVar6 = FUN_0011a840(*(u16 *)(puVar2 + 0x12));

      puVar2[0x16] = uVar6;

    }

    else if (iVar11 == 0) {

      sVar3 = FUN_0016c6f0();

      sVar4 = FUN_00177280(sVar3);

      puVar2[0x11] = (int)sVar4;

      sVar3 = FUN_00177280(sVar3 + (short)puVar2[0x10]);

      puVar2[0x12] = (int)sVar3;

      uVar6 = FUN_0011a810(*(u16 *)(puVar2 + 0x11));

      puVar2[0x15] = uVar6;

      uVar6 = FUN_0011a810(*(u16 *)(puVar2 + 0x12));

      puVar2[0x16] = uVar6;

    }

    else {

      puVar2[0x11] = 0;

      puVar2[0x12] = 0;

    }

    if ((*(u32 *)(puVar2[1] + 4) & 8) != 0) {

      iVar11 = puVar2[0xd];

      switch(iVar11) {

      case 0:

        sVar3 = FUN_0016c6f0(1);

        sVar3 = (short)puVar2[0x10] + sVar3;

        if (999 < sVar3) {

          sVar3 = 999;

        }

        FUN_0016cfe0(1,sVar3);

        break;

      case 1:

        sVar3 = FUN_0016c740(1);

        sVar3 = (short)puVar2[0x10] + sVar3;

        if (999 < sVar3) {

          sVar3 = 999;

        }

        FUN_0016d090(1,sVar3);

        break;

      case 2:

        sVar3 = FUN_0016c790(1);

        sVar3 = (short)puVar2[0x10] + sVar3;

        if (999 < sVar3) {

          sVar3 = 999;

        }

        FUN_0016d160(1,sVar3);

        break;

      case 3:

      case 4:

      case 5:

      case 6:

      case 7:

        uVar6 = puVar2[0x10];

        uVar5 = FUN_00175360();

        uVar9 = (u8)uVar6;

        if (iVar11 == 7) {

          FUN_00174710(uVar5,4,uVar9);

        }

        else if (iVar11 == 6) {

          FUN_00174710(uVar5,3,uVar9);

        }

        else if (iVar11 == 5) {

          FUN_00174710(uVar5,2,uVar9);

        }

        else if (iVar11 == 4) {

          FUN_00174710(uVar5,1,uVar9);

        }

        else if (iVar11 == 3) {

          FUN_00174710(uVar5,0,uVar9);

        }

      }

    }

    uVar6 = FUN_00100d80(0x6a1340,1);

    puVar2[3] = uVar6;

    *puVar2 = 1;

    break;

  case 1:

    lVar8 = FUN_001016b0(puVar2[3]);

    if (lVar8 == 1) {

      uVar7 = FUN_001021c0(0x6a1360,auStack_4);

      puVar2[0xc] = (int)uVar7;

      FUN_0039ec70(puVar10,uVar7);

      FUN_0039ef30(puVar10,0,puVar2[0x14]);

      FUN_0039eef0(puVar10,1,puVar2[0x10]);

      *puVar2 = 2;

    }

    break;

  case 2:

    if (puVar2[0xe] == 0) {

      FUN_0039f210(puVar10,0,0xffffffffffffffff,0xffffffffffffffff);

    }

    else {

      FUN_0039f210(puVar10,1,0xffffffffffffffff,0xffffffffffffffff);

    }

    FUN_0010a4e0(0,0,4,3);

    FUN_003bb010(*(u16 *)(puVar2 + 0x13),7);

    *puVar2 = 3;

    break;

  case 3:

    lVar8 = FUN_0039f6e0(puVar10);

    if (lVar8 == 1) {

      *puVar2 = 4;

    }

    break;

  case 4:

    if (puVar2[0x11] == puVar2[0x12]) {

      *puVar2 = 8;

    }

    else {

      FUN_0039ef30(puVar10,1,puVar2[0x15]);

      FUN_0039ef30(puVar10,2,puVar2[0x16]);

      FUN_0039f210(puVar10,2,0xffffffffffffffff,0xffffffffffffffff);

      *puVar2 = 5;

    }

    break;

  case 5:

    lVar8 = FUN_0039f6e0(puVar10);

    if (lVar8 == 1) {

      *puVar2 = 8;

    }

    break;

  case 6:

    iVar11 = puVar2[0xd];

    if (iVar11 == 1) {

      iVar11 = 0;

      lVar8 = FUN_003951d0(0x121a);

      if (lVar8 != 1) {

        lVar8 = FUN_003951d0(0x121b);

        if (lVar8 == 1) {

          iVar11 = 1;

        }

        else {

          lVar8 = FUN_003951d0(0x121c);

          if (lVar8 == 1) {

            iVar11 = 2;

          }

          else {

            lVar8 = FUN_003951d0(0x121d);

            if (lVar8 == 1) {

              iVar11 = 3;

            }

            else {

              lVar8 = FUN_003951d0(0x121e);

              if (lVar8 == 1) {

                iVar11 = 4;

              }

            }

          }

        }

      }

      FUN_0039f210(puVar10,iVar11 + 5,0xffffffffffffffff,0xffffffffffffffff);

    }

    else if (iVar11 == 2) {

      FUN_0039f210(puVar10,4,0xffffffffffffffff,0xffffffffffffffff);

    }

    else if (iVar11 == 0) {

      FUN_0039f210(puVar10,3,0xffffffffffffffff,0xffffffffffffffff);

    }

    *puVar2 = 7;

    break;

  case 7:

    lVar8 = FUN_0039f6e0(puVar10);

    if (lVar8 == 1) {

      *puVar2 = 8;

    }

    break;

  case 8:

    return 0xffffffff;

  }

  FUN_0039f410(puVar10);

  return 0;

}
#define FUN_00399c40(...) ((u32 (*)(...))FUN_00399c40)(__VA_ARGS__)
#undef FUN_0039a560
// FUN_0039A560


void FUN_0039a560(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  if (*(int *)(iVar1 + 0xc) != 0) {

    FUN_00100ec0(*(int *)(iVar1 + 0xc));

    *(u32 *)(iVar1 + 0xc) = 0;

  }

  FUN_0039ee80(iVar1 + 0x10);

  FUN_00386b70(iVar1,2,0x5c);

  return;

}
#define FUN_0039a560(...) ((void (*)(...))FUN_0039a560)(__VA_ARGS__)
#undef FUN_0039a5c0
// FUN_0039A5C0


u32 FUN_0039a5c0(int param_1)



{

  u32 uVar1;

  u32 *puVar2;

  int iVar3;

  u32 uVar4;

  u32 uVar5;
 
  int lVar6;

  u32 *puVar7;

  u8 auStack_4 [4];

  

  puVar2 = *(u32 **)(param_1 + 0x3c);

  puVar7 = puVar2 + 4;

  iVar3 = puVar2[1];

  switch(*puVar2) {

  case 0:

    if ((*(u32 *)(iVar3 + 4) & 8) != 0) {

      lVar6 = FUN_00172c50(puVar2 + 0xd);

      if (lVar6 == 0) {

        *puVar2 = 6;

        break;

      }

      lVar6 = FUN_001717c0(*(s16 *)(puVar2 + 0xd));

      if ((lVar6 == 0) && (lVar6 = FUN_00172160(*(s16 *)(puVar2 + 0xd)), lVar6 == 0)) {

        *puVar2 = 6;

        break;

      }

    }

    else {

      *(u16 *)(puVar2 + 0xd) = 0;

    }

    uVar1 = *(u16 *)(puVar2[2] + 0x14);

    FUN_003b91c0_a5c0(1.0f,uVar1,0,3,0,0,0);

    FUN_003bb010(uVar1,0x11);

    FUN_003952d0(0,0x65,3);

    uVar4 = FUN_00100d80(DAT_006a1380,1);

    puVar2[3] = uVar4;

    *puVar2 = 1;

    break;

  case 1:

    lVar6 = FUN_001016b0(puVar2[3]);

    if (lVar6 == 1) {

      uVar5 = FUN_001021c0(DAT_006a13a0,auStack_4);

      puVar2[0xc] = (int)uVar5;

      FUN_0039ec70(puVar7,uVar5);

      *puVar2 = 2;

    }

    break;

  case 2:

    FUN_0039f210(puVar7,0,-1,-1);

    *puVar2 = 3;

    break;

  case 3:

    lVar6 = FUN_0039f6e0(puVar7);

    if (lVar6 == 1) {

      *puVar2 = 4;

    }

    break;

  case 4:

    FUN_0039f210(puVar7,*(short *)(puVar2 + 0xd) + 3,-1,-1);

    *puVar2 = 5;

    break;

  case 5:

    lVar6 = FUN_0039f6e0(puVar7);

    if (lVar6 == 1) {

      if ((*(u32 *)(iVar3 + 4) & 8) != 0) {

        FUN_00172b20();

      }

      *puVar2 = 6;

    }

    break;

  case 6:

    return 0xffffffff;

  }

  FUN_0039f410(puVar7);

  return 0;

}
#define FUN_0039a5c0(...) ((u32 (*)(...))FUN_0039a5c0)(__VA_ARGS__)
#undef FUN_0039a840
// FUN_0039A840


void FUN_0039a840(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  if (*(int *)(iVar1 + 0xc) != 0) {

    FUN_00100ec0(*(int *)(iVar1 + 0xc));

    *(u32 *)(iVar1 + 0xc) = 0;

  }

  FUN_0039ee80(iVar1 + 0x10);

  FUN_00386b70(iVar1,2,0x38);

  return;

}
#define FUN_0039a840(...) ((void (*)(...))FUN_0039a840)(__VA_ARGS__)
#undef FUN_0039a8a0
// FUN_0039A8A0 NONMATCHING


u32 FUN_0039a8a0(int param_1)



{
  extern u32 *FUN_003c2ee0(u32 param_1);

  short sVar1;
  u32 *puVar11;
  u32 uVar2;

  u8 *puVar4;

  u8 uVar5;

  char cVar6;

  u16 uVar7;

  u32 uVar8;

  u32 uVar9;

  int lVar10;
  u32 *puVar13;

  u32 *puVar3;

  int iVar12;

  u16 auStack_30 [14];

  u16 auStack_40 [8];

  u8 auStack_4 [4];

  u16 auStack_8 [2];

  u8 auStack_c [4];

  int iStack_10;

  int iStack_14;

  

  puVar3 = *(u32 **)(param_1 + 0x3c);

  puVar11 = puVar3 + 0x227;

  switch(*puVar3) {

  case 0:

    lVar10 = FUN_003beca0(puVar3 + 4);

    puVar3[2] = (int)lVar10;

    if (lVar10 == 0) {

      *puVar3 = 0x21;

    }

    else {

      uVar8 = FUN_00100d80(0x6a13c0,1);

      puVar3[0x226] = uVar8;

      *puVar3 = 1;

      puVar3[0x22] = 0;

    }

    break;

  case 1:

    lVar10 = FUN_001016b0(puVar3[0x226]);

    if (lVar10 == 1) {

      uVar9 = FUN_001021c0(0x6a13e0,auStack_4);

      puVar3[0x22f] = (int)uVar9;

      FUN_0039ec70(puVar11,uVar9);

      uVar9 = FUN_001021c0(0x6a1400,auStack_4);

      FUN_003c94e0(uVar9);

      puVar3[0x236] = 1;

      *puVar3 = 2;

    }

    break;

  case 2:

    *puVar3 = 3;

    break;

  case 3:

    if ((int)puVar3[3] >= (int)puVar3[2]) {

      *puVar3 = 0x21;

    }

    else {

      if ((int)puVar3[0x224] < (int)puVar3[0x225]) {

        puVar3[0x224] = puVar3[0x224] + 1;

      }

      else {

        uVar8 = puVar3[puVar3[3] + 4];

        puVar3[0x230] = uVar8;

        FUN_0016e920((short)uVar8);

        FUN_003beb70(puVar3[0x230]);

        puVar13 = FUN_003c2ee0(puVar3[0x230]);

        if (puVar13 == 0) {

          FUN_0019d3f0("mt_evtCustomEvent.c",0x6b7);

        }

        FUN_0039ef70(puVar11,0,puVar3[0x230]);

        FUN_0039efd0(puVar11,1,puVar3[0x230]);

        FUN_0039f050(puVar11,2,puVar3[0x230]);

        iVar12 = (int)puVar13;

        uVar9 = FUN_003c4270(*(u32 *)(iVar12 + 4),*(u32 *)(iVar12 + 8));

        FUN_0039ef30(puVar11,3,uVar9);

        FUN_0039f0c0(puVar11,4,*(u8 *)(iVar12 + 0x2a));

        lVar10 = FUN_0016dbc0(*(u16 *)(puVar3 + 0x230),auStack_8);

        if (lVar10 == 1) {

          uVar9 = FUN_00173220(auStack_8[0]);

          FUN_0039ef30(puVar11,5,uVar9);

        }

        FUN_003bb010(*(u16 *)(puVar3 + 1),0x11);

        FUN_003952d0(0,0x65,3);

        puVar3[0x224] = 0;

        puVar3[0x225] = 0x32;

        *puVar3 = 4;

      }

    }

    break;

  case 4:

    if ((int)puVar3[0x224] < (int)puVar3[0x225]) {

      puVar3[0x224] = puVar3[0x224] + 1;

    }

    else {

      FUN_003b91c0(1.0f,*(u16 *)(puVar3 + 1),0,0x16,0,0,0);

      FUN_003b9320(1.0f,*(u16 *)(puVar3 + 1),0,0x17,0,1,0);

      FUN_0039f210(puVar11,puVar3[0x230] * 9 + 0xc,puVar3[0x230] * 9 + 0xd,0xffffffffffffffff);

      *puVar3 = 5;

    }

    break;

  case 5:

    lVar10 = FUN_0039f6e0(puVar11);

    if (lVar10 == 1) {

      lVar10 = FUN_0039f800(puVar11);

      puVar3[0x232] = (int)lVar10;

      if (lVar10 == 1) {

        *puVar3 = 6;

      }

      else {

        lVar10 = FUN_0016dbc0(*(u16 *)(puVar3 + 0x230),auStack_c);

        if (lVar10 == 1) {

          *puVar3 = 10;

        }

        else {

          *puVar3 = 8;

        }

      }

    }

    break;

  case 6:

    FUN_0039f210(puVar11,puVar3[0x230] * 9 + 0xe,0xffffffffffffffff,0xffffffffffffffff);

    *puVar3 = 7;

    break;

  case 7:

    lVar10 = FUN_0039f6e0(puVar11);

    if (lVar10 == 1) {

      puVar3[3] = puVar3[3] + 1;

      puVar3[0x224] = 0;

      puVar3[0x225] = 0x3c;

      *puVar3 = 3;

      FUN_003b91c0(1.0f,*(u16 *)(puVar3 + 1),0,0x18,0,0,0);

      FUN_003b9320(1.0f,*(u16 *)(puVar3 + 1),0,0,0,1,0);

    }

    break;

  case 8:

    FUN_0039f210(puVar11,puVar3[0x230] * 9 + 0xf,puVar3[0x230] * 9 + 0x10,0xffffffffffffffff);

    *puVar3 = 9;

    break;

  case 9:

    lVar10 = FUN_0039f6e0(puVar11);

    if (lVar10 == 1) {

      lVar10 = FUN_0039f800(puVar11);

      puVar3[0x232] = (int)lVar10;

      if (lVar10 == 1) {

        *puVar3 = 0xf;

      }

      else if (lVar10 == 2) {

        *puVar3 = 0xd;

      }

      else if (lVar10 == 0) {

        *puVar3 = 0xc;

      }

    }

    break;

  case 10:

    FUN_0039f210(puVar11,puVar3[0x230] * 9 + 0xf,0xffffffffffffffff,0xffffffffffffffff);

    *puVar3 = 0xb;

    break;

  case 0xb:

    lVar10 = FUN_0039f6e0(puVar11);

    if (lVar10 == 1) {

      FUN_0039f210(puVar11,5,puVar3[0x230] * 9 + 0x10,0xffffffffffffffff);

      *puVar3 = 9;

    }

    break;

  case 0xc:

    lVar10 = FUN_00172c50(puVar3 + 0x223);

    if (lVar10 == 0) {

      *puVar3 = 0x1f;

    }

    else {

      *puVar3 = 0x17;

    }

    break;

  case 0xd:

    FUN_0039f210(puVar11,puVar3[0x230] * 9 + 0x11,0xffffffffffffffff,0xffffffffffffffff);

    *puVar3 = 0xe;

    break;

  case 0xe:

    lVar10 = FUN_0039f6e0(puVar11);

    if (lVar10 == 1) {

      puVar3[3] = puVar3[3] + 1;

      puVar3[0x224] = 0;

      puVar3[0x225] = 0x3c;

      *puVar3 = 3;

      FUN_003b91c0(1.0f,*(u16 *)(puVar3 + 1),0,0x18,0,0,0);

      FUN_003b9320(1.0f,*(u16 *)(puVar3 + 1),0,0,0,1,0);

    }

    break;

  case 0xf:

    uVar9 = FUN_003c3f80(puVar3[0x230]);

    FUN_0039ef30(puVar11,0,uVar9);

    uVar5 = FUN_0016df30(*(u16 *)(puVar3 + 0x230));

    uVar9 = FUN_0030bbb0(uVar5);

    FUN_0039ef30(puVar11,1,uVar9);

    uVar5 = FUN_0016dba0(*(u16 *)(puVar3 + 0x230));

    FUN_0039eef0(puVar11,2,uVar5);

    FUN_0039f210(puVar11,puVar3[0x230] + 0x11a,0xffffffffffffffff,0xffffffffffffffff);

    *puVar3 = 0x10;

    break;

  case 0x10:

    lVar10 = FUN_0039f6e0(puVar11);

    if (lVar10 == 1) {

      puVar3[0x234] = 0;

      uVar8 = FUN_003bee80(puVar3[0x230],puVar3 + 0x233);

      puVar3[0x235] = uVar8;

      *puVar3 = 0x13;

    }

    break;

  case 0x11:

    uVar5 = FUN_0016df30(*(u16 *)(puVar3 + 0x230));

    uVar9 = FUN_0030bbb0(uVar5);

    FUN_0039ef30(puVar11,0,uVar9);

    FUN_0039f210(puVar11,6,7,0xffffffffffffffff);

    *puVar3 = 0x12;

    break;

  case 0x12:

    lVar10 = FUN_0039f6e0(puVar11);

    if (lVar10 == 1) {

      lVar10 = FUN_0039f800(puVar11);

      if (lVar10 != 0) {

        *puVar3 = 8;

      }

      else {

        puVar3[0x234] = 0;

        uVar8 = FUN_003bee80(puVar3[0x230],puVar3 + 0x233);

        puVar3[0x235] = uVar8;

        *puVar3 = 0x13;

      }

    }

    break;

  case 0x13:

    if ((int)puVar3[0x234] >= (int)puVar3[0x233]) {

      *puVar3 = 0x15;

    }

    else {

      uVar2 = *(u16 *)(puVar3[0x235] + puVar3[0x234] * 2);

      FUN_003c7c20(0,*(u8 *)((u32)uVar2 * 0xe + iGpffffb730 + 3),0);

      uVar9 = FUN_00173220(uVar2);

      FUN_003c7bc0(1,uVar9);

      for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {

        uVar9 = FUN_003c43f0();

        FUN_003c7bc0(iVar12 + 2,uVar9);

      }

      FUN_00176fb0(uVar2,auStack_30,&iStack_10);

      for (iVar12 = 0; iVar12 < iStack_10; iVar12 = iVar12 + 1) {

        uVar9 = FUN_0030bb40(auStack_30[iVar12]);

        FUN_003c7bc0(iVar12 + 2,uVar9);

      }

      FUN_005225a8(0x6a1420,uVar2);

      FUN_003c9790(0);

      *puVar3 = 0x14;

    }

    break;

  case 0x14:

    lVar10 = FUN_003c7850();

    if (lVar10 == 0) {

      FUN_003c7700();

      puVar3[0x234] = puVar3[0x234] + 1;

      *puVar3 = 0x13;

    }

    FUN_003c7b90();

    break;

  case 0x15:

    cVar6 = FUN_0016dba0(*(u16 *)(puVar3 + 0x230));

    puVar4 = PTR_s_It_seems_further_power_lies_hi_007cd6f4;

    if (cVar6 == '\n') {

      puVar4 = PTR_s_No_further_power_is_available__007cd6f0;

    }

    FUN_0039ef30(puVar11,5,puVar4);

    FUN_0039f210(puVar11,8,0xffffffffffffffff,0xffffffffffffffff);

    *puVar3 = 0x16;

    break;

  case 0x16:

    lVar10 = FUN_0039f6e0(puVar11);

    if (lVar10 == 1) {

      *puVar3 = 8;

    }

    break;

  case 0x17:

    FUN_0039f210(puVar11,1,2,0xffffffffffffffff);

    *puVar3 = 0x18;

    break;

  case 0x18:

    lVar10 = FUN_0039f6e0(puVar11);

    if (lVar10 == 1) {

      lVar10 = FUN_0039f800(puVar11);

      puVar3[0x232] = (int)lVar10;

      if (lVar10 == 1) {

        *puVar3 = 0x19;

      }

      else if (lVar10 == 2) {

        *puVar3 = 0xd;

      }

      else if (lVar10 == 0) {

        FUN_00172cc0(*(u16 *)(puVar3 + 0x223));

        FUN_00172b20();

        uVar7 = FUN_003bdbb0();

        FUN_00171960(*(u16 *)(puVar3 + 0x223),uVar7);

        *puVar3 = 0x1f;

      }

    }

    break;

  case 0x19:

    sVar1 = *(short *)(puVar3 + 0x223);

    uVar9 = FUN_003c3f80(sVar1);

    FUN_0039ef30(puVar11,0,uVar9);

    uVar5 = FUN_0016df30(sVar1);

    uVar9 = FUN_0030bbb0(uVar5);

    FUN_0039ef30(puVar11,1,uVar9);

    uVar5 = FUN_0016dba0(sVar1);

    FUN_0039eef0(puVar11,2,uVar5);

    FUN_0039f210(puVar11,sVar1 + 0x11a,0xffffffffffffffff,0xffffffffffffffff);

    *puVar3 = 0x1c;

    break;

  case 0x1a:

    if ((int)puVar3[0x234] >= (int)puVar3[0x233]) {

      *puVar3 = 0x1d;

    }

    else {

      uVar2 = *(u16 *)(puVar3[0x235] + puVar3[0x234] * 2);

      FUN_003c7c20(0,*(u8 *)((u32)uVar2 * 0xe + iGpffffb730 + 3),0);

      uVar9 = FUN_00173220(uVar2);

      FUN_003c7bc0(1,uVar9);

      for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {

        uVar9 = FUN_003c43f0();

        FUN_003c7bc0(iVar12 + 2,uVar9);

      }

      FUN_00176fb0(uVar2,auStack_40,&iStack_14);

      for (iVar12 = 0; iVar12 < iStack_14; iVar12 = iVar12 + 1) {

        uVar9 = FUN_0030bb40(auStack_40[iVar12]);

        FUN_003c7bc0(iVar12 + 2,uVar9);

      }

      FUN_005225a8(0x6a1420,uVar2);

      FUN_003c9790(0);

      *puVar3 = 0x1b;

    }

    break;

  case 0x1b:

    lVar10 = FUN_003c7850();

    if (lVar10 == 0) {

      FUN_003c7700();

      puVar3[0x234] = puVar3[0x234] + 1;

      *puVar3 = 0x1a;

    }

    FUN_003c7b90();

    break;

  case 0x1c:

    lVar10 = FUN_0039f6e0(puVar11);

    if (lVar10 == 1) {

      puVar3[0x234] = 0;

      uVar8 = FUN_003bee80(*(u16 *)(puVar3 + 0x223),puVar3 + 0x233);

      puVar3[0x235] = uVar8;

      *puVar3 = 0x1a;

    }

    break;

  case 0x1d:

    cVar6 = FUN_0016dba0(*(u16 *)(puVar3 + 0x223));

    puVar4 = PTR_s_It_seems_further_power_lies_hi_007cd6f4;

    if (cVar6 == '\n') {

      puVar4 = PTR_s_No_further_power_is_available__007cd6f0;

    }

    FUN_0039ef30(puVar11,5,puVar4);

    FUN_0039f210(puVar11,8,0xffffffffffffffff,0xffffffffffffffff);

    *puVar3 = 0x1e;

    break;

  case 0x1e:

    lVar10 = FUN_0039f6e0(puVar11);

    if (lVar10 == 1) {

      *puVar3 = 0x17;

    }

    break;

  case 0x1f:

    lVar10 = FUN_003c30b0();

    if (lVar10 == 0) {

      FUN_0019d3f0("mt_evtCustomEvent.c",0x896);

    }

    FUN_0039f210(puVar11,puVar3[0x230] * 9 + 0x12,0xffffffffffffffff,0xffffffffffffffff);

    *puVar3 = 0x20;

    break;

  case 0x20:

    lVar10 = FUN_0039f6e0(puVar11);

    if (lVar10 == 1) {

      puVar3[3] = puVar3[3] + 1;

      puVar3[0x224] = 0;

      puVar3[0x225] = 0x3c;

      *puVar3 = 3;

      FUN_003b91c0(1.0f,*(u16 *)(puVar3 + 1),0,0x18,0,0,0);

      FUN_003b9320(1.0f,*(u16 *)(puVar3 + 1),0,0,0,1,0);

    }

    break;

  case 0x21:

    return 0xffffffff;

  }

  FUN_0039f410(puVar11);

  return 0;

}
#define FUN_0039a8a0(...) ((u32 (*)(...))FUN_0039a8a0)(__VA_ARGS__)
#undef FUN_0039b830
// FUN_0039B830


void FUN_0039b830(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  if (*(int *)(iVar1 + 0x8d8) != 0) {

    FUN_003c77a0_b830();

    *(u32 *)(iVar1 + 0x8d8) = 0;

  }

  if (*(int *)(iVar1 + 0x898) != 0) {


    FUN_00100ec0_b830_arg((void *)(*(int *)(iVar1 + 0x898)));
    *(u32 *)(iVar1 + 0x898) = 0;

  }

  FUN_0039ee80_b830((void *)(iVar1 + 0x89c));

  (*DAT_0096017c_abs)(iVar1);

  return;

}
#define FUN_0039b830(...) ((void (*)(...))FUN_0039b830)(__VA_ARGS__)
#undef FUN_0039b8b0
// FUN_0039B8B0


void FUN_0039b8b0(u64 param_1,u16 param_2)



{

  u32 uVar1;

  

  uVar1 = (*DAT_00960178_abs)(0x8dc,0x40000);

  FUN_00521408_b8b0((void *)(u32)uVar1,0,0x8dc);

  *(u16 *)((int)uVar1 + 4) = param_2;

  FUN_00194b20_b8b0(param_1,DAT_006a1430,0x10,FUN_0039a8a0_b8b0,FUN_0039b830_b8b0,(void *)(u32)uVar1);

  return;

}
#define FUN_0039b8b0(...) ((void (*)(...))FUN_0039b8b0)(__VA_ARGS__)
#undef FUN_0039b950
// FUN_0039B950 NONMATCHING


u32 FUN_0039b950(u64 param_1)



{

  u32 *puVar1;

  u16 uVar2;

  int iVar3;

  int iVar4;

  u32 uVar5;

  int lVar6;

  int iVar7;

  u32 *puVar8;

  u32 uVar9;

  u8 auStack_270 [304];

  char acStack_140 [316];

  u8 auStack_4 [4];

  

  puVar1 = *(u32 **)((int)param_1 + 0x3c);

  puVar8 = puVar1 + 4;

  iVar3 = puVar1[1];

  switch(*puVar1) {

  case 0:

    FUN_00521408(puVar1 + 0xf,0,0x18);

    if ((*(u32 *)(iVar3 + 4) & 8) == 0) {

      puVar1[0xe] = 3;

      puVar1[0xf] = 6;

      puVar1[0x10] = 7;

      puVar1[0x11] = 0xb;

      for (iVar3 = 0; iVar3 < (int)puVar1[0xe]; iVar3 = iVar3 + 1) {

        FUN_0016dfb0(*(u16 *)(puVar1 + iVar3 + 0xf));

      }

      puVar1[0x15] = 8;

      puVar1[0x16] = 0x28;

    }

    else {

      iVar4 = FUN_00172e40();

      iVar3 = *(int *)(iVar4 + 0x18);

      puVar1[0xe] = iVar3;

      for (iVar7 = 0; iVar7 < iVar3; iVar7 = iVar7 + 1) {

        puVar1[iVar7 + 0xf] = *(u32 *)(iVar4 + iVar7 * 4);

      }

      puVar1[0x15] = *(u32 *)(iVar4 + 0x1c);

      puVar1[0x16] = *(u32 *)(iVar4 + 0x20);

    }

    if (puVar1[0xe] != 0) {

      puVar1[0xd] = 0;

      *(u16 *)((int)puVar1 + 0x66) = *(u16 *)(puVar1[2] + 0x14);

      uVar9 = FUN_00100d80(0x6a1440,1);

      puVar1[3] = uVar9;

      *puVar1 = 1;

    }

    else {

      *puVar1 = 0xf;

    }

    break;

  case 1:

    lVar6 = FUN_001016b0(puVar1[3]);

    if (lVar6 == 1) {

      uVar5 = FUN_001021c0(0x6a1460,auStack_4);

      puVar1[0xc] = (int)uVar5;

      FUN_0039ec70(puVar8,uVar5);

      uVar5 = FUN_0017d9c0(puVar1[0x16]);

      FUN_0039eef0(puVar8,0,uVar5);

      *puVar1 = 2;

    }

    break;

  case 2:

    if ((int)puVar1[0xd] < (int)puVar1[0xe]) {

      FUN_003951a0(0xa18);

      puVar1[0x17] = puVar1[puVar1[0xd] + 0xf];

      uVar2 = FUN_003c4110();

      uVar9 = FUN_00316e00(5,uVar2,0);

      puVar1[0x18] = uVar9;

      puVar1[0xd] = puVar1[0xd] + 1;

      uVar5 = FUN_003c4040(puVar1[0x15],puVar1[0x17]);

      FUN_0039ef30(puVar8,1,uVar5);

      *puVar1 = 3;

    }

    else {

      *puVar1 = 0xf;

    }

    break;

  case 3:

    lVar6 = FUN_00316f70(puVar1[0x18]);

    if (lVar6 == 1) {

      uVar2 = FUN_003b6270(0x38a,3,puVar1[0x18]);

      *(u16 *)(puVar1 + 0x19) = uVar2;

      FUN_0038d840(*(u32 *)(puVar1[2] + 0x40),acStack_140,0);

      uVar9 = FUN_0038a900(5);

      if (acStack_140[0] >= '\x01') {

        FUN_003bb1d0(*(u16 *)(puVar1 + 0x19),1,1,0xd,6);

        FUN_003b89f0(uVar9,*(u16 *)(puVar1 + 0x19),acStack_140,0);

        FUN_003b91c0(0x3f800000,*(u16 *)(puVar1 + 0x19),0,1,0,1,0);

      }

      else {

        FUN_0019d3f0("mt_evtCustomEvent.c",0x991);

      }

      FUN_003b9550(*(u16 *)(puVar1 + 0x19),1);

      *puVar1 = 4;

    }

    break;

  case 4:

    lVar6 = FUN_003b95a0(*(u16 *)(puVar1 + 0x19));

    if (lVar6 == 0) {

      *puVar1 = 0xb;

      FUN_003b91c0(0x3f800000,*(u16 *)(puVar1 + 0x19),0,0,5,1,0);

      *puVar1 = 5;

    }

    break;

  case 5:

    iVar3 = FUN_00395200(3);

    FUN_0039f210(puVar8,(puVar1[0x17] + -6) * 0x14 + iVar3 + 3,0xffffffffffffffff,0xffffffffffffffff

                );

    *puVar1 = 6;

    break;

  case 6:

    lVar6 = FUN_0039f6e0(puVar8);

    if (lVar6 == 1) {

      *puVar1 = 7;

    }

    break;

  case 7:

    FUN_0039f210(puVar8,0,(puVar1[0x17] + -6) * 0x14 + 6,0xffffffffffffffff);

    *puVar1 = 8;

    break;

  case 8:

    lVar6 = FUN_0039f6e0(puVar8);

    if (lVar6 == 1) {

      FUN_003b91c0(0x3f800000,*(u16 *)((int)puVar1 + 0x66),0,3,0,0,0);

      FUN_003b9320(0x3f800000,*(u16 *)((int)puVar1 + 0x66),0,0,0,1,0);

      *puVar1 = 9;

    }

    break;

  case 9:

    iVar3 = FUN_0039f800(puVar8);

    iVar4 = FUN_00395200(4);

    FUN_0039f210(puVar8,iVar3 * 4 + iVar4 + (puVar1[0x17] + -6) * 0x14 + 7,0xffffffffffffffff,

                 0xffffffffffffffff);

    *puVar1 = 10;

    break;

  case 10:

    lVar6 = FUN_0039f6e0(puVar8);

    if (lVar6 == 1) {

      lVar6 = FUN_003951d0(0xa18);

      if (lVar6 == 1) {

        *puVar1 = 0xb;

      }

      else {

        *puVar1 = 0xd;

      }

    }

    break;

  case 0xb:

    uVar9 = FUN_003a2090(param_1,puVar1[0x17],2,*(u16 *)((int)puVar1 + 0x66));

    puVar1[0x1a] = uVar9;

    *puVar1 = 0xc;

    break;

  case 0xc:

    lVar6 = FUN_00195460(puVar1[0x1a]);

    if (lVar6 == 0) {

      *puVar1 = 0xd;

    }

    break;

  case 0xd:

    FUN_0038d840(*(u32 *)(puVar1[2] + 0x40),auStack_270,1);

    uVar9 = FUN_0038a900(10);

    FUN_003bb1d0(*(u16 *)(puVar1 + 0x19),1,1,0xc,6);

    FUN_003b89f0(uVar9,*(u16 *)(puVar1 + 0x19),auStack_270,0);

    FUN_003b91c0(0x3f800000,*(u16 *)(puVar1 + 0x19),0,1,0,1,0);

    *puVar1 = 0xe;

    break;

  case 0xe:

    lVar6 = FUN_003b95a0(*(u16 *)(puVar1 + 0x19));

    if (lVar6 == 0) {

      lVar6 = FUN_003951d0(0xa18);

      if (lVar6 == 1) {

        FUN_00171f50(puVar1[0x17]);

      }

      FUN_003b7090(*(u16 *)(puVar1 + 0x19));

      *(u16 *)(puVar1 + 0x19) = 0;

      *puVar1 = 2;

    }

    break;

  case 0xf:

    return 0xffffffff;

  }

  FUN_0039f410(puVar8);

  return 0;

}
#define FUN_0039b950(...) ((u32 (*)(...))FUN_0039b950)(__VA_ARGS__)
#undef FUN_0039c090
// FUN_0039C090


void FUN_0039c090(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  if (*(int *)(iVar1 + 0xc) != 0) {

    FUN_00100ec0(*(int *)(iVar1 + 0xc));

    *(u32 *)(iVar1 + 0xc) = 0;

  }

  FUN_0039ee80(iVar1 + 0x10);

  FUN_00386b70(iVar1,2,0x6c);

  return;

}
#define FUN_0039c090(...) ((void (*)(...))FUN_0039c090)(__VA_ARGS__)
#undef FUN_0039c0f0
// FUN_0039C0F0 NONMATCHING


u32 FUN_0039c0f0(int param_1)



{

  u32 *puVar1;

  int iVar2;

  u32 uVar3;

  u32 uVar4;

  int lVar5;

  u32 *puVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  short sVar10;

  int aiStack_30 [8];

  short asStack_10 [6];

  u8 auStack_4 [4];

  

  puVar1 = *(u32 **)(param_1 + 0x3c);

  puVar6 = puVar1 + 4;

  iVar2 = puVar1[1];

  switch(*puVar1) {

  case 0:

    *puVar1 = 5;

    break;

  case 1:

    iVar8 = 0;

    for (iVar9 = 0; iVar7 = -1, sVar10 = 0, iVar9 < 5; iVar9 = iVar9 + 1) {

      sVar10 = *(short *)(puVar1[0x10] + iVar9 * 2 + 0x14);

      if ((sVar10 != 0) && (lVar5 = FUN_0017afd0(sVar10), lVar5 != 0)) {

        lVar5 = FUN_0017ae50(sVar10);

        iVar7 = iVar9;

        if (lVar5 != 1) break;

        asStack_10[iVar8] = sVar10;

        aiStack_30[iVar8] = iVar9;

        iVar8 = iVar8 + 1;

      }

    }

    if (iVar7 != -1) {

      puVar1[0xd] = iVar7;

      *(short *)(puVar1 + 0xe) = sVar10;

    }

    else {

      if (iVar8 == 0) {

        *puVar1 = 5;

        FUN_00361050(iVar2,*(u16 *)(puVar1[2] + 0x14));

        break;

      }

      iVar2 = FUN_00395200(iVar8);

      puVar1[0xd] = aiStack_30[iVar2];

      *(short *)(puVar1 + 0xe) = asStack_10[iVar2];

    }

    uVar3 = FUN_00100d80(0x6a1480,1);

    puVar1[3] = uVar3;

    *puVar1 = 2;

    break;

  case 2:

    lVar5 = FUN_001016b0(puVar1[3]);

    if (lVar5 == 1) {

      uVar4 = FUN_001021c0(0x6a14a0,auStack_4);

      puVar1[0xc] = (int)uVar4;

      FUN_0039ec70(puVar6,uVar4);

      *puVar1 = 3;

    }

    break;

  case 3:

    uVar4 = FUN_0017b100(*(u16 *)(puVar1 + 0xe));

    FUN_0039ef30(puVar6,0,uVar4);

    FUN_0039f210(puVar6,puVar1[0xd] + puVar1[0xf] * 5 + 3,0xffffffffffffffff,0xffffffffffffffff);

    *puVar1 = 4;

    break;

  case 4:

    lVar5 = FUN_0039f6e0(puVar6);

    if (lVar5 == 1) {

      FUN_0017af20(*(u16 *)(puVar1 + 0xe));

      *puVar1 = 5;

    }

    break;

  case 5:

    if ((*(u32 *)(iVar2 + 4) & 8) == 0) {

      FUN_00172ae0();

    }

    return 0xffffffff;

  }

  FUN_0039f410(puVar6);

  return 0;

}
#define FUN_0039c0f0(...) ((u32 (*)(...))FUN_0039c0f0)(__VA_ARGS__)
#undef FUN_0039c3e0
// FUN_0039C3E0


void FUN_0039c3e0(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  if (*(int *)(iVar1 + 0xc) != 0) {

    FUN_00100ec0(*(int *)(iVar1 + 0xc));

    *(u32 *)(iVar1 + 0xc) = 0;

  }

  FUN_0039ee80(iVar1 + 0x10);

  FUN_00386b70(iVar1,2,0x44);

  return;

}
#define FUN_0039c3e0(...) ((void (*)(...))FUN_0039c3e0)(__VA_ARGS__)
#undef FUN_0039c440
// FUN_0039C440 NONMATCHING


u32 FUN_0039c440(int param_1)



{

  u32 *puVar1;

  short sVar2;

  u32 uVar3;

  int iVar4;

  u32 uVar5;

  int iVar6;

  u8 *pbVar7;

  u32 uVar8;

  int lVar9;

  u32 uVar10;

  u32 uVar11;

  u16 uVar12;

  u32 *puVar13;

  u16 *puVar14;

  int iVar15;

  int iVar16;

  int iVar17;

  u8 auStack_4 [4];

  

  puVar1 = *(u32 **)(param_1 + 0x3c);

  puVar13 = puVar1 + 4;

  uVar3 = puVar1[1];

  iVar4 = puVar1[2];

  switch(*puVar1) {

  case 0:

    sVar2 = FUN_0016dd40();

    puVar1[0x17] = (int)sVar2;

    *(u16 *)(puVar1 + 0x1a) = *(u16 *)(iVar4 + 0x1c);

    lVar9 = FUN_0016dce0(*(u16 *)(puVar1 + 0x17));

    if (lVar9 == 0) {

      FUN_0019d3f0("mt_evtCustomEvent.c",0xb69);

    }

    iVar4 = 0;

    for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {

      iVar17 = 0;

      iVar16 = FUN_003bd870();

      iVar16 = *(int *)(iVar16 + 0x67c);

      if (3 < iVar6) {

        FUN_0019d3f0("mt_evtCustomEvent.c",0xb1f);

      }

      for (iVar15 = 0; iVar15 < 4; iVar15 = iVar15 + 1) {

        puVar14 = (u16 *)(iVar16 + iVar6 * 8 + iVar15 * 2);

        lVar9 = FUN_0017ae50(*puVar14);

        if (lVar9 == 1) {

          *(u16 *)((int)puVar1 + iVar17 * 2 + 0x3c) = *puVar14;

          puVar1[iVar17 + 0x11] = iVar15 + iVar6 * 4;

          iVar17 = iVar17 + 1;

        }

      }

      iVar4 = iVar4 + iVar17;

    }

    if ((iVar4 == 0) || (lVar9 = FUN_00172a50(*(u16 *)(puVar1 + 0x17)), lVar9 == 0)) {

      puVar1[0x18] = 0;

      *puVar1 = 0xc;

    }

    else {

      uVar3 = FUN_00100d80(0x6a14c0,1);

      puVar1[3] = uVar3;

      *puVar1 = 1;

    }

    break;

  case 1:

    lVar9 = FUN_001016b0(puVar1[3]);

    if (lVar9 == 1) {

      uVar8 = FUN_001021c0(0x6a14e0,auStack_4);

      puVar1[0xc] = (int)uVar8;

      FUN_0039ec70(puVar13,uVar8);

      uVar8 = FUN_003c3fe0(puVar1[0x17]);

      FUN_0039ef30(puVar13,0,uVar8);

      *puVar1 = 2;

    }

    break;

  case 2:

    FUN_0039f210(puVar13,0,1,0xffffffffffffffff);

    *puVar1 = 3;

    break;

  case 3:

    lVar9 = FUN_0039f6e0(puVar13);

    if (lVar9 == 1) {

      lVar9 = FUN_0039f800(puVar13);

      puVar1[0xd] = (int)lVar9;

      if (lVar9 == 0) {

        *puVar1 = 4;

      }

      else {

        puVar1[0x18] = 0;

        *puVar1 = 0xc;

      }

    }

    break;

  case 4:

    FUN_0039f210(puVar13,2,3,0xffffffffffffffff);

    *puVar1 = 5;

    break;

  case 5:

    lVar9 = FUN_0039f6e0(puVar13);

    if (lVar9 == 1) {

      uVar3 = FUN_0039f800(puVar13);

      puVar1[0xd] = uVar3;

      *puVar1 = 6;

    }

    break;

  case 6:

    iVar4 = puVar1[0xd];

    iVar16 = 0;

    iVar6 = FUN_003bd870();

    iVar6 = *(int *)(iVar6 + 0x67c);

    if (3 < iVar4) {

      FUN_0019d3f0("mt_evtCustomEvent.c",0xb1f);

    }

    for (iVar17 = 0; iVar17 < 4; iVar17 = iVar17 + 1) {

      puVar14 = (u16 *)(iVar6 + iVar4 * 8 + iVar17 * 2);

      lVar9 = FUN_0017ae50(*puVar14);

      if (lVar9 == 1) {

        *(u16 *)((int)puVar1 + iVar16 * 2 + 0x3c) = *puVar14;

        puVar1[iVar16 + 0x11] = iVar17 + iVar4 * 4;

        iVar16 = iVar16 + 1;

      }

    }

    puVar1[0x19] = iVar16;

    if (iVar16 == 0) {

      *puVar1 = 8;

    }

    else {

      FUN_0039f210(puVar13,5,6,0xffffffffffffffff);

      *puVar1 = 7;

      uVar10 = 0;

      for (uVar11 = puVar1[0x19]; (int)uVar11 < 4; uVar11 = uVar11 + 1) {

        uVar10 = uVar10 | 1 << (uVar11 & 0x1f);

      }

      FUN_003a3ba0(puVar1[6],uVar10 | 0x10);

      for (iVar4 = 0; iVar4 < (int)puVar1[0x19]; iVar4 = iVar4 + 1) {

        uVar8 = FUN_0017b100(*(u16 *)((int)puVar1 + iVar4 * 2 + 0x3c));

        FUN_0039ef30(puVar13,iVar4,uVar8);

      }

      FUN_003a4a70(puVar1[6],5,4);

    }

    break;

  case 7:

    lVar9 = FUN_0039f6e0(puVar13);

    if (lVar9 == 1) {

      lVar9 = FUN_0039f800(puVar13);

      puVar1[0xd] = (int)lVar9;

      if (lVar9 == 4) {

        *puVar1 = 4;

      }

      else {

        uVar11 = puVar1[(int)lVar9 + 0x11];

        iVar4 = FUN_003bd870();

        uVar10 = uVar11;

        if ((int)uVar11 < 0) {

          uVar10 = uVar11 + 3;

        }

        uVar5 = uVar11 & 3;

        if (((int)uVar11 < 0) && (uVar5 != 0)) {

          uVar5 = uVar5 - 4;

        }

        uVar12 = *(u16 *)(*(int *)(iVar4 + 0x67c) + ((int)uVar10 >> 2) * 8 + uVar5 * 2);

        iVar4 = puVar1[0x17];

        iVar6 = FUN_003bd870();

        puVar1[0x15] = (u32)*(u8 *)(*(int *)(iVar6 + 0x648) + iVar4 * 0x10 + uVar11);

        FUN_0017b070(uVar12);

        pbVar7 = (u8 *)FUN_003bdba0();

        if ((int)(u32)*pbVar7 >= (int)puVar1[0x15]) {

          puVar1[0x18] = 1;

        }

        else {

          if ((int)(u32)pbVar7[1] < (int)puVar1[0x15]) {

            puVar1[0x18] = 3;

          }

          else {

            puVar1[0x18] = 2;

          }

        }

        *puVar1 = 10;

      }

    }

    break;

  case 8:

    FUN_0039f210(puVar13,4,0xffffffffffffffff,0xffffffffffffffff);

    *puVar1 = 9;

    break;

  case 9:

    lVar9 = FUN_0039f6e0(puVar13);

    if (lVar9 == 1) {

      *puVar1 = 4;

    }

    break;

  case 10:

    if (*(char *)(iVar4 + 0x24) == '\0') {

      iVar6 = puVar1[0x18];

      if (iVar6 == 3) {

        FUN_0039f210(puVar13,puVar1[0x17] * 3 + 9,0xffffffffffffffff,0xffffffffffffffff);

      }

      else if (iVar6 == 2) {

        FUN_0039f210(puVar13,puVar1[0x17] * 3 + 8,0xffffffffffffffff,0xffffffffffffffff);

      }

      else if (iVar6 == 1) {

        FUN_0039f210(puVar13,puVar1[0x17] * 3 + 7,0xffffffffffffffff,0xffffffffffffffff);

      }

      else {

        FUN_0019d3f0("mt_evtCustomEvent.c",0xbfe);

      }

    }

    else {

      iVar6 = puVar1[0x18];

      if (iVar6 == 3) {

        FUN_0039f210(puVar13,puVar1[0x17] * 3 + 99,0xffffffffffffffff,0xffffffffffffffff);

      }

      else if (iVar6 == 2) {

        FUN_0039f210(puVar13,puVar1[0x17] * 3 + 0x62,0xffffffffffffffff,0xffffffffffffffff);

      }

      else if (iVar6 == 1) {

        FUN_0039f210(puVar13,puVar1[0x17] * 3 + 0x61,0xffffffffffffffff,0xffffffffffffffff);

      }

      else {

        FUN_0019d3f0("mt_evtCustomEvent.c",0xc0e);

      }

    }

    FUN_003b91c0(1.0f,*(u16 *)(puVar1 + 0x1a),0,*(u16 *)(iVar4 + 0x1e),0,0,0);

    FUN_003b9320(1.0f,*(u16 *)(puVar1 + 0x1a),0,*(u16 *)(iVar4 + 0x20),0,1,0);

    *puVar1 = 0xb;

    break;

  case 0xb:

    lVar9 = FUN_0039f6e0(puVar13);

    if (lVar9 == 1) {

      *puVar1 = 0xc;

    }

    break;

  case 0xc:

    uVar12 = 0;

    iVar6 = puVar1[0x18];

    if (iVar6 == 3) {

      uVar12 = *(u16 *)(iVar4 + 0x1a);

    }

    else if (iVar6 == 2) {

      uVar12 = *(u16 *)(iVar4 + 0x18);

    }

    else if (iVar6 == 1) {

      uVar12 = *(u16 *)(iVar4 + 0x16);

    }

    else if (iVar6 == 0) {

      uVar12 = *(u16 *)(iVar4 + 0x14);

    }

    else {

      FUN_0019d3f0("mt_evtCustomEvent.c",0xc2f);

    }

    FUN_00361050(uVar3,uVar12);

    return 0xffffffff;

  }

  FUN_0039f410(puVar13);

  return 0;

}
#define FUN_0039c440(...) ((u32 (*)(...))FUN_0039c440)(__VA_ARGS__)
#undef FUN_0039cd60
// FUN_0039CD60


void FUN_0039cd60(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  if (*(int *)(iVar1 + 0xc) != 0) {

    FUN_00100ec0(*(int *)(iVar1 + 0xc));

    *(u32 *)(iVar1 + 0xc) = 0;

  }

  FUN_0039ee80(iVar1 + 0x10);

  FUN_00386b70(iVar1,2,0x6c);

  return;

}
#define FUN_0039cd60(...) ((void (*)(...))FUN_0039cd60)(__VA_ARGS__)
#undef FUN_0039cdc0
// FUN_0039CDC0


u32 FUN_0039cdc0(int param_1)
{
  int *state;
  int *work;
  int resourceId;
  u32 fieldHandle;
  u32 areaHandle;
  u32 resourceHandle;
  u32 unitHandle;
  int result;
  u8 pathScratch[4];

  state = *(int **)(param_1 + 0x3c);
  work = state + 4;
  resourceId = state[1];

  switch (state[0]) {
  case 0:
    fieldHandle = FUN_0017d920();
    areaHandle = FUN_0017da40();
    resourceHandle = FUN_00386e10(resourceId);
    unitHandle = FUN_00386e30(resourceId);
    result = FUN_003bda60(fieldHandle,areaHandle,resourceHandle,unitHandle);
    state[0xd] = result;
    if (result == -1) {
      *state = 4;
    }
    else {
      state[3] = FUN_00100d80(DAT_006a1500,1);
      *state = 1;
    }
    break;

  case 1:
    if (FUN_001016b0(state[3]) == 1) {
      result = FUN_001021c0(DAT_006a1520,pathScratch);
      state[0xc] = result;
      FUN_0039ec70(work,result);
      *state = 2;
    }
    break;

  case 2:
    FUN_0039f210(work,state[0xd],-1,-1);
    *state = 3;
    break;

  case 3:
    if (FUN_0039f6e0(work) == 1) {
      *state = 4;
    }
    break;

  case 4:
    return 0xffffffff;
  }

  FUN_0039f410(work);
  return 0;
}
#define FUN_0039cdc0(...) ((u32 (*)(...))FUN_0039cdc0)(__VA_ARGS__)
#undef FUN_0039cfb0
// FUN_0039CFB0


void FUN_0039cfb0(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  if (*(int *)(iVar1 + 0xc) != 0) {

    FUN_00100ec0(*(int *)(iVar1 + 0xc));

    *(u32 *)(iVar1 + 0xc) = 0;

  }

  FUN_0039ee80(iVar1 + 0x10);

  FUN_00386b70(iVar1,2,0x38);

  return;

}
#define FUN_0039cfb0(...) ((void (*)(...))FUN_0039cfb0)(__VA_ARGS__)
#undef FUN_0039d010
// FUN_0039D010


u32 FUN_0039d010(int param_1)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  s8 cVar4;
  int sVar5;
  u16 uVar6;

  piVar1 = *(int **)(param_1 + 0x3c);
  piVar2 = (int *)piVar1[1];
  iVar3 = piVar1[2];
  switch (piVar1[0]) {
  case 0:
    cVar4 = *(s8 *)(iVar3 + 0x14);
    sVar5 = *(s8 *)(iVar3 + 0x18);
    uVar6 = *(u16 *)(iVar3 + 0x16);
    switch (cVar4) {
    case 0:
      break;
    case 1:
    case 2:
    case 3:
      sVar5 = FUN_0016dd40_d010();
      break;
    }
    if (FUN_0016dce0_d010((s16)sVar5) == 0) {
      if ((piVar2[1] & 8) != 0) {
        FUN_0019d3f0(D_006A1200,0xd88);
        return 0xffffffff;
      }
      sVar5 = 0;
    }
    piVar1[3] = FUN_003a2090_d010(param_1,sVar5,cVar4,uVar6);
    piVar1[0] = 1;
    break;
  case 1:
    if (kwlnTaskExists_d010(piVar1[3]) == 0) {
      piVar1[0] = 2;
    }
    break;
  case 2:
    return 0xffffffff;
  }
  return 0;
}
#define FUN_0039d010(...) ((u32 (*)(...))FUN_0039d010)(__VA_ARGS__)
#undef FUN_0039d190
// FUN_0039d190


void FUN_0039d190(int param_1)



{

  FUN_00386b70(*(u32 *)(param_1 + 0x3c),2,0x10);

  return;

}
#define FUN_0039d190(...) ((void (*)(...))FUN_0039d190)(__VA_ARGS__)
#undef FUN_0039d1c0
// FUN_0039D1C0 NONMATCHING


void FUN_0039d1c0(int param_1)



{

  float uStack_28;


  float uStack_24;


  float uStack_20;


  float uStack_1c;


  float uStack_18;


  float uStack_14;


  float uStack_10;


  u32 uStack_c;

  union {
    u32 value;
    u8 bytes[4];
  } uStack_4;

  

  if (0 < *(int *)(param_1 + 0x18)) {

    uStack_4.bytes[3] = (u8)*(int *)(param_1 + 0x18);

    uStack_4.value = (undefined3)DAT_007cd488;

    uStack_10 = 127.0f;

    uStack_c = 183.0f;

    if (*(int *)(param_1 + 0x1c) == 1) {

      uStack_c = 213.0f;

    }

    uStack_18 = 10.0f;

    uStack_14 = 29.0f;

    uStack_20 = 0.4765625f;

    uStack_1c = 0.4296875f;

    uStack_28 = 0.515625f;

    uStack_24 = 0.65625f;

    FUN_00388000_d1c0(5.0,0,&uStack_10,&uStack_18,&uStack_20,&uStack_28,

                 *(u32 *)(param_1 + 0x14),&uStack_4.value,0);

    uStack_10 = 137.0f;

    uStack_18 = 367.0f;

    uStack_14 = 29.0f;

    uStack_20 = 0.51171875f;

    uStack_1c = 0.4296875f;

    uStack_28 = 0.515625f;

    uStack_24 = 0.65625f;

    FUN_00388000_d1c0(5.0,0,&uStack_10,&uStack_18,&uStack_20,&uStack_28,

                 *(u32 *)(param_1 + 0x14),&uStack_4.value,0);

    uStack_10 = 504.0f;

    uStack_18 = 10.0f;

    uStack_14 = 29.0f;

    uStack_20 = 0.5390625f;

    uStack_1c = 0.4296875f;

    uStack_28 = 0.578125f;

    uStack_24 = 0.65625f;

    FUN_00388000_d1c0(5.0,0,&uStack_10,&uStack_18,&uStack_20,&uStack_28,

                 *(u32 *)(param_1 + 0x14),&uStack_4.value,0);

    if (*(int *)(param_1 + 0x1c) == 0) {

      uStack_4.value = 0;

    }

    else {

      uStack_4.value = 0xffdeb6;

    }

    uStack_10 = 215.0f;

    uStack_c = 184.0f;

    uStack_18 = 216.0f;

    uStack_14 = 26.0f;

    uStack_20 = 0.00390625f;

    uStack_1c = 0.0078125f;

    uStack_28 = 0.83203125f;

    uStack_24 = 0.2109375f;

    FUN_00388000_d1c0(4.0,0,&uStack_10,&uStack_18,&uStack_20,&uStack_28,

                 *(u32 *)(param_1 + 0x14),&uStack_4.value,0);

    if (*(int *)(param_1 + 0x1c) == 1) {

      uStack_4.value = 0;

    }

    else {

      uStack_4.value = 0xffdeb6;

    }

    uStack_10 = 184.0f;

    uStack_c = 0x43560000;

    uStack_18 = 159.0f;

    uStack_14 = 26.0f;

    uStack_20 = 0.00390625f;

    uStack_1c = 0x3e600000;

    uStack_28 = 0x3f200000;

    uStack_24 = 0x3ed80000;

    FUN_00388000_d1c0(4.0,0,&uStack_10,&uStack_18,&uStack_20,&uStack_28,

                 *(u32 *)(param_1 + 0x14),&uStack_4.value,0);

    uStack_10 = 0x43aa8000;

    uStack_c = 0x43560000;

    uStack_18 = 0x42ec0000;

    uStack_14 = 26.0f;

    uStack_20 = 0.00390625f;

    uStack_1c = 0.4296875f;

    uStack_28 = 0x3eee0000;

    uStack_24 = 0x3f220000;

    FUN_00388000_d1c0(4.0,0,&uStack_10,&uStack_18,&uStack_20,&uStack_28,

                 *(u32 *)(param_1 + 0x14),&uStack_4.value,0);

  }

  return;

}
#define FUN_0039d1c0(...) ((void (*)(...))FUN_0039d1c0)(__VA_ARGS__)
#undef FUN_0039d550
// FUN_0039D550 NONMATCHING


u32 FUN_0039d550(int param_1)



{

  u32 *puVar1;

  int iVar2;

  u32 uVar3;

  u64 uVar4;

  int lVar5;

  u32 *puVar6;

  int iStack_8;

  u8 auStack_4 [4];

  

  puVar1 = *(u32 **)(param_1 + 0x3c);

  puVar6 = puVar1 + 8;

  switch(*puVar1) {

  case 0:

    if (((*(u32 *)(puVar1[1] + 4) & 8) != 0) && (lVar5 = FUN_00188660(), lVar5 == 0)) {

      FUN_003951a0(0x1413);

      return 0xffffffff;

    }

    uVar3 = FUN_00100d80(0x6a1540,1);

    puVar1[3] = uVar3;

    *puVar1 = 1;

    break;

  case 1:

    lVar5 = FUN_001016b0(puVar1[3]);

    if (lVar5 == 1) {

      uVar4 = FUN_001021c0(0x6a1560,auStack_4);

      FUN_0039ec70(puVar6,uVar4);

      uVar3 = FUN_0010c1a0(0,0x6a1580,0,0,0,0,0,0);

      puVar1[4] = uVar3;

      *puVar1 = 2;

    }

    break;

  case 2:

    uVar3 = FUN_0010c3a0(puVar1[4],&iStack_8,0);

    if (iStack_8 == 1) {

      puVar1[5] = uVar3;

      puVar1[4] = 0;

      puVar1[6] = 0;

      *puVar1 = 3;

    }

    break;

  case 3:

    iVar2 = puVar1[6];

    puVar1[6] = iVar2 + 8;

    if (0xff < iVar2 + 8) {

      puVar1[6] = 0xff;

      *puVar1 = 4;

    }

    break;

  case 4:

    if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e0952 & 0x4000) == 0)) {

      if ((DAT_007e0952 & 0x40) != 0) {

        *puVar1 = 5;

      }

    }

    else {

      puVar1[7] = (u32)(puVar1[7] == 0);

    }

    break;

  case 5:

    if ((int)puVar1[6] < 9) {

      puVar1[6] = 0;

      if (puVar1[7] == 0) {

        FUN_003951a0(0x1413);

      }

      else {

        FUN_00395170(0x1413);

      }

      *puVar1 = 8;

    }

    else {

      puVar1[6] = puVar1[6] + -8;

    }

    break;

  case 6:

    FUN_0039f210(puVar6,0,1,0xffffffffffffffff);

    *puVar1 = 7;

    break;

  case 7:

    lVar5 = FUN_0039f6e0(puVar6);

    if (lVar5 == 1) {

      lVar5 = FUN_0039f800(puVar6);

      if (lVar5 == 0) {

        FUN_003951a0(0x1413);

      }

      else {

        FUN_00395170(0x1413);

      }

      *puVar1 = 8;

    }

    break;

  case 8:

    return 0xffffffff;

  }

  FUN_0039d1c0(puVar1);

  FUN_0039f410(puVar6);

  return 0;

}
#define FUN_0039d550(...) ((u32 (*)(...))FUN_0039d550)(__VA_ARGS__)
#undef FUN_0039d880
// FUN_0039D880


void FUN_0039d880(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  if (*(int *)(iVar1 + 0xc) != 0) {

    FUN_00100ec0(*(int *)(iVar1 + 0xc));

    *(u32 *)(iVar1 + 0xc) = 0;

  }

  FUN_0039ee80(iVar1 + 0x20);

  FUN_00386b70(iVar1,2,0x40);

  return;

}
#define FUN_0039d880(...) ((void (*)(...))FUN_0039d880)(__VA_ARGS__)
#undef FUN_0039d8e0
// FUN_0039D8E0 NONMATCHING


u32 FUN_0039d8e0(int param_1)
{
  u32 *config;
  int *piVar1;
  u8 uVar2;
  short sVar3;
  int iVar4;
  u32 uVar5;
  int lVar6;
  u32 uVar7;
  int *piVar8;
  u8 auStack_4[4];

  piVar1 = *(int **)(param_1 + 0x3c);
  config = (u32 *)piVar1[1];
  piVar8 = piVar1 + 5;
  uVar5 = 0;
  switch (*piVar1) {
  case 0:
    if ((config[1] & 8) != 0) {
      sVar3 = FUN_0016dd40();
      piVar1[3] = (int)sVar3;
      lVar6 = FUN_0016dce0(sVar3);
      if (lVar6 == 0) {
        FUN_0019d3f0("mt_evtCustomEvent.c",0xf23);
      }
      lVar6 = FUN_0016dbc0((short)piVar1[3],piVar1 + 0xd);
      if (lVar6 == 0) {
        return 0xffffffff;
      }
    } else {
      piVar1[3] = 0;
      piVar1[0xd] = 1;
    }
    iVar4 = FUN_00100d80(DAT_006a15a0,1);
    piVar1[4] = iVar4;
    *piVar1 = 1;
    break;
  case 1:
    lVar6 = FUN_001016b0(piVar1[4]);
    if (lVar6 == 1) {
      uVar7 = FUN_001021c0(DAT_006a15c0,auStack_4);
      FUN_0039ec70(piVar8,uVar7);
      *piVar1 = 2;
    }
    break;
  case 2:
    uVar2 = FUN_0016df30_u64((short)piVar1[3]);
    uVar7 = FUN_0030bbb0(uVar2);
    FUN_0039ef30(piVar8,0,uVar7);
    uVar7 = FUN_00173220((u16)piVar1[0xd]);
    FUN_0039ef30(piVar8,1,uVar7);
    FUN_0039f210(piVar8,0,-1,-1);
    *piVar1 = 3;
    break;
  case 3:
    lVar6 = FUN_0039f6e0(piVar8);
    if (lVar6 == 1) {
      *piVar1 = 4;
    }
    break;
  case 4:
    return 0xffffffff;
  }
  FUN_0039f410(piVar8);
  return uVar5;
}
#define FUN_0039d8e0(...) ((u32 (*)(...))FUN_0039d8e0)(__VA_ARGS__)
#undef FUN_0039db00
// FUN_0039DB00


void FUN_0039db00(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  if (*(int *)(iVar1 + 0x10) != 0) {

    FUN_00100ec0(*(int *)(iVar1 + 0x10));

    *(u32 *)(iVar1 + 0x10) = 0;

  }

  FUN_0039ee80(iVar1 + 0x14);

  FUN_00386b70(iVar1,2,0x38);

  return;

}
#define FUN_0039db00(...) ((void (*)(...))FUN_0039db00)(__VA_ARGS__)
#undef FUN_0039db60
// FUN_0039DB60 NONMATCHING


u32 FUN_0039db60(int param_1)
{
  int *piVar1;
  u32 *config;
  int iVar3;
  int lVar5;
  u32 uVar6;
  int *piVar7;
  u8 auStack_4[4];

  piVar1 = *(int **)(param_1 + 0x3c);
  config = (u32 *)piVar1[1];
  piVar7 = piVar1 + 5;
  switch (*piVar1) {
  case 0:
    if ((config[1] & 8) == 0) {
      FUN_0016e920(6);
      FUN_0016dfb0(6);
      FUN_001723a0(6,2,1);
    }
    piVar1[3] = (short)FUN_0016dd40();
    lVar5 = FUN_00172660();
    if (lVar5 == 0) {
      return 0xffffffff;
    }
    iVar3 = FUN_00100d80(DAT_006a15e0,1);
    piVar1[4] = iVar3;
    *piVar1 = 1;
    break;
  case 1:
    lVar5 = FUN_001016b0(piVar1[4]);
    if (lVar5 == 1) {
      uVar6 = FUN_001021c0(DAT_006a1600,auStack_4);
      FUN_0039ec70(piVar7,uVar6);
      *piVar1 = 2;
    }
    break;
  case 2:
    FUN_0039f210(piVar7,0,-1,-1);
    *piVar1 = 3;
    break;
  case 3:
    lVar5 = FUN_0039f6e0(piVar7);
    if (lVar5 == 1) {
      *piVar1 = 4;
    }
    break;
  case 4:
    return 0xffffffff;
  }
  FUN_0039f410(piVar7);
  return 0;
}
#define FUN_0039db60(...) ((u32 (*)(...))FUN_0039db60)(__VA_ARGS__)
#undef FUN_0039dd30
// FUN_0039DD30


void FUN_0039dd30(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  if (*(int *)(iVar1 + 0x10) != 0) {

    FUN_00100ec0(*(int *)(iVar1 + 0x10));

    *(u32 *)(iVar1 + 0x10) = 0;

  }

  FUN_0039ee80(iVar1 + 0x14);

  FUN_00386b70(iVar1,2,0x34);

  return;

}
#define FUN_0039dd30(...) ((void (*)(...))FUN_0039dd30)(__VA_ARGS__)
#undef FUN_0039dd90
// FUN_0039DD90 NONMATCHING


u32 FUN_0039dd90(int param_1)



{

  u16 uVar1;

  u32 *puVar2;
  u32 *config;

  u8 *puVar3;

  char cVar4;

  short sVar5;

  u32 uVar6;

  u32 uVar7;

  int lVar8;

  int iVar9;

  u32 *puVar10;

  u16 auStack_20 [12];

  int iStack_8;

  u8 auStack_4 [4];

  

  puVar2 = *(u32 **)(param_1 + 0x3c);
  config = (u32 *)puVar2[1];

  puVar10 = puVar2 + 5;

  switch(*puVar2) {

  case 0:

    if ((config[1] & 8) == 0) {

      FUN_0016e920(6);

      FUN_0016dfb0(6);

    }

    sVar5 = FUN_0016dd40();

    puVar2[3] = (int)sVar5;

    puVar2[0xe] = 0;

    uVar6 = FUN_003bee80(puVar2[3],puVar2 + 0xd);

    puVar2[0xf] = uVar6;

    if ((int)puVar2[0xd] < 1) {

      return 0xffffffff;

    }

    uVar6 = FUN_00100d80(DAT_006a1620,1);

    puVar2[4] = uVar6;

    *puVar2 = 1;

    break;

  case 1:

    lVar8 = FUN_001016b0(puVar2[4]);

    if (lVar8 == 1) {

      uVar7 = FUN_001021c0(DAT_006a1640,auStack_4);

      FUN_0039ec70(puVar10,uVar7);

      uVar7 = FUN_001021c0(DAT_006a1400,auStack_4);

      FUN_003c94e0(uVar7);

      puVar2[0x10] = 1;

      *puVar2 = 2;

    }

    break;

  case 2:

    if ((int)puVar2[0xe] >= (int)puVar2[0xd]) {

      *puVar2 = 4;

    }

    else {

      uVar1 = *(u16 *)(puVar2[0xf] + puVar2[0xe] * 2);

      FUN_003c7c20(0,*(u8 *)((u32)uVar1 * 0xe + DAT_007ce420 + 3),0);

      uVar7 = FUN_00173220(uVar1);

      FUN_003c7bc0(1,uVar7);

      for (iVar9 = 0; iVar9 < 3; iVar9 = iVar9 + 1) {

        uVar7 = FUN_003c43f0();

        FUN_003c7bc0(iVar9 + 2,uVar7);

      }

      FUN_00176fb0(uVar1,auStack_20,&iStack_8);

      for (iVar9 = 0; iVar9 < iStack_8; iVar9 = iVar9 + 1) {

        uVar7 = FUN_0030bb40(auStack_20[iVar9]);

        FUN_003c7bc0(iVar9 + 2,uVar7);

      }

      FUN_005225a8(DAT_006a1420,uVar1);

      FUN_003c9790(0);

      *puVar2 = 3;

    }

    break;

  case 3:

    lVar8 = FUN_003c7850();

    if (lVar8 == 0) {

      FUN_003c7700();

      puVar2[0xe] = puVar2[0xe] + 1;

      *puVar2 = 2;

    }

    FUN_003c7b90();

    break;

  case 4:

    cVar4 = FUN_0016dba0(*(u16 *)(puVar2 + 3));

    puVar3 = PTR_s_It_seems_further_power_lies_hi_007cd6f4;

    if (cVar4 == '\n') {

      puVar3 = PTR_s_No_further_power_is_available__007cd6f0;

    }

    FUN_0039ef30(puVar10,5,puVar3);

    FUN_0039f210(puVar10,0,-1,-1);

    *puVar2 = 5;

    break;

  case 5:

    lVar8 = FUN_0039f6e0(puVar10);

    if (lVar8 == 1) {

      *puVar2 = 6;

    }

    break;

  case 6:

    return 0xffffffff;

  }

  FUN_0039f410(puVar10);

  return 0;

}
#define FUN_0039dd90(...) ((u32 (*)(...))FUN_0039dd90)(__VA_ARGS__)
#undef FUN_0039e130
// FUN_0039E130


void FUN_0039e130(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  if (*(int *)(iVar1 + 0x40) != 0) {

    FUN_003c77a0();

    *(u32 *)(iVar1 + 0x40) = 0;

  }

  if (*(int *)(iVar1 + 0x10) != 0) {

    FUN_00100ec0(*(int *)(iVar1 + 0x10));

    *(u32 *)(iVar1 + 0x10) = 0;

  }

  FUN_0039ee80(iVar1 + 0x14);

  FUN_00386b70(iVar1,2,0x44);

  return;

}
#define FUN_0039e130(...) ((void (*)(...))FUN_0039e130)(__VA_ARGS__)
#undef FUN_0039e1b0
// FUN_0039E1B0 NONMATCHING


u32 FUN_0039e1b0(int param_1,int param_2)



{

  u16 uVar1;

  int iVar2;

  u32 uVar3;

  u32 uVar4;

  

  if (*(int *)(param_1 + 0x938) != 0) {

    FUN_00195020();

    *(u32 *)(param_1 + 0x938) = 0;

  }

  switch(*(s8 *)(param_2 + 0x10)) {

  case 0:

    uVar4 = FUN_00386ae0(0x9c,2);

    iVar2 = (int)uVar4;

    *(int *)(iVar2 + 0x48) = param_1;

    *(int *)(iVar2 + 0x4c) = param_2;

    *(u16 *)(iVar2 + 0x94) = 0;

    uVar3 = FUN_00194b20(*(u32 *)(param_1 + 0x92c),0x6a1660,0x10,0x398530,0x399830,uVar4);

    *(u32 *)(param_1 + 0x938) = uVar3;
    break;

  case 1:

    uVar4 = FUN_00386ae0(0x3c,2);

    *(int *)((int)uVar4 + 4) = param_1;

    *(int *)((int)uVar4 + 8) = param_2;

    uVar3 = FUN_00194b20(*(u32 *)(param_1 + 0x92c),0x6a1680,0x10,0x3998b0,0x399be0,uVar4);

    *(u32 *)(param_1 + 0x938) = uVar3;

    break;

  case 2:

    uVar4 = FUN_00386ae0(0x5c,2);

    *(int *)((int)uVar4 + 4) = param_1;

    *(int *)((int)uVar4 + 8) = param_2;

    uVar3 = FUN_00194b20(*(u32 *)(param_1 + 0x92c),0x6a16a0,0x10,0x399c40,0x39a560,uVar4);

    *(u32 *)(param_1 + 0x938) = uVar3;

    break;

  case 3:

    uVar4 = FUN_00386ae0(0x38,2);

    *(int *)((int)uVar4 + 4) = param_1;

    *(int *)((int)uVar4 + 8) = param_2;

    uVar3 = FUN_00194b20(*(u32 *)(param_1 + 0x92c),0x6a16c0,0x10,0x39a5c0,0x39a840,uVar4);

    *(u32 *)(param_1 + 0x938) = uVar3;

    break;

  case 4:

    uVar1 = *(u16 *)(param_2 + 0x14);

    uVar3 = *(u32 *)(param_1 + 0x92c);

    uVar4 = (*DAT_00960178_abs)(0x8dc,0x40000);

    FUN_00521408(uVar4,0,0x8dc);

    *(u16 *)((int)uVar4 + 4) = uVar1;

    uVar3 = FUN_00194b20(uVar3,0x6a1430,0x10,0x39a8a0,0x39b830,uVar4);

    *(u32 *)(param_1 + 0x938) = uVar3;

    break;

  case 5:

    uVar4 = FUN_00386ae0(0x6c,2);

    *(int *)((int)uVar4 + 4) = param_1;

    *(int *)((int)uVar4 + 8) = param_2;

    uVar3 = FUN_00194b20(*(u32 *)(param_1 + 0x92c),0x6a16e0,0x10,0x39b950,0x39c090,uVar4);

    *(u32 *)(param_1 + 0x938) = uVar3;

    break;

  case 6:

    uVar4 = FUN_00386ae0(0x44,2);

    *(int *)((int)uVar4 + 4) = param_1;

    *(int *)((int)uVar4 + 8) = param_2;

    uVar3 = FUN_00194b20(*(u32 *)(param_1 + 0x92c),0x6a1700,0x10,0x39c0f0,0x39c3e0,uVar4);

    *(u32 *)(param_1 + 0x938) = uVar3;

    break;

  case 7:

    uVar4 = FUN_00386ae0(0x6c,2);

    *(int *)((int)uVar4 + 4) = param_1;

    *(int *)((int)uVar4 + 8) = param_2;

    uVar3 = FUN_00194b20(*(u32 *)(param_1 + 0x92c),0x6a1720,0x10,0x39c440,0x39cd60,uVar4);

    *(u32 *)(param_1 + 0x938) = uVar3;

    break;

  case 8:

    uVar4 = FUN_00386ae0(0x38,2);

    *(int *)((int)uVar4 + 4) = param_1;

    *(int *)((int)uVar4 + 8) = param_2;

    uVar3 = FUN_00194b20(*(u32 *)(param_1 + 0x92c),0x6a1740,0x10,0x39cdc0,0x39cfb0,uVar4);

    *(u32 *)(param_1 + 0x938) = uVar3;

    break;

  case 9:

    uVar4 = FUN_00386ae0(0x10,2);

    *(int *)((int)uVar4 + 4) = param_1;

    *(int *)((int)uVar4 + 8) = param_2;

    uVar3 = FUN_00194b20(*(u32 *)(param_1 + 0x92c),0x6a1760,0x10,0x39d010,0x39d190,uVar4);

    *(u32 *)(param_1 + 0x938) = uVar3;

    break;

  case 10:

    uVar4 = FUN_00386ae0(0x40,2);

    *(int *)((int)uVar4 + 4) = param_1;

    *(int *)((int)uVar4 + 8) = param_2;

    uVar3 = FUN_00194b20(*(u32 *)(param_1 + 0x92c),0x6a1780,0x18c0,0x39d550,0x39d880,uVar4);

    *(u32 *)(param_1 + 0x938) = uVar3;

    break;

  case 0xb:

    uVar4 = FUN_00386ae0(0x38,2);

    *(int *)((int)uVar4 + 4) = param_1;

    *(int *)((int)uVar4 + 8) = param_2;

    uVar3 = FUN_00194b20(*(u32 *)(param_1 + 0x92c),0x6a17a0,0x10,0x39d8e0,0x39db00,uVar4);

    *(u32 *)(param_1 + 0x938) = uVar3;

    break;

  case 0xc:

    uVar4 = FUN_00386ae0(0x34,2);

    *(int *)((int)uVar4 + 4) = param_1;

    *(int *)((int)uVar4 + 8) = param_2;

    uVar3 = FUN_00194b20(*(u32 *)(param_1 + 0x92c),0x6a17c0,0x10,0x39db60,0x39dd30,uVar4);

    *(u32 *)(param_1 + 0x938) = uVar3;

    break;

  case 0xd:

    uVar4 = FUN_00386ae0(0x44,2);

    *(int *)((int)uVar4 + 4) = param_1;

    *(int *)((int)uVar4 + 8) = param_2;

    uVar3 = FUN_00194b20(*(u32 *)(param_1 + 0x92c),0x6a17e0,0x10,0x39dd90,0x39e130,uVar4);

    *(u32 *)(param_1 + 0x938) = uVar3;

  }

  if (*(int *)(param_1 + 0x938) == 0) {

    FUN_0019d3f0("mt_evtCustomEvent.c",0x11b8);

  }

  *(u32 *)(param_1 + 4) = *(u32 *)(param_1 + 4) | 0x20000;

  return 1;

}
#define FUN_0039e1b0(...) ((u32 (*)(...))FUN_0039e1b0)(__VA_ARGS__)
#undef FUN_0039e6f0
// FUN_0039e6f0


u32 FUN_0039e6f0(void)



{

  return DAT_007ce618;

}
#define FUN_0039e6f0(...) ((u32 (*)(...))FUN_0039e6f0)(__VA_ARGS__)
#undef FUN_0039e700
// FUN_0039E700 NONMATCHING


void FUN_0039e700(u8 *param_1)



{
  extern u8 DAT_006a1800[];


  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  u32 uVar5;

  int iVar6;

  int iVar7;


  

  *(u32 *)(param_1 + 0x78c) = 0;

  iVar1 = *(int *)(param_1 + 8);



  for (iVar7 = 0; iVar7 < *(int *)(iVar1 + 0x38); iVar7 = iVar7 + 1) {

    iVar6 = *(int *)(iVar1 + 0x34) + iVar7 * 0x20;

    if (*(int *)(iVar6 + 0x18) == 1) {

      iVar2 = *(int *)(param_1 + 0x78c);

      if (9 < iVar2) break;

      iVar3 = *(int *)(iVar1 + 0x10);

      iVar4 = *(int *)(iVar6 + 0x10);
      iVar3 = iVar3 + iVar4;

      uVar5 = *(u32 *)(iVar6 + 0x14);

      *(short *)(param_1 + iVar2 * 2 + 0x7b8) = iVar2 + 30000;

      iVar6 = (int)param_1 + iVar2 * 4;

      *(int *)(iVar6 + 0x790) = iVar3;

      *(u32 *)(iVar6 + 0x7cc) = uVar5;

      *(int *)(param_1 + 0x78c) = *(int *)(param_1 + 0x78c) + 1;

    }

  }

  FUN_005225a8((u32)DAT_006a1800,*(u32 *)(param_1 + 0x78c));

  return;

}
#define FUN_0039e700(...) ((void (*)(...))FUN_0039e700)(__VA_ARGS__)
#undef FUN_0039e7c0
#undef FUN_0039e820
// FUN_0039E7C0


void FUN_0039e7c0(void)



{

  int iVar1;

  

  for (iVar1 = FUN_003b5d50(3); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xf8)) {

    FUN_0039e820(*(int *)(iVar1 + 0x128));

  }

  return;

}
#define FUN_0039e7c0(...) ((void (*)(...))FUN_0039e7c0)(__VA_ARGS__)
#undef FUN_0039e820
// FUN_0039E820


void FUN_0039e820(u64 param_1)



{

  int iVar1;

  

  for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {

    FUN_0039ea20_e820(param_1,iVar1);

  }

  return;

}
#define FUN_0039e820(...) ((void (*)(...))FUN_0039e820)(__VA_ARGS__)
#undef FUN_0039e880
// FUN_0039E880 NONMATCHING


u32 FUN_0039e880(int param_1,int param_2,int param_3,int param_4,int param_5)



{

  int bVar1;

  u32 uVar2;

  int lVar3;

  int iVar4;

  u16 *puVar5;

  u8 auStack_40 [64];

  

  if (param_4 >= *(int *)(param_1 + 0x78c)) {

    uVar2 = 0;

  }

  else {

    if (param_3 >= 3) {

      uVar2 = 0;

    }

    else {

      bVar1 = 0;

      iVar4 = (int)param_3 * 0xc + (int)param_2;

      if (((*(u8 *)(iVar4 + 0x3b4) & 1) != 0) && (*(int *)(iVar4 + 0x3b8) != 0)) {

        bVar1 = 1;

      }

      if (bVar1 == 1) {

        FUN_003196f0(param_2,param_3 & 0xffff);

      }

      lVar3 = FUN_00318d10(param_2,param_5,auStack_40);

      if (lVar3 == 0) {

        uVar2 = 0;

      }

      else {

        iVar4 = param_4 * 2 + param_1;

        puVar5 = (u16 *)(iVar4 + 0x7b8);

        lVar3 = FUN_00316910(5,*(u16 *)(iVar4 + 0x7b8),0);

        if (lVar3 == 0) {
          iVar4 = param_4 * 4 + param_1;
          FUN_00319390(param_2,param_3 & 0xffff,5,*puVar5,*(u32 *)(iVar4 + 0x790),
                       *(u32 *)(iVar4 + 0x7cc),1);
        }
        else {
          FUN_00319490(param_2,param_3 & 0xffff,5,*puVar5,0);
        }

        FUN_003196d0(param_2,param_3 & 0xffff,param_5);

        uVar2 = 1;

      }

    }

  }

  return uVar2;

}
#define FUN_0039e880(...) ((u32 (*)(...))FUN_0039e880)(__VA_ARGS__)
#undef FUN_0039ea20
// FUN_0039EA20


void FUN_0039ea20(int param_1,int param_2)



{

  int iVar1;

  int bVar2;

  

  if ((param_2 < 3) && (param_2 >= 0) && (param_1 != 0)) {
    bVar2 = 0;

    iVar1 = (int)param_2 * 0xc;
    iVar1 = iVar1 + param_1;

    if (((*(u8 *)(iVar1 + 0x3b4) & 1) != 0) && (*(int *)(iVar1 + 0x3b8) != 0)) {

      bVar2 = 1;

    }

    if (bVar2 != 1) goto done;
    FUN_003196f0_ea20((int)param_1,param_2 & 0xffff);

  }
done:

  return;

}
#define FUN_0039ea20(...) ((void (*)(...))FUN_0039ea20)(__VA_ARGS__)
#undef FUN_0039eaa0
// FUN_0039EAA0 NONMATCHING


void FUN_0039eaa0(int param_1)
{
  int base;
  int count;
  int baseValue;
  int entryValue;
  int combinedValue;
  int extraValue;
  int index;
  u8 *entry;
  int *output;

  output = (int *)(param_1 + 0x7f4);
  FUN_00521408_b8b0(output,0,0x38);
  base = *(int *)(param_1 + 8);
  for (index = 0; index < *(int *)(base + 0x38); index = index + 1) {
    entry = (u8 *)(*(int *)(base + 0x34) + index * 0x20);
    if (*(int *)(entry + 0x18) == 2) {
      count = *output;
      if (4 < count) {
        break;
      }
      baseValue = *(int *)(base + 0x10);
      entryValue = *(int *)(entry + 0x10);
      combinedValue = baseValue + entryValue;
      extraValue = *(int *)(entry + 0x14);
      *(short *)((int)output + count * 2 + 0x18) = count + 31000;
      output[count + 1] = combinedValue;
      output[count + 9] = extraValue;
      *output = *output + 1;
    }
  }
  FUN_005225a8_eaa0(DAT_006a1820,*output);
  return;
}
#define FUN_0039eaa0(...) ((void (*)(...))FUN_0039eaa0)(__VA_ARGS__)
#undef FUN_0039eb90
// FUN_0039EB90


void FUN_0039eb90(void)



{

  int iVar3;

  u32 uVar1;

  u32 lVar2;

  

  for (iVar3 = 0; iVar3 < 8; iVar3 = iVar3 + 1) {

    uVar1 = iVar3 + 0x38eU & 0x3ff | 0xc00;

    lVar2 = FUN_003b5d10_eb90((u16)uVar1);

    if (lVar2 != 0) {

      FUN_003b7090_eb90((u16)uVar1);

    }

  }

  return;

}
#define FUN_0039eb90(...) ((void (*)(...))FUN_0039eb90)(__VA_ARGS__)
#undef FUN_0039ec10
// FUN_0039EC10


u32 FUN_0039ec10(int param_1,int param_2,u32 *param_3,u32 *param_4)
{
  int offset;
  int halfOffset;

  if ((param_2 >= 5) || (param_2 < 0)) {
    return 0;
  }

  offset = param_2 * 4;
  offset += param_1;
  *param_3 = *(u32 *)(offset + 0x818);

  halfOffset = param_2 * 2;
  halfOffset += param_1;
  *param_4 = *(u16 *)(halfOffset + 0x80c);

  return *(u32 *)(offset + 0x7f8);
}

#define FUN_0039ec10(...) ((u32 (*)(...))FUN_0039ec10)(__VA_ARGS__)
#undef FUN_0039ec60
// FUN_0039ec60


int FUN_0039ec60(int param_1)



{

  return param_1 + 0x38e;

}
#define FUN_0039ec60(...) ((int (*)(...))FUN_0039ec60)(__VA_ARGS__)
