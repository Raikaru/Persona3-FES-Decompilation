#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern u32 LAB_003c5438;
extern u32 LAB_003c5550;
extern u32 LAB_003c5594;
extern u32 LAB_003c5598;
extern u32 LAB_003c5700;
extern u32 LAB_003c5720;
extern u32 LAB_003c58a0;
extern u32 LAB_003c58b0;
extern u32 LAB_003c58c0;
#pragma alias LAB_003c58a0_abs LAB_003c58a0
extern u8 LAB_003c58a0_abs[];
#pragma alias LAB_003c58b0_abs LAB_003c58b0
extern u8 LAB_003c58b0_abs[];
#pragma alias LAB_003c58c0_abs LAB_003c58c0
extern u8 LAB_003c58c0_abs[];
#pragma alias LAB_003c58d0_abs LAB_003c58d0
extern u8 LAB_003c58d0_abs[];
#pragma alias LAB_003c58e0_abs LAB_003c58e0
extern u8 LAB_003c58e0_abs[];
extern u32 LAB_003c58d0;
extern u32 LAB_003c58e0;

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
u32  FUN_003c5240(u32 param_1,u32 param_2,u32 param_3,u16 param_4,u16 param_5);
void FUN_003c53e0(u32 *param_1,u32 param_2);
#pragma alias FUN_003c53e0_3 FUN_003c53e0
extern void FUN_003c53e0_3(u32 *param_1,u32 param_2,u32 param_3);
#pragma alias FUN_003c5840_direct FUN_003c5840
extern void FUN_003c5840_direct(u32 param_1,u32 param_2);
#pragma alias FUN_003c5870_direct FUN_003c5870
extern void FUN_003c5870_direct(u32 param_1,int param_2);
u32 FUN_003c5460(int param_1);
u32 FUN_003c5470(int param_1);
int FUN_003c5480(int param_1);
u32 FUN_003c5490(u32 param_1);
u64 FUN_003c5760(u32 param_1);
u64 FUN_003c57e0(u64 param_1,int param_2);
u64 FUN_003c5810(u64 param_1,int param_2);
void FUN_003c5840(u64 param_1,int param_2);
u64 FUN_003c5870(u64 param_1,int param_2);
u64 FUN_003c58f0(u32 param_1,long param_2,u32 param_3,u32 param_4);
void FUN_003c5a20(void);
u32 FUN_003c5a40(u32 param_1,u32 param_2,u32 param_3,u32 param_4);
void FUN_003c5af0(u32 param_1);
void FUN_003c5bb0(u32 param_1);
u32 FUN_003c5c50(u32 param_1);
void FUN_003c5d40(u32 param_1,int param_2,int param_3);
#pragma alias FUN_003c4c80_nm_typed FUN_003c4c80
extern u32 FUN_003c4c80_nm_typed(int *param_1, int *param_2);

/* Region call-cast macros */
#define FUN_003c5240(...) ((u32 (*)(...))FUN_003c5240)(__VA_ARGS__)
#define FUN_003c53e0(...) ((void (*)(...))FUN_003c53e0)(__VA_ARGS__)
#define FUN_003c5460(...) ((u32 (*)(...))FUN_003c5460)(__VA_ARGS__)
#define FUN_003c5470(...) ((u32 (*)(...))FUN_003c5470)(__VA_ARGS__)
#define FUN_003c5480(...) ((int (*)(...))FUN_003c5480)(__VA_ARGS__)
#define FUN_003c5490(...) ((u32 (*)(...))FUN_003c5490)(__VA_ARGS__)
#define FUN_003c5760(...) ((u64 (*)(...))FUN_003c5760)(__VA_ARGS__)
#define FUN_003c57e0(...) ((u64 (*)(...))FUN_003c57e0)(__VA_ARGS__)
#define FUN_003c5810(...) ((u64 (*)(...))FUN_003c5810)(__VA_ARGS__)
#define FUN_003c5840(...) ((void (*)(...))FUN_003c5840)(__VA_ARGS__)
#define FUN_003c5870(...) ((u64 (*)(...))FUN_003c5870)(__VA_ARGS__)
#define FUN_003c58f0(...) ((u64 (*)(...))FUN_003c58f0)(__VA_ARGS__)
#define FUN_003c5a20(...) ((void (*)(...))FUN_003c5a20)(__VA_ARGS__)
#define FUN_003c5a40(...) ((u32 (*)(...))FUN_003c5a40)(__VA_ARGS__)
#define FUN_003c5af0(...) ((void (*)(...))FUN_003c5af0)(__VA_ARGS__)
#define FUN_003c5bb0(...) ((void (*)(...))FUN_003c5bb0)(__VA_ARGS__)
#define FUN_003c5c50(...) ((u32 (*)(...))FUN_003c5c50)(__VA_ARGS__)
#define FUN_003c5d40(...) ((void (*)(...))FUN_003c5d40)(__VA_ARGS__)

