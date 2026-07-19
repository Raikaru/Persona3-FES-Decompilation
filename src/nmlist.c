#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern code DAT_00960178;
extern code DAT_0096017c;
extern u8 LAB_003c4400[];
extern u8 LAB_003c4410[];
extern u8 LAB_003c4420[];
extern u8 LAB_003c5210[];

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
long FUN_003c4430(long param_1);
long FUN_003c44d0(long param_1,long param_2,long param_3,long param_4);
void FUN_003c45f0(long param_1);
long FUN_003c4650(u64 param_1,long param_2,long param_3);
void FUN_003c4710(long param_1,long param_2,long param_3);
int FUN_003c4820(long param_1,int param_2);
long FUN_003c4910(long param_1,long param_2,u64 param_3);
u64 FUN_003c49e0(u64 param_1,u64 param_2,int param_3);
void FUN_003c4a90(long param_1,long param_2);
int * FUN_003c4b50(long param_1,long param_2,int param_3);
int FUN_003c4bf0(long param_1,long param_2,int param_3);
u32 FUN_003c4c80(long param_1,long param_2);
u32 FUN_003c4d20(long param_1,long param_2);
void FUN_003c4dc0(u64 param_1,u32 param_2);
u64 FUN_003c4de0(u64 param_1,int param_2,u32 param_3);
int FUN_003c4df0(u64 param_1,int *param_2,int param_3);
u32 FUN_003c4e50(u64 param_1, u32* param_2);
u32 FUN_003c4e60(u64 param_1, int param_2);
u64 FUN_003c4e70(u64 param_1);
void FUN_003c4f30(long param_1);
int FUN_003c4f80(int param_1);
void FUN_003c4fc0(u64 param_1,u64 param_2);
int FUN_003c50b0(int param_1,long param_2,int param_3);
void FUN_003c5180(long param_1,long param_2);
void FUN_003c5220(void);

/* Region call-cast macros */
#define FUN_003c4430(...) ((long (*)(...))FUN_003c4430)(__VA_ARGS__)
#define FUN_003c44d0(...) ((long (*)(...))FUN_003c44d0)(__VA_ARGS__)
#define FUN_003c45f0(...) ((void (*)(...))FUN_003c45f0)(__VA_ARGS__)
#define FUN_003c4650(...) ((long (*)(...))FUN_003c4650)(__VA_ARGS__)
#define FUN_003c4710(...) ((void (*)(...))FUN_003c4710)(__VA_ARGS__)
#define FUN_003c4820(...) ((int (*)(...))FUN_003c4820)(__VA_ARGS__)
#define FUN_003c4910(...) ((long (*)(...))FUN_003c4910)(__VA_ARGS__)
#define FUN_003c49e0(...) ((u64 (*)(...))FUN_003c49e0)(__VA_ARGS__)
#define FUN_003c4a90(...) ((void (*)(...))FUN_003c4a90)(__VA_ARGS__)
#define FUN_003c4b50(...) ((int * (*)(...))FUN_003c4b50)(__VA_ARGS__)
#define FUN_003c4bf0(...) ((int (*)(...))FUN_003c4bf0)(__VA_ARGS__)
#define FUN_003c4c80(...) ((u32 (*)(...))FUN_003c4c80)(__VA_ARGS__)
#define FUN_003c4d20(...) ((u32 (*)(...))FUN_003c4d20)(__VA_ARGS__)
#define FUN_003c4dc0(...) ((void (*)(...))FUN_003c4dc0)(__VA_ARGS__)
#define FUN_003c4de0(...) ((u64 (*)(...))FUN_003c4de0)(__VA_ARGS__)
#define FUN_003c4df0(...) ((int (*)(...))FUN_003c4df0)(__VA_ARGS__)
#define FUN_003c4e50(...) ((u32 (*)(...))FUN_003c4e50)(__VA_ARGS__)
#define FUN_003c4e60(...) ((u32 (*)(...))FUN_003c4e60)(__VA_ARGS__)
#define FUN_003c4e70(...) ((u64 (*)(...))FUN_003c4e70)(__VA_ARGS__)
#define FUN_003c4f30(...) ((void (*)(...))FUN_003c4f30)(__VA_ARGS__)
#define FUN_003c4f80(...) ((int (*)(...))FUN_003c4f80)(__VA_ARGS__)
#define FUN_003c4fc0(...) ((void (*)(...))FUN_003c4fc0)(__VA_ARGS__)
#define FUN_003c50b0(...) ((int (*)(...))FUN_003c50b0)(__VA_ARGS__)
#define FUN_003c5180(...) ((void (*)(...))FUN_003c5180)(__VA_ARGS__)
#define FUN_003c5220(...) ((void (*)(...))FUN_003c5220)(__VA_ARGS__)

