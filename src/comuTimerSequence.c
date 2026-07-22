#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern u32 DAT_007ce670;
extern u32 DAT_007ce674;
extern u32 DAT_007ce678;
extern u8 DAT_0095b750[];
extern code DAT_00960178;
extern code DAT_0096017c;
extern u32 LAB_003c2530;
extern u32 _DAT_007ce678;
extern u32 uGpffffb980;
extern u32 FUN_003bf370(void);
extern u32 FUN_003bf510(void);
extern u64 FUN_003b91c0(float param_1,u16 param_2,u32 param_3,u32 param_4,u32 param_5,u32 param_6,u32 param_7);
extern u64 FUN_003b9320(float param_1,u16 param_2,u32 param_3,u32 param_4,u32 param_5,u32 param_6,u32 param_7);
extern void FUN_0039f210(u32 *param_1,int param_2,int param_3,int param_4);

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
u32 FUN_003bf720(void);
code * FUN_003bf8e0(void);
code * FUN_003bf950(void);
u32 FUN_003bfae0(void);
u32 FUN_003bffa0(u32 *param_1,u32 *param_2,u32 *param_3);
code * FUN_003bfdb0(void);
code * FUN_003bff40(void);
u32 FUN_003c03f0(void);
code * FUN_003c0570(void);
code * FUN_003c07c0(void);
code * FUN_003c09a0(void);
code * FUN_003c0b30(void);
code * FUN_003c0bd0(void);
u32 FUN_003c0c30(void);
code * FUN_003c0d20(void);
u32 FUN_003c0db0(u32 *param_1,u32 *param_2,u32 *param_3);
u32 FUN_003c0f20(void);
u32 FUN_003c1150(void);
code * FUN_003c1300(void);
u32 FUN_003c1340(void);
u8 * FUN_003c1430(void);
code * FUN_003c1440(void);
code * FUN_003c15d0(void);
code * FUN_003c1810(void);
u32 FUN_003c18c0(void);
void FUN_003c1a70(void);
u64 FUN_003c1ab0(u64 param_1,u64 param_2);
u32 FUN_003c1d20(u8 *param_1);
void FUN_003c22f0(int param_1);
void FUN_003c2350(u64 param_1,u16 param_2);
u32 FUN_003c23f0(u32 param_1,u32 param_2,u32 param_3);

/* Region call-cast macros */
#define FUN_003bf720(...) ((u32 (*)(...))FUN_003bf720)(__VA_ARGS__)
#define FUN_003bf8e0(...) ((code * (*)(...))FUN_003bf8e0)(__VA_ARGS__)
#define FUN_003bf950(...) ((code * (*)(...))FUN_003bf950)(__VA_ARGS__)
#define FUN_003bfae0(...) ((u32 (*)(...))FUN_003bfae0)(__VA_ARGS__)
#define FUN_003bfc50(...) ((code * (*)(...))FUN_003bfc50)(__VA_ARGS__)
#define FUN_003bfdb0(...) ((code * (*)(...))FUN_003bfdb0)(__VA_ARGS__)
#define FUN_003bff40(...) ((code * (*)(...))FUN_003bff40)(__VA_ARGS__)
#define FUN_003bffa0(...) ((u64 (*)(...))FUN_003bffa0)(__VA_ARGS__)
#define FUN_003c03f0(...) ((u32 (*)(...))FUN_003c03f0)(__VA_ARGS__)
#define FUN_003c0570(...) ((code * (*)(...))FUN_003c0570)(__VA_ARGS__)
#define FUN_003c07c0(...) ((code * (*)(...))FUN_003c07c0)(__VA_ARGS__)
#define FUN_003c09a0(...) ((code * (*)(...))FUN_003c09a0)(__VA_ARGS__)
#define FUN_003c0b30(...) ((code * (*)(...))FUN_003c0b30)(__VA_ARGS__)
#define FUN_003c0bd0(...) ((code * (*)(...))FUN_003c0bd0)(__VA_ARGS__)
#define FUN_003c0c30(...) ((u32 (*)(...))FUN_003c0c30)(__VA_ARGS__)
#define FUN_003c0d20(...) ((code * (*)(...))FUN_003c0d20)(__VA_ARGS__)
#define FUN_003c0db0(...) ((u32 (*)(...))FUN_003c0db0)(__VA_ARGS__)
#define FUN_003c0f20(...) ((u32 (*)(...))FUN_003c0f20)(__VA_ARGS__)
#define FUN_003c1150(...) ((u32 (*)(...))FUN_003c1150)(__VA_ARGS__)
#define FUN_003c1300(...) ((code * (*)(...))FUN_003c1300)(__VA_ARGS__)
#define FUN_003c1340(...) ((u32 (*)(...))FUN_003c1340)(__VA_ARGS__)
#define FUN_003c1430(...) ((u8 * (*)(...))FUN_003c1430)(__VA_ARGS__)
#define FUN_003c1440(...) ((code * (*)(...))FUN_003c1440)(__VA_ARGS__)
#define FUN_003c15d0(...) ((code * (*)(...))FUN_003c15d0)(__VA_ARGS__)
#define FUN_003c1810(...) ((code * (*)(...))FUN_003c1810)(__VA_ARGS__)
#define FUN_003c18c0(...) ((u32 (*)(...))FUN_003c18c0)(__VA_ARGS__)
#define FUN_003c1a70(...) ((void (*)(...))FUN_003c1a70)(__VA_ARGS__)
#define FUN_003c1ab0(...) ((u64 (*)(...))FUN_003c1ab0)(__VA_ARGS__)
#define FUN_003c1d20(...) ((u32 (*)(...))FUN_003c1d20)(__VA_ARGS__)
#define FUN_003c22f0(...) ((void (*)(...))FUN_003c22f0)(__VA_ARGS__)
#define FUN_003c2350(...) ((void (*)(...))FUN_003c2350)(__VA_ARGS__)
#define FUN_003c23f0(...) ((u32 (*)(...))FUN_003c23f0)(__VA_ARGS__)

#undef FUN_003bf720
// FUN_003BF720 NONMATCHING






u32 FUN_003bf720(void)



{

  int iVar1;

  u8 bVar2;

  int *piVar3;

  u32 uVar4;

  long lVar5;

  u8 auStack_20 [12];

  u32 uStack_14;

  u32 uStack_10;

  u32 uStack_c;

  

  piVar3 = (int *)FUN_00195540();

  iVar1 = *piVar3;

  if (iVar1 == 3) {

    lVar5 = FUN_0038d6f0(0);

    if (lVar5 == 0) {

      lVar5 = FUN_003c30b0();

      if (lVar5 == 0) {

        FUN_0019d3f0("comuTimerSequence.c",0x1a9);

      }

      uVar4 = 0xffffffff;

    }

    else {

      uVar4 = 0xffffffff;

    }

  }

  else {

    if (iVar1 == 2) {

      lVar5 = FUN_0027c2b0();

      if ((lVar5 == 0) && (lVar5 = FUN_0027c330(), lVar5 == -1)) {

        bVar2 = 1;

      }

      else {

        bVar2 = 0;

      }

      if (bVar2) {

        *piVar3 = 3;

      }

    }

    else if (iVar1 == 1) {

      if (piVar3[1] < piVar3[2]) {

        piVar3[1] = piVar3[1] + 1;

      }

      else {

        piVar3[1] = 0;

        piVar3[2] = 0;

        FUN_0016e920(DAT_007ce678);

        uVar4 = _DAT_007ce678;

        FUN_00521408(auStack_20,0,0x1c);

        uStack_14 = 0x329;

        uStack_10 = 1;

        uStack_c = uVar4;

        FUN_0027c080(3,auStack_20,0x1c,0);

        *piVar3 = 2;

      }

    }

    else if (iVar1 == 0) {

      piVar3[1] = 0;

      piVar3[2] = 2;

      *piVar3 = 1;

    }

    uVar4 = 0;

  }

  return uVar4;

}
#define FUN_003bf720(...) ((u32 (*)(...))FUN_003bf720)(__VA_ARGS__)
#undef FUN_003bf8e0
// FUN_003BF8E0 NONMATCHING


