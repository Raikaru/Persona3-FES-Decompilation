#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern u32 DAT_006a28d0;
extern u8 DAT_006a28b0[];
extern u8 DAT_006a29f0[];
#pragma alias DAT_006a28d0_abs DAT_006a28d0
extern u32 DAT_006a28d0_abs[];
extern u16 DAT_006a28f0[];
#pragma alias DAT_006a28f0_abs DAT_006a28f0
extern u16 DAT_006a28f0_abs[];
extern u32 DAT_0095ae10;
#pragma alias DAT_0095ae10_abs DAT_0095ae10
extern u32 DAT_0095ae10_abs[];
extern u32 DAT_00960088;
#pragma alias DAT_00960088_abs DAT_00960088
extern u32 DAT_00960088_abs[];
extern code DAT_00960090;
#pragma alias DAT_00960090_abs DAT_00960090
extern code DAT_00960090_abs[];
extern code DAT_009600a0;
#pragma alias DAT_009600a0_abs DAT_009600a0
extern code DAT_009600a0_abs[];
extern code DAT_00960178;
#pragma alias DAT_00960178_abs DAT_00960178
extern code DAT_00960178_abs[];
extern code DAT_0096017c;
#pragma alias DAT_0096017c_abs DAT_0096017c
extern code DAT_0096017c_abs[];
extern u8 *DAT_007ce644;
#define piGpffffb954 ((int *)DAT_007ce644)
#define uGpffffb954 (*(u32 *)DAT_007ce644)
#define iGpffffb954 DAT_007ce644

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
void FUN_003b35e0(int param_1);
void FUN_003b3740(void);
void FUN_003b3770(void);
u64  FUN_003b38f0(float param_1,int param_2,int param_3,u32 param_4,short param_5,u32 param_6,  u32 param_7,u32 param_8);
long FUN_003b3d60(u64 param_1,u64 param_2,u64 param_3);
long FUN_003b3dd0(void);
u32 FUN_003b3e00(u32 param_1,short param_2);
u32 FUN_003b3e60(u32 param_1,u32 param_2,u32 param_3);
void FUN_003b3f90(int param_1,u8 *param_2,int param_3);
/* Region call-cast macros */
#define FUN_003b35e0(...) ((void (*)(...))FUN_003b35e0)(__VA_ARGS__)
#define FUN_003b3740(...) ((void (*)(...))FUN_003b3740)(__VA_ARGS__)
#define FUN_003b3770(...) ((void (*)(...))FUN_003b3770)(__VA_ARGS__)
#define FUN_003b38f0(...) ((u64 (*)(...))FUN_003b38f0)(__VA_ARGS__)
#define FUN_003b3d60(...) ((long (*)(...))FUN_003b3d60)(__VA_ARGS__)
#define FUN_003b3dd0(...) ((long (*)(...))FUN_003b3dd0)(__VA_ARGS__)
#define FUN_003b3e00(...) ((u32 (*)(...))FUN_003b3e00)(__VA_ARGS__)
#define FUN_003b3e60(...) ((u32 (*)(...))FUN_003b3e60)(__VA_ARGS__)
#define FUN_003b3f90(...) ((void (*)(...))FUN_003b3f90)(__VA_ARGS__)

#undef FUN_003b35e0
// FUN_003B35E0 NONMATCHING


void FUN_003b35e0(int count)
{
  int i;
  int size;
  u32 memory;
  int *node;
  u32 block;

  size = count * 0x21c + 0x18;
  if (piGpffffb954 != (int *)0x0) {
    FUN_0019d3f0("frFontRaster.c",0x24);
  }
  memory = (*DAT_00960178_abs)(size,0x40000);
  piGpffffb954 = (int *)memory;
  FUN_00521408(memory,0,size);
  *piGpffffb954 = count;
  piGpffffb954[1] = (int)(piGpffffb954 + 6);
  node = (int *)piGpffffb954[1];
  node[3] = (int)(node + 7);
  piGpffffb954[4] = (int)node;
  for (i = 0; i < count - 1; i = i + 1) {
    int *next = (int *)node[3];
    node[6] = (int)(next + 0x80);
    next[0x83] = (int)(next + 0x87);
    node = next + 0x80;
  }
  piGpffffb954[5] = (int)node;
  node = (int *)piGpffffb954[4];
  while (node != (int *)0x0) {
    block = FUN_004ce0f0(0x20,0x20,4,0x4504);
    node[5] = block;
    if (block == 0) {
      FUN_005225a8((u32)(uintptr_t)DAT_006a28b0);
    } else {
      node = (int *)node[6];
    }
  }
}
#define FUN_003b35e0(...) ((void (*)(...))FUN_003b35e0)(__VA_ARGS__)
#undef FUN_003b3740
// FUN_003B3740


void FUN_003b3740(void)



