#include "temporary.h"
#include "Event/Comu/comuFunction.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))
#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif
extern u32 DAT_007ce420;
extern u32 DAT_007ce66c;
extern u32 DAT_0095b074;
extern u8 DAT_0095b070[];
#pragma alias DAT_0095b070_abs DAT_0095b070
#pragma alias DAT_0095b714_abs DAT_0095b714
extern u8 DAT_0095b714_abs[];
extern u8 DAT_0095b070_abs[];
extern u32 FUN_0035bb40(u32 param_1,u32 param_2,u32 param_3);
extern void FUN_0019d3f0(char* param_1,u32 param_2);
extern u32 FUN_0017e050(long param_1,long param_2,long param_3);
extern u32 FUN_0027c2b0(void);
extern u32 FUN_0027c330(void);
extern u32 FUN_0016dce0(s16 param_1);
extern void K_Assert(const char *file,s32 line);
extern char D_006A3280[];
extern s8 datGetSocialLinkLevel(s16 socialLink);
extern u32 datSocialLinkLevelIsNotZero(s16 socialLink);
extern u32 func_00172a50(s32 socialLink);
extern u32 func_00171960(s32 socialLink,s16 value);
extern s8 func_0016dd20(s16 socialLink);
extern void func_0016e410(s16 socialLink,s8 level);
extern s32 func_003c2570(s32 socialLink);
extern s32 clndGetCurrentMonth(void);
extern s32 clndGetCurrentDay(void);
extern u32 func_003c2b40(s32 *month,s32 *day);
extern u32 func_003c2c50(u8 socialLink);
extern s8 func_0016df30(s16 socialLink);
extern u32 datGetNextExp(s16 pcId);
extern u32 func_0016d280(s32 exp);
extern void *kwlnTaskGetWorkData(void);
extern s16 *datGetActiveSocialLinkPtr(void);
extern u32 func_003c3e80(s32 param_1);
extern u32 adminiGetNowSeqId(void);
extern u32 adminiGetNextSeqId(void);
extern s32 FUN_00172160(long socialLink);
extern s32 FUN_001717c0(long socialLink);
extern s32 FUN_00172660(long socialLink);
#pragma alias FUN_003be1c0_typed FUN_003be1c0
extern u32 FUN_003be1c0_typed(long param_1,s32 param_2);
#pragma alias FUN_003be1c0_wide FUN_003be1c0
extern u32 FUN_003be1c0_wide(long param_1,long param_2);
#pragma alias FUN_003be2a0_typed FUN_003be2a0
extern u32 FUN_003be2a0_typed(...);
extern void adminiChangeSeq(s32 type,void *seq,s32 size,s32 arg4);
extern void FUN_0016f1f0(int param_1,int param_2);
#pragma alias FUN_0016f190_comu FUN_0016f190
extern u32 FUN_0016f190_comu(int param_1);
extern u32 DAT_0095b280;
extern u16* DAT_0095b2a0;
#pragma alias DAT_0095b2a0_abs DAT_0095b2a0
extern u8 DAT_0095b2a0_abs[];
#pragma alias DAT_0095b2a8_abs DAT_0095b2a8
extern u8 DAT_0095b2a8_abs[];
extern u32 DAT_0095b2a8;
extern u32 DAT_0095b568;
extern u32 DAT_0095b5e0[];
extern u32 DAT_0095b678[];
extern u32 DAT_0095b6a8[];
extern u32 DAT_0095b6ac;
extern u32 DAT_0095b6c8;
extern u32 DAT_0095b6cc;
extern u32 DAT_0095b6d8;
extern u32 DAT_0095b6dc;
extern u32 DAT_0095b6f8;
extern u32 DAT_0095b700;
extern u32 DAT_0095b704;
extern u32 DAT_0095b708;
extern u32 DAT_0095b70c;
extern u32 DAT_0095b710;
#pragma alias DAT_0095b710_abs DAT_0095b710
extern u8 *DAT_0095b710_abs[];
extern u32 DAT_0095b714;
extern u32 DAT_0095b718;
extern u32 DAT_0095b730;
extern u32 LAB_003be5a0;

static SiteibiEventTable sSiteibiEvtTable; // 0095b658

SiteibiEventTable* Comu_GetSiteibiEvtTable()
{
    return &sSiteibiEvtTable;
}



/* Region 0x390000-0x3CFFFF recovered prototypes */
void FUN_003bdbd0(int param_1);
u32 * FUN_003bdd40(void);
u32 * FUN_003bdd50(void);
void FUN_003bdd60(u32 param_1,u32 param_2);
u32 FUN_003bdd90(int param_1);
u32 FUN_003bddd0(void);
void FUN_003bdde0(void);
u32 FUN_003bded0(u64 param_1);
u8 FUN_003bdfc0(int param_1);
u32 FUN_003be020(u64 param_1,int param_2,u32 param_3);
u32 FUN_003be2a0(int param_1,int *param_2,u32 param_3,u32 param_4,u8 *param_5);
u32 FUN_003be1c0(u32 param_1,s32 param_2);
u32 FUN_003be8e0(long param_1,u64 param_2);
u8 FUN_003bea20(int param_1,int param_2);
u32 FUN_003beab0(u32 param_1,u32 param_2,int *param_3);
int FUN_003beb10(int param_1);
void FUN_003beb70(int param_1);
u8 FUN_003bebd0(int param_1);
void FUN_003bec50(void);
int FUN_003beca0(int param_1);
u8 * FUN_003bee80(u16 param_1,int *param_2);
u32 FUN_003bf130(void);
void FUN_003bf180(u32 param_1,u32 param_2,u32 param_3);
u32 FUN_003bf200(long param_1,long param_2,long param_3,long param_4);
u32  FUN_003bf270(long param_1,long param_2,long param_3,long param_4,long param_5,long param_6);
u32 FUN_003bf370(void);
u32 FUN_003bf510(void);
u32 FUN_003bf610(void);

