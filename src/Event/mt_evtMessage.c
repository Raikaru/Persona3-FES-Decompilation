#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern u32 DAT_006a1850;
extern u8 DAT_006a0000[];
extern u32 DAT_006a1870;
extern u32 DAT_007cae58;
extern u32 DAT_007caf30;
extern u32 DAT_007cd490;
extern u32 DAT_007cd494;
extern u32 DAT_007cd498;
extern u32 DAT_007cd4a0;
extern u32 DAT_007ce61c;
extern code DAT_00960178;
extern code DAT_0096017c;
extern u32 gp0xffffa7b8;
extern u8 *FUN_003c3f40(u32 param_1);
extern u8 *FUN_003c3f80(int param_1);
extern u8 *FUN_0013bcb0(u64 param_1, u64 param_2);
extern void FUN_003189f0(u32 param_1, int param_2, float param_3);
#pragma alias FUN_0019d3f0_ptr FUN_0019d3f0
extern void FUN_0019d3f0_ptr(void *param_1, int param_2);
extern s8 FUN_0016dba0(s16 param_1);
extern u32 FUN_003a51a0(int param_1);
#pragma alias FUN_003a4010_evt FUN_003a4010
extern void FUN_003a4010_evt(int param_1, int param_2, s8 param_3, int param_4);
extern u32 FUN_003a5120(int param_1, int param_2);

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
long FUN_0039ec70(int *param_1,u64 param_2);
long FUN_0039ed20(int *param_1,u64 param_2);
long FUN_0039edd0(int *param_1,u64 param_2);
void FUN_0039ee80(u64 param_1);
u8 FUN_0039eee0(int *param_1);
void FUN_0039eef0(int *param_1,u64 param_2,u64 param_3);
void FUN_0039ef30(int *param_1);
void FUN_0039ef70(int *param_1,u64 param_2,int param_3);
void FUN_0039efd0(int *param_1,u64 param_2,u16 param_3);
void FUN_0039f050(int *param_1,int param_2,u16 param_3);
void FUN_0039f0c0(int *param_1,u64 param_2,u8 param_3);
void FUN_0039f120(int *param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_0039f190(int *param_1,u64 param_2,u16 param_3);
void FUN_0039f210(int *param_1,int param_2,int param_3,int param_4);
void FUN_0039f2a0(int *param_1);
void FUN_0039f350(int *param_1);
void FUN_0039f410(int *param_1);
u8 FUN_0039f6e0(int *param_1);
u32 FUN_0039f710(int *param_1);
void FUN_0039f750(int *param_1,int param_2);
void FUN_0039f7c0(int *param_1);
int FUN_0039f800(int *param_1);
u8 FUN_0039f850(int param_1);
void FUN_0039f950(int param_1);
void FUN_0039fb10(void);
void FUN_0039fbd0(int param_1);
void FUN_0039ffc0(int param_1,float *param_2,int param_3,u64 param_4);
u64 FUN_003a0220(int param_1);
void FUN_003a05b0(int param_1,int param_2);
void FUN_003a0960(int param_1,int param_2,u64 param_3);
u32 FUN_003a0b50(int param_1);
u32 FUN_003a0e90(u64 param_1);
u32 FUN_003a1c00(u64 param_1);
void FUN_003a1f30(int param_1);
void FUN_003a2090(u64 param_1,u16 param_2,u32 param_3,u16 param_4);

/* Region call-cast macros */
#define FUN_0039ec70(...) ((long (*)(...))FUN_0039ec70)(__VA_ARGS__)
#define FUN_0039ed20(...) ((long (*)(...))FUN_0039ed20)(__VA_ARGS__)
#define FUN_0039edd0(...) ((long (*)(...))FUN_0039edd0)(__VA_ARGS__)
#define FUN_0039ee80(...) ((void (*)(...))FUN_0039ee80)(__VA_ARGS__)
#define FUN_0039eee0(...) ((u8 (*)(...))FUN_0039eee0)(__VA_ARGS__)
#define FUN_0039eef0(...) ((void (*)(...))FUN_0039eef0)(__VA_ARGS__)
#define FUN_0039ef30(...) ((void (*)(...))FUN_0039ef30)(__VA_ARGS__)
#define FUN_0039ef70(...) ((void (*)(...))FUN_0039ef70)(__VA_ARGS__)
#define FUN_0039efd0(...) ((void (*)(...))FUN_0039efd0)(__VA_ARGS__)
#define FUN_0039f050(...) ((void (*)(...))FUN_0039f050)(__VA_ARGS__)
#define FUN_0039f0c0(...) ((void (*)(...))FUN_0039f0c0)(__VA_ARGS__)
#define FUN_0039f120(...) ((void (*)(...))FUN_0039f120)(__VA_ARGS__)
#define FUN_0039f190(...) ((void (*)(...))FUN_0039f190)(__VA_ARGS__)
#define FUN_0039f210(...) ((void (*)(...))FUN_0039f210)(__VA_ARGS__)
#define FUN_0039f2a0(...) ((void (*)(...))FUN_0039f2a0)(__VA_ARGS__)
#define FUN_0039f350(...) ((void (*)(...))FUN_0039f350)(__VA_ARGS__)
#define FUN_0039f410(...) ((void (*)(...))FUN_0039f410)(__VA_ARGS__)
#define FUN_0039f6e0(...) ((u8 (*)(...))FUN_0039f6e0)(__VA_ARGS__)
#define FUN_0039f710(...) ((u64 (*)(...))FUN_0039f710)(__VA_ARGS__)
#define FUN_0039f750(...) ((void (*)(...))FUN_0039f750)(__VA_ARGS__)
#define FUN_0039f7c0(...) ((void (*)(...))FUN_0039f7c0)(__VA_ARGS__)
#define FUN_0039f800(...) ((int (*)(...))FUN_0039f800)(__VA_ARGS__)
#define FUN_0039f850(...) ((u8 (*)(...))FUN_0039f850)(__VA_ARGS__)
#define FUN_0039f950(...) ((void (*)(...))FUN_0039f950)(__VA_ARGS__)
#define FUN_0039fb10(...) ((void (*)(...))FUN_0039fb10)(__VA_ARGS__)
#define FUN_0039fbd0(...) ((void (*)(...))FUN_0039fbd0)(__VA_ARGS__)
#define FUN_0039ffc0(...) ((void (*)(...))FUN_0039ffc0)(__VA_ARGS__)
#define FUN_003a0220(...) ((u64 (*)(...))FUN_003a0220)(__VA_ARGS__)
#define FUN_003a05b0(...) ((void (*)(...))FUN_003a05b0)(__VA_ARGS__)
#define FUN_003a0960(...) ((void (*)(...))FUN_003a0960)(__VA_ARGS__)
#define FUN_003a0b50(...) ((u32 (*)(...))FUN_003a0b50)(__VA_ARGS__)
#define FUN_003a0e90(...) ((u32 (*)(...))FUN_003a0e90)(__VA_ARGS__)
#define FUN_003a1c00(...) ((u32 (*)(...))FUN_003a1c00)(__VA_ARGS__)
#define FUN_003a1f30(...) ((void (*)(...))FUN_003a1f30)(__VA_ARGS__)
#define FUN_003a2090(...) ((void (*)(...))FUN_003a2090)(__VA_ARGS__)

#undef FUN_0039ec70
// FUN_0039EC70 NONMATCHING


long FUN_0039ec70(int *param_1,u64 param_2)



{

  long lVar1;

  

  if (*param_1 != 0) {

    FUN_0019d3f0("mt_evtMessage.c",0x1f);

  }

  param_1[1] = 0;

  lVar1 = FUN_003a2d80(param_2);

  FUN_003a4990(lVar1,4,0);

  param_1[2] = (int)lVar1;

  if (lVar1 < 0) {

    FUN_0019d3f0("mt_evtMessage.c",0x27);

  }

  *param_1 = 1;

  return lVar1;

}
#define FUN_0039ec70(...) ((long (*)(...))FUN_0039ec70)(__VA_ARGS__)
#undef FUN_0039ed20
// FUN_0039ED20 NONMATCHING


long FUN_0039ed20(int *param_1,u64 param_2)



{

  long lVar1;

  

  if (*param_1 != 0) {

    FUN_0019d3f0("mt_evtMessage.c",0x1f);

  }

  param_1[1] = 1;

  lVar1 = FUN_003a2d80(param_2);

  FUN_003a4990(lVar1,4,0);

  param_1[2] = (int)lVar1;

  if (lVar1 < 0) {

    FUN_0019d3f0("mt_evtMessage.c",0x27);

  }

  *param_1 = 1;

  return lVar1;

}
#define FUN_0039ed20(...) ((long (*)(...))FUN_0039ed20)(__VA_ARGS__)
#undef FUN_0039edd0
// FUN_0039EDD0 NONMATCHING


long FUN_0039edd0(int *param_1,u64 param_2)



{

  long lVar1;

  

  if (*param_1 != 0) {

    FUN_0019d3f0("mt_evtMessage.c",0x1f);

  }

  param_1[1] = 2;

  lVar1 = FUN_003a2d80(param_2);

  FUN_003a4990(lVar1,4,0);

  param_1[2] = (int)lVar1;

  if (lVar1 < 0) {

    FUN_0019d3f0("mt_evtMessage.c",0x27);

  }

  *param_1 = 1;

  return lVar1;

}
#define FUN_0039edd0(...) ((long (*)(...))FUN_0039edd0)(__VA_ARGS__)
#undef FUN_0039ee80
// FUN_0039EE80 NONMATCHING


void FUN_0039ee80(u64 param_1)



{

  int *piVar1;

  

  piVar1 = (int *)param_1;

  if (*piVar1 != 0) {

    FUN_0039f350();

    FUN_003a3060(piVar1[2]);

    *piVar1 = 0;

    FUN_00521408(param_1,0,0x20);

  }

  return;

}
#define FUN_0039ee80(...) ((void (*)(...))FUN_0039ee80)(__VA_ARGS__)
#undef FUN_0039eee0
// FUN_0039eee0


u8 FUN_0039eee0(int *param_1)



{

  return *param_1 != 0;

}
#define FUN_0039eee0(...) ((u8 (*)(...))FUN_0039eee0)(__VA_ARGS__)
#undef FUN_0039eef0
// FUN_0039EEF0


void FUN_0039eef0(int *param_1,u64 param_2,u64 param_3)



{

  if ((u8)(*param_1 != 0)) {

    FUN_003a4010(param_1[2],param_2,param_3,0);

  }

  return;

}
#define FUN_0039eef0(...) ((void (*)(...))FUN_0039eef0)(__VA_ARGS__)
#undef FUN_0039ef30
// FUN_0039EF30


void FUN_0039ef30(int *param_1)



{

  if ((u8)(*param_1 != 0)) {

    FUN_003a4220(param_1[2]);

  }

  return;

}
#define FUN_0039ef30(...) ((void (*)(...))FUN_0039ef30)(__VA_ARGS__)
#undef FUN_0039ef70
// FUN_0039EF70


void FUN_0039ef70(int *param_1,u64 param_2,int param_3)



{

  u8 *uVar1;

  

  uVar1 = FUN_003c3f80(param_3);

  if ((u8)(*param_1 != 0) != 0) {

    FUN_003a4220(param_1[2],param_2,uVar1);

  }

  return;

}
#define FUN_0039ef70(...) ((void (*)(...))FUN_0039ef70)(__VA_ARGS__)
#undef FUN_0039efd0
// FUN_0039EFD0 NONMATCHING


void FUN_0039efd0(int *param_1,u64 param_2,u16 param_3)



{

  u8 uVar1;

  u64 uVar2;

  

  uVar1 = FUN_0016df30(param_3);

  uVar2 = FUN_0030bbb0(uVar1);

  if (*param_1 != 0) {

    FUN_003a4220(param_1[2],param_2,uVar2);

  }

  return;

}
#define FUN_0039efd0(...) ((void (*)(...))FUN_0039efd0)(__VA_ARGS__)
#undef FUN_0039f050
// FUN_0039F050


void FUN_0039f050(int *param_1,int param_2,u16 param_3)



{

  s8 uVar1;

  

  uVar1 = FUN_0016dba0(param_3);

  if ((u8)(*param_1 != 0)) {

    FUN_003a4010_evt(param_1[2],param_2,uVar1,0);

  }

  return;

}
#define FUN_0039f050(...) ((void (*)(...))FUN_0039f050)(__VA_ARGS__)
#undef FUN_0039f0c0
// FUN_0039F0C0


void FUN_0039f0c0(int *param_1,u64 param_2,u8 param_3)



{

  u8 *uVar1;

  

  uVar1 = FUN_003c3f40(param_3);

  if ((u8)(*param_1 != 0) != 0) {

    FUN_003a4220(param_1[2],param_2,uVar1);

  }

  return;

}
#define FUN_0039f0c0(...) ((void (*)(...))FUN_0039f0c0)(__VA_ARGS__)
#undef FUN_0039f120
// FUN_0039F120


void FUN_0039f120(int *param_1,u64 param_2,u64 param_3,u64 param_4)



{

  u8 *uVar1;

  

  uVar1 = FUN_0013bcb0(param_3,param_4);

  if ((u8)(*param_1 != 0) != 0) {

    FUN_003a4220(param_1[2],param_2,uVar1);

  }

  return;

}
#define FUN_0039f120(...) ((void (*)(...))FUN_0039f120)(__VA_ARGS__)
#undef FUN_0039f190
// FUN_0039F190 NONMATCHING


void FUN_0039f190(int *param_1,u64 param_2,u16 param_3)



{

  u8 uVar1;

  u64 uVar2;

  

  uVar1 = FUN_0016df30(param_3);

  uVar2 = FUN_003c4390(uVar1);

  if (*param_1 != 0) {

    FUN_003a4220(param_1[2],param_2,uVar2);

  }

  return;

}
#define FUN_0039f190(...) ((void (*)(...))FUN_0039f190)(__VA_ARGS__)
#undef FUN_0039f210
// FUN_0039F210 NONMATCHING


void FUN_0039f210(int *param_1,int param_2,int param_3,int param_4)



{

  if (*param_1 != 0) {

    if (param_1[3] != 0) {

      FUN_0039f2a0();

    }

    param_1[3] = 1;

    param_1[4] = param_2;

    param_1[5] = param_3;

    param_1[6] = param_4;

    param_1[7] = -1;

  }

  return;

}
#define FUN_0039f210(...) ((void (*)(...))FUN_0039f210)(__VA_ARGS__)
#undef FUN_0039f2a0
// FUN_0039F2A0 NONMATCHING


void FUN_0039f2a0(int *param_1)



{

  int iVar1;

  

  iVar1 = param_1[2];

  if ((*param_1 != 0) && (param_1[3] != 0)) {

    FUN_003a25f0(iVar1,0);

    FUN_003a2a30(iVar1);

    FUN_003a3420(iVar1,0);

    FUN_003a3e90(iVar1,0x800000);

    FUN_003a3e90(iVar1,0x100000);

    FUN_003a25f0(iVar1,1);

    param_1[3] = 0;

  }

  return;

}
#define FUN_0039f2a0(...) ((void (*)(...))FUN_0039f2a0)(__VA_ARGS__)
#undef FUN_0039f350
// FUN_0039F350 NONMATCHING


void FUN_0039f350(int *param_1)



{

  int iVar1;

  

  if (((*param_1 != 0) && (param_1[3] != 0)) && (iVar1 = param_1[2], param_1[3] != 0)) {

    FUN_003a25f0(iVar1,0);

    FUN_003a2a30(iVar1);

    FUN_003a3420(iVar1,0);

    FUN_003a3e90(iVar1,0x800000);

    FUN_003a3e90(iVar1,0x100000);

    FUN_003a25f0(iVar1,1);

    param_1[3] = 0;

  }

  return;

}
#define FUN_0039f350(...) ((void (*)(...))FUN_0039f350)(__VA_ARGS__)
#undef FUN_0039f410
// FUN_0039F410 NONMATCHING


void FUN_0039f410(int *param_1)



{

  int iVar1;

  int iVar2;

  long lVar3;

  u64 uVar4;

  int iVar5;

  

  if (*param_1 != 0) {

    iVar2 = param_1[2];

    switch(param_1[3]) {

    case 1:

      iVar5 = param_1[4];

      if (iVar5 < 0) {

        param_1[3] = 3;

      }

      else {

        iVar1 = param_1[1];

        if (iVar1 == 2) {

          iVar2 = FUN_003a4b90(iVar2,iVar5,0);

          iVar5 = iVar2 >> 5;

          if (iVar2 >> 4 < 0) {

            iVar5 = (iVar2 >> 4) + 1 >> 1;

          }

          FUN_003a3ce0(param_1[2],(0x140 - iVar5) * 0x10,0x5f0);

        }

        else if (iVar1 == 1) {

          iVar2 = FUN_003a4b90(iVar2,iVar5,0);

          iVar5 = iVar2 >> 5;

          if (iVar2 >> 4 < 0) {

            iVar5 = (iVar2 >> 4) + 1 >> 1;

          }

          FUN_003a3ce0(param_1[2],(0x140 - iVar5) * 0x10,0x8a0);

        }

        else if (iVar1 == 0) {

          FUN_003a3e10(iVar2,0x200000);

        }

        FUN_003a30c0(param_1[2],param_1[4],0);

        FUN_003a27c0(param_1[2],0xffffffffffffffff);

        param_1[3] = 2;

      }

      break;

    case 2:

      lVar3 = FUN_003a2580(iVar2);

      if (lVar3 < 0) {

        param_1[3] = 3;

      }

      break;

    case 3:

      if (param_1[5] < 0) {

        param_1[3] = 5;

      }

      else {

        FUN_003a3c10(iVar2,0);

        FUN_003a37c0(iVar2,param_1[5]);

        param_1[3] = 4;

      }

      break;

    case 4:

      lVar3 = FUN_003a2750(iVar2);

      if (lVar3 < 0) {

        uVar4 = FUN_003a3f20(iVar2);

        iVar2 = param_1[6];

        if ((-1 < iVar2) && (iVar2 < 10)) {

          FUN_0038d6b0(iVar2,uVar4);

        }

        param_1[7] = (int)uVar4;

        param_1[3] = 5;

      }

      break;

    case 5:

      if (param_1[3] != 0) {

        FUN_003a25f0(iVar2,0);

        FUN_003a2a30(iVar2);

        FUN_003a3420(iVar2,0);

        FUN_003a3e90(iVar2,0x800000);

        FUN_003a3e90(iVar2,0x100000);

        FUN_003a25f0(iVar2,1);

        param_1[3] = 0;

      }

    }

  }

  return;

}
#define FUN_0039f410(...) ((void (*)(...))FUN_0039f410)(__VA_ARGS__)
#undef FUN_0039f6e0
#pragma push
#pragma opt_rebuildconditionals off
// FUN_0039F6E0


u8 FUN_0039f6e0(int *param_1)



{

  u8 bVar1;

  

  if ((u8)(*param_1 != 0)) goto nonzero;

  return 1;

nonzero:

  return param_1[3] == 0;

}
#pragma pop
#define FUN_0039f6e0(...) ((u8 (*)(...))FUN_0039f6e0)(__VA_ARGS__)
#undef FUN_0039f710
// FUN_0039F710 NONMATCHING


u32 FUN_0039f710(int *param_1)



{

  u32 uVar1;

  

  if (!(u8)(*param_1 != 0)) {

    uVar1 = 0;

  }

  else {

    uVar1 = FUN_003a51a0(param_1[2]);

  }

  return uVar1;

}
#define FUN_0039f710(...) ((u32 (*)(...))FUN_0039f710)(__VA_ARGS__)
#undef FUN_0039f750
// FUN_0039F750


void FUN_0039f750(int *param_1,int param_2)



{

  if (!(u8)(*param_1 != 0)) {

    FUN_0019d3f0_ptr((void*)(DAT_006a0000 + 0x1840),0x15f);

  }

  FUN_003a5120(param_1[2],param_2);

  return;

}
#define FUN_0039f750(...) ((void (*)(...))FUN_0039f750)(__VA_ARGS__)
#undef FUN_0039f7c0
// FUN_0039F7C0


void FUN_0039f7c0(int *param_1)



{

  if ((u8)(*param_1 != 0)) {

    FUN_003a3ba0(param_1[2]);

  }

  return;

}
#define FUN_0039f7c0(...) ((void (*)(...))FUN_0039f7c0)(__VA_ARGS__)
#undef FUN_0039f800
// FUN_0039F800


int FUN_0039f800(int *param_1)



{

  if (!(u8)(*param_1 != 0)) {

    FUN_0019d3f0_ptr((void*)(DAT_006a0000 + 0x1840),0x173);

  }

  return param_1[7];

}
#define FUN_0039f800(...) ((int (*)(...))FUN_0039f800)(__VA_ARGS__)
#undef FUN_0039f850
// FUN_0039F850 NONMATCHING


u8 FUN_0039f850(int param_1)



{

  u32 uVar1;

  int iVar2;

  int iVar3;

  int iStack_4;

  

  for (iVar3 = 0; iVar3 < *(int *)(param_1 + 0x70); iVar3 = iVar3 + 1) {

    iVar2 = param_1 + iVar3 * 4;

    if (*(int *)(iVar2 + 0x68) == 0) {

      uVar1 = FUN_0010c3a0(*(u32 *)(iVar2 + 0x60),&iStack_4,0);

      if (iStack_4 == 1) {

        *(u32 *)(iVar2 + 0x68) = uVar1;

        *(u32 *)(iVar2 + 0x60) = 0;

      }

    }

  }

  iVar3 = 0;

  while( 1 ) {

    if (*(int *)(param_1 + 0x70) <= iVar3) {

      return 1;

    }

    if (*(int *)(param_1 + iVar3 * 4 + 0x68) == 0) break;

    iVar3 = iVar3 + 1;

  }

  return 0;

}
#define FUN_0039f850(...) ((u8 (*)(...))FUN_0039f850)(__VA_ARGS__)
#undef FUN_0039f950
// FUN_0039F950 NONMATCHING


void FUN_0039f950(int param_1)



{

  int iVar1;

  u32 uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  iVar1 = FUN_003b5d50(1);

  iVar5 = 0;

  iVar4 = 0;

  for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xf8)) {

    iVar5 = iVar5 + 1;

  }

  for (iVar1 = FUN_003b5d50(3); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xf8)) {

    iVar5 = iVar5 + 1;

  }

  if (iVar5 != 0) {

    uVar2 = (*DAT_00960178)(iVar5 << 4,0x40000);

    *(u32 *)(param_1 + 0xe8) = uVar2;

    for (iVar1 = FUN_003b5d50(1); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xf8)) {

      iVar3 = iVar4 * 0x10;

      *(u32 *)(*(int *)(param_1 + 0xe8) + iVar3 + 4) = *(u32 *)(iVar1 + 0x128);

      uVar2 = FUN_003b83a0(iVar1);

      *(u32 *)(*(int *)(param_1 + 0xe8) + iVar3 + 8) = uVar2;

      *(u32 *)(*(int *)(param_1 + 0xe8) + iVar3) =

           *(u32 *)(*(int *)(iVar1 + 0x128) + 0xf4);

      *(int *)(*(int *)(param_1 + 0xe8) + iVar3 + 0xc) = iVar1;

      iVar4 = iVar4 + 1;

    }

    for (iVar1 = FUN_003b5d50(3); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xf8)) {

      iVar3 = iVar4 * 0x10;

      *(u32 *)(*(int *)(param_1 + 0xe8) + iVar3 + 4) = *(u32 *)(iVar1 + 0x128);

      uVar2 = FUN_003b83a0(iVar1);

      *(u32 *)(*(int *)(param_1 + 0xe8) + iVar3 + 8) = uVar2;

      *(u32 *)(*(int *)(param_1 + 0xe8) + iVar3) =

           *(u32 *)(*(int *)(iVar1 + 0x128) + 0xf4);

      *(int *)(*(int *)(param_1 + 0xe8) + iVar3 + 0xc) = iVar1;

      iVar4 = iVar4 + 1;

    }

    *(int *)(param_1 + 0xe4) = iVar5;

  }

  return;

}
#define FUN_0039f950(...) ((void (*)(...))FUN_0039f950)(__VA_ARGS__)
#undef FUN_0039fb10
// FUN_0039FB10