code * FUN_003bf8e0(void)



{

  u32 *puVar1;

  code *pcVar2;

  int lVar3;

  

  puVar1 = (u32 *)FUN_00195540();

  lVar3 = FUN_003c3190((u32)&DAT_007ce678);

  if (lVar3 == 1) {

    *puVar1 = 0;

    puVar1[1] = 0;

    puVar1[2] = 0;

    puVar1[3] = 0;

    puVar1[4] = 0;

    puVar1[5] = 0;

    pcVar2 = (code *)&FUN_003bf720;

  }

  else {

    pcVar2 = (code *)0xffffffff;

  }

  return pcVar2;

}
#define FUN_003bf8e0(...) ((code * (*)(...))FUN_003bf8e0)(__VA_ARGS__)
#undef FUN_003bf950
// FUN_003BF950 NONMATCHING


code * FUN_003bf950(void)



{

  int iVar1;

  u8 bVar2;

  int *piVar3;

  code *pcVar4;

  long lVar5;

  u8 auStack_20 [12];

  u32 uStack_14;

  u32 uStack_10;

  u32 uStack_c;

  

  piVar3 = (int *)FUN_00195540();

  FUN_001717b0();

  iVar1 = *piVar3;

  if (iVar1 == 3) {

    *piVar3 = 0;

    piVar3[1] = 0;

    piVar3[2] = 0;

    piVar3[3] = 0;

    piVar3[4] = 0;

    piVar3[5] = 0;

    pcVar4 = (code *)&FUN_003bf8e0;

  }

  else {

    if (iVar1 == 2) {

      lVar5 = FUN_0027c2b0();

      if ((lVar5 == 0) && (lVar5 = FUN_0027c330(), lVar5 == -1)) {

        bVar2 = 1;

      }

      else {

        bVar2 = 0;

      }

      if (bVar2) {

        *piVar3 = 3;

      }

    }

    else if (iVar1 == 1) {

      if (piVar3[1] < piVar3[2]) {

        piVar3[1] = piVar3[1] + 1;

      }

      else {

        piVar3[1] = 0;

        piVar3[2] = 0;

        FUN_00521408(auStack_20,0,0x1c);

        uStack_14 = 0x32b;

        uStack_10 = 1;

        uStack_c = 0;

        FUN_0027c080(3,auStack_20,0x1c,0);

        *piVar3 = 2;

      }

    }

    else if (iVar1 == 0) {

      piVar3[1] = 0;

      piVar3[2] = 2;

      *piVar3 = 1;

    }

    pcVar4 = (code *)0x0;

  }

  return pcVar4;

}
#define FUN_003bf950(...) ((code * (*)(...))FUN_003bf950)(__VA_ARGS__)
#undef FUN_003bfae0
// FUN_003BFAE0 NONMATCHING


u32 FUN_003bfae0(void)



{

  int iVar1;

  u8 bVar2;

  int *piVar3;

  u32 uVar4;

  long lVar5;

  u8 auStack_20 [12];

  u32 uStack_14;

  u32 uStack_10;

  u32 uStack_c;

  

  piVar3 = (int *)FUN_00195540();

  FUN_001717b0();

  iVar1 = *piVar3;

  if (iVar1 == 3) {

    uVar4 = 0xffffffff;

  }

  else {

    if (iVar1 == 2) {

      lVar5 = FUN_0027c2b0();

      if ((lVar5 == 0) && (lVar5 = FUN_0027c330(), lVar5 == -1)) {

        bVar2 = 1;

      }

      else {

        bVar2 = 0;

      }

      if (bVar2) {

        *piVar3 = 3;

      }

    }

    else if (iVar1 == 1) {

      if (piVar3[1] < piVar3[2]) {

        piVar3[1] = piVar3[1] + 1;

      }

      else {

        piVar3[1] = 0;

        piVar3[2] = 0;

        FUN_00521408(auStack_20,0,0x1c);

        uStack_14 = 0x328;

        uStack_10 = 1;

        uStack_c = 0;

        FUN_0027c080(3,auStack_20,0x1c,0);

        *piVar3 = 2;

      }

    }

    else if (iVar1 == 0) {

      piVar3[1] = 0;

      piVar3[2] = 2;

      *piVar3 = 1;

    }

    uVar4 = 0;

  }

  return uVar4;

}
#define FUN_003bfae0(...) ((u32 (*)(...))FUN_003bfae0)(__VA_ARGS__)
#undef FUN_003bfc50
// FUN_003BFC50 NONMATCHING


code * FUN_003bfc50(void)



{

  int iVar1;

  u8 bVar2;

  u32 uVar3;

  int *piVar4;

  code *pcVar5;

  long lVar6;

  u8 auStack_20 [12];

  u32 uStack_14;

  u32 uStack_10;

  u32 uStack_c;

  

  piVar4 = (int *)FUN_00195540();

  uVar3 = DAT_007ce674;

  iVar1 = *piVar4;

  if (iVar1 == 3) {

    *piVar4 = 0;

    piVar4[1] = 0;

    piVar4[2] = 0;

    piVar4[3] = 0;

    piVar4[4] = 0;

    piVar4[5] = 0;

    pcVar5 = (code *)&FUN_003bf950;

  }

  else {

    if (iVar1 == 2) {

      lVar6 = FUN_0027c2b0();

      if ((lVar6 == 0) && (lVar6 = FUN_0027c330(), lVar6 == -1)) {

        bVar2 = 1;

      }

      else {

        bVar2 = 0;

      }

      if (bVar2) {

        FUN_00172b20();

        *piVar4 = 3;

      }

    }

    else if (iVar1 == 1) {

      FUN_00521408(auStack_20,0,0x1c);

      uStack_14 = 0x32a;

      uStack_10 = 1;

      uStack_c = uVar3;

      FUN_0027c080(3,auStack_20,0x1c,0);

      *piVar4 = 2;

    }

    else if (iVar1 == 0) {

      piVar4[1] = 0;

      piVar4[2] = 2;

      *piVar4 = 1;

    }

    pcVar5 = (code *)0x0;

  }

  return pcVar5;

}
#define FUN_003bfc50(...) ((code * (*)(...))FUN_003bfc50)(__VA_ARGS__)
#undef FUN_003bfdb0
// FUN_003BFDB0 NONMATCHING


code * FUN_003bfdb0(void)



{

  char cVar1;

  u32 *puVar2;

  code *pcVar3;

  long lVar4;

  short sStack_2;

  

  puVar2 = (u32 *)FUN_00195540();

  lVar4 = FUN_00172c50(&sStack_2);

  if (lVar4 == 0) {

    *puVar2 = 0;

    puVar2[1] = 0;

    puVar2[2] = 0;

    puVar2[3] = 0;

    puVar2[4] = 0;

    puVar2[5] = 0;

    pcVar3 = (code *)&FUN_003bf950;

  }

  else {

    cVar1 = FUN_0016dba0(sStack_2);

    if (cVar1 == '\n') {

      DAT_007ce674 = sStack_2 + 0x1e;

      *puVar2 = 0;

      puVar2[1] = 0;

      puVar2[2] = 0;

      puVar2[3] = 0;

      puVar2[4] = 0;

      puVar2[5] = 0;

      pcVar3 = (code *)&FUN_003bfc50;

    }

    else {

      lVar4 = FUN_001717c0(sStack_2);

      if ((lVar4 == 1) || (lVar4 = FUN_00172160(sStack_2), lVar4 == 1)) {

        DAT_007ce674 = (int)sStack_2;

        *puVar2 = 0;

        puVar2[1] = 0;

        puVar2[2] = 0;

        puVar2[3] = 0;

        puVar2[4] = 0;

        puVar2[5] = 0;

        pcVar3 = (code *)&FUN_003bfc50;

      }

      else {

        lVar4 = FUN_003c3050(sStack_2);

        if (lVar4 == 0) {

          FUN_0019d3f0("comuTimerSequence.c",0x249);

        }

        lVar4 = FUN_003c3120();

        if (lVar4 == 0) {

          FUN_0019d3f0("comuTimerSequence.c",0x24b);

        }

        *puVar2 = 0;

        puVar2[1] = 0;

        puVar2[2] = 0;

        puVar2[3] = 0;

        puVar2[4] = 0;

        puVar2[5] = 0;

        pcVar3 = (code *)&FUN_003bfae0;

      }

    }

  }

  return pcVar3;

}
#define FUN_003bfdb0(...) ((code * (*)(...))FUN_003bfdb0)(__VA_ARGS__)
#undef FUN_003bff40
// FUN_003BFF40