/* Region call-cast macros */
#define FUN_003bdbd0(...) ((void (*)(...))FUN_003bdbd0)(__VA_ARGS__)
#define FUN_003bdd40(...) ((u32 * (*)(...))FUN_003bdd40)(__VA_ARGS__)
#define FUN_003bdd50(...) ((u32 * (*)(...))FUN_003bdd50)(__VA_ARGS__)
#define FUN_003bdd60(...) ((void (*)(...))FUN_003bdd60)(__VA_ARGS__)
#define FUN_003bdd90(...) ((u32 (*)(...))FUN_003bdd90)(__VA_ARGS__)
#define FUN_003bddd0(...) ((u32 (*)(...))FUN_003bddd0)(__VA_ARGS__)
#define FUN_003bdde0(...) ((void (*)(...))FUN_003bdde0)(__VA_ARGS__)
#define FUN_003bded0(...) ((u32 (*)(...))FUN_003bded0)(__VA_ARGS__)
#define FUN_003bdfc0(...) ((u8 (*)(...))FUN_003bdfc0)(__VA_ARGS__)
#define FUN_003be020(...) ((u32 (*)(...))FUN_003be020)(__VA_ARGS__)
#define FUN_003be1a0(...) ((u8 (*)(...))FUN_003be1a0)(__VA_ARGS__)
#define FUN_003be1c0(...) ((u32 (*)(...))FUN_003be1c0)(__VA_ARGS__)
#define FUN_003be2a0(...) ((u32 (*)(...))FUN_003be2a0)(__VA_ARGS__)
#define FUN_003be8e0(...) ((u32 (*)(...))FUN_003be8e0)(__VA_ARGS__)
#define FUN_003bea20(...) ((u8 (*)(...))FUN_003bea20)(__VA_ARGS__)
#define FUN_003beab0(...) ((u32 (*)(...))FUN_003beab0)(__VA_ARGS__)
#define FUN_003beb10(...) ((int (*)(...))FUN_003beb10)(__VA_ARGS__)
#define FUN_003beb70(...) ((void (*)(...))FUN_003beb70)(__VA_ARGS__)
#define FUN_003bebd0(...) ((u8 (*)(...))FUN_003bebd0)(__VA_ARGS__)
#define FUN_003bec50(...) ((void (*)(...))FUN_003bec50)(__VA_ARGS__)
#define FUN_003beca0(...) ((int (*)(...))FUN_003beca0)(__VA_ARGS__)
#define FUN_003bee80(...) ((u8 * (*)(...))FUN_003bee80)(__VA_ARGS__)
#define FUN_003bf130(...) ((u32 (*)(...))FUN_003bf130)(__VA_ARGS__)
#define FUN_003bf180(...) ((void (*)(...))FUN_003bf180)(__VA_ARGS__)
#define FUN_003bf200(...) ((u32 (*)(...))FUN_003bf200)(__VA_ARGS__)
#define FUN_003bf270(...) ((u32 (*)(...))FUN_003bf270)(__VA_ARGS__)
#define FUN_003bf370(...) ((u32 (*)(...))FUN_003bf370)(__VA_ARGS__)
#define FUN_003bf510(...) ((u32 (*)(...))FUN_003bf510)(__VA_ARGS__)
#define FUN_003bf610(...) ((u32 (*)(...))FUN_003bf610)(__VA_ARGS__)

#undef FUN_003bdbd0
// FUN_003BDBD0 NONMATCHING


void FUN_003bdbd0(int param_1)
{
  extern u32 FUN_0016e100(s16 param_1);
  extern s8 FUN_0016dba0(s16 param_1);
  u32 bVar2;
  s8 cVar3;
  s16 sVar1;
  u32 lVar4;
  int iVar5;
  lVar4 = FUN_0016dce0((s16)param_1);
  if ((lVar4 != 0) && (lVar4 = FUN_00172a50((s16)param_1), lVar4 != 0)) {
    for (iVar5 = 0; iVar5 < 6; iVar5 = iVar5 + 1) {
      if (param_1 != iVar5 + 6) {
        lVar4 = FUN_0016dce0((s16)(iVar5 + 6));
        if (lVar4 == 0) {
          FUN_0019d3f0("comuFunction.c",0x1b6);
        }

        if (FUN_0016e100((s16)(iVar5 + 6)) == 0) {
          bVar2 = 0;
        }
        else if (FUN_00172a50((s16)(iVar5 + 6)) == 0) {
          bVar2 = 0;
        }
        else {
          cVar3 = FUN_0016dba0((s16)(iVar5 + 6));
          if ((long)cVar3 >= (long)(u32)*(u8 *)(*(u32 *)DAT_0095b2a8_abs + iVar5)) {
            bVar2 = 1;
          }
          else {
            bVar2 = 0;
          }
        }

        if (bVar2) {
          sVar1 = *(volatile /* Removing this qualifier worsens FUN_003bdbd0 (NONMATCHING nd41 -> NONMATCHING nd49, size 360 -> 360) - measured W170. */ s16 *)(*(u32 *)DAT_0095b2a0_abs);
          FUN_00171960(iVar5 + 6,(s32)sVar1);
        }
      }
    }
  }
}
#define FUN_003bdbd0(...) ((void (*)(...))FUN_003bdbd0)(__VA_ARGS__)
#undef FUN_003bdd40
// FUN_003BDD40

u32 *FUN_003bdd40(void)
{
  return DAT_0095b678;
}
#define FUN_003bdd40(...) ((u32 * (*)(...))FUN_003bdd40)(__VA_ARGS__)
#undef FUN_003bdd50
// FUN_003BDD50

u32 *FUN_003bdd50(void)
{
  return DAT_0095b6a8;
}
#define FUN_003bdd50(...) ((u32 * (*)(...))FUN_003bdd50)(__VA_ARGS__)
#undef FUN_003bdd60
// FUN_003BDD60


