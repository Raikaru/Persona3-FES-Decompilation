#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern void FUN_0019d3f0(const char *file,s32 line);
extern u32 FUN_00171250(s16 id);
extern u32 FUN_00170d60(s16 id);
extern u64 FUN_00171110(s16 id,s16 field);
extern const char DAT_006a1bf8[];
extern u32 DAT_006a1d10;
#pragma alias DAT_006a1d10_abs DAT_006a1d10
extern u32 DAT_006a1d10_abs[];
extern const char DAT_006a1d70[];
extern const char DAT_006a1d50[];
extern const char DAT_006a1d90[];
extern const char DAT_006a1db0[];
extern const char DAT_006a1dd0[];
extern u32 DAT_006a1fdc;
extern u32 DAT_006a1fec;
extern u32 DAT_006a1ffc;
extern u32 DAT_006a200c;
extern s16 DAT_006a2060[];
extern s16 DAT_006a2080[];
extern u32 DAT_006a20a0;
extern u32 DAT_006a20c0;
extern u8 DAT_006a1ee0[];
extern u8 DAT_006a1ef0[];
#pragma alias DAT_006a1ee0_abs DAT_006a1ee0
extern u8 DAT_006a1ee0_abs[];
#pragma alias DAT_006a1ef0_abs DAT_006a1ef0
extern u8 DAT_006a1ef0_abs[];
extern u32 DAT_006a212c;
#pragma alias DAT_006a212c_abs DAT_006a212c
extern u8 DAT_006a212c_abs[];
extern u32 DAT_007cd520;
extern void FUN_006a1e00(void);
extern void FUN_006a1e60(void);
extern void FUN_006a1ea0(void);
extern void FUN_006a1eb0(void);
extern u32 DAT_006a2640;
extern u32 DAT_006a2644;
extern u32 DAT_006a2648;
extern u32 DAT_006a2650;
extern u32 DAT_006a2654;
extern u32 DAT_006a2658;
extern s32 DAT_006a2680[];
extern u32 DAT_007cd4e8;
extern s16 DAT_007cd500;
extern u32 DAT_0095ac70;
#pragma alias DAT_0095ac70_abs DAT_0095ac70
extern u32 DAT_0095ac70_abs[];
extern u32 DAT_00960088;
extern code DAT_00960090;
/* Absolute callback addresses keep the render-state setup in one local pointer. */
#pragma alias DAT_00960090_abs DAT_00960090
extern code DAT_00960090_abs[];
#pragma alias DAT_009600a0_abs DAT_009600a0
extern code DAT_009600a0_abs[];
#pragma alias DAT_00960178_abs DAT_00960178
extern code DAT_00960178_abs[];
#pragma alias DAT_0096017c_abs DAT_0096017c
extern code DAT_0096017c_abs[];
#pragma alias DAT_00960088_abs DAT_00960088
extern u32 DAT_00960088_abs[];
extern code DAT_009600a0;
extern code DAT_00960178;
extern code DAT_0096017c;
extern char gp0xffffa830[];
extern u8 LAB_003a9170[];
extern u8 LAB_003a9230[];
extern u8 LAB_003a92d0[];
extern u8 LAB_003a93a0[];
extern u8 LAB_003a9400[];
extern u8 LAB_003a9470[];
extern u8 LAB_003a9510[];
extern u8 LAB_003a9580[];
extern u32 LAB_003aa508;
extern u32 LAB_006a1de8;
extern u8 * PTR_FUN_006a1c10;
#pragma alias PTR_FUN_006a1c10_abs PTR_FUN_006a1c10
extern code PTR_FUN_006a1c10_abs[];
extern u8 * PTR_FUN_006a1c90;
#pragma alias PTR_FUN_006a1c90_abs PTR_FUN_006a1c90
extern u8 PTR_FUN_006a1c90_abs[];
extern u8 * PTR_LAB_006a1c50;
#pragma alias PTR_LAB_006a1c50_abs PTR_LAB_006a1c50
extern code PTR_LAB_006a1c50_abs[];
extern u8 * PTR_s_Sayonara_006a24d0;
#pragma alias PTR_s_Sayonara_006a24d0_abs PTR_s_Sayonara_006a24d0
extern u8 PTR_s_Sayonara_006a24d0_abs[];
extern f32 fGpffff8110;
extern f32 fGpffff839c;
extern f32 fGpffff845c;
extern u32 uGpffffa7f8;
extern u32 gp0xffffa7d0;
extern u32 gp0xffffa7d4;
extern u32 gp0xffffa7d8;
extern u32 gp0xffffa7dc;
extern u32 gp0xffffa7e0;
extern u32 gp0xffffa7e8;
extern u32 gp0xffffa7f0;
extern u32 gp0xffffb934;
extern u32 gp0xffffb938;
extern u32 gp0xffffb93c;
extern u32 gp0xffffb944;
extern f32 uGpffff8070;
extern f32 uGpffff8458;
extern void FUN_003c9000(float param_1,float param_2,float param_3,int param_4,int param_5,int param_6,int param_7,int param_8);
extern u32 uGpffffb964;

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif

extern void FUN_003bb060(u16 param_1,u16 param_2);
/* Region 0x390000-0x3CFFFF recovered prototypes */
void FUN_003a87d0(float param_1,int param_2,int param_3,long param_4,u32 param_5,u32 param_6,  long param_7);
void FUN_003a8dc0(int param_1,int param_2,int param_3,int param_4,  int param_5,int param_6);
void FUN_003a8d60(int param_1);
void FUN_003a8ea0(long param_1,int param_2,int param_3,int param_4,int param_5,int param_6);
void FUN_003a8fb0(int param_1,int param_2,int param_3,int param_4,  int param_5);
void FUN_003a9080(u64 param_1);
void FUN_003a90c0(int param_1,u64 param_2);
u64 FUN_003a9140(int param_1);
int FUN_003a9230(int param_1);
u64 FUN_003a92a0(int param_1);
int FUN_003a92d0(int param_1);
u64 FUN_003a93a0(int param_1);
u64 FUN_003a9400(int param_1);
u64 FUN_003a9470(int param_1);
u64 FUN_003a94e0(int param_1);
u64 FUN_003a9510(int param_1);
u64 FUN_003a9580(int param_1);
int FUN_003a95f0(int param_1);
int FUN_003a9630(int param_1);
int FUN_003a9670(int param_1);
int FUN_003a96b0(int param_1);
void FUN_003a96f0(int *param_1,int param_2,int param_3,int param_4,int param_5);
void FUN_003a9780(int *param_1,int param_2,int param_3,int param_4,int param_5);
void FUN_003a9930(int *param_1,int param_2,int param_3,int param_4,int param_5);
void FUN_003a9af0(int *param_1,u32 param_2,int param_3,int param_4,u32 param_5);
void FUN_003a9b80(int param_1,u64 param_2,int param_3,u64 param_4,int param_5);
void FUN_003a9c30(int param_1,u32 param_2,u32 param_3,u32 param_4,  u32 param_5);
void FUN_003a9c90(int param_1,u32 param_2,u32 param_3,u32 param_4,  u32 param_5);
void FUN_003a9cf0(int param_1,u64 param_2,u64 param_3,u64 param_4,  u32 param_5);
void FUN_003a9e20(int param_1,u64 param_2);
void FUN_003a9ed0(int param_1,u64 param_2);
void FUN_003aa000(int param_1,u64 param_2);
void FUN_003aa130(int param_1,u64 param_2);
void FUN_003aa280(int param_1,u64 param_2);
void FUN_003aa2d0(int param_1,u64 param_2);
void FUN_003aa370(int param_1,u64 param_2);
void FUN_003aa720(int param_1);
void FUN_003aaae0(int param_1);
void FUN_003ab2a0(int param_1,u32 param_2);
void FUN_003ab320(int param_1);
void FUN_003abb10(int param_1);
void FUN_003ac240(int param_1,u64 param_2);
void FUN_003ac350(int param_1,u64 param_2);
void FUN_003ac500(int param_1,u64 param_2);
void FUN_003b4a90(int *param_1,int param_2,int param_3,int param_4,int param_5,int *param_6,int param_7);
void FUN_003ac590(void);
u64 FUN_003ac5a0(int param_1,int param_2);
u64 FUN_003ac600(int param_1,int param_2);
u64 FUN_003ac820(u64 param_1,u64 param_2);
u64 FUN_003ac890(u64 param_1,u64 param_2);
u64 FUN_003ac900(u64 param_1,int param_2);
u64 FUN_003aca50(u64 param_1,u64 param_2);
u32 FUN_003acab0(u64 param_1,u64 param_2);
u64 FUN_003acbc0(u64 param_1,int param_2);
u64 FUN_003acb10(int param_1,int param_2);
u64 FUN_003acda0(u64 param_1,int param_2);
u64 FUN_003ace60(u64 param_1,int param_2);
u32 FUN_003acf80(u32 param_1,int param_2);
u64 FUN_003ad030(u64 param_1,int param_2);
u64 FUN_003ad1b0(u32 param_1,int param_2);
u64 FUN_003ad400(u16 param_1,u16 param_2,u64 param_3,u32 param_4);
#pragma alias FUN_003ad400_typed FUN_003ad400
extern u64 FUN_003ad400_typed(u16 param_1,u16 param_2,u64 param_3,int param_4);
u64 FUN_003ad640(u64 param_1,u64 param_2);
u64 FUN_003ad740(int param_1,int param_2);
u64 FUN_003ad860(u64 param_1,int param_2);
u64 FUN_003ad930(u64 param_1,int param_2);
u64 FUN_003ada00(u64 param_1,int param_2);
u64 FUN_003adb00(u64 param_1,int param_2);
u64 FUN_003adb80(u64 param_1,int param_2);
u64 FUN_003add00(void);
u64 FUN_003add30(void);
u64 FUN_003add40(u64 param_1,int param_2);
u64 FUN_003ade70(int param_1,int param_2);
u64 FUN_003adf70(u64 param_1,int param_2);
u64 FUN_003ae000(u64 param_1,int param_2);
u64 FUN_003ae160(u64 param_1,int param_2);
u64 FUN_003ae260(u64 param_1,int param_2);
u64 FUN_003ae360(u64 param_1,int param_2);
u64 FUN_003ad360(u32 param_1,int param_2);
u64 FUN_003ad380(u64 param_1,int param_2);
void FUN_003a9d90(int param_1,int param_2,int param_3,int param_4,int param_5);
void FUN_003a9db0(int param_1,int param_2,int param_3,int param_4,int param_5);
void FUN_003a9de0(int param_1);
u64 FUN_003ae140(u64 param_1,int param_2);
u64 FUN_003ae150(u64 param_1,int param_2);
u64 FUN_003aca30(u64 param_1,u64 param_2);
u64 FUN_003aca40(u64 param_1,u64 param_2);
u64 FUN_003ad130(u32 param_1,int param_2);
u64 FUN_003ade60(u64 param_1,int param_2);
void FUN_003a9ac0(int param_1,int param_2,int param_3,int param_4,int param_5);

/* Region call-cast macros */
#define FUN_003a87d0(...) ((void (*)(...))FUN_003a87d0)(__VA_ARGS__)
#define FUN_003a8b00(...) ((u64 (*)(...))FUN_003a8b00)(__VA_ARGS__)
#define FUN_003a8d60(...) ((void (*)(...))FUN_003a8d60)(__VA_ARGS__)
#define FUN_003a8dc0(...) ((void (*)(...))FUN_003a8dc0)(__VA_ARGS__)
#define FUN_003a8ea0(...) ((void (*)(...))FUN_003a8ea0)(__VA_ARGS__)
#define FUN_003a8fb0(...) ((void (*)(...))FUN_003a8fb0)(__VA_ARGS__)
#define FUN_003a9080(...) ((void (*)(...))FUN_003a9080)(__VA_ARGS__)
#define FUN_003a90c0(...) ((void (*)(...))FUN_003a90c0)(__VA_ARGS__)
#define FUN_003a9140(...) ((u64 (*)(...))FUN_003a9140)(__VA_ARGS__)
#define FUN_003a9170(...) ((u64 (*)(...))FUN_003a9170)(__VA_ARGS__)
#define FUN_003a92a0(...) ((u64 (*)(...))FUN_003a92a0)(__VA_ARGS__)
#define FUN_003a92d0(...) ((u64 (*)(...))FUN_003a92d0)(__VA_ARGS__)
#define FUN_003a93a0(...) ((u64 (*)(...))FUN_003a93a0)(__VA_ARGS__)
#define FUN_003a9400(...) ((u64 (*)(...))FUN_003a9400)(__VA_ARGS__)
#define FUN_003a9470(...) ((u64 (*)(...))FUN_003a9470)(__VA_ARGS__)
#define FUN_003a94e0(...) ((u64 (*)(...))FUN_003a94e0)(__VA_ARGS__)
#define FUN_003a9510(...) ((u64 (*)(...))FUN_003a9510)(__VA_ARGS__)
#define FUN_003a9580(...) ((u64 (*)(...))FUN_003a9580)(__VA_ARGS__)
#define FUN_003a95f0(...) ((u64 (*)(...))FUN_003a95f0)(__VA_ARGS__)
#define FUN_003a9630(...) ((u64 (*)(...))FUN_003a9630)(__VA_ARGS__)
#define FUN_003a9670(...) ((u64 (*)(...))FUN_003a9670)(__VA_ARGS__)
#define FUN_003a96b0(...) ((u64 (*)(...))FUN_003a96b0)(__VA_ARGS__)
#define FUN_003a96f0(...) ((void (*)(...))FUN_003a96f0)(__VA_ARGS__)
#define FUN_003a9780(...) ((void (*)(...))FUN_003a9780)(__VA_ARGS__)
#define FUN_003a9930(...) ((void (*)(...))FUN_003a9930)(__VA_ARGS__)
#define FUN_003a9af0(...) ((void (*)(...))FUN_003a9af0)(__VA_ARGS__)
#define FUN_003a9b80(...) ((void (*)(...))FUN_003a9b80)(__VA_ARGS__)
#define FUN_003a9c30(...) ((void (*)(...))FUN_003a9c30)(__VA_ARGS__)
#define FUN_003a9c90(...) ((void (*)(...))FUN_003a9c90)(__VA_ARGS__)
#define FUN_003a9cf0(...) ((void (*)(...))FUN_003a9cf0)(__VA_ARGS__)
#define FUN_003a9e20(...) ((void (*)(...))FUN_003a9e20)(__VA_ARGS__)
#define FUN_003a9ed0(...) ((void (*)(...))FUN_003a9ed0)(__VA_ARGS__)
#define FUN_003aa000(...) ((void (*)(...))FUN_003aa000)(__VA_ARGS__)
#define FUN_003aa130(...) ((void (*)(...))FUN_003aa130)(__VA_ARGS__)
#define FUN_003aa280(...) ((void (*)(...))FUN_003aa280)(__VA_ARGS__)
#define FUN_003aa2d0(...) ((void (*)(...))FUN_003aa2d0)(__VA_ARGS__)
#define FUN_003aa370(...) ((void (*)(...))FUN_003aa370)(__VA_ARGS__)
#define FUN_003aa720(...) ((void (*)(...))FUN_003aa720)(__VA_ARGS__)
#define FUN_003aaae0(...) ((void (*)(...))FUN_003aaae0)(__VA_ARGS__)
#define FUN_003ab2a0(...) ((void (*)(...))FUN_003ab2a0)(__VA_ARGS__)
#define FUN_003ab320(...) ((void (*)(...))FUN_003ab320)(__VA_ARGS__)
#define FUN_003abb10(...) ((void (*)(...))FUN_003abb10)(__VA_ARGS__)
#define FUN_003ac240(...) ((void (*)(...))FUN_003ac240)(__VA_ARGS__)
#define FUN_003ac350(...) ((void (*)(...))FUN_003ac350)(__VA_ARGS__)
#define FUN_003ac500(...) ((void (*)(...))FUN_003ac500)(__VA_ARGS__)
#define FUN_003ac590(...) ((void (*)(...))FUN_003ac590)(__VA_ARGS__)
#define FUN_003ac5a0(...) ((u64 (*)(...))FUN_003ac5a0)(__VA_ARGS__)
#define FUN_003ac600(...) ((u64 (*)(...))FUN_003ac600)(__VA_ARGS__)
#define FUN_003ac820(...) ((u64 (*)(...))FUN_003ac820)(__VA_ARGS__)
#define FUN_003ac890(...) ((u64 (*)(...))FUN_003ac890)(__VA_ARGS__)
#define FUN_003ac900(...) ((u64 (*)(...))FUN_003ac900)(__VA_ARGS__)
#define FUN_003aca50(...) ((u64 (*)(...))FUN_003aca50)(__VA_ARGS__)
#define FUN_003acab0(...) ((u32 (*)(...))FUN_003acab0)(__VA_ARGS__)
#define FUN_003acbc0(...) ((u64 (*)(...))FUN_003acbc0)(__VA_ARGS__)
#define FUN_003acda0(...) ((u64 (*)(...))FUN_003acda0)(__VA_ARGS__)
#define FUN_003ace60(...) ((u64 (*)(...))FUN_003ace60)(__VA_ARGS__)
#define FUN_003acf80(...) ((u64 (*)(...))FUN_003acf80)(__VA_ARGS__)
#define FUN_003ad030(...) ((u64 (*)(...))FUN_003ad030)(__VA_ARGS__)
#define FUN_003ad1b0(...) ((u64 (*)(...))FUN_003ad1b0)(__VA_ARGS__)
#define FUN_003ad400(...) ((u64 (*)(...))FUN_003ad400)(__VA_ARGS__)
#define FUN_003ad640(...) ((u64 (*)(...))FUN_003ad640)(__VA_ARGS__)
#define FUN_003ad740(...) ((u64 (*)(...))FUN_003ad740)(__VA_ARGS__)
#define FUN_003ad860(...) ((u64 (*)(...))FUN_003ad860)(__VA_ARGS__)
#define FUN_003ad930(...) ((u64 (*)(...))FUN_003ad930)(__VA_ARGS__)
#define FUN_003ada00(...) ((u64 (*)(...))FUN_003ada00)(__VA_ARGS__)
#define FUN_003adb00(...) ((u64 (*)(...))FUN_003adb00)(__VA_ARGS__)
#define FUN_003adb80(...) ((u64 (*)(...))FUN_003adb80)(__VA_ARGS__)
#define FUN_003add00(...) ((u64 (*)(...))FUN_003add00)(__VA_ARGS__)
#define FUN_003add30(...) ((u64 (*)(...))FUN_003add30)(__VA_ARGS__)
#define FUN_003add40(...) ((u64 (*)(...))FUN_003add40)(__VA_ARGS__)
#define FUN_003ade70(...) ((u64 (*)(...))FUN_003ade70)(__VA_ARGS__)
#define FUN_003adf70(...) ((u64 (*)(...))FUN_003adf70)(__VA_ARGS__)
#define FUN_003ae000(...) ((u64 (*)(...))FUN_003ae000)(__VA_ARGS__)
#define FUN_003ae160(...) ((u64 (*)(...))FUN_003ae160)(__VA_ARGS__)
#define FUN_003ae260(...) ((u64 (*)(...))FUN_003ae260)(__VA_ARGS__)
#define FUN_003ae360(...) ((u64 (*)(...))FUN_003ae360)(__VA_ARGS__)

