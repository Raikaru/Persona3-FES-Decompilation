#include "temporary.h"
typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))
typedef struct {
  f32 x;
  f32 y;
  f32 z;
} ItfFloat3;

extern void FUN_0019d3f0(const char *file,s32 line);
extern u32 FUN_00171250(s16 id);
extern u32 FUN_00170d60(s16 id);
extern u64 FUN_00171110(s16 id,s16 field);
extern u32 FUN_00171110_u32(s16 id,s16 field);
#pragma alias FUN_00171110_u32 FUN_00171110
#pragma alias FUN_0052e878_f32 FUN_0052e878
extern f32 FUN_0052e878_f32(f32 value);
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
#pragma alias DAT_006a1fdc_abs DAT_006a1fdc
extern u32 DAT_006a1fdc_abs[];
#pragma alias DAT_006a1fec_abs DAT_006a1fec
extern u32 DAT_006a1fec_abs[];
#pragma alias DAT_006a1ffc_abs DAT_006a1ffc
extern u32 DAT_006a1ffc_abs[];
#pragma alias DAT_006a200c_abs DAT_006a200c
extern u32 DAT_006a200c_abs[];
extern s16 DAT_006a2060[];
extern s16 DAT_006a2080[];
extern u32 DAT_006a20a0;
extern u32 DAT_006a20c0;
extern u8 DAT_006a20e0[];
#pragma alias DAT_006a20e0_abs DAT_006a20e0
extern u8 DAT_006a20e0_abs[];
 
extern u8 DAT_006a20f0[];
#pragma alias DAT_006a20f0_abs DAT_006a20f0
extern u8 DAT_006a20f0_abs[];
extern u8 DAT_006a1ee0[];
extern u8 DAT_006a1ef0[];
#pragma alias DAT_006a1ee0_abs DAT_006a1ee0
extern u8 DAT_006a1ee0_abs[];
#pragma alias DAT_006a1ef0_abs DAT_006a1ef0
extern u8 DAT_006a1ef0_abs[];
extern u8 DAT_006a1f00[];
#pragma alias DAT_006a1f00_abs DAT_006a1f00
extern u8 DAT_006a1f00_abs[];
extern u8 DAT_006a1f20[];
#pragma alias DAT_006a1f20_abs DAT_006a1f20
extern u8 DAT_006a1f20_abs[];
extern u8 DAT_006a1f40[];
#pragma alias DAT_006a1f40_abs DAT_006a1f40
extern u8 DAT_006a1f40_abs[];
extern u8 DAT_006a1f60[];
#pragma alias DAT_006a1f60_abs DAT_006a1f60
extern u8 DAT_006a1f60_abs[];
extern u8 DAT_006a1f80[];
#pragma alias DAT_006a1f80_abs DAT_006a1f80
extern u8 DAT_006a1f80_abs[];
extern u8 DAT_006a1fa0[];
#pragma alias DAT_006a1fa0_abs DAT_006a1fa0
extern u8 DAT_006a1fa0_abs[];
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
#pragma alias DAT_006a2640_vec_abs DAT_006a2640
extern ItfFloat3 DAT_006a2640_vec_abs[];
#pragma alias DAT_006a2650_vec_abs DAT_006a2650
extern ItfFloat3 DAT_006a2650_vec_abs[];
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
extern char gp0xffffa830;
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
void FUN_003a87d0(int param_2,int param_3,float param_1,long param_4,u32 param_5,u32 param_6,  long param_7);
#pragma alias FUN_003a87d0_typed FUN_003a87d0
extern void FUN_003a87d0_typed(int param_2,int param_3,float param_1,void* param_4,
                               u32 param_5,u32 param_6,long param_7);