void FUN_0039fb10(void)



{

  u16 *puVar1;

  

  FUN_003b5d50(1);

  for (puVar1 = (u16 *)FUN_003b5d50(1); puVar1 != (u16 *)0x0;

      puVar1 = *(u16 **)(puVar1 + 0x7c)) {

    FUN_003189f0(*(u32 *)(puVar1 + 0x94),0,0.0f);

    FUN_003b8310(*puVar1,1);

  }

  for (puVar1 = (u16 *)FUN_003b5d50(3); puVar1 != (u16 *)0x0;

      puVar1 = *(u16 **)(puVar1 + 0x7c)) {

    FUN_003189f0(*(u32 *)(puVar1 + 0x94),0,0.0f);

    FUN_003b8310(*puVar1,1);

  }

  return;

}
#define FUN_0039fb10(...) ((void (*)(...))FUN_0039fb10)(__VA_ARGS__)
#undef FUN_0039fbd0
// FUN_0039FBD0 NONMATCHING


void FUN_0039fbd0(int param_1)



{

  u64 uVar1;

  u64 uVar2;

  int iVar3;

  float *pfVar4;

  float *pfVar5;

  float fVar6;

  float fVar7;

  float afStack_50 [19];

  undefined3 uStack_4;

  u8 uStack_1;

  

  pfVar5 = (float *)&DAT_006a1850;

  pfVar4 = afStack_50 + 8;

  iVar3 = 4;

  do {

    fVar6 = *pfVar5;

    fVar7 = pfVar5[1];

    pfVar5 = pfVar5 + 2;

    iVar3 = iVar3 + -1;

    *pfVar4 = fVar6;

    pfVar4[1] = fVar7;

    pfVar4 = pfVar4 + 2;

  } while (0 < iVar3);

  pfVar5 = (float *)&DAT_006a1870;

  pfVar4 = afStack_50;

  iVar3 = 4;

  do {

    fVar6 = *pfVar5;

    fVar7 = pfVar5[1];

    pfVar5 = pfVar5 + 2;

    iVar3 = iVar3 + -1;

    *pfVar4 = fVar6;

    pfVar4[1] = fVar7;

    pfVar4 = pfVar4 + 2;

  } while (0 < iVar3);

  uStack_4 = CONCAT13((char)*(u32 *)(param_1 + 0x9c),*(undefined3 *)(param_1 + 0xb0));

  afStack_50[0x10] = 127.0;

  afStack_50[0x11] = -130.0;

  afStack_50[0x12] = 0.0;

  FUN_004c69f0(afStack_50 + 0x10,afStack_50 + 0x10);

  uVar1 = FUN_00530da0(DAT_007cae58 * ((float)*(int *)(param_1 + 0xbc) / 180.0));

  uVar1 = FUN_0052e038(uVar1);

  uVar1 = FUN_005311c8(0x3ff0000000000000,uVar1);

  uVar2 = FUN_00530da0(afStack_50[0x10] * 50.0);

  uVar1 = FUN_00531230(uVar2,uVar1);

  fVar6 = (float)FUN_005318a0(uVar1);

  uVar1 = FUN_00530da0(DAT_007cae58 * ((float)*(int *)(param_1 + 0xbc) / 180.0));

  uVar1 = FUN_0052e038(uVar1);

  uVar1 = FUN_005311c8(0x3ff0000000000000,uVar1);

  uVar2 = FUN_00530da0(afStack_50[0x11] * 50.0);

  uVar1 = FUN_00531230(uVar2,uVar1);

  fVar7 = (float)FUN_005318a0(uVar1);

  afStack_50[8] = 256.5;

  afStack_50[9] = 96.0;

  afStack_50[10] = 383.5;

  afStack_50[0xb] = 96.0;

  afStack_50[0xc] = 256.5;

  afStack_50[0xd] = 243.0;

  afStack_50[0xe] = 383.5;

  afStack_50[0xf] = 113.0;

  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

    afStack_50[iVar3 * 2 + 8] = afStack_50[iVar3 * 2 + 8] + fVar6;

    afStack_50[iVar3 * 2 + 9] = afStack_50[iVar3 * 2 + 9] + fVar7;

  }

  afStack_50[0] = 0.0;

  afStack_50[1] = 0.0;

  afStack_50[2] = 1.0;

  afStack_50[3] = 0.0;

  afStack_50[4] = 0.0;

  afStack_50[5] = 0.57421875;

  afStack_50[6] = 1.0;

  afStack_50[7] = 0.06640625;

  FUN_003877c0(0x41200000,0x42200000,afStack_50 + 8,afStack_50,*(u32 *)(param_1 + 0x6c),

               &uStack_4);

  afStack_50[8] = 256.5;

  afStack_50[9] = 243.0;

  afStack_50[10] = 383.5;

  afStack_50[0xb] = 113.0;

  afStack_50[0xc] = 256.5;

  afStack_50[0xd] = 260.0;

  afStack_50[0xe] = 383.5;

  afStack_50[0xf] = 260.0;

  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

    afStack_50[iVar3 * 2 + 8] = afStack_50[iVar3 * 2 + 8] - fVar6;

    afStack_50[iVar3 * 2 + 9] = afStack_50[iVar3 * 2 + 9] - fVar7;

  }

  afStack_50[0] = 0.0;

  afStack_50[1] = 0.57421875;

  afStack_50[2] = 1.0;

  afStack_50[3] = 0.06640625;

  afStack_50[4] = 0.0;

  afStack_50[5] = 0.63671875;

  afStack_50[6] = 1.0;

  afStack_50[7] = 0.63671875;

  FUN_003877c0(0x41100000,0x42200000,afStack_50 + 8,afStack_50,*(u32 *)(param_1 + 0x6c),

               &uStack_4);

  return;

}
#define FUN_0039fbd0(...) ((void (*)(...))FUN_0039fbd0)(__VA_ARGS__)
#undef FUN_0039ffc0
// FUN_0039FFC0 NONMATCHING


