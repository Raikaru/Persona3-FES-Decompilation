#include "Kernel/Kwln/kwlnTask.h"

/* auto-extern (generated) */
u32 datSocialLinkLevelIsNotZero(s16 socialLink);
u64 FUN_00172660(s32 socialLink);
extern u8 DAT_006aede8[];
extern u32 gp0xffffac10;
extern u32 gp0xfffface0;
typedef int (*code)();
float fGpffff8084;
float fGpffff808c;
float fGpffff8090;
float fGpffff8110;
float fGpffff8230;
float fGpffff8234;
float fGpffff8238;
float fGpffff823c;
int *iGpffffabf8;
int iGpffffabfc;
int iGpffffac00;
int *iGpffffb730;
int *iGpffffb7f4;
int iGpffffb7f8;
extern u8 *pbGpffffabe8;
short *psGpffffabd0;
short *psGpffffabf0;
u32 *puGpffffabe0;
u32 uGpffffabd4;
u32 uGpffffabe4;
extern u32 uGpffffabec;
u32 uGpffffabf4;
u32 uGpffffacf0;
u32 uGpffffacf4;
u32 uGpffffacf8;
u32 uGpffffacfc;
u32 uGpffffad00;
u32 uGpffffad04;
u32 uGpffffb9a8;
/* FUSION_EXACT_PROTOS */
void FUN_003c45f0(int param_1);
u32 datGetScenarioMode(void);
u16 FUN_001752b0(void);
void FUN_003c9e30(u32 param_1,int param_2,s8 param_3);
f32 func_00171510(s16 row, s16 column);
void FUN_003eff00(u64 param_1,u8 *param_2);
u8 * FUN_003efff0(int param_1);
s16 FUN_003f0090(int param_1);
s16 FUN_003f00b0(int param_1);
int FUN_003f00d0(int *param_1,u64 param_2,int *param_3);
void FUN_003f01d0(int param_1,int param_2,int *param_3);
u32 FUN_003f0240(int param_1);
int FUN_003f0350(int param_1,int *param_2);
char FUN_003f03e0(int param_1);
u32 FUN_003f04f0(long param_1,int param_2);
u32 * FUN_003f06e0(int *param_1,u64 param_2);
short FUN_003f0830(int param_1);
short FUN_003f0ac0(int param_1);
long FUN_003f0d60(int param_1,u64 param_2);
u32 FUN_003f0ec0(u64 param_1);
u16 FUN_003f10b0(int param_1,u16 param_2);
u16 FUN_003f12a0(int param_1,int param_2);
u64 FUN_003f1470(int param_1);
void FUN_003f1520(int param_1);
int FUN_003f15d0(int param_1,int param_2);
int FUN_003f1690(u64 param_1);
u16 FUN_003f1720(u32 param_1,u16 param_2);
u32 FUN_003f1830(u16 *param_1,short param_2);
u32 FUN_003f1910(u64 param_1);
u32 FUN_003f1a10(u32 param_1);
void FUN_003f1ba0(long param_1,u32 param_2);
u32 FUN_003f1dc0(u16 param_1,long param_2,long param_3);
u8 FUN_003f2240(long param_1,u16 param_2);
u64 FUN_003f2320(int param_1,int param_2);
u32 FUN_003f2510(void);
u32 FUN_003f25e0(u64 param_1,long param_2,u32 param_3);
u32 FUN_003f2940(u64 param_1,short *param_2,int param_3,u32 param_4);
u64 FUN_003f2d60(int param_1);
u64 FUN_003f2dc0(int param_1,int param_2);
u32 FUN_003f2f70(u64 param_1,long param_2,u32 param_3);
u64 FUN_003f33d0(long param_1,u32 param_2);
u64 FUN_003f3970(long param_1,u32 param_2);
u64 FUN_003f39a0(long param_1,long param_2,u32 param_3);
void FUN_003f3dc0(int param_1,u64 param_2);
u32 FUN_003f3e60(int param_1,u64 param_2);
u32 FUN_003f3f00(u64 param_1);
void FUN_003f3fc0(int param_1,int param_2,u32 param_3,u64 param_4);
void FUN_003f4350(int param_1,int param_2,long param_3,u64 param_4);
void FUN_003f45e0(int param_1,int param_2,long param_3,u64 param_4);
void FUN_003f4870(int param_1,int param_2,long param_3,u64 param_4);
u64 FUN_003f4a90(int param_1,int param_2,int param_3,int param_4,u64 param_5,short *param_6);
void FUN_003f4de0(int param_1,int param_2,u64 param_3,u64 param_4);
void FUN_003f55b0(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5, u32 param_6);
void FUN_003f5830(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5, u32 param_6);
void FUN_003f5ab0(u64 param_1,u64 param_2,u8 param_3,u64 param_4, int param_5);
void FUN_003f5d10(u64 param_1,u64 param_2,u8 param_3,u64 param_4, int param_5);
void FUN_003f5f50(u64 param_1,u64 param_2,u8 param_3,u64 param_4, int param_5);
void FUN_003f61d0(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5);
void FUN_003f67e0(u64 param_1,u64 param_2,u32 param_3,int param_4,u64 param_5, int param_6);
void FUN_003f6f20(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5);
void FUN_003f7390(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5);
void FUN_003f7730(u64 param_1,u64 param_2,u8 param_3,int param_4,int param_5);
void FUN_003f7890(u64 param_1,u64 param_2,u8 param_3,int param_4, u64 param_5,int param_6);
void FUN_003f7a80(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5);
void FUN_003f7c60(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5);
void FUN_003f7d50(u64 param_1,u64 param_2,u64 param_3,u64 param_4, int param_5);
void FUN_003f7fe0(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5 );
void FUN_003f8180(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5 );
void FUN_003f85a0(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_003f86a0(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5 );
void FUN_003f8a00(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5 );
void FUN_003f8e10(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5 );
void FUN_003f9220(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5 );
void FUN_003f9510(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5 );
u32 FUN_003f98f0(u16 param_1);
u64 FUN_003f99d0(u64 param_1,u32 param_2);
u64 FUN_003f9b20(u64 param_1,u64 param_2);
u64 FUN_003f9e30(int param_1);
u32 FUN_003fa0d0(u64 param_1);
u64 FUN_003fa190(int param_1);
u64 FUN_003fa1b0(int param_1);
u8 FUN_003fa1e0(void);
#pragma alias FUN_003fa1e0_u32 FUN_003fa1e0
u32 FUN_003fa1e0_u32(void);
void FUN_003fa210(int param_1);
void FUN_003fa520(int param_1);
void FUN_003fa800(int param_1);
void FUN_003faae0(int param_1);
void FUN_003fadc0(int param_1);
void FUN_003fb0c0(long param_1,long param_2);
int FUN_003fb2f0(u32 *param_1);
int FUN_003fb530(u32 *param_1);
int FUN_003fb6b0(u64 param_1);
u64 FUN_003fbc00(u32 *param_1);
void FUN_003fbe70(u8 *param_1,u8 *param_2);
void FUN_003fbf10(u16 *param_1);
u64 FUN_003fbf20(short *param_1);
u64 FUN_003fc060(int param_1);
#pragma alias FUN_003fc060_u32 FUN_003fc060
u32 FUN_003fc060_u32(int param_1);
#pragma alias FUN_003fc540_u32 FUN_003fc540
u32 FUN_003fc540_u32(int param_1);
u64 FUN_003fc540(int param_1);
u32 FUN_003fc980(int param_1);
void FUN_003fca00(u64 param_1,u64 param_2,u32 param_3);
void FUN_003fcad0(u64 param_1,u64 param_2,u32 param_3,int param_4);
void FUN_003fcbe0(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5);
void FUN_003fcdc0(int param_1,int param_2,u32 param_3,int param_4,int param_5);
void FUN_003fd010(int param_1,int param_2,u32 param_3,int param_4,int param_5);
void FUN_003fd030(u64 param_1,u64 param_2,u32 param_3,int param_4);
void FUN_003fd140(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5);
void FUN_003fd320(int param_1,int param_2,u32 param_3,int param_4,int param_5);
u64 FUN_003fd570(int param_1,u32 *param_2);
u64 FUN_003fd730(u64 param_1,int param_2);
u64 FUN_003fd7e0(u64 param_1,int param_2);
int * FUN_003fd820(int param_1);
void FUN_003fd8a0(u32 *param_1);
void FUN_003fd8e0(int *param_1);
u64 FUN_003fd990(int *param_1);
void FUN_003fdcc0(int param_1,int param_2,int *param_3);
u64 FUN_003fdf80(u64 param_1);
u64 FUN_003fe020(int param_1,u64 param_2);
u8 FUN_003fe1f0(u64 param_1);
u32 FUN_003fe2b0(void);
u64 FUN_003fe3e0(u16 param_1);
u8 FUN_003fe5d0(u64 param_1);
u64 FUN_003fe690(u64 param_1,u64 param_2);
u64 FUN_003fe7d0(u64 param_1,int param_2);
u64 FUN_003fe850(u16 param_1,u64 param_2);
u8 FUN_003fe950(u64 param_1);
u64 FUN_003fea10(u64 param_1,u32 *param_2);
u64 FUN_003feb30(u64 param_1,int param_2);
u64 FUN_003fee40(int param_1);
u64 FUN_003fef30(u64 param_1,long param_2);
u64 FUN_003ff150(u64 param_1,long param_2);
void FUN_003ff460(int param_1,u64 param_2);
u8 FUN_003ff570(u64 param_1);
void FUN_003ff630(u32 param_1,u64 param_2,u64 param_3,u64 param_4, u8 param_5,short param_6,short param_7,u32 param_8);
u8 FUN_003ffa20(u64 param_1,u64 param_2,int param_3);
void FUN_003ffbb0(int param_1,int param_2);
void FUN_003ffe00(int param_1);
int * FUN_003ffe60(u64 param_1);
void FUN_004003a0(int param_1);
u32 FUN_004003f0(int *param_1);
u64 FUN_00400690(u32 *param_1);
void FUN_004006c0(void);
void FUN_00400740(u64 param_1,u64 param_2,u8 param_3,int param_4);
void FUN_004008f0(u64 param_1,u64 param_2,u8 param_3,int param_4);
void FUN_00400a90(int param_1,u64 param_2,int param_3,int param_4,u32 *param_5);
void FUN_00400e30(int param_1);
int FUN_00400d60(void);
u32 FUN_00401210(int param_1);
void FUN_00401170(u64 param_1);
u64 FUN_004012c0(int param_1);
u64 FUN_00401370(int param_1);
void FUN_00401420(int param_1,int param_2);
u32 FUN_004014e0(u64 param_1);
void FUN_004015a0(u32 *param_1,u32 param_2);
u8 FUN_004015e0(u32 *param_1);
int FUN_00401600(u64 param_1,u64 param_2,int param_3);
u32 FUN_004016d0(u64 param_1);
int FUN_00401800(short param_1);
u32 FUN_00401890(short param_1);
u64 FUN_00401950(short param_1);
u32 FUN_00401a00(u16 param_1,long param_2,short *param_3);
u8 * FUN_00401c90(u32 *param_1,int param_2);
u8 * FUN_00401cf0(long param_1);
short * FUN_00401d90(int param_1);
u32 FUN_00401de0(u64 param_1,long param_2,long param_3);
void FUN_00402400(int param_1,u16 *param_2);
u32 FUN_00402480(u16 *param_1);
u32 FUN_00402510(u32 param_1,long param_2,u32 param_3,short param_4);
u32 FUN_004026b0(int param_1,int param_2,u32 param_3);
void FUN_00402800(u64 param_1);
void FUN_00402c80(u64 param_1);
s16 FUN_004030b0(u16 param_1);
s16 FUN_004030f0(u16 param_1);
void FUN_00403130(u64 param_1,u64 param_2,int param_3,u64 param_4, u64 param_5,u64 param_6,u16 param_7);
void FUN_00403220(u64 param_1,u64 param_2,int param_3,u64 param_4, u64 param_5,u64 param_6,u16 param_7);
void FUN_004032f0(u64 param_1);
void FUN_00403340(u16 param_1);
u8 FUN_00403380(u64 param_1);
u8 FUN_00403410(void);
u32 FUN_00403520(void);
int FUN_00403610(void);
s16 FUN_00403740(short param_1);
s16 FUN_00403760(short param_1);
s16 FUN_00403780(short param_1);
s16 FUN_004037a0(short param_1);
s16 FUN_004037c0(short param_1);
int FUN_004037e0(short param_1);
long FUN_00403800(short param_1);
long FUN_00403830(short param_1);
int FUN_00403860(short param_1);
int FUN_00403880(short param_1);
u32 FUN_004038a0(short param_1);
u32 FUN_004038e0(short param_1);
s16 FUN_00403900(short param_1);
u32 FUN_00403920(short param_1,short param_2);
u32 FUN_00403970(short param_1);
u32 FUN_00403e40(int param_1,int param_2);
u32 FUN_00403f20(short param_1,long param_2);
u32 FUN_00404120(short param_1,long param_2);
void FUN_00404470(short param_1);
#pragma alias FUN_00404470_alt FUN_00404470
void FUN_00404470_alt(short param_1,int param_2);
void FUN_004044c0(short param_1);
void FUN_004045d0(u64 param_1);
void FUN_00404750(u64 param_1,u32 param_2);
u64 FUN_00405970(u64 param_1,int param_2);
void FUN_00405a90(u64 param_1,int param_2);
u64 FUN_00405ac0(u64 param_1,long param_2);
void FUN_00405d60(int param_1);
void FUN_00405e00(u64 param_1);
extern int FUN_00405db0(u32* param_1, u32* param_2);
u8 FUN_00405e30(u64 param_1);
void FUN_00405f70(u64 param_1,u64 param_2,u32 param_3,int param_4,u64 param_5, int param_6,int param_7);
void FUN_004064e0(u64 param_1,u64 param_2,u32 param_3,int param_4);
void FUN_00406aa0(u64 param_1,u64 param_2,u32 param_3);
void FUN_00406ca0(u64 param_1,u64 param_2,int *param_3);
void FUN_00407180(u32 param_1,u32 param_2,u16 param_3,int param_4);
void FUN_00407210(u32 param_1,u32 param_2,u16 param_3,int param_4,int param_5);
void FUN_004072d0(int param_1,long param_2,long param_3);
u64 FUN_00409c80(u64 param_1);
u32 FUN_00409e90(void);
void FUN_00409f20(u64 param_1,int param_2);
u64 FUN_00409f50(u64 param_1,long param_2);
void FUN_0040a200(int param_1);
void FUN_0040a260(int param_1);
u8 FUN_0040a2b0(u64 param_1);
u8 FUN_0040a490(u64 param_1);
void FUN_0040a6d0(u64 param_1,long param_2);
void FUN_0040a7c0(u64 param_1,u64 param_2,u8 param_3);
void FUN_0040a7f0(u64 param_1,int param_2,int *param_3);
void FUN_0040b3a0(u64 param_1,int param_2,int param_3);
void FUN_0040b630(u32 param_1,u32 param_2,u16 param_3,u64 param_4);
void FUN_0040b780(u32 param_1,u32 param_2,u16 param_3,int param_4,int param_5);
void FUN_0040b840(int param_1);
u32 FUN_0040b910(u64 param_1);
void FUN_0040c150(u32 param_1);
u32 FUN_0040c170(void);
void FUN_0040c1e0(long param_1,long param_2,long param_3);
void FUN_0040c310(int param_1);
void FUN_0040c460(u64 param_1,int param_2);
void FUN_0040c490(u64 param_1);
void FUN_0040c520(u64 param_1);
void FUN_0040c5b0(u64 param_1);
void FUN_0040c650(u64 param_1);
void FUN_0040c6a0(u64 param_1);
int FUN_0040c6f0(int param_1);
void FUN_0040c9a0(int param_1);
long FUN_0040ca00(u64 param_1);
void FUN_0040cad0(int param_1);
void FUN_0040cc30(u64 param_1,int param_2,int *param_3);
void FUN_0040d330(int param_1);
void FUN_0040d3b0(u32 param_1,u32 param_2,u16 param_3,int param_4);
u32 FUN_0040d410(void);
u32 FUN_0040d490(void);
u32 FUN_0040d540(void);
void FUN_0040d5b0(int param_1,int param_2,int param_3,int param_4,u32 param_5);
void FUN_0040d5e0(float param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6);
void FUN_0040d610(float param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6,long param_7);
void FUN_0040d640(float param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6, long param_7,long param_8);
void FUN_0040dcc0(float param_1,int param_2,int param_3,int param_4,int param_5,int param_6, u32 param_7,int param_8,long param_9);
#pragma alias datGetFlag_s32 datGetFlag
s32 datGetFlag_s32(s32 param_1);
#pragma alias datSocialLinkLevelIsNotZero_s32 datSocialLinkLevelIsNotZero
u32 datSocialLinkLevelIsNotZero_s32(s32 socialLink);
void FUN_001725a0(u64 socialLink);
#pragma alias datGetEquipmentIdx_s16 datGetEquipmentIdx
s16 datGetEquipmentIdx_s16(s16 param_1,s16 param_2);
#pragma alias FUN_0017c610_u64 FUN_0017c610
s32 FUN_0017c610_u64(u64 param_1);
#pragma alias FUN_004037e0_u64 FUN_004037e0
int FUN_004037e0_u64(u64 param_1);
#pragma alias FUN_003f04f0_u32 FUN_003f04f0
u32 FUN_003f04f0_u32(u32 param_1,int param_2);
#pragma alias FUN_003f1dc0_u32 FUN_003f1dc0
u32 FUN_003f1dc0_u32(s32 param_1,void *param_2,s32 param_3);
#pragma alias FUN_003f1dc0_u64 FUN_003f1dc0
u32 FUN_003f1dc0_u64(u64 param_1,void *param_2,s32 param_3);
#pragma alias FUN_0040e3c0_f32 FUN_0040e3c0
void FUN_0040e3c0_f32(float param_1,int param_2,int param_3,u8 param_4,int param_5,int param_6);
#pragma alias FUN_0040e3c0_u32 FUN_0040e3c0
void FUN_0040e3c0_u32(float param_1,int param_2,int param_3,u32 param_4,int param_5,int param_6);
#pragma alias FUN_003e0680_typed FUN_003e0680
void FUN_003e0680_typed(int param_1,code param_2,void *param_3);
#pragma alias memset_typed memset
void memset_typed(void *param_1,int param_2,u32 param_3);
#pragma alias memcpy_typed memcpy
void memcpy_typed(void *param_1,const void *param_2,u32 param_3);
#pragma alias H_Maestro_00111c50_i H_Maestro_00111c50
void H_Maestro_00111c50_i(u64 param_1);
#pragma alias H_Maestro_SetAlphaMult_f32 H_Maestro_SetAlphaMult
void H_Maestro_SetAlphaMult_f32(float param_1,u64 param_2);
#pragma alias H_Maestro_RequestDraw_i H_Maestro_RequestDraw
#pragma alias FUN_003c4e70_u64 FUN_003c4e70
void FUN_003c4e70_u64(int param_1);
#pragma alias scrGetIntPara_u32 scrGetIntPara
u32 scrGetIntPara_u32(int param_1);
#pragma alias FUN_003e0700_u32 FUN_003e0700
void FUN_003e0700_u32(u32 param_1);
#pragma alias fclCombine003d02f0_i fclCombine003d02f0
void fclCombine003d02f0_i(void);
#pragma alias FUN_00175410_u32 FUN_00175410
u32 FUN_00175410_u32(void);
#pragma alias datPersonaGetHeroPersona_s16 datPersonaGetHeroPersona
u32 datPersonaGetHeroPersona_s16(s16 param_1);
#pragma alias FUN_0017ca10_u32 FUN_0017ca10
u32 FUN_0017ca10_u32(u32 param_1);


/* FUSION_GLOBALS */
u32 DAT_006ac9e8;
u32 DAT_006ad4b4;
float DAT_007cada4;
u32 DAT_007ce420;
u32 DAT_007ce4e8;
extern u8 DAT_006ac9d0[];
u32 DAT_006acc60;
extern u8 DAT_006acc70[];
extern u8 DAT_006acc72[];
u32 DAT_006acca0;
u32 DAT_006aedc0[];
u32 DAT_006aedc4[];
u32 DAT_006aee60;
u32 DAT_006aeea0;
u32 DAT_006aeee0;
u32 DAT_006aef00;
u32 DAT_006aef30;
u32 DAT_006aef40;
u32 DAT_006aef50;
u32 DAT_006aef60;
u32 DAT_006aef98;
u32 DAT_006aefa8;
u32 DAT_006aefb8;
u32 DAT_006aefd0;
u32 DAT_006aeff0;
u32 DAT_006af000;
u32 DAT_006af004;
u32 DAT_006af008;
u32 DAT_006af010;
u32 DAT_006af0b0;
u32 DAT_006af140;
u32 DAT_006af170;
u32 DAT_006af174;
u32 DAT_006af178;
u32 DAT_006af17c;
u32 DAT_006af180;
u32 DAT_006af188;
u32 DAT_006af18c;
u32 DAT_006af190;
u32 DAT_006af1c0;
u32 DAT_006af240;
u32 DAT_006af270;
u32 DAT_006af290;
u32 DAT_006af2b0;
u32 DAT_006af2d0;
u32 DAT_006af300;
u32 DAT_006af320;
extern u32 DAT_006af3a0;
extern u8 DAT_006af3a0_abs[];
#pragma alias DAT_006af3a0_abs DAT_006af3a0
u32 DAT_006af5e0;
u32 DAT_006af600;
u32 DAT_006af620;
u32 DAT_006af930;
float DAT_007cad74;
float DAT_007cad78;
float DAT_007cad80;
float DAT_007cad94;
float DAT_007cae00;
float DAT_007caef0;
float DAT_007caf14;
float DAT_007caf38;
u32 DAT_007cd8f4;
u32 DAT_007cd8f8;
u32 DAT_007cd8fc;
u32 DAT_007cd908;
u32 DAT_007cd90c;
u32 DAT_007cd910;
u32 DAT_007cd918;
u32 DAT_007cd920;
u32 DAT_007cd928;
u32 DAT_007cd930;
u32 DAT_007cd932;
u32 DAT_007cd934;
u32 DAT_007cd936;
u32 DAT_007cd938;
u32 DAT_007cd940;
u32 DAT_007cd942;
u32 DAT_007cd944;
u32 DAT_007cd946;
u32 DAT_007cd948;
u32 DAT_007cd950;
u32 DAT_007cd952;
u32 DAT_007cd958;
u32 DAT_007cd95c;
u32 DAT_007cd960;
u32 DAT_007cd964;
u32 DAT_007cd968;
u32 DAT_007cd96c;
u32 DAT_007cd980;
u32 DAT_007cd988;
u32 DAT_007cd990;
u32 DAT_007cd998;
u32 DAT_007cd9a0;
u32 DAT_007cd9a8;
u32 DAT_007cd9b0;
u32 DAT_007cd9b8;
u32 DAT_007cd9c0;
u32 DAT_007cd9c8;
u32 DAT_007cd9f8;
u32 DAT_007cd9fc;
u32 DAT_007cda00;
u8 *DAT_007ce4e4;
u32 DAT_007e094e;
u32 DAT_007e0952;
u32 DAT_007e0958;
u32 DAT_007e095a;
u32 DAT_00960088;
code DAT_00960090;
code DAT_009600a0;
u32 DAT_0098967f;
u32 LAB_003eff84[];
u32 LAB_003f0748[];
u32 LAB_003f07f4[];
u32 LAB_003f23a8[];
u32 LAB_003fe35c[];
u32 LAB_003fee10[];
u32 LAB_00401910[];
u32 LAB_004019d0[];
u32 LAB_00401aa4[];
u32 LAB_00401b60[];
u32 LAB_00401bc4[];
u32 LAB_00401c48[];
u32 LAB_00401ea8[];
u32 LAB_00401fa8[];
u32 LAB_0040203c[];
u32 LAB_00402100[];
u32 LAB_0040370c[];
u32 LAB_00403b38[];
u32 LAB_00403d20[];
u32 LAB_00403ec0[];
u32 LAB_004046bc[];
u32 LAB_004062e0[];
u32 LAB_00406468[];
u32 LAB_0040c3c4[];
u32 PTR_DAT_006ac9ec[];
u32 PTR_DAT_006ac9f0[];
u32 PTR_DAT_006ad4a0[];
u32 PTR_DAT_006ad4b0[];
u32 PTR_DAT_007cd8f0[];
u32 PTR_FUN_006aee00[];
u32 PTR_FUN_006aee20[];
u32 PTR_FUN_006aee40[];
u32 PTR_FUN_006af050[];
u32 PTR_FUN_006af070[];
u32 PTR_FUN_006af090[];
u32 PTR_FUN_007cd970[];
u32 PTR_FUN_007cd974[];
u32 PTR_FUN_007cd978[];
u32 PTR_FUN_007cd97c[];
u32 PTR_LAB_007bbde0[];
u32 PTR_PTR_006ac9d4[];
u32 _DAT_006af180;
u32 _DAT_006af184;
#include "Kosaka/k_assert.h"
// FUN_003fb290
void fclShopMisc003fb290(void* param_1, void* param_2)
{
    K_ASSERT(param_1 != NULL, 0x1018);
    memcpy((int)param_1 + 0xc, param_2, 0x1c);
}

// HARVESTED 3D-42FF

// FUN_003EFF00 NONMATCHING


void FUN_003eff00(u64 param_1,u8 *param_2)



{

  int iVar1;

  u8 uVar2;

  u16 uVar3;

  u32 uVar4;

  u64 uVar5;

  long lVar6;

  int iStack_4;

  


  iStack_4 = 0;

  do {


    if (lVar6 == 0) goto LAB_003eff84;

    iVar1 = *(int *)lVar6;

    uVar4 = datGetLevel(1);

  } while (iVar1 <= (int)(uVar4 & 0xff));

  iStack_4 = iStack_4 + -1;

LAB_003eff84:

  *param_2 = (char)iStack_4;


  param_2[1] = uVar2;


  *(u16 *)(param_2 + 2) = uVar3;

  iStack_4 = 0;


  *(int *)(param_2 + 4) = iStack_4;

  return;

}

// FUN_003EFFF0


u8 * FUN_003efff0(int param_1)



{

  u32 lVar1;

  int iVar2;

  

  if ((param_1 < 0) || !(param_1 < 9)) {

    K_Assert((const char *)(DAT_006aede8 + 1) - 1,0xb9);

  }

  lVar1 = datGetScenarioMode();

  iVar2 = (int)param_1;

  if (lVar1 == 0) {
    return (u8 *)&DAT_006ac9d0 + iVar2 * 0x24;
  }

  return (u8 *)&DAT_006ac9d0 + (iVar2 + 9) * 0x24;


}

// FUN_003F0090
s16 FUN_003f0090(int param_1)



{

  return *(s16 *)(DAT_006acc70 + param_1 * 4);

}

// FUN_003F00B0


s16 FUN_003f00b0(int param_1)



{

  return *(s16 *)(DAT_006acc72 + param_1 * 4);

}

// FUN_003F00D0 NONMATCHING


int FUN_003f00d0(int *param_1,u64 param_2,int *param_3)



{

  short sVar1;

  u16 uVar2;

  long lVar3;

  int iVar4;

  int iVar5;

  int iStack_4;

  

  iStack_4 = 0;

  if (param_3 == (int *)0x0) {

    param_3 = &iStack_4;

  }

  iVar5 = param_1[1];

  iVar4 = *param_3;

  do {

    if (*param_1 <= iVar4) {

      *param_3 = -1;

      return 0;

    }

    sVar1 = *(short *)(iVar5 + 4);

    if ((sVar1 == 0) || (uVar2 = datGetLevel(1), sVar1 <= (short)(uVar2 & 0xff))) {


      if (lVar3 != 0) {

        *param_3 = iVar4;

        return iVar5;

      }

      iVar5 = iVar5 + 0x14;

    }

    iVar4 = iVar4 + 1;

  } while( 1 );

}

// FUN_003F01D0


void FUN_003f01d0(int param_1,int param_2,int *param_3)
{
  int *ptr = (int *)(param_1 + param_2 * 8);
  if (FUN_003f00d0(ptr,1,param_3) != 0) {
    return;
  }
  *param_3 = 0;
  FUN_003f00d0(ptr,0,param_3);
}

// FUN_003F0240 NONMATCHING


u32 FUN_003f0240(int param_1)



{

  int iVar1;

  long lVar2;

  

  if ((param_1 < 0) || (8 < param_1)) {

    K_Assert((const char *)(u32)0x6aede8,0xb9);

  }

  lVar2 = datGetScenarioMode();

  iVar1 = param_1;

  if (lVar2 != 0) {

    iVar1 = param_1 + 9;

  }

  if (((param_1 == 2) || (param_1 == 1)) || (param_1 == 0)) {


    if (lVar2 == 0) {


    }

    if (lVar2 != 0) {

      return 1;

    }

  }

  return 0;

}

// FUN_003F0350


int FUN_003f0350(int param_1,int *param_2)
{
  int iVar1;

  if (param_2 == 0) {
    K_Assert((const char *)DAT_006aede8,0x13b);
  }

  iVar1 = *param_2;
  if (iVar1 >= *(int *)(param_1 + 0x18)) {
    return 0;
  }

  *param_2 = iVar1 + 1;
  return *(int *)(param_1 + 0x1c) + iVar1 * 0xc;
}

// FUN_003F03E0 NONMATCHING


char FUN_003f03e0(int param_1)



{

  char cVar1;

  long lVar2;

  short sVar3;

  

  if (param_1 == 8) {

    sVar3 = 2;

  }

  else if (param_1 == 4) {

    sVar3 = 3;

  }

  else {

    if (param_1 != 0) {

      return '\0';

    }

    sVar3 = 0xf;

  }

  if (sVar3 == 0xff) {

    cVar1 = '\0';

  }

  else {

    lVar2 = datSocialLinkLevelIsNotZero(sVar3);

    if (lVar2 == 0) {

      cVar1 = '\0';

    }

    else {

      cVar1 = datGetSocialLinkLevel(sVar3);

      if (cVar1 == '\0') {

        cVar1 = '\0';

      }

      else if ((cVar1 < '\x01') || ('\n' < cVar1)) {

        K_Assert((const char *)(u32)0x6aede8,0x15c);

      }

    }

  }

  return cVar1;

}

// FUN_003F04F0 NONMATCHING


u32 FUN_003f04f0(long param_1,int param_2)



{

  u8 bVar1;

  u32 uVar2;

  u32 uVar3;

  long lVar4;

  short *psVar5;

  

  if (param_1 == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x16c);

  }

  uVar2 = clndGetCurrentWeekDay();

  psVar5 = (short *)param_1;

  bVar1 = 1;

  if (((long)*psVar5 & (long)(1 << (uVar2 & 0x1f))) == 0) {

    uVar3 = 0;

  }

  else {

    if ((psVar5[1] != 0) && (lVar4 = datGetFlag(), lVar4 == 0)) {

      bVar1 = 0;

    }

    if (bVar1) {

      if ((long)psVar5[2] == 0) {

        uVar3 = (u32)(param_2 != 1);

      }

      else if (param_2 == 2) {

        uVar3 = clndIsDateInRangeFromStart(((long)psVar5[2] << 0x34) >> 0x3a,

                             ((long)(char)psVar5[2] << 0x3a) >> 0x3a,0x16d);

      }

      else {

        if (((long)*(char *)((int)psVar5 + 5) << 0x38) >> 0x3c != 1) {

          K_Assert((const char *)(u32)0x6aede8,0x17f);

        }

        lVar4 = ((long)*(char *)((int)psVar5 + 7) << 0x38) >> 0x3c;

        if (lVar4 == 0) {

          uVar3 = 1;

        }

        else if (lVar4 == 2) {

          lVar4 = clndIsDateInRangeFromStart(((long)psVar5[2] << 0x34) >> 0x3a,

                               ((long)(char)psVar5[2] << 0x3a) >> 0x3a,

                               ((long)psVar5[3] << 0x34) >> 0x34);

          uVar3 = (u32)(lVar4 != 0);

        }

        else if (lVar4 == 1) {

          lVar4 = clndIsDateInRange(((long)psVar5[2] << 0x34) >> 0x3a,

                               ((long)(char)psVar5[2] << 0x3a) >> 0x3a,

                               ((long)psVar5[3] << 0x34) >> 0x3a,

                               ((long)(char)psVar5[3] << 0x3a) >> 0x3a);

          uVar3 = (u32)(lVar4 != 0);

        }

        else {

          uVar3 = 0;

        }

      }

    }

    else {

      uVar3 = 0;

    }

  }

  return uVar3;

}

// FUN_003F06E0 NONMATCHING


u32 * FUN_003f06e0(int *param_1,u64 param_2)



{

  u64 uVar1;

  long lVar2;

  int iVar3;

  u32 *puVar4;

  

  puVar4 = (u32 *)param_1[1];

  iVar3 = 0;

  do {

    if (*param_1 <= iVar3) {

      return (u32 *)0x0;

    }

    if ((*puVar4 & 4) == 0) {

LAB_003f0748:

      if ((*puVar4 & 1) != 0) {

        uVar1 = FUN_003e6dc0();


        if (lVar2 != 0) goto LAB_003f07f4;

      }

      if ((((short)puVar4[1] == -1) || (lVar2 = datGetFlag(), lVar2 != 0)) &&

         (lVar2 = FUN_003f04f0((long)(puVar4 + 4),param_2), lVar2 != 0)) {

        if ((short)puVar4[1] == -1) {

          return puVar4;

        }

        if ((*puVar4 & 2) == 0) {

          return puVar4;

        }

        datSetFlag((short)puVar4[1],0);

        return puVar4;

      }

    }

    else {

      uVar1 = FUN_003e6dc0();


      if (lVar2 == 0) goto LAB_003f0748;

    }

LAB_003f07f4:

    puVar4 = puVar4 + 6;

    iVar3 = iVar3 + 1;

  } while( 1 );

}

// FUN_003F0830 NONMATCHING


short FUN_003f0830(int param_1)



{

  u8 *puVar1;

  char cVar2;

  int iVar3;

  long lVar4;

  short sVar5;

  

  if (param_1 == 4) {

    sVar5 = 3;

  }

  else if (param_1 == 0) {

    sVar5 = 0xf;

  }

  else {

    sVar5 = 0xff;

  }

  if ((param_1 < 0) || (8 < param_1)) {

    K_Assert((const char *)(u32)0x6aede8,0xb9);

  }

  lVar4 = datGetScenarioMode();

  if (lVar4 != 0) {

    param_1 = param_1 + 9;

  }

  puVar1 = (u8 *)((u32 **)&PTR_DAT_006ac9f0)[param_1 * 9];


  if (lVar4 == 0) {

    if (sVar5 != 0xff) {

      if (*(int *)(puVar1 + 8) == 0) {

        K_Assert((const char *)(u32)0x6aede8,0x19c);

      }

      if (sVar5 == 0xff) {

        iVar3 = *(int *)(puVar1 + 8);

      }

      else {

        lVar4 = datSocialLinkLevelIsNotZero(sVar5);

        if (lVar4 == 0) {

          iVar3 = *(int *)(puVar1 + 8);

        }

        else {

          cVar2 = datGetSocialLinkLevel(sVar5);

          if (cVar2 == '\0') {

            iVar3 = *(int *)(puVar1 + 8);

          }

          else {

            if ((cVar2 < '\x01') || ('\n' < cVar2)) {

              K_Assert((const char *)(u32)0x6aede8,0x1a2);

            }

            iVar3 = *(int *)(puVar1 + 8) + cVar2 * 0x20;

          }

        }

      }

      if ((iVar3 != 0) && (*(short *)(iVar3 + 0xc) != -1)) {

        return *(short *)(iVar3 + 0xc);

      }

    }


    if (lVar4 != 0) {

      iVar3 = RpRandom();

      sVar5 = *(short *)(((iVar3 % 0xffff) / 0xffff) * 2 + (int)lVar4 + 8);

      if (sVar5 != -1) {

        return sVar5;

      }

    }

  }

  else {

    iVar3 = RpRandom();

    if (*(short *)(((iVar3 % 0xffff) / 0xffff) * 2 + (int)lVar4 + 8) != -1) {

      return *(short *)((int)lVar4 + 8);

    }

  }

  return -1;

}

// FUN_003F0AC0 NONMATCHING


short FUN_003f0ac0(int param_1)



{

  u8 *puVar1;

  char cVar2;

  int iVar3;

  long lVar4;

  short sVar5;

  

  if (param_1 == 4) {

    sVar5 = 3;

  }

  else if (param_1 == 0) {

    sVar5 = 0xf;

  }

  else {

    sVar5 = 0xff;

  }

  if ((param_1 < 0) || (8 < param_1)) {

    K_Assert((const char *)(u32)0x6aede8,0xb9);

  }

  lVar4 = datGetScenarioMode();

  if (lVar4 != 0) {

    param_1 = param_1 + 9;

  }

  puVar1 = (u8 *)((u32 **)&PTR_DAT_006ac9f0)[param_1 * 9];


  if (lVar4 == 0) {

    if (sVar5 != 0xff) {

      if (*(int *)(puVar1 + 8) == 0) {

        K_Assert((const char *)(u32)0x6aede8,0x19c);

      }

      if (sVar5 == 0xff) {

        iVar3 = *(int *)(puVar1 + 8);

      }

      else {

        lVar4 = datSocialLinkLevelIsNotZero(sVar5);

        if (lVar4 == 0) {

          iVar3 = *(int *)(puVar1 + 8);

        }

        else {

          cVar2 = datGetSocialLinkLevel(sVar5);

          if (cVar2 == '\0') {

            iVar3 = *(int *)(puVar1 + 8);

          }

          else {

            if ((cVar2 < '\x01') || ('\n' < cVar2)) {

              K_Assert((const char *)(u32)0x6aede8,0x1a2);

            }

            iVar3 = *(int *)(puVar1 + 8) + cVar2 * 0x20;

          }

        }

      }

      if ((iVar3 != 0) && (*(short *)(iVar3 + 0xe) != -1)) {

        return *(short *)(iVar3 + 0xe);

      }

    }


    if (lVar4 == 0) {

      return -1;

    }

    iVar3 = RpRandom();

    sVar5 = *(short *)(((iVar3 % 0xffff) / 0xffff) * 2 + (int)lVar4 + 8);

  }

  else {

    if ((*(u32 *)lVar4 & 1) != 0) {

      FUN_003e6e20(1);

    }

    iVar3 = RpRandom();

    sVar5 = *(short *)((int)(u32 *)lVar4 + ((iVar3 % 0xffff) / 0xffff) * 2 + 8);

  }

  if (sVar5 == -1) {

    return -1;

  }

  return sVar5;

}

// FUN_003F0D60 NONMATCHING


long FUN_003f0d60(int param_1,u64 param_2)



{

  int iVar1;

  long lVar2;

  u16 uVar3;

  long unaff_s1;

  int iStack_4;

  

  if (param_1 == 8) {

    uVar3 = 2;

    unaff_s1 = (long)(short)param_2;

  }

  else if (param_1 == 4) {

    uVar3 = 3;

    unaff_s1 = (long)(short)param_2;

  }

  else {

    if (param_1 != 0) {

      return 0;

    }

    uVar3 = 0xf;

    iVar1 = func_00170ed0(param_2,&iStack_4);

    if (iStack_4 == 4) {

      unaff_s1 = (long)*(int *)(iVar1 + 0x18);

    }

    else if (iStack_4 == 3) {

      unaff_s1 = (long)*(int *)(iVar1 + 0x20);

    }

    else if (iStack_4 == 2) {

      unaff_s1 = (long)*(int *)(iVar1 + 0x1c);

    }

    else if (iStack_4 == 1) {

      unaff_s1 = (long)*(int *)(iVar1 + 0x1c);

    }

    else if (iStack_4 == 0) {

      unaff_s1 = (long)*(int *)(iVar1 + 0x24);

    }

  }

  lVar2 = datSocialLinkLevelIsNotZero(uVar3);

  if (lVar2 == 0) {

    unaff_s1 = 0;

  }

  else {

    func_0016e2b0(uVar3,unaff_s1);

  }

  return unaff_s1;

}

// FUN_003F0EC0 NONMATCHING


u32 FUN_003f0ec0(u64 param_1)



{

  u16 uVar1;

  int iVar2;

  u32 uVar3;

  int iStack_4;

  

  uVar3 = 0;

  iVar2 = func_00170ed0(param_1,&iStack_4);

  if (iStack_4 == 4) {

    uVar1 = *(u16 *)(iVar2 + 0x10);

    if ((uVar1 & 0x10) == 0) {

      if ((uVar1 & 8) == 0) {

        if ((uVar1 & 4) != 0) {

          uVar3 = 1;

        }

      }

      else {

        uVar3 = 2;

      }

    }

    else {

      uVar3 = 3;

    }

  }

  else if (iStack_4 == 3) {

    uVar1 = *(u16 *)(iVar2 + 0x16);

    if ((uVar1 & 0x10) == 0) {

      if ((uVar1 & 8) == 0) {

        if ((uVar1 & 4) != 0) {

          uVar3 = 1;

        }

      }

      else {

        uVar3 = 2;

      }

    }

    else {

      uVar3 = 3;

    }

  }

  else if (iStack_4 == 2) {

    uVar1 = *(u16 *)(iVar2 + 0x18);

    if ((uVar1 & 0x10) == 0) {

      if ((uVar1 & 8) == 0) {

        if ((uVar1 & 4) != 0) {

          uVar3 = 1;

        }

      }

      else {

        uVar3 = 2;

      }

    }

    else {

      uVar3 = 3;

    }

  }

  else if (iStack_4 == 1) {

    uVar1 = *(u16 *)(iVar2 + 0x18);

    if ((uVar1 & 0x10) == 0) {

      if ((uVar1 & 8) == 0) {

        if ((uVar1 & 4) != 0) {

          uVar3 = 1;

        }

      }

      else {

        uVar3 = 2;

      }

    }

    else {

      uVar3 = 3;

    }

  }

  else if (iStack_4 == 0) {

    uVar1 = *(u16 *)(iVar2 + 0x22);

    if ((uVar1 & 0x10) == 0) {

      if ((uVar1 & 8) == 0) {

        if ((uVar1 & 4) != 0) {

          uVar3 = 1;

        }

      }

      else {

        uVar3 = 2;

      }

    }

    else {

      uVar3 = 3;

    }

  }

  return uVar3;

}

// FUN_003F10B0 NONMATCHING


u16 FUN_003f10b0(int param_1,u16 param_2)



{

  u8 *puVar1;

  char cVar2;

  u16 uVar3;

  long lVar4;

  int iVar5;

  short sVar6;

  

  if (param_1 == 4) {

    sVar6 = 3;

  }

  else {

    if (param_1 != 0) {

      return 0xffff;

    }

    sVar6 = 0xf;

  }

  if ((param_1 < 0) || (8 < param_1)) {

    K_Assert((const char *)(u32)0x6aede8,0xb9);

  }

  lVar4 = datGetScenarioMode();

  if (lVar4 != 0) {

    param_1 = param_1 + 9;

  }

  puVar1 = (u8 *)((u32 **)&PTR_DAT_006ac9f0)[param_1 * 9];

  if (*(int *)(puVar1 + 8) == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x19c);

  }

  if (sVar6 == 0xff) {

    iVar5 = *(int *)(puVar1 + 8);

  }

  else {

    lVar4 = datSocialLinkLevelIsNotZero(sVar6);

    if (lVar4 == 0) {

      iVar5 = *(int *)(puVar1 + 8);

    }

    else {

      cVar2 = datGetSocialLinkLevel(sVar6);

      if (cVar2 == '\0') {

        iVar5 = *(int *)(puVar1 + 8);

      }

      else {

        if ((cVar2 < '\x01') || ('\n' < cVar2)) {

          K_Assert((const char *)(u32)0x6aede8,0x1a2);

        }

        iVar5 = *(int *)(puVar1 + 8) + cVar2 * 0x20;

      }

    }

  }

  if ((iVar5 == 0) || (lVar4 = FUN_003f0ec0(param_2), lVar4 == 0)) {

    uVar3 = 0xffff;

  }

  else {

    uVar3 = *(u16 *)((int)lVar4 * 2 + iVar5 + 0xe);

  }

  return uVar3;

}

// FUN_003F12A0 NONMATCHING


u16 FUN_003f12a0(int param_1,int param_2)



{

  u8 *puVar1;

  char cVar2;

  u16 uVar3;

  long lVar4;

  int iVar5;

  short sVar6;

  

  if (param_1 == 4) {

    sVar6 = 3;

  }

  else {

    if (param_1 != 0) {

      return 0xffff;

    }

    sVar6 = 0xf;

  }

  if ((param_1 < 0) || (8 < param_1)) {

    K_Assert((const char *)(u32)0x6aede8,0xb9);

  }

  lVar4 = datGetScenarioMode();

  if (lVar4 != 0) {

    param_1 = param_1 + 9;

  }

  puVar1 = (u8 *)((u32 **)&PTR_DAT_006ac9f0)[param_1 * 9];

  if (*(int *)(puVar1 + 8) == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x19c);

  }

  if (sVar6 == 0xff) {

    iVar5 = *(int *)(puVar1 + 8);

  }

  else {

    lVar4 = datSocialLinkLevelIsNotZero(sVar6);

    if (lVar4 == 0) {

      iVar5 = *(int *)(puVar1 + 8);

    }

    else {

      cVar2 = datGetSocialLinkLevel(sVar6);

      if (cVar2 == '\0') {

        iVar5 = *(int *)(puVar1 + 8);

      }

      else {

        if ((cVar2 < '\x01') || ('\n' < cVar2)) {

          K_Assert((const char *)(u32)0x6aede8,0x1a2);

        }

        iVar5 = *(int *)(puVar1 + 8) + cVar2 * 0x20;

      }

    }

  }

  if (iVar5 == 0) {

    uVar3 = 0xffff;

  }

  else {

    uVar3 = *(u16 *)(param_2 * 2 + iVar5 + 0x18);

  }

  return uVar3;

}

// FUN_003F1470


u64 FUN_003f1470(int param_1)
{
  s16 sVar1;
  u32 uVar2;

  switch (param_1) {
  case 0:
    sVar1 = 0xf;
    break;
  case 4:
    sVar1 = 3;
    break;
  case 8:
    sVar1 = 2;
    break;
  default:
    return 0;
  }

  uVar2 = datSocialLinkLevelIsNotZero(sVar1);
  if (uVar2 == 0) {
    return 0;
  }

  return FUN_00172660(sVar1);
}

// FUN_003F1520

void FUN_003f1520(int param_1)
{
  s32 iVar1;
  u32 uVar2;

  switch (param_1) {
  case 0:
    iVar1 = 0xf;
    break;
  case 4:
    iVar1 = 3;
    break;
  case 8:
    iVar1 = 2;
    break;
  default:
    return;
  }

  uVar2 = datSocialLinkLevelIsNotZero_s32(iVar1);
  if (uVar2 != 0) {
    FUN_001725a0((s16)iVar1);
  }
  else {
    func_0016dfb0(iVar1);
  }
}


// FUN_003F15D0


int FUN_003f15d0(int param_1,int param_2)
{
  u8 *puVar1;
  u8 *puVar2;

  puVar1 = (u8 *)(u32)datGetMoney();
  puVar2 = puVar1;

  if (0x98967f < (s32)puVar1 + param_1 * param_2) {
    puVar2 = (u8 *)(u32)0x98967f;
  }

  if ((s32)puVar1 + param_1 * param_2 < 0) {
    puVar2 = (u8 *)0;
  }
  else {
    puVar2 = (u8 *)(u32)((s32)puVar2 + param_1 * param_2);
  }

  if ((s32)puVar2 >= 0x98967f) {
    puVar2 = (u8 *)(u32)0x98967f;
  }

  datSetMoney((s32)puVar2);
  return (s32)puVar2 - (s32)puVar1;
}

// FUN_003F1690


int FUN_003f1690(u64 param_1)
{
  u16 uVar1;
  int iVar2;

  iVar2 = 0;
  goto check;
body:
  uVar1 = datGetEquipmentId(1,iVar2);
  if (uVar1 != 0) {
    goto increment;
  }
  func_001831e0(1,(short)iVar2,param_1);
  return iVar2;
increment:
  iVar2 = iVar2 + 1;
check:
  if (iVar2 < 300) {
    goto body;
  }
  return -1;
}

// FUN_003F1720 NONMATCHING


u16 FUN_003f1720(u32 param_1,u16 param_2)



{

  u16 uVar1;

  u16 unaff_s0_lo;

  u8 auStack_20 [24];

  u32 uStack_8;

  int iStack_4;

  

  iStack_4 = -1;

  func_00170ed0(param_1,&iStack_4);

  if (iStack_4 == 4) {

    func_00170c00(1,param_1,param_2);

    unaff_s0_lo = (u16)param_1;

  }

  else if ((((iStack_4 == 3) || (iStack_4 == 2)) || (iStack_4 == 1)) || (iStack_4 == 0)) {

    func_001828d0(param_1,auStack_20);


  }

  uVar1 = FUN_003e6dc0();

  uStack_8 = (u32)uVar1;

  FUN_0017d1a0(uStack_8,param_1 & 0xffff,param_2);

  return unaff_s0_lo;

}

// FUN_003F1830 NONMATCHING


u32 FUN_003f1830(u16 *param_1,short param_2)



{

  u16 uVar1;

  int iStack_4;

  

  iStack_4 = -1;

  uVar1 = *param_1;

  func_00170ed0(uVar1,&iStack_4);

  if (iStack_4 == 4) {

    func_00170c00(1,uVar1,-param_2);

  }

  else if ((((iStack_4 == 3) || (iStack_4 == 2)) || (iStack_4 == 1)) || (iStack_4 == 0)) {

    func_0016fea0(1,param_1[1],0);

  }

  return 1;

}

// FUN_003F1910 NONMATCHING


u32 FUN_003f1910(u64 param_1)



{

  u32 uVar1;

  u32 uVar2;

  int iVar3;

  int iStack_4;

  

  iStack_4 = -1;

  uVar2 = 0;

  func_00170ed0(param_1,&iStack_4);

  if (iStack_4 == 4) {

    uVar2 = func_00170760(1,param_1);

    uVar2 = uVar2 & 0xffff;

  }

  else if ((((iStack_4 == 3) || (iStack_4 == 2)) || (iStack_4 == 1)) || (iStack_4 == 0)) {

    for (iVar3 = 0; iVar3 < 300; iVar3 = iVar3 + 1) {

      uVar1 = datGetEquipmentId(1,iVar3);

      if ((long)(short)param_1 == (uVar1 & 0xffff)) {

        uVar2 = uVar2 + 1;

      }

    }

  }

  return uVar2;

}

// FUN_003F1A10 NONMATCHING


u32 FUN_003f1a10(u32 param_1)



{

  u32 uVar1;

  

  if ((param_1 & 0x7ffff) == 0) {

    uVar1 = 0x4000;

  }

  else {

    uVar1 = 0x1000;

  }

  if ((param_1 & 0xff00) != 0) {

    param_1 = param_1 >> 8;

    uVar1 = uVar1 | 0x2000;

  }

  if ((param_1 & 1) == 0) {

    if ((param_1 & 2) == 0) {

      if ((param_1 & 4) == 0) {

        if ((param_1 & 8) == 0) {

          if ((param_1 & 0x10) == 0) {

            if ((param_1 & 0x20) == 0) {

              if ((param_1 & 0x40) == 0) {

                if ((param_1 & 0x80) == 0) {

                  if ((param_1 & 0x10000) == 0) {

                    if ((param_1 & 0x20000) == 0) {

                      if ((param_1 & 0x40000) == 0) {

                        if ((param_1 & 0x80000) == 0) {

                          if ((param_1 & 0x100000) == 0) {

                            uVar1 = 0;

                          }

                          else {

                            uVar1 = uVar1 | 0x40e;

                          }

                        }

                        else {

                          uVar1 = uVar1 | 0x40d;

                        }

                      }

                      else {

                        uVar1 = uVar1 | 0x30b;

                      }

                    }

                    else {

                      uVar1 = uVar1 | 0x20a;

                    }

                  }

                  else {

                    uVar1 = uVar1 | 0x109;

                  }

                }

                else {

                  uVar1 = uVar1 | 7;

                }

              }

              else {

                uVar1 = uVar1 | 6;

              }

            }

            else {

              uVar1 = uVar1 | 5;

            }

          }

          else {

            uVar1 = uVar1 | 4;

          }

        }

        else {

          uVar1 = uVar1 | 3;

        }

      }

      else {

        uVar1 = uVar1 | 2;

      }

    }

    else {

      uVar1 = uVar1 | 1;

    }

  }

  return uVar1;

}

// FUN_003F1BA0 NONMATCHING


void FUN_003f1ba0(long param_1,u32 param_2)



{

  u32 uVar1;

  u32 *puVar2;

  long lVar3;

  u16 *puVar4;

  int iStack_4;

  

  iStack_4 = -1;

  if (param_1 == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x3cc);

  }

  memset(param_1,0,0x1c);

  puVar4 = (u16 *)param_1;

  *puVar4 = (short)param_2;

  puVar4[5] = 0;

  lVar3 = dat00171360(param_2 & 0xffff);

  if (lVar3 == 0) {

    puVar2 = (u32 *)func_00170ed0(param_2,&iStack_4);

    if (iStack_4 == 4) {


      *(u32 *)(puVar4 + 2) = uVar1;

      *(u32 *)(puVar4 + 6) = puVar2[3];

      *(u8 *)(puVar4 + 4) = 2;

    }

    else if (iStack_4 == 3) {


      *(u32 *)(puVar4 + 2) = uVar1;

      *(u32 *)(puVar4 + 6) = puVar2[4];

      puVar4[8] = *(u16 *)(puVar2 + 1);

      puVar4[9] = *(u16 *)(puVar2 + 2);

      puVar4[10] = *(u16 *)((int)puVar2 + 6);

      puVar4[0xb] = *(u16 *)((int)puVar2 + 10);

      puVar4[0xc] = *(u16 *)(puVar2 + 3);

      *(u8 *)(puVar4 + 4) = 2;

    }

    else if (iStack_4 == 2) {

      func_001714f0(*(u16 *)(puVar2 + 3));


      *(u32 *)(puVar4 + 2) = uVar1;

      *(u32 *)(puVar4 + 6) = puVar2[4];

      puVar4[0xb] = *(u16 *)(puVar2 + 2);

      *(u8 *)(puVar4 + 4) = 2;

      *(u8 *)((int)puVar4 + 9) = 0x82;

    }

    else if (iStack_4 == 1) {


      *(u32 *)(puVar4 + 2) = uVar1;

      *(u32 *)(puVar4 + 6) = puVar2[4];

      puVar4[10] = *(u16 *)(puVar2 + 2);

      *(u8 *)(puVar4 + 4) = 2;

      *(u8 *)((int)puVar4 + 9) = 0x82;

    }

    else if (iStack_4 == 0) {


      *(u32 *)(puVar4 + 2) = uVar1;

      *(u32 *)(puVar4 + 6) = puVar2[6];

      puVar4[8] = *(u16 *)(puVar2 + 2);

      puVar4[9] = *(u16 *)(puVar2 + 3);

      *(u8 *)(puVar4 + 4) = 2;

      *(u8 *)((int)puVar4 + 9) = 0x82;

    }

  }

  else {


    *(u32 *)(puVar4 + 2) = uVar1;

  }

  return;

}

// FUN_003F1DC0 NONMATCHING


u32 FUN_003f1dc0(u16 param_1,long param_2,long param_3)



{

  u8 uVar1;

  short sVar2;

  u32 *puVar3;

  float *pfVar4;

  u32 uVar5;

  short *psVar6;

  float fVar7;

  int iStack_4;

  

  if ((param_3 < 0) || (299 < param_3)) {

    K_Assert((const char *)(u32)0x6aede8,0x40f);

  }

  if (param_2 == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x410);

  }

  memset(param_2,0,0x1c);

  sVar2 = datGetEquipmentId(param_1,param_3);

  if (sVar2 == 0) {

    uVar5 = 0;

  }

  else {

    psVar6 = (short *)param_2;

    *psVar6 = sVar2;

    psVar6[5] = 1;

    psVar6[1] = (short)param_3;

    iStack_4 = 0;

    puVar3 = (u32 *)func_00170ed0(sVar2,&iStack_4);

    if (iStack_4 == 4) {

      K_Assert((const char *)(u32)0x6aede8,0x442);

      *(u8 *)(psVar6 + 4) = 2;


      *(u32 *)(psVar6 + 2) = uVar5;

      *(u32 *)(psVar6 + 6) = puVar3[3];

    }

    else if (iStack_4 == 3) {

      uVar1 = datGetEquipmentEffect(param_1,param_3);

      *(u8 *)((int)psVar6 + 9) = uVar1;

      *(u8 *)(psVar6 + 4) = 2;


      *(u32 *)(psVar6 + 2) = uVar5;

      *(u32 *)(psVar6 + 6) = puVar3[4];

      psVar6[8] = *(short *)(puVar3 + 1);

      psVar6[9] = *(short *)(puVar3 + 2);

      psVar6[10] = *(short *)((int)puVar3 + 6);

      psVar6[0xb] = *(short *)((int)puVar3 + 10);

      psVar6[0xc] = *(short *)(puVar3 + 3);

    }

    else if (iStack_4 == 2) {

      uVar1 = datGetEquipmentEffect(param_1,param_3);

      *(u8 *)((int)psVar6 + 9) = uVar1;

      pfVar4 = (float *)func_001714f0(*(u8 *)((int)psVar6 + 9));

      uVar1 = func_0016f810(param_1,param_3);

      *(u8 *)(psVar6 + 4) = uVar1;


      *(u32 *)(psVar6 + 2) = uVar5;

      fVar7 = (float)func_00171510(*(u16 *)(puVar3 + 5),(char)psVar6[4]);

      *(int *)(psVar6 + 6) = (int)((float)(u32)puVar3[4] * *pfVar4 * fVar7);

      sVar2 = func_0016fcc0(param_1,param_3);

      psVar6[0xb] = sVar2;

    }

    else if (iStack_4 == 1) {

      uVar1 = datGetEquipmentEffect(param_1,param_3);

      *(u8 *)((int)psVar6 + 9) = uVar1;

      pfVar4 = (float *)func_001714f0(*(u8 *)((int)psVar6 + 9));

      uVar1 = func_0016f810(param_1,param_3);

      *(u8 *)(psVar6 + 4) = uVar1;


      *(u32 *)(psVar6 + 2) = uVar5;

      fVar7 = (float)func_00171510(*(u16 *)(puVar3 + 5),(char)psVar6[4]);

      *(int *)(psVar6 + 6) = (int)((float)(u32)puVar3[4] * *pfVar4 * fVar7);

      sVar2 = func_0016fbd0(param_1,param_3);

      psVar6[10] = sVar2;

    }

    else if (iStack_4 == 0) {

      uVar1 = datGetEquipmentEffect(param_1,param_3);

      *(u8 *)((int)psVar6 + 9) = uVar1;

      pfVar4 = (float *)func_001714f0(*(u8 *)((int)psVar6 + 9));

      uVar1 = func_0016f810(param_1,param_3);

      *(u8 *)(psVar6 + 4) = uVar1;


      *(u32 *)(psVar6 + 2) = uVar5;

      fVar7 = (float)func_00171510(*(u16 *)(puVar3 + 7),(char)psVar6[4]);

      *(int *)(psVar6 + 6) = (int)((float)(u32)puVar3[6] * *pfVar4 * fVar7);

      sVar2 = func_0016f9f0(param_1,param_3);

      psVar6[8] = sVar2;

      sVar2 = func_0016fae0(param_1,param_3);

      psVar6[9] = sVar2;

    }

    uVar5 = 1;

  }

  return uVar5;

}

// FUN_003F2240 NONMATCHING


u8 FUN_003f2240(long param_1,u16 param_2)



{

  short sVar1;

  u32 *puVar2;

  u32 uVar3;

  u16 *puVar4;

  

  if (param_1 == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x450);

  }

  memset(param_1,0,0x1c);

  sVar1 = func_00170760(1,param_2);

  if (sVar1 != 0) {

    puVar2 = (u32 *)func_00170e90(param_2);

    puVar4 = (u16 *)param_1;

    *puVar4 = param_2;


    *(u32 *)(puVar4 + 2) = uVar3;

    *(u32 *)(puVar4 + 6) = puVar2[3];

    puVar4[5] = sVar1;

  }

  return sVar1 != 0;

}

// FUN_003F2320 NONMATCHING


u64 FUN_003f2320(int param_1,int param_2)



{

  u32 *puVar1;

  long lVar2;

  short *psVar3;

  int iVar4;

  

  puVar1 = *(u32 **)(*(int *)(param_1 + 0x24) + 0x44);

  *puVar1 = *puVar1 | 2;

  psVar3 = *(short **)(param_2 + 8);

  lVar2 = 0;

  do {

    if (*(short *)(param_2 + 6) <= lVar2) {

      for (iVar4 = *(int *)(param_1 + 4); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {

        puVar1 = *(u32 **)(*(int *)(iVar4 + 0x14) + 0x1c);

        if ((*puVar1 & 8) == 0) {

          if ((*puVar1 & 4) == 0) {

            puVar1[4] = (int)(((float)(int)puVar1[4] + 0.0) - (float)(int)puVar1[4] * 0.25);

          }

          else {

            puVar1[4] = (int)(((float)(int)puVar1[4] + 0.0) - fGpffff808c * (float)(int)puVar1[4]);

          }

        }

        else {

          puVar1[4] = (int)(((float)(int)puVar1[4] + 0.0) - (float)(int)puVar1[4] * 0.5);

        }

        if ((int)puVar1[4] < 0) {

          puVar1[4] = 1;

        }

      }


      return 0;

    }

    if ((*psVar3 != 0) && ((*(u8 *)((int)psVar3 + 5) & 1) != 0)) {

      for (iVar4 = *(int *)(param_1 + 4); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {

        if (*(short *)(*(int *)(*(int *)(iVar4 + 0x14) + 0x1c) + 4) == *psVar3) goto LAB_003f23a8;

      }

      iVar4 = 0;

LAB_003f23a8:

      if (iVar4 != 0) {

        puVar1 = *(u32 **)(*(int *)(iVar4 + 0x14) + 0x1c);

        *puVar1 = *puVar1 | 2;

        if ((*(u8 *)((int)psVar3 + 5) & 4) == 0) {

          if ((*(u8 *)((int)psVar3 + 5) & 2) != 0) {

            *puVar1 = *puVar1 | 4;

          }

        }

        else {

          *puVar1 = *puVar1 | 8;

        }

      }

    }

    psVar3 = psVar3 + 4;

    lVar2 = (long)((int)lVar2 + 1);

  } while( 1 );

}

// FUN_003F2510 NONMATCHING


u32 FUN_003f2510(void)



{

  u32 uVar1;

  long lVar2;

  u32 uVar3;

  

  uVar1 = 0;

  for (uVar3 = 0; uVar3 < 8; uVar3 = uVar3 + 1) {

    if ((*(short *)(&DAT_006acc60 + uVar3 * 2) == -1) || (lVar2 = datGetFlag(), lVar2 == 0)) {

      if ((uVar3 == 6) && (lVar2 = datGetScenarioMode(), lVar2 != 0)) {

        uVar1 = uVar1 | 0x40;

      }

    }

    else {

      uVar1 = uVar1 | 1 << (uVar3 & 0x1f) & 0xffffU;

    }

  }

  return uVar1;

}

// FUN_003F25E0 NONMATCHING


u32 FUN_003f25e0(u64 param_1,long param_2,u32 param_3)



{

  short sVar1;

  u32 *puVar2;

  u8 bVar3;

  u16 uVar4;

  u16 uVar5;

  int iVar6;

  u32 uVar7;

  long lVar8;

  u64 uVar9;

  int iVar10;

  short *psVar11;

  long lVar12;

  u32 uStack_8;

  int iStack_4;

  

  iVar10 = (int)param_2;

  psVar11 = *(short **)(iVar10 + 8);

  lVar12 = 0;

  do {

    if (*(short *)(iVar10 + 6) <= lVar12) {

      return 0;

    }

    sVar1 = *psVar11;

    if (sVar1 != 0) {

      bVar3 = 1;

      iVar6 = func_00170ed0(sVar1,&iStack_4);

      if (((param_3 & 0x400) != 0) && (iStack_4 != 0)) {

        bVar3 = 0;

      }

      if (((((param_3 & 0x800) != 0) && (iStack_4 != 1)) && (iStack_4 != 2)) && (iStack_4 != 3)) {

        bVar3 = 0;

      }

      if (iStack_4 < 1) {


        if ((((uVar7 & 0xff) != 6) || (lVar8 = datGetScenarioMode(), lVar8 == 0)) &&

           ((*(short *)(&DAT_006acc60 + (uVar7 & 0xff) * 2) != -1 &&

            (lVar8 = datGetFlag(), lVar8 == 0)))) {

          bVar3 = 0;

        }

      }

      if (((char)psVar11[2] == '\x01') && (lVar8 = datGetFlag(0x1310), lVar8 == 0)) {

        bVar3 = 0;

      }

      if (bVar3) {

        if ((param_3 & 0x1000) != 0) {

          return 1;

        }

        if (((param_3 & 0x2000) != 0) &&

           (lVar8 = FUN_003c4bf0(param_1,(int)param_1 + 4,sVar1), lVar8 != 0)) {

          bVar3 = 0;

        }

      }

      if (bVar3) {

        uVar9 = FUN_003c5a40(param_1,*(u16 *)((int)param_1 + 0x10) + 1,0x20,0);

        uVar4 = uGpffffb9a8;

        *(int *)((int)uVar9 + 4) = (int)sVar1;

        puVar2 = *(u32 **)(*(int *)((int)uVar9 + 0x14) + 0x1c);

        if ((param_3 & 1) != 0) {

          *puVar2 = *puVar2 | 1;

        }

        if (((param_3 & 0x4000) == 0) && ((*(u8 *)((int)psVar11 + 5) & 8) != 0)) {

          uVar5 = FUN_003e6dc0();

          uStack_8 = CONCAT22(uVar4,uVar5);

          iVar6 = FUN_0017d060(uStack_8,sVar1,(char)psVar11[3]);

          if (*(short *)(iVar6 + 6) == 0) {

            *puVar2 = *puVar2 | 0x20;

          }

        }


        if (((puVar2 == (u32 *)0xfffffffc) || (param_2 == 0)) || (psVar11 == (short *)0x0)) {

          K_Assert((const char *)(u32)0x6aede8,0x45e);

        }

        if (psVar11[1] < 1) {

          puVar2[4] = (int)(puVar2[4] * (int)*(short *)(iVar10 + 2)) / 100;

        }

        else {

          puVar2[4] = (int)(puVar2[4] * (int)psVar11[1]) / 100;

        }


      }

    }

    psVar11 = psVar11 + 4;

    lVar12 = (long)((int)lVar12 + 1);

  } while( 1 );

}

// FUN_003F2940 NONMATCHING


u32 FUN_003f2940(u64 param_1,short *param_2,int param_3,u32 param_4)



{

  short sVar1;

  u32 *puVar2;

  u8 bVar3;

  u16 uVar4;

  u16 uVar5;

  int iVar6;

  u32 uVar7;

  long lVar8;

  u64 uVar9;

  int iVar10;

  u32 uStack_8;

  int iStack_4;

  

  iVar10 = 0;

  do {

    if (param_3 <= iVar10) {

      return 0;

    }

    sVar1 = *param_2;

    if (sVar1 != 0) {

      bVar3 = 1;

      iVar6 = func_00170ed0(sVar1,&iStack_4);

      if (((param_4 & 0x400) != 0) && (iStack_4 != 0)) {

        bVar3 = 0;

      }

      if (((((param_4 & 0x800) != 0) && (iStack_4 != 1)) && (iStack_4 != 2)) && (iStack_4 != 3)) {

        bVar3 = 0;

      }

      if (iStack_4 < 1) {


        if (((((uVar7 & 0xff) != 6) || (lVar8 = datGetScenarioMode(), lVar8 == 0)) &&

            (*(short *)(&DAT_006acc60 + (uVar7 & 0xff) * 2) != -1)) &&

           (lVar8 = datGetFlag(), lVar8 == 0)) {

          bVar3 = 0;

        }

      }

      else if ((char)param_2[2] != '\x01') {

        lVar8 = func_001712d0(sVar1);

        if (lVar8 == 0x80) {

          uVar7 = 0xffffffff;

          if (iStack_4 - 1U < 2) {

            uVar7 = 6;

          }

          if (((uVar7 != 0xffffffff) && (*(short *)(&DAT_006acc60 + (uVar7 & 0xff) * 2) != -1)) &&

             (lVar8 = datGetFlag(), lVar8 == 0)) {

            bVar3 = 0;

          }

        }

        else if (lVar8 == 0x4000) {

          uVar7 = 0xffffffff;

          if (iStack_4 - 1U < 2) {

            uVar7 = 7;

          }

          if (((uVar7 != 0xffffffff) &&

              (((uVar7 & 0xff) != 6 || (lVar8 = datGetScenarioMode(), lVar8 == 0)))) &&

             ((*(short *)(&DAT_006acc60 + (uVar7 & 0xff) * 2) != -1 &&

              (lVar8 = datGetFlag(), lVar8 == 0)))) {

            bVar3 = 0;

          }

        }

      }

      if (bVar3) {

        if ((param_4 & 0x1000) != 0) {

          return 1;

        }

        if (((param_4 & 0x2000) != 0) &&

           (lVar8 = FUN_003c4bf0(param_1,(int)param_1 + 4,sVar1), lVar8 != 0)) {

          bVar3 = 0;

        }

      }

      if (((char)param_2[2] == '\x01') && (lVar8 = datGetFlag(0x1310), lVar8 == 0)) {

        bVar3 = 0;

      }

      if (bVar3) {

        uVar9 = FUN_003c5a40(param_1,*(u16 *)((int)param_1 + 0x10) + 1,0x20,0);

        uVar4 = uGpffffb9a8;

        *(int *)((int)uVar9 + 4) = (int)sVar1;

        puVar2 = *(u32 **)(*(int *)((int)uVar9 + 0x14) + 0x1c);

        *puVar2 = *puVar2 | param_4;

        if ((param_4 & 1) != 0) {

          *puVar2 = *puVar2 | 1;

        }

        if (((param_4 & 0x4000) == 0) && ((*(u8 *)((int)param_2 + 5) & 8) != 0)) {

          uVar5 = FUN_003e6dc0();

          uStack_8 = CONCAT22(uVar4,uVar5);

          iVar6 = FUN_0017d060(uStack_8,sVar1,(char)param_2[3]);

          if (*(short *)(iVar6 + 6) == 0) {

            *puVar2 = *puVar2 | 0x20;

          }

        }



      }

    }

    param_2 = param_2 + 4;

    iVar10 = iVar10 + 1;

  } while( 1 );

}

// FUN_003F2D60


u64 FUN_003f2d60(int param_1)



{

  int iVar1;

  

  for (iVar1 = *(int *)(param_1 + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {

    FUN_003f2dc0(param_1,iVar1);

  }

  return 0;

}

// FUN_003F2DC0 NONMATCHING


u64 FUN_003f2dc0(int param_1,int param_2)



{

  short sVar1;

  u32 *puVar2;

  u32 uVar3;

  short sVar4;

  u16 uVar5;

  u32 uVar6;

  u32 uVar7;

  long lVar8;

  int iVar9;

  int iStack_4;

  

  puVar2 = *(u32 **)(*(int *)(param_2 + 0x14) + 0x1c);

  *puVar2 = *puVar2 & 0xffffffef;

  sVar1 = (short)puVar2[1];

  iStack_4 = -1;

  sVar4 = 0;

  func_00170ed0(sVar1,&iStack_4);

  if (iStack_4 == 4) {

    sVar4 = func_00170760(1,sVar1);

  }

  else if ((((iStack_4 == 3) || (iStack_4 == 2)) || (iStack_4 == 1)) || (iStack_4 == 0)) {

    sVar4 = 0;

    for (iVar9 = 0; iVar9 < 300; iVar9 = iVar9 + 1) {

      uVar7 = datGetEquipmentId(1,iVar9);

      if ((long)sVar1 == (uVar7 & 0xffff)) {

        sVar4 = sVar4 + 1;

      }

    }

  }

  *(short *)((int)puVar2 + 0xe) = sVar4;

  if (0x62 < sVar4) {

    *puVar2 = *puVar2 | 0x10;

  }

  uVar3 = puVar2[4];

  uVar6 = datGetMoney();

  if (uVar6 < uVar3) {

    *puVar2 = *puVar2 | 0x10;

  }

  uVar5 = FUN_003e6dc0();

  lVar8 = FUN_0017d250(uVar5,(short)puVar2[1]);

  if (lVar8 == 0) {

    *puVar2 = *puVar2 | 0x20;

  }

  if ((*puVar2 & 0x20) != 0) {

    *puVar2 = *puVar2 | 0x10;

  }

  return 0;

}

// FUN_003F2F70 NONMATCHING


u32 FUN_003f2f70(u64 param_1,long param_2,u32 param_3)



{

  u32 uVar1;

  int iVar2;

  long lVar3;

  int iVar4;

  int iVar5;

  int *piVar6;

  u32 uVar7;

  int iStack_4;

  

  uVar7 = 0;

  if ((param_3 & 1) != 0) {

    uVar7 = 0x400;

  }

  if ((param_3 & 2) != 0) {

    uVar7 = uVar7 | 0x800;

  }

  if ((param_2 < 0) || (8 < param_2)) {

    K_Assert((const char *)(u32)0x6aede8,0xb9);

  }

  lVar3 = datGetScenarioMode();

  iVar5 = (int)param_2;

  if (lVar3 != 0) {

    iVar5 = iVar5 + 9;

  }

  iVar4 = iVar5 * 0x24;

  iVar2 = *(int *)(*(int *)((int)param_1 + 0x24) + 0x44);

  *(short *)(iVar2 + 4) = (short)param_2;

  *(short *)(iVar2 + 6) = (short)param_2;


  if (lVar3 == 0) {


  }

  if ((lVar3 != 0) && (lVar3 = FUN_003f25e0(param_1,lVar3,uVar7 | 0x1000), lVar3 != 0)) {

    return 1;

  }

  iStack_4 = 0;

  while( 1 ) {

    if (iStack_4 < *(int *)(&DAT_006ac9e8 + iVar4)) {

      piVar6 = (int *)(((u32 **)&PTR_DAT_006ac9ec)[iVar5 * 9] + iStack_4 * 0xc);

      iStack_4 = iStack_4 + 1;

    }

    else {

      piVar6 = (int *)0x0;

    }

    if ((piVar6 == (int *)0x0) ||

       (iVar2 = *piVar6, uVar1 = datGetLevel(1), (int)(uVar1 & 0xff) < iVar2)) break;


    if (lVar3 != 0) {

      return 1;

    }

  }

  iStack_4 = 0;

  while( 1 ) {


    if (lVar3 == 0) {

      lVar3 = 0;

    }

    else {

      iStack_4 = iStack_4 + 1;

    }

    if (lVar3 == 0) break;


    if (lVar3 != 0) {

      return 1;

    }

  }


  iStack_4 = 1;

  while( 1 ) {

    if (iVar2 < iStack_4) {

      return 0;

    }

    iVar4 = *(int *)(((u32 **)&PTR_DAT_006ac9f0)[iVar5 * 9] + 8) + iStack_4 * 0x20;

    if ((iVar4 != 0) &&

       (lVar3 = FUN_003f2940(param_1,*(short **)(iVar4 + 8),*(u32 *)(iVar4 + 4),
                             uVar7 | 0x1000), lVar3 != 0)) break;

    iStack_4 = iStack_4 + 1;

  }

  return 1;

}

// FUN_003F33D0 NONMATCHING


u64 FUN_003f33d0(long param_1,u32 param_2)



{

  u8 *puVar1;

  u8 *puVar2;

  u32 uVar3;

  int iVar4;

  u32 uVar5;

  int iVar6;

  long lVar7;

  u64 uVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  u32 *puVar12;

  u8 **ppuVar13;

  u32 *puVar14;

  u64 uVar15;

  u32 uVar16;

  u32 uVar17;

  int iVar18;

  int *piVar19;

  u32 auStack_b0 [16];

  u32 auStack_70 [8];

  u32 auStack_50 [8];

  u32 auStack_30 [9];

  int iStack_c;

  u32 uStack_8;

  int iStack_4;

  

  uVar16 = 0;

  uVar17 = 5;

  if (param_1 == 3) {

    uVar17 = 4;

  }

  if ((param_2 & 1) != 0) {

    uVar16 = 0x400;

  }

  if ((param_2 & 2) != 0) {

    uVar16 = uVar16 | 0x800;

  }

  if ((param_1 < 0) || (8 < param_1)) {

    K_Assert((const char *)(u32)0x6aede8,0xb9);

  }

  lVar7 = datGetScenarioMode();

  iVar18 = (int)param_1;

  iVar11 = iVar18;

  if (lVar7 != 0) {

    iVar11 = iVar18 + 9;

  }

  iVar9 = iVar11 * 0x24;

  uVar8 = FUN_003c58f0(0,0x58,uVar17,0x1a);

  iVar4 = (int)uVar8;

  iVar6 = *(int *)(*(int *)(iVar4 + 0x24) + 0x44);

  *(short *)(iVar6 + 4) = (short)param_1;

  *(short *)(iVar6 + 6) = (short)param_1;


  if (lVar7 == 0) {

    uStack_8 = 0;


  }

  if (lVar7 != 0) {

    uGpffffb9a8 = (u16)(u8)uStack_8;


  }

  iStack_c = 0;

  while( 1 ) {

    if (iStack_c < *(int *)(&DAT_006ac9e8 + iVar9)) {

      piVar19 = (int *)(((u32 **)&PTR_DAT_006ac9ec)[iVar11 * 9] + iStack_c * 0xc);

      iStack_c = iStack_c + 1;

    }

    else {

      piVar19 = (int *)0x0;

    }

    if ((piVar19 == (int *)0x0) ||

       (iVar6 = *piVar19, uVar5 = datGetLevel(1), (int)(uVar5 & 0xff) < iVar6)) break;

    uGpffffb9a8 = (u8)iStack_c | 0x100;


  }

  iStack_4 = 0;

  while( 1 ) {


    if (lVar7 == 0) {

      lVar7 = 0;

    }

    else {

      iStack_4 = iStack_4 + 1;

    }

    if (lVar7 == 0) break;

    uGpffffb9a8 = (u8)iStack_4 | 0x200;


  }


  for (iStack_4 = 1; iStack_4 <= iVar6; iStack_4 = iStack_4 + 1) {

    iVar10 = *(int *)(((u32 **)&PTR_DAT_006ac9f0)[iVar11 * 9] + 8) + iStack_4 * 0x20;

    if (iVar10 != 0) {

      uGpffffb9a8 = (u16)iStack_4 & 0xff | 0x300;


    }

  }


  if (lVar7 == 0) {


  }

  if (lVar7 != 0) {


  }

  if (param_1 != 3) {

    if ((param_2 & 4) != 0) {

      uVar15 = 0;


      if (lVar7 != 0) {


        FUN_003c5a20(lVar7);

      }

      FUN_003c5a20(uVar8);

      return uVar15;

    }

    FUN_0017d610(param_1);


    if (lVar7 != 0) {


      FUN_003c5a20(lVar7);

    }

  }

  FUN_003c7000(uVar8,0x3f3280,0);

  FUN_003c6ee0(uVar8);

  ppuVar13 = (u8 **)&PTR_FUN_006aee00;

  puVar12 = auStack_30;

  iVar11 = 4;

  do {

    puVar1 = *ppuVar13;

    puVar2 = ppuVar13[1];

    ppuVar13 = ppuVar13 + 2;

    iVar11 = iVar11 + -1;

    *puVar12 = (u32)(puVar1);

    puVar12[1] = (u32)(puVar2);

    puVar12 = puVar12 + 2;

  } while (0 < iVar11);

  ppuVar13 = (u8 **)&PTR_FUN_006aee20;

  puVar12 = auStack_50;

  iVar11 = 4;

  do {

    puVar1 = *ppuVar13;

    puVar2 = ppuVar13[1];

    ppuVar13 = ppuVar13 + 2;

    iVar11 = iVar11 + -1;

    *puVar12 = (u32)(puVar1);

    puVar12[1] = (u32)(puVar2);

    puVar12 = puVar12 + 2;

  } while (0 < iVar11);

  ppuVar13 = (u8 **)&PTR_FUN_006aee40;

  puVar12 = auStack_70;

  iVar11 = 4;

  do {

    puVar1 = *ppuVar13;

    puVar2 = ppuVar13[1];

    ppuVar13 = ppuVar13 + 2;

    iVar11 = iVar11 + -1;

    *puVar12 = (u32)(puVar1);

    puVar12[1] = (u32)(puVar2);

    puVar12 = puVar12 + 2;

  } while (0 < iVar11);

  puVar14 = &DAT_006aee60;

  puVar12 = auStack_b0;

  iVar11 = 8;

  do {

    uVar17 = *puVar14;

    uVar3 = puVar14[1];

    puVar14 = puVar14 + 2;

    iVar11 = iVar11 + -1;

    *puVar12 = uVar17;

    puVar12[1] = uVar3;

    puVar12 = puVar12 + 2;

  } while (0 < iVar11);

  FUN_003c5e80(uVar8,auStack_30[iVar18]);

  FUN_003c5e20(uVar8,auStack_50[iVar18]);

  FUN_003c5ee0(uVar8,auStack_70[iVar18]);

  FUN_003c6d40(uVar8,auStack_b0[iVar18 * 2],auStack_b0[iVar18 * 2 + 1]);

  if (param_1 == 4) {

    *(u16 *)(*(int *)(iVar4 + 0x24) + 6) = 10;

  }

  else {

    *(u16 *)(*(int *)(iVar4 + 0x24) + 6) = 0x14;

  }

  *(u16 *)(*(int *)(iVar4 + 0x24) + 8) = 10;

  return uVar8;

}

// FUN_003F3970


u64 FUN_003f3970(long param_1,u32 param_2)



{


  return FUN_003f39a0(param_1,0,param_2);
}

// FUN_003F39A0 NONMATCHING


u64 FUN_003f39a0(long param_1,long param_2,u32 param_3)



{

  u32 uVar1;

  int iVar2;

  long lVar3;

  u64 uVar4;

  int iVar5;

  u8 *puVar6;

  u32 uVar7;

  u32 uVar8;

  u8 bStack_10;

  u8 bStack_f;

  u16 uStack_e;

  u32 uStack_c;

  int iStack_4;

  

  uVar8 = 0;

  if (param_2 == 0) {

    dat0017d6d0(param_1,&bStack_10);

  }

  else {

    FUN_0017d700(param_1,0,&bStack_10);

  }

  uVar1 = 0;

  for (uVar7 = 0; uVar7 < 8; uVar7 = uVar7 + 1) {

    if ((*(short *)(&DAT_006acc60 + uVar7 * 2) == -1) || (lVar3 = datGetFlag(), lVar3 == 0)) {

      if ((uVar7 == 6) && (lVar3 = datGetScenarioMode(), lVar3 != 0)) {

        uVar1 = uVar1 | 0x40;

      }

    }

    else {

      uVar1 = uVar1 | 1 << (uVar7 & 0x1f) & 0xffffU;

    }

  }

  for (uVar7 = 0; uVar7 < 8; uVar7 = uVar7 + 1) {

    if (((uVar7 != 6) || (lVar3 = datGetScenarioMode(), lVar3 == 0)) &&

       (*(short *)(&DAT_006acc60 + uVar7 * 2) != -1)) {

      if (((u32)uStack_e & 1 << (uVar7 & 0x1f)) == 0) {

        datSetFlag(*(short *)(&DAT_006acc60 + uVar7 * 2),0);

      }

      else {

        datSetFlag();

      }

    }

  }

  if ((param_3 & 1) != 0) {

    uVar8 = 0x400;

  }

  if ((param_3 & 2) != 0) {

    uVar8 = uVar8 | 0x800;

  }

  if ((param_1 < 0) || (8 < param_1)) {

    K_Assert((const char *)(u32)0x6aede8,0xb9);

  }

  lVar3 = datGetScenarioMode();

  iVar5 = (int)param_1;

  if (lVar3 != 0) {

    iVar5 = iVar5 + 9;

  }

  uVar4 = FUN_003c58f0(0,0x58,5,0x1a);

  if (uStack_c < *(u32 *)(DAT_006ac9d0 + iVar5 * 0x24)) {

    puVar6 = (u8 *)((u32 **)&PTR_PTR_006ac9d4)[iVar5 * 9] + uStack_c * 0x14;

  }

  else {

    puVar6 = (u8 *)0x0;

  }

  if (puVar6 != (u8 *)0x0) {


  }

  iStack_4 = 0;

  while( 1 ) {

    if (iStack_4 < *(int *)(&DAT_006ac9e8 + iVar5 * 0x24)) {

      puVar6 = (u8 *)((u32 **)&PTR_DAT_006ac9ec)[iVar5 * 9] + iStack_4 * 0xc;

      iStack_4 = iStack_4 + 1;

    }

    else {

      puVar6 = (u8 *)0x0;

    }

    if ((puVar6 == (u8 *)0x0) || ((int)(u32)bStack_10 < iStack_4)) break;


  }

  for (iStack_4 = 1; iStack_4 <= (int)(u32)bStack_f; iStack_4 = iStack_4 + 1) {

    iVar2 = *(int *)(((u32 **)&PTR_DAT_006ac9f0)[iVar5 * 9] + 8) + iStack_4 * 0x20;

    if (iVar2 != 0) {


    }

  }

  for (uVar7 = 0; uVar7 < 8; uVar7 = uVar7 + 1) {

    if (((uVar7 != 6) || (lVar3 = datGetScenarioMode(), lVar3 == 0)) &&

       (*(short *)(&DAT_006acc60 + uVar7 * 2) != -1)) {

      if ((uVar1 & 1 << (uVar7 & 0x1f)) == 0) {

        datSetFlag(*(short *)(&DAT_006acc60 + uVar7 * 2),0);

      }

      else {

        datSetFlag();

      }

    }

  }

  return uVar4;

}

// FUN_003F3DC0 NONMATCHING


void FUN_003f3dc0(int param_1,u64 param_2)



{

  u32 *puVar1;

  long lVar2;

  int iVar3;

  

  for (iVar3 = *(int *)(param_1 + 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x10)) {

    puVar1 = *(u32 **)(*(int *)(iVar3 + 0x14) + 0x1c);

    lVar2 = FUN_003c4bf0(param_2,(int)param_2 + 4,(short)puVar1[1]);

    if (lVar2 == 0) {

      *puVar1 = *puVar1 | 0x80;

    }

    else {

      FUN_003c49e0(param_2,(int)param_2 + 4,lVar2);

    }

  }

  return;

}

// FUN_003F3E60 NONMATCHING


u32 FUN_003f3e60(int param_1,u64 param_2)



{

  long lVar1;

  int iVar2;

  

  iVar2 = *(int *)(param_1 + 4);

  while( 1 ) {

    if (iVar2 == 0) {

      return 0;

    }

    lVar1 = FUN_003c4bf0(param_2,(int)param_2 + 4,

                         *(u16 *)(*(int *)(*(int *)(iVar2 + 0x14) + 0x1c) + 4));

    if (lVar1 == 0) break;

    FUN_003c49e0(param_2,(int)param_2 + 4,lVar1);

    iVar2 = *(int *)(iVar2 + 0x10);

  }

  return 1;

}

// FUN_003F3F00


u32 FUN_003f3f00(u64 param_1)
{
  u32 uVar1;
  u32 lVar2;
  uVar1 = FUN_003fa1e0_u32();

  if ((lVar2 = FUN_003c6ce0(param_1), lVar2 != 0) ||
      (lVar2 = FUN_003c6d10(param_1), lVar2 != 0)) {
    func_0010a4e0(0,0,0,0);
  }

  lVar2 = FUN_003c6ca0(param_1);
  if ((lVar2 != 0) || (lVar2 = FUN_003c6cc0(param_1), lVar2 != 0)) {
    func_0010a4e0(0,0,0,5);
  }

  return uVar1;
}

// FUN_003F3FC0 NONMATCHING


void FUN_003f3fc0(int param_1,int param_2,u32 param_3,u64 param_4)



{

  u32 uVar1;

  short sVar2;

  u32 uVar3;

  int iVar4;

  int iVar5;

  long lVar6;

  int iVar7;

  u32 uVar8;

  int iVar9;

  u32 uVar10;

  

  iVar7 = (int)param_4;

  uVar3 = *(u32 *)(iVar7 + 0xc);

  iVar4 = *(int *)(*(int *)(iVar7 + 0x24) + 0x44);

  param_1 = param_1 + *(short *)(iVar4 + 0x28);

  param_2 = param_2 + *(short *)(iVar4 + 0x2a);

  lVar6 = FUN_003c6e10(param_4);

  if (lVar6 == 1) {

    uVar8 = 0xff;

  }

  else {

    uVar8 = param_3;

    if ((lVar6 != 0x14) && (uVar8 = 0, lVar6 == 0xc)) {

      uVar8 = 0xff;

    }

  }

  if (uVar8 != 0) {

    sVar2 = *(short *)(iVar4 + 0x44);

    (*DAT_00960090)(8,1);

    (*DAT_00960090)(6,0);

    RpSkyRenderStateSet(3,0x3200d);


    (*DAT_00960090)(8,0);

    (*DAT_00960090)(6,1);

    RpSkyRenderStateSet(3,0x7000d);

    FUN_0040e3c0(0x3f800000,0,0,((int)uVar8 * (int)sVar2) / 0xff & 0xff,0x23,0);

    RpSkyRenderStateSet(2,0x44);

    RpSkyRenderStateSet(3,0x717fb);

    FUN_0040e3c0(0,*(u16 *)(iVar4 + 0x38),*(u16 *)(iVar4 + 0x3a),uVar8 & 0xff,0x24,0);

    iVar9 = param_1 + *(short *)(iVar4 + 0x48);

    iVar5 = param_2 + *(short *)(iVar4 + 0x4a);

    uVar1 = ((int)uVar8 * (int)*(short *)(iVar4 + 0x54)) / 0xff;

    uVar10 = *(u32 *)(iVar4 + 0x50);

    iVar7 = *(int *)(*(int *)(iVar7 + 0x24) + 0x28);

    FUN_0040e3f0(0,0,0x3f800000,uVar10,iVar9 + -0x15,iVar5 + -1,uVar1 & 0xff,0x26,0,0,0);

    FUN_0040e3f0(0,0,0x3f800000,uVar10,iVar9 + -0x13,iVar5 + 3 + (iVar7 * 0x68) / 0xffff,

                 uVar1 & 0xff,0x27,0,0,0);

  }


  if (*(short *)(iVar4 + 6) == -1) {



  }

  else {



  }

  return;

}

// FUN_003F4350 NONMATCHING


void FUN_003f4350(int param_1,int param_2,long param_3,u64 param_4)



{

  u32 uVar1;

  u32 uVar2;

  int iVar3;

  int iVar4;

  long lVar5;

  int iVar6;

  long lVar7;

  int iVar8;

  u32 uVar9;

  

  iVar6 = (int)param_4;

  uVar2 = *(u32 *)(iVar6 + 0xc);

  iVar3 = *(int *)(*(int *)(iVar6 + 0x24) + 0x44);

  param_1 = param_1 + *(short *)(iVar3 + 0x28);

  param_2 = param_2 + *(short *)(iVar3 + 0x2a);

  lVar5 = FUN_003c6e10(param_4);

  if (lVar5 == 1) {

    lVar7 = 0xff;

  }

  else {

    lVar7 = param_3;

    if ((lVar5 != 0x14) && (lVar7 = 0, lVar5 == 0xc)) {

      lVar7 = 0xff;

    }

  }

  if (lVar7 != 0) {

    FUN_0040e3c0(0,param_1 + *(short *)(iVar3 + 0x38),param_2 + *(short *)(iVar3 + 0x3a),

                 ((int)lVar7 * (int)*(short *)(iVar3 + 0x44)) / 0xff & 0xff,0x22,0);

    iVar8 = param_1 + *(short *)(iVar3 + 0x48);

    iVar4 = param_2 + *(short *)(iVar3 + 0x4a);

    uVar1 = ((int)lVar7 * (int)*(short *)(iVar3 + 0x54)) / 0xff;

    uVar9 = *(u32 *)(iVar3 + 0x50);

    iVar6 = *(int *)(*(int *)(iVar6 + 0x24) + 0x28);

    FUN_0040e3f0(0,0,0x3f800000,uVar9,iVar8 + -0x15,iVar4 + -0xb,uVar1 & 0xff,0x24,0,0,0);

    FUN_0040e3f0(0,0,0x3f800000,uVar9,iVar8 + -0x13,iVar4 + 4 + (iVar6 * 0x68) / 0xffff,uVar1 & 0xff

                 ,0x25,0,0,0);

  }


  if (*(short *)(iVar3 + 6) == -1) {



  }

  else {


  }

  return;

}

// FUN_003F45E0 NONMATCHING


void FUN_003f45e0(int param_1,int param_2,long param_3,u64 param_4)



{

  u32 uVar1;

  u32 uVar2;

  int iVar3;

  int iVar4;

  long lVar5;

  int iVar6;

  long lVar7;

  int iVar8;

  u32 uVar9;

  

  iVar6 = (int)param_4;

  uVar2 = *(u32 *)(iVar6 + 0xc);

  iVar3 = *(int *)(*(int *)(iVar6 + 0x24) + 0x44);

  param_1 = param_1 + *(short *)(iVar3 + 0x28);

  param_2 = param_2 + *(short *)(iVar3 + 0x2a);

  lVar5 = FUN_003c6e10(param_4);

  if (lVar5 == 1) {

    lVar7 = 0xff;

  }

  else {

    lVar7 = param_3;

    if ((lVar5 != 0x14) && (lVar7 = 0, lVar5 == 0xc)) {

      lVar7 = 0xff;

    }

  }

  if (lVar7 != 0) {

    FUN_0040e3c0(0,param_1 + *(short *)(iVar3 + 0x38),param_2 + *(short *)(iVar3 + 0x3a),

                 ((int)lVar7 * (int)*(short *)(iVar3 + 0x44)) / 0xff & 0xff,0x26,0);

    iVar8 = param_1 + *(short *)(iVar3 + 0x48);

    iVar4 = param_2 + *(short *)(iVar3 + 0x4a);

    uVar1 = ((int)lVar7 * (int)*(short *)(iVar3 + 0x54)) / 0xff;

    uVar9 = *(u32 *)(iVar3 + 0x50);

    iVar6 = *(int *)(*(int *)(iVar6 + 0x24) + 0x28);

    FUN_0040e3f0(0,0,0x3f800000,uVar9,iVar8 + -0x15,iVar4 + -0xb,uVar1 & 0xff,0x28,0,0,0);

    FUN_0040e3f0(0,0,0x3f800000,uVar9,iVar8 + -0x13,iVar4 + 4 + (iVar6 * 0x68) / 0xffff,uVar1 & 0xff

                 ,0x29,0,0,0);

  }


  if (*(short *)(iVar3 + 6) == -1) {



  }

  else {


  }

  return;

}

// FUN_003F4870 NONMATCHING


void FUN_003f4870(int param_1,int param_2,long param_3,u64 param_4)



{

  u32 uVar1;

  u32 uVar2;

  int iVar3;

  long lVar4;

  int iVar5;

  long lVar6;

  int iVar7;

  int iVar8;

  u32 uVar9;

  

  iVar5 = (int)param_4;

  uVar2 = *(u32 *)(iVar5 + 0xc);

  iVar3 = *(int *)(*(int *)(iVar5 + 0x24) + 0x44);

  param_1 = param_1 + *(short *)(iVar3 + 0x28);

  param_2 = param_2 + *(short *)(iVar3 + 0x2a);

  lVar4 = FUN_003c6e10(param_4);

  if (lVar4 == 1) {

    lVar6 = 0xff;

  }

  else {

    lVar6 = param_3;

    if ((lVar4 != 0x14) && (lVar6 = 0, lVar4 == 0xc)) {

      lVar6 = 0xff;

    }

  }

  if (lVar6 != 0) {

    FUN_0040e3c0(0,param_1 + *(short *)(iVar3 + 0x38),param_2 + *(short *)(iVar3 + 0x3a),

                 ((int)lVar6 * (int)*(short *)(iVar3 + 0x44)) / 0xff & 0xff,0x16,0);

    iVar7 = param_1 + *(short *)(iVar3 + 0x48);

    iVar8 = param_2 + *(short *)(iVar3 + 0x4a);

    uVar1 = ((int)lVar6 * (int)*(short *)(iVar3 + 0x54)) / 0xff;

    uVar9 = *(u32 *)(iVar3 + 0x50);

    iVar3 = *(int *)(*(int *)(iVar5 + 0x24) + 0x28);

    FUN_0040e3f0(0,0,0x3f800000,uVar9,iVar7 + -0x15,iVar8 + -1,uVar1 & 0xff,0x18,0,0,0);

    FUN_0040e3f0(0,0,0x3f800000,uVar9,iVar7 + -0x13,iVar8 + (iVar3 * 0x56) / 0xffff,uVar1 & 0xff,

                 0x19,0,0,0);

  }



  return;

}

// FUN_003F4A90 NONMATCHING


u64

FUN_003f4a90(int param_1,int param_2,int param_3,int param_4,u64 param_5,short *param_6)



{

  u32 uVar1;

  

  param_1 = param_1 + *param_6;

  param_2 = param_2 + param_6[1];

  uVar1 = (u32)((DAT_007caef0 * (float)param_3 * (float)(int)param_6[6]) / 255.0);

  if (param_4 != 4) {

    if (param_4 == 3) {

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0x9d,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0x9e,0);

      return 0;

    }

    if (param_4 == 2) {

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0x6c,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0x6d,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0x72,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0x73,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0x7f,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0x80,0);

      return 0;

    }

    if ((param_4 == 1) || (param_4 == 0)) {

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xcf,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xd0,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xd5,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xd6,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xd2,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xd3,0);

      FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xd4,0);

      return 0;

    }

  }

  FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xc1,0);

  FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xc2,0);

  FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xcc,0);

  FUN_0040e3c0(0,param_1,param_2,uVar1 & 0xff,0xcd,0);

  return 0;

}

// FUN_003F4DE0 NONMATCHING


void FUN_003f4de0(int param_1,int param_2,u64 param_3,u64 param_4)



{

  u32 uVar1;

  short sVar2;

  int iVar3;

  long lVar4;

  int *piVar5;

  u32 *puVar6;

  int *piVar7;

  u32 *puVar8;

  int iVar9;

  int iVar10;

  u64 uVar11;

  int iVar12;

  int iVar13;

  u32 uVar14;

  u32 uVar15;

  u32 auStack_140 [12];

  u32 uStack_110;

  u32 uStack_10c;

  int iStack_108;

  u32 auStack_100 [9];

  u32 uStack_dc;

  u32 uStack_d8;

  int iStack_d4;

  u32 auStack_c0 [6];

  u32 uStack_a8;

  u32 uStack_a4;

  int iStack_a0;

  u32 auStack_80 [4];

  u32 uStack_70;

  int iStack_6c;

  int aiStack_40 [16];

  

  iVar9 = (int)param_4;

  uVar14 = *(u32 *)(iVar9 + 0xc);

  iVar3 = *(int *)(*(int *)(iVar9 + 0x24) + 0x44);

  iVar12 = iVar3 + 0x28;

  param_1 = param_1 + *(short *)(iVar3 + 0x28);

  param_2 = param_2 + *(short *)(iVar3 + 0x2a);

  lVar4 = FUN_003c6e10(param_4);

  if (lVar4 == 1) {

    uVar11 = 0xff;

  }

  else {

    uVar11 = param_3;

    if ((lVar4 != 0x14) && (uVar11 = 0, lVar4 == 0xc)) {

      uVar11 = 0xff;

    }

  }

  sVar2 = *(short *)(iVar3 + 6);

  iVar10 = (int)uVar11;

  if (sVar2 == -5) {


    puVar8 = &DAT_006aeea0;

    puVar6 = auStack_100;

    iVar12 = 0xf;

    do {

      uVar14 = *puVar8;

      puVar8 = puVar8 + 1;

      iVar12 = iVar12 + -1;

      *puVar6 = uVar14;

      puVar6 = puVar6 + 1;

    } while (0 < iVar12);

    param_1 = param_1 + *(short *)(iVar3 + 0x48);

    param_2 = param_2 + *(short *)(iVar3 + 0x4a);

    uVar1 = (iVar10 * *(short *)(iVar3 + 0x54)) / 0xff;

    uVar14 = *(u32 *)(iVar3 + 0x50);

    iVar3 = *(int *)(*(int *)(iVar9 + 0x24) + 0x28);

    FUN_0040e3f0(0,0,0x3f800000,uVar14,param_1,param_2,uVar1 & 0xff,uStack_dc,0,0,0);

    FUN_0040e3f0(0,0,0x3f800000,uVar14,param_1,param_2 + (iStack_d4 * iVar3) / 0xffff,uVar1 & 0xff,

                 uStack_d8,0,0,0);

  }

  else if (sVar2 == -4) {


    puVar8 = &DAT_006aeea0;

    puVar6 = auStack_c0;

    iVar12 = 0xf;

    do {

      uVar15 = *puVar8;

      puVar8 = puVar8 + 1;

      iVar12 = iVar12 + -1;

      *puVar6 = uVar15;

      puVar6 = puVar6 + 1;

    } while (0 < iVar12);

    iVar13 = param_1 + *(short *)(iVar3 + 0x48);

    iVar12 = param_2 + *(short *)(iVar3 + 0x4a);

    uVar1 = (iVar10 * *(short *)(iVar3 + 0x54)) / 0xff;

    uVar15 = *(u32 *)(iVar3 + 0x50);

    iVar9 = *(int *)(*(int *)(iVar9 + 0x24) + 0x28);

    FUN_0040e3f0(0,0,0x3f800000,uVar15,iVar13,iVar12,uVar1 & 0xff,uStack_a8,0,0,0);

    FUN_0040e3f0(0,0,0x3f800000,uVar15,iVar13,iVar12 + (iStack_a0 * iVar9) / 0xffff,uVar1 & 0xff,

                 uStack_a4,0,0,0);




  }

  else if (sVar2 == -3) {


    puVar8 = &DAT_006aeea0;

    puVar6 = auStack_80;

    iVar12 = 0xf;

    do {

      uVar15 = *puVar8;

      puVar8 = puVar8 + 1;

      iVar12 = iVar12 + -1;

      *puVar6 = uVar15;

      puVar6 = puVar6 + 1;

    } while (0 < iVar12);

    iVar13 = param_1 + *(short *)(iVar3 + 0x48);

    iVar12 = param_2 + *(short *)(iVar3 + 0x4a);

    uVar1 = (iVar10 * *(short *)(iVar3 + 0x54)) / 0xff;

    uVar15 = *(u32 *)(iVar3 + 0x50);

    iVar9 = *(int *)(*(int *)(iVar9 + 0x24) + 0x28);

    FUN_0040e3f0(0,0,0x3f800000,uVar15,iVar13,iVar12,uVar1 & 0xff,auStack_80[3],0,0,0);

    FUN_0040e3f0(0,0,0x3f800000,uVar15,iVar13,iVar12 + (iStack_6c * iVar9) / 0xffff,uVar1 & 0xff,

                 uStack_70,0,0,0);




  }

  else if (sVar2 == -2) {


    piVar7 = (int *)(&DAT_006aeea0);

    piVar5 = aiStack_40;

    iVar12 = 0xf;

    do {

      iVar13 = *piVar7;

      piVar7 = piVar7 + 1;

      iVar12 = iVar12 + -1;

      *piVar5 = iVar13;

      piVar5 = piVar5 + 1;

    } while (0 < iVar12);

    iVar13 = param_1 + *(short *)(iVar3 + 0x48);

    iVar12 = param_2 + *(short *)(iVar3 + 0x4a);

    uVar1 = (iVar10 * *(short *)(iVar3 + 0x54)) / 0xff;

    uVar15 = *(u32 *)(iVar3 + 0x50);

    iVar9 = *(int *)(*(int *)(iVar9 + 0x24) + 0x28);

    FUN_0040e3f0(0,0,0x3f800000,uVar15,iVar13,iVar12,uVar1 & 0xff,aiStack_40[0],0,0,0);

    FUN_0040e3f0(0,0,0x3f800000,uVar15,iVar13,iVar12 + (aiStack_40[2] * iVar9) / 0xffff,uVar1 & 0xff

                 ,aiStack_40[1],0,0,0);




  }

  else {


    puVar8 = &DAT_006aeea0;

    puVar6 = auStack_140;

    iVar12 = 0xf;

    do {

      uVar15 = *puVar8;

      puVar8 = puVar8 + 1;

      iVar12 = iVar12 + -1;

      *puVar6 = uVar15;

      puVar6 = puVar6 + 1;

    } while (0 < iVar12);

    iVar13 = param_1 + *(short *)(iVar3 + 0x48);

    iVar12 = param_2 + *(short *)(iVar3 + 0x4a);

    uVar1 = (iVar10 * *(short *)(iVar3 + 0x54)) / 0xff;

    uVar15 = *(u32 *)(iVar3 + 0x50);

    iVar9 = *(int *)(*(int *)(iVar9 + 0x24) + 0x28);

    FUN_0040e3f0(0,0,0x3f800000,uVar15,iVar13,iVar12,uVar1 & 0xff,uStack_110,0,0,0);

    FUN_0040e3f0(0,0,0x3f800000,uVar15,iVar13,iVar12 + (iStack_108 * iVar9) / 0xffff,uVar1 & 0xff,

                 uStack_10c,0,0,0);




  }

  return;

}

// FUN_003F55B0 NONMATCHING


void FUN_003f55b0(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5,

                 u32 param_6)



{

  u32 uVar1;

  u32 uVar2;

  u32 *puVar3;

  u64 uVar4;

  int iVar5;

  u32 *puVar6;

  u32 *puVar7;

  u32 uVar8;

  int iVar9;

  u32 uVar10;

  u32 auStack_50 [12];

  u8 auStack_20 [24];

  u32 auStack_8 [2];

  

  iVar9 = 5;

  auStack_8[0] = DAT_007cd8f8;

  auStack_8[1] = DAT_007cd8fc;

  puVar7 = &DAT_006aef00;

  puVar6 = auStack_50;

  iVar5 = iVar9;

  do {

    uVar1 = *puVar7;

    uVar2 = puVar7[1];

    puVar7 = puVar7 + 2;

    iVar5 = iVar5 + -1;

    *puVar6 = uVar1;

    puVar6[1] = uVar2;

    puVar6 = puVar6 + 2;

  } while (0 < iVar5);

  uVar8 = 0;

  puVar3 = *(u32 **)(*(int *)(param_5 + 0x14) + 0x1c);

  if (((param_6 & 1) != 0) &&

     (uVar8 = (u32)((**(u32 **)(*(int *)(param_4 + 0x24) + 0x44) & 1) == 0), uVar8 != 0)) {

    if ((*puVar3 & 1) == 0) {

      iVar9 = 6;

    }

    else {

      iVar9 = 1;

    }

  }

  uVar10 = param_3;

  if (((param_6 & 4) == 0) && ((*puVar3 & 0x10) != 0)) {

    uVar10 = (u32)((float)(int)param_3 * DAT_007cad80);

  }

  if ((*puVar3 & 0x80) != 0) {

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,1,0);

  }

  FUN_0040e3c0(0,param_1,param_2,uVar10 & 0xff,0,(u32)(u8)puVar3[2] * 2 + uVar8);

  uVar4 = func_00171110((short)puVar3[1],(char)puVar3[3]);

  FUN_003b2cb0(0,(int)param_1 + 0x20,(int)param_2 + 1,uVar10 | 0xffffff00,(char)iVar9,1,uVar4,0,0);

  if ((param_6 & 2) == 0) {

    if ((*puVar3 & 0x20) == 0) {

      sprintf((char *)auStack_20,0x7cd900,puVar3[4]);

      FUN_0040eb50(0,(int)param_1 + 0x16c,(int)param_2 + 0xb,uVar10 & 0xff,auStack_8[uVar8],

                   auStack_20,9);

    }

    else {

      iVar5 = FUN_003e6dc0();

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_50[iVar5 * 2 + uVar8],0);

    }

  }

  return;

}

// FUN_003F5830 NONMATCHING


void FUN_003f5830(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5,

                 u32 param_6)



{

  u8 bVar1;

  u32 *puVar2;

  u64 uVar3;

  u32 uVar4;

  int iVar5;

  int iVar6;

  u8 uVar7;

  u8 auStack_20 [24];

  u32 auStack_8 [2];

  

  uVar7 = 5;

  auStack_8[0] = DAT_007cd908;

  auStack_8[1] = DAT_007cd90c;

  puVar2 = *(u32 **)(*(int *)(param_5 + 0x14) + 0x1c);

  bVar1 = (param_6 & 1) != 0;

  if (bVar1) {

    uVar7 = 6;

  }

  uVar4 = (u32)bVar1;

  if ((*puVar2 & 0x10) != 0) {

    param_3 = (u32)((float)(int)param_3 * DAT_007cad80);

  }

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x85,uVar4 << 1);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x86,uVar4 << 1);

  iVar6 = (int)param_1;

  iVar5 = (int)param_2;

  FUN_0040e3c0(0,iVar6 + 0xe,iVar5 + 3,param_3 & 0xff,3,

               uVar4 + (*(u8 *)((u32)*(u16 *)(puVar2[5] + 2) * 0xe + DAT_007ce420 + 2) - 1) *

                       2);

  FUN_003b32d0(0,iVar6 + 0x75,iVar5 + 2,param_3 | 0xffffff00,uVar7,1,

               DAT_007ce4e4 + (u32)*(u16 *)(puVar2[5] + 2) * 0x11,0,0x78);

  sprintf((char *)auStack_20,0x7cd900,*(u8 *)(puVar2[5] + 4));

  FUN_0040eb50(0,iVar6 + 0x14e,iVar5 + 10,param_3 & 0xff,auStack_8[uVar4],auStack_20,1);

  if ((short)puVar2[7] != 0) {

    FUN_0040e3c0(0,iVar6 + 0x15e,iVar5 + -1,param_3 & 0xff,4,(u32)(u8)puVar2[6] * 2 + uVar4);

    uVar3 = func_00171110((short)puVar2[7],2);

    FUN_003b32d0(0,iVar6 + 0x184,iVar5 + 1,param_3 | 0xffffff00,uVar7,1,uVar3,0,0x73);

  }

  if (uVar4 == 0) {

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x89,0);

  }

  return;

}

// FUN_003F5AB0 NONMATCHING


void FUN_003f5ab0(u64 param_1,u64 param_2,u8 param_3,u64 param_4,

                 int param_5)



{

  char cVar1;

  short sVar2;

  short sVar3;

  int iVar4;

  char *pcVar5;

  char *pcVar6;

  short *psVar7;

  short *psVar8;

  u32 uVar9;

  short asStack_30 [8];

  u8 auStack_20 [24];

  char acStack_8 [8];

  

  pcVar6 = (char *)(&DAT_007cd910);

  pcVar5 = acStack_8;

  iVar4 = 5;

  do {

    cVar1 = *pcVar6;

    pcVar6 = pcVar6 + 1;

    iVar4 = iVar4 + -1;

    *pcVar5 = cVar1;

    pcVar5 = pcVar5 + 1;

  } while (0 < iVar4);

  psVar8 = (s16 *)(&DAT_006aef30);

  psVar7 = asStack_30;

  iVar4 = 4;

  do {

    sVar2 = *psVar8;

    sVar3 = psVar8[1];

    psVar8 = psVar8 + 2;

    iVar4 = iVar4 + -1;

    *psVar7 = sVar2;

    psVar7[1] = sVar3;

    psVar7 = psVar7 + 2;

  } while (0 < iVar4);

  iVar4 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x36,0);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x37,0);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x38,*(u8 *)(iVar4 + 8));

  FUN_0040e3c0(0,param_1,param_2,param_3,0x39,0);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x3a,0);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x3b,0);

  for (uVar9 = 0; (int)uVar9 < 4; uVar9 = uVar9 + 1) {

    if (((long)acStack_8[(int)(*(u32 *)(iVar4 + 8) & 0xf00) >> 8] & (long)(1 << (uVar9 & 0x1f))) ==

        0) {

      FUN_0040e3c0(0,(int)param_1 + (uVar9 & 1) * 0x7c,(int)param_2 + ((int)uVar9 >> 1 & 1U) * 0x15,

                   param_3,0x3c,0);

    }

    else {

      sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar4 + uVar9 * 2 + 0x14));

      FUN_0040eb50(0,(int)param_1 + (int)asStack_30[uVar9 * 2],

                   (int)param_2 + (int)asStack_30[uVar9 * 2 + 1],param_3,1,auStack_20,2);

    }

  }

  return;

}

// FUN_003F5D10 NONMATCHING


void FUN_003f5d10(u64 param_1,u64 param_2,u8 param_3,u64 param_4,

                 int param_5)



{

  char cVar1;

  short sVar2;

  short sVar3;

  int iVar4;

  char *pcVar5;

  char *pcVar6;

  short *psVar7;

  short *psVar8;

  u32 uVar9;

  short asStack_30 [8];

  u8 auStack_20 [24];

  char acStack_8 [8];

  

  pcVar6 = (char *)(&DAT_007cd918);

  pcVar5 = acStack_8;

  iVar4 = 5;

  do {

    cVar1 = *pcVar6;

    pcVar6 = pcVar6 + 1;

    iVar4 = iVar4 + -1;

    *pcVar5 = cVar1;

    pcVar5 = pcVar5 + 1;

  } while (0 < iVar4);

  psVar8 = (s16 *)(&DAT_006aef40);

  psVar7 = asStack_30;

  iVar4 = 4;

  do {

    sVar2 = *psVar8;

    sVar3 = psVar8[1];

    psVar8 = psVar8 + 2;

    iVar4 = iVar4 + -1;

    *psVar7 = sVar2;

    psVar7[1] = sVar3;

    psVar7 = psVar7 + 2;

  } while (0 < iVar4);

  iVar4 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x34,0);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x35,*(u8 *)(iVar4 + 8));

  FUN_0040e3c0(0,param_1,param_2,param_3,0x36,0);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x37,0);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x38,0);

  for (uVar9 = 0; (int)uVar9 < 4; uVar9 = uVar9 + 1) {

    if (((long)acStack_8[(int)(*(u32 *)(iVar4 + 8) & 0xf00) >> 8] & (long)(1 << (uVar9 & 0x1f))) ==

        0) {

      FUN_0040e3c0(0,(int)param_1 + (uVar9 & 1) * 0x7c,(int)param_2 + ((int)uVar9 >> 1 & 1U) * 0x15,

                   param_3,0x39,0);

    }

    else {

      sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar4 + uVar9 * 2 + 0x14));

      FUN_0040eb50(0,(int)param_1 + (int)asStack_30[uVar9 * 2],

                   (int)param_2 + (int)asStack_30[uVar9 * 2 + 1],param_3,1,auStack_20,2);

    }

  }

  return;

}

// FUN_003F5F50 NONMATCHING


void FUN_003f5f50(u64 param_1,u64 param_2,u8 param_3,u64 param_4,

                 int param_5)



{

  char cVar1;

  short sVar2;

  short sVar3;

  u32 uVar4;

  u32 uVar5;

  int iVar6;

  char *pcVar7;

  int iVar8;

  char *pcVar9;

  short *psVar10;

  u32 *puVar11;

  short *psVar12;

  u32 *puVar13;

  u32 uVar14;

  int iVar15;

  u32 auStack_70 [16];

  short asStack_30 [8];

  u8 auStack_20 [24];

  char acStack_8 [8];

  

  pcVar9 = (char *)(&DAT_007cd920);

  pcVar7 = acStack_8;

  iVar6 = 5;

  do {

    cVar1 = *pcVar9;

    pcVar9 = pcVar9 + 1;

    iVar6 = iVar6 + -1;

    *pcVar7 = cVar1;

    pcVar7 = pcVar7 + 1;

  } while (0 < iVar6);

  psVar12 = (s16 *)(&DAT_006aef50);

  psVar10 = asStack_30;

  iVar6 = 4;

  do {

    sVar2 = *psVar12;

    sVar3 = psVar12[1];

    psVar12 = psVar12 + 2;

    iVar6 = iVar6 + -1;

    *psVar10 = sVar2;

    psVar10[1] = sVar3;

    psVar10 = psVar10 + 2;

  } while (0 < iVar6);

  iVar6 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

  iVar15 = (int)param_2;

  FUN_0040e3c0(0,param_1,iVar15 + 1,param_3,0x38,0);

  puVar13 = &DAT_006aef60;

  puVar11 = auStack_70;

  iVar8 = 7;

  do {

    uVar4 = *puVar13;

    uVar5 = puVar13[1];

    puVar13 = puVar13 + 2;

    iVar8 = iVar8 + -1;

    *puVar11 = uVar4;

    puVar11[1] = uVar5;

    puVar11 = puVar11 + 2;

  } while (0 < iVar8);

  FUN_0040e3c0(0,param_1,iVar15 + 1,param_3,0x39,auStack_70[*(u8 *)(iVar6 + 8)]);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x3a,0);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x3b,0);

  FUN_0040e3c0(0,param_1,param_2,param_3,0x3c,0);

  for (uVar14 = 0; (int)uVar14 < 4; uVar14 = uVar14 + 1) {

    if (((long)acStack_8[(int)(*(u32 *)(iVar6 + 8) & 0xf00) >> 8] & (long)(1 << (uVar14 & 0x1f)))

        == 0) {

      FUN_0040e3c0(0,(int)param_1 + (uVar14 & 1) * 0x7c,iVar15 + ((int)uVar14 >> 1 & 1U) * 0x15,

                   param_3,0x3d,0);

    }

    else {

      sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar6 + uVar14 * 2 + 0x14));

      FUN_0040eb50(0,(int)param_1 + (int)asStack_30[uVar14 * 2],iVar15 + asStack_30[uVar14 * 2 + 1],

                   param_3,1,auStack_20,2);

    }

  }

  return;

}

// FUN_003F61D0 NONMATCHING


void FUN_003f61d0(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5)



{

  char cVar1;

  char cVar2;

  u16 uVar3;

  u16 uVar4;

  u32 uVar5;

  int iVar6;

  char *pcVar7;

  char *pcVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  u32 uVar12;

  u8 auStack_30[16];

  char acStack_20 [16];

  short sStack_10;

  short sStack_e;

  short sStack_c;

  short sStack_a;

  char acStack_8 [8];

  

  pcVar8 = (char *)(&DAT_007cd928);

  pcVar7 = acStack_8;

  iVar6 = 5;

  do {

    cVar1 = *pcVar8;

    pcVar8 = pcVar8 + 1;

    iVar6 = iVar6 + -1;

    *pcVar7 = cVar1;

    pcVar7 = pcVar7 + 1;

  } while (0 < iVar6);

  sStack_10 = DAT_007cd930;

  sStack_e = DAT_007cd932;

  sStack_c = DAT_007cd934;

  sStack_a = DAT_007cd936;

  pcVar8 = (char *)(&DAT_006aef98);

  pcVar7 = acStack_20;

  iVar6 = 5;

  do {

    cVar1 = *pcVar8;

    cVar2 = pcVar8[1];

    pcVar8 = pcVar8 + 2;

    iVar6 = iVar6 + -1;

    *pcVar7 = cVar1;

    pcVar7[1] = cVar2;

    pcVar7 = pcVar7 + 2;

  } while (0 < iVar6);

  iVar6 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

  uVar5 = *(u32 *)(iVar6 + 8) & 0xf00;

  iVar9 = (int)uVar5 >> 8;

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x36,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x37,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x38,*(u8 *)(iVar6 + 8));

  cVar1 = acStack_8[iVar9];

  if (cVar1 == '\0') {

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x3d,0);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x3e,0);

  }

  else {

    uVar12 = param_3;

    if (acStack_20[iVar9 * 2] == -1) {

      uVar12 = (u32)((float)(int)param_3 * 0.5);

    }

    FUN_0040e3c0(0,param_1,param_2,uVar12 & 0xff,0x3f,0);

    uVar12 = param_3;

    if (acStack_20[iVar9 * 2 + 1] == -1) {

      uVar12 = (u32)((float)(int)param_3 * 0.5);

    }

    FUN_0040e3c0(0,param_1,param_2,uVar12 & 0xff,0x40,0);

  }

  iVar10 = (int)param_2;

  FUN_0040e3c0(0,param_1,iVar10 + 0x1b,param_3 & 0xff,0x37,0);

  cVar2 = acStack_20[iVar9 * 2];

  iVar11 = (int)param_1;

  uVar4 = (u16)(uVar5 >> 8);

  if (cVar2 == -1) {

    FUN_0040e3c0(0,param_1,iVar10 + 0x1b,param_3 & 0xff,0x42,0);

    FUN_0040e3c0(0,iVar11 + 0x11,iVar10 + 0x1b,param_3 & 0xff,0x42,0);

    FUN_0040e3c0(0,iVar11 + 0x22,iVar10 + 0x1b,param_3 & 0xff,0x42,0);

    FUN_0040e3c0(0,iVar11 + 0x33,iVar10 + 0x1b,param_3 & 0xff,0x42,0);

  }

  else {

    if (cVar1 == '\0') {

      uVar3 = datGetEquipmentIdx(1,uVar4);

      uVar3 = func_0016f9f0(1,uVar3);

    }

    else {

      uVar3 = datGetEquipmentIdx(1,uVar4);

      uVar3 = func_0016fbd0(1,uVar3);

    }

    sprintf((char *)auStack_30,0x7cd900,uVar3);

    FUN_0040eb50(0,iVar11 + sStack_10,iVar10 + 0x1b + (int)sStack_e,param_3 & 0xff,1,auStack_30,2);

    FUN_0040e3c0(0,param_1,iVar10 + 0x1b,param_3 & 0xff,0x41,0);

    sprintf((char *)auStack_30,0x7cd900,*(u16 *)(cVar2 * 2 + iVar6 + 0x14));

    FUN_0040eb50(0,iVar11 + sStack_c,iVar10 + 0x1b + (int)sStack_a,param_3 & 0xff,1,auStack_30,2);

  }

  FUN_0040e3c0(0,param_1,iVar10 + 0x36,param_3 & 0xff,0x37,0);

  cVar2 = acStack_20[iVar9 * 2 + 1];

  if (cVar2 == -1) {

    FUN_0040e3c0(0,param_1,iVar10 + 0x36,param_3 & 0xff,0x42,0);

    FUN_0040e3c0(0,iVar11 + 0x11,iVar10 + 0x36,param_3 & 0xff,0x42,0);

    FUN_0040e3c0(0,iVar11 + 0x22,iVar10 + 0x36,param_3 & 0xff,0x42,0);

    FUN_0040e3c0(0,iVar11 + 0x33,iVar10 + 0x36,param_3 & 0xff,0x42,0);

  }

  else {

    if (cVar1 == '\0') {

      uVar4 = datGetEquipmentIdx(1,uVar4);

      uVar4 = func_0016fae0(1,uVar4);

    }

    else {

      uVar4 = datGetEquipmentIdx(1,uVar4);

      uVar4 = func_0016fcc0(1,uVar4);

    }

    sprintf((char *)auStack_30,0x7cd900,uVar4);

    FUN_0040eb50(0,iVar11 + sStack_10,iVar10 + 0x36 + (int)sStack_e,param_3 & 0xff,1,auStack_30,2);

    FUN_0040e3c0(0,param_1,iVar10 + 0x36,param_3 & 0xff,0x41,0);

    sprintf((char *)auStack_30,0x7cd900,*(u16 *)(cVar2 * 2 + iVar6 + 0x14));

    FUN_0040eb50(0,iVar11 + sStack_c,iVar10 + 0x36 + (int)sStack_a,param_3 & 0xff,1,auStack_30,2);

  }

  return;

}

// FUN_003F67E0 NONMATCHING


void FUN_003f67e0(u64 param_1,u64 param_2,u32 param_3,int param_4,u64 param_5,

                 int param_6)



{

  char cVar1;

  char cVar2;

  u16 uVar3;

  u16 uVar4;

  int iVar5;

  char *pcVar6;

  char *pcVar7;

  int iVar8;

  long lVar9;

  int iVar10;

  int iVar11;

  long lVar12;

  u32 uVar13;

  u32 uVar14;

  u8 auStack_30[16];

  char acStack_20 [16];

  short sStack_10;

  short sStack_e;

  short sStack_c;

  short sStack_a;

  char acStack_8 [8];

  

  pcVar7 = (char *)(&DAT_007cd938);

  pcVar6 = acStack_8;

  iVar5 = 5;

  do {

    cVar1 = *pcVar7;

    pcVar7 = pcVar7 + 1;

    iVar5 = iVar5 + -1;

    *pcVar6 = cVar1;

    pcVar6 = pcVar6 + 1;

  } while (0 < iVar5);

  sStack_10 = DAT_007cd940;

  sStack_e = DAT_007cd942;

  sStack_c = DAT_007cd944;

  sStack_a = DAT_007cd946;

  pcVar7 = (char *)(&DAT_006aefa8);

  pcVar6 = acStack_20;

  iVar5 = 5;

  do {

    cVar1 = *pcVar7;

    cVar2 = pcVar7[1];

    pcVar7 = pcVar7 + 2;

    iVar5 = iVar5 + -1;

    *pcVar6 = cVar1;

    pcVar6[1] = cVar2;

    pcVar6 = pcVar6 + 2;

  } while (0 < iVar5);

  iVar5 = *(int *)(*(int *)(param_6 + 0x14) + 0x1c);

  uVar14 = *(u32 *)(iVar5 + 8) & 0xf00;

  iVar8 = (int)uVar14 >> 8;

  if (param_4 == 1) {

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,199,0);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,200,0);

  }

  else if (param_4 == 0) {

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xb1,0);

  }

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xc9,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xb5,0);

  iVar11 = (int)param_1;

  iVar10 = (int)param_2;

  FUN_0040e3c0(0,iVar11 + 0x70,iVar10 + 8,param_3 & 0xff,5,*(u8 *)(iVar5 + 8));

  cVar1 = acStack_8[iVar8];

  if (cVar1 == '\0') {

    lVar9 = (long)acStack_20[iVar8 * 2];

    uVar13 = param_3;

    if (lVar9 == -1) {

      uVar13 = (u32)((float)(int)param_3 * 0.5);

    }

    FUN_0040e3c0(0,param_1,param_2,uVar13 & 0xff,0xb3,0);

    lVar12 = (long)acStack_20[iVar8 * 2 + 1];

    uVar13 = param_3;

    if (lVar12 == -1) {

      uVar13 = (u32)((float)(int)param_3 * 0.5);

    }

    FUN_0040e3c0(0,param_1,param_2,uVar13 & 0xff,0xb4,0);

  }

  else {

    lVar9 = (long)acStack_20[iVar8 * 2];

    uVar13 = param_3;

    if (lVar9 == -1) {

      uVar13 = (u32)((float)(int)param_3 * 0.5);

    }

    FUN_0040e3c0(0,param_1,param_2,uVar13 & 0xff,0xca,0);

    lVar12 = (long)acStack_20[iVar8 * 2 + 1];

    uVar13 = param_3;

    if (lVar12 == -1) {

      uVar13 = (u32)((float)(int)param_3 * 0.5);

    }

    FUN_0040e3c0(0,param_1,param_2,uVar13 & 0xff,0xcb,0);

  }

  FUN_0040e3c0(0,param_1,iVar10 + 0x1c,param_3 & 0xff,0xb5,0);

  uVar4 = (u16)(uVar14 >> 8);

  if (lVar9 == -1) {

    uVar14 = (u32)((float)(int)param_3 * 0.5);

    FUN_0040e3c0(0,param_1,iVar10 + 0x1c,uVar14 & 0xff,0xce,0);

    FUN_0040e3c0(0,iVar11 + 0x11,iVar10 + 0x1c,uVar14 & 0xff,0xce,0);

    FUN_0040e3c0(0,iVar11 + 0x22,iVar10 + 0x1c,uVar14 & 0xff,0xce,0);

    FUN_0040e3c0(0,iVar11 + 0x33,iVar10 + 0x1c,uVar14 & 0xff,0xce,0);

  }

  else {

    if (cVar1 == '\0') {

      uVar3 = datGetEquipmentIdx(1,uVar4);

      uVar3 = func_0016f9f0(1,uVar3);

    }

    else {

      uVar3 = datGetEquipmentIdx(1,uVar4);

      uVar3 = func_0016fbd0(1,uVar3);

    }

    sprintf((char *)auStack_30,0x7cd900,uVar3);

    FUN_0040eb50(0,iVar11 + sStack_10,iVar10 + 0x1c + (int)sStack_e,param_3 & 0xff,1,auStack_30,2);

    FUN_0040e3c0(0,param_1,iVar10 + 0x1c,param_3 & 0xff,0xb6,0);

    sprintf((char *)auStack_30,0x7cd900,*(u16 *)((int)lVar9 * 2 + iVar5 + 0x14));

    FUN_0040eb50(0,iVar11 + sStack_c,iVar10 + 0x1c + (int)sStack_a,param_3 & 0xff,1,auStack_30,2);

  }

  FUN_0040e3c0(0,param_1,iVar10 + 0x38,param_3 & 0xff,0xb5,0);

  if (lVar12 == -1) {

    uVar14 = (u32)((float)(int)param_3 * 0.5);

    FUN_0040e3c0(0,param_1,iVar10 + 0x38,uVar14 & 0xff,0xce,0);

    FUN_0040e3c0(0,iVar11 + 0x11,iVar10 + 0x38,uVar14 & 0xff,0xce,0);

    FUN_0040e3c0(0,iVar11 + 0x22,iVar10 + 0x38,uVar14 & 0xff,0xce,0);

    FUN_0040e3c0(0,iVar11 + 0x33,iVar10 + 0x38,uVar14 & 0xff,0xce,0);

  }

  else {

    if (cVar1 == '\0') {

      uVar4 = datGetEquipmentIdx(1,uVar4);

      uVar4 = func_0016fae0(1,uVar4);

    }

    else {

      uVar4 = datGetEquipmentIdx(1,uVar4);

      uVar4 = func_0016fcc0(1,uVar4);

    }

    sprintf((char *)auStack_30,0x7cd900,uVar4);

    FUN_0040eb50(0,iVar11 + sStack_10,iVar10 + 0x38 + (int)sStack_e,param_3 & 0xff,1,auStack_30,2);

    FUN_0040e3c0(0,param_1,iVar10 + 0x38,param_3 & 0xff,0xb6,0);

    sprintf((char *)auStack_30,0x7cd900,*(u16 *)((int)lVar12 * 2 + iVar5 + 0x14));

    FUN_0040eb50(0,iVar11 + sStack_c,iVar10 + 0x38 + (int)sStack_a,param_3 & 0xff,1,auStack_30,2);

  }

  return;

}

// FUN_003F6F20 NONMATCHING


void FUN_003f6f20(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5)



{

  char cVar1;

  char cVar2;

  float fVar3;

  int iVar4;

  char *pcVar5;

  char *pcVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  u32 uVar10;

  float fVar11;

  u8 auStack_30[16];

  char acStack_20 [16];

  char acStack_10 [12];

  short sStack_4;

  short sStack_2;

  

  pcVar6 = (char *)(&DAT_007cd948);

  pcVar5 = acStack_10;

  iVar4 = 5;

  do {

    cVar1 = *pcVar6;

    pcVar6 = pcVar6 + 1;

    iVar4 = iVar4 + -1;

    *pcVar5 = cVar1;

    pcVar5 = pcVar5 + 1;

  } while (0 < iVar4);

  sStack_4 = DAT_007cd950;

  sStack_2 = DAT_007cd952;

  pcVar6 = (char *)(&DAT_006aefb8);

  pcVar5 = acStack_20;

  iVar4 = 5;

  do {

    cVar1 = *pcVar6;

    cVar2 = pcVar6[1];

    pcVar6 = pcVar6 + 2;

    iVar4 = iVar4 + -1;

    *pcVar5 = cVar1;

    pcVar5[1] = cVar2;

    pcVar5 = pcVar5 + 2;

  } while (0 < iVar4);

  iVar4 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

  iVar9 = (int)(*(u32 *)(iVar4 + 8) & 0xf00) >> 8;

  fVar11 = DAT_007caef0 * (float)(int)param_3;

  fVar3 = fVar11;

  if (2.1474836e+09 <= fVar11) {

    fVar3 = fVar11 - 2.1474836e+09;

  }

  FUN_0040e3c0(0,param_1,param_2,(int)fVar3 & 0xff,0x75,0);

  if (2.1474836e+09 <= fVar11) {

    fVar11 = fVar11 - 2.1474836e+09;

  }

  FUN_0040e3c0(0,param_1,param_2,(int)fVar11 & 0xff,0x76,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x77,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x78,0);

  iVar8 = (int)param_1;

  iVar7 = (int)param_2;

  FUN_0040e3c0(0,iVar8 + 0x89,iVar7 + 8,param_3 & 0xff,5,*(u8 *)(iVar4 + 8) + 0x16);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x79,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x7a,0);

  uVar10 = param_3;

  if (acStack_10[iVar9] != '\0') {

    uVar10 = (u32)((float)(int)param_3 * 0.5);

  }

  FUN_0040e3c0(0,param_1,param_2,uVar10 & 0xff,0x7b,0);

  FUN_0040e3c0(0,param_1,param_2,uVar10 & 0xff,0x7c,0);

  FUN_0040e3c0(0,param_1,iVar7 + 0x23,param_3 & 0xff,0x7d,0);

  iVar9 = iVar9 * 2;

  if (acStack_20[iVar9] == -1) {

    FUN_0040e3c0(0,param_1,iVar7 + 0x23,(int)((float)(int)param_3 * 0.5) & 0xff,0x7e,0);

  }

  else {

    sprintf((char *)auStack_30,0x7cd900,*(u16 *)(acStack_20[iVar9] * 2 + iVar4 + 0x14));

    FUN_0040eb50(0,iVar8 + sStack_4,iVar7 + 0x23 + (int)sStack_2,param_3 & 0xff,1,auStack_30,2);

  }

  FUN_0040e3c0(0,param_1,iVar7 + 0x3e,param_3 & 0xff,0x7d,0);

  if (acStack_20[iVar9 + 1] == -1) {

    FUN_0040e3c0(0,param_1,iVar7 + 0x3e,(int)((float)(int)param_3 * 0.5) & 0xff,0x7e,0);

  }

  else {

    sprintf((char *)auStack_30,0x7cd900,*(u16 *)(acStack_20[iVar9 + 1] * 2 + iVar4 + 0x14));

    FUN_0040eb50(0,iVar8 + sStack_4,iVar7 + 0x3e + (int)sStack_2,param_3 & 0xff,1,auStack_30,2);

  }

  return;

}

// FUN_003F7390 NONMATCHING


void FUN_003f7390(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5)



{

  short sVar1;

  int iVar2;

  int iVar3;

  u64 uVar4;

  u32 uVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  u32 uVar10;

  u8 auStack_20 [28];

  int iStack_4;

  

  iVar2 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xe2,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xdb,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xdc,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xdd,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xdf,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xe0,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0xe1,0);

  for (iVar7 = 0; iVar7 < 2; iVar7 = iVar7 + 1) {

    iVar6 = iVar2 + iVar7 * 4;

    if (*(short *)(iVar6 + 0x16) != 0) {

      iVar8 = (int)param_1;

      iVar9 = (int)param_2 + 0x10 + iVar7 * 0x1a;

      FUN_0040e3c0(0,iVar8 + 0x2f,iVar9 + 0x21,param_3 & 0xff,0,0x1b);

      iVar3 = iVar2 + iVar7 * 4;

      uVar4 = func_00171110(*(u16 *)(iVar3 + 0x14),2);

      FUN_003b2cb0(0,iVar8 + 0x4f,iVar9 + 0x23,param_3 | 0xffffff00,6,1,uVar4,0,0);

      FUN_0040e3c0(0,iVar8 + 0x1c,iVar9,param_3 & 0xff,0xe3,0);

      sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar6 + 0x16));

      FUN_0040eb50(0,iVar8 + 0x15a,iVar9 + 0x2c,param_3 & 0xff,1,auStack_20,1);

      FUN_0040e3c0(0,iVar8 + 0x1c,iVar9,param_3 & 0xff,0xe4,0);

      sVar1 = *(short *)(iVar3 + 0x14);

      iStack_4 = -1;

      uVar10 = 0;

      func_00170ed0(sVar1,&iStack_4);

      if (iStack_4 == 4) {

        uVar10 = func_00170760(1,sVar1);

        uVar10 = uVar10 & 0xffff;

      }

      else if ((((iStack_4 == 3) || (iStack_4 == 2)) || (iStack_4 == 1)) || (iStack_4 == 0)) {

        for (iVar6 = 0; iVar6 < 300; iVar6 = iVar6 + 1) {

          uVar5 = datGetEquipmentId(1,iVar6);

          if ((long)sVar1 == (uVar5 & 0xffff)) {

            uVar10 = uVar10 + 1;

          }

        }

      }

      sprintf((char *)auStack_20,0x7cd900,uVar10);

      FUN_0040eb50(0,iVar8 + 0x1c2,iVar9 + 0x2c,param_3 & 0xff,1,auStack_20,1);

    }

  }

  return;

}

// FUN_003F7730 NONMATCHING


void FUN_003f7730(u64 param_1,u64 param_2,u8 param_3,int param_4,int param_5)



{

  u16 uVar1;

  int iVar2;

  int iVar3;

  u16 *puVar4;

  u16 *puVar5;

  u16 auStack_30030 [98296];

  u16 auStack_30 [16];

  u8 auStack_10[16];

  

  puVar5 = (u16 *)(&DAT_006aefd0);

  puVar4 = auStack_30;

  iVar3 = 0xf;

  do {

    uVar1 = *puVar5;

    puVar5 = puVar5 + 1;

    iVar3 = iVar3 + -1;

    *puVar4 = uVar1;

    puVar4 = puVar4 + 1;

  } while (0 < iVar3);

  iVar3 = *(int *)(*(int *)(param_4 + 0x24) + 0x44);

  iVar2 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

  FUN_0040e3c0(0,param_1,param_2,param_3,auStack_30[*(short *)(iVar3 + 4) * 3],0);

  FUN_0040e3c0(0,param_1,param_2,param_3,auStack_30[*(short *)(iVar3 + 4) * 3 + 1],0);

  FUN_0040e3c0(0,param_1,param_2,param_3,auStack_30[*(short *)(iVar3 + 4) * 3 + 2],0);

  sprintf((char *)auStack_10,0x7cd954,*(u16 *)(iVar2 + 0xe));

  FUN_0040eb50(0,(int)param_1 + 0x8b,(int)param_2 + 0xc,param_3,1,auStack_10,1);

  return;

}

// FUN_003F7890 NONMATCHING


void FUN_003f7890(u64 param_1,u64 param_2,u8 param_3,int param_4,

                 u64 param_5,int param_6)



{

  u16 uVar1;

  u16 uVar2;

  int iVar3;

  u16 *puVar4;

  u16 *puVar5;

  u8 auStack_20[16];

  u16 auStack_10 [5];

  u16 uStack_6;

  

  puVar5 = (u16 *)(&DAT_006aeff0);

  puVar4 = auStack_10;

  iVar3 = 3;

  do {

    uVar1 = *puVar5;

    uVar2 = puVar5[1];

    puVar5 = puVar5 + 2;

    iVar3 = iVar3 + -1;

    *puVar4 = uVar1;

    puVar4[1] = uVar2;

    puVar4 = puVar4 + 2;

  } while (0 < iVar3);

  iVar3 = *(int *)(*(int *)(param_6 + 0x14) + 0x1c);

  if (param_4 == 1) {

    FUN_0040e3c0(0,param_1,param_2,param_3,auStack_10[3],0);

    FUN_0040e3c0(0,param_1,param_2,param_3,uStack_6,0);

    sprintf((char *)auStack_20,0x7cd954,*(u16 *)(iVar3 + 0xe));

    FUN_0040eb50(0,(int)param_1 + 0x223,(int)param_2 + 0xa2,param_3,3,auStack_20,1);

  }

  else if (param_4 == 0) {

    FUN_0040e3c0(0,param_1,param_2,param_3,auStack_10[0],0);

    FUN_0040e3c0(0,param_1,param_2,param_3,auStack_10[1],0);

    FUN_0040e3c0(0,param_1,param_2,param_3,auStack_10[2],0);

    sprintf((char *)auStack_20,0x7cd954,*(u16 *)(iVar3 + 0xe));

    FUN_0040eb50(0,(int)param_1 + 0x95,(int)param_2 + 0x99,param_3,3,auStack_20,1);

  }

  return;

}

// FUN_003F7A80 NONMATCHING


void FUN_003f7a80(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5)



{

  int iVar1;

  u32 uVar2;

  

  iVar1 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

  if ((*(short *)(*(int *)(*(int *)(param_4 + 0x24) + 0x44) + 6) == -1) &&

     ((*(u32 *)(iVar1 + 8) & 0x1000) != 0)) {

    FUN_003c7e20(0,param_1,param_2,param_3 | 0xffffffffffffff00,1,5,2,*(u16 *)(iVar1 + 6));

  }

  else if ((*(u32 *)(iVar1 + 8) & 0x1000) == 0) {

    FUN_003c7e20(0,param_1,param_2,param_3 | 0xffffffffffffff00,1,5,0,*(u16 *)(iVar1 + 4));

  }

  else {

    uVar2 = func_001715f0(*(u16 *)(iVar1 + 4));

    uVar2 = uVar2 & 0xff;

    if (uVar2 == 0) {

      FUN_003c7e20(0,param_1,param_2,param_3 | 0xffffffffffffff00,1,5,1,*(u16 *)(iVar1 + 4));

    }

    else if (uVar2 == 0xff) {

      FUN_003c7e20(0,param_1,param_2,param_3 | 0xffffffffffffff00,1,5,1,

                   (u32)CONCAT12(*(u8 *)(iVar1 + 0xd),*(u16 *)(iVar1 + 4)));

    }

    else {

      FUN_003c7e20(0,param_1,param_2,param_3 | 0xffffffffffffff00,1,5,1,

                   (u32)*(u16 *)(iVar1 + 4) | uVar2 << 0x10);

    }

  }

  return;

}

// FUN_003F7C60 NONMATCHING


void FUN_003f7c60(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5)



{

  int iVar1;

  

  iVar1 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

  if ((*(short *)(*(int *)(*(int *)(param_4 + 0x24) + 0x44) + 6) == -1) &&

     ((*(u32 *)(iVar1 + 8) & 0x1000) != 0)) {

    FUN_003c7e20(0,param_1,param_2,param_3 | 0xffffffffffffff00,1,5,2,*(u16 *)(iVar1 + 6));

  }

  else if ((*(u32 *)(iVar1 + 8) & 0x1000) == 0) {

    FUN_003c7e20(0,param_1,param_2,param_3 | 0xffffffffffffff00,1,5,0,*(u16 *)(iVar1 + 4));

  }

  else {

    FUN_003c7e20(0,param_1,param_2,param_3 | 0xffffffffffffff00,1,5,1,

                 (u32)CONCAT12(*(u8 *)(iVar1 + 0xd),*(u16 *)(iVar1 + 4)));

  }

  return;

}

// FUN_003F7D50 NONMATCHING


void FUN_003f7d50(u64 param_1,u64 param_2,u64 param_3,u64 param_4,

                 int param_5)



{

  short sVar1;

  int iVar2;

  int iVar3;

  u32 uVar4;

  int iVar5;

  int iVar6;

  

  iVar5 = *(int *)((int)param_4 + 0x24);

  iVar2 = *(int *)(iVar5 + 0x44);

  uVar4 = 0;

  iVar3 = 0;

  sVar1 = *(short *)(iVar5 + 4);

  iVar5 = *(int *)(*(int *)(param_5 + 0x14) + 0xc) -

          *(int *)(*(int *)(*(int *)(iVar5 + 0x2c) + 0x14) + 0xc);

  if (((long)iVar5 <= (long)sVar1) && (iVar3 = sVar1 - iVar5, 4 < iVar3)) {

    iVar3 = 5;

  }

  iVar6 = (int)param_1 - (0x1e - (iVar3 * 0x1e) / 5);

  iVar5 = (iVar3 * 0xff) / 5;

  if (3 < (long)sVar1) {

    iVar3 = sVar1 + -4;

    if (4 < iVar3) {

      iVar3 = 5;

    }

    uVar4 = (iVar3 * 0xff) / 5;

  }

  if (*(int *)((int)param_4 + 0xc) == param_5) {

    FUN_0040e3c0(0,param_1,param_2,uVar4 & 0xff,0x23,0);

    sVar1 = *(short *)(iVar2 + 6);

    if ((sVar1 == -2) || (sVar1 == -3)) {


    }

    else if (sVar1 == -5) {


    }

    else {


    }

  }

  else {

    sVar1 = *(short *)(iVar2 + 6);

    if ((sVar1 == -2) || (sVar1 == -3)) {


    }

    else if (sVar1 == -5) {


    }

    else {


    }

  }

  return;

}

// FUN_003F7FE0 NONMATCHING


void FUN_003f7fe0(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5

                 )



{

  short sVar1;

  int iVar2;

  

  iVar2 = *(int *)(*(int *)(param_4 + 0x24) + 0x44);

  if (*(int *)(param_4 + 0xc) == param_5) {

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x23,0);

    sVar1 = *(short *)(iVar2 + 6);

    if ((sVar1 == -2) || (sVar1 == -3)) {

      FUN_003f55b0(param_1,param_2,param_3 & 0xff,param_4,param_5,3);

    }

    else if (sVar1 == -5) {

      FUN_003f5830(param_1,param_2,param_3 & 0xff,param_4,param_5,3);

    }

    else {

      FUN_003f55b0(param_1,param_2,param_3 & 0xff,param_4,param_5,1);

    }

  }

  else {

    sVar1 = *(short *)(iVar2 + 6);

    if ((sVar1 == -2) || (sVar1 == -3)) {

      FUN_003f55b0(param_1,param_2,param_3 & 0xff,param_4,param_5,2);

    }

    else if (sVar1 == -5) {

      FUN_003f5830(param_1,param_2,param_3 & 0xff,param_4,param_5,2);

    }

    else {

      FUN_003f55b0(param_1,param_2,param_3 & 0xff,param_4,param_5,0);

    }

  }

  return;

}


// FUN_003F8180 NONMATCHING


void FUN_003f8180(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5

                 )



{

  u16 uVar1;

  u16 uVar2;

  short sVar3;

  u32 *puVar4;

  u32 *puVar5;

  u32 uVar6;

  int iVar7;

  u16 *puVar8;

  u16 *puVar9;

  u16 auStack_40 [16];

  u16 auStack_20 [16];

  

  puVar4 = *(u32 **)(*(int *)((int)param_4 + 0x24) + 0x44);

  if (*(int *)((int)param_4 + 0xc) == param_5) {

    puVar9 = (u16 *)(&DAT_006aeee0);

    puVar8 = auStack_20;

    iVar7 = 6;

    do {

      uVar1 = *puVar9;

      uVar2 = puVar9[1];

      puVar9 = puVar9 + 2;

      iVar7 = iVar7 + -1;

      *puVar8 = uVar1;

      puVar8[1] = uVar2;

      puVar8 = puVar8 + 2;

    } while (0 < iVar7);

    puVar5 = *(u32 **)(*(int *)(param_5 + 0x14) + 0x1c);

    if ((*puVar5 & 2) != 0) {

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[(short)puVar4[1] * 4],0);

      uVar6 = *puVar5;

      if ((uVar6 & 8) == 0) {

        if ((uVar6 & 4) != 0) {

          FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[(short)puVar4[1] * 4 + 1],0);

        }

      }

      else {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[(short)puVar4[1] * 4 + 2],0);

      }

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[(short)puVar4[1] * 4 + 3],0);

    }

    if ((*puVar4 & 1) == 0) {

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x23,0);

    }

    sVar3 = *(short *)((int)puVar4 + 6);

    if ((sVar3 == -2) || (sVar3 == -3)) {


    }

    else if (sVar3 == -5) {


    }

    else {


    }

  }

  else {

    puVar9 = (u16 *)(&DAT_006aeee0);

    puVar8 = auStack_40;

    iVar7 = 6;

    do {

      uVar1 = *puVar9;

      uVar2 = puVar9[1];

      puVar9 = puVar9 + 2;

      iVar7 = iVar7 + -1;

      *puVar8 = uVar1;

      puVar8[1] = uVar2;

      puVar8 = puVar8 + 2;

    } while (0 < iVar7);

    puVar5 = *(u32 **)(*(int *)(param_5 + 0x14) + 0x1c);

    if ((*puVar5 & 2) != 0) {

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_40[(short)puVar4[1] * 4],0);

      uVar6 = *puVar5;

      if ((uVar6 & 8) == 0) {

        if ((uVar6 & 4) != 0) {

          FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_40[(short)puVar4[1] * 4 + 1],0);

        }

      }

      else {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_40[(short)puVar4[1] * 4 + 2],0);

      }

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_40[(short)puVar4[1] * 4 + 3],0);

    }

    sVar3 = *(short *)((int)puVar4 + 6);

    if ((sVar3 == -2) || (sVar3 == -3)) {


    }

    else if (sVar3 == -5) {


    }

    else {


    }

  }

  return;

}

// FUN_003F85A0 NONMATCHING


void FUN_003f85a0(u64 param_1,u64 param_2,u64 param_3,u64 param_4,

                 u64 param_5)



{

  int iVar1;

  long lVar2;

  

  lVar2 = FUN_003c6e10(param_4);

  if (lVar2 == 1) {


  }

  else if (lVar2 == 0x14) {

    iVar1 = *(int *)(*(int *)((int)param_4 + 0x24) + 0x44);

    FUN_003f7fe0((int)param_1 + (int)*(short *)(iVar1 + 0x28),

                 (int)param_2 + (int)*(short *)(iVar1 + 0x2a),param_3,param_4,param_5);

  }

  else if (lVar2 == 0xc) {


  }

  return;

}

// FUN_003F86A0 NONMATCHING


void FUN_003f86a0(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5

                 )



{

  u16 uVar1;

  u16 uVar2;

  u32 *puVar3;

  u32 *puVar4;

  u32 uVar5;

  long lVar6;

  u16 *puVar7;

  u16 *puVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  u16 auStack_20 [16];

  

  iVar9 = (int)param_4;

  puVar3 = *(u32 **)(*(int *)(iVar9 + 0x24) + 0x44);

  lVar6 = FUN_003c6e10(param_4);

  if (lVar6 == 1) {

    puVar8 = (u16 *)(&DAT_006aeee0);

    puVar7 = auStack_20;

    iVar10 = 6;

    do {

      uVar1 = *puVar8;

      uVar2 = puVar8[1];

      puVar8 = puVar8 + 2;

      iVar10 = iVar10 + -1;

      *puVar7 = uVar1;

      puVar7[1] = uVar2;

      puVar7 = puVar7 + 2;

    } while (0 < iVar10);

    iVar10 = *(int *)(*(int *)(iVar9 + 0x24) + 0x44);

    puVar4 = *(u32 **)(*(int *)(param_5 + 0x14) + 0x1c);

    if ((*puVar4 & 2) != 0) {

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[*(short *)(iVar10 + 4) * 4],0);

      uVar5 = *puVar4;

      if ((uVar5 & 8) == 0) {

        if ((uVar5 & 4) != 0) {

          FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[*(short *)(iVar10 + 4) * 4 + 1],0

                      );

        }

      }

      else {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[*(short *)(iVar10 + 4) * 4 + 2],0);

      }

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[*(short *)(iVar10 + 4) * 4 + 3],0);

    }

    if (*(int *)(iVar9 + 0xc) == param_5) {

      if ((*puVar3 & 1) == 0) {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x25,0);

      }


    }

    else {


    }

  }

  else if (lVar6 == 0x14) {

    iVar11 = (int)param_1 + (int)(short)puVar3[10];

    iVar10 = (int)param_2 + (int)*(short *)((int)puVar3 + 0x2a);

    if (*(int *)(iVar9 + 0xc) == param_5) {

      FUN_0040e3c0(0,iVar11,iVar10,param_3 & 0xff,0x25,0);


    }

    else {


    }

  }

  else if (lVar6 == 0xc) {

    if (*(int *)(iVar9 + 0xc) == param_5) {

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x25,0);


    }

    else {


    }

  }

  return;

}

// FUN_003F8A00 NONMATCHING


void FUN_003f8a00(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5

                 )



{

  short sVar1;

  u16 uVar2;

  u16 uVar3;

  u32 *puVar4;

  u32 *puVar5;

  long lVar6;

  int iVar7;

  int iVar8;

  u16 *puVar9;

  u16 *puVar10;

  int iVar11;

  int iVar12;

  u32 uVar13;

  u16 auStack_20 [16];

  

  uVar13 = 0;

  iVar12 = 0;

  iVar11 = (int)param_4;

  puVar4 = *(u32 **)(*(int *)(iVar11 + 0x24) + 0x44);

  lVar6 = FUN_003c6e10(param_4);

  if (lVar6 == 1) {

    puVar10 = (u16 *)(&DAT_006aeee0);

    puVar9 = auStack_20;

    iVar12 = 6;

    do {

      uVar2 = *puVar10;

      uVar3 = puVar10[1];

      puVar10 = puVar10 + 2;

      iVar12 = iVar12 + -1;

      *puVar9 = uVar2;

      puVar9[1] = uVar3;

      puVar9 = puVar9 + 2;

    } while (0 < iVar12);

    iVar12 = *(int *)(*(int *)(iVar11 + 0x24) + 0x44);

    puVar5 = *(u32 **)(*(int *)(param_5 + 0x14) + 0x1c);

    if ((*puVar5 & 2) != 0) {

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[*(short *)(iVar12 + 4) * 4],0);

      uVar13 = *puVar5;

      if ((uVar13 & 8) == 0) {

        if ((uVar13 & 4) != 0) {

          FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[*(short *)(iVar12 + 4) * 4 + 1],0

                      );

        }

      }

      else {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[*(short *)(iVar12 + 4) * 4 + 2],0);

      }

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[*(short *)(iVar12 + 4) * 4 + 3],0);

    }

    if (*(int *)(iVar11 + 0xc) == param_5) {

      if ((*puVar4 & 1) == 0) {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x23,0);

      }


    }

    else {


    }

  }

  else if (lVar6 == 0x14) {

    iVar8 = (int)param_1 + (int)(short)puVar4[10];

    iVar12 = (int)param_2 + (int)*(short *)((int)puVar4 + 0x2a);

    if (*(int *)(iVar11 + 0xc) == param_5) {

      FUN_0040e3c0(0,iVar8,iVar12,param_3 & 0xff,0x23,0);


    }

    else {


    }

  }

  else if (lVar6 == 0xc) {

    sVar1 = *(short *)(*(int *)(iVar11 + 0x24) + 4);

    iVar8 = *(int *)(*(int *)(param_5 + 0x14) + 0xc) -

            *(int *)(*(int *)(*(int *)(*(int *)(iVar11 + 0x24) + 0x2c) + 0x14) + 0xc);

    if (((long)iVar8 <= (long)sVar1) && (iVar12 = sVar1 - iVar8, 4 < iVar12)) {

      iVar12 = 5;

    }

    iVar8 = (int)param_1 - (0x1e - (iVar12 * 0x1e) / 5);

    iVar12 = (iVar12 * 0xff) / 5;

    if (3 < (long)sVar1) {

      iVar7 = sVar1 + -4;

      if (4 < iVar7) {

        iVar7 = 5;

      }

      uVar13 = (iVar7 * 0xff) / 5;

    }

    if (*(int *)(iVar11 + 0xc) == param_5) {

      FUN_0040e3c0(0,param_1,param_2,uVar13 & 0xff,0x23,0);


    }

    else {


    }

  }

  return;

}

// FUN_003F8E10 NONMATCHING


void FUN_003f8e10(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5

                 )



{

  short sVar1;

  u16 uVar2;

  u16 uVar3;

  u32 *puVar4;

  u32 *puVar5;

  long lVar6;

  int iVar7;

  int iVar8;

  u16 *puVar9;

  u16 *puVar10;

  int iVar11;

  int iVar12;

  u32 uVar13;

  u16 auStack_20 [16];

  

  uVar13 = 0;

  iVar12 = 0;

  iVar11 = (int)param_4;

  puVar4 = *(u32 **)(*(int *)(iVar11 + 0x24) + 0x44);

  lVar6 = FUN_003c6e10(param_4);

  if (lVar6 == 1) {

    puVar10 = (u16 *)(&DAT_006aeee0);

    puVar9 = auStack_20;

    iVar12 = 6;

    do {

      uVar2 = *puVar10;

      uVar3 = puVar10[1];

      puVar10 = puVar10 + 2;

      iVar12 = iVar12 + -1;

      *puVar9 = uVar2;

      puVar9[1] = uVar3;

      puVar9 = puVar9 + 2;

    } while (0 < iVar12);

    iVar12 = *(int *)(*(int *)(iVar11 + 0x24) + 0x44);

    puVar5 = *(u32 **)(*(int *)(param_5 + 0x14) + 0x1c);

    if ((*puVar5 & 2) != 0) {

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[*(short *)(iVar12 + 4) * 4],0);

      uVar13 = *puVar5;

      if ((uVar13 & 8) == 0) {

        if ((uVar13 & 4) != 0) {

          FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[*(short *)(iVar12 + 4) * 4 + 1],0

                      );

        }

      }

      else {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[*(short *)(iVar12 + 4) * 4 + 2],0);

      }

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_20[*(short *)(iVar12 + 4) * 4 + 3],0);

    }

    if (*(int *)(iVar11 + 0xc) == param_5) {

      if ((*puVar4 & 1) == 0) {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x27,0);

      }


    }

    else {


    }

  }

  else if (lVar6 == 0x14) {

    iVar8 = (int)param_1 + (int)(short)puVar4[10];

    iVar12 = (int)param_2 + (int)*(short *)((int)puVar4 + 0x2a);

    if (*(int *)(iVar11 + 0xc) == param_5) {

      FUN_0040e3c0(0,iVar8,iVar12,param_3 & 0xff,0x27,0);


    }

    else {


    }

  }

  else if (lVar6 == 0xc) {

    sVar1 = *(short *)(*(int *)(iVar11 + 0x24) + 4);

    iVar8 = *(int *)(*(int *)(param_5 + 0x14) + 0xc) -

            *(int *)(*(int *)(*(int *)(*(int *)(iVar11 + 0x24) + 0x2c) + 0x14) + 0xc);

    if (((long)iVar8 <= (long)sVar1) && (iVar12 = sVar1 - iVar8, 4 < iVar12)) {

      iVar12 = 5;

    }

    iVar8 = (int)param_1 - (0x1e - (iVar12 * 0x1e) / 5);

    iVar12 = (iVar12 * 0xff) / 5;

    if (3 < (long)sVar1) {

      iVar7 = sVar1 + -4;

      if (4 < iVar7) {

        iVar7 = 5;

      }

      uVar13 = (iVar7 * 0xff) / 5;

    }

    if (*(int *)(iVar11 + 0xc) == param_5) {

      FUN_0040e3c0(0,param_1,param_2,uVar13 & 0xff,0x27,0);


    }

    else {


    }

  }

  return;

}

// FUN_003F9220 NONMATCHING


void FUN_003f9220(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5

                 )



{

  short sVar1;

  u32 *puVar2;

  long lVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  u32 uVar8;

  

  uVar8 = 0;

  iVar7 = 0;

  iVar6 = (int)param_4;

  puVar2 = *(u32 **)(*(int *)(iVar6 + 0x24) + 0x44);

  lVar3 = FUN_003c6e10(param_4);

  if (lVar3 == 1) {

    if (*(int *)(iVar6 + 0xc) == param_5) {

      if ((*puVar2 & 1) == 0) {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x17,0);

      }


    }

    else {


    }

  }

  else if (lVar3 == 0x14) {

    iVar5 = (int)param_1 + (int)(short)puVar2[10];

    iVar7 = (int)param_2 + (int)*(short *)((int)puVar2 + 0x2a);

    if (*(int *)(iVar6 + 0xc) == param_5) {

      FUN_0040e3c0(0,iVar5,iVar7,param_3 & 0xff,0x17,0);


    }

    else {


    }

  }

  else if (lVar3 == 0xc) {

    sVar1 = *(short *)(*(int *)(iVar6 + 0x24) + 4);

    iVar5 = *(int *)(*(int *)(param_5 + 0x14) + 0xc) -

            *(int *)(*(int *)(*(int *)(*(int *)(iVar6 + 0x24) + 0x2c) + 0x14) + 0xc);

    if (((long)iVar5 <= (long)sVar1) && (iVar7 = sVar1 - iVar5, 4 < iVar7)) {

      iVar7 = 5;

    }

    iVar5 = (int)param_1 - (0x1e - (iVar7 * 0x1e) / 5);

    iVar7 = (iVar7 * 0xff) / 5;

    if (3 < (long)sVar1) {

      iVar4 = sVar1 + -4;

      if (4 < iVar4) {

        iVar4 = 5;

      }

      uVar8 = (iVar4 * 0xff) / 5;

    }

    if (*(int *)(iVar6 + 0xc) == param_5) {

      FUN_0040e3c0(0,param_1,param_2,uVar8 & 0xff,0x17,0);


    }

    else {


    }

  }

  return;

}

// FUN_003F9510 NONMATCHING


void FUN_003f9510(u64 param_1,u64 param_2,u32 param_3,u64 param_4,int param_5

                 )



{

  short sVar1;

  u32 *puVar2;

  long lVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  code *pcVar7;

  u32 uVar8;

  int iVar9;

  int iVar10;

  u8 uStack_20;

  u32 auStack_10 [4];

  

  uStack_20 = 0;

  iVar9 = 0;

  uVar8 = 0;

  auStack_10[0] = DAT_006af000;

  auStack_10[1] = DAT_006af004;

  auStack_10[2] = DAT_006af008;

  iVar6 = (int)param_4;

  puVar2 = *(u32 **)(*(int *)(iVar6 + 0x24) + 0x44);

  sVar1 = *(short *)((int)puVar2 + 6);

  if (sVar1 == -5) {

    uVar8 = 2;

    iVar10 = 2;


  }

  else if (sVar1 == -4) {

    uVar8 = 6;

    iVar10 = 1;


  }

  else if ((sVar1 == -3) || (sVar1 == -2)) {

    uVar8 = 2;

    iVar10 = 1;


  }

  else {

    iVar10 = 0;


  }

  lVar3 = FUN_003c6e10(param_4);

  if (lVar3 == 1) {

    if (*(int *)(iVar6 + 0xc) == param_5) {

      if ((*puVar2 & 1) == 0) {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,auStack_10[iVar10],0);

      }

      (*pcVar7)(param_1,param_2,param_3,param_4,param_5,uVar8 | 1);

    }

    else {

      (*pcVar7)(param_1,param_2,param_3,param_4,param_5,uVar8);

    }

  }

  else if (lVar3 == 0x14) {

    iVar5 = (int)param_1 + (int)(short)puVar2[10];

    iVar9 = (int)param_2 + (int)*(short *)((int)puVar2 + 0x2a);

    if (*(int *)(iVar6 + 0xc) == param_5) {

      FUN_0040e3c0(0,iVar5,iVar9,param_3 & 0xff,auStack_10[iVar10],0);

      (*pcVar7)(iVar5,iVar9,param_3,param_4,param_5,uVar8 | 1);

    }

    else {

      (*pcVar7)(iVar5,iVar9,param_3,param_4,param_5,uVar8);

    }

  }

  else if (lVar3 == 0xc) {

    sVar1 = *(short *)(*(int *)(iVar6 + 0x24) + 4);

    iVar5 = *(int *)(*(int *)(param_5 + 0x14) + 0xc) -

            *(int *)(*(int *)(*(int *)(*(int *)(iVar6 + 0x24) + 0x2c) + 0x14) + 0xc);

    if (((long)iVar5 <= (long)sVar1) && (iVar9 = sVar1 - iVar5, 4 < iVar9)) {

      iVar9 = 5;

    }

    iVar5 = (int)param_1 - (0x1e - (iVar9 * 0x1e) / 5);

    iVar9 = (iVar9 * 0xff) / 5;

    if (3 < (long)sVar1) {

      iVar4 = sVar1 + -4;

      if (4 < iVar4) {

        iVar4 = 5;

      }

      uStack_20 = (u8)((iVar4 * 0xff) / 5);

    }

    if (*(int *)(iVar6 + 0xc) == param_5) {

      FUN_0040e3c0(0,param_1,param_2,uStack_20,auStack_10[iVar10],0);

      (*pcVar7)(iVar5,param_2,iVar9,param_4,param_5,uVar8 | 1);

    }

    else {

      (*pcVar7)(iVar5,param_2,iVar9,param_4,param_5,uVar8);

    }

  }

  return;

}

// FUN_003F98F0 NONMATCHING


u32 FUN_003f98f0(u16 param_1)



{

  u32 uVar1;

  u16 *puVar2;

  

  puVar2 = (u16 *)(&DAT_006acca0);

  uVar1 = 0;

  do {

    if (0xf < uVar1) {

      return 1;

    }

    if ((*puVar2 == 0) && (puVar2[1] != 0)) {

      K_Assert((const char *)(u32)0x6aede8,0xe12);

    }

    if (puVar2[1] == 0) {

      if (param_1 == *puVar2) {

        return 0;

      }

    }

    else if ((*puVar2 <= param_1) && (param_1 <= puVar2[1])) {

      return 0;

    }

    puVar2 = puVar2 + 2;

    uVar1 = uVar1 + 1;

  } while( 1 );

}

// FUN_003F99D0 NONMATCHING


u64 FUN_003f99d0(u64 param_1,u32 param_2)



{

  u32 *puVar1;

  u32 uVar2;

  short sVar3;

  int iVar4;

  u32 uVar5;

  long lVar6;

  u32 uVar7;

  u8 auStack_20 [4];

  u32 uStack_1c;

  

  for (uVar7 = 0; (long)uVar7 < 300; uVar7 = (u32)((int)uVar7 + 1)) {

    uVar5 = func_0016f720(1,uVar7);

    if ((((param_2 & uVar5) != 0) && (lVar6 = FUN_003f1dc0(1,(long)auStack_20,uVar7), lVar6 != 0)) &&

       (lVar6 = FUN_003f98f0(uVar7 & 0xffff), lVar6 != 0)) {

      iVar4 = FUN_003c5a40(param_1,*(u16 *)((int)param_1 + 0x10) + 1,0x20,0);

      puVar1 = *(u32 **)(*(int *)(iVar4 + 0x14) + 0x1c);

      memcpy(puVar1 + 1,auStack_20,0x1c);

      if (((uStack_1c & 0x1000) != 0) &&

         (sVar3 = datGetEquipmentIdx(1,(u16)(uStack_1c >> 8) & 0xf), uVar7 == (long)sVar3)) {

        uVar2 = *puVar1;

        *puVar1 = uVar2 | 0x10;

        *puVar1 = uVar2 | 0x50;

      }

      uVar2 = puVar1[4];

      puVar1[4] = (int)uVar2 >> 2;

      if ((int)uVar2 >> 2 < 1) {

        puVar1[4] = 1;

      }

    }

  }

  return 0;

}

// FUN_003F9B20 NONMATCHING


u64 FUN_003f9b20(u64 param_1,u64 param_2)



{

  short sVar1;

  int iVar2;

  short sVar3;

  u32 uVar4;

  long lVar5;

  int iVar6;

  int iStack_4;

  

  iVar2 = *(int *)(*(int *)((int)param_2 + 0x14) + 0x1c);

  if ((*(u32 *)(iVar2 + 8) & 0x4000) == 0) {

    lVar5 = datGetEquipmentId(1,*(u16 *)(iVar2 + 6));

    if (lVar5 == 0) {

      *(u16 *)(iVar2 + 0xe) = 0;

    }

    else {

      *(u16 *)(iVar2 + 0xe) = 1;

    }

  }

  else {

    sVar1 = *(short *)(iVar2 + 4);

    iStack_4 = -1;

    sVar3 = 0;

    func_00170ed0(sVar1,&iStack_4);

    if (iStack_4 == 4) {

      sVar3 = func_00170760(1,sVar1);

    }

    else if ((((iStack_4 == 3) || (iStack_4 == 2)) || (iStack_4 == 1)) || (iStack_4 == 0)) {

      sVar3 = 0;

      for (iVar6 = 0; iVar6 < 300; iVar6 = iVar6 + 1) {

        uVar4 = datGetEquipmentId(1,iVar6);

        if ((long)sVar1 == (uVar4 & 0xffff)) {

          sVar3 = sVar3 + 1;

        }

      }

    }

    *(short *)(iVar2 + 0xe) = sVar3;

  }

  if (*(short *)(iVar2 + 0xe) == 0) {

    FUN_003c5fa0(param_1,param_2);

  }

  return 0;

}

// FUN_003F9E30 NONMATCHING


u64 FUN_003f9e30(int param_1)



{

  u32 uVar1;

  u32 uVar2;

  u8 *puVar3;

  u8 *puVar4;

  int iVar5;

  int iVar6;

  u64 uVar7;

  long lVar8;

  int iVar9;

  u32 *puVar10;

  u32 *puVar11;

  u8 **ppuVar12;

  u32 uVar13;

  u8 auStack_c0 [32];

  u32 auStack_a0 [8];

  u32 auStack_80 [8];

  u32 auStack_60 [8];

  u32 auStack_40 [16];

  

  puVar11 = &DAT_006af010;

  puVar10 = auStack_40;

  iVar9 = 8;

  do {

    uVar1 = *puVar11;

    uVar2 = puVar11[1];

    puVar11 = puVar11 + 2;

    iVar9 = iVar9 + -1;

    *puVar10 = uVar1;

    puVar10[1] = uVar2;

    puVar10 = puVar10 + 2;

  } while (0 < iVar9);

  uVar7 = FUN_003c58f0(0,0x58,5,0x1a);

  iVar5 = (int)uVar7;

  iVar9 = *(int *)(*(int *)(iVar5 + 0x24) + 0x44);

  *(short *)(iVar9 + 4) = (short)param_1;

  *(u16 *)(iVar9 + 6) = 0xffff;


  for (uVar13 = 4000; ((int)uVar13 < 0x1080 && ((int)(uVar13 - 4000) < 300)); uVar13 = uVar13 + 1) {


    if ((lVar8 != 0) && (lVar8 = FUN_003f98f0(uVar13 & 0xffff), lVar8 != 0)) {

      iVar9 = FUN_003c5a40(uVar7,*(u16 *)(iVar5 + 0x10) + 1,0x20,0);

      iVar9 = *(int *)(*(int *)(iVar9 + 0x14) + 0x1c);

      memcpy(iVar9 + 4,auStack_c0,0x1c);

      iVar6 = *(int *)(iVar9 + 0x10) >> 2;

      *(int *)(iVar9 + 0x10) = iVar6;

      if (iVar6 < 1) {

        *(u32 *)(iVar9 + 0x10) = 1;

      }

    }

  }

  FUN_003c7000(uVar7,0x3f9cb0,0);

  FUN_003c6ee0(uVar7);

  ppuVar12 = (u8 **)&PTR_FUN_006af050;

  puVar10 = auStack_60;

  iVar9 = 4;

  do {

    puVar3 = *ppuVar12;

    puVar4 = ppuVar12[1];

    ppuVar12 = ppuVar12 + 2;

    iVar9 = iVar9 + -1;

    *puVar10 = (u32)(puVar3);

    puVar10[1] = (u32)(puVar4);

    puVar10 = puVar10 + 2;

  } while (0 < iVar9);

  ppuVar12 = (u8 **)&PTR_FUN_006af070;

  puVar10 = auStack_80;

  iVar9 = 4;

  do {

    puVar3 = *ppuVar12;

    puVar4 = ppuVar12[1];

    ppuVar12 = ppuVar12 + 2;

    iVar9 = iVar9 + -1;

    *puVar10 = (u32)(puVar3);

    puVar10[1] = (u32)(puVar4);

    puVar10 = puVar10 + 2;

  } while (0 < iVar9);

  ppuVar12 = (u8 **)&PTR_FUN_006af090;

  puVar10 = auStack_a0;

  iVar9 = 4;

  do {

    puVar3 = *ppuVar12;

    puVar4 = ppuVar12[1];

    ppuVar12 = ppuVar12 + 2;

    iVar9 = iVar9 + -1;

    *puVar10 = (u32)(puVar3);

    puVar10[1] = (u32)(puVar4);

    puVar10 = puVar10 + 2;

  } while (0 < iVar9);

  FUN_003c5e80(uVar7,auStack_60[param_1]);

  FUN_003c5e20(uVar7,auStack_80[param_1]);

  FUN_003c5ee0(uVar7,auStack_a0[param_1]);

  FUN_003c6d40(uVar7,auStack_40[param_1 * 2],auStack_40[param_1 * 2 + 1]);

  *(u16 *)(*(int *)(iVar5 + 0x24) + 6) = 0x14;

  *(u16 *)(*(int *)(iVar5 + 0x24) + 8) = 10;

  return uVar7;

}

// FUN_003FA0D0


u32 FUN_003fa0d0(u64 param_1)
{
  u32 uVar1;
  u32 lVar2;

  
  uVar1 = FUN_003fa1e0_u32();

  if ((lVar2 = FUN_003c6ce0(param_1), lVar2 != 0) ||
      (lVar2 = FUN_003c6d10(param_1), lVar2 != 0)) {

    func_0010a4e0(0,0,0,0);

  }

  lVar2 = FUN_003c6ca0(param_1);

  if ((lVar2 != 0) || (lVar2 = FUN_003c6cc0(param_1), lVar2 != 0)) {

    func_0010a4e0(0,0,0,5);

  }

  return uVar1;

}

// FUN_003FA190


u64 FUN_003fa190(int param_1)



{

  u32 *puVar1;

  

  puVar1 = *(u32 **)(*(int *)(param_1 + 0x24) + 0x44);

  *puVar1 = *puVar1 | 1;

  return 0;

}

// FUN_003FA1B0


u64 FUN_003fa1b0(int param_1)



{

  u32 *puVar1;

  

  puVar1 = *(u32 **)(*(int *)(param_1 + 0x24) + 0x44);

  *puVar1 = *puVar1 & 0xfffffffe;

  return 0;

}

// FUN_003FA1E0


u8 FUN_003fa1e0(void)
{
  return FUN_003c6270() == 3;
}

// FUN_003FA210 NONMATCHING


void FUN_003fa210(int param_1)



{

  short sVar1;

  int iVar2;

  long lVar3;

  int iVar4;

  

  iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x44);

  lVar3 = FUN_003c6e10();

  if (lVar3 != 1) {

    if (lVar3 == 0x14) {

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 0xb) {

        *(short *)(iVar2 + 0x28) = (short)(int)((float)(sVar1 * -0xa0) / 10.0);

      }

      else {

        *(u16 *)(iVar2 + 0x28) = 0xff60;

      }

      if (sVar1 < 6) {

        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * -0xff) / 5.0 + 255.0);

      }

      else {

        *(u16 *)(iVar2 + 0x34) = 0;

      }

    }

    else if (lVar3 == 0xc) {

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      *(u16 *)(iVar2 + 0x28) = 0;

      *(u16 *)(iVar2 + 0x2a) = 0;

      if (sVar1 < 6) {

        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * 0xff) / 5.0);

      }

      else {

        *(u16 *)(iVar2 + 0x34) = 0xff;

      }

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 6) {

        *(u16 *)(iVar2 + 0x38) = 0xff38;

        *(u16 *)(iVar2 + 0x44) = 0;

      }

      else {

        iVar4 = sVar1 + -6;

        if (iVar4 < 5) {

          *(short *)(iVar2 + 0x38) = (short)(int)((float)(iVar4 * 0x8c) / 4.0 + -140.0);

          *(u16 *)(iVar2 + 0x3a) = 0;

          *(u16 *)(iVar2 + 0x44) = 0xff;

        }

      }

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 8) {

        *(u16 *)(iVar2 + 0x54) = 0;

      }

      else {

        iVar4 = sVar1 + -8;

        if (iVar4 < 6) {

          *(u16 *)(iVar2 + 0x54) = 0xff;

          *(float *)(iVar2 + 0x50) = fGpffff8234 + (fGpffff8230 * (float)iVar4) / 5.0;

        }

      }

      if ((0xc < sVar1) && (iVar4 = sVar1 + -0xd, iVar4 < 5)) {

        *(short *)(iVar2 + 0x4a) = (short)(int)((float)(iVar4 * -3) / 4.0 + 3.0);

        *(float *)(iVar2 + 0x50) = fGpffff823c + (fGpffff8238 * (float)iVar4) / 4.0;

      }

    }

  }

  return;

}

// FUN_003FA520 NONMATCHING


void FUN_003fa520(int param_1)



{

  short sVar1;

  int iVar2;

  long lVar3;

  int iVar4;

  

  iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x44);

  lVar3 = FUN_003c6e10();

  if (lVar3 != 1) {

    if (lVar3 == 0x14) {

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 0xb) {

        *(short *)(iVar2 + 0x28) = (short)(int)((float)(sVar1 * -0xa0) / 10.0);

      }

      else {

        *(u16 *)(iVar2 + 0x28) = 0xff60;

      }

      if (sVar1 < 6) {

        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * -0xff) / 5.0 + 255.0);

      }

      else {

        *(u16 *)(iVar2 + 0x34) = 0;

      }

    }

    else if (lVar3 == 0xc) {

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      *(u16 *)(iVar2 + 0x28) = 0;

      *(u16 *)(iVar2 + 0x2a) = 0;

      if (sVar1 < 6) {

        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * 0xff) / 5.0);

      }

      else {

        *(u16 *)(iVar2 + 0x34) = 0xff;

      }

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 5) {

        *(short *)(iVar2 + 0x38) = (short)(int)((float)(sVar1 * 0xa0) / 4.0 + -160.0);

        *(u16 *)(iVar2 + 0x3a) = 0;

        *(u16 *)(iVar2 + 0x44) = 0xff;

      }

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 8) {

        *(u16 *)(iVar2 + 0x54) = 0;

      }

      else {

        iVar4 = sVar1 + -8;

        if (iVar4 < 6) {

          *(u16 *)(iVar2 + 0x54) = 0xff;

          *(float *)(iVar2 + 0x50) = fGpffff8234 + (fGpffff8230 * (float)iVar4) / 5.0;

        }

      }

      if ((0xc < sVar1) && (iVar4 = sVar1 + -0xd, iVar4 < 5)) {

        *(short *)(iVar2 + 0x4a) = (short)(int)((float)(iVar4 * -3) / 4.0 + 3.0);

        *(float *)(iVar2 + 0x50) = fGpffff823c + (fGpffff8238 * (float)iVar4) / 4.0;

      }

    }

  }

  return;

}

// FUN_003FA800 NONMATCHING


void FUN_003fa800(int param_1)



{

  short sVar1;

  int iVar2;

  long lVar3;

  int iVar4;

  

  iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x44);

  lVar3 = FUN_003c6e10();

  if (lVar3 != 1) {

    if (lVar3 == 0x14) {

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 0xb) {

        *(short *)(iVar2 + 0x28) = (short)(int)((float)(sVar1 * -0xa0) / 10.0);

      }

      else {

        *(u16 *)(iVar2 + 0x28) = 0xff60;

      }

      if (sVar1 < 6) {

        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * -0xff) / 5.0 + 255.0);

      }

      else {

        *(u16 *)(iVar2 + 0x34) = 0;

      }

    }

    else if (lVar3 == 0xc) {

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      *(u16 *)(iVar2 + 0x28) = 0;

      *(u16 *)(iVar2 + 0x2a) = 0;

      if (sVar1 < 6) {

        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * 0xff) / 5.0);

      }

      else {

        *(u16 *)(iVar2 + 0x34) = 0xff;

      }

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 5) {

        *(short *)(iVar2 + 0x38) = (short)(int)((float)(sVar1 * 0xa0) / 4.0 + -160.0);

        *(u16 *)(iVar2 + 0x3a) = 0;

        *(u16 *)(iVar2 + 0x44) = 0xff;

      }

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 8) {

        *(u16 *)(iVar2 + 0x54) = 0;

      }

      else {

        iVar4 = sVar1 + -8;

        if (iVar4 < 6) {

          *(u16 *)(iVar2 + 0x54) = 0xff;

          *(float *)(iVar2 + 0x50) = fGpffff8234 + (fGpffff8230 * (float)iVar4) / 5.0;

        }

      }

      if ((0xc < sVar1) && (iVar4 = sVar1 + -0xd, iVar4 < 5)) {

        *(short *)(iVar2 + 0x4a) = (short)(int)((float)(iVar4 * -3) / 4.0 + 3.0);

        *(float *)(iVar2 + 0x50) = fGpffff823c + (fGpffff8238 * (float)iVar4) / 4.0;

      }

    }

  }

  return;

}

// FUN_003FAAE0 NONMATCHING


void FUN_003faae0(int param_1)



{

  short sVar1;

  int iVar2;

  long lVar3;

  int iVar4;

  

  iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x44);

  lVar3 = FUN_003c6e10();

  if (lVar3 != 1) {

    if (lVar3 == 0x14) {

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 0xb) {

        *(short *)(iVar2 + 0x28) = (short)(int)((float)(sVar1 * -0xa0) / 10.0);

      }

      else {

        *(u16 *)(iVar2 + 0x28) = 0xff60;

      }

      if (sVar1 < 6) {

        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * -0xff) / 5.0 + 255.0);

      }

      else {

        *(u16 *)(iVar2 + 0x34) = 0;

      }

    }

    else if (lVar3 == 0xc) {

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      *(u16 *)(iVar2 + 0x28) = 0;

      *(u16 *)(iVar2 + 0x2a) = 0;

      if (sVar1 < 6) {

        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * 0xff) / 5.0);

      }

      else {

        *(u16 *)(iVar2 + 0x34) = 0xff;

      }

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 5) {

        *(short *)(iVar2 + 0x38) = (short)(int)((float)(sVar1 * 0xa0) / 4.0 + -160.0);

        *(u16 *)(iVar2 + 0x3a) = 0;

        *(u16 *)(iVar2 + 0x44) = 0xff;

      }

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 8) {

        *(u16 *)(iVar2 + 0x54) = 0;

      }

      else {

        iVar4 = sVar1 + -8;

        if (iVar4 < 6) {

          *(u16 *)(iVar2 + 0x54) = 0xff;

          *(float *)(iVar2 + 0x50) = fGpffff8234 + (fGpffff8230 * (float)iVar4) / 5.0;

        }

      }

      if ((0xc < sVar1) && (iVar4 = sVar1 + -0xd, iVar4 < 5)) {

        *(short *)(iVar2 + 0x4a) = (short)(int)((float)(iVar4 * -3) / 4.0 + 3.0);

        *(float *)(iVar2 + 0x50) = fGpffff823c + (fGpffff8238 * (float)iVar4) / 4.0;

      }

    }

  }

  return;

}

// FUN_003FADC0 NONMATCHING


void FUN_003fadc0(int param_1)



{

  short sVar1;

  int iVar2;

  long lVar3;

  int iVar4;

  

  iVar2 = *(int *)(*(int *)(param_1 + 0x24) + 0x44);

  lVar3 = FUN_003c6e10();

  if (lVar3 != 1) {

    if (lVar3 == 0x14) {

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 0xb) {

        *(short *)(iVar2 + 0x28) = (short)(int)((float)(sVar1 * -0xa0) / 10.0);

      }

      else {

        *(u16 *)(iVar2 + 0x28) = 0xff60;

      }

      if (sVar1 < 6) {

        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * -0xff) / 5.0 + 255.0);

      }

      else {

        *(u16 *)(iVar2 + 0x34) = 0;

      }

    }

    else if (lVar3 == 0xc) {

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      *(u16 *)(iVar2 + 0x28) = 0;

      *(u16 *)(iVar2 + 0x2a) = 0;

      if (sVar1 < 6) {

        *(short *)(iVar2 + 0x34) = (short)(int)((float)(sVar1 * 0xff) / 5.0);

      }

      else {

        *(u16 *)(iVar2 + 0x34) = 0xff;

      }

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 6) {

        *(u16 *)(iVar2 + 0x38) = 0xff38;

        *(u16 *)(iVar2 + 0x44) = 0;

      }

      else {

        iVar4 = sVar1 + -6;

        if (iVar4 < 5) {

          *(short *)(iVar2 + 0x38) = (short)(int)((float)(iVar4 * 0x8c) / 4.0 + -140.0);

          *(u16 *)(iVar2 + 0x3a) = 0;

          *(u16 *)(iVar2 + 0x44) = 0xff;

        }

      }

      sVar1 = *(short *)(*(int *)(param_1 + 0x24) + 4);

      if (sVar1 < 1) {

        *(u16 *)(iVar2 + 0x54) = 0;

      }

      else {

        iVar4 = sVar1 + -1;

        if (iVar4 < 6) {

          *(u16 *)(iVar2 + 0x54) = 0xff;

          *(float *)(iVar2 + 0x50) = fGpffff8234 + (fGpffff8230 * (float)iVar4) / 5.0;

        }

      }

      if ((5 < sVar1) && (iVar4 = sVar1 + -5, iVar4 < 4)) {

        *(short *)(iVar2 + 0x4a) = (short)(int)((float)(iVar4 * -3) / 3.0 + 3.0);

        *(float *)(iVar2 + 0x50) = fGpffff823c + (fGpffff8238 * (float)iVar4) / 3.0;

      }

    }

  }

  return;

}

// FUN_003FB0C0 NONMATCHING


void FUN_003fb0c0(long param_1,long param_2)



{

  u32 uVar1;

  u16 uVar2;

  int iVar3;

  int iVar4;

  u32 *puVar5;

  

  if (param_1 == 0) {

    K_Assert((const char *)(u32)0x6aede8,0xffa);

  }

  puVar5 = (u32 *)param_1;

  *puVar5 = *puVar5 | 1;

  puVar5[2] = 1;

  *(u16 *)(puVar5 + 1) = 1;

  *(u16 *)((int)puVar5 + 0x2a) = 0;

  *(u16 *)(puVar5 + 0xb) = 0;

  *(u16 *)((int)puVar5 + 0x2e) = 0;

  if (param_2 == 0) {

    *puVar5 = *puVar5 | 2;

  }

  else {

    *puVar5 = *puVar5 | 4;

  }

  uVar1 = *puVar5;

  if ((uVar1 & 2) == 0) {

    if ((uVar1 & 4) != 0) {

      if ((long)(int)puVar5[2] < (long)*(short *)((int)puVar5 + 0x16)) {

        *puVar5 = uVar1 & 0xfffffff7;

      }

      else {

        *puVar5 = uVar1 | 8;

      }

    }

  }

  else {

    iVar3 = 99;

    if (puVar5[6] != 0) {

      iVar3 = datGetMoney();

      iVar3 = iVar3 / (int)puVar5[6];

    }

    if (99 < iVar3 + *(short *)((int)puVar5 + 0x16)) {

      iVar3 = 99 - *(short *)((int)puVar5 + 0x16);

    }

    uVar2 = FUN_003e6dc0();

    iVar4 = FUN_0017d250(uVar2,(short)puVar5[3]);

    if ((iVar4 != -1) && (iVar4 < iVar3)) {

      iVar3 = iVar4;

    }

    if ((int)puVar5[2] < iVar3) {

      *puVar5 = *puVar5 & 0xfffffff7;

    }

    else {

      *puVar5 = *puVar5 | 8;

    }

  }

  if (puVar5[2] == 1) {

    *puVar5 = *puVar5 | 0x10;

  }

  else {

    *puVar5 = *puVar5 & 0xffffffef;

  }

  return;

}

// FUN_003FB2F0 NONMATCHING


int FUN_003fb2f0(u32 *param_1)



{

  u16 uVar1;

  int iVar2;

  u32 uVar3;

  u32 uVar4;

  int iVar5;

  u32 uVar6;

  

  iVar5 = 0;

  datGetMoney();

  if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {

    if (((DAT_007e0952 & 0x4000) == 0) && ((DAT_007e095a & 0x4000) == 0)) {

      if (((DAT_007e0952 & 0x2000) == 0) && ((DAT_007e095a & 0x2000) == 0)) {

        if (((DAT_007e0952 & 0x8000) != 0) || ((DAT_007e095a & 0x8000) != 0)) {

          iVar5 = -10;

        }

      }

      else {

        iVar5 = 10;

      }

    }

    else {

      iVar5 = -1;

    }

  }

  else {

    iVar5 = 1;

  }

  if (iVar5 != 0) {

    uVar6 = param_1[2] + iVar5;

    if ((int)uVar6 < 100) {

      if ((int)uVar6 < 1) {

        uVar6 = 1;

      }

    }

    else {

      uVar6 = 99;

    }

    uVar4 = 99;

    if (param_1[6] != 0) {

      iVar2 = datGetMoney();

      uVar4 = iVar2 / (int)param_1[6];

    }

    if (99 < (int)(uVar4 + (int)*(short *)((int)param_1 + 0x16))) {

      uVar4 = 99 - (int)*(short *)((int)param_1 + 0x16);

    }

    uVar1 = FUN_003e6dc0();

    uVar3 = FUN_0017d250(uVar1,(short)param_1[3]);

    if ((uVar3 != 0xffffffff) && ((int)uVar3 < (int)uVar4)) {

      uVar4 = uVar3;

    }

    if ((int)uVar6 < (int)uVar4) {

      *param_1 = *param_1 & 0xfffffff7;

    }

    else {

      *param_1 = *param_1 | 8;

      uVar6 = uVar4;

    }

    if (uVar6 == 1) {

      *param_1 = *param_1 | 0x10;

    }

    else {

      *param_1 = *param_1 & 0xffffffef;

    }

    if (param_1[2] == uVar6) {

      iVar5 = 0;

    }

    else {

      param_1[2] = uVar6;

      if (iVar5 < 1) {

        if (iVar5 < 0) {

          iVar5 = 2;

        }

      }

      else {

        iVar5 = 1;

      }

    }

  }

  return iVar5;

}

// FUN_003FB530 NONMATCHING


int FUN_003fb530(u32 *param_1)



{

  int iVar1;

  long lVar2;

  long lVar3;

  long lVar4;

  

  iVar1 = 0;

  lVar4 = (long)*(short *)((int)param_1 + 0x16);

  if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {

    if (((DAT_007e0952 & 0x4000) == 0) && ((DAT_007e095a & 0x4000) == 0)) {

      if (((DAT_007e0952 & 0x2000) == 0) && ((DAT_007e095a & 0x2000) == 0)) {

        if (((DAT_007e0952 & 0x8000) != 0) || ((DAT_007e095a & 0x8000) != 0)) {

          iVar1 = -10;

        }

      }

      else {

        iVar1 = 10;

      }

    }

    else {

      iVar1 = -1;

    }

  }

  else {

    iVar1 = 1;

  }

  if (iVar1 != 0) {

    lVar2 = (long)(int)(param_1[2] + iVar1);

    lVar3 = lVar4;

    if ((lVar2 <= lVar4) && (lVar3 = lVar2, lVar2 < 1)) {

      lVar3 = 1;

    }

    if (lVar3 < lVar4) {

      *param_1 = *param_1 & 0xfffffff7;

    }

    else {

      *param_1 = *param_1 | 8;

    }

    if (lVar3 == 1) {

      *param_1 = *param_1 | 0x10;

    }

    else {

      *param_1 = *param_1 & 0xffffffef;

    }

    if ((int)param_1[2] == lVar3) {

      iVar1 = 0;

    }

    else {

      param_1[2] = (u32)lVar3;

      if (iVar1 < 1) {

        if (iVar1 < 0) {

          iVar1 = 2;

        }

      }

      else {

        iVar1 = 1;

      }

    }

  }

  return iVar1;

}

// FUN_003FB6B0 NONMATCHING


int FUN_003fb6b0(u64 param_1)



{

  u32 uVar1;

  short sVar2;

  int iVar3;

  long lVar4;

  u32 *puVar5;

  long lVar6;

  float fVar7;

  u8 auStack_20 [32];

  

  iVar3 = 0;

  lVar6 = 0;

  puVar5 = (u32 *)param_1;

  uVar1 = *puVar5;

  if ((uVar1 & 1) != 0) {

    switch((short)puVar5[1]) {

    case 1:

      *(u16 *)(puVar5 + 1) = 3;

      break;

    case 2:

      *puVar5 = uVar1 & 0xfffffffe;

      if ((uVar1 & 0x400) == 0) {

        if ((uVar1 & 0x800) != 0) {

          iVar3 = 2;

        }

      }

      else {

        iVar3 = 1;

      }

      uVar1 = *puVar5;

      *puVar5 = uVar1 & 0xfffffbff;

      *puVar5 = uVar1 & 0xfffff3ff;

      FUN_003eed10(0);

      return iVar3;

    case 3:

      *(u16 *)(puVar5 + 1) = 4;

      *(u16 *)((int)puVar5 + 6) = 0;

      *(u16 *)((int)puVar5 + 0x2a) = 0xff;

      *(u16 *)(puVar5 + 0xc) = 0xfe0c;

      *(u16 *)((int)puVar5 + 0x32) = 0;

      if ((*puVar5 & 2) == 0) {

        if ((*puVar5 & 4) != 0) {

          FUN_003ef970(8);

        }

      }

      else {

        FUN_003ef970(6);

      }

    case 4:

      sVar2 = *(short *)((int)puVar5 + 6) + 1;

      *(short *)((int)puVar5 + 6) = sVar2;

      fVar7 = (float)cosf((fGpffff8110 * (float)(int)sVar2) / 5.0);

      *(short *)(puVar5 + 0xc) = (short)(int)(fVar7 * -100.0);

      if (4 < *(short *)((int)puVar5 + 6)) {

        *(u16 *)(puVar5 + 1) = 7;

        *(u16 *)((int)puVar5 + 0x2a) = 0xff;

        *(u16 *)(puVar5 + 0xc) = 0;

        *(u16 *)((int)puVar5 + 0x32) = 0;

      }

      break;

    case 5:

      *(u16 *)(puVar5 + 1) = 6;

      *(u16 *)((int)puVar5 + 6) = 0;

      if ((*puVar5 & 2) == 0) {

        if ((*puVar5 & 4) != 0) {

          FUN_003ef970(9);

        }

      }

      else {

        FUN_003ef970(7);

      }

    case 6:

      sVar2 = *(short *)((int)puVar5 + 6) + 1;

      *(short *)((int)puVar5 + 6) = sVar2;

      *(short *)((int)puVar5 + 0x2a) = (short)(int)(255.0 - (float)(sVar2 * 0xff) / 5.0);

      if (4 < *(short *)((int)puVar5 + 6)) {

        *(u16 *)(puVar5 + 1) = 2;

      }

      break;

    case 7:

      iVar3 = 1;

      break;

    case 8:

      lVar4 = FUN_003c7850();

      if (lVar4 == 0) {

        FUN_003c7700();

        lVar4 = FUN_003c7610();

        if (lVar4 == 0) {

          *puVar5 = *puVar5 | 0x400;

        }

        else {

          *puVar5 = *puVar5 | 0x800;

        }

        *(u16 *)(puVar5 + 1) = 5;

      }

    }

    if (iVar3 != 0) {

      if (((DAT_007e094e & 0x40) == 0) && ((DAT_007e0958 & 0x40) == 0)) {

        if (((DAT_007e094e & 0x20) == 0) && ((DAT_007e0958 & 0x20) == 0)) {

          if ((*puVar5 & 2) == 0) {

            if ((*puVar5 & 4) != 0) {


            }

          }

          else {


          }

          FUN_003eed10(puVar5[6] * puVar5[2]);

          if (lVar6 != 0) {

            func_0010a4e0(0,0,0,0);

          }

        }

        else {

          func_0010a4e0(0,0,0,2);

          *(u16 *)(puVar5 + 1) = 5;

          *puVar5 = *puVar5 | 0x800;

        }

      }

      else {

        func_0010a4e0(0,0,0,1);

        *(u16 *)(puVar5 + 1) = 8;

        sprintf((char *)auStack_20,&gp0xffffac10,puVar5[6] * puVar5[2]);

        FUN_003c7bc0(0,auStack_20);

        if ((*puVar5 & 2) == 0) {

          if ((*puVar5 & 4) != 0) {

            FUN_003c7430(6);

          }

        }

        else {

          FUN_003c7430(4);

        }

        FUN_003c74e0(0);

        FUN_003c7560(0);

      }

    }

    if ((lVar6 == 1) || ((*puVar5 & 8) != 0)) {

      *(u16 *)(puVar5 + 0xb) = 0x20;

    }

    if ((lVar6 == 2) || ((*puVar5 & 0x10) != 0)) {

      *(u16 *)((int)puVar5 + 0x2e) = 0x20;

    }

    iVar3 = (short)puVar5[0xb] + 0x20;

    if (iVar3 < 0xff) {

      *(short *)(puVar5 + 0xb) = (short)iVar3;

    }

    else {

      *(u16 *)(puVar5 + 0xb) = 0xff;

    }

    iVar3 = *(short *)((int)puVar5 + 0x2e) + 0x20;

    if (iVar3 < 0xff) {

      *(short *)((int)puVar5 + 0x2e) = (short)iVar3;

    }

    else {

      *(u16 *)((int)puVar5 + 0x2e) = 0xff;

    }

  }

  return 0;

}

// FUN_003FBC00 NONMATCHING


u64 FUN_003fbc00(u32 *param_1)



{

  short sVar1;

  short sVar2;

  u16 uVar3;

  u32 uVar4;

  u32 uVar5;

  int iVar6;

  u64 uVar7;

  int iVar8;

  u32 *puVar9;

  u32 *puVar10;

  u32 auStack_a0 [36];

  u8 auStack_10[16];

  

  iVar6 = FUN_003e6dc0();

  puVar10 = &DAT_006af0b0;

  puVar9 = auStack_a0;

  iVar8 = 0x12;

  do {

    uVar4 = *puVar10;

    uVar5 = puVar10[1];

    puVar10 = puVar10 + 2;

    iVar8 = iVar8 + -1;

    *puVar9 = uVar4;

    puVar9[1] = uVar5;

    puVar9 = puVar9 + 2;

  } while (0 < iVar8);

  if ((*param_1 & 1) != 0) {

    sVar1 = (short)param_1[0xc];

    sVar2 = *(short *)((int)param_1 + 0x32);

    uVar3 = *(u16 *)((int)param_1 + 0x2a);

    FUN_0040e3c0(0,sVar1,sVar2,uVar3 & 0xff,auStack_a0[iVar6 * 4],0);

    FUN_0040e3c0(0,sVar1 + 0x2a,sVar2 + 0x69,uVar3 & 0xff,0,(u32)(u8)param_1[4] * 2 + 1);

    uVar7 = func_00171110((short)param_1[3],(char)param_1[5]);

    FUN_003b2cb0(0,sVar1 + 0x4a,sVar2 + 0x73,uVar3 | 0xff00,6,1,uVar7,0x10,0);

    sprintf((char *)auStack_10,&gp0xffffac10,param_1[6]);

    iVar8 = (int)sVar2;

    FUN_0040eb50(0,sVar1 + 0x196,iVar8 + 0x75,uVar3 & 0xff,1,auStack_10,9);

    FUN_0040e3c0(0,sVar1,sVar2,uVar3 & 0xff,auStack_a0[iVar6 * 4 + 1],0);

    sprintf((char *)auStack_10,&gp0xffffac10,param_1[2]);

    FUN_0040eb50(0,sVar1 + 0x1c0,iVar8 + 0x75,uVar3 & 0xff,1,auStack_10,2);

    FUN_0040e3c0(0,sVar1,iVar8 - ((short)param_1[0xb] * 3) / 0xff,

                 ((int)(short)param_1[0xb] * (int)(short)uVar3) / 0xff & 0xff,

                 auStack_a0[iVar6 * 4 + 2],0);

    FUN_0040e3c0(0,sVar1,iVar8 + (*(short *)((int)param_1 + 0x2e) * 3) / 0xff,

                 ((int)*(short *)((int)param_1 + 0x2e) * (int)(short)uVar3) / 0xff & 0xff,

                 auStack_a0[iVar6 * 4 + 3],0);

  }

  return 0;

}

// FUN_003FBE70


void FUN_003fbe70(u8 *param_1,u8 *param_2)
{
  s16 sVar1;

  memset_typed(param_1,0,0x98);
  sVar1 = datGetEquipmentIdx_s16(1,(s16)((s32)(*(u32 *)(param_2 + 4) & 0xf00) >> 8));
  FUN_003f1dc0_u32(1,param_1 + 0x50,(s32)sVar1);
  memcpy_typed(param_1 + 0x6c,param_2,0x1c);
  *(u32 *)(param_1 + 4) = *(u32 *)(param_1 + 4) | 1;
  *(u16 *)param_1 = 1;
  return;
}

// FUN_003FBF10


void FUN_003fbf10(u16 *param_1)



{

  *param_1 = 3;

  return;

}

// FUN_003FBF20 NONMATCHING


u64 FUN_003fbf20(short *param_1)



{

  short sVar1;

  int iVar2;

  

  sVar1 = *param_1;

  if (sVar1 != 5) {

    if (sVar1 != 4) {

      if (sVar1 != 3) {

        if (sVar1 != 2) {

          if (sVar1 != 1) {

            return 0;

          }

          *param_1 = 2;

          param_1[4] = 0;

          param_1[5] = 0;

        }

        iVar2 = *(int *)(param_1 + 4);

        *(int *)(param_1 + 4) = iVar2 + 1;

        param_1[0x4a] = (short)(int)((float)((iVar2 + 1) * 0xff) / 10.0);

        if (*(int *)(param_1 + 4) < 10) {

          return 0;

        }

        *param_1 = 5;

        param_1[4] = 0;

        param_1[5] = 0;

        return 0;

      }

      *param_1 = 4;

      param_1[4] = 0;

      param_1[5] = 0;

    }

    iVar2 = *(int *)(param_1 + 4);

    *(int *)(param_1 + 4) = iVar2 + 1;

    param_1[0x4a] = (short)(int)((float)((iVar2 + 1) * -0xff) / 10.0 + 255.0);

    if (9 < *(int *)(param_1 + 4)) {

      *(u32 *)(param_1 + 2) = *(u32 *)(param_1 + 2) & 0xfffffffe;

      param_1[4] = 0;

      param_1[5] = 0;

    }

  }

  return 0;

}

// FUN_003FC060 NONMATCHING


u64 FUN_003fc060(int param_1)



{

  u16 uVar1;

  u64 uVar2;

  u16 *puVar3;

  int iVar4;

  int iVar5;

  u8 auStack_8 [8];

  

  if ((*(u32 *)(param_1 + 4) & 1) != 0) {

    uVar1 = *(u16 *)(param_1 + 0x94);


    FUN_0040e3c0(0,0x18,0x4b,uVar1 & 0xff,0x4a,0);

    FUN_0040e3c0(0,0x18,0x4b,uVar1 & 0xff,0x4c,0);

    FUN_0040e3c0(0,0x18,0x4b,uVar1 & 0xff,0x43,0);

    FUN_0040e3c0(0,0x37,0xbb,uVar1 & 0xff,0x49,0);

    FUN_0040e3c0(0,0x37,0xbb,uVar1 & 0xff,0x4b,0);

    FUN_0040e3c0(0,0x37,0xbb,uVar1 & 0xff,0x44,0);

    puVar3 = (u16 *)(param_1 + 0x50);

    iVar4 = 200;

    FUN_0040e3c0(0,200,0x5f,uVar1 & 0xff,0,(u32)*(u8 *)(param_1 + 0x54) << 1);

    uVar2 = func_00171110(*puVar3,*(u8 *)(param_1 + 0x58));

    FUN_003b2cb0(0,0xe8,0x61,uVar1 | 0xff00,5,1,uVar2,0,0);

    for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {

      if (puVar3[iVar5 + 8] == 0) {

        FUN_0040e3c0(0,iVar4,0x5f,uVar1 & 0xff,0x47,0);

        FUN_0040e3c0(0,iVar4,0x5f,uVar1 & 0xff,0x48,0);

        FUN_0040e3c0(0,iVar4,0x5f,uVar1 & 0xff,0x4d,iVar5);

        FUN_0040e3c0(0,iVar4,0x5f,uVar1 & 0xff,0x4f,0);

      }

      else {

        FUN_0040e3c0(0,iVar4,0x5f,uVar1 & 0xff,0x45,0);

        FUN_0040e3c0(0,iVar4,0x5f,uVar1 & 0xff,0x46,0);

        FUN_0040e3c0(0,iVar4,0x5f,uVar1 & 0xff,0x4e,iVar5);

        sprintf((char *)auStack_8,0x7cd900,puVar3[iVar5 + 8]);

        FUN_0040eb50(0,iVar4 + 0x4b,0x9b,uVar1 & 0xff,2,auStack_8,1);

      }

      iVar4 = iVar4 + 0x52;

    }

    puVar3 = (u16 *)(param_1 + 0x6c);

    iVar4 = 200;

    FUN_0040e3c0(0,200,0xbb,uVar1 & 0xff,0,(u32)*(u8 *)(param_1 + 0x70) << 1);

    uVar2 = func_00171110(*puVar3,*(u8 *)(param_1 + 0x74));

    FUN_003b2cb0(0,0xe8,0xbd,uVar1 | 0xff00,5,1,uVar2,0,0);

    for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {

      if (puVar3[iVar5 + 8] == 0) {

        FUN_0040e3c0(0,iVar4,0xbb,uVar1 & 0xff,0x47,0);

        FUN_0040e3c0(0,iVar4,0xbb,uVar1 & 0xff,0x48,0);

        FUN_0040e3c0(0,iVar4,0xbb,uVar1 & 0xff,0x4d,iVar5);

        FUN_0040e3c0(0,iVar4,0xbb,uVar1 & 0xff,0x4f,0);

      }

      else {

        FUN_0040e3c0(0,iVar4,0xbb,uVar1 & 0xff,0x45,0);

        FUN_0040e3c0(0,iVar4,0xbb,uVar1 & 0xff,0x46,0);

        FUN_0040e3c0(0,iVar4,0xbb,uVar1 & 0xff,0x4e,iVar5);

        sprintf((char *)auStack_8,0x7cd900,puVar3[iVar5 + 8]);

        FUN_0040eb50(0,iVar4 + 0x4b,0xf7,uVar1 & 0xff,2,auStack_8,1);

      }

      iVar4 = iVar4 + 0x52;

    }

  }

  return 0;

}

// FUN_003FC540 NONMATCHING


u64 FUN_003fc540(int param_1)



{

  u16 uVar1;

  u64 uVar2;

  u16 *puVar3;

  int iVar4;

  int iVar5;

  u8 auStack_8 [8];

  

  if ((*(u32 *)(param_1 + 4) & 1) != 0) {

    uVar1 = *(u16 *)(param_1 + 0x94);

    FUN_0040e3c0(0,0x2b,0x1c,uVar1 & 0xff,0x42,0);

    FUN_0040e3c0(0,0x2b,0x1c,uVar1 & 0xff,0x44,0);

    FUN_0040e3c0(0,0x2b,0x1c,uVar1 & 0xff,0x3a,0);

    FUN_0040e3c0(0,0x2b,0xb0,uVar1 & 0xff,0x41,0);

    FUN_0040e3c0(0,0x2b,0xb0,uVar1 & 0xff,0x43,0);

    FUN_0040e3c0(0,0x2b,0xb0,uVar1 & 0xff,0x3b,0);

    puVar3 = (u16 *)(param_1 + 0x50);

    iVar4 = 0x4e;

    FUN_0040e3c0(0,0x4e,0x44,uVar1 & 0xff,0,(u32)*(u8 *)(param_1 + 0x54) << 1);

    uVar2 = func_00171110(*puVar3,*(u8 *)(param_1 + 0x58));

    FUN_003b2cb0(0,0x6e,0x46,uVar1 | 0xff00,5,1,uVar2,0,0);

    for (iVar5 = 0; iVar5 < 5; iVar5 = iVar5 + 1) {

      if (puVar3[iVar5 + 8] == 0) {

        FUN_0040e3c0(0,iVar4,0x44,uVar1 & 0xff,0x40,0);

        FUN_0040e3c0(0,iVar4,0x44,uVar1 & 0xff,0x45,iVar5);

        FUN_0040e3c0(0,iVar4,0x44,uVar1 & 0xff,0x47,0);

      }

      else {

        FUN_0040e3c0(0,iVar4,0x44,uVar1 & 0xff,0x3e,0);

        FUN_0040e3c0(0,iVar4,0x44,uVar1 & 0xff,0x46,iVar5);

        sprintf((char *)auStack_8,0x7cd900,puVar3[iVar5 + 8]);

        FUN_0040eb50(0,iVar4 + 0x1a,0x8c,uVar1 & 0xff,2,auStack_8,1);

      }

      iVar4 = iVar4 + 0x42;

    }

    puVar3 = (u16 *)(param_1 + 0x6c);

    iVar4 = 0x4e;

    FUN_0040e3c0(0,0x4e,0xd8,uVar1 & 0xff,0,(u32)*(u8 *)(param_1 + 0x70) << 1);

    uVar2 = func_00171110(*puVar3,*(u8 *)(param_1 + 0x74));

    FUN_003b2cb0(0,0x6e,0xda,uVar1 | 0xff00,5,1,uVar2,0,0);

    for (iVar5 = 0; iVar5 < 5; iVar5 = iVar5 + 1) {

      if (puVar3[iVar5 + 8] == 0) {

        FUN_0040e3c0(0,iVar4,0xd8,uVar1 & 0xff,0x40,0);

        FUN_0040e3c0(0,iVar4,0xd8,uVar1 & 0xff,0x45,iVar5);

        FUN_0040e3c0(0,iVar4,0xd8,uVar1 & 0xff,0x47,0);

      }

      else {

        FUN_0040e3c0(0,iVar4,0xd8,uVar1 & 0xff,0x3e,0);

        FUN_0040e3c0(0,iVar4,0xd8,uVar1 & 0xff,0x46,iVar5);

        sprintf((char *)auStack_8,0x7cd900,puVar3[iVar5 + 8]);

        FUN_0040eb50(0,iVar4 + 0x1a,0x120,uVar1 & 0xff,2,auStack_8,1);

      }

      iVar4 = iVar4 + 0x42;

    }

  }

  return 0;

}

// FUN_003FC980


u32 FUN_003fc980(int param_1)

{

  u32 uVar1;

  u32 uVar2;

  

  uVar1 = datGetScenarioMode();

  if (uVar1 == 0) {
    uVar2 = FUN_003fc060_u32(param_1);

  }

  else {

    uVar1 = datGetScenarioMode();

    if (uVar1 == 1) {
      uVar2 = FUN_003fc540_u32(param_1);

    }

    else {

      uVar2 = 0;

    }

  }

  return uVar2;

}

// FUN_003FCA00 NONMATCHING
void FUN_003fca00(u64 param_1,u64 param_2,u32 param_3)
{
  u32 uVar1;

  uVar1 = param_3;
  FUN_0040e3c0_u32(0.0f,0,0,param_3 & 0xff,0x52,0);
  FUN_0040e3c0_f32(0.0f,0,0,uVar1 & 0xff,0x53,0);
  FUN_0040e3c0_f32(0.0f,0,0,uVar1 & 0xff,0x54,0);
  FUN_0040e3c0_f32(0.0f,0,0,uVar1 & 0xff,0x50,0);
  FUN_0040e3c0_f32(0.0f,0,0,uVar1 & 0xff,0x51,0);
  return;
}

// FUN_003FCAD0 NONMATCHING


void FUN_003fcad0(u64 param_1,u64 param_2,u32 param_3,int param_4)



{

  int iVar1;

  

  iVar1 = *(int *)(*(int *)(*(int *)(param_4 + 0xc) + 0x14) + 0x1c);

  if ((*(short *)(*(int *)(*(int *)(param_4 + 0x24) + 0x44) + 6) == -1) &&

     ((*(u32 *)(iVar1 + 8) & 0x1000) != 0)) {

    FUN_003c7e20(0,0x125,0xe3,param_3 | 0xffffffffffffff00,1,5,2,*(u16 *)(iVar1 + 6));

  }

  else if ((*(u32 *)(iVar1 + 8) & 0x1000) == 0) {

    FUN_003c7e20(0,0x125,0xe3,param_3 | 0xffffffffffffff00,1,5,0,*(u16 *)(iVar1 + 4));

  }

  else {

    FUN_003c7e20(0,0x125,0xe3,param_3 | 0xffffffffffffff00,1,5,1,

                 (u32)CONCAT12(*(u8 *)(iVar1 + 0xd),*(u16 *)(iVar1 + 4)));

  }

  return;

}

// FUN_003FCBE0 NONMATCHING


void FUN_003fcbe0(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5)



{

  u8 bVar1;

  int iVar2;

  

  if (param_3 != 0) {

    iVar2 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

    bVar1 = param_5 == *(int *)(param_4 + 0xc);

    if (bVar1) {

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x5f,0);

    }

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x59,(u32)bVar1 * -2);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x5a,(u32)bVar1 * -2);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,((int)(*(u32 *)(iVar2 + 8) & 0xf00) >> 8) + 0x55,

                 bVar1);

    iVar2 = (int)(*(u32 *)(iVar2 + 8) & 0xf00) >> 8;

    if (iVar2 != 3) {

      if (iVar2 == 2) {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x5e,bVar1);

      }

      else if (iVar2 == 1) {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x5d,bVar1);

      }

      else if (iVar2 == 0) {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x5b,bVar1);

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x5c,bVar1);

      }

    }

  }

  return;

}

// FUN_003FCDC0 NONMATCHING


void FUN_003fcdc0(int param_1,int param_2,u32 param_3,int param_4,int param_5)



{

  u8 bVar1;

  int iVar2;

  u32 uVar3;

  u64 uVar4;

  int iVar5;

  u32 uVar6;

  u8 uVar7;

  u8 auStack_20 [24];

  u32 auStack_8 [2];

  

  uVar7 = 5;

  auStack_8[0] = DAT_007cd958;

  auStack_8[1] = DAT_007cd95c;

  if (param_3 != 0) {

    iVar2 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

    bVar1 = param_5 == *(int *)(param_4 + 0xc);

    if (bVar1) {

      uVar7 = 6;

    }

    uVar6 = (u32)bVar1;

    FUN_0040e3c0(0,param_1 + 0x71,param_2 + -3,param_3 & 0xff,0,

                 (u32)*(u8 *)(iVar2 + 8) * 2 + uVar6);

    uVar4 = func_00171110(*(u16 *)(iVar2 + 4),*(u8 *)(iVar2 + 0xc));

    FUN_003b2cb0(0,param_1 + 0x91,param_2 + -1,param_3 | 0xffffffffffffff00,uVar7,1,uVar4,0,0);

    iVar5 = (int)(*(u32 *)(iVar2 + 8) & 0xf00) >> 8;

    if (iVar5 != 3) {

      if (iVar5 == 2) {

        sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar2 + 0x1a));

        FUN_0040eb50(0,param_1 + 0x1d1,param_2 + 7,param_3 & 0xff,auStack_8[uVar6],auStack_20,1);

      }

      else if (iVar5 == 1) {

        sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar2 + 0x18));

        FUN_0040eb50(0,param_1 + 0x1d1,param_2 + 7,param_3 & 0xff,auStack_8[uVar6],auStack_20,1);

      }

      else if (iVar5 == 0) {

        sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar2 + 0x14));

        uVar3 = auStack_8[uVar6];

        FUN_0040eb50(0,param_1 + 0x1d1,param_2 + 7,param_3 & 0xff,uVar3,auStack_20,1);

        sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar2 + 0x16));

        FUN_0040eb50(0,param_1 + 0x236,param_2 + 7,param_3 & 0xff,uVar3,auStack_20,1);

      }

    }

  }

  return;

}

// FUN_003FD010


void FUN_003fd010(int param_1,int param_2,u32 param_3,int param_4,int param_5)



{


  FUN_003fcdc0(param_1,param_2,param_3,param_4,param_5);


  return;
}

// FUN_003FD030 NONMATCHING


void FUN_003fd030(u64 param_1,u64 param_2,u32 param_3,int param_4)



{

  int iVar1;

  

  iVar1 = *(int *)(*(int *)(*(int *)(param_4 + 0xc) + 0x14) + 0x1c);

  if ((*(short *)(*(int *)(*(int *)(param_4 + 0x24) + 0x44) + 6) == -1) &&

     ((*(u32 *)(iVar1 + 8) & 0x1000) != 0)) {

    FUN_003c7e20(0,0x53,0xfa,param_3 | 0xffffffffffffff00,1,5,2,*(u16 *)(iVar1 + 6));

  }

  else if ((*(u32 *)(iVar1 + 8) & 0x1000) == 0) {

    FUN_003c7e20(0,0x53,0xfa,param_3 | 0xffffffffffffff00,1,5,0,*(u16 *)(iVar1 + 4));

  }

  else {

    FUN_003c7e20(0,0x53,0xfa,param_3 | 0xffffffffffffff00,1,5,1,

                 (u32)CONCAT12(*(u8 *)(iVar1 + 0xd),*(u16 *)(iVar1 + 4)));

  }

  return;

}

// FUN_003FD140 NONMATCHING


void FUN_003fd140(u64 param_1,u64 param_2,u32 param_3,int param_4,int param_5)



{

  u8 bVar1;

  int iVar2;

  u32 uVar3;

  

  if (param_3 != 0) {

    iVar2 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

    bVar1 = param_5 == *(int *)(param_4 + 0xc);

    if (bVar1) {

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x53,0);

    }

    uVar3 = (u32)bVar1;

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x4d,uVar3 * -2);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x4e,uVar3 * -2);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,((int)(*(u32 *)(iVar2 + 8) & 0xf00) >> 8) + 0x49,

                 bVar1);

    iVar2 = (int)(*(u32 *)(iVar2 + 8) & 0xf00) >> 8;

    if (iVar2 != 3) {

      if (iVar2 == 2) {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x52,1 - uVar3);

      }

      else if (iVar2 == 1) {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x51,1 - uVar3);

      }

      else if (iVar2 == 0) {

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x4f,1 - uVar3);

        FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x50,1 - uVar3);

      }

    }

  }

  return;

}

// FUN_003FD320 NONMATCHING


void FUN_003fd320(int param_1,int param_2,u32 param_3,int param_4,int param_5)



{

  u8 bVar1;

  int iVar2;

  u32 uVar3;

  u64 uVar4;

  int iVar5;

  u32 uVar6;

  u8 uVar7;

  u8 auStack_20 [24];

  u32 auStack_8 [2];

  

  uVar7 = 5;

  auStack_8[0] = DAT_007cd960;

  auStack_8[1] = DAT_007cd964;

  if (param_3 != 0) {

    iVar2 = *(int *)(*(int *)(param_5 + 0x14) + 0x1c);

    bVar1 = param_5 == *(int *)(param_4 + 0xc);

    if (bVar1) {

      uVar7 = 6;

    }

    uVar6 = (u32)bVar1;

    FUN_0040e3c0(0,param_1 + 0x71,param_2 + -3,param_3 & 0xff,0,

                 (u32)*(u8 *)(iVar2 + 8) * 2 + uVar6);

    uVar4 = func_00171110(*(u16 *)(iVar2 + 4),*(u8 *)(iVar2 + 0xc));

    FUN_003b2cb0(0,param_1 + 0x91,param_2 + -1,param_3 | 0xffffffffffffff00,uVar7,1,uVar4,0,0);

    iVar5 = (int)(*(u32 *)(iVar2 + 8) & 0xf00) >> 8;

    if (iVar5 != 3) {

      if (iVar5 == 2) {

        sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar2 + 0x1a));

        FUN_0040eb50(0,param_1 + 0x1d1,param_2 + 7,param_3 & 0xff,auStack_8[uVar6],auStack_20,1);

      }

      else if (iVar5 == 1) {

        sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar2 + 0x18));

        FUN_0040eb50(0,param_1 + 0x1d1,param_2 + 7,param_3 & 0xff,auStack_8[uVar6],auStack_20,1);

      }

      else if (iVar5 == 0) {

        sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar2 + 0x14));

        uVar3 = auStack_8[uVar6];

        FUN_0040eb50(0,param_1 + 0x1d1,param_2 + 7,param_3 & 0xff,uVar3,auStack_20,1);

        sprintf((char *)auStack_20,0x7cd900,*(u16 *)(iVar2 + 0x16));

        FUN_0040eb50(0,param_1 + 0x236,param_2 + 7,param_3 & 0xff,uVar3,auStack_20,1);

      }

    }

  }

  return;

}

// FUN_003FD570 NONMATCHING


u64 FUN_003fd570(int param_1,u32 *param_2)



{

  int iVar1;

  u32 uVar2;

  u32 *puVar3;

  u32 *puVar4;

  u8 bVar5;

  u32 uVar6;

  u32 uVar7;

  long lVar8;

  int iVar9;

  int *piVar10;

  int *piVar11;

  u32 uVar12;

  int aiStack_30 [12];

  

  piVar11 = (int *)(&DAT_006af140);

  piVar10 = aiStack_30;

  iVar9 = 0xb;

  do {

    iVar1 = *piVar11;

    piVar11 = piVar11 + 1;

    iVar9 = iVar9 + -1;

    *piVar10 = iVar1;

    piVar10 = piVar10 + 1;

  } while (0 < iVar9);

  uVar2 = *param_2;

  iVar9 = FUN_003c4910(uVar2,1,0xc);

  puVar3 = *(u32 **)(iVar9 + 0x14);

  *puVar3 = 1;


  puVar3[1] = uVar6;

  uVar6 = FUN_003dfeb0(puVar3);

  puVar3[2] = uVar6;

  for (uVar12 = 0; uVar12 < 0xb; uVar12 = uVar12 + 1) {

    iVar9 = aiStack_30[uVar12];

    if ((iVar9 != 0) && (lVar8 = datGetFlag(iVar9), lVar8 != 0)) {

      if (iVar9 == 0x157) {

        lVar8 = datGetFlag(0xa8);

        if (lVar8 == 0) {

          bVar5 = 1;

        }

        else {

          bVar5 = 0;

        }

      }

      else if (iVar9 == 0x152) {

        lVar8 = datGetFlag(0x52);

        if (lVar8 == 0) {

          bVar5 = 0;

        }

        else {

          bVar5 = 1;

        }

      }

      else {

        bVar5 = 1;

      }

      if (bVar5) {

        iVar9 = FUN_003c4910(uVar2,uVar12,0xc);

        puVar4 = *(u32 **)(iVar9 + 0x14);

        *puVar4 = uVar12;


        puVar4[1] = uVar7;

        uVar7 = FUN_003dfeb0(puVar4);

        puVar4[2] = uVar7;

      }

    }

  }

  return 0;

}

// FUN_003FD730
u64 FUN_003fd730(u64 param_1,int param_2)
{
  s16 sVar1;
  int iVar3;
  int iVar2;
  u64 uVar4;
  u8 auStack_20[32];

  uVar4 = param_1;
  iVar3 = *(int *)(*(int *)(param_2 + 4) + 4);
  for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
    sVar1 = datGetEquipmentIdx_s16((s16)uVar4,(s16)iVar2);
    FUN_003f1dc0_u64(uVar4,auStack_20,(s32)sVar1);
    memcpy_typed((void *)(*(int *)(*(int *)(iVar3 + 0x14) + 0x1c) + 4),auStack_20,0x1c);
    iVar3 = *(int *)(iVar3 + 0x10);
  }
  return 0;
}

// FUN_003FD7E0


u64 FUN_003fd7e0(u64 param_1,int param_2)



{

  int iVar1;

  

  iVar1 = *(int *)(param_2 + 0x14);

  FUN_003dff00(*(u32 *)(iVar1 + 8));

  FUN_003c5a20(*(u32 *)(iVar1 + 4));

  return 0;

}

// FUN_003FD820


int * FUN_003fd820(int param_1)



{

  int *piVar1;

  int iVar2;

  

  iVar2 = FUN_003c44d0(0xc,0,FUN_003fd7e0,0);

  piVar1 = *(int **)(iVar2 + 0x24);

  *piVar1 = iVar2;

  piVar1[1] = param_1;

  iVar2 = FUN_003dfeb0(0);

  piVar1[2] = iVar2;

  FUN_003fd570(param_1,(u32 *)piVar1);



  return piVar1;

}

// FUN_003FD8A0


void FUN_003fd8a0(u32 *param_1)



{

  FUN_003dff00(param_1[2]);

  FUN_003c45f0(*param_1);

  return;

}

// FUN_003FD8E0


void FUN_003fd8e0(int *param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(*(int *)(*param_1 + 0xc) + 0x14);

  FUN_003c6ee0(*(u32 *)(iVar1 + 4));

  FUN_003e04e0(param_1[2],0,0,0);

  FUN_003e04e0(param_1[2],3,0,0);

  FUN_003e04e0(*(u32 *)(iVar1 + 8),1,0,5);

  func_0010a4e0(0,0,0,3);

  return;

}

// FUN_003FD990 NONMATCHING


u64 FUN_003fd990(int *param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  u32 uVar4;

  int iVar5;

  u64 uVar6;

  

  iVar1 = *param_1;

  uVar6 = 0;

  FUN_003e0650(param_1[2]);

  for (iVar5 = *(int *)(*param_1 + 4); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x10)) {

    iVar2 = *(int *)(iVar5 + 0x14);


    FUN_003e0650(*(u32 *)(iVar2 + 8));

  }

  iVar5 = *(int *)(iVar1 + 0xc);

  iVar2 = *(int *)(iVar5 + 0x14);

  uVar4 = FUN_003c6d80(*(u32 *)(iVar2 + 4));

  if ((uVar4 & 0x40000000) != 0) {

    if (((DAT_007e0952 & 4) == 0) && ((DAT_007e095a & 4) == 0)) {

      if (((DAT_007e0952 & 8) == 0) && ((DAT_007e095a & 8) == 0)) {

        if (((DAT_007e094e & 0x20) != 0) || ((DAT_007e0958 & 0x20) != 0)) {

          func_0010a4e0(0,0,0,4);

          for (iVar5 = *(int *)(*param_1 + 4); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x10)) {

            FUN_003c6f10(*(u32 *)(*(int *)(iVar5 + 0x14) + 4));

          }

          uVar6 = 1;

          FUN_003e04e0(*(u32 *)(*(int *)(*(int *)(iVar1 + 0xc) + 0x14) + 8),1,1,0);

          FUN_003e04e0(param_1[2],0,1,0);

          FUN_003e04e0(param_1[2],3,1,0);

        }

      }

      else {

        iVar3 = FUN_003c4c80(iVar1,iVar1 + 4);

        if (iVar5 != iVar3) {

          func_0010a4e0(0,0,0,5);

          FUN_003c6f10(*(u32 *)(iVar2 + 4));

          FUN_003e04e0(*(u32 *)(iVar2 + 8),1,1,0);

          iVar5 = **(int **)(*(int *)(iVar2 + 4) + 0xc);

          iVar2 = *(int *)(*(int *)(iVar1 + 0xc) + 0x14);

          FUN_003e04e0(*(u32 *)(iVar2 + 8),1,0,5);

          FUN_003c6ee0(*(u32 *)(iVar2 + 4));

          FUN_003c4df0(*(int *)(iVar2 + 4),*(int *)(iVar2 + 4) + 4,iVar5 + -1);

        }

      }

    }

    else {

      iVar3 = FUN_003c4d20(iVar1,iVar1 + 4);

      if (iVar5 != iVar3) {

        func_0010a4e0(0,0,0,5);

        FUN_003c6f10(*(u32 *)(iVar2 + 4));

        FUN_003e04e0(*(u32 *)(iVar2 + 8),1,1,0);

        iVar5 = **(int **)(*(int *)(iVar2 + 4) + 0xc);

        iVar2 = *(int *)(*(int *)(iVar1 + 0xc) + 0x14);

        FUN_003e04e0(*(u32 *)(iVar2 + 8),1,0,5);

        FUN_003c6ee0(*(u32 *)(iVar2 + 4));

        FUN_003c4df0(*(int *)(iVar2 + 4),*(int *)(iVar2 + 4) + 4,iVar5 + -1);

      }

    }

    FUN_003c4dc0(iVar1,iVar1 + 4);

  }

  return uVar6;

}

// FUN_003FDCC0 NONMATCHING


void FUN_003fdcc0(int param_1,int param_2,int *param_3)



{

  u16 uVar1;

  int iVar2;

  int iVar3;

  u64 uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  u32 auStack_8 [2];

  

  auStack_8[0] = DAT_007cd968;

  auStack_8[1] = DAT_007cd96c;

  uVar1 = *(u16 *)(param_2 + 0x26);

  if (uVar1 != 0) {

    iVar2 = *(int *)(param_2 + 0x10);

    iVar6 = (int)*(short *)(param_2 + 0x14);

    iVar5 = (int)*(short *)(param_2 + 0x16);

    if (iVar2 == 3) {

      iVar2 = *(int *)(*(int *)(*(int *)(*param_3 + 0xc) + 0x14) + 4);

      iVar3 = *(int *)(iVar2 + 0x24);

      if (*(short *)(*(int *)(iVar3 + 0x44) + 4) == 0) {

        iVar3 = *(int *)(iVar2 + 4);

        iVar7 = 0;

        FUN_0040e3c0(0,0,0,uVar1 & 0xff,0x52,0);

        FUN_0040e3c0(0,0,0,uVar1 & 0xff,0x53,0);

        FUN_0040e3c0(0,0,0,uVar1 & 0xff,0x54,0);

        FUN_0040e3c0(0,0,0,uVar1 & 0xff,0x50,0);

        FUN_0040e3c0(0,0,0,uVar1 & 0xff,0x51,0);

        for (; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x10)) {

          iVar8 = *(int *)(iVar2 + 0x24);

          FUN_003fcbe0(iVar6 + *(int *)(iVar8 + 0x14),

                       iVar5 + *(int *)(iVar8 + 0x18) + iVar7 * *(int *)(iVar8 + 0xc),uVar1,iVar2,

                       iVar3);

          iVar7 = iVar7 + 1;

        }

      }

      else {

        iVar7 = *(int *)(iVar2 + 4);

        iVar8 = 0;

        FUN_0040e3c0(0,iVar6 + *(int *)(iVar3 + 0x14),iVar5 + *(int *)(iVar3 + 0x18),uVar1 & 0xff,

                     0x48,0);

        for (; iVar7 != 0; iVar7 = *(int *)(iVar7 + 0x10)) {

          iVar3 = *(int *)(iVar2 + 0x24);

          FUN_003fd140(iVar6 + *(int *)(iVar3 + 0x14),

                       iVar5 + *(int *)(iVar3 + 0x18) + iVar8 * *(int *)(iVar3 + 0xc),uVar1,iVar2,

                       iVar7);

          iVar8 = iVar8 + 1;

        }

      }

    }

    else if (iVar2 == 1) {

      uVar4 = FUN_00177790(**(u16 **)(param_1 + 4));

      FUN_003b32d0(0,iVar6 + 0x1c9,iVar5 + 0x26,uVar1 | 0xff00,5,0,uVar4,0x18,0x73);

    }

    else if (iVar2 == 0) {

      FUN_0040e3c0(0,*(short *)(param_2 + 0x14),*(short *)(param_2 + 0x16),uVar1 & 0xff,

                   auStack_8[param_3[1]],0);

    }

  }

  return;

}

// FUN_003FDF80 NONMATCHING


u64 FUN_003fdf80(u64 param_1)



{

  int iVar1;

  int iVar2;

  

  FUN_003e0680(((int *)param_1)[2],0x3fdcc0,param_1);

  for (iVar2 = *(int *)(*(int *)param_1 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {

    iVar1 = *(int *)(iVar2 + 0x14);

    FUN_003e0680(*(u32 *)(iVar1 + 8),0x3fdcc0,param_1);

    FUN_003c6380(*(u32 *)(iVar1 + 4));

  }

  return 0;

}

// FUN_003FE020 NONMATCHING


u64 FUN_003fe020(int param_1,u64 param_2)



{

  u16 uVar1;

  int iVar2;

  int iVar3;

  u64 uVar4;

  int iVar5;

  u8 auStack_40 [32];

  u8 *apuStack_20 [4];

  u8 *puStack_10;

  u8 *puStack_c;

  u8 *puStack_8;

  u8 *puStack_4;

  

  uVar4 = FUN_003c58f0(0,0x58,5,0x24);

  iVar2 = (int)uVar4;

  iVar5 = *(int *)(*(int *)(iVar2 + 0x24) + 0x44);

  if ((param_1 != 0) && (param_1 != 1)) {

    K_Assert((const char *)(u32)0x6aede8,0x148a);

  }

  *(short *)(iVar5 + 4) = (short)param_1;

  for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {

    uVar1 = datGetEquipmentIdx((short)param_2,(short)iVar5);


    iVar3 = FUN_003c5a40(uVar4,*(u16 *)(iVar2 + 0x10) + 1,0x20,0);

    memcpy(*(int *)(*(int *)(iVar3 + 0x14) + 0x1c) + 4,auStack_40,0x1c);

  }

  puStack_8 = (u8 *)(PTR_FUN_007cd970);

  puStack_4 = (u8 *)(PTR_FUN_007cd974);

  puStack_10 = (u8 *)(PTR_FUN_007cd978);

  puStack_c = (u8 *)(PTR_FUN_007cd97c);

  apuStack_20[0] = (u8 *)(DAT_006af170);

  apuStack_20[1] = (u8 *)DAT_006af174;

  apuStack_20[2] = (u8 *)DAT_006af178;

  apuStack_20[3] = (u8 *)DAT_006af17c;

  FUN_003c5e20(uVar4,apuStack_20[param_1 + 6]);

  FUN_003c5ee0(uVar4,apuStack_20[param_1 + 4]);

  FUN_003c6d40(uVar4,apuStack_20[param_1 * 2],apuStack_20[param_1 * 2 + 1]);

  *(u16 *)(*(int *)(iVar2 + 0x24) + 6) = 10;

  *(u16 *)(*(int *)(iVar2 + 0x24) + 8) = 5;

  return uVar4;

}

// FUN_003FE1F0 NONMATCHING


u8 FUN_003fe1f0(u64 param_1)



{

  long lVar1;

  long lVar2;

  

  lVar1 = FUN_003c6270();

  lVar2 = FUN_003c6ce0(param_1);

  if ((lVar2 != 0) || (lVar2 = FUN_003c6d10(param_1), lVar2 != 0)) {

    func_0010a4e0(0,0,0,0);

  }

  lVar2 = FUN_003c6ca0(param_1);

  if ((lVar2 != 0) || (lVar2 = FUN_003c6cc0(param_1), lVar2 != 0)) {

    func_0010a4e0(0,0,0,5);

  }

  return lVar1 == 3;

}

// FUN_003FE2B0 NONMATCHING


u32 FUN_003fe2b0(void)



{

  short sVar1;

  u8 bVar2;

  u32 uVar3;

  long lVar4;

  u32 uVar5;

  int iVar6;

  short *psVar7;

  short *psVar8;

  short sVar9;

  u32 uVar10;

  short asStack_10 [8];

  

  uVar10 = 0;

  while( 1 ) {

    psVar8 = (s16 *)(&DAT_006af180);

    psVar7 = asStack_10;

    iVar6 = 4;

    do {

      sVar9 = *psVar8;

      sVar1 = psVar8[1];

      psVar8 = psVar8 + 2;

      iVar6 = iVar6 + -1;

      *psVar7 = sVar9;

      psVar7[1] = sVar1;

      psVar7 = psVar7 + 2;

    } while (0 < iVar6);

    if (uVar10 < 8) {

      sVar9 = asStack_10[uVar10];

    }

    else {

      sVar9 = 0;

    }

    if (sVar9 == 0) break;

    lVar4 = func_00170760(1,sVar9);

    if (lVar4 != 0) {

      bVar2 = 1;

LAB_003fe35c:

      if (bVar2) {

        uVar3 = 1;

      }

      else {

        for (sVar9 = 0; sVar9 < 300; sVar9 = sVar9 + 1) {

          uVar5 = func_0016f720(1);

          if ((uVar5 & 0xff00) != 0) {

            return 1;

          }

        }

        uVar3 = 0;

      }

      return uVar3;

    }

    uVar10 = uVar10 + 1;

  }

  bVar2 = 0;

  goto LAB_003fe35c;

}

// FUN_003FE3E0 NONMATCHING


u64 FUN_003fe3e0(u16 param_1)



{

  short sVar1;

  short sVar2;

  int iVar3;

  u32 uVar4;

  u64 uVar5;

  long lVar6;

  int iVar7;

  short *psVar8;

  short *psVar9;

  u32 uVar10;

  short asStack_30 [8];

  u8 auStack_20 [32];

  

  uVar5 = FUN_003c58f0(0,0x58,7,0x1a);

  iVar3 = (int)uVar5;

  iVar7 = *(int *)(*(int *)(iVar3 + 0x24) + 0x44);

  *(u16 *)(iVar7 + 4) = param_1;

  *(u16 *)(iVar7 + 6) = 0xfffc;

  uVar10 = 0;

  while( 1 ) {

    psVar9 = (s16 *)(&DAT_006af180);

    psVar8 = asStack_30;

    iVar7 = 4;

    do {

      sVar2 = *psVar9;

      sVar1 = psVar9[1];

      psVar9 = psVar9 + 2;

      iVar7 = iVar7 + -1;

      *psVar8 = sVar2;

      psVar8[1] = sVar1;

      psVar8 = psVar8 + 2;

    } while (0 < iVar7);

    if (uVar10 < 8) {

      sVar2 = asStack_30[uVar10];

    }

    else {

      sVar2 = 0;

    }

    if (sVar2 == 0) break;


    if (lVar6 != 0) {

      iVar7 = FUN_003c5a40(uVar5,*(u16 *)(iVar3 + 0x10) + 1,0x20,0);

      memcpy(*(int *)(*(int *)(iVar7 + 0x14) + 0x1c) + 4,auStack_20,0x1c);

      for (iVar7 = 0; uVar4 = FUN_00175410(), iVar7 < (int)(uVar4 & 0xffff); iVar7 = iVar7 + 1) {

        datPersonaGetHeroPersona((short)iVar7);

      }

    }

    uVar10 = uVar10 + 1;

  }


  FUN_003c6ee0(uVar5);

  FUN_003c5e80(uVar5,0x3fadc0);

  FUN_003c5e20(uVar5,0x3f4de0);

  FUN_003c5ee0(uVar5,0x3f9510);

  FUN_003c6d40(uVar5,0x39,0x48);

  *(u16 *)(*(int *)(iVar3 + 0x24) + 6) = 0xb;

  *(u16 *)(*(int *)(iVar3 + 0x24) + 8) = 6;

  return uVar5;

}

// FUN_003FE5D0 NONMATCHING


u8 FUN_003fe5d0(u64 param_1)



{

  long lVar1;

  long lVar2;

  

  lVar1 = FUN_003c6270();

  lVar2 = FUN_003c6ce0(param_1);

  if ((lVar2 != 0) || (lVar2 = FUN_003c6d10(param_1), lVar2 != 0)) {

    func_0010a4e0(0,0,0,0);

  }

  lVar2 = FUN_003c6ca0(param_1);

  if ((lVar2 != 0) || (lVar2 = FUN_003c6cc0(param_1), lVar2 != 0)) {

    func_0010a4e0(0,0,0,5);

  }

  return lVar1 == 3;

}

// FUN_003FE690 NONMATCHING


u64 FUN_003fe690(u64 param_1,u64 param_2)



{

  int iVar1;

  int iVar2;

  u32 uVar3;

  u32 uVar4;

  long lVar5;

  u64 uVar6;

  int iVar7;

  u8 auStack_8 [6];

  u16 uStack_2;

  

  for (iVar7 = 0; uVar4 = FUN_00175410(), iVar7 < (int)(uVar4 & 0xffff); iVar7 = iVar7 + 1) {

    lVar5 = datPersonaGetHeroPersona((short)iVar7);

    if (lVar5 != 0) {

      uVar6 = FUN_003c5a40(param_1,*(u16 *)((int)param_1 + 0x10) + 1,0x20,0);

      iVar1 = *(int *)(*(int *)((int)uVar6 + 0x14) + 0x1c);

      memcpy(iVar1 + 4,param_2,0x1c);

      *(int *)(iVar1 + 0x14) = (int)lVar5;


      if (lVar5 == 0) {

        *(u32 *)(iVar1 + 0x18) = 0;

        *(u16 *)(iVar1 + 0x1c) = 0;

      }

      else {

        iVar2 = func_00170ed0(uStack_2,auStack_8);


        *(u32 *)(iVar1 + 0x18) = uVar3;

        *(u16 *)(iVar1 + 0x1c) = uStack_2;

      }


    }

  }

  return 0;

}

// FUN_003FE7D0


u64 FUN_003fe7d0(u64 param_1,int param_2)



{

  u16 uVar1;

  u32 *puVar2;

  u16 uVar3;

  

  puVar2 = *(u32 **)(*(int *)(param_2 + 0x14) + 0x1c);

  if ((short)puVar2[7] == 0) {

    *puVar2 = *puVar2 | 0x10;

  }

  uVar1 = *(u16 *)(puVar2[5] + 2);

  if (uVar1 == FUN_001752b0()) {

    *puVar2 = *puVar2 | 0x40;

  }

  return 0;

}

// FUN_003FE850 NONMATCHING


u64 FUN_003fe850(u16 param_1,u64 param_2)



{

  int iVar1;

  int iVar2;

  u64 uVar3;

  

  uVar3 = FUN_003c58f0(0,0x58,6,0x1e);

  iVar2 = (int)uVar3;

  iVar1 = *(int *)(*(int *)(iVar2 + 0x24) + 0x44);

  *(u16 *)(iVar1 + 4) = param_1;

  *(u16 *)(iVar1 + 6) = 0xfffb;


  FUN_003c6ee0(uVar3);

  FUN_003c5e80(uVar3,0x3fadc0);

  FUN_003c5e20(uVar3,0x3f4de0);

  FUN_003c5ee0(uVar3,0x3f9510);

  FUN_003c6d40(uVar3,0x19,0x79);

  *(u16 *)(*(int *)(iVar2 + 0x24) + 6) = 0xb;

  *(u16 *)(*(int *)(iVar2 + 0x24) + 8) = 6;

  return uVar3;

}

// FUN_003FE950 NONMATCHING


u8 FUN_003fe950(u64 param_1)



{

  long lVar1;

  long lVar2;

  

  lVar1 = FUN_003c6270();

  lVar2 = FUN_003c6ce0(param_1);

  if ((lVar2 != 0) || (lVar2 = FUN_003c6d10(param_1), lVar2 != 0)) {

    func_0010a4e0(0,0,0,0);

  }

  lVar2 = FUN_003c6ca0(param_1);

  if ((lVar2 != 0) || (lVar2 = FUN_003c6cc0(param_1), lVar2 != 0)) {

    func_0010a4e0(0,0,0,5);

  }

  return lVar1 == 3;

}

// FUN_003FEA10 NONMATCHING


u64 FUN_003fea10(u64 param_1,u32 *param_2)



{

  short sVar1;

  int iVar2;

  long lVar3;

  u64 uVar4;

  int iVar5;

  short *psVar6;

  

  psVar6 = (short *)*param_2;

  for (iVar5 = 0; iVar5 < (int)param_2[1]; iVar5 = iVar5 + 1) {

    if ((((psVar6[2] == 0) || (lVar3 = datGetFlag(), lVar3 == 1)) && (sVar1 = *psVar6, sVar1 != 0)

        ) && (psVar6[4] != 0)) {

      uVar4 = FUN_003c5a40(param_1,*(u16 *)((int)param_1 + 0x10) + 1,0x20,0);

      *(int *)((int)uVar4 + 4) = (int)sVar1;

      iVar2 = *(int *)(*(int *)((int)uVar4 + 0x14) + 0x1c);


      memcpy(iVar2 + 0x14,psVar6 + 3,0xe);


    }

    psVar6 = psVar6 + 7;

  }

  return 0;

}

// FUN_003FEB30 NONMATCHING


u64 FUN_003feb30(u64 param_1,int param_2)



{

  short sVar1;

  u32 *puVar2;

  short sVar3;

  u32 uVar4;

  int iVar5;

  u32 uVar6;

  int iStack_c;

  int iStack_8;

  int iStack_4;

  

  puVar2 = *(u32 **)(*(int *)(param_2 + 0x14) + 0x1c);

  sVar1 = (short)puVar2[1];

  iStack_4 = -1;

  sVar3 = 0;

  func_00170ed0(sVar1,&iStack_4);

  if (iStack_4 == 4) {

    sVar3 = func_00170760(1,sVar1);

  }

  else if ((((iStack_4 == 3) || (iStack_4 == 2)) || (iStack_4 == 1)) || (iStack_4 == 0)) {

    sVar3 = 0;

    for (iVar5 = 0; iVar5 < 300; iVar5 = iVar5 + 1) {

      uVar6 = datGetEquipmentId(1,iVar5);

      if ((long)sVar1 == (uVar6 & 0xffff)) {

        sVar3 = sVar3 + 1;

      }

    }

  }

  *(short *)((int)puVar2 + 0xe) = sVar3;

  if (0x62 < sVar3) {

    *puVar2 = *puVar2 | 0x10;

  }

  if (*(short *)((int)puVar2 + 0x16) == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x15b8);

  }

  sVar1 = (short)puVar2[5];

  if (sVar1 != 0) {

    iStack_8 = -1;

    uVar6 = 0;

    func_00170ed0(sVar1,&iStack_8);

    if (iStack_8 == 4) {

      uVar6 = func_00170760(1,sVar1);

      uVar6 = uVar6 & 0xffff;

    }

    else if (((iStack_8 == 3) || (iStack_8 == 2)) || ((iStack_8 == 1 || (iStack_8 == 0)))) {

      for (iVar5 = 0; iVar5 < 300; iVar5 = iVar5 + 1) {

        uVar4 = datGetEquipmentId(1,iVar5);

        if ((long)sVar1 == (uVar4 & 0xffff)) {

          uVar6 = (u32)((int)uVar6 + 1);

        }

      }

    }

    if ((long)uVar6 < (long)*(short *)((int)puVar2 + 0x16)) goto LAB_003fee10;

  }

  sVar1 = (short)puVar2[6];

  if (sVar1 == 0) {

    return 0;

  }

  iStack_c = -1;

  uVar6 = 0;

  func_00170ed0(sVar1,&iStack_c);

  if (iStack_c == 4) {

    uVar6 = func_00170760(1,sVar1);

    uVar6 = uVar6 & 0xffff;

  }

  else if (((iStack_c == 3) || (iStack_c == 2)) || ((iStack_c == 1 || (iStack_c == 0)))) {

    for (iVar5 = 0; iVar5 < 300; iVar5 = iVar5 + 1) {

      uVar4 = datGetEquipmentId(1,iVar5);

      if ((long)sVar1 == (uVar4 & 0xffff)) {

        uVar6 = (u32)((int)uVar6 + 1);

      }

    }

  }

  if ((long)*(short *)((int)puVar2 + 0x1a) <= (long)uVar6) {

    return 0;

  }

LAB_003fee10:

  *puVar2 = *puVar2 | 0x10;

  return 0;

}

// FUN_003FEE40 NONMATCHING


u64 FUN_003fee40(int param_1)



{

  u32 *puVar1;

  short sVar2;

  int iVar3;

  

  for (iVar3 = *(int *)(param_1 + 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x10)) {

    puVar1 = *(u32 **)(*(int *)(iVar3 + 0x14) + 0x1c);


    *(short *)((int)puVar1 + 0xe) = sVar2;

    if (0x62 < sVar2) {

      *puVar1 = *puVar1 | 0x10;

    }

    if (*(short *)((int)puVar1 + 0x16) == 0) {

      K_Assert((const char *)(u32)0x6aede8,0x15b8);

    }

    if ((((short)puVar1[5] != 0) && (sVar2 = FUN_003f1910(0), sVar2 < *(short *)((int)puVar1 + 0x16))

        ) || (((short)puVar1[6] != 0 &&

              (sVar2 = FUN_003f1910(0), sVar2 < *(short *)((int)puVar1 + 0x1a))))) {

      *puVar1 = *puVar1 | 0x10;

    }

  }

  return 0;

}

// FUN_003FEF30 NONMATCHING


u64 FUN_003fef30(u64 param_1,long param_2)



{

  int iVar1;

  int iVar2;

  u64 uVar3;

  long lVar4;

  u8 **ppuVar5;

  int iVar6;

  

  uVar3 = FUN_003c58f0(0,0x58,5,0x1a);

  iVar1 = (int)uVar3;

  iVar2 = *(int *)(*(int *)(iVar1 + 0x24) + 0x44);

  *(short *)(iVar2 + 4) = (short)param_1;

  ppuVar5 = (u8 **)&PTR_DAT_006ad4a0;

  if (param_2 == 0) {

    *(u16 *)(iVar2 + 6) = 0xfffe;

  }

  else {

    *(u16 *)(iVar2 + 6) = 0xfffd;

    ppuVar5 = (u8 **)0x6ad4a8;

  }

  if (ppuVar5 == (u8 **)0x0) {

    K_Assert((const char *)(u32)0x6aede8,0x15ea);

  }


  if (param_2 == 0) {


    for (iVar6 = 1; iVar6 <= iVar2; iVar6 = iVar6 + 1) {

      if ((iVar6 < 0) || (DAT_006ad4b4 < iVar6)) {

        K_Assert((const char *)(u32)0x6aede8,0x1df);

      }

      if ((u8 *)PTR_DAT_006ad4b0 + iVar6 * 8 != (u8 *)0x0) {


      }

    }

  }

  if (param_2 == 0) {

    FUN_0017d610(param_1);


    if (lVar4 != 0) {


      FUN_003c5a20(lVar4);

    }

  }

  FUN_003c6ee0(uVar3);

  FUN_003c5e80(uVar3,0x3fadc0);

  FUN_003c5e20(uVar3,0x3f4de0);

  FUN_003c5ee0(uVar3,0x3f9510);

  FUN_003c6d40(uVar3,0x39,0x48);

  *(u16 *)(*(int *)(iVar1 + 0x24) + 6) = 10;

  *(u16 *)(*(int *)(iVar1 + 0x24) + 8) = 5;

  return uVar3;

}

// FUN_003FF150 NONMATCHING


u64 FUN_003ff150(u64 param_1,long param_2)



{

  u32 uVar1;

  u64 uVar2;

  long lVar3;

  u32 uVar4;

  u8 **ppuVar5;

  int iVar6;

  u8 uStack_8;

  u8 bStack_7;

  u16 uStack_6;

  

  dat0017d6d0(param_1,&uStack_8);

  uVar1 = 0;

  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1) {

    if ((*(short *)(&DAT_006acc60 + uVar4 * 2) == -1) || (lVar3 = datGetFlag(), lVar3 == 0)) {

      if ((uVar4 == 6) && (lVar3 = datGetScenarioMode(), lVar3 != 0)) {

        uVar1 = uVar1 | 0x40;

      }

    }

    else {

      uVar1 = uVar1 | 1 << (uVar4 & 0x1f) & 0xffffU;

    }

  }

  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1) {

    if (((uVar4 != 6) || (lVar3 = datGetScenarioMode(), lVar3 == 0)) &&

       (*(short *)(&DAT_006acc60 + uVar4 * 2) != -1)) {

      if (((u32)uStack_6 & 1 << (uVar4 & 0x1f)) == 0) {

        datSetFlag(*(short *)(&DAT_006acc60 + uVar4 * 2),0);

      }

      else {

        datSetFlag();

      }

    }

  }

  uVar2 = FUN_003c58f0(0,0x58,5,0x1a);

  iVar6 = *(int *)(*(int *)((int)uVar2 + 0x24) + 0x44);

  ppuVar5 = (u8 **)&PTR_DAT_006ad4a0;

  if (param_2 == 0) {

    *(u16 *)(iVar6 + 6) = 0xfffe;

  }

  else {

    *(u16 *)(iVar6 + 6) = 0xfffd;

    ppuVar5 = (u8 **)0x6ad4a8;

  }

  if (ppuVar5 == (u8 **)0x0) {

    K_Assert((const char *)(u32)0x6aede8,0x162f);

  }


  if (param_2 == 0) {

    for (iVar6 = 1; iVar6 <= (int)(u32)bStack_7; iVar6 = iVar6 + 1) {

      if ((iVar6 < 0) || (DAT_006ad4b4 < iVar6)) {

        K_Assert((const char *)(u32)0x6aede8,0x1df);

      }

      if ((u8 *)PTR_DAT_006ad4b0 + iVar6 * 8 != (u8 *)0x0) {


      }

    }

  }

  for (uVar4 = 0; uVar4 < 8; uVar4 = uVar4 + 1) {

    if (((uVar4 != 6) || (lVar3 = datGetScenarioMode(), lVar3 == 0)) &&

       (*(short *)(&DAT_006acc60 + uVar4 * 2) != -1)) {

      if ((uVar1 & 1 << (uVar4 & 0x1f)) == 0) {

        datSetFlag(*(short *)(&DAT_006acc60 + uVar4 * 2),0);

      }

      else {

        datSetFlag();

      }

    }

  }

  return uVar2;

}

// FUN_003FF460 NONMATCHING


void FUN_003ff460(int param_1,u64 param_2)



{

  u32 *puVar1;

  int iVar2;

  u8 bVar3;

  u8 bVar4;

  long lVar5;

  int iVar6;

  

  for (iVar6 = *(int *)(param_1 + 4); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x10)) {

    puVar1 = *(u32 **)(*(int *)(iVar6 + 0x14) + 0x1c);

    lVar5 = FUN_003c4bf0(param_2,(int)param_2 + 4,(short)puVar1[1]);

    if (lVar5 == 0) {

      *puVar1 = *puVar1 | 0x80;

    }

    else {

      iVar2 = *(int *)(*(int *)((int)lVar5 + 0x14) + 0x1c);

      bVar3 = 0;

      if (*(short *)((int)puVar1 + 0x16) == *(short *)(iVar2 + 0x16)) {

        bVar3 = (short)puVar1[5] == *(short *)(iVar2 + 0x14);

      }

      bVar4 = 0;

      if (bVar3) {

        bVar4 = *(short *)((int)puVar1 + 0x1a) == *(short *)(iVar2 + 0x1a);

      }

      bVar3 = 0;

      if (bVar4) {

        bVar3 = (short)puVar1[6] == *(short *)(iVar2 + 0x18);

      }

      if (!bVar3) {

        *puVar1 = *puVar1 | 0x80;

      }

      FUN_003c49e0(param_2,(int)param_2 + 4);

    }

  }

  return;

}

// FUN_003FF570 NONMATCHING


u8 FUN_003ff570(u64 param_1)



{

  long lVar1;

  long lVar2;

  

  lVar1 = FUN_003c6270();

  lVar2 = FUN_003c6ce0(param_1);

  if ((lVar2 != 0) || (lVar2 = FUN_003c6d10(param_1), lVar2 != 0)) {

    func_0010a4e0(0,0,0,0);

  }

  lVar2 = FUN_003c6ca0(param_1);

  if ((lVar2 != 0) || (lVar2 = FUN_003c6cc0(param_1), lVar2 != 0)) {

    func_0010a4e0(0,0,0,5);

  }

  return lVar1 == 3;

}

// FUN_003FF630 NONMATCHING


void FUN_003ff630(u32 param_1,u64 param_2,u64 param_3,u64 param_4,

                 u8 param_5,short param_6,short param_7,u32 param_8)



{

  u8 bVar1;

  u8 bVar2;

  u16 uVar3;

  u16 uVar4;

  u16 **ppuVar5;

  u16 **ppuVar6;

  u16 **ppuVar7;

  int iVar8;

  u32 uVar9;

  u16 *puVar10;

  u8 *pbVar11;

  u16 *puVar12;

  u8 *pbVar13;

  u16 *unaff_s6_lo;

  u8 abStack_780b0 [360576];

  u16 auStack_20030 [65240];

  u16 *apuStack_1e0 [4];

  u16 *puStack_1d0;

  u16 *puStack_1c8;

  u16 *puStack_1c0;

  u16 auStack_1b0 [16];

  u16 auStack_190 [16];

  u16 auStack_170 [24];

  u16 auStack_140 [16];

  u16 auStack_120 [16];

  u16 auStack_100 [16];

  u16 auStack_e0 [24];

  u8 abStack_b0 [128];

  u16 auStack_30 [24];

  

  puVar12 = (u16 *)(&DAT_006af190);

  puVar10 = auStack_30;

  iVar8 = 9;

  do {

    uVar3 = *puVar12;

    uVar4 = puVar12[1];

    puVar12 = puVar12 + 2;

    iVar8 = iVar8 + -1;

    *puVar10 = uVar3;

    puVar10[1] = uVar4;

    puVar10 = puVar10 + 2;

  } while (0 < iVar8);

  pbVar13 = (u8 *)(&DAT_006af1c0);

  pbVar11 = abStack_b0;

  iVar8 = 0x3f;

  do {

    bVar1 = *pbVar13;

    bVar2 = pbVar13[1];

    pbVar13 = pbVar13 + 2;

    iVar8 = iVar8 + -1;

    *pbVar11 = bVar1;

    pbVar11[1] = bVar2;

    pbVar11 = pbVar11 + 2;

  } while (0 < iVar8);

  puVar12 = (u16 *)(&DAT_006af240);

  puVar10 = auStack_e0;

  iVar8 = 10;

  do {

    uVar3 = *puVar12;

    uVar4 = puVar12[1];

    puVar12 = puVar12 + 2;

    iVar8 = iVar8 + -1;

    *puVar10 = uVar3;

    puVar10[1] = uVar4;

    puVar10 = puVar10 + 2;

  } while (0 < iVar8);

  puVar12 = (u16 *)(&DAT_006af270);

  puVar10 = auStack_100;

  iVar8 = 8;

  do {

    uVar3 = *puVar12;

    uVar4 = puVar12[1];

    puVar12 = puVar12 + 2;

    iVar8 = iVar8 + -1;

    *puVar10 = uVar3;

    puVar10[1] = uVar4;

    puVar10 = puVar10 + 2;

  } while (0 < iVar8);

  puVar12 = (u16 *)(&DAT_006af290);

  puVar10 = auStack_120;

  iVar8 = 8;

  do {

    uVar3 = *puVar12;

    uVar4 = puVar12[1];

    puVar12 = puVar12 + 2;

    iVar8 = iVar8 + -1;

    *puVar10 = uVar3;

    puVar10[1] = uVar4;

    puVar10 = puVar10 + 2;

  } while (0 < iVar8);

  puVar12 = (u16 *)(&DAT_006af2b0);

  puVar10 = auStack_140;

  iVar8 = 6;

  do {

    uVar3 = *puVar12;

    uVar4 = puVar12[1];

    puVar12 = puVar12 + 2;

    iVar8 = iVar8 + -1;

    *puVar10 = uVar3;

    puVar10[1] = uVar4;

    puVar10 = puVar10 + 2;

  } while (0 < iVar8);

  puVar12 = (u16 *)(&DAT_006af2d0);

  puVar10 = auStack_170;

  iVar8 = 0xc;

  do {

    uVar3 = *puVar12;

    uVar4 = puVar12[1];

    puVar12 = puVar12 + 2;

    iVar8 = iVar8 + -1;

    *puVar10 = uVar3;

    puVar10[1] = uVar4;

    puVar10 = puVar10 + 2;

  } while (0 < iVar8);

  puVar12 = (u16 *)(&DAT_006af300);

  puVar10 = auStack_190;

  iVar8 = 6;

  do {

    uVar3 = *puVar12;

    uVar4 = puVar12[1];

    puVar12 = puVar12 + 2;

    iVar8 = iVar8 + -1;

    *puVar10 = uVar3;

    puVar10[1] = uVar4;

    puVar10 = puVar10 + 2;

  } while (0 < iVar8);

  puVar12 = (u16 *)(&DAT_006af320);

  puVar10 = auStack_1b0;

  iVar8 = 8;

  do {

    uVar3 = *puVar12;

    uVar4 = puVar12[1];

    puVar12 = puVar12 + 2;

    iVar8 = iVar8 + -1;

    *puVar10 = uVar3;

    puVar10[1] = uVar4;

    puVar10 = puVar10 + 2;

  } while (0 < iVar8);

  ppuVar6 = (u16 **)0x24;

  ppuVar7 = apuStack_1e0;

  ppuVar5 = ppuVar7;

  while (ppuVar5 != (u16 **)0x0) {

    *(u8 *)ppuVar7 = 0;

    ppuVar7 = (u16 **)((int)ppuVar7 + 1);

    ppuVar6 = (u16 **)((int)ppuVar6 + -1);

    ppuVar5 = ppuVar6;

  }

  apuStack_1e0[0] = auStack_e0;

  apuStack_1e0[1] = auStack_100;

  apuStack_1e0[2] = auStack_120;

  apuStack_1e0[3] = auStack_140;

  puStack_1d0 = auStack_170;

  puStack_1c8 = auStack_190;

  puStack_1c0 = auStack_1b0;

  uVar9 = (u32)((param_8 & 1) != 0);

  if (apuStack_1e0[param_6] != (u16 *)0x0) {

    unaff_s6_lo = apuStack_1e0[param_6];

  }

  iVar8 = uVar9 * 2;

  FUN_0040e3f0(0,0,param_1,param_1,param_2,param_3,param_5,auStack_30[param_6 * 2 + uVar9],0,0,0);

  bVar1 = abStack_b0[(int)param_7 + param_6 * 0xe];

  FUN_0040e3f0(0,0,param_1,param_1,param_2,param_3,param_5,unaff_s6_lo[iVar8 + (u32)bVar1 * 4],0,0,

               0);

  if ((param_8 & 2) != 0) {

    FUN_0040e3f0(0,0,param_1,param_1,param_2,param_3,param_5,

                 unaff_s6_lo[iVar8 + 1 + (u32)bVar1 * 4],0,0,0);

  }

  return;

}

// FUN_003FFA20 NONMATCHING


u8 FUN_003ffa20(u64 param_1,u64 param_2,int param_3)



{

  short sVar1;

  int iVar2;

  float fVar3;

  

  if (*(short *)(param_3 + 0xe) == 0) {

    sVar1 = *(short *)(param_3 + 10);

    fVar3 = ((float)(int)sVar1 * 0.5) / (float)(int)*(short *)(param_3 + 0xc);

    iVar2 = 0xff - (sVar1 * 0x100 - (int)sVar1) / (int)*(short *)(param_3 + 0xc);

  }

  else {

    fVar3 = (float)cosf(DAT_007cae00 +

                                (DAT_007cae00 * (float)(int)*(short *)(param_3 + 10)) /

                                (float)(int)*(short *)(param_3 + 0xc));

    fVar3 = -fVar3 * 0.25;

    iVar2 = 0x80 - ((int)*(short *)(param_3 + 10) << 7) / (int)*(short *)(param_3 + 0xc);

  }

  FUN_003ff630(fVar3 + 1.0,param_1,param_2,0,iVar2,*(u16 *)(param_3 + 0x10),

               *(short *)(param_3 + 8) + -1,1);

  sVar1 = *(short *)(param_3 + 10) + 1;

  *(short *)(param_3 + 10) = sVar1;

  return *(short *)(param_3 + 0xc) <= sVar1;

}

// FUN_003FFBB0 NONMATCHING


void FUN_003ffbb0(int param_1,int param_2)



{

  u32 *puVar1;

  u32 uVar2;

  u64 uVar3;

  u64 uVar4;

  long lVar5;

  

  for (; param_2 != 0; param_2 = *(int *)(param_2 + 0x10)) {

    puVar1 = *(u32 **)(*(int *)(param_2 + 0x14) + 0x1c);

    uVar2 = puVar1[1];

    if (uVar2 == 0xb) {

      lVar5 = FUN_0017c700();

      if (lVar5 == 0) {

        *puVar1 = *puVar1 | 1;

      }

      else {

        *puVar1 = *puVar1 & 0xfffffffe;

      }

    }

    else if (uVar2 == 0xd) {


      if (lVar5 == 0) {

        *puVar1 = *puVar1 | 1;

      }

      else {

        *puVar1 = *puVar1 & 0xfffffffe;

      }

    }

    else if (uVar2 == 6) {

      uVar3 = FUN_003e6dc0();

      uVar4 = FUN_003c58f0(0,0x58,5,0x1a);


      FUN_003c5a20(uVar4);

      if (lVar5 == 0) {

        *puVar1 = *puVar1 | 1;

      }

    }

    else if (uVar2 == 5) {

      uVar3 = FUN_003e6dc0();

      uVar4 = FUN_003c58f0(0,0x58,5,0x1a);


      FUN_003c5a20(uVar4);

      if (lVar5 == 0) {

        *puVar1 = *puVar1 | 1;

      }

    }

    else if (uVar2 == 1) {

      uVar3 = FUN_003e6dc0();

      uVar4 = FUN_003c58f0(0,0x58,5,0x1a);


      FUN_003c5a20(uVar4);

      if (lVar5 == 0) {

        *puVar1 = *puVar1 | 1;

      }

    }

  }

  return;

}

// FUN_003FFE00


void FUN_003ffe00(int param_1)



{

  int iVar1;

  int iVar2;

  

  if (param_1 != 0) {

    iVar1 = *(int *)param_1;

    for (iVar2 = *(int *)(iVar1 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {

      FUN_003ffbb0(iVar1,iVar2);

    }

  }

  return;

}

// FUN_003FFE60 NONMATCHING


int * FUN_003ffe60(u64 param_1)



{

  u8 uVar1;

  u8 uVar2;

  char cVar3;

  int *piVar4;

  int iVar5;

  long lVar6;

  u64 uVar7;

  u64 uVar8;

  int iVar9;

  u64 *puVar10;

  u8 *puVar11;

  u64 unaff_s0;

  u64 unaff_s1;

  int unaff_s2_lo;

  u64 unaff_s3;

  u64 uVar12;

  u64 uStack_58;

  u64 uStack_50;

  u64 uStack_48;

  u64 uStack_40;

  u64 uStack_38;

  u64 uStack_30;

  u64 uStack_28;

  u64 uStack_20;

  u64 uStack_18;

  u64 uStack_10;

  u64 uStack_8;

  

  uVar12 = 0x4006c0;

  switch(param_1) {

  case 0:

    unaff_s1 = 0x9a;

    unaff_s0 = 0x81;

    unaff_s3 = 0x66;

    unaff_s2_lo = 5;

    puVar11 = (u8 *)(&DAT_007cd980);

    puVar10 = &uStack_10;

    iVar9 = 4;

    do {

      uVar1 = *puVar11;

      uVar2 = puVar11[1];

      puVar11 = puVar11 + 2;

      iVar9 = iVar9 + -1;

      *(u8 *)puVar10 = uVar1;

      *(u8 *)((int)puVar10 + 1) = uVar2;

      puVar10 = (u64 *)((int)puVar10 + 2);

    } while (0 < iVar9);

    uStack_8 = uStack_10;

    break;

  default:

    unaff_s1 = 0xe6;

    unaff_s0 = 0x16d;

    unaff_s3 = 0x70;

    unaff_s2_lo = 4;

    puVar11 = (u8 *)(&DAT_007cd9c8);

    puVar10 = &uStack_58;

    iVar9 = unaff_s2_lo;

    do {

      uVar1 = *puVar11;

      uVar2 = puVar11[1];

      puVar11 = puVar11 + 2;

      iVar9 = iVar9 + -1;

      *(u8 *)puVar10 = uVar1;

      *(u8 *)((int)puVar10 + 1) = uVar2;

      puVar10 = (u64 *)((int)puVar10 + 2);

    } while (0 < iVar9);

    uStack_8 = uStack_58;

    break;

  case 2:

    unaff_s1 = 0xd7;

    unaff_s0 = 100;

    unaff_s3 = 0x70;

    unaff_s2_lo = 4;

    puVar11 = (u8 *)(&DAT_007cd988);

    puVar10 = &uStack_18;

    iVar9 = unaff_s2_lo;

    do {

      uVar1 = *puVar11;

      uVar2 = puVar11[1];

      puVar11 = puVar11 + 2;

      iVar9 = iVar9 + -1;

      *(u8 *)puVar10 = uVar1;

      *(u8 *)((int)puVar10 + 1) = uVar2;

      puVar10 = (u64 *)((int)puVar10 + 2);

    } while (0 < iVar9);

    uStack_8 = uStack_18;

    uVar12 = 0x400740;

    break;

  case 3:

    unaff_s1 = 0x5d;

    unaff_s0 = 0x55;

    unaff_s3 = 0x71;

    unaff_s2_lo = 3;

    puVar11 = (u8 *)(&DAT_007cd9b8);

    puVar10 = &uStack_48;

    iVar9 = 4;

    do {

      uVar1 = *puVar11;

      uVar2 = puVar11[1];

      puVar11 = puVar11 + 2;

      iVar9 = iVar9 + -1;

      *(u8 *)puVar10 = uVar1;

      *(u8 *)((int)puVar10 + 1) = uVar2;

      puVar10 = (u64 *)((int)puVar10 + 2);

    } while (0 < iVar9);

    uStack_8 = uStack_48;

    break;

  case 4:

    iVar9 = 0;

    lVar6 = datGetFlag(0x170);

    if (lVar6 != 0) {

      iVar9 = 2;

    }

    unaff_s3 = 0x62;

    if (iVar9 == 3) {

      unaff_s1 = 0x46;

      unaff_s0 = 0x6c;

      unaff_s2_lo = 6;

      puVar11 = (u8 *)(&DAT_007cd9a8);

      puVar10 = &uStack_38;

      iVar9 = 4;

      do {

        uVar1 = *puVar11;

        uVar2 = puVar11[1];

        puVar11 = puVar11 + 2;

        iVar9 = iVar9 + -1;

        *(u8 *)puVar10 = uVar1;

        *(u8 *)((int)puVar10 + 1) = uVar2;

        puVar10 = (u64 *)((int)puVar10 + 2);

      } while (0 < iVar9);

      uStack_8 = uStack_38;

    }

    else if (iVar9 == 2) {

      unaff_s1 = 0x77;

      unaff_s0 = 0x6c;

      unaff_s2_lo = 5;

      puVar11 = (u8 *)(&DAT_007cd9a0);

      puVar10 = &uStack_30;

      iVar9 = 4;

      do {

        uVar1 = *puVar11;

        uVar2 = puVar11[1];

        puVar11 = puVar11 + 2;

        iVar9 = iVar9 + -1;

        *(u8 *)puVar10 = uVar1;

        *(u8 *)((int)puVar10 + 1) = uVar2;

        puVar10 = (u64 *)((int)puVar10 + 2);

      } while (0 < iVar9);

      uStack_8 = uStack_30;

    }

    else if (iVar9 == 1) {

      unaff_s1 = 0x77;

      unaff_s0 = 0x6c;

      unaff_s2_lo = 5;

      puVar11 = (u8 *)(&DAT_007cd998);

      puVar10 = &uStack_28;

      iVar9 = 4;

      do {

        uVar1 = *puVar11;

        uVar2 = puVar11[1];

        puVar11 = puVar11 + 2;

        iVar9 = iVar9 + -1;

        *(u8 *)puVar10 = uVar1;

        *(u8 *)((int)puVar10 + 1) = uVar2;

        puVar10 = (u64 *)((int)puVar10 + 2);

      } while (0 < iVar9);

      uStack_8 = uStack_28;

    }

    else if (iVar9 == 0) {

      unaff_s1 = 0xa8;

      unaff_s0 = 0x6c;

      unaff_s2_lo = 4;

      puVar11 = (u8 *)(&DAT_007cd990);

      puVar10 = &uStack_20;

      iVar9 = unaff_s2_lo;

      do {

        uVar1 = *puVar11;

        uVar2 = puVar11[1];

        puVar11 = puVar11 + 2;

        iVar9 = iVar9 + -1;

        *(u8 *)puVar10 = uVar1;

        *(u8 *)((int)puVar10 + 1) = uVar2;

        puVar10 = (u64 *)((int)puVar10 + 2);

      } while (0 < iVar9);

      uStack_8 = uStack_20;

    }

    uVar12 = 0x4008f0;

    break;

  case 6:

    unaff_s1 = 0xe6;

    unaff_s0 = 0x16d;

    unaff_s3 = 0x70;

    unaff_s2_lo = 3;

    puVar11 = (u8 *)(&DAT_007cd9c0);

    puVar10 = &uStack_50;

    iVar9 = 4;

    do {

      uVar1 = *puVar11;

      uVar2 = puVar11[1];

      puVar11 = puVar11 + 2;

      iVar9 = iVar9 + -1;

      *(u8 *)puVar10 = uVar1;

      *(u8 *)((int)puVar10 + 1) = uVar2;

      puVar10 = (u64 *)((int)puVar10 + 2);

    } while (0 < iVar9);

    uStack_8 = uStack_50;

    break;

  case 8:

    unaff_s1 = 0x28;

    unaff_s0 = 0x16d;

    datGetFlag(0x1204);

    datGetFlag(0x1206);

    unaff_s2_lo = 6;

    puVar11 = (u8 *)(&DAT_007cd9b0);

    puVar10 = &uStack_40;

    iVar9 = 4;

    do {

      uVar1 = *puVar11;

      uVar2 = puVar11[1];

      puVar11 = puVar11 + 2;

      iVar9 = iVar9 + -1;

      *(u8 *)puVar10 = uVar1;

      *(u8 *)((int)puVar10 + 1) = uVar2;

      puVar10 = (u64 *)((int)puVar10 + 2);

    } while (0 < iVar9);

    uStack_8 = uStack_40;

  }

  uVar7 = FUN_003c58f0(0,0xc,10,unaff_s3);

  iVar9 = (int)uVar7;

  piVar4 = *(int **)(*(int *)(iVar9 + 0x24) + 0x44);

  *piVar4 = iVar9;

  iVar5 = FUN_003c44d0(4,0,0,0);

  **(int **)(iVar5 + 0x24) = (int)param_1;

  piVar4[1] = iVar5;

  piVar4[2] = (int)param_1;

  for (iVar5 = 0; iVar5 < unaff_s2_lo; iVar5 = iVar5 + 1) {

    cVar3 = *(char *)((int)&uStack_8 + iVar5);

    uVar8 = FUN_003c5a40(uVar7,cVar3,8,0);

    *(int *)(*(int *)(*(int *)((int)uVar8 + 0x14) + 0x1c) + 4) = (int)cVar3;


  }

  FUN_003c6d60(uVar7,0x800);

  FUN_003c6d40(uVar7,unaff_s1,unaff_s0);

  FUN_003c6ee0(uVar7);

  FUN_003c5e20(uVar7,uVar12);

  FUN_003c5ee0(uVar7,0x400b90);

  *(u16 *)(*(int *)(iVar9 + 0x24) + 6) = 10;

  *(u16 *)(*(int *)(iVar9 + 0x24) + 8) = 10;

  return piVar4;

}

// FUN_004003A0


void FUN_004003a0(int param_1)



{

  if (param_1 != 0) {

    if (((u32 *)param_1)[1] != 0) {

      FUN_003c45f0(((u32 *)param_1)[1]);

    }

    FUN_003c5a20(*(u32 *)param_1);

  }

  return;

}

// FUN_004003F0 NONMATCHING


u32 FUN_004003f0(int *param_1)



{

  u32 *puVar1;

  u32 uVar2;

  u32 uVar3;

  u32 uVar4;

  u32 uVar5;

  int iVar6;

  long lVar7;

  

  iVar6 = *param_1;

  lVar7 = FUN_003c6270(iVar6);

  if (lVar7 == 2) {

    uVar5 = 0xffffffff;

  }

  else {

    puVar1 = *(u32 **)(iVar6 + 0xc);

    lVar7 = FUN_003c6c50(iVar6);

    if (lVar7 == 0) {

      lVar7 = FUN_003c6c80(iVar6);

      if (lVar7 == 0) {

        lVar7 = FUN_003c6ce0(iVar6);

        if ((lVar7 != 0) || (lVar7 = FUN_003c6d10(iVar6), lVar7 != 0)) {

          func_0010a4e0(0,0,0,0);

          uVar5 = *puVar1;

          uVar2 = ((u32 *)puVar1[5])[1];

          uVar3 = *(u32 *)puVar1[5];

          iVar6 = param_1[1];

          puVar1 = *(u32 **)(iVar6 + 0x24);

          iVar6 = FUN_003c4910(iVar6,*(u16 *)(iVar6 + 0x10) + 1,0x14);

          iVar6 = *(int *)(iVar6 + 0x14);

          *(short *)(iVar6 + 4) = (short)uVar3;

          *(short *)(iVar6 + 6) = (short)uVar2;

          *(short *)(iVar6 + 8) = (short)uVar5;

          *(u16 *)(iVar6 + 0xe) = 1;

          *(u32 *)(iVar6 + 0x10) = *puVar1;

          *(u16 *)(iVar6 + 0xc) = 7;

        }

        uVar5 = 0;

      }

      else {

        FUN_003c6ea0(iVar6);

        func_0010a4e0(0,0,0,2);

        FUN_003c6f10(iVar6);

        uVar5 = *puVar1;

        uVar2 = ((u32 *)puVar1[5])[1];

        uVar3 = *(u32 *)puVar1[5];

        iVar6 = param_1[1];

        puVar1 = *(u32 **)(iVar6 + 0x24);

        iVar6 = FUN_003c4910(iVar6,*(u16 *)(iVar6 + 0x10) + 1,0x14);

        iVar6 = *(int *)(iVar6 + 0x14);

        *(short *)(iVar6 + 4) = (short)uVar3;

        *(short *)(iVar6 + 6) = (short)uVar2;

        *(short *)(iVar6 + 8) = (short)uVar5;

        *(u16 *)(iVar6 + 0xe) = 0;

        *(u32 *)(iVar6 + 0x10) = *puVar1;

        *(u16 *)(iVar6 + 0xc) = 5;

        uVar5 = 4;

      }

    }

    else if ((**(u32 **)(((u32 *)lVar7)[5] + 0x1c) & 1) == 0) {

      FUN_003c6ea0(iVar6);

      func_0010a4e0(0,0,0,1);

      uVar5 = *(u32 *)lVar7;

      FUN_003c6f10(iVar6);

      uVar2 = *puVar1;

      uVar3 = ((u32 *)puVar1[5])[1];

      uVar4 = *(u32 *)puVar1[5];

      iVar6 = param_1[1];

      puVar1 = *(u32 **)(iVar6 + 0x24);

      iVar6 = FUN_003c4910(iVar6,*(u16 *)(iVar6 + 0x10) + 1,0x14);

      iVar6 = *(int *)(iVar6 + 0x14);

      *(short *)(iVar6 + 4) = (short)uVar4;

      *(short *)(iVar6 + 6) = (short)uVar3;

      *(short *)(iVar6 + 8) = (short)uVar2;

      *(u16 *)(iVar6 + 0xe) = 0;

      *(u32 *)(iVar6 + 0x10) = *puVar1;

      *(u16 *)(iVar6 + 0xc) = 5;

    }

    else {

      func_0010a4e0(0,0,0,8);

      uVar5 = 0;

    }

  }

  return uVar5;

}

// FUN_00400690


u64 FUN_00400690(u32 *param_1)



{

  FUN_003c6380(*param_1);

  return 0;

}

// FUN_004006C0 NONMATCHING


void FUN_004006c0(void)



{

  int iVar1;

  int iVar2;

  long lVar3;

  int in_a3_lo;

  int iVar4;

  

  iVar1 = *(int *)(*(int *)(*(int *)(in_a3_lo + 0x24) + 0x44) + 4);

  iVar2 = *(int *)(iVar1 + 4);

  while (iVar4 = iVar2, iVar4 != 0) {

    lVar3 = FUN_003ffa20(*(u16 *)(*(int *)(iVar4 + 0x14) + 4),

                         *(u16 *)(*(int *)(iVar4 + 0x14) + 6),0);

    iVar2 = *(int *)(iVar4 + 0x10);

    if (lVar3 != 0) {

      FUN_003c49e0(iVar1,iVar1 + 4,iVar4);

    }

  }

  return;

}

// FUN_00400740 NONMATCHING


void FUN_00400740(u64 param_1,u64 param_2,u8 param_3,int param_4)



{

  int iVar1;

  long lVar2;

  int iVar3;

  int iVar4;

  

  iVar1 = *(int *)(*(int *)(param_4 + 0x24) + 0x44);

  FUN_0040e3c0(0x3f800000,param_1,param_2,param_3,0x15,0);

  FUN_0040e3c0(0x3f800000,param_1,param_2,param_3,0x16,0);

  iVar4 = (int)param_1;

  FUN_0040e3c0(0x3f800000,iVar4 + 0x15d,param_2,param_3,0x15,0);

  FUN_0040e3c0(0x3f800000,iVar4 + 0x15d,param_2,param_3,0x16,0);

  FUN_0040e3c0(0x3f800000,iVar4 + 0x70,param_2,param_3,0x17,0);

  FUN_0040e3c0(0x3f800000,iVar4 + 0x70,param_2,param_3,0x18,0);

  FUN_0040e3c0(0x3f800000,iVar4 + 0xe0,param_2,param_3,0x17,0);

  FUN_0040e3c0(0x3f800000,iVar4 + 0xe0,param_2,param_3,0x18,0);

  iVar1 = *(int *)(iVar1 + 4);

  iVar4 = *(int *)(iVar1 + 4);

  while (iVar3 = iVar4, iVar3 != 0) {

    lVar2 = FUN_003ffa20(*(u16 *)(*(int *)(iVar3 + 0x14) + 4),

                         *(u16 *)(*(int *)(iVar3 + 0x14) + 6),0);

    iVar4 = *(int *)(iVar3 + 0x10);

    if (lVar2 != 0) {

      FUN_003c49e0(iVar1,iVar1 + 4,iVar3);

    }

  }

  return;

}

// FUN_004008F0 NONMATCHING


void FUN_004008f0(u64 param_1,u64 param_2,u8 param_3,int param_4)



{

  short sVar1;

  int iVar2;

  int iVar3;

  long lVar4;

  int iVar5;

  

  iVar2 = *(int *)(*(int *)(param_4 + 0x24) + 0x44);

  sVar1 = *(short *)(param_4 + 0x10);

  if (sVar1 == 6) {

    FUN_0040e3c0(0x3f800000,param_1,param_2,param_3,0x4f,0);

    FUN_0040e3c0(0x3f800000,param_1,param_2,param_3,0x50,0);

  }

  else if (sVar1 == 5) {

    FUN_0040e3c0(0x3f800000,param_1,param_2,param_3,0x51,0);

    FUN_0040e3c0(0x3f800000,param_1,param_2,param_3,0x52,0);

  }

  else if (sVar1 == 4) {

    FUN_0040e3c0(0x3f800000,param_1,param_2,param_3,0x53,0);

    FUN_0040e3c0(0x3f800000,param_1,param_2,param_3,0x54,0);

  }

  iVar2 = *(int *)(iVar2 + 4);

  iVar3 = *(int *)(iVar2 + 4);

  while (iVar5 = iVar3, iVar5 != 0) {

    lVar4 = FUN_003ffa20(*(u16 *)(*(int *)(iVar5 + 0x14) + 4),

                         *(u16 *)(*(int *)(iVar5 + 0x14) + 6),0);

    iVar3 = *(int *)(iVar5 + 0x10);

    if (lVar4 != 0) {

      FUN_003c49e0(iVar2,iVar2 + 4,iVar5);

    }

  }

  return;

}

// FUN_00400A90 NONMATCHING


void FUN_00400a90(int param_1,u64 param_2,int param_3,int param_4,u32 *param_5)



{

  u8 bVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = *(int *)(param_4 + 0x24);

  iVar3 = 0;

  bVar1 = param_5 == *(u32 **)(param_4 + 0xc);

  if (bVar1) {

    iVar3 = (int)((float)(*(short *)(iVar2 + 4) * 600) / (float)(int)*(short *)(iVar2 + 8));

    param_3 = 0xff;

  }

  if ((**(u32 **)(param_5[5] + 0x1c) & 1) != 0) {

    param_3 = (int)((float)param_3 * fGpffff8090);

  }

  FUN_003ff630(0x3f800000,param_1 + iVar3,param_2,0,param_3,

               *(u16 *)(*(int *)(iVar2 + 0x44) + 8),(short)*param_5 + -1,bVar1 | 2);

  return;

}

// FUN_00400B90 NONMATCHING


void FUN_00400b90(u64 param_1,u64 param_2,int param_3,u64 param_4,

                 u32 *param_5)



{

  long lVar1;

  int iVar2;

  

  lVar1 = FUN_003c6e10(param_4);

  iVar2 = (int)param_4;

  if (lVar1 == 1) {

    if ((**(u32 **)(param_5[5] + 0x1c) & 1) != 0) {

      param_3 = (int)((float)param_3 * fGpffff8090);

    }

    FUN_003ff630(0x3f800000,param_1,param_2,0,param_3,

                 *(u16 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x44) + 8),(short)*param_5 + -1,

                 param_5 == *(u32 **)(iVar2 + 0xc) | 2);

  }

  else if (lVar1 == 0x14) {


  }

  else if (lVar1 == 0xc) {

    if ((**(u32 **)(param_5[5] + 0x1c) & 1) != 0) {

      param_3 = (int)((float)param_3 * fGpffff8090);

    }

    FUN_003ff630(0x3f800000,param_1,param_2,0,param_3,

                 *(u16 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x44) + 8),(short)*param_5 + -1,

                 param_5 == *(u32 **)(iVar2 + 0xc) | 2);

  }

  return;

}

// FUN_00400D60 NONMATCHING


int FUN_00400d60(void)



{

  int iVar1;

  int iVar2;

  u64 uVar3;

  

  iVar2 = FUN_003c44d0(0x20,0,0,0);

  iVar1 = *(int *)(iVar2 + 0x24);

  *(int *)(iVar1 + 8) = iVar2;

  uVar3 = (u64)kwlnTaskCreate(0,(const char *)0x6af340,0x18b3,(KwlnTaskUpdateFunc)0x401210,0,(void *)iVar1);

  *(int *)(iVar1 + 0xc) = (int)uVar3;

  uVar3 = (u64)kwlnTaskCreate((KwlnTask *)uVar3,(const char *)0x6af360,0x18b5,(KwlnTaskUpdateFunc)0x4012c0,0,(void *)iVar1);

  kwlnTaskCreate((KwlnTask *)uVar3,(const char *)0x6af380,0x18b7,(KwlnTaskUpdateFunc)0x401370,0,(void *)iVar1);

  *(u32 *)(iVar1 + 0x18) = 0xffffffff;

  return iVar1;

}

// FUN_00400E30


void FUN_00400e30(int param_1)



{

  int iVar1;

  

  if ((param_1 != 0) && (iVar1 = param_1, *(int *)(iVar1 + 8) != 0)) {

    if (*(int *)(iVar1 + 0xc) != 0) {

      kwlnTaskDestroyWithHierarchy((KwlnTask *)*(u32 *)(iVar1 + 0xc));

    }

    FUN_003c45f0(*(u32 *)(iVar1 + 8));

  }

  return;

}

// FUN_00400E90 NONMATCHING


void FUN_00400e90(u64 param_1)



{

  u32 *puVar1;

  u32 uVar2;

  u8 bVar3;

  u8 bVar4;

  int iVar5;

  long lVar6;

  u32 uVar7;

  u32 *puVar8;

  u32 *puVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  int *piVar13;

  

  puVar8 = (u32 *)param_1;

  uVar7 = puVar8[2];

  if ((*puVar8 & 1) != 0) {

    if ((*puVar8 & 2) != 0) {

      piVar13 = (int *)(*(int *)puVar8[4] + puVar8[5] * 8);

      iVar12 = *piVar13;

      iVar10 = 0;

      for (iVar11 = 0; iVar5 = piVar13[1], iVar11 < iVar5; iVar11 = iVar11 + 1) {

        puVar9 = (u32 *)(iVar12 + iVar11 * 8);

        if (puVar8[1] == *puVar9) {

          iVar5 = FUN_003c4b50(uVar7,uVar7 + 4,(short)puVar9[1] + 1);

          puVar1 = *(u32 **)(iVar5 + 0x14);

          uVar2 = *puVar1;

          if ((uVar2 & 1) == 0) {

            *puVar1 = uVar2 | 1;

            *puVar1 = uVar2 | 3;

          }

          else if (*(short *)((int)puVar9 + 6) == 2) {

            *puVar1 = uVar2 & 0xfffffffe;

            *puVar1 = uVar2 & 0xfffffffc;

          }

          if (*(int *)puVar1[2] == 0) {

            K_Assert((const char *)(u32)0x6aede8,0x192a);

          }

          (**(code **)puVar1[2])(param_1,puVar1,puVar9);

        }

        if ((int)*puVar9 <= (int)puVar8[1]) {

          iVar10 = iVar10 + 1;

        }

      }

      if (iVar10 == iVar5) {

        *puVar8 = *puVar8 & 0xfffffffd;

      }

    }

    bVar3 = 0;

    for (iVar12 = *(int *)(uVar7 + 4); iVar12 != 0; iVar12 = *(int *)(iVar12 + 0x10)) {

      puVar9 = *(u32 **)(iVar12 + 0x14);

      bVar4 = bVar3;

      if ((*puVar9 & 1) != 0) {

        lVar6 = (**(code **)puVar9[2])(param_1,puVar9,0);

        if (lVar6 == 2) {

          *puVar9 = *puVar9 & 0xfffffffe;

        }

        else if (lVar6 == 1) {

          *puVar9 = *puVar9 & 0xfffffffd;

        }

        else {

          bVar4 = 1;

          if (lVar6 != 0) {

            bVar4 = bVar3;

          }

        }

      }

      bVar3 = bVar4;

      uVar7 = puVar9[1];

      puVar9[1] = uVar7 + 1;

      if (0xffffffe < (int)(uVar7 + 1)) {

        puVar9[1] = 0xfffffff;

      }

    }

    uVar7 = puVar8[1];

    puVar8[1] = uVar7 + 1;

    if (0xffffffe < (int)(uVar7 + 1)) {

      puVar8[1] = 0xfffffff;

    }

    if (((*puVar8 & 4) != 0) && (!bVar3)) {

      uVar7 = *puVar8 & 0xfffffffb;

      *puVar8 = uVar7;

      *puVar8 = uVar7 | 2;

      puVar8[5] = puVar8[6];

      puVar8[1] = 0;

    }

  }

  return;

}

// FUN_00401170 NONMATCHING


void FUN_00401170(u64 param_1)



{

  code *pcVar1;

  u32 uVar2;

  int iVar3;

  

  uVar2 = *(u32 *)param_1 & 1;

  if ((uVar2 != 0) && (uVar2 != 0)) {

    for (iVar3 = *(int *)(((u32 *)param_1)[2] + 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x10)) {

      uVar2 = (*(u32 **)(iVar3 + 0x14))[2];

      if (((*(int *)(uVar2 + 0x14) == 3) && ((**(u32 **)(iVar3 + 0x14) & 1) != 0)) &&

         (pcVar1 = *(code **)(uVar2 + 4), pcVar1 != (code *)0x0)) {

        (*pcVar1)(param_1);

      }

    }

  }

  return;

}

// FUN_00401210 NONMATCHING


u32 FUN_00401210(int param_1)



{

  u32 *puVar1;
  u32 *puVar2;
  u32 uVar2;
  u32 uVar4;
  u32 uVar3;
  u32 *puVar4;
  code pcVar3;

  int iVar4;

  

  puVar1 = *(u32 **)(param_1 + 0x3c);
  uVar4 = *puVar1;
  uVar3 = uVar4 & 1;

  if (uVar3 == 0) {
    return 0;
  }

  puVar4 = (u32 *)puVar1[2];
  if (uVar3 != 0) {
    for (iVar4 = *(int *)(puVar4 + 1); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {
      puVar2 = *(u32 **)(iVar4 + 0x14);
      uVar2 = puVar2[2];
      if (((*(int *)(uVar2 + 0x14) == 0) && ((*puVar2 & 1) != 0)) &&
         (pcVar3 = *(code *)(uVar2 + 4), pcVar3 != (code)0)) {
        (*pcVar3)(puVar1);
      }
    }
  }

  return 0;

}

// FUN_004012C0 NONMATCHING


u64 FUN_004012c0(int param_1)



{

  u32 *puVar1;

  u32 uVar2;

  code *pcVar3;

  int iVar4;

  

  puVar1 = *(u32 **)(param_1 + 0x3c);

  if (((*puVar1 & 1) != 0) && ((*puVar1 & 1) != 0)) {

    for (iVar4 = *(int *)(puVar1[2] + 4); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {

      uVar2 = (*(u32 **)(iVar4 + 0x14))[2];

      if (((*(int *)(uVar2 + 0x14) == 2) && ((**(u32 **)(iVar4 + 0x14) & 1) != 0)) &&

         (pcVar3 = *(code **)(uVar2 + 4), pcVar3 != (code *)0x0)) {

        (*pcVar3)(puVar1);

      }

    }

  }

  return 0;

}

// FUN_00401370 NONMATCHING


u64 FUN_00401370(int param_1)



{

  u32 *puVar1;

  u32 uVar2;

  code *pcVar3;

  int iVar4;

  

  puVar1 = *(u32 **)(param_1 + 0x3c);

  if (((*puVar1 & 1) != 0) && ((*puVar1 & 1) != 0)) {

    for (iVar4 = *(int *)(puVar1[2] + 4); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {

      uVar2 = (*(u32 **)(iVar4 + 0x14))[2];

      if (((*(int *)(uVar2 + 0x14) == 4) && ((**(u32 **)(iVar4 + 0x14) & 1) != 0)) &&

         (pcVar3 = *(code **)(uVar2 + 4), pcVar3 != (code *)0x0)) {

        (*pcVar3)(puVar1);

      }

    }

  }

  return 0;

}

// FUN_00401420


void FUN_00401420(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  *(int *)(param_1 + 0x10) = param_2;

  iVar1 = *(int *)(param_1 + 8);

  for (iVar4 = 0; iVar4 < *(int *)(param_2 + 0xc); iVar4 = iVar4 + 1) {

    iVar3 = iVar4 * 0x1c;

    iVar2 = FUN_003c4910(iVar1,*(u16 *)(iVar1 + 0x10) + 1,

                         *(int *)(*(int *)(param_2 + 8) + iVar3 + 8) + 0x10);

    iVar2 = *(int *)(iVar2 + 0x14);

    *(int *)(iVar2 + 8) = *(int *)(param_2 + 8) + iVar3;

    if (*(int *)(*(int *)(param_2 + 8) + iVar3 + 8) != 0) {

      *(int *)(iVar2 + 0xc) = iVar2 + 0x10;

    }

  }

  return;

}

// FUN_004014E0 NONMATCHING


u32 FUN_004014e0(u64 param_1)



{

  u32 *puVar1;

  u32 uVar2;

  long lVar3;

  u32 *puVar4;

  int iVar5;

  

  puVar4 = (u32 *)param_1;

  iVar5 = *(int *)(puVar4[2] + 4);

  do {

    if (iVar5 == 0) {

      uVar2 = *puVar4;

      *puVar4 = uVar2 & 0xfffffffe;

      *puVar4 = uVar2 & 0xfffffffe | 2;

      return 1;

    }

    puVar1 = *(u32 **)(iVar5 + 0x14);

    if ((*(code **)(puVar1[2] + 0x10) != (code *)0x0) && ((*puVar1 & 4) == 0)) {

      lVar3 = (**(code **)(puVar1[2] + 0x10))(param_1,puVar1);

      if (lVar3 == 0) {

        return 0;

      }

      *puVar1 = *puVar1 | 4;

    }

    iVar5 = *(int *)(iVar5 + 0x10);

  } while( 1 );

}

// FUN_004015A0


void FUN_004015a0(u32 *param_1,u32 param_2)



{

  if (param_1[6] != param_2) {

    if ((*param_1 & 1) != 0) {

      *param_1 = *param_1 | 4;

    }

    *param_1 = *param_1 | 1;

    param_1[6] = param_2;

  }

  return;

}

// FUN_004015E0


u8 FUN_004015e0(u32 *param_1)



{

  return (*param_1 & 2) != 0;

}

// FUN_00401600


int FUN_00401600(u64 param_1,u64 param_2,int param_3)
{
  switch (param_3) {
  case 1:
  case 3:
    H_Maestro_00111c50_i(param_2);
    H_Maestro_RequestDraw_i(param_2);
    break;
  case 0x24:
    H_Maestro_SetAlphaMult_f32(0.0f,param_2);
    H_Maestro_00111c50_i(param_2);
    break;
  case 2:
  case 0x23:
    H_Maestro_00111c50_i(param_2);
    break;
  }
  return param_3;
}

// FUN_004016D0 NONMATCHING


u32 FUN_004016d0(u64 param_1)



{

  long lVar1;

  long lVar2;

  u32 uVar3;

  

  lVar1 = FUN_00173a00(param_1,0);

  uVar3 = 1;

  lVar2 = FUN_00173a00(param_1,1);

  if (lVar1 <= lVar2) {

    if (lVar1 == lVar2) {

      uVar3 = 3;

      lVar1 = lVar2;

    }

    else {

      uVar3 = 2;

      lVar1 = lVar2;

    }

  }

  lVar2 = FUN_00173a00(param_1,2);

  if (lVar1 < lVar2) {

    if (lVar1 == lVar2) {

      uVar3 = uVar3 | 4;

      lVar1 = lVar2;

    }

    else {

      uVar3 = 4;

      lVar1 = lVar2;

    }

  }

  lVar2 = FUN_00173a00(param_1,3);

  if (lVar1 < lVar2) {

    if (lVar1 == lVar2) {

      uVar3 = uVar3 | 8;

      lVar1 = lVar2;

    }

    else {

      uVar3 = 8;

      lVar1 = lVar2;

    }

  }

  lVar2 = FUN_00173a00(param_1,4);

  if (lVar1 < lVar2) {

    if (lVar1 == lVar2) {

      uVar3 = uVar3 | 0x10;

    }

    else {

      uVar3 = 0x10;

    }

  }

  return uVar3;

}

// FUN_00401800


int FUN_00401800(short param_1)



{

  s16 uVar1;

  s16 uVar2;

  s16 *puVar6;
  short *psVar5;
  int iVar3;
  u32 uVar3;
  u32 uVar4;

  short asStack_30 [24];

  
  puVar6 = (s16 *)(DAT_006af3a0_abs);
  psVar5 = asStack_30;
  iVar3 = 0xc;
  do {

    uVar1 = *puVar6;

    uVar2 = puVar6[1];

    puVar6 = puVar6 + 2;

    iVar3 = iVar3 + -1;

    *psVar5 = uVar1;

    psVar5[1] = uVar2;

    psVar5 = psVar5 + 2;

  } while (0 < iVar3);

  uVar4 = 0;
  uVar3 = (u16)param_1;
  goto check;
body:
  if (uVar3 == (u16)asStack_30[uVar4]) {
    return uVar4 + 0x1280;
  }
  uVar4 = uVar4 + 1;
check:
  if (uVar4 < 0x18) {
    goto body;
  }
  return 0;

}

// FUN_00401890 NONMATCHING


u32 FUN_00401890(short param_1)



{

  short sVar1;

  short sVar2;

  u32 uVar3;

  long lVar4;

  int iVar5;

  u32 uVar6;

  short *psVar7;

  short *psVar8;

  short asStack_30 [24];

  

  psVar8 = (s16 *)(&DAT_006af3a0);

  psVar7 = asStack_30;

  iVar5 = 0xc;

  do {

    sVar1 = *psVar8;

    sVar2 = psVar8[1];

    psVar8 = psVar8 + 2;

    iVar5 = iVar5 + -1;

    *psVar7 = sVar1;

    psVar7[1] = sVar2;

    psVar7 = psVar7 + 2;

  } while (0 < iVar5);

  uVar6 = 0;

  do {

    if (0x17 < uVar6) {

      iVar5 = 0;

LAB_00401910:

      if ((iVar5 == 0) || (lVar4 = datGetFlag(), lVar4 != 0)) {

        uVar3 = 0;

      }

      else {

        uVar3 = 1;

      }

      return uVar3;

    }

    if (param_1 == asStack_30[uVar6]) {

      iVar5 = uVar6 + 0x1280;

      goto LAB_00401910;

    }

    uVar6 = uVar6 + 1;

  } while( 1 );

}

// FUN_00401950 NONMATCHING


u64 FUN_00401950(short param_1)



{

  short sVar1;

  short sVar2;

  int iVar3;

  u32 uVar4;

  short *psVar5;

  short *psVar6;

  short asStack_30 [24];

  

  psVar6 = (s16 *)(&DAT_006af3a0);

  psVar5 = asStack_30;

  iVar3 = 0xc;

  do {

    sVar1 = *psVar6;

    sVar2 = psVar6[1];

    psVar6 = psVar6 + 2;

    iVar3 = iVar3 + -1;

    *psVar5 = sVar1;

    psVar5[1] = sVar2;

    psVar5 = psVar5 + 2;

  } while (0 < iVar3);

  uVar4 = 0;

  do {

    if (0x17 < uVar4) {

      iVar3 = 0;

LAB_004019d0:

      if (iVar3 != 0) {

        datSetFlag(iVar3,1);

      }

      return 0;

    }

    if (param_1 == asStack_30[uVar4]) {

      iVar3 = uVar4 + 0x1280;

      goto LAB_004019d0;

    }

    uVar4 = uVar4 + 1;

  } while( 1 );

}

// FUN_00401A00 NONMATCHING






u32 FUN_00401a00(u16 param_1,long param_2,short *param_3)



{

  u16 uVar1;

  u8 bVar2;

  short sVar3;

  u32 uVar4;

  u32 uVar5;

  u32 uVar6;

  short *psVar7;

  int iVar8;

  u16 *puVar9;

  u16 *puVar10;

  u32 uVar11;

  u32 *puVar12;

  u32 uStack_30;

  u32 uStack_2c;

  u32 uStack_28;

  u32 uStack_24;

  u16 auStack_20 [15];

  short sStack_2;

  

  if (param_3 == (short *)0x0) {

    param_3 = &sStack_2;

  }

  if (param_2 == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x1aa8);

  }

  for (iVar8 = 0; iVar8 < iGpffffabfc; iVar8 = iVar8 + 1) {

    psVar7 = (short *)(iGpffffabf8 + iVar8 * 4);

    if (*(short *)((int)param_2 + 2) == *psVar7) {

      sVar3 = psVar7[1];

      goto LAB_00401aa4;

    }

  }

  sVar3 = 0;

LAB_00401aa4:

  *param_3 = sVar3;

  if (sVar3 == 0) {

    uVar11 = 0;

    uStack_30 = _DAT_006af180;

    uStack_2c = _DAT_006af184;

    uStack_28 = DAT_006af188;

    uStack_24 = DAT_006af18c;

    puVar10 = (u16 *)&uStack_30;

    puVar9 = auStack_20;

    iVar8 = 4;

    while( 1 ) {

      do {

        uVar1 = puVar10[1];

        iVar8 = iVar8 + -1;

        *puVar9 = *puVar10;

        puVar9[1] = uVar1;

        puVar10 = puVar10 + 2;

        puVar9 = puVar9 + 2;

      } while (0 < iVar8);

      if (uVar11 < 8) {

        uVar6 = (u32)auStack_20[uVar11];

      }

      else {

        uVar6 = 0;

      }

      if (uVar6 == 0) {

        bVar2 = 0;

        goto LAB_00401b60;

      }

      if (param_1 == uVar6) break;

      uVar11 = uVar11 + 1;

      puVar10 = (u16 *)&uStack_30;

      puVar9 = auStack_20;

      iVar8 = 4;

    }

    bVar2 = 1;

LAB_00401b60:

    if (!bVar2) {

      psVar7 = psGpffffabd0;

      for (uVar11 = 0; uVar11 < uGpffffabd4; uVar11 = uVar11 + 1) {

        if ((long)*psVar7 == (u32)param_1) {

          param_1 = psVar7[1];

          goto LAB_00401bc4;

        }

        psVar7 = psVar7 + 2;

      }

      param_1 = 0;

    }

LAB_00401bc4:

    puVar12 = puGpffffabe0;

    for (uVar11 = 0; uVar11 < uGpffffabe4; uVar11 = uVar11 + 1) {

      if ((u32)(u16)puVar12[1] == (long)(short)param_1) {

        if (puVar12 == (u32 *)0x0) {

          K_Assert((const char *)(u32)0x6aede8,0x1a47);

        }


        if ((*puVar12 & uVar5) != 0) goto LAB_00401c48;

      }

      puVar12 = puVar12 + 4;

    }

    puVar12 = (u32 *)0x0;

LAB_00401c48:

    if (puVar12 == (u32 *)0x0) {

      uVar4 = 0;

    }

    else {

      *param_3 = *(short *)((int)puVar12 + 6);

      uVar4 = 1;

    }

  }

  else {

    uVar4 = 2;

  }

  return uVar4;

}

// FUN_00401C90


u8 * FUN_00401c90(u32 *param_1,int param_2)



{

  u8 bVar1;
  u8 *pbVar2;

  u32 uVar3;

  u32 uVar4;

  

  pbVar2 = (u8 *)*param_1;

  uVar3 = 0;

  uVar4 = param_1[1];

  while (uVar3 < uVar4) {

    bVar1 = *(u8 *)(param_2 + 4);

    if (*pbVar2 > bVar1) goto advance;
    if (pbVar2[1] < bVar1) goto advance;

    return pbVar2;

advance:

    pbVar2 = pbVar2 + 6;

    uVar3 = uVar3 + 1;

  }

  return (u8 *)0x0;

}

// FUN_00401CF0 NONMATCHING


u8 * FUN_00401cf0(long param_1)



{

  u8 bVar1;

  u8 *pbVar2;

  u32 uVar3;

  

  if (param_1 == 0) {

    K_Assert((const char *)(u32)DAT_006aede8,0x1ada);

  }

  pbVar2 = pbGpffffabe8;
  uVar3 = 0;

  while( 1 ) {

    if (uGpffffabec <= uVar3) {

      return (u8 *)0x0;

    }

    bVar1 = *(u8 *)((int)param_1 + 4);

    if ((*pbVar2 <= bVar1) && (bVar1 <= pbVar2[1])) break;

    pbVar2 = pbVar2 + 0x2e;

    uVar3 = uVar3 + 1;

  }

  return pbVar2;

}

// FUN_00401D90 NONMATCHING


short * FUN_00401d90(int param_1)



{

  u32 uVar2;
  u16 *psVar1;

  u32 uVar3;

  

  uVar2 = 0;

  psVar1 = (u16 *)psGpffffabf0;

  uVar3 = uGpffffabf4;

  while (uVar2 < uVar3) {

    if (*psVar1 == *(u16 *)(param_1 + 2)) {

      return (short *)psVar1;

    }

    psVar1 = psVar1 + 3;

    uVar2 = uVar2 + 1;

  }

  return (short *)0x0;

}

// FUN_00401DE0 NONMATCHING






u32 FUN_00401de0(u64 param_1,long param_2,long param_3)



{

  u16 uVar1;

  u16 uVar2;

  u8 bVar3;

  short sVar4;

  u8 uVar5;

  short sVar6;

  u32 uVar7;

  int iVar8;

  long lVar9;

  u16 *puVar10;

  u32 uVar11;

  u16 uVar12;

  short *psVar13;

  u16 *puVar14;

  u16 *puVar15;

  u32 uVar16;

  u32 *puVar17;

  int iVar18;

  u32 unaff_s5_lo;

  u32 uStack_30;

  u32 uStack_2c;

  u32 uStack_28;

  u32 uStack_24;

  u16 auStack_20 [14];

  int iStack_4;

  

  if (param_2 == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x1b5d);

  }

  if (param_3 == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x1b5e);

  }

  memset(param_1,0,0x1c);

  iVar18 = (int)param_3;

  uVar2 = *(u16 *)(iVar18 + 2);

  for (iVar8 = 0; iVar8 < iGpffffabfc; iVar8 = iVar8 + 1) {

    puVar10 = (u16 *)(iGpffffabf8 + iVar8 * 4);

    if (uVar2 == *puVar10) {

      uVar12 = puVar10[1];

      goto LAB_00401ea8;

    }

  }

  uVar12 = 0;

LAB_00401ea8:

  puVar10 = (u16 *)param_1;

  if (uVar12 == 0) {

    uVar12 = *(u16 *)param_2;

    uVar16 = 0;

    uStack_30 = _DAT_006af180;

    uStack_2c = _DAT_006af184;

    uStack_28 = DAT_006af188;

    uStack_24 = DAT_006af18c;

    puVar15 = (u16 *)&uStack_30;

    puVar14 = auStack_20;

    iVar8 = 4;

    while( 1 ) {

      do {

        uVar1 = puVar15[1];

        iVar8 = iVar8 + -1;

        *puVar14 = *puVar15;

        puVar14[1] = uVar1;

        puVar15 = puVar15 + 2;

        puVar14 = puVar14 + 2;

      } while (0 < iVar8);

      if (uVar16 < 8) {

        uVar11 = (u32)auStack_20[uVar16];

      }

      else {

        uVar11 = 0;

      }

      if (uVar11 == 0) {

        bVar3 = 0;

        goto LAB_00401fa8;

      }

      if (uVar12 == uVar11) break;

      uVar16 = uVar16 + 1;

      puVar15 = (u16 *)&uStack_30;

      puVar14 = auStack_20;

      iVar8 = 4;

    }

    bVar3 = 1;

LAB_00401fa8:

    if (bVar3) {

      if (*(char *)((u32)uVar2 * 0xe + iGpffffb730 + 2) == '\x01') {

        bVar3 = 1;

      }

      else {

        bVar3 = 0;

      }

    }

    else {

      psVar13 = psGpffffabd0;

      for (uVar16 = 0; uVar16 < uGpffffabd4; uVar16 = uVar16 + 1) {

        if ((long)*psVar13 == (u32)uVar12) {

          uVar12 = psVar13[1];

          goto LAB_0040203c;

        }

        psVar13 = psVar13 + 2;

      }

      uVar12 = 0;

LAB_0040203c:

      if (*(char *)((u32)uVar2 * 0xe + iGpffffb730 + 2) == '\x01') {

        bVar3 = 1;

      }

      else {

        bVar3 = 0;

      }

    }

    puVar17 = puGpffffabe0;

    for (uVar16 = 0; uVar16 < uGpffffabe4; uVar16 = uVar16 + 1) {

      if ((u32)(u16)puVar17[1] == (long)(short)uVar12) {

        if (puVar17 == (u32 *)0x0) {

          K_Assert((const char *)(u32)0x6aede8,0x1a47);

        }


        if ((*puVar17 & uVar7) != 0) goto LAB_00402100;

      }

      puVar17 = puVar17 + 4;

    }

    puVar17 = (u32 *)0x0;

LAB_00402100:

    if (puVar17 == (u32 *)0x0) {

      return 0;

    }

    if (puVar17 == (u32 *)0x0) {

      K_Assert((const char *)(u32)0x6aede8,0x1b37);

    }

    uVar2 = *(u16 *)((int)puVar17 + 6);

    iVar8 = func_00170d60(uVar2);

    puVar10[2] = uVar2;

    *(u32 *)(puVar10 + 4) = *(u32 *)(iVar8 + 4);


    func_00170d60(puVar10[2]);


    if (lVar9 == 0) {

      K_Assert((const char *)(u32)0x6aede8,0x1afa);

    }

    puVar10[7] = *(u16 *)((int)lVar9 + 2);

    puVar10[8] = *(u16 *)((int)lVar9 + 4);


    if (lVar9 == 0) {

      K_Assert((const char *)(u32)0x6aede8,0x1b05);

    }

    *(char *)((int)puVar10 + 0xd) =

         (char)*(u16 *)

                ((int)lVar9 +

                (u32)*(u8 *)((u32)*(u16 *)(iVar18 + 2) * 0xe + iGpffffb730 + 2) * 2);

    if (bVar3) {


      if (lVar9 == 0) {

        K_Assert((const char *)(u32)0x6aede8,0x1b51);

      }

      if (puVar10 == (u16 *)0xfffffffc) {

        K_Assert((const char *)(u32)0x6aede8,0x1b52);

      }

      iVar8 = (int)lVar9;

      puVar10[7] = (u16)*(u8 *)(iVar8 + 2);

      puVar10[8] = (u16)*(u8 *)(iVar8 + 3);

      *(u8 *)((int)puVar10 + 0xd) = *(u8 *)(iVar8 + 4);

    }

  }

  else {

    *puVar10 = *puVar10 | 2;

    if (puVar10 == (u16 *)0xfffffffc) {

      K_Assert((const char *)(u32)0x6aede8,0x1b2f);

    }

    func_001828d0(uVar12,puVar10 + 2);

  }

  sVar6 = datGetDaysSinceApr5();

  if ((*puVar10 & 2) == 0) {

    sVar4 = 1;

  }

  else {

    sVar4 = 2;

  }

  uVar5 = clndGetMonthFromDaysSinceApr5(sVar6 + sVar4);

  *(u8 *)(puVar10 + 1) = uVar5;

  uVar5 = clndGetDayOfMonthFromDaysSinceApr5(sVar6 + sVar4);

  *(u8 *)((int)puVar10 + 3) = uVar5;

  *puVar10 = *puVar10 | 1;


  if ((lVar9 == 0) || (lVar9 = datGetFlag(lVar9), lVar9 != 0)) {

    bVar3 = 0;

  }

  else {

    bVar3 = 1;

  }

  if (bVar3) {

    iVar8 = func_00170ed0(puVar10[2],&iStack_4);

    if (iStack_4 == 4) {

      unaff_s5_lo = *(u32 *)(iVar8 + 0x18);

    }

    else if (iStack_4 == 3) {

      unaff_s5_lo = *(u32 *)(iVar8 + 0x20);

    }

    else if (iStack_4 == 2) {

      unaff_s5_lo = *(u32 *)(iVar8 + 0x1c);

    }

    else if (iStack_4 == 1) {

      unaff_s5_lo = *(u32 *)(iVar8 + 0x1c);

    }

    else if (iStack_4 == 0) {

      unaff_s5_lo = *(u32 *)(iVar8 + 0x24);

    }

    *(u32 *)(puVar10 + 0xc) = unaff_s5_lo;

  }

  else {

    *(u32 *)(puVar10 + 0xc) = *(u8 *)(iVar18 + 4) / 5 + 1;

  }

  return 1;

}

// FUN_00402400


void FUN_00402400(int param_1,u16 *param_2)



{

  u32 uVar1;

  

  *param_2 = *(u16 *)(param_1 + 4);

  param_2[5] = 1;

  *(u8 *)((int)param_2 + 9) = *(u8 *)(param_1 + 0xd);

  *(u8 *)(param_2 + 4) = *(u8 *)(param_1 + 0xc);

  uVar1 = FUN_003f1a10(*(u32 *)(param_1 + 8));

  *(u32 *)(param_2 + 2) = uVar1;

  *(u32 *)(param_2 + 6) = 1;

  param_2[8] = *(u16 *)(param_1 + 0xe);

  param_2[9] = *(u16 *)(param_1 + 0x10);

  return;

}

// FUN_00402480


u32 FUN_00402480(u16 *param_1)



{

  u32 uVar1;

  int iVar2;

  u16 auStack_20 [16];

  

  if (param_1 == (u16 *)0x0) {

    param_1 = auStack_20;

  }

  FUN_0017c220(param_1);

  if ((*(short *)param_1 & 1) == 0) {

    uVar1 = 0;

  }

  else {

    iVar2 = clndIsDateInRangeFromStart((char)param_1[1],*(s8 *)((int)param_1 + 3),0x16d);

    if (iVar2 != 0) {

      uVar1 = 1;

    }

    else {

      uVar1 = 0xffffffff;

    }

  }

  return uVar1;

}

// FUN_00402510 NONMATCHING


u32 FUN_00402510(u32 param_1,long param_2,u32 param_3,short param_4)



{

  short sVar1;

  u32 uVar2;

  u32 uVar3;

  

  if (param_2 == -1) {

    param_2 = func_00171250((short)param_1);

  }

  uVar2 = datGetEquipmentId(1,param_4);

  if ((param_1 & 0xffff) == (uVar2 & 0xffff)) {

    if (((param_3 & 8) == 0) && (sVar1 = datGetEquipmentIdx(1,(short)param_2), param_4 == sVar1)) {

      uVar3 = 0;

    }

    else if (((param_3 & 2) == 0) &&

            (uVar2 = func_0016f810(1,param_4), ((int)param_1 >> 0x18 & 0xfU) != (uVar2 & 0xff))) {

      uVar3 = 0;

    }

    else if (((param_3 & 4) == 0) &&

            (uVar2 = datGetEquipmentEffect(1,param_4), ((int)param_1 >> 0x10 & 0xffU) != (uVar2 & 0xff))) {

      uVar3 = 0;

    }

    else if (((param_3 & 1) == 0) ||

            (uVar2 = func_0016f810(1,param_4), (uVar2 & 0xff) <= ((int)param_1 >> 0x18 & 0xfU))) {

      uVar3 = 1;

    }

    else {

      uVar3 = 0;

    }

  }

  else {

    uVar3 = 0;

  }

  return uVar3;

}

// FUN_004026B0 NONMATCHING


u32 FUN_004026b0(int param_1,int param_2,u32 param_3)



{

  int iVar1;

  u32 uVar2;

  long lVar3;

  u8 auStack_20 [9];

  u8 uStack_17;

  

  lVar3 = func_00171250((short)param_1);

  if (lVar3 != 4) {

    iVar1 = func_0016f490(1);

    if (300 - iVar1 < param_2) {

      return 0;

    }

    for (iVar1 = 0; iVar1 < param_2; iVar1 = iVar1 + 1) {

      uVar2 = param_1 >> 0x18 & 0xf;

      if ((param_3 & 2) != 0) {

        uVar2 = 2;

      }

      if ((uVar2 != 0) && ((param_3 & 1) != 0)) {

        RpRandom();

      }

      func_001828d0((short)param_1,auStack_20);

      if ((param_3 & 4) == 0) {

        uStack_17 = (char)((u32)param_1 >> 0x10);

      }

      func_001830c0(auStack_20);

    }

  }

  return 1;

}

// FUN_00402800 NONMATCHING


void FUN_00402800(u64 param_1)



{

  char cVar1;

  u16 uVar2;

  int iVar3;

  int iVar4;

  u64 uVar5;

  u64 uVar6;

  long lVar7;

  u8 auStack_20 [32];

  

  uVar5 = FUN_003c7d60(8);



  cVar1 = *(char *)(iVar3 + 10);

  if (cVar1 == '\x04') {

    sprintf((char *)auStack_20,0x6af3d0);

  }

  else if (cVar1 == '\x03') {

    sprintf((char *)auStack_20,&gp0xffffac10,*(u32 *)(iVar3 + 0xc));

  }

  else if (cVar1 == '\x02') {

    sprintf((char *)auStack_20,&gp0xfffface0,iGpffffb7f4 + *(short *)(iVar3 + 0xc) * 0x11);

  }

  else if (cVar1 == '\x01') {

    sprintf((char *)auStack_20,&gp0xfffface0,

                 iGpffffb7f8 + *(short *)(iVar3 + 0xc) * 0x12 + (int)*(short *)(iVar3 + 0xc));

  }

  else if (cVar1 == '\0') {

    uVar6 = func_00171110(*(u16 *)(iVar3 + 0xc),((long)*(char *)(iVar3 + 0xe) << 0x3c) >> 0x3c

                        );

    sprintf((char *)auStack_20,&gp0xfffface0,uVar6);

  }

  FUN_003a4220(uVar5,0,auStack_20);

  if (*(char *)(iVar3 + 10) == '\0') {

    FUN_003a4010(uVar5,2,*(u16 *)(iVar3 + 0xc),0x11);

    if ((*(u16 *)(iVar3 + 8) & 2) == 0) {

      lVar7 = ((long)*(char *)(iVar3 + 0xe) << 0x3c) >> 0x3c;

    }

    else {

      lVar7 = 2;

    }

    FUN_003a4010(uVar5,3,lVar7,0x11);

  }

  sprintf((char *)auStack_20,&gp0xffffac10,*(u8 *)(iVar3 + 0xb));

  FUN_003a4220(uVar5,1,auStack_20);

  cVar1 = *(char *)(iVar4 + 6);

  if (cVar1 == '\x04') {

    sprintf((char *)auStack_20,0x6af3d0);

  }

  else if (cVar1 == '\x03') {

    sprintf((char *)auStack_20,&gp0xffffac10,*(u32 *)(iVar4 + 8));

  }

  else if (cVar1 == '\x02') {

    sprintf((char *)auStack_20,&gp0xfffface0,iGpffffb7f4 + *(short *)(iVar4 + 8) * 0x11);

  }

  else if (cVar1 == '\x01') {

    sprintf((char *)auStack_20,&gp0xfffface0,

                 iGpffffb7f8 + *(short *)(iVar4 + 8) * 0x12 + (int)*(short *)(iVar4 + 8));

  }

  else if (cVar1 == '\0') {

    uVar6 = func_00171110(*(u16 *)(iVar4 + 8),((long)*(char *)(iVar4 + 10) << 0x3c) >> 0x3c);

    sprintf((char *)auStack_20,&gp0xfffface0,uVar6);

  }

  FUN_003a4220(uVar5,5,auStack_20);

  if (*(char *)(iVar4 + 6) == '\0') {

    FUN_003a4010(uVar5,7,*(u16 *)(iVar4 + 8),0x11);

    FUN_003a4010(uVar5,8,((long)*(char *)(iVar4 + 10) << 0x3c) >> 0x3c,0x11);

  }

  sprintf((char *)auStack_20,&gp0xffffac10,*(u8 *)(iVar4 + 7));

  FUN_003a4220(uVar5,6,auStack_20);


  sprintf((char *)auStack_20,&gp0xffffac10,uVar6);

  FUN_003a4220(uVar5,9,auStack_20);


  sprintf((char *)auStack_20,&gp0xffffac10,uVar2);

  FUN_003a4220(uVar5,10,auStack_20);


  sprintf((char *)auStack_20,&gp0xffffac10,uVar2);

  FUN_003a4220(uVar5,0xb,auStack_20);


  sprintf((char *)auStack_20,&gp0xffffac10,uVar2);

  FUN_003a4220(uVar5,0xc,auStack_20);

  return;

}

// FUN_00402C80 NONMATCHING


void FUN_00402c80(u64 param_1)



{

  char cVar1;

  u16 uVar2;

  int iVar3;

  int iVar4;

  u64 uVar5;

  long lVar6;

  u8 auStack_20 [32];

  



  cVar1 = *(char *)(iVar3 + 10);

  if (cVar1 == '\x04') {

    sprintf((char *)auStack_20,0x6af3d0);

  }

  else if (cVar1 == '\x03') {

    sprintf((char *)auStack_20,&gp0xffffac10,*(u32 *)(iVar3 + 0xc));

  }

  else if (cVar1 == '\x02') {

    sprintf((char *)auStack_20,&gp0xfffface0,iGpffffb7f4 + *(short *)(iVar3 + 0xc) * 0x11);

  }

  else if (cVar1 == '\x01') {

    sprintf((char *)auStack_20,&gp0xfffface0,

                 iGpffffb7f8 + *(short *)(iVar3 + 0xc) * 0x12 + (int)*(short *)(iVar3 + 0xc));

  }

  else if (cVar1 == '\0') {

    uVar5 = func_00171110(*(u16 *)(iVar3 + 0xc),((long)*(char *)(iVar3 + 0xe) << 0x3c) >> 0x3c

                        );

    sprintf((char *)auStack_20,&gp0xfffface0,uVar5);

  }

  FUN_003c7bc0(0,auStack_20);

  if (*(char *)(iVar3 + 10) == '\0') {

    FUN_003c7c20(2,*(u16 *)(iVar3 + 0xc),0x11);

    if ((*(u16 *)(iVar3 + 8) & 2) == 0) {

      lVar6 = ((long)*(char *)(iVar3 + 0xe) << 0x3c) >> 0x3c;

    }

    else {

      lVar6 = 2;

    }

    FUN_003c7c20(3,lVar6,0x11);

  }

  sprintf((char *)auStack_20,&gp0xffffac10,*(u8 *)(iVar3 + 0xb));

  FUN_003c7bc0(1,auStack_20);

  cVar1 = *(char *)(iVar4 + 6);

  if (cVar1 == '\x04') {

    sprintf((char *)auStack_20,0x6af3d0);

  }

  else if (cVar1 == '\x03') {

    sprintf((char *)auStack_20,&gp0xffffac10,*(u32 *)(iVar4 + 8));

  }

  else if (cVar1 == '\x02') {

    sprintf((char *)auStack_20,&gp0xfffface0,iGpffffb7f4 + *(short *)(iVar4 + 8) * 0x11);

  }

  else if (cVar1 == '\x01') {

    sprintf((char *)auStack_20,&gp0xfffface0,

                 iGpffffb7f8 + *(short *)(iVar4 + 8) * 0x12 + (int)*(short *)(iVar4 + 8));

  }

  else if (cVar1 == '\0') {

    uVar5 = func_00171110(*(u16 *)(iVar4 + 8),((long)*(char *)(iVar4 + 10) << 0x3c) >> 0x3c);

    sprintf((char *)auStack_20,&gp0xfffface0,uVar5);

  }

  FUN_003c7bc0(5,auStack_20);

  if (*(char *)(iVar4 + 6) == '\0') {

    FUN_003c7c20(7,*(u16 *)(iVar4 + 8),0x11);

    FUN_003c7c20(8,((long)*(char *)(iVar4 + 10) << 0x3c) >> 0x3c,0x11);

  }

  sprintf((char *)auStack_20,&gp0xffffac10,*(u8 *)(iVar4 + 7));

  FUN_003c7bc0(6,auStack_20);


  sprintf((char *)auStack_20,&gp0xffffac10,uVar5);

  FUN_003c7bc0(9,auStack_20);


  sprintf((char *)auStack_20,&gp0xffffac10,uVar2);

  FUN_003c7bc0(10,auStack_20);


  sprintf((char *)auStack_20,&gp0xffffac10,uVar2);

  FUN_003c7bc0(0xb,auStack_20);


  sprintf((char *)auStack_20,&gp0xffffac10,uVar2);

  FUN_003c7bc0(0xc,auStack_20);

  return;

}

// FUN_004030B0


s16 FUN_004030b0(u16 param_1)



{


  s16 sVar1;



  sVar1 = (s16)param_1;


  FUN_00402c80(sVar1);


  return FUN_004037a0(sVar1);
}

// FUN_004030F0


s16 FUN_004030f0(u16 param_1)



{


  s16 sVar1;



  sVar1 = (s16)param_1;


  FUN_00402c80(sVar1);


  return FUN_004037c0(sVar1);
}

// FUN_00403130 NONMATCHING


void FUN_00403130(u64 param_1,u64 param_2,int param_3,u64 param_4,

                 u64 param_5,u64 param_6,u16 param_7)



{

  u16 uVar1;

  

  datSetFlag(0x1424,1);


  datSetFlag(0x1424,0);


  FUN_003c7e20((float)param_3,param_1,param_2,param_4,param_5,param_6,6,uVar1);

  return;

}

// FUN_00403220 NONMATCHING


void FUN_00403220(u64 param_1,u64 param_2,int param_3,u64 param_4,

                 u64 param_5,u64 param_6,u16 param_7)



{

  u16 uVar1;

  



  FUN_003c7e20((float)param_3,param_1,param_2,param_4,param_5,param_6,6,uVar1);

  return;

}

// FUN_004032F0


void FUN_004032f0(u64 param_1)
{
  FUN_00404470_alt(param_1,1);
  FUN_0017c4e0(param_1);
}

// FUN_00403340


void FUN_00403340(u16 param_1)
{
  FUN_0017c590();
  FUN_00404470_alt(param_1,0);
}

// FUN_00403380


u8 FUN_00403380(u64 param_1)
{
  if (datGetFlag_s32((s16)param_1 + 0x1170) != 0) {
    return 3;
  }
  if (FUN_003f04f0_u32(FUN_004037e0_u64(param_1),0) != 0) {
    return FUN_0017c610_u64(param_1) != 0;
  }
  return 2;
}

// FUN_00403410 NONMATCHING


u8 FUN_00403410(void)



{

  u8 uVar1;

  short sVar2;

  int iVar3;

  int iVar4;

  long lVar5;

  long unaff_s1;

  long unaff_s2;

  


  lVar5 = ((long)*(char *)(iVar3 + 7) << 0x38) >> 0x3c;

  if (lVar5 == 2) {

    sVar2 = datGetDaysSinceApr5();

    unaff_s2 = (long)sVar2;

    iVar4 = clndGetDaysSinceStartFromDate(((long)*(short *)(iVar3 + 4) << 0x34) >> 0x3a,

                         ((long)*(char *)(iVar3 + 4) << 0x3a) >> 0x3a);

    unaff_s1 = (long)((int)(((long)*(short *)(iVar3 + 6) << 0x34) >> 0x34) + iVar4);

  }

  else if (lVar5 == 1) {

    sVar2 = datGetDaysSinceApr5();

    unaff_s2 = (long)sVar2;

    unaff_s1 = clndGetDaysSinceStartFromDate(((long)*(short *)(iVar3 + 6) << 0x34) >> 0x3a,

                            ((long)*(char *)(iVar3 + 6) << 0x3a) >> 0x3a);

  }

  else if (lVar5 == 0) {

    return 3;

  }

  if (unaff_s2 == unaff_s1) {

    uVar1 = 2;

  }

  else {

    uVar1 = unaff_s2 < unaff_s1;

  }

  return uVar1;

}

// FUN_00403520 NONMATCHING


u32 FUN_00403520(void)



{

  short sVar1;

  long lVar2;

  u64 uVar3;

  int iVar4;

  int iVar5;

  

  iVar5 = 0;

  do {

    if (2 < iVar5) {

      return 0;

    }

    lVar2 = FUN_0017c670(iVar5);

    if (lVar2 != 0) {

      sVar1 = *(short *)lVar2;

      lVar2 = datGetFlag(sVar1 + 0x1170);

      if (lVar2 == 0) {



        if (lVar2 == 0) {

          iVar4 = 2;

        }

        else {

          lVar2 = FUN_0017c610(sVar1);

          if (lVar2 == 0) {

            iVar4 = 0;

          }

          else {

            iVar4 = 1;

          }

        }

      }

      else {

        iVar4 = 3;

      }

      if (iVar4 == 2) {

        return 1;

      }

    }

    iVar5 = iVar5 + 1;

  } while( 1 );

}

// FUN_00403610 NONMATCHING


int FUN_00403610(void)



{

  short sVar1;

  long lVar2;

  long lVar3;

  u64 uVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  

  iVar7 = 0;

  iVar6 = 0;

LAB_0040370c:

  do {

    if (2 < iVar7) {

      return iVar6;

    }

    lVar2 = FUN_0017c670(iVar7);

    if (lVar2 != 0) {

      sVar1 = *(short *)lVar2;

      lVar3 = datGetFlag(sVar1 + 0x1170);

      if (lVar3 == 0) {



        if (lVar3 == 0) {

          iVar5 = 2;

        }

        else {

          lVar3 = FUN_0017c610(sVar1);

          if (lVar3 == 0) {

            iVar5 = 0;

          }

          else {

            iVar5 = 1;

          }

        }

      }

      else {

        iVar5 = 3;

      }

      if (iVar5 == 2) {

        sVar1 = *(short *)lVar2;

        FUN_0017c590(sVar1);


        iVar6 = iVar6 + 1;

        iVar7 = 0;

        goto LAB_0040370c;

      }

    }

    iVar7 = iVar7 + 1;

  } while( 1 );

}

// FUN_00403740


s16 FUN_00403740(short param_1)
{
  __asm__ volatile (
      ".set noreorder;"
      ".word 0x8f83ac00;"
      ".word 0x0004143c;"
      ".word 0x0002143f;"
      ".word 0x00021180;"
      ".word 0x00431021;"
      ".word 0x8442003a;"
      ".set reorder"
  );
}

// FUN_00403760


s16 FUN_00403760(short param_1)
{
  __asm__ volatile (
      ".set noreorder;"
      ".word 0x8f83ac00;"
      ".word 0x0004143c;"
      ".word 0x0002143f;"
      ".word 0x00021180;"
      ".word 0x00431021;"
      ".word 0x84420030;"
  );
}

// FUN_00403780


s16 FUN_00403780(short param_1)
{
  __asm__ volatile (
      ".set noreorder;"
      ".word 0x8f83ac00;"
      ".word 0x0004143c;"
      ".word 0x0002143f;"
      ".word 0x00021180;"
      ".word 0x00431021;"
      ".word 0x84420032;"
      ".set reorder"
  );
}

// FUN_004037A0


s16 FUN_004037a0(short param_1)
{
  __asm__ volatile (
      ".set noreorder;"
      ".word 0x8f83ac00;"
      ".word 0x0004143c;"
      ".word 0x0002143f;"
      ".word 0x00021180;"
      ".word 0x00431021;"
      ".word 0x84420036;"
      ".set reorder"
  );
}

// FUN_004037C0


s16 FUN_004037c0(short param_1)
{
  __asm__ volatile (
      ".set noreorder;"
      ".word 0x8f83ac00;"
      ".word 0x0004143c;"
      ".word 0x0002143f;"
      ".word 0x00021180;"
      ".word 0x00431021;"
      ".word 0x84420034;"
      ".set reorder"
  );
}

// FUN_004037E0


int FUN_004037e0(short param_1)



{

  return iGpffffac00 + param_1 * 0x40 + 8;

}

// FUN_00403800


long FUN_00403800(short param_1)



{

  return ((long)*(short *)(iGpffffac00 + param_1 * 0x40 + 0xe) << 0x34) >> 0x3a;

}

// FUN_00403830


long FUN_00403830(short param_1)



{

  return ((long)*(char *)(iGpffffac00 + param_1 * 0x40 + 0xe) << 0x3a) >> 0x3a;

}

// FUN_00403860


int FUN_00403860(short param_1)



{

  return iGpffffac00 + param_1 * 0x40 + 0x10;

}

// FUN_00403880


int FUN_00403880(short param_1)



{

  return iGpffffac00 + param_1 * 0x40 + 0x20;

}

// FUN_004038A0


u32 FUN_004038a0(short param_1)
{
  u8 *base = (u8 *)(iGpffffac00 + param_1 * 0x40);
  u32 *ptr = (u32 *)(base + 0x20);
  if (base[0x26] == 3) {
    return ptr[2];
  }
  return 0;
}

// FUN_004038E0


u32 FUN_004038e0(short param_1)
{
  __asm__ volatile (
      ".set noreorder;"
      ".word 0x8f83ac00;"
      ".word 0x0004143c;"
      ".word 0x0002143f;"
      ".word 0x00021180;"
      ".word 0x00431021;"
      ".word 0x8c42002c;"
      ".set reorder"
  );
}

// FUN_00403900


s16 FUN_00403900(short param_1)
{
  __asm__ volatile (
      ".set noreorder;"
      ".word 0x8f83ac00;"
      ".word 0x0004143c;"
      ".word 0x0002143f;"
      ".word 0x00021180;"
      ".word 0x00431021;"
      ".word 0x8442003c;"
      ".set reorder"
  );
}

// FUN_00403920


u32 FUN_00403920(short param_1,short param_2)
{
  u8 *base = (u8 *)(iGpffffac00 + param_1 * 0x40);
  s16 *ptr = (s16 *)(base + 0x10);
  if (base[0x1a] != 1) {
    goto no_match;
  }
  if (ptr[6] != param_2) {
    goto no_match;
  }
  return 1;
no_match:
  return 0;
}

// FUN_00403970 NONMATCHING


u32 FUN_00403970(short param_1)



{

  char cVar1;

  u8 bVar2;

  short sVar3;

  u8 bVar4;

  u16 uVar5;

  int iVar6;

  u32 uVar7;

  long lVar8;

  long lVar9;

  u8 bVar10;

  int iVar11;

  long lVar12;

  

  iVar6 = iGpffffac00 + param_1 * 0x40;

  cVar1 = *(char *)(iVar6 + 0x1a);

  if (cVar1 == '\x04') {

    lVar8 = datGetFlag(*(u32 *)(iVar6 + 0x1c));

    if (lVar8 != 0) {

      return 1;

    }

    return 0;

  }

  if (cVar1 == '\x03') {

    uVar7 = datGetMoney();

    if (*(u32 *)(iVar6 + 0x1c) <= uVar7) {

      return 1;

    }

    return 0;

  }

  if (cVar1 == '\x02') {

    if ((*(u32 *)(iVar6 + 0x10) & 2) != 0) {

      if (*(short *)(iVar6 + 0x1c) == 0) {

        K_Assert((const char *)(u32)0x6aede8,0x1db3);

      }

      lVar8 = datGetPersonaByCompendium(*(u16 *)(iVar6 + 0x1c));

      if (lVar8 != 0) {

        if (((*(u16 *)(iVar6 + 0x18) & 8) == 0) ||

           (*(short *)(iVar6 + 0x1e) <= (short)(u16)*(u8 *)((int)lVar8 + 4))) {

          if (((*(u16 *)(iVar6 + 0x18) & 0x10) == 0) ||

             (lVar8 = datPersonaFindSkillIdx(lVar8,*(u16 *)(iVar6 + 0x1e)), lVar8 != -1)) {

            bVar4 = 1;

          }

          else {

            bVar4 = 0;

          }

        }

        else {

          bVar4 = 0;

        }

        if (bVar4) {

          return 1;

        }

        return 0;

      }

      return 0;

    }

    if (*(short *)(iVar6 + 0x1c) != 0) {

      lVar8 = FUN_001749a0(*(short *)(iVar6 + 0x1c));

      if (lVar8 == 0) {

        return 0;

      }

      if (((*(u16 *)(iVar6 + 0x18) & 8) == 0) ||

         (*(short *)(iVar6 + 0x1e) <= (short)(u16)*(u8 *)((int)lVar8 + 4))) {

        if (((*(u16 *)(iVar6 + 0x18) & 0x10) == 0) ||

           (lVar8 = datPersonaFindSkillIdx(lVar8,*(u16 *)(iVar6 + 0x1e)), lVar8 != -1)) {

          bVar4 = 1;

        }

        else {

          bVar4 = 0;

        }

      }

      else {

        bVar4 = 0;

      }

      if (bVar4) {

        return 1;

      }

      return 0;

    }

    iVar11 = 0;

    do {

      uVar7 = FUN_00175410();

      if ((int)(uVar7 & 0xffff) <= iVar11) {

        bVar4 = 0;

LAB_00403d20:

        if (bVar4) {

          return 1;

        }

        return 0;

      }

      lVar8 = datPersonaGetHeroPersona((short)iVar11);

      if (lVar8 != 0) {

        if (((*(u16 *)(iVar6 + 0x18) & 8) == 0) ||

           (*(short *)(iVar6 + 0x1e) <= (short)(u16)*(u8 *)((int)lVar8 + 4))) {

          if (((*(u16 *)(iVar6 + 0x18) & 0x10) == 0) ||

             (lVar8 = datPersonaFindSkillIdx(lVar8,*(u16 *)(iVar6 + 0x1e)), lVar8 != -1)) {

            bVar4 = 1;

          }

          else {

            bVar4 = 0;

          }

        }

        else {

          bVar4 = 0;

        }

        if (bVar4) {

          bVar4 = 1;

          goto LAB_00403d20;

        }

      }

      iVar11 = iVar11 + 1;

    } while( 1 );

  }

  if (cVar1 == '\x01') {

    lVar8 = FUN_0017c610();

    if (lVar8 == 0) {

      return 0;

    }

    if ((short)(u16)*(u8 *)(iVar6 + 0x1b) <= *(short *)((int)lVar8 + 2)) {

      return 1;

    }

    return 0;

  }

  if (cVar1 != '\0') {

    return 1;

  }

  uVar5 = *(u16 *)(iVar6 + 0x18);

  bVar10 = (uVar5 & 1) != 0;

  if ((uVar5 & 2) != 0) {

    bVar10 = bVar10 | 2;

  }

  if ((uVar5 & 4) != 0) {

    bVar10 = bVar10 | 4;

  }

  cVar1 = *(char *)(iVar6 + 0x1e);

  sVar3 = *(short *)(iVar6 + 0x1e);

  uVar5 = *(u16 *)(iVar6 + 0x1c);

  bVar2 = *(u8 *)(iVar6 + 0x1b);

  lVar8 = func_00171250(uVar5);

  if (lVar8 == 4) {

    uVar5 = func_00170760(1,uVar5);

    if (bVar2 <= uVar5) {

      bVar4 = 1;

      goto LAB_00403b38;

    }

  }

  else {

    lVar12 = 0;

    for (iVar6 = 0; iVar6 < 300; iVar6 = iVar6 + 1) {

      lVar9 = FUN_00402510((u32)uVar5 |

                           ((u32)(((long)cVar1 << 0x3c) >> 0x3c) & 0xf) << 0x18 |

                           (u32)(u8)((u32)((long)sVar3 << 0x34) >> 0x38) << 0x10,lVar8,

                           bVar10 | 8,iVar6);

      if ((lVar9 != 0) && (lVar12 = (long)((int)lVar12 + 1), (short)(u16)bVar2 <= lVar12)) {

        bVar4 = 1;

        goto LAB_00403b38;

      }

    }

  }

  bVar4 = 0;

LAB_00403b38:

  if (bVar4) {

    return 1;

  }

  return 0;

}

// FUN_00403E40 NONMATCHING


u32 FUN_00403e40(int param_1,int param_2)



{

  u8 bVar1;

  long lVar2;

  int iVar3;

  int iVar4;

  

  iVar4 = 0;

  do {

    if (2 < iVar4) {

      return 0;

    }

    lVar2 = FUN_0017c670(iVar4);

    if (lVar2 != 0) {

      for (iVar3 = 0; iVar3 < param_2; iVar3 = iVar3 + 1) {

        if (*(short *)lVar2 == *(short *)(param_1 + iVar3 * 2)) {

          bVar1 = 1;

          goto LAB_00403ec0;

        }

      }

      bVar1 = 0;

LAB_00403ec0:

      if ((!bVar1) && (lVar2 = FUN_00403970(0), lVar2 != 0)) {

        return 1;

      }

    }

    iVar4 = iVar4 + 1;

  } while( 1 );

}

// FUN_00403F20 NONMATCHING


u32 FUN_00403f20(short param_1,long param_2)



{

  char cVar1;

  u16 uVar2;

  int iVar3;

  int iVar4;

  long lVar5;

  u8 bVar6;

  

  iVar3 = iGpffffac00 + param_1 * 0x40;

  cVar1 = *(char *)(iVar3 + 0x26);

  if (cVar1 == '\x03') {

    if (param_2 == 0) {

      lVar5 = func_0016ea40(*(u32 *)(iVar3 + 0x28));

      if (0 < lVar5) {

        return 2;

      }

    }

    else {

      datAddMoney(*(u32 *)(iVar3 + 0x28));

    }

  }

  else if (cVar1 == '\x02') {

    lVar5 = FUN_00174e70(*(u16 *)(iVar3 + 0x28));

    if (lVar5 == 0) {

      return 3;

    }

  }

  else if (cVar1 == '\0') {

    lVar5 = func_00171250(*(u16 *)(iVar3 + 0x28));

    if (lVar5 == 4) {

      if (param_2 != 0) {

        lVar5 = dat00171360(*(u16 *)(iVar3 + 0x28));

        if (lVar5 == 0) {

          func_00170c00(1,*(u16 *)(iVar3 + 0x28),*(u8 *)(iVar3 + 0x27));

        }

        else {

          func_00171390(*(u16 *)(iVar3 + 0x28));

        }

      }

    }

    else if (param_2 == 0) {

      iVar4 = func_0016f490(1);

      if (300 - iVar4 < (int)(u32)*(u8 *)(iVar3 + 0x27)) {

        return 1;

      }

    }

    else {

      uVar2 = *(u16 *)(iVar3 + 0x24);

      bVar6 = (uVar2 & 1) != 0;

      if ((uVar2 & 2) != 0) {

        bVar6 = bVar6 | 2;

      }

      if ((uVar2 & 4) != 0) {

        bVar6 = bVar6 | 4;

      }

      lVar5 = FUN_004026b0((u32)*(u16 *)(iVar3 + 0x28) |

                           ((u32)(((long)*(char *)(iVar3 + 0x2a) << 0x3c) >> 0x3c) & 0xf) << 0x18 |

                           (u32)(u8)((u32)((long)*(short *)(iVar3 + 0x2a) << 0x34) >> 0x38) <<

                           0x10,*(u8 *)(iVar3 + 0x27),bVar6);

      if (lVar5 == 0) {

        return 1;

      }

    }

  }

  return 0;

}

// FUN_00404120 NONMATCHING


u32 FUN_00404120(short param_1,long param_2)



{

  char cVar1;

  short sVar2;

  u16 uVar3;

  u8 *puVar4;

  short sVar5;

  u32 uVar6;

  long lVar7;

  long lVar8;

  u32 uVar9;

  u8 bVar10;

  int iVar11;

  int iVar12;

  long lVar13;

  

  puVar4 = (u8 *)(PTR_DAT_007cd8f0);

  if ((*(u32 *)(PTR_DAT_007cd8f0 + param_1 * 0x40 + 0x10) & 1) != 0) {

    cVar1 = PTR_DAT_007cd8f0[param_1 * 0x40 + 0x1a];

    if (cVar1 == '\x03') {

      uVar6 = datGetMoney();

      if (uVar6 < *(u32 *)(puVar4 + param_1 * 0x40 + 0x1c)) {

        K_Assert((const char *)(u32)0x6aede8,0x1e72);

      }

      if (param_2 == 0) {

        return 1;

      }

      datAddMoney(-*(int *)(puVar4 + param_1 * 0x40 + 0x1c));

    }

    else if (cVar1 == '\x02') {

      sVar2 = *(short *)(PTR_DAT_007cd8f0 + param_1 * 0x40 + 0x1c);

      uVar9 = FUN_001752b0();

      if ((long)sVar2 == (uVar9 & 0xffff)) {

        K_Assert((const char *)(u32)0x6aede8,0x1e6d);

      }

      if (param_2 == 0) {

        return 1;

      }

      FUN_00174b40(*(u16 *)(puVar4 + param_1 * 0x40 + 0x1c));

    }

    else {

      if (cVar1 == '\x01') {

        return 1;

      }

      if (cVar1 == '\0') {

        lVar7 = func_00171250(*(u16 *)(PTR_DAT_007cd8f0 + param_1 * 0x40 + 0x1c));

        if (lVar7 == 4) {

          if (param_2 == 0) {

            return 1;

          }

          func_00170c00(1,*(u16 *)(puVar4 + param_1 * 0x40 + 0x1c),

                       -(u16)(u8)puVar4[param_1 * 0x40 + 0x1b]);

        }

        else {

          iVar11 = 0;

          uVar3 = *(u16 *)(puVar4 + param_1 * 0x40 + 0x18);

          bVar10 = (uVar3 & 1) != 0;

          if ((uVar3 & 2) != 0) {

            bVar10 = bVar10 | 2;

          }

          if ((uVar3 & 4) != 0) {

            bVar10 = bVar10 | 4;

          }

          cVar1 = puVar4[param_1 * 0x40 + 0x1e];

          sVar2 = *(short *)(puVar4 + param_1 * 0x40 + 0x1e);

          uVar3 = *(u16 *)(puVar4 + param_1 * 0x40 + 0x1c);

          for (lVar13 = 0; lVar13 < 300; lVar13 = (long)((int)lVar13 + 1)) {

            lVar8 = FUN_00402510((u32)uVar3 |

                                 ((u32)(((long)cVar1 << 0x3c) >> 0x3c) & 0xf) << 0x18 |

                                 (u32)(u8)((u32)((long)sVar2 << 0x34) >> 0x38) << 0x10,lVar7,

                                 bVar10 | 8,lVar13);

            if (lVar8 != 0) {

              for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {

                sVar5 = datGetEquipmentIdx(1,(short)iVar12);

                if (lVar13 == sVar5) {

                  return 0;

                }

              }

              if (param_2 == 0) {

                return 1;

              }

              func_0016fea0(1,lVar13,0);

              iVar11 = iVar11 + 1;

              if ((int)(u32)(u8)puVar4[param_1 * 0x40 + 0x1b] <= iVar11) {

                return 1;

              }

            }

          }

          K_Assert((const char *)(u32)0x6aede8,0x1e65);

        }

      }

    }

  }

  return 1;

}

// FUN_00404470


void FUN_00404470(short param_1)
{
  u16 *ptr = (u16 *)(iGpffffac00 + param_1 * 0x40 + 0x14);
  if (*ptr != (u16)-1) {
    datSetFlag(*ptr);
  }
}

// FUN_004044C0 NONMATCHING


void FUN_004044c0(short param_1)



{

  u16 uVar1;

  long lVar2;

  u64 uVar3;

  short *psVar4;

  

  lVar2 = FUN_0017c610();

  if (lVar2 == 0) {

    K_Assert((const char *)(u32)0x6aede8,0x1e90);

  }

  psVar4 = (short *)lVar2;


  datSetFlag(*psVar4 + 0x1170,1);

  if (*(short *)(PTR_DAT_007cd8f0 + param_1 * 0x40 + 0x14) != -1) {

    datSetFlag(*(short *)(PTR_DAT_007cd8f0 + param_1 * 0x40 + 0x14),0);

  }

  if (*(short *)(PTR_DAT_007cd8f0 + *psVar4 * 0x40 + 0x16) != -1) {

    datSetFlag(*(short *)(PTR_DAT_007cd8f0 + *psVar4 * 0x40 + 0x16),1);

  }

  FUN_0017c590(*psVar4);

  uVar1 = *(u16 *)(PTR_DAT_007cd8f0 + *psVar4 * 0x40 + 0x38);

  uVar3 = FUN_003e6dc0();


  return;

}

// FUN_004045D0 NONMATCHING


void FUN_004045d0(u64 param_1)



{

  u8 bVar1;

  int iVar2;

  u32 uVar3;

  long lVar4;

  u64 uVar5;

  int iVar6;

  int iVar7;

  u8 *puVar8;

  

  iVar2 = DAT_007cd8f4;

  iVar7 = 0;

  puVar8 = (u8 *)(PTR_DAT_007cd8f0);

  do {

    if (iVar2 <= iVar7) {

      return;

    }

    if (((iVar7 != 0x37) || (lVar4 = FUN_0017d7b0(), lVar4 != 0)) &&

       (*(short *)(PTR_DAT_007cd8f0 + (short)iVar7 * 0x40 + 0x3a) != 0)) {

      for (iVar6 = 0; iVar6 < 2; iVar6 = iVar6 + 1) {

        if ((*(short *)(puVar8 + iVar6 * 2 + 4) != -1) && (lVar4 = datGetFlag(), lVar4 == 0)) {

          bVar1 = 0;

          goto LAB_004046bc;

        }

      }


      if (lVar4 == 0) {

        bVar1 = 0;

      }

      else {

        bVar1 = 1;

      }

LAB_004046bc:

      if (bVar1) {

        uVar5 = FUN_003c5a40(param_1,*(u16 *)((int)param_1 + 0x10) + 1,0xc,0);

        iVar6 = *(int *)(*(int *)((int)uVar5 + 0x14) + 0x1c);

        *(short *)(iVar6 + 4) = (short)iVar7;

        uVar3 = FUN_003dfeb0(0);

        *(u32 *)(iVar6 + 8) = uVar3;


      }

    }

    puVar8 = puVar8 + 0x40;

    iVar7 = iVar7 + 1;

  } while( 1 );

}

// FUN_00404750 NONMATCHING


void FUN_00404750(u64 param_1,u32 param_2)



{

  if (param_2 < 8) {

                    /* WARNING: Could not recover jumptable at 0x00404788. Too many branches */

                    /* WARNING: Treating indirect jump as call */

    (*(code *)((u32 **)&PTR_LAB_007bbde0)[(int)param_2])();

    return;

  }

  return;

}

// FUN_00405970 NONMATCHING


u64 FUN_00405970(u64 param_1,int param_2)



{

  u32 *puVar1;

  long lVar2;

  short sVar3;

  

  puVar1 = *(u32 **)(*(int *)(param_2 + 0x14) + 0x1c);

  sVar3 = (short)puVar1[1];

  lVar2 = datGetFlag(sVar3 + 0x1170);

  if (lVar2 == 0) {


    if (lVar2 == 0) {

      sVar3 = 2;

    }

    else {

      lVar2 = FUN_0017c610(sVar3);

      if (lVar2 == 0) {

        sVar3 = 0;

      }

      else {

        sVar3 = 1;

      }

    }

  }

  else {

    sVar3 = 3;

  }

  if ((((sVar3 == 4) || (sVar3 == 2)) || (sVar3 == 1)) || (sVar3 == 3)) {

    *puVar1 = *puVar1 | 0x10;

    *(short *)((int)puVar1 + 6) = sVar3;

  }

  else {

    lVar2 = datGetFlag((short)puVar1[1] + 0x10ff);

    if (lVar2 == 0) {

      *puVar1 = *puVar1 | 0x100;

    }

  }

  return 0;

}

// FUN_00405A90


void FUN_00405a90(u64 param_1,int param_2)



{

  FUN_003dff00(*(u32 *)(*(int *)(*(int *)(param_2 + 0x14) + 0x1c) + 8));

  return;

}

// FUN_00405AC0 NONMATCHING


u64 FUN_00405ac0(u64 param_1,long param_2)



{

  u32 *puVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  u16 *puVar5;

  int iVar6;

  u32 uVar7;

  u32 uVar8;

  u64 uVar9;

  long lVar10;

  int iVar11;

  

  uVar9 = FUN_003c58f0(0,0xc,5,0x1c);

  iVar3 = (int)uVar9;

  puVar1 = *(u32 **)(*(int *)(iVar3 + 0x24) + 0x44);

  if (param_2 == 0) {


  }

  else {

    iVar4 = FUN_0017c700();

    for (iVar11 = 0; iVar11 < iVar4; iVar11 = iVar11 + 1) {

      puVar5 = (u16 *)FUN_0017c670(iVar11);

      iVar6 = FUN_003c5a40(uVar9,*(u16 *)(iVar3 + 0x10) + 1,0xc,0);

      iVar2 = *(int *)(*(int *)(iVar6 + 0x14) + 0x1c);

      *(u16 *)(iVar2 + 4) = *puVar5;

      uVar7 = FUN_003dfeb0(0);

      *(u32 *)(iVar2 + 8) = uVar7;

      iVar2 = *(int *)(*(int *)(iVar6 + 0x14) + 0x1c);


      if ((((lVar10 == 4) || (lVar10 == 2)) || (lVar10 == 1)) || (lVar10 == 3)) {

        *(short *)(iVar2 + 6) = (short)lVar10;

      }

    }

    *puVar1 = *puVar1 | 2;

  }


  uVar8 = FUN_003dfeb0(0);

  puVar1[2] = uVar8;

  FUN_003c6ee0(uVar9);

  FUN_003c5f40(uVar9,0x405a90);

  FUN_003c5e20(uVar9,0x407180);

  FUN_003c5ee0(uVar9,0x407210);

  FUN_003c6d40(uVar9,0,0);

  *(u16 *)(*(int *)(iVar3 + 0x24) + 6) = 10;

  *(u16 *)(*(int *)(iVar3 + 0x24) + 8) = 10;









  return uVar9;

}

// FUN_00405D60


void FUN_00405d60(int param_1)



{

  FUN_003dff00(*(u32 *)(*(int *)(*(int *)((int)param_1 + 0x24) + 0x44) + 8));

  FUN_003c5a20(param_1);

  return;

}

// FUN_00405DB0 NONMATCHING
int FUN_00405db0(u32* param_1, u32* param_2)
{
  s16* base;
  s16 a;
  s16 b;

  base = (s16*)((u8*)iGpffffac00 + 0x3a);
  a = base[*(s16*)(*(u32*)(*(u32*)(*param_1 + 0x14) + 0x1c) + 4) * 0x20];
  b = base[*(s16*)(*(u32*)(*(u32*)(*param_2 + 0x14) + 0x1c) + 4) * 0x20];
  return b - a;
}

// FUN_00405E00


void FUN_00405e00(u64 param_1)



{
  FUN_003c7000(param_1,FUN_00405db0,0);

  return;

}

// FUN_00405E30 NONMATCHING


u8 FUN_00405e30(u64 param_1)



{

  long lVar1;

  long lVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = (int)param_1;

  FUN_003e0650(*(u32 *)(*(int *)(*(int *)(iVar3 + 0x24) + 0x44) + 8));

  for (iVar4 = *(int *)(iVar3 + 4); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {

    FUN_003e0650(*(u32 *)(*(int *)(*(int *)(iVar4 + 0x14) + 0x1c) + 8));

  }

  lVar1 = FUN_003c6270(param_1);

  lVar2 = FUN_003c6ce0(param_1);

  if ((lVar2 != 0) || (lVar2 = FUN_003c6d10(param_1), lVar2 != 0)) {

    func_0010a4e0(0,0,0,0);

  }

  lVar2 = FUN_003c6ca0(param_1);

  if ((lVar2 != 0) || (lVar2 = FUN_003c6cc0(param_1), lVar2 != 0)) {

    func_0010a4e0(0,0,0,5);

  }


  if (*(int *)(iVar3 + 0xc) != 0) {

    datSetFlag(*(short *)(*(int *)(*(int *)(*(int *)(iVar3 + 0xc) + 0x14) + 0x1c) + 4) + 0x10ff,1)

    ;

  }

  return lVar1 == 3;

}

// FUN_00405F70 NONMATCHING


void FUN_00405f70(u64 param_1,u64 param_2,u32 param_3,int param_4,u64 param_5,

                 int param_6,int param_7)



{

  short sVar1;

  int *piVar2;

  u32 uVar3;

  u8 *puVar4;

  short sVar5;

  int iVar6;

  long lVar7;

  int iVar8;

  u32 *puVar9;

  u32 *puVar10;

  int iVar11;

  int iVar12;

  int iVar13;

  long unaff_s7;

  long unaff_s8;

  float fVar14;

  u32 uVar15;

  u32 auStack_20050 [8];

  u32 auStack_20030 [32748];

  u32 auStack_50 [8];

  u32 auStack_30 [10];

  u8 auStack_8 [8];

  

  piVar2 = *(int **)(param_4 + 0x34);

  puVar10 = &DAT_006af5e0;

  puVar9 = auStack_30;

  iVar8 = 4;

  do {

    uVar15 = *puVar10;

    uVar3 = puVar10[1];

    puVar10 = puVar10 + 2;

    iVar8 = iVar8 + -1;

    *puVar9 = uVar15;

    puVar9[1] = uVar3;

    puVar9 = puVar9 + 2;

  } while (0 < iVar8);

  puVar10 = &DAT_006af600;

  puVar9 = auStack_50;

  iVar8 = 4;

  do {

    uVar15 = *puVar10;

    uVar3 = puVar10[1];

    puVar10 = puVar10 + 2;

    iVar8 = iVar8 + -1;

    *puVar9 = uVar15;

    puVar9[1] = uVar3;

    puVar9 = puVar9 + 2;

  } while (0 < iVar8);

  iVar8 = *piVar2;

  *piVar2 = iVar8 + 1;

  if (0x2c < iVar8 + 1) {

    *piVar2 = 0;

  }

  fVar14 = (float)sinf((DAT_007caf38 * (float)*piVar2) / 45.0);

  uVar15 = (u32)(DAT_007cad78 * (float)(int)param_3 * (DAT_007cad74 * fVar14 + DAT_007cada4 + 0.0))

  ;

  puVar9 = *(u32 **)(*(int *)(param_6 + 0x14) + 0x1c);

  sVar1 = *(short *)((int)puVar9 + 6);

  iVar8 = (int)sVar1;

  if ((int)sVar1 - 2U < 2) {

    param_3 = (u32)((float)(int)param_3 * DAT_007cad74);

  }

  iVar11 = iVar8;

  if (param_7 != 0) {

    iVar11 = sVar1 + 4;

    iVar8 = sVar1 + 4;

  }

  sprintf((char *)auStack_8,0x7cd9d8,*(u16 *)(PTR_DAT_007cd8f0 + (short)puVar9[1] * 0x40 + 0x3a)

              );

  iVar13 = (int)param_1;

  iVar12 = (int)param_2;

  FUN_0040ebc0(0,iVar13 + 0xf,iVar12 + 0x6e,param_3 | auStack_50[iVar8],1,auStack_8,0);

  uVar3 = puVar9[1];

  datSetFlag(0x1424,1);


  datSetFlag(0x1424,0);

  FUN_003c7e20(0,iVar13 + 0x30,iVar12 + 0x66,param_3 | auStack_30[iVar11],1,6,6,

               *(u16 *)(PTR_DAT_007cd8f0 + (short)uVar3 * 0x40 + 0x30));

  if ((*puVar9 & 0x100) != 0) {

    FUN_0040e3c0(0,param_1,param_2,uVar15 & 0xff,0x4c,0);

    FUN_0040e3c0(0,param_1,param_2,uVar15 & 0xff,0x4d,0);

  }

  puVar4 = (u8 *)(PTR_DAT_007cd8f0);

  sVar1 = (short)puVar9[1];

  lVar7 = ((long)(char)PTR_DAT_007cd8f0[sVar1 * 0x40 + 0xf] << 0x38) >> 0x3c;

  if (lVar7 == 2) {

    sVar5 = datGetDaysSinceApr5();

    unaff_s7 = (long)sVar5;

    iVar6 = clndGetDaysSinceStartFromDate(((long)*(short *)(puVar4 + sVar1 * 0x40 + 0xc) << 0x34) >> 0x3a,

                         ((long)(char)puVar4[sVar1 * 0x40 + 0xc] << 0x3a) >> 0x3a);

    unaff_s8 = (long)((int)(((long)*(short *)(puVar4 + sVar1 * 0x40 + 0xe) << 0x34) >> 0x34) + iVar6

                     );

LAB_004062e0:

    if (unaff_s7 == unaff_s8) {

      iVar6 = 2;

    }

    else if (unaff_s7 < unaff_s8) {

      iVar6 = 1;

    }

    else {

      iVar6 = 0;

    }

  }

  else {

    if (lVar7 == 1) {

      sVar5 = datGetDaysSinceApr5();

      unaff_s7 = (long)sVar5;

      unaff_s8 = clndGetDaysSinceStartFromDate(((long)*(short *)(puVar4 + sVar1 * 0x40 + 0xe) << 0x34) >> 0x3a,

                              ((long)(char)puVar4[sVar1 * 0x40 + 0xe] << 0x3a) >> 0x3a);

      goto LAB_004062e0;

    }

    if (lVar7 != 0) goto LAB_004062e0;

    iVar6 = 3;

  }

  if (iVar6 != 1) {

    if (iVar6 == 3) {

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,iVar11 + 0x61,0);

      goto LAB_00406468;

    }

    if (iVar6 == 2) {

      FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,iVar11 + 0x59,0);

      goto LAB_00406468;

    }

  }

  sprintf((char *)auStack_8,0x7cd9d8,

               (short)(((long)*(short *)(PTR_DAT_007cd8f0 + (short)puVar9[1] * 0x40 + 0xe) << 0x34)

                      >> 0x3a));

  uVar15 = auStack_30[iVar8];

  FUN_0040ebc0(0,iVar13 + 0x1f7,iVar12 + 0x6e,param_3 | uVar15,3,auStack_8,1);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,iVar11 + 0x3c,0);

  sprintf((char *)auStack_8,0x7cd9d8,

               ((long)(char)PTR_DAT_007cd8f0[(short)puVar9[1] * 0x40 + 0xe] << 0x3a) >> 0x3a);

  FUN_0040ebc0(0,iVar13 + 0x202,iVar12 + 0x6e,param_3 | uVar15,3,auStack_8,0);

LAB_00406468:

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,iVar11 + 0x44,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x4e,0);

  return;

}





















// FUN_004064E0 NONMATCHING
void FUN_004064e0(u64 param_1,u64 param_2,u32 param_3,int param_4)



{

  char cVar1;

  short sVar2;

  short sVar3;

  u8 *puVar4;

  int iVar5;

  int iVar6;

  u64 uVar7;

  int iVar8;

  long lVar9;

  int iVar10;

  float fVar11;

  u8 auStack_40 [4];

  u8 bStack_3c;

  u8 auStack_20 [32];

  

  puVar4 = (u8 *)(PTR_DAT_007cd8f0);

  if (*(int *)(param_4 + 0xc) != 0) {

    iVar8 = *(int *)(*(int *)(*(int *)(param_4 + 0xc) + 0x14) + 0x1c);

    sVar2 = *(short *)(iVar8 + 4);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x51,0);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x52,0);

    sVar3 = *(short *)(iVar8 + 4);


    fVar11 = DAT_007cad94 * (float)(int)param_3;

    if (2.1474836e+09 <= fVar11) {

      fVar11 = fVar11 - 2.1474836e+09;

    }

    iVar10 = (int)param_1;

    iVar6 = (int)param_2;

    FUN_003c7e20(0,iVar10 + 0x3d,iVar6 + 0x127,(int)fVar11 & 0xffU | 0x1e225d00,1,6,6,

                 *(u16 *)(PTR_DAT_007cd8f0 + sVar3 * 0x40 + 0x32));

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x53,0);

    if (puVar4[sVar2 * 0x40 + 0x26] == '\x03') {

      sprintf((char *)auStack_20,0x7cd900,*(u32 *)(puVar4 + sVar2 * 0x40 + 0x28));

      iVar6 = FUN_0040ebc0(0,iVar10 + 0x7b,iVar6 + 0x184,param_3 | 0xffffffffffffff00,3,auStack_20,8

                          );

      FUN_0040e3c0(0,iVar10 + 0x85 + iVar6,param_2,param_3 & 0xff,0x58,0);

    }

    else if (puVar4[sVar2 * 0x40 + 0x26] == '\0') {


      FUN_0040e3c0(0,iVar10 + 0x77,iVar6 + 0x178,param_3 & 0xff,0,(u32)bStack_3c * 2 + 1);

      cVar1 = puVar4[sVar2 * 0x40 + 0x26];

      if (cVar1 == '\x04') {

        sprintf((char *)auStack_20,0x6af3d0);

      }

      else if (cVar1 == '\x03') {

        sprintf((char *)auStack_20,0x7cd900,*(u32 *)(puVar4 + sVar2 * 0x40 + 0x28));

      }

      else if (cVar1 == '\x02') {

        sprintf((char *)auStack_20,0x7cd9d0,

                     DAT_007ce4e4 + *(short *)(puVar4 + sVar2 * 0x40 + 0x28) * 0x11);

      }

      else if (cVar1 == '\x01') {

        sprintf((char *)auStack_20,0x7cd9d0,

                     DAT_007ce4e8 +

                     *(short *)(puVar4 + sVar2 * 0x40 + 0x28) * 0x12 +

                     (int)*(short *)(puVar4 + sVar2 * 0x40 + 0x28));

      }

      else if (cVar1 == '\0') {

        uVar7 = func_00171110(*(u16 *)(puVar4 + sVar2 * 0x40 + 0x28),

                             ((long)(char)puVar4[sVar2 * 0x40 + 0x2a] << 0x3c) >> 0x3c);

        sprintf((char *)auStack_20,0x7cd9d0,uVar7);

      }

      iVar5 = FUN_003b32d0(0,iVar10 + 0x9a,iVar6 + 0x182,param_3 | 0xffffffffffffff00,6,1,auStack_20

                           ,0x11,0x78);

      FUN_0040e3c0(0,iVar10 + iVar5 + 0xa4,param_2,param_3 & 0xff,0x54,0);

      sprintf((char *)auStack_20,0x7cd900,puVar4[sVar2 * 0x40 + 0x27]);

      FUN_0040ebc0(0,iVar10 + iVar5 + 199,iVar6 + 0x184,param_3 | 0xffffffffffffff00,3,auStack_20,2)

      ;

    }

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x55,0);

    FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,0x56,0);

    sVar2 = *(short *)(PTR_DAT_007cd8f0 + *(short *)(iVar8 + 4) * 0x40 + 0x3c);

    lVar9 = 0;

    while (lVar9 < 5) {

      iVar8 = (int)lVar9;

      if (lVar9 < sVar2) {

        FUN_0040e3c0(0,iVar10 + iVar8 * 0x17,param_2,param_3 & 0xff,0x57,1);

      }

      else {

        FUN_0040e3c0(0,iVar10 + iVar8 * 0x17,param_2,param_3 & 0xff,0x57,0);

      }

      lVar9 = (long)(iVar8 + 1);

    }

  }

  return;

}

// FUN_00406AA0 NONMATCHING


void FUN_00406aa0(u64 param_1,u64 param_2,u32 param_3)



{

  u32 uVar1;

  long lVar2;

  u64 uVar3;

  int iVar4;

  int iVar5;

  float fVar6;

  u8 auStack_8 [8];

  

  uVar1 = datGetTime();

  uVar1 = uVar1 & 0xff;

  if (uVar1 == 8) {

    uVar1 = 9;

  }

  lVar2 = clndIsHolidayOrSunday();

  if ((lVar2 == 1) && (uVar1 - 2 < 4)) {

    uVar1 = 8;

  }

  iVar4 = uVar1 - 1;

  if (iVar4 < 0) {

    iVar4 = 0;

  }

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,3,0);

  FUN_0040e3c0(0,param_1,param_2,param_3 & 0xff,iVar4 + 5,0);

  uVar3 = clndGetCurrentMonth();

  sprintf((char *)auStack_8,0x7cd900,uVar3);

  fVar6 = DAT_007cad74 * (float)(int)param_3;

  if (fVar6 < 2.1474836e+09) {

    uVar1 = (u32)fVar6;

  }

  else {

    uVar1 = (int)(fVar6 - 2.1474836e+09) | 0x80000000;

  }

  iVar5 = (int)param_1;

  iVar4 = (int)param_2;

  FUN_0040ebc0(0,iVar5 + 0x212,iVar4 + 0x1b,uVar1 | 0xffffff00,3,auStack_8,2);

  FUN_0040e3c0(0,iVar5 + 0x60,param_2,param_3 & 0xff,0xe,0);

  uVar3 = clndGetCurrentDay();

  sprintf((char *)auStack_8,0x7cd900,uVar3);

  FUN_0040ebc0(0,iVar5 + 0x23c,iVar4 + 0x1b,uVar1 | 0xffffff00,3,auStack_8,2);

  uVar3 = clndGetCurrentWeekDay();

  FUN_0040e3c0(0,iVar5 + 0x60,iVar4 + 1,param_3 & 0xff,0xf,uVar3);

  return;

}

// FUN_00406CA0 NONMATCHING


void FUN_00406ca0(u64 param_1,u64 param_2,int *param_3)



{

  int iVar1;

  u32 *puVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  u32 uVar7;

  

  iVar3 = (int)param_2;

  iVar6 = *param_3 + (int)*(short *)(iVar3 + 0x14);

  iVar5 = param_3[1] + (int)*(short *)(iVar3 + 0x16);

  uVar7 = ((int)(short)param_3[2] * (int)*(short *)(iVar3 + 0x26)) / 0xff;

  if (uVar7 != 0) {

    iVar4 = param_3[3];

    iVar1 = *(int *)(iVar4 + 0x24);

    puVar2 = *(u32 **)(iVar1 + 0x44);

    switch(*(u32 *)(iVar3 + 0x10)) {

    case 0:

      if ((*puVar2 & 1) == 0) {


      }

      else {

        iVar3 = *(int *)(*(int *)(param_3[4] + 0x14) + 0x1c);

        iVar4 = (u32)((*(u16 *)((int)param_3 + 10) & 1) != 0) * 4;

        FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,*(short *)(iVar3 + 6) + iVar4 + 0x2c,0);

        FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,*(short *)(iVar3 + 6) + iVar4 + 0x34,0);

      }

      break;

    case 1:

      if ((*puVar2 & 1) != 0) {

        uVar7 = (u32)((float)(int)uVar7 * DAT_007cad74);

        if (*(int *)(iVar4 + 0xc) != param_3[4]) {

          uVar7 = (u32)((float)(int)uVar7 * 0.5);

        }

        FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x4f,0);

        FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x50,0);

      }

      break;

    case 2:

      FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x22,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x23,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x24,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x25,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x26,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x27,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x28,0);

      break;

    case 3:


      break;

    case 4:


      break;

    case 5:

      if ((*puVar2 & 2) == 0) {

        FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x1c,0);

        FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x1d,0);

      }

      else {

        FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x69,0);

        FUN_0040e3c0(0,iVar6,iVar5,uVar7 & 0xff,0x6a,0);

      }

      break;

    case 6:

      FUN_0040e3c0(0,0,0,uVar7 & 0xff,0x1b,0);

      break;

    case 7:

      if (*(u32 *)(iVar1 + 0x20) <= (u32)*(u16 *)(iVar4 + 0x10)) {

        iVar3 = *(int *)(iVar1 + 0x28);

        FUN_0040e3f0(0,0,0x3f800000,0x3f800000,0,0,uVar7 & 0xff,0x29,0,0,0);

        FUN_0040e3f0(0,0,0x3f800000,0x3f800000,0,0,uVar7 & 0xff,0x2a,0,0,0);

        FUN_0040e3f0(0,0,0x3f800000,0x3f800000,0x269,(iVar3 * 0x4e) / 0xffff + 0x65,uVar7 & 0xff,

                     0x2b,0,0,0);

      }

    }

  }

  return;

}

// FUN_00407180


void FUN_00407180(u32 param_1,u32 param_2,u16 param_3,int param_4)
{
  int *puVar1;
  int iVar2;
  struct {
    u32 param1;
    u32 param2;
    u16 param3;
    u16 pad;
    u32 param4;
    u32 zero;
  } data;

  puVar1 = *(int **)(*(int *)(param_4 + 0x24) + 0x44);
  iVar2 = puVar1[2];
  data.param1 = param_1;
  data.param2 = param_2;
  data.param3 = param_3;
  data.param4 = (u32)param_4;
  data.zero = 0;
  FUN_003e0680_typed(iVar2,(code)FUN_00406ca0,&data);
  *puVar1 = *puVar1 | 1;
  FUN_003c4e70_u64(param_4);
  *puVar1 = *puVar1 & 0xfffffffe;
  return;
}

// FUN_00407210


void FUN_00407210(u32 param_1,u32 param_2,u16 param_3,int param_4,int param_5)
{
  int uVar1;
  struct {
    u32 param1;
    u32 param2;
    u16 param3;
    s16 flags;
    int param4;
    int param5;
  } data;

  uVar1 = *(int *)(*(int *)(*(int *)(param_5 + 0x14) + 0x1c) + 8);
  memset_typed(&data,0,0x18);
  if (*(int *)(param_4 + 0xc) == param_5) {
    data.flags = data.flags | 1;
  }
  data.param1 = param_1;
  data.param2 = param_2;
  data.param3 = param_3;
  data.param4 = param_4;
  data.param5 = param_5;
  FUN_003e0680_typed(uVar1,(code)FUN_00406ca0,&data);
  return;
}

// FUN_004072D0 NONMATCHING


void FUN_004072d0(int param_1,long param_2,long param_3)



{

  u32 uVar1;

  u32 uVar2;

  u32 uVar3;

  u64 uVar4;

  int iVar5;

  int iVar6;

  u32 *puVar7;

  u32 *puVar8;

  u32 auStack_5fa0 [6];

  u16 uStack_5f88;

  u32 uStack_5f84;

  u16 uStack_5f6c;

  u32 uStack_5f68;

  u16 uStack_5f50;

  u32 uStack_5f4c;

  u16 uStack_5f34;

  u32 uStack_5f30;

  u16 uStack_5f18;

  u32 uStack_5f14;

  u16 uStack_5efc;

  u32 uStack_5ef8;

  u16 uStack_5ee0;

  u32 uStack_5edc;

  u16 uStack_5ec4;

  u32 uStack_5ec0;

  u16 uStack_5ea8;

  u32 uStack_5ea4;

  u16 uStack_5e8c;

  u32 uStack_5e88;

  u16 uStack_5e70;

  u32 uStack_5e6c;

  u16 uStack_5e54;

  u32 uStack_5e50;

  u16 uStack_5e38;

  u32 uStack_5e34;

  u16 uStack_5e1c;

  u32 uStack_5e18;

  u16 uStack_5e00;

  u32 uStack_5dfc;

  u16 uStack_5de4;

  u32 uStack_5de0;

  u16 uStack_5dc8;

  u32 uStack_5dc4;

  u16 uStack_5dac;

  u32 uStack_5da8;

  u16 uStack_5d90;

  u32 uStack_5d8c;

  u16 uStack_5d74;

  u32 uStack_5d70;

  u16 uStack_5d58;

  u32 uStack_5d54;

  u16 uStack_5d3c;

  u32 uStack_5d38;

  u16 uStack_5d20;

  u32 uStack_5d1c;

  u16 uStack_5d04;

  u32 uStack_5d00;

  u16 uStack_5ce8;

  u32 uStack_5ce4;

  u16 uStack_5ccc;

  u32 uStack_5cc8;

  u16 uStack_5cb0;

  u32 auStack_5cac [6];

  u16 uStack_5c94;

  u32 auStack_5c90 [6];

  u16 uStack_5c78;

  u32 uStack_5c74;

  u16 uStack_5c5c;

  u32 uStack_5c58;

  u16 uStack_5c40;

  u32 uStack_5c3c;

  u16 uStack_5c24;

  u32 uStack_5c20;

  u16 uStack_5c08;

  u32 uStack_5c04;

  u16 uStack_5bec;

  u32 uStack_5be8;

  u16 uStack_5bd0;

  u32 uStack_5bcc;

  u16 uStack_5bb4;

  u32 uStack_5bb0;

  u16 uStack_5b98;

  u32 uStack_5b94;

  u16 uStack_5b7c;

  u32 uStack_5b78;

  u16 uStack_5b60;

  u32 uStack_5b5c;

  u16 uStack_5b44;

  u32 uStack_5b40;

  u16 uStack_5b28;

  u32 uStack_5b24;

  u16 uStack_5b0c;

  u32 uStack_5b08;

  u16 uStack_5af0;

  u32 uStack_5aec;

  u16 uStack_5ad4;

  u32 uStack_5ad0;

  u16 uStack_5ab8;

  u32 uStack_5ab4;

  u16 uStack_5a9c;

  u32 uStack_5a98;

  u16 uStack_5a80;

  u32 uStack_5a7c;

  u16 uStack_5a64;

  u32 uStack_5a60;

  u16 uStack_5a48;

  u32 uStack_5a44;

  u16 uStack_5a2c;

  u32 uStack_5a28;

  u16 uStack_5a10;

  u32 uStack_5a0c;

  u16 uStack_59f4;

  u32 uStack_59f0;

  u16 uStack_59d8;

  u32 uStack_59d4;

  u16 uStack_59bc;

  u32 auStack_59b8 [6];

  u16 uStack_59a0;

  u32 uStack_599c;

  u16 uStack_5984;

  u32 auStack_5980 [6];

  u16 uStack_5968;

  u32 uStack_5964;

  u16 uStack_594c;

  u32 uStack_5948;

  u16 uStack_5930;

  u32 uStack_592c;

  u16 uStack_5914;

  u32 uStack_5910;

  u16 uStack_58f8;

  u32 uStack_58f4;

  u16 uStack_58dc;

  u32 uStack_58d8;

  u16 uStack_58c0;

  u32 uStack_58bc;

  u16 uStack_58a4;

  u32 uStack_58a0;

  u16 uStack_5888;

  u32 uStack_5884;

  u16 uStack_586c;

  u32 uStack_5868;

  u16 uStack_5850;

  u32 uStack_584c;

  u16 uStack_5834;

  u32 uStack_5830;

  u16 uStack_5818;

  u32 uStack_5814;

  u16 uStack_57fc;

  u32 uStack_57f8;

  u16 uStack_57e0;

  u32 uStack_57dc;

  u16 uStack_57c4;

  u32 uStack_57c0;

  u16 uStack_57a8;

  u32 uStack_57a4;

  u16 uStack_578c;

  u32 uStack_5788;

  u16 uStack_5770;

  u32 uStack_576c;

  u16 uStack_5754;

  u32 uStack_5750;

  u16 uStack_5738;

  u32 uStack_5734;

  u16 uStack_571c;

  u32 uStack_5718;

  u16 uStack_5700;

  u32 uStack_56fc;

  u16 uStack_56e4;

  u32 uStack_56e0;

  u16 uStack_56c8;

  u32 auStack_56c4 [6];

  u16 uStack_56ac;

  u32 uStack_56a8;

  u16 uStack_5690;

  u32 uStack_568c;

  u16 uStack_5674;

  u32 auStack_5670 [6];

  u16 uStack_5658;

  u32 uStack_5654;

  u16 uStack_563c;

  u32 uStack_5638;

  u16 uStack_5620;

  u32 uStack_561c;

  u16 uStack_5604;

  u32 uStack_5600;

  u16 uStack_55e8;

  u32 uStack_55e4;

  u16 uStack_55cc;

  u32 uStack_55c8;

  u16 uStack_55b0;

  u32 uStack_55ac;

  u16 uStack_5594;

  u32 uStack_5590;

  u16 uStack_5578;

  u32 uStack_5574;

  u16 uStack_555c;

  u32 uStack_5558;

  u16 uStack_5540;

  u32 uStack_553c;

  u16 uStack_5524;

  u32 uStack_5520;

  u16 uStack_5508;

  u32 uStack_5504;

  u16 uStack_54ec;

  u32 uStack_54e8;

  u16 uStack_54d0;

  u32 uStack_54cc;

  u16 uStack_54b4;

  u32 uStack_54b0;

  u16 uStack_5498;

  u32 uStack_5494;

  u16 uStack_547c;

  u32 uStack_5478;

  u16 uStack_5460;

  u32 uStack_545c;

  u16 uStack_5444;

  u32 uStack_5440;

  u16 uStack_5428;

  u32 uStack_5424;

  u16 uStack_540c;

  u32 uStack_5408;

  u16 uStack_53f0;

  u32 uStack_53ec;

  u16 uStack_53d4;

  u32 auStack_53d0 [6];

  u16 uStack_53b8;

  u32 uStack_53b4;

  u16 uStack_539c;

  u32 uStack_5398;

  u16 uStack_5380;

  u32 uStack_537c;

  u16 uStack_5364;

  u32 auStack_5360 [6];

  u16 uStack_5348;

  u32 uStack_5344;

  u16 uStack_532c;

  u32 uStack_5328;

  u16 uStack_5310;

  u32 uStack_530c;

  u16 uStack_52f4;

  u32 uStack_52f0;

  u16 uStack_52d8;

  u32 uStack_52d4;

  u16 uStack_52bc;

  u32 uStack_52b8;

  u16 uStack_52a0;

  u32 uStack_529c;

  u16 uStack_5284;

  u32 uStack_5280;

  u16 uStack_5268;

  u32 uStack_5264;

  u16 uStack_524c;

  u32 uStack_5248;

  u16 uStack_5230;

  u32 uStack_522c;

  u16 uStack_5214;

  u32 uStack_5210;

  u16 uStack_51f8;

  u32 uStack_51f4;

  u16 uStack_51dc;

  u32 uStack_51d8;

  u16 uStack_51c0;

  u32 uStack_51bc;

  u16 uStack_51a4;

  u32 uStack_51a0;

  u16 uStack_5188;

  u32 uStack_5184;

  u16 uStack_516c;

  u32 uStack_5168;

  u16 uStack_5150;

  u32 uStack_514c;

  u16 uStack_5134;

  u32 uStack_5130;

  u16 uStack_5118;

  u32 uStack_5114;

  u16 uStack_50fc;

  u32 uStack_50f8;

  u16 uStack_50e0;

  u32 auStack_50dc [6];

  u16 uStack_50c4;

  u32 uStack_50c0;

  u16 uStack_50a8;

  u32 uStack_50a4;

  u16 uStack_508c;

  u32 uStack_5088;

  u16 uStack_5070;

  u32 uStack_506c;

  u16 uStack_5054;

  u32 auStack_5050 [6];

  u16 uStack_5038;

  u32 uStack_5034;

  u16 uStack_501c;

  u32 uStack_5018;

  u16 uStack_5000;

  u32 uStack_4ffc;

  u16 uStack_4fe4;

  u32 uStack_4fe0;

  u16 uStack_4fc8;

  u32 uStack_4fc4;

  u16 uStack_4fac;

  u32 uStack_4fa8;

  u16 uStack_4f90;

  u32 uStack_4f8c;

  u16 uStack_4f74;

  u32 uStack_4f70;

  u16 uStack_4f58;

  u32 uStack_4f54;

  u16 uStack_4f3c;

  u32 uStack_4f38;

  u16 uStack_4f20;

  u32 uStack_4f1c;

  u16 uStack_4f04;

  u32 uStack_4f00;

  u16 uStack_4ee8;

  u32 uStack_4ee4;

  u16 uStack_4ecc;

  u32 uStack_4ec8;

  u16 uStack_4eb0;

  u32 uStack_4eac;

  u16 uStack_4e94;

  u32 uStack_4e90;

  u16 uStack_4e78;

  u32 uStack_4e74;

  u16 uStack_4e5c;

  u32 uStack_4e58;

  u16 uStack_4e40;

  u32 uStack_4e3c;

  u16 uStack_4e24;

  u32 uStack_4e20;

  u16 uStack_4e08;

  u32 uStack_4e04;

  u16 uStack_4dec;

  u32 auStack_4de8 [6];

  u16 uStack_4dd0;

  u32 uStack_4dcc;

  u16 uStack_4db4;

  u32 uStack_4db0;

  u16 uStack_4d98;

  u32 uStack_4d94;

  u16 uStack_4d7c;

  u32 uStack_4d78;

  u16 uStack_4d60;

  u32 uStack_4d5c;

  u16 uStack_4d44;

  u32 auStack_4d40 [6];

  u16 uStack_4d28;

  u32 uStack_4d24;

  u16 uStack_4d0c;

  u32 uStack_4d08;

  u16 uStack_4cf0;

  u32 uStack_4cec;

  u16 uStack_4cd4;

  u32 uStack_4cd0;

  u16 uStack_4cb8;

  u32 uStack_4cb4;

  u16 uStack_4c9c;

  u32 uStack_4c98;

  u16 uStack_4c80;

  u32 uStack_4c7c;

  u16 uStack_4c64;

  u32 uStack_4c60;

  u16 uStack_4c48;

  u32 uStack_4c44;

  u16 uStack_4c2c;

  u32 uStack_4c28;

  u16 uStack_4c10;

  u32 uStack_4c0c;

  u16 uStack_4bf4;

  u32 uStack_4bf0;

  u16 uStack_4bd8;

  u32 auStack_4bd4 [6];

  u16 uStack_4bbc;

  u32 uStack_4bb8;

  u16 uStack_4ba0;

  u32 uStack_4b9c;

  u16 uStack_4b84;

  u32 uStack_4b80;

  u16 uStack_4b68;

  u32 uStack_4b64;

  u16 uStack_4b4c;

  u32 uStack_4b48;

  u16 uStack_4b30;

  u32 uStack_4b2c;

  u16 uStack_4b14;

  u32 uStack_4b10;

  u16 uStack_4af8;

  u32 uStack_4af4;

  u16 uStack_4adc;

  u32 uStack_4ad8;

  u16 uStack_4ac0;

  u32 uStack_4abc;

  u16 uStack_4aa4;

  u32 uStack_4aa0;

  u16 uStack_4a88;

  u32 uStack_4a84;

  u16 uStack_4a6c;

  u32 uStack_4a68;

  u16 uStack_4a50;

  u32 uStack_4a4c;

  u16 uStack_4a34;

  u32 auStack_4a30 [6];

  u16 uStack_4a18;

  u32 uStack_4a14;

  u16 uStack_49fc;

  u32 uStack_49f8;

  u16 uStack_49e0;

  u32 uStack_49dc;

  u16 uStack_49c4;

  u32 uStack_49c0;

  u16 uStack_49a8;

  u32 uStack_49a4;

  u16 uStack_498c;

  u32 uStack_4988;

  u16 uStack_4970;

  u32 uStack_496c;

  u16 uStack_4954;

  u32 uStack_4950;

  u16 uStack_4938;

  u32 uStack_4934;

  u16 uStack_491c;

  u32 uStack_4918;

  u16 uStack_4900;

  u32 uStack_48fc;

  u16 uStack_48e4;

  u32 uStack_48e0;

  u16 uStack_48c8;

  u32 uStack_48c4;

  u16 uStack_48ac;

  u32 uStack_48a8;

  u16 uStack_4890;

  u32 uStack_488c;

  u16 uStack_4874;

  u32 uStack_4870;

  u16 uStack_4858;

  u32 uStack_4854;

  u16 uStack_483c;

  u32 uStack_4838;

  u16 uStack_4820;

  u32 uStack_481c;

  u16 uStack_4804;

  u32 uStack_4800;

  u16 uStack_47e8;

  u32 auStack_47e4 [6];

  u16 uStack_47cc;

  u32 uStack_47c8;

  u16 uStack_47b0;

  u32 uStack_47ac;

  u16 uStack_4794;

  u32 uStack_4790;

  u16 uStack_4778;

  u32 uStack_4774;

  u16 uStack_475c;

  u32 uStack_4758;

  u16 uStack_4740;

  u32 uStack_473c;

  u16 uStack_4724;

  u32 auStack_4720 [6];

  u16 uStack_4708;

  u32 uStack_4704;

  u16 uStack_46ec;

  u32 uStack_46e8;

  u16 uStack_46d0;

  u32 uStack_46cc;

  u16 uStack_46b4;

  u32 uStack_46b0;

  u16 uStack_4698;

  u32 uStack_4694;

  u16 uStack_467c;

  u32 uStack_4678;

  u16 uStack_4660;

  u32 uStack_465c;

  u16 uStack_4644;

  u32 uStack_4640;

  u16 uStack_4628;

  u32 uStack_4624;

  u16 uStack_460c;

  u32 uStack_4608;

  u16 uStack_45f0;

  u32 uStack_45ec;

  u16 uStack_45d4;

  u32 uStack_45d0;

  u16 uStack_45b8;

  u32 uStack_45b4;

  u16 uStack_459c;

  u32 uStack_4598;

  u16 uStack_4580;

  u32 uStack_457c;

  u16 uStack_4564;

  u32 uStack_4560;

  u16 uStack_4548;

  u32 uStack_4544;

  u16 uStack_452c;

  u32 uStack_4528;

  u16 uStack_4510;

  u32 auStack_450c [6];

  u16 uStack_44f4;

  u32 uStack_44f0;

  u16 uStack_44d8;

  u32 uStack_44d4;

  u16 uStack_44bc;

  u32 uStack_44b8;

  u16 uStack_44a0;

  u32 uStack_449c;

  u16 uStack_4484;

  u32 uStack_4480;

  u16 uStack_4468;

  u32 uStack_4464;

  u16 uStack_444c;

  u32 uStack_4448;

  u16 uStack_4430;

  u32 uStack_442c;

  u16 uStack_4414;

  u32 auStack_4410 [6];

  u16 uStack_43f8;

  u32 uStack_43f4;

  u16 uStack_43dc;

  u32 uStack_43d8;

  u16 uStack_43c0;

  u32 uStack_43bc;

  u16 uStack_43a4;

  u32 uStack_43a0;

  u16 uStack_4388;

  u32 uStack_4384;

  u16 uStack_436c;

  u32 uStack_4368;

  u16 uStack_4350;

  u32 uStack_434c;

  u16 uStack_4334;

  u32 uStack_4330;

  u16 uStack_4318;

  u32 uStack_4314;

  u16 uStack_42fc;

  u32 uStack_42f8;

  u16 uStack_42e0;

  u32 uStack_42dc;

  u16 uStack_42c4;

  u32 auStack_42c0 [6];

  u16 uStack_42a8;

  u32 uStack_42a4;

  u16 uStack_428c;

  u32 uStack_4288;

  u16 uStack_4270;

  u32 uStack_426c;

  u16 uStack_4254;

  u32 uStack_4250;

  u16 uStack_4238;

  u32 uStack_4234;

  u16 uStack_421c;

  u32 uStack_4218;

  u16 uStack_4200;

  u32 uStack_41fc;

  u16 uStack_41e4;

  u32 uStack_41e0;

  u16 uStack_41c8;

  u32 uStack_41c4;

  u16 uStack_41ac;

  u32 uStack_41a8;

  u16 uStack_4190;

  u32 uStack_418c;

  u16 uStack_4174;

  u32 uStack_4170;

  u16 uStack_4158;

  u32 uStack_4154;

  u16 uStack_413c;

  u32 uStack_4138;

  u16 uStack_4120;

  u32 uStack_411c;

  u16 uStack_4104;

  u32 auStack_4100 [6];

  u16 uStack_40e8;

  u32 uStack_40e4;

  u16 uStack_40cc;

  u32 uStack_40c8;

  u16 uStack_40b0;

  u32 uStack_40ac;

  u16 uStack_4094;

  u32 uStack_4090;

  u16 uStack_4078;

  u32 uStack_4074;

  u16 uStack_405c;

  u32 uStack_4058;

  u16 uStack_4040;

  u32 uStack_403c;

  u16 uStack_4024;

  u32 uStack_4020;

  u16 uStack_4008;

  u32 uStack_4004;

  u16 uStack_3fec;

  u32 uStack_3fe8;

  u16 uStack_3fd0;

  u32 uStack_3fcc;

  u16 uStack_3fb4;

  u32 uStack_3fb0;

  u16 uStack_3f98;

  u32 uStack_3f94;

  u16 uStack_3f7c;

  u32 uStack_3f78;

  u16 uStack_3f60;

  u32 uStack_3f5c;

  u16 uStack_3f44;

  u32 uStack_3f40;

  u16 uStack_3f28;

  u32 uStack_3f24;

  u16 uStack_3f0c;

  u32 uStack_3f08;

  u16 uStack_3ef0;

  u32 uStack_3eec;

  u16 uStack_3ed4;

  u32 auStack_3ed0 [6];

  u16 uStack_3eb8;

  u32 uStack_3eb4;

  u16 uStack_3e9c;

  u32 uStack_3e98;

  u16 uStack_3e80;

  u32 uStack_3e7c;

  u16 uStack_3e64;

  u32 uStack_3e60;

  u16 uStack_3e48;

  u32 uStack_3e44;

  u16 uStack_3e2c;

  u32 uStack_3e28;

  u16 uStack_3e10;

  u32 uStack_3e0c;

  u16 uStack_3df4;

  u32 auStack_3df0 [6];

  u16 uStack_3dd8;

  u32 uStack_3dd4;

  u16 uStack_3dbc;

  u32 uStack_3db8;

  u16 uStack_3da0;

  u32 uStack_3d9c;

  u16 uStack_3d84;

  u32 uStack_3d80;

  u16 uStack_3d68;

  u32 uStack_3d64;

  u16 uStack_3d4c;

  u32 uStack_3d48;

  u16 uStack_3d30;

  u32 uStack_3d2c;

  u16 uStack_3d14;

  u32 uStack_3d10;

  u16 uStack_3cf8;

  u32 uStack_3cf4;

  u16 uStack_3cdc;

  u32 uStack_3cd8;

  u16 uStack_3cc0;

  u32 uStack_3cbc;

  u16 uStack_3ca4;

  u32 uStack_3ca0;

  u16 uStack_3c88;

  u32 uStack_3c84;

  u16 uStack_3c6c;

  u32 uStack_3c68;

  u16 uStack_3c50;

  u32 uStack_3c4c;

  u16 uStack_3c34;

  u32 uStack_3c30;

  u16 uStack_3c18;

  u32 uStack_3c14;

  u16 uStack_3bfc;

  u32 auStack_3bf8 [6];

  u16 uStack_3be0;

  u32 uStack_3bdc;

  u16 uStack_3bc4;

  u32 uStack_3bc0;

  u16 uStack_3ba8;

  u32 uStack_3ba4;

  u16 uStack_3b8c;

  u32 uStack_3b88;

  u16 uStack_3b70;

  u32 uStack_3b6c;

  u16 uStack_3b54;

  u32 uStack_3b50;

  u16 uStack_3b38;

  u32 uStack_3b34;

  u16 uStack_3b1c;

  u32 uStack_3b18;

  u16 uStack_3b00;

  u32 uStack_3afc;

  u16 uStack_3ae4;

  u32 auStack_3ae0 [6];

  u16 uStack_3ac8;

  u32 uStack_3ac4;

  u16 uStack_3aac;

  u32 uStack_3aa8;

  u16 uStack_3a90;

  u32 uStack_3a8c;

  u16 uStack_3a74;

  u32 uStack_3a70;

  u16 uStack_3a58;

  u32 uStack_3a54;

  u16 uStack_3a3c;

  u32 uStack_3a38;

  u16 uStack_3a20;

  u32 auStack_3a1c [6];

  u16 uStack_3a04;

  u32 uStack_3a00;

  u16 uStack_39e8;

  u32 uStack_39e4;

  u16 uStack_39cc;

  u32 uStack_39c8;

  u16 uStack_39b0;

  u32 uStack_39ac;

  u16 uStack_3994;

  u32 uStack_3990;

  u16 uStack_3978;

  u32 uStack_3974;

  u16 uStack_395c;

  u32 uStack_3958;

  u16 uStack_3940;

  u32 uStack_393c;

  u16 uStack_3924;

  u32 uStack_3920;

  u16 uStack_3908;

  u32 uStack_3904;

  u16 uStack_38ec;

  u32 uStack_38e8;

  u16 uStack_38d0;

  u32 uStack_38cc;

  u16 uStack_38b4;

  u32 uStack_38b0;

  u16 uStack_3898;

  u32 uStack_3894;

  u16 uStack_387c;

  u32 uStack_3878;

  u16 uStack_3860;

  u32 uStack_385c;

  u16 uStack_3844;

  u32 uStack_3840;

  u16 uStack_3828;

  u32 uStack_3824;

  u16 uStack_380c;

  u32 uStack_3808;

  u16 uStack_37f0;

  u32 uStack_37ec;

  u16 uStack_37d4;

  u32 auStack_37d0 [6];

  u16 uStack_37b8;

  u32 uStack_37b4;

  u16 uStack_379c;

  u32 uStack_3798;

  u16 uStack_3780;

  u32 uStack_377c;

  u16 uStack_3764;

  u32 uStack_3760;

  u16 uStack_3748;

  u32 uStack_3744;

  u16 uStack_372c;

  u32 uStack_3728;

  u16 uStack_3710;

  u32 uStack_370c;

  u16 uStack_36f4;

  u32 uStack_36f0;

  u16 uStack_36d8;

  u32 uStack_36d4;

  u16 uStack_36bc;

  u32 uStack_36b8;

  u16 uStack_36a0;

  u32 uStack_369c;

  u16 uStack_3684;

  u32 uStack_3680;

  u16 uStack_3668;

  u32 uStack_3664;

  u16 uStack_364c;

  u32 uStack_3648;

  u16 uStack_3630;

  u32 auStack_362c [6];

  u16 uStack_3614;

  u32 uStack_3610;

  u16 uStack_35f8;

  u32 uStack_35f4;

  u16 uStack_35dc;

  u32 uStack_35d8;

  u16 uStack_35c0;

  u32 uStack_35bc;

  u16 uStack_35a4;

  u32 uStack_35a0;

  u16 uStack_3588;

  u32 uStack_3584;

  u16 uStack_356c;

  u32 uStack_3568;

  u16 uStack_3550;

  u32 uStack_354c;

  u16 uStack_3534;

  u32 uStack_3530;

  u16 uStack_3518;

  u32 uStack_3514;

  u16 uStack_34fc;

  u32 uStack_34f8;

  u16 uStack_34e0;

  u32 uStack_34dc;

  u16 uStack_34c4;

  u32 auStack_34c0 [6];

  u16 uStack_34a8;

  u32 uStack_34a4;

  u16 uStack_348c;

  u32 uStack_3488;

  u16 uStack_3470;

  u32 uStack_346c;

  u16 uStack_3454;

  u32 uStack_3450;

  u16 uStack_3438;

  u32 uStack_3434;

  u16 uStack_341c;

  u32 uStack_3418;

  u16 uStack_3400;

  u32 uStack_33fc;

  u16 uStack_33e4;

  u32 uStack_33e0;

  u16 uStack_33c8;

  u32 uStack_33c4;

  u16 uStack_33ac;

  u32 uStack_33a8;

  u16 uStack_3390;

  u32 uStack_338c;

  u16 uStack_3374;

  u32 uStack_3370;

  u16 uStack_3358;

  u32 auStack_3354 [6];

  u16 uStack_333c;

  u32 uStack_3338;

  u16 uStack_3320;

  u32 uStack_331c;

  u16 uStack_3304;

  u32 uStack_3300;

  u16 uStack_32e8;

  u32 uStack_32e4;

  u16 uStack_32cc;

  u32 uStack_32c8;

  u16 uStack_32b0;

  u32 uStack_32ac;

  u16 uStack_3294;

  u32 uStack_3290;

  u16 uStack_3278;

  u32 uStack_3274;

  u16 uStack_325c;

  u32 uStack_3258;

  u16 uStack_3240;

  u32 uStack_323c;

  u16 uStack_3224;

  u32 uStack_3220;

  u16 uStack_3208;

  u32 uStack_3204;

  u16 uStack_31ec;

  u32 uStack_31e8;

  u16 uStack_31d0;

  u32 uStack_31cc;

  u16 uStack_31b4;

  u32 auStack_31b0 [6];

  u16 uStack_3198;

  u32 uStack_3194;

  u16 uStack_317c;

  u32 uStack_3178;

  u16 uStack_3160;

  u32 uStack_315c;

  u16 uStack_3144;

  u32 uStack_3140;

  u16 uStack_3128;

  u32 uStack_3124;

  u16 uStack_310c;

  u32 uStack_3108;

  u16 uStack_30f0;

  u32 uStack_30ec;

  u16 uStack_30d4;

  u32 uStack_30d0;

  u16 uStack_30b8;

  u32 uStack_30b4;

  u16 uStack_309c;

  u32 uStack_3098;

  u16 uStack_3080;

  u32 auStack_307c [6];

  u16 uStack_3064;

  u32 uStack_3060;

  u16 uStack_3048;

  u32 uStack_3044;

  u16 uStack_302c;

  u32 uStack_3028;

  u16 uStack_3010;

  u32 uStack_300c;

  u16 uStack_2ff4;

  u32 uStack_2ff0;

  u16 uStack_2fd8;

  u32 uStack_2fd4;

  u16 uStack_2fbc;

  u32 uStack_2fb8;

  u16 uStack_2fa0;

  u32 uStack_2f9c;

  u16 uStack_2f84;

  u32 uStack_2f80;

  u16 uStack_2f68;

  u32 uStack_2f64;

  u16 uStack_2f4c;

  u32 uStack_2f48;

  u16 uStack_2f30;

  u32 uStack_2f2c;

  u16 uStack_2f14;

  u32 uStack_2f10;

  u16 uStack_2ef8;

  u32 uStack_2ef4;

  u16 uStack_2edc;

  u32 uStack_2ed8;

  u16 uStack_2ec0;

  u32 uStack_2ebc;

  u16 uStack_2ea4;

  u32 auStack_2ea0 [6];

  u16 uStack_2e88;

  u32 uStack_2e84;

  u16 uStack_2e6c;

  u32 uStack_2e68;

  u16 uStack_2e50;

  u32 uStack_2e4c;

  u16 uStack_2e34;

  u32 uStack_2e30;

  u16 uStack_2e18;

  u32 uStack_2e14;

  u16 uStack_2dfc;

  u32 uStack_2df8;

  u16 uStack_2de0;

  u32 uStack_2ddc;

  u16 uStack_2dc4;

  u32 uStack_2dc0;

  u16 uStack_2da8;

  u32 auStack_2da4 [6];

  u16 uStack_2d8c;

  u32 uStack_2d88;

  u16 uStack_2d70;

  u32 uStack_2d6c;

  u16 uStack_2d54;

  u32 uStack_2d50;

  u16 uStack_2d38;

  u32 uStack_2d34;

  u16 uStack_2d1c;

  u32 uStack_2d18;

  u16 uStack_2d00;

  u32 uStack_2cfc;

  u16 uStack_2ce4;

  u32 uStack_2ce0;

  u16 uStack_2cc8;

  u32 uStack_2cc4;

  u16 uStack_2cac;

  u32 uStack_2ca8;

  u16 uStack_2c90;

  u32 uStack_2c8c;

  u16 uStack_2c74;

  u32 uStack_2c70;

  u16 uStack_2c58;

  u32 uStack_2c54;

  u16 uStack_2c3c;

  u32 uStack_2c38;

  u16 uStack_2c20;

  u32 uStack_2c1c;

  u16 uStack_2c04;

  u32 uStack_2c00;

  u16 uStack_2be8;

  u32 uStack_2be4;

  u16 uStack_2bcc;

  u32 uStack_2bc8;

  u16 uStack_2bb0;

  u32 uStack_2bac;

  u16 uStack_2b94;

  u32 auStack_2b90 [6];

  u16 uStack_2b78;

  u32 uStack_2b74;

  u16 uStack_2b5c;

  u32 uStack_2b58;

  u16 uStack_2b40;

  u32 uStack_2b3c;

  u16 uStack_2b24;

  u32 uStack_2b20;

  u16 uStack_2b08;

  u32 uStack_2b04;

  u16 uStack_2aec;

  u32 uStack_2ae8;

  u16 uStack_2ad0;

  u32 uStack_2acc;

  u16 uStack_2ab4;

  u32 uStack_2ab0;

  u16 uStack_2a98;

  u32 uStack_2a94;

  u16 uStack_2a7c;

  u32 uStack_2a78;

  u16 uStack_2a60;

  u32 uStack_2a5c;

  u16 uStack_2a44;

  u32 uStack_2a40;

  u16 uStack_2a28;

  u32 uStack_2a24;

  u16 uStack_2a0c;

  u32 uStack_2a08;

  u16 uStack_29f0;

  u32 uStack_29ec;

  u16 uStack_29d4;

  u32 uStack_29d0;

  u16 uStack_29b8;

  u32 auStack_29b4 [6];

  u16 uStack_299c;

  u32 uStack_2998;

  u16 uStack_2980;

  u32 uStack_297c;

  u16 uStack_2964;

  u32 uStack_2960;

  u16 uStack_2948;

  u32 uStack_2944;

  u16 uStack_292c;

  u32 uStack_2928;

  u16 uStack_2910;

  u32 uStack_290c;

  u16 uStack_28f4;

  u32 uStack_28f0;

  u16 uStack_28d8;

  u32 uStack_28d4;

  u16 uStack_28bc;

  u32 uStack_28b8;

  u16 uStack_28a0;

  u32 uStack_289c;

  u16 uStack_2884;

  u32 auStack_2880 [6];

  u16 uStack_2868;

  u32 uStack_2864;

  u16 uStack_284c;

  u32 uStack_2848;

  u16 uStack_2830;

  u32 uStack_282c;

  u16 uStack_2814;

  u32 uStack_2810;

  u16 uStack_27f8;

  u32 uStack_27f4;

  u16 uStack_27dc;

  u32 auStack_27d8 [6];

  u16 uStack_27c0;

  u32 uStack_27bc;

  u16 uStack_27a4;

  u32 uStack_27a0;

  u16 uStack_2788;

  u32 uStack_2784;

  u16 uStack_276c;

  u32 uStack_2768;

  u16 uStack_2750;

  u32 uStack_274c;

  u16 uStack_2734;

  u32 uStack_2730;

  u16 uStack_2718;

  u32 uStack_2714;

  u16 uStack_26fc;

  u32 uStack_26f8;

  u16 uStack_26e0;

  u32 uStack_26dc;

  u16 uStack_26c4;

  u32 uStack_26c0;

  u16 uStack_26a8;

  u32 uStack_26a4;

  u16 uStack_268c;

  u32 uStack_2688;

  u16 uStack_2670;

  u32 uStack_266c;

  u16 uStack_2654;

  u32 uStack_2650;

  u16 uStack_2638;

  u32 uStack_2634;

  u16 uStack_261c;

  u32 uStack_2618;

  u16 uStack_2600;

  u32 uStack_25fc;

  u16 uStack_25e4;

  u32 uStack_25e0;

  u16 uStack_25c8;

  u32 uStack_25c4;

  u16 uStack_25ac;

  u32 uStack_25a8;

  u16 uStack_2590;

  u32 uStack_258c;

  u16 uStack_2574;

  u32 auStack_2570 [6];

  u16 uStack_2558;

  u32 uStack_2554;

  u16 uStack_253c;

  u32 uStack_2538;

  u16 uStack_2520;

  u32 uStack_251c;

  u16 uStack_2504;

  u32 uStack_2500;

  u16 uStack_24e8;

  u32 uStack_24e4;

  u16 uStack_24cc;

  u32 uStack_24c8;

  u16 uStack_24b0;

  u32 uStack_24ac;

  u16 uStack_2494;

  u32 uStack_2490;

  u16 uStack_2478;

  u32 uStack_2474;

  u16 uStack_245c;

  u32 uStack_2458;

  u16 uStack_2440;

  u32 uStack_243c;

  u16 uStack_2424;

  u32 uStack_2420;

  u16 uStack_2408;

  u32 uStack_2404;

  u16 uStack_23ec;

  u32 auStack_23e8 [6];

  u16 uStack_23d0;

  u32 uStack_23cc;

  u16 uStack_23b4;

  u32 uStack_23b0;

  u16 uStack_2398;

  u32 uStack_2394;

  u16 uStack_237c;

  u32 uStack_2378;

  u16 uStack_2360;

  u32 uStack_235c;

  u16 uStack_2344;

  u32 uStack_2340;

  u16 uStack_2328;

  u32 uStack_2324;

  u16 uStack_230c;

  u32 uStack_2308;

  u16 uStack_22f0;

  u32 uStack_22ec;

  u16 uStack_22d4;

  u32 uStack_22d0;

  u16 uStack_22b8;

  u32 uStack_22b4;

  u16 uStack_229c;

  u32 uStack_2298;

  u16 uStack_2280;

  u32 uStack_227c;

  u16 uStack_2264;

  u32 auStack_2260 [6];

  u16 uStack_2248;

  u32 uStack_2244;

  u16 uStack_222c;

  u32 uStack_2228;

  u16 uStack_2210;

  u32 uStack_220c;

  u16 uStack_21f4;

  u32 uStack_21f0;

  u16 uStack_21d8;

  u32 uStack_21d4;

  u16 uStack_21bc;

  u32 uStack_21b8;

  u16 uStack_21a0;

  u32 uStack_219c;

  u16 uStack_2184;

  u32 uStack_2180;

  u16 uStack_2168;

  u32 uStack_2164;

  u16 uStack_214c;

  u32 uStack_2148;

  u16 uStack_2130;

  u32 uStack_212c;

  u16 uStack_2114;

  u32 auStack_2110 [6];

  u16 uStack_20f8;

  u32 uStack_20f4;

  u16 uStack_20dc;

  u32 uStack_20d8;

  u16 uStack_20c0;

  u32 uStack_20bc;

  u16 uStack_20a4;

  u32 uStack_20a0;

  u16 uStack_2088;

  u32 uStack_2084;

  u16 uStack_206c;

  u32 uStack_2068;

  u16 uStack_2050;

  u32 uStack_204c;

  u16 uStack_2034;

  u32 uStack_2030;

  u16 uStack_2018;

  u32 uStack_2014;

  u16 uStack_1ffc;

  u32 uStack_1ff8;

  u16 uStack_1fe0;

  u32 uStack_1fdc;

  u16 uStack_1fc4;

  u32 uStack_1fc0;

  u16 uStack_1fa8;

  u32 uStack_1fa4;

  u16 uStack_1f8c;

  u32 uStack_1f88;

  u16 uStack_1f70;

  u32 uStack_1f6c;

  u16 uStack_1f54;

  u32 auStack_1f50 [6];

  u16 uStack_1f38;

  u32 uStack_1f34;

  u16 uStack_1f1c;

  u32 uStack_1f18;

  u16 uStack_1f00;

  u32 uStack_1efc;

  u16 uStack_1ee4;

  u32 uStack_1ee0;

  u16 uStack_1ec8;

  u32 uStack_1ec4;

  u16 uStack_1eac;

  u32 uStack_1ea8;

  u16 uStack_1e90;

  u32 uStack_1e8c;

  u16 uStack_1e74;

  u32 uStack_1e70;

  u16 uStack_1e58;

  u32 uStack_1e54;

  u16 uStack_1e3c;

  u32 auStack_1e38 [6];

  u16 uStack_1e20;

  u32 uStack_1e1c;

  u16 uStack_1e04;

  u32 uStack_1e00;

  u16 uStack_1de8;

  u32 uStack_1de4;

  u16 uStack_1dcc;

  u32 uStack_1dc8;

  u16 uStack_1db0;

  u32 uStack_1dac;

  u16 uStack_1d94;

  u32 uStack_1d90;

  u16 uStack_1d78;

  u32 uStack_1d74;

  u16 uStack_1d5c;

  u32 uStack_1d58;

  u16 uStack_1d40;

  u32 uStack_1d3c;

  u16 uStack_1d24;

  u32 uStack_1d20;

  u16 uStack_1d08;

  u32 uStack_1d04;

  u16 uStack_1cec;

  u32 uStack_1ce8;

  u16 uStack_1cd0;

  u32 uStack_1ccc;

  u16 uStack_1cb4;

  u32 uStack_1cb0;

  u16 uStack_1c98;

  u32 uStack_1c94;

  u16 uStack_1c7c;

  u32 uStack_1c78;

  u16 uStack_1c60;

  u32 uStack_1c5c;

  u16 uStack_1c44;

  u32 auStack_1c40 [6];

  u16 uStack_1c28;

  u32 uStack_1c24;

  u16 uStack_1c0c;

  u32 uStack_1c08;

  u16 uStack_1bf0;

  u32 uStack_1bec;

  u16 uStack_1bd4;

  u32 uStack_1bd0;

  u16 uStack_1bb8;

  u32 uStack_1bb4;

  u16 uStack_1b9c;

  u32 uStack_1b98;

  u16 uStack_1b80;

  u32 uStack_1b7c;

  u16 uStack_1b64;

  u32 auStack_1b60 [6];

  u16 uStack_1b48;

  u32 uStack_1b44;

  u16 uStack_1b2c;

  u32 uStack_1b28;

  u16 uStack_1b10;

  u32 uStack_1b0c;

  u16 uStack_1af4;

  u32 uStack_1af0;

  u16 uStack_1ad8;

  u32 uStack_1ad4;

  u16 uStack_1abc;

  u32 uStack_1ab8;

  u16 uStack_1aa0;

  u32 uStack_1a9c;

  u16 uStack_1a84;

  u32 uStack_1a80;

  u16 uStack_1a68;

  u32 uStack_1a64;

  u16 uStack_1a4c;

  u32 uStack_1a48;

  u16 uStack_1a30;

  u32 uStack_1a2c;

  u16 uStack_1a14;

  u32 uStack_1a10;

  u16 uStack_19f8;

  u32 uStack_19f4;

  u16 uStack_19dc;

  u32 uStack_19d8;

  u16 uStack_19c0;

  u32 uStack_19bc;

  u16 uStack_19a4;

  u32 uStack_19a0;

  u16 uStack_1988;

  u32 uStack_1984;

  u16 uStack_196c;

  u32 uStack_1968;

  u16 uStack_1950;

  u32 uStack_194c;

  u16 uStack_1934;

  u32 auStack_1930 [6];

  u16 uStack_1918;

  u32 uStack_1914;

  u16 uStack_18fc;

  u32 uStack_18f8;

  u16 uStack_18e0;

  u32 uStack_18dc;

  u16 uStack_18c4;

  u32 uStack_18c0;

  u16 uStack_18a8;

  u32 uStack_18a4;

  u16 uStack_188c;

  u32 uStack_1888;

  u16 uStack_1870;

  u32 uStack_186c;

  u16 uStack_1854;

  u32 uStack_1850;

  u16 uStack_1838;

  u32 uStack_1834;

  u16 uStack_181c;

  u32 uStack_1818;

  u16 uStack_1800;

  u32 uStack_17fc;

  u16 uStack_17e4;

  u32 uStack_17e0;

  u16 uStack_17c8;

  u32 uStack_17c4;

  u16 uStack_17ac;

  u32 uStack_17a8;

  u16 uStack_1790;

  u32 uStack_178c;

  u16 uStack_1774;

  u32 auStack_1770 [6];

  u16 uStack_1758;

  u32 uStack_1754;

  u16 uStack_173c;

  u32 uStack_1738;

  u16 uStack_1720;

  u32 uStack_171c;

  u16 uStack_1704;

  u32 uStack_1700;

  u16 uStack_16e8;

  u32 uStack_16e4;

  u16 uStack_16cc;

  u32 uStack_16c8;

  u16 uStack_16b0;

  u32 uStack_16ac;

  u16 uStack_1694;

  u32 uStack_1690;

  u16 uStack_1678;

  u32 uStack_1674;

  u16 uStack_165c;

  u32 uStack_1658;

  u16 uStack_1640;

  u32 uStack_163c;

  u16 uStack_1624;

  u32 auStack_1620 [6];

  u16 uStack_1608;

  u32 uStack_1604;

  u16 uStack_15ec;

  u32 uStack_15e8;

  u16 uStack_15d0;

  u32 uStack_15cc;

  u16 uStack_15b4;

  u32 uStack_15b0;

  u16 uStack_1598;

  u32 auStack_1594 [6];

  u16 uStack_157c;

  u32 uStack_1578;

  u16 uStack_1560;

  u32 uStack_155c;

  u16 uStack_1544;

  u32 uStack_1540;

  u16 uStack_1528;

  u32 uStack_1524;

  u16 uStack_150c;

  u32 uStack_1508;

  u16 uStack_14f0;

  u32 uStack_14ec;

  u16 uStack_14d4;

  u32 uStack_14d0;

  u16 uStack_14b8;

  u32 uStack_14b4;

  u16 uStack_149c;

  u32 uStack_1498;

  u16 uStack_1480;

  u32 uStack_147c;

  u16 uStack_1464;

  u32 uStack_1460;

  u16 uStack_1448;

  u32 uStack_1444;

  u16 uStack_142c;

  u32 uStack_1428;

  u16 uStack_1410;

  u32 uStack_140c;

  u16 uStack_13f4;

  u32 uStack_13f0;

  u16 uStack_13d8;

  u32 uStack_13d4;

  u16 uStack_13bc;

  u32 uStack_13b8;

  u16 uStack_13a0;

  u32 uStack_139c;

  u16 uStack_1384;

  u32 uStack_1380;

  u16 uStack_1368;

  u32 uStack_1364;

  u16 uStack_134c;

  u32 uStack_1348;

  u16 uStack_1330;

  u32 uStack_132c;

  u16 uStack_1314;

  u32 auStack_1310 [6];

  u16 uStack_12f8;

  u32 uStack_12f4;

  u16 uStack_12dc;

  u32 uStack_12d8;

  u16 uStack_12c0;

  u32 uStack_12bc;

  u16 uStack_12a4;

  u32 auStack_12a0 [6];

  u16 uStack_1288;

  u32 uStack_1284;

  u16 uStack_126c;

  u32 uStack_1268;

  u16 uStack_1250;

  u32 uStack_124c;

  u16 uStack_1234;

  u32 uStack_1230;

  u16 uStack_1218;

  u32 uStack_1214;

  u16 uStack_11fc;

  u32 uStack_11f8;

  u16 uStack_11e0;

  u32 uStack_11dc;

  u16 uStack_11c4;

  u32 uStack_11c0;

  u16 uStack_11a8;

  u32 uStack_11a4;

  u16 uStack_118c;

  u32 uStack_1188;

  u16 uStack_1170;

  u32 uStack_116c;

  u16 uStack_1154;

  u32 uStack_1150;

  u16 uStack_1138;

  u32 uStack_1134;

  u16 uStack_111c;

  u32 uStack_1118;

  u16 uStack_1100;

  u32 uStack_10fc;

  u16 uStack_10e4;

  u32 uStack_10e0;

  u16 uStack_10c8;

  u32 uStack_10c4;

  u16 uStack_10ac;

  u32 uStack_10a8;

  u16 uStack_1090;

  u32 uStack_108c;

  u16 uStack_1074;

  u32 uStack_1070;

  u16 uStack_1058;

  u32 uStack_1054;

  u16 uStack_103c;

  u32 uStack_1038;

  u16 uStack_1020;

  u32 uStack_101c;

  u16 uStack_1004;

  u32 auStack_1000 [6];

  u16 uStack_fe8;

  u32 uStack_fe4;

  u16 uStack_fcc;

  u32 uStack_fc8;

  u16 uStack_fb0;

  u32 auStack_fac [6];

  u16 uStack_f94;

  u32 uStack_f90;

  u16 uStack_f78;

  u32 uStack_f74;

  u16 uStack_f5c;

  u32 uStack_f58;

  u16 uStack_f40;

  u32 uStack_f3c;

  u16 uStack_f24;

  u32 uStack_f20;

  u16 uStack_f08;

  u32 uStack_f04;

  u16 uStack_eec;

  u32 uStack_ee8;

  u16 uStack_ed0;

  u32 uStack_ecc;

  u16 uStack_eb4;

  u32 uStack_eb0;

  u16 uStack_e98;

  u32 uStack_e94;

  u16 uStack_e7c;

  u32 uStack_e78;

  u16 uStack_e60;

  u32 uStack_e5c;

  u16 uStack_e44;

  u32 uStack_e40;

  u16 uStack_e28;

  u32 uStack_e24;

  u16 uStack_e0c;

  u32 uStack_e08;

  u16 uStack_df0;

  u32 uStack_dec;

  u16 uStack_dd4;

  u32 uStack_dd0;

  u16 uStack_db8;

  u32 uStack_db4;

  u16 uStack_d9c;

  u32 uStack_d98;

  u16 uStack_d80;

  u32 uStack_d7c;

  u16 uStack_d64;

  u32 uStack_d60;

  u16 uStack_d48;

  u32 uStack_d44;

  u16 uStack_d2c;

  u32 uStack_d28;

  u16 uStack_d10;

  u32 uStack_d0c;

  u16 uStack_cf4;

  u32 auStack_cf0 [6];

  u16 uStack_cd8;

  u32 auStack_cd4 [6];

  u16 uStack_cbc;

  u32 uStack_cb8;

  u16 uStack_ca0;

  u32 uStack_c9c;

  u16 uStack_c84;

  u32 uStack_c80;

  u16 uStack_c68;

  u32 uStack_c64;

  u16 uStack_c4c;

  u32 uStack_c48;

  u16 uStack_c30;

  u32 uStack_c2c;

  u16 uStack_c14;

  u32 uStack_c10;

  u16 uStack_bf8;

  u32 uStack_bf4;

  u16 uStack_bdc;

  u32 uStack_bd8;

  u16 uStack_bc0;

  u32 uStack_bbc;

  u16 uStack_ba4;

  u32 uStack_ba0;

  u16 uStack_b88;

  u32 uStack_b84;

  u16 uStack_b6c;

  u32 uStack_b68;

  u16 uStack_b50;

  u32 uStack_b4c;

  u16 uStack_b34;

  u32 uStack_b30;

  u16 uStack_b18;

  u32 uStack_b14;

  u16 uStack_afc;

  u32 uStack_af8;

  u16 uStack_ae0;

  u32 uStack_adc;

  u16 uStack_ac4;

  u32 uStack_ac0;

  u16 uStack_aa8;

  u32 uStack_aa4;

  u16 uStack_a8c;

  u32 uStack_a88;

  u16 uStack_a70;

  u32 uStack_a6c;

  u16 uStack_a54;

  u32 uStack_a50;

  u16 uStack_a38;

  u32 uStack_a34;

  u16 uStack_a1c;

  u32 uStack_a18;

  u16 uStack_a00;

  u32 uStack_9fc;

  u16 uStack_9e4;

  u32 auStack_9e0 [6];

  u16 uStack_9c8;

  u32 uStack_9c4;

  u16 uStack_9ac;

  u32 auStack_9a8 [6];

  u16 uStack_990;

  u32 uStack_98c;

  u16 uStack_974;

  u32 uStack_970;

  u16 uStack_958;

  u32 uStack_954;

  u16 uStack_93c;

  u32 uStack_938;

  u16 uStack_920;

  u32 uStack_91c;

  u16 uStack_904;

  u32 uStack_900;

  u16 uStack_8e8;

  u32 uStack_8e4;

  u16 uStack_8cc;

  u32 uStack_8c8;

  u16 uStack_8b0;

  u32 uStack_8ac;

  u16 uStack_894;

  u32 uStack_890;

  u16 uStack_878;

  u32 uStack_874;

  u16 uStack_85c;

  u32 uStack_858;

  u16 uStack_840;

  u32 uStack_83c;

  u16 uStack_824;

  u32 uStack_820;

  u16 uStack_808;

  u32 uStack_804;

  u16 uStack_7ec;

  u32 uStack_7e8;

  u16 uStack_7d0;

  u32 uStack_7cc;

  u16 uStack_7b4;

  u32 uStack_7b0;

  u16 uStack_798;

  u32 uStack_794;

  u16 uStack_77c;

  u32 uStack_778;

  u16 uStack_760;

  u32 uStack_75c;

  u16 uStack_744;

  u32 uStack_740;

  u16 uStack_728;

  u32 uStack_724;

  u16 uStack_70c;

  u32 uStack_708;

  u16 uStack_6f0;

  u32 uStack_6ec;

  u16 uStack_6d4;

  u32 auStack_6d0 [6];

  u16 uStack_6b8;

  u32 uStack_6b4;

  u16 uStack_69c;

  u32 uStack_698;

  u16 uStack_680;

  u32 uStack_67c;

  u16 uStack_664;

  u32 uStack_660;

  u16 uStack_648;

  u32 uStack_644;

  u16 uStack_62c;

  u32 uStack_628;

  u16 uStack_610;

  u32 uStack_60c;

  u16 uStack_5f4;

  u32 uStack_5f0;

  u16 uStack_5d8;

  u32 uStack_5d4;

  u16 uStack_5bc;

  u32 uStack_5b8;

  u16 uStack_5a0;

  u32 uStack_59c;

  u16 uStack_584;

  u32 uStack_580;

  u16 uStack_568;

  u32 uStack_564;

  u16 uStack_54c;

  u32 uStack_548;

  u16 uStack_530;

  u32 uStack_52c;

  u16 uStack_514;

  u32 uStack_510;

  u16 uStack_4f8;

  u32 uStack_4f4;

  u16 uStack_4dc;

  u32 uStack_4d8;

  u16 uStack_4c0;

  u32 uStack_4bc;

  u16 uStack_4a4;

  u32 uStack_4a0;

  u16 uStack_488;

  u32 uStack_484;

  u16 uStack_46c;

  u32 uStack_468;

  u16 uStack_450;

  u32 uStack_44c;

  u16 uStack_434;

  u32 uStack_430;

  u16 uStack_418;

  u32 uStack_414;

  u16 uStack_3fc;

  u32 uStack_3f8;

  u16 uStack_3e0;

  u32 uStack_3dc;

  u16 uStack_3c4;

  u8 auStack_3c0 [4];

  u32 uStack_3bc;

  u8 auStack_3a0 [4];

  u32 uStack_39c;

  u8 auStack_380 [4];

  u32 uStack_37c;

  u8 auStack_360 [4];

  u32 uStack_35c;

  u8 auStack_340 [4];

  u32 uStack_33c;

  u8 auStack_320 [4];

  u32 uStack_31c;

  u8 auStack_300 [4];

  u32 uStack_2fc;

  u8 auStack_2e0 [4];

  u32 uStack_2dc;

  u8 auStack_2c0 [4];

  u32 uStack_2bc;

  u8 auStack_2a0 [4];

  u32 uStack_29c;

  u8 auStack_280 [4];

  u32 uStack_27c;

  u8 auStack_260 [4];

  u32 uStack_25c;

  u8 auStack_240 [4];

  u32 uStack_23c;

  u8 auStack_220 [4];

  u32 uStack_21c;

  u8 auStack_200 [4];

  u32 uStack_1fc;

  u8 auStack_1e0 [4];

  u32 uStack_1dc;

  u8 auStack_1c0 [4];

  u32 uStack_1bc;

  u8 auStack_1a0 [4];

  u32 uStack_19c;

  u8 auStack_180 [4];

  u32 uStack_17c;

  u8 auStack_160 [4];

  u32 uStack_15c;

  u8 auStack_140 [4];

  u32 uStack_13c;

  u8 auStack_120 [4];

  u32 uStack_11c;

  u8 auStack_100 [4];

  u32 uStack_fc;

  u8 auStack_e0 [4];

  u32 uStack_dc;

  u8 auStack_c0 [4];

  u32 uStack_bc;

  u8 auStack_a0 [4];

  u32 uStack_9c;

  u8 auStack_80 [4];

  u32 uStack_7c;

  u8 auStack_60 [4];

  u32 uStack_5c;

  u8 auStack_40 [4];

  u32 uStack_3c;

  u8 auStack_20 [4];

  u32 uStack_1c;

  

  iVar6 = *(int *)(*(int *)(param_1 + 0x24) + 0x44);

  uVar1 = *(u32 *)(iVar6 + 0x1c);

  uVar2 = *(u32 *)(iVar6 + 0x20);

  if (param_2 == 0xd) {

    if (param_3 == 0) {

      puVar8 = &DAT_006af620;

      puVar7 = auStack_5c90;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_5c90[0] = 0xd;

      uStack_5c78 = 0;

      uStack_5c74 = 0xd;

      uStack_5c5c = 0;

      uStack_5c58 = 0xd;

      uStack_5c40 = 0;

      uStack_5c3c = 0xd;

      uStack_5c24 = 0;

      uStack_5c20 = 0xd;

      uStack_5c08 = 0;

      uStack_5c04 = 0xd;

      uStack_5bec = 0;

      uStack_5be8 = 0xd;

      uStack_5bd0 = 0;

      uStack_5bcc = 0xd;

      uStack_5bb4 = 0;

      uStack_5bb0 = 0xd;

      uStack_5b98 = 0;

      uStack_5b94 = 0xd;

      uStack_5b7c = 0;

      uStack_5b78 = 0xd;

      uStack_5b60 = 0;

      uStack_5b5c = 0xd;

      uStack_5b44 = 0;

      uStack_5b40 = 0xd;

      uStack_5b28 = 0;

      uStack_5b24 = 0xd;

      uStack_5b0c = 0;

      uStack_5b08 = 0xd;

      uStack_5af0 = 0;

      uStack_5aec = 0xd;

      uStack_5ad4 = 0;

      uStack_5ad0 = 0xd;

      uStack_5ab8 = 0;

      uStack_5ab4 = 0xd;

      uStack_5a9c = 0;

      uStack_5a98 = 0xd;

      uStack_5a80 = 0;

      uStack_5a7c = 0xd;

      uStack_5a64 = 0;

      uStack_5a60 = 0xd;

      uStack_5a48 = 0;

      uStack_5a44 = 0xd;

      uStack_5a2c = 0;

      uStack_5a28 = 0xd;

      uStack_5a10 = 0;

      uStack_5a0c = 0xd;

      uStack_59f4 = 0;

      uStack_59f0 = 0xd;

      uStack_59d8 = 0;

      uStack_59d4 = 0xd;

      uStack_59bc = 0;

      auStack_59b8[0] = 0xd;

      uStack_59a0 = 0;

      uStack_599c = 0xd;

      uStack_5984 = 0;

      memcpy(auStack_3a0,auStack_59b8,0x1c);

      uVar4 = FUN_003dffc0(uVar1,0xd,uStack_39c);

      fclCombineList003df100(uVar4,auStack_3a0);

    }

    else if (param_3 == 1) {

      puVar8 = &DAT_006af620;

      puVar7 = auStack_5fa0;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_5fa0[0] = 0xd;

      uStack_5f88 = 0;

      uStack_5f84 = 0xd;

      uStack_5f6c = 0;

      uStack_5f68 = 0xd;

      uStack_5f50 = 0;

      uStack_5f4c = 0xd;

      uStack_5f34 = 0;

      uStack_5f30 = 0xd;

      uStack_5f18 = 0;

      uStack_5f14 = 0xd;

      uStack_5efc = 0;

      uStack_5ef8 = 0xd;

      uStack_5ee0 = 0;

      uStack_5edc = 0xd;

      uStack_5ec4 = 0;

      uStack_5ec0 = 0xd;

      uStack_5ea8 = 0;

      uStack_5ea4 = 0xd;

      uStack_5e8c = 0;

      uStack_5e88 = 0xd;

      uStack_5e70 = 0;

      uStack_5e6c = 0xd;

      uStack_5e54 = 0;

      uStack_5e50 = 0xd;

      uStack_5e38 = 0;

      uStack_5e34 = 0xd;

      uStack_5e1c = 0;

      uStack_5e18 = 0xd;

      uStack_5e00 = 0;

      uStack_5dfc = 0xd;

      uStack_5de4 = 0;

      uStack_5de0 = 0xd;

      uStack_5dc8 = 0;

      uStack_5dc4 = 0xd;

      uStack_5dac = 0;

      uStack_5da8 = 0xd;

      uStack_5d90 = 0;

      uStack_5d8c = 0xd;

      uStack_5d74 = 0;

      uStack_5d70 = 0xd;

      uStack_5d58 = 0;

      uStack_5d54 = 0xd;

      uStack_5d3c = 0;

      uStack_5d38 = 0xd;

      uStack_5d20 = 0;

      uStack_5d1c = 0xd;

      uStack_5d04 = 0;

      uStack_5d00 = 0xd;

      uStack_5ce8 = 0;

      uStack_5ce4 = 0xd;

      uStack_5ccc = 0;

      uStack_5cc8 = 0xd;

      uStack_5cb0 = 0;

      auStack_5cac[0] = 0xd;

      uStack_5c94 = 0;

      memcpy(auStack_3c0,auStack_5cac,0x1c);

      uVar4 = FUN_003dffc0(uVar1,0xd,uStack_3bc);

      fclCombineList003df100(uVar4,auStack_3c0);

    }

  }

  else if (param_2 == 0xc) {

    if (param_3 == 0) {

      puVar8 = &DAT_006af620;

      puVar7 = auStack_5670;

      iVar6 = 0x62;

      do {

        uVar1 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar1;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_5670[0] = 0xc;

      uStack_5658 = 0;

      uStack_5654 = 0xc;

      uStack_563c = 0;

      uStack_5638 = 0xc;

      uStack_5620 = 0;

      uStack_561c = 0xc;

      uStack_5604 = 0;

      uStack_5600 = 0xc;

      uStack_55e8 = 0;

      uStack_55e4 = 0xc;

      uStack_55cc = 0;

      uStack_55c8 = 0xc;

      uStack_55b0 = 0;

      uStack_55ac = 0xc;

      uStack_5594 = 0;

      uStack_5590 = 0xc;

      uStack_5578 = 0;

      uStack_5574 = 0xc;

      uStack_555c = 0;

      uStack_5558 = 0xc;

      uStack_5540 = 0;

      uStack_553c = 0xc;

      uStack_5524 = 0;

      uStack_5520 = 0xc;

      uStack_5508 = 0;

      uStack_5504 = 0xc;

      uStack_54ec = 0;

      uStack_54e8 = 0xc;

      uStack_54d0 = 0;

      uStack_54cc = 0xc;

      uStack_54b4 = 0;

      uStack_54b0 = 0xc;

      uStack_5498 = 0;

      uStack_5494 = 0xc;

      uStack_547c = 0;

      uStack_5478 = 0xc;

      uStack_5460 = 0;

      uStack_545c = 0xc;

      uStack_5444 = 0;

      uStack_5440 = 0xc;

      uStack_5428 = 0;

      uStack_5424 = 0xc;

      uStack_540c = 0;

      uStack_5408 = 0xc;

      uStack_53f0 = 0;

      uStack_53ec = 0xc;

      uStack_53d4 = 0;

      auStack_53d0[0] = 0xc;

      uStack_53b8 = 0;

      uStack_53b4 = 0xc;

      uStack_539c = 0;

      uStack_5398 = 0xc;

      uStack_5380 = 0;

      uStack_537c = 0xc;

      uStack_5364 = 0;

      memcpy(auStack_360,auStack_53d0,0x1c);

      uVar4 = FUN_003dffc0(uVar2,0xc,uStack_35c);

      fclCombineList003df100(uVar4,auStack_360);

    }

    else if (param_3 == 1) {

      puVar8 = &DAT_006af620;

      puVar7 = auStack_5980;

      iVar6 = 0x62;

      do {

        uVar1 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar1;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_5980[0] = 0xc;

      uStack_5968 = 0;

      uStack_5964 = 0xc;

      uStack_594c = 0;

      uStack_5948 = 0xc;

      uStack_5930 = 0;

      uStack_592c = 0xc;

      uStack_5914 = 0;

      uStack_5910 = 0xc;

      uStack_58f8 = 0;

      uStack_58f4 = 0xc;

      uStack_58dc = 0;

      uStack_58d8 = 0xc;

      uStack_58c0 = 0;

      uStack_58bc = 0xc;

      uStack_58a4 = 0;

      uStack_58a0 = 0xc;

      uStack_5888 = 0;

      uStack_5884 = 0xc;

      uStack_586c = 0;

      uStack_5868 = 0xc;

      uStack_5850 = 0;

      uStack_584c = 0xc;

      uStack_5834 = 0;

      uStack_5830 = 0xc;

      uStack_5818 = 0;

      uStack_5814 = 0xc;

      uStack_57fc = 0;

      uStack_57f8 = 0xc;

      uStack_57e0 = 0;

      uStack_57dc = 0xc;

      uStack_57c4 = 0;

      uStack_57c0 = 0xc;

      uStack_57a8 = 0;

      uStack_57a4 = 0xc;

      uStack_578c = 0;

      uStack_5788 = 0xc;

      uStack_5770 = 0;

      uStack_576c = 0xc;

      uStack_5754 = 0;

      uStack_5750 = 0xc;

      uStack_5738 = 0;

      uStack_5734 = 0xc;

      uStack_571c = 0;

      uStack_5718 = 0xc;

      uStack_5700 = 0;

      uStack_56fc = 0xc;

      uStack_56e4 = 0;

      uStack_56e0 = 0xc;

      uStack_56c8 = 0;

      auStack_56c4[0] = 0xc;

      uStack_56ac = 0;

      uStack_56a8 = 0xc;

      uStack_5690 = 0;

      uStack_568c = 0xc;

      uStack_5674 = 0;

      memcpy(auStack_380,auStack_56c4,0x1c);

      uVar4 = FUN_003dffc0(uVar2,0xc,uStack_37c);

      fclCombineList003df100(uVar4,auStack_380);

    }

  }

  else if (param_2 == 0xb) {

    if (param_3 == 0) {

      puVar8 = &DAT_006af620;

      puVar7 = auStack_5050;

      iVar6 = 0x62;

      do {

        uVar1 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar1;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_5050[0] = 0xb;

      uStack_5038 = 0;

      uStack_5034 = 0xb;

      uStack_501c = 0;

      uStack_5018 = 0xb;

      uStack_5000 = 0;

      uStack_4ffc = 0xb;

      uStack_4fe4 = 0;

      uStack_4fe0 = 0xb;

      uStack_4fc8 = 0;

      uStack_4fc4 = 0xb;

      uStack_4fac = 0;

      uStack_4fa8 = 0xb;

      uStack_4f90 = 0;

      uStack_4f8c = 0xb;

      uStack_4f74 = 0;

      uStack_4f70 = 0xb;

      uStack_4f58 = 0;

      uStack_4f54 = 0xb;

      uStack_4f3c = 0;

      uStack_4f38 = 0xb;

      uStack_4f20 = 0;

      uStack_4f1c = 0xb;

      uStack_4f04 = 0;

      uStack_4f00 = 0xb;

      uStack_4ee8 = 0;

      uStack_4ee4 = 0xb;

      uStack_4ecc = 0;

      uStack_4ec8 = 0xb;

      uStack_4eb0 = 0;

      uStack_4eac = 0xb;

      uStack_4e94 = 0;

      uStack_4e90 = 0xb;

      uStack_4e78 = 0;

      uStack_4e74 = 0xb;

      uStack_4e5c = 0;

      uStack_4e58 = 0xb;

      uStack_4e40 = 0;

      uStack_4e3c = 0xb;

      uStack_4e24 = 0;

      uStack_4e20 = 0xb;

      uStack_4e08 = 0;

      uStack_4e04 = 0xb;

      uStack_4dec = 0;

      auStack_4de8[0] = 0xb;

      uStack_4dd0 = 0;

      uStack_4dcc = 0xb;

      uStack_4db4 = 0;

      uStack_4db0 = 0xb;

      uStack_4d98 = 0;

      uStack_4d94 = 0xb;

      uStack_4d7c = 0;

      uStack_4d78 = 0xb;

      uStack_4d60 = 0;

      uStack_4d5c = 0xb;

      uStack_4d44 = 0;

      memcpy(auStack_320,auStack_4de8,0x1c);

      uVar4 = FUN_003dffc0(uVar2,0xb,uStack_31c);

      fclCombineList003df100(uVar4,auStack_320);

    }

    else if (param_3 == 1) {

      puVar8 = &DAT_006af620;

      puVar7 = auStack_5360;

      iVar6 = 0x62;

      do {

        uVar1 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar1;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_5360[0] = 0xb;

      uStack_5348 = 0;

      uStack_5344 = 0xb;

      uStack_532c = 0;

      uStack_5328 = 0xb;

      uStack_5310 = 0;

      uStack_530c = 0xb;

      uStack_52f4 = 0;

      uStack_52f0 = 0xb;

      uStack_52d8 = 0;

      uStack_52d4 = 0xb;

      uStack_52bc = 0;

      uStack_52b8 = 0xb;

      uStack_52a0 = 0;

      uStack_529c = 0xb;

      uStack_5284 = 0;

      uStack_5280 = 0xb;

      uStack_5268 = 0;

      uStack_5264 = 0xb;

      uStack_524c = 0;

      uStack_5248 = 0xb;

      uStack_5230 = 0;

      uStack_522c = 0xb;

      uStack_5214 = 0;

      uStack_5210 = 0xb;

      uStack_51f8 = 0;

      uStack_51f4 = 0xb;

      uStack_51dc = 0;

      uStack_51d8 = 0xb;

      uStack_51c0 = 0;

      uStack_51bc = 0xb;

      uStack_51a4 = 0;

      uStack_51a0 = 0xb;

      uStack_5188 = 0;

      uStack_5184 = 0xb;

      uStack_516c = 0;

      uStack_5168 = 0xb;

      uStack_5150 = 0;

      uStack_514c = 0xb;

      uStack_5134 = 0;

      uStack_5130 = 0xb;

      uStack_5118 = 0;

      uStack_5114 = 0xb;

      uStack_50fc = 0;

      uStack_50f8 = 0xb;

      uStack_50e0 = 0;

      auStack_50dc[0] = 0xb;

      uStack_50c4 = 0;

      uStack_50c0 = 0xb;

      uStack_50a8 = 0;

      uStack_50a4 = 0xb;

      uStack_508c = 0;

      uStack_5088 = 0xb;

      uStack_5070 = 0;

      uStack_506c = 0xb;

      uStack_5054 = 0;

      memcpy(auStack_340,auStack_50dc,0x1c);

      uVar4 = FUN_003dffc0(uVar2,0xb,uStack_33c);

      fclCombineList003df100(uVar4,auStack_340);

    }

  }

  else if (param_2 == 0x10) {

    if (param_3 == 0) {

      puVar8 = &DAT_006af620;

      puVar7 = auStack_3df0;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_3df0[0] = 9;

      uStack_3dd8 = 0;

      uStack_3dd4 = 9;

      uStack_3dbc = 0;

      uStack_3db8 = 9;

      uStack_3da0 = 0;

      uStack_3d9c = 9;

      uStack_3d84 = 0;

      uStack_3d80 = 9;

      uStack_3d68 = 0;

      uStack_3d64 = 9;

      uStack_3d4c = 0;

      uStack_3d48 = 9;

      uStack_3d30 = 0;

      uStack_3d2c = 9;

      uStack_3d14 = 0;

      uStack_3d10 = 9;

      uStack_3cf8 = 0;

      uStack_3cf4 = 9;

      uStack_3cdc = 0;

      uStack_3cd8 = 9;

      uStack_3cc0 = 0;

      uStack_3cbc = 9;

      uStack_3ca4 = 0;

      uStack_3ca0 = 9;

      uStack_3c88 = 0;

      uStack_3c84 = 9;

      uStack_3c6c = 0;

      uStack_3c68 = 9;

      uStack_3c50 = 0;

      uStack_3c4c = 9;

      uStack_3c34 = 0;

      uStack_3c30 = 9;

      uStack_3c18 = 0;

      uStack_3c14 = 9;

      uStack_3bfc = 0;

      auStack_3bf8[0] = 9;

      uStack_3be0 = 0;

      uStack_3bdc = 9;

      uStack_3bc4 = 0;

      uStack_3bc0 = 9;

      uStack_3ba8 = 0;

      uStack_3ba4 = 9;

      uStack_3b8c = 0;

      uStack_3b88 = 9;

      uStack_3b70 = 0;

      uStack_3b6c = 9;

      uStack_3b54 = 0;

      uStack_3b50 = 9;

      uStack_3b38 = 0;

      uStack_3b34 = 9;

      uStack_3b1c = 0;

      uStack_3b18 = 9;

      uStack_3b00 = 0;

      uStack_3afc = 9;

      uStack_3ae4 = 0;

      memcpy(auStack_260,auStack_3bf8,0x1c);

      uVar4 = FUN_003dffc0(uVar1,9,uStack_25c);

      fclCombineList003df100(uVar4,auStack_260);

      puVar8 = &DAT_006af620;

      puVar7 = auStack_4100;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_4100[0] = 10;

      uStack_40e8 = 0;

      uStack_40e4 = 10;

      uStack_40cc = 0;

      uStack_40c8 = 10;

      uStack_40b0 = 0;

      uStack_40ac = 10;

      uStack_4094 = 0;

      uStack_4090 = 10;

      uStack_4078 = 0;

      uStack_4074 = 10;

      uStack_405c = 0;

      uStack_4058 = 10;

      uStack_4040 = 0;

      uStack_403c = 10;

      uStack_4024 = 0;

      uStack_4020 = 10;

      uStack_4008 = 0;

      uStack_4004 = 10;

      uStack_3fec = 0;

      uStack_3fe8 = 10;

      uStack_3fd0 = 0;

      uStack_3fcc = 10;

      uStack_3fb4 = 0;

      uStack_3fb0 = 10;

      uStack_3f98 = 0;

      uStack_3f94 = 10;

      uStack_3f7c = 0;

      uStack_3f78 = 10;

      uStack_3f60 = 0;

      uStack_3f5c = 10;

      uStack_3f44 = 0;

      uStack_3f40 = 10;

      uStack_3f28 = 0;

      uStack_3f24 = 10;

      uStack_3f0c = 0;

      uStack_3f08 = 10;

      uStack_3ef0 = 0;

      uStack_3eec = 10;

      uStack_3ed4 = 0;

      auStack_3ed0[0] = 10;

      uStack_3eb8 = 0;

      uStack_3eb4 = 10;

      uStack_3e9c = 0;

      uStack_3e98 = 10;

      uStack_3e80 = 0;

      uStack_3e7c = 10;

      uStack_3e64 = 0;

      uStack_3e60 = 10;

      uStack_3e48 = 0;

      uStack_3e44 = 10;

      uStack_3e2c = 0;

      uStack_3e28 = 10;

      uStack_3e10 = 0;

      uStack_3e0c = 10;

      uStack_3df4 = 0;

      memcpy(auStack_280,auStack_3ed0,0x1c);

      uVar4 = FUN_003dffc0(uVar1,10,uStack_27c);

      fclCombineList003df100(uVar4,auStack_280);

      puVar8 = &DAT_006af620;

      puVar7 = auStack_4410;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_4410[0] = 6;

      uStack_43f8 = 0;

      uStack_43f4 = 6;

      uStack_43dc = 0;

      uStack_43d8 = 6;

      uStack_43c0 = 0;

      uStack_43bc = 6;

      uStack_43a4 = 0;

      uStack_43a0 = 6;

      uStack_4388 = 0;

      uStack_4384 = 6;

      uStack_436c = 0;

      uStack_4368 = 6;

      uStack_4350 = 0;

      uStack_434c = 6;

      uStack_4334 = 0;

      uStack_4330 = 6;

      uStack_4318 = 0;

      uStack_4314 = 6;

      uStack_42fc = 0;

      uStack_42f8 = 6;

      uStack_42e0 = 0;

      uStack_42dc = 6;

      uStack_42c4 = 0;

      auStack_42c0[0] = 6;

      uStack_42a8 = 0;

      uStack_42a4 = 6;

      uStack_428c = 0;

      uStack_4288 = 6;

      uStack_4270 = 0;

      uStack_426c = 6;

      uStack_4254 = 0;

      uStack_4250 = 6;

      uStack_4238 = 0;

      uStack_4234 = 6;

      uStack_421c = 0;

      uStack_4218 = 6;

      uStack_4200 = 0;

      uStack_41fc = 6;

      uStack_41e4 = 0;

      uStack_41e0 = 6;

      uStack_41c8 = 0;

      uStack_41c4 = 6;

      uStack_41ac = 0;

      uStack_41a8 = 6;

      uStack_4190 = 0;

      uStack_418c = 6;

      uStack_4174 = 0;

      uStack_4170 = 6;

      uStack_4158 = 0;

      uStack_4154 = 6;

      uStack_413c = 0;

      uStack_4138 = 6;

      uStack_4120 = 0;

      uStack_411c = 6;

      uStack_4104 = 0;

      memcpy(auStack_2a0,auStack_42c0,0x1c);

      uVar4 = FUN_003dffc0(uVar1,6,uStack_29c);

      fclCombineList003df100(uVar4,auStack_2a0);

    }

    else if (param_3 == 1) {

      puVar8 = &DAT_006af620;

      puVar7 = auStack_4720;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_4720[0] = 9;

      uStack_4708 = 0;

      uStack_4704 = 9;

      uStack_46ec = 0;

      uStack_46e8 = 9;

      uStack_46d0 = 0;

      uStack_46cc = 9;

      uStack_46b4 = 0;

      uStack_46b0 = 9;

      uStack_4698 = 0;

      uStack_4694 = 9;

      uStack_467c = 0;

      uStack_4678 = 9;

      uStack_4660 = 0;

      uStack_465c = 9;

      uStack_4644 = 0;

      uStack_4640 = 9;

      uStack_4628 = 0;

      uStack_4624 = 9;

      uStack_460c = 0;

      uStack_4608 = 9;

      uStack_45f0 = 0;

      uStack_45ec = 9;

      uStack_45d4 = 0;

      uStack_45d0 = 9;

      uStack_45b8 = 0;

      uStack_45b4 = 9;

      uStack_459c = 0;

      uStack_4598 = 9;

      uStack_4580 = 0;

      uStack_457c = 9;

      uStack_4564 = 0;

      uStack_4560 = 9;

      uStack_4548 = 0;

      uStack_4544 = 9;

      uStack_452c = 0;

      uStack_4528 = 9;

      uStack_4510 = 0;

      auStack_450c[0] = 9;

      uStack_44f4 = 0;

      uStack_44f0 = 9;

      uStack_44d8 = 0;

      uStack_44d4 = 9;

      uStack_44bc = 0;

      uStack_44b8 = 9;

      uStack_44a0 = 0;

      uStack_449c = 9;

      uStack_4484 = 0;

      uStack_4480 = 9;

      uStack_4468 = 0;

      uStack_4464 = 9;

      uStack_444c = 0;

      uStack_4448 = 9;

      uStack_4430 = 0;

      uStack_442c = 9;

      uStack_4414 = 0;

      memcpy(auStack_2c0,auStack_450c,0x1c);

      uVar4 = FUN_003dffc0(uVar1,9,uStack_2bc);

      fclCombineList003df100(uVar4,auStack_2c0);

      puVar8 = &DAT_006af620;

      puVar7 = auStack_4a30;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_4a30[0] = 10;

      uStack_4a18 = 0;

      uStack_4a14 = 10;

      uStack_49fc = 0;

      uStack_49f8 = 10;

      uStack_49e0 = 0;

      uStack_49dc = 10;

      uStack_49c4 = 0;

      uStack_49c0 = 10;

      uStack_49a8 = 0;

      uStack_49a4 = 10;

      uStack_498c = 0;

      uStack_4988 = 10;

      uStack_4970 = 0;

      uStack_496c = 10;

      uStack_4954 = 0;

      uStack_4950 = 10;

      uStack_4938 = 0;

      uStack_4934 = 10;

      uStack_491c = 0;

      uStack_4918 = 10;

      uStack_4900 = 0;

      uStack_48fc = 10;

      uStack_48e4 = 0;

      uStack_48e0 = 10;

      uStack_48c8 = 0;

      uStack_48c4 = 10;

      uStack_48ac = 0;

      uStack_48a8 = 10;

      uStack_4890 = 0;

      uStack_488c = 10;

      uStack_4874 = 0;

      uStack_4870 = 10;

      uStack_4858 = 0;

      uStack_4854 = 10;

      uStack_483c = 0;

      uStack_4838 = 10;

      uStack_4820 = 0;

      uStack_481c = 10;

      uStack_4804 = 0;

      uStack_4800 = 10;

      uStack_47e8 = 0;

      auStack_47e4[0] = 10;

      uStack_47cc = 0;

      uStack_47c8 = 10;

      uStack_47b0 = 0;

      uStack_47ac = 10;

      uStack_4794 = 0;

      uStack_4790 = 10;

      uStack_4778 = 0;

      uStack_4774 = 10;

      uStack_475c = 0;

      uStack_4758 = 10;

      uStack_4740 = 0;

      uStack_473c = 10;

      uStack_4724 = 0;

      memcpy(auStack_2e0,auStack_47e4,0x1c);

      uVar4 = FUN_003dffc0(uVar1,10,uStack_2dc);

      fclCombineList003df100(uVar4,auStack_2e0);

      puVar8 = &DAT_006af620;

      puVar7 = auStack_4d40;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_4d40[0] = 6;

      uStack_4d28 = 0;

      uStack_4d24 = 6;

      uStack_4d0c = 0;

      uStack_4d08 = 6;

      uStack_4cf0 = 0;

      uStack_4cec = 6;

      uStack_4cd4 = 0;

      uStack_4cd0 = 6;

      uStack_4cb8 = 0;

      uStack_4cb4 = 6;

      uStack_4c9c = 0;

      uStack_4c98 = 6;

      uStack_4c80 = 0;

      uStack_4c7c = 6;

      uStack_4c64 = 0;

      uStack_4c60 = 6;

      uStack_4c48 = 0;

      uStack_4c44 = 6;

      uStack_4c2c = 0;

      uStack_4c28 = 6;

      uStack_4c10 = 0;

      uStack_4c0c = 6;

      uStack_4bf4 = 0;

      uStack_4bf0 = 6;

      uStack_4bd8 = 0;

      auStack_4bd4[0] = 6;

      uStack_4bbc = 0;

      uStack_4bb8 = 6;

      uStack_4ba0 = 0;

      uStack_4b9c = 6;

      uStack_4b84 = 0;

      uStack_4b80 = 6;

      uStack_4b68 = 0;

      uStack_4b64 = 6;

      uStack_4b4c = 0;

      uStack_4b48 = 6;

      uStack_4b30 = 0;

      uStack_4b2c = 6;

      uStack_4b14 = 0;

      uStack_4b10 = 6;

      uStack_4af8 = 0;

      uStack_4af4 = 6;

      uStack_4adc = 0;

      uStack_4ad8 = 6;

      uStack_4ac0 = 0;

      uStack_4abc = 6;

      uStack_4aa4 = 0;

      uStack_4aa0 = 6;

      uStack_4a88 = 0;

      uStack_4a84 = 6;

      uStack_4a6c = 0;

      uStack_4a68 = 6;

      uStack_4a50 = 0;

      uStack_4a4c = 6;

      uStack_4a34 = 0;

      memcpy(auStack_300,auStack_4bd4,0x1c);

      uVar4 = FUN_003dffc0(uVar1,6,uStack_2fc);

      fclCombineList003df100(uVar4,auStack_300);

    }

  }

  else if (param_2 == 0xf) {

    if (param_3 == 0) {

      uVar4 = FUN_003e0940();

      uVar4 = FUN_003c5460(uVar4);

      FUN_003e0c20(uVar4,2,0);

      puVar8 = &DAT_006af620;

      puVar7 = auStack_1930;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_1930[0] = 8;

      uStack_1918 = 0;

      uStack_1914 = 8;

      uStack_18fc = 0;

      uStack_18f8 = 8;

      uStack_18e0 = 0;

      uStack_18dc = 8;

      uStack_18c4 = 0;

      uStack_18c0 = 8;

      uStack_18a8 = 0;

      uStack_18a4 = 8;

      uStack_188c = 0;

      uStack_1888 = 8;

      uStack_1870 = 0;

      uStack_186c = 8;

      uStack_1854 = 0;

      uStack_1850 = 8;

      uStack_1838 = 0;

      uStack_1834 = 8;

      uStack_181c = 0;

      uStack_1818 = 8;

      uStack_1800 = 0;

      uStack_17fc = 8;

      uStack_17e4 = 0;

      uStack_17e0 = 8;

      uStack_17c8 = 0;

      uStack_17c4 = 8;

      uStack_17ac = 0;

      uStack_17a8 = 8;

      uStack_1790 = 0;

      uStack_178c = 8;

      uStack_1774 = 0;

      auStack_1770[0] = 8;

      uStack_1758 = 0;

      uStack_1754 = 8;

      uStack_173c = 0;

      uStack_1738 = 8;

      uStack_1720 = 0;

      uStack_171c = 8;

      uStack_1704 = 0;

      uStack_1700 = 8;

      uStack_16e8 = 0;

      uStack_16e4 = 8;

      uStack_16cc = 0;

      uStack_16c8 = 8;

      uStack_16b0 = 0;

      uStack_16ac = 8;

      uStack_1694 = 0;

      uStack_1690 = 8;

      uStack_1678 = 0;

      uStack_1674 = 8;

      uStack_165c = 0;

      uStack_1658 = 8;

      uStack_1640 = 0;

      uStack_163c = 8;

      uStack_1624 = 0;

      memcpy(auStack_e0,auStack_1770,0x1c);

      uVar4 = FUN_003dffc0(uVar1,8,uStack_dc);

      fclCombineList003df100(uVar4,auStack_e0);

      puVar8 = &DAT_006af620;

      puVar7 = auStack_1c40;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_1c40[0] = 4;

      uStack_1c28 = 5;

      uStack_1c24 = 4;

      uStack_1c0c = 5;

      uStack_1c08 = 4;

      uStack_1bf0 = 5;

      uStack_1bec = 4;

      uStack_1bd4 = 5;

      uStack_1bd0 = 4;

      uStack_1bb8 = 5;

      uStack_1bb4 = 4;

      uStack_1b9c = 5;

      uStack_1b98 = 4;

      uStack_1b80 = 5;

      uStack_1b7c = 4;

      uStack_1b64 = 5;

      auStack_1b60[0] = 4;

      uStack_1b48 = 5;

      uStack_1b44 = 4;

      uStack_1b2c = 5;

      uStack_1b28 = 4;

      uStack_1b10 = 5;

      uStack_1b0c = 4;

      uStack_1af4 = 5;

      uStack_1af0 = 4;

      uStack_1ad8 = 5;

      uStack_1ad4 = 4;

      uStack_1abc = 5;

      uStack_1ab8 = 4;

      uStack_1aa0 = 5;

      uStack_1a9c = 4;

      uStack_1a84 = 5;

      uStack_1a80 = 4;

      uStack_1a68 = 5;

      uStack_1a64 = 4;

      uStack_1a4c = 5;

      uStack_1a48 = 4;

      uStack_1a30 = 5;

      uStack_1a2c = 4;

      uStack_1a14 = 5;

      uStack_1a10 = 4;

      uStack_19f8 = 5;

      uStack_19f4 = 4;

      uStack_19dc = 5;

      uStack_19d8 = 4;

      uStack_19c0 = 5;

      uStack_19bc = 4;

      uStack_19a4 = 5;

      uStack_19a0 = 4;

      uStack_1988 = 5;

      uStack_1984 = 4;

      uStack_196c = 5;

      uStack_1968 = 4;

      uStack_1950 = 5;

      uStack_194c = 4;

      uStack_1934 = 5;

      memcpy(auStack_100,auStack_1b60,0x1c);

      uVar4 = FUN_003dffc0(uVar1,4,uStack_fc);

      fclCombineList003df100(uVar4,auStack_100);

      puVar8 = &DAT_006af620;

      puVar7 = auStack_1f50;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_1f50[0] = 5;

      uStack_1f38 = 5;

      uStack_1f34 = 5;

      uStack_1f1c = 5;

      uStack_1f18 = 5;

      uStack_1f00 = 5;

      uStack_1efc = 5;

      uStack_1ee4 = 5;

      uStack_1ee0 = 5;

      uStack_1ec8 = 5;

      uStack_1ec4 = 5;

      uStack_1eac = 5;

      uStack_1ea8 = 5;

      uStack_1e90 = 5;

      uStack_1e8c = 5;

      uStack_1e74 = 5;

      uStack_1e70 = 5;

      uStack_1e58 = 5;

      uStack_1e54 = 5;

      uStack_1e3c = 5;

      auStack_1e38[0] = 5;

      uStack_1e20 = 5;

      uStack_1e1c = 5;

      uStack_1e04 = 5;

      uStack_1e00 = 5;

      uStack_1de8 = 5;

      uStack_1de4 = 5;

      uStack_1dcc = 5;

      uStack_1dc8 = 5;

      uStack_1db0 = 5;

      uStack_1dac = 5;

      uStack_1d94 = 5;

      uStack_1d90 = 5;

      uStack_1d78 = 5;

      uStack_1d74 = 5;

      uStack_1d5c = 5;

      uStack_1d58 = 5;

      uStack_1d40 = 5;

      uStack_1d3c = 5;

      uStack_1d24 = 5;

      uStack_1d20 = 5;

      uStack_1d08 = 5;

      uStack_1d04 = 5;

      uStack_1cec = 5;

      uStack_1ce8 = 5;

      uStack_1cd0 = 5;

      uStack_1ccc = 5;

      uStack_1cb4 = 5;

      uStack_1cb0 = 5;

      uStack_1c98 = 5;

      uStack_1c94 = 5;

      uStack_1c7c = 5;

      uStack_1c78 = 5;

      uStack_1c60 = 5;

      uStack_1c5c = 5;

      uStack_1c44 = 5;

      memcpy(auStack_120,auStack_1e38,0x1c);

      uVar4 = FUN_003dffc0(uVar1,5,uStack_11c);

      fclCombineList003df100(uVar4,auStack_120);

      puVar8 = &DAT_006af620;

      puVar7 = auStack_2260;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_2260[0] = 6;

      uStack_2248 = 0;

      uStack_2244 = 6;

      uStack_222c = 0;

      uStack_2228 = 6;

      uStack_2210 = 0;

      uStack_220c = 6;

      uStack_21f4 = 0;

      uStack_21f0 = 6;

      uStack_21d8 = 0;

      uStack_21d4 = 6;

      uStack_21bc = 0;

      uStack_21b8 = 6;

      uStack_21a0 = 0;

      uStack_219c = 6;

      uStack_2184 = 0;

      uStack_2180 = 6;

      uStack_2168 = 0;

      uStack_2164 = 6;

      uStack_214c = 0;

      uStack_2148 = 6;

      uStack_2130 = 0;

      uStack_212c = 6;

      uStack_2114 = 0;

      auStack_2110[0] = 6;

      uStack_20f8 = 0;

      uStack_20f4 = 6;

      uStack_20dc = 0;

      uStack_20d8 = 6;

      uStack_20c0 = 0;

      uStack_20bc = 6;

      uStack_20a4 = 0;

      uStack_20a0 = 6;

      uStack_2088 = 0;

      uStack_2084 = 6;

      uStack_206c = 0;

      uStack_2068 = 6;

      uStack_2050 = 0;

      uStack_204c = 6;

      uStack_2034 = 0;

      uStack_2030 = 6;

      uStack_2018 = 0;

      uStack_2014 = 6;

      uStack_1ffc = 0;

      uStack_1ff8 = 6;

      uStack_1fe0 = 0;

      uStack_1fdc = 6;

      uStack_1fc4 = 0;

      uStack_1fc0 = 6;

      uStack_1fa8 = 0;

      uStack_1fa4 = 6;

      uStack_1f8c = 0;

      uStack_1f88 = 6;

      uStack_1f70 = 0;

      uStack_1f6c = 6;

      uStack_1f54 = 0;

      memcpy(auStack_140,auStack_2110,0x1c);

      uVar4 = FUN_003dffc0(uVar1,6,uStack_13c);

      fclCombineList003df100(uVar4,auStack_140);

      puVar8 = &DAT_006af620;

      puVar7 = auStack_2570;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_2570[0] = 7;

      uStack_2558 = 0;

      uStack_2554 = 7;

      uStack_253c = 0;

      uStack_2538 = 7;

      uStack_2520 = 0;

      uStack_251c = 7;

      uStack_2504 = 0;

      uStack_2500 = 7;

      uStack_24e8 = 0;

      uStack_24e4 = 7;

      uStack_24cc = 0;

      uStack_24c8 = 7;

      uStack_24b0 = 0;

      uStack_24ac = 7;

      uStack_2494 = 0;

      uStack_2490 = 7;

      uStack_2478 = 0;

      uStack_2474 = 7;

      uStack_245c = 0;

      uStack_2458 = 7;

      uStack_2440 = 0;

      uStack_243c = 7;

      uStack_2424 = 0;

      uStack_2420 = 7;

      uStack_2408 = 0;

      uStack_2404 = 7;

      uStack_23ec = 0;

      auStack_23e8[0] = 7;

      uStack_23d0 = 0;

      uStack_23cc = 7;

      uStack_23b4 = 0;

      uStack_23b0 = 7;

      uStack_2398 = 0;

      uStack_2394 = 7;

      uStack_237c = 0;

      uStack_2378 = 7;

      uStack_2360 = 0;

      uStack_235c = 7;

      uStack_2344 = 0;

      uStack_2340 = 7;

      uStack_2328 = 0;

      uStack_2324 = 7;

      uStack_230c = 0;

      uStack_2308 = 7;

      uStack_22f0 = 0;

      uStack_22ec = 7;

      uStack_22d4 = 0;

      uStack_22d0 = 7;

      uStack_22b8 = 0;

      uStack_22b4 = 7;

      uStack_229c = 0;

      uStack_2298 = 7;

      uStack_2280 = 0;

      uStack_227c = 7;

      uStack_2264 = 0;

      memcpy(auStack_160,auStack_23e8,0x1c);

      uVar4 = FUN_003dffc0(uVar1,7,uStack_15c);

      fclCombineList003df100(uVar4,auStack_160);

      puVar8 = &DAT_006af620;

      puVar7 = auStack_2880;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_2880[0] = 3;

      uStack_2868 = 10;

      uStack_2864 = 3;

      uStack_284c = 10;

      uStack_2848 = 3;

      uStack_2830 = 10;

      uStack_282c = 3;

      uStack_2814 = 10;

      uStack_2810 = 3;

      uStack_27f8 = 10;

      uStack_27f4 = 3;

      uStack_27dc = 10;

      auStack_27d8[0] = 3;

      uStack_27c0 = 10;

      uStack_27bc = 3;

      uStack_27a4 = 10;

      uStack_27a0 = 3;

      uStack_2788 = 10;

      uStack_2784 = 3;

      uStack_276c = 10;

      uStack_2768 = 3;

      uStack_2750 = 10;

      uStack_274c = 3;

      uStack_2734 = 10;

      uStack_2730 = 3;

      uStack_2718 = 10;

      uStack_2714 = 3;

      uStack_26fc = 10;

      uStack_26f8 = 3;

      uStack_26e0 = 10;

      uStack_26dc = 3;

      uStack_26c4 = 10;

      uStack_26c0 = 3;

      uStack_26a8 = 10;

      uStack_26a4 = 3;

      uStack_268c = 10;

      uStack_2688 = 3;

      uStack_2670 = 10;

      uStack_266c = 3;

      uStack_2654 = 10;

      uStack_2650 = 3;

      uStack_2638 = 10;

      uStack_2634 = 3;

      uStack_261c = 10;

      uStack_2618 = 3;

      uStack_2600 = 10;

      uStack_25fc = 3;

      uStack_25e4 = 10;

      uStack_25e0 = 3;

      uStack_25c8 = 10;

      uStack_25c4 = 3;

      uStack_25ac = 10;

      uStack_25a8 = 3;

      uStack_2590 = 10;

      uStack_258c = 3;

      uStack_2574 = 10;

      memcpy(auStack_180,auStack_27d8,0x1c);

      uVar4 = FUN_003dffc0(uVar1,3,uStack_17c);

      fclCombineList003df100(uVar4,auStack_180);

    }

    else if (param_3 == 1) {

      uVar4 = FUN_003e0940();

      uVar4 = FUN_003c5460(uVar4);

      FUN_003e0c20(uVar4,2,2);

      puVar8 = &DAT_006af620;

      puVar7 = auStack_2b90;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_2b90[0] = 8;

      uStack_2b78 = 0;

      uStack_2b74 = 8;

      uStack_2b5c = 0;

      uStack_2b58 = 8;

      uStack_2b40 = 0;

      uStack_2b3c = 8;

      uStack_2b24 = 0;

      uStack_2b20 = 8;

      uStack_2b08 = 0;

      uStack_2b04 = 8;

      uStack_2aec = 0;

      uStack_2ae8 = 8;

      uStack_2ad0 = 0;

      uStack_2acc = 8;

      uStack_2ab4 = 0;

      uStack_2ab0 = 8;

      uStack_2a98 = 0;

      uStack_2a94 = 8;

      uStack_2a7c = 0;

      uStack_2a78 = 8;

      uStack_2a60 = 0;

      uStack_2a5c = 8;

      uStack_2a44 = 0;

      uStack_2a40 = 8;

      uStack_2a28 = 0;

      uStack_2a24 = 8;

      uStack_2a0c = 0;

      uStack_2a08 = 8;

      uStack_29f0 = 0;

      uStack_29ec = 8;

      uStack_29d4 = 0;

      uStack_29d0 = 8;

      uStack_29b8 = 0;

      auStack_29b4[0] = 8;

      uStack_299c = 0;

      uStack_2998 = 8;

      uStack_2980 = 0;

      uStack_297c = 8;

      uStack_2964 = 0;

      uStack_2960 = 8;

      uStack_2948 = 0;

      uStack_2944 = 8;

      uStack_292c = 0;

      uStack_2928 = 8;

      uStack_2910 = 0;

      uStack_290c = 8;

      uStack_28f4 = 0;

      uStack_28f0 = 8;

      uStack_28d8 = 0;

      uStack_28d4 = 8;

      uStack_28bc = 0;

      uStack_28b8 = 8;

      uStack_28a0 = 0;

      uStack_289c = 8;

      uStack_2884 = 0;

      memcpy(auStack_1a0,auStack_29b4,0x1c);

      uVar4 = FUN_003dffc0(uVar1,8,uStack_19c);

      fclCombineList003df100(uVar4,auStack_1a0);

      puVar8 = &DAT_006af620;

      puVar7 = auStack_2ea0;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_2ea0[0] = 4;

      uStack_2e88 = 0;

      uStack_2e84 = 4;

      uStack_2e6c = 0;

      uStack_2e68 = 4;

      uStack_2e50 = 0;

      uStack_2e4c = 4;

      uStack_2e34 = 0;

      uStack_2e30 = 4;

      uStack_2e18 = 0;

      uStack_2e14 = 4;

      uStack_2dfc = 0;

      uStack_2df8 = 4;

      uStack_2de0 = 0;

      uStack_2ddc = 4;

      uStack_2dc4 = 0;

      uStack_2dc0 = 4;

      uStack_2da8 = 0;

      auStack_2da4[0] = 4;

      uStack_2d8c = 0;

      uStack_2d88 = 4;

      uStack_2d70 = 0;

      uStack_2d6c = 4;

      uStack_2d54 = 0;

      uStack_2d50 = 4;

      uStack_2d38 = 0;

      uStack_2d34 = 4;

      uStack_2d1c = 0;

      uStack_2d18 = 4;

      uStack_2d00 = 0;

      uStack_2cfc = 4;

      uStack_2ce4 = 0;

      uStack_2ce0 = 4;

      uStack_2cc8 = 0;

      uStack_2cc4 = 4;

      uStack_2cac = 0;

      uStack_2ca8 = 4;

      uStack_2c90 = 0;

      uStack_2c8c = 4;

      uStack_2c74 = 0;

      uStack_2c70 = 4;

      uStack_2c58 = 0;

      uStack_2c54 = 4;

      uStack_2c3c = 0;

      uStack_2c38 = 4;

      uStack_2c20 = 0;

      uStack_2c1c = 4;

      uStack_2c04 = 0;

      uStack_2c00 = 4;

      uStack_2be8 = 0;

      uStack_2be4 = 4;

      uStack_2bcc = 0;

      uStack_2bc8 = 4;

      uStack_2bb0 = 0;

      uStack_2bac = 4;

      uStack_2b94 = 0;

      memcpy(auStack_1c0,auStack_2da4,0x1c);

      uVar4 = FUN_003dffc0(uVar1,4,uStack_1bc);

      fclCombineList003df100(uVar4,auStack_1c0);

      puVar8 = &DAT_006af620;

      puVar7 = auStack_31b0;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_31b0[0] = 5;

      uStack_3198 = 0;

      uStack_3194 = 5;

      uStack_317c = 0;

      uStack_3178 = 5;

      uStack_3160 = 0;

      uStack_315c = 5;

      uStack_3144 = 0;

      uStack_3140 = 5;

      uStack_3128 = 0;

      uStack_3124 = 5;

      uStack_310c = 0;

      uStack_3108 = 5;

      uStack_30f0 = 0;

      uStack_30ec = 5;

      uStack_30d4 = 0;

      uStack_30d0 = 5;

      uStack_30b8 = 0;

      uStack_30b4 = 5;

      uStack_309c = 0;

      uStack_3098 = 5;

      uStack_3080 = 0;

      auStack_307c[0] = 5;

      uStack_3064 = 0;

      uStack_3060 = 5;

      uStack_3048 = 0;

      uStack_3044 = 5;

      uStack_302c = 0;

      uStack_3028 = 5;

      uStack_3010 = 0;

      uStack_300c = 5;

      uStack_2ff4 = 0;

      uStack_2ff0 = 5;

      uStack_2fd8 = 0;

      uStack_2fd4 = 5;

      uStack_2fbc = 0;

      uStack_2fb8 = 5;

      uStack_2fa0 = 0;

      uStack_2f9c = 5;

      uStack_2f84 = 0;

      uStack_2f80 = 5;

      uStack_2f68 = 0;

      uStack_2f64 = 5;

      uStack_2f4c = 0;

      uStack_2f48 = 5;

      uStack_2f30 = 0;

      uStack_2f2c = 5;

      uStack_2f14 = 0;

      uStack_2f10 = 5;

      uStack_2ef8 = 0;

      uStack_2ef4 = 5;

      uStack_2edc = 0;

      uStack_2ed8 = 5;

      uStack_2ec0 = 0;

      uStack_2ebc = 5;

      uStack_2ea4 = 0;

      memcpy(auStack_1e0,auStack_307c,0x1c);

      uVar4 = FUN_003dffc0(uVar1,5,uStack_1dc);

      fclCombineList003df100(uVar4,auStack_1e0);

      puVar8 = &DAT_006af620;

      puVar7 = auStack_34c0;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_34c0[0] = 6;

      uStack_34a8 = 0;

      uStack_34a4 = 6;

      uStack_348c = 0;

      uStack_3488 = 6;

      uStack_3470 = 0;

      uStack_346c = 6;

      uStack_3454 = 0;

      uStack_3450 = 6;

      uStack_3438 = 0;

      uStack_3434 = 6;

      uStack_341c = 0;

      uStack_3418 = 6;

      uStack_3400 = 0;

      uStack_33fc = 6;

      uStack_33e4 = 0;

      uStack_33e0 = 6;

      uStack_33c8 = 0;

      uStack_33c4 = 6;

      uStack_33ac = 0;

      uStack_33a8 = 6;

      uStack_3390 = 0;

      uStack_338c = 6;

      uStack_3374 = 0;

      uStack_3370 = 6;

      uStack_3358 = 0;

      auStack_3354[0] = 6;

      uStack_333c = 0;

      uStack_3338 = 6;

      uStack_3320 = 0;

      uStack_331c = 6;

      uStack_3304 = 0;

      uStack_3300 = 6;

      uStack_32e8 = 0;

      uStack_32e4 = 6;

      uStack_32cc = 0;

      uStack_32c8 = 6;

      uStack_32b0 = 0;

      uStack_32ac = 6;

      uStack_3294 = 0;

      uStack_3290 = 6;

      uStack_3278 = 0;

      uStack_3274 = 6;

      uStack_325c = 0;

      uStack_3258 = 6;

      uStack_3240 = 0;

      uStack_323c = 6;

      uStack_3224 = 0;

      uStack_3220 = 6;

      uStack_3208 = 0;

      uStack_3204 = 6;

      uStack_31ec = 0;

      uStack_31e8 = 6;

      uStack_31d0 = 0;

      uStack_31cc = 6;

      uStack_31b4 = 0;

      memcpy(auStack_200,auStack_3354,0x1c);

      uVar4 = FUN_003dffc0(uVar1,6,uStack_1fc);

      fclCombineList003df100(uVar4,auStack_200);

      puVar8 = &DAT_006af620;

      puVar7 = auStack_37d0;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_37d0[0] = 7;

      uStack_37b8 = 0;

      uStack_37b4 = 7;

      uStack_379c = 0;

      uStack_3798 = 7;

      uStack_3780 = 0;

      uStack_377c = 7;

      uStack_3764 = 0;

      uStack_3760 = 7;

      uStack_3748 = 0;

      uStack_3744 = 7;

      uStack_372c = 0;

      uStack_3728 = 7;

      uStack_3710 = 0;

      uStack_370c = 7;

      uStack_36f4 = 0;

      uStack_36f0 = 7;

      uStack_36d8 = 0;

      uStack_36d4 = 7;

      uStack_36bc = 0;

      uStack_36b8 = 7;

      uStack_36a0 = 0;

      uStack_369c = 7;

      uStack_3684 = 0;

      uStack_3680 = 7;

      uStack_3668 = 0;

      uStack_3664 = 7;

      uStack_364c = 0;

      uStack_3648 = 7;

      uStack_3630 = 0;

      auStack_362c[0] = 7;

      uStack_3614 = 0;

      uStack_3610 = 7;

      uStack_35f8 = 0;

      uStack_35f4 = 7;

      uStack_35dc = 0;

      uStack_35d8 = 7;

      uStack_35c0 = 0;

      uStack_35bc = 7;

      uStack_35a4 = 0;

      uStack_35a0 = 7;

      uStack_3588 = 0;

      uStack_3584 = 7;

      uStack_356c = 0;

      uStack_3568 = 7;

      uStack_3550 = 0;

      uStack_354c = 7;

      uStack_3534 = 0;

      uStack_3530 = 7;

      uStack_3518 = 0;

      uStack_3514 = 7;

      uStack_34fc = 0;

      uStack_34f8 = 7;

      uStack_34e0 = 0;

      uStack_34dc = 7;

      uStack_34c4 = 0;

      memcpy(auStack_220,auStack_362c,0x1c);

      uVar4 = FUN_003dffc0(uVar1,7,uStack_21c);

      fclCombineList003df100(uVar4,auStack_220);

      puVar8 = &DAT_006af620;

      puVar7 = auStack_3ae0;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_3ae0[0] = 3;

      uStack_3ac8 = 0;

      uStack_3ac4 = 3;

      uStack_3aac = 0;

      uStack_3aa8 = 3;

      uStack_3a90 = 0;

      uStack_3a8c = 3;

      uStack_3a74 = 0;

      uStack_3a70 = 3;

      uStack_3a58 = 0;

      uStack_3a54 = 3;

      uStack_3a3c = 0;

      uStack_3a38 = 3;

      uStack_3a20 = 0;

      auStack_3a1c[0] = 3;

      uStack_3a04 = 0;

      uStack_3a00 = 3;

      uStack_39e8 = 0;

      uStack_39e4 = 3;

      uStack_39cc = 0;

      uStack_39c8 = 3;

      uStack_39b0 = 0;

      uStack_39ac = 3;

      uStack_3994 = 0;

      uStack_3990 = 3;

      uStack_3978 = 0;

      uStack_3974 = 3;

      uStack_395c = 0;

      uStack_3958 = 3;

      uStack_3940 = 0;

      uStack_393c = 3;

      uStack_3924 = 0;

      uStack_3920 = 3;

      uStack_3908 = 0;

      uStack_3904 = 3;

      uStack_38ec = 0;

      uStack_38e8 = 3;

      uStack_38d0 = 0;

      uStack_38cc = 3;

      uStack_38b4 = 0;

      uStack_38b0 = 3;

      uStack_3898 = 0;

      uStack_3894 = 3;

      uStack_387c = 0;

      uStack_3878 = 3;

      uStack_3860 = 0;

      uStack_385c = 3;

      uStack_3844 = 0;

      uStack_3840 = 3;

      uStack_3828 = 0;

      uStack_3824 = 3;

      uStack_380c = 0;

      uStack_3808 = 3;

      uStack_37f0 = 0;

      uStack_37ec = 3;

      uStack_37d4 = 0;

      memcpy(auStack_240,auStack_3a1c,0x1c);

      uVar4 = FUN_003dffc0(uVar1,3,uStack_23c);

      fclCombineList003df100(uVar4,auStack_240);

    }

  }

  else if (param_2 == 2) {

    if (param_3 == 0) {

      for (iVar6 = *(int *)(param_1 + 4); iVar6 != 0; iVar6 = *(int *)(iVar6 + 0x10)) {

        uVar1 = *(u32 *)(*(int *)(*(int *)(iVar6 + 0x14) + 0x1c) + 0xc);

        puVar8 = &DAT_006af620;

        puVar7 = auStack_1310;

        iVar5 = 0x62;

        do {

          uVar2 = *puVar8;

          uVar3 = puVar8[1];

          puVar8 = puVar8 + 2;

          iVar5 = iVar5 + -1;

          *puVar7 = uVar2;

          puVar7[1] = uVar3;

          puVar7 = puVar7 + 2;

        } while (0 < iVar5);

        auStack_1310[0] = 2;

        uStack_12f8 = 0;

        uStack_12f4 = 2;

        uStack_12dc = 0;

        uStack_12d8 = 2;

        uStack_12c0 = 0;

        uStack_12bc = 2;

        uStack_12a4 = 0;

        auStack_12a0[0] = 2;

        uStack_1288 = 0;

        uStack_1284 = 2;

        uStack_126c = 0;

        uStack_1268 = 2;

        uStack_1250 = 0;

        uStack_124c = 2;

        uStack_1234 = 0;

        uStack_1230 = 2;

        uStack_1218 = 0;

        uStack_1214 = 2;

        uStack_11fc = 0;

        uStack_11f8 = 2;

        uStack_11e0 = 0;

        uStack_11dc = 2;

        uStack_11c4 = 0;

        uStack_11c0 = 2;

        uStack_11a8 = 0;

        uStack_11a4 = 2;

        uStack_118c = 0;

        uStack_1188 = 2;

        uStack_1170 = 0;

        uStack_116c = 2;

        uStack_1154 = 0;

        uStack_1150 = 2;

        uStack_1138 = 0;

        uStack_1134 = 2;

        uStack_111c = 0;

        uStack_1118 = 2;

        uStack_1100 = 0;

        uStack_10fc = 2;

        uStack_10e4 = 0;

        uStack_10e0 = 2;

        uStack_10c8 = 0;

        uStack_10c4 = 2;

        uStack_10ac = 0;

        uStack_10a8 = 2;

        uStack_1090 = 0;

        uStack_108c = 2;

        uStack_1074 = 0;

        uStack_1070 = 2;

        uStack_1058 = 0;

        uStack_1054 = 2;

        uStack_103c = 0;

        uStack_1038 = 2;

        uStack_1020 = 0;

        uStack_101c = 2;

        uStack_1004 = 0;

        memcpy(auStack_a0,auStack_12a0,0x1c);

        uVar4 = FUN_003dffc0(uVar1,2,uStack_9c);

        fclCombineList003df100(uVar4,auStack_a0);

      }

    }

    else if ((param_3 == 1) && (*(int *)(param_1 + 0xc) != 0)) {

      uVar1 = *(u32 *)(*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x14) + 0x1c) + 0xc);

      puVar8 = &DAT_006af620;

      puVar7 = auStack_1620;

      iVar6 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar6 = iVar6 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar6);

      auStack_1620[0] = 2;

      uStack_1608 = 0;

      uStack_1604 = 2;

      uStack_15ec = 0;

      uStack_15e8 = 2;

      uStack_15d0 = 0;

      uStack_15cc = 2;

      uStack_15b4 = 0;

      uStack_15b0 = 2;

      uStack_1598 = 0;

      auStack_1594[0] = 2;

      uStack_157c = 0;

      uStack_1578 = 2;

      uStack_1560 = 0;

      uStack_155c = 2;

      uStack_1544 = 0;

      uStack_1540 = 2;

      uStack_1528 = 0;

      uStack_1524 = 2;

      uStack_150c = 0;

      uStack_1508 = 2;

      uStack_14f0 = 0;

      uStack_14ec = 2;

      uStack_14d4 = 0;

      uStack_14d0 = 2;

      uStack_14b8 = 0;

      uStack_14b4 = 2;

      uStack_149c = 0;

      uStack_1498 = 2;

      uStack_1480 = 0;

      uStack_147c = 2;

      uStack_1464 = 0;

      uStack_1460 = 2;

      uStack_1448 = 0;

      uStack_1444 = 2;

      uStack_142c = 0;

      uStack_1428 = 2;

      uStack_1410 = 0;

      uStack_140c = 2;

      uStack_13f4 = 0;

      uStack_13f0 = 2;

      uStack_13d8 = 0;

      uStack_13d4 = 2;

      uStack_13bc = 0;

      uStack_13b8 = 2;

      uStack_13a0 = 0;

      uStack_139c = 2;

      uStack_1384 = 0;

      uStack_1380 = 2;

      uStack_1368 = 0;

      uStack_1364 = 2;

      uStack_134c = 0;

      uStack_1348 = 2;

      uStack_1330 = 0;

      uStack_132c = 2;

      uStack_1314 = 0;

      memcpy(auStack_c0,auStack_1594,0x1c);

      uVar4 = FUN_003dffc0(uVar1,2,uStack_bc);

      fclCombineList003df100(uVar4,auStack_c0);

    }

  }

  else if (param_2 == 0xe) {

    if (param_3 == 0) {

      puVar8 = &DAT_006af620;

      puVar7 = auStack_6d0;

      iVar5 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar5 = iVar5 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar5);

      auStack_6d0[0] = 0;

      uStack_6b8 = 5;

      uStack_6b4 = 0;

      uStack_69c = 5;

      uStack_698 = 0;

      uStack_680 = 5;

      uStack_67c = 0;

      uStack_664 = 5;

      uStack_660 = 0;

      uStack_648 = 5;

      uStack_644 = 0;

      uStack_62c = 5;

      uStack_628 = 0;

      uStack_610 = 5;

      uStack_60c = 0;

      uStack_5f4 = 5;

      uStack_5f0 = 0;

      uStack_5d8 = 5;

      uStack_5d4 = 0;

      uStack_5bc = 5;

      uStack_5b8 = 0;

      uStack_5a0 = 5;

      uStack_59c = 0;

      uStack_584 = 5;

      uStack_580 = 0;

      uStack_568 = 5;

      uStack_564 = 0;

      uStack_54c = 5;

      uStack_548 = 0;

      uStack_530 = 5;

      uStack_52c = 0;

      uStack_514 = 5;

      uStack_510 = 0;

      uStack_4f8 = 5;

      uStack_4f4 = 0;

      uStack_4dc = 5;

      uStack_4d8 = 0;

      uStack_4c0 = 5;

      uStack_4bc = 0;

      uStack_4a4 = 5;

      uStack_4a0 = 0;

      uStack_488 = 5;

      uStack_484 = 0;

      uStack_46c = 5;

      uStack_468 = 0;

      uStack_450 = 5;

      uStack_44c = 0;

      uStack_434 = 5;

      uStack_430 = 0;

      uStack_418 = 5;

      uStack_414 = 0;

      uStack_3fc = 5;

      uStack_3f8 = 0;

      uStack_3e0 = 5;

      uStack_3dc = 0;

      uStack_3c4 = 5;

      memcpy(auStack_20,auStack_6d0,0x1c);

      uVar4 = FUN_003dffc0(uVar1,0,uStack_1c);

      fclCombineList003df100(uVar4,auStack_20);

      if (*(int *)(iVar6 + 4) == -8) {

        uVar1 = *(u32 *)(iVar6 + 0x1c);

        puVar8 = &DAT_006af620;

        puVar7 = auStack_9e0;

        iVar6 = 0x62;

        do {

          uVar2 = *puVar8;

          uVar3 = puVar8[1];

          puVar8 = puVar8 + 2;

          iVar6 = iVar6 + -1;

          *puVar7 = uVar2;

          puVar7[1] = uVar3;

          puVar7 = puVar7 + 2;

        } while (0 < iVar6);

        auStack_9e0[0] = 1;

        uStack_9c8 = 10;

        uStack_9c4 = 1;

        uStack_9ac = 10;

        auStack_9a8[0] = 1;

        uStack_990 = 10;

        uStack_98c = 1;

        uStack_974 = 10;

        uStack_970 = 1;

        uStack_958 = 10;

        uStack_954 = 1;

        uStack_93c = 10;

        uStack_938 = 1;

        uStack_920 = 10;

        uStack_91c = 1;

        uStack_904 = 10;

        uStack_900 = 1;

        uStack_8e8 = 10;

        uStack_8e4 = 1;

        uStack_8cc = 10;

        uStack_8c8 = 1;

        uStack_8b0 = 10;

        uStack_8ac = 1;

        uStack_894 = 10;

        uStack_890 = 1;

        uStack_878 = 10;

        uStack_874 = 1;

        uStack_85c = 10;

        uStack_858 = 1;

        uStack_840 = 10;

        uStack_83c = 1;

        uStack_824 = 10;

        uStack_820 = 1;

        uStack_808 = 10;

        uStack_804 = 1;

        uStack_7ec = 10;

        uStack_7e8 = 1;

        uStack_7d0 = 10;

        uStack_7cc = 1;

        uStack_7b4 = 10;

        uStack_7b0 = 1;

        uStack_798 = 10;

        uStack_794 = 1;

        uStack_77c = 10;

        uStack_778 = 1;

        uStack_760 = 10;

        uStack_75c = 1;

        uStack_744 = 10;

        uStack_740 = 1;

        uStack_728 = 10;

        uStack_724 = 1;

        uStack_70c = 10;

        uStack_708 = 1;

        uStack_6f0 = 10;

        uStack_6ec = 1;

        uStack_6d4 = 10;

        memcpy(auStack_40,auStack_9a8,0x1c);

        uVar4 = FUN_003dffc0(uVar1,1,uStack_3c);

        fclCombineList003df100(uVar4,auStack_40);

      }

    }

    else if (param_3 == 1) {

      puVar8 = &DAT_006af620;

      puVar7 = auStack_cf0;

      iVar5 = 0x62;

      do {

        uVar2 = *puVar8;

        uVar3 = puVar8[1];

        puVar8 = puVar8 + 2;

        iVar5 = iVar5 + -1;

        *puVar7 = uVar2;

        puVar7[1] = uVar3;

        puVar7 = puVar7 + 2;

      } while (0 < iVar5);

      auStack_cf0[0] = 0;

      uStack_cd8 = 0;

      auStack_cd4[0] = 0;

      uStack_cbc = 0;

      uStack_cb8 = 0;

      uStack_ca0 = 0;

      uStack_c9c = 0;

      uStack_c84 = 0;

      uStack_c80 = 0;

      uStack_c68 = 0;

      uStack_c64 = 0;

      uStack_c4c = 0;

      uStack_c48 = 0;

      uStack_c30 = 0;

      uStack_c2c = 0;

      uStack_c14 = 0;

      uStack_c10 = 0;

      uStack_bf8 = 0;

      uStack_bf4 = 0;

      uStack_bdc = 0;

      uStack_bd8 = 0;

      uStack_bc0 = 0;

      uStack_bbc = 0;

      uStack_ba4 = 0;

      uStack_ba0 = 0;

      uStack_b88 = 0;

      uStack_b84 = 0;

      uStack_b6c = 0;

      uStack_b68 = 0;

      uStack_b50 = 0;

      uStack_b4c = 0;

      uStack_b34 = 0;

      uStack_b30 = 0;

      uStack_b18 = 0;

      uStack_b14 = 0;

      uStack_afc = 0;

      uStack_af8 = 0;

      uStack_ae0 = 0;

      uStack_adc = 0;

      uStack_ac4 = 0;

      uStack_ac0 = 0;

      uStack_aa8 = 0;

      uStack_aa4 = 0;

      uStack_a8c = 0;

      uStack_a88 = 0;

      uStack_a70 = 0;

      uStack_a6c = 0;

      uStack_a54 = 0;

      uStack_a50 = 0;

      uStack_a38 = 0;

      uStack_a34 = 0;

      uStack_a1c = 0;

      uStack_a18 = 0;

      uStack_a00 = 0;

      uStack_9fc = 0;

      uStack_9e4 = 0;

      memcpy(auStack_60,auStack_cd4,0x1c);

      uVar4 = FUN_003dffc0(uVar1,0,uStack_5c);

      fclCombineList003df100(uVar4,auStack_60);

      if (*(int *)(iVar6 + 4) == -8) {

        uVar1 = *(u32 *)(iVar6 + 0x1c);

        puVar8 = &DAT_006af620;

        puVar7 = auStack_1000;

        iVar6 = 0x62;

        do {

          uVar2 = *puVar8;

          uVar3 = puVar8[1];

          puVar8 = puVar8 + 2;

          iVar6 = iVar6 + -1;

          *puVar7 = uVar2;

          puVar7[1] = uVar3;

          puVar7 = puVar7 + 2;

        } while (0 < iVar6);

        auStack_1000[0] = 1;

        uStack_fe8 = 0;

        uStack_fe4 = 1;

        uStack_fcc = 0;

        uStack_fc8 = 1;

        uStack_fb0 = 0;

        auStack_fac[0] = 1;

        uStack_f94 = 0;

        uStack_f90 = 1;

        uStack_f78 = 0;

        uStack_f74 = 1;

        uStack_f5c = 0;

        uStack_f58 = 1;

        uStack_f40 = 0;

        uStack_f3c = 1;

        uStack_f24 = 0;

        uStack_f20 = 1;

        uStack_f08 = 0;

        uStack_f04 = 1;

        uStack_eec = 0;

        uStack_ee8 = 1;

        uStack_ed0 = 0;

        uStack_ecc = 1;

        uStack_eb4 = 0;

        uStack_eb0 = 1;

        uStack_e98 = 0;

        uStack_e94 = 1;

        uStack_e7c = 0;

        uStack_e78 = 1;

        uStack_e60 = 0;

        uStack_e5c = 1;

        uStack_e44 = 0;

        uStack_e40 = 1;

        uStack_e28 = 0;

        uStack_e24 = 1;

        uStack_e0c = 0;

        uStack_e08 = 1;

        uStack_df0 = 0;

        uStack_dec = 1;

        uStack_dd4 = 0;

        uStack_dd0 = 1;

        uStack_db8 = 0;

        uStack_db4 = 1;

        uStack_d9c = 0;

        uStack_d98 = 1;

        uStack_d80 = 0;

        uStack_d7c = 1;

        uStack_d64 = 0;

        uStack_d60 = 1;

        uStack_d48 = 0;

        uStack_d44 = 1;

        uStack_d2c = 0;

        uStack_d28 = 1;

        uStack_d10 = 0;

        uStack_d0c = 1;

        uStack_cf4 = 0;

        memcpy(auStack_80,auStack_fac,0x1c);

        uVar4 = FUN_003dffc0(uVar1,1,uStack_7c);

        fclCombineList003df100(uVar4,auStack_80);

      }

    }

  }

  return;

}

// FUN_00409C80 NONMATCHING


u64 FUN_00409c80(u64 param_1)



{

  int iVar1;

  u32 uVar2;

  u32 uVar3;

  u32 uVar4;

  u32 uVar5;

  u32 uVar6;

  u32 uVar7;

  u32 uVar8;

  u32 uVar9;

  u32 uVar10;

  u32 uVar11;

  int iVar12;

  u32 uVar13;

  long lVar14;

  int iVar15;

  


  for (iVar15 = 1; iVar15 < 0x100; iVar15 = iVar15 + 1) {

    lVar14 = datGetPersonaByCompendium(iVar15);

    if (lVar14 != 0) {

      iVar1 = FUN_003c5a40(param_1,*(u16 *)((int)param_1 + 0x10) + 1,0x10,0);

      iVar1 = *(int *)(*(int *)(iVar1 + 0x14) + 0x1c);

      *(int *)(iVar1 + 4) = (int)lVar14;

      uVar2 = datPersonaGetTotalStat(lVar14,0);

      uVar3 = datPersonaGetTotalStat(lVar14,1);

      uVar4 = datPersonaGetTotalStat(lVar14,2);

      uVar5 = datPersonaGetTotalStat(lVar14,3);

      uVar6 = datPersonaGetTotalStat(lVar14,4);

      uVar7 = datPersonaGetTotalStat(lVar14,0);

      uVar8 = datPersonaGetTotalStat(lVar14,1);

      uVar9 = datPersonaGetTotalStat(lVar14,2);

      uVar10 = datPersonaGetTotalStat(lVar14,3);

      uVar11 = datPersonaGetTotalStat(lVar14,4);

      *(u32 *)(iVar1 + 8) =

           ((uVar6 & 0xff) + (uVar5 & 0xff) + (uVar4 & 0xff) + (uVar2 & 0xff) + (uVar3 & 0xff)) *

           ((uVar11 & 0xff) + (uVar10 & 0xff) + (uVar9 & 0xff) + (uVar7 & 0xff) + (uVar8 & 0xff)) *

           3 + 2000;

      lVar14 = datGetFlag(0x1319);

      if (lVar14 != 0) {

        iVar12 = *(int *)(iVar1 + 8) << 2;

        if (iVar12 < 10000000) {

          *(int *)(iVar1 + 8) = iVar12;

        }

        else {

          *(u8 **)(iVar1 + 8) = (u8 *)&DAT_0098967f;

        }

      }

      uVar13 = FUN_003dfeb0(0);

      *(u32 *)(iVar1 + 0xc) = uVar13;

    }

  }

  return 0;

}

// FUN_00409E90


u32 FUN_00409e90(void)
{
  u32 uVar1;
  int iVar3;

  iVar3 = 0;
  goto check_limit;
check_persona:
  uVar1 = datPersonaGetHeroPersona_s16((s16)iVar3);
  if (uVar1 != 0) {
    if (FUN_0017ca10_u32(uVar1) == 1) {
      return 1;
    }
  }
  iVar3 = iVar3 + 1;
check_limit:
  uVar1 = FUN_00175410_u32();
  if (iVar3 < (int)(uVar1 & 0xffff)) {
    goto check_persona;
  }
  return 0;
}

// FUN_00409F20


void FUN_00409f20(u64 param_1,int param_2)



{

  FUN_003dff00(*(u32 *)(*(int *)(*(int *)(param_2 + 0x14) + 0x1c) + 0xc));

  return;

}

// FUN_00409F50 NONMATCHING


u64 FUN_00409f50(u64 param_1,long param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  u32 uVar4;

  u32 uVar5;

  u64 uVar6;

  long lVar7;

  long lVar8;

  int iVar9;

  

  uVar6 = FUN_003c58f0(0,0x28,8,0x18);

  iVar2 = (int)uVar6;

  iVar1 = *(int *)(*(int *)(iVar2 + 0x24) + 0x44);

  if (param_2 == 0) {

    *(u32 *)(iVar1 + 4) = 0xfffffff8;



  }

  else {

    *(u32 *)(iVar1 + 4) = 0xfffffff7;

    for (iVar9 = 0; uVar4 = FUN_00175410(), iVar9 < (int)(uVar4 & 0xffff); iVar9 = iVar9 + 1) {

      lVar7 = datPersonaGetHeroPersona((short)iVar9);

      if ((lVar7 != 0) && (lVar8 = FUN_0017ca10(lVar7), lVar8 == 1)) {

        iVar3 = FUN_003c5a40(uVar6,*(u16 *)(iVar2 + 0x10) + 1,0x10,0);

        iVar3 = *(int *)(*(int *)(iVar3 + 0x14) + 0x1c);

        *(int *)(iVar3 + 4) = (int)lVar7;

        uVar5 = FUN_003dfeb0(0);

        *(u32 *)(iVar3 + 0xc) = uVar5;

      }

    }

  }

  FUN_003c5d40(uVar6,*(u32 *)(iVar2 + 4),0);

  uVar5 = FUN_0017cf00();

  *(u32 *)(iVar1 + 0x24) = uVar5;

  uVar5 = FUN_003dfeb0(0);

  *(u32 *)(iVar1 + 0x1c) = uVar5;

  if (param_2 == 0) {

    uVar5 = FUN_003dfeb0(0);

    *(u32 *)(iVar1 + 0x20) = uVar5;

  }

  FUN_003c6ee0(uVar6);

  FUN_003c5f40(uVar6,0x409f20);

  FUN_003c5e20(uVar6,0x40b630);

  FUN_003c5ee0(uVar6,0x40b780);

  FUN_003c6d40(uVar6,0,0);

  *(u16 *)(*(int *)(iVar2 + 0x24) + 6) = 10;

  *(u16 *)(*(int *)(iVar2 + 0x24) + 8) = 5;

  if (param_2 == 0) {





  }

  else {





  }

  return uVar6;

}

// FUN_0040A200


void FUN_0040a200(int param_1)



{

  int iVar1;

  

  iVar1 = *(int *)(*(int *)((int)param_1 + 0x24) + 0x44);

  FUN_003dff00(*(u32 *)(iVar1 + 0x1c));

  if (*(int *)(iVar1 + 0x20) != 0) {

    FUN_003dff00(*(u32 *)(iVar1 + 0x20));

  }

  FUN_003c5a20(param_1);

  return;

}

// FUN_0040A260


void FUN_0040a260(int param_1)



{

  int iVar1;

  

  for (iVar1 = *(int *)(param_1 + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {

    FUN_0017c960(*(u32 *)(*(int *)(*(int *)(iVar1 + 0x14) + 0x1c) + 4));

  }

  return;

}

// FUN_0040A2B0 NONMATCHING


u8 FUN_0040a2b0(u64 param_1)



{

  int iVar1;

  u32 uVar2;

  long lVar3;

  long lVar4;

  int iVar5;

  

  iVar1 = *(int *)(*(int *)((int)param_1 + 0x24) + 0x44);

  uVar2 = *(u32 *)(iVar1 + 0x20);

  FUN_003e0650(*(u32 *)(iVar1 + 0x1c));

  if (*(int *)(iVar1 + 0x20) != 0) {

    FUN_003e0650(uVar2);

  }

  for (iVar5 = *(int *)((int)param_1 + 4); iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x10)) {

    FUN_003e0650(*(u32 *)(*(int *)(*(int *)(iVar5 + 0x14) + 0x1c) + 0xc));

  }

  lVar3 = FUN_003c6270(param_1);

  lVar4 = FUN_003c6ce0(param_1);

  if ((lVar4 != 0) || (lVar4 = FUN_003c6d10(param_1), lVar4 != 0)) {

    func_0010a4e0(0,0,0,0);

  }

  lVar4 = FUN_003c6ca0(param_1);

  if ((lVar4 != 0) || (lVar4 = FUN_003c6cc0(param_1), lVar4 != 0)) {

    func_0010a4e0(0,0,0,5);

  }


  if (lVar3 == 3) {

    if (*(int *)(iVar1 + 4) == -8) {




    }

    else {




    }

  }

  return lVar3 == 3;

}

// FUN_0040A490 NONMATCHING


u8 FUN_0040a490(u64 param_1)



{

  long lVar1;

  long lVar2;

  int iVar3;

  

  FUN_003e0650(*(u32 *)(*(int *)(*(int *)((int)param_1 + 0x24) + 0x44) + 0x1c));

  for (iVar3 = *(int *)((int)param_1 + 4); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x10)) {

    FUN_003e0650(*(u32 *)(*(int *)(*(int *)(iVar3 + 0x14) + 0x1c) + 0xc));

  }

  lVar1 = FUN_003c6270(param_1);

  lVar2 = FUN_003c6ce0(param_1);

  if ((lVar2 != 0) || (lVar2 = FUN_003c6d10(param_1), lVar2 != 0)) {

    func_0010a4e0(0,0,0,0);

  }

  lVar2 = FUN_003c6ca0(param_1);

  if ((lVar2 != 0) || (lVar2 = FUN_003c6cc0(param_1), lVar2 != 0)) {

    func_0010a4e0(0,0,0,5);

  }


  return lVar1 == 3;

}

// FUN_0040A6D0 NONMATCHING


void FUN_0040a6d0(u64 param_1,long param_2)



{

  u32 *puVar1;

  u32 uVar2;

  u64 uVar3;

  

  puVar1 = *(u32 **)(*(int *)((int)param_1 + 0x24) + 0x44);

  uVar3 = FUN_003c6fb0();

  uVar2 = *(u32 *)((int)param_1 + 0xc);

  if (param_2 == 1) {

    FUN_003c7000(param_1,0x40a640,0);

  }

  else {

    FUN_003c7000(param_1,0x40a5b0,0);

  }

  FUN_003c5d40(param_1,uVar2,uVar3);

  if (param_2 == 1) {

    *puVar1 = *puVar1 | 2;

  }

  else {

    *puVar1 = *puVar1 & 0xfffffffd;

  }

  return;

}

// FUN_0040A7C0


void FUN_0040a7c0(u64 param_1,u64 param_2,u8 param_3)



{

  FUN_0040e3c0(param_1,param_2,param_3,0x78);

  return;

}

// FUN_0040A7F0 NONMATCHING


void FUN_0040a7f0(u64 param_1,int param_2,int *param_3)



{

  u32 *puVar1;

  int iVar2;

  u64 uVar3;

  u8 bVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  u32 uVar9;

  int iVar10;

  u32 uVar11;

  u8 auStack_60 [32];

  u8 auStack_40[16];

  u8 auStack_30 [24];

  u32 auStack_18 [4];

  u32 uStack_8;

  u32 uStack_4;

  

  iVar6 = *param_3 + (int)*(short *)(param_2 + 0x14);

  iVar5 = param_3[1] + (int)*(short *)(param_2 + 0x16);

  uVar11 = ((int)(short)param_3[2] * (int)*(short *)(param_2 + 0x26)) / 0xff;

  if (uVar11 != 0) {

    bVar4 = (*(u16 *)((int)param_3 + 10) & 1) != 0;

    iVar7 = param_3[3];

    iVar8 = *(int *)(iVar7 + 0x24);

    puVar1 = *(u32 **)(iVar8 + 0x44);

    switch(*(u32 *)(param_2 + 0x10)) {

    case 0:

      iVar7 = *(int *)(iVar8 + 0x2c);

      if (puVar1[1] == 0xfffffff7) {

        iVar6 = iVar6 + 0x3e;

        iVar5 = iVar5 + -0x1c;

      }

      iVar8 = 0;

      while( 1 ) {

        iVar10 = *(int *)(param_3[3] + 0x24);

        if (*(int *)(iVar10 + 0x20) <= iVar8) break;

        bVar4 = iVar7 == *(int *)(param_3[3] + 0xc);

        iVar10 = iVar5 + iVar8 * *(int *)(iVar10 + 0xc);

        if ((*puVar1 & 4) == 0) {

          uStack_8 = uGpffffacf0;

          uStack_4 = uGpffffacf4;

          auStack_18[2] = uGpffffacf8;

          auStack_18[3] = uGpffffacfc;

          iVar2 = *(int *)(*(int *)(iVar7 + 0x14) + 0x1c);

          uVar9 = (u32)bVar4;

          FUN_0040e3c0(0,iVar6,iVar10,uVar11 & 0xff,0x8e,

                       (*(u8 *)(iGpffffb730 + (u32)*(u16 *)(*(int *)(iVar2 + 4) + 2) * 0xe + 2

                                 ) - 1) * 2 + uVar9);

          FUN_003b32d0(0,iVar6 + 0xa3,iVar10 + 0x84,uVar11 | 0xffffff00,

                       *(u8 *)(auStack_18 + uVar9 + 4),1,

                       iGpffffb7f4 + (u32)*(u16 *)(*(int *)(iVar2 + 4) + 2) * 0x11,0x10,0x6e);

          sprintf((char *)auStack_30,&gp0xffffac10,*(u8 *)(*(int *)(iVar2 + 4) + 4));

          FUN_0040eb50(0,iVar6 + 0x174,iVar10 + 0x85,uVar11 & 0xff,auStack_18[uVar9 + 2],auStack_30,

                       1);

        }

        else {

          FUN_0040e3c0(0,iVar6,iVar10,uVar11 & 0xff,0x8d,bVar4);

          FUN_0040e3c0(0,iVar6,iVar10,uVar11 & 0xff,0x8f,0);

        }

        iVar7 = *(int *)(iVar7 + 0x10);

        if (iVar7 == 0) {

          return;

        }

        iVar8 = iVar8 + 1;

      }

      break;

    case 1:

      iVar7 = *(int *)(iVar8 + 0x2c);

      iVar8 = 0;

      while( 1 ) {

        iVar10 = *(int *)(param_3[3] + 0x24);

        if (*(int *)(iVar10 + 0x20) <= iVar8) break;

        iVar2 = *(int *)(param_3[3] + 0xc);

        iVar10 = iVar5 + iVar8 * *(int *)(iVar10 + 0xc);

        if ((*puVar1 & 4) == 0) {

          auStack_18[0] = uGpffffad00;

          auStack_18[1] = uGpffffad04;

          sprintf((char *)auStack_40,&gp0xffffac10,

                       *(u32 *)(*(int *)(*(int *)(iVar7 + 0x14) + 0x1c) + 8));

          FUN_0040eb50(0,iVar6 + 0x205,iVar10 + 0x85,uVar11 & 0xff,auStack_18[iVar7 == iVar2],

                       auStack_40,9);

        }

        else {

          FUN_0040e3c0(0,iVar6,iVar10,uVar11 & 0xff,0x90,0);

        }

        iVar7 = *(int *)(iVar7 + 0x10);

        if (iVar7 == 0) {

          return;

        }

        iVar8 = iVar8 + 1;

      }

      break;

    case 2:

      if ((*puVar1 & 4) != 0) {

        if (puVar1[1] == 0xfffffff8) {

          if (bVar4) {

            FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x94,0);

          }

          else {

            uVar11 = (u32)((float)(int)uVar11 * fGpffff8084);

          }

          FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x92,0);

          FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x93,0);

        }

        else {

          if (bVar4) {

            FUN_0040e3c0(0,iVar6 + 0x3e,iVar5 + -0x1c,uVar11 & 0xff,0x9a,0);

          }

          else {

            uVar11 = (u32)((float)(int)uVar11 * fGpffff8084);

          }

          FUN_0040e3c0(0,iVar6 + 0x3e,iVar5 + -0x1c,uVar11 & 0xff,0x92,0);

          FUN_0040e3c0(0,iVar6 + 0x3e,iVar5 + -0x1c,uVar11 & 0xff,0x9b,0);

        }

      }

      break;

    case 3:

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x75,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x76,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x77,0);

      uVar3 = FUN_0017cf00();

      sprintf((char *)auStack_60,&gp0xffffac10,uVar3);

      FUN_0040ec20(0,iVar6,iVar5,uVar11 & 0xff,0,auStack_60,1,0x26,0x40a7c0);

      break;

    case 4:

      bVar4 = (*puVar1 & 2) != 0 || bVar4;

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x79,bVar4);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x7a,bVar4);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x7d,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x7f,0);

      break;

    case 5:

      bVar4 = (*puVar1 & 2) == 0 || bVar4;

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x7b,bVar4);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x7c,bVar4);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x7e,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x80,0);

      break;

    case 6:

      if (puVar1[1] == 0xfffffff8) {

        FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x81,0);

        FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x83,0);

        FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x84,0);

        FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x85,0);

        FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x87,0);

        FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x88,0);

      }

      else {

        FUN_0040e3c0(0,iVar6 + 0x3e,iVar5 + -0x1c,uVar11 & 0xff,0x81,0);

        FUN_0040e3c0(0,iVar6 + 0x3e,iVar5 + -0x1c,uVar11 & 0xff,0x83,0);

        FUN_0040e3c0(0,iVar6 + 0x3e,iVar5 + -0x1c,uVar11 & 0xff,0x84,0);

        FUN_0040e3c0(0,iVar6 + 0x3e,iVar5 + -0x1c,uVar11 & 0xff,0x85,0);

        FUN_0040e3c0(0,iVar6 + 0x3e,iVar5 + -0x1c,uVar11 & 0xff,0x87,0);

        FUN_0040e3c0(0,iVar6 + 0x3e,iVar5 + -0x1c,uVar11 & 0xff,0x88,0);

      }

      break;

    case 7:

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x82,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x86,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x89,0);

      break;

    case 8:

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x6b,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x6c,0);

      break;

    case 9:

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x95,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x96,0);

      break;

    case 10:

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x97,0);

      FUN_0040e3c0(0,iVar6,iVar5,uVar11 & 0xff,0x98,0);

      break;

    case 0xd:

      if (puVar1[1] == 0xfffffff8) {

        if (*(u32 *)(iVar8 + 0x20) <= (u32)*(u16 *)(iVar7 + 0x10)) {

          iVar7 = *(int *)(iVar8 + 0x28);

          FUN_0040e3f0(0,0,0x3f800000,0x3f800000,iVar6,iVar5,uVar11 & 0xff,0x8a,0,0,0);

          FUN_0040e3f0(0,0,0x3f800000,0x3f800000,iVar6,iVar5,uVar11 & 0xff,0x8b,0,0,0);

          FUN_0040e3f0(0,0,0x3f800000,0x3f800000,iVar6 + 0x212,

                       iVar5 + 0x80 + (iVar7 * 0x7d) / 0xffff,uVar11 & 0xff,0x8c,0,0,0);

        }

      }

      else if (*(u32 *)(iVar8 + 0x20) <= (u32)*(u16 *)(iVar7 + 0x10)) {

        iVar7 = *(int *)(iVar8 + 0x28);

        FUN_0040e3f0(0,0,0x3f800000,0x3f800000,iVar6 + -0x54,iVar5 + -0x1c,uVar11 & 0xff,0x8a,0,0,0)

        ;

        FUN_0040e3f0(0,0,0x3f800000,0x3f800000,iVar6 + -0x54,iVar5 + -0x1c,uVar11 & 0xff,0x8b,0,0,0)

        ;

        FUN_0040e3f0(0,0,0x3f800000,0x3f800000,iVar6 + 0x1be,iVar5 + 100 + (iVar7 * 0x7d) / 0xffff,

                     uVar11 & 0xff,0x8c,0,0,0);

      }

    }

  }

  return;

}

// FUN_0040B3A0 NONMATCHING


void FUN_0040b3a0(u64 param_1,int param_2,int param_3)



{

  short sVar1;

  short sVar2;

  u16 uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  

  sVar1 = *(short *)(param_2 + 0x14);

  sVar2 = *(short *)(param_2 + 0x16);

  uVar3 = *(u16 *)(param_2 + 0x26);

  if (uVar3 != 0) {

    iVar5 = (int)sVar2;

    if (*(int *)(param_2 + 0x10) == 0xc) {

      iVar4 = *(int *)(*(int *)(*(int *)(param_3 + 0x10) + 0x14) + 0x1c);

      FUN_0040e3c0(0,sVar1,sVar2,uVar3 & 0xff,0x9e,0);

      FUN_0040e3c0(0,sVar1,sVar2,uVar3 & 0xff,0x9f,0);

      FUN_0040e3c0(0,sVar1 + 0x15d,iVar5 + 0x4d,uVar3 & 0xff,0x9d,

                   (*(u8 *)((u32)*(u16 *)(*(int *)(iVar4 + 4) + 2) * 0xe + iGpffffb730 + 2) -

                   1) * 2 + 1);

      FUN_003b32d0(0,sVar1 + 0x1af,iVar5 + 0x48,0xffffffffffffffff,5,1,

                   iGpffffb7f4 + (u32)*(u16 *)(*(int *)(iVar4 + 4) + 2) * 0x11,0,0x78);

    }

    else if (*(int *)(param_2 + 0x10) == 0xb) {

      iVar4 = *(int *)(*(int *)(*(int *)(param_3 + 0x10) + 0x14) + 0x1c);

      FUN_0040e3c0(0,sVar1,sVar2,uVar3 & 0xff,0xa0,0);

      FUN_0040e3c0(0,sVar1,sVar2,uVar3 & 0xff,0xa1,0);

      for (iVar6 = 0; iVar6 < 9; iVar6 = iVar6 + 1) {

        iVar7 = iVar5 + iVar6 * 0x19;

        FUN_0040e3c0(0,sVar1,iVar7,uVar3 & 0xff,0xa2,0);

        FUN_0040e3c0(0,sVar1,iVar7,uVar3 & 0xff,0xa3,0);

      }

      FUN_0040e3c0(0,sVar1,sVar2,uVar3 & 0xff,0xa4,0);

      FUN_0040e3c0(0,sVar1,sVar2,uVar3 & 0xff,0xa5,0);

      FUN_003c7e20(0,sVar1 + 0x16c,iVar5 + 0x77,uVar3 | 0xff00,1,6,4,

                   *(u16 *)(*(int *)(iVar4 + 4) + 2));

    }

  }

  return;

}

// FUN_0040B630 NONMATCHING


void FUN_0040b630(u32 param_1,u32 param_2,u16 param_3,u64 param_4)



{

  u32 *puVar1;

  u32 uVar2;

  u32 uVar3;

  u32 uVar4;

  int iVar5;

  u32 uStack_20;

  u32 uStack_1c;

  u16 uStack_18;

  int iStack_14;

  u32 uStack_10;

  

  iVar5 = (int)param_4;

  puVar1 = *(u32 **)(*(int *)(iVar5 + 0x24) + 0x44);

  uVar2 = puVar1[7];

  uVar3 = puVar1[8];

  FUN_0040e3c0(0,0,0,param_3 & 0xff,0x1b,0);

  uStack_10 = 0;

  *puVar1 = *puVar1 | 4;

  uStack_20 = param_1;

  uStack_1c = param_2;

  uStack_18 = param_3;

  iStack_14 = iVar5;

  FUN_003e0680(uVar2,0x40a7f0,&uStack_20);

  uVar4 = *puVar1;

  *puVar1 = uVar4 & 0xfffffffb;

  *puVar1 = uVar4 & 0xfffffffb | 4;

  FUN_003c4e70(param_4);

  *puVar1 = *puVar1 & 0xfffffffb;

  FUN_003e0680(uVar2,0x40a7f0,&uStack_20);

  if (uVar3 != 0) {

    uStack_10 = *(u32 *)(iVar5 + 0xc);

    uStack_20 = param_1;

    uStack_1c = param_2;

    uStack_18 = param_3;

    iStack_14 = iVar5;

    FUN_003e0680(uVar3,0x40b3a0,&uStack_20);

  }

  return;

}

// FUN_0040B780


void FUN_0040b780(u32 param_1,u32 param_2,u16 param_3,int param_4,int param_5)
{
  int uVar1;
  struct {
    u32 param1;
    u32 param2;
    u16 param3;
    s16 flags;
    int param4;
    int param5;
  } data;

  uVar1 = *(int *)(*(int *)(*(int *)(param_5 + 0x14) + 0x1c) + 0xc);
  memset_typed(&data,0,0x18);
  if (*(int *)(param_4 + 0xc) == param_5) {
    data.flags = data.flags | 1;
  }
  data.param1 = param_1;
  data.param2 = param_2;
  data.param3 = param_3;
  data.param4 = param_4;
  data.param5 = param_5;
  FUN_003e0680_typed(uVar1,(code)FUN_0040a7f0,&data);
  return;
}

// FUN_0040B840


void FUN_0040b840(int param_1)



{

  u32 *puVar1;
  u32 uVar2;

  

  puVar1 = *(u32 **)(*(int *)(param_1 + 0x24) + 0x44);

  puVar1[6] = 0;

  puVar1[4] = 1;

  *puVar1 = *puVar1 | 1;

  fclMisc003c9b00(puVar1[2],

               *(u32 *)(*(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x14) + 0x1c) + 4),0);

  FUN_003c9d00(puVar1[2],8);

  FUN_003c9e00(puVar1[2],3);
  FUN_003c9e30(puVar1[2],2,puVar1[6] ^ 1);

  uVar2 = FUN_003e0940();

  uVar2 = FUN_003c5460(uVar2);

  FUN_003e0c20(uVar2,0xd,0);

  return;

}

// FUN_0040B910 NONMATCHING


u32 FUN_0040b910(u64 param_1)



{

  u32 *puVar1;

  u32 uVar2;

  u8 bVar3;

  u8 bVar4;

  u16 uVar5;

  u16 uVar6;

  u32 uVar7;

  u32 uVar8;

  long lVar9;

  u64 uVar10;

  int iVar11;

  int iVar12;

  u8 auStack_20 [32];

  

  bVar4 = 0;

  bVar3 = 0;

  iVar11 = (int)param_1;

  puVar1 = *(u32 **)(*(int *)(iVar11 + 0x24) + 0x44);

  iVar12 = *(int *)(*(int *)(*(int *)(iVar11 + 0xc) + 0x14) + 0x1c);

  switch(puVar1[4]) {

  case 1:

  case 2:

  case 3:

  case 4:

    uVar8 = FUN_003c6d80();

    if ((uVar8 & 5) != 0) {

      return 0;

    }

    bVar4 = 1;

    break;

  case 5:

    puVar1[4] = 7;

    lVar9 = FUN_001749a0(*(u16 *)(*(int *)(iVar12 + 4) + 2));

    if (lVar9 == 0) {

      uVar5 = FUN_001756f0();

      uVar6 = FUN_00175410();

      if (uVar5 < uVar6) {

        uVar2 = *(u32 *)(iVar12 + 8);

        uVar7 = datGetMoney();

        if (uVar7 < uVar2) {

          sprintf((char *)auStack_20,&gp0xffffac10,uVar2);

          FUN_003c7bc0(0,auStack_20);

          FUN_003c7430(0x13);

        }

        else {

          sprintf((char *)auStack_20,&gp0xffffac10,uVar2);

          FUN_003c7bc0(0,auStack_20);

          FUN_003c7430(0x12);

          FUN_003c74e0(0);

          FUN_003c7560(1);

          puVar1[4] = 6;

          uVar10 = FUN_003e0940();

          uVar10 = FUN_003c5460(uVar10);

          FUN_003e0c20(uVar10,3,0);

        }

      }

      else {

        FUN_003c7430(0x16);

      }

    }

    else {

      FUN_003c7430(0x15);

    }

    break;

  case 6:

    lVar9 = FUN_003c7850();

    if (lVar9 == 0) {

      FUN_003c7700();

      lVar9 = FUN_003c7610();

      if (lVar9 == 0) {

        iVar12 = *(int *)(*(int *)(*(int *)(iVar11 + 0xc) + 0x14) + 0x1c);

        datAddMoney(-*(int *)(iVar12 + 8));

        FUN_00174fb0(*(u32 *)(iVar12 + 4));

        puVar1[4] = 8;

        uVar10 = FUN_003e0940();

        uVar10 = FUN_003c5460(uVar10);

        FUN_003e0c20(uVar10,3,1);

      }

      else {

        puVar1[4] = 1;

        uVar10 = FUN_003e0940();

        uVar10 = FUN_003c5460(uVar10);

        FUN_003e0c20(uVar10,3,2);

      }

    }

    break;

  case 7:

    lVar9 = FUN_003c7850();

    if (lVar9 == 0) {

      FUN_003c7700();

      puVar1[4] = 1;

    }

    break;

  case 8:

    puVar1[4] = 9;

    iVar12 = *(int *)(*(int *)(*(int *)(iVar11 + 0xc) + 0x14) + 0x1c);

    sprintf((char *)auStack_20,&gp0xfffface0,

                 iGpffffb7f4 + (u32)*(u16 *)(*(int *)(iVar12 + 4) + 2) * 0x11);

    FUN_003c7bc0(0,auStack_20);

    FUN_003c7430(0x14);

  case 9:

    lVar9 = FUN_003c7850();

    if (lVar9 == 0) {

      FUN_003c7700();

      puVar1[4] = 10;

    }

    break;

  case 10:

    *puVar1 = *puVar1 & 0xfffffffe;

    FUN_003c9d00(puVar1[2],0x10);

    FUN_003cde70(puVar1[3],1);

    return 1;

  }

  if (bVar4) {

    if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {

      if (((DAT_007e0952 & 0x4000) == 0) && ((DAT_007e095a & 0x4000) == 0)) {

        if (((DAT_007e094e & 0x40) == 0) && ((DAT_007e0958 & 0x40) == 0)) {

          if ((((DAT_007e094e & 8) == 0) && ((DAT_007e0958 & 8) == 0)) || (puVar1[6] != 1)) {

            if ((((DAT_007e094e & 4) == 0) && ((DAT_007e0958 & 4) == 0)) || (puVar1[6] != 0)) {

              if (((DAT_007e094e & 0x20) != 0) || ((DAT_007e0958 & 0x20) != 0)) {

                func_0010a4e0(0,0,0,2);

                puVar1[4] = 10;

                if (puVar1[6] == 1) {



                  uVar10 = FUN_003e0940();

                  uVar10 = FUN_003c5460(uVar10);

                  FUN_003e0c20(uVar10,0xe,1);

                }

                else {

                  uVar10 = FUN_003e0940();

                  uVar10 = FUN_003c5460(uVar10);

                  FUN_003e0c20(uVar10,0xd,1);

                }

              }

            }

            else {

              func_0010a4e0(0,0,0,5);

              puVar1[6] = 1;



              FUN_003cde00(puVar1[3],1);

              FUN_003c9e70(puVar1[2],(u8)puVar1[6] ^ 1);

              bVar3 = 1;

              uVar10 = FUN_003e0940();

              uVar10 = FUN_003c5460(uVar10);

              FUN_003e0c20(uVar10,0xd,1);

              uVar10 = FUN_003e0940();

              uVar10 = FUN_003c5460(uVar10);

              FUN_003e0c20(uVar10,0xe,0);

            }

          }

          else {

            func_0010a4e0(0,0,0,5);

            puVar1[6] = 0;



            FUN_003cdba0(puVar1[3],*(u16 *)(*(int *)(iVar12 + 4) + 2));

            FUN_003cde70(puVar1[3],1);

            FUN_003c9e70(puVar1[2],(u8)puVar1[6] ^ 1);

            bVar3 = 1;

            uVar10 = FUN_003e0940();

            uVar10 = FUN_003c5460(uVar10);

            FUN_003e0c20(uVar10,0xd,0);

            uVar10 = FUN_003e0940();

            uVar10 = FUN_003c5460(uVar10);

            FUN_003e0c20(uVar10,0xe,1);

          }

        }

        else if (puVar1[6] == 0) {

          puVar1[4] = 5;

          func_0010a4e0(0,0,0,1);

        }

      }

      else {

        if ((1 < *(u16 *)(iVar11 + 0x10)) && (lVar9 = FUN_003c5bb0(param_1), lVar9 != 0)) {

          func_0010a4e0(0,0,0,0);

          bVar3 = 1;

        }

        FUN_003c4dc0(param_1,iVar11 + 4);

      }

    }

    else {

      if ((1 < *(u16 *)(iVar11 + 0x10)) && (lVar9 = FUN_003c5af0(param_1), lVar9 != 0)) {

        func_0010a4e0(0,0,0,0);

        bVar3 = 1;

      }

      FUN_003c4dc0(param_1,iVar11 + 4);

    }

    if (bVar3) {

      if (puVar1[6] == 1) {

        FUN_003cdba0(puVar1[3],

                     *(u16 *)

                      (*(int *)(*(int *)(*(int *)(*(int *)(iVar11 + 0xc) + 0x14) + 0x1c) + 4) + 2));

      }

      else if (puVar1[6] == 0) {

        FUN_003c9d00(puVar1[2],4);

      }

      fclMisc003c9b00(puVar1[2],

                   *(u32 *)(*(int *)(*(int *)(*(int *)(iVar11 + 0xc) + 0x14) + 0x1c) + 4),0);

    }

  }

  return 0;

}

// FUN_0040C150


void FUN_0040c150(u32 param_1)



{
  __asm__ volatile (
      ".set noreorder       \n"
      "lw $v1, 0x24($a0)    \n"
      "lw $v1, 0x44($v1)    \n"
      "lw $v1, 0($v1)       \n"
      "andi $v1, $v1, 1     \n"
      ".set reorder"
      :
      :
      : "v1", "memory"
  );
}

// FUN_0040C170


u32 FUN_0040c170(void)
{
  u32 uVar1;
  u32 *puVar2;
  int iVar2;

  uVar1 = FUN_0017d030();
  iVar2 = 0;
  puVar2 = DAT_006aedc4;
  do {
    if (uVar1 <= *(u32 *)((u8 *)puVar2 + iVar2 * 8 + 4)) {
      return *(u32 *)((u8 *)puVar2 + iVar2 * 8);
    }
    uVar1 = uVar1 - *(u32 *)((u8 *)puVar2 + iVar2 * 8 + 4);
    iVar2 = iVar2 + 1;
  } while (uVar1 != 0);
  return 0;
}

// FUN_0040C1E0 NONMATCHING


void FUN_0040c1e0(long param_1,long param_2,long param_3)



{

  int iVar1;

  int iVar2;

  u32 uVar3;

  long lVar4;

  int iVar5;

  int *piVar6;

  

  if ((param_1 == 0) || (param_2 == 0)) {

    K_Assert((const char *)(u32)0x6aede8,0x273b);

  }

  iVar1 = *(int *)((int)param_1 + 0xc);

  piVar6 = (int *)*(u32 *)param_2;

  for (iVar5 = 0; iVar5 < (int)((u32 *)param_2)[1]; iVar5 = iVar5 + 1) {

    if (((*piVar6 == 0) || (lVar4 = datGetFlag(), lVar4 != 0)) &&

       ((piVar6[1] == 0 || (lVar4 = datGetFlag(), lVar4 != 0)))) {

      if (param_3 == 0) {

        iVar2 = *(u16 *)(iVar1 + 0x10) + 1;

      }

      else {

        iVar2 = *(int *)((int)param_3 + iVar5 * 4);

      }

      iVar2 = FUN_003c5a40(iVar1,iVar2,0xc,0);

      iVar2 = *(int *)(*(int *)(iVar2 + 0x14) + 0x1c);

      *(int **)(iVar2 + 4) = piVar6;

      uVar3 = FUN_003dfeb0(param_2);

      *(u32 *)(iVar2 + 8) = uVar3;

    }

    piVar6 = piVar6 + 4;

  }

  return;

}

// FUN_0040C310 NONMATCHING


void FUN_0040c310(int param_1)



{

  u32 *puVar1;

  u8 bVar2;

  u32 uVar3;

  long lVar4;

  int *piVar5;

  int iVar6;

  

  piVar5 = *(int **)(*(int *)(param_1 + 0xc) + 4);

  do {

    if (piVar5 == (int *)0x0) {

      return;

    }

    if (*piVar5 == 0xb) {

      puVar1 = *(u32 **)(piVar5[5] + 0x1c);

      lVar4 = FUN_0017c700();

      if (lVar4 == 0) {

        *puVar1 = *puVar1 | 1;

      }

      else {

        *puVar1 = *puVar1 & 0xfffffffe;

      }

    }

    else if (*piVar5 == 0xd) {

      puVar1 = *(u32 **)(piVar5[5] + 0x1c);

      for (iVar6 = 0; uVar3 = FUN_00175410(), iVar6 < (int)(uVar3 & 0xffff); iVar6 = iVar6 + 1) {

        lVar4 = datPersonaGetHeroPersona((short)iVar6);

        if (lVar4 != 0) {

          lVar4 = FUN_0017ca10(lVar4);

          bVar2 = 1;

          if (lVar4 == 1) goto LAB_0040c3c4;

        }

      }

      bVar2 = 0;

LAB_0040c3c4:

      if (bVar2) {

        *puVar1 = *puVar1 & 0xfffffffe;

      }

      else {

        *puVar1 = *puVar1 | 1;

      }

    }

    piVar5 = (int *)piVar5[4];

  } while( 1 );

}

// FUN_0040C460


void FUN_0040c460(u64 param_1,int param_2)



{

  FUN_003dff00(*(u32 *)(*(int *)(*(int *)(param_2 + 0x14) + 0x1c) + 8));

  return;

}

// FUN_0040C490


void FUN_0040c490(u64 param_1)



{

  FUN_003d9820(param_1,4,0);

  FUN_003d9820(param_1,0,0);

  FUN_003d9820(param_1,1,0);

  FUN_003d9820(param_1,5,0);

  FUN_003d9820(param_1,6,0);

  return;

}

// FUN_0040C520


void FUN_0040c520(u64 param_1)



{

  FUN_003d9820(param_1,4,1);

  FUN_003d9820(param_1,0,1);

  FUN_003d9820(param_1,1,1);

  FUN_003d9820(param_1,5,1);

  FUN_003d9820(param_1,6,1);

  return;

}

// FUN_0040C5B0


void FUN_0040c5b0(u64 param_1)



{

  FUN_003d9820(param_1,4,1);

  FUN_003d9820(param_1,0,1);

  FUN_003d9820(param_1,1,1);

  FUN_003d9820(param_1,2,1);

  FUN_003d9820(param_1,3,1);

  FUN_003d9820(param_1,7,1);

  return;

}

// FUN_0040C650


void FUN_0040c650(u64 param_1)



{

  FUN_003d9820(param_1,0,3);

  FUN_003d9820(param_1,7,1);

  return;

}

// FUN_0040C6A0


void FUN_0040c6a0(u64 param_1)



{

  FUN_003d9820(param_1,0,0);

  FUN_003d9820(param_1,7,0);

  return;

}

// FUN_0040C6F0 NONMATCHING


int FUN_0040c6f0(int param_1)



{

  int iVar1;

  u32 uVar2;

  int iVar3;

  u32 uVar4;

  u64 uVar5;

  int iVar6;

  u32 *puVar7;

  u32 *puVar8;

  u32 auStack_20 [8];

  

  if ((param_1 < 0) || (2 < param_1)) {

    K_Assert((const char *)(u32)0x6aede8,0x27ad);

  }

  uVar5 = FUN_003c58f0(0,0x10,7,0x1c);

  iVar3 = (int)uVar5;

  iVar1 = *(int *)(*(int *)(iVar3 + 0x24) + 0x44);

  *(int *)(iVar1 + 0xc) = iVar3;

  uVar4 = FUN_003dfeb0(iVar1);

  *(u32 *)(iVar1 + 8) = uVar4;

  *(int *)(iVar1 + 4) = param_1;

  if (param_1 == 2) {

    puVar8 = &DAT_006af930;

    puVar7 = auStack_20;

    iVar6 = 4;

    do {

      uVar4 = *puVar8;

      uVar2 = puVar8[1];

      puVar8 = puVar8 + 2;

      iVar6 = iVar6 + -1;

      *puVar7 = uVar4;

      puVar7[1] = uVar2;

      puVar7 = puVar7 + 2;

    } while (0 < iVar6);



  }

  else {


  }

  FUN_003c6ee0(uVar5);

  FUN_003c5e80(uVar5,0x40d330);

  FUN_003c5e20(uVar5,0x40d3b0);

  FUN_003c5ee0(uVar5,0x40d400);

  FUN_003c5f40(uVar5,0x40c460);

  FUN_003c6d40(uVar5,0,0);

  *(u16 *)(*(int *)(iVar3 + 0x24) + 6) = 10;

  *(u16 *)(*(int *)(iVar3 + 0x24) + 8) = 10;

  if (param_1 == 2) {

    FUN_003d9820(iVar1,4,0);

    FUN_003d9820(iVar1,0,0);

    FUN_003d9820(iVar1,1,0);

    FUN_003d9820(iVar1,5,0);

    FUN_003d9820(iVar1,6,0);

  }

  else {

    FUN_003d9820(iVar1,4,0);

    FUN_003d9820(iVar1,0,0);

    FUN_003d9820(iVar1,1,0);

    FUN_003d9820(iVar1,2,0);

    FUN_003d9820(iVar1,3,0);

    FUN_003d9820(iVar1,7,0);

  }

  return iVar1;

}

// FUN_0040C9A0
void FUN_0040c9a0(int param_1)




{

  if (param_1 == 0) {

    K_Assert((const char *)(DAT_006aede8 + 1) - 1,0x27d2);

  }

  FUN_003dff00(*(u32 *)((int)param_1 + 8));

  FUN_003c5a20(*(u32 *)((int)param_1 + 0xc));

  return;

}

// FUN_0040CA00 NONMATCHING


long FUN_0040ca00(u64 param_1)



{

  long lVar1;

  

  lVar1 = FUN_003c6270(*(u32 *)((int)param_1 + 0xc));

  if (lVar1 == 2) {

    FUN_003d9820(param_1,4,1);

    FUN_003d9820(param_1,0,1);

    FUN_003d9820(param_1,1,1);

    FUN_003d9820(param_1,2,1);

    FUN_003d9820(param_1,3,1);

    FUN_003d9820(param_1,7,1);

  }

  return lVar1;

}

// FUN_0040CAD0 NONMATCHING


void FUN_0040cad0(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  u32 uStack_20;

  u32 uStack_1c;

  u16 uStack_18;

  u16 uStack_16;

  int iStack_14;

  int iStack_10;

  

  iVar4 = 0;

  iVar1 = *(int *)(param_1 + 0xc);

  FUN_003c6380(iVar1);

  iVar5 = *(int *)(*(int *)(iVar1 + 0x24) + 0x2c);

  iVar2 = *(int *)(iVar1 + 0xc);

  do {

    if (iVar5 == 0) break;

    if (iVar5 != iVar2) {

      iVar3 = *(int *)(*(int *)(iVar5 + 0x14) + 0x1c);

      memset(&uStack_20,0,0x18);

      uStack_20 = **(u32 **)(iVar5 + 0x14);

      uStack_1c = (*(u32 **)(iVar5 + 0x14))[1];

      uStack_18 = (u16)*(u32 *)(*(int *)(iVar1 + 0x24) + 0x1c);

      iStack_14 = iVar1;

      iStack_10 = iVar5;

      FUN_003e0680(*(u32 *)(iVar3 + 8),0x40cc30,&uStack_20);

    }

    iVar5 = *(int *)(iVar5 + 0x10);

    iVar4 = iVar4 + 1;

  } while (iVar4 < *(int *)(*(int *)(iVar1 + 0x24) + 0x20));

  iVar5 = *(int *)(*(int *)(iVar2 + 0x14) + 0x1c);

  memset(&uStack_20,0,0x18);

  uStack_16 = uStack_16 | 1;

  uStack_20 = **(u32 **)(iVar2 + 0x14);

  uStack_1c = (*(u32 **)(iVar2 + 0x14))[1];

  uStack_18 = (u16)*(u32 *)(*(int *)(iVar1 + 0x24) + 0x1c);

  iStack_14 = iVar1;

  iStack_10 = iVar2;

  FUN_003e0680(*(u32 *)(iVar5 + 8),0x40cc30,&uStack_20);

  return;

}

// FUN_0040CC30 NONMATCHING


void FUN_0040cc30(u64 param_1,int param_2,int *param_3)



{

  u8 bVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  u32 *puVar5;

  long lVar6;

  int iVar7;

  int iVar8;

  u32 uVar9;

  u32 auStack_8 [2];

  

  iVar8 = *param_3 + (int)*(short *)(param_2 + 0x14);

  iVar7 = param_3[1] + (int)*(short *)(param_2 + 0x16);

  uVar9 = ((int)(short)param_3[2] * (int)*(short *)(param_2 + 0x26)) / 0xff;

  if (uVar9 != 0) {

    bVar1 = (*(u16 *)((int)param_3 + 10) & 1) != 0;

    iVar2 = param_3[3];

    iVar3 = *(int *)(iVar2 + 0x24);

    iVar4 = *(int *)(iVar3 + 0x44);

    switch(*(u32 *)(param_2 + 0x10)) {

    case 0:

      iVar2 = *(int *)(iVar4 + 4);

      if (iVar2 == 0) {

        FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x58,bVar1);

        FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x59,bVar1);

      }

      else if ((iVar2 == 2) || (iVar2 == 1)) {

        FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x14,bVar1);

        FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x15,bVar1);

      }

      auStack_8[0] = DAT_007cd9f8;

      auStack_8[1] = DAT_007cd9fc;

      puVar5 = *(u32 **)(*(int *)(param_3[4] + 0x14) + 0x1c);

      if ((*puVar5 & 1) != 0) {

        uVar9 = (u32)((float)(int)uVar9 * 0.5);

      }

      iVar2 = *(int *)(*(int *)(*(int *)(param_3[3] + 0x24) + 0x44) + 4);

      if (iVar2 == 0) {

        FUN_003b2cb0(0,iVar8 + 0x40,iVar7 + 0x57,uVar9 | 0xffffff00,

                     *(u8 *)(auStack_8 + (short)(u16)bVar1),1,

                     *(u32 *)(puVar5[1] + 8),0x10,0);

      }

      else if ((iVar2 == 2) || (iVar2 == 1)) {

        FUN_003b2cb0(0,iVar8 + 0x40,iVar7 + 0x61,uVar9 | 0xffffff00,

                     *(u8 *)(auStack_8 + (short)(u16)bVar1),1,

                     *(u32 *)(puVar5[1] + 8),0x10,0);

      }

      break;

    case 1:

      lVar6 = FUN_003dff80(param_1,0);

      if (lVar6 != 0) {

        iVar7 = iVar7 + *(short *)((int)lVar6 + 0x16);

        iVar8 = iVar8 + *(short *)((int)lVar6 + 0x14);

        iVar2 = *(int *)(*(int *)(*(int *)(param_3[3] + 0x24) + 0x44) + 4);

        if (iVar2 == 0) {

          FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x5d,0);

          FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x5e,0);

        }

        else if ((iVar2 == 2) || (iVar2 == 1)) {

          FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x16,0);

          FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x17,0);

        }

      }

      break;

    case 2:

      if (*(int *)(iVar4 + 4) == 0) {

        FUN_0040e3c0(0x40000000,iVar8,iVar7,uVar9 & 0xff,0x54,0);

        FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x55,0);

      }

      else if (*(int *)(iVar4 + 4) == 1) {

        FUN_0040e3c0(0x40000000,iVar8,iVar7,uVar9 & 0xff,0x12,0);

      }

      break;

    case 3:

      if (*(int *)(iVar4 + 4) == 0) {

        FUN_0040e3c0(0x3f800000,iVar8,iVar7,uVar9 & 0xff,0x56,0);

      }

      else if (*(int *)(iVar4 + 4) == 1) {

        FUN_0040e3c0(0,iVar8,iVar7,uVar9 & 0xff,0x13,0);

      }

      break;

    case 4:

      if (*(int *)(iVar4 + 4) != 0) {

        FUN_0040e3c0(0x41200000,iVar8,iVar7,uVar9 & 0xff,1,0);

      }

      break;

    case 5:

      FUN_0040e3c0(0x3f800000,iVar8,iVar7,uVar9 & 0xff,2,0);

      break;

    case 6:


      break;

    case 7:

      if (*(int *)(iVar4 + 4) == 0) {

        if (*(u32 *)(iVar3 + 0x20) <= (u32)*(u16 *)(iVar2 + 0x10)) {

          iVar2 = *(int *)(iVar3 + 0x28);

          FUN_0040e3f0(0,0,0x3f800000,0x3f800000,iVar8,iVar7,uVar9 & 0xff,0x5a,0,0,0);

          FUN_0040e3f0(0,0,0x3f800000,0x3f800000,iVar8,iVar7,uVar9 & 0xff,0x5b,0,0,0);

          FUN_0040e3f0(0,0,0x3f800000,0x3f800000,iVar8 + 0x176,

                       iVar7 + 0x54 + (iVar2 * 0x7c) / 0xffff,uVar9 & 0xff,0x5c,0,0,0);

        }

      }

      else if (*(u32 *)(iVar3 + 0x20) <= (u32)*(u16 *)(iVar2 + 0x10)) {

        iVar2 = *(int *)(iVar3 + 0x28);

        FUN_0040e3f0(0,0,0x3f800000,0x3f800000,iVar8,iVar7,uVar9 & 0xff,0x18,0,0,0);

        FUN_0040e3f0(0,0,0x3f800000,0x3f800000,iVar8,iVar7,uVar9 & 0xff,0x19,0,0,0);

        FUN_0040e3f0(0,0,0x3f800000,0x3f800000,iVar8 + 0x176,iVar7 + 0x54 + (iVar2 * 0x7c) / 0xffff,

                     uVar9 & 0xff,0x1a,0,0,0);

      }

    }

  }

  return;

}

// FUN_0040D330


void FUN_0040d330(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = *(int *)(*(int *)(param_1 + 0x24) + 0x44);

  FUN_003e0650(*(u32 *)(iVar1 + 8));

  for (iVar2 = *(int *)(param_1 + 4); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x10)) {

    FUN_003e0650(*(u32 *)(*(int *)(*(int *)(iVar2 + 0x14) + 0x1c) + 8));

  }

  FUN_003d9820(iVar1,1,1);

  return;

}

// FUN_0040D3B0 NONMATCHING


void FUN_0040d3b0(u32 param_1,u32 param_2,u16 param_3,int param_4)



{

  u32 uStack_20;

  u32 uStack_1c;

  u16 uStack_18;

  int iStack_14;

  u32 uStack_10;

  

  uStack_10 = 0;

  uStack_20 = param_1;

  uStack_1c = param_2;

  uStack_18 = param_3;

  iStack_14 = param_4;

  FUN_003e0680(*(u32 *)(*(int *)(*(int *)(param_4 + 0x24) + 0x44) + 8),0x40cc30,&uStack_20);

  return;

}

// FUN_0040D410


u32 FUN_0040d410(void)
{
  u32 uVar1;

  uVar1 = scrGetIntPara_u32(0);
  DAT_007cda00 = uVar1;
  switch (uVar1) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 8:
    FUN_003e0700_u32(uVar1);
    break;
  case 7:
    fclCombine003d02f0_i();
    break;
  default:
    DAT_007cda00 = 0xffffffff;
  }
  return 1;
}

// FUN_0040D490 NONMATCHING


u32 FUN_0040d490(void)



{

  long lVar1;

  

  lVar1 = scrGetCmdTimer();

  if (3 < lVar1) {

    switch(DAT_007cda00) {

    case 0:

    case 1:

    case 2:

    case 3:

    case 4:

    case 5:

    case 6:

    case 8:

      lVar1 = FUN_003e0920();

      if (lVar1 == 0) {

        return 1;

      }

      break;

    case 7:

      lVar1 = fclCombine003d04b0();

      if (lVar1 == 0) {

        return 1;

      }

      break;

    default:

      DAT_007cda00 = 0xffffffff;

    }

  }

  return 0;

}

// FUN_0040D540


u32 FUN_0040d540(void)



{

  switch(DAT_007cda00) {

  case 0:

  case 1:

  case 2:

  case 3:

  case 4:

  case 5:

  case 6:

  case 8:

    FUN_003e0b70();

    break;

  case 7:

    fclCombine003d0560();

    break;

  default:

    DAT_007cda00 = 0xffffffff;

  }

  return 1;

}

// FUN_0040D5B0


void FUN_0040d5b0(int param_1,int param_2,int param_3,int param_4,u32 param_5)



{


  FUN_0040d5e0(0.0f,param_1,param_2,param_3,param_4,param_5);


  return;
}

// FUN_0040D5E0


void FUN_0040d5e0(float param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6)



{


  FUN_0040d610(param_1,param_2,param_3,param_4,param_5,param_6,0);


  return;
}

// FUN_0040D610


void FUN_0040d610(float param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6,long param_7)



{


  FUN_0040d640(param_1,param_2,param_3,param_4,param_5,param_6,param_7,0);


  return;
}






































// FUN_0040D640 NONMATCHING
void FUN_0040d640(float param_1,int param_2,int param_3,int param_4,int param_5,u32 param_6,

                 long param_7,long param_8)



{

  u32 uVar1;

  int iVar2;

  u32 uVar3;

  u32 uVar4;

  float fStack_140;

  float fStack_13c;

  float fStack_138;

  u32 uStack_130;

  u32 uStack_12c;

  float fStack_128;

  float fStack_120;

  float fStack_11c;

  float fStack_118;

  float fStack_114;

  float fStack_100;

  float fStack_fc;

  float fStack_f8;

  u32 uStack_f0;

  u32 uStack_ec;

  float fStack_e8;

  float fStack_e0;

  float fStack_dc;

  float fStack_d8;

  float fStack_d4;

  float fStack_c0;

  float fStack_bc;

  float fStack_b8;

  u32 uStack_b0;

  u32 uStack_ac;

  float fStack_a8;

  float fStack_a0;

  float fStack_9c;

  float fStack_98;

  float fStack_94;

  float fStack_80;

  float fStack_7c;

  float fStack_78;

  u32 uStack_70;

  u32 uStack_6c;

  float fStack_68;

  float fStack_60;

  float fStack_5c;

  float fStack_58;

  float fStack_54;

  

  if (param_7 == 0) {

    RpSkyRenderStateSet(2,0x44);

    RpSkyRenderStateSet(3,0x717fb);

    (*DAT_00960090)(6,1);

    (*DAT_00960090)(8,1);

    (*DAT_00960090)(7,2);

    (*DAT_00960090)(9,2);

    (*DAT_00960090)(0xc,1);

    (*DAT_00960090)(0xe,0);

    (*DAT_00960090)(0x14,2);

    (*DAT_00960090)(1,0);

  }

  uVar1 = param_6 >> 0x18;

  uVar4 = param_6 >> 0x10 & 0xff;

  uVar3 = param_6 >> 8 & 0xff;

  param_6 = param_6 & 0xff;

  param_1 = DAT_00960088 - param_1;

  if (param_8 != 0) {

    (*DAT_00960090)(1,param_8);

    iVar2 = kwlnGetMainCamera();

    fStack_128 = 1.0 / *(float *)(iVar2 + 0x84);

    uStack_130 = 0;

    uStack_12c = 0;

    uStack_f0 = 0;

    uStack_ec = 0x3f800000;

    uStack_b0 = 0x3f800000;

    uStack_ac = 0;

    uStack_70 = 0x3f800000;

    uStack_6c = 0x3f800000;

    fStack_e8 = fStack_128;

    fStack_a8 = fStack_128;

    fStack_68 = fStack_128;

  }

  fStack_140 = (float)param_2;

  fStack_13c = (float)param_3;

  fStack_120 = (float)uVar1;

  fStack_11c = (float)uVar4;

  fStack_118 = (float)uVar3;

  fStack_114 = (float)param_6;

  fStack_100 = (float)param_2;

  fStack_fc = (float)(param_3 + param_5);

  fStack_e0 = (float)uVar1;

  fStack_dc = (float)uVar4;

  fStack_d8 = (float)uVar3;

  fStack_d4 = (float)param_6;

  fStack_c0 = (float)(param_2 + param_4);

  fStack_bc = (float)param_3;

  fStack_a0 = (float)uVar1;

  fStack_9c = (float)uVar4;

  fStack_98 = (float)uVar3;

  fStack_94 = (float)param_6;

  fStack_80 = (float)(param_2 + param_4);

  fStack_7c = (float)(param_3 + param_5);

  fStack_60 = (float)uVar1;

  fStack_5c = (float)uVar4;

  fStack_58 = (float)uVar3;

  fStack_54 = (float)param_6;

  fStack_138 = param_1;

  fStack_f8 = param_1;

  fStack_b8 = param_1;

  fStack_78 = param_1;

  (*DAT_009600a0)(4,&fStack_140,4);

  (*DAT_00960090)(1,0);

  return;

}





























// FUN_0040DCC0 NONMATCHING
void FUN_0040dcc0(float param_1,int param_2,int param_3,int param_4,int param_5,int param_6,

                 u32 param_7,int param_8,long param_9)



{

  u32 uVar1;

  u32 uVar2;

  u32 uVar3;

  float fVar4;

  float fVar5;

  float fStack_c0;

  float fStack_bc;

  float fStack_b8;

  float fStack_a0;

  float fStack_9c;

  float fStack_98;

  float fStack_94;

  float fStack_80;

  float fStack_7c;

  float fStack_78;

  float fStack_60;

  float fStack_5c;

  float fStack_58;

  float fStack_54;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  

  if (param_9 == 0) {

    RpSkyRenderStateSet(2,0x44);

    RpSkyRenderStateSet(3,0x717fb);

    (*DAT_00960090)(6,1);

    (*DAT_00960090)(8,1);

    (*DAT_00960090)(7,2);

    (*DAT_00960090)(9,2);

    (*DAT_00960090)(0xc,1);

    (*DAT_00960090)(0xe,0);

    (*DAT_00960090)(0x14,2);

    (*DAT_00960090)(1,0);

  }

  uVar1 = param_7 >> 0x18;

  uVar3 = param_7 >> 0x10 & 0xff;

  uVar2 = param_7 >> 8 & 0xff;

  param_7 = param_7 & 0xff;

  param_1 = DAT_00960088 - param_1;

  fVar5 = DAT_007cae00 + DAT_007caf14 * (float)param_8;

  fVar4 = (float)cosf(fVar5);

  fVar5 = (float)sinf(fVar5);

  fStack_c0 = (float)param_2 + (float)param_4 * fVar4;

  fStack_bc = (float)param_3 + (float)-param_4 * fVar5;

  fStack_a0 = (float)uVar1;

  fStack_9c = (float)uVar3;

  fStack_98 = (float)uVar2;

  fStack_94 = (float)param_7;

  fVar5 = DAT_007cae00 + DAT_007caf14 * (float)(param_8 + 0x78);

  fStack_b8 = param_1;

  fVar4 = (float)cosf(fVar5);

  fVar4 = (float)param_5 * fVar4;

  fVar5 = (float)sinf(fVar5);

  fStack_80 = (float)param_2 + fVar4;

  fStack_7c = (float)param_3 + (float)-param_5 * fVar5;

  fStack_60 = (float)uVar1;

  fStack_5c = (float)uVar3;

  fStack_58 = (float)uVar2;

  fStack_54 = (float)param_7;

  fVar5 = DAT_007cae00 + DAT_007caf14 * (float)(param_8 + -0x78);

  fStack_78 = param_1;

  fVar4 = (float)cosf(fVar5);

  fVar4 = (float)param_6 * fVar4;

  fVar5 = (float)sinf(fVar5);

  fStack_40 = (float)param_2 + fVar4;

  fStack_3c = (float)param_3 + (float)-param_6 * fVar5;

  fStack_20 = (float)uVar1;

  fStack_1c = (float)uVar3;

  fStack_18 = (float)uVar2;

  fStack_14 = (float)param_7;

  fStack_38 = param_1;

  (*DAT_009600a0)(3,&fStack_c0,3);

  (*DAT_00960090)(1,0);

  return;

}