{

  (*DAT_0096017c_abs)(DAT_007ce644);

  DAT_007ce644 = 0;

  return;

}
#define FUN_003b3740(...) ((void (*)(...))FUN_003b3740)(__VA_ARGS__)
#undef FUN_003b3770
// FUN_003B3770 NONMATCHING


void FUN_003b3770(void)
{
  int *current;
  int *previous;

  previous = (int *)0x0;
  current = *(int **)(iGpffffb954 + 8);
  while (current != (int *)0x0) {
    if (((current[0] & 1) == 0) || (current[4] == 0)) {
      *(short *)((char *)current + 10) = *(short *)((char *)current + 10) - 1;
    }
    if (*(short *)((char *)current + 10) < 0) {
      if (previous == (int *)0x0) {
        *(int *)(iGpffffb954 + 8) = current[6];
        if (*(int *)(iGpffffb954 + 8) == 0) {
          *(int *)(iGpffffb954 + 0xc) = 0;
        }
        if (*(int *)(iGpffffb954 + 0x14) == 0) {
          *(int **)(iGpffffb954 + 0x14) = current;
          *(int **)(iGpffffb954 + 0x10) = current;
        } else {
          *(int **)(*(int *)(iGpffffb954 + 0x14) + 0x18) = current;
          *(int **)(iGpffffb954 + 0x14) = current;
        }
        current[6] = 0;
        current = *(int **)(iGpffffb954 + 8);
        previous = (int *)0x0;
      } else if (current[6] == 0) {
        *(int **)(iGpffffb954 + 0xc) = previous;
        previous[6] = 0;
        if (*(int *)(iGpffffb954 + 0x14) == 0) {
          *(int **)(iGpffffb954 + 0x14) = current;
          *(int **)(iGpffffb954 + 0x10) = current;
        } else {
          *(int **)(*(int *)(iGpffffb954 + 0x14) + 0x18) = current;
          *(int **)(iGpffffb954 + 0x14) = current;
        }
        current[6] = 0;
        current = (int *)0x0;
      } else {
        previous[6] = current[6];
        if (*(int *)(iGpffffb954 + 0x14) == 0) {
          *(int **)(iGpffffb954 + 0x14) = current;
          *(int **)(iGpffffb954 + 0x10) = current;
        } else {
          *(int **)(*(int *)(iGpffffb954 + 0x14) + 0x18) = current;
          *(int **)(iGpffffb954 + 0x14) = current;
        }
        current[6] = 0;
        current = (int *)previous[6];
      }
    } else {
      previous = current;
      current = (int *)current[6];
    }
  }
}
#define FUN_003b3770(...) ((void (*)(...))FUN_003b3770)(__VA_ARGS__)
#undef FUN_003b38f0
// FUN_003B38F0 NONMATCHING
u64

FUN_003b38f0(float param_1,int param_2,int param_3,u32 param_4,short param_5,u32 param_6,

            u32 param_7,u32 param_8)



