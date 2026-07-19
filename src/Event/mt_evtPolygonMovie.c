#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern u32 DAT_006a0cd0;
extern u32 DAT_006a0cd4;
extern u32 DAT_006a0cdc;
extern u32 DAT_006a0ce0;
extern u32 DAT_006a0ce4;
extern u32 DAT_006a0ce8;
extern u32 DAT_006a0cec;
extern u32 DAT_006a0cf0;
extern u32 DAT_006a0d50;
extern u32 DAT_006a0d54;
extern u32 DAT_006a0d58;
extern u32 DAT_006a0d5c;
extern u32 DAT_006a0d60;
extern u32 DAT_006a0d64;
extern u32 DAT_006a0d68;
extern u32 DAT_006a0d6c;
extern u8 * PTR_DAT_006a0cd8;

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
void FUN_00393e30(u64 param_1,u64 param_2,u64 param_3,u64 param_4,  u32 param_5,u32 param_6);
void FUN_00393f30(u64 param_1,u32 param_2);
float FUN_00394040(float param_1,float param_2,float param_3,long param_4);
void FUN_00394070(float param_1,long param_2,u32 *param_3,long param_4,u32 *param_5);
long FUN_00394270(void);
u64  FUN_003942f0(u64 param_1,u64 param_2,long param_3,long param_4,long param_5);
void FUN_00394c30(long param_1,u64 param_2);
u64 FUN_00394ce0(u32 *param_1);
u64 FUN_00394d60(u32 *param_1);
u64 FUN_00394df0(u32 *param_1);
void FUN_00394e70(u64 param_1,u64 param_2,long param_3,long param_4,long param_5);
void FUN_00395000(u64 param_1,u64 param_2,long param_3,long param_4,long param_5,  long param_6);


/* Region call-cast macros */
#define FUN_00393e30(...) ((void (*)(...))FUN_00393e30)(__VA_ARGS__)
#define FUN_00393f30(...) ((void (*)(...))FUN_00393f30)(__VA_ARGS__)
#define FUN_00394040(...) ((float (*)(...))FUN_00394040)(__VA_ARGS__)
#define FUN_00394070(...) ((void (*)(...))FUN_00394070)(__VA_ARGS__)
#define FUN_00394270(...) ((long (*)(...))FUN_00394270)(__VA_ARGS__)
#define FUN_003942f0(...) ((u64 (*)(...))FUN_003942f0)(__VA_ARGS__)
#define FUN_00394c30(...) ((void (*)(...))FUN_00394c30)(__VA_ARGS__)
#define FUN_00394ce0(...) ((u64 (*)(...))FUN_00394ce0)(__VA_ARGS__)
#define FUN_00394d60(...) ((u64 (*)(...))FUN_00394d60)(__VA_ARGS__)
#define FUN_00394df0(...) ((u64 (*)(...))FUN_00394df0)(__VA_ARGS__)
#define FUN_00394e70(...) ((void (*)(...))FUN_00394e70)(__VA_ARGS__)
#define FUN_00395000(...) ((void (*)(...))FUN_00395000)(__VA_ARGS__)

#undef FUN_00393e30
// FUN_00393E30 NONMATCHING


void FUN_00393e30(u64 param_1,u64 param_2,u64 param_3,u64 param_4,

                 u32 param_5,u32 param_6)



{

  int iVar1;

  

  iVar1 = (int)param_1;

  *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 0x80;

  FUN_00521408(iVar1 + 0x960,0,0x1c);

  if ((*(u32 *)(iVar1 + 4) & 8) == 0) {

    *(u32 *)(iVar1 + 0x960) = 0;

    if (*(int *)(iVar1 + 0x934) != 0) {

      FUN_00195020();

      *(u32 *)(iVar1 + 0x934) = 0;

    }

  }

  else {

    *(u32 *)(iVar1 + 0x960) = 1;

  }

  *(u32 *)(iVar1 + 0x964) = param_5;

  FUN_00386e20(param_1,param_2);

  FUN_00386e40(param_1,param_3);

  FUN_00397510(param_1,param_4);

  *(u32 *)(iVar1 + 0x978) = param_6;

  return;

}
#define FUN_00393e30(...) ((void (*)(...))FUN_00393e30)(__VA_ARGS__)
#undef FUN_00393f30
// FUN_00393F30 NONMATCHING


