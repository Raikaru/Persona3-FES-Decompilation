#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))
#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
u64 FUN_00397950(void);
void FUN_00397d60(void);
void FUN_00397ec0(u32 param_1,u32 param_2,u32 param_3,u32 param_4);
u32 FUN_00397f80(u32 param_1,u32 param_2,u32 param_3,u32 param_4);
u8 FUN_00398060(u64 param_1);
void FUN_003980e0(u64 param_1);
u32  FUN_00398140(u32 param_1,u32 *param_2,u32 *param_3,u32 *param_4,int *param_5);
u8 FUN_003982d0(u64 param_1);
void FUN_00398390(u32 *param_1,u32 param_2);
u8 FUN_003983a0(int *param_1);
extern u32 FUN_00386ae0(u32 param_1, u32 param_2);
extern void FUN_00521408();
extern u32 FUN_00195460();
extern u32 FUN_00195540();
extern u32 FUN_00194e10();
extern s32 FUN_003bd8b0(u32 param_1, u32 param_2, u32 param_3);
#pragma alias FUN_00195460_pm FUN_00195460
extern u32 FUN_00195460_pm();
#pragma alias FUN_00195540_pm FUN_00195540
extern u32 FUN_00195540_pm();
#pragma alias FUN_0019d3f0_pm FUN_0019d3f0
extern void FUN_0019d3f0_pm(const char *param_1, u32 param_2);
#pragma alias FUN_00386ae0_pm FUN_00386ae0
extern u32 FUN_00386ae0_pm(u32 param_1, u32 param_2);
#pragma alias FUN_00521408_pm FUN_00521408
extern void FUN_00521408_pm();
#pragma alias FUN_00194e10_pm FUN_00194e10
extern u32 FUN_00194e10_pm();
#pragma alias FUN_0035ae10_pm FUN_0035ae10
extern u32 FUN_0035ae10_pm();
extern u8 DAT_006a11c0[];
extern void FUN_006a11c0(void);
#pragma alias FUN_003bd8b0_pm FUN_003bd8b0
extern s32 FUN_003bd8b0_pm(u32 param_1, u32 param_2, u32 param_3);
#pragma alias FUN_00395000_pm FUN_00395000
extern void FUN_00395000_pm(u32 param_1,u32 param_2,u8 *param_3,u8 *param_4,u8 *param_5,u8 *param_6);
#pragma alias FUN_00100d80_pm FUN_00100d80
extern u32 FUN_00100d80_pm();
#pragma alias FUN_001016b0_pm FUN_001016b0
extern s32 FUN_001016b0_pm(u32 param_1);
#pragma alias FUN_001021c0_pm FUN_001021c0
extern s32 FUN_001021c0_pm(u8 *param_1,u32 *param_2);
#pragma alias FUN_00386c40_pm FUN_00386c40
extern void FUN_00386c40_pm(u32 param_1,u32 param_2);
#pragma alias FUN_00394ce0_pm FUN_00394ce0
extern u32 FUN_00394ce0_pm(int *param_1);
#pragma alias FUN_00394d60_pm FUN_00394d60
extern u32 FUN_00394d60_pm(int *param_1);
#pragma alias FUN_00394df0_pm FUN_00394df0
extern u32 FUN_00394df0_pm(int *param_1);
#pragma alias FUN_00395170_pm FUN_00395170
extern void FUN_00395170_pm(u64 param_1);
#pragma alias FUN_003951a0_pm FUN_003951a0
extern void FUN_003951a0_pm(u32 param_1);
#pragma alias FUN_00395000_pm2 FUN_00395000
extern void FUN_00395000_pm2(u32 param_1,u32 param_2,u8 *param_3,u8 *param_4,u8 *param_5,u8 *param_6);
#pragma alias FUN_003bd9a0_pm2 FUN_003bd9a0
extern u16 FUN_003bd9a0_pm2(u32 param_1,u32 param_2);
#pragma alias FUN_005225a8_pm2 FUN_005225a8
extern void FUN_005225a8_pm2(u32 param_1);
extern u8 DAT_006a10b0[];
#pragma alias DAT_006a10b0_abs DAT_006a10b0
extern u8 DAT_006a10b0_abs[];
extern u8 DAT_006a10d0[];
extern u8 DAT_006a10f0[];
extern u8 DAT_006a1120[];
extern u8 DAT_006a1140[];
extern u8 DAT_006a1170[];
extern u8 DAT_006a1190[];
#pragma alias FUN_00521408_pm2 FUN_00521408
extern void FUN_00521408_pm2(void *param_1,u8 param_2,u32 param_3);
#pragma alias FUN_00100ec0_pm FUN_00100ec0
extern void FUN_00100ec0_pm(u32 param_1);

