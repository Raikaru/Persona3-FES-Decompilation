#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))
#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
u32 FUN_00396e30(int param_1);
u32 FUN_00396ed0(int param_1);
void FUN_00396f50(int param_1);
void FUN_00397030(int param_1);
void FUN_003970d0(void);
u32 FUN_003971a0(void);
u8 FUN_003973e0(void);
void FUN_00397450(void);
u32 FUN_00397500(int param_1);
void FUN_00397510(int param_1,u32 param_2);
u32 FUN_00397520(int param_1,u32 *param_2);
u32 FUN_00397580(int param_1,int param_2,u16 *param_3);
u32 FUN_00397630(int param_1,int param_2,u32 *param_3);
u32 FUN_003976f0(int param_1,int param_2,u32 *param_3,u32 *param_4);
u8 FUN_003977c0(int param_1,u32 *param_2,u32 *param_3,u32 *param_4);
u32 FUN_00397870(int param_1,int param_2,u32 *param_3,u32 *param_4,u32 *param_5,u32 *param_6);
extern int FUN_00195340(const char *);
extern int FUN_00195540(int);
#pragma alias FUN_00396f50_int FUN_00396f50
extern void FUN_00396f50_int(int);
#pragma alias FUN_00397030_int FUN_00397030
extern void FUN_00397030_int(int);
extern void FUN_00195020(u32 param_1);
extern void FUN_0019d3f0(const char *,u32);
extern int FUN_0035ed20(int);
extern int FUN_0035f130(void);
extern char DAT_006a1050[];
extern char DAT_006a1070[];
#pragma alias DAT_006a1050_abs DAT_006a1050
extern u8 DAT_006a1050_abs[];
#pragma alias DAT_006a1070_abs DAT_006a1070
extern u8 DAT_006a1070_abs[];


/* Region call-cast macros */
#define FUN_00396e30(...) ((u32 (*)(...))FUN_00396e30)(__VA_ARGS__)
#define FUN_00396ed0(...) ((u32 (*)(...))FUN_00396ed0)(__VA_ARGS__)
#define FUN_00396f50(...) ((void (*)(...))FUN_00396f50)(__VA_ARGS__)
#define FUN_00397030(...) ((void (*)(...))FUN_00397030)(__VA_ARGS__)
#define FUN_003970d0(...) ((void (*)(...))FUN_003970d0)(__VA_ARGS__)
#define FUN_003971a0(...) ((u32 (*)(...))FUN_003971a0)(__VA_ARGS__)
#define FUN_003973e0(...) ((u8 (*)(...))FUN_003973e0)(__VA_ARGS__)
#define FUN_00397450(...) ((void (*)(...))FUN_00397450)(__VA_ARGS__)
#define FUN_00397500(...) ((u32 (*)(...))FUN_00397500)(__VA_ARGS__)
#define FUN_00397510(...) ((void (*)(...))FUN_00397510)(__VA_ARGS__)
#define FUN_00397520(...) ((u32 (*)(...))FUN_00397520)(__VA_ARGS__)
#define FUN_00397580(...) ((u32 (*)(...))FUN_00397580)(__VA_ARGS__)
#define FUN_00397630(...) ((u32 (*)(...))FUN_00397630)(__VA_ARGS__)
#define FUN_003976f0(...) ((u32 (*)(...))FUN_003976f0)(__VA_ARGS__)
#define FUN_003977c0(...) ((u8 (*)(...))FUN_003977c0)(__VA_ARGS__)
#define FUN_00397870(...) ((u32 (*)(...))FUN_00397870)(__VA_ARGS__)
#undef FUN_00396e30
// FUN_00396E30