void FUN_00393f30(u64 param_1,u32 param_2)



{

  long lVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  u32 uStack_10;

  u8 auStack_c [4];

  u8 auStack_8 [8];

  

  iVar4 = (int)param_1;

  *(u32 *)(iVar4 + 0x18) = *(u32 *)(iVar4 + 0x10);

  *(u32 *)(iVar4 + 0x1c) = 0xffffffff;

  *(u32 *)(iVar4 + 0x8e0) = 0;

  *(u32 *)(iVar4 + 0x918) = 0;

  *(u32 *)(iVar4 + 0x8e4) = 0;

  for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {

    *(u32 *)(auStack_c + iVar3 * 4 + -4) = 0;

  }

  lVar1 = FUN_003977c0(param_1,&uStack_10,auStack_c,auStack_8);

  if (lVar1 == 1) {

    *(u32 *)(iVar4 + 0x8e4) = 3;

    for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {

      iVar2 = iVar4 + 0x8e0 + iVar3 * 0xc;

      *(u32 *)(iVar2 + 8) = 5;

      *(u32 *)(iVar2 + 0xc) = *(u32 *)(auStack_c + iVar3 * 4 + -4);

    }

  }

  *(u32 *)(iVar4 + 4) = *(u32 *)(iVar4 + 4) | 0x10000;

  *(u32 *)(iVar4 + 0x920) = param_2;

  return;

}
#define FUN_00393f30(...) ((void (*)(...))FUN_00393f30)(__VA_ARGS__)
#undef FUN_00394040
// FUN_00394040 NONMATCHING


float FUN_00394040(float param_1,float param_2,float param_3,long param_4)



{

  if (param_4 != 0) {

    param_2 = param_2 * (1.0 - param_1) + param_3 * param_1;

  }

  return param_2;

}
#define FUN_00394040(...) ((float (*)(...))FUN_00394040)(__VA_ARGS__)
#undef FUN_00394070
// FUN_00394070 NONMATCHING


void FUN_00394070(float param_1,long param_2,u32 *param_3,long param_4,u32 *param_5)



{

  u32 uVar1;

  u32 uVar2;

  int iVar3;

  int iVar4;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  u32 uStack_20;

  u32 uStack_1c;

  u32 uStack_18;

  u32 uStack_10;

  u32 uStack_c;

  u32 uStack_8;

  

  if (param_5 == (u32 *)0x0) {

    FUN_0019d3f0("mt_evtPolygonMovie.c",0xb5);

  }

  if (param_2 == 0) {

    param_1 = 0.0;

  }

  if (param_3 != (u32 *)0x0) {

    if (param_4 == 0) {

      iVar3 = 6;

      do {

        uVar1 = *param_3;

        uVar2 = param_3[1];

        param_3 = param_3 + 2;

        iVar3 = iVar3 + -1;

        *param_5 = uVar1;

        param_5[1] = uVar2;

        param_5 = param_5 + 2;

      } while (0 < iVar3);

    }

    else {

      for (iVar3 = 0; iVar4 = (int)param_4, iVar3 < 4; iVar3 = iVar3 + 1) {

        param_5[iVar3 + 8] =

             param_1 * (*(float *)(iVar4 + iVar3 * 4 + 0x20) - (float)param_3[iVar3 + 8]) +

             (float)param_3[iVar3 + 8] + 0.0;

      }

      for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

        param_5[iVar3] =

             param_1 * (*(float *)(iVar4 + iVar3 * 4) - (float)param_3[iVar3]) +

             (float)param_3[iVar3] + 0.0;

      }

      uStack_10 = param_3[4];

      uStack_c = param_3[5];

      uStack_8 = param_3[6];

      uStack_20 = *(u32 *)(iVar4 + 0x10);

      uStack_1c = *(u32 *)(iVar4 + 0x14);

      uStack_18 = *(u32 *)(iVar4 + 0x18);

      FUN_003bbaa0(&uStack_10,&uStack_20,&fStack_30);

      fStack_40 = fStack_30 * param_1 + (float)param_3[4] + 0.0;

      fStack_3c = fStack_2c * param_1 + (float)param_3[5] + 0.0;

      fStack_38 = fStack_28 * param_1 + (float)param_3[6] + 0.0;

      FUN_003bb9b0(&fStack_40);

      param_5[4] = fStack_40;

      param_5[5] = fStack_3c;

      param_5[6] = fStack_38;

    }

  }

  return;

}
#define FUN_00394070(...) ((void (*)(...))FUN_00394070)(__VA_ARGS__)
#undef FUN_00394270
// FUN_00394270 NONMATCHING