code * FUN_003bff40(void)



{

  u32 *puVar1;

  

  puVar1 = (u32 *)FUN_00195540();

  FUN_003bdde0();

  *puVar1 = 0;

  puVar1[1] = 0;

  puVar1[2] = 0;

  puVar1[3] = 0;

  puVar1[4] = 0;

  puVar1[5] = 0;

  return (code *)&FUN_003bfdb0;

}
#define FUN_003bff40(...) ((code * (*)(...))FUN_003bff40)(__VA_ARGS__)
#undef FUN_003bffa0
// FUN_003BFFA0 NONMATCHING


u32 FUN_003bffa0(u32 *param_1,u32 *param_2,u32 *param_3)



{

  u8 bVar1;

  int iVar2;

  u8 bVar3;

  u8 bVar4;

  u8 bVar5;

  int *piVar6;

  u8 *pbVar7;

  int iVar8;

  u8 *puVar9;

  u32 uVar10;

  u32 uVar11;

  u32 uVar12;

  u32 lVar13;

  u32 uVar14;

  u32 uVar15;

  int iVar16;

  int iVar17;

  u32 unaff_s8_lo;

  int aiStack_30 [12];

  

  piVar6 = (int *)FUN_003bdd40();

  uVar10 = FUN_0017d920();

  uVar11 = FUN_0017da40();

  iVar2 = *piVar6;

  iVar8 = piVar6[1];

  for (iVar16 = 0; bVar5 = 0, iVar16 < iVar8; iVar16 = iVar16 + 1) {

    pbVar7 = (u8 *)(iVar2 + iVar16 * 3);

    uVar15 = (u32)pbVar7[1];

    uVar14 = (u32)*pbVar7;

    if (uVar14 == 0xff) {

      lVar13 = FUN_0017e050(uVar15,uVar10,uVar11);

      bVar3 = 1;

      if (lVar13 != 1) {

        bVar3 = 0;

      }

    }

    else if ((uVar10 == uVar14) && (uVar11 == uVar15)) {

      bVar3 = 1;

    }

    else {

      bVar3 = 0;

    }

    bVar5 = 1;

    if (bVar3) {

      unaff_s8_lo = (u32)*(u8 *)(iVar16 * 3 + iVar2 + 2);

      break;

    }

  }

  uVar12 = 1;

  if (bVar5) {

    *param_1 = 0x322;

    *param_2 = 1;

    *param_3 = unaff_s8_lo;

  }

  else {

    iVar2 = piVar6[2];

    iVar8 = piVar6[3];

    for (iVar16 = 0; bVar3 = bVar5, iVar16 < iVar8; iVar16 = iVar16 + 1) {

      pbVar7 = (u8 *)(iVar2 + iVar16 * 3);

      uVar15 = (u32)pbVar7[1];

      uVar14 = (u32)*pbVar7;

      if (uVar14 == 0xff) {

        lVar13 = FUN_0017e050(uVar15,uVar10,uVar11);

        bVar4 = 1;

        if (lVar13 != 1) {

          bVar4 = 0;

        }

      }

      else if ((uVar10 == uVar14) && (uVar11 == uVar15)) {

        bVar4 = 1;

      }

      else {

        bVar4 = 0;

      }

      bVar3 = 1;

      if (bVar4) {

        unaff_s8_lo = (u32)*(u8 *)(iVar16 * 3 + iVar2 + 2);

        break;

      }

    }

    uVar12 = 1;

    if (bVar3) {

      *param_1 = 0x323;

      *param_2 = 1;

      *param_3 = unaff_s8_lo;

    }

    else {

      iVar2 = piVar6[4];

      iVar8 = piVar6[5];

      iVar17 = 0;

      for (iVar16 = 0; iVar16 < iVar8; iVar16 = iVar16 + 1) {

        puVar9 = (u8 *)(iVar2 + iVar16 * 5);

        lVar13 = FUN_003bf270(uVar10,uVar11,*puVar9,puVar9[1],puVar9[2],puVar9[3]);

        if (lVar13 == 1) {

          aiStack_30[iVar17] = iVar16;

          iVar17 = iVar17 + 1;

        }

        if (9 < iVar17) break;

      }

      if (0 < iVar17) {

        iVar8 = FUN_00395200(iVar17);

        bVar1 = *(u8 *)(aiStack_30[iVar8] * 5 + iVar2 + 4);

        lVar13 = FUN_00395230(0x14);

        if (lVar13 == 1) {

          *param_1 = 0x322;

          *param_2 = 1;

          *param_3 = (u32)bVar1;

          return 1;

        }

      }

      iVar2 = piVar6[6];

      iVar8 = piVar6[7];

      iVar17 = 0;

      for (iVar16 = 0; iVar16 < iVar8; iVar16 = iVar16 + 1) {

        puVar9 = (u8 *)(iVar2 + iVar16 * 5);

        lVar13 = FUN_003bf270(uVar10,uVar11,*puVar9,puVar9[1],puVar9[2],puVar9[3]);

        if (lVar13 == 1) {

          aiStack_30[iVar17] = iVar16;

          iVar17 = iVar17 + 1;

        }

        if (9 < iVar17) break;

      }

      if (0 < iVar17) {

        iVar8 = FUN_00395200(iVar17);

        bVar1 = *(u8 *)(aiStack_30[iVar8] * 5 + iVar2 + 4);

        lVar13 = FUN_00395230(0x14);

        if (lVar13 == 1) {

          *param_1 = 0x323;

          *param_2 = 1;

          *param_3 = (u32)bVar1;

          return 1;

        }

      }

      uVar12 = 0;

    }

  }

  return uVar12;

}
#define FUN_003bffa0(...) ((u64 (*)(...))FUN_003bffa0)(__VA_ARGS__)
#undef FUN_003c03f0
// FUN_003C03F0 NONMATCHING


u32 FUN_003c03f0(void)



{

  int iVar1;

  u8 bVar2;

  int *piVar3;

  u32 uVar4;

  long lVar5;

  u8 auStack_20 [12];

  u32 uStack_14;

  u32 uStack_10;

  u32 uStack_c;

  

  piVar3 = (int *)FUN_00195540();

  iVar1 = *piVar3;

  if (iVar1 == 3) {

    uVar4 = 0xffffffff;

  }

  else {

    if (iVar1 == 2) {

      lVar5 = FUN_0027c2b0();

      if ((lVar5 == 0) && (lVar5 = FUN_0027c330(), lVar5 == -1)) {

        bVar2 = 1;

      }

      else {

        bVar2 = 0;

      }

      if (bVar2) {

        *piVar3 = 3;

      }

    }

    else if (iVar1 == 1) {

      if (piVar3[1] < piVar3[2]) {

        piVar3[1] = piVar3[1] + 1;

      }

      else {

        piVar3[1] = 0;

        piVar3[2] = 0;

        FUN_00521408(auStack_20,0,0x1c);

        uStack_14 = 0x8c;

        uStack_10 = 4;

        uStack_c = 0;

        FUN_0027c080(3,auStack_20,0x1c,0);

        *piVar3 = 2;

      }

    }

    else if (iVar1 == 0) {

      if (DAT_007ce670 == 0) {

        *piVar3 = 3;

      }

      piVar3[1] = 0;

      piVar3[2] = 2;

      *piVar3 = 1;

    }

    uVar4 = 0;

  }

  return uVar4;

}
#define FUN_003c03f0(...) ((u32 (*)(...))FUN_003c03f0)(__VA_ARGS__)
#undef FUN_003c0570
// FUN_003C0570 NONMATCHING