#undef FUN_003c4430
// FUN_003C4430 NONMATCHING


long FUN_003c4430(long param_1)



{

  long lVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = (int)param_1 + 0x18;

  lVar1 = (*DAT_00960178)(iVar3,0x40000);

  if (lVar1 == 0) {

    FUN_0019d3f0("nmlist.c",0x60);

  }

  FUN_00521408(lVar1,0,iVar3);

  iVar2 = (int)lVar1;

  if (param_1 != 0) {

    *(int *)(iVar2 + 0x14) = iVar2 + 0x18;

  }

  *(int *)(iVar2 + 8) = iVar3;

  return lVar1;

}
#define FUN_003c4430(...) ((long (*)(...))FUN_003c4430)(__VA_ARGS__)
#undef FUN_003c44d0
// FUN_003C44D0 NONMATCHING


long FUN_003c44d0(long param_1,long param_2,long param_3,long param_4)



{

  long lVar1;

  int iVar2;

  

  iVar2 = (int)param_1 + 0x28;

  lVar1 = (*DAT_00960178)(iVar2,0x40000);

  if (lVar1 == 0) {

    FUN_0019d3f0("nmlist.c",0x37);

  }

  FUN_00521408(lVar1,0,iVar2);

  iVar2 = (int)lVar1;

  if (param_1 != 0) {

    *(int *)(iVar2 + 0x24) = iVar2 + 0x28;

  }

  *(int *)(iVar2 + 0x20) = (int)param_1;

  if (param_2 == 0) {

    *(u8 **)(iVar2 + 0x14) = (u8 *)&LAB_003c4400;

  }

  else {

    *(int *)(iVar2 + 0x14) = (int)param_2;

  }

  if (param_3 == 0) {

    *(u8 **)(iVar2 + 0x18) = (u8 *)&LAB_003c4410;

  }

  else {

    *(int *)(iVar2 + 0x18) = (int)param_3;

  }

  if (param_4 == 0) {

    *(u8 **)(iVar2 + 0x1c) = (u8 *)&LAB_003c4420;

  }

  else {

    *(int *)(iVar2 + 0x1c) = (int)param_4;

  }

  return lVar1;

}
#define FUN_003c44d0(...) ((long (*)(...))FUN_003c44d0)(__VA_ARGS__)
#undef FUN_003c45f0
// FUN_003C45F0 NONMATCHING


void FUN_003c45f0(long param_1)



{

  FUN_003c4a90(param_1,(int)param_1 + 4);

  if (param_1 != 0) {

    FUN_00521408(param_1,0,*(u32 *)((int)param_1 + 0x20));

    (*DAT_0096017c)(param_1);

  }

  return;

}
#define FUN_003c45f0(...) ((void (*)(...))FUN_003c45f0)(__VA_ARGS__)
#undef FUN_003c4650
// FUN_003C4650 NONMATCHING


long FUN_003c4650(u64 param_1,long param_2,long param_3)



{

  long lVar1;

  u32 *puVar2;

  int iVar3;

  

  iVar3 = (int)param_3 + 0x18;

  lVar1 = (*DAT_00960178)(iVar3,0x40000);

  if (lVar1 == 0) {

    FUN_0019d3f0("nmlist.c",0x60);

  }

  FUN_00521408(lVar1,0,iVar3);

  puVar2 = (u32 *)lVar1;

  if (param_3 != 0) {

      puVar2[5] = (u32)(puVar2 + 6);

  }

  puVar2[2] = iVar3;

  if (param_2 == 0) {

      *puVar2 = (u32)puVar2;

  }

  else {

    *puVar2 = (int)param_2;

  }

  return lVar1;

}
#define FUN_003c4650(...) ((long (*)(...))FUN_003c4650)(__VA_ARGS__)
#undef FUN_003c4710
// FUN_003C4710 NONMATCHING


