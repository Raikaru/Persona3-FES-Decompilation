#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern float fGpffff808c;
extern float fGpffff80a4;
extern s8 gp0xffffa808;
extern s16 uGpffffa810;
extern u32 uGpffffb948;

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

/* Region 0x390000-0x3CFFFF recovered prototypes */
void FUN_003b2c60(u32 param_1,long param_2);
int FUN_003b2cb0(float param_1,int param_2,int param_3,u32 param_4,u32 param_5,u32 param_6,u32 param_7,u32 param_8,u32 param_9);
int FUN_003b2f90(float param_1,int param_2,int param_3,u32 param_4,u32 param_5,u32 param_6,u32 param_7,u32 param_8,u32 param_9);
int FUN_003b32d0(float param_1,int param_2,int param_3,u32 param_4,u32 param_5,u32 param_6,u32 param_7,u32 param_8,u32 param_9);
s8 FUN_003b35c0(char param_1);

/* Region call-cast macros */
#define FUN_003b2c60(...) ((void (*)(...))FUN_003b2c60)(__VA_ARGS__)
#define FUN_003b2cb0(...) ((int (*)(...))FUN_003b2cb0)(__VA_ARGS__)
#define FUN_003b2f90(...) ((int (*)(...))FUN_003b2f90)(__VA_ARGS__)
#define FUN_003b32d0(...) ((int (*)(...))FUN_003b32d0)(__VA_ARGS__)
#define FUN_003b35c0(...) ((s8 (*)(...))FUN_003b35c0)(__VA_ARGS__)

#undef FUN_003b2c60
// FUN_003B2C60 NONMATCHING


void FUN_003b2c60(u32 param_1,long param_2)



{

  if (param_2 == 0) {

    FUN_0019d3f0("frFontEx.c",0x13);

  }

  *(u32 *)((int)param_2 + 0x14) = param_1;

  return;

}
#define FUN_003b2c60(...) ((void (*)(...))FUN_003b2c60)(__VA_ARGS__)
#undef FUN_003b2cb0
// FUN_003B2CB0 NONMATCHING






int FUN_003b2cb0(float param_1,int param_2,int param_3,u32 param_4,u32 param_5,

                u32 param_6,u32 param_7,u32 param_8,u32 param_9)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  iVar5 = 0;

  if ((char)param_5 == '\n') {

    param_5 = 5;

    param_4 = param_4 & 0xffffff00 | (int)(fGpffff80a4 * (float)(param_4 & 0xff));

  }


  uGpffffa810 = (uGpffffa810 | 1) & 0xfffd;
  iVar2 = FUN_003b0970(param_7,param_6,param_5,0,0);

  uGpffffa810 = (uGpffffa810 | 2) & 0xfffe;

  if ((param_8 & 0xb) != 0) {
    iVar5 = 0;

    for (iVar3 = *(int *)(iVar2 + 0x1c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x28)) {

      iVar5 = iVar5 + *(int *)(iVar3 + 0xc) + (int)*(char *)(iVar2 + 3);

    }

  }

  if ((param_8 & 8) == 0) {

    if ((param_8 & 2) != 0) {

      param_2 = param_2 - iVar5;

    }

  }

  else {

    param_2 = param_2 - (iVar5 >> 1);

  }

  if ((param_8 & 4) == 0) {

    if ((param_8 & 0x10) != 0) {

      iVar3 = FUN_003b35c0(param_6);

      param_3 = (int)(((float)param_3 + 0.0) - fGpffff808c * (float)iVar3);

    }

  }

  else {

    iVar3 = FUN_003b35c0(param_6);

    param_3 = param_3 - iVar3;

  }

  if (iVar2 == 0) {

    FUN_0019d3f0("frFont.c",0x88c);

  }

  *(int *)(iVar2 + 4) = param_2 << 4;

  *(int *)(iVar2 + 8) = param_3 << 3;

  if (iVar2 == 0) {

    FUN_0019d3f0("frFontEx.c",0x13);

  }

  *(float *)(iVar2 + 0x14) = param_1;

  for (iVar3 = iVar2; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x24)) {

    for (iVar4 = *(int *)(iVar3 + 0x1c); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x28)) {

      *(u32 *)(iVar4 + 0x10) = param_4;

    }

  }

  FUN_003b1360(iVar2,1,0);

  cVar1 = FUN_003b0ec0(iVar2);

  if (cVar1 == '\0') {

    FUN_003b0030(iVar2);

  }

  return iVar5;

}
#define FUN_003b2cb0(...) ((int (*)(...))FUN_003b2cb0)(__VA_ARGS__)
#undef FUN_003b2f90
// FUN_003B2F90 NONMATCHING