void FUN_003bdd60(u32 param_1,u32 param_2)



{

  FUN_0035bb40(param_1,*(u32 *)0x0095b074,param_2);

  return;

}
#define FUN_003bdd60(...) ((void (*)(...))FUN_003bdd60)(__VA_ARGS__)
#undef FUN_003bdd90
// FUN_003BDD90


u32 FUN_003bdd90(int param_1)



{

  u32 uVar1;
  int iVar2;
  u32 *puVar1;
  puVar1 = (u32 *)DAT_0095b070;

  

  if (0x1e < param_1) {

    uVar1 = 0;

  }

  else {

    uVar1 = puVar1[param_1 + 0x15c];

  }

  return uVar1;

}
#define FUN_003bdd90(...) ((u32 (*)(...))FUN_003bdd90)(__VA_ARGS__)
#undef FUN_003bddd0
// FUN_003BDDD0

u32 FUN_003bddd0(void)
{
  return *(u32 *)0x0095b280;
}
#define FUN_003bddd0(...) ((u32 (*)(...))FUN_003bddd0)(__VA_ARGS__)
#undef FUN_003bdde0
// FUN_003BDDE0


void FUN_003bdde0(void)



{
  extern u32 FUN_0016e100(s16 param_1);
  extern s32 FUN_001717c0(s32 param_1);
  extern s32 FUN_00172160(s32 param_1);
  extern s8 FUN_0016dba0(s16 param_1);
  extern void FUN_00171960(s32 param_1,s32 param_2);
  extern s16 FUN_00171ac0(s32 param_1);
  extern void FUN_00171c40(s32 param_1,s32 param_2);

  char cVar1;

  short sVar2;

  u32 uVar3;

  int iVar4;

  

  for (iVar4 = 0; iVar4 < 0x1e; iVar4 = iVar4 + 1) {


    if ((((uVar3 = FUN_0016e100((short)iVar4), uVar3 != 0) &&

          (uVar3 = FUN_001717c0(iVar4), uVar3 != 1)) &&

         (uVar3 = FUN_00172160(iVar4), uVar3 != 1)) &&

        (cVar1 = FUN_0016dba0((short)iVar4), cVar1 != '\n')) {

      FUN_00171960(iVar4,1);

      sVar2 = FUN_00171ac0(iVar4);

      if (sVar2 < 1) {

        FUN_00171c40(iVar4,1);

      }

    }

  }

  return;

}
#define FUN_003bdde0(...) ((void (*)(...))FUN_003bdde0)(__VA_ARGS__)
#undef FUN_003bded0
// FUN_003BDED0


u32 FUN_003bded0(u64 param_1)



{

  extern s8 FUN_0016dba0(s16 param_1);
  char cVar1;
  s32 lVar3;

  

  cVar1 = FUN_0016dba0((short)param_1);
  if (cVar1 == '\n') {
    return 5;
  }
  lVar3 = FUN_00172160(param_1);
  if (lVar3 == 1) {
    return 4;
  }
  lVar3 = FUN_001717c0(param_1);
  if (lVar3 == 1) {
    return 3;
  }
  lVar3 = FUN_00172660(param_1);
  if (lVar3 == 1) {
    lVar3 = FUN_003be1c0_typed(param_1,cVar1 + 1);
    if (lVar3 == 1) {
      return 2;
    }
    return 1;
  }
  return 0;

}
#define FUN_003bded0(...) ((u32 (*)(...))FUN_003bded0)(__VA_ARGS__)
#undef FUN_003bdfc0
// FUN_003BDFC0


u8 FUN_003bdfc0(int param_1)



{

  u32 lVar1;

  

  lVar1 = FUN_0016dce0((short)param_1);

  if (lVar1 == 0) {

    FUN_0019d3f0("comuFunction.c",0x291);

  }

  return *(u8 *)(*(u32 *)0x0095b700 + param_1);

}
#define FUN_003bdfc0(...) ((u8 (*)(...))FUN_003bdfc0)(__VA_ARGS__)
#undef FUN_003be020
// FUN_003BE020 NONMATCHING


u32 FUN_003be020(u64 param_1,int param_2,u32 param_3)



{

  u8 bVar1;

  u8 bVar2;

  u16 uVar3;

  u16 uVar4;

  int iVar5;

  int iVar6;

  char cVar7;

  u8 *pbVar8;

  u16 *puVar9;

  long lVar10;

  u32 uVar11;

  int iVar12;

  

  iVar6 = DAT_0095b6cc;

  iVar5 = DAT_0095b6c8;

  iVar12 = 0;

  do {

    if (iVar6 <= iVar12) {

      return 0;

    }

    pbVar8 = (u8 *)(iVar5 + iVar12 * 2);

    bVar1 = *pbVar8;

    uVar11 = (u32)bVar1;

    if (param_3 == uVar11) {

      bVar2 = pbVar8[1];

      lVar10 = FUN_00172a50(bVar1);

      if (lVar10 != 0) {

        lVar10 = FUN_0016e100(bVar1);

        if (lVar10 == 1) {

          cVar7 = FUN_0016dba0(bVar1);

          lVar10 = (long)cVar7;

        }

        else {

          lVar10 = 0;

        }

        if (((long)(u32)bVar2 <= lVar10) &&

           ((lVar10 < 1 ||

            ((lVar10 = FUN_001717c0(uVar11), lVar10 != 1 &&

             (lVar10 = FUN_00172160(uVar11), lVar10 != 1)))))) {

          puVar9 = (u16 *)(DAT_0095b70c + (bVar1 - 6) * 6);

          uVar3 = puVar9[1];

          uVar4 = puVar9[2];

          *(u16 *)(param_2 + 0x2a) = *puVar9;

          *(u16 *)(param_2 + 0x2c) = uVar3;

          *(u16 *)(param_2 + 0x2e) = uVar4;

          *(u8 *)(param_2 + 1) = bVar1;

          return 1;

        }

      }

    }

    iVar12 = iVar12 + 1;

  } while( 1 );

}
#define FUN_003be020(...) ((u32 (*)(...))FUN_003be020)(__VA_ARGS__)
#undef FUN_003be1a0
// FUN_003BE1A0