void FUN_0039ffc0(int param_1,float *param_2,int param_3,u64 param_4)



{

  u64 uVar1;

  u64 uVar2;

  u8 uVar3;

  float fVar4;

  float fVar5;

  u32 uStack_28;

  u32 uStack_24;

  u32 uStack_20;

  u32 uStack_1c;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_c;

  u32 uStack_4;

  

  uStack_4 = DAT_007cd490;

  uVar1 = FUN_00530da0(DAT_007cae58 * (*param_2 / 180.0));

  uVar1 = FUN_0052e328(uVar1);

  fVar4 = (float)FUN_005318a0(uVar1);

  fVar5 = fVar4 / 4.0 + 1.0;

  uVar1 = FUN_00530da0(DAT_007cae58 * ((*(float *)(param_1 + 0xa8) - 90.0) / 180.0));

  uVar1 = FUN_0052e328(uVar1);

  uVar2 = FUN_00530da0(fVar5 * 127.0);

  uVar1 = FUN_00531230(uVar2,uVar1);

  fStack_18 = (float)FUN_005318a0(uVar1);

  fStack_14 = fVar5 * 164.0;

  fStack_10 = 320.0 - fStack_18 / 2.0;

  fStack_c = 178.0 - fStack_14 / 2.0;

  uStack_20 = 0;

  uStack_1c = 0;

  uStack_28 = 0x3f800000;

  uStack_24 = 0x3f240000;

  fVar4 = (1.0 - fVar4) * 128.0;

  if (fVar4 < 2.1474836e+09) {

    uVar3 = (u8)(int)fVar4;

  }

  else {

    uVar3 = (u8)(int)(fVar4 - 2.1474836e+09);

  }

  uStack_4 = CONCAT13(uVar3,(undefined3)uStack_4);

  FUN_00388000(0x40800000,*(u32 *)(param_1 + 0xac),&fStack_10,&fStack_18,&uStack_20,

               &uStack_28,param_4,&uStack_4,0);

  *param_2 = DAT_007caf30 * (float)param_3;

  return;

}
#define FUN_0039ffc0(...) ((void (*)(...))FUN_0039ffc0)(__VA_ARGS__)
#undef FUN_003a0220
// FUN_003A0220 NONMATCHING