#undef FUN_003c5240
#undef FUN_003c53e0
// FUN_003C5240


u32

FUN_003c5240(u32 param_1,u32 param_2,u32 param_3,u16 param_4,u16 param_5)



{

  int iVar1;

  u32 *puVar2;

  u32 uVar3;

  u32 uVar4;

  u32 *puVar5;

  

  if (param_1 == 0) {

    FUN_0019d3f0("nmSequence.c",0x86);

  }

  if (param_3 == 0) {

    FUN_0019d3f0("nmSequence.c",0x87);

  }

  puVar5 = (u32 *)param_3;

  if ((int)puVar5 + 0x14 == 0) {

    FUN_0019d3f0("nmSequence.c",0x88);

  }

  iVar1 = *(int *)((int)param_1 + 0x24);

  if (param_2 == 0) {

    FUN_0019d3f0("nmSequence.c",0x8c);

  }

  uVar4 = FUN_003c4650(param_1,param_2,puVar5[4] + 0x30);

  puVar2 = (u32 *)((u32 *)uVar4)[5];

  uVar3 = FUN_003c4f80(puVar5 + 5);

  *puVar2 = uVar3;

  FUN_00521250(puVar2 + 1,puVar5 + 5,0x10);

  puVar2[5] = puVar2[5] | 4;

  puVar2[6] = *puVar5;

  puVar2[7] = puVar5[1];

  puVar2[8] = puVar5[2];

  puVar2[9] = puVar5[3];

  *(u16 *)(puVar2 + 0xb) = param_4;

  *(u16 *)((int)puVar2 + 0x2e) = param_5;

  if (puVar5[4] != 0) {

    puVar2[10] = (u32)(puVar2 + 0xc);

  }

  FUN_003c53e0_3((u32 *)(iVar1 + 0x10),*(u32 *)uVar4,uVar4);

  (*(code *)((int)param_1 + 0x14))(param_1,uVar4);

  return uVar4;

}
#define FUN_003c5240(...) ((u32 (*)(...))FUN_003c5240)(__VA_ARGS__)
#undef FUN_003c53e0
// FUN_003C53E0


void FUN_003c53e0(u32 *param_1,u32 param_2)

{
  u32 *puVar1;

  puVar1 = (u32 *)*param_1;
  while (puVar1 != (u32 *)0x0) {
    if (param_2 < *puVar1) {
      puVar1 = (u32 *)puVar1[3];
      goto found;
    }
    puVar1 = (u32 *)puVar1[4];
    if (puVar1 == (u32 *)0x0) {
      FUN_003c4710(param_1,param_1[1]);
      return;
    }
  }
found:
  FUN_003c4710(param_1,(u32)puVar1);
}

#define FUN_003c53e0(...) ((void (*)(...))FUN_003c53e0)(__VA_ARGS__)
#undef FUN_003c5460
// FUN_003C5460


u32 FUN_003c5460(int param_1)



{

  return *(u32 *)(*(int *)(param_1 + 0x24) + 0xc);

}
#define FUN_003c5460(...) ((u32 (*)(...))FUN_003c5460)(__VA_ARGS__)
#undef FUN_003c5470
// FUN_003C5470