#undef FUN_003a87d0
#pragma opt_loop_invariants on
// FUN_003A87D0 NONMATCHING
void FUN_003a87d0(float param_1,int param_2,int param_3,long param_4,u32 param_5,u32 param_6,
                  long param_7)
{
  u32 uVar1;
  float *pfVar3;
  float *pfVar2;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar4;
  float fVar1;
  float fVar2;
  code *renderState;

  if ((param_4 == 0) || (param_5 == 0)) {
    FUN_0019d3f0(DAT_006a1bf8,0x39);
  }

  if (param_7 == 0) {
    FUN_004d7f60(2,0x44);
    FUN_004d7f60(3,0x717fb);
    renderState = (code *)&DAT_00960090_abs;
    (*renderState)(6,1);
    (*renderState)(8,1);
    (*renderState)(7,2);
    (*renderState)(9,2);
    (*renderState)(0xc,1);
    (*renderState)(0xe,0);
    (*renderState)(1,0);
  }

  uVar5 = param_6 >> 0x18 & 0xff;
  uVar6 = param_6 >> 0x10 & 0xff;
  uVar7 = param_6 >> 8 & 0xff;
  uVar8 = param_6 & 0xff;
  param_1 = *(float *)&DAT_00960088_abs - param_1;

  if ((param_7 != 0) || ((u8)param_6 > 0)) {
    uVar1 = (*DAT_00960178_abs)(param_5 << 6,0x40000);
    uVar4 = 0;
    fVar1 = (float)param_2;
    fVar2 = (float)param_3;
    do {
      pfVar3 = (float *)((int)param_4 + uVar4 * 8);
      pfVar2 = (float *)((int)uVar1 + uVar4 * 0x40);
      *pfVar2 = fVar1 + *pfVar3;
      pfVar2[1] = fVar2 + pfVar3[1];
      pfVar2[2] = param_1;
      pfVar2[8] = (float)uVar5;
      pfVar2[9] = (float)uVar6;
      pfVar2[10] = (float)uVar7;
      pfVar2[0xb] = (float)uVar8;
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_5);
    (*DAT_009600a0_abs)(4,uVar1,param_5);
    (*DAT_0096017c_abs)(uVar1);
  }
}
#pragma opt_loop_invariants off
#define FUN_003a87d0(...) ((void (*)(...))FUN_003a87d0)(__VA_ARGS__)
#undef FUN_003a8b00


// FUN_003A8B00 NONMATCHING
u32 FUN_003a8b00(int param_1,int param_2)



{

  u32 uVar1;

  u32 uVar2;

  int iVar3;


  

  FUN_005225a8(DAT_006a1d50);

  if ((param_1 < 0) || !(param_1 < 0xf)) {

    FUN_0019d3f0(DAT_006a1bf8, 0x1b5);

  }

  uVar1 = FUN_00191af0(0x50);

  FUN_00521408(uVar1,0,0x50);

  iVar3 = (int)uVar1;

  *(int *)iVar3 = iVar3;

  *(char *)(iVar3 + 0x3c) = (char)param_1;
  if (DAT_006a1d10_abs[param_1] != 0) {


    uVar2 = FUN_00191af0(DAT_006a1d10_abs[param_1]);

    *(int *)(iVar3 + 4) = (int)uVar2;

    *(int *)(iVar3 + 8) = (int)uVar2;
    FUN_00521408(uVar2,0,DAT_006a1d10_abs[param_1]);


  }

  switch (param_1) {
  case 10:
    *(code *)(iVar3 + 0x40) = (code)FUN_003a9140;
    *(u8 **)(iVar3 + 0x44) = (u8 *)&LAB_003a9170;
    *(u8 **)(iVar3 + 0x48) = (u8 *)&FUN_003a9230;
    break;
  case 0xb:
    *(code *)(iVar3 + 0x40) = (code)FUN_003a92a0;
    *(u8 **)(iVar3 + 0x44) = (u8 *)&LAB_003a92d0;
    *(u8 **)(iVar3 + 0x48) = (u8 *)&LAB_003a93a0;
    break;
  case 0xc:
    *(u8 **)(iVar3 + 0x44) = (u8 *)&LAB_003a9400;
    *(u8 **)(iVar3 + 0x48) = (u8 *)&LAB_003a9470;
    *(u32 *)(iVar3 + 0x4c) = 0;
    break;
  case 0xd:
    *(code *)(iVar3 + 0x40) = (code)FUN_003a94e0;
    *(u8 **)(iVar3 + 0x44) = (u8 *)&LAB_003a9510;
    *(u8 **)(iVar3 + 0x48) = (u8 *)&LAB_003a9580;
    break;
  case 0xe:
    *(u32 *)(iVar3 + 0x44) = 0;
    *(u32 *)(iVar3 + 0x48) = 0;
    *(u32 *)(iVar3 + 0x4c) = 0;
    break;
  }

  if (param_2 != 0) {

    switch (param_1) {
    case 6:
      **(u32 **)(iVar3 + 8) = param_2;
      break;
    case 7:
      **(u32 **)(iVar3 + 8) = param_2;
      break;
    case 9:
      **(u32 **)(iVar3 + 8) = param_2;
      break;
    case 8:
      **(u32 **)(iVar3 + 8) = param_2;
      break;
    }
  }

  return uVar1;

}
#define FUN_003a8b00(...) ((u64 (*)(...))FUN_003a8b00)(__VA_ARGS__)
#undef FUN_003a8d60
// FUN_003A8D60


void FUN_003a8d60(int param_1)
{
  u32 *puVar1;

  
  FUN_005225a8(DAT_006a1d70);

  if (param_1 != 0) {

    puVar1 = (u32 *)param_1;

    if (puVar1[2] != 0) {

      FUN_00191a10(puVar1[1]);

    }

    FUN_00191a10(*puVar1);

  }

  return;

}
#define FUN_003a8d60(...) ((void (*)(...))FUN_003a8d60)(__VA_ARGS__)
#undef FUN_003a8dc0
// FUN_003A8DC0


void FUN_003a8dc0(int param_1,int param_2,int param_3,int param_4,

                 int param_5,int param_6)



{

  int iVar1;

  

  if (param_1 == 0) {

    FUN_0019d3f0(DAT_006a1bf8, 0x24e);

  }

  FUN_005225a8(DAT_006a1d90);

  iVar1 = (int)param_1;

  *(int *)(iVar1 + 0x10) = (int)param_2;

  *(int *)(iVar1 + 0x14) = (int)param_3;

  *(int *)(iVar1 + 0x18) = (int)param_4;

  *(int *)(iVar1 + 0x1c) = (int)param_5;

  *(u32 *)(iVar1 + 0xc) = param_6;

  if (PTR_FUN_006a1c10_abs[*(u8 *)(iVar1 + 0x3c)] != (code)0) {

    (PTR_FUN_006a1c10_abs[*(u8 *)(iVar1 + 0x3c)])

              (*(u32 *)(iVar1 + 8),param_2,param_3,param_4,param_5);

  }

  return;

}
#define FUN_003a8dc0(...) ((void (*)(...))FUN_003a8dc0)(__VA_ARGS__)
#undef FUN_003a8ea0
// FUN_003A8EA0 NONMATCHING


void FUN_003a8ea0(long param_1,int param_2,int param_3,int param_4,int param_5,int param_6)



{

  int iVar1;

  

  if (param_1 == 0) {

    FUN_0019d3f0(DAT_006a1bf8, 0x270);

  }

  FUN_005225a8(DAT_006a1db0);

  iVar1 = (int)param_1;

  *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + param_2;

  *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + param_3;

  *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + param_4;

  *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + param_5;

  *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + param_6;

  if ((code *)(&PTR_FUN_006a1c10)[*(u8 *)(iVar1 + 0x3c)] != (code *)0x0) {

    (*(code *)(&PTR_FUN_006a1c10)[*(u8 *)(iVar1 + 0x3c)])

              (*(u32 *)(iVar1 + 8),*(u32 *)(iVar1 + 0x10),

               *(u32 *)(iVar1 + 0x14),*(u32 *)(iVar1 + 0x18),

               *(u32 *)(iVar1 + 0x1c));

  }

  return;

}
#define FUN_003a8ea0(...) ((void (*)(...))FUN_003a8ea0)(__VA_ARGS__)
#undef FUN_003a8fb0
// FUN_003A8FB0


void FUN_003a8fb0(int param_1,int param_2,int param_3,int param_4,

                 int param_5)



{

  int iVar1;

  

  if (param_1 == 0) {

    FUN_0019d3f0(DAT_006a1bf8, 0x294);

  }

  FUN_005225a8(DAT_006a1dd0);

  iVar1 = (int)param_1;

  *(int *)(iVar1 + 0x2c) = (int)param_2;

  *(int *)(iVar1 + 0x30) = (int)param_3;

  *(int *)(iVar1 + 0x34) = (int)param_4;

  *(int *)(iVar1 + 0x38) = (int)param_5;

  if (PTR_LAB_006a1c50_abs[*(u8 *)(iVar1 + 0x3c)] != (code)0) {

    (PTR_LAB_006a1c50_abs[*(u8 *)(iVar1 + 0x3c)])

              (*(u32 *)(iVar1 + 8),param_2,param_3,param_4,param_5);

  }

  return;

}
#define FUN_003a8fb0(...) ((void (*)(...))FUN_003a8fb0)(__VA_ARGS__)
#undef FUN_003a9080
// FUN_003A9080


void FUN_003a9080(u64 param_1)



{

  FUN_003ac590_direct(0);

  FUN_003a90c0_direct(param_1,0);

  return;

}

#define FUN_003a9080(...) ((void (*)(...))FUN_003a9080)(__VA_ARGS__)
#undef FUN_003a90c0
// FUN_003A90C0


void FUN_003a90c0(int param_1,u64 param_2)



{

  if (param_1 == 0) {

    FUN_0019d3f0(DAT_006a1bf8, 0x2d6);

  }

  ((code *)PTR_FUN_006a1c90_abs)[*(u8 *)(param_1 + 0x3c)](param_1,param_2);

  return;

}
#define FUN_003a90c0(...) ((void (*)(...))FUN_003a90c0)(__VA_ARGS__)
#undef FUN_003a9140
// FUN_003A9140
u64 FUN_003a9140(int param_1)
{
  FUN_00521408(*(u32 *)(param_1 + 8),0,0x10);
  return 0;
}
#define FUN_003a9140(...) ((u64 (*)(...))FUN_003a9140)(__VA_ARGS__)
#undef FUN_003a9170
// FUN_003A9170
int FUN_003a9170(int param_1)
{
  int *piVar1;

  piVar1 = *(int **)(param_1 + 8);
  *piVar1 = 1;
  piVar1[2] = piVar1[2] + 1;
  piVar1[1] = 100 - piVar1[2] * 100 / 6;
  if (piVar1[2] > 1) {
    piVar1[3] = piVar1[2] * 255 / 6;
  } else {
    piVar1[3] = 0;
  }
  if (piVar1[2] >= 6) {
    *piVar1 = 2;
    piVar1[2] = 0;
    piVar1[1] = 0;
    piVar1[3] = 0xff;
    return 1;
  }
  return 0;
}

// FUN_003A9230
int FUN_003a9230(int param_1)
{
  int* state;

  state = *(int**)(param_1 + 8);
  state[0] = 3;
  state[2] = state[2] + 1;
  state[3] = 0xff - state[2] * 0xff / 10;
  if (state[2] >= 10) {
    state[0] = 0;
    state[2] = 0;
    state[3] = 0;
    return 1;
  }
  return 0;
}