code * FUN_003c0570(void)



{

  int iVar1;

  u8 bVar2;

  int *piVar3;

  code *pcVar4;

  long lVar5;

  long lVar6;

  u8 auStack_40 [12];

  u32 uStack_34;

  u32 uStack_30;

  u32 uStack_2c;

  u8 auStack_20 [12];

  u32 uStack_14;

  u32 uStack_10;

  u32 uStack_c;

  

  piVar3 = (int *)FUN_00195540();

  iVar1 = *piVar3;

  if (iVar1 == 3) {

    *piVar3 = 0;

    piVar3[1] = 0;

    piVar3[2] = 0;

    piVar3[3] = 0;

    piVar3[4] = 0;

    piVar3[5] = 0;

    pcVar4 = (code *)&FUN_003c03f0;

  }

  else {

    if (iVar1 == 2) {

      lVar5 = FUN_0027c2b0();

      if ((lVar5 == 0) && (lVar5 = FUN_0027c330(), lVar5 == -1)) {

        bVar2 = 1;

      }

      else {

        bVar2 = 0;

      }

      if (bVar2) {

        *piVar3 = 3;

      }

    }

    else if (iVar1 == 1) {

      if (piVar3[1] < piVar3[2]) {

        piVar3[1] = piVar3[1] + 1;

      }

      else {

        piVar3[1] = 0;

        piVar3[2] = 0;

        lVar5 = FUN_0017d920();

        lVar6 = FUN_0017da40();

        if ((lVar5 == 4) && (lVar6 == 0x15)) {

          FUN_00395170(0x24);

          DAT_007ce670 = 0;

          FUN_00521408(auStack_20,0,0x1c);

          uStack_14 = 0x8d;

          uStack_10 = 1;

          uStack_c = 0;

          FUN_0027c080(3,auStack_20,0x1c,0);

          *piVar3 = 2;

        }

        else if ((lVar5 == 4) && (lVar6 == 0x1b)) {

          FUN_00395170(0x10a);

          DAT_007ce670 = 0;

          FUN_00521408(auStack_40,0,0x1c);

          uStack_34 = 0x6f;

          uStack_30 = 2;

          uStack_2c = 0;

          FUN_0027c080(3,auStack_40,0x1c,0);

          *piVar3 = 2;

        }

        else {

          *piVar3 = 3;

        }

      }

    }

    else if (iVar1 == 0) {

      piVar3[1] = 0;

      piVar3[2] = 2;

      *piVar3 = 1;

    }

    pcVar4 = (code *)0x0;

  }

  return pcVar4;

}
#define FUN_003c0570(...) ((code * (*)(...))FUN_003c0570)(__VA_ARGS__)
#undef FUN_003c07c0
// FUN_003C07C0 NONMATCHING


code * FUN_003c07c0(void)



{

  int iVar1;

  u8 bVar2;

  int *piVar3;

  code *pcVar4;

  long lVar5;

  u8 auStack_30 [12];

  u32 uStack_24;

  u32 uStack_20;

  u32 uStack_1c;

  u32 uStack_c;

  u32 uStack_8;

  u32 uStack_4;

  

  piVar3 = (int *)FUN_00195540();

  uStack_4 = 0;

  uStack_8 = 0;

  uStack_c = 0;

  iVar1 = *piVar3;

  if (iVar1 == 3) {

    *piVar3 = 0;

    piVar3[1] = 0;

    piVar3[2] = 0;

    piVar3[3] = 0;

    piVar3[4] = 0;

    piVar3[5] = 0;

    pcVar4 = (code *)&FUN_003c0570;

  }

  else {

    if (iVar1 == 2) {

      lVar5 = FUN_0027c2b0();

      if ((lVar5 == 0) && (lVar5 = FUN_0027c330(), lVar5 == -1)) {

        bVar2 = 1;

      }

      else {

        bVar2 = 0;

      }

      if (bVar2) {

        *piVar3 = 3;

      }

    }

    else if (iVar1 == 1) {

      if (piVar3[1] < piVar3[2]) {

        piVar3[1] = piVar3[1] + 1;

      }

      else {

        piVar3[1] = 0;

        piVar3[2] = 0;

        lVar5 = FUN_003bffa0(&uStack_4,&uStack_8,&uStack_c);

        uStack_24 = uStack_4;

        uStack_20 = uStack_8;

        uStack_1c = uStack_c;

        if (lVar5 == 0) {

          *piVar3 = 3;

        }

        else {

          DAT_007ce670 = 0;

          FUN_00521408(auStack_30,0,0x1c);

          FUN_0027c080(3,auStack_30,0x1c,0);

          *piVar3 = 2;

        }

      }

    }

    else if (iVar1 == 0) {

      piVar3[1] = 0;

      piVar3[2] = 2;

      *piVar3 = 1;

    }

    pcVar4 = (code *)0x0;

  }

  return pcVar4;

}
#define FUN_003c07c0(...) ((code * (*)(...))FUN_003c07c0)(__VA_ARGS__)
#undef FUN_003c09a0
// FUN_003C09A0 NONMATCHING


code * FUN_003c09a0(void)



{

  int iVar1;

  u8 bVar2;

  int *piVar3;

  long lVar4;

  u8 auStack_20 [12];

  u32 uStack_14;

  u32 uStack_10;

  u32 uStack_c;

  

  piVar3 = (int *)FUN_00195540();

  iVar1 = *piVar3;

  if (iVar1 == 2) {

    lVar4 = FUN_0027c2b0();

    if ((lVar4 == 0) && (lVar4 = FUN_0027c330(), lVar4 == -1)) {

      bVar2 = 1;

    }

    else {

      bVar2 = 0;

    }

    if (bVar2) {

      lVar4 = FUN_0038d6f0(0);

      if (lVar4 == 0) {

        return (code *)0xffffffff;

      }

      *piVar3 = 0;

      piVar3[1] = 0;

      piVar3[2] = 0;

      piVar3[3] = 0;

      piVar3[4] = 0;

      piVar3[5] = 0;

      return (code *)&FUN_003c07c0;

    }

  }

  else if (iVar1 == 1) {

    if (piVar3[1] < piVar3[2]) {

      piVar3[1] = piVar3[1] + 1;

    }

    else {

      piVar3[1] = 0;

      piVar3[2] = 0;

      uGpffffb980 = 0;

      FUN_00521408(auStack_20,0,0x1c);

      uStack_14 = 0x321;

      uStack_10 = 1;

      uStack_c = 0;

      FUN_0027c080(3,auStack_20,0x1c,0);

      *piVar3 = 2;

    }

  }

  else if (iVar1 == 0) {

    piVar3[1] = 0;

    piVar3[2] = 2;

    *piVar3 = 1;

  }

  return (code *)0x0;

}
#define FUN_003c09a0(...) ((code * (*)(...))FUN_003c09a0)(__VA_ARGS__)
#undef FUN_003c0b30
// FUN_003C0B30 NONMATCHING


code * FUN_003c0b30(void)