int FUN_003b2f90(float param_1,int param_2,int param_3,u32 param_4,u32 param_5,

                u32 param_6,u32 param_7,u32 param_8,u32 param_9)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  iVar5 = 0;

  if ((char)param_5 == '\n') {

    param_5 = 5;

    param_4 = param_4 & 0xffffff00 | (int)(fGpffff80a4 * (float)(param_4 & 0xff));

  }

  uGpffffa810 = (uGpffffa810 | 1) & 0xfffd;

  iVar2 = FUN_003b0970(param_7,param_6,param_5,0,0);
  if (iVar2 == 0) {

    FUN_0019d3f0("frFont.c",0x848);

  }

  *(u8 *)(iVar2 + 3) = param_9;

  iVar4 = 0;

  for (iVar3 = *(int *)(iVar2 + 0x1c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x28)) {

    iVar4 = iVar4 + *(int *)(iVar3 + 0xc) + (int)*(char *)(iVar2 + 3);

  }

  *(int *)(iVar2 + 0xc) = iVar4;

  uGpffffa810 = (uGpffffa810 | 2) & 0xfffe;

  if ((param_8 & 0xb) != 0) {

    iVar5 = 0;
    for (iVar3 = *(int *)(iVar2 + 0x1c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x28)) {


      iVar5 = iVar5 + *(int *)(iVar3 + 0xc) + (int)*(char *)(iVar2 + 3);

    }

  }

  if ((param_8 & 8) == 0) {

    if ((param_8 & 2) != 0) {

      param_2 = param_2 - iVar5;

    }

  }

  else {

    param_2 = param_2 - (iVar5 >> 1);

  }

  if ((param_8 & 4) == 0) {

    if ((param_8 & 0x10) != 0) {

      iVar3 = FUN_003b35c0(param_6);

      param_3 = (int)(((float)param_3 + 0.0) - fGpffff808c * (float)iVar3);

    }

  }

  else {

    iVar3 = FUN_003b35c0(param_6);

    param_3 = param_3 - iVar3;

  }

  if (iVar2 == 0) {

    FUN_0019d3f0("frFont.c",0x88c);

  }

  *(int *)(iVar2 + 4) = param_2 << 4;

  *(int *)(iVar2 + 8) = param_3 << 3;

  if (iVar2 == 0) {

    FUN_0019d3f0("frFontEx.c",0x13);

  }

  *(float *)(iVar2 + 0x14) = param_1;

  for (iVar3 = iVar2; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x24)) {

    for (iVar4 = *(int *)(iVar3 + 0x1c); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x28)) {

      *(u32 *)(iVar4 + 0x10) = param_4;

    }

  }

  FUN_003b1360(iVar2,1,0);

  cVar1 = FUN_003b0ec0(iVar2);

  if (cVar1 == '\0') {

    FUN_003b0030(iVar2);

  }

  return iVar5;

}
#define FUN_003b2f90(...) ((int (*)(...))FUN_003b2f90)(__VA_ARGS__)
#undef FUN_003b32d0
// FUN_003B32D0 NONMATCHING






int FUN_003b32d0(float param_1,int param_2,int param_3,u32 param_4,u32 param_5,

                u32 param_6,u32 param_7,u32 param_8,u32 param_9)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  iVar5 = 0;

  if ((char)param_5 == '\n') {

    param_5 = 5;

    param_4 = param_4 & 0xffffff00 | (int)(fGpffff80a4 * (float)(param_4 & 0xff));

  }

  uGpffffa810 = (uGpffffa810 | 1) & 0xfffd;

  uGpffffb948 = param_9;

  iVar2 = FUN_003b0970(param_7,param_6,param_5,0,0);

  uGpffffb948 = 0;

  uGpffffa810 = (uGpffffa810 | 2) & 0xfffe;

  if ((param_8 & 0xb) != 0) {

    iVar5 = 0;

    for (iVar3 = *(int *)(iVar2 + 0x1c); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x28)) {

      iVar5 = iVar5 + *(int *)(iVar3 + 0xc) + (int)*(char *)(iVar2 + 3);

    }

  }

  if ((param_8 & 8) == 0) {

    if ((param_8 & 2) != 0) {

      param_2 = param_2 - iVar5;

    }

  }
  else {

    param_2 = param_2 - (iVar5 >> 1);

  }

  if ((param_8 & 4) == 0) {

    if ((param_8 & 0x10) != 0) {


      param_3 = (int)(((float)param_3 + 0.0) - fGpffff808c * (float)iVar3);

    }

  }

  else {

    iVar3 = FUN_003b35c0(param_6);

    param_3 = param_3 - iVar3;

  }

  if (iVar2 == 0) {

    FUN_0019d3f0("frFont.c",0x88c);

  }

  *(int *)(iVar2 + 4) = param_2 << 4;

  *(int *)(iVar2 + 8) = param_3 << 3;

  if (iVar2 == 0) {

    FUN_0019d3f0("frFontEx.c",0x13);

  }

  *(float *)(iVar2 + 0x14) = param_1;

  for (iVar3 = iVar2; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x24)) {

    for (iVar4 = *(int *)(iVar3 + 0x1c); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x28)) {

      *(u32 *)(iVar4 + 0x10) = param_4;

    }

  }

  FUN_003b1360(iVar2,1,0);

  cVar1 = FUN_003b0ec0(iVar2);

  if (cVar1 == '\0') {

    FUN_003b0030(iVar2);

  }

  return iVar5;

}
#define FUN_003b32d0(...) ((int (*)(...))FUN_003b32d0)(__VA_ARGS__)
#undef FUN_003b35c0
// FUN_003B35C0


s8 FUN_003b35c0(char param_1)



{

  return (&gp0xffffa808)[param_1];

}
#define FUN_003b35c0(...) ((s8 (*)(...))FUN_003b35c0)(__VA_ARGS__)