u64 FUN_003a0220(int param_1)



{

  int iVar1;

  u8 *puVar2;

  u8 *puVar3;

  int iVar4;

  u64 uVar5;

  u64 uVar6;

  u8 *puVar7;

  int *piVar8;

  int iVar9;

  float fVar10;

  u64 uStack_38;

  u8 auStack_30 [8];

  u32 uStack_28;

  u32 uStack_24;

  u32 uStack_20;

  u32 uStack_1c;

  float afStack_18 [3];

  u32 uStack_c;

  undefined3 uStack_8;

  u8 uStack_5;

  u32 uStack_4;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  uStack_4 = DAT_007cd494;

  DAT_007ce61c = DAT_007ce61c + 0.5;

  if (*(int *)(iVar1 + 0xb8) != 0) {

    puVar3 = (u8 *)0x8;

    puVar7 = auStack_30;

    puVar2 = puVar7;

    while (puVar2 != (u8 *)0x0) {

      *puVar7 = 0;

      puVar7 = puVar7 + 1;

      puVar3 = puVar3 + -1;

      puVar2 = puVar3;

    }

    uStack_38 = DAT_007cd498;

    uStack_8 = CONCAT13((char)*(u32 *)(iVar1 + 0xa0),(int3)DAT_007cd4a0);

    FUN_00386f70(0x42c80000,auStack_30,&uStack_38,&uStack_8);

    uStack_4 = CONCAT13((char)*(u32 *)(iVar1 + 0x9c),*(undefined3 *)(iVar1 + 0xb0));

    if ((float)*(int *)(iVar1 + 0xbc) == 0.0) {

      uStack_20 = 0;

      uStack_1c = 0;

      uStack_28 = 0x3f800000;

      uStack_24 = 0x3f240000;

      fVar10 = *(float *)(iVar1 + 0xa8);

      if (fVar10 < 90.0) {

        uVar5 = FUN_00530da0(DAT_007cae58 * (fVar10 / 180.0));

        uVar5 = FUN_0052e038(uVar5);

        uVar6 = FUN_00530da0(0x42fe0000);

        uVar5 = FUN_00531230(uVar6,uVar5);

        afStack_18[0] = (float)FUN_005318a0(uVar5);

        afStack_18[1] = 164.0;

        afStack_18[2] = 320.0 - afStack_18[0] / 2.0;

        uStack_c = 0x42c00000;

        FUN_00388000(0x40a00000,*(u32 *)(iVar1 + 0xac),afStack_18 + 2,afStack_18,&uStack_20,

                     &uStack_28,*(u32 *)(iVar1 + 0x68),&uStack_4,0);

      }

      else {

        uVar5 = FUN_00530da0(DAT_007cae58 * ((fVar10 - 90.0) / 180.0));

        uVar5 = FUN_0052e328(uVar5);

        uVar6 = FUN_00530da0(0x42fe0000);

        uVar5 = FUN_00531230(uVar6,uVar5);

        afStack_18[0] = (float)FUN_005318a0(uVar5);

        afStack_18[1] = 164.0;

        afStack_18[2] = 320.0 - afStack_18[0] / 2.0;

        uStack_c = 0x42c00000;

        FUN_00388000(0x40a00000,*(u32 *)(iVar1 + 0xac),afStack_18 + 2,afStack_18,&uStack_20,

                     &uStack_28,*(u32 *)(iVar1 + 0x6c),&uStack_4,0);

      }

      for (iVar9 = 0; iVar9 < 1; iVar9 = iVar9 + 1) {

        iVar4 = iVar1 + 0x94 + iVar9 * 4;

        piVar8 = (int *)(iVar4 + 0x34);

        iVar4 = *(int *)(iVar4 + 0x34);

        if (0 < iVar4) {

          *piVar8 = iVar4 + 1;

        }

        if (0x37 < *piVar8) {

          if (*(int *)(iVar1 + 0xd0) == 1) {

            *piVar8 = 0;

          }

          else {

            *piVar8 = 1;

          }

        }

        if (0 < *piVar8) {

          FUN_0039ffc0(iVar1,iVar1 + 0x94 + iVar9 * 4 + 0x30,*piVar8,*(u32 *)(iVar1 + 0x6c));

        }

      }

    }

    else {

      FUN_0039fbd0(iVar1);

    }

  }

  return 0;

}
#define FUN_003a0220(...) ((u64 (*)(...))FUN_003a0220)(__VA_ARGS__)
#undef FUN_003a05b0
// FUN_003A05B0 NONMATCHING


