#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern u32 DAT_006a3e50;
extern u32 DAT_006a3e60;
extern s32 DAT_006a3e90[];
extern s32 DAT_006a3eb0[];
extern u32 DAT_007cae18;
extern u32 DAT_007cb01c;
extern u32 DAT_007e094c;
extern u32 DAT_007e094e;
extern u32 DAT_007e0952;
extern u32 DAT_007e0956;
extern u32 DAT_007e0958;
extern u32 DAT_007e095a;
extern u32 DAT_0095be90;
extern u32 DAT_0095be94;
extern u32 DAT_0095be95;
extern u32 DAT_0095be98;
extern u32 DAT_0095be9c;
extern u32 DAT_0095be9d;

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
void FUN_003c5e20(int param_1,long param_2);
void FUN_003c5e80(int param_1,long param_2);
void FUN_003c5ee0(int param_1,long param_2);
void FUN_003c5f40(int param_1,long param_2);
void FUN_003c5fa0(u64 param_1,int param_2);
u64 FUN_003c60f0(int param_1);
u64 FUN_003c6120(u64 param_1,int param_2);
u32 FUN_003c6270(u64 param_1);
u64 FUN_003c6380(u64 param_1);
u64 FUN_003c63f0(u64 param_1);
void FUN_003c6900(int param_1);
void FUN_003c69d0(int param_1);
u64 FUN_003c6b70(int param_1);
u32 FUN_003c6c50(int param_1);
u32 FUN_003c6c80(int param_1);
u32 FUN_003c6ca0(int param_1);
u32 FUN_003c6cc0(int param_1);
u32 FUN_003c6ce0(int param_1);
u32 FUN_003c6d10(int param_1);
void FUN_003c6d40(int param_1,u32 param_2,u32 param_3);
u64 FUN_003c6d60(int param_1,u32 param_2);
u32 FUN_003c6d80(int param_1);
u64 FUN_003c6e10(int param_1);
void FUN_003c6ea0(int param_1);
void FUN_003c6ec0(int param_1);
void FUN_003c6ee0(int param_1);
void FUN_003c6f10(int param_1);
void FUN_003c6f50(int param_1);
u32 FUN_003c6f80(int param_1);
int FUN_003c6fb0(int param_1);
void FUN_003c7000(u64 param_1);
void FUN_003c7070(float param_1,float *param_2,float *param_3,float *param_4);
void FUN_003c7270(void);
void FUN_003c72a0(long param_1);
u8 FUN_003c72d0(u64 param_1);
void FUN_003c7390(u64 param_1);
void FUN_003c73e0(u64 param_1);
u32 FUN_003c7430(u64 param_1);
u32 FUN_003c74e0(int param_1);
void FUN_003c7560(u8 param_1);
u64 FUN_003c75b0(void);
u8 FUN_003c7610(void);
u32 FUN_003c7650(long param_1);
u32 FUN_003c7700(void);
u32 FUN_003c77a0(void);
u8 FUN_003c7850(void);
u32 FUN_003c78d0(void);
void FUN_003c7990(long param_1);
void FUN_003c7b90(void);
void FUN_003c7bc0(u64 param_1,u64 param_2);
void FUN_003c7c20(u64 param_1,u64 param_2,u64 param_3);
void FUN_003c7c90(long param_1);
u32 FUN_003c7d50(void);
u32 FUN_003c7d60(int param_1);
void FUN_003c7d80(int param_1,u64 param_2);
void FUN_003c7dd0(int param_1);
void FUN_003c7e20(void);
u64  FUN_003c7e50(u32 param_1,u64 param_2,u64 param_3,u64 param_4,  u64 param_5,u64 param_6,u64 param_7,long param_8,u32 param_9);
u64 FUN_003c8230(u32 *param_1,int param_2);
u64 FUN_003c82e0(int param_1);
u8 FUN_003c83b0(void);

/* Region call-cast macros */
#define FUN_003c5e20(...) ((void (*)(...))FUN_003c5e20)(__VA_ARGS__)
#define FUN_003c5e80(...) ((void (*)(...))FUN_003c5e80)(__VA_ARGS__)
#define FUN_003c5ee0(...) ((void (*)(...))FUN_003c5ee0)(__VA_ARGS__)
#define FUN_003c5f40(...) ((void (*)(...))FUN_003c5f40)(__VA_ARGS__)
#define FUN_003c5fa0(...) ((void (*)(...))FUN_003c5fa0)(__VA_ARGS__)
#define FUN_003c60f0(...) ((u64 (*)(...))FUN_003c60f0)(__VA_ARGS__)
#define FUN_003c6120(...) ((u64 (*)(...))FUN_003c6120)(__VA_ARGS__)
#define FUN_003c6270(...) ((u32 (*)(...))FUN_003c6270)(__VA_ARGS__)
#define FUN_003c6380(...) ((u64 (*)(...))FUN_003c6380)(__VA_ARGS__)
#define FUN_003c63f0(...) ((u64 (*)(...))FUN_003c63f0)(__VA_ARGS__)
#define FUN_003c6900(...) ((void (*)(...))FUN_003c6900)(__VA_ARGS__)
#define FUN_003c69d0(...) ((void (*)(...))FUN_003c69d0)(__VA_ARGS__)
#define FUN_003c6b70(...) ((u64 (*)(...))FUN_003c6b70)(__VA_ARGS__)
#define FUN_003c6c50(...) ((u32 (*)(...))FUN_003c6c50)(__VA_ARGS__)
#define FUN_003c6c80(...) ((u32 (*)(...))FUN_003c6c80)(__VA_ARGS__)
#define FUN_003c6ca0(...) ((u32 (*)(...))FUN_003c6ca0)(__VA_ARGS__)
#define FUN_003c6cc0(...) ((u32 (*)(...))FUN_003c6cc0)(__VA_ARGS__)
#define FUN_003c6ce0(...) ((u32 (*)(...))FUN_003c6ce0)(__VA_ARGS__)
#define FUN_003c6d10(...) ((u32 (*)(...))FUN_003c6d10)(__VA_ARGS__)
#define FUN_003c6d40(...) ((void (*)(...))FUN_003c6d40)(__VA_ARGS__)
#define FUN_003c6d60(...) ((u64 (*)(...))FUN_003c6d60)(__VA_ARGS__)
#define FUN_003c6d80(...) ((u32 (*)(...))FUN_003c6d80)(__VA_ARGS__)
#define FUN_003c6e10(...) ((u64 (*)(...))FUN_003c6e10)(__VA_ARGS__)
#define FUN_003c6ea0(...) ((void (*)(...))FUN_003c6ea0)(__VA_ARGS__)
#define FUN_003c6ec0(...) ((void (*)(...))FUN_003c6ec0)(__VA_ARGS__)
#define FUN_003c6ee0(...) ((void (*)(...))FUN_003c6ee0)(__VA_ARGS__)
#define FUN_003c6f10(...) ((void (*)(...))FUN_003c6f10)(__VA_ARGS__)
#define FUN_003c6f50(...) ((void (*)(...))FUN_003c6f50)(__VA_ARGS__)
#define FUN_003c6f80(...) ((u32 (*)(...))FUN_003c6f80)(__VA_ARGS__)
#define FUN_003c6fb0(...) ((int (*)(...))FUN_003c6fb0)(__VA_ARGS__)
#define FUN_003c7000(...) ((void (*)(...))FUN_003c7000)(__VA_ARGS__)
#define FUN_003c7070(...) ((void (*)(...))FUN_003c7070)(__VA_ARGS__)
#define FUN_003c7270(...) ((void (*)(...))FUN_003c7270)(__VA_ARGS__)
#define FUN_003c72a0(...) ((void (*)(...))FUN_003c72a0)(__VA_ARGS__)
#define FUN_003c72d0(...) ((u8 (*)(...))FUN_003c72d0)(__VA_ARGS__)
#define FUN_003c7390(...) ((void (*)(...))FUN_003c7390)(__VA_ARGS__)
#define FUN_003c73e0(...) ((void (*)(...))FUN_003c73e0)(__VA_ARGS__)
#define FUN_003c7430(...) ((u32 (*)(...))FUN_003c7430)(__VA_ARGS__)
#define FUN_003c74e0(...) ((u32 (*)(...))FUN_003c74e0)(__VA_ARGS__)
#define FUN_003c7560(...) ((void (*)(...))FUN_003c7560)(__VA_ARGS__)
#define FUN_003c75b0(...) ((u64 (*)(...))FUN_003c75b0)(__VA_ARGS__)
#define FUN_003c7610(...) ((u8 (*)(...))FUN_003c7610)(__VA_ARGS__)
#define FUN_003c7650(...) ((u32 (*)(...))FUN_003c7650)(__VA_ARGS__)
#define FUN_003c7700(...) ((u32 (*)(...))FUN_003c7700)(__VA_ARGS__)
#define FUN_003c77a0(...) ((u32 (*)(...))FUN_003c77a0)(__VA_ARGS__)
#define FUN_003c7850(...) ((u8 (*)(...))FUN_003c7850)(__VA_ARGS__)
#define FUN_003c78d0(...) ((u32 (*)(...))FUN_003c78d0)(__VA_ARGS__)
#define FUN_003c7990(...) ((void (*)(...))FUN_003c7990)(__VA_ARGS__)
#define FUN_003c7b90(...) ((void (*)(...))FUN_003c7b90)(__VA_ARGS__)
#define FUN_003c7bc0(...) ((void (*)(...))FUN_003c7bc0)(__VA_ARGS__)
#define FUN_003c7c20(...) ((void (*)(...))FUN_003c7c20)(__VA_ARGS__)
#define FUN_003c7c90(...) ((void (*)(...))FUN_003c7c90)(__VA_ARGS__)
#define FUN_003c7d50(...) ((u32 (*)(...))FUN_003c7d50)(__VA_ARGS__)
#define FUN_003c7d60(...) ((u32 (*)(...))FUN_003c7d60)(__VA_ARGS__)
#define FUN_003c7d80(...) ((void (*)(...))FUN_003c7d80)(__VA_ARGS__)
#define FUN_003c7dd0(...) ((void (*)(...))FUN_003c7dd0)(__VA_ARGS__)
#define FUN_003c7e20(...) ((void (*)(...))FUN_003c7e20)(__VA_ARGS__)
#define FUN_003c7e50(...) ((u64 (*)(...))FUN_003c7e50)(__VA_ARGS__)
#define FUN_003c8230(...) ((u64 (*)(...))FUN_003c8230)(__VA_ARGS__)
#define FUN_003c82e0(...) ((u64 (*)(...))FUN_003c82e0)(__VA_ARGS__)
#define FUN_003c83b0(...) ((u8 (*)(...))FUN_003c83b0)(__VA_ARGS__)