void FUN_003a8dc0(int param_1,int param_2,int param_3,int param_4,  int param_5,int param_6);
void FUN_003a8d60(int param_1);
void FUN_003a8ea0(u8 *param_1,int param_2,int param_3,int param_4,int param_5,int param_6);
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
void FUN_003a9cf0(int param_1,int param_2,int param_3,int param_4,  u32 param_5);
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
u32 FUN_003acbc0(u64 param_1,int param_2);
u64 FUN_003acb10(int param_1,int param_2);
u64 FUN_003acda0(u64 param_1,int param_2);
u64 FUN_003ace60(u64 param_1,int param_2);
u32 FUN_003acf80(u32 param_1,int param_2);
u32 FUN_003ad030(u64 param_1,int param_2);
u32 FUN_003ad1b0(u32 param_1,int param_2);
u32 FUN_003ad400(u16 param_1,u16 param_2,u64 param_3,u32 param_4);
#pragma alias FUN_003ad400_typed FUN_003ad400
extern u64 FUN_003ad400_typed(u16 param_1,u16 param_2,u64 param_3,int param_4);
#pragma alias FUN_003ad400_three FUN_003ad400
extern u32 FUN_003ad400_three(u16 param_1,u16 param_2,u64 param_3);
u32 FUN_003ad640(u64 param_1,int param_2);
u32 FUN_003ad740(int param_1,int param_2);
u64 FUN_003ad860(u64 param_1,int param_2);
u64 FUN_003ad930(u64 param_1,int param_2);
u32 FUN_003ada00(u64 param_1,int param_2);
u64 FUN_003adb00(u64 param_1,int param_2);
u32 FUN_003adb80(u64 param_1,int param_2);
u64 FUN_003add00(void);
u64 FUN_003add30(void);
u32 FUN_003add40(u64 param_1,int param_2);
u32 FUN_003ade70(int param_1,int param_2);
u64 FUN_003adf70(u64 param_1,int param_2);
u64 FUN_003ae000(u64 param_1,int param_2);
u32 FUN_003ae160(u64 param_1,int param_2);
u32 FUN_003ae260(u64 param_1,int param_2);
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
#define FUN_003a87d0(...) ((void (*)(...))FUN_003a87d0)(__VA_ARGS__)
#undef FUN_003a8b00


#define FUN_003a8b00(...) ((u64 (*)(...))FUN_003a8b00)(__VA_ARGS__)
#undef FUN_003a8d60
#define FUN_003a8d60(...) ((void (*)(...))FUN_003a8d60)(__VA_ARGS__)
#undef FUN_003a8dc0
#define FUN_003a8dc0(...) ((void (*)(...))FUN_003a8dc0)(__VA_ARGS__)
#undef FUN_003a8ea0
#define FUN_003a8ea0(...) ((void (*)(...))FUN_003a8ea0)(__VA_ARGS__)
#undef FUN_003a8fb0
#define FUN_003a8fb0(...) ((void (*)(...))FUN_003a8fb0)(__VA_ARGS__)
#undef FUN_003a9080

#define FUN_003a9080(...) ((void (*)(...))FUN_003a9080)(__VA_ARGS__)
#undef FUN_003a90c0
#define FUN_003a90c0(...) ((void (*)(...))FUN_003a90c0)(__VA_ARGS__)
#undef FUN_003a9140
#define FUN_003a9140(...) ((u64 (*)(...))FUN_003a9140)(__VA_ARGS__)
#undef FUN_003a9170



#define FUN_003a9170(...) ((u64 (*)(...))FUN_003a9170)(__VA_ARGS__)
#undef FUN_003a92a0
#define FUN_003a92a0(...) ((u64 (*)(...))FUN_003a92a0)(__VA_ARGS__)
#undef FUN_003a92d0
#define FUN_003a92d0(...) ((u64 (*)(...))FUN_003a92d0)(__VA_ARGS__)
#undef FUN_003a93a0
#define FUN_003a93a0(...) ((u64 (*)(...))FUN_003a93a0)(__VA_ARGS__)
#undef FUN_003a9400
#define FUN_003a9400(...) ((u64 (*)(...))FUN_003a9400)(__VA_ARGS__)
#undef FUN_003a9470
#define FUN_003a9470(...) ((u64 (*)(...))FUN_003a9470)(__VA_ARGS__)
#undef FUN_003a94e0
#define FUN_003a94e0(...) ((u64 (*)(...))FUN_003a94e0)(__VA_ARGS__)
#undef FUN_003a9510
#define FUN_003a9510(...) ((u64 (*)(...))FUN_003a9510)(__VA_ARGS__)
#undef FUN_003a9580
#define FUN_003a9580(...) ((u64 (*)(...))FUN_003a9580)(__VA_ARGS__)
#undef FUN_003a95f0
#define FUN_003a95f0(...) ((u64 (*)(...))FUN_003a95f0)(__VA_ARGS__)
#undef FUN_003a9630
#define FUN_003a9630(...) ((u64 (*)(...))FUN_003a9630)(__VA_ARGS__)
#undef FUN_003a9670
#define FUN_003a9670(...) ((u64 (*)(...))FUN_003a9670)(__VA_ARGS__)
#undef FUN_003a96b0
#define FUN_003a96b0(...) ((u64 (*)(...))FUN_003a96b0)(__VA_ARGS__)
#undef FUN_003a96f0