u32 FUN_003c5470(int param_1)



{

  return *(u32 *)(*(int *)(param_1 + 0x14) + 0x28);

}
#define FUN_003c5470(...) ((u32 (*)(...))FUN_003c5470)(__VA_ARGS__)
#undef FUN_003c5480
// FUN_003C5480


int FUN_003c5480(int param_1)



{

  return *(int *)(param_1 + 0x14) + 0x28;

}
#define FUN_003c5480(...) ((int (*)(...))FUN_003c5480)(__VA_ARGS__)
#undef FUN_003c5490
// FUN_003C5490 NONMATCHING


u32 FUN_003c5490(u32 param_1)



{

  u32 uVar8;

  int iVar4;

  u32 *puVar10;

  u16 sVar1;

  u32 *puVar2;

  u32 *puVar14;

  u32 *puVar13;

  int iVar3;

  u32 *puVar5;

  u32 *puVar6;

  u32 uVar7;

  u32 *puVar9;

  u32 uVar10;

  u32 lVar11;

  int iVar12;

  

  if (param_1 == 0) {

    uVar7 = 0xffffffff;

  }

  else {

    iVar12 = (int)param_1;

    puVar2 = *(u32 **)(iVar12 + 0x24);

    puVar10 = (u32 *)puVar2[8];

    while (puVar10 != 0) {
      iVar4 = *(int *)((u8 *)puVar10 + 0x14);

      sVar1 = *(u16 *)((u8 *)iVar4 + 0x2e);

      if (((sVar1 != 0) && (*(u16 *)((u8 *)iVar4 + 0x2e) = sVar1 + -1, sVar1 != 0)) ||

         (puVar10 = (u32 *)FUN_003c49e0(param_1,puVar2 + 8), puVar10 != 0)) {

        puVar10 = *(u32 **)((u8 *)puVar10 + 0x10);

      }

    }

    iVar3 = *(int *)(iVar12 + 0x24);

    puVar14 = *(u32 **)(iVar3 + 0x10);

LAB_003c5598:

    if (puVar14 != (u32 *)0x0) {

      iVar4 = puVar14[5];

      sVar1 = *(u16 *)(iVar4 + 0x2c);

      if ((sVar1 == 0) || (*(u16 *)(iVar4 + 0x2c) = sVar1 + -1, puVar9 = puVar14, sVar1 == 0))

      goto LAB_003c5550;

      goto LAB_003c5594;

    }
    if ((*puVar2 & 1) == 0) {

      lVar11 = (*(code *)puVar2[2])(param_1);

      if (lVar11 != 0) {

        *puVar2 = *puVar2 | 1;

      }

      puVar13 = *(u32 **)(iVar12 + 4);

LAB_003c5720:

      if (puVar13 != (u32 *)0x0) {

        *(u32 **)(iVar12 + 0xc) = puVar13;

        uVar8 = puVar13[5];

        FUN_003c5840_direct(param_1,(u32)puVar13);
        lVar11 = 0;

        if ((lVar11 == 0) && ((*(u32 *)(uVar8 + 0x14) & 1) == 0)) {

          puVar13 = (u32 *)puVar13[4];

        }

        else {

          do {

            if (lVar11 == 0) break;

            lVar11 = (*(code *)lVar11)(param_1,puVar13);

          } while (lVar11 != 0);

          uVar10 = *(u32 *)(uVar8 + 0x14) & 0xfffffffb;

          *(u32 *)(uVar8 + 0x14) = uVar10;

          *(u32 *)(uVar8 + 0x14) = uVar10 | 8;

          puVar5 = (u32 *)puVar13[4];

          FUN_003c4820(iVar12 + 4,puVar13);

          puVar6 = (u32 *)puVar2[8];

          do {

            uVar8 = 0;

            if (puVar6 == (u32 *)0x0) {

LAB_003c5700:

              FUN_003c4710(puVar2 + 8,uVar8,puVar13);

              puVar13 = puVar5;

              goto LAB_003c5720;

            }

            if (*puVar13 < *puVar6) {

              uVar8 = puVar6[3];

              goto LAB_003c5700;

            }

            puVar6 = (u32 *)puVar6[4];

          } while (puVar6 != (u32 *)0x0);

          FUN_003c4710(puVar2 + 8,puVar2[9],puVar13);

          puVar13 = puVar5;

        }

        goto LAB_003c5720;

      }

      uVar7 = 0;

    }

    else {

      *puVar2 = *puVar2 & 0xfffffffe;

      FUN_003c4a90(param_1,puVar2 + 4);

      FUN_003c4a90(param_1,puVar2 + 8);

      FUN_003c4a90(param_1,iVar12 + 4);

      uVar7 = 1;

    }

  }

  return uVar7;

LAB_003c5550:

  puVar9 = (u32 *)FUN_003c4820(iVar3 + 0x10,puVar14);

  FUN_003c53e0_3((u32 *)(iVar12 + 4),*puVar14,(u32)puVar14);

  *(u32 *)(iVar4 + 0x14) = *(u32 *)(iVar4 + 0x14) & 0xfffffffb;

  puVar14 = puVar9;

  if (puVar9 != (u32 *)0x0) {

LAB_003c5594:

    puVar14 = (u32 *)puVar9[4];

  }

  goto LAB_003c5598;

}
#define FUN_003c5490(...) ((u32 (*)(...))FUN_003c5490)(__VA_ARGS__)
#undef FUN_003c5760
// FUN_003C5760