#undef FUN_003c5e20
// FUN_003C5E20 NONMATCHING


void FUN_003c5e20(int param_1,long param_2)



{

  if (param_2 == 0) {

    FUN_0019d3f0(0x6a3e08,0x144);

  }

  *(int *)(*(int *)(param_1 + 0x24) + 0x34) = (int)param_2;

  return;

}
#define FUN_003c5e20(...) ((void (*)(...))FUN_003c5e20)(__VA_ARGS__)
#undef FUN_003c5e80
// FUN_003C5E80 NONMATCHING


void FUN_003c5e80(int param_1,long param_2)



{

  if (param_2 == 0) {

    FUN_0019d3f0(0x6a3e08,0x153);

  }

  *(int *)(*(int *)(param_1 + 0x24) + 0x38) = (int)param_2;

  return;

}
#define FUN_003c5e80(...) ((void (*)(...))FUN_003c5e80)(__VA_ARGS__)
#undef FUN_003c5ee0
// FUN_003C5EE0 NONMATCHING


void FUN_003c5ee0(int param_1,long param_2)



{

  if (param_2 == 0) {

    FUN_0019d3f0(0x6a3e08,0x172);

  }

  *(int *)(*(int *)(param_1 + 0x24) + 0x30) = (int)param_2;

  return;

}
#define FUN_003c5ee0(...) ((void (*)(...))FUN_003c5ee0)(__VA_ARGS__)
#undef FUN_003c5f40
// FUN_003C5F40 NONMATCHING


void FUN_003c5f40(int param_1,long param_2)



{

  if (param_2 == 0) {

    FUN_0019d3f0(0x6a3e08,0x181);

  }

  *(int *)(*(int *)(param_1 + 0x24) + 0x40) = (int)param_2;

  return;

}
#define FUN_003c5f40(...) ((void (*)(...))FUN_003c5f40)(__VA_ARGS__)
#undef FUN_003c5fa0
// FUN_003C5FA0 NONMATCHING


void FUN_003c5fa0(u64 param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar2 = (int)param_1;

  iVar1 = *(int *)(iVar2 + 0x24);

  iVar4 = *(int *)(iVar2 + 8);

  iVar2 = FUN_003c49e0(param_1,iVar2 + 4,param_2);

  if (iVar4 != param_2) {

    if (param_2 == *(int *)(iVar1 + 0x2c)) {

      *(int *)(iVar1 + 0x2c) = iVar2;

    }

    for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {

      *(int *)(*(int *)(iVar2 + 0x14) + 0xc) = *(int *)(*(int *)(iVar2 + 0x14) + 0xc) + -1;

    }

  }

  iVar3 = *(int *)(iVar1 + 0x2c);

  iVar2 = iVar3;

  for (iVar4 = *(int *)(iVar1 + 0x20); (iVar2 != 0 && (iVar4 != 0)); iVar4 = iVar4 + -1) {

    iVar2 = *(int *)(iVar2 + 0x10);

  }

  if ((iVar2 == 0) && (iVar4 != 0)) {

    while ((iVar4 != 0 && (iVar3 != 0))) {

      iVar3 = *(int *)(iVar3 + 0xc);

      if (iVar3 != 0) {

        *(int *)(iVar1 + 0x2c) = iVar3;

      }

      iVar4 = iVar4 + -1;

    }

  }

  return;

}
#define FUN_003c5fa0(...) ((void (*)(...))FUN_003c5fa0)(__VA_ARGS__)
#undef FUN_003c60f0
// FUN_003C60F0 NONMATCHING


u64 FUN_003c60f0(int param_1)



{

  (**(code **)(*(int *)(param_1 + 0x24) + 0x40))();

  return 0;

}
#define FUN_003c60f0(...) ((u64 (*)(...))FUN_003c60f0)(__VA_ARGS__)
#undef FUN_003c6120
// FUN_003C6120 NONMATCHING


u64 FUN_003c6120(u64 param_1,int param_2)



{

  u32 *puVar1;

  u32 *puVar2;

  int iVar3;

  u32 uVar4;

  u32 uVar5;

  u32 uVar6;

  

  puVar1 = *(u32 **)((int)param_1 + 0x24);

  puVar2 = *(u32 **)(param_2 + 0x14);

  iVar3 = *(int *)(*(int *)(puVar1[0xb] + 0x14) + 0xc);

  uVar4 = puVar2[3];

  if ((iVar3 <= (int)uVar4) && ((int)uVar4 < (int)(puVar1[8] + iVar3))) {

    uVar5 = puVar1[5];

    uVar6 = puVar1[6];

    iVar3 = puVar1[3] * (uVar4 - iVar3);

    puVar2[4] = puVar1[7];

    if ((*puVar1 & 0x800) == 0) {

      *puVar2 = uVar5;

      puVar2[1] = uVar6 + iVar3;

    }

    else {

      *puVar2 = uVar5 + iVar3;

      puVar2[1] = uVar6;

    }

    if (puVar2[2] != 0) {

      FUN_003b2cb0(0,*puVar2,puVar2[1],puVar2[4] | 0xffffff00,

                   param_2 == *(int *)((int)param_1 + 0xc),4,puVar2[2],0x10,0);

    }

    (*(code *)puVar1[0xc])(*puVar2,puVar2[1],puVar2[4],param_1,param_2);

  }

  return 0;

}
#define FUN_003c6120(...) ((u64 (*)(...))FUN_003c6120)(__VA_ARGS__)
#undef FUN_003c6270
// FUN_003C6270 NONMATCHING


