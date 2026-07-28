#include "Kosaka/k_assert.h"

extern const char DAT_006a5f70[];
extern u8 DAT_006a5410[];
extern u8 DAT_006a5414[];
extern u8 DAT_006a5416[];
extern u8 DAT_006a53d0[];
extern int DAT_006a5fe0[];
extern u32 DAT_006a6000[];
extern char DAT_007cd790[];
extern u8 DAT_007ce3f4[];
extern u16 *PTR_DAT_006a5f40[];
extern float DAT_007caf9c;
extern float DAT_007cb000;
extern float DAT_007cb004;
extern u16 _DAT_007cd788;
extern u16 _DAT_007cd78a;
extern u16 u_NDEFGHIJKLM_006a53b0[];
extern void *(*DAT_00960178)();
extern void (*PTR_LAB_007bb7a0[])();
extern void (*PTR_LAB_007bb820[])();
extern void (*DAT_0096017c)();
extern int func_0016deb0(int);
extern int func_0016dba0(int);
extern s8 datGetSocialLinkLevel(int);
#pragma alias datGetSocialLinkLevel_s16 datGetSocialLinkLevel
extern s8 datGetSocialLinkLevel_s16(s16);
extern u8 (*gp0xffffb730)[1];
extern int datSocialLinkLevelIsNotZero(int);
/* FUSION_PROTOS */
#pragma alias memcpy_003d6e60 memcpy
extern void *memcpy_003d6e60(void *dest,const void *src,u32 size);
#pragma alias datPersonaFindSkillIdx_003d6e60 datPersonaFindSkillIdx
extern s32 datPersonaFindSkillIdx_003d6e60(s32 param_1,u16 param_2);
#pragma alias datPersonaSetSkill_003d6e60 datPersonaSetSkill
extern void datPersonaSetSkill_003d6e60(s32 param_1,u16 param_2);
u32 FUN_003d5510(u32 *param_1,u16 *param_2,int param_3,u32 *param_4);
#pragma alias FUN_003d5510_i FUN_003d5510
extern s16 FUN_003d5510_i(u32 *param_1,u16 *param_2,int param_3,u32 *param_4);
s16 FUN_003d5730(void *param_1,int param_2,int param_3,u32 *param_4);
#pragma alias FUN_003d5730_i FUN_003d5730
extern int FUN_003d5730_i(void *param_1,int param_2,int param_3,u32 *param_4);
int FUN_003d58c0(int param_1,int param_2);
s16 FUN_003d5dc0(u32 param_1);
u64 FUN_003d5bb0(u32 param_1);
short FUN_003d5cd0(u32 *param_1);
u8 FUN_003d5e60(void *param_1,void *param_2,void *param_3);
u8 FUN_003d6200(void *param_1,int param_2,u16 *param_3,int param_4);
u32 FUN_003d64a0(void *param_1,u16 param_2,u16 param_3);
u32 FUN_003d6740(void *param_1,void *param_2,void *param_3,void *param_4);
char FUN_003d6910(void *param_1,int param_2,int *param_3);
u8 FUN_003d6ae0(void *param_1,int param_2,int *param_3);
u32 FUN_003d6c90(int param_1);
s32 FUN_003d6e60(int param_1,int param_2);
u32 FUN_003d6f80(int param_1,int param_2,void *param_3);
u32 FUN_003d71d0(u32 *param_1,u8 *param_2,u16 *param_3);
u64 FUN_003d72f0(u16 *param_1);
void FUN_003d74f0(int param_1,int param_2,int param_3);
#pragma alias FUN_003d74f0_i FUN_003d74f0
extern void FUN_003d74f0_i(int param_1, int param_2, int param_3);
u32 FUN_003d7ac0(u8 param_1,u8 param_2,u16 *param_3);
#pragma alias FUN_003d7ac0_u8 FUN_003d7ac0
extern u32 FUN_003d7ac0_u8(u8 param_1,u8 param_2,u16 *param_3);
u32 FUN_003d7da0(u8 param_1,u8 param_2,u16 *param_3);
u32 FUN_003d8080(int param_1,int param_2,int param_3);
u32 FUN_003d8260(int param_1,u32 param_2);
u32 FUN_003d8370(int param_1,u32 param_2,u32 param_3);
u32 FUN_003d84c0(u64 param_1,int param_2);
u32 FUN_003d8630(int param_1,int param_2);
void FUN_003d8850();
typedef struct Fcm982Node Fcm982Node;
typedef struct Fcm982Item Fcm982Item;
typedef struct Fcm982Thing Fcm982Thing;
typedef struct Fcm982Chain Fcm982Chain;
typedef struct Fcm982Ctx Fcm982Ctx;
typedef struct Fcm982Root Fcm982Root;
typedef struct Fcm982Result Fcm982Result;
struct Fcm982Thing {
  u8 pad0[0x8]; void *unk8; u8 padc[0x14]; void *unk1c;
  u8 pad20[0x40]; void *unk60;
};
struct Fcm982Node {
  u8 pad0[0x10]; Fcm982Node *unk10; Fcm982Item *unk14;
};
struct Fcm982Item {
  u8 pad0[0x1c]; Fcm982Thing *unk1c;
};
struct Fcm982Chain {
  u8 pad0[0xc]; int unkc; u8 pad10[0x1c]; Fcm982Node *unk2c;
};
struct Fcm982Ctx {
  u8 pad0[4]; Fcm982Node *unk4; u8 pad8[4]; Fcm982Node *unkc;
  u8 pad10[0x14]; Fcm982Chain *unk24;
};
struct Fcm982Root {
  u8 pad0[8]; void *unk8; Fcm982Ctx *unkc;
};
struct Fcm982Result {
  u8 pad0[0x1a]; s16 unk1a; u8 pad1c[2]; s16 unk1e;
  u8 pad20[0xa]; s16 unk2a; u8 pad2c[8]; void *unk34;
};
typedef struct FcmDispatchWork FcmDispatchWork;
typedef struct FcmDispatchOwner FcmDispatchOwner;
typedef struct FcmDispatchLink FcmDispatchLink;
typedef struct FcmDispatchMeta FcmDispatchMeta;
typedef struct FcmDispatchNode FcmDispatchNode;
typedef struct FcmDispatchResult FcmDispatchResult;
struct FcmDispatchWork {
  u32 flags;
  s32 mode;
  u8 pad8[4];
  s32 capacity;
  s32 used;
  FcmDispatchOwner *owners;
  void **values;
  u8 pad1c[0x190];
  void *result;
};
struct FcmDispatchOwner {
  u8 pad0[4];
  FcmDispatchLink *links;
  u8 pad8[4];
  FcmDispatchLink *root;
};
struct FcmDispatchLink {
  u8 pad0[0x10];
  FcmDispatchLink *next;
  FcmDispatchMeta *payload;
};
struct FcmDispatchMeta {
  u8 pad0[0x1c];
  FcmDispatchNode *data;
};
struct FcmDispatchNode {
  u8 pad0[0x60];
  void *callback_target;
};
struct FcmDispatchResult {
  u8 pad0[0x34];
  void *payload;
};
extern FcmDispatchResult *FUN_003e0260();
extern Fcm982Result *FUN_003e0330(void *param_1,int param_2,int param_3,int param_4);
void FUN_003d9820(Fcm982Root *arg0,u32 arg1,u32 arg2);
void FUN_003d9cc0(int param_1);
void FUN_003d9ea0(int param_1);
typedef int (*code)(...);
extern void fclCombineList003db5e0(void);
extern void fclCombineList003dc210(void);
extern void fclCombineList003dd800(void);
extern void fclCombineList003deb80(void);
extern void fclCombineList003dec00(void);

u32 FUN_003c3f80();
u32 FUN_0017d800();
u32 FUN_00488f30();
u32 FUN_001749a0(u32 param_1);
void FUN_003dff00(s32 param_1);
s8 FUN_0016dba0(s32 param_1);
extern s32 DAT_006a5fc0[];
extern char DAT_006a4ba0[];
extern char DAT_006a4e10[];
extern char DAT_006a5630[];
extern char DAT_006a5f44[];
extern u32 DAT_007ce420;

// FUN_003d5850
s32 fclCombineMisc003d5850(s32 param_1)
{
    s32 local[8];
    s32* src;
    s32* dst;
    s32 count;
    s32 temp;

    src = DAT_006a5fc0;
    dst = local;
    count = 5;
    do {
        temp = *src;
        src++;
        count--;
        *dst = temp;
        dst++;
    } while (count > 0);
    return local[param_1];
}

// FUN_003d58a0
void fclCombineMisc003d58a0(void)
{
    FUN_003c3f80();
}

// FUN_003d5c90
char* fclCombineMisc003d5c90(void)
{
    if (FUN_0017d800() != 0) {
        return DAT_006a4e10;
    }
    return DAT_006a4ba0;
}


// FUN_003d7180
u32 fclCombineMisc003d7180(void)
{
    return (s32)(((FUN_00488f30() % 0xffff) * 1000) / 0xffff) < 500;
}

// FUN_003d74b0
s32 fclCombineMisc003d74b0(u32 param_1)
{
    u8* base;

    base = (u8*)DAT_007ce420;
    return *(s32*)(DAT_006a5630 + (u32)base[(param_1 & 0xffff) * 0xe + 0xd] * 4);
}
// FUN_003d7a30
s32 fclCombineMisc003d7a30(u32 *param_1, void *param_2, s32 param_3)
{
    s32 idx;
    s32 link;

    idx = (u32)*(u16 *)((u8 *)param_1 + 2) * 0xe;
    link = func_0016deb0((*gp0xffffb730)[idx + 2]);
    func_0016dba0(link);
    FUN_003d74f0_i((int)param_1, (int)param_2, param_3);
    return 0;
}


// FUN_003d8230
u32 fclCombineMisc003d8230(s32 param_1)
{
    return FUN_001749a0(*(u16*)(param_1 + 6)) != 0;
}

// FUN_003d8830
s32 fclCombineMisc003d8830(s32 param_1)
{
    return *(s32*)(DAT_006a5f44 + param_1 * 8);
}

// FUN_003d9c90
void fclCombineMisc003d9c90(s32 param_1, s32 param_2)
{
    FUN_003dff00(*(s32*)(*(s32*)(*(s32*)(param_2 + 0x14) + 0x1c) + 0x60));
}