{

  u32 *puVar1;

  code *pcVar2;

  int lVar3;

  

  puVar1 = (u32 *)FUN_00195540();

  FUN_0016c920(1);

  lVar3 = FUN_003951d0(0xbde);

  if (lVar3 == 1) {

    *puVar1 = 0;

    puVar1[1] = 0;

    puVar1[2] = 0;

    puVar1[3] = 0;

    puVar1[4] = 0;

    puVar1[5] = 0;

    pcVar2 = (code *)&FUN_003c09a0;

  }

  else {

    *puVar1 = 0;

    puVar1[1] = 0;

    puVar1[2] = 0;

    puVar1[3] = 0;

    puVar1[4] = 0;

    puVar1[5] = 0;

    pcVar2 = (code *)&FUN_003c07c0;

  }

  return pcVar2;

}
#define FUN_003c0b30(...) ((code * (*)(...))FUN_003c0b30)(__VA_ARGS__)
#undef FUN_003c0bd0
// FUN_003C0BD0


code * FUN_003c0bd0(void)



{

  u32 *puVar1;

  

  puVar1 = (u32 *)FUN_00195540();

  FUN_003bdde0();

  uGpffffb980 = 1;

  *puVar1 = 0;

  puVar1[1] = 0;

  puVar1[2] = 0;

  puVar1[3] = 0;

  puVar1[4] = 0;

  puVar1[5] = 0;

  return (code *)&FUN_003c0b30;

}
#define FUN_003c0bd0(...) ((code * (*)(...))FUN_003c0bd0)(__VA_ARGS__)
#undef FUN_003c0c30
// FUN_003C0C30 NONMATCHING


u32 FUN_003c0c30(void)



{

  u8 bVar1;

  int *piVar2;

  long lVar3;

  u16 uStack_20;

  u16 uStack_1e;

  u16 uStack_1c;

  u16 uStack_18;

  

  piVar2 = (int *)FUN_00195540();

  if (*piVar2 == 1) {

    lVar3 = FUN_0027c2b0();

    if ((lVar3 == 0) && (lVar3 = FUN_0027c330(), lVar3 == -1)) {

      bVar1 = 1;

    }

    else {

      bVar1 = 0;

    }

    if (bVar1) {

      return 0xffffffff;

    }

  }

  else if (*piVar2 == 0) {

    FUN_00521408(&uStack_20,0,0x1c);

    uStack_20 = 7;

    uStack_1e = 1;

    uStack_1c = 0;

    uStack_18 = 0;

    FUN_0027c080(2,&uStack_20,0x1c,0);

    *piVar2 = 1;

  }

  return 0;

}
#define FUN_003c0c30(...) ((u32 (*)(...))FUN_003c0c30)(__VA_ARGS__)
#undef FUN_003c0d20
// FUN_003C0D20 NONMATCHING


code * FUN_003c0d20(void)



{

  u32 *puVar1;

  code *pcVar2;

  int lVar3;

  u16 auStack_2;

  

  puVar1 = (u32 *)FUN_00195540();

  lVar3 = FUN_00172c50(&auStack_2);

  if (lVar3 != 0) {

    *puVar1 = 0;

    puVar1[1] = 0;

    puVar1[2] = 0;

    puVar1[3] = 0;

    puVar1[4] = 0;

    puVar1[5] = 0;

    pcVar2 = (code *)&FUN_003c0c30;

  }

  else {

    *puVar1 = 0;

    puVar1[1] = 0;

    puVar1[2] = 0;

    puVar1[3] = 0;

    puVar1[4] = 0;

    puVar1[5] = 0;

    pcVar2 = (code *)&FUN_003bf510;

  }

  return pcVar2;

}
#define FUN_003c0d20(...) ((code * (*)(...))FUN_003c0d20)(__VA_ARGS__)
#undef FUN_003c0db0
// FUN_003C0DB0 NONMATCHING


u32 FUN_003c0db0(u32 *param_1,u32 *param_2,u32 *param_3)



{

  int iVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  u32 uVar5;

  u32 uVar6;

  u8 *pbVar7;

  int iVar8;

  

  iVar3 = FUN_003bd870();

  iVar1 = *(int *)(iVar3 + 0x664);

  uVar5 = FUN_0017d920();

  uVar6 = FUN_0017da40();

  cVar2 = FUN_0016ef30();

  iVar8 = 0;

  do {

    if (iVar1 <= iVar8) {

      return 0;

    }

    iVar4 = iVar8 * 0xc;

    pbVar7 = (u8 *)(*(int *)(iVar3 + 0x660) + iVar4);

    if ((uVar5 == *pbVar7) && (uVar6 == pbVar7[1])) {

      if (*(int *)(pbVar7 + 4) == 0) {

        if (cVar2 == '\x02') {

          *param_1 = (u32)*(u16 *)(pbVar7 + 8);

          *param_2 = (u32)*(u8 *)(iVar4 + *(int *)(iVar3 + 0x660) + 10);

          *param_3 = (u32)*(u8 *)(iVar4 + *(int *)(iVar3 + 0x660) + 0xb);

          return 1;

        }

      }

      else if (cVar2 == '\x04') {

        *param_1 = (u32)*(u16 *)(pbVar7 + 8);

        *param_2 = (u32)*(u8 *)(iVar4 + *(int *)(iVar3 + 0x660) + 10);

        *param_3 = (u32)*(u8 *)(iVar4 + *(int *)(iVar3 + 0x660) + 0xb);

        return 1;

      }

    }

    iVar8 = iVar8 + 1;

  } while( 1 );

}
#define FUN_003c0db0(...) ((u32 (*)(...))FUN_003c0db0)(__VA_ARGS__)
#undef FUN_003c0f20
// FUN_003C0F20 NONMATCHING


u32 FUN_003c0f20(void)



{

  int iVar1;

  u8 bVar2;

  char cVar3;

  int *piVar4;

  u32 uVar5;

  long lVar6;

  u8 auStack_30 [12];

  u32 uStack_24;

  u32 uStack_20;

  u32 uStack_1c;

  u32 uStack_c;

  u32 uStack_8;

  u32 uStack_4;

  

  piVar4 = (int *)FUN_00195540();

  FUN_001717b0();

  FUN_0017d920();

  FUN_0017da40();

  iVar1 = *piVar4;

  if (iVar1 == 3) {

    cVar3 = FUN_0016ef30();

    if (cVar3 == '\x02') {

      FUN_00395170(0x98c);

    }

    uVar5 = 0xffffffff;

  }

  else {

    if (iVar1 == 2) {

      lVar6 = FUN_0027c2b0();

      if ((lVar6 == 0) && (lVar6 = FUN_0027c330(), lVar6 == -1)) {

        bVar2 = 1;

      }

      else {

        bVar2 = 0;

      }

      if (bVar2) {

        *piVar4 = 3;

      }

    }

    else if (iVar1 == 1) {

      if (piVar4[1] < piVar4[2]) {

        piVar4[1] = piVar4[1] + 1;

      }

      else {

        piVar4[1] = 0;

        piVar4[2] = 0;

        lVar6 = FUN_003c0db0(&uStack_4,&uStack_8,&uStack_c);

        if (lVar6 != 1) {

          return 0xffffffff;

        }

        FUN_00521408(auStack_30,0,0x1c);

        uStack_24 = uStack_4;

        uStack_20 = uStack_8;

        uStack_1c = uStack_c;

        FUN_0027c080(3,auStack_30,0x1c,0);

        *piVar4 = 2;

      }

    }

    else if (iVar1 == 0) {

      cVar3 = FUN_0016ef30();

      if ((cVar3 == '\x04') && (lVar6 = FUN_003951d0(0x98c), lVar6 == 1)) {

        return 0xffffffff;

      }

      piVar4[1] = 0;

      piVar4[2] = 2;

      *piVar4 = 1;

    }

    uVar5 = 0;

  }

  return uVar5;

}
#define FUN_003c0f20(...) ((u32 (*)(...))FUN_003c0f20)(__VA_ARGS__)
#undef FUN_003c1150
// FUN_003C1150 NONMATCHING