#define FUN_003a9170(...) ((u64 (*)(...))FUN_003a9170)(__VA_ARGS__)
#undef FUN_003a92a0
// FUN_003A92A0
u64 FUN_003a92a0(int param_1)
{
  FUN_00521408(*(u32 *)(param_1 + 8),0,0x10);
  return 0;
}
#define FUN_003a92a0(...) ((u64 (*)(...))FUN_003a92a0)(__VA_ARGS__)
#undef FUN_003a92d0
// FUN_003A92D0
int FUN_003a92d0(int param_1)
{
  int *piVar1;

  piVar1 = *(int **)(param_1 + 8);
  *piVar1 = 1;
  piVar1[2] = piVar1[2] + 1;
  if (piVar1[2] < 4) {
    piVar1[1] = 100 - piVar1[2] * 100 / 4;
    piVar1[3] = piVar1[2] * 255 / 10;
  } else {
    piVar1[1] = 0;
    piVar1[3] = 0xff;
  }
  if (piVar1[2] >= 10) {
    *piVar1 = 2;
    piVar1[2] = 0;
    piVar1[1] = 0;
    piVar1[3] = 0xff;
    return 1;
  }
  return 0;
}
#define FUN_003a92d0(...) ((u64 (*)(...))FUN_003a92d0)(__VA_ARGS__)
#undef FUN_003a93a0
// FUN_003A93A0
u64 FUN_003a93a0(int param_1)
{
  int *piVar1;
  int iVar2;

  piVar1 = *(int **)(param_1 + 8);
  *piVar1 = 3;
  iVar2 = piVar1[2] + 1;
  piVar1[2] = iVar2;
  piVar1[3] = (1 - iVar2) * 255;
  if (piVar1[2] > 0) {
    *piVar1 = 0;
    piVar1[2] = 0;
    piVar1[3] = 0;
    return 1;
  }
  return 0;
}
#define FUN_003a93a0(...) ((u64 (*)(...))FUN_003a93a0)(__VA_ARGS__)
#undef FUN_003a9400
// FUN_003A9400
u64 FUN_003a9400(int param_1)
{
  int *piVar1;
  int iVar2;

  piVar1 = *(int **)(param_1 + 8);
  *piVar1 = 1;
  iVar2 = piVar1[2] + 1;
  piVar1[2] = iVar2;
  piVar1[3] = iVar2 * 255 / 15;
  if (piVar1[2] >= 15) {
    *piVar1 = 2;
    piVar1[2] = 0;
    piVar1[3] = 0xff;
    return 1;
  }
  return 0;
}
#define FUN_003a9400(...) ((u64 (*)(...))FUN_003a9400)(__VA_ARGS__)
#undef FUN_003a9470
// FUN_003A9470
u64 FUN_003a9470(int param_1)
{
  int *piVar1;
  int iVar2;

  piVar1 = *(int **)(param_1 + 8);
  *piVar1 = 3;
  iVar2 = piVar1[2] + 1;
  piVar1[2] = iVar2;
  piVar1[3] = 0xff - iVar2 * 255 / 5;
  if (piVar1[2] >= 5) {
    *piVar1 = 0;
    piVar1[2] = 0;
    piVar1[3] = 0;
    return 1;
  }
  return 0;
}
#define FUN_003a9470(...) ((u64 (*)(...))FUN_003a9470)(__VA_ARGS__)
#undef FUN_003a94e0
// FUN_003A94E0
u64 FUN_003a94e0(int param_1)
{
  FUN_00521408(*(u32 *)(param_1 + 8),0,0x10);
  return 0;
}
#define FUN_003a94e0(...) ((u64 (*)(...))FUN_003a94e0)(__VA_ARGS__)
#undef FUN_003a9510
// FUN_003A9510
u64 FUN_003a9510(int param_1)
{
  int *piVar1;
  int iVar2;

  piVar1 = *(int **)(param_1 + 8);
  *piVar1 = 1;
  iVar2 = piVar1[2] + 1;
  piVar1[2] = iVar2;
  piVar1[3] = iVar2 * 255 / 6;
  if (piVar1[2] >= 6) {
    *piVar1 = 2;
    piVar1[2] = 0;
    piVar1[3] = 0xff;
    return 1;
  }
  return 0;
}
#define FUN_003a9510(...) ((u64 (*)(...))FUN_003a9510)(__VA_ARGS__)
#undef FUN_003a9580
// FUN_003A9580
u64 FUN_003a9580(int param_1)
{
  int *piVar1;
  int iVar2;

  piVar1 = *(int **)(param_1 + 8);
  *piVar1 = 3;
  iVar2 = piVar1[2] + 1;
  piVar1[2] = iVar2;
  piVar1[3] = 0xff - iVar2 * 255 / 10;
  if (piVar1[2] >= 10) {
    *piVar1 = 0;
    piVar1[2] = 0;
    piVar1[3] = 0;
    return 1;
  }
  return 0;
}
#define FUN_003a9580(...) ((u64 (*)(...))FUN_003a9580)(__VA_ARGS__)
#undef FUN_003a95f0
// FUN_003A95F0
#pragma push
#pragma opt_rebuildconditionals off


int FUN_003a95f0(int param_1)
{
  int uVar1;

  if (*(code **)(param_1 + 0x40) == (code *)0x0)
    goto set_one;
  uVar1 = (*(code *)(param_1 + 0x40))();
  goto done;
set_one:
  uVar1 = 1;
done:
  return uVar1;
}
#pragma pop
#define FUN_003a95f0(...) ((u64 (*)(...))FUN_003a95f0)(__VA_ARGS__)
#undef FUN_003a9630
// FUN_003A9630
#pragma push
#pragma opt_rebuildconditionals off


int FUN_003a9630(int param_1)
{
  int uVar1;

  if (*(code **)(param_1 + 0x44) == (code *)0x0)
    goto set_one;
  uVar1 = (*(code *)(param_1 + 0x44))();
  goto done;
set_one:
  uVar1 = 1;
done:
  return uVar1;
}
#pragma pop
#define FUN_003a9630(...) ((u64 (*)(...))FUN_003a9630)(__VA_ARGS__)
#undef FUN_003a9670
// FUN_003A9670
#pragma push
#pragma opt_rebuildconditionals off


int FUN_003a9670(int param_1)
{
  int uVar1;

  if (*(code **)(param_1 + 0x48) == (code *)0x0)
    goto set_one;
  uVar1 = (*(code *)(param_1 + 0x48))();
  goto done;
set_one:
  uVar1 = 1;
done:
  return uVar1;
}
#pragma pop
#define FUN_003a9670(...) ((u64 (*)(...))FUN_003a9670)(__VA_ARGS__)
#undef FUN_003a96b0
// FUN_003A96B0
#pragma push
#pragma opt_rebuildconditionals off


int FUN_003a96b0(int param_1)
{
  int uVar1;

  if (*(code **)(param_1 + 0x4c) == (code *)0x0)
    goto set_one;
  uVar1 = (*(code *)(param_1 + 0x4c))();
  goto done;
set_one:
  uVar1 = 1;
done:
  return uVar1;
}
#pragma pop
#define FUN_003a96b0(...) ((u64 (*)(...))FUN_003a96b0)(__VA_ARGS__)
#undef FUN_003a96f0
// FUN_003A96F0 MATCHING


void FUN_003a96f0(int *param_1,int param_2,int param_3,int param_4,int param_5)



{

  int iVar1;

  int iVar2;

  int aiStack_10 [4];

  

  aiStack_10[0] = param_2;

  aiStack_10[1] = param_2 + 0x200;

  aiStack_10[2] = param_4 + -0x200;

  aiStack_10[3] = param_4;

  if (param_4 + -0x200 < param_2 + 0x200) {

    aiStack_10[1] = param_2 + (param_4 - param_2 >> 1);

    aiStack_10[2] = aiStack_10[1];

  }

  for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {

    iVar1 = *(int *)(int)(aiStack_10 + iVar2);

    *param_1 = iVar1;

    param_1[1] = param_3;

    param_1[2] = iVar1;

    param_1[3] = param_5;

    param_1 = param_1 + 4;

  }

  return;

}

#define FUN_003a96f0(...) ((void (*)(...))FUN_003a96f0)(__VA_ARGS__)
#undef FUN_003a9780
// FUN_003A9780 NONMATCHING


void FUN_003a9780(int *param_1,int param_2,int param_3,int param_4,int param_5)



{

  int iVar1;

  int iVar3;

  int iVar2;

  int aiStack_10 [4];

  int aiStack_20 [4];

  

  aiStack_10[0] = param_2 + -0x100;

  aiStack_10[1] = param_2 + 0x200;

  aiStack_10[2] = param_4 + -0x200;

  aiStack_10[3] = param_4 + 0x100;

  aiStack_20[0] = param_3 + -0x80;

  aiStack_20[1] = param_3 + 0x80;

  aiStack_20[2] = param_5 + -0x80;

  aiStack_20[3] = param_5 + 0x80;

  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

    iVar1 = aiStack_20[iVar3];

    for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {

      *param_1 = aiStack_10[iVar2];

      param_1[1] = iVar1;

      param_1 = param_1 + 2;

    }

  }

  aiStack_10[0] = param_2 + -0x100;

  aiStack_10[1] = param_2 + 0x400;

  aiStack_10[2] = param_4 + -0x400;

  aiStack_10[3] = param_4 + 0x100;

  for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {

    iVar1 = *(int *)(&LAB_006a1de8 + iVar3 * 4);

    for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {

      *param_1 = aiStack_10[iVar2];

      param_1[1] = param_3 + iVar1;

      param_1 = param_1 + 2;

    }

  }

  for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {

    iVar1 = *(int *)(&LAB_006a1de8 + iVar3 * 4);

    for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {

      *param_1 = aiStack_10[iVar2];

      param_1[1] = param_5 - iVar1;

      param_1 = param_1 + 2;

    }

  }

  return;

}
#define FUN_003a9780(...) ((void (*)(...))FUN_003a9780)(__VA_ARGS__)
#undef FUN_003a9930
// FUN_003A9930 NONMATCHING


void FUN_003a9930(int *param_1,int param_2,int param_3,int param_4,int param_5)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int aiStack_10 [4];

  int aiStack_20 [4];

  

  aiStack_10[0] = param_2 + -0x100;

  aiStack_10[1] = param_2 + 0x200;

  aiStack_10[2] = param_4 + -0x200;

  aiStack_10[3] = param_4 + 0x100;

  aiStack_20[0] = param_3 + -0x80;

  aiStack_20[1] = param_3 + 0x80;

  aiStack_20[2] = param_5 + -0x80;

  aiStack_20[3] = param_5 + 0x80;

  for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {

    iVar1 = aiStack_20[iVar2];

    for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

      *param_1 = aiStack_10[iVar3];

      param_1[1] = iVar1;

      param_1 = param_1 + 2;

    }

  }

  aiStack_10[0] = param_2 + -0x100;

  aiStack_10[1] = param_2 + 0x400;

  aiStack_10[2] = param_4 + -0x400;

  aiStack_10[3] = param_4 + 0x100;

  for (iVar2 = 0; iVar2 < 2; iVar2 = iVar2 + 1) {

    for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {

      *param_1 = aiStack_10[iVar1];

      param_1[1] = param_3 + iVar2 * 8;

      param_1 = param_1 + 2;

    }

  }

  for (iVar2 = 0; iVar2 < 2; iVar2 = iVar2 + 1) {

    for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {

      *param_1 = aiStack_10[iVar1];

      param_1[1] = param_5 + iVar2 * -8;

      param_1 = param_1 + 2;

    }

  }

  return;

}
#define FUN_003a9930(...) ((void (*)(...))FUN_003a9930)(__VA_ARGS__)
// Retail 0x003a9ac0-0x003a9ae4
// FUN_003A9AC0
void FUN_003a9ac0(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  *(int *)(param_1 + 0) = param_2;
  *(int *)(param_1 + 4) = param_3;
  *(int *)(param_1 + 8) = param_4;
  *(int *)(param_1 + 0xc) = param_3;
  *(int *)(param_1 + 0x10) = param_4;
  *(int *)(param_1 + 0x14) = param_5;
  *(int *)(param_1 + 0x18) = param_2;
  *(int *)(param_1 + 0x1c) = param_5;
}
#undef FUN_003a9af0
// FUN_003A9AF0


void FUN_003a9af0(int *param_1,u32 param_2,int param_3,int param_4,u32 param_5)



{

  int iVar3;

  int iVar2;

  int iVar1;

  struct {
    int pad[2];
    int values[6];
  } stack;

  

  stack.values[2] = param_2;

  stack.values[3] = param_4 + -0x5a0;

  stack.values[4] = param_4;

  stack.values[0] = param_3;

  stack.values[1] = param_5;

  for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {

    iVar2 = 0;
    iVar1 = stack.values[iVar3];

    for (; iVar2 < 3; iVar2 = iVar2 + 1) {

      *param_1 = stack.values[iVar2 + 2];

      param_1[1] = iVar1;

      param_1 = param_1 + 2;

    }

  }

  return;

}
#define FUN_003a9af0(...) ((void (*)(...))FUN_003a9af0)(__VA_ARGS__)
#undef FUN_003a9b80
// FUN_003A9B80


void FUN_003a9b80(int param_1,u64 param_2,int param_3,u64 param_4,int param_5)
{
  u32 uVar1;
  int iVar2;
  u32 *puVar3;
  u32 value1;
  u32 value2;
  u32 *p;
  u32 auStack_10[4];

  puVar3 = (u32 *)(param_1 + 4);
  auStack_10[0] = 0x1a0;
  auStack_10[1] = 0x480;
  auStack_10[2] = 0x1b70;
  auStack_10[3] = 0x1e50;
  value1 = param_3 + 0x160;
  value2 = param_5 + -0x140;
  for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
    p = auStack_10 + iVar2;
    uVar1 = *(u32 *)((int)p + 0);
    *puVar3 = uVar1;
    puVar3[1] = value1;
    puVar3[2] = uVar1;
    puVar3[3] = value2;
    puVar3 = puVar3 + 4;
  }
  return;
}
#define FUN_003a9b80(...) ((void (*)(...))FUN_003a9b80)(__VA_ARGS__)
// FUN_003A9C00
void FUN_003a9c00(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  *(int *)(param_1 + 0x40) = param_2;
  *(int *)(param_1 + 0x44) = param_3;
  *(int *)(param_1 + 0x48) = param_4;
  *(int *)(param_1 + 0x4c) = 0;
  *(int *)(param_1 + 0x50) = param_2;
  *(int *)(param_1 + 0x54) = param_3;
  *(int *)(param_1 + 0x58) = param_4;
  *(int *)(param_1 + 0x5c) = param_5;
}
#undef FUN_003a9c30
// FUN_003A9C30


void FUN_003a9c30(int param_1,u32 param_2,u32 param_3,u32 param_4,

                 u32 param_5)



{
  u32 *puVar1;

  puVar1 = (u32 *)(param_1 + 0x140);
  puVar1[0] = param_2;
  puVar1[1] = param_3;
  puVar1[2] = param_4;
  puVar1[3] = 1;
  puVar1[4] = param_2;
  puVar1[5] = param_3;
  puVar1[6] = param_4;
  puVar1[7] = param_5;
  FUN_003b4a90((int *)(puVar1 + 8),param_2,param_3,param_4,param_5,(int *)FUN_006a1e00,6);
  return;
}

#define FUN_003a9c30(...) ((void (*)(...))FUN_003a9c30)(__VA_ARGS__)
#undef FUN_003a9c90
// FUN_003A9C90


void FUN_003a9c90(int param_1,u32 param_2,u32 param_3,u32 param_4,

                 u32 param_5)



{
  u32 *puVar1;

  puVar1 = (u32 *)(param_1 + 0x100);
  puVar1[0] = param_2;
  puVar1[1] = param_3;
  puVar1[2] = param_4;
  puVar1[3] = 1;
  puVar1[4] = param_2;
  puVar1[5] = param_3;
  puVar1[6] = param_4;
  puVar1[7] = param_5;
  FUN_003b4a90((int *)(puVar1 + 8),param_2,param_3,param_4,param_5,(int *)FUN_006a1e60,4);
  return;
}

#define FUN_003a9c90(...) ((void (*)(...))FUN_003a9c90)(__VA_ARGS__)
#undef FUN_003a9cf0
// FUN_003A9CF0 NONMATCHING


void FUN_003a9cf0(int param_1,u64 param_2,u64 param_3,u64 param_4,

                 u32 param_5)



{

  *(int *)(param_1 + 0x20) = (int)param_2;

  *(int *)(param_1 + 0x24) = (int)param_3;

  *(int *)(param_1 + 0x28) = (int)param_4;

  *(u32 *)(param_1 + 0x2c) = param_5;

  FUN_003b4a90((int *)(param_1 + 0x30),(int)param_2,(int)param_3,(int)param_4,param_5,(int *)FUN_006a1ea0,1);
  FUN_003b4a90((int *)(param_1 + 0x40),(int)param_2,(int)param_3,(int)param_4,0x80,(int *)FUN_006a1eb0,2);

  return;

}
#define FUN_003a9cf0(...) ((void (*)(...))FUN_003a9cf0)(__VA_ARGS__)
// Retail 0x003a9d90-0x003a9da4
// FUN_003A9D90
void FUN_003a9d90(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  *(int *)(param_1 + 0x20) = param_2;
  *(int *)(param_1 + 0x24) = param_3;
  *(int *)(param_1 + 0x28) = param_4;
  *(int *)(param_1 + 0x2c) = param_5;
}

// Retail 0x003a9db0-0x003a9dd4
// FUN_003A9DB0
void FUN_003a9db0(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  *(int *)(param_1 + 0x30) = param_2;
  *(int *)(param_1 + 0x34) = param_3;
  *(int *)(param_1 + 0x38) = param_4;
  *(int *)(param_1 + 0x3c) = 0;
  *(int *)(param_1 + 0x40) = param_2;
  *(int *)(param_1 + 0x44) = param_3;
  *(int *)(param_1 + 0x48) = param_4;
  *(int *)(param_1 + 0x4c) = param_5;
}

// Retail 0x003a9de0-0x003a9e10
// FUN_003A9DE0
void FUN_003a9de0(int param_1)
{
  *(int *)(param_1 + 0x44) = 0x73;
  *(int *)(param_1 + 0x48) = 0x87;
  *(int *)(param_1 + 0x4c) = 0xff;
  *(int *)(param_1 + 0x50) = 0;
  *(int *)(param_1 + 0x54) = 0x73;
  *(int *)(param_1 + 0x58) = 0x87;
  *(int *)(param_1 + 0x5c) = 0xff;
  *(int *)(param_1 + 0x60) = 0;
}
#undef FUN_003a9e20
// FUN_003A9E20


