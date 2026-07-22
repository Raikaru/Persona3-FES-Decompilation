#include "temporary.h"

/* auto-extern (generated) */
extern u32* puGpffffbd04;
extern u8 LAB_00490d80;
extern u8 LAB_004944a0;
extern u8 LAB_004a9be0;

typedef int (*code)(...);
extern long thunk_FUN_004c3970(int param_1,u32 param_2,long param_3,int param_4,long param_5,u32 param_6);
#pragma alias thunk_FUN_004c3970_u32 thunk_FUN_004c3970
extern u32 thunk_FUN_004c3970_u32(int param_1,u32 param_2,int param_3,u32 param_4,u32 param_5,u32 param_6);
typedef u8 bool;
#ifndef CONCAT44
#define CONCAT44(hi, lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif
#ifndef CONCAT22
#define CONCAT22(hi, lo) ((u32)((((u32)(u16)(hi)) << 16) | (u16)(lo)))
#endif

typedef union Vec128 { struct { u32 _0_4_; u32 _4_4_; u32 _8_4_; u32 _12_4_; }; struct { u64 _0_8_; u64 _8_8_; }; u8 _bytes[16]; } Vec128;
static Vec128 rwVecZero(void) { Vec128 v; v._0_8_=0; v._8_8_=0; return v; }
static Vec128 rwVecKeep(Vec128 v) { return v; }
#define _lqc2(x) rwVecZero()
#define _sqc2(x) rwVecKeep(x)
#define _qmtc2(x) rwVecZero()
#define _qmfc2(x) rwVecZero()
#define _vwaitq() ((u32)0)
#define _ctc2(x) ((void)0)
#define _vnop() ((void)0)
#define DI() ((void)0)
#define EI() ((void)0)
#define SYNC(x) ((void)0)
#define FlushCache(x) ((void)0)
#define _pcpyld(...) rwVecZero()
#define _pexew(...) rwVecZero()
#define _ppacw(...) rwVecZero()
#define _vabs(...) rwVecZero()
#define _vadd(...) rwVecZero()
#define _vaddabc(...) rwVecZero()
#define _vaddi(...) rwVecZero()
#define _vmadd(...) rwVecZero()
#define _vmadda(...) rwVecZero()
#define _vmaddabc(...) rwVecZero()
#define _vmaddbc(...) rwVecZero()
#define _vmax(...) rwVecZero()
#define _vmini(...) rwVecZero()
#define _vmsubbc(...) rwVecZero()
#define _vmul(...) rwVecZero()
#define _vmula(...) rwVecZero()
#define _vmulabc(...) rwVecZero()
#define _vmulbc(...) rwVecZero()
#define _vmuli(...) rwVecZero()
#define _vsub(...) rwVecZero()
extern u32 DAT_006b4608;
extern u32 DAT_006b4610;
extern u32 DAT_006b4618;
extern u32 DAT_006b4620;
extern u32 DAT_006b4650;
extern u32 DAT_006b4652;
extern u32 DAT_006b46d0;
extern u32 DAT_006b46d2;
extern u32 DAT_006b46d4;
extern u32 DAT_006b46d6;
extern u32 DAT_006b46d8;
extern u32 DAT_006b46da;
extern u32 DAT_006b46dc;
extern u32 DAT_006b46de;
extern u32 DAT_006b46e0;
extern u32 DAT_006b46e2;
extern u32 DAT_006b46e4;
extern u32 DAT_006b46e6;
extern u32 DAT_006b4712;
extern u32 DAT_006b4714;
extern u32 DAT_006b4716;
extern u32 DAT_006b4718;
extern u32 DAT_006b471a;
extern u32 DAT_006b471c;
extern u32 DAT_006b471e;
extern u32 DAT_006b477a;
extern u32 DAT_006b477c;
extern u32 DAT_006b477e;
extern u32 DAT_006b4780;
extern u32 DAT_006b4782;
extern u32 DAT_006b4784;
extern u32 DAT_006b4786;
extern u32 DAT_006b4788;
extern u32 DAT_006b478a;
extern u32 DAT_006b478c;
extern u32 DAT_006b478e;
extern u32 DAT_006b4790;
extern u32 DAT_006b4792;
extern u32 DAT_006b4794;
extern u32 DAT_006b4796;
extern u32 DAT_006b4798;
extern u32 DAT_006b479a;
extern u32 DAT_006b479c;
extern u32 DAT_006b479e;
extern u32 DAT_006b47a0;
extern u32 DAT_006b47a2;
extern u32 DAT_006b47a4;
extern u32 DAT_006b47a6;
extern u32 DAT_006b47ae;
extern u32 DAT_006b481a;
extern u32 DAT_006b4a48;
extern u32 DAT_006b4a50;
extern u32 DAT_006b4a78;
extern u32 DAT_006b4a80;
extern u32 DAT_006b4a90;
extern u32 DAT_006b4ab0;
extern u32 DAT_006b4ab4;
extern u32 DAT_006b4ab8;
extern u32 DAT_006b4abc;
extern u32 DAT_006b4ac0;
extern u32 DAT_006b4ac2;
extern u32 DAT_006b4ac4;
extern u32 DAT_006b4ac6;
extern u32 DAT_006b4ac8;
extern u32 DAT_006b4b20;
extern u32 DAT_006b4b28;
extern u32 DAT_006b4b80;
extern u32 DAT_006b4b82;
extern u32 DAT_006b4b84;
extern u32 DAT_006b4e00;
extern u32 DAT_007bc460;
extern u32 DAT_007bc6b0;
extern u32 DAT_007bc730;
extern u32 DAT_007caf94;
extern u32 DAT_007cafa8;
extern u32 DAT_007cafc0;
extern u32 DAT_007cb134;
extern u32 DAT_007cb138;
extern u32 DAT_007cdb10;
extern u32 DAT_007ce290;
extern u32 DAT_007ce6ac;
extern u32 DAT_007ce6bc;
extern u32 DAT_007ce6c0;
extern u32 DAT_007ce6c4;
extern u32 DAT_007ce6c8;
extern u32 DAT_007ce6cc;
extern u32 DAT_007ce6d0;
extern u32 DAT_007ce6d4;
extern u32 DAT_007ce6e0;
extern u32 DAT_007ce6e4;
extern u32 DAT_007ce6e8;
extern u32 DAT_007ce6ec;
extern u32 DAT_007ce6f0;
extern u32 DAT_007ce6f4;
extern u32 DAT_007ce700;
extern u32 DAT_007ce704;
extern u32 DAT_007ce70c;
extern u32 DAT_007ce710;
extern u32 DAT_007ce714;
extern u32 DAT_007ce718;
extern u32 DAT_007e094e;
extern u32 DAT_007e0952;
extern u32 DAT_007e0958;
extern u32 DAT_007e095a;
extern u32 DAT_0086be00;
extern u32 DAT_0086e6e8;
extern u32 DAT_0086e6f0;
extern u32 DAT_0086e6f4;
extern u32 DAT_0086e808;
extern u32 DAT_0086e80c;
extern u32 DAT_0086e810;
extern u32 DAT_0086e848;
extern u32 DAT_0086e9cc;
extern u32 DAT_0086eb8c;
extern u32 DAT_0086ed4c;
extern u32 DAT_0086eda0;
extern u32 DAT_0086ede8;
extern u32 DAT_0086edf4;
extern u32 DAT_0086ef08;
extern u32 DAT_0086ef0c;
extern u32 DAT_0086ef10;
extern u32 DAT_0086ef2c;
extern u32 DAT_0086ef38;
extern u32 DAT_0086ef39;
extern u32 DAT_0086ef3a;
extern u32 DAT_0086ef3b;
extern u32 DAT_0086ef3c;
extern u32 DAT_008717a0;
extern u32 DAT_008717e8;
extern u32 DAT_008717f0;
extern u32 DAT_008717f4;
extern u32 DAT_0087190c;
extern u32 DAT_0087193a;
extern u32 DAT_0087193b;
extern u32 DAT_0087193c;
extern u32 DAT_00871948;
extern u32 DAT_0087194a;
extern u32 DAT_0087194c;
extern u32 DAT_00871954;
extern u32 DAT_00871958;
extern u32 DAT_008719b0;
extern u32 DAT_0095c0e0;
extern u32 DAT_0095c0e4;
extern u32 DAT_0095c0e8;
extern u32 DAT_0095c0ec;
extern u32 DAT_0095c0f0;
extern u32 DAT_0095c0f4;
extern u32 DAT_0095c0f8;
extern u32 DAT_0095c0fc;
extern u32 DAT_0095c100;
extern u32 DAT_0095c110;
extern u32 DAT_0095c210;
extern u32 DAT_0095c21e;
extern u32 DAT_0095c21f;
extern u32 DAT_0095c220;
extern u32 DAT_0095c221;
extern u32 DAT_0095c23e;
extern u32 DAT_0095c23f;
extern u32 DAT_0095c240;
extern u32 DAT_0095c241;
extern u32 DAT_0095c258;
extern u32 DAT_0095c25c;
extern u32 DAT_0095c260;
extern u32 DAT_00960088;
extern code DAT_00960090;
extern code DAT_009600a0;
extern code DAT_0096017c;
extern code DAT_00960184;
extern u32 PTR_DAT_006b46f0;
extern u32 PTR_DAT_006b4720;
extern u32 PTR_DAT_006b4de0;
extern u32 PTR_FUN_006b4e60;
extern u8 cGpffffb9cc;
extern u32 fGpffff8110;
extern u32 fGpffff8248;
extern u32 fGpffff82d8;
extern u32 gp0xffffae24;
extern u32 gp0xffffb9f7;
extern u32 iGpffffb418;
extern u32 iGpffffb5a0;
extern u32 iGpffffb9fc;
extern u32 iGpffffba08;
extern u32 iGpffffba20;
extern u32 iGpffffba24;
extern u32 uGpffff82b8;
extern u32 uGpffff82d0;
extern u32 uGpffff82d4;
extern u32 uGpffffae20;
extern u32 uGpffffb418;
extern u32 uGpffffb9cc;
extern u32 uGpffffb9dc;
extern u32 uGpffffb9e0;
extern u32 uGpffffb9e4;
extern u32 uGpffffba00;
extern u32 uGpffffba04;
extern u32 uGpffffba08;
extern u32 uGpffffba28;
extern char getCopCondition(int,int);

extern code FUN_00100d80;
extern code FUN_00100ec0;
extern code FUN_001016b0;
extern code FUN_00102100;
extern code FUN_001023a0;
extern code FUN_00108570;
extern code FUN_001085c0;
extern code FUN_00108670;
extern code FUN_00108710;
extern code FUN_00108fd0;
extern code FUN_0010a4e0;
extern code FUN_0010c1a0;
extern code FUN_0010c3a0;
extern code FUN_00111f30;
extern code FUN_001120c0;
extern code FUN_00112370;
extern code FUN_00112420;
extern code FUN_001124b0;
extern code FUN_001126b0;
extern code FUN_00112740;
extern code FUN_001127d0;
extern code FUN_00113a30;
extern code FUN_001140d0;
extern code FUN_001158b0;
extern code FUN_00115980;
extern code FUN_001159f0;
extern code FUN_00115bc0;
extern code FUN_0016c470;
extern code FUN_0016c4f0;
extern code FUN_0016c570;
extern code FUN_0016c5f0;
extern code FUN_0016c920;
extern code FUN_0016c970;
extern code FUN_0016cf40;
extern code FUN_0016cf90;
extern code FUN_0016f190;
extern code FUN_0016f1f0;
extern code FUN_0016f490;
extern code FUN_00170a40;
extern code FUN_00170ab0;
extern code FUN_00170b20;
extern code FUN_00170b90;
extern code FUN_00173300;
extern code FUN_00173380;
extern code FUN_00177410;
extern code FUN_0017b500;
extern code FUN_0017b5b0;
extern code FUN_0017b660;
extern code FUN_0017b860;
extern code FUN_0017be10;
extern code FUN_001831e0;
extern code FUN_0018bee0;
extern code FUN_0018c0c0;
extern code FUN_0018eb30;
extern code FUN_00194b20;
extern code FUN_00194b80;
extern code FUN_00195020;
extern code FUN_00195460;
extern code FUN_00198590;
extern code FUN_001a0040;
extern code FUN_001a0250;
extern code FUN_001a02c0;
extern code FUN_001a0dc0;
extern code FUN_001a5320;
extern code FUN_001a56b0;
extern code FUN_001a56c0;
extern code FUN_001a56d0;
extern code FUN_001a5700;
extern code FUN_001a57a0;
extern code FUN_001a5aa0;
extern code FUN_001a91b0;
extern code FUN_001a9390;
extern code FUN_001a9760;
extern code FUN_001aaa20;
extern code FUN_001aaac0;
extern code FUN_001acc30;
extern code FUN_001ad870;
extern code FUN_001ad910;
extern code FUN_001ad920;
extern code FUN_001ad940;
extern code FUN_001adc20;
extern code FUN_001adff0;
extern code FUN_001af930;
extern code FUN_001afa20;
extern code FUN_001aff70;
extern code FUN_001b0020;
extern code FUN_001b00c0;
extern code FUN_001b01b0;
extern code FUN_001b01d0;
extern code FUN_001b0220;
extern code FUN_001b0230;
extern code FUN_001b0240;
extern code FUN_001b0250;
extern code FUN_001b0260;
extern code FUN_001b9120;
extern code FUN_001bf220;
extern code FUN_001c6450;
extern code FUN_001c65e0;
extern code FUN_001c6720;
extern code FUN_001c6d70;
extern code FUN_001c6dd0;
extern code FUN_001c7130;
extern code FUN_001c7160;
extern code FUN_001c7270;
extern code FUN_001c7b10;
extern code FUN_001cd670;
extern code FUN_001d0110;
extern code FUN_001d22a0;
extern code FUN_001d3810;
extern code FUN_001d8b00;
extern code FUN_001d8c60;
extern code FUN_001d8d80;
extern code FUN_001d8e60;
extern code FUN_001dde00;
extern code FUN_001ded40;
extern code FUN_001e1360;
extern code FUN_001e13c0;
extern code FUN_00269690;
extern code FUN_002699a0;
extern code FUN_002699d0;
extern code FUN_00269a10;
extern code FUN_00269c80;
extern code FUN_00269ca0;
extern code FUN_002ff340;
extern code FUN_002ff760;
extern code FUN_002ff790;
extern code FUN_00316e00;
extern code FUN_00316f70;
extern code FUN_003174e0;
extern code FUN_003182d0;
extern code FUN_00318540;
extern code FUN_00318b60;
extern code FUN_00318ed0;
extern code FUN_0031c1d0;
extern code FUN_0035bb40;
extern code FUN_0035bc00;
extern code FUN_0035c1a0;
extern code FUN_003952d0;
extern code FUN_003b2cb0;
extern code FUN_003b5d10;
extern code FUN_003b5d50;
extern code FUN_003b6030;
extern code FUN_003b7090;
extern code FUN_003bb010;
extern code FUN_003c72d0;
extern code FUN_003c7430;
extern code FUN_003c74e0;
extern code FUN_003c7560;
extern code FUN_003c75b0;
extern code FUN_003c77a0;
extern code FUN_003c7850;
extern code FUN_003c78d0;
extern code FUN_003c7b90;
extern code FUN_00421fe0;
extern code FUN_004221a0;
extern code FUN_004222d0;
extern code FUN_004229d0;
extern code FUN_00422c10;
extern code FUN_00422c30;
extern code FUN_00422c90;
extern code FUN_00423fe0;
extern code FUN_00427830;
extern code FUN_00427a10;
extern code FUN_00427db0;
extern code FUN_00427de0;
extern code FUN_00427e20;
extern code FUN_00427e50;
extern code FUN_00427e60;
extern code FUN_00427e70;
extern code FUN_00429e80;
extern code FUN_00488f30;
extern code FUN_004c31b0;
extern code FUN_004c3880;
extern code FUN_004c38c0;
extern code FUN_004c69f0;
extern code FUN_004c6ac0;
extern code FUN_004c6be0;
extern code FUN_004d0f00;
extern code FUN_004d1260;
extern code FUN_004d7f60;
extern code FUN_00521250;
#pragma alias FUN_00521250_copy FUN_00521250
extern void FUN_00521250_copy(u64 destination,u64 source,u32 size);
#pragma alias FUN_00521250_u32 FUN_00521250
extern void FUN_00521250_u32(u32 destination,u32 source,u32 size);
extern code FUN_00521408;
extern code FUN_00523e68;
extern code FUN_00524388;
extern code FUN_00524670;
extern code FUN_00524828;
extern code FUN_0052e878;
extern code FUN_0052ea18;

char FUN_00435440(char param_1);
char FUN_0043bc20(char param_1);
float FUN_0045b4e0(long param_1);
float FUN_004693a0(int param_1);
float FUN_0047cfd0(u32 *param_1,u8 (*param_2) [12],u8 (*param_3) [12], int param_4,int param_5);
float FUN_004a9560(float param_1,int param_2,u8 *param_3);
float FUN_004aa2c0(void);
int * FUN_00496cd0(u32 param_1,u32 *param_2,u64 param_3,u16 *param_4);
int * FUN_004ac120(int *param_1,u64 param_2);
int * FUN_004ac240(int *param_1);
int FUN_0044f120(float *param_1);
int FUN_0044f170(int param_1);
int FUN_00457410(void);
int FUN_0045edd0(u32 *param_1);
int FUN_0045f540(int param_1,int param_2);
int FUN_00465b40(int param_1);
int FUN_00468350(int param_1);
int FUN_0046ad20(int *param_1,int param_2);
int FUN_0046b060(int param_1,u32 *param_2,int param_3);
int FUN_004753d0(int param_1,u32 param_2);
int FUN_00475540(int param_1,u64 param_2,u64 param_3,u32 param_4);
int FUN_00489320(int *param_1);
int FUN_00489ae0(int param_1);
int FUN_0048a7a0(int param_1);
int FUN_0048d200(int param_1);
int FUN_0048e4f0(long param_1);
int FUN_0048e890(int *param_1,long param_2,u64 param_3,int param_4);
int FUN_0048ed20(int param_1,int param_2);
int FUN_0048ede0(int param_1);
int FUN_0048ee30(int param_1,int param_2);
int FUN_004912b0(int param_1);
int FUN_00491cc0(int param_1);
int FUN_00492f80(int param_1,int param_2);
int FUN_00493cb0(u64 param_1);
int FUN_00495340(int *param_1,int param_2);
int FUN_004964f0(int param_1,char *param_2);
int FUN_00499400(int param_1,u64 param_2,int param_3,int param_4);
int FUN_0049c560(int param_1);
int FUN_0049c5c0(int param_1);
int FUN_0049c620(int param_1);
int FUN_0049d4d0(int param_1,int param_2,int *param_3,int *param_4,int *param_5,int *param_6);
int FUN_0049ecd0(int param_1);
int FUN_0049f340(int param_1);
int FUN_004a0ce0(int param_1,int *param_2,int param_3,u32 param_4);
int FUN_004a26d0(int param_1,int *param_2,int param_3,u32 param_4);
int FUN_004a5200(void);
int FUN_004a5290(void);
int FUN_004a5320(void);
int FUN_004a6630(int param_1,float *param_2,int param_3,int *param_4,int *param_5);
int FUN_004ab0e0(u64 param_1);
int FUN_004ace80(int param_1,float *param_2,u64 param_3,u32 *param_4,int *param_5);
long FUN_0045ec40(u16 param_1,u16 param_2,u32 *param_3,u32 param_4);
long FUN_0045efe0(u64 param_1);
long FUN_0045f140(u64 param_1,u16 param_2,u16 param_3,u64 param_4, u32 *param_5);
long FUN_00464280(u32 param_1);
long FUN_00464540(u64 param_1);
long FUN_00467c20(long param_1,u64 param_2,int param_3);
long FUN_0046bab0(long param_1,u64 param_2);
long FUN_0046bd00(long param_1,u64 param_2);
long FUN_0046bfb0(float param_1,long param_2,u8 *param_3,float *param_4,u32 param_5);
long FUN_00474260(u32 param_1,u32 param_2,u64 param_3,u64 param_4);
long FUN_00475d60(u64 param_1,u64 param_2,u64 param_3,u32 param_4, u32 param_5);
long FUN_0047ab70(void);
long FUN_0047b1a0(void);
long FUN_0047bb40(int param_1,int param_2,u32 param_3);
long FUN_0048a9a0(long param_1,u64 param_2);
long FUN_0048af80(u32 param_1);
long FUN_0048dab0(int param_1,long param_2,u64 param_3);
long FUN_00490050(u64 param_1);
long FUN_00490dc0(u64 param_1,int *param_2,int *param_3);
long FUN_00491880(void);
long FUN_00491b40(u64 param_1);
long FUN_00491de0(void);
long FUN_004920a0(u64 param_1);
long FUN_00494580(u64 param_1);
long FUN_004947c0(u8 param_1);
long FUN_00494be0(void);
long FUN_00494e30(u64 param_1);
long FUN_004954c0(u64 param_1,long param_2);
long FUN_00495b10(long param_1);
long FUN_00496230(u64 param_1,char *param_2,u32 param_3);
#pragma alias FUN_00496230_u32 FUN_00496230
extern long FUN_00496230_u32(u32 param_1,u32 param_2,u32 param_3);
long FUN_00497130(u64 param_1,long param_2,u64 param_3,u64 param_4,long param_5);
long FUN_00498e70(int param_1);
long FUN_00499140(long param_1,u32 param_2);
long FUN_0049a080(long param_1);
long FUN_0049a400(u32 *param_1);
long FUN_0049c810(void);
long FUN_0049fe40(long param_1,int param_2,long param_3);
long FUN_0049fec0(long param_1,u32 param_2);
long FUN_004a35c0(long param_1,long param_2,u32 param_3);
long FUN_004a38f0(long param_1,long param_2,long param_3,long param_4);
long FUN_004a3a80(long param_1,long param_2,long param_3,long param_4);
long FUN_004a3c10(long param_1,long param_2,long param_3);
long FUN_004a3d70(long param_1,u32 param_2);
long FUN_004a3db0(long param_1,long param_2,long param_3);
long FUN_004a3e30(long param_1,int param_2,long param_3);
long FUN_004a5470(void);
long FUN_004a6ce0(u32 param_1,long param_2,u8 *param_3,u32 *param_4, u64 param_5);
long FUN_004a6eb0(float param_1,long param_2,u8 *param_3,float *param_4,float *param_5);
long FUN_004a7820(long param_1,u64 param_2,u32 param_3,u32 param_4);
long FUN_004a9490(long param_1);
long FUN_004a98a0(u64 param_1);
long FUN_004ac570(void);
long FUN_004ac5f0(long param_1);
long FUN_004ac710(long param_1);
long FUN_004acb90(u64 param_1);
long FUN_004aeea0(u64 param_1);
long FUN_004af210(int *param_1,int *param_2,u32 param_3,u64 param_4);
short * FUN_00496e80(int param_1,short param_2,short param_3);
short FUN_0043b980(char param_1,u64 param_2);
short FUN_0043bda0(char param_1,char param_2);
u16 FUN_00435660(char param_1);
u16 FUN_0043c180(char param_1);
u16 FUN_0043c340(char param_1);
u16 FUN_00453460(void);
u32 * FUN_0048f580(u64 param_1,int *param_2,int param_3,u32 param_4);
u32 * FUN_0048fbd0(u64 param_1,u64 param_2,u64 param_3,u32 param_4);
u32 * FUN_004a7e40(u32 *param_1,u32 param_2,u32 param_3,char *param_4);
u32 * FUN_004a8980(u32 *param_1,u64 param_2,u32 param_3,u64 param_4);
u32 * FUN_004a90f0(void);
u32 * FUN_004a9a80(u64 param_1);
u32 * FUN_004ab8c0(void);
u32 FUN_00431880(int param_1);
u32 FUN_00431aa0(u64 param_1);
u32 FUN_00432050(u64 param_1);
u32 FUN_00432600(u64 param_1);
u32 FUN_00432bb0(u64 param_1);
u32 FUN_00433160(int param_1);
u32 FUN_00433810(char param_1,char param_2);
u32 FUN_004339d0(int param_1);
u32 FUN_00433de0(int param_1);
u32 FUN_00434770(float param_1,float param_2,u64 param_3,float *param_4);
u32 FUN_00434920(float param_1,float param_2,int param_3,float *param_4);
u32 FUN_004352e0(void);
u32 FUN_00437e20(char param_1);
u32 FUN_0043a230(char param_1);
u32 FUN_0043a9d0(u64 param_1,u64 param_2,char param_3);
u32 FUN_0043c500(int param_1);
u32 FUN_0043c910(char param_1);
u32 FUN_0043ca30(u64 param_1);
u32 FUN_00449fe0(float param_1,float param_2,float param_3,float param_4,int param_5,short param_6);
u32 FUN_0044a110(float param_1,float param_2,float param_3,float param_4,int param_5,short param_6);
u32 FUN_0044f300(char param_1);
u32 FUN_0044ffb0(int param_1);
u32 FUN_004514a0(char param_1);
u32 FUN_004523c0(u64 param_1,char param_2);
u32 FUN_00452a70(char param_1,char param_2);
u32 FUN_004534b0(char param_1);
u32 FUN_00453ed0(char param_1,char param_2,char param_3,u32 *param_4,char param_5,char param_6);
u32 FUN_004541f0(int param_1);
u32 FUN_00457470(int param_1);
u32 FUN_004575e0(int param_1);
u32 FUN_004589e0(void);
u32 FUN_00458a80(char param_1,char param_2);
u32 FUN_00458cb0(u64 param_1,char param_2,char param_3);
u32 FUN_00459790(u64 param_1,char param_2);
u32 FUN_00459e00(char param_1);
u32 FUN_00459e80(int param_1);
u32 FUN_0045a020(int param_1);
u32 FUN_0045a280(u64 param_1,int param_2);
u32 FUN_0045af40(void);
u32 FUN_0045afd0(float param_1,long param_2,int param_3,int param_4,int param_5,int param_6, u8 param_7,u8 param_8,short param_9);
u32 FUN_0045b190(long param_1);
u32 FUN_0045b420(long param_1,long param_2);
u32 FUN_0045df00(int param_1);
u32 FUN_0045e3e0(u64 param_1);
u32 FUN_0045e8c0(u64 param_1);
u32 FUN_0045eaf0(void);
u32 FUN_0045eba0(void);
u32 FUN_00465590(int param_1,u64 param_2);
u32 FUN_00466710(int param_1);
u32 FUN_00466720(int param_1);
u32 FUN_00466730(u32 *param_1);
u32 FUN_00469030(int param_1);
u32 FUN_00469340(int param_1);
u32 FUN_004695f0(int param_1);
u32 FUN_00469650(int param_1);
u32 FUN_004696b0(int param_1);
u32 FUN_00469710(int param_1);
u32 FUN_004698e0(int param_1);
u32 FUN_00469a90(void);
u32 FUN_00469ce0(void);
u32 FUN_00469cf0(void);
u32 FUN_0046a6c0(int param_1,u64 param_2,u64 param_3,u64 param_4);
u32 FUN_0046a6f0(int param_1,u64 param_2,u64 param_3,u64 param_4);
u32 FUN_0046a720(int param_1,u64 param_2,u64 param_3,u64 param_4);
u32 FUN_0046a750(u64 param_1);
u32 FUN_0046a890(u64 param_1);
u32 FUN_0046eb10(int param_1,u32 *param_2);
u32 FUN_00473600(int *param_1,u32 param_2);
u32 FUN_00473b10(int *param_1,u32 param_2);
u32 FUN_00473fb0(u32 param_1);
u32 FUN_00474640(int param_1,int *param_2,u32 param_3,u32 param_4);
u32 FUN_00474a80(int param_1);
u32 FUN_00478440(int param_1,u32 *param_2);
u32 FUN_00478e80(u64 param_1,u32 param_2);
u32 FUN_00479840(int param_1,u32 *param_2);
u32 FUN_0047a210(u64 param_1,int param_2);
u32 FUN_0047a510(u64 param_1,u64 param_2,u64 param_3,u32 param_4);
u32 FUN_0047abf0(int param_1,u32 *param_2);
u32 FUN_0047bd20(u64 param_1);
u32 FUN_0047de30(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_0047e9e0(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5);
u32 FUN_0047fb10(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_00480c30(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_00481860(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5);
u32 FUN_00482a50(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_00483170(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_004861b0(u64 param_1,u64 param_2,u32 param_3,u32 param_4);
u32 FUN_00486340(u32 param_1,int param_2,u32 param_3);
u32 FUN_00489020(int param_1);
u32 FUN_00489550(int *param_1,int param_2,long param_3,int param_4,long param_5,long param_6, long param_7,long param_8);
u32 FUN_004899f0(u64 param_1);
u32 FUN_00489a80(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
u32 FUN_0048a1a0(void);
u32 FUN_0048a2c0(int param_1);
u32 FUN_0048a3d0(u32 *param_1);
u32 FUN_0048a3e0(int param_1);
u32 FUN_0048a480(int param_1);
u32 FUN_0048abf0(void);
u32 FUN_0048ac00(void);
u32 FUN_0048da30(u64 param_1);
u32 FUN_0048ef30(int param_1);
f32 FUN_0048ef60(int param_1,int param_2);
u32 FUN_0048ef80(int param_1,int param_2);
int FUN_0048efe0(int param_1);
u32 FUN_00491a80(u64 param_1);
u32 FUN_00491ea0(u64 param_1);
u32 FUN_00492d50(u64 param_1);
u32 FUN_00493b60(u64 param_1);
u32 FUN_00494760(u64 param_1);
u32 FUN_00494cc0(u64 param_1);
u32 FUN_00495320(int *param_1,int param_2);
u32 FUN_00495c20(u64 param_1);
u32 FUN_00495c80(int *param_1);
u32 FUN_00497600(int param_1,u32 param_2,int *param_3,int param_4);
u32 FUN_004982b0(int *param_1,long param_2);
u32 FUN_00498e40(long param_1,long param_2);
u32 FUN_00499c20(code *param_1,u64 param_2);
u32 FUN_0049a170(u32 param_1);
u32 FUN_0049a290(int param_1);
u32 FUN_0049aeb0(u64 param_1);
u32 FUN_0049af20(int *param_1);
u32 FUN_0049c230(int param_1);
u32 FUN_0049c790(void);
u32 FUN_0049c7a0(u64 param_1,u32 *param_2);
u32 FUN_0049c8c0(void);
u32 FUN_0049cc70(int param_1);
u32 FUN_0049e6c0(int param_1);
u32 FUN_0049e780(int param_1);
u32 FUN_0049f5d0(int param_1,u32 *param_2);
u32 FUN_004a09d0(u64 param_1,u32 *param_2);
u32 FUN_004a1430(int param_1);
u32 FUN_004a2bb0(int param_1);
u32 FUN_004a4060(int param_1,int *param_2);
u32 FUN_004a42f0(int param_1);
u32 FUN_004a4f90(int param_1);
u32 FUN_004a5080(int param_1);
u32 FUN_004a5210(void);
u32 FUN_004a52a0(void);
u32 FUN_004a5330(void);
u32 FUN_004a5400(void);
u32 FUN_004a5540(u64 param_1);
u32 FUN_004a9330(void);
u32 FUN_004a9550(u32 param_1);
u32 FUN_004a96b0(int param_1);
u32 FUN_004a9bf0(void);
u32 FUN_004a9d80(float *param_1,float *param_2,float *param_3);
u32 FUN_004a9f20(float param_1,float param_2,float param_3,float param_4);
u32 FUN_004aa410(int param_1);
u32 FUN_004aa540(void);
u32 FUN_004aa6c0(void);
u32 FUN_004aada0(u32 param_1,u32 param_2);
u32 FUN_004aae00(u32 param_1,u32 param_2);
u32 FUN_004ab0c0(void);
u32 FUN_004ac870(void);
u32 FUN_004adb80(void);
u32 FUN_004ae010(int param_1);
u32 FUN_004ae8f0(int param_1);
u32 FUN_004ae900(int param_1);
u32 FUN_004af130(u64 param_1);
u32 FUN_004af940(int param_1);
u64 FUN_00430060(int param_1);
u64 FUN_00430180(u64 param_1);
u64 FUN_00430bb0(u64 param_1);
u64 FUN_00431110(u64 param_1,u64 param_2,char param_3,u8 param_4);
u64 FUN_004312b0(u64 param_1);
u64 FUN_00431670(u64 param_1,char param_2,u32 param_3);
u64 FUN_00439f60(u64 param_1,char param_2);
u64 FUN_0043a0b0(u64 param_1,char param_2);
u64 FUN_0043c690(u32 param_1);
u64 FUN_00447e70(u64 param_1,u8 param_2,u8 param_3);
u64 FUN_0044aaf0(u64 param_1);
u64 FUN_0044ad20(u64 param_1,char param_2);
u64 FUN_0044e560(u64 param_1);
u64 FUN_004542c0(char param_1);
u64 FUN_00454620(char param_1);
u64 FUN_00455e00(u64 param_1);
u64 FUN_004560d0(u32 param_1,u32 param_2,u32 param_3,u64 param_4, u32 param_5,u32 param_6);
u64 FUN_004579b0(u64 param_1);
u64 FUN_00457a40(u64 param_1);
u64 FUN_00458630(u64 param_1,char param_2,u8 param_3);
u64 FUN_00459f60(u64 param_1,u16 param_2,char param_3);
u64 FUN_0045ee00(u64 param_1,u64 param_2);
u64 FUN_0045f4e0(u64 param_1,int param_2);
u64 FUN_0045f580(u64 param_1,u64 param_2,int param_3,int param_4);
u64 FUN_0045f600(u64 param_1,u64 param_2,char *param_3,int param_4);
u64 FUN_00464020(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
u64 FUN_00464120(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
u64 FUN_004643b0(u64 param_1,int param_2,u32 param_3);
u64 FUN_004654a0(u64 param_1,u64 param_2);
u64 FUN_00465930(u64 param_1,u64 param_2);
u64 FUN_00465a00(u64 param_1);
u64 FUN_00465ae0(u64 param_1);
u64 FUN_00465bf0(u64 param_1,int param_2);
u64 FUN_00465cf0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00465eb0(u64 param_1,u64 param_2,u32 param_3);
u64 FUN_00466260(u32 param_1,u32 *param_2,u32 *param_3,u32 param_4,u64 param_5);
u64 FUN_004663d0(u64 param_1);
u64 FUN_00466480(u32 param_1,int param_2,u32 param_3,u64 param_4);
u64 FUN_00466640(u64 param_1);
u64 FUN_00466ef0(u32 *param_1);
u64 FUN_00467590(u64 param_1);
u64 FUN_00467600(u64 param_1);
u64 FUN_004676c0(u64 param_1);
u64 FUN_004677f0(u64 param_1);
u64 FUN_00467860(u64 param_1,u64 param_2);
u64 FUN_00467b40(u64 param_1,int *param_2);
u64 FUN_00467fd0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00468560(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00468690(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_004687e0(long param_1,int *param_2);
u64 FUN_00468dc0(u64 param_1);
u64 FUN_00468e30(u64 param_1);
u64 FUN_00468ea0(u64 param_1,int param_2);
u64 FUN_00469060(u64 param_1,long param_2);
u64 FUN_00469280(u64 param_1,u32 param_2);
u64 FUN_004692e0(float param_1,u64 param_2);
u64 FUN_00469400(u64 param_1,int param_2);
u64 FUN_004694b0(u64 param_1,u32 param_2);
u64 FUN_00469510(u64 param_1,u32 param_2);
u64 FUN_00469590(u32 param_1,u64 param_2);
u64 FUN_00469770(u64 param_1,int param_2);
u64 FUN_00469840(u64 param_1,u32 param_2,u32 param_3);
u64 FUN_00469940(u64 param_1,u32 *param_2,u32 *param_3);
u64 FUN_004699b0(u64 param_1,u32 param_2,u32 param_3);
u64 FUN_00469a10(u64 param_1,long param_2,long param_3);
u64 FUN_00469d00(u64 param_1);
u64 FUN_00469d60(u64 param_1);
u64 FUN_00469e30(u64 param_1,int param_2);
u64 FUN_00469fe0(u64 param_1);
u64 FUN_0046a040(u64 param_1,int param_2);
u64 FUN_0046a0f0(u64 param_1,u64 param_2,int param_3);
u64 FUN_0046a230(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_0046a470(u64 param_1,int param_2);
u64 FUN_0046a600(u64 param_1);
u64 FUN_0046a660(u64 param_1);
u64 FUN_0046a830(u64 param_1);
u64 FUN_0046a970(u64 param_1,int param_2);
u64 FUN_0046aa80(u64 param_1,u32 *param_2);
u64 FUN_0046ac30(u64 param_1);
u64 FUN_0046ad80(u32 *param_1);
u64 FUN_0046afa0(u32 *param_1);
u64 FUN_0046b8e0(int param_1);
u64 FUN_0046c330(u64 param_1,u32 param_2);
u64 FUN_0046c5b0(int param_1);
u64 FUN_0046cd90(int param_1);
u64 FUN_0046d6f0(int param_1);
u64 FUN_0046e170(int param_1);
u64 FUN_0046eb90(int param_1,u32 *param_2);
u64 FUN_0046f400(u32 *param_1,u32 *param_2);
u64 FUN_0046fdd0(int param_1);
u64 FUN_00470200(float *param_1,float *param_2);
u64 FUN_004709e0(int param_1);
u64 FUN_00470e10(u32 *param_1,u32 *param_2);
u64 FUN_00471470(int param_1);
u64 FUN_004718a0(int param_1,u32 *param_2);
u64 FUN_00472270(int param_1);
u64 FUN_00472970(int param_1);
u64 FUN_004733c0(int param_1,int param_2);
u64 FUN_004734d0(u64 param_1);
u64 FUN_00474160(u64 param_1);
u64 FUN_004747f0(u64 param_1);
u64 FUN_00474820(int param_1,long param_2,u32 param_3);
u64 FUN_004748c0(int param_1,long param_2);
u64 FUN_004749a0(int param_1,long param_2);
u64 FUN_00474bb0(u64 param_1);
u64 FUN_00474c60(u64 param_1);
u64 FUN_00478520(int param_1);
u64 FUN_00478a70(void);
u64 FUN_00479900(int param_1);
u64 FUN_00479e50(void);
u64 FUN_0047a710(u64 param_1,int *param_2);
u64 FUN_0047b280(u64 param_1,float *param_2,u32 param_3,u8 *param_4);
u64 FUN_0047b750(u64 param_1,float *param_2,u32 param_3,float *param_4);
u64 FUN_0047be10(int param_1,int param_2,u64 param_3);
u64 FUN_00488cd0(u64 param_1);
u64 FUN_00488d40(u64 param_1);
u64 FUN_00489080(u64 param_1,int *param_2);
u64 FUN_00489160(u64 param_1,long param_2);
u64 FUN_00489730(u64 param_1);
u64 FUN_00489840(u64 param_1);
u64 FUN_004898e0(u64 param_1);
u64 FUN_00489960(u64 param_1);
u64 FUN_00489b70(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00489cd0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00489f20(u64 param_1,u64 param_2,int param_3,u64 param_4,u64 param_5);
u64 FUN_0048a2a0(u64 param_1,u32 param_2);
u64 FUN_0048a2e0(u64 param_1,int param_2);
u64 FUN_0048a370(u64 param_1);
u64 FUN_0048a4b0(u64 param_1);
u64 FUN_0048a790(u64 param_1);
u64 FUN_0048a800(u64 param_1,int param_2);
u64 FUN_0048ac10(u64 param_1,long param_2);
u64 FUN_0048b910(u64 param_1,float *param_2);
u64 FUN_0048cf00(u64 param_1);
u64 FUN_0048cfa0(u64 param_1);
u64 FUN_0048d0e0(u64 param_1);
u64 FUN_0048d270(int param_1,int param_2,u64 param_3);
u64 FUN_0048d370(u64 param_1,int param_2,u32 *param_3);
u64 FUN_0048d480(float param_1,int param_2,long param_3,u64 param_4,long param_5);
u64 FUN_0048d960(u64 param_1);
u64 FUN_0048e020(int *param_1,u64 param_2);
u64 FUN_0048e2d0(int *param_1,u64 param_2);
u64 FUN_0048e750(long param_1,u64 param_2);
u64 FUN_0048eab0(u64 param_1,int param_2);
u64 FUN_0048eb50(u64 param_1,int param_2,int param_3);
u64 FUN_0048ec20(u64 param_1,u64 param_2,int param_3,int param_4);
u64 FUN_0048ecf0(u64 param_1,u64 param_2,int param_3,int param_4);
u64 FUN_0048f340(u64 param_1,int param_2);
u64 FUN_0048f3c0(u64 param_1,u64 param_2,int param_3);
u64 FUN_0048f460(u64 param_1,int param_2);
u64 FUN_0048f4e0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00490770(u64 param_1,u64 param_2,int param_3);
u64 FUN_00490810(u64 param_1);
u64 FUN_00490860(u64 param_1);
u64 FUN_004908d0(u64 param_1,int param_2);
u64 FUN_00490980(u64 param_1,u64 param_2);
u64 FUN_00490d00(u64 param_1);
u32 FUN_00490d40(int param_1);
u64 FUN_00490d90(u64 param_1);
u64 FUN_00491410(u64 param_1);
u64 FUN_004914d0(u64 param_1,int param_2);
u64 FUN_00491630(u64 param_1);
u64 FUN_004916d0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_00491760(u64 param_1,code *param_2,u64 param_3);
u64 FUN_004917f0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_004919b0(u64 param_1,int param_2,u32 param_3);
u64 FUN_00491ff0(u64 param_1,int param_2);
u64 FUN_00492020(u64 param_1,int param_2);
u64 FUN_00492060(u64 param_1,int param_2);
u64 FUN_00492d10(u64 param_1);
u64 FUN_00492e20(u64 param_1,float *param_2);
u64 FUN_00493210(u64 param_1,u16 *param_2,u16 param_3,u16 param_4, u16 param_5);
u64 FUN_00493230(u64 param_1,int param_2,long param_3);
u64 FUN_004932c0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_00493370(u64 param_1,u16 param_2);
u64 FUN_004933d0(u64 param_1);
u32 FUN_00493b40(u32 param_1);
u64 FUN_004944b0(u64 param_1,u32 *param_2);
u64 FUN_004948b0(u64 param_1);
u64 FUN_00494930(u64 param_1,int param_2);
u64 FUN_004949c0(u64 param_1,int param_2);
u64 FUN_00494a40(u64 param_1,u64 param_2,int param_3);
u64 FUN_00494ae0(u64 param_1,int param_2);
u64 FUN_00494b70(u64 param_1);
u64 FUN_00494d50(u64 param_1,long param_2);
u64 FUN_00495260(u64 param_1);
u32 FUN_00495300(u32 param_1);
u64 FUN_00495a30(u64 param_1,int param_2);
u64 FUN_00495cf0(u64 param_1,u32 param_2,u16 param_3,u16 param_4, u16 param_5,u16 param_6,u16 param_7,u16 param_8, u16 param_9);
u64 FUN_00495f10(u64 param_1,code *param_2,u64 param_3);
u64 FUN_00495fb0(u32 *param_1,char *param_2,u64 param_3,u64 param_4);
#pragma alias FUN_00495fb0_u32 FUN_00495fb0
extern u64 FUN_00495fb0_u32(u32 *param_1,char *param_2,u32 param_3,u32 param_4);
u64 FUN_004967a0(u64 param_1);
u64 FUN_00496be0(u32 param_1,u32 *param_2,int param_3,u32 *param_4);
u64 FUN_00498720(int param_1,u64 param_2,u32 param_3);
#pragma alias FUN_00498720_wide FUN_00498720
extern u64 FUN_00498720_wide(u64 param_1,u64 param_2,u32 param_3);
u64 FUN_00499320(u64 param_1);
u64 FUN_00499a80(u64 param_1);
u64 FUN_00499af0(u64 param_1,int param_2);
u64 FUN_00499b90(u64 param_1);
u64 FUN_00499ca0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_00499d30(u64 param_1);
u64 FUN_00499fd0(u64 param_1);
u64 FUN_0049a250(u64 param_1);
u32 FUN_0049a3d0(u32 param_1,code *param_2);
u64 FUN_0049a7c0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_0049a870(u64 param_1,code *param_2,u64 param_3);
u64 FUN_0049aaf0(u64 param_1,int param_2);
u64 FUN_0049abf0(u64 param_1);
u64 FUN_0049ade0(u64 param_1,int param_2);
u64 FUN_0049ae30(u64 param_1);
u64 FUN_0049b180(u64 param_1);
u64 FUN_0049b2e0(u64 param_1);
u64 FUN_0049b3f0(u64 param_1,int param_2);
u64 FUN_0049b440(u64 param_1);
u64 FUN_0049b760(u64 param_1,int param_2);
u64 FUN_0049b7a0(u64 param_1);
u64 FUN_0049b850(u64 param_1,int param_2);
u64 FUN_0049bbc0(u64 param_1,u64 param_2);
u64 FUN_0049bbf0(u64 param_1,u64 param_2);
u64 FUN_0049bc20(u64 param_1,u64 param_2);
u64 FUN_0049bdc0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_0049c160(u64 param_1,int param_2);
#pragma alias FUN_0049c160_wide FUN_0049c160
extern u64 FUN_0049c160_wide(u64 param_1,u64 param_2);
u64 FUN_0049c1b0(u64 param_1,int param_2);
u64 FUN_0049c1e0(u64 param_1,int param_2);
#pragma alias FUN_0049c1e0_wide FUN_0049c1e0
extern u64 FUN_0049c1e0_wide(u64 param_1,u64 param_2);
u64 FUN_0049c240(u64 param_1,u64 param_2);
#pragma alias FUN_0049c240_typed FUN_0049c240
extern u64 FUN_0049c240_typed(int param_1,u64 param_2);
u64 FUN_0049c330(u64 param_1,code *param_2,u64 param_3);
#pragma alias FUN_0049c330_typed FUN_0049c330
extern u64 FUN_0049c330_typed(u32 param_1,u32 param_2,u64 param_3);
u64 FUN_0049c3d0(u64 param_1,int param_2);
#pragma alias FUN_0049c3d0_wide FUN_0049c3d0
extern u64 FUN_0049c3d0_wide(u64 param_1,u64 param_2);
u64 FUN_0049c480(u64 param_1,int param_2);
u64 FUN_0049dc70(int param_1);
u64 FUN_0049e5a0(u64 param_1,int param_2);
u64 FUN_0049e830(u64 param_1,u64 param_2);
u64 FUN_0049e9f0(u64 param_1,u64 param_2);
u64 FUN_0049ee70(u64 param_1,u64 param_2);
u64 FUN_0049f040(u64 param_1,u64 param_2);
u64 FUN_0049faa0(u64 param_1);
u64 FUN_004a0430(u64 param_1,int param_2);
u64 FUN_004a0e00(int param_1);
u64 FUN_004a30d0(int param_1);
u64 FUN_004a3f20(u64 param_1);
u64 FUN_004a4d60(u64 param_1,int param_2);
u64 FUN_004a4da0(u64 param_1);
u64 FUN_004a4e40(u64 param_1);
u64 FUN_004a4ef0(u64 param_1);
u64 FUN_004a55b0(u64 param_1,float *param_2,float *param_3,float *param_4,float *param_5, float *param_6,float *param_7);
u64 FUN_004a5dd0(u64 param_1,u8 *param_2,u8 *param_3,u8 *param_4,u64 param_5);
u64 FUN_004a6200(u64 param_1,float *param_2,float *param_3,float *param_4,float *param_5);
u64 FUN_004a62e0(u64 param_1,long param_2);
u64 FUN_004a6360(u64 param_1,int param_2,u64 param_3);
u64 FUN_004a6530(u64 param_1,u64 param_2);
u64 FUN_004a6600(u64 param_1,u64 param_2);
u64 FUN_004a7620(u64 param_1);
u64 FUN_004ab1b0(u64 param_1);
u64 FUN_004ab200(u32 param_1,u32 param_2,u64 param_3);
u64 FUN_004ab2c0(float param_1,float param_2,u64 param_3);
u64 FUN_004ab410(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6, u64 param_7);
u64 FUN_004ab6a0(u64 param_1);
u64 FUN_004abd50(u64 param_1,u32 *param_2);
u64 FUN_004ac020(int *param_1,u64 param_2);
u64 FUN_004ac920(u64 param_1,int param_2,u64 param_3);
u64 FUN_004acb10(u64 param_1,u64 param_2);
u64 FUN_004ad480(u64 param_1,char *param_2);
u64 FUN_004ad5b0(u64 param_1,long param_2,u64 param_3);
u64 FUN_004ad6a0(int param_1);
u64 FUN_004ad700(u64 param_1,u64 param_2);
u64 FUN_004ad750(u64 param_1);
u64 FUN_004ad940(u64 param_1,u64 param_2);
u64 FUN_004adbd0(int *param_1);
u64 FUN_004adcc0(u64 param_1,u32 param_2);
u64 FUN_004addb0(u64 param_1,u64 param_2);
u64 FUN_004ade90(u64 param_1);
u64 FUN_004adf30(u64 param_1);
u64 FUN_004adfd0(u64 param_1,int param_2);
u64 FUN_004ae020(u64 param_1,u32 *param_2);
u64 FUN_004ae070(u32 param_1,u32 param_2,u64 param_3);
u64 FUN_004ae0c0(u32 param_1,u32 param_2,u64 param_3);
u32 FUN_004ae110(int param_1,int param_2);
u64 FUN_004ae150(u64 param_1,u64 param_2);
u32 FUN_004ae1d0(u32 param_1,u32 param_2);
u64 FUN_004ae1f0(int param_1,u32 *param_2);
u64 FUN_004ae270(u64 param_1,u64 param_2);
u64 FUN_004ae2f0(u64 param_1);
u64 FUN_004ae3b0(u64 param_1,u64 param_2);
u64 FUN_004ae690(u64 param_1);
u64 FUN_004ae790(u64 param_1);
u64 FUN_004ae960(u64 param_1,float *param_2,float *param_3);
u64 FUN_004aeb60(u64 param_1,code *param_2,u64 param_3);
u64 FUN_004aebf0(u64 param_1,u64 param_2,long param_3);
u32 FUN_004aef50(u32 param_1);
u64 FUN_004aef60(u64 param_1);
u64 FUN_004af340(u32 *param_1);
u64 FUN_004af760(u64 param_1);
u64 FUN_004af9d0(u64 param_1,float *param_2,float *param_3);
u64 FUN_004affe0(u64 param_1,u64 param_2,long param_3);
u8 * FUN_00493710(int param_1,int param_2,u32 param_3);
u8 * FUN_004aae60(void);
u8 ** FUN_0049ff00(void);
u8 ** FUN_004a3f10(void);
u8 FUN_00435260(char param_1);
u8 FUN_004353f0(int param_1);
u8 FUN_00435810(void);
u8 FUN_004359f0(u64 param_1,u8 param_2,u8 param_3,u32 *param_4, u8 param_5,u8 param_6);
u8 FUN_0043c730(char param_1);
u8 FUN_0043c7f0(char param_1);
u8 FUN_00449c90(u64 param_1,char param_2);
u8 FUN_0044a420(int param_1,long param_2,u64 param_3);
u8 FUN_0044f060(float param_1,int param_2,float *param_3);
u8 FUN_0044f1c0(float param_1,float *param_2,float *param_3);
u8 FUN_0044fab0(int param_1);
u8 FUN_00453480(void);
u8 FUN_00454400(u32 *param_1,char param_2);
u8 FUN_00454520(float *param_1,char param_2);
u8 FUN_00454a70(char param_1,float *param_2);
u8 FUN_00454d00(float *param_1);
u8 FUN_00457390(char param_1);
u8 FUN_004573d0(char param_1);
u8 FUN_0045a3b0(void);
u8 FUN_0045af90(long param_1);
u8 FUN_0045b480(long param_1);
u8 FUN_0045b4b0(long param_1);
u8 FUN_0045e010(int param_1);
u8 FUN_0045e0c0(int param_1);
u8 FUN_0045e170(int param_1);
u8 FUN_0045ec00(void);
u8 FUN_0045ec20(void);
u8 FUN_0045f7d0(void);
u8 FUN_004661b0(void);
u8 FUN_00468c50(void);
u8 FUN_0046a530(void);
u8 FUN_00473590(void);
u8 FUN_00477050(int param_1);
u8 FUN_00479030(int param_1);
u8 FUN_0047a3d0(int param_1);
u8 FUN_00488fe0(void);
u8 FUN_0048ad20(void);
u8 FUN_0048dcf0(void);
u8 FUN_0048f030(void);
u8 FUN_004915c0(void);
u8 FUN_0049a980(void);
u8 FUN_0049be50(void);
u8 FUN_0049c6c0(void);
u8 FUN_004a5100(void);
u8 FUN_004a9bd0(int param_1);
u8 FUN_004aa390(float param_1);
u8 FUN_004aa3d0(float param_1);
u8 FUN_004aaa60(void);
u8 FUN_004aab40(long param_1);
u8 FUN_004aac70(u32 *param_1);
u8 FUN_004ac390(long param_1);
u8 FUN_004accc0(float *param_1,int *param_2);
u8 FUN_004ae1e0(int param_1);
u8 FUN_004ae4e0(int param_1);
u8 FUN_004ae5a0(long param_1);
void FUN_00430150(int param_1);
void FUN_00430220(int param_1,u64 param_2);
void FUN_00430270(u32 *param_1,int param_2);
void FUN_004302a0(int param_1);
void FUN_004302b0(void);
void FUN_00430630(int param_1);
void FUN_00430780(u64 param_1,int param_2,int param_3,int param_4);
void FUN_00430a40(char param_1);
void FUN_004310e0(int param_1);
void FUN_004311f0(float *param_1,u32 param_2,u32 param_3);
void FUN_00431630(int param_1);
void FUN_004332f0(int param_1);
void FUN_004333d0(int param_1);
void FUN_004334d0(int param_1);
void FUN_004343d0(int param_1);
void FUN_004344f0(float param_1,float *param_2,int param_3,float *param_4,float *param_5);
void FUN_00434c90(char param_1);
void FUN_00434d30(void);
void FUN_00434e60(void);
void FUN_00434f60(u8 param_1);
void FUN_00434f70(void);
void FUN_00435060(u8 param_1);
void FUN_004350e0(char param_1,char param_2);
void FUN_00435370(u8 param_1);
void FUN_00435c00(u64 param_1);
void FUN_00437e00(void);
void FUN_00437e80(u32 *param_1,char param_2);
void FUN_00438010(u64 param_1);
void FUN_00439400(char param_1);
void FUN_00439520(u64 param_1);
void FUN_0043a1a0(char param_1,u8 param_2);
void FUN_0043a2f0(int param_1);
void FUN_0043a960(int param_1);
void FUN_0043bf50(u64 param_1);
void FUN_0043c660(int param_1);
void FUN_0043c7a0(char param_1,u8 param_2);
void FUN_00447ad0(int param_1);
void FUN_00447f90(float *param_1,int param_2,char param_3);
void FUN_00448060(u64 param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6);
void FUN_00448cf0(u64 param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6,int param_7);
void FUN_00449d10(int param_1);
void FUN_00449d60(u64 param_1);
void FUN_00449ed0(void);
void FUN_00449fa0(void);
void FUN_0044a240(u32 param_1,u32 param_2,float param_3,u32 param_4,int param_5 ,u8 param_6);
void FUN_0044a330(u32 param_1,u32 param_2,float param_3,u32 param_4,int param_5 ,u8 param_6);
void FUN_0044a630(int param_1);
void FUN_0044a790(u32 *param_1);
void FUN_0044a990(int param_1,u32 *param_2);
void FUN_0044acf0(int param_1);
void FUN_0044af60(u64 param_1);
void FUN_0044b7d0(int param_1);
void FUN_0044beb0(u64 param_1);
void FUN_0044d600(int param_1);
void FUN_0044dfc0(u64 param_1);
void FUN_0044e530(int param_1,u8 param_2);
void FUN_0044f270(float *param_1,float *param_2);
void FUN_004501b0(char param_1);
void FUN_00450b30(char param_1);
void FUN_00451d70(int param_1);
void FUN_00452010(float *param_1);
void FUN_00452f70(u32 *param_1,int param_2);
void FUN_004532d0(char param_1);
void FUN_004533e0(u8 param_1);
void FUN_00453470(u16 param_1);
void FUN_00453490(int param_1);
void FUN_00453d90(char param_1);
void FUN_00454110(int param_1);
void FUN_00454290(int param_1);
void FUN_004543c0(char param_1,u8 param_2);
void FUN_00454f50(char param_1,char param_2);
void FUN_00455b50(void);
void FUN_00455cf0(void);
void FUN_00456050(int param_1);
void FUN_004561d0(u32 param_1,u32 param_2,int param_3);
void FUN_004561f0(float param_1,int param_2);
void FUN_004563b0(f32 param_1, int param_2);
void FUN_004563c0(int param_1,u8 param_2);
void FUN_004563d0(int param_1,u64 param_2);
void FUN_00456400(int param_1,u8 param_2);
void FUN_00456410(char param_1);
void FUN_00456450(char param_1);
void FUN_00456490(char param_1);
void FUN_004564e0(char param_1);
void FUN_00456530(char param_1);
void FUN_00456580(char param_1);
void FUN_004565d0(char param_1);
void FUN_00456620(char param_1);
void FUN_00456670(u64 param_1,u64 param_2);
void FUN_00456a90(u64 param_1,u64 param_2,u64 param_3);
void FUN_00456ea0(u64 param_1,u64 param_2,u64 param_3);
void FUN_00457340(char param_1,u8 param_2,char param_3);
void FUN_00457980(int param_1);
void FUN_00458600(int param_1);
void FUN_00458850(int param_1);
void FUN_00458870(int param_1);
void FUN_00458890(void);
void FUN_00458920(int param_1);
void FUN_00458930(void);
void FUN_004589d0(int param_1,u8 param_2);
void FUN_00458b00(void);
void FUN_00458b60(void);
void FUN_00458bb0(void);
void FUN_00459d60(void);
void FUN_00459f30(int param_1);
void FUN_0045a220(int param_1);
void FUN_0045a3e0(void);
void FUN_0045a430(char param_1);
void FUN_0045a490(void);
void FUN_0045ace0(void);
void FUN_0045af70(u8 param_1);
void FUN_0045b620(float param_1,float param_2,float param_3,float param_4,u64 param_5, char param_6,int param_7);
void FUN_0045b830(int param_1,long param_2);
void FUN_0045b8f0(int param_1);
void FUN_0045bcb0(u64 param_1,u64 param_2);
void FUN_0045bd90(u64 param_1);
void FUN_0045c530(int param_1);
void FUN_0045c8c0(int param_1,int param_2);
void FUN_0045cdd0(u64 param_1,long param_2);
void FUN_0045ce90(u64 param_1);
void FUN_0045d990(u64 param_1,long param_2);
void FUN_0045e7b0(int param_1);
void FUN_0045e7e0(void);
void FUN_0045ea80(int param_1);
void FUN_0045edc0(void);
void FUN_0045f930(int param_1,float *param_2,code *param_3,u32 param_4);
void FUN_004606b0(int param_1,u64 param_2,code *param_3,u32 param_4);
void FUN_00460ec0(int param_1,u64 param_2,u32 param_3,code *param_4,u32 param_5);
void FUN_00461900(int param_1,float *param_2,u64 param_3,code *param_4,u32 param_5);
void FUN_00461d00(int param_1,u64 param_2,u32 param_3,code *param_4,u32 param_5);
void FUN_00461ea0(int param_1,float *param_2,u32 param_3,code *param_4,u32 param_5);
void FUN_00462bb0(int param_1,u64 param_2,u32 param_3,code *param_4,u32 param_5);
void FUN_00463490(int param_1,int param_2,float *param_3,u32 param_4,code *param_5, u32 param_6);
void FUN_00463b20(int param_1,int param_2,int param_3,u32 param_4,code *param_5, u32 param_6);
void FUN_00463f20(int param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00464850(float param_1,int param_2,int param_3,int param_4);
void FUN_00464e80(float param_1,int param_2,int param_3,int param_4);
void FUN_00465670(int param_1,int param_2);
void FUN_00468530(u64 param_1,u64 param_2,int param_3);
void FUN_00468660(u64 param_1,u64 param_2,int param_3);
void FUN_00468720(char *param_1,long param_2,int param_3);
void FUN_00469aa0(int param_1);
void FUN_00469b50(int param_1);
void FUN_00469bc0(int param_1);
void FUN_0046a8d0(int *param_1,int *param_2);
void FUN_0046a9e0(int *param_1);
void FUN_0046b1b0(u32 *param_1,int param_2,u32 *param_3);
void FUN_0046ea80(u64 param_1);
void FUN_00472130(u64 param_1);
void FUN_00472170(u64 param_1);
void FUN_004721b0(u64 param_1);
void FUN_004721f0(u64 param_1);
void FUN_00472230(u64 param_1);
void FUN_00473340(u64 param_1);
void FUN_00473380(u64 param_1);
void FUN_00474210(u64 param_1,u64 param_2,u64 param_3);
void FUN_00474d30(int param_1,int param_2);
void FUN_00474f20(int param_1,u32 param_2);
void FUN_00475c20(int param_1);
void FUN_00475cb0(int param_1);
void FUN_00476140(u32 *param_1,long param_2,u32 param_3);
void FUN_00476490(u64 *param_1,long param_2,u64 *param_3);
void FUN_00476720(int param_1,long param_2,u64 *param_3);
void FUN_00476980(int param_1,long param_2,u64 *param_3);
void FUN_00476c20(int param_1,int param_2,long param_3);
void FUN_00477150(int *param_1,int param_2,u64 param_3,u64 param_4,u32 param_5);
void FUN_00477470(int *param_1,u64 param_2,u64 param_3,u64 param_4, u32 param_5);
void FUN_00477610(int *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
void FUN_00477810(u32 *param_1,int param_2,int param_3);
void FUN_00477a20(u32 *param_1,int param_2,int param_3);
void FUN_00477c90(int *param_1,int param_2,int param_3);
void FUN_00477eb0(int *param_1,int param_2,int param_3);
void FUN_00478100(int *param_1,int param_2,int param_3);
void FUN_00478280(int *param_1,int param_2,int param_3);
void FUN_00478cc0(int param_1,u32 *param_2);
void FUN_00479170(int *param_1,int param_2,u64 param_3,u64 param_4,u32 param_5);
void FUN_00479590(int *param_1,u64 param_2,u64 param_3,u64 param_4, u32 param_5);
void FUN_0047a050(int param_1,u32 *param_2);
void FUN_0047bf80(int param_1);
void FUN_0047c240(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_0047c8c0(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_004838e0(u32 *param_1,int param_2,int param_3);
void FUN_00485070(u32 *param_1,int param_2,int param_3);
void FUN_00485110(u32 *param_1,int param_2,int param_3);
void FUN_00485440(u32 *param_1,int param_2,int param_3);
void FUN_00485750(int *param_1,int param_2,int param_3);
void FUN_00485e20(int *param_1,int param_2,int param_3);
void FUN_00485ef0(int *param_1,int param_2,int param_3);
void FUN_00485ff0(int *param_1,int param_2,int param_3);
void FUN_004866c0(int param_1);
void FUN_00486c80(int *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_00487030(int *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_00487280(int *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_004876f0(int *param_1,float *param_2,float *param_3,long param_4,int param_5);
void FUN_00487bf0(u32 *param_1,int param_2,int param_3);
void FUN_00488550(int *param_1,int param_2,int param_3,int param_4,u32 param_5);
void FUN_00489350(u64 param_1,long param_2);
void FUN_004893e0(int param_1,int param_2,u32 param_3);
void FUN_00489460(int param_1,u32 *param_2,int *param_3,int param_4,u32 *param_5,u32 param_6);
void FUN_0048a3f0(u64 param_1,long param_2);
void FUN_0048dd70(int *param_1);
void FUN_0048de50(int *param_1,int *param_2);
void FUN_0048e610(int *param_1);
void FUN_0048efa0(int param_1,int param_2,u32 param_3);
void FUN_0048efc0(int param_1,int param_2,f32 param_3);
void FUN_00491100(int param_1);
void FUN_00492c30(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00492c60(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00492c90(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00492cc0(u64 param_1,u64 param_2);
void FUN_00492ce0(u64 param_1,u64 param_2);
void FUN_00492d00(u32 param_1);
void FUN_00493c50(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00493c80(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00494520(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00494550(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00494db0(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00494de0(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00494e10(u64 param_1,u64 param_2);
void FUN_00495480(int *param_1,int param_2);
int FUN_004959c0(u64 param_1);
void FUN_00496580(void);
void FUN_00496ad0(u64 param_1,int *param_2,short param_3,short param_4,int param_5, int param_6);
void FUN_00496f60(int param_1,int param_2,long param_3);
void FUN_00498e30(u64 param_1);
void FUN_00499230(void);
void FUN_00499250(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00499280(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_004992b0(u64 param_1,u64 param_2);
void FUN_004992d0(u64 param_1,u64 param_2);
void FUN_00499720(u64 param_1);
void FUN_00499850(int *param_1);
void FUN_00499e90(u32 param_1,u32 param_2);
void FUN_00499f40(int param_1);
void FUN_0049a920(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_0049a950(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_0049afa0(int param_1,u64 param_2);
void FUN_0049be20(int param_1);
void FUN_0049c680(void);
void FUN_0049c9b0(void);
void FUN_0049ca50(long param_1);
void FUN_0049cab0(float param_1,u8 *param_2);
void FUN_0049cbd0(int param_1,float *param_2);
void FUN_0049cc30(int param_1);
void FUN_0049e4f0(u64 param_1);
void FUN_0049ff10(u32 param_1,u32 param_2,int param_3,long param_4);
void FUN_004a0480(int param_1,int param_2);
void FUN_004a05d0(int param_1,int param_2);
void FUN_004a06c0(int param_1);
void FUN_004a08f0(int param_1,int *param_2,int param_3,u32 param_4);
void FUN_004a0dc0(int param_1);
void FUN_004a24a0(int param_1,int param_2);
void FUN_004a2560(u64 param_1,int *param_2);
void FUN_004a3540(int param_1);
void FUN_004a3f70(int param_1,u32 *param_2);
void FUN_004a53b0(void);
void FUN_004a91f0(void);
void FUN_004a97c0(u64 param_1,u64 param_2);
void FUN_004a9a70(int param_1);
void FUN_004aa550(u64 param_1);
void FUN_004aa5c0(void);
void FUN_004aa620(void);
void FUN_004aad50(void);
void FUN_004ab170(u32 *param_1);
void FUN_004ab910(float *param_1,float *param_2,float *param_3);
void FUN_004aba20(u64 param_1,u64 param_2,int param_3);
void FUN_004ac410(int *param_1);
void FUN_004ac7f0(void);
void FUN_004ac860(u32 param_1,u32 param_2);
void FUN_004adb50(void);
void FUN_004adc70(u64 param_1);
void FUN_004adc90(u64 param_1,u64 param_2);
void FUN_004adca0(void);
void FUN_004ae060(int param_1);
void FUN_004ae940(u64 param_1);

extern u32 DAT_0077dce0;
#pragma alias DAT_0077dce0_abs DAT_0077dce0
extern u8 DAT_0077dce0_abs[];
extern u32 DAT_0077dd00;
#pragma alias DAT_0077dd00_abs DAT_0077dd00
extern u8 DAT_0077dd00_abs[];
extern u32 DAT_0077dd20;
extern u32 DAT_0077dd40;
#pragma alias DAT_0077dd20_abs DAT_0077dd20
extern u8 DAT_0077dd20_abs[];
extern u32 DAT_0077dd60;
extern u32 DAT_0077dd78;
#pragma alias DAT_0077dd40_abs DAT_0077dd40
extern u8 DAT_0077dd40_abs[];
extern u32 DAT_0077dd7c;
extern u32 DAT_0077dd80;
#pragma alias DAT_0077dd60_abs DAT_0077dd60
extern u8 DAT_0077dd60_abs[];
extern u32 DAT_0077dda4;
extern u32 DAT_0077ddb0;
#pragma alias DAT_0077ddb0_abs DAT_0077ddb0
extern u8 DAT_0077ddb0_abs[];
extern u32 DAT_0077ddd0;
extern u32 DAT_0077dec0;
extern u32 DAT_0077dee0;
extern u32 DAT_007bcac2;
extern u32 DAT_007bcac3;
extern u32 DAT_007bcac7;
extern u32 DAT_007bcac8;
extern u32 DAT_007bcac9;
extern u32 DAT_007bcacc;
extern u32 DAT_007bcacf;
extern u32 DAT_007bcae2;
extern u32 DAT_007bcae3;
extern u32 DAT_007bcae7;
extern u32 DAT_007bcae8;
extern u32 DAT_007bcae9;
extern u32 DAT_007bcaec;
extern u32 DAT_007bcaef;
extern u32 DAT_007bcb52;
extern u32 DAT_007bcb53;
extern u32 DAT_007bcb57;
extern u32 DAT_007bcb58;
extern u32 DAT_007bcb59;
extern u32 DAT_007bcb5c;
extern u32 DAT_007bcb5f;
extern u32 DAT_007cdbe0;
extern u32 DAT_007cdbe4;
extern u32 DAT_007cdbe8;
extern u32 DAT_007cdbec;
extern u32 DAT_007cdc08;
extern u32 DAT_007cdc09;
extern u32 DAT_007cdc0a;
extern u32 DAT_007cdc0b;
extern u32 DAT_007cdc64;
extern u32 DAT_007cdc68;
#pragma alias DAT_007cdc64_abs DAT_007cdc64
extern u32 DAT_007cdc64_abs[];
#pragma alias DAT_007cdc68_abs DAT_007cdc68
extern u32 DAT_007cdc68_abs[];
extern u32 DAT_007cdc6c;
extern u32 DAT_007cdcc4;
extern u32 DAT_007cdcc8;
extern u32 DAT_007cdccc;
extern u32 DAT_007cdcd0;
extern u32 DAT_007cdcd4;
extern u32 DAT_007ce720;
extern u32 DAT_007ce724;
extern u32 DAT_007ce728;
extern u32 DAT_007ce72c;
extern u32 DAT_007ce7b8;
extern u32 DAT_007ce7bc;
extern u32 DAT_007ce7c0;
extern u32 DAT_007ce7c4;
extern u32 DAT_007ce7c8;
extern u32 DAT_007ce7cc;
extern u32 DAT_007ce7d0;
extern u32 DAT_007ce7d4;
extern u32 DAT_007ce7d8;
extern u32 DAT_007ce7dc;
extern u32 DAT_007ce7e0;
extern u32 DAT_007ce7e4;
extern u32 DAT_007ce7e8;
extern u32 DAT_007ce7ec;
extern u32 DAT_007ce7f8;
extern u32 DAT_007ce7fc;
extern u32 DAT_007ce830;
extern u32 DAT_007ce834;
extern u32 DAT_007ce838;
extern u32 DAT_007ce83c;
extern u32 DAT_007ce840;
extern u32 DAT_007ce844;
extern u32 DAT_007ce848;
extern u32 DAT_007ce850;
extern u32 DAT_007ce854;
extern u32 DAT_007ce868;
extern u32 DAT_007ce86c;
extern u32 DAT_007ce870;
extern u32 DAT_007ce874;
extern u32 DAT_007ce878;
extern u32 DAT_007ce880;
extern u32* DAT_007ce884;
extern u32 DAT_007ce888;
extern u32 DAT_007ce88c;
extern u32 DAT_007ce890;
extern u32 DAT_007ce8f0;
extern u32* DAT_007ce9f4;
extern u32 DAT_007cea60;
extern u32 DAT_007ceaf4;
extern u32 DAT_007ceb20;
extern u32 DAT_007ceb28;
extern u32 DAT_0095dfc0;
extern u32 DAT_0095dfc4;
extern u32 DAT_0095dfc8;
extern u32 DAT_0095dfcc;
extern u32 DAT_0095dfd0;
extern u32 DAT_0095e860;
extern u32 DAT_0095e864;
extern u32 DAT_0095ea60;
extern u32 DAT_0095ed60;
extern u32 DAT_0095ed64;
#pragma alias DAT_0095ed60_abs DAT_0095ed60
extern u32 DAT_0095ed60_abs[];
#pragma alias DAT_0095ed64_abs DAT_0095ed64
extern u32 DAT_0095ed64_abs[];
extern u32 DAT_0095ed68;
extern u32 DAT_0095ed6c;
extern u32 DAT_0095ed70;
extern u32 DAT_0095ed74;
extern u32 DAT_0095ed78;
extern u32 DAT_0095ed7c;
extern u32 DAT_0095ed80;
extern u32 DAT_0095ed84;
extern u32* DAT_0095ed88;
extern u32 DAT_0095ed8c;
#pragma alias DAT_0095ed8c_abs DAT_0095ed8c
extern u32 DAT_0095ed8c_abs[];
#pragma alias DAT_0096018c_abs DAT_0096018c
extern u32 DAT_0096018c_abs[];
extern u32 DAT_0095edb0;
extern u32 DAT_0095edb4;
extern u32 DAT_0095edb8;
extern u32 DAT_0095edbc;
extern u32 DAT_0095edc0;
extern u32 DAT_0095edc4;
extern u32 DAT_0095edc8;
extern u32 DAT_0095edd0;
extern u32 DAT_0095edd4;
extern u32 DAT_0095edd8;
extern u32 DAT_0095ede0;
extern u32 DAT_0095ede4;
extern u32 DAT_0095ede8;
extern u32 DAT_0095edec;
extern u8 DAT_0095edf0[];
#pragma alias DAT_0095edf0_abs DAT_0095edf0
extern u32 DAT_0095edf0_abs[];
extern u32 DAT_0095ee70;
#pragma alias DAT_0095ee70_abs DAT_0095ee70
extern int DAT_0095ee70_abs[];
extern u32 DAT_0095ee74;
extern u32 DAT_0095ee78;
extern u32 DAT_0095ee7c;
extern u32 DAT_0095ee80;
extern u32 DAT_0095ee90;
extern u32 DAT_0095ee94;
extern u32 DAT_0095ee98;
extern u32 DAT_0095ee9c;
extern u32 DAT_0095eea0;
extern u32 DAT_0095eea4;
extern u32 DAT_0095eea8;
extern u32 DAT_0095eeac;
extern u32 DAT_0095eeb0;
extern u32 DAT_0095eeb4;
extern u32 DAT_0095eeb8;
extern u32 DAT_0095eebc;
extern u32 DAT_0095eec0;
extern u32 DAT_0095eec4;
extern u32 DAT_0095eec8;
extern u32 DAT_0095eecc;
#pragma alias DAT_0095ef50_abs DAT_0095ef50
extern u32 DAT_0095ef50_abs[];
 #pragma alias DAT_0095ef64_abs DAT_0095ef64
extern u32 DAT_0095ef64_abs[];
extern u32 DAT_0095ef10;
extern u32 DAT_0095ef50;
extern u32 DAT_0095ef54;
extern u32 DAT_0095ef58;
extern u32 DAT_0095ef5c;
extern u32 DAT_0095ef60;
extern u32 DAT_0095ef64;
extern u32 DAT_0095ef68;
extern u32 DAT_0095ef70;
extern u32 DAT_0095ef74;
extern u32 DAT_0095ef78;
extern u32 DAT_0095ef7c;
extern u32 DAT_0095ef84;
extern u32 DAT_0095ef88;
extern u32 DAT_0095ef98;
extern u32 DAT_0095efa0;
extern u32 DAT_0095efa4;
extern u32 DAT_0095efc4;
extern u32 DAT_0095efc8;
extern u32 DAT_0095efd0;
extern u32 DAT_0095f040;
#pragma alias DAT_00960074_abs DAT_00960074
extern u32 DAT_00960074_abs[];
extern code DAT_0095f478;
extern u32 DAT_0095f57c;
extern u32 DAT_0095f580;
extern u32 DAT_0095f584;
extern u32 DAT_0095f984;
extern u32 DAT_0095f988;
extern u8 DAT_00960070[];
#pragma alias DAT_00960070_abs DAT_00960070
extern u32 DAT_00960070_abs[];
extern u32 DAT_00960074;
extern u32 DAT_00960078;
extern u32 DAT_0096007a;
extern u32 DAT_0096007c;
extern u32 DAT_00960080;
extern u32 DAT_00960088;
extern u32 DAT_0096008c;
extern code DAT_00960090;
extern code DAT_00960094;
extern u32 DAT_00960098;
extern u32 DAT_0096009c;
extern code DAT_009600a0;
extern u32 DAT_009600a8;
extern u32 DAT_009600ac;
extern u32 DAT_009600b0;
extern u32 DAT_009600b4;
extern u32 DAT_009600b8;
extern u32 DAT_009600bc;
extern u32 DAT_009600c0;
extern u32 DAT_009600c4;
extern u32 DAT_009600c8;
extern u32 DAT_009600cc;
extern code DAT_00960134;
extern code DAT_0096013c;
extern code DAT_00960144;
extern code DAT_00960158;
extern code DAT_00960164;
extern code DAT_00960174;
extern code DAT_00960178;
#pragma alias DAT_00960178_abs DAT_00960178
extern int (*DAT_00960178_abs[])(u64,u64);
extern code DAT_0096017c;
extern code DAT_00960180;
extern code DAT_00960188;
extern code DAT_0096018c;
extern u32 DAT_009658a0;
extern u32 DAT_009658a8;
extern u32 DAT_009658ac;
extern u32 DAT_00965910;
extern u32 DAT_00965920;
extern u32 DAT_00965930;
extern u32 DAT_00965940;
extern u32 PTR_DAT_0077f130;
extern u32 PTR_FUN_0077dda0;
extern u8 *PTR_s_PS2AllMat_csl_0077e1e0[];
extern u8 *PTR_s_PS2All_csl_0077de80[];
extern u32 Status;
extern u32 _DAT_00965910;
extern u32 _DAT_00965920;
extern u32 _DAT_00965930;
extern u32 _DAT_00965940;
extern u32 switchdataD_007bca50[];
extern u32 bGpffffbe04;
extern u32 gp0xffffaf20;
extern u32 gp0xffffaf98;
extern u32 gp0xffffafa0;
extern u32 gp0xffffafa8;
extern u32 gp0xffffafc0;
extern u32 gp0xffffafc8;
extern u32 gp0xffffafd0;
extern u32 iGpffffb0f8;
extern u32 iGpffffba38;
extern u32 iGpffffba3c;
extern u32 iGpffffbb14;
extern u32 iGpffffbb20;
extern u32 iGpffffbb24;
extern u32 iGpffffbb2c;
extern u32 iGpffffbb30;
extern u32 iGpffffbb34;
extern u32 iGpffffbb60;
extern u32 iGpffffbb70;
extern u32 iGpffffbb74;
extern u32 iGpffffbb78;
extern u32 iGpffffbb7c;
extern u32 iGpffffbb80;
extern u32 iGpffffbb84;
extern u32 iGpffffbb88;
extern u32 iGpffffbb8c;
extern u32 iGpffffbb9c;
extern u32 iGpffffbba0;
extern u32 iGpffffbdb4;
extern u32 iGpffffbdbc;
extern u32 iGpffffbdcc;
extern u32 iGpffffbe14;
extern u32 iGpffffbe38;
extern u32 uGpffffaee0;
extern u32 uGpffffaee4;
extern u32 uGpffffaee8;
extern u32 uGpffffaeec;
extern u32 uGpffffaf00;
extern u32 uGpffffaf04;
extern u32 uGpffffaf08;
extern u32 uGpffffaf0c;
extern u32 uGpffffafb0;
extern u32 uGpffffafb4;
extern u32 uGpffffafb8;
extern u32 uGpffffafbc;
extern u32 uGpffffb0d0;
extern u32 uGpffffbb10;
extern u32 uGpffffbb20;
extern u32 uGpffffbb24;
extern u32 uGpffffbb28;
extern u32 uGpffffbb78;
extern u32 uGpffffbb7c;
extern u32 uGpffffbb80;
extern u32 uGpffffbb84;
extern u32 uGpffffbba4;
extern u32 uGpffffbd50;
extern u32 uGpffffbd68;
extern u32 uGpffffbd70;
extern u32 uGpffffbdc4;
extern u32 uGpffffbdc8;
extern u32 uGpffffbe08;
extern u32 uGpffffbe0c;
extern u32 uGpffffbe10;
extern char getCopCondition(int,int);

extern code FUN_00100d80;
extern code FUN_00100ec0;
extern code FUN_001016b0;
extern code FUN_00102100;
extern code FUN_001023a0;
extern code FUN_00108570;
extern code FUN_001085c0;
extern code FUN_00108670;
extern code FUN_00108710;
extern code FUN_00108f70;
extern code FUN_00108fd0;
extern code FUN_00109040;
extern code FUN_0010a4e0;
extern code FUN_0010c1a0;
extern code FUN_0010c3a0;
extern code FUN_00111f30;
extern code FUN_001120c0;
extern code FUN_00112370;
extern code FUN_00112420;
extern code FUN_001124b0;
extern code FUN_001126b0;
extern code FUN_00112740;
extern code FUN_001127d0;
extern code FUN_00113a30;
extern code FUN_001140d0;
extern code FUN_001158b0;
extern code FUN_00115980;
extern code FUN_001159f0;
extern code FUN_00115bc0;
extern code FUN_0016c470;
extern code FUN_0016c4f0;
extern code FUN_0016c570;
extern code FUN_0016c5f0;
extern code FUN_0016c920;
extern code FUN_0016c970;
extern code FUN_0016cf40;
extern code FUN_0016cf90;
extern code FUN_0016f190;
extern code FUN_0016f1f0;
extern code FUN_0016f490;
extern code FUN_00170a40;
extern code FUN_00170ab0;
extern code FUN_00170b20;
extern code FUN_00170b90;
extern code FUN_00173300;
extern code FUN_00173380;
extern code FUN_00177410;
extern code FUN_0017b500;
extern code FUN_0017b5b0;
extern code FUN_0017b660;
extern code FUN_0017b860;
extern code FUN_0017be10;
extern code FUN_001831e0;
extern code FUN_0018bee0;
extern code FUN_0018c0c0;
extern code FUN_0018eb30;
extern code FUN_00194b20;
extern code FUN_00194b80;
extern code FUN_00195020;
extern code FUN_00195290;
extern code FUN_00195460;
extern code FUN_00198590;
extern code FUN_001a0040;
extern code FUN_001a0250;
extern code FUN_001a02c0;
extern code FUN_001a0dc0;
extern code FUN_001a5320;
extern code FUN_001a56b0;
extern code FUN_001a56c0;
extern code FUN_001a56d0;
extern code FUN_001a5700;
extern code FUN_001a57a0;
extern code FUN_001a5aa0;
extern code FUN_001a91b0;
extern code FUN_001a9390;
extern code FUN_001a9760;
extern code FUN_001aaa20;
extern code FUN_001aaac0;
extern code FUN_001acc30;
extern code FUN_001ad870;
extern code FUN_001ad910;
extern code FUN_001ad920;
extern code FUN_001ad940;
extern code FUN_001adc20;
extern code FUN_001adff0;
extern code FUN_001af930;
extern code FUN_001afa20;
extern code FUN_001aff70;
extern code FUN_001b0020;
extern code FUN_001b00c0;
extern code FUN_001b01b0;
extern code FUN_001b01d0;
extern code FUN_001b0220;
extern code FUN_001b0230;
extern code FUN_001b0240;
extern code FUN_001b0250;
extern code FUN_001b0260;
extern code FUN_001b9120;
extern code FUN_001bf220;
extern code FUN_001c6450;
extern code FUN_001c65e0;
extern code FUN_001c6720;
extern code FUN_001c6d70;
extern code FUN_001c6dd0;
extern code FUN_001c7130;
extern code FUN_001c7160;
extern code FUN_001c7270;
extern code FUN_001c7b10;
extern code FUN_001cd670;
extern code FUN_001d0110;
extern code FUN_001d22a0;
extern code FUN_001d3810;
extern code FUN_001d8b00;
extern code FUN_001d8c60;
extern code FUN_001d8d80;
extern code FUN_001d8e60;
extern code FUN_001dde00;
extern code FUN_001ded40;
extern code FUN_001e1360;
extern code FUN_001e13c0;
extern code FUN_00269690;
extern code FUN_002699a0;
extern code FUN_002699d0;
extern code FUN_00269a10;
extern code FUN_00269c80;
extern code FUN_00269ca0;
extern code FUN_002ff340;
extern code FUN_002ff760;
extern code FUN_002ff790;
extern code FUN_00316e00;
extern code FUN_00316f70;
extern code FUN_003174e0;
extern code FUN_003182d0;
extern code FUN_00318540;
extern code FUN_00318b60;
extern code FUN_00318ed0;
extern code FUN_0031c1d0;
extern code FUN_0035bb40;
extern code FUN_0035bc00;
extern code FUN_0035c1a0;
extern code FUN_003952d0;
extern code FUN_003b2cb0;
extern code FUN_003b5d10;
extern code FUN_003b5d50;
extern code FUN_003b6030;
extern code FUN_003b7090;
extern code FUN_003bb010;
extern code FUN_003c72d0;
extern code FUN_003c7430;
extern code FUN_003c74e0;
extern code FUN_003c7560;
extern code FUN_003c75b0;
extern code FUN_003c77a0;
extern code FUN_003c7850;
extern code FUN_003c78d0;
extern code FUN_003c7b90;
extern code FUN_00421fe0;
extern code FUN_004221a0;
extern code FUN_004222d0;
extern code FUN_004229d0;
extern code FUN_00422c10;
extern code FUN_00422c30;
extern code FUN_00422c90;
extern code FUN_00423fe0;
extern code FUN_00427830;
extern code FUN_00427a10;
extern code FUN_00427db0;
extern code FUN_00427de0;
extern code FUN_00427e20;
extern code FUN_00427e50;
extern code FUN_00427e60;
extern code FUN_00427e70;
extern code FUN_00429e80;
extern code FUN_00469DC0;
extern code FUN_00474630;
extern code FUN_00488dd0;
extern code FUN_00488f30;
extern code FUN_004ACE60;
extern code FUN_004ACE70;
extern code FUN_004b0fa0;
extern code FUN_004b1050;
extern code FUN_004b1090;
extern code FUN_004b1100;
extern code FUN_004b11a0;
extern code FUN_004b6680;
extern code FUN_004b6e10;
extern code FUN_004b6eb0;
extern code FUN_004b75d0;
extern code FUN_004bae00;
extern code FUN_004bb5d0;
extern code FUN_004c0240;
extern code FUN_004c0370;
extern code FUN_004c0550;
extern code FUN_004c06c0;
extern code FUN_004c15a0;
extern code FUN_004c1600;
extern code FUN_004c1750;
extern code FUN_004c17f0;
extern code FUN_004c1820;
extern code FUN_004c1850;
extern code FUN_004c18b0;
extern code FUN_004c1910;
extern code FUN_004c19f0;
extern code FUN_004c1c50;
extern code FUN_004c1cd0;
extern code FUN_004c1d10;
extern code FUN_004c1d50;
extern code FUN_004c1e60;
#pragma alias FUN_004c1e60_typed FUN_004c1e60
extern void FUN_004c1e60_typed(u32 param_1);
extern code FUN_004c1e70;
extern code FUN_004c1f70;
extern code FUN_004c2090;
extern code FUN_004c20b0;
extern code FUN_004c2120;
extern code FUN_004c2130;
extern code FUN_004c21b0;
#pragma alias FUN_004c21b0_typed FUN_004c21b0
extern u32 *FUN_004c21b0_typed(u32 param_1);
#pragma alias FUN_00492060_typed FUN_00492060
extern void FUN_00492060_typed(u32 param_1,u32 param_2);
#pragma alias FUN_004ca030_typed FUN_004ca030
extern void FUN_004ca030_typed(u32 param_1);
extern code FUN_004c2d20;
extern code FUN_004c2f30;
extern code FUN_004c31b0;
extern code FUN_004c32a0;
extern code FUN_004c33d0;
extern code FUN_004c35d0;
extern code FUN_004c3880;
extern code FUN_004c38c0;
#pragma alias FUN_004c3c30_typed FUN_004c3c30
extern void FUN_004c3c30_typed(u32 param_1);
extern code FUN_004c3b50;
extern code FUN_004c3c30;
extern code FUN_004c4200;
extern code FUN_004c47e0;
extern code FUN_004c4930;
extern code FUN_004c5250;
extern code FUN_004c53f0;
extern code FUN_004c5620;
extern code FUN_004c5780;
extern code FUN_004c58a0;
extern code FUN_004c5960;
extern code FUN_004c59b0;
extern code FUN_004c5a00;
#pragma alias FUN_004c5a00_typed FUN_004c5a00
extern void FUN_004c5a00_typed(u64 param_1,u64 param_2,u64 param_3);
#pragma alias FUN_004c5a00_u32 FUN_004c5a00
extern void FUN_004c5a00_u32(u32 param_1,u64 param_2,u64 param_3);
extern code FUN_004c5a50;
extern code FUN_004c5c30;
extern code FUN_004c6170;
extern code FUN_004c61b0;
#pragma alias FUN_004c5960_raw FUN_004c5960
extern void FUN_004c5960_raw();
#pragma alias FUN_004c59b0_raw FUN_004c59b0
extern void FUN_004c59b0_raw();
#pragma alias FUN_004c6170_raw FUN_004c6170
extern void FUN_004c6170_raw();
#pragma alias FUN_004c6170_u32 FUN_004c6170
extern u32 FUN_004c6170_u32(u32 param_1,u32 param_2);
#pragma alias FUN_004c61b0_raw FUN_004c61b0
extern void FUN_004c61b0_raw();
extern code FUN_004c64b0;
extern code FUN_004c6560;
extern code FUN_004c65d0;
extern code FUN_004c6970;
extern code FUN_004c69f0;
extern code FUN_004c6ac0;
extern code FUN_004c6be0;
extern code FUN_004c6c20;
extern code FUN_004c6c60;
extern code FUN_004c7a50;
extern code FUN_004c7b60;
extern code FUN_004c7b90;
extern code FUN_004c7d00;
extern code FUN_004c7d30;
extern code FUN_004c7d80;
extern code FUN_004c81a0;
extern code FUN_004c81d0;
extern code FUN_004c8240;
extern code FUN_004c83c0;
extern code FUN_004c9df0;
extern code FUN_004ca000;
extern code FUN_004ca030;
extern code FUN_004ca510;
extern code FUN_004ca520;
extern code FUN_004ca550;
extern code FUN_004cace0;
extern code FUN_004cad30;
extern code FUN_004cae30;
extern code FUN_004caf10;
extern code FUN_004caf80;
extern code FUN_004cb1b0;
extern code FUN_004cb270;
extern code FUN_004cb2f0;
extern code FUN_004cb6e0;
extern code FUN_004cb7f0;
extern code FUN_004cb9f0;
extern code FUN_004cbe00;
extern code FUN_004cbeb0;
extern code FUN_004cbf20;
extern code FUN_004cc0a0;
extern code FUN_004cc1d0;
extern code FUN_004cc5c0;
extern code FUN_004cc6b0;
extern code FUN_004cdc70;
extern code FUN_004cdce0;
extern code FUN_004cdd50;
extern code FUN_004ce0f0;
extern code FUN_004cec10;
extern code FUN_004d0c30;
extern code FUN_004d0d10;
extern code FUN_004d0e40;
extern code FUN_004d0f00;
extern code FUN_004d0fd0;
extern code FUN_004d1110;
extern code FUN_004d1170;
extern code FUN_004d11d0;
extern code FUN_004d11f0;
extern code FUN_004d1260;
extern code FUN_004d13b0;
extern code FUN_004d1840;
extern code FUN_004d18c0;
extern code FUN_004d4df0;
#pragma alias FUN_004d4df0_typed FUN_004d4df0
extern void FUN_004d4df0_typed(void);
extern code FUN_004d51c0;
extern code FUN_004d59d0;
#pragma alias FUN_004d59d0_typed FUN_004d59d0
extern void FUN_004d59d0_typed(int,int);
#pragma alias FUN_004d5fe0_typed FUN_004d5fe0
extern int FUN_004d5fe0_typed(int,int);
extern code FUN_004d5e90;
extern code FUN_004d5fe0;
extern code FUN_004d7f60;
extern code FUN_004ec2b0;
extern code FUN_004f0f30;
extern code FUN_004f1020;
extern code FUN_004f1e20;
extern code FUN_004f1e40;
extern code FUN_004f1ed0;
extern code FUN_004f1f80;
extern code FUN_004f1fd0;
extern code FUN_004f23c0;
extern code FUN_004f2430;
extern code FUN_004f2710;
extern code FUN_004f2e70;
extern code FUN_004f2f70;
extern code FUN_004f3010;
extern code FUN_004f3ec0;
extern code FUN_004f3f70;
extern code FUN_004f3f80;
extern code FUN_004f4640;
extern code FUN_004f4830;
extern code FUN_004f4950;
extern code FUN_00503a58;
extern code FUN_0050d3a0;
extern code FUN_0050d3f0;
extern code FUN_005211b8;
extern code FUN_00521250;
extern code FUN_00521408;
extern code FUN_005225a8;
extern code FUN_005225f8;
extern code FUN_00523e68;
extern code FUN_00524270;
extern code FUN_00524388;
extern code FUN_00524670;
extern code FUN_00524828;
extern code FUN_0052e6d8;
extern code FUN_0052e878;
extern code FUN_0052ea18;
extern code FUN_005316d0;
#pragma alias FUN_005316d0_s32 FUN_005316d0
extern int FUN_005316d0_s32(void);

char FUN_00435440(char param_1);
char FUN_0043bc20(char param_1);
float FUN_0045b4e0(long param_1);
float FUN_004693a0(int param_1);
float FUN_0047cfd0(u32 *param_1,u8 (*param_2) [12],u8 (*param_3) [12], int param_4,int param_5);
float FUN_004a9560(float param_1,int param_2,u8 *param_3);
float FUN_004aa2c0(void);
int * FUN_00496cd0(u32 param_1,u32 *param_2,u64 param_3,u16 *param_4);
int * FUN_004ac120(int *param_1,u64 param_2);
int * FUN_004ac240(int *param_1);
int FUN_0044f120(float *param_1);
int FUN_0044f170(int param_1);
int FUN_00457410(void);
int FUN_0045edd0(u32 *param_1);
int FUN_0045f540(int param_1,int param_2);
int FUN_00465b40(int param_1);
int FUN_00468350(int param_1);
int FUN_0046ad20(int *param_1,int param_2);
int FUN_0046b060(int param_1,u32 *param_2,int param_3);
int FUN_004753d0(int param_1,u32 param_2);
int FUN_00475540(int param_1,u64 param_2,u64 param_3,u32 param_4);
int FUN_00489320(int *param_1);
int FUN_00489ae0(int param_1);
int FUN_0048a7a0(int param_1);
int FUN_0048d200(int param_1);
int FUN_0048e4f0(long param_1);
int FUN_0048e890(int *param_1,long param_2,u64 param_3,int param_4);
int FUN_0048ed20(int param_1,int param_2);
int FUN_0048ede0(int param_1);
int FUN_0048ee30(int param_1,int param_2);
int FUN_004912b0(int param_1);
int FUN_00491cc0(int param_1);
int FUN_00492f80(int param_1,int param_2);
int FUN_00493cb0(u64 param_1);
int FUN_00495340(int *param_1,int param_2);
int FUN_004964f0(int param_1,char *param_2);
int FUN_00499400(int param_1,u64 param_2,int param_3,int param_4);
int FUN_0049c560(int param_1);
int FUN_0049c5c0(int param_1);
int FUN_0049c620(int param_1);
int FUN_0049d4d0(int param_1,int param_2,int *param_3,int *param_4,int *param_5,int *param_6);
int FUN_0049ecd0(int param_1);
int FUN_0049f340(int param_1);
int FUN_004a0ce0(int param_1,int *param_2,int param_3,u32 param_4);
int FUN_004a26d0(int param_1,int *param_2,int param_3,u32 param_4);
int FUN_004a5200(void);
int FUN_004a5290(void);
int FUN_004a5320(void);
int FUN_004a6630(int param_1,float *param_2,int param_3,int *param_4,int *param_5);
int FUN_004ab0e0(u64 param_1);
int FUN_004ace80(int param_1,float *param_2,u64 param_3,u32 *param_4,int *param_5);
long FUN_0045ec40(u16 param_1,u16 param_2,u32 *param_3,u32 param_4);
long FUN_0045efe0(u64 param_1);
long FUN_0045f140(u64 param_1,u16 param_2,u16 param_3,u64 param_4, u32 *param_5);
long FUN_00464280(u32 param_1);
long FUN_00464540(u64 param_1);
long FUN_00467c20(long param_1,u64 param_2,int param_3);
long FUN_0046bab0(long param_1,u64 param_2);
long FUN_0046bd00(long param_1,u64 param_2);
long FUN_0046bfb0(float param_1,long param_2,u8 *param_3,float *param_4,u32 param_5);
long FUN_00474260(u32 param_1,u32 param_2,u64 param_3,u64 param_4);
long FUN_00475d60(u64 param_1,u64 param_2,u64 param_3,u32 param_4, u32 param_5);
long FUN_0047ab70(void);
long FUN_0047b1a0(void);
long FUN_0047bb40(int param_1,int param_2,u32 param_3);
long FUN_0048a9a0(long param_1,u64 param_2);
long FUN_0048af80(u32 param_1);
long FUN_0048dab0(int param_1,long param_2,u64 param_3);
long FUN_00490050(u64 param_1);
long FUN_00490dc0(u64 param_1,int *param_2,int *param_3);
long FUN_00491880(void);
long FUN_00491b40(u64 param_1);
long FUN_00491de0(void);
long FUN_004920a0(u64 param_1);
long FUN_00494580(u64 param_1);
long FUN_004947c0(u8 param_1);
long FUN_00494be0(void);
long FUN_00494e30(u64 param_1);
long FUN_004954c0(u64 param_1,long param_2);
long FUN_00495b10(long param_1);
long FUN_00496230(u64 param_1,char *param_2,u32 param_3);
long FUN_00497130(u64 param_1,long param_2,u64 param_3,u64 param_4,long param_5);
long FUN_00498e70(int param_1);
long FUN_00499140(long param_1,u32 param_2);
long FUN_0049a080(long param_1);
long FUN_0049a400(u32 *param_1);
long FUN_0049c810(void);
long FUN_0049fe40(long param_1,int param_2,long param_3);
long FUN_0049fec0(long param_1,u32 param_2);
long FUN_004a35c0(long param_1,long param_2,u32 param_3);
long FUN_004a38f0(long param_1,long param_2,long param_3,long param_4);
long FUN_004a3a80(long param_1,long param_2,long param_3,long param_4);
long FUN_004a3c10(long param_1,long param_2,long param_3);
long FUN_004a3d70(long param_1,u32 param_2);
long FUN_004a3db0(long param_1,long param_2,long param_3);
long FUN_004a3e30(long param_1,int param_2,long param_3);
long FUN_004a5470(void);
long FUN_004a6ce0(u32 param_1,long param_2,u8 *param_3,u32 *param_4, u64 param_5);
long FUN_004a6eb0(float param_1,long param_2,u8 *param_3,float *param_4,float *param_5);
long FUN_004a7820(long param_1,u64 param_2,u32 param_3,u32 param_4);
long FUN_004a9490(long param_1);
long FUN_004a98a0(u64 param_1);
long FUN_004ac570(void);
long FUN_004ac5f0(long param_1);
long FUN_004ac710(long param_1);
long FUN_004acb90(u64 param_1);
long FUN_004aeea0(u64 param_1);
long FUN_004af210(int *param_1,int *param_2,u32 param_3,u64 param_4);
short * FUN_00496e80(int param_1,short param_2,short param_3);
short FUN_0043b980(char param_1,u64 param_2);
short FUN_0043bda0(char param_1,char param_2);
u16 FUN_00435660(char param_1);
u16 FUN_0043c180(char param_1);
u16 FUN_0043c340(char param_1);
u16 FUN_00453460(void);
u32 * FUN_0048f580(u64 param_1,int *param_2,int param_3,u32 param_4);
u32 * FUN_0048fbd0(u64 param_1,u64 param_2,u64 param_3,u32 param_4);
u32 * FUN_004a7e40(u32 *param_1,u32 param_2,u32 param_3,char *param_4);
u32 * FUN_004a8980(u32 *param_1,u64 param_2,u32 param_3,u64 param_4);
u32 * FUN_004a90f0(void);
u32 * FUN_004a9a80(u64 param_1);
u32 * FUN_004ab8c0(void);
u32 FUN_00431880(int param_1);
u32 FUN_00431aa0(u64 param_1);
u32 FUN_00432050(u64 param_1);
u32 FUN_00432600(u64 param_1);
u32 FUN_00432bb0(u64 param_1);
u32 FUN_00433160(int param_1);
u32 FUN_00433810(char param_1,char param_2);
u32 FUN_004339d0(int param_1);
u32 FUN_00433de0(int param_1);
u32 FUN_00434770(float param_1,float param_2,u64 param_3,float *param_4);
u32 FUN_00434920(float param_1,float param_2,int param_3,float *param_4);
u32 FUN_004352e0(void);
u32 FUN_00437e20(char param_1);
u32 FUN_0043a230(char param_1);
u32 FUN_0043a9d0(u64 param_1,u64 param_2,char param_3);
u32 FUN_0043c500(int param_1);
u32 FUN_0043c910(char param_1);
u32 FUN_0043ca30(u64 param_1);
u32 FUN_00449fe0(float param_1,float param_2,float param_3,float param_4,int param_5,short param_6);
u32 FUN_0044a110(float param_1,float param_2,float param_3,float param_4,int param_5,short param_6);
u32 FUN_0044f300(char param_1);
u32 FUN_0044ffb0(int param_1);
u32 FUN_004514a0(char param_1);
u32 FUN_004523c0(u64 param_1,char param_2);
u32 FUN_00452a70(char param_1,char param_2);
u32 FUN_004534b0(char param_1);
u32 FUN_00453ed0(char param_1,char param_2,char param_3,u32 *param_4,char param_5,char param_6);
u32 FUN_004541f0(int param_1);
u32 FUN_00457470(int param_1);
u32 FUN_004575e0(int param_1);
u32 FUN_004589e0(void);
u32 FUN_00458a80(char param_1,char param_2);
u32 FUN_00458cb0(u64 param_1,char param_2,char param_3);
u32 FUN_00459790(u64 param_1,char param_2);
u32 FUN_00459e00(char param_1);
u32 FUN_00459e80(int param_1);
u32 FUN_0045a020(int param_1);
u32 FUN_0045a280(u64 param_1,int param_2);
u32 FUN_0045af40(void);
u32 FUN_0045afd0(float param_1,long param_2,int param_3,int param_4,int param_5,int param_6, u8 param_7,u8 param_8,short param_9);
u32 FUN_0045b190(long param_1);
u32 FUN_0045b420(long param_1,long param_2);
u32 FUN_0045df00(int param_1);
u32 FUN_0045e3e0(u64 param_1);
u32 FUN_0045e8c0(u64 param_1);
u32 FUN_0045eaf0(void);
u32 FUN_0045eba0(void);
u32 FUN_00465590(int param_1,u64 param_2);
u32 FUN_00466710(int param_1);
u32 FUN_00466720(int param_1);
u32 FUN_00466730(u32 *param_1);
u32 FUN_00469030(int param_1);
u32 FUN_00469340(int param_1);
u32 FUN_004695f0(int param_1);
u32 FUN_00469650(int param_1);
u32 FUN_004696b0(int param_1);
u32 FUN_00469710(int param_1);
u32 FUN_004698e0(int param_1);
u32 FUN_00469a90(void);
u32 FUN_00469ce0(void);
u32 FUN_00469cf0(void);
u32 FUN_0046a6c0(int param_1,u64 param_2,u64 param_3,u64 param_4);
u32 FUN_0046a6f0(int param_1,u64 param_2,u64 param_3,u64 param_4);
u32 FUN_0046a720(int param_1,u64 param_2,u64 param_3,u64 param_4);
u32 FUN_0046a750(u64 param_1);
u32 FUN_0046a890(u64 param_1);
u32 FUN_0046eb10(int param_1,u32 *param_2);
u32 FUN_00473600(int *param_1,u32 param_2);
u32 FUN_00473b10(int *param_1,u32 param_2);
u32 FUN_00473fb0(u32 param_1);
u32 FUN_00474640(int param_1,int *param_2,u32 param_3,u32 param_4);
u32 FUN_00474a80(int param_1);
u32 FUN_00478440(int param_1,u32 *param_2);
u32 FUN_00478e80(u64 param_1,u32 param_2);
u32 FUN_00479840(int param_1,u32 *param_2);
u32 FUN_0047a210(u64 param_1,int param_2);
u32 FUN_0047a510(u64 param_1,u64 param_2,u64 param_3,u32 param_4);
u32 FUN_0047abf0(int param_1,u32 *param_2);
u32 FUN_0047bd20(u64 param_1);
u32 FUN_0047de30(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_0047e9e0(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5);
u32 FUN_0047fb10(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_00480c30(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_00481860(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5);
u32 FUN_00482a50(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_00483170(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
u32 FUN_004861b0(u64 param_1,u64 param_2,u32 param_3,u32 param_4);
u32 FUN_00486340(u32 param_1,int param_2,u32 param_3);
u32 FUN_00489020(int param_1);
u32 FUN_00489550(int *param_1,int param_2,long param_3,int param_4,long param_5,long param_6, long param_7,long param_8);
u32 FUN_004899f0(u64 param_1);
u32 FUN_00489a80(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
u32 FUN_0048a1a0(void);
u32 FUN_0048a2c0(int param_1);
u32 FUN_0048a3d0(u32 *param_1);
u32 FUN_0048a3e0(int param_1);
u32 FUN_0048a480(int param_1);
u32 FUN_0048abf0(void);
u32 FUN_0048ac00(void);
u32 FUN_0048da30(u64 param_1);
u32 FUN_0048ef30(int param_1);
f32 FUN_0048ef60(int param_1,int param_2);
u32 FUN_0048ef80(int param_1,int param_2);
int FUN_0048efe0(int param_1);
u32 FUN_00491a80(u64 param_1);
u32 FUN_00491ea0(u64 param_1);
u32 FUN_00492d50(u64 param_1);
u32 FUN_00493b60(u64 param_1);
u32 FUN_00494760(u64 param_1);
u32 FUN_00494cc0(u64 param_1);
u32 FUN_00495320(int *param_1,int param_2);
u32 FUN_00495c20(u64 param_1);
u32 FUN_00495c80(int *param_1);
u32 FUN_00497600(int param_1,u32 param_2,int *param_3,int param_4);
u32 FUN_004982b0(int *param_1,long param_2);
u32 FUN_00498e40(long param_1,long param_2);
u32 FUN_00499c20(code *param_1,u64 param_2);
u32 FUN_0049a170(u32 param_1);
u32 FUN_0049a290(int param_1);
u32 FUN_0049aeb0(u64 param_1);
u32 FUN_0049af20(int *param_1);
u32 FUN_0049c230(int param_1);
u32 FUN_0049c790(void);
u32 FUN_0049c7a0(u64 param_1,u32 *param_2);
u32 FUN_0049c8c0(void);
u32 FUN_0049cc70(int param_1);
u32 FUN_0049e6c0(int param_1);
u32 FUN_0049e780(int param_1);
u32 FUN_0049f5d0(int param_1,u32 *param_2);
u32 FUN_004a09d0(u64 param_1,u32 *param_2);
u32 FUN_004a1430(int param_1);
u32 FUN_004a2bb0(int param_1);
u32 FUN_004a4060(int param_1,int *param_2);
u32 FUN_004a42f0(int param_1);
u32 FUN_004a4f90(int param_1);
u32 FUN_004a5080(int param_1);
u32 FUN_004a5210(void);
u32 FUN_004a52a0(void);
u32 FUN_004a5330(void);
u32 FUN_004a5400(void);
u32 FUN_004a5540(u64 param_1);
u32 FUN_004a9330(void);
u32 FUN_004a9550(u32 param_1);
u32 FUN_004a96b0(int param_1);
u32 FUN_004a9bf0(void);
u32 FUN_004a9d80(float *param_1,float *param_2,float *param_3);
u32 FUN_004a9f20(float param_1,float param_2,float param_3,float param_4);
u32 FUN_004aa410(int param_1);
u32 FUN_004aa540(void);
u32 FUN_004aa6c0(void);
u32 FUN_004aada0(u32 param_1,u32 param_2);
u32 FUN_004aae00(u32 param_1,u32 param_2);
u32 FUN_004ab0c0(void);
u32 FUN_004ac870(void);
u32 FUN_004adb80(void);
u32 FUN_004ae010(int param_1);
u32 FUN_004ae8f0(int param_1);
u32 FUN_004ae900(int param_1);
u32 FUN_004af130(u64 param_1);
u32 FUN_004af940(int param_1);
u64 FUN_00430060(int param_1);
u64 FUN_00430180(u64 param_1);
u64 FUN_00430bb0(u64 param_1);
u64 FUN_00431110(u64 param_1,u64 param_2,char param_3,u8 param_4);
u64 FUN_004312b0(u64 param_1);
u64 FUN_00431670(u64 param_1,char param_2,u32 param_3);
u64 FUN_00439f60(u64 param_1,char param_2);
u64 FUN_0043a0b0(u64 param_1,char param_2);
u64 FUN_0043c690(u32 param_1);
u64 FUN_00447e70(u64 param_1,u8 param_2,u8 param_3);
u64 FUN_0044aaf0(u64 param_1);
u64 FUN_0044ad20(u64 param_1,char param_2);
u64 FUN_0044e560(u64 param_1);
u64 FUN_004542c0(char param_1);
u64 FUN_00454620(char param_1);
u64 FUN_00455e00(u64 param_1);
u64 FUN_004560d0(u32 param_1,u32 param_2,u32 param_3,u64 param_4, u32 param_5,u32 param_6);
u64 FUN_004579b0(u64 param_1);
u64 FUN_00457a40(u64 param_1);
u64 FUN_00458630(u64 param_1,char param_2,u8 param_3);
u64 FUN_00459f60(u64 param_1,u16 param_2,char param_3);
u64 FUN_0045ee00(u64 param_1,u64 param_2);
u64 FUN_0045f4e0(u64 param_1,int param_2);
u64 FUN_0045f580(u64 param_1,u64 param_2,int param_3,int param_4);
u64 FUN_0045f600(u64 param_1,u64 param_2,char *param_3,int param_4);
u64 FUN_00464020(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
u64 FUN_00464120(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
u64 FUN_004643b0(u64 param_1,int param_2,u32 param_3);
u64 FUN_004654a0(u64 param_1,u64 param_2);
u64 FUN_00465930(u64 param_1,u64 param_2);
u64 FUN_00465a00(u64 param_1);
u64 FUN_00465ae0(u64 param_1);
u64 FUN_00465bf0(u64 param_1,int param_2);
u64 FUN_00465cf0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00465eb0(u64 param_1,u64 param_2,u32 param_3);
u64 FUN_00466260(u32 param_1,u32 *param_2,u32 *param_3,u32 param_4,u64 param_5);
u64 FUN_004663d0(u64 param_1);
u64 FUN_00466480(u32 param_1,int param_2,u32 param_3,u64 param_4);
u64 FUN_00466640(u64 param_1);
u64 FUN_00466ef0(u32 *param_1);
u64 FUN_00467590(u64 param_1);
u64 FUN_00467600(u64 param_1);
u64 FUN_004676c0(u64 param_1);
u64 FUN_004677f0(u64 param_1);
u64 FUN_00467860(u64 param_1,u64 param_2);
u64 FUN_00467b40(u64 param_1,int *param_2);
u64 FUN_00467fd0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00468560(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00468690(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_004687e0(long param_1,int *param_2);
u64 FUN_00468dc0(u64 param_1);
u64 FUN_00468e30(u64 param_1);
u64 FUN_00468ea0(u64 param_1,int param_2);
u64 FUN_00469060(u64 param_1,long param_2);
u64 FUN_00469280(u64 param_1,u32 param_2);
u64 FUN_004692e0(float param_1,u64 param_2);
u64 FUN_00469400(u64 param_1,int param_2);
u64 FUN_004694b0(u64 param_1,u32 param_2);
u64 FUN_00469510(u64 param_1,u32 param_2);
u64 FUN_00469590(u32 param_1,u64 param_2);
u64 FUN_00469770(u64 param_1,int param_2);
u64 FUN_00469840(u64 param_1,u32 param_2,u32 param_3);
u64 FUN_00469940(u64 param_1,u32 *param_2,u32 *param_3);
u64 FUN_004699b0(u64 param_1,u32 param_2,u32 param_3);
u64 FUN_00469a10(u64 param_1,long param_2,long param_3);
u64 FUN_00469d00(u64 param_1);
u64 FUN_00469d60(u64 param_1);
u64 FUN_00469e30(u64 param_1,int param_2);
u64 FUN_00469fe0(u64 param_1);
u64 FUN_0046a040(u64 param_1,int param_2);
u64 FUN_0046a0f0(u64 param_1,u64 param_2,int param_3);
u64 FUN_0046a230(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_0046a470(u64 param_1,int param_2);
u64 FUN_0046a600(u64 param_1);
u64 FUN_0046a660(u64 param_1);
u64 FUN_0046a830(u64 param_1);
u64 FUN_0046a970(u64 param_1,int param_2);
u64 FUN_0046aa80(u64 param_1,u32 *param_2);
u64 FUN_0046ac30(u64 param_1);
u64 FUN_0046ad80(u32 *param_1);
u64 FUN_0046afa0(u32 *param_1);
u64 FUN_0046b8e0(int param_1);
u64 FUN_0046c330(u64 param_1,u32 param_2);
u64 FUN_0046c5b0(int param_1);
u64 FUN_0046cd90(int param_1);
u64 FUN_0046d6f0(int param_1);
u64 FUN_0046e170(int param_1);
u64 FUN_0046eb90(int param_1,u32 *param_2);
u64 FUN_0046f400(u32 *param_1,u32 *param_2);
u64 FUN_0046fdd0(int param_1);
u64 FUN_00470200(float *param_1,float *param_2);
u64 FUN_004709e0(int param_1);
u64 FUN_00470e10(u32 *param_1,u32 *param_2);
u64 FUN_00471470(int param_1);
u64 FUN_004718a0(int param_1,u32 *param_2);
u64 FUN_00472270(int param_1);
u64 FUN_00472970(int param_1);
u64 FUN_004733c0(int param_1,int param_2);
u64 FUN_004734d0(u64 param_1);
u64 FUN_00474160(u64 param_1);
u64 FUN_004747f0(u64 param_1);
u64 FUN_00474820(int param_1,long param_2,u32 param_3);
u64 FUN_004748c0(int param_1,long param_2);
u64 FUN_004749a0(int param_1,long param_2);
u64 FUN_00474bb0(u64 param_1);
u64 FUN_00474c60(u64 param_1);
u64 FUN_00478520(int param_1);
u64 FUN_00478a70(void);
u64 FUN_00479900(int param_1);
u64 FUN_00479e50(void);
u64 FUN_0047a710(u64 param_1,int *param_2);
u64 FUN_0047b280(u64 param_1,float *param_2,u32 param_3,u8 *param_4);
u64 FUN_0047b750(u64 param_1,float *param_2,u32 param_3,float *param_4);
u64 FUN_0047be10(int param_1,int param_2,u64 param_3);
u64 FUN_00488cd0(u64 param_1);
u64 FUN_00488d40(u64 param_1);
u64 FUN_00489080(u64 param_1,int *param_2);
u64 FUN_00489160(u64 param_1,long param_2);
u64 FUN_00489730(u64 param_1);
u64 FUN_00489840(u64 param_1);
u64 FUN_004898e0(u64 param_1);
u64 FUN_00489960(u64 param_1);
u64 FUN_00489b70(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00489cd0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00489f20(u64 param_1,u64 param_2,int param_3,u64 param_4,u64 param_5);
u64 FUN_0048a2a0(u64 param_1,u32 param_2);
u64 FUN_0048a2e0(u64 param_1,int param_2);
u64 FUN_0048a370(u64 param_1);
u64 FUN_0048a4b0(u64 param_1);
u64 FUN_0048a790(u64 param_1);
u64 FUN_0048a800(u64 param_1,int param_2);
u64 FUN_0048ac10(u64 param_1,long param_2);
u64 FUN_0048b910(u64 param_1,float *param_2);
u64 FUN_0048cf00(u64 param_1);
u64 FUN_0048cfa0(u64 param_1);
u64 FUN_0048d0e0(u64 param_1);
u64 FUN_0048d270(int param_1,int param_2,u64 param_3);
u64 FUN_0048d370(u64 param_1,int param_2,u32 *param_3);
u64 FUN_0048d480(float param_1,int param_2,long param_3,u64 param_4,long param_5);
u64 FUN_0048d960(u64 param_1);
u64 FUN_0048e020(int *param_1,u64 param_2);
u64 FUN_0048e2d0(int *param_1,u64 param_2);
u64 FUN_0048e750(long param_1,u64 param_2);
u64 FUN_0048eab0(u64 param_1,int param_2);
u64 FUN_0048eb50(u64 param_1,int param_2,int param_3);
u64 FUN_0048ec20(u64 param_1,u64 param_2,int param_3,int param_4);
u64 FUN_0048ecf0(u64 param_1,u64 param_2,int param_3,int param_4);
u64 FUN_0048f340(u64 param_1,int param_2);
u64 FUN_0048f3c0(u64 param_1,u64 param_2,int param_3);
u64 FUN_0048f460(u64 param_1,int param_2);
u64 FUN_0048f4e0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00490770(u64 param_1,u64 param_2,int param_3);
u64 FUN_00490810(u64 param_1);
u64 FUN_00490860(u64 param_1);
u64 FUN_004908d0(u64 param_1,int param_2);
u64 FUN_00490980(u64 param_1,u64 param_2);
u64 FUN_00490d00(u64 param_1);
u32 FUN_00490d40(int param_1);
u64 FUN_00490d90(u64 param_1);
u64 FUN_00491410(u64 param_1);
u64 FUN_004914d0(u64 param_1,int param_2);
u64 FUN_00491630(u64 param_1);
u64 FUN_004916d0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_00491760(u64 param_1,code *param_2,u64 param_3);
u64 FUN_004917f0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_004919b0(u64 param_1,int param_2,u32 param_3);
u64 FUN_00491ff0(u64 param_1,int param_2);
u64 FUN_00492020(u64 param_1,int param_2);
u64 FUN_00492060(u64 param_1,int param_2);
u64 FUN_00492d10(u64 param_1);
u64 FUN_00492e20(u64 param_1,float *param_2);
u64 FUN_00493210(u64 param_1,u16 *param_2,u16 param_3,u16 param_4, u16 param_5);
u64 FUN_00493230(u64 param_1,int param_2,long param_3);
u64 FUN_004932c0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_00493370(u64 param_1,u16 param_2);
u64 FUN_004933d0(u64 param_1);
u32 FUN_00493b40(u32 param_1);
u64 FUN_004944b0(u64 param_1,u32 *param_2);
u64 FUN_004948b0(u64 param_1);
u64 FUN_00494930(u64 param_1,int param_2);
u64 FUN_004949c0(u64 param_1,int param_2);
u64 FUN_00494a40(u64 param_1,u64 param_2,int param_3);
u64 FUN_00494ae0(u64 param_1,int param_2);
u64 FUN_00494b70(u64 param_1);
u64 FUN_00494d50(u64 param_1,long param_2);
u64 FUN_00495260(u64 param_1);
u32 FUN_00495300(u32 param_1);
u64 FUN_00495a30(u64 param_1,int param_2);
u64 FUN_00495cf0(u64 param_1,u32 param_2,u16 param_3,u16 param_4, u16 param_5,u16 param_6,u16 param_7,u16 param_8, u16 param_9);
u64 FUN_00495f10(u64 param_1,code *param_2,u64 param_3);
u64 FUN_00495fb0(u32 *param_1,char *param_2,u64 param_3,u64 param_4);
u64 FUN_004967a0(u64 param_1);
u64 FUN_00496be0(u32 param_1,u32 *param_2,int param_3,u32 *param_4);
u64 FUN_00498720(int param_1,u64 param_2,u32 param_3);
u64 FUN_00499320(u64 param_1);
u64 FUN_00499a80(u64 param_1);
u64 FUN_00499af0(u64 param_1,int param_2);
u64 FUN_00499b90(u64 param_1);
u64 FUN_00499ca0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_00499d30(u64 param_1);
u64 FUN_00499fd0(u64 param_1);
u64 FUN_0049a250(u64 param_1);
u32 FUN_0049a3d0(u32 param_1,code *param_2);
u64 FUN_0049a7c0(u64 param_1,code *param_2,u64 param_3);
u64 FUN_0049a870(u64 param_1,code *param_2,u64 param_3);
u64 FUN_0049aaf0(u64 param_1,int param_2);
u64 FUN_0049abf0(u64 param_1);
u64 FUN_0049ade0(u64 param_1,int param_2);
u64 FUN_0049ae30(u64 param_1);
u64 FUN_0049b180(u64 param_1);
u64 FUN_0049b2e0(u64 param_1);
u64 FUN_0049b3f0(u64 param_1,int param_2);
u64 FUN_0049b440(u64 param_1);
u64 FUN_0049b760(u64 param_1,int param_2);
u64 FUN_0049b7a0(u64 param_1);
u64 FUN_0049b850(u64 param_1,int param_2);
u64 FUN_0049bbc0(u64 param_1,u64 param_2);
u64 FUN_0049bbf0(u64 param_1,u64 param_2);
u64 FUN_0049bc20(u64 param_1,u64 param_2);
u64 FUN_0049bdc0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_0049c160(u64 param_1,int param_2);
#pragma alias FUN_0049c160_wide FUN_0049c160
extern u64 FUN_0049c160_wide(u64 param_1,u64 param_2);
u64 FUN_0049c1b0(u64 param_1,int param_2);
u64 FUN_0049c1e0(u64 param_1,int param_2);
u64 FUN_0049c240(u64 param_1,u64 param_2);
u64 FUN_0049c330(u64 param_1,code *param_2,u64 param_3);
u64 FUN_0049c3d0(u64 param_1,int param_2);
u64 FUN_0049c480(u64 param_1,int param_2);
u64 FUN_0049dc70(int param_1);
u64 FUN_0049e5a0(u64 param_1,int param_2);
u64 FUN_0049e830(u64 param_1,u64 param_2);
u64 FUN_0049e9f0(u64 param_1,u64 param_2);
u64 FUN_0049ee70(u64 param_1,u64 param_2);
u64 FUN_0049f040(u64 param_1,u64 param_2);
u64 FUN_0049faa0(u64 param_1);
u64 FUN_004a0430(u64 param_1,int param_2);
u64 FUN_004a0e00(int param_1);
u64 FUN_004a30d0(int param_1);
u64 FUN_004a3f20(u64 param_1);
u64 FUN_004a4d60(u64 param_1,int param_2);
u64 FUN_004a4da0(u64 param_1);
u64 FUN_004a4e40(u64 param_1);
u64 FUN_004a4ef0(u64 param_1);
u64 FUN_004a55b0(u64 param_1,float *param_2,float *param_3,float *param_4,float *param_5, float *param_6,float *param_7);
u64 FUN_004a5dd0(u64 param_1,u8 *param_2,u8 *param_3,u8 *param_4,u64 param_5);
u64 FUN_004a6200(u64 param_1,float *param_2,float *param_3,float *param_4,float *param_5);
u64 FUN_004a62e0(u64 param_1,long param_2);
u64 FUN_004a6360(u64 param_1,int param_2,u64 param_3);
u64 FUN_004a6530(u64 param_1,u64 param_2);
u64 FUN_004a6600(u64 param_1,u64 param_2);
u64 FUN_004a7620(u64 param_1);
u64 FUN_004ab1b0(u64 param_1);
u64 FUN_004ab200(u32 param_1,u32 param_2,u64 param_3);
u64 FUN_004ab2c0(float param_1,float param_2,u64 param_3);
u64 FUN_004ab410(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6, u64 param_7);
u64 FUN_004ab6a0(u64 param_1);
u64 FUN_004abd50(u64 param_1,u32 *param_2);
u64 FUN_004ac020(int *param_1,u64 param_2);
u64 FUN_004ac920(u64 param_1,int param_2,u64 param_3);
u64 FUN_004acb10(u64 param_1,u64 param_2);
u64 FUN_004ad480(u64 param_1,char *param_2);
u64 FUN_004ad5b0(u64 param_1,long param_2,u64 param_3);
u64 FUN_004ad6a0(int param_1);
u64 FUN_004ad700(u64 param_1,u64 param_2);
u64 FUN_004ad750(u64 param_1);
u64 FUN_004ad940(u64 param_1,u64 param_2);
u64 FUN_004adbd0(int *param_1);
u64 FUN_004adcc0(u64 param_1,u32 param_2);
u64 FUN_004addb0(u64 param_1,u64 param_2);
u64 FUN_004ade90(u64 param_1);
u64 FUN_004adf30(u64 param_1);
u64 FUN_004adfd0(u64 param_1,int param_2);
u64 FUN_004ae020(u64 param_1,u32 *param_2);
u64 FUN_004ae070(u32 param_1,u32 param_2,u64 param_3);
u64 FUN_004ae0c0(u32 param_1,u32 param_2,u64 param_3);
u32 FUN_004ae110(int param_1,int param_2);
u64 FUN_004ae150(u64 param_1,u64 param_2);
u32 FUN_004ae1d0(u32 param_1,u32 param_2);
u64 FUN_004ae1f0(int param_1,u32 *param_2);
u64 FUN_004ae270(u64 param_1,u64 param_2);
u64 FUN_004ae2f0(u64 param_1);
u64 FUN_004ae3b0(u64 param_1,u64 param_2);
u64 FUN_004ae690(u64 param_1);
u64 FUN_004ae790(u64 param_1);
u64 FUN_004ae960(u64 param_1,float *param_2,float *param_3);
u64 FUN_004aeb60(u64 param_1,code *param_2,u64 param_3);
u64 FUN_004aebf0(u64 param_1,u64 param_2,long param_3);
u32 FUN_004aef50(u32 param_1);
u64 FUN_004aef60(u64 param_1);
u64 FUN_004af340(u32 *param_1);
u64 FUN_004af760(u64 param_1);
u64 FUN_004af9d0(u64 param_1,float *param_2,float *param_3);
u64 FUN_004affe0(u64 param_1,u64 param_2,long param_3);
u8 * FUN_00493710(int param_1,int param_2,u32 param_3);
u8 * FUN_004aae60(void);
u8 ** FUN_0049ff00(void);
u8 ** FUN_004a3f10(void);
u8 FUN_00435260(char param_1);
u8 FUN_004353f0(int param_1);
u8 FUN_00435810(void);
u8 FUN_004359f0(u64 param_1,u8 param_2,u8 param_3,u32 *param_4, u8 param_5,u8 param_6);
u8 FUN_0043c730(char param_1);
u8 FUN_0043c7f0(char param_1);
u8 FUN_00449c90(u64 param_1,char param_2);
u8 FUN_0044a420(int param_1,long param_2,u64 param_3);
u8 FUN_0044f060(float param_1,int param_2,float *param_3);
u8 FUN_0044f1c0(float param_1,float *param_2,float *param_3);
u8 FUN_0044fab0(int param_1);
u8 FUN_00453480(void);
u8 FUN_00454400(u32 *param_1,char param_2);
u8 FUN_00454520(float *param_1,char param_2);
u8 FUN_00454a70(char param_1,float *param_2);
u8 FUN_00454d00(float *param_1);
u8 FUN_00457390(char param_1);
u8 FUN_004573d0(char param_1);
u8 FUN_0045a3b0(void);
u8 FUN_0045af90(long param_1);
u8 FUN_0045b480(long param_1);
u8 FUN_0045b4b0(long param_1);
u8 FUN_0045e010(int param_1);
u8 FUN_0045e0c0(int param_1);
u8 FUN_0045e170(int param_1);
u8 FUN_0045ec00(void);
u8 FUN_0045ec20(void);
u8 FUN_0045f7d0(void);
u8 FUN_004661b0(void);
u8 FUN_00468c50(void);
u8 FUN_0046a530(void);
u8 FUN_00473590(void);
u8 FUN_00477050(int param_1);
u8 FUN_00479030(int param_1);
u8 FUN_0047a3d0(int param_1);
u8 FUN_00488fe0(void);
u8 FUN_0048ad20(void);
u8 FUN_0048dcf0(void);
u8 FUN_0048f030(void);
u8 FUN_004915c0(void);
u8 FUN_0049a980(void);
u8 FUN_0049be50(void);
u8 FUN_0049c6c0(void);
u8 FUN_004a5100(void);
u8 FUN_004a9bd0(int param_1);
u8 FUN_004aa390(float param_1);
u8 FUN_004aa3d0(float param_1);
u8 FUN_004aaa60(void);
u8 FUN_004aab40(long param_1);
u8 FUN_004aac70(u32 *param_1);
u8 FUN_004ac390(long param_1);
u8 FUN_004accc0(float *param_1,int *param_2);
u8 FUN_004ae1e0(int param_1);
u8 FUN_004ae4e0(int param_1);
u8 FUN_004ae5a0(long param_1);
void FUN_00430150(int param_1);
void FUN_00430220(int param_1,u64 param_2);
void FUN_00430270(u32 *param_1,int param_2);
void FUN_004302a0(int param_1);
void FUN_004302b0(void);
void FUN_00430630(int param_1);
void FUN_00430780(u64 param_1,int param_2,int param_3,int param_4);
void FUN_00430a40(char param_1);
void FUN_004310e0(int param_1);
void FUN_004311f0(float *param_1,u32 param_2,u32 param_3);
void FUN_00431630(int param_1);
void FUN_004332f0(int param_1);
void FUN_004333d0(int param_1);
void FUN_004334d0(int param_1);
void FUN_004343d0(int param_1);
void FUN_004344f0(float param_1,float *param_2,int param_3,float *param_4,float *param_5);
void FUN_00434c90(char param_1);
void FUN_00434d30(void);
void FUN_00434e60(void);
void FUN_00434f60(u8 param_1);
void FUN_00434f70(void);
void FUN_00435060(u8 param_1);
void FUN_004350e0(char param_1,char param_2);
void FUN_00435370(u8 param_1);
void FUN_00435c00(u64 param_1);
void FUN_00437e00(void);
void FUN_00437e80(u32 *param_1,char param_2);
void FUN_00438010(u64 param_1);
void FUN_00439400(char param_1);
void FUN_00439520(u64 param_1);
void FUN_0043a1a0(char param_1,u8 param_2);
void FUN_0043a2f0(int param_1);
void FUN_0043a960(int param_1);
void FUN_0043bf50(u64 param_1);
void FUN_0043c660(int param_1);
void FUN_0043c7a0(char param_1,u8 param_2);
void FUN_00447ad0(int param_1);
void FUN_00447f90(float *param_1,int param_2,char param_3);
void FUN_00448060(u64 param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6);
void FUN_00448cf0(u64 param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6,int param_7);
void FUN_00449d10(int param_1);
void FUN_00449d60(u64 param_1);
void FUN_00449ed0(void);
void FUN_00449fa0(void);
void FUN_0044a240(u32 param_1,u32 param_2,float param_3,u32 param_4,int param_5 ,u8 param_6);
void FUN_0044a330(u32 param_1,u32 param_2,float param_3,u32 param_4,int param_5 ,u8 param_6);
void FUN_0044a630(int param_1);
void FUN_0044a790(u32 *param_1);
void FUN_0044a990(int param_1,u32 *param_2);
void FUN_0044acf0(int param_1);
void FUN_0044af60(u64 param_1);
void FUN_0044b7d0(int param_1);
void FUN_0044beb0(u64 param_1);
void FUN_0044d600(int param_1);
void FUN_0044dfc0(u64 param_1);
void FUN_0044e530(int param_1,u8 param_2);
void FUN_0044f270(float *param_1,float *param_2);
void FUN_004501b0(char param_1);
void FUN_00450b30(char param_1);
void FUN_00451d70(int param_1);
void FUN_00452010(float *param_1);
void FUN_00452f70(u32 *param_1,int param_2);
void FUN_004532d0(char param_1);
void FUN_004533e0(u8 param_1);
void FUN_00453470(u16 param_1);
void FUN_00453490(int param_1);
void FUN_00453d90(char param_1);
void FUN_00454110(int param_1);
void FUN_00454290(int param_1);
void FUN_004543c0(char param_1,u8 param_2);
void FUN_00454f50(char param_1,char param_2);
void FUN_00455b50(void);
void FUN_00455cf0(void);
void FUN_00456050(int param_1);
void FUN_004561d0(u32 param_1,u32 param_2,int param_3);
void FUN_004561f0(float param_1,int param_2);
void FUN_004563b0(f32 param_1, int param_2);
void FUN_004563c0(int param_1,u8 param_2);
void FUN_004563d0(int param_1,u64 param_2);
void FUN_00456400(int param_1,u8 param_2);
void FUN_00456410(char param_1);
void FUN_00456450(char param_1);
void FUN_00456490(char param_1);
void FUN_004564e0(char param_1);
void FUN_00456530(char param_1);
void FUN_00456580(char param_1);
void FUN_004565d0(char param_1);
void FUN_00456620(char param_1);
void FUN_00456670(u64 param_1,u64 param_2);
void FUN_00456a90(u64 param_1,u64 param_2,u64 param_3);
void FUN_00456ea0(u64 param_1,u64 param_2,u64 param_3);
void FUN_00457340(char param_1,u8 param_2,char param_3);
void FUN_00457980(int param_1);
void FUN_00458600(int param_1);
void FUN_00458850(int param_1);
void FUN_00458870(int param_1);
void FUN_00458890(void);
void FUN_00458920(int param_1);
void FUN_00458930(void);
void FUN_004589d0(int param_1,u8 param_2);
void FUN_00458b00(void);
void FUN_00458b60(void);
void FUN_00458bb0(void);
void FUN_00459d60(void);
void FUN_00459f30(int param_1);
void FUN_0045a220(int param_1);
void FUN_0045a3e0(void);
void FUN_0045a430(char param_1);
void FUN_0045a490(void);
void FUN_0045ace0(void);
void FUN_0045af70(u8 param_1);
void FUN_0045b620(float param_1,float param_2,float param_3,float param_4,u64 param_5, char param_6,int param_7);
void FUN_0045b830(int param_1,long param_2);
void FUN_0045b8f0(int param_1);
void FUN_0045bcb0(u64 param_1,u64 param_2);
void FUN_0045bd90(u64 param_1);
void FUN_0045c530(int param_1);
void FUN_0045c8c0(int param_1,int param_2);
void FUN_0045cdd0(u64 param_1,long param_2);
void FUN_0045ce90(u64 param_1);
void FUN_0045d990(u64 param_1,long param_2);
void FUN_0045e7b0(int param_1);
void FUN_0045e7e0(void);
void FUN_0045ea80(int param_1);
void FUN_0045edc0(void);
void FUN_0045f930(int param_1,float *param_2,code *param_3,u32 param_4);
void FUN_004606b0(int param_1,u64 param_2,code *param_3,u32 param_4);
void FUN_00460ec0(int param_1,u64 param_2,u32 param_3,code *param_4,u32 param_5);
void FUN_00461900(int param_1,float *param_2,u64 param_3,code *param_4,u32 param_5);
void FUN_00461d00(int param_1,u64 param_2,u32 param_3,code *param_4,u32 param_5);
void FUN_00461ea0(int param_1,float *param_2,u32 param_3,code *param_4,u32 param_5);
void FUN_00462bb0(int param_1,u64 param_2,u32 param_3,code *param_4,u32 param_5);
void FUN_00463490(int param_1,int param_2,float *param_3,u32 param_4,code *param_5, u32 param_6);
void FUN_00463b20(int param_1,int param_2,int param_3,u32 param_4,code *param_5, u32 param_6);
void FUN_00463f20(int param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00464850(float param_1,int param_2,int param_3,int param_4);
void FUN_00464e80(float param_1,int param_2,int param_3,int param_4);
void FUN_00465670(int param_1,int param_2);
void FUN_00468530(u64 param_1,u64 param_2,int param_3);
void FUN_00468660(u64 param_1,u64 param_2,int param_3);
void FUN_00468720(char *param_1,long param_2,int param_3);
void FUN_00469aa0(int param_1);
void FUN_00469b50(int param_1);
void FUN_00469bc0(int param_1);
void FUN_0046a8d0(int *param_1,int *param_2);
void FUN_0046a9e0(int *param_1);
void FUN_0046b1b0(u32 *param_1,int param_2,u32 *param_3);
void FUN_0046ea80(u64 param_1);
void FUN_00472130(u64 param_1);
void FUN_00472170(u64 param_1);
void FUN_004721b0(u64 param_1);
void FUN_004721f0(u64 param_1);
void FUN_00472230(u64 param_1);
void FUN_00473340(u64 param_1);
void FUN_00473380(u64 param_1);
void FUN_00474210(u64 param_1,u64 param_2,u64 param_3);
void FUN_00474d30(int param_1,int param_2);
void FUN_00474f20(int param_1,u32 param_2);
void FUN_00475c20(int param_1);
void FUN_00475cb0(int param_1);
void FUN_00476140(u32 *param_1,long param_2,u32 param_3);
void FUN_00476490(u64 *param_1,long param_2,u64 *param_3);
void FUN_00476720(int param_1,long param_2,u64 *param_3);
void FUN_00476980(int param_1,long param_2,u64 *param_3);
void FUN_00476c20(int param_1,int param_2,long param_3);
void FUN_00477150(int *param_1,int param_2,u64 param_3,u64 param_4,u32 param_5);
void FUN_00477470(int *param_1,u64 param_2,u64 param_3,u64 param_4, u32 param_5);
void FUN_00477610(int *param_1,u64 param_2,u64 param_3,int param_4,int param_5);
void FUN_00477810(u32 *param_1,int param_2,int param_3);
void FUN_00477a20(u32 *param_1,int param_2,int param_3);
void FUN_00477c90(int *param_1,int param_2,int param_3);
void FUN_00477eb0(int *param_1,int param_2,int param_3);
void FUN_00478100(int *param_1,int param_2,int param_3);
void FUN_00478280(int *param_1,int param_2,int param_3);
void FUN_00478cc0(int param_1,u32 *param_2);
void FUN_00479170(int *param_1,int param_2,u64 param_3,u64 param_4,u32 param_5);
void FUN_00479590(int *param_1,u64 param_2,u64 param_3,u64 param_4, u32 param_5);
void FUN_0047a050(int param_1,u32 *param_2);
void FUN_0047bf80(int param_1);
void FUN_0047c240(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_0047c8c0(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_004838e0(u32 *param_1,int param_2,int param_3);
void FUN_00485070(u32 *param_1,int param_2,int param_3);
void FUN_00485110(u32 *param_1,int param_2,int param_3);
void FUN_00485440(u32 *param_1,int param_2,int param_3);
void FUN_00485750(int *param_1,int param_2,int param_3);
void FUN_00485e20(int *param_1,int param_2,int param_3);
void FUN_00485ef0(int *param_1,int param_2,int param_3);
void FUN_00485ff0(int *param_1,int param_2,int param_3);
void FUN_004866c0(int param_1);
void FUN_00486c80(int *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_00487030(int *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_00487280(int *param_1,float *param_2,float *param_3,int param_4,int param_5);
void FUN_004876f0(int *param_1,float *param_2,float *param_3,long param_4,int param_5);
void FUN_00487bf0(u32 *param_1,int param_2,int param_3);
void FUN_00488550(int *param_1,int param_2,int param_3,int param_4,u32 param_5);
void FUN_00489350(u64 param_1,long param_2);
void FUN_004893e0(int param_1,int param_2,u32 param_3);
void FUN_00489460(int param_1,u32 *param_2,int *param_3,int param_4,u32 *param_5,u32 param_6);
void FUN_0048a3f0(u64 param_1,long param_2);
void FUN_0048dd70(int *param_1);
void FUN_0048de50(int *param_1,int *param_2);
void FUN_0048e610(int *param_1);
void FUN_0048efa0(int param_1,int param_2,u32 param_3);
void FUN_0048efc0(int param_1,int param_2,f32 param_3);
void FUN_00491100(int param_1);
void FUN_00492c30(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00492c60(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00492c90(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00492cc0(u64 param_1,u64 param_2);
void FUN_00492ce0(u64 param_1,u64 param_2);
void FUN_00492d00(u32 param_1);
void FUN_00493c50(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00493c80(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00494520(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00494550(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00494db0(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00494de0(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00494e10(u64 param_1,u64 param_2);
void FUN_00495480(int *param_1,int param_2);
int FUN_004959c0(u64 param_1);
void FUN_00496580(void);
void FUN_00496ad0(u64 param_1,int *param_2,short param_3,short param_4,int param_5, int param_6);
void FUN_00496f60(int param_1,int param_2,long param_3);
void FUN_00498e30(u64 param_1);
void FUN_00499230(void);
void FUN_00499250(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00499280(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_004992b0(u64 param_1,u64 param_2);
void FUN_004992d0(u64 param_1,u64 param_2);
void FUN_00499720(u64 param_1);
void FUN_00499850(int *param_1);
void FUN_00499e90(u32 param_1,u32 param_2);
void FUN_00499f40(int param_1);
void FUN_0049a920(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_0049a950(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_0049afa0(int param_1,u64 param_2);
void FUN_0049be20(int param_1);
void FUN_0049c680(void);
void FUN_0049c9b0(void);
void FUN_0049ca50(long param_1);
void FUN_0049cab0(float param_1,u8 *param_2);
void FUN_0049cbd0(int param_1,float *param_2);
void FUN_0049cc30(int param_1);
void FUN_0049e4f0(u64 param_1);
void FUN_0049ff10(u32 param_1,u32 param_2,int param_3,long param_4);
void FUN_004a0480(int param_1,int param_2);
void FUN_004a05d0(int param_1,int param_2);
void FUN_004a06c0(int param_1);
void FUN_004a08f0(int param_1,int *param_2,int param_3,u32 param_4);
void FUN_004a0dc0(int param_1);
void FUN_004a24a0(int param_1,int param_2);
void FUN_004a2560(u64 param_1,int *param_2);
void FUN_004a3540(int param_1);
void FUN_004a3f70(int param_1,u32 *param_2);
void FUN_004a53b0(void);
void FUN_004a91f0(void);
void FUN_004a97c0(u64 param_1,u64 param_2);
void FUN_004a9a70(int param_1);
void FUN_004aa550(u64 param_1);
void FUN_004aa5c0(void);
void FUN_004aa620(void);
void FUN_004aad50(void);
void FUN_004ab170(u32 *param_1);
void FUN_004ab910(float *param_1,float *param_2,float *param_3);
void FUN_004aba20(u64 param_1,u64 param_2,int param_3);
void FUN_004ac410(int *param_1);
void FUN_004ac7f0(void);
void FUN_004ac860(u32 param_1,u32 param_2);
void FUN_004adb50(void);
void FUN_004adc70(u64 param_1);
void FUN_004adc90(u64 param_1,u64 param_2);
void FUN_004adca0(void);
void FUN_004ae060(int param_1);
void FUN_004ae940(u64 param_1);

#pragma schedule on
// FUN_0045EC00

u8 FUN_0045ec00(void)

{
  int iVar1;
  
  iVar1 = FUN_005316d0_s32();
  return iVar1 < 0;
}

#pragma schedule on
// FUN_0045EC20

u8 FUN_0045ec20(void)
{
  int iVar1;
  
  iVar1 = FUN_005316d0_s32();
  return 0 < iVar1;
}
#pragma schedule off

// FUN_0045EC40 NONMATCHING

long FUN_0045ec40(u16 param_1,u16 param_2,u32 *param_3,u32 param_4)

{
  u32 *puVar1;
  u32 *puVar2;
  long lVar3;
  int iVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar4 = 0x28;
  if (param_2 != 0) {
    iVar4 = (u32)param_2 * 0x10 + 0x37;
  }
  if ((param_4 & 1) != 0) {
    iVar4 = iVar4 + (u32)param_1 * 2 + 1;
  }
  lVar3 = (*DAT_00960178)(iVar4,0x3002c);
  if (lVar3 == 0) {
    uStack_8 = 0x11d;
    uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,iVar4);
    ((code)FUN_004c1c50)(&uStack_8);
    lVar3 = 0;
  }
  else {
    puVar1 = (u32 *)lVar3;
    *puVar1 = param_4;
    *(u16 *)(puVar1 + 7) = param_1;
    *(u16 *)((int)puVar1 + 0x1e) = param_2;
    uVar7 = param_3[1];
    uVar5 = param_3[2];
    uVar6 = param_3[3];
    puVar1[1] = *param_3;
    puVar1[2] = uVar7;
    puVar1[3] = uVar5;
    puVar1[4] = uVar6;
    uVar5 = param_3[5];
    puVar1[5] = param_3[4];
    puVar1[6] = uVar5;
    puVar2 = puVar1 + 10;
    if (param_2 == 0) {
      puVar1[8] = 0;
    }
    else {
      uVar5 = (int)puVar1 + 0x37U & 0xfffffff0;
      puVar2 = (u32 *)(uVar5 + (u32)param_2 * 0x10);
      puVar1[8] = uVar5;
    }
    if ((param_4 & 1) == 0) {
      puVar1[9] = 0;
    }
    else {
      puVar1[9] = (int)puVar2 + 1U & 0xfffffffe;
    }
  }
  return lVar3;
}

#pragma alias DAT_0096017c_abs DAT_0096017c
extern void (*DAT_0096017c_abs[])(void);

#pragma optimization_level 3
// FUN_0045EDC0
void FUN_0045edc0(void)
{
  DAT_0096017c_abs[0]();
}
#pragma optimization_level 2

// FUN_0045EDD0
asm int FUN_0045edd0(u32 *param_1)
{
  .set noreorder
  lhu $v0, 0x1e($a0)
  addiu $a1, $zero, 0x30
  lw $v1, 0($a0)
  sll $v0, $v0, 4
  andi $v1, $v1, 1
  beq $v1, $zero, 1f
  addu $v0, $a1, $v0
  lhu $v1, 0x1c($a0)
  sll $v1, $v1, 1
  addu $v0, $v0, $v1
1:
  jr $ra
  nop
  .set reorder
}

// FUN_0045EE00 NONMATCHING

u64 FUN_0045ee00(u64 param_1,u64 param_2)

{
  u32 *puVar1;
  long lVar2;
  u32 *puVar3;
  int iVar4;
  u32 uVar5;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  
  puVar3 = (u32 *)param_1;
  iVar4 = (u32)*(u16 *)((int)puVar3 + 0x1e) * 0x10 + 0x30;
  if ((*puVar3 & 1) != 0) {
    iVar4 = iVar4 + (u32)(u16)puVar3[7] * 2;
  }
  lVar2 = ((code)FUN_004c15a0)(param_2,0x2c,iVar4,0x37002,0x37);
  if (lVar2 == 0) {
    param_1 = 0;
  }
  else {
    lVar2 = ((code)FUN_004c15a0)(param_2,1,iVar4 + -0xc,0x37002,0x37);
    if (lVar2 == 0) {
      param_1 = 0;
    }
    else {
      uStack_2c = puVar3[4];
      uStack_30 = *puVar3;
      uStack_28 = puVar3[5];
      uStack_24 = puVar3[6];
      uStack_20 = puVar3[1];
      uStack_1c = puVar3[2];
      uStack_18 = puVar3[3];
      uStack_14 = (u32)(u16)puVar3[7];
      uStack_10 = (u32)*(u16 *)((int)puVar3 + 0x1e);
      lVar2 = ((code)FUN_004c53f0)(param_2,&uStack_30,0x24);
      if (lVar2 == 0) {
        param_1 = 0;
      }
      else {
        if ((*(short *)((int)puVar3 + 0x1e) != 0) &&
           (uVar5 = 0, *(short *)((int)puVar3 + 0x1e) != 0)) {
          iVar4 = 0;
          do {
            puVar1 = (u32 *)(puVar3[8] + iVar4);
            uStack_40 = *puVar1;
            uStack_3c = puVar1[1];
            uStack_38 = puVar1[2];
            uStack_34 = puVar1[3];
            lVar2 = ((code)FUN_004c53f0)(param_2,&uStack_40,0x10);
            if (lVar2 == 0) {
              return 0;
            }
            uVar5 = uVar5 + 1;
            iVar4 = iVar4 + 0x10;
          } while (uVar5 < *(u16 *)((int)puVar3 + 0x1e));
        }
        if (((*puVar3 & 1) != 0) &&
           (lVar2 = ((code)FUN_004c1820)(param_2,puVar3[9],(u32)(u16)puVar3[7] << 1), lVar2 == 0)) {
          param_1 = 0;
        }
      }
    }
  }
  return param_1;
}

// FUN_0045EFE0 NONMATCHING

long FUN_0045efe0(u64 param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  u32 *puVar4;
  int iVar5;
  u32 uStack_50;
  u32 uStack_4c;
  u32 uStack_48;
  u32 uStack_44;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u16 uStack_14;
  u16 uStack_10;
  u8 auStack_4 [4];
  
  lVar2 = ((code)FUN_004c1600)(param_1,1,0,auStack_4);
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  else {
    lVar2 = ((code)FUN_004c5250)(param_1,&uStack_30,0x24);
    if (lVar2 == 0x24) {
      uStack_44 = uStack_2c;
      uStack_40 = uStack_28;
      uStack_3c = uStack_24;
      uStack_50 = uStack_20;
      uStack_4c = uStack_1c;
      uStack_48 = uStack_18;
      lVar2 = ((code)FUN_0045ec40)(uStack_14,uStack_10,&uStack_50,uStack_30);
      if (lVar2 == 0) {
        lVar2 = 0;
      }
      else {
        puVar4 = (u32 *)lVar2;
        if ((*(u16 *)((int)puVar4 + 0x1e) == 0) ||
           (iVar5 = (u32)*(u16 *)((int)puVar4 + 0x1e) << 4,
           iVar1 = ((code)FUN_004c5250)(param_1,puVar4[8],iVar5), iVar5 == iVar1)) {
          if (((*puVar4 & 1) != 0) &&
             (lVar3 = ((code)FUN_004c1850)(param_1,puVar4[9],(u32)(u16)puVar4[7] << 1), lVar3 == 0)) {
            (*DAT_0096017c)(lVar2);
            lVar2 = 0;
          }
        }
        else {
          (*DAT_0096017c)(lVar2);
          lVar2 = 0;
        }
      }
    }
    else {
      lVar2 = 0;
    }
  }
  return lVar2;
}

// FUN_0045F140 NONMATCHING

long FUN_0045f140(u64 param_1,u16 param_2,u16 param_3,u64 param_4,
                 u32 *param_5)

{
  long lVar1;
  long lVar2;
  u32 *puVar3;
  int iVar4;
  u32 uVar5;
  u8 *puVar6;
  u8 *pbVar7;
  int aiStack_b0 [36];
  u32 uStack_20;
  u32 uStack_1c;
  u8 uStack_18;
  u8 uStack_17;
  u16 uStack_16;
  u8 auStack_10 [4];
  u32 uStack_c;
  u8 auStack_8 [4];
  u32 uStack_4;
  
  *param_5 = 0;
  lVar1 = ((code)FUN_0045ec40)(param_2,param_3,param_4,1);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else {
    puVar3 = (u32 *)lVar1;
    if (*(short *)((int)puVar3 + 0x1e) == 0) {
      lVar2 = ((code)FUN_004c5620)(param_1,4);
      if (lVar2 == 0) {
        (*DAT_0096017c)(lVar1);
        return 0;
      }
    }
    else {
      pbVar7 = (u8 *)puVar3[8];
      uVar5 = 0;
      if (*(short *)((int)puVar3 + 0x1e) != 0) {
        do {
          lVar2 = ((code)FUN_004c1910)(param_1,&uStack_4,4);
          if ((((lVar2 == 0) || (lVar2 = ((code)FUN_004c1910)(param_1,auStack_8,4), lVar2 == 0)) ||
              (lVar2 = ((code)FUN_004c18b0)(param_1,pbVar7 + 4,4), lVar2 == 0)) ||
             (lVar2 = ((code)FUN_004c18b0)(param_1,pbVar7 + 0xc,4), lVar2 == 0)) {
            (*DAT_0096017c)(lVar1);
            return 0;
          }
          pbVar7[8] = (u8)(uStack_4 >> 0x10);
          *pbVar7 = pbVar7[8] | 1;
          *(short *)(pbVar7 + 10) = (*(u16*)((u8*)&auStack_8 + 0));
          *(short *)(pbVar7 + 2) = (*(u16*)((u8*)&auStack_8 + 2));
          if ((uStack_4 >> 8 & 0xff) == 2) {
            pbVar7[1] = 0xff;
          }
          else {
            pbVar7[1] = 0;
          }
          if ((char)uStack_4 == '\x02') {
            pbVar7[9] = 0xff;
          }
          else {
            pbVar7[9] = 0;
          }
          uVar5 = uVar5 + 1;
          pbVar7 = pbVar7 + 0x10;
        } while (uVar5 < *(u16 *)((int)puVar3 + 0x1e));
      }
      uStack_16 = 0;
      uStack_17 = 0xff;
      puVar6 = &uStack_18;
      iVar4 = 1;
      do {
        if (puVar6[1] == -1) {
          puVar6 = (u8 *)(puVar3[8] + (u32)*(u16 *)(puVar6 + 2) * 0x10);
          aiStack_b0[iVar4] = (int)(puVar6 + 8);
          iVar4 = iVar4 + 1;
        }
        else {
          lVar2 = ((code)FUN_004c1910)(param_1,&uStack_c,4);
          if (lVar2 == 0) {
            (*DAT_0096017c)(lVar1);
            return 0;
          }
          if (0xef < uStack_c >> 0x10) {
            *param_5 = 1;
            (*DAT_0096017c)(lVar1);
            uStack_20 = 0x11d;
            uStack_1c = ((code)FUN_004c1d10)(1);
            ((code)FUN_004c1c50)(&uStack_20);
            return 0;
          }
          puVar6[1] = (char)(uStack_c >> 0x10);
          iVar4 = iVar4 + -1;
          *(short *)(puVar6 + 2) = (short)uStack_c;
          puVar6 = (u8 *)aiStack_b0[iVar4];
        }
      } while (iVar4 != 0);
    }
    if (((*puVar3 & 1) != 0) && (uVar5 = 0, (short)puVar3[7] != 0)) {
      iVar4 = 0;
      do {
        lVar2 = ((code)FUN_004c1910)(param_1,auStack_10,4);
        if (lVar2 == 0) {
          (*DAT_0096017c)(lVar1);
          return 0;
        }
        uVar5 = uVar5 + 1;
        *(short *)(puVar3[9] + iVar4) = (*(u16*)((u8*)&auStack_10 + 0));
        iVar4 = iVar4 + 2;
      } while (uVar5 < (u16)puVar3[7]);
    }
  }
  return lVar1;
}

// FUN_0045F4E0 NONMATCHING

u64 FUN_0045f4e0(u64 param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)((int)param_1 + param_2);
  if (*piVar1 != 0) {
    ((code)FUN_0045edc0)();
    *piVar1 = 0;
  }
  return param_1;
}

// FUN_0045F540 NONMATCHING

int FUN_0045f540(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + param_2) == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = ((code)FUN_0045edd0)();
    iVar1 = iVar1 + 0x10;
  }
  return iVar1;
}

// FUN_0045F580 NONMATCHING

u64 FUN_0045f580(u64 param_1,u64 param_2,int param_3,int param_4)

{
  long lVar1;
  u32 uStack_4;
  
  if (*(int *)(param_3 + param_4) != 0) {
    uStack_4 = ((code)FUN_004ca510)();
    lVar1 = ((code)FUN_004c17f0)(param_1,&uStack_4,4);
    if (lVar1 == 0) {
      param_1 = 0;
    }
    else {
      lVar1 = ((code)FUN_0045ee00)(*(int *)(param_3 + param_4),param_1);
      if (lVar1 == 0) {
        param_1 = 0;
      }
    }
  }
  return param_1;
}

// FUN_0045F600 NONMATCHING

u64 FUN_0045f600(u64 param_1,u64 param_2,char *param_3,int param_4)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  int iStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  piVar3 = (int *)(param_3 + param_4);
  lVar2 = ((code)FUN_004c1910)(param_1,&uStack_4,4);
  if (lVar2 == 0) {
    return 0;
  }
  if (uStack_4 < 0x36001) {
    lVar2 = ((code)FUN_004c1910)(param_1,&uStack_8,4);
    if (lVar2 == 0) {
      return 0;
    }
    if (*param_3 == '\b') {
      iVar1 = *(int *)(param_3 + 0x5c);
      fStack_24 = *(float *)(iVar1 + 4) - *(float *)(iVar1 + 0x10);
      fStack_20 = *(float *)(iVar1 + 8) - *(float *)(iVar1 + 0x10);
      fStack_1c = *(float *)(iVar1 + 0xc) - *(float *)(iVar1 + 0x10);
      fStack_30 = *(float *)(iVar1 + 4) + *(float *)(iVar1 + 0x10);
      fStack_2c = *(float *)(iVar1 + 8) + *(float *)(iVar1 + 0x10);
      fStack_28 = *(float *)(iVar1 + 0xc) + *(float *)(iVar1 + 0x10);
    }
    else {
      fStack_30 = *(float *)(param_3 + 0x60);
      fStack_2c = *(float *)(param_3 + 100);
      fStack_28 = *(float *)(param_3 + 0x68);
      fStack_24 = *(float *)(param_3 + 0x6c);
      fStack_20 = *(float *)(param_3 + 0x70);
      fStack_1c = *(float *)(param_3 + 0x74);
    }
    iStack_c = 0;
    iVar1 = ((code)FUN_0045f140)(param_1,uStack_8,uStack_4 - 1,&fStack_30,&iStack_c);
    *piVar3 = iVar1;
    if (iStack_c != 0) {
      return param_1;
    }
  }
  else {
    lVar2 = ((code)FUN_004c1600)(param_1,0x2c,0,0);
    if (lVar2 == 0) {
      return 0;
    }
    iVar1 = ((code)FUN_0045efe0)(param_1);
    *piVar3 = iVar1;
  }
  if (*piVar3 == 0) {
    param_1 = 0;
  }
  return param_1;
}

// FUN_0045F7D0 NONMATCHING

u8 FUN_0045f7d0(void)

{
  u8 bVar1;
  u8 bVar2;
  long lVar3;
  
  lVar3 = ((code)FUN_004ca520)(4,0x11d,0x45f490,0x45f4c0);
  DAT_007ce720 = (u32)lVar3;
  bVar2 = 0;
  if (0 < lVar3) {
    lVar3 = ((code)FUN_00492c30)(4,0x11d,0x45f7b0,0,0);
    DAT_007ce724 = (u32)lVar3;
    bVar1 = 0;
    if (0 < lVar3) {
      lVar3 = ((code)FUN_00499250)(4,0x11d,0x45f530,0x45f4e0,0);
      DAT_007ce72c = (u32)lVar3;
      bVar1 = 0;
      if (-1 < lVar3) {
        lVar3 = ((code)FUN_00499280)(0x11d,0x45f600,0x45f580,0x45f540);
        bVar1 = -1 < lVar3;
      }
    }
    bVar2 = 0;
    if (bVar1) {
      lVar3 = ((code)FUN_00493c50)(4,0x11d,0x45f530,0x45f4e0,0);
      DAT_007ce728 = (u32)lVar3;
      bVar2 = 0;
      if (-1 < lVar3) {
        lVar3 = ((code)FUN_00493c80)(0x11d,0x45f600,0x45f580,0x45f540);
        bVar2 = -1 < lVar3;
      }
    }
  }
  return bVar2;
}

// FUN_0045F930 NONMATCHING

void FUN_0045f930(int param_1,float *param_2,code *param_3,u32 param_4)

{
  u8 bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  u8 *puVar6;
  u8 bVar7;
  u8 bVar8;
  int *piVar9;
  u8 **ppuVar10;
  long lVar11;
  u8 *pbVar12;
  u16 *puVar13;
  u32 uVar14;
  u32 uVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float unaff_f20;
  float fVar30;
  float fStack_540;
  float fStack_53c;
  float fStack_538;
  float fStack_534;
  float fStack_530;
  float fStack_52c;
  u32 uStack_528;
  float *pfStack_524;
  float *pfStack_520;
  float *pfStack_51c;
  int iStack_510;
  float afStack_50c [12];
  u8 uStack_4dc;
  u8 uStack_4db;
  u16 uStack_4da;
  u8 *puStack_4d4;
  int iStack_4d0;
  int iStack_4cc;
  u8 *apuStack_4c8 [96];
  u8 **ppuStack_348;
  float afStack_340 [12];
  int aiStack_310 [195];
  int *piStack_4;
  
  afStack_340[6] = 0.0;
  afStack_340[0] = *param_2;
  afStack_340[1] = param_2[1];
  afStack_340[2] = param_2[2];
  afStack_340[3] = param_2[3] - *param_2;
  afStack_340[4] = param_2[4] - param_2[1];
  afStack_340[5] = param_2[5] - param_2[2];
  if (afStack_340[3] != 0.0) {
    afStack_340[6] = 1.0 / afStack_340[3];
  }
  afStack_340[7] = 0.0;
  if (afStack_340[4] != 0.0) {
    afStack_340[7] = 1.0 / afStack_340[4];
  }
  afStack_340[8] = 0.0;
  if (afStack_340[5] != 0.0) {
    afStack_340[8] = 1.0 / afStack_340[5];
  }
  fVar20 = param_2[3];
  fVar21 = fVar20;
  if (fVar20 < 0.0) {
    fVar21 = -fVar20;
  }
  fVar16 = *param_2;
  fVar18 = fVar16;
  if (fVar16 < 0.0) {
    fVar18 = -fVar16;
  }
  if (fVar21 <= fVar18) {
    fVar20 = fVar16;
    if (fVar16 < 0.0) {
      fVar20 = -fVar16;
    }
  }
  else if (fVar20 < 0.0) {
    fVar20 = -fVar20;
  }
  fVar21 = param_2[4];
  fVar18 = fVar21;
  if (fVar21 < 0.0) {
    fVar18 = -fVar21;
  }
  fVar17 = param_2[1];
  fVar16 = fVar17;
  if (fVar17 < 0.0) {
    fVar16 = -fVar17;
  }
  if (fVar18 <= fVar16) {
    fVar21 = fVar17;
    if (fVar17 < 0.0) {
      fVar21 = -fVar17;
    }
  }
  else if (fVar21 < 0.0) {
    fVar21 = -fVar21;
  }
  fVar18 = param_2[5];
  fVar16 = fVar18;
  if (fVar18 < 0.0) {
    fVar16 = -fVar18;
  }
  fVar19 = param_2[2];
  fVar17 = fVar19;
  if (fVar19 < 0.0) {
    fVar17 = -fVar19;
  }
  if (fVar16 <= fVar17) {
    fVar18 = fVar19;
    if (fVar19 < 0.0) {
      fVar18 = -fVar19;
    }
  }
  else if (fVar18 < 0.0) {
    fVar18 = -fVar18;
  }
  piStack_4 = aiStack_310 + 3;
  afStack_340[0xb] = fVar18 * 1e-06;
  afStack_340[9] = fVar20 * 1e-06;
  afStack_340[10] = fVar21 * 1e-06;
  aiStack_310[0] = *(int *)(param_1 + 0x1c);
  aiStack_310[2] = 0x3f800000;
  aiStack_310[1] = 0;
  if (aiStack_310 < piStack_4) {
    do {
      piVar2 = piStack_4;
      piStack_4 = piStack_4 + -3;
      piVar2 = (int *)piVar2[-3];
      iVar3 = *piVar2;
      piVar9 = piStack_4;
      while (piStack_4 = piVar9, -1 < iVar3) {
        iVar3 = *piVar2;
        fVar18 = *(float *)((int)afStack_340 + iVar3 + 0xc);
        fVar20 = *(float *)((int)afStack_340 + iVar3 + 0x24);
        fVar21 = (float)piVar9[2] * fVar18 + *(float *)((int)afStack_340 + iVar3) + 0.0;
        fVar16 = (float)piVar2[5] - fVar20;
        fVar20 = (float)piVar2[4] + fVar20;
        fVar17 = (float)piVar9[1] * fVar18 + *(float *)((int)afStack_340 + iVar3) + 0.0;
        if (0.0 < fVar18) {
          if (fVar16 <= fVar21) {
            if (fVar17 <= fVar20) {
              piStack_4 = piVar9 + 3;
              fVar18 = *(float *)((int)afStack_340 + *piVar2 + 0x18);
              piVar9[3] = piVar2[2];
              piVar9[4] = piVar9[1];
              piVar9[5] = piVar9[2];
              if (fVar20 < fVar21) {
                piVar9[5] = (int)(fVar18 * (fVar20 - fVar21) + (float)piVar9[5] + 0.0);
              }
              *piVar9 = piVar2[3];
              if (fVar17 < fVar16) {
                piVar9[1] = (int)(fVar18 * (fVar16 - fVar17) + (float)piVar9[1] + 0.0);
              }
            }
            else {
              *piVar9 = piVar2[3];
            }
          }
          else {
            *piVar9 = piVar2[2];
          }
        }
        else if (fVar21 <= fVar20) {
          if (fVar16 <= fVar17) {
            piStack_4 = piVar9 + 3;
            fVar18 = *(float *)((int)afStack_340 + *piVar2 + 0x18);
            piVar9[3] = piVar2[3];
            piVar9[4] = piVar9[1];
            piVar9[5] = piVar9[2];
            if (fVar21 < fVar16) {
              piVar9[5] = (int)(fVar18 * (fVar16 - fVar21) + (float)piVar9[5] + 0.0);
            }
            *piVar9 = piVar2[2];
            if (fVar20 < fVar17) {
              piVar9[1] = (int)(fVar18 * (fVar20 - fVar17) + (float)piVar9[1] + 0.0);
            }
          }
          else {
            *piVar9 = piVar2[2];
          }
        }
        else {
          *piVar9 = piVar2[3];
        }
        piVar2 = (int *)*piStack_4;
        piVar9 = piStack_4;
        iVar3 = *piVar2;
      }
      iVar3 = *(int *)((int)piVar2 + DAT_007ce72c);
      if (iVar3 != 0) {
        iVar4 = piVar2[1];
        iVar5 = piVar2[2];
        uStack_4db = 0xff;
        uStack_4da = 0;
        if (*(short *)(iVar3 + 0x1e) == 0) {
          uStack_4db = (char)*(u16 *)(iVar3 + 0x1c);
        }
        puStack_4d4 = &uStack_4dc;
        afStack_50c[1] = afStack_340[1];
        afStack_50c[0] = afStack_340[0];
        afStack_50c[2] = afStack_340[2];
        afStack_50c[3] = afStack_340[3];
        afStack_50c[4] = afStack_340[4];
        afStack_50c[5] = afStack_340[5];
        afStack_50c[6] = afStack_340[6];
        afStack_50c[7] = afStack_340[7];
        afStack_50c[8] = afStack_340[8];
        afStack_50c[9] = afStack_340[9];
        afStack_50c[10] = afStack_340[10];
        afStack_50c[0xb] = afStack_340[0xb];
        iStack_4d0 = piVar9[1];
        iStack_4cc = piVar9[2];
        ppuStack_348 = apuStack_4c8;
        iStack_510 = iVar3;
        if (&puStack_4d4 < apuStack_4c8) {
          do {
            ppuVar10 = ppuStack_348;
            ppuStack_348 = ppuStack_348 + -3;
            puVar6 = ppuVar10[-3];
            bVar1 = puVar6[1];
            ppuVar10 = ppuStack_348;
            while (ppuStack_348 = ppuVar10, bVar1 == 0xff) {
              pbVar12 = (u8 *)(*(int *)(iStack_510 + 0x20) + (u32)*(u16 *)(puVar6 + 2) * 0x10)
              ;
              uVar14 = *pbVar12 & 0xc;
              fVar21 = *(float *)((int)afStack_50c + uVar14 + 0x24);
              fVar16 = *(float *)((int)afStack_50c + uVar14 + 0xc);
              fVar17 = *(float *)(pbVar12 + 0xc) - fVar21;
              fVar20 = (float)(int)ppuVar10[2] * fVar16 + *(float *)((int)afStack_50c + uVar14) + 0.0;
              fVar21 = *(float *)(pbVar12 + 4) + fVar21;
              fVar18 = (float)(int)ppuVar10[1] * fVar16 + *(float *)((int)afStack_50c + uVar14) + 0.0;
              if (0.0 < fVar16) {
                if (fVar17 <= fVar20) {
                  if (fVar18 <= fVar21) {
                    ppuStack_348 = ppuVar10 + 3;
                    fVar16 = *(float *)((int)afStack_50c + uVar14 + 0x18);
                    ppuVar10[3] = pbVar12;
                    ppuVar10[4] = ppuVar10[1];
                    ppuVar10[5] = ppuVar10[2];
                    if (fVar21 < fVar20) {
                      ppuVar10[5] = (u8 *)(int)(fVar16 * (fVar21 - fVar20) + (float)(int)ppuVar10[5] + 0.0);
                    }
                    *ppuVar10 = pbVar12 + 8;
                    if (fVar18 < fVar17) {
                      ppuVar10[1] = (u8 *)(int)(fVar16 * (fVar17 - fVar18) + (float)(int)ppuVar10[1] + 0.0);
                    }
                  }
                  else {
                    *ppuVar10 = pbVar12 + 8;
                  }
                }
                else {
                  *ppuVar10 = pbVar12;
                }
              }
              else if (fVar20 <= fVar21) {
                if (fVar17 <= fVar18) {
                  ppuStack_348 = ppuVar10 + 3;
                  fVar16 = *(float *)((int)afStack_50c + uVar14 + 0x18);
                  ppuVar10[3] = pbVar12 + 8;
                  ppuVar10[4] = ppuVar10[1];
                  ppuVar10[5] = ppuVar10[2];
                    if (fVar20 < fVar17) {
                      ppuVar10[5] = (u8 *)(int)(fVar16 * (fVar17 - fVar20) + (float)(int)ppuVar10[5] + 0.0);
                    }
                    *ppuVar10 = pbVar12;
                    if (fVar21 < fVar18) {
                      ppuVar10[1] = (u8 *)(int)(fVar16 * (fVar21 - fVar18) + (float)(int)ppuVar10[1] + 0.0);
                    }
                }
                else {
                  *ppuVar10 = pbVar12;
                }
              }
              else {
                *ppuVar10 = pbVar12 + 8;
              }
              puVar6 = *ppuStack_348;
              ppuVar10 = ppuStack_348;
              bVar1 = puVar6[1];
            }
            uVar14 = (u32)*(u16 *)(*ppuVar10 + 2);
            uVar15 = uVar14 + bVar1;
            for (; uVar14 < uVar15; uVar14 = uVar14 + 1 & 0xffff) {
              uStack_528 = uVar14;
              if (*(int *)(iVar3 + 0x24) != 0) {
                uStack_528 = (u32)*(u16 *)(*(int *)(iVar3 + 0x24) + uVar14 * 2);
              }
              puVar13 = (u16 *)(iVar4 + uStack_528 * 8);
              pfStack_524 = (float *)(iVar5 + (u32)*puVar13 * 0xc);
              pfStack_520 = (float *)(iVar5 + (u32)puVar13[1] * 0xc);
              fVar16 = *pfStack_524;
              fVar20 = pfStack_524[2];
              fVar18 = pfStack_524[1];
              pfStack_51c = (float *)(iVar5 + (u32)puVar13[2] * 0xc);
              fVar28 = *pfStack_520 - fVar16;
              fVar29 = pfStack_520[2] - fVar20;
              fVar23 = *pfStack_51c - fVar16;
              fVar27 = pfStack_520[1] - fVar18;
              fVar25 = pfStack_51c[2] - fVar20;
              fVar26 = pfStack_51c[1] - fVar18;
              fVar19 = afStack_340[4] * fVar25 - afStack_340[5] * fVar26;
              fVar17 = afStack_340[5] * fVar23 - afStack_340[3] * fVar25;
              fVar24 = afStack_340[3] * fVar26 - afStack_340[4] * fVar23;
              fVar21 = fVar29 * fVar24 + fVar28 * fVar19 + fVar27 * fVar17;
              bVar7 = 0;
              if (1e-08 < fVar21) {
                fVar30 = -fVar21 * 1e-05;
                fVar18 = afStack_340[1] - fVar18;
                fVar16 = afStack_340[0] - fVar16;
                fVar20 = afStack_340[2] - fVar20;
                fVar17 = fVar20 * fVar24 + fVar16 * fVar19 + fVar18 * fVar17;
                fVar19 = fVar21 - fVar30;
                bVar8 = 0;
                if ((fVar30 <= fVar17) && (bVar8 = 1, fVar19 < fVar17)) {
                  bVar8 = 0;
                }
                bVar7 = 0;
                if (bVar8) {
                  fVar22 = fVar18 * fVar29 - fVar20 * fVar27;
                  fVar24 = fVar20 * fVar28 - fVar16 * fVar29;
                  fVar18 = fVar16 * fVar27 - fVar18 * fVar28;
                  fVar20 = afStack_340[5] * fVar18 +
                           afStack_340[3] * fVar22 + afStack_340[4] * fVar24;
                  bVar8 = 0;
                  if ((fVar30 <= fVar20) && (bVar8 = 1, fVar19 < fVar17 + fVar20)) {
                    bVar8 = 0;
                  }
                  bVar7 = 0;
                  if (bVar8) {
                    unaff_f20 = fVar25 * fVar18 + fVar23 * fVar22 + fVar26 * fVar24;
                    bVar7 = 0;
                    if ((fVar30 <= unaff_f20) && (bVar7 = 1, fVar19 < unaff_f20)) {
                      bVar7 = 0;
                    }
                    if (bVar7) {
                      unaff_f20 = unaff_f20 / fVar21;
                    }
                  }
                }
              }
              if (bVar7) {
                fStack_534 = *pfStack_524;
                fStack_530 = pfStack_524[1];
                fStack_52c = pfStack_524[2];
                fVar19 = *pfStack_520 - *pfStack_524;
                fVar21 = *pfStack_51c - *pfStack_524;
                fVar17 = pfStack_520[2] - pfStack_524[2];
                fVar16 = pfStack_520[1] - pfStack_524[1];
                fVar20 = pfStack_51c[2] - pfStack_524[2];
                fVar18 = pfStack_51c[1] - pfStack_524[1];
                fStack_540 = fVar16 * fVar20 - fVar17 * fVar18;
                fStack_53c = fVar17 * fVar21 - fVar19 * fVar20;
                fStack_538 = fVar19 * fVar18 - fVar16 * fVar21;
                fVar20 = SQRT(fStack_538 * fStack_538 +
                              fStack_540 * fStack_540 + fStack_53c * fStack_53c);
                if (0.0 < fVar20) {
                  fVar20 = 1.0 / fVar20;
                }
                fStack_540 = fStack_540 * fVar20;
                fStack_53c = fStack_53c * fVar20;
                fStack_538 = fStack_538 * fVar20;
                lVar11 = (*param_3)(unaff_f20,param_2,piVar2,&fStack_540,param_4);
                if (lVar11 == 0) {
                  return;
                }
              }
            }
          } while (&puStack_4d4 < ppuStack_348);
        }
      }
    } while (aiStack_310 < piStack_4);
  }
  return;
}

// FUN_004606B0 NONMATCHING

void FUN_004606b0(int param_1,u64 param_2,code *param_3,u32 param_4)

{
  char cVar1;
  u16 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  u8 *puVar7;
  u8 **ppuVar8;
  u16 *puVar9;
  float *pfVar10;
  long lVar11;
  u16 uVar12;
  float *pfVar13;
  u32 uVar14;
  u32 uVar15;
  u8 *pbVar16;
  int iVar17;
  u32 uVar18;
  u32 uVar19;
  u32 uVar20;
  int iVar21;
  float *pfVar22;
  float *pfVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  u8 *puStack_2c0;
  float fStack_2a0;
  float fStack_29c;
  float fStack_298;
  float fStack_294;
  float fStack_290;
  float fStack_28c;
  u32 uStack_288;
  float *pfStack_284;
  float *pfStack_280;
  float *pfStack_27c;
  int iStack_270;
  float afStack_26c [12];
  u8 uStack_23c;
  u8 uStack_23b;
  u16 uStack_23a;
  u8 *puStack_234;
  u32 uStack_230;
  u8 *apuStack_22c [64];
  u8 **ppuStack_12c;
  float afStack_120 [6];
  int iStack_108;
  int aiStack_104 [64];
  int *piStack_4;
  
  pfVar13 = (float *)param_2;
  piStack_4 = aiStack_104;
  afStack_120[0] = *pfVar13;
  afStack_120[1] = pfVar13[1];
  afStack_120[2] = pfVar13[2];
  afStack_120[3] = pfVar13[3];
  afStack_120[4] = pfVar13[4];
  afStack_120[5] = pfVar13[5];
  iStack_108 = *(int *)(param_1 + 0x1c);
  if (&iStack_108 < piStack_4) {
    do {
      piVar3 = piStack_4;
      piStack_4 = piStack_4 + -1;
      piVar3 = (int *)piVar3[-1];
      iVar4 = *piVar3;
      while (-1 < iVar4) {
        if (*(float *)((int)afStack_120 + *piVar3) < (float)piVar3[5]) {
          *piStack_4 = piVar3[2];
        }
        else {
          *piStack_4 = piVar3[3];
          if (*(float *)((int)afStack_120 + *piVar3 + 0xc) <= (float)piVar3[4]) {
            piStack_4 = piStack_4 + 1;
            *piStack_4 = piVar3[2];
          }
        }
        piVar3 = (int *)*piStack_4;
        iVar4 = *piVar3;
      }
      iVar4 = *(int *)((int)piVar3 + DAT_007ce72c);
      if (iVar4 != 0) {
        iVar5 = piVar3[1];
        iVar6 = piVar3[2];
        if ((((*pfVar13 < *(float *)(iVar4 + 0x10)) || (pfVar13[1] < *(float *)(iVar4 + 0x14))) ||
            (pfVar13[2] < *(float *)(iVar4 + 0x18))) ||
           (((*(float *)(iVar4 + 4) < pfVar13[3] || (*(float *)(iVar4 + 8) < pfVar13[4])) ||
            (*(float *)(iVar4 + 0xc) < pfVar13[5])))) {
          ppuStack_12c = &puStack_234;
        }
        else {
          uStack_23b = 0xff;
          uStack_23a = 0;
          if (*(short *)(iVar4 + 0x1e) == 0) {
            uStack_23b = (char)*(u16 *)(iVar4 + 0x1c);
          }
          afStack_26c[0] = *pfVar13;
          afStack_26c[1] = pfVar13[1];
          afStack_26c[2] = pfVar13[2];
          afStack_26c[3] = pfVar13[3];
          afStack_26c[4] = pfVar13[4];
          afStack_26c[5] = pfVar13[5];
          afStack_26c[6] = *pfVar13;
          afStack_26c[7] = pfVar13[1];
          afStack_26c[8] = pfVar13[2];
          afStack_26c[9] = pfVar13[3];
          afStack_26c[10] = pfVar13[4];
          puStack_234 = &uStack_23c;
          afStack_26c[0xb] = pfVar13[5];
          if (*(float *)(iVar4 + 0x14) < pfVar13[4]) {
            uVar15 = 4;
          }
          else {
            uVar15 = 0;
          }
          if (*(float *)(iVar4 + 0x18) < pfVar13[5]) {
            uVar20 = 0x10;
          }
          else {
            uVar20 = 0;
          }
          if (*pfVar13 < *(float *)(iVar4 + 4)) {
            uVar19 = 2;
          }
          else {
            uVar19 = 0;
          }
          if (pfVar13[1] < *(float *)(iVar4 + 8)) {
            uVar18 = 8;
          }
          else {
            uVar18 = 0;
          }
          if (pfVar13[2] < *(float *)(iVar4 + 0xc)) {
            uVar14 = 0x20;
          }
          else {
            uVar14 = 0;
          }
          ppuStack_12c = apuStack_22c;
          uStack_230 = uVar14 | uVar18 | uVar19 | uVar20 | *(float *)(iVar4 + 0x10) < pfVar13[3] |
                                                           uVar15;
          iStack_270 = iVar4;
        }
        if (&puStack_234 < ppuStack_12c) {
          do {
            ppuStack_12c = ppuStack_12c + -2;
LAB_00460a2c:
            ppuVar8 = ppuStack_12c;
            puVar7 = *ppuStack_12c;
            uVar12 = (u16)(u8)puVar7[1];
            if (uVar12 == 0xff) {
              if (ppuStack_12c[1] != (u8 *)0x0) goto code_r0x00460a60;
              iVar17 = *(int *)(iStack_270 + 0x20) + (u32)*(u16 *)(puVar7 + 2) * 0x10;
              cVar1 = *(char *)(iVar17 + 1);
              iVar21 = iVar17;
              while (cVar1 == -1) {
                iVar21 = *(int *)(iStack_270 + 0x20) + (u32)*(u16 *)(iVar21 + 2) * 0x10;
                cVar1 = *(char *)(iVar21 + 1);
              }
              uVar12 = (u16)*(u8 *)(iVar17 + 9);
              iVar17 = iVar17 + 8;
              if (uVar12 == 0xff) {
                do {
                  iVar17 = *(int *)(iStack_270 + 0x20) + (u32)*(u16 *)(iVar17 + 2) * 0x10;
                  uVar12 = (u16)*(u8 *)(iVar17 + 9);
                  iVar17 = iVar17 + 8;
                } while (uVar12 == 0xff);
              }
              uVar2 = *(u16 *)(iVar21 + 2);
              puStack_2c0 = (u8 *)0x0;
              uVar12 = (*(short *)(iVar17 + 2) + uVar12) - uVar2;
            }
            else {
              puStack_2c0 = ppuStack_12c[1];
              uVar2 = *(u16 *)(puVar7 + 2);
            }
            for (uVar15 = (u32)uVar2; uVar15 < (u32)uVar2 + (u32)uVar12;
                uVar15 = uVar15 + 1 & 0xffff) {
              uVar20 = uVar15;
              if (*(int *)(iVar4 + 0x24) != 0) {
                uVar20 = (u32)*(u16 *)(*(int *)(iVar4 + 0x24) + uVar15 * 2);
              }
              puVar9 = (u16 *)(iVar5 + uVar20 * 8);
              pfVar22 = (float *)(iVar6 + (u32)*puVar9 * 0xc);
              pfVar23 = (float *)(iVar6 + (u32)puVar9[1] * 0xc);
              pfVar10 = (float *)(iVar6 + (u32)puVar9[2] * 0xc);
              if (puStack_2c0 == (u8 *)0x0) {
                fStack_294 = *pfVar22;
LAB_00460be8:
                fStack_290 = pfVar22[1];
                fStack_28c = pfVar22[2];
                fVar29 = *pfVar23 - *pfVar22;
                fVar25 = *pfVar10 - *pfVar22;
                fVar28 = pfVar23[2] - pfVar22[2];
                fVar27 = pfVar23[1] - pfVar22[1];
                fVar24 = pfVar10[2] - pfVar22[2];
                fVar26 = pfVar10[1] - pfVar22[1];
                fStack_2a0 = fVar27 * fVar24 - fVar28 * fVar26;
                fStack_29c = fVar28 * fVar25 - fVar29 * fVar24;
                fStack_298 = fVar29 * fVar26 - fVar27 * fVar25;
                fVar24 = SQRT(fStack_298 * fStack_298 +
                              fStack_2a0 * fStack_2a0 + fStack_29c * fStack_29c);
                if (0.0 < fVar24) {
                  fVar24 = 1.0 / fVar24;
                }
                fStack_2a0 = fStack_2a0 * fVar24;
                fStack_29c = fStack_29c * fVar24;
                fStack_298 = fStack_298 * fVar24;
                uStack_288 = uVar20;
                pfStack_284 = pfVar22;
                pfStack_280 = pfVar23;
                pfStack_27c = pfVar10;
                lVar11 = (*param_3)(0,param_2,piVar3,&fStack_2a0,param_4);
                if (lVar11 == 0) {
                  return;
                }
              }
              else {
                lVar11 = ((code)FUN_004bb5d0)(param_2,pfVar22,pfVar23,pfVar10);
                if (lVar11 != 0) {
                  fStack_294 = *pfVar22;
                  goto LAB_00460be8;
                }
              }
            }
          } while (&puStack_234 < ppuStack_12c);
        }
      }
    } while (&iStack_108 < piStack_4);
  }
  return;
code_r0x00460a60:
  pbVar16 = (u8 *)(*(int *)(iStack_270 + 0x20) + (u32)*(u16 *)(puVar7 + 2) * 0x10);
  uVar15 = *pbVar16 & 0xc;
  if (*(float *)((int)afStack_26c + uVar15) < *(float *)(pbVar16 + 0xc)) {
    *ppuStack_12c = pbVar16;
  }
  else {
    *ppuStack_12c = pbVar16 + 8;
    if (*(float *)((int)afStack_26c + uVar15 + 0xc) <= *(float *)(pbVar16 + 4)) {
      ppuStack_12c = ppuStack_12c + 2;
      ppuVar8[2] = pbVar16;
      ppuVar8[3] = ppuVar8[1];
      if (*(float *)(pbVar16 + 4) <= *(float *)((int)afStack_26c + uVar15 + 0x18)) {
        ppuVar8[3] = (u8 *)((u32)ppuVar8[3] & ~(2 << (uVar15 >> 1)));
      }
      if (*(float *)((int)afStack_26c + uVar15 + 0x24) <= *(float *)(pbVar16 + 0xc)) {
        ppuVar8[1] = (u8 *)((u32)ppuVar8[1] & ~(1 << (uVar15 >> 1)));
      }
    }
  }
  goto LAB_00460a2c;
}

// FUN_00460EC0 NONMATCHING

void FUN_00460ec0(int param_1,u64 param_2,u32 param_3,code *param_4,u32 param_5
                 )

{
  char cVar1;
  u16 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  u8 *puVar7;
  u8 **ppuVar8;
  u16 *puVar9;
  float *pfVar10;
  long lVar11;
  u16 uVar12;
  float *pfVar13;
  u32 uVar14;
  u32 uVar15;
  u8 *pbVar16;
  int iVar17;
  u32 uVar18;
  u32 uVar19;
  u32 uVar20;
  int iVar21;
  float *pfVar22;
  float *pfVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  float fVar41;
  u8 *puStack_300;
  float fStack_2e0;
  float fStack_2dc;
  float fStack_2d8;
  float fStack_2d4;
  float fStack_2d0;
  float fStack_2cc;
  u32 uStack_2c8;
  float *pfStack_2c4;
  float *pfStack_2c0;
  float *pfStack_2bc;
  int iStack_2b0;
  float afStack_2ac [12];
  u8 uStack_27c;
  u8 uStack_27b;
  u16 uStack_27a;
  u8 *puStack_274;
  u32 uStack_270;
  u8 *apuStack_26c [64];
  u8 **ppuStack_16c;
  float afStack_160 [6];
  int iStack_148;
  int aiStack_144 [64];
  int *piStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_4;
  
  pfVar13 = (float *)param_2;
  fVar24 = pfVar13[1];
  fVar27 = pfVar13[2];
  fVar31 = pfVar13[3];
  fVar28 = *pfVar13;
  piStack_44 = aiStack_144;
  fVar33 = fVar31 * 0.57;
  fVar38 = fVar28 - fVar31;
  fVar39 = fVar24 - fVar31;
  fVar36 = fVar28 - fVar33;
  afStack_160[3] = fVar38;
  fVar35 = fVar27 - fVar33;
  fStack_20 = fVar28 + fVar31;
  fVar37 = fVar27 - fVar31;
  afStack_160[0] = fVar28 + fVar31;
  afStack_160[4] = fVar39;
  afStack_160[5] = fVar37;
  fStack_14 = fVar38;
  fStack_10 = fVar39;
  fVar41 = fVar27 + fVar31;
  fVar40 = fVar24 + fVar31;
  fStack_40 = fVar28 + fVar33;
  afStack_160[1] = fVar40;
  afStack_160[2] = fVar41;
  fStack_c = fVar37;
  fVar28 = fVar24 - fVar33;
  fVar24 = fVar24 + fVar33;
  iStack_148 = *(int *)(param_1 + 0x1c);
  fVar27 = fVar27 + fVar33;
  fStack_34 = fVar36;
  fStack_1c = fVar40;
  fStack_18 = fVar41;
  fStack_30 = fVar28;
  fStack_2c = fVar35;
  fStack_3c = fVar24;
  fStack_38 = fVar27;
  if (&iStack_148 < piStack_44) {
    do {
      piVar3 = piStack_44;
      piStack_44 = piStack_44 + -1;
      piVar3 = (int *)piVar3[-1];
      iVar4 = *piVar3;
      while (-1 < iVar4) {
        if (*(float *)((int)afStack_160 + *piVar3) < (float)piVar3[5]) {
          *piStack_44 = piVar3[2];
        }
        else {
          *piStack_44 = piVar3[3];
          if (*(float *)((int)afStack_160 + *piVar3 + 0xc) <= (float)piVar3[4]) {
            piStack_44 = piStack_44 + 1;
            *piStack_44 = piVar3[2];
          }
        }
        piVar3 = (int *)*piStack_44;
        iVar4 = *piVar3;
      }
      iVar4 = *(int *)((int)piVar3 + iGpffffba3c);
      if (iVar4 != 0) {
        fVar34 = *(float *)(iVar4 + 0x10);
        fVar33 = *pfVar13;
        if (fVar33 < fVar34) {
          fVar33 = fVar34 - fVar33;
        }
        else if (*(float *)(iVar4 + 4) < fVar33) {
          fVar33 = fVar33 - *(float *)(iVar4 + 4);
        }
        else {
          fVar33 = 0.0;
        }
        fVar29 = *(float *)(iVar4 + 0x14);
        fVar25 = pfVar13[1];
        if (fVar25 < fVar29) {
          fVar25 = fVar29 - fVar25;
        }
        else if (*(float *)(iVar4 + 8) < fVar25) {
          fVar25 = fVar25 - *(float *)(iVar4 + 8);
        }
        else {
          fVar25 = 0.0;
        }
        fVar30 = *(float *)(iVar4 + 0x18);
        fVar26 = pfVar13[2];
        fVar32 = 0.0;
        if (fVar26 < fVar30) {
          fVar32 = fVar30 - fVar26;
        }
        else if (*(float *)(iVar4 + 0xc) < fVar26) {
          fVar32 = fVar26 - *(float *)(iVar4 + 0xc);
        }
        if (fVar32 * fVar32 + fVar25 * fVar25 + fVar33 * fVar33 + 0.0 + 0.0 <=
            pfVar13[3] * pfVar13[3]) {
          iVar5 = piVar3[1];
          iVar6 = piVar3[2];
          if ((((fStack_20 < fVar34) || (fVar40 < fVar29)) || (fVar41 < fVar30)) ||
             (((*(float *)(iVar4 + 4) < fVar38 || (*(float *)(iVar4 + 8) < fVar39)) ||
              (*(float *)(iVar4 + 0xc) < fVar37)))) {
            ppuStack_16c = &puStack_274;
          }
          else {
            uStack_27b = 0xff;
            uStack_27a = 0;
            if (*(short *)(iVar4 + 0x1e) == 0) {
              uStack_27b = (char)*(u16 *)(iVar4 + 0x1c);
            }
            afStack_2ac[1] = fVar40;
            puStack_274 = &uStack_27c;
            afStack_2ac[2] = fVar41;
            afStack_2ac[3] = fVar38;
            afStack_2ac[4] = fVar39;
            afStack_2ac[5] = fVar37;
            afStack_2ac[7] = fVar24;
            afStack_2ac[8] = fVar27;
            afStack_2ac[0] = fStack_20;
            afStack_2ac[6] = fStack_40;
            afStack_2ac[9] = fVar36;
            afStack_2ac[10] = fVar28;
            afStack_2ac[0xb] = fVar35;
            if (*(float *)(iVar4 + 0x14) < fVar28) {
              uVar15 = 4;
            }
            else {
              uVar15 = 0;
            }
            if (*(float *)(iVar4 + 0x18) < fVar35) {
              uVar20 = 0x10;
            }
            else {
              uVar20 = 0;
            }
            if (fStack_40 < *(float *)(iVar4 + 4)) {
              uVar19 = 2;
            }
            else {
              uVar19 = 0;
            }
            if (fVar24 < *(float *)(iVar4 + 8)) {
              uVar18 = 8;
            }
            else {
              uVar18 = 0;
            }
            if (fVar27 < *(float *)(iVar4 + 0xc)) {
              uVar14 = 0x20;
            }
            else {
              uVar14 = 0;
            }
            ppuStack_16c = apuStack_26c;
            uStack_270 = uVar14 | uVar18 | uVar19 | uVar20 | *(float *)(iVar4 + 0x10) < fVar36 |
                                                             uVar15;
            iStack_2b0 = iVar4;
          }
          if (&puStack_274 < ppuStack_16c) {
            do {
              ppuStack_16c = ppuStack_16c + -2;
LAB_004613e8:
              ppuVar8 = ppuStack_16c;
              puVar7 = *ppuStack_16c;
              uVar12 = (u16)(u8)puVar7[1];
              if (uVar12 == 0xff) {
                if (ppuStack_16c[1] != (u8 *)0x0) goto code_r0x0046141c;
                iVar17 = *(int *)(iStack_2b0 + 0x20) + (u32)*(u16 *)(puVar7 + 2) * 0x10;
                cVar1 = *(char *)(iVar17 + 1);
                iVar21 = iVar17;
                while (cVar1 == -1) {
                  iVar21 = *(int *)(iStack_2b0 + 0x20) + (u32)*(u16 *)(iVar21 + 2) * 0x10;
                  cVar1 = *(char *)(iVar21 + 1);
                }
                uVar12 = (u16)*(u8 *)(iVar17 + 9);
                iVar17 = iVar17 + 8;
                if (uVar12 == 0xff) {
                  do {
                    iVar17 = *(int *)(iStack_2b0 + 0x20) + (u32)*(u16 *)(iVar17 + 2) * 0x10;
                    uVar12 = (u16)*(u8 *)(iVar17 + 9);
                    iVar17 = iVar17 + 8;
                  } while (uVar12 == 0xff);
                }
                uVar2 = *(u16 *)(iVar21 + 2);
                puStack_300 = (u8 *)0x0;
                uVar12 = (*(short *)(iVar17 + 2) + uVar12) - uVar2;
              }
              else {
                puStack_300 = ppuStack_16c[1];
                uVar2 = *(u16 *)(puVar7 + 2);
              }
              for (uVar15 = (u32)uVar2; uVar15 < (u32)uVar2 + (u32)uVar12;
                  uVar15 = uVar15 + 1 & 0xffff) {
                uVar20 = uVar15;
                if (*(int *)(iVar4 + 0x24) != 0) {
                  uVar20 = (u32)*(u16 *)(*(int *)(iVar4 + 0x24) + uVar15 * 2);
                }
                puVar9 = (u16 *)(iVar5 + uVar20 * 8);
                pfVar22 = (float *)(iVar6 + (u32)*puVar9 * 0xc);
                pfVar23 = (float *)(iVar6 + (u32)puVar9[1] * 0xc);
                pfVar10 = (float *)(iVar6 + (u32)puVar9[2] * 0xc);
                if (puStack_300 == (u8 *)0x0) {
                  fVar30 = *pfVar23 - *pfVar22;
                  fVar29 = pfVar23[1] - pfVar22[1];
                  fVar34 = *pfVar10 - *pfVar22;
                  fVar26 = pfVar23[2] - pfVar22[2];
                  fVar33 = pfVar10[2] - pfVar22[2];
                  fVar25 = pfVar10[1] - pfVar22[1];
                  fStack_2e0 = fVar29 * fVar33 - fVar26 * fVar25;
                  fStack_2dc = fVar26 * fVar34 - fVar30 * fVar33;
                  fStack_2d8 = fVar30 * fVar25 - fVar29 * fVar34;
                  fVar33 = SQRT(fStack_2d8 * fStack_2d8 +
                                fStack_2e0 * fStack_2e0 + fStack_2dc * fStack_2dc);
                  if (0.0 < fVar33) {
                    fVar33 = 1.0 / fVar33;
                  }
                  fStack_2e0 = fStack_2e0 * fVar33;
                  fStack_2dc = fStack_2dc * fVar33;
                  fStack_2d8 = fStack_2d8 * fVar33;
                  fStack_4 = (pfVar13[2] - pfVar22[2]) * fStack_2d8 +
                             (*pfVar13 - *pfVar22) * fStack_2e0 +
                             (pfVar13[1] - pfVar22[1]) * fStack_2dc;
LAB_004616d0:
                  fStack_4 = fStack_4 * (1.0 / fVar31);
                  fStack_2d4 = *pfVar22;
                  fStack_2d0 = pfVar22[1];
                  fStack_2cc = pfVar22[2];
                  uStack_2c8 = uVar20;
                  pfStack_2c4 = pfVar22;
                  pfStack_2c0 = pfVar23;
                  pfStack_2bc = pfVar10;
                  lVar11 = (*param_4)(fStack_4,param_3,piVar3,&fStack_2e0,param_5);
                  if (lVar11 == 0) {
                    return;
                  }
                }
                else {
                  lVar11 = ((code)FUN_004bae00)(param_2,pfVar22,pfVar23,pfVar10,&fStack_2e0,&fStack_4);
                  if (lVar11 != 0) goto LAB_004616d0;
                }
              }
            } while (&puStack_274 < ppuStack_16c);
          }
        }
      }
    } while (&iStack_148 < piStack_44);
  }
  return;
code_r0x0046141c:
  pbVar16 = (u8 *)(*(int *)(iStack_2b0 + 0x20) + (u32)*(u16 *)(puVar7 + 2) * 0x10);
  uVar15 = *pbVar16 & 0xc;
  if (*(float *)((int)afStack_2ac + uVar15) < *(float *)(pbVar16 + 0xc)) {
    *ppuStack_16c = pbVar16;
  }
  else {
    *ppuStack_16c = pbVar16 + 8;
    if (*(float *)((int)afStack_2ac + uVar15 + 0xc) <= *(float *)(pbVar16 + 4)) {
      ppuStack_16c = ppuStack_16c + 2;
      ppuVar8[2] = pbVar16;
      ppuVar8[3] = ppuVar8[1];
      if (*(float *)(pbVar16 + 4) <= *(float *)((int)afStack_2ac + uVar15 + 0x18)) {
        ppuVar8[3] = (u8 *)((u32)ppuVar8[3] & ~(2 << (uVar15 >> 1)));
      }
      if (*(float *)((int)afStack_2ac + uVar15 + 0x24) <= *(float *)(pbVar16 + 0xc)) {
        ppuVar8[1] = (u8 *)((u32)ppuVar8[1] & ~(1 << (uVar15 >> 1)));
      }
    }
  }
  goto LAB_004613e8;
}

// FUN_00461900 NONMATCHING

void FUN_00461900(int param_1,float *param_2,u64 param_3,code *param_4,u32 param_5)

{
  int iVar1;
  u8 bVar2;
  u8 bVar3;
  long lVar4;
  int iVar5;
  u16 *puVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float in_f23;
  float fVar24;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  int iStack_18;
  float *pfStack_14;
  float *pfStack_10;
  float *pfStack_c;
  
  iVar5 = 0;
  puVar6 = *(u16 **)(param_1 + 0x2c);
  iVar1 = *(int *)(*(int *)(param_1 + 0x5c) + 0x14);
  fVar23 = param_2[3] - *param_2;
  fVar22 = param_2[4] - param_2[1];
  fVar24 = param_2[5] - param_2[2];
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      pfStack_14 = (float *)(iVar1 + (u32)*puVar6 * 0xc);
      pfStack_10 = (float *)(iVar1 + (u32)puVar6[1] * 0xc);
      pfStack_c = (float *)(iVar1 + (u32)puVar6[2] * 0xc);
      fVar10 = *pfStack_14;
      fVar9 = pfStack_14[2];
      fVar11 = pfStack_14[1];
      fVar14 = *pfStack_c - fVar10;
      fVar20 = pfStack_10[2] - fVar9;
      fVar18 = pfStack_10[1] - fVar11;
      fVar16 = pfStack_c[2] - fVar9;
      fVar17 = pfStack_c[1] - fVar11;
      fVar13 = fVar22 * fVar16 - fVar24 * fVar17;
      fVar12 = fVar24 * fVar14 - fVar23 * fVar16;
      fVar15 = fVar23 * fVar17 - fVar22 * fVar14;
      fVar19 = *pfStack_10 - fVar10;
      fVar7 = fVar20 * fVar15 + fVar19 * fVar13 + fVar18 * fVar12;
      bVar2 = 0;
      if (1e-08 < fVar7) {
        fVar21 = -fVar7 * 1e-05;
        fVar11 = param_2[1] - fVar11;
        fVar10 = *param_2 - fVar10;
        fVar9 = param_2[2] - fVar9;
        fVar12 = fVar9 * fVar15 + fVar10 * fVar13 + fVar11 * fVar12;
        fVar13 = fVar7 - fVar21;
        bVar3 = 0;
        if ((fVar21 <= fVar12) && (bVar3 = 1, fVar13 < fVar12)) {
          bVar3 = 0;
        }
        bVar2 = 0;
        if (bVar3) {
          fVar8 = fVar11 * fVar20 - fVar9 * fVar18;
          fVar15 = fVar9 * fVar19 - fVar10 * fVar20;
          fVar10 = fVar10 * fVar18 - fVar11 * fVar19;
          fVar9 = fVar24 * fVar10 + fVar23 * fVar8 + fVar22 * fVar15;
          bVar3 = 0;
          if ((fVar21 <= fVar9) && (bVar3 = 1, fVar13 < fVar12 + fVar9)) {
            bVar3 = 0;
          }
          bVar2 = 0;
          if (bVar3) {
            in_f23 = fVar16 * fVar10 + fVar14 * fVar8 + fVar17 * fVar15;
            bVar2 = 0;
            if ((fVar21 <= in_f23) && (bVar2 = 1, fVar13 < in_f23)) {
              bVar2 = 0;
            }
            if (bVar2) {
              in_f23 = in_f23 / fVar7;
            }
          }
        }
      }
      if (bVar2) {
        fStack_24 = *pfStack_14;
        fStack_20 = pfStack_14[1];
        fStack_1c = pfStack_14[2];
        fVar13 = *pfStack_10 - *pfStack_14;
        fVar7 = *pfStack_c - *pfStack_14;
        fVar12 = pfStack_10[2] - pfStack_14[2];
        fVar11 = pfStack_10[1] - pfStack_14[1];
        fVar9 = pfStack_c[2] - pfStack_14[2];
        fVar10 = pfStack_c[1] - pfStack_14[1];
        fStack_30 = fVar11 * fVar9 - fVar12 * fVar10;
        fStack_2c = fVar12 * fVar7 - fVar13 * fVar9;
        fStack_28 = fVar13 * fVar10 - fVar11 * fVar7;
        fVar9 = SQRT(fStack_28 * fStack_28 + fStack_30 * fStack_30 + fStack_2c * fStack_2c);
        if (0.0 < fVar9) {
          fVar9 = 1.0 / fVar9;
        }
        fStack_30 = fStack_30 * fVar9;
        fStack_2c = fStack_2c * fVar9;
        fStack_28 = fStack_28 * fVar9;
        iStack_18 = iVar5;
        lVar4 = (*param_4)(in_f23,param_3,&fStack_30,param_5);
        if (lVar4 == 0) {
          return;
        }
      }
      iVar5 = iVar5 + 1;
      puVar6 = puVar6 + 4;
    } while (iVar5 < *(int *)(param_1 + 0x10));
  }
  return;
}

// FUN_00461D00 NONMATCHING

void FUN_00461d00(int param_1,u64 param_2,u32 param_3,code *param_4,u32 param_5
                 )

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  u32 *puVar5;
  int iVar6;
  u16 *puVar7;
  float fVar8;
  u8 auStack_30 [12];
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  int iStack_18;
  u32 *puStack_14;
  int iStack_10;
  int iStack_c;
  float fStack_4;
  
  fVar8 = *(float *)((int)param_2 + 0xc);
  iVar6 = 0;
  puVar7 = *(u16 **)(param_1 + 0x2c);
  iVar1 = *(int *)(*(int *)(param_1 + 0x5c) + 0x14);
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      iVar4 = iVar1 + (u32)puVar7[1] * 0xc;
      puVar5 = (u32 *)(iVar1 + (u32)*puVar7 * 0xc);
      iVar3 = iVar1 + (u32)puVar7[2] * 0xc;
      lVar2 = ((code)FUN_004bae00)(param_2,puVar5,iVar4,iVar3,auStack_30,&fStack_4);
      if (lVar2 != 0) {
        fStack_4 = fStack_4 * (1.0 / fVar8);
        uStack_24 = *puVar5;
        uStack_20 = puVar5[1];
        uStack_1c = puVar5[2];
        iStack_18 = iVar6;
        puStack_14 = puVar5;
        iStack_10 = iVar4;
        iStack_c = iVar3;
        lVar2 = (*param_4)(fStack_4,param_3,auStack_30,param_5);
        if (lVar2 == 0) {
          return;
        }
      }
      iVar6 = iVar6 + 1;
      puVar7 = puVar7 + 4;
    } while (iVar6 < *(int *)(param_1 + 0x10));
  }
  return;
}

// FUN_00461EA0 NONMATCHING

void FUN_00461ea0(int param_1,float *param_2,u32 param_3,code *param_4,u32 param_5)

{
  u8 bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  u8 *puVar5;
  u8 bVar6;
  u8 bVar7;
  u8 **ppuVar8;
  long lVar9;
  u8 *pbVar10;
  u16 *puVar11;
  u32 uVar12;
  u32 uVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float in_f23;
  float fVar31;
  float fStack_200;
  float fStack_1fc;
  float fStack_1f8;
  float fStack_1f4;
  float fStack_1f0;
  float fStack_1ec;
  u32 uStack_1e8;
  float *pfStack_1e4;
  float *pfStack_1e0;
  float *pfStack_1dc;
  int iStack_1d0;
  float afStack_1cc [12];
  u8 uStack_19c;
  u8 uStack_19b;
  u16 uStack_19a;
  u8 *puStack_194;
  float fStack_190;
  float fStack_18c;
  u8 *apuStack_188 [96];
  u8 **ppuStack_8;
  
  iVar2 = *(int *)(param_1 + iGpffffba38);
  if (iVar2 == 0) {
    ((code)FUN_00461900)();
  }
  else {
    iVar3 = *(int *)(param_1 + 0x2c);
    iVar4 = *(int *)(*(int *)(param_1 + 0x5c) + 0x14);
    fVar30 = param_2[3] - *param_2;
    fVar29 = param_2[4] - param_2[1];
    uStack_19b = 0xff;
    uStack_19a = 0;
    fVar31 = param_2[5] - param_2[2];
    if (*(short *)(iVar2 + 0x1e) == 0) {
      uStack_19b = (char)*(u16 *)(iVar2 + 0x1c);
    }
    afStack_1cc[0] = *param_2;
    afStack_1cc[1] = param_2[1];
    afStack_1cc[2] = param_2[2];
    afStack_1cc[6] = 0.0;
    afStack_1cc[3] = param_2[3] - *param_2;
    afStack_1cc[4] = param_2[4] - param_2[1];
    afStack_1cc[5] = param_2[5] - param_2[2];
    if (afStack_1cc[3] != 0.0) {
      afStack_1cc[6] = 1.0 / afStack_1cc[3];
    }
    afStack_1cc[7] = 0.0;
    if (afStack_1cc[4] != 0.0) {
      afStack_1cc[7] = 1.0 / afStack_1cc[4];
    }
    afStack_1cc[8] = 0.0;
    if (afStack_1cc[5] != 0.0) {
      afStack_1cc[8] = 1.0 / afStack_1cc[5];
    }
    afStack_1cc[9] = param_2[3];
    fVar15 = afStack_1cc[9];
    if (afStack_1cc[9] < 0.0) {
      fVar15 = -afStack_1cc[9];
    }
    fVar14 = *param_2;
    fVar16 = fVar14;
    if (fVar14 < 0.0) {
      fVar16 = -fVar14;
    }
    if (fVar15 <= fVar16) {
      afStack_1cc[9] = fVar14;
      if (fVar14 < 0.0) {
        afStack_1cc[9] = -fVar14;
      }
    }
    else if (afStack_1cc[9] < 0.0) {
      afStack_1cc[9] = -afStack_1cc[9];
    }
    afStack_1cc[10] = param_2[4];
    fVar15 = afStack_1cc[10];
    if (afStack_1cc[10] < 0.0) {
      fVar15 = -afStack_1cc[10];
    }
    fVar14 = param_2[1];
    fVar16 = fVar14;
    if (fVar14 < 0.0) {
      fVar16 = -fVar14;
    }
    if (fVar15 <= fVar16) {
      afStack_1cc[10] = fVar14;
      if (fVar14 < 0.0) {
        afStack_1cc[10] = -fVar14;
      }
    }
    else if (afStack_1cc[10] < 0.0) {
      afStack_1cc[10] = -afStack_1cc[10];
    }
    afStack_1cc[0xb] = param_2[5];
    fVar15 = afStack_1cc[0xb];
    if (afStack_1cc[0xb] < 0.0) {
      fVar15 = -afStack_1cc[0xb];
    }
    fVar14 = param_2[2];
    fVar16 = fVar14;
    if (fVar14 < 0.0) {
      fVar16 = -fVar14;
    }
    if (fVar15 <= fVar16) {
      afStack_1cc[0xb] = fVar14;
      if (fVar14 < 0.0) {
        afStack_1cc[0xb] = -fVar14;
      }
    }
    else if (afStack_1cc[0xb] < 0.0) {
      afStack_1cc[0xb] = -afStack_1cc[0xb];
    }
    afStack_1cc[0xb] = afStack_1cc[0xb] * 1e-06;
    puStack_194 = &uStack_19c;
    fStack_18c = 1.0;
    ppuStack_8 = apuStack_188;
    fStack_190 = 0.0;
    afStack_1cc[9] = afStack_1cc[9] * 1e-06;
    afStack_1cc[10] = afStack_1cc[10] * 1e-06;
    fVar19 = *(float *)(iVar2 + 0x14) - afStack_1cc[10];
    fVar20 = *(float *)(iVar2 + 8) + afStack_1cc[10];
    fVar18 = *(float *)(iVar2 + 0x10) - afStack_1cc[9];
    fVar16 = *(float *)(iVar2 + 0x18) - afStack_1cc[0xb];
    fVar14 = *(float *)(iVar2 + 4) + afStack_1cc[9];
    fVar15 = *(float *)(iVar2 + 0xc) + afStack_1cc[0xb];
    if (afStack_1cc[6] == 0.0) {
      bVar6 = 0;
      if ((fVar18 <= afStack_1cc[0]) && (afStack_1cc[0] <= fVar14)) {
        bVar6 = 1;
      }
    }
    else {
      fVar18 = afStack_1cc[6] * (fVar18 - afStack_1cc[0]);
      fVar21 = afStack_1cc[6] * (fVar14 - afStack_1cc[0]);
      fVar14 = fVar21;
      if (fVar18 <= fVar21) {
        fVar14 = fVar18;
        fVar18 = fVar21;
      }
      bVar6 = 0;
      if ((0.0 <= fVar18) && (fVar14 <= 1.0)) {
        bVar6 = 1;
      }
      if (bVar6) {
        if (0.0 < fVar14) {
          fStack_190 = fVar14;
        }
        if (1.0 <= fVar18) {
          fStack_18c = 1.0;
        }
        else {
          fStack_18c = fVar18;
        }
      }
    }
    bVar7 = 0;
    if (bVar6) {
      if (afStack_1cc[7] == 0.0) {
        bVar6 = 0;
        if ((fVar19 <= afStack_1cc[1]) && (afStack_1cc[1] <= fVar20)) {
          bVar6 = 1;
        }
      }
      else {
        fVar18 = afStack_1cc[7] * (fVar19 - afStack_1cc[1]);
        fVar19 = afStack_1cc[7] * (fVar20 - afStack_1cc[1]);
        fVar14 = fVar19;
        if (fVar18 <= fVar19) {
          fVar14 = fVar18;
          fVar18 = fVar19;
        }
        bVar6 = 0;
        if ((fStack_190 <= fVar18) && (fVar14 <= fStack_18c)) {
          bVar6 = 1;
        }
        if (bVar6) {
          if (fStack_190 < fVar14) {
            fStack_190 = fVar14;
          }
          if (fStack_18c <= fVar18) {
          }
          else {
            fStack_18c = fVar18;
          }
        }
      }
      bVar7 = 0;
      if (bVar6) {
        if (afStack_1cc[8] == 0.0) {
          bVar7 = 0;
          if ((fVar16 <= afStack_1cc[2]) && (afStack_1cc[2] <= fVar15)) {
            bVar7 = 1;
          }
        }
        else {
          fVar16 = afStack_1cc[8] * (fVar16 - afStack_1cc[2]);
          fVar14 = afStack_1cc[8] * (fVar15 - afStack_1cc[2]);
          fVar15 = fVar14;
          if (fVar16 <= fVar14) {
            fVar15 = fVar16;
            fVar16 = fVar14;
          }
          bVar7 = 0;
          if ((fStack_190 <= fVar16) && (fVar15 <= fStack_18c)) {
            bVar7 = 1;
          }
          if (bVar7) {
            if (fStack_190 < fVar15) {
              fStack_190 = fVar15;
            }
            if (fStack_18c <= fVar16) {
            }
            else {
              fStack_18c = fVar16;
            }
          }
        }
      }
    }
    if (!bVar7) {
      ppuStack_8 = &puStack_194;
    }
    iStack_1d0 = iVar2;
    if (&puStack_194 < ppuStack_8) {
      do {
        ppuVar8 = ppuStack_8;
        ppuStack_8 = ppuStack_8 + -3;
        puVar5 = ppuVar8[-3];
        bVar1 = puVar5[1];
        ppuVar8 = ppuStack_8;
        while (ppuStack_8 = ppuVar8, bVar1 == 0xff) {
          pbVar10 = (u8 *)(*(int *)(iStack_1d0 + 0x20) + (u32)*(u16 *)(puVar5 + 2) * 0x10);
          uVar13 = *pbVar10 & 0xc;
          fVar18 = *(float *)((int)afStack_1cc + uVar13 + 0xc);
          fVar16 = *(float *)((int)afStack_1cc + uVar13 + 0x24);
          fVar19 = *(float *)(pbVar10 + 0xc) - fVar16;
          fVar16 = *(float *)(pbVar10 + 4) + fVar16;
          fVar15 = (float)(int)ppuVar8[2] * fVar18 + *(float *)((int)afStack_1cc + uVar13) + 0.0;
          fVar14 = (float)(int)ppuVar8[1] * fVar18 + *(float *)((int)afStack_1cc + uVar13) + 0.0;
          if (0.0 < fVar18) {
            if (fVar19 <= fVar15) {
              if (fVar14 <= fVar16) {
                ppuStack_8 = ppuVar8 + 3;
                fVar18 = *(float *)((int)afStack_1cc + uVar13 + 0x18);
                ppuVar8[3] = pbVar10;
                ppuVar8[4] = ppuVar8[1];
                ppuVar8[5] = ppuVar8[2];
                if (fVar16 < fVar15) {
                  ppuVar8[5] = (u8 *)(int)(fVar18 * (fVar16 - fVar15) + (float)(int)ppuVar8[5] + 0.0);
                }
                *ppuVar8 = pbVar10 + 8;
                if (fVar14 < fVar19) {
                  ppuVar8[1] = (u8 *)(int)(fVar18 * (fVar19 - fVar14) + (float)(int)ppuVar8[1] + 0.0);
                }
                *ppuVar8 = pbVar10 + 8;
              }
              *ppuVar8 = pbVar10;
            }
          }
          else if (fVar15 <= fVar16) {
            if (fVar19 <= fVar14) {
              ppuStack_8 = ppuVar8 + 3;
              fVar18 = *(float *)((int)afStack_1cc + uVar13 + 0x18);
              ppuVar8[3] = pbVar10 + 8;
              ppuVar8[4] = ppuVar8[1];
              ppuVar8[5] = ppuVar8[2];
              if (fVar15 < fVar19) {
                ppuVar8[5] = (u8 *)(int)(fVar18 * (fVar19 - fVar15) + (float)(int)ppuVar8[5] + 0.0);
              }
              *ppuVar8 = pbVar10;
              if (fVar16 < fVar14) {
                ppuVar8[1] = (u8 *)(int)(fVar18 * (fVar16 - fVar14) + (float)(int)ppuVar8[1] + 0.0);
              }
              *ppuVar8 = pbVar10;
            }
            *ppuVar8 = pbVar10 + 8;
          }
          puVar5 = *ppuStack_8;
          ppuVar8 = ppuStack_8;
          bVar1 = puVar5[1];
        }
        uVar13 = (u32)*(u16 *)(*ppuVar8 + 2);
        uVar12 = uVar13 + bVar1;
        for (; uVar13 < uVar12; uVar13 = uVar13 + 1 & 0xffff) {
          uStack_1e8 = uVar13;
          if (*(int *)(iVar2 + 0x24) != 0) {
            uStack_1e8 = (u32)*(u16 *)(*(int *)(iVar2 + 0x24) + uVar13 * 2);
          }
          puVar11 = (u16 *)(iVar3 + uStack_1e8 * 8);
          pfStack_1e4 = (float *)(iVar4 + (u32)*puVar11 * 0xc);
          pfStack_1e0 = (float *)(iVar4 + (u32)puVar11[1] * 0xc);
          fVar14 = *pfStack_1e4;
          fVar15 = pfStack_1e4[2];
          fVar18 = pfStack_1e4[1];
          pfStack_1dc = (float *)(iVar4 + (u32)puVar11[2] * 0xc);
          fVar26 = *pfStack_1e0 - fVar14;
          fVar28 = pfStack_1e0[2] - fVar15;
          fVar21 = *pfStack_1dc - fVar14;
          fVar25 = pfStack_1e0[1] - fVar18;
          fVar23 = pfStack_1dc[2] - fVar15;
          fVar24 = pfStack_1dc[1] - fVar18;
          fVar20 = fVar29 * fVar23 - fVar31 * fVar24;
          fVar19 = fVar31 * fVar21 - fVar30 * fVar23;
          fVar22 = fVar30 * fVar24 - fVar29 * fVar21;
          fVar16 = fVar28 * fVar22 + fVar26 * fVar20 + fVar25 * fVar19;
          bVar6 = 0;
          if (1e-08 < fVar16) {
            fVar27 = -fVar16 * 1e-05;
            fVar14 = *param_2 - fVar14;
            fVar18 = param_2[1] - fVar18;
            fVar15 = param_2[2] - fVar15;
            fVar19 = fVar15 * fVar22 + fVar14 * fVar20 + fVar18 * fVar19;
            fVar20 = fVar16 - fVar27;
            bVar7 = 0;
            if ((fVar27 <= fVar19) && (bVar7 = 1, fVar20 < fVar19)) {
              bVar7 = 0;
            }
            bVar6 = 0;
            if (bVar7) {
              fVar17 = fVar18 * fVar28 - fVar15 * fVar25;
              fVar22 = fVar15 * fVar26 - fVar14 * fVar28;
              fVar14 = fVar14 * fVar25 - fVar18 * fVar26;
              fVar15 = fVar31 * fVar14 + fVar30 * fVar17 + fVar29 * fVar22;
              bVar7 = 0;
              if ((fVar27 <= fVar15) && (bVar7 = 1, fVar20 < fVar19 + fVar15)) {
                bVar7 = 0;
              }
              bVar6 = 0;
              if (bVar7) {
                in_f23 = fVar23 * fVar14 + fVar21 * fVar17 + fVar24 * fVar22;
                bVar6 = 0;
                if ((fVar27 <= in_f23) && (bVar6 = 1, fVar20 < in_f23)) {
                  bVar6 = 0;
                }
                if (bVar6) {
                  in_f23 = in_f23 / fVar16;
                }
              }
            }
          }
          if (bVar6) {
            fStack_1f4 = *pfStack_1e4;
            fStack_1f0 = pfStack_1e4[1];
            fStack_1ec = pfStack_1e4[2];
            fVar20 = *pfStack_1e0 - *pfStack_1e4;
            fVar16 = *pfStack_1dc - *pfStack_1e4;
            fVar19 = pfStack_1e0[2] - pfStack_1e4[2];
            fVar18 = pfStack_1e0[1] - pfStack_1e4[1];
            fVar15 = pfStack_1dc[2] - pfStack_1e4[2];
            fVar14 = pfStack_1dc[1] - pfStack_1e4[1];
            fStack_200 = fVar18 * fVar15 - fVar19 * fVar14;
            fStack_1fc = fVar19 * fVar16 - fVar20 * fVar15;
            fStack_1f8 = fVar20 * fVar14 - fVar18 * fVar16;
            fVar15 = SQRT(fStack_1f8 * fStack_1f8 +
                          fStack_200 * fStack_200 + fStack_1fc * fStack_1fc);
            if (0.0 < fVar15) {
              fVar15 = 1.0 / fVar15;
            }
            fStack_200 = fStack_200 * fVar15;
            fStack_1fc = fStack_1fc * fVar15;
            fStack_1f8 = fStack_1f8 * fVar15;
            lVar9 = (*param_4)(in_f23,param_3,&fStack_200,param_5);
            if (lVar9 == 0) {
              return;
            }
          }
        }
      } while (&puStack_194 < ppuStack_8);
    }
  }
  return;
}

// FUN_00462BB0 NONMATCHING

void FUN_00462bb0(int param_1,u64 param_2,u32 param_3,code *param_4,u32 param_5
                 )

{
  char cVar1;
  u16 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  u8 **ppuVar6;
  u16 *puVar7;
  long lVar8;
  u16 uVar9;
  u32 uVar10;
  u32 uVar11;
  u32 uVar12;
  u8 *pbVar13;
  int iVar14;
  u32 uVar15;
  u32 uVar16;
  int iVar17;
  float *pfVar18;
  float *pfVar19;
  float *pfVar20;
  float *pfVar21;
  u8 *puVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  u8 **ppuStack_1f0;
  float fStack_1d0;
  float fStack_1cc;
  float fStack_1c8;
  float fStack_1c4;
  float fStack_1c0;
  float fStack_1bc;
  u32 uStack_1b8;
  float *pfStack_1b4;
  float *pfStack_1b0;
  float *pfStack_1ac;
  int iStack_1a0;
  float afStack_19c [12];
  u8 uStack_16c;
  u8 uStack_16b;
  u16 uStack_16a;
  u8 *puStack_164;
  u32 uStack_160;
  u8 *apuStack_15c [64];
  u8 **ppuStack_5c;
  u64 uStack_50;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  u64 uStack_30;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar3 = *(int *)(param_1 + iGpffffba38);
  if (iVar3 == 0) {
    ((code)FUN_00461d00)();
  }
  else {
    fVar28 = *(float *)(iVar3 + 0x10);
    pfVar18 = (float *)param_2;
    fVar23 = *pfVar18;
    if (fVar23 < fVar28) {
      fVar23 = fVar28 - fVar23;
    }
    else if (*(float *)(iVar3 + 4) < fVar23) {
      fVar23 = fVar23 - *(float *)(iVar3 + 4);
    }
    else {
      fVar23 = 0.0;
    }
    fVar29 = *(float *)(iVar3 + 0x14);
    fVar24 = pfVar18[1];
    if (fVar24 < fVar29) {
      fVar24 = fVar29 - fVar24;
    }
    else if (*(float *)(iVar3 + 8) < fVar24) {
      fVar24 = fVar24 - *(float *)(iVar3 + 8);
    }
    else {
      fVar24 = 0.0;
    }
    fVar26 = *(float *)(iVar3 + 0x18);
    fVar25 = pfVar18[2];
    fVar27 = 0.0;
    if (fVar25 < fVar26) {
      fVar27 = fVar26 - fVar25;
    }
    else if (*(float *)(iVar3 + 0xc) < fVar25) {
      fVar27 = fVar25 - *(float *)(iVar3 + 0xc);
    }
    fVar25 = pfVar18[3];
    if (fVar27 * fVar27 + fVar24 * fVar24 + fVar23 * fVar23 + 0.0 + 0.0 <= fVar25 * fVar25) {
      iVar4 = *(int *)(param_1 + 0x2c);
      iVar5 = *(int *)(*(int *)(param_1 + 0x5c) + 0x14);
      fStack_10 = *pfVar18;
      fStack_c = pfVar18[1];
      fVar23 = fVar25 * 0.57;
      fStack_8 = pfVar18[2];
      fVar30 = fStack_10 + fVar25;
      fStack_44 = fStack_10 - fVar23;
      fStack_3c = fStack_8 - fVar23;
      fVar24 = fStack_10 + fVar23;
      fStack_48 = fStack_8 + fVar23;
      fStack_28 = fStack_8 + fVar25;
      fStack_24 = fStack_10 - fVar25;
      fStack_20 = fStack_c - fVar25;
      fVar27 = fStack_c + fVar25;
      fStack_40 = fStack_c - fVar23;
      fStack_1c = fStack_8 - fVar25;
      fVar23 = fStack_c + fVar23;
      uStack_30 = CONCAT44(fVar27,fVar30);
      uStack_50 = CONCAT44(fVar23,fVar24);
      if ((((fVar30 < fVar28) || (fVar27 < fVar29)) || (fStack_28 < fVar26)) ||
         (((*(float *)(iVar3 + 4) < fStack_24 || (*(float *)(iVar3 + 8) < fStack_20)) ||
          (*(float *)(iVar3 + 0xc) < fStack_1c)))) {
        ppuStack_5c = &puStack_164;
      }
      else {
        uStack_16a = 0;
        uStack_16b = 0xff;
        if (*(short *)(iVar3 + 0x1e) == 0) {
          uStack_16b = (char)*(u16 *)(iVar3 + 0x1c);
        }
        afStack_19c[2] = fStack_28;
        afStack_19c[5] = fStack_1c;
        puStack_164 = &uStack_16c;
        afStack_19c[0] = fVar30;
        afStack_19c[1] = fVar27;
        afStack_19c[3] = fStack_24;
        afStack_19c[4] = fStack_20;
        afStack_19c[7] = fVar23;
        afStack_19c[8] = fStack_48;
        afStack_19c[9] = fStack_44;
        afStack_19c[10] = fStack_40;
        afStack_19c[0xb] = fStack_3c;
        afStack_19c[6] = fVar24;
        if (*(float *)(iVar3 + 0x14) < fStack_40) {
          uVar12 = 4;
        }
        else {
          uVar12 = 0;
        }
        if (*(float *)(iVar3 + 0x18) < fStack_3c) {
          uVar10 = 0x10;
        }
        else {
          uVar10 = 0;
        }
        if (fVar24 < *(float *)(iVar3 + 4)) {
          uVar16 = 2;
        }
        else {
          uVar16 = 0;
        }
        if (fVar23 < *(float *)(iVar3 + 8)) {
          uVar15 = 8;
        }
        else {
          uVar15 = 0;
        }
        if (fStack_48 < *(float *)(iVar3 + 0xc)) {
          uVar11 = 0x20;
        }
        else {
          uVar11 = 0;
        }
        ppuStack_5c = apuStack_15c;
        uStack_160 = uVar11 | uVar15 | uVar16 | uVar10 | *(float *)(iVar3 + 0x10) < fStack_44 |
                                                         uVar12;
        iStack_1a0 = iVar3;
      }
      ppuStack_1f0 = &puStack_164;
      while (ppuStack_1f0 < ppuStack_5c) {
        ppuStack_5c = ppuStack_5c + -2;
LAB_00462fc4:
        ppuVar6 = ppuStack_5c;
        puVar22 = *ppuStack_5c;
        uVar9 = (u16)(u8)puVar22[1];
        if (uVar9 == 0xff) {
          if (ppuStack_5c[1] != (u8 *)0x0) goto code_r0x00462ff4;
          iVar14 = *(int *)(iStack_1a0 + 0x20) + (u32)*(u16 *)(puVar22 + 2) * 0x10;
          cVar1 = *(char *)(iVar14 + 1);
          iVar17 = iVar14;
          while (cVar1 == -1) {
            iVar17 = *(int *)(iStack_1a0 + 0x20) + (u32)*(u16 *)(iVar17 + 2) * 0x10;
            cVar1 = *(char *)(iVar17 + 1);
          }
          uVar9 = (u16)*(u8 *)(iVar14 + 9);
          iVar14 = iVar14 + 8;
          if (uVar9 == 0xff) {
            do {
              iVar14 = *(int *)(iStack_1a0 + 0x20) + (u32)*(u16 *)(iVar14 + 2) * 0x10;
              uVar9 = (u16)*(u8 *)(iVar14 + 9);
              iVar14 = iVar14 + 8;
            } while (uVar9 == 0xff);
          }
          uVar2 = *(u16 *)(iVar17 + 2);
          puVar22 = (u8 *)0x0;
          uVar9 = (*(short *)(iVar14 + 2) + uVar9) - uVar2;
        }
        else {
          uVar2 = *(u16 *)(puVar22 + 2);
          puVar22 = ppuStack_5c[1];
        }
        for (uVar12 = (u32)uVar2; uVar12 < (u32)uVar2 + (u32)uVar9; uVar12 = uVar12 + 1 & 0xffff)
        {
          uVar10 = uVar12;
          if (*(int *)(iVar3 + 0x24) != 0) {
            uVar10 = (u32)*(u16 *)(*(int *)(iVar3 + 0x24) + uVar12 * 2);
          }
          puVar7 = (u16 *)(iVar4 + uVar10 * 8);
          pfVar19 = (float *)(iVar5 + (u32)*puVar7 * 0xc);
          pfVar20 = (float *)(iVar5 + (u32)puVar7[1] * 0xc);
          pfVar21 = (float *)(iVar5 + (u32)puVar7[2] * 0xc);
          if (puVar22 == (u8 *)0x0) {
            fVar27 = *pfVar20 - *pfVar19;
            fVar28 = *pfVar21 - *pfVar19;
            fVar26 = pfVar20[2] - pfVar19[2];
            fVar29 = pfVar20[1] - pfVar19[1];
            fVar23 = pfVar21[2] - pfVar19[2];
            fVar24 = pfVar21[1] - pfVar19[1];
            fStack_1d0 = fVar29 * fVar23 - fVar26 * fVar24;
            fStack_1cc = fVar26 * fVar28 - fVar27 * fVar23;
            fStack_1c8 = fVar27 * fVar24 - fVar29 * fVar28;
            fVar23 = SQRT(fStack_1c8 * fStack_1c8 +
                          fStack_1d0 * fStack_1d0 + fStack_1cc * fStack_1cc);
            if (0.0 < fVar23) {
              fVar23 = 1.0 / fVar23;
            }
            fStack_1d0 = fStack_1d0 * fVar23;
            fStack_1cc = fStack_1cc * fVar23;
            fStack_1c8 = fStack_1c8 * fVar23;
            fStack_4 = (pfVar18[2] - pfVar19[2]) * fStack_1c8 +
                       (*pfVar18 - *pfVar19) * fStack_1d0 + (pfVar18[1] - pfVar19[1]) * fStack_1cc;
LAB_00463298:
            fStack_4 = fStack_4 * (1.0 / fVar25);
            fStack_1c4 = *pfVar19;
            fStack_1c0 = pfVar19[1];
            fStack_1bc = pfVar19[2];
            uStack_1b8 = uVar10;
            pfStack_1b4 = pfVar19;
            pfStack_1b0 = pfVar20;
            pfStack_1ac = pfVar21;
            lVar8 = (*param_4)(fStack_4,param_3,&fStack_1d0,param_5);
            if (lVar8 == 0) {
              return;
            }
          }
          else {
            lVar8 = ((code)FUN_004bae00)(param_2,pfVar19,pfVar20,pfVar21,&fStack_1d0,&fStack_4);
            if (lVar8 != 0) goto LAB_00463298;
          }
        }
      }
    }
  }
  return;
code_r0x00462ff4:
  pbVar13 = (u8 *)(*(int *)(iStack_1a0 + 0x20) + (u32)*(u16 *)(puVar22 + 2) * 0x10);
  uVar12 = *pbVar13 & 0xc;
  if (*(float *)((int)afStack_19c + uVar12) < *(float *)(pbVar13 + 0xc)) {
    *ppuStack_5c = pbVar13;
  }
  else {
    *ppuStack_5c = pbVar13 + 8;
    if (*(float *)((int)afStack_19c + uVar12 + 0xc) <= *(float *)(pbVar13 + 4)) {
      ppuStack_5c = ppuStack_5c + 2;
      ppuVar6[2] = pbVar13;
      ppuVar6[3] = ppuVar6[1];
      if (*(float *)(pbVar13 + 4) <= *(float *)((int)afStack_19c + uVar12 + 0x18)) {
        ppuVar6[3] = (u8 *)((u32)ppuVar6[3] & ~(2 << (uVar12 >> 1)));
      }
      if (*(float *)((int)afStack_19c + uVar12 + 0x24) <= *(float *)(pbVar13 + 0xc)) {
        ppuVar6[1] = (u8 *)((u32)ppuVar6[1] & ~(1 << (uVar12 >> 1)));
      }
    }
  }
  goto LAB_00462fc4;
}

// FUN_00463490 NONMATCHING

void FUN_00463490(int param_1,int param_2,float *param_3,u32 param_4,code *param_5,
                 u32 param_6)

{
  u8 bVar1;
  u8 bVar2;
  long lVar3;
  float *pfVar4;
  float *pfVar5;
  u16 *puVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  int iVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float in_f23;
  float fVar28;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  int iStack_48;
  float *pfStack_44;
  float *pfStack_40;
  float *pfStack_3c;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  int iStack_c;
  int iStack_8;
  float fStack_4;
  
  iVar10 = 0;
  pfVar9 = &fStack_30;
  pfVar8 = &fStack_24;
  pfVar7 = &fStack_18;
  fVar27 = param_3[3] - *param_3;
  fVar28 = param_3[5] - param_3[2];
  iStack_c = *(int *)(*(short *)(param_2 + 4) * 0x1c + *(int *)(param_1 + 0x5c) + 0x14);
  iStack_8 = *(int *)(*(short *)(param_2 + 6) * 0x1c + *(int *)(param_1 + 0x5c) + 0x14);
  fStack_4 = *(float *)(param_2 + 0xc) * *(float *)(param_2 + 0x10);
  puVar6 = *(u16 **)(param_1 + 0x2c);
  fVar26 = param_3[4] - param_3[1];
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      if (iStack_c == iStack_8) {
        pfVar8 = (float *)(iStack_c + (u32)puVar6[1] * 0xc);
        pfVar9 = (float *)(iStack_c + (u32)*puVar6 * 0xc);
        pfVar7 = (float *)(iStack_c + (u32)puVar6[2] * 0xc);
      }
      else {
        pfVar5 = (float *)(iStack_c + (u32)*puVar6 * 0xc);
        pfVar4 = (float *)(iStack_8 + (u32)*puVar6 * 0xc);
        fStack_30 = (*pfVar4 - *pfVar5) * fStack_4 + *pfVar5;
        fStack_2c = (pfVar4[1] - pfVar5[1]) * fStack_4 + pfVar5[1];
        fStack_28 = (pfVar4[2] - pfVar5[2]) * fStack_4 + pfVar5[2];
        pfVar5 = (float *)(iStack_c + (u32)puVar6[1] * 0xc);
        pfVar4 = (float *)(iStack_8 + (u32)puVar6[1] * 0xc);
        fStack_24 = (*pfVar4 - *pfVar5) * fStack_4 + *pfVar5;
        fStack_20 = (pfVar4[1] - pfVar5[1]) * fStack_4 + pfVar5[1];
        fStack_1c = (pfVar4[2] - pfVar5[2]) * fStack_4 + pfVar5[2];
        pfVar5 = (float *)(iStack_c + (u32)puVar6[2] * 0xc);
        pfVar4 = (float *)(iStack_8 + (u32)puVar6[2] * 0xc);
        fStack_18 = (*pfVar4 - *pfVar5) * fStack_4 + *pfVar5;
        fStack_14 = (pfVar4[1] - pfVar5[1]) * fStack_4 + pfVar5[1];
        fStack_10 = (pfVar4[2] - pfVar5[2]) * fStack_4 + pfVar5[2];
      }
      fVar14 = *pfVar9;
      fVar13 = pfVar9[2];
      fVar15 = pfVar9[1];
      fVar18 = *pfVar7 - fVar14;
      fVar25 = pfVar8[2] - fVar13;
      fVar22 = pfVar8[1] - fVar15;
      fVar20 = pfVar7[2] - fVar13;
      fVar21 = pfVar7[1] - fVar15;
      fVar17 = fVar26 * fVar20 - fVar28 * fVar21;
      fVar16 = fVar28 * fVar18 - fVar27 * fVar20;
      fVar19 = fVar27 * fVar21 - fVar26 * fVar18;
      fVar23 = *pfVar8 - fVar14;
      fVar11 = fVar25 * fVar19 + fVar23 * fVar17 + fVar22 * fVar16;
      bVar1 = 0;
      if (1e-08 < fVar11) {
        fVar24 = -fVar11 * 1e-05;
        fVar14 = *param_3 - fVar14;
        fVar15 = param_3[1] - fVar15;
        fVar13 = param_3[2] - fVar13;
        fVar16 = fVar13 * fVar19 + fVar14 * fVar17 + fVar15 * fVar16;
        fVar17 = fVar11 - fVar24;
        bVar2 = 0;
        if ((fVar24 <= fVar16) && (bVar2 = 1, fVar17 < fVar16)) {
          bVar2 = 0;
        }
        bVar1 = 0;
        if (bVar2) {
          fVar12 = fVar15 * fVar25 - fVar13 * fVar22;
          fVar19 = fVar13 * fVar23 - fVar14 * fVar25;
          fVar14 = fVar14 * fVar22 - fVar15 * fVar23;
          fVar13 = fVar28 * fVar14 + fVar27 * fVar12 + fVar26 * fVar19;
          bVar2 = 0;
          if ((fVar24 <= fVar13) && (bVar2 = 1, fVar17 < fVar16 + fVar13)) {
            bVar2 = 0;
          }
          bVar1 = 0;
          if (bVar2) {
            in_f23 = fVar20 * fVar14 + fVar18 * fVar12 + fVar21 * fVar19;
            bVar1 = 0;
            if ((fVar24 <= in_f23) && (bVar1 = 1, fVar17 < in_f23)) {
              bVar1 = 0;
            }
            if (bVar1) {
              in_f23 = in_f23 / fVar11;
            }
          }
        }
      }
      if (bVar1) {
        fStack_54 = *pfVar9;
        fStack_50 = pfVar9[1];
        fStack_4c = pfVar9[2];
        fVar17 = *pfVar8 - *pfVar9;
        fVar11 = *pfVar7 - *pfVar9;
        fVar16 = pfVar8[2] - pfVar9[2];
        fVar15 = pfVar8[1] - pfVar9[1];
        fVar13 = pfVar7[2] - pfVar9[2];
        fVar14 = pfVar7[1] - pfVar9[1];
        fStack_60 = fVar15 * fVar13 - fVar16 * fVar14;
        fStack_5c = fVar16 * fVar11 - fVar17 * fVar13;
        fStack_58 = fVar17 * fVar14 - fVar15 * fVar11;
        fVar13 = SQRT(fStack_58 * fStack_58 + fStack_60 * fStack_60 + fStack_5c * fStack_5c);
        if (0.0 < fVar13) {
          fVar13 = 1.0 / fVar13;
        }
        fStack_60 = fStack_60 * fVar13;
        fStack_5c = fStack_5c * fVar13;
        fStack_58 = fStack_58 * fVar13;
        iStack_48 = iVar10;
        pfStack_44 = pfVar9;
        pfStack_40 = pfVar8;
        pfStack_3c = pfVar7;
        lVar3 = (*param_5)(in_f23,param_4,&fStack_60,param_6);
        if (lVar3 == 0) {
          return;
        }
      }
      iVar10 = iVar10 + 1;
      puVar6 = puVar6 + 4;
    } while (iVar10 < *(int *)(param_1 + 0x10));
  }
  return;
}

// FUN_00463B20 NONMATCHING

void FUN_00463b20(int param_1,int param_2,int param_3,u32 param_4,code *param_5,
                 u32 param_6)

{
  long lVar1;
  float *pfVar2;
  float *pfVar3;
  u16 *puVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  float fVar9;
  u8 auStack_70 [12];
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  int iStack_58;
  float *pfStack_54;
  float *pfStack_50;
  float *pfStack_4c;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  int iStack_1c;
  int iStack_18;
  float fStack_14;
  float fStack_4;
  
  pfVar7 = &fStack_34;
  pfVar8 = &fStack_40;
  pfVar6 = &fStack_28;
  iVar5 = 0;
  fVar9 = *(float *)(param_3 + 0xc);
  iStack_1c = *(int *)(*(short *)(param_2 + 4) * 0x1c + *(int *)(param_1 + 0x5c) + 0x14);
  iStack_18 = *(int *)(*(short *)(param_2 + 6) * 0x1c + *(int *)(param_1 + 0x5c) + 0x14);
  fStack_14 = *(float *)(param_2 + 0xc) * *(float *)(param_2 + 0x10);
  puVar4 = *(u16 **)(param_1 + 0x2c);
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      if (iStack_1c == iStack_18) {
        pfVar7 = (float *)(iStack_1c + (u32)puVar4[1] * 0xc);
        pfVar8 = (float *)(iStack_1c + (u32)*puVar4 * 0xc);
        pfVar6 = (float *)(iStack_1c + (u32)puVar4[2] * 0xc);
      }
      else {
        pfVar3 = (float *)(iStack_1c + (u32)*puVar4 * 0xc);
        pfVar2 = (float *)(iStack_18 + (u32)*puVar4 * 0xc);
        fStack_40 = (*pfVar2 - *pfVar3) * fStack_14 + *pfVar3;
        fStack_3c = (pfVar2[1] - pfVar3[1]) * fStack_14 + pfVar3[1];
        fStack_38 = (pfVar2[2] - pfVar3[2]) * fStack_14 + pfVar3[2];
        pfVar3 = (float *)(iStack_1c + (u32)puVar4[1] * 0xc);
        pfVar2 = (float *)(iStack_18 + (u32)puVar4[1] * 0xc);
        fStack_34 = (*pfVar2 - *pfVar3) * fStack_14 + *pfVar3;
        fStack_30 = (pfVar2[1] - pfVar3[1]) * fStack_14 + pfVar3[1];
        fStack_2c = (pfVar2[2] - pfVar3[2]) * fStack_14 + pfVar3[2];
        pfVar3 = (float *)(iStack_1c + (u32)puVar4[2] * 0xc);
        pfVar2 = (float *)(iStack_18 + (u32)puVar4[2] * 0xc);
        fStack_28 = (*pfVar2 - *pfVar3) * fStack_14 + *pfVar3;
        fStack_24 = (pfVar2[1] - pfVar3[1]) * fStack_14 + pfVar3[1];
        fStack_20 = (pfVar2[2] - pfVar3[2]) * fStack_14 + pfVar3[2];
      }
      lVar1 = ((code)FUN_004bae00)(param_3,pfVar8,pfVar7,pfVar6,auStack_70,&fStack_4);
      if (lVar1 != 0) {
        fStack_64 = *pfVar8;
        fStack_60 = pfVar8[1];
        fStack_5c = pfVar8[2];
        fStack_4 = fStack_4 * (1.0 / fVar9);
        iStack_58 = iVar5;
        pfStack_54 = pfVar8;
        pfStack_50 = pfVar7;
        pfStack_4c = pfVar6;
        lVar1 = (*param_5)(param_4,auStack_70,param_6);
        if (lVar1 == 0) {
          return;
        }
      }
      iVar5 = iVar5 + 1;
      puVar4 = puVar4 + 4;
    } while (iVar5 < *(int *)(param_1 + 0x10));
  }
  return;
}

// FUN_00463F20 NONMATCHING

void FUN_00463f20(int param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5)

{
  int iVar1;
  u64 uVar2;
  u8 auStack_50 [32];
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  u8 auStack_10 [12];
  float fStack_4;
  
  iVar1 = *(int *)(param_1 + 0x18);
  uVar2 = ((code)FUN_004cb2f0)(*(u32 *)(param_1 + 4));
  ((code)FUN_004c32a0)(auStack_50,uVar2);
  ((code)FUN_004c6c20)(auStack_10,param_2,1,auStack_50);
  fStack_4 = SQRT(fStack_28 * fStack_28 + fStack_30 * fStack_30 + fStack_2c * fStack_2c) *
             *(float *)((int)param_2 + 0xc);
  if (*(int *)(iVar1 + 0x18) < 2) {
    ((code)FUN_00462bb0)(iVar1,auStack_10,param_3,param_4,param_5);
  }
  else {
    ((code)FUN_00463b20)(iVar1,param_1 + 0x4c,auStack_10,param_3,param_4,param_5);
  }
  return;
}

// FUN_00464020 NONMATCHING

u64 FUN_00464020(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  int iVar1;
  u32 *puVar2;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar1 = ((u32 *)param_2)[6];
  if (iVar1 == 5) {
    puVar2 = (u32 *)((code)FUN_004912b0)(*(u32 *)param_2);
    uStack_10 = *puVar2;
    uStack_c = puVar2[1];
    uStack_8 = puVar2[2];
    uStack_4 = puVar2[3];
    ((code)FUN_00460ec0)(param_1,&uStack_10,param_2,param_3,param_4);
  }
  else if (iVar1 == 4) {
    ((code)FUN_004606b0)();
  }
  else if (iVar1 == 3) {
    ((code)FUN_00460ec0)(param_1,param_2,param_2,param_3,param_4);
  }
  else if (iVar1 == 1) {
    ((code)FUN_0045f930)();
  }
  return param_1;
}

// FUN_00464120 NONMATCHING

u64 FUN_00464120(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  int iVar1;
  u32 *puVar2;
  u64 uVar3;
  int iVar4;
  u8 auStack_70 [32];
  u8 auStack_50 [64];
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar1 = ((u32 *)param_2)[6];
  if (iVar1 == 5) {
    puVar2 = (u32 *)((code)FUN_004912b0)(*(u32 *)param_2);
    uStack_10 = *puVar2;
    uStack_c = puVar2[1];
    uStack_8 = puVar2[2];
    uStack_4 = puVar2[3];
    ((code)FUN_00463f20)(param_1,&uStack_10,param_2,param_3,param_4);
  }
  else if (iVar1 == 3) {
    ((code)FUN_00463f20)(param_1,param_2,param_2,param_3,param_4);
  }
  else if (iVar1 == 1) {
    iVar4 = (int)param_1;
    iVar1 = *(int *)(iVar4 + 0x18);
    uVar3 = ((code)FUN_004cb2f0)(*(u32 *)(iVar4 + 4));
    ((code)FUN_004c32a0)(auStack_50,uVar3);
    ((code)FUN_004c6c20)(auStack_70,param_2,2,auStack_50);
    if (*(int *)(iVar1 + 0x18) < 2) {
      ((code)FUN_00461ea0)(iVar1,auStack_70,param_2,param_3,param_4);
    }
    else {
      ((code)FUN_00463490)(iVar1,iVar4 + 0x4c,auStack_70,param_2,param_3,param_4);
    }
  }
  return param_1;
}

// FUN_00464280 NONMATCHING

long FUN_00464280(u32 param_1)

{
  u32 *puVar1;
  long lVar2;
  u32 *puVar3;
  u32 uVar4;
  int iVar5;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar5 = param_1 * 8 + 8;
  lVar2 = (*DAT_00960178)(iVar5,0x3001e);
  if (lVar2 == 0) {
    uStack_8 = 0x122;
    uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,iVar5);
    ((code)FUN_004c1c50)(&uStack_8);
    lVar2 = 0;
  }
  else {
    puVar1 = (u32 *)lVar2;
    *puVar1 = param_1;
    puVar1[1] = (u32)(puVar1 + 2);
    puVar3 = (u32 *)puVar1[1];
    uVar4 = 0;
    if (param_1 != 0) {
      if (8 < param_1) {
        do {
          *puVar3 = 0;
          uVar4 = uVar4 + 8;
          puVar3[1] = 0;
          puVar3[2] = 0;
          puVar3[3] = 0;
          puVar3[4] = 0;
          puVar3[5] = 0;
          puVar3[6] = 0;
          puVar3[7] = 0;
          puVar3[8] = 0;
          puVar3[9] = 0;
          puVar3[10] = 0;
          puVar3[0xb] = 0;
          puVar3[0xc] = 0;
          puVar3[0xd] = 0;
          puVar3[0xe] = 0;
          puVar3[0xf] = 0;
          puVar3 = puVar3 + 0x10;
        } while (uVar4 < param_1 - 8);
      }
      for (; uVar4 < param_1; uVar4 = uVar4 + 1) {
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3 = puVar3 + 2;
      }
    }
  }
  return lVar2;
}

// FUN_004643B0 NONMATCHING

u64 FUN_004643b0(u64 param_1,int param_2,u32 param_3)

{
  u32 uVar1;
  u32 *puVar2;
  int iVar3;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar3 = param_3 * 0x14;
  puVar2 = (u32 *)(*(int *)((int)param_1 + 4) + param_2 * 8);
  uVar1 = (*DAT_00960178)(iVar3,0x30122);
  puVar2[1] = uVar1;
  if (puVar2[1] == 0) {
    uStack_8 = 0x122;
    uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,iVar3);
    ((code)FUN_004c1c50)(&uStack_8);
    param_1 = 0;
  }
  else {
    ((code)FUN_00521408)(puVar2[1],0,iVar3);
    uVar1 = 0;
    if (param_3 != 0) {
      if (8 < param_3) {
        iVar3 = 0;
        do {
          uVar1 = uVar1 + 8;
          *(u32 *)(puVar2[1] + iVar3 + 0x10) = 0xffffffff;
          *(u32 *)(puVar2[1] + iVar3 + 0x24) = 0xffffffff;
          *(u32 *)(puVar2[1] + iVar3 + 0x38) = 0xffffffff;
          *(u32 *)(puVar2[1] + iVar3 + 0x4c) = 0xffffffff;
          *(u32 *)(puVar2[1] + iVar3 + 0x60) = 0xffffffff;
          *(u32 *)(puVar2[1] + iVar3 + 0x74) = 0xffffffff;
          *(u32 *)(puVar2[1] + iVar3 + 0x88) = 0xffffffff;
          *(u32 *)(puVar2[1] + iVar3 + 0x9c) = 0xffffffff;
          iVar3 = iVar3 + 0xa0;
        } while (uVar1 < param_3 - 8);
      }
      if (uVar1 < param_3) {
        iVar3 = uVar1 * 0x14;
        do {
          uVar1 = uVar1 + 1;
          *(u32 *)(puVar2[1] + iVar3 + 0x10) = 0xffffffff;
          iVar3 = iVar3 + 0x14;
        } while (uVar1 < param_3);
      }
    }
    *puVar2 = param_3;
  }
  return param_1;
}

// FUN_00464540 NONMATCHING

long FUN_00464540(u64 param_1)

{
  long lVar1;
  long lVar2;
  int iVar3;
  u32 uVar4;
  int iVar5;
  u32 uVar6;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_1c;
  u8 auStack_18 [4];
  u32 uStack_14;
  u8 auStack_10 [4];
  u32 uStack_c;
  u8 auStack_8 [4];
  u8 auStack_4 [4];
  
  lVar1 = ((code)FUN_004c1600)(param_1,1,auStack_4,auStack_8);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else {
    lVar1 = ((code)FUN_004c1910)(param_1,&uStack_c,4);
    if ((((lVar1 == 0) || (lVar1 = ((code)FUN_004c1910)(param_1,auStack_10,4), lVar1 == 0)) ||
        (lVar1 = ((code)FUN_004c1910)(param_1,&uStack_14,4), lVar1 == 0)) ||
       (lVar1 = ((code)FUN_004c1910)(param_1,auStack_18,4), lVar1 == 0)) {
      lVar1 = 0;
    }
    else if (uStack_c < 0x101) {
      lVar1 = ((code)FUN_00464280)(uStack_14);
      if (lVar1 == 0) {
        lVar1 = 0;
      }
      else {
        uVar6 = 0;
        if (uStack_14 != 0) {
          iVar3 = 0;
          do {
            lVar2 = ((code)FUN_004c1910)(param_1,&uStack_1c,4);
            if (lVar2 == 0) {
              return 0;
            }
            if (uStack_1c != 0) {
              lVar2 = ((code)FUN_004643b0)(lVar1,uVar6);
              if (lVar2 == 0) {
                return 0;
              }
              iVar5 = *(int *)(*(int *)((int)lVar1 + 4) + iVar3 + 4);
              uVar4 = 0;
              if (uStack_1c != 0) {
                do {
                  lVar2 = ((code)FUN_004c18b0)(param_1,iVar5,0x10);
                  if ((lVar2 == 0) || (lVar2 = ((code)FUN_004c1910)(param_1,iVar5 + 0x10,4), lVar2 == 0)) {
                    return 0;
                  }
                  uVar4 = uVar4 + 1;
                  iVar5 = iVar5 + 0x14;
                } while (uVar4 < uStack_1c);
              }
            }
            uVar6 = uVar6 + 1;
            iVar3 = iVar3 + 8;
          } while (uVar6 < uStack_14);
        }
      }
    }
    else {
      uStack_28 = 0x122;
      uStack_24 = ((code)FUN_004c1d10)(0xffffffff80000004);
      ((code)FUN_004c1c50)(&uStack_28);
      lVar1 = 0;
    }
  }
  return lVar1;
}

// FUN_0048F030 NONMATCHING

u8 FUN_0048f030(void)

{
  u8 bVar1;
  long lVar2;
  
  lVar2 = ((code)FUN_004ca520)(0,0x11f,0x48dd30,0x48dd50);
  if (lVar2 < 0) {
    bVar1 = 0;
  }
  else {
    lVar2 = ((code)FUN_00493c50)(8,0x11f,0x48ea90,0x48eab0,0x48eb50);
    DAT_007ce7b8 = (int)lVar2;
    if (lVar2 < 0) {
      bVar1 = 0;
    }
    else {
      lVar2 = ((code)FUN_00493c80)(0x11f,0x48ec20,0x48ecf0,0x48ed20);
      DAT_007ce7bc = (int)lVar2;
      if (lVar2 < 0) {
        bVar1 = 0;
      }
      else {
        DAT_007ce7c0 = ((code)FUN_00499250)(8,0x11f,0x48ea90,0x48eab0,0x48eb50);
        if (DAT_007ce7b8 < 0) {
          bVar1 = 0;
        }
        else {
          DAT_007ce7c4 = ((code)FUN_00499280)(0x11f,0x48ec20,0x48ecf0,0x48ed20);
          if (DAT_007ce7bc < 0) {
            bVar1 = 0;
          }
          else {
            lVar2 = ((code)FUN_004cb9f0)(8,0x11f,0x48ea90,0x48eab0,0x48eb50);
            DAT_007ce7c8 = (u32)lVar2;
            if (lVar2 < 0) {
              bVar1 = 0;
            }
            else {
              lVar2 = ((code)FUN_004c7d00)(0x11f,0x48ec20,0x48ecf0,0x48ed20);
              DAT_007ce7cc = (u32)lVar2;
              if (lVar2 < 0) {
                bVar1 = 0;
              }
              else {
                lVar2 = ((code)FUN_004ca000)(8,0x11f,0x48ea90,0x48eab0,0x48eb50);
                DAT_007ce7d0 = (u32)lVar2;
                if (lVar2 < 0) {
                  bVar1 = 0;
                }
                else {
                  lVar2 = ((code)FUN_004c7b60)(0x11f,0x48ec20,0x48ecf0,0x48ed20);
                  DAT_007ce7d4 = (u32)lVar2;
                  if (lVar2 < 0) {
                    bVar1 = 0;
                  }
                  else {
                    lVar2 = ((code)FUN_00494520)(8,0x11f,0x48ea90,0x48eab0,0x48eb50);
                    DAT_007ce7d8 = (u32)lVar2;
                    if (lVar2 < 0) {
                      bVar1 = 0;
                    }
                    else {
                      lVar2 = ((code)FUN_00494550)(0x11f,0x48ec20,0x48ecf0,0x48ed20);
                      DAT_007ce7dc = (u32)lVar2;
                      if (lVar2 < 0) {
                        bVar1 = 0;
                      }
                      else {
                        lVar2 = ((code)FUN_00494db0)(8,0x11f,0x48ea90,0x48eab0,0x48eb50);
                        DAT_007ce7e0 = (u32)lVar2;
                        if (lVar2 < 0) {
                          bVar1 = 0;
                        }
                        else {
                          lVar2 = ((code)FUN_00494de0)(0x11f,0x48ec20,0x48ecf0,0x48ed20);
                          DAT_007ce7e4 = (u32)lVar2;
                          if (lVar2 < 0) {
                            bVar1 = 0;
                          }
                          else {
                            lVar2 = ((code)FUN_004d13b0)(8,0x11f,0x48ea90,0x48eab0,0x48eb50);
                            DAT_007ce7e8 = (u32)lVar2;
                            if (lVar2 < 0) {
                              bVar1 = 0;
                            }
                            else {
                              lVar2 = ((code)FUN_004c81a0)(0x11f,0x48ec20,0x48ecf0,0x48ed20);
                              DAT_007ce7ec = (u32)lVar2;
                              bVar1 = -1 < lVar2;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return bVar1;
}

// FUN_0048F340 NONMATCHING

u64 FUN_0048f340(u64 param_1,int param_2)

{
  long lVar1;
  
  lVar1 = ((code)FUN_004c1910)(param_1,0x7ce804,4);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  else if ((param_2 == 8) && (lVar1 = ((code)FUN_004c1910)(param_1,0x7ce800,4), lVar1 == 0)) {
    param_1 = 0;
  }
  return param_1;
}

// FUN_0048F3C0 NONMATCHING

u64 FUN_0048f3c0(u64 param_1,u64 param_2,int param_3)

{
  long lVar1;
  
  lVar1 = ((code)FUN_004c17f0)(param_1,*(int *)(param_3 + 0x6c) + 0x2c,4);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  else {
    lVar1 = ((code)FUN_004c17f0)(param_1,*(int *)(param_3 + 0x6c) + 0x30,4);
    if (lVar1 == 0) {
      param_1 = 0;
    }
  }
  return param_1;
}

// FUN_0048F460 NONMATCHING

u64 FUN_0048f460(u64 param_1,int param_2)

{
  long lVar1;
  
  lVar1 = ((code)FUN_004c1910)(param_1,0x7ce7fc,4);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  else if ((param_2 == 8) && (lVar1 = ((code)FUN_004c1910)(param_1,0x7ce7f8,4), lVar1 == 0)) {
    param_1 = 0;
  }
  return param_1;
}

// FUN_0048F4E0 NONMATCHING

u64 FUN_0048f4e0(u64 param_1,u64 param_2,int param_3)

{
  long lVar1;
  
  lVar1 = ((code)FUN_004c17f0)(param_1,*(int *)(param_3 + 0x7c) + 0x2c,4);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  else {
    lVar1 = ((code)FUN_004c17f0)(param_1,*(int *)(param_3 + 0x7c) + 0x30,4);
    if (lVar1 == 0) {
      param_1 = 0;
    }
  }
  return param_1;
}

// FUN_0048F580 NONMATCHING

u32 * FUN_0048f580(u64 param_1,int *param_2,int param_3,u32 param_4)

{
  int iVar1;
  u8 bVar2;
  u32 *puVar3;
  long lVar4;
  int iVar5;
  u16 *puVar6;
  int iVar7;
  u32 *puVar8;
  u16 auStack_80 [2];
  int iStack_7c;
  int iStack_78;
  u32 uStack_74;
  u32 uStack_70;
  u32 uStack_6c;
  u32 uStack_68;
  u32 uStack_64;
  u32 uStack_60;
  u16 uStack_48;
  u16 uStack_46;
  u16 uStack_44;
  u16 uStack_42;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_4;
  
  bVar2 = 1;
  lVar4 = ((code)FUN_004c1600)(param_1,1,0,&uStack_4);
  if (lVar4 == 0) {
    puVar3 = (u32 *)0x0;
  }
  else if ((uStack_4 < 0x35000) || (0x37002 < uStack_4)) {
    uStack_10 = 2;
    uStack_c = ((code)FUN_004c1d10)(0xffffffff80000004);
    ((code)FUN_004c1c50)(&uStack_10);
    puVar3 = (u32 *)0x0;
  }
  else {
    lVar4 = ((code)FUN_004c5250)(param_1,auStack_80,0x2c);
    if (lVar4 == 0x2c) {
      puVar3 = (u32 *)*param_2;
      *param_2 = (int)puVar3 + DAT_0077ddb0;
      if (puVar3 == (u32 *)0x0) {
        uStack_18 = 2;
        uStack_14 = ((code)FUN_004c1d10)(0xffffffff80000013,DAT_0077ddb0);
        ((code)FUN_004c1c50)(&uStack_18);
        puVar3 = (u32 *)0x0;
      }
      else {
        *puVar3 = 0xffffffff;
        puVar3[0x1b] = uStack_74;
        puVar3[0x1c] = uStack_70;
        puVar3[0x1d] = uStack_6c;
        puVar3[0x18] = uStack_68;
        puVar3[0x19] = uStack_64;
        puVar3[0x1a] = uStack_60;
        *(u16 *)(puVar3 + 0x20) = auStack_80[0];
        *(short *)(puVar3 + 0x21) = (short)iStack_7c;
        *(short *)((int)puVar3 + 0x82) = (short)iStack_78;
        puVar3[1] = 0;
        puVar3[2] = 0;
        puVar3[0xc] = 0;
        puVar3[3] = 0;
        ((code)FUN_00521408)(puVar3 + 4,0,0x20);
        puVar3[0x1f] = 0;
        puVar3[0xd] = 0;
        puVar3[0x1e] = 0;
        puVar3[0xe] = (u32)(puVar3 + 0xe);
        puVar3[0xf] = (u32)(puVar3 + 0xe);
        puVar3[0x10] = (u32)(puVar3 + 0x10);
        puVar3[0x11] = (u32)(puVar3 + 0x10);
        if ((*(u32 *)(param_3 + 8) & 0x1000000) == 0) {
          if (iStack_78 != 0) {
            iVar5 = *param_2;
            iVar7 = iStack_78 * 0xc;
            *param_2 = iVar5 + iVar7;
            puVar3[2] = iVar5;
            iVar5 = puVar3[2];
            if (iVar5 == 0) {
              uStack_20 = 2;
              uStack_1c = ((code)FUN_004c1d10)(0xffffffff80000013,iVar7);
              ((code)FUN_004c1c50)(&uStack_20);
            }
            bVar2 = iVar5 != 0;
            if ((bVar2) && (lVar4 = ((code)FUN_004c18b0)(param_1,puVar3[2],iVar7), lVar4 == 0)) {
              bVar2 = 0;
            }
            if ((bVar2) && ((param_4 & 0x10) != 0)) {
              iVar5 = *param_2;
              iVar7 = iStack_78 * 4;
              *param_2 = iVar5 + iVar7;
              puVar3[3] = iVar5;
              if (puVar3[3] == 0) {
                uStack_28 = 2;
                uStack_24 = ((code)FUN_004c1d10)(0xffffffff80000013,iVar7);
                ((code)FUN_004c1c50)(&uStack_28);
                bVar2 = 0;
              }
              if ((bVar2) && (iVar5 = ((code)FUN_004c5250)(param_1,puVar3[3],iVar7), iVar7 != iVar5)) {
                bVar2 = 0;
              }
            }
            if ((bVar2) && ((param_4 & 8) != 0)) {
              iVar5 = *param_2;
              iVar7 = iStack_78 * 4;
              *param_2 = iVar5 + iVar7;
              puVar3[0xc] = iVar5;
              if (puVar3[0xc] == 0) {
                uStack_30 = 2;
                uStack_2c = ((code)FUN_004c1d10)(0xffffffff80000013,iVar7);
                ((code)FUN_004c1c50)(&uStack_30);
                bVar2 = 0;
              }
              if ((bVar2) && (lVar4 = ((code)FUN_004c5250)(param_1,puVar3[0xc],iVar7), lVar4 == 0)) {
                bVar2 = 0;
              }
            }
            if ((bVar2) && (0 < *(int *)(param_3 + 0x20))) {
              iVar5 = 0;
              iVar7 = (u32)*(u16 *)((int)puVar3 + 0x82) * 8;
              puVar8 = puVar3;
              if (0 < *(int *)(param_3 + 0x20)) {
                do {
                  iVar1 = *param_2;
                  *param_2 = iVar1 + iVar7;
                  puVar8[4] = iVar1;
                  if (puVar8[4] == 0) {
                    uStack_38 = 2;
                    uStack_34 = ((code)FUN_004c1d10)(0xffffffff80000013,iVar7);
                    ((code)FUN_004c1c50)(&uStack_38);
                    bVar2 = 0;
                    break;
                  }
                  lVar4 = ((code)FUN_004c18b0)(param_1,puVar8[4],iVar7);
                  if (lVar4 == 0) {
                    bVar2 = 0;
                    break;
                  }
                  iVar5 = iVar5 + 1;
                  puVar8 = puVar8 + 1;
                } while (iVar5 < *(int *)(param_3 + 0x20));
              }
            }
          }
          if ((bVar2) && (iStack_7c != 0)) {
            iVar5 = *param_2;
            iVar7 = iStack_7c * 8;
            *param_2 = iVar5 + iVar7;
            puVar3[1] = iVar5;
            if (puVar3[1] == 0) {
              uStack_40 = 2;
              uStack_3c = ((code)FUN_004c1d10)(0xffffffff80000013,iVar7);
              ((code)FUN_004c1c50)(&uStack_40);
              bVar2 = 0;
            }
            if ((bVar2) && (lVar4 = ((code)FUN_004c1850)(param_1,puVar3[1],iVar7), lVar4 == 0)) {
              bVar2 = 0;
            }
            if (((bVar2) && (uStack_4 < 0x36002)) && (iVar5 = 0, 0 < iStack_7c)) {
              iVar7 = 0;
              do {
                iVar5 = iVar5 + 1;
                puVar6 = (u16 *)(puVar3[1] + iVar7);
                uStack_46 = puVar6[1];
                uStack_42 = puVar6[3];
                uStack_48 = *puVar6;
                uStack_44 = puVar6[2];
                *puVar6 = uStack_46;
                *(u16 *)(puVar3[1] + iVar7 + 2) = uStack_44;
                *(u16 *)(puVar3[1] + iVar7 + 4) = uStack_42;
                *(u16 *)(puVar3[1] + iVar7 + 6) = uStack_48;
                iVar7 = iVar7 + 8;
              } while (iVar5 < iStack_7c);
            }
          }
        }
        if (bVar2) {
          ((code)FUN_004c64b0)(0x77ddb0,puVar3);
          DAT_007ce7fc = 0;
          DAT_007ce7f8 = 0;
          lVar4 = ((code)FUN_004c5a50)(0x77ddb0,param_1,puVar3);
          if (lVar4 == 0) {
            bVar2 = 0;
          }
          if ((bVar2) && (DAT_007ce7fc != 0)) {
            ((code)FUN_004c5c30)(0x77ddb0,DAT_007ce7fc,puVar3,DAT_007ce7f8);
          }
        }
        if (!bVar2) {
          if ((*(u8 *)(param_3 + 3) & 1) == 0) {
            ((code)FUN_00499850)(puVar3);
          }
          else {
            ((code)FUN_00499720)(puVar3);
          }
          puVar3 = (u32 *)0x0;
        }
      }
    }
    else {
      puVar3 = (u32 *)0x0;
    }
  }
  return puVar3;
}

// FUN_0048FBD0 NONMATCHING

u32 * FUN_0048fbd0(u64 param_1,u64 param_2,u64 param_3,u32 param_4)

{
  u8 bVar1;
  int iVar2;
  u32 *puVar3;
  long lVar4;
  u32 uStack_50;
  u32 uStack_4c;
  int iStack_48;
  int iStack_44;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  int iStack_4;
  
  lVar4 = ((code)FUN_004c1600)(param_1,1,&iStack_4,&uStack_8);
  if (lVar4 == 0) {
    puVar3 = (u32 *)0x0;
  }
  else if ((uStack_8 < 0x35000) || (0x37002 < uStack_8)) {
    uStack_10 = 2;
    uStack_c = ((code)FUN_004c1d10)(0xffffffff80000004);
    ((code)FUN_004c1c50)(&uStack_10);
    puVar3 = (u32 *)0x0;
  }
  else {
    ((code)FUN_00521408)(&uStack_50,0,0x18);
    iVar2 = ((code)FUN_004c5250)(param_1,&uStack_50,iStack_4);
    if (iStack_4 == iVar2) {
      puVar3 = (u32 *)*(int *)param_2;
      *(int *)param_2 = (int)(puVar3 + 6);
      if (puVar3 == (u32 *)0x0) {
        uStack_18 = 2;
        uStack_14 = ((code)FUN_004c1d10)(0xffffffff80000013,0x18);
        ((code)FUN_004c1c50)(&uStack_18);
        puVar3 = (u32 *)0x0;
      }
      else {
        *puVar3 = uStack_50;
        puVar3[1] = uStack_4c;
        if ((param_4 & 0x40000000) == 0) {
          puVar3[4] = uStack_4c;
          puVar3[5] = uStack_4c;
        }
        else {
          puVar3[4] = uStack_40;
          puVar3[5] = uStack_3c;
        }
        if (iStack_48 == 0) {
          lVar4 = ((code)FUN_004c1600)(param_1,10,0,&uStack_8);
          bVar1 = lVar4 != 0;
          if ((bVar1) && ((uStack_8 < 0x35000 || (0x37002 < uStack_8)))) {
            uStack_28 = 2;
            uStack_24 = ((code)FUN_004c1d10)(0xffffffff80000004);
            ((code)FUN_004c1c50)(&uStack_28);
            bVar1 = 0;
          }
          if (bVar1) {
            lVar4 = ((code)FUN_0048fbd0)(param_1,param_2,param_3,param_4);
            puVar3[2] = (int)lVar4;
            if (lVar4 == 0) {
              bVar1 = 0;
            }
          }
        }
        else {
          lVar4 = ((code)FUN_004c1600)(param_1,9,0,&uStack_8);
          bVar1 = lVar4 != 0;
          if ((bVar1) && ((uStack_8 < 0x35000 || (0x37002 < uStack_8)))) {
            uStack_20 = 2;
            uStack_1c = ((code)FUN_004c1d10)(0xffffffff80000004);
            ((code)FUN_004c1c50)(&uStack_20);
            bVar1 = 0;
          }
          if (bVar1) {
            lVar4 = ((code)FUN_0048f580)(param_1,param_2,param_3,param_4);
            puVar3[2] = (int)lVar4;
            if (lVar4 == 0) {
              bVar1 = 0;
            }
          }
        }
        if (bVar1) {
          if (iStack_44 == 0) {
            lVar4 = ((code)FUN_004c1600)(param_1,10,0,&uStack_8);
            if (lVar4 == 0) {
              bVar1 = 0;
            }
            if ((bVar1) && ((uStack_8 < 0x35000 || (0x37002 < uStack_8)))) {
              uStack_38 = 2;
              uStack_34 = ((code)FUN_004c1d10)(0xffffffff80000004);
              ((code)FUN_004c1c50)(&uStack_38);
              bVar1 = 0;
            }
            if (bVar1) {
              lVar4 = ((code)FUN_0048fbd0)(param_1,param_2,param_3,param_4);
              puVar3[3] = (int)lVar4;
              if (lVar4 == 0) {
                bVar1 = 0;
              }
            }
          }
          else {
            lVar4 = ((code)FUN_004c1600)(param_1,9,0,&uStack_8);
            if (lVar4 == 0) {
              bVar1 = 0;
            }
            if ((bVar1) && ((uStack_8 < 0x35000 || (0x37002 < uStack_8)))) {
              uStack_30 = 2;
              uStack_2c = ((code)FUN_004c1d10)(0xffffffff80000004);
              ((code)FUN_004c1c50)(&uStack_30);
              bVar1 = 0;
            }
            if (bVar1) {
              lVar4 = ((code)FUN_0048f580)(param_1,param_2,param_3,param_4);
              puVar3[3] = (int)lVar4;
              if (lVar4 == 0) {
                bVar1 = 0;
              }
            }
          }
        }
        if (!bVar1) {
          if (puVar3[2] != 0) {
            if ((*(u8 *)((int)param_3 + 3) & 1) == 0) {
              ((code)FUN_00499850)();
              puVar3[2] = 0;
            }
            else {
              ((code)FUN_00499720)();
              puVar3[2] = 0;
            }
          }
          puVar3 = (u32 *)0x0;
        }
      }
    }
    else {
      puVar3 = (u32 *)0x0;
    }
  }
  return puVar3;
}

// FUN_00490050 NONMATCHING

long FUN_00490050(u64 param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  u8 *puVar4;
  u32 uVar5;
  int iVar6;
  int iStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_74;
  int iStack_70;
  int iStack_6c;
  int iStack_68;
  int iStack_64;
  int iStack_60;
  u32 uStack_5c;
  u32 uStack_58;
  u32 uStack_54;
  u32 uStack_50;
  u32 uStack_4c;
  u32 uStack_48;
  u32 uStack_44;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  int iStack_8;
  u8 *puStack_4;
  
  lVar2 = ((code)FUN_004c1600)(param_1,1,&iStack_8,&uStack_c);
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  else if ((uStack_c < 0x35000) || (0x37002 < uStack_c)) {
    uStack_18 = 2;
    uStack_14 = ((code)FUN_004c1d10)(0xffffffff80000004);
    ((code)FUN_004c1c50)(&uStack_18);
    lVar2 = 0;
  }
  else {
    ((code)FUN_00521408)(&iStack_80,0,0x40);
    iVar1 = ((code)FUN_004c5250)(param_1,&iStack_80,iStack_8);
    if (iStack_8 == iVar1) {
      if (iStack_60 < 1) {
        iVar1 = DAT_0077ddd0 + iStack_68 * 0x18 + iStack_64 * DAT_0077ddb0;
        if ((uStack_5c & 0xff0000) == 0) {
          if ((uStack_5c & 0x80) == 0) {
            uVar5 = (u32)((uStack_5c & 4) != 0);
          }
          else {
            uVar5 = 2;
          }
        }
        else {
          uVar5 = (int)(uStack_5c & 0xff0000) >> 0x10;
        }
        if ((uStack_5c & 0x1000000) == 0) {
          iVar1 = iVar1 + iStack_6c * 0xc;
          if ((uStack_5c & 0x10) != 0) {
            iVar1 = iVar1 + iStack_6c * 4;
          }
          if ((uStack_5c & 8) != 0) {
            iVar1 = iVar1 + iStack_6c * 4;
          }
          if (uVar5 != 0) {
            iVar1 = iVar1 + uVar5 * iStack_6c * 8;
          }
          iVar1 = iVar1 + iStack_70 * 8;
        }
        lVar2 = (*DAT_00960178)(iVar1,0x3000b);
        if (lVar2 == 0) {
          uStack_28 = 2;
          uStack_24 = ((code)FUN_004c1d10)(0xffffffff80000013,iVar1);
          ((code)FUN_004c1c50)(&uStack_28);
          lVar2 = 0;
        }
        else {
          ((code)FUN_00521408)(lVar2,0,iVar1);
          puVar4 = (u8 *)lVar2;
          puStack_4 = puVar4 + DAT_0077ddd0;
          *puVar4 = 7;
          puVar4[1] = 0;
          puVar4[2] = 0;
          puVar4[3] = 0;
          *(u32 *)(puVar4 + 4) = 0;
          puVar4[3] = 1;
          ((code)FUN_00499e90)(lVar2,iVar1);
          *(u32 *)(puVar4 + 8) = uStack_5c;
          *(u32 *)(puVar4 + 0xc) = 2;
          *(float *)(puVar4 + 0x44) = fStack_7c * -1.0;
          *(float *)(puVar4 + 0x48) = fStack_78 * -1.0;
          *(float *)(puVar4 + 0x4c) = fStack_74 * -1.0;
          *(u32 *)(puVar4 + 0x20) = uVar5;
          *(u32 *)(puVar4 + 0x1c) = 0;
          *(u32 *)(puVar4 + 0x6c) = 0;
          *(u8 **)(puVar4 + 0x2c) = puVar4 + 0x2c;
          *(u8 **)(puVar4 + 0x30) = puVar4 + 0x2c;
          *(u8 **)(puVar4 + 0x34) = puVar4 + 0x34;
          *(u8 **)(puVar4 + 0x38) = puVar4 + 0x34;
          *(u8 **)(puVar4 + 0x3c) = puVar4 + 0x3c;
          *(u8 **)(puVar4 + 0x40) = puVar4 + 0x3c;
          lVar3 = ((code)FUN_004c1600)(param_1,8,0,&uStack_10);
          if (lVar3 == 0) {
            ((code)FUN_0049a290)(lVar2);
            lVar2 = 0;
          }
          else if ((uStack_10 < 0x35000) || (0x37002 < uStack_10)) {
            uStack_30 = 2;
            uStack_2c = ((code)FUN_004c1d10)(0xffffffff80000004);
            ((code)FUN_004c1c50)(&uStack_30);
            ((code)FUN_0049a290)(lVar2);
            lVar2 = 0;
          }
          else {
            lVar3 = ((code)FUN_004954c0)(param_1,puVar4 + 0x10);
            if (lVar3 == 0) {
              ((code)FUN_0049a290)(lVar2);
              lVar2 = 0;
            }
            else {
              if (iStack_80 == 0) {
                lVar3 = ((code)FUN_004c1600)(param_1,10,0,&uStack_10);
                if (lVar3 == 0) {
                  ((code)FUN_0049a290)(lVar2);
                  return 0;
                }
                if ((uStack_10 < 0x35000) || (0x37002 < uStack_10)) {
                  uStack_40 = 2;
                  uStack_3c = ((code)FUN_004c1d10)(0xffffffff80000004);
                  ((code)FUN_004c1c50)(&uStack_40);
                  ((code)FUN_0049a290)(lVar2);
                  return 0;
                }
                lVar3 = ((code)FUN_0048fbd0)(param_1,&puStack_4,lVar2,uStack_5c);
                *(int *)(puVar4 + 0x1c) = (int)lVar3;
                if (lVar3 == 0) {
                  ((code)FUN_0049a290)(lVar2);
                  return 0;
                }
              }
              else {
                lVar3 = ((code)FUN_004c1600)(param_1,9,0,&uStack_10);
                if (lVar3 == 0) {
                  ((code)FUN_0049a290)(lVar2);
                  return 0;
                }
                if ((uStack_10 < 0x35000) || (0x37002 < uStack_10)) {
                  uStack_38 = 2;
                  uStack_34 = ((code)FUN_004c1d10)(0xffffffff80000004);
                  ((code)FUN_004c1c50)(&uStack_38);
                  ((code)FUN_0049a290)(lVar2);
                  return 0;
                }
                lVar3 = ((code)FUN_0048f580)(param_1,&puStack_4,lVar2,uStack_5c);
                *(int *)(puVar4 + 0x1c) = (int)lVar3;
                if (lVar3 == 0) {
                  ((code)FUN_0049a290)(lVar2);
                  return 0;
                }
              }
              *(u32 *)(puVar4 + 0x24) = 0;
              *(u8 **)(puVar4 + 0x28) = puVar4 + 0x2c;
              *(u32 *)(puVar4 + 0x50) = uStack_58;
              *(u32 *)(puVar4 + 0x54) = uStack_54;
              *(u32 *)(puVar4 + 0x58) = uStack_50;
              *(u32 *)(puVar4 + 0x5c) = uStack_4c;
              *(u32 *)(puVar4 + 0x60) = uStack_48;
              *(u32 *)(puVar4 + 100) = uStack_44;
              ((code)FUN_00499d30)(lVar2);
              ((code)FUN_0049a3d0)(lVar2,0);
              iVar1 = 0;
              if (0 < *(int *)(puVar4 + 0x14)) {
                iVar6 = 0;
                do {
                  if (**(int **)(*(int *)(puVar4 + 0x10) + iVar6) != 0) {
                    ((code)FUN_00494d50)();
                  }
                  iVar1 = iVar1 + 1;
                  iVar6 = iVar6 + 4;
                } while (iVar1 < *(int *)(puVar4 + 0x14));
              }
              ((code)FUN_004c64b0)(0x77ddd0,lVar2);
              iGpffffbb14 = 0;
              uGpffffbb10 = 0;
              lVar3 = ((code)FUN_004c5a50)(0x77ddd0,param_1,lVar2);
              if (lVar3 == 0) {
                ((code)FUN_0049a290)(lVar2);
                lVar2 = 0;
              }
              else {
                if (iGpffffbb14 != 0) {
                  ((code)FUN_004c5c30)(0x77ddd0,iGpffffbb14,lVar2,uGpffffbb10);
                }
                lVar3 = ((code)FUN_0049a080)(lVar2);
                if (lVar3 == 0) {
                  ((code)FUN_0049a290)(lVar2);
                  lVar2 = 0;
                }
              }
            }
          }
        }
      }
      else {
        uStack_20 = 2;
        uStack_1c = ((code)FUN_004c1d10)(0xffffffff80000004);
        ((code)FUN_004c1c50)(&uStack_20);
        lVar2 = 0;
      }
    }
    else {
      lVar2 = 0;
    }
  }
  return lVar2;
}

// FUN_00490770 NONMATCHING

u64 FUN_00490770(u64 param_1,u64 param_2,int param_3)

{
  long lVar1;
  
  lVar1 = ((code)FUN_004c17f0)(param_1,*(int *)(param_3 + 0x6c) + 0x2c,4);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  else {
    lVar1 = ((code)FUN_004c17f0)(param_1,*(int *)(param_3 + 0x6c) + 0x30,4);
    if (lVar1 == 0) {
      param_1 = 0;
    }
  }
  return param_1;
}

// FUN_00490810 NONMATCHING

u64 FUN_00490810(u64 param_1)

{
  u8 bVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if ((*(u32 *)(iVar2 + 0x4c) & 2) == 0) {
    bVar1 = *(u8 *)(iVar2 + 3);
  }
  else {
    ((code)FUN_00491100)();
    bVar1 = *(u8 *)(iVar2 + 3);
  }
  *(u8 *)(iVar2 + 3) = bVar1 | 1;
  return param_1;
}

// FUN_00490860 NONMATCHING

u64 FUN_00490860(u64 param_1)

{
  long lVar1;
  int iVar2;
  
  iVar2 = *(int *)((int)param_1 + 0x6c);
  if (iVar2 == 0) {
    iVar2 = *(int *)((u8 *)DAT_009600ac + iGpffffbe38);
  }
  lVar1 = ((code)FUN_004f2e70)(iVar2,param_1,1);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  return param_1;
}

// FUN_004908D0 NONMATCHING

u64 FUN_004908d0(u64 param_1,int param_2)

{
  int iVar1;
  long lVar2;
  u32 uStack_8;
  u32 uStack_4;
  
  lVar2 = ((code)FUN_00491b40)();
  if (lVar2 == 0) {
    *(u32 *)(param_2 + 8) = 0;
    param_1 = 0;
  }
  else {
    iVar1 = *(int *)((int)param_1 + 4);
    if (iVar1 == 0) {
      ((code)FUN_00491a80)(lVar2);
      uStack_8 = 2;
      uStack_4 = ((code)FUN_004c1d10)(5);
      ((code)FUN_004c1c50)(&uStack_8);
      param_1 = 0;
    }
    else {
      ((code)FUN_00492d10)(lVar2,*(u32 *)(iVar1 + 0xa0));
      ((code)FUN_00491ff0)(*(u32 *)(param_2 + 4),lVar2);
    }
  }
  return param_1;
}

// FUN_00490980 NONMATCHING

u64 FUN_00490980(u64 param_1,u64 param_2)

{
  long lVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_c;
  u8 auStack_8 [4];
  int iStack_4;
  
  lVar1 = ((code)FUN_004c1600)(param_1,1,auStack_8,&uStack_c);
  if (lVar1 == 0) {
    param_2 = 0;
  }
  else if ((uStack_c < 0x35000) || (0x37002 < uStack_c)) {
    uStack_20 = 2;
    uStack_1c = ((code)FUN_004c1d10)(0xffffffff80000004);
    ((code)FUN_004c1c50)(&uStack_20);
    param_2 = 0;
  }
  else {
    lVar1 = ((code)FUN_004c5250)(param_1,&iStack_4,4);
    if (lVar1 == 4) {
      piVar2 = (int *)param_2;
      piVar2[1] = 0;
      if (iStack_4 < 1) {
        *piVar2 = 0;
      }
      else {
        iVar4 = (*DAT_00960178)(iStack_4 << 2,0x3000f);
        *piVar2 = iVar4;
        if (*piVar2 == 0) {
          uStack_18 = 2;
          uStack_14 = ((code)FUN_004c1d10)(0xffffffff80000013,iStack_4 << 2);
          ((code)FUN_004c1c50)(&uStack_18);
          return 0;
        }
      }
      iVar4 = 0;
      if (0 < iStack_4) {
        iVar3 = 0;
        do {
          lVar1 = ((code)FUN_004c1600)(param_1,0xf,0,&uStack_c);
          if (lVar1 == 0) {
            iVar4 = 0;
            if (piVar2[1] < 1) {
              iVar4 = *piVar2;
            }
            else {
              iVar3 = 0;
              do {
                ((code)FUN_00493b60)(*(u32 *)(*piVar2 + iVar3));
                iVar4 = iVar4 + 1;
                iVar3 = iVar3 + 4;
              } while (iVar4 < piVar2[1]);
              iVar4 = *piVar2;
            }
            if (iVar4 != 0) {
              (*DAT_0096017c)();
              *piVar2 = 0;
            }
            return 0;
          }
          if ((uStack_c < 0x35000) || (0x37002 < uStack_c)) {
            iVar4 = 0;
            if (piVar2[1] < 1) {
              iVar4 = *piVar2;
            }
            else {
              iVar3 = 0;
              do {
                ((code)FUN_00493b60)(*(u32 *)(*piVar2 + iVar3));
                iVar4 = iVar4 + 1;
                iVar3 = iVar3 + 4;
              } while (iVar4 < piVar2[1]);
              iVar4 = *piVar2;
            }
            if (iVar4 != 0) {
              (*DAT_0096017c)();
              *piVar2 = 0;
            }
            return 0;
          }
          lVar1 = ((code)FUN_00493cb0)(param_1);
          *(int *)(*piVar2 + iVar3) = (int)lVar1;
          if (lVar1 == 0) {
            iVar4 = 0;
            if (piVar2[1] < 1) {
              iVar4 = *piVar2;
            }
            else {
              iVar3 = 0;
              do {
                ((code)FUN_00493b60)(*(u32 *)(*piVar2 + iVar3));
                iVar4 = iVar4 + 1;
                iVar3 = iVar3 + 4;
              } while (iVar4 < piVar2[1]);
              iVar4 = *piVar2;
            }
            if (iVar4 != 0) {
              (*DAT_0096017c)();
              *piVar2 = 0;
            }
            return 0;
          }
          iVar4 = iVar4 + 1;
          piVar2[1] = piVar2[1] + 1;
          iVar3 = iVar3 + 4;
        } while (iVar4 < iStack_4);
      }
    }
    else {
      param_2 = 0;
    }
  }
  return param_2;
}

// FUN_00490D00 NONMATCHING

u64 FUN_00490d00(u64 param_1)

{
  ((code)FUN_00492020)(*(u32 *)((int)param_1 + iGpffffbb24),param_1);
  ((code)FUN_00494760)(param_1);
  return param_1;
}

#pragma schedule on
// FUN_00490D40 NONMATCHING

u32 FUN_00490d40(int param_1)

{
  int iVar1;
  
  iVar1 = param_1;
  FUN_00492060_typed(*(u32 *)(iVar1 + iGpffffbb20),(u32)param_1);
  FUN_004ca030_typed((u32)param_1);
  return param_1;
}
#pragma schedule off

#pragma optimization_level 3
// FUN_00490D90

u64 FUN_00490d90(u64 param_1)

{
  FUN_00491a80(param_1);
  return param_1;
}
#pragma optimization_level 2

// FUN_00490DC0 NONMATCHING

long FUN_00490dc0(u64 param_1,int *param_2,int *param_3)

{
  int iVar1;
  long lVar2;
  long lVar3;
  int iStack_50;
  int iStack_4c;
  u8 uStack_48;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  int iStack_4;
  
  lVar2 = ((code)FUN_004c1600)(param_1,1,&iStack_4,&uStack_8);
  if (lVar2 == 0) {
    uStack_10 = 2;
    uStack_c = ((code)FUN_004c1d10)(0xffffffff8000001a);
    ((code)FUN_004c1c50)(&uStack_10);
    lVar2 = 0;
  }
  else if ((uStack_8 < 0x35000) || (0x37002 < uStack_8)) {
    uStack_40 = 2;
    uStack_3c = ((code)FUN_004c1d10)(0xffffffff80000004);
    ((code)FUN_004c1c50)(&uStack_40);
    lVar2 = 0;
  }
  else {
    ((code)FUN_00521408)(&iStack_50,0,0x10);
    iVar1 = ((code)FUN_004c5250)(param_1,&iStack_50,iStack_4);
    if (iStack_4 == iVar1) {
      lVar2 = ((code)FUN_00491880)();
      if (lVar2 == 0) {
        lVar2 = 0;
      }
      else {
        *(u8 *)((int)lVar2 + 2) = uStack_48;
        if (param_2[1] == 0) {
          iVar1 = param_3[1];
        }
        else {
          ((code)FUN_00492d10)(lVar2,*(u32 *)(*param_2 + iStack_50 * 4));
          iVar1 = param_3[1];
        }
        if (iVar1 == 0) {
          lVar3 = ((code)FUN_004c1600)(param_1,0xf,0,&uStack_8);
          if (lVar3 == 0) {
            ((code)FUN_00491a80)(lVar2);
            uStack_20 = 2;
            uStack_1c = ((code)FUN_004c1d10)(0xffffffff8000001a);
            ((code)FUN_004c1c50)(&uStack_20);
            return 0;
          }
          if ((uStack_8 < 0x35000) || (0x37002 < uStack_8)) {
            ((code)FUN_00491a80)(lVar2);
            uStack_30 = 2;
            uStack_2c = ((code)FUN_004c1d10)(0xffffffff80000004);
            ((code)FUN_004c1c50)(&uStack_30);
            return 0;
          }
          lVar3 = ((code)FUN_00493cb0)(param_1);
          if (lVar3 == 0) {
            ((code)FUN_00491a80)(lVar2);
            uStack_28 = 2;
            uStack_24 = ((code)FUN_004c1d10)(0xffffffff8000001a);
            ((code)FUN_004c1c50)(&uStack_28);
            return 0;
          }
          ((code)FUN_004919b0)(lVar2,lVar3,0);
          ((code)FUN_00493b60)(lVar3);
        }
        else {
          ((code)FUN_004919b0)(lVar2,*(u32 *)(*param_3 + iStack_4c * 4),0);
        }
        iGpffffbb2c = 0;
        uGpffffbb28 = 0;
        lVar3 = ((code)FUN_004c5a50)(0x77dce0,param_1,lVar2);
        if (lVar3 == 0) {
          uStack_38 = 2;
          uStack_34 = ((code)FUN_004c1d10)(0xffffffff8000001a);
          ((code)FUN_004c1c50)(&uStack_38);
          lVar2 = 0;
        }
        else if (iGpffffbb2c != 0) {
          ((code)FUN_004c5c30)(0x77dce0,iGpffffbb2c,lVar2,uGpffffbb28);
        }
      }
    }
    else {
      uStack_18 = 2;
      uStack_14 = ((code)FUN_004c1d10)(0xffffffff8000001a);
      ((code)FUN_004c1c50)(&uStack_18);
      lVar2 = 0;
    }
  }
  return lVar2;
}

// FUN_00491100 NONMATCHING

void FUN_00491100(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  u32 uVar6;
  u32 uVar7;
  float fVar8;
  u32 uVar9;
  
  iVar2 = *(int *)(param_1 + 0x18);
  if (iVar2 != 0) {
    lVar5 = (long)*(short *)(param_1 + 0x52);
    sVar1 = *(short *)(param_1 + 0x50);
    lVar4 = (long)sVar1;
    if (((lVar4 == lVar5) || (*(int *)(iVar2 + 0x18) <= lVar4)) || (*(int *)(iVar2 + 0x18) <= lVar5)
       ) {
      if ((lVar4 < *(int *)(iVar2 + 0x18)) && (lVar5 < *(int *)(iVar2 + 0x18))) {
        iVar2 = sVar1 * 0x1c + *(int *)(iVar2 + 0x5c);
        uVar9 = *(u32 *)(iVar2 + 8);
        uVar6 = *(u32 *)(iVar2 + 0xc);
        uVar7 = *(u32 *)(iVar2 + 0x10);
        *(u32 *)(param_1 + 0x1c) = *(u32 *)(iVar2 + 4);
        *(u32 *)(param_1 + 0x20) = uVar9;
        *(u32 *)(param_1 + 0x24) = uVar6;
        *(u32 *)(param_1 + 0x28) = uVar7;
      }
      else {
        iVar2 = *(int *)(iVar2 + 0x5c);
        uVar9 = *(u32 *)(iVar2 + 8);
        uVar6 = *(u32 *)(iVar2 + 0xc);
        uVar7 = *(u32 *)(iVar2 + 0x10);
        *(u32 *)(param_1 + 0x1c) = *(u32 *)(iVar2 + 4);
        *(u32 *)(param_1 + 0x20) = uVar9;
        *(u32 *)(param_1 + 0x24) = uVar6;
        *(u32 *)(param_1 + 0x28) = uVar7;
      }
    }
    else {
      iVar3 = *(int *)(iVar2 + 0x5c) + sVar1 * 0x1c;
      iVar2 = *(int *)(iVar2 + 0x5c) + *(short *)(param_1 + 0x52) * 0x1c;
      fVar8 = *(float *)(param_1 + 0x58) * *(float *)(param_1 + 0x5c);
      *(float *)(param_1 + 0x28) =
           fVar8 * (*(float *)(iVar2 + 0x10) - *(float *)(iVar3 + 0x10)) +
           *(float *)(iVar3 + 0x10) + 0.0;
      *(float *)(param_1 + 0x1c) = *(float *)(iVar2 + 4) - *(float *)(iVar3 + 4);
      *(float *)(param_1 + 0x20) = *(float *)(iVar2 + 8) - *(float *)(iVar3 + 8);
      *(float *)(param_1 + 0x24) = *(float *)(iVar2 + 0xc) - *(float *)(iVar3 + 0xc);
      *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 0x1c) * fVar8;
      *(float *)(param_1 + 0x20) = *(float *)(param_1 + 0x20) * fVar8;
      *(float *)(param_1 + 0x24) = *(float *)(param_1 + 0x24) * fVar8;
      *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 0x1c) + *(float *)(iVar3 + 4);
      *(float *)(param_1 + 0x20) = *(float *)(param_1 + 0x20) + *(float *)(iVar3 + 8);
      *(float *)(param_1 + 0x24) = *(float *)(param_1 + 0x24) + *(float *)(iVar3 + 0xc);
    }
    *(u32 *)(param_1 + 0x4c) = *(u32 *)(param_1 + 0x4c) & 0xfffffffd;
    *(u8 *)(param_1 + 3) = *(u8 *)(param_1 + 3) | 1;
  }
  return;
}

// FUN_004912B0 NONMATCHING

int FUN_004912b0(int param_1)

{
  u32 uVar1;
  long lVar2;
  u64 uVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  uVar1 = *(u32 *)(param_1 + 4);
  if ((*(u32 *)(param_1 + 0x4c) & 2) != 0) {
    ((code)FUN_00491100)();
  }
  lVar2 = ((code)FUN_004cae30)(uVar1);
  if ((lVar2 != 0) || ((*(u8 *)(param_1 + 3) & 1) != 0)) {
    uVar3 = ((code)FUN_004cb2f0)(uVar1);
    ((code)FUN_004c6be0)(param_1 + 0x2c,param_1 + 0x1c,uVar3);
    pfVar4 = (float *)uVar3;
    if (((u32)pfVar4[3] & 3) == 3) {
      *(u32 *)(param_1 + 0x38) = *(u32 *)(param_1 + 0x28);
    }
    else {
      fVar8 = pfVar4[2] * pfVar4[2] + *pfVar4 * *pfVar4 + pfVar4[1] * pfVar4[1];
      fVar7 = pfVar4[6] * pfVar4[6] + pfVar4[4] * pfVar4[4] + pfVar4[5] * pfVar4[5];
      fVar5 = pfVar4[10] * pfVar4[10] + pfVar4[8] * pfVar4[8] + pfVar4[9] * pfVar4[9];
      fVar6 = fVar7;
      if (fVar7 < fVar5) {
        fVar6 = fVar5;
      }
      if ((fVar8 < fVar6) && (fVar8 = fVar7, fVar7 < fVar5)) {
        fVar8 = fVar5;
      }
      *(float *)(param_1 + 0x38) = *(float *)(param_1 + 0x28) * SQRT(fVar8);
    }
    *(u8 *)(param_1 + 3) = *(u8 *)(param_1 + 3) & 0xfe;
  }
  return param_1 + 0x2c;
}

// FUN_00491410 NONMATCHING

u64 FUN_00491410(u64 param_1)

{
  ((code)FUN_004c4200)(*(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb30),0x4906d0,0);
  ((code)FUN_004c4200)(*(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb30),0x4906e0,0);
  ((code)FUN_004c3c30)(*(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb30));
  ((code)FUN_004c3c30)(*(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb30));
  *(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb30) = 0;
  *(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb30) = 0;
  iGpffffbb34 = iGpffffbb34 + -1;
  return param_1;
}

// FUN_004914D0 NONMATCHING

u64 FUN_004914d0(u64 param_1,int param_2)

{
  int iVar1;
  u32 uVar2;
  
  iGpffffbb30 = param_2;
  iVar1 = thunk_FUN_004c3970(DAT_0077dce0,uGpffffaee0,0x10,uGpffffaee4,0x95dea0,0x40010);
  *(int *)((int)(u8 *)DAT_00960070 + iGpffffbb30) = iVar1;
  if (*(int *)((int)(u8 *)DAT_00960070 + iGpffffbb30) != 0) {
    uVar2 = thunk_FUN_004c3970(DAT_0077dd00,uGpffffaee8,0x10,uGpffffaeec,0x95de70,0x40014);
    *(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb30) = uVar2;
    if (*(int *)((int)(u8 *)DAT_00960074 + iGpffffbb30) != 0) {
      iGpffffbb34 = iGpffffbb34 + 1;
      return param_1;
    }
    ((code)FUN_004c3c30)(*(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb30));
    *(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb30) = 0;
  }
  return 0;
}

// FUN_004915C0 NONMATCHING

u8 FUN_004915c0(void)

{
  u8 bVar1;
  long lVar2;
  
  lVar2 = ((code)FUN_004ca000)(0xc,0x10,0x490ca0,0x490cc0,0);
  uGpffffbb20 = (u32)lVar2;
  if (lVar2 < 0) {
    bVar1 = 0;
  }
  else {
    lVar2 = ((code)FUN_00494520)(0xc,0x10,0x490cd0,0x490cf0,0);
    uGpffffbb24 = (u32)lVar2;
    bVar1 = -1 < lVar2;
  }
  return bVar1;
}

// FUN_00491630 NONMATCHING

u64 FUN_00491630(u64 param_1)

{
  u32 *puVar1;
  long lVar2;
  int iVar3;
  
  iVar3 = (int)param_1;
  for (puVar1 = *(u32 **)(iVar3 + 8); puVar1 != (u32 *)(iVar3 + 8);
      puVar1 = (u32 *)*puVar1) {
    if ((*(u8 *)((int)puVar1 + -0x3e) & 4) != 0) {
      ((code)FUN_004cb2f0)(puVar1[-0xf]);
      lVar2 = (*(code *)puVar1[2])(puVar1 + -0x10);
      if (lVar2 == 0) {
        param_1 = 0;
      }
    }
  }
  return param_1;
}

// FUN_004916D0 NONMATCHING

u64 FUN_004916d0(u64 param_1,code *param_2,u64 param_3)

{
  u32 *puVar1;
  u32 *puVar2;
  long lVar3;
  
  puVar2 = *(u32 **)((int)param_1 + 8);
  do {
    if (puVar2 == (u32 *)((int)param_1 + 8)) {
      return param_1;
    }
    puVar1 = (u32 *)*puVar2;
    lVar3 = (*param_2)(puVar2 + -0x10,param_3);
    puVar2 = puVar1;
  } while (lVar3 != 0);
  return param_1;
}

// FUN_00491760 NONMATCHING

u64 FUN_00491760(u64 param_1,code *param_2,u64 param_3)

{
  u32 *puVar1;
  u32 *puVar2;
  long lVar3;
  
  puVar2 = *(u32 **)((int)param_1 + 0x18);
  do {
    if (puVar2 == (u32 *)((int)param_1 + 0x18)) {
      return param_1;
    }
    puVar1 = (u32 *)*puVar2;
    lVar3 = (*param_2)((int)puVar2 + (-4 - iGpffffbb20),param_3);
    puVar2 = puVar1;
  } while (lVar3 != 0);
  return param_1;
}

// FUN_004917F0 NONMATCHING

u64 FUN_004917f0(u64 param_1,code *param_2,u64 param_3)

{
  u32 *puVar1;
  u32 *puVar2;
  long lVar3;
  
  puVar2 = *(u32 **)((int)param_1 + 0x10);
  do {
    if (puVar2 == (u32 *)((int)param_1 + 0x10)) {
      return param_1;
    }
    puVar1 = (u32 *)*puVar2;
    lVar3 = (*param_2)((int)puVar2 + (-4 - iGpffffbb24),param_3);
    puVar2 = puVar1;
  } while (lVar3 != 0);
  return param_1;
}

// FUN_00491880 NONMATCHING

long FUN_00491880(void)

{
  long lVar1;
  u8 *puVar2;
  
  lVar1 = (*DAT_00960188)(*(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb30),0x30014);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else {
    puVar2 = (u8 *)lVar1;
    *puVar2 = 1;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    *(u32 *)(puVar2 + 4) = 0;
    *(code **)(puVar2 + 0x10) = (code *)(FUN_00490810);
    *(u32 *)(puVar2 + 0x14) = 0;
    puVar2[2] = 5;
    puVar2[3] = 1;
    ((code)FUN_00492d10)(lVar1,0);
    *(u32 *)(puVar2 + 0x18) = 0;
    *(u32 *)(puVar2 + 0x28) = 0;
    *(u32 *)(puVar2 + 0x1c) = 0;
    *(u32 *)(puVar2 + 0x20) = 0;
    *(u32 *)(puVar2 + 0x24) = 0;
    *(u32 *)(puVar2 + 0x38) = 0;
    *(u32 *)(puVar2 + 0x2c) = 0;
    *(u32 *)(puVar2 + 0x30) = 0;
    *(u32 *)(puVar2 + 0x34) = 0;
    *(code **)(puVar2 + 0x48) = (code *)(FUN_00490860);
    if (*(int *)(puVar2 + 0x48) == 0) {
      *(code **)(puVar2 + 0x48) = (code *)(FUN_00490860);
    }
    *(u16 *)(puVar2 + 0x50) = 0;
    *(u16 *)(puVar2 + 0x52) = 0;
    *(u32 *)(puVar2 + 0x54) = 0x3f800000;
    *(u32 *)(puVar2 + 0x58) = 0x3f800000;
    *(u32 *)(puVar2 + 0x5c) = 0;
    *(u32 *)(puVar2 + 0x4c) = 3;
    *(u32 *)(puVar2 + 0x44) = 0;
    *(u32 *)(puVar2 + 0x40) = 0;
    *(u32 *)(puVar2 + 0x3c) = 0;
    *(u32 *)(puVar2 + 0x6c) = 0;
    *(u8 **)(puVar2 + 100) = puVar2 + 100;
    *(u8 **)(puVar2 + 0x68) = puVar2 + 100;
    ((code)FUN_004c64b0)(0x77dce0,lVar1);
  }
  return lVar1;
}

// FUN_004919B0 NONMATCHING

u64 FUN_004919b0(u64 param_1,int param_2,u32 param_3)

{
  int iVar1;
  long lVar2;
  int iVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  
  iVar3 = (int)param_1;
  if (param_2 != *(int *)(iVar3 + 0x18)) {
    if (param_2 != 0) {
      ((code)FUN_00493b40)(param_2);
    }
    if (*(int *)(iVar3 + 0x18) != 0) {
      ((code)FUN_00493b60)();
    }
    *(int *)(iVar3 + 0x18) = param_2;
    if ((param_3 & 1) == 0) {
      if (param_2 != 0) {
        iVar1 = *(int *)(param_2 + 0x5c);
        uVar6 = *(u32 *)(iVar1 + 8);
        uVar4 = *(u32 *)(iVar1 + 0xc);
        uVar5 = *(u32 *)(iVar1 + 0x10);
        *(u32 *)(iVar3 + 0x1c) = *(u32 *)(iVar1 + 4);
        *(u32 *)(iVar3 + 0x20) = uVar6;
        *(u32 *)(iVar3 + 0x24) = uVar4;
        *(u32 *)(iVar3 + 0x28) = uVar5;
      }
      iVar3 = *(int *)(iVar3 + 4);
      if ((iVar3 != 0) && (lVar2 = ((code)FUN_0049c230)(param_1), lVar2 != 0)) {
        ((code)FUN_004cb270)(iVar3);
      }
    }
  }
  return param_1;
}

// FUN_00491A80 NONMATCHING

u32 FUN_00491a80(u64 param_1)

{
  long lVar1;
  int iVar2;
  
  ((code)FUN_004c6560)(0x77dce0,param_1);
  iVar2 = (int)param_1;
  if (*(int *)(iVar2 + 0x14) != 0) {
    ((code)FUN_004c47e0)();
  }
  if (*(int *)(iVar2 + 0x18) != 0) {
    if (*(int *)(iVar2 + 0x18) != 0) {
      ((code)FUN_00493b60)();
    }
    *(u32 *)(iVar2 + 0x18) = 0;
    iVar2 = *(int *)(iVar2 + 4);
    if ((iVar2 != 0) && (lVar1 = ((code)FUN_0049c230)(param_1), lVar1 != 0)) {
      ((code)FUN_004cb270)(iVar2);
    }
  }
  ((code)FUN_004d18c0)(param_1);
  (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb30),param_1);
  return 1;
}

// FUN_00491B40 NONMATCHING

long FUN_00491b40(u64 param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  u8 *puVar4;
  u8 *puVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  
  lVar2 = ((code)FUN_00491880)();
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  else {
    puVar5 = (u8 *)param_1;
    puVar4 = (u8 *)lVar2;
    *puVar4 = *puVar5;
    puVar4[1] = puVar5[1];
    puVar4[2] = puVar5[2];
    puVar4[3] = puVar5[3];
    *(u32 *)(puVar4 + 4) = 0;
    puVar4[2] = puVar5[2];
    ((code)FUN_00492d10)(lVar2,0);
    iVar1 = *(int *)(puVar5 + 0x18);
    if (iVar1 != *(int *)(puVar4 + 0x18)) {
      if (iVar1 != 0) {
        ((code)FUN_00493b40)(iVar1);
      }
      if (*(int *)(puVar4 + 0x18) != 0) {
        ((code)FUN_00493b60)();
      }
      *(int *)(puVar4 + 0x18) = iVar1;
      if (iVar1 != 0) {
        iVar1 = *(int *)(iVar1 + 0x5c);
        uVar8 = *(u32 *)(iVar1 + 8);
        uVar6 = *(u32 *)(iVar1 + 0xc);
        uVar7 = *(u32 *)(iVar1 + 0x10);
        *(u32 *)(puVar4 + 0x1c) = *(u32 *)(iVar1 + 4);
        *(u32 *)(puVar4 + 0x20) = uVar8;
        *(u32 *)(puVar4 + 0x24) = uVar6;
        *(u32 *)(puVar4 + 0x28) = uVar7;
      }
      iVar1 = *(int *)(puVar4 + 4);
      if ((iVar1 != 0) && (lVar3 = ((code)FUN_0049c230)(lVar2), lVar3 != 0)) {
        ((code)FUN_004cb270)(iVar1);
      }
    }
    uVar8 = *(u32 *)(puVar5 + 0x20);
    uVar6 = *(u32 *)(puVar5 + 0x24);
    uVar7 = *(u32 *)(puVar5 + 0x28);
    *(u32 *)(puVar4 + 0x1c) = *(u32 *)(puVar5 + 0x1c);
    *(u32 *)(puVar4 + 0x20) = uVar8;
    *(u32 *)(puVar4 + 0x24) = uVar6;
    *(u32 *)(puVar4 + 0x28) = uVar7;
    *(u32 *)(puVar4 + 0x48) = *(u32 *)(puVar5 + 0x48);
    *(u32 *)(puVar4 + 0x6c) = *(u32 *)(puVar5 + 0x6c);
    uVar8 = *(u32 *)(puVar5 + 0x50);
    uVar6 = *(u32 *)(puVar5 + 0x54);
    uVar7 = *(u32 *)(puVar5 + 0x58);
    *(u32 *)(puVar4 + 0x4c) = *(u32 *)(puVar5 + 0x4c);
    *(u32 *)(puVar4 + 0x50) = uVar8;
    *(u32 *)(puVar4 + 0x54) = uVar6;
    *(u32 *)(puVar4 + 0x58) = uVar7;
    *(u32 *)(puVar4 + 0x5c) = *(u32 *)(puVar5 + 0x5c);
    ((code)FUN_004c65d0)(0x77dce0,lVar2,param_1);
  }
  return lVar2;
}

// FUN_00491CC0 NONMATCHING

int FUN_00491cc0(int param_1)

{
  u32 *puVar1;
  u32 *puVar2;
  u32 uVar3;
  long lVar4;
  u32 *puVar5;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  
  iStack_10 = param_1;
  lVar4 = ((code)FUN_00491de0)();
  iStack_c = (int)lVar4;
  if (lVar4 == 0) {
    iStack_c = 0;
  }
  else {
    uVar3 = ((code)FUN_004cace0)(*(u32 *)(iStack_10 + 4));
    *(u32 *)(iStack_c + 4) = uVar3;
    if (*(int *)(iStack_c + 4) == 0) {
      ((code)FUN_00491ea0)();
      iStack_c = 0;
    }
    else {
      iStack_8 = 1;
      puVar5 = (u32 *)(iStack_10 + 8);
      puVar2 = *(u32 **)(iStack_10 + 8);
      do {
        if (puVar2 == puVar5) break;
        puVar1 = (u32 *)*puVar2;
        lVar4 = ((code)FUN_004908d0)(puVar2 + -0x10,&iStack_10);
        puVar2 = puVar1;
      } while (lVar4 != 0);
      ((code)FUN_004cad30)(*(u32 *)(iStack_10 + 4));
      if (iStack_8 == 0) {
        ((code)FUN_00491ea0)(iStack_c);
        iStack_c = 0;
      }
      else {
        *(u32 *)(iStack_c + 0x28) = *(u32 *)(iStack_10 + 0x28);
        ((code)FUN_004c65d0)(0x77dd00,iStack_c,iStack_10);
      }
    }
  }
  return iStack_c;
}

// FUN_00491DE0 NONMATCHING

long FUN_00491de0(void)

{
  long lVar1;
  u8 *puVar2;
  
  lVar1 = (*DAT_00960188)(*(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb30),0x30010);
  if (lVar1 != 0) {
    puVar2 = (u8 *)lVar1;
    *puVar2 = 2;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    *(u32 *)(puVar2 + 4) = 0;
    *(u8 **)(puVar2 + 8) = puVar2 + 8;
    *(u8 **)(puVar2 + 0xc) = puVar2 + 8;
    *(u8 **)(puVar2 + 0x10) = puVar2 + 0x10;
    *(u8 **)(puVar2 + 0x14) = puVar2 + 0x10;
    *(u8 **)(puVar2 + 0x18) = puVar2 + 0x18;
    *(u8 **)(puVar2 + 0x1c) = puVar2 + 0x18;
    *(u32 *)(puVar2 + 0x24) = 0;
    *(u32 *)(puVar2 + 0x20) = 0;
    *(u8 **)(puVar2 + 0x28) = &LAB_00490d80;
    ((code)FUN_004c64b0)(0x77dd00,lVar1);
  }
  return lVar1;
}

// FUN_00491EA0 NONMATCHING

u32 FUN_00491ea0(u64 param_1)

{
  u32 *puVar1;
  int iVar2;
  u32 *puVar3;
  int iVar4;
  
  ((code)FUN_004c6560)(0x77dd00,param_1);
  iVar2 = (int)param_1;
  puVar1 = *(u32 **)(iVar2 + 8);
  do {
    if (puVar1 == (u32 *)(iVar2 + 8)) break;
    puVar3 = puVar1 + -0x10;
    puVar1 = (u32 *)*puVar1;
    ((code)FUN_00491a80)(puVar3);
  } while (puVar3 != (u32 *)0x0);
  puVar1 = *(u32 **)(iVar2 + 0x10);
  do {
    if (puVar1 == (u32 *)(iVar2 + 0x10)) break;
    puVar3 = (u32 *)*puVar1;
    iVar4 = (int)puVar1 + (-4 - iGpffffbb24);
    ((code)FUN_00492020)(*(u32 *)(iVar4 + iGpffffbb24),iVar4);
    ((code)FUN_00494760)(iVar4);
    puVar1 = puVar3;
  } while (iVar4 != 0);
  puVar1 = *(u32 **)(iVar2 + 0x18);
  do {
    if (puVar1 == (u32 *)(iVar2 + 0x18)) break;
    puVar3 = (u32 *)*puVar1;
    iVar4 = (int)puVar1 + (-4 - iGpffffbb20);
    ((code)FUN_00492060)(*(u32 *)(iVar4 + iGpffffbb20),iVar4);
    ((code)FUN_004ca030)(iVar4);
    puVar1 = puVar3;
  } while (iVar4 != 0);
  if (*(int *)(iVar2 + 4) != 0) {
    ((code)FUN_004cb1b0)();
  }
  (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb30),param_1);
  return 1;
}

// FUN_00491FF0 NONMATCHING

u64 FUN_00491ff0(u64 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(u32 *)(param_2 + 0x40) = *(u32 *)(iVar1 + 8);
  *(int *)(param_2 + 0x44) = iVar1 + 8;
  *(int *)(*(int *)(iVar1 + 8) + 4) = param_2 + 0x40;
  *(int *)(iVar1 + 8) = param_2 + 0x40;
  *(int *)(param_2 + 0x3c) = iVar1;
  return param_1;
}

#pragma schedule on
// FUN_00492020

u64 FUN_00492020(u64 param_1,int param_2)
{
  u64 result;
  u32 *puVar1;
  u32 first;
  u32 second;

  result = param_1;
  puVar1 = (u32 *)((u8 *)param_2 + iGpffffbb24);
  first = puVar1[1];
  second = puVar1[2];
  *(u32 *)second = first;
  second = puVar1[2];
  first = puVar1[1];
  *(u32 *)(first + 4) = second;
  puVar1[2] = 0;
  puVar1[1] = 0;
  *puVar1 = 0;
  return result;
}

#pragma schedule on
// FUN_00492060

u64 FUN_00492060(u64 param_1,int param_2)
{
  u64 result;
  u32 *puVar1;
  u32 first;
  u32 second;

  result = param_1;
  puVar1 = (u32 *)(param_2 + iGpffffbb20);
  first = puVar1[1];
  second = puVar1[2];
  *(u32 *)second = first;
  second = puVar1[2];
  first = puVar1[1];
  *(u32 *)(first + 4) = second;
  puVar1[2] = 0;
  puVar1[1] = 0;
  *puVar1 = 0;
  return result;
}

#pragma schedule off
// FUN_004920A0 NONMATCHING

long FUN_004920a0(u64 param_1)

{
  u8 bVar1;
  long lVar2;
  long lVar3;
  int *piVar4;
  long unaff_s0;
  int iVar5;
  long unaff_s1;
  int iVar6;
  long unaff_s2;
  int iVar7;
  u32 uStack_90;
  u32 uStack_8c;
  u32 uStack_88;
  u32 uStack_84;
  u32 uStack_80;
  u32 uStack_7c;
  u32 uStack_78;
  u32 uStack_74;
  u32 uStack_70;
  u32 uStack_6c;
  u32 uStack_68;
  u32 uStack_64;
  u32 uStack_60;
  u32 uStack_5c;
  u32 uStack_58;
  u32 uStack_54;
  u32 uStack_50;
  u32 uStack_4c;
  u32 uStack_48;
  u32 uStack_44;
  int iStack_40;
  int iStack_3c;
  u32 *apuStack_38 [2];
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  u32 uStack_20;
  u32 uStack_1c;
  int iStack_14;
  int iStack_10;
  u8 auStack_c [4];
  u32 uStack_8;
  u8 auStack_4 [4];
  
  lVar2 = ((code)FUN_004c1600)(param_1,1,auStack_4,&uStack_8);
  if (lVar2 == 0) {
    uStack_20 = 2;
    uStack_1c = ((code)FUN_004c1d10)(0xffffffff8000001a);
    ((code)FUN_004c1c50)(&uStack_20);
    lVar2 = 0;
  }
  else if ((uStack_8 < 0x35000) || (0x37002 < uStack_8)) {
    uStack_90 = 2;
    uStack_8c = ((code)FUN_004c1d10)(0xffffffff80000004);
    ((code)FUN_004c1c50)(&uStack_90);
    lVar2 = 0;
  }
  else {
    lVar2 = ((code)FUN_004c5250)(param_1,&iStack_30,0xc);
    if (lVar2 == 0xc) {
      lVar2 = ((code)FUN_00491de0)();
      if (lVar2 == 0) {
        lVar2 = 0;
      }
      else {
        lVar3 = ((code)FUN_004c1600)(param_1,0xe,0,auStack_c);
        iVar7 = (int)lVar2;
        if (lVar3 == 0) {
          ((code)FUN_004c6560)(0x77dd00,lVar2);
          ((code)FUN_004916d0)(lVar2,0x490d90,0);
          ((code)FUN_004917f0)(lVar2,0x490d00,0);
          ((code)FUN_00491760)(lVar2,0x490d40,0);
          if (*(int *)(iVar7 + 4) != 0) {
            ((code)FUN_004cb1b0)();
          }
          (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb30),lVar2);
          uStack_50 = 2;
          uStack_4c = ((code)FUN_004c1d10)(0xffffffff8000001a);
          ((code)FUN_004c1c50)(&uStack_50);
          lVar2 = 0;
        }
        else {
          lVar3 = ((code)FUN_004c7d80)(param_1,apuStack_38);
          if (lVar3 == 0) {
            ((code)FUN_004c6560)(0x77dd00,lVar2);
            ((code)FUN_004916d0)(lVar2,0x490d90,0);
            ((code)FUN_004917f0)(lVar2,0x490d00,0);
            ((code)FUN_00491760)(lVar2,0x490d40,0);
            if (*(int *)(iVar7 + 4) != 0) {
              ((code)FUN_004cb1b0)();
            }
            (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb30),lVar2);
            uStack_58 = 2;
            uStack_54 = ((code)FUN_004c1d10)(0xffffffff8000001a);
            ((code)FUN_004c1c50)(&uStack_58);
            lVar2 = 0;
          }
          else {
            *(u32 *)(iVar7 + 4) = *apuStack_38[0];
            lVar3 = ((code)FUN_004c1600)(param_1,0x1a,0,auStack_c);
            if (lVar3 == 0) {
              ((code)FUN_004c7d30)(apuStack_38);
              ((code)FUN_004c6560)(0x77dd00,lVar2);
              ((code)FUN_004916d0)(lVar2,0x490d90,0);
              ((code)FUN_004917f0)(lVar2,0x490d00,0);
              ((code)FUN_00491760)(lVar2,0x490d40,0);
              if (*(int *)(iVar7 + 4) != 0) {
                ((code)FUN_004cb1b0)();
              }
              (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb30),lVar2);
              uStack_60 = 2;
              uStack_5c = ((code)FUN_004c1d10)(0xffffffff8000001a);
              ((code)FUN_004c1c50)(&uStack_60);
              lVar2 = 0;
            }
            else {
              lVar3 = ((code)FUN_00490980)(param_1,&iStack_40);
              if (lVar3 == 0) {
                ((code)FUN_004c7d30)(apuStack_38);
                ((code)FUN_004c6560)(0x77dd00,lVar2);
                ((code)FUN_004916d0)(lVar2,0x490d90,0);
                ((code)FUN_004917f0)(lVar2,0x490d00,0);
                ((code)FUN_00491760)(lVar2,0x490d40,0);
                if (*(int *)(iVar7 + 4) != 0) {
                  ((code)FUN_004cb1b0)();
                }
                (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb30),lVar2);
                uStack_68 = 2;
                uStack_64 = ((code)FUN_004c1d10)(0xffffffff8000001a);
                ((code)FUN_004c1c50)(&uStack_68);
                lVar2 = 0;
              }
              else {
                iVar6 = 0;
                if (0 < iStack_30) {
                  do {
                    lVar3 = ((code)FUN_004c1600)(param_1,0x14,0,&uStack_8);
                    bVar1 = 0;
                    if (lVar3 != 0) {
                      unaff_s2 = ((code)FUN_00490dc0)(param_1,apuStack_38,&iStack_40);
                      bVar1 = unaff_s2 != 0;
                    }
                    if (!bVar1) {
                      iVar6 = 0;
                      if (0 < iStack_3c) {
                        iVar5 = 0;
                        do {
                          ((code)FUN_00493b60)(*(u32 *)(iStack_40 + iVar5));
                          iVar6 = iVar6 + 1;
                          iVar5 = iVar5 + 4;
                        } while (iVar6 < iStack_3c);
                      }
                      if (iStack_40 != 0) {
                        (*DAT_0096017c)();
                        iStack_40 = 0;
                      }
                      ((code)FUN_004c7d30)(apuStack_38);
                      ((code)FUN_004c6560)(0x77dd00,lVar2);
                      ((code)FUN_004916d0)(lVar2,0x490d90,0);
                      ((code)FUN_004917f0)(lVar2,0x490d00,0);
                      ((code)FUN_00491760)(lVar2,0x490d40,0);
                      if (*(int *)(iVar7 + 4) != 0) {
                        ((code)FUN_004cb1b0)();
                      }
                      (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb30),lVar2);
                      uStack_70 = 2;
                      uStack_6c = ((code)FUN_004c1d10)(0xffffffff8000001a);
                      ((code)FUN_004c1c50)(&uStack_70);
                      return 0;
                    }
                    iVar5 = (int)unaff_s2;
                    iVar6 = iVar6 + 1;
                    *(u32 *)(iVar5 + 0x40) = *(u32 *)(iVar7 + 8);
                    *(int *)(iVar5 + 0x44) = iVar7 + 8;
                    *(int *)(*(int *)(iVar7 + 8) + 4) = iVar5 + 0x40;
                    *(int *)(iVar7 + 8) = iVar5 + 0x40;
                    *(int *)(iVar5 + 0x3c) = iVar7;
                  } while (iVar6 < iStack_30);
                }
                iVar6 = 0;
                if (0 < iStack_2c) {
                  do {
                    lVar3 = ((code)FUN_004c1600)(param_1,1,0,0);
                    bVar1 = 0;
                    if (lVar3 != 0) {
                      lVar3 = ((code)FUN_004c1910)(param_1,&iStack_10,4);
                      bVar1 = lVar3 != 0;
                    }
                    lVar3 = 0;
                    if (bVar1) {
                      lVar3 = ((code)FUN_004c1600)(param_1,0x12,0,0);
                    }
                    bVar1 = 0;
                    if (lVar3 != 0) {
                      unaff_s1 = ((code)FUN_00494580)(param_1);
                      bVar1 = unaff_s1 != 0;
                    }
                    if (!bVar1) {
                      iVar6 = 0;
                      if (0 < iStack_3c) {
                        iVar5 = 0;
                        do {
                          ((code)FUN_00493b60)(*(u32 *)(iStack_40 + iVar5));
                          iVar6 = iVar6 + 1;
                          iVar5 = iVar5 + 4;
                        } while (iVar6 < iStack_3c);
                      }
                      if (iStack_40 != 0) {
                        (*DAT_0096017c)();
                        iStack_40 = 0;
                      }
                      ((code)FUN_004c7d30)(apuStack_38);
                      ((code)FUN_004c6560)(0x77dd00,lVar2);
                      ((code)FUN_004916d0)(lVar2,0x490d90,0);
                      ((code)FUN_004917f0)(lVar2,0x490d00,0);
                      ((code)FUN_00491760)(lVar2,0x490d40,0);
                      if (*(int *)(iVar7 + 4) != 0) {
                        ((code)FUN_004cb1b0)();
                      }
                      (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb30),lVar2);
                      uStack_78 = 2;
                      uStack_74 = ((code)FUN_004c1d10)(0xffffffff8000001a);
                      ((code)FUN_004c1c50)(&uStack_78);
                      return 0;
                    }
                    ((code)FUN_004d1840)(unaff_s1,apuStack_38[0][iStack_10]);
                    iVar6 = iVar6 + 1;
                    piVar4 = (int *)((int)unaff_s1 + iGpffffbb24);
                    piVar4[1] = *(int *)(iVar7 + 0x10);
                    piVar4[2] = iVar7 + 0x10;
                    *(int **)(*(int *)(iVar7 + 0x10) + 4) = piVar4 + 1;
                    *(int **)(iVar7 + 0x10) = piVar4 + 1;
                    *piVar4 = iVar7;
                  } while (iVar6 < iStack_2c);
                }
                iVar6 = 0;
                if (0 < iStack_28) {
                  do {
                    lVar3 = ((code)FUN_004c1600)(param_1,1,0,0);
                    bVar1 = 0;
                    if (lVar3 != 0) {
                      lVar3 = ((code)FUN_004c1910)(param_1,&iStack_14,4);
                      bVar1 = lVar3 != 0;
                    }
                    lVar3 = 0;
                    if (bVar1) {
                      lVar3 = ((code)FUN_004c1600)(param_1,5,0,0);
                    }
                    bVar1 = 0;
                    if (lVar3 != 0) {
                      unaff_s0 = ((code)FUN_004c7b90)(param_1);
                      bVar1 = unaff_s0 != 0;
                    }
                    if (!bVar1) {
                      iVar6 = 0;
                      if (0 < iStack_3c) {
                        iVar5 = 0;
                        do {
                          ((code)FUN_00493b60)(*(u32 *)(iStack_40 + iVar5));
                          iVar6 = iVar6 + 1;
                          iVar5 = iVar5 + 4;
                        } while (iVar6 < iStack_3c);
                      }
                      if (iStack_40 != 0) {
                        (*DAT_0096017c)();
                        iStack_40 = 0;
                      }
                      ((code)FUN_004c7d30)(apuStack_38);
                      ((code)FUN_004c6560)(0x77dd00,lVar2);
                      ((code)FUN_004916d0)(lVar2,0x490d90,0);
                      ((code)FUN_004917f0)(lVar2,0x490d00,0);
                      ((code)FUN_00491760)(lVar2,0x490d40,0);
                      if (*(int *)(iVar7 + 4) != 0) {
                        ((code)FUN_004cb1b0)();
                      }
                      (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb30),lVar2);
                      uStack_80 = 2;
                      uStack_7c = ((code)FUN_004c1d10)(0xffffffff8000001a);
                      ((code)FUN_004c1c50)(&uStack_80);
                      return 0;
                    }
                    ((code)FUN_004d1840)(unaff_s0,apuStack_38[0][iStack_14]);
                    iVar6 = iVar6 + 1;
                    piVar4 = (int *)((int)unaff_s0 + iGpffffbb20);
                    piVar4[1] = *(int *)(iVar7 + 0x18);
                    piVar4[2] = iVar7 + 0x18;
                    *(int **)(*(int *)(iVar7 + 0x18) + 4) = piVar4 + 1;
                    *(int **)(iVar7 + 0x18) = piVar4 + 1;
                    *piVar4 = iVar7;
                  } while (iVar6 < iStack_28);
                }
                iVar6 = 0;
                if (0 < iStack_3c) {
                  iVar5 = 0;
                  do {
                    ((code)FUN_00493b60)(*(u32 *)(iStack_40 + iVar5));
                    iVar6 = iVar6 + 1;
                    iVar5 = iVar5 + 4;
                  } while (iVar6 < iStack_3c);
                }
                if (iStack_40 != 0) {
                  (*DAT_0096017c)();
                  iStack_40 = 0;
                }
                ((code)FUN_004c7d30)(apuStack_38);
                lVar3 = ((code)FUN_004c5a50)(0x77dd00,param_1,lVar2);
                if (lVar3 == 0) {
                  ((code)FUN_004c6560)(0x77dd00,lVar2);
                  ((code)FUN_004916d0)(lVar2,0x490d90,0);
                  ((code)FUN_004917f0)(lVar2,0x490d00,0);
                  ((code)FUN_00491760)(lVar2,0x490d40,0);
                  if (*(int *)(iVar7 + 4) != 0) {
                    ((code)FUN_004cb1b0)();
                  }
                  (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb30),lVar2);
                  uStack_88 = 2;
                  uStack_84 = ((code)FUN_004c1d10)(0xffffffff8000001a);
                  ((code)FUN_004c1c50)(&uStack_88);
                  lVar2 = 0;
                }
              }
            }
          }
        }
      }
    }
    else {
      uStack_48 = 2;
      uStack_44 = ((code)FUN_004c1d10)(0xffffffff8000001a);
      ((code)FUN_004c1c50)(&uStack_48);
      lVar2 = 0;
    }
  }
  return lVar2;
}

#pragma schedule on
#pragma tailcall on
// FUN_00492C30

void FUN_00492c30(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5)

{
  FUN_004c61b0_raw((u32)DAT_0077dce0_abs,param_1,param_2,param_3,param_4,param_5);
}
#pragma tailcall off
#pragma schedule off

#pragma schedule on
#pragma tailcall on
// FUN_00492C60

void FUN_00492c60(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5)

{
  FUN_004c61b0_raw((u32)DAT_0077dd00_abs,param_1,param_2,param_3,param_4,param_5);
}

// FUN_00492C90

void FUN_00492c90(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  FUN_004c5960_raw((u32)DAT_0077dce0_abs,param_1,param_2,param_3,param_4);
}

// FUN_00492CC0

void FUN_00492cc0(u64 param_1,u64 param_2)

{
  FUN_004c59b0_raw((u32)DAT_0077dce0_abs,param_1,param_2);
}

#pragma schedule on

#pragma tailcall on

// FUN_00492CE0

void FUN_00492ce0(u64 param_1,u64 param_2)

{
  FUN_004c5a00_u32((u32)DAT_0077dce0_abs,param_1,param_2);
}
#pragma tailcall off
#pragma schedule off

#pragma schedule on
// FUN_00492D00 NONMATCHING

void FUN_00492d00(u32 param_1)

{
  FUN_004c6170_u32((u32)DAT_0077dce0_abs,param_1);
}
#pragma tailcall off
#pragma schedule off

// FUN_00492D10 NONMATCHING

u64 FUN_00492d10(u64 param_1)

{
  ((code)FUN_004d1840)();
  *(u8 *)((int)param_1 + 3) = *(u8 *)((int)param_1 + 3) | 1;
  return param_1;
}

// FUN_00492D50 NONMATCHING

u32 FUN_00492d50(u64 param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(short *)(iVar1 + 0xe) = *(short *)(iVar1 + 0xe) + 1;
  ((code)FUN_00493370)(param_1,0xfff);
  ((code)FUN_004c6560)(0x77dd20,param_1);
  if (*(int *)(iVar1 + 0x5c) != 0) {
    (*DAT_0096017c)();
    *(u32 *)(iVar1 + 0x5c) = 0;
  }
  ((code)FUN_00495260)(iVar1 + 0x20);
  *(short *)(iVar1 + 0xe) = *(short *)(iVar1 + 0xe) + -1;
  (*DAT_0096017c)(param_1);
  return 1;
}

// FUN_00492E20 NONMATCHING

u64 FUN_00492e20(u64 param_1,float *param_2)

{
  int *piVar1;
  int iVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  
  piVar1 = (int *)param_1;
  iVar2 = *(int *)(*piVar1 + 0x14);
  ((code)FUN_004c7a50)(&fStack_30,piVar1[5],iVar2);
  pfVar3 = (float *)piVar1[5];
  fVar6 = (fStack_24 + fStack_30) * 0.5;
  fVar8 = (fStack_20 + fStack_2c) * 0.5;
  fVar9 = (fStack_1c + fStack_28) * 0.5;
  fVar10 = 0.0;
  while (iVar2 != 0) {
    iVar2 = iVar2 + -1;
    fVar4 = pfVar3[1] - fVar8;
    fVar7 = *pfVar3 - fVar6;
    fVar5 = pfVar3[2] - fVar9;
    fVar4 = fVar5 * fVar5 + fVar7 * fVar7 + fVar4 * fVar4;
    if (fVar4 <= fVar10) {
      fVar4 = fVar10;
    }
    pfVar3 = pfVar3 + 3;
    fVar10 = fVar4;
  }
  if (0.0 < fVar10) {
    fVar10 = SQRT(fVar10);
  }
  *param_2 = fVar6;
  param_2[1] = fVar8;
  param_2[2] = fVar9;
  param_2[3] = fVar10 * 1.001;
  return param_1;
}

// FUN_00492F80 NONMATCHING

int FUN_00492f80(int param_1,int param_2)

{
  int *piVar1;
  long lVar2;
  int iVar3;
  u8 *puVar4;
  u8 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  if ((*(u32 *)(param_1 + 8) & 0x1000000) == 0) {
    iVar3 = *(int *)(param_1 + 0x14) * 0xc;
    iVar8 = iVar3 + 0x1c;
    if ((*(u32 *)(param_1 + 8) & 0x10) != 0) {
      iVar8 = iVar8 + iVar3;
    }
  }
  else {
    iVar8 = 0x1c;
  }
  iVar3 = iVar8 * (*(int *)(param_1 + 0x18) + param_2);
  if (*(int *)(param_1 + 0x5c) == 0) {
    lVar2 = (*DAT_00960178)(iVar3,0x3000f);
    if (lVar2 == 0) {
      uStack_10 = 2;
      uStack_c = ((code)FUN_004c1d10)(0xffffffff80000013,iVar3);
      ((code)FUN_004c1c50)(&uStack_10);
      return -1;
    }
  }
  else {
    lVar2 = (*DAT_00960180)(*(int *)(param_1 + 0x5c),iVar3,0x3000f);
    if (lVar2 == 0) {
      uStack_8 = 2;
      uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,iVar3);
      ((code)FUN_004c1c50)(&uStack_8);
      return -1;
    }
    puVar5 = (u8 *)((int)lVar2 + iVar8 * *(int *)(param_1 + 0x18) + -1);
    puVar4 = puVar5 + param_2 * 0x1c;
    for (iVar8 = *(int *)(param_1 + 0x18) * (iVar8 + -0x1c); iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar4 = *puVar5;
      puVar5 = puVar5 + -1;
      puVar4 = puVar4 + -1;
    }
  }
  iVar3 = 0;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + param_2;
  *(int *)(param_1 + 0x5c) = (int)lVar2;
  iVar8 = *(int *)(param_1 + 0x18);
  iVar7 = (int)lVar2 + iVar8 * 0x1c;
  if (0 < iVar8) {
    iVar6 = 0;
    do {
      iVar8 = *(int *)(param_1 + 0x5c) + iVar6;
      *(u32 *)(iVar8 + 0x14) = 0;
      *(u32 *)(iVar8 + 0x18) = 0;
      if (((*(u32 *)(param_1 + 8) & 0x1000000) == 0) && (*(int *)(param_1 + 0x14) != 0)) {
        *(int *)(iVar8 + 0x14) = iVar7;
        iVar7 = iVar7 + *(int *)(param_1 + 0x14) * 0xc;
        if ((*(u32 *)(param_1 + 8) & 0x10) != 0) {
          *(int *)(iVar8 + 0x18) = iVar7;
          iVar7 = iVar7 + *(int *)(param_1 + 0x14) * 0xc;
        }
      }
      iVar8 = *(int *)(param_1 + 0x18);
      iVar3 = iVar3 + 1;
      iVar6 = iVar6 + 0x1c;
    } while (iVar3 < iVar8);
  }
  iVar3 = iVar8 - param_2;
  if (iVar3 < iVar8) {
    iVar8 = iVar3 * 0x1c;
    do {
      iVar3 = iVar3 + 1;
      piVar1 = (int *)(*(int *)(param_1 + 0x5c) + iVar8);
      piVar1[1] = 0;
      piVar1[2] = 0;
      piVar1[3] = 0;
      piVar1[4] = 0;
      *piVar1 = param_1;
      iVar8 = iVar8 + 0x1c;
    } while (iVar3 < *(int *)(param_1 + 0x18));
    param_2 = *(int *)(param_1 + 0x18) - param_2;
  }
  else {
    param_2 = iVar8 - param_2;
  }
  return param_2;
}

#pragma optimization_level 3

u64
// FUN_00493210
FUN_00493210(u64 param_1,u16 *param_2,u16 param_3,u16 param_4,
            u16 param_5)
{
  *param_2 = param_3;
  param_2[1] = param_4;
  param_2[2] = param_5;
  return param_1;
}
#pragma optimization_level 2

// FUN_00493230 NONMATCHING

u64 FUN_00493230(u64 param_1,int param_2,long param_3)

{
  long lVar1;
  
  if (param_3 == 0) {
    *(u16 *)(param_2 + 6) = 0xffff;
  }
  else {
    lVar1 = ((code)FUN_00495480)((int)param_1 + 0x20,param_3);
    if ((lVar1 < 0) && (lVar1 = ((code)FUN_00495340)((int)param_1 + 0x20,param_3), lVar1 < 0)) {
      param_1 = 0;
    }
    else {
      *(short *)(param_2 + 6) = (short)lVar1;
    }
  }
  return param_1;
}

// FUN_004932C0 NONMATCHING

u64 FUN_004932c0(u64 param_1,code *param_2,u64 param_3)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)((int)param_1 + 0x24);
  iVar4 = 0;
  if (0 < iVar1) {
    iVar3 = 0;
    do {
      lVar2 = (*param_2)(*(u32 *)(*(int *)((int)param_1 + 0x20) + iVar3),param_3);
      if (lVar2 == 0) {
        return param_1;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar4 < iVar1);
  }
  return param_1;
}

// FUN_00493370 NONMATCHING

u64 FUN_00493370(u64 param_1,u16 param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(u16 *)(iVar1 + 0xc) = *(u16 *)(iVar1 + 0xc) | param_2;
  if (((param_2 & 1) != 0) && (*(int *)(iVar1 + 0x54) != 0)) {
    ((code)FUN_00495c80)();
    *(u32 *)(iVar1 + 0x54) = 0;
  }
  return param_1;
}

// FUN_004933D0 NONMATCHING

u64 FUN_004933d0(u64 param_1)

{
  int *piVar1;
  u32 uVar2;
  int iVar3;
  long lVar4;
  u64 uVar5;
  u64 uVar6;
  int iVar7;
  u32 uVar8;
  int iVar9;
  int iVar10;
  u16 *puVar11;
  u32 uVar12;
  u32 uVar13;
  u32 uVar14;
  int iVar15;
  int iVar16;
  
  uVar14 = 0;
  uVar13 = 0;
  iVar7 = (int)param_1;
  uVar12 = 0;
  if (*(int *)(iVar7 + 0x54) == 0) {
    lVar4 = ((code)FUN_00495b10)(*(u32 *)(iVar7 + 0x10));
    uVar2 = (u32)lVar4;
    if (lVar4 == 0) {
      param_1 = 0;
    }
    else {
      if (0 < *(int *)(iVar7 + 0x24)) {
        iVar9 = *(int *)(iVar7 + 0x24) << 2;
        uVar5 = (*DAT_00960178)(iVar9,0x10006);
        iVar3 = (*DAT_00960178)(iVar9,0x10503);
        iVar9 = (*DAT_00960178)(iVar9,0x10503);
        iVar15 = 0;
        if (0 < *(int *)(iVar7 + 0x10)) {
          iVar16 = 0;
          do {
            puVar11 = (u16 *)(*(int *)(iVar7 + 0x2c) + iVar16);
            iVar10 = 0;
            uVar6 = ((code)FUN_00495320)(iVar7 + 0x20,puVar11[3]);
            piVar1 = (int *)*(int *)uVar6;
            uVar8 = 0;
            if (uVar13 != 0) {
              do {
                if (*(int **)((int)uVar5 + uVar8 * 4) == piVar1) break;
                uVar8 = uVar8 + 1 & 0xffff;
              } while (uVar8 < uVar13);
            }
            if (uVar8 == uVar13) {
              uVar13 = uVar13 + 1 & 0xffff;
              *(int **)((int)uVar5 + uVar8 * 4) = piVar1;
            }
            if (piVar1 != (int *)0x0) {
              iVar10 = *piVar1;
            }
            uVar8 = 0;
            if (uVar12 != 0) {
              do {
                if (*(int *)(iVar3 + uVar8 * 4) == iVar10) break;
                uVar8 = uVar8 + 1 & 0xffff;
              } while (uVar8 < uVar12);
            }
            if (uVar8 == uVar12) {
              *(int *)(iVar3 + uVar8 * 4) = iVar10;
              uVar12 = uVar12 + 1 & 0xffff;
            }
            iVar10 = ((int *)uVar6)[2];
            uVar8 = 0;
            if (uVar14 != 0) {
              do {
                if (*(int *)(iVar9 + uVar8 * 4) == iVar10) break;
                uVar8 = uVar8 + 1 & 0xffff;
              } while (uVar8 < uVar14);
            }
            if (uVar8 == uVar14) {
              *(int *)(iVar9 + uVar8 * 4) = iVar10;
              uVar14 = uVar14 + 1 & 0xffff;
            }
            ((code)FUN_00495cf0)(uVar2,uVar6,*puVar11,puVar11[1],puVar11[2],puVar11[3]);
            iVar15 = iVar15 + 1;
            iVar16 = iVar16 + 8;
          } while (iVar15 < *(int *)(iVar7 + 0x10));
        }
        (*DAT_0096017c)(uVar5);
        (*DAT_0096017c)(iVar3);
        (*DAT_0096017c)(iVar9);
      }
      if ((*(u32 *)(iVar7 + 8) & 1) == 0) {
        lVar4 = ((code)FUN_00499140)(uVar2,0);
      }
      else {
        lVar4 = ((code)FUN_00499140)(uVar2,1);
      }
      if (lVar4 == 0) {
        ((code)FUN_00495c20)(uVar2);
        param_1 = 0;
      }
      else {
        *(int *)(iVar7 + 0x54) = (int)lVar4;
      }
    }
  }
  return param_1;
}

// FUN_00493710 NONMATCHING

u8 * FUN_00493710(int param_1,int param_2,u32 param_3)

{
  u8 bVar1;
  u8 *puVar2;
  long lVar3;
  int iVar4;
  u8 *puVar5;
  u32 uVar6;
  u8 *puVar7;
  int iVar8;
  u32 uVar9;
  u32 uStack_8;
  u32 uStack_4;
  
  if (((param_1 < 0) || (0xffff < param_1)) || (param_2 < 0)) {
    if ((-1 < param_1) && (0xffff < param_1)) {
      uStack_8 = 2;
      uStack_4 = ((code)FUN_004c1d10)(6);
      ((code)FUN_004c1c50)(&uStack_8);
    }
    puVar2 = (u8 *)0x0;
  }
  else {
    if ((param_3 & 0xff0000) == 0) {
      if ((param_3 & 0x80) == 0) {
        uVar9 = (u32)((param_3 & 4) != 0);
      }
      else {
        uVar9 = 2;
      }
    }
    else {
      uVar9 = (param_3 & 0xff0000) >> 0x10;
    }
    if (uVar9 == 1) {
      uVar6 = 4;
    }
    else if (uVar9 < 2) {
      uVar6 = 0;
    }
    else {
      uVar6 = 0x80;
    }
    iVar4 = DAT_0077dd20;
    if ((param_3 & 0x1000000) == 0) {
      if ((param_3 & 8) != 0) {
        iVar4 = DAT_0077dd20 + param_1 * 4;
      }
      if (uVar9 != 0) {
        iVar4 = iVar4 + uVar9 * param_1 * 8;
      }
      iVar4 = iVar4 + param_2 * 8;
    }
    puVar2 = (u8 *)(*DAT_00960178)(iVar4,0x3000f);
    if (puVar2 == (u8 *)0x0) {
      puVar2 = (u8 *)0x0;
    }
    else {
      lVar3 = ((code)FUN_00495300)(puVar2 + 0x20);
      if (lVar3 == 0) {
        puVar2 = (u8 *)0x0;
      }
      else {
        *(u32 *)(puVar2 + 0x5c) = 0;
        *(u32 *)(puVar2 + 0x18) = 0;
        *puVar2 = 8;
        puVar2[1] = 0;
        puVar2[2] = 0;
        puVar2[3] = 0;
        *(u32 *)(puVar2 + 4) = 0;
        *(u32 *)(puVar2 + 0x58) = 0;
        *(u16 *)(puVar2 + 0xc) = 0;
        *(u16 *)(puVar2 + 0xe) = 1;
        *(u32 *)(puVar2 + 0x54) = 0;
        *(u32 *)(puVar2 + 0x1c) = uVar9;
        ((code)FUN_00521408)(puVar2 + 0x34,0,0x20);
        *(u32 *)(puVar2 + 0x30) = 0;
        *(u32 *)(puVar2 + 0x2c) = 0;
        *(int *)(puVar2 + 0x10) = param_2;
        *(u32 *)(puVar2 + 8) = param_3 & 0x7b | uVar6 | param_3 & 0xf000000;
        *(int *)(puVar2 + 0x14) = param_1;
        if ((param_3 & 0x1000000) == 0) {
          puVar7 = puVar2 + DAT_0077dd20;
          if (((param_3 & 8) != 0) && (param_1 != 0)) {
            *(u8 **)(puVar2 + 0x30) = puVar7;
            puVar7 = puVar7 + param_1 * 4;
          }
          if (((uVar9 != 0) && (param_1 != 0)) && (uVar6 = 0, uVar9 != 0)) {
            if (8 < uVar9) {
              iVar4 = param_1 * 8;
              puVar5 = puVar2;
              do {
                *(u8 **)(puVar5 + 0x34) = puVar7;
                puVar7 = puVar7 + iVar4;
                *(u8 **)(puVar5 + 0x38) = puVar7;
                uVar6 = uVar6 + 8;
                puVar7 = puVar7 + iVar4;
                *(u8 **)(puVar5 + 0x3c) = puVar7;
                puVar7 = puVar7 + iVar4;
                *(u8 **)(puVar5 + 0x40) = puVar7;
                puVar7 = puVar7 + iVar4;
                *(u8 **)(puVar5 + 0x44) = puVar7;
                puVar7 = puVar7 + iVar4;
                *(u8 **)(puVar5 + 0x48) = puVar7;
                puVar7 = puVar7 + iVar4;
                *(u8 **)(puVar5 + 0x4c) = puVar7;
                *(u8 **)(puVar5 + 0x50) = puVar7 + iVar4;
                puVar7 = puVar7 + iVar4 + iVar4;
                puVar5 = puVar5 + 0x20;
              } while (uVar6 < uVar9 - 8);
            }
            if (uVar6 < uVar9) {
              puVar5 = puVar2 + uVar6 * 4;
              do {
                uVar6 = uVar6 + 1;
                *(u8 **)(puVar5 + 0x34) = puVar7;
                puVar7 = puVar7 + param_1 * 8;
                puVar5 = puVar5 + 4;
              } while (uVar6 < uVar9);
            }
          }
          if (param_2 != 0) {
            *(u8 **)(puVar2 + 0x2c) = puVar7;
            iVar4 = 0;
            if (0 < param_2) {
              if (8 < param_2) {
                bVar1 = 0;
                if ((-1 < param_2) && (param_2 < 0x7fffffff)) {
                  bVar1 = 1;
                }
                if (bVar1) {
                  iVar8 = 0;
                  do {
                    iVar4 = iVar4 + 8;
                    *(u16 *)(*(int *)(puVar2 + 0x2c) + iVar8 + 6) = 0xffff;
                    *(u16 *)(*(int *)(puVar2 + 0x2c) + iVar8 + 0xe) = 0xffff;
                    *(u16 *)(*(int *)(puVar2 + 0x2c) + iVar8 + 0x16) = 0xffff;
                    *(u16 *)(*(int *)(puVar2 + 0x2c) + iVar8 + 0x1e) = 0xffff;
                    *(u16 *)(*(int *)(puVar2 + 0x2c) + iVar8 + 0x26) = 0xffff;
                    *(u16 *)(*(int *)(puVar2 + 0x2c) + iVar8 + 0x2e) = 0xffff;
                    *(u16 *)(*(int *)(puVar2 + 0x2c) + iVar8 + 0x36) = 0xffff;
                    *(u16 *)(*(int *)(puVar2 + 0x2c) + iVar8 + 0x3e) = 0xffff;
                    iVar8 = iVar8 + 0x40;
                  } while (iVar4 < param_2 + -8);
                }
              }
              if (iVar4 < param_2) {
                iVar8 = iVar4 << 3;
                do {
                  iVar4 = iVar4 + 1;
                  *(u16 *)(*(int *)(puVar2 + 0x2c) + iVar8 + 6) = 0xffff;
                  iVar8 = iVar8 + 8;
                } while (iVar4 < param_2);
              }
            }
          }
        }
        lVar3 = ((code)FUN_00492f80)(puVar2,1);
        if (lVar3 < 0) {
          ((code)FUN_00495260)(puVar2 + 0x20);
          (*DAT_0096017c)(puVar2);
          puVar2 = (u8 *)0x0;
        }
        else {
          ((code)FUN_004c64b0)(0x77dd20,puVar2);
        }
      }
    }
  }
  return puVar2;
}

#pragma schedule on
// FUN_00493B40

u32 FUN_00493b40(u32 param_1)
{
  short sVar1;
  
  sVar1 = *(short *)((int)param_1 + 0xe);
  sVar1 = sVar1 + 1;
  *(short *)((int)param_1 + 0xe) = sVar1;
  return param_1;
}
#pragma schedule off

// FUN_00493B60 NONMATCHING

u32 FUN_00493b60(u64 param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if (*(short *)(iVar1 + 0xe) + -1 < 1) {
    if (*(int *)(iVar1 + 0x58) != 0) {
      ((code)FUN_004c47e0)();
    }
    *(short *)(iVar1 + 0xe) = *(short *)(iVar1 + 0xe) + -1;
    *(short *)(iVar1 + 0xe) = *(short *)(iVar1 + 0xe) + 1;
    *(u16 *)(iVar1 + 0xc) = *(u16 *)(iVar1 + 0xc) | 0xfff;
    if (*(int *)(iVar1 + 0x54) != 0) {
      ((code)FUN_00495c80)();
      *(u32 *)(iVar1 + 0x54) = 0;
    }
    ((code)FUN_004c6560)(0x77dd20,param_1);
    if (*(int *)(iVar1 + 0x5c) != 0) {
      (*DAT_0096017c)();
      *(u32 *)(iVar1 + 0x5c) = 0;
    }
    ((code)FUN_00495260)(iVar1 + 0x20);
    *(short *)(iVar1 + 0xe) = *(short *)(iVar1 + 0xe) + -1;
    (*DAT_0096017c)(param_1);
  }
  else {
    *(short *)(iVar1 + 0xe) = *(short *)(iVar1 + 0xe) + -1;
  }
  return 1;
}

// FUN_00493C50 NONMATCHING

void FUN_00493c50(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5)

{
  ((code)FUN_004c61b0)(0x77dd20,param_1,param_2,param_3,param_4,param_5);
  return;
}

// FUN_00493C80 NONMATCHING

void FUN_00493c80(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  ((code)FUN_004c5960)(0x77dd20,param_1,param_2,param_3,param_4);
  return;
}

// FUN_00493CB0 NONMATCHING

int FUN_00493cb0(u64 param_1)

{
  u32 uVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  u32 *puVar6;
  int iVar7;
  u32 uStack_50;
  u32 uStack_4c;
  u32 uStack_48;
  u32 uStack_44;
  int iStack_40;
  int iStack_3c;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  int iStack_24;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_4;
  
  lVar4 = ((code)FUN_004c1600)(param_1,1,0,&uStack_4);
  if (lVar4 == 0) {
    iVar2 = 0;
  }
  else if ((uStack_4 < 0x35000) || (0x37002 < uStack_4)) {
    uStack_10 = 2;
    uStack_c = ((code)FUN_004c1d10)(0xffffffff80000004);
    ((code)FUN_004c1c50)(&uStack_10);
    iVar2 = 0;
  }
  else {
    lVar4 = ((code)FUN_004c5250)(param_1,&uStack_30,0x10);
    if (lVar4 == 0x10) {
      iVar2 = ((code)FUN_00493710)(uStack_28,uStack_2c,uStack_30);
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else if ((iStack_24 < 2) || (lVar4 = ((code)FUN_00492f80)(iVar2,iStack_24 + -1), -1 < lVar4)) {
        if (((*(u32 *)(iVar2 + 8) & 0x1000000) == 0) && (*(int *)(iVar2 + 0x14) != 0)) {
          if (((uStack_30 & 8) != 0) &&
             (iVar3 = *(int *)(iVar2 + 0x14) << 2,
             iVar5 = ((code)FUN_004c5250)(param_1,*(u32 *)(iVar2 + 0x30),iVar3), iVar3 != iVar5)) {
            if (*(short *)(iVar2 + 0xe) + -1 < 1) {
              if (*(int *)(iVar2 + 0x58) != 0) {
                ((code)FUN_004c47e0)();
              }
              *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
              ((code)FUN_00492d50)(iVar2);
            }
            else {
              *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
            }
            return 0;
          }
          if (0 < *(int *)(iVar2 + 0x1c)) {
            iVar5 = *(int *)(iVar2 + 0x14);
            iVar7 = 0;
            iVar3 = iVar2;
            if (0 < *(int *)(iVar2 + 0x1c)) {
              do {
                lVar4 = ((code)FUN_004c18b0)(param_1,*(u32 *)(iVar3 + 0x34),iVar5 << 3);
                if (lVar4 == 0) {
                  if (*(short *)(iVar2 + 0xe) + -1 < 1) {
                    if (*(int *)(iVar2 + 0x58) != 0) {
                      ((code)FUN_004c47e0)();
                    }
                    *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
                    ((code)FUN_00492d50)(iVar2);
                  }
                  else {
                    *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
                  }
                  return 0;
                }
                iVar7 = iVar7 + 1;
                iVar3 = iVar3 + 4;
              } while (iVar7 < *(int *)(iVar2 + 0x1c));
            }
          }
          iVar5 = *(int *)(iVar2 + 0x10);
          if (iVar5 != 0) {
            puVar6 = *(u32 **)(iVar2 + 0x2c);
            iVar3 = ((code)FUN_004c5250)(param_1,puVar6,iVar5 << 3);
            if (iVar5 << 3 != iVar3) {
              if (*(short *)(iVar2 + 0xe) + -1 < 1) {
                if (*(int *)(iVar2 + 0x58) != 0) {
                  ((code)FUN_004c47e0)();
                }
                *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
                ((code)FUN_00492d50)(iVar2);
              }
              else {
                *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
              }
              return 0;
            }
            for (; iVar5 != 0; iVar5 = iVar5 + -1) {
              uVar1 = *puVar6;
              *(short *)puVar6 = (short)((u32)uVar1 >> 0x10);
              *(short *)((int)puVar6 + 2) = (short)uVar1;
              uVar1 = puVar6[1];
              *(short *)(puVar6 + 1) = (short)((u32)uVar1 >> 0x10);
              *(short *)((int)puVar6 + 6) = (short)uVar1;
              puVar6 = puVar6 + 2;
            }
          }
        }
        iVar5 = 0;
        if (0 < *(int *)(iVar2 + 0x18)) {
          iVar3 = 0;
          do {
            iVar7 = *(int *)(iVar2 + 0x5c) + iVar3;
            lVar4 = ((code)FUN_004c5250)(param_1,&uStack_50,0x18);
            if (lVar4 != 0x18) {
              if (*(short *)(iVar2 + 0xe) + -1 < 1) {
                if (*(int *)(iVar2 + 0x58) != 0) {
                  ((code)FUN_004c47e0)();
                }
                *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
                ((code)FUN_00492d50)(iVar2);
              }
              else {
                *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
              }
              return 0;
            }
            *(u32 *)(iVar7 + 4) = uStack_50;
            *(u32 *)(iVar7 + 8) = uStack_4c;
            *(u32 *)(iVar7 + 0xc) = uStack_48;
            *(u32 *)(iVar7 + 0x10) = uStack_44;
            if ((iStack_40 == 0) || (iStack_3c == 0)) {
              if ((iStack_40 != 0) &&
                 (lVar4 = ((code)FUN_004c18b0)(param_1,*(u32 *)(iVar7 + 0x14),
                                       *(int *)(iVar2 + 0x14) * 0xc), lVar4 == 0)) {
                if (*(short *)(iVar2 + 0xe) + -1 < 1) {
                  if (*(int *)(iVar2 + 0x58) != 0) {
                    ((code)FUN_004c47e0)();
                  }
                  *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
                  ((code)FUN_00492d50)(iVar2);
                }
                else {
                  *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
                }
                return 0;
              }
              if ((iStack_3c != 0) &&
                 (lVar4 = ((code)FUN_004c18b0)(param_1,*(u32 *)(iVar7 + 0x18),
                                       *(int *)(iVar2 + 0x14) * 0xc), lVar4 == 0)) {
                if (*(short *)(iVar2 + 0xe) + -1 < 1) {
                  if (*(int *)(iVar2 + 0x58) != 0) {
                    ((code)FUN_004c47e0)();
                  }
                  *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
                  ((code)FUN_00492d50)(iVar2);
                }
                else {
                  *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
                }
                return 0;
              }
            }
            else {
              lVar4 = ((code)FUN_004c18b0)(param_1,*(u32 *)(iVar7 + 0x14),
                                   *(int *)(iVar2 + 0x14) * 0x18);
              if (lVar4 == 0) {
                if (*(short *)(iVar2 + 0xe) + -1 < 1) {
                  if (*(int *)(iVar2 + 0x58) != 0) {
                    ((code)FUN_004c47e0)();
                  }
                  *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
                  ((code)FUN_00492d50)(iVar2);
                }
                else {
                  *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
                }
                return 0;
              }
            }
            iVar5 = iVar5 + 1;
            iVar3 = iVar3 + 0x1c;
          } while (iVar5 < *(int *)(iVar2 + 0x18));
        }
        lVar4 = ((code)FUN_004c1600)(param_1,8,0,&uStack_4);
        if (lVar4 == 0) {
          iVar2 = 0;
        }
        else if ((uStack_4 < 0x35000) || (0x37002 < uStack_4)) {
          if (*(short *)(iVar2 + 0xe) + -1 < 1) {
            if (*(int *)(iVar2 + 0x58) != 0) {
              ((code)FUN_004c47e0)();
            }
            *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
            ((code)FUN_00492d50)(iVar2);
          }
          else {
            *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
          }
          uStack_18 = 2;
          uStack_14 = ((code)FUN_004c1d10)(0xffffffff80000004);
          ((code)FUN_004c1c50)(&uStack_18);
          iVar2 = 0;
        }
        else {
          lVar4 = ((code)FUN_004954c0)(param_1,iVar2 + 0x20);
          if (lVar4 == 0) {
            if (*(short *)(iVar2 + 0xe) + -1 < 1) {
              if (*(int *)(iVar2 + 0x58) != 0) {
                ((code)FUN_004c47e0)();
              }
              *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
              ((code)FUN_00492d50)(iVar2);
            }
            else {
              *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
            }
            iVar2 = 0;
          }
          else {
            lVar4 = ((code)FUN_004c5a50)(0x77dd20,param_1,iVar2);
            if (lVar4 == 0) {
              if (*(short *)(iVar2 + 0xe) + -1 < 1) {
                if (*(int *)(iVar2 + 0x58) != 0) {
                  ((code)FUN_004c47e0)();
                }
                *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
                ((code)FUN_00492d50)(iVar2);
              }
              else {
                *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
              }
              iVar2 = 0;
            }
            else {
              lVar4 = ((code)FUN_004933d0)(iVar2);
              if (lVar4 == 0) {
                if (*(short *)(iVar2 + 0xe) + -1 < 1) {
                  if (*(int *)(iVar2 + 0x58) != 0) {
                    ((code)FUN_004c47e0)();
                  }
                  *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
                  ((code)FUN_00492d50)(iVar2);
                }
                else {
                  *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
                }
                iVar2 = 0;
              }
            }
          }
        }
      }
      else {
        if (*(short *)(iVar2 + 0xe) + -1 < 1) {
          if (*(int *)(iVar2 + 0x58) != 0) {
            ((code)FUN_004c47e0)();
          }
          *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
          ((code)FUN_00492d50)(iVar2);
        }
        else {
          *(short *)(iVar2 + 0xe) = *(short *)(iVar2 + 0xe) + -1;
        }
        iVar2 = 0;
      }
    }
    else {
      iVar2 = 0;
    }
  }
  return iVar2;
}

// FUN_004944B0 NONMATCHING

u64 FUN_004944b0(u64 param_1,u32 *param_2)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  
  iVar1 = (int)param_1;
  uVar4 = param_2[1];
  uVar2 = param_2[2];
  uVar3 = param_2[3];
  *(u32 *)(iVar1 + 0x18) = *param_2;
  *(u32 *)(iVar1 + 0x1c) = uVar4;
  *(u32 *)(iVar1 + 0x20) = uVar2;
  *(u32 *)(iVar1 + 0x24) = uVar3;
  if ((*(float *)(iVar1 + 0x18) == *(float *)(iVar1 + 0x1c)) &&
     (*(float *)(iVar1 + 0x18) == *(float *)(iVar1 + 0x20))) {
    *(u8 *)(iVar1 + 3) = 1;
  }
  else {
    *(u8 *)(iVar1 + 3) = 0;
  }
  return param_1;
}

// FUN_00494520 NONMATCHING

void FUN_00494520(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5)

{
  ((code)FUN_004c61b0)(0x77dd40,param_1,param_2,param_3,param_4,param_5);
  return;
}

// FUN_00494550 NONMATCHING

void FUN_00494550(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  ((code)FUN_004c5960)(0x77dd40,param_1,param_2,param_3,param_4);
  return;
}

// FUN_00494580 NONMATCHING

long FUN_00494580(u64 param_1)

{
  int iVar1;
  long lVar2;
  long lVar3;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  float fStack_20;
  u32 uStack_1c;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  int iStack_4;
  
  lVar2 = ((code)FUN_004c1600)(param_1,1,&iStack_4,&uStack_8);
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  else if ((uStack_8 < 0x35000) || (0x37002 < uStack_8)) {
    uStack_10 = 2;
    uStack_c = ((code)FUN_004c1d10)(0xffffffff80000004);
    ((code)FUN_004c1c50)(&uStack_10);
    lVar2 = 0;
  }
  else {
    ((code)FUN_00521408)(&uStack_30,0,0x18);
    iVar1 = ((code)FUN_004c5250)(param_1,&uStack_30,iStack_4);
    if (iStack_4 == iVar1) {
      lVar2 = ((code)FUN_004947c0)(uStack_1c >> 0x10 & 0xff);
      if (lVar2 == 0) {
        lVar2 = 0;
      }
      else {
        iVar1 = (int)lVar2;
        *(u32 *)(iVar1 + 0x14) = uStack_30;
        *(u32 *)(iVar1 + 0x18) = uStack_2c;
        *(u32 *)(iVar1 + 0x1c) = uStack_28;
        *(u32 *)(iVar1 + 0x20) = uStack_24;
        if (uStack_8 < 0x30300) {
          *(float *)(iVar1 + 0x28) = -SQRT(1.0 / (fStack_20 * fStack_20 + 1.0));
        }
        else {
          *(float *)(iVar1 + 0x28) = fStack_20;
        }
        if ((*(float *)(iVar1 + 0x18) == *(float *)(iVar1 + 0x1c)) &&
           (*(float *)(iVar1 + 0x18) == *(float *)(iVar1 + 0x20))) {
          *(u8 *)(iVar1 + 3) = 1;
        }
        else {
          *(u8 *)(iVar1 + 3) = 0;
        }
        *(char *)(iVar1 + 2) = (char)uStack_1c;
        lVar3 = ((code)FUN_004c5a50)(0x77dd40,param_1,lVar2);
        if (lVar3 == 0) {
          lVar2 = 0;
        }
      }
    }
    else {
      lVar2 = 0;
    }
  }
  return lVar2;
}

// FUN_00494760 NONMATCHING

u32 FUN_00494760(u64 param_1)

{
  ((code)FUN_004c6560)(0x77dd40,param_1);
  ((code)FUN_004d18c0)(param_1);
  (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960070 + DAT_007ce830),param_1);
  return 1;
}

// FUN_004947C0 NONMATCHING

long FUN_004947c0(u8 param_1)

{
  long lVar1;
  u8 *puVar2;
  
  lVar1 = (*DAT_00960188)(*(u32 *)((int)(u8 *)DAT_00960070 + DAT_007ce830),0x30012);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else {
    puVar2 = (u8 *)lVar1;
    *puVar2 = 3;
    puVar2[1] = param_1;
    puVar2[2] = 0;
    puVar2[3] = 0;
    *(u32 *)(puVar2 + 4) = 0;
    *(u8 **)(puVar2 + 0x10) = &LAB_004944a0;
    *(u32 *)(puVar2 + 0x14) = 0;
    *(u32 *)(puVar2 + 0x28) = 0;
    *(u32 *)(puVar2 + 0x18) = 0x3f800000;
    *(u32 *)(puVar2 + 0x1c) = 0x3f800000;
    *(u32 *)(puVar2 + 0x20) = 0x3f800000;
    *(u32 *)(puVar2 + 0x24) = 0x3f800000;
    puVar2[3] = 1;
    *(u8 **)(puVar2 + 0x2c) = puVar2 + 0x2c;
    *(u8 **)(puVar2 + 0x30) = puVar2 + 0x2c;
    *(u32 *)(puVar2 + 0x38) = 0;
    *(u32 *)(puVar2 + 0x34) = 0;
    *(short *)(puVar2 + 0x3c) = DAT_0096007a + -1;
    puVar2[2] = 3;
    ((code)FUN_004c64b0)(0x77dd40,lVar1);
  }
  return lVar1;
}

// FUN_004948B0 NONMATCHING

u64 FUN_004948b0(u64 param_1)

{
  ((code)FUN_004c4200)(*(u32 *)((int)(u8 *)DAT_00960070 + DAT_007ce830),0x494490,0);
  ((code)FUN_004c3c30)(*(u32 *)((int)(u8 *)DAT_00960070 + DAT_007ce830));
  DAT_007ce834 = DAT_007ce834 + -1;
  *(u32 *)((int)(u8 *)DAT_00960070 + DAT_007ce830) = 0;
  return param_1;
}

// FUN_00494930 NONMATCHING

u64 FUN_00494930(u64 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  DAT_007ce830 = param_2;
  iVar1 = thunk_FUN_004c3970(DAT_0077dd40,DAT_007cdbe0,0x10,DAT_007cdbe4,0x95ded0,0x40012);
  piVar2 = (int *)((int)(u8 *)DAT_00960070 + DAT_007ce830);
  *piVar2 = iVar1;
  if (*piVar2 == 0) {
    param_1 = 0;
  }
  else {
    DAT_007ce834 = DAT_007ce834 + 1;
  }
  return param_1;
}

// FUN_004949C0 NONMATCHING

u64 FUN_004949c0(u64 param_1,int param_2)

{
  long lVar1;
  
  lVar1 = ((code)FUN_004c1910)(param_1,0x7ce83c,4);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  else if ((param_2 == 8) && (lVar1 = ((code)FUN_004c1910)(param_1,0x7ce838,4), lVar1 == 0)) {
    param_1 = 0;
  }
  return param_1;
}

// FUN_00494A40 NONMATCHING

u64 FUN_00494a40(u64 param_1,u64 param_2,int param_3)

{
  long lVar1;
  
  lVar1 = ((code)FUN_004c17f0)(param_1,*(int *)(param_3 + 8) + 0x2c,4);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  else {
    lVar1 = ((code)FUN_004c17f0)(param_1,*(int *)(param_3 + 8) + 0x30,4);
    if (lVar1 == 0) {
      param_1 = 0;
    }
  }
  return param_1;
}

// FUN_00494AE0 NONMATCHING

u64 FUN_00494ae0(u64 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  DAT_007ce840 = param_2;
  iVar1 = thunk_FUN_004c3970(DAT_0077dd60,DAT_007cdbe8,4,DAT_007cdbec,0x95df00,0x40007);
  piVar2 = (int *)((int)(u8 *)DAT_00960070 + DAT_007ce840);
  *piVar2 = iVar1;
  if (*piVar2 == 0) {
    param_1 = 0;
  }
  else {
    DAT_007ce844 = DAT_007ce844 + 1;
  }
  return param_1;
}

// FUN_00494B70 NONMATCHING

u64 FUN_00494b70(u64 param_1)

{
  if (*(int *)((int)(u8 *)DAT_00960070 + DAT_007ce840) != 0) {
    ((code)FUN_004c3c30)();
    *(u32 *)((int)(u8 *)DAT_00960070 + DAT_007ce840) = 0;
  }
  DAT_007ce844 = DAT_007ce844 + -1;
  return param_1;
}

// FUN_00494BE0 NONMATCHING

long FUN_00494be0(void)

{
  u32 uVar1;
  u32 uVar2;
  long lVar3;
  u32 *puVar4;
  
  lVar3 = (*DAT_00960188)(*(u32 *)((int)(u8 *)DAT_00960070 + DAT_007ce840),0x30007);
  if (lVar3 == 0) {
    lVar3 = 0;
  }
  else {
    puVar4 = (u32 *)lVar3;
    *(u16 *)(puVar4 + 6) = 1;
    *(u8 *)(puVar4 + 1) = 0xff;
    *(u8 *)((int)puVar4 + 5) = 0xff;
    *(u8 *)((int)puVar4 + 6) = 0xff;
    *(u8 *)((int)puVar4 + 7) = 0xff;
    *puVar4 = 0;
    puVar4[2] = 0;
    uVar2 = DAT_0077dd80;
    uVar1 = DAT_0077dd7c;
    puVar4[3] = DAT_0077dd78;
    puVar4[4] = uVar1;
    puVar4[5] = uVar2;
    ((code)FUN_004c64b0)(0x77dd60,lVar3);
  }
  return lVar3;
}

// FUN_00494CC0 NONMATCHING

u32 FUN_00494cc0(u64 param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if (*(short *)(iVar1 + 0x18) == 1) {
    ((code)FUN_004c6560)(0x77dd60,param_1);
    ((code)FUN_00494d50)(param_1,0);
    (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960070 + DAT_007ce840),param_1);
  }
  else {
    *(short *)(iVar1 + 0x18) = *(short *)(iVar1 + 0x18) + -1;
  }
  return 1;
}

// FUN_00494D50 NONMATCHING

u64 FUN_00494d50(u64 param_1,long param_2)

{
  int iVar1;
  
  iVar1 = (int)param_2;
  if (param_2 != 0) {
    *(int *)(iVar1 + 0x54) = *(int *)(iVar1 + 0x54) + 1;
  }
  if (*(int *)param_1 != 0) {
    ((code)FUN_004d0f00)();
  }
  *(int *)param_1 = iVar1;
  return param_1;
}

// FUN_00494DB0 NONMATCHING

void FUN_00494db0(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5)

{
  ((code)FUN_004c61b0)(0x77dd60,param_1,param_2,param_3,param_4,param_5);
  return;
}

// FUN_00494DE0 NONMATCHING

void FUN_00494de0(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  ((code)FUN_004c5960)(0x77dd60,param_1,param_2,param_3,param_4);
  return;
}

// FUN_00494E10 NONMATCHING

void FUN_00494e10(u64 param_1,u64 param_2)

{
  ((code)FUN_004c5a00)(0x77dd60,param_1,param_2);
  return;
}

// FUN_00494E30 NONMATCHING

long FUN_00494e30(u64 param_1)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  long lVar4;
  long lVar5;
  u32 *puVar6;
  int *piVar7;
  u8 auStack_40 [4];
  u8 uStack_3c;
  u8 uStack_3b;
  u8 uStack_3a;
  u8 uStack_39;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u8 uStack_c;
  u8 uStack_b;
  u8 uStack_a;
  u8 uStack_9;
  u32 uStack_8;
  int iStack_4;
  
  lVar4 = ((code)FUN_004c1600)(param_1,1,&iStack_4,&uStack_8);
  if (lVar4 == 0) {
    lVar4 = 0;
  }
  else if ((uStack_8 < 0x35000) || (0x37002 < uStack_8)) {
    uStack_20 = 2;
    uStack_1c = ((code)FUN_004c1d10)(0xffffffff80000004);
    ((code)FUN_004c1c50)(&uStack_20);
    lVar4 = 0;
  }
  else {
    ((code)FUN_00521408)(auStack_40,0,0x1c);
    iVar3 = ((code)FUN_004c5250)(param_1,auStack_40,iStack_4);
    if (iStack_4 == iVar3) {
      lVar4 = (*DAT_00960188)(*(u32 *)((int)(u8 *)DAT_00960070 + DAT_007ce840),0x30007);
      if (lVar4 == 0) {
        lVar4 = 0;
      }
      else {
        uStack_c = 0xff;
        uStack_b = 0xff;
        uStack_a = 0xff;
        uStack_9 = 0xff;
        puVar6 = (u32 *)lVar4;
        *(u16 *)(puVar6 + 6) = 1;
        *(u8 *)(puVar6 + 1) = 0xff;
        *(u8 *)((int)puVar6 + 5) = 0xff;
        *(u8 *)((int)puVar6 + 6) = 0xff;
        *(u8 *)((int)puVar6 + 7) = 0xff;
        *puVar6 = 0;
        puVar6[2] = 0;
        uVar2 = DAT_0077dd80;
        uVar1 = DAT_0077dd7c;
        puVar6[3] = DAT_0077dd78;
        puVar6[4] = uVar1;
        puVar6[5] = uVar2;
        ((code)FUN_004c64b0)(0x77dd60,lVar4);
      }
      if (lVar4 == 0) {
        lVar4 = 0;
      }
      else {
        piVar7 = (int *)lVar4;
        *(u8 *)(piVar7 + 1) = uStack_3c;
        *(u8 *)((int)piVar7 + 5) = uStack_3b;
        *(u8 *)((int)piVar7 + 6) = uStack_3a;
        *(u8 *)((int)piVar7 + 7) = uStack_39;
        piVar7[3] = iStack_30;
        piVar7[4] = iStack_2c;
        piVar7[5] = iStack_28;
        *piVar7 = 0;
        if (iStack_34 != 0) {
          lVar5 = ((code)FUN_004c1600)(param_1,6,0,&uStack_8);
          if (lVar5 == 0) {
            if ((short)piVar7[6] == 1) {
              ((code)FUN_004c6560)(0x77dd60,lVar4);
              if (*piVar7 != 0) {
                ((code)FUN_004d0f00)();
              }
              *piVar7 = 0;
              (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960070 + DAT_007ce840),lVar4);
            }
            else {
              *(short *)(piVar7 + 6) = (short)piVar7[6] + -1;
            }
            return 0;
          }
          if ((uStack_8 < 0x35000) || (0x37002 < uStack_8)) {
            if ((short)piVar7[6] == 1) {
              ((code)FUN_004c6560)(0x77dd60,lVar4);
              if (*piVar7 != 0) {
                ((code)FUN_004d0f00)();
              }
              *piVar7 = 0;
              (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960070 + DAT_007ce840),lVar4);
            }
            else {
              *(short *)(piVar7 + 6) = (short)piVar7[6] + -1;
            }
            uStack_18 = 2;
            uStack_14 = ((code)FUN_004c1d10)(0xffffffff80000004);
            ((code)FUN_004c1c50)(&uStack_18);
            return 0;
          }
          iVar3 = ((code)FUN_004c83c0)(param_1);
          *piVar7 = iVar3;
        }
        DAT_007ce83c = 0;
        DAT_007ce838 = 0;
        lVar5 = ((code)FUN_004c5a50)(0x77dd60,param_1,lVar4);
        if (lVar5 == 0) {
          if ((short)piVar7[6] == 1) {
            ((code)FUN_004c6560)(0x77dd60,lVar4);
            if (*piVar7 != 0) {
              ((code)FUN_004d0f00)();
            }
            *piVar7 = 0;
            (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960070 + DAT_007ce840),lVar4);
          }
          else {
            *(short *)(piVar7 + 6) = (short)piVar7[6] + -1;
          }
          lVar4 = 0;
        }
        else if (DAT_007ce83c != 0) {
          ((code)FUN_004c5c30)(0x77dd60,DAT_007ce83c,lVar4,DAT_007ce838);
        }
      }
    }
    else {
      lVar4 = 0;
    }
  }
  return lVar4;
}

// FUN_00495260 NONMATCHING

u64 FUN_00495260(u64 param_1)

{
  u32 *puVar1;
  int iVar2;
  u32 *puVar3;
  u32 *puVar4;
  int iVar5;
  
  puVar3 = (u32 *)param_1;
  puVar1 = (u32 *)*puVar3;
  if (puVar1 != (u32 *)0x0) {
    iVar2 = puVar3[1];
    iVar5 = 0;
    puVar4 = puVar1;
    if (0 < iVar2) {
      do {
        ((code)FUN_00494cc0)(*puVar4);
        iVar5 = iVar5 + 1;
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      } while (iVar5 < iVar2);
    }
    (*DAT_0096017c)(puVar1);
    *puVar3 = 0;
  }
  puVar3[1] = 0;
  puVar3[2] = 0;
  return param_1;
}

#pragma optimization_level 3
// FUN_00495300

u32 FUN_00495300(u32 param_1)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)param_1;
  puVar1[2] = 0;
  *puVar1 = 0;
  puVar1[1] = 0;
  return param_1;
}
#pragma optimization_level 2


#pragma optimization_level 3
// FUN_00495320
u32 FUN_00495320(int *param_1,int param_2)
{
  return *(u32 *)(*param_1 + param_2 * 4);
}
#pragma optimization_level 2

// FUN_00495340 NONMATCHING

int FUN_00495340(int *param_1,int param_2)

{
  long lVar1;
  int iVar2;
  u32 uStack_8;
  u32 uStack_4;
  
  if (param_1[1] < param_1[2]) {
    *(int *)(*param_1 + param_1[1] * 4) = param_2;
    *(short *)(param_2 + 0x18) = *(short *)(param_2 + 0x18) + 1;
    param_1[1] = param_1[1] + 1;
    iVar2 = param_1[1] + -1;
  }
  else {
    iVar2 = (param_1[2] + 0x14) * 4;
    if (*param_1 == 0) {
      lVar1 = (*DAT_00960178)(iVar2,0x1030008);
    }
    else {
      lVar1 = (*DAT_00960180)(*param_1,iVar2,0x1030008);
    }
    if (lVar1 == 0) {
      uStack_8 = 2;
      uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,iVar2);
      ((code)FUN_004c1c50)(&uStack_8);
      iVar2 = -1;
    }
    else {
      *param_1 = (int)lVar1;
      param_1[2] = param_1[2] + 0x14;
      *(int *)((int)lVar1 + param_1[1] * 4) = param_2;
      *(short *)(param_2 + 0x18) = *(short *)(param_2 + 0x18) + 1;
      param_1[1] = param_1[1] + 1;
      iVar2 = param_1[1] + -1;
    }
  }
  return iVar2;
}

// FUN_00495480 NONMATCHING

void FUN_00495480(int *param_1,int param_2)

{
  u8 bVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = param_1[1] + -1;
  if (0 < param_1[1]) {
    piVar3 = (int *)(*param_1 + iVar2 * 4);
    do {
      if (*piVar3 == param_2) {
        return;
      }
      piVar3 = piVar3 + -1;
      bVar1 = 0 < iVar2;
      iVar2 = iVar2 + -1;
    } while (bVar1);
  }
  return;
}

// FUN_004954C0 NONMATCHING

long FUN_004954c0(u64 param_1,long param_2)

{
  u32 *puVar1;
  int *piVar2;
  long lVar3;
  long lVar4;
  int *piVar5;
  int *piVar6;
  u32 *puVar7;
  int iVar8;
  int iVar9;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_c;
  u8 auStack_8 [4];
  int iStack_4;
  
  lVar3 = ((code)FUN_004c1600)(param_1,1,auStack_8,&uStack_c);
  if (lVar3 == 0) {
    param_2 = 0;
  }
  else if ((uStack_c < 0x35000) || (0x37002 < uStack_c)) {
    uStack_20 = 2;
    uStack_1c = ((code)FUN_004c1d10)(0xffffffff80000004);
    ((code)FUN_004c1c50)(&uStack_20);
    param_2 = 0;
  }
  else {
    lVar3 = ((code)FUN_004c1910)(param_1,&iStack_4,4);
    iVar9 = iStack_4;
    if (lVar3 == 0) {
      param_2 = 0;
    }
    else {
      piVar5 = (int *)param_2;
      piVar5[2] = 0;
      *piVar5 = 0;
      piVar5[1] = 0;
      if (iStack_4 != 0) {
        lVar3 = param_2;
        if (piVar5[2] < iStack_4) {
          iVar8 = iStack_4 << 2;
          if (*piVar5 == 0) {
            lVar4 = (*DAT_00960178)(iVar8,0x1030008);
          }
          else {
            lVar4 = (*DAT_00960180)(*piVar5,iVar8,0x1030008);
          }
          if (lVar4 == 0) {
            uStack_28 = 2;
            uStack_24 = ((code)FUN_004c1d10)(0xffffffff80000013,iVar8);
            ((code)FUN_004c1c50)(&uStack_28);
            lVar3 = 0;
          }
          else {
            *piVar5 = (int)lVar4;
            piVar5[2] = iVar9;
          }
        }
        if (lVar3 == 0) {
          puVar1 = (u32 *)*piVar5;
          if (puVar1 != (u32 *)0x0) {
            iVar9 = piVar5[1];
            iVar8 = 0;
            puVar7 = puVar1;
            if (0 < iVar9) {
              do {
                ((code)FUN_00494cc0)(*puVar7);
                iVar8 = iVar8 + 1;
                *puVar7 = 0;
                puVar7 = puVar7 + 1;
              } while (iVar8 < iVar9);
            }
            (*DAT_0096017c)(puVar1);
            *piVar5 = 0;
          }
          piVar5[1] = 0;
          param_2 = 0;
          piVar5[2] = 0;
        }
        else {
          piVar2 = (int *)(*DAT_00960178)(iStack_4 << 2,0x10501);
          lVar3 = ((code)FUN_004c1910)(param_1,piVar2,iStack_4 << 2);
          if (lVar3 == 0) {
            (*DAT_0096017c)(piVar2);
            puVar1 = (u32 *)*piVar5;
            if (puVar1 != (u32 *)0x0) {
              iVar9 = piVar5[1];
              iVar8 = 0;
              puVar7 = puVar1;
              if (0 < iVar9) {
                do {
                  ((code)FUN_00494cc0)(*puVar7);
                  iVar8 = iVar8 + 1;
                  *puVar7 = 0;
                  puVar7 = puVar7 + 1;
                } while (iVar8 < iVar9);
              }
              (*DAT_0096017c)(puVar1);
              *piVar5 = 0;
            }
            piVar5[1] = 0;
            param_2 = 0;
            piVar5[2] = 0;
          }
          else {
            iVar9 = 0;
            piVar6 = piVar2;
            if (0 < iStack_4) {
              do {
                if (*piVar6 < 0) {
                  lVar3 = ((code)FUN_004c1600)(param_1,7,0,&uStack_c);
                  if (lVar3 == 0) {
                    (*DAT_0096017c)(piVar2);
                    puVar1 = (u32 *)*piVar5;
                    if (puVar1 != (u32 *)0x0) {
                      iVar9 = piVar5[1];
                      iVar8 = 0;
                      puVar7 = puVar1;
                      if (0 < iVar9) {
                        do {
                          ((code)FUN_00494cc0)(*puVar7);
                          iVar8 = iVar8 + 1;
                          *puVar7 = 0;
                          puVar7 = puVar7 + 1;
                        } while (iVar8 < iVar9);
                      }
                      (*DAT_0096017c)(puVar1);
                      *piVar5 = 0;
                    }
                    piVar5[1] = 0;
                    piVar5[2] = 0;
                    return 0;
                  }
                  if ((uStack_c < 0x35000) || (0x37002 < uStack_c)) {
                    uStack_18 = 2;
                    uStack_14 = ((code)FUN_004c1d10)(0xffffffff80000004);
                    ((code)FUN_004c1c50)(&uStack_18);
                    (*DAT_0096017c)(piVar2);
                    puVar1 = (u32 *)*piVar5;
                    if (puVar1 != (u32 *)0x0) {
                      iVar9 = piVar5[1];
                      iVar8 = 0;
                      puVar7 = puVar1;
                      if (0 < iVar9) {
                        do {
                          ((code)FUN_00494cc0)(*puVar7);
                          iVar8 = iVar8 + 1;
                          *puVar7 = 0;
                          puVar7 = puVar7 + 1;
                        } while (iVar8 < iVar9);
                      }
                      (*DAT_0096017c)(puVar1);
                      *piVar5 = 0;
                    }
                    piVar5[1] = 0;
                    piVar5[2] = 0;
                    return 0;
                  }
                  iVar8 = ((code)FUN_00494e30)(param_1);
                  if (iVar8 == 0) {
                    (*DAT_0096017c)(piVar2);
                    puVar1 = (u32 *)*piVar5;
                    if (puVar1 != (u32 *)0x0) {
                      iVar9 = piVar5[1];
                      iVar8 = 0;
                      puVar7 = puVar1;
                      if (0 < iVar9) {
                        do {
                          ((code)FUN_00494cc0)(*puVar7);
                          iVar8 = iVar8 + 1;
                          *puVar7 = 0;
                          puVar7 = puVar7 + 1;
                        } while (iVar8 < iVar9);
                      }
                      (*DAT_0096017c)(puVar1);
                      *piVar5 = 0;
                    }
                    piVar5[1] = 0;
                    piVar5[2] = 0;
                    return 0;
                  }
                }
                else {
                  iVar8 = *(int *)(*piVar5 + *piVar6 * 4);
                  *(short *)(iVar8 + 0x18) = *(short *)(iVar8 + 0x18) + 1;
                }
                ((code)FUN_00495340)(param_2,iVar8);
                ((code)FUN_00494cc0)(iVar8);
                iVar9 = iVar9 + 1;
                piVar6 = piVar6 + 1;
              } while (iVar9 < iStack_4);
            }
            (*DAT_0096017c)(piVar2);
          }
        }
      }
    }
  }
  return param_2;
}

#pragma tailcall on
// FUN_004959C0

int FUN_004959c0(u64 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x004959d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  return DAT_00960178_abs[0](param_1,0x30502);
}
#pragma tailcall off
#pragma optimization_level 2
#pragma schedule on
// FUN_004959E0 NONMATCHING
u64 FUN_004959e0(u64 param_1)
{
  u32 callback;

  DAT_007ce854 = DAT_007ce854 - 1;
  if (DAT_007ce854 == 0) {
    callback = DAT_007ce848;
    if (callback != 0) {
      FUN_004c3c30_typed(callback);
      DAT_007ce848 = 0;
    }
  }
  return param_1;
}
#pragma schedule off



// FUN_00495A30 NONMATCHING



u64 FUN_00495a30(u64 param_1,int param_2)

{
  int iVar1;
  long lVar2;
  
  DAT_007ce850 = param_2;
  if (DAT_007ce854 == 0) {
    lVar2 = ((code)FUN_004c3b50)(0xc,0x32,4,0x40502);
    DAT_007ce848 = (u32)lVar2;
    if (lVar2 == 0) {
      return 0;
    }
  }
  iVar1 = DAT_007ce850;
  *(u16 *)((int)(u8 *)DAT_00960070 + DAT_007ce850) = 1;
  DAT_007ce854 = DAT_007ce854 + 1;
  *(u8 *)((int)(u8 *)DAT_00960078 + iVar1) = 3;
  *(u8 *)((int)(u8 *)DAT_00960078 + iVar1 + 1) = 4;
  *(u8 *)((int)(u8 *)DAT_0096007a + iVar1) = 5;
  ((u8 *)DAT_0096007c)[iVar1] = 1;
  *(u8 *)((int)(u8 *)DAT_00960080 + iVar1) = 2;
  *(u8 *)((int)(u8 *)DAT_00960088 + iVar1) = 6;
  *(u8 *)((int)(u8 *)DAT_00960098 + iVar1) = 4;
  *(u8 *)((int)(u8 *)DAT_00960098 + iVar1 + 1) = 8;
  *(u8 *)((int)(u8 *)DAT_00960098 + iVar1 + 2) = 0;
  *(u8 *)((int)(u8 *)DAT_00960098 + iVar1 + 3) = 1;
  *(u8 *)((int)(u8 *)DAT_0096009c + iVar1) = 2;
  *(u8 *)((int)(u8 *)DAT_0096009c + iVar1 + 1) = 0x10;
  return param_1;
}

// FUN_00495B10 NONMATCHING

long FUN_00495b10(long param_1)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int *piVar4;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  lVar2 = (*DAT_00960188)(DAT_007ce848,0x30502);
  if (lVar2 == 0) {
    uStack_10 = 2;
    uStack_c = ((code)FUN_004c1d10)(0xffffffff80000013,0xc);
    ((code)FUN_004c1c50)(&uStack_10);
    lVar2 = 0;
  }
  else {
    piVar4 = (int *)lVar2;
    piVar4[1] = 0;
    if (param_1 == 0) {
      piVar4[2] = 0;
      *piVar4 = 0;
    }
    else {
      iVar3 = (int)param_1 * 0x14;
      iVar1 = (*DAT_00960178)(iVar3,0x1030502);
      piVar4[2] = iVar1;
      if (piVar4[2] == 0) {
        (*DAT_0096018c)(DAT_007ce848,lVar2);
        uStack_8 = 2;
        uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,iVar3);
        ((code)FUN_004c1c50)(&uStack_8);
        lVar2 = 0;
      }
      else {
        *piVar4 = (int)param_1;
      }
    }
  }
  return lVar2;
}

// FUN_00495C20 NONMATCHING

u32 FUN_00495c20(u64 param_1)

{
  if (*(int *)((int)param_1 + 8) != 0) {
    (*DAT_0096017c)();
    *(u32 *)((int)param_1 + 8) = 0;
  }
  (*DAT_0096018c)(DAT_007ce848,param_1);
  return 1;
}

// FUN_00495C80 NONMATCHING

u32 FUN_00495c80(int *param_1)

{
  if ((((*param_1 != 0) || ((short)param_1[1] != 0)) ||
      (*(short *)((int)param_1 + 6) != 0)) ||
     (param_1[2] != 0 || (param_1[3] != 0))) {
    (*DAT_0096017c)();
  }
  return 1;
}

// FUN_00495CF0 NONMATCHING

u64
FUN_00495cf0(u64 param_1,u32 param_2,u16 param_3,u16 param_4,
            u16 param_5,u16 param_6,u16 param_7,u16 param_8,
            u16 param_9)

{
  u32 uVar1;
  long lVar2;
  u32 *puVar3;
  int iVar4;
  u32 uStack_8;
  u32 uStack_4;
  
  puVar3 = (u32 *)param_1;
  uVar1 = puVar3[1];
  if (*puVar3 <= uVar1) {
    iVar4 = (uVar1 + 1) * 0x14;
    if (uVar1 == 0) {
      lVar2 = (*DAT_00960178)(0x14,0x1030502);
    }
    else {
      lVar2 = (*DAT_00960180)(puVar3[2],iVar4,0x1030502);
    }
    if (lVar2 == 0) {
      uStack_8 = 2;
      uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,iVar4);
      ((code)FUN_004c1c50)(&uStack_8);
      return 0;
    }
    puVar3[2] = (u32)lVar2;
    *puVar3 = puVar3[1] + 1;
  }
  *(u32 *)(puVar3[1] * 0x14 + puVar3[2] + 8) = param_2;
  *(u16 *)(puVar3[2] + puVar3[1] * 0x14) = param_3;
  *(u16 *)(puVar3[1] * 0x14 + puVar3[2] + 2) = param_4;
  *(u16 *)(puVar3[1] * 0x14 + puVar3[2] + 4) = param_5;
  *(u16 *)(puVar3[1] * 0x14 + puVar3[2] + 0xc) = param_6;
  *(u16 *)(puVar3[1] * 0x14 + puVar3[2] + 0xe) = param_7;
  *(u16 *)(puVar3[1] * 0x14 + puVar3[2] + 0x10) = param_8;
  *(u16 *)(puVar3[1] * 0x14 + puVar3[2] + 0x12) = param_9;
  puVar3[1] = puVar3[1] + 1;
  return param_1;
}

// FUN_00495F10 NONMATCHING

u64 FUN_00495f10(u64 param_1,code *param_2,u64 param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  u32 uVar4;
  
  iVar2 = (int)param_1;
  uVar4 = (u32)*(u16 *)(iVar2 + 4);
  iVar3 = *(int *)(iVar2 + 0xc) + iVar2 + 0x10;
  if (*(u16 *)(iVar2 + 4) != 0) {
    do {
      uVar4 = uVar4 - 1;
      lVar1 = (*param_2)(iVar3,param_1,param_3);
      if (lVar1 == 0) {
        return param_1;
      }
      iVar3 = iVar3 + 0xc;
    } while (uVar4 != 0);
  }
  return param_1;
}

// FUN_00495FB0 NONMATCHING

u64 FUN_00495fb0(u32 *param_1,char *param_2,u64 param_3,u64 param_4)

{
  u32 uVar1;
  long lVar2;
  u32 *puVar3;
  u32 uVar4;
  u16 *puVar5;
  u32 uVar6;
  u32 *puVar7;
  u32 uVar8;
  u32 auStack_420 [258];
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  uStack_10 = *param_1;
  uStack_8 = param_1[2];
  uStack_c = (u32)*(u16 *)(param_1 + 1);
  lVar2 = ((code)FUN_004c17f0)(param_3,&uStack_10,0xc);
  if (lVar2 == 0) {
    param_3 = 0;
  }
  else {
    puVar7 = param_1 + 4;
    uVar8 = (u32)*(u16 *)(param_1 + 1);
    if (*(u16 *)(param_1 + 1) != 0) {
      do {
        uVar8 = uVar8 - 1;
        uStack_18 = puVar7[1];
        lVar2 = ((code)FUN_00495480)(param_4,puVar7[2]);
        uStack_14 = (u32)lVar2;
        if (lVar2 < 0) {
          uStack_14 = 0;
        }
        lVar2 = ((code)FUN_004c17f0)(param_3,&uStack_18,8);
        if (lVar2 == 0) {
          return 0;
        }
        if (((*param_2 == '\b') && ((*(u32 *)(param_2 + 8) & 0x1000000) == 0)) ||
           ((*param_2 == '\a' && ((*(u32 *)(param_2 + 8) & 0x1000000) == 0)))) {
          puVar5 = (u16 *)*puVar7;
          for (uVar6 = puVar7[1]; uVar6 != 0; uVar6 = uVar6 - uVar4) {
            uVar4 = uVar6;
            if (0xff < uVar6) {
              uVar4 = 0x100;
            }
            uVar1 = 0;
            if (uVar4 != 0) {
              if (8 < uVar4) {
                puVar3 = auStack_420;
                do {
                  uVar1 = uVar1 + 8;
                  *puVar3 = (u32)*puVar5;
                  puVar3[1] = (u32)puVar5[1];
                  puVar3[2] = (u32)puVar5[2];
                  puVar3[3] = (u32)puVar5[3];
                  puVar3[4] = (u32)puVar5[4];
                  puVar3[5] = (u32)puVar5[5];
                  puVar3[6] = (u32)puVar5[6];
                  puVar3[7] = (u32)puVar5[7];
                  puVar5 = puVar5 + 8;
                  puVar3 = puVar3 + 8;
                } while (uVar1 < uVar4 - 8);
              }
              if (uVar1 < uVar4) {
                puVar3 = auStack_420 + uVar1;
                do {
                  uVar1 = uVar1 + 1;
                  *puVar3 = (u32)*puVar5;
                  puVar5 = puVar5 + 1;
                  puVar3 = puVar3 + 1;
                } while (uVar1 < uVar4);
              }
            }
            lVar2 = ((code)FUN_004c17f0)(param_3,auStack_420,uVar4 << 2);
            if (lVar2 == 0) {
              return 0;
            }
          }
        }
        puVar7 = puVar7 + 3;
      } while (uVar8 != 0);
    }
  }
  return param_3;
}

// FUN_00496230 NONMATCHING

long FUN_00496230(u64 param_1,char *param_2,u32 param_3)

{
  char cVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  u32 uVar5;
  int *piVar6;
  int *piVar7;
  u32 uVar8;
  u32 uVar9;
  u32 *puVar10;
  u32 auStack_420 [258];
  int iStack_18;
  u32 uStack_14;
  u32 uStack_10;
  int iStack_c;
  int iStack_8;
  
  lVar2 = ((code)FUN_004c1910)(param_1,&uStack_10,0xc);
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  else {
    iVar4 = iStack_c * 0x10 + 0x10;
    if (((*param_2 == '\b') && ((*(u32 *)(param_2 + 8) & 0x1000000) == 0)) ||
       ((*param_2 == '\a' && ((*(u32 *)(param_2 + 8) & 0x1000000) == 0)))) {
      iVar4 = iVar4 + iStack_8 * 2;
    }
    lVar2 = (*DAT_00960178)(iVar4,0x30502);
    if (lVar2 != 0) {
      puVar10 = (u32 *)lVar2;
      piVar7 = (int *)(puVar10 + 4);
      *puVar10 = uStack_10;
      *(short *)(puVar10 + 1) = (short)iStack_c;
      piVar6 = piVar7 + iStack_c * 3;
      *(u16 *)((int)puVar10 + 6) = *(u16 *)((int)(u8 *)DAT_00960070 + DAT_007ce850);
      puVar10[2] = iStack_8;
      puVar10[3] = 0;
      *(short *)((int)(u8 *)DAT_00960070 + DAT_007ce850) =
           *(short *)((int)(u8 *)DAT_00960070 + DAT_007ce850) + 1;
      uVar9 = (u32)*(u16 *)(puVar10 + 1);
      if (*(u16 *)(puVar10 + 1) != 0) {
        do {
          uVar9 = uVar9 - 1;
          lVar3 = ((code)FUN_004c1910)(param_1,&iStack_18,8);
          if (lVar3 == 0) {
            return 0;
          }
          piVar7[1] = iStack_18;
          iVar4 = ((code)FUN_00495320)(param_3,uStack_14);
          piVar7[2] = iVar4;
          cVar1 = *param_2;
          *piVar7 = (int)piVar6;
          if (((cVar1 == '\b') && ((*(u32 *)(param_2 + 8) & 0x1000000) == 0)) ||
             ((cVar1 == '\a' && ((*(u32 *)(param_2 + 8) & 0x1000000) == 0)))) {
            uVar8 = piVar7[1];
            while (uVar8 != 0) {
              puVar10 = auStack_420;
              uVar5 = uVar8;
              if (0xff < uVar8) {
                uVar5 = 0x100;
              }
              lVar3 = ((code)FUN_004c1910)(param_1,puVar10,uVar5 << 2);
              if (lVar3 == 0) {
                return 0;
              }
              uVar8 = uVar8 - uVar5;
              for (; uVar5 != 0; uVar5 = uVar5 - 1) {
                *(short *)piVar6 = (short)*puVar10;
                puVar10 = puVar10 + 1;
                piVar6 = (int *)((int)piVar6 + 2);
              }
            }
          }
          piVar7 = piVar7 + 3;
        } while (uVar9 != 0);
      }
    }
  }
  return lVar2;
}

// FUN_004964F0 NONMATCHING

int FUN_004964f0(int param_1,char *param_2)

{
  int iVar1;
  
  if (((*param_2 == '\b') && ((*(u32 *)(param_2 + 8) & 0x1000000) != 0)) ||
     ((*param_2 == '\a' && ((*(u32 *)(param_2 + 8) & 0x1000000) != 0)))) {
    iVar1 = (u32)*(u16 *)(param_1 + 4) * 8 + 0xc;
  }
  else {
    iVar1 = (u32)*(u16 *)(param_1 + 4) * 8 + 0xc + *(int *)(param_1 + 8) * 4;
  }
  return iVar1;
}

#pragma schedule on
// FUN_00496580 NONMATCHING
void FUN_00496580(void)
{
  u8 *puVar1;
  int iVar2;

  puVar1 = (u8 *)DAT_00960070_abs;
  iVar2 = DAT_007ce850;
  *(short *)(puVar1 + iVar2) = *(short *)(puVar1 + iVar2) + 1;
  return;
}

// FUN_004967A0 NONMATCHING

u64 FUN_004967a0(u64 param_1)

{
  u16 uVar1;
  u16 uVar2;
  u16 uVar3;
  int iVar4;
  u8 *puVar5;
  u8 *puVar6;
  u16 *puVar7;
  u32 uVar8;
  u32 uVar9;
  u32 *puVar10;
  u16 *puVar11;
  u32 uVar12;
  u32 uVar13;
  u32 uVar14;
  u32 uVar15;
  u16 *puVar16;
  
  puVar10 = (u32 *)param_1;
  uVar15 = puVar10[1];
  puVar16 = (u16 *)*puVar10;
  uVar13 = 0;
  uVar12 = 0;
  uVar8 = 0;
  uVar14 = uVar15 / 3;
  if (uVar15 != 0) {
    puVar7 = puVar16;
    uVar12 = uVar13;
    if (8 < uVar15) {
      do {
        uVar8 = uVar8 + 8;
        uVar12 = uVar13 | *puVar7 | (u32)puVar7[1] | (u32)puVar7[2] | (u32)puVar7[3] |
                 (u32)puVar7[4] | (u32)puVar7[5] | (u32)puVar7[6] | (u32)puVar7[7];
        puVar7 = puVar7 + 8;
        uVar13 = uVar12;
      } while (uVar8 < uVar15 - 8);
    }
    if (uVar8 < uVar15) {
      puVar7 = puVar16 + uVar8;
      do {
        uVar8 = uVar8 + 1;
        uVar12 = uVar12 | *puVar7;
        puVar7 = puVar7 + 1;
      } while (uVar8 < uVar15);
    }
  }
  uVar15 = uVar12 + 0x1f >> 3;
  puVar6 = (u8 *)(*DAT_00960178)(uVar15,0x10502);
  if (puVar6 != (u8 *)0x0) {
    iVar4 = puVar10[1];
    puVar7 = (u16 *)(*DAT_00960178)(iVar4 << 1,0x10502);
    if (puVar7 != (u16 *)0x0) {
      ((code)FUN_00521250)(puVar7,puVar16,iVar4 << 1);
      uVar13 = 0;
      uVar12 = uVar15;
      puVar5 = puVar6;
      if (uVar14 != 0) {
        do {
          for (; uVar12 != 0; uVar12 = uVar12 - 1) {
            *puVar5 = 0;
            puVar5 = puVar5 + 1;
          }
          uVar12 = 0;
          puVar11 = puVar7;
          if (uVar14 != 0) {
            do {
              uVar1 = puVar11[1];
              uVar2 = *puVar11;
              uVar3 = puVar11[2];
              if ((uVar3 & uVar2 & uVar1) != 0xffff) {
                uVar9 = 1 << (uVar2 & 0x1f);
                uVar8 = *(u32 *)(puVar6 + ((int)(u32)uVar2 >> 5) * 4);
                if ((((uVar9 & uVar8) == 0) &&
                    ((1 << (uVar1 & 0x1f) & *(u32 *)(puVar6 + ((int)(u32)uVar1 >> 5) * 4)) == 0))
                   && ((1 << (uVar3 & 0x1f) & *(u32 *)(puVar6 + ((int)(u32)uVar3 >> 5) * 4)) == 0)
                   ) {
                  uVar13 = uVar13 + 1;
                  *(u32 *)(puVar6 + ((int)(u32)uVar2 >> 5) * 4) = uVar8 | uVar9;
                  *(u32 *)(puVar6 + ((int)(u32)puVar11[1] >> 5) * 4) =
                       *(u32 *)(puVar6 + ((int)(u32)puVar11[1] >> 5) * 4) |
                       1 << (puVar11[1] & 0x1f);
                  *(u32 *)(puVar6 + ((int)(u32)puVar11[2] >> 5) * 4) =
                       *(u32 *)(puVar6 + ((int)(u32)puVar11[2] >> 5) * 4) |
                       1 << (puVar11[2] & 0x1f);
                  *puVar16 = *puVar11;
                  puVar16[1] = puVar11[1];
                  puVar16[2] = puVar11[2];
                  puVar11[2] = 0xffff;
                  puVar16 = puVar16 + 3;
                  puVar11[1] = 0xffff;
                  *puVar11 = 0xffff;
                }
              }
              uVar12 = uVar12 + 1;
              puVar11 = puVar11 + 3;
            } while (uVar12 < uVar14);
          }
          uVar12 = uVar15;
          puVar5 = puVar6;
        } while (uVar13 < uVar14);
      }
      (*DAT_0096017c)(puVar7);
    }
    (*DAT_0096017c)(puVar6);
  }
  return param_1;
}

// FUN_00496AD0 NONMATCHING

void FUN_00496ad0(u64 param_1,int *param_2,short param_3,short param_4,int param_5,
                 int param_6)

{
  int iVar1;
  short *psVar2;
  int *piVar3;
  
  psVar2 = (short *)*param_2;
  while( 1 ) {
    if (psVar2 == (short *)0x0) {
      psVar2 = (short *)(*DAT_00960188)(param_1,0x30502);
      *psVar2 = param_3;
      psVar2[1] = param_4;
      *(u32 *)(psVar2 + 2) = *(u32 *)(param_6 + param_5 * 4);
      psVar2[4] = 0;
      psVar2[5] = 0;
      *(int *)(psVar2 + 6) = *param_2;
      *param_2 = (int)psVar2;
      return;
    }
    if (((param_3 == psVar2[1]) && (param_4 == *psVar2)) && (*(int *)(psVar2 + 4) == 0)) break;
    psVar2 = *(short **)(psVar2 + 6);
  }
  piVar3 = (int *)(param_6 + param_5 * 4);
  *(char *)(*(int *)(psVar2 + 2) + 0x20) = *(char *)(*(int *)(psVar2 + 2) + 0x20) + '\x01';
  iVar1 = *piVar3;
  *(char *)(iVar1 + 0x20) = *(char *)(iVar1 + 0x20) + '\x01';
  *(int *)(psVar2 + 4) = *piVar3;
  return;
}

// FUN_00496BE0 NONMATCHING

u64 FUN_00496be0(u32 param_1,u32 *param_2,int param_3,u32 *param_4)

{
  int iVar1;
  u32 *puVar2;
  u32 uVar3;
  
  while (param_3 != 0) {
    iVar1 = *(int *)(param_3 + 0xc);
    (*DAT_0096018c)(param_2[1],param_3);
    param_3 = iVar1;
  }
  ((code)FUN_004c3c30)(param_2[1]);
  param_2[1] = 0;
  uVar3 = 0;
  puVar2 = param_4;
  if (param_1 != 0) {
    do {
      (*DAT_0096018c)(*param_2,*puVar2);
      uVar3 = uVar3 + 1;
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    } while (uVar3 < param_1);
  }
  ((code)FUN_004c3c30)(*param_2);
  *param_2 = 0;
  (*DAT_0096017c)(param_4);
  return 0;
}

// FUN_00496CD0 NONMATCHING

int * FUN_00496cd0(u32 param_1,u32 *param_2,u64 param_3,u16 *param_4)

{
  int *piVar1;
  u32 uVar2;
  int iVar3;
  int *piVar4;
  u32 uVar5;
  
  piVar1 = (int *)(*DAT_00960178)(param_1 << 2,0x30502);
  uVar2 = ((code)FUN_004c3b50)(0x24,param_1,4,0x30502);
  *param_2 = uVar2;
  uVar2 = ((code)FUN_004c3b50)(0x10,(param_1 >> 1) + 1,4,0x30502);
  param_2[1] = uVar2;
  uVar5 = 0;
  piVar4 = piVar1;
  if (param_1 != 0) {
    do {
      iVar3 = (*DAT_00960188)(*param_2,0x30502);
      *piVar4 = iVar3;
      *(u8 *)(*piVar4 + 0x20) = 0;
      *(u32 *)*piVar4 = uVar5;
      *(u32 *)(*piVar4 + 0x14) = 0;
      *(u32 *)(*piVar4 + 0x10) = 0;
      *(u32 *)(*piVar4 + 0x18) = 0;
      uVar2 = ((code)FUN_00496ad0)(param_2[1],param_3,*param_4,param_4[1],uVar5,piVar1);
      *(u32 *)(*piVar4 + 4) = uVar2;
      uVar2 = ((code)FUN_00496ad0)(param_2[1],param_3,param_4[1],param_4[2],uVar5,piVar1);
      *(u32 *)(*piVar4 + 8) = uVar2;
      uVar2 = ((code)FUN_00496ad0)(param_2[1],param_3,param_4[2],*param_4,uVar5,piVar1);
      uVar5 = uVar5 + 1;
      param_4 = param_4 + 10;
      *(u32 *)(*piVar4 + 0xc) = uVar2;
      piVar4 = piVar4 + 1;
    } while (uVar5 < param_1);
  }
  return piVar1;
}

// FUN_00496E80 NONMATCHING

short * FUN_00496e80(int param_1,short param_2,short param_3)

{
  short *psVar1;
  
  psVar1 = *(short **)(param_1 + 4);
  if (((*psVar1 != param_2) || (psVar1[1] != param_3)) &&
     ((*psVar1 != param_3 || (psVar1[1] != param_2)))) {
    psVar1 = *(short **)(param_1 + 8);
    if (((*psVar1 != param_2) || (psVar1[1] != param_3)) &&
       ((*psVar1 != param_3 || (psVar1[1] != param_2)))) {
      psVar1 = *(short **)(param_1 + 0xc);
      if (((*psVar1 != param_2) || (psVar1[1] != param_3)) &&
         ((*psVar1 != param_3 || (psVar1[1] != param_2)))) {
        psVar1 = (short *)0x0;
      }
    }
  }
  return psVar1;
}

// FUN_00496F60 NONMATCHING

void FUN_00496f60(int param_1,int param_2,long param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  u32 uVar4;
  
  if (param_3 < 4) {
    *(u32 *)(param_1 + 0x1c) = 1;
  }
  else {
    *(u32 *)(param_1 + 0x18) = 1;
    piVar3 = (int *)(param_2 + (u32)*(u8 *)(param_1 + 0x20) * 4);
    iVar1 = *piVar3;
    if (iVar1 == param_1) {
      *piVar3 = *(int *)(iVar1 + 0x10);
      iVar1 = *(int *)(param_2 + (u32)*(u8 *)(param_1 + 0x20) * 4);
      if (iVar1 != 0) {
        *(u32 *)(iVar1 + 0x14) = 0;
      }
    }
    else {
      if (*(int *)(param_1 + 0x10) != 0) {
        *(u32 *)(*(int *)(param_1 + 0x10) + 0x14) = *(u32 *)(param_1 + 0x14);
      }
      if (*(int *)(param_1 + 0x14) != 0) {
        *(u32 *)(*(int *)(param_1 + 0x14) + 0x10) = *(u32 *)(param_1 + 0x10);
      }
    }
    uVar4 = 0;
    do {
      iVar1 = *(int *)(param_1 + uVar4 * 4 + 4);
      iVar2 = *(int *)(iVar1 + 4);
      if ((((iVar2 == 0) || (iVar2 == param_1)) || (*(int *)(iVar2 + 0x18) != 0)) &&
         ((iVar1 = *(int *)(iVar1 + 8), iVar2 = 0, iVar1 != 0 && (*(int *)(iVar1 + 0x18) == 0)))) {
        iVar2 = iVar1;
      }
      if (iVar2 != 0) {
        piVar3 = (int *)(param_2 + (u32)*(u8 *)(iVar2 + 0x20) * 4);
        iVar1 = *piVar3;
        if (iVar1 == iVar2) {
          *piVar3 = *(int *)(iVar1 + 0x10);
          iVar1 = *(int *)(param_2 + (u32)*(u8 *)(iVar2 + 0x20) * 4);
          if (iVar1 != 0) {
            *(u32 *)(iVar1 + 0x14) = 0;
          }
        }
        else {
          if (*(int *)(iVar2 + 0x10) != 0) {
            *(u32 *)(*(int *)(iVar2 + 0x10) + 0x14) = *(u32 *)(iVar2 + 0x14);
          }
          if (*(int *)(iVar2 + 0x14) != 0) {
            *(u32 *)(*(int *)(iVar2 + 0x14) + 0x10) = *(u32 *)(iVar2 + 0x10);
          }
        }
        *(char *)(iVar2 + 0x20) = *(char *)(iVar2 + 0x20) + -1;
        *(u32 *)(iVar2 + 0x10) = *(u32 *)(param_2 + (u32)*(u8 *)(iVar2 + 0x20) * 4)
        ;
        if (*(int *)(iVar2 + 0x10) != 0) {
          *(int *)(*(int *)(iVar2 + 0x10) + 0x14) = iVar2;
        }
        *(int *)(param_2 + (u32)*(u8 *)(iVar2 + 0x20) * 4) = iVar2;
        *(u32 *)(iVar2 + 0x14) = 0;
      }
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 3);
  }
  return;
}

// FUN_00497130 NONMATCHING

long FUN_00497130(u64 param_1,long param_2,u64 param_3,u64 param_4,long param_5
                 )

{
  u16 uVar1;
  u32 uVar2;
  int iVar3;
  u8 bVar4;
  long lVar5;
  long lVar6;
  u16 *puVar7;
  u8 bVar8;
  u16 extraout_t1_lo;
  int extraout_t2_lo;
  int iVar9;
  long extraout_t2;
  int iVar10;
  int extraout_t3_lo;
  long extraout_t3;
  long lVar11;
  long lVar12;
  int *piVar13;
  
  lVar12 = 0;
  lVar11 = 0;
  while( 1 ) {
    if (param_2 == 0) {
      return lVar12;
    }
    iVar10 = 0;
    iVar3 = (int)param_2;
    if (param_5 < 4) {
      iVar9 = *(int *)(iVar3 + 4);
      if (((iVar9 == 0) || (*(int *)(iVar9 + 0x1c) != 0)) &&
         ((iVar3 = *(int *)(iVar3 + 8), iVar9 = iVar10, iVar3 != 0 && (*(int *)(iVar3 + 0x1c) == 0))
         )) {
        iVar9 = iVar3;
      }
    }
    else {
      iVar9 = *(int *)(iVar3 + 4);
      if ((((iVar9 == 0) || (*(int *)(iVar9 + 0x18) != 0)) &&
          (iVar3 = *(int *)(iVar3 + 8), iVar9 = iVar10, iVar3 != 0)) &&
         (*(int *)(iVar3 + 0x18) == 0)) {
        iVar9 = iVar3;
      }
    }
    if (iVar9 == 0) break;
    lVar12 = (long)((int)lVar12 + 1);
    iVar3 = ((code)FUN_00496f60)(iVar9,param_3,param_5);
    iVar10 = (int)extraout_t3;
    if (iVar3 == *(int *)(iVar10 + 4)) {
      iVar9 = 0;
    }
    else if (iVar3 == *(int *)(iVar10 + 8)) {
      iVar9 = 1;
    }
    else {
      iVar9 = extraout_t2_lo;
      if (iVar3 == *(int *)(iVar10 + 0xc)) {
        iVar9 = 2;
      }
    }
    puVar7 = *(u16 **)(iVar10 + ((iVar9 + 1) % 3) * 4 + 4);
    if (*(int *)(puVar7 + 2) == extraout_t3) {
      uVar1 = puVar7[1];
    }
    else {
      uVar1 = *puVar7;
    }
    param_2 = ((code)FUN_00496e80)(extraout_t3,
                           *(u16 *)(*(int *)param_1 + ((int *)param_1)[1] * 2 + -2),uVar1);
    iVar3 = (int)param_2;
    if (param_5 < 4) {
      bVar4 = 1;
      bVar8 = bVar4;
      if (param_2 != 0) {
        iVar10 = 0;
        if ((*(int *)(iVar3 + 8) != 0) && (*(int *)(*(int *)(iVar3 + 8) + 0x1c) == 0)) {
          iVar10 = 1;
        }
        iVar9 = 0;
        if ((*(int *)(iVar3 + 4) != 0) && (*(int *)(*(int *)(iVar3 + 4) + 0x1c) == 0)) {
          iVar9 = 1;
        }
        if (iVar9 + iVar10 != 0) {
          bVar8 = 0;
        }
      }
      if (!bVar8) {
        bVar4 = 0;
      }
    }
    else {
      bVar4 = 1;
      bVar8 = bVar4;
      if (param_2 != 0) {
        iVar10 = 0;
        if ((*(int *)(iVar3 + 8) != 0) && (*(int *)(*(int *)(iVar3 + 8) + 0x18) == 0)) {
          iVar10 = 1;
        }
        iVar9 = 0;
        if ((*(int *)(iVar3 + 4) != 0) && (*(int *)(*(int *)(iVar3 + 4) + 0x18) == 0)) {
          iVar9 = 1;
        }
        if (iVar9 + iVar10 != 0) {
          bVar8 = 0;
        }
      }
      if (!bVar8) {
        bVar4 = 0;
      }
    }
    piVar13 = (int *)param_1;
    if (bVar4) {
      lVar5 = (long)*(int *)(extraout_t3_lo + 4);
      if ((((lVar5 == extraout_t2) || (lVar5 == param_2)) &&
          ((lVar5 = (long)*(int *)(extraout_t3_lo + 8), lVar5 == extraout_t2 || (lVar5 == param_2)))
          ) && ((lVar6 = (long)*(int *)(extraout_t3_lo + 0xc), lVar5 = lVar11, lVar6 != extraout_t2
                && (lVar6 != param_2)))) {
        lVar5 = lVar6;
      }
      iVar3 = (int)lVar5;
      if (param_5 < 4) {
        bVar8 = 0;
        bVar4 = 0;
        if (lVar5 != 0) {
          iVar10 = 0;
          if ((*(int *)(iVar3 + 8) != 0) && (*(int *)(*(int *)(iVar3 + 8) + 0x1c) == 0)) {
            iVar10 = 1;
          }
          iVar9 = 0;
          if ((*(int *)(iVar3 + 4) != 0) && (*(int *)(*(int *)(iVar3 + 4) + 0x1c) == 0)) {
            iVar9 = 1;
          }
          if (iVar9 + iVar10 != 0) {
            bVar4 = 1;
          }
        }
        if (bVar4) {
          bVar8 = 1;
        }
      }
      else {
        bVar8 = 0;
        bVar4 = 0;
        if (lVar5 != 0) {
          iVar10 = 0;
          if ((*(int *)(iVar3 + 8) != 0) && (*(int *)(*(int *)(iVar3 + 8) + 0x18) == 0)) {
            iVar10 = 1;
          }
          iVar9 = 0;
          if ((*(int *)(iVar3 + 4) != 0) && (*(int *)(*(int *)(iVar3 + 4) + 0x18) == 0)) {
            iVar9 = 1;
          }
          if (iVar9 + iVar10 != 0) {
            bVar4 = 1;
          }
        }
        if (bVar4) {
          bVar8 = 1;
        }
      }
      lVar11 = lVar5;
      if (bVar8) {
        uVar2 = piVar13[1];
        if ((uVar2 & 1) == 0) {
          puVar7 = (u16 *)(*piVar13 + uVar2 * 2);
          *puVar7 = puVar7[-2];
          piVar13[1] = piVar13[1] + 1;
          *(u16 *)(*piVar13 + piVar13[1] * 2) = extraout_t1_lo;
          piVar13[1] = piVar13[1] + 1;
          param_2 = lVar5;
        }
        else {
          *(u16 *)(*piVar13 + uVar2 * 2) = extraout_t1_lo;
          piVar13[1] = piVar13[1] + 1;
          param_2 = 0;
        }
      }
      else {
        param_2 = 0;
        *(u16 *)(*piVar13 + piVar13[1] * 2) = extraout_t1_lo;
        piVar13[1] = piVar13[1] + 1;
      }
    }
    else {
      *(u16 *)(*piVar13 + piVar13[1] * 2) = extraout_t1_lo;
      piVar13[1] = piVar13[1] + 1;
    }
  }
  return lVar12;
}

// FUN_00497600 NONMATCHING

u32 FUN_00497600(int param_1,u32 param_2,int *param_3,int param_4)

{
  u32 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  u32 uVar9;
  u32 uVar10;
  u32 *puVar11;
  u32 uVar12;
  u64 uVar13;
  u64 uVar14;
  u8 bVar15;
  int iVar16;
  u32 uVar17;
  int *piVar18;
  int iVar19;
  int iVar20;
  u16 *puVar21;
  u32 uVar22;
  u8 bVar23;
  u8 bVar24;
  int iVar25;
  u8 bVar26;
  int iVar27;
  int iVar28;
  u32 uVar29;
  u32 uVar30;
  long lVar31;
  u32 uStack_64;
  int iStack_60;
  u32 uStack_50;
  int *piStack_20;
  int aiStack_1c [6];
  u32 uStack_4;
  
  uStack_4 = 0;
  piStack_20 = (int *)0x0;
  aiStack_1c[0] = 0;
  aiStack_1c[1] = 0;
  aiStack_1c[2] = 0;
  aiStack_1c[3] = 0;
  aiStack_1c[4] = 0;
  uStack_50 = 0;
  iStack_60 = 0;
  piVar4 = (int *)((code)FUN_00496cd0)(param_2,aiStack_1c + 3,&uStack_4,param_1);
  uVar22 = 0;
  piVar5 = piVar4;
  if (param_2 != 0) {
    do {
      *(int **)(*piVar5 + 0x10) = (&piStack_20)[*(u8 *)(*piVar5 + 0x20)];
      iVar6 = *(int *)(*piVar5 + 0x10);
      if (iVar6 != 0) {
        *(int *)(iVar6 + 0x14) = *piVar5;
      }
      uVar22 = uVar22 + 1;
      (&piStack_20)[*(u8 *)((int *)*piVar5 + 8)] = (int *)*piVar5;
      *(u32 *)(*piVar5 + 0x14) = 0;
      piVar5 = piVar5 + 1;
    } while (uVar22 < param_2);
  }
  uVar13 = (*DAT_00960188)(*(u32 *)((int)(u8 *)DAT_00960074 + DAT_007ce850),0x10502);
  iVar28 = param_2 * 2 + 2;
  piVar5 = (int *)uVar13;
  piVar5[2] = iVar28;
  piVar5[1] = 0;
  iVar6 = (*DAT_00960178)(piVar5[2] << 2,0x10502);
  *piVar5 = iVar6;
  uVar14 = (*DAT_00960188)(*(u32 *)((int)(u8 *)DAT_00960074 + DAT_007ce850),0x10502);
  piVar7 = (int *)uVar14;
  piVar7[2] = iVar28;
  piVar7[1] = 0;
  iVar6 = (*DAT_00960178)(piVar7[2] << 2,0x10502);
  *piVar7 = iVar6;
  uVar22 = 0;
  if (param_2 == 0) {
LAB_004978a8:
    (*DAT_0096017c)(*piVar7);
    *piVar7 = 0;
    (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + DAT_007ce850),uVar14);
    (*DAT_0096017c)(*piVar5);
    *piVar5 = 0;
    (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + DAT_007ce850),uVar13);
    ((code)FUN_00496be0)(param_2,aiStack_1c + 3,uStack_4,piVar4);
    return 1;
  }
LAB_004977ac:
  uStack_64 = 0;
  if (param_4 == 0) {
    iVar6 = 3;
  }
  else {
    iVar6 = 0;
  }
  if (piStack_20 == (int *)0x0) {
    piVar8 = aiStack_1c;
    iVar16 = 1;
    iVar28 = aiStack_1c[0];
    while (iVar28 == 0) {
      piVar8 = piVar8 + 1;
      iVar16 = iVar16 + 1;
      iVar28 = *piVar8;
    }
    lVar31 = (long)(int)(&piStack_20 + iVar16);
    piVar8 = (&piStack_20)[iVar16];
    iVar28 = *(int *)(piVar8[3] + 8);
    iVar16 = 0;
    if ((iVar28 != 0) && (*(int *)(iVar28 + 0x18) == 0)) {
      iVar16 = 1;
    }
    iVar2 = *(int *)(piVar8[3] + 4);
    iVar19 = 0;
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x18) == 0)) {
      iVar19 = 1;
    }
    if (1 < (u32)(iVar19 + iVar16)) {
      iVar16 = *(int *)(piVar8[2] + 8);
      iVar19 = 0;
      if ((iVar16 != 0) && (*(int *)(iVar16 + 0x18) == 0)) {
        iVar19 = 1;
      }
      iVar16 = *(int *)(piVar8[2] + 4);
      iVar20 = 0;
      if ((iVar16 != 0) && (*(int *)(iVar16 + 0x18) == 0)) {
        iVar20 = 1;
      }
      if (1 < (u32)(iVar20 + iVar19)) {
        uVar30 = 1;
        goto LAB_00497cc4;
      }
    }
    iVar16 = *(int *)(piVar8[1] + 8);
    iVar19 = 0;
    if ((iVar16 != 0) && (*(int *)(iVar16 + 0x18) == 0)) {
      iVar19 = 1;
    }
    iVar20 = *(int *)(piVar8[1] + 4);
    iVar25 = 0;
    if ((iVar20 != 0) && (*(int *)(iVar20 + 0x18) == 0)) {
      iVar25 = 1;
    }
    if (1 < (u32)(iVar25 + iVar19)) {
      bVar23 = 0;
      if (iVar2 != 0) {
        bVar23 = *(int *)(iVar2 + 0x18) == 0;
      }
      bVar15 = 0;
      if (iVar28 != 0) {
        bVar15 = *(int *)(iVar28 + 0x18) == 0;
      }
      if (1 < (u8)(bVar23 + bVar15)) {
        uVar30 = 2;
        goto LAB_00497cc4;
      }
    }
    iVar19 = *(int *)(piVar8[2] + 8);
    iVar25 = 0;
    if ((iVar19 != 0) && (*(int *)(iVar19 + 0x18) == 0)) {
      iVar25 = 1;
    }
    iVar3 = *(int *)(piVar8[2] + 4);
    iVar27 = 0;
    if ((iVar3 != 0) && (*(int *)(iVar3 + 0x18) == 0)) {
      iVar27 = 1;
    }
    if (1 < (u32)(iVar27 + iVar25)) {
      bVar23 = 0;
      if (iVar20 != 0) {
        bVar23 = *(int *)(iVar20 + 0x18) == 0;
      }
      bVar15 = 0;
      if (iVar16 != 0) {
        bVar15 = *(int *)(iVar16 + 0x18) == 0;
      }
      if (1 < (u8)(bVar23 + bVar15)) {
        uVar30 = 0;
        goto LAB_00497cc4;
      }
    }
    bVar23 = 0;
    if (iVar20 != 0) {
      bVar23 = *(int *)(iVar20 + 0x18) == 0;
    }
    bVar15 = 0;
    if (iVar16 != 0) {
      bVar15 = *(int *)(iVar16 + 0x18) == 0;
    }
    bVar26 = 0;
    if (iVar3 != 0) {
      bVar26 = *(int *)(iVar3 + 0x18) == 0;
    }
    bVar24 = 0;
    if (iVar19 != 0) {
      bVar24 = *(int *)(iVar19 + 0x18) == 0;
    }
    if ((u8)(bVar26 + bVar24) < (u8)(bVar23 + bVar15)) {
      bVar23 = 0;
      if (iVar20 != 0) {
        bVar23 = *(int *)(iVar20 + 0x18) == 0;
      }
      bVar15 = 0;
      if (iVar16 != 0) {
        bVar15 = *(int *)(iVar16 + 0x18) == 0;
      }
      bVar26 = 0;
      if (iVar2 != 0) {
        bVar26 = *(int *)(iVar2 + 0x18) == 0;
      }
      bVar24 = 0;
      if (iVar28 != 0) {
        bVar24 = *(int *)(iVar28 + 0x18) == 0;
      }
      if ((u8)(bVar26 + bVar24) < (u8)(bVar23 + bVar15)) {
        uVar30 = 2;
      }
      else {
        uVar30 = 1;
      }
    }
    else {
      bVar23 = 0;
      if (iVar3 != 0) {
        bVar23 = *(int *)(iVar3 + 0x18) == 0;
      }
      bVar15 = 0;
      if (iVar19 != 0) {
        bVar15 = *(int *)(iVar19 + 0x18) == 0;
      }
      bVar26 = 0;
      if (iVar2 != 0) {
        bVar26 = *(int *)(iVar2 + 0x18) == 0;
      }
      bVar24 = 0;
      if (iVar28 != 0) {
        bVar24 = *(int *)(iVar28 + 0x18) == 0;
      }
      if ((u8)(bVar26 + bVar24) < (u8)(bVar23 + bVar15)) {
        uVar30 = 0;
      }
      else {
        uVar30 = 1;
      }
    }
LAB_00497cc4:
    uVar1 = uVar30 % 3;
    uVar9 = uVar30 + 1;
    uVar10 = uVar30 + 2;
LAB_00497cfc:
    do {
      uVar17 = 0;
      if (param_2 != 0) {
        piVar8 = piVar4;
        if (8 < param_2) {
          do {
            uVar17 = uVar17 + 8;
            *(u32 *)(*piVar8 + 0x1c) = *(u32 *)(*piVar8 + 0x18);
            *(u32 *)(piVar8[1] + 0x1c) = *(u32 *)(piVar8[1] + 0x18);
            *(u32 *)(piVar8[2] + 0x1c) = *(u32 *)(piVar8[2] + 0x18);
            *(u32 *)(piVar8[3] + 0x1c) = *(u32 *)(piVar8[3] + 0x18);
            *(u32 *)(piVar8[4] + 0x1c) = *(u32 *)(piVar8[4] + 0x18);
            *(u32 *)(piVar8[5] + 0x1c) = *(u32 *)(piVar8[5] + 0x18);
            *(u32 *)(piVar8[6] + 0x1c) = *(u32 *)(piVar8[6] + 0x18);
            *(u32 *)(piVar8[7] + 0x1c) = *(u32 *)(piVar8[7] + 0x18);
            piVar8 = piVar8 + 8;
          } while (uVar17 < param_2 - 8);
        }
        if (uVar17 < param_2) {
          piVar8 = piVar4 + uVar17;
          do {
            iVar28 = *piVar8;
            uVar17 = uVar17 + 1;
            piVar8 = piVar8 + 1;
            *(u32 *)(iVar28 + 0x1c) = *(u32 *)(iVar28 + 0x18);
          } while (uVar17 < param_2);
        }
      }
      iVar28 = iVar6 + 1;
      uVar17 = uVar10 % 3;
      if (((iVar6 != 2) && (uVar17 = uVar9 % 3, iVar6 != 1)) && (uVar17 = uVar1, iVar6 != 0)) {
        uVar17 = uVar30;
      }
      piVar8 = (int *)lVar31;
      if (uVar17 == 2) {
        uStack_50 = *(u32 *)(*piVar8 + 4);
        iStack_60 = *(int *)(*piVar8 + 0xc);
LAB_00497e48:
        piVar18 = (int *)*piVar8;
      }
      else {
        if (uVar17 == 1) {
          uStack_50 = *(u32 *)(*piVar8 + 0xc);
          iStack_60 = *(int *)(*piVar8 + 8);
          goto LAB_00497e48;
        }
        if (uVar17 == 0) {
          uStack_50 = *(u32 *)(*piVar8 + 8);
          iStack_60 = *(int *)(*piVar8 + 4);
          goto LAB_00497e48;
        }
        piVar18 = (int *)*piVar8;
      }
      iVar6 = param_1 + *piVar18 * 0x14;
      *(u16 *)*piVar5 = *(u16 *)(iVar6 + (uVar17 % 3) * 2);
      *(u16 *)(*piVar5 + 2) = *(u16 *)(iVar6 + ((uVar17 + 1) % 3) * 2);
      *(u16 *)(*piVar5 + 4) = *(u16 *)(iVar6 + ((uVar17 + 2) % 3) * 2);
      piVar5[1] = 3;
      ((code)FUN_00496f60)(*piVar8,&piStack_20,iVar28);
      iVar6 = ((code)FUN_00497130)(uVar13,uStack_50,&piStack_20,param_1,iVar28);
      uVar29 = uVar22 + 1 + iVar6;
      if (iVar28 < 4) {
        iVar6 = 0;
        if ((*(int *)(iStack_60 + 8) != 0) && (*(int *)(*(int *)(iStack_60 + 8) + 0x1c) == 0)) {
          iVar6 = 1;
        }
        iVar16 = 0;
        if ((*(int *)(iStack_60 + 4) != 0) && (*(int *)(*(int *)(iStack_60 + 4) + 0x1c) == 0)) {
          iVar16 = 1;
        }
        iVar16 = iVar16 + iVar6;
      }
      else {
        iVar6 = 0;
        if ((*(int *)(iStack_60 + 8) != 0) && (*(int *)(*(int *)(iStack_60 + 8) + 0x18) == 0)) {
          iVar6 = 1;
        }
        iVar16 = 0;
        if ((*(int *)(iStack_60 + 4) != 0) && (*(int *)(*(int *)(iStack_60 + 4) + 0x18) == 0)) {
          iVar16 = 1;
        }
        iVar16 = iVar16 + iVar6;
      }
      iVar6 = iVar28;
      if (iVar16 == 0) goto code_r0x00497fc0;
      *(u16 *)*piVar7 = *(u16 *)(*piVar5 + 2);
      *(u16 *)(*piVar7 + 2) = *(u16 *)*piVar5;
      piVar7[1] = 2;
      iVar16 = ((code)FUN_00497130)(uVar14,iStack_60,&piStack_20,param_1,iVar28);
      uVar29 = uVar29 + iVar16;
      if ((piVar7[1] & 1U) != 0) {
        puVar21 = (u16 *)(piVar7[1] * 2 + *piVar7);
        *puVar21 = puVar21[-2];
        piVar7[1] = piVar7[1] + 1;
      }
      if (uStack_64 < uVar29) {
        uVar30 = uVar17;
        uStack_64 = uVar29;
      }
    } while (iVar28 < 4);
    piVar8 = (int *)(*DAT_00960188)(*(u32 *)((int)(u8 *)DAT_00960074 + DAT_007ce850),0x30502);
    piVar8[3] = *param_3;
    *param_3 = (int)piVar8;
    piVar8[2] = piVar5[1] + piVar7[1] + -2;
    piVar8[1] = 0;
    iVar6 = (*DAT_00960178)(piVar8[2] << 2,0x30502);
    *piVar8 = iVar6;
    uVar22 = piVar7[1];
    if (uVar22 < 3) {
      iVar6 = piVar8[1];
    }
    else {
      do {
        *(u16 *)(*piVar8 + piVar8[1] * 2) = *(u16 *)(uVar22 * 2 + *piVar7 + -2);
        piVar8[1] = piVar8[1] + 1;
        piVar7[1] = piVar7[1] + -1;
        uVar22 = piVar7[1];
      } while (2 < uVar22);
      iVar6 = piVar8[1];
    }
    ((code)FUN_00521250)(*piVar8 + iVar6 * 2,*piVar5,piVar5[1] << 2);
    piVar8[1] = piVar8[2];
    goto LAB_004978a0;
  }
  iVar6 = *piStack_20;
  piVar8 = (int *)(*DAT_00960188)(*(u32 *)((int)(u8 *)DAT_00960074 + DAT_007ce850),0x30502);
  piVar8[3] = *param_3;
  *param_3 = (int)piVar8;
  piVar8[2] = 3;
  piVar8[1] = 3;
  iVar28 = (*DAT_00960178)(0xc,0x30502);
  *piVar8 = iVar28;
  puVar21 = (u16 *)(param_1 + iVar6 * 0x14);
  *(u16 *)*piVar8 = *puVar21;
  *(u16 *)(*piVar8 + 2) = puVar21[1];
  *(u16 *)(*piVar8 + 4) = puVar21[2];
  piStack_20[6] = 1;
  piStack_20[7] = 1;
  piStack_20 = (int *)piStack_20[4];
  if (piStack_20 != (int *)0x0) {
    piStack_20[5] = 0;
  }
  uVar29 = uVar22 + 1;
  goto LAB_004978a0;
code_r0x00497fc0:
  if (uStack_64 < uVar29) {
    uVar30 = uVar17;
    uStack_64 = uVar29;
  }
  if (3 < iVar28) goto code_r0x00497fe4;
  goto LAB_00497cfc;
code_r0x00497fe4:
  puVar11 = (u32 *)
            (*DAT_00960188)(*(u32 *)((int)(u8 *)DAT_00960074 + DAT_007ce850),0x30502);
  puVar11[3] = *param_3;
  *param_3 = (int)puVar11;
  puVar11[2] = piVar5[1];
  puVar11[1] = piVar5[1];
  uVar12 = (*DAT_00960178)(piVar5[1] << 2,0x30502);
  *puVar11 = uVar12;
  ((code)FUN_00521250)(*puVar11,*piVar5,piVar5[1] << 2);
LAB_004978a0:
  uVar22 = uVar29;
  if (param_2 <= uVar29) goto LAB_004978a8;
  goto LAB_004977ac;
}

// FUN_004982B0 NONMATCHING

u32 FUN_004982b0(int *param_1,long param_2)

{
  short sVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  u32 uVar5;
  u16 *puVar6;
  int *piVar7;
  short *psVar8;
  u32 uVar9;
  int *piVar10;
  
  if (*param_1 == 0) {
    uVar5 = 0;
  }
  else {
    piVar3 = (int *)(*DAT_00960188)(*(u32 *)((int)(u8 *)DAT_00960074 + DAT_007ce850),0x30502);
    piVar3[1] = 0;
    piVar3[2] = 0;
    for (iVar4 = *param_1; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0xc)) {
      piVar3[2] = piVar3[2] + *(int *)(iVar4 + 4) + 6;
    }
    iVar4 = (*DAT_00960178)(piVar3[2] << 2,0x30502);
    *piVar3 = iVar4;
    piVar10 = (int *)*param_1;
    uVar9 = 0;
    if (piVar10[1] != 0) {
      iVar4 = 0;
      do {
        uVar9 = uVar9 + 1;
        *(u16 *)(*piVar3 + piVar3[1] * 2) = *(u16 *)(*piVar10 + iVar4);
        piVar3[1] = piVar3[1] + 1;
        iVar4 = iVar4 + 2;
      } while (uVar9 < (u32)piVar10[1]);
    }
    (*DAT_0096017c)(*piVar10);
    *piVar10 = 0;
    piVar2 = (int *)piVar10[3];
    (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + DAT_007ce850),piVar10);
    while (piVar2 != (int *)0x0) {
      piVar10 = piVar2;
      if (piVar2 != (int *)0x0) {
        psVar8 = (short *)(*piVar3 + piVar3[1] * 2);
        do {
          if (*(short *)*piVar10 == psVar8[-1]) {
            if (((piVar3[1] & 1U) != 0) && (param_2 != 0)) {
              *psVar8 = *(short *)*piVar10;
              piVar3[1] = piVar3[1] + 1;
            }
            break;
          }
          piVar10 = (int *)piVar10[3];
        } while (piVar10 != (int *)0x0);
      }
      if ((piVar10 == (int *)0x0) && (piVar10 = piVar2, piVar2 != (int *)0x0)) {
        psVar8 = (short *)(*piVar3 + piVar3[1] * 2);
        do {
          sVar1 = *(short *)*piVar10;
          if (sVar1 == psVar8[-2]) {
            if (((piVar3[1] & 1U) == 0) && (param_2 != 0)) {
              *psVar8 = sVar1;
              *(u16 *)(*piVar3 + piVar3[1] * 2 + 2) = *(u16 *)*piVar10;
              piVar3[1] = piVar3[1] + 2;
            }
            else {
              *psVar8 = sVar1;
              piVar3[1] = piVar3[1] + 1;
            }
            break;
          }
          piVar10 = (int *)piVar10[3];
        } while (piVar10 != (int *)0x0);
      }
      if (piVar10 == (int *)0x0) {
        uVar9 = piVar3[1];
        if (((uVar9 & 1) == 0) || (param_2 == 0)) {
          puVar6 = (u16 *)(*piVar3 + uVar9 * 2);
          *puVar6 = puVar6[-1];
          *(u16 *)(*piVar3 + piVar3[1] * 2 + 2) = *(u16 *)*piVar2;
          piVar3[1] = piVar3[1] + 2;
          piVar10 = piVar2;
        }
        else {
          puVar6 = (u16 *)(*piVar3 + uVar9 * 2);
          *puVar6 = puVar6[-1];
          *(u16 *)(*piVar3 + piVar3[1] * 2 + 2) = *(u16 *)*piVar2;
          *(u16 *)(*piVar3 + piVar3[1] * 2 + 4) = *(u16 *)*piVar2;
          piVar3[1] = piVar3[1] + 3;
          piVar10 = piVar2;
        }
      }
      uVar9 = 0;
      if (piVar10[1] != 0) {
        iVar4 = 0;
        do {
          uVar9 = uVar9 + 1;
          *(u16 *)(*piVar3 + piVar3[1] * 2) = *(u16 *)(*piVar10 + iVar4);
          piVar3[1] = piVar3[1] + 1;
          iVar4 = iVar4 + 2;
        } while (uVar9 < (u32)piVar10[1]);
      }
      (*DAT_0096017c)(*piVar10);
      *piVar10 = 0;
      if (piVar2 == piVar10) {
        piVar2 = (int *)piVar2[3];
        (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + DAT_007ce850),piVar10);
      }
      else {
        piVar7 = piVar2;
        if ((int *)piVar2[3] == piVar10) {
          iVar4 = piVar10[3];
        }
        else {
          do {
            piVar7 = (int *)piVar7[3];
          } while ((int *)piVar7[3] != piVar10);
          iVar4 = piVar10[3];
        }
        piVar7[3] = iVar4;
        (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + DAT_007ce850),piVar10);
      }
    }
    *param_1 = (int)piVar3;
    piVar3[3] = 0;
    uVar5 = 1;
  }
  return uVar5;
}

// FUN_00498720 NONMATCHING

u64 FUN_00498720(int param_1,u64 param_2,u32 param_3)

{
  int iVar1;
  u32 *puVar2;
  int *piVar3;
  int *piVar4;
  u32 *puVar5;
  u32 uVar6;
  u32 *puVar7;
  int *piVar8;
  u32 *puVar9;
  u64 uVar10;
  int iVar11;
  u32 uVar12;
  u32 uVar13;
  u32 uVar14;
  int *piVar15;
  u32 *puVar16;
  int iVar17;
  u32 uVar18;
  u32 uVar19;
  u32 uVar20;
  u32 uStack_40;
  int *piStack_20;
  int *piStack_4;
  
  uVar18 = 0;
  piVar3 = (int *)(*DAT_00960178)(*(int *)(param_1 + 4) << 2,0x10502);
  if (piVar3 == (int *)0x0) {
    uVar10 = 0;
  }
  else {
    uVar14 = 0;
    if (*(int *)(param_1 + 4) == 0) {
      uVar12 = 0;
    }
    else {
      iVar11 = 0;
      piVar4 = piVar3;
      do {
        uVar14 = uVar14 + 1;
        *piVar4 = *(int *)(param_1 + 8) + iVar11;
        iVar11 = iVar11 + 0x14;
        uVar12 = *(u32 *)(param_1 + 4);
        piVar4 = piVar4 + 1;
      } while (uVar14 < uVar12);
    }
    ((code)FUN_005225f8)(piVar3,uVar12,4,0x4965a0);
    uVar14 = *(u32 *)(param_1 + 4);
    iVar11 = 1;
    if (1 < uVar14) {
      iVar17 = *(int *)(*piVar3 + 8);
      uVar12 = 1;
      piVar4 = piVar3;
      if (1 < uVar14) {
        do {
          iVar1 = *(int *)(piVar4[1] + 8);
          if (iVar1 != iVar17) {
            iVar11 = iVar11 + 1;
            iVar17 = iVar1;
          }
          uVar12 = uVar12 + 1;
          piVar4 = piVar4 + 1;
        } while (uVar12 < uVar14);
      }
    }
    piVar4 = (int *)(*DAT_00960178)(iVar11 << 2,0x1010502);
    puVar5 = (u32 *)(*DAT_00960178)(iVar11 * 0xc,0x10502);
    puVar5[2] = *(u32 *)(*piVar3 + 8);
    puVar5[1] = 0;
    *puVar5 = 0;
    uVar14 = *(u32 *)(param_1 + 4);
    uVar12 = 1;
    if ((1 < uVar14) && (uVar13 = 0, uVar14 != 1)) {
      puVar9 = puVar5 + 3;
      piVar15 = piVar3;
      do {
        if (*(int *)(*piVar15 + 8) != *(int *)(piVar15[1] + 8)) {
          puVar9[2] = *(int *)(piVar15[1] + 8);
          uVar12 = uVar12 + 1;
          puVar9[1] = uVar13 + 1;
          *puVar9 = 0;
          puVar9[-2] = (uVar13 + 1) - puVar9[-2];
          puVar9 = puVar9 + 3;
        }
        uVar14 = *(u32 *)(param_1 + 4);
        uVar13 = uVar13 + 1;
        piVar15 = piVar15 + 1;
      } while (uVar13 < uVar14 - 1);
    }
    puVar5[uVar12 * 3 + -2] = uVar14 - puVar5[uVar12 * 3 + -2];
    uVar6 = ((code)FUN_004c3b50)(0x10,*(u32 *)(param_1 + 4) / 10 + 5,4,0x10502);
    piStack_4 = (int *)0x0;
    uStack_40 = 0;
    *(u32 *)((int)(u8 *)DAT_00960074 + DAT_007ce850) = uVar6;
    puVar9 = puVar5;
    piStack_20 = piVar3;
    if (uVar12 != 0) {
      do {
        puVar7 = (u32 *)(*DAT_00960178)(puVar9[1] * 0x14,0x10502);
        uVar13 = 0;
        uVar14 = 0;
        puVar16 = puVar7;
        if (puVar9[1] != 0) {
          do {
            uVar13 = uVar13 + 1;
            puVar2 = (u32 *)*piStack_20;
            piStack_20 = piStack_20 + 1;
            uVar20 = puVar2[1];
            uVar6 = puVar2[2];
            uVar19 = puVar2[3];
            *puVar16 = *puVar2;
            puVar16[1] = uVar20;
            puVar16[2] = uVar6;
            puVar16[3] = uVar19;
            puVar16[4] = puVar2[4];
            uVar14 = puVar9[1];
            puVar16 = puVar16 + 5;
          } while (uVar13 < uVar14);
        }
        ((code)FUN_00497600)(puVar7,uVar14,&piStack_4,param_2);
        ((code)FUN_004982b0)(&piStack_4,param_3);
        for (piVar15 = piStack_4; piVar15 != (int *)0x0; piVar15 = (int *)piVar15[3]) {
          piVar8 = (int *)(*DAT_00960178)(piVar15[1] * 2 + 0xc,0x10502);
          piVar8[2] = puVar9[2];
          piVar8[1] = piVar15[1];
          *piVar8 = (int)(piVar8 + 3);
          uVar14 = 0;
          if (piVar8[1] != 0) {
            iVar11 = 0;
            do {
              uVar14 = uVar14 + 1;
              *(u16 *)(*piVar8 + iVar11) = *(u16 *)(*piVar15 + iVar11);
              iVar11 = iVar11 + 2;
            } while (uVar14 < (u32)piVar8[1]);
          }
          piVar4[uVar18] = (int)piVar8;
          uVar18 = uVar18 + 1 & 0xffff;
        }
        while (piVar15 = piStack_4, piStack_4 != (int *)0x0) {
          iVar11 = *piStack_4;
          piStack_4 = (int *)piStack_4[3];
          (*DAT_0096017c)(iVar11);
          *piVar15 = 0;
          (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + DAT_007ce850),piVar15);
        }
        (*DAT_0096017c)(puVar7);
        uStack_40 = uStack_40 + 1;
        puVar9 = puVar9 + 3;
      } while (uStack_40 < uVar12);
    }
    ((code)FUN_004c3c30)(*(u32 *)((int)(u8 *)DAT_00960074 + DAT_007ce850));
    iVar11 = 0x10;
    iVar17 = 0;
    uVar14 = 0;
    *(u32 *)((int)(u8 *)DAT_00960074 + DAT_007ce850) = 0;
    if (uVar18 != 0) {
      piVar15 = piVar4;
      if (8 < uVar18) {
        do {
          uVar14 = uVar14 + 8;
          iVar17 = iVar17 + *(int *)(*piVar15 + 4) + *(int *)(piVar15[1] + 4) +
                   *(int *)(piVar15[2] + 4) + *(int *)(piVar15[3] + 4) + *(int *)(piVar15[4] + 4) +
                   *(int *)(piVar15[5] + 4) + *(int *)(piVar15[6] + 4) + *(int *)(piVar15[7] + 4);
          iVar11 = iVar11 + *(int *)(*piVar15 + 4) * 2 + *(int *)(piVar15[1] + 4) * 2 +
                   *(int *)(piVar15[2] + 4) * 2 + *(int *)(piVar15[3] + 4) * 2 +
                   *(int *)(piVar15[4] + 4) * 2 + *(int *)(piVar15[5] + 4) * 2 +
                   *(int *)(piVar15[6] + 4) * 2 + *(int *)(piVar15[7] + 4) * 2 + 0x60;
          piVar15 = piVar15 + 8;
        } while (uVar14 < uVar18 - 8);
      }
      if (uVar14 < uVar18) {
        piVar15 = piVar4 + uVar14;
        do {
          iVar1 = *piVar15;
          uVar14 = uVar14 + 1;
          piVar15 = piVar15 + 1;
          iVar17 = iVar17 + *(int *)(iVar1 + 4);
          iVar11 = iVar11 + *(int *)(iVar1 + 4) * 2 + 0xc;
        } while (uVar14 < uVar18);
      }
    }
    uVar10 = ((code)FUN_004959c0)(iVar11);
    puVar9 = (u32 *)uVar10;
    *puVar9 = 1;
    *(short *)(puVar9 + 1) = (short)uVar18;
    puVar16 = puVar9 + 4;
    puVar7 = puVar16 + uVar18 * 3;
    uVar14 = 0;
    *(u16 *)((int)puVar9 + 6) = *(u16 *)((int)(u8 *)DAT_00960070 + DAT_007ce850);
    puVar9[3] = 0;
    puVar9[2] = iVar17;
    *(short *)((int)(u8 *)DAT_00960070 + DAT_007ce850) =
         *(short *)((int)(u8 *)DAT_00960070 + DAT_007ce850) + 1;
    piVar15 = piVar4;
    if (uVar18 != 0) {
      do {
        *puVar16 = (u32)(puVar7);
        puVar16[1] = *(u32 *)(*piVar15 + 4);
        puVar16[2] = *(u32 *)(*piVar15 + 8);
        ((code)FUN_00521250)(puVar7,*(u32 *)*piVar15,((u32 *)*piVar15)[1] << 1);
        piVar8 = (int *)(puVar16 + 1);
        puVar16 = puVar16 + 3;
        puVar7 = (u32 *)((int)puVar7 + *piVar8 * 2);
        (*DAT_0096017c)(*piVar15);
        uVar14 = uVar14 + 1;
        *piVar15 = 0;
        piVar15 = piVar15 + 1;
      } while (uVar14 < uVar18);
    }
    (*DAT_0096017c)(piVar3);
    (*DAT_0096017c)(piVar4);
    (*DAT_0096017c)(puVar5);
  }
  return uVar10;
}

#pragma tailcall on
// FUN_00498E30

void FUN_00498e30(u64 param_1)

{
  FUN_00498720_wide(param_1,0,1);
  return;
}
#pragma tailcall off

// FUN_00498E40 NONMATCHING

u32 FUN_00498e40(long param_1,long param_2)

{
  if (param_1 != 0) {
    *(u32 *)param_1 = PTR_FUN_0077dda0;
  }
  if (param_2 != 0) {
    *(u32 *)param_2 = DAT_0077dda4;
  }
  return 1;
}

// FUN_00498E70 NONMATCHING

long FUN_00498e70(int param_1)

{
  int iVar1;
  int *piVar2;
  u32 uVar3;
  long lVar4;
  int *piVar5;
  u32 uVar6;
  int iVar7;
  u32 *puVar8;
  u32 *puVar9;
  u32 uVar10;
  u32 *puVar11;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  piVar2 = (int *)(*DAT_00960178)(*(int *)(param_1 + 4) << 2,0x10502);
  if (piVar2 == (int *)0x0) {
    uStack_10 = 2;
    uStack_c = ((code)FUN_004c1d10)(0xffffffff80000013,*(int *)(param_1 + 4) << 2);
    ((code)FUN_004c1c50)(&uStack_10);
    lVar4 = 0;
  }
  else {
    uVar10 = 0;
    uVar3 = 0;
    if (*(int *)(param_1 + 4) != 0) {
      iVar7 = 0;
      piVar5 = piVar2;
      do {
        uVar10 = uVar10 + 1;
        *piVar5 = *(int *)(param_1 + 8) + iVar7;
        iVar7 = iVar7 + 0x14;
        uVar3 = *(u32 *)(param_1 + 4);
        piVar5 = piVar5 + 1;
      } while (uVar10 < uVar3);
    }
    ((code)FUN_005225f8)(piVar2,uVar3,4,0x4965a0);
    uVar3 = *(u32 *)(param_1 + 4);
    uVar6 = 1;
    uVar10 = uVar6;
    if ((1 < uVar3) && (iVar7 = *(int *)(*piVar2 + 8), piVar5 = piVar2, 1 < uVar3)) {
      do {
        iVar1 = *(int *)(piVar5[1] + 8);
        if (iVar1 != iVar7) {
          uVar10 = uVar10 + 1;
          iVar7 = iVar1;
        }
        uVar6 = uVar6 + 1;
        piVar5 = piVar5 + 1;
      } while (uVar6 < uVar3);
    }
    iVar7 = uVar10 * 0xc + 0x10 + uVar3 * 6;
    lVar4 = ((code)FUN_004959c0)(iVar7);
    if (lVar4 == 0) {
      (*DAT_0096017c)(piVar2);
      uStack_8 = 2;
      uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,iVar7);
      ((code)FUN_004c1c50)(&uStack_8);
      lVar4 = 0;
    }
    else {
      puVar11 = (u32 *)lVar4;
      *puVar11 = 0;
      *(u16 *)(puVar11 + 1) = 1;
      puVar9 = puVar11 + 4;
      uVar3 = 0;
      puVar8 = puVar9 + uVar10 * 3;
      *(u16 *)((int)puVar11 + 6) = *(u16 *)((int)(u8 *)DAT_00960070 + iGpffffbb60);
      puVar11[3] = 0;
      puVar11[2] = *(int *)(param_1 + 4) * 3;
      *(short *)((int)(u8 *)DAT_00960070 + iGpffffbb60) =
           *(short *)((int)(u8 *)DAT_00960070 + iGpffffbb60) + 1;
      puVar11[5] = 0;
      puVar11[6] = *(u32 *)(*piVar2 + 8);
      puVar11[4] = (u32)(puVar8);
      piVar5 = piVar2;
      do {
        if (*(int *)(*piVar5 + 8) != puVar9[2]) {
          puVar9[4] = 0;
          puVar9[5] = *(u32 *)(*piVar5 + 8);
          puVar9[3] = (u32)(puVar8);
          *(short *)(puVar11 + 1) = *(short *)(puVar11 + 1) + 1;
          puVar9 = puVar9 + 3;
        }
        uVar3 = uVar3 + 1;
        *(u16 *)puVar8 = *(u16 *)*piVar5;
        *(u16 *)((int)puVar8 + 2) = *(u16 *)(*piVar5 + 2);
        iVar7 = *piVar5;
        piVar5 = piVar5 + 1;
        *(u16 *)(puVar8 + 1) = *(u16 *)(iVar7 + 4);
        puVar9[1] = puVar9[1] + 3;
        puVar8 = (u32 *)((int)puVar8 + 6);
      } while (uVar3 < *(u32 *)(param_1 + 4));
      ((code)FUN_00495f10)(lVar4,0x4967a0,0);
      (*DAT_0096017c)(piVar2);
    }
  }
  return lVar4;
}

// FUN_00499140 NONMATCHING

long FUN_00499140(long param_1,u32 param_2)

{
  long lVar1;
  code *pcVar2;
  u32 uVar3;
  
  if (param_1 != 0) {
    if (*(int *)((int)param_1 + 4) == 0) {
      ((code)FUN_00495c20)();
      return 0x77dd90;
    }
    pcVar2 = (code *)PTR_FUN_0077dda0;
    uVar3 = DAT_0077dda4;
    if ((param_2 & 1) == 0) {
      pcVar2 = (code *)(FUN_00498e70);
      uVar3 = 0;
    }
    lVar1 = (*pcVar2)(param_1,uVar3);
    if (lVar1 != 0) {
      ((code)FUN_00495c20)(param_1);
      return lVar1;
    }
  }
  return 0;
}

#pragma tailcall on
// FUN_00499230
void FUN_00499230(void)
{
  ((code)(*(u32 *)((u8 *)DAT_00960074_abs[0] + 0x68)))();
  return;
}
#pragma tailcall off

// FUN_00499250 NONMATCHING

void FUN_00499250(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5)

{
  ((code)FUN_004c61b0)(0x77ddb0,param_1,param_2,param_3,param_4,param_5);
  return;
}

// FUN_00499280 NONMATCHING

void FUN_00499280(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  ((code)FUN_004c5960)(0x77ddb0,param_1,param_2,param_3,param_4);
  return;
}

// FUN_004992B0 NONMATCHING

void FUN_004992b0(u64 param_1,u64 param_2)

{
  ((code)FUN_004c59b0)(0x77ddb0,param_1,param_2);
  return;
}

#pragma tailcall on
// FUN_004992D0

void FUN_004992d0(u64 param_1,u64 param_2)

{
  FUN_004c5a00_u32((u32)DAT_0077ddb0_abs,param_1,param_2);
}
#pragma tailcall off
// FUN_004992F0 NONMATCHING
u32 FUN_004992f0(u32 param_1,u32 *param_2)
{
  if (*param_2 == param_1) {
    goto equal;
  }
  return param_1;
equal:
  param_2[1] = 1;
  return 0;
}

// FUN_00499320 NONMATCHING

u64 FUN_00499320(u64 param_1)

{
  u32 *puVar1;
  int iVar2;
  long lVar3;
  u64 uVar4;
  
  lVar3 = ((code)FUN_00499230)();
  if (lVar3 != 0) {
    for (puVar1 = *(u32 **)((int)param_1 + 0x38);
        puVar1 != (u32 *)((int)param_1 + 0x38); puVar1 = (u32 *)*puVar1) {
      iVar2 = puVar1[2];
      if (((*(u8 *)(iVar2 + 2) & 4) != 0) && (*(short *)(iVar2 + 0x60) != DAT_00960078)) {
        uVar4 = ((code)FUN_004912b0)(iVar2);
        lVar3 = ((code)FUN_004c9df0)(DAT_00960070,uVar4);
        if (lVar3 != 0) {
          (**(code **)(iVar2 + 0x48))(iVar2);
        }
        *(short *)(iVar2 + 0x60) = DAT_00960078;
      }
    }
  }
  return param_1;
}

// FUN_00499400 NONMATCHING

int FUN_00499400(int param_1,u64 param_2,int param_3,int param_4)

{
  int *piVar1;
  int *piVar2;
  u64 uVar3;
  u64 uVar4;
  long lVar5;
  int iVar6;
  u16 *puVar7;
  u32 uVar8;
  int iVar9;
  int iVar10;
  u32 uVar11;
  u32 uVar12;
  u32 uVar13;
  int iVar14;
  
  uVar13 = 0;
  uVar12 = 0;
  uVar11 = 0;
  if (*(int *)(param_1 + 0x14) != 0) {
    iVar9 = *(int *)(param_1 + 0x14) << 2;
    uVar3 = (*DAT_00960178)(iVar9,0x10006);
    uVar4 = (*DAT_00960178)(iVar9,0x10507);
    iVar9 = (*DAT_00960178)(iVar9,0x10507);
    iVar14 = 0;
    if (*(short *)(param_3 + 0x84) != 0) {
      iVar10 = 0;
      do {
        iVar6 = 0;
        puVar7 = (u16 *)(*(int *)(param_3 + 4) + iVar10);
        piVar1 = *(int **)(param_4 + (u32)(u16)puVar7[3] * 4);
        piVar2 = (int *)*piVar1;
        uVar8 = 0;
        if (uVar13 != 0) {
          do {
            if (*(int **)((int)uVar3 + uVar8 * 4) == piVar2) break;
            uVar8 = uVar8 + 1 & 0xffff;
          } while (uVar8 < uVar13);
        }
        if (uVar8 == uVar13) {
          uVar13 = uVar13 + 1 & 0xffff;
          *(int **)((int)uVar3 + uVar8 * 4) = piVar2;
        }
        if (piVar2 != (int *)0x0) {
          iVar6 = *piVar2;
        }
        uVar8 = 0;
        if (uVar12 != 0) {
          do {
            if (*(int *)((int)uVar4 + uVar8 * 4) == iVar6) break;
            uVar8 = uVar8 + 1 & 0xffff;
          } while (uVar8 < uVar12);
        }
        if (uVar8 == uVar12) {
          *(int *)((int)uVar4 + uVar8 * 4) = iVar6;
          uVar12 = uVar12 + 1 & 0xffff;
        }
        uVar8 = 0;
        if (uVar11 != 0) {
          do {
            if (*(int *)(iVar9 + uVar8 * 4) == piVar1[2]) break;
            uVar8 = uVar8 + 1 & 0xffff;
          } while (uVar8 < uVar11);
        }
        if (uVar8 == uVar11) {
          *(int *)(iVar9 + uVar8 * 4) = piVar1[2];
          uVar11 = uVar11 + 1 & 0xffff;
        }
        ((code)FUN_00495cf0)(param_2,piVar1,*puVar7,puVar7[1],puVar7[2],puVar7[3]);
        iVar14 = iVar14 + 1;
        iVar10 = iVar10 + 8;
      } while (iVar14 < (int)(u32)*(u16 *)(param_3 + 0x84));
    }
    (*DAT_0096017c)(uVar3);
    (*DAT_0096017c)(uVar4);
    (*DAT_0096017c)(iVar9);
  }
  if ((*(u32 *)(param_1 + 8) & 1) == 0) {
    lVar5 = ((code)FUN_00499140)(param_2,0);
  }
  else {
    lVar5 = ((code)FUN_00499140)(param_2,1);
  }
  if (lVar5 == 0) {
    ((code)FUN_00495c20)(param_2);
    param_1 = 0;
  }
  else {
    *(int *)(param_3 + 0x78) = (int)lVar5;
  }
  return param_1;
}

// FUN_00499720 NONMATCHING

void FUN_00499720(u64 param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = (int *)param_1;
  if (*piVar2 != -2) {
    if (*piVar2 == -1) {
      if (piVar2[0xd] != 0) {
        ((code)FUN_004c47e0)();
      }
      piVar3 = (int *)piVar2[0xe];
      if ((int *)piVar2[0xe] == piVar2 + 0xe) {
        piVar3 = (int *)piVar2[0x10];
      }
      else {
        do {
          piVar1 = (int *)*piVar3;
          ((code)FUN_0049af20)(piVar3);
          piVar3 = piVar1;
        } while (piVar1 != piVar2 + 0xe);
        piVar3 = (int *)piVar2[0x10];
      }
      while (piVar3 != piVar2 + 0x10) {
        piVar1 = (int *)*piVar3;
        ((code)FUN_0049aeb0)(piVar3);
        piVar3 = piVar1;
      }
      ((code)FUN_004c6560)(0x77ddb0,param_1);
      if (piVar2[0x1e] != 0) {
        ((code)FUN_00495c80)();
        piVar2[0x1e] = 0;
      }
    }
    else {
      if (piVar2[2] != 0) {
        ((code)FUN_00499720)();
      }
      if (piVar2[3] != 0) {
        ((code)FUN_00499720)();
      }
    }
  }
  return;
}

// FUN_00499850 NONMATCHING

void FUN_00499850(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (*param_1 == -2) {
    (*DAT_0096017c)();
  }
  else if (*param_1 == -1) {
    if (param_1[0xd] != 0) {
      ((code)FUN_004c47e0)();
    }
    piVar2 = (int *)param_1[0xe];
    if ((int *)param_1[0xe] == param_1 + 0xe) {
      piVar2 = (int *)param_1[0x10];
    }
    else {
      do {
        piVar1 = (int *)*piVar2;
        ((code)FUN_0049af20)(piVar2);
        piVar2 = piVar1;
      } while (piVar1 != param_1 + 0xe);
      piVar2 = (int *)param_1[0x10];
    }
    while (piVar2 != param_1 + 0x10) {
      piVar1 = (int *)*piVar2;
      ((code)FUN_0049aeb0)(piVar2);
      piVar2 = piVar1;
    }
    ((code)FUN_004c6560)(0x77ddb0,param_1);
    if (param_1[2] != 0) {
      (*DAT_0096017c)();
      param_1[2] = 0;
    }
    if (param_1[3] != 0) {
      (*DAT_0096017c)();
      param_1[3] = 0;
    }
    if (param_1[0xc] != 0) {
      (*DAT_0096017c)();
      param_1[0xc] = 0;
    }
    if (param_1[1] != 0) {
      (*DAT_0096017c)();
      param_1[1] = 0;
    }
    iVar3 = 0;
    piVar2 = param_1;
    do {
      if (piVar2[4] != 0) {
        (*DAT_0096017c)();
        piVar2[4] = 0;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 < 8);
    if (param_1[0x1e] != 0) {
      ((code)FUN_00495c80)();
      param_1[0x1e] = 0;
    }
    (*DAT_0096017c)(param_1);
  }
  else {
    if (param_1[2] != 0) {
      ((code)FUN_00499850)();
    }
    param_1[2] = 0;
    if (param_1[3] != 0) {
      ((code)FUN_00499850)();
    }
    param_1[3] = 0;
    (*DAT_0096017c)(param_1);
  }
  return;
}

// FUN_00499A80 NONMATCHING

u64 FUN_00499a80(u64 param_1)

{
  if (*(int *)((int)(u8 *)DAT_00960070 + iGpffffbb70) != 0) {
    ((code)FUN_004c3c30)();
    *(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb70) = 0;
  }
  ((code)FUN_0049c680)();
  iGpffffbb74 = iGpffffbb74 + -1;
  return param_1;
}

// FUN_00499AF0 NONMATCHING

u64 FUN_00499af0(u64 param_1,int param_2)

{
  int iVar1;
  long lVar2;
  
  iGpffffbb70 = param_2;
  lVar2 = ((code)FUN_0049c6c0)();
  if (lVar2 == 0) {
    param_1 = 0;
  }
  else {
    iVar1 = thunk_FUN_004c3970(0x10,8,4,1,0x95df30,0x4000b);
    *(int *)((int)(u8 *)DAT_00960070 + iGpffffbb70) = iVar1;
    if (*(int *)((int)(u8 *)DAT_00960070 + iGpffffbb70) == 0) {
      param_1 = 0;
    }
    else {
      *(int *)((int)(u8 *)DAT_00960074 + iGpffffbb70) = (int)(u8 *)DAT_00960074 + iGpffffbb70;
      *(int *)((int)(u8 *)DAT_00960078 + iGpffffbb70) = (int)(u8 *)DAT_00960074 + iGpffffbb70;
      iGpffffbb74 = iGpffffbb74 + 1;
    }
  }
  return param_1;
}

// FUN_00499B90 NONMATCHING

u64 FUN_00499b90(u64 param_1)

{
  long lVar1;
  int iVar2;
  
  if (*(short *)((int)param_1 + 0x84) != 0) {
    iVar2 = *(int *)((int)param_1 + 0x7c);
    if ((iVar2 == 0) && (iVar2 = *(int *)(DAT_00960074 + 0x6c), iVar2 == 0)) {
      iVar2 = *(int *)((u8 *)DAT_009600b0 + iGpffffbe38);
    }
    lVar1 = ((code)FUN_004f2e70)(iVar2,param_1,1);
    if (lVar1 == 0) {
      param_1 = 0;
    }
  }
  return param_1;
}

// FUN_00499C20 NONMATCHING

u32 FUN_00499c20(code *param_1,u64 param_2)

{
  u32 *puVar1;
  long lVar2;
  u32 *puVar3;
  u32 *puVar4;
  
  puVar1 = *(u32 **)(DAT_00960074 + 0x3c);
  puVar4 = (u32 *)(DAT_00960074 + 0x3c);
  do {
    if (puVar1 == puVar4) {
      return 1;
    }
    puVar3 = puVar1 + -0xd;
    puVar1 = (u32 *)*puVar1;
  } while ((puVar3 == (u32 *)0x0) || (lVar2 = (*param_1)(puVar3,param_2), lVar2 != 0));
  return 1;
}

// FUN_00499CA0 NONMATCHING

u64 FUN_00499ca0(u64 param_1,code *param_2,u64 param_3)

{
  int *piVar1;
  u32 *puVar2;
  long lVar3;
  
  puVar2 = *(u32 **)((int)param_1 + 0x40);
  do {
    if (puVar2 == (u32 *)((int)param_1 + 0x40)) {
      return param_1;
    }
    piVar1 = (int *)(puVar2 + 2);
    puVar2 = (u32 *)*puVar2;
  } while ((*piVar1 == 0) || (lVar3 = (*param_2)(*piVar1,param_3), lVar3 != 0));
  return param_1;
}

// FUN_00499D30 NONMATCHING

u64 FUN_00499d30(u64 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int aiStack_720 [384];
  int aiStack_120 [4];
  int iStack_110;
  int iStack_10c;
  int aiStack_100 [64];
  
  iVar7 = (int)param_1;
  piVar6 = *(int **)(iVar7 + 0x1c);
  aiStack_120[0] = *(int *)(iVar7 + 0x50);
  aiStack_120[1] = *(int *)(iVar7 + 0x54);
  aiStack_120[2] = *(int *)(iVar7 + 0x58);
  aiStack_120[3] = *(int *)(iVar7 + 0x5c);
  iStack_110 = *(int *)(iVar7 + 0x60);
  iStack_10c = *(int *)(iVar7 + 100);
  iVar7 = 0;
  do {
    iVar3 = aiStack_120[3];
    iVar2 = aiStack_120[2];
    iVar1 = aiStack_120[1];
    if (*piVar6 < 0) {
      piVar6[0x12] = aiStack_120[0];
      piVar6[0x13] = aiStack_120[1];
      iVar8 = iVar7 + -1;
      piVar6[0x14] = aiStack_120[2];
      piVar6[0x15] = aiStack_120[3];
      piVar6[0x16] = iStack_110;
      piVar6[0x17] = iStack_10c;
      piVar6 = (int *)aiStack_100[iVar7];
      aiStack_120[0] = aiStack_720[iVar7 * 6];
      aiStack_120[1] = aiStack_720[iVar7 * 6 + 1];
      aiStack_120[2] = aiStack_720[iVar7 * 6 + 2];
      aiStack_120[3] = aiStack_720[iVar7 * 6 + 3];
      iStack_110 = aiStack_720[iVar7 * 6 + 4];
      iStack_10c = aiStack_720[iVar7 * 6 + 5];
    }
    else {
      iVar8 = iVar7 + 1;
      iVar7 = *piVar6;
      iVar9 = piVar6[5];
      aiStack_100[iVar8] = piVar6[3];
      iVar10 = piVar6[4];
      aiStack_720[iVar8 * 6] = aiStack_120[0];
      iVar5 = iStack_10c;
      iVar4 = iStack_110;
      piVar6 = (int *)piVar6[2];
      aiStack_720[iVar8 * 6 + 1] = iVar1;
      aiStack_720[iVar8 * 6 + 2] = iVar2;
      aiStack_720[iVar8 * 6 + 3] = iVar3;
      aiStack_720[iVar8 * 6 + 4] = iVar4;
      aiStack_720[iVar8 * 6 + 5] = iVar5;
      *(int *)((int)(aiStack_720 + iVar8 * 6) + iVar7 + 0xc) = iVar9;
      *(int *)((int)aiStack_120 + iVar7) = iVar10;
    }
    iVar7 = iVar8;
  } while (-1 < iVar8);
  return param_1;
}

// FUN_00499E90 NONMATCHING

void FUN_00499e90(u32 param_1,u32 param_2)

{
  u32 *puVar1;
  long lVar2;
  
  lVar2 = (*DAT_00960188)(*(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb70),0x40507);
  if (lVar2 != 0) {
    puVar1 = (u32 *)lVar2;
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = *(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb70);
    puVar1[3] = (int)(u8 *)DAT_00960074 + iGpffffbb70;
    *(u32 **)(*(int *)((int)(u8 *)DAT_00960074 + iGpffffbb70) + 4) = puVar1 + 2;
    *(u32 **)((int)(u8 *)DAT_00960074 + iGpffffbb70) = puVar1 + 2;
  }
  return;
}

// FUN_00499F40 NONMATCHING

void FUN_00499f40(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)((int)(u8 *)DAT_00960074 + iGpffffbb70);
  while( 1 ) {
    if (piVar1 == (int *)((int)(u8 *)DAT_00960074 + iGpffffbb70)) {
      return;
    }
    if (piVar1[-2] == param_1) break;
    piVar1 = (int *)*piVar1;
  }
  *(int *)piVar1[1] = *piVar1;
  *(int *)(*piVar1 + 4) = piVar1[1];
  (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb70));
  return;
}

// FUN_00499FD0 NONMATCHING

u64 FUN_00499fd0(u64 param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int aiStack_100 [64];
  
  piVar3 = *(int **)((int)param_1 + 0x1c);
  iVar2 = 0;
  if (piVar3 == (int *)0x0) {
    param_1 = 0;
  }
  else {
    do {
      if (*piVar3 < 0) {
        if (piVar3[0x1e] != 0) {
          ((code)FUN_00495c80)();
          piVar3[0x1e] = 0;
        }
        piVar3 = (int *)aiStack_100[iVar2];
        iVar2 = iVar2 + -1;
      }
      else {
        piVar1 = piVar3 + 3;
        iVar2 = iVar2 + 1;
        piVar3 = (int *)piVar3[2];
        aiStack_100[iVar2] = *piVar1;
      }
    } while (-1 < iVar2);
  }
  return param_1;
}

// FUN_0049A080 NONMATCHING

long FUN_0049a080(long param_1)

{
  int *piVar1;
  u16 uVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  int *piVar6;
  int aiStack_100 [64];
  
  piVar6 = *(int **)((int)param_1 + 0x1c);
  iVar5 = 0;
  if (piVar6 == (int *)0x0) {
    param_1 = 0;
  }
  else {
    do {
      if (*piVar6 < 0) {
        uVar2 = *(u16 *)(piVar6 + 0x20);
        iVar3 = *(int *)((int)param_1 + 0x10);
        if (piVar6[0x1e] == 0) {
          lVar4 = ((code)FUN_00495b10)((short)piVar6[0x21]);
          if (lVar4 == 0) {
            return 0;
          }
          param_1 = ((code)FUN_00499400)(param_1,lVar4,piVar6,iVar3 + (u32)uVar2 * 4);
          if (param_1 == 0) {
            return 0;
          }
        }
        piVar6 = (int *)aiStack_100[iVar5];
        iVar5 = iVar5 + -1;
      }
      else {
        piVar1 = piVar6 + 3;
        iVar5 = iVar5 + 1;
        piVar6 = (int *)piVar6[2];
        aiStack_100[iVar5] = *piVar1;
      }
    } while (-1 < iVar5);
  }
  return param_1;
}

// FUN_0049A170 NONMATCHING

u32 FUN_0049a170(u32 param_1)

{
  u32 *puVar1;
  u32 uVar2;
  u32 *puVar3;
  u32 uStack_8;
  int iStack_4;
  
  puVar1 = *(u32 **)((int)(u8 *)DAT_00960074 + iGpffffbb70);
  puVar3 = (u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb70);
  do {
    if (puVar1 == puVar3) {
      return 0;
    }
    uVar2 = puVar1[-2];
    if ((*(u8 *)(uVar2 + 3) & 1) == 0) {
      iStack_4 = 0;
      uStack_8 = param_1;
      ((code)FUN_0049a870)(puVar1[-2],0x4992f0,&uStack_8);
      if (iStack_4 != 0) {
        return puVar1[-2];
      }
    }
    else if ((uVar2 <= param_1) && (param_1 < uVar2 + puVar1[-1])) {
      return uVar2;
    }
    puVar1 = (u32 *)*puVar1;
  } while( 1 );
}

// FUN_0049A250

u64 FUN_0049a250(u64 param_1)

{
  FUN_0049c330_typed(*(u32 *)DAT_00960070_abs,(u32)FUN_00499320,param_1);
  return param_1;
}

// FUN_0049A290 NONMATCHING

u32 FUN_0049a290(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)((int)(u8 *)DAT_00960074 + iGpffffbb70);
  do {
    if (piVar1 == (int *)((int)(u8 *)DAT_00960074 + iGpffffbb70)) {
LAB_0049a39c:
      ((code)FUN_00499fd0)(param_1);
      ((code)FUN_00495260)(param_1 + 0x10);
      if ((*(u8 *)(param_1 + 3) & 1) == 0) {
        if (*(int *)(param_1 + 0x1c) != 0) {
          ((code)FUN_00499850)();
        }
        ((code)FUN_004c6560)(0x77ddd0,param_1);
        (*DAT_0096017c)(param_1);
      }
      else {
        if (*(int *)(param_1 + 0x1c) != 0) {
          ((code)FUN_00499720)();
        }
        ((code)FUN_004c6560)(0x77ddd0,param_1);
        (*DAT_0096017c)(param_1);
      }
      return 1;
    }
    if (piVar1[-2] == param_1) {
      *(int *)piVar1[1] = *piVar1;
      *(int *)(*piVar1 + 4) = piVar1[1];
      (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb70));
      goto LAB_0049a39c;
    }
    piVar1 = (int *)*piVar1;
  } while( 1 );
}

#pragma optimization_level 3
#pragma schedule on
#pragma optimization_level 2
 
// FUN_0049A3D0 NONMATCHING
u32 FUN_0049a3d0(u32 param_1,code *param_2)
{
  u32 result;

  result = param_1;
  if (param_2 != (code *)0x0) {
    *(code **)((int)param_1 + 0x68) = param_2;
  }
  else {
    param_2 = (code *)FUN_00499b90;
    *(code **)((int)param_1 + 0x68) = param_2;
  }
  return result;
}
#pragma optimization_level 2

// FUN_0049A400 NONMATCHING

long FUN_0049a400(u32 *param_1)

{
  u32 *puVar1;
  long lVar2;
  long lVar3;
  long lVar4;
  u8 *puVar5;
  u8 *puVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  lVar2 = (*DAT_00960178)(DAT_0077ddd0,0x3000b);
  if (lVar2 == 0) {
    uStack_8 = 2;
    uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,DAT_0077ddd0);
    ((code)FUN_004c1c50)(&uStack_8);
    lVar2 = 0;
  }
  else {
    puVar6 = (u8 *)lVar2;
    *puVar6 = 7;
    puVar6[1] = 0;
    puVar6[2] = 0;
    puVar6[3] = 0;
    *(u32 *)(puVar6 + 4) = 0;
    ((code)FUN_00495300)(puVar6 + 0x10);
    *(u32 *)(puVar6 + 0xc) = 2;
    *(u32 *)(puVar6 + 8) = 0;
    lVar3 = (*DAT_00960178)(DAT_0077ddb0,0x3000b);
    if (lVar3 == 0) {
      uStack_10 = 2;
      uStack_c = ((code)FUN_004c1d10)(0xffffffff80000013,4);
      ((code)FUN_004c1c50)(&uStack_10);
      (*DAT_0096017c)(lVar2);
      lVar2 = 0;
    }
    else {
      puVar1 = (u32 *)lVar3;
      *puVar1 = 0xffffffff;
      puVar1[0xd] = 0;
      puVar1[0x1e] = 0;
      puVar1[0xe] = (u32)(puVar1 + 0xe);
      puVar1[0xf] = (u32)(puVar1 + 0xe);
      puVar1[0x10] = (u32)(puVar1 + 0x10);
      puVar1[0x11] = (u32)(puVar1 + 0x10);
      *(u16 *)((int)puVar1 + 0x82) = 0;
      *(u16 *)(puVar1 + 0x21) = 0;
      puVar1[2] = 0;
      puVar1[1] = 0;
      puVar1[3] = 0;
      ((code)FUN_00521408)(puVar1 + 4,0,0x20);
      puVar1[0xc] = 0;
      uVar7 = param_1[4];
      uVar8 = param_1[5];
      puVar5 = puVar6 + 0x2c;
      puVar1[0x15] = param_1[3];
      puVar1[0x16] = uVar7;
      puVar1[0x17] = uVar8;
      uVar7 = param_1[1];
      uVar8 = param_1[2];
      puVar1[0x12] = *param_1;
      puVar1[0x13] = uVar7;
      puVar1[0x14] = uVar8;
      uVar7 = param_1[4];
      uVar8 = param_1[5];
      puVar1[0x1b] = param_1[3];
      puVar1[0x1c] = uVar7;
      puVar1[0x1d] = uVar8;
      uVar7 = param_1[1];
      uVar8 = param_1[2];
      puVar1[0x18] = *param_1;
      puVar1[0x19] = uVar7;
      puVar1[0x1a] = uVar8;
      puVar1[0x1f] = 0;
      *(u32 **)(puVar6 + 0x1c) = puVar1;
      *(u32 *)(puVar6 + 0x20) = 0;
      *(u32 *)(puVar6 + 0x4c) = 0;
      *(u32 *)(puVar6 + 0x48) = 0;
      *(u32 *)(puVar6 + 0x44) = 0;
      uVar7 = param_1[4];
      uVar8 = param_1[5];
      *(u32 *)(puVar6 + 0x5c) = param_1[3];
      *(u32 *)(puVar6 + 0x60) = uVar7;
      *(u32 *)(puVar6 + 100) = uVar8;
      uVar7 = param_1[1];
      uVar8 = param_1[2];
      *(u32 *)(puVar6 + 0x50) = *param_1;
      *(u32 *)(puVar6 + 0x54) = uVar7;
      *(u32 *)(puVar6 + 0x58) = uVar8;
      *(u8 **)(puVar6 + 0x2c) = puVar5;
      *(u8 **)(puVar6 + 0x30) = puVar5;
      *(u32 *)(puVar6 + 0x24) = 0;
      *(u8 **)(puVar6 + 0x28) = puVar5;
      *(u8 **)(puVar6 + 0x34) = puVar6 + 0x34;
      *(u8 **)(puVar6 + 0x38) = puVar6 + 0x34;
      *(u8 **)(puVar6 + 0x3c) = puVar6 + 0x3c;
      *(u8 **)(puVar6 + 0x40) = puVar6 + 0x3c;
      *(code **)(puVar6 + 0x68) = (code *)(FUN_00499b90);
      *(u32 *)(puVar6 + 0x6c) = 0;
      uVar7 = DAT_0077ddd0;
      lVar4 = (*DAT_00960188)(*(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb70),0x40507);
      if (lVar4 != 0) {
        puVar1 = (u32 *)lVar4;
        *puVar1 = (u32)(puVar6);
        puVar1[1] = uVar7;
        puVar1[2] = *(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb70);
        puVar1[3] = (int)(u8 *)DAT_00960074 + iGpffffbb70;
        *(u32 **)(*(int *)((int)(u8 *)DAT_00960074 + iGpffffbb70) + 4) = puVar1 + 2;
        *(u32 **)((int)(u8 *)DAT_00960074 + iGpffffbb70) = puVar1 + 2;
      }
      ((code)FUN_004c64b0)(0x77ddd0,lVar2);
      ((code)FUN_004c64b0)(0x77ddb0,lVar3);
      lVar3 = ((code)FUN_0049a080)(lVar2);
      if (lVar3 == 0) {
        ((code)FUN_00499f40)(lVar2);
        ((code)FUN_00499fd0)(lVar2);
        ((code)FUN_00495260)(puVar6 + 0x10);
        if ((puVar6[3] & 1) == 0) {
          if (*(int *)(puVar6 + 0x1c) != 0) {
            ((code)FUN_00499850)();
          }
          ((code)FUN_004c6560)(0x77ddd0,lVar2);
          (*DAT_0096017c)(lVar2);
          lVar2 = 0;
        }
        else {
          if (*(int *)(puVar6 + 0x1c) != 0) {
            ((code)FUN_00499720)();
          }
          ((code)FUN_004c6560)(0x77ddd0,lVar2);
          (*DAT_0096017c)(lVar2);
          lVar2 = 0;
        }
      }
    }
  }
  return lVar2;
}

// FUN_0049A7C0 NONMATCHING

u64 FUN_0049a7c0(u64 param_1,code *param_2,u64 param_3)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)((int)param_1 + 0x14);
  iVar4 = 0;
  if (0 < iVar1) {
    iVar3 = 0;
    do {
      lVar2 = (*param_2)(*(u32 *)(*(int *)((int)param_1 + 0x10) + iVar3),param_3);
      if (lVar2 == 0) {
        return param_1;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar4 < iVar1);
  }
  return param_1;
}

// FUN_0049A870 NONMATCHING

u64 FUN_0049a870(u64 param_1,code *param_2,u64 param_3)

{
  int *piVar1;
  int *piVar2;
  long lVar3;
  int iVar4;
  int aiStack_100 [64];
  
  piVar2 = *(int **)((int)param_1 + 0x1c);
  iVar4 = 0;
  do {
    if (*piVar2 < 0) {
      lVar3 = (*param_2)(piVar2,param_3);
      if (lVar3 == 0) {
        return param_1;
      }
      piVar2 = (int *)aiStack_100[iVar4];
      iVar4 = iVar4 + -1;
    }
    else {
      piVar1 = piVar2 + 3;
      iVar4 = iVar4 + 1;
      piVar2 = (int *)piVar2[2];
      aiStack_100[iVar4] = *piVar1;
    }
  } while (-1 < iVar4);
  return param_1;
}

// FUN_0049A920 NONMATCHING

void FUN_0049a920(u64 param_1,u64 param_2,u64 param_3,u64 param_4,
                 u64 param_5)

{
  ((code)FUN_004c61b0)(0x77ddd0,param_1,param_2,param_3,param_4,param_5);
  return;
}

// FUN_0049A950 NONMATCHING

void FUN_0049a950(u64 param_1,u64 param_2,u64 param_3,u64 param_4)

{
  ((code)FUN_004c5960)(0x77ddd0,param_1,param_2,param_3,param_4);
  return;
}

// FUN_0049A980 NONMATCHING

u8 FUN_0049a980(void)

{
  u8 bVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar9;
  long lVar10;
  
  uVar2 = ((code)FUN_004ca520)(4,0x501,0x494ae0,0x494b70);
  uVar3 = ((code)FUN_004ca520)(0x30,0x502,0x495a30,0x4959e0);
  uVar4 = ((code)FUN_004ca520)(4,0x503,0x492de0,0x492e00);
  uVar5 = ((code)FUN_004ca520)(8,0x504,0x4914d0,0x491410);
  uVar6 = ((code)FUN_004ca520)(4,0x505,0x494930,0x4948b0);
  uVar7 = ((code)FUN_004ca520)(0,0x50a,0x4991f0,0x499210);
  uVar8 = ((code)FUN_004ca520)(0xc,0x507,0x499af0,0x499a80);
  uVar9 = ((code)FUN_004ca520)(0,0x50b,0x4906b0,0x490690);
  if ((long)(uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9) < 0) {
    bVar1 = 0;
  }
  else {
    lVar10 = ((code)FUN_0049be50)();
    if (lVar10 == 0) {
      bVar1 = 0;
    }
    else {
      lVar10 = ((code)FUN_004915c0)();
      if (lVar10 == 0) {
        bVar1 = 0;
      }
      else {
        lVar10 = ((code)FUN_004a5100)();
        bVar1 = lVar10 != 0;
      }
    }
  }
  return bVar1;
}

// FUN_0049AAF0 NONMATCHING

u64 FUN_0049aaf0(u64 param_1,int param_2)

{
  int iVar1;
  u32 uVar2;
  
  iGpffffbb88 = param_2;
  iVar1 = thunk_FUN_004c3970(0x18,uGpffffaf00,4,uGpffffaf04,0x95df90,0x40507);
  *(int *)((int)(u8 *)DAT_00960070 + iGpffffbb88) = iVar1;
  if (*(int *)((int)(u8 *)DAT_00960070 + iGpffffbb88) == 0) {
    param_1 = 0;
  }
  else {
    uVar2 = thunk_FUN_004c3970(0x18,uGpffffaf08,4,uGpffffaf0c,0x95df60,0x40507);
    *(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb88) = uVar2;
    if (*(int *)((int)(u8 *)DAT_00960074 + iGpffffbb88) == 0) {
      ((code)FUN_004c3c30)(*(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb88));
      param_1 = 0;
      *(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb88) = 0;
    }
    else {
      DAT_00960078 = 1;
      iGpffffbb8c = iGpffffbb8c + 1;
      *(u32 *)((int)(u8 *)DAT_00960078 + iGpffffbb88) = 0;
    }
  }
  return param_1;
}

// FUN_0049ABF0 NONMATCHING

u64 FUN_0049abf0(u64 param_1)

{
  if (*(int *)((int)(u8 *)DAT_00960074 + iGpffffbb88) != 0) {
    ((code)FUN_004c3c30)();
    *(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb88) = 0;
  }
  if (*(int *)((int)(u8 *)DAT_00960070 + iGpffffbb88) != 0) {
    ((code)FUN_004c3c30)();
    *(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb88) = 0;
  }
  iGpffffbb8c = iGpffffbb8c + -1;
  return param_1;
}

// FUN_0049ADE0 NONMATCHING

u64 FUN_0049ade0(u64 param_1,int param_2)

{
  int iVar1;
  u32 *puVar2;
  
  iVar1 = *(int *)(param_2 + iGpffffbb78 + 0xc);
  puVar2 = (u32 *)((int)param_1 + iGpffffbb78);
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  if (iVar1 != 0) {
    ((code)FUN_0049c160)(iVar1,param_1);
  }
  return param_1;
}

// FUN_0049AE30 NONMATCHING

u64 FUN_0049ae30(u64 param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (int)param_1;
  piVar2 = (int *)(iVar1 + iGpffffbb78);
  if (*piVar2 != 0) {
    (*DAT_0096017c)();
  }
  *piVar2 = 0;
  piVar2[1] = 0;
  piVar2[2] = 0;
  *(int *)(iVar1 + 0x18) = piVar2[4];
  *(int *)(iVar1 + 0x1c) = piVar2[5];
  *(int *)(iVar1 + 0x10) = piVar2[6];
  return param_1;
}

// FUN_0049AEB0 NONMATCHING

u32 FUN_0049aeb0(u64 param_1)

{
  int *piVar1;
  
  piVar1 = (int *)param_1;
  *(int *)piVar1[4] = piVar1[3];
  *(int *)(piVar1[3] + 4) = piVar1[4];
  *(int *)piVar1[1] = *piVar1;
  *(int *)(*piVar1 + 4) = piVar1[1];
  (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb88),param_1);
  return 1;
}

// FUN_0049AF20 NONMATCHING

u32 FUN_0049af20(int *param_1)

{
  if ((param_1[2] != 0) && (param_1[5] != 0)) {
    *(int *)param_1[4] = param_1[3];
    *(int *)(param_1[3] + 4) = param_1[4];
    *(int *)param_1[1] = *param_1;
    *(int *)(*param_1 + 4) = param_1[1];
    (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb88));
  }
  return 1;
}

// FUN_0049AFA0 NONMATCHING

void FUN_0049afa0(int param_1,u64 param_2)

{
  int *piVar1;
  float *pfVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  float fVar7;
  int aiStack_120 [64];
  float afStack_20 [4];
  float afStack_10 [4];
  
  iVar4 = 0;
  pfVar2 = (float *)((code)FUN_004912b0)(param_2);
  piVar5 = *(int **)(param_1 + 0x1c);
  fVar7 = pfVar2[3];
  afStack_10[0] = *pfVar2 - fVar7;
  afStack_20[0] = *pfVar2 + fVar7;
  afStack_10[1] = pfVar2[1] - fVar7;
  afStack_20[1] = pfVar2[1] + fVar7;
  afStack_10[2] = pfVar2[2] - fVar7;
  afStack_20[2] = pfVar2[2] + fVar7;
  do {
    if (*piVar5 < 0) {
      piVar3 = (int *)(*DAT_00960188)(*(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb88),0x30507);
      piVar3[5] = (int)piVar5;
      iVar6 = (int)param_2;
      piVar3[2] = iVar6;
      *piVar3 = piVar5[0xe];
      piVar3[1] = (int)(piVar5 + 0xe);
      *(int **)(piVar5[0xe] + 4) = piVar3;
      piVar5[0xe] = (int)piVar3;
      piVar1 = (int *)aiStack_120[iVar4];
      piVar3[3] = *(int *)(iVar6 + 100);
      piVar3[4] = iVar6 + 100;
      *(int **)(*(int *)(iVar6 + 100) + 4) = piVar3 + 3;
      *(int **)(iVar6 + 100) = piVar3 + 3;
      iVar4 = iVar4 + -1;
    }
    else if (*(float *)((int)afStack_10 + *piVar5) < (float)piVar5[4]) {
      piVar1 = (int *)piVar5[2];
      if ((float)piVar5[5] < *(float *)((int)afStack_20 + *piVar5)) {
        aiStack_120[iVar4 + 1] = piVar5[3];
        iVar4 = iVar4 + 1;
      }
    }
    else if ((float)piVar5[5] < *(float *)((int)afStack_20 + *piVar5)) {
      piVar1 = (int *)piVar5[3];
    }
    else {
      piVar1 = (int *)aiStack_120[iVar4];
      iVar4 = iVar4 + -1;
    }
    piVar5 = piVar1;
  } while (-1 < iVar4);
  return;
}

// FUN_0049B180 NONMATCHING

u64 FUN_0049b180(u64 param_1)

{
  int iVar1;
  int *piVar2;
  long lVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = (int)param_1;
  piVar4 = (int *)(iVar5 + iGpffffbb7c);
  lVar3 = (*(code *)piVar4[1])();
  if (lVar3 == 0) {
    param_1 = 0;
  }
  else {
    iVar1 = *piVar4;
    if (iVar1 != 0) {
      piVar4 = *(int **)(iVar5 + 100);
      while (piVar2 = piVar4, piVar2 != (int *)(iVar5 + 100)) {
        piVar4 = (int *)*piVar2;
        if ((piVar2[-1] != 0) && (piVar2[2] != 0)) {
          *(int *)piVar2[1] = *piVar2;
          *(int *)(*piVar2 + 4) = piVar2[1];
          *(int *)piVar2[-2] = piVar2[-3];
          *(int *)(piVar2[-3] + 4) = piVar2[-2];
          (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb88));
        }
      }
      ((code)FUN_0049afa0)(iVar1,param_1);
    }
  }
  return param_1;
}

// FUN_0049B2E0 NONMATCHING

u64 FUN_0049b2e0(u64 param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = (int)param_1;
  iVar3 = iVar4 + iGpffffbb7c;
  piVar1 = *(int **)(iVar4 + 100);
  while (piVar2 = piVar1, piVar2 != (int *)(iVar4 + 100)) {
    piVar1 = (int *)*piVar2;
    if ((piVar2[-1] != 0) && (piVar2[2] != 0)) {
      *(int *)piVar2[1] = *piVar2;
      *(int *)(*piVar2 + 4) = piVar2[1];
      *(int *)piVar2[-2] = piVar2[-3];
      *(int *)(piVar2[-3] + 4) = piVar2[-2];
      (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960070 + iGpffffbb88));
    }
  }
  *(u32 *)(iVar4 + 0x10) = *(u32 *)(iVar3 + 4);
  return param_1;
}

// FUN_0049B3F0 NONMATCHING

u64 FUN_0049b3f0(u64 param_1,int param_2)
{
  int callback;

  callback = *(int *)(param_2 + iGpffffbb80);
  if (callback != 0) {
    FUN_0049c240_typed(callback,param_1);
  }
  return param_1;
}

// FUN_0049B440 NONMATCHING

u64 FUN_0049b440(u64 param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  long lVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  int aiStack_130 [66];
  u32 uStack_28;
  u32 uStack_24;
  float afStack_20 [4];
  float afStack_10 [4];
  
  iVar8 = (int)param_1;
  piVar6 = (int *)(iVar8 + iGpffffbb84);
  lVar5 = (*(code *)piVar6[1])();
  if (lVar5 == 0) {
    uStack_28 = 2;
    uStack_24 = ((code)FUN_004c1d10)(0xffffffff80000016);
    ((code)FUN_004c1c50)(&uStack_28);
  }
  else if (0x7f < *(u8 *)(iVar8 + 1)) {
    iVar1 = *piVar6;
    iVar3 = *(int *)(iVar8 + 4);
    if ((iVar1 != 0) && (iVar3 != 0)) {
      fVar9 = *(float *)(iVar8 + 0x14);
      iVar7 = 0;
      piVar6 = *(int **)(iVar8 + 0x2c);
      while (piVar6 != (int *)(iVar8 + 0x2c)) {
        piVar2 = (int *)*piVar6;
        *(int *)piVar6[1] = *piVar6;
        *(int *)(*piVar6 + 4) = piVar6[1];
        *(int *)piVar6[-2] = piVar6[-3];
        *(int *)(piVar6[-3] + 4) = piVar6[-2];
        (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb88));
        piVar6 = piVar2;
      }
      iVar3 = ((code)FUN_004cb2f0)(iVar3);
      piVar6 = *(int **)(iVar1 + 0x1c);
      afStack_20[0] = *(float *)(iVar3 + 0x30) + fVar9;
      afStack_10[0] = *(float *)(iVar3 + 0x30) - fVar9;
      afStack_20[1] = *(float *)(iVar3 + 0x34) + fVar9;
      afStack_10[1] = *(float *)(iVar3 + 0x34) - fVar9;
      afStack_20[2] = *(float *)(iVar3 + 0x38) + fVar9;
      afStack_10[2] = *(float *)(iVar3 + 0x38) - fVar9;
      do {
        if (*piVar6 < 0) {
          piVar4 = (int *)(*DAT_00960188)(*(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb88),0x30507)
          ;
          piVar4[5] = (int)piVar6;
          piVar4[2] = iVar8;
          *piVar4 = piVar6[0x10];
          piVar4[1] = (int)(piVar6 + 0x10);
          *(int **)(piVar6[0x10] + 4) = piVar4;
          piVar6[0x10] = (int)piVar4;
          piVar2 = (int *)aiStack_130[iVar7];
          piVar4[3] = *(int *)(iVar8 + 0x2c);
          piVar4[4] = iVar8 + 0x2c;
          *(int **)(*(int *)(iVar8 + 0x2c) + 4) = piVar4 + 3;
          *(int **)(iVar8 + 0x2c) = piVar4 + 3;
          iVar7 = iVar7 + -1;
        }
        else if (*(float *)((int)afStack_10 + *piVar6) < (float)piVar6[4]) {
          piVar2 = (int *)piVar6[2];
          if ((float)piVar6[5] < *(float *)((int)afStack_20 + *piVar6)) {
            aiStack_130[iVar7 + 1] = piVar6[3];
            iVar7 = iVar7 + 1;
          }
        }
        else if ((float)piVar6[5] < *(float *)((int)afStack_20 + *piVar6)) {
          piVar2 = (int *)piVar6[3];
        }
        else {
          piVar2 = (int *)aiStack_130[iVar7];
          iVar7 = iVar7 + -1;
        }
        piVar6 = piVar2;
      } while (-1 < iVar7);
    }
  }
  return param_1;
}

// FUN_0049B760 NONMATCHING

u64 FUN_0049b760(u64 param_1,int param_2)

{
  if (*(int *)(param_2 + iGpffffbb84) != 0) {
    ((code)FUN_0049c3d0)(*(int *)(param_2 + iGpffffbb84),param_1);
  }
  return param_1;
}

// FUN_0049B7A0 NONMATCHING

u64 FUN_0049b7a0(u64 param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = *(int **)((int)param_1 + 0x2c);
  while (piVar2 != (int *)((int)param_1 + 0x2c)) {
    piVar1 = (int *)*piVar2;
    *(int *)piVar2[1] = *piVar2;
    *(int *)(*piVar2 + 4) = piVar2[1];
    *(int *)piVar2[-2] = piVar2[-3];
    *(int *)(piVar2[-3] + 4) = piVar2[-2];
    (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + iGpffffbb88));
    piVar2 = piVar1;
  }
  return param_1;
}

// FUN_0049B850 NONMATCHING

u64 FUN_0049b850(u64 param_1,int param_2)

{
  int *piVar1;
  u8 bVar2;
  u8 bVar3;
  int iVar4;
  long lVar5;
  float *pfVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int aiStack_140 [64];
  u32 uStack_40;
  u32 uStack_3c;
  float afStack_38 [4];
  float afStack_28 [4];
  float afStack_18 [4];
  float fStack_8;
  float fStack_4;
  
  iVar9 = 0;
  iVar8 = 0;
  piVar7 = (int *)(param_2 + iGpffffbb78);
  iVar4 = ((code)FUN_004cb2f0)(*(u32 *)(param_2 + 4));
  iVar11 = 0;
  afStack_18[0] = *(float *)(iVar4 + 0x30);
  piVar10 = *(int **)(piVar7[3] + 0x1c);
  afStack_28[0] = *(float *)(param_2 + 0x118);
  afStack_28[1] = (float)*(u32 *)(param_2 + 0x11c);
  afStack_18[1] = (float)*(u32 *)(iVar4 + 0x34);
  afStack_18[2] = (float)*(u32 *)(iVar4 + 0x38);
  bVar2 = *(int *)((int)param_1 + 0xc) == 2;
  afStack_28[2] = (float)*(u32 *)(param_2 + 0x120);
  afStack_38[0] = *(float *)(param_2 + 0x10c);
  afStack_38[1] = (float)*(u32 *)(param_2 + 0x110);
  afStack_38[2] = (float)*(u32 *)(param_2 + 0x114);
  do {
    iVar4 = *piVar10;
    if (iVar4 < 0) {
      iVar4 = 0;
      pfVar6 = (float *)(param_2 + 0x94);
      do {
        fStack_4 = ((float)piVar10[(u32)*(u8 *)((int)pfVar6 + 0x12) * 3 + 0x14] * pfVar6[2] +
                   (float)piVar10[(u32)*(u8 *)(pfVar6 + 4) * 3 + 0x12] * *pfVar6 +
                   (float)piVar10[(u32)*(u8 *)((int)pfVar6 + 0x11) * 3 + 0x13] * pfVar6[1]) -
                   pfVar6[3];
        if (0 < (int)fStack_4) break;
        iVar4 = iVar4 + 1;
        pfVar6 = pfVar6 + 5;
      } while (iVar4 < 6);
      if (0 >= (int)fStack_4) {
        if (piVar7[1] <= iVar8) {
          iVar4 = (piVar7[1] + 0x32) * 4;
          if (*piVar7 == 0) {
            lVar5 = (*DAT_00960178)(iVar4,0x1030507);
          }
          else {
            lVar5 = (*DAT_00960180)(*piVar7,iVar4,0x1030507);
          }
          if (lVar5 == 0) {
            uStack_40 = 2;
            uStack_3c = ((code)FUN_004c1d10)(0xffffffff80000013,iVar4);
            ((code)FUN_004c1c50)(&uStack_40);
            piVar7[2] = iVar8;
            return param_1;
          }
          *piVar7 = (int)lVar5;
          piVar7[1] = piVar7[1] + 0x32;
        }
        iVar8 = iVar8 + 1;
        *(int **)(*piVar7 + iVar11) = piVar10;
        iVar11 = iVar11 + 4;
      }
      piVar10 = (int *)aiStack_140[iVar9];
      iVar9 = iVar9 + -1;
    }
    else {
      fStack_8 = *(float *)((int)afStack_28 + iVar4) - (float)piVar10[4];
      afStack_18[3] = (float)piVar10[5] - *(float *)((int)afStack_38 + iVar4);
      if (((int)fStack_8 < 0) && ((int)afStack_18[3] < 0)) {
        bVar3 = (float)piVar10[1] < *(float *)((int)afStack_18 + iVar4);
        if (((bVar2) && (bVar3)) || ((!bVar2 && (!bVar3)))) {
          piVar1 = piVar10 + 3;
          iVar9 = iVar9 + 1;
          piVar10 = (int *)piVar10[2];
          aiStack_140[iVar9] = *piVar1;
        }
        else {
          piVar1 = piVar10 + 2;
          iVar9 = iVar9 + 1;
          piVar10 = (int *)piVar10[3];
          aiStack_140[iVar9] = *piVar1;
        }
      }
      else if ((int)fStack_8 < 0) {
        piVar10 = (int *)piVar10[2];
      }
      else {
        piVar10 = (int *)piVar10[3];
      }
    }
    if (iVar9 < 0) {
      piVar7[2] = iVar8;
      return param_1;
    }
  } while( 1 );
}

#pragma optimization_level 3
// FUN_0049BBC0

u64 FUN_0049bbc0(u64 param_1,u64 param_2)

{
  FUN_0049c1e0_wide(param_2,param_1);
  return param_1;
}
#pragma optimization_level 2

#pragma optimization_level 3
// FUN_0049BBF0

u64 FUN_0049bbf0(u64 param_1,u64 param_2)

{
  FUN_0049c3d0_wide(param_2,param_1);
  return param_1;
}
#pragma optimization_level 2

#pragma optimization_level 3
// FUN_0049BC20

u64 FUN_0049bc20(u64 param_1,u64 param_2)

{
  FUN_0049c160_wide(param_2,param_1);
  return param_1;
}
#pragma optimization_level 2
// FUN_0049BC50
#pragma schedule on
#pragma tailcall on
u32 FUN_0049bc50(u32 param_1,u32 param_2,u32 param_3)
{
  char *base;

  base = (char *)param_3;
  FUN_00495fb0_u32(*(u32 **)(param_3 + 0x54),base,param_1,(u32)base + 0x20);
  return;
}
#pragma tailcall off
#pragma schedule off

// FUN_0049BC70 NONMATCHING
#pragma schedule on
u32 FUN_0049bc70(u32 param_1,u32 param_2,u32 param_3)
{
  u32 result;
  u32 base;

  base = param_3;
  result = (u32)FUN_00496230_u32(param_1,base,base + 0x20);
  *(u32 *)(param_3 + 0x54) = result;
  if (result == 0) {
    param_1 = 0;
  }
  return param_1;
}
#pragma schedule off

// FUN_0049BCC0
#pragma schedule on
#pragma tailcall on
void FUN_0049bcc0(int param_1)
{
  FUN_004964f0(*(u32 *)(param_1 + 0x54),(char *)param_1);
  return;
}
#pragma tailcall off
#pragma schedule off

// FUN_0049BCD0
#pragma schedule on
#pragma tailcall on
u64 FUN_0049bcd0(u64 param_1,u64 param_2,u64 param_3)
{
  return FUN_0049e830(param_1,param_3);
}
#pragma tailcall off
#pragma schedule off

// FUN_0049BCE0 NONMATCHING
#pragma schedule on
u64 FUN_0049bce0(u64 param_1,u64 param_2,u64 param_3)
{
  u64 result;
  u64 condition;

  result = param_1;
  condition = FUN_0049e9f0(param_1,param_3);
  result = condition != 0 ? result : 0;
  return result;
}
#pragma schedule off

// FUN_0049BD10
#pragma tailcall on
int FUN_0049bd10(int param_1)
{
  return FUN_0049ecd0(param_1);
}
#pragma tailcall off

// FUN_0049BD20
#pragma schedule on
#pragma tailcall on
u64 FUN_0049bd20(u64 param_1,u64 param_2,u64 param_3)
{
  return FUN_0049ee70(param_1,param_3);
}
#pragma tailcall off
#pragma schedule off

// FUN_0049BD30 NONMATCHING
#pragma schedule on
u64 FUN_0049bd30(u64 param_1,u64 param_2,u64 param_3)
{
  u64 result;
  u64 condition;

  result = param_1;
  condition = FUN_0049f040(param_1,param_3);
  result = condition != 0 ? result : 0;
  return result;
}
#pragma schedule off

// FUN_0049BD60
#pragma tailcall on
int FUN_0049bd60(int param_1)
{
  return FUN_0049f340(param_1);
}
#pragma tailcall off

// FUN_0049BD70 NONMATCHING
#pragma schedule on
void FUN_0049bd70(u32 param_1,u32 param_2,u32 param_3)
{
  u32 result;
  char *base;

  result = FUN_0049a170(param_3);
  base = (char *)result;
  FUN_00495fb0_u32(*(u32 **)(param_3 + 0x78),base,param_1,(u32)base + 0x10);
  return;
}
#pragma schedule off



// FUN_0049BDC0 NONMATCHING

u64 FUN_0049bdc0(u64 param_1,u64 param_2,u64 param_3)

{
  u32 uVar1;
  u64 uVar2;
  
  uVar2 = ((code)FUN_0049a170)(param_3);
  uVar1 = ((code)FUN_00496230)(param_1,uVar2,(int)uVar2 + 0x10);
  *(u32 *)((int)param_3 + 0x78) = uVar1;
  if (*(int *)((int)param_3 + 0x78) == 0) {
    param_1 = 0;
  }
  return param_1;
}

// FUN_0049BE20 NONMATCHING

void FUN_0049be20(int param_1)

{
  u64 uVar1;
  
  uVar1 = ((code)FUN_0049a170)();
  ((code)FUN_004964f0)(*(u32 *)(param_1 + 0x78),uVar1);
  return;
}

// FUN_0049BE50 NONMATCHING

u8 FUN_0049be50(void)

{
  u8 bVar1;
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
  u32 uVar12;
  u32 uVar13;
  u32 uVar14;
  u32 uVar15;
  u32 uVar16;
  u32 uVar17;
  u32 uVar18;
  u32 uVar19;
  u32 uVar20;
  u32 uVar21;
  u32 uVar22;
  long lVar23;
  
  uVar2 = ((code)FUN_004ca520)(0xc,0x509,0x49aaf0,0x49abf0);
  uVar3 = ((code)FUN_004ca000)(0x1c,0x509,0x49ad80,0x49ae30,0x49ade0);
  uGpffffbb78 = (u32)uVar3;
  uVar4 = ((code)FUN_00492c30)(8,0x509,0x49b290,0x49b2e0,0x49b2d0);
  uGpffffbb7c = (u32)uVar4;
  uVar5 = ((code)FUN_00492c60)(8,0x509,0x49b3c0,0x49b430,0x49b3f0);
  uGpffffbb80 = (u32)uVar5;
  uVar6 = ((code)FUN_00494520)(8,0x509,0x49b730,0x49b7a0,0x49b760);
  uGpffffbb84 = (u32)uVar6;
  uVar7 = ((code)FUN_00493c50)(0,0x50e,0,0,0);
  uVar8 = ((code)FUN_00499250)(0,0x50e,0,0,0);
  uVar9 = ((code)FUN_00493c80)(0x50e,0x49bc70,0x49bc50,0x49bcc0);
  uVar10 = ((code)FUN_00499280)(0x50e,0x49bdc0,0x49bd70,0x49be20);
  uVar11 = ((code)FUN_00493c50)(0,0x510,0,0,0);
  uVar12 = ((code)FUN_00499250)(0,0x510,0,0,0);
  uVar13 = ((code)FUN_00493c80)(0x510,0x49bce0,0x49bcd0,0x49bd10);
  uVar14 = ((code)FUN_00499280)(0x510,0x49bd30,0x49bd20,0x49bd60);
  uVar15 = ((code)FUN_00492c30)(0,0x1f,0,0,0);
  uVar16 = ((code)FUN_00492c90)(0x1f,0x4906f0,0x490770,0x4907e0);
  uVar17 = ((code)FUN_0049a920)(0,0x1f,0,0,0);
  uVar18 = ((code)FUN_0049a950)(0x1f,0x48f340,0x48f3c0,0x48f430);
  uVar19 = ((code)FUN_00499250)(0,0x1f,0,0,0);
  uVar20 = ((code)FUN_00499280)(0x1f,0x48f460,0x48f4e0,0x48f550);
  uVar21 = ((code)FUN_00494db0)(0,0x1f,0,0,0);
  uVar22 = ((code)FUN_00494de0)(0x1f,0x4949c0,0x494a40,0x494ab0);
  if ((long)(uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7 | uVar8 | uVar9 | uVar10 | uVar11 |
             uVar12 | uVar13 | uVar14 | uVar15 | uVar16 | uVar17 | uVar18 | uVar19 | uVar20 | uVar21
            | uVar22) < 0) {
    bVar1 = 0;
  }
  else {
    lVar23 = ((code)FUN_0049c790)();
    bVar1 = lVar23 != 0;
  }
  return bVar1;
}

// FUN_0049C160 NONMATCHING

u64 FUN_0049c160(u64 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_2 + DAT_007ce868;
  if (*(int *)(param_2 + 4) != 0) {
    ((code)FUN_004cb270)();
  }
  *(int *)(iVar1 + 0xc) = (int)param_1;
  return param_1;
}

// FUN_0049C1B0 NONMATCHING

u64 FUN_0049c1b0(u64 param_1,int param_2)
{
  u8 *puVar1;
  
  puVar1 = (u8 *)param_2 + DAT_007ce868;
  if (*(int *)(puVar1 + 0xc) == 0) {
    param_1 = 0;
  }
  else {
    *(u32 *)(puVar1 + 0xc) = 0;
    *(u32 *)(puVar1 + 8) = 0;
  }
  return param_1;
}

// FUN_0049C1E0 NONMATCHING

u64 FUN_0049c1e0(u64 param_1,int param_2)

{
  u32 *puVar1;
  
  puVar1 = (u32 *)(param_2 + DAT_007ce86c);
  if (*(int *)(param_2 + 4) != 0) {
    ((code)FUN_004cb270)();
  }
  *puVar1 = (int)param_1;
  return param_1;
}


#pragma optimization_level 3
// FUN_0049C230
u32 FUN_0049c230(int param_1)
{
  return *(u32 *)(param_1 + DAT_007ce86c);
}
#pragma optimization_level 2

// FUN_0049C240 NONMATCHING

u64 FUN_0049c240(u64 param_1,u64 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = (int)param_1;
  iVar3 = (int)param_2;
  iVar1 = *(int *)(iVar3 + 4);
  piVar2 = (int *)(iVar3 + DAT_007ce870);
  *(u32 *)(iVar3 + 0x20) = *(u32 *)(iVar4 + 0x2c);
  *(int *)(iVar3 + 0x24) = iVar4 + 0x2c;
  *(int *)(*(int *)(iVar4 + 0x2c) + 4) = iVar3 + 0x20;
  *(int *)(iVar4 + 0x2c) = iVar3 + 0x20;
  *(int *)(iVar4 + 0x24) = *(int *)(iVar4 + 0x24) + 1;
  *piVar2 = iVar4;
  ((code)FUN_004916d0)(param_2,0x49bbc0,param_1);
  ((code)FUN_004917f0)(param_2,0x49bbf0,param_1);
  ((code)FUN_00491760)(param_2,0x49bc20,param_1);
  if (iVar1 != 0) {
    ((code)FUN_004c2d20)(iVar1 + 0x10,0);
    ((code)FUN_004cb270)(iVar1);
  }
  piVar2[1] = *(int *)((int)(u8 *)DAT_00960078 + DAT_007ce878);
  return param_1;
}

// FUN_0049C330 NONMATCHING

u64 FUN_0049c330(u64 param_1,code *param_2,u64 param_3)

{
  u32 *puVar1;
  long lVar2;
  int iVar3;
  
  puVar1 = (u32 *)((int)param_1 + DAT_007ce868);
  iVar3 = puVar1[2];
  puVar1 = (u32 *)*puVar1;
  while ((iVar3 != 0 && (lVar2 = (*param_2)(*puVar1,param_3), lVar2 != 0))) {
    iVar3 = iVar3 + -1;
    puVar1 = puVar1 + 1;
  }
  return param_1;
}

// FUN_0049C3D0 NONMATCHING

u64 FUN_0049c3d0(u64 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(int *)(param_2 + DAT_007ce874) = iVar1;
  if (*(u8 *)(param_2 + 1) < 0x80) {
    *(u32 *)(param_2 + 0x34) = *(u32 *)(iVar1 + 0x3c);
    *(int *)(param_2 + 0x38) = iVar1 + 0x3c;
    *(int *)(*(int *)(iVar1 + 0x3c) + 4) = param_2 + 0x34;
    *(int *)(iVar1 + 0x3c) = param_2 + 0x34;
  }
  else {
    if (*(int *)(param_2 + 4) != 0) {
      ((code)FUN_004cb270)();
    }
    *(u32 *)(param_2 + 0x34) = *(u32 *)(iVar1 + 0x34);
    *(int *)(param_2 + 0x38) = iVar1 + 0x34;
    *(int *)(*(int *)(iVar1 + 0x34) + 4) = param_2 + 0x34;
    *(int *)(iVar1 + 0x34) = param_2 + 0x34;
  }
  return param_1;
}

// FUN_0049C480 NONMATCHING

u64 FUN_0049c480(u64 param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  
  *(u32 *)(param_2 + DAT_007ce874) = 0;
  piVar2 = *(int **)(param_2 + 0x2c);
  while (piVar2 != (int *)(param_2 + 0x2c)) {
    piVar1 = (int *)*piVar2;
    *(int *)piVar2[1] = *piVar2;
    *(int *)(*piVar2 + 4) = piVar2[1];
    *(int *)piVar2[-2] = piVar2[-3];
    *(int *)(piVar2[-3] + 4) = piVar2[-2];
    (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960074 + DAT_007ce878));
    piVar2 = piVar1;
  }
  **(u32 **)(param_2 + 0x38) = *(u32 *)(param_2 + 0x34);
  *(u32 *)(*(int *)(param_2 + 0x34) + 4) = *(u32 *)(param_2 + 0x38);
  return param_1;
}

// FUN_0049C560 NONMATCHING

int FUN_0049c560(int param_1)

{
  if ((param_1 == 0) && (param_1 = *(int *)((int)(u8 *)DAT_009600c8 + DAT_007ceb28), param_1 == 0)) {
    param_1 = 0;
  }
  *(int *)((u8 *)DAT_009600b0 + DAT_007ceb28) = param_1;
  return param_1;
}

// FUN_0049C5C0 NONMATCHING

int FUN_0049c5c0(int param_1)

{
  if ((param_1 == 0) && (param_1 = *(int *)((u8 *)DAT_009600c4 + DAT_007ceb28), param_1 == 0)) {
    param_1 = 0;
  }
  *(int *)((u8 *)DAT_009600ac + DAT_007ceb28) = param_1;
  return param_1;
}

// FUN_0049C620 NONMATCHING

int FUN_0049c620(int param_1)

{
  if ((param_1 == 0) && (param_1 = *(int *)((int)(u8 *)DAT_009600cc + DAT_007ceb28), param_1 == 0)) {
    param_1 = 0;
  }
  *(int *)((u8 *)DAT_009600b4 + DAT_007ceb28) = param_1;
  return param_1;
}

// FUN_0049C680 NONMATCHING

void FUN_0049c680(void)

{
  ((code)FUN_0049c9b0)();
  ((code)FUN_004a5290)();
  ((code)FUN_004a5320)();
  ((code)FUN_004a5200)();
  return;
}

// FUN_0049C6C0 NONMATCHING

u8 FUN_0049c6c0(void)

{
  int iVar1;
  long lVar2;
  long lVar3;
  
  iVar1 = DAT_007ceb28;
  *(u32 *)((u8 *)DAT_009600ac + DAT_007ceb28) = 0;
  *(u32 *)((u8 *)DAT_009600b0 + iVar1) = 0;
  *(u32 *)((u8 *)DAT_009600b4 + iVar1) = 0;
  *(u32 *)((u8 *)DAT_009600b8 + iVar1) = 0;
  *(u32 *)((int)(u8 *)DAT_009600bc + iVar1) = 0;
  *(u32 *)((u8 *)DAT_009600c0 + iVar1) = 0;
  *(u32 *)((u8 *)DAT_009600c4 + iVar1) = 0;
  *(u32 *)((int)(u8 *)DAT_009600c8 + iVar1) = 0;
  *(u32 *)((int)(u8 *)DAT_009600cc + iVar1) = 0;
  lVar2 = ((code)FUN_004a5210)();
  lVar3 = 0;
  if (lVar2 != 0) {
    lVar3 = ((code)FUN_004a5330)();
  }
  lVar2 = 0;
  if (lVar3 != 0) {
    lVar2 = ((code)FUN_004a52a0)();
  }
  lVar3 = 0;
  if (lVar2 != 0) {
    lVar3 = ((code)FUN_0049c8c0)();
  }
  if (lVar3 == 0) {
    ((code)FUN_0049c9b0)();
    ((code)FUN_004a5290)();
    ((code)FUN_004a5320)();
    ((code)FUN_004a5200)();
  }
  return lVar3 != 0;
}

// FUN_0049C790
#pragma optimization_level 3

u32 FUN_0049c790(void)
{
  return 1;
}
#pragma optimization_level 2

// FUN_0049C7A0 NONMATCHING

u32 FUN_0049c7a0(u64 param_1,u32 *param_2)

{
  u16 *psVar1;
  u32 uVar2;
  
  psVar1 = (u16 *)*param_2;
  if (0 < *psVar1) {
    *(u32 *)(psVar1 + 0xc) = *(u32 *)(psVar1 + 2);
    if ((*(u32 *)(psVar1 + 6) & 1) == 0) {
      (*DAT_00960090)(1,0);
    }
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

// FUN_0049C810 NONMATCHING

long FUN_0049c810(void)

{
  long lVar1;
  long lVar2;
  u32 uStack_8;
  u32 uStack_4;
  
  lVar1 = ((code)FUN_004f2f70)();
  if (lVar1 != 0) {
    *(u32 *)((int)lVar1 + 0x2c) = 1;
    lVar2 = ((code)FUN_004f4640)(lVar1);
    if (((lVar2 != 0) && (lVar2 = ((code)FUN_004f4950)(lVar2,0,0x77de10,0), lVar2 != 0)) &&
       (lVar2 = ((code)FUN_004f3f80)(lVar2), lVar2 != 0)) {
      return lVar1;
    }
    ((code)FUN_004f3010)(lVar1);
  }
  uStack_8 = 2;
  uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000006,0x77de50);
  ((code)FUN_004c1c50)(&uStack_8);
  return 0;
}

// FUN_0049C8C0 NONMATCHING

u32 FUN_0049c8c0(void)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  u64 uVar4;
  u64 uVar5;
  u64 uVar6;
  u32 uVar7;
  
  uVar4 = ((code)FUN_0049c810)();
  uVar2 = ((code)FUN_0046a890)(4);
  uVar5 = ((code)FUN_0046a890)(6);
  uVar3 = ((code)FUN_0046a890)(5);
  uVar6 = ((code)FUN_0046a890)(7);
  iVar1 = DAT_007ceb20;
  *(int *)((int)(u8 *)DAT_0096008c + DAT_007ceb20) = (int)uVar4;
  uVar7 = (u32)uVar5;
  *(u32 *)((int)(u8 *)DAT_00960090 + iVar1) = uVar7;
  *(u32 *)((int)(u8 *)DAT_00960094 + iVar1) = uVar7;
  *(u32 *)((int)(u8 *)DAT_00960098 + iVar1) = uVar7;
  *(int *)((int)(u8 *)DAT_0096009c + iVar1) = (int)uVar6;
  *(int *)((int)(u8 *)DAT_009600a0 + iVar1) = (int)uVar6;
  *(u32 *)((u8 *)DAT_009600a8 + iVar1) = uVar2;
  *(u32 *)((u8 *)DAT_009600ac + iVar1) = uVar3;
  ((code)FUN_004f23c0)(uVar4);
  ((code)FUN_004f2430)(uVar5,3);
  ((code)FUN_004f2430)(uVar5,5);
  ((code)FUN_004f2430)(uVar5,4);
  ((code)FUN_004f2430)(uVar6,1);
  ((code)FUN_004f2430)(uVar6,2);
  return 1;
}

// FUN_0049C9B0 NONMATCHING

void FUN_0049c9b0(void)

{
  int iVar1;
  
  ((code)FUN_004f2430)(0,2);
  ((code)FUN_004f2430)(0,1);
  ((code)FUN_004f2430)(0,4);
  ((code)FUN_004f2430)(0,5);
  ((code)FUN_004f2430)(0,3);
  ((code)FUN_004f23c0)(0);
  iVar1 = DAT_007ceb20;
  *(u32 *)((u8 *)DAT_009600ac + DAT_007ceb20) = 0;
  *(u32 *)((u8 *)DAT_009600a8 + iVar1) = 0;
  *(u32 *)((int)(u8 *)DAT_009600a0 + iVar1) = 0;
  *(u32 *)((int)(u8 *)DAT_0096009c + iVar1) = 0;
  *(u32 *)((int)(u8 *)DAT_00960094 + iVar1) = 0;
  *(u32 *)((int)(u8 *)DAT_00960098 + iVar1) = 0;
  *(u32 *)((int)(u8 *)DAT_00960090 + iVar1) = 0;
  ((code)FUN_004f3010)(*(u32 *)((int)(u8 *)DAT_0096008c + iVar1));
  *(u32 *)((int)(u8 *)DAT_0096008c + DAT_007ceb20) = 0;
  return;
}

// FUN_0049CA50 NONMATCHING

void FUN_0049ca50(long param_1)

{
  DAT_007cea60 = DAT_007cea60 & 0xfffffffffffffe1f;
  if (param_1 == 6) {
    DAT_007cea60 = DAT_007cea60 | 0x160;
  }
  else if (param_1 == 5) {
    DAT_007cea60 = DAT_007cea60 | 0xc0;
  }
  else if (param_1 == 4) {
    DAT_007cea60 = DAT_007cea60 | 0x120;
  }
  else if (param_1 == 3) {
    DAT_007cea60 = DAT_007cea60 | 0x80;
  }
  else if (param_1 == 2) {
    DAT_007cea60 = DAT_007cea60 | 0x60;
  }
  return;
}

// FUN_0049CAB0 NONMATCHING






void FUN_0049cab0(float param_1,u8 *param_2)

{
  u32 *puVar1;
  u64 in_v1_udw;
  Vec128 auVar2;
  u64 in_a0_udw;
  Vec128 auVar3;
  Vec128 auVar4;
  Vec128 auVar5;
  
  puVar1 = (u32 *)(DAT_007ce9f4);
  auVar3._0_8_ = (long)(int)((float)param_2[3] * 0.0019700117);
  auVar3._8_8_ = in_a0_udw;
  auVar2._0_8_ = (long)(int)((float)param_2[1] * param_1);
  auVar2._8_8_ = in_v1_udw;
  auVar4 = _pexew(auVar3);
  auVar2 = _pexew(auVar2);
  auVar5._8_8_ = auVar4._8_8_;
  auVar5._0_8_ = (long)(int)((float)param_2[2] * param_1);
  auVar4._8_8_ = auVar2._8_8_;
  auVar4._0_8_ = (long)(int)((float)*param_2 * param_1);
  auVar2 = _ppacw(auVar5,auVar4);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar2 + 0));
  puVar1[1] = auVar2._4_4_;
  puVar1[2] = auVar2._8_4_;
  puVar1[3] = auVar2._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  return;
}
// FUN_0049CBD0 NONMATCHING

void FUN_0049cbd0(int param_1,float *param_2)

{
  u32 *puVar1;
  u64 in_v1_udw;
  Vec128 auVar2;
  u64 in_a0_udw;
  Vec128 auVar3;
  Vec128 auVar4;
  Vec128 auVar5;
  
  puVar1 = (u32 *)(DAT_007ce9f4);
  auVar3._0_8_ = (long)param_1;
  auVar3._8_8_ = in_a0_udw;
  auVar2._0_8_ = (long)(int)(param_2[1] * 255.00002);
  auVar2._8_8_ = in_v1_udw;
  auVar4 = _pexew(auVar3);
  auVar2 = _pexew(auVar2);
  auVar5._8_8_ = auVar4._8_8_;
  auVar5._0_8_ = (long)(int)(param_2[2] * 255.00002);
  auVar4._8_8_ = auVar2._8_8_;
  auVar4._0_8_ = (long)(int)(*param_2 * 255.00002);
  auVar2 = _ppacw(auVar5,auVar4);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar2 + 0));
  puVar1[1] = auVar2._4_4_;
  puVar1[2] = auVar2._8_4_;
  puVar1[3] = auVar2._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  return;
}

// FUN_0049CC30 NONMATCHING

void FUN_0049cc30(int param_1)
{
  if (*(int *)(param_1 + 0x18) == 0) {
    goto done;
  }
  FUN_004d4df0_typed();
  FUN_004d4df0_typed();
  goto done;
done:
  return;
}

// FUN_0049CC70 NONMATCHING

u32 FUN_0049cc70(int param_1)

{
  int iVar1;
  u8 bVar2;
  u32 uVar3;
  u8 *pbVar4;
  int iVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  int iVar9;
  int iVar10;
  u8 *pbVar11;
  int iVar12;
  u8 bVar13;
  
  uVar7 = *(u32 *)(param_1 + 0xb0);
  if (((uVar7 & 1) == 0) && ((uVar7 & 0xff) != 0)) {
    if ((uVar7 & 0xc) == 0) {
      *(u8 *)(param_1 + 0x1f0) = 4;
      *(u8 *)(param_1 + 0x1f1) = 0;
      *(u8 *)(param_1 + 0xb8) = 4;
      *(u8 *)(param_1 + 0xb9) = 0;
    }
    else {
      *(u8 *)(param_1 + 0x1f0) = 4;
      *(u8 *)(param_1 + 0x1f1) = 0;
      *(u8 *)(param_1 + 0xb8) = 4;
      *(u8 *)(param_1 + 0xb9) = 1;
    }
  }
  else {
    *(u8 *)(param_1 + 0x1f0) = 0xc;
    *(u8 *)(param_1 + 0x1f1) = 0;
    *(u8 *)(param_1 + 0xb8) = 4;
    *(u8 *)(param_1 + 0xb9) = 2;
  }
  *(u32 *)(param_1 + 0x70) = 0x68002001;
  uVar8 = 0;
  bVar2 = 1;
  *(u32 *)(param_1 + 0x78) = 0x6e002001;
  uVar7 = 0;
  iVar5 = param_1;
  do {
    uVar6 = *(u32 *)(iVar5 + 0x20);
    if (((uVar6 & 1) != 0) || ((uVar6 & 0x10) != 0)) {
      if (((uVar6 & 1) != 0) && ((uVar6 & 0x2000) == 0)) {
        bVar2 = 0;
      }
      uVar8 = uVar8 + 1 & 0xff;
    }
    uVar7 = uVar7 + 1;
    iVar5 = iVar5 + 8;
  } while (uVar7 < 10);
  *(u8 *)(param_1 + 0xb4) = bVar2;
  if (uVar8 == *(u8 *)(param_1 + 0xb6)) {
    uVar7 = 1;
    pbVar4 = (u8 *)(param_1 + 0x1f0);
    do {
      if (bVar2) {
        *(u32 *)(pbVar4 + 8) =
             (u32)*pbVar4 * ((*(int *)(pbVar4 + 4) / (int)uVar8) / (int)(u32)*pbVar4);
        iVar5 = *(int *)(pbVar4 + 8);
        if (iVar5 < (int)(u32)*pbVar4) {
          return 0;
        }
        *(int *)(pbVar4 + 0xc) =
             0xffff / ((iVar5 * 4 + 3 >> 2) * 2 + 5 + (iVar5 + 3 >> 2) + (iVar5 * 3 + 0xf >> 4));
        *(u32 *)(pbVar4 + 0x10) =
             (u32)*pbVar4 * ((*(int *)(pbVar4 + 4) / (int)(uVar8 + 2)) / (int)(u32)*pbVar4);
        iVar5 = *(int *)(pbVar4 + 0x10);
        *(int *)(pbVar4 + 0x14) =
             0xffff / (((iVar5 * 4 + 3 >> 2) + (iVar5 * 3 + 0xf >> 4)) * 2 + 7 + (iVar5 + 3 >> 2) +
                      ((iVar5 + 1) * 3 >> 2));
      }
      else {
        *(u32 *)(pbVar4 + 8) = *(int *)(pbVar4 + 4) / (int)uVar8 - (u32)pbVar4[1];
        *(u32 *)(pbVar4 + 8) =
             (u32)pbVar4[1] + (u32)*pbVar4 * (*(int *)(pbVar4 + 8) / (int)(u32)*pbVar4);
        if (*(int *)(pbVar4 + 8) < (int)((u32)*pbVar4 + (u32)pbVar4[1])) {
          return 0;
        }
        pbVar4[0xc] = 1;
        pbVar4[0xd] = 0;
        pbVar4[0xe] = 0;
        pbVar4[0xf] = 0;
        *(u32 *)(pbVar4 + 0x10) = *(int *)(pbVar4 + 4) / (int)(uVar8 + 2) - (u32)pbVar4[1];
        *(u32 *)(pbVar4 + 0x10) =
             (u32)pbVar4[1] + (u32)*pbVar4 * (*(int *)(pbVar4 + 0x10) / (int)(u32)*pbVar4);
        pbVar4[0x14] = 1;
        pbVar4[0x15] = 0;
        pbVar4[0x16] = 0;
        pbVar4[0x17] = 0;
      }
      iVar5 = 2;
      if (bVar2) {
        iVar5 = 1;
      }
      uVar6 = 0;
      iVar9 = param_1;
      do {
        if ((*(u32 *)(iVar9 + 0x20) & 1) != 0) {
          if ((*(u32 *)(iVar9 + 0x20) & 0x2000) == 0) {
            iVar5 = iVar5 + 2;
          }
          else {
            switch(uVar6) {
            case 0:
              iVar5 = iVar5 + ((*(int *)(pbVar4 + 8) + 1) * 3 >> 2);
              break;
            case 1:
              iVar5 = iVar5 + *(int *)(pbVar4 + 8);
              break;
            case 2:
              iVar5 = iVar5 + (*(int *)(pbVar4 + 8) * 2 + 3 >> 2);
              break;
            case 3:
              iVar5 = iVar5 + *(int *)(pbVar4 + 8);
              break;
            case 4:
              iVar5 = iVar5 + (*(int *)(pbVar4 + 8) + 3 >> 2);
              break;
            case 5:
              iVar5 = iVar5 + (*(int *)(pbVar4 + 8) * 3 + 0xf >> 4);
            }
            iVar5 = iVar5 + 1;
          }
        }
        uVar6 = uVar6 + 1;
        iVar9 = iVar9 + 8;
      } while (uVar6 < 10);
      iVar10 = 0;
      bVar13 = 0;
      uVar6 = 0;
      iVar12 = (u32)*(u8 *)(param_1 + 0xb5) * 2 + 1;
      pbVar11 = pbVar4;
      iVar9 = param_1;
      do {
        if ((*(u32 *)(iVar9 + 0x20) & 1) == 0) {
          if ((*(u32 *)(iVar9 + 0x20) & 0x10) != 0) {
            pbVar11[0x2e] = bVar13;
            bVar13 = bVar13 + 1;
            pbVar11[0x18] = 0;
            pbVar11[0x19] = 0;
            pbVar11[0x1a] = 0;
            pbVar11[0x1b] = 0;
            pbVar11[0x20] = 0;
            pbVar11[0x21] = 0;
            pbVar11[0x22] = 0;
            pbVar11[0x23] = 0;
            pbVar11[0x28] = 0;
            pbVar11[0x29] = 0;
            pbVar11[0x2c] = 0;
            pbVar11[0x2d] = 0;
          }
        }
        else {
          pbVar11[0x2e] = bVar13;
          if ((*(u32 *)(iVar9 + 0x20) & 0x2000) == 0) {
            pbVar11[0x18] = 0;
            pbVar11[0x19] = 0;
            pbVar11[0x1a] = 0;
            pbVar11[0x1b] = 0;
            pbVar11[0x20] = 0;
            pbVar11[0x21] = 0;
            pbVar11[0x22] = 0;
            pbVar11[0x23] = 0;
            bVar13 = bVar13 + 1;
            pbVar11[0x28] = 0;
            pbVar11[0x29] = 0;
            pbVar11[0x2c] = 0;
            pbVar11[0x2d] = 0;
          }
          else {
            iVar1 = *(int *)(pbVar4 + 8);
            iVar12 = iVar12 + iVar10 + 1;
            bVar13 = bVar13 + 1;
            *(int *)(pbVar11 + 0x18) = iVar1;
            *(int *)(pbVar11 + 0x20) = iVar12;
            *(short *)(pbVar11 + 0x28) = (short)iVar5;
            pbVar11[0x2c] = 0;
            pbVar11[0x2d] = 0;
            switch(uVar6) {
            case 0:
              iVar10 = (iVar1 + 1) * 3 >> 2;
              break;
            case 1:
              iVar10 = iVar1;
              break;
            case 2:
              iVar10 = iVar1 * 2 + 3 >> 2;
              break;
            case 3:
              iVar10 = iVar1;
              break;
            case 4:
              iVar10 = iVar1 + 3 >> 2;
              break;
            case 5:
              iVar10 = iVar1 * 3 + 0xf >> 4;
            }
          }
        }
        uVar6 = uVar6 + 1;
        iVar9 = iVar9 + 8;
        pbVar11 = pbVar11 + 0x18;
      } while (uVar6 < 10);
      iVar5 = 2;
      if (bVar2) {
        iVar5 = 1;
      }
      uVar6 = 0;
      iVar9 = param_1;
      do {
        if ((*(u32 *)(iVar9 + 0x20) & 1) != 0) {
          if ((*(u32 *)(iVar9 + 0x20) & 0x2000) == 0) {
            iVar5 = iVar5 + 2;
          }
          else {
            switch(uVar6) {
            case 0:
              iVar5 = iVar5 + ((*(int *)(pbVar4 + 0x10) + 1) * 3 >> 2);
              break;
            case 1:
              iVar5 = iVar5 + *(int *)(pbVar4 + 0x10);
              break;
            case 2:
              iVar5 = iVar5 + (*(int *)(pbVar4 + 0x10) * 2 + 3 >> 2);
              break;
            case 3:
              iVar5 = iVar5 + *(int *)(pbVar4 + 0x10);
              break;
            case 4:
              iVar5 = iVar5 + (*(int *)(pbVar4 + 0x10) + 3 >> 2);
              break;
            case 5:
              iVar5 = iVar5 + (*(int *)(pbVar4 + 0x10) * 3 + 0xf >> 4);
              break;
            case 10:
              iVar5 = iVar5 + ((*(int *)(pbVar4 + 0x10) + 1) * 3 >> 2);
              break;
            case 0xb:
              iVar5 = iVar5 + (*(int *)(pbVar4 + 0x10) * 3 + 0xf >> 4);
            }
            iVar5 = iVar5 + 1;
          }
        }
        uVar6 = uVar6 + 1;
        iVar9 = iVar9 + 8;
      } while (uVar6 < 0xc);
      iVar10 = 0;
      bVar13 = 0;
      uVar6 = 0;
      iVar12 = (u32)*(u8 *)(param_1 + 0xb5) * 2 + 1;
      pbVar11 = pbVar4;
      iVar9 = param_1;
      do {
        if ((*(u32 *)(iVar9 + 0x20) & 1) == 0) {
          if ((*(u32 *)(iVar9 + 0x20) & 0x10) != 0) {
            pbVar11[0x2e] = bVar13;
            bVar13 = bVar13 + 1;
            pbVar11[0x1c] = 0;
            pbVar11[0x1d] = 0;
            pbVar11[0x1e] = 0;
            pbVar11[0x1f] = 0;
            pbVar11[0x24] = 0;
            pbVar11[0x25] = 0;
            pbVar11[0x26] = 0;
            pbVar11[0x27] = 0;
            pbVar11[0x2a] = 0;
            pbVar11[0x2b] = 0;
            pbVar11[0x2c] = 0;
            pbVar11[0x2d] = 0;
          }
        }
        else {
          pbVar11[0x2e] = bVar13;
          if ((*(u32 *)(iVar9 + 0x20) & 0x2000) == 0) {
            pbVar11[0x1c] = 0;
            pbVar11[0x1d] = 0;
            pbVar11[0x1e] = 0;
            pbVar11[0x1f] = 0;
            pbVar11[0x24] = 0;
            pbVar11[0x25] = 0;
            pbVar11[0x26] = 0;
            pbVar11[0x27] = 0;
            bVar13 = bVar13 + 1;
            pbVar11[0x2a] = 0;
            pbVar11[0x2b] = 0;
            pbVar11[0x2c] = 0;
            pbVar11[0x2d] = 0;
          }
          else {
            iVar1 = *(int *)(pbVar4 + 0x10);
            iVar12 = iVar12 + iVar10 + 1;
            bVar13 = bVar13 + 1;
            *(int *)(pbVar11 + 0x1c) = iVar1;
            *(int *)(pbVar11 + 0x24) = iVar12;
            *(short *)(pbVar11 + 0x2a) = (short)iVar5;
            pbVar11[0x2c] = 0;
            pbVar11[0x2d] = 0;
            switch(uVar6) {
            case 0:
              iVar10 = (iVar1 + 1) * 3 >> 2;
              break;
            case 1:
              iVar10 = iVar1;
              break;
            case 2:
              iVar10 = iVar1 * 2 + 3 >> 2;
              break;
            case 3:
              iVar10 = iVar1;
              break;
            case 4:
              iVar10 = iVar1 + 3 >> 2;
              break;
            case 5:
              iVar10 = iVar1 * 3 + 0xf >> 4;
              break;
            case 10:
              iVar10 = (iVar1 + 1) * 3 >> 2;
              break;
            case 0xb:
              iVar10 = iVar1 * 3 + 0xf >> 4;
            }
          }
        }
        uVar6 = uVar6 + 1;
        iVar9 = iVar9 + 8;
        pbVar11 = pbVar11 + 0x18;
      } while (uVar6 < 0xc);
      uVar7 = uVar7 + 1;
      pbVar4 = (u8 *)(param_1 + 0xb8);
    } while (uVar7 < 3);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

// FUN_0049D4D0 NONMATCHING

int FUN_0049d4d0(int param_1,int param_2,int *param_3,int *param_4,int *param_5,int *param_6)

{
  int iVar1;
  u8 bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  short sVar6;
  int *piVar7;
  u32 uVar8;
  int iVar9;
  u32 uVar10;
  short sVar11;
  u32 uVar12;
  int iVar13;
  int iVar14;
  u32 uVar15;
  u16 uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  u32 uVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  int iStack_10;
  
  iVar18 = *(int *)(param_1 + 4);
  if (((**(u32 **)(param_1 + 0xc) & 1) == 0) && ((**(u32 **)(param_1 + 0xc) & 8) == 0)) {
    iVar5 = iVar18 + 0x1f0;
  }
  else {
    iVar5 = iVar18 + 0xb8;
  }
  iStack_10 = *(int *)(iVar5 + 0xc);
  iVar17 = *(int *)(iVar5 + 8);
  if (*(int *)(param_1 + 0x24) != 0) {
    iStack_10 = *(int *)(iVar5 + 0x14);
    iVar17 = *(int *)(iVar5 + 0x10);
  }
  bVar2 = *(u8 *)(iVar5 + 1);
  iVar1 = (int)((u32)bVar2 * -2 + -1 + iVar17 + param_2) / (int)(iVar17 - (u32)bVar2);
  iVar9 = param_2 + (u32)bVar2 * (iVar1 + -1);
  uVar12 = 0;
  piVar7 = param_3;
  if (*(int *)(param_1 + 0x24) == -10) {
    cVar3 = *(char *)(iVar18 + 0xb4);
  }
  else {
    do {
      iVar23 = *(int *)(iVar5 + 0x1c);
      uVar12 = uVar12 + 1;
      iVar21 = *(int *)(iVar5 + 0x20);
      iVar22 = *(int *)(iVar5 + 0x24);
      *piVar7 = *(int *)(iVar5 + 0x18);
      piVar7[1] = iVar23;
      piVar7[2] = iVar21;
      piVar7[3] = iVar22;
      iVar21 = *(int *)(iVar5 + 0x2c);
      piVar7[4] = *(int *)(iVar5 + 0x28);
      piVar7[5] = iVar21;
      iVar5 = iVar5 + 0x18;
      piVar7 = piVar7 + 6;
    } while (uVar12 < *(int *)(param_1 + 0x24) + 10U);
    cVar3 = *(char *)(iVar18 + 0xb4);
  }
  if (cVar3 == '\0') {
    iVar13 = iVar1 + -1;
    iVar14 = 0;
    iVar9 = iVar9 - iVar17 * iVar13;
    iVar21 = iVar1 * (*(u8 *)(iVar18 + 0xb5) + 1) * 2;
    uVar10 = (iVar17 + 1U) * 3 >> 2;
    iVar5 = 0;
    uVar15 = 0;
    iVar23 = (iVar9 + 1) * 3 >> 2;
    uVar20 = iVar17 + 3U >> 2;
    iVar19 = iVar9 * 3 + 0xf >> 4;
    uVar8 = iVar17 + 1U >> 1;
    uVar12 = iVar17 * 3 + 0xfU >> 4;
    iVar22 = iVar18;
    piVar7 = param_3;
    do {
      if ((*(u32 *)(iVar22 + 0x20) & 1) != 0) {
        if ((*(u32 *)(iVar22 + 0x20) & 0x2000) == 0) {
          iVar4 = *(int *)(iVar22 + 0x24);
          *piVar7 = param_2;
          piVar7[1] = param_2;
          *(u16 *)(piVar7 + 5) = 0;
          iVar5 = iVar5 + (param_2 * iVar4 + 3U >> 2);
        }
        else {
          uVar16 = (u16)iVar14;
          switch(uVar15) {
          case 0:
            iVar21 = param_3[2];
            sVar11 = (short)param_3[4];
            if (*(int *)(param_1 + 0x24) != 0) {
              sVar11 = *(short *)((int)param_3 + 0x12);
              iVar21 = param_3[3];
            }
            *(u16 *)(param_3 + 5) = uVar16;
            iVar14 = iVar14 + (uVar10 - iVar23);
            iVar21 = uVar10 + iVar21 + sVar11 * iVar13 + 1;
            break;
          case 1:
            iVar21 = param_3[8];
            sVar11 = (short)param_3[10];
            if (*(int *)(param_1 + 0x24) != 0) {
              sVar11 = *(short *)((int)param_3 + 0x2a);
              iVar21 = param_3[9];
            }
            *(u16 *)(param_3 + 0xb) = uVar16;
            iVar14 = iVar14 + (iVar17 - iVar9);
            iVar21 = iVar17 + iVar21 + sVar11 * iVar13 + 1;
            break;
          case 2:
            iVar21 = param_3[0xe];
            sVar11 = (short)param_3[0x10];
            if (*(int *)(param_1 + 0x24) != 0) {
              sVar11 = *(short *)((int)param_3 + 0x42);
              iVar21 = param_3[0xf];
            }
            *(u16 *)(param_3 + 0x11) = uVar16;
            iVar14 = iVar14 + (uVar8 - (iVar9 + 1 >> 1));
            iVar21 = uVar8 + iVar21 + sVar11 * iVar13 + 1;
            break;
          case 3:
            iVar21 = param_3[0x14];
            sVar11 = (short)param_3[0x16];
            if (*(int *)(param_1 + 0x24) != 0) {
              sVar11 = *(short *)((int)param_3 + 0x5a);
              iVar21 = param_3[0x15];
            }
            *(u16 *)(param_3 + 0x17) = uVar16;
            iVar14 = iVar14 + (iVar17 - iVar9);
            iVar21 = iVar17 + iVar21 + sVar11 * iVar13 + 1;
            break;
          case 4:
            iVar21 = param_3[0x1a];
            sVar11 = (short)param_3[0x1c];
            if (*(int *)(param_1 + 0x24) != 0) {
              sVar11 = *(short *)((int)param_3 + 0x72);
              iVar21 = param_3[0x1b];
            }
            *(u16 *)(param_3 + 0x1d) = uVar16;
            iVar21 = uVar20 + iVar21 + sVar11 * iVar13 + 1;
            iVar14 = iVar14 + (uVar20 - (iVar9 + 3 >> 2));
            break;
          case 5:
            iVar21 = param_3[0x20];
            sVar11 = (short)param_3[0x22];
            if (*(int *)(param_1 + 0x24) != 0) {
              sVar11 = *(short *)((int)param_3 + 0x8a);
              iVar21 = param_3[0x21];
            }
            *(u16 *)(param_3 + 0x23) = uVar16;
            iVar21 = uVar12 + iVar21 + sVar11 * iVar13 + 1;
            iVar14 = iVar14 + (uVar12 - iVar19);
          }
        }
      }
      uVar15 = uVar15 + 1;
      iVar22 = iVar22 + 8;
      piVar7 = piVar7 + 6;
    } while (uVar15 < 10);
    if (*(int *)(param_1 + 0x24) != 0) {
      *(short *)(param_3 + 0x41) = (short)iVar14;
      iVar14 = iVar14 + (uVar10 - iVar23);
      *(short *)(param_3 + 0x47) = (short)iVar14;
      iVar14 = iVar14 + (uVar12 - iVar19);
      iVar21 = uVar12 + param_3[0x45] + (int)*(short *)((int)param_3 + 0x11a) * (iVar1 + -1) + 1;
    }
    iVar9 = *(int *)(param_1 + 0x24);
    iVar21 = iVar21 - iVar14;
    uVar12 = 0;
    iVar5 = iVar5 + iVar21;
    if (iVar9 != -10) {
      do {
        if (((*(u32 *)(iVar18 + 0x20) & 1) != 0) && ((*(u32 *)(iVar18 + 0x20) & 0x2000) == 0)) {
          if (iVar9 == 0) {
            param_3[2] = iVar21;
          }
          else {
            param_3[3] = iVar21;
          }
          iVar21 = iVar21 + (param_2 * *(int *)(iVar18 + 0x24) + 3U >> 2);
        }
        iVar9 = *(int *)(param_1 + 0x24);
        uVar12 = uVar12 + 1;
        iVar18 = iVar18 + 8;
        param_3 = param_3 + 6;
      } while (uVar12 < iVar9 + 10U);
    }
  }
  else {
    iVar5 = 1;
    iVar18 = iVar17 * iVar1 - iVar9;
    if ((short)param_3[4] == 0) {
      uVar12 = 0;
    }
    else {
      iVar5 = 2;
      uVar12 = (u32)((iVar9 + 1) * 3) >> 2;
    }
    *(u16 *)(param_3 + 5) = 0;
    if ((short)param_3[4] == 0) {
      sVar11 = 0;
    }
    else {
      sVar11 = (short)(iVar18 * 3 >> 2);
    }
    if ((short)param_3[10] == 0) {
      iVar21 = 0;
    }
    else {
      iVar5 = iVar5 + 1;
      iVar21 = iVar9;
    }
    *(short *)(param_3 + 0xb) = sVar11;
    iVar22 = iVar18;
    if ((short)param_3[10] == 0) {
      iVar22 = 0;
    }
    sVar11 = sVar11 + (short)iVar22;
    if ((short)param_3[0x10] == 0) {
      uVar8 = 0;
    }
    else {
      iVar5 = iVar5 + 1;
      uVar8 = iVar9 * 2 + 3U >> 2;
    }
    *(short *)(param_3 + 0x11) = sVar11;
    if ((short)param_3[0x10] == 0) {
      sVar6 = 0;
    }
    else {
      sVar6 = (short)(iVar18 >> 1);
    }
    sVar11 = sVar11 + sVar6;
    if ((short)param_3[0x16] == 0) {
      iVar22 = 0;
    }
    else {
      iVar5 = iVar5 + 1;
      iVar22 = iVar9;
    }
    *(short *)(param_3 + 0x17) = sVar11;
    iVar23 = iVar18;
    if ((short)param_3[0x16] == 0) {
      iVar23 = 0;
    }
    sVar11 = sVar11 + (short)iVar23;
    if ((short)param_3[0x1c] == 0) {
      uVar10 = 0;
    }
    else {
      iVar5 = iVar5 + 1;
      uVar10 = iVar9 + 3U >> 2;
    }
    *(short *)(param_3 + 0x1d) = sVar11;
    if ((short)param_3[0x1c] == 0) {
      sVar6 = 0;
    }
    else {
      sVar6 = (short)(iVar18 >> 2);
    }
    sVar11 = sVar11 + sVar6;
    if ((short)param_3[0x22] == 0) {
      iVar23 = 0;
    }
    else {
      iVar5 = iVar5 + 1;
      iVar23 = (iVar1 + -1) * (iVar17 * 3 + 0xfU >> 4) +
               ((iVar9 - iVar17 * (iVar1 + -1)) * 3 + 0xfU >> 4);
    }
    iVar23 = uVar12 + iVar21 + uVar8 + iVar22 + uVar10 + iVar23;
    *(short *)(param_3 + 0x23) = sVar11;
    if (*(int *)(param_1 + 0x24) != 0) {
      if ((short)param_3[0x22] == 0) {
        sVar6 = 0;
      }
      else {
        sVar6 = (short)(iVar17 * 3 + 0xfU >> 4) -
                (short)((iVar9 - iVar17 * (iVar1 + -1)) * 3 + 0xfU >> 4);
      }
      sVar11 = sVar11 + sVar6;
      iVar5 = iVar5 + 2;
      *(short *)(param_3 + 0x41) = sVar11;
      *(short *)(param_3 + 0x47) = sVar11 + (short)(iVar18 * 3 >> 2);
      iVar23 = iVar23 + ((u32)((iVar9 + 1) * 3) >> 2) +
               (iVar1 + -1) * (iVar17 * 3 + 0xfU >> 4) +
               ((iVar9 - iVar17 * (iVar1 + -1)) * 3 + 0xfU >> 4);
    }
    iVar5 = iVar23 + iVar5 * iVar1 + ((iVar1 + iStack_10 + -1) / iStack_10) * 9;
  }
  *param_4 = iVar17;
  *param_5 = iStack_10;
  *param_6 = iVar1;
  return iVar5 * 0x10 + 0x22f;
}

// FUN_0049DC70 NONMATCHING

u64 FUN_0049dc70(int param_1)

{
  int iVar1;
  int iVar2;
  Vec128 auVar3;
  Vec128 auVar4;
  Vec128 auVar5;
  Vec128 auVar6;
  Vec128 auVar7;
  Vec128 auVar8;
  Vec128 auVar9;
  Vec128 auVar10;
  Vec128 auVar11;
  u8 bVar12;
  Vec128 auVar13;
  Vec128 auVar14;
  u32 uVar15;
  long lVar16;
  u32 uVar19;
  u8 in_v0_qw [16];
  u32 uVar20;
  Vec128 auVar17;
  Vec128 auVar18;
  u32 uVar21;
  int iVar22;
  long lVar23;
  Vec128 auVar24;
  Vec128 auVar25;
  u32 uVar26;
  int iVar27;
  Vec128 auVar28;
  Vec128 auVar29;
  Vec128 auVar30;
  int iVar31;
  u32 uVar32;
  u32 in_a2_udw;
  int iVar33;
  u32 uVar34;
  int iVar35;
  u32 uVar36;
  u32 uVar37;
  u32 *puVar38;
  Vec128 in_t4_qw;
  Vec128 auVar39;
  Vec128 auVar40;
  Vec128 auVar41;
  Vec128 auVar42;
  Vec128 auVar43;
  Vec128 auVar44;
  Vec128 auVar45;
  Vec128 auVar46;
  Vec128 in_t5_qw;
  Vec128 auVar47;
  Vec128 auVar48;
  Vec128 auVar49;
  int iVar50;
  int iVar51;
  u32 in_t7_udw;
  u32 in_register_000000fc;
  int iVar52;
  u32 uVar53;
  u32 uVar54;
  u32 in_s0_udw;
  u32 in_register_0000010c;
  long lVar55;
  long *plVar56;
  long *plVar57;
  long *plVar58;
  u32 in_s7_udw;
  u32 in_register_0000017c;
  u32 uVar59;
  u32 uVar60;
  u32 uVar62;
  u32 uVar63;
  Vec128 auVar61;
  u32 uVar64;
  u32 in_s8_udw;
  u32 in_register_000001ec;
  u32 uStack_180;
  int iStack_20;
  
  iVar1 = *(int *)(param_1 + 4);
  (*(u64*)((u8*)&auVar17 + 8)) = (*(u64*)((u8*)&in_v0_qw + 8));
  auVar61._8_8_ = 0;
  auVar61._0_8_ = auVar17._8_8_;
  iVar22 = **(int **)(param_1 + 0x30);
  auVar18._8_8_ = 0;
  auVar18._0_8_ = in_a2_udw;
  auVar61 = _pcpyld(auVar18 << 0x40,auVar61 << 0x40);
  plVar58 = *(long **)(iVar22 + 0x20);
  lVar23 = (long)*(int *)(iVar22 + 0x34);
  uVar15 = (u32)*(u8 *)(iVar1 + 0xb6);
  uVar19 = (*(u32*)((u8*)&in_v0_qw + 8));
  uVar20 = (*(u32*)((u8*)&in_v0_qw + 12));
  iStack_20 = *(int *)(iVar22 + 0x24);
  iVar2 = *(int *)(iVar22 + 0x38);
  if (((**(u32 **)(param_1 + 0xc) & 1) == 0) && ((**(u32 **)(param_1 + 0xc) & 8) == 0)) {
    uStack_180 = (u32)*(u8 *)(iVar1 + 0x1f1);
  }
  else {
    uStack_180 = (u32)*(u8 *)(iVar1 + 0xb9);
    iStack_20 = iStack_20 + uStack_180 * (*(int *)(iVar22 + 0x34) + -1);
  }
  bVar12 = 0;
  lVar55 = 0;
  plVar56 = plVar58;
  if ((0 < lVar23) && (0 < lVar23)) {
    iVar50 = 0;
    auVar25._8_8_ = 0;
    auVar25._0_8_ = auVar17._8_8_;
    uVar34 = (u32)uVar15 | 0x1000100;
    auVar17._0_8_ = 0x10000000;
    auVar18 = _pcpyld(auVar25 << 0x40,auVar17);
    lVar16 = 0x500000000000000;
    uVar26 = auVar17._8_8_;
    do {
      iVar27 = (int)lVar23 + -1;
      lVar23 = (long)iVar27;
      if (lVar55 < lVar23) {
        uVar59 = *(u32 *)(iVar22 + 0x30);
      }
      else {
        iVar27 = iVar27 * *(int *)(iVar22 + 0x30);
        lVar23 = (long)iVar27;
        uVar59 = iStack_20 - iVar27;
      }
      auVar29._8_8_ = uVar26;
      auVar29._0_8_ = lVar23;
      plVar57 = plVar58;
      if ((int)lVar55 % iVar2 == 0) {
        iVar27 = (int)plVar58 - (int)plVar56;
        if (iVar27 < 0) {
          iVar27 = iVar27 + 0xf;
        }
        auVar28._8_4_ = uVar19;
        auVar28._0_8_ = 0x1100000011000000;
        auVar28._12_4_ = uVar20;
        uVar32 = (iVar27 >> 4) - 1U | 0x10000000;
        if (lVar55 != 0) {
          auVar11._8_8_ = 0;
          auVar11._0_8_ = auVar28._8_8_;
          auVar28._0_8_ = auVar11._8_8_;
          auVar28._8_8_ = 0;
        }
        auVar3._8_8_ = in_a2_udw;
        auVar3._0_8_ = (long)(int)uVar32;
        auVar29 = _pcpyld(auVar28,auVar3);
        if ((*(char *)(iVar1 + 0xb4) == '\0') || (lVar55 == 0)) {
          *(int *)plVar56 = auVar29._0_4_;
          *(int *)((int)plVar56 + 4) = auVar29._4_4_;
          *(int *)(plVar56 + 1) = auVar29._8_4_;
          *(int *)((int)plVar56 + 0xc) = auVar29._12_4_;
          plVar57 = plVar58 + 2;
          plVar56 = plVar58;
        }
        else {
          *plVar56 = (long)(int)uVar32;
          bVar12 = 1;
          plVar56 = plVar58;
        }
      }
      iVar27 = *(int *)(param_1 + 0x24);
      auVar30._8_8_ = auVar29._8_8_;
      iVar31 = iVar27 + 10;
      iVar52 = 0;
      uVar26 = auVar17._8_8_;
      if (0 < iVar31) {
        (*(u64*)((u8*)&in_t5_qw + 0)) = (long)iVar1;
        (*(u64*)((u8*)&in_t4_qw + 0)) = (long)(iVar22 + 0x18);
        do {
          iVar31 = (*(u32*)((u8*)&in_t5_qw + 0));
          uVar32 = *(u32 *)(iVar31 + 0x20);
          iVar35 = (*(u32*)((u8*)&in_t4_qw + 0));
          if (((uVar32 & 1) != 0) && ((uVar32 & 0x2000) == 0)) {
            uVar32 = uVar32 & 0xff000000;
            if (uVar32 == 0x6c000000) {
LAB_0049df20:
              iVar51 = 4;
            }
            else if (uVar32 == 0x68000000) {
              iVar51 = 3;
            }
            else if ((uVar32 == 0x6d000000) || (uVar32 == 0x64000000)) {
              iVar51 = 2;
            }
            else {
              if (((uVar32 != 0x65000000) && (uVar32 != 0x6e000000)) && (uVar32 != 0x60000000))
              goto LAB_0049df20;
              iVar51 = 1;
            }
            iVar33 = *(int *)(iVar35 + 0x98);
            if (iVar27 != 0) {
              iVar33 = *(int *)(iVar35 + 0x9c);
            }
            uVar32 = uVar59 * iVar51 + 3;
            auVar24._0_8_ =
                 ((u32)(*(u32 *)(iVar31 + 0x20) & 0xff004000) | 0x8000 |
                  (long)(int)(u32)*(u8 *)(iVar35 + 0xa6) |
                 (long)(int)((uVar59 + (int)(((uVar32 & 0xfffffffc) - uVar59 * iVar51) + iVar51 + -1
                                            ) / iVar51) * 0x10000)) << 0x20 | 0x1000100 |
                 (u32)uVar15;
            auVar24._8_8_ = auVar17._8_8_;
            auVar4._8_8_ = in_a2_udw;
            auVar4._0_8_ = (long)(int)((int)uVar32 >> 2 | 0x30000000) |
                           (long)(*(int *)(iVar22 + 0x20) + iVar33 * 0x10) +
                           (u32)((*(int *)(iVar22 + 0x30) - uStack_180) * iVar51 * iVar50) << 0x20
            ;
            auVar25 = _pcpyld(auVar24,auVar4);
            *(int *)plVar56 = auVar25._0_4_;
            *(int *)((int)plVar56 + 4) = auVar25._4_4_;
            *(int *)(plVar56 + 1) = auVar25._8_4_;
            *(int *)((int)plVar56 + 0xc) = auVar25._12_4_;
            uVar26 = auVar18._8_8_;
            plVar56 = plVar57 + 2;
            *(int *)plVar57 = auVar18._0_4_;
            *(int *)((int)plVar57 + 4) = auVar18._4_4_;
            *(int *)(plVar57 + 1) = auVar18._8_4_;
            *(int *)((int)plVar57 + 0xc) = auVar18._12_4_;
            plVar57 = plVar57 + 4;
          }
          iVar27 = *(int *)(param_1 + 0x24);
          iVar52 = iVar52 + 1;
          (*(u64*)((u8*)&in_t5_qw + 0)) = (long)(iVar31 + 8);
          iVar31 = iVar27 + 10;
          (*(u64*)((u8*)&in_t4_qw + 0)) = (long)(iVar35 + 0x18);
        } while (iVar52 < iVar31);
      }
      uVar32 = 0;
      auVar46 = in_t4_qw;
      auVar49 = in_t5_qw;
      if (0 < iVar31) {
        uVar36 = uVar59 << 0x10;
        iVar31 = (int)((uVar59 + 1) * 3) >> 2;
        uVar21 = uVar59 * 3 + 0xf & 0xfffffff0;
        uVar37 = uVar36 | 0x6a008000 | uVar59 * (uVar15 + 1);
        (*(u64*)((u8*)&auVar14 + 4)) = (*(u64*)((u8*)&auVar17 + 8));
        auVar14._0_4_ = uVar37;
        auVar14._12_4_ = 0;
        auVar49._0_4_ = auVar14._4_4_;
        auVar49._4_4_ = auVar14._8_4_;
        auVar49._8_4_ = auVar14._12_4_;
        auVar49._12_4_ = 0;
        auVar46._8_4_ = uVar19;
        auVar46._0_8_ = 0x1000404;
        auVar46._12_4_ = uVar20;
        lVar23 = (long)(iVar22 + 0x18);
        iVar27 = iVar1;
        do {
          auVar49._0_8_ = (u32)*(int *)(iVar27 + 0x20);
          auVar45._8_8_ = auVar46._8_8_;
          auVar45._0_8_ = auVar49._0_8_ & 1;
          iVar52 = (int)lVar23;
          if (((auVar45._0_8_ != 0) && (auVar45._0_8_ = auVar49._0_8_ & 0x2000, auVar45._0_8_ != 0))
             && (uVar32 < 0xc)) {
            auVar49._0_8_ = (u32)(int)(uVar32 * 4);
            auVar45._0_8_ = (u32)(int)((u32 *)(switchdataD_007bca50))[uVar32];
            uVar60 = auVar61._0_4_;
            uVar62 = auVar61._4_4_;
            uVar63 = auVar61._8_4_;
            uVar64 = auVar61._12_4_;
            uVar53 = 0;
            uVar54 = 0x5000000;
            switch(uVar32) {
            case 0:
              lVar23 = lVar16;
              if (bVar12) {
                bVar12 = 0;
                lVar23 = *plVar57;
              }
              auVar39._8_8_ = auVar45._8_8_;
              auVar39._0_8_ = lVar23;
              plVar58 = plVar57 + iVar31 * 2;
              auVar49._0_8_ = (u32)(int)plVar58;
              auVar6._8_4_ = in_t7_udw;
              auVar6._0_8_ = uVar34 | (u32)(uVar36 | 0x68008000 | (u32)*(u8 *)(iVar52 + 0xa6))
                                      << 0x20;
              auVar6._12_4_ = in_register_000000fc;
              auVar45 = _pcpyld(auVar6,auVar39);
              *(int *)plVar57 = auVar45._0_4_;
              *(int *)((int)plVar57 + 4) = auVar45._4_4_;
              *(int *)(plVar57 + 1) = auVar45._8_4_;
              *(int *)((int)plVar57 + 0xc) = auVar45._12_4_;
              *(u32 *)plVar58 = uVar60;
              *(u32 *)((int)plVar58 + 4) = uVar62;
              *(u32 *)(plVar58 + 1) = uVar63;
              *(u32 *)((int)plVar58 + 0xc) = uVar64;
              plVar57 = plVar58 + 2;
              break;
            case 1:
              lVar23 = lVar16;
              if (bVar12) {
                bVar12 = 0;
                lVar23 = *plVar57;
              }
              auVar49._0_8_ = lVar23;
              plVar58 = plVar57 + uVar59 * 2;
              auVar40._0_8_ =
                   uVar34 | (u32)(uVar36 | 0x6c008000 | (u32)*(u8 *)(iVar52 + 0xa6)) << 0x20;
              auVar40._8_8_ = auVar45._8_8_;
              auVar45 = _pcpyld(auVar40,auVar49);
              *(int *)plVar57 = auVar45._0_4_;
              *(int *)((int)plVar57 + 4) = auVar45._4_4_;
              *(int *)(plVar57 + 1) = auVar45._8_4_;
              *(int *)((int)plVar57 + 0xc) = auVar45._12_4_;
              *(u32 *)plVar58 = uVar60;
              *(u32 *)((int)plVar58 + 4) = uVar62;
              *(u32 *)(plVar58 + 1) = uVar63;
              *(u32 *)((int)plVar58 + 0xc) = uVar64;
              plVar57 = plVar58 + 2;
              in_t7_udw = uVar19;
              in_register_000000fc = uVar20;
              break;
            case 2:
              if (bVar12) {
                uVar53 = (u32)*plVar57;
                uVar54 = (u32)((u32)*plVar57 >> 0x20);
                bVar12 = 0;
              }
              plVar58 = plVar57 + ((int)(uVar59 * 2 + 3) >> 2) * 2;
              auVar49._0_8_ = (u32)(int)plVar58;
              (*(u64*)((u8*)&auVar49 + 8)) = (*(u64*)((u8*)&in_t5_qw + 8));
              auVar41._0_8_ =
                   uVar34 | ((u32)(uVar36 | 0x64008000) | (u32)*(u8 *)(iVar52 + 0xa6)) << 0x20
              ;
              auVar41._8_8_ = auVar17._8_8_;
              auVar8._4_4_ = uVar54;
              auVar8._0_4_ = uVar53;
              auVar8._8_4_ = in_s0_udw;
              auVar8._12_4_ = in_register_0000010c;
              auVar45 = _pcpyld(auVar41,auVar8);
              *(int *)plVar57 = auVar45._0_4_;
              *(int *)((int)plVar57 + 4) = auVar45._4_4_;
              *(int *)(plVar57 + 1) = auVar45._8_4_;
              *(int *)((int)plVar57 + 0xc) = auVar45._12_4_;
              *(u32 *)plVar58 = uVar60;
              *(u32 *)((int)plVar58 + 4) = uVar62;
              *(u32 *)(plVar58 + 1) = uVar63;
              *(u32 *)((int)plVar58 + 0xc) = uVar64;
              plVar57 = plVar58 + 2;
              break;
            case 3:
              lVar23 = lVar16;
              if (bVar12) {
                bVar12 = 0;
                lVar23 = *plVar57;
              }
              auVar49._0_8_ = lVar23;
              plVar58 = plVar57 + ((int)(uVar59 * 4 + 3) >> 2) * 2;
              auVar42._0_8_ =
                   uVar34 | (u32)(uVar36 | 0x6c008000 | (u32)*(u8 *)(iVar52 + 0xa6)) << 0x20;
              auVar42._8_8_ = auVar45._8_8_;
              auVar45 = _pcpyld(auVar42,auVar49);
              *(int *)plVar57 = auVar45._0_4_;
              *(int *)((int)plVar57 + 4) = auVar45._4_4_;
              *(int *)(plVar57 + 1) = auVar45._8_4_;
              *(int *)((int)plVar57 + 0xc) = auVar45._12_4_;
              *(u32 *)plVar58 = uVar60;
              *(u32 *)((int)plVar58 + 4) = uVar62;
              *(u32 *)(plVar58 + 1) = uVar63;
              *(u32 *)((int)plVar58 + 0xc) = uVar64;
              plVar57 = plVar58 + 2;
              in_t7_udw = (*(u32*)((u8*)&in_t5_qw + 8));
              in_register_000000fc = (*(u32*)((u8*)&in_t5_qw + 12));
              break;
            case 4:
              if (bVar12) {
                uVar53 = (u32)*plVar57;
                uVar54 = (u32)((u32)*plVar57 >> 0x20);
                bVar12 = 0;
              }
              plVar58 = plVar57 + ((int)(uVar59 + 3) >> 2) * 2;
              auVar49._0_8_ = (u32)(int)plVar58;
              (*(u64*)((u8*)&auVar49 + 8)) = (*(u64*)((u8*)&in_t4_qw + 8));
              auVar43._0_8_ =
                   uVar34 | ((u32)(uVar36 | 0x6e00c000) | (u32)*(u8 *)(iVar52 + 0xa6)) << 0x20
              ;
              auVar43._8_8_ = auVar17._8_8_;
              auVar7._4_4_ = uVar54;
              auVar7._0_4_ = uVar53;
              auVar7._8_4_ = in_s0_udw;
              auVar7._12_4_ = in_register_0000010c;
              auVar45 = _pcpyld(auVar43,auVar7);
              *(int *)plVar57 = auVar45._0_4_;
              *(int *)((int)plVar57 + 4) = auVar45._4_4_;
              *(int *)(plVar57 + 1) = auVar45._8_4_;
              *(int *)((int)plVar57 + 0xc) = auVar45._12_4_;
              *(u32 *)plVar58 = uVar60;
              *(u32 *)((int)plVar58 + 4) = uVar62;
              *(u32 *)(plVar58 + 1) = uVar63;
              *(u32 *)((int)plVar58 + 0xc) = uVar64;
              plVar57 = plVar58 + 2;
              break;
            case 5:
              lVar23 = lVar16;
              if (bVar12) {
                bVar12 = 0;
                lVar23 = *plVar57;
              }
              auVar44._8_8_ = auVar45._8_8_;
              auVar44._0_8_ = lVar23;
              puVar38 = (u32 *)((int)plVar57 + uVar21);
              auVar49._0_8_ = (u32)(int)puVar38;
              auVar5._8_4_ = in_t7_udw;
              auVar5._0_8_ = uVar34 | (u32)(uVar36 | 0x6a008000 | (u32)*(u8 *)(iVar52 + 0xa6))
                                      << 0x20;
              auVar5._12_4_ = in_register_000000fc;
              auVar45 = _pcpyld(auVar5,auVar44);
              *(int *)plVar57 = auVar45._0_4_;
              *(int *)((int)plVar57 + 4) = auVar45._4_4_;
              *(int *)(plVar57 + 1) = auVar45._8_4_;
              *(int *)((int)plVar57 + 0xc) = auVar45._12_4_;
              *puVar38 = uVar60;
              puVar38[1] = uVar62;
              puVar38[2] = uVar63;
              puVar38[3] = uVar64;
              plVar57 = (long *)(puVar38 + 4);
              break;
            case 10:
              lVar23 = lVar16;
              if (bVar12) {
                bVar12 = 0;
                lVar23 = *plVar57;
              }
              auVar47._8_8_ = auVar49._8_8_;
              auVar47._0_8_ = lVar23;
              plVar58 = plVar57 + iVar31 * 2;
              auVar45._0_8_ = (u32)(int)plVar58;
              auVar9._8_4_ = in_s7_udw;
              auVar9._0_8_ = (u32)(uVar36 | 0x68008000 | uVar59 * uVar15) << 0x20 | 0x1000404;
              auVar9._12_4_ = in_register_0000017c;
              auVar49 = _pcpyld(auVar9,auVar47);
              *(int *)plVar57 = auVar49._0_4_;
              *(int *)((int)plVar57 + 4) = auVar49._4_4_;
              *(int *)(plVar57 + 1) = auVar49._8_4_;
              *(int *)((int)plVar57 + 0xc) = auVar49._12_4_;
              *(u32 *)plVar58 = uVar60;
              *(u32 *)((int)plVar58 + 4) = uVar62;
              *(u32 *)(plVar58 + 1) = uVar63;
              *(u32 *)((int)plVar58 + 0xc) = uVar64;
              plVar57 = plVar58 + 2;
              break;
            case 0xb:
              lVar23 = lVar16;
              if (bVar12) {
                bVar12 = 0;
                lVar23 = *plVar57;
              }
              auVar48._8_8_ = auVar49._8_8_;
              auVar48._0_8_ = lVar23;
              puVar38 = (u32 *)((int)plVar57 + uVar21);
              auVar45._0_8_ = (u32)(int)puVar38;
              auVar10._8_4_ = in_s8_udw;
              auVar10._0_8_ = (u32)uVar37 << 0x20 | 0x1000404;
              auVar10._12_4_ = in_register_000001ec;
              auVar49 = _pcpyld(auVar10,auVar48);
              *(int *)plVar57 = auVar49._0_4_;
              *(int *)((int)plVar57 + 4) = auVar49._4_4_;
              *(int *)(plVar57 + 1) = auVar49._8_4_;
              *(int *)((int)plVar57 + 0xc) = auVar49._12_4_;
              *puVar38 = uVar60;
              puVar38[1] = uVar62;
              puVar38[2] = uVar63;
              puVar38[3] = uVar64;
              plVar57 = (long *)(puVar38 + 4);
            }
          }
          auVar46._8_8_ = auVar45._8_8_;
          uVar32 = uVar32 + 1;
          iVar27 = iVar27 + 8;
          auVar46._0_8_ = CONCAT71(0,(int)uVar32 < *(int *)(param_1 + 0x24) + 10);
          lVar23 = (long)(iVar52 + 0x18);
          uVar26 = auVar17._8_8_;
        } while (auVar46._0_8_ != 0);
      }
      uVar32 = 0x15000000;
      iVar50 = iVar50 + 4;
      if (lVar55 != 0) {
        uVar32 = 0x17000000;
      }
      lVar55 = (long)((int)lVar55 + 1);
      auVar30._0_8_ = (u32)uVar32 << 0x20 | (long)(int)(uVar59 | 0x4000000);
      auVar13._8_8_ = 0;
      auVar13._0_8_ = uVar26;
      auVar25 = _pcpyld(auVar13 << 0x40,auVar30);
      *(int *)plVar57 = auVar25._0_4_;
      *(int *)((int)plVar57 + 4) = auVar25._4_4_;
      *(int *)(plVar57 + 1) = auVar25._8_4_;
      *(int *)((int)plVar57 + 0xc) = auVar25._12_4_;
      lVar23 = (long)*(int *)(iVar22 + 0x34);
      plVar58 = plVar57 + 2;
      in_t4_qw = auVar46;
      in_t5_qw = auVar49;
      uVar26 = auVar30._8_8_;
    } while (lVar55 < lVar23);
  }
  iVar22 = (int)plVar58 - (int)plVar56;
  plVar58[-1] = 0x1100000011000000;
  if (iVar22 < 0) {
    iVar22 = iVar22 + 0xf;
  }
  *plVar56 = (long)(int)((iVar22 >> 4) - 1U | 0x60000000);
  if (*(char *)(iVar1 + 0xb4) == '\0') {
    plVar56[1] = 0;
  }
  return 1;
}

// FUN_0049E4F0 NONMATCHING

void FUN_0049e4f0(u64 param_1)

{
  u8 bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  iVar2 = *(int *)param_1;
  iVar5 = iVar2 + -1;
  if (iVar2 != 0) {
    piVar4 = (int *)param_1 + iVar5;
    do {
      piVar3 = (int *)piVar4[1];
      if (piVar3 != (int *)0x0) {
        if ((*piVar3 == 0) && (piVar3[1] == 0)) {
          ((code)FUN_0049cc30)(piVar3);
          ((code)FUN_004c47e0)(piVar3);
        }
        else {
          piVar3[4] = 0;
        }
      }
      piVar4 = piVar4 + -1;
      bVar1 = iVar5 != 0;
      iVar5 = iVar5 + -1;
    } while (bVar1);
  }
  (*DAT_0096017c)(param_1);
  return;
}

// FUN_0049E5A0 NONMATCHING

u64 FUN_0049e5a0(u64 param_1,int param_2)

{
  u8 bVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  
  piVar4 = (int *)param_1;
  piVar2 = (int *)*piVar4;
  if (piVar2 != (int *)0x0) {
    iVar6 = *piVar2 + -1;
    if (*piVar2 != 0) {
      piVar5 = piVar2 + iVar6;
      do {
        piVar3 = (int *)piVar5[1];
        if (piVar3 != (int *)0x0) {
          if ((*piVar3 == 0) && (piVar3[1] == 0)) {
            ((code)FUN_0049cc30)(piVar3);
            ((code)FUN_004c47e0)(piVar3);
          }
          else {
            piVar3[4] = 0;
          }
        }
        piVar5 = piVar5 + -1;
        bVar1 = iVar6 != 0;
        iVar6 = iVar6 + -1;
      } while (bVar1);
    }
    (*DAT_0096017c)(piVar2);
    *piVar4 = 0;
  }
  iVar6 = (*DAT_00960178)((param_2 + -1) * 4 + 8,0x3050d);
  *piVar4 = iVar6;
  if ((int *)*piVar4 != (int *)0x0) {
    *(int *)*piVar4 = param_2;
    ((code)FUN_00521408)(*piVar4 + 4,0,param_2 << 2);
  }
  return param_1;
}

// FUN_0049E6C0 NONMATCHING

u32 FUN_0049e6c0(int param_1)

{
  u8 bVar1;
  u32 uVar2;
  u32 *puVar3;
  int iVar4;
  
  puVar3 = *(u32 **)(param_1 + 8);
  bVar1 = 0;
  uVar2 = 1;
  do {
    switch(*puVar3 >> 0x1c & 7) {
    case 0:
      bVar1 = 1;
      break;
    case 1:
      puVar3 = puVar3 + ((*puVar3 & 0xffff) + 1) * 4;
      break;
    case 3:
      iVar4 = puVar3[1] - *(int *)(param_1 + 8);
      if (iVar4 < 0) {
        iVar4 = iVar4 + 0xf;
      }
      puVar3[1] = iVar4 >> 4;
      uVar2 = 0;
      puVar3 = puVar3 + 4;
      break;
    case 6:
      bVar1 = 1;
      break;
    case 7:
      bVar1 = 1;
    }
  } while (!bVar1);
  return uVar2;
}

// FUN_0049E780 NONMATCHING

u32 FUN_0049e780(int param_1)

{
  u8 bVar1;
  u32 uVar2;
  u32 *puVar3;
  
  puVar3 = *(u32 **)(param_1 + 8);
  bVar1 = 0;
  uVar2 = 1;
  do {
    switch(*puVar3 >> 0x1c & 7) {
    case 0:
      bVar1 = 1;
      break;
    case 1:
      puVar3 = puVar3 + ((*puVar3 & 0xffff) + 1) * 4;
      break;
    case 3:
      uVar2 = 0;
      puVar3[1] = *(int *)(param_1 + 8) + puVar3[1] * 0x10;
      puVar3 = puVar3 + 4;
      break;
    case 6:
      bVar1 = 1;
      break;
    case 7:
      bVar1 = 1;
    }
  } while (!bVar1);
  return uVar2;
}

// FUN_0049E830 NONMATCHING

u64 FUN_0049e830(u64 param_1,u64 param_2)

{
  u32 *puVar1;
  int iVar2;
  long lVar3;
  u32 uVar4;
  u32 uVar5;
  u32 *puVar6;
  u32 uStack_8;
  int iStack_4;
  
  if ((*(u32 *)((int)param_2 + 8) & 0x1000000) != 0) {
    puVar1 = *(u32 **)((int)param_2 + DAT_007ce890);
    uVar5 = *puVar1;
    uVar4 = 0;
    puVar6 = puVar1;
    if (uVar5 != 0) {
      do {
        ((code)FUN_0049cc30)(puVar6[1]);
        uVar4 = uVar4 + 1;
        puVar6 = puVar6 + 1;
      } while (uVar4 < uVar5);
    }
    iVar2 = ((code)FUN_0049ecd0)(param_2);
    lVar3 = ((code)FUN_004c15a0)(param_1,1,iVar2 + -0xc,0x37002,0x37);
    if (lVar3 == 0) {
      param_1 = 0;
    }
    else {
      lVar3 = ((code)FUN_004c53f0)(param_1,0x7cdc00,4);
      if (lVar3 == 0) {
        param_1 = 0;
      }
      else {
        uVar5 = 0;
        puVar6 = puVar1;
        if (*puVar1 != 0) {
          do {
            uVar4 = puVar6[1];
            iStack_4 = *(int *)(uVar4 + 8) - (*(int *)(uVar4 + 0x20) - uVar4);
            lVar3 = ((code)FUN_004c53f0)(param_1,&iStack_4,4);
            if (lVar3 == 0) {
              return 0;
            }
            uStack_8 = ((code)FUN_0049e6c0)(uVar4 + 0x18);
            lVar3 = ((code)FUN_004c53f0)(param_1,&uStack_8,4);
            if (lVar3 == 0) {
              return 0;
            }
            lVar3 = ((code)FUN_004c53f0)(param_1,*(u32 *)(uVar4 + 0x20),iStack_4);
            if (lVar3 == 0) {
              return 0;
            }
            ((code)FUN_0049e780)(uVar4 + 0x18);
            ((code)FUN_00503a58)(uVar4,uVar4 + *(int *)(uVar4 + 8) + 0x18);
            uVar5 = uVar5 + 1;
            puVar6 = puVar6 + 1;
          } while (uVar5 < *puVar1);
        }
      }
    }
  }
  return param_1;
}

// FUN_0049E9F0 NONMATCHING

u64 FUN_0049e9f0(u64 param_1,u64 param_2)

{
  int iVar1;
  u8 bVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int *piVar6;
  u32 *puVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  u32 uStack_18;
  u32 uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  u32 uStack_4;
  
  lVar5 = ((code)FUN_004c1600)(param_1,1,0,&uStack_4);
  if (lVar5 == 0) {
    param_2 = 0;
  }
  else if ((uStack_4 < 0x35000) || (0x37002 < uStack_4)) {
    uStack_18 = 2;
    uStack_14 = ((code)FUN_004c1d10)(0xffffffff80000004);
    ((code)FUN_004c1c50)(&uStack_18);
    param_2 = 0;
  }
  else {
    lVar5 = ((code)FUN_004c5250)(param_1,&iStack_8,4);
    if (lVar5 == 4) {
      if (iStack_8 == 4) {
        iVar10 = (int)param_2;
        piVar6 = (int *)(iVar10 + DAT_007ce890);
        bVar2 = 0;
        if (((int *)*piVar6 != (int *)0x0) && (*(int *)(iVar10 + 0x24) == *(int *)*piVar6)) {
          bVar2 = 1;
        }
        if (bVar2) {
          piVar6 = (int *)*piVar6;
        }
        else {
          piVar6 = (int *)((code)FUN_0049e5a0)(piVar6,*(u32 *)(iVar10 + 0x24));
          piVar6 = (int *)*piVar6;
        }
        iVar1 = *piVar6;
        iVar9 = 0;
        if (0 < iVar1) {
          do {
            lVar5 = ((code)FUN_004c5250)(param_1,&iStack_c,4);
            if (lVar5 != 4) {
              return 0;
            }
            piVar8 = piVar6 + 1;
            iVar4 = (*DAT_00960178)(iStack_c + 0x247,0x3050d);
            *piVar8 = iVar4;
            if ((u32 *)*piVar8 == (u32 *)0x0) {
              return 0;
            }
            *(u32 *)*piVar8 = 0;
            *(u32 *)(*piVar8 + 4) = 0;
            *(int *)(*piVar8 + 0xc) = iVar10;
            *(int *)(*piVar8 + 8) = iStack_c + 0x22f;
            *(int **)(*piVar8 + 0x10) = piVar8;
            *(code **)(*piVar8 + 0x14) = (code *)(FUN_0049cc30);
            iVar4 = *piVar8;
            puVar7 = (u32 *)(iVar4 + 0x18);
            lVar5 = ((code)FUN_004c5250)(param_1,&iStack_10,4);
            if (lVar5 != 4) {
              return 0;
            }
            *puVar7 = 0;
            *(u32 *)(iVar4 + 0x1c) = 0;
            ((code)FUN_00521408)(puVar7,0,0x1b0);
            iVar3 = iStack_c;
            *(u32 *)(iVar4 + 0x20) = iVar4 + 0x207U & 0xffffffc0;
            if (iStack_10 != 0) {
              *(u32 *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x7fU & 0xffffff80;
            }
            iVar4 = ((code)FUN_004c5250)(param_1,*(u32 *)(iVar4 + 0x20),iStack_c);
            if (iVar3 != iVar4) {
              return 0;
            }
            ((code)FUN_0049e780)(puVar7);
            iVar4 = *piVar8;
            ((code)FUN_00503a58)(iVar4,iVar4 + *(int *)(iVar4 + 8) + 0x18);
            iVar9 = iVar9 + 1;
            piVar6 = piVar6 + 1;
          } while (iVar9 < iVar1);
        }
      }
      else {
        param_2 = 0;
      }
    }
    else {
      param_2 = 0;
    }
  }
  return param_2;
}

// FUN_0049ECD0 NONMATCHING

int FUN_0049ecd0(int param_1)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar9;
  int iVar10;
  u32 *puVar11;
  u32 uVar12;
  u32 *puVar13;
  
  iVar10 = 0;
  if ((*(u32 *)(param_1 + 8) & 0x1000000) != 0) {
    iVar10 = 0x10;
    puVar13 = *(u32 **)(param_1 + DAT_007ce890);
    uVar1 = *puVar13;
    uVar12 = 0;
    if (uVar1 != 0) {
      puVar11 = puVar13;
      if (8 < uVar1) {
        do {
          uVar2 = puVar11[1];
          uVar12 = uVar12 + 8;
          uVar3 = puVar11[2];
          uVar4 = puVar11[3];
          uVar5 = puVar11[4];
          uVar6 = puVar11[5];
          uVar7 = puVar11[6];
          uVar8 = puVar11[7];
          uVar9 = puVar11[8];
          iVar10 = iVar10 + (*(int *)(uVar2 + 8) - (*(int *)(uVar2 + 0x20) - uVar2)) +
                   (*(int *)(uVar3 + 8) - (*(int *)(uVar3 + 0x20) - uVar3)) +
                   (*(int *)(uVar4 + 8) - (*(int *)(uVar4 + 0x20) - uVar4)) +
                   (*(int *)(uVar5 + 8) - (*(int *)(uVar5 + 0x20) - uVar5)) +
                   (*(int *)(uVar6 + 8) - (*(int *)(uVar6 + 0x20) - uVar6)) +
                   (*(int *)(uVar7 + 8) - (*(int *)(uVar7 + 0x20) - uVar7)) +
                   (*(int *)(uVar8 + 8) - (*(int *)(uVar8 + 0x20) - uVar8)) +
                   (*(int *)(uVar9 + 8) - (*(int *)(uVar9 + 0x20) - uVar9)) + 0x40;
          puVar11 = puVar11 + 8;
        } while (uVar12 < uVar1 - 8);
      }
      if (uVar12 < uVar1) {
        puVar13 = puVar13 + uVar12;
        do {
          uVar2 = puVar13[1];
          uVar12 = uVar12 + 1;
          puVar13 = puVar13 + 1;
          iVar10 = iVar10 + (*(int *)(uVar2 + 8) - (*(int *)(uVar2 + 0x20) - uVar2)) + 8;
        } while (uVar12 < uVar1);
      }
    }
  }
  return iVar10;
}

// FUN_0049EE70 NONMATCHING

u64 FUN_0049ee70(u64 param_1,u64 param_2)

{
  u32 *puVar1;
  int iVar2;
  long lVar3;
  u32 uVar4;
  u32 uVar5;
  u32 *puVar6;
  u32 uStack_8;
  int iStack_4;
  
  iVar2 = ((code)FUN_0049a170)(param_2);
  if ((*(u32 *)(iVar2 + 8) & 0x1000000) != 0) {
    puVar1 = *(u32 **)((int)param_2 + DAT_007ce888);
    uVar5 = *puVar1;
    uVar4 = 0;
    puVar6 = puVar1;
    if (uVar5 != 0) {
      do {
        ((code)FUN_0049cc30)(puVar6[1]);
        uVar4 = uVar4 + 1;
        puVar6 = puVar6 + 1;
      } while (uVar4 < uVar5);
    }
    iVar2 = ((code)FUN_0049f340)(param_2);
    lVar3 = ((code)FUN_004c15a0)(param_1,1,iVar2 + -0xc,0x37002,0x37);
    if (lVar3 == 0) {
      param_1 = 0;
    }
    else {
      lVar3 = ((code)FUN_004c53f0)(param_1,0x7cdc04,4);
      if (lVar3 == 0) {
        param_1 = 0;
      }
      else {
        uVar5 = 0;
        puVar6 = puVar1;
        if (*puVar1 != 0) {
          do {
            uVar4 = puVar6[1];
            iStack_4 = *(int *)(uVar4 + 8) - (*(int *)(uVar4 + 0x20) - uVar4);
            lVar3 = ((code)FUN_004c53f0)(param_1,&iStack_4,4);
            if (lVar3 == 0) {
              return 0;
            }
            uStack_8 = ((code)FUN_0049e6c0)(uVar4 + 0x18);
            lVar3 = ((code)FUN_004c53f0)(param_1,&uStack_8,4);
            if (lVar3 == 0) {
              return 0;
            }
            lVar3 = ((code)FUN_004c53f0)(param_1,*(u32 *)(uVar4 + 0x20),iStack_4);
            if (lVar3 == 0) {
              return 0;
            }
            ((code)FUN_0049e780)(uVar4 + 0x18);
            ((code)FUN_00503a58)(uVar4,uVar4 + *(int *)(uVar4 + 8) + 0x18);
            uVar5 = uVar5 + 1;
            puVar6 = puVar6 + 1;
          } while (uVar5 < *puVar1);
        }
      }
    }
  }
  return param_1;
}

// FUN_0049F040 NONMATCHING

u64 FUN_0049f040(u64 param_1,u64 param_2)

{
  int iVar1;
  u8 bVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  int *piVar6;
  u32 *puVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  u32 uStack_18;
  u32 uStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  u32 uStack_4;
  
  ((code)FUN_0049a170)(param_2);
  lVar5 = ((code)FUN_004c1600)(param_1,1,0,&uStack_4);
  if (lVar5 == 0) {
    param_2 = 0;
  }
  else if ((uStack_4 < 0x35000) || (0x37002 < uStack_4)) {
    uStack_18 = 2;
    uStack_14 = ((code)FUN_004c1d10)(0xffffffff80000004);
    ((code)FUN_004c1c50)(&uStack_18);
    param_2 = 0;
  }
  else {
    lVar5 = ((code)FUN_004c5250)(param_1,&iStack_8,4);
    if (lVar5 == 4) {
      if (iStack_8 == 4) {
        iVar10 = (int)param_2;
        piVar6 = (int *)(iVar10 + DAT_007ce888);
        bVar2 = 0;
        if (((u32 *)*piVar6 != (u32 *)0x0) &&
           ((u32)*(u16 *)(*(int *)(iVar10 + 0x78) + 4) == *(u32 *)*piVar6)) {
          bVar2 = 1;
        }
        if (bVar2) {
          piVar6 = (int *)*piVar6;
        }
        else {
          piVar6 = (int *)((code)FUN_0049e5a0)(piVar6,*(u16 *)(*(int *)(iVar10 + 0x78) + 4));
          piVar6 = (int *)*piVar6;
        }
        iVar1 = *piVar6;
        iVar9 = 0;
        if (0 < iVar1) {
          do {
            lVar5 = ((code)FUN_004c5250)(param_1,&iStack_c,4);
            if (lVar5 != 4) {
              return 0;
            }
            piVar8 = piVar6 + 1;
            iVar4 = (*DAT_00960178)(iStack_c + 0x247,0x3050d);
            *piVar8 = iVar4;
            if ((u32 *)*piVar8 == (u32 *)0x0) {
              return 0;
            }
            *(u32 *)*piVar8 = 0;
            *(u32 *)(*piVar8 + 4) = 0;
            *(int *)(*piVar8 + 0xc) = iVar10;
            *(int *)(*piVar8 + 8) = iStack_c + 0x22f;
            *(int **)(*piVar8 + 0x10) = piVar8;
            *(code **)(*piVar8 + 0x14) = (code *)(FUN_0049cc30);
            iVar4 = *piVar8;
            puVar7 = (u32 *)(iVar4 + 0x18);
            lVar5 = ((code)FUN_004c5250)(param_1,&iStack_10,4);
            if (lVar5 != 4) {
              return 0;
            }
            *puVar7 = 0;
            *(u32 *)(iVar4 + 0x1c) = 0;
            ((code)FUN_00521408)(puVar7,0,0x1b0);
            iVar3 = iStack_c;
            *(u32 *)(iVar4 + 0x20) = iVar4 + 0x207U & 0xffffffc0;
            if (iStack_10 != 0) {
              *(u32 *)(iVar4 + 0x20) = *(int *)(iVar4 + 0x20) + 0x7fU & 0xffffff80;
            }
            iVar4 = ((code)FUN_004c5250)(param_1,*(u32 *)(iVar4 + 0x20),iStack_c);
            if (iVar3 != iVar4) {
              return 0;
            }
            ((code)FUN_0049e780)(puVar7);
            iVar4 = *piVar8;
            ((code)FUN_00503a58)(iVar4,iVar4 + *(int *)(iVar4 + 8) + 0x18);
            iVar9 = iVar9 + 1;
            piVar6 = piVar6 + 1;
          } while (iVar9 < iVar1);
        }
      }
      else {
        param_2 = 0;
      }
    }
    else {
      param_2 = 0;
    }
  }
  return param_2;
}

// FUN_0049F340 NONMATCHING

int FUN_0049f340(int param_1)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar9;
  int iVar10;
  u32 *puVar11;
  u32 uVar12;
  u32 *puVar13;
  int iVar14;
  
  iVar14 = 0;
  iVar10 = ((code)FUN_0049a170)();
  if ((*(u32 *)(iVar10 + 8) & 0x1000000) != 0) {
    iVar14 = 0x10;
    puVar13 = *(u32 **)(param_1 + DAT_007ce888);
    uVar1 = *puVar13;
    uVar12 = 0;
    if (uVar1 != 0) {
      puVar11 = puVar13;
      if (8 < uVar1) {
        do {
          uVar2 = puVar11[1];
          uVar12 = uVar12 + 8;
          uVar3 = puVar11[2];
          uVar4 = puVar11[3];
          uVar5 = puVar11[4];
          uVar6 = puVar11[5];
          uVar7 = puVar11[6];
          uVar8 = puVar11[7];
          uVar9 = puVar11[8];
          iVar14 = iVar14 + (*(int *)(uVar2 + 8) - (*(int *)(uVar2 + 0x20) - uVar2)) +
                   (*(int *)(uVar3 + 8) - (*(int *)(uVar3 + 0x20) - uVar3)) +
                   (*(int *)(uVar4 + 8) - (*(int *)(uVar4 + 0x20) - uVar4)) +
                   (*(int *)(uVar5 + 8) - (*(int *)(uVar5 + 0x20) - uVar5)) +
                   (*(int *)(uVar6 + 8) - (*(int *)(uVar6 + 0x20) - uVar6)) +
                   (*(int *)(uVar7 + 8) - (*(int *)(uVar7 + 0x20) - uVar7)) +
                   (*(int *)(uVar8 + 8) - (*(int *)(uVar8 + 0x20) - uVar8)) +
                   (*(int *)(uVar9 + 8) - (*(int *)(uVar9 + 0x20) - uVar9)) + 0x40;
          puVar11 = puVar11 + 8;
        } while (uVar12 < uVar1 - 8);
      }
      if (uVar12 < uVar1) {
        puVar13 = puVar13 + uVar12;
        do {
          uVar2 = puVar13[1];
          uVar12 = uVar12 + 1;
          puVar13 = puVar13 + 1;
          iVar14 = iVar14 + (*(int *)(uVar2 + 8) - (*(int *)(uVar2 + 0x20) - uVar2)) + 8;
        } while (uVar12 < uVar1);
      }
    }
  }
  return iVar14;
}

// FUN_0049F5D0 NONMATCHING

u32 FUN_0049f5d0(int param_1,u32 *param_2)

{
  int iVar1;
  int iVar2;
  Vec128 auVar3;
  int iVar4;
  long lVar5;
  u64 in_v1_udw;
  Vec128 auVar6;
  Vec128 auVar7;
  u32 in_a2_udw;
  int iVar8;
  int iVar9;
  u32 *puVar10;
  u32 uVar11;
  int iVar12;
  int iVar13;
  u8 *apuStack_a0 [4];
  u8 auStack_90 [64];
  int iStack_50;
  u32 *puStack_4c;
  u32 uStack_48;
  int iStack_44;
  int iStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  int iStack_30;
  u32 uStack_2c;
  u8 bStack_28;
  u8 uStack_27;
  char cStack_26;
  u8 bStack_25;
  int iStack_24;
  int *piStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  int iStack_14;
  u32 uStack_10;
  u8 uStack_c;
  u8 uStack_b;
  u8 uStack_a;
  u8 uStack_9;
  
  uStack_48 = *param_2;
  iVar1 = *(int *)(param_1 + 0x14);
  puStack_4c = (u32 *)0x0;
  iVar2 = *(int *)((u8 *)DAT_009600b4 + DAT_007ceb28);
  iStack_30 = 1;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_2c = 0;
  uStack_27 = 0xff;
  iStack_44 = 0;
  iStack_40 = 0;
  DAT_007ce880 = 0;
  DAT_007ce884 = (u32 *)((u32)((u8 *)DAT_0095dfd0));
  uStack_3c = 1;
  apuStack_a0[0] = auStack_90;
  bStack_28 = 0;
  cStack_26 = '\0';
  iStack_50 = iVar1;
  lVar5 = (**(code **)(iVar1 + 0x10))(&iStack_50,apuStack_a0);
  if (lVar5 != 0) {
    if (1 < iStack_30) {
      uStack_2c = 2;
    }
    auVar7._0_8_ = (long)(int)DAT_007ce880;
    auVar7._8_8_ = in_v1_udw;
    if (auVar7._0_8_ == 0) {
      DAT_007ce884 = (u32 *)((u32)(*(u32 **)(iVar1 + 0x24)));
      DAT_007ce880 = 2;
    }
    else if (auVar7._0_8_ == -1) {
      DAT_007ce880 = 0;
    }
    else {
      if (auVar7._0_8_ == -5) {
        DAT_007ce880 = 4;
      }
      else {
        auVar7 = *(Vec128 *)(*(int *)(iVar1 + 0x24) + 0x10);
        *DAT_007ce884 = (*(u32*)((u8*)&auVar7 + 0));
        DAT_007ce884[1] = (*(u32*)((u8*)&auVar7 + 4));
        DAT_007ce884[2] = (*(u32*)((u8*)&auVar7 + 8));
        DAT_007ce884[3] = (*(u32*)((u8*)&auVar7 + 12));
        DAT_007ce880 = DAT_007ce880 + 1;
      }
      auVar6._8_8_ = auVar7._8_8_;
      DAT_007ce884 = (u32 *)((u32)((u8 *)DAT_0095dfc0));
      auVar6._0_8_ = ((u32)DAT_007ce880 << 0x10 | 0x6c000000 | (u32)*(u32 *)(iVar1 + 0x1c)) <<
                     0x20 | 0x1000404;
      auVar3._8_8_ = 0;
      auVar3._0_8_ = in_a2_udw;
      auVar7 = _pcpyld(auVar6,auVar3 << 0x40);
      DAT_0095dfc0 = auVar7._0_4_;
      DAT_0095dfc4 = auVar7._4_4_;
      DAT_0095dfc8 = auVar7._8_4_;
      DAT_0095dfcc = auVar7._12_4_;
      DAT_007ce880 = DAT_007ce880 + 1;
    }
    ((code)FUN_004ec2b0)(apuStack_a0[0],DAT_007ce884,DAT_007ce880);
    iVar4 = iStack_44;
    iVar13 = 0;
    puVar10 = (u32 *)0x0;
    uVar11 = 0;
    iVar9 = *(int *)(iStack_44 + 0xc) + iStack_44 + 0x10;
    iVar12 = iStack_40;
    if (*(short *)(iStack_44 + 4) != 0) {
      do {
        iVar8 = *(int *)(iVar1 + 0x18);
        if ((*(int *)(iVar1 + 0x18) == 0) && (iVar8 = *(int *)(*(int *)(iVar9 + 8) + 8), iVar8 == 0)
           ) {
          iVar8 = iVar2;
        }
        if (iVar8 != iVar13) {
          puVar10 = *(u32 **)(*(int *)(iVar8 + 8) + 0x14);
          iVar13 = iVar8;
          puStack_4c = puVar10;
        }
        uStack_18 = 0;
        piStack_20 = (int *)(iVar12 + 4);
        uStack_1c = uStack_3c;
        bStack_25 = bStack_28 & 0x1f;
        iStack_14 = *(int *)(iVar9 + 8) + 0xc;
        uStack_10 = **(u32 **)(iVar9 + 8);
        uStack_c = DAT_007cdc08;
        uStack_b = DAT_007cdc09;
        uStack_a = DAT_007cdc0a;
        uStack_9 = DAT_007cdc0b;
        if (cStack_26 != '\0') {
          iVar8 = *(int *)(iVar9 + 8);
          uStack_c = *(u8 *)(iVar8 + 4);
          uStack_b = *(u8 *)(iVar8 + 5);
          uStack_a = *(u8 *)(iVar8 + 6);
          uStack_9 = *(u8 *)(iVar8 + 7);
        }
        iStack_24 = iVar9;
        if (uStack_3c != 1) {
          uStack_1c = uStack_3c | 1;
          if (*piStack_20 == 0) {
            uStack_1c = uStack_3c | 0x7fff9;
          }
          else if ((code *)*puStack_4c != (code *)0x0) {
            (*(code *)*puStack_4c)(&iStack_50);
          }
          if (((uStack_1c & 0xe) != 0) && (lVar5 = ((code)FUN_0049faa0)(&iStack_50), lVar5 == 0)) {
            return 0;
          }
          iVar8 = *(int *)*piStack_20;
          if (iVar8 != 0) {
            *(int *)((int *)*piStack_20)[1] = iVar8;
            *(int *)(*(int *)*piStack_20 + 4) = ((int *)*piStack_20)[1];
            *(u32 *)*piStack_20 = **(u32 **)((int)(u8 *)DAT_00960094 + DAT_007ce8f0);
            *(u32 *)(*piStack_20 + 4) = *(u32 *)((int)(u8 *)DAT_00960094 + DAT_007ce8f0);
            *(int *)(**(int **)((int)(u8 *)DAT_00960094 + DAT_007ce8f0) + 4) = *piStack_20;
            **(int **)((int)(u8 *)DAT_00960094 + DAT_007ce8f0) = *piStack_20;
          }
        }
        (*(code *)puStack_4c[3])(&iStack_50);
        iVar9 = iVar9 + 0xc;
        if ((code *)puVar10[4] != (code *)0x0) {
          (*(code *)puVar10[4])(&iStack_50);
        }
        uVar11 = uVar11 + 1;
        iVar12 = iVar12 + 4;
      } while (uVar11 < *(u16 *)(iVar4 + 4));
    }
    if (*(code **)(iVar1 + 0x14) != (code *)0x0) {
      (**(code **)(iVar1 + 0x14))(&iStack_50);
    }
  }
  return 1;
}

// FUN_0049FAA0 NONMATCHING

u64 FUN_0049faa0(u64 param_1)

{
  u8 bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  u64 uVar6;
  int iVar7;
  u32 uVar8;
  u32 uVar9;
  u32 *puVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  u32 uVar16;
  u32 uVar17;
  u32 uVar18;
  u32 auStack_160 [12];
  u32 auStack_130 [73];
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  uStack_4 = 0;
  uStack_8 = 0;
  uStack_c = 0;
  iVar7 = (int)param_1;
  iVar2 = *(int *)(iVar7 + 4);
  piVar3 = *(int **)(iVar7 + 0x30);
  iVar15 = *piVar3 + 0x18;
  if ((*(u32 *)(iVar7 + 0x34) & 0xc) == 0) {
    bVar1 = *(u8 *)(iVar2 + 0xb5);
  }
  else {
    *(u32 *)(iVar7 + 0x34) = *(u32 *)(iVar7 + 0x34) | 0x7fff0;
    iVar12 = *(int *)(*(int *)(iVar7 + 0x2c) + 4);
    if ((**(u32 **)(iVar7 + 0xc) & 2) != 0) {
      iVar12 = (iVar12 + -2) * 3;
    }
    uVar6 = ((code)FUN_0049d4d0)(param_1,iVar12,auStack_130,&uStack_4,&uStack_8,&uStack_c);
    if (*piVar3 != 0) {
      *(u32 *)(*piVar3 + 0x10) = 0;
      *piVar3 = 0;
    }
    iVar15 = (**(code **)(iVar2 + 4))(param_1,piVar3,uVar6,0x49cc30);
    *piVar3 = iVar15;
    iVar4 = *piVar3;
    if (iVar4 == 0) {
      return 0;
    }
    *(u32 *)(iVar4 + 0x18) = 0;
    *(u32 *)(iVar4 + 0x1c) = 0;
    iVar15 = iVar4 + 0x18;
    *(u32 *)(iVar4 + 0x28) = *(u32 *)(iVar7 + 0x18);
    *(u32 *)(iVar7 + 0x38) = **(u32 **)(iVar7 + 0xc);
    *(u32 *)(iVar4 + 0x2c) = *(u32 *)(iVar7 + 0x38);
    *(int *)(iVar4 + 0x24) = iVar12;
    uVar8 = 0;
    if (*(int *)(iVar7 + 0x24) != -10) {
      puVar10 = auStack_130;
      iVar12 = iVar15;
      do {
        uVar8 = uVar8 + 1;
        uVar18 = puVar10[1];
        uVar16 = puVar10[2];
        uVar17 = puVar10[3];
        *(u32 *)(iVar12 + 0x90) = *puVar10;
        *(u32 *)(iVar12 + 0x94) = uVar18;
        *(u32 *)(iVar12 + 0x98) = uVar16;
        *(u32 *)(iVar12 + 0x9c) = uVar17;
        uVar16 = puVar10[5];
        *(u32 *)(iVar12 + 0xa0) = puVar10[4];
        puVar10 = puVar10 + 6;
        *(u32 *)(iVar12 + 0xa4) = uVar16;
        iVar12 = iVar12 + 0x18;
      } while (uVar8 < *(int *)(iVar7 + 0x24) + 10U);
    }
    uVar8 = iVar4 + 0x207U & 0xffffffc0;
    *(u32 *)(iVar4 + 0x30) = uStack_4;
    *(u32 *)(iVar4 + 0x34) = uStack_c;
    *(u32 *)(iVar4 + 0x38) = uStack_8;
    *(u32 *)(iVar4 + 0x3c) = 0;
    *(u32 *)(iVar4 + 0x40) = 0;
    *(u32 *)(iVar4 + 0x44) = 1;
    if (*(char *)(iVar2 + 0xb4) != '\0') {
      uVar8 = uVar8 + 0x7f & 0xffffff80;
    }
    *(u32 *)(iVar4 + 0x20) = uVar8;
    iVar12 = *(int *)(iVar7 + 0x24);
    uVar8 = 0;
    iVar14 = iVar2;
    iVar11 = iVar15;
    iVar13 = iVar15;
    if (iVar12 != -10) {
      do {
        if (((*(u32 *)(iVar14 + 0x20) & 1) != 0) && ((*(u32 *)(iVar14 + 0x20) & 0x2000) == 0)) {
          iVar5 = *(int *)(iVar13 + 0x98);
          if (iVar12 != 0) {
            iVar5 = *(int *)(iVar13 + 0x9c);
          }
          *(int *)(iVar11 + 0x30) = *(int *)(iVar4 + 0x20) + iVar5 * 0x10;
          *(int *)(iVar11 + 0x34) = *(int *)(iVar14 + 0x24) << 2;
          iVar11 = iVar11 + 8;
        }
        iVar12 = *(int *)(iVar7 + 0x24);
        uVar8 = uVar8 + 1;
        iVar14 = iVar14 + 8;
        iVar13 = iVar13 + 0x18;
      } while (uVar8 < iVar12 + 10U);
    }
    ((code)FUN_0049dc70)(param_1);
    bVar1 = *(u8 *)(iVar2 + 0xb5);
  }
  uVar9 = (u32)bVar1;
  uVar8 = 0;
  if (uVar9 != 0) {
    if (8 < uVar9) {
      puVar10 = auStack_160;
      iVar12 = iVar15;
      do {
        uVar8 = uVar8 + 8;
        *puVar10 = *(u32 *)(iVar12 + 0x30);
        puVar10[1] = *(u32 *)(iVar12 + 0x38);
        puVar10[2] = *(u32 *)(iVar12 + 0x40);
        puVar10[3] = *(u32 *)(iVar12 + 0x48);
        puVar10[4] = *(u32 *)(iVar12 + 0x50);
        puVar10[5] = *(u32 *)(iVar12 + 0x58);
        puVar10[6] = *(u32 *)(iVar12 + 0x60);
        puVar10[7] = *(u32 *)(iVar12 + 0x68);
        iVar12 = iVar12 + 0x40;
        puVar10 = puVar10 + 8;
      } while (uVar8 < bVar1 - 8);
    }
    if (uVar8 < uVar9) {
      iVar12 = iVar15 + uVar8 * 8;
      puVar10 = auStack_160 + uVar8;
      do {
        uVar8 = uVar8 + 1;
        *puVar10 = *(u32 *)(iVar12 + 0x30);
        iVar12 = iVar12 + 8;
        puVar10 = puVar10 + 1;
      } while (uVar8 < uVar9);
    }
  }
  uVar6 = (**(code **)(iVar2 + 8))(param_1,auStack_160);
  ((code)FUN_00503a58)(*(u32 *)(iVar15 + 8),
               **(int **)(iVar7 + 0x30) + *(int *)(**(int **)(iVar7 + 0x30) + 8) + 0xdb);
  return uVar6;
}

// FUN_0049FE40 NONMATCHING

long FUN_0049fe40(long param_1,int param_2,long param_3)

{
  int iVar1;
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    iVar1 = *(int *)((int)param_1 + 0x14);
    if (iVar1 == 0) {
      param_1 = 0;
    }
    else if (param_2 == 2) {
      *(int *)(iVar1 + 0x14) = (int)param_3;
    }
    else if (param_2 == 1) {
      if (param_3 == 0) {
        param_1 = 0;
      }
      else {
        *(int *)(iVar1 + 0x10) = (int)param_3;
      }
    }
    else {
      param_1 = 0;
    }
  }
  return param_1;
}

// FUN_0049FEC0 NONMATCHING

long FUN_0049fec0(long param_1,u32 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    iVar1 = *(int *)((int)param_1 + 0x14);
    if (iVar1 == 0) {
      param_1 = 0;
    }
    else {
      *(u32 *)(iVar1 + 0x18) = param_2;
    }
  }
  return param_1;
}

// FUN_0049FF00
#pragma optimization_level 3

u8 ** FUN_0049ff00(void)
{
  return PTR_s_PS2All_csl_0077de80;
}
#pragma optimization_level 2

// FUN_0049FF10 NONMATCHING

void FUN_0049ff10(u32 param_1,u32 param_2,int param_3,long param_4)

{
  u8 bVar1;
  int iVar2;
  u32 *puVar3;
  u32 *puVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar9;
  u32 uVar10;
  u32 uVar11;
  u32 uVar12;
  u32 uVar13;
  u32 uVar14;
  u32 uVar15;
  
  bVar1 = *(u8 *)(param_3 + 1);
  iVar2 = *(int *)(param_3 + 4);
  if (DAT_007ce880 < 0x7c) {
    if (DAT_007ce880 == 0) {
      if (param_4 == 0) {
        *DAT_007ce884 = 0x3f800000;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = 0;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = 0;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = param_1;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = 0;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = 0x3f800000;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = 0;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = param_1;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = 0;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = 0;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = 0x3f800000;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = param_1;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = 0;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = 0;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = 0;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = param_2;
      }
      else {
        puVar3 = (u32 *)param_4;
        uVar15 = puVar3[1];
        uVar13 = puVar3[2];
        uVar14 = puVar3[4];
        uVar11 = puVar3[5];
        uVar12 = puVar3[6];
        *DAT_007ce884 = *puVar3;
        uVar9 = puVar3[8];
        uVar10 = puVar3[9];
        uVar7 = puVar3[10];
        uVar8 = puVar3[0xc];
        uVar5 = puVar3[0xd];
        uVar6 = puVar3[0xe];
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = uVar15;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = uVar13;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = param_1;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = uVar14;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = uVar11;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = uVar12;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = param_1;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = uVar9;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = uVar10;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = uVar7;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = param_1;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = uVar8;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = uVar5;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = uVar6;
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = param_2;
      }
      DAT_007ce884 = DAT_007ce884 + 1;
      DAT_007ce880 = DAT_007ce880 + 4;
    }
    if (iVar2 == 0) {
      puVar4 = (u32 *)0x0;
      puVar3 = (u32 *)0x0;
    }
    else {
      iVar2 = ((code)FUN_004cb2f0)();
      puVar3 = (u32 *)(iVar2 + 0x20);
      puVar4 = (u32 *)(iVar2 + 0x30);
    }
    uVar5 = *(u32 *)(param_3 + 0x1c);
    uVar6 = *(u32 *)(param_3 + 0x20);
    *DAT_007ce884 = *(u32 *)(param_3 + 0x18);
    DAT_007ce884[1] = uVar5;
    DAT_007ce884[2] = uVar6;
    DAT_007ce884[3] = (u32)bVar1;
    if (bVar1 != 0) {
      if ((bVar1 == 0x82) || (bVar1 == 0x81)) {
        uVar5 = *(u32 *)(param_3 + 0x14);
        uVar6 = *(u32 *)(param_3 + 0x28);
        DAT_007ce884 = DAT_007ce884 + 4;
        *DAT_007ce884 = *puVar4;
        DAT_007ce884 = DAT_007ce884 + 1;
        *DAT_007ce884 = puVar4[1];
        DAT_007ce884 = DAT_007ce884 + 1;
        *DAT_007ce884 = puVar4[2];
        puVar4 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar4 = uVar5;
        DAT_007ce884 = DAT_007ce884 + 1;
        *DAT_007ce884 = *puVar3;
        DAT_007ce884 = DAT_007ce884 + 1;
        *DAT_007ce884 = puVar3[1];
        DAT_007ce884 = DAT_007ce884 + 1;
        *DAT_007ce884 = puVar3[2];
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = uVar6;
        DAT_007ce884 = DAT_007ce884 + 1;
        DAT_007ce880 = DAT_007ce880 + 3;
      }
      else if (bVar1 == 0x80) {
        uVar5 = *(u32 *)(param_3 + 0x14);
        DAT_007ce884 = DAT_007ce884 + 4;
        *DAT_007ce884 = *puVar4;
        DAT_007ce884 = DAT_007ce884 + 1;
        *DAT_007ce884 = puVar4[1];
        DAT_007ce884 = DAT_007ce884 + 1;
        *DAT_007ce884 = puVar4[2];
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = uVar5;
        DAT_007ce884 = DAT_007ce884 + 1;
        DAT_007ce880 = DAT_007ce880 + 2;
      }
      else if (bVar1 == 2) {
        DAT_007ce884 = DAT_007ce884 + 4;
        DAT_007ce880 = DAT_007ce880 + 1;
      }
      else if (bVar1 == 1) {
        DAT_007ce884 = DAT_007ce884 + 4;
        *DAT_007ce884 = *puVar3;
        DAT_007ce884 = DAT_007ce884 + 1;
        *DAT_007ce884 = puVar3[1];
        DAT_007ce884 = DAT_007ce884 + 1;
        *DAT_007ce884 = puVar3[2];
        puVar3 = (u32 *)(DAT_007ce884 + 1);
        DAT_007ce884 = DAT_007ce884 + 1;
        *puVar3 = 0;
        DAT_007ce884 = DAT_007ce884 + 1;
        DAT_007ce880 = DAT_007ce880 + 2;
      }
    }
  }
  return;
}

// FUN_004A0430 NONMATCHING

u64 FUN_004a0430(u64 param_1,int param_2)

{
  if ((*(u8 *)((int)param_1 + 2) & 1) != 0) {
    ((code)FUN_0049ff10)(*(u32 *)(param_2 + 0x50),*(u32 *)(param_2 + 0x54),(int)param_1,
                 param_2 + 0x10);
  }
  return param_1;
}

// FUN_004A0480 NONMATCHING

void FUN_004a0480(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  u32 uVar3;
  u32 uVar4;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if ((*(u32 *)(iVar1 + 8) & 0x1000000) == 0) {
    *(u32 *)(param_2 + 0x18) =
         (u32)*(u8 *)(iVar1 + 0x18) << 0x18 |
         (u32)*(u16 *)(*(int *)(param_2 + 0xc) + 6) | (*(u32 *)(iVar1 + 8) & 0x9f) << 0x10;
    *(u32 *)(param_2 + 0x14) = *(u32 *)(param_2 + 0x14) & 0xfffffffe;
    iVar2 = *(int *)(*(int *)(param_2 + 0x10) + 4);
    if (iVar2 != 0) {
      uVar3 = *(u32 *)(iVar2 + 0x28);
      uVar4 = *(u32 *)(param_2 + 0x18);
      if (uVar4 != uVar3) {
        if (((uVar4 >> 0x10 & 0xff) == (uVar3 >> 0x10 & 0xff)) && (uVar4 >> 0x18 == uVar3 >> 0x18))
        {
          *(u32 *)(param_2 + 0x14) = *(u32 *)(param_2 + 0x14) | 4;
        }
        else {
          *(u32 *)(param_2 + 0x14) = *(u32 *)(param_2 + 0x14) | 8;
        }
      }
      if (*(u16 *)(iVar1 + 0xc) != 0) {
        if ((*(u16 *)(iVar1 + 0xc) & 1) == 0) {
          *(u32 *)(param_2 + 0x14) = *(u32 *)(param_2 + 0x14) | 2;
          *(u32 *)(param_2 + 0x14) =
               *(u32 *)(param_2 + 0x14) | (u32)*(u16 *)(iVar1 + 0xc) << 3;
        }
        else {
          *(u32 *)(param_2 + 0x14) = *(u32 *)(param_2 + 0x14) | 8;
        }
      }
      if (((*(u32 *)(param_1 + 0x4c) & 1) != 0) &&
         (((long)*(int *)(iVar2 + 0x40) != (long)*(short *)(param_1 + 0x52) ||
          ((long)*(int *)(iVar2 + 0x3c) != (long)*(short *)(param_1 + 0x50))))) {
        *(u32 *)(param_2 + 0x14) = *(u32 *)(param_2 + 0x14) | 4;
      }
    }
  }
  return;
}

// FUN_004A05D0 NONMATCHING

void FUN_004a05d0(int param_1,int param_2)

{
  u32 uVar1;
  
  uVar1 = **(u32 **)(param_1 + 0xc);
  if ((uVar1 & 1) == 1) {
    *(u8 *)(param_1 + 0x29) = 4;
    *(u8 *)(param_1 + 0x28) = DAT_007ceaf4;
  }
  else if (((uVar1 & 0xff) == 0) || ((uVar1 & 2) == 2)) {
    *(u8 *)(param_1 + 0x29) = 3;
    *(u8 *)(param_1 + 0x28) = DAT_007ceaf4 | 4;
  }
  else if ((uVar1 & 0x10) == 0x10) {
    *(u8 *)(param_1 + 0x29) = 4;
    *(u8 *)(param_1 + 0x28) = DAT_007ceaf4;
  }
  else if ((uVar1 & 8) == 8) {
    *(u8 *)(param_1 + 0x29) = 2;
    *(u8 *)(param_1 + 0x28) = DAT_007ceaf4 | 0x10;
  }
  else {
    *(u8 *)(param_1 + 0x29) = 1;
    *(u8 *)(param_1 + 0x28) = DAT_007ceaf4 | 0x14;
  }
  if (param_2 != 2) {
    *(u8 *)(param_1 + 0x28) = *(u8 *)(param_1 + 0x28) | 2;
  }
  return;
}

// FUN_004A06C0 NONMATCHING

void FUN_004a06c0(int param_1)

{
  int iVar1;
  int iVar2;
  u32 *puVar3;
  u32 *puVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  u64 uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  int aiStack_60 [4];
  u8 auStack_50 [32];
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_10;
  float fStack_c;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(iVar1 + 0x18);
  if ((*(u32 *)(iVar2 + 8) & 0x20) != 0) {
    DAT_0096007a = DAT_0096007a + 1;
    uVar8 = ((code)FUN_004cb2f0)(*(u32 *)(iVar1 + 4));
    ((code)FUN_004c32a0)(auStack_50,uVar8);
    if ((*(u32 *)((int)uVar8 + 0xc) & 3) == 3) {
      fStack_10 = 1.0;
      fStack_c = 1.0;
    }
    else {
      fStack_10 = SQRT(fStack_28 * fStack_28 + fStack_30 * fStack_30 + fStack_2c * fStack_2c);
      fStack_c = fStack_10;
      if (0.0 < fStack_10) {
        fStack_c = 1.0 / fStack_10;
      }
    }
    iVar2 = *(int *)(iVar2 + 0x54);
    aiStack_60[0] = *(int *)(*(int *)(iVar2 + 0xc) + iVar2 + 0x18) + 0xc;
    ((code)FUN_00499c20)(0x4a0430,aiStack_60);
    for (puVar3 = *(u32 **)(iVar1 + 100); puVar3 != (u32 *)(iVar1 + 100);
        puVar3 = (u32 *)*puVar3) {
      iVar2 = puVar3[2];
      for (puVar4 = *(u32 **)(iVar2 + 0x40); puVar4 != (u32 *)(iVar2 + 0x40);
          puVar4 = (u32 *)*puVar4) {
        iVar5 = puVar4[2];
        if (((iVar5 != 0) && (*(short *)(iVar5 + 0x3c) != DAT_0096007a)) &&
           ((*(u8 *)(iVar5 + 2) & 1) != 0)) {
          *(short *)(iVar5 + 0x3c) = DAT_0096007a;
          iVar6 = ((code)FUN_004cb2f0)(*(u32 *)(puVar4[2] + 4));
          pfVar7 = (float *)((code)FUN_004912b0)(iVar1);
          iVar5 = puVar4[2];
          fVar11 = pfVar7[1] - *(float *)(iVar6 + 0x34);
          fVar12 = *pfVar7 - *(float *)(iVar6 + 0x30);
          fVar9 = pfVar7[2] - *(float *)(iVar6 + 0x38);
          fVar10 = pfVar7[3] + *(float *)(iVar5 + 0x14);
          if ((fVar9 * fVar9 + fVar12 * fVar12 + fVar11 * fVar11 < fVar10 * fVar10) &&
             ((*(u8 *)(iVar5 + 2) & 1) != 0)) {
            ((code)FUN_0049ff10)(fStack_10,fStack_c,iVar5,auStack_50);
          }
        }
      }
    }
  }
  return;
}

// FUN_004A08F0 NONMATCHING

void FUN_004a08f0(int param_1,int *param_2,int param_3,u32 param_4)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x24) == 0) {
    iVar2 = *(int *)(*(int *)(param_1 + 8) + 0x18);
    if ((*(u32 *)(iVar2 + 8) & 0x2000000) == 0) {
      iVar2 = ((code)FUN_004c4930)(iVar2);
      *param_2 = iVar2;
    }
    else {
      iVar1 = (*DAT_00960178)(param_3 + 0x18,0x3050d);
      *param_2 = iVar1;
      *(u32 *)*param_2 = 0;
      *(u32 *)(*param_2 + 4) = 0;
      *(int *)(*param_2 + 0xc) = iVar2;
      *(int *)(*param_2 + 8) = param_3;
      *(int **)(*param_2 + 0x10) = param_2;
      *(u32 *)(*param_2 + 0x14) = param_4;
    }
  }
  else {
    iVar2 = ((code)FUN_004c4930)(*(u32 *)(param_1 + 8));
    *param_2 = iVar2;
  }
  return;
}

// FUN_004A09D0 NONMATCHING

u32 FUN_004a09d0(u64 param_1,u32 *param_2)

{
  int iVar1;
  float *pfVar2;
  u64 uVar3;
  int iVar4;
  int *piVar5;
  float *pfVar6;
  u8 bVar7;
  u32 uVar8;
  int iVar9;
  
  iVar4 = (int)param_1;
  iVar1 = *(int *)(iVar4 + 8);
  iVar9 = *(int *)(iVar1 + 0x18);
  *(u32 *)(iVar4 + 0xc) = *(u32 *)(iVar9 + 0x54);
  if (*(int *)(iVar9 + 0x18) == 1) {
    piVar5 = (int *)(iVar9 + iGpffffbba0);
    bVar7 = 0;
    if (((u32 *)*piVar5 != (u32 *)0x0) &&
       ((u32)*(u16 *)(*(int *)(iVar9 + 0x54) + 4) == *(u32 *)*piVar5)) {
      bVar7 = 1;
    }
    if (bVar7) {
      iVar9 = *piVar5;
    }
    else {
      piVar5 = (int *)((code)FUN_0049e5a0)(piVar5,*(u16 *)(*(int *)(iVar9 + 0x54) + 4));
      iVar9 = *piVar5;
    }
    *(int *)(iVar4 + 0x10) = iVar9;
  }
  else {
    piVar5 = (int *)(iVar1 + iGpffffbb9c);
    bVar7 = 0;
    if (((u32 *)*piVar5 != (u32 *)0x0) &&
       ((u32)*(u16 *)(*(int *)(iVar9 + 0x54) + 4) == *(u32 *)*piVar5)) {
      bVar7 = 1;
    }
    if (bVar7) {
      iVar9 = *piVar5;
    }
    else {
      piVar5 = (int *)((code)FUN_0049e5a0)(piVar5,*(u16 *)(*(int *)(iVar9 + 0x54) + 4));
      iVar9 = *piVar5;
    }
    *(int *)(iVar4 + 0x10) = iVar9;
  }
  *(u32 *)(iVar4 + 0x20) = *(u32 *)(*(int *)(iVar1 + 0x18) + 0x18);
  if (1 < *(int *)(iVar4 + 0x20)) {
    *(float *)(iVar4 + 0x1c) = *(float *)(iVar1 + 0x58) * *(float *)(iVar1 + 0x5c);
  }
  ((code)FUN_004a0480)(iVar1,param_1);
  *(u16 *)(*(int *)(iVar1 + 0x18) + 0xc) = 0;
  *(u32 *)(iVar1 + 0x4c) = *(u32 *)(iVar1 + 0x4c) & 0xfffffffe;
  iVar9 = (int)DAT_00960070 + 0x20;
  uVar3 = ((code)FUN_004cb2f0)(*(u32 *)(iVar1 + 4));
  ((code)FUN_004c2f30)(*param_2,uVar3,iVar9);
  uVar8 = 2;
  pfVar2 = (float *)((code)FUN_004912b0)(iVar1);
  iVar9 = 5;
  pfVar6 = (float *)((int)DAT_00960070 + iGpffffbdb4 + 0x60);
  do {
    if (-pfVar2[3] < (pfVar2[2] * pfVar6[2] + *pfVar2 * *pfVar6 + pfVar2[1] * pfVar6[1]) - pfVar6[3]
       ) {
      uVar8 = 1;
      break;
    }
    pfVar6 = pfVar6 + 5;
    bVar7 = iVar9 != 0;
    iVar9 = iVar9 + -1;
  } while (bVar7);
  ((code)FUN_004a05d0)(param_1,uVar8);
  *(u8 *)(iVar4 + 0x2a) = (*(u32 *)(*(int *)(iVar1 + 0x18) + 8) & 0x40) != 0;
  ((code)FUN_004a06c0)(param_1);
  return 1;
}

// FUN_004A0CE0 NONMATCHING

int FUN_004a0ce0(int param_1,int *param_2,int param_3,u32 param_4)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = *(char **)(param_1 + 8);
  if (*pcVar1 == -1) {
    if ((*(u32 *)(DAT_00960074 + 8) & 0x2000000) == 0) {
      iVar2 = ((code)FUN_004c4930)(pcVar1);
      *param_2 = iVar2;
    }
    else {
      iVar2 = (*DAT_00960178)(param_3 + 0x18,0x3050d);
      *param_2 = iVar2;
      *(u32 *)*param_2 = 0;
      *(u32 *)(*param_2 + 4) = 0;
      *(char **)(*param_2 + 0xc) = pcVar1;
      *(int *)(*param_2 + 8) = param_3;
      *(int **)(*param_2 + 0x10) = param_2;
      *(u32 *)(*param_2 + 0x14) = param_4;
    }
  }
  else {
    ((code)FUN_004a08f0)();
  }
  return *param_2;
}

// FUN_004A0DC0 NONMATCHING

void FUN_004a0dc0(int param_1)

{
  if (**(char **)(param_1 + 8) == -1) {
    ((code)FUN_004a42f0)();
  }
  else {
    ((code)FUN_004a1430)();
  }
  return;
}

// FUN_004A0E00 NONMATCHING



u64 FUN_004a0e00(int param_1)

{
  int *piVar1;
  u32 uVar2;
  u8 bVar3;
  Vec128 auVar4;
  Vec128 auVar5;
  Vec128 auVar6;
  Vec128 auVar7;
  Vec128 auVar8;
  Vec128 auVar9;
  Vec128 auVar10;
  Vec128 auVar11;
  u32 *puVar12;
  u32 in_zero_lo;
  u32 in_zero_hi;
  u32 in_zero_udw;
  u32 in_register_0000000c;
  u32 uVar13;
  u32 uVar14;
  u64 extraout_v0_udw;
  Vec128 auVar15;
  Vec128 auVar16;
  Vec128 auVar17;
  Vec128 auVar18;
  Vec128 auVar19;
  u64 extraout_v0_udw_00;
  Vec128 auVar20;
  u64 extraout_v0_udw_01;
  Vec128 auVar21;
  Vec128 auVar22;
  Vec128 auVar23;
  Vec128 auVar24;
  Vec128 auVar25;
  Vec128 auVar26;
  u64 uVar31;
  Vec128 auVar27;
  Vec128 auVar28;
  Vec128 auVar29;
  Vec128 auVar30;
  u8 bVar32;
  u32 *puVar33;
  u32 in_v1_udw;
  Vec128 auVar34;
  u32 uVar40;
  Vec128 auVar35;
  Vec128 auVar36;
  Vec128 auVar37;
  Vec128 auVar38;
  Vec128 auVar39;
  u32 uVar41;
  u32 in_a0_udw;
  Vec128 auVar42;
  Vec128 auVar43;
  Vec128 auVar44;
  Vec128 auVar45;
  u8 in_a1_qw [16];
  u32 uVar48;
  Vec128 auVar46;
  Vec128 auVar47;
  Vec128 auVar49;
  Vec128 auVar50;
  int iVar51;
  
  if (*(u32 **)(param_1 + 0x40) != (u32 *)0x0) {
    ((code)FUN_004f0f30)(**(u32 **)(param_1 + 0x40));
  }
  uVar48 = (*(u64*)((u8*)&in_a1_qw + 8));
  piVar1 = *(int **)(param_1 + 0x40);
  iVar51 = 0;
  if (piVar1 != (int *)0x0) {
    iVar51 = *piVar1;
  }
  uGpffffbdc8 = 0;
  if (iVar51 != 0) {
    bVar32 = *(u8 *)(iVar51 + 0x23) & 0xf;
    uGpffffbdc8 = (u32)(bVar32 == 1 || bVar32 == 5);
  }
  if (iVar51 != iGpffffbdcc) {
    if (iVar51 == 0) {
      uGpffffb0d0 = uGpffffb0d0 & 0xffffffffffffffef;
    }
    else {
      auVar17._8_8_ = 0;
      auVar17._0_8_ = uVar48;
      (*(u64*)((u8*)&in_a1_qw + 0)) = auVar17._8_8_;
      (*(u64*)((u8*)&in_a1_qw + 8)) = 0;
      uGpffffb0d0 = uGpffffb0d0 | 0x10;
      ((code)FUN_004f1020)(iVar51,0);
    }
    uVar48 = (*(u64*)((u8*)&in_a1_qw + 8));
    iGpffffbdcc = iVar51;
    if (piVar1 != (int *)0x0) {
      ((code)FUN_0049ca50)((char)piVar1[0x14]);
      uVar48 = (*(u64*)((u8*)&in_a1_qw + 8));
      uGpffffbd68 = (u32)((piVar1[0x14] & 0xf00U) == 0x300);
      if ((piVar1[0x14] & 0xf000U) == 0x3000) {
        uGpffffbd68 = uGpffffbd68 | 4;
      }
    }
  }
  if (uGpffffbdc8 == 0) {
    uGpffffbd50 = uGpffffbd50 & 0xfffffffffffffffe;
  }
  else {
    uGpffffbd50 = uGpffffbd50 | 1;
  }
  ((code)FUN_004d59d0)(0,0x12);
  auVar49._8_8_ = 0;
  auVar49._0_8_ = in_v1_udw;
  auVar15._8_8_ = extraout_v0_udw;
  auVar15._0_8_ = 0x1000000f;
  auVar49 = _pcpyld(auVar49 << 0x40,auVar15);
  auVar8._8_8_ = 0;
  auVar8._0_8_ = uVar48;
  auVar16._8_8_ = extraout_v0_udw;
  auVar16._0_8_ = 0x6c0103fa01000404;
  *puGpffffbd04 = auVar49._0_4_;
  puGpffffbd04[1] = auVar49._4_4_;
  puGpffffbd04[2] = auVar49._8_4_;
  puGpffffbd04[3] = auVar49._12_4_;
  auVar17 = _pcpyld(auVar16,auVar8 << 0x40);
  puGpffffbd04[4] = auVar17._0_4_;
  puGpffffbd04[5] = auVar17._4_4_;
  puGpffffbd04[6] = auVar17._8_4_;
  puGpffffbd04[7] = auVar17._12_4_;
  auVar18._8_8_ = auVar17._8_8_;
  bVar3 = *(char *)(param_1 + 0x47) != -1;
  uGpffffbdc4 = (u32)bVar3;
  if (bVar3 || uGpffffbdc8 != 0) {
    uGpffffb0d0 = uGpffffb0d0 | 0x40;
  }
  else {
    uGpffffb0d0 = uGpffffb0d0 & 0xffffffffffffffbf;
  }
  auVar50._8_8_ = auVar49._8_8_;
  auVar50._0_8_ = 0xfc007fffffffffff;
  auVar18._4_4_ = DAT_009658ac;
  auVar18._0_4_ = DAT_009658a8;
  auVar4._4_4_ = in_zero_hi;
  auVar4._0_4_ = in_zero_lo;
  auVar4._8_4_ = in_zero_udw;
  auVar4._12_4_ = in_register_0000000c;
  auVar17 = _pcpyld(auVar4,auVar50);
  auVar42._0_8_ =
       CONCAT44((*(u32*)((u8*)&DAT_009658a0 + 4)),(u32)DAT_009658a0) & (*(u64*)((u8*)&auVar17 + 0)) |
       ((long)(int)((u32)uGpffffb0d0 | (u32)*(u8 *)(param_1 + 0x29)) & 0x7ffU) << 0x2f;
  auVar42._8_8_ = in_a0_udw;
  auVar17 = _pcpyld(auVar18,auVar42);
  (*(u32*)((u8*)&DAT_009658a0 + 0)) = (*(u32*)((u8*)&auVar17 + 0));
  (*(u32*)((u8*)&DAT_009658a0 + 4)) = (*(u32*)((u8*)&auVar17 + 4));
  DAT_009658a8 = auVar17._8_4_;
  DAT_009658ac = auVar17._12_4_;
  puGpffffbd04[8] = (u32)DAT_009658a0;
  puGpffffbd04[9] = auVar17._4_4_;
  puGpffffbd04[10] = auVar17._8_4_;
  puGpffffbd04[0xb] = auVar17._12_4_;
  auVar5._8_8_ = 0;
  auVar5._0_8_ = auVar17._8_8_;
  auVar19._8_8_ = auVar18._8_8_;
  auVar19._0_8_ = 0x6c0103fb01000404;
  auVar17 = _pcpyld(auVar19,auVar5 << 0x40);
  puGpffffbd04[0xc] = auVar17._0_4_;
  puGpffffbd04[0xd] = auVar17._4_4_;
  puGpffffbd04[0xe] = auVar17._8_4_;
  puGpffffbd04[0xf] = auVar17._12_4_;
  puGpffffbd04 = puGpffffbd04 + 0x10;
  if ((uGpffffb0d0 & 0x10) == 0) {
    uVar13 = 0x3b808081;
  }
  else {
    uVar13 = 0x3b011b50;
  }
  ((code)FUN_0049cab0)(uVar13,param_1 + 0x44);
  auVar9._8_8_ = 0;
  auVar9._0_8_ = in_a0_udw;
  auVar20._8_8_ = extraout_v0_udw_00;
  auVar20._0_8_ = 0x6c0103fc01000404;
  auVar17 = _pcpyld(auVar20,auVar9 << 0x40);
  *puGpffffbd04 = auVar17._0_4_;
  puGpffffbd04[1] = auVar17._4_4_;
  puGpffffbd04[2] = auVar17._8_4_;
  puGpffffbd04[3] = auVar17._12_4_;
  puGpffffbd04 = puGpffffbd04 + 4;
  uVar31 = auVar17._8_8_;
  ((code)FUN_0049cbd0)(*(u32 *)(param_1 + 0x1c),*(u32 *)(param_1 + 0x3c));
  puVar12 = puGpffffbd04;
  bVar32 = *(u8 *)(param_1 + 0x28);
  auVar10._8_8_ = 0;
  auVar10._0_8_ = uVar48;
  auVar34._8_8_ = uVar31;
  auVar34._0_8_ = 0x6c0303fd01000404;
  uVar14 = (u32)bVar32 & 7;
  auVar17 = _pcpyld(auVar34,auVar10 << 0x40);
  *puGpffffbd04 = auVar17._0_4_;
  puGpffffbd04[1] = auVar17._4_4_;
  puGpffffbd04[2] = auVar17._8_4_;
  puGpffffbd04[3] = auVar17._12_4_;
  auVar49 = *(Vec128 *)&_DAT_00965930;
  auVar17 = *(Vec128 *)&_DAT_00965910;
  if (((iGpffffbe14 == 0) || ((bVar32 & 4) != 0)) && ((iGpffffb0f8 == 0 || ((bVar32 & 4) == 0)))) {
    puGpffffbd04[4] = DAT_00965910;
    puGpffffbd04[5] = auVar17._4_4_;
    puGpffffbd04[6] = auVar17._8_4_;
    puGpffffbd04[7] = auVar17._12_4_;
      auVar49 = *(Vec128 *)&_DAT_00965920;
    puGpffffbd04[8] = DAT_00965920;
    puGpffffbd04[9] = auVar49._4_4_;
    puGpffffbd04[10] = auVar49._8_4_;
    puGpffffbd04[0xb] = auVar49._12_4_;
    uVar40 = auVar49._8_8_;
  }
  else {
    uVar14 = uVar14 | 8;
    puGpffffbd04[4] = DAT_00965930;
    puGpffffbd04[5] = auVar49._4_4_;
    puGpffffbd04[6] = auVar49._8_4_;
    puGpffffbd04[7] = auVar49._12_4_;
      auVar17 = *(Vec128 *)&_DAT_00965940;
    puGpffffbd04[8] = DAT_00965940;
    puGpffffbd04[9] = auVar17._4_4_;
    puGpffffbd04[10] = auVar17._8_4_;
    puGpffffbd04[0xb] = auVar17._12_4_;
    uVar40 = auVar17._8_8_;
    auVar17 = auVar49;
  }
  uGpffffbe0c = 0;
  auVar43._8_8_ = auVar17._8_8_;
  uVar41 = 0;
  if (iGpffffbdbc == 3) {
    uVar41 = 0x20;
    uGpffffbe0c = 0x20;
  }
  auVar21._8_8_ = extraout_v0_udw_01;
  auVar21._0_8_ = uVar14;
  auVar43._0_8_ = (u32)uGpffffbe10 << 0x20 | uVar41;
  auVar17 = _pcpyld(auVar43,auVar21);
  puGpffffbd04[0xc] = auVar17._0_4_;
  puGpffffbd04[0xd] = auVar17._4_4_;
  puGpffffbd04[0xe] = auVar17._8_4_;
  puGpffffbd04[0xf] = auVar17._12_4_;
  puVar33 = puGpffffbd04 + 0x10;
  auVar44._8_8_ = auVar17._8_8_;
  if (*(int *)(param_1 + 0x40) == 0) {
    *puVar33 = in_zero_lo;
    puGpffffbd04[0x11] = in_zero_hi;
    puGpffffbd04[0x12] = in_zero_udw;
    puGpffffbd04[0x13] = in_register_0000000c;
    auVar29._8_8_ = extraout_v0_udw_01;
    auVar29._0_8_ = 0x5000000200000000;
    auVar11._8_8_ = 0;
    auVar11._0_8_ = uVar40;
    puGpffffbd04[0x14] = in_zero_lo;
    puGpffffbd04[0x15] = in_zero_hi;
    puGpffffbd04[0x16] = in_zero_udw;
    puGpffffbd04[0x17] = in_register_0000000c;
    auVar17 = _pcpyld(auVar29,auVar11 << 0x40);
    puGpffffbd04[0x18] = auVar17._0_4_;
    puGpffffbd04[0x19] = auVar17._4_4_;
    puGpffffbd04[0x1a] = auVar17._8_4_;
    puGpffffbd04[0x1b] = auVar17._12_4_;
    auVar45._8_8_ = auVar44._8_8_;
    auVar45._0_8_ = 0xe;
    auVar30._8_8_ = auVar17._8_8_;
    auVar38._8_8_ = uVar40;
    auVar38._0_8_ = 0x1000000000008001;
    auVar17 = _pcpyld(auVar45,auVar38);
    puGpffffbd04[0x1c] = auVar17._0_4_;
    puGpffffbd04[0x1d] = auVar17._4_4_;
    puGpffffbd04[0x1e] = auVar17._8_4_;
    puGpffffbd04[0x1f] = auVar17._12_4_;
    auVar30._0_8_ = 0x47;
    auVar39._8_8_ = auVar17._8_8_;
    auVar39._0_8_ = uGpffffbd50;
    auVar17 = _pcpyld(auVar30,auVar39);
    puGpffffbd04[0x20] = auVar17._0_4_;
    puGpffffbd04[0x21] = auVar17._4_4_;
    puGpffffbd04[0x22] = auVar17._8_4_;
    puGpffffbd04[0x23] = auVar17._12_4_;
    uVar31 = auVar17._8_8_;
  }
  else {
    auVar6._8_8_ = 0;
    auVar6._0_8_ = auVar44._8_8_;
    auVar22._8_8_ = extraout_v0_udw_01;
    auVar22._0_8_ = 0x5000000400000000;
    auVar17 = _pcpyld(auVar22,auVar6 << 0x40);
    auVar44._0_8_ = 0xe;
    *puVar33 = auVar17._0_4_;
    puGpffffbd04[0x11] = auVar17._4_4_;
    puGpffffbd04[0x12] = auVar17._8_4_;
    puGpffffbd04[0x13] = auVar17._12_4_;
    auVar23._8_8_ = auVar17._8_8_;
    auVar23._0_8_ = 0x1000000000008003;
    auVar17 = _pcpyld(auVar44,auVar23);
    puGpffffbd04[0x14] = auVar17._0_4_;
    puGpffffbd04[0x15] = auVar17._4_4_;
    puGpffffbd04[0x16] = auVar17._8_4_;
    puGpffffbd04[0x17] = auVar17._12_4_;
    auVar35._8_8_ = uVar40;
    auVar35._0_8_ = uGpffffbd50;
    auVar24._8_8_ = auVar17._8_8_;
    auVar24._0_8_ = 0x47;
    auVar17 = _pcpyld(auVar24,auVar35);
    puGpffffbd04[0x18] = auVar17._0_4_;
    puGpffffbd04[0x19] = auVar17._4_4_;
    puGpffffbd04[0x1a] = auVar17._8_4_;
    puGpffffbd04[0x1b] = auVar17._12_4_;
    auVar36._8_8_ = uVar40;
    auVar36._0_8_ = uGpffffbd70;
    auVar25._8_8_ = auVar17._8_8_;
    auVar25._0_8_ = 0x14;
    auVar17 = _pcpyld(auVar25,auVar36);
    puGpffffbd04[0x1c] = auVar17._0_4_;
    puGpffffbd04[0x1d] = auVar17._4_4_;
    puGpffffbd04[0x1e] = auVar17._8_4_;
    puGpffffbd04[0x1f] = auVar17._12_4_;
    auVar37._8_8_ = uVar40;
    auVar37._0_8_ = uGpffffbd68;
    auVar26._8_8_ = auVar17._8_8_;
    auVar26._0_8_ = 8;
    auVar17 = _pcpyld(auVar26,auVar37);
    puGpffffbd04[0x20] = auVar17._0_4_;
    puGpffffbd04[0x21] = auVar17._4_4_;
    puGpffffbd04[0x22] = auVar17._8_4_;
    puGpffffbd04[0x23] = auVar17._12_4_;
    uVar31 = auVar17._8_8_;
  }
  puGpffffbd04 = puGpffffbd04 + 0x24;
  auVar46._0_8_ = (long)(int)puVar33;
  auVar46._8_8_ = uVar48;
  *(u8 *)(param_1 + 0x2b) =
       (u8)((int)(*(u8 *)(param_1 + 0x28) & 0x20) >> 5) |
       (u8)((int)(*(u8 *)(param_1 + 0x28) & 0x18) >> 2);
  uVar2 = *(u32 *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + (u32)*(u8 *)(param_1 + 0x2b) * 4);
  if (uGpffffbe08 != uVar2) {
    auVar7._8_8_ = 0;
    auVar7._0_8_ = uVar48;
    auVar46._0_8_ = auVar7._8_8_;
    auVar46._8_8_ = 0;
    auVar27._0_8_ = (u32)uVar2 << 0x20 | 0x50000000;
    auVar27._8_8_ = uVar31;
    auVar17 = _pcpyld(auVar46,auVar27);
    *puGpffffbd04 = auVar17._0_4_;
    puVar12[0x25] = auVar17._4_4_;
    puVar12[0x26] = auVar17._8_4_;
    puVar12[0x27] = auVar17._12_4_;
    puGpffffbd04 = puVar12 + 0x28;
    uGpffffbe08 = uVar2;
  }
  auVar47._8_8_ = auVar46._8_8_;
  iVar51 = **(int **)(param_1 + 0x30);
  auVar47._0_8_ = ((long)*(int *)(*(int *)(param_1 + 4) + 0x14) | 0x2000000U) << 0x20 | 0x3000000;
  auVar28._0_8_ = (u32)*(u32 *)(iVar51 + 0x20) << 0x20 | 0x50000000;
  auVar28._8_8_ = uVar31;
  auVar17 = _pcpyld(auVar47,auVar28);
  *puGpffffbd04 = auVar17._0_4_;
  puGpffffbd04[1] = auVar17._4_4_;
  puGpffffbd04[2] = auVar17._8_4_;
  puGpffffbd04[3] = auVar17._12_4_;
  puGpffffbd04 = puGpffffbd04 + 4;
  do {
    DI();
    SYNC(0x10);
  } while ((Status & 0x10000) != 0);
  *(int *)(iVar51 + 0x18) = *(int *)(iVar51 + 0x18) + 1;
  EI();
  *(int *)(iVar51 + 0x1c) = *(int *)(iVar51 + 0x1c) + 1;
  if (*(int *)(iVar51 + 0x1c) == 1) {
    ((code)FUN_004d51c0)();
  }
  return 1;
}

// FUN_004A1430 NONMATCHING

u32 FUN_004a1430(int param_1)

{
  u8 bVar1;
  short sVar3;
  int iVar4;
  int iVar5;
  u8 bVar6;
  u8 bVar7;
  u8 *puVar8;
  u8 bVar9;
  int iVar10;
  int iVar11;
  u32 *puVar12;
  u32 *puVar13;
  int iVar14;
  u8 *puVar15;
  u8 *puVar16;
  u8 *puVar17;
  u8 *puVar18;
  int iVar19;
  int iVar20;
  u32 uVar21;
  u32 uVar22;
  u32 uVar23;
  u8 *pbVar24;
  u32 *puVar25;
  u8 *puVar26;
  int iVar27;
  int iVar28;
  float *pfVar29;
  u32 *puVar30;
  int iVar31;
  int iVar32;
  int iVar33;
  u8 bVar2;
  
  iVar33 = *(int *)(param_1 + 8);
  iVar4 = *(int *)(iVar33 + 0x18);
  iVar5 = **(int **)(param_1 + 0x30);
  uVar23 = **(u32 **)(param_1 + 0xc);
  iVar10 = *(int *)(iVar5 + 0x24);
  if ((uVar23 & 2) == 0) {
    puVar17 = (u8 *)0x7bcac4;
    puVar16 = (u8 *)0x7bcac5;
    puVar15 = (u8 *)0x7bcac6;
    bVar1 = DAT_007bcac3;
    bVar2 = DAT_007bcac2;
  }
  else {
    puVar17 = (u8 *)DAT_007bcac9;
    puVar16 = (u8 *)DAT_007bcacc;
    puVar15 = (u8 *)DAT_007bcacf;
    bVar1 = DAT_007bcac8;
    bVar2 = DAT_007bcac7;
  }
  uVar21 = (u32)bVar1;
  if ((uVar23 & 1) == 0) {
    if ((uVar23 & 8) == 0) {
      iVar19 = 0;
    }
    else {
      iVar19 = 1;
    }
  }
  else {
    iVar19 = 2;
  }
  if ((uVar23 & 0x100) == 0) {
    iVar14 = **(int **)(param_1 + 0x2c);
    puVar18 = puVar16;
    puVar16 = puVar17;
  }
  else {
    iVar14 = 0x7bcac0;
    puVar18 = puVar17;
  }
  uVar23 = *(u32 *)(param_1 + 0x34) & 0x10;
  bVar9 = 0;
  if (((uVar23 != 0) && (uVar22 = *(u32 *)(*(int *)(param_1 + 4) + 0x20), (uVar22 & 1) != 0)) &&
     ((uVar22 & 8) == 0)) {
    bVar9 = 1;
  }
  bVar6 = 0;
  if (((uVar23 != 0) && (uVar23 = *(u32 *)(*(int *)(param_1 + 4) + 0x28), (uVar23 & 1) != 0)) &&
     ((uVar23 & 8) == 0)) {
    bVar6 = 1;
  }
  bVar7 = 0;
  if ((((*(u32 *)(param_1 + 0x34) & 0x20) != 0) &&
      (uVar23 = *(u32 *)(*(int *)(param_1 + 4) + 0x48), (uVar23 & 1) != 0)) && ((uVar23 & 8) == 0))
  {
    bVar7 = 1;
  }
  iVar11 = *(int *)(iVar4 + 0x5c) + *(short *)(iVar33 + 0x50) * 0x1c;
  if (bVar9) {
    iVar27 = *(int *)(iVar4 + 0x18);
    iVar32 = *(int *)(iVar11 + 0x14);
    iVar28 = *(int *)(iVar5 + 0xb0);
    if (1 < iVar27) {
      iVar28 = *(int *)(iVar5 + 0xb4);
    }
    puVar13 = (u32 *)(*(int *)(iVar5 + 0x20) + iVar28 * 0x10);
    uVar23 = 0;
    iVar28 = iVar10;
    uVar22 = uVar21;
    while (0 < iVar28) {
      if (*(int *)(iVar5 + 0x30) < iVar28) {
        iVar31 = *(int *)(iVar5 + 0xa8);
        if (1 < iVar27) {
          iVar31 = *(int *)(iVar5 + 0xac);
        }
        iVar20 = iVar28 - (iVar31 - iVar19);
      }
      else {
        iVar20 = 0;
        puVar13 = puVar13 + *(short *)(iVar5 + 0xbc) * -4;
        iVar31 = iVar28;
      }
      puVar12 = puVar13;
      if (iVar31 == 0) {
        iVar27 = *(int *)(iVar4 + 0x18);
      }
      else {
        do {
          iVar31 = iVar31 + -1;
          iVar28 = uVar22 << ((u8)puVar18[uVar23] & 0x1f);
          pbVar24 = puVar15 + uVar23;
          iVar27 = uVar22 << ((u8)puVar16[uVar23] & 0x1f);
          uVar23 = bVar2 >> (uVar23 << 1) & 3;
          uVar22 = uVar22 + *pbVar24;
          puVar25 = (u32 *)
                    (iVar32 + (iVar27 + (u32)*(u16 *)(iVar14 + iVar28 * 2) & 0xffff) * 0xc);
          *puVar12 = *puVar25;
          puVar12[1] = puVar25[1];
          puVar12[2] = puVar25[2];
          puVar12 = puVar12 + 3;
        } while (iVar31 != 0);
        iVar27 = *(int *)(iVar4 + 0x18);
      }
      sVar3 = *(short *)(iVar5 + 0xb8);
      uVar22 = uVar22 - iVar19;
      if (1 < iVar27) {
        sVar3 = *(short *)(iVar5 + 0xba);
      }
      puVar13 = puVar13 + sVar3 * 4;
      iVar28 = iVar20;
    }
  }
  if (bVar6) {
    iVar28 = *(int *)(iVar5 + 200);
    iVar27 = *(int *)(iVar4 + 0x18);
    iVar32 = *(int *)(iVar11 + 0x14);
    if (1 < iVar27) {
      iVar28 = *(int *)(iVar5 + 0xcc);
    }
    puVar13 = (u32 *)(*(int *)(iVar5 + 0x20) + iVar28 * 0x10);
    uVar22 = 0;
    iVar28 = iVar10;
    uVar23 = uVar21;
    while (0 < iVar28) {
      if (*(int *)(iVar5 + 0x30) < iVar28) {
        iVar31 = *(int *)(iVar5 + 0xc0);
        if (1 < iVar27) {
          iVar31 = *(int *)(iVar5 + 0xc4);
        }
        iVar20 = iVar28 - (iVar31 - iVar19);
      }
      else {
        iVar20 = 0;
        puVar13 = puVar13 + *(short *)(iVar5 + 0xd4) * -4;
        iVar31 = iVar28;
      }
      puVar12 = puVar13;
      if (iVar31 == 0) {
        iVar27 = *(int *)(iVar4 + 0x18);
      }
      else {
        do {
          iVar31 = iVar31 + -1;
          iVar28 = uVar23 << ((u8)puVar18[uVar22] & 0x1f);
          pbVar24 = puVar15 + uVar22;
          iVar27 = uVar23 << ((u8)puVar16[uVar22] & 0x1f);
          uVar22 = bVar2 >> (uVar22 << 1) & 3;
          uVar23 = uVar23 + *pbVar24;
          puVar25 = (u32 *)
                    (iVar32 + (iVar27 + (u32)*(u16 *)(iVar14 + iVar28 * 2) & 0xffff) * 0xc);
          *puVar12 = *puVar25;
          puVar12[1] = puVar25[1];
          puVar12[2] = puVar25[2];
          puVar12[3] = 0;
          puVar12 = puVar12 + 4;
        } while (iVar31 != 0);
        iVar27 = *(int *)(iVar4 + 0x18);
      }
      sVar3 = *(short *)(iVar5 + 0xd0);
      uVar23 = uVar23 - iVar19;
      if (1 < iVar27) {
        sVar3 = *(short *)(iVar5 + 0xd2);
      }
      puVar13 = puVar13 + sVar3 * 4;
      iVar28 = iVar20;
    }
  }
  if (bVar7) {
    iVar32 = *(int *)(iVar5 + 0x128);
    iVar27 = *(int *)(iVar4 + 0x18);
    iVar11 = *(int *)(iVar11 + 0x18);
    if (1 < iVar27) {
      iVar32 = *(int *)(iVar5 + 300);
    }
    puVar26 = (u8 *)(*(int *)(iVar5 + 0x20) + iVar32 * 0x10);
    uVar22 = 0;
    iVar32 = iVar10;
    uVar23 = uVar21;
    while (0 < iVar32) {
      if (*(int *)(iVar5 + 0x30) < iVar32) {
        iVar28 = *(int *)(iVar5 + 0x120);
        if (1 < iVar27) {
          iVar28 = *(int *)(iVar5 + 0x124);
        }
        iVar31 = iVar32 - (iVar28 - iVar19);
      }
      else {
        iVar31 = 0;
        puVar26 = puVar26 + *(short *)(iVar5 + 0x134) * -0x10;
        iVar28 = iVar32;
      }
      if ((*(u32 *)(iVar4 + 8) & 0x10) == 0) {
        puVar8 = puVar26;
        if ((*(u32 *)(*(int *)(param_1 + 4) + 0x48) & 0x2000) == 0) {
          for (; iVar28 != 0; iVar28 = iVar28 + -1) {
            *puVar8 = 0;
            puVar8[1] = 0;
            puVar8[2] = 0;
            puVar8[3] = 0;
            puVar8 = puVar8 + 4;
          }
        }
        else {
          for (; iVar28 != 0; iVar28 = iVar28 + -1) {
            *puVar8 = 0;
            puVar8[1] = 0;
            puVar8[2] = 0;
            puVar8 = puVar8 + 3;
          }
        }
      }
      else {
        puVar8 = puVar26;
        if ((*(u32 *)(*(int *)(param_1 + 4) + 0x48) & 0x2000) == 0) {
          for (; iVar28 != 0; iVar28 = iVar28 + -1) {
            iVar32 = uVar23 << ((u8)puVar18[uVar22] & 0x1f);
            pbVar24 = puVar15 + uVar22;
            iVar27 = uVar23 << ((u8)puVar16[uVar22] & 0x1f);
            uVar22 = bVar2 >> (uVar22 << 1) & 3;
            uVar23 = uVar23 + *pbVar24;
            pfVar29 = (float *)(iVar11 + (iVar27 + (u32)*(u16 *)(iVar14 + iVar32 * 2)) * 0xc);
            *puVar8 = (char)(int)(*pfVar29 * 127.0);
            puVar8[1] = (char)(int)(pfVar29[1] * 127.0);
            puVar8[2] = (char)(int)(pfVar29[2] * 127.0);
            puVar8[3] = 0;
            puVar8 = puVar8 + 4;
          }
        }
        else {
          for (; iVar28 != 0; iVar28 = iVar28 + -1) {
            iVar32 = uVar23 << ((u8)puVar18[uVar22] & 0x1f);
            pbVar24 = puVar15 + uVar22;
            iVar27 = uVar23 << ((u8)puVar16[uVar22] & 0x1f);
            uVar22 = bVar2 >> (uVar22 << 1) & 3;
            uVar23 = uVar23 + *pbVar24;
            pfVar29 = (float *)(iVar11 + (iVar27 + (u32)*(u16 *)(iVar14 + iVar32 * 2)) * 0xc);
            *puVar8 = (char)(int)(*pfVar29 * 127.0);
            puVar8[1] = (char)(int)(pfVar29[1] * 127.0);
            puVar8[2] = (char)(int)(pfVar29[2] * 127.0);
            puVar8 = puVar8 + 3;
          }
        }
      }
      iVar27 = *(int *)(iVar4 + 0x18);
      sVar3 = *(short *)(iVar5 + 0x130);
      uVar23 = uVar23 - iVar19;
      if (1 < iVar27) {
        sVar3 = *(short *)(iVar5 + 0x132);
      }
      puVar26 = puVar26 + sVar3 * 0x10;
      iVar32 = iVar31;
    }
  }
  *(int *)(iVar5 + 0x3c) = (int)*(short *)(iVar33 + 0x50);
  *(int *)(iVar5 + 0x40) = (int)*(short *)(iVar33 + 0x52);
  *(u32 *)(iVar5 + 0x44) = *(u32 *)(iVar4 + 0x18);
  if (1 < *(int *)(iVar4 + 0x18)) {
    iVar33 = *(int *)(iVar4 + 0x5c) + *(short *)(iVar33 + 0x52) * 0x1c;
    if (bVar9) {
      uVar22 = 0;
      iVar11 = *(int *)(iVar33 + 0x14);
      puVar13 = (u32 *)(*(int *)(iVar5 + 0x20) + *(int *)(iVar5 + 0x1a4) * 0x10);
      iVar27 = iVar10;
      uVar23 = uVar21;
      while (0 < iVar27) {
        if (*(int *)(iVar5 + 0x30) < iVar27) {
          iVar32 = *(int *)(iVar5 + 0x19c);
          iVar28 = iVar27 - (iVar32 - iVar19);
        }
        else {
          iVar28 = 0;
          puVar13 = puVar13 + *(short *)(iVar5 + 0x1ac) * -4;
          iVar32 = iVar27;
        }
        puVar12 = puVar13;
        if (iVar32 == 0) {
          sVar3 = *(short *)(iVar5 + 0x1aa);
        }
        else {
          do {
            iVar32 = iVar32 + -1;
            iVar31 = uVar23 << ((u8)puVar18[uVar22] & 0x1f);
            pbVar24 = puVar15 + uVar22;
            iVar27 = uVar23 << ((u8)puVar16[uVar22] & 0x1f);
            uVar22 = bVar2 >> (uVar22 << 1) & 3;
            uVar23 = uVar23 + *pbVar24;
            puVar25 = (u32 *)
                      (iVar11 + (iVar27 + (u32)*(u16 *)(iVar14 + iVar31 * 2) & 0xffff) * 0xc);
            *puVar12 = *puVar25;
            puVar12[1] = puVar25[1];
            puVar12[2] = puVar25[2];
            puVar12 = puVar12 + 3;
          } while (iVar32 != 0);
          sVar3 = *(short *)(iVar5 + 0x1aa);
        }
        uVar23 = uVar23 - iVar19;
        puVar13 = puVar13 + sVar3 * 4;
        iVar27 = iVar28;
      }
    }
    if (bVar7) {
      uVar22 = 0;
      iVar33 = *(int *)(iVar33 + 0x18);
      puVar26 = (u8 *)(*(int *)(iVar5 + 0x20) + *(int *)(iVar5 + 0x1bc) * 0x10);
      iVar11 = iVar10;
      uVar23 = uVar21;
      while (0 < iVar11) {
        if (*(int *)(iVar5 + 0x30) < iVar11) {
          iVar27 = *(int *)(iVar5 + 0x1b4);
          iVar32 = iVar11 - (iVar27 - iVar19);
        }
        else {
          iVar32 = 0;
          puVar26 = puVar26 + *(short *)(iVar5 + 0x1c4) * -0x10;
          iVar27 = iVar11;
        }
        if ((*(u32 *)(iVar4 + 8) & 0x10) == 0) {
          puVar8 = puVar26;
          if ((*(u32 *)(*(int *)(param_1 + 4) + 0x78) & 0x2000) == 0) {
            for (; iVar27 != 0; iVar27 = iVar27 + -1) {
              *puVar8 = 0;
              puVar8[1] = 0;
              puVar8[2] = 0;
              puVar8[3] = 0;
              puVar8 = puVar8 + 4;
            }
          }
          else {
            for (; iVar27 != 0; iVar27 = iVar27 + -1) {
              *puVar8 = 0;
              puVar8[1] = 0;
              puVar8[2] = 0;
              puVar8 = puVar8 + 3;
            }
          }
        }
        else {
          puVar8 = puVar26;
          if ((*(u32 *)(*(int *)(param_1 + 4) + 0x78) & 0x2000) == 0) {
            for (; iVar27 != 0; iVar27 = iVar27 + -1) {
              iVar28 = uVar23 << ((u8)puVar18[uVar22] & 0x1f);
              pbVar24 = puVar15 + uVar22;
              iVar11 = uVar23 << ((u8)puVar16[uVar22] & 0x1f);
              uVar22 = bVar2 >> (uVar22 << 1) & 3;
              uVar23 = uVar23 + *pbVar24;
              pfVar29 = (float *)(iVar33 + (iVar11 + (u32)*(u16 *)(iVar14 + iVar28 * 2)) * 0xc);
              *puVar8 = (char)(int)(*pfVar29 * 127.0);
              puVar8[1] = (char)(int)(pfVar29[1] * 127.0);
              puVar8[2] = (char)(int)(pfVar29[2] * 127.0);
              puVar8[3] = 0;
              puVar8 = puVar8 + 4;
            }
          }
          else {
            for (; iVar27 != 0; iVar27 = iVar27 + -1) {
              iVar28 = uVar23 << ((u8)puVar18[uVar22] & 0x1f);
              pbVar24 = puVar15 + uVar22;
              iVar11 = uVar23 << ((u8)puVar16[uVar22] & 0x1f);
              uVar22 = bVar2 >> (uVar22 << 1) & 3;
              uVar23 = uVar23 + *pbVar24;
              pfVar29 = (float *)(iVar33 + (iVar11 + (u32)*(u16 *)(iVar14 + iVar28 * 2)) * 0xc);
              *puVar8 = (char)(int)(*pfVar29 * 127.0);
              puVar8[1] = (char)(int)(pfVar29[1] * 127.0);
              puVar8[2] = (char)(int)(pfVar29[2] * 127.0);
              puVar8 = puVar8 + 3;
            }
          }
        }
        uVar23 = uVar23 - iVar19;
        puVar26 = puVar26 + *(short *)(iVar5 + 0x1c2) * 0x10;
        iVar11 = iVar32;
      }
    }
  }
  if (((((*(u32 *)(param_1 + 0x34) & 0x180) != 0) &&
       (uVar23 = *(u32 *)(*(int *)(param_1 + 4) + 0x30), (uVar23 & 1) != 0)) && ((uVar23 & 8) == 0)
      ) && ((*(u32 *)(iVar4 + 8) & 0x84) != 0)) {
    iVar27 = *(int *)(iVar5 + 0xe0);
    iVar33 = *(int *)(iVar4 + 0x18);
    iVar11 = *(int *)(iVar4 + 0x34);
    if (1 < iVar33) {
      iVar27 = *(int *)(iVar5 + 0xe4);
    }
    puVar13 = (u32 *)(*(int *)(iVar5 + 0x20) + iVar27 * 0x10);
    uVar22 = 0;
    iVar27 = iVar10;
    uVar23 = uVar21;
    while (0 < iVar27) {
      if (*(int *)(iVar5 + 0x30) < iVar27) {
        iVar32 = *(int *)(iVar5 + 0xd8);
        if (1 < iVar33) {
          iVar32 = *(int *)(iVar5 + 0xdc);
        }
        iVar28 = iVar27 - (iVar32 - iVar19);
      }
      else {
        iVar28 = 0;
        puVar13 = puVar13 + *(short *)(iVar5 + 0xec) * -4;
        iVar32 = iVar27;
      }
      puVar12 = puVar13;
      if (iVar32 == 0) {
        iVar33 = *(int *)(iVar4 + 0x18);
      }
      else {
        do {
          iVar32 = iVar32 + -1;
          iVar27 = uVar23 << ((u8)puVar18[uVar22] & 0x1f);
          pbVar24 = puVar15 + uVar22;
          iVar33 = uVar23 << ((u8)puVar16[uVar22] & 0x1f);
          uVar22 = bVar2 >> (uVar22 << 1) & 3;
          uVar23 = uVar23 + *pbVar24;
          puVar25 = (u32 *)
                    (iVar11 + (iVar33 + (u32)*(u16 *)(iVar14 + iVar27 * 2) & 0xffff) * 8);
          *puVar12 = *puVar25;
          puVar12[1] = puVar25[1];
          puVar12 = puVar12 + 2;
        } while (iVar32 != 0);
        iVar33 = *(int *)(iVar4 + 0x18);
      }
      sVar3 = *(short *)(iVar5 + 0xe8);
      uVar23 = uVar23 - iVar19;
      if (1 < iVar33) {
        sVar3 = *(short *)(iVar5 + 0xea);
      }
      puVar13 = puVar13 + sVar3 * 4;
      iVar27 = iVar28;
    }
  }
  if ((((*(u32 *)(param_1 + 0x34) & 0x180) != 0) &&
      (uVar23 = *(u32 *)(*(int *)(param_1 + 4) + 0x38), (uVar23 & 1) != 0)) &&
     (((uVar23 & 8) == 0 && ((*(u32 *)(iVar4 + 8) & 0x84) != 0)))) {
    iVar33 = *(int *)(iVar4 + 0x34);
    iVar11 = iVar33;
    if ((*(u32 *)(iVar4 + 8) & 0x80) != 0) {
      iVar11 = *(int *)(iVar4 + 0x38);
    }
    iVar32 = *(int *)(iVar5 + 0xf8);
    iVar27 = *(int *)(iVar4 + 0x18);
    if (1 < iVar27) {
      iVar32 = *(int *)(iVar5 + 0xfc);
    }
    puVar13 = (u32 *)(*(int *)(iVar5 + 0x20) + iVar32 * 0x10);
    uVar22 = 0;
    iVar32 = iVar10;
    uVar23 = uVar21;
    while (0 < iVar32) {
      if (*(int *)(iVar5 + 0x30) < iVar32) {
        iVar28 = *(int *)(iVar5 + 0xf0);
        if (1 < iVar27) {
          iVar28 = *(int *)(iVar5 + 0xf4);
        }
        iVar31 = iVar32 - (iVar28 - iVar19);
      }
      else {
        iVar31 = 0;
        puVar13 = puVar13 + *(short *)(iVar5 + 0x104) * -4;
        iVar28 = iVar32;
      }
      puVar12 = puVar13;
      if (iVar28 == 0) {
        iVar27 = *(int *)(iVar4 + 0x18);
      }
      else {
        do {
          iVar28 = iVar28 + -1;
          iVar32 = uVar23 << ((u8)puVar18[uVar22] & 0x1f);
          pbVar24 = puVar15 + uVar22;
          iVar27 = uVar23 << ((u8)puVar16[uVar22] & 0x1f);
          uVar22 = bVar2 >> (uVar22 << 1) & 3;
          uVar23 = uVar23 + *pbVar24;
          iVar27 = (iVar27 + (u32)*(u16 *)(iVar14 + iVar32 * 2) & 0xffff) * 8;
          puVar30 = (u32 *)(iVar33 + iVar27);
          puVar25 = (u32 *)(iVar11 + iVar27);
          *puVar12 = *puVar30;
          puVar12[1] = puVar30[1];
          puVar12[2] = *puVar25;
          puVar12[3] = puVar25[1];
          puVar12 = puVar12 + 4;
        } while (iVar28 != 0);
        iVar27 = *(int *)(iVar4 + 0x18);
      }
      sVar3 = *(short *)(iVar5 + 0x100);
      uVar23 = uVar23 - iVar19;
      if (1 < iVar27) {
        sVar3 = *(short *)(iVar5 + 0x102);
      }
      puVar13 = puVar13 + sVar3 * 4;
      iVar32 = iVar31;
    }
  }
  if ((((*(u32 *)(param_1 + 0x34) & 0x40) != 0) &&
      (uVar23 = *(u32 *)(*(int *)(param_1 + 4) + 0x40), (uVar23 & 1) != 0)) && ((uVar23 & 8) == 0))
  {
    iVar27 = *(int *)(iVar5 + 0x110);
    iVar33 = *(int *)(iVar4 + 0x18);
    iVar11 = *(int *)(iVar4 + 0x30);
    if (1 < iVar33) {
      iVar27 = *(int *)(iVar5 + 0x114);
    }
    puVar13 = (u32 *)(*(int *)(iVar5 + 0x20) + iVar27 * 0x10);
    uVar23 = 0;
    while (0 < iVar10) {
      if (*(int *)(iVar5 + 0x30) < iVar10) {
        iVar27 = *(int *)(iVar5 + 0x108);
        if (1 < iVar33) {
          iVar27 = *(int *)(iVar5 + 0x10c);
        }
        iVar32 = iVar10 - (iVar27 - iVar19);
      }
      else {
        iVar32 = 0;
        puVar13 = puVar13 + *(short *)(iVar5 + 0x11c) * -4;
        iVar27 = iVar10;
      }
      puVar12 = puVar13;
      if ((*(u32 *)(iVar4 + 8) & 8) == 0) {
        for (; iVar27 != 0; iVar27 = iVar27 + -1) {
          *puVar12 = 0xff000000;
          puVar12 = puVar12 + 1;
        }
      }
      else {
        for (; iVar27 != 0; iVar27 = iVar27 + -1) {
          pbVar24 = puVar15 + uVar23;
          iVar33 = uVar21 << ((u8)puVar18[uVar23] & 0x1f);
          iVar10 = uVar21 << ((u8)puVar16[uVar23] & 0x1f);
          uVar23 = bVar2 >> (uVar23 << 1) & 3;
          uVar21 = uVar21 + *pbVar24;
          *puVar12 = *(u32 *)
                      (iVar11 + (iVar10 + (u32)*(u16 *)(iVar14 + iVar33 * 2) & 0xffff) * 4);
          puVar12 = puVar12 + 1;
        }
      }
      iVar33 = *(int *)(iVar4 + 0x18);
      sVar3 = *(short *)(iVar5 + 0x118);
      uVar21 = uVar21 - iVar19;
      if (1 < iVar33) {
        sVar3 = *(short *)(iVar5 + 0x11a);
      }
      puVar13 = puVar13 + sVar3 * 4;
      iVar10 = iVar32;
    }
  }
  return 1;
}

// FUN_004A24A0 NONMATCHING

void FUN_004a24a0(int param_1,int param_2)

{
  int iVar1;
  
  *(u8 **)(param_2 + 0x10) = (u8 *)gp0xffffaf20;
  *(u32 **)(param_2 + 0xc) = (u32 *)DAT_0077dec0;
  *(u32 *)(*(int *)(param_2 + 0xc) + 8) = *(u32 *)(param_1 + 0x2c);
  *(u32 *)(*(int *)(param_2 + 0xc) + 0xc) = 0;
  **(u32 **)(param_2 + 0xc) = 0;
  **(u32 **)(param_2 + 0xc) =
       **(u32 **)(param_2 + 0xc) & 0xffffff00 |
       (u32)*(u8 *)((int)(u8 *)DAT_00960094 + (u32)*(u8 *)(param_1 + 0x24) + iGpffffbb60 + 3);
  if (*(int *)(param_1 + 0x28) == 0) {
    **(u32 **)(param_2 + 0xc) = **(u32 **)(param_2 + 0xc) | 0x100;
  }
  *(u32 *)(*(int *)(param_2 + 0x10) + 4) = 0;
  iVar1 = *(int *)(param_2 + 0xc);
  *(u8 **)(iVar1 + 0x18) = (u8 *)DAT_0077dee0;
  *(u32 *)(iVar1 + 0x10) = *(u32 *)(param_1 + 0x28);
  *(u32 *)(iVar1 + 0x14) = *(u32 *)(param_1 + 0x2c);
  return;
}

// FUN_004A2560 NONMATCHING

void FUN_004a2560(u64 param_1,int *param_2)

{
  u32 *puVar1;
  u32 uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = (int)param_1;
  puVar1 = *(u32 **)(iVar4 + 8);
  ((code)FUN_004a24a0)(puVar1,param_1);
  *(u32 *)(iVar4 + 0x14) = 0x7fff8;
  if (puVar1[1] == 0) {
    *param_2 = (int)DAT_00960070 + 0x20;
  }
  else {
    ((code)FUN_004c2f30)(*param_2);
  }
  iVar3 = 1;
  if ((*puVar1 & 4) != 0) {
    iVar3 = 2;
  }
  uVar2 = **(u32 **)(iVar4 + 0xc);
  if ((uVar2 & 1) == 1) {
    *(u8 *)(iVar4 + 0x29) = 4;
    *(u8 *)(iVar4 + 0x28) = bGpffffbe04;
  }
  else if (((uVar2 & 0xff) == 0) || ((uVar2 & 2) == 2)) {
    *(u8 *)(iVar4 + 0x29) = 3;
    *(u8 *)(iVar4 + 0x28) = bGpffffbe04 | 4;
  }
  else if ((uVar2 & 0x10) == 0x10) {
    *(u8 *)(iVar4 + 0x29) = 4;
    *(u8 *)(iVar4 + 0x28) = bGpffffbe04;
  }
  else if ((uVar2 & 8) == 8) {
    *(u8 *)(iVar4 + 0x29) = 2;
    *(u8 *)(iVar4 + 0x28) = bGpffffbe04 | 0x10;
  }
  else {
    *(u8 *)(iVar4 + 0x29) = 1;
    *(u8 *)(iVar4 + 0x28) = bGpffffbe04 | 0x14;
  }
  if (iVar3 != 2) {
    *(u8 *)(iVar4 + 0x28) = *(u8 *)(iVar4 + 0x28) | 2;
  }
  *(u8 *)(iVar4 + 0x2a) = 1;
  return;
}

#pragma schedule on
// FUN_004A26D0 NONMATCHING

int FUN_004a26d0(int param_1,int *param_2,int param_3,u32 param_4)

{
  int iVar1;
  
  FUN_004d59d0_typed(0,0x80);
  iVar1 = FUN_004d5fe0_typed(param_3 + 0x18,0);
  *param_2 = iVar1;
  *(u32 *)(*(volatile int *)param_2 + 4) = 0;
  *(u32 *)*(volatile int *)param_2 = 0;
  *(u32 *)(*(volatile int *)param_2 + 0xc) = *(u32 *)(param_1 + 8);
  *(int *)(*(volatile int *)param_2 + 8) = param_3;
  *(u32 *)(*(volatile int *)param_2 + 0x10) = 0;
  *(u32 *)(*(volatile int *)param_2 + 0x14) = param_4;
  iVar1 = *(volatile int *)param_2;
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  return iVar1;
}
#pragma schedule off

// FUN_004A2BB0 NONMATCHING

u32 FUN_004a2bb0(int param_1)

{
  u8 bVar1;
  short sVar3;
  u32 *puVar4;
  int iVar5;
  u32 uVar6;
  int iVar7;
  int iVar8;
  u32 *puVar9;
  u32 *puVar10;
  int iVar11;
  u8 *puVar12;
  u8 *puVar13;
  u8 *puVar14;
  u8 *puVar15;
  int iVar16;
  u32 uVar17;
  int iVar18;
  u8 *pbVar19;
  u32 uVar20;
  u32 *puVar21;
  u8 *pbVar22;
  int iVar23;
  int iVar24;
  u32 uVar25;
  u32 uVar26;
  u32 uVar27;
  u8 bVar2;
  
  puVar4 = *(u32 **)(param_1 + 8);
  iVar5 = **(int **)(param_1 + 0x30);
  uVar6 = **(u32 **)(param_1 + 0xc);
  iVar7 = *(int *)(iVar5 + 0x24);
  if ((uVar6 & 2) == 0) {
    puVar14 = (u8 *)0x7bcae4;
    puVar13 = (u8 *)0x7bcae5;
    puVar12 = (u8 *)0x7bcae6;
    bVar1 = DAT_007bcae3;
    bVar2 = DAT_007bcae2;
  }
  else {
    puVar14 = (u8 *)DAT_007bcae9;
    puVar13 = (u8 *)DAT_007bcaec;
    puVar12 = (u8 *)DAT_007bcaef;
    bVar1 = DAT_007bcae8;
    bVar2 = DAT_007bcae7;
  }
  uVar17 = (u32)bVar1;
  if ((uVar6 & 1) == 0) {
    if ((uVar6 & 8) == 0) {
      iVar16 = 0;
    }
    else {
      iVar16 = 1;
    }
  }
  else {
    iVar16 = 2;
  }
  if ((uVar6 & 0x100) == 0) {
    iVar11 = **(int **)(param_1 + 0x2c);
    puVar15 = puVar13;
    puVar13 = puVar14;
  }
  else {
    iVar11 = 0x7bcae0;
    puVar15 = puVar14;
  }
  if (((*(u32 *)(param_1 + 0x34) & 0x10) != 0) && ((*puVar4 & 8) != 0)) {
    uVar20 = 0;
    uVar6 = puVar4[3];
    puVar10 = (u32 *)(*(int *)(iVar5 + 0x20) + *(int *)(iVar5 + 0xb0) * 0x10);
    iVar23 = iVar7;
    uVar25 = uVar17;
    while (0 < iVar23) {
      if (*(int *)(iVar5 + 0x30) < iVar23) {
        iVar18 = *(int *)(iVar5 + 0xa8);
        iVar8 = iVar23 - (iVar18 - iVar16);
      }
      else {
        iVar8 = 0;
        puVar10 = puVar10 + *(short *)(iVar5 + 0xbc) * -4;
        iVar18 = iVar23;
      }
      puVar9 = puVar10;
      if (iVar18 == 0) {
        sVar3 = *(short *)(iVar5 + 0xb8);
      }
      else {
        do {
          iVar18 = iVar18 + -1;
          iVar24 = uVar25 << ((u8)puVar15[uVar20] & 0x1f);
          pbVar19 = puVar12 + uVar20;
          iVar23 = uVar25 << ((u8)puVar13[uVar20] & 0x1f);
          uVar20 = bVar2 >> (uVar20 << 1) & 3;
          uVar25 = uVar25 + *pbVar19;
          puVar21 = (u32 *)
                    (uVar6 + (iVar23 + (u32)*(u16 *)(iVar11 + iVar24 * 2) & 0xffff) * 0x24);
          uVar26 = puVar21[1];
          uVar27 = puVar21[2];
          *puVar9 = *puVar21;
          puVar9[1] = uVar26;
          puVar9[2] = uVar27;
          puVar9 = puVar9 + 3;
        } while (iVar18 != 0);
        sVar3 = *(short *)(iVar5 + 0xb8);
      }
      uVar25 = uVar25 - iVar16;
      puVar10 = puVar10 + sVar3 * 4;
      iVar23 = iVar8;
    }
  }
  if (((*(u32 *)(param_1 + 0x34) & 0x80) != 0) && ((*puVar4 & 1) != 0)) {
    uVar25 = 0;
    uVar6 = puVar4[3];
    puVar10 = (u32 *)(*(int *)(iVar5 + 0x20) + *(int *)(iVar5 + 0xe0) * 0x10);
    iVar23 = iVar7;
    uVar20 = uVar17;
    while (0 < iVar23) {
      if (*(int *)(iVar5 + 0x30) < iVar23) {
        iVar18 = *(int *)(iVar5 + 0xd8);
        iVar8 = iVar23 - (iVar18 - iVar16);
      }
      else {
        iVar8 = 0;
        puVar10 = puVar10 + *(short *)(iVar5 + 0xec) * -4;
        iVar18 = iVar23;
      }
      puVar9 = puVar10;
      if (iVar18 == 0) {
        sVar3 = *(short *)(iVar5 + 0xe8);
      }
      else {
        do {
          iVar18 = iVar18 + -1;
          iVar24 = uVar20 << ((u8)puVar15[uVar25] & 0x1f);
          pbVar19 = puVar12 + uVar25;
          iVar23 = uVar20 << ((u8)puVar13[uVar25] & 0x1f);
          uVar25 = bVar2 >> (uVar25 << 1) & 3;
          uVar20 = uVar20 + *pbVar19;
          iVar23 = uVar6 + (iVar23 + (u32)*(u16 *)(iVar11 + iVar24 * 2) & 0xffff) * 0x24;
          *puVar9 = *(u32 *)(iVar23 + 0x1c);
          puVar9[1] = *(u32 *)(iVar23 + 0x20);
          puVar9 = puVar9 + 2;
        } while (iVar18 != 0);
        sVar3 = *(short *)(iVar5 + 0xe8);
      }
      uVar20 = uVar20 - iVar16;
      puVar10 = puVar10 + sVar3 * 4;
      iVar23 = iVar8;
    }
  }
  if (((*(u32 *)(param_1 + 0x34) & 0x40) != 0) && ((*puVar4 & 0x10) != 0)) {
    uVar20 = 0;
    uVar6 = puVar4[3];
    puVar10 = (u32 *)(*(int *)(iVar5 + 0x20) + *(int *)(iVar5 + 0x110) * 0x10);
    while (0 < iVar7) {
      if (*(int *)(iVar5 + 0x30) < iVar7) {
        iVar23 = *(int *)(iVar5 + 0x108);
        iVar18 = iVar7 - (iVar23 - iVar16);
      }
      else {
        iVar18 = 0;
        puVar10 = puVar10 + *(short *)(iVar5 + 0x11c) * -4;
        iVar23 = iVar7;
      }
      puVar9 = puVar10;
      if (iVar23 == 0) {
        sVar3 = *(short *)(iVar5 + 0x118);
      }
      else {
        do {
          iVar23 = iVar23 + -1;
          pbVar22 = puVar12 + uVar20;
          iVar8 = uVar17 << ((u8)puVar15[uVar20] & 0x1f);
          pbVar19 = puVar13 + uVar20;
          uVar20 = bVar2 >> (uVar20 << 1) & 3;
          iVar7 = uVar17 << (*pbVar19 & 0x1f);
          uVar17 = uVar17 + *pbVar22;
          *puVar9 = *(u32 *)
                     (uVar6 + (iVar7 + (u32)*(u16 *)(iVar11 + iVar8 * 2) & 0xffff) * 0x24 + 0xc)
          ;
          puVar9 = puVar9 + 1;
        } while (iVar23 != 0);
        sVar3 = *(short *)(iVar5 + 0x118);
      }
      uVar17 = uVar17 - iVar16;
      puVar10 = puVar10 + sVar3 * 4;
      iVar7 = iVar18;
    }
  }
  return 1;
}

// FUN_004A30D0 NONMATCHING

u64 FUN_004a30d0(int param_1)

{
  int iVar1;
  u32 *puVar2;
  int *piVar3;
  u64 uVar4;
  u32 uVar5;
  int iVar6;
  u32 uVar7;
  int iVar8;
  int *piVar9;
  u8 auStack_520 [32];
  u8 auStack_500 [256];
  u8 auStack_400 [256];
  u8 auStack_300 [256];
  u8 auStack_200 [256];
  u8 auStack_100 [256];
  
  iVar1 = *(int *)(param_1 + 0x14);
  iVar6 = 0;
  piVar3 = (int *)((code)FUN_004f3f70)();
  if (piVar3 == (int *)0x0) {
    *(u8 *)(iVar1 + 0xb6) = 4;
    *(u32 *)(iVar1 + 0xbc) = 0x100;
    *(u32 *)(iVar1 + 500) = 0x40;
    *(u32 *)(iVar1 + 0xb0) = 3;
  }
  else {
    *(char *)(iVar1 + 0xb6) = (char)piVar3[0xe];
    if (*(char *)(iVar1 + 0xb6) == '\0') {
      return 0;
    }
    *(int *)(iVar1 + 0xbc) = piVar3[0xc];
    *(int *)(iVar1 + 500) = piVar3[0xd];
    *(int *)(iVar1 + 0xb0) = piVar3[0xf];
    if (*(int *)(iVar1 + 0xb0) == 0) {
      *(u32 *)(iVar1 + 0xb0) = 3;
    }
    *(u8 *)(iVar1 + 0xb5) = 0;
    uVar7 = 0;
    iVar8 = iVar1;
    piVar9 = piVar3;
    do {
      puVar2 = (u32 *)*piVar9;
      if (puVar2 == (u32 *)0x0) {
        *(u32 *)(iVar8 + 0x20) = 0;
      }
      else {
        uVar5 = puVar2[2];
        iVar6 = iVar6 + 1;
        if ((uVar5 & 1) == 0) {
          if ((uVar5 & 0x10) == 0) {
            switch(uVar7) {
            case 0:
              ((code)FUN_00524270)(auStack_520,0x7cdc18);
              break;
            case 1:
              ((code)FUN_00524270)(auStack_520,0x7cdc20);
              break;
            case 2:
              ((code)FUN_00524270)(auStack_520,0x7cdc28);
              break;
            case 3:
              ((code)FUN_00524270)(auStack_520,0x7cdc2c);
              break;
            case 4:
              ((code)FUN_00524270)(auStack_520,0x7cdc30);
              break;
            case 5:
              ((code)FUN_00524270)(auStack_520,0x7cdc38);
              break;
            case 6:
              ((code)FUN_00524270)(auStack_520,0x7cdc40);
              break;
            case 7:
              ((code)FUN_00524270)(auStack_520,0x7cdc48);
              break;
            case 8:
              ((code)FUN_00524270)(auStack_520,0x7cdc50);
              break;
            case 9:
              ((code)FUN_00524270)(auStack_520,0x7cdc58);
              break;
            default:
              ((code)FUN_00524270)(auStack_520,0x77e170);
            }
            (*DAT_00960134)(auStack_500,0x77e180,auStack_520);
            return 0;
          }
          *(u32 *)(iVar8 + 0x20) = uVar5;
          uVar5 = *(u32 *)(iVar8 + 0x20) & 0xff000000;
          if (uVar5 == 0x6c000000) {
LAB_004a3208:
            *(u32 *)(iVar8 + 0x24) = 4;
          }
          else if (uVar5 == 0x68000000) {
            *(u32 *)(iVar8 + 0x24) = 3;
          }
          else if ((uVar5 == 0x6d000000) || (uVar5 == 0x64000000)) {
            *(u32 *)(iVar8 + 0x24) = 2;
          }
          else {
            if (((uVar5 != 0x65000000) && (uVar5 != 0x6e000000)) && (uVar5 != 0x60000000))
            goto LAB_004a3208;
            *(u32 *)(iVar8 + 0x24) = 1;
          }
        }
        else {
          *(u32 *)(iVar8 + 0x20) = uVar5;
          if ((puVar2[2] & 0x10) != 0) {
            (*DAT_00960134)(auStack_100,0x77df00,*puVar2);
            return 0;
          }
          uVar5 = *(u32 *)(iVar8 + 0x20) & 0xff000000;
          if (uVar5 == 0x6c000000) {
LAB_004a32d0:
            *(u32 *)(iVar8 + 0x24) = 4;
          }
          else if (uVar5 == 0x68000000) {
            *(u32 *)(iVar8 + 0x24) = 3;
          }
          else if ((uVar5 == 0x6d000000) || (uVar5 == 0x64000000)) {
            *(u32 *)(iVar8 + 0x24) = 2;
          }
          else {
            if (((uVar5 != 0x65000000) && (uVar5 != 0x6e000000)) && (uVar5 != 0x60000000))
            goto LAB_004a32d0;
            *(u32 *)(iVar8 + 0x24) = 1;
          }
          uVar5 = puVar2[2];
          if ((uVar5 & 6) == 0) {
            if (5 < uVar7) {
              (*DAT_00960134)(auStack_300,0x77e0e0,*puVar2);
              return 0;
            }
            if ((uVar5 & 8) != 0) {
              (*DAT_00960134)(auStack_400,0x77e010,*puVar2);
              return 0;
            }
          }
          else {
            if ((uVar5 & 0x2000) != 0) {
              (*DAT_00960134)(auStack_200,0x77df80,*puVar2);
              return 0;
            }
            *(u32 *)(iVar1 + (u32)*(u8 *)(iVar1 + 0xb5) * 4 + 0x80) = 0;
            *(char *)(iVar1 + 0xb5) = *(char *)(iVar1 + 0xb5) + '\x01';
          }
        }
      }
      uVar7 = uVar7 + 1;
      piVar9 = piVar9 + 1;
      iVar8 = iVar8 + 8;
    } while (uVar7 < 10);
  }
  if ((piVar3 != (int *)0x0) && (iVar6 != 0)) {
    uVar4 = ((code)FUN_0049cc70)(iVar1);
    return uVar4;
  }
  return 0;
}

// FUN_004A3540 NONMATCHING

void FUN_004a3540(int param_1)

{
  u32 *puVar1;
  long lVar2;
  
  puVar1 = *(u32 **)(param_1 + 0x14);
  lVar2 = ((code)FUN_004a30d0)();
  if (lVar2 != 0) {
    puVar1[6] = (u32)((u8 *)PTR_DAT_0077f130);
    puVar1[7] = 0x20;
    puVar1[5] = 0x114;
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[0xca] = 0x34f9;
  }
  return;
}

// FUN_004A35C0 NONMATCHING

long FUN_004a35c0(long param_1,long param_2,u32 param_3)

{
  u32 *puVar1;
  long lVar2;
  u32 *puVar3;
  u8 bVar4;
  u32 uVar5;
  int iVar6;
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else if (param_2 == 0) {
    param_1 = 0;
  }
  else if (param_3 < 10) {
    iVar6 = (int)param_2;
    switch(param_3) {
    case 0:
      if (((*(u32 *)(iVar6 + 8) & 0x68000000) == 0) ||
         (lVar2 = (*DAT_00960158)(*(u32 *)(iVar6 + 0xc),0x7cdc60), lVar2 != 0)) {
        return 0;
      }
      break;
    case 1:
      if (((*(u32 *)(iVar6 + 8) & 0x6c000000) == 0) ||
         (lVar2 = (*DAT_00960158)(*(u32 *)(iVar6 + 0xc),0x7cdc60), lVar2 != 0)) {
        return 0;
      }
      break;
    case 2:
      if (((*(u32 *)(iVar6 + 8) & 0x64000000) == 0) ||
         (lVar2 = (*DAT_00960158)(*(u32 *)(iVar6 + 0xc),0x7cdc60), lVar2 != 0)) {
        return 0;
      }
      break;
    case 3:
      if (((*(u32 *)(iVar6 + 8) & 0x6c000000) == 0) ||
         (lVar2 = (*DAT_00960158)(*(u32 *)(iVar6 + 0xc),0x7cdc60), lVar2 != 0)) {
        return 0;
      }
      break;
    case 4:
      if ((((*(u32 *)(iVar6 + 8) & 0x6e000000) == 0) || ((*(u32 *)(iVar6 + 8) & 0x4000) == 0)) ||
         (lVar2 = (*DAT_00960158)(*(u32 *)(iVar6 + 0xc),0x7cdc60), lVar2 != 0)) {
        return 0;
      }
      break;
    case 5:
      if (((*(u32 *)(iVar6 + 8) & 0x6e000000) == 0) ||
         (lVar2 = (*DAT_00960158)(*(u32 *)(iVar6 + 0xc),0x7cdc60), lVar2 != 0)) {
        return 0;
      }
    }
    lVar2 = (*DAT_00960158)(*(u32 *)(iVar6 + 0xc),0x7cdc60);
    if (lVar2 == 0) {
      lVar2 = ((code)FUN_004f3f70)(param_1);
      if (lVar2 == 0) {
        puVar1 = (u32 *)((code)FUN_004f3ec0)(param_1,0x40);
        if (puVar1 == (u32 *)0x0) {
          bVar4 = 0;
        }
        else {
          uVar5 = 0;
          puVar3 = puVar1;
          do {
            *puVar3 = 0;
            uVar5 = uVar5 + 5;
            puVar3[1] = 0;
            puVar3[2] = 0;
            puVar3[3] = 0;
            puVar3[4] = 0;
            puVar3 = puVar3 + 5;
          } while (uVar5 < 10);
          puVar1[0xf] = 0;
          puVar1[0xe] = 4;
          bVar4 = 1;
          puVar1[0xd] = puVar1[0xe] * 0x45;
          puVar1[0xc] = puVar1[0xe] * 0x45;
        }
        if (!bVar4) {
          return 0;
        }
        lVar2 = ((code)FUN_004f3f70)(param_1);
      }
      *(int *)((int)lVar2 + (int)param_3 * 4) = iVar6;
    }
  }
  else {
    param_1 = 0;
  }
  return param_1;
}

// FUN_004A38F0 NONMATCHING

long FUN_004a38f0(long param_1,long param_2,long param_3,long param_4)

{
  int iVar1;
  u32 *puVar2;
  long lVar3;
  u32 *puVar4;
  u8 bVar5;
  u32 uVar6;
  int iVar7;
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else if (param_2 < 1) {
    param_1 = 0;
  }
  else if (param_3 < 3) {
    param_1 = 0;
  }
  else if (param_4 < 1) {
    param_1 = 0;
  }
  else {
    lVar3 = ((code)FUN_004f3f70)();
    if ((lVar3 == 0) || ((*(u32 *)((int)lVar3 + 0x3c) & 0x1c) == 0)) {
      if (lVar3 == 0) {
        puVar2 = (u32 *)((code)FUN_004f3ec0)(param_1,0x40);
        if (puVar2 == (u32 *)0x0) {
          bVar5 = 0;
        }
        else {
          uVar6 = 0;
          puVar4 = puVar2;
          do {
            *puVar4 = 0;
            uVar6 = uVar6 + 5;
            puVar4[1] = 0;
            puVar4[2] = 0;
            puVar4[3] = 0;
            puVar4[4] = 0;
            puVar4 = puVar4 + 5;
          } while (uVar6 < 10);
          puVar2[0xf] = 0;
          puVar2[0xe] = 4;
          bVar5 = 1;
          puVar2[0xd] = puVar2[0xe] * 0x45;
          puVar2[0xc] = puVar2[0xe] * 0x45;
        }
        if (!bVar5) {
          return 0;
        }
        lVar3 = ((code)FUN_004f3f70)(param_1);
      }
      iVar7 = (int)param_2;
      iVar1 = (int)lVar3;
      *(int *)(iVar1 + 0x34) = iVar7 * (int)param_4 * 3;
      *(int *)(iVar1 + 0x30) = (int)param_3 * iVar7;
      *(int *)(iVar1 + 0x38) = iVar7;
      *(u32 *)(iVar1 + 0x3c) = 3;
    }
    else {
      param_1 = 0;
    }
  }
  return param_1;
}

// FUN_004A3A80 NONMATCHING

long FUN_004a3a80(long param_1,long param_2,long param_3,long param_4)

{
  int iVar1;
  u32 *puVar2;
  long lVar3;
  u32 *puVar4;
  u8 bVar5;
  u32 uVar6;
  int iVar7;
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else if (param_2 < 1) {
    param_1 = 0;
  }
  else if (param_3 < 2) {
    param_1 = 0;
  }
  else if (param_4 < 1) {
    param_1 = 0;
  }
  else {
    lVar3 = ((code)FUN_004f3f70)();
    if ((lVar3 == 0) || ((*(u32 *)((int)lVar3 + 0x3c) & 0x13) == 0)) {
      if (lVar3 == 0) {
        puVar2 = (u32 *)((code)FUN_004f3ec0)(param_1,0x40);
        if (puVar2 == (u32 *)0x0) {
          bVar5 = 0;
        }
        else {
          uVar6 = 0;
          puVar4 = puVar2;
          do {
            *puVar4 = 0;
            uVar6 = uVar6 + 5;
            puVar4[1] = 0;
            puVar4[2] = 0;
            puVar4[3] = 0;
            puVar4[4] = 0;
            puVar4 = puVar4 + 5;
          } while (uVar6 < 10);
          puVar2[0xf] = 0;
          puVar2[0xe] = 4;
          bVar5 = 1;
          puVar2[0xd] = puVar2[0xe] * 0x45;
          puVar2[0xc] = puVar2[0xe] * 0x45;
        }
        if (!bVar5) {
          return 0;
        }
        lVar3 = ((code)FUN_004f3f70)(param_1);
      }
      iVar7 = (int)param_2;
      iVar1 = (int)lVar3;
      *(int *)(iVar1 + 0x34) = iVar7 * (int)param_4 * 2;
      *(int *)(iVar1 + 0x30) = (int)param_3 * iVar7;
      *(int *)(iVar1 + 0x38) = iVar7;
      *(u32 *)(iVar1 + 0x3c) = 0xc;
    }
    else {
      param_1 = 0;
    }
  }
  return param_1;
}

// FUN_004A3C10 NONMATCHING

long FUN_004a3c10(long param_1,long param_2,long param_3)

{
  int iVar1;
  u32 *puVar2;
  long lVar3;
  u32 *puVar4;
  u8 bVar5;
  u32 uVar6;
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else if (param_2 < 1) {
    param_1 = 0;
  }
  else if (param_3 < 1) {
    param_1 = 0;
  }
  else {
    lVar3 = ((code)FUN_004f3f70)();
    if ((lVar3 == 0) || ((*(u32 *)((int)lVar3 + 0x3c) & 0xf) == 0)) {
      if (lVar3 == 0) {
        puVar2 = (u32 *)((code)FUN_004f3ec0)(param_1,0x40);
        if (puVar2 == (u32 *)0x0) {
          bVar5 = 0;
        }
        else {
          uVar6 = 0;
          puVar4 = puVar2;
          do {
            *puVar4 = 0;
            uVar6 = uVar6 + 5;
            puVar4[1] = 0;
            puVar4[2] = 0;
            puVar4[3] = 0;
            puVar4[4] = 0;
            puVar4 = puVar4 + 5;
          } while (uVar6 < 10);
          puVar2[0xf] = 0;
          puVar2[0xe] = 4;
          bVar5 = 1;
          puVar2[0xd] = puVar2[0xe] * 0x45;
          puVar2[0xc] = puVar2[0xe] * 0x45;
        }
        if (!bVar5) {
          return 0;
        }
        lVar3 = ((code)FUN_004f3f70)(param_1);
      }
      iVar1 = (int)lVar3;
      *(int *)(iVar1 + 0x34) = (int)param_3 * (int)param_2;
      *(int *)(iVar1 + 0x38) = (int)param_2;
      *(u32 *)(iVar1 + 0x3c) = 0x10;
    }
    else {
      param_1 = 0;
    }
  }
  return param_1;
}

// FUN_004A3D70 NONMATCHING

long FUN_004a3d70(long param_1,u32 param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    iVar1 = *(int *)((int)param_1 + 0x14);
    if (iVar1 == 0) {
      param_1 = 0;
    }
    else {
      *(u32 *)(iVar1 + 0x14) = param_2;
    }
  }
  return param_1;
}

// FUN_004A3DB0 NONMATCHING

long FUN_004a3db0(long param_1,long param_2,long param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    iVar1 = *(int *)(iVar2 + 0x14);
    if (iVar1 == 0) {
      param_1 = 0;
    }
    else if (param_2 == 0) {
      *(u8 ***)(iVar1 + 0x18) = (u8 **)(int)PTR_DAT_0077f130;
      *(u32 *)(*(int *)(iVar2 + 0x14) + 0x1c) = 0x20;
    }
    else {
      if (param_3 == 0) {
        return 0;
      }
      *(int *)(iVar1 + 0x18) = (int)param_2;
      *(int *)(*(int *)(iVar2 + 0x14) + 0x1c) = (int)param_3;
    }
  }
  return param_1;
}

// FUN_004A3E30 NONMATCHING

long FUN_004a3e30(long param_1,int param_2,long param_3)

{
  u32 *puVar1;
  u32 uVar2;
  
  uVar2 = (u32)param_3;
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    puVar1 = *(u32 **)((int)param_1 + 0x14);
    if (puVar1 == (u32 *)0x0) {
      param_1 = 0;
    }
    else if (param_2 == 5) {
      puVar1[4] = uVar2;
    }
    else if (param_2 == 4) {
      if (param_3 == 0) {
        param_1 = 0;
      }
      else {
        puVar1[3] = uVar2;
      }
    }
    else if (param_2 == 3) {
      if (param_3 == 0) {
        param_1 = 0;
      }
      else {
        puVar1[2] = uVar2;
      }
    }
    else if (param_2 == 2) {
      if (param_3 == 0) {
        param_1 = 0;
      }
      else {
        puVar1[1] = uVar2;
      }
    }
    else if (param_2 == 1) {
      *puVar1 = uVar2;
    }
    else {
      param_1 = 0;
    }
  }
  return param_1;
}

// FUN_004A3F10
#pragma optimization_level 3

u8 ** FUN_004a3f10(void)
{
  return PTR_s_PS2AllMat_csl_0077e1e0;
}
#pragma optimization_level 2

// FUN_004A3F20 NONMATCHING

u64 FUN_004a3f20(u64 param_1)

{
  if ((*(u8 *)((int)param_1 + 2) & 2) != 0) {
    ((code)FUN_0049ff10)(0x3f800000,0x3f800000,(int)param_1,0);
  }
  return param_1;
}

// FUN_004A3F70 NONMATCHING

void FUN_004a3f70(int param_1,u32 *param_2)

{
  u8 bVar1;
  int iVar2;
  float *pfVar3;
  
  *param_2 = 2;
  iVar2 = 5;
  pfVar3 = (float *)((int)DAT_00960070 + iGpffffbdb4 + 0x60);
  do {
    if (0.0 < (*(float *)((1 - (u32)*(u8 *)((int)pfVar3 + 0x12)) * 0xc + param_1 + 0x68) *
               pfVar3[2] +
              *(float *)((1 - (u32)*(u8 *)(pfVar3 + 4)) * 0xc + param_1 + 0x60) * *pfVar3 +
              *(float *)((1 - (u32)*(u8 *)((int)pfVar3 + 0x11)) * 0xc + param_1 + 100) *
              pfVar3[1]) - pfVar3[3]) {
      *param_2 = 1;
      return;
    }
    pfVar3 = pfVar3 + 5;
    bVar1 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  return;
}

// FUN_004A4060 NONMATCHING

u32 FUN_004a4060(int param_1,int *param_2)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  u8 bVar4;
  int iVar5;
  int *piVar6;
  int iStack_4;
  
  iVar1 = *(int *)(param_1 + 8);
  *(u32 *)(param_1 + 0xc) = *(u32 *)(iVar1 + 0x78);
  piVar6 = (int *)(iVar1 + DAT_007ce888);
  bVar4 = 0;
  if (((u32 *)*piVar6 != (u32 *)0x0) &&
     ((u32)*(u16 *)(*(int *)(param_1 + 0xc) + 4) == *(u32 *)*piVar6)) {
    bVar4 = 1;
  }
  if (bVar4) {
    iVar5 = *piVar6;
  }
  else {
    piVar6 = (int *)((code)FUN_0049e5a0)(piVar6,*(u16 *)(*(int *)(param_1 + 0xc) + 4));
    iVar5 = *piVar6;
  }
  *(int *)(param_1 + 0x10) = iVar5;
  if ((*(u32 *)(DAT_00960074 + 8) & 0x1000000) == 0) {
    *(u32 *)(param_1 + 0x18) =
         (u32)*(u16 *)(*(int *)(param_1 + 0xc) + 6) |
         (*(u32 *)(DAT_00960074 + 8) & 0x9d) << 0x10;
    *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) & 0xfffffffe;
    iVar5 = *(int *)(*(int *)(param_1 + 0x10) + 4);
    if (iVar5 != 0) {
      uVar2 = *(u32 *)(iVar5 + 0x28);
      if (*(u32 *)(param_1 + 0x18) != uVar2) {
        if ((*(u32 *)(param_1 + 0x18) >> 0x10 & 0xff) == (uVar2 >> 0x10 & 0xff)) {
          *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 4;
        }
        else {
          *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 8;
        }
      }
    }
  }
  *param_2 = (int)DAT_00960070 + 0x20;
  ((code)FUN_004a3f70)(iVar1,&iStack_4);
  uVar2 = **(u32 **)(param_1 + 0xc);
  if ((uVar2 & 1) == 1) {
    *(u8 *)(param_1 + 0x29) = 4;
    *(u8 *)(param_1 + 0x28) = DAT_007ceaf4;
  }
  else if (((uVar2 & 0xff) == 0) || ((uVar2 & 2) == 2)) {
    *(u8 *)(param_1 + 0x29) = 3;
    *(u8 *)(param_1 + 0x28) = DAT_007ceaf4 | 4;
  }
  else if ((uVar2 & 0x10) == 0x10) {
    *(u8 *)(param_1 + 0x29) = 4;
    *(u8 *)(param_1 + 0x28) = DAT_007ceaf4;
  }
  else if ((uVar2 & 8) == 8) {
    *(u8 *)(param_1 + 0x29) = 2;
    *(u8 *)(param_1 + 0x28) = DAT_007ceaf4 | 0x10;
  }
  else {
    *(u8 *)(param_1 + 0x29) = 1;
    *(u8 *)(param_1 + 0x28) = DAT_007ceaf4 | 0x14;
  }
  if (iStack_4 != 2) {
    *(u8 *)(param_1 + 0x28) = *(u8 *)(param_1 + 0x28) | 2;
  }
  *(u8 *)(param_1 + 0x2a) = (*(u32 *)(DAT_00960074 + 8) & 0x40) != 0;
  uVar3 = *(u32 *)(param_1 + 8);
  if ((*(u32 *)(DAT_00960074 + 8) & 0x20) != 0) {
    ((code)FUN_00499c20)(0x4a3f20,0);
    ((code)FUN_00499ca0)(uVar3,0x4a3f20,0);
  }
  return 1;
}

// FUN_004A42F0 NONMATCHING

u32 FUN_004a42f0(int param_1)

{
  u8 bVar1;
  short sVar3;
  int iVar4;
  int iVar5;
  u8 *puVar6;
  int iVar7;
  int iVar8;
  u32 *puVar9;
  u32 *puVar10;
  int iVar11;
  u32 uVar12;
  u32 uVar13;
  int iVar14;
  u8 *puVar15;
  u8 *pbVar16;
  u8 *puVar17;
  int iVar18;
  u8 *puVar19;
  u8 *puVar20;
  u8 *puVar21;
  u8 *puVar22;
  u32 *puVar23;
  int iVar24;
  int iVar25;
  int iVar26;
  u32 *puVar27;
  int iVar28;
  int iVar29;
  u32 uVar30;
  u8 bVar2;
  
  iVar7 = DAT_00960074;
  iVar4 = *(int *)(param_1 + 8);
  iVar5 = **(int **)(param_1 + 0x30);
  uVar13 = **(u32 **)(param_1 + 0xc);
  iVar8 = *(int *)(iVar5 + 0x24);
  if ((uVar13 & 2) == 0) {
    puVar21 = (u8 *)0x7bcb54;
    puVar20 = (u8 *)0x7bcb55;
    puVar19 = (u8 *)0x7bcb56;
    bVar1 = DAT_007bcb52;
    bVar2 = DAT_007bcb53;
  }
  else {
    puVar21 = (u8 *)DAT_007bcb59;
    puVar20 = (u8 *)DAT_007bcb5c;
    puVar19 = (u8 *)DAT_007bcb5f;
    bVar1 = DAT_007bcb57;
    bVar2 = DAT_007bcb58;
  }
  uVar30 = (u32)bVar2;
  if ((uVar13 & 1) == 0) {
    if ((uVar13 & 8) == 0) {
      iVar29 = 0;
    }
    else {
      iVar29 = 1;
    }
  }
  else {
    iVar29 = 2;
  }
  if ((uVar13 & 0x100) == 0) {
    iVar18 = **(int **)(param_1 + 0x2c);
    puVar22 = puVar20;
    puVar20 = puVar21;
  }
  else {
    iVar18 = 0x7bcb50;
    puVar22 = puVar21;
  }
  if ((((*(u32 *)(param_1 + 0x34) & 0x10) != 0) &&
      (uVar13 = *(u32 *)(*(int *)(param_1 + 4) + 0x20), (uVar13 & 1) != 0)) && ((uVar13 & 8) == 0))
  {
    uVar13 = 0;
    iVar11 = *(int *)(iVar4 + 8);
    puVar10 = (u32 *)(*(int *)(iVar5 + 0x20) + *(int *)(iVar5 + 0xb0) * 0x10);
    iVar24 = iVar8;
    uVar12 = uVar30;
    while (0 < iVar24) {
      if (*(int *)(iVar5 + 0x30) < iVar24) {
        iVar14 = *(int *)(iVar5 + 0xa8);
        iVar25 = iVar24 - (iVar14 - iVar29);
      }
      else {
        iVar25 = 0;
        puVar10 = puVar10 + *(short *)(iVar5 + 0xbc) * -4;
        iVar14 = iVar24;
      }
      puVar9 = puVar10;
      if (iVar14 == 0) {
        sVar3 = *(short *)(iVar5 + 0xb8);
      }
      else {
        do {
          iVar14 = iVar14 + -1;
          iVar26 = uVar12 << ((u8)puVar22[uVar13] & 0x1f);
          pbVar16 = puVar19 + uVar13;
          iVar24 = uVar12 << ((u8)puVar20[uVar13] & 0x1f);
          uVar13 = bVar1 >> (uVar13 << 1) & 3;
          uVar12 = uVar12 + *pbVar16;
          puVar23 = (u32 *)
                    (iVar11 + (iVar24 + (u32)*(u16 *)(iVar18 + iVar26 * 2) & 0xffff) * 0xc);
          *puVar9 = *puVar23;
          puVar9[1] = puVar23[1];
          puVar9[2] = puVar23[2];
          puVar9 = puVar9 + 3;
        } while (iVar14 != 0);
        sVar3 = *(short *)(iVar5 + 0xb8);
      }
      uVar12 = uVar12 - iVar29;
      puVar10 = puVar10 + sVar3 * 4;
      iVar24 = iVar25;
    }
  }
  if ((((*(u32 *)(param_1 + 0x34) & 0x10) != 0) &&
      (uVar13 = *(u32 *)(*(int *)(param_1 + 4) + 0x28), (uVar13 & 1) != 0)) && ((uVar13 & 8) == 0))
  {
    uVar12 = 0;
    iVar11 = *(int *)(iVar4 + 8);
    puVar10 = (u32 *)(*(int *)(iVar5 + 0x20) + *(int *)(iVar5 + 200) * 0x10);
    iVar24 = iVar8;
    uVar13 = uVar30;
    while (0 < iVar24) {
      if (*(int *)(iVar5 + 0x30) < iVar24) {
        iVar14 = *(int *)(iVar5 + 0xc0);
        iVar24 = iVar24 - (iVar14 - iVar29);
        puVar9 = puVar10;
      }
      else {
        puVar10 = puVar10 + *(short *)(iVar5 + 0xd4) * -4;
        iVar14 = iVar24;
        puVar9 = puVar10;
        iVar24 = 0;
      }
      for (; iVar14 != 0; iVar14 = iVar14 + -1) {
        iVar26 = uVar13 << ((u8)puVar22[uVar12] & 0x1f);
        pbVar16 = puVar19 + uVar12;
        iVar25 = uVar13 << ((u8)puVar20[uVar12] & 0x1f);
        uVar12 = bVar1 >> (uVar12 << 1) & 3;
        uVar13 = uVar13 + *pbVar16;
        puVar23 = (u32 *)
                  (iVar11 + (iVar25 + (u32)*(u16 *)(iVar18 + iVar26 * 2) & 0xffff) * 0xc);
        *puVar10 = *puVar23;
        puVar10[1] = puVar23[1];
        puVar10[2] = puVar23[2];
        puVar10[3] = 0;
        puVar10 = puVar10 + 4;
      }
      uVar13 = uVar13 - iVar29;
      puVar10 = puVar9 + *(short *)(iVar5 + 0xd0) * 4;
    }
  }
  if ((((*(u32 *)(param_1 + 0x34) & 0x180) != 0) &&
      (uVar13 = *(u32 *)(*(int *)(param_1 + 4) + 0x30), (uVar13 & 1) != 0)) &&
     (((uVar13 & 8) == 0 && ((*(u32 *)(iVar7 + 8) & 0x84) != 0)))) {
    uVar12 = 0;
    iVar11 = *(int *)(iVar4 + 0x10);
    puVar10 = (u32 *)(*(int *)(iVar5 + 0x20) + *(int *)(iVar5 + 0xe0) * 0x10);
    iVar24 = iVar8;
    uVar13 = uVar30;
    while (0 < iVar24) {
      if (*(int *)(iVar5 + 0x30) < iVar24) {
        iVar14 = *(int *)(iVar5 + 0xd8);
        iVar24 = iVar24 - (iVar14 - iVar29);
        puVar9 = puVar10;
      }
      else {
        puVar10 = puVar10 + *(short *)(iVar5 + 0xec) * -4;
        iVar14 = iVar24;
        puVar9 = puVar10;
        iVar24 = 0;
      }
      for (; iVar14 != 0; iVar14 = iVar14 + -1) {
        iVar26 = uVar13 << ((u8)puVar22[uVar12] & 0x1f);
        pbVar16 = puVar19 + uVar12;
        iVar25 = uVar13 << ((u8)puVar20[uVar12] & 0x1f);
        uVar12 = bVar1 >> (uVar12 << 1) & 3;
        uVar13 = uVar13 + *pbVar16;
        puVar23 = (u32 *)
                  (iVar11 + (iVar25 + (u32)*(u16 *)(iVar18 + iVar26 * 2) & 0xffff) * 8);
        *puVar10 = *puVar23;
        puVar10[1] = puVar23[1];
        puVar10 = puVar10 + 2;
      }
      uVar13 = uVar13 - iVar29;
      puVar10 = puVar9 + *(short *)(iVar5 + 0xe8) * 4;
    }
  }
  if (((((*(u32 *)(param_1 + 0x34) & 0x180) != 0) &&
       (uVar13 = *(u32 *)(*(int *)(param_1 + 4) + 0x38), (uVar13 & 1) != 0)) && ((uVar13 & 8) == 0)
      ) && ((*(u32 *)(iVar7 + 8) & 0x84) != 0)) {
    iVar11 = *(int *)(iVar4 + 0x10);
    puVar10 = (u32 *)(*(int *)(iVar5 + 0x20) + *(int *)(iVar5 + 0xf8) * 0x10);
    iVar24 = iVar11;
    if ((*(u32 *)(iVar7 + 8) & 0x80) != 0) {
      iVar24 = *(int *)(iVar4 + 0x14);
    }
    uVar12 = 0;
    iVar14 = iVar8;
    uVar13 = uVar30;
    while (0 < iVar14) {
      if (*(int *)(iVar5 + 0x30) < iVar14) {
        iVar25 = *(int *)(iVar5 + 0xf0);
        iVar26 = iVar14 - (iVar25 - iVar29);
      }
      else {
        iVar26 = 0;
        puVar10 = puVar10 + *(short *)(iVar5 + 0x104) * -4;
        iVar25 = iVar14;
      }
      puVar9 = puVar10;
      if (iVar25 == 0) {
        sVar3 = *(short *)(iVar5 + 0x100);
      }
      else {
        do {
          iVar25 = iVar25 + -1;
          iVar28 = uVar13 << ((u8)puVar22[uVar12] & 0x1f);
          pbVar16 = puVar19 + uVar12;
          iVar14 = uVar13 << ((u8)puVar20[uVar12] & 0x1f);
          uVar12 = bVar1 >> (uVar12 << 1) & 3;
          uVar13 = uVar13 + *pbVar16;
          iVar14 = (iVar14 + (u32)*(u16 *)(iVar18 + iVar28 * 2) & 0xffff) * 8;
          puVar27 = (u32 *)(iVar11 + iVar14);
          puVar23 = (u32 *)(iVar24 + iVar14);
          *puVar9 = *puVar27;
          puVar9[1] = puVar27[1];
          puVar9[2] = *puVar23;
          puVar9[3] = puVar23[1];
          puVar9 = puVar9 + 4;
        } while (iVar25 != 0);
        sVar3 = *(short *)(iVar5 + 0x100);
      }
      uVar13 = uVar13 - iVar29;
      puVar10 = puVar10 + sVar3 * 4;
      iVar14 = iVar26;
    }
  }
  if ((((*(u32 *)(param_1 + 0x34) & 0x40) != 0) &&
      (uVar13 = *(u32 *)(*(int *)(param_1 + 4) + 0x40), (uVar13 & 1) != 0)) && ((uVar13 & 8) == 0))
  {
    uVar12 = 0;
    iVar11 = *(int *)(iVar4 + 0x30);
    puVar10 = (u32 *)(*(int *)(iVar5 + 0x20) + *(int *)(iVar5 + 0x110) * 0x10);
    iVar24 = iVar8;
    uVar13 = uVar30;
    while (0 < iVar24) {
      if (*(int *)(iVar5 + 0x30) < iVar24) {
        iVar14 = *(int *)(iVar5 + 0x108);
        iVar25 = iVar24 - (iVar14 - iVar29);
      }
      else {
        iVar25 = 0;
        puVar10 = puVar10 + *(short *)(iVar5 + 0x11c) * -4;
        iVar14 = iVar24;
      }
      puVar9 = puVar10;
      if ((*(u32 *)(iVar7 + 8) & 8) == 0) {
        for (; iVar14 != 0; iVar14 = iVar14 + -1) {
          *puVar9 = 0xff000000;
          puVar9 = puVar9 + 1;
        }
      }
      else {
        for (; iVar14 != 0; iVar14 = iVar14 + -1) {
          iVar26 = uVar13 << ((u8)puVar22[uVar12] & 0x1f);
          pbVar16 = puVar19 + uVar12;
          iVar24 = uVar13 << ((u8)puVar20[uVar12] & 0x1f);
          uVar12 = bVar1 >> (uVar12 << 1) & 3;
          uVar13 = uVar13 + *pbVar16;
          *puVar9 = *(u32 *)
                     (iVar11 + (iVar24 + (u32)*(u16 *)(iVar18 + iVar26 * 2) & 0xffff) * 4);
          puVar9 = puVar9 + 1;
        }
      }
      uVar13 = uVar13 - iVar29;
      puVar10 = puVar10 + *(short *)(iVar5 + 0x118) * 4;
      iVar24 = iVar25;
    }
  }
  if ((((*(u32 *)(param_1 + 0x34) & 0x20) != 0) &&
      (uVar13 = *(u32 *)(*(int *)(param_1 + 4) + 0x48), (uVar13 & 1) != 0)) && ((uVar13 & 8) == 0))
  {
    uVar13 = 0;
    iVar4 = *(int *)(iVar4 + 0xc);
    puVar15 = (u8 *)(*(int *)(iVar5 + 0x20) + *(int *)(iVar5 + 0x128) * 0x10);
    while (0 < iVar8) {
      if (*(int *)(iVar5 + 0x30) < iVar8) {
        iVar11 = *(int *)(iVar5 + 0x120);
        iVar24 = iVar8 - (iVar11 - iVar29);
      }
      else {
        iVar24 = 0;
        puVar15 = puVar15 + *(short *)(iVar5 + 0x134) * -0x10;
        iVar11 = iVar8;
      }
      if ((*(u32 *)(iVar7 + 8) & 0x10) == 0) {
        puVar6 = puVar15;
        if ((*(u32 *)(*(int *)(param_1 + 4) + 0x48) & 0x2000) == 0) {
          for (; iVar11 != 0; iVar11 = iVar11 + -1) {
            *puVar6 = 0;
            puVar6[1] = 0;
            puVar6[2] = 0;
            puVar6[3] = 0;
            puVar6 = puVar6 + 4;
          }
        }
        else {
          for (; iVar11 != 0; iVar11 = iVar11 + -1) {
            *puVar6 = 0;
            puVar6[1] = 0;
            puVar6[2] = 0;
            puVar6 = puVar6 + 3;
          }
        }
      }
      else {
        puVar6 = puVar15;
        if ((*(u32 *)(*(int *)(param_1 + 4) + 0x48) & 0x2000) == 0) {
          for (; iVar11 != 0; iVar11 = iVar11 + -1) {
            pbVar16 = puVar19 + uVar13;
            iVar8 = uVar30 << ((u8)puVar22[uVar13] & 0x1f);
            iVar14 = uVar30 << ((u8)puVar20[uVar13] & 0x1f);
            uVar13 = bVar1 >> (uVar13 << 1) & 3;
            uVar30 = uVar30 + *pbVar16;
            puVar17 = (u8 *)(iVar4 + (iVar14 + (u32)*(u16 *)(iVar18 + iVar8 * 2)) * 4);
            *puVar6 = *puVar17;
            puVar6[1] = puVar17[1];
            puVar6[2] = puVar17[2];
            puVar6[3] = 0;
            puVar6 = puVar6 + 4;
          }
        }
        else {
          for (; iVar11 != 0; iVar11 = iVar11 + -1) {
            pbVar16 = puVar19 + uVar13;
            iVar8 = uVar30 << ((u8)puVar22[uVar13] & 0x1f);
            iVar14 = uVar30 << ((u8)puVar20[uVar13] & 0x1f);
            uVar13 = bVar1 >> (uVar13 << 1) & 3;
            uVar30 = uVar30 + *pbVar16;
            puVar17 = (u8 *)(iVar4 + (iVar14 + (u32)*(u16 *)(iVar18 + iVar8 * 2)) * 4);
            *puVar6 = *puVar17;
            puVar6[1] = puVar17[1];
            puVar6[2] = puVar17[2];
            puVar6 = puVar6 + 3;
          }
        }
      }
      uVar30 = uVar30 - iVar29;
      puVar15 = puVar15 + *(short *)(iVar5 + 0x130) * 0x10;
      iVar8 = iVar24;
    }
  }
  return 1;
}

// FUN_004A4D60 NONMATCHING

u64 FUN_004a4d60(u64 param_1,int param_2)

{
  if (*(int *)((int)param_1 + param_2) != 0) {
    ((code)FUN_0049e4f0)();
  }
  return param_1;
}

// FUN_004A4DA0 NONMATCHING

u64 FUN_004a4da0(u64 param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  u8 bVar4;
  
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + 0x54);
  if (iVar1 == 0) {
    *(u32 *)(iVar2 + DAT_007ce890) = 0;
  }
  else {
    piVar3 = (int *)(iVar2 + DAT_007ce890);
    bVar4 = 0;
    if (((u32 *)*piVar3 != (u32 *)0x0) && ((u32)*(u16 *)(iVar1 + 4) == *(u32 *)*piVar3)) {
      bVar4 = 1;
    }
    if (bVar4) {
      iVar1 = *piVar3;
    }
    else {
      piVar3 = (int *)((code)FUN_0049e5a0)(piVar3,*(u16 *)(iVar1 + 4));
      iVar1 = *piVar3;
    }
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  return param_1;
}

// FUN_004A4E40 NONMATCHING

u64 FUN_004a4e40(u64 param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  u8 bVar4;
  
  iVar2 = (int)param_1;
  iVar1 = *(int *)(*(int *)(iVar2 + 0x18) + 0x54);
  if ((iVar1 == 0) || (*(int *)(*(int *)(iVar2 + 0x18) + 0x18) < 2)) {
    *(u32 *)(iVar2 + DAT_007ce88c) = 0;
  }
  else {
    piVar3 = (int *)(iVar2 + DAT_007ce88c);
    bVar4 = 0;
    if (((u32 *)*piVar3 != (u32 *)0x0) && ((u32)*(u16 *)(iVar1 + 4) == *(u32 *)*piVar3)) {
      bVar4 = 1;
    }
    if (bVar4) {
      iVar1 = *piVar3;
    }
    else {
      piVar3 = (int *)((code)FUN_0049e5a0)(piVar3,*(u16 *)(iVar1 + 4));
      iVar1 = *piVar3;
    }
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  return param_1;
}

// FUN_004A4EF0 NONMATCHING

u64 FUN_004a4ef0(u64 param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  u8 bVar4;
  
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + 0x78);
  if (iVar1 == 0) {
    *(u32 *)(iVar2 + DAT_007ce888) = 0;
  }
  else {
    piVar3 = (int *)(iVar2 + DAT_007ce888);
    bVar4 = 0;
    if (((u32 *)*piVar3 != (u32 *)0x0) && ((u32)*(u16 *)(iVar1 + 4) == *(u32 *)*piVar3)) {
      bVar4 = 1;
    }
    if (bVar4) {
      iVar1 = *piVar3;
    }
    else {
      piVar3 = (int *)((code)FUN_0049e5a0)(piVar3,*(u16 *)(iVar1 + 4));
      iVar1 = *piVar3;
    }
    if (iVar1 == 0) {
      param_1 = 0;
    }
  }
  return param_1;
}

// FUN_004A4F90 NONMATCHING

u32 FUN_004a4f90(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  u8 bVar4;
  
  iVar2 = *(int *)(param_1 + 0x18);
  iVar1 = *(int *)(iVar2 + 0x54);
  if (iVar1 != 0) {
    if (*(int *)(iVar2 + 0x18) == 1) {
      piVar3 = (int *)(iVar2 + DAT_007ce890);
      bVar4 = 0;
      if (((u32 *)*piVar3 != (u32 *)0x0) && ((u32)*(u16 *)(iVar1 + 4) == *(u32 *)*piVar3)) {
        bVar4 = 1;
      }
      if (bVar4) {
        iVar2 = *piVar3;
      }
      else {
        piVar3 = (int *)((code)FUN_0049e5a0)(piVar3,*(u16 *)(iVar1 + 4));
        iVar2 = *piVar3;
      }
      if (iVar2 == 0) {
        return 0;
      }
    }
    else {
      piVar3 = (int *)(param_1 + DAT_007ce88c);
      bVar4 = 0;
      if (((u32 *)*piVar3 != (u32 *)0x0) && ((u32)*(u16 *)(iVar1 + 4) == *(u32 *)*piVar3)) {
        bVar4 = 1;
      }
      if (bVar4) {
        iVar2 = *piVar3;
      }
      else {
        piVar3 = (int *)((code)FUN_0049e5a0)(piVar3,*(u16 *)(iVar1 + 4));
        iVar2 = *piVar3;
      }
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  return 1;
}

// FUN_004A5080 NONMATCHING

u32 FUN_004a5080(int param_1)

{
  int iVar1;
  int *piVar2;
  u8 bVar3;
  
  iVar1 = *(int *)(param_1 + 0x78);
  if (iVar1 != 0) {
    piVar2 = (int *)(param_1 + DAT_007ce888);
    bVar3 = 0;
    if (((u32 *)*piVar2 != (u32 *)0x0) && ((u32)*(u16 *)(iVar1 + 4) == *(u32 *)*piVar2)) {
      bVar3 = 1;
    }
    if (bVar3) {
      iVar1 = *piVar2;
    }
    else {
      piVar2 = (int *)((code)FUN_0049e5a0)(piVar2,*(u16 *)(iVar1 + 4));
      iVar1 = *piVar2;
    }
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 1;
}

// FUN_004A5100 NONMATCHING

u8 FUN_004a5100(void)

{
  u32 uVar1;
  u32 uVar2;
  
  DAT_007ce890 = ((code)FUN_00493c50)(4,0x50f,0x4a4d50,0x4a4d60,0x4a4da0);
  DAT_007ce88c = ((code)FUN_00492c30)(4,0x50f,0x4a4d50,0x4a4d60,0x4a4e40);
  DAT_007ce888 = ((code)FUN_00499250)(4,0x50f,0x4a4d50,0x4a4d60,0x4a4ef0);
  uVar1 = ((code)FUN_00492cc0)(0x50f,0x4a4f90);
  uVar2 = ((code)FUN_004992b0)(0x50f,0x4a5080);
  return -1 < (int)(uVar1 | uVar2 | DAT_007ce888 | DAT_007ce890 | DAT_007ce88c);
}

#pragma optimization_level 3
// FUN_004A5200
int FUN_004a5200(void)
{
  return FUN_0049c620(0);
}
#pragma optimization_level 2

// FUN_004A5210 NONMATCHING

u32 FUN_004a5210(void)

{
  long lVar1;
  u32 uStack_8;
  u32 uStack_4;
  
  lVar1 = ((code)FUN_0046a890)(0x1001);
  *(int *)((int)(u8 *)DAT_009600cc + DAT_007ceb28) = (int)lVar1;
  if (lVar1 == 0) {
    ((code)FUN_0049c620)(0);
    uStack_8 = 2;
    uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000006,0x77e300);
    ((code)FUN_004c1c50)(&uStack_8);
  }
  else {
    ((code)FUN_0049c620)(lVar1);
  }
  return 1;
}

#pragma optimization_level 3
// FUN_004A5290
int FUN_004a5290(void)
{
  return FUN_0049c560(0);
}
#pragma optimization_level 2

// FUN_004A52A0 NONMATCHING

u32 FUN_004a52a0(void)

{
  long lVar1;
  u32 uStack_8;
  u32 uStack_4;
  
  lVar1 = ((code)FUN_0046a890)(0x1003);
  *(int *)((int)(u8 *)DAT_009600c8 + DAT_007ceb28) = (int)lVar1;
  if (lVar1 == 0) {
    ((code)FUN_0049c560)(0);
    uStack_8 = 2;
    uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000006,0x77e320);
    ((code)FUN_004c1c50)(&uStack_8);
  }
  else {
    ((code)FUN_0049c560)(lVar1);
  }
  return 1;
}

#pragma optimization_level 3
// FUN_004A5320
int FUN_004a5320(void)
{
  return FUN_0049c5c0(0);
}
#pragma optimization_level 2

// FUN_004A5330 NONMATCHING

u32 FUN_004a5330(void)

{
  long lVar1;
  u32 uStack_8;
  u32 uStack_4;
  
  lVar1 = ((code)FUN_0046a890)(0x1002);
  *(int *)((u8 *)DAT_009600c4 + DAT_007ceb28) = (int)lVar1;
  if (lVar1 == 0) {
    ((code)FUN_0049c5c0)(0);
    uStack_8 = 2;
    uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000006,0x77e340);
    ((code)FUN_004c1c50)(&uStack_8);
  }
  else {
    ((code)FUN_0049c5c0)(lVar1);
  }
  return 1;
}

// FUN_004A53B0 NONMATCHING

void FUN_004a53b0(void)

{
  ((code)FUN_004c3c30)(DAT_0095ed60);
  DAT_0095ed60 = 0;
  (*DAT_0096017c)(DAT_0095ed64);
  DAT_0095ed64 = 0;
  return;
}

#pragma schedule on
// FUN_004A5400 NONMATCHING

u32 FUN_004a5400(void)
{
  DAT_0095ed64_abs[0] = (u32)DAT_00960178_abs[0](0x2400,0x40190);
  DAT_0095ed60_abs[0] = thunk_FUN_004c3970_u32(0x78,DAT_007cdc64_abs[0],0x10,DAT_007cdc68_abs[0],0x95e7d0,0x401a2);
  return 1;
}
#pragma schedule off

// FUN_004A5470 NONMATCHING

long FUN_004a5470(void)

{
  long lVar1;
  u32 uStack_10;
  u32 uStack_c;
  u8 uStack_4;
  u8 uStack_3;
  u8 uStack_2;
  u8 uStack_1;
  
  lVar1 = (*DAT_00960188)(DAT_0095ed60,0x301a2);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else {
    ((code)FUN_00521408)(lVar1,0,0x78);
    uStack_4 = 0xff;
    uStack_3 = 0xff;
    uStack_2 = 0xff;
    uStack_1 = 0xff;
    ((code)FUN_004a5dd0)(lVar1,&uStack_4,&uStack_4,&uStack_4,&uStack_4);
    uStack_10 = 0;
    uStack_c = 0;
    ((code)FUN_004a6200)(lVar1,&uStack_10,&uStack_10,&uStack_10,&uStack_10);
    ((code)FUN_004a62e0)(lVar1,0);
    *(u32 *)((int)lVar1 + 0x70) = 0x3f000000;
    *(u32 *)((int)lVar1 + 0x74) = 1;
  }
  return lVar1;
}

// FUN_004A5540 NONMATCHING

u32 FUN_004a5540(u64 param_1)

{
  int iVar1;
  u32 uVar2;
  int iVar3;
  
  iVar3 = (int)param_1;
  iVar1 = *(int *)(iVar3 + 0x74) + -1;
  *(int *)(iVar3 + 0x74) = iVar1;
  if (iVar1 < 1) {
    if (*(int *)(iVar3 + 0x68) != 0) {
      ((code)FUN_004d0f00)();
    }
    (*DAT_0096018c)(DAT_0095ed60,param_1);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

// FUN_004A55B0 NONMATCHING

u64
FUN_004a55b0(u64 param_1,float *param_2,float *param_3,float *param_4,float *param_5,
            float *param_6,float *param_7)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  
  pfVar1 = (float *)param_1;
  fVar3 = *param_5 * *param_6 + *param_7 + 0.0;
  fVar2 = fVar3;
  if (255.0 < fVar3) {
    fVar2 = 255.0;
  }
  if (fVar2 <= 0.0) {
    *pfVar1 = 0.0;
  }
  else {
    if (255.0 < fVar3) {
      fVar3 = 255.0;
    }
    *pfVar1 = fVar3;
  }
  fVar3 = param_5[1] * param_6[1] + param_7[1] + 0.0;
  fVar2 = fVar3;
  if (255.0 < fVar3) {
    fVar2 = 255.0;
  }
  if (fVar2 <= 0.0) {
    pfVar1[1] = 0.0;
  }
  else {
    if (255.0 < fVar3) {
      fVar3 = 255.0;
    }
    pfVar1[1] = fVar3;
  }
  fVar3 = param_5[2] * param_6[2] + param_7[2] + 0.0;
  fVar2 = fVar3;
  if (255.0 < fVar3) {
    fVar2 = 255.0;
  }
  if (fVar2 <= 0.0) {
    pfVar1[2] = 0.0;
  }
  else {
    if (255.0 < fVar3) {
      fVar3 = 255.0;
    }
    pfVar1[2] = fVar3;
  }
  fVar3 = param_5[3] * param_6[3] + param_7[3] + 0.0;
  fVar2 = fVar3;
  if (255.0 < fVar3) {
    fVar2 = 255.0;
  }
  if (fVar2 <= 0.0) {
    pfVar1[3] = 0.0;
  }
  else {
    if (255.0 < fVar3) {
      fVar3 = 255.0;
    }
    pfVar1[3] = fVar3;
  }
  fVar3 = *param_4 * *param_6 + *param_7 + 0.0;
  fVar2 = fVar3;
  if (255.0 < fVar3) {
    fVar2 = 255.0;
  }
  if (fVar2 <= 0.0) {
    pfVar1[6] = 0.0;
  }
  else {
    if (255.0 < fVar3) {
      fVar3 = 255.0;
    }
    pfVar1[6] = fVar3;
  }
  fVar3 = param_4[1] * param_6[1] + param_7[1] + 0.0;
  fVar2 = fVar3;
  if (255.0 < fVar3) {
    fVar2 = 255.0;
  }
  if (fVar2 <= 0.0) {
    pfVar1[7] = 0.0;
  }
  else {
    if (255.0 < fVar3) {
      fVar3 = 255.0;
    }
    pfVar1[7] = fVar3;
  }
  fVar3 = param_4[2] * param_6[2] + param_7[2] + 0.0;
  fVar2 = fVar3;
  if (255.0 < fVar3) {
    fVar2 = 255.0;
  }
  if (fVar2 <= 0.0) {
    pfVar1[8] = 0.0;
  }
  else {
    if (255.0 < fVar3) {
      fVar3 = 255.0;
    }
    pfVar1[8] = fVar3;
  }
  fVar3 = param_4[3] * param_6[3] + param_7[3] + 0.0;
  fVar2 = fVar3;
  if (255.0 < fVar3) {
    fVar2 = 255.0;
  }
  if (fVar2 <= 0.0) {
    pfVar1[9] = 0.0;
  }
  else {
    if (255.0 < fVar3) {
      fVar3 = 255.0;
    }
    pfVar1[9] = fVar3;
  }
  fVar3 = *param_2 * *param_6 + *param_7 + 0.0;
  fVar2 = fVar3;
  if (255.0 < fVar3) {
    fVar2 = 255.0;
  }
  if (fVar2 <= 0.0) {
    pfVar1[0xc] = 0.0;
  }
  else {
    if (255.0 < fVar3) {
      fVar3 = 255.0;
    }
    pfVar1[0xc] = fVar3;
  }
  fVar3 = param_2[1] * param_6[1] + param_7[1] + 0.0;
  fVar2 = fVar3;
  if (255.0 < fVar3) {
    fVar2 = 255.0;
  }
  if (fVar2 <= 0.0) {
    pfVar1[0xd] = 0.0;
  }
  else {
    if (255.0 < fVar3) {
      fVar3 = 255.0;
    }
    pfVar1[0xd] = fVar3;
  }
  fVar3 = param_2[2] * param_6[2] + param_7[2] + 0.0;
  fVar2 = fVar3;
  if (255.0 < fVar3) {
    fVar2 = 255.0;
  }
  if (fVar2 <= 0.0) {
    pfVar1[0xe] = 0.0;
  }
  else {
    if (255.0 < fVar3) {
      fVar3 = 255.0;
    }
    pfVar1[0xe] = fVar3;
  }
  fVar3 = param_2[3] * param_6[3] + param_7[3] + 0.0;
  fVar2 = fVar3;
  if (255.0 < fVar3) {
    fVar2 = 255.0;
  }
  if (fVar2 <= 0.0) {
    pfVar1[0xf] = 0.0;
  }
  else {
    if (255.0 < fVar3) {
      fVar3 = 255.0;
    }
    pfVar1[0xf] = fVar3;
  }
  fVar3 = *param_3 * *param_6 + *param_7 + 0.0;
  fVar2 = fVar3;
  if (255.0 < fVar3) {
    fVar2 = 255.0;
  }
  if (fVar2 <= 0.0) {
    pfVar1[0x12] = 0.0;
  }
  else {
    if (255.0 < fVar3) {
      fVar3 = 255.0;
    }
    pfVar1[0x12] = fVar3;
  }
  fVar3 = param_3[1] * param_6[1] + param_7[1] + 0.0;
  fVar2 = fVar3;
  if (255.0 < fVar3) {
    fVar2 = 255.0;
  }
  if (fVar2 <= 0.0) {
    pfVar1[0x13] = 0.0;
  }
  else {
    if (255.0 < fVar3) {
      fVar3 = 255.0;
    }
    pfVar1[0x13] = fVar3;
  }
  fVar3 = param_3[2] * param_6[2] + param_7[2] + 0.0;
  fVar2 = fVar3;
  if (255.0 < fVar3) {
    fVar2 = 255.0;
  }
  if (fVar2 <= 0.0) {
    pfVar1[0x14] = 0.0;
  }
  else {
    if (255.0 < fVar3) {
      fVar3 = 255.0;
    }
    pfVar1[0x14] = fVar3;
  }
  fVar3 = param_3[3] * param_6[3] + param_7[3] + 0.0;
  fVar2 = fVar3;
  if (255.0 < fVar3) {
    fVar2 = 255.0;
  }
  if (fVar2 <= 0.0) {
    pfVar1[0x15] = 0.0;
  }
  else {
    if (255.0 < fVar3) {
      fVar3 = 255.0;
    }
    pfVar1[0x15] = fVar3;
  }
  *(char *)(pfVar1 + 0x18) = (char)(int)*pfVar1;
  *(char *)((int)pfVar1 + 0x61) = (char)(int)pfVar1[1];
  *(char *)((int)pfVar1 + 0x62) = (char)(int)pfVar1[2];
  *(char *)((int)pfVar1 + 99) = (char)(int)pfVar1[3];
  return param_1;
}

// FUN_004A5DD0 NONMATCHING
u64
FUN_004a5dd0(u64 param_1,u8 *param_2,u8 *param_3,u8 *param_4,u64 param_5)

{
  u8 *pbVar1;
  float *pfVar2;
  
  pbVar1 = (u8 *)param_5;
  pfVar2 = (float *)param_1;
  *pfVar2 = (float)*pbVar1;
  pfVar2[1] = (float)pbVar1[1];
  pfVar2[2] = (float)pbVar1[2];
  pfVar2[3] = (float)pbVar1[3];
  pfVar2[6] = (float)*param_4;
  pfVar2[7] = (float)param_4[1];
  pfVar2[8] = (float)param_4[2];
  pfVar2[9] = (float)param_4[3];
  pfVar2[6] = pfVar2[6] - *pfVar2;
  pfVar2[7] = pfVar2[7] - pfVar2[1];
  pfVar2[8] = pfVar2[8] - pfVar2[2];
  pfVar2[9] = pfVar2[9] - pfVar2[3];
  pfVar2[0xc] = (float)*param_2;
  pfVar2[0xd] = (float)param_2[1];
  pfVar2[0xe] = (float)param_2[2];
  pfVar2[0xf] = (float)param_2[3];
  pfVar2[0x12] = (float)*param_3;
  pfVar2[0x13] = (float)param_3[1];
  pfVar2[0x14] = (float)param_3[2];
  pfVar2[0x15] = (float)param_3[3];
  pfVar2[0x12] = pfVar2[0x12] - pfVar2[0xc];
  pfVar2[0x13] = pfVar2[0x13] - pfVar2[0xd];
  pfVar2[0x14] = pfVar2[0x14] - pfVar2[0xe];
  pfVar2[0x15] = pfVar2[0x15] - pfVar2[0xf];
  ((code)FUN_00521250)(pfVar2 + 0x18,param_5,4);
  return param_1;
}

// FUN_004A6200 NONMATCHING

u64
FUN_004a6200(u64 param_1,float *param_2,float *param_3,float *param_4,float *param_5)

{
  int iVar1;
  float fVar2;
  
  iVar1 = (int)param_1;
  fVar2 = param_5[1];
  *(float *)(iVar1 + 0x10) = *param_5;
  *(float *)(iVar1 + 0x14) = fVar2;
  *(float *)(iVar1 + 0x28) = *param_4 - *param_5;
  *(float *)(iVar1 + 0x2c) = param_4[1] - param_5[1];
  fVar2 = param_2[1];
  *(float *)(iVar1 + 0x40) = *param_2;
  *(float *)(iVar1 + 0x44) = fVar2;
  *(float *)(iVar1 + 0x58) = *param_3 - *param_2;
  *(float *)(iVar1 + 0x5c) = param_3[1] - param_2[1];
  if ((((*(float *)(iVar1 + 0x28) == 0.0) && (*(float *)(iVar1 + 0x2c) == 0.0)) &&
      (*(float *)(iVar1 + 0x58) == 0.0)) && (*(float *)(iVar1 + 0x5c) == 0.0)) {
    *(u32 *)(iVar1 + 100) = *(u32 *)(iVar1 + 100) & 0xfffffffd;
  }
  else {
    *(u32 *)(iVar1 + 100) = *(u32 *)(iVar1 + 100) | 2;
  }
  return param_1;
}

// FUN_004A62E0 NONMATCHING

u64 FUN_004a62e0(u64 param_1,long param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  iVar1 = (int)param_2;
  if (param_2 == 0) {
    *(u32 *)(iVar2 + 100) = *(u32 *)(iVar2 + 100) & 0xfffffffd;
  }
  else {
    *(u32 *)(iVar2 + 100) = *(u32 *)(iVar2 + 100) | 2;
    *(int *)(iVar1 + 0x54) = *(int *)(iVar1 + 0x54) + 1;
  }
  if (*(int *)(iVar2 + 0x68) != 0) {
    ((code)FUN_004d0f00)();
  }
  *(int *)(iVar2 + 0x68) = iVar1;
  return param_1;
}

// FUN_004A6360 NONMATCHING

u64 FUN_004a6360(u64 param_1,int param_2,u64 param_3)

{
  int iVar1;
  int *piVar2;
  long lVar3;
  float *pfVar4;
  float fVar5;
  
  ((code)FUN_00521250)(param_1,param_2 + 4,0x10);
  pfVar4 = (float *)param_1;
  fVar5 = *(float *)(param_2 + 0x18);
  pfVar4[4] = *(float *)(param_2 + 0x14);
  pfVar4[5] = fVar5;
  ((code)FUN_00521250)(pfVar4 + 6,param_2 + 0x1c,0x10);
  fVar5 = *(float *)(param_2 + 0x30);
  pfVar4[10] = *(float *)(param_2 + 0x2c);
  pfVar4[0xb] = fVar5;
  ((code)FUN_00521250)(pfVar4 + 0xc,param_2 + 0x34,0x10);
  fVar5 = *(float *)(param_2 + 0x48);
  pfVar4[0x10] = *(float *)(param_2 + 0x44);
  pfVar4[0x11] = fVar5;
  ((code)FUN_00521250)(pfVar4 + 0x12,param_2 + 0x4c,0x10);
  fVar5 = *(float *)(param_2 + 0x60);
  pfVar4[0x16] = *(float *)(param_2 + 0x5c);
  pfVar4[0x17] = fVar5;
  *(char *)(pfVar4 + 0x18) = (char)(int)*pfVar4;
  *(char *)((int)pfVar4 + 0x61) = (char)(int)pfVar4[1];
  *(char *)((int)pfVar4 + 0x62) = (char)(int)pfVar4[2];
  *(char *)((int)pfVar4 + 99) = (char)(int)pfVar4[3];
  pfVar4[0x19] = *(float *)(param_2 + 100);
  pfVar4[0x1c] = *(float *)(param_2 + 0x68);
  if (*(int *)(param_2 + 0x6c) != 0) {
    lVar3 = ((code)FUN_004c1600)(param_3,6,0,0);
    if (lVar3 == 0) {
      param_1 = 0;
    }
    else {
      lVar3 = ((code)FUN_004c83c0)(param_3);
      piVar2 = (int *)lVar3;
      if (((lVar3 != 0) && (iVar1 = *piVar2, iVar1 != 0)) &&
         ((*(u32 *)(iVar1 + 0x10) & *(u32 *)(iVar1 + 0x10) - 1) != 0 ||
          (*(u32 *)(iVar1 + 0xc) & *(u32 *)(iVar1 + 0xc) - 1) != 0)) {
        piVar2[0x14] = piVar2[0x14] & 0xffff00ffU | 0x3300;
      }
      pfVar4[0x1a] = (float)(int)piVar2;
      pfVar4[0x19] = (float)((u32)pfVar4[0x19] | 2);
    }
  }
  return param_1;
}

// FUN_004A6530 NONMATCHING

u64 FUN_004a6530(u64 param_1,u64 param_2)

{
  long lVar1;
  u64 uVar2;
  float *pfVar3;
  int aiStack_70 [28];
  
  lVar1 = ((code)FUN_004c5250)(param_2,aiStack_70,0x70);
  if (lVar1 == 0x70) {
    pfVar3 = (float *)param_1;
    *(char *)(pfVar3 + 0x18) = (char)(int)*pfVar3;
    *(char *)((int)pfVar3 + 0x61) = (char)(int)pfVar3[1];
    *(char *)((int)pfVar3 + 0x62) = (char)(int)pfVar3[2];
    *(char *)((int)pfVar3 + 99) = (char)(int)pfVar3[3];
    if (aiStack_70[0] == 1) {
      uVar2 = ((code)FUN_004a6360)(param_1,aiStack_70,param_2);
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

#pragma optimization_level 3
// FUN_004A6600

u64 FUN_004a6600(u64 param_1,u64 param_2)

{
  FUN_0046bd00(param_1,param_2);
  return param_1;
}
#pragma optimization_level 2

// FUN_004A6630 NONMATCHING

int FUN_004a6630(int param_1,float *param_2,int param_3,int *param_4,int *param_5)

{
  u8 uVar1;
  u8 uVar2;
  u8 uVar3;
  u32 uVar4;
  u32 uVar5;
  int iVar6;
  float fVar7;
  long lVar8;
  u32 uVar9;
  u32 *puVar10;
  u8 *puVar11;
  float *pfVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  float *pfVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  u32 uStack_80;
  int *piStack_70;
  int *piStack_60;
  int iStack_50;
  int iStack_40;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  u32 uStack_8;
  u32 uStack_4;
  
  fVar7 = param_2[0x1b];
  if (fVar7 == 0.0) {
    fVar7 = (float)((code)FUN_00494be0)();
    if (param_2[0x1a] != 0.0) {
      ((code)FUN_00494d50)(fVar7);
    }
    if (((u32)param_2[0x19] & 1) == 0) {
      uVar1 = *(u8 *)((int)param_2 + 0x61);
      uVar2 = *(u8 *)((int)param_2 + 0x62);
      uVar3 = *(u8 *)((int)param_2 + 99);
      *(u8 *)((int)fVar7 + 4) = *(u8 *)(param_2 + 0x18);
      *(u8 *)((int)fVar7 + 5) = uVar1;
      *(u8 *)((int)fVar7 + 6) = uVar2;
      *(u8 *)((int)fVar7 + 7) = uVar3;
    }
    else {
      uStack_8 = DAT_007cdc6c;
      uVar4 = uStack_8;
      (*(u8*)((u8*)&uStack_8 + 0)) = (u8)DAT_007cdc6c;
      (*(u8*)((u8*)&uStack_8 + 1)) = (u8)((u32)DAT_007cdc6c >> 8);
      (*(u8*)((u8*)&uStack_8 + 2)) = (u8)((u32)DAT_007cdc6c >> 0x10);
      (*(u8*)((u8*)&uStack_8 + 3)) = (u8)((u32)DAT_007cdc6c >> 0x18);
      *(u8 *)((int)fVar7 + 4) = (u8)uStack_8;
      *(u8 *)((int)fVar7 + 5) = (*(u8*)((u8*)&uStack_8 + 1));
      *(u8 *)((int)fVar7 + 6) = (*(u8*)((u8*)&uStack_8 + 2));
      *(u8 *)((int)fVar7 + 7) = (*(u8*)((u8*)&uStack_8 + 3));
      uStack_8 = uVar4;
    }
    param_2[0x1b] = fVar7;
  }
  else {
    *(short *)((int)fVar7 + 0x18) = *(short *)((int)fVar7 + 0x18) + 1;
  }
  uStack_4 = 0;
  iStack_40 = 0;
  iStack_50 = 0;
  piStack_60 = (int *)0x0;
  puVar10 = *(u32 **)(param_1 + 0x14);
  do {
    uVar5 = puVar10[1];
    if (uVar5 == 0xffffffff) {
      uVar5 = ((code)FUN_004c2120)(*puVar10);
    }
    iStack_40 = iStack_40 + uVar5;
    iStack_50 = iStack_50 + (uVar5 - 3);
    if (uStack_4 < uVar5) {
      uStack_4 = uVar5 - 3;
    }
    puVar10 = (u32 *)puVar10[5];
  } while (puVar10 != *(u32 **)(param_1 + 0x14));
  if (uStack_4 != 0) {
    if (DAT_0095f580 < uStack_4 * 3) {
      if (DAT_0095f57c != 0) {
        (*DAT_0096017c)();
      }
      DAT_0095f580 = 0;
      lVar8 = (*DAT_00960178)(uStack_4 * 0xc,0x30190);
      DAT_0095f57c = (u32)((int *)lVar8);
      if (lVar8 == 0) {
        return 0;
      }
      DAT_0095f580 = uStack_4 * 3;
    }
    piStack_60 = (int *)(DAT_0095f57c);
    ((code)FUN_00521408)(DAT_0095f57c,0,uStack_4 * 0xc);
  }
  if ((iStack_50 != 0) && (iStack_40 != 0)) {
    iVar13 = *param_4;
    pfVar12 = (float *)(*(int *)(*(int *)(param_3 + 0x5c) + 0x14) + iVar13 * 0xc);
    iVar14 = *(int *)(param_3 + 0x2c) + *param_5 * 8;
    pfVar16 = (float *)(*(int *)(param_3 + 0x34) + iVar13 * 8);
    puVar11 = (u8 *)(*(int *)(param_3 + 0x30) + iVar13 * 4);
    piStack_70 = *(int **)(param_1 + 0x14);
    fVar29 = DAT_0095ef58;
    do {
      fVar30 = (float)piStack_70[4];
      if (piStack_70[1] == -1) {
        iVar6 = ((code)FUN_004c2090)(*piStack_70);
      }
      else {
        iVar6 = *piStack_70;
      }
      uVar5 = piStack_70[1];
      if (uVar5 == 0xffffffff) {
        uVar5 = ((code)FUN_004c2120)(*piStack_70);
      }
      uStack_4 = uVar5 - 3;
      fStack_20 = *(float *)(iVar6 + 4);
      fStack_1c = *(float *)(iVar6 + 8);
      fStack_18 = fStack_20;
      fStack_14 = fStack_1c;
      ((code)FUN_004ac020)(piStack_70,&fStack_20);
      uVar9 = 0;
      if (uVar5 != 0) {
        do {
          fVar20 = *(float *)(iVar6 + 0x10);
          *pfVar12 = (*(float *)(iVar6 + 4) + 0.0) - *(float *)(iVar6 + 0xc) * fVar30;
          pfVar12[1] = *(float *)(iVar6 + 8) - fVar20 * fVar30;
          pfVar12[2] = fVar29;
          fVar20 = (*pfVar12 - fStack_20) * (1.0 / (fStack_18 - fStack_20));
          fVar22 = (pfVar12[1] - fStack_1c) * (1.0 / (fStack_14 - fStack_1c));
          if (((u32)param_2[0x19] & 1) == 0) {
            *puVar11 = 0xff;
            puVar11[1] = 0xff;
            puVar11[2] = 0xff;
            puVar11[3] = 0xff;
          }
          else {
            fVar25 = param_2[7];
            fVar19 = param_2[0x12] * fVar20 + param_2[0xc];
            fVar21 = param_2[0x13] * fVar20 + param_2[0xd];
            fVar27 = param_2[8];
            fVar18 = param_2[0x15] * fVar20 + param_2[0xf];
            fVar23 = param_2[9];
            fVar17 = param_2[0x14] * fVar20 + param_2[0xe];
            fVar26 = param_2[1];
            fVar28 = param_2[2];
            fVar24 = param_2[3];
            *puVar11 = (char)(int)(((param_2[6] * fVar20 + *param_2) - fVar19) * fVar22 + fVar19);
            puVar11[1] = (char)(int)(((fVar25 * fVar20 + fVar26) - fVar21) * fVar22 + fVar21);
            puVar11[2] = (char)(int)(((fVar27 * fVar20 + fVar28) - fVar17) * fVar22 + fVar17);
            puVar11[3] = (char)(int)(((fVar23 * fVar20 + fVar24) - fVar18) * fVar22 + fVar18);
          }
          puVar11 = puVar11 + 4;
          if (param_2[0x1a] != 0.0) {
            fVar17 = param_2[0xb];
            fVar21 = param_2[0x16] * fVar20 + param_2[0x10];
            fVar19 = param_2[0x17] * fVar20 + param_2[0x11];
            fVar18 = param_2[5];
            *pfVar16 = ((param_2[10] * fVar20 + param_2[4]) - fVar21) * fVar22 + fVar21;
            pfVar16[1] = ((fVar17 * fVar20 + fVar18) - fVar19) * fVar22 + fVar19;
            pfVar16 = pfVar16 + 2;
          }
          uVar9 = uVar9 + 1;
          iVar6 = iVar6 + 0x18;
          pfVar12 = pfVar12 + 3;
        } while (uVar9 < uVar5);
      }
      ((code)FUN_004b0fa0)(piStack_70,&uStack_4,piStack_60);
      uStack_80 = 0;
      piVar15 = piStack_60;
      if (uVar5 != 3) {
        do {
          ((code)FUN_00493210)(param_3,iVar14,iVar13 + *piVar15 & 0xffff,iVar13 + piVar15[1] & 0xffff,
                       iVar13 + piVar15[2] & 0xffff);
          ((code)FUN_00493230)(param_3,iVar14,fVar7);
          iVar14 = iVar14 + 8;
          uStack_80 = uStack_80 + 1;
          piVar15 = piVar15 + 3;
        } while (uStack_80 < uVar5 - 3);
      }
      piStack_70 = (int *)piStack_70[5];
      iVar13 = iVar13 + uVar5;
    } while (piStack_70 != *(int **)(param_1 + 0x14));
  }
  ((code)FUN_00494cc0)(fVar7);
  *param_4 = *param_4 + iStack_40;
  *param_5 = *param_5 + iStack_50;
  return param_1;
}

// FUN_004A6CE0 NONMATCHING

long FUN_004a6ce0(u32 param_1,long param_2,u8 *param_3,u32 *param_4,
                 u64 param_5)

{
  u8 bVar1;
  int iVar2;
  long lVar3;
  u32 uVar4;
  int iVar5;
  float *pfVar6;
  u32 uVar7;
  int iVar8;
  int iVar9;
  
  if (param_2 != 0) {
    iVar9 = (int)param_2;
    iVar2 = ((code)FUN_004c2090)(*(u32 *)(iVar9 + 0x134));
    bVar1 = (*(u32 *)(iVar9 + 0x10) & 2) == 0;
    if (bVar1) {
      iVar8 = 1;
      uVar7 = 0;
    }
    else {
      iVar8 = 2;
      uVar7 = 0xff;
    }
    bVar1 = !bVar1;
    ((code)FUN_004aaa60)();
    ((code)FUN_004aae00)(*param_4,param_4[1]);
    ((code)FUN_004aada0)(param_1,param_1);
    ((code)FUN_004aae00)(0,-*(float *)(iVar9 + 8));
    uVar4 = (u32)*param_3 | (uVar7 & param_3[bVar1]) << 8;
    while (uVar4 != 0) {
      if (uVar4 < 0x80) {
        lVar3 = (long)*(short *)(iVar9 + uVar4 * 2 + 0x24);
      }
      else {
        iVar5 = uVar4 - *(int *)(iVar9 + 0x124);
        if ((iVar5 < 0) || (*(int *)(iVar9 + 0x128) <= iVar5)) {
          lVar3 = -1;
        }
        else {
          lVar3 = (long)*(short *)(*(int *)(iVar9 + 300) + iVar5 * 2);
        }
      }
      param_3 = param_3 + iVar8;
      if ((-1 < lVar3) && (pfVar6 = (float *)(iVar2 + (int)lVar3 * 0x20), pfVar6[1] == 0.0)) {
        ((code)FUN_004aae00)(*pfVar6 + *(float *)(iVar9 + 0xc),0);
      }
      uVar4 = (u32)*param_3 | (uVar7 & param_3[bVar1]) << 8;
    }
    ((code)FUN_004aad50)();
  }
  return param_2;
}

// FUN_004A6EB0 NONMATCHING

long FUN_004a6eb0(float param_1,long param_2,u8 *param_3,float *param_4,float *param_5)

{
  u8 bVar1;
  int iVar2;
  float *pfVar3;
  u64 uVar4;
  u32 uVar5;
  int iVar6;
  long lVar7;
  u32 uVar8;
  float *pfVar9;
  int iVar10;
  float fVar11;
  int iVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  int iStack_60;
  
  if (param_2 != 0) {
    iVar12 = (int)param_2;
    fVar21 = DAT_0095ef58;
    iVar2 = ((code)FUN_004c2090)(*(u32 *)(iVar12 + 0x134));
    bVar1 = (*(u32 *)(iVar12 + 0x10) & 2) == 0;
    if (bVar1) {
      uVar8 = 0;
      iStack_60 = 1;
    }
    else {
      uVar8 = 0xff;
      iStack_60 = 2;
    }
    bVar1 = !bVar1;
    ((code)FUN_004aaa60)();
    ((code)FUN_004aae00)(*param_4,param_4[1]);
    ((code)FUN_004aada0)(param_1,param_1);
    ((code)FUN_004aae00)(0,-*(float *)(iVar12 + 8));
    uVar4 = ((code)FUN_004aae60)();
    fVar14 = (float)((code)FUN_004a9560)(0x3f800000,param_2,param_3);
    fVar22 = 0.0;
    fVar11 = 0.0;
    iVar10 = 0;
    fVar14 = 1.0 / fVar14;
    fVar23 = 0.0;
    uVar5 = (u32)*param_3 | (uVar8 & param_3[bVar1]) << 8;
    pfVar3 = (float *)DAT_0095ed64;
    while (uVar5 != 0) {
      if (uVar5 < 0x80) {
        lVar7 = (long)*(short *)(iVar12 + uVar5 * 2 + 0x24);
      }
      else {
        iVar6 = uVar5 - *(int *)(iVar12 + 0x124);
        if ((iVar6 < 0) || (*(int *)(iVar12 + 0x128) <= iVar6)) {
          lVar7 = -1;
        }
        else {
          lVar7 = (long)*(short *)(*(int *)(iVar12 + 300) + iVar6 * 2);
        }
      }
      param_3 = param_3 + iStack_60;
      if (-1 < lVar7) {
        pfVar9 = (float *)(iVar2 + (int)lVar7 * 0x20);
        if ((pfVar9[1] != fVar11) || (0x17a < iVar10)) {
          if ((iVar10 != 0) &&
             (lVar7 = ((code)FUN_004f1ed0)(DAT_0095ed64,((int)pfVar3 - (int)DAT_0095ed64) / 0x24,uVar4,5),
             lVar7 != 0)) {
            ((code)FUN_004f1fd0)(3,0x95ea60,iVar10);
            ((code)FUN_004f1f80)();
          }
          if (pfVar9[1] != fVar11) {
            (*DAT_00960090)(9,*(u8 *)((int)(u32)pfVar9[1] + 0x50));
            (*DAT_00960090)(1,(u32)pfVar9[1]);
            fVar11 = pfVar9[1];
          }
          pfVar3 = (float *)DAT_0095ed64;
          if ((param_5[0x1a] != 0.0) && (((u32)param_5[0x19] & 2) != 0)) {
            param_5[0x19] = (float)((u32)param_5[0x19] & 0xfffffffd);
          }
        }
        *pfVar3 = fVar23;
        pfVar3[1] = 0.0;
        pfVar3[2] = fVar21;
        pfVar3[7] = pfVar9[2];
        pfVar3[8] = pfVar9[5];
        if (((u32)param_5[0x19] & 1) == 0) {
          *(u8 *)(pfVar3 + 3) = *(u8 *)(param_5 + 0x18);
          *(u8 *)((int)pfVar3 + 0xd) = *(u8 *)((int)param_5 + 0x61);
          *(u8 *)((int)pfVar3 + 0xe) = *(u8 *)((int)param_5 + 0x62);
          *(u8 *)((int)pfVar3 + 0xf) = *(u8 *)((int)param_5 + 99);
        }
        else {
          fVar20 = fVar22 * fVar14;
          fVar18 = param_5[0x13];
          fVar15 = param_5[0xd];
          fVar19 = param_5[0x14];
          fVar17 = param_5[0x15];
          fVar13 = param_5[0xe];
          fVar16 = param_5[0xf];
          *(char *)(pfVar3 + 3) = (char)(int)(param_5[0x12] * fVar20 + param_5[0xc]);
          *(char *)((int)pfVar3 + 0xd) = (char)(int)(fVar18 * fVar20 + fVar15);
          *(char *)((int)pfVar3 + 0xe) = (char)(int)(fVar19 * fVar20 + fVar13);
          *(char *)((int)pfVar3 + 0xf) = (char)(int)(fVar17 * fVar20 + fVar16);
        }
        pfVar3[9] = fVar23;
        pfVar3[10] = 1.0;
        pfVar3[0xb] = fVar21;
        pfVar3[0x10] = pfVar9[2];
        pfVar3[0x11] = pfVar9[3];
        if (((u32)param_5[0x19] & 1) == 0) {
          *(u8 *)(pfVar3 + 0xc) = *(u8 *)(param_5 + 0x18);
          *(u8 *)((int)pfVar3 + 0x31) = *(u8 *)((int)param_5 + 0x61);
          *(u8 *)((int)pfVar3 + 0x32) = *(u8 *)((int)param_5 + 0x62);
          *(u8 *)((int)pfVar3 + 0x33) = *(u8 *)((int)param_5 + 99);
        }
        else {
          fVar20 = fVar22 * fVar14;
          fVar18 = param_5[7];
          fVar15 = param_5[1];
          fVar19 = param_5[8];
          fVar17 = param_5[9];
          fVar13 = param_5[2];
          fVar16 = param_5[3];
          *(char *)(pfVar3 + 0xc) = (char)(int)(param_5[6] * fVar20 + *param_5);
          *(char *)((int)pfVar3 + 0x31) = (char)(int)(fVar18 * fVar20 + fVar15);
          *(char *)((int)pfVar3 + 0x32) = (char)(int)(fVar19 * fVar20 + fVar13);
          *(char *)((int)pfVar3 + 0x33) = (char)(int)(fVar17 * fVar20 + fVar16);
        }
        pfVar3[0x12] = fVar23 + *pfVar9;
        pfVar3[0x13] = 0.0;
        pfVar3[0x14] = fVar21;
        pfVar3[0x19] = pfVar9[4];
        pfVar3[0x1a] = pfVar9[5];
        if (((u32)param_5[0x19] & 1) == 0) {
          *(u8 *)(pfVar3 + 0x15) = *(u8 *)(param_5 + 0x18);
          *(u8 *)((int)pfVar3 + 0x55) = *(u8 *)((int)param_5 + 0x61);
          *(u8 *)((int)pfVar3 + 0x56) = *(u8 *)((int)param_5 + 0x62);
          *(u8 *)((int)pfVar3 + 0x57) = *(u8 *)((int)param_5 + 99);
        }
        else {
          fVar18 = param_5[0x14];
          fVar13 = param_5[0x15];
          fVar17 = param_5[0x13];
          fVar20 = fVar14 * (fVar22 + *pfVar9);
          fVar19 = param_5[0xd];
          fVar15 = param_5[0xe];
          fVar16 = param_5[0xf];
          *(char *)(pfVar3 + 0x15) = (char)(int)(param_5[0x12] * fVar20 + param_5[0xc]);
          *(char *)((int)pfVar3 + 0x55) = (char)(int)(fVar17 * fVar20 + fVar19);
          *(char *)((int)pfVar3 + 0x56) = (char)(int)(fVar18 * fVar20 + fVar15);
          *(char *)((int)pfVar3 + 0x57) = (char)(int)(fVar13 * fVar20 + fVar16);
        }
        pfVar3[0x1b] = fVar23 + *pfVar9;
        pfVar3[0x1c] = 1.0;
        pfVar3[0x1d] = fVar21;
        pfVar3[0x22] = pfVar9[4];
        pfVar3[0x23] = pfVar9[3];
        if (((u32)param_5[0x19] & 1) == 0) {
          *(u8 *)(pfVar3 + 0x1e) = *(u8 *)(param_5 + 0x18);
          *(u8 *)((int)pfVar3 + 0x79) = *(u8 *)((int)param_5 + 0x61);
          *(u8 *)((int)pfVar3 + 0x7a) = *(u8 *)((int)param_5 + 0x62);
          *(u8 *)((int)pfVar3 + 0x7b) = *(u8 *)((int)param_5 + 99);
        }
        else {
          fVar18 = param_5[8];
          fVar13 = param_5[9];
          fVar17 = param_5[7];
          fVar20 = fVar14 * (fVar22 + *pfVar9);
          fVar19 = param_5[1];
          fVar15 = param_5[2];
          fVar16 = param_5[3];
          *(char *)(pfVar3 + 0x1e) = (char)(int)(param_5[6] * fVar20 + *param_5);
          *(char *)((int)pfVar3 + 0x79) = (char)(int)(fVar17 * fVar20 + fVar19);
          *(char *)((int)pfVar3 + 0x7a) = (char)(int)(fVar18 * fVar20 + fVar15);
          *(char *)((int)pfVar3 + 0x7b) = (char)(int)(fVar13 * fVar20 + fVar16);
        }
        pfVar3 = pfVar3 + 0x24;
        iVar10 = iVar10 + 6;
        fVar13 = *pfVar9 + *(float *)(iVar12 + 0xc);
        fVar23 = fVar23 + fVar13;
        fVar22 = fVar22 + fVar13;
      }
      uVar5 = (u32)*param_3 | (uVar8 & param_3[bVar1]) << 8;
    }
    if ((iVar10 != 0) &&
       (lVar7 = ((code)FUN_004f1ed0)(DAT_0095ed64,((int)pfVar3 - (int)DAT_0095ed64) / 0x24,uVar4,5),
       lVar7 != 0)) {
      ((code)FUN_004f1fd0)(3,0x95ea60,iVar10);
      ((code)FUN_004f1f80)();
    }
    *param_4 = fVar23 * param_1 + *param_4 + 0.0;
    ((code)FUN_004aad50)();
  }
  return param_2;
}

// FUN_004A7620 NONMATCHING

u64 FUN_004a7620(u64 param_1)

{
  u16 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  u8 bVar5;
  u16 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = 0;
  bVar5 = 0;
  iVar7 = 0;
  iVar2 = (int)param_1;
  iVar9 = 0xffff;
  if (0 < *(int *)(iVar2 + 0x130)) {
    piVar3 = (int *)(DAT_0095f984);
    do {
      iVar4 = *piVar3;
      if (0 < iVar4) {
        if (iVar4 < iVar9) {
          iVar9 = iVar4;
        }
        bVar5 = 1;
        if (iVar8 < iVar4) {
          iVar8 = iVar4;
        }
      }
      iVar7 = iVar7 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar7 < *(int *)(iVar2 + 0x130));
  }
  if (bVar5) {
    iVar8 = iVar8 - iVar9;
    iVar7 = iVar8 + 1;
    puVar1 = (u16 *)(*DAT_00960178)(iVar7 * 2,0x30190);
    if (puVar1 == (u16 *)0x0) {
      param_1 = 0;
    }
    else {
      iVar4 = 0;
      if (0 < iVar7) {
        if (8 < iVar7) {
          bVar5 = 0;
          if ((-1 < iVar7) && (iVar7 < 0x7fffffff)) {
            bVar5 = 1;
          }
          puVar6 = puVar1;
          if (bVar5) {
            do {
              *puVar6 = 0xffff;
              iVar4 = iVar4 + 8;
              puVar6[1] = 0xffff;
              puVar6[2] = 0xffff;
              puVar6[3] = 0xffff;
              puVar6[4] = 0xffff;
              puVar6[5] = 0xffff;
              puVar6[6] = 0xffff;
              puVar6[7] = 0xffff;
              puVar6 = puVar6 + 8;
            } while (iVar4 < iVar8 + -7);
          }
        }
        if (iVar4 < iVar7) {
          puVar6 = puVar1 + iVar4;
          do {
            iVar4 = iVar4 + 1;
            *puVar6 = 0xffff;
            puVar6 = puVar6 + 1;
          } while (iVar4 < iVar8 + 1);
        }
      }
      iVar8 = 0;
      if (0 < *(int *)(iVar2 + 0x130)) {
        iVar4 = 0;
        do {
          if (0 < *(int *)((int)DAT_0095f984 + iVar4)) {
            puVar1[*(int *)((int)DAT_0095f984 + iVar4) - iVar9] = (short)iVar8;
          }
          iVar8 = iVar8 + 1;
          iVar4 = iVar4 + 4;
        } while (iVar8 < *(int *)(iVar2 + 0x130));
      }
      *(int *)(iVar2 + 0x128) = iVar7;
      *(int *)(iVar2 + 0x124) = iVar9;
      *(u16 **)(iVar2 + 300) = puVar1;
    }
  }
  return param_1;
}

// FUN_004A7820 NONMATCHING




long FUN_004a7820(long param_1,u64 param_2,u32 param_3,u32 param_4)

{
  int iVar1;
  u8 bVar2;
  u8 bVar3;
  u32 uVar4;
  int iVar5;
  int iVar6;
  u64 uVar7;
  long lVar8;
  u32 *puVar9;
  float *pfVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  u32 *puVar14;
  int iVar15;
  long lVar16;
  int iVar17;
  float fVar18;
  float fVar19;
  int iStack_40;
  int *piStack_28;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  uVar4 = ((code)FUN_004d11f0)();
  ((code)FUN_004d11d0)(DAT_0095ed80);
  puVar14 = (u32 *)param_1;
  *puVar14 = 0;
  iVar11 = DAT_0095f984;
  iVar13 = puVar14[0x4c];
  iVar12 = 0;
  if (iVar13 == 0) {
    iVar13 = 0x100;
  }
  ((code)FUN_004c1f70)(puVar14[0x4d],iVar13,0x30190);
  uVar7 = ((code)FUN_004c2090)(puVar14[0x4d]);
  ((code)FUN_00521408)(uVar7,0,iVar13 << 5);
  ((code)FUN_004c0550)(param_4,0x100,param_3);
  lVar8 = (*DAT_00960174)(param_4,0x7cdc70,param_2,0x95f584);
  lVar16 = param_1;
  if ((int)lVar8 - 1U < 2) {
    ((code)FUN_004cc5c0)(DAT_0095ed6c);
    if (lVar8 == 1) {
      (*DAT_00960134)(0x95f584,0x7cdc78,DAT_0095ed6c,param_2);
      lVar8 = ((code)FUN_004c06c0)(0x95f584);
      if (lVar8 == 0) {
        piStack_28 = (int *)((code)FUN_004d1260)(param_2,0);
      }
      else {
        (*DAT_00960134)(0x95f584,0x7cdc80,param_2);
        piStack_28 = (int *)((code)FUN_004d1260)(param_2,0x95f584);
      }
    }
    else {
      piStack_28 = (int *)((code)FUN_004d1260)(param_2,0x95f584);
    }
    if (piStack_28 == (int *)0x0) {
      lVar16 = 0;
    }
    else {
      puVar14[5] = (u32)(piStack_28);
      iVar1 = *(int *)(*piStack_28 + 0xc);
      iVar5 = *(int *)(*piStack_28 + 0x10);
      ((code)FUN_004c0550)(param_4,0x100,param_3);
      (*DAT_00960174)(param_4,0x7cdc84,&iStack_4);
      iVar17 = 0;
      iStack_40 = 0;
      fVar18 = 1.0 / (float)iVar1;
      fVar19 = 1.0 / (float)iVar5;
      while ((lVar16 == param_1 && (lVar8 = ((code)FUN_004c0550)(param_4,0x100,param_3), lVar8 != 0))) {
        lVar8 = (*DAT_00960174)(param_4,0x77e360,&iStack_8,&iStack_c,&iStack_14,&iStack_10,
                                &iStack_18);
        iVar1 = DAT_0095f988;
        if (lVar8 == 5) {
          if (iStack_8 < 0x10000) {
            iVar5 = DAT_0095f984;
            iVar15 = DAT_0095f988;
            iVar6 = iVar11;
            if (DAT_0095f988 <= iVar12) {
              iVar15 = DAT_0095f988 + 0x20;
              iVar5 = (*DAT_00960178)(iVar15 * 4,0x30190);
              ((code)FUN_00521250)(iVar5,iVar11,DAT_0095f988 << 2);
              if (DAT_0095f988 < iVar15) {
                iVar6 = DAT_0095f988;
                if (8 < iVar15 - DAT_0095f988) {
                  bVar2 = 0;
                  bVar3 = 0;
                  if ((DAT_0095f988 <= iVar15) && (iVar15 < 0x7fffffff)) {
                    bVar3 = 1;
                  }
                  if ((bVar3) && (DAT_0095f988 < 0x7fffffff)) {
                    bVar2 = 1;
                  }
                  if (bVar2) {
                    puVar9 = (u32 *)(iVar5 + DAT_0095f988 * 4);
                    do {
                      *puVar9 = 0xffffffff;
                      puVar9[1] = 0xffffffff;
                      iVar6 = iVar6 + 8;
                      puVar9[2] = 0xffffffff;
                      puVar9[3] = 0xffffffff;
                      puVar9[4] = 0xffffffff;
                      puVar9[5] = 0xffffffff;
                      puVar9[6] = 0xffffffff;
                      puVar9[7] = 0xffffffff;
                      puVar9 = puVar9 + 8;
                    } while (iVar6 < iVar1 + 0x18);
                  }
                }
                if (iVar6 < iVar15) {
                  puVar9 = (u32 *)(iVar5 + iVar6 * 4);
                  do {
                    iVar6 = iVar6 + 1;
                    *puVar9 = 0xffffffff;
                    puVar9 = puVar9 + 1;
                  } while (iVar6 < iVar15);
                }
              }
              iVar6 = iVar5;
              if (iVar11 != 0) {
                (*DAT_0096017c)(iVar11);
              }
            }
            iVar11 = iVar6;
            DAT_0095f988 = iVar15;
            DAT_0095f984 = iVar5;
            if (iStack_8 < 0x80) {
              *(short *)((int)puVar14 + iStack_8 * 2 + 0x24) = (short)iVar12;
            }
            else {
              puVar14[4] = puVar14[4] | 2;
              *(int *)(iVar11 + iVar17) = iStack_8;
            }
            pfVar10 = (float *)((int)uVar7 + iVar12 * 0x20);
            iVar12 = iVar12 + 1;
            iVar17 = iVar17 + 4;
            iStack_40 = iStack_40 + 0x20;
            pfVar10[2] = ((float)iStack_c + 0.5) * fVar18;
            pfVar10[3] = ((float)iStack_14 + 0.5) * fVar19;
            pfVar10[4] = ((float)iStack_10 + 0.5) * fVar18;
            pfVar10[5] = ((float)iStack_18 + 0.5) * fVar19;
            pfVar10[1] = (float)(int)piStack_28;
            *(u8 *)(pfVar10 + 7) = 0;
            if (iVar13 <= iVar12) {
              ((code)FUN_004c1f70)(puVar14[0x4d],0x20,0x30190);
              uVar7 = ((code)FUN_004c2090)(puVar14[0x4d]);
              iVar13 = iVar13 + 0x20;
              ((code)FUN_00521408)((int)uVar7 + iStack_40,0,0x400);
            }
          }
          else {
            lVar16 = 0;
          }
        }
      }
      if (lVar16 == param_1) {
        puVar14[0x4c] = iVar12;
        ((code)FUN_004a7620)(param_1);
        if (DAT_0095f984 != 0) {
          ((code)FUN_00521408)(DAT_0095f984,0xffffffffffffffff,DAT_0095f988 << 2);
        }
        puVar14[1] = (float)(iStack_18 - iStack_14);
        puVar14[2] = (float)iStack_4 / (float)puVar14[1];
        puVar14[3] = 0;
        puVar14[0x4e] = (u32)(FUN_0046bfb0);
      }
    }
  }
  ((code)FUN_004d11d0)(uVar4);
  return lVar16;
}

// FUN_004A7E40 NONMATCHING

u32 * FUN_004a7e40(u32 *param_1,u32 param_2,u32 param_3,char *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  u8 bVar5;
  u8 bVar6;
  u32 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  long lVar12;
  u64 uVar13;
  int iVar14;
  u32 uVar15;
  u32 *puVar16;
  float *pfVar17;
  int iVar18;
  char *pcVar19;
  u32 unaff_s3;
  int iVar20;
  int iVar21;
  float fVar22;
  float fVar23;
  int *piStack_130;
  u32 uStack_12c;
  int iStack_d0;
  int iStack_c0;
  int iStack_b0;
  int iStack_a0;
  int iStack_78;
  int iStack_74;
  u32 *puStack_5c;
  int iStack_54;
  int iStack_50;
  u32 uStack_40;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_4;
  
  uStack_40 = 0;
  uVar7 = ((code)FUN_004d11f0)();
  ((code)FUN_004d11d0)(DAT_0095ed80);
  *param_1 = 0;
  iVar14 = DAT_0095f984;
  iVar20 = 0;
  iStack_50 = param_1[0x4c];
  if (iStack_50 == 0) {
    iStack_50 = 0x100;
  }
  ((code)FUN_004c1f70)(param_1[0x4d],iStack_50,0x30190);
  iStack_54 = ((code)FUN_004c2090)(param_1[0x4d]);
  ((code)FUN_00521408)(iStack_54,0,iStack_50 << 5);
  iStack_10 = 0;
  iStack_18 = 0;
  iStack_14 = 0;
  iStack_a0 = 0;
  iStack_b0 = 0;
  puStack_5c = param_1;
LAB_004a7f58:
  do {
    while( 1 ) {
      pcVar19 = (char *)0x0;
      if ((((3 < uStack_40) || (lVar12 = ((code)FUN_004c0550)(param_4,0x100,param_3), lVar12 == 0)) ||
          (lVar12 = (*DAT_00960174)(param_4,0x7cdc70,param_2,(u8 *)DAT_0095f584), lVar12 == 0)) ||
         ((lVar12 != 1 && (lVar12 != 2)))) {
        if (iStack_10 != 0) {
          ((code)FUN_004cbeb0)(iStack_10);
        }
        if (puStack_5c == param_1) {
          param_1[0x4c] = iVar20;
          ((code)FUN_004a7620)(param_1);
          if (DAT_0095f984 != 0) {
            ((code)FUN_00521408)(DAT_0095f984,0xffffffffffffffff,DAT_0095f988 << 2);
          }
          param_1[0x4e] = (u32)(FUN_0046bfb0);
        }
        ((code)FUN_004d11d0)(uVar7);
        return puStack_5c;
      }
      ((code)FUN_004cc5c0)(DAT_0095ed6c);
      if (lVar12 == 1) {
        uVar13 = ((code)FUN_004d1260)(param_2,0);
        piStack_130 = (int *)uVar13;
        uStack_12c = (u32)((u32)uVar13 >> 0x20);
      }
      else {
        uVar13 = ((code)FUN_004d1260)(param_2,(u8 *)DAT_0095f584);
        piStack_130 = (int *)uVar13;
        uStack_12c = (u32)((u32)uVar13 >> 0x20);
      }
      if (CONCAT44(uStack_12c,piStack_130) != 0) break;
      puStack_5c = (u32 *)0x0;
      uStack_40 = 4;
    }
    param_1[uStack_40 + 5] = (u32)(piStack_130);
    iVar2 = *piStack_130;
    iVar3 = *(int *)(iVar2 + 0x10);
    iVar4 = *(int *)(iVar2 + 0xc);
    if (iStack_10 != 0) {
      if (iStack_14 == iVar4) {
        if (iStack_18 != iVar3) {
          ((code)FUN_004cbeb0)(iStack_10);
          iStack_10 = 0;
        }
      }
      else {
        ((code)FUN_004cbeb0)(iStack_10);
        iStack_10 = 0;
      }
    }
    if (iStack_10 == 0) {
      uVar13 = ((code)FUN_004cbe00)(iVar4,iVar3,0x20);
      iStack_10 = (int)uVar13;
      ((code)FUN_004cbf20)(uVar13);
    }
    ((code)FUN_004cdc70)(iStack_10,iVar2);
    fVar22 = 1.0 / (float)iVar3;
    ((code)FUN_004c0550)(param_4,0x100,param_3);
    (*DAT_00960174)(param_4,0x7cdc84,&iStack_4);
    iStack_74 = 0;
    iVar9 = 1;
    iVar2 = *(int *)(iStack_10 + 0x14);
    iVar8 = *(int *)(iStack_10 + 0xc) >> 3;
    iVar21 = iStack_74;
    if (1 < iVar3) {
      do {
        lVar12 = ((code)FUN_005211b8)(iVar2,iVar2 + *(int *)(iStack_10 + 0x10) * iVar9,iVar8);
        iVar21 = iVar9;
        if (lVar12 == 0) break;
        iVar9 = iVar9 + 1;
        iVar21 = iStack_74;
      } while (iVar9 < iVar3);
    }
    iStack_74 = iVar21;
    iStack_18 = iVar3;
    iStack_14 = iVar4;
    if (0 < iStack_74) {
      iStack_d0 = 0;
LAB_004a815c:
      if ((iStack_d0 < iVar3) && (puStack_5c == param_1)) {
        iStack_78 = 0;
        iVar21 = 1;
        fVar23 = ((float)iStack_d0 + 2.5) * fVar22;
        iStack_c0 = iVar8;
        do {
          if ((iVar4 <= iVar21) || (puStack_5c != param_1)) goto LAB_004a8870;
          lVar12 = ((code)FUN_005211b8)(iVar2,iVar2 + *(int *)(iStack_10 + 0x10) * iStack_d0 + iStack_c0,
                                iVar8);
          uVar15 = unaff_s3;
          if (lVar12 == 0) {
            if (iVar21 - iStack_78 == 1) goto LAB_004a8870;
            if (((pcVar19 == (char *)0x0) || (*pcVar19 == '\n')) || (*pcVar19 == '\0')) {
              ((code)FUN_004c0550)(param_4,0x100,param_3);
              pcVar19 = param_4;
            }
            else if ((int)pcVar19 - (int)param_4 < 0x80) {
              if (0x7f < (int)pcVar19 - (int)param_4) {
                iVar9 = (*DAT_00960164)(pcVar19);
                ((code)FUN_00521250)(param_4,pcVar19,iVar9 + 1);
                if (param_4[iVar9 + -1] == '\n') {
                  iVar9 = iVar9 + -1;
                }
                ((code)FUN_004c0550)(param_4 + iVar9,0x100 - iVar9,param_3);
                pcVar19 = param_4;
              }
            }
            else {
              iVar9 = (*DAT_00960164)(pcVar19);
              if (pcVar19 + (iVar9 - (int)param_4) == (char *)0xff) {
                ((code)FUN_00521250)(param_4,pcVar19,iVar9 + 1);
                if (param_4[iVar9 + -1] == '\n') {
                  iVar9 = iVar9 + -1;
                }
                ((code)FUN_004c0550)(param_4 + iVar9,0x100 - iVar9,param_3);
                pcVar19 = param_4;
              }
            }
            iVar9 = DAT_0095f988;
            cVar1 = *pcVar19;
            uVar15 = (u32)cVar1;
            if ((uVar15 & 0x80) == 0) {
              iVar11 = 1;
            }
            else if ((uVar15 & 0xe0) == 0xc0) {
              iVar11 = 2;
              uVar15 = (long)(int)(((int)cVar1 & 0x1fU) << 6) | (long)pcVar19[1] & 0x3fU;
            }
            else if ((uVar15 & 0xf0) == 0xe0) {
              iVar11 = 3;
              uVar15 = (long)pcVar19[2] & 0x3fU |
                       (long)(int)(((int)cVar1 & 0xfU) << 0xc | ((int)pcVar19[1] & 0x3fU) << 6);
            }
            else if ((uVar15 & 0xf8) == 0xf0) {
              iVar11 = 4;
              uVar15 = (long)pcVar19[3] & 0x3fU |
                       (long)(int)(((int)pcVar19[2] & 0x3fU) << 6 |
                                  ((int)cVar1 & 7U) << 0x12 | ((int)pcVar19[1] & 0x3fU) << 0xc);
            }
            else if ((uVar15 & 0xfc) == 0xf8) {
              iVar11 = 5;
              uVar15 = (long)pcVar19[4] & 0x3fU |
                       (long)(int)(((int)pcVar19[3] & 0x3fU) << 6 |
                                  ((int)pcVar19[2] & 0x3fU) << 0xc |
                                  ((int)cVar1 & 3U) << 0x18 | ((int)pcVar19[1] & 0x3fU) << 0x12);
            }
            else if ((uVar15 & 0xfe) == 0xfc) {
              iVar11 = 6;
              uVar15 = (long)pcVar19[5] & 0x3fU |
                       (long)(int)(((int)pcVar19[4] & 0x3fU) << 6 |
                                  ((int)pcVar19[3] & 0x3fU) << 0xc |
                                  ((int)pcVar19[2] & 0x3fU) << 0x12 |
                                  ((int)cVar1 & 1U) << 0x1e | ((int)pcVar19[1] & 0x3fU) << 0x18);
            }
            else {
              iVar11 = -1;
              uVar15 = unaff_s3;
            }
            if ((iVar11 < 1) || (0xffff < (long)uVar15)) {
              uStack_40 = 4;
              puStack_5c = (u32 *)0x0;
              iStack_78 = iVar21;
            }
            else {
              pcVar19 = pcVar19 + iVar11;
              iVar11 = DAT_0095f984;
              iVar18 = DAT_0095f988;
              iVar10 = iVar14;
              if (DAT_0095f988 <= iVar20) {
                iVar18 = DAT_0095f988 + 0x20;
                iVar10 = (*DAT_00960178)(iVar18 * 4,0x30190);
                ((code)FUN_00521250)(iVar10,iVar14,DAT_0095f988 << 2);
                if (DAT_0095f988 < iVar18) {
                  iVar11 = DAT_0095f988;
                  if (8 < iVar18 - DAT_0095f988) {
                    bVar5 = 0;
                    bVar6 = 0;
                    if ((DAT_0095f988 <= iVar18) && (iVar18 < 0x7fffffff)) {
                      bVar6 = 1;
                    }
                    if ((bVar6) && (DAT_0095f988 < 0x7fffffff)) {
                      bVar5 = 1;
                    }
                    if (bVar5) {
                      puVar16 = (u32 *)(iVar10 + DAT_0095f988 * 4);
                      do {
                        *puVar16 = 0xffffffff;
                        puVar16[1] = 0xffffffff;
                        iVar11 = iVar11 + 8;
                        puVar16[2] = 0xffffffff;
                        puVar16[3] = 0xffffffff;
                        puVar16[4] = 0xffffffff;
                        puVar16[5] = 0xffffffff;
                        puVar16[6] = 0xffffffff;
                        puVar16[7] = 0xffffffff;
                        puVar16 = puVar16 + 8;
                      } while (iVar11 < iVar9 + 0x18);
                    }
                  }
                  if (iVar11 < iVar18) {
                    puVar16 = (u32 *)(iVar10 + iVar11 * 4);
                    do {
                      iVar11 = iVar11 + 1;
                      *puVar16 = 0xffffffff;
                      puVar16 = puVar16 + 1;
                    } while (iVar11 < iVar18);
                  }
                }
                iVar11 = iVar10;
                if (iVar14 != 0) {
                  (*DAT_0096017c)(iVar14);
                }
              }
              DAT_0095f988 = iVar18;
              DAT_0095f984 = iVar11;
              if ((long)uVar15 < 0x80) {
                *(short *)((int)param_1 + (int)uVar15 * 2 + 0x24) = (short)iVar20;
              }
              else {
                param_1[4] = param_1[4] | 2;
                *(int *)(iVar10 + iStack_a0) = (int)uVar15;
              }
              iVar14 = iVar20 * 0x20;
              iVar20 = iVar20 + 1;
              pfVar17 = (float *)(iStack_54 + iVar14);
              pfVar17[2] = ((float)iStack_78 + 2.5) * (1.0 / (float)iVar4);
              iStack_a0 = iStack_a0 + 4;
              iStack_b0 = iStack_b0 + 0x20;
              pfVar17[3] = fVar23;
              pfVar17[4] = ((float)iVar21 - 0.5) * (1.0 / (float)iVar4);
              pfVar17[5] = ((float)(iStack_d0 + iStack_74) - 0.5) * fVar22;
              pfVar17[1] = (float)(int)piStack_130;
                         (float)(((iStack_d0 + iStack_74) - iStack_d0) + -3);
              *(char *)(pfVar17 + 7) = (char)uStack_40;
              iStack_78 = iVar21;
              iVar14 = iVar10;
              if (iStack_50 <= iVar20) {
                ((code)FUN_004c1f70)(param_1[0x4d],0x20,0x30190);
                iStack_54 = ((code)FUN_004c2090)(param_1[0x4d]);
                iStack_50 = iStack_50 + 0x20;
                ((code)FUN_00521408)(iStack_54 + iStack_b0,0,0x400);
              }
            }
          }
          iVar21 = iVar21 + 1;
          iStack_c0 = iStack_c0 + iVar8;
          unaff_s3 = uVar15;
        } while( 1 );
      }
      param_1[1] = (float)iStack_74 - 3.0;
      uStack_40 = uStack_40 + 1;
      param_1[2] = (float)iStack_4 / (float)param_1[1];
      param_1[3] = 0;
      goto LAB_004a7f58;
    }
    puStack_5c = (u32 *)0x0;
    uStack_40 = 4;
  } while( 1 );
LAB_004a8870:
  iStack_d0 = iStack_d0 + iStack_74;
  goto LAB_004a815c;
}

// FUN_004A8980 NONMATCHING

u32 *
FUN_004a8980(u32 *param_1,u64 param_2,u32 param_3,u64 param_4)

{
  char cVar1;
  u8 bVar2;
  u8 bVar3;
  int iVar4;
  int iVar5;
  long lVar6;
  u64 uVar7;
  int iVar8;
  u32 *puVar9;
  u32 uVar10;
  int iVar11;
  long lVar12;
  int iVar13;
  u32 uVar14;
  int iVar15;
  int iStack_f0;
  int iStack_e0;
  int iStack_c4;
  int iStack_c0;
  u32 *puStack_a8;
  u8 auStack_a0 [128];
  u32 uStack_20;
  u32 uStack_1c;
  u32 auStack_18 [2];
  u32 uStack_10;
  u32 uStack_c;
  u32 auStack_8 [2];
  
  *param_1 = 1;
  lVar12 = 0;
  param_1[1] = 0x3f800000;
  param_1[2] = 0;
  param_1[3] = 0;
  ((code)FUN_004c0550)(param_4,0x100);
  iVar13 = DAT_0095f984;
  iStack_c0 = param_1[0x4c];
  iVar15 = 0;
  if (iStack_c0 == 0) {
    iStack_c0 = 0x100;
  }
  ((code)FUN_004c1f70)(param_1[0x4d],iStack_c0,0x30190);
  iStack_c4 = ((code)FUN_004c2090)(param_1[0x4d]);
  ((code)FUN_00521408)(iStack_c4,0,iStack_c0 << 5);
  lVar6 = (*DAT_00960174)(param_4,(u8 *)gp0xffffaf98,auStack_a0);
  puStack_a8 = param_1;
  if (lVar6 == 1) {
    iStack_e0 = 0;
    iStack_f0 = 0;
    uVar14 = 0;
    while ((puStack_a8 == param_1 && (lVar6 = ((code)FUN_004c0550)(param_4,0x100,param_3), lVar6 != 0))) {
      if (uVar14 == 0) {
        iVar8 = (int)param_4;
        cVar1 = *(char *)(iVar8 + 1);
        uVar10 = (u32)cVar1;
        if ((uVar10 & 0x80) == 0) {
          iVar4 = 1;
        }
        else if ((uVar10 & 0xe0) == 0xc0) {
          iVar4 = 2;
          uVar10 = (long)(int)(((int)cVar1 & 0x1fU) << 6) | (long)*(char *)(iVar8 + 2) & 0x3fU;
        }
        else if ((uVar10 & 0xf0) == 0xe0) {
          iVar4 = 3;
          uVar10 = (long)*(char *)(iVar8 + 3) & 0x3fU |
                   (long)(int)(((int)cVar1 & 0xfU) << 0xc | ((int)*(char *)(iVar8 + 2) & 0x3fU) << 6
                              );
        }
        else if ((uVar10 & 0xf8) == 0xf0) {
          iVar4 = 4;
          uVar10 = (long)*(char *)(iVar8 + 4) & 0x3fU |
                   (long)(int)(((int)*(char *)(iVar8 + 3) & 0x3fU) << 6 |
                              ((int)cVar1 & 7U) << 0x12 | ((int)*(char *)(iVar8 + 2) & 0x3fU) << 0xc
                              );
        }
        else if ((uVar10 & 0xfc) == 0xf8) {
          iVar4 = 5;
          uVar10 = (long)*(char *)(iVar8 + 5) & 0x3fU |
                   (long)(int)(((int)*(char *)(iVar8 + 4) & 0x3fU) << 6 |
                              ((int)*(char *)(iVar8 + 3) & 0x3fU) << 0xc |
                              ((int)cVar1 & 3U) << 0x18 |
                              ((int)*(char *)(iVar8 + 2) & 0x3fU) << 0x12);
        }
        else if ((uVar10 & 0xfe) == 0xfc) {
          iVar4 = 6;
          uVar10 = (long)*(char *)(iVar8 + 6) & 0x3fU |
                   (long)(int)(((int)*(char *)(iVar8 + 5) & 0x3fU) << 6 |
                              ((int)*(char *)(iVar8 + 4) & 0x3fU) << 0xc |
                              ((int)*(char *)(iVar8 + 3) & 0x3fU) << 0x12 |
                              ((int)cVar1 & 1U) << 0x1e |
                              ((int)*(char *)(iVar8 + 2) & 0x3fU) << 0x18);
        }
        else {
          iVar4 = -1;
          uVar10 = uVar14;
        }
        uVar14 = uVar10;
        if ((iVar4 < 0) || (0xffff < (long)uVar10)) {
          puStack_a8 = (u32 *)0x0;
        }
      }
      else {
        lVar6 = (*DAT_00960158)(param_4,(u8 *)gp0xffffafa0);
        if (lVar6 == 0) {
          lVar12 = ((code)FUN_004ac570)();
          ((code)FUN_004ac5f0)(lVar12);
        }
        else {
          lVar6 = (*DAT_00960158)(param_4,(u8 *)gp0xffffafa8);
          if (lVar6 == 0) {
            uVar7 = ((code)FUN_004ac240)(lVar12);
            ((code)FUN_004ac710)(uVar7);
            iVar8 = DAT_0095f988;
            iVar4 = DAT_0095f984;
            iVar11 = DAT_0095f988;
            iVar5 = iVar13;
            if (DAT_0095f988 <= iVar15) {
              iVar11 = DAT_0095f988 + 0x20;
              iVar4 = (*DAT_00960178)(iVar11 * 4,0x30190);
              ((code)FUN_00521250)(iVar4,iVar13,DAT_0095f988 << 2);
              if (DAT_0095f988 < iVar11) {
                iVar5 = DAT_0095f988;
                if (8 < iVar11 - DAT_0095f988) {
                  bVar2 = 0;
                  bVar3 = 0;
                  if ((DAT_0095f988 <= iVar11) && (iVar11 < 0x7fffffff)) {
                    bVar3 = 1;
                  }
                  if ((bVar3) && (DAT_0095f988 < 0x7fffffff)) {
                    bVar2 = 1;
                  }
                  if (bVar2) {
                    puVar9 = (u32 *)(iVar4 + DAT_0095f988 * 4);
                    do {
                      *puVar9 = 0xffffffff;
                      puVar9[1] = 0xffffffff;
                      iVar5 = iVar5 + 8;
                      puVar9[2] = 0xffffffff;
                      puVar9[3] = 0xffffffff;
                      puVar9[4] = 0xffffffff;
                      puVar9[5] = 0xffffffff;
                      puVar9[6] = 0xffffffff;
                      puVar9[7] = 0xffffffff;
                      puVar9 = puVar9 + 8;
                    } while (iVar5 < iVar8 + 0x18);
                  }
                }
                if (iVar5 < iVar11) {
                  puVar9 = (u32 *)(iVar4 + iVar5 * 4);
                  do {
                    iVar5 = iVar5 + 1;
                    *puVar9 = 0xffffffff;
                    puVar9 = puVar9 + 1;
                  } while (iVar5 < iVar11);
                }
              }
              iVar5 = iVar4;
              if (iVar13 != 0) {
                (*DAT_0096017c)(iVar13);
              }
            }
            iVar13 = iVar5;
            DAT_0095f988 = iVar11;
            DAT_0095f984 = iVar4;
            if ((long)uVar14 < 0x80) {
              *(short *)((int)param_1 + (int)uVar14 * 2 + 0x24) = (short)iVar15;
            }
            else {
              param_1[4] = param_1[4] | 2;
              *(int *)(iVar13 + iStack_e0) = (int)uVar14;
            }
            iVar8 = iVar15 * 0x20;
            uVar14 = 0;
            iVar15 = iVar15 + 1;
            lVar12 = 0;
            puVar9 = (u32 *)(iStack_c4 + iVar8);
            puVar9[6] = (int)uVar7;
            iStack_e0 = iStack_e0 + 4;
            iStack_f0 = iStack_f0 + 0x20;
            *puVar9 = uStack_10;
            if (iStack_c0 <= iVar15) {
              ((code)FUN_004c1f70)(param_1[0x4d],0x20,0x30190);
              iStack_c4 = ((code)FUN_004c2090)(param_1[0x4d]);
              iStack_c0 = iStack_c0 + 0x20;
              ((code)FUN_00521408)(iStack_c4 + iStack_f0,0,0x400);
            }
          }
          else if (lVar12 != 0) {
            lVar6 = (*DAT_00960174)(param_4,0x77e370,&uStack_10,&uStack_20);
            if (lVar6 == 2) {
              ((code)FUN_004ab200)(uStack_10,uStack_20,lVar12);
            }
            else {
              lVar6 = (*DAT_00960174)(param_4,0x77e380,&uStack_10,&uStack_20);
              if (lVar6 == 2) {
                ((code)FUN_004ab2c0)(uStack_10,uStack_20,lVar12);
              }
              else {
                lVar6 = (*DAT_00960174)(param_4,0x77e390,&uStack_10,&uStack_20,&uStack_c,&uStack_1c,
                                        auStack_8,auStack_18);
                if (lVar6 == 6) {
                  ((code)FUN_004ab410)(uStack_10,uStack_20,uStack_c,uStack_1c,auStack_8[0],auStack_18[0],
                               lVar12);
                }
                else {
                  lVar6 = (*DAT_00960158)(param_4,0x77e3b0);
                  if (lVar6 == 0) {
                    ((code)FUN_004ab6a0)(lVar12);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if (puStack_a8 == param_1) {
    param_1[0x4c] = iVar15;
    ((code)FUN_004a7620)(param_1);
    if (DAT_0095f984 != 0) {
      ((code)FUN_00521408)(DAT_0095f984,0xffffffffffffffff,DAT_0095f988 << 2);
    }
    param_1[0x4e] = (u32)(FUN_004a6ce0);
  }
  return puStack_a8;
}

// FUN_004A90F0 NONMATCHING

u32 * FUN_004a90f0(void)

{
  u32 *puVar1;
  u32 uVar2;
  u32 *puVar3;
  int iVar4;
  
  puVar1 = (u32 *)(*DAT_00960188)(DAT_0095ed68,0x30199);
  if (puVar1 == (u32 *)0x0) {
    puVar1 = (u32 *)0x0;
  }
  else {
    *puVar1 = 1;
    puVar1[1] = 0x3f800000;
    puVar1[2] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 0;
    puVar1[0x4a] = 0;
    puVar1[0x4c] = 0;
    puVar1[0x49] = 0;
    puVar1[0x4b] = 0;
    uVar2 = ((code)FUN_004c1d50)(0x20,0x30190);
    puVar1[0x4d] = uVar2;
    iVar4 = 0;
    puVar1[0x4e] = (u32)(FUN_004a6eb0);
    puVar1[0x4f] = 0;
    puVar1[0x50] = 0;
    puVar3 = puVar1;
    do {
      *(u16 *)(puVar3 + 9) = 0xffff;
      iVar4 = iVar4 + 8;
      *(u16 *)((int)puVar3 + 0x26) = 0xffff;
      *(u16 *)(puVar3 + 10) = 0xffff;
      *(u16 *)((int)puVar3 + 0x2a) = 0xffff;
      *(u16 *)(puVar3 + 0xb) = 0xffff;
      *(u16 *)((int)puVar3 + 0x2e) = 0xffff;
      *(u16 *)(puVar3 + 0xc) = 0xffff;
      *(u16 *)((int)puVar3 + 0x32) = 0xffff;
      puVar3 = puVar3 + 4;
    } while (iVar4 < 0x80);
  }
  return puVar1;
}

// FUN_004A91F0 NONMATCHING

void FUN_004a91f0(void)

{
  u32 *puVar1;
  u32 *puVar2;
  
  puVar2 = (u32 *)(DAT_0095ed78);
  while (puVar2 != (u32 *)0x0) {
    (*DAT_0096017c)(*puVar2);
    ((code)FUN_004a96b0)(puVar2[1]);
    puVar1 = (u32 *)puVar2[2];
    (*DAT_0096018c)(DAT_0095ed74,puVar2);
    puVar2 = puVar1;
  }
  DAT_0095ed78 = (u32)((u32 *)0x0);
  if (DAT_0095ed7c != 0) {
    ((code)FUN_004d0d10)();
  }
  DAT_0095ed7c = 0;
  DAT_0095ed80 = 0;
  ((code)FUN_004c3c30)(DAT_0095ed74);
  DAT_0095ed74 = 0;
  ((code)FUN_004c3c30)(DAT_0095ed68);
  DAT_0095ed68 = 0;
  if (DAT_0095f984 != 0) {
    (*DAT_0096017c)();
  }
  DAT_0095f984 = 0;
  if (DAT_0095ed6c != 0) {
    (*DAT_0096017c)();
  }
  uGpffffbba4 = 0;
  DAT_0095ed6c = 0;
  DAT_0095ed70 = 0;
  return;
}

// FUN_004A9330 NONMATCHING

u32 FUN_004a9330(void)

{
  u32 uVar1;
  long lVar2;
  short *psVar3;
  short sVar4;
  int iVar5;
  
  lVar2 = thunk_FUN_004c3970(0x144,uGpffffafb0,4,uGpffffafb4,0x95e830,0x40199);
  DAT_0095ed68 = (u32)lVar2;
  if (lVar2 == 0) {
    uVar1 = 0;
  }
  else {
    lVar2 = thunk_FUN_004c3970(0xc,uGpffffafb8,4,uGpffffafbc,0x95e800,0x40190);
    DAT_0095ed74 = (u32)lVar2;
    if (lVar2 == 0) {
      uVar1 = 0;
    }
    else {
      lVar2 = (*DAT_00960178)(0x51,0x1040190);
      DAT_0095ed6c = (u32)lVar2;
      if (lVar2 == 0) {
        uVar1 = 0;
      }
      else {
        DAT_0095ed70 = 0x51;
        ((code)FUN_004a9490)((u8 *)gp0xffffafc0);
        iVar5 = 0;
        psVar3 = (s16 *)((u8 *)DAT_0095ea60);
        sVar4 = 0;
        do {
          *psVar3 = sVar4;
          psVar3[1] = sVar4 + 2;
          psVar3[2] = sVar4 + 3;
          psVar3[3] = sVar4;
          iVar5 = iVar5 + 6;
          psVar3[4] = sVar4 + 3;
          psVar3[5] = sVar4 + 1;
          psVar3 = psVar3 + 6;
          sVar4 = sVar4 + 4;
        } while (iVar5 < 0x180);
        DAT_0095ed78 = 0;
        DAT_0095ed7c = ((code)FUN_004d0c30)();
        DAT_0095f984 = 0;
        DAT_0095f988 = 0;
        DAT_0095ed80 = DAT_0095ed7c;
        ((code)FUN_004a9550)(0x4a98a0);
        uVar1 = 1;
        uGpffffbba4 = 1;
      }
    }
  }
  return uVar1;
}

// FUN_004A9490 NONMATCHING

long FUN_004a9490(long param_1)

{
  int iVar1;
  long lVar2;
  u32 uVar3;
  
  if (param_1 == 0) {
    param_1 = 0;
  }
  else {
    iVar1 = (*DAT_00960164)();
    uVar3 = iVar1 + 1;
    if (DAT_0095ed70 < uVar3) {
      lVar2 = (*DAT_00960180)(DAT_0095ed6c,uVar3,0x1040190);
      if (lVar2 == 0) {
        return 0;
      }
      DAT_0095ed6c = (u32)lVar2;
      DAT_0095ed70 = uVar3;
    }
    (*DAT_0096013c)(DAT_0095ed6c,param_1);
  }
  return param_1;
}


#pragma optimization_level 3
// FUN_004A9550
u32 FUN_004a9550(u32 param_1)
{
  *(u32 *)0x0095f478 = param_1;
  return 1;
}
#pragma optimization_level 2

// FUN_004A9560 NONMATCHING

float FUN_004a9560(float param_1,int param_2,u8 *param_3)

{
  u8 bVar1;
  int iVar2;
  u32 uVar3;
  int iVar4;
  long lVar5;
  u32 uVar6;
  int iVar7;
  float fVar8;
  
  fVar8 = 0.0;
  iVar2 = ((code)FUN_004c2090)(*(u32 *)(param_2 + 0x134));
  bVar1 = (*(u32 *)(param_2 + 0x10) & 2) == 0;
  if (bVar1) {
    iVar4 = 1;
    uVar3 = 0;
  }
  else {
    iVar4 = 2;
    uVar3 = 0xff;
  }
  bVar1 = !bVar1;
  uVar6 = (u32)*param_3 | (uVar3 & param_3[bVar1]) << 8;
  if (uVar6 != 0) {
    do {
      if (uVar6 < 0x80) {
        lVar5 = (long)*(short *)(param_2 + uVar6 * 2 + 0x24);
      }
      else {
        iVar7 = uVar6 - *(int *)(param_2 + 0x124);
        lVar5 = -1;
        if ((-1 < iVar7) && (iVar7 < *(int *)(param_2 + 0x128))) {
          lVar5 = (long)*(short *)(*(int *)(param_2 + 300) + iVar7 * 2);
        }
      }
      param_3 = param_3 + iVar4;
      if (-1 < lVar5) {
        fVar8 = fVar8 + *(float *)(iVar2 + (int)lVar5 * 0x20) + *(float *)(param_2 + 0xc);
      }
      uVar6 = (u32)*param_3 | (uVar3 & param_3[bVar1]) << 8;
    } while (uVar6 != 0);
  }
  return fVar8 * param_1;
}

// FUN_004A96B0 NONMATCHING

u32 FUN_004a96b0(int param_1)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x134) != 0) {
      iVar1 = ((code)FUN_004c2090)();
      uVar3 = 0;
      if (*(int *)(param_1 + 0x130) != 0) {
        do {
          if (*(int *)(iVar1 + 0x18) != 0) {
            ((code)FUN_004ac390)();
            *(u32 *)(iVar1 + 0x18) = 0;
          }
          uVar3 = uVar3 + 1;
          iVar1 = iVar1 + 0x20;
        } while (uVar3 < *(u32 *)(param_1 + 0x130));
      }
      ((code)FUN_004c20b0)(*(u32 *)(param_1 + 0x134));
    }
    *(u32 *)(param_1 + 0x134) = 0;
    if (*(int *)(param_1 + 300) != 0) {
      (*DAT_0096017c)();
    }
    *(u32 *)(param_1 + 300) = 0;
    uVar3 = 0;
    iVar1 = param_1;
    do {
      if (*(int *)(iVar1 + 0x14) != 0) {
        ((code)FUN_004d0f00)();
      }
      uVar3 = uVar3 + 1;
      *(u32 *)(iVar1 + 0x14) = 0;
      iVar1 = iVar1 + 4;
    } while (uVar3 < 4);
    (*DAT_0096018c)(DAT_0095ed68,param_1);
    uVar2 = 1;
  }
  return uVar2;
}

// FUN_004A97C0 NONMATCHING

void FUN_004a97c0(u64 param_1,u64 param_2)

{
  char cVar1;
  long lVar2;
  int iVar3;
  char *pcVar4;
  
  iVar3 = 0;
  lVar2 = 0;
  pcVar4 = (char *)(DAT_0095ed6c);
  do {
    cVar1 = *pcVar4;
    if ((cVar1 == ';') || (cVar1 == '\0')) {
      *(u8 *)((int)param_2 + iVar3) = 0;
      (*DAT_00960144)(param_2,param_1);
      (*DAT_00960144)(param_2,(u8 *)gp0xffffafc8);
      lVar2 = ((code)FUN_004c0240)(param_2,(u8 *)gp0xffffafd0);
      iVar3 = 0;
    }
    else {
      *(char *)((int)param_2 + iVar3) = cVar1;
      iVar3 = iVar3 + 1;
    }
    pcVar4 = pcVar4 + 1;
  } while ((cVar1 != '\0') && (lVar2 == 0));
  return;
}

// FUN_004A98A0 NONMATCHING

long FUN_004a98a0(u64 param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  u8 auStack_180 [256];
  u8 auStack_80 [128];
  
  lVar3 = ((code)FUN_004a90f0)();
  if (lVar3 == 0) {
    lVar3 = 0;
  }
  else {
    iVar1 = (*DAT_00960164)(DAT_0095ed6c);
    iVar2 = (*DAT_00960164)(param_1);
    lVar4 = (*DAT_00960178)(iVar1 + iVar2 + 5,0x10190);
    if (lVar4 == 0) {
      ((code)FUN_004a96b0)(lVar3);
      lVar3 = 0;
    }
    else {
      lVar5 = ((code)FUN_004a97c0)(param_1,lVar4);
      lVar7 = 0;
      if (lVar5 != 0) {
        ((code)FUN_004c0550)(auStack_180,0x100,lVar5);
        lVar6 = (*DAT_00960158)(auStack_180,0x77e3c0);
        if (lVar6 == 0) {
          lVar7 = ((code)FUN_004a7820)(lVar3,auStack_80,lVar5,auStack_180);
        }
        else {
          lVar6 = (*DAT_00960158)(auStack_180,0x77e3d0);
          if (lVar6 == 0) {
            lVar7 = ((code)FUN_004a7e40)(lVar3,auStack_80,lVar5,auStack_180);
          }
          else {
            lVar6 = (*DAT_00960158)(auStack_180,0x77e3e0);
            if (lVar6 == 0) {
              lVar7 = ((code)FUN_004a8980)(lVar3,auStack_80,lVar5,auStack_180);
            }
          }
        }
        ((code)FUN_004c0370)(lVar5);
      }
      (*DAT_0096017c)(lVar4);
      if (lVar7 != lVar3) {
        ((code)FUN_004a96b0)(lVar3);
        lVar3 = 0;
      }
    }
  }
  return lVar3;
}

#pragma optimization_level 3
// FUN_004A9A70
void FUN_004a9a70(int param_1)
{
  ((void (*)(void))*(u32 *)(param_1 + 0x138))();
}
#pragma optimization_level 2

// FUN_004A9A80 NONMATCHING

u32 * FUN_004a9a80(u64 param_1)

{
  u32 *puVar1;
  int iVar2;
  u32 uVar3;
  long lVar4;
  u64 uVar5;
  u8 auStack_80 [128];
  
  for (puVar1 = (u32 *)DAT_0095ed78; puVar1 != (u32 *)0x0; puVar1 = (u32 *)puVar1[2]) {
    if (lVar4 == 0) goto LAB_004a9adc;
  }
  puVar1 = (u32 *)0x0;
LAB_004a9adc:
  if (puVar1 == (u32 *)0x0) {
    uVar5 = ((code)FUN_004cc6b0)();
    (*DAT_0096013c)(auStack_80,uVar5);
    lVar4 = (*DAT_0095f478)(param_1);
    if (lVar4 == 0) {
      puVar1 = (u32 *)0x0;
    }
    else {
      puVar1 = (u32 *)(*DAT_00960188)(DAT_0095ed74,0x30190);
      puVar1[1] = (int)lVar4;
      iVar2 = (*DAT_00960164)(param_1);
      uVar3 = (*DAT_00960178)(iVar2 + 1,0x30190);
      *puVar1 = uVar3;
      (*DAT_0096013c)(*puVar1,param_1);
      puVar1[2] = DAT_0095ed78;
      DAT_0095ed78 = (u32)(puVar1);
    }
    ((code)FUN_004cc5c0)(auStack_80);
  }
  return puVar1;
}


#pragma optimization_level 3
// FUN_004A9BD0
u8 FUN_004a9bd0(int param_1)
{
  return (*(u32 *)(param_1 + 0x10) & 2) != 0;
}
#pragma optimization_level 2

// FUN_004A9BE0
asm void FUN_004a9be0(void)
{
  .set noreorder
  lui $v0, 0x96
  lw $v0, -0x1030($v0)
  jr $v0
  nop
}

// FUN_004A9BF0 NONMATCHING

u32 FUN_004a9bf0(void)

{
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x28) = 0x3f800000;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x14) = 0x3f800000;
  *(u32 *)((u8 *)DAT_0095edf0)[DAT_0095ee70] = 0x3f800000;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x10) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 8) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 4) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x24) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x20) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x18) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x38) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x34) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x30) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0xc) =
       *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0xc) | 0x20003;
  DAT_0095ef50 = 0;
  DAT_0095ef64 = 0;
  return 1;
}

// FUN_004A9D80 NONMATCHING

u32 FUN_004a9d80(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fStack_10;
  float fStack_c;
  u32 uStack_8;
  
  fVar3 = DAT_0095ee80;
  fVar2 = DAT_0095ee78;
  fVar1 = DAT_0095ee74;
  fVar4 = DAT_0095ef58;
  if (*(int *)(DAT_0095ef84 + 0x14) == 2) {
    fVar4 = 1.0;
  }
  fVar5 = DAT_0095ee7c;
  ((code)FUN_004aae60)();
  fStack_c = 0.0;
  uStack_8 = 0;
  fStack_10 = -fVar4 * (fVar1 / fVar5);
  ((code)FUN_004c6c60)(&fStack_10,&fStack_10,0x95eed0);
  *param_1 = fStack_10;
  param_1[1] = fStack_c;
  fStack_10 = 0.0;
  uStack_8 = 0;
  fStack_c = fVar4 * (fVar2 / fVar3);
  ((code)FUN_004c6c60)(&fStack_10,&fStack_10,0x95eed0);
  *param_2 = fStack_10;
  fStack_10 = fVar1 * 0.5 * fVar4;
  param_2[1] = fStack_c;
  fStack_c = -fVar2 * 0.5 * fVar4;
  uStack_8 = 0;
  ((code)FUN_004c6be0)(&fStack_10,&fStack_10,0x95eed0);
  *param_3 = fStack_10;
  param_3[1] = fStack_c;
  return 1;
}

// FUN_004A9F20 NONMATCHING

u32 FUN_004a9f20(float param_1,float param_2,float param_3,float param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fStack_28;
  float fStack_24;
  u32 uStack_20;
  float fStack_18;
  u32 uStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  DAT_0095edd8 = 0x3f800000;
  DAT_0095edc4 = 0x3f800000;
  DAT_0095edb0 = 0x3f800000;
  DAT_0095edc0 = 0;
  DAT_0095edb8 = 0;
  DAT_0095edb4 = 0;
  DAT_0095edd4 = 0;
  DAT_0095edd0 = 0;
  DAT_0095edc8 = 0;
  DAT_0095ede8 = 0;
  DAT_0095ede4 = 0;
  DAT_0095ede0 = 0;
  DAT_0095edbc = DAT_0095edbc | 0x20003;
  ((code)FUN_004aaa60)();
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x28) = 0x3f800000;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x14) = 0x3f800000;
  *(u32 *)((u8 *)DAT_0095edf0)[DAT_0095ee70] = 0x3f800000;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x10) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 8) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 4) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x24) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x20) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x18) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x38) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x34) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x30) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0xc) =
       *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0xc) | 0x20003;
  DAT_0095ef50 = 0;
  DAT_0095ef64 = 0;
  ((code)FUN_004a9d80)(&fStack_8,&fStack_10,&fStack_18);
  uStack_20 = 0;
  fStack_28 = fStack_18;
  fStack_8 = fStack_8 * (DAT_0095ee7c / param_3);
  fStack_10 = fStack_10 * (DAT_0095ee80 / param_4);
  fStack_24 = (float)uStack_14;
  fStack_4 = fStack_4 * (DAT_0095ee7c / param_3);
  fStack_c = fStack_c * (DAT_0095ee80 / param_4);
  fVar3 = fStack_c * fStack_c;
  fVar1 = fStack_10 * fStack_10;
  fVar2 = SQRT(fStack_8 * fStack_8 + fStack_4 * fStack_4);
  ((code)FUN_004c35d0)(0x95edb0,&fStack_28,1);
  uStack_20 = 0x3f800000;
  fStack_28 = fVar2;
  fStack_24 = SQRT(fVar1 + fVar3);
  ((code)FUN_004c33d0)(0x95edb0,&fStack_28,1);
  fStack_28 = -param_1;
  fStack_24 = -param_2;
  uStack_20 = 0;
  ((code)FUN_004c35d0)(0x95edb0,&fStack_28,1);
  DAT_0095ef70 = param_1;
  DAT_0095ef74 = param_2;
  DAT_0095ef78 = param_3;
  DAT_0095ef7c = param_4;
  ((code)FUN_004aad50)();
  DAT_0095ef50 = 0;
  return 1;
}

// FUN_004AA2C0 NONMATCHING

float FUN_004aa2c0(void)

{
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  if (DAT_0095ef64 == 0) {
    ((code)FUN_004aae60)();
    fStack_c = 0.0;
    fStack_8 = 0.0;
    fStack_10 = DAT_0095ef5c * DAT_0095ef58 * (DAT_0095ee74 / DAT_0095ee7c);
    ((code)FUN_004c6c60)(&fStack_10,&fStack_10,0x95eed0);
    DAT_0095ef64 = 1;
    DAT_0095ef60 = fStack_8 * fStack_8 + fStack_10 * fStack_10 + fStack_c * fStack_c;
  }
  return DAT_0095ef60;
}

// FUN_004AA390 NONMATCHING

u8 FUN_004aa390(float param_1)

{
  if (0.0 < param_1) {
    DAT_0095ef64 = 0;
    DAT_0095ef5c = param_1;
  }
  return 0.0 < param_1;
}

// FUN_004AA3D0 NONMATCHING

u8 FUN_004aa3d0(float param_1)

{
  if (0.0 < param_1) {
    DAT_0095ef50 = 0;
    DAT_0095ef58 = param_1;
  }
  return 0.0 < param_1;
}

// FUN_004AA410 NONMATCHING

u32 FUN_004aa410(int param_1)

{
  int iVar1;
  int iVar2;
  u32 uVar3;
  
  iVar2 = param_1;
  if ((param_1 == 0) || (iVar1 = *(int *)(param_1 + 0x60), iVar2 = DAT_0095ef84, iVar1 == 0)) {
    DAT_0095ef84 = iVar2;
    uVar3 = 0;
  }
  else {
    DAT_0095ee80 = (float)*(int *)(iVar1 + 0x10);
    DAT_0095ee7c = (float)*(int *)(iVar1 + 0xc);
    DAT_0095ee74 = *(float *)(param_1 + 0x68) * 2.0;
    DAT_0095ee78 = *(float *)(param_1 + 0x6c) * 2.0;
    if ((*(u8 **)(param_1 + 0x1c) != &LAB_004a9be0) && (DAT_0095ef84 != param_1)) {
      DAT_0095efd0 = (u32)(*(u8 **)(param_1 + 0x1c));
      *(u8 **)(param_1 + 0x1c) = &LAB_004a9be0;
    }
    DAT_0095ef50 = 0;
    DAT_0095ef70 = 0;
    DAT_0095ef74 = 0;
    if (DAT_0095ee78 < DAT_0095ee74) {
      DAT_0095ef78 = DAT_0095ee74 / DAT_0095ee78;
      DAT_0095ef7c = 1.0;
    }
    else {
      DAT_0095ef7c = DAT_0095ee78 / DAT_0095ee74;
      DAT_0095ef78 = 1.0;
    }
    uVar3 = 1;
    DAT_0095ef84 = param_1;
  }
  return uVar3;
}

// FUN_004AA540
#pragma optimization_level 3

u32 FUN_004aa540(void)

{
  return *(u32 *)0x95ef84;
}
#pragma optimization_level 2

// FUN_004AA550 NONMATCHING

void FUN_004aa550(u64 param_1)

{
  DAT_0095ef54 = 0;
  ((code)FUN_004b1090)();
  ((code)FUN_004ac870)();
  ((code)FUN_004a5400)();
  ((code)FUN_004a9330)();
  ((code)FUN_004adb80)();
  ((code)FUN_004aa6c0)();
  ((code)FUN_004b1100)();
  ((code)FUN_004aa410)(param_1);
  return;
}

// FUN_004AA5C0 NONMATCHING

void FUN_004aa5c0(void)

{
  ((code)FUN_004b11a0)();
  ((code)FUN_004aa620)();
  ((code)FUN_004adb50)();
  ((code)FUN_004a91f0)();
  ((code)FUN_004a53b0)();
  ((code)FUN_004ac7f0)();
  ((code)FUN_004b1050)();
  ((code)FUN_004aa410)(0);
  return;
}

// FUN_004AA620 NONMATCHING

void FUN_004aa620(void)

{
  u16 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = (u16 *)((u8 *)DAT_0095e860);
  do {
    if (*(int *)(puVar1 + 0x2c8) != 0) {
      ((code)FUN_004c3880)();
      *(u32 *)(puVar1 + 0x2c8) = 0;
    }
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 2;
  } while (iVar2 < 0x20);
  DAT_0095ee70 = 0;
  if (DAT_0095f57c != 0) {
    (*DAT_0096017c)();
    DAT_0095f57c = 0;
    DAT_0095f580 = 0;
  }
  return;
}

// FUN_004AA6C0 NONMATCHING

u32 FUN_004aa6c0(void)

{
  short *psVar1;
  u16 *puVar2;
  short sVar3;
  int iVar4;
  
  DAT_0095ee70 = 0;
  *(u32 *)&DAT_0095edf0 = ((code)FUN_004c38c0)();
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x28) = 0x3f800000;
  psVar1 = (s16 *)((u8 *)DAT_0095e860);
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x14) = 0x3f800000;
  iVar4 = 0;
  *(u32 *)((u8 *)DAT_0095edf0)[DAT_0095ee70] = 0x3f800000;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x10) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 8) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 4) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x24) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x20) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x18) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x38) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x34) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0x30) = 0;
  *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0xc) =
       *(u32 *)(((u8 *)DAT_0095edf0)[DAT_0095ee70] + 0xc) | 0x20003;
  DAT_0095ef58 = 0x3f800000;
  DAT_0095ef5c = 0x3f000000;
  DAT_0095edd8 = 0x3f800000;
  DAT_0095ef68 = 7;
  DAT_0095edc4 = 0x3f800000;
  DAT_0095edb0 = 0x3f800000;
  DAT_0095ef64 = 0;
  DAT_0095ef50 = 0;
  DAT_0095edc0 = 0;
  DAT_0095edb8 = 0;
  DAT_0095edb4 = 0;
  DAT_0095edd4 = 0;
  DAT_0095edd0 = 0;
  DAT_0095edc8 = 0;
  DAT_0095ede8 = 0;
  DAT_0095ede4 = 0;
  DAT_0095ede0 = 0;
  DAT_0095edbc = DAT_0095edbc | 0x20003;
  do {
    sVar3 = (short)iVar4;
    *psVar1 = sVar3;
    psVar1[1] = sVar3 + 1;
    psVar1[2] = sVar3 + 2;
    psVar1[3] = sVar3 + 3;
    psVar1[4] = sVar3 + 4;
    psVar1[5] = sVar3 + 5;
    psVar1[6] = sVar3 + 6;
    psVar1[7] = sVar3 + 7;
    iVar4 = iVar4 + 8;
    psVar1 = psVar1 + 8;
  } while (iVar4 < 0x100);
  iVar4 = 1;
  puVar2 = (u16 *)((u8 *)DAT_0095e864);
  do {
    *(u32 *)(puVar2 + 0x2c8) = 0;
    iVar4 = iVar4 + 6;
    *(u32 *)(puVar2 + 0x2ca) = 0;
    *(u32 *)(puVar2 + 0x2cc) = 0;
    *(u32 *)(puVar2 + 0x2ce) = 0;
    *(u32 *)(puVar2 + 0x2d0) = 0;
    *(u32 *)(puVar2 + 0x2d2) = 0;
    puVar2 = puVar2 + 0xc;
  } while (iVar4 < 0x1a);
  ((u8 *)DAT_0095edf0)[iVar4] = 0;
  DAT_0095ef84 = 0;
  DAT_0095ef70 = 0;
  DAT_0095ef74 = 0;
  DAT_0095ef78 = 0x3f800000;
  DAT_0095ef7c = 0x3f800000;
  DAT_0095f57c = 0;
  DAT_0095f580 = 0;
  return 1;
}

// FUN_004AAA60 NONMATCHING

u8 FUN_004aaa60(void)

{
  u8 bVar1;
  u32 uVar2;
  int iVar3;
  u32 *puVar4;
  u32 *puVar5;
  
  bVar1 = DAT_0095ee70 < 0x1f;
  if (bVar1) {
    DAT_0095ee70 = DAT_0095ee70 + 1;
    if (((u8 *)DAT_0095edf0)[DAT_0095ee70] == 0) {
      uVar2 = ((code)FUN_004c38c0)();
      ((u8 *)DAT_0095edf0)[DAT_0095ee70] = uVar2;
    }
    iVar3 = 8;
    puVar5 = *(u32 **)((u8 *)DAT_0095edec + DAT_0095ee70 * 4);
    puVar4 = (u32 *)((u8 *)DAT_0095edf0)[DAT_0095ee70];
    do {
      iVar3 = iVar3 + -1;
      uVar2 = puVar5[1];
      *puVar4 = *puVar5;
      puVar5 = puVar5 + 2;
      puVar4[1] = uVar2;
      puVar4 = puVar4 + 2;
    } while (0 < iVar3);
  }
  return bVar1;
}

// FUN_004AAB40 NONMATCHING

u8 FUN_004aab40(long param_1)

{
  u8 bVar1;
  u32 uVar2;
  int iVar3;
  u32 *puVar4;
  u32 *puVar5;
  
  bVar1 = DAT_0095ee70 < 0x1f;
  if (bVar1) {
    DAT_0095ee70 = DAT_0095ee70 + 1;
    if (((u8 *)DAT_0095edf0)[DAT_0095ee70] == 0) {
      uVar2 = ((code)FUN_004c38c0)();
      ((u8 *)DAT_0095edf0)[DAT_0095ee70] = uVar2;
    }
    if (param_1 == 0) {
      iVar3 = 8;
      puVar5 = *(u32 **)((u8 *)DAT_0095edec + DAT_0095ee70 * 4);
      puVar4 = (u32 *)((u8 *)DAT_0095edf0)[DAT_0095ee70];
      do {
        iVar3 = iVar3 + -1;
        uVar2 = puVar5[1];
        *puVar4 = *puVar5;
        puVar5 = puVar5 + 2;
        puVar4[1] = uVar2;
        puVar4 = puVar4 + 2;
      } while (0 < iVar3);
    }
    else {
      ((code)FUN_004c2f30)(((u8 *)DAT_0095edf0)[DAT_0095ee70],param_1,
                   *(u32 *)((u8 *)DAT_0095edec + DAT_0095ee70 * 4));
    }
  }
  DAT_0095ef50 = 0;
  DAT_0095ef64 = 0;
  return bVar1;
}

// FUN_004AAC70 NONMATCHING

u8 FUN_004aac70(u32 *param_1)

{
  u8 bVar1;
  u32 uVar2;
  int iVar3;
  u32 *puVar4;
  
  bVar1 = DAT_0095ee70 < 0x1f;
  if (bVar1) {
    DAT_0095ee70 = DAT_0095ee70 + 1;
    if (((u8 *)DAT_0095edf0)[DAT_0095ee70] == 0) {
      uVar2 = ((code)FUN_004c38c0)();
      ((u8 *)DAT_0095edf0)[DAT_0095ee70] = uVar2;
    }
    iVar3 = 8;
    puVar4 = (u32 *)((u8 *)DAT_0095edf0)[DAT_0095ee70];
    do {
      iVar3 = iVar3 + -1;
      uVar2 = param_1[1];
      *puVar4 = *param_1;
      param_1 = param_1 + 2;
      puVar4[1] = uVar2;
      puVar4 = puVar4 + 2;
    } while (0 < iVar3);
  }
  DAT_0095ef50 = 0;
  DAT_0095ef64 = 0;
  return bVar1;
}

// FUN_004AAD50 NONMATCHING
void FUN_004aad50(void)
{
  if (0 < DAT_0095ee70) {
    DAT_0095ee70 = DAT_0095ee70 + -1;
    DAT_0095ef50 = 0;
    DAT_0095ef64 = 0;
  }
  return;
}

// FUN_004AADA0 NONMATCHING

u32 FUN_004aada0(u32 param_1,u32 param_2)

{
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  uStack_8 = 0x3f800000;
  uStack_10 = param_1;
  uStack_c = param_2;
  ((code)FUN_004c33d0)(((u8 *)DAT_0095edf0)[DAT_0095ee70],&uStack_10,1);
  DAT_0095ef50 = 0;
  DAT_0095ef64 = 0;
  return 1;
}

// FUN_004AAE00 NONMATCHING

u32 FUN_004aae00(u32 param_1,u32 param_2)

{
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  uStack_8 = 0;
  uStack_10 = param_1;
  uStack_c = param_2;
  ((code)FUN_004c35d0)(((u8 *)DAT_0095edf0)[DAT_0095ee70],&uStack_10,1);
  DAT_0095ef50 = 0;
  DAT_0095ef64 = 0;
  return 1;
}

// FUN_004AAE60 NONMATCHING

u8 * FUN_004aae60(void)

{
  float fVar1;
  u64 uVar2;
  float fVar3;
  float fVar4;
  u32 uStack_60;
  u32 uStack_5c;
  u32 uStack_58;
  u32 uStack_54;
  u32 uStack_50;
  u32 uStack_4c;
  u32 uStack_48;
  u32 uStack_44;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  float fStack_20;
  float fStack_1c;
  u32 uStack_18;
  float fStack_10;
  float fStack_c;
  u32 uStack_8;
  
  if (DAT_0095ef50 == 0) {
    fVar4 = DAT_0095ef58;
    if (*(int *)(DAT_0095ef84 + 0x14) == 2) {
      fVar4 = 1.0;
    }
    ((code)FUN_004c2f30)(&uStack_60,((u8 *)DAT_0095edf0)[DAT_0095ee70],0x95edb0);
    fVar1 = DAT_0095ee74;
    uStack_8 = 0x3f800000;
    fVar3 = DAT_0095ee78;
    fStack_10 = fVar4;
    fStack_c = fVar4;
    ((code)FUN_004c33d0)(&uStack_60,&fStack_10,2);
    fStack_c = fVar1;
    if (fVar3 <= fVar1) {
      fStack_c = fVar3;
    }
    fStack_10 = -fStack_c;
    uStack_8 = 0x3f800000;
    ((code)FUN_004c33d0)(&uStack_60,&fStack_10,2);
    uStack_18 = 0;
    fStack_20 = fVar1 * 0.5 * fVar4;
    fStack_1c = -(fVar3 * 0.5 * fVar4);
    ((code)FUN_004c35d0)(&uStack_60,&fStack_20,2);
    DAT_0095ee90 = uStack_60;
    DAT_0095ee94 = uStack_5c;
    DAT_0095eea0 = uStack_50;
    DAT_0095ee98 = uStack_58;
    DAT_0095eea4 = uStack_4c;
    DAT_0095ee9c = uStack_54;
    DAT_0095eea8 = uStack_48;
    DAT_0095eebc = uStack_34;
    DAT_0095eeac = uStack_44;
    DAT_0095eeb0 = uStack_40;
    DAT_0095eeb8 = uStack_38;
    DAT_0095eeb4 = uStack_3c;
    DAT_0095eecc = uStack_24;
    DAT_0095eec0 = uStack_30;
    DAT_0095eec4 = uStack_2c;
    DAT_0095eec8 = uStack_28;
    ((code)FUN_004c32a0)(0x95eed0,&uStack_60);
    DAT_0095ef50 = 1;
  }
  uVar2 = ((code)FUN_004cb2f0)(*(u32 *)(DAT_0095ef84 + 4));
  ((code)FUN_004c2f30)(0x95ef10,0x95ee90,uVar2);
  return (u8 *)DAT_0095ef10;
}

#pragma schedule on
// FUN_004AB0C0
u32 FUN_004ab0c0(void)
{
  return DAT_0095edf0_abs[DAT_0095ee70_abs[0]];
}

// FUN_004AB0E0 NONMATCHING

int FUN_004ab0e0(u64 param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)param_1;
  iVar1 = piVar2[5];
  if (*piVar2 != 0) {
    if (piVar2[1] == -1) {
      ((code)FUN_004c20b0)();
      *piVar2 = 0;
      goto LAB_004ab138;
    }
    (*DAT_0096017c)();
  }
  *piVar2 = 0;
LAB_004ab138:
  (*DAT_0096018c)(DAT_0095ed84,param_1);
  return iVar1;
}

// FUN_004AB170

void FUN_004ab170(u32 *param_1)

{
  FUN_004c1e60_typed(*param_1);
  param_1[2] = 0;
  param_1[3] = 1;
  return;
}

// FUN_004AB1B0 NONMATCHING

u64 FUN_004ab1b0(u64 param_1)

{
  u32 *puVar1;
  
  puVar1 = (u32 *)param_1;
  ((code)FUN_004ac390)(puVar1[5]);
  puVar1[5] = 0;
  ((code)FUN_004c1e60)(*puVar1);
  puVar1[2] = 0;
  puVar1[3] = 1;
  puVar1[6] = (u32)(puVar1);
  return param_1;
}

// FUN_004AB200 NONMATCHING

u64 FUN_004ab200(u32 param_1,u32 param_2,u64 param_3)

{
  u32 *puVar1;
  u32 uVar2;
  long lVar3;
  int iVar4;
  
  iVar4 = (int)param_3;
  lVar3 = ((code)FUN_004c2120)(**(u32 **)(iVar4 + 0x18));
  if (lVar3 == 0) {
    puVar1 = (u32 *)((code)FUN_004c1e70)(**(u32 **)(iVar4 + 0x18),0x30190);
    *puVar1 = 0;
    puVar1[1] = param_1;
    puVar1[2] = param_2;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
  }
  else {
    uVar2 = ((code)FUN_004ac570)();
    *(u32 *)(*(int *)(iVar4 + 0x18) + 0x14) = uVar2;
    ((code)FUN_004ac5f0)(*(u32 *)(*(int *)(iVar4 + 0x18) + 0x14));
    *(u32 *)(iVar4 + 0x18) = *(u32 *)(*(int *)(iVar4 + 0x18) + 0x14);
    ((code)FUN_004ab200)(param_1,param_2,param_3);
  }
  return param_3;
}

// FUN_004AB2C0 NONMATCHING

u64 FUN_004ab2c0(float param_1,float param_2,u64 param_3)

{
  u32 *puVar1;
  long lVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  lVar2 = ((code)FUN_004c2120)(**(u32 **)((int)param_3 + 0x18));
  puVar1 = (u32 *)((code)FUN_004c1e70)(**(u32 **)((int)param_3 + 0x18),0x30190);
  *puVar1 = 1;
  puVar1[1] = param_1;
  puVar1[2] = param_2;
  param_1 = (float)puVar1[-5] - param_1;
  param_2 = param_2 - (float)puVar1[-4];
  fVar4 = SQRT(param_2 * param_2 + param_1 * param_1);
  fVar3 = fVar4;
  if (0.0 < fVar4) {
    fVar3 = 1.0 / fVar4;
  }
  puVar1[3] = param_2 * fVar3;
  puVar1[4] = param_1 * fVar3;
  puVar1[5] = (float)puVar1[-1] + fVar4;
  if (lVar2 < 2) {
    puVar1[-3] = puVar1[3];
    puVar1[-2] = puVar1[4];
  }
  else {
    fVar5 = (float)puVar1[-3] + (float)puVar1[3];
    fVar4 = (float)puVar1[-2] + (float)puVar1[4];
    fVar3 = 1.0 / ((float)puVar1[-3] * fVar5 + (float)puVar1[-2] * fVar4);
    puVar1[-3] = fVar5 * fVar3;
    puVar1[-2] = fVar4 * fVar3;
  }
  return param_3;
}

// FUN_004AB410 NONMATCHING

u64
FUN_004ab410(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6,
            u64 param_7)

{
  u32 *puVar1;
  long lVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  iVar3 = (int)param_7;
  lVar2 = ((code)FUN_004c2120)(**(u32 **)(iVar3 + 0x18));
  puVar1 = (u32 *)((code)FUN_004c1f70)(**(u32 **)(iVar3 + 0x18),3,0x30190);
  *puVar1 = 2;
  puVar1[1] = param_1;
  puVar1[2] = param_2;
  param_1 = (float)puVar1[-5] - param_1;
  param_2 = param_2 - (float)puVar1[-4];
  fVar5 = SQRT(param_2 * param_2 + param_1 * param_1);
  fVar4 = fVar5;
  if (0.0 < fVar5) {
    fVar4 = 1.0 / fVar5;
  }
  puVar1[3] = param_2 * fVar4;
  puVar1[4] = param_1 * fVar4;
  puVar1[5] = (float)puVar1[-1] + fVar5;
  if (lVar2 < 2) {
    puVar1[-3] = puVar1[3];
    puVar1[-2] = puVar1[4];
  }
  else {
    fVar6 = (float)puVar1[-3] + (float)puVar1[3];
    fVar5 = (float)puVar1[-2] + (float)puVar1[4];
    fVar4 = 1.0 / ((float)puVar1[-3] * fVar6 + (float)puVar1[-2] * fVar5);
    puVar1[-3] = fVar6 * fVar4;
    puVar1[-2] = fVar5 * fVar4;
  }
  puVar1[6] = 2;
  puVar1[7] = param_3;
  puVar1[8] = param_4;
  param_3 = (float)puVar1[1] - param_3;
  param_4 = param_4 - (float)puVar1[2];
  fVar5 = SQRT(param_4 * param_4 + param_3 * param_3);
  fVar4 = fVar5;
  if (0.0 < fVar5) {
    fVar4 = 1.0 / fVar5;
  }
  puVar1[9] = param_4 * fVar4;
  puVar1[10] = param_3 * fVar4;
  puVar1[0xb] = (float)puVar1[5] + fVar5;
  puVar1[0xc] = 2;
  puVar1[0xd] = param_5;
  puVar1[0xe] = param_6;
  param_5 = (float)puVar1[7] - param_5;
  param_6 = param_6 - (float)puVar1[8];
  fVar5 = SQRT(param_6 * param_6 + param_5 * param_5);
  fVar4 = fVar5;
  if (0.0 < fVar5) {
    fVar4 = 1.0 / fVar5;
  }
  puVar1[0xf] = param_6 * fVar4;
  puVar1[0x10] = param_5 * fVar4;
  puVar1[0x11] = (float)puVar1[0xb] + fVar5;
  *(u32 *)(*(int *)(iVar3 + 0x18) + 0xc) = 0;
  return param_7;
}

// FUN_004AB6A0 NONMATCHING

u64 FUN_004ab6a0(u64 param_1)

{
  u32 *puVar1;
  int iVar2;
  int iVar3;
  u32 *puVar4;
  u64 uVar5;
  long lVar6;
  int iVar7;
  u32 uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  iVar7 = (int)param_1;
  puVar1 = *(u32 **)(iVar7 + 0x18);
  uVar5 = ((code)FUN_004c2120)(*puVar1);
  iVar2 = ((code)FUN_004c2090)(*puVar1);
  iVar3 = ((code)FUN_004c21b0)(*puVar1,(int)uVar5 + -1);
  fVar9 = *(float *)(iVar2 + 8);
  fVar10 = *(float *)(iVar2 + 4);
  if ((fVar9 - *(float *)(iVar3 + 8) != 0.0) || (*(float *)(iVar3 + 4) - fVar10 != 0.0)) {
    lVar6 = ((code)FUN_004c2120)(**(u32 **)(iVar7 + 0x18));
    puVar4 = (u32 *)((code)FUN_004c1e70)(**(u32 **)(iVar7 + 0x18),0x30190);
    *puVar4 = 1;
    puVar4[1] = fVar10;
    puVar4[2] = fVar9;
    fVar10 = (float)puVar4[-5] - fVar10;
    fVar9 = fVar9 - (float)puVar4[-4];
    fVar11 = SQRT(fVar9 * fVar9 + fVar10 * fVar10);
    fVar12 = fVar11;
    if (0.0 < fVar11) {
      fVar12 = 1.0 / fVar11;
    }
    puVar4[3] = fVar9 * fVar12;
    puVar4[4] = fVar10 * fVar12;
    puVar4[5] = (float)puVar4[-1] + fVar11;
    if (lVar6 < 2) {
      puVar4[-3] = puVar4[3];
      puVar4[-2] = puVar4[4];
    }
    else {
      fVar12 = (float)puVar4[-3] + (float)puVar4[3];
      fVar10 = (float)puVar4[-2] + (float)puVar4[4];
      fVar9 = 1.0 / ((float)puVar4[-3] * fVar12 + (float)puVar4[-2] * fVar10);
      puVar4[-3] = fVar12 * fVar9;
      puVar4[-2] = fVar10 * fVar9;
    }
    iVar2 = ((code)FUN_004c2090)(*puVar1);
    iVar3 = ((code)FUN_004c21b0)(*puVar1,uVar5);
  }
  fVar12 = *(float *)(iVar2 + 0xc) + *(float *)(iVar3 + 0xc);
  fVar10 = *(float *)(iVar2 + 0x10) + *(float *)(iVar3 + 0x10);
  fVar9 = 1.0 / (*(float *)(iVar2 + 0xc) * fVar12 + *(float *)(iVar2 + 0x10) * fVar10);
  *(float *)(iVar3 + 0xc) = fVar12 * fVar9;
  *(float *)(iVar3 + 0x10) = fVar10 * fVar9;
  uVar8 = *(u32 *)(iVar3 + 0x10);
  *(u32 *)(iVar2 + 0xc) = *(u32 *)(iVar3 + 0xc);
  *(u32 *)(iVar2 + 0x10) = uVar8;
  puVar1[2] = 1;
  return param_1;
}

// FUN_004AB8C0 NONMATCHING

u32 * FUN_004ab8c0(void)

{
  u32 *puVar1;
  
  puVar1 = (u32 *)(DAT_0095ed88);
  ((code)FUN_004ac390)(DAT_0095ed88[5]);
  puVar1[5] = 0;
  ((code)FUN_004c1e60)(*puVar1);
  puVar1[2] = 0;
  puVar1[3] = 1;
  puVar1[6] = (u32)(puVar1);
  return DAT_0095ed88;
}

// FUN_004AB910 NONMATCHING

void FUN_004ab910(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  fVar6 = param_1[4];
  fVar4 = param_1[3];
  fVar2 = param_1[1];
  fVar3 = param_1[5];
  fVar7 = (param_1[2] + fVar6) * 0.5;
  fVar5 = param_1[6];
  fVar1 = param_1[7];
  param_2[2] = (*param_1 + param_1[2]) * 0.5;
  param_2[3] = (fVar2 + fVar4) * 0.5;
  param_3[4] = (fVar5 + fVar6) * 0.5;
  param_3[5] = (fVar1 + fVar3) * 0.5;
  fVar5 = (fVar4 + fVar3) * 0.5;
  param_2[4] = (param_2[2] + fVar7) * 0.5;
  param_2[5] = (param_2[3] + fVar5) * 0.5;
  fVar4 = *param_1;
  fVar2 = param_1[1];
  fVar3 = param_1[6];
  fVar1 = param_1[7];
  param_3[2] = (param_3[4] + fVar7) * 0.5;
  param_3[3] = (param_3[5] + fVar5) * 0.5;
  fVar5 = param_3[3];
  param_2[6] = (param_2[4] + param_3[2]) * 0.5;
  param_2[7] = (param_2[5] + fVar5) * 0.5;
  *param_2 = fVar4;
  param_2[1] = fVar2;
  fVar2 = param_2[7];
  *param_3 = param_2[6];
  param_3[1] = fVar2;
  param_3[6] = fVar3;
  param_3[7] = fVar1;
  return;
}

// FUN_004ABA20 NONMATCHING

void FUN_004aba20(u64 param_1,u64 param_2,int param_3)

{
  u8 bVar1;
  u32 *puVar2;
  long lVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  u8 auStack_40 [32];
  u8 auStack_20 [32];
  
  pfVar4 = (float *)param_2;
  puVar2 = (u32 *)param_1;
  if (param_3 + -1 < 0) {
    lVar3 = ((code)FUN_004c2120)(*puVar2);
    puVar2 = (u32 *)((code)FUN_004c1e70)(*puVar2,0x30190);
    fVar6 = pfVar4[6];
    fVar11 = pfVar4[7];
    *puVar2 = 1;
    puVar2[1] = fVar6;
    puVar2[2] = fVar11;
    fVar11 = fVar11 - (float)puVar2[-4];
    fVar6 = (float)puVar2[-5] - fVar6;
    fVar9 = SQRT(fVar11 * fVar11 + fVar6 * fVar6);
    fVar5 = fVar9;
    if (0.0 < fVar9) {
      fVar5 = 1.0 / fVar9;
    }
    puVar2[3] = fVar11 * fVar5;
    puVar2[4] = fVar6 * fVar5;
    puVar2[5] = (float)puVar2[-1] + fVar9;
    if (lVar3 < 2) {
      puVar2[-3] = puVar2[3];
      puVar2[-2] = puVar2[4];
    }
    else {
      fVar6 = (float)puVar2[-3] + (float)puVar2[3];
      fVar11 = (float)puVar2[-2] + (float)puVar2[4];
      fVar5 = 1.0 / ((float)puVar2[-3] * fVar6 + (float)puVar2[-2] * fVar11);
      puVar2[-3] = fVar6 * fVar5;
      puVar2[-2] = fVar11 * fVar5;
    }
  }
  else {
    fVar9 = pfVar4[1];
    fVar11 = *pfVar4;
    fVar10 = pfVar4[7] - fVar9;
    fVar8 = pfVar4[2] - fVar11;
    fVar7 = pfVar4[6] - fVar11;
    fVar5 = pfVar4[3] - fVar9;
    fVar12 = fVar7 * fVar7 + fVar10 * fVar10;
    fVar6 = fVar8 * fVar7 + fVar5 * fVar10;
    bVar1 = 0;
    if (fVar12 * ((fVar8 * fVar8 + fVar5 * fVar5) - DAT_0095ef60) < fVar6 * fVar6) {
      fVar9 = pfVar4[5] - fVar9;
      fVar11 = pfVar4[4] - fVar11;
      fVar5 = fVar11 * fVar7 + fVar9 * fVar10;
      bVar1 = 1;
      if (fVar5 * fVar5 <= fVar12 * ((fVar11 * fVar11 + fVar9 * fVar9) - DAT_0095ef60)) {
        bVar1 = 0;
      }
    }
    if (bVar1) {
      lVar3 = ((code)FUN_004c2120)(*puVar2);
      puVar2 = (u32 *)((code)FUN_004c1e70)(*puVar2,0x30190);
      fVar6 = pfVar4[6];
      fVar11 = pfVar4[7];
      *puVar2 = 1;
      puVar2[1] = fVar6;
      puVar2[2] = fVar11;
      fVar11 = fVar11 - (float)puVar2[-4];
      fVar6 = (float)puVar2[-5] - fVar6;
      fVar9 = SQRT(fVar11 * fVar11 + fVar6 * fVar6);
      fVar5 = fVar9;
      if (0.0 < fVar9) {
        fVar5 = 1.0 / fVar9;
      }
      puVar2[3] = fVar11 * fVar5;
      puVar2[4] = fVar6 * fVar5;
      puVar2[5] = (float)puVar2[-1] + fVar9;
      if (lVar3 < 2) {
        puVar2[-3] = puVar2[3];
        puVar2[-2] = puVar2[4];
      }
      else {
        fVar6 = (float)puVar2[-3] + (float)puVar2[3];
        fVar11 = (float)puVar2[-2] + (float)puVar2[4];
        fVar5 = 1.0 / ((float)puVar2[-3] * fVar6 + (float)puVar2[-2] * fVar11);
        puVar2[-3] = fVar6 * fVar5;
        puVar2[-2] = fVar11 * fVar5;
      }
    }
    else {
      ((code)FUN_004ab910)(param_2,auStack_20,auStack_40);
      ((code)FUN_004aba20)(param_1);
      ((code)FUN_004aba20)(param_1,auStack_40,param_3 + -1);
    }
  }
  return;
}

// FUN_004ABD50 NONMATCHING

u64 FUN_004abd50(u64 param_1,u32 *param_2)

{
  int *piVar1;
  int iVar2;
  u32 *puVar3;
  int *piVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  int iVar12;
  float fVar13;
  int iStack_20;
  int iStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  DAT_0095ef60 = ((code)FUN_004aa2c0)();
  if (param_2[1] == -1) {
    piVar1 = (int *)((code)FUN_004c2090)(*param_2);
    iVar2 = param_2[1];
  }
  else {
    piVar1 = (int *)*param_2;
    iVar2 = param_2[1];
  }
  if (iVar2 == -1) {
    iVar2 = ((code)FUN_004c2120)(*param_2);
  }
  iVar6 = 0;
  if (0 < iVar2) {
    do {
      if (*piVar1 == 2) {
        iStack_20 = piVar1[-5];
        iStack_1c = piVar1[-4];
        iStack_18 = piVar1[1];
        iStack_14 = piVar1[2];
        iStack_10 = piVar1[7];
        iStack_c = piVar1[8];
        iStack_8 = piVar1[0xd];
        iStack_4 = piVar1[0xe];
        ((code)FUN_004aba20)(param_1,&iStack_20,DAT_0095ef68);
        iVar6 = iVar6 + 2;
        piVar1 = piVar1 + 0xc;
      }
      else {
        puVar3 = (u32 *)param_1;
        if (*piVar1 == 1) {
          lVar5 = ((code)FUN_004c2120)(*puVar3);
          puVar3 = (u32 *)((code)FUN_004c1e70)(*puVar3,0x30190);
          *puVar3 = 1;
          puVar3[1] = piVar1[1];
          puVar3[2] = piVar1[2];
          fVar11 = (float)puVar3[-5] - (float)piVar1[1];
          fVar10 = (float)piVar1[2] - (float)puVar3[-4];
          fVar13 = SQRT(fVar10 * fVar10 + fVar11 * fVar11);
          fVar8 = fVar13;
          if (0.0 < fVar13) {
            fVar8 = 1.0 / fVar13;
          }
          puVar3[3] = fVar10 * fVar8;
          puVar3[4] = fVar11 * fVar8;
          puVar3[5] = (float)puVar3[-1] + fVar13;
          if (lVar5 < 2) {
            puVar3[-3] = puVar3[3];
            puVar3[-2] = puVar3[4];
          }
          else {
            fVar11 = (float)puVar3[-3] + (float)puVar3[3];
            fVar10 = (float)puVar3[-2] + (float)puVar3[4];
            fVar8 = 1.0 / ((float)puVar3[-3] * fVar11 + (float)puVar3[-2] * fVar10);
            puVar3[-3] = fVar11 * fVar8;
            puVar3[-2] = fVar10 * fVar8;
          }
        }
        else {
          piVar4 = (int *)((code)FUN_004c1e70)(*puVar3,0x301a1);
          iVar12 = piVar1[1];
          iVar7 = piVar1[2];
          iVar9 = piVar1[3];
          *piVar4 = *piVar1;
          piVar4[1] = iVar12;
          piVar4[2] = iVar7;
          piVar4[3] = iVar9;
          iVar7 = piVar1[5];
          piVar4[4] = piVar1[4];
          piVar4[5] = iVar7;
        }
      }
      iVar6 = iVar6 + 1;
      piVar1 = piVar1 + 6;
    } while (iVar6 < iVar2);
  }
  if (param_2[2] != 0) {
    ((code)FUN_004ab6a0)(param_1);
  }
  return param_1;
}

// FUN_004AC020 NONMATCHING

u64 FUN_004ac020(int *param_1,u64 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  float fVar5;
  
  if (param_1[1] == -1) {
    iVar1 = ((code)FUN_004c2090)(*param_1);
  }
  else {
    iVar1 = *param_1;
  }
  iVar2 = param_1[1];
  if (iVar2 == -1) {
    iVar2 = ((code)FUN_004c2120)(*param_1);
  }
  iVar3 = 0;
  if (0 < iVar2) {
    do {
      fVar5 = *(float *)(iVar1 + 4);
      pfVar4 = (float *)param_2;
      if (*pfVar4 <= fVar5) {
        if (pfVar4[2] < fVar5) {
          pfVar4[2] = fVar5;
        }
      }
      else {
        *pfVar4 = fVar5;
      }
      fVar5 = *(float *)(iVar1 + 8);
      if (pfVar4[1] <= fVar5) {
        if (pfVar4[3] < fVar5) {
          pfVar4[3] = fVar5;
        }
      }
      else {
        pfVar4[1] = fVar5;
      }
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + 0x18;
    } while (iVar3 < iVar2);
  }
  return param_2;
}

// FUN_004AC120 NONMATCHING

int * FUN_004ac120(int *param_1,u64 param_2)

{
  int *piVar1;
  int iVar2;
  float *pfVar3;
  float fVar4;
  
  if (param_1[1] == -1) {
    iVar2 = ((code)FUN_004c2090)(*param_1);
    fVar4 = *(float *)(iVar2 + 4);
  }
  else {
    iVar2 = *param_1;
    fVar4 = *(float *)(iVar2 + 4);
  }
  pfVar3 = (float *)param_2;
  pfVar3[2] = fVar4;
  *pfVar3 = fVar4;
  fVar4 = *(float *)(iVar2 + 8);
  pfVar3[3] = fVar4;
  pfVar3[1] = fVar4;
  iVar2 = (int)(DAT_0095ed88);
  for (piVar1 = param_1; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[5]) {
    DAT_0095ed88 = (u32 *)iVar2;
    if (piVar1[3] == 0) {
      *(u32 *)(iVar2 + 0x14) = 0;
      ((code)FUN_004ab170)(iVar2);
      *(int *)(iVar2 + 0x18) = iVar2;
      iVar2 = (int)(DAT_0095ed88);
      ((code)FUN_004abd50)(DAT_0095ed88,piVar1);
      ((code)FUN_004ac020)(iVar2,param_2);
    }
    else {
      ((code)FUN_004ac020)(piVar1,param_2);
    }
    iVar2 = (int)(DAT_0095ed88);
  }
  pfVar3[2] = pfVar3[2] - *pfVar3;
  pfVar3[3] = pfVar3[3] - pfVar3[1];
  return param_1;
}

// FUN_004AC240 NONMATCHING

int * FUN_004ac240(int *param_1)

{
  int *piVar1;
  u32 uVar2;
  u32 *puVar3;
  u32 *puVar4;
  u32 *puVar5;
  long lVar6;
  
  if (param_1 == (int *)0x0) {
    return (int *)0x0;
  }
  puVar5 = (u32 *)param_1[5];
  if (puVar5 != (u32 *)0x0) {
    puVar4 = (u32 *)puVar5[5];
    if (puVar4 != (u32 *)0x0) {
      puVar3 = (u32 *)puVar4[5];
      if (puVar3 != (u32 *)0x0) {
        uVar2 = ((code)FUN_004ac240)(puVar3[5]);
        puVar3[5] = uVar2;
        lVar6 = ((code)FUN_004c2120)(*puVar3);
        if (lVar6 == 1) {
          puVar3 = (u32 *)((code)FUN_004ab0e0)(puVar3);
        }
      }
      puVar4[5] = (u32)(puVar3);
      lVar6 = ((code)FUN_004c2120)(*puVar4);
      if (lVar6 == 1) {
        puVar4 = (u32 *)((code)FUN_004ab0e0)(puVar4);
      }
    }
    puVar5[5] = (u32)(puVar4);
    lVar6 = ((code)FUN_004c2120)(*puVar5);
    if (lVar6 == 1) {
      puVar5 = (u32 *)((code)FUN_004ab0e0)(puVar5);
    }
  }
  param_1[5] = (int)puVar5;
  lVar6 = ((code)FUN_004c2120)(*param_1);
  if (lVar6 != 1) {
    return param_1;
  }
  piVar1 = (int *)param_1[5];
  if (*param_1 != 0) {
    if (param_1[1] == -1) {
      ((code)FUN_004c20b0)();
      *param_1 = 0;
      goto LAB_004ac350;
    }
    (*DAT_0096017c)();
  }
  *param_1 = 0;
LAB_004ac350:
  (*DAT_0096018c)(DAT_0095ed84,param_1);
  return piVar1;
}

// FUN_004AC390 NONMATCHING

u8 FUN_004ac390(long param_1)

{
  long lVar1;
  u64 uVar2;
  
  if ((((param_1 != 0) && (lVar1 = ((code)FUN_004ab0e0)(), lVar1 != 0)) &&
      (lVar1 = ((code)FUN_004ab0e0)(lVar1), lVar1 != 0)) && (lVar1 = ((code)FUN_004ab0e0)(lVar1), lVar1 != 0)) {
    uVar2 = ((code)FUN_004ab0e0)(lVar1);
    ((code)FUN_004ac390)(uVar2);
  }
  return param_1 != 0;
}

// FUN_004AC410 NONMATCHING

void FUN_004ac410(int *param_1)

{
  int *piVar1;
  long lVar2;
  u64 uVar3;
  
  if (param_1[1] == -1) {
    ((code)FUN_004c20b0)(*param_1);
    *param_1 = 0;
  }
  else {
    if (*param_1 != 0) {
      (*DAT_0096017c)();
    }
    *param_1 = 0;
  }
  param_1[1] = 0;
  piVar1 = (int *)param_1[5];
  if (piVar1 != (int *)0x0) {
    if (piVar1[1] == -1) {
      ((code)FUN_004c20b0)(*piVar1);
      *piVar1 = 0;
    }
    else {
      if (*piVar1 != 0) {
        (*DAT_0096017c)();
      }
      *piVar1 = 0;
    }
    piVar1[1] = 0;
    if (piVar1[5] != 0) {
      ((code)FUN_004ac410)();
      if ((piVar1[5] != 0) && (lVar2 = ((code)FUN_004ab0e0)(), lVar2 != 0)) {
        uVar3 = ((code)FUN_004ab0e0)();
        ((code)FUN_004ac390)(uVar3);
      }
      piVar1[5] = 0;
    }
    if (((param_1[5] != 0) && (lVar2 = ((code)FUN_004ab0e0)(), lVar2 != 0)) &&
       (lVar2 = ((code)FUN_004ab0e0)(), lVar2 != 0)) {
      uVar3 = ((code)FUN_004ab0e0)();
      ((code)FUN_004ac390)(uVar3);
    }
    param_1[5] = 0;
  }
  return;
}

// FUN_004AC570 NONMATCHING

long FUN_004ac570(void)

{
  long lVar1;
  u32 *puVar2;
  
  lVar1 = (*DAT_00960188)(DAT_0095ed84,0x301a1);
  if (lVar1 != 0) {
    puVar2 = (u32 *)lVar1;
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 1;
    puVar2[5] = 0;
    puVar2[6] = (u32)(puVar2);
    puVar2[4] = 0;
    ((code)FUN_004ac5f0)(lVar1);
  }
  return lVar1;
}

// FUN_004AC5F0 NONMATCHING

long FUN_004ac5f0(long param_1)

{
  u32 uVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  u32 *puVar5;
  
  if ((param_1 != 0) && (puVar5 = (u32 *)param_1, puVar5[1] != -1)) {
    lVar3 = ((code)FUN_004c1d50)(0x18,0x301a1);
    if (lVar3 == 0) {
      param_1 = 0;
    }
    else {
      if (puVar5[1] == -1) {
        uVar1 = ((code)FUN_004c2090)(*puVar5);
        iVar2 = puVar5[1];
      }
      else {
        uVar1 = *puVar5;
        iVar2 = puVar5[1];
      }
      if (iVar2 == -1) {
        iVar2 = ((code)FUN_004c2120)(*puVar5);
      }
      if (iVar2 != 0) {
        lVar4 = ((code)FUN_004c1f70)(lVar3,iVar2,0x301a1);
        if (lVar4 != 0) {
          ((code)FUN_00521250)(lVar4,uVar1,iVar2 * 0x18);
        }
        (*DAT_0096017c)(uVar1);
      }
      puVar5[1] = 0xffffffff;
      *puVar5 = (int)lVar3;
      ((code)FUN_004ac5f0)(puVar5[5]);
    }
  }
  return param_1;
}

// FUN_004AC710 NONMATCHING

long FUN_004ac710(long param_1)

{
  u32 uVar1;
  u32 uVar2;
  u32 *puVar3;
  
  if ((param_1 != 0) && (puVar3 = (u32 *)param_1, puVar3[1] == -1)) {
    uVar1 = ((code)FUN_004c2120)(*puVar3);
    uVar2 = ((code)FUN_004c2130)(*puVar3);
    *puVar3 = uVar2;
    puVar3[1] = uVar1;
    puVar3 = (u32 *)puVar3[5];
    if ((puVar3 != (u32 *)0x0) && (puVar3[1] == -1)) {
      uVar1 = ((code)FUN_004c2120)(*puVar3);
      uVar2 = ((code)FUN_004c2130)(*puVar3);
      *puVar3 = uVar2;
      puVar3[1] = uVar1;
      puVar3 = (u32 *)puVar3[5];
      if ((puVar3 != (u32 *)0x0) && (puVar3[1] == -1)) {
        uVar1 = ((code)FUN_004c2120)(*puVar3);
        uVar2 = ((code)FUN_004c2130)(*puVar3);
        *puVar3 = uVar2;
        puVar3[1] = uVar1;
        ((code)FUN_004ac710)(puVar3[5]);
      }
    }
  }
  return param_1;
}

// FUN_004AC7F0 NONMATCHING

void FUN_004ac7f0(void)

{
  long lVar1;
  u64 uVar2;
  
  if (((DAT_0095ed88 != 0) && (lVar1 = ((code)FUN_004ab0e0)(), lVar1 != 0)) &&
     (lVar1 = ((code)FUN_004ab0e0)(lVar1), lVar1 != 0)) {
    uVar2 = ((code)FUN_004ab0e0)(lVar1);
    ((code)FUN_004ac390)(uVar2);
  }
  ((code)FUN_004c3c30)(DAT_0095ed84);
  DAT_0095ed84 = 0;
  return;
}

// FUN_004AC860
#pragma optimization_level 3

void FUN_004ac860(u32 param_1,u32 param_2)

{
  DAT_007cdcc4 = param_1;
  DAT_007cdcc8 = param_2;
  return;
}
#pragma optimization_level 2

// FUN_004AC870 NONMATCHING

u32 FUN_004ac870(void)

{
  u64 uVar1;
  long lVar2;
  u32 *puVar3;
  
  uVar1 = thunk_FUN_004c3970(0x1c,DAT_007cdcc4,4,DAT_007cdcc8,0x95f990,0x401a1);
  DAT_0095ed84 = (u32)uVar1;
  lVar2 = (*DAT_00960188)(uVar1,0x301a1);
  puVar3 = (u32 *)lVar2;
  if (lVar2 != 0) {
    *puVar3 = 0;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 1;
    puVar3[5] = 0;
    puVar3[6] = (u32)(puVar3);
    puVar3[4] = 0;
    ((code)FUN_004ac5f0)(lVar2);
  }
  DAT_0095ed88 = (u32 *)((u32)(puVar3));
  ((code)FUN_004ac5f0)(lVar2);
  return 1;
}

// FUN_004AC920 NONMATCHING

u64 FUN_004ac920(u64 param_1,int param_2,u64 param_3)

{
  int iVar1;
  long lVar2;
  u64 uVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = (int *)param_1;
  if (piVar4[1] == -1) {
    ((code)FUN_004c20b0)(*piVar4);
    *piVar4 = 0;
  }
  else {
    if (*piVar4 != 0) {
      (*DAT_0096017c)();
    }
    *piVar4 = 0;
  }
  piVar4[1] = 0;
  if (piVar4[5] != 0) {
    ((code)FUN_004ac410)();
    if ((piVar4[5] != 0) && (lVar2 = ((code)FUN_004ab0e0)(), lVar2 != 0)) {
      uVar3 = ((code)FUN_004ab0e0)(lVar2);
      ((code)FUN_004ac390)(uVar3);
    }
    piVar4[5] = 0;
  }
  piVar4[6] = (int)piVar4;
  piVar4[1] = *(int *)(param_2 + 4);
  piVar4[2] = (u32)((*(u32 *)(param_2 + 8) & 1) != 0);
  piVar4[3] = (u32)((*(u32 *)(param_2 + 8) & 2) != 0);
  piVar4[4] = *(int *)(param_2 + 0xc);
  lVar2 = (*DAT_00960178)(piVar4[1] * 0x18,0x301a1);
  if (lVar2 == 0) {
    param_1 = 0;
  }
  else if ((piVar4[1] == 0) ||
          (iVar5 = piVar4[1] * 0x18, iVar1 = ((code)FUN_004c5250)(param_3,lVar2,iVar5), iVar5 == iVar1)) {
    *piVar4 = (int)lVar2;
    if ((*(u32 *)(param_2 + 8) & 4) != 0) {
      lVar2 = ((code)FUN_004c1600)(param_3,0x1a1,0,0);
      if (lVar2 == 0) {
        return 0;
      }
      iVar1 = ((code)FUN_004acb90)(param_3);
      piVar4[5] = iVar1;
    }
    for (iVar1 = piVar4[5]; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x14)) {
      *(int **)(iVar1 + 0x18) = piVar4;
    }
  }
  else {
    param_1 = 0;
  }
  return param_1;
}

// FUN_004ACB10 NONMATCHING

u64 FUN_004acb10(u64 param_1,u64 param_2)

{
  long lVar1;
  int aiStack_10 [4];
  
  lVar1 = ((code)FUN_004c5250)(param_2,aiStack_10,0x10);
  if (lVar1 == 0x10) {
    if (aiStack_10[0] == 1) {
      param_1 = ((code)FUN_004ac920)(param_1,aiStack_10,param_2);
    }
  }
  else {
    param_1 = 0;
  }
  return param_1;
}

// FUN_004ACB90 NONMATCHING

long FUN_004acb90(u64 param_1)

{
  long lVar1;
  long lVar2;
  u64 uVar3;
  u32 *puVar4;
  int aiStack_10 [4];
  
  lVar1 = (*DAT_00960188)(DAT_0095ed84,0x301a1);
  if (lVar1 != 0) {
    puVar4 = (u32 *)lVar1;
    *puVar4 = 0;
    puVar4[1] = 0;
    puVar4[2] = 0;
    puVar4[3] = 1;
    puVar4[5] = 0;
    puVar4[6] = (u32)(puVar4);
    puVar4[4] = 0;
    ((code)FUN_004ac5f0)(lVar1);
  }
  lVar2 = ((code)FUN_004c5250)(param_1,aiStack_10,0x10);
  if (lVar2 == 0x10) {
    lVar2 = lVar1;
    if (aiStack_10[0] == 1) {
      lVar2 = ((code)FUN_004ac920)(lVar1,aiStack_10,param_1);
    }
  }
  else {
    lVar2 = 0;
  }
  if ((((lVar2 == 0) && (lVar1 != 0)) && (lVar1 = ((code)FUN_004ab0e0)(lVar1), lVar1 != 0)) &&
     (lVar1 = ((code)FUN_004ab0e0)(lVar1), lVar1 != 0)) {
    uVar3 = ((code)FUN_004ab0e0)(lVar1);
    ((code)FUN_004ac390)(uVar3);
  }
  return lVar2;
}

// FUN_004ACCC0 NONMATCHING

u8 FUN_004accc0(float *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  u32 uVar3;
  u32 uVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  uVar4 = 0;
  if (param_2[1] == -1) {
    iVar1 = ((code)FUN_004c2090)(*param_2);
  }
  else {
    iVar1 = *param_2;
  }
  iVar5 = 0;
  iVar6 = iVar1;
  while( 1 ) {
    iVar2 = param_2[1];
    if (iVar2 == -1) {
      iVar2 = ((code)FUN_004c2120)(*param_2);
    }
    if (iVar2 + -1 <= iVar5) break;
    fVar12 = *(float *)(iVar6 + 0x20);
    fVar7 = *(float *)(iVar1 + 8);
    fVar8 = fVar7;
    if (fVar12 < fVar7) {
      fVar8 = fVar12;
    }
    fVar9 = param_1[1];
    if (fVar8 < fVar9) {
      fVar8 = fVar7;
      if (fVar7 < fVar12) {
        fVar8 = fVar12;
      }
      if (fVar9 <= fVar8) {
        fVar11 = *(float *)(iVar6 + 0x1c);
        fVar10 = *(float *)(iVar1 + 4);
        fVar8 = fVar10;
        if (fVar10 < fVar11) {
          fVar8 = fVar11;
        }
        if (((*param_1 <= fVar8) && (fVar7 != fVar12)) &&
           ((fVar10 == fVar11 ||
            (*param_1 <= fVar10 + ((fVar9 - fVar7) * (fVar11 - fVar10)) / (fVar12 - fVar7))))) {
          uVar4 = uVar4 + 1;
        }
      }
    }
    iVar1 = iVar1 + 0x18;
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 0x18;
  }
  uVar3 = uVar4 & 1;
  if (((int)uVar4 < 0) && (uVar3 != 0)) {
    uVar3 = uVar3 - 2;
  }
  return uVar3 != 0;
}



// FUN_004ace60 thunk_FUN_004accc0 NONMATCHING

u8 thunk_FUN_004accc0(float *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  u32 uVar3;
  u32 uVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  uVar4 = 0;
  if (param_2[1] == -1) {
    iVar1 = ((code)FUN_004c2090)(*param_2);
  }
  else {
    iVar1 = *param_2;
  }
  iVar5 = 0;
  iVar6 = iVar1;
  while( 1 ) {
    iVar2 = param_2[1];
    if (iVar2 == -1) {
      iVar2 = ((code)FUN_004c2120)(*param_2);
    }
    if (iVar2 + -1 <= iVar5) break;
    fVar12 = *(float *)(iVar6 + 0x20);
    fVar7 = *(float *)(iVar1 + 8);
    fVar8 = fVar7;
    if (fVar12 < fVar7) {
      fVar8 = fVar12;
    }
    fVar9 = param_1[1];
    if (fVar8 < fVar9) {
      fVar8 = fVar7;
      if (fVar7 < fVar12) {
        fVar8 = fVar12;
      }
      if (fVar9 <= fVar8) {
        fVar11 = *(float *)(iVar6 + 0x1c);
        fVar10 = *(float *)(iVar1 + 4);
        fVar8 = fVar10;
        if (fVar10 < fVar11) {
          fVar8 = fVar11;
        }
        if (((*param_1 <= fVar8) && (fVar7 != fVar12)) &&
           ((fVar10 == fVar11 ||
            (*param_1 <= fVar10 + ((fVar9 - fVar7) * (fVar11 - fVar10)) / (fVar12 - fVar7))))) {
          uVar4 = uVar4 + 1;
        }
      }
    }
    iVar1 = iVar1 + 0x18;
    iVar5 = iVar5 + 1;
    iVar6 = iVar6 + 0x18;
  }
  uVar3 = uVar4 & 1;
  if (((int)uVar4 < 0) && (uVar3 != 0)) {
    uVar3 = uVar3 - 2;
  }
  return uVar3 != 0;
}



// FUN_004ace70 thunk_FUN_0046bab0 NONMATCHING

long thunk_FUN_0046bab0(long param_1,u64 param_2)

{
  u32 *puVar1;
  u32 uVar2;
  int iVar3;
  int iVar4;
  u16 *puVar5;
  long lVar6;
  int iVar7;
  int *piVar8;
  u32 uVar9;
  int iVar10;
  
  if (param_1 != 0) {
    iVar10 = (int)param_1;
    lVar6 = param_1;
    if (*(int *)(iVar10 + 0xc) == 0) {
      lVar6 = ((code)FUN_004ab8c0)();
      ((code)FUN_004abd50)(lVar6,param_1);
    }
    piVar8 = (int *)lVar6;
    if (piVar8[1] == -1) {
      iVar3 = ((code)FUN_004c2090)(*piVar8);
    }
    else {
      iVar3 = *piVar8;
    }
    iVar4 = piVar8[1];
    if (iVar4 == -1) {
      iVar4 = ((code)FUN_004c2120)(*piVar8);
    }
    puVar1 = *(u32 **)((int)param_2 + 0x68);
    if (puVar1 == (u32 *)0x0) {
      (*DAT_00960090)(1,0);
    }
    else {
      uVar2 = puVar1[0x14];
      uVar9 = (uVar2 & 0xf000) >> 0xc;
      if ((uVar2 & 0xf00) >> 8 != uVar9) {
        uVar9 = 0;
      }
      (*DAT_00960090)(1,*puVar1);
      (*DAT_00960090)(9,uVar2 & 0xff);
      (*DAT_00960090)(2,uVar9);
    }
    DAT_0095efa4 = *(u32 *)(iVar4 * 0x18 + iVar3 + -4);
    DAT_0095efa0 = *(u32 *)(iVar10 + 0x10);
    DAT_0095ef88 = (int)param_2;
    puVar5 = (u16 *)((code)FUN_004f2710)();
    iVar7 = iVar4 + -0x28;
    if (iVar7 < 1) {
      DAT_0095efc8 = 0;
    }
    else {
      DAT_0095efc8 = iVar7 / 0x27 + 1;
      if (iVar7 % 0x27 == 0) {
        DAT_0095efc8 = iVar7 / 0x27;
      }
    }
    DAT_0095efc4 = iVar4 + DAT_0095efc8;
    DAT_0095ef98 = iVar3;
    *puVar5 = (short)DAT_0095efc4;
    *(u32 *)(puVar5 + 2) = DAT_0095ed64;
    *(u32 *)(puVar5 + 4) = 0x14;
    lVar6 = ((code)FUN_004f2e70)(DAT_0095f040,puVar5 + 6,0);
    if (lVar6 == 0) {
      param_1 = 0;
    }
    else {
      ((code)FUN_0046bab0)(*(u32 *)(iVar10 + 0x14),param_2);
    }
  }
  return param_1;
}

// FUN_004ACE80 NONMATCHING

int FUN_004ace80(int param_1,float *param_2,u64 param_3,u32 *param_4,int *param_5)

{
  u8 uVar1;
  u8 uVar2;
  u8 uVar3;
  int iVar4;
  int iVar5;
  u32 uVar6;
  float fVar7;
  u64 uVar8;
  u32 uVar9;
  int *piVar10;
  u32 uVar11;
  float *pfVar12;
  u8 *puVar13;
  float *pfVar14;
  u32 uVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  int iStack_50;
  int iStack_4c;
  int *piStack_40;
  int iStack_30;
  int iStack_20;
  u8 uStack_4;
  u8 uStack_3;
  u8 uStack_2;
  u8 uStack_1;
  
  fVar7 = param_2[0x1b];
  if (fVar7 == 0.0) {
    fVar7 = (float)((code)FUN_00494be0)();
    if (param_2[0x1a] != 0.0) {
      ((code)FUN_00494d50)(fVar7);
    }
    if (((u32)param_2[0x19] & 1) == 0) {
      uVar1 = *(u8 *)((int)param_2 + 0x61);
      uVar2 = *(u8 *)((int)param_2 + 0x62);
      uVar3 = *(u8 *)((int)param_2 + 99);
      *(u8 *)((int)fVar7 + 4) = *(u8 *)(param_2 + 0x18);
      *(u8 *)((int)fVar7 + 5) = uVar1;
      *(u8 *)((int)fVar7 + 6) = uVar2;
      *(u8 *)((int)fVar7 + 7) = uVar3;
    }
    else {
      uStack_4 = (u8)DAT_007cdccc;
      uStack_3 = (u8)((u32)DAT_007cdccc >> 8);
      uStack_2 = (u8)((u32)DAT_007cdccc >> 0x10);
      uStack_1 = (u8)((u32)DAT_007cdccc >> 0x18);
      *(u8 *)((int)fVar7 + 4) = uStack_4;
      *(u8 *)((int)fVar7 + 5) = uStack_3;
      *(u8 *)((int)fVar7 + 6) = uStack_2;
      *(u8 *)((int)fVar7 + 7) = uStack_1;
    }
    param_2[0x1b] = fVar7;
  }
  else {
    *(short *)((int)fVar7 + 0x18) = *(short *)((int)fVar7 + 0x18) + 1;
  }
  iStack_20 = 0;
  iStack_30 = 0;
  piVar10 = *(int **)(param_1 + 0x14);
  do {
    iVar4 = piVar10[1];
    if (iVar4 == -1) {
      iVar4 = ((code)FUN_004c2120)(*piVar10);
    }
    piVar10 = (int *)piVar10[5];
    iStack_20 = iStack_20 + iVar4 * 2;
    iStack_30 = iStack_30 + iVar4 * 2 + -2;
    piStack_40 = *(int **)(param_1 + 0x14);
  } while (piVar10 != piStack_40);
  fVar26 = param_2[0x1c];
  if ((iStack_30 != 0) && (iStack_20 != 0)) {
    iVar5 = (int)param_3;
    uVar15 = *param_4;
    puVar13 = (u8 *)(*(int *)(iVar5 + 0x30) + uVar15 * 4);
    pfVar14 = (float *)(*(int *)(*(int *)(iVar5 + 0x5c) + 0x14) + uVar15 * 0xc);
    iVar4 = *(int *)(iVar5 + 0x2c) + *param_5 * 8;
    pfVar12 = (float *)(*(int *)(iVar5 + 0x34) + uVar15 * 8);
    fVar25 = DAT_0095ef58;
    do {
      fVar27 = (float)piStack_40[4];
      if (piStack_40[1] == -1) {
        iVar5 = ((code)FUN_004c2090)(*piStack_40);
      }
      else {
        iVar5 = *piStack_40;
      }
      iStack_50 = piStack_40[1];
      iStack_4c = iStack_50 >> 0x1f;
      if (iStack_50 == -1) {
        uVar8 = ((code)FUN_004c2120)(*piStack_40);
        iStack_50 = (int)uVar8;
        iStack_4c = (int)((u32)uVar8 >> 0x20);
      }
      uVar6 = uVar15 + iStack_50 * 2;
      uVar9 = 0;
      fVar16 = 1.0 / *(float *)(iVar5 + iStack_50 * 0x18 + -4);
      if (CONCAT44(iStack_4c,iStack_50) != 0) {
        fVar17 = fVar26 + fVar27;
        fVar27 = fVar26 - fVar27;
        do {
          fVar21 = *(float *)(iVar5 + 0x10);
          *pfVar14 = (*(float *)(iVar5 + 4) + 0.0) - *(float *)(iVar5 + 0xc) * fVar17;
          pfVar14[1] = *(float *)(iVar5 + 8) - fVar21 * fVar17;
          pfVar14[2] = fVar25;
          if (((u32)param_2[0x19] & 1) == 0) {
            *puVar13 = 0xff;
            puVar13[1] = 0xff;
            puVar13[2] = 0xff;
            puVar13[3] = 0xff;
          }
          else {
            fVar22 = param_2[8];
            fVar21 = param_2[9];
            fVar20 = param_2[7];
            fVar24 = *(float *)(iVar5 + 0x14) * fVar16;
            fVar23 = param_2[1];
            fVar18 = param_2[2];
            fVar19 = param_2[3];
            *puVar13 = (char)(int)(param_2[6] * fVar24 + *param_2);
            puVar13[1] = (char)(int)(fVar20 * fVar24 + fVar23);
            puVar13[2] = (char)(int)(fVar22 * fVar24 + fVar18);
            puVar13[3] = (char)(int)(fVar21 * fVar24 + fVar19);
          }
          if (((u32)param_2[0x19] & 2) != 0) {
            fVar18 = param_2[0xb];
            fVar21 = param_2[5];
            fVar19 = *(float *)(iVar5 + 0x14) * fVar16;
            *pfVar12 = param_2[10] * fVar19 + param_2[4];
            pfVar12[1] = fVar18 * fVar19 + fVar21;
            pfVar12 = pfVar12 + 2;
          }
          fVar21 = *(float *)(iVar5 + 0x10);
          pfVar14[3] = *(float *)(iVar5 + 0xc) * fVar27 + *(float *)(iVar5 + 4) + 0.0;
          pfVar14[4] = *(float *)(iVar5 + 8) + fVar21 * fVar27;
          pfVar14[5] = fVar25;
          if (((u32)param_2[0x19] & 1) == 0) {
            puVar13[4] = 0xff;
            puVar13[5] = 0xff;
            puVar13[6] = 0xff;
            puVar13[7] = 0xff;
          }
          else {
            fVar22 = param_2[0x14];
            fVar21 = param_2[0x15];
            fVar20 = param_2[0x13];
            fVar24 = *(float *)(iVar5 + 0x14) * fVar16;
            fVar23 = param_2[0xd];
            fVar18 = param_2[0xe];
            fVar19 = param_2[0xf];
            puVar13[4] = (char)(int)(param_2[0x12] * fVar24 + param_2[0xc]);
            puVar13[5] = (char)(int)(fVar20 * fVar24 + fVar23);
            puVar13[6] = (char)(int)(fVar22 * fVar24 + fVar18);
            puVar13[7] = (char)(int)(fVar21 * fVar24 + fVar19);
          }
          puVar13 = puVar13 + 8;
          if (((u32)param_2[0x19] & 2) != 0) {
            fVar18 = param_2[0x17];
            fVar21 = param_2[0x11];
            fVar19 = *(float *)(iVar5 + 0x14) * fVar16;
            *pfVar12 = param_2[0x16] * fVar19 + param_2[0x10];
            pfVar12[1] = fVar18 * fVar19 + fVar21;
            pfVar12 = pfVar12 + 2;
          }
          uVar9 = (u32)((int)uVar9 + 1);
          pfVar14 = pfVar14 + 6;
          iVar5 = iVar5 + 0x18;
        } while (uVar9 < CONCAT44(iStack_4c,iStack_50));
      }
      uVar11 = 0;
      if (iStack_50 != 1) {
        do {
          ((code)FUN_00493210)(param_3,iVar4,uVar15 & 0xffff,uVar15 + 1 & 0xffff,uVar15 + 2 & 0xffff);
          ((code)FUN_00493230)(param_3,iVar4,fVar7);
          ((code)FUN_00493210)(param_3,iVar4 + 8,uVar15 + 1 & 0xffff,uVar15 + 3 & 0xffff,uVar15 + 2 & 0xffff
                      );
          ((code)FUN_00493230)(param_3,iVar4 + 8,fVar7);
          uVar11 = uVar11 + 1;
          iVar4 = iVar4 + 0x10;
          uVar15 = uVar15 + 2;
        } while (uVar11 < iStack_50 - 1U);
      }
      piStack_40 = (int *)piStack_40[5];
      uVar15 = uVar6;
    } while (piStack_40 != *(int **)(param_1 + 0x14));
  }
  ((code)FUN_00494cc0)(fVar7);
  *param_4 = *param_4 + iStack_20;
  *param_5 = *param_5 + iStack_30;
  return param_1;
}

// FUN_004AD480 NONMATCHING

u64 FUN_004ad480(u64 param_1,char *param_2)

{
  int iVar1;
  long lVar2;
  char *pcVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = (int *)param_1;
  lVar2 = ((code)FUN_004a9bd0)(*(u32 *)(piVar4[4] + 4));
  if (lVar2 == 0) {
    iVar5 = (*DAT_00960164)(param_2);
    iVar1 = (*DAT_00960178)(iVar5 + 1,0x301a7);
    *piVar4 = iVar1;
    if (*piVar4 == 0) {
      param_1 = 0;
    }
    else {
      (*DAT_0096013c)(*piVar4,param_2);
      piVar4[2] = iVar5;
    }
  }
  else {
    iVar5 = 0;
    for (pcVar3 = param_2; (*pcVar3 != '\0' || (pcVar3[1] != '\0')); pcVar3 = pcVar3 + 2) {
      iVar5 = iVar5 + 2;
    }
    iVar1 = (*DAT_00960178)(iVar5 + 2,0x301a7);
    *piVar4 = iVar1;
    if (*piVar4 == 0) {
      param_1 = 0;
    }
    else {
      ((code)FUN_00521250)(*piVar4,param_2,iVar5 + 2);
      piVar4[2] = iVar5;
    }
  }
  return param_1;
}

// FUN_004AD5B0 NONMATCHING

u64 FUN_004ad5b0(u64 param_1,long param_2,u64 param_3)

{
  u32 uVar1;
  long lVar2;
  int iVar3;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar3 = (int)param_1;
  *(u32 *)(iVar3 + 0xbc) = 0x3f800000;
  *(u32 *)(iVar3 + 8) = *(u32 *)(iVar3 + 8) & 0xfffffffe;
  uVar1 = ((code)FUN_004a5470)();
  *(u32 *)(iVar3 + 0xb4) = uVar1;
  if (*(int *)(iVar3 + 0xb4) == 0) {
    param_1 = 0;
  }
  else {
    lVar2 = ((code)FUN_004ad700)(param_1,param_3);
    if (lVar2 == 0) {
      uStack_8 = 400;
      uStack_4 = ((code)FUN_004c1d10)(0);
      ((code)FUN_004c1c50)(&uStack_8);
      *(u32 *)(iVar3 + 8) = *(u32 *)(iVar3 + 8) | 0x1000000;
    }
    if (param_2 == 0) {
      *(u32 *)(iVar3 + 0xb0) = 0;
      *(u32 *)(iVar3 + 0xb8) = 0;
    }
    else {
      lVar2 = ((code)FUN_004ad480)(iVar3 + 0xb0,param_2);
      if (lVar2 == 0) {
        ((code)FUN_004a5540)(*(u32 *)(iVar3 + 0xb4));
        param_1 = 0;
      }
    }
  }
  return param_1;
}

// FUN_004AD6A0 NONMATCHING

u64 FUN_004ad6a0(int param_1)

{
  u64 uVar1;
  
  uVar1 = 1;
  if (*(int *)(param_1 + 0xb0) != 0) {
    (*DAT_0096017c)();
  }
  if (*(int *)(param_1 + 0xb4) != 0) {
    uVar1 = ((code)FUN_004a5540)();
  }
  return uVar1;
}

// FUN_004AD700 NONMATCHING

u64 FUN_004ad700(u64 param_1,u64 param_2)

{
  long lVar1;
  u64 uVar2;
  
  lVar1 = ((code)FUN_004a9a80)(param_2);
  uVar2 = param_1;
  if (lVar1 == 0) {
    uVar2 = 0;
  }
  *(int *)((int)param_1 + 0xc0) = (int)lVar1;
  return uVar2;
}

// FUN_004AD750 NONMATCHING

u64 FUN_004ad750(u64 param_1)

{
  u32 uVar1;
  u8 *puVar2;
  u8 *puVar3;
  u32 *puVar4;
  u8 *puVar5;
  int iVar6;
  int iVar7;
  u32 *puVar8;
  Vec128 auStack_70;
  Vec128 auStack_60;
  Vec128 auStack_50;
  Vec128 auStack_40;
  Vec128 auStack_30;
  u8 auStack_20 [24];
  u8 auStack_8 [8];
  
  iVar6 = (int)param_1;
  if ((*(u32 *)(iVar6 + 8) & 0x1000004) == 4) {
    puVar3 = (u8 *)0x8;
    puVar5 = auStack_8;
    puVar2 = puVar5;
    while (puVar2 != (u8 *)0x0) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
      puVar3 = puVar3 + -1;
      puVar2 = puVar3;
    }
    if ((*(u32 *)(iVar6 + 8) & 2) == 2) {
      ((code)FUN_004aab40)(iVar6 + 0x10);
      puVar4 = (u32 *)((code)FUN_004ab0c0)();
      puVar8 = (u32 *)(iVar6 + 0x50);
      iVar7 = 8;
      do {
        iVar7 = iVar7 + -1;
        uVar1 = puVar4[1];
        *puVar8 = *puVar4;
        puVar4 = puVar4 + 2;
        puVar8[1] = uVar1;
        puVar8 = puVar8 + 2;
      } while (0 < iVar7);
      *(u32 *)(iVar6 + 8) = *(u32 *)(iVar6 + 8) & 0xfffffffd;
    }
    else {
      ((code)FUN_004aac70)(iVar6 + 0x50);
    }
    ((code)FUN_00521250)(auStack_20,iVar6 + 0x90,0x10);
    ((code)FUN_00521250)(auStack_30,iVar6 + 0xa0,0x10);
    iVar7 = *(int *)(iVar6 + 0xb4);
    ((code)FUN_00521250)(auStack_70,iVar7 + 0x30,0x10);
    ((code)FUN_00521250)(auStack_60,iVar7 + 0x48,0x10);
    ((code)FUN_00521250)(auStack_50,iVar7 + 0x18,0x10);
    ((code)FUN_00521250)(auStack_40,iVar7,0x10);
    ((code)FUN_004a55b0)(iVar7,auStack_70,auStack_60,auStack_50,auStack_40,auStack_20,auStack_30);
    ((code)FUN_004a9a70)(*(u32 *)(iVar6 + 0xbc),*(u32 *)(*(int *)(iVar6 + 0xc0) + 4),
                 *(u32 *)(iVar6 + 0xb0),auStack_8,iVar7);
    ((code)FUN_004aad50)();
    ((code)FUN_00521250)(iVar7 + 0x30,auStack_70,0x10);
    ((code)FUN_00521250)(iVar7 + 0x48,auStack_60,0x10);
    ((code)FUN_00521250)(iVar7 + 0x18,auStack_50,0x10);
    ((code)FUN_00521250)(iVar7,auStack_40,0x10);
  }
  return param_1;
}

// FUN_004AD940 NONMATCHING

u64 FUN_004ad940(u64 param_1,u64 param_2)

{
  u8 bVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  long lVar6;
  u32 uStack_14;
  int iStack_10;
  int iStack_c;
  u8 auStack_8 [4];
  u8 auStack_4 [4];
  
  lVar6 = 0;
  lVar3 = ((code)FUN_004c5250)(param_2,&iStack_c,4);
  if ((lVar3 == 4) && (lVar3 = ((code)FUN_004c5250)(param_2,&uStack_14), lVar3 == 4)) {
    lVar3 = (*DAT_00960178)(iStack_c + 3,0x101a7);
    if ((lVar3 != 0) &&
       ((iVar5 = iStack_c + 1, iVar2 = ((code)FUN_004c5250)(param_2,lVar3,iVar5), iVar5 == iVar2 &&
        (lVar4 = ((code)FUN_004c5250)(param_2,&iStack_10,4), lVar4 == 4)))) {
      *(u8 *)(iStack_c + (int)lVar3 + 1) = 0;
      *(u8 *)(iStack_c + (int)lVar3 + 2) = 0;
      bVar1 = 0;
      if (iStack_10 == 0) {
        bVar1 = 1;
      }
      else {
        lVar6 = (*DAT_00960178)(iStack_10 + 1,0x101a7);
        if ((lVar6 != 0) &&
           (iVar2 = ((code)FUN_004c5250)(param_2,lVar6,iStack_10 + 1), iStack_10 + 1 == iVar2)) {
          bVar1 = 1;
        }
      }
      if (((bVar1) && (lVar4 = ((code)FUN_004ad5b0)(param_1,lVar3,lVar6), lVar4 != 0)) &&
         (lVar4 = ((code)FUN_004c1600)(param_2,0x1a2,auStack_4,auStack_8), lVar4 != 0)) {
        lVar4 = ((code)FUN_004a6530)(*(u32 *)((int)param_1 + 0xb4),param_2);
        if (lVar4 != 0) {
          *(u32 *)((int)param_1 + 0xbc) = uStack_14;
          (*DAT_0096017c)(lVar6);
          (*DAT_0096017c)(lVar3);
          return param_1;
        }
      }
      (*DAT_0096017c)(lVar6);
    }
    (*DAT_0096017c)(lVar3);
  }
  return 0;
}

#pragma schedule on
// FUN_004ADB50

void FUN_004adb50(void)
{
  FUN_004c3c30_typed(DAT_0095ed8c_abs[0]);
  DAT_0095ed8c_abs[0] = 0;
  return;
}

// FUN_004ADB80 NONMATCHING

u32 FUN_004adb80(void)
{
  u32 uVar1;
  
  uVar1 = thunk_FUN_004c3970_u32(0x110,DAT_007cdcd0,0x10,DAT_007cdcd4,
                                 (u32)((u8 *)DAT_00960070_abs - 0x6b0),0x401a3);
  DAT_0095ed8c_abs[0] = uVar1;
  return 1;
}

// FUN_004ADBD0 NONMATCHING

u64 FUN_004adbd0(int *param_1)

{
  int iVar1;
  u64 uVar2;
  
  iVar1 = *param_1;
  if (iVar1 == 4) {
    uVar2 = ((code)FUN_004ad6a0)();
  }
  else if (iVar1 == 3) {
    uVar2 = ((code)FUN_004ae1e0)();
  }
  else if (iVar1 == 2) {
    uVar2 = ((code)FUN_004af940)();
  }
  else if (iVar1 == 1) {
    uVar2 = ((code)FUN_004ae4e0)();
  }
  else if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

#pragma tailcall on
 
// FUN_004ADC70

void FUN_004adc70(u64 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x004adc84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)DAT_0096018c_abs)(DAT_0095ed8c_abs[0],param_1);
  return;
}
#pragma tailcall off

#pragma optimization_level 3
// FUN_004ADC90

void FUN_004adc90(u64 param_1,u64 param_2)

{
  FUN_00521250_copy(param_1,param_2,0x110);
  return;
}
#pragma optimization_level 2

// FUN_004ADCA0 NONMATCHING

void FUN_004adca0(void)

{
                    /* WARNING: Could not recover jumptable at 0x004adcb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00960188)(DAT_0095ed8c,0x301a3);
  return;
}

// FUN_004ADCC0 NONMATCHING

u64 FUN_004adcc0(u64 param_1,u32 param_2)

{
  u32 *puVar1;
  
  puVar1 = (u32 *)param_1;
  *puVar1 = param_2;
  puVar1[1] = 0x29a;
  puVar1[0xe] = 0x3f800000;
  puVar1[9] = 0x3f800000;
  puVar1[4] = 0x3f800000;
  puVar1[8] = 0;
  puVar1[6] = 0;
  puVar1[5] = 0;
  puVar1[0xd] = 0;
  puVar1[0xc] = 0;
  puVar1[10] = 0;
  puVar1[0x12] = 0;
  puVar1[0x11] = 0;
  puVar1[0x10] = 0;
  puVar1[7] = puVar1[7] | 0x20003;
  puVar1[0x1e] = 0x3f800000;
  puVar1[0x19] = 0x3f800000;
  puVar1[0x14] = 0x3f800000;
  puVar1[0x18] = 0;
  puVar1[0x16] = 0;
  puVar1[0x15] = 0;
  puVar1[0x1d] = 0;
  puVar1[0x1c] = 0;
  puVar1[0x1a] = 0;
  puVar1[0x22] = 0;
  puVar1[0x21] = 0;
  puVar1[0x20] = 0;
  puVar1[0x17] = puVar1[0x17] | 0x20003;
  puVar1[0x24] = 0x3f800000;
  puVar1[0x25] = 0x3f800000;
  puVar1[0x26] = 0x3f800000;
  puVar1[0x27] = 0x3f800000;
  puVar1[0x28] = 0;
  puVar1[0x29] = 0;
  puVar1[0x2a] = 0;
  puVar1[0x2b] = 0;
  puVar1[2] = 6;
  ((code)FUN_00521408)(puVar1 + 0x2c,0,0x60);
  return param_1;
}

// FUN_004ADDB0 NONMATCHING

u64 FUN_004addb0(u64 param_1,u64 param_2)

{
  long lVar1;
  u32 *puVar2;
  u8 auStack_30 [4];
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  lVar1 = ((code)FUN_004c5250)(param_2,auStack_30,0x2c);
  if (lVar1 == 0x2c) {
    lVar1 = ((code)FUN_004c1600)(param_2,0xd,0,0);
    if (lVar1 == 0) {
      param_1 = 0;
    }
    else {
      puVar2 = (u32 *)param_1;
      ((code)FUN_004c19f0)(param_2,puVar2 + 4);
      *puVar2 = uStack_2c;
      puVar2[1] = uStack_28;
      puVar2[0x24] = uStack_24;
      puVar2[0x25] = uStack_20;
      puVar2[0x26] = uStack_1c;
      puVar2[0x27] = uStack_18;
      puVar2[0x28] = uStack_14;
      puVar2[0x29] = uStack_10;
      puVar2[0x2a] = uStack_c;
      puVar2[0x2b] = uStack_8;
      puVar2[2] = 6;
    }
  }
  else {
    param_1 = 0;
  }
  return param_1;
}

// FUN_004ADE90 NONMATCHING

u64 FUN_004ade90(u64 param_1)

{
  int iVar1;
  
  iVar1 = *(int *)param_1;
  if (iVar1 == 4) {
    ((code)FUN_004ad940)();
  }
  else if (iVar1 == 3) {
    ((code)FUN_004ae270)();
  }
  else if (iVar1 == 2) {
    ((code)FUN_004affe0)();
  }
  else if (iVar1 == 1) {
    ((code)FUN_004aebf0)();
  }
  else {
    param_1 = 0;
  }
  return param_1;
}

// FUN_004ADF30 NONMATCHING

u64 FUN_004adf30(u64 param_1)

{
  int iVar1;
  
  iVar1 = *(int *)param_1;
  if (iVar1 == 4) {
    ((code)FUN_004ad750)();
  }
  else if (iVar1 == 3) {
    ((code)FUN_004ae2f0)();
  }
  else if (iVar1 == 2) {
    ((code)FUN_004af9d0)();
  }
  else if (iVar1 == 1) {
    ((code)FUN_004ae960)();
  }
  else if (iVar1 != 0) {
    param_1 = 0;
  }
  return param_1;
}

// FUN_004ADFD0 NONMATCHING

u64 FUN_004adfd0(u64 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if (param_2 == 1) {
    *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) | 4;
  }
  else {
    *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) & 0xfffffffb;
  }
  return param_1;
}

// FUN_004AE010
#pragma optimization_level 3

u32 FUN_004ae010(int param_1)
{
  return *(u32 *)(param_1 + 8) & 4;
}
#pragma optimization_level 2

// FUN_004AE020 NONMATCHING

u64 FUN_004ae020(u64 param_1,u32 *param_2)

{
  u32 uVar1;
  int iVar2;
  int iVar3;
  u32 *puVar4;
  
  iVar2 = (int)param_1;
  puVar4 = (u32 *)(iVar2 + 0x10);
  iVar3 = 8;
  do {
    iVar3 = iVar3 + -1;
    uVar1 = param_2[1];
    *puVar4 = *param_2;
    param_2 = param_2 + 2;
    puVar4[1] = uVar1;
    puVar4 = puVar4 + 2;
  } while (0 < iVar3);
  *(u32 *)(iVar2 + 8) = *(u32 *)(iVar2 + 8) | 2;
  return param_1;
}

// FUN_004AE060
#pragma optimization_level 3

void FUN_004ae060(int param_1)

{
  *(u32 *)(param_1 + 8) = *(u32 *)(param_1 + 8) | 2;
  return;
}
#pragma optimization_level 2

// FUN_004AE070 NONMATCHING

u64 FUN_004ae070(u32 param_1,u32 param_2,u64 param_3)

{
  int iVar1;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  uStack_8 = 0x3f800000;
  iVar1 = (int)param_3;
  uStack_10 = param_1;
  uStack_c = param_2;
  ((code)FUN_004c33d0)(iVar1 + 0x10,&uStack_10,1);
  *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) | 2;
  return param_3;
}

// FUN_004AE0C0 NONMATCHING

u64 FUN_004ae0c0(u32 param_1,u32 param_2,u64 param_3)

{
  int iVar1;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  uStack_8 = 0;
  iVar1 = (int)param_3;
  uStack_10 = param_1;
  uStack_c = param_2;
  ((code)FUN_004c35d0)(iVar1 + 0x10,&uStack_10,1);
  *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) | 2;
  return param_3;
}

#pragma schedule on
// FUN_004AE110 NONMATCHING

u32 FUN_004ae110(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  FUN_00521250_u32(param_1 + 0x90,(u32)param_2,0x10);
  *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) | 8;
  return (u32)param_1;
}
#pragma schedule off

// FUN_004AE150 NONMATCHING

u64 FUN_004ae150(u64 param_1,u64 param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  ((code)FUN_00521250)(iVar1 + 0xa0,param_2,0x10);
  *(float *)(iVar1 + 0xa0) = *(float *)(iVar1 + 0xa0) * 255.0;
  *(float *)(iVar1 + 0xa4) = *(float *)(iVar1 + 0xa4) * 255.0;
  *(float *)(iVar1 + 0xa8) = *(float *)(iVar1 + 0xa8) * 255.0;
  *(float *)(iVar1 + 0xac) = *(float *)(iVar1 + 0xac) * 255.0;
  *(u32 *)(iVar1 + 8) = *(u32 *)(iVar1 + 8) | 8;
  return param_1;
}

// FUN_004AE1D0

#pragma schedule on
u32 FUN_004ae1d0(u32 param_1,u32 param_2)

{
  *(u32 *)((int)param_1 + 4) = param_2;
  return param_1;
}
#pragma schedule off

// FUN_004AE1E0 NONMATCHING

u8 FUN_004ae1e0(int param_1)

{
  u8 bVar1;
  long lVar2;
  u64 uVar3;
  
  bVar1 = *(int *)(param_1 + 0xb0) != 0;
  if ((((bVar1) && (lVar2 = ((code)FUN_004ab0e0)(), lVar2 != 0)) &&
      (lVar2 = ((code)FUN_004ab0e0)(lVar2), lVar2 != 0)) && (lVar2 = ((code)FUN_004ab0e0)(lVar2), lVar2 != 0)) {
    uVar3 = ((code)FUN_004ab0e0)(lVar2);
    ((code)FUN_004ac390)(uVar3);
  }
  return bVar1;
}

// FUN_004AE1F0 NONMATCHING

u64 FUN_004ae1f0(int param_1,u32 *param_2)

{
  u64 uVar1;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_8;
  u32 uStack_4;
  
  if ((*(u32 *)(param_1 + 8) & 4) == 4) {
    uStack_18 = *param_2;
    uStack_14 = param_2[1];
    uStack_10 = 0;
    ((code)FUN_004c6be0)(&uStack_28,&uStack_18,param_1 + 0xd0);
    uStack_8 = uStack_28;
    uStack_4 = uStack_24;
    uVar1 = thunk_FUN_004accc0((float *)&uStack_8,(int *)(u32)(*(u32 *)(param_1 + 0xb0)));
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

// FUN_004AE270 NONMATCHING

u64 FUN_004ae270(u64 param_1,u64 param_2)

{
  u32 uVar1;
  long lVar2;
  int iVar3;
  u8 auStack_8 [4];
  u8 auStack_4 [4];
  
  uVar1 = ((code)FUN_004ac570)();
  iVar3 = (int)param_1;
  *(u32 *)(iVar3 + 0xb0) = uVar1;
  *(u32 *)(iVar3 + 8) = *(u32 *)(iVar3 + 8) & 0xfffffffe;
  lVar2 = ((code)FUN_004c1600)(param_2,0x1a1,auStack_4,auStack_8);
  if (lVar2 == 0) {
    param_1 = 0;
  }
  else {
    lVar2 = ((code)FUN_004acb10)(*(u32 *)(iVar3 + 0xb0),param_2);
    if (lVar2 == 0) {
      param_1 = 0;
    }
  }
  return param_1;
}

// FUN_004AE2F0 NONMATCHING

u64 FUN_004ae2f0(u64 param_1)

{
  u32 uVar1;
  u32 *puVar2;
  int iVar3;
  int iVar4;
  u32 *puVar5;
  
  iVar3 = (int)param_1;
  if ((*(u32 *)(iVar3 + 8) & 4) == 4) {
    if ((*(u32 *)(iVar3 + 8) & 2) == 2) {
      ((code)FUN_004aab40)(iVar3 + 0x10);
      puVar2 = (u32 *)((code)FUN_004ab0c0)();
      puVar5 = (u32 *)(iVar3 + 0x50);
      iVar4 = 8;
      do {
        iVar4 = iVar4 + -1;
        uVar1 = puVar2[1];
        *puVar5 = *puVar2;
        puVar2 = puVar2 + 2;
        puVar5[1] = uVar1;
        puVar5 = puVar5 + 2;
      } while (0 < iVar4);
      ((code)FUN_004c32a0)(iVar3 + 0xd0,iVar3 + 0x50);
      *(u32 *)(iVar3 + 8) = *(u32 *)(iVar3 + 8) & 0xfffffffd;
    }
    else {
      ((code)FUN_004aac70)(iVar3 + 0x50);
    }
    ((code)FUN_004aad50)();
  }
  return param_1;
}

// FUN_004AE3B0 NONMATCHING

u64 FUN_004ae3b0(u64 param_1,u64 param_2)

{
  int iVar1;
  long lVar2;
  u32 uVar3;
  int *piVar4;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_4;
  
  lVar2 = ((code)FUN_004c1910)(param_2,&uStack_4,4);
  if (lVar2 == 0) {
    param_1 = 0;
  }
  else {
    piVar4 = (int *)param_1;
    piVar4[1] = uStack_4;
    if (uStack_4 == 0) {
      *piVar4 = 0;
    }
    else {
      iVar1 = (*DAT_00960178)(uStack_4 << 2,0x30190);
      *piVar4 = iVar1;
      if (*piVar4 == 0) {
        uStack_10 = 400;
        uStack_c = ((code)FUN_004c1d10)(0xffffffff80000013,uStack_4 << 2);
        ((code)FUN_004c1c50)(&uStack_10);
        param_1 = 0;
      }
      else {
        uVar3 = 0;
        if (uStack_4 != 0) {
          iVar1 = 0;
          do {
            lVar2 = ((code)FUN_004af760)(param_2);
            *(int *)(*piVar4 + iVar1) = (int)lVar2;
            if (lVar2 == 0) {
              return 0;
            }
            uVar3 = uVar3 + 1;
            iVar1 = iVar1 + 4;
          } while (uVar3 < uStack_4);
        }
      }
    }
  }
  return param_1;
}

// FUN_004AE4E0 NONMATCHING

u8 FUN_004ae4e0(int param_1)

{
  int iVar1;
  u8 bVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  u32 uVar6;
  
  uVar6 = 1;
  if (*(int *)(param_1 + 0xb8) != 0) {
    uVar6 = ((code)FUN_004c20b0)();
  }
  iVar3 = ((code)FUN_004c2090)(*(u32 *)(param_1 + 0xb0));
  iVar1 = *(int *)(param_1 + 0xb4);
  for (iVar4 = ((code)FUN_004c2090)(*(u32 *)(param_1 + 0xb0)); iVar4 != iVar3 + iVar1 * 0x110;
      iVar4 = iVar4 + 0x110) {
    bVar2 = uVar6 != 0;
    uVar6 = 0;
    if (bVar2) {
      lVar5 = ((code)FUN_004adbd0)(iVar4);
      uVar6 = (u32)(lVar5 != 0);
    }
  }
  bVar2 = 0;
  if (uVar6 != 0) {
    lVar5 = ((code)FUN_004c20b0)(*(u32 *)(param_1 + 0xb0));
    bVar2 = lVar5 != 0;
  }
  return bVar2;
}

// FUN_004AE5A0 NONMATCHING

u8 FUN_004ae5a0(long param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  u8 bVar5;
  u32 uVar6;
  int iVar7;
  
  bVar5 = 0;
  if (param_1 != 0) {
    iVar7 = (int)param_1;
    uVar6 = 1;
    if (*(int *)(iVar7 + 0xb8) != 0) {
      uVar6 = ((code)FUN_004c20b0)();
    }
    iVar2 = ((code)FUN_004c2090)(*(u32 *)(iVar7 + 0xb0));
    iVar1 = *(int *)(iVar7 + 0xb4);
    for (iVar3 = ((code)FUN_004c2090)(*(u32 *)(iVar7 + 0xb0)); iVar3 != iVar2 + iVar1 * 0x110;
        iVar3 = iVar3 + 0x110) {
      bVar5 = uVar6 != 0;
      uVar6 = 0;
      if (bVar5) {
        lVar4 = ((code)FUN_004adbd0)(iVar3);
        uVar6 = (u32)(lVar4 != 0);
      }
    }
    bVar5 = 0;
    if (uVar6 != 0) {
      lVar4 = ((code)FUN_004c20b0)(*(u32 *)(iVar7 + 0xb0));
      bVar5 = lVar4 != 0;
    }
    (*DAT_0096018c)(DAT_0095ed8c,param_1);
  }
  return bVar5;
}

// FUN_004AE690 NONMATCHING

u64 FUN_004ae690(u64 param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  piVar2 = (int *)((code)FUN_004c2090)(*(u32 *)((int)param_1 + 0xb8));
  piVar3 = piVar2 + *(int *)((int)param_1 + 0xb4) * 2;
  piVar4 = piVar2;
  if (piVar2 != piVar3) {
    for (; piVar4 != piVar3; piVar4 = piVar4 + 2) {
      piVar4[1] = *(int *)(*piVar4 + 4);
    }
    for (; piVar4 = piVar2, piVar2 < piVar3 + -2; piVar2 = piVar2 + 2) {
      while (piVar1 = piVar4, piVar4 = piVar1 + 2, piVar4 < piVar3) {
        if (piVar1[3] < piVar2[1]) {
          iVar6 = *piVar2;
          iVar7 = piVar2[1];
          iVar5 = piVar1[3];
          *piVar2 = *piVar4;
          piVar2[1] = iVar5;
          *piVar4 = iVar6;
          piVar1[3] = iVar7;
        }
      }
    }
  }
  return param_1;
}

// FUN_004AE790 NONMATCHING

u64 FUN_004ae790(u64 param_1)

{
  int *piVar1;
  u32 uVar2;
  int iVar3;
  u64 uVar4;
  u64 uVar5;
  int iVar6;
  int *piVar7;
  
  iVar6 = (int)param_1;
  if ((*(u32 *)(iVar6 + 8) & 1) == 1) {
    uVar4 = ((code)FUN_004c1d50)(0x110,0x301a3);
    piVar1 = (int *)((code)FUN_004c2090)(*(u32 *)(iVar6 + 0xb0));
    piVar7 = piVar1 + *(int *)(iVar6 + 0xb4);
    for (; piVar1 != piVar7; piVar1 = piVar1 + 1) {
      uVar5 = ((code)FUN_004c1e70)(uVar4,0x301a3);
      if (*piVar1 != 0) {
        ((code)FUN_004adc90)(uVar5);
        ((code)FUN_004adc70)(*piVar1);
      }
    }
    ((code)FUN_004c20b0)(*(u32 *)(iVar6 + 0xb0));
    *(int *)(iVar6 + 0xb0) = (int)uVar4;
    *(u32 *)(iVar6 + 8) = *(u32 *)(iVar6 + 8) & 0xfffffffe;
    uVar2 = ((code)FUN_004c1d50)(8,0x30190);
    *(u32 *)(iVar6 + 0xb8) = uVar2;
    if (*(int *)(iVar6 + 0xb4) != 0) {
      ((code)FUN_004c1f70)(*(u32 *)(iVar6 + 0xb8),*(int *)(iVar6 + 0xb4),0x30190);
      piVar1 = (int *)((code)FUN_004c2090)(*(u32 *)(iVar6 + 0xb8));
      iVar3 = ((code)FUN_004c2090)(*(u32 *)(iVar6 + 0xb0));
      piVar7 = piVar1 + *(int *)(iVar6 + 0xb4) * 2;
      for (; piVar1 != piVar7; piVar1 = piVar1 + 2) {
        *piVar1 = iVar3;
        iVar3 = iVar3 + 0x110;
      }
      ((code)FUN_004ae690)(param_1);
      *(u32 *)(iVar6 + 0xbc) = 0;
    }
  }
  return param_1;
}

// FUN_004AE8F0
#pragma optimization_level 3

u32 FUN_004ae8f0(int param_1)
{
  return *(u32 *)(param_1 + 0xb4);
}
#pragma optimization_level 2

#pragma optimization_level 3
#pragma schedule on
// FUN_004AE900 NONMATCHING

u32 FUN_004ae900(int param_1)

{
  u32 *puVar1;
  u32 uVar2;
  
  if ((*(u32 *)(param_1 + 8) & 1) == 1) {
    puVar1 = FUN_004c21b0_typed(*(u32 *)(param_1 + 0xb0));
    uVar2 = *puVar1;
  }
  else {
    uVar2 = (u32)FUN_004c21b0_typed(*(u32 *)(param_1 + 0xb0));
  }
  return uVar2;
}
#pragma optimization_level 2
#pragma schedule off

// FUN_004AE940 NONMATCHING

void FUN_004ae940(u64 param_1)

{
  ((code)FUN_004ae960)(param_1,0x7bcb70,0x7bcb80);
  return;
}

// FUN_004AE960 NONMATCHING

u64 FUN_004ae960(u64 param_1,float *param_2,float *param_3)

{
  u32 uVar1;
  u8 bVar2;
  int *piVar3;
  u32 *puVar4;
  int iVar5;
  int iVar6;
  u32 *puVar7;
  int *piVar8;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  bVar2 = 0;
  iVar5 = (int)param_1;
  if ((*(u32 *)(iVar5 + 8) & 4) == 4) {
    if ((*(u32 *)(iVar5 + 8) & 2) == 2) {
      ((code)FUN_004aab40)(iVar5 + 0x10);
      puVar4 = (u32 *)((code)FUN_004ab0c0)();
      puVar7 = (u32 *)(iVar5 + 0x50);
      iVar6 = 8;
      do {
        iVar6 = iVar6 + -1;
        uVar1 = puVar4[1];
        *puVar7 = *puVar4;
        puVar4 = puVar4 + 2;
        puVar7[1] = uVar1;
        puVar7 = puVar7 + 2;
      } while (0 < iVar6);
      bVar2 = 1;
      *(u32 *)(iVar5 + 8) = *(u32 *)(iVar5 + 8) & 0xfffffffd;
    }
    else {
      ((code)FUN_004aac70)(iVar5 + 0x50);
    }
    fStack_10 = *(float *)(iVar5 + 0x90) * *param_2;
    fStack_c = *(float *)(iVar5 + 0x94) * param_2[1];
    fStack_8 = *(float *)(iVar5 + 0x98) * param_2[2];
    fStack_4 = *(float *)(iVar5 + 0x9c) * param_2[3];
    fStack_20 = (*(float *)(iVar5 + 0xa0) / 255.0) * *param_2 + *param_3 + 0.0;
    fStack_1c = (*(float *)(iVar5 + 0xa4) / 255.0) * param_2[1] + param_3[1] + 0.0;
    fStack_18 = (*(float *)(iVar5 + 0xa8) / 255.0) * param_2[2] + param_3[2] + 0.0;
    fStack_14 = (*(float *)(iVar5 + 0xac) / 255.0) * param_2[3] + param_3[3] + 0.0;
    piVar3 = (int *)((code)FUN_004c2090)(*(u32 *)(iVar5 + 0xb8));
    piVar8 = piVar3 + *(int *)(iVar5 + 0xb4) * 2;
    if (*(int *)(iVar5 + 0xbc) != 0) {
      ((code)FUN_004ae690)(param_1);
      *(u32 *)(iVar5 + 0xbc) = 0;
    }
    for (; piVar3 != piVar8; piVar3 = piVar3 + 2) {
      if (bVar2) {
        *(u32 *)(*piVar3 + 8) = *(u32 *)(*piVar3 + 8) | 2;
      }
      ((code)FUN_004adf30)(*piVar3,&fStack_10,&fStack_20);
    }
    ((code)FUN_004aad50)();
  }
  return param_1;
}

// FUN_004AEB60 NONMATCHING

u64 FUN_004aeb60(u64 param_1,code *param_2,u64 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = ((code)FUN_004c2090)(*(u32 *)((int)param_1 + 0xb0));
  iVar2 = iVar1 + *(int *)((int)param_1 + 0xb4) * 0x110;
  for (; iVar1 != iVar2; iVar1 = iVar1 + 0x110) {
    (*param_2)(iVar1,param_1,param_3);
  }
  return param_1;
}

// FUN_004AEBF0 NONMATCHING

u64 FUN_004aebf0(u64 param_1,u64 param_2,long param_3)

{
  u32 uVar1;
  int iVar2;
  int *piVar3;
  long lVar4;
  u64 uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  u32 uVar9;
  int iStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  int iStack_4;
  
  iStack_4 = 0;
  lVar4 = ((code)FUN_004c5250)(param_2,&iStack_4,4);
  iVar2 = iStack_4;
  if (lVar4 == 4) {
    iVar6 = (int)param_1;
    *(int *)(iVar6 + 0xb4) = iStack_4;
    uVar1 = ((code)FUN_004c1d50)(4,0x30190);
    *(u32 *)(iVar6 + 0xb0) = uVar1;
    if (iVar2 != 0) {
      ((code)FUN_004c1f70)(*(u32 *)(iVar6 + 0xb0),iVar2,0x30190);
      uVar5 = ((code)FUN_004c2090)(*(u32 *)(iVar6 + 0xb0));
      ((code)FUN_00521408)(uVar5,0,iVar2 << 2);
    }
    *(u32 *)(iVar6 + 0xb8) = 0;
    *(u32 *)(iVar6 + 0xbc) = 0;
    *(u32 *)(iVar6 + 8) = *(u32 *)(iVar6 + 8) | 1;
    ((code)FUN_004ae790)(param_1);
    uVar1 = (u32)param_2;
    if (param_3 == 0) {
      lVar4 = ((code)FUN_004ae3b0)(&iStack_18,param_2);
      if (lVar4 == 0) {
        return 0;
      }
      iVar2 = ((code)FUN_004c2090)(*(u32 *)(iVar6 + 0xb0));
      iVar8 = iVar2 + *(int *)(iVar6 + 0xb4) * 0x110;
      if (iVar2 != iVar8) {
        for (; iVar2 != iVar8; iVar2 = iVar2 + 0x110) {
          lVar4 = ((code)FUN_004addb0)(iVar2,uVar1);
          if (lVar4 != 0) {
            ((code)FUN_004ade90)(iVar2,uVar1,&iStack_18);
          }
        }
      }
      if (uStack_14 != 0) {
        uVar9 = 0;
        if (uStack_14 != 0) {
          iVar2 = 0;
          do {
            ((code)FUN_004af130)(*(u32 *)(iStack_18 + iVar2));
            uVar9 = uVar9 + 1;
            iVar2 = iVar2 + 4;
          } while (uVar9 < uStack_14);
        }
        (*DAT_0096017c)(iStack_18);
      }
    }
    else {
      uStack_c = (u32)param_3;
      uStack_10 = uVar1;
      iVar2 = ((code)FUN_004c2090)(*(u32 *)(iVar6 + 0xb0));
      iVar8 = iVar2 + *(int *)(iVar6 + 0xb4) * 0x110;
      if (iVar2 != iVar8) {
        for (; iVar2 != iVar8; iVar2 = iVar2 + 0x110) {
          lVar4 = ((code)FUN_004addb0)(iVar2,uStack_10);
          if (lVar4 != 0) {
            ((code)FUN_004ade90)(iVar2,uStack_10,uStack_c);
          }
        }
      }
    }
    piVar3 = (int *)((code)FUN_004c2090)(*(u32 *)(iVar6 + 0xb8));
    piVar7 = piVar3 + *(int *)(iVar6 + 0xb4) * 2;
    iVar2 = ((code)FUN_004c2090)(*(u32 *)(iVar6 + 0xb0));
    for (; piVar3 != piVar7; piVar3 = piVar3 + 2) {
      *piVar3 = iVar2;
      iVar2 = iVar2 + 0x110;
    }
    ((code)FUN_004ae690)(param_1);
    *(u32 *)(iVar6 + 8) = *(u32 *)(iVar6 + 8) & 0xfffffffe;
  }
  else {
    param_1 = 0;
  }
  return param_1;
}

// FUN_004AEEA0 NONMATCHING

long FUN_004aeea0(u64 param_1)

{
  long lVar1;
  long lVar2;
  
  lVar1 = ((code)FUN_004adca0)();
  ((code)FUN_004adcc0)(lVar1,1);
  lVar2 = ((code)FUN_004addb0)(lVar1,param_1);
  if (lVar2 == 0) {
    lVar2 = 0;
  }
  else {
    lVar2 = ((code)FUN_004aebf0)(lVar1,param_1,0);
    if ((lVar2 == 0) && (lVar1 != 0)) {
      ((code)FUN_004ae4e0)(lVar1);
      (*DAT_0096018c)(DAT_0095ed8c,lVar1);
    }
  }
  return lVar2;
}

// FUN_004AEF50
#pragma schedule on
u32 FUN_004aef50(u32 param_1)

{
  *(u32 *)((int)param_1 + 0xbc) = 1;
  return param_1;
}
#pragma schedule off

// FUN_004AEF60 NONMATCHING

u64 FUN_004aef60(u64 param_1)

{
  int *piVar1;
  u32 uVar2;
  u8 bVar3;
  int *piVar4;
  u32 *puVar5;
  int iVar6;
  int iVar7;
  u32 *puVar8;
  int *piVar9;
  
  iVar7 = (int)param_1;
  bVar3 = 0;
  if ((*(u32 *)(iVar7 + 8) & 2) == 2) {
    ((code)FUN_004aab40)(iVar7 + 0x10);
    puVar5 = (u32 *)((code)FUN_004ab0c0)();
    puVar8 = (u32 *)(iVar7 + 0x50);
    iVar6 = 8;
    do {
      iVar6 = iVar6 + -1;
      uVar2 = puVar5[1];
      *puVar8 = *puVar5;
      puVar5 = puVar5 + 2;
      puVar8[1] = uVar2;
      puVar8 = puVar8 + 2;
    } while (0 < iVar6);
    bVar3 = 1;
    *(u32 *)(iVar7 + 8) = *(u32 *)(iVar7 + 8) & 0xfffffffd;
  }
  else {
    ((code)FUN_004aac70)(iVar7 + 0x50);
  }
  piVar4 = (int *)((code)FUN_004c2090)(*(u32 *)(iVar7 + 0xb8));
  piVar9 = piVar4 + *(int *)(iVar7 + 0xb4) * 2;
  for (; piVar4 != piVar9; piVar4 = piVar4 + 2) {
    if (bVar3) {
      *(u32 *)(*piVar4 + 8) = *(u32 *)(*piVar4 + 8) | 2;
    }
    piVar1 = (int *)*piVar4;
    if (*piVar1 == 1) {
      ((code)FUN_004aef60)();
    }
    else {
      if ((piVar1[2] & 2U) == 2) {
        ((code)FUN_004aab40)(piVar1 + 4);
        puVar5 = (u32 *)((code)FUN_004ab0c0)();
        iVar7 = 8;
        puVar8 = (u32 *)(*piVar4 + 0x50);
        do {
          iVar7 = iVar7 + -1;
          uVar2 = puVar5[1];
          *puVar8 = *puVar5;
          puVar5 = puVar5 + 2;
          puVar8[1] = uVar2;
          puVar8 = puVar8 + 2;
        } while (0 < iVar7);
        *(u32 *)(*piVar4 + 8) = *(u32 *)(*piVar4 + 8) & 0xfffffffd;
      }
      else {
        ((code)FUN_004aac70)(piVar1 + 0x14);
      }
      piVar1 = (int *)*piVar4;
      if (*piVar1 == 3) {
        ((code)FUN_004c32a0)(piVar1 + 0x34,piVar1 + 0x14);
      }
    }
    ((code)FUN_004aad50)();
  }
  ((code)FUN_004aad50)();
  return param_1;
}

// FUN_004AF130 NONMATCHING

u32 FUN_004af130(u64 param_1)

{
  int iVar1;
  int iVar2;
  u32 uVar3;
  u32 *puVar4;
  int iVar5;
  
  puVar4 = (u32 *)param_1;
  iVar1 = puVar4[1];
  puVar4[1] = iVar1 + -1;
  if (iVar1 + -1 == 0) {
    iVar1 = ((code)FUN_004c2120)(*puVar4);
    iVar2 = ((code)FUN_004c2090)(*puVar4);
    iVar5 = 0;
    if (0 < iVar1) {
      do {
        if (*(int *)(iVar2 + 4) != 0) {
          ((code)FUN_004ac390)();
          ((code)FUN_004a5540)(*(u32 *)(iVar2 + 8));
        }
        iVar5 = iVar5 + 1;
        iVar2 = iVar2 + 0xc;
      } while (iVar5 < iVar1);
    }
    ((code)FUN_004c20b0)(*puVar4);
    if (puVar4[2] != 0) {
      ((code)FUN_00493b60)();
      puVar4[2] = 0;
    }
    (*DAT_0096017c)(param_1);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}

// FUN_004AF210 NONMATCHING

long FUN_004af210(int *param_1,int *param_2,u32 param_3,u64 param_4)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  long lVar4;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_8;
  u32 uStack_4;
  
  lVar4 = 0;
  if (*param_1 != 0) {
    lVar4 = ((code)FUN_00493710)(param_1[3],param_1[2],param_4);
    uStack_4 = 0;
    uVar3 = 0;
    uStack_8 = 0;
    if (param_3 != 0) {
      do {
        if (*param_2 != 0) {
          uVar2 = *(u32 *)(*param_2 + 0x14);
          if ((param_2[4] & 1U) == 0) {
            ((code)FUN_004ace80)(uVar2,param_2[5],lVar4,&uStack_4,&uStack_8);
          }
          else {
            ((code)FUN_004a6630)(uVar2,param_2[5],lVar4,&uStack_4,&uStack_8);
          }
        }
        uVar3 = uVar3 + 1;
        param_2 = param_2 + 6;
      } while (uVar3 < param_3);
    }
  }
  if (lVar4 != 0) {
    iVar1 = *(int *)((int)lVar4 + 0x5c);
    ((code)FUN_00492e20)(iVar1,&uStack_20);
    *(u32 *)(iVar1 + 4) = uStack_20;
    *(u32 *)(iVar1 + 8) = uStack_1c;
    *(u32 *)(iVar1 + 0xc) = uStack_18;
    *(u32 *)(iVar1 + 0x10) = uStack_14;
    ((code)FUN_004933d0)(lVar4);
  }
  return lVar4;
}

// FUN_004AF340 NONMATCHING

u64 FUN_004af340(u32 *param_1)

{
  u32 *puVar1;
  int *piVar2;
  int iVar3;
  u64 uVar4;
  u64 uVar5;
  int iVar6;
  u32 *puVar7;
  u32 uVar8;
  u32 *puVar9;
  int *piVar10;
  u32 *puVar11;
  u32 uVar12;
  int *piStack_20;
  u32 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  u8 auStack_8 [4];
  u8 auStack_4 [4];
  
  ((code)FUN_00498e40)(auStack_4,auStack_8);
  uVar4 = ((code)FUN_004c2120)(*param_1);
  puVar1 = (u32 *)((code)FUN_004c2090)(*param_1);
  uVar8 = (u32)uVar4;
  puVar11 = puVar1 + uVar8 * 3;
  piVar2 = (int *)(*DAT_00960178)(uVar8 * 0x18,0x30190);
  iStack_14 = 0;
  iStack_10 = 0;
  iStack_18 = 0;
  uStack_1c = uVar8;
  piVar10 = piVar2;
  piStack_20 = piVar2;
  for (; puVar1 != puVar11; puVar1 = puVar1 + 3) {
    puVar7 = (u32 *)puVar1[1];
    *piVar10 = 0;
    piVar10[2] = 0;
    piVar10[1] = 0;
    piVar10[3] = 0;
    piVar10[5] = puVar1[2];
    piVar10[4] = *puVar1;
    if ((*puVar1 & 1) == 0) {
      for (; puVar7 != (u32 *)0x0; puVar7 = (u32 *)puVar7[5]) {
        uVar5 = ((code)FUN_004ac570)();
        puVar9 = (u32 *)uVar5;
        if (puVar7[3] == 0) {
          ((code)FUN_004abd50)(uVar5,puVar7);
          iVar3 = puVar9[1];
          if (iVar3 == -1) {
            iVar3 = ((code)FUN_004c2120)(*puVar9);
          }
          uVar12 = puVar7[4];
        }
        else {
          ((code)FUN_004c20b0)(*puVar9);
          *puVar9 = *puVar7;
          puVar9[1] = puVar7[1];
          puVar9[2] = puVar7[2];
          puVar9[3] = 0;
          iVar3 = puVar7[1];
          if (iVar3 == -1) {
            iVar3 = ((code)FUN_004c2120)(*puVar7);
          }
          uVar12 = puVar7[4];
        }
        iVar6 = iVar3 * 2 + -2;
        puVar9[4] = uVar12;
        piVar10[2] = piVar10[2] + iVar3 * 2;
        piVar10[1] = piVar10[1] + iVar6;
        piVar10[3] = piVar10[3] + iVar6 * 3;
        if (*piVar10 == 0) {
          puVar9[5] = (u32)(puVar9);
        }
        else {
          puVar9[5] = *(u32 *)(*piVar10 + 0x14);
          *(u32 **)(*piVar10 + 0x14) = puVar9;
        }
        *piVar10 = (int)puVar9;
      }
    }
    else {
      for (; puVar7 != (u32 *)0x0; puVar7 = (u32 *)puVar7[5]) {
        if (puVar7[2] != 0) {
          uVar5 = ((code)FUN_004ac570)();
          puVar9 = (u32 *)uVar5;
          if (puVar7[3] == 0) {
            ((code)FUN_004abd50)(uVar5,puVar7);
            iVar3 = puVar9[1];
            if (iVar3 == -1) {
              iVar3 = ((code)FUN_004c2120)(*puVar9);
            }
            uVar12 = puVar7[4];
          }
          else {
            ((code)FUN_004c20b0)(*puVar9);
            *puVar9 = *puVar7;
            puVar9[1] = puVar7[1];
            puVar9[2] = puVar7[2];
            puVar9[3] = 0;
            iVar3 = puVar7[1];
            if (iVar3 == -1) {
              iVar3 = ((code)FUN_004c2120)(*puVar7);
            }
            uVar12 = puVar7[4];
          }
          puVar9[4] = uVar12;
          piVar10[2] = piVar10[2] + iVar3;
          piVar10[1] = piVar10[1] + iVar3 + -3;
          piVar10[3] = piVar10[3] + (iVar3 + -3) * 3;
          if (*piVar10 == 0) {
            puVar9[5] = (u32)(puVar9);
          }
          else {
            puVar9[5] = *(u32 *)(*piVar10 + 0x14);
            *(u32 **)(*piVar10 + 0x14) = puVar9;
          }
          *piVar10 = (int)puVar9;
        }
      }
    }
    iStack_14 = iStack_14 + piVar10[2];
    iStack_18 = iStack_18 + piVar10[1];
    iStack_10 = iStack_10 + piVar10[3];
    piVar10 = piVar10 + 6;
  }
  uVar4 = ((code)FUN_004af210)(&piStack_20,piVar2,uVar4,0x6f);
  if (piStack_20 != (int *)0x0) {
    uVar8 = 0;
    if (uStack_1c != 0) {
      do {
        puVar7 = *(u32 **)(*piVar2 + 0x14);
        do {
          if (puVar7[3] == 0) {
            *puVar7 = 0;
          }
          puVar7 = (u32 *)puVar7[5];
        } while (puVar7 != *(u32 **)(*piVar2 + 0x14));
        *(u32 *)(*piVar2 + 0x14) = 0;
        ((code)FUN_004ac390)();
        uVar8 = uVar8 + 1;
        piVar2 = piVar2 + 6;
      } while (uVar8 < uStack_1c);
    }
    (*DAT_0096017c)(piStack_20);
  }
  param_1[2] = (int)uVar4;
  return uVar4;
}

// FUN_004AF760 NONMATCHING

u64 FUN_004af760(u64 param_1)

{
  u32 *puVar1;
  u32 uVar2;
  int iVar3;
  long lVar4;
  u64 uVar5;
  int iVar6;
  u8 auStack_18 [4];
  int iStack_14;
  u8 auStack_c [4];
  u8 auStack_8 [4];
  u32 uStack_4;
  
  lVar4 = ((code)FUN_004c5250)(param_1,auStack_18,8);
  iVar3 = iStack_14;
  if (lVar4 == 8) {
    uVar5 = (*DAT_00960178)(0xc,0x30190);
    puVar1 = (u32 *)uVar5;
    puVar1[1] = 1;
    uVar2 = ((code)FUN_004c1d50)(0xc,0x301a4);
    *puVar1 = uVar2;
    puVar1[2] = 0;
    if (iVar3 != 0) {
      ((code)FUN_004c1f70)(*puVar1,iVar3,0x301a4);
    }
    iVar3 = ((code)FUN_004c2090)(*puVar1);
    iVar6 = 0;
    if (0 < iStack_14) {
      do {
        lVar4 = ((code)FUN_004c5250)(param_1,&uStack_4,4);
        if (lVar4 != 4) {
          return 0;
        }
        if ((uStack_4 & 4) == 0) {
          *(u32 *)(iVar3 + 4) = 0;
          *(u32 *)(iVar3 + 8) = 0;
        }
        else {
          ((code)FUN_004c1910)(param_1,iVar3);
          lVar4 = ((code)FUN_004c1600)(param_1,0x1a1,auStack_8,auStack_c);
          if (lVar4 == 0) {
            return 0;
          }
          uVar2 = ((code)FUN_004ac570)();
          *(u32 *)(iVar3 + 4) = uVar2;
          ((code)FUN_004ac710)(*(u32 *)(iVar3 + 4));
          ((code)FUN_004acb10)(*(u32 *)(iVar3 + 4),param_1);
          lVar4 = ((code)FUN_004c1600)(param_1,0x1a2,auStack_8,auStack_c);
          if (lVar4 == 0) {
            return 0;
          }
          uVar2 = ((code)FUN_004a5470)();
          *(u32 *)(iVar3 + 8) = uVar2;
          ((code)FUN_004a6530)(*(u32 *)(iVar3 + 8),param_1);
        }
        iVar6 = iVar6 + 1;
        iVar3 = iVar3 + 0xc;
      } while (iVar6 < iStack_14);
    }
    uVar2 = ((code)FUN_004af340)(uVar5);
    puVar1[2] = uVar2;
  }
  else {
    uVar5 = 0;
  }
  return uVar5;
}

// FUN_004AF940 NONMATCHING

u32 FUN_004af940(int param_1)

{
  int iVar1;
  int iVar2;
  
  ((code)FUN_004af130)(*(u32 *)(param_1 + 0xb0));
  iVar1 = *(int *)(param_1 + 0xb8);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 4);
    if (iVar2 != 0) {
      ((code)FUN_00492d10)(iVar1,0);
      ((code)FUN_004caf80)(iVar2);
    }
    ((code)FUN_00491a80)(*(u32 *)(param_1 + 0xb8));
  }
  if (*(int *)(param_1 + 0xb4) != 0) {
    (*DAT_0096017c)();
    *(u32 *)(param_1 + 0xb4) = 0;
  }
  return 1;
}

// FUN_004AF9D0 NONMATCHING






u64 FUN_004af9d0(u64 param_1,float *param_2,float *param_3)

{
  u32 uVar1;
  u32 uVar2;
  u32 *puVar3;
  int iVar4;
  u32 *puVar5;
  u64 uVar6;
  u8 *pbVar7;
  int iVar8;
  int iVar9;
  u32 *puVar10;
  int iVar11;
  u32 uVar12;
  u32 *puVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  Vec128 auStack_70;
  Vec128 auStack_60;
  Vec128 auStack_50;
  Vec128 auStack_40;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  u8 uStack_4;
  u8 uStack_3;
  u8 uStack_2;
  u8 uStack_1;
  
  iVar4 = (int)param_1;
  if ((*(u32 *)(iVar4 + 8) & 4) != 0) {
    fStack_20 = *(float *)(iVar4 + 0x90) * *param_2;
    fStack_1c = *(float *)(iVar4 + 0x94) * param_2[1];
    fStack_18 = *(float *)(iVar4 + 0x98) * param_2[2];
    fStack_14 = *(float *)(iVar4 + 0x9c) * param_2[3];
    fStack_30 = *param_3 * 255.0 + *(float *)(iVar4 + 0xa0) * *param_2;
    fStack_2c = param_3[1] * 255.0 + *(float *)(iVar4 + 0xa4) * param_2[1];
    fStack_28 = param_3[2] * 255.0 + *(float *)(iVar4 + 0xa8) * param_2[2];
    fStack_24 = param_3[3] * 255.0 + *(float *)(iVar4 + 0xac) * param_2[3];
    if (*(int *)(iVar4 + 0xb8) == 0) {
      if ((*(u32 *)(iVar4 + 8) & 2) == 2) {
        ((code)FUN_004aab40)(iVar4 + 0x10);
        puVar5 = (u32 *)((code)FUN_004ab0c0)();
        puVar10 = (u32 *)(iVar4 + 0x50);
        iVar9 = 8;
        do {
          iVar9 = iVar9 + -1;
          uVar2 = puVar5[1];
          *puVar10 = *puVar5;
          puVar5 = puVar5 + 2;
          puVar10[1] = uVar2;
          puVar10 = puVar10 + 2;
        } while (0 < iVar9);
        *(u32 *)(iVar4 + 8) = *(u32 *)(iVar4 + 8) & 0xfffffffd;
      }
      else {
        ((code)FUN_004aac70)(iVar4 + 0x50);
      }
      puVar3 = (u32 *)((code)FUN_004c2090)(**(u32 **)(iVar4 + 0xb0));
      iVar4 = ((code)FUN_004c2120)(**(u32 **)(iVar4 + 0xb0));
      puVar13 = puVar3 + iVar4 * 3;
      if (puVar3 != puVar13) {
        do {
          uVar1 = puVar3[2];
          ((code)FUN_00521250)(auStack_70,uVar1 + 0x30,0x10);
          ((code)FUN_00521250)(auStack_60,uVar1 + 0x48,0x10);
          ((code)FUN_00521250)(auStack_50,uVar1 + 0x18,0x10);
          ((code)FUN_00521250)(auStack_40,uVar1,0x10);
          ((code)FUN_004a55b0)(uVar1,auStack_70,auStack_60,auStack_50,auStack_40,&fStack_20,&fStack_30);
          if ((*puVar3 & 1) == 0) {
            thunk_FUN_0046bab0(puVar3[1],uVar1);
          }
          else {
            ((code)FUN_004a6600)(puVar3[1],uVar1);
          }
          ((code)FUN_00521250)(uVar1 + 0x30,auStack_70,0x10);
          ((code)FUN_00521250)(uVar1 + 0x48,auStack_60,0x10);
          ((code)FUN_00521250)(uVar1 + 0x18,auStack_50,0x10);
          ((code)FUN_00521250)(uVar1,auStack_40,0x10);
          puVar3 = puVar3 + 3;
        } while (puVar3 != puVar13);
      }
    }
    else {
      iVar9 = *(int *)(*(int *)(iVar4 + 0xb0) + 8);
      uVar1 = *(u32 *)(iVar9 + 0x24);
      uVar12 = 0;
      if (uVar1 != 0) {
        iVar11 = 0;
        do {
          pbVar7 = (u8 *)(*(int *)(iVar4 + 0xb4) + iVar11);
          iVar14 = (int)(fStack_20 * (float)*pbVar7 + fStack_30 + 0.0);
          iVar15 = (int)(fStack_1c * (float)pbVar7[1] + fStack_2c + 0.0);
          iVar16 = (int)(fStack_18 * (float)pbVar7[2] + fStack_28 + 0.0);
          iVar17 = (int)(fStack_14 * (float)pbVar7[3] + fStack_24 + 0.0);
          iVar8 = iVar14;
          if (0xff < iVar14) {
            iVar8 = 0xff;
          }
          if (iVar8 < 1) {
            uStack_4 = 0;
          }
          else {
            if (0xff < iVar14) {
              iVar14 = 0xff;
            }
            uStack_4 = (u8)iVar14;
          }
          iVar8 = iVar15;
          if (0xff < iVar15) {
            iVar8 = 0xff;
          }
          if (iVar8 < 1) {
            uStack_3 = 0;
          }
          else {
            if (0xff < iVar15) {
              iVar15 = 0xff;
            }
            uStack_3 = (u8)iVar15;
          }
          iVar8 = iVar16;
          if (0xff < iVar16) {
            iVar8 = 0xff;
          }
          if (iVar8 < 1) {
            uStack_2 = 0;
          }
          else {
            if (0xff < iVar16) {
              iVar16 = 0xff;
            }
            uStack_2 = (u8)iVar16;
          }
          iVar8 = iVar17;
          if (0xff < iVar17) {
            iVar8 = 0xff;
          }
          if (iVar8 < 1) {
            uStack_1 = 0;
            iVar8 = *(int *)(iVar9 + 0x20);
          }
          else {
            if (0xff < iVar17) {
              iVar17 = 0xff;
            }
            uStack_1 = (u8)iVar17;
            iVar8 = *(int *)(iVar9 + 0x20);
          }
          uVar12 = uVar12 + 1;
          iVar8 = *(int *)(iVar8 + iVar11);
          iVar11 = iVar11 + 4;
          *(u8 *)(iVar8 + 4) = uStack_4;
          *(u8 *)(iVar8 + 5) = uStack_3;
          *(u8 *)(iVar8 + 6) = uStack_2;
          *(u8 *)(iVar8 + 7) = uStack_1;
        } while (uVar12 < uVar1);
      }
      *(u32 *)(iVar4 + 8) = *(u32 *)(iVar4 + 8) & 0xfffffff7;
      if ((*(u32 *)(iVar4 + 8) & 2) == 2) {
        ((code)FUN_004aab40)(iVar4 + 0x10);
        puVar5 = (u32 *)((code)FUN_004ab0c0)();
        puVar10 = (u32 *)(iVar4 + 0x50);
        iVar9 = 8;
        do {
          iVar9 = iVar9 + -1;
          uVar2 = puVar5[1];
          *puVar10 = *puVar5;
          puVar5 = puVar5 + 2;
          puVar10[1] = uVar2;
          puVar10 = puVar10 + 2;
        } while (0 < iVar9);
        *(u32 *)(iVar4 + 8) = *(u32 *)(iVar4 + 8) & 0xfffffffd;
      }
      else {
        ((code)FUN_004aac70)(iVar4 + 0x50);
      }
      uVar6 = ((code)FUN_004aae60)();
      ((code)FUN_004cb7f0)(*(u32 *)(*(int *)(iVar4 + 0xb8) + 4),uVar6,0);
      (**(code **)(*(int *)(iVar4 + 0xb8) + 0x48))();
    }
    ((code)FUN_004aad50)();
  }
  return param_1;
}

// FUN_004AFFE0 NONMATCHING

u64 FUN_004affe0(u64 param_1,u64 param_2,long param_3)

{
  u8 uVar1;
  u8 uVar2;
  u8 uVar3;
  int iVar4;
  u32 uVar5;
  int iVar6;
  int iVar7;
  u8 *puVar8;
  u32 *puVar9;
  u32 uVar10;
  long lVar11;
  u64 uVar12;
  u64 uVar13;
  u8 *puVar14;
  int iVar15;
  u32 uVar16;
  int iVar17;
  int iStack_4;
  
  if (param_3 == 0) {
    iVar7 = ((code)FUN_004af760)(param_2);
  }
  else {
    lVar11 = ((code)FUN_004c5250)(param_2,&iStack_4,4);
    if (lVar11 != 4) {
      return 0;
    }
    iVar7 = *(int *)(*(int *)param_3 + iStack_4 * 4);
  }
  iVar17 = (int)param_1;
  *(u32 *)(iVar17 + 8) = *(u32 *)(iVar17 + 8) & 0xfffffffe;
  iVar4 = *(int *)(iVar7 + 8);
  uVar5 = *(u32 *)(iVar4 + 0x24);
  if (uVar5 == 0) {
    puVar8 = (u8 *)0x0;
  }
  else {
    puVar8 = (u8 *)(*DAT_00960178)(uVar5 << 2,0x30190);
    uVar16 = 0;
    if (uVar5 != 0) {
      if (8 < uVar5) {
        iVar15 = 0;
        puVar14 = puVar8;
        do {
          uVar16 = uVar16 + 8;
          iVar6 = *(int *)(*(int *)(iVar4 + 0x20) + iVar15);
          uVar1 = *(u8 *)(iVar6 + 5);
          uVar2 = *(u8 *)(iVar6 + 6);
          uVar3 = *(u8 *)(iVar6 + 7);
          *puVar14 = *(u8 *)(iVar6 + 4);
          puVar14[1] = uVar1;
          puVar14[2] = uVar2;
          puVar14[3] = uVar3;
          iVar6 = *(int *)(*(int *)(iVar4 + 0x20) + iVar15 + 4);
          uVar1 = *(u8 *)(iVar6 + 5);
          uVar2 = *(u8 *)(iVar6 + 6);
          uVar3 = *(u8 *)(iVar6 + 7);
          puVar14[4] = *(u8 *)(iVar6 + 4);
          puVar14[5] = uVar1;
          puVar14[6] = uVar2;
          puVar14[7] = uVar3;
          iVar6 = *(int *)(*(int *)(iVar4 + 0x20) + iVar15 + 8);
          uVar1 = *(u8 *)(iVar6 + 5);
          uVar2 = *(u8 *)(iVar6 + 6);
          uVar3 = *(u8 *)(iVar6 + 7);
          puVar14[8] = *(u8 *)(iVar6 + 4);
          puVar14[9] = uVar1;
          puVar14[10] = uVar2;
          puVar14[0xb] = uVar3;
          iVar6 = *(int *)(*(int *)(iVar4 + 0x20) + iVar15 + 0xc);
          uVar1 = *(u8 *)(iVar6 + 5);
          uVar2 = *(u8 *)(iVar6 + 6);
          uVar3 = *(u8 *)(iVar6 + 7);
          puVar14[0xc] = *(u8 *)(iVar6 + 4);
          puVar14[0xd] = uVar1;
          puVar14[0xe] = uVar2;
          puVar14[0xf] = uVar3;
          iVar6 = *(int *)(*(int *)(iVar4 + 0x20) + iVar15 + 0x10);
          uVar1 = *(u8 *)(iVar6 + 5);
          uVar2 = *(u8 *)(iVar6 + 6);
          uVar3 = *(u8 *)(iVar6 + 7);
          puVar14[0x10] = *(u8 *)(iVar6 + 4);
          puVar14[0x11] = uVar1;
          puVar14[0x12] = uVar2;
          puVar14[0x13] = uVar3;
          iVar6 = *(int *)(*(int *)(iVar4 + 0x20) + iVar15 + 0x14);
          uVar1 = *(u8 *)(iVar6 + 5);
          uVar2 = *(u8 *)(iVar6 + 6);
          uVar3 = *(u8 *)(iVar6 + 7);
          puVar14[0x14] = *(u8 *)(iVar6 + 4);
          puVar14[0x15] = uVar1;
          puVar14[0x16] = uVar2;
          puVar14[0x17] = uVar3;
          iVar6 = *(int *)(*(int *)(iVar4 + 0x20) + iVar15 + 0x18);
          uVar1 = *(u8 *)(iVar6 + 5);
          uVar2 = *(u8 *)(iVar6 + 6);
          uVar3 = *(u8 *)(iVar6 + 7);
          puVar14[0x18] = *(u8 *)(iVar6 + 4);
          puVar14[0x19] = uVar1;
          puVar14[0x1a] = uVar2;
          puVar14[0x1b] = uVar3;
          iVar6 = *(int *)(*(int *)(iVar4 + 0x20) + iVar15 + 0x1c);
          iVar15 = iVar15 + 0x20;
          uVar1 = *(u8 *)(iVar6 + 5);
          uVar2 = *(u8 *)(iVar6 + 6);
          uVar3 = *(u8 *)(iVar6 + 7);
          puVar14[0x1c] = *(u8 *)(iVar6 + 4);
          puVar14[0x1d] = uVar1;
          puVar14[0x1e] = uVar2;
          puVar14[0x1f] = uVar3;
          puVar14 = puVar14 + 0x20;
        } while (uVar16 < uVar5 - 8);
      }
      if (uVar16 < uVar5) {
        iVar15 = uVar16 * 4;
        puVar14 = puVar8 + iVar15;
        do {
          uVar16 = uVar16 + 1;
          iVar6 = *(int *)(*(int *)(iVar4 + 0x20) + iVar15);
          iVar15 = iVar15 + 4;
          uVar1 = *(u8 *)(iVar6 + 5);
          uVar2 = *(u8 *)(iVar6 + 6);
          uVar3 = *(u8 *)(iVar6 + 7);
          *puVar14 = *(u8 *)(iVar6 + 4);
          puVar14[1] = uVar1;
          puVar14[2] = uVar2;
          puVar14[3] = uVar3;
          puVar14 = puVar14 + 4;
        } while (uVar16 < uVar5);
      }
    }
  }
  *(u8 **)(iVar17 + 0xb4) = puVar8;
  if (iVar7 == 0) {
    puVar9 = (u32 *)(*DAT_00960178)(0xc,0x30190);
    puVar9[1] = 1;
    uVar10 = ((code)FUN_004c1d50)(0xc,0x301a4);
    *puVar9 = uVar10;
    puVar9[2] = 0;
    *(u32 **)(iVar17 + 0xb0) = puVar9;
    *(u32 *)(iVar17 + 0xb4) = 0;
  }
  else {
    *(int *)(iVar17 + 0xb0) = iVar7;
    *(int *)(iVar7 + 4) = *(int *)(iVar7 + 4) + 1;
  }
  *(u32 *)(iVar17 + 8) = *(u32 *)(iVar17 + 8) | 1;
  uVar12 = ((code)FUN_004caf10)();
  uVar13 = ((code)FUN_004aae60)();
  ((code)FUN_004cb7f0)(uVar12,uVar13,0);
  uVar13 = ((code)FUN_00491880)();
  ((code)FUN_00492d10)(uVar13,uVar12);
  ((code)FUN_004919b0)(uVar13,*(u32 *)(iVar7 + 8),0);
  *(int *)(iVar17 + 0xb8) = (int)uVar13;
  return param_1;
}