u32 FUN_00396e30(int param_1)
{
  extern int FUN_00195340(const char *);
  extern int FUN_00195540(int);
  int entry;
  u32 result;
  int manager;
  int base;
  int offset;

  manager = FUN_00195340("koma_Manager");
  if (manager == 0) {
    result = 0;
  }
  else if (param_1 >= 3) {
    result = 0;
  }
  else {
    base = FUN_00195540(manager);
    offset = param_1 * 0xc;
    entry = offset + base;
    if (*(int *)(entry + 8) == 0) {
      result = 0;
    }
    else {
      result = 1;
      *(u32 *)(entry + 4) = 1;
    }
  }
  return result;
}

#define FUN_00396e30(...) ((u32 (*)(...))FUN_00396e30)(__VA_ARGS__)
#undef FUN_00396ed0
// FUN_00396ED0


u32 FUN_00396ed0(int param_1)
{
    int iVar1;
    u32 uVar2;
    int lVar3;

    lVar3 = FUN_00195340("koma_Manager");
    if (lVar3 == 0) {
        uVar2 = 0;
    } else if (param_1 >= 3) {
        uVar2 = 0;
    } else {
        iVar1 = FUN_00195540(lVar3);
        uVar2 = *(u32 *)(iVar1 + param_1 * 0xc);
    }
    return uVar2;
}
#define FUN_00396ed0(...) ((u32 (*)(...))FUN_00396ed0)(__VA_ARGS__)
#undef FUN_00396f50
// FUN_00396F50 NONMATCHING


#pragma push
#pragma opt_rebuildconditionals off
void FUN_00396f50(int param_1)



{

  int manager;
  int base;
  u32 *state_ptr;
  u32 *entry;
  int offset;

  manager = FUN_00195340("koma_Manager");
  if (manager == 0) return;
  if (param_1 >= 3) return;
  base = FUN_00195540(manager);
  offset = (int)param_1 * 0xc;
  entry = (u32 *)(offset + base);
  state_ptr = entry + 2;
  if (*state_ptr != 0) {
    if (*entry == 2) goto state_action;
    if (*entry == 1) goto state_action;
    if (*entry == 0) return;
    goto state_default;
state_action:
    FUN_00397030_int(param_1);
    goto state_done;
state_default:
    FUN_00111500();
    *entry = 0;
    *state_ptr = 0;
state_done:
    ;
  }
  return;

}
#pragma pop
#define FUN_00396f50(...) ((void (*)(...))FUN_00396f50)(__VA_ARGS__)
#undef FUN_00397030
// FUN_00397030 NONMATCHING


void FUN_00397030(int param_1)
{
    int iVar1;
    int lVar2;
    int iVar3;
    int iVar4;

    lVar2 = FUN_00195340("koma_Manager");
    if ((lVar2 != 0) && (param_1 < 3)) {
        iVar1 = FUN_00195540(lVar2);
        iVar4 = param_1 * 0xc;
        iVar3 = iVar4 + iVar1;
        if (*(int *)(iVar3 + 8) != 0) {
            FUN_00195020(*(u32 *)(iVar3 + 8));
            *(u32 *)(iVar3 + 8) = 0;
            *(u32 *)(iVar1 + iVar4) = 0;
        }
    }
}
#define FUN_00397030(...) ((void (*)(...))FUN_00397030)(__VA_ARGS__)
#undef FUN_003970d0
// FUN_003970D0


void FUN_003970d0(void)



{

  int lVar1;

  int iVar2;

  int iVar3;

  u32 *puVar4;
  u32 *puVar5;

  lVar1 = FUN_00195340("koma_Manager");

  if (lVar1 != 0) {

    for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {

      lVar1 = FUN_00195340("koma_Manager");

      if ((lVar1 != 0) && (iVar3 < 3)) {

        iVar2 = FUN_00195540(lVar1);

        puVar4 = (u32 *)(iVar2 + iVar3 * 0xc);
        puVar5 = puVar4 + 2;
        iVar2 = *puVar5;
        if (iVar2 != 0) {

          FUN_00195020(iVar2);

          *puVar5 = 0;
          *puVar4 = 0;

        }

      }

    }

  }

  return;

}
#define FUN_003970d0(...) ((void (*)(...))FUN_003970d0)(__VA_ARGS__)
#undef FUN_003971a0
// FUN_003971A0 NONMATCHING