u32 FUN_003c1150(void)



{

  int iVar1;

  u8 bVar2;

  int *piVar3;

  u32 uVar4;

  long lVar5;

  u8 auStack_20 [12];

  u32 uStack_14;

  u32 uStack_10;

  u32 uStack_c;

  

  piVar3 = (int *)FUN_00195540();

  iVar1 = *piVar3;

  if (iVar1 == 4) {

    uVar4 = 0xffffffff;

  }

  else {

    if (iVar1 == 3) {

      lVar5 = FUN_0027c2b0();

      if ((lVar5 == 0) && (lVar5 = FUN_0027c330(), lVar5 == -1)) {

        bVar2 = 1;

      }

      else {

        bVar2 = 0;

      }

      if (bVar2) {

        *piVar3 = 4;

      }

    }

    else if (iVar1 == 2) {

      FUN_00521408(auStack_20,0,0x1c);

      uStack_14 = 0x32c;

      uStack_10 = 2;

      uStack_c = 0;

      FUN_0027c080(3,auStack_20,0x1c,0);

      *piVar3 = 3;

    }

    else if (iVar1 == 1) {

      if (piVar3[1] < piVar3[2]) {

        piVar3[1] = piVar3[1] + 1;

      }

      else {

        piVar3[1] = 0;

        piVar3[2] = 0;

        lVar5 = FUN_003c2630(0,0,0);

        if (lVar5 != 1) {

          return 0xffffffff;

        }

        *piVar3 = 2;

      }

    }

    else if (iVar1 == 0) {

      piVar3[1] = 0;

      piVar3[2] = 2;

      *piVar3 = 1;

    }

    uVar4 = 0;

  }

  return uVar4;

}
#define FUN_003c1150(...) ((u32 (*)(...))FUN_003c1150)(__VA_ARGS__)
#undef FUN_003c1300
// FUN_003C1300


code * FUN_003c1300(void)



{

  u32 *puVar1;

  

  puVar1 = (u32 *)FUN_00195540();

  *puVar1 = 0;

  puVar1[1] = 0;

  puVar1[2] = 0;

  puVar1[3] = 0;

  puVar1[4] = 0;

  puVar1[5] = 0;

  return (code *)&FUN_003c1150;

}
#define FUN_003c1300(...) ((code * (*)(...))FUN_003c1300)(__VA_ARGS__)
#undef FUN_003c1340
// FUN_003C1340 NONMATCHING


u32 FUN_003c1340(void)



{

  u8 bVar1;

  int *piVar2;

  int lVar3;

  u16 uStack_20;

  u16 uStack_1e;

  u16 uStack_1c;

  u16 uStack_18;

  

  piVar2 = (int *)FUN_00195540();

  if (*piVar2 == 1) {

    lVar3 = FUN_0027c2b0();

    if ((lVar3 == 0) && (lVar3 = FUN_0027c330(), lVar3 == -1)) {

      bVar1 = 1;

    }

    else {

      bVar1 = 0;

    }

    if (bVar1) {

      return 0xffffffff;

    }

  }

  else if (*piVar2 == 0) {

    FUN_00521408(&uStack_20,0,0x1c);

    uStack_20 = 6;

    uStack_1e = 3;

    uStack_1c = 2;

    uStack_18 = 0;

    FUN_0027c080(2,&uStack_20,0x1c,0);

    *piVar2 = 1;

  }

  return 0;

}
#define FUN_003c1340(...) ((u32 (*)(...))FUN_003c1340)(__VA_ARGS__)
#undef FUN_003c1430
// FUN_003C1430


u8 * FUN_003c1430(void)



{

  return DAT_0095b750;

}
#define FUN_003c1430(...) ((u8 * (*)(...))FUN_003c1430)(__VA_ARGS__)
#undef FUN_003c1440
// FUN_003C1440 NONMATCHING


code * FUN_003c1440(void)



{

  int iVar1;

  u8 bVar2;

  int *piVar3;

  long lVar4;

  

  piVar3 = (int *)FUN_00195540();

  iVar1 = *piVar3;

  if (iVar1 == 2) {

    lVar4 = FUN_0027c2b0();

    if ((lVar4 == 0) && (lVar4 = FUN_0027c330(), lVar4 == -1)) {

      bVar2 = 1;

    }

    else {

      bVar2 = 0;

    }

    if (bVar2) {

      lVar4 = FUN_0038d6f0(0);

      if (lVar4 == 0) {

        FUN_001728d0(0x95b750);

        *piVar3 = 0;

        piVar3[1] = 0;

        piVar3[2] = 0;

        piVar3[3] = 0;

        piVar3[4] = 0;

        piVar3[5] = 0;

        return (code *)&FUN_003bf370;

      }

      *piVar3 = 0;

      piVar3[1] = 0;

      piVar3[2] = 0;

      piVar3[3] = 0;

      piVar3[4] = 0;

      piVar3[5] = 0;

      return (code *)&FUN_003c1340;

    }

  }

  else if (iVar1 == 1) {

    if (piVar3[2] <= piVar3[1]) {

      piVar3[1] = 0;

      piVar3[2] = 0;

      *piVar3 = 0;

      piVar3[1] = 0;

      piVar3[2] = 0;

      piVar3[3] = 0;

      piVar3[4] = 0;

      piVar3[5] = 0;

      return (code *)&FUN_003c1340;

    }

    piVar3[1] = piVar3[1] + 1;

  }

  else if (iVar1 == 0) {

    piVar3[1] = 0;

    piVar3[2] = 2;

    *piVar3 = 1;

  }

  return (code *)0x0;

}
#define FUN_003c1440(...) ((code * (*)(...))FUN_003c1440)(__VA_ARGS__)
#undef FUN_003c15d0
// FUN_003C15D0 NONMATCHING


code * FUN_003c15d0(void)



{

  u8 bVar1;

  int iVar2;

  int iVar3;

  u8 bVar4;

  int *piVar5;

  int iVar6;

  code *pcVar7;

  long lVar8;

  int *piVar9;

  int *piVar10;

  u8 auStack_40 [12];

  u32 uStack_34;

  u32 uStack_30;

  u32 uStack_2c;

  u8 auStack_20 [12];

  u32 uStack_14;

  u32 uStack_10;

  u32 uStack_c;

  

  piVar5 = (int *)FUN_00195540();

  iVar6 = FUN_001717b0();

  piVar10 = (int *)(iVar6 + 0x1e4);

  piVar9 = piVar5 + 8;

  iVar6 = 7;

  do {

    iVar2 = *piVar10;

    iVar3 = piVar10[1];

    piVar10 = piVar10 + 2;

    iVar6 = iVar6 + -1;

    *piVar9 = iVar2;

    piVar9[1] = iVar3;

    piVar9 = piVar9 + 2;

  } while (0 < iVar6);

  bVar1 = *(u8 *)(piVar5 + 8);

  iVar6 = *piVar5;

  if (iVar6 == 3) {

    *piVar5 = 0;

    piVar5[1] = 0;

    piVar5[2] = 0;

    piVar5[3] = 0;

    piVar5[4] = 0;

    piVar5[5] = 0;

    pcVar7 = (code *)&FUN_003bf370;

  }

  else {

    if (iVar6 == 2) {

      lVar8 = FUN_0027c2b0();

      if ((lVar8 == 0) && (lVar8 = FUN_0027c330(), lVar8 == -1)) {

        bVar4 = 1;

      }

      else {

        bVar4 = 0;

      }

      if (bVar4) {

        *piVar5 = 3;

      }

    }

    else if (iVar6 == 1) {

      if (piVar5[1] < piVar5[2]) {

        piVar5[1] = piVar5[1] + 1;

      }

      else {

        piVar5[1] = 0;

        piVar5[2] = 0;

        lVar8 = FUN_003c40f0(bVar1);

        if (lVar8 == 1) {

          FUN_00521408(auStack_40,0,0x1c);

          uStack_34 = 0x335;

          uStack_30 = 1;

          uStack_2c = (u32)bVar1;

          FUN_0027c080(3,auStack_40,0x1c,0);

        }

        else if ((lVar8 == 2) || (lVar8 == 0)) {

          FUN_00521408(auStack_20,0,0x1c);

          uStack_14 = 0x334;

          uStack_10 = 1;

          uStack_c = (u32)bVar1;

          FUN_0027c080(3,auStack_20,0x1c,0);

        }

        *piVar5 = 2;

      }

    }

    else if (iVar6 == 0) {

      piVar5[1] = 0;

      piVar5[2] = 2;

      *piVar5 = 3;

    }

    pcVar7 = (code *)0x0;

  }

  return pcVar7;

}
#define FUN_003c15d0(...) ((code * (*)(...))FUN_003c15d0)(__VA_ARGS__)
#undef FUN_003c1810
// FUN_003C1810