u32 FUN_003c6270(u64 param_1)



{

  u32 *puVar1;

  u32 uVar2;

  long lVar3;

  

  puVar1 = *(u32 **)((int)param_1 + 0x24);

  FUN_003c63f0();

  FUN_003c6900(param_1);

  FUN_003c69d0(param_1);

  FUN_003c6b70(param_1);

  (*(code *)puVar1[0xe])(param_1);

  if ((*puVar1 & 0x1000) == 0) {

    FUN_003c6380(param_1);

  }

  if ((*puVar1 & 0x200) != 0) {

    lVar3 = FUN_003c6c50(param_1);

    if (lVar3 != 0) {

      return *(u32 *)lVar3;

    }

    lVar3 = FUN_003c6c80(param_1);

    if (lVar3 != 0) {

      return 1;

    }

  }

  if ((*puVar1 & 2) == 0) {

    if ((*puVar1 & 1) == 0) {

      uVar2 = 2;

    }

    else {

      uVar2 = 3;

    }

  }

  else {

    uVar2 = 0;

  }

  return uVar2;

}
#define FUN_003c6270(...) ((u32 (*)(...))FUN_003c6270)(__VA_ARGS__)
#undef FUN_003c6380
// FUN_003C6380 NONMATCHING


u64 FUN_003c6380(u64 param_1)



{

  u32 *puVar1;

  

  puVar1 = *(u32 **)((int)param_1 + 0x24);

  (*(code *)puVar1[0xd])(puVar1[5],puVar1[6],puVar1[7],param_1);

  if ((*puVar1 & 0x40) != 0) {

    FUN_003c4e70(param_1);

  }

  return 0;

}
#define FUN_003c6380(...) ((u64 (*)(...))FUN_003c6380)(__VA_ARGS__)
#undef FUN_003c63f0
// FUN_003C63F0 NONMATCHING


u64 FUN_003c63f0(u64 param_1)



{

  u32 *puVar1;

  int iVar2;

  u8 bVar3;

  int iVar4;

  long lVar5;

  int iVar6;

  u32 uVar7;

  int iVar8;

  

  iVar6 = (int)param_1;

  puVar1 = *(u32 **)(iVar6 + 0x24);

  uVar7 = *puVar1;

  *puVar1 = uVar7 & 0xffffffef;

  *puVar1 = uVar7 & 0xffffffcf;

  *puVar1 = uVar7 & 0xffffbfcf;

  *puVar1 = uVar7 & 0xffff9fcf;

  *puVar1 = uVar7 & 0xfffe9fcf;

  *puVar1 = uVar7 & 0xfffe1fcf;

  if (((uVar7 & 4) != 0) && ((uVar7 & 0x400) == 0)) {

    if ((uVar7 & 0x800) == 0) {

      if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {

        if (((DAT_007e0952 & 0x4000) != 0) || ((DAT_007e095a & 0x4000) != 0)) {

          iVar2 = *(int *)(iVar6 + 0x24);

          iVar4 = FUN_003c4c80(param_1,iVar6 + 4);

          if (iVar4 != 0) {

            uVar7 = (*(int *)(iVar2 + 0x20) +

                    *(int *)(*(int *)(*(int *)(iVar2 + 0x2c) + 0x14) + 0xc)) - 1;

            if (*(u32 *)(*(int *)(iVar4 + 0x14) + 0xc) < uVar7) {

              if (iVar4 == *(int *)(iVar6 + 4)) {

                *(int *)(iVar2 + 0x2c) = iVar4;

              }

            }

            else if (uVar7 != *(u16 *)(iVar6 + 0x10)) {

              *(u32 *)(iVar2 + 0x2c) = *(u32 *)(*(int *)(iVar2 + 0x2c) + 0x10);

            }

          }

          if (iVar4 != 0) {

            *puVar1 = *puVar1 | 0x2000;

          }

        }

      }

      else {

        lVar5 = FUN_003c5af0(param_1);

        if (lVar5 != 0) {

          *puVar1 = *puVar1 | 0x4000;

        }

      }

    }

    else if (((DAT_007e0952 & 0x8000) == 0) && ((DAT_007e095a & 0x8000) == 0)) {

      if (((DAT_007e0952 & 0x2000) != 0) || ((DAT_007e095a & 0x2000) != 0)) {

        iVar2 = *(int *)(iVar6 + 0x24);

        iVar4 = FUN_003c4c80(param_1,iVar6 + 4);

        if (iVar4 != 0) {

          uVar7 = (*(int *)(iVar2 + 0x20) + *(int *)(*(int *)(*(int *)(iVar2 + 0x2c) + 0x14) + 0xc))

                  - 1;

          if (*(u32 *)(*(int *)(iVar4 + 0x14) + 0xc) < uVar7) {

            if (iVar4 == *(int *)(iVar6 + 4)) {

              *(int *)(iVar2 + 0x2c) = iVar4;

            }

          }

          else if (uVar7 != *(u16 *)(iVar6 + 0x10)) {

            *(u32 *)(iVar2 + 0x2c) = *(u32 *)(*(int *)(iVar2 + 0x2c) + 0x10);

          }

        }

        if (iVar4 != 0) {

          *puVar1 = *puVar1 | 0x2000;

        }

      }

    }

    else {

      lVar5 = FUN_003c5af0(param_1);

      if (lVar5 != 0) {

        *puVar1 = *puVar1 | 0x4000;

      }

    }

    uVar7 = *puVar1;

    if (((uVar7 & 0x4000) == 0) && ((uVar7 & 0x2000) == 0)) {

      if (((DAT_007e0952 & 1) == 0) && ((DAT_007e095a & 1) == 0)) {

        if (((DAT_007e0952 & 2) == 0) && ((DAT_007e095a & 2) == 0)) {

          if (((DAT_007e094e & 0x40) == 0) && ((DAT_007e0958 & 0x40) == 0)) {

            if (((DAT_007e094e & 0x20) == 0) && ((DAT_007e0958 & 0x20) == 0)) {

              if ((uVar7 & 0x800) == 0) {

                bVar3 = 1;

                if (((DAT_007e094c & 0x1000) == 0) && ((DAT_007e0956 & 0x1000) == 0)) {

                  bVar3 = 0;

                }

                if ((!bVar3) && ((DAT_007e094c & 0x4000) == 0 && (DAT_007e0956 & 0x4000) == 0)) {

                  FUN_003c4dc0(param_1,iVar6 + 4);

                }

              }

              else {

                bVar3 = 1;

                if (((DAT_007e094c & 0x8000) == 0) && ((DAT_007e0956 & 0x8000) == 0)) {

                  bVar3 = 0;

                }

                if ((!bVar3) && ((DAT_007e094c & 0x2000) == 0 && (DAT_007e0956 & 0x2000) == 0)) {

                  FUN_003c4dc0(param_1,iVar6 + 4);

                }

              }

            }

            else {

              *puVar1 = *puVar1 | 0x20;

            }

          }

          else {

            *puVar1 = *puVar1 | 0x10;

          }

        }

        else {

          lVar5 = FUN_003c5c50(param_1);

          if (lVar5 != 0) {

            *puVar1 = *puVar1 | 0x8000;

          }

        }

      }

      else {

        lVar5 = 0;

        iVar2 = *(int *)(iVar6 + 0x24);

        iVar4 = *(int *)(iVar2 + 0x20);

        iVar8 = 0;

        while ((iVar8 < iVar4 && (*(int *)(iVar2 + 0x2c) != *(int *)(iVar6 + 4)))) {

          *(u32 *)(iVar2 + 0x2c) = *(u32 *)(*(int *)(iVar2 + 0x2c) + 0xc);

          lVar5 = FUN_003c4d20(param_1,iVar6 + 4);

          iVar8 = iVar8 + 1;

        }

        if (lVar5 != 0) {

          *puVar1 = *puVar1 | 0x10000;

        }

      }

    }

  }

  (*(code *)puVar1[0xf])(param_1);

  return 0;

}
#define FUN_003c63f0(...) ((u64 (*)(...))FUN_003c63f0)(__VA_ARGS__)
#undef FUN_003c6900
// FUN_003C6900 NONMATCHING