{

  float fVar1;

  float fVar2;

  int iVar3;

  float *pfVar4;

  int iVar5;

  float *pfVar6;

  int iVar7;

  float *pfVar8;

  u32 *puVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float afStack_140 [5];

  float fStack_12c;

  float fStack_128;

  float fStack_124;

  float afStack_120 [8];

  float afStack_100 [64];

  

  fVar12 = (float)param_2 / 16.0;

  fVar11 = (float)param_3 / 8.0;

  iVar5 = FUN_00198590();

  fVar10 = *(float *)(iVar5 + 0x80);

  pfVar6 = (float *)&DAT_006a28d0_abs;

  pfVar8 = afStack_120;

  iVar5 = 4;

  do {

    fVar1 = *pfVar6;

    fVar2 = pfVar6[1];

    pfVar6 = pfVar6 + 2;

    iVar5 = iVar5 + -1;

    *pfVar8 = fVar1;

    pfVar8[1] = fVar2;

    pfVar8 = pfVar8 + 2;

  } while (0 < iVar5);

  pfVar6 = (float *)0x20;

  pfVar8 = afStack_140;

  pfVar4 = pfVar8;

  while (pfVar4 != (float *)0x0) {

    *(u8 *)pfVar8 = 0;

    pfVar8 = (float *)((int)pfVar8 + 1);

    pfVar6 = (float *)((int)pfVar6 + -1);

    pfVar4 = pfVar6;

  }

  if ((long)param_6 < 0) {

    afStack_140[2] = (float)(param_6 & 0xffffffff);

  }

  else {

    afStack_140[2] = (float)(int)param_6;

  }

  afStack_140[2] = fVar12 + afStack_140[2];

  if ((long)param_7 < 0) {

    fStack_12c = (float)(param_7 & 0xffffffff);

  }

  else {

    fStack_12c = (float)(int)param_7;

  }

  fStack_12c = fVar11 + fStack_12c;

  iVar5 = (int)param_4;

  afStack_140[0] = fVar12;

  afStack_140[1] = fVar11;

  afStack_140[3] = fVar11;

  afStack_140[4] = fVar12;

  fStack_128 = afStack_140[2];

  fStack_124 = fStack_12c;

  if (*(int *)(iVar5 + 0x1c) == 0) {

    FUN_0019d3f0("frFontRaster.c",0x99);

  }

  puVar9 = *(u32 **)(*(int *)(iVar5 + 0x1c) + 0xc);

  if ((short)puVar9[2] != param_5) {

    iVar7 = FUN_003b0430(param_4,puVar9[1]);

    *(short *)(*(int *)(iVar5 + 0x1c) + 4) = *(short *)(*(int *)(iVar5 + 0x1c) + 4) + -1;

    iVar3 = *(int *)(iVar5 + 0x1c);

    if ((iVar3 != 0) && (*(short *)(iVar3 + 4) == 0)) {

      puVar9 = *(u32 **)(iVar3 + 0xc);

      if (puVar9 != (u32 *)0x0) {

        *puVar9 = *puVar9 & 0xfffffffe;

        puVar9[4] = 0;

      }

      FUN_003b4580(*(u32 *)(iVar3 + 8));

      *(u32 *)DAT_0095ae10_abs = *(u32 *)DAT_0095ae10_abs + -1;

    }

    *(int *)(iVar5 + 0x1c) = iVar7;

    puVar9 = *(u32 **)(iVar7 + 0xc);

  }

  *puVar9 = *puVar9 | 1;

  if ((param_8 & 0xff) != 0) {

    FUN_00521408(afStack_100,0,0x100);

    for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {

      afStack_100[iVar5 * 0x10 + 2] = *(float *)DAT_00960088_abs - param_1;

      afStack_100[iVar5 * 0x10 + 6] = 1.0 / fVar10;

      afStack_100[iVar5 * 0x10 + 4] = afStack_120[iVar5 * 2];

      afStack_100[iVar5 * 0x10 + 5] = afStack_120[iVar5 * 2 + 1];

      afStack_100[iVar5 * 0x10 + 8] = (float)(param_8 >> 0x18);

      afStack_100[iVar5 * 0x10 + 9] = (float)(param_8 >> 0x10 & 0xff);

      afStack_100[iVar5 * 0x10 + 10] = (float)(param_8 >> 8 & 0xff);

      afStack_100[iVar5 * 0x10 + 0xb] = (float)(param_8 & 0xff);

      afStack_100[iVar5 * 0x10] = afStack_140[iVar5 * 2];

      afStack_100[iVar5 * 0x10 + 1] = afStack_140[iVar5 * 2 + 1];

    }

    (*DAT_00960090_abs)(1,puVar9[5]);

    (*DAT_009600a0_abs)(4,afStack_100,4);

  }

  return 0;

}
#define FUN_003b38f0(...) ((u64 (*)(...))FUN_003b38f0)(__VA_ARGS__)
#undef FUN_003b3d60
// FUN_003B3D60 NONMATCHING


long FUN_003b3d60(u64 param_1,u64 param_2,u64 param_3)



{

  long lVar1;

  

  lVar1 = FUN_003b3e00(param_1,param_3);

  if ((lVar1 == 0) && (lVar1 = FUN_003b3e60(param_1,param_2,param_3), lVar1 == 0)) {

    lVar1 = 0;

  }

  return lVar1;

}
#define FUN_003b3d60(...) ((long (*)(...))FUN_003b3d60)(__VA_ARGS__)
#undef FUN_003b3dd0
// FUN_003B3DD0 NONMATCHING


long FUN_003b3dd0(void)



{

  long lVar1;

  

  lVar1 = FUN_003b3e00();

  if (lVar1 == 0) {

    lVar1 = 0;

  }

  return lVar1;

}
#define FUN_003b3dd0(...) ((long (*)(...))FUN_003b3dd0)(__VA_ARGS__)
#undef FUN_003b3e00
// FUN_003B3E00 NONMATCHING


u32 FUN_003b3e00(u32 param_1,short param_2)



{

  u32 *puVar1;

  

  puVar1 = *(u32 **)(iGpffffb954 + 8);

  while( 1 ) {

    if (puVar1 == (u32 *)0x0) {

      return (u32)0;

    }

    if ((puVar1[1] == param_1) && ((short)puVar1[2] == param_2)) break;

    puVar1 = (u32 *)puVar1[6];

  }

  *(u16 *)((int)puVar1 + 10) = 1;

  *puVar1 = *puVar1 | 1;

  return (u32)puVar1;

}
#define FUN_003b3e00(...) ((u32 (*)(...))FUN_003b3e00)(__VA_ARGS__)
#undef FUN_003b3e60
#undef FUN_003b3f90
// FUN_003B3E60