u8 FUN_003be1a0(int param_1)



{

  return *(int *)(param_1 + 4) == 3;

}
#define FUN_003be1a0(...) ((u8 (*)(...))FUN_003be1a0)(__VA_ARGS__)
#undef FUN_003be1c0
// FUN_003BE1C0


u32 FUN_003be1c0(u32 param_1,s32 param_2)



{
  int iVar1;
  u32 lVar2;
  int iVar2;
  int iVar3;
  u8 *pbBase;

  iVar1 = *(u32 *)DAT_0095b714_abs;


  if (param_2 < 2) {
    return 0;
  }

  iVar3 = 0;
  iVar2 = (int)param_2 * 2;
  for (; iVar3 < iVar1; iVar3 = iVar3 + 1) {
    pbBase = DAT_0095b710_abs[0];
    if (((param_1 == pbBase[iVar3 * 0x1a]) &&
        (*(u16 *)(iVar2 + (int)pbBase + iVar3 * 0x1a + 4) != 0)) &&
       (lVar2 = FUN_0016f190_comu(*(u16 *)(iVar2 + (int)pbBase +
                                            iVar3 * 0x1a + 4)),
        lVar2 == 0)) {
      return 1;
    }
  }

  return 0;
}
#define FUN_003be1c0(...) ((u32 (*)(...))FUN_003be1c0)(__VA_ARGS__)
#undef FUN_003be2a0
// FUN_003BE2A0 NONMATCHING
u32 FUN_003be2a0(int param_1,int *param_2,u32 param_3,u32 param_4,u8 *param_5)