code * FUN_003c1810(void)



{

  int *piVar1;

  code *pcVar2;

  int lVar3;

  

  piVar1 = (int *)FUN_00195540();

  switch (*piVar1) {
  case 0:
    lVar3 = FUN_001729a0();
    if (lVar3 == 1) {
      *piVar1 = 0;
      piVar1[1] = 0;
      piVar1[2] = 0;
      piVar1[3] = 0;
      piVar1[4] = 0;
      piVar1[5] = 0;
      pcVar2 = (code *)&FUN_003c15d0;
    }
    else {
      *piVar1 = 0;
      piVar1[1] = 0;
      piVar1[2] = 0;
      piVar1[3] = 0;
      piVar1[4] = 0;
      piVar1[5] = 0;
      pcVar2 = (code *)&FUN_003c1440;
    }
    break;
  default:
    pcVar2 = (code *)0x0;
    break;
  }

  return pcVar2;

}
#define FUN_003c1810(...) ((code * (*)(...))FUN_003c1810)(__VA_ARGS__)
#undef FUN_003c18c0
// FUN_003C18C0 NONMATCHING


u32 FUN_003c18c0(void)



{

  int iVar1;

  u8 bVar2;

  int *piVar3;

  long lVar4;

  u16 uStack_40;

  u16 uStack_3e;

  u16 uStack_3c;

  u16 uStack_38;

  u16 uStack_20;

  u16 uStack_1e;

  u16 uStack_1c;

  u16 uStack_18;

  

  piVar3 = (int *)FUN_00195540();

  iVar1 = *piVar3;

  if (iVar1 == 2) {

    lVar4 = FUN_0027c2b0();

    if ((lVar4 == 0) && (lVar4 = FUN_0027c330(), lVar4 == -1)) {

      bVar2 = 1;

    }

    else {

      bVar2 = 0;

    }

    if (bVar2) {

      return 0xffffffff;

    }

  }

  else if (iVar1 == 1) {

    if (piVar3[1] < piVar3[2]) {

      piVar3[1] = piVar3[1] + 1;

    }

    else {

      piVar3[1] = 0;

      piVar3[2] = 0;

      lVar4 = FUN_003951d0(0xbd4);

      if (lVar4 == 1) {

        FUN_00521408(&uStack_20,0,0x1c);

        uStack_20 = 7;

        uStack_1e = 1;

        uStack_1c = 5;

        uStack_18 = 0;

        FUN_0027c080(2,&uStack_20,0x1c,0);

      }

      else {

        FUN_00521408(&uStack_40,0,0x1c);

        uStack_40 = 7;

        uStack_3e = 2;

        uStack_3c = 0;

        uStack_38 = 0;

        FUN_0027c080(2,&uStack_40,0x1c,0);

      }

      *piVar3 = 2;

    }

  }

  else if (iVar1 == 0) {

    piVar3[1] = 0;

    piVar3[2] = 2;

    *piVar3 = 1;

  }

  return 0;

}
#define FUN_003c18c0(...) ((u32 (*)(...))FUN_003c18c0)(__VA_ARGS__)
#undef FUN_003c1a70
// FUN_003C1A70


void FUN_003c1a70(void)



{

  int iVar1;
  
  iVar1 = FUN_00195540();

  (*(code *)0x96017c)(iVar1);

  return;

}
#define FUN_003c1a70(...) ((void (*)(...))FUN_003c1a70)(__VA_ARGS__)
#undef FUN_003c1ab0
// FUN_003C1AB0 NONMATCHING


u64 FUN_003c1ab0(u64 param_1,u64 param_2)



{

  u64 uVar1;

  u64 uVar2;

  long lVar3;

  long lVar4;

  

  lVar4 = 0;

  uVar1 = FUN_0017d920();

  uVar2 = FUN_0017da40();

  switch(param_2) {

  case 1:

    lVar4 = FUN_0017e050(100,uVar1,uVar2);

    if (lVar4 == 1) {

      lVar4 = 0x3bff40;

    }

    else {

      lVar4 = 0x3c0bd0;

    }

    break;

  case 2:

    lVar3 = FUN_0017e050(100,uVar1,uVar2);

    if (lVar3 != 1) {

      lVar4 = 0x3c0f20;

    }

    break;

  case 3:

    lVar3 = FUN_0017e050(100,uVar1,uVar2);

    if (lVar3 == 0) {

      lVar4 = 0x3c1300;

    }

    break;

  case 4:

    lVar3 = FUN_0017e050(100,uVar1,uVar2);

    if (lVar3 == 1) {

      FUN_003bec50();

      lVar4 = 0x3c0d20;

    }

    else {

      lVar3 = FUN_0017db00();

      if ((lVar3 != 6) && (lVar3 = FUN_0017e050(100,uVar1,uVar2), lVar3 == 0)) {

        lVar4 = 0x3c0f20;

      }

    }

    break;

  case 5:

    lVar3 = FUN_0017e050(100,uVar1,uVar2);

    if (lVar3 == 0) {

      lVar4 = 0x3c1810;

    }

    break;

  case 6:

    lVar4 = 0x3c18c0;

    break;

  case 7:

    lVar4 = 0x3bf610;

  }

  if (lVar4 == 0) {

    uVar1 = 0;

  }

  else {

    lVar3 = (*DAT_00960178)(0x58,0x40000);

    if (lVar3 == 0) {

      FUN_0019d3f0("comuTimerSequence.c",0x836);

    }

    FUN_00521408(lVar3,0,0x58);

    uVar1 = FUN_00194b20(param_1,0x6a32b0,0xe,lVar4,0x3c1a70,lVar3);

    *(int *)((int)lVar3 + 0x18) = (int)uVar1;

  }

  return uVar1;

}
#define FUN_003c1ab0(...) ((u64 (*)(...))FUN_003c1ab0)(__VA_ARGS__)
#undef FUN_003c1d20
// FUN_003C1D20 NONMATCHING


u32 FUN_003c1d20(u8 *param_1)