void FUN_003a9e20(int param_1,u64 param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;
  int index;

  

  iVar2 = *(int *)(param_1 + 8);
  iVar3 = iVar2 + 0x40;

  *(u32 *)(iVar2 + 0x5c) = *(u32 *)(param_1 + 0x38);

  for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {

    index = iVar1 << 2;
    FUN_003b4b40(iVar2,iVar3,DAT_006a1ee0_abs + index,DAT_006a1ef0_abs + index,

                 *(u32 *)(param_1 + 0xc),param_2);

  }

  return;

}
#define FUN_003a9e20(...) ((void (*)(...))FUN_003a9e20)(__VA_ARGS__)
#undef FUN_003a9ed0
// FUN_003A9ED0 NONMATCHING


void FUN_003a9ed0(int param_1,u64 param_2)



{

  u32 uVar1;

  int iVar2;

  int iVar3;

  

  uVar1 = *(u32 *)(param_1 + 0x38);

  iVar2 = *(int *)(param_1 + 8) + 0x150;

  for (iVar3 = 1; iVar3 < 8; iVar3 = iVar3 + 1) {

    *(u32 *)(iVar2 + 0xc) = uVar1;

    iVar2 = iVar2 + 0x10;

  }

  iVar2 = *(int *)(param_1 + 8);

  for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {

    FUN_003b4eb0(iVar2,iVar2 + 0x140,iVar3 * 8 + 0x6a1f00,iVar3 * 8 + 0x6a1f20,8,

                 *(u32 *)(param_1 + 0xc),param_2);

  }

  for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {

    FUN_003b4ec0(iVar2 + (iVar3 * 4 + 0x10) * 8,iVar2 + 0x140,&gp0xffffa7d0,iVar3 * 4 + 0x6a1f40,4,

                 *(u32 *)(param_1 + 0xc),param_2);

  }

  return;

}
#define FUN_003a9ed0(...) ((void (*)(...))FUN_003a9ed0)(__VA_ARGS__)
#undef FUN_003aa000
// FUN_003AA000 NONMATCHING


void FUN_003aa000(int param_1,u64 param_2)



{

  u32 uVar1;

  int iVar2;

  int iVar3;

  

  uVar1 = *(u32 *)(param_1 + 0x38);

  iVar2 = *(int *)(param_1 + 8) + 0x110;

  for (iVar3 = 1; iVar3 < 6; iVar3 = iVar3 + 1) {

    *(u32 *)(iVar2 + 0xc) = uVar1;

    iVar2 = iVar2 + 0x10;

  }

  iVar2 = *(int *)(param_1 + 8);

  for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {

    FUN_003b4eb0(iVar2,iVar2 + 0x100,iVar3 * 8 + 0x6a1f60,iVar3 * 8 + 0x6a1f80,8,

                 *(u32 *)(param_1 + 0xc),param_2);

  }

  for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {

    FUN_003b4ec0(iVar2 + (iVar3 * 4 + 0x10) * 8,iVar2 + 0x100,&gp0xffffa7d4,iVar3 * 4 + 0x6a1fa0,4,

                 *(u32 *)(param_1 + 0xc),param_2);

  }

  return;

}
#define FUN_003aa000(...) ((void (*)(...))FUN_003aa000)(__VA_ARGS__)
#undef FUN_003aa130
// FUN_003AA130 NONMATCHING


void FUN_003aa130(int param_1,u64 param_2)
{
  int *piVar1;
  int iVar2;
  int aiStack_60[24];

  piVar1 = *(int **)(param_1 + 8);
  for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
    aiStack_60[iVar2 * 8] = piVar1[0] + iVar2 * 0x10;
    aiStack_60[iVar2 * 8 + 1] = piVar1[1] + iVar2 * 8;
    aiStack_60[iVar2 * 8 + 2] = piVar1[2] - iVar2 * 0x10;
    aiStack_60[iVar2 * 8 + 3] = piVar1[3] + iVar2 * 8;
    aiStack_60[iVar2 * 8 + 4] = piVar1[4] - iVar2 * 0x10;
    aiStack_60[iVar2 * 8 + 5] = piVar1[5] - iVar2 * 8;
    aiStack_60[iVar2 * 8 + 6] = piVar1[6] + iVar2 * 0x10;
    aiStack_60[iVar2 * 8 + 7] = piVar1[7] - iVar2 * 8;
  }
  FUN_003b4b40(piVar1,piVar1 + 8,gp0xffffa7d8,gp0xffffa7dc,
               *(u32 *)(param_1 + 0xc),param_2);
  for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
    FUN_003b4ec0(aiStack_60,piVar1 + 8,iVar2 * 5 + 0x6a1fb0,
                 iVar2 * 5 + 0x6a1fc0,5,*(u32 *)(param_1 + 0xc),param_2);
  }
  return;
}
#define FUN_003aa130(...) ((void (*)(...))FUN_003aa130)(__VA_ARGS__)
#undef FUN_003aa280
// FUN_003AA280


void FUN_003aa280(int param_1,u64 param_2)



{

  int *iVar1;
  int *iVar2;

  

  iVar1 = *(int **)(param_1 + 8);
  iVar2 = (int *)((u8 *)iVar1 + 0x20);

  *(u32 *)((u8 *)iVar2 + 0xc) = *(u32 *)(param_1 + 0x38);

  FUN_003b4b40(iVar1,iVar2,&gp0xffffa7e0,&gp0xffffb934,*(u32 *)(param_1 + 0xc),param_2
              );

  return;

}
#define FUN_003aa280(...) ((void (*)(...))FUN_003aa280)(__VA_ARGS__)
#undef FUN_003aa2d0
// FUN_003AA2D0


void FUN_003aa2d0(int param_1,u64 param_2)
{
  int *iVar1;
  int *iVar2;

  iVar1 = *(int **)(param_1 + 8);
  iVar2 = (int *)((u8 *)iVar1 + 0x30);
  *(u32 *)((u8 *)iVar1 + 0x4c) = *(u32 *)(param_1 + 0x38);
  iVar1 = *(int **)(param_1 + 8);
  FUN_003b4ed0(param_2,2,0);
  FUN_003b4eb0(iVar1,iVar2,&gp0xffffa7e8,&gp0xffffa7f0,6,
               *(u32 *)(param_1 + 0xc),param_2);
  FUN_003b4ed0(param_2,0,0);
}
#define FUN_003aa2d0(...) ((void (*)(...))FUN_003aa2d0)(__VA_ARGS__)
#undef FUN_003aa370
// FUN_003AA370 NONMATCHING


void FUN_003aa370(int param_1,u64 param_2)



{

  u32 *puVar1;

  int iVar2;

  int iStack_10;

  int iStack_c;

  int iStack_8;

  int iStack_4;

  

  puVar1 = *(u32 **)(param_1 + 8);

  iVar2 = *(int *)(param_1 + 0x38) * 0x39;

  if (iVar2 < 0) {

    iVar2 = iVar2 + 0x7f;

  }

  DAT_006a1fdc = iVar2 >> 7;

  iStack_10 = *(int *)(param_1 + 0x10);

  iStack_c = *(u32 *)(param_1 + 0x14);

  iStack_8 = *(u32 *)(param_1 + 0x18);

  iStack_4 = *(u32 *)(param_1 + 0x1c);

  FUN_003b4d10(&iStack_10,0x6a1fd0,*(u32 *)(param_1 + 0xc),0x490,param_2);

  iVar2 = *(int *)(param_1 + 0x38) * 0x26;

  if (iVar2 < 0) {

    iVar2 = iVar2 + 0x7f;

  }

  DAT_006a1fec = iVar2 >> 7;

  iStack_10 = *(int *)(param_1 + 0x10) + 0x720;

  iStack_c = *(u32 *)(param_1 + 0x14);

  iStack_8 = *(int *)(param_1 + 0x10) + 0x17e0;

  iStack_4 = *(u32 *)(param_1 + 0x1c);

  FUN_003b4d10(&iStack_10,0x6a1fe0,*(u32 *)(param_1 + 0xc),0x680,param_2);

  iStack_10 = *(int *)(param_1 + 0x10) + -0x140;

  iStack_c = *(int *)(param_1 + 0x14) + 0x48;

  iStack_8 = *(int *)(param_1 + 0x10) + 0xb40;

  iStack_4 = *(u32 *)(param_1 + 0x1c);

  FUN_003b4e90(&iStack_10,0x6a2040,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2);

  if (0 < *(int *)(param_1 + 0x28)) {

    if (*(int *)(param_1 + 0x24) != *(int *)(param_1 + 0x14)) {

      DAT_006a200c = 0x80 - ((*(int *)(param_1 + 0x24) - *(int *)(param_1 + 0x14)) * 0x80) /

                            *(int *)(param_1 + 0x28);

      goto LAB_003aa508;

    }

  }

  DAT_006a200c = *(int *)(param_1 + 0x38);

LAB_003aa508:

  iStack_10 = *(int *)(param_1 + 0x18) + -0xb40;

  iStack_c = *(u32 *)(param_1 + 0x14);

  iStack_8 = *(int *)(param_1 + 0x18) + 0x140;

  iStack_4 = *(int *)(param_1 + 0x1c) + -0x48;

  FUN_003b4e90(&iStack_10,0x6a2050,0x6a2000,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2);

  iVar2 = *(int *)(param_1 + 0x38) * 0x46;

  if (iVar2 < 0) {

    iVar2 = iVar2 + 0x7f;

  }

  DAT_006a1ffc = iVar2 >> 7;

  iStack_10 = *(int *)(param_1 + 0x10) + -0x140;

  iStack_c = *(int *)(param_1 + 0x14) + -0xb8;

  iStack_8 = *(int *)(param_1 + 0x10) + 0x1a40;

  iStack_4 = *(int *)(param_1 + 0x14) + 8;

  FUN_003b4e90(&iStack_10,0x6a2040,0x6a1ff0,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2);

  iStack_10 = *(int *)(param_1 + 0x10) + 0x8b0;

  iStack_4 = *(int *)(param_1 + 0x14);

  iStack_c = iStack_4 + -0x10;

  iStack_8 = *(int *)(param_1 + 0x10) + 0xfc0;

  FUN_003b4e90(&iStack_10,0x6a2020,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2);

  iStack_10 = iStack_8;

  iStack_8 = iStack_8 + 0x1040;

  FUN_003b4e90(&iStack_10,0x6a2030,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2);

  iStack_10 = *(int *)(param_1 + 0x10) + 0x1020;

  iStack_4 = *(int *)(param_1 + 0x1c);

  iStack_c = iStack_4 + -0x10;

  iStack_8 = *(int *)(param_1 + 0x10) + 0x1730;

  FUN_003b4e90(&iStack_10,0x6a2010,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2);

  iStack_8 = iStack_10;

  iStack_10 = iStack_10 + -0x1220;

  FUN_003b4e90(&iStack_10,0x6a2030,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2);

  return;

}
#define FUN_003aa370(...) ((void (*)(...))FUN_003aa370)(__VA_ARGS__)
#undef FUN_003aa720
// FUN_003AA720 NONMATCHING


void FUN_003aa720(int param_1)



{

  short sVar1;

  short sVar2;

  u32 uVar3;

  int iVar4;

  u64 uVar5;

  int iVar6;

  short *psVar7;

  short *psVar8;

  char cVar9;

  short asStack_20 [5];

  short sStack_16;

  short sStack_14;

  short sStack_12;

  short sStack_10;

  short sStack_e;

  short sStack_c;

  short sStack_a;

  short sStack_8;

  short sStack_6;

  short sStack_4;

  short sStack_2;

  

  iVar4 = *(int *)(param_1 + 8);

  psVar8 = DAT_006a2060;

  psVar7 = asStack_20;

  iVar6 = 8;

  do {

    sVar1 = *psVar8;

    sVar2 = psVar8[1];

    psVar8 = psVar8 + 2;

    iVar6 = iVar6 + -1;

    *psVar7 = sVar1;

    psVar7[1] = sVar2;

    psVar7 = psVar7 + 2;

  } while (0 < iVar6);

  uVar3 = *(u32 *)(iVar4 + 0xc);

  iVar6 = *(int *)(iVar4 + 4) + -5;

  uVar5 = FUN_001158b0(0,uGpffffb964,0);

  iVar4 = (int)uVar5;

  *(float *)(iVar4 + 0x10) = (float)(int)asStack_20[0];

  *(float *)(iVar4 + 0x14) = (float)(iVar6 + asStack_20[1]);

  *(u32 *)(iVar4 + 0x2c) = 0;

  cVar9 = -1 - (char)uVar3;

  *(char *)(iVar4 + 0x19) = cVar9;

  FUN_001127d0(uVar5,1);

  FUN_00115980(uVar5);

  uVar5 = FUN_001158b0(0,uGpffffb964,1);

  iVar4 = (int)uVar5;

  *(float *)(iVar4 + 0x10) = (float)(int)asStack_20[2];

  *(float *)(iVar4 + 0x14) = (float)(iVar6 + asStack_20[3]);

  *(u32 *)(iVar4 + 0x2c) = 0;

  *(char *)(iVar4 + 0x19) = cVar9;

  FUN_001127d0(uVar5,1);

  FUN_00115980(uVar5);

  uVar5 = FUN_001158b0(0,uGpffffb964,2);

  iVar4 = (int)uVar5;

  *(float *)(iVar4 + 0x10) = (float)(int)asStack_20[4];

  *(float *)(iVar4 + 0x14) = (float)(iVar6 + sStack_16);

  *(u32 *)(iVar4 + 0x2c) = 0;

  *(char *)(iVar4 + 0x19) = cVar9;

  FUN_001127d0(uVar5,1);

  FUN_00115980(uVar5);

  uVar5 = FUN_001158b0(0,uGpffffb964,3);

  iVar4 = (int)uVar5;

  *(float *)(iVar4 + 0x10) = (float)(int)sStack_14;

  *(float *)(iVar4 + 0x14) = (float)(iVar6 + sStack_12);

  *(u32 *)(iVar4 + 0x2c) = 0;

  *(char *)(iVar4 + 0x19) = cVar9;

  FUN_001127d0(uVar5,1);

  FUN_00115980(uVar5);

  uVar5 = FUN_001158b0(0,uGpffffb964,4);

  iVar4 = (int)uVar5;

  *(float *)(iVar4 + 0x10) = (float)(int)sStack_10;

  *(float *)(iVar4 + 0x14) = (float)(iVar6 + sStack_e);

  *(u32 *)(iVar4 + 0x2c) = 0;

  *(char *)(iVar4 + 0x19) = cVar9;

  FUN_001127d0(uVar5,1);

  FUN_00115980(uVar5);

  uVar5 = FUN_001158b0(0,uGpffffb964,5);

  iVar4 = (int)uVar5;

  *(float *)(iVar4 + 0x10) = (float)(int)sStack_c;

  *(float *)(iVar4 + 0x14) = (float)(iVar6 + sStack_a);

  *(u32 *)(iVar4 + 0x2c) = 0;

  *(char *)(iVar4 + 0x19) = cVar9;

  FUN_001127d0(uVar5,1);

  FUN_00115980(uVar5);

  uVar5 = FUN_001158b0(0,uGpffffb964,6);

  iVar4 = (int)uVar5;

  *(float *)(iVar4 + 0x10) = (float)(int)sStack_8;

  *(float *)(iVar4 + 0x14) = (float)(iVar6 + sStack_6);

  *(u32 *)(iVar4 + 0x2c) = 0;

  *(char *)(iVar4 + 0x19) = cVar9;

  FUN_001127d0(uVar5,1);

  FUN_00115980(uVar5);

  uVar5 = FUN_001158b0(0,uGpffffb964,7);

  iVar4 = (int)uVar5;

  *(float *)(iVar4 + 0x10) = (float)(int)sStack_4;

  *(float *)(iVar4 + 0x14) = (float)(iVar6 + sStack_2);

  *(u32 *)(iVar4 + 0x2c) = 0;

  *(char *)(iVar4 + 0x19) = cVar9;

  FUN_001127d0(uVar5,1);

  FUN_00115980(uVar5);

  return;

}
#define FUN_003aa720(...) ((void (*)(...))FUN_003aa720)(__VA_ARGS__)
#undef FUN_003aaae0
// FUN_003AAAE0 NONMATCHING


void FUN_003aaae0(int param_1)