{

  u16 uVar1;

  u16 uVar2;

  u16 uVar3;

  char cVar4;

  u16 *puVar5;

  s32 lVar6;

  u8 *pbVar7;

  u16 uVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  u32 uVar13;

  u8 *puVar14;

  u16 auStack_44 [32];

  

  puVar14 = param_5;
  uVar13 = 0;

  lVar6 = FUN_0016dce0((s16)param_3);

  if (lVar6 == 0) {

    FUN_0019d3f0("comuFunction.c",0x32a);

  }

  FUN_00521408(puVar14,0,0x38);


  *puVar14 = (char)param_3;

  puVar14[2] = (char)param_4;

  cVar4 = FUN_0016dba0((s16)param_3);


  if (cVar4 >= '\x01') {

    if (param_4 < 8) {

      iVar9 = (int)param_3;

      iVar11 = (int)cVar4;

      switch(param_4) {

      case 0:

        if (*(int *)((u8 *)DAT_0095b070_abs + iVar9 * 4 + 0x480) == 0) {

          FUN_0019d3f0("comuFunction.c",0x339);

        }

        cVar4 = FUN_0016dd20((s16)param_3);

        lVar6 = (s32)cVar4;

        if (9 < lVar6) {

          lVar6 = 9;

        }

        iVar12 = *(int *)((u8 *)DAT_0095b070_abs + iVar9 * 4 + 0x480) + ((int)lVar6 + (iVar11 + -1) * 10) * 0xe;

        uVar13 = 2;

        uVar8 = *(u16 *)(iVar12 + 10);

        uVar2 = *(u16 *)(iVar12 + 0xc);

        *(u16 *)(puVar14 + 0x1e) = *(u16 *)(iVar12 + 8);

        *(u16 *)(puVar14 + 0x20) = uVar8;

        *(u16 *)(puVar14 + 0x22) = uVar2;

        uVar8 = *(u16 *)(iVar12 + 0x10);

        uVar2 = *(u16 *)(iVar12 + 0x12);

        *(u16 *)(puVar14 + 0x24) = *(u16 *)(iVar12 + 0xe);

        *(u16 *)(puVar14 + 0x26) = uVar8;

        *(u16 *)(puVar14 + 0x28) = uVar2;

        if ((*(char *)(iVar12 + 0x14) != '\0') &&

           (lVar6 = FUN_003be020(param_3,param_5), lVar6 == 1)) {

          uVar13 = 3;

        }

        break;

      case 1:

        if (*(int *)((u8 *)DAT_0095b070_abs + iVar9 * 4 + 0x4f8) == 0) {

          FUN_0019d3f0("comuFunction.c",0x351);

        }

        iVar12 = *(int *)((u8 *)DAT_0095b070_abs + iVar9 * 4 + 0x4f8) + (iVar11 + -1) * 0x18;

        uVar2 = *(u16 *)(iVar12 + 10);

        uVar1 = *(u16 *)(iVar12 + 0xc);

        *(u16 *)(puVar14 + 0x1e) = *(u16 *)(iVar12 + 8);

        *(u16 *)(puVar14 + 0x20) = uVar2;

        *(u16 *)(puVar14 + 0x22) = uVar1;

        uVar2 = *(u16 *)(iVar12 + 0x10);

        uVar1 = *(u16 *)(iVar12 + 0x12);

        *(u16 *)(puVar14 + 0x24) = *(u16 *)(iVar12 + 0xe);

        *(u16 *)(puVar14 + 0x26) = uVar2;

        *(u16 *)(puVar14 + 0x28) = uVar1;

        uVar2 = *(u16 *)(iVar12 + 0x16);

        uVar1 = *(u16 *)(iVar12 + 0x18);

        *(u16 *)(puVar14 + 0x2a) = *(u16 *)(iVar12 + 0x14);

        *(u16 *)(puVar14 + 0x2c) = uVar2;

        *(u16 *)(puVar14 + 0x2e) = uVar1;

        uVar2 = *(u16 *)(iVar12 + 0x1c);

        uVar1 = *(u16 *)(iVar12 + 0x1e);

        *(u16 *)(puVar14 + 0x30) = *(u16 *)(iVar12 + 0x1a);

        *(u16 *)(puVar14 + 0x32) = uVar2;

        *(u16 *)(puVar14 + 0x34) = uVar1;

        uVar13 = 3;

        if (param_1 == 1) {

          FUN_0016e410(param_3,cVar4 + '\x01');

        }

        break;

      case 2:

        for (iVar12 = 0; iVar12 < DAT_0095b714; iVar12 = iVar12 + 1) {
          pbVar7 = (u8 *)DAT_0095b710_abs + iVar12 * 0x1a;


          if (param_3 == *pbVar7) {

            pbVar7 = pbVar7 + 2;

            goto LAB_003be5a0;

          }

        }

        pbVar7 = (u8 *)0x0;

LAB_003be5a0:

        if (pbVar7 == (u8 *)0x0) {

          FUN_0019d3f0("comuFunction.c",0x365);

        }

        uVar8 = *(u16 *)(pbVar7 + 2);

        uVar2 = *(u16 *)(pbVar7 + 4);

        *(u16 *)(puVar14 + 0x1e) = *(u16 *)pbVar7;

        *(u16 *)(puVar14 + 0x20) = uVar8;

        *(u16 *)(puVar14 + 0x22) = uVar2;

        uVar13 = 1;

        break;

      case 3:

        puVar5 = (u16 *)(DAT_0095b6f8 + iVar9 * 6);

        uVar8 = puVar5[1];

        uVar2 = puVar5[2];

        *(u16 *)(puVar14 + 0x1e) = *puVar5;

        *(u16 *)(puVar14 + 0x20) = uVar8;

        *(u16 *)(puVar14 + 0x22) = uVar2;

        puVar14[0x23] = 0;

        uVar13 = 1;

        break;

      case 4:

        puVar5 = (u16 *)(DAT_0095b704 + iVar9 * 6);

        uVar8 = puVar5[1];

        uVar2 = puVar5[2];

        *(u16 *)(puVar14 + 0x1e) = *puVar5;

        *(u16 *)(puVar14 + 0x20) = uVar8;

        *(u16 *)(puVar14 + 0x22) = uVar2;

        uVar13 = 1;

        break;

      case 5:

        if (*(int *)((u8 *)DAT_0095b070_abs + iVar9 * 4 + 0x480) == 0) {

          FUN_0019d3f0("comuFunction.c",0x37d);

        }

        iVar12 = *(int *)((u8 *)DAT_0095b070_abs + iVar9 * 4 + 0x480);

        uVar8 = *(u16 *)(iVar12 + 0x4f6);

        uVar2 = *(u16 *)(iVar12 + 0x4f8);

        *(u16 *)(puVar14 + 0x1e) = *(u16 *)(iVar12 + 0x4f4);

        *(u16 *)(puVar14 + 0x20) = uVar8;

        *(u16 *)(puVar14 + 0x22) = uVar2;

        uVar13 = 1;

        break;

      case 6:
        lVar6 = FUN_00172a50((s16)param_3);

        if (lVar6 == 0) {

          FUN_0019d3f0("comuFunction.c",0x388);

        }

        iVar12 = FUN_003c2570(param_3);

        puVar5 = (u16 *)(DAT_0095b708 + (iVar12 + (iVar9 + -6) * 4) * 6);

        uVar8 = puVar5[1];

        uVar2 = puVar5[2];

        *(u16 *)(puVar14 + 0x1e) = *puVar5;

        *(u16 *)(puVar14 + 0x20) = uVar8;

        *(u16 *)(puVar14 + 0x22) = uVar2;

        uVar13 = 1;

        break;

      case 7:
        puVar5 = (u16 *)DAT_0095b6a8;
        iVar12 = *(u32 *)puVar5;

        iVar9 = 0;

        for (iVar10 = 0; iVar10 < *((u32 *)puVar5 + 1); iVar10 = iVar10 + 1) {

          if (param_3 == *(u8 *)(iVar12 + iVar10 * 0x18)) {

            if (0x1f < iVar9) break;

            auStack_44[iVar9] = (u16)iVar10;

            iVar9 = iVar9 + 1;

          }

        }

        if (iVar9 == 0) {

          FUN_0019d3f0("comuFunction.c",0x3b3);

          return 0;

        }

        if (param_1 != 1) {

          if ((cVar4 < '\x02') || ('\t' < cVar4)) {

            FUN_0019d3f0("comuFunction.c",0x3ca);

          }

          uVar3 = auStack_44[iVar11 - 2];

        }

        else {

          uVar3 = auStack_44[*param_2];

        }

        iVar12 = iVar12 + (u32)uVar3 * 0x18;

        uVar8 = *(u16 *)(iVar12 + 4);

        uVar2 = *(u16 *)(iVar12 + 6);

        *(u16 *)(puVar14 + 0x1e) = *(u16 *)(iVar12 + 2);

        *(u16 *)(puVar14 + 0x20) = uVar8;

        *(u16 *)(puVar14 + 0x22) = uVar2;

        uVar8 = *(u16 *)(iVar12 + 10);

        uVar2 = *(u16 *)(iVar12 + 0xc);

        *(u16 *)(puVar14 + 0x24) = *(u16 *)(iVar12 + 8);

        *(u16 *)(puVar14 + 0x26) = uVar8;

        *(u16 *)(puVar14 + 0x28) = uVar2;

        for (iVar11 = 0; iVar11 < 5; iVar11 = iVar11 + 1) {

          *(u16 *)(puVar14 + iVar11 * 2 + 0x14) = *(u16 *)(iVar12 + iVar11 * 2 + 0xe);

        }

        uVar13 = 2;

      }

    }

    *(u32 *)(puVar14 + 4) = uVar13;

    uVar13 = 1;

  }

  else {

    uVar13 = 0;

  }

  return uVar13;

}
#define FUN_003be2a0(...) ((u32 (*)(...))FUN_003be2a0)(__VA_ARGS__)
#undef FUN_003be8e0
// FUN_003BE8E0
u32 FUN_003be8e0(long param_1,u64 param_2)
{
  s32 var_7;
  s8 cVar1;
  s32 lVar2;

  if ((param_1 >= 0x1e) || (param_1 < 0)) {
    K_Assert(D_006A3280,0x3e8);
  }

  cVar1 = datGetSocialLinkLevel((s16)param_1);
  if (cVar1 == '\n') {
    var_7 = 5;
  }
  else {
    lVar2 = FUN_00172160(param_1);
    if (lVar2 == 1) {
      var_7 = 4;
    }
    else {
      lVar2 = FUN_001717c0(param_1);
      if (lVar2 == 1) {
        var_7 = 3;
      }
      else {
        lVar2 = FUN_00172660(param_1);
        if (lVar2 == 1) {
          lVar2 = FUN_003be1c0_typed(param_1,cVar1 + 1);
          if (lVar2 == 1) {
            var_7 = 2;
          }
          else {
            var_7 = 1;
          }
        }
        else {
          var_7 = 0;
        }
      }
    }
  }

  FUN_003be2a0_typed(0,0,param_1,var_7,param_2);
  return 1;
}
#define FUN_003be8e0(...) ((u32 (*)(...))FUN_003be8e0)(__VA_ARGS__)
#undef FUN_003bea20
// FUN_003BEA20