u32 FUN_003971a0(void)



{

  u8 bVar1;

  int iVar2;

  int lVar3;

  s32 uVar4;

  s32 uVar5;

  s32 uVar6;

  s32 uVar7;

  s32 uVar8;

  s32 uVar9;

  int lVar10;

  

  lVar3 = FUN_0035ed20(0);

  uVar4 = FUN_0035ed20(1);

  uVar5 = FUN_0035ed20(2);

  uVar6 = FUN_0035ed20(3);

  uVar7 = FUN_0035ed20(4);

  uVar8 = FUN_0035ed20(5);

  uVar9 = FUN_0035ed20(6);

  lVar10 = FUN_0035f130();

  if (lVar10 == 0) {

    lVar3 = FUN_00396c70(lVar3,uVar4,uVar5,uVar6,uVar7,uVar8,uVar9);

    if (lVar3 == 0) {

      FUN_0019d3f0("mt_evtCutin.c",0x11a);

    }

  }

  else {

    lVar10 = FUN_0035f130();

    if (lVar10 == 1) {

      lVar10 = FUN_00195340("koma_Manager");

      if (lVar10 == 0) {

        bVar1 = 0;

      }

      else if (lVar3 < 3) {

        iVar2 = FUN_00195540(lVar10);

        iVar2 = (int)lVar3 * 0xc + iVar2;

        if (*(int *)(iVar2 + 8) == 0) {

          bVar1 = 0;

        }

        else {

          bVar1 = 1;

          *(u32 *)(iVar2 + 4) = 1;

        }

      }

      else {

        bVar1 = 0;

      }

      if (!bVar1) {

        FUN_0019d3f0("mt_evtCutin.c",0x120);

      }

    }

    else {

      lVar10 = FUN_00195340("koma_Manager");

      if (lVar10 == 0) {

        iVar2 = 0;

      }

      else if (lVar3 < 3) {

        iVar2 = FUN_00195540(lVar10);

        iVar2 = *(int *)(iVar2 + (int)lVar3 * 0xc);

      }

      else {

        iVar2 = 0;

      }

      if (iVar2 == 3) {

        return 1;

      }

    }

  }

  return 0;

}
#define FUN_003971a0(...) ((u32 (*)(...))FUN_003971a0)(__VA_ARGS__)
#undef FUN_003973e0
// FUN_003973E0


u8 FUN_003973e0(void)
{
    int uVar1;

    uVar1 = FUN_0035ed20(0);
    if (FUN_0035f130() != 0) goto success;
    FUN_00396f50_int(uVar1);
    goto done;
success:
    return 1;
done:
    return 0;
}
#define FUN_003973e0(...) ((u8 (*)(...))FUN_003973e0)(__VA_ARGS__)
#undef FUN_00397450
// FUN_00397450


void FUN_00397450(void)



{

  int uVar1;
  int iVar3;
  int lVar2;
  

  lVar2 = FUN_003b5cf0();

  if (lVar2 == 0) {
    return;
  }
  for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
    uVar1 = (u16)(iVar3 + 900U & 0x3ff | 0xc00);
    FUN_005225a8(DAT_006a1050_abs,uVar1);
    lVar2 = FUN_003b5d10(uVar1);
    if (lVar2 != 0) {
      FUN_003b7090(uVar1);
      FUN_005225a8(DAT_006a1070_abs);
    }
  }

  return;

}
#define FUN_00397450(...) ((void (*)(...))FUN_00397450)(__VA_ARGS__)
#undef FUN_00397500
// FUN_00397500


u32 FUN_00397500(int param_1)