{

  short sVar1;

  short sVar2;

  int iVar3;

  u64 uVar4;

  int iVar5;

  short *psVar6;

  short *psVar7;

  char cVar8;

  float fVar9;

  short asStack_20 [5];

  short sStack_16;

  short sStack_14;

  short sStack_12;

  short sStack_10;

  short sStack_e;

  short sStack_c;

  short sStack_a;

  short sStack_8;

  short sStack_6;

  short sStack_4;

  short sStack_2;

  

  psVar7 = DAT_006a2080;

  psVar6 = asStack_20;

  iVar5 = 8;

  do {

    sVar1 = *psVar7;

    sVar2 = psVar7[1];

    psVar7 = psVar7 + 2;

    iVar5 = iVar5 + -1;

    *psVar6 = sVar1;

    psVar6[1] = sVar2;

    psVar6 = psVar6 + 2;

  } while (0 < iVar5);

  iVar5 = *(int *)(*(int *)(param_1 + 8) + 0xc);

  uVar4 = FUN_001158b0(0,uGpffffb964,0x14);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(asStack_20[0] + 5);

  *(float *)(iVar3 + 0x14) = (float)(asStack_20[1] + 5);

  *(u32 *)(iVar3 + 0x2c) = 0;

  cVar8 = -1 - (char)iVar5;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0x15);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(asStack_20[2] + 5);

  *(float *)(iVar3 + 0x14) = (float)(asStack_20[3] + 5);

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0x16);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(asStack_20[4] + 5);

  *(float *)(iVar3 + 0x14) = (float)(sStack_16 + 5);

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0x17);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(sStack_14 + 5);

  *(float *)(iVar3 + 0x14) = (float)(sStack_12 + 5);

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0x18);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(sStack_10 + 5);

  *(float *)(iVar3 + 0x14) = (float)(sStack_e + 5);

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0x19);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(sStack_c + 5);

  *(float *)(iVar3 + 0x14) = (float)(sStack_a + 5);

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0x1a);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(sStack_8 + 5);

  *(float *)(iVar3 + 0x14) = (float)(sStack_6 + 5);

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0x1b);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(sStack_4 + 5);

  *(float *)(iVar3 + 0x14) = (float)(sStack_2 + 5);

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,8);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(int)asStack_20[0];

  *(float *)(iVar3 + 0x14) = (float)(int)asStack_20[1];

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,9);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(int)asStack_20[2];

  *(float *)(iVar3 + 0x14) = (float)(int)asStack_20[3];

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,10);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(int)asStack_20[4];

  *(float *)(iVar3 + 0x14) = (float)(int)sStack_16;

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0xb);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(int)sStack_14;

  *(float *)(iVar3 + 0x14) = (float)(int)sStack_12;

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0xc);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(int)sStack_10;

  *(float *)(iVar3 + 0x14) = (float)(int)sStack_e;

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0xd);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(int)sStack_c;

  *(float *)(iVar3 + 0x14) = (float)(int)sStack_a;

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0xe);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(int)sStack_8;

  *(float *)(iVar3 + 0x14) = (float)(int)sStack_6;

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0xf);

  iVar3 = (int)uVar4;

  *(float *)(iVar3 + 0x10) = (float)(int)sStack_4;

  *(float *)(iVar3 + 0x14) = (float)(int)sStack_2;

  *(u32 *)(iVar3 + 0x2c) = 0;

  *(char *)(iVar3 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  uVar4 = FUN_001158b0(0,uGpffffb964,0x11);

  fVar9 = (1.0f - (float)iVar5 / 255.0f) * 32.0f;

  iVar5 = (int)uVar4;

  *(float *)(iVar5 + 0x10) = (float)(int)(fVar9 + 549.0f);

  *(float *)(iVar5 + 0x14) = (float)(int)(fVar9 + 379.0f);

  *(u32 *)(iVar5 + 0x2c) = 0;

  *(char *)(iVar5 + 0x19) = cVar8;

  FUN_001127d0(uVar4,1);

  FUN_00115980(uVar4);

  return;

}
#define FUN_003aaae0(...) ((void (*)(...))FUN_003aaae0)(__VA_ARGS__)
#undef FUN_003ab2a0
// FUN_003AB2A0


void FUN_003ab2a0(int param_1,u32 param_2)



{

  if (param_1 == 0) {

    FUN_0019d3f0(DAT_006a1bf8,0x80b);

  }

  if (*(u8 *)((int)param_1 + 0x3c) != '\f') {

    FUN_0019d3f0(DAT_006a1bf8,0x80c);

  }

  *(u32 *)(*(int *)((int)param_1 + 8) + 4) = param_2;

  return;

}
#define FUN_003ab2a0(...) ((void (*)(...))FUN_003ab2a0)(__VA_ARGS__)
#undef FUN_003ab320
// FUN_003AB320 NONMATCHING


void FUN_003ab320(int param_1)
{
  int *piVar1;
  int iVar3;
  int mode;
  int iVar2;
  float fVar4;
  float fVar5;

  piVar1 = *(int **)(param_1 + 8);
  iVar3 = piVar1[3];
  mode = *piVar1;
  if (mode == 3) {
    iVar3 = (int)((float)((5 - piVar1[2]) * 0xff) / 5.0f);
    FUN_003c9000(0.0f,((float)(piVar1[2] / 5) + 1.0f) * 5.5f,6.90625f,-75,-57,iVar3 & 0xff,0,0);
    FUN_003c9000(0.0f,1.328125f,1.328125f,-31,-16,iVar3 & 0xff,piVar1[1],0);
  } else if (mode == 2) {
    fVar4 = fGpffff839c * (float)iVar3;
    if (2147483648.0f <= fVar4)
      fVar4 = fVar4 - 2147483648.0f;
    FUN_003c9000(0.0f,5.5f,6.90625f,-75,-57,(int)fVar4 & 0xff,0,1);
    FUN_003c9000(0.0f,5.5f,6.90625f,-75,-57,(int)fVar4 & 0xff,0,0);
    fVar4 = fGpffff845c * (float)iVar3;
    if (2147483648.0f <= fVar4)
      fVar4 = fVar4 - 2147483648.0f;
    FUN_003c9000(0.0f,5.5f,uGpffff8070,-75,0x23,(int)fVar4 & 0xff,0,0);
    FUN_003c9000(0.0f,1.328125f,1.328125f,-31,-16,0xff,piVar1[1],0);
  } else if (mode == 1) {
    iVar2 = piVar1[2];
    if ((10 < iVar2) && (iVar2 < 0x10)) {
      fVar4 = (fGpffff839c * (float)iVar3 * (float)(iVar2 + -10)) / 5.0f;
      if (2147483648.0f <= fVar4)
        fVar4 = fVar4 - 2147483648.0f;
      FUN_003c9000(0.0f,5.5f,6.90625f,-75,-57,(int)fVar4 & 0xff,0,1);
    }
    iVar3 = piVar1[2];
    if (iVar3 < 6) {
      fVar4 = (float)(iVar3 * 0xff) / 5.0f;
      if (2147483648.0f <= fVar4)
        fVar4 = fVar4 - 2147483648.0f;
      FUN_003c9000(0.0f,((float)iVar3 * 5.5f) / 5.0f,uGpffff8070,-75,0x23,(int)fVar4 & 0xff,0,0);
    } else if (iVar3 < 0xd) {
      FUN_003c9000(0.0f,5.5f,uGpffff8070,-75,0x23,0xff,0,0);
    } else if (iVar3 < 0x10) {
      fVar4 = (float)((0xf - iVar3) * 0xff) / 3.0f;
      if (2147483648.0f <= fVar4)
        fVar4 = fVar4 - 2147483648.0f;
      FUN_003c9000(0.0f,5.5f,uGpffff8070,-75,0x23,(int)fVar4 & 0xff,0,0);
    }
    iVar3 = piVar1[2];
    if (5 < iVar3) {
      if (iVar3 < 0xd) {
        iVar3 = iVar3 + -5;
        fVar4 = (float)(iVar3 * 0xff) / 7.0f;
        if (2147483648.0f <= fVar4)
          fVar4 = fVar4 - 2147483648.0f;
        FUN_003c9000(0.0f,5.5f,((float)iVar3 * 6.90625f) / 7.0f,-75,
                     (int)(38.0f - (float)(iVar3 * 0x5f) / 7.0f),(int)fVar4 & 0xff,0,0);
      } else {
        FUN_003c9000(0.0f,uGpffff8458,6.90625f,-75,-57,0xff,0,0);
      }
    }
    iVar3 = piVar1[2];
    if (10 < iVar3) {
      if (iVar3 < 0xf) {
        fVar4 = (float)FUN_0052e878((fGpffff8110 * (float)(0xe - iVar3)) / 4.0f);
        fVar5 = (float)FUN_0052e878((fGpffff8110 * (float)(0xe - piVar1[2])) / 4.0f);
        FUN_003c9000(0.0f,1.328125f,1.328125f,(int)(-31.0f - fVar4 * 64.0f),
                     (int)(fVar5 * 64.0f + -16.0f),0xff,piVar1[1],0);
      } else {
        FUN_003c9000(0.0f,1.328125f,1.328125f,-31,-16,0xff,piVar1[1],0);
      }
    }
  }
}

#define FUN_003ab320(...) ((void (*)(...))FUN_003ab320)(__VA_ARGS__)
#undef FUN_003abb10
// FUN_003ABB10 NONMATCHING


void FUN_003abb10(int param_1)