u8 FUN_003bea20(int param_1,int param_2)



{
  u8 *pbVar1;
  int iVar2;
  int iVar3;

  if (!(param_1 < 4)) {

    FUN_0019d3f0("comuFunction.c",0x3f9);

  }

  iVar2 = (int)param_1 * 6;
  iVar3 = param_2;
  param_2 = iVar2;
  param_2 += iVar3;
  pbVar1 = (u8 *)(param_2 + 0x1e);
  if (!(*(u8 *)(param_2 + 0x1e) < 0x2a)) {

    FUN_0019d3f0("comuFunction.c",0x3fb);

  }

  return *pbVar1;

}
#define FUN_003bea20(...) ((u8 (*)(...))FUN_003bea20)(__VA_ARGS__)
#undef FUN_003beab0
// FUN_003BEAB0


u32 FUN_003beab0(u32 param_1,u32 param_2,int *param_3)



{
  u8 *pbVar1;
  u8 *pbBase;
  int iVar2;

  iVar2 = 0;
  pbBase = *(u8 **)(0x0095b718);
  goto check;
loop:
  pbVar1 = pbBase + iVar2 * 0x20;
  if (param_1 != *pbVar1) goto next;
  if (param_2 != pbVar1[1]) goto next;
  *param_3 = iVar2;
  return 1;
next:
  iVar2 = iVar2 + 1;
check:
  if (iVar2 < 0x40) goto loop;
  return 0;
}

#define FUN_003beab0(...) ((u32 (*)(...))FUN_003beab0)(__VA_ARGS__)
#undef FUN_003beb10
// FUN_003BEB10


int FUN_003beb10(int param_1)



{
  u32 base;

  if ((param_1 < 0) || !(param_1 < 0x40)) {

    FUN_0019d3f0("comuFunction.c",0x416);

  }

  base = *(u32 *)0x0095b718;
  return base + param_1 * 0x20;

}
#define FUN_003beb10(...) ((int (*)(...))FUN_003beb10)(__VA_ARGS__)
#undef FUN_003beb70
// FUN_003BEB70


void FUN_003beb70(int param_1)



{

  u32 lVar1;

  

  lVar1 = FUN_0016dce0((short)param_1);

  if (lVar1 == 0) {

    FUN_0019d3f0("comuFunction.c",0x422);

  }

  FUN_0016f1f0(param_1 + 0x9d0,1);

  return;

}
#define FUN_003beb70(...) ((void (*)(...))FUN_003beb70)(__VA_ARGS__)
#undef FUN_003bebd0
// FUN_003BEBD0


u8 FUN_003bebd0(int param_1)



{

  u32 lVar1;

  

  lVar1 = FUN_0016dce0((short)param_1);

  if (lVar1 == 0) {

    FUN_0019d3f0("comuFunction.c",0x42b);

  }

  lVar1 = FUN_0016f190_comu(param_1 + 0x9d0);

  if (lVar1 == 1) {

    return 1;

  }

  return 0;

}
#define FUN_003bebd0(...) ((u8 (*)(...))FUN_003bebd0)(__VA_ARGS__)
#undef FUN_003bec50
// FUN_003BEC50


void FUN_003bec50(void)



{

  int iVar1;

  

  for (iVar1 = 0; iVar1 < 0x1e; iVar1 = iVar1 + 1) {

    FUN_0016f1f0(iVar1 + 0x9d0,0);

  }

  return;

}
#define FUN_003bec50(...) ((void (*)(...))FUN_003bec50)(__VA_ARGS__)
#undef FUN_003beca0
// FUN_003BECA0 NONMATCHING


int FUN_003beca0(int param_1)