void FUN_003c4710(long param_1,long param_2,long param_3)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  

  if (param_1 == 0) {

    FUN_0019d3f0("nmlist.c",0x115);

  }

  piVar3 = (int *)param_1;

  *(short *)(piVar3 + 3) = (short)piVar3[3] + 1;

  if (param_3 != 0) {

    iVar1 = (int)param_3;

    *(u32 *)(iVar1 + 0x10) = 0;

    *(u32 *)(iVar1 + 0xc) = 0;

    if (param_2 == 0) {

      if (*piVar3 != 0) {

        *(u32 *)(iVar1 + 0xc) = 0;

        *(int *)(iVar1 + 0x10) = *piVar3;

        *(int *)(*piVar3 + 0xc) = iVar1;

      }

      *piVar3 = iVar1;

      if (piVar3[1] == 0) {

        piVar3[1] = iVar1;

      }

    }

    else {

      iVar2 = (int)param_2;

      if (*(int *)(iVar2 + 0x10) == 0) {

        *(int *)(iVar1 + 0xc) = iVar2;

        *(u32 *)(iVar1 + 0x10) = 0;

        *(int *)(iVar2 + 0x10) = iVar1;

        piVar3[1] = iVar1;

      }

      else {

        *(int *)(iVar1 + 0xc) = iVar2;

        *(u32 *)(iVar1 + 0x10) = *(u32 *)(iVar2 + 0x10);

        *(int *)(iVar2 + 0x10) = iVar1;

        *(int *)(*(int *)(iVar1 + 0x10) + 0xc) = iVar1;

      }

    }

    if (piVar3[2] == 0) {

      piVar3[2] = iVar1;

    }

  }

  return;

}
#define FUN_003c4710(...) ((void (*)(...))FUN_003c4710)(__VA_ARGS__)
#undef FUN_003c4820
// FUN_003C4820 NONMATCHING


int FUN_003c4820(long param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  

  if (param_1 == 0) {

    FUN_0019d3f0("nmlist.c",0x149);

  }

  if (param_2 == 0) {

    FUN_0019d3f0("nmlist.c",0x14a);

  }

  piVar3 = (int *)param_1;

  *(short *)(piVar3 + 3) = (short)piVar3[3] + -1;

  iVar2 = *(int *)(param_2 + 0xc);

  if (iVar2 == 0) {

    iVar2 = *(int *)(param_2 + 0x10);

    if (iVar2 == 0) {

      if (*piVar3 == param_2) {

        piVar3[1] = 0;

        *piVar3 = 0;

      }

      iVar2 = 0;

    }

    else {

      *(u32 *)(iVar2 + 0xc) = 0;

      *piVar3 = iVar2;

    }

  }

  else {

    iVar1 = *(int *)(param_2 + 0x10);

    if (iVar1 == 0) {

      *(u32 *)(iVar2 + 0x10) = 0;

      piVar3[1] = iVar2;

    }

    else {

      *(int *)(iVar2 + 0x10) = iVar1;

      *(int *)(iVar1 + 0xc) = iVar2;

      iVar2 = *(int *)(iVar2 + 0x10);

    }

  }

  *(u32 *)(param_2 + 0xc) = 0;

  *(u32 *)(param_2 + 0x10) = 0;

  return iVar2;

}
#define FUN_003c4820(...) ((int (*)(...))FUN_003c4820)(__VA_ARGS__)
#undef FUN_003c4910
// FUN_003C4910 NONMATCHING


long FUN_003c4910(long param_1,long param_2,u64 param_3)



{

  long lVar1;

  u32 *puVar2;

  int iVar3;

  

  if (param_1 == 0) {

    FUN_0019d3f0("nmlist.c",0x17d);

  }

  lVar1 = FUN_003c4430(param_3);

  puVar2 = (u32 *)lVar1;

  if (param_2 == 0) {

      *puVar2 = (u32)puVar2;

  }

  else {

    *puVar2 = (int)param_2;

  }

  if (lVar1 == 0) {

    FUN_0019d3f0("nmlist.c",0x180);

  }

  iVar3 = (int)param_1;

  FUN_003c4710(iVar3 + 4,*(u32 *)(iVar3 + 8),lVar1);

  (**(code **)(iVar3 + 0x14))(param_1,lVar1);

  return lVar1;

}
#define FUN_003c4910(...) ((long (*)(...))FUN_003c4910)(__VA_ARGS__)
#undef FUN_003c49e0
// FUN_003C49E0 NONMATCHING