u32 FUN_003b3e60(u32 param_1,u32 param_2,u32 param_3)
{
  u32 *puVar1;

  if (param_2 == 0) {
    FUN_0019d3f0("frFontRaster.c",0x123);
  }
  puVar1 = *(u32 **)(iGpffffb954 + 0x10);
  if (puVar1 != (u32 *)0x0) {
    *(u32 *)(iGpffffb954 + 0x10) = puVar1[6];
    if (*(int *)(iGpffffb954 + 0x10) == 0) {
      *(u32 *)(iGpffffb954 + 0x14) = 0;
    }
    puVar1[6] = 0;
    if (*(int *)(iGpffffb954 + 0xc) != 0) {
      *(u32 *)(*(int *)(iGpffffb954 + 0xc) + 0x18) = (u32)puVar1;
      *(u32 *)(iGpffffb954 + 0xc) = (u32)puVar1;
    }
    else {
      *(u32 *)(iGpffffb954 + 0xc) = (u32)puVar1;
      *(u32 *)(iGpffffb954 + 8) = (u32)puVar1;
    }
    puVar1[4] = 0;
  }
  if (puVar1 == (u32 *)0x0) {
    return 0;
  }
  FUN_003b3f90((int)puVar1,(u8 *)param_2,param_3);
  puVar1[1] = param_1;
  *(u16 *)((int)puVar1 + 10) = 1;
  *puVar1 = *puVar1 | 1;
  FUN_00521250(puVar1[3],param_2,0x200);
  puVar1[4] = 0;
  return (u32)puVar1;
}
#define FUN_003b3e60(...) ((u32 (*)(...))FUN_003b3e60)(__VA_ARGS__)
#undef FUN_003b3f90
// FUN_003B3F90 NONMATCHING


void FUN_003b3f90(int param_1,u8 *param_2,int param_3)



{

  short uVar1;

  short uVar2;

  long lVar3;

  int iVar4;

  u32 uVar5;

  u16 *puVar6;

  u32 uVar7;

  short *puVar8;

  u32 uVar9;

  u32 uVar10;
  u8 *src;

  u8 *pbVar11;

  u16 auStack_100 [128];

  

  if (param_2 == (u8 *)0x0) {
    FUN_005225a8((u32)(uintptr_t)DAT_006a29f0);
    FUN_0019d3f0("frFontRaster.c",0x179);
    return;
  }
  puVar8 = (short *)DAT_006a28f0_abs;


    puVar6 = auStack_100;

    iVar4 = 0x40;

    do {

      uVar1 = *puVar8;

      uVar2 = puVar8[1];

      puVar8 = puVar8 + 2;

      iVar4 = iVar4 + -1;

      *puVar6 = uVar1;

      puVar6[1] = uVar2;

      puVar6 = puVar6 + 2;

    } while (0 < iVar4);

    src = param_2;
    iVar4 = FUN_004ce200(*(u32 *)(param_1 + 0x14),0,9);

    for (uVar5 = 0; (int)uVar5 < 0x20; uVar5 = uVar5 + 1) {

      for (uVar7 = 0; (int)uVar7 < 0x20; uVar7 = uVar7 + 1) {

        uVar9 = (u32)auStack_100

                      [((int)(uVar5 & 7) >> 2) * 0x40 + (uVar5 & 3) * 0x10 + (uVar7 & 0xf)] +

                (((int)(uVar7 & 0xffff) >> 4) * 0x20 + ((int)(uVar5 & 0xffff) >> 2) * 0x80 & 0xffffU

                );

        pbVar11 = (u8 *)(iVar4 + ((int)(uVar9 & 0xffff) >> 1));

        uVar10 = (int)(u32)*src >> ((uVar7 & 1) << 2);

        if ((uVar9 & 1) == 0) {

          *pbVar11 = (u8)uVar10 & 0xf;

        }

        else {

          *pbVar11 = *pbVar11 | (u8)((uVar10 & 0xf) << 4);

        }

        if ((uVar7 & 1) != 0) {

          src = src + 1;

        }

      }

    }

    FUN_004cde00(*(u32 *)(param_1 + 0x14));

    lVar3 = FUN_004cdf30(*(u32 *)(param_1 + 0x14),1);

    if (lVar3 == 0) {

      FUN_0019d3f0("frFontRaster.c",0x1ac);

    }

    FUN_00521250(lVar3,param_3 * 0x40 + 0x6a2130,0x40);

    FUN_004cde40(*(u32 *)(param_1 + 0x14));

    *(short *)(param_1 + 8) = (short)param_3;


  return;

}
#define FUN_003b3f90(...) ((void (*)(...))FUN_003b3f90)(__VA_ARGS__)