#define FUN_00395000 FUN_00395000_pm
#define FUN_00100d80 FUN_00100d80_pm
#define FUN_001016b0 FUN_001016b0_pm
#define FUN_001021c0 FUN_001021c0_pm
#define FUN_00386c40 FUN_00386c40_pm
#define FUN_00394ce0 FUN_00394ce0_pm
#define FUN_00394d60 FUN_00394d60_pm
#define FUN_00394df0 FUN_00394df0_pm
#define FUN_00395170 FUN_00395170_pm
#define FUN_003951a0 FUN_003951a0_pm
#define FUN_005225a8 FUN_005225a8_pm2
#define FUN_003bd9a0 FUN_003bd9a0_pm2
/* Region call-cast macros */
#define FUN_00100ec0 FUN_00100ec0_pm
#define FUN_0019d3f0 FUN_0019d3f0_pm
#define FUN_00195460 FUN_00195460_pm
#define FUN_00195540 FUN_00195540_pm
#define FUN_00521408 FUN_00521408_pm2
#define FUN_00397950(...) ((u64 (*)(...))FUN_00397950)(__VA_ARGS__)
#define FUN_00397d60(...) ((void (*)(...))FUN_00397d60)(__VA_ARGS__)
#define FUN_00397ec0(...) ((void (*)(...))FUN_00397ec0)(__VA_ARGS__)
#define FUN_00397f80(...) ((u32 (*)(...))FUN_00397f80)(__VA_ARGS__)
#define FUN_00398060(...) ((u8 (*)(...))FUN_00398060)(__VA_ARGS__)
#define FUN_003980e0(...) ((void (*)(...))FUN_003980e0)(__VA_ARGS__)
#define FUN_00398140(...) ((u32 (*)(...))FUN_00398140)(__VA_ARGS__)
#define FUN_003982d0(...) ((u8 (*)(...))FUN_003982d0)(__VA_ARGS__)
#define FUN_00398390(...) ((void (*)(...))FUN_00398390)(__VA_ARGS__)
#define FUN_003983a0(...) ((u8 (*)(...))FUN_003983a0)(__VA_ARGS__)

#undef FUN_00397950
// FUN_00397950 NONMATCHING