u64 FUN_003c5760(u32 param_1)



{

  int iVar1;

  

  if (param_1 == 0) {

    FUN_0019d3f0("nmSequence.c",0x1ce);

  }

  for (iVar1 = *(int *)((int)param_1 + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {

    FUN_003c5870_direct(param_1,iVar1);

  }

  return 0;

}
#define FUN_003c5760(...) ((u64 (*)(...))FUN_003c5760)(__VA_ARGS__)
#undef FUN_003c57e0
// FUN_003C57E0


u64 FUN_003c57e0(u64 param_1,int param_2)



{

  (*(code *)(*(int *)(param_2 + 0x14) + 0x18))();

  return 0;

}
#define FUN_003c57e0(...) ((u64 (*)(...))FUN_003c57e0)(__VA_ARGS__)
#undef FUN_003c5810
// FUN_003C5810


u64 FUN_003c5810(u64 param_1,int param_2)



{

  (*(code *)(*(int *)(param_2 + 0x14) + 0x1c))();

  return 0;

}
#define FUN_003c5810(...) ((u64 (*)(...))FUN_003c5810)(__VA_ARGS__)
#undef FUN_003c5840
// FUN_003C5840


void FUN_003c5840(u64 param_1,int param_2)



{

  (*(code *)(*(int *)(param_2 + 0x14) + 0x20))();

  return;

}
#define FUN_003c5840(...) ((void (*)(...))FUN_003c5840)(__VA_ARGS__)
#undef FUN_003c5870
// FUN_003C5870


u64 FUN_003c5870(u64 param_1,int param_2)



{

  (*(code *)(*(int *)(param_2 + 0x14) + 0x24))();

  return 0;

}
// FUN_003C58A0
void FUN_003c58a0(void)
{
  return;
}
// FUN_003C58B0
void FUN_003c58b0(void)
{
  return;
}
// FUN_003C58C0
void FUN_003c58c0(void)
{
  return;
}
// FUN_003C58D0
void FUN_003c58d0(void)
{
  return;
}
// FUN_003C58E0
void FUN_003c58e0(void)
{
  return;
}
#define FUN_003c5870(...) ((u64 (*)(...))FUN_003c5870)(__VA_ARGS__)
#undef FUN_003c58f0
// FUN_003C58F0 NONMATCHING


u64 FUN_003c58f0(u32 param_1,long param_2,u32 param_3,u32 param_4)



{

  u32 uVar3;

  u32 *puVar1;

  u32 uVar2;

  

  uVar3 = FUN_003c44d0((int)param_2 + 0x48,0x3c60c0,0x3c60f0,0x3c6120);

  puVar1 = *(u32 **)((int)uVar3 + 0x24);

  if (param_2 != 0) {

    puVar1[0x11] = (u32)(puVar1 + 0x12);

  }

  puVar1[3] = param_4;

  *(u16 *)((int)puVar1 + 6) = 5;

  *(u16 *)(puVar1 + 2) = 5;

  puVar1[8] = param_3;

  puVar1[0xc] = (u32)LAB_003c58c0_abs;

  puVar1[0xd] = (u32)LAB_003c58d0_abs;

  puVar1[0xe] = (u32)LAB_003c58a0_abs;

  puVar1[0xf] = (u32)LAB_003c58b0_abs;

  puVar1[0x10] = (u32)LAB_003c58e0_abs;

  *(u16 *)((int)puVar1 + 10) = 0;

  uVar2 = *puVar1;

  *puVar1 = uVar2 | 8;

  *puVar1 = uVar2 | 0x1008;

  if ((param_1 & 1) != 0) {

    FUN_003c6ee0(uVar3);

    *puVar1 = *puVar1 | 0x200;

  }

  return uVar3;

}
#define FUN_003c58f0(...) ((u64 (*)(...))FUN_003c58f0)(__VA_ARGS__)
#undef FUN_003c5a20
// FUN_003C5A20


void FUN_003c5a20(void)



{

  FUN_003c45f0();

  return;

}
#define FUN_003c5a20(...) ((void (*)(...))FUN_003c5a20)(__VA_ARGS__)
#undef FUN_003c5a40
// FUN_003C5A40


u32 FUN_003c5a40(u32 param_1,u32 param_2,u32 param_3,u32 param_4)



{

  u32 uVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = (int)param_3;

  iVar3 = iVar2 + 0x20;

  if (param_4 != 0) {

    iVar3 = iVar3 + 0x20;

  }

  uVar1 = FUN_003c4910(param_1,param_2,iVar3);

  iVar3 = *(int *)((int)uVar1 + 0x14);

  if (param_3 != 0) {

    *(int *)(iVar3 + 0x1c) = iVar3 + 0x20;

  }

  if (param_4 != 0) {

    iVar2 = iVar2 + iVar3 + 0x20;

    *(int *)(iVar3 + 8) = iVar2;

    FUN_00524270(iVar2,param_4);

  }

  *(u32 *)(*(int *)((int)param_1 + 0x24) + 0x2c) = *(u32 *)((int)param_1 + 4);

  return uVar1;

}
#define FUN_003c5a40(...) ((u64 (*)(...))FUN_003c5a40)(__VA_ARGS__)
#undef FUN_003c5af0
// FUN_003C5AF0 NONMATCHING


void FUN_003c5af0(u32 param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar4 = (int)param_1;

  iVar1 = *(int *)(iVar4 + 0x24);

  iVar2 = FUN_003c4d20(param_1,iVar4 + 4);

  if (iVar2 != 0) {

    if (*(int *)(*(int *)(*(int *)(iVar1 + 0x2c) + 0x14) + 0xc) <

        *(int *)(*(int *)(iVar2 + 0x14) + 0xc)) {

      if (iVar2 == *(int *)(iVar4 + 8)) {

        iVar4 = *(int *)(iVar1 + 0x20);


        do {
          iVar3 = *(int *)(iVar2 + 0xc);

          if (iVar3 == 0) break;

          iVar2 = iVar3;
          iVar4 = iVar4 + -1;
        } while (iVar4 > 0);

        *(int *)(iVar1 + 0x2c) = iVar2;

      }

    }

    else {

      iVar2 = *(int *)(*(int *)(iVar1 + 0x2c) + 0xc);

      if (iVar2 != 0) {

        *(int *)(iVar1 + 0x2c) = iVar2;

      }

    }

  }

  return;

}
#define FUN_003c5af0(...) ((void (*)(...))FUN_003c5af0)(__VA_ARGS__)
#undef FUN_003c5bb0
// FUN_003C5BB0 NONMATCHING


void FUN_003c5bb0(u32 param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  u32 uVar4;

  

  iVar3 = (int)param_1;

  iVar1 = *(int *)(iVar3 + 0x24);

  iVar2 = FUN_003c4c80(param_1,iVar3 + 4);

  if (iVar2 != 0) {

    uVar4 = (*(int *)(iVar1 + 0x20) + *(int *)(*(int *)(*(int *)(iVar1 + 0x2c) + 0x14) + 0xc)) - 1;

    if (*(u32 *)(*(int *)(iVar2 + 0x14) + 0xc) < uVar4) {

      if (iVar2 == *(int *)(iVar3 + 4)) {

        *(int *)(iVar1 + 0x2c) = iVar2;

      }

    }

    else if (uVar4 != *(u16 *)(iVar3 + 0x10)) {

      *(u32 *)(iVar1 + 0x2c) = *(u32 *)(*(int *)(iVar1 + 0x2c) + 0x10);

    }

  }

  return;

}
#define FUN_003c5bb0(...) ((void (*)(...))FUN_003c5bb0)(__VA_ARGS__)
#undef FUN_003c5c50
// FUN_003C5C50 NONMATCHING


u32 FUN_003c5c50(u32 param_1)



{

  int iVar1;

  int iVar2;

  u32 uVar7;

  int iVar4;

  int iVar5;

  int iVar6;
  int iVar7;

  int iVar3;

  

  uVar7 = 0;

  iVar4 = (int)param_1;

  iVar1 = *(int *)(iVar4 + 0x24);

  iVar2 = *(int *)(iVar1 + 0x20);

  iVar6 = *(int *)(iVar1 + 0x2c);
  iVar7 = FUN_003c6f80() - 1;
  for (iVar5 = 0; iVar5 < iVar7;) {
    if (iVar6 == 0) {
      return 0;
    }
    iVar6 = *(int *)(iVar6 + 0x10);
    iVar5 = iVar5 + 1;
  }

  iVar3 = 0;
  while (iVar3 < iVar2) {
    if (iVar6 == *(int *)(iVar4 + 8)) {
      break;
    }
    iVar6 = *(int *)(iVar6 + 0x10);
    *(u32 *)(iVar1 + 0x2c) = *(u32 *)(*(int *)(iVar1 + 0x2c) + 0x10);
    uVar7 = FUN_003c4c80_nm_typed((int *)param_1,((int *)param_1) + 1);
    iVar3 = iVar3 + 1;
  }

  return uVar7;

}
#define FUN_003c5c50(...) ((u64 (*)(...))FUN_003c5c50)(__VA_ARGS__)
#undef FUN_003c5d40
// FUN_003C5D40 NONMATCHING


void FUN_003c5d40(u32 param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  iVar3 = (int)param_1;

  iVar1 = *(int *)(iVar3 + 0x24);

  iVar2 = FUN_003c6f80();

  if (param_2 != 0) {

    iVar4 = 0;

    iVar5 = param_2;

    while ((iVar4 < (iVar2 - param_3) + -1 && (*(int *)(iVar5 + 0x10) != 0))) {

      iVar4 = iVar4 + 1;

      iVar5 = *(int *)(iVar5 + 0x10);

    }

    while ((iVar2 = iVar2 + -1, iVar5 != 0 && (iVar2 != 0))) {

      iVar5 = *(int *)(iVar5 + 0xc);

    }

    if (iVar5 == 0) {

      iVar5 = *(int *)(iVar3 + 4);

    }

    *(int *)(iVar1 + 0x2c) = iVar5;

    FUN_003c4de0(param_1,iVar3 + 4,param_2);

  }

  return;

}
#define FUN_003c5d40(...) ((void (*)(...))FUN_003c5d40)(__VA_ARGS__)