u64 FUN_003c49e0(u64 param_1,u64 param_2,int param_3)



{

  u64 uVar1;

  

  uVar1 = FUN_003c4820(param_2,param_3);

  if (param_3 == *(int *)((int)param_2 + 8)) {

    *(int *)((int)param_2 + 8) = (int)uVar1;

  }

  (**(code **)((int)param_1 + 0x18))(param_1,param_3);

  if (param_3 != 0) {

    FUN_00521408(param_3,0,*(u32 *)(param_3 + 8));

    (*DAT_0096017c)(param_3);

  }

  return uVar1;

}
#define FUN_003c49e0(...) ((u64 (*)(...))FUN_003c49e0)(__VA_ARGS__)
#undef FUN_003c4a90
// FUN_003C4A90 NONMATCHING


void FUN_003c4a90(long param_1,long param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  

  if ((param_1 != 0) && (param_2 != 0)) {

    piVar3 = (int *)param_2;

    iVar1 = *piVar3;

    while (iVar2 = iVar1, iVar2 != 0) {

      iVar1 = *(int *)(iVar2 + 0x10);

      (**(code **)((int)param_1 + 0x18))(param_1,iVar2);

      if (iVar2 != 0) {

        FUN_00521408(iVar2,0,*(u32 *)(iVar2 + 8));

        (*DAT_0096017c)(iVar2);

      }

    }

    *(u16 *)(piVar3 + 3) = 0;

    piVar3[2] = 0;

    piVar3[1] = 0;

    *piVar3 = 0;

  }

  return;

}
#define FUN_003c4a90(...) ((void (*)(...))FUN_003c4a90)(__VA_ARGS__)
#undef FUN_003c4b50
// FUN_003C4B50 NONMATCHING


int * FUN_003c4b50(long param_1,long param_2,int param_3)



{

  int *piVar1;

  

  if (param_1 == 0) {

    FUN_0019d3f0("nmlist.c",0x1c7);

  }

  if (param_2 == 0) {

    FUN_0019d3f0("nmlist.c",0x1c8);

  }

  piVar1 = (int *)*(u32 *)param_2;

  while( 1 ) {

    if (piVar1 == (int *)0x0) {

      return (int *)0x0;

    }

    if (*piVar1 == param_3) break;

    piVar1 = (int *)piVar1[4];

  }

  return piVar1;

}
#define FUN_003c4b50(...) ((int * (*)(...))FUN_003c4b50)(__VA_ARGS__)
#undef FUN_003c4bf0
// FUN_003C4BF0 NONMATCHING


int FUN_003c4bf0(long param_1,long param_2,int param_3)



{

  int iVar1;

  

  if ((param_1 == 0) || (param_2 == 0)) {

    FUN_0019d3f0("nmlist.c",0x1f7);

  }

  iVar1 = *(int *)param_2;

  while( 1 ) {

    if (iVar1 == 0) {

      return 0;

    }

    if (*(int *)(iVar1 + 4) == param_3) break;

    iVar1 = *(int *)(iVar1 + 0x10);

  }

  return iVar1;

}
#define FUN_003c4bf0(...) ((int (*)(...))FUN_003c4bf0)(__VA_ARGS__)
#undef FUN_003c4c80
// FUN_003C4C80 NONMATCHING


u32 FUN_003c4c80(long param_1,long param_2)