u64 FUN_00397950(void)
{
  u16 uVar1;
  int *piVar2;
  int iVar3;
  s32 lVar4;
  u8 auStack_110 [64];
  u8 auStack_d0 [64];
  u8 auStack_90 [64];
  u8 auStack_50 [64];
  u32 uStack_4;

  piVar2 = (int *)FUN_0035ae10_pm();
  FUN_00395000(piVar2[3],piVar2[4],auStack_110,auStack_d0,auStack_90,auStack_50);
  if (piVar2[2] != 0) {
    iVar3 = *piVar2;
    if (iVar3 == 7) {
      goto done;
    }
    if (1 == iVar3) {
      goto state1_nonzero;
    }
    switch (iVar3) {
    case 0:
      goto state0_nonzero;
    default:
      goto done;
    }

  state0_nonzero:
    piVar2[10] = 0;
    piVar2[0xb] = 0;
    piVar2[0xc] = 0;
    piVar2[0xd] = 0;
    piVar2[0xe] = 0;
    piVar2[0xf] = 0;
    iVar3 = FUN_00100d80(auStack_50);
    piVar2[7] = iVar3;
    *piVar2 = 1;
    goto done;

  state1_nonzero:
    lVar4 = FUN_001016b0(piVar2[7]);
    if (lVar4 == 1) {
      lVar4 = FUN_001021c0(auStack_110,&uStack_4);
      piVar2[0xd] = (int)lVar4;
      if (lVar4 == 0) {
        iVar3 = FUN_00394ce0(piVar2 + 0xd);
        piVar2[10] = iVar3;
      }
      FUN_00386c40(4,uStack_4);
      lVar4 = FUN_001021c0(auStack_d0,&uStack_4);
      piVar2[0xe] = (int)lVar4;
      if (lVar4 == 0) {
        iVar3 = FUN_00394d60(piVar2 + 0xe);
        piVar2[0xb] = iVar3;
      }
      FUN_00386c40(5,uStack_4);
      lVar4 = FUN_001021c0(auStack_90,&uStack_4);
      piVar2[0xf] = (int)lVar4;
      if (lVar4 == 0) {
        iVar3 = FUN_00394df0(piVar2 + 0xf);
        piVar2[0xc] = iVar3;
      }
      FUN_00386c40(6,uStack_4);
      *piVar2 = 7;
    }
    goto done;
  }
  else {
    switch(*piVar2) {
    case 0:
      iVar3 = FUN_00100d80(auStack_110,0);
      piVar2[7] = iVar3;
      *piVar2 = 1;
      break;
    case 1:
      lVar4 = FUN_001016b0(piVar2[7]);
      if (lVar4 == 1) {
        piVar2[10] = 0;
        iVar3 = FUN_001021c0(auStack_110,&uStack_4);
        piVar2[0xd] = iVar3;
        FUN_00386c40(4,uStack_4);
        *piVar2 = 2;
      }
      break;
    case 2:
      if (piVar2[1] == 1) {
        iVar3 = FUN_00394d60(piVar2 + 0xe);
        piVar2[0xb] = iVar3;
        if (piVar2[0xe] == 0) {
          FUN_0019d3f0("mt_evtPMFileReader.c",0x76);
        }
        *piVar2 = 4;
      }
      else {
        iVar3 = FUN_00100d80(auStack_d0,0);
        piVar2[8] = iVar3;
        *piVar2 = 3;
      }
      break;
    case 3:
      lVar4 = FUN_001016b0(piVar2[8]);
      if (lVar4 == 1) {
        *piVar2 = 4;
        piVar2[0xb] = 0;
        iVar3 = FUN_001021c0(auStack_d0,&uStack_4);
        piVar2[0xe] = iVar3;
        FUN_00386c40(5,uStack_4);
      }
      break;
    case 4:
      if (piVar2[1] == 1) {
        iVar3 = FUN_00394df0(piVar2 + 0xf);
        piVar2[0xc] = iVar3;
        if (piVar2[0xf] == 0) {
          FUN_0019d3f0("mt_evtPMFileReader.c",0x91);
        }
        *piVar2 = 6;
      }
      else {
        iVar3 = FUN_00100d80(auStack_90,0);
        piVar2[9] = iVar3;
        *piVar2 = 5;
      }
      break;
    case 5:
      lVar4 = FUN_001016b0(piVar2[9]);
      if (lVar4 == 1) {
        *piVar2 = 6;
        piVar2[0xc] = 0;
        iVar3 = FUN_001021c0(auStack_90,&uStack_4);
        piVar2[0xf] = iVar3;
        FUN_00386c40(6,uStack_4);
      }
      break;
    case 6:
      uVar1 = FUN_003bd9a0(piVar2[3],piVar2[4]);
      *(u16 *)(piVar2 + 6) = uVar1;
      if (*(u16 *)(piVar2 + 6) > 0) {
        FUN_00395170(*(u16 *)(piVar2 + 6));
      }
      *piVar2 = 7;
      FUN_005225a8((u32)(uintptr_t)DAT_006a10b0_abs);
      break;
    case 7:
      break;
    }
  }
done:
  return 0;
}
#define FUN_00397950(...) ((u64 (*)(...))FUN_00397950)(__VA_ARGS__)
#undef FUN_00397d60
// FUN_00397D60


void FUN_00397d60(void)



