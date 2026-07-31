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


void FUN_00396f50(int param_1)
{
  int manager;
  int base;
  u32 *entry;
  u32 *state_ptr;
  int offset;

  manager = FUN_00195340("koma_Manager");
  if (manager != 0) {
    if (param_1 < 3) {
      base = FUN_00195540(manager);
      offset = param_1 * 0xc;
      entry = (u32 *)(offset + base);
      state_ptr = entry + 2;
      if (*state_ptr != 0) {
        switch (*entry) {
        case 0:
          break;
        case 1:
        case 2:
          FUN_00397030_int(param_1);
          break;
        default:
          FUN_00111500();
          *entry = 0;
          *state_ptr = 0;
          break;
        }
      }
    }
  }
}
#define FUN_00396f50(...) ((void (*)(...))FUN_00396f50)(__VA_ARGS__)
#undef FUN_00397030
// FUN_00397030


void FUN_00397030(int param_1)
{
    int manager;
    u32* base;
    int index;

    manager = FUN_00195340("koma_Manager");
    if (manager == 0)
    {
        goto done;
    }
    if (param_1 >= 3)
    {
        goto done;
    }
    base = (u32*)FUN_00195540(manager);
    index = param_1 * 3;
    if (base[index + 2] == 0)
    {
        goto done;
    }
    FUN_00195020(base[index + 2]);
    base[index + 2] = 0;
    base[index] = 0;
done:
    ;
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
#define FUN_003971a0(...) ((u32 (*)(...))FUN_003971a0)(__VA_ARGS__)
#undef FUN_003973e0
#define FUN_003973e0(...) ((u8 (*)(...))FUN_003973e0)(__VA_ARGS__)
#undef FUN_00397450
#define FUN_00397450(...) ((void (*)(...))FUN_00397450)(__VA_ARGS__)
#undef FUN_00397500
#define FUN_00397500(...) ((u32 (*)(...))FUN_00397500)(__VA_ARGS__)
#undef FUN_00397510
#define FUN_00397510(...) ((void (*)(...))FUN_00397510)(__VA_ARGS__)
#undef FUN_00397520
#define FUN_00397520(...) ((u32 (*)(...))FUN_00397520)(__VA_ARGS__)
#undef FUN_00397580
#define FUN_00397580(...) ((u32 (*)(...))FUN_00397580)(__VA_ARGS__)
#undef FUN_00397630
#define FUN_00397630(...) ((u32 (*)(...))FUN_00397630)(__VA_ARGS__)
#undef FUN_003976f0
#define FUN_003976f0(...) ((u32 (*)(...))FUN_003976f0)(__VA_ARGS__)
#undef FUN_003977c0
#define FUN_003977c0(...) ((u8 (*)(...))FUN_003977c0)(__VA_ARGS__)
#undef FUN_00397870
#define FUN_00397870(...) ((u32 (*)(...))FUN_00397870)(__VA_ARGS__)