void FUN_003a05b0(int param_1,int param_2)



{

  u32 uVar1;

  u32 uVar2;

  float fVar3;

  u16 uVar4;

  int iVar5;

  u32 *puVar6;

  u64 uVar7;

  u64 uVar8;

  u64 uVar9;

  u64 uVar10;

  u64 uVar11;

  u64 uVar12;

  u64 uVar13;

  u32 *puVar14;

  u16 *puVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  float fVar19;

  u32 auStack_b0 [4];

  float fStack_a0;

  float fStack_9c;

  float fStack_98;

  float fStack_90;

  float fStack_8c;

  float fStack_88;

  float fStack_80;

  float fStack_7c;

  float fStack_78;

  u8 auStack_68 [16];

  u8 auStack_58 [16];

  float fStack_48;

  float fStack_44;

  float fStack_40;

  float fStack_38;

  float fStack_34;

  float fStack_30;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  u32 uStack_8;

  u32 uStack_4;

  

  iVar5 = *(int *)(param_2 * 4 + param_1 + 0x74);

  if (iVar5 != 0) {

    puVar15 = (u16 *)(param_2 * 2 + param_1 + 0xec);

    uVar4 = FUN_003b64c0(param_2 + 0xfaU & 0xffff,iVar5,1);

    *puVar15 = uVar4;

    iVar5 = FUN_00198590();

    puVar6 = (u32 *)FUN_004cb2f0(*(u32 *)(iVar5 + 4));

    puVar14 = auStack_b0;

    iVar5 = 8;

    do {

      uVar1 = *puVar6;

      uVar2 = puVar6[1];

      puVar6 = puVar6 + 2;

      iVar5 = iVar5 + -1;

      *puVar14 = uVar1;

      puVar14[1] = uVar2;

      puVar14 = puVar14 + 2;

    } while (0 < iVar5);

    fStack_18 = fStack_90;

    fStack_14 = fStack_8c;

    fStack_10 = fStack_88;

    fStack_28 = fStack_a0;

    fStack_24 = fStack_9c;

    fStack_20 = fStack_98;

    fStack_38 = fStack_80;

    fStack_34 = fStack_7c;

    fStack_30 = fStack_78;

    FUN_004c69f0(&fStack_18,&fStack_18);

    fVar3 = fStack_30;

    fVar19 = fStack_18 * 800.0 + fStack_38 + 0.0;

    fVar16 = fStack_14 * 800.0 + fStack_34 + 0.0;

    fVar17 = fStack_10 * 800.0 + fStack_30 + 0.0;

    fVar18 = fStack_34;

    fStack_48 = fVar19;

    fStack_44 = fVar16;

    fStack_40 = fVar17;

    uVar7 = FUN_00530da0();

    uVar8 = FUN_00530da0(fVar18);

    uVar9 = FUN_00530da0(fVar3);

    uVar10 = FUN_00530da0(fVar19);

    uVar11 = FUN_00530da0(fVar16);

    uVar12 = FUN_00530da0(fVar17);

    uVar13 = FUN_00530da0(fVar19 - fStack_38);

    FUN_00530da0(fVar16 - fVar18);

    FUN_00530da0(fVar17 - fVar3);

    FUN_005225a8(0x6a1890,uVar7,uVar8,uVar9,uVar10,uVar11,uVar12,uVar13);

    if (param_2 == 3) {

      fStack_48 = (fStack_48 + 0.0) - fStack_28 * 85.0;

      fStack_44 = (fStack_44 + 0.0) - fStack_24 * 85.0;

      fStack_40 = (fStack_40 + 0.0) - fStack_20 * 85.0;

    }

    else {

      fStack_48 = (fStack_48 + 0.0) - fStack_28 * 240.0;

      fStack_44 = (fStack_44 + 0.0) - fStack_24 * 240.0;

      fStack_40 = (fStack_40 + 0.0) - fStack_20 * 240.0;

    }

    FUN_003b7ac0(auStack_b0,auStack_68,auStack_58);

    FUN_003b78b0(*puVar15,&fStack_48,auStack_68);

    if (param_2 == 6) {

      iVar5 = FUN_003b5d10(*puVar15);

      FUN_00350040(*(u32 *)(iVar5 + 0x104),&uStack_4);

      uStack_8 = uStack_4 & 0xffffff;

      FUN_0034ff90(*(u32 *)(iVar5 + 0x104),&uStack_8);

    }

    FUN_003b9550(*puVar15,1);

  }

  return;

}
#define FUN_003a05b0(...) ((void (*)(...))FUN_003a05b0)(__VA_ARGS__)
#undef FUN_003a0960
// FUN_003A0960 NONMATCHING


void FUN_003a0960(int param_1,int param_2,u64 param_3)



{

  u32 *puVar1;

  u16 uVar2;

  long lVar3;

  u32 *puVar4;

  int iVar5;

  u32 *puVar6;

  u16 *puVar7;

  u32 uStack_10;

  float fStack_c;

  u32 uStack_8;

  

  iVar5 = *(int *)(param_2 * 4 + param_1 + 0x74);

  if (iVar5 != 0) {

    uVar2 = FUN_003b64c0(param_2 + 0xfaU & 0xffff,iVar5,0);

    *(u16 *)(param_2 * 2 + param_1 + 0xec) = uVar2;

    lVar3 = FUN_003b5d10(param_3);

    puVar4 = (u32 *)0xc;

    puVar6 = &uStack_10;

    puVar1 = puVar6;

    while (puVar1 != (u32 *)0x0) {

      *(u8 *)puVar6 = 0;

      puVar6 = (u32 *)((int)puVar6 + 1);

      puVar4 = (u32 *)((int)puVar4 + -1);

      puVar1 = puVar4;

    }

    if (lVar3 != 0) {

      puVar7 = (u16 *)lVar3;

      iVar5 = (int)(*puVar7 & 0xffc00) >> 10;

      if (iVar5 == 3) {

        lVar3 = FUN_00318ed0(*(u32 *)(puVar7 + 0x94),2,&uStack_10);

        if (lVar3 == 0) {

          iVar5 = FUN_00318b60(*(u32 *)(puVar7 + 0x94));

          uStack_10 = *(u32 *)(iVar5 + 0x30);

          uStack_8 = *(u32 *)(iVar5 + 0x38);

          fStack_c = *(float *)(iVar5 + 0x34) + 175.0;

        }

      }

      else if (iVar5 == 1) {

        FUN_00318b60(*(u32 *)(puVar7 + 0x94));

        lVar3 = FUN_00318ed0(*(u32 *)(puVar7 + 0x94),2,&uStack_10);

        if (lVar3 == 0) {

          iVar5 = FUN_00318b60(*(u32 *)(puVar7 + 0x94));

          uStack_10 = *(u32 *)(iVar5 + 0x30);

          uStack_8 = *(u32 *)(iVar5 + 0x38);

          fStack_c = *(float *)(iVar5 + 0x34) + 175.0;

        }

      }

      param_1 = param_2 * 2 + param_1;

      FUN_003b78b0(*(u16 *)(param_1 + 0xec),&uStack_10,0);

      FUN_003b9550(*(u16 *)(param_1 + 0xec),1);

    }

  }

  return;

}
#define FUN_003a0960(...) ((void (*)(...))FUN_003a0960)(__VA_ARGS__)
#undef FUN_003a0b50
// FUN_003A0B50 NONMATCHING


