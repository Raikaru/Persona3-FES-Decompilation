#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern s32 DAT_007ce680;
extern s32 DAT_007cd728;
extern s32 DAT_007cd730;
extern s32 DAT_007cd738;
extern s32 DAT_007cd740;
extern s32 DAT_007cd748;
extern char DAT_006a4270[];
extern char DAT_006a4318[];
extern u32 LAB_003cff00;
extern u32 LAB_003d00e8;

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
s32 FUN_003cfe50(void);
#pragma alias FUN_003cf6c0_ptr FUN_003cf6c0
extern short FUN_003cf6c0_ptr(int *param_1);

/* Region call-cast macros */
#define FUN_003cfe50(...) ((u64 (*)(...))FUN_003cfe50)(__VA_ARGS__)

#undef FUN_003cfe50
#pragma opt_loop_invariants on
// FUN_003CFE50


s32 FUN_003cfe50(void)
{
  short uVar1;
  s32 bVar2;
  short sVar3;
  s32 lVar4;
  short *puVar6;
  short *puVar8;
  int iVar8;
  int iVar7;
  u32 iVar9 = (u32)-0x10000;

  if (DAT_007ce680 == 0) {
    FUN_0019d3f0("fclBankManager.c",0x270);
  }

  {
    int *iVar5;
    int *iVar6;

    iVar8 = *(int *)(DAT_007ce680 + 0x24);
    iVar5 = *(int **)(DAT_007ce680 + 4);

    while (iVar5 != 0) {
      iVar6 = *(int **)((char *)iVar5 + 0x10);
      sVar3 = FUN_003cf6c0_ptr(iVar5);
      if (sVar3 == -1) {
        FUN_005225a8((&DAT_007cd728),DAT_006a4270,0x279);
        FUN_005225a8(DAT_006a4318);
        FUN_001052b0(DAT_006a4318);
        break;
      }
      iVar5 = iVar6;
    }
  }

  puVar8 = (short *)(iVar8 + 4);
  for (iVar7 = 0; iVar7 < 3; iVar7++) {
    if ((*puVar8 & 1) != 0) {
      if (((*puVar8 & 2) != 0) &&
          (lVar4 = FUN_00106ff0((short)iVar7), lVar4 != 0)) {
        *puVar8 = *puVar8 & ~2;
        *puVar8 = *puVar8 | 4;
        if ((*puVar8 & 0x400) != 0) {
          *puVar8 = *puVar8 & ~0x200;
          *puVar8 = *puVar8 & ~0x400;
        }
      }

      uVar1 = *puVar8;
      if (((uVar1 & 2) == 0) && ((uVar1 & 4) != 0)) {
        if ((uVar1 & 0x200) != 0) {
          if ((uVar1 & 8) != 0) {
            *puVar8 = *puVar8 & ~0x200;
          }
          else {
            lVar4 = FUN_003cfac0(puVar8);
            if (lVar4 != 0) {
              FUN_005225a8((&DAT_007cd728),DAT_006a4270,0x298);
              FUN_005225a8((&DAT_007cd730));
              FUN_001052b0((&DAT_007cd730));
              *puVar8 = *puVar8 & ~0x200;
              *puVar8 = *puVar8 & ~4;
              puVar8[1] = 1;
              puVar6 = (short *)(*(int *)(DAT_007ce680 + 0x24) + 4);
              {
                int iVar5;
                for (iVar5 = 0; iVar5 < 3; iVar5 = iVar5 + 1) {
                  if ((((puVar6 != puVar8) &&
                        (uVar1 = *puVar6, (uVar1 & 1) != 0)) &&
                       ((uVar1 & 8) != 0)) &&
                      (((uVar1 & 0x100) == (*puVar8 & 0x100)) &&
                       ((*(u32 *)(puVar6 + 2) & iVar9) >> 0x10 ==
                        (*(u32 *)(puVar8 + 2) & iVar9) >> 0x10))) {
                    bVar2 = 1;
                    goto LAB_003d00e8;
                  }
                  puVar6 = puVar6 + 10;
                }
              }
              bVar2 = 0;
LAB_003d00e8:
              if (bVar2) {
                *puVar8 = *puVar8 | 0x20;
              }
            }
          }
        }
        else if ((uVar1 & 0x400) != 0) {
          FUN_005225a8((&DAT_007cd728),DAT_006a4270,0x2a3);
          FUN_005225a8((&DAT_007cd738));
          FUN_001052b0((&DAT_007cd738));
          *puVar8 = *puVar8 & ~0x400;
          if ((*puVar8 & 8) != 0) {
            *puVar8 = *puVar8 & ~4;
            puVar8[1] = 4;
          }
        }
        else if ((uVar1 & 0x800) != 0) {
          if ((uVar1 & 8) != 0) {
            *puVar8 = uVar1 | 0x400;
          }
          else {
            FUN_005225a8((&DAT_007cd728),DAT_006a4270,0x2b2);
            FUN_005225a8((&DAT_007cd740));
            FUN_001052b0((&DAT_007cd740));
            *puVar8 = *puVar8 & ~0x800;
            *puVar8 = *puVar8 & ~4;
            *puVar8 = *puVar8 & ~1;
            FUN_00106730(puVar8[4]);
          }
        }
        else if ((uVar1 & 0x1000) != 0) {
          FUN_005225a8((&DAT_007cd728),DAT_006a4270,0x2bb);
          FUN_005225a8((&DAT_007cd748));
          FUN_001052b0((&DAT_007cd748));
          *puVar8 = *puVar8 & ~0x1000;
          *puVar8 = *puVar8 & ~4;
          *puVar8 = *puVar8 & ~1;
          FUN_00106730(puVar8[4]);
        }
      }
    }
    puVar8 = puVar8 + 10;
  }

  FUN_003cfb50();
  return 0;
}
#pragma opt_loop_invariants off
#define FUN_003cfe50(...) ((u64 (*)(...))FUN_003cfe50)(__VA_ARGS__)