#define FUN_003a96f0(...) ((void (*)(...))FUN_003a96f0)(__VA_ARGS__)
#undef FUN_003a9780
#define FUN_003a9780(...) ((void (*)(...))FUN_003a9780)(__VA_ARGS__)
#undef FUN_003a9930
#define FUN_003a9930(...) ((void (*)(...))FUN_003a9930)(__VA_ARGS__)
#undef FUN_003a9af0
#define FUN_003a9af0(...) ((void (*)(...))FUN_003a9af0)(__VA_ARGS__)
#undef FUN_003a9b80
#define FUN_003a9b80(...) ((void (*)(...))FUN_003a9b80)(__VA_ARGS__)
#undef FUN_003a9c30

#define FUN_003a9c30(...) ((void (*)(...))FUN_003a9c30)(__VA_ARGS__)
#undef FUN_003a9c90

#define FUN_003a9c90(...) ((void (*)(...))FUN_003a9c90)(__VA_ARGS__)
#undef FUN_003a9cf0
#define FUN_003a9cf0(...) ((void (*)(...))FUN_003a9cf0)(__VA_ARGS__)


#undef FUN_003a9e20
#define FUN_003a9e20(...) ((void (*)(...))FUN_003a9e20)(__VA_ARGS__)
#undef FUN_003a9ed0
#define FUN_003a9ed0(...) ((void (*)(...))FUN_003a9ed0)(__VA_ARGS__)
#undef FUN_003aa000
#define FUN_003aa000(...) ((void (*)(...))FUN_003aa000)(__VA_ARGS__)
#undef FUN_003aa130
#define FUN_003aa130(...) ((void (*)(...))FUN_003aa130)(__VA_ARGS__)
#undef FUN_003aa280
#define FUN_003aa280(...) ((void (*)(...))FUN_003aa280)(__VA_ARGS__)
#undef FUN_003aa2d0
#define FUN_003aa2d0(...) ((void (*)(...))FUN_003aa2d0)(__VA_ARGS__)
#undef FUN_003aa370
#define FUN_003aa370(...) ((void (*)(...))FUN_003aa370)(__VA_ARGS__)
#undef FUN_003aa720
#define FUN_003aa720(...) ((void (*)(...))FUN_003aa720)(__VA_ARGS__)
#undef FUN_003aaae0
#define FUN_003aaae0(...) ((void (*)(...))FUN_003aaae0)(__VA_ARGS__)
#undef FUN_003ab2a0
#define FUN_003ab2a0(...) ((void (*)(...))FUN_003ab2a0)(__VA_ARGS__)
#undef FUN_003ab320

#define FUN_003ab320(...) ((void (*)(...))FUN_003ab320)(__VA_ARGS__)
#undef FUN_003abb10
#define FUN_003abb10(...) ((void (*)(...))FUN_003abb10)(__VA_ARGS__)

#undef FUN_003ac240
#define FUN_003ac240(...) ((void (*)(...))FUN_003ac240)(__VA_ARGS__)
#undef FUN_003ac350
#define FUN_003ac350(...) ((void (*)(...))FUN_003ac350)(__VA_ARGS__)
#undef FUN_003ac500
#define FUN_003ac500(...) ((void (*)(...))FUN_003ac500)(__VA_ARGS__)
#undef FUN_003ac590
#define FUN_003ac590(...) ((void (*)(...))FUN_003ac590)(__VA_ARGS__)
#undef FUN_003ac5a0
#define FUN_003ac5a0(...) ((u64 (*)(...))FUN_003ac5a0)(__VA_ARGS__)
#undef FUN_003ac600