{

  u8 bVar1;

  u8 bVar2;

  u8 bVar3;

  int iVar4;

  int iVar5;

  char cVar6;

  u32 uVar7;

  u32 uVar8;

  int lVar9;

  u8 *pbVar10;

  int iVar11;

  int iVar12;

  u32 uStack_8;

  u32 uStack_4;

  

  iVar5 = DAT_0095b6dc;

  iVar4 = DAT_0095b6d8;

  iVar11 = 0;

  uStack_4 = 0;

  uStack_8 = 0;

  uVar7 = FUN_0017d920();

  uVar8 = FUN_0017da40();

  lVar9 = FUN_003c2b40(&uStack_4,&uStack_8);

  if (lVar9 != 0) {

    for (iVar12 = 0; iVar12 < iVar5; iVar12 = iVar12 + 1) {

      pbVar10 = (u8 *)(iVar4 + iVar12 * 5);

      if ((uVar7 == *pbVar10) && (uVar8 == pbVar10[1])) {

        bVar1 = pbVar10[2];

        bVar2 = pbVar10[3];

        bVar3 = pbVar10[4];

        cVar6 = FUN_0016dba0(bVar1);

        lVar9 = (long)cVar6;

        if ((((long)(u32)bVar2 <= lVar9) && (lVar9 <= (long)(u32)bVar3)) &&

           ((lVar9 != 9 || (lVar9 = FUN_00172660(bVar1), lVar9 != 1)))) {

          lVar9 = FUN_0016dce0(bVar1);

          if (lVar9 == 0) {

            FUN_0019d3f0("comuFunction.c",0x42b);

          }

          lVar9 = FUN_0016f190(bVar1 + 0x9d0);

          if ((lVar9 != 1) && (lVar9 = FUN_003c2c50(bVar1), lVar9 != 0)) {

            *(u32 *)(param_1 + iVar11 * 4) = (u32)bVar1;

            iVar11 = iVar11 + 1;

          }

        }

      }

    }

  }

  else {

    iVar11 = 0;

  }

  return iVar11;

}
#define FUN_003beca0(...) ((int (*)(...))FUN_003beca0)(__VA_ARGS__)
#undef FUN_003bee80
// FUN_003BEE80 NONMATCHING


u8 * FUN_003bee80(u16 param_1,int *param_2)



{

  u16 uVar1;

  u16 uVar2;

  char cVar3;

  char cVar4;

  int iVar5;

  u64 uVar6;

  u32 uVar7;

  u32 uVar8;

  u16 *puVar9;

  int iVar10;

  u32 uVar11;

  int iVar12;

  int iVar13;

  

  cVar3 = FUN_0016df30(param_1);

  iVar13 = 0;

  uVar6 = FUN_0016c7e0(1);

  uVar7 = FUN_0016d280(uVar6);

  iVar12 = -1;

  uVar11 = 9999;

  for (iVar5 = 1; iVar5 < 0x100; iVar5 = iVar5 + 1) {

    puVar9 = (u16 *)(DAT_007ce420 + iVar5 * 0xe);

    if (((((long)cVar3 == (u32)(u8)puVar9[1]) && (uVar1 = *puVar9, (uVar1 & 0x10) == 0)) &&

        ((uVar1 & 8) == 0)) &&

       (((uVar1 & 0x40) == 0 || (cVar4 = FUN_0016dba0(param_1), cVar4 == '\n')))) {

      uVar8 = (u32)*(u8 *)(DAT_007ce420 + iVar5 * 0xe + 3);

      if ((uVar7 & 0xff) < uVar8) {

        if (uVar8 < uVar11) {

          uVar11 = uVar8;

          iVar12 = iVar5;

        }

      }

      else {

        if (0xe < iVar13) {

          FUN_0019d3f0("comuFunction.c",0x4b2);

        }

        *(short *)(&DAT_0095b730 + iVar13 * 2) = (short)iVar5;

        iVar13 = iVar13 + 1;

      }

    }

  }

  if (iVar12 != -1) {

    if (0xe < iVar13) {

      FUN_0019d3f0("comuFunction.c",0x4c4);

    }

    *(short *)(&DAT_0095b730 + iVar13 * 2) = (short)iVar12;

    iVar13 = iVar13 + 1;

  }

  *param_2 = iVar13;

  iVar12 = DAT_007ce420;

  for (iVar5 = 0; iVar5 < iVar13 + -1; iVar5 = iVar5 + 1) {

    iVar10 = iVar5;

    while (iVar10 = iVar10 + 1, iVar10 < iVar13) {

      uVar1 = *(u16 *)(&DAT_0095b730 + iVar5 * 2);

      uVar2 = *(u16 *)(&DAT_0095b730 + iVar10 * 2);

      if (*(u8 *)(iVar12 + (u32)uVar2 * 0xe + 3) < *(u8 *)(iVar12 + (u32)uVar1 * 0xe + 3)) {

        *(u16 *)(&DAT_0095b730 + iVar5 * 2) = uVar2;

        *(u16 *)(&DAT_0095b730 + iVar10 * 2) = uVar1;

      }

    }

  }

  if (iVar13 == 0) {

    FUN_0019d3f0("comuFunction.c",0x4dd);

  }

  return (u8*)&DAT_0095b730;

}
#define FUN_003bee80(...) ((u8 * (*)(...))FUN_003bee80)(__VA_ARGS__)
#undef FUN_003bf130
// FUN_003BF130


u32 FUN_003bf130(void)



{

  u32 uVar1;

  u32 lVar2;

  

  lVar2 = FUN_0027c2b0();

  if ((lVar2 == 0) && (lVar2 = FUN_0027c330(), lVar2 == -1)) {

    uVar1 = 1;

  }

  else {

    uVar1 = 0;

  }

  return uVar1;

}
#define FUN_003bf130(...) ((u32 (*)(...))FUN_003bf130)(__VA_ARGS__)
#undef FUN_003bf180
// FUN_003BF180


void FUN_003bf180(u32 param_1,u32 param_2,u32 param_3)



{
  struct {
    u8 data[12];
    u32 param_1;
    u32 param_2;
    u32 param_3;
    u32 pad;
  } packet;

  FUN_00521408(packet.data,0,0x1c);

  packet.param_1 = param_1;
  packet.param_2 = param_2;
  packet.param_3 = param_3;

  FUN_0027c080(3,packet.data,0x1c,0);
  return;
}
#define FUN_003bf180(...) ((void (*)(...))FUN_003bf180)(__VA_ARGS__)
#undef FUN_003bf200
// FUN_003BF200


u32 FUN_003bf200(long param_1,long param_2,long param_3,long param_4)