{

  int iVar1;

  iVar1 = (int)FUN_0035ae10_pm();

  if (*(u16 *)(iVar1 + 0x18) > 0) {

    FUN_003951a0(*(u16 *)(iVar1 + 0x18));

  }

  if (*(int *)(iVar1 + 0x1c) != 0) {

    FUN_00100ec0(*(int *)(iVar1 + 0x1c));

    *(u32 *)(iVar1 + 0x1c) = 0;

    FUN_005225a8((u32)(uintptr_t)DAT_006a10d0);

  }

  if (*(int *)(iVar1 + 0x28) != 0) {

    FUN_00386b70(*(int *)(iVar1 + 0x28),4,0);

    *(u32 *)(iVar1 + 0x28) = 0;

    FUN_005225a8((u32)(uintptr_t)DAT_006a10f0);

  }

  if (*(int *)(iVar1 + 0x20) != 0) {

    FUN_00100ec0(*(int *)(iVar1 + 0x20));

    *(u32 *)(iVar1 + 0x20) = 0;

    FUN_005225a8((u32)(uintptr_t)DAT_006a1120);

  }

  if (*(int *)(iVar1 + 0x2c) != 0) {

    FUN_00386b70(*(int *)(iVar1 + 0x2c),5,0);

    *(u32 *)(iVar1 + 0x2c) = 0;

    FUN_005225a8((u32)(uintptr_t)DAT_006a1140);

  }

  if (*(int *)(iVar1 + 0x24) != 0) {

    FUN_00100ec0(*(int *)(iVar1 + 0x24));

    *(u32 *)(iVar1 + 0x24) = 0;

    FUN_005225a8((u32)(uintptr_t)DAT_006a1170);

  }

  if (*(int *)(iVar1 + 0x30) != 0) {

    FUN_00386b70(*(int *)(iVar1 + 0x30),6,0);

    *(u32 *)(iVar1 + 0x30) = 0;

    FUN_005225a8((u32)(uintptr_t)DAT_006a1190);

  }

  FUN_00386b70(iVar1,1,0x40);
  return;

}
#define FUN_00397d60(...) ((void (*)(...))FUN_00397d60)
#undef FUN_00397ec0

// FUN_00397EC0
void FUN_00397ec0(u32 param_1,u32 param_2,u32 param_3,u32 param_4)
{
  u32 uVar1;
  int iVar2;

  uVar1 = FUN_00386ae0_pm(0x40,1);
  FUN_00521408_pm(uVar1,0,0x40);
  iVar2 = (int)uVar1;
  *(u32 *)(iVar2 + 0xc) = param_1;
  *(u32 *)(iVar2 + 0x10) = param_2;
  *(u32 *)(iVar2 + 0x14) = param_3;
  *(u32 *)(iVar2 + 4) = param_4;
  *(u32 *)(iVar2 + 8) = 0;
  FUN_00194e10_pm(FUN_006a11c0,0xf,1,1,FUN_00397950,FUN_00397d60,uVar1);
}

#define FUN_00397ec0(...) ((void (*)(...))FUN_00397ec0)(__VA_ARGS__)
#undef FUN_00397f80
// FUN_00397F80


u32 FUN_00397f80(u32 param_1,u32 param_2,u32 param_3,u32 param_4)
{
  int iVar1;
  u32 uVar2;

  uVar2 = FUN_00386ae0_pm(0x40,1);
  FUN_00521408_pm(uVar2,0,0x40);
  iVar1 = (int)uVar2;
  *(u32 *)(iVar1 + 0xc) = param_1;
  *(u32 *)(iVar1 + 0x10) = param_2;
  *(u32 *)(iVar1 + 0x14) = param_3;
  *(u32 *)(iVar1 + 4) = param_4;
  *(u32 *)(iVar1 + 8) = 0;
  uVar2 = FUN_00194e10_pm(FUN_006a11c0,0xf,1,1,FUN_00397950,FUN_00397d60,uVar2);
  iVar1 = FUN_0035ae10_pm(uVar2);
  *(u32 *)(iVar1 + 8) = 0;
  return uVar2;
}
#define FUN_00397f80(...) ((u32 (*)(...))FUN_00397f80)(__VA_ARGS__)
#undef FUN_00398060
// FUN_00398060


u8 FUN_00398060(u64 param_1)
{
  int *piVar1;
  s32 lVar2;

  lVar2 = FUN_00195460_pm();
  if (lVar2 == 0) {
    FUN_0019d3f0_pm("mt_evtPMFileReader.c",0x115);
  }

  piVar1 = (int *)FUN_00195540_pm(param_1);
  if (*piVar1 == 7) {
    return 1;
  }
  return 0;
}

#define FUN_00398060(...) ((u8 (*)(...))FUN_00398060)(__VA_ARGS__)
#undef FUN_003980e0
// FUN_003980E0


void FUN_003980e0(u64 param_1)
{
  s32 lVar1;

  lVar1 = FUN_00195460_pm();
  if (lVar1 == 0) {
    FUN_0019d3f0_pm("mt_evtPMFileReader.c",0x127);
  }

  FUN_00195540_pm(param_1);
}