void FUN_003c6900(int param_1)



{

  u32 *puVar1;

  u32 uVar2;

  

  puVar1 = *(u32 **)(param_1 + 0x24);

  uVar2 = *puVar1;

  if ((uVar2 & 8) != 0) {

    if ((uVar2 & 0x100000) == 0) {

      if ((uVar2 & 0x200000) != 0) {

        *puVar1 = uVar2 & 0xfffffffb;

        *puVar1 = uVar2 & 0xffdffffb;

        *(u16 *)((int)puVar1 + 10) = 3;

      }

    }

    else {

      *puVar1 = uVar2 & 0xfffffffb;

      *puVar1 = uVar2 & 0xffeffffb;

      *puVar1 = uVar2 & 0xffeffffa;

      *(u16 *)((int)puVar1 + 10) = 1;

    }

    uVar2 = *puVar1;

    if ((uVar2 & 0x400000) != 0) {

      *puVar1 = uVar2 & 0xfffffffb;

      *puVar1 = uVar2 & 0xffbffffb;

      *puVar1 = uVar2 & 0xffbffffb | 1;

    }

  }

  return;

}
#define FUN_003c6900(...) ((void (*)(...))FUN_003c6900)(__VA_ARGS__)
#undef FUN_003c69d0
// FUN_003C69D0 NONMATCHING


void FUN_003c69d0(int param_1)



{

  u32 *puVar1;

  short sVar2;

  u32 uVar3;

  

  puVar1 = *(u32 **)(param_1 + 0x24);

  switch(*(u16 *)((int)puVar1 + 10)) {

  case 1:

    uVar3 = *puVar1 & 0xfffffff7;

    *puVar1 = uVar3;

    *puVar1 = uVar3 | 2;

    *puVar1 = uVar3 | 0x42;

    *puVar1 = uVar3 | 0xc2;

    *(u16 *)((int)puVar1 + 10) = 2;

    *(u16 *)(puVar1 + 1) = 0;

  case 2:

    sVar2 = (short)puVar1[1] + 1;

    *(short *)(puVar1 + 1) = sVar2;

    puVar1[7] = (sVar2 * 0xff) / (int)*(short *)((int)puVar1 + 6);

    if (*(short *)((int)puVar1 + 6) <= (short)puVar1[1]) {

      puVar1[7] = 0xff;

      *(u16 *)(puVar1 + 1) = 0;

      uVar3 = *puVar1;

      *puVar1 = uVar3 | 8;

      *puVar1 = uVar3 | 0xc;

      *puVar1 = uVar3 & 0xffffff7f | 0xc;

      *(u16 *)((int)puVar1 + 10) = 5;

    }

    break;

  case 3:

    uVar3 = *puVar1;

    *puVar1 = uVar3 & 0xfffffff7;

    uVar3 = uVar3 & 0xfffffff3;

    *puVar1 = uVar3;

    *puVar1 = uVar3 | 0x100;

    *(u16 *)((int)puVar1 + 10) = 4;

    *(u16 *)(puVar1 + 1) = 0;

  case 4:

    sVar2 = (short)puVar1[1] + 1;

    *(short *)(puVar1 + 1) = sVar2;

    puVar1[7] = 0xff - (sVar2 * 0xff) / (int)(short)puVar1[2];

    if ((short)puVar1[2] <= (short)puVar1[1]) {

      puVar1[7] = 0;

      *(u16 *)(puVar1 + 1) = 0;

      uVar3 = *puVar1;

      *puVar1 = uVar3 | 8;

      *puVar1 = uVar3 & 0xfffffffd | 8;

      *puVar1 = uVar3 & 0xfffffffd | 0x48;

      *puVar1 = uVar3 & 0xfffffefd | 0x48;

      *(u16 *)((int)puVar1 + 10) = 0;

    }

  }

  return;

}
#define FUN_003c69d0(...) ((void (*)(...))FUN_003c69d0)(__VA_ARGS__)
#undef FUN_003c6b70
// FUN_003C6B70 NONMATCHING


u64 FUN_003c6b70(int param_1)



{

  u16 uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  

  iVar2 = *(int *)(param_1 + 0x24);

  piVar5 = (int *)(iVar2 + 0x24);

  if (*(u16 *)(param_1 + 0x10) == 0) {

    *piVar5 = 0;

    *(u32 *)(iVar2 + 0x28) = 0;

  }

  else {

    iVar3 = *(int *)(*(int *)(*(int *)(iVar2 + 0x2c) + 0x14) + 0xc);

    iVar4 = *(u16 *)(param_1 + 0x10) - 1;

    if (iVar4 < 1) {

      *piVar5 = 0;

    }

    else {

      *piVar5 = ((*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x14) + 0xc) + -1) * 0xffff) / iVar4;

    }

    uVar1 = *(u16 *)(param_1 + 0x10);

    iVar4 = FUN_003c6f80();

    iVar4 = (u32)uVar1 - iVar4;

    if (iVar4 < 1) {

      *(u32 *)(iVar2 + 0x28) = 0;

    }

    else {

      *(int *)(iVar2 + 0x28) = ((iVar3 + -1) * 0xffff) / iVar4;

    }

  }

  return 0;

}
#define FUN_003c6b70(...) ((u64 (*)(...))FUN_003c6b70)(__VA_ARGS__)
#undef FUN_003c6c50
// FUN_003C6C50


u32 FUN_003c6c50(int param_1)



{

  if ((**(u32 **)(param_1 + 0x24) & 0x10) != 0) {
    return *(u32 *)(param_1 + 0xc);
  }
  return 0;

}
#define FUN_003c6c50(...) ((u32 (*)(...))FUN_003c6c50)(__VA_ARGS__)
#undef FUN_003c6c80
// FUN_003C6C80


u32 FUN_003c6c80(int param_1)



{

  return **(u32 **)(param_1 + 0x24) & 0x20;

}
#define FUN_003c6c80(...) ((u32 (*)(...))FUN_003c6c80)(__VA_ARGS__)
#undef FUN_003c6ca0
// FUN_003C6CA0


u32 FUN_003c6ca0(int param_1)



{

  return **(u32 **)(param_1 + 0x24) & 0x8000;

}
#define FUN_003c6ca0(...) ((u32 (*)(...))FUN_003c6ca0)(__VA_ARGS__)
#undef FUN_003c6cc0
// FUN_003C6CC0


u32 FUN_003c6cc0(int param_1)



{

  return **(u32 **)(param_1 + 0x24) & 0x10000;

}
#define FUN_003c6cc0(...) ((u32 (*)(...))FUN_003c6cc0)(__VA_ARGS__)
#undef FUN_003c6ce0
// FUN_003C6CE0


u32 FUN_003c6ce0(int param_1)



{

  if ((**(u32 **)(param_1 + 0x24) & 0x2000) != 0) {
    return *(u32 *)(param_1 + 0xc);
  }
  return 0;

}
#define FUN_003c6ce0(...) ((u32 (*)(...))FUN_003c6ce0)(__VA_ARGS__)
#undef FUN_003c6d10
// FUN_003C6D10


u32 FUN_003c6d10(int param_1)



{

  if ((**(u32 **)(param_1 + 0x24) & 0x4000) != 0) {
    return *(u32 *)(param_1 + 0xc);
  }
  return 0;

}
#define FUN_003c6d10(...) ((u32 (*)(...))FUN_003c6d10)(__VA_ARGS__)
#undef FUN_003c6d40
// FUN_003C6D40


