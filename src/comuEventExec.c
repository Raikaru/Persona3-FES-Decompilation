#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern u32 DAT_006a3340;
#pragma alias DAT_006a3340_abs DAT_006a3340
extern u8 DAT_006a3340_abs[];
extern u8 * PTR_DAT_006a3590;
#pragma alias PTR_DAT_006a3590_abs PTR_DAT_006a3590
extern u8 *PTR_DAT_006a3590_abs[];
extern u8 * PTR_DAT_006a36a0;
extern u8 * PTR_DAT_006a38e0;
#pragma alias PTR_DAT_006a36a0_abs PTR_DAT_006a36a0
extern u8* PTR_DAT_006a36a0_abs[];
#pragma alias PTR_DAT_006a38e0_abs PTR_DAT_006a38e0
extern u8* PTR_DAT_006a38e0_abs[];

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
u32 FUN_003bf130(void);
#pragma alias FUN_003c33c0_call FUN_003c33c0
extern u32 FUN_003c33c0_call();
u32 FUN_003c3e80(u8 *param_1);
u8 * FUN_003c3f40(u32 param_1);
u8 * FUN_003c3f80(int param_1);
u8 * FUN_003c3fe0(int param_1);

/* Region call-cast macros */
#define FUN_003c33c0(...) ((u8 (*)(...))FUN_003c33c0)(__VA_ARGS__)
#define FUN_003c3e80(...) ((u32 (*)(...))FUN_003c3e80)(__VA_ARGS__)
#define FUN_003c3f40(...) ((u8 * (*)(...))FUN_003c3f40)(__VA_ARGS__)
#define FUN_003c3f80(...) ((u8 * (*)(...))FUN_003c3f80)(__VA_ARGS__)
#define FUN_003c3fe0(...) ((u8 * (*)(...))FUN_003c3fe0)(__VA_ARGS__)

#undef FUN_003c33c0
#pragma push
// W419 state-2 switch-shaped dispatch probe worsened 1436/2516 to 1466/2540 (rate 57.07% to 57.72%); if/else form retained.
/* W420 negative: duplicating the shared state-1 case body for states 0,2..7 produced nd1603/object2756 against window2752 (rate .5707 -> .5814); reverted. */
/* W455 retail state-one dispatch has eight distinct jump-table targets, so
 * repeated state assignments are kept as separate case bodies below. */
// FUN_003C33C0 NONMATCHING