{

  int *piVar1;

  u32 uVar2;

  u32 uVar3;

  int iVar4;

  u64 uVar5;

  int iVar6;

  int iVar7;

  u32 *puVar8;

  u32 *puVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  char cVar13;

  int iVar14;

  u32 auStack_40 [8];

  u32 auStack_20 [8];

  

  piVar1 = *(int **)(param_1 + 8);

  puVar9 = &DAT_006a20a0;

  puVar8 = auStack_20;

  iVar7 = 3;

  do {

    uVar2 = *puVar9;

    uVar3 = puVar9[1];

    puVar9 = puVar9 + 2;

    iVar7 = iVar7 + -1;

    *puVar8 = uVar2;

    puVar8[1] = uVar3;

    puVar8 = puVar8 + 2;

  } while (0 < iVar7);

  puVar9 = &DAT_006a20c0;

  puVar8 = auStack_40;

  iVar7 = 3;

  do {

    uVar2 = *puVar9;

    uVar3 = puVar9[1];

    puVar9 = puVar9 + 2;

    iVar7 = iVar7 + -1;

    *puVar8 = uVar2;

    puVar8[1] = uVar3;

    puVar8 = puVar8 + 2;

  } while (0 < iVar7);

  iVar12 = *(int *)(param_1 + 0x10) >> 4;

  iVar11 = *(int *)(param_1 + 0x14) >> 3;

  iVar14 = *(int *)(param_1 + 0x18) >> 4;

  iVar6 = *(int *)(param_1 + 0x1c) >> 3;

  iVar10 = iVar6 + 10;

  iVar7 = piVar1[3];

  iVar4 = *piVar1;

  cVar13 = (char)iVar7;

  if (iVar4 == 3) {

    uVar5 = FUN_001158b0(0,uGpffffb964,0x2a);

    iVar4 = (int)uVar5;

    *(u32 *)(iVar4 + 0x10) = 0;

    *(float *)(iVar4 + 0x14) = (float)(iVar6 + 0x8d);

    *(u32 *)(iVar4 + 0x2c) = 0;

    cVar13 = -1 - cVar13;

    *(char *)(iVar4 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    FUN_0040d5b0(iVar12,iVar11,iVar14,iVar10,(iVar7 * 0xe5) / 0xff & 0xffU | 0xb8bfc900);

    uVar5 = FUN_001158b0(0,uGpffffb964,0x27);

    iVar4 = (int)uVar5;

    *(u32 *)(iVar4 + 0x10) = 0;

    *(u32 *)(iVar4 + 0x14) = 0x42fa0000;

    *(u32 *)(iVar4 + 0x2c) = 0;

    *(char *)(iVar4 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    uVar5 = FUN_001158b0(0,uGpffffb964,0x28);

    iVar4 = (int)uVar5;

    *(u32 *)(iVar4 + 0x10) = 0;

    *(float *)(iVar4 + 0x14) = (float)(iVar6 + 0x8b);

    *(u32 *)(iVar4 + 0x2c) = 0;

    *(char *)(iVar4 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    uVar5 = FUN_001158b0(0,uGpffffb964,0x26);

    iVar4 = (int)uVar5;

    *(u32 *)(iVar4 + 0x10) = 0x42940000;

    *(u32 *)(iVar4 + 0x14) = 0x43010000;

    *(u32 *)(iVar4 + 0x2c) = 0;

    *(char *)(iVar4 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    iVar7 = ((0xff - iVar7) * -0xb4) / 0xff;

    FUN_003a87d0(0,0,iVar7,auStack_20,3,0x1b2d38ff,0);

    FUN_003a87d0(0,0,-iVar7,auStack_40,3,0x1b2d38ff,0);

  }

  else if (iVar4 == 2) {

    uVar5 = FUN_001158b0(0,uGpffffb964,0x2a);

    iVar4 = (int)uVar5;

    *(u32 *)(iVar4 + 0x10) = 0;

    *(float *)(iVar4 + 0x14) = (float)(iVar6 + 0x8d);

    *(u32 *)(iVar4 + 0x2c) = 0;

    cVar13 = -1 - cVar13;

    *(char *)(iVar4 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    FUN_0040d5b0(iVar12,iVar11,iVar14,iVar10,(iVar7 * 0xe5) / 0xff & 0xffU | 0xb8bfc900);

    uVar5 = FUN_001158b0(0,uGpffffb964,0x27);

    iVar7 = (int)uVar5;

    *(u32 *)(iVar7 + 0x10) = 0;

    *(u32 *)(iVar7 + 0x14) = 0x42fa0000;

    *(u32 *)(iVar7 + 0x2c) = 0;

    *(char *)(iVar7 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    uVar5 = FUN_001158b0(0,uGpffffb964,0x28);

    iVar7 = (int)uVar5;

    *(u32 *)(iVar7 + 0x10) = 0;

    *(float *)(iVar7 + 0x14) = (float)(iVar6 + 0x8b);

    *(u32 *)(iVar7 + 0x2c) = 0;

    *(char *)(iVar7 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    uVar5 = FUN_001158b0(0,uGpffffb964,0x26);

    iVar7 = (int)uVar5;

    *(u32 *)(iVar7 + 0x10) = 0x42940000;

    *(u32 *)(iVar7 + 0x14) = 0x43010000;

    *(u32 *)(iVar7 + 0x2c) = 0;

    *(char *)(iVar7 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    FUN_003a87d0(0,0,0,auStack_20,3,0x1b2d38ff,0);

    FUN_003a87d0(0,0,0,auStack_40,3,0x1b2d38ff,0);

  }

  else if (iVar4 == 1) {

    uVar5 = FUN_001158b0(0,uGpffffb964,0x2a);

    iVar4 = (int)uVar5;

    *(u32 *)(iVar4 + 0x10) = 0;

    *(float *)(iVar4 + 0x14) = (float)(iVar6 + 0x8d);

    *(u32 *)(iVar4 + 0x2c) = 0;

    cVar13 = -1 - cVar13;

    *(char *)(iVar4 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    FUN_0040d5b0(iVar12,iVar11,iVar14,iVar10,(iVar7 * 0xe5) / 0xff & 0xffU | 0xb8bfc900);

    uVar5 = FUN_001158b0(0,uGpffffb964,0x27);

    iVar4 = (int)uVar5;

    *(u32 *)(iVar4 + 0x10) = 0;

    *(u32 *)(iVar4 + 0x14) = 0x42fa0000;

    *(u32 *)(iVar4 + 0x2c) = 0;

    *(char *)(iVar4 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    uVar5 = FUN_001158b0(0,uGpffffb964,0x28);

    iVar4 = (int)uVar5;

    *(u32 *)(iVar4 + 0x10) = 0;

    *(float *)(iVar4 + 0x14) = (float)(iVar6 + 0x8b);

    *(u32 *)(iVar4 + 0x2c) = 0;

    *(char *)(iVar4 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    uVar5 = FUN_001158b0(0,uGpffffb964,0x26);

    iVar4 = (int)uVar5;

    *(float *)(iVar4 + 0x10) = (float)(((0xff - iVar7) * -0x8c) / 0xff + 0x4a);

    *(u32 *)(iVar4 + 0x14) = 0x43010000;

    *(u32 *)(iVar4 + 0x2c) = 0;

    *(char *)(iVar4 + 0x19) = cVar13;

    FUN_001127d0(uVar5,1);

    FUN_00115980(uVar5);

    iVar7 = ((0xff - iVar7) * -0x141) / 0xff;

    FUN_003a87d0(0,iVar7,0,auStack_20,3,0x1b2d38ff,0);

    FUN_003a87d0(0,-iVar7,0,auStack_40,3,0x1b2d38ff,0);

  }

  return;

}
#define FUN_003abb10(...) ((void (*)(...))FUN_003abb10)(__VA_ARGS__)
#undef FUN_003ac240
// FUN_003AC240 NONMATCHING


void FUN_003ac240(int param_1,u64 param_2)



{

  int iVar1;

  int iVar2;

  int iStack_10;

  u32 uStack_c;

  int iStack_8;

  u32 uStack_4;

  

  iStack_10 = *(int *)(param_1 + 0x10);

  iVar2 = iStack_10 + 0x3e0;

  iVar1 = *(int *)(param_1 + 0x18) + -0x3e0;

  uStack_c = *(u32 *)(param_1 + 0x14);

  uStack_4 = *(u32 *)(param_1 + 0x1c);

  iStack_8 = iVar2;

  FUN_003b4e90(&iStack_10,0x6a20e0,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),

               **(u32 **)(param_1 + 8),0,param_2);

  uStack_c = *(u32 *)(param_1 + 0x14);

  uStack_4 = *(u32 *)(param_1 + 0x1c);

  iStack_10 = iVar2;

  iStack_8 = iVar1;

  FUN_003b4ea0(&iStack_10,0x6a20f0,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),0,param_2);

  iStack_10 = *(int *)(param_1 + 0x18);

  uStack_c = *(u32 *)(param_1 + 0x14);

  uStack_4 = *(u32 *)(param_1 + 0x1c);

  iStack_8 = iVar1;

  FUN_003b4ea0(&iStack_10,0x6a20e0,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),0,param_2);

  return;

}
#define FUN_003ac240(...) ((void (*)(...))FUN_003ac240)(__VA_ARGS__)
#undef FUN_003ac350
// FUN_003AC350 NONMATCHING


void FUN_003ac350(int param_1,u64 param_2)



{

  u32 *puVar1;

  int iVar2;

  int iVar3;

  u32 uStack_10;

  int iStack_c;

  u32 uStack_8;

  int iStack_4;

  

  puVar1 = *(u32 **)(param_1 + 8);

  puVar1[0x18] = (*(int *)(param_1 + 0x38) << 5) >> 7;

  for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {

    FUN_003b4b40(puVar1 + 1,puVar1 + 0x11,iVar2 * 4 + 0x6a2100,iVar2 * 4 + 0x6a2110,

                 *(u32 *)(param_1 + 0xc),param_2);

  }

  iStack_c = *(int *)(param_1 + 0x14);

  if (*(int *)(param_1 + 0x1c) - iStack_c < 0x569) {

    FUN_003b4e90(param_1 + 0x10,0x6a1d00,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),*puVar1,0,

                 param_2);

  }

  else {

    iVar3 = iStack_c + 0x2b4;

    iVar2 = *(int *)(param_1 + 0x1c) + -0x2b4;

    uStack_10 = *(u32 *)(param_1 + 0x10);

    uStack_8 = *(u32 *)(param_1 + 0x18);

    iStack_4 = iVar3;

    FUN_003b4e90(&uStack_10,0x6a1cd0,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2

                );

    iStack_c = iVar3;

    iStack_4 = iVar2;

    FUN_003b4e90(&uStack_10,0x6a1ce0,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2

                );

    iStack_4 = *(u32 *)(param_1 + 0x1c);

    iStack_c = iVar2;

    FUN_003b4e90(&uStack_10,0x6a1cf0,param_1 + 0x2c,*(u32 *)(param_1 + 0xc),*puVar1,0,param_2

                );

  }

  return;

}
#define FUN_003ac350(...) ((void (*)(...))FUN_003ac350)(__VA_ARGS__)
#undef FUN_003ac500
// FUN_003AC500


void FUN_003ac500(int param_1,u64 param_2)



{

  int iVar1;
  int iVar2;
  u32 *p;
  u32 auStack_10[4];

  


  p = (u32 *)param_1;
  iVar1 = p[0xe] * 0x67;

  iVar2 = iVar1 >> 7;
  if (iVar1 < 0) {
    iVar1 = iVar1 + 0x7f;
    iVar2 = iVar1 >> 7;
  }

  *(u32 *)DAT_006a212c_abs = iVar2;

  auStack_10[0] = p[4];
  auStack_10[1] = p[5];
  auStack_10[2] = p[6];
  auStack_10[3] = p[7];
  asm volatile("" : "+m"(auStack_10));

  FUN_003b4d10(auStack_10,(u32 *)(DAT_006a212c_abs - 0xc),p[3],0x240,param_2);

  return;

}
#define FUN_003ac500(...) ((void (*)(...))FUN_003ac500)(__VA_ARGS__)
#undef FUN_003ac590
// FUN_003AC590
void FUN_003ac590(void)
{
  return;
}
#define FUN_003ac590(...) ((void (*)(...))FUN_003ac590)(__VA_ARGS__)
#undef FUN_003ac5a0
// FUN_003AC5A0
u64 FUN_003ac5a0(int param_1,int param_2)
{
  u8 *pbVar1;
  u8 bVar2;
  u8 bVar3;
  pbVar1 = (u8 *)(*(int *)((int)param_2 + 0x18));
  pbVar1 = (u8 *)(*(int *)((int)param_2 + 0x10) + (int)pbVar1);
  bVar2 = pbVar1[0] - 1;
  bVar3 = pbVar1[1];
  if (bVar3 == 0xff) {
    bVar3 = 0;
  } else {
    bVar3 = bVar3 - 1;
  }
  *(u8 *)((int)param_2 + 0xd) = bVar3 << 8 | bVar2;
  return 0;
}
#define FUN_003ac5a0(...) ((u64 (*)(...))FUN_003ac5a0)(__VA_ARGS__)
#undef FUN_003ac600
// FUN_003AC600


u64 FUN_003ac600(int param_1,int param_2)



{

  u8 *pbVar3;

  u8 bVar1;

  u32 uVar2;

  u8 uVar4;
  u16 index;

  

  pbVar3 = (u8 *)(*(int *)((int)param_2 + 0x18));
  pbVar3 = (u8 *)(*(int *)((int)param_2 + 0x10) + (int)pbVar3);

  uVar4 = *pbVar3 - 1 & 0xff;

  bVar1 = pbVar3[1];

  if (bVar1 == 0xff) {

    uVar2 = 0;

  }

  else {

    uVar2 = (u32)(u8)(bVar1 - 1);

  }
  index = (u8)uVar2 << 8 | (u8)uVar4;

  if (DAT_0095ac70_abs[index] != 0) {

    FUN_003b22a0(param_2);

    FUN_003b1d90(index & 0xff,param_2);

  }

  return 0;

}
// FUN_003AC6C0
u64 FUN_003ac6c0(u64 param_1,u64 param_2)
{
  uGpffffa7f8 = uGpffffa7f8 | 1;
  return 1;
}

// FUN_003AC6E0
u64 FUN_003ac6e0(u64 param_1,u64 param_2)
{
  return 0;
}

// FUN_003AC6F0
u64 FUN_003ac6f0(int param_1,int param_2)
{
  u8 *pbVar1;
  u8 bVar2;
  u8 bVar3;

  pbVar1 = (u8 *)(*(int *)((int)param_2 + 0x18));
  pbVar1 = (u8 *)(*(int *)((int)param_2 + 0x10) + (int)pbVar1);
  bVar2 = pbVar1[0] - 1;
  bVar3 = pbVar1[1];
  if (bVar3 == 0xff) {
    bVar3 = 0;
  } else {
    bVar3 = bVar3 - 1;
  }
  *(u8 *)((int)param_2 + 0xc) = bVar3 << 8 | bVar2;
  return 0;
}

// FUN_003AC750
u64 FUN_003ac750(int param_1,int param_2)
{
  u8 *pbVar1;
  u8 bVar2;
  u8 bVar3;

  pbVar1 = (u8 *)(*(int *)((int)param_2 + 0x18));
  pbVar1 = (u8 *)(*(int *)((int)param_2 + 0x10) + (int)pbVar1);
  bVar2 = pbVar1[0] - 1;
  bVar3 = pbVar1[1];
  if (bVar3 == 0xff) {
    bVar3 = 0;
  } else {
    bVar3 = bVar3 - 1;
  }
  *(u8 *)((int)param_2 + 0xf) = bVar3 << 8 | bVar2;
  return 0;
}

// FUN_003AC7B0
u64 FUN_003ac7b0(u64 param_1,u64 param_2)
{
  return 0;
}

// FUN_003AC7C0
u64 FUN_003ac7c0(int param_1,int param_2)
{
  u8 *pbVar1;
  u8 bVar2;
  u8 bVar3;

  pbVar1 = (u8 *)(*(int *)((int)param_2 + 0x18));
  pbVar1 = (u8 *)(*(int *)((int)param_2 + 0x10) + (int)pbVar1);
  bVar2 = pbVar1[0] - 1;
  bVar3 = pbVar1[1];
  if (bVar3 == 0xff) {
    bVar3 = 0;
  } else {
    bVar3 = bVar3 - 1;
  }
  *(u8 *)((int)param_2 + 0xe) = bVar3 << 8 | bVar2;
  return 0;
}
#define FUN_003ac600(...) ((u64 (*)(...))FUN_003ac600)(__VA_ARGS__)
#undef FUN_003ac820
// FUN_003AC820


u64 FUN_003ac820(u64 param_1,u64 param_2)



{

  u32 uVar1;

  u8 auStack_8 [8];

  uVar1 = FUN_00177670(1);

  FUN_00523ac8((char *)auStack_8,&DAT_007cd520,uVar1);

  FUN_003b22a0(param_2);

  FUN_003b2020(auStack_8,param_2);

  return 0;

}
#define FUN_003ac820(...) ((u64 (*)(...))FUN_003ac820)(__VA_ARGS__)
#undef FUN_003ac890
// FUN_003AC890


u64 FUN_003ac890(u64 param_1,u64 param_2)



{

  u32 uVar1;

  u8 auStack_8 [8];

  uVar1 = FUN_00177790(1);

  FUN_00523ac8((char *)auStack_8,&DAT_007cd520,uVar1);

  FUN_003b22a0(param_2);

  FUN_003b2020(auStack_8,param_2);

  return 0;

}
#define FUN_003ac890(...) ((u64 (*)(...))FUN_003ac890)(__VA_ARGS__)
#undef FUN_003ac900
// FUN_003AC900 NONMATCHING


u64 FUN_003ac900(u64 param_1,int param_2)
{
  u32 lVar1;
  u32 uVar2;
  char auStack_20[16];

  lVar1 = FUN_0017d800();
  if (lVar1 == 0) {
    uVar2 = FUN_00177790(1);
    FUN_00523ac8(auStack_20,gp0xffffa830,uVar2);
    FUN_003b22a0(param_2);
    FUN_003b2020(auStack_20,param_2);
    auStack_20[0] = 0x83;
    auStack_20[1] = 0xf7;
    auStack_20[2] = 0;
    FUN_003b22a0(param_2);
    FUN_003b2020(auStack_20,param_2);
    uVar2 = FUN_00177670(1);
    FUN_00523ac8(auStack_20,gp0xffffa830,uVar2);
    FUN_003b22a0(param_2);
    FUN_003b2020(auStack_20,param_2);
  } else {
    uVar2 = FUN_00177670(1);
    FUN_00523ac8(auStack_20,gp0xffffa830,uVar2);
    FUN_003b22a0(param_2);
    FUN_003b2020(auStack_20,param_2);
  }
  return 0;
}
#define FUN_003ac900(...) ((u64 (*)(...))FUN_003ac900)(__VA_ARGS__)
// Retail 0x003aca30-0x003aca38
// FUN_003ACA30
u64 FUN_003aca30(u64 param_1,u64 param_2)
{
  return 0;
}

// Retail 0x003aca40-0x003aca48
// FUN_003ACA40
u64 FUN_003aca40(u64 param_1,u64 param_2)
{
  return 0;
}
#undef FUN_003aca50
// FUN_003ACA50


u64 FUN_003aca50(u64 param_1,u64 param_2)



{

  if ((DAT_007cd500 & 4) == 0) {

    FUN_003b2400(param_2);

  }

  return 0;

}
#define FUN_003aca50(...) ((u64 (*)(...))FUN_003aca50)(__VA_ARGS__)
// FUN_003ACA90
u64 FUN_003aca90(u64 param_1,u64 param_2)
{
  DAT_007cd4e8 = DAT_007cd4e8 | 2;
  return 0;
}
#undef FUN_003acab0
// FUN_003ACAB0


#pragma push
#pragma opt_rebuildconditionals off
u32 FUN_003acab0(u64 param_1,u64 param_2)
{
  u32 uVar1;

  if ((DAT_007cd500 & 8) == 0) goto clearcase;
  DAT_007cd4e8 = DAT_007cd4e8 | 1;
  uVar1 = 1;
  goto done;
clearcase:
  if ((DAT_007cd500 & 0x20) != 0) {
    FUN_003b2400(param_2);
  }
  uVar1 = 0;
done:
  return uVar1;
}
#pragma pop

// FUN_003ACB10
u64 FUN_003acb10(int param_1,int param_2)
{
  u8 *pbVar1;
  u8 bVar2;
  u8 bVar3;

  pbVar1 = (u8 *)(*(int *)(param_2 + 0x18));
  pbVar1 = (u8 *)(*(int *)(param_2 + 0x10) + (int)pbVar1);
  bVar2 = pbVar1[0] - 1;
  bVar3 = pbVar1[1];
  if (bVar3 == 0xff) {
    bVar3 = 0;
  } else {
    bVar3 = bVar3 - 1;
  }
  *(u8 *)(param_2 + 0xf) = bVar3 << 8 | bVar2;
  pbVar1 = (u8 *)(*(int *)(param_2 + 0x18));
  pbVar1 = (u8 *)((int)pbVar1 + *(int *)(param_2 + 0x10));
  bVar2 = pbVar1[2] - 1;
  bVar3 = pbVar1[3];
  if (bVar3 == 0xff) {
    bVar3 = 0;
  } else {
    bVar3 = bVar3 - 1;
  }
  *(u16 *)(param_2 + 0x1e) = bVar3 << 8 | bVar2;
  return 0;
}
#define FUN_003acab0(...) ((u32 (*)(...))FUN_003acab0)(__VA_ARGS__)
#undef FUN_003acbc0
// FUN_003ACBC0 NONMATCHING


u64 FUN_003acbc0(u64 param_1,int param_2)



{

  u8 bVar1;

  char cVar2;

  u32 uVar3;

  u32 uVar4;

  u32 uVar5;

  long lVar6;

  u8 *pbVar7;

  int iVar8;

  u8 auStack_40 [64];

  

  pbVar7 = (u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18));

  bVar1 = pbVar7[1];

  if (bVar1 == 0xff) {

    uVar3 = 0;

  }

  else {

    uVar3 = (u32)(u8)(bVar1 - 1);

  }

  uVar3 = uVar3 << 8 | *pbVar7 - 1 & 0xff;

  iVar8 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

  cVar2 = *(char *)(iVar8 + 3);

  if (cVar2 == -1) {

    uVar4 = 0;

  }

  else {

    uVar4 = (u32)(u8)(cVar2 - 1);

  }

  uVar4 = uVar4 << 8 | *(u8 *)(iVar8 + 2) - 1 & 0xff;

  iVar8 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

  cVar2 = *(char *)(iVar8 + 5);

  if (cVar2 == -1) {

    uVar5 = 0;

  }

  else {

    uVar5 = (u32)(u8)(cVar2 - 1);

  }

  uVar5 = uVar5 << 8 | *(u8 *)(iVar8 + 4) - 1 & 0xff;

  lVar6 = FUN_0016f190(0x184);

  if (lVar6 != 0) {

    if (uVar3 < 0x191) {

      FUN_00523ac8(auStack_40,0x6a25e0,uVar3,uVar4,uVar3,uVar4,uVar5);

    }

    else if ((400 < uVar3) && (uVar3 < 0x1f5)) {

      FUN_00523ac8(auStack_40,0x6a2610,uVar3,uVar4 / 0x14,uVar3,uVar4,uVar5);

    }

    FUN_0010a370(2,auStack_40);

  }

  return 0;

}
#define FUN_003acbc0(...) ((u64 (*)(...))FUN_003acbc0)(__VA_ARGS__)
#undef FUN_003acda0
// FUN_003ACDA0 NONMATCHING


u64 FUN_003acda0(u64 param_1,int param_2)



{

  u8 bVar1;

  u8 bVar2;

  u32 uVar3;

  long lVar4;

  u8 *pbVar5;

  

  pbVar5 = (u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18));

  bVar1 = *pbVar5;

  bVar2 = pbVar5[1];

  if (bVar2 == 0xff) {

    uVar3 = 0;

  }

  else {

    uVar3 = (u32)(u8)(bVar2 - 1);

  }

  lVar4 = FUN_0016f190(0x184);

  if ((lVar4 != 0) && ((DAT_007cd500 & 0x100) == 0)) {

    FUN_0010a2e0(2,2,uVar3 << 8 | bVar1 - 1 & 0xff);

  }

  return 0;

}
#define FUN_003acda0(...) ((u64 (*)(...))FUN_003acda0)(__VA_ARGS__)
#undef FUN_003ace60
// FUN_003ACE60 NONMATCHING


u64 FUN_003ace60(u64 param_1,int param_2)



{

  u8 bVar1;

  u8 bVar2;

  char cVar3;

  u32 uVar4;

  u32 uVar5;

  long lVar6;

  u8 *pbVar7;

  int iVar8;

  

  pbVar7 = (u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18));

  bVar1 = *pbVar7;

  bVar2 = pbVar7[1];

  if (bVar2 == 0xff) {

    uVar4 = 0;

  }

  else {

    uVar4 = (u32)(u8)(bVar2 - 1);

  }

  iVar8 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

  bVar2 = *(u8 *)(iVar8 + 2);

  cVar3 = *(char *)(iVar8 + 3);

  if (cVar3 == -1) {

    uVar5 = 0;

  }

  else {

    uVar5 = (u32)(u8)(cVar3 - 1);

  }

  lVar6 = FUN_0016f190(0x184);

  if ((lVar6 != 0) && ((DAT_007cd500 & 0x100) == 0)) {

    FUN_0010a2e0(uVar4 << 8 | bVar1 - 1 & 0xff,2,uVar5 << 8 | bVar2 - 1 & 0xff);

  }

  return 0;

}
#define FUN_003ace60(...) ((u64 (*)(...))FUN_003ace60)(__VA_ARGS__)
#undef FUN_003acf80
// FUN_003ACF80 NONMATCHING


u64 FUN_003acf80(u64 param_1,int param_2)



{

  u8 bVar1;

  u8 bVar2;

  u32 uVar3;

  long lVar4;

  u8 *pbVar5;

  

  pbVar5 = (u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18));

  bVar1 = *pbVar5;

  bVar2 = pbVar5[1];

  if (bVar2 == 0xff) {

    uVar3 = 0;

  }

  else {

    uVar3 = (u32)(u8)(bVar2 - 1);

  }

  lVar4 = FUN_0016f190(0x184);

  if (lVar4 != 0) {

    FUN_0010a2e0(2,2,uVar3 << 8 | bVar1 - 1 & 0xff);

  }

  return 0;

}
#define FUN_003acf80(...) ((u64 (*)(...))FUN_003acf80)(__VA_ARGS__)
#undef FUN_003ad030
// FUN_003AD030 NONMATCHING


u64 FUN_003ad030(u64 param_1,int param_2)



{

  u8 bVar1;

  u8 bVar2;

  char cVar3;

  u32 uVar4;

  u32 uVar5;

  long lVar6;

  u8 *pbVar7;

  int iVar8;

  

  pbVar7 = (u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18));

  bVar1 = *pbVar7;

  bVar2 = pbVar7[1];

  if (bVar2 == 0xff) {

    uVar4 = 0;

  }

  else {

    uVar4 = (u32)(u8)(bVar2 - 1);

  }

  iVar8 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

  bVar2 = *(u8 *)(iVar8 + 2);

  cVar3 = *(char *)(iVar8 + 3);

  if (cVar3 == -1) {

    uVar5 = 0;

  }

  else {

    uVar5 = (u32)(u8)(cVar3 - 1);

  }

  lVar6 = FUN_0016f190(0x184);

  if (lVar6 != 0) {

    FUN_0010a2e0(uVar4 << 8 | bVar1 - 1 & 0xff,2,uVar5 << 8 | bVar2 - 1 & 0xff);

  }

  return 0;

}
#define FUN_003ad030(...) ((u64 (*)(...))FUN_003ad030)(__VA_ARGS__)
// Retail 0x003ad130-0x003ad1ac
// FUN_003AD130
u64 FUN_003ad130(u32 param_1,int param_2)
{
  u8 low;
  u8 high;
  u32 value;
  u8 *data;
  int offset;
  int base;

  if (*(int *)(*(int *)(param_2 + 0x14) + 0x34) != 0) {
    *(u32 *)(*(int *)(param_2 + 0x14) + 0x38) = 1;
  }
  *(u32 *)(*(int *)(param_2 + 0x14) + 0x30) = param_1;
  offset = *(volatile int *)(param_2 + 0x18);
  base = *(volatile int *)(param_2 + 0x10);
  base = base + offset;
  data = (u8 *)base;
  low = data[0] - 1;
  high = data[1];
  if (high == 0xff) {
    high = 0;
  } else {
    high = high - 1;
  }
  value = (u32)high << 8 | low & 0xff;
  *(u32 *)(*(int *)(param_2 + 0x14) + 0x3c) = value;
  return 0;
}
#undef FUN_003ad1b0
// FUN_003AD1B0 NONMATCHING


u64 FUN_003ad1b0(u32 param_1,int param_2)



{

  u8 bVar1;

  long lVar2;

  u8 *pbVar3;

  

  if (*(int *)(*(int *)(param_2 + 0x14) + 0x34) != 0) {

    *(u32 *)(*(int *)(param_2 + 0x14) + 0x38) = 1;

  }

  *(u32 *)(*(int *)(param_2 + 0x14) + 0x30) = param_1;

  lVar2 = FUN_0016f190(0x184);

  if (lVar2 == 0) {

    *(u32 *)(*(int *)(param_2 + 0x14) + 0x3c) = 0x23;

  }

  else {

    pbVar3 = (u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18));

    bVar1 = pbVar3[1];

    if (bVar1 == 0xff) {

      bVar1 = 0;

    }

    else {

      bVar1 = bVar1 - 1;

    }

    *(int *)(*(int *)(param_2 + 0x14) + 0x3c) =

         (int)(short)((u16)bVar1 << 8 | *pbVar3 - 1 & 0xff);

  }

  if (*(int *)(*(int *)(param_2 + 0x14) + 0x3c) < 0) {

    *(u32 *)(*(int *)(param_2 + 0x14) + 0x3c) = 0;

  }

  return 0;

}
#define FUN_003ad1b0(...) ((u64 (*)(...))FUN_003ad1b0)(__VA_ARGS__)
// Retail 0x003ad2a0-0x003ad354
// FUN_003AD2A0
u64 FUN_003ad2a0(u64 param_1,int param_2)
{
  u8 low;
  u8 high;
  u32 value;
  u8 *data;
  int offset;
  int base;

  offset = *(volatile int *)(param_2 + 0x18);
  base = *(volatile int *)(param_2 + 0x10);
  base = base + offset;
  data = (u8 *)base;
  low = data[0] - 1;
  high = data[1];
  if (high == 0xff) {
    high = 0;
  } else {
    high = high - 1;
  }
  value = (u32)high << 8 | low & 0xff;
  gp0xffffb938 = value;

  offset = *(volatile int *)(param_2 + 0x18);
  base = *(volatile int *)(param_2 + 0x10);
  data = (u8 *)(offset + base);
  low = data[2] - 1;
  high = data[3];
  if (high == 0xff) {
    high = 0;
  } else {
    high = high - 1;
  }
  value = (u32)high << 8 | low & 0xff;
  gp0xffffb93c = value;
  uGpffffa7f8 = uGpffffa7f8 | 8;
  return 0;
}

// Retail 0x003ad360-0x003ad370
// FUN_003AD360
u64 FUN_003ad360(u32 param_1,int param_2)
{
  *(u32 *)(*(int *)(param_2 + 0x14) + 0x34) = param_1;
  return 0;
}

// Retail 0x003ad380-0x003ad3f0
// FUN_003AD380
u64 FUN_003ad380(u64 param_1,int param_2)
{
  u8 low;
  u8 high;
  u32 value;
  u8 *data;
  int offset;
  int base;

  offset = *(volatile int *)(param_2 + 0x18);
  base = *(volatile int *)(param_2 + 0x10);
  base = base + offset;
  data = (u8 *)base;
  low = data[0] - 1;
  high = data[1];
  if (high == 0xff) {
    high = 0;
  } else {
    high = high - 1;
  }
  value = (u32)high << 8 | low & 0xff;
  if (value != 0) {
    return 0;
  }
  gp0xffffb944 = 0x14;
  return 0;
}
#undef FUN_003ad400
// FUN_003AD400 NONMATCHING


u64 FUN_003ad400(u16 param_1,u16 param_2,u64 param_3,u32 param_4)



{

  u8 uVar1;

  int iVar2;

  long lVar3;

  u64 uVar4;

  u32 uVar5;
  u32 iVar6;

  int iVar7;

  int cVar8;

  u8 msg[3];

  

  iVar6 = (int)param_4;

  cVar8 = '\0';

  iVar7 = 0;

  uVar1 = *(u8 *)(iVar6 + 0xd);

  *(u8 *)(iVar6 + 0xd) = 3;

  lVar3 = FUN_00171250(param_1);

  switch ((int)lVar3) {
  case 0:
    iVar2 = FUN_00170d60(param_1);
    if ((*(u32 *)(iVar2 + 4) & 0xff00) != 0) {
      iVar7 = 8;
    }
    uVar5 = *(u32 *)(iVar2 + 4) >> iVar7;
    if ((uVar5 & 1) == 0) {
      if ((uVar5 & 2) == 0) {
        if ((uVar5 & 4) == 0) {
          if ((uVar5 & 8) == 0) {
            if ((uVar5 & 0x10) == 0) {
              if ((uVar5 & 0x20) == 0) {
                if ((uVar5 & 0x40) == 0) {
                  if ((uVar5 & 0x80) != 0) {
                    cVar8 = '\a';
                  }
                } else {
                  cVar8 = '\x06';
                }
              } else {
                cVar8 = '\x05';
              }
            } else {
              cVar8 = '\x04';
            }
          } else {
            cVar8 = '\x03';
          }
        } else {
          cVar8 = '\x02';
        }
      } else {
        cVar8 = '\x01';
      }
    } else {
      cVar8 = '\0';
    }
    break;
  case 1:
    cVar8 = '\t';
    break;
  case 2:
    cVar8 = '\n';
    break;
  case 3:
    cVar8 = '\v';
    break;
  case 4:
    cVar8 = '\r';
    break;
  }

  msg[0] = 0x83;
  msg[1] = cVar8 + -0x38;
  msg[2] = 0;
  FUN_003b22a0(param_4);
  FUN_003b2020(msg,param_4);

  FUN_003b22a0(param_4);

  uVar4 = FUN_00171110(param_1,param_2);

  FUN_003b2020(uVar4,param_4);

  *(u8 *)(iVar6 + 0xd) = uVar1;

  return 0;

}
#define FUN_003ad400(...) ((u64 (*)(...))FUN_003ad400)(__VA_ARGS__)
#undef FUN_003ad640
// FUN_003AD640 NONMATCHING


u64 FUN_003ad640(u64 param_1,u64 param_2)



{

  u8 bVar1;

  u8 uVar2;

  u32 uVar3;

  u8 *pbVar4;

  u32 uVar5;

  int iVar6;

  u8 uStack_8;

  u8 uStack_7;

  u8 uStack_6;

  

  iVar6 = (int)param_2;

  pbVar4 = (u8 *)(*(int *)(iVar6 + 0x10) + *(int *)(iVar6 + 0x18));

  uVar5 = *pbVar4 - 1 & 0xff;

  bVar1 = pbVar4[1];

  if (bVar1 == 0xff) {

    uVar3 = 0;

  }

  else {

    uVar3 = (u32)(u8)(bVar1 - 1);

  }

  if (*(int *)(&DAT_0095ac70 + (uVar3 << 8 | uVar5) * 4) != 0) {

    uVar2 = *(u8 *)(iVar6 + 0xd);

    *(u8 *)(iVar6 + 0xd) = 3;

    uStack_8 = 0x83;

    uStack_7 = 0xd5;

    uStack_6 = 0;

    FUN_003b22a0(param_2);

    FUN_003b2020(&uStack_8,param_2);

    FUN_003b22a0(param_2);

    FUN_003b1d90(uVar5,param_2);

    *(u8 *)(iVar6 + 0xd) = uVar2;

  }

  return 0;

}
#define FUN_003ad640(...) ((u64 (*)(...))FUN_003ad640)(__VA_ARGS__)
#undef FUN_003ad740
// FUN_003AD740 NONMATCHING


u64 FUN_003ad740(int param_1,int param_2)



{

  u8 bVar1;

  char cVar2;

  u32 uVar3;

  u32 uVar4;

  u8 *pbVar5;

  int iVar6;

  u32 uVar7;

  u32 uVar8;

  

  pbVar5 = (u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18));

  bVar1 = pbVar5[1];

  if (bVar1 == 0xff) {

    uVar3 = 0;

  }

  else {

    uVar3 = (u32)(u8)(bVar1 - 1);

  }

  iVar6 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

  cVar2 = *(char *)(iVar6 + 3);

  if (cVar2 == -1) {

    uVar4 = 0;

  }

  else {

    uVar4 = (u32)(u8)(cVar2 - 1);

  }

  uVar7 = 0;

  uVar8 = 0;

  if (*(u32 **)(&DAT_0095ac70 + (uVar3 << 8 | *pbVar5 - 1 & 0xff) * 4) != (u32 *)0x0)

  {

    uVar8 = **(u32 **)(&DAT_0095ac70 + (uVar3 << 8 | *pbVar5 - 1 & 0xff) * 4);

  }

  if (*(u32 **)(&DAT_0095ac70 + (uVar4 << 8 | *(u8 *)(iVar6 + 2) - 1 & 0xff) * 4) !=

      (u32 *)0x0) {

    uVar7 = **(u32 **)(&DAT_0095ac70 + (uVar4 << 8 | *(u8 *)(iVar6 + 2) - 1 & 0xff) * 4);

  }

  FUN_003ad400(uVar7,uVar8,param_1);

  return 0;

}
#define FUN_003ad740(...) ((u64 (*)(...))FUN_003ad740)(__VA_ARGS__)
#undef FUN_003ad860
// FUN_003AD860