{

  return *(u32 *)(param_1 + 0x970);

}
#define FUN_00397500(...) ((u32 (*)(...))FUN_00397500)(__VA_ARGS__)
#undef FUN_00397510
// FUN_00397510


void FUN_00397510(int param_1,u32 param_2)



{

  *(u32 *)(param_1 + 0x970) = param_2;

  return;

}
#define FUN_00397510(...) ((void (*)(...))FUN_00397510)(__VA_ARGS__)
#undef FUN_00397520
// FUN_00397520


u32 FUN_00397520(int param_1,u32 *param_2)
{
    int iVar1;

    iVar1 = *(int *)(param_1 + 8);
    if (param_1 == 0) {
        return 0;
    }
    if (iVar1 == 0) {
        return 0;
    }
    iVar1 = *(int *)(iVar1 + 0x60);
    if (iVar1 == 0) {
        return 0;
    }
    *param_2 = (u32)*(u16 *)(iVar1 + 2);
    return 1;
}
#define FUN_00397520(...) ((u32 (*)(...))FUN_00397520)(__VA_ARGS__)
#undef FUN_00397580
// FUN_00397580


u32 FUN_00397580(int param_1,int param_2,u16 *param_3)
{
    int iVar1;
    int iVar2;
    int index;
    int length;
    u32 bVar2;

    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == 0) {
        bVar2 = 0;
    } else {
        iVar2 = *(int *)(iVar1 + 0x60);
        if (iVar2 == 0) {
            bVar2 = 0;
        } else {
            index = *(volatile int *)(param_1 + 0x970);
            length = (int)(u32)*(volatile u16 *)(iVar2 + 2);
            if (length <= index) {
                bVar2 = 0;
            } else {
            bVar2 = 1;
        }
    }
    }
    if (!bVar2) {
        return 0;
    }
    index = *(volatile int *)(param_1 + 0x970);
    iVar2 = *(volatile int *)((u8 *)iVar1 + 0x60);
    *param_3 = *(u16 *)(*(int *)(iVar2 + 4) +
                        index * 0x8c + param_2 * 2);
    return 1;
}
#define FUN_00397580(...) ((u32 (*)(...))FUN_00397580)(__VA_ARGS__)
#undef FUN_00397630
// FUN_00397630


u32 FUN_00397630(int param_1,int param_2,u32 *param_3)
{
    int iVar1;
    int iVar2;
    int index;
    int length;
    int base;
    int scaled;
    u32 bVar2;

    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == 0) {
        bVar2 = 0;
    } else {
        iVar2 = *(int *)(iVar1 + 0x60);
        if (iVar2 == 0) {
            bVar2 = 0;
        } else {
            index = *(volatile int *)(param_1 + 0x970);
            length = (int)(u32)*(volatile u16 *)(iVar2 + 2);
            if (length <= index) {
                bVar2 = 0;
            } else {
                bVar2 = 1;
            }
        }
    }
    if (!bVar2) {
        return 0;
    }
    if (param_2 >= 10) {
        return 0;
    }
    index = *(volatile int *)(param_1 + 0x970);
    iVar2 = *(volatile int *)((u8 *)iVar1 + 0x60);
    base = *(volatile int *)(iVar2 + 4);
    scaled = index * 0x8c;
    *param_3 = (u32)*(u8 *)((scaled + base) + param_2 + 0x16);
    return 1;
}
#define FUN_00397630(...) ((u32 (*)(...))FUN_00397630)(__VA_ARGS__)
#undef FUN_003976f0
// FUN_003976F0


