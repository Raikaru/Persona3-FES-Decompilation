#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern u32 DAT_007ce680;
extern u32 LAB_003cff00;
extern u32 LAB_003d00e8;

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
u64 FUN_003cfe50(void);

/* Region call-cast macros */
#define FUN_003cfe50(...) ((u64 (*)(...))FUN_003cfe50)(__VA_ARGS__)

#undef FUN_003cfe50
// FUN_003CFE50 NONMATCHING


u64 FUN_003cfe50(void)



{

  u16 uVar1;

  u8 bVar2;

  short sVar3;

  long lVar4;

  int iVar5;

  u16 *puVar6;

  int iVar7;

  u16 *puVar8;

  

  if (DAT_007ce680 == 0) {

    FUN_0019d3f0("fclBankManager.c",0x270);

  }

  iVar7 = *(int *)(DAT_007ce680 + 0x24);

  iVar5 = *(int *)(DAT_007ce680 + 4);

  do {

    if (iVar5 == 0) goto LAB_003cff00;

    iVar5 = *(int *)(iVar5 + 0x10);

    sVar3 = FUN_003cf6c0();

  } while (sVar3 != -1);

  FUN_005225a8(0x7cd728,0x6a4270,0x279);

  FUN_005225a8(0x6a4318);

  FUN_001052b0(0x6a4318);

LAB_003cff00:

  puVar8 = (u16 *)(iVar7 + 4);

  iVar7 = 0;

  do {

    if (2 < iVar7) {

      FUN_003cfb50();

      return 0;

    }

    if ((*puVar8 & 1) != 0) {

      if (((*puVar8 & 2) != 0) && (lVar4 = FUN_00106ff0((short)iVar7), lVar4 != 0)) {

        uVar1 = *puVar8;

        *puVar8 = uVar1 & 0xfffd;

        *puVar8 = uVar1 & 0xfffd | 4;

        if ((uVar1 & 0x400) != 0) {

          *puVar8 = uVar1 & 0xfdfd | 4;

          *puVar8 = uVar1 & 0xf9fd | 4;

        }

      }

      uVar1 = *puVar8;

      if (((uVar1 & 2) == 0) && ((uVar1 & 4) != 0)) {

        if ((uVar1 & 0x200) == 0) {

          if ((uVar1 & 0x400) == 0) {

            if ((uVar1 & 0x800) == 0) {

              if ((uVar1 & 0x1000) != 0) {

                FUN_005225a8(0x7cd728,0x6a4270,699);

                FUN_005225a8(0x7cd748);

                FUN_001052b0(0x7cd748);

                uVar1 = *puVar8;

                *puVar8 = uVar1 & 0xefff;

                *puVar8 = uVar1 & 0xeffb;

                *puVar8 = uVar1 & 0xeffa;

                FUN_00106730(puVar8[4]);

              }

            }

            else if ((uVar1 & 8) == 0) {

              FUN_005225a8(0x7cd728,0x6a4270,0x2b2);

              FUN_005225a8(0x7cd740);

              FUN_001052b0(0x7cd740);

              uVar1 = *puVar8;

              *puVar8 = uVar1 & 0xf7ff;

              *puVar8 = uVar1 & 0xf7fb;

              *puVar8 = uVar1 & 0xf7fa;

              FUN_00106730(puVar8[4]);

            }

            else {

              *puVar8 = uVar1 | 0x400;

            }

          }

          else {

            FUN_005225a8(0x7cd728,0x6a4270,0x2a3);

            FUN_005225a8(0x7cd738);

            FUN_001052b0(0x7cd738);

            uVar1 = *puVar8;

            *puVar8 = uVar1 & 0xfbff;

            if ((uVar1 & 8) != 0) {

              *puVar8 = uVar1 & 0xfbfb;

              puVar8[1] = 4;

            }

          }

        }

        else if ((uVar1 & 8) == 0) {

          lVar4 = FUN_003cfac0(puVar8);

          if (lVar4 != 0) {

            FUN_005225a8(0x7cd728,0x6a4270,0x298);

            FUN_005225a8(0x7cd730);

            FUN_001052b0(0x7cd730);

            uVar1 = *puVar8;

            *puVar8 = uVar1 & 0xfdff;

            *puVar8 = uVar1 & 0xfdfb;

            puVar8[1] = 1;

            puVar6 = (u16 *)(*(int *)(DAT_007ce680 + 0x24) + 4);

            for (iVar5 = 0; iVar5 < 3; iVar5 = iVar5 + 1) {

              if ((((puVar6 != puVar8) && (uVar1 = *puVar6, (uVar1 & 1) != 0)) && ((uVar1 & 8) != 0)

                  ) && (((uVar1 & 0x100) == (*puVar8 & 0x100) &&

                        (*(u32 *)(puVar6 + 2) >> 0x10 == *(u32 *)(puVar8 + 2) >> 0x10)))) {

                bVar2 = 1;

                goto LAB_003d00e8;

              }

              puVar6 = puVar6 + 10;

            }

            bVar2 = 0;

LAB_003d00e8:

            if (bVar2) {

              *puVar8 = *puVar8 | 0x20;

            }

          }

        }

        else {

          *puVar8 = uVar1 & 0xfdff;

        }

      }

    }

    puVar8 = puVar8 + 10;

    iVar7 = iVar7 + 1;

  } while( 1 );

}
#define FUN_003cfe50(...) ((u64 (*)(...))FUN_003cfe50)(__VA_ARGS__)