u32 FUN_003a0b50(int param_1)



{

  int iVar1;

  char cVar2;

  long lVar3;

  u32 *puVar4;

  

  puVar4 = (u32 *)(param_1 + 0xc0);

  switch(*(u32 *)(param_1 + 0xc0)) {

  case 0:

    iVar1 = *(int *)(param_1 + 8);

    if ((iVar1 == 3) || (iVar1 == 2)) {

      *puVar4 = 0xf;

    }

    else if (iVar1 == 1) {

      cVar2 = FUN_0016dba0(*(u16 *)(param_1 + 4));

      if (cVar2 == '\n') {

        *puVar4 = 7;

      }

      else {

        *puVar4 = 3;

      }

    }

    else if (iVar1 == 0) {

      *puVar4 = 1;

    }

    break;

  case 1:

    FUN_0039f210(param_1 + 0x3c,1,0xffffffffffffffff,0xffffffffffffffff);

    *puVar4 = 2;

    break;

  case 2:

    lVar3 = FUN_0039f6e0(param_1 + 0x3c);

    if (lVar3 == 1) {

      *puVar4 = 0xf;

    }

    break;

  case 3:

    FUN_0039f210(param_1 + 0x3c,2,0xffffffffffffffff,0xffffffffffffffff);

    *puVar4 = 4;

    break;

  case 4:

    lVar3 = FUN_0039f6e0(param_1 + 0x3c);

    if (lVar3 == 1) {

      *puVar4 = 5;

    }

    break;

  case 5:

    FUN_0039f210(param_1 + 0x3c,3,0xffffffffffffffff,0xffffffffffffffff);

    *puVar4 = 6;

    break;

  case 6:

    lVar3 = FUN_0039f6e0(param_1 + 0x3c);

    if (lVar3 == 1) {

      *puVar4 = 0xf;

    }

    break;

  case 7:

    FUN_0039f210(param_1 + 0x3c,4,0xffffffffffffffff,0xffffffffffffffff);

    *puVar4 = 8;

    break;

  case 8:

    lVar3 = FUN_0039f6e0(param_1 + 0x3c);

    if (lVar3 == 1) {

      *puVar4 = 9;

    }

    break;

  case 9:

    FUN_0039f210(param_1 + 0x3c,5,0xffffffffffffffff,0xffffffffffffffff);

    *puVar4 = 10;

    break;

  case 10:

    lVar3 = FUN_0039f6e0(param_1 + 0x3c);

    if (lVar3 == 1) {

      *puVar4 = 0xb;

    }

    break;

  case 0xb:

    FUN_0039f210(param_1 + 0x3c,*(short *)(param_1 + 4) * 2 + 6,0xffffffffffffffff,

                 0xffffffffffffffff);

    *puVar4 = 0xc;

    break;

  case 0xc:

    lVar3 = FUN_0039f6e0(param_1 + 0x3c);

    if (lVar3 == 1) {

      *puVar4 = 0xd;

    }

    break;

  case 0xd:

    FUN_0039f210(param_1 + 0x3c,*(short *)(param_1 + 4) * 2 + 7,0xffffffffffffffff,

                 0xffffffffffffffff);

    *puVar4 = 0xe;

    break;

  case 0xe:

    lVar3 = FUN_0039f6e0(param_1 + 0x3c);

    if (lVar3 == 1) {

      *puVar4 = 0xf;

    }

    break;

  case 0xf:

    return 1;

  }

  return 0;

}
#define FUN_003a0b50(...) ((u32 (*)(...))FUN_003a0b50)(__VA_ARGS__)
#undef FUN_003a0e90
// FUN_003A0E90 NONMATCHING


u32 FUN_003a0e90(u64 param_1)