u8 FUN_003c33c0(u8 *param_1, int *param_2, long param_3)
{
  int bVar1;
  int iVar2;
  int iVar3;
  int cVar4;
  u16 uVar5;
  s32 lVar6;
  u32 uVar7;
  u8 *pbVar8;
  u16 uStack_2;

  pbVar8 = param_1;
  iVar2 = *(int *)(pbVar8 + 0xc);
  *param_2 = 0;
  bVar1 = pbVar8[8];
  iVar3 = *(int *)(pbVar8 + 0xc);

  switch (iVar3) { case 0: {
  short state0Value;
  FUN_0016e920(*pbVar8);
  FUN_001727e0();
  state0Value = *pbVar8;
  cVar4 = FUN_0016e850(state0Value);
  if ((char)DAT_006a3340_abs[(short)(u16)state0Value] < cVar4)
    FUN_0016f1f0(0xa2d, 1);
  else
    FUN_0016f1f0(0xa2d, 0);
  pbVar8[8] = 0;
  *(int *)(pbVar8 + 0xc) = 1; } break; case 1: { switch (pbVar8[2]) {
  case 0:
    if (bVar1 < 4) {
      *(int *)(pbVar8 + 0xc) = 2;
    } else {
      *(int *)(pbVar8 + 0xc) = 3;
    }
    break;
  case 1:
    if (bVar1 < 4) {
      if (bVar1 == 0)
        FUN_001725a0(*pbVar8);
      *(int *)(pbVar8 + 0xc) = 2;
    } else {
      *(int *)(pbVar8 + 0xc) = 3;
    }
    break;
  case 2:
    if (bVar1 < 4) {
      *(int *)(pbVar8 + 0xc) = 2;
    } else {
      *(int *)(pbVar8 + 0xc) = 3;
    }
    break;
  case 3:
    if (bVar1 < 4) {
      *(int *)(pbVar8 + 0xc) = 2;
    } else {
      *(int *)(pbVar8 + 0xc) = 3;
    }
    break;
  case 4:
    if (bVar1 < 4) {
      *(int *)(pbVar8 + 0xc) = 2;
    } else {
      *(int *)(pbVar8 + 0xc) = 3;
    }
    break;
  case 5:
    if (bVar1 < 4) {
      *(int *)(pbVar8 + 0xc) = 2;
    } else {
      *(int *)(pbVar8 + 0xc) = 3;
    }
    break;
  case 6:
    if (bVar1 < 4) {
      *(int *)(pbVar8 + 0xc) = 2;
    } else {
      *(int *)(pbVar8 + 0xc) = 3;
    }
    break;
  case 7:
    if (bVar1 < 4) {
      *(int *)(pbVar8 + 0xc) = 2;
    } else {
      *(int *)(pbVar8 + 0xc) = 3;
    }
    break;
  default:
    FUN_0019d3f0("comuEventExec.c", 0xfb);
  }
  if (*(int *)(pbVar8 + 0xc) == 2) {
    *param_2 = pbVar8[8] + 1;
    FUN_0016f1f0(0xa14, 0);
    FUN_0016f1f0(0xa15, 0);
    FUN_0016f1f0(0xa16, 0);
    FUN_0016f1f0(0xa17, 0);
  } } break; case 2: if (param_3 != 0) { switch (pbVar8[2]) {
  case 0:
    switch (bVar1) {
    case 0:
      lVar6 = FUN_00172750(pbVar8 + 0x24);
      if (lVar6 == 1) {
        lVar6 = FUN_00172a30();
        if (lVar6 == 1) {
          pbVar8[8] = 1;
        } else {
          lVar6 = FUN_003be1a0(param_1);
          if (lVar6 == 1) {
            FUN_0016e920(pbVar8[1]);
            pbVar8[8] = 2;
          } else {
            pbVar8[8] = 4;
          }
        }
      } else {
        lVar6 = FUN_003be1a0(param_1);
        if (lVar6 == 1) {
          FUN_0016e920(pbVar8[1]);
          pbVar8[8] = 2;
        } else {
          pbVar8[8] = 4;
        }
      }
      break;
    case 1:
      FUN_00395170(0x989);
      lVar6 = FUN_003be1a0(param_1);
      if (lVar6 == 1) {
        bVar1 = pbVar8[1];
        FUN_0016e920(bVar1);
        cVar4 = FUN_0016e850(bVar1);
        if ((char)DAT_006a3340_abs[(short)(u16)bVar1] < cVar4)
          FUN_0016f1f0(0xa2d, 1);
        else
          FUN_0016f1f0(0xa2d, 0);
        pbVar8[8] = 2;
      } else {
        pbVar8[8] = 4;
      }
      break;
    case 2:
      lVar6 = FUN_0016e100(pbVar8[1]);
      if (lVar6 == 1) {
        uVar7 = FUN_0016ef20();
        FUN_0016e7a0(pbVar8[1], uVar7);
      }
      pbVar8[8] = 4;
      break;
    default:
      FUN_0019d3f0("comuEventExec.c", 0x14a);
    }
    break;
  case 1:
    if (bVar1 == 3) {
      pbVar8[8] = 4;
    } else if (bVar1 == 2) {
      lVar6 = FUN_00172750(pbVar8 + 0x30);
      if (lVar6 == 1)
        pbVar8[8] = 3;
      else
        pbVar8[8] = 4;
    } else if (bVar1 == 1) {
      lVar6 = FUN_00172750(pbVar8 + 0x2a);
      if (lVar6 == 1)
        pbVar8[8] = 2;
      else
        pbVar8[8] = 4;
    } else if (bVar1 == 0) {
      lVar6 = FUN_00172750(pbVar8 + 0x24);
      if (lVar6 == 1) {
        lVar6 = FUN_0038d6f0(9);
        if (lVar6 == 0) {
          pbVar8[8] = 1;
        } else if (lVar6 == 1) {
          lVar6 = FUN_00172750(pbVar8 + 0x2a);
          if (lVar6 == 1)
            pbVar8[8] = 2;
          else
            pbVar8[8] = 4;
        } else {
          pbVar8[8] = 1;
        }
      } else {
        pbVar8[8] = 4;
      }
    } else {
      FUN_0019d3f0("comuEventExec.c", 0x182);
    }
    break;
  case 2:
    pbVar8[8] = 4;
    break;
  case 3:
    pbVar8[8] = 4;
    break;
  case 4:
    pbVar8[8] = 4;
    break;
  case 5:
    pbVar8[8] = 4;
    break;
  case 6:
    pbVar8[8] = 4;
    break;
  case 7:
    if (bVar1 == 0) {
      lVar6 = FUN_00172750(pbVar8 + 0x24);
      if (lVar6 == 0)
        FUN_0019d3f0("comuEventExec.c", 0x199);
      lVar6 = FUN_0038d6f0(8);
      if (lVar6 == 0)
        pbVar8[8] = 1;
      else
        pbVar8[8] = 4;
    } else {
      pbVar8[8] = 4;
    }
    break;
  default:
    FUN_0019d3f0("comuEventExec.c", 0x1aa);
  }
  
  *(int *)(pbVar8 + 0xc) = 1;
  lVar6 = FUN_003951d0(0xa14);
  if (lVar6 == 1) {
    uVar5 = FUN_0016dd40();
    FUN_00171c40(uVar5, 1);
  }
  lVar6 = FUN_003951d0(0xa15);
  if (lVar6 == 1) {
    uVar5 = FUN_0016dd40();
    FUN_00171c40(uVar5, 0);
  }
  lVar6 = FUN_003951d0(0xa16);
  if (lVar6 == 1) {
    uVar5 = FUN_0016dd40();
    FUN_00172200(uVar5, 1);
  }
  lVar6 = FUN_003951d0(0xa17);
  if (lVar6 == 1) {
    uVar5 = FUN_0016dd40();
    FUN_00172200(uVar5, 0);
  }
  lVar6 = FUN_0038d6f0(7);
  if ((lVar6 == 0) || ((lVar6 = FUN_0038d6f0(7)), lVar6 == 2)) {
    lVar6 = FUN_0038d6f0(7);
    if (lVar6 == 2) {
      lVar6 = FUN_00172c50(&uStack_2);
      if (lVar6 == 0)
        FUN_0019d3f0("comuEventExec.c", 0x1ca);
      FUN_00172cc0(uStack_2);
      FUN_00172b20();
    }
    lVar6 = FUN_003c30b0();
    if (lVar6 == 0)
      FUN_0019d3f0("comuEventExec.c", 0x1d0);
  } } break; case 3: { switch (pbVar8[2]) {
  case 0:
    FUN_0016e670(*pbVar8);
    FUN_00171b50(*pbVar8);
    break;
  case 1:
    FUN_003951a0(*pbVar8 + 0x960);
    FUN_003951a0(*pbVar8 + 0x990);
    FUN_00171b50(*pbVar8);
    break;
  case 2:
    FUN_00171b50(*pbVar8);
    break;
  case 3:
  case 4:
  case 6:
    break;
  case 5:
    FUN_00171b50(*pbVar8);
    break;
  case 7:
    FUN_00395170(*pbVar8 + 0x960);
    FUN_00171b50(*pbVar8);
    break;
  default:
    FUN_0019d3f0("comuEventExec.c", 0x1f6);
  }
  bVar1 = pbVar8[2];
  if (((bVar1 == 7) || (bVar1 == 1) || (bVar1 == 0)) &&
      ((lVar6 = FUN_00172a50(*pbVar8)), lVar6 == 1)) {
    FUN_00172ab0(*pbVar8);
    FUN_003bdbd0(*pbVar8);
  }
  uVar7 = FUN_0016ef20();
  FUN_0016e7a0(*pbVar8, uVar7);
  FUN_0016c920(1);
  FUN_00172860();
  switch (pbVar8[2]) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
    FUN_00172890();
    break;
  case 7:
    FUN_00172ae0();
    break;
  default:
    FUN_0019d3f0("comuEventExec.c", 0x218);
  } } break; default: { FUN_0019d3f0("comuEventExec.c", 0x21c); } break; }

  return iVar2 != 3;
}
#pragma pop
#undef FUN_003c33c0
#undef FUN_003c3e80
// FUN_003C3E80


