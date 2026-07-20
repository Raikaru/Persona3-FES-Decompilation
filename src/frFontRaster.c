#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern u32 DAT_006a28d0;
extern u16 DAT_006a28f0[];
extern u32 DAT_0095ae10;
extern u32 DAT_00960088;
extern code DAT_00960090;
extern code DAT_009600a0;
extern code DAT_00960178;
extern code DAT_0096017c;
extern int *piGpffffb954;
extern u32 uGpffffb954;
extern u32 iGpffffb954;

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
void FUN_003b35e0(int param_1);
void FUN_003b3740(void);
void FUN_003b3770(void);
u64  FUN_003b38f0(float param_1,int param_2,int param_3,u64 param_4,short param_5,u32 param_6,  u32 param_7,u32 param_8);
long FUN_003b3d60(u64 param_1,u64 param_2,u64 param_3);
long FUN_003b3dd0(void);
u32 FUN_003b3e00(u32 param_1,short param_2);
u32 FUN_003b3e60(u32 param_1,long param_2,u64 param_3);
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


void FUN_003b35e0(int param_1)



{

  int iVar1;

  u64 uVar2;

  long lVar3;

  int iVar4;

  int iVar5;

  

  iVar5 = param_1 * 0x21c + 0x18;

  if (piGpffffb954 != (int *)0x0) {

    FUN_0019d3f0("frFontRaster.c",0x24);

  }

  uVar2 = (*DAT_00960178)(iVar5,0x40000);

  piGpffffb954 = (int *)uVar2;

  FUN_00521408(uVar2,0,iVar5);

  *piGpffffb954 = param_1;

  piGpffffb954[1] = (int)(piGpffffb954 + 6);

  iVar5 = piGpffffb954[1];

  *(int *)(iVar5 + 0xc) = iVar5 + 0x1c;

  piGpffffb954[4] = iVar5;

  for (iVar4 = 0; iVar4 < param_1 + -1; iVar4 = iVar4 + 1) {

    iVar1 = *(int *)(iVar5 + 0xc);

    *(int *)(iVar5 + 0x18) = iVar1 + 0x200;

    *(int *)(iVar1 + 0x20c) = iVar1 + 0x21c;

    iVar5 = iVar1 + 0x200;

  }

  piGpffffb954[5] = iVar5;

  iVar5 = piGpffffb954[4];

  while (iVar5 != 0) {

    lVar3 = FUN_004ce0f0(0x20,0x20,4,0x4504);

    *(int *)(iVar5 + 0x14) = (int)lVar3;

    if (lVar3 == 0) {

      FUN_005225a8(0x6a28b0);

    }

    else {

      iVar5 = *(int *)(iVar5 + 0x18);

    }

  }

  return;

}
#define FUN_003b35e0(...) ((void (*)(...))FUN_003b35e0)(__VA_ARGS__)
#undef FUN_003b3740
// FUN_003B3740


void FUN_003b3740(void)



{

  (*(void (**)(...))0x0096017c)(uGpffffb954);

  uGpffffb954 = 0;

  return;

}
#define FUN_003b3740(...) ((void (*)(...))FUN_003b3740)(__VA_ARGS__)
#undef FUN_003b3770
// FUN_003B3770 NONMATCHING


void FUN_003b3770(void)



{

  u32 *puVar1;

  u32 *puVar2;

  u32 *puVar3;

  

  puVar1 = *(u32 **)(iGpffffb954 + 8);

  puVar2 = (u32 *)0x0;

  while (puVar3 = puVar1, puVar3 != (u32 *)0x0) {

    if (((*puVar3 & 1) == 0) || (puVar3[4] == 0)) {

      *(short *)((int)puVar3 + 10) = *(short *)((int)puVar3 + 10) + -1;

    }

    if (*(short *)((int)puVar3 + 10) < 0) {

      if (puVar2 == (u32 *)0x0) {

        *(u32 *)(iGpffffb954 + 8) = puVar3[6];

        if (*(int *)(iGpffffb954 + 8) == 0) {

          *(u32 *)(iGpffffb954 + 0xc) = 0;

        }

        if (*(int *)(iGpffffb954 + 0x14) == 0) {

          *(u32 **)(iGpffffb954 + 0x14) = puVar3;

          *(u32 **)(iGpffffb954 + 0x10) = puVar3;

        }

        else {

          *(u32 **)(*(int *)(iGpffffb954 + 0x14) + 0x18) = puVar3;

          *(u32 **)(iGpffffb954 + 0x14) = puVar3;

        }

        puVar3[6] = 0;

        puVar1 = *(u32 **)(iGpffffb954 + 8);

        puVar2 = (u32 *)0x0;

      }

      else if (puVar3[6] == 0) {

        *(u32 **)(iGpffffb954 + 0xc) = puVar2;

        puVar2[6] = 0;

        if (*(int *)(iGpffffb954 + 0x14) == 0) {

          *(u32 **)(iGpffffb954 + 0x14) = puVar3;

          *(u32 **)(iGpffffb954 + 0x10) = puVar3;

        }

        else {

          *(u32 **)(*(int *)(iGpffffb954 + 0x14) + 0x18) = puVar3;

          *(u32 **)(iGpffffb954 + 0x14) = puVar3;

        }

        puVar3[6] = 0;

        puVar1 = (u32 *)0x0;

      }

      else {

        puVar2[6] = puVar3[6];

        if (*(int *)(iGpffffb954 + 0x14) == 0) {

          *(u32 **)(iGpffffb954 + 0x14) = puVar3;

          *(u32 **)(iGpffffb954 + 0x10) = puVar3;

        }

        else {

          *(u32 **)(*(int *)(iGpffffb954 + 0x14) + 0x18) = puVar3;

          *(u32 **)(iGpffffb954 + 0x14) = puVar3;

        }

        puVar3[6] = 0;

        puVar1 = (u32 *)puVar2[6];

      }

    }

    else {

      puVar1 = (u32 *)puVar3[6];

      puVar2 = puVar3;

    }

  }

  return;

}
#define FUN_003b3770(...) ((void (*)(...))FUN_003b3770)(__VA_ARGS__)
#undef FUN_003b38f0
// FUN_003B38F0 NONMATCHING
u64