u32 FUN_003976f0(int param_1,int param_2,u32 *param_3,u32 *param_4)
{
    int iVar1;
    int iVar2;
    int index;
    int length;
    int base;
    int offset;
    int scaled;
    u32 bVar1;

    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == 0) {
        bVar1 = 0;
    } else {
        iVar2 = *(int *)(iVar1 + 0x60);
        if (iVar2 == 0) {
            bVar1 = 0;
        } else {
            index = *(volatile int *)(param_1 + 0x970);
            length = (int)(u32)*(volatile u16 *)(iVar2 + 2);
            if (length <= index) {
                bVar1 = 0;
            } else {
                bVar1 = 1;
            }
        }
    }
    if (!bVar1) {
        return 0;
    }
    if (param_2 >= 10) {
        return 0;
    }
    index = *(volatile int *)(param_1 + 0x970);
    iVar2 = *(volatile int *)((u8 *)iVar1 + 0x60);
    base = *(volatile int *)(iVar2 + 4);
    offset = param_2 * 2;
    scaled = index * 0x8c;
    *param_3 = (u32)*(u8 *)((scaled + base) + offset + 0x20);
    *param_4 = (u32)*(u8 *)(scaled + base + offset + 0x21);
    return 1;
}
#define FUN_003976f0(...) ((u32 (*)(...))FUN_003976f0)(__VA_ARGS__)
#undef FUN_003977c0
// FUN_003977C0


u8 FUN_003977c0(int param_1,u32 *param_2,u32 *param_3,u32 *param_4)
{
    int iVar1;
    int iVar2;
    int index;
    int length;
    int base;
    int scaled;
    u32 bVar1;

    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == 0) {
        bVar1 = 0;
    } else {
        iVar2 = *(int *)(iVar1 + 0x60);
        if (iVar2 == 0) {
            bVar1 = 0;
        } else {
            index = *(volatile int *)(param_1 + 0x970);
            length = (int)(u32)*(volatile u16 *)(iVar2 + 2);
            if (length <= index) {
                bVar1 = 0;
            } else {
                bVar1 = 1;
            }
        }
    }
    if (!bVar1) {
        return 0;
    }
    index = *(volatile int *)(param_1 + 0x970);
    iVar2 = *(volatile int *)((u8 *)iVar1 + 0x60);
    base = *(volatile int *)(iVar2 + 4);
    scaled = index * 0x8c;
    *param_2 = (u32)*(u16 *)((scaled + base) + 0xa);
    *param_3 = (u32)*(u16 *)(scaled + base + 0xe);
    *param_4 = (u32)*(u16 *)(scaled + base + 0x12);
    return 1;
}
#define FUN_003977c0(...) ((u8 (*)(...))FUN_003977c0)(__VA_ARGS__)
#undef FUN_00397870
// FUN_00397870 NONMATCHING


u32

FUN_00397870(int param_1,int param_2,u32 *param_3,u32 *param_4,u32 *param_5,u32 *param_6)



{

  u8 bVar1;

  u32 uVar2;

  int iVar3;

  

  iVar3 = *(int *)(param_1 + 8);

  if (iVar3 == 0) {

    bVar1 = 0;

  }

  else if (*(int *)(iVar3 + 0x60) == 0) {

    bVar1 = 0;

  }

  else if (*(int *)(param_1 + 0x970) < (int)(u32)*(u16 *)(*(int *)(iVar3 + 0x60) + 2)) {

    bVar1 = 1;

  }

  else {

    bVar1 = 0;

  }

  if (bVar1) {

    if (param_2 < 10) {

      iVar3 = (int)param_2 * 8 +

              *(int *)(param_1 + 0x970) * 0x8c + *(int *)(*(int *)(iVar3 + 0x60) + 4);

      *param_3 = (u32)*(u16 *)(iVar3 + 0x34);

      *param_4 = (u32)*(u16 *)(iVar3 + 0x36);

      *param_5 = (u32)*(u16 *)(iVar3 + 0x38);

      *param_6 = (u32)*(u16 *)(iVar3 + 0x3a);

      uVar2 = 1;

    }

    else {

      uVar2 = 0;

    }

  }

  else {

    uVar2 = 0;

  }

  return uVar2;

}
#define FUN_00397870(...) ((u32 (*)(...))FUN_00397870)(__VA_ARGS__)