{

  int iVar1;

  u8 uVar2;

  char cVar3;

  long lVar4;

  int iVar5;

  u32 *puVar6;

  int iVar7;

  float fVar8;

  u32 uVar9;

  u8 auStack_90 [64];

  u8 auStack_50 [72];

  undefined3 uStack_8;

  u8 uStack_5;

  u8 auStack_4 [4];

  

  iVar1 = *(int *)((int)param_1 + 0x3c);

  puVar6 = (u32 *)(iVar1 + 0x94);

  iVar5 = iVar1 + 0x1c;

  switch(*(u32 *)(iVar1 + 0x94)) {

  case 0:

    FUN_00194b20(param_1,0x6a18c0,0x106f,0x3a0220,0,iVar1);

    *puVar6 = 1;

    break;

  case 1:

    uVar9 = FUN_00100d80(0x6a18e0,0);

    *(u32 *)(iVar1 + 0x14) = uVar9;

    *puVar6 = 2;

    break;

  case 2:

    lVar4 = FUN_001016b0(*(u32 *)(iVar1 + 0x14));

    if (lVar4 == 1) {

      uVar9 = FUN_0010c1a0(0,0x6a18e0,0,0,0,0,0,0);

      *(u32 *)(iVar1 + 0x60) = uVar9;

      *(u32 *)(iVar1 + 0x70) = 1;

      *puVar6 = 3;

    }

    break;

  case 3:

    uVar2 = FUN_0016df30(*(u16 *)(iVar1 + 4));

    FUN_00523ac8(auStack_50,0x6a1920,uVar2);

    uVar9 = FUN_00100d80(auStack_50,0);

    *(u32 *)(iVar1 + 0x18) = uVar9;

    *puVar6 = 4;

    break;

  case 4:

    lVar4 = FUN_001016b0(*(u32 *)(iVar1 + 0x18));

    if (lVar4 == 1) {

      uVar2 = FUN_0016df30(*(u16 *)(iVar1 + 4));

      FUN_00523ac8(auStack_90,0x6a1920,uVar2);

      uVar9 = FUN_0010c1a0(0,auStack_90,0,0,0,0,0,0);

      *(u32 *)(iVar1 + 100) = uVar9;

      *(u32 *)(iVar1 + 0x70) = 2;

      *puVar6 = 5;

    }

    break;

  case 5:

    lVar4 = FUN_0039f850(iVar1);

    if (lVar4 == 1) {

      *(u8 *)(iVar1 + 0xb1) = 0xff;

      *(u8 *)(iVar1 + 0xb2) = 0xff;

      *(u8 *)(iVar1 + 0xb0) = 0xff;

      *(u8 *)(iVar1 + 0xb3) = 0;

      iVar7 = *(int *)(iVar1 + 8);

      if ((iVar7 == 3) || (iVar7 == 2)) {

        *puVar6 = 10;

      }

      else if ((iVar7 == 1) || (iVar7 == 0)) {

        *puVar6 = 6;

      }

      iVar7 = *(int *)(iVar1 + 8);

      if (iVar7 == 3) {

        FUN_00395270(0x27);

      }

      else if (iVar7 == 2) {

        FUN_00395270(0x27);

      }

      else if ((iVar7 == 1) || (iVar7 == 0)) {

        cVar3 = FUN_0016dba0(*(u16 *)(iVar1 + 4));

        if (cVar3 == '\n') {

          FUN_00395270(0x2e);

        }

        else {

          FUN_00395270(0x56);

        }

      }

      *(u32 *)(iVar1 + 0xb8) = 1;

    }

    break;

  case 6:

    FUN_0039f210(iVar5,0,0xffffffffffffffff,0xffffffffffffffff);

    *puVar6 = 7;

    break;

  case 7:

    *puVar6 = 10;

    break;

  case 8:

    *puVar6 = 9;

    break;

  case 9:

    *puVar6 = 10;

    break;

  case 10:

    FUN_003a05b0(iVar1,5);

    FUN_0010a4e0(1,0,2,4);

    *(u32 *)(iVar1 + 0xa0) = 0;

    *puVar6 = 0xb;

    break;

  case 0xb:

    iVar7 = *(int *)(iVar1 + 0xa0) + 4;

    *(int *)(iVar1 + 0xa0) = iVar7;

    if (0x80 < iVar7) {

      *(u32 *)(iVar1 + 0xa0) = 0x80;

      FUN_0039fb10();

      lVar4 = FUN_0039f6e0(iVar5);

      if (lVar4 == 1) {

        *puVar6 = 0xd;

        FUN_00398390(iVar1 + 0xd4,0);

      }

    }

    break;

  case 0xc:

    lVar4 = FUN_003983a0(iVar1 + 0xd4);

    if (lVar4 != 0) {

      FUN_003952d0(0,0x1f5,4);

      FUN_003a05b0(iVar1,0);

      FUN_003a05b0(iVar1,6);

      FUN_00398390(iVar1 + 0xd4,0x1e);

      *puVar6 = 0xe;

    }

    break;

  case 0xd:

    iVar7 = *(int *)(iVar1 + 8);

    if (((iVar7 == 3) || (iVar7 == 2)) || (iVar7 == 1)) {

      *(u32 *)(iVar1 + 0xa8) = 0x43340000;

    }

    else if (iVar7 == 0) {

      *(u32 *)(iVar1 + 0xa8) = 0;

    }

    *puVar6 = 0xc;

    break;

  case 0xe:

    lVar4 = FUN_003983a0(iVar1 + 0xd4);

    if ((lVar4 != 0) &&

       (iVar7 = *(int *)(iVar1 + 0x9c) + 3, *(int *)(iVar1 + 0x9c) = iVar7, 0xff < iVar7)) {

      *(u32 *)(iVar1 + 0x9c) = 0xff;

      iVar7 = *(int *)(iVar1 + 8);

      if ((iVar7 == 3) || (iVar7 == 2)) {

        *puVar6 = 0x13;

      }

      else if (iVar7 == 1) {

        *(u32 *)(iVar1 + 200) = 1;

        *puVar6 = 0x13;

      }

      else if (iVar7 == 0) {

        FUN_003952d0(0,0xb0);

        *puVar6 = 0xf;

      }

    }

    break;

  case 0xf:

    fVar8 = *(float *)(iVar1 + 0xa8) + 8.0;

    *(float *)(iVar1 + 0xa8) = fVar8;

    if (90.0 < fVar8) {

      *(u32 *)(iVar1 + 0xa8) = 0x42b40000;

      *puVar6 = 0x10;

    }

    break;

  case 0x10:

    fVar8 = *(float *)(iVar1 + 0xa8) + 4.0;

    *(float *)(iVar1 + 0xa8) = fVar8;

    if (180.0 <= fVar8) {

      *(u32 *)(iVar1 + 0xa8) = 0x43340000;

      FUN_003a05b0(iVar1,1);

      *(u32 *)(iVar1 + 200) = 1;

      FUN_00398390(iVar1 + 0xd4,0x14);

      *puVar6 = 0x11;

    }

    break;

  case 0x11:

    lVar4 = FUN_003983a0(iVar1 + 0xd4);

    if (lVar4 != 0) {

      *puVar6 = 0x13;

    }

    break;

  case 0x13:

    lVar4 = FUN_003a0b50(iVar1);

    if (lVar4 == 1) {

      *puVar6 = 0x14;

    }

    break;

  case 0x14:

    iVar7 = *(int *)(iVar1 + 8);

    if (iVar7 == 3) {

      *puVar6 = 0x17;

    }

    else if (iVar7 == 2) {

      *puVar6 = 0x15;

      FUN_003952d0(0,0x1f6);

    }

    else if (iVar7 == 1) {

      *puVar6 = 0x1a;

    }

    else if (iVar7 == 0) {

      *puVar6 = 0x1a;

    }

    break;

  case 0x15:

    if (*(u8 *)(iVar1 + 0xb1) < 0x15) {

      *(u8 *)(iVar1 + 0xb1) = 0xe;

      *(u8 *)(iVar1 + 0xb2) = *(u8 *)(iVar1 + 0xb1);

    }

    else {

      *(u8 *)(iVar1 + 0xb1) = *(u8 *)(iVar1 + 0xb1) - 6;

      *(u8 *)(iVar1 + 0xb2) = *(u8 *)(iVar1 + 0xb1);

    }

    if ((*(u8 *)(iVar1 + 0xb1) < 0xa0) &&

       (fVar8 = *(float *)(iVar1 + 0xac) + 12.0, *(float *)(iVar1 + 0xac) = fVar8, 180.0 <= fVar8))

    {

      *(u32 *)(iVar1 + 0xac) = 0x43340000;

    }

    if ((*(char *)(iVar1 + 0xb1) == '\x0e') && (180.0 <= *(float *)(iVar1 + 0xac))) {

      FUN_00398390(iVar1 + 0xd4,0x1e);

      *puVar6 = 0x1a;

    }

    break;

  case 0x16:

    lVar4 = FUN_003983a0(iVar1 + 0xd4);

    if ((lVar4 != 0) &&

       (fVar8 = *(float *)(iVar1 + 0xac) + 12.0, *(float *)(iVar1 + 0xac) = fVar8, 180.0 <= fVar8))

    {

      *(u32 *)(iVar1 + 0xac) = 0x43340000;

      FUN_00398390(iVar1 + 0xd4,10);

      *puVar6 = 0x1a;

    }

    break;

  case 0x17:

    lVar4 = FUN_003983a0(iVar1 + 0xd4);

    if (lVar4 != 0) {

      FUN_003952d0(0,0x1f8,3);

      FUN_003a05b0(iVar1,3);

      *puVar6 = 0x18;

    }

    break;

  case 0x18:

    iVar7 = *(int *)(iVar1 + 0xbc) + 0x10;

    *(int *)(iVar1 + 0xbc) = iVar7;

    if (0xb3 < iVar7) {

      *(u32 *)(iVar1 + 0xbc) = 0xb4;

      *puVar6 = 0x19;

    }

    break;

  case 0x19:

    iVar7 = *(int *)(iVar1 + 0x9c) + -4;

    *(int *)(iVar1 + 0x9c) = iVar7;

    if (iVar7 < 0) {

      *(u32 *)(iVar1 + 0x9c) = 0;

      FUN_00398390(iVar1 + 0xd4,0x14);

      *puVar6 = 0x20;

    }

    break;

  case 0x1a:

    lVar4 = FUN_003983a0(iVar1 + 0xd4);

    if (lVar4 != 0) {

      iVar7 = *(int *)(iVar1 + 8);

      if (((iVar7 != 3) && (iVar7 != 2)) && ((iVar7 == 1 || (iVar7 == 0)))) {

        FUN_003952d0(0,0x1f5,4);

        FUN_003a05b0(iVar1,2);

      }

      *(u32 *)(iVar1 + 0xd0) = 1;

      *puVar6 = 0x1b;

    }

    break;

  case 0x1b:

    iVar7 = *(int *)(iVar1 + 0x9c) + -4;

    *(int *)(iVar1 + 0x9c) = iVar7;

    if (iVar7 < 1) {

      *(u32 *)(iVar1 + 0x9c) = 0;

      iVar7 = *(int *)(iVar1 + 8);

      if ((iVar7 == 3) || (iVar7 == 2)) {

        *puVar6 = 0x20;

      }

      else if ((iVar7 == 1) || (iVar7 == 0)) {

        *puVar6 = 0x1c;

      }

    }

    break;

  case 0x1c:

    FUN_003a0960(iVar1,4,*(u16 *)(iVar1 + 0xc));

    FUN_003952d0(0,3,3);

    FUN_00398390(iVar1 + 0xd4,0x3c);

    *puVar6 = 0x1d;

    break;

  case 0x1d:

    lVar4 = FUN_003983a0(iVar1 + 0xd4);

    if (lVar4 != 0) {

      *puVar6 = 0x20;

    }

    break;

  case 0x1e:

    *puVar6 = 0x1f;

    break;

  case 0x1f:

    if (*(int *)(iVar1 + 0xa0) < 4) {

      *(u32 *)(iVar1 + 0xa0) = 0;

      *puVar6 = 0x22;

      if (*(int *)(iVar1 + 0xe8) != 0) {

        for (iVar7 = 0; iVar7 < *(int *)(iVar1 + 0xe4); iVar7 = iVar7 + 1) {

          puVar6 = (u32 *)(*(int *)(iVar1 + 0xe8) + iVar7 * 0x10);

          uVar9 = *puVar6;

          if (puVar6[2] == 0) {

            FUN_003b82c0(puVar6[3],0);

          }

          FUN_003189f0(uVar9,*(u32 *)(*(int *)(iVar1 + 0xe8) + iVar7 * 0x10 + 4),0);

        }

      }

      FUN_00398390(iVar1 + 0xd4,0x14);

    }

    else {

      *(int *)(iVar1 + 0xa0) = *(int *)(iVar1 + 0xa0) + -2;

    }

    break;

  case 0x20:

    iVar7 = *(int *)(iVar1 + 8);

    if (iVar7 == 3) {

      FUN_0039f210(iVar5,6,0xffffffffffffffff,0xffffffffffffffff);

    }

    else if (iVar7 == 2) {

      FUN_0039f210(iVar5,5,0xffffffffffffffff,0xffffffffffffffff);

    }

    else if (iVar7 == 1) {

      cVar3 = FUN_0016dba0(*(u16 *)(iVar1 + 4));

      if (cVar3 == '\n') {

        FUN_0039f210(iVar5,4,0xffffffffffffffff,0xffffffffffffffff);

      }

      else {

        FUN_0039f210(iVar5,3,0xffffffffffffffff,0xffffffffffffffff);

      }

    }

    else if (iVar7 == 0) {

      FUN_0039f210(iVar5,2,0xffffffffffffffff,0xffffffffffffffff);

    }

    *puVar6 = 0x21;

    break;

  case 0x21:

    lVar4 = FUN_0039f6e0(iVar5);

    if (lVar4 == 1) {

      *puVar6 = 0x1e;

    }

    break;

  case 0x22:

    FUN_00398390(iVar1 + 0xd4,5);

    *puVar6 = 0x23;

    break;

  case 0x23:

    lVar4 = FUN_003983a0(iVar1 + 0xd4);

    if (lVar4 != 0) {

      if (*(short *)(iVar1 + 0xe0) == -1) {

        FUN_00108f70();

      }

      else {

        FUN_00395270();

      }

      return 0xffffffff;

    }

  }

  lVar4 = FUN_003b5d10(*(u16 *)(iVar1 + 0xf8));

  if (lVar4 != 0) {

    FUN_00350040(*(u32 *)((int)lVar4 + 0x104),auStack_4);

    iVar7 = *(int *)(iVar1 + 0x9c);

    uVar2 = (u8)(iVar7 >> 1);

    if (iVar7 < 0) {

      uVar2 = (u8)(iVar7 + 1 >> 1);

    }

    uStack_8 = CONCAT13(uVar2,(*(u32 *)auStack_4 & 0xffffff));

    FUN_0034ff90(*(u32 *)((int)lVar4 + 0x104),&uStack_8);

  }

  FUN_0039f410(iVar5);

  FUN_0039f410(iVar1 + 0x3c);

  return 0;

}
#define FUN_003a0e90(...) ((u32 (*)(...))FUN_003a0e90)(__VA_ARGS__)
#undef FUN_003a1c00
// FUN_003A1C00 NONMATCHING