u64 FUN_003ad860(u64 param_1,int param_2)



{

  u8 bVar1;

  u8 uVar2;
  u32 uVar3;
  u32 index32;
  u16 index;

  u8 *pbVar4;

  u32 uVar5;

  int iVar6;
  int offset;

  int base;

  

  iVar6 = (int)param_2;

  offset = *(volatile int *)(iVar6 + 0x18);

  base = *(volatile int *)(iVar6 + 0x10);

  pbVar4 = (u8 *)(base + offset);

  uVar5 = *(volatile u8 *)pbVar4;
  uVar5 = uVar5 - 1 & 0xff;
  bVar1 = *(volatile u8 *)(pbVar4 + 1);

  if (bVar1 == 0xff) {

    uVar3 = 0;

  }

  else {

    uVar3 = (u32)(u8)(bVar1 - 1);

  }
  index32 = (u8)uVar3 << 8;
  index32 |= (u8)uVar5;
  index = index32;

  if (DAT_0095ac70_abs[index] != 0) {

    uVar2 = *(u8 *)(iVar6 + 0xd);

    *(u8 *)(iVar6 + 0xd) = 3;

    FUN_003b22a0(param_2);

    FUN_003b1d90(index & 0xff,param_2);

    *(u8 *)(iVar6 + 0xd) = uVar2;

  }

  return 0;

}
#define FUN_003ad860(...) ((u64 (*)(...))FUN_003ad860)(__VA_ARGS__)
#undef FUN_003ad930
// FUN_003AD930


u64 FUN_003ad930(u64 param_1,int param_2)



{

  u8 bVar1;
  u8 uVar2;

  u32 uVar3;
  u32 index32;
  u16 index;

  u8 *pbVar4;

  u32 uVar5;

  int iVar6;
  int offset;

  int base;

  

  iVar6 = (int)param_2;

  offset = *(volatile int *)(iVar6 + 0x18);

  base = *(volatile int *)(iVar6 + 0x10);

  pbVar4 = (u8 *)(base + offset);

  uVar5 = *(volatile u8 *)pbVar4;
  uVar5 = uVar5 - 1 & 0xff;
  bVar1 = *(volatile u8 *)(pbVar4 + 1);

  if (bVar1 == 0xff) {

    uVar3 = 0;

  }

  else {

    uVar3 = (u32)(u8)(bVar1 - 1);

  }
  index32 = (u8)uVar3 << 8;
  index32 |= (u8)uVar5;
  index = index32;

  if (DAT_0095ac70_abs[index] != 0) {

    uVar2 = *(u8 *)(iVar6 + 0xd);

    *(u8 *)(iVar6 + 0xd) = 3;

    FUN_003b22a0(param_2);

    FUN_003b1d90(index & 0xff,param_2);

    *(u8 *)(iVar6 + 0xd) = uVar2;

  }

  return 0;

}
#define FUN_003ad930(...) ((u64 (*)(...))FUN_003ad930)(__VA_ARGS__)
#undef FUN_003ada00
// FUN_003ADA00 NONMATCHING