// HARVESTED 3D-42FF

// FUN_003D5510 NONMATCHING


u32 FUN_003d5510(u32 *param_1,u16 *param_2,int param_3,u32 *param_4)



{

  u32 uVar1;

  u8 bVar2;

  u32 uVar3;

  u32 uVar4;

  u32 uVar5;

  u32 uVar6;

  short sVar7;

  short sVar8;

  short sVar9;

  int iVar10;

  short *psVar11;

  short *psVar12;
  u32 uVar12;
  u8 *puVar14;
  u32 *puVar13;

  

  if (((param_1 == 0) || (param_2 == 0)) || (param_4 == 0)) {

    K_Assert(DAT_006a5f70,0x28);

  }

  psVar11 = (short *)param_2;

  if (*param_2 == 0) {

    uVar4 = 0;

  }

  else {

    uVar6 = 0;

    sVar9 = 0;
    psVar12 = psVar11 + 2;
    puVar13 = (u32 *)param_1;

    for (sVar8 = 0, iVar10 = 0; iVar10 < 8; sVar8 = sVar8 + 1, iVar10 = (int)sVar8) {


      uVar5 = ((long)psVar12[iVar10 + 2] << 0x36) >> 0x36;

      if (uVar5 != 0) {

        puVar14 = (u8 *)DAT_007ce420;
        for (sVar7 = 0; bVar2 = 0, sVar7 < 0xc; sVar7 = sVar7 + 1) {

          uVar1 = *(u32 *)((int)param_4 + sVar7 * 0xc + 4);

          if (uVar1 != 0) {

            uVar12 = (u32)*(u16 *)(uVar1 + 2);

            uVar3 = 1 << ((int)sVar7 & 0x1fU);

            if ((uVar6 & uVar3) == 0) {

              if ((long)*(char *)((int)psVar12 + iVar10 * 2 + 5) << 0x39 < 0) {

                uVar12 = (u32)puVar14[(u32)*(u16 *)(uVar1 + 2) * 0xe + 2];

              }
              if (uVar12 == uVar5) {

                puVar13[iVar10 + 2] = uVar1;

                uVar6 = uVar6 | uVar3;

                sVar9 = sVar9 + 1;

                bVar2 = 1;

                break;

              }

            }

          }

        }

        if (((long)*(char *)((int)psVar12 + iVar10 * 2 + 5) << 0x38 < 0) && (!bVar2)) {

          *puVar13 = *puVar13 | 1;

        }
      }

    }

    if (sVar9 >= param_3) {

      uVar4 = 1;

    }

    else {

      *puVar13 = *puVar13 | 1;

      uVar4 = 1;

    }

  }

  return uVar4;

}

// FUN_003D5730


s16 FUN_003d5730(void *param_1,int param_2,int param_3,u32 *param_4)
{
    s16 uVar1;
    s32 count;
    u16 *psVar3;

    if (param_1 == 0) {
        K_Assert("fclCombineMisc.c",0x58);
    }
    count = *(int *)(DAT_006a5f44 + param_2 * 8);
    if (count > param_3) {
        goto valid_index;
    }
    return 0;
valid_index:
    psVar3 = (u16 *)((u8 *)((PTR_DAT_006a5f40)[param_2 * 2]) + param_3 * 0x20);
    if (FUN_003d5bb0(*psVar3) == 0) {
        return 0;
    }
    if (*psVar3 == 0) {
        return 0;
    }
    memset(param_1,0,0x28);
    *(u16 **)((u8 *)param_1 + 4) = psVar3;
    uVar1 = FUN_003d5510_i(param_1,psVar3,param_2 + 2,param_4);
    return uVar1;
}

// FUN_003D58C0


int FUN_003d58c0(int param_1,int param_2)
{
  return (int)((((float)param_2 + ((float)datGetSocialLinkLevel_s16(param_1) / 2.5f + 1.0f)) *
                ((float)param_2 + ((float)datGetSocialLinkLevel_s16(param_1) / 2.5f + 1.0f)) *
                ((float)param_2 + ((float)datGetSocialLinkLevel_s16(param_1) / 2.5f + 1.0f)) -
                (float)(param_2 * param_2 * param_2)) *
               DAT_007caf9c *
               ((DAT_007cb004 + 0.0f) - DAT_007cb000 * (float)param_2) +
               15.0f);
}

// FUN_003D5A40 NONMATCHING


u32 FUN_003d5a40(u16 *param_1,u16 param_2,u16 *param_3,short param_4,void *param_5)



{

  u8 bVar1;

  u32 uVar2;

  int iVar3;

  u32 uVar4;

  u32 uVar5;

  s32 sVar6;

  s32 sVar7;

  s32 sVar8;

  u32 uVar9;

  u32 uVar10;

  

  if (*param_1 == 0) {

    uVar2 = 0;

  }

  else {

    sVar8 = 0;

    uVar2 = 0;

    for (sVar7 = 0; sVar7 < 8; sVar7 = sVar7 + 1) {

      iVar3 = sVar7 * 2;

      uVar5 = ((long)param_1[sVar7 + 4] << 0x36) >> 0x36;

      if (uVar5 != 0) {

        for (sVar6 = 0; bVar1 = 0, sVar6 < param_4; sVar6 = sVar6 + 1) {

          uVar9 = (u32)sVar6;

          uVar4 = 1 << (uVar9 & 0x1f);

          if ((uVar2 & uVar4) == 0) {

            if ((long)*(char *)((int)param_1 + iVar3 + 9) << 0x39 < 0) {

              uVar10 = (u32)*(u8 *)(DAT_007ce420 + (u32)*(u16 *)(param_3 + uVar9 * 2) * 0xe

                                       + 2);

            }

            else {

              uVar10 = (u32)*(u16 *)(param_3 + uVar9 * 2);

            }

            if (uVar10 == uVar5) {

              uVar2 = uVar2 | uVar4;

              sVar8 = sVar8 + 1;

              bVar1 = 1;

              break;

            }

          }

        }

        if (((long)*(char *)((int)param_1 + iVar3 + 9) << 0x38 < 0) && (!bVar1)) {

          return 0;

        }

      }

    }

    if (param_5 != 0) {

      *(short *)param_5 = sVar8;

    }

  }

  return uVar2;

}

// FUN_003D5BB0


u64 FUN_003d5bb0(u32 param_1)



{

  u32 lVar1;
  int iVar2;
  u32 uVar3;
  u32 uVar4;
  u64 uVar5;
  u8 *puVar6;
  s16 uVar7;
  uVar5 = 1;
  uVar3 = 0;
  uVar4 = param_1 & 0xffff;
  while (uVar3 < 0x43) {
    iVar2 = uVar3 * 8;
    puVar6 = DAT_006a5410 + iVar2;
    if (uVar4 == *(s16 *)(puVar6 + 4)) {
      uVar7 = *(s16 *)(puVar6 + 6);
      if ((uVar7 & 1) != 0) {
        lVar1 = datGetFlag(*(u32 *)puVar6);
        if (lVar1 == 0) {
          return 0;
        }
      } else if ((uVar7 & 2) != 0) {
        uVar5 = 0;
        lVar1 = datGetFlag(*(u32 *)puVar6);
        if (lVar1 == 1) {
          return 1;
        }
      }
    }
    uVar3 = uVar3 + 1;
  }
  return uVar5;
}

// FUN_003D5CD0 NONMATCHING


short FUN_003d5cd0(u32 *param_1)
{
  int lVar1;
  u32 uVar2;
  u32 *puVar3;
  s32 sVar4;
  s32 sVar5;

  sVar4 = 0;
  memset(param_1,0,0x90);
  for (sVar5 = 0; uVar2 = FUN_00175410(), (long)sVar5 < (long)(uVar2 & 0xffff); sVar5 = sVar5 + 1) {
    lVar1 = datPersonaGetHeroPersona(sVar5);
    if (lVar1 != 0) {
      puVar3 = (u32 *)((int)param_1 + sVar4 * 0xc);
      *puVar3 = 0;
      puVar3[1] = (int)lVar1;
      puVar3[2] = DAT_007ce420 + (u32)*(u16 *)((int)lVar1 + 2) * 0xe;
      sVar4 = sVar4 + 1;
    }
  }
  return sVar4;
}
// FUN_003D5DC0


s16 FUN_003d5dc0(u32 param_1)
{
    s32 iVar5;
    s32 iVar4;
    int link;

    iVar4 = 0;
    iVar5 = (param_1 & 0xffff) * 0xe;
    link = func_0016deb0(*(u8 *)(iVar5 + DAT_007ce420 + 2));
    if (datSocialLinkLevelIsNotZero(link) != 0) {
        link = func_0016deb0(*(u8 *)(iVar5 + DAT_007ce420 + 2));
        iVar4 = (s32)datGetSocialLinkLevel(link);
    }
    return u_NDEFGHIJKLM_006a53b0[iVar4];
}

#pragma optimization_level 3
// FUN_003D5E60 NONMATCHING


u8 FUN_003d5e60(void *param_1,void *param_2,void *param_3)