long FUN_00394270(void)



{

  long lVar1;

  

  lVar1 = FUN_00386ae0(0x130,1);

  if (lVar1 == 0) {

    FUN_0019d3f0("mt_evtPolygonMovie.c",0x421);

    lVar1 = 0;

  }

  else {

    FUN_00521408(lVar1,0,0x130);

  }

  return lVar1;

}
#define FUN_00394270(...) ((long (*)(...))FUN_00394270)(__VA_ARGS__)
#undef FUN_003942f0
// FUN_003942F0 NONMATCHING


u64

FUN_003942f0(u64 param_1,u64 param_2,long param_3,long param_4,long param_5)



{

  long lVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  

  if (param_3 == 0) {

    FUN_0019d3f0("mt_evtPolygonMovie.c",0x449);

    param_2 = 0;

  }

  else {

    iVar6 = (int)param_2;

    *(u32 *)(iVar6 + 0x128) = 0;

    lVar1 = FUN_00386ae0(0x1fc,1);

    *(int *)(iVar6 + 300) = (int)lVar1;

    if (lVar1 == 0) {

      FUN_0019d3f0("mt_evtPolygonMovie.c",0x45c);

    }

    for (iVar7 = 0; iVar7 < 0x7f; iVar7 = iVar7 + 1) {

      *(u32 *)(*(int *)(iVar6 + 300) + iVar7 * 4) = 0;

    }

    iVar5 = (int)param_3;

    *(int *)(iVar6 + 0x10) = iVar5;

    *(int *)(iVar6 + 0x14) = iVar5 + 0x20;

    *(u32 *)(iVar6 + 0x18) = 0;

    *(u32 *)(iVar6 + 0x1c) = 0;

    *(u32 *)(iVar6 + 0x20) = 0;

    *(u32 *)(iVar6 + 0x24) = 0;

    *(u32 *)(iVar6 + 0x28) = 0;

    *(u32 *)(iVar6 + 0x2c) = 0;

    *(u32 *)(iVar6 + 0x30) = 0;

    *(u32 *)(iVar6 + 0x34) = 0;

    *(u32 *)(iVar6 + 0x38) = 0;

    *(u32 *)(iVar6 + 0x3c) = 0;

    *(u32 *)(iVar6 + 0x40) = 0;

    *(u32 *)(iVar6 + 0x44) = 0;

    *(u32 *)(iVar6 + 0x48) = 0;

    *(u32 *)(iVar6 + 0x50) = 0;

    *(u32 *)(iVar6 + 0x4c) = 0;

    *(u32 *)(iVar6 + 0x54) = 0;

    *(u32 *)(iVar6 + 0x58) = 0;

    *(u32 *)(iVar6 + 0x5c) = 0;

    *(u32 *)(iVar6 + 0x60) = 0;

    for (iVar7 = 0; iVar7 < *(int *)(*(int *)(iVar6 + 0x10) + 0x10); iVar7 = iVar7 + 1) {

      iVar3 = iVar7 * 0x10;

      piVar4 = (int *)(*(int *)(iVar6 + 0x14) + iVar3);

      iVar2 = *piVar4;

      if (iVar2 == 0x1b) {

        if (piVar4[2] != 0) {

          iVar2 = iVar5 + piVar4[3];

          *(int *)(iVar6 + 0x60) = iVar2;

          *(int *)(iVar2 + 4) = iVar2 + 0x10;

          FUN_005225a8(0x6a0c60,**(u32 **)(iVar6 + 0x60));

        }

      }

      else if (iVar2 == 0x17) {

        *(int *)(iVar6 + 0x5c) = iVar5 + piVar4[3];

      }

      else if (iVar2 == 0x16) {

        *(int *)(iVar6 + 0x54) = iVar5 + piVar4[3];

        *(u32 *)(iVar6 + 0x58) = *(u32 *)(*(int *)(iVar6 + 0x14) + iVar3 + 8);

      }

      else if (iVar2 == 8) {

        *(int *)(iVar6 + 0x48) = iVar5 + piVar4[3];

      }

      else if (iVar2 == 7) {

        *(int *)(iVar6 + 0x40) = iVar5 + piVar4[3];

        *(u32 *)(iVar6 + 0x44) = *(u32 *)(*(int *)(iVar6 + 0x14) + iVar3 + 8);

      }

      else if (iVar2 == 6) {

        *(int *)(iVar6 + 0x4c) = iVar5 + piVar4[3];

        *(u32 *)(iVar6 + 0x50) = *(u32 *)(*(int *)(iVar6 + 0x14) + iVar3 + 8);

      }

      else if (iVar2 == 1) {

        *(int *)(iVar6 + 0x18) = iVar5 + piVar4[3];

        *(u32 *)(iVar6 + 0x1c) = *(u32 *)(*(int *)(iVar6 + 0x14) + iVar3 + 8);

      }

      else if (iVar2 == 9) {

        *(int *)(iVar6 + 0x3c) = iVar5 + piVar4[3];

      }

      else if (iVar2 == 3) {

        *(int *)(iVar6 + 0x34) = iVar5 + piVar4[3];

        *(u32 *)(iVar6 + 0x38) = *(u32 *)(*(int *)(iVar6 + 0x14) + iVar3 + 8);

      }

      else if (iVar2 == 0xc) {

        *(int *)(iVar6 + 0x30) = iVar5 + piVar4[3];

      }

      else if (iVar2 == 0xb) {

        *(int *)(iVar6 + 0x2c) = iVar5 + piVar4[3];

      }

      else if (iVar2 == 10) {

        *(int *)(iVar6 + 0x28) = iVar5 + piVar4[3];

      }

      else if (iVar2 == 2) {

        *(int *)(iVar6 + 0x20) = iVar5 + piVar4[3];

        *(u32 *)(iVar6 + 0x24) = *(u32 *)(*(int *)(iVar6 + 0x14) + iVar3 + 8);

      }

      else {

        FUN_0019d3f0("mt_evtPolygonMovie.c",0x4c5);

      }

    }

    iVar7 = (int)param_4;

    *(int *)(iVar6 + 0x84) = iVar7;

    if (param_4 == 0) {

      *(u32 *)(iVar6 + 0x88) = 0;

    }

    else {

      *(int *)(iVar6 + 0x88) = iVar7 + 0x20;

    }

    *(u32 *)(iVar6 + 0x8c) = 0;

    *(u32 *)(iVar6 + 0x90) = 0;

    *(u32 *)(iVar6 + 0x94) = 0;

    *(u32 *)(iVar6 + 0x98) = 0;

    *(u32 *)(iVar6 + 0xb0) = 0;

    *(u32 *)(iVar6 + 0xb4) = 0;

    *(u32 *)(iVar6 + 0xb8) = 0;

    *(u32 *)(iVar6 + 0xbc) = 0;

    *(u32 *)(iVar6 + 0xc0) = 0;

    *(u32 *)(iVar6 + 0xc4) = 0;

    *(u32 *)(iVar6 + 200) = 0;

    *(u32 *)(iVar6 + 0xcc) = 0;

    *(u32 *)(iVar6 + 0xd0) = 0;

    *(u32 *)(iVar6 + 0xd4) = 0;

    *(u32 *)(iVar6 + 0xd8) = 0;

    *(u32 *)(iVar6 + 0xdc) = 0;

    *(u32 *)(iVar6 + 0xe0) = 0;

    *(u32 *)(iVar6 + 0xe4) = 0;

    *(u32 *)(iVar6 + 0xe8) = 0;

    *(u32 *)(iVar6 + 0xec) = 0;

    *(u32 *)(iVar6 + 0xf0) = 0;

    *(u32 *)(iVar6 + 0xf4) = 0;

    *(u32 *)(iVar6 + 0xf8) = 0;

    *(u32 *)(iVar6 + 0x104) = 0;

    *(u32 *)(iVar6 + 0x108) = 0;

    *(u32 *)(iVar6 + 0xfc) = 0;

    *(u32 *)(iVar6 + 0x100) = 0;

    *(u32 *)(iVar6 + 0x10c) = 0;

    *(u32 *)(iVar6 + 0x110) = 0;

    *(u32 *)(iVar6 + 100) = 0;

    *(u32 *)(iVar6 + 0x68) = 0;

    if (param_4 != 0) {

      FUN_005225a8(0x6a0c90,*(u32 *)(*(int *)(iVar6 + 0x84) + 0x10));

      for (iVar5 = 0; iVar5 < *(int *)(*(int *)(iVar6 + 0x84) + 0x10); iVar5 = iVar5 + 1) {

        iVar3 = iVar5 * 0x10;

        piVar4 = (int *)(*(int *)(iVar6 + 0x88) + iVar3);

        iVar2 = *piVar4;

        if (iVar2 == 0x1a) {

          *(int *)(iVar6 + 100) = iVar7 + piVar4[3];

          *(u32 *)(iVar6 + 0x68) = *(u32 *)(*(int *)(iVar6 + 0x88) + iVar3 + 8);

        }

        else if (iVar2 == 0x19) {

          *(int *)(iVar6 + 0x10c) = iVar7 + piVar4[3];

          *(u32 *)(iVar6 + 0x110) = *(u32 *)(*(int *)(iVar6 + 0x88) + iVar3 + 8);

        }

        else if (iVar2 == 0x15) {

          *(int *)(iVar6 + 0x104) = iVar7 + piVar4[3];

          *(u32 *)(iVar6 + 0x108) = *(u32 *)(*(int *)(iVar6 + 0x88) + iVar3 + 8);

          FUN_005225a8(0x6a0cb0);

        }

        else if (iVar2 == 0x18) {

          *(int *)(iVar6 + 0xfc) = iVar7 + piVar4[3];

          *(u32 *)(iVar6 + 0x100) = *(u32 *)(*(int *)(iVar6 + 0x88) + iVar3 + 8);

        }

        else if (iVar2 == 0x14) {

          *(int *)(iVar6 + 0xf4) = iVar7 + piVar4[3];

          *(u32 *)(iVar6 + 0xf8) = *(u32 *)(*(int *)(iVar6 + 0x88) + iVar3 + 8);

        }

        else if (iVar2 == 0x13) {

          *(int *)(iVar6 + 0xec) = iVar7 + piVar4[3];

          *(u32 *)(iVar6 + 0xf0) = *(u32 *)(*(int *)(iVar6 + 0x88) + iVar3 + 8);

        }

        else if (iVar2 == 0x12) {

          *(int *)(iVar6 + 0xe4) = iVar7 + piVar4[3];

          *(u32 *)(iVar6 + 0xe8) = *(u32 *)(*(int *)(iVar6 + 0x88) + iVar3 + 8);

        }

        else if (iVar2 == 0x11) {

          *(int *)(iVar6 + 0xdc) = iVar7 + piVar4[3];

          *(u32 *)(iVar6 + 0xe0) = *(u32 *)(*(int *)(iVar6 + 0x88) + iVar3 + 8);

        }

        else if (iVar2 == 0x10) {

          *(int *)(iVar6 + 0xd4) = iVar7 + piVar4[3];

          *(u32 *)(iVar6 + 0xd8) = *(u32 *)(*(int *)(iVar6 + 0x88) + iVar3 + 8);

        }

        else if (iVar2 == 0xf) {

          *(int *)(iVar6 + 0xcc) = iVar7 + piVar4[3];

          *(u32 *)(iVar6 + 0xd0) = *(u32 *)(*(int *)(iVar6 + 0x88) + iVar3 + 8);

        }

        else if (iVar2 == 0xe) {

          *(int *)(iVar6 + 0xc4) = iVar7 + piVar4[3];

          *(u32 *)(iVar6 + 200) = *(u32 *)(*(int *)(iVar6 + 0x88) + iVar3 + 8);

        }

        else if (iVar2 == 0xd) {

          *(int *)(iVar6 + 0xbc) = iVar7 + piVar4[3];

          *(u32 *)(iVar6 + 0xc0) = *(u32 *)(*(int *)(iVar6 + 0x88) + iVar3 + 8);

        }

        else if (iVar2 == 5) {

          *(int *)(iVar6 + 0xb4) = iVar7 + piVar4[3];

          *(u32 *)(iVar6 + 0xb8) = *(u32 *)(*(int *)(iVar6 + 0x88) + iVar3 + 8);

        }

        else if (iVar2 == 1) {

          *(int *)(iVar6 + 0x8c) = iVar7 + piVar4[3];

          *(u32 *)(iVar6 + 0x90) = *(u32 *)(*(int *)(iVar6 + 0x88) + iVar3 + 8);

        }

        else if (iVar2 == 4) {

          if (*(int *)(*(int *)(iVar6 + 0x84) + 0x14) == 4) {

            *(int *)(iVar6 + 0x98) = iVar7 + piVar4[3];

            *(u32 *)(iVar6 + 0x9c) = 0;

          }

          else {

            *(int *)(iVar6 + 0x9c) = iVar7 + piVar4[3];

            *(u32 *)(iVar6 + 0x98) = 0;

          }

          *(u32 *)(iVar6 + 0xb0) = *(u32 *)(*(int *)(iVar6 + 0x88) + iVar3 + 8);

        }

        else if (iVar2 == 0) {

          *(int *)(iVar6 + 0x94) = iVar7 + piVar4[3];

        }

        else {

          FUN_0019d3f0("mt_evtPolygonMovie.c",0x54f);

        }

      }

      *(u8 *)(*(int *)(iVar6 + 0x94) + 0x20) = *(u8 *)(*(int *)(iVar6 + 0x94) + 0x20) | 8;

      if (((*(int *)(iVar6 + 0x94) != 0) && (*(int *)(iVar6 + 0x4c) != 0)) &&

         (0 < *(int *)(iVar6 + 0x50))) {

        if ((*(u8 *)(*(int *)(iVar6 + 0x94) + 0x20) & 2) == 0) {

          FUN_0039ec70(param_1);

          if ((*(u8 *)(*(int *)(iVar6 + 0x94) + 0x20) & 8) != 0) {

            FUN_003c94e0(*(u32 *)(iVar6 + 0x4c));

          }

        }

        else {

          FUN_0039edd0(param_1);

          if ((*(u8 *)(*(int *)(iVar6 + 0x94) + 0x20) & 8) != 0) {

            FUN_003c94e0(*(u32 *)(iVar6 + 0x4c));

          }

        }

      }

      iVar7 = (int)param_5;

      *(int *)(iVar6 + 0xa0) = iVar7;

      if (param_5 == 0) {

        *(u32 *)(iVar6 + 0xa4) = 0;

      }

      else {

        *(int *)(iVar6 + 0xa4) = iVar7 + 0x20;

      }

      *(u32 *)(iVar6 + 0xa8) = 0;

      *(u32 *)(iVar6 + 0xac) = 0;

      if (param_5 != 0) {

        for (iVar5 = 0; iVar5 < *(int *)(*(int *)(iVar6 + 0xa0) + 0x10); iVar5 = iVar5 + 1) {

          piVar4 = (int *)(*(int *)(iVar6 + 0xa4) + iVar5 * 0x10);

          if (*piVar4 == 4) {

            *(int *)(iVar6 + 0xa8) = iVar7 + piVar4[3];

            *(u32 *)(iVar6 + 0xac) =

                 *(u32 *)(*(int *)(iVar6 + 0xa4) + iVar5 * 0x10 + 8);

          }

        }

      }

    }

  }

  return param_2;

}
#define FUN_003942f0(...) ((u64 (*)(...))FUN_003942f0)(__VA_ARGS__)
#undef FUN_00394c30
// FUN_00394C30 NONMATCHING