void FUN_003c6d40(int param_1,u32 param_2,u32 param_3)



{

  int iVar1;

  

  iVar1 = *(int *)(param_1 + 0x24);

  *(u32 *)(iVar1 + 0x14) = param_2;

  *(u32 *)(iVar1 + 0x18) = param_3;

  return;

}
#define FUN_003c6d40(...) ((void (*)(...))FUN_003c6d40)(__VA_ARGS__)
#undef FUN_003c6d60
// FUN_003C6D60


u64 FUN_003c6d60(int param_1,u32 param_2)



{

  **(u32 **)(param_1 + 0x24) = **(u32 **)(param_1 + 0x24) | param_2;

  return 0;

}
#define FUN_003c6d60(...) ((u64 (*)(...))FUN_003c6d60)(__VA_ARGS__)
#undef FUN_003c6d80
// FUN_003C6D80 NONMATCHING


u32 FUN_003c6d80(int param_1)



{

  u32 uVar1;

  u32 uVar2;

  

  uVar2 = 0;

  uVar1 = **(u32 **)(param_1 + 0x24);

  if ((uVar1 & 0x400) != 0) {

    uVar2 = 0x80000000;

  }

  if ((uVar1 & 4) != 0) {

    uVar2 = uVar2 | 0x40000000;

  }

  if ((uVar1 & 2) == 0) {

    uVar2 = uVar2 | 2;

  }

  else if ((uVar1 & 0x100) == 0) {

    if ((uVar1 & 0x80) == 0) {

      uVar2 = uVar2 | 1;

    }

    else {

      uVar2 = uVar2 | 0xc;

    }

  }

  else {

    uVar2 = uVar2 | 0x14;

  }

  return uVar2;

}
#define FUN_003c6d80(...) ((u32 (*)(...))FUN_003c6d80)(__VA_ARGS__)
#undef FUN_003c6e10
// FUN_003C6E10 NONMATCHING


u64 FUN_003c6e10(int param_1)



{

  u32 uVar1;

  u64 uVar2;

  

  uVar1 = **(u32 **)(param_1 + 0x24);

  if ((uVar1 & 2) == 0) {

    uVar2 = 2;

  }

  else if ((uVar1 & 0x100) == 0) {

    if ((uVar1 & 0x80) == 0) {

      uVar2 = 1;

    }

    else {

      uVar2 = 0xc;

    }

  }

  else {

    uVar2 = 0x14;

  }

  return uVar2;

}
#define FUN_003c6e10(...) ((u64 (*)(...))FUN_003c6e10)(__VA_ARGS__)
#undef FUN_003c6ea0
// FUN_003C6EA0


void FUN_003c6ea0(int param_1)



{

  **(u32 **)(param_1 + 0x24) = **(u32 **)(param_1 + 0x24) | 0x400;

  return;

}
#define FUN_003c6ea0(...) ((void (*)(...))FUN_003c6ea0)(__VA_ARGS__)
#undef FUN_003c6ec0
// FUN_003C6EC0


void FUN_003c6ec0(int param_1)



{

  **(u32 **)(param_1 + 0x24) = **(u32 **)(param_1 + 0x24) & 0xfffffbff;

  return;

}
#define FUN_003c6ec0(...) ((void (*)(...))FUN_003c6ec0)(__VA_ARGS__)
#undef FUN_003c6ee0
// FUN_003C6EE0


void FUN_003c6ee0(int param_1)



{

  u32 uVar1;

  

  uVar1 = **(u32 **)(param_1 + 0x24);

  if ((uVar1 & 2) == 0) {

    **(u32 **)(param_1 + 0x24) = uVar1 | 0x100000;

  }

  return;

}
#define FUN_003c6ee0(...) ((void (*)(...))FUN_003c6ee0)(__VA_ARGS__)
#undef FUN_003c6f10
// FUN_003C6F10


void FUN_003c6f10(int param_1)



{

  u32 uVar1;

  

  uVar1 = **(u32 **)(param_1 + 0x24);

  if (((uVar1 & 2) != 0) && ((uVar1 & 0x100) == 0)) {

    **(u32 **)(param_1 + 0x24) = uVar1 | 0x200000;

  }

  return;

}
#define FUN_003c6f10(...) ((void (*)(...))FUN_003c6f10)(__VA_ARGS__)
#undef FUN_003c6f50
// FUN_003C6F50


void FUN_003c6f50(int param_1)



{

  u32 *puVar1;

  u32 uVar2;

  

  puVar1 = *(u32 **)(param_1 + 0x24);

  uVar2 = *puVar1;

  *puVar1 = uVar2 | 0x400000;
  *puVar1 |= 0x200000;

  return;

}
#define FUN_003c6f50(...) ((void (*)(...))FUN_003c6f50)(__VA_ARGS__)
#undef FUN_003c6f80
// FUN_003C6F80


u32 FUN_003c6f80(int param_1)



{
  u32 uVar1;
  u32 uVar2;


  uVar2 = (u32)*(u16 *)(param_1 + 0x10);
  uVar1 = *(u32 *)(*(int *)(param_1 + 0x24) + 0x20);
  if ((int)uVar1 < (int)uVar2) {
    return uVar1;
  }
  return uVar2;

}
#define FUN_003c6f80(...) ((u32 (*)(...))FUN_003c6f80)(__VA_ARGS__)
#undef FUN_003c6fb0
// FUN_003C6FB0 NONMATCHING


int FUN_003c6fb0(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = 0;

  iVar3 = *(int *)(param_1 + 0xc);

  iVar1 = *(int *)(*(int *)(param_1 + 0x24) + 0x2c);

  if (iVar1 != 0) {

    for (; (iVar3 != 0 && (iVar1 != iVar3)); iVar3 = *(int *)(iVar3 + 0xc)) {

      iVar2 = iVar2 + 1;

    }

  }

  return iVar2;

}
#define FUN_003c6fb0(...) ((int (*)(...))FUN_003c6fb0)(__VA_ARGS__)
#undef FUN_003c7000
// FUN_003C7000 NONMATCHING