#define FUN_003980e0(...) ((void (*)(...))FUN_003980e0)(__VA_ARGS__)
#undef FUN_00398140
// FUN_00398140


u32

FUN_00398140(u32 param_1,u32 *param_2,u32 *param_3,u32 *param_4,int *param_5)



{

  int *piVar1;

  int iVar2;

  s32 lVar3;

  int iVar4;

  int iVar5;

  u8 auStack_130 [0x130];

  u8 *puVar2;

  

  puVar2 = auStack_130;
  FUN_00521408(puVar2,0,0x130);

  lVar3 = FUN_00195460(param_1);

  if (lVar3 == 0) {

    FUN_0019d3f0("mt_evtPMFileReader.c",0x115);

  }

  piVar1 = (int *)FUN_00195540(param_1);

  if (*piVar1 != 7) {
    return 0;
  }

  iVar2 = FUN_00195540(param_1);

  *(u32 *)(puVar2 + 0x84) = *(int *)(iVar2 + 0x38);
  if (*(int *)(iVar2 + 0x38) != 0) {
    *(u32 *)(puVar2 + 0x88) = *(int *)(iVar2 + 0x38) + 0x20;
  }
  else {
    *(u32 *)(puVar2 + 0x88) = 0;
  }


    for (iVar4 = 0, iVar5 = *(int *)(*(u32 *)(puVar2 + 0x84) + 0x10); iVar4 < iVar5; iVar4 = iVar4 + 1) {

      piVar1 = (int *)*(u32 *)(puVar2 + 0x88);
      piVar1 = (int *)((u8 *)piVar1 + iVar4 * 0x10);

      switch (*piVar1) {
      case 0:
        goto found;
      default:
        goto next;
      }

    found:

      iVar2 = *(int *)(iVar2 + 0x38) + piVar1[3];
      *(u32 *)(puVar2 + 0x94) = iVar2;

      *param_2 = *(u32 *)(*(u32 *)(puVar2 + 0x94) + 0x10);

      *param_3 = *(u32 *)(*(u32 *)(puVar2 + 0x94) + 0x14);

      *param_4 = (u32)*(u8 *)(*(u32 *)(puVar2 + 0x94) + 0x1a);

      *param_5 = (int)*(short *)(*(u32 *)(puVar2 + 0x94) + 0x1c);

      return 1;
    next:
      ;
    }


  return 0;

}
#define FUN_00398140(...) ((u32 (*)(...))FUN_00398140)(__VA_ARGS__)
#undef FUN_003982d0
// FUN_003982D0


u8 FUN_003982d0(u64 param_1)



{

  int *piVar1;

  int iVar2;

  s32 lVar3;

  

  lVar3 = FUN_00195460_pm();
  if (lVar3 == 0) {
    FUN_0019d3f0_pm("mt_evtPMFileReader.c",0x115);
  }

  piVar1 = (int *)FUN_00195540_pm(param_1);
  if (*piVar1 != 7) {
    FUN_0019d3f0_pm("mt_evtPMFileReader.c",0x175);
  }

  iVar2 = FUN_00195540_pm(param_1);
  lVar3 = FUN_003bd8b0_pm(*(u32 *)(iVar2 + 0xc),*(u32 *)(iVar2 + 0x10),
                          *(u32 *)(iVar2 + 0x14));
  if (lVar3 != -1) {
    return 1;
  }
  return 0;

}
#define FUN_003982d0(...) ((u8 (*)(...))FUN_003982d0)(__VA_ARGS__)
#undef FUN_00398390
// FUN_00398390


void FUN_00398390(u32 *param_1,u32 param_2)



{

  *param_1 = 0;

  param_1[1] = param_2;

  return;

}
#define FUN_00398390(...) ((void (*)(...))FUN_00398390)(__VA_ARGS__)
#undef FUN_003983a0
// FUN_003983A0


u8 FUN_003983a0(int *param_1)
{
  int iVar1;

  iVar1 = *param_1;

  if (iVar1 >= param_1[1]) {
    return 1;
  }

  *param_1 = iVar1 + 1;
  return 0;
}
#define FUN_003983a0(...) ((u8 (*)(...))FUN_003983a0)(__VA_ARGS__)