u64 FUN_003ada00(u64 param_1,int param_2)



{

  char msg[8];

  int bVar7;

  u8 uVar2;

  u64 uVar3;

  u8 *pbVar4;

  int iVar5;

  u8 bVar6;

  u8 bVar1;
  int offset;
  int base;

  

  iVar5 = param_2;

  offset = *(volatile int *)(iVar5 + 0x18);
  base = *(int *)(iVar5 + 0x10);
  pbVar4 = (u8 *)(base + offset);

  bVar1 = *pbVar4 - 1;

  bVar6 = pbVar4[1];

  if (bVar6 == 0xff) {

    bVar7 = 0;

  }

  else {

    bVar7 = (bVar6 - 1) & 0xff;

  }

  msg[0] = 0x83;

  msg[1] = 0xd5;

  msg[2] = 0;

  uVar2 = *(u8 *)(iVar5 + 0xd);

  *(u8 *)(iVar5 + 0xd) = 3;

  FUN_003b22a0(param_2);

  FUN_003b2020(msg,param_2);

  FUN_003b22a0(param_2);

  uVar3 = FUN_00171110((u16)((bVar7 & 0xff) << 8 | bVar1),0);

  FUN_003b2020(uVar3,param_2);

  *(u8 *)(iVar5 + 0xd) = uVar2;

  return 0;

}
#define FUN_003ada00(...) ((u64 (*)(...))FUN_003ada00)(__VA_ARGS__)
#undef FUN_003adb00
// FUN_003ADB00
u64 FUN_003adb00(u64 param_1,int param_2)
{
  u8 low;
  u8 high;
  u8 *data;
  int state;
  int offset;
  int base;

  state = param_2;
  offset = *(volatile int *)(param_2 + 0x18);
  base = *(volatile int *)(param_2 + 0x10);
  base = base + offset;
  data = (u8 *)base;
  low = data[0] - 1;
  high = data[1];
  if (high == 0xff) {
    high = 0;
  } else {
    high = (u8)(high - 1);
  }
  FUN_003ad400_typed((u16)(high << 8 | low),2,param_1,state);
  return 0;
}

#define FUN_003adb00(...) ((u64 (*)(...))FUN_003adb00)(__VA_ARGS__)
#undef FUN_003adb80
// FUN_003ADB80 NONMATCHING


u64 FUN_003adb80(u64 param_1,int param_2)
{
  u32 uVar2;
  u32 uVar4;
  u32 uVar7;
  u32 uVar9;
  int iVar3;
  int iVar8;
  u8 *pbVar6;
  u8 temp;

  iVar3 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);
  temp = *(u8 *)(iVar3 + 5);
  if (temp == 0xff) {
    uVar2 = 0;
  } else {
    uVar2 = (temp - 1) & 0xff;
  }

  pbVar6 = (u8 *)(*(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10));
  temp = pbVar6[1];
  if (temp == 0xff) {
    uVar7 = 0;
  } else {
    uVar7 = (temp - 1) & 0xff;
  }

  iVar8 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);
  temp = *(u8 *)(iVar8 + 3);
  if (temp == 0xff) {
    uVar4 = 0;
  } else {
    uVar4 = (temp - 1) & 0xff;
  }

  temp = *(u8 *)(iVar8 + 7);
  if (temp == 0xff) {
    temp = 0;
  } else {
    temp = temp - 1;
  }

  uVar9 = 0;
  if ((temp == 0) && (*(u8 *)(iVar8 + 6) == 1)) {
    uVar9 = 0x100;
  }

  FUN_003cf160(
      uVar2 << 8 | *(u8 *)(iVar3 + 4) - 1 & 0xff |
      (uVar7 << 8 | *pbVar6 - 1 & 0xff) << 0x10 |
      (uVar4 << 8 | *(u8 *)(iVar8 + 2) - 1 & 0xff) << 8,
      uVar9 | 0x200);
  return 0;
}
#define FUN_003adb80(...) ((u64 (*)(...))FUN_003adb80)(__VA_ARGS__)
#undef FUN_003add00
// FUN_003ADD00
u64 FUN_003add00(void)
{
  FUN_003cf520();
  return 0;
}
#define FUN_003add00(...) ((u64 (*)(...))FUN_003add00)(__VA_ARGS__)
#undef FUN_003add30
// FUN_003ADD30
u64 FUN_003add30(void)
{
  return 0;
}
#define FUN_003add30(...) ((u64 (*)(...))FUN_003add30)(__VA_ARGS__)
#undef FUN_003add40
// FUN_003ADD40 NONMATCHING


u64 FUN_003add40(u64 param_1,int param_2)



{

  char cVar1;

  u32 uVar2;

  int iVar3;

  u32 uVar4;

  u8 *pbVar5;

  u32 uVar6;

  int iVar7;

  

  iVar3 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

  cVar1 = *(char *)(iVar3 + 5);

  if (cVar1 == -1) {

    uVar2 = 0;

  }

  else {

    uVar2 = (u32)(u8)(cVar1 - 1);

  }

  pbVar5 = (u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18));

  uVar6 = (u32)pbVar5[1];

  if (uVar6 == 0xff) {

    uVar6 = 0;

  }

  else {

    uVar6 = uVar6 - 1 & 0xff;

  }

  iVar7 = *(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x10);

  cVar1 = *(char *)(iVar7 + 3);

  if (cVar1 == -1) {

    uVar4 = 0;

  }

  else {

    uVar4 = (u32)(u8)(cVar1 - 1);

  }

  FUN_003cf160(uVar2 << 8 | *(u8 *)(iVar3 + 4) - 1 & 0xff |

               (uVar6 << 8 | *pbVar5 - 1 & 0xff) << 0x10 |

               (uVar4 << 8 | *(u8 *)(iVar7 + 2) - 1 & 0xff) << 8,0);

  return 0;

}
#define FUN_003add40(...) ((u64 (*)(...))FUN_003add40)(__VA_ARGS__)
// Retail 0x003ade60-0x003ade68
// FUN_003ADE60
u64 FUN_003ade60(u64 param_1,int param_2)
{
  return 0;
}
#undef FUN_003ade70
// FUN_003ADE70 NONMATCHING
u64 FUN_003ade70(int param_1,int param_2)
{
  u8 bVar1;
  u8 bVar2;
  u8 bVar3;
  u8 bVar4;
  u16 sVar5;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;

  bVar1 = ((volatile u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18)))[0];
  uVar5 = (u8)(bVar1 - 1);
  bVar2 = ((volatile u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18)))[1];
  if (bVar2 == 0xff) {
    uVar6 = 0;
  } else {
    uVar6 = (u8)(bVar2 - 1);
  }
  uVar5 = (u8)uVar6 << 8 | uVar5 & 0xff;
  bVar3 = ((volatile u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18)))[2];
  uVar7 = (u8)(bVar3 - 1);
  bVar4 = ((volatile u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18)))[3];
  if (bVar4 == 0xff) {
    uVar8 = 0;
    sVar5 = uVar5;
  } else {
    uVar8 = (u8)(bVar4 - 1);
    sVar5 = uVar5;
  }
  FUN_003bb060(sVar5,(u16)(uVar8 << 8 | uVar7 & 0xff));
  return 0;
}
#undef FUN_003adf40
// FUN_003ADF40
u64 FUN_003adf40(void)
{
  return 0;
}
#undef FUN_003adf50
// FUN_003ADF50
u64 FUN_003adf50(void)
{
  return 0;
}
#undef FUN_003adf60
// FUN_003ADF60
u64 FUN_003adf60(void)
{
  return 0;
}
#undef FUN_003adf70
// FUN_003ADF70


u64 FUN_003adf70(u64 param_1,int param_2)



{

  u32 uVar5;
  u8 uVar6;
  u8 bVar2;
  u32 uVar3;
  int uVar4;
  u32 combined;
  int first;
  int second;
  
  first = *(volatile int *)(param_2 + 0x18);
  second = *(volatile int *)(param_2 + 0x10);
  uVar5 = second + first;
  uVar6 = *(u8 *)uVar5 - 1;
  bVar2 = *(u8 *)(uVar5 + 1);
  if (bVar2 == 0xff) {
    uVar3 = 0;
  } else {
    uVar3 = (u32)(u8)(bVar2 - 1);
  }
  uVar3 = uVar3 & 0xff;
  combined = uVar3 << 8;
  uVar3 = combined | uVar6;
  FUN_0017db00();
  uVar4 = FUN_0016dd40();
  FUN_0016e2b0(uVar4,uVar3);

  return 0;

}
#define FUN_003adf70(...) ((u64 (*)(...))FUN_003adf70)(__VA_ARGS__)
#undef FUN_003ae000
// FUN_003AE000 NONMATCHING


u64 FUN_003ae000(u64 param_1,int param_2)



{

  u8 bVar1;

  u32 uVar2;

  u64 uVar3;

  u8 *pbVar4;

  u32 uVar5;

  u32 auStack_20 [4];

  int aiStack_10 [4];

  

  aiStack_10[0] = DAT_006a2640;

  aiStack_10[1] = DAT_006a2644;

  aiStack_10[2] = DAT_006a2648;

  auStack_20[0] = DAT_006a2650;

  auStack_20[1] = DAT_006a2654;

  auStack_20[2] = DAT_006a2658;

  pbVar4 = (u8 *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x18));

  bVar1 = pbVar4[1];

  if (bVar1 == 0xff) {

    uVar2 = 0;

  }

  else {

    uVar2 = (u32)(u8)(bVar1 - 1);

  }

  uVar2 = uVar2 << 8 | *pbVar4 - 1 & 0xff;

  FUN_0017db00();

  uVar3 = FUN_0016dd40();

  FUN_0016e2b0(uVar3,uVar2);

  if (uVar2 != 0) {

    for (uVar5 = 0; (uVar5 < 3 && (aiStack_10[uVar5] < (int)uVar2)); uVar5 = uVar5 + 1) {

    }

    FUN_0010a4e0(0,0,4,*(u16 *)(auStack_20 + uVar5));

  }

  return 0;

}
#define FUN_003ae000(...) ((u64 (*)(...))FUN_003ae000)(__VA_ARGS__)
// Retail 0x003ae140-0x003ae148
// FUN_003AE140
u64 FUN_003ae140(u64 param_1,int param_2)
{
  return 0;
}

// Retail 0x003ae150-0x003ae158
// FUN_003AE150
u64 FUN_003ae150(u64 param_1,int param_2)
{
  return 0;
}
#undef FUN_003ae160
// FUN_003AE160 NONMATCHING


u64 FUN_003ae160(u64 param_1,int param_2)



{

  u8 bVar1;

  u8 bVar2;

  u8 cVar3;

  int iVar4;
  u32 uVar5;
  u32 uVar6;
  int iVar8;
  u32 firstLow;
  u32 secondLow;
  int first2;
  int second2;


  u8 *pbVar7;
  int *piVar10;

  int *piVar9;

  int aiStack_20 [8];

  

  first2 = *(volatile int *)(param_2 + 0x18);
  second2 = *(volatile int *)(param_2 + 0x10);
  iVar8 = second2 + first2;
  pbVar7 = (u8 *)iVar8;

  bVar1 = *pbVar7;
  firstLow = bVar1 - 1 & 0xff;

  bVar2 = pbVar7[1];

  if (bVar2 == 0xff) {

    uVar5 = 0;

  }

  else {

    uVar5 = (u32)(u8)(bVar2 - 1);

  }


  uVar5 = (u8)uVar5 << 8 | (u8)firstLow;
  first2 = *(volatile int *)(param_2 + 0x18);
  second2 = *(volatile int *)(param_2 + 0x10);
  iVar8 = first2 + second2;
  bVar2 = *(u8 *)(iVar8 + 2);
  secondLow = bVar2 - 1 & 0xff;

  cVar3 = *(u8 *)(iVar8 + 3);

  if (cVar3 == 0xff) {

    uVar6 = 0;

  }

  else {

    uVar6 = (u32)(u8)(cVar3 - 1);

  }

  uVar6 = (u8)uVar6 << 8 | (u8)secondLow;
  piVar10 = (int *)DAT_006a2680;
  piVar9 = aiStack_20;

  iVar8 = 5;

  do {

    iVar4 = *piVar10;

    piVar10 = piVar10 + 1;

    iVar8 = iVar8 + -1;

    *piVar9 = iVar4;

    piVar9 = piVar9 + 1;

  } while (0 < iVar8);

  FUN_0016f1f0(uVar6 + aiStack_20[uVar5],1);

  return 0;

}
#define FUN_003ae160(...) ((u64 (*)(...))FUN_003ae160)(__VA_ARGS__)
#undef FUN_003ae260
// FUN_003AE260 NONMATCHING


u64 FUN_003ae260(u64 param_1,int param_2)



{

  u8 bVar1;

  u8 bVar2;

  u8 cVar3;

  int iVar4;

  u32 uVar5;

  u32 uVar6;

  int iVar8;
  u32 firstLow;
  u32 secondLow;
  int first2;
  int second2;


  u8 *pbVar7;
  int *piVar10;

  int *piVar9;

  int aiStack_20 [8];

  

  first2 = *(volatile int *)(param_2 + 0x18);
  second2 = *(volatile int *)(param_2 + 0x10);
  iVar8 = second2 + first2;
  pbVar7 = (u8 *)iVar8;

  bVar1 = *pbVar7;
  firstLow = bVar1 - 1 & 0xff;

  bVar2 = pbVar7[1];

  if (bVar2 == 0xff) {

    uVar5 = 0;

  }

  else {

    uVar5 = (u32)(u8)(bVar2 - 1);

  }


  uVar5 = (u8)uVar5 << 8 | (u8)firstLow;
  first2 = *(volatile int *)(param_2 + 0x18);
  second2 = *(volatile int *)(param_2 + 0x10);
  iVar8 = first2 + second2;
  bVar2 = *(u8 *)(iVar8 + 2);
  secondLow = bVar2 - 1 & 0xff;

  cVar3 = *(u8 *)(iVar8 + 3);

  if (cVar3 == 0xff) {

    uVar6 = 0;

  }

  else {

    uVar6 = (u32)(u8)(cVar3 - 1);

  }

  uVar6 = (u8)uVar6 << 8 | (u8)secondLow;
  piVar10 = (int *)DAT_006a2680;
  piVar9 = aiStack_20;

  iVar8 = 5;

  do {

    iVar4 = *piVar10;

    piVar10 = piVar10 + 1;

    iVar8 = iVar8 + -1;

    *piVar9 = iVar4;

    piVar9 = piVar9 + 1;

  } while (0 < iVar8);

  FUN_0016f1f0(uVar6 + aiStack_20[uVar5],0);
  return 0;

}
#define FUN_003ae260(...) ((u64 (*)(...))FUN_003ae260)(__VA_ARGS__)
#undef FUN_003ae360
// FUN_003AE360


u64 FUN_003ae360(u64 param_1,int param_2)



{

  u8 bVar1;

  u32 uVar2;

  u32 uVar3;

  int iVar3;

  int offset;

  int base;

  u8 *pbVar4;

  

  offset = *(volatile int *)(param_2 + 0x18);

  base = *(volatile int *)(param_2 + 0x10);

  pbVar4 = (u8 *)(base + offset);

  uVar3 = *(volatile u8 *)pbVar4;

  uVar3 = uVar3 - 1 & 0xff;

  bVar1 = *(volatile u8 *)(pbVar4 + 1);

  if (bVar1 == 0xff) {

    uVar2 = 0;

  }

  else {

    uVar2 = (u32)(u8)(bVar1 - 1);

  }

  uVar2 = (uVar2 & 0xff) << 8;

  uVar3 = uVar3 & 0xff;

  uVar2 = uVar2 | uVar3;

  FUN_003b22a0(param_2);

  iVar3 = FUN_0017c860(uVar2);

  offset = iVar3 << 2;

  uVar2 = uVar2 << 4;

  FUN_003b2020(*(u8 **)((u8 *)&PTR_s_Sayonara_006a24d0_abs + uVar2 + offset),param_2);

  return 0;

}
#define FUN_003ae360(...) ((u64 (*)(...))FUN_003ae360)(__VA_ARGS__)