void FUN_00394c30(long param_1,u64 param_2)



{

  int iVar1;

  long lVar2;

  

  if (param_1 != 0) {

    iVar1 = *(int *)((int)param_1 + 300);

    if (iVar1 != 0) {

      FUN_00386b70(iVar1,1,0x1fc);

    }

    lVar2 = FUN_0039eee0(param_2);

    if ((lVar2 == 1) &&

       (FUN_0039ee80(param_2), (*(u8 *)(*(int *)((int)param_1 + 0x94) + 0x20) & 8) != 0)) {

      FUN_003c77a0();

    }

    FUN_00386b70(param_1,1,0x130);

  }

  return;

}
#define FUN_00394c30(...) ((void (*)(...))FUN_00394c30)(__VA_ARGS__)
#undef FUN_00394ce0
// FUN_00394CE0 NONMATCHING


u64 FUN_00394ce0(u32 *param_1)



{

  u64 uVar1;

  u32 uStack_20;

  u32 uStack_1c;

  u8 *puStack_18;

  u32 uStack_14;

  u32 uStack_10;

  u32 uStack_c;

  u32 uStack_8;

  u32 uStack_4;

  

  uStack_20 = DAT_006a0cd0;

  uStack_1c = DAT_006a0cd4;

  puStack_18 = PTR_DAT_006a0cd8;

  uStack_14 = DAT_006a0cdc;

  uStack_10 = DAT_006a0ce0;

  uStack_c = DAT_006a0ce4;

  uStack_8 = DAT_006a0ce8;

  uStack_4 = DAT_006a0cec;

  uVar1 = FUN_00386ae0(0x20,4);

  FUN_00521250(uVar1,&uStack_20,0x20);

  *param_1 = (int)uVar1;

  return uVar1;

}
#define FUN_00394ce0(...) ((u64 (*)(...))FUN_00394ce0)(__VA_ARGS__)
#undef FUN_00394d60
// FUN_00394D60 NONMATCHING