{

  u32 bVar1;

  u32 lVar2;

  

  if (param_3 == 0xff) {

    lVar2 = FUN_0017e050(param_4,param_1,param_2);

    bVar1 = lVar2 == 1;

  }

  else if ((param_1 == param_3) && (param_2 == param_4)) {

    bVar1 = 1;

  }

  else {

    bVar1 = 0;

  }

  return bVar1;

}
#define FUN_003bf200(...) ((u32 (*)(...))FUN_003bf200)(__VA_ARGS__)
#undef FUN_003bf270
// FUN_003BF270


u32

FUN_003bf270(long param_1,long param_2,long param_3,long param_4,long param_5,long param_6)



{
  if (param_3 > param_5 || ((param_3 == param_5) && (param_6 < param_4))) {
    if (param_3 <= param_1) {
      if (param_3 == param_1) {
        if (param_4 <= param_2) {
          return 1;
        }
      } else {
        return 1;
      }
    } else {
      if (!(param_5 < param_1)) {
        if (param_5 == param_1) {
          if (!(param_6 < param_2)) {
            return 1;
          }
        } else {
          return 1;
        }
      }
    }
  } else if ((param_3 <= param_1) && (param_1 <= param_5)) {
    if (param_3 == param_1) {
      if (param_4 <= param_2) {
        return 1;
      }
    } else {
      if (param_5 == param_1) {
        if (!(param_6 < param_2)) {
          return 1;
        }
      } else {
        return 1;
      }
    }
  }
  return 0;
}
#define FUN_003bf270(...) ((u32 (*)(...))FUN_003bf270)(__VA_ARGS__)
#undef FUN_003bf370
// FUN_003BF370


u32 FUN_003bf370(void)
{
  int iVar1;
  u32 bVar2;
  u32 bVar3;
  int *piVar3;
  int iVar4;
  u32 lVar5;
  u8 auStack_20 [28];

  piVar3 = (int *)FUN_00195540();
  iVar4 = FUN_001717b0();
  iVar1 = *piVar3;
  switch (iVar1) {
  case 0:
    DAT_007ce66c = 0;
    *piVar3 = 1;
    break;
  case 1:
    lVar5 = FUN_003c3e80(iVar4 + 0x1e4);
    if (lVar5 == 0) {
      *piVar3 = 2;
    }
    break;
  case 2:
    piVar3[1] = 0;
    piVar3[2] = 2;
    *piVar3 = 3;
    break;
  case 3:
    if (piVar3[1] >= piVar3[2]) {
      piVar3[1] = 0;
      piVar3[2] = 0;
      bVar3 = 1;
    }
    else {
      piVar3[1] = piVar3[1] + 1;
      bVar3 = 0;
    }
    if (bVar3 == 0) {
      break;
    }
    FUN_00521408(auStack_20,0,0x1c);
    ((u32 *)auStack_20)[3] = 0x35d;
    ((u32 *)auStack_20)[4] = 1;
    ((u32 *)auStack_20)[5] = 0;
    FUN_0027c080(3,auStack_20,0x1c,0);
    *piVar3 = 4;
    break;
  case 4:
    lVar5 = FUN_0027c2b0();
    if (lVar5 != 0) goto case4_false;
    lVar5 = FUN_0027c330();
    if (lVar5 != -1) goto case4_false;
    bVar2 = 1;
    goto case4_check;
case4_false:
    bVar2 = 0;
case4_check:
    if (bVar2 != 1) {
      break;
    }
    return 0xffffffff;
  }
  return 0;
}
#define FUN_003bf370(...) ((u32 (*)(...))FUN_003bf370)(__VA_ARGS__)
#undef FUN_003bf510
// FUN_003BF510


u32 FUN_003bf510(void)



{
  int iVar1;
  int *piVar3;
  int iVar4;
  u32 lVar5;
  u32 bVar2;

  piVar3 = (int *)FUN_00195540();
  iVar4 = FUN_001717b0();
  iVar1 = *piVar3;

  switch (iVar1) {
  case 0:
    *piVar3 = 1;
    break;
  case 1:
    lVar5 = FUN_003c3e80(iVar4 + 0x248);
    if (lVar5 == 0) {
      *piVar3 = 2;
    }
    break;
  case 2:
    return 0xffffffff;
  case 3:
    lVar5 = FUN_0027c2b0();
    if (lVar5 != 0) goto case3_false;
    lVar5 = FUN_0027c330();
    if (lVar5 != -1) goto case3_false;
    bVar2 = 1;
    goto case3_check;
case3_false:
    bVar2 = 0;
case3_check:
    if (bVar2 != 1) {
      break;
    }
    return 0xffffffff;
  default:
    break;
  }

  return 0;
}
#define FUN_003bf510(...) ((u32 (*)(...))FUN_003bf510)(__VA_ARGS__)
#undef FUN_003bf610
// FUN_003BF610

u32 FUN_003bf610(void)
{
  int iVar1;
  u32 bVar2;
  int *piVar3;
  u32 lVar4;
  u16 auStack_20 [14];

  piVar3 = (int *)FUN_00195540();
  iVar1 = *piVar3;
  switch (iVar1) {
  case 0:
    piVar3[1] = 0;
    piVar3[2] = 2;
    *piVar3 = 1;
    break;
  case 1:
    FUN_00521408(auStack_20,0,0x1c);
    auStack_20[0] = 7;
    auStack_20[1] = 1;
    auStack_20[2] = 0;
    auStack_20[4] = 0;
    FUN_0027c080(2,auStack_20,0x1c,0);
    *piVar3 = 2;
    break;
  case 2:
    lVar4 = FUN_0027c2b0();
    if ((lVar4 == 0) && (lVar4 = FUN_0027c330(), lVar4 == -1)) {
      bVar2 = 1;
    }
    else {
      bVar2 = 0;
    }
    if (bVar2 == 1) {
      return 0xffffffff;
    }
    break;
  }
  return 0;
}
#define FUN_003bf610(...) ((u32 (*)(...))FUN_003bf610)(__VA_ARGS__)