{

  int iVar1;

  u32 uVar2;

  u32 *puVar3;

  

  puVar3 = (u32 *)param_2;

  if (param_1 == 0) {

    uVar2 = 0;

  }

  else if (param_2 == 0) {

    uVar2 = 0;

  }

  else if (puVar3[2] == 0) {

    uVar2 = 0;

  }

  else {

    iVar1 = *(int *)(puVar3[2] + 0x10);

    if (iVar1 == 0) {

      if ((*(u16 *)((int)puVar3 + 0xe) & 2) != 0) {

        return 0;

      }

      puVar3[2] = *puVar3;

    }

    else {

      puVar3[2] = iVar1;

    }

    *(u16 *)((int)puVar3 + 0xe) = *(u16 *)((int)puVar3 + 0xe) | 2;

    uVar2 = puVar3[2];

  }

  return uVar2;

}
#define FUN_003c4c80(...) ((u32 (*)(...))FUN_003c4c80)(__VA_ARGS__)
#undef FUN_003c4d20
// FUN_003C4D20 NONMATCHING


u32 FUN_003c4d20(long param_1,long param_2)



{

  int iVar1;

  u32 uVar2;

  int iVar3;

  

  iVar3 = (int)param_2;

  if (param_1 == 0) {

    uVar2 = 0;

  }

  else if (param_2 == 0) {

    uVar2 = 0;

  }

  else if (*(int *)(iVar3 + 8) == 0) {

    uVar2 = 0;

  }

  else {

    iVar1 = *(int *)(*(int *)(iVar3 + 8) + 0xc);

    if (iVar1 == 0) {

      if ((*(u16 *)(iVar3 + 0xe) & 2) != 0) {

        return 0;

      }

      *(u32 *)(iVar3 + 8) = *(u32 *)(iVar3 + 4);

    }

    else {

      *(int *)(iVar3 + 8) = iVar1;

    }

    *(u16 *)(iVar3 + 0xe) = *(u16 *)(iVar3 + 0xe) | 2;

    uVar2 = *(u32 *)(iVar3 + 8);

  }

  return uVar2;

}
#define FUN_003c4d20(...) ((u32 (*)(...))FUN_003c4d20)(__VA_ARGS__)
#undef FUN_003c4dc0
// FUN_003C4DC0


void FUN_003c4dc0(u64 param_1,u32 param_2)



{

  if (param_2 != 0) {

    *(s16 *)(param_2 + 0xe) = *(s16 *)(param_2 + 0xe) & -3;

  }

  return;

}
#define FUN_003c4dc0(...) ((void (*)(...))FUN_003c4dc0)(__VA_ARGS__)
#undef FUN_003c4de0
// FUN_003C4DE0


u64 FUN_003c4de0(u64 param_1,int param_2,u32 param_3)



{

  *(u32 *)(param_2 + 8) = param_3;

  return 0;

}
#define FUN_003c4de0(...) ((u64 (*)(...))FUN_003c4de0)(__VA_ARGS__)
#undef FUN_003c4df0
// FUN_003C4DF0


int FUN_003c4df0(u64 param_1,int *param_2,int param_3)
{
  int node;
  int index;

  index = 0;
  if (param_3 == -1) {
    return param_2[1];
  }

  node = *param_2;
  while (node != 0) {
    if (index == param_3) {
      param_2[2] = node;
      return node;
    }
    node = *(int *)(node + 0x10);
    index++;
  }
  return 0;
}
#define FUN_003c4df0(...) ((int (*)(...))FUN_003c4df0)(__VA_ARGS__)
#undef FUN_003c4e50
// FUN_003C4E50


u32 FUN_003c4e50(u64 param_1, u32* param_2)
{
    return param_2[2] = param_2[0];
}
#define FUN_003c4e50(...) ((u32 (*)(...))FUN_003c4e50)(__VA_ARGS__)
#undef FUN_003c4e60
// FUN_003C4E60


u32 FUN_003c4e60(u64 param_1, int param_2)
{
    return *(u32*)(param_2 + 8) = *(u32*)(param_2 + 4);
}
#define FUN_003c4e60(...) ((u32 (*)(...))FUN_003c4e60)(__VA_ARGS__)
#undef FUN_003c4e70
// FUN_003C4E70 NONMATCHING


u64 FUN_003c4e70(u64 param_1)