u32 FUN_003a1c00(u64 param_1)



{

  int *piVar1;

  char cVar2;

  u16 uVar3;

  int iVar4;

  u32 uVar5;

  long lVar6;

  u64 uVar7;

  int *piVar8;

  u8 auStack_4 [4];

  

  piVar1 = *(int **)((int)param_1 + 0x3c);

  piVar8 = piVar1 + 7;

  iVar4 = *piVar1;

  if (iVar4 == 4) {

    uVar5 = 0xffffffff;

  }

  else {

    if (iVar4 == 3) {

      lVar6 = FUN_00195460(piVar1[0x24]);

      if (lVar6 == 0) {

        *piVar1 = 4;

      }

    }

    else if (iVar4 == 2) {

      iVar4 = FUN_00194b20(param_1,&gp0xffffa7b8,0x10,0x3a0e90,0,piVar1);

      FUN_0039f950(piVar1);

      piVar1[0x24] = iVar4;

      *piVar1 = 3;

    }

    else if (iVar4 == 1) {

      lVar6 = FUN_001016b0(piVar1[4]);

      if (lVar6 == 1) {

        uVar7 = FUN_001021c0(0x6a1960,auStack_4);

        piVar1[0x17] = (int)uVar7;

        FUN_0039ec70(piVar8,uVar7);

        uVar3 = FUN_001099a0();

        *(u16 *)(piVar1 + 0x38) = uVar3;

        FUN_0039efd0(piVar8,0,(short)piVar1[1]);

        FUN_0039ef70(piVar8,2,(short)piVar1[1]);

        cVar2 = FUN_0016dba0((short)piVar1[1]);

        if ('\x01' < cVar2) {

          FUN_0039f120(piVar8,3,(short)piVar1[1],cVar2 + -1);

        }

        if ('\0' < cVar2) {

          FUN_0039f120(piVar8,4,(short)piVar1[1],cVar2);

        }

        FUN_0039eef0(piVar8,5,cVar2);

        uVar7 = FUN_001021c0(0x6a1980,auStack_4);

        FUN_0039ed20(piVar1 + 0xf,uVar7);

        FUN_0039efd0(piVar1 + 0xf,0,(short)piVar1[1]);

        FUN_0039f190(piVar1 + 0xf,1,(short)piVar1[1]);

        iVar4 = FUN_001021c0(0x6a19a0,auStack_4);

        piVar1[0x1d] = iVar4;

        iVar4 = FUN_001021c0(0x6a19c0,auStack_4);

        piVar1[0x1e] = iVar4;

        iVar4 = FUN_001021c0(0x6a19a0,auStack_4);

        piVar1[0x1f] = iVar4;

        iVar4 = FUN_001021c0(0x6a19e0,auStack_4);

        piVar1[0x20] = iVar4;

        iVar4 = FUN_001021c0(0x6a1a00,auStack_4);

        piVar1[0x21] = iVar4;

        iVar4 = FUN_001021c0(0x6a1a20,auStack_4);

        piVar1[0x22] = iVar4;

        iVar4 = FUN_001021c0(0x6a1a40,auStack_4);

        piVar1[0x23] = iVar4;

        for (iVar4 = 0; iVar4 < 7; iVar4 = iVar4 + 1) {

          *(u16 *)((int)piVar1 + iVar4 * 2 + 0xec) = 0;

        }

        *piVar1 = 2;

      }

    }

    else if (iVar4 == 0) {

      iVar4 = FUN_00100d80(0x6a1940);

      piVar1[4] = iVar4;

      *piVar1 = 1;

    }

    uVar5 = 0;

  }

  return uVar5;

}
#define FUN_003a1c00(...) ((u32 (*)(...))FUN_003a1c00)(__VA_ARGS__)
#undef FUN_003a1f30
// FUN_003A1F30 NONMATCHING


void FUN_003a1f30(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  for (iVar2 = 0; iVar2 < *(int *)(iVar1 + 0x70); iVar2 = iVar2 + 1) {

    if (*(int *)(iVar1 + iVar2 * 4 + 0x68) != 0) {

      FUN_004d0f00();

    }

  }

  for (iVar2 = 0; iVar2 < 7; iVar2 = iVar2 + 1) {

    if (*(short *)(iVar1 + iVar2 * 2 + 0xec) != 0) {

      FUN_003b7090();

    }

  }

  if (*(int *)(iVar1 + 0x10) != 0) {

    FUN_00100ec0();

    *(u32 *)(iVar1 + 0x10) = 0;

  }

  if (*(int *)(iVar1 + 0x14) != 0) {

    if (*(int *)(iVar1 + 0x60) != 0) {

      FUN_00133d30();

    }

    FUN_00100ec0(*(u32 *)(iVar1 + 0x14));

    *(u32 *)(iVar1 + 0x14) = 0;

  }

  if (*(int *)(iVar1 + 0x18) != 0) {

    if (*(int *)(iVar1 + 100) != 0) {

      FUN_00133d30();

    }

    FUN_00100ec0(*(u32 *)(iVar1 + 0x18));

    *(u32 *)(iVar1 + 0x18) = 0;

  }

  FUN_0039ee80(iVar1 + 0x1c);

  FUN_0039ee80(iVar1 + 0x3c);

  if (*(int *)(iVar1 + 0xe8) != 0) {

    (*DAT_0096017c)();

  }

  (*DAT_0096017c)(iVar1);

  return;

}
#define FUN_003a1f30(...) ((void (*)(...))FUN_003a1f30)(__VA_ARGS__)
#undef FUN_003a2090
// FUN_003A2090 NONMATCHING


void FUN_003a2090(u64 param_1,u16 param_2,u32 param_3,u16 param_4)



{

  u64 uVar1;

  int iVar2;

  

  uVar1 = (*DAT_00960178)(0xfc,0x40000);

  FUN_00521408(uVar1,0,0xfc);

  iVar2 = (int)uVar1;

  *(u16 *)(iVar2 + 4) = param_2;

  *(u32 *)(iVar2 + 8) = param_3;

  *(u16 *)(iVar2 + 0xc) = param_4;

  FUN_00194b20(param_1,0x6a1a58,0x10,0x3a1c00,0x3a1f30,uVar1);

  return;

}
#define FUN_003a2090(...) ((void (*)(...))FUN_003a2090)(__VA_ARGS__)