u32 FUN_003c3e80(u8 *param_1)
{
  int iVar1;
  int iStack_4;

  iStack_4 = 0;
  if (FUN_003c33c0_call(param_1,&iStack_4,
                   (*(int *)(param_1 + 0xc) == 2) &&
                   (FUN_003bf130() == 1)) != 1) {
    goto return_zero;
  }
  if (iStack_4 != 0) {
    iVar1 = (int)(param_1 + (iStack_4 + -1) * 6);
    FUN_003bf180(*(u16 *)(iVar1 + 0x20),*(u8 *)(iVar1 + 0x22),
                 *(u8 *)(iVar1 + 0x23));
  }
  goto return_one;

return_zero:
  return 0;
return_one:
  return 1;
}

#define FUN_003c3e80(...) ((u32 (*)(...))FUN_003c3e80)(__VA_ARGS__)
#undef FUN_003c3f40
// FUN_003C3F40


u8 *FUN_003c3f40(u32 param_1)
{
  int index;

  index = param_1 & 0xff;
  if (index >= 0x2a) {
    return 0;
  }

  return PTR_DAT_006a3590_abs[index];
}

#define FUN_003c3f40(...) ((u8 * (*)(...))FUN_003c3f40)(__VA_ARGS__)
#undef FUN_003c3f80
// FUN_003C3F80


u8* FUN_003c3f80(s32 socialLink)
{
  u8* result;

  if (FUN_0016dce0_direct((s16)socialLink) == 0)
  {
    result = NULL;
  }
  else
  {
    result = PTR_DAT_006a38e0_abs[socialLink];
  }

  return result;
}

#define FUN_003c3f80(...) ((u8 * (*)(...))FUN_003c3f80)(__VA_ARGS__)
#undef FUN_003c3fe0
// FUN_003C3FE0


u8* FUN_003c3fe0(s32 socialLink)
{
  u8* result;

  if (FUN_0016dce0_direct((s16)socialLink) == 0)
  {
    result = NULL;
  }
  else
  {
    result = PTR_DAT_006a36a0_abs[socialLink];
  }

  return result;
}

#define FUN_003c3fe0(...) ((u8 * (*)(...))FUN_003c3fe0)(__VA_ARGS__)