{

  int iVar1;

  long lVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = (int)param_1;

  iVar4 = *(int *)(iVar3 + 4);

  while (iVar4 != 0) {

    lVar2 = (**(code **)(iVar3 + 0x1c))(param_1,iVar4);

    if (lVar2 == 0) {

      iVar4 = *(int *)(iVar4 + 0x10);

    }

    else {

      iVar1 = FUN_003c4820(iVar3 + 4,iVar4);

      if (iVar4 == *(int *)(iVar3 + 0xc)) {

        *(int *)(iVar3 + 0xc) = iVar1;

      }

      (**(code **)(iVar3 + 0x18))(param_1,iVar4);

      FUN_003c4f30(iVar4);

      iVar4 = iVar1;

    }

  }

  return 0;

}
#define FUN_003c4e70(...) ((u64 (*)(...))FUN_003c4e70)(__VA_ARGS__)
#undef FUN_003c4f30
// FUN_003C4F30 NONMATCHING


void FUN_003c4f30(long param_1)



{

  if (param_1 != 0) {

    FUN_00521408(param_1,0,*(u32 *)((int)param_1 + 8));

    (*DAT_0096017c)(param_1);

  }

  return;

}
#define FUN_003c4f30(...) ((void (*)(...))FUN_003c4f30)(__VA_ARGS__)
#undef FUN_003c4f80
// FUN_003C4F80 NONMATCHING


int FUN_003c4f80(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = 0;

  for (iVar2 = 0; *(char *)(param_1 + iVar2) != '\0'; iVar2 = iVar2 + 1) {

    iVar1 = iVar1 + *(char *)(param_1 + iVar2);

  }

  return iVar1;

}
#define FUN_003c4f80(...) ((int (*)(...))FUN_003c4f80)(__VA_ARGS__)
#undef FUN_003c4fc0
// FUN_003C4FC0 NONMATCHING


void FUN_003c4fc0(u64 param_1,u64 param_2)



{

  u64 uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = 0;

  iVar2 = (int)param_1;

  iVar4 = *(int *)(iVar2 + 4);

  if (iVar4 != 0) {

    uVar1 = (*DAT_00960178)((u32)*(u16 *)(iVar2 + 0x10) << 2,0x40000);

    for (; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {

      *(int *)((int)uVar1 + iVar3 * 4) = iVar4;

      iVar3 = iVar3 + 1;

    }

    FUN_005225f8(uVar1,iVar3,4,param_2);

    FUN_003c50b0(param_1,uVar1,iVar3);

    *(u32 *)(iVar2 + 0xc) = *(u32 *)(iVar2 + 4);

    (*DAT_0096017c)(uVar1);

  }

  return;

}
#define FUN_003c4fc0(...) ((void (*)(...))FUN_003c4fc0)(__VA_ARGS__)
#undef FUN_003c50b0
// FUN_003C50B0 NONMATCHING


int FUN_003c50b0(int param_1,long param_2,int param_3)



{

  int iVar1;

  

  if ((param_2 == 0) || (param_3 == 0)) {

    iVar1 = 0;

  }

  else {

    if (param_1 + 4 != 0) {

      FUN_00521408(param_1 + 4,0,0x10);

    }

    for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {

      FUN_003c4710(param_1 + 4,*(u32 *)(param_1 + 8),

                   *(u32 *)((int)param_2 + iVar1 * 4));

    }

  }

  return iVar1;

}
#define FUN_003c50b0(...) ((int (*)(...))FUN_003c50b0)(__VA_ARGS__)
#undef FUN_003c5180
// FUN_003C5180 NONMATCHING


void FUN_003c5180(long param_1,long param_2)



{

  int iVar1;

  

  iVar1 = FUN_003c44d0((int)param_2 + 0x30,0x3c57e0,0x3c5810,0x3c5840);

  iVar1 = *(int *)(iVar1 + 0x24);

  if (param_1 == 0) {

    *(u8 **)(iVar1 + 8) = (u8 *)&LAB_003c5210;

  }

  else {

    *(int *)(iVar1 + 8) = (int)param_1;

  }

  if (param_2 != 0) {

    *(int *)(iVar1 + 0xc) = iVar1 + 0x30;

  }

  return;

}
#define FUN_003c5180(...) ((void (*)(...))FUN_003c5180)(__VA_ARGS__)
#undef FUN_003c5220
// FUN_003C5220 NONMATCHING


void FUN_003c5220(void)



{

  FUN_003c45f0();

  return;

}
#define FUN_003c5220(...) ((void (*)(...))FUN_003c5220)(__VA_ARGS__)