{

  u32 *puVar1;

  u8 uVar2;

  short sVar3;

  u32 uVar4;

  u32 uVar5;

  u32 lVar6;

  u32 *puVar7;

  u8 auStack_4 [4];

  

  puVar1 = *(u32 **)((int)param_1 + 0x3c);

  puVar7 = puVar1 + 0x25;

  switch(*puVar1) {

  case 0:

    lVar6 = FUN_00172d70(puVar1 + 6);

    puVar1[4] = (int)lVar6;

    if (lVar6 == 0) {

      *puVar1 = 0x15;

    }

    else {

      *puVar1 = 1;

    }

    break;

  case 1:

    uVar4 = FUN_00100d80(0x6a32d0,1);

    puVar1[0x2d] = uVar4;

    *puVar1 = 2;

    break;

  case 2:

    lVar6 = FUN_001016b0(puVar1[0x2d]);

    if (lVar6 == 1) {

      uVar5 = FUN_001021c0(0x6a32f0,auStack_4);

      FUN_0039ec70(puVar7,uVar5);

      *puVar1 = 3;

    }

    break;

  case 3:

    puVar1[5] = 0;

    *puVar1 = 4;

    break;

  case 4:

    FUN_0039f210(puVar7,3,-1,-1);

    *puVar1 = 5;

    break;

  case 5:

    lVar6 = FUN_0039f6e0(puVar7);

    if (lVar6 == 1) {

      *puVar1 = 6;

    }

    break;

  case 6:

    if ((int)puVar1[5] >= (int)puVar1[4]) {

      *puVar1 = 0x15;

    }

    else {

      FUN_003bdfc0(puVar1[puVar1[5] + 6]);

      *puVar1 = 7;

    }

    break;

  case 7:

    FUN_003bb010(*(u16 *)(puVar1 + 3),0x11);

    FUN_003952d0(0,0x65,3);

    puVar1[1] = 0;

    puVar1[2] = 0x32;

    *puVar1 = 8;

    break;

  case 8:

    if ((int)puVar1[1] < (int)puVar1[2]) {

      puVar1[1] = puVar1[1] + 1;

    }

    else {

      FUN_003b91c0(1.0f,*(u16 *)(puVar1 + 3),0,0x13,0,0,0);

      FUN_003b9320(1.0f,*(u16 *)(puVar1 + 3),0,0x14,0,1,0);

      *puVar1 = 9;

    }

    break;

  case 9:

    uVar5 = FUN_003c3fe0(puVar1[puVar1[5] + 6]);

    FUN_0039ef30(puVar7,0,uVar5);

    uVar2 = FUN_0016df30(*(u16 *)(puVar1 + puVar1[5] + 6));

    uVar5 = FUN_0030bbb0(uVar2);

    FUN_0039ef30(puVar7,1,uVar5);

    FUN_0039f210(puVar7,0,-1,-1);

    *puVar1 = 10;

    break;

  case 10:

    lVar6 = FUN_0039f6e0(puVar7);

    if (lVar6 == 1) {

      *puVar1 = 0xb;

    }

    break;

  case 0xb:

    FUN_0039f210(puVar7,puVar1[puVar1[5] + 6] + 5,-1,-1);

    *puVar1 = 0xc;

    break;

  case 0xc:

    lVar6 = FUN_0039f6e0(puVar7);

    if (lVar6 == 1) {

      uVar4 = puVar1[puVar1[5] + 6];

      sVar3 = FUN_00171ac0(uVar4);

      if (sVar3 < 1) {

        lVar6 = FUN_001717c0(uVar4);

        if ((lVar6 == 1) || (lVar6 = FUN_00172160(uVar4), lVar6 == 1)) {

          *puVar1 = 0x13;

        }

        else {

          *puVar1 = 0xd;

        }

      }

      else {

        *puVar1 = 0x13;

      }

    }

    break;

  case 0xd:

    FUN_0039f210(puVar7,1,-1,-1);

    *puVar1 = 0xe;

    break;

  case 0xe:

    lVar6 = FUN_0039f6e0(puVar7);

    if (lVar6 == 1) {

      *puVar1 = 0xf;

    }

    break;

  case 0xf:

    uVar4 = FUN_003a2090(param_1,puVar1[puVar1[5] + 6],2,*(u16 *)(puVar1 + 3));

    puVar1[0x24] = uVar4;

    *puVar1 = 0x10;

    break;

  case 0x10:

    lVar6 = FUN_00195460(puVar1[0x24]);

    if (lVar6 == 0) {

      FUN_00171c40(puVar1[puVar1[5] + 6],1);

      *puVar1 = 0x13;

    }

    break;

  case 0x13:

    *puVar1 = 0x14;

    FUN_003b91c0(1.0f,*(u16 *)(puVar1 + 3),0,0x15,0,0,0);

    FUN_003b9320(1.0f,*(u16 *)(puVar1 + 3),0,0,0,1,0);

    puVar1[1] = 0;

    puVar1[2] = 0x1e;

    break;

  case 0x14:

    if ((int)puVar1[1] < (int)puVar1[2]) {

      puVar1[1] = puVar1[1] + 1;

    }

    else {

      puVar1[5] = puVar1[5] + 1;

      *puVar1 = 6;

    }

    break;

  case 0x15:

    return 0xffffffff;

  }

  FUN_0039f410(puVar7);

  return 0;

}
#define FUN_003c1d20(...) ((u32 (*)(...))FUN_003c1d20)(__VA_ARGS__)
#undef FUN_003c22f0
// FUN_003C22F0


void FUN_003c22f0(int param_1)



{

  int iVar1;


  

  iVar1 = *(int *)(param_1 + 0x3c);

  if (*(int *)(iVar1 + 0xb4) != 0) {

    FUN_00100ec0(*(u32 *)(iVar1 + 0xb4));

    *(u32 *)(iVar1 + 0xb4) = 0;

  }

  FUN_0039ee80(iVar1 + 0x94);

  (*(void (**)(...))0x0096017c)(iVar1);

  return;

}
#define FUN_003c22f0(...) ((void (*)(...))FUN_003c22f0)(__VA_ARGS__)
#undef FUN_003c2350
// FUN_003C2350 NONMATCHING


void FUN_003c2350(u64 param_1,u16 param_2)



{

  u64 uVar1;

  

  uVar1 = (*DAT_00960178)(0xb8,0x40000);

  FUN_00521408(uVar1,0,0xb8);

  *(u16 *)((int)uVar1 + 0xc) = param_2;

  FUN_00194b20(param_1,0x6a3308,0x10,0x3c1d20,0x3c22f0,uVar1);

  return;

}
#define FUN_003c2350(...) ((void (*)(...))FUN_003c2350)(__VA_ARGS__)
#undef FUN_003c23f0
// FUN_003C23F0 NONMATCHING

u32 FUN_003c23f0(u32 param_1,u32 param_2,u32 param_3)
{
  u8 bVar1;
  u32 uVar2;
  u32 uVar3;
  u32 iVar4;
  u32 iVar7;
  uVar2 = FUN_003bd870();
  uVar2 = *(u32 *)(uVar2 + 0x628);
  uVar3 = FUN_003bd870();
  uVar3 = *(u32 *)(uVar3 + 0x62c);
  iVar7 = 0;
  goto LAB_003c2544;

LAB_003c2440:
  iVar4 = uVar2 + iVar7 * 5;
  if (param_1 == *(u8 *)iVar4) {
    bVar1 = *(u8 *)(iVar4 + 3);
    if ((bVar1 == 0xff) && (*(u8 *)(iVar4 + 1) != 0xff)) {
      if (FUN_003bf200(param_2,param_3,*(u8 *)(iVar4 + 1),
                       *(u8 *)(iVar4 + 2)) == 1) {
        return 1;
      }
    } else {
      if ((bVar1 == 0xff) && (*(u8 *)(iVar4 + 1) == 0xff)) {
        if (FUN_003bf200(param_2,param_3,*(u8 *)(iVar4 + 1),
                         *(u8 *)(iVar4 + 2)) == 1) {
          return 1;
        }
      } else {
        if (FUN_0017e520(param_2,param_3,*(u8 *)(iVar4 + 1),
                         *(u8 *)(iVar4 + 2),bVar1,*(u8 *)(iVar4 + 4)) == 1) {
          return 1;
        }
        goto LAB_003c2530;
      }
    }
  }
LAB_003c2530:
  iVar7 = iVar7 + 1;
LAB_003c2544:
  if (iVar7 < uVar3) {
    goto LAB_003c2440;
  }
  return 0;
}
#define FUN_003c23f0(...) ((u32 (*)(...))FUN_003c23f0)(__VA_ARGS__)