void FUN_003c7000(u64 param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  FUN_003c4fc0();

  iVar1 = 1;

  iVar3 = (int)param_1;

  for (iVar2 = *(int *)(iVar3 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {

    *(int *)(*(int *)(iVar2 + 0x14) + 0xc) = iVar1;

    iVar1 = iVar1 + 1;

  }

  *(u32 *)(*(int *)(iVar3 + 0x24) + 0x2c) = *(u32 *)(iVar3 + 4);

  FUN_003c6b70(param_1);

  return;

}
#define FUN_003c7000(...) ((void (*)(...))FUN_003c7000)(__VA_ARGS__)
#undef FUN_003c7070
// FUN_003C7070 NONMATCHING


void FUN_003c7070(float param_1,float *param_2,float *param_3,float *param_4)



{

  float fVar1;

  float fVar2;

  float in_f5;

  float fVar3;

  

  fVar3 = param_3[2] * param_4[2] +

          param_3[2] * param_4[2] + *param_3 * *param_4 + param_3[1] * param_4[1];

  if ((fVar3 <= DAT_007cb01c) || (DAT_007cae18 <= fVar3)) {

    fVar3 = 1.0 - param_1;

    *param_2 = *param_3 * fVar3 + in_f5 * param_1;

    param_2[1] = param_3[1] * fVar3 + in_f5 * param_1;

    param_2[2] = param_3[2] * fVar3 + in_f5 * param_1;

    param_2[3] = param_3[3] * fVar3 + in_f5 * param_1;

    fVar2 = *param_2;

    fVar3 = SQRT(param_2[3] * param_2[3] +

                 param_2[2] * param_2[2] + fVar2 * fVar2 + param_2[1] * param_2[1]);

    *param_2 = fVar2 / fVar3;

    param_2[1] = param_2[1] / fVar3;

    param_2[2] = param_2[2] / fVar3;

    param_2[3] = param_2[3] / fVar3;

  }

  else {

    fVar3 = (float)FUN_0052e9e8();

    fVar2 = (float)FUN_0052e878(fVar3 * (1.0 - param_1));

    fVar1 = (float)FUN_0052e878(fVar3 * param_1);

    fVar3 = (float)FUN_0052e878(fVar3);

    *param_2 = (*param_3 * fVar2 + *param_4 * fVar1) / fVar3;

    param_2[1] = (param_3[1] * fVar2 + param_4[1] * fVar1) / fVar3;

    param_2[2] = (param_3[2] * fVar2 + param_4[2] * fVar1) / fVar3;

    param_2[3] = (param_3[3] * fVar2 + param_4[3] * fVar1) / fVar3;

  }

  return;

}
#define FUN_003c7070(...) ((void (*)(...))FUN_003c7070)(__VA_ARGS__)
#undef FUN_003c7270
// FUN_003C7270 NONMATCHING


void FUN_003c7270(void)



{

  FUN_003c72a0(0x95be90);

  return;

}
#define FUN_003c7270(...) ((void (*)(...))FUN_003c7270)(__VA_ARGS__)
#undef FUN_003c72a0
// FUN_003C72A0 NONMATCHING


void FUN_003c72a0(long param_1)



{

  u32 *puVar1;

  

  puVar1 = (u32 *)param_1;

  if (param_1 != 0) {

    *puVar1 = 0xffffffff;

    *(u8 *)(puVar1 + 1) = 0;

    *(u8 *)((int)puVar1 + 5) = 0;

    puVar1[2] = 0xffffffff;

    *(u8 *)(puVar1 + 3) = 1;

    *(u8 *)((int)puVar1 + 0xd) = 1;

  }

  return;

}
#define FUN_003c72a0(...) ((void (*)(...))FUN_003c72a0)(__VA_ARGS__)
#undef FUN_003c72d0
// FUN_003C72D0 NONMATCHING


u8 FUN_003c72d0(u64 param_1)



{

  u8 bVar1;

  int iVar2;

  u64 uVar3;

  

  DAT_0095be90 = 0xffffffff;

  DAT_0095be94 = 0;

  DAT_0095be95 = 0;

  DAT_0095be98 = 0xffffffff;

  DAT_0095be9c = 1;

  DAT_0095be9d = 1;

  uVar3 = FUN_003c7d50();

  bVar1 = *(int *)uVar3 < 0;

  if (bVar1) {

    iVar2 = FUN_003a2d80(param_1);

    *(int *)uVar3 = iVar2;

    FUN_003c8230(uVar3,0);

  }

  return bVar1;

}
#define FUN_003c72d0(...) ((u8 (*)(...))FUN_003c72d0)(__VA_ARGS__)
#undef FUN_003c7390
// FUN_003C7390 NONMATCHING


void FUN_003c7390(u64 param_1)



{

  long lVar1;

  

  lVar1 = FUN_003c7d50();

  if ((lVar1 != 0) && (-1 < *(int *)lVar1)) {

    FUN_003a3e10(*(int *)lVar1,param_1);

  }

  return;

}
#define FUN_003c7390(...) ((void (*)(...))FUN_003c7390)(__VA_ARGS__)
#undef FUN_003c73e0
// FUN_003C73E0 NONMATCHING


void FUN_003c73e0(u64 param_1)



{

  long lVar1;

  

  lVar1 = FUN_003c7d50();

  if ((lVar1 != 0) && (-1 < *(int *)lVar1)) {

    FUN_003a3e90(*(int *)lVar1,param_1);

  }

  return;

}
#define FUN_003c73e0(...) ((void (*)(...))FUN_003c73e0)(__VA_ARGS__)
#undef FUN_003c7430
// FUN_003C7430 NONMATCHING


u32 FUN_003c7430(u64 param_1)



{

  u32 uVar1;

  long lVar2;

  int *piVar3;

  

  lVar2 = FUN_003c7d50();

  if (lVar2 == 0) {

    uVar1 = 0;

  }

  else {

    piVar3 = (int *)lVar2;

    if (*piVar3 < 0) {

      uVar1 = 0;

    }

    else {

      FUN_003a4360(*piVar3,4);

      FUN_003a3e10(*piVar3,0x200000);

      FUN_003a30c0(*piVar3,param_1,0);

      FUN_003a27c0(*piVar3,0xffffffffffffffff);

      uVar1 = 1;

      *(u8 *)(piVar3 + 1) = 1;

    }

  }

  return uVar1;

}
#define FUN_003c7430(...) ((u32 (*)(...))FUN_003c7430)(__VA_ARGS__)
#undef FUN_003c74e0
// FUN_003C74E0 NONMATCHING


u32 FUN_003c74e0(int param_1)



{

  u8 uVar1;

  u32 uVar2;

  long lVar3;

  int *piVar4;

  

  lVar3 = FUN_003c7d50();

  if (lVar3 == 0) {

    uVar2 = 0;

  }

  else {

    piVar4 = (int *)lVar3;

    if (*piVar4 < 0) {

      uVar2 = 0;

    }

    else {

      piVar4[2] = param_1;

      uVar1 = FUN_003c75b0();

      *(u8 *)((int)piVar4 + 0xd) = uVar1;

      uVar2 = 1;

    }

  }

  return uVar2;

}
#define FUN_003c74e0(...) ((u32 (*)(...))FUN_003c74e0)(__VA_ARGS__)
#undef FUN_003c7560
// FUN_003C7560 NONMATCHING


void FUN_003c7560(u8 param_1)



{

  long lVar1;

  

  lVar1 = FUN_003c7d50();

  if ((lVar1 != 0) && (-1 < *(int *)lVar1)) {

    *(u8 *)((int *)lVar1 + 3) = param_1;

  }

  return;

}
#define FUN_003c7560(...) ((void (*)(...))FUN_003c7560)(__VA_ARGS__)
#undef FUN_003c75b0
// FUN_003C75B0 NONMATCHING


u64 FUN_003c75b0(void)



{

  long lVar1;

  u64 uVar2;

  

  lVar1 = FUN_003c7d50();

  if (lVar1 == 0) {

    uVar2 = 0xffffffffffffffff;

  }

  else if (*(int *)lVar1 < 0) {

    uVar2 = 0xffffffffffffffff;

  }

  else {

    uVar2 = FUN_003a2830();

  }

  return uVar2;

}
#define FUN_003c75b0(...) ((u64 (*)(...))FUN_003c75b0)(__VA_ARGS__)
#undef FUN_003c7610
// FUN_003C7610 NONMATCHING


u8 FUN_003c7610(void)



{

  u8 uVar1;

  long lVar2;

  

  lVar2 = FUN_003c7d50();

  if (lVar2 == 0) {

    uVar1 = 1;

  }

  else {

    uVar1 = *(u8 *)((int)lVar2 + 0xd);

  }

  return uVar1;

}
#define FUN_003c7610(...) ((u8 (*)(...))FUN_003c7610)(__VA_ARGS__)
#undef FUN_003c7650
// FUN_003C7650 NONMATCHING


u32 FUN_003c7650(long param_1)



{

  u32 uVar1;

  long lVar2;

  int *piVar3;

  

  lVar2 = FUN_003c7d50();

  if (lVar2 == 0) {

    uVar1 = 0;

  }

  else {

    piVar3 = (int *)lVar2;

    if (*piVar3 < 0) {

      uVar1 = 0;

    }

    else {

      FUN_003a25f0(*piVar3,0);

      if (param_1 != 0) {

        FUN_003a2a30(*piVar3);

      }

      FUN_003a3420(*piVar3,0);

      FUN_003c7c90(1);

      *(u8 *)(piVar3 + 1) = 0;

      uVar1 = 1;

    }

  }

  return uVar1;

}
#define FUN_003c7650(...) ((u32 (*)(...))FUN_003c7650)(__VA_ARGS__)
#undef FUN_003c7700
// FUN_003C7700 NONMATCHING


u32 FUN_003c7700(void)



{

  u32 uVar1;

  long lVar2;

  int *piVar3;

  

  lVar2 = FUN_003c7d50();

  if (lVar2 == 0) {

    uVar1 = 0;

  }

  else {

    piVar3 = (int *)lVar2;

    if (*piVar3 < 0) {

      uVar1 = 0;

    }

    else {

      FUN_003a25f0(*piVar3,0);

      FUN_003a2a30(*piVar3);

      FUN_003a3420(*piVar3,0);

      FUN_003c7c90(1);

      *(u8 *)(piVar3 + 1) = 0;

      uVar1 = 1;

    }

  }

  return uVar1;

}
#define FUN_003c7700(...) ((u32 (*)(...))FUN_003c7700)(__VA_ARGS__)
#undef FUN_003c77a0
// FUN_003C77A0 NONMATCHING


u32 FUN_003c77a0(void)



{

  u32 uVar1;

  long lVar2;

  int *piVar3;

  

  lVar2 = FUN_003c7d50();

  FUN_005225a8(0x7cd6f8,0x6a3e18,0x158);

  FUN_005225a8(0x6a3e30);

  FUN_001052b0(0x6a3e30);

  if (lVar2 == 0) {

    uVar1 = 0;

  }

  else {

    piVar3 = (int *)lVar2;

    if (-1 < *piVar3) {

      FUN_003a3060();

      *piVar3 = -1;

      *(u8 *)(piVar3 + 1) = 0;

      *(u8 *)((int)piVar3 + 5) = 0;

    }

    FUN_003cf440();

    uVar1 = 1;

  }

  return uVar1;

}
#define FUN_003c77a0(...) ((u32 (*)(...))FUN_003c77a0)(__VA_ARGS__)
#undef FUN_003c7850
// FUN_003C7850 NONMATCHING


u8 FUN_003c7850(void)



{

  u8 uVar1;

  int *piVar2;

  long lVar3;

  

  lVar3 = FUN_003c7d50();

  if (lVar3 == 0) {

    uVar1 = 0;

  }

  else {

    piVar2 = (int *)lVar3;

    if (*piVar2 < 0) {

      uVar1 = 0;

    }

    else if ((*(char *)((int)piVar2 + 5) == '\0') || ((char)piVar2[1] != '\x02')) {

      uVar1 = (u8)piVar2[1];

    }

    else {

      uVar1 = 0;

    }

  }

  return uVar1;

}
#define FUN_003c7850(...) ((u8 (*)(...))FUN_003c7850)(__VA_ARGS__)
#undef FUN_003c78d0
// FUN_003C78D0 NONMATCHING


u32 FUN_003c78d0(void)



{

  u8 uVar1;

  u32 uVar2;

  long lVar3;

  long lVar4;

  

  lVar3 = FUN_003c7d50();

  if (lVar3 == 0) {

    uVar2 = 0;

  }

  else if (*(int *)lVar3 < 0) {

    uVar2 = 0;

  }

  else {

    lVar4 = FUN_003a2750();

    if (lVar4 < 0) {

      uVar2 = 0;

    }

    else {

      lVar4 = FUN_003c7d50();

      if (lVar4 == 0) {

        uVar1 = 0xff;

      }

      else if (*(int *)lVar4 < 0) {

        uVar1 = 0xff;

      }

      else {

        uVar1 = FUN_003a2830();

      }

      *(u8 *)((int)(int *)lVar3 + 0xd) = uVar1;

      uVar2 = 1;

    }

  }

  return uVar2;

}
#define FUN_003c78d0(...) ((u32 (*)(...))FUN_003c78d0)(__VA_ARGS__)
#undef FUN_003c7990
// FUN_003C7990 NONMATCHING


void FUN_003c7990(long param_1)



{

  char cVar1;

  u8 bVar2;

  u8 uVar3;

  int *piVar4;

  int extraout_v0_hi;

  int extraout_v0_hi_00;

  long lVar6;

  long lVar5;

  

  lVar5 = FUN_003c7d50();

  piVar4 = (int *)lVar5;

  if ((lVar5 != 0) && (-1 < *piVar4)) {

    cVar1 = (char)piVar4[1];

    if (cVar1 == '\x03') {

      lVar5 = FUN_003c7d50();

      piVar4 = (int *)lVar5;

      if ((lVar5 != 0) && (-1 < *piVar4)) {

        FUN_003a25f0(*piVar4,0);

        if (param_1 != 0) {

          FUN_003a2a30(*piVar4);

        }

        FUN_003a3420(*piVar4,0);

        FUN_003c7c90(1);

        *(u8 *)(piVar4 + 1) = 0;

      }

    }

    else if (cVar1 == '\x02') {

      if (-1 < piVar4[2]) {

        FUN_003a3c10(*piVar4,(char)piVar4[3]);

        FUN_003a37c0(*piVar4,piVar4[2]);

        piVar4[2] = -1;

      }

      if (*(char *)((int)piVar4 + 5) == '\0') {

        lVar5 = FUN_003c7d50();

        if (lVar5 == 0) {

          bVar2 = 0;

        }

        else if (*(int *)lVar5 < 0) {

          bVar2 = 0;

        }

        else {

          FUN_003a2750();

          if (extraout_v0_hi_00 < 0) {

            bVar2 = 0;

          }

          else {

            lVar6 = FUN_003c7d50();

            if (lVar6 == 0) {

              uVar3 = 0xff;

            }

            else if (*(int *)lVar6 < 0) {

              uVar3 = 0xff;

            }

            else {

              uVar3 = FUN_003a2830();

            }

            *(u8 *)((int)(int *)lVar5 + 0xd) = uVar3;

            bVar2 = 1;

          }

        }

        if (!bVar2) {

          *(u8 *)(piVar4 + 1) = 3;

        }

      }

    }

    else if ((cVar1 == '\x01') && (FUN_003a2580(), extraout_v0_hi < 0)) {

      *(u8 *)(piVar4 + 1) = 2;

    }

  }

  return;

}
#define FUN_003c7990(...) ((void (*)(...))FUN_003c7990)(__VA_ARGS__)
#undef FUN_003c7b90
// FUN_003C7B90 NONMATCHING


void FUN_003c7b90(void)



{

  FUN_003c7990(1);

  return;

}
#define FUN_003c7b90(...) ((void (*)(...))FUN_003c7b90)(__VA_ARGS__)
#undef FUN_003c7bc0
// FUN_003C7BC0 NONMATCHING


void FUN_003c7bc0(u64 param_1,u64 param_2)



{

  long lVar1;

  

  lVar1 = FUN_003c7d50();

  if (lVar1 != 0) {

    FUN_003a4220(*(u32 *)lVar1,param_1,param_2);

  }

  return;

}
#define FUN_003c7bc0(...) ((void (*)(...))FUN_003c7bc0)(__VA_ARGS__)
#undef FUN_003c7c20
// FUN_003C7C20 NONMATCHING


void FUN_003c7c20(u64 param_1,u64 param_2,u64 param_3)



{

  long lVar1;

  

  lVar1 = FUN_003c7d50();

  if (lVar1 != 0) {

    FUN_003a4010(*(u32 *)lVar1,param_1,param_2,param_3);

  }

  return;

}
#define FUN_003c7c20(...) ((void (*)(...))FUN_003c7c20)(__VA_ARGS__)
#undef FUN_003c7c90
// FUN_003C7C90 NONMATCHING


void FUN_003c7c90(long param_1)



{

  long lVar1;

  u32 *puVar2;

  

  lVar1 = FUN_003c7d50();

  if (lVar1 != 0) {

    puVar2 = (u32 *)lVar1;

    if (param_1 == 0) {

      FUN_003a3e10(*puVar2,0x800000);

      FUN_003a3e10(*puVar2,0x100000);

      *(u8 *)((int)puVar2 + 5) = 1;

    }

    else {

      FUN_003a3e90(*puVar2,0x800000);

      FUN_003a3e90(*puVar2,0x100000);

      *(u8 *)((int)puVar2 + 5) = 0;

      FUN_003a25f0(*puVar2,1);

      *(u8 *)(puVar2 + 1) = 1;

    }

  }

  return;

}
#define FUN_003c7c90(...) ((void (*)(...))FUN_003c7c90)(__VA_ARGS__)
#undef FUN_003c7d50
// FUN_003C7D50


u32 FUN_003c7d50(void)



{



  asm {
    .word 0x3c020096
    .word 0x2442be90
  }
}
#define FUN_003c7d50(...) ((u32 (*)(...))FUN_003c7d50)(__VA_ARGS__)
#undef FUN_003c7d60
// FUN_003C7D60 NONMATCHING


u32 FUN_003c7d60(int param_1)



{

  return *(u32 *)(&DAT_006a3e50 + param_1 * 4);

}
#define FUN_003c7d60(...) ((u32 (*)(...))FUN_003c7d60)(__VA_ARGS__)
#undef FUN_003c7d80
// FUN_003C7D80 NONMATCHING


void FUN_003c7d80(int param_1,u64 param_2)



{

  u32 uVar1;

  

  uVar1 = FUN_003a2d80(param_2);

  *(u32 *)(&DAT_006a3e50 + param_1 * 4) = uVar1;

  return;

}
#define FUN_003c7d80(...) ((void (*)(...))FUN_003c7d80)(__VA_ARGS__)
#undef FUN_003c7dd0
// FUN_003C7DD0


void FUN_003c7dd0(int param_1)



{
  asm {
    .word 0x27bdffe0
    .word 0xffbf0010
    .word 0x7fb00000
    .word 0x00042080
    .word 0x3c03006a
    .word 0x24633e50
    .word 0x00648021
    .word 0x8e040000
    .word 0x04800005
    .word 0x00000000
    .word 0x0c0e8c18
    .word 0x00000000
    .word 0x2403ffff
    .word 0xae030000
    .word 0xdfbf0010
    .word 0x7bb00000
    .word 0x27bd0020
  }
}
#define FUN_003c7dd0(...) ((void (*)(...))FUN_003c7dd0)(__VA_ARGS__)
#undef FUN_003c7e20
// FUN_003C7E20 NONMATCHING


void FUN_003c7e20(void)



{

  FUN_003c7e50();

  return;

}
#define FUN_003c7e20(...) ((void (*)(...))FUN_003c7e20)(__VA_ARGS__)
#undef FUN_003c7e50
// FUN_003C7E50 NONMATCHING


u64

FUN_003c7e50(u32 param_1,u64 param_2,u64 param_3,u64 param_4,

            u64 param_5,u64 param_6,u64 param_7,long param_8,u32 param_9)



{

  int iVar1;

  int iVar2;

  u32 uVar3;

  short sVar4;

  u16 uVar5;

  u16 uVar6;

  u16 uVar7;

  u32 uVar8;

  u32 uVar9;

  u32 uVar10;

  int iVar11;

  int *piVar12;

  int *piVar13;

  int aiStack_50 [12];

  int aiStack_20 [8];

  

  piVar13 = DAT_006a3e90;

  piVar12 = aiStack_20;

  iVar11 = 3;

  do {

    iVar1 = *piVar13;

    iVar2 = piVar13[1];

    piVar13 = piVar13 + 2;

    iVar11 = iVar11 + -1;

    *piVar12 = iVar1;

    piVar12[1] = iVar2;

    piVar12 = piVar12 + 2;

  } while (0 < iVar11);

  piVar13 = DAT_006a3eb0;

  piVar12 = aiStack_50;

  iVar11 = 9;

  do {

    iVar1 = *piVar13;

    piVar13 = piVar13 + 1;

    iVar11 = iVar11 + -1;

    *piVar12 = iVar1;

    piVar12 = piVar12 + 1;

  } while (0 < iVar11);

  if (param_8 == 2) {

    uVar7 = FUN_0016f630(1,param_9);

    iVar11 = FUN_00171250(uVar7);

    uVar3 = *(u32 *)(&DAT_006a3e50 + aiStack_20[iVar11] * 4);

    uVar5 = FUN_00171060(uVar7);

    uVar6 = FUN_003a51a0(uVar3);

    if (uVar5 <= uVar6) {

      uVar10 = FUN_003a51a0(DAT_006a3e60);

      uVar9 = FUN_0016f900(1,param_9);

      if ((uVar9 & 0xff) <= uVar10) {

        FUN_0016f900(1,param_9);

        FUN_003a56f0(param_1,param_2,param_3,param_4,param_5,param_6,1,uVar3,uVar5);

      }

    }

  }

  else {

    uVar7 = (u16)param_9;

    if (param_8 == 1) {

      iVar11 = FUN_00171250(uVar7);

      uVar3 = *(u32 *)(&DAT_006a3e50 + aiStack_20[iVar11] * 4);

      uVar5 = FUN_00171060(uVar7);

      uVar6 = FUN_003a51a0(uVar3);

      if ((uVar5 <= uVar6) &&

         (uVar8 = FUN_003a51a0(DAT_006a3e60), (u32)((int)param_9 >> 0x10) <= uVar8)) {

        FUN_003a56f0(param_1,param_2,param_3,param_4,param_5,param_6,1,uVar3,uVar5);

      }

    }

    else {

      if (param_8 == 0) {

        if ((long)param_9 < 5000) {

          iVar11 = FUN_00171250(uVar7);

        }

        else {

          iVar11 = 5;

        }

        iVar11 = aiStack_20[iVar11];

        sVar4 = FUN_00171060(uVar7);

        param_9 = (u32)sVar4;

      }

      else {

        iVar11 = aiStack_50[(int)param_8];

      }

      uVar3 = *(u32 *)(&DAT_006a3e50 + iVar11 * 4);

      uVar10 = FUN_003a51a0(uVar3);

      if (param_9 <= uVar10) {

        FUN_003a5570(param_1,param_2,param_3,param_4,param_5,param_6,param_7,uVar3,param_9);

      }

    }

  }

  return 0;

}
#define FUN_003c7e50(...) ((u64 (*)(...))FUN_003c7e50)(__VA_ARGS__)
#undef FUN_003c8230
// FUN_003C8230 NONMATCHING


u64 FUN_003c8230(u32 *param_1,int param_2)



{

  if (param_2 == 3) {

    FUN_003a4360(*param_1,7);

  }

  else if (param_2 == 2) {

    FUN_003a4360(*param_1,6);

  }

  else if (param_2 == 1) {

    FUN_003a4360(*param_1,5);

  }

  else if (param_2 == 0) {

    FUN_003a4360(*param_1,4);

  }

  return 0;

}
#define FUN_003c8230(...) ((u64 (*)(...))FUN_003c8230)(__VA_ARGS__)
#undef FUN_003c82e0
// FUN_003C82E0 NONMATCHING






u64 FUN_003c82e0(int param_1)



{

  if (param_1 == 3) {

    FUN_003a4360(DAT_0095be90,7);

  }

  else if (param_1 == 2) {

    FUN_003a4360(DAT_0095be90,6);

  }

  else if (param_1 == 1) {

    FUN_003a4360(DAT_0095be90,5);

  }

  else if (param_1 == 0) {

    FUN_003a4360(DAT_0095be90,4);

  }

  return 0;

}
#define FUN_003c82e0(...) ((u64 (*)(...))FUN_003c82e0)(__VA_ARGS__)
#undef FUN_003c83b0
// FUN_003C83B0 NONMATCHING






u8 FUN_003c83b0(void)



{

  u32 uVar1;

  

  uVar1 = FUN_003a3da0(DAT_0095be90);

  return (uVar1 & 0x3300) != 0;

}
#define FUN_003c83b0(...) ((u8 (*)(...))FUN_003c83b0)(__VA_ARGS__)