FUN_003b38f0(float param_1,int param_2,int param_3,u64 param_4,short param_5,u32 param_6,

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

  pfVar6 = (float *)&DAT_006a28d0;

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

      DAT_0095ae10 = DAT_0095ae10 + -1;

    }

    *(int *)(iVar5 + 0x1c) = iVar7;

    puVar9 = *(u32 **)(iVar7 + 0xc);

  }

  *puVar9 = *puVar9 | 1;

  if ((param_8 & 0xff) != 0) {

    FUN_00521408(afStack_100,0,0x100);

    for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {

      afStack_100[iVar5 * 0x10 + 2] = DAT_00960088 - param_1;

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

    (*DAT_00960090)(1,puVar9[5]);

    (*DAT_009600a0)(4,afStack_100,4);

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
// FUN_003B3E60 NONMATCHING


u32 FUN_003b3e60(u32 param_1,long param_2,u64 param_3)



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

    if (*(int *)(iGpffffb954 + 0xc) == 0) {

      *(u32 **)(iGpffffb954 + 0xc) = puVar1;

      *(u32 **)(iGpffffb954 + 8) = puVar1;

    }

    else {

      *(u32 **)(*(int *)(iGpffffb954 + 0xc) + 0x18) = puVar1;

      *(u32 **)(iGpffffb954 + 0xc) = puVar1;

    }

    puVar1[4] = 0;

  }

  if (puVar1 == (u32 *)0x0) {

    puVar1 = (u32 *)0x0;

  }

  else {

    FUN_003b3f90(puVar1,param_2,param_3);

    puVar1[1] = param_1;

    *(u16 *)((int)puVar1 + 10) = 1;

    *puVar1 = *puVar1 | 1;

    FUN_00521250(puVar1[3],param_2,0x200);

    puVar1[4] = 0;

  }


  return (u32)puVar1;
}
#define FUN_003b3e60(...) ((u32 (*)(...))FUN_003b3e60)(__VA_ARGS__)
#undef FUN_003b3f90
// FUN_003B3F90 NONMATCHING


void FUN_003b3f90(int param_1,u8 *param_2,int param_3)



{

  u16 uVar1;

  u16 uVar2;

  long lVar3;

  int iVar4;

  u32 uVar5;

  u16 *puVar6;

  u32 uVar7;

  u16 *puVar8;

  u32 uVar9;

  u32 uVar10;

  u8 *pbVar11;

  u16 auStack_100 [128];

  

  if (param_2 == (u8 *)0x0) {

    FUN_005225a8(0x6a29f0);

    FUN_0019d3f0("frFontRaster.c",0x179);

  }

  else {

    puVar8 = DAT_006a28f0;

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

    iVar4 = FUN_004ce200(*(u32 *)(param_1 + 0x14),0,9);

    for (uVar5 = 0; (int)uVar5 < 0x20; uVar5 = uVar5 + 1) {

      for (uVar7 = 0; (int)uVar7 < 0x20; uVar7 = uVar7 + 1) {

        uVar9 = (u32)auStack_100

                      [((int)(uVar5 & 7) >> 2) * 0x40 + (uVar5 & 3) * 0x10 + (uVar7 & 0xf)] +

                (((int)(uVar7 & 0xffff) >> 4) * 0x20 + ((int)(uVar5 & 0xffff) >> 2) * 0x80 & 0xffffU

                );

        pbVar11 = (u8 *)(iVar4 + ((int)(uVar9 & 0xffff) >> 1));

        uVar10 = (int)(u32)*param_2 >> ((uVar7 & 1) << 2);

        if ((uVar9 & 1) == 0) {

          *pbVar11 = (u8)uVar10 & 0xf;

        }

        else {

          *pbVar11 = *pbVar11 | (u8)((uVar10 & 0xf) << 4);

        }

        if ((uVar7 & 1) != 0) {

          param_2 = param_2 + 1;

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

  }

  return;

}
#define FUN_003b3f90(...) ((void (*)(...))FUN_003b3f90)(__VA_ARGS__)