{

  char cVar1;

  char cVar2;

  u8 bVar3;

  u8 bVar4;

  u8 bVar5;

  int *piVar6;

  u8 uVar7;

  int *piVar8;

  int *piVar9;

  short sVar10;

  int iVar11;

  char *pcVar12;

  char *pcVar13;

  int aiStack_20 [4];
  char acStack_8 [6];

  

  piVar8 = (int *)0x10;

  piVar9 = aiStack_20;

  piVar6 = piVar9;

  while (piVar6 != (int *)0x0) {

    *(u8 *)piVar9 = 0;

    piVar9 = (int *)((int)piVar9 + 1);

    piVar8 = (int *)((int)piVar8 + -1);

    piVar6 = piVar8;

  }

  aiStack_20[0] = (int)param_1;

  aiStack_20[1] = (int)param_2;

  aiStack_20[2] = (int)param_3;

  pcVar13 = DAT_007cd790;

  pcVar12 = acStack_8;

  iVar11 = 3;

  do {

    cVar1 = *pcVar13;

    cVar2 = pcVar13[1];

    pcVar13 = pcVar13 + 2;

    iVar11 = iVar11 + -1;

    *pcVar12 = cVar1;

    pcVar12[1] = cVar2;

    pcVar12 = pcVar12 + 2;

  } while (0 < iVar11);

  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {

    K_Assert(DAT_006a5f70,0x131);

  }

  for (sVar10 = 0; sVar10 < 3; sVar10 = sVar10 + 1) {

    bVar3 = *(u8 *)(aiStack_20[acStack_8[sVar10 * 2 + 1]] + 4);

    iVar11 = aiStack_20[acStack_8[sVar10 * 2]];

    if ((*(u8 *)(iVar11 + 4) < bVar3) ||

       ((*(u8 *)(iVar11 + 4) == bVar3 &&

        (*(u8 *)(DAT_007ce420 + (u32)*(u16 *)(aiStack_20[acStack_8[sVar10 * 2 + 1]] + 2) * 0xe

                  + 2) < *(u8 *)(DAT_007ce420 + (u32)*(u16 *)(iVar11 + 2) * 0xe + 2))))) {

      aiStack_20[3] = iVar11;

      cVar1 = acStack_8[sVar10 * 2 + 1];

      aiStack_20[acStack_8[sVar10 * 2]] = aiStack_20[cVar1];

      aiStack_20[cVar1] = aiStack_20[3];

    }

  }

  iVar11 = DAT_007ce420 + 2;

  bVar3 = *(u8 *)(iVar11 + (u32)*(u16 *)(aiStack_20[0] + 2) * 0xe);

  bVar4 = *(u8 *)(iVar11 + (u32)*(u16 *)(aiStack_20[1] + 2) * 0xe);

  bVar5 = *(u8 *)(iVar11 + (u32)*(u16 *)(aiStack_20[2] + 2) * 0xe);

  if (((bVar3 == 0) || (bVar4 == 0)) || (bVar5 == 0)) {

    K_Assert(DAT_006a5f70,0x142);

  }

  if ((bVar4 == 0) || (bVar5 == 0)) {

    K_Assert(DAT_006a5f70,0x80);

  }

  if (bVar4 >= bVar5) {

    bVar4 = *(u8 *)((u32)bVar4 + (u32)bVar5 * 0x16 + 0x6a58e9);

  }

  else {

    bVar4 = *(u8 *)((u32)bVar5 + (u32)bVar4 * 0x16 + 0x6a58e9);

  }

  if (bVar4 != 0) {

    if ((bVar3 == 0) || (bVar4 == 0)) {

      K_Assert(DAT_006a5f70,0x80);

    }

    if (bVar3 >= bVar4) {

      uVar7 = *(u8 *)((u32)bVar3 + (u32)bVar4 * 0x16 + 0x6a5ad9);

    }

    else {

      uVar7 = *(u8 *)((u32)bVar4 + (u32)bVar3 * 0x16 + 0x6a5ad9);

    }

  }

  else {

    uVar7 = 0;

  }

  return uVar7;

}
#pragma optimization_level 2

// FUN_003D6200 NONMATCHING


u8 FUN_003d6200(void *param_1,int param_2,u16 *param_3,int param_4)



{

  u16 uVar1;

  u8 bVar2;

  u8 bVar3;

  int lVar4;

  int iVar5;

  u32 uVar6;

  int iVar7;

  u16 *puVar8;

  int iVar9;

  int iVar10;

  u8 *puVar11;

  short sStack_2;

  

  if (((param_1 == 0) || (param_3 == 0)) || (4 < param_2)) {

    K_Assert(DAT_006a5f70,0x14f);

  }

  iVar10 = (int)param_2;

  puVar8 = (u16 *)(PTR_DAT_006a5f40)[iVar10 * 2];

  iVar7 = *(int *)(DAT_006a5f44 + iVar10 * 8);

  iVar9 = 0;

  do {

    if (iVar7 <= iVar9) {

      return 0;

    }

    sStack_2 = 0;

    lVar4 = FUN_003d5a40(puVar8,(short)param_2 + 2,param_3,param_4,&sStack_2);

    if (sStack_2 < (short)((short)param_2 + 2)) {

      lVar4 = 0;

    }

    if (lVar4 != 0) {

      uVar1 = *puVar8;

      bVar2 = 1;

      for (uVar6 = 0; uVar6 < 0x43; uVar6 = uVar6 + 1) {

        iVar5 = uVar6 * 8;

        puVar11 = DAT_006a5410 + iVar5;

        bVar3 = bVar2;

        if ((u32)uVar1 == (long)*(short *)(puVar11 + 4)) {

          if ((*(s16 *)(puVar11 + 6) & 1) != 0) {

            lVar4 = datGetFlag(*(u32 *)puVar11);

            if (lVar4 == 0) {

              bVar2 = 0;

              break;

            }

          }

          else {

            if ((*(s16 *)(puVar11 + 6) & 2) != 0) {

              lVar4 = datGetFlag(*(u32 *)puVar11);

              bVar2 = 1;

              bVar3 = 0;

              if (lVar4 == 1) break;

            }

          }

        }

        bVar2 = bVar3;

      }

      if (bVar2) {

        FUN_00176680(param_1,*puVar8);

        iVar7 = 0;

        while ((iVar7 < 4 &&

               (((puVar8[iVar7 + 0xc] == 0 || (lVar4 = datPersonaFindSkillIdx(param_1), lVar4 != -1)) ||

                (lVar4 = datPersonaSetSkill(param_1,puVar8[iVar7 + 0xc]), lVar4 != 0))))) {

          iVar7 = iVar7 + 1;

        }

        return *(u8 *)((u32)*(u16 *)((int)param_1 + 2) * 0xe + DAT_007ce420 + 2);

      }

    }

    puVar8 = puVar8 + 0x10;

    iVar9 = iVar9 + 1;

  } while( 1 );

}

// FUN_003D64A0 NONMATCHING






u32 FUN_003d64a0(void *param_1,u16 param_2,u16 param_3)



{

  u8 bVar1;

  u8 bVar2;

  u32 cVar3;

  u32 sVar4;

  u32 uVar5;

  u32 uVar6;

  int iVar7;

  u16 uStack_20[12];

  u16 uStack_4[2];

  

  uStack_4[0] = param_2;

  uStack_4[1] = param_3;

  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {

    K_Assert(DAT_006a5f70,0x175);

  }

  cVar3 = FUN_003d6200(param_1,0,uStack_4,2);

  if (cVar3 != '\0') {

    uVar5 = 2;

  }

  else {

    iVar7 = (u32)param_3 * 0xe;

    bVar1 = *(u8 *)(DAT_007ce420 + 2 + iVar7);

    bVar2 = *(u8 *)(DAT_007ce420 + 2 + (u32)param_2 * 0xe);

    if ((bVar2 == 0) || (bVar1 == 0)) {

      K_Assert(DAT_006a5f70,0x80);

    }

    if (bVar2 < bVar1) {

      cVar3 = *(char *)((u32)bVar1 + (u32)bVar2 * 0x16 + 0x6a56b9);

    }

    else {

      cVar3 = *(char *)((u32)bVar2 + (u32)bVar1 * 0x16 + 0x6a56b9);

    }

    if (cVar3 == '\0') {

      memset(param_1,0,0x34);

      uVar5 = 0;

    }

    else {

      memset(uStack_20,0,0x18);

      uVar6 = ((int)((u32)*(u8 *)(DAT_007ce420 + 3 + (u32)param_2 * 0xe) +
                    (u32)*(u8 *)(DAT_007ce420 + 3 + iVar7)) >> 1) + 1U & 0xff;

      uStack_20[0] = param_2;

      uStack_20[1] = param_3;

      if ((cVar3 == *(char *)(DAT_007ce420 + 2 + (u32)param_2 * 0xe)) &&
         (cVar3 == *(char *)(DAT_007ce420 + 2 + iVar7))) {

        sVar4 = FUN_003d7da0(cVar3,uVar6,uStack_20);

        if (sVar4 == 0) {

          return 0;

        }

      }

      else {

        sVar4 = FUN_003d7ac0(cVar3,uVar6,uStack_20);

        if (sVar4 == 0) {

          return 0;

        }

      }

      FUN_00176680(param_1);

      uVar5 = 1;

    }

  }

  return uVar5;

}

// FUN_003D6740 NONMATCHING


u32 FUN_003d6740(void *param_1,void *param_2,void *param_3,void *param_4)