u64 FUN_00394d60(u32 *param_1)



{

  u64 uVar1;

  u32 uVar2;

  u32 uVar3;

  int iVar4;

  u32 *puVar5;

  u64 *puVar6;

  u32 auStack_60 [24];

  

  puVar6 = (u64 *)&DAT_006a0cf0;

  puVar5 = auStack_60;

  iVar4 = 5;

  do {

    uVar1 = *puVar6;

    uVar2 = *(u32 *)(puVar6 + 1);

    uVar3 = *(u32 *)((int)puVar6 + 0xc);

    puVar6 = puVar6 + 2;

    iVar4 = iVar4 + -1;

    *puVar5 = (int)uVar1;

    puVar5[1] = (int)((u32)uVar1 >> 0x20);

    puVar5[2] = uVar2;

    puVar5[3] = uVar3;

    puVar5 = puVar5 + 4;

  } while (0 < iVar4);

  *puVar5 = *(u32 *)puVar6;

  uVar1 = FUN_00386ae0(0x54,5);

  FUN_00521250(uVar1,auStack_60,0x54);

  *param_1 = (int)uVar1;

  return uVar1;

}
#define FUN_00394d60(...) ((u64 (*)(...))FUN_00394d60)(__VA_ARGS__)
#undef FUN_00394df0
// FUN_00394DF0 NONMATCHING