#define FUN_003ac600(...) ((u64 (*)(...))FUN_003ac600)(__VA_ARGS__)
#undef FUN_003ac820
#define FUN_003ac820(...) ((u64 (*)(...))FUN_003ac820)(__VA_ARGS__)
#undef FUN_003ac890
#define FUN_003ac890(...) ((u64 (*)(...))FUN_003ac890)(__VA_ARGS__)
#undef FUN_003ac900
#define FUN_003ac900(...) ((u64 (*)(...))FUN_003ac900)(__VA_ARGS__)

#undef FUN_003aca50
#define FUN_003aca50(...) ((u64 (*)(...))FUN_003aca50)(__VA_ARGS__)
#undef FUN_003acab0

#define FUN_003acab0(...) ((u32 (*)(...))FUN_003acab0)(__VA_ARGS__)
#undef FUN_003acbc0
#define FUN_003acbc0(...) ((u64 (*)(...))FUN_003acbc0)(__VA_ARGS__)
#undef FUN_003acda0
#define FUN_003acda0(...) ((u64 (*)(...))FUN_003acda0)(__VA_ARGS__)
#undef FUN_003ace60
#define FUN_003ace60(...) ((u64 (*)(...))FUN_003ace60)(__VA_ARGS__)
#undef FUN_003acf80
#define FUN_003acf80(...) ((u64 (*)(...))FUN_003acf80)(__VA_ARGS__)
#undef FUN_003ad030
#define FUN_003ad030(...) ((u64 (*)(...))FUN_003ad030)(__VA_ARGS__)
#undef FUN_003ad1b0
#define FUN_003ad1b0(...) ((u64 (*)(...))FUN_003ad1b0)(__VA_ARGS__)


#undef FUN_003ad400
#define FUN_003ad400(...) ((u64 (*)(...))FUN_003ad400)(__VA_ARGS__)
// measured: the fixed message buffer cuts nd157 to nd1; lint: allow S003
#undef FUN_003ad640
#define FUN_003ad640(...) ((u64 (*)(...))FUN_003ad640)(__VA_ARGS__)
#undef FUN_003ad740
#define FUN_003ad740(...) ((u64 (*)(...))FUN_003ad740)(__VA_ARGS__)
#undef FUN_003ad860
#define FUN_003ad860(...) ((u64 (*)(...))FUN_003ad860)(__VA_ARGS__)
#undef FUN_003ad930
#define FUN_003ad930(...) ((u64 (*)(...))FUN_003ad930)(__VA_ARGS__)
#undef FUN_003ada00
#define FUN_003ada00(...) ((u64 (*)(...))FUN_003ada00)(__VA_ARGS__)
#undef FUN_003adb00

#define FUN_003adb00(...) ((u64 (*)(...))FUN_003adb00)(__VA_ARGS__)
#undef FUN_003adb80
#define FUN_003adb80(...) ((u64 (*)(...))FUN_003adb80)(__VA_ARGS__)
#undef FUN_003add00
#define FUN_003add00(...) ((u64 (*)(...))FUN_003add00)(__VA_ARGS__)
#undef FUN_003add30
#define FUN_003add30(...) ((u64 (*)(...))FUN_003add30)(__VA_ARGS__)
#undef FUN_003add40
#define FUN_003add40(...) ((u64 (*)(...))FUN_003add40)(__VA_ARGS__)
#undef FUN_003ade70
#undef FUN_003adf40
#undef FUN_003adf50
#undef FUN_003adf60
#undef FUN_003adf70
#define FUN_003adf70(...) ((u64 (*)(...))FUN_003adf70)(__VA_ARGS__)
#undef FUN_003ae000
#define FUN_003ae000(...) ((u64 (*)(...))FUN_003ae000)(__VA_ARGS__)

#undef FUN_003ae160
#define FUN_003ae160(...) ((u64 (*)(...))FUN_003ae160)(__VA_ARGS__)
#undef FUN_003ae260
#define FUN_003ae260(...) ((u64 (*)(...))FUN_003ae260)(__VA_ARGS__)
#undef FUN_003ae360
#define FUN_003ae360(...) ((u64 (*)(...))FUN_003ae360)(__VA_ARGS__)