{

  u8 cVar1;

  u16 sVar2;

  u32 uVar3;

  int iVar4;

  u16 uStack_20;
  u16 uStack_1e;
  u16 uStack_1c;
  u16 uStack_8;
  u16 uStack_6;
  u16 uStack_4;

  

  uStack_8 = *(u16 *)((int)param_2 + 2);

  uStack_6 = *(u16 *)((int)param_3 + 2);

  uStack_4 = *(u16 *)((int)param_4 + 2);

  if ((((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) || (param_4 == 0)) {

    K_Assert(DAT_006a5f70,0x1a0);

  }

  cVar1 = FUN_003d6200(param_1,1,&uStack_8,3);

  if (cVar1 == '\0') {

    cVar1 = FUN_003d5e60(param_2,param_3,param_4);

    if (cVar1 == '\0') {

      memset(param_1,0,0x34);

      uVar3 = 0;

    }

    else {

      memset(&uStack_20,0,0x18);

      uStack_20 = *(u16 *)((int)param_2 + 2);

      uStack_1e = *(u16 *)((int)param_3 + 2);

      uStack_1c = *(u16 *)((int)param_4 + 2);

      iVar4 = DAT_007ce420 + 3;

      sVar2 = FUN_003d7ac0(cVar1,((u32)*(u8 *)(iVar4 + (u32)uStack_1c * 0xe) +
                                 (u32)*(u8 *)(iVar4 + (u32)uStack_20 * 0xe) +
                                 (u32)*(u8 *)(iVar4 + (u32)uStack_1e * 0xe)) / 3 + 5 & 0xff,
                           &uStack_20);

      if (sVar2 != 0) {

        FUN_00176680(param_1);

        uVar3 = 1;

      }

      else {

        uVar3 = 0;

      }

    }

  }

  else {

    uVar3 = 2;

  }

  return uVar3;

}

// W212: restoring helper-failure early returns measured nd168 -> nd193 (396 -> 456 bytes); rejected.
// FUN_003D6910 NONMATCHING


char FUN_003d6910(void *param_1,int param_2,int *param_3)
{
  char cVar1;
  int iVar2;
  int *piVar5;
  int *piVar3;
  int iVar4;
  int iVar6;
  u16 auStack_10 [8];
  int aiStack_30 [8];

  piVar5 = DAT_006a5fe0;
  piVar3 = aiStack_30;
  iVar6 = 5;
  do {
    iVar4 = *piVar5;
    piVar5 = piVar5 + 1;
    iVar6 = iVar6 + -1;
    *piVar3 = iVar4;
    piVar3 = piVar3 + 1;
  } while (0 < iVar6);
  if ((param_3 == 0) || (4 < param_2)) {
    K_Assert("fclCombineMisc.c",0x1c2);
  }
  memset(param_1,0,0x34);
  iVar2 = aiStack_30[(int)param_2];
  piVar3 = (int *)param_3;
  if (param_2 != 1) {
    if (param_2 != 0) {
      iVar4 = 0;
      do {
        if (piVar3[iVar4] != 0) {
          auStack_10[iVar4] = *(u16 *)(piVar3[iVar4] + 2);
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2);
      cVar1 = FUN_003d6200(param_1,param_2,auStack_10,iVar2);
      cVar1 = 2;
    }
    else {
      cVar1 = FUN_003d64a0(param_1,*(u16 *)(*piVar3 + 2),*(u16 *)(piVar3[1] + 2));
    }
  }
  else {
    cVar1 = FUN_003d6740(param_1,(void *)*piVar3,(void *)piVar3[1],(void *)piVar3[2]);
  }
  FUN_00176ac0(param_1,param_3,iVar2);
  return cVar1;
}

// FUN_003D6AE0 NONMATCHING


u8 FUN_003d6ae0(void *param_1,int param_2,int *param_3)



{

  u16 sVar1;

  u32 uVar2;

  int uVar3;

  u8 cVar4;

  u8 bVar5;

  int iVar6;
  int iVar7;
  int copyCount;


  u32 *puVar8;

  u32 *puVar9;

  u32 *puVar10;

  u32 auStack_20 [8];

  struct {
    u8 prefix[12];
    u16 values[8];
    u8 deltas[24];
  } scratch;

  

  puVar9 = DAT_006a6000;

  puVar8 = auStack_20;

  copyCount = 5;

  do {

    uVar2 = *puVar9;

    puVar9 = puVar9 + 1;

    copyCount = copyCount + -1;

    *puVar8 = uVar2;

    puVar8 = puVar8 + 1;

  } while (0 < copyCount);

  memset(param_1,0,0x54);

  memset(&scratch,0,0x34);

  puVar10 = (u32 *)param_1;

  cVar4 = FUN_003d6910(puVar10 + 1,param_2,param_3);

  if (cVar4 == '\x02') {

    *puVar10 = *puVar10 | 4;

  }

  memcpy(&scratch,puVar10 + 1,0x34);

  fclCombineMisc003d7a30(puVar10 + 1,param_3,auStack_20[(int)param_2]);

  uVar3 = *(u8 *)(puVar10 + 2);

  bVar5 = datGetLevel(1);

  if (bVar5 < uVar3) {

    *puVar10 = *puVar10 | 2;

  }

  for (iVar7 = 0; iVar7 < 5; iVar7 = iVar7 + 1) {

    *(u8 *)((int)puVar10 + iVar7 + 0x38) =

         *(u8 *)((int)puVar10 + iVar7 + 0x20) - scratch.deltas[iVar7];

  }

  for (iVar7 = 0; iVar7 < 8; iVar7 = iVar7 + 1) {

    iVar6 = iVar7 * 2;

    sVar1 = *(u16 *)((int)puVar10 + iVar6 + 0x10);

    if (sVar1 != scratch.values[iVar7]) {

      *(u16 *)((int)puVar10 + iVar6 + 0x3e) = sVar1;

    }

    else {

      *(u16 *)((int)puVar10 + iVar6 + 0x3e) = 0;

    }

  }

  return cVar4;

}

// FUN_003D6C90 NONMATCHING








u32 FUN_003d6c90(int param_1)



{

  int iVar1;

  int lVar2;

  

  lVar2 = datGetFlag(0xbdd);

  if (lVar2 == 0) {

    if (param_1 == 2) {

      RpRandom();

    }

    else if (param_1 == 1) {

      iVar1 = RpRandom();

      if ((iVar1 % 0xffff << 10) / 0xffff < 0x20) {

        return 1;

      }

    }

    else if ((param_1 == 0) && (iVar1 = RpRandom(), (iVar1 % 0xffff << 0xc) / 0xffff < 0x40)) {

      return 1;

    }

  }

  else if (param_1 == 2) {

    RpRandom();

  }

  else if (param_1 == 1) {

    iVar1 = RpRandom();

    if (((iVar1 % 0xffff) * 9) / 0xffff < 3) {

      return 1;

    }

  }

  else if ((param_1 == 0) && (iVar1 = RpRandom(), ((iVar1 % 0xffff) * 0x24) / 0xffff < 6)) {

    return 1;

  }

  return 0;

}
// b210 floor: at +0x78/+0x7c and +0x94/+0x98 candidate emits a0 then a1,
// while retail emits the identical two call arguments in a1 then a0 order.
// FUN_003D6E60 NONMATCHING
s32 FUN_003d6e60(s32 param_1,s32 param_2)
{
  u8 sp50[0x34];
  s32 temp_2;
  s32 var_16;
  s32 var_5;
  u32 temp_19;
  u16 temp_3;
  u8 *temp_4;
  void *dest;

  dest = sp50;
  /* Removing this barrier worsens FUN_003d6e60 (nd16 -> nd22) - measured W164. */
  asm ("" : "+r"(dest));
  memcpy_003d6e60(dest,(void *)(param_1 + 4),0x34);
  var_16 = 0;
  goto outer_check;
outer_body:
  temp_2 = var_16 * 2;
  temp_19 = *(u16 *)(param_2 + temp_2 + 0x3e);
  if (temp_19 != 0) {
    if (datPersonaCountValidSkills(param_1 + 4) >= 8) {
      return 0;
    }
    if (datPersonaFindSkillIdx_003d6e60(param_1 + 4,temp_19) == -1) {
      datPersonaSetSkill_003d6e60(param_1 + 4,temp_19);
    }
  }
outer_increment:
  var_16 += 1;
outer_check:
  if (var_16 < 8) {
    goto outer_body;
  }
  var_5 = 0;
  goto inner_check;
inner_body:
  temp_2 = var_5 * 2;
  temp_4 = (u8 *)(param_1 + temp_2);
  temp_3 = *(u16 *)(temp_4 + 0x10);
  if (temp_3 != *(u16 *)(sp50 + temp_2 + 0xc)) {
    *(u16 *)(temp_4 + 0x3e) = temp_3;
  }
  else {
    *(u16 *)(temp_4 + 0x3e) = 0U;
  }
inner_increment:
  var_5 += 1;
inner_check:
  if (var_5 < 8) {
    goto inner_body;
  }
  return 0;
}

// FUN_003D6F80 NONMATCHING


u32 FUN_003d6f80(int param_1,int param_2,void *param_3)



{

  u8 bVar1;

  u8 bVar2;

  u32 sVar3;

  int iVar4;

  int iVar5;

  u32 uVar6;

  u32 uVar7;

  s32 lVar8;

  

  if ((param_2 == 0) || (param_1 == 0)) {

    K_Assert(DAT_006a5f70,0x2b8);

  }

  memset(param_1,0,0x54);

  do {

    iVar4 = RpRandom();

    iVar5 = RpRandom();

    uVar6 = datGetLevel(1);

    uVar6 = ((uVar6 & 0xff) + ((iVar5 % 0xffff) * 0xc) / 0xffff) - 10;

    if ((int)uVar6 < 1) {

      uVar6 = 1;

    }

    else if (99 < (int)uVar6) {

      uVar6 = 99;

    }

    sVar3 = FUN_003d7ac0_u8((u8)(((iVar4 % 0xffff) * 0x13) / 0xffff + 2U & 0xff),
                            (u8)(uVar6 & 0xff),param_3);

    lVar8 = FUN_001749a0(sVar3);

  } while ((lVar8 != 0) || (*(short *)((int)param_2 + 6) == sVar3));

  if (sVar3 != 0) {

    iVar4 = (int)param_1;

    FUN_00176680(iVar4 + 4,sVar3);

    bVar1 = *(u8 *)(iVar4 + 8);

    uVar6 = datGetLevel(1);

    if (((int)(u32)bVar1 < (int)((uVar6 & 0xff) - 10)) || ((uVar6 & 0xff) + 1 < (u32)bVar1)) {

      bVar2 = 0;

    }

    else {

      bVar2 = 1;

    }

    if (bVar2) {

      FUN_003d6e60(param_1,param_2);

      FUN_00176c80(iVar4 + 4,(int)param_2 + 4);

      uVar7 = 1;

    }

    else {

      uVar7 = 0;

    }

  }

  else {

    uVar7 = 0;

  }

  return uVar7;

}

// FUN_003D71D0 NONMATCHING


u32 FUN_003d71d0(u32 *param_1,u8 *param_2,u16 *param_3)
{
  u16 sVar2;
  u32 cVar1;
  u32 uVar3;

  if ((param_2 == 0) || (param_1 == 0)) {
    K_Assert(DAT_006a5f70,0x2e5);
  }
  memset(param_1,0,0x54);
  cVar1 = datGetLevel(1);
  sVar2 = FUN_003d7da0(1,cVar1 + 3,param_3);
  if (sVar2 == 0) {
    uVar3 = 0;
  } else {
    if ((FUN_001749a0(sVar2) == 0) && (*(u16 *)(param_2 + 6) != sVar2)) {
      FUN_00176680(param_1 + 1,sVar2);
      FUN_003d6e60((int)param_1,(int)param_2);
      FUN_00176c80(param_1 + 1,param_2 + 4);
      uVar3 = 1;
    } else {
      uVar3 = 0;
    }
  }
  return uVar3;
}

// FUN_003D72F0 NONMATCHING






u64 FUN_003d72f0(u16 *param_1)



{

  short sVar1;

  u8 bVar2;

  u8 bVar3;

  u32 uVar4;

  int iVar5;

  u32 uVar6;

  u32 uVar7;

  

  uVar6 = func_0016deb0(*(u8 *)((u32)param_1[1] * 0xe + DAT_007ce420 + 2));

  datGetSocialLinkLevel(uVar6);

  bVar3 = datGetLevel(1);

  if (9 < bVar3) {

    uVar4 = clndGetCurrentMoonPhase();

    sVar1 = *(short *)(DAT_006a53d0 + (uVar4 & 0xff) * 2);

    bVar3 = *(u8 *)((u32)param_1[1] * 0xe + DAT_007ce420 + 0xc);

    iVar5 = RpRandom();

    if ((u32)(((iVar5 % 0xffff) * 100) / 0xffff) < (u32)((int)((u32)bVar3 * (int)sVar1) / 100)) {

      bVar2 = 0;

      while (!bVar2) {

        if ((u32)param_1[1] == (long)_DAT_007cd788) {

          uVar7 = (u32)_DAT_007cd78a;

          goto LAB_003d7430;

        }

        bVar2 = 1;

      }

      uVar7 = 0xffffffffffffffff;

LAB_003d7430:

      if (uVar7 == 0xffffffffffffffff) {

        uVar7 = 0;

      }

      *param_1 = *param_1 | 4;

      iVar5 = RpRandom();

      if (uVar7 <= (u32)(((iVar5 % 0xffff) * 1000) / 0xffff)) {

        *param_1 = *param_1 | 8;

      }

    }

  }

  return 0;

}

// FUN_003D74F0 NONMATCHING


void FUN_003d74f0(int param_1,int param_2,int param_3)



{

  char cVar1;

  short sVar2;

  u16 uVar3;

  u16 uVar4;

  int iVar5;

  int iVar6;

  s32 uVar7;
  s32 lVar8;
  int *uVar9;
  s32 lVar10;

  int iVar11;

  s32 lVar12;

  int iVar13;

  int *piVar14;

  int iVar15;

  int iVar16;

  

  if (((param_1 == 0) || (param_2 == 0)) || (param_3 < 1)) {

    K_Assert(DAT_006a5f70,0x3a6);

  }

  lVar12 = 0;

  uVar7 = FUN_003c44d0(0,0,0,0);

  iVar5 = 0;

  while( 1 ) {

    iVar11 = (int)uVar7;

    if (param_3 <= iVar5) break;

    for (iVar6 = 0; iVar6 < 8; iVar6 = iVar6 + 1) {

      uVar3 = *(u16 *)(*(int *)((int)param_2 + iVar5 * 4) + iVar6 * 2 + 0xc);

      if (uVar3 != 0) {

        lVar12 = lVar12 + 1;

        lVar10 = datPersonaFindSkillIdx(param_1,uVar3);

        if ((lVar10 == -1) && (lVar10 = FUN_003c4bf0(uVar7,iVar11 + 4,uVar3), lVar10 == 0)) {

          if (param_1 == 0) {

            K_Assert(DAT_006a5f70,0x387);

          }

          lVar10 = (long)*(char *)(DAT_007ce3f4 + (u32)uVar3 * 2);

          if (lVar10 == -1) {

            lVar10 = 0x12;

          }

          uVar4 = *(u16 *)(DAT_007ce420 + (u32)*(u16 *)((int)param_1 + 2) * 0xe + 10);

          sVar2 = *(short *)((int)lVar10 * 2 + ((u32)uVar4 * 0x12 + (u32)uVar4) * 2 + 0x6a48f0);

          lVar10 = datGetScenarioMode();

          if (lVar10 != 0) {

            cVar1 = (DAT_006a4e10)[uVar3];

          }

          else {

            cVar1 = (DAT_006a4ba0)[uVar3];

          }

          if (cVar1 != '\0') {

            iVar16 = (sVar2 * 10) / (int)cVar1;

          }

          else {

            iVar16 = 0;

          }

          if (iVar16 != 0) {

            iVar16 = FUN_003c4910(uVar7,0,0);

            *(u32 *)(iVar16 + 4) = (u32)uVar3;

          }

        }

      }

    }

    iVar5 = iVar5 + 1;

  }

  if ((lVar12 == 0) || (*(short *)(iVar11 + 0x10) == 0)) {

    FUN_003c45f0(uVar7);

  }

  else {

    for (iVar5 = 8; -1 < iVar5; iVar5 = iVar5 + -1) {

      if (*(char *)(iVar5 * 2 + 0x6a48d0) <= lVar12) {

        lVar10 = (long)*(char *)(iVar5 * 2 + 0x6a48d1);

        goto LAB_003d7790;

      }

    }

    lVar10 = 0;

LAB_003d7790:

    iVar5 = datPersonaCountValidSkills(param_1);

    lVar8 = (long)(8 - iVar5);

    if (lVar8 != 0) {

      if (lVar8 < lVar10) {

        lVar10 = lVar8;

      }

      uVar9 = (*DAT_00960178)(lVar12 << 2,0x40000);

LAB_003d79d4:

      if (lVar10 != 0) {

        iVar6 = 0;

        iVar16 = 0;

        iVar5 = *(int *)(iVar11 + 4);

        if (iVar5 == 0) goto LAB_003d79dc;

        for (; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x10)) {

          uVar3 = *(u16 *)(iVar5 + 4);

          if (param_1 == 0) {

            K_Assert(DAT_006a5f70,0x387);

          }

          lVar12 = (long)*(char *)(DAT_007ce3f4 + (u32)uVar3 * 2);

          if (lVar12 == -1) {

            lVar12 = 0x12;

          }

          uVar4 = *(u16 *)(DAT_007ce420 + (u32)*(u16 *)((int)param_1 + 2) * 0xe + 10);

          sVar2 = *(short *)((int)lVar12 * 2 + ((u32)uVar4 * 0x12 + (u32)uVar4) * 2 + 0x6a48f0);

          lVar12 = datGetScenarioMode();

          if (lVar12 != 0) {

            cVar1 = (DAT_006a4e10)[uVar3];

          }

          else {

            cVar1 = (DAT_006a4ba0)[uVar3];

          }

          if (cVar1 != '\0') {

            iVar13 = (sVar2 * 10) / (int)cVar1;

          }

          else {

            iVar13 = 0;

          }

          piVar14 = uVar9 + iVar6;
          *piVar14 = iVar13;

          if (iVar13 == 0) {

            K_Assert(DAT_006a5f70,0x3e2);

          }

          iVar16 = iVar16 + *piVar14;

          iVar6 = iVar6 + 1;

        }

        iVar15 = 0;

        iVar13 = 0;

        iVar6 = RpRandom();

        for (iVar5 = *(int *)(iVar11 + 4); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x10)) {

          iVar13 = iVar13 + uVar9[iVar15];

          if ((iVar16 * (iVar6 % 0xffff)) / 0xffff < iVar13) {

            datPersonaSetSkill(param_1,*(u16 *)(iVar5 + 4));

            lVar10 = lVar10 - 1;

            FUN_003c49e0(uVar7,iVar11 + 4,iVar5);

            break;

          }

          iVar15 = iVar15 + 1;

        }

        goto LAB_003d79d4;

      }

LAB_003d79dc:

      FUN_003c45f0(uVar7);

      (*DAT_0096017c)(uVar9);

    }

    else {

      FUN_003c45f0(uVar7);

    }

  }

  return;

}

// FUN_003D7AC0 NONMATCHING


u32 FUN_003d7ac0(u8 param_1,u8 param_2,u16 *param_3)



{

  u8 bVar1;

  u16 uVar2;

  u8 bVar3;


  int lVar5;

  int iVar6;

  u32 uVar7;

  u32 uVar8;

  u32 uVar9;

  u32 uVar10;

  int iVar11;

  u8 *puVar12;

  

  uVar9 = 0;

  uVar8 = 0;

  for (uVar10 = 0; uVar10 < 0xc0; uVar10 = uVar10 + 1) {

    iVar11 = (int)uVar10 * 0xe;

    if (param_1 == (char)((u16 *)(DAT_007ce420 + iVar11))[1]) {

      uVar2 = *(u16 *)(DAT_007ce420 + iVar11);

      if ((uVar2 & 1) != 0) {

        bVar3 = 0;

      }

      else {

        if ((uVar2 & 2) == 0) {

          bVar3 = 1;

        }

        else {

          bVar3 = 0;

        }

      }

      if (bVar3) {

        bVar3 = 1;

        for (uVar7 = 0; uVar7 < 0x43; uVar7 = uVar7 + 1) {

          iVar6 = uVar7 * 8;

          puVar12 = DAT_006a5410 + iVar6;

          if (uVar10 == (long)*(short *)(puVar12 + 4)) {

            if ((*(s16 *)(puVar12 + 6) & 1) != 0) {

              lVar5 = datGetFlag(*(u32 *)puVar12);

              if (lVar5 == 0) {

                bVar3 = 0;

                break;

              }

            }

            else if ((*(s16 *)(puVar12 + 6) & 2) != 0) {

              lVar5 = datGetFlag(*(u32 *)puVar12);

              if (lVar5 == 1) {

                bVar3 = 1;

                break;

              }

              bVar3 = 0;

            }

          }

        }

        if (bVar3) {

          if ((uVar8 == 0) ||

             (*(u8 *)(DAT_007ce420 + (int)uVar8 * 0xe + 3) < *(u8 *)(DAT_007ce420 + iVar11 + 3))

             ) {

            uVar8 = uVar10;

          }

          bVar1 = *(u8 *)(DAT_007ce420 + iVar11 + 3);

          if (param_2 <= bVar1) {

            for (iVar11 = 0; iVar11 < 0xc; iVar11 = iVar11 + 1) {

              if (uVar10 == *(u16 *)(param_3 + iVar11 * 2)) {

                bVar3 = 1;

                goto LAB_003d7cb4;

              }

            }

            bVar3 = 0;

LAB_003d7cb4:

            if ((!bVar3) &&

               ((uVar9 == 0 || (bVar1 < *(u8 *)(DAT_007ce420 + (int)uVar9 * 0xe + 3))))) {

              uVar9 = uVar10;

            }

          }

        }

      }

    }

  }

  if (uVar8 == 0) {

    K_Assert(DAT_006a5f70,0x45b);

  }

  if ((uVar9 == 0) && (*(u8 *)((int)uVar8 * 0xe + DAT_007ce420 + 3) < param_2)) {

    uVar9 = uVar8;

  }

  return uVar9;

}

// FUN_003D7DA0 NONMATCHING


u32 FUN_003d7da0(u8 param_1,u8 param_2,u16 *param_3)



{

  u8 bVar1;

  u16 uVar2;

  u8 bVar3;


  int lVar5;

  int iVar6;

  u32 uVar7;

  u32 uVar8;

  u32 uVar9;

  u32 uVar10;

  int iVar11;

  u8 *puVar12;

  

  uVar9 = 0;

  uVar8 = 0;

  for (uVar10 = 0; uVar10 < 0xc0; uVar10 = uVar10 + 1) {

    iVar11 = (int)uVar10 * 0xe;

    if (param_1 == (char)((u16 *)(DAT_007ce420 + iVar11))[1]) {

      uVar2 = *(u16 *)(DAT_007ce420 + iVar11);

      if ((uVar2 & 1) != 0) {

        bVar3 = 0;

      }

      else {

        if ((uVar2 & 2) == 0) {

          bVar3 = 1;

        }

        else {

          bVar3 = 0;

        }

      }

      if (bVar3) {

        bVar3 = 1;

        for (uVar7 = 0; uVar7 < 0x43; uVar7 = uVar7 + 1) {

          iVar6 = uVar7 * 8;

          puVar12 = DAT_006a5410 + iVar6;

          if (uVar10 == (long)*(short *)(puVar12 + 4)) {

            if ((*(s16 *)(puVar12 + 6) & 1) != 0) {

              lVar5 = datGetFlag(*(u32 *)puVar12);

              if (lVar5 == 0) {

                bVar3 = 0;

                break;

              }

            }

            else if ((*(s16 *)(puVar12 + 6) & 2) != 0) {

              lVar5 = datGetFlag(*(u32 *)puVar12);

              if (lVar5 == 1) {

                bVar3 = 1;

                break;

              }

              bVar3 = 0;

            }

          }

        }

        if (bVar3) {

          if ((uVar8 == 0) ||

             (*(u8 *)(DAT_007ce420 + (int)uVar8 * 0xe + 3) < *(u8 *)(DAT_007ce420 + iVar11 + 3))

             ) {

            uVar8 = uVar10;

          }

          bVar1 = *(u8 *)(DAT_007ce420 + iVar11 + 3);

          if (bVar1 <= param_2) {

            for (iVar11 = 0; iVar11 < 0xc; iVar11 = iVar11 + 1) {

              if (uVar10 == *(u16 *)(param_3 + iVar11 * 2)) {

                bVar3 = 1;

                goto LAB_003d7f94;

              }

            }

            bVar3 = 0;

LAB_003d7f94:

            if ((!bVar3) &&

               ((uVar9 == 0 || (*(u8 *)(DAT_007ce420 + (int)uVar9 * 0xe + 3) < bVar1)))) {

              uVar9 = uVar10;

            }

          }

        }

      }

    }

  }

  if (uVar8 == 0) {

    K_Assert(DAT_006a5f70,0x47c);

  }

  if ((uVar9 == 0) && (*(u8 *)((int)uVar8 * 0xe + DAT_007ce420 + 3) < param_2)) {

    uVar9 = uVar8;

  }

  return uVar9;

}

// FUN_003D8080 NONMATCHING


u32 FUN_003d8080(int param_1,int param_2,int param_3)



{

  u32 uVar1;

  u32 uVar2;

  u8 bVar3;

  u32 uVar4;

  u32 uVar5;

s32 lVar6;

  int iVar7;

  u32 auStack_20 [8];

  

  uVar4 = FUN_001752b0();

  uVar4 = uVar4 & 0xffff;

  bVar3 = 0;

  if (((param_1 == 0) || (param_2 == 0)) || (param_3 == 0)) {

    K_Assert(DAT_006a5f70,0x48d);

  }

  for (iVar7 = 0; iVar7 < param_3; iVar7 = iVar7 + 1) {

    auStack_20[iVar7] = (u32)*(u16 *)(*(int *)((int)param_2 + iVar7 * 4) + 2);

  }

  for (iVar7 = 0; iVar7 < param_3; iVar7 = iVar7 + 1) {

    if (uVar4 == auStack_20[iVar7]) {

      bVar3 = 1;

    }

    else {

      lVar6 = FUN_00174b40(auStack_20[iVar7] & 0xffff);

      if (lVar6 == 0) {

        K_Assert(DAT_006a5f70,0x494);

      }

    }

  }

  iVar7 = (int)param_1;

  lVar6 = FUN_00174e20(*(u16 *)(iVar7 + 6));

  if (lVar6 != 0) {

    uVar1 = *(u16 *)lVar6;

    uVar2 = *(u16 *)(iVar7 + 4);

    memcpy(lVar6,iVar7 + 4,0x34);

    *(u16 *)lVar6 = uVar1 | uVar2;

    if (bVar3) {

      FUN_00175130(*(u16 *)(iVar7 + 6));

      FUN_00174b40(uVar4);

    }

    else {

      FUN_00175130(uVar4);

    }

    uVar5 = 1;

  }

  else {

    uVar5 = 0;

  }

  return uVar5;

}



// FUN_003D8260
u32 FUN_003d8260(int param_1,u32 param_2)



{

  u16 sVar1;

  int iVar2;

s32 lVar3;

  int target;
  s32 uVar4;

  s32 uVar5;

  u8 auStack_40 [64];

  

  uVar5 = 0;

  if (((param_1 == 0) || ((int)param_2 < 0)) || ((int)param_2 >= 0xc)) {

    K_Assert(DAT_006a5f70,0x4ca);

  }

  uVar4 = 0;

  target = (int)param_1 + (int)param_2 * 0xc;

  for (; (int)uVar4 < 0xc; uVar4 = uVar4 + 1) {

    iVar2 = *(int *)((int)param_1 + uVar4 * 0xc + 4);

    if (((iVar2 != 0) && (sVar1 = *(short *)(iVar2 + 2), sVar1 != 0)) &&

       ((uVar4 != param_2 &&

        (lVar3 = FUN_003d64a0(auStack_40,sVar1,

                              *(u16 *)(*(int *)(target + 4) + 2)),
        lVar3 != 0)))) {

      uVar5 = uVar5 | 1 << uVar4;


    }

  }

  return uVar5;

}



// FUN_003D8370
u32 FUN_003d8370(int param_1,u32 param_2,u32 param_3)



{

  int iVar1;

s32 lVar2;
  int target2;
  int target3;
  u32 uVar4;

  u32 uVar3;


  int iVar5;

  u8 auStack_40 [64];

  

  uVar3 = 0;

  if ((((param_1 == 0) || ((int)param_2 < 0)) || ((int)param_2 >= 0xc)) ||
     (((int)param_3 < 0 || ((int)param_3 >= 0xc)))) {

    K_Assert(DAT_006a5f70,0x4dc);

  }


  iVar5 = (int)param_1;

  uVar4 = 0;

  target2 = iVar5 + (int)param_3 * 0xc;
  target3 = iVar5 + (int)param_2 * 0xc;

  for (; (int)uVar4 < 0xc; uVar4 = uVar4 + 1) {

    iVar1 = *(int *)(iVar5 + uVar4 * 0xc + 4);

    if (((iVar1 != 0) && (*(u16 *)(iVar1 + 2) != 0)) &&

       ((uVar4 != param_2 &&

        ((uVar4 != param_3 &&

         (lVar2 = FUN_003d6740(auStack_40,(void *)iVar1,
                                (void *)*(u32 *)(target3 + 4),
                                (void *)*(u32 *)(target2 + 4)), lVar2 != 0)))))) {

      uVar3 = uVar3 | 1 << uVar4;

    }

  }

  return uVar3;

}

// FUN_003D84C0 NONMATCHING


u32 FUN_003d84c0(u64 param_1,int param_2)



{

  u16 uVar1;

  u8 bVar2;

  u8 bVar3;

  int lVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  u32 uVar8;

  u16 *puVar9;

  


  puVar9 = (u16 *)(PTR_DAT_006a5f40)[param_2 * 2];
  for (iVar7 = 0; iVar7 < iVar5; iVar7 = iVar7 + 1) {

    uVar1 = *puVar9;

    bVar2 = 1;

    for (uVar8 = 0; uVar8 < 0x43; uVar8 = uVar8 + 1) {

      iVar6 = uVar8 * 8;

      bVar3 = bVar2;

      if ((u32)uVar1 == *(short *)(DAT_006a5414 + iVar6)) {

        if ((*(u16 *)(DAT_006a5416 + iVar6) & 1) == 0) {

          if ((*(u16 *)(DAT_006a5416 + iVar6) & 2) != 0) {

            lVar4 = datGetFlag(*(u32 *)(DAT_006a5410 + iVar6));

            bVar2 = 1;

            bVar3 = 0;

            if (lVar4 == 1) break;

          }

        }

        else {

          lVar4 = datGetFlag(*(u32 *)(DAT_006a5410 + iVar6));

          if (lVar4 == 0) {

            bVar2 = 0;

            break;

          }

        }

      }

      bVar2 = bVar3;

    }

    if (bVar2) {

      return 1;

    }

    puVar9 = puVar9 + 0x10;

  }

}

// FUN_003D8630 NONMATCHING


u32 FUN_003d8630(int param_1,int param_2)



{

  u16 uVar1;

  u8 bVar2;

  u8 bVar3;

  u32 lVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  u32 uVar8;

  u16 *puVar9;

  u8 *puVar10;

  u16 auStack_20 [15];

  short sStack_2;

  

  for (iVar6 = 0; iVar6 < 0xc; iVar6 = iVar6 + 1) {

    iVar7 = *(int *)(param_1 + iVar6 * 0xc + 4);

    if (iVar7 != 0) {

      auStack_20[iVar6] = *(u16 *)(iVar7 + 2);

    }

  }

  puVar9 = (u16 *)(PTR_DAT_006a5f40)[param_2 * 2];

  iVar6 = *(int *)(DAT_006a5f44 + param_2 * 8);

  iVar7 = 0;

  do {

    if (iVar6 <= iVar7) {

      return 0;

    }

    sStack_2 = 0;

    lVar4 = FUN_003d5a40(puVar9,(short)param_2 + 2,auStack_20,0xc,&sStack_2);

    if (sStack_2 < (short)((short)param_2 + 2)) {

      lVar4 = 0;

    }

    if (lVar4 != 0) {

      uVar1 = *puVar9;

      bVar2 = 1;

      for (uVar8 = 0; uVar8 < 0x43; uVar8 = uVar8 + 1) {

        iVar5 = uVar8 * 8;

        puVar10 = DAT_006a5410 + iVar5;

        bVar3 = bVar2;

        if ((u32)uVar1 == (long)*(short *)(puVar10 + 4)) {

          if ((*(s16 *)(puVar10 + 6) & 1) != 0) {

            lVar4 = datGetFlag(*(u32 *)puVar10);

            if (lVar4 == 0) {

              bVar2 = 0;

              break;

            }

          }

          else {

            if ((*(s16 *)(puVar10 + 6) & 2) != 0) {

              lVar4 = datGetFlag(*(u32 *)puVar10);

              bVar2 = 1;

              bVar3 = 0;

              if (lVar4 == 1) break;

            }

          }

        }

        bVar2 = bVar3;

      }

      if (bVar2) {

        return 1;

      }

    }

    puVar9 = puVar9 + 0x10;

    iVar7 = iVar7 + 1;

  } while( 1 );

}

// FUN_003D8850
void FUN_003d8850(FcmDispatchWork *work,u32 command,u32 mode)
{
  int index;
  FcmDispatchLink *link;
  FcmDispatchResult *result;

  index = 0;
  link = work->owners->links;
  switch (command) {
  case 0:
    if (mode == 0) {
      while (link != 0) {
        FUN_003e0260(link->payload->data->callback_target,0,0,
          index - (index >> 2));
        link = link->next;
        index += 1;
      }
    } else if (mode == 1) {
      while (link != 0) {
        FUN_003e0260(link->payload->data->callback_target,0,1,0);
        link = link->next;
        index += 1;
      }
    }
    break;
  case 1:
    if (mode == 0) {
      while (link != 0) {
        FUN_003e0260(link->payload->data->callback_target,1,0,
          index - (index >> 2));
        link = link->next;
        index += 1;
      }
    } else if (mode == 1) {
      while (link != 0) {
        FUN_003e0260(link->payload->data->callback_target,1,1,0);
        link = link->next;
        index += 1;
      }
    }
    break;
  case 2:
    if (mode == 0) {
      while (link != 0) {
        FUN_003e0260(link->payload->data->callback_target,2,0,index * 3);
        link = link->next;
        index += 1;
      }
    } else if (mode == 1) {
      while (link != 0) {
        FUN_003e0260(link->payload->data->callback_target,2,1,0);
        link = link->next;
        index += 1;
      }
    }
    break;
  case 3:
    if (mode == 0) {
      while (link != 0) {
        FUN_003e0260(link->payload->data->callback_target,3,0,0);
        link = link->next;
        index += 1;
      }
    } else if (mode == 1) {
      while (link != 0) {
        FUN_003e0260(link->payload->data->callback_target,3,1,0);
        link = link->next;
        index += 1;
      }
    }
    break;
  case 4:
    if (mode == 0) {
      FUN_003e0260(work->result,4,0,0);
    } else if (mode == 1) {
      FUN_003e0260(work->result,4,1,0);
    }
    break;
  case 5:
    if (mode == 0) {
      FUN_003e0260(work->result,5,0,0);
    } else if (mode == 1) {
      FUN_003e0260(work->result,5,1,0);
    }
    break;
  case 6:
    if (mode == 0) {
      FUN_003e0260(work->result,6,0,0);
    } else if (mode == 1) {
      FUN_003e0260(work->result,6,1,0);
    }
    break;
  case 7:
    if (mode == 0) {
      while (link != 0) {
        FUN_003e0260(link->payload->data->callback_target,7,0,
          index - (index >> 2));
        link = link->next;
        index += 1;
      }
    } else if (mode == 1) {
      while (link != 0) {
        FUN_003e0260(link->payload->data->callback_target,7,1,0);
        link = link->next;
        index += 1;
      }
    }
    break;
  case 8:
    if (mode == 0) {
      while (link != 0) {
        FUN_003e0260(link->payload->data->callback_target,8,0,0);
        link = link->next;
      }
    } else if (mode == 1) {
      while (link != 0) {
        FUN_003e0260(link->payload->data->callback_target,8,1,0);
        link = link->next;
      }
    }
    break;
  case 9:
    if (mode == 0) {
      FUN_003e0260(work->result,9,0,0);
    } else if (mode == 1) {
      FUN_003e0260(work->result,9,1,0);
    }
    break;
  case 10:
    if (mode == 0) {
      FUN_003e0260(work->result,10,0,0);
    } else if (mode == 1) {
      FUN_003e0260(work->result,10,1,0);
    }
    break;
  case 11:
    if (mode == 0) {
      while (link != 0) {
        FUN_003e0260(link->payload->data->callback_target,11,0,0);
        link = link->next;
      }
    } else if (mode == 1) {
      FUN_003e0260(work->owners->root->payload->data->callback_target,11,1,0);
    }
    break;
  case 12:
    if (mode == 0) {
      FUN_003e0260(work->result,12,0,0);
    } else if (mode == 1) {
      FUN_003e0260(work->result,12,1,0);
    }
    break;
  case 13:
    if (work->capacity == 3) {
      if (mode == 0) {
        FUN_003e0260(work->result,13,0,0);
        FUN_003e0260(work->result,14,1,0);
      } else if (mode == 1) {
        FUN_003e0260(work->result,13,1,0);
      }
    }
    break;
  case 14:
    break;
  case 15:
    if (mode == 0) {
      FUN_003e0260(work->result,15,0,0);
    } else if (mode == 1) {
      FUN_003e0260(work->result,15,1,0);
    }
    break;
  case 16:
  case 17:
  case 18:
  case 19:
  case 20:
  case 21:
    break;
  case 22:
    if (mode == 0) {
      if (work->mode >= 2) {
        FUN_003e0260(work->result,19,0,0);
      } else {
        switch (work->used) {
        case 0:
          FUN_003e0260(work->result,16,0,0);
          break;
        case 1:
          FUN_003e0260(work->result,17,0,0);
          break;
        case 2:
          FUN_003e0260(work->result,18,0,0);
          break;
        default:
          break;
        }
      }
    } else if (mode == 1) {
      if (work->mode >= 2) {
        FUN_003e0260(work->result,19,1,0);
      } else {
        switch (work->used) {
        case 0:
          FUN_003e0260(work->result,16,1,0);
          break;
        case 1:
          FUN_003e0260(work->result,17,1,0);
          break;
        case 2:
          FUN_003e0260(work->result,18,1,0);
          break;
        default:
          break;
        }
      }
    }
    break;
  case 23:
    if (mode == 0) {
      switch (work->used) {
      case 0:
        break;
      case 1:
        FUN_003e0260(work->result,16,0,0);
        break;
      case 2:
        FUN_003e0260(work->result,17,0,0);
        break;
      case 3:
        FUN_003e0260(work->result,18,0,0);
        break;
      default:
        FUN_003e0260(work->result,19,0,0);
        break;
      }
    } else if (mode == 1) {
      switch (work->used) {
      case 0:
        break;
      case 1:
        FUN_003e0260(work->result,16,1,0);
        break;
      case 2:
        FUN_003e0260(work->result,17,1,0);
        break;
      case 3:
        FUN_003e0260(work->result,18,1,0);
        break;
      default:
        FUN_003e0260(work->result,19,1,0);
        break;
      }
    }
    break;
  case 24:
    if (mode == 0) {
      switch (work->used) {
      case 0:
        FUN_003e0260(work->result,17,0,0);
        break;
      case 1:
        FUN_003e0260(work->result,18,0,0);
        break;
      case 2:
        break;
      default:
        FUN_003e0260(work->result,19,0,0);
        break;
      }
    } else if (mode == 1) {
      switch (work->used) {
      case 0:
        FUN_003e0260(work->result,17,1,0);
        break;
      case 1:
        FUN_003e0260(work->result,18,1,0);
        break;
      case 2:
        break;
      default:
        FUN_003e0260(work->result,19,1,0);
        break;
      }
    }
    break;
  case 25:
    if (mode == 0) {
      switch (work->used) {
      case 1:
        result = FUN_003e0260(work->result,20,0,0);
        if (work->values[0] != 0) {
          memcpy(result->payload,work->values[0],0x34);
        }
        break;
      case 2:
        result = FUN_003e0260(work->result,21,0,0);
        if (work->values[1] != 0) {
          memcpy(result->payload,work->values[1],0x34);
        }
        break;
      default:
        break;
      }
    } else if (mode == 1) {
      switch (work->used) {
      case 1:
        FUN_003e0260(work->result,20,1,0);
        break;
      case 2:
        FUN_003e0260(work->result,21,1,0);
        break;
      default:
        break;
      }
    }
    break;
  case 27:
    if (mode == 0) {
      switch (work->used) {
      case 0:
        FUN_003e0260(work->result,20,0,0);
        break;
      case 1:
        FUN_003e0260(work->result,21,0,0);
        break;
      default:
        break;
      }
    } else if (mode == 1) {
      switch (work->used) {
      case 0:
        FUN_003e0260(work->result,20,1,0);
        break;
      case 1:
        FUN_003e0260(work->result,21,1,0);
        break;
      default:
        break;
      }
    }
    break;
  case 26:
    if (mode == 0) {
      switch (work->used) {
      case 2:
        FUN_003e0260(work->result,20,0,0);
        break;
      case 3:
        FUN_003e0260(work->result,21,0,0);
        break;
      default:
        break;
      }
    } else if (mode == 1) {
      switch (work->used) {
      case 2:
        FUN_003e0260(work->result,20,1,0);
        break;
      case 3:
        FUN_003e0260(work->result,21,1,0);
        break;
      default:
        break;
      }
    }
    break;
  case 28:
    if (mode == 0) {
      switch (work->used) {
      case 1:
        result = FUN_003e0260(work->result,20,0,0);
        if (work->values[0] != 0) {
          memcpy(result->payload,work->values[0],0x34);
        }
        break;
      case 2:
      case 3:
        if (work->values[0] != 0) {
          result = FUN_003e0260(work->result,20,0,0);
          memcpy(result->payload,work->values[0],0x34);
        }
        if (work->values[1] != 0) {
          result = FUN_003e0260(work->result,21,0,5);
          memcpy(result->payload,work->values[1],0x34);
        }
        break;
      default:
        break;
      }
    } else if (mode == 1) {
      switch (work->used) {
      case 1:
        FUN_003e0260(work->result,20,1,0);
        break;
      case 2:
      case 3:
        if (work->values[0] != 0) {
          FUN_003e0260(work->result,20,1,0);
        }
        if (work->values[1] != 0) {
          FUN_003e0260(work->result,21,1,0);
        }
        break;
      default:
        break;
      }
    }
    break;
  default:
    break;
  }
}

// FUN_003D9820
void FUN_003d9820(Fcm982Root *arg0,u32 arg1,u32 arg2)
{
  int var_16;
  Fcm982Result *temp_2;
  Fcm982Ctx *temp_7;
  Fcm982Node *var_18;
  Fcm982Node *var_18_2;
  Fcm982Node *var_18_3;
  Fcm982Node *var_18_4;

  var_16 = 0;
  temp_7 = arg0->unkc;
  var_18 = temp_7->unk4;
  switch (arg1) {
  case 0:
    if (arg2 == 0) {
      var_18_2 = temp_7->unk24->unk2c;
      while (var_18_2 != 0) {
        temp_2 = FUN_003e0330(var_18_2->unk14->unk1c->unk8,0,0,
          var_16 - (var_16 >> 2));
        temp_2->unk1a =
          (s16)(var_16 * -arg0->unkc->unk24->unkc);
        var_18_2 = var_18_2->unk10;
        var_16 += 1;
      }
      goto done;
    }
    // fallthrough (arg1==1, unreachable via dispatch - part of case0's chain)
    if (arg2 == 1) {
      var_18_3 = temp_7->unk24->unk2c;
      while (var_18_3 != 0) {
        temp_2 = FUN_003e0330(var_18_3->unk14->unk1c->unk8,0,1,0);
        temp_2->unk1e =
          (s16)(var_16 * -arg0->unkc->unk24->unkc);
        var_18_3 = var_18_3->unk10;
        var_16 += 1;
      }
      goto done;
    }
    // fallthrough (arg1==2, unreachable via dispatch - part of case0's chain)
    if (arg2 == 3) {
      var_18_4 = temp_7->unk24->unk2c;
      while (var_18_4 != 0) {
        temp_2 = FUN_003e0330(var_18_4->unk14->unk1c->unk8,0,1,0);
        temp_2->unk1e = (s16)(var_16 * -arg0->unkc->unk24->unkc);
        if (var_18_4 == arg0->unkc->unkc) {
          temp_2->unk2a = 0xff;
        }
        var_18_4 = var_18_4->unk10;
        var_16 += 1;
      }
      goto done;
    }
  default:
    goto done;
  case 1:
    if (arg2 == 0) {
      while (var_18 != 0) {
        FUN_003e0330(var_18->unk14->unk1c->unk8,1,0,0);
        var_18 = var_18->unk10;
        var_16 += 1;
      }
      goto done;
    }
    // fallthrough (arg1==4, unreachable via dispatch - part of this chain)
    if (arg2 == 1) {
      FUN_003e0330(temp_7->unkc->unk14->unk1c->unk8,1,1,0);
      goto done;
    }
    if (arg2 == 3) {
      FUN_003e0330(temp_7->unkc->unk14->unk1c->unk8,1,1,0);
      goto done;
    }
    goto done;
  case 2:
    if (arg2 == 0) {
      FUN_003e0330(arg0->unk8,2,0,0);
      goto done;
    }
    if (arg2 == 1) {
      FUN_003e0330(arg0->unk8,2,1,0);
      goto done;
    }
    goto done;
  case 3:
    if (arg2 == 0) {
      FUN_003e0330(arg0->unk8,3,0,0);
      goto done;
    }
    if (arg2 == 1) {
      FUN_003e0330(arg0->unk8,3,1,0);
      goto done;
    }
    goto done;
  case 4:
    if (arg2 == 0) {
      FUN_003e0330(arg0->unk8,4,0,0);
      goto done;
    }
    if (arg2 == 1) {
      FUN_003e0330(arg0->unk8,4,1,0);
    }
    goto done;
  case 5:
    if (arg2 == 0) {
      FUN_003e0330(arg0->unk8,5,0,0);
      goto done;
    }
    if (arg2 == 1) {
      FUN_003e0330(arg0->unk8,5,1,0);
      goto done;
    }
    goto done;
  case 6:
    if (arg2 == 0) {
      FUN_003e0330(arg0->unk8,6,0,0);
      goto done;
    }
    if (arg2 == 1) {
      FUN_003e0330(arg0->unk8,6,1,0);
      goto done;
    }
    goto done;
  case 7:
    if (arg2 == 0) {
      FUN_003e0330(arg0->unk8,7,0,0);
      goto done;
    }
    if (arg2 == 1) {
      FUN_003e0330(arg0->unk8,7,1,0);
      goto done;
    }
    goto done;
  }
done:
  ;
}
// FUN_003D9CC0 NONMATCHING


void FUN_003d9cc0(int param_1)



{

  int iVar1;

  int iVar2;

  u32 uVar3;

  u32 uVar4;

  int iVar5;

  int unaff_s1_lo;

  int lVar6;

  int iVar7;

  int iVar8;

  int entry_base;

  

  iVar7 = (int)param_1;

  entry_base = iVar7 + 0x11c;

  iVar1 = *(int *)(iVar7 + 0x14);

  for (iVar5 = 0; iVar5 < 0xc; iVar5 = iVar5 + 1) {

    iVar8 = entry_base + iVar5 * 0xc;

    lVar6 = 0;

    iVar2 = *(int *)(iVar8 + 4);

    if ((iVar2 == 0) || (*(short *)(iVar2 + 2) == 0)) {

      uVar4 = FUN_00175410();

      if (iVar5 < (int)(uVar4 & 0xffff)) {

        lVar6 = FUN_003c5a40(iVar1,*(u16 *)(iVar1 + 0x10) + 1,0x8c,0);

        unaff_s1_lo = *(int *)(*(int *)((int)lVar6 + 0x14) + 0x1c);

        *(u32 *)(unaff_s1_lo + 4) = 0;

        *(u32 *)(unaff_s1_lo + 8) = 0;

      }

    } else {

      lVar6 = FUN_003c5a40(iVar1,*(u16 *)(iVar1 + 0x10) + 1,0x8c,0);

      unaff_s1_lo = *(int *)(*(int *)((int)lVar6 + 0x14) + 0x1c);

      if (*(int *)(iVar7 + 4) == 0) {

        uVar3 = FUN_003d8260(entry_base,iVar5);

        *(u32 *)(unaff_s1_lo + 4) = uVar3;

      }

      *(u32 *)(unaff_s1_lo + 8) = *(u32 *)(iVar8 + 4);

    }

    if (lVar6 != 0) {

      uVar3 = FUN_003dfeb0(param_1);

      *(u32 *)(unaff_s1_lo + 0x60) = uVar3;

    }

  }

  FUN_003c5e80(iVar1,fclCombineList003db5e0);

  FUN_003c5e20(iVar1,fclCombineList003dc210);

  FUN_003c5ee0(iVar1,fclCombineList003dd800);

  FUN_003c5f40(iVar1,fclCombineMisc003d9c90);

  FUN_003c6d40(iVar1,0,0);

  FUN_003c6ee0(iVar1);

  *(u16 *)(iVar7 + 8) = 3;

  return;

}

// FUN_003D9EA0


void FUN_003d9ea0(int param_1)



{

  int iVar1;

  int iVar8;

  u32 uVar2;

  u32 uVar3;

  int iVar4;

  int lVar5;

  int iVar6;

  int iVar0;

  int iVar7;

  int iVar9;

  int iVar10;

  int aiStack_20 [8];

  struct {
    u32 flags;
    u16 *entry;
    int personas[8];
  } scratch;

  

  iVar9 = (int)param_1;

  iVar10 = iVar9 + 0x11c;

  iVar1 = *(int *)(iVar9 + 0x14);

  uVar2 = *(u32 *)(iVar9 + 4);

  for (iVar0 = 0; iVar0 < 0xc; iVar0 = iVar0 + 1) {

  }

  for (iVar7 = 0; iVar4 = fclCombineMisc003d8830(uVar2), iVar7 <= iVar4; iVar7 = iVar7 + 1) {

    lVar5 = FUN_003d5730_i(&scratch,uVar2,iVar7,(u32 *)iVar10);

    if (lVar5 != 0) {

      iVar4 = FUN_003c5a40(iVar1,*(u16 *)(iVar1 + 0x10) + 1,0x8c,0);

      iVar4 = *(int *)(*(int *)(iVar4 + 0x14) + 0x1c);

      *(u32 *)(iVar4 + 4) = 0;

      memcpy(iVar4 + 100,&scratch,0x28);

      iVar8 = 0;

      if ((scratch.flags & 1) != 0) {

        memset(aiStack_20,0,4);

        for (iVar6 = 0; iVar6 < 8; iVar6 = iVar6 + 1) {

          if (((int *)&scratch)[iVar6 + 2] != 0) {

            aiStack_20[iVar8] = ((int *)&scratch)[iVar6 + 2];

            iVar8 = iVar8 + 1;

          }

        }

        FUN_003d6910((void *)(iVar4 + 0x10),uVar2,aiStack_20);

        *(int *)(iVar4 + 8) = iVar4 + 0x10;

      }

      uVar3 = FUN_003dfeb0(param_1);

      *(u32 *)(iVar4 + 0x60) = uVar3;

    }

  }

  FUN_003c5e80(iVar1,fclCombineList003db5e0);

  FUN_003c5e20(iVar1,fclCombineList003deb80);

  FUN_003c5ee0(iVar1,fclCombineList003dec00);

  FUN_003c5f40(iVar1,fclCombineMisc003d9c90);

  FUN_003c6d40(iVar1,0,0);

  FUN_003c6ee0(iVar1);

  *(u16 *)(iVar9 + 8) = 3;

  return;

}