u64 FUN_00394df0(u32 *param_1)



{

  u64 uVar1;

  u32 uStack_20;

  u32 uStack_1c;

  u32 uStack_18;

  u32 uStack_14;

  u32 uStack_10;

  u32 uStack_c;

  u32 uStack_8;

  u32 uStack_4;

  

  uStack_20 = DAT_006a0d50;

  uStack_1c = DAT_006a0d54;

  uStack_18 = DAT_006a0d58;

  uStack_14 = DAT_006a0d5c;

  uStack_10 = DAT_006a0d60;

  uStack_c = DAT_006a0d64;

  uStack_8 = DAT_006a0d68;

  uStack_4 = DAT_006a0d6c;

  uVar1 = FUN_00386ae0(0x20,6);

  FUN_00521250(uVar1,&uStack_20,0x20);

  *param_1 = (int)uVar1;

  return uVar1;

}
#define FUN_00394df0(...) ((u64 (*)(...))FUN_00394df0)(__VA_ARGS__)
#undef FUN_00394e70
// FUN_00394E70 NONMATCHING


void FUN_00394e70(u64 param_1,u64 param_2,long param_3,long param_4,long param_5)



{

  int iVar1;

  u8 auStack_100 [256];

  

  if (param_3 == 0) {

    FUN_0019d3f0("mt_evtPolygonMovie.c",0x665);

  }

  if (param_4 == 0) {

    FUN_0019d3f0("mt_evtPolygonMovie.c",0x666);

  }

  if (param_5 == 0) {

    FUN_0019d3f0("mt_evtPolygonMovie.c",0x667);

  }

  iVar1 = ((int)param_1 / 10) * 10;

  FUN_00523ac8(auStack_100,0x6a0d70,iVar1,param_1,param_2);

  FUN_00523ac8(param_3,0x7cd458);

  FUN_00523e68(param_3,auStack_100);

  FUN_00523ac8(auStack_100,0x6a0da0,iVar1,param_1,param_2);

  FUN_00523ac8(param_4,0x7cd458);

  FUN_00523e68(param_4,auStack_100);

  FUN_00523ac8(auStack_100,0x6a0dd0,iVar1,param_1,param_2);

  FUN_00523ac8(param_5,0x7cd458);

  FUN_00523e68(param_5,auStack_100);

  return;

}
#define FUN_00394e70(...) ((void (*)(...))FUN_00394e70)(__VA_ARGS__)
#undef FUN_00395000
// FUN_00395000 NONMATCHING


void FUN_00395000(u64 param_1,u64 param_2,long param_3,long param_4,long param_5,

                 long param_6)



{

  int iVar1;

  

  if (param_3 == 0) {

    FUN_0019d3f0("mt_evtPolygonMovie.c",0x6ae);

  }

  if (param_4 == 0) {

    FUN_0019d3f0("mt_evtPolygonMovie.c",0x6af);

  }

  if (param_5 == 0) {

    FUN_0019d3f0("mt_evtPolygonMovie.c",0x6b0);

  }

  if (param_6 == 0) {

    FUN_0019d3f0("mt_evtPolygonMovie.c",0x6b1);

  }

  iVar1 = ((int)param_1 / 10) * 10;

  FUN_00523ac8(param_3,0x6a0e00,iVar1,param_1,param_2);

  FUN_00523ac8(param_4,0x6a0e20,iVar1,param_1,param_2);

  FUN_00523ac8(param_5,0x6a0e40,iVar1,param_1,param_2);

  FUN_00523ac8(param_6,0x6a0e60,iVar1,param_1,param_2);

  return;

}
#define FUN_00395000(...) ((void (*)(...))FUN_00395000)(__VA_ARGS__)
