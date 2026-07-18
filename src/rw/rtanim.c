#include "temporary.h"

/* auto-extern (generated) */
extern u32* pcGpffffba74;
extern u32* puGpffffbd04;
extern void* FUN_0046b510(int param_1,u64 param_2);
extern float fRam0000000c;
extern u64 thunk_FUN_004687e0(int *param_1,int *param_2);
extern u8 LAB_00464760;
extern u8 LAB_00465660;
extern u8 LAB_004657d0;
extern u8 LAB_00486100;
extern u8 LAB_00486980;
extern u8 LAB_00486ae0;
extern u8 LAB_00486ec0;
extern u8 LAB_00487520;
extern u8 LAB_00487990;
extern u8 LAB_00487ac0;
extern u8 LAB_00487e80;
extern u8 LAB_00487ef0;
extern u8 LAB_004880b0;
extern u8 LAB_00488260;
extern u8 LAB_004882f0;
extern u8 LAB_00488390;
extern u8 LAB_00488410;
extern u8 LAB_004884a0;
extern u8 LAB_00488b80;
extern u8 LAB_00488b90;

extern char s_G3_2DStroke_Node_c_006b5770[];
extern char s_G3_2DFont_Node_c_006b58c0[];
extern char s_G3_2DFill_Node_c_006b5a10[];
extern u32 stack0x00000000;
extern u32 lVar11;
extern u32 LAB_004745f4;

typedef int (*code)(...);
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
extern u32 iGpffffba40;
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
f32 FUN_0048ef60(int param_1, int param_2);
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
u64 FUN_00469060(u64 param_1,int *param_2);
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
u32 FUN_004747f0(int *param_1);
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
u64 FUN_00490d40(u64 param_1);
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
u64 FUN_00493b40(u64 param_1);
u64 FUN_004944b0(u64 param_1,u32 *param_2);
u64 FUN_004948b0(u64 param_1);
u64 FUN_00494930(u64 param_1,int param_2);
u64 FUN_004949c0(u64 param_1,int param_2);
u64 FUN_00494a40(u64 param_1,u64 param_2,int param_3);
u64 FUN_00494ae0(u64 param_1,int param_2);
u64 FUN_00494b70(u64 param_1);
u64 FUN_00494d50(u64 param_1,long param_2);
u64 FUN_00495260(u64 param_1);
u64 FUN_00495300(u64 param_1);
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
u64 FUN_0049a3d0(u64 param_1,code *param_2);
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
u64 FUN_004a6600(u64 param_1);
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
u64 FUN_004ae110(u64 param_1,u64 param_2);
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
void FUN_0048efc0(int param_1, int param_2, f32 param_3);
void FUN_00491100(int param_1);
void FUN_00492c30(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00492c60(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00492c90(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00492cc0(u64 param_1,u64 param_2);
void FUN_00492ce0(u64 param_1,u64 param_2);
void FUN_00492d00(u64 param_1);
void FUN_00493c50(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00493c80(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00494520(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00494550(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00494db0(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00494de0(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00494e10(u64 param_1,u64 param_2);
void FUN_00495480(int *param_1,int param_2);
void FUN_004959c0(u64 param_1);
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

extern u32 DAT_006b5150;
extern u32 DAT_006b5158;
extern u32 DAT_006b5160;
extern u32 DAT_006b5168;
extern u32 DAT_0077abc0;
extern u32 DAT_0077abc4;
extern u32 DAT_0077abc8;
extern u32 DAT_0077abcc;
extern u32 DAT_0077abd0;
extern u32 DAT_0077abd4;
extern u32 DAT_0077abd8;
extern u32 DAT_0077abdc;
extern u32 DAT_0077abe0;
extern u32 DAT_0077ac10;
extern u32 DAT_0077ac50;
extern u32 DAT_0077ac58;
extern u32 DAT_0077dcb0;
extern u32 DAT_0077dcb4;
extern u32 DAT_0077dcb8;
extern u32 DAT_007bc900;
extern u32 DAT_007bc904;
extern u32 DAT_007bc908;
extern u32 DAT_007bc90c;
extern u32 DAT_007bc910;
extern u32 DAT_007bc914;
extern u32 DAT_007bc918;
extern u32 DAT_007bc91c;
extern u32 DAT_007bc920;
extern u32 DAT_007cdb18;
extern u32 DAT_007cdb1c;
extern u32 DAT_007cdb20;
extern u32 DAT_007cdb24;
extern u32 DAT_007cdb30;
extern u32 DAT_007cdb34;
extern u32 DAT_007cdb38;
extern u32 DAT_007cdb3c;
extern u32 DAT_007cdbb8;
extern u32 DAT_007cdbc0;
extern u32 DAT_007cdbc1;
extern u32 DAT_007cdbc2;
extern u32 DAT_007cdbc3;
extern u32 DAT_007cddc0;
extern u32 DAT_007cdde8;
extern u32 DAT_007ce730;
extern u32 DAT_007ce734;
extern u32 DAT_007ce738;
extern u32 DAT_007ce73c;
extern u32 DAT_007ce740;
extern u32 DAT_007ce770;
extern u32 DAT_007ce774;
extern u32 DAT_007ce77c;
extern u32 DAT_007ce780;
extern u32 DAT_007ce784;
extern u32 DAT_007ce788;
extern u32 DAT_007ce78c;
extern u32 DAT_007ce790;
extern u32 DAT_007ce794;
extern u32 DAT_007ce798;
extern u32 DAT_007ce88c;
extern u32 DAT_007ce890;
extern u32* DAT_007ce9f4;
extern u32 DAT_007cea30;
extern u32 DAT_007cea40;
extern u32 DAT_007cea50;
extern u32 DAT_007cea58;
extern u32 DAT_007cea60;
extern u32 DAT_007cea68;
extern u32 DAT_007ceaa4;
extern u32 DAT_007ceaa8;
extern u32 DAT_007ceaac;
extern u32 DAT_007ceab4;
extern u32 DAT_007ceab8;
extern u32 DAT_007ceabc;
extern u32 DAT_007ceaf4;
extern u32 DAT_007ceaf8;
extern u32 DAT_007ceafc;
extern u32 DAT_007ceb00;
extern u32 DAT_007ceb04;
extern u32 DAT_0095c3fc;
extern u32 DAT_0095c400;
extern u32 DAT_0095c440;
extern u32 DAT_0095c448;
extern u32 DAT_0095c44c;
extern u32 DAT_0095c45c;
extern u32 DAT_0095c460;
extern u32 DAT_0095c46c;
extern u32 DAT_0095d3a8;
extern u32 DAT_0095d3b8;
extern u32 DAT_0095d3c8;
extern u32 DAT_0095d3d8;
extern u32 DAT_0095d3e8;
extern u32 DAT_0095d3f8;
extern u32 DAT_0095d408;
extern u32 DAT_0095de14;
extern u32 DAT_0095de18;
extern u32 DAT_0095de1c;
extern code DAT_0095de34;
extern u32* DAT_0095de38;
extern u32 DAT_0095ed64;
extern u32 DAT_0095ef58;
extern u32 DAT_0095ef84;
extern u32* DAT_0095ef88;
extern u32* DAT_0095ef8c;
extern u32 DAT_0095ef94;
extern u32 DAT_0095ef98;
extern u32 DAT_0095ef9c;
extern u32 DAT_0095efa0;
extern u32 DAT_0095efa4;
extern u32 DAT_0095efa8;
extern u32 DAT_0095efac;
extern u32 DAT_0095efb0;
extern u32 DAT_0095efbc;
extern u32 DAT_0095efc0;
extern u32 DAT_0095efc4;
extern u32 DAT_0095efc8;
extern u32 DAT_0095f040;
extern u32 DAT_0095f048;
extern u32 DAT_0095f050;
extern u32 DAT_00960070;
extern u32 DAT_00960078;
extern u32 DAT_0096007a;
extern code DAT_00960090;
extern code DAT_00960094;
extern u32 DAT_0096009c;
extern u32 DAT_0096012c;
extern code DAT_0096013c;
extern code DAT_00960164;
extern code DAT_00960178;
extern code DAT_0096017c;
extern code DAT_00960180;
extern code DAT_00960188;
extern code DAT_0096018c;
extern u32* DAT_009658a0;
extern u32 DAT_009658a8;
extern u32 DAT_009658ac;
extern u32* DAT_00965910;
extern u32 DAT_00965914;
extern u32 DAT_00965918;
extern u32 DAT_0096591c;
extern u32 DAT_00965920;
extern u32 DAT_00965924;
extern u32 DAT_00965928;
extern u32 DAT_0096592c;
extern u32* DAT_00965930;
extern u32 DAT_00965940;
extern u32 DAT_00965944;
extern u32 DAT_00965948;
extern u32 DAT_0096594c;
extern u32 DAT_70000000;
extern u32 DAT_700002c0;
extern u32 DAT_70000300;
extern u32 DAT_700005c0;
extern u32 DAT_70000840;
extern u32 DAT_70000cc0;
extern u32 DAT_70000f00;
extern u32 DAT_70001140;
extern u32 DAT_70001340;
extern u32 DAT_70001550;
extern u32 DAT_70001fc0;
extern u32 DAT_70003f00;
extern u32 DAT_70003f04;
extern u32 DAT_70003f08;
extern u32 DAT_70003f10;
extern u32 DAT_70003f14;
extern u32 DAT_70003f18;
extern u32 DAT_70003f20;
extern u32 DAT_70003f24;
extern u32 DAT_70003f28;
extern u32 DAT_70003f2c;
extern u32 DAT_70003f30;
extern u32 DAT_70003f34;
extern u32 DAT_70003f38;
extern u32 DAT_70003f3c;
extern u32 DAT_70003f40;
extern u32 DAT_70003f44;
extern u32 DAT_70003f48;
extern u32 DAT_70003f4c;
extern u32 DAT_70003f50;
extern u32 DAT_70003f54;
extern u32 DAT_70003f58;
extern u32 DAT_70003f60;
extern u32 DAT_70003f64;
extern u32 DAT_70003f68;
extern u32 DAT_70003f6c;
extern u32 DAT_70003f70;
extern u32 DAT_70003f74;
extern u32 DAT_70003f78;
extern u32 DAT_70003f7c;
extern u32 DAT_70003f90;
extern u32 DAT_70003f94;
extern u32 DAT_70003fa0;
extern u32 DAT_70003fa4;
extern u32 DAT_70003fa8;
extern u32 DAT_70003fac;
extern u32 DAT_70003fb0;
extern u32 DAT_70003fb4;
extern u32 PTR_FUN_006b4ee4;
extern u32 PTR_FUN_0077b250;
extern u32 PTR_FUN_0077b254;
extern u32 REG_DMAC_8_SPR_FROM_CHCR;
extern u32 REG_DMAC_8_SPR_FROM_MADR;
extern u32 REG_DMAC_8_SPR_FROM_QWC;
extern u32 REG_DMAC_8_SPR_FROM_SADR;
extern u32 REG_DMAC_9_SPR_TO_CHCR;
extern u32 REG_DMAC_9_SPR_TO_MADR;
extern u32 REG_DMAC_9_SPR_TO_QWC;
extern u32 REG_DMAC_9_SPR_TO_SADR;
extern u32 REG_DMAC_PCR;
extern u32 REG_DMAC_STAT;
extern u32 Status;
extern Vec128 _DAT_00965910;
extern Vec128 _DAT_00965920;
extern Vec128 _DAT_00965930;
extern Vec128 _DAT_00965940;
extern u32 _DAT_70000000;
extern u32 bGpffffbe04;
extern u32 iGpffffb0f8;
extern u32 iGpffffba48;
extern u32 iGpffffba44;
extern u32 iGpffffba4c;
extern u32 iGpffffba50;
extern u32 iGpffffba54;
extern u32 iGpffffba58;
extern u32 iGpffffba70;
extern u32 iGpffffba80;
extern u32 iGpffffba84;
extern u32 iGpffffbb60;
extern u32 iGpffffbb9c;
extern u32 iGpffffbba0;
extern u32 iGpffffbdb4;
extern u32 iGpffffbdb8;
extern u32 iGpffffbdbc;
extern u32 iGpffffbdc8;
extern u32 iGpffffbdcc;
extern u32 iGpffffbe14;
extern u32 iRam00000008;
extern u32 iRam007ce820;
extern u32 uGpffffb0d0;
extern u32 uGpffffba48;
extern u32 uGpffffba4c;
extern u32 uGpffffba50;
extern u32 uGpffffba54;
extern u32 uGpffffba58;
extern u32 uGpffffba78;
extern u32 uGpffffba80;
extern u32 uGpffffba84;
extern u32 uGpffffbd40;
extern u32 uGpffffbd50;
extern u32 uGpffffbd60;
extern u32 uGpffffbd68;
extern u32 uGpffffbd70;
extern u32 uGpffffbdc4;
extern u32 uGpffffbdc8;
extern u32 uGpffffbdcc;
extern u32 uGpffffbe04;
extern u32 uGpffffbe08;
extern u32 uGpffffbe0c;
extern u32 uGpffffbe10;
extern u32 uRam00000000;
extern u32 uRam00000004;
extern u32 uRam00000008;
extern u32 uRam0000000c;
extern u32 uRam70003f0c;
extern u32 uRam70003f1c;
extern u32 uRam70003f5c;
extern u32 uRam70003f98;
extern u32 uRam70003fb8;
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
#pragma alias FUN_004c17f0_typed FUN_004c17f0
extern long FUN_004c17f0_typed(u64 param_1,void *param_2,int param_3);
#pragma alias FUN_004c3c30_typed FUN_004c3c30
extern u32 FUN_004c3c30_typed(u32 param_1);
#pragma alias FUN_004c47e0_typed FUN_004c47e0
extern void FUN_004c47e0_typed(u32 param_1);
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
extern code FUN_004c1e70;
extern code FUN_004c1f70;
extern code FUN_004c2090;
extern code FUN_004c20b0;
extern code FUN_004c2120;
extern code FUN_004c2130;
extern code FUN_004c21b0;
extern code FUN_004c2d20;
extern code FUN_004c2f30;
extern code FUN_004c31b0;
extern code FUN_004c32a0;
extern code FUN_004c33d0;
extern code FUN_004c35d0;
extern code FUN_004c3880;
extern code FUN_004c38c0;
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
extern code FUN_004c5a50;
extern code FUN_004c5c30;
extern code FUN_004c6170;
extern code FUN_004c61b0;
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
extern code FUN_004d51c0;
extern code FUN_004d59d0;
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
f32 FUN_0048ef60(int param_1, int param_2);
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
u64 FUN_00469060(u64 param_1,int *param_2);
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
u32 FUN_004747f0(int *param_1);
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
u64 FUN_00490d40(u64 param_1);
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
u64 FUN_00493b40(u64 param_1);
u64 FUN_004944b0(u64 param_1,u32 *param_2);
u64 FUN_004948b0(u64 param_1);
u64 FUN_00494930(u64 param_1,int param_2);
u64 FUN_004949c0(u64 param_1,int param_2);
u64 FUN_00494a40(u64 param_1,u64 param_2,int param_3);
u64 FUN_00494ae0(u64 param_1,int param_2);
u64 FUN_00494b70(u64 param_1);
u64 FUN_00494d50(u64 param_1,long param_2);
u64 FUN_00495260(u64 param_1);
u64 FUN_00495300(u64 param_1);
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
u64 FUN_0049a3d0(u64 param_1,code *param_2);
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
u64 FUN_004a6600(u64 param_1);
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
u64 FUN_004ae110(u64 param_1,u64 param_2);
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
void FUN_0048efc0(int param_1, int param_2, f32 param_3);
void FUN_00491100(int param_1);
void FUN_00492c30(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00492c60(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00492c90(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00492cc0(u64 param_1,u64 param_2);
void FUN_00492ce0(u64 param_1,u64 param_2);
void FUN_00492d00(u64 param_1);
void FUN_00493c50(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00493c80(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00494520(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00494550(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00494db0(u64 param_1,u64 param_2,u64 param_3,u64 param_4, u64 param_5);
void FUN_00494de0(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00494e10(u64 param_1,u64 param_2);
void FUN_00495480(int *param_1,int param_2);
void FUN_004959c0(u64 param_1);
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

// FUN_00464850 NONMATCHING

void FUN_00464850(float param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar3 = (param_1 - *(float *)(param_3 + 4)) / (*(float *)(param_4 + 4) - *(float *)(param_3 + 4));
  fVar2 = *(float *)(param_3 + 0x14) * *(float *)(param_4 + 0x14) +
          *(float *)(param_3 + 0x10) * *(float *)(param_4 + 0x10) +
          *(float *)(param_3 + 8) * *(float *)(param_4 + 8) +
          *(float *)(param_3 + 0xc) * *(float *)(param_4 + 0xc);
  *(float *)(param_2 + 0x18) =
       fVar3 * (*(float *)(param_4 + 0x18) - *(float *)(param_3 + 0x18)) +
       *(float *)(param_3 + 0x18) + 0.0;
  *(float *)(param_2 + 0x1c) =
       fVar3 * (*(float *)(param_4 + 0x1c) - *(float *)(param_3 + 0x1c)) +
       *(float *)(param_3 + 0x1c) + 0.0;
  *(float *)(param_2 + 0x20) =
       fVar3 * (*(float *)(param_4 + 0x20) - *(float *)(param_3 + 0x20)) +
       *(float *)(param_3 + 0x20) + 0.0;
  if (fVar2 < 0.0) {
    fVar2 = -fVar2;
    *(float *)(param_4 + 8) = -*(float *)(param_4 + 8);
    *(float *)(param_4 + 0xc) = -*(float *)(param_4 + 0xc);
    *(float *)(param_4 + 0x10) = -*(float *)(param_4 + 0x10);
    *(float *)(param_4 + 0x14) = -*(float *)(param_4 + 0x14);
  }
  fVar1 = 1.0 - fVar3;
  if (fVar2 < 0.999) {
    fVar4 = ABS(fVar2);
    if ((u32)fVar4 < 0x3f800000) {
      if ((u32)fVar4 < 0x3f000000) {
        if ((u32)fVar4 < 0x23000001) {
          fVar2 = 1.5707964;
        }
        else {
          fVar4 = fVar2 * fVar2;
          fVar2 = 1.5707963 -
                  (fVar2 - (7.5497894e-08 -
                           fVar2 * ((fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * 
                                                  3.479331e-05 + 0.000791535) + -0.040055536) +
                                                  0.20121253) + -0.32556581) + 0.16666667)) /
                                   (fVar4 * (fVar4 * (fVar4 * (fVar4 * 0.077038154 + -0.688284) +
                                                     2.0209458) + -2.403395) + 1.0))));
        }
      }
      else if ((int)fVar2 < 0) {
        fVar2 = (fVar2 + 1.0) * 0.5;
        fVar2 = 3.1415925 -
                (SQRT(fVar2) +
                (((fVar2 * (fVar2 * (fVar2 * (fVar2 * (fVar2 * (fVar2 * 3.479331e-05 + 0.000791535)
                                                      + -0.040055536) + 0.20121253) + -0.32556581) +
                           0.16666667)) /
                 (fVar2 * (fVar2 * (fVar2 * (fVar2 * 0.077038154 + -0.688284) + 2.0209458) +
                          -2.403395) + 1.0)) * SQRT(fVar2) - 7.5497894e-08)) * 2.0;
      }
      else {
        fVar4 = (1.0 - fVar2) * 0.5;
        fVar5 = SQRT(fVar4);
        fVar2 = (float)((u32)fVar5 & 0xfffff000);
        fVar2 = (fVar2 + ((fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * 3.479331e-05 +
                                                                       0.000791535) + -0.040055536)
                                                     + 0.20121253) + -0.32556581) + 0.16666667)) /
                         (fVar4 * (fVar4 * (fVar4 * (fVar4 * 0.077038154 + -0.688284) + 2.0209458) +
                                  -2.403395) + 1.0)) * fVar5 +
                         ((fVar4 + 0.0) - fVar2 * fVar2) / (fVar5 + fVar2) + 0.0) * 2.0;
      }
    }
    else if ((int)fVar2 < 1) {
      fVar2 = 3.1415927;
    }
    else {
      fVar2 = 0.0;
    }
    fVar4 = fVar2 * fVar2;
    fVar3 = fVar3 * fVar2;
    fVar4 = 1.0 / (fVar4 * fVar2 *
                   (fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * 1.589691e-10 + -2.505076e-08) +
                                              2.7557314e-06) + -0.0001984127) + 0.008333334) +
                   -0.16666667) + fVar2 + 0.0);
    fVar1 = fVar1 * fVar2;
    fVar2 = fVar1 * fVar1;
    fVar1 = (fVar2 * fVar1 *
             (fVar2 * (fVar2 * (fVar2 * (fVar2 * (fVar2 * 1.589691e-10 + -2.505076e-08) +
                                        2.7557314e-06) + -0.0001984127) + 0.008333334) + -0.16666667
             ) + fVar1 + 0.0) * fVar4;
    fVar2 = fVar3 * fVar3;
    fVar3 = (fVar2 * fVar3 *
             (fVar2 * (fVar2 * (fVar2 * (fVar2 * (fVar2 * 1.589691e-10 + -2.505076e-08) +
                                        2.7557314e-06) + -0.0001984127) + 0.008333334) + -0.16666667
             ) + fVar3 + 0.0) * fVar4;
  }
  *(float *)(param_2 + 8) = fVar1 * *(float *)(param_3 + 8) + fVar3 * *(float *)(param_4 + 8);
  *(float *)(param_2 + 0xc) = fVar1 * *(float *)(param_3 + 0xc) + fVar3 * *(float *)(param_4 + 0xc);
  *(float *)(param_2 + 0x10) =
       fVar1 * *(float *)(param_3 + 0x10) + fVar3 * *(float *)(param_4 + 0x10);
  *(float *)(param_2 + 0x14) =
       fVar1 * *(float *)(param_3 + 0x14) + fVar3 * *(float *)(param_4 + 0x14);
  return;
}

// FUN_00464E80 NONMATCHING

void FUN_00464e80(float param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *(float *)(param_3 + 0x14) * *(float *)(param_4 + 0x14) +
          *(float *)(param_3 + 0x10) * *(float *)(param_4 + 0x10) +
          *(float *)(param_3 + 8) * *(float *)(param_4 + 8) +
          *(float *)(param_3 + 0xc) * *(float *)(param_4 + 0xc);
  *(float *)(param_2 + 0x18) =
       param_1 * (*(float *)(param_4 + 0x18) - *(float *)(param_3 + 0x18)) +
       *(float *)(param_3 + 0x18) + 0.0;
  *(float *)(param_2 + 0x1c) =
       param_1 * (*(float *)(param_4 + 0x1c) - *(float *)(param_3 + 0x1c)) +
       *(float *)(param_3 + 0x1c) + 0.0;
  *(float *)(param_2 + 0x20) =
       param_1 * (*(float *)(param_4 + 0x20) - *(float *)(param_3 + 0x20)) +
       *(float *)(param_3 + 0x20) + 0.0;
  if (fVar1 < 0.0) {
    fVar1 = -fVar1;
    *(float *)(param_4 + 8) = -*(float *)(param_4 + 8);
    *(float *)(param_4 + 0xc) = -*(float *)(param_4 + 0xc);
    *(float *)(param_4 + 0x10) = -*(float *)(param_4 + 0x10);
    *(float *)(param_4 + 0x14) = -*(float *)(param_4 + 0x14);
  }
  fVar2 = 1.0 - param_1;
  if (fVar1 < 0.999) {
    fVar4 = ABS(fVar1);
    if ((u32)fVar4 < 0x3f800000) {
      if ((u32)fVar4 < 0x3f000000) {
        if ((u32)fVar4 < 0x23000001) {
          fVar1 = 1.5707964;
        }
        else {
          fVar4 = fVar1 * fVar1;
          fVar1 = 1.5707963 -
                  (fVar1 - (7.5497894e-08 -
                           fVar1 * ((fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * 
                                                  3.479331e-05 + 0.000791535) + -0.040055536) +
                                                  0.20121253) + -0.32556581) + 0.16666667)) /
                                   (fVar4 * (fVar4 * (fVar4 * (fVar4 * 0.077038154 + -0.688284) +
                                                     2.0209458) + -2.403395) + 1.0))));
        }
      }
      else if ((int)fVar1 < 0) {
        fVar1 = (fVar1 + 1.0) * 0.5;
        fVar1 = 3.1415925 -
                (SQRT(fVar1) +
                (((fVar1 * (fVar1 * (fVar1 * (fVar1 * (fVar1 * (fVar1 * 3.479331e-05 + 0.000791535)
                                                      + -0.040055536) + 0.20121253) + -0.32556581) +
                           0.16666667)) /
                 (fVar1 * (fVar1 * (fVar1 * (fVar1 * 0.077038154 + -0.688284) + 2.0209458) +
                          -2.403395) + 1.0)) * SQRT(fVar1) - 7.5497894e-08)) * 2.0;
      }
      else {
        fVar4 = (1.0 - fVar1) * 0.5;
        fVar3 = SQRT(fVar4);
        fVar1 = (float)((u32)fVar3 & 0xfffff000);
        fVar1 = (fVar1 + ((fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * 3.479331e-05 +
                                                                       0.000791535) + -0.040055536)
                                                     + 0.20121253) + -0.32556581) + 0.16666667)) /
                         (fVar4 * (fVar4 * (fVar4 * (fVar4 * 0.077038154 + -0.688284) + 2.0209458) +
                                  -2.403395) + 1.0)) * fVar3 +
                         ((fVar4 + 0.0) - fVar1 * fVar1) / (fVar3 + fVar1) + 0.0) * 2.0;
      }
    }
    else if ((int)fVar1 < 1) {
      fVar1 = 3.1415927;
    }
    else {
      fVar1 = 0.0;
    }
    fVar4 = fVar1 * fVar1;
    fVar2 = fVar2 * fVar1;
    fVar3 = 1.0 / (fVar4 * fVar1 *
                   (fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * 1.589691e-10 + -2.505076e-08) +
                                              2.7557314e-06) + -0.0001984127) + 0.008333334) +
                   -0.16666667) + fVar1 + 0.0);
    fVar4 = fVar2 * fVar2;
    param_1 = param_1 * fVar1;
    fVar2 = (fVar4 * fVar2 *
             (fVar4 * (fVar4 * (fVar4 * (fVar4 * (fVar4 * 1.589691e-10 + -2.505076e-08) +
                                        2.7557314e-06) + -0.0001984127) + 0.008333334) + -0.16666667
             ) + fVar2 + 0.0) * fVar3;
    fVar1 = param_1 * param_1;
    param_1 = (fVar1 * param_1 *
               (fVar1 * (fVar1 * (fVar1 * (fVar1 * (fVar1 * 1.589691e-10 + -2.505076e-08) +
                                          2.7557314e-06) + -0.0001984127) + 0.008333334) +
               -0.16666667) + param_1 + 0.0) * fVar3;
  }
  *(float *)(param_2 + 8) = fVar2 * *(float *)(param_3 + 8) + param_1 * *(float *)(param_4 + 8);
  *(float *)(param_2 + 0xc) =
       fVar2 * *(float *)(param_3 + 0xc) + param_1 * *(float *)(param_4 + 0xc);
  *(float *)(param_2 + 0x10) =
       fVar2 * *(float *)(param_3 + 0x10) + param_1 * *(float *)(param_4 + 0x10);
  *(float *)(param_2 + 0x14) =
       fVar2 * *(float *)(param_3 + 0x14) + param_1 * *(float *)(param_4 + 0x14);
  return;
}

// FUN_004654A0 NONMATCHING

u64 FUN_004654a0(u64 param_1,u64 param_2)

{
  int *piVar1;
  long lVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  u32 uStack_4;
  
  iVar3 = (int)param_2;
  piVar1 = *(int **)(iVar3 + 0x10);
  iVar5 = 0;
  piVar4 = piVar1;
  if (0 < *(int *)(iVar3 + 4)) {
    do {
      lVar2 = ((code)FUN_004c18b0)(param_1,piVar4 + 1,0x20);
      if (lVar2 == 0) {
        return 0;
      }
      lVar2 = ((code)FUN_004c1910)(param_1,&uStack_4,4);
      if (lVar2 == 0) {
        return 0;
      }
      iVar5 = iVar5 + 1;
      *piVar4 = (int)(piVar1 + (uStack_4 / 0x24) * 9);
      piVar4 = piVar4 + 9;
    } while (iVar5 < *(int *)(iVar3 + 4));
  }
  return param_2;
}

// FUN_00465590 NONMATCHING

u32 FUN_00465590(int param_1,u64 param_2)

{
  int *piVar1;
  long lVar2;
  int *piVar3;
  int iVar4;
  int iStack_4;
  
  piVar1 = *(int **)(param_1 + 0x10);
  iVar4 = 0;
  piVar3 = piVar1;
  if (0 < *(int *)(param_1 + 4)) {
    do {
      lVar2 = ((code)FUN_004c1750)(param_2,piVar3 + 1,0x20);
      if (lVar2 == 0) {
        return 0;
      }
      iStack_4 = *piVar3 - (int)piVar1;
      lVar2 = ((code)FUN_004c17f0)(param_2,&iStack_4,4);
      if (lVar2 == 0) {
        return 0;
      }
      iVar4 = iVar4 + 1;
      piVar3 = piVar3 + 9;
    } while (iVar4 < *(int *)(param_1 + 4));
  }
  return 1;
}

// FUN_00465670 NONMATCHING

void FUN_00465670(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  fVar4 = *(float *)(param_2 + 0xc);
  fVar5 = *(float *)(param_2 + 8);
  fVar2 = *(float *)(param_2 + 0x10);
  fVar3 = *(float *)(param_2 + 0x14);
  fVar1 = fVar3 * fVar3 + fVar2 * fVar2 + fVar5 * fVar5 + fVar4 * fVar4;
  if (0.0 < fVar1) {
    fVar1 = 1.0 / fVar1;
    uStack_4 = fVar3 * fVar1;
    fVar1 = -fVar1;
    uStack_10 = fVar5 * fVar1;
    uStack_c = fVar4 * fVar1;
    uStack_8 = fVar2 * fVar1;
  }
  fVar1 = *(float *)(param_1 + 0x14);
  fVar2 = *(float *)(param_1 + 0xc);
  fVar4 = *(float *)(param_1 + 8);
  fVar3 = *(float *)(param_1 + 0x10);
  *(float *)(param_1 + 0x14) =
       uStack_4 * fVar1 - (uStack_8 * fVar3 + uStack_10 * fVar4 + uStack_c * fVar2);
  *(float *)(param_1 + 8) = uStack_c * fVar3 - uStack_8 * fVar2;
  *(float *)(param_1 + 0xc) = uStack_8 * fVar4 - uStack_10 * fVar3;
  *(float *)(param_1 + 0x10) = uStack_10 * fVar2 - uStack_c * fVar4;
  *(float *)(param_1 + 8) = fVar4 * uStack_4 + *(float *)(param_1 + 8) + 0.0;
  *(float *)(param_1 + 0xc) = fVar2 * uStack_4 + *(float *)(param_1 + 0xc) + 0.0;
  *(float *)(param_1 + 0x10) = fVar3 * uStack_4 + *(float *)(param_1 + 0x10) + 0.0;
  *(float *)(param_1 + 8) = uStack_10 * fVar1 + *(float *)(param_1 + 8) + 0.0;
  *(float *)(param_1 + 0xc) = uStack_c * fVar1 + *(float *)(param_1 + 0xc) + 0.0;
  *(float *)(param_1 + 0x10) = uStack_8 * fVar1 + *(float *)(param_1 + 0x10) + 0.0;
  *(float *)(param_1 + 0x18) = *(float *)(param_1 + 0x18) - *(float *)(param_2 + 0x18);
  *(float *)(param_1 + 0x1c) = *(float *)(param_1 + 0x1c) - *(float *)(param_2 + 0x1c);
  *(float *)(param_1 + 0x20) = *(float *)(param_1 + 0x20) - *(float *)(param_2 + 0x20);
  return;
}

// FUN_00465930 NONMATCHING

u64 FUN_00465930(u64 param_1,u64 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar3 = (int)param_2;
  iVar5 = 0;
  if (0 < *(int *)(iVar3 + 4)) {
    iVar4 = 0;
    do {
      piVar6 = (int *)(*(int *)(iVar3 + 0x10) + iVar4);
      iVar1 = *piVar6;
      iVar2 = ((code)FUN_00466720)(param_1);
      if (iVar1 == iVar2) {
        piVar6[3] = (int)param_1;
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x10;
    } while (iVar5 < *(int *)(iVar3 + 4));
  }
  ((code)FUN_004cb270)(param_1);
  ((code)FUN_004cb6e0)(param_1,0x465930,param_2);
  return param_1;
}

// FUN_00465A00 NONMATCHING

u64 FUN_00465a00(u64 param_1)

{
  long lVar1;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u8 *puStack_24;
  code *pcStack_20;
  code *pcStack_1c;
  u8 *puStack_18;
  code *pcStack_14;
  code *pcStack_10;
  code *pcStack_c;
  u8 *puStack_8;
  u32 uStack_4;
  
  lVar1 = thunk_FUN_004c3970(0x24,DAT_007cdb18,4,DAT_007cdb1c,0x95c3d0,0x4011e);
  DAT_007ce734 = (u32)lVar1;
  if (lVar1 == 0) {
    param_1 = 0;
  }
  uStack_30 = 1;
  puStack_24 = &LAB_00464760;
  uStack_2c = 0x24;
  uStack_28 = 0x24;
  pcStack_1c = (code *)(FUN_00464850);
  pcStack_20 = (code *)(FUN_00464e80);
  pcStack_14 = (code *)(FUN_00465670);
  puStack_18 = &LAB_004657d0;
  pcStack_c = (code *)(FUN_00465590);
  pcStack_10 = (code *)(FUN_004654a0);
  uStack_4 = 0;
  puStack_8 = &LAB_00465660;
  ((code)FUN_004b6680)(&uStack_30);
  return param_1;
}

// FUN_00465AE0 NONMATCHING

u64 FUN_00465ae0(u64 param_1)

{
  if (iGpffffba44 != 0) {
    FUN_004c3c30_typed(iGpffffba44);
    iGpffffba44 = 0;
  }
  return param_1;
}
#pragma schedule off

// FUN_00465B40 NONMATCHING

int FUN_00465b40(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  u32 *puVar4;
  
  puVar4 = (u32 *)(param_1 + DAT_007ce730);
  iVar1 = puVar4[1];
  if (iVar1 != 0) {
    iVar3 = 0;
    if (0 < *(int *)(iVar1 + 4)) {
      iVar2 = 0;
      do {
        iVar3 = iVar3 + 1;
        *(u32 *)(*(int *)(iVar1 + 0x10) + iVar2 + 0xc) = 0;
        iVar2 = iVar2 + 0x10;
      } while (iVar3 < *(int *)(iVar1 + 4));
    }
    if (*(int *)(iVar1 + 0x14) == param_1) {
      ((code)FUN_004663d0)();
      puVar4[1] = 0;
    }
    else {
      puVar4[1] = 0;
    }
  }
  *puVar4 = 0xffffffff;
  return param_1;
}

// FUN_00465BF0 NONMATCHING

u64 FUN_00465bf0(u64 param_1,int param_2)

{
  u32 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  u32 *puVar5;
  
  puVar5 = (u32 *)((int)param_1 + DAT_007ce730);
  puVar1 = (u32 *)((u32 *)(param_2 + DAT_007ce730))[1];
  *puVar5 = *(u32 *)(param_2 + DAT_007ce730);
  if ((puVar1 != (u32 *)0x0) && ((*puVar1 & 1) == 0)) {
    iVar2 = ((code)FUN_00466260)(puVar1[1],0,0,*puVar1,*(u32 *)(puVar1[8] + 0x20));
    iVar4 = 0;
    if (0 < *(int *)(iVar2 + 4)) {
      iVar3 = 0;
      do {
        iVar4 = iVar4 + 1;
        *(u32 *)(*(int *)(iVar2 + 0x10) + iVar3 + 0xc) = 0;
        *(u32 *)(*(int *)(iVar2 + 0x10) + iVar3 + 8) = *(u32 *)(puVar1[4] + iVar3 + 8)
        ;
        *(u32 *)(*(int *)(iVar2 + 0x10) + iVar3 + 4) = *(u32 *)(puVar1[4] + iVar3 + 4)
        ;
        *(u32 *)(*(int *)(iVar2 + 0x10) + iVar3) = *(u32 *)(puVar1[4] + iVar3);
        iVar3 = iVar3 + 0x10;
      } while (iVar4 < *(int *)(iVar2 + 4));
    }
    puVar5[1] = iVar2;
    *(int *)(iVar2 + 0x14) = (int)param_1;
  }
  return param_1;
}

// FUN_00465CF0 NONMATCHING

u64 FUN_00465cf0(u64 param_1,u64 param_2,int param_3)

{
  u32 *puVar1;
  long lVar2;
  u32 uVar3;
  int iVar4;
  u32 uStack_8;
  u32 uStack_4;
  
  uStack_4 = 0x100;
  lVar2 = ((code)FUN_004c17f0)(param_1,&uStack_4,4);
  if (lVar2 == 0) {
    param_1 = 0;
  }
  else {
    param_3 = param_3 + DAT_007ce730;
    lVar2 = ((code)FUN_004c17f0)(param_1,param_3,4);
    if (lVar2 == 0) {
      param_1 = 0;
    }
    else {
      puVar1 = *(u32 **)(param_3 + 4);
      if ((puVar1 == (u32 *)0x0) || ((*puVar1 & 1) != 0)) {
        uStack_8 = 0;
        lVar2 = ((code)FUN_004c17f0)(param_1,&uStack_8,4);
        if (lVar2 == 0) {
          param_1 = 0;
        }
      }
      else {
        lVar2 = ((code)FUN_004c17f0)(param_1,puVar1 + 1,4);
        if (lVar2 == 0) {
          param_1 = 0;
        }
        else {
          lVar2 = ((code)FUN_004c17f0)(param_1,puVar1,4);
          if (lVar2 == 0) {
            param_1 = 0;
          }
          else {
            lVar2 = ((code)FUN_004c17f0)(param_1,puVar1[8] + 0x20,4);
            if (lVar2 == 0) {
              param_1 = 0;
            }
            else {
              uVar3 = puVar1[4];
              iVar4 = 0;
              if (0 < (int)puVar1[1]) {
                do {
                  lVar2 = ((code)FUN_004c17f0)(param_1,uVar3,4);
                  if (lVar2 == 0) {
                    return 0;
                  }
                  lVar2 = ((code)FUN_004c17f0)(param_1,uVar3 + 4,4);
                  if (lVar2 == 0) {
                    return 0;
                  }
                  lVar2 = ((code)FUN_004c17f0)(param_1,uVar3 + 8,4);
                  if (lVar2 == 0) {
                    return 0;
                  }
                  iVar4 = iVar4 + 1;
                  uVar3 = uVar3 + 0x10;
                } while (iVar4 < (int)puVar1[1]);
              }
            }
          }
        }
      }
    }
  }
  return param_1;
}

// FUN_00465EB0 NONMATCHING

u64 FUN_00465eb0(u64 param_1,u64 param_2,u32 param_3)

{
  u32 uVar1;
  long lVar2;
  int iVar3;
  u32 *puVar4;
  int iVar5;
  u32 uStack_10;
  u32 uStack_c;
  int iStack_8;
  u32 uStack_4;
  
  iVar3 = param_3 + DAT_007ce730;
  lVar2 = ((code)FUN_004c1910)(param_1,&iStack_8,4);
  if (lVar2 == 0) {
    param_1 = 0;
  }
  else if (iStack_8 == 0x100) {
    lVar2 = ((code)FUN_004c1910)(param_1,iVar3,4);
    if (lVar2 == 0) {
      param_1 = 0;
    }
    else {
      lVar2 = ((code)FUN_004c1910)(param_1,&uStack_4,4);
      if (lVar2 == 0) {
        param_1 = 0;
      }
      else if (0 < (int)uStack_4) {
        lVar2 = ((code)FUN_004c1910)(param_1,&uStack_c,4);
        if (lVar2 == 0) {
          param_1 = 0;
        }
        else {
          lVar2 = ((code)FUN_004c1910)(param_1,&uStack_10,4);
          if (lVar2 == 0) {
            param_1 = 0;
          }
          else {
            lVar2 = (*DAT_00960188)(DAT_007ce734,0x3011e);
            ((code)FUN_00521408)(lVar2,0,0x24);
            puVar4 = (u32 *)lVar2;
            if (lVar2 != 0) {
              uVar1 = ((code)FUN_004b6e10)(uStack_4,uStack_10);
              puVar4[8] = uVar1;
              *puVar4 = uStack_c;
              puVar4[5] = param_3;
              puVar4[1] = uStack_4;
              puVar4[6] = (u32)puVar4;
              if ((*puVar4 & 2) == 0) {
                uVar1 = (*DAT_00960178)(uStack_4 * 0x40 + 0xf,0x3011e);
                puVar4[2] = uVar1 + 0xf & 0xfffffff0;
                puVar4[3] = uVar1;
              }
              else {
                puVar4[2] = 0;
                puVar4[3] = 0;
              }
              uVar1 = (*DAT_00960178)(uStack_4 << 4,0x3011e);
              puVar4[4] = uVar1;
              uVar1 = puVar4[4];
              iVar5 = 0;
              if (0 < (int)puVar4[1]) {
                do {
                  lVar2 = ((code)FUN_004c1910)(param_1,uVar1,4);
                  if (lVar2 == 0) {
                    return 0;
                  }
                  lVar2 = ((code)FUN_004c1910)(param_1,uVar1 + 4,4);
                  if (lVar2 == 0) {
                    return 0;
                  }
                  lVar2 = ((code)FUN_004c1910)(param_1,uVar1 + 8,4);
                  if (lVar2 == 0) {
                    return 0;
                  }
                  *(u32 *)(uVar1 + 0xc) = 0;
                  iVar5 = iVar5 + 1;
                  uVar1 = uVar1 + 0x10;
                } while (iVar5 < (int)puVar4[1]);
              }
            }
            *(u32 **)(iVar3 + 4) = puVar4;
          }
        }
      }
    }
  }
  else {
    param_1 = 0;
  }
  return param_1;
}

// FUN_004661B0 NONMATCHING

u8 FUN_004661b0(void)

{
  u8 bVar1;
  long lVar2;
  
  lVar2 = ((code)FUN_004ca520)(0,0x11e,0x465a00,0x465ae0);
  if (lVar2 < 0) {
    bVar1 = 0;
  }
  else {
    DAT_007ce730 = ((code)FUN_004cb9f0)(8,0x11e,0x465b20,0x465b40,0x465bf0);
    lVar2 = ((code)FUN_004c7d00)(0x11e,0x465eb0,0x465cf0,0x466130);
    bVar1 = 0;
    if (-1 < lVar2) {
      bVar1 = -1 < DAT_007ce730;
    }
  }
  return bVar1;
}

// FUN_00466260 NONMATCHING

u64
FUN_00466260(u32 param_1,u32 *param_2,u32 *param_3,u32 param_4,u64 param_5)

{
  u32 uVar1;
  u64 uVar2;
  u32 *puVar3;
  u32 *puVar4;
  int iVar5;
  int iVar6;
  u32 *puVar7;
  
  uVar2 = (*DAT_00960188)(DAT_007ce734,0x3011e);
  uVar1 = ((code)FUN_004b6e10)(param_1,param_5);
  puVar7 = (u32 *)uVar2;
  puVar7[8] = uVar1;
  *puVar7 = param_4;
  puVar7[1] = param_1;
  puVar7[5] = 0;
  if ((param_4 & 2) == 0) {
    uVar1 = (*DAT_00960178)(param_1 * 0x40 + 0xf,0x3011e);
    puVar7[2] = uVar1 + 0xf & 0xfffffff0;
    puVar7[3] = uVar1;
  }
  else {
    puVar7[2] = 0;
    puVar7[3] = 0;
  }
  uVar1 = (*DAT_00960178)(param_1 << 4,0x3011e);
  puVar7[4] = uVar1;
  iVar6 = 0;
  if (0 < (int)param_1) {
    iVar5 = 0;
    puVar3 = param_2;
    puVar4 = param_3;
    do {
      *(u32 *)(puVar7[4] + iVar5 + 0xc) = 0;
      if (param_3 != (u32 *)0x0) {
        *(u32 *)(puVar7[4] + iVar5) = *puVar4;
      }
      *(int *)(puVar7[4] + iVar5 + 4) = iVar6;
      if (param_2 != (u32 *)0x0) {
        *(u32 *)(puVar7[4] + iVar5 + 8) = *puVar3;
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 0x10;
      puVar4 = puVar4 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar6 < (int)param_1);
  }
  puVar7[6] = (u32)puVar7;
  return uVar2;
}

// FUN_004663D0 NONMATCHING

u64 FUN_004663d0(u64 param_1)

{
  u32 uVar1;
  u32 *puVar2;
  
  puVar2 = (u32 *)param_1;
  uVar1 = puVar2[5];
  if ((*puVar2 & 1) == 0) {
    if ((*puVar2 & 2) == 0) {
      (*DAT_0096017c)(puVar2[3]);
    }
    (*DAT_0096017c)(puVar2[4]);
  }
  puVar2[3] = 0;
  puVar2[2] = 0;
  puVar2[4] = 0;
  ((code)FUN_004b6eb0)(puVar2[8]);
  (*DAT_0096018c)(DAT_007ce734,param_1);
  if (uVar1 != 0) {
    *(u32 *)(uVar1 + DAT_007ce730 + 4) = 0;
  }
  return 0;
}

// FUN_00466480 NONMATCHING

u64 FUN_00466480(u32 param_1,int param_2,u32 param_3,u64 param_4)

{
  u8 bVar1;
  u32 *puVar2;
  u64 uVar3;
  int iVar4;
  int iVar5;
  u32 uVar6;
  u32 *puVar7;
  int iVar8;
  u32 uVar9;
  u32 auStack_80 [32];
  
  uVar9 = 1;
  iVar8 = param_2 * 0x10;
  iVar4 = *(int *)(param_1 + 0x10) + iVar8;
  bVar1 = (*(u32 *)(iVar4 + 8) & 1) == 0;
  if (bVar1) {
    iVar4 = iVar4 + 0x10;
  }
  uVar6 = (u32)bVar1;
  while (uVar6 != 0) {
    if ((*(u32 *)(iVar4 + 8) & 2) != 0) {
      uVar6 = uVar6 + 1;
    }
    if ((*(u32 *)(iVar4 + 8) & 1) != 0) {
      uVar6 = uVar6 - 1;
    }
    uVar9 = uVar9 + 1;
    iVar4 = iVar4 + 0x10;
  }
  uVar3 = (*DAT_00960188)(DAT_007ce734,0x3011e);
  puVar2 = (u32 *)uVar3;
  *puVar2 = param_3 | 1;
  puVar2[1] = uVar9;
  uVar9 = ((code)FUN_004b75d0)(*(u32 *)(param_1 + 0x20),param_2,uVar9,param_4);
  puVar2[8] = uVar9;
  if (param_2 == 0) {
    puVar2[7] = 0xffffffff;
  }
  else {
    puVar7 = auStack_80;
    uVar9 = 0xffffffff;
    uVar6 = 0;
    if (0 < param_2) {
      iVar4 = *(int *)(param_1 + 0x10);
      iVar5 = 0;
      uVar9 = 0xffffffff;
      do {
        if ((*(u32 *)(iVar4 + iVar5 + 8) & 2) != 0) {
          *puVar7 = uVar9;
          puVar7 = puVar7 + 1;
        }
        uVar9 = uVar6;
        if ((*(u32 *)(*(int *)(param_1 + 0x10) + iVar5 + 8) & 1) != 0) {
          puVar7 = puVar7 + -1;
          uVar9 = *puVar7;
        }
        uVar6 = uVar6 + 1;
        iVar5 = iVar5 + 0x10;
      } while ((int)uVar6 < param_2);
    }
    puVar2[7] = uVar9;
  }
  puVar2[5] = *(u32 *)(iVar8 + *(int *)(param_1 + 0x10) + 0xc);
  puVar2[2] = *(int *)(param_1 + 8) + param_2 * 0x40;
  puVar2[3] = 0;
  puVar2[4] = *(int *)(param_1 + 0x10) + iVar8;
  puVar2[6] = param_1;
  return uVar3;
}

// FUN_00466640 NONMATCHING

u64 FUN_00466640(u64 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  iVar4 = (int)param_1;
  iVar1 = *(int *)(iVar4 + 0x14);
  iVar6 = 0;
  if (0 < *(int *)(iVar4 + 4)) {
    iVar5 = 0;
    do {
      piVar7 = (int *)(*(int *)(iVar4 + 0x10) + iVar5);
      iVar2 = *piVar7;
      iVar3 = ((code)FUN_00466720)(iVar1);
      if (iVar2 == iVar3) {
        piVar7[3] = iVar1;
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 0x10;
    } while (iVar6 < *(int *)(iVar4 + 4));
  }
  ((code)FUN_004cb270)(iVar1);
  ((code)FUN_004cb6e0)(iVar1,0x465930,param_1);
  return param_1;
}

// FUN_00466710

#pragma optimization_level 3
u32 FUN_00466710(int param_1)
{
  return *(u32 *)(param_1 + iGpffffba40 + 4);
}
#pragma optimization_level 2

// FUN_00466720

#pragma optimization_level 3
u32 FUN_00466720(int param_1)
{
  return *(u32 *)(param_1 + iGpffffba40);
}
#pragma optimization_level 2

// FUN_00466730 NONMATCHING

u32 FUN_00466730(u32 *param_1)

{
  u32 uVar1;
  code *pcVar2;
  u32 *puVar3;
  long lVar4;
  u32 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  float *pfVar10;
  u32 *puVar11;
  u32 *puVar12;
  float *pfVar13;
  u32 uVar14;
  u32 uVar15;
  int iVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  u32 auStack_900 [5];
  u32 uStack_8ec;
  u32 uStack_8e8;
  u32 uStack_8e4;
  u32 uStack_8e0;
  u32 uStack_8dc;
  u32 uStack_8d8;
  u32 uStack_8d4;
  u32 uStack_8d0;
  u32 uStack_8cc;
  u32 uStack_8c8;
  u32 uStack_8c4;
  float fStack_8c0;
  float fStack_8bc;
  float fStack_8b8;
  u32 uStack_8b4;
  float fStack_8b0;
  float fStack_8ac;
  float fStack_8a8;
  float fStack_8a0;
  float fStack_89c;
  float fStack_898;
  u32 uStack_890;
  u32 uStack_88c;
  u32 uStack_888;
  u32 auStack_880 [16];
  u32 auStack_840 [8];
  u32 uStack_820;
  u32 uStack_81c;
  u32 uStack_818;
  u32 uStack_814;
  u32 uStack_810;
  u32 uStack_80c;
  u32 uStack_808;
  u32 uStack_804;
  u32 auStack_7c0 [496];
  
  uVar1 = *param_1;
  iVar9 = *(int *)(param_1[5] + 4);
  if (iVar9 == 0) {
    uStack_818 = 0x3f800000;
    auStack_840[5] = 0x3f800000;
    auStack_840[0] = 0x3f800000;
    auStack_840[4] = 0;
    auStack_840[2] = 0;
    auStack_840[1] = 0;
    uStack_81c = 0;
    uStack_820 = 0;
    auStack_840[3] = auStack_840[3] | 0x20003;
    auStack_840[6] = 0;
    uStack_808 = 0;
    uStack_80c = 0;
    uStack_810 = 0;
  }
  else {
    lVar4 = ((code)FUN_004cae30)(iVar9);
    if (lVar4 == 0) {
      puVar3 = (u32 *)((code)FUN_004cb2f0)(iVar9);
      puVar11 = auStack_840;
      iVar9 = 8;
      do {
        iVar9 = iVar9 + -1;
        uVar15 = puVar3[1];
        *puVar11 = *puVar3;
        puVar3 = puVar3 + 2;
        puVar11[1] = uVar15;
        puVar11 = puVar11 + 2;
      } while (0 < iVar9);
    }
    else {
      puVar11 = (u32 *)(iVar9 + 0x10);
      puVar3 = auStack_840;
      iVar6 = 8;
      do {
        iVar6 = iVar6 + -1;
        uVar15 = puVar11[1];
        *puVar3 = *puVar11;
        puVar11 = puVar11 + 2;
        puVar3[1] = uVar15;
        puVar3 = puVar3 + 2;
      } while (0 < iVar6);
      for (iVar9 = *(int *)(iVar9 + 4); iVar9 != 0; iVar9 = *(int *)(iVar9 + 4)) {
        ((code)FUN_004c2f30)(auStack_840,auStack_880,iVar9 + 0x10);
      }
    }
  }
  uVar15 = uVar1 & 0x2000;
  if ((uVar15 != 0) && ((*(u8 *)(*(int *)(param_1[5] + 0xa0) + 3) & 3) == 0)) {
    *(int *)(*(int *)(param_1[5] + 0xa0) + 8) = DAT_0096012c;
    *(int **)(*(int *)(param_1[5] + 0xa0) + 0xc) = (int *)DAT_0096012c;
    *(int *)(DAT_0096012c + 4) = *(int *)(param_1[5] + 0xa0) + 8;
    DAT_0096012c = *(int *)(param_1[5] + 0xa0) + 8;
    *(u8 *)(*(int *)(param_1[5] + 0xa0) + 3) = *(u8 *)(*(int *)(param_1[5] + 0xa0) + 3) | 2;
  }
  uVar5 = param_1[8];
  puVar3 = auStack_7c0;
  iVar16 = 0;
  uVar14 = param_1[4];
  pcVar2 = *(code **)(uVar5 + 0x3c);
  iVar6 = uVar5 + 0x4c;
  iVar9 = *(int *)(uVar5 + 0x24);
  if (0 < (int)param_1[1]) {
    do {
      if (pcVar2 == (code *)&LAB_00464760) {
        fVar20 = *(float *)(iVar6 + 8);
        fVar19 = *(float *)(iVar6 + 0xc);
        fVar18 = *(float *)(iVar6 + 0x10);
        fVar17 = *(float *)(iVar6 + 0x14);
        uStack_8b4 = 3;
        fStack_8bc = (fVar20 * fVar19 + fVar17 * fVar18) * 2.0;
        fStack_8b0 = (fVar20 * fVar19 - fVar17 * fVar18) * 2.0;
        fStack_8c0 = 1.0 - (fVar19 * fVar19 + fVar18 * fVar18) * 2.0;
        fStack_8ac = 1.0 - (fVar20 * fVar20 + fVar18 * fVar18) * 2.0;
        fStack_898 = 1.0 - (fVar20 * fVar20 + fVar19 * fVar19) * 2.0;
        fStack_8b8 = (fVar18 * fVar20 - fVar17 * fVar19) * 2.0;
        fStack_8a0 = (fVar18 * fVar20 + fVar17 * fVar19) * 2.0;
        fStack_8a8 = (fVar19 * fVar18 + fVar17 * fVar20) * 2.0;
        fStack_89c = (fVar19 * fVar18 - fVar17 * fVar20) * 2.0;
        uStack_890 = *(u32 *)(iVar6 + 0x18);
        uStack_88c = *(u32 *)(iVar6 + 0x1c);
        uStack_888 = *(u32 *)(iVar6 + 0x20);
      }
      else {
        (*pcVar2)(&fStack_8c0,iVar6);
      }
      ((code)FUN_004c2f30)(auStack_900,&fStack_8c0,auStack_840);
      iVar8 = *(int *)(uVar14 + 0xc);
      if (iVar8 != 0) {
        if ((uVar1 & 0x1000) != 0) {
          pfVar13 = &fStack_8c0;
          pfVar10 = (float *)(iVar8 + 0x10);
          iVar7 = 8;
          do {
            iVar7 = iVar7 + -1;
            fVar17 = pfVar13[1];
            *pfVar10 = *pfVar13;
            pfVar13 = pfVar13 + 2;
            pfVar10[1] = fVar17;
            pfVar10 = pfVar10 + 2;
          } while (0 < iVar7);
          if (uVar15 == 0) {
            ((code)FUN_004cb270)(iVar8);
          }
        }
        if (uVar15 != 0) {
          puVar12 = auStack_900;
          puVar11 = (u32 *)(iVar8 + 0x50);
          iVar7 = 8;
          do {
            iVar7 = iVar7 + -1;
            uVar5 = puVar12[1];
            *puVar11 = *puVar12;
            puVar12 = puVar12 + 2;
            puVar11[1] = uVar5;
            puVar11 = puVar11 + 2;
          } while (0 < iVar7);
          *(u8 *)(iVar8 + 3) = *(u8 *)(iVar8 + 3) & 0xfb | 8;
        }
      }
      uVar5 = *(u32 *)(uVar14 + 8) & 3;
      if (uVar5 != 3) {
        if (uVar5 == 2) {
          puVar12 = auStack_840;
          iVar8 = 8;
          puVar11 = puVar3;
          do {
            iVar8 = iVar8 + -1;
            uVar5 = puVar12[1];
            *puVar11 = *puVar12;
            puVar11[1] = uVar5;
            puVar12 = puVar12 + 2;
            puVar11 = puVar11 + 2;
          } while (0 < iVar8);
          puVar3 = puVar3 + 0x10;
          auStack_840[0] = auStack_900[0];
          auStack_840[1] = auStack_900[1];
          auStack_840[2] = auStack_900[2];
          auStack_840[3] = auStack_900[3];
          auStack_840[4] = auStack_900[4];
          auStack_840[7] = uStack_8e4;
          auStack_840[5] = uStack_8ec;
          uStack_814 = uStack_8d4;
          auStack_840[6] = uStack_8e8;
          uStack_804 = uStack_8c4;
          uStack_820 = uStack_8e0;
          uStack_81c = uStack_8dc;
          uStack_818 = uStack_8d8;
          uStack_810 = uStack_8d0;
          uStack_80c = uStack_8cc;
          uStack_808 = uStack_8c8;
        }
        else if (uVar5 == 1) {
          puVar3 = puVar3 + -0x10;
          puVar12 = auStack_840;
          iVar8 = 8;
          puVar11 = puVar3;
          do {
            iVar8 = iVar8 + -1;
            uVar5 = puVar11[1];
            *puVar12 = *puVar11;
            puVar12[1] = uVar5;
            puVar11 = puVar11 + 2;
            puVar12 = puVar12 + 2;
          } while (0 < iVar8);
        }
        else if (uVar5 == 0) {
          auStack_840[0] = auStack_900[0];
          auStack_840[1] = auStack_900[1];
          auStack_840[3] = auStack_900[3];
          auStack_840[2] = auStack_900[2];
          auStack_840[7] = uStack_8e4;
          auStack_840[4] = auStack_900[4];
          uStack_814 = uStack_8d4;
          auStack_840[5] = uStack_8ec;
          uStack_804 = uStack_8c4;
          auStack_840[6] = uStack_8e8;
          uStack_820 = uStack_8e0;
          uStack_81c = uStack_8dc;
          uStack_818 = uStack_8d8;
          uStack_810 = uStack_8d0;
          uStack_80c = uStack_8cc;
          uStack_808 = uStack_8c8;
        }
      }
      iVar16 = iVar16 + 1;
      iVar6 = iVar6 + iVar9;
      uVar14 = uVar14 + 0x10;
    } while (iVar16 < (int)param_1[1]);
  }
  return 1;
}

// FUN_00466EF0 NONMATCHING

u64 FUN_00466ef0(u32 *param_1)

{
  u8 bVar1;
  u32 uVar2;
  code *pcVar3;
  int iVar4;
  u32 *puVar5;
  long lVar6;
  u64 uVar7;
  u32 uVar8;
  int iVar9;
  int iVar10;
  u32 *puVar11;
  int iVar12;
  float *pfVar13;
  u32 *puVar14;
  u32 *puVar15;
  float *pfVar16;
  u8 bVar17;
  u32 uVar18;
  u32 *puVar19;
  u32 uVar20;
  int iVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fStack_180;
  float fStack_17c;
  float fStack_178;
  u32 uStack_174;
  float fStack_170;
  float fStack_16c;
  float fStack_168;
  float fStack_160;
  float fStack_15c;
  float fStack_158;
  u32 uStack_150;
  u32 uStack_14c;
  u32 uStack_148;
  u32 auStack_140 [17];
  u32 auStack_fc [31];
  u32 uStack_80;
  u32 uStack_7c;
  u32 uStack_78;
  u32 uStack_74;
  u32 uStack_70;
  u32 uStack_6c;
  u32 uStack_68;
  u32 uStack_60;
  u32 uStack_5c;
  u32 uStack_58;
  u32 uStack_50;
  u32 uStack_4c;
  u32 uStack_48;
  u32 auStack_40 [8];
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  bVar17 = 0;
  uVar18 = 0;
  uVar2 = *param_1;
  if ((uVar2 & 2) == 0) {
    if (((uVar2 & 1) == 0) || (param_1[7] == 0xffffffff)) {
      if ((uVar2 & 0x4000) == 0) {
        uVar18 = param_1[5];
        bVar17 = 1;
        puVar19 = auStack_40;
      }
      else {
        uStack_58 = 0x3f800000;
        uStack_6c = 0x3f800000;
        uStack_80 = 0x3f800000;
        puVar19 = &uStack_80;
        uStack_70 = 0;
        uStack_78 = 0;
        uStack_7c = 0;
        uStack_5c = 0;
        uStack_60 = 0;
        uStack_74 = uStack_74 | 0x20003;
        uStack_68 = 0;
        uStack_48 = 0;
        uStack_4c = 0;
        uStack_50 = 0;
        if ((uVar2 & 0x2000) != 0) {
          uVar18 = param_1[5];
          bVar17 = 1;
        }
      }
    }
    else {
      puVar19 = (u32 *)(*(int *)(param_1[6] + 8) + param_1[7] * 0x40);
      if (((uVar2 & 0x2000) != 0) && ((uVar2 & 0x4000) != 0)) {
        uVar18 = *(u32 *)(param_1[6] + 0x14);
        bVar17 = 1;
      }
    }
    if (bVar17) {
      if ((uVar18 == 0) || (iVar12 = *(int *)(uVar18 + 4), iVar12 == 0)) {
        uStack_18 = 0x3f800000;
        auStack_40[5] = 0x3f800000;
        auStack_40[0] = 0x3f800000;
        auStack_40[4] = 0;
        auStack_40[2] = 0;
        auStack_40[1] = 0;
        uStack_1c = 0;
        uStack_20 = 0;
        auStack_40[3] = auStack_40[3] | 0x20003;
        auStack_40[6] = 0;
        uStack_8 = 0;
        uStack_c = 0;
        uStack_10 = 0;
      }
      else {
        lVar6 = ((code)FUN_004cae30)(iVar12);
        if (lVar6 == 0) {
          puVar5 = (u32 *)((code)FUN_004cb2f0)(iVar12);
          puVar14 = auStack_40;
          iVar12 = 8;
          do {
            iVar12 = iVar12 + -1;
            uVar18 = puVar5[1];
            *puVar14 = *puVar5;
            puVar5 = puVar5 + 2;
            puVar14[1] = uVar18;
            puVar14 = puVar14 + 2;
          } while (0 < iVar12);
        }
        else {
          puVar14 = (u32 *)(iVar12 + 0x10);
          puVar5 = auStack_40;
          iVar9 = 8;
          do {
            iVar9 = iVar9 + -1;
            uVar18 = puVar14[1];
            *puVar5 = *puVar14;
            puVar14 = puVar14 + 2;
            puVar5[1] = uVar18;
            puVar5 = puVar5 + 2;
          } while (0 < iVar9);
          for (iVar12 = *(int *)(iVar12 + 4); iVar12 != 0; iVar12 = *(int *)(iVar12 + 4)) {
            ((code)FUN_004c2f30)(auStack_40,auStack_140,iVar12 + 0x10);
          }
        }
      }
    }
    uVar18 = uVar2 & 0x2000;
    if ((uVar18 != 0) && ((*(u8 *)(*(int *)(param_1[5] + 0xa0) + 3) & 3) == 0)) {
      *(int *)(*(int *)(param_1[5] + 0xa0) + 8) = DAT_0096012c;
      *(int **)(*(int *)(param_1[5] + 0xa0) + 0xc) = (int *)DAT_0096012c;
      *(int *)(DAT_0096012c + 4) = *(int *)(param_1[5] + 0xa0) + 8;
      DAT_0096012c = *(int *)(param_1[5] + 0xa0) + 8;
      *(u8 *)(*(int *)(param_1[5] + 0xa0) + 3) = *(u8 *)(*(int *)(param_1[5] + 0xa0) + 3) | 2;
    }
    uVar8 = param_1[8];
    puVar14 = auStack_fc;
    iVar21 = 0;
    uVar20 = param_1[4];
    puVar5 = (u32 *)param_1[2];
    pcVar3 = *(code **)(uVar8 + 0x3c);
    iVar9 = uVar8 + 0x4c;
    iVar12 = *(int *)(uVar8 + 0x24);
    if (0 < (int)param_1[1]) {
      do {
        if (pcVar3 == (code *)&LAB_00464760) {
          fVar25 = *(float *)(iVar9 + 8);
          fVar24 = *(float *)(iVar9 + 0xc);
          fVar23 = *(float *)(iVar9 + 0x10);
          fVar22 = *(float *)(iVar9 + 0x14);
          uStack_174 = 3;
          fStack_17c = (fVar25 * fVar24 + fVar22 * fVar23) * 2.0;
          fStack_170 = (fVar25 * fVar24 - fVar22 * fVar23) * 2.0;
          fStack_180 = 1.0 - (fVar24 * fVar24 + fVar23 * fVar23) * 2.0;
          fStack_16c = 1.0 - (fVar25 * fVar25 + fVar23 * fVar23) * 2.0;
          fStack_158 = 1.0 - (fVar25 * fVar25 + fVar24 * fVar24) * 2.0;
          fStack_178 = (fVar23 * fVar25 - fVar22 * fVar24) * 2.0;
          fStack_160 = (fVar23 * fVar25 + fVar22 * fVar24) * 2.0;
          fStack_168 = (fVar24 * fVar23 + fVar22 * fVar25) * 2.0;
          fStack_15c = (fVar24 * fVar23 - fVar22 * fVar25) * 2.0;
          uStack_150 = *(u32 *)(iVar9 + 0x18);
          uStack_14c = *(u32 *)(iVar9 + 0x1c);
          uStack_148 = *(u32 *)(iVar9 + 0x20);
        }
        else {
          (*pcVar3)(&fStack_180,iVar9);
        }
        ((code)FUN_004c2f30)(puVar5,&fStack_180,puVar19);
        iVar4 = *(int *)(uVar20 + 0xc);
        if (iVar4 != 0) {
          if ((uVar2 & 0x1000) != 0) {
            pfVar16 = &fStack_180;
            pfVar13 = (float *)(iVar4 + 0x10);
            iVar10 = 8;
            do {
              iVar10 = iVar10 + -1;
              fVar22 = pfVar16[1];
              *pfVar13 = *pfVar16;
              pfVar16 = pfVar16 + 2;
              pfVar13[1] = fVar22;
              pfVar13 = pfVar13 + 2;
            } while (0 < iVar10);
            if (uVar18 == 0) {
              ((code)FUN_004cb270)(iVar4);
            }
          }
          if (uVar18 != 0) {
            if ((uVar2 & 0x4000) == 0) {
              puVar11 = (u32 *)(iVar4 + 0x50);
              iVar10 = 8;
              puVar15 = puVar5;
              do {
                iVar10 = iVar10 + -1;
                uVar8 = puVar15[1];
                *puVar11 = *puVar15;
                puVar15 = puVar15 + 2;
                puVar11[1] = uVar8;
                puVar11 = puVar11 + 2;
              } while (0 < iVar10);
              bVar1 = *(u8 *)(iVar4 + 3);
            }
            else {
              ((code)FUN_004c2f30)(iVar4 + 0x50,puVar5,auStack_40);
              bVar1 = *(u8 *)(iVar4 + 3);
            }
            *(u8 *)(iVar4 + 3) = bVar1 & 0xfb | 8;
          }
        }
        uVar8 = *(u32 *)(uVar20 + 8) & 3;
        if (uVar8 != 3) {
          if (uVar8 == 2) {
            *puVar14 = (u32)puVar19;
            puVar14 = puVar14 + 1;
            puVar19 = puVar5;
          }
          else if (uVar8 == 1) {
            puVar14 = puVar14 + -1;
            puVar19 = (u32 *)*puVar14;
          }
          else if (uVar8 == 0) {
            puVar19 = puVar5;
          }
        }
        iVar21 = iVar21 + 1;
        puVar5 = puVar5 + 0x10;
        iVar9 = iVar9 + iVar12;
        uVar20 = uVar20 + 0x10;
      } while (iVar21 < (int)param_1[1]);
    }
    uVar7 = 1;
  }
  else {
    uVar7 = ((code)FUN_00466730)();
  }
  return uVar7;
}

// FUN_00467590 NONMATCHING

u64 FUN_00467590(u64 param_1)

{
  DAT_0095c3fc = DAT_0095c3fc + -1;
  if (DAT_0095c3fc == 0) {
    ((code)FUN_00469cf0)();
  }
  if (DAT_0095c400 != 0) {
    ((code)FUN_004c3c30)();
    DAT_0095c400 = 0;
  }
  return param_1;
}

// FUN_00467600 NONMATCHING

u64 FUN_00467600(u64 param_1)

{
  long lVar1;
  
  if (DAT_0095c3fc == 0) {
    lVar1 = thunk_FUN_004c3970(0x90,DAT_007cdb20,0x10,DAT_007cdb24,0x95c410,0x40120);
    DAT_0095c400 = (u32)lVar1;
    if (lVar1 == 0) {
      return 0;
    }
    lVar1 = ((code)FUN_00469ce0)();
    if (lVar1 == 0) {
      return 0;
    }
  }
  DAT_0095c3fc = DAT_0095c3fc + 1;
  return param_1;
}

// FUN_004676C0 NONMATCHING

u64 FUN_004676c0(u64 param_1)

{
  int iVar1;
  int *piVar2;
  u32 uVar3;
  
  uVar3 = 0;
  do {
    piVar2 = (int *)((int)param_1 + uVar3 * 0x40);
    iVar1 = piVar2[8];
    if (iVar1 == 5) {
      *piVar2 = 0;
      piVar2[1] = 0;
    }
    else if (iVar1 == 4) {
      if (*piVar2 != 0) {
        ((code)FUN_004d0f00)();
      }
    }
    else if (iVar1 == 2) {
      if (piVar2[1] != 0) {
        ((code)FUN_004d0f00)();
      }
    }
    else if (iVar1 == 1) {
      if (piVar2[1] != 0) {
        ((code)FUN_004d0f00)();
      }
      if (piVar2[2] != 0) {
        ((code)FUN_004d0f00)();
      }
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 2);
  ((code)FUN_00521408)(param_1,0,0x90);
  return param_1;
}

// FUN_004677F0 NONMATCHING

u64 FUN_004677f0(u64 param_1)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + DAT_007ce738);
  if (iVar1 != 0) {
    ((code)FUN_004676c0)(iVar1);
    (*DAT_0096018c)(DAT_0095c400,iVar1);
    *(u32 *)((int)param_1 + DAT_007ce738) = 0;
  }
  return param_1;
}

// FUN_00467860 NONMATCHING

u64 FUN_00467860(u64 param_1,u64 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  u64 uVar4;
  long lVar5;
  u64 uVar6;
  u64 uVar7;
  int iVar8;
  int iVar9;
  u32 uVar10;
  u32 uVar11;
  u32 auStack_20 [4];
  u32 auStack_10 [2];
  u32 uStack_8;
  u32 uStack_4;
  
  iVar1 = *(int *)((int)param_2 + DAT_007ce738);
  if (iVar1 == 0) {
    param_1 = 0;
  }
  else {
    iVar3 = *(int *)((int)param_1 + DAT_007ce738);
    if (iVar3 == 0) {
      iVar3 = (*DAT_00960188)(DAT_0095c400,0x30120);
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        ((code)FUN_00521408)(iVar3,0,0x90);
        *(int *)((int)param_1 + DAT_007ce738) = iVar3;
      }
    }
    if (iVar3 == 0) {
      param_1 = 0;
    }
    else {
      ((code)FUN_00468ea0)(param_1,*(u32 *)(iVar1 + 0x80));
      uVar10 = 0;
      uVar7 = param_1;
      do {
        iVar9 = iVar1 + uVar10 * 0x40;
        iVar2 = *(int *)(iVar9 + 0x20);
        if (iVar2 == 5) {
          param_2 = ((code)FUN_00469a10)(param_2,auStack_10,auStack_20);
          uVar7 = ((code)FUN_004699b0)(uVar7,auStack_10[0],auStack_20[0]);
        }
        else if (iVar2 == 4) {
          lVar5 = ((code)FUN_004698e0)(param_2);
          ((code)FUN_00469940)(param_2,&uStack_4,&uStack_8);
          if (lVar5 != 0) {
            ((code)FUN_00469770)(uVar7,lVar5);
          }
          ((code)FUN_00469840)(uVar7,uStack_4,uStack_8);
        }
        else if (iVar2 == 2) {
          lVar5 = ((code)FUN_004695f0)(param_2);
          uVar4 = ((code)FUN_00469650)(param_2);
          uVar11 = ((code)FUN_00469710)(param_2);
          uVar6 = ((code)FUN_004696b0)(param_2);
          if (lVar5 != 0) {
            ((code)FUN_00469400)(uVar7,lVar5);
          }
          ((code)FUN_004694b0)(uVar7,uVar4);
          ((code)FUN_00469510)(uVar7,uVar6);
          ((code)FUN_00469590)(uVar11,uVar7);
        }
        else if (iVar2 == 1) {
          iVar8 = iVar3 + uVar10 * 0x40;
          uVar4 = ((code)FUN_00469340)(param_2);
          uVar11 = ((code)FUN_004693a0)(param_2);
          ((code)FUN_00469280)(uVar7,uVar4);
          ((code)FUN_004692e0)(uVar11,uVar7);
          *(u32 *)(iVar8 + 4) = *(u32 *)(iVar9 + 4);
          *(u32 *)(iVar8 + 8) = *(u32 *)(iVar9 + 8);
          iVar2 = *(int *)(iVar8 + 4);
          if (iVar2 != 0) {
            *(int *)(iVar2 + 0x54) = *(int *)(iVar2 + 0x54) + 1;
          }
          iVar2 = *(int *)(iVar8 + 8);
          if (iVar2 != 0) {
            *(int *)(iVar2 + 0x54) = *(int *)(iVar2 + 0x54) + 1;
          }
        }
        uVar10 = uVar10 + 1 & 0xff;
      } while (uVar10 < 2);
    }
  }
  return param_1;
}

// FUN_00467B40 NONMATCHING

u64 FUN_00467b40(u64 param_1,int *param_2)

{
  int iVar1;
  long lVar2;
  u8 auStack_10 [4];
  int iStack_c;
  int iStack_4;
  
  lVar2 = ((code)FUN_004c1910)(param_1,&iStack_4,4);
  if (lVar2 == 0) {
    param_1 = 0;
  }
  else if (iStack_4 == 0) {
    *param_2 = 0;
  }
  else {
    lVar2 = ((code)FUN_004c1600)(param_1,6,0,0);
    if (lVar2 == 0) {
      param_1 = 0;
    }
    else {
      ((code)FUN_004c1cd0)(auStack_10);
      iVar1 = ((code)FUN_004c83c0)(param_1);
      *param_2 = iVar1;
      if (((*param_2 == 0) && (((code)FUN_004c1cd0)(auStack_10), iStack_c != -0x80000000)) &&
         (iStack_c != 0x16)) {
        ((code)FUN_004c1c50)(auStack_10);
        param_1 = 0;
      }
    }
  }
  return param_1;
}

// FUN_00467C20 NONMATCHING

long FUN_00467c20(long param_1,u64 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  int iVar5;
  int *piVar6;
  u32 uVar7;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  float fStack_c;
  int iStack_8;
  int iStack_4;
  
  iVar1 = *(int *)(param_3 + DAT_007ce738);
  iStack_4 = *(int *)(iVar1 + 0x80);
  lVar3 = ((code)FUN_004c17f0)(param_1,&iStack_4,4);
  if (lVar3 == 0) {
    param_1 = 0;
  }
  else {
    uVar7 = 0;
    do {
      iVar5 = uVar7 * 0x40;
      iStack_8 = *(int *)(iVar1 + iVar5 + 0x20);
      lVar3 = ((code)FUN_004c17f0)(param_1,&iStack_8,4);
      if (lVar3 == 0) {
        return 0;
      }
      if (iStack_8 == 4) {
        piVar6 = (int *)(iVar1 + iVar5);
        iStack_4 = piVar6[1];
        lVar3 = ((code)FUN_004c17f0)(param_1,&iStack_4);
        if (lVar3 == 0) {
          return 0;
        }
        iStack_4 = piVar6[2];
        lVar3 = ((code)FUN_004c17f0)(param_1,&iStack_4,4);
        if (lVar3 == 0) {
          return 0;
        }
        iVar5 = *piVar6;
        uStack_1c = (u32)(iVar5 != 0);
        lVar3 = ((code)FUN_004c17f0)(param_1,&uStack_1c,4);
        if (lVar3 == 0) {
          lVar3 = 0;
        }
        else {
          lVar3 = param_1;
          if ((uStack_1c != 0) && (lVar4 = ((code)FUN_004c8240)(iVar5,param_1), lVar4 == 0)) {
            lVar3 = 0;
          }
        }
        if (lVar3 == 0) {
          return 0;
        }
      }
      else if (iStack_8 == 2) {
        iVar5 = iVar1 + iVar5;
        lVar3 = ((code)FUN_004c1750)(param_1,iVar5 + 8);
        if (lVar3 == 0) {
          return 0;
        }
        iStack_4 = *(int *)(iVar5 + 0xc);
        lVar3 = ((code)FUN_004c17f0)(param_1,&iStack_4,4);
        if (lVar3 == 0) {
          return 0;
        }
        iVar5 = *(int *)(iVar5 + 4);
        uStack_18 = (u32)(iVar5 != 0);
        lVar3 = ((code)FUN_004c17f0)(param_1,&uStack_18,4);
        if (lVar3 == 0) {
          lVar3 = 0;
        }
        else {
          lVar3 = param_1;
          if ((uStack_18 != 0) && (lVar4 = ((code)FUN_004c8240)(iVar5,param_1), lVar4 == 0)) {
            lVar3 = 0;
          }
        }
        if (lVar3 == 0) {
          return 0;
        }
      }
      else if (iStack_8 == 1) {
        iVar5 = iVar1 + iVar5;
        fStack_c = -*(float *)(iVar5 + 0xc);
        lVar3 = ((code)FUN_004c1750)(param_1,&fStack_c);
        if (lVar3 == 0) {
          return 0;
        }
        iVar2 = *(int *)(iVar5 + 4);
        uStack_10 = (u32)(iVar2 != 0);
        lVar3 = ((code)FUN_004c17f0)(param_1,&uStack_10,4);
        if (lVar3 == 0) {
          lVar3 = 0;
        }
        else {
          lVar3 = param_1;
          if ((uStack_10 != 0) && (lVar4 = ((code)FUN_004c8240)(iVar2,param_1), lVar4 == 0)) {
            lVar3 = 0;
          }
        }
        if (lVar3 == 0) {
          return 0;
        }
        iVar5 = *(int *)(iVar5 + 8);
        uStack_14 = (u32)(iVar5 != 0);
        lVar3 = ((code)FUN_004c17f0)(param_1,&uStack_14,4);
        if (lVar3 == 0) {
          lVar3 = 0;
        }
        else {
          lVar3 = param_1;
          if ((uStack_14 != 0) && (lVar4 = ((code)FUN_004c8240)(iVar5,param_1), lVar4 == 0)) {
            lVar3 = 0;
          }
        }
        if (lVar3 == 0) {
          return 0;
        }
      }
      uVar7 = uVar7 + 1 & 0xff;
    } while (uVar7 < 2);
  }
  return param_1;
}

// FUN_00467FD0 NONMATCHING

u64 FUN_00467fd0(u64 param_1,u64 param_2,u64 param_3)

{
  int iVar1;
  long lVar2;
  int iVar3;
  u32 uVar4;
  u32 uStack_30;
  u32 uStack_2c;
  int iStack_24;
  int iStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  int iStack_14;
  int iStack_10;
  u32 uStack_c;
  int iStack_8;
  u32 uStack_4;
  
  iVar1 = *(int *)((int)param_3 + DAT_007ce738);
  if (iVar1 == 0) {
    iVar1 = (*DAT_00960188)(DAT_0095c400,0x30120);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      ((code)FUN_00521408)(iVar1,0,0x90);
      *(int *)((int)param_3 + DAT_007ce738) = iVar1;
    }
  }
  if (iVar1 == 0) {
    param_1 = 0;
  }
  else {
    lVar2 = ((code)FUN_004c1910)(param_1,&uStack_4,4);
    if (lVar2 == 0) {
      param_1 = 0;
    }
    else {
      ((code)FUN_00468ea0)(param_3,uStack_4);
      uVar4 = 0;
      do {
        lVar2 = ((code)FUN_004c1910)(param_1,&iStack_8,4);
        if (lVar2 == 0) {
          return 0;
        }
        if (iStack_8 == 4) {
          iStack_24 = 0;
          lVar2 = ((code)FUN_004c1910)(param_1,&uStack_30,8);
          if (lVar2 == 0) {
            return 0;
          }
          lVar2 = ((code)FUN_00467b40)(param_1,&iStack_24);
          if (lVar2 == 0) {
            return 0;
          }
          if (iStack_24 != 0) {
            ((code)FUN_00469770)(param_3);
            ((code)FUN_004d0f00)(iStack_24);
          }
          ((code)FUN_00469840)(param_3,uStack_30,uStack_2c);
        }
        else if (iStack_8 == 2) {
          iStack_20 = 0;
          lVar2 = ((code)FUN_004c18b0)(param_1,&uStack_18);
          if (lVar2 == 0) {
            return 0;
          }
          lVar2 = ((code)FUN_004c1910)(param_1,&uStack_1c,4);
          if (lVar2 == 0) {
            return 0;
          }
          lVar2 = ((code)FUN_00467b40)(param_1,&iStack_20);
          if (lVar2 == 0) {
            return 0;
          }
          if (iStack_20 != 0) {
            ((code)FUN_00469400)(param_3);
            ((code)FUN_004d0f00)(iStack_20);
          }
          ((code)FUN_00469590)(uStack_18,param_3);
          ((code)FUN_00469510)(param_3,uStack_1c);
        }
        else if (iStack_8 == 1) {
          iVar3 = iVar1 + uVar4 * 0x40;
          iStack_10 = 0;
          iStack_14 = 0;
          lVar2 = ((code)FUN_004c18b0)(param_1,&uStack_c);
          if (lVar2 == 0) {
            return 0;
          }
          lVar2 = ((code)FUN_00467b40)(param_1,&iStack_10);
          if (lVar2 == 0) {
            return 0;
          }
          lVar2 = ((code)FUN_00467b40)(param_1,&iStack_14);
          if (lVar2 == 0) {
            if (iStack_10 != 0) {
              ((code)FUN_004d0f00)();
            }
            return 0;
          }
          if (iStack_10 == 0) {
            if (iStack_14 == 0) {
              *(u32 *)(iVar3 + 4) = 0;
              *(u32 *)(iVar3 + 8) = 0;
            }
            else {
              ((code)FUN_00469060)(param_3);
              ((code)FUN_004d0f00)(iStack_14);
            }
          }
          else {
            *(int *)(iVar3 + 4) = iStack_10;
            *(int *)(iVar3 + 8) = iStack_14;
            *(float *)(iVar3 + 0x10) = 1.0 / (float)*(int *)(**(int **)(iVar3 + 4) + 0xc);
          }
          ((code)FUN_004692e0)(uStack_c,param_3);
        }
        uVar4 = uVar4 + 1 & 0xff;
      } while (uVar4 < 2);
    }
  }
  return param_1;
}

// FUN_00468350 NONMATCHING

int FUN_00468350(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  u32 uVar7;
  
  iVar1 = *(int *)(param_1 + DAT_007ce738);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x80) == 0)) {
    iVar3 = 0;
  }
  else {
    iVar3 = 4;
    uVar7 = 0;
    do {
      iVar4 = 4;
      piVar6 = (int *)(iVar1 + uVar7 * 0x40);
      iVar5 = piVar6[8];
      if (iVar5 == 4) {
        if (*piVar6 != 0) {
          iVar4 = ((code)FUN_004c81d0)();
          iVar4 = iVar4 + 0x10;
        }
        iVar2 = iVar3 + 0xc + iVar4;
      }
      else if (iVar5 == 2) {
        if (piVar6[1] != 0) {
          iVar4 = ((code)FUN_004c81d0)();
          iVar4 = iVar4 + 0x10;
        }
        iVar2 = iVar3 + 0xc + iVar4;
      }
      else {
        iVar2 = iVar3 + 4;
        if (iVar5 == 1) {
          if (piVar6[1] != 0) {
            iVar4 = ((code)FUN_004c81d0)();
            iVar4 = iVar4 + 0x10;
          }
          iVar5 = 4;
          if (piVar6[2] != 0) {
            iVar5 = ((code)FUN_004c81d0)();
            iVar5 = iVar5 + 0x10;
          }
          iVar2 = iVar3 + 8 + iVar4 + iVar5;
        }
      }
      iVar3 = iVar2;
      uVar7 = uVar7 + 1 & 0xff;
    } while (uVar7 < 2);
  }
  return iVar3;
}

#pragma schedule on
// FUN_00468530

void FUN_00468530(u64 param_1,u64 param_2,int param_3)

{
  u32 uStack_4;
  
  uStack_4 = *(u32 *)(param_3 + iGpffffba4c);
  FUN_004c17f0_typed(param_1,&uStack_4,4);
  return;
}
#pragma schedule off

// FUN_00468560 NONMATCHING

u64 FUN_00468560(u64 param_1,u64 param_2,u64 param_3)

{
  long lVar1;
  int iStack_4;
  
  lVar1 = ((code)FUN_004c1910)(param_1,&iStack_4,4);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  else if (iStack_4 != 0) {
    ((code)FUN_00468dc0)(param_3);
  }
  return param_1;
}

#pragma schedule on
// FUN_00468660

void FUN_00468660(u64 param_1,u64 param_2,int param_3)

{
  u32 uStack_4;
  
  uStack_4 = *(u32 *)(param_3 + iGpffffba50);
  FUN_004c17f0_typed(param_1,&uStack_4,4);
  return;
}
#pragma schedule off

// FUN_00468690 NONMATCHING

u64 FUN_00468690(u64 param_1,u64 param_2,u64 param_3)

{
  long lVar1;
  int iStack_4;
  
  lVar1 = ((code)FUN_004c1910)(param_1,&iStack_4,4);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  else if (iStack_4 != 0) {
    ((code)FUN_00468e30)(param_3);
  }
  return param_1;
}

// FUN_00468720 NONMATCHING

void FUN_00468720(char *param_1,long param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  u8 bVar3;
  char **ppcVar4;
  int iVar5;
  int iVar6;
  char *apcStack_8 [2];
  
  iVar6 = 0;
  if (param_2 == 0) {
    apcStack_8[1] = (char *)(param_3 + 0x10);
    apcStack_8[0] = (char *)(param_3 + 0x10);
  }
  else {
    apcStack_8[0] = (char *)((int)param_2 + 0x10);
    apcStack_8[1] = (char *)(param_3 + 0x10);
  }
  bVar3 = 1;
  while ((bVar3 && ((*apcStack_8[0] != '\0' || (*apcStack_8[1] != '\0'))))) {
    iVar5 = 0;
    ppcVar4 = apcStack_8;
    do {
      pcVar2 = *ppcVar4;
      cVar1 = *pcVar2;
      if (cVar1 != '\0') {
        *param_1 = cVar1;
        iVar6 = iVar6 + 1;
        param_1 = param_1 + 1;
        *ppcVar4 = pcVar2 + 1;
      }
      iVar5 = iVar5 + 1;
      ppcVar4 = ppcVar4 + 1;
    } while (iVar5 < 2);
    bVar3 = iVar6 < 0x1e;
  }
  *param_1 = '\0';
  return;
}

// FUN_004687E0 NONMATCHING

u64 FUN_004687e0(long param_1,int *param_2)

{
  u8 bVar1;
  int iVar2;
  int iVar3;
  u32 uVar4;
  u8 bVar5;
  u8 *puVar6;
  u8 *puVar7;
  u64 uVar8;
  u64 uVar9;
  u64 uVar10;
  u8 *puVar11;
  int iVar12;
  int iVar13;
  u32 uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  u8 auStack_30 [32];
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar20 = 0;
  iVar16 = *param_2;
  iVar2 = *(int *)(iVar16 + 0xc);
  iVar3 = *(int *)(iVar16 + 0x10);
  uVar8 = ((code)FUN_004cbe00)(iVar2,iVar3,0x20);
  ((code)FUN_004cbf20)(uVar8);
  ((code)FUN_004cdc70)(uVar8,iVar16);
  if (param_1 == 0) {
    iVar19 = *(int *)(iVar16 + 0xc);
    iVar18 = *(int *)(iVar16 + 0x10);
    uVar9 = ((code)FUN_004cbe00)(iVar19,iVar18,0x20);
    ((code)FUN_004cbf20)(uVar9);
    iVar13 = 0;
    if (0 < iVar18) {
      do {
        iVar15 = 0;
        if (0 < iVar19) {
          iVar17 = (int)uVar9;
          if (8 < iVar19) {
            bVar5 = 0;
            if ((-1 < iVar19) && (iVar19 < 0x7fffffff)) {
              bVar5 = 1;
            }
            if (bVar5) {
              iVar12 = 0;
              do {
                *(u32 *)(*(int *)(iVar17 + 0x14) + *(int *)(iVar17 + 0x10) * iVar13 + iVar12)
                     = 0xffffffff;
                *(u32 *)
                 (*(int *)(iVar17 + 0x14) + *(int *)(iVar17 + 0x10) * iVar13 + iVar12 + 4) =
                     0xffffffff;
                *(u32 *)
                 (*(int *)(iVar17 + 0x14) + *(int *)(iVar17 + 0x10) * iVar13 + iVar12 + 8) =
                     0xffffffff;
                *(u32 *)
                 (*(int *)(iVar17 + 0x14) + *(int *)(iVar17 + 0x10) * iVar13 + iVar12 + 0xc) =
                     0xffffffff;
                *(u32 *)
                 (*(int *)(iVar17 + 0x14) + *(int *)(iVar17 + 0x10) * iVar13 + iVar12 + 0x10) =
                     0xffffffff;
                *(u32 *)
                 (*(int *)(iVar17 + 0x14) + *(int *)(iVar17 + 0x10) * iVar13 + iVar12 + 0x14) =
                     0xffffffff;
                *(u32 *)
                 (*(int *)(iVar17 + 0x14) + *(int *)(iVar17 + 0x10) * iVar13 + iVar12 + 0x18) =
                     0xffffffff;
                iVar15 = iVar15 + 8;
                *(u32 *)
                 (*(int *)(iVar17 + 0x14) + *(int *)(iVar17 + 0x10) * iVar13 + iVar12 + 0x1c) =
                     0xffffffff;
                iVar12 = iVar12 + 0x20;
              } while (iVar15 < iVar19 + -8);
            }
          }
          if (iVar15 < iVar19) {
            iVar12 = iVar15 << 2;
            do {
              iVar15 = iVar15 + 1;
              *(u32 *)(*(int *)(iVar17 + 0x14) + *(int *)(iVar17 + 0x10) * iVar13 + iVar12) =
                   0xffffffff;
              iVar12 = iVar12 + 4;
            } while (iVar15 < iVar19);
          }
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 < iVar18);
    }
  }
  else {
    iVar20 = *(int *)param_1;
    iVar19 = *(int *)(iVar20 + 0xc);
    iVar18 = *(int *)(iVar20 + 0x10);
    uVar9 = ((code)FUN_004cbe00)(iVar19,iVar18,0x20);
    ((code)FUN_004cbf20)(uVar9);
    ((code)FUN_004cdc70)(uVar9,iVar20);
  }
  if ((iVar19 != iVar2) || (uVar10 = uVar8, iVar18 != iVar3)) {
    uVar10 = ((code)FUN_004cbe00)(iVar19,iVar18,0x20);
    ((code)FUN_004cbf20)(uVar10);
    ((code)FUN_004cec10)(uVar10,uVar8);
    ((code)FUN_004cbeb0)(uVar8);
  }
  ((code)FUN_004cc0a0)(uVar10);
  ((code)FUN_004cc1d0)(uVar9,uVar10);
  ((code)FUN_004cdd50)(uVar9,4,&uStack_4,&uStack_8,&uStack_c,&uStack_10);
  if (param_1 == 0) {
    bVar1 = *(u8 *)(iVar16 + 0x23);
  }
  else {
    bVar1 = *(u8 *)(iVar20 + 0x23);
  }
  if ((bVar1 & 0x80) != 0) {
    uStack_10 = uStack_10 | 0x9000;
  }
  uVar8 = ((code)FUN_004ce0f0)(uStack_4,uStack_8,uStack_c,uStack_10);
  ((code)FUN_004cdce0)(uVar8,uVar9);
  uVar8 = ((code)FUN_004d0e40)(uVar8);
  if (param_1 == 0) {
    uVar4 = param_2[0x14];
    uVar14 = (uVar4 & 0xf000) >> 0xc;
    if ((uVar4 & 0xf00) >> 8 != uVar14) {
      uVar14 = 0;
    }
  }
  else {
    uVar4 = ((int *)param_1)[0x14];
    uVar14 = (uVar4 & 0xf000) >> 0xc;
    if ((uVar4 & 0xf00) >> 8 != uVar14) {
      uVar14 = 0;
    }
  }
  iVar16 = (int)uVar8;
  *(u32 *)(iVar16 + 0x50) = *(u32 *)(iVar16 + 0x50) & 0xffff00ff | uVar14 << 8 | uVar14 << 0xc;
  *(u32 *)(iVar16 + 0x50) = *(u32 *)(iVar16 + 0x50) & 0xffffff00 | uVar4 & 0xff;
  ((code)FUN_004cbeb0)(uVar9);
  ((code)FUN_004cbeb0)(uVar10);
  puVar7 = (u8 *)0x20;
  puVar11 = auStack_30;
  puVar6 = puVar11;
  while (puVar6 != (u8 *)0x0) {
    *puVar11 = 0;
    puVar11 = puVar11 + 1;
    puVar7 = puVar7 + -1;
    puVar6 = puVar7;
  }
  ((code)FUN_00468720)(auStack_30,param_1,param_2);
  ((code)FUN_004d0fd0)(uVar8,auStack_30);
  return uVar8;
}

// FUN_00468C50 NONMATCHING

u8 FUN_00468c50(void)

{
  u8 bVar1;
  long lVar2;
  
  lVar2 = ((code)FUN_004ca520)(0,0x120,0x467600,0x467590);
  if (lVar2 < 0) {
    bVar1 = 0;
  }
  else {
    lVar2 = ((code)FUN_00494db0)(4,0x120,0x4676a0,0x4677f0,0x467860);
    uGpffffba48 = (u32)lVar2;
    if (lVar2 < 0) {
      bVar1 = 0;
    }
    else {
      lVar2 = ((code)FUN_00494de0)(0x120,0x467fd0,0x467c20,0x468350);
      if (lVar2 < 0) {
        bVar1 = 0;
      }
      else {
        lVar2 = ((code)FUN_00492c30)(4,0x120,0x4684c0,0x4684e0,0x468500);
        uGpffffba4c = (u32)lVar2;
        if (lVar2 < 0) {
          bVar1 = 0;
        }
        else {
          lVar2 = ((code)FUN_00492c90)(0x120,0x468560,0x468530,0x4685d0);
          if (lVar2 < 0) {
            bVar1 = 0;
          }
          else {
            lVar2 = ((code)FUN_00499250)(4,0x120,0x4685f0,0x468610,0x468630);
            uGpffffba50 = (u32)lVar2;
            if (lVar2 < 0) {
              bVar1 = 0;
            }
            else {
              lVar2 = ((code)FUN_00499280)(0x120,0x468690,0x468660,0x468700);
              bVar1 = -1 < lVar2;
            }
          }
        }
      }
    }
  }
  return bVar1;
}

// FUN_00468DC0 NONMATCHING

u64 FUN_00468dc0(u64 param_1)

{
  long lVar1;
  int *piVar2;
  
  piVar2 = (int *)((int)param_1 + iGpffffba4c);
  if (*piVar2 == 0) {
    lVar1 = ((code)FUN_00469d60)();
    if (lVar1 == 0) {
      param_1 = 0;
    }
    else {
      *piVar2 = 1;
    }
  }
  return param_1;
}

// FUN_00468E30 NONMATCHING

u64 FUN_00468e30(u64 param_1)

{
  long lVar1;
  int *piVar2;
  
  piVar2 = (int *)((int)param_1 + iGpffffba50);
  if (*piVar2 == 0) {
    lVar1 = ((code)FUN_00469d00)();
    if (lVar1 == 0) {
      param_1 = 0;
    }
    else {
      *piVar2 = 1;
    }
  }
  return param_1;
}

// FUN_00468EA0 NONMATCHING

u64 FUN_00468ea0(u64 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + iGpffffba48);
  if (iVar1 == 0) {
    iVar1 = (*DAT_00960188)(DAT_0095c400,0x30120);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      ((code)FUN_00521408)(iVar1,0,0x90);
      *(int *)((int)param_1 + iGpffffba48) = iVar1;
    }
  }
  if (iVar1 == 0) {
    return 0;
  }
  if ((param_2 == 0) || ((*(int *)(iVar1 + 0x80) != 0 && (*(int *)(iVar1 + 0x80) != param_2)))) {
    ((code)FUN_004676c0)(iVar1);
    *(int *)(iVar1 + 0x80) = param_2;
  }
  else {
    *(int *)(iVar1 + 0x80) = param_2;
  }
  switch(*(u32 *)(iVar1 + 0x80)) {
  case 1:
    *(u32 *)(iVar1 + 0x20) = 1;
    break;
  case 2:
    *(u32 *)(iVar1 + 0x20) = 2;
    break;
  case 3:
    *(u32 *)(iVar1 + 0x20) = 1;
    *(u32 *)(iVar1 + 0x60) = 2;
    break;
  case 4:
    *(u32 *)(iVar1 + 0x20) = 4;
    ((code)FUN_00469840)(param_1,5,6);
    goto LAB_00468f98;
  case 5:
    *(u32 *)(iVar1 + 0x20) = 5;
    break;
  case 6:
    *(u32 *)(iVar1 + 0x20) = 5;
    *(u32 *)(iVar1 + 0x60) = 4;
    ((code)FUN_00469840)(param_1,5,6);
  }
LAB_00468f98:
  ((code)FUN_00469aa0)(param_1);
  return param_1;
}

// FUN_00469030 NONMATCHING

u32 FUN_00469030(int param_1)

{
  u32 uVar1;
  
  if (*(int *)(param_1 + iGpffffba48) == 0) goto zero;
  uVar1 = *(u32 *)(*(int *)(param_1 + iGpffffba48) + 0x80);
  goto done;
zero:
  uVar1 = 0;
done:
  return uVar1;
}

// FUN_00469060 NONMATCHING

u64 FUN_00469060(u64 param_1,int *param_2)

{
  int iVar1;
  u8 bVar2;
  u8 *puVar3;
  u8 *puVar4;
  u32 uVar5;
  long lVar6;
  u8 *puVar7;
  u32 uVar8;
  int iVar9;
  int *piVar10;
  u8 auStack_20 [32];
  
  uVar8 = 0;
  piVar10 = (int *)param_1;
  do {
    iVar9 = *(int *)((int)piVar10 + iGpffffba48) + uVar8 * 0x40;
    if (*(int *)(iVar9 + 0x20) == 1) {
      iVar1 = *(int *)(iVar9 + 8);
      goto LAB_004690d4;
    }
    uVar8 = uVar8 + 1 & 0xff;
  } while (uVar8 < 2);
  iVar9 = 0;
  iVar1 = iRam00000008;
LAB_004690d4:
  if (iVar1 != 0) {
    ((code)FUN_004d0f00)();
    *(u32 *)(iVar9 + 8) = 0;
  }
  if (*(int *)(iVar9 + 4) != 0) {
    ((code)FUN_004d0f00)();
    *(u32 *)(iVar9 + 4) = 0;
    *(u32 *)(iVar9 + 0x10) = 0;
  }
  if (param_2 == 0) {
    *(float *)(iVar9 + 0x10) = 1.0 / (float)*(int *)(*(int *)*piVar10 + 0xc);
    return param_1;
  }
  *(int **)(iVar9 + 8) = (int *)param_2;
  *(int *)(*(int *)(iVar9 + 8) + 0x54) = *(int *)(*(int *)(iVar9 + 8) + 0x54) + 1;
  bVar2 = *(int *)(*(int *)param_2 + 0xc) == 0;
  piVar10 = (int *)*piVar10;
  if ((!bVar2) && (piVar10 != (int *)0x0)) {
    bVar2 = *(int *)(*piVar10 + 0xc) == 0;
  }
  if (bVar2) {
    return param_1;
  }
  puVar4 = (u8 *)0x20;
  puVar7 = auStack_20;
  puVar3 = puVar7;
  while (puVar3 != (u8 *)0x0) {
    *puVar7 = 0;
    puVar7 = puVar7 + 1;
    puVar4 = puVar4 + -1;
    puVar3 = puVar4;
  }
  ((code)FUN_00468720)(auStack_20,piVar10,param_2);
  lVar6 = ((code)FUN_004d11f0)();
  *(u32 *)(iVar9 + 4) = 0;
  if (lVar6 != 0) {
    uVar5 = ((code)FUN_004d1170)(lVar6,auStack_20);
    *(u32 *)(iVar9 + 4) = uVar5;
  }
  iVar1 = *(int *)(iVar9 + 4);
  if (iVar1 == 0) {
    uVar5 = thunk_FUN_004687e0(piVar10,param_2);
    *(u32 *)(iVar9 + 4) = uVar5;
    if (*(int *)(iVar9 + 4) == 0) {
      return 0;
    }
    if (lVar6 != 0) {
      ((code)FUN_004d1110)(lVar6);
      piVar10 = *(int **)(iVar9 + 4);
      goto LAB_004691d0;
    }
  }
  else {
    *(int *)(iVar1 + 0x54) = *(int *)(iVar1 + 0x54) + 1;
  }
  piVar10 = *(int **)(iVar9 + 4);
LAB_004691d0:
  *(float *)(iVar9 + 0x10) = 1.0 / (float)*(int *)(*piVar10 + 0xc);
  return param_1;
}

// FUN_00469280 NONMATCHING

u64 FUN_00469280(u64 param_1,u32 param_2)

{
  u32 uVar1;
  u32 *puVar2;
  
  uVar1 = 0;
  do {
    puVar2 = (u32 *)(*(int *)((int)param_1 + iGpffffba48) + uVar1 * 0x40);
    if (puVar2[8] == 1) {
      *puVar2 = param_2;
      return param_1;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 2);
  uRam00000000 = param_2;
  return param_1;
}

// FUN_004692E0 NONMATCHING

u64 FUN_004692e0(float param_1,u64 param_2)

{
  u32 uVar1;
  int iVar2;
  
  uVar1 = 0;
  do {
    iVar2 = *(int *)((int)param_2 + iGpffffba48) + uVar1 * 0x40;
    if (*(int *)(iVar2 + 0x20) == 1) goto LAB_00469330;
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 2);
  iVar2 = 0;
LAB_00469330:
  *(float *)(iVar2 + 0xc) = -param_1;
  return param_2;
}

// FUN_00469340 NONMATCHING

u32 FUN_00469340(int param_1)

{
  u32 uVar1;
  u32 *puVar2;
  
  uVar1 = 0;
  do {
    puVar2 = (u32 *)(*(int *)(param_1 + iGpffffba48) + uVar1 * 0x40);
    if (puVar2[8] == 1) {
      return *puVar2;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 2);
  return uRam00000000;
}

// FUN_004693A0 NONMATCHING

float FUN_004693a0(int param_1)

{
  u32 uVar1;
  int iVar2;
  float fVar3;
  
  uVar1 = 0;
  do {
    iVar2 = *(int *)(param_1 + iGpffffba48) + uVar1 * 0x40;
    if (*(int *)(iVar2 + 0x20) == 1) {
      fVar3 = *(float *)(iVar2 + 0xc);
      break;
    }
    uVar1 = uVar1 + 1 & 0xff;
    fVar3 = fRam0000000c;
  } while (uVar1 < 2);
  return -fVar3;
}

// FUN_00469400 NONMATCHING

u64 FUN_00469400(u64 param_1,int param_2)

{
  int iVar1;
  u32 uVar2;
  int iVar3;
  
  uVar2 = 0;
  do {
    iVar3 = *(int *)((int)param_1 + iGpffffba48) + uVar2 * 0x40;
    if (*(int *)(iVar3 + 0x20) == 2) {
      iVar1 = *(int *)(param_2 + 0x54);
      goto LAB_0046946c;
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 2);
  iVar3 = 0;
  iVar1 = *(int *)(param_2 + 0x54);
LAB_0046946c:
  *(int *)(param_2 + 0x54) = iVar1 + 1;
  if (*(int *)(iVar3 + 4) != 0) {
    ((code)FUN_004d0f00)();
    *(u32 *)(iVar3 + 4) = 0;
  }
  *(int *)(iVar3 + 4) = param_2;
  return param_1;
}

// FUN_004694B0 NONMATCHING

u64 FUN_004694b0(u64 param_1,u32 param_2)

{
  u32 uVar1;
  u32 *puVar2;
  
  uVar1 = 0;
  do {
    puVar2 = (u32 *)(*(int *)((int)param_1 + iGpffffba48) + uVar1 * 0x40);
    if (puVar2[8] == 2) {
      *puVar2 = param_2;
      return param_1;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 2);
  uRam00000000 = param_2;
  return param_1;
}

// FUN_00469510 NONMATCHING

u64 FUN_00469510(u64 param_1,u32 param_2)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  
  uVar2 = 0;
  do {
    iVar3 = *(int *)((int)param_1 + iGpffffba48) + uVar2 * 0x40;
    if (*(int *)(iVar3 + 0x20) == 2) {
      *(u32 *)(iVar3 + 0xc) = param_2;
      uVar1 = uRam0000000c;
      break;
    }
    uVar2 = uVar2 + 1 & 0xff;
    uVar1 = param_2;
  } while (uVar2 < 2);
  uRam0000000c = uVar1;
  ((code)FUN_00469b50)(param_1);
  return param_1;
}

// FUN_00469590 NONMATCHING

u64 FUN_00469590(u32 param_1,u64 param_2)

{
  u32 uVar1;
  int iVar2;
  
  uVar1 = 0;
  do {
    iVar2 = *(int *)((int)param_2 + iGpffffba48) + uVar1 * 0x40;
    if (*(int *)(iVar2 + 0x20) == 2) {
      *(u32 *)(iVar2 + 8) = param_1;
      return param_2;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 2);
  uRam00000008 = param_1;
  return param_2;
}

// FUN_004695F0 NONMATCHING

u32 FUN_004695f0(int param_1)

{
  u32 uVar1;
  int iVar2;
  
  uVar1 = 0;
  do {
    iVar2 = *(int *)(param_1 + iGpffffba48) + uVar1 * 0x40;
    if (*(int *)(iVar2 + 0x20) == 2) {
      return *(u32 *)(iVar2 + 4);
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 2);
  return uRam00000004;
}

// FUN_00469650 NONMATCHING

u32 FUN_00469650(int param_1)

{
  u32 uVar1;
  u32 *puVar2;
  
  uVar1 = 0;
  do {
    puVar2 = (u32 *)(*(int *)(param_1 + iGpffffba48) + uVar1 * 0x40);
    if (puVar2[8] == 2) {
      return *puVar2;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 2);
  return uRam00000000;
}

// FUN_004696B0 NONMATCHING

u32 FUN_004696b0(int param_1)

{
  u32 uVar1;
  int iVar2;
  
  uVar1 = 0;
  do {
    iVar2 = *(int *)(param_1 + iGpffffba48) + uVar1 * 0x40;
    if (*(int *)(iVar2 + 0x20) == 2) {
      return *(u32 *)(iVar2 + 0xc);
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 2);
  return uRam0000000c;
}

// FUN_00469710 NONMATCHING

u32 FUN_00469710(int param_1)

{
  u32 uVar1;
  int iVar2;
  
  uVar1 = 0;
  do {
    iVar2 = *(int *)(param_1 + iGpffffba48) + uVar1 * 0x40;
    if (*(int *)(iVar2 + 0x20) == 2) {
      return *(u32 *)(iVar2 + 8);
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 2);
  return uRam00000008;
}

// FUN_00469770 NONMATCHING

u64 FUN_00469770(u64 param_1,int param_2)

{
  int iVar1;
  u32 uVar2;
  int *piVar3;
  
  uVar2 = 0;
  do {
    piVar3 = (int *)(*(int *)((int)param_1 + iGpffffba48) + uVar2 * 0x40);
    if (piVar3[8] == 4) {
      iVar1 = *(int *)(param_2 + 0x54);
      goto LAB_004697dc;
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 2);
  piVar3 = (int *)0x0;
  iVar1 = *(int *)(param_2 + 0x54);
LAB_004697dc:
  *(int *)(param_2 + 0x54) = iVar1 + 1;
  if (*piVar3 != 0) {
    ((code)FUN_004d0f00)();
    *piVar3 = 0;
  }
  *piVar3 = param_2;
  ((code)FUN_00469a90)(piVar3,2);
  ((code)FUN_00469a90)(piVar3,1);
  return param_1;
}

// FUN_00469840 NONMATCHING

u64 FUN_00469840(u64 param_1,u32 param_2,u32 param_3)

{
  u32 uVar1;
  int iVar2;
  
  uVar1 = 0;
  do {
    iVar2 = *(int *)((int)param_1 + iGpffffba48) + uVar1 * 0x40;
    if (*(int *)(iVar2 + 0x20) == 4) {
      *(u32 *)(iVar2 + 4) = param_2;
      goto LAB_004698a4;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 2);
  iVar2 = 0;
  uRam00000004 = param_2;
LAB_004698a4:
  *(u32 *)(iVar2 + 8) = param_3;
  ((code)FUN_00469a90)(iVar2,10);
  ((code)FUN_00469a90)(iVar2,0xb);
  ((code)FUN_00469bc0)(param_1);
  return param_1;
}

// FUN_004698E0 NONMATCHING

u32 FUN_004698e0(int param_1)

{
  u32 uVar1;
  u32 *puVar2;
  
  uVar1 = 0;
  do {
    puVar2 = (u32 *)(*(int *)(param_1 + iGpffffba48) + uVar1 * 0x40);
    if (puVar2[8] == 4) {
      return *puVar2;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 2);
  return uRam00000000;
}

// FUN_00469940 NONMATCHING

u64 FUN_00469940(u64 param_1,u32 *param_2,u32 *param_3)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  
  uVar2 = 0;
  do {
    iVar3 = *(int *)((int)param_1 + iGpffffba48) + uVar2 * 0x40;
    if (*(int *)(iVar3 + 0x20) == 4) {
      uVar1 = *(u32 *)(iVar3 + 4);
      goto LAB_00469990;
    }
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 2);
  iVar3 = 0;
  uVar1 = uRam00000004;
LAB_00469990:
  *param_2 = uVar1;
  *param_3 = *(u32 *)(iVar3 + 8);
  return param_1;
}

// FUN_004699B0 NONMATCHING

u64 FUN_004699b0(u64 param_1,u32 param_2,u32 param_3)

{
  u32 uVar1;
  u32 *puVar2;
  
  uVar1 = 0;
  do {
    puVar2 = (u32 *)(*(int *)((int)param_1 + iGpffffba48) + uVar1 * 0x40);
    if (puVar2[8] == 5) {
      *puVar2 = param_2;
      goto LAB_00469a00;
    }
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 2);
  puVar2 = (u32 *)0x0;
  uRam00000000 = param_2;
LAB_00469a00:
  puVar2[1] = param_3;
  return param_1;
}

// FUN_00469A10 NONMATCHING

u64 FUN_00469a10(u64 param_1,long param_2,long param_3)

{
  u32 uVar1;
  u32 *puVar2;
  
  uVar1 = 0;
  do {
    puVar2 = (u32 *)(*(int *)((int)param_1 + iGpffffba48) + uVar1 * 0x40);
    if (puVar2[8] == 5) goto LAB_00469a5c;
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 2);
  puVar2 = (u32 *)0x0;
LAB_00469a5c:
  if (param_2 != 0) {
    *(u32 *)param_2 = *puVar2;
  }
  if (param_3 != 0) {
    *(u32 *)param_3 = puVar2[1];
  }
  return param_1;
}

#pragma optimization_level 3
// FUN_00469A90
u32 FUN_00469a90(void)
{
  return 1;
}
#pragma optimization_level 2

// FUN_00469AA0 NONMATCHING

void FUN_00469aa0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + iGpffffba48);
  switch(*(u32 *)(iVar1 + 0x80)) {
  case 2:
    *(u64 *)(iVar1 + 0x28) = 0x8000000068;
    *(u64 *)(iVar1 + 0x30) = 0;
    *(u64 *)(iVar1 + 0x38) = 0;
    break;
  case 3:
    *(u64 *)(iVar1 + 0x68) = 0x58;
    *(u64 *)(iVar1 + 0x70) = 0;
    *(u64 *)(iVar1 + 0x78) = 0;
  case 1:
    *(u64 *)(iVar1 + 0x28) = 0x8000000048;
    *(u64 *)(iVar1 + 0x30) = 0;
    *(u64 *)(iVar1 + 0x38) = 0;
    break;
  case 4:
    *(u64 *)(iVar1 + 0x30) = 0x1000000;
    *(u64 *)(iVar1 + 0x38) = 0;
    break;
  case 6:
    *(u64 *)(iVar1 + 0x70) = 0x1000000;
    *(u64 *)(iVar1 + 0x78) = 0;
  }
  return;
}

// FUN_00469B50 NONMATCHING

void FUN_00469b50(int param_1)

{
  int iVar1;
  u64 uVar2;
  
  iVar1 = *(int *)(param_1 + iGpffffba48);
  if (*(int *)(iVar1 + 0x80) == 3) {
    uVar2 = 0x58;
    if (*(int *)(iVar1 + 0x4c) == 0) {
      uVar2 = 0x8000000068;
    }
    *(u64 *)(iVar1 + 0x68) = uVar2;
  }
  else {
    uVar2 = 0x58;
    if (*(int *)(iVar1 + 0xc) == 0) {
      uVar2 = 0x8000000068;
    }
    *(u64 *)(iVar1 + 0x28) = uVar2;
  }
  return;
}

// FUN_00469BC0 NONMATCHING

void FUN_00469bc0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + iGpffffba48);
  iVar3 = (u32)(*(int *)(iVar1 + 0x80) != 4) * 0x40;
  iVar2 = iVar1 + iVar3;
  switch(*(u32 *)(iVar2 + 4)) {
  default:
    iVar4 = 5;
    break;
  case 1:
    iVar4 = 0;
    break;
  case 2:
    iVar4 = 1;
    break;
  case 5:
    iVar4 = 2;
    break;
  case 6:
    iVar4 = 3;
    break;
  case 7:
    iVar4 = 4;
  }
  switch(*(u32 *)(iVar2 + 8)) {
  default:
    iVar2 = 5;
    break;
  case 1:
    iVar2 = 0;
    break;
  case 2:
    iVar2 = 1;
    break;
  case 5:
    iVar2 = 2;
    break;
  case 6:
    iVar2 = 3;
    break;
  case 7:
    iVar2 = 4;
  }
  *(u32 *)(iVar3 + iVar1 + 0x28) = (u32)*(u8 *)(iVar4 + iVar2 * 6 + 0x6b4eb0) | 0x8000000000;
  return;
}

#pragma optimization_level 3
// FUN_00469CE0
u32 FUN_00469ce0(void)
{
  return 1;
}
#pragma optimization_level 2

#pragma optimization_level 3
// FUN_00469CF0
u32 FUN_00469cf0(void)
{
  return 1;
}
#pragma optimization_level 2

// FUN_00469D00 NONMATCHING

u64 FUN_00469d00(u64 param_1)

{
  int iVar1;
  u32 uVar2;
  
  iVar1 = ((code)FUN_0049a170)();
  if ((*(u32 *)(iVar1 + 8) & 0x80) == 0) {
    uVar2 = ((code)FUN_0046a890)(0x1100f);
    *(u32 *)((int)param_1 + 0x7c) = uVar2;
  }
  else {
    uVar2 = ((code)FUN_0046a890)(0x11010);
    *(u32 *)((int)param_1 + 0x7c) = uVar2;
  }
  return param_1;
}

// FUN_00469D60 NONMATCHING

u64 FUN_00469d60(u64 param_1)

{
  u32 uVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if ((*(u32 *)(*(int *)(iVar2 + 0x18) + 8) & 0x80) == 0) {
    uVar1 = ((code)FUN_0046a890)(0x1100d);
    *(u32 *)(iVar2 + 0x6c) = uVar1;
  }
  else {
    uVar1 = ((code)FUN_0046a890)(0x1100e);
    *(u32 *)(iVar2 + 0x6c) = uVar1;
  }
  return param_1;
}



// FUN_00469dc0 thunk_FUN_004687e0 NONMATCHING

u64 thunk_FUN_004687e0(int *param_1,int *param_2)

{
  u8 bVar1;
  int iVar2;
  int iVar3;
  u32 uVar4;
  u8 bVar5;
  u8 *puVar6;
  u8 *puVar7;
  u64 uVar8;
  u64 uVar9;
  u64 uVar10;
  u8 *puVar11;
  int iVar12;
  int iVar13;
  u32 uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  u8 auStack_30 [32];
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar20 = 0;
  iVar16 = *param_2;
  iVar2 = *(int *)(iVar16 + 0xc);
  iVar3 = *(int *)(iVar16 + 0x10);
  uVar8 = ((code)FUN_004cbe00)(iVar2,iVar3,0x20);
  ((code)FUN_004cbf20)(uVar8);
  ((code)FUN_004cdc70)(uVar8,iVar16);
  if (param_1 == 0) {
    iVar19 = *(int *)(iVar16 + 0xc);
    iVar18 = *(int *)(iVar16 + 0x10);
    uVar9 = ((code)FUN_004cbe00)(iVar19,iVar18,0x20);
    ((code)FUN_004cbf20)(uVar9);
    iVar13 = 0;
    if (0 < iVar18) {
      do {
        iVar15 = 0;
        if (0 < iVar19) {
          iVar17 = (int)uVar9;
          if (8 < iVar19) {
            bVar5 = 0;
            if ((-1 < iVar19) && (iVar19 < 0x7fffffff)) {
              bVar5 = 1;
            }
            if (bVar5) {
              iVar12 = 0;
              do {
                *(u32 *)(*(int *)(iVar17 + 0x14) + *(int *)(iVar17 + 0x10) * iVar13 + iVar12)
                     = 0xffffffff;
                *(u32 *)
                 (*(int *)(iVar17 + 0x14) + *(int *)(iVar17 + 0x10) * iVar13 + iVar12 + 4) =
                     0xffffffff;
                *(u32 *)
                 (*(int *)(iVar17 + 0x14) + *(int *)(iVar17 + 0x10) * iVar13 + iVar12 + 8) =
                     0xffffffff;
                *(u32 *)
                 (*(int *)(iVar17 + 0x14) + *(int *)(iVar17 + 0x10) * iVar13 + iVar12 + 0xc) =
                     0xffffffff;
                *(u32 *)
                 (*(int *)(iVar17 + 0x14) + *(int *)(iVar17 + 0x10) * iVar13 + iVar12 + 0x10) =
                     0xffffffff;
                *(u32 *)
                 (*(int *)(iVar17 + 0x14) + *(int *)(iVar17 + 0x10) * iVar13 + iVar12 + 0x14) =
                     0xffffffff;
                *(u32 *)
                 (*(int *)(iVar17 + 0x14) + *(int *)(iVar17 + 0x10) * iVar13 + iVar12 + 0x18) =
                     0xffffffff;
                iVar15 = iVar15 + 8;
                *(u32 *)
                 (*(int *)(iVar17 + 0x14) + *(int *)(iVar17 + 0x10) * iVar13 + iVar12 + 0x1c) =
                     0xffffffff;
                iVar12 = iVar12 + 0x20;
              } while (iVar15 < iVar19 + -8);
            }
          }
          if (iVar15 < iVar19) {
            iVar12 = iVar15 << 2;
            do {
              iVar15 = iVar15 + 1;
              *(u32 *)(*(int *)(iVar17 + 0x14) + *(int *)(iVar17 + 0x10) * iVar13 + iVar12) =
                   0xffffffff;
              iVar12 = iVar12 + 4;
            } while (iVar15 < iVar19);
          }
        }
        iVar13 = iVar13 + 1;
      } while (iVar13 < iVar18);
    }
  }
  else {
    iVar20 = *(int *)param_1;
    iVar19 = *(int *)(iVar20 + 0xc);
    iVar18 = *(int *)(iVar20 + 0x10);
    uVar9 = ((code)FUN_004cbe00)(iVar19,iVar18,0x20);
    ((code)FUN_004cbf20)(uVar9);
    ((code)FUN_004cdc70)(uVar9,iVar20);
  }
  if ((iVar19 != iVar2) || (uVar10 = uVar8, iVar18 != iVar3)) {
    uVar10 = ((code)FUN_004cbe00)(iVar19,iVar18,0x20);
    ((code)FUN_004cbf20)(uVar10);
    ((code)FUN_004cec10)(uVar10,uVar8);
    ((code)FUN_004cbeb0)(uVar8);
  }
  ((code)FUN_004cc0a0)(uVar10);
  ((code)FUN_004cc1d0)(uVar9,uVar10);
  ((code)FUN_004cdd50)(uVar9,4,&uStack_4,&uStack_8,&uStack_c,&uStack_10);
  if (param_1 == 0) {
    bVar1 = *(u8 *)(iVar16 + 0x23);
  }
  else {
    bVar1 = *(u8 *)(iVar20 + 0x23);
  }
  if ((bVar1 & 0x80) != 0) {
    uStack_10 = uStack_10 | 0x9000;
  }
  uVar8 = ((code)FUN_004ce0f0)(uStack_4,uStack_8,uStack_c,uStack_10);
  ((code)FUN_004cdce0)(uVar8,uVar9);
  uVar8 = ((code)FUN_004d0e40)(uVar8);
  if (param_1 == 0) {
    uVar4 = param_2[0x14];
    uVar14 = (uVar4 & 0xf000) >> 0xc;
    if ((uVar4 & 0xf00) >> 8 != uVar14) {
      uVar14 = 0;
    }
  }
  else {
    uVar4 = ((int *)param_1)[0x14];
    uVar14 = (uVar4 & 0xf000) >> 0xc;
    if ((uVar4 & 0xf00) >> 8 != uVar14) {
      uVar14 = 0;
    }
  }
  iVar16 = (int)uVar8;
  *(u32 *)(iVar16 + 0x50) = *(u32 *)(iVar16 + 0x50) & 0xffff00ff | uVar14 << 8 | uVar14 << 0xc;
  *(u32 *)(iVar16 + 0x50) = *(u32 *)(iVar16 + 0x50) & 0xffffff00 | uVar4 & 0xff;
  ((code)FUN_004cbeb0)(uVar9);
  ((code)FUN_004cbeb0)(uVar10);
  puVar7 = (u8 *)0x20;
  puVar11 = auStack_30;
  puVar6 = puVar11;
  while (puVar6 != (u8 *)0x0) {
    *puVar11 = 0;
    puVar11 = puVar11 + 1;
    puVar7 = puVar7 + -1;
    puVar6 = puVar7;
  }
  ((code)FUN_00468720)(auStack_30,param_1,param_2);
  ((code)FUN_004d0fd0)(uVar8,auStack_30);
  return uVar8;
}

// FUN_00469E30 NONMATCHING

u64 FUN_00469e30(u64 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  u32 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  piVar2 = (int *)(param_2 + iGpffffba54);
  iVar5 = (int)param_1;
  piVar4 = (int *)(iVar5 + iGpffffba54);
  iVar1 = piVar2[2];
  puVar3 = (u32 *)(iVar5 + 0x4c);
  if (iVar1 == *(int *)(param_2 + 0x18)) {
    iVar6 = piVar2[1];
    *piVar4 = *piVar2;
    piVar4[1] = iVar6;
    piVar4[2] = iVar1;
    if (*piVar4 != 0) {
      *(u16 *)(iVar5 + 0x50) = *(u16 *)(*piVar4 + 4);
      *puVar3 = *puVar3 | 3;
      if (((*puVar3 & 4) == 0) && (*(int *)(iVar5 + 4) != 0)) {
        ((code)FUN_004cb270)();
      }
      *(u16 *)(iVar5 + 0x52) = *(u16 *)(*piVar4 + 6);
      *puVar3 = *puVar3 | 3;
      if (((*puVar3 & 4) == 0) && (*(int *)(iVar5 + 4) != 0)) {
        ((code)FUN_004cb270)();
      }
      *(u32 *)(iVar5 + 0x54) = *(u32 *)(*piVar4 + 8);
      *(float *)(iVar5 + 0x58) = 1.0 / *(float *)(*piVar4 + 8);
      *puVar3 = *puVar3 | 3;
      if (((*puVar3 & 4) == 0) && (*(int *)(iVar5 + 4) != 0)) {
        ((code)FUN_004cb270)();
      }
      *(int *)(iVar5 + 0x5c) = piVar4[1];
      *puVar3 = *puVar3 | 3;
      if (((*puVar3 & 4) == 0) && (*(int *)(iVar5 + 4) != 0)) {
        ((code)FUN_004cb270)();
      }
    }
  }
  else {
    *piVar4 = 0;
    piVar4[1] = 0;
    piVar4[2] = 0;
  }
  return param_1;
}

// FUN_00469FE0 NONMATCHING

u64 FUN_00469fe0(u64 param_1)

{
  u32 *puVar1;
  
  puVar1 = (u32 *)((int)param_1 + iGpffffba58);
  if (puVar1[2] != 0) {
    (*DAT_0096017c)();
  }
  puVar1[2] = 0;
  *puVar1 = 0;
  return param_1;
}

// FUN_0046A040 NONMATCHING

u64 FUN_0046a040(u64 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  piVar2 = (int *)(param_2 + iGpffffba58);
  piVar3 = (int *)((int)param_1 + iGpffffba58);
  if (0 < *piVar2) {
    iVar4 = *piVar2 * 0x14;
    iVar1 = (*DAT_00960178)(iVar4,0x30105);
    piVar3[2] = iVar1;
    if (piVar3[2] == 0) {
      param_1 = 0;
    }
    else {
      iVar1 = piVar2[2];
      *piVar3 = *piVar2;
      ((code)FUN_00521250)(piVar3[2],iVar1,iVar4);
    }
  }
  return param_1;
}

// FUN_0046A0F0 NONMATCHING

u64 FUN_0046a0f0(u64 param_1,u64 param_2,int param_3)

{
  int iVar1;
  long lVar2;
  u32 *puVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  u32 uStack_20;
  int iStack_1c;
  int iStack_18;
  u32 uStack_14;
  int iStack_10;
  int iStack_4;
  
  piVar4 = (int *)(param_3 + iGpffffba58);
  iStack_4 = *piVar4;
  lVar2 = ((code)FUN_004c17f0)(param_1,&iStack_4,4);
  if (lVar2 == 0) {
    param_1 = 0;
  }
  else {
    iVar6 = 0;
    if (0 < iStack_4) {
      iVar5 = 0;
      do {
        iVar1 = piVar4[2];
        puVar3 = (u32 *)(iVar1 + iVar5);
        uStack_20 = *puVar3;
        iStack_1c = (int)*(short *)(puVar3 + 1);
        iStack_18 = (int)*(short *)((int)puVar3 + 6);
        uStack_14 = puVar3[2];
        iStack_10 = (puVar3[4] - iVar1) / 0x14;
        lVar2 = ((code)FUN_004c53f0)(param_1,&uStack_20,0x14);
        if (lVar2 == 0) {
          return 0;
        }
        iVar6 = iVar6 + 1;
        iVar5 = iVar5 + 0x14;
      } while (iVar6 < iStack_4);
    }
  }
  return param_1;
}

// FUN_0046A230 NONMATCHING

u64 FUN_0046a230(u64 param_1,u64 param_2,u64 param_3)

{
  long lVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  u32 auStack_20 [3];
  float fStack_14;
  int iStack_10;
  int iStack_4;
  
  iVar2 = (int)param_3 + iGpffffba58;
  lVar1 = ((code)FUN_004c1910)(param_1,&iStack_4,4);
  if (lVar1 == 0) {
    param_1 = 0;
  }
  else if (0 < iStack_4) {
    lVar1 = ((code)FUN_0046a470)(param_3);
    if (lVar1 == 0) {
      param_1 = 0;
    }
    else {
      iVar4 = 0;
      if (0 < iStack_4) {
        iVar3 = 0;
        do {
          lVar1 = ((code)FUN_004c5250)(param_1,auStack_20,0x14);
          if (lVar1 != 0x14) {
            return 0;
          }
          iVar4 = iVar4 + 1;
          *(u32 *)(*(int *)(iVar2 + 8) + iVar3) = auStack_20[0];
          *(short *)(*(int *)(iVar2 + 8) + iVar3 + 4) = (short)auStack_20[1];
          *(short *)(*(int *)(iVar2 + 8) + iVar3 + 6) = (short)auStack_20[2];
          *(float *)(*(int *)(iVar2 + 8) + iVar3 + 8) = fStack_14;
          *(float *)(*(int *)(iVar2 + 8) + iVar3 + 0xc) = 1.0 / fStack_14;
          *(int *)(*(int *)(iVar2 + 8) + iVar3 + 0x10) = *(int *)(iVar2 + 8) + iStack_10 * 0x14;
          iVar3 = iVar3 + 0x14;
        } while (iVar4 < iStack_4);
      }
    }
  }
  return param_1;
}

// FUN_0046A470 NONMATCHING

u64 FUN_0046a470(u64 param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)((int)param_1 + iGpffffba58);
  if (piVar2[2] != 0) {
    (*DAT_0096017c)();
    *piVar2 = 0;
    piVar2[2] = 0;
  }
  iVar1 = (*DAT_00960178)(param_2 * 0x14,0x30105);
  piVar2[2] = iVar1;
  if (piVar2[2] == 0) {
    param_1 = 0;
  }
  else {
    *piVar2 = param_2;
    ((code)FUN_00521408)(piVar2[2],0,param_2 * 0x14);
  }
  return param_1;
}

// FUN_0046A530 NONMATCHING

u8 FUN_0046a530(void)

{
  u8 bVar1;
  long lVar2;
  
  lVar2 = ((code)FUN_004ca520)(0,0x105,0x469dd0,0x469df0);
  if (lVar2 < 0) {
    bVar1 = 0;
  }
  else {
    lVar2 = ((code)FUN_00492c30)(0xc,0x105,0x469e10,0x469e10,0x469e30);
    uGpffffba54 = (u32)lVar2;
    if (lVar2 < 0) {
      bVar1 = 0;
    }
    else {
      lVar2 = ((code)FUN_00493c50)(0xc,0x105,0x46a440,0x469fe0,0x46a040);
      uGpffffba58 = (u32)lVar2;
      if (lVar2 < 0) {
        bVar1 = 0;
      }
      else {
        lVar2 = ((code)FUN_00493c80)(0x105,0x46a230,0x46a0f0,0x46a3c0);
        bVar1 = -1 < lVar2;
      }
    }
  }
  return bVar1;
}

// FUN_0046A600 NONMATCHING

u64 FUN_0046a600(u64 param_1)

{
  if (DAT_0095c448 == 0) {
    ((code)FUN_0046ac30)(0x95c44c);
  }
  DAT_0095c448 = DAT_0095c448 + 1;
  return param_1;
}

// FUN_0046A660 NONMATCHING

u64 FUN_0046a660(u64 param_1)

{
  DAT_0095c448 = DAT_0095c448 + -1;
  if (DAT_0095c448 == 0) {
    ((code)FUN_0046a9e0)(0x95c44c);
  }
  return param_1;
}

#pragma optimization_level 3
// FUN_0046A6C0

u32 FUN_0046a6c0(int param_1,u64 param_2,u64 param_3,u64 param_4)

{
  u32 uVar1;
  
  uVar1 = FUN_0046a890(param_4);
  *(u32 *)(param_1 + 8) = uVar1;
  return 1;
}
#pragma optimization_level 2

#pragma optimization_level 3
// FUN_0046A6F0

u32 FUN_0046a6f0(int param_1,u64 param_2,u64 param_3,u64 param_4)

{
  u32 uVar1;
  
  uVar1 = FUN_0046a890(param_4);
  *(u32 *)(param_1 + 0x6c) = uVar1;
  return 1;
}
#pragma optimization_level 2

#pragma optimization_level 3
// FUN_0046A720

u32 FUN_0046a720(int param_1,u64 param_2,u64 param_3,u64 param_4)

{
  u32 uVar1;
  
  uVar1 = FUN_0046a890(param_4);
  *(u32 *)(param_1 + 0x7c) = uVar1;
  return 1;
}
#pragma optimization_level 2

// FUN_0046A750 NONMATCHING

u32 FUN_0046a750(u64 param_1)

{
  ((code)FUN_0046a970)(0x95c44c,param_1);
  DAT_0095c45c = (u32)param_1;
  DAT_0095c440 = ((code)FUN_004ca520)(0,0x131,0x46a600,0x46a660);
  ((code)FUN_00494db0)(0,0x131,0,0,0);
  ((code)FUN_00492c30)(0,0x131,0,0,0);
  ((code)FUN_00499250)(0,0x131,0,0,0);
  ((code)FUN_00494e10)(0x131,0x46a6c0);
  ((code)FUN_00492ce0)(0x131,0x46a6f0);
  ((code)FUN_004992d0)(0x131,0x46a720);
  return 1;
}

// FUN_0046A830 NONMATCHING

u64 FUN_0046a830(u64 param_1)

{
  u64 uVar1;
  
  uVar1 = 0x95c44c;
  if (DAT_0095c44c == 0) {
    uVar1 = ((code)FUN_0046a970)(0x95c44c,DAT_0095c45c);
  }
  ((code)FUN_0046aa80)(uVar1,param_1);
  return param_1;
}

// FUN_0046A890 NONMATCHING

u32 FUN_0046a890(u64 param_1)

{
  u32 uVar1;
  long lVar2;
  
  lVar2 = ((code)FUN_0046ad20)(0x95c44c,param_1);
  if (lVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(u32 *)((int)lVar2 + 0x10);
  }
  return uVar1;
}

// FUN_0046A8D0 NONMATCHING

void FUN_0046a8d0(int *param_1,int *param_2)

{
  int iVar1;
  u32 uVar2;
  
  if (param_1[3] == 2) {
    if (param_1[1] == 0) {
      *(u32 *)(*param_1 + 0x10) = 0;
    }
    else {
      uVar2 = 0;
      if (param_2[1] != 0) {
        iVar1 = *param_2;
        do {
          if (param_1[1] == *(int *)(iVar1 + 8)) {
            *(u32 *)(*param_1 + 0x10) = *(u32 *)(iVar1 + 0x10);
            break;
          }
          uVar2 = uVar2 + 1;
          iVar1 = iVar1 + 0x14;
        } while (uVar2 < (u32)param_2[1]);
      }
    }
    iVar1 = ((code)FUN_0046afa0)();
    param_1[4] = iVar1;
    *(int *)(param_1[4] + 0x30) = param_1[2];
  }
  return;
}

// FUN_0046A970 NONMATCHING

u64 FUN_0046a970(u64 param_1,int param_2)

{
  u32 uVar1;
  u32 *puVar2;
  
  if (param_2 == 0) {
    param_2 = 9;
  }
  uVar1 = (*DAT_00960178)(param_2 * 0x14,0x1040131);
  puVar2 = (u32 *)param_1;
  *puVar2 = uVar1;
  puVar2[2] = param_2;
  puVar2[1] = 0;
  puVar2[3] = 0;
  return param_1;
}

// FUN_0046A9E0 NONMATCHING

void FUN_0046a9e0(int *param_1)

{
  int iVar1;
  u32 uVar2;
  
  uVar2 = 0;
  if (param_1[1] != 0) {
    iVar1 = 0;
    do {
      if (*(int *)(*param_1 + iVar1 + 0x10) != 0) {
        ((code)FUN_004f3010)();
      }
      uVar2 = uVar2 + 1;
      iVar1 = iVar1 + 0x14;
    } while (uVar2 < (u32)param_1[1]);
  }
  (*DAT_0096017c)(*param_1);
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  param_1[3] = 0;
  return;
}

// FUN_0046AA80 NONMATCHING

u64 FUN_0046aa80(u64 param_1,u32 *param_2)

{
  u32 uVar1;
  u32 uVar2;
  int *piVar3;
  int iVar4;
  u32 uVar5;
  u32 *puVar6;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  uVar5 = 0;
  piVar3 = (int *)param_1;
  uVar1 = piVar3[1];
  if (uVar1 != 0) {
    iVar4 = *piVar3;
    do {
      if (param_2[2] == *(int *)(iVar4 + 8)) break;
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0x14;
    } while (uVar5 < uVar1);
  }
  if (uVar5 < uVar1) {
    uStack_8 = 0x131;
    uStack_4 = ((code)FUN_004c1d10)(2);
    ((code)FUN_004c1c50)(&uStack_8);
    param_1 = 0;
  }
  else {
    if (uVar1 == piVar3[2]) {
      piVar3[2] = piVar3[2] << 1;
      iVar4 = (*DAT_00960180)(*piVar3,piVar3[2] * 0x14,0x1040131);
      *piVar3 = iVar4;
    }
    iVar4 = piVar3[1];
    piVar3[1] = iVar4 + 1;
    puVar6 = (u32 *)(*piVar3 + iVar4 * 0x14);
    puVar6[2] = param_2[2];
    puVar6[3] = param_2[3];
    *puVar6 = *param_2;
    puVar6[1] = param_2[1];
    puVar6[4] = 0;
    if (piVar3[3] != 0) {
      if (puVar6[3] == 2) {
        ((code)FUN_0046a8d0)(puVar6,param_1);
      }
      else if (puVar6[3] == 1) {
        uVar2 = ((code)FUN_0046ad80)(*puVar6);
        puVar6[4] = uVar2;
        *(u32 *)(puVar6[4] + 0x30) = puVar6[2];
      }
      else {
        uStack_10 = 0x131;
        uStack_c = ((code)FUN_004c1d10)();
        ((code)FUN_004c1c50)(&uStack_10);
      }
    }
  }
  return param_1;
}

// FUN_0046AC30 NONMATCHING

u64 FUN_0046ac30(u64 param_1)

{
  u32 uVar1;
  u32 uVar2;
  int *piVar3;
  u32 *puVar4;
  int iVar5;
  u32 uVar6;
  
  piVar3 = (int *)param_1;
  uVar6 = 0;
  uVar2 = 0;
  if (piVar3[1] != 0) {
    iVar5 = 0;
    do {
      puVar4 = (u32 *)(*piVar3 + iVar5);
      if (puVar4[3] == 1) {
        uVar1 = ((code)FUN_0046ad80)(*puVar4);
        puVar4[4] = uVar1;
        *(u32 *)(puVar4[4] + 0x30) = puVar4[2];
      }
      uVar2 = piVar3[1];
      uVar6 = uVar6 + 1;
      iVar5 = iVar5 + 0x14;
    } while (uVar6 < uVar2);
  }
  uVar6 = 0;
  if (uVar2 != 0) {
    iVar5 = 0;
    do {
      ((code)FUN_0046a8d0)(*piVar3 + iVar5,param_1);
      uVar6 = uVar6 + 1;
      iVar5 = iVar5 + 0x14;
    } while (uVar6 < (u32)piVar3[1]);
  }
  piVar3[3] = 1;
  return param_1;
}

// FUN_0046AD20 NONMATCHING

int FUN_0046ad20(int *param_1,int param_2)

{
  int iVar1;
  u32 uVar2;
  
  if (!((u32)param_1[1] > 0)) goto done;
  uVar2 = 0;
  iVar1 = *param_1;
  do {
    if (param_2 == *(int *)(iVar1 + 8)) {
      return *param_1 + uVar2 * 0x14;
    }
    uVar2 = uVar2 + 1;
    iVar1 = iVar1 + 0x14;
  } while (uVar2 < (u32)param_1[1]);
done:
  return 0;
}

// FUN_0046AD80 NONMATCHING

u64 FUN_0046ad80(u32 *param_1)

{
  u64 uVar1;
  u64 uVar2;
  u64 uVar3;
  u64 uVar4;
  u32 *puVar5;
  u32 uVar6;
  u32 uStack_8;
  u32 uStack_4;
  
  uVar1 = ((code)FUN_004f2f70)();
  *(u32 *)((int)uVar1 + 0x2c) = *param_1;
  *(u32 *)((int)uVar1 + 0x30) = param_1[1];
  uVar2 = ((code)FUN_004f4640)(uVar1);
  uVar3 = ((code)FUN_004a3f10)();
  uVar2 = ((code)FUN_004f4950)(uVar2,0,uVar3,0);
  uVar4 = ((code)FUN_004f4830)(uVar2,*(u32 *)uVar3,0,0);
  uVar6 = 0;
  for (puVar5 = param_1; (uVar6 < 10 && (puVar5[2] != 0)); puVar5 = puVar5 + 2) {
    ((code)FUN_004a35c0)(uVar4,puVar5[2],puVar5[3]);
    uVar6 = uVar6 + 1;
  }
  switch(param_1[0x16]) {
  default:
    uStack_8 = 0x131;
    uStack_4 = ((code)FUN_004c1d10)(0);
    ((code)FUN_004c1c50)(&uStack_8);
    break;
  case 1:
  case 2:
    ((code)FUN_004a3a80)(uVar4,param_1[0x17],param_1[0x18],param_1[0x19]);
    break;
  case 3:
  case 4:
  case 5:
    ((code)FUN_004a38f0)(uVar4,param_1[0x17],param_1[0x18],param_1[0x19]);
    break;
  case 6:
    ((code)FUN_004a3c10)(uVar4,param_1[0x17],param_1[0x18]);
  }
  uVar2 = ((code)FUN_004f3f80)(uVar2);
  uVar2 = ((code)FUN_004f4830)(uVar2,*(u32 *)uVar3,0,0);
  uVar2 = ((code)FUN_004a3d70)(uVar2,param_1[0x1a]);
  ((code)FUN_004a3db0)(uVar2,*(u32 *)param_1[0x1b],((u32 *)param_1[0x1b])[1]);
  uVar2 = ((code)FUN_004a3e30)(uVar2,1,param_1[0x1c]);
  uVar2 = ((code)FUN_004a3e30)(uVar2,2,param_1[0x1d]);
  uVar2 = ((code)FUN_004a3e30)(uVar2,3,param_1[0x1e]);
  uVar2 = ((code)FUN_004a3e30)(uVar2,4,param_1[0x1f]);
  ((code)FUN_004a3e30)(uVar2,5,param_1[0x20]);
  return uVar1;
}

// FUN_0046AFA0 NONMATCHING

u64 FUN_0046afa0(u32 *param_1)

{
  u64 uVar1;
  u64 uVar2;
  u64 uVar3;
  
  uVar1 = ((code)FUN_004f2f70)();
  *(u32 *)((int)uVar1 + 0x2c) = *param_1;
  *(u32 *)((int)uVar1 + 0x30) = param_1[1];
  uVar2 = ((code)FUN_004f4640)(uVar1);
  uVar3 = ((code)FUN_0049ff00)();
  uVar2 = ((code)FUN_004f4950)(uVar2,0,uVar3,0);
  uVar2 = ((code)FUN_004f3f80)(uVar2);
  uVar2 = ((code)FUN_004f4830)(uVar2,*(u32 *)uVar3,0,0);
  uVar2 = ((code)FUN_0049fe40)(uVar2,1,param_1[2]);
  uVar2 = ((code)FUN_0049fe40)(uVar2,2,param_1[3]);
  ((code)FUN_0049fec0)(uVar2,param_1[4]);
  return uVar1;
}

// FUN_0046B060 NONMATCHING

int FUN_0046b060(int param_1,u32 *param_2,int param_3)

{
  char *pcVar1;
  u32 uVar2;
  char *pcVar3;
  u32 uVar4;
  u64 uVar5;
  int iVar6;
  u32 *puVar7;
  u32 uVar8;
  u8 auStack_40 [64];
  
  if (param_1 == 0) {
    param_1 = *(int *)(DAT_00960070 + 4);
  }
  pcVar1 = *(char **)(param_3 + 8);
  uVar8 = (u32)DAT_00960078;
  if (((pcVar1 != (char *)pcGpffffba74) || (param_1 != iGpffffba70)) ||
     (iVar6 = iGpffffba70, pcVar3 = (char *)pcGpffffba74, uVar4 = uGpffffba78, uVar8 != uGpffffba78)) {
    uVar5 = ((code)FUN_004cb2f0)(param_1);
    if (*pcVar1 == -1) {
      ((code)FUN_004c32a0)(0x95c460,uVar5);
    }
    else {
      ((code)FUN_004c32a0)(auStack_40,uVar5);
      uVar5 = ((code)FUN_004cb2f0)(*(u32 *)(pcVar1 + 4));
      ((code)FUN_004c2f30)(0x95c460,uVar5,auStack_40);
    }
    iVar6 = param_1;
    pcVar3 = pcVar1;
    uVar4 = uVar8;
    if ((DAT_0095c46c & 3) != 3) {
      thunk_FUN_004c2330(0x95c460,0x95c460);
    }
  }
  uGpffffba78 = uVar4;
  pcGpffffba74 = (u32 *)(pcVar3);
  iGpffffba70 = iVar6;
  iVar6 = 8;
  puVar7 = (u32 *)((u8 *)DAT_0095c460);
  do {
    iVar6 = iVar6 + -1;
    uVar2 = puVar7[1];
    *param_2 = *puVar7;
    puVar7 = puVar7 + 2;
    param_2[1] = uVar2;
    param_2 = param_2 + 2;
  } while (0 < iVar6);
  return param_1;
}

// FUN_0046B1B0 NONMATCHING

void FUN_0046b1b0(u32 *param_1,int param_2,u32 *param_3)

{
  u16 *puVar1;
  u16 uVar2;
  int iVar3;
  int iVar4;
  u8 bVar5;
  int iVar6;
  u16 *puVar7;
  
  puVar7 = (u16 *)*param_1;
  iVar3 = *(int *)(param_2 + 0x18);
  iVar4 = param_1[1];
  iVar6 = 0;
  if (0 < iVar4) {
    if (8 < iVar4) {
      bVar5 = 0;
      if ((-1 < iVar4) && (iVar4 < 0x7fffffff)) {
        bVar5 = 1;
      }
      if (bVar5) {
        do {
          iVar6 = iVar6 + 8;
          *param_3 = *(u32 *)(iVar3 + (u32)*puVar7 * 0x10);
          param_3[1] = *(u32 *)(iVar3 + (u32)*puVar7 * 0x10 + 4);
          param_3[2] = *(u32 *)(iVar3 + (u32)*puVar7 * 0x10 + 8);
          param_3[3] = *(u32 *)(iVar3 + (u32)*puVar7 * 0x10 + 0xc);
          param_3[4] = *(u32 *)(iVar3 + (u32)puVar7[1] * 0x10);
          param_3[5] = *(u32 *)(iVar3 + (u32)puVar7[1] * 0x10 + 4);
          param_3[6] = *(u32 *)(iVar3 + (u32)puVar7[1] * 0x10 + 8);
          param_3[7] = *(u32 *)(iVar3 + (u32)puVar7[1] * 0x10 + 0xc);
          param_3[8] = *(u32 *)(iVar3 + (u32)puVar7[2] * 0x10);
          param_3[9] = *(u32 *)(iVar3 + (u32)puVar7[2] * 0x10 + 4);
          param_3[10] = *(u32 *)(iVar3 + (u32)puVar7[2] * 0x10 + 8);
          param_3[0xb] = *(u32 *)(iVar3 + (u32)puVar7[2] * 0x10 + 0xc);
          param_3[0xc] = *(u32 *)(iVar3 + (u32)puVar7[3] * 0x10);
          param_3[0xd] = *(u32 *)(iVar3 + (u32)puVar7[3] * 0x10 + 4);
          param_3[0xe] = *(u32 *)(iVar3 + (u32)puVar7[3] * 0x10 + 8);
          param_3[0xf] = *(u32 *)(iVar3 + (u32)puVar7[3] * 0x10 + 0xc);
          param_3[0x10] = *(u32 *)(iVar3 + (u32)puVar7[4] * 0x10);
          param_3[0x11] = *(u32 *)(iVar3 + (u32)puVar7[4] * 0x10 + 4);
          param_3[0x12] = *(u32 *)(iVar3 + (u32)puVar7[4] * 0x10 + 8);
          param_3[0x13] = *(u32 *)(iVar3 + (u32)puVar7[4] * 0x10 + 0xc);
          param_3[0x14] = *(u32 *)(iVar3 + (u32)puVar7[5] * 0x10);
          param_3[0x15] = *(u32 *)(iVar3 + (u32)puVar7[5] * 0x10 + 4);
          param_3[0x16] = *(u32 *)(iVar3 + (u32)puVar7[5] * 0x10 + 8);
          param_3[0x17] = *(u32 *)(iVar3 + (u32)puVar7[5] * 0x10 + 0xc);
          param_3[0x18] = *(u32 *)(iVar3 + (u32)puVar7[6] * 0x10);
          param_3[0x19] = *(u32 *)(iVar3 + (u32)puVar7[6] * 0x10 + 4);
          param_3[0x1a] = *(u32 *)(iVar3 + (u32)puVar7[6] * 0x10 + 8);
          param_3[0x1b] = *(u32 *)(iVar3 + (u32)puVar7[6] * 0x10 + 0xc);
          param_3[0x1c] = *(u32 *)(iVar3 + (u32)puVar7[7] * 0x10);
          param_3[0x1d] = *(u32 *)(iVar3 + (u32)puVar7[7] * 0x10 + 4);
          param_3[0x1e] = *(u32 *)(iVar3 + (u32)puVar7[7] * 0x10 + 8);
          puVar1 = puVar7 + 7;
          puVar7 = puVar7 + 8;
          param_3[0x1f] = *(u32 *)(iVar3 + (u32)*puVar1 * 0x10 + 0xc);
          param_3 = param_3 + 0x20;
        } while (iVar6 < iVar4 + -8);
      }
    }
    for (; iVar6 < iVar4; iVar6 = iVar6 + 1) {
      *param_3 = *(u32 *)(iVar3 + (u32)*puVar7 * 0x10);
      param_3[1] = *(u32 *)(iVar3 + (u32)*puVar7 * 0x10 + 4);
      param_3[2] = *(u32 *)(iVar3 + (u32)*puVar7 * 0x10 + 8);
      uVar2 = *puVar7;
      puVar7 = puVar7 + 1;
      param_3[3] = *(u32 *)(iVar3 + (u32)uVar2 * 0x10 + 0xc);
      param_3 = param_3 + 4;
    }
  }
  return;
}

// FUN_0046b510 NONMATCHING
void* FUN_0046b510(int param_1,u64 param_2)


{
  u32 *puVar1;
  u32 uVar2;
  u8 (*pauVar3) [16];
  u8 (*pauVar4) [16];
  u8 (*pauVar5) [16];
  u64 uVar6;
  u8 (*pauVar7) [16];
  u32 uVar8;
  int iVar9;
  Vec128 in_vf0;
  Vec128 auVar10;
  Vec128 auVar11;
  Vec128 auVar12;
  Vec128 auVar13;
  Vec128 auVar14;
  Vec128 auVar15;
  Vec128 auVar16;
  Vec128 auVar17;
  Vec128 auVar18;
  Vec128 auVar19;
  Vec128 auVar20;
  Vec128 auVar21;
  u8 auStack_c0 [12];
  u32 uStack_b4;
  Vec128 auStack_b0;
  Vec128 auStack_a0;
  Vec128 auStack_90;
  Vec128 auStack_80;
  Vec128 auStack_70;
  Vec128 auStack_60;
  Vec128 auStack_50;
  u8 auStack_40 [12];
  u32 uStack_34;
  Vec128 auStack_30;
  Vec128 auStack_20;
  Vec128 auStack_10;
  
  pauVar3 = (u8 (*)[16])DAT_0095de1c;
  puVar1 = *(u32 **)(param_1 + DAT_0095de14);
  if (puVar1 == (u32 *)0x0) {
    uVar2 = *(u32 *)param_2;
    uVar8 = 0;
    pauVar5 = (u8 (*)[16])DAT_0095de1c;
    if (uVar2 != 0) {
      do {
        *(u32 *)(pauVar5[2] + 8) = 0x3f800000;
        uVar8 = uVar8 + 1;
        *(u32 *)(pauVar5[1] + 4) = 0x3f800000;
        *(u32 *)*pauVar5 = 0x3f800000;
        *(u32 *)pauVar5[1] = 0;
        *(u32 *)(*pauVar5 + 8) = 0;
        *(u32 *)(*pauVar5 + 4) = 0;
        *(u32 *)(pauVar5[2] + 4) = 0;
        *(u32 *)pauVar5[2] = 0;
        *(u32 *)(pauVar5[1] + 8) = 0;
        *(u32 *)(pauVar5[3] + 8) = 0;
        *(u32 *)(pauVar5[3] + 4) = 0;
        *(u32 *)pauVar5[3] = 0;
        *(u32 *)(*pauVar5 + 0xc) = *(u32 *)(*pauVar5 + 0xc) | 0x20003;
        pauVar5 = pauVar5 + 4;
      } while (uVar8 < uVar2);
    }
  }
  else {
    uVar2 = puVar1[1];
    pauVar5 = (u8 (*) [16])puVar1[2];
    pauVar4 = (u8 (*) [16])((code)FUN_0048a3e0)(param_2);
    if ((*puVar1 & 2) == 0) {
      if ((*puVar1 & 0x4000) == 0) {
        uStack_b4 = 0;
        uVar6 = ((code)FUN_004cb2f0)(*(u32 *)(param_1 + 4));
        ((code)FUN_004c32a0)(auStack_c0,uVar6);
        auVar10._12_4_ = uStack_b4;
        auVar10._0_4_ = *(u32 *)auStack_c0;
        auVar10._4_4_ = *(u32 *)(auStack_c0 + 4);
        auVar10._8_4_ = *(u32 *)(auStack_c0 + 8);
        auVar10 = _lqc2(auVar10);
        auVar11 = _lqc2(auStack_b0);
        auVar12 = _lqc2(auStack_a0);
        auVar13 = _lqc2(auStack_90);
        pauVar7 = pauVar3;
        do {
          auVar14 = _lqc2(*pauVar4);
          auVar16 = _lqc2(pauVar4[1]);
          auVar18 = _lqc2(pauVar4[2]);
          auVar20 = _lqc2(pauVar4[3]);
          auVar15 = _lqc2(*pauVar5);
          auVar17 = _lqc2(pauVar5[1]);
          auVar19 = _lqc2(pauVar5[2]);
          auVar21 = _lqc2(pauVar5[3]);
          _vmulabc(auVar15,auVar14);
          _vmaddabc(auVar17,auVar14);
          auVar14 = _vmaddbc(auVar19,auVar14);
          _vmulabc(auVar15,auVar16);
          _vmaddabc(auVar17,auVar16);
          auVar16 = _vmaddbc(auVar19,auVar16);
          _vmulabc(auVar15,auVar18);
          _vmaddabc(auVar17,auVar18);
          auVar18 = _vmaddbc(auVar19,auVar18);
          _vmulabc(auVar15,auVar20);
          _vmaddabc(auVar17,auVar20);
          _vmaddabc(auVar19,auVar20);
          auVar20 = _vmaddbc(auVar21,in_vf0);
          _vmulabc(auVar10,auVar14);
          _vmaddabc(auVar11,auVar14);
          auVar14 = _vmaddbc(auVar12,auVar14);
          _vmulabc(auVar10,auVar16);
          _vmaddabc(auVar11,auVar16);
          auVar16 = _vmaddbc(auVar12,auVar16);
          _vmulabc(auVar10,auVar18);
          _vmaddabc(auVar11,auVar18);
          auVar18 = _vmaddbc(auVar12,auVar18);
          _vmulabc(auVar10,auVar20);
          _vmaddabc(auVar11,auVar20);
          _vmaddabc(auVar12,auVar20);
          auVar20 = _vmaddbc(auVar13,in_vf0);
          auVar14 = _sqc2(auVar14);
          *(Vec128 *)pauVar7 = auVar14;
          auVar14 = _sqc2(auVar16);
          ((Vec128 *)pauVar7)[1] = auVar14;
          auVar14 = _sqc2(auVar18);
          ((Vec128 *)pauVar7)[2] = auVar14;
          auVar14 = _sqc2(auVar20);
          ((Vec128 *)pauVar7)[3] = auVar14;
          pauVar7 = pauVar7 + 4;
          pauVar4 = pauVar4 + 4;
          pauVar5 = pauVar5 + 4;
        } while (pauVar3 + uVar2 * 4 != pauVar7);
      }
      else {
        pauVar7 = pauVar3;
        do {
          auVar10 = _lqc2(*pauVar4);
          auVar11 = _lqc2(pauVar4[1]);
          auVar12 = _lqc2(pauVar4[2]);
          auVar13 = _lqc2(pauVar4[3]);
          auVar14 = _lqc2(*pauVar5);
          auVar16 = _lqc2(pauVar5[1]);
          auVar18 = _lqc2(pauVar5[2]);
          auVar20 = _lqc2(pauVar5[3]);
          _vmulabc(auVar14,auVar10);
          _vmaddabc(auVar16,auVar10);
          auVar10 = _vmaddbc(auVar18,auVar10);
          _vmulabc(auVar14,auVar11);
          _vmaddabc(auVar16,auVar11);
          auVar11 = _vmaddbc(auVar18,auVar11);
          _vmulabc(auVar14,auVar12);
          _vmaddabc(auVar16,auVar12);
          auVar12 = _vmaddbc(auVar18,auVar12);
          _vmulabc(auVar14,auVar13);
          _vmaddabc(auVar16,auVar13);
          _vmaddabc(auVar18,auVar13);
          auVar13 = _vmaddbc(auVar20,in_vf0);
          auVar10 = _sqc2(auVar10);
          *(Vec128 *)pauVar7 = auVar10;
          auVar10 = _sqc2(auVar11);
          ((Vec128 *)pauVar7)[1] = auVar10;
          auVar10 = _sqc2(auVar12);
          ((Vec128 *)pauVar7)[2] = auVar10;
          auVar10 = _sqc2(auVar13);
          ((Vec128 *)pauVar7)[3] = auVar10;
          pauVar7 = pauVar7 + 4;
          pauVar4 = pauVar4 + 4;
          pauVar5 = pauVar5 + 4;
        } while (pauVar3 + uVar2 * 4 != pauVar7);
      }
    }
    else {
      uVar8 = puVar1[4];
      uStack_34 = 0;
      auStack_80._12_4_ = 0;
      uVar6 = ((code)FUN_004cb2f0)(*(u32 *)(param_1 + 4));
      ((code)FUN_004c32a0)(auStack_40,uVar6);
      iVar9 = 0;
      if (0 < (int)uVar2) {
        do {
          pauVar5 = (u8 (*) [16])((code)FUN_004cb2f0)(*(u32 *)(uVar8 + iVar9 * 0x10 + 0xc));
          pauVar7 = pauVar4 + iVar9 * 4;
          auVar10 = _lqc2(*pauVar7);
          auVar11 = _lqc2(pauVar7[1]);
          auVar12 = _lqc2(pauVar7[2]);
          auVar13 = _lqc2(pauVar7[3]);
          auVar14 = _lqc2(*pauVar5);
          auVar16 = _lqc2(pauVar5[1]);
          auVar18 = _lqc2(pauVar5[2]);
          auVar20 = _lqc2(pauVar5[3]);
          _vmulabc(auVar14,auVar10);
          _vmaddabc(auVar16,auVar10);
          auVar10 = _vmaddbc(auVar18,auVar10);
          _vmulabc(auVar14,auVar11);
          _vmaddabc(auVar16,auVar11);
          auVar11 = _vmaddbc(auVar18,auVar11);
          _vmulabc(auVar14,auVar12);
          _vmaddabc(auVar16,auVar12);
          auVar12 = _vmaddbc(auVar18,auVar12);
          _vmulabc(auVar14,auVar13);
          _vmaddabc(auVar16,auVar13);
          _vmaddabc(auVar18,auVar13);
          auVar13 = _vmaddbc(auVar20,in_vf0);
          auStack_80 = _sqc2(auVar10);
          auStack_70 = _sqc2(auVar11);
          auStack_60 = _sqc2(auVar12);
          auStack_50 = _sqc2(auVar13);
          pauVar5 = pauVar3 + iVar9 * 4;
          auVar10 = _lqc2(auStack_80);
          auVar12 = _lqc2(auStack_70);
          auVar13 = _lqc2(auStack_60);
          auVar14 = _lqc2(auStack_50);
          auVar11._12_4_ = uStack_34;
          auVar11._0_4_ = *(u32 *)auStack_40;
          auVar11._4_4_ = *(u32 *)(auStack_40 + 4);
          auVar11._8_4_ = *(u32 *)(auStack_40 + 8);
          auVar11 = _lqc2(auVar11);
          auVar16 = _lqc2(auStack_30);
          auVar18 = _lqc2(auStack_20);
          auVar20 = _lqc2(auStack_10);
          _vmulabc(auVar11,auVar10);
          _vmaddabc(auVar16,auVar10);
          auVar10 = _vmaddbc(auVar18,auVar10);
          _vmulabc(auVar11,auVar12);
          _vmaddabc(auVar16,auVar12);
          auVar12 = _vmaddbc(auVar18,auVar12);
          _vmulabc(auVar11,auVar13);
          _vmaddabc(auVar16,auVar13);
          auVar13 = _vmaddbc(auVar18,auVar13);
          _vmulabc(auVar11,auVar14);
          _vmaddabc(auVar16,auVar14);
          _vmaddabc(auVar18,auVar14);
          auVar11 = _vmaddbc(auVar20,in_vf0);
          auVar10 = _sqc2(auVar10);
          *(Vec128 *)pauVar5 = auVar10;
          auVar10 = _sqc2(auVar12);
          ((Vec128 *)pauVar5)[1] = auVar10;
          auVar10 = _sqc2(auVar13);
          ((Vec128 *)pauVar5)[2] = auVar10;
          auVar10 = _sqc2(auVar11);
          ((Vec128 *)pauVar5)[3] = auVar10;
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)uVar2);
      }
    }
  }
  return pauVar3;
}

// FUN_0046B8E0 NONMATCHING

u64 FUN_0046b8e0(int param_1)

{
  u8 bVar1;
  int iVar2;
  Vec128 auVar3;
  u64 uVar4;
  Vec128 auVar5;
  Vec128 auVar6;
  Vec128 auVar7;
  int *piVar8;
  u32 uVar9;
  u64 in_v0_udw;
  int iVar10;
  u8 *pbVar11;
  u32 uVar12;
  u64 in_v1_udw;
  Vec128 auVar13;
  Vec128 auVar14;
  u32 in_a0_udw;
  Vec128 auVar15;
  u32 in_a1_udw;
  u32 uVar16;
  Vec128 auVar17;
  u32 uVar18;
  u64 *puVar19;
  u32 uVar20;
  u32 uVar21;
  u32 *puVar22;
  u32 uVar23;
  u32 uVar24;
  u32 uVar25;
  u32 uVar26;
  u32 uVar27;
  u32 uVar28;
  u32 uVar29;
  u32 uVar30;
  u32 uVar31;
  u32 uVar32;
  u32 uVar33;
  u32 uVar34;
  u32 uVar35;
  
  piVar8 = (int *)(DAT_0095de38);
  iVar10 = *(int *)(param_1 + 0x2c) - (*(int *)(param_1 + 0xc) + 0x10);
  auVar17._0_8_ = (long)-(iVar10 >> 0x1f);
  auVar17._8_8_ = in_v1_udw;
  iVar2 = *DAT_0095de38;
  auVar15._8_8_ = 0;
  auVar15._0_8_ = in_a0_udw;
  auVar15._0_8_ = auVar15._0_8_ << 0x40;
  uVar35 = iVar2 * 4;
  ((code)FUN_004d59d0)(0,uVar35 + 3);
  if (uVar35 + 1 != 0) {
    auVar14._8_8_ = auVar17._8_8_;
    auVar14._0_8_ = (u32)(uVar35 + 1) | 0x10000000;
    auVar5._8_8_ = 0;
    auVar5._0_8_ = auVar15._8_8_;
    auVar15._0_8_ = auVar5._0_8_ << 0x40;
    auVar17 = _pcpyld(auVar15,auVar14);
    *puGpffffbd04 = auVar17._0_4_;
    puGpffffbd04[1] = auVar17._4_4_;
    puGpffffbd04[2] = auVar17._8_4_;
    puGpffffbd04[3] = auVar17._12_4_;
    puGpffffbd04 = puGpffffbd04 + 4;
  }
  auVar13._8_8_ = auVar17._8_8_;
  auVar13._0_8_ = (long)(int)((uVar35 & 0xff) << 0x10) | 0x6c0002bc;
  auVar6._8_8_ = 0;
  auVar6._0_8_ = auVar15._8_8_;
  auVar3._8_8_ = in_v0_udw;
  auVar3._0_8_ = 0x1000101;
  auVar17 = _ppacw(auVar13,auVar3);
  pbVar11 = (u8 *)(piVar8[4] + (iVar10 / 0xc) * 2);
  bVar1 = *pbVar11;
  auVar7._8_8_ = 0;
  auVar7._0_8_ = in_a1_udw;
  auVar15 = _ppacw(auVar7 << 0x40,auVar6 << 0x40);
  uVar35 = (u32)pbVar11[1];
  auVar15 = _ppacw(auVar17,auVar15);
  *puGpffffbd04 = auVar15._0_4_;
  puGpffffbd04[1] = auVar15._4_4_;
  puGpffffbd04[2] = auVar15._8_4_;
  puGpffffbd04[3] = auVar15._12_4_;
  iVar10 = (u32)bVar1 << 1;
  uVar18 = 0;
  if (uVar35 != 0) {
    do {
      uVar12 = (u32)((u8 *)(piVar8[5] + iVar10))[1];
      uVar9 = (u32)*(u8 *)(piVar8[5] + iVar10);
      uVar16 = 0;
      if (uVar12 != 0) {
        do {
          puVar19 = (u64 *)(DAT_0095de1c + (uVar9 + uVar16) * 0x40);
          uVar31 = *(u32 *)(puVar19 + 2);
          uVar32 = *(u32 *)((int)puVar19 + 0x14);
          uVar33 = *(u32 *)(puVar19 + 3);
          uVar34 = *(u32 *)((int)puVar19 + 0x1c);
          uVar27 = *(u32 *)(puVar19 + 4);
          uVar28 = *(u32 *)((int)puVar19 + 0x24);
          uVar29 = *(u32 *)(puVar19 + 5);
          uVar30 = *(u32 *)((int)puVar19 + 0x2c);
          uVar23 = *(u32 *)(puVar19 + 6);
          uVar24 = *(u32 *)((int)puVar19 + 0x34);
          uVar25 = *(u32 *)(puVar19 + 7);
          uVar26 = *(u32 *)((int)puVar19 + 0x3c);
          pbVar11 = (u8 *)(uVar9 + piVar8[3] + uVar16);
          uVar16 = uVar16 + 1;
          uVar4 = *puVar19;
          uVar20 = *(u32 *)(puVar19 + 1);
          uVar21 = *(u32 *)((int)puVar19 + 0xc);
          puVar22 = puGpffffbd04 + (u32)*pbVar11 * 0x10 + 4;
          *puVar22 = (int)uVar4;
          puVar22[1] = (int)((u32)uVar4 >> 0x20);
          puVar22[2] = uVar20;
          puVar22[3] = uVar21;
          puVar22[4] = uVar31;
          puVar22[5] = uVar32;
          puVar22[6] = uVar33;
          puVar22[7] = uVar34;
          puVar22[8] = uVar27;
          puVar22[9] = uVar28;
          puVar22[10] = uVar29;
          puVar22[0xb] = uVar30;
          puVar22[0xc] = uVar23;
          puVar22[0xd] = uVar24;
          puVar22[0xe] = uVar25;
          puVar22[0xf] = uVar26;
        } while (uVar16 < uVar12);
      }
      uVar18 = (u32)((int)uVar18 + 1);
      iVar10 = iVar10 + 2;
    } while (uVar18 < uVar35);
  }
  puGpffffbd04 = puGpffffbd04 + iVar2 * 0x10 + 4;
  return 1;
}

// FUN_0046BAB0 NONMATCHING

long FUN_0046bab0(long param_1,u64 param_2)

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
    DAT_0095ef88 = (u32 *)((int)param_2);
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

// FUN_0046BD00 NONMATCHING

long FUN_0046bd00(long param_1,u64 param_2)

{
  u32 *puVar1;
  u32 uVar2;
  int iVar3;
  int iVar4;
  u16 *puVar5;
  long lVar6;
  u32 uVar7;
  int *piVar8;
  int iVar9;
  u32 uVar10;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (param_1 != 0) {
    iVar9 = (int)param_1;
    if (*(int *)(iVar9 + 8) != 0) {
      lVar6 = param_1;
      if (*(int *)(iVar9 + 0xc) == 0) {
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
      uVar7 = iVar4 - 1;
      if ((int)uVar7 < 3) {
        uVar7 = 3;
      }
      puVar1 = *(u32 **)((int)param_2 + 0x68);
      iVar4 = uVar7 - 1;
      if (puVar1 == (u32 *)0x0) {
        (*DAT_00960090)(1,0);
        fStack_10 = *(float *)(iVar3 + 4);
      }
      else {
        uVar2 = puVar1[0x14];
        uVar10 = (uVar2 & 0xf000) >> 0xc;
        if ((uVar2 & 0xf00) >> 8 != uVar10) {
          uVar10 = 0;
        }
        (*DAT_00960090)(1,*puVar1);
        (*DAT_00960090)(9,uVar2 & 0xff);
        (*DAT_00960090)(2,uVar10);
        fStack_10 = *(float *)(iVar3 + 4);
      }
      fStack_c = *(float *)(iVar3 + 8);
      fStack_8 = fStack_10;
      fStack_4 = fStack_c;
      ((code)FUN_004ac020)(lVar6,&fStack_10);
      DAT_0095efac = fStack_10;
      DAT_0095efb0 = fStack_c;
      DAT_0095efbc = 1.0 / (fStack_8 - fStack_10);
      DAT_0095efc0 = 1.0 / (fStack_4 - fStack_c);
      DAT_0095efa0 = *(u32 *)(iVar9 + 0x10);
      DAT_0095efa4 = 0x3f800000;
      DAT_0095ef88 = (u32 *)((int)param_2);
      puVar5 = (u16 *)((code)FUN_004f2710)();
      if ((uVar7 & 1) != 0) {
        uVar7 = uVar7 + 1;
      }
      DAT_0095ef98 = iVar3;
      DAT_0095ef9c = iVar3 + iVar4 * 0x18;
      DAT_0095efc4 = uVar7;
      *puVar5 = (short)uVar7;
      *(u32 *)(puVar5 + 2) = DAT_0095ed64;
      *(u32 *)(puVar5 + 4) = 0x14;
      lVar6 = ((code)FUN_004f2e70)(DAT_0095f050,puVar5 + 6,0);
      if (lVar6 == 0) {
        return 0;
      }
    }
    ((code)FUN_0046bd00)(*(u32 *)(iVar9 + 0x14),param_2);
  }
  return param_1;
}

// FUN_0046BFB0 NONMATCHING

long FUN_0046bfb0(float param_1,long param_2,u8 *param_3,float *param_4,u32 param_5)

{
  u8 bVar1;
  u8 bVar2;
  u8 bVar3;
  int iVar4;
  u16 *puVar5;
  long lVar6;
  float fVar7;
  int iVar8;
  u32 uVar9;
  u32 uVar10;
  float *pfVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  float fVar15;
  
  if ((param_2 != 0) && (param_3 != (u8 *)0x0)) {
    iVar13 = (int)param_2;
    iVar4 = ((code)FUN_004c2090)(*(u32 *)(iVar13 + 0x134));
    bVar1 = (*(u32 *)(iVar13 + 0x10) & 2) == 0;
    if (bVar1) {
      iVar14 = 1;
      uVar10 = 0;
    }
    else {
      iVar14 = 2;
      uVar10 = 0xff;
    }
    bVar1 = !bVar1;
    ((code)FUN_004aaa60)();
    ((code)FUN_004aae00)(*param_4,param_4[1]);
    ((code)FUN_004aada0)(param_1,param_1);
    ((code)FUN_004aae00)(0,-*(float *)(iVar13 + 8));
    ((code)FUN_004aae60)();
    DAT_0095efa4 = ((code)FUN_004a9560)(0x3f800000,param_2,param_3);
    DAT_0095efa0 = 0;
    fVar15 = 0.0;
    DAT_0095ef88 = (u32 *)(param_5);
    DAT_0095ef8c = (u32 *)(iVar13);
    puVar5 = (u16 *)((code)FUN_004f2710)();
    bVar2 = *param_3;
    iVar12 = 0;
    bVar3 = param_3[bVar1];
    *(u32 *)(puVar5 + 2) = DAT_0095ed64;
    fVar7 = 0.0;
    *(u32 *)(puVar5 + 4) = 0x14;
    DAT_0095efa8 = 0.0;
    uVar9 = (u32)bVar2 | (uVar10 & bVar3) << 8;
    DAT_0095ef94 = (u32)(param_3);
    while (uVar9 != 0) {
      if (uVar9 < 0x80) {
        lVar6 = (long)*(short *)(iVar13 + uVar9 * 2 + 0x24);
      }
      else {
        iVar8 = uVar9 - *(int *)(iVar13 + 0x124);
        if ((iVar8 < 0) || (*(int *)(iVar13 + 0x128) <= iVar8)) {
          lVar6 = -1;
        }
        else {
          lVar6 = (long)*(short *)(*(int *)(iVar13 + 300) + iVar8 * 2);
        }
      }
      if (-1 < lVar6) {
        pfVar11 = (float *)(iVar4 + (int)lVar6 * 0x20);
        if (pfVar11[1] != fVar7) {
          if (fVar7 != 0.0) {
            DAT_0095efc8 = iVar12 / 0xc;
            DAT_0095efc4 = iVar12;
            *puVar5 = (short)iVar12;
            lVar6 = ((code)FUN_004f2e70)(DAT_0095f048,puVar5 + 6,0);
            if (lVar6 == 0) {
              return 0;
            }
            iVar12 = 0;
            DAT_0095ef94 = (u32)(param_3);
            DAT_0095efa8 = fVar15;
          }
          (*DAT_00960090)(9,*(u8 *)((int)pfVar11[1] + 0x50));
          (*DAT_00960090)(1,(u32 *)(int)pfVar11[1]);
          fVar7 = pfVar11[1];
        }
        fVar15 = fVar15 + *pfVar11 + *(float *)(iVar13 + 0xc);
      }
      param_3 = param_3 + iVar14;
      iVar12 = iVar12 + 1;
      uVar9 = (u32)*param_3 | (uVar10 & param_3[bVar1]) << 8;
    }
    if (0 < iVar12) {
      DAT_0095efc8 = iVar12 / 0xc;
      DAT_0095efc4 = iVar12;
      *puVar5 = (short)iVar12;
      lVar6 = ((code)FUN_004f2e70)(DAT_0095f048,puVar5 + 6,0);
      if (lVar6 == 0) {
        return 0;
      }
    }
    *param_4 = fVar15 * param_1 + *param_4 + 0.0;
    ((code)FUN_004aad50)();
  }
  return param_2;
}

// FUN_0046C330 NONMATCHING

u64 FUN_0046c330(u64 param_1,u32 param_2)

{
  int iVar1;
  Vec128 auVar2;
  u64 extraout_v0_udw;
  Vec128 auVar3;
  Vec128 auVar4;
  Vec128 auVar5;
  u32 uVar6;
  u32 *puVar7;
  u32 in_v1_udw;
  u32 in_register_0000003c;
  u32 *puVar8;
  u64 in_a0_udw;
  u32 uVar9;
  u32 uVar10;
  u32 uVar11;
  u32 uVar12;
  
  iVar1 = (int)param_2 * 5;
  ((code)FUN_004d59d0)(0,iVar1 + 2);
  uVar6 = iVar1 + 1;
  auVar3._0_8_ = (u32)uVar6 | 0x10000000;
  auVar3._8_8_ = extraout_v0_udw;
  uVar9 = 0;
  auVar4._8_8_ = in_a0_udw;
  auVar4._0_8_ = (u32)(uVar6 * 0x10000) << 0x20 | 0x6c0002ff01000404;
  auVar4 = _pcpyld(auVar4,auVar3);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar4 + 0));
  DAT_007ce9f4[1] = (*(u32*)((u8*)&auVar4 + 4));
  DAT_007ce9f4[2] = (*(u32*)((u8*)&auVar4 + 8));
  DAT_007ce9f4[3] = (*(u32*)((u8*)&auVar4 + 12));
  auVar5._8_8_ = auVar4._8_8_;
  puVar8 = (u32 *)(DAT_007ce9f4 + 8);
  auVar5._0_8_ = param_2 & 0xffffffff;
  auVar2._4_4_ = in_register_0000003c;
  auVar2._0_4_ = in_v1_udw;
  auVar2._8_8_ = 0;
  auVar4 = _pcpyld(auVar2 << 0x40,auVar5);
  DAT_007ce9f4[4] = (*(u32*)((u8*)&auVar4 + 0));
  DAT_007ce9f4[5] = (*(u32*)((u8*)&auVar4 + 4));
  DAT_007ce9f4[6] = (*(u32*)((u8*)&auVar4 + 8));
  DAT_007ce9f4[7] = (*(u32*)((u8*)&auVar4 + 12));
  if (param_2 != 0) {
    puVar7 = (u32 *)param_1;
    if (8 < param_2) {
      do {
        uVar10 = puVar7[1];
        uVar11 = puVar7[2];
        uVar12 = puVar7[3];
        uVar9 = (u32)((int)uVar9 + 8);
        *puVar8 = *puVar7;
        puVar8[1] = uVar10;
        puVar8[2] = uVar11;
        puVar8[3] = uVar12;
        uVar10 = puVar7[5];
        uVar11 = puVar7[6];
        uVar12 = puVar7[7];
        puVar8[4] = puVar7[4];
        puVar8[5] = uVar10;
        puVar8[6] = uVar11;
        puVar8[7] = uVar12;
        uVar10 = puVar7[9];
        uVar11 = puVar7[10];
        uVar12 = puVar7[0xb];
        puVar8[8] = puVar7[8];
        puVar8[9] = uVar10;
        puVar8[10] = uVar11;
        puVar8[0xb] = uVar12;
        uVar10 = puVar7[0xd];
        uVar11 = puVar7[0xe];
        uVar12 = puVar7[0xf];
        puVar8[0xc] = puVar7[0xc];
        puVar8[0xd] = uVar10;
        puVar8[0xe] = uVar11;
        puVar8[0xf] = uVar12;
        uVar10 = puVar7[0x11];
        uVar11 = puVar7[0x12];
        uVar12 = puVar7[0x13];
        puVar8[0x10] = puVar7[0x10];
        puVar8[0x11] = uVar10;
        puVar8[0x12] = uVar11;
        puVar8[0x13] = uVar12;
        uVar10 = puVar7[0x15];
        uVar11 = puVar7[0x16];
        uVar12 = puVar7[0x17];
        puVar8[0x14] = puVar7[0x14];
        puVar8[0x15] = uVar10;
        puVar8[0x16] = uVar11;
        puVar8[0x17] = uVar12;
        uVar10 = puVar7[0x19];
        uVar11 = puVar7[0x1a];
        uVar12 = puVar7[0x1b];
        puVar8[0x18] = puVar7[0x18];
        puVar8[0x19] = uVar10;
        puVar8[0x1a] = uVar11;
        puVar8[0x1b] = uVar12;
        uVar10 = puVar7[0x1d];
        uVar11 = puVar7[0x1e];
        uVar12 = puVar7[0x1f];
        puVar8[0x1c] = puVar7[0x1c];
        puVar8[0x1d] = uVar10;
        puVar8[0x1e] = uVar11;
        puVar8[0x1f] = uVar12;
        uVar10 = puVar7[0x21];
        uVar11 = puVar7[0x22];
        uVar12 = puVar7[0x23];
        puVar8[0x20] = puVar7[0x20];
        puVar8[0x21] = uVar10;
        puVar8[0x22] = uVar11;
        puVar8[0x23] = uVar12;
        uVar10 = puVar7[0x25];
        uVar11 = puVar7[0x26];
        uVar12 = puVar7[0x27];
        puVar8[0x24] = puVar7[0x24];
        puVar8[0x25] = uVar10;
        puVar8[0x26] = uVar11;
        puVar8[0x27] = uVar12;
        uVar10 = puVar7[0x29];
        uVar11 = puVar7[0x2a];
        uVar12 = puVar7[0x2b];
        puVar8[0x28] = puVar7[0x28];
        puVar8[0x29] = uVar10;
        puVar8[0x2a] = uVar11;
        puVar8[0x2b] = uVar12;
        uVar10 = puVar7[0x2d];
        uVar11 = puVar7[0x2e];
        uVar12 = puVar7[0x2f];
        puVar8[0x2c] = puVar7[0x2c];
        puVar8[0x2d] = uVar10;
        puVar8[0x2e] = uVar11;
        puVar8[0x2f] = uVar12;
        uVar10 = puVar7[0x31];
        uVar11 = puVar7[0x32];
        uVar12 = puVar7[0x33];
        puVar8[0x30] = puVar7[0x30];
        puVar8[0x31] = uVar10;
        puVar8[0x32] = uVar11;
        puVar8[0x33] = uVar12;
        uVar10 = puVar7[0x35];
        uVar11 = puVar7[0x36];
        uVar12 = puVar7[0x37];
        puVar8[0x34] = puVar7[0x34];
        puVar8[0x35] = uVar10;
        puVar8[0x36] = uVar11;
        puVar8[0x37] = uVar12;
        uVar10 = puVar7[0x39];
        uVar11 = puVar7[0x3a];
        uVar12 = puVar7[0x3b];
        puVar8[0x38] = puVar7[0x38];
        puVar8[0x39] = uVar10;
        puVar8[0x3a] = uVar11;
        puVar8[0x3b] = uVar12;
        uVar10 = puVar7[0x3d];
        uVar11 = puVar7[0x3e];
        uVar12 = puVar7[0x3f];
        puVar8[0x3c] = puVar7[0x3c];
        puVar8[0x3d] = uVar10;
        puVar8[0x3e] = uVar11;
        puVar8[0x3f] = uVar12;
        uVar10 = puVar7[0x41];
        uVar11 = puVar7[0x42];
        uVar12 = puVar7[0x43];
        puVar8[0x40] = puVar7[0x40];
        puVar8[0x41] = uVar10;
        puVar8[0x42] = uVar11;
        puVar8[0x43] = uVar12;
        uVar10 = puVar7[0x45];
        uVar11 = puVar7[0x46];
        uVar12 = puVar7[0x47];
        puVar8[0x44] = puVar7[0x44];
        puVar8[0x45] = uVar10;
        puVar8[0x46] = uVar11;
        puVar8[0x47] = uVar12;
        uVar10 = puVar7[0x49];
        uVar11 = puVar7[0x4a];
        uVar12 = puVar7[0x4b];
        puVar8[0x48] = puVar7[0x48];
        puVar8[0x49] = uVar10;
        puVar8[0x4a] = uVar11;
        puVar8[0x4b] = uVar12;
        uVar10 = puVar7[0x4d];
        uVar11 = puVar7[0x4e];
        uVar12 = puVar7[0x4f];
        puVar8[0x4c] = puVar7[0x4c];
        puVar8[0x4d] = uVar10;
        puVar8[0x4e] = uVar11;
        puVar8[0x4f] = uVar12;
        uVar10 = puVar7[0x51];
        uVar11 = puVar7[0x52];
        uVar12 = puVar7[0x53];
        puVar8[0x50] = puVar7[0x50];
        puVar8[0x51] = uVar10;
        puVar8[0x52] = uVar11;
        puVar8[0x53] = uVar12;
        uVar10 = puVar7[0x55];
        uVar11 = puVar7[0x56];
        uVar12 = puVar7[0x57];
        puVar8[0x54] = puVar7[0x54];
        puVar8[0x55] = uVar10;
        puVar8[0x56] = uVar11;
        puVar8[0x57] = uVar12;
        uVar10 = puVar7[0x59];
        uVar11 = puVar7[0x5a];
        uVar12 = puVar7[0x5b];
        puVar8[0x58] = puVar7[0x58];
        puVar8[0x59] = uVar10;
        puVar8[0x5a] = uVar11;
        puVar8[0x5b] = uVar12;
        uVar10 = puVar7[0x5d];
        uVar11 = puVar7[0x5e];
        uVar12 = puVar7[0x5f];
        puVar8[0x5c] = puVar7[0x5c];
        puVar8[0x5d] = uVar10;
        puVar8[0x5e] = uVar11;
        puVar8[0x5f] = uVar12;
        uVar10 = puVar7[0x61];
        uVar11 = puVar7[0x62];
        uVar12 = puVar7[99];
        puVar8[0x60] = puVar7[0x60];
        puVar8[0x61] = uVar10;
        puVar8[0x62] = uVar11;
        puVar8[99] = uVar12;
        uVar10 = puVar7[0x65];
        uVar11 = puVar7[0x66];
        uVar12 = puVar7[0x67];
        puVar8[100] = puVar7[100];
        puVar8[0x65] = uVar10;
        puVar8[0x66] = uVar11;
        puVar8[0x67] = uVar12;
        uVar10 = puVar7[0x69];
        uVar11 = puVar7[0x6a];
        uVar12 = puVar7[0x6b];
        puVar8[0x68] = puVar7[0x68];
        puVar8[0x69] = uVar10;
        puVar8[0x6a] = uVar11;
        puVar8[0x6b] = uVar12;
        uVar10 = puVar7[0x6d];
        uVar11 = puVar7[0x6e];
        uVar12 = puVar7[0x6f];
        puVar8[0x6c] = puVar7[0x6c];
        puVar8[0x6d] = uVar10;
        puVar8[0x6e] = uVar11;
        puVar8[0x6f] = uVar12;
        uVar10 = puVar7[0x71];
        uVar11 = puVar7[0x72];
        uVar12 = puVar7[0x73];
        puVar8[0x70] = puVar7[0x70];
        puVar8[0x71] = uVar10;
        puVar8[0x72] = uVar11;
        puVar8[0x73] = uVar12;
        uVar10 = puVar7[0x75];
        uVar11 = puVar7[0x76];
        uVar12 = puVar7[0x77];
        puVar8[0x74] = puVar7[0x74];
        puVar8[0x75] = uVar10;
        puVar8[0x76] = uVar11;
        puVar8[0x77] = uVar12;
        uVar10 = puVar7[0x79];
        uVar11 = puVar7[0x7a];
        uVar12 = puVar7[0x7b];
        puVar8[0x78] = puVar7[0x78];
        puVar8[0x79] = uVar10;
        puVar8[0x7a] = uVar11;
        puVar8[0x7b] = uVar12;
        uVar10 = puVar7[0x7d];
        uVar11 = puVar7[0x7e];
        uVar12 = puVar7[0x7f];
        puVar8[0x7c] = puVar7[0x7c];
        puVar8[0x7d] = uVar10;
        puVar8[0x7e] = uVar11;
        puVar8[0x7f] = uVar12;
        uVar10 = puVar7[0x81];
        uVar11 = puVar7[0x82];
        uVar12 = puVar7[0x83];
        puVar8[0x80] = puVar7[0x80];
        puVar8[0x81] = uVar10;
        puVar8[0x82] = uVar11;
        puVar8[0x83] = uVar12;
        uVar10 = puVar7[0x85];
        uVar11 = puVar7[0x86];
        uVar12 = puVar7[0x87];
        puVar8[0x84] = puVar7[0x84];
        puVar8[0x85] = uVar10;
        puVar8[0x86] = uVar11;
        puVar8[0x87] = uVar12;
        uVar10 = puVar7[0x89];
        uVar11 = puVar7[0x8a];
        uVar12 = puVar7[0x8b];
        puVar8[0x88] = puVar7[0x88];
        puVar8[0x89] = uVar10;
        puVar8[0x8a] = uVar11;
        puVar8[0x8b] = uVar12;
        uVar10 = puVar7[0x8d];
        uVar11 = puVar7[0x8e];
        uVar12 = puVar7[0x8f];
        puVar8[0x8c] = puVar7[0x8c];
        puVar8[0x8d] = uVar10;
        puVar8[0x8e] = uVar11;
        puVar8[0x8f] = uVar12;
        uVar10 = puVar7[0x91];
        uVar11 = puVar7[0x92];
        uVar12 = puVar7[0x93];
        puVar8[0x90] = puVar7[0x90];
        puVar8[0x91] = uVar10;
        puVar8[0x92] = uVar11;
        puVar8[0x93] = uVar12;
        uVar10 = puVar7[0x95];
        uVar11 = puVar7[0x96];
        uVar12 = puVar7[0x97];
        puVar8[0x94] = puVar7[0x94];
        puVar8[0x95] = uVar10;
        puVar8[0x96] = uVar11;
        puVar8[0x97] = uVar12;
        uVar10 = puVar7[0x99];
        uVar11 = puVar7[0x9a];
        uVar12 = puVar7[0x9b];
        puVar8[0x98] = puVar7[0x98];
        puVar8[0x99] = uVar10;
        puVar8[0x9a] = uVar11;
        puVar8[0x9b] = uVar12;
        uVar10 = puVar7[0x9d];
        uVar11 = puVar7[0x9e];
        uVar12 = puVar7[0x9f];
        puVar8[0x9c] = puVar7[0x9c];
        puVar8[0x9d] = uVar10;
        puVar8[0x9e] = uVar11;
        puVar8[0x9f] = uVar12;
        puVar8 = puVar8 + 0xa0;
        puVar7 = puVar7 + 0xa0;
      } while (uVar9 < (u32)(long)((int)param_2 + -8));
    }
    if (uVar9 < param_2) {
      puVar7 = (u32 *)param_1 + (int)uVar9 * 0x14;
      do {
        uVar10 = puVar7[1];
        uVar11 = puVar7[2];
        uVar12 = puVar7[3];
        uVar9 = (u32)((int)uVar9 + 1);
        *puVar8 = *puVar7;
        puVar8[1] = uVar10;
        puVar8[2] = uVar11;
        puVar8[3] = uVar12;
        uVar10 = puVar7[5];
        uVar11 = puVar7[6];
        uVar12 = puVar7[7];
        puVar8[4] = puVar7[4];
        puVar8[5] = uVar10;
        puVar8[6] = uVar11;
        puVar8[7] = uVar12;
        uVar10 = puVar7[9];
        uVar11 = puVar7[10];
        uVar12 = puVar7[0xb];
        puVar8[8] = puVar7[8];
        puVar8[9] = uVar10;
        puVar8[10] = uVar11;
        puVar8[0xb] = uVar12;
        uVar10 = puVar7[0xd];
        uVar11 = puVar7[0xe];
        uVar12 = puVar7[0xf];
        puVar8[0xc] = puVar7[0xc];
        puVar8[0xd] = uVar10;
        puVar8[0xe] = uVar11;
        puVar8[0xf] = uVar12;
        uVar10 = puVar7[0x11];
        uVar11 = puVar7[0x12];
        uVar12 = puVar7[0x13];
        puVar8[0x10] = puVar7[0x10];
        puVar8[0x11] = uVar10;
        puVar8[0x12] = uVar11;
        puVar8[0x13] = uVar12;
        puVar7 = puVar7 + 0x14;
        puVar8 = puVar8 + 0x14;
      } while (uVar9 < param_2);
    }
  }
  DAT_007ce9f4 = (u32 *)((u32)(puVar8));
  return param_1;
}

// FUN_0046C5B0 NONMATCHING



u64 FUN_0046c5b0(int param_1)

{
  u32 *puVar1;
  u32 *puVar2;
  int *piVar3;
  u32 uVar4;
  u8 bVar5;
  Vec128 auVar6;
  Vec128 auVar7;
  Vec128 auVar8;
  Vec128 auVar9;
  Vec128 auVar10;
  Vec128 auVar11;
  Vec128 auVar12;
  Vec128 auVar13;
  Vec128 auVar14;
  Vec128 auVar15;
  Vec128 auVar16;
  Vec128 auVar17;
  Vec128 auVar18;
  float fVar19;
  u32 in_zero_lo;
  u32 in_zero_hi;
  u32 in_zero_udw;
  u32 in_register_0000000c;
  u32 uVar20;
  u64 extraout_v0_udw;
  Vec128 auVar21;
  Vec128 auVar22;
  Vec128 auVar23;
  Vec128 auVar24;
  u64 extraout_v0_udw_00;
  Vec128 auVar25;
  Vec128 auVar26;
  Vec128 auVar27;
  Vec128 auVar28;
  Vec128 auVar29;
  u8 bVar30;
  u32 *puVar31;
  u32 uVar32;
  u64 in_v1_udw;
  Vec128 auVar33;
  Vec128 auVar34;
  Vec128 auVar35;
  Vec128 auVar36;
  u64 uVar46;
  Vec128 auVar37;
  Vec128 auVar38;
  Vec128 auVar39;
  Vec128 auVar40;
  Vec128 auVar41;
  Vec128 auVar42;
  u32 uVar47;
  Vec128 auVar43;
  Vec128 auVar44;
  Vec128 auVar45;
  u32 in_a0_udw;
  Vec128 auVar48;
  Vec128 auVar49;
  Vec128 auVar50;
  Vec128 auVar51;
  Vec128 auVar52;
  Vec128 auVar53;
  Vec128 auVar54;
  u64 in_a1_udw;
  Vec128 auVar55;
  Vec128 auVar56;
  Vec128 auVar57;
  Vec128 auVar58;
  Vec128 auVar59;
  u64 in_a2_udw;
  Vec128 auVar60;
  Vec128 auVar61;
  Vec128 auVar62;
  u32 in_a3_udw;
  Vec128 auVar63;
  Vec128 auVar64;
  Vec128 auVar65;
  Vec128 auVar66;
  u32 in_t0_udw;
  Vec128 auVar67;
  Vec128 auVar68;
  Vec128 auVar69;
  Vec128 auVar70;
  u64 in_t3_udw;
  Vec128 auVar71;
  Vec128 auVar72;
  u32 in_s1_udw;
  u32 in_register_0000011c;
  u32 *puVar73;
  int iVar74;
  float fVar75;
  u8 auStack_50 [8];
  u32 uStack_48;
  u32 uStack_44;
  u64 uStack_40;
  u32 uStack_38;
  u32 uStack_34;
  u64 uStack_30;
  u32 uStack_28;
  u32 uStack_24;
  float fStack_4;
  
  auVar68._0_8_ = (long)(int)auStack_50;
  auVar68._8_8_ = in_a1_udw;
  puVar1 = *(u32 **)(*(int *)(param_1 + 0x2c) + 8);
  puVar2 = *(u32 **)((int)puVar1 + DAT_007ce738);
  puVar73 = (u32 *)puVar2[1];
  fStack_4 = (float)puVar2[3] * (float)puVar2[4];
  ((code)FUN_0046b060)(*puVar2,auVar68._0_8_);
  fVar75 = *(float *)(DAT_00960070 + 0x84);
  if (fVar75 != DAT_007cdb34) {
    DAT_007cdb30 = 1.0 / (fVar75 - *(float *)(DAT_00960070 + 0x80));
    DAT_007cdb34 = fVar75;
  }
  if (puVar73 == (u32 *)0x0) {
    puVar73 = (u32 *)*puVar1;
  }
  if (puVar73 != (u32 *)0x0) {
    ((code)FUN_004f0f30)(*puVar73);
  }
  uVar32 = auVar68._8_8_;
  *(u32 **)(param_1 + 0x40) = puVar73;
  piVar3 = *(int **)(param_1 + 0x40);
  iVar74 = 0;
  if (piVar3 != (int *)0x0) {
    iVar74 = *piVar3;
  }
  DAT_007ceab8 = 0;
  if (iVar74 != 0) {
    bVar30 = *(u8 *)(iVar74 + 0x23) & 0xf;
    DAT_007ceab8 = (u32)(bVar30 == 1 || bVar30 == 5);
  }
  if (iVar74 != DAT_007ceabc) {
    if (iVar74 == 0) {
      DAT_007cddc0 = DAT_007cddc0 & 0xffffffffffffffef;
    }
    else {
      auVar69._8_8_ = 0;
      auVar69._0_8_ = uVar32;
      auVar68._0_8_ = auVar69._0_8_ << 0x40;
      DAT_007cddc0 = DAT_007cddc0 | 0x10;
      ((code)FUN_004f1020)(iVar74,0);
    }
    uVar32 = auVar68._8_8_;
    DAT_007ceabc = iVar74;
    if (piVar3 != (int *)0x0) {
      ((code)FUN_0049ca50)((char)piVar3[0x14]);
      uVar32 = auVar68._8_8_;
      DAT_007cea58 = (u32)((piVar3[0x14] & 0xf00U) == 0x300);
      if ((piVar3[0x14] & 0xf000U) == 0x3000) {
        DAT_007cea58 = DAT_007cea58 | 4;
      }
    }
  }
  if (DAT_007ceab8 == 0) {
    DAT_007cea40 = DAT_007cea40 & 0xfffffffffffffffe;
  }
  else {
    DAT_007cea40 = DAT_007cea40 | 1;
  }
  ((code)FUN_004d59d0)(0,0x21);
  puVar1 = (u32 *)(DAT_007ce9f4);
  fVar19 = DAT_007cdb34;
  fVar75 = DAT_007cdb30;
  auVar11._8_8_ = 0;
  auVar11._0_8_ = in_a0_udw;
  auVar33._8_8_ = in_v1_udw;
  auVar33._0_8_ = 0x1000001a;
  auVar68 = _pcpyld(auVar11 << 0x40,auVar33);
  auVar48._8_8_ = in_a0_udw;
  auVar48._0_8_ = 0x6c0a03bc;
  auVar34._8_8_ = in_v1_udw;
  auVar34._0_8_ = 0x1000101;
  auVar69 = _ppacw(auVar48,auVar34);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar68 + 0));
  puVar1[1] = auVar68._4_4_;
  puVar1[2] = auVar68._8_4_;
  puVar1[3] = auVar68._12_4_;
  puVar2 = (u32 *)(DAT_007ce9f4);
  auVar67._8_8_ = 0;
  auVar67._0_8_ = auVar68._8_8_;
  auVar12._8_8_ = 0;
  auVar12._0_8_ = in_t0_udw;
  auVar35._4_4_ = 0;
  auVar35._0_4_ = fStack_4;
  auVar35._8_8_ = in_v1_udw;
  auVar68 = _ppacw(auVar67 << 0x40,auVar12 << 0x40);
  auVar67 = _ppacw(auVar69,auVar68);
  DAT_007ce9f4[4] = (*(u32*)((u8*)&auVar67 + 0));
  DAT_007ce9f4[5] = (*(u32*)((u8*)&auVar67 + 4));
  DAT_007ce9f4[6] = (*(u32*)((u8*)&auVar67 + 8));
  DAT_007ce9f4[7] = (*(u32*)((u8*)&auVar67 + 12));
  auVar55._4_4_ = fVar19;
  auVar55._0_4_ = fVar75;
  auVar55._8_8_ = uVar32;
  auVar71._8_8_ = in_t3_udw;
  auVar71._0_8_ = 0x42;
  auVar68 = _pcpyld(auVar55,auVar35);
  DAT_007ce9f4[8] = (*(u32*)((u8*)&auVar68 + 0));
  DAT_007ce9f4[9] = (*(u32*)((u8*)&auVar68 + 4));
  DAT_007ce9f4[10] = (*(u32*)((u8*)&auVar68 + 8));
  DAT_007ce9f4[0xb] = (*(u32*)((u8*)&auVar68 + 12));
  auVar63._8_8_ = in_a3_udw;
  auVar63._0_8_ = 0xe;
  auVar72._8_4_ = in_s1_udw;
  auVar72._0_8_ = 0x1000000000008002;
  auVar72._12_4_ = in_register_0000011c;
  auVar68 = _pcpyld(auVar63,auVar72);
  DAT_007ce9f4[0xc] = (*(u32*)((u8*)&auVar68 + 0));
  DAT_007ce9f4[0xd] = (*(u32*)((u8*)&auVar68 + 4));
  DAT_007ce9f4[0xe] = (*(u32*)((u8*)&auVar68 + 8));
  DAT_007ce9f4[0xf] = (*(u32*)((u8*)&auVar68 + 12));
  auVar70._8_8_ = auVar69._8_8_;
  auVar70._0_8_ = 0x47;
  auVar60._8_8_ = in_a2_udw;
  auVar60._0_8_ = 0x8000000002;
  auVar69 = _pcpyld(auVar71,auVar60);
  DAT_007ce9f4[0x10] = (*(u32*)((u8*)&auVar69 + 0));
  DAT_007ce9f4[0x11] = (*(u32*)((u8*)&auVar69 + 4));
  DAT_007ce9f4[0x12] = (*(u32*)((u8*)&auVar69 + 8));
  DAT_007ce9f4[0x13] = (*(u32*)((u8*)&auVar69 + 12));
  auVar61._8_8_ = auVar69._8_8_;
  auVar64._8_8_ = in_a3_udw;
  auVar64._0_8_ = 0x8000000048;
  auVar49._8_8_ = in_a0_udw;
  auVar49._0_8_ = 0x6c0103fa01000404;
  auVar61._0_8_ = DAT_007cea40 & 0x70000;
  auVar69 = _pcpyld(auVar70,auVar61);
  DAT_007ce9f4[0x14] = (*(u32*)((u8*)&auVar69 + 0));
  DAT_007ce9f4[0x15] = (*(u32*)((u8*)&auVar69 + 4));
  DAT_007ce9f4[0x16] = (*(u32*)((u8*)&auVar69 + 8));
  DAT_007ce9f4[0x17] = (*(u32*)((u8*)&auVar69 + 12));
  auVar72 = _pcpyld(auVar71,auVar64);
  DAT_007ce9f4[0x18] = (*(u32*)((u8*)&auVar68 + 0));
  DAT_007ce9f4[0x19] = (*(u32*)((u8*)&auVar68 + 4));
  DAT_007ce9f4[0x1a] = (*(u32*)((u8*)&auVar68 + 8));
  DAT_007ce9f4[0x1b] = (*(u32*)((u8*)&auVar68 + 12));
  auVar18._8_8_ = 0;
  auVar18._0_8_ = in_a3_udw;
  DAT_007ce9f4[0x1c] = (*(u32*)((u8*)&auVar72 + 0));
  DAT_007ce9f4[0x1d] = (*(u32*)((u8*)&auVar72 + 4));
  DAT_007ce9f4[0x1e] = (*(u32*)((u8*)&auVar72 + 8));
  DAT_007ce9f4[0x1f] = (*(u32*)((u8*)&auVar72 + 12));
  auVar68 = _pcpyld(auVar49,auVar18 << 0x40);
  DAT_007ce9f4[0x20] = (*(u32*)((u8*)&auVar69 + 0));
  DAT_007ce9f4[0x21] = (*(u32*)((u8*)&auVar69 + 4));
  DAT_007ce9f4[0x22] = (*(u32*)((u8*)&auVar69 + 8));
  DAT_007ce9f4[0x23] = (*(u32*)((u8*)&auVar69 + 12));
  DAT_007ce9f4[0x24] = (*(u32*)((u8*)&auStack_50 + 0));
  DAT_007ce9f4[0x25] = (*(u32*)((u8*)&auStack_50 + 4));
  DAT_007ce9f4[0x26] = uStack_48;
  DAT_007ce9f4[0x27] = uStack_44;
  DAT_007ce9f4[0x28] = (int)uStack_40;
  DAT_007ce9f4[0x29] = (int)((u32)uStack_40 >> 0x20);
  DAT_007ce9f4[0x2a] = uStack_38;
  DAT_007ce9f4[0x2b] = uStack_34;
  auVar36._12_4_ = uStack_24;
  auVar36._8_4_ = uStack_28;
  DAT_007ce9f4[0x2c] = (int)uStack_30;
  DAT_007ce9f4[0x2d] = (int)((u32)uStack_30 >> 0x20);
  DAT_007ce9f4[0x2e] = uStack_28;
  DAT_007ce9f4[0x2f] = uStack_24;
  puVar1 = (u32 *)(DAT_007ce9f4 + 0x30);
  DAT_007ce9f4 = DAT_007ce9f4 + 0x30;
  *puVar1 = auVar68._0_4_;
  puVar2[0x31] = auVar68._4_4_;
  puVar2[0x32] = auVar68._8_4_;
  puVar2[0x33] = auVar68._12_4_;
  puVar1 = (u32 *)(DAT_007ce9f4);
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  bVar5 = *(char *)(param_1 + 0x47) != -1;
  DAT_007ceab4 = (u32)bVar5;
  if (bVar5 || DAT_007ceab8 != 0) {
    DAT_007cddc0 = DAT_007cddc0 | 0x40;
  }
  else {
    DAT_007cddc0 = DAT_007cddc0 & 0xffffffffffffffbf;
  }
  auVar50._8_8_ = auVar68._8_8_;
  auVar36._0_8_ = 0xfc007fffffffffff;
  auVar6._4_4_ = in_zero_hi;
  auVar6._0_4_ = in_zero_lo;
  auVar6._8_4_ = in_zero_udw;
  auVar6._12_4_ = in_register_0000000c;
  auVar68 = _pcpyld(auVar6,auVar36);
  uVar46 = auVar68._8_8_;
  auVar62._8_8_ = auVar69._8_8_;
  auVar62._4_4_ = DAT_009658ac;
  auVar62._0_4_ = DAT_009658a8;
  auVar50._0_8_ = 0x6c0103fb01000404;
  uVar32 = DAT_007cddc0 & 0x10;
  auVar65._0_8_ =
       CONCAT44((*(u32*)((u8*)&DAT_009658a0 + 4)),(u32)DAT_009658a0) & (*(u64*)((u8*)&auVar68 + 0)) |
       ((long)(int)((u32)DAT_007cddc0 | (u32)*(u8 *)(param_1 + 0x29)) & 0x7ffU) << 0x2f;
  auVar65._8_8_ = in_a3_udw;
  auVar13._8_8_ = 0;
  auVar13._0_8_ = auVar67._8_8_;
  auVar69 = _pcpyld(auVar62,auVar65);
  (*(u32*)((u8*)&DAT_009658a0 + 0)) = (*(u32*)((u8*)&auVar69 + 0));
  auVar68 = _pcpyld(auVar50,auVar13 << 0x40);
  (*(u32*)((u8*)&DAT_009658a0 + 4)) = (*(u32*)((u8*)&auVar69 + 4));
  DAT_009658a8 = auVar69._8_4_;
  DAT_009658ac = auVar69._12_4_;
  *DAT_007ce9f4 = (u32)DAT_009658a0;
  puVar1[5] = auVar69._4_4_;
  puVar1[6] = auVar69._8_4_;
  puVar1[7] = auVar69._12_4_;
  puVar1[8] = auVar68._0_4_;
  puVar1[9] = auVar68._4_4_;
  puVar1[10] = auVar68._8_4_;
  puVar1[0xb] = auVar68._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 8;
  uVar47 = auVar68._8_8_;
  if (uVar32 == 0) {
    uVar20 = 0x3b808081;
  }
  else {
    uVar20 = 0x3b011b50;
  }
  ((code)FUN_0049cab0)(uVar20,param_1 + 0x44);
  puVar1 = (u32 *)(DAT_007ce9f4);
  auVar14._8_8_ = 0;
  auVar14._0_8_ = uVar47;
  auVar37._8_8_ = uVar46;
  auVar37._0_8_ = 0x6c0103fc01000404;
  auVar68 = _pcpyld(auVar37,auVar14 << 0x40);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar68 + 0));
  puVar1[1] = auVar68._4_4_;
  puVar1[2] = auVar68._8_4_;
  puVar1[3] = auVar68._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  ((code)FUN_0049cbd0)(*(u32 *)(param_1 + 0x1c),*(u32 *)(param_1 + 0x3c));
  puVar1 = (u32 *)(DAT_007ce9f4);
  bVar30 = *(u8 *)(param_1 + 0x28);
  auVar21._8_8_ = extraout_v0_udw;
  auVar21._0_8_ = 0x6c0303fd01000404;
  auVar15._8_8_ = 0;
  auVar15._0_8_ = auVar68._8_8_;
  auVar72 = _pcpyld(auVar21,auVar15 << 0x40);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar72 + 0));
  puVar1[1] = auVar72._4_4_;
  puVar1[2] = auVar72._8_4_;
  puVar1[3] = auVar72._12_4_;
  auVar69 = _DAT_00965930;
  auVar68 = _DAT_00965910;
  puVar1 = (u32 *)(DAT_007ce9f4);
  uVar32 = (u32)bVar30 & 7;
  auVar56._8_8_ = auVar72._8_8_;
  if (((DAT_007ceb04 == 0) || ((bVar30 & 4) != 0)) && ((DAT_007cdde8 == 0 || ((bVar30 & 4) == 0))))
  {
    DAT_007ce9f4[4] = (u32)(DAT_00965910);
    puVar1[5] = auVar68._4_4_;
    puVar1[6] = auVar68._8_4_;
    puVar1[7] = auVar68._12_4_;
    auVar69 = _DAT_00965920;
    puVar1[8] = DAT_00965920;
    puVar1[9] = auVar69._4_4_;
    puVar1[10] = auVar69._8_4_;
    puVar1[0xb] = auVar69._12_4_;
    uVar46 = auVar69._8_8_;
    puVar1 = (u32 *)(DAT_007ce9f4);
  }
  else {
    uVar32 = uVar32 | 8;
    DAT_007ce9f4[4] = (u32)(DAT_00965930);
    puVar1[5] = auVar69._4_4_;
    puVar1[6] = auVar69._8_4_;
    puVar1[7] = auVar69._12_4_;
    auVar68 = _DAT_00965940;
    puVar1[8] = DAT_00965940;
    puVar1[9] = auVar68._4_4_;
    puVar1[10] = auVar68._8_4_;
    puVar1[0xb] = auVar68._12_4_;
    uVar46 = auVar68._8_8_;
    auVar68 = auVar69;
    puVar1 = (u32 *)(DAT_007ce9f4);
  }
  DAT_007ce9f4 = (u32 *)((u32)(puVar1 + 0xc));
  auVar51._8_8_ = auVar68._8_8_;
  DAT_007ceafc = 0;
  uVar47 = 0;
  if (DAT_007ceaac == 3) {
    uVar47 = 0x20;
    DAT_007ceafc = 0x20;
  }
  auVar38._8_8_ = uVar46;
  auVar38._0_8_ = uVar32;
  auVar51._0_8_ = (u32)DAT_007ceb00 << 0x20 | uVar47;
  auVar68 = _pcpyld(auVar51,auVar38);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar68 + 0));
  puVar1[0xd] = auVar68._4_4_;
  puVar1[0xe] = auVar68._8_4_;
  puVar1[0xf] = auVar68._12_4_;
  puVar1 = (u32 *)(DAT_007ce9f4);
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  auVar39._8_8_ = auVar68._8_8_;
  if (*(int *)(param_1 + 0x40) == 0) {
    *DAT_007ce9f4 = in_zero_lo;
    puVar1[5] = in_zero_hi;
    puVar1[6] = in_zero_udw;
    puVar1[7] = in_register_0000000c;
    auVar28._8_8_ = extraout_v0_udw;
    auVar28._0_8_ = 0x5000000200000000;
    auVar10._8_8_ = 0;
    auVar10._0_8_ = auVar39._8_8_;
    puVar1[8] = in_zero_lo;
    puVar1[9] = in_zero_hi;
    puVar1[10] = in_zero_udw;
    puVar1[0xb] = in_register_0000000c;
    auVar68 = _pcpyld(auVar28,auVar10 << 0x40);
    puVar1[0xc] = auVar68._0_4_;
    puVar1[0xd] = auVar68._4_4_;
    puVar1[0xe] = auVar68._8_4_;
    puVar1[0xf] = auVar68._12_4_;
    auVar53._8_8_ = auVar51._8_8_;
    auVar53._0_8_ = 0xe;
    auVar29._8_8_ = auVar68._8_8_;
    auVar45._8_8_ = auVar39._8_8_;
    auVar45._0_8_ = 0x1000000000008001;
    auVar68 = _pcpyld(auVar53,auVar45);
    puVar1[0x10] = auVar68._0_4_;
    puVar1[0x11] = auVar68._4_4_;
    puVar1[0x12] = auVar68._8_4_;
    puVar1[0x13] = auVar68._12_4_;
    auVar29._0_8_ = 0x47;
    auVar40._8_8_ = auVar68._8_8_;
    auVar40._0_8_ = DAT_007cea40;
    auVar68 = _pcpyld(auVar29,auVar40);
    puVar1[0x14] = auVar68._0_4_;
    puVar1[0x15] = auVar68._4_4_;
    puVar1[0x16] = auVar68._8_4_;
    puVar1[0x17] = auVar68._12_4_;
  }
  else {
    auVar8._8_8_ = 0;
    auVar8._0_8_ = auVar39._8_8_;
    auVar22._8_8_ = extraout_v0_udw;
    auVar22._0_8_ = 0x5000000400000000;
    auVar68 = _pcpyld(auVar22,auVar8 << 0x40);
    *DAT_007ce9f4 = (*(u32*)((u8*)&auVar68 + 0));
    puVar1[5] = auVar68._4_4_;
    puVar1[6] = auVar68._8_4_;
    puVar1[7] = auVar68._12_4_;
    auVar56._0_8_ = 0xe;
    auVar23._8_8_ = auVar68._8_8_;
    auVar52._8_8_ = auVar51._8_8_;
    auVar52._0_8_ = 0x47;
    auVar23._0_8_ = 0x1000000000008003;
    auVar68 = _pcpyld(auVar56,auVar23);
    puVar1[8] = auVar68._0_4_;
    puVar1[9] = auVar68._4_4_;
    puVar1[10] = auVar68._8_4_;
    puVar1[0xb] = auVar68._12_4_;
    auVar39._0_8_ = 0x14;
    auVar57._8_8_ = auVar56._8_8_;
    auVar57._0_8_ = DAT_007cea40;
    auVar24._8_8_ = auVar68._8_8_;
    auVar24._0_8_ = 8;
    auVar68 = _pcpyld(auVar52,auVar57);
    puVar1[0xc] = auVar68._0_4_;
    puVar1[0xd] = auVar68._4_4_;
    puVar1[0xe] = auVar68._8_4_;
    puVar1[0xf] = auVar68._12_4_;
    auVar53._8_8_ = auVar68._8_8_;
    auVar53._0_8_ = DAT_007cea60;
    auVar68 = _pcpyld(auVar39,auVar53);
    puVar1[0x10] = auVar68._0_4_;
    puVar1[0x11] = auVar68._4_4_;
    puVar1[0x12] = auVar68._8_4_;
    puVar1[0x13] = auVar68._12_4_;
    auVar40._8_8_ = auVar68._8_8_;
    auVar40._0_8_ = DAT_007cea58;
    auVar68 = _pcpyld(auVar24,auVar40);
    puVar1[0x14] = auVar68._0_4_;
    puVar1[0x15] = auVar68._4_4_;
    puVar1[0x16] = auVar68._8_4_;
    puVar1[0x17] = auVar68._12_4_;
  }
  DAT_007ce9f4 = DAT_007ce9f4 + 0x14;
  auVar42._8_8_ = auVar40._8_8_;
  *(u8 *)(param_1 + 0x2b) =
       (u8)((int)(*(u8 *)(param_1 + 0x28) & 0x20) >> 5) |
       (u8)((int)(*(u8 *)(param_1 + 0x28) & 0x18) >> 2);
  puVar1 = (u32 *)(DAT_007ce9f4);
  uVar32 = auVar53._8_8_;
  puVar31 = (u32 *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + (u32)*(u8 *)(param_1 + 0x2b) * 4);
  auVar42._0_8_ = (long)(int)puVar31;
  uVar4 = *puVar31;
  if (DAT_007ceaf8 != uVar4) {
    auVar9._8_8_ = 0;
    auVar9._0_8_ = auVar56._8_8_;
    auVar41._0_8_ = (u32)uVar4 << 0x20 | 0x50000000;
    auVar41._8_8_ = auVar42._8_8_;
    auVar42 = _pcpyld(auVar9 << 0x40,auVar41);
    *DAT_007ce9f4 = (*(u32*)((u8*)&auVar42 + 0));
    puVar1[1] = auVar42._4_4_;
    puVar1[2] = auVar42._8_4_;
    puVar1[3] = auVar42._12_4_;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    DAT_007ceaf8 = uVar4;
  }
  puVar1 = (u32 *)(DAT_007ce9f4);
  auVar66._8_8_ = auVar65._8_8_;
  uVar47 = auVar42._8_8_;
  iVar74 = **(int **)(param_1 + 0x30);
  auVar66._0_8_ = ((long)*(int *)(*(int *)(param_1 + 4) + 0x14) | 0x2000000U) << 0x20 | 0x3000000;
  auVar58._0_8_ = (u32)*(u32 *)(iVar74 + 0x20) << 0x20 | 0x50000000;
  auVar58._8_8_ = auVar56._8_8_;
  auVar68 = _pcpyld(auVar66,auVar58);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar68 + 0));
  puVar1[1] = auVar68._4_4_;
  puVar1[2] = auVar68._8_4_;
  puVar1[3] = auVar68._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  uVar46 = auVar68._8_8_;
  do {
    DI();
    SYNC(0x10);
  } while ((Status & 0x10000) != 0);
  *(int *)(iVar74 + 0x18) = *(int *)(iVar74 + 0x18) + 1;
  EI();
  *(int *)(iVar74 + 0x1c) = *(int *)(iVar74 + 0x1c) + 1;
  if (*(int *)(iVar74 + 0x1c) == 1) {
    ((code)FUN_004d51c0)();
  }
  ((code)FUN_004d59d0)(0,4);
  puVar1 = (u32 *)(DAT_007ce9f4);
  auVar16._8_8_ = 0;
  auVar16._0_8_ = uVar47;
  auVar25._8_8_ = extraout_v0_udw_00;
  auVar25._0_8_ = 0x50000003;
  auVar17._8_8_ = 0;
  auVar17._0_8_ = uVar32;
  auVar72 = _ppacw(auVar25,auVar16 << 0x40);
  auVar26._8_8_ = extraout_v0_udw_00;
  auVar26._0_8_ = 0xe;
  auVar7._8_4_ = in_s1_udw;
  auVar7._0_8_ = 0x1000000000008002;
  auVar7._12_4_ = in_register_0000011c;
  auVar69 = _pcpyld(auVar26,auVar7);
  auVar27._8_8_ = extraout_v0_udw_00;
  auVar27._0_8_ = 0x10000003;
  auVar59._8_8_ = uVar46;
  auVar59._0_8_ = 0x42;
  auVar68 = _ppacw(auVar17 << 0x40,auVar27);
  auVar68 = _ppacw(auVar72,auVar68);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar68 + 0));
  puVar1[1] = auVar68._4_4_;
  puVar1[2] = auVar68._8_4_;
  puVar1[3] = auVar68._12_4_;
  auVar54._8_8_ = uVar32;
  auVar54._0_8_ = 0x47;
  puVar1[4] = auVar69._0_4_;
  puVar1[5] = auVar69._4_4_;
  puVar1[6] = auVar69._8_4_;
  puVar1[7] = auVar69._12_4_;
  auVar43._8_8_ = uVar47;
  auVar43._0_8_ = DAT_007cea68;
  auVar68 = _pcpyld(auVar59,auVar43);
  puVar1[8] = auVar68._0_4_;
  puVar1[9] = auVar68._4_4_;
  puVar1[10] = auVar68._8_4_;
  puVar1[0xb] = auVar68._12_4_;
  auVar44._8_8_ = auVar68._8_8_;
  auVar44._0_8_ = DAT_007cea40;
  auVar68 = _pcpyld(auVar54,auVar44);
  puVar1[0xc] = auVar68._0_4_;
  puVar1[0xd] = auVar68._4_4_;
  puVar1[0xe] = auVar68._8_4_;
  puVar1[0xf] = auVar68._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 0x10;
  return 1;
}

// FUN_0046CD90 NONMATCHING



u64 FUN_0046cd90(int param_1)

{
  u8 bVar1;
  int *piVar2;
  int *piVar3;
  u32 *puVar4;
  u32 uVar5;
  int iVar6;
  u8 bVar7;
  Vec128 auVar8;
  Vec128 auVar9;
  Vec128 auVar10;
  Vec128 auVar11;
  Vec128 auVar12;
  Vec128 auVar13;
  Vec128 auVar14;
  Vec128 auVar15;
  Vec128 auVar16;
  Vec128 auVar17;
  Vec128 auVar18;
  Vec128 auVar19;
  Vec128 auVar20;
  Vec128 auVar21;
  Vec128 auVar22;
  Vec128 auVar23;
  Vec128 auVar24;
  u32 *puVar25;
  u64 uVar26;
  u32 in_zero_lo;
  u32 in_zero_hi;
  u32 in_zero_udw;
  u32 in_register_0000000c;
  u32 uVar27;
  u64 uVar28;
  u64 extraout_v0_udw;
  Vec128 auVar29;
  Vec128 auVar30;
  Vec128 auVar31;
  Vec128 auVar32;
  u64 extraout_v0_udw_00;
  Vec128 auVar33;
  Vec128 auVar34;
  u64 extraout_v0_udw_01;
  Vec128 auVar35;
  Vec128 auVar36;
  Vec128 auVar37;
  Vec128 auVar38;
  Vec128 auVar39;
  Vec128 auVar40;
  Vec128 auVar41;
  Vec128 auVar42;
  u32 *puVar43;
  u32 uVar44;
  u32 in_v1_udw;
  Vec128 auVar45;
  u64 uVar59;
  Vec128 auVar46;
  Vec128 auVar47;
  Vec128 auVar48;
  Vec128 auVar49;
  Vec128 auVar50;
  Vec128 auVar51;
  Vec128 auVar52;
  Vec128 auVar53;
  Vec128 auVar54;
  Vec128 auVar55;
  Vec128 auVar56;
  Vec128 auVar57;
  Vec128 auVar58;
  u64 in_a0_udw;
  Vec128 auVar60;
  u32 uVar68;
  Vec128 auVar61;
  Vec128 auVar62;
  Vec128 auVar63;
  Vec128 auVar64;
  Vec128 auVar65;
  Vec128 auVar66;
  Vec128 auVar67;
  u64 in_a1_udw;
  Vec128 auVar69;
  Vec128 auVar70;
  Vec128 auVar71;
  u64 uVar76;
  Vec128 auVar72;
  Vec128 auVar73;
  Vec128 auVar74;
  Vec128 auVar75;
  u64 in_a2_udw;
  Vec128 auVar77;
  Vec128 auVar78;
  Vec128 auVar79;
  Vec128 auVar80;
  Vec128 auVar81;
  Vec128 auVar82;
  Vec128 auVar83;
  Vec128 auVar84;
  Vec128 auVar85;
  u64 in_t2_udw;
  Vec128 auVar86;
  Vec128 auVar87;
  Vec128 auVar88;
  Vec128 auVar89;
  Vec128 auVar90;
  u64 in_t4_udw;
  Vec128 auVar91;
  Vec128 auVar92;
  u64 in_t5_udw;
  Vec128 auVar93;
  Vec128 auVar94;
  u64 in_t6_udw;
  u64 in_t7_udw;
  u32 in_s0_udw;
  u32 in_register_0000010c;
  u32 uVar95;
  u32 in_s2_udw;
  u32 in_register_0000012c;
  u32 in_s3_udw;
  u32 in_register_0000013c;
  u32 in_s5_udw;
  u32 in_register_0000015c;
  u32 in_s6_udw;
  u32 in_register_0000016c;
  u32 in_s7_udw;
  u32 in_register_0000017c;
  u32 in_t8_udw;
  u8 auStack_60 [8];
  u32 uStack_58;
  u32 uStack_54;
  u64 uStack_50;
  u32 uStack_48;
  u32 uStack_44;
  u64 uStack_40;
  u32 uStack_38;
  u64 uStack_20;
  u64 uStack_18;
  u64 uStack_10;
  u32 uStack_4;
  
  uVar26 = DAT_007cea30;
  auVar83._0_8_ = (long)(int)auStack_60;
  auVar83._8_8_ = in_a1_udw;
  uVar95 = 0;
  piVar2 = *(int **)(*(int *)(param_1 + 0x2c) + 8);
  uVar5 = (u32)DAT_007cea40;
  piVar3 = (int *)*piVar2;
  puVar4 = *(u32 **)((int)piVar2 + DAT_007ce738);
  uStack_4 = puVar4[2];
  piVar2 = (int *)puVar4[1];
  uVar59 = *(u64 *)(puVar4 + 10);
  uVar76 = *(u64 *)(puVar4 + 0xc);
  uVar28 = *(u64 *)(puVar4 + 0xe);
  uStack_10 = 0;
  ((code)FUN_0046b060)(*puVar4,auVar83._0_8_);
  uStack_18 = 0;
  uStack_20 = 0;
  DAT_007ceab8 = 0;
  if ((piVar3 != (int *)0x0) && (((code)FUN_004f0f30)(*piVar3), (*(u8 *)(*piVar3 + 0x23) & 0xf) != 6)) {
    DAT_007ceab8 = 1;
  }
  uVar44 = auVar83._8_8_;
  if (piVar2 != (int *)0x0) {
    ((code)FUN_004f0f30)(*piVar2);
    uVar44 = auVar83._8_8_;
    ((code)FUN_004f1020)(*piVar2,1);
  }
  if (piVar3 != (int *)0x0) {
    auVar80._8_8_ = 0;
    auVar80._0_8_ = uVar44;
    auVar80._0_8_ = auVar80._0_8_ << 0x40;
    ((code)FUN_004f1020)(*piVar3,0);
    uVar44 = auVar80._8_8_;
  }
  if ((piVar2 != (int *)0x0) && (*(int *)(*piVar2 + DAT_007ceaa8 + 0x58) == 0)) {
    ((code)FUN_004f1020)(*piVar2,1);
  }
  if ((piVar3 != (int *)0x0) && (*(int *)(*piVar3 + DAT_007ceaa8 + 0x58) == 0)) {
    auVar84._8_8_ = 0;
    auVar84._0_8_ = uVar44;
    auVar84._0_8_ = auVar84._0_8_ << 0x40;
    ((code)FUN_004f1020)(*piVar3,0);
    uVar44 = auVar84._8_8_;
  }
  if (piVar3 == (int *)0x0) {
    DAT_007ceabc = 0;
    DAT_007cddc0 = DAT_007cddc0 & 0xffffffffffffffef;
  }
  else {
    DAT_007cddc0 = DAT_007cddc0 | 0x10;
    DAT_007ceabc = *piVar3;
    ((code)FUN_004f1e20)(*piVar3,(int)&uStack_18 + 4,&uStack_18);
    ((code)FUN_004f1e40)(*piVar3,0x7cea60,(char)piVar3[0x14]);
    DAT_007cea58 = (u32)((piVar3[0x14] & 0xf00U) == 0x300);
    if ((piVar3[0x14] & 0xf000U) == 0x3000) {
      DAT_007cea58 = DAT_007cea58 | 4;
    }
  }
  DAT_007cea40 = DAT_007cea40 | 1;
  if (piVar2 != (int *)0x0) {
    ((code)FUN_004f1e20)(*piVar2,(int)&uStack_20 + 4,&uStack_20);
    ((code)FUN_004f1e40)(*piVar2,&uStack_10,(char)piVar2[0x14]);
    uVar95 = (u32)((piVar2[0x14] & 0xf00U) == 0x300);
    if ((piVar2[0x14] & 0xf000U) == 0x3000) {
      uVar95 = uVar95 | 4;
    }
  }
  if ((((piVar3 != (int *)0x0) && (*(int *)(*piVar3 + 0x14) < 9)) && (piVar2 != (int *)0x0)) &&
     (*(int *)(*piVar2 + 0x14) < 9)) {
    DAT_007ceabc = -1;
  }
  ((code)FUN_004d59d0)(0,0x28);
  puVar4 = (u32 *)(DAT_007ce9f4);
  auVar21._8_8_ = 0;
  auVar21._0_8_ = uVar44;
  auVar53._8_8_ = in_v1_udw;
  auVar53._0_8_ = 0x10000022;
  auVar83 = _pcpyld(auVar21 << 0x40,auVar53);
  auVar91._8_8_ = in_t4_udw;
  auVar91._0_8_ = DAT_006b5150;
  auVar73._8_8_ = uVar44;
  auVar73._0_8_ = 0x6c0b03bc;
  auVar35._8_8_ = extraout_v0_udw_01;
  auVar35._0_8_ = 0x1000101;
  auVar80 = _ppacw(auVar73,auVar35);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar83 + 0));
  puVar4[1] = auVar83._4_4_;
  puVar4[2] = auVar83._8_4_;
  puVar4[3] = auVar83._12_4_;
  puVar25 = (u32 *)(DAT_007ce9f4);
  auVar22._8_8_ = 0;
  auVar22._0_8_ = uVar44;
  auVar23._8_8_ = 0;
  auVar23._0_8_ = in_v1_udw;
  auVar84 = _ppacw(auVar22 << 0x40,auVar23 << 0x40);
  auVar74._8_8_ = uVar44;
  auVar74._0_8_ = 0xe;
  auVar83 = _ppacw(auVar80,auVar84);
  DAT_007ce9f4[4] = (*(u32*)((u8*)&auVar83 + 0));
  DAT_007ce9f4[5] = (*(u32*)((u8*)&auVar83 + 4));
  DAT_007ce9f4[6] = (*(u32*)((u8*)&auVar83 + 8));
  DAT_007ce9f4[7] = (*(u32*)((u8*)&auVar83 + 12));
  auVar54._8_8_ = auVar83._8_8_;
  auVar54._0_8_ = 0x3d;
  auVar81._8_8_ = auVar80._8_8_;
  auVar81._0_8_ = 0x1000000000008002;
  auVar80 = _pcpyld(auVar74,auVar81);
  auVar82._8_4_ = in_s5_udw;
  auVar82._0_8_ = uVar76;
  auVar82._12_4_ = in_register_0000015c;
  auVar83 = _pcpyld(auVar54,auVar82);
  DAT_007ce9f4[8] = (*(u32*)((u8*)&auVar80 + 0));
  DAT_007ce9f4[9] = (*(u32*)((u8*)&auVar80 + 4));
  DAT_007ce9f4[10] = (*(u32*)((u8*)&auVar80 + 8));
  DAT_007ce9f4[0xb] = (*(u32*)((u8*)&auVar80 + 12));
  DAT_007ce9f4[0xc] = (*(u32*)((u8*)&auVar83 + 0));
  DAT_007ce9f4[0xd] = (*(u32*)((u8*)&auVar83 + 4));
  DAT_007ce9f4[0xe] = (*(u32*)((u8*)&auVar83 + 8));
  DAT_007ce9f4[0xf] = (*(u32*)((u8*)&auVar83 + 12));
  auVar36._8_8_ = extraout_v0_udw_01;
  auVar36._0_8_ = 7;
  auVar89._8_8_ = auVar83._8_8_;
  auVar93._8_8_ = in_t5_udw;
  auVar93._0_8_ = DAT_006b5158;
  auVar92._8_4_ = in_s5_udw;
  auVar92._0_8_ = uStack_20;
  auVar92._12_4_ = in_register_0000015c;
  auVar83 = _pcpyld(auVar36,auVar92);
  DAT_007ce9f4[0x10] = (*(u32*)((u8*)&auVar83 + 0));
  DAT_007ce9f4[0x11] = (*(u32*)((u8*)&auVar83 + 4));
  DAT_007ce9f4[0x12] = (*(u32*)((u8*)&auVar83 + 8));
  DAT_007ce9f4[0x13] = (*(u32*)((u8*)&auVar83 + 12));
  DAT_007ce9f4[0x14] = (*(u32*)((u8*)&auVar80 + 0));
  DAT_007ce9f4[0x15] = (*(u32*)((u8*)&auVar80 + 4));
  DAT_007ce9f4[0x16] = (*(u32*)((u8*)&auVar80 + 8));
  DAT_007ce9f4[0x17] = (*(u32*)((u8*)&auVar80 + 12));
  auVar37._8_8_ = auVar83._8_8_;
  auVar37._0_8_ = DAT_007cea50;
  auVar89._0_8_ = 0x50000006;
  auVar94._8_8_ = 0;
  auVar94._0_8_ = in_t8_udw;
  auVar80 = _ppacw(auVar89,auVar94 << 0x40);
  auVar83 = _pcpyld(auVar54,auVar37);
  DAT_007ce9f4[0x18] = (*(u32*)((u8*)&auVar83 + 0));
  DAT_007ce9f4[0x19] = (*(u32*)((u8*)&auVar83 + 4));
  DAT_007ce9f4[0x1a] = (*(u32*)((u8*)&auVar83 + 8));
  DAT_007ce9f4[0x1b] = (*(u32*)((u8*)&auVar83 + 12));
  auVar38._8_8_ = auVar37._8_8_;
  auVar38._0_8_ = 0x1000000000008005;
  auVar55._8_8_ = auVar83._8_8_;
  auVar55._0_8_ = uStack_18;
  auVar92 = _pcpyld(auVar93,auVar91);
  auVar94 = _pcpyld(auVar74,auVar38);
  auVar82 = _ppacw(auVar80,auVar84);
  auVar90._8_4_ = in_s3_udw;
  auVar90._0_8_ = 6;
  auVar90._12_4_ = in_register_0000013c;
  auVar83 = _pcpyld(auVar90,auVar55);
  auVar66._8_8_ = in_a0_udw;
  auVar66._0_8_ = 0x43;
  auVar39._8_8_ = auVar37._8_8_;
  auVar39._0_8_ = 9;
  auVar85._8_4_ = in_s0_udw;
  auVar85._0_8_ = uVar59;
  auVar85._12_4_ = in_register_0000010c;
  auVar90 = _pcpyld(auVar66,auVar85);
  DAT_007ce9f4[0x1c] = (*(u32*)((u8*)&auVar83 + 0));
  DAT_007ce9f4[0x1d] = (*(u32*)((u8*)&auVar83 + 4));
  DAT_007ce9f4[0x1e] = (*(u32*)((u8*)&auVar83 + 8));
  DAT_007ce9f4[0x1f] = (*(u32*)((u8*)&auVar83 + 12));
  auVar10._4_4_ = 0;
  auVar10._0_4_ = uVar95;
  auVar10._8_4_ = in_s2_udw;
  auVar10._12_4_ = in_register_0000012c;
  auVar85 = _pcpyld(auVar39,auVar10);
  auVar67._8_8_ = in_a0_udw;
  auVar67._0_8_ = 0x48;
  auVar56._8_8_ = auVar83._8_8_;
  auVar56._0_8_ = 0x4f;
  auVar11._4_4_ = (int)((u32)uVar28 >> 0x20);
  auVar11._0_4_ = uVar5 & 0x70000 | (u32)uVar28;
  auVar11._8_4_ = in_s6_udw;
  auVar11._12_4_ = in_register_0000016c;
  auVar83 = _pcpyld(auVar67,auVar11);
  auVar12._8_4_ = in_s7_udw;
  auVar12._0_8_ = uVar26;
  auVar12._12_4_ = in_register_0000017c;
  auVar84 = _pcpyld(auVar56,auVar12);
  auVar40._8_8_ = auVar37._8_8_;
  auVar40._0_8_ = 0x15;
  auVar57._8_8_ = auVar56._8_8_;
  auVar57._0_8_ = 0x6c0103fa01000404;
  auVar86._0_8_ =
       (((long)(int)(*(u8 *)(param_1 + 0x28) & 1) << 5 | 600U | (u32)*(u8 *)(param_1 + 0x29))
        << 0xf | 0x30004000) << 0x20;
  auVar86._8_8_ = in_t2_udw;
  auVar9._8_8_ = in_t7_udw;
  auVar9._0_8_ = 0x412;
  auVar80 = _pcpyld(auVar9,auVar86);
  DAT_007ce9f4[0x20] = (*(u32*)((u8*)&auVar80 + 0));
  DAT_007ce9f4[0x21] = (*(u32*)((u8*)&auVar80 + 4));
  DAT_007ce9f4[0x22] = (*(u32*)((u8*)&auVar80 + 8));
  DAT_007ce9f4[0x23] = (*(u32*)((u8*)&auVar80 + 12));
  auVar24._4_4_ = in_register_0000013c;
  auVar24._0_4_ = in_s3_udw;
  auVar24._8_8_ = 0;
  auVar80 = _pcpyld(auVar57,auVar24 << 0x40);
  DAT_007ce9f4[0x24] = (*(u32*)((u8*)&auStack_60 + 0));
  DAT_007ce9f4[0x25] = (*(u32*)((u8*)&auStack_60 + 4));
  DAT_007ce9f4[0x26] = uStack_58;
  DAT_007ce9f4[0x27] = uStack_54;
  auVar87._12_4_ = uStack_44;
  auVar87._8_4_ = uStack_48;
  DAT_007ce9f4[0x28] = (int)uStack_50;
  DAT_007ce9f4[0x29] = (int)((u32)uStack_50 >> 0x20);
  DAT_007ce9f4[0x2a] = uStack_48;
  DAT_007ce9f4[0x2b] = uStack_44;
  auVar87._0_8_ = uStack_40;
  auVar88._4_4_ = uStack_4;
  auVar88._0_4_ = uStack_38;
  auVar88._8_8_ = in_t6_udw;
  auVar88 = _pcpyld(auVar88,auVar87);
  DAT_007ce9f4[0x2c] = (*(u32*)((u8*)&auVar88 + 0));
  DAT_007ce9f4[0x2d] = (*(u32*)((u8*)&auVar88 + 4));
  DAT_007ce9f4[0x2e] = (*(u32*)((u8*)&auVar88 + 8));
  DAT_007ce9f4[0x2f] = (*(u32*)((u8*)&auVar88 + 12));
  DAT_007ce9f4[0x30] = (*(u32*)((u8*)&auVar92 + 0));
  DAT_007ce9f4[0x31] = (*(u32*)((u8*)&auVar92 + 4));
  DAT_007ce9f4[0x32] = (*(u32*)((u8*)&auVar92 + 8));
  DAT_007ce9f4[0x33] = (*(u32*)((u8*)&auVar92 + 12));
  DAT_007ce9f4[0x34] = (*(u32*)((u8*)&auVar82 + 0));
  DAT_007ce9f4[0x35] = (*(u32*)((u8*)&auVar82 + 4));
  DAT_007ce9f4[0x36] = (*(u32*)((u8*)&auVar82 + 8));
  DAT_007ce9f4[0x37] = (*(u32*)((u8*)&auVar82 + 12));
  DAT_007ce9f4[0x38] = (*(u32*)((u8*)&auVar94 + 0));
  DAT_007ce9f4[0x39] = (*(u32*)((u8*)&auVar94 + 4));
  DAT_007ce9f4[0x3a] = (*(u32*)((u8*)&auVar94 + 8));
  DAT_007ce9f4[0x3b] = (*(u32*)((u8*)&auVar94 + 12));
  DAT_007ce9f4[0x3c] = (*(u32*)((u8*)&auVar90 + 0));
  DAT_007ce9f4[0x3d] = (*(u32*)((u8*)&auVar90 + 4));
  DAT_007ce9f4[0x3e] = (*(u32*)((u8*)&auVar90 + 8));
  DAT_007ce9f4[0x3f] = (*(u32*)((u8*)&auVar90 + 12));
  DAT_007ce9f4[0x40] = (*(u32*)((u8*)&auVar85 + 0));
  DAT_007ce9f4[0x41] = (*(u32*)((u8*)&auVar85 + 4));
  DAT_007ce9f4[0x42] = (*(u32*)((u8*)&auVar85 + 8));
  DAT_007ce9f4[0x43] = (*(u32*)((u8*)&auVar85 + 12));
  DAT_007ce9f4[0x44] = (*(u32*)((u8*)&auVar83 + 0));
  DAT_007ce9f4[0x45] = (*(u32*)((u8*)&auVar83 + 4));
  DAT_007ce9f4[0x46] = (*(u32*)((u8*)&auVar83 + 8));
  DAT_007ce9f4[0x47] = (*(u32*)((u8*)&auVar83 + 12));
  auVar75._8_8_ = auVar83._8_8_;
  auVar75._0_8_ = uStack_10;
  auVar83 = _pcpyld(auVar40,auVar75);
  DAT_007ce9f4[0x48] = (*(u32*)((u8*)&auVar83 + 0));
  DAT_007ce9f4[0x49] = (*(u32*)((u8*)&auVar83 + 4));
  DAT_007ce9f4[0x4a] = (*(u32*)((u8*)&auVar83 + 8));
  DAT_007ce9f4[0x4b] = (*(u32*)((u8*)&auVar83 + 12));
  DAT_007ce9f4[0x4c] = (*(u32*)((u8*)&auVar84 + 0));
  DAT_007ce9f4[0x4d] = (*(u32*)((u8*)&auVar84 + 4));
  DAT_007ce9f4[0x4e] = (*(u32*)((u8*)&auVar84 + 8));
  DAT_007ce9f4[0x4f] = (*(u32*)((u8*)&auVar84 + 12));
  puVar4 = (u32 *)(DAT_007ce9f4 + 0x50);
  DAT_007ce9f4 = DAT_007ce9f4 + 0x50;
  *puVar4 = auVar80._0_4_;
  puVar25[0x51] = auVar80._4_4_;
  puVar25[0x52] = auVar80._8_4_;
  puVar25[0x53] = auVar80._12_4_;
  puVar4 = (u32 *)(DAT_007ce9f4);
  auVar45._8_8_ = auVar80._8_8_;
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  bVar7 = *(char *)(param_1 + 0x47) != -1;
  DAT_007ceab4 = (u32)bVar7;
  if (bVar7 || DAT_007ceab8 != 0) {
    DAT_007cddc0 = DAT_007cddc0 | 0x40;
  }
  else {
    DAT_007cddc0 = DAT_007cddc0 & 0xffffffffffffffbf;
  }
  auVar78._8_8_ = auVar82._8_8_;
  auVar60._8_8_ = auVar84._8_8_;
  auVar45._0_8_ = 0xfc007fffffffffff;
  auVar8._4_4_ = in_zero_hi;
  auVar8._0_4_ = in_zero_lo;
  auVar8._8_4_ = in_zero_udw;
  auVar8._12_4_ = in_register_0000000c;
  auVar83 = _pcpyld(auVar8,auVar45);
  uVar59 = auVar83._8_8_;
  auVar77._4_4_ = DAT_009658ac;
  auVar77._0_4_ = DAT_009658a8;
  auVar77._8_8_ = in_a2_udw;
  auVar60._0_8_ = 0x6c0103fb01000404;
  uVar44 = DAT_007cddc0 & 0x10;
  auVar78._0_8_ =
       CONCAT44((*(u32*)((u8*)&DAT_009658a0 + 4)),(u32)DAT_009658a0) & (*(u64*)((u8*)&auVar83 + 0)) |
       ((long)(int)((u32)DAT_007cddc0 | (u32)*(u8 *)(param_1 + 0x29)) & 0x7ffU) << 0x2f;
  auVar17._8_8_ = 0;
  auVar17._0_8_ = auVar85._8_8_;
  auVar80 = _pcpyld(auVar77,auVar78);
  (*(u32*)((u8*)&DAT_009658a0 + 0)) = (*(u32*)((u8*)&auVar80 + 0));
  auVar83 = _pcpyld(auVar60,auVar17 << 0x40);
  (*(u32*)((u8*)&DAT_009658a0 + 4)) = (*(u32*)((u8*)&auVar80 + 4));
  DAT_009658a8 = auVar80._8_4_;
  DAT_009658ac = auVar80._12_4_;
  *DAT_007ce9f4 = (u32)DAT_009658a0;
  puVar4[5] = auVar80._4_4_;
  puVar4[6] = auVar80._8_4_;
  puVar4[7] = auVar80._12_4_;
  puVar4[8] = auVar83._0_4_;
  puVar4[9] = auVar83._4_4_;
  puVar4[10] = auVar83._8_4_;
  puVar4[0xb] = auVar83._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 8;
  uVar68 = auVar83._8_8_;
  if (uVar44 == 0) {
    uVar27 = 0x3b808081;
  }
  else {
    uVar27 = 0x3b011b50;
  }
  ((code)FUN_0049cab0)(uVar27,param_1 + 0x44);
  puVar4 = (u32 *)(DAT_007ce9f4);
  auVar18._8_8_ = 0;
  auVar18._0_8_ = uVar68;
  auVar46._8_8_ = uVar59;
  auVar46._0_8_ = 0x6c0103fc01000404;
  auVar83 = _pcpyld(auVar46,auVar18 << 0x40);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar83 + 0));
  puVar4[1] = auVar83._4_4_;
  puVar4[2] = auVar83._8_4_;
  puVar4[3] = auVar83._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  ((code)FUN_0049cbd0)(*(u32 *)(param_1 + 0x1c),*(u32 *)(param_1 + 0x3c));
  puVar4 = (u32 *)(DAT_007ce9f4);
  bVar1 = *(u8 *)(param_1 + 0x28);
  auVar29._8_8_ = extraout_v0_udw;
  auVar29._0_8_ = 0x6c0303fd01000404;
  auVar19._8_8_ = 0;
  auVar19._0_8_ = auVar83._8_8_;
  auVar84 = _pcpyld(auVar29,auVar19 << 0x40);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar84 + 0));
  puVar4[1] = auVar84._4_4_;
  puVar4[2] = auVar84._8_4_;
  puVar4[3] = auVar84._12_4_;
  auVar80 = _DAT_00965930;
  auVar83 = _DAT_00965910;
  puVar4 = (u32 *)(DAT_007ce9f4);
  uVar44 = (u32)bVar1 & 7;
  auVar69._8_8_ = auVar84._8_8_;
  if (((DAT_007ceb04 == 0) || ((bVar1 & 4) != 0)) && ((DAT_007cdde8 == 0 || ((bVar1 & 4) == 0)))) {
    DAT_007ce9f4[4] = (u32)(DAT_00965910);
    puVar4[5] = auVar83._4_4_;
    puVar4[6] = auVar83._8_4_;
    puVar4[7] = auVar83._12_4_;
    auVar80 = _DAT_00965920;
    puVar4[8] = DAT_00965920;
    puVar4[9] = auVar80._4_4_;
    puVar4[10] = auVar80._8_4_;
    puVar4[0xb] = auVar80._12_4_;
    uVar59 = auVar80._8_8_;
    puVar4 = (u32 *)(DAT_007ce9f4);
  }
  else {
    uVar44 = uVar44 | 8;
    DAT_007ce9f4[4] = (u32)(DAT_00965930);
    puVar4[5] = auVar80._4_4_;
    puVar4[6] = auVar80._8_4_;
    puVar4[7] = auVar80._12_4_;
    auVar83 = _DAT_00965940;
    puVar4[8] = DAT_00965940;
    puVar4[9] = auVar83._4_4_;
    puVar4[10] = auVar83._8_4_;
    puVar4[0xb] = auVar83._12_4_;
    uVar59 = auVar83._8_8_;
    auVar83 = auVar80;
    puVar4 = (u32 *)(DAT_007ce9f4);
  }
  DAT_007ce9f4 = (u32 *)((u32)(puVar4 + 0xc));
  auVar61._8_8_ = auVar83._8_8_;
  DAT_007ceafc = 0;
  uVar68 = 0;
  if (DAT_007ceaac == 3) {
    uVar68 = 0x20;
    DAT_007ceafc = 0x20;
  }
  auVar47._8_8_ = uVar59;
  auVar47._0_8_ = uVar44;
  auVar61._0_8_ = (u32)DAT_007ceb00 << 0x20 | uVar68;
  auVar83 = _pcpyld(auVar61,auVar47);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar83 + 0));
  puVar4[0xd] = auVar83._4_4_;
  puVar4[0xe] = auVar83._8_4_;
  puVar4[0xf] = auVar83._12_4_;
  puVar4 = (u32 *)(DAT_007ce9f4);
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  auVar48._8_8_ = auVar83._8_8_;
  if (*(int *)(param_1 + 0x40) == 0) {
    auVar70._0_8_ = (long)(int)DAT_007ce9f4;
    auVar70._8_8_ = auVar69._8_8_;
    *DAT_007ce9f4 = in_zero_lo;
    puVar4[5] = in_zero_hi;
    puVar4[6] = in_zero_udw;
    puVar4[7] = in_register_0000000c;
    auVar41._8_8_ = extraout_v0_udw;
    auVar41._0_8_ = 0x5000000200000000;
    auVar16._8_8_ = 0;
    auVar16._0_8_ = auVar48._8_8_;
    puVar4[8] = in_zero_lo;
    puVar4[9] = in_zero_hi;
    puVar4[10] = in_zero_udw;
    puVar4[0xb] = in_register_0000000c;
    auVar83 = _pcpyld(auVar41,auVar16 << 0x40);
    puVar4[0xc] = auVar83._0_4_;
    puVar4[0xd] = auVar83._4_4_;
    puVar4[0xe] = auVar83._8_4_;
    puVar4[0xf] = auVar83._12_4_;
    auVar63._8_8_ = auVar61._8_8_;
    auVar63._0_8_ = 0xe;
    auVar42._8_8_ = auVar83._8_8_;
    auVar58._8_8_ = auVar48._8_8_;
    auVar58._0_8_ = 0x1000000000008001;
    auVar83 = _pcpyld(auVar63,auVar58);
    puVar4[0x10] = auVar83._0_4_;
    puVar4[0x11] = auVar83._4_4_;
    puVar4[0x12] = auVar83._8_4_;
    puVar4[0x13] = auVar83._12_4_;
    auVar42._0_8_ = 0x47;
    auVar49._8_8_ = auVar83._8_8_;
    auVar49._0_8_ = DAT_007cea40;
    auVar83 = _pcpyld(auVar42,auVar49);
    puVar4[0x14] = auVar83._0_4_;
    puVar4[0x15] = auVar83._4_4_;
    puVar4[0x16] = auVar83._8_4_;
    puVar4[0x17] = auVar83._12_4_;
  }
  else {
    auVar13._8_8_ = 0;
    auVar13._0_8_ = auVar48._8_8_;
    auVar30._8_8_ = extraout_v0_udw;
    auVar30._0_8_ = 0x5000000400000000;
    auVar83 = _pcpyld(auVar30,auVar13 << 0x40);
    *DAT_007ce9f4 = (*(u32*)((u8*)&auVar83 + 0));
    puVar4[5] = auVar83._4_4_;
    puVar4[6] = auVar83._8_4_;
    puVar4[7] = auVar83._12_4_;
    auVar69._0_8_ = 0xe;
    auVar31._8_8_ = auVar83._8_8_;
    auVar62._8_8_ = auVar61._8_8_;
    auVar62._0_8_ = 0x47;
    auVar31._0_8_ = 0x1000000000008003;
    auVar83 = _pcpyld(auVar69,auVar31);
    puVar4[8] = auVar83._0_4_;
    puVar4[9] = auVar83._4_4_;
    puVar4[10] = auVar83._8_4_;
    puVar4[0xb] = auVar83._12_4_;
    auVar48._0_8_ = 0x14;
    auVar70._8_8_ = auVar69._8_8_;
    auVar70._0_8_ = DAT_007cea40;
    auVar32._8_8_ = auVar83._8_8_;
    auVar32._0_8_ = 8;
    auVar83 = _pcpyld(auVar62,auVar70);
    puVar4[0xc] = auVar83._0_4_;
    puVar4[0xd] = auVar83._4_4_;
    puVar4[0xe] = auVar83._8_4_;
    puVar4[0xf] = auVar83._12_4_;
    auVar63._8_8_ = auVar83._8_8_;
    auVar63._0_8_ = DAT_007cea60;
    auVar83 = _pcpyld(auVar48,auVar63);
    puVar4[0x10] = auVar83._0_4_;
    puVar4[0x11] = auVar83._4_4_;
    puVar4[0x12] = auVar83._8_4_;
    puVar4[0x13] = auVar83._12_4_;
    auVar49._8_8_ = auVar83._8_8_;
    auVar49._0_8_ = DAT_007cea58;
    auVar83 = _pcpyld(auVar32,auVar49);
    puVar4[0x14] = auVar83._0_4_;
    puVar4[0x15] = auVar83._4_4_;
    puVar4[0x16] = auVar83._8_4_;
    puVar4[0x17] = auVar83._12_4_;
  }
  DAT_007ce9f4 = DAT_007ce9f4 + 0x14;
  auVar51._8_8_ = auVar49._8_8_;
  *(u8 *)(param_1 + 0x2b) =
       (u8)((int)(*(u8 *)(param_1 + 0x28) & 0x20) >> 5) |
       (u8)((int)(*(u8 *)(param_1 + 0x28) & 0x18) >> 2);
  puVar4 = (u32 *)(DAT_007ce9f4);
  uVar59 = auVar63._8_8_;
  puVar43 = (u32 *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + (u32)*(u8 *)(param_1 + 0x2b) * 4);
  auVar51._0_8_ = (long)(int)puVar43;
  uVar5 = *puVar43;
  if (DAT_007ceaf8 != uVar5) {
    auVar14._8_8_ = 0;
    auVar14._0_8_ = auVar70._8_8_;
    auVar70._0_8_ = auVar14._0_8_ << 0x40;
    auVar50._0_8_ = (u32)uVar5 << 0x20 | 0x50000000;
    auVar50._8_8_ = auVar51._8_8_;
    auVar51 = _pcpyld(auVar70,auVar50);
    *DAT_007ce9f4 = (*(u32*)((u8*)&auVar51 + 0));
    puVar4[1] = auVar51._4_4_;
    puVar4[2] = auVar51._8_4_;
    puVar4[3] = auVar51._12_4_;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    DAT_007ceaf8 = uVar5;
  }
  puVar4 = (u32 *)(DAT_007ce9f4);
  auVar79._8_8_ = auVar78._8_8_;
  uVar44 = auVar51._8_8_;
  auVar71._8_8_ = auVar70._8_8_;
  iVar6 = **(int **)(param_1 + 0x30);
  auVar79._0_8_ = ((long)*(int *)(*(int *)(param_1 + 4) + 0x14) | 0x2000000U) << 0x20 | 0x3000000;
  auVar71._0_8_ = (u32)*(u32 *)(iVar6 + 0x20) << 0x20 | 0x50000000;
  auVar83 = _pcpyld(auVar79,auVar71);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar83 + 0));
  puVar4[1] = auVar83._4_4_;
  puVar4[2] = auVar83._8_4_;
  puVar4[3] = auVar83._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  do {
    DI();
    SYNC(0x10);
  } while ((Status & 0x10000) != 0);
  *(int *)(iVar6 + 0x18) = *(int *)(iVar6 + 0x18) + 1;
  EI();
  *(int *)(iVar6 + 0x1c) = *(int *)(iVar6 + 0x1c) + 1;
  if (*(int *)(iVar6 + 0x1c) == 1) {
    ((code)FUN_004d51c0)();
  }
  uVar76 = auVar83._8_8_;
  ((code)FUN_004d59d0)(0,3);
  puVar4 = (u32 *)(DAT_007ce9f4);
  auVar20._8_8_ = 0;
  auVar20._0_8_ = uVar44;
  auVar33._8_8_ = extraout_v0_udw_00;
  auVar33._0_8_ = 0x50000002;
  auVar15._8_8_ = 0;
  auVar15._0_8_ = auVar79._8_8_;
  auVar80 = _ppacw(auVar33,auVar20 << 0x40);
  auVar72._8_8_ = uVar76;
  auVar72._0_8_ = 0xe;
  auVar64._8_8_ = uVar59;
  auVar64._0_8_ = 0x10000002;
  auVar83 = _ppacw(auVar15 << 0x40,auVar64);
  auVar83 = _ppacw(auVar80,auVar83);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar83 + 0));
  puVar4[1] = auVar83._4_4_;
  puVar4[2] = auVar83._8_4_;
  puVar4[3] = auVar83._12_4_;
  auVar65._8_8_ = uVar59;
  auVar65._0_8_ = 0x3d;
  auVar34._8_8_ = auVar83._8_8_;
  auVar34._0_8_ = 0x1000000000008001;
  auVar83 = _pcpyld(auVar72,auVar34);
  puVar4[4] = auVar83._0_4_;
  puVar4[5] = auVar83._4_4_;
  puVar4[6] = auVar83._8_4_;
  puVar4[7] = auVar83._12_4_;
  auVar52._8_8_ = uVar44;
  auVar52._0_8_ = DAT_007cea50;
  auVar83 = _pcpyld(auVar65,auVar52);
  puVar4[8] = auVar83._0_4_;
  puVar4[9] = auVar83._4_4_;
  puVar4[10] = auVar83._8_4_;
  puVar4[0xb] = auVar83._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 0xc;
  return 1;
}

// FUN_0046D6F0 NONMATCHING



u64 FUN_0046d6f0(int param_1)

{
  u8 bVar1;
  u32 *puVar2;
  u32 *puVar3;
  int *piVar4;
  u32 uVar5;
  int iVar6;
  u8 bVar7;
  Vec128 auVar8;
  Vec128 auVar9;
  Vec128 auVar10;
  Vec128 auVar11;
  Vec128 auVar12;
  Vec128 auVar13;
  Vec128 auVar14;
  Vec128 auVar15;
  Vec128 auVar16;
  Vec128 auVar17;
  Vec128 auVar18;
  Vec128 auVar19;
  Vec128 auVar20;
  Vec128 auVar21;
  Vec128 auVar22;
  Vec128 auVar23;
  u32 in_zero_lo;
  u32 in_zero_hi;
  u32 in_zero_udw;
  u32 in_register_0000000c;
  u32 uVar24;
  u64 uVar25;
  u64 extraout_v0_udw;
  Vec128 auVar26;
  Vec128 auVar27;
  Vec128 auVar28;
  Vec128 auVar29;
  u64 extraout_v0_udw_00;
  Vec128 auVar30;
  Vec128 auVar31;
  u32 extraout_v0_udw_01;
  Vec128 auVar32;
  Vec128 auVar33;
  Vec128 auVar34;
  Vec128 auVar35;
  Vec128 auVar36;
  Vec128 auVar37;
  Vec128 auVar38;
  u32 *puVar39;
  u32 uVar40;
  u64 in_v1_udw;
  Vec128 auVar41;
  u64 uVar54;
  Vec128 auVar42;
  u64 uVar55;
  Vec128 auVar43;
  Vec128 auVar44;
  Vec128 auVar45;
  Vec128 auVar46;
  Vec128 auVar47;
  Vec128 auVar48;
  Vec128 auVar49;
  Vec128 auVar50;
  Vec128 auVar51;
  Vec128 auVar52;
  Vec128 auVar53;
  u64 in_a0_udw;
  Vec128 auVar56;
  Vec128 auVar57;
  Vec128 auVar58;
  Vec128 auVar59;
  Vec128 auVar60;
  Vec128 auVar61;
  Vec128 auVar62;
  Vec128 auVar63;
  Vec128 auVar64;
  Vec128 auVar65;
  u64 in_a1_udw;
  Vec128 auVar66;
  Vec128 auVar67;
  Vec128 auVar68;
  Vec128 auVar69;
  Vec128 auVar70;
  Vec128 auVar71;
  u64 in_a2_udw;
  Vec128 auVar72;
  Vec128 auVar73;
  u32 uVar79;
  Vec128 auVar74;
  Vec128 auVar75;
  Vec128 auVar76;
  Vec128 auVar77;
  Vec128 auVar78;
  u64 in_a3_udw;
  Vec128 auVar80;
  Vec128 auVar81;
  Vec128 auVar82;
  Vec128 auVar83;
  Vec128 auVar84;
  Vec128 auVar85;
  Vec128 auVar86;
  u32 in_t0_udw;
  Vec128 auVar87;
  Vec128 auVar88;
  Vec128 auVar89;
  Vec128 auVar90;
  Vec128 auVar91;
  Vec128 auVar92;
  Vec128 auVar93;
  Vec128 auVar94;
  Vec128 auVar95;
  Vec128 auVar96;
  u64 in_t5_udw;
  Vec128 auVar97;
  Vec128 auVar98;
  Vec128 auVar99;
  u64 in_t6_udw;
  Vec128 auVar100;
  Vec128 auVar101;
  u64 in_t7_udw;
  Vec128 auVar102;
  Vec128 auVar103;
  Vec128 auVar104;
  Vec128 auVar105;
  u32 uVar106;
  u32 in_s1_udw;
  u32 in_register_0000011c;
  u32 in_s2_udw;
  u32 in_register_0000012c;
  int *piVar107;
  u32 in_s3_udw;
  u32 in_register_0000013c;
  u32 in_s5_udw;
  u32 in_register_0000015c;
  u8 in_s6_qw [16];
  Vec128 auVar108;
  u32 in_s7_udw;
  u32 in_register_0000017c;
  u64 in_t8_udw;
  u64 in_t9_udw;
  u32 in_s8_udw;
  u32 in_register_000001ec;
  float fVar109;
  u8 auStack_a0 [8];
  u32 uStack_98;
  u32 uStack_94;
  u64 uStack_90;
  u32 uStack_88;
  u32 uStack_84;
  u64 uStack_80;
  u32 uStack_78;
  u8 auStack_60 [8];
  u32 uStack_58;
  u32 uStack_54;
  u64 uStack_50;
  u32 uStack_48;
  u32 uStack_44;
  u64 uStack_40;
  u32 uStack_38;
  u32 uStack_34;
  u64 uStack_20;
  u64 uStack_18;
  u64 uStack_10;
  float fStack_8;
  u32 uStack_4;
  
  uVar55 = DAT_007cea30;
  puVar2 = *(u32 **)(*(int *)(param_1 + 0x2c) + 8);
  puVar3 = *(u32 **)((int)puVar2 + DAT_007ce738);
  piVar107 = (int *)puVar3[1];
  fStack_8 = (float)puVar3[3] * (float)puVar3[4];
  if (piVar107 == (int *)0x0) {
    piVar107 = (int *)*puVar2;
  }
  uStack_4 = puVar3[0x12];
  piVar4 = (int *)puVar3[0x11];
  uVar24 = puVar3[0x10];
  uVar54 = *(u64 *)(puVar3 + 0x1a);
  (*(u64*)((u8*)&auVar65 + 8)) = (*(u64*)((u8*)&in_s6_qw + 8));
  auVar65._0_8_ = *(u64 *)(puVar3 + 0x1c);
  uVar106 = 0;
  uVar25 = *(u64 *)(puVar3 + 0x1e);
  uVar5 = (u32)DAT_007cea40;
  uStack_10 = 0;
  ((code)FUN_0046b060)(*puVar3,auStack_60);
  auVar94._0_8_ = (long)(int)auStack_a0;
  auVar94._8_8_ = in_a1_udw;
  ((code)FUN_0046b060)(uVar24,auVar94._0_8_);
  fVar109 = *(float *)(DAT_00960070 + 0x84);
  if (fVar109 != DAT_007cdb3c) {
    DAT_007cdb38 = 1.0 / (fVar109 - *(float *)(DAT_00960070 + 0x80));
    DAT_007cdb3c = fVar109;
  }
  uStack_18 = 0;
  uStack_20 = 0;
  DAT_007ceab8 = 0;
  if ((piVar107 != (int *)0x0) &&
     (((code)FUN_004f0f30)(*piVar107), (*(u8 *)(*piVar107 + 0x23) & 0xf) != 6)) {
    DAT_007ceab8 = 1;
  }
  uVar40 = auVar94._8_8_;
  if (piVar4 != (int *)0x0) {
    ((code)FUN_004f0f30)(*piVar4);
    uVar40 = auVar94._8_8_;
    ((code)FUN_004f1020)(*piVar4,1);
  }
  if (piVar107 != (int *)0x0) {
    auVar87._8_8_ = 0;
    auVar87._0_8_ = uVar40;
    auVar87._0_8_ = auVar87._0_8_ << 0x40;
    ((code)FUN_004f1020)(*piVar107,0);
    uVar40 = auVar87._8_8_;
  }
  if ((piVar4 != (int *)0x0) && (*(int *)(*piVar4 + DAT_007ceaa8 + 0x58) == 0)) {
    ((code)FUN_004f1020)(*piVar4,1);
  }
  if ((piVar107 != (int *)0x0) && (*(int *)(*piVar107 + DAT_007ceaa8 + 0x58) == 0)) {
    auVar84._8_8_ = 0;
    auVar84._0_8_ = uVar40;
    auVar84._0_8_ = auVar84._0_8_ << 0x40;
    ((code)FUN_004f1020)(*piVar107,0);
    uVar40 = auVar84._8_8_;
  }
  if (piVar107 == (int *)0x0) {
    DAT_007ceabc = 0;
    DAT_007cddc0 = DAT_007cddc0 & 0xffffffffffffffef;
  }
  else {
    DAT_007cddc0 = DAT_007cddc0 | 0x10;
    DAT_007ceabc = *piVar107;
    ((code)FUN_004f1e20)(*piVar107,(int)&uStack_18 + 4,&uStack_18);
    ((code)FUN_004f1e40)(*piVar107,0x7cea60,(char)piVar107[0x14]);
    DAT_007cea58 = (u32)((piVar107[0x14] & 0xf00U) == 0x300);
    if ((piVar107[0x14] & 0xf000U) == 0x3000) {
      DAT_007cea58 = DAT_007cea58 | 4;
    }
  }
  DAT_007cea40 = DAT_007cea40 | 1;
  if (piVar4 != (int *)0x0) {
    ((code)FUN_004f1e20)(*piVar4,(int)&uStack_20 + 4,&uStack_20);
    ((code)FUN_004f1e40)(*piVar4,&uStack_10,(char)piVar4[0x14]);
    uVar106 = (u32)((piVar4[0x14] & 0xf00U) == 0x300);
    if ((piVar4[0x14] & 0xf000U) == 0x3000) {
      uVar106 = uVar106 | 4;
    }
  }
  if ((((piVar107 != (int *)0x0) && (*(int *)(*piVar107 + 0x14) < 9)) && (piVar4 != (int *)0x0)) &&
     (*(int *)(*piVar4 + 0x14) < 9)) {
    DAT_007ceabc = -1;
  }
  ((code)FUN_004d59d0)(0,0x33);
  puVar2 = (u32 *)(DAT_007ce9f4);
  fVar109 = DAT_007cdb3c;
  auVar108._8_8_ = 0;
  auVar108._0_8_ = uVar40;
  auVar62._8_8_ = in_a0_udw;
  auVar62._0_8_ = 0x1000002b;
  auVar94 = _pcpyld(auVar108 << 0x40,auVar62);
  auVar82._4_4_ = 0;
  auVar82._0_4_ = fStack_8;
  auVar82._8_8_ = in_a3_udw;
  auVar71._8_8_ = uVar40;
  auVar71._0_8_ = 0x6c1403bc;
  auVar63._8_8_ = in_a0_udw;
  auVar63._0_8_ = 0x1000101;
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar94 + 0));
  puVar2[1] = auVar94._4_4_;
  puVar2[2] = auVar94._8_4_;
  puVar2[3] = auVar94._12_4_;
  puVar3 = (u32 *)(DAT_007ce9f4);
  auVar20._8_8_ = 0;
  auVar20._0_8_ = in_t0_udw;
  auVar21._8_8_ = 0;
  auVar21._0_8_ = extraout_v0_udw_01;
  auVar95 = _ppacw(auVar20 << 0x40,auVar21 << 0x40);
  auVar94 = _ppacw(auVar71,auVar63);
  auVar87 = _ppacw(auVar94,auVar95);
  auVar90._8_8_ = auVar94._8_8_;
  auVar32._4_4_ = fVar109;
  auVar32._0_4_ = DAT_007cdb38;
  auVar32._8_8_ = extraout_v0_udw_01;
  auVar97._8_8_ = in_t5_udw;
  auVar97._0_8_ = 0x48;
  auVar102._8_8_ = in_t7_udw;
  auVar102._0_8_ = 0x47;
  auVar94 = _pcpyld(auVar32,auVar82);
  DAT_007ce9f4[4] = (*(u32*)((u8*)&auVar87 + 0));
  DAT_007ce9f4[5] = (*(u32*)((u8*)&auVar87 + 4));
  DAT_007ce9f4[6] = (*(u32*)((u8*)&auVar87 + 8));
  DAT_007ce9f4[7] = (*(u32*)((u8*)&auVar87 + 12));
  DAT_007ce9f4[8] = (*(u32*)((u8*)&auVar94 + 0));
  DAT_007ce9f4[9] = (*(u32*)((u8*)&auVar94 + 4));
  DAT_007ce9f4[10] = (*(u32*)((u8*)&auVar94 + 8));
  DAT_007ce9f4[0xb] = (*(u32*)((u8*)&auVar94 + 12));
  auVar88._8_8_ = auVar87._8_8_;
  auVar33._8_8_ = auVar94._8_8_;
  auVar64._8_8_ = in_a0_udw;
  auVar64._0_8_ = 0xe;
  auVar75._8_8_ = in_a2_udw;
  auVar75._0_8_ = 0x1000000000008004;
  auVar88._0_8_ = 0x1000000000008002;
  auVar33._0_8_ = 0x8000000002;
  auVar94 = _pcpyld(auVar64,auVar75);
  DAT_007ce9f4[0xc] = (*(u32*)((u8*)&auVar94 + 0));
  DAT_007ce9f4[0xd] = (*(u32*)((u8*)&auVar94 + 4));
  DAT_007ce9f4[0xe] = (*(u32*)((u8*)&auVar94 + 8));
  DAT_007ce9f4[0xf] = (*(u32*)((u8*)&auVar94 + 12));
  auVar89._8_4_ = in_s2_udw;
  auVar89._0_8_ = 0x42;
  auVar89._12_4_ = in_register_0000012c;
  auVar94 = _pcpyld(auVar89,auVar33);
  DAT_007ce9f4[0x10] = (*(u32*)((u8*)&auVar94 + 0));
  DAT_007ce9f4[0x11] = (*(u32*)((u8*)&auVar94 + 4));
  DAT_007ce9f4[0x12] = (*(u32*)((u8*)&auVar94 + 8));
  DAT_007ce9f4[0x13] = (*(u32*)((u8*)&auVar94 + 12));
  auVar83._8_8_ = in_a3_udw;
  auVar83._0_8_ = 0x8000000048;
  auVar34._8_8_ = auVar94._8_8_;
  auVar34._0_8_ = 0x3d;
  auVar87 = _pcpyld(auVar34,auVar65);
  auVar101._4_4_ = (int)((u32)uVar25 >> 0x20);
  auVar101._0_4_ = uVar5 & 0x70000 | (u32)uVar25;
  auVar101._8_4_ = in_s7_udw;
  auVar101._12_4_ = in_register_0000017c;
  auVar108 = _pcpyld(auVar97,auVar101);
  auVar91._8_4_ = in_s2_udw;
  auVar91._0_8_ = 0x42;
  auVar91._12_4_ = in_register_0000012c;
  auVar84 = _pcpyld(auVar91,auVar83);
  auVar89 = _pcpyld(auVar64,auVar88);
  auVar90._0_8_ = DAT_007cea40 & 0x70000;
  auVar91 = _pcpyld(auVar102,auVar90);
  auVar103._8_8_ = in_t7_udw;
  auVar103._0_8_ = DAT_006b5168;
  DAT_007ce9f4[0x14] = (*(u32*)((u8*)&auVar91 + 0));
  DAT_007ce9f4[0x15] = (*(u32*)((u8*)&auVar91 + 4));
  DAT_007ce9f4[0x16] = (*(u32*)((u8*)&auVar91 + 8));
  DAT_007ce9f4[0x17] = (*(u32*)((u8*)&auVar91 + 12));
  auVar100._8_8_ = in_t6_udw;
  auVar100._0_8_ = DAT_006b5160;
  auVar99._8_4_ = in_s3_udw;
  auVar99._0_8_ = DAT_007cea50;
  auVar99._12_4_ = in_register_0000013c;
  auVar94 = _pcpyld(auVar34,auVar99);
  DAT_007ce9f4[0x18] = (*(u32*)((u8*)&auVar94 + 0));
  DAT_007ce9f4[0x19] = (*(u32*)((u8*)&auVar94 + 4));
  DAT_007ce9f4[0x1a] = (*(u32*)((u8*)&auVar94 + 8));
  DAT_007ce9f4[0x1b] = (*(u32*)((u8*)&auVar94 + 12));
  auVar35._8_8_ = auVar94._8_8_;
  auVar35._0_8_ = 0x1000000000008005;
  auVar65 = _pcpyld(auVar64,auVar35);
  auVar51._8_8_ = in_v1_udw;
  auVar51._0_8_ = 9;
  auVar98._8_8_ = in_t5_udw;
  auVar98._0_8_ = 0x50000006;
  auVar22._4_4_ = in_register_0000017c;
  auVar22._0_4_ = in_s7_udw;
  auVar22._8_8_ = 0;
  auVar94 = _ppacw(auVar98,auVar22 << 0x40);
  auVar99 = _ppacw(auVar94,auVar95);
  auVar96._8_8_ = auVar95._8_8_;
  auVar96._0_8_ = uStack_18;
  auVar101 = _pcpyld(auVar103,auVar100);
  auVar104._8_8_ = in_t7_udw;
  auVar104._0_8_ = 0x43;
  auVar105._8_4_ = in_s5_udw;
  auVar105._0_8_ = uVar54;
  auVar105._12_4_ = in_register_0000015c;
  auVar94 = _pcpyld(auVar104,auVar105);
  auVar95._4_4_ = 0;
  auVar95._0_4_ = uVar106;
  auVar95._8_4_ = in_s1_udw;
  auVar95._12_4_ = in_register_0000011c;
  auVar105 = _pcpyld(auVar51,auVar95);
  auVar52._8_8_ = in_v1_udw;
  auVar52._0_8_ = 0x15;
  auVar9._8_8_ = in_t8_udw;
  auVar9._0_8_ = 6;
  auVar95 = _pcpyld(auVar9,auVar96);
  DAT_007ce9f4[0x1c] = (*(u32*)((u8*)&auVar95 + 0));
  DAT_007ce9f4[0x1d] = (*(u32*)((u8*)&auVar95 + 4));
  DAT_007ce9f4[0x1e] = (*(u32*)((u8*)&auVar95 + 8));
  DAT_007ce9f4[0x1f] = (*(u32*)((u8*)&auVar95 + 12));
  DAT_007ce9f4[0x20] = (*(u32*)((u8*)&auVar89 + 0));
  DAT_007ce9f4[0x21] = (*(u32*)((u8*)&auVar89 + 4));
  DAT_007ce9f4[0x22] = (*(u32*)((u8*)&auVar89 + 8));
  DAT_007ce9f4[0x23] = (*(u32*)((u8*)&auVar89 + 12));
  DAT_007ce9f4[0x24] = (*(u32*)((u8*)&auVar84 + 0));
  DAT_007ce9f4[0x25] = (*(u32*)((u8*)&auVar84 + 4));
  DAT_007ce9f4[0x26] = (*(u32*)((u8*)&auVar84 + 8));
  DAT_007ce9f4[0x27] = (*(u32*)((u8*)&auVar84 + 12));
  DAT_007ce9f4[0x28] = (*(u32*)((u8*)&auVar91 + 0));
  DAT_007ce9f4[0x29] = (*(u32*)((u8*)&auVar91 + 4));
  DAT_007ce9f4[0x2a] = (*(u32*)((u8*)&auVar91 + 8));
  DAT_007ce9f4[0x2b] = (*(u32*)((u8*)&auVar91 + 12));
  auVar92._8_8_ = auVar91._8_8_;
  auVar92._0_8_ = 0x4f;
  auVar11._8_4_ = in_s8_udw;
  auVar11._0_8_ = uVar55;
  auVar11._12_4_ = in_register_000001ec;
  auVar95 = _pcpyld(auVar92,auVar11);
  auVar93._8_8_ = auVar92._8_8_;
  auVar93._0_8_ = 0x6c0103fa01000404;
  DAT_007ce9f4[0x2c] = (*(u32*)((u8*)&auStack_60 + 0));
  DAT_007ce9f4[0x2d] = (*(u32*)((u8*)&auStack_60 + 4));
  DAT_007ce9f4[0x2e] = uStack_58;
  DAT_007ce9f4[0x2f] = uStack_54;
  auVar23._4_4_ = in_register_0000011c;
  auVar23._0_4_ = in_s1_udw;
  auVar23._8_8_ = 0;
  auVar84 = _pcpyld(auVar93,auVar23 << 0x40);
  DAT_007ce9f4[0x30] = (int)uStack_50;
  DAT_007ce9f4[0x31] = (int)((u32)uStack_50 >> 0x20);
  DAT_007ce9f4[0x32] = uStack_48;
  DAT_007ce9f4[0x33] = uStack_44;
  uVar55 = CONCAT44(uStack_34,uStack_38);
  DAT_007ce9f4[0x34] = (int)uStack_40;
  DAT_007ce9f4[0x35] = (int)((u32)uStack_40 >> 0x20);
  DAT_007ce9f4[0x36] = uStack_38;
  DAT_007ce9f4[0x37] = uStack_34;
  DAT_007ce9f4[0x38] = (*(u32*)((u8*)&auVar89 + 0));
  DAT_007ce9f4[0x39] = (*(u32*)((u8*)&auVar89 + 4));
  DAT_007ce9f4[0x3a] = (*(u32*)((u8*)&auVar89 + 8));
  DAT_007ce9f4[0x3b] = (*(u32*)((u8*)&auVar89 + 12));
  DAT_007ce9f4[0x3c] = (*(u32*)((u8*)&auVar87 + 0));
  DAT_007ce9f4[0x3d] = (*(u32*)((u8*)&auVar87 + 4));
  DAT_007ce9f4[0x3e] = (*(u32*)((u8*)&auVar87 + 8));
  DAT_007ce9f4[0x3f] = (*(u32*)((u8*)&auVar87 + 12));
  auVar76._8_8_ = auVar87._8_8_;
  auVar76._0_8_ = uStack_20;
  auVar10._8_8_ = in_t9_udw;
  auVar10._0_8_ = 7;
  auVar87 = _pcpyld(auVar10,auVar76);
  DAT_007ce9f4[0x40] = (*(u32*)((u8*)&auVar87 + 0));
  DAT_007ce9f4[0x41] = (*(u32*)((u8*)&auVar87 + 4));
  DAT_007ce9f4[0x42] = (*(u32*)((u8*)&auVar87 + 8));
  DAT_007ce9f4[0x43] = (*(u32*)((u8*)&auVar87 + 12));
  auVar77._8_8_ = auVar87._8_8_;
  auVar85._0_8_ =
       (((long)(int)(*(u8 *)(param_1 + 0x28) & 1) << 5 | 600U | (u32)*(u8 *)(param_1 + 0x29))
        << 0xf | 0x30004000) << 0x20;
  auVar85._8_8_ = uVar55;
  auVar77._0_8_ = 0x412;
  auVar87 = _pcpyld(auVar77,auVar85);
  DAT_007ce9f4[0x44] = (*(u32*)((u8*)&auVar87 + 0));
  DAT_007ce9f4[0x45] = (*(u32*)((u8*)&auVar87 + 4));
  DAT_007ce9f4[0x46] = (*(u32*)((u8*)&auVar87 + 8));
  DAT_007ce9f4[0x47] = (*(u32*)((u8*)&auVar87 + 12));
  DAT_007ce9f4[0x48] = (*(u32*)((u8*)&auStack_a0 + 0));
  DAT_007ce9f4[0x49] = (*(u32*)((u8*)&auStack_a0 + 4));
  DAT_007ce9f4[0x4a] = uStack_98;
  DAT_007ce9f4[0x4b] = uStack_94;
  auVar78._12_4_ = uStack_84;
  auVar78._8_4_ = uStack_88;
  DAT_007ce9f4[0x4c] = (int)uStack_90;
  DAT_007ce9f4[0x4d] = (int)((u32)uStack_90 >> 0x20);
  DAT_007ce9f4[0x4e] = uStack_88;
  DAT_007ce9f4[0x4f] = uStack_84;
  auVar78._0_8_ = uStack_80;
  auVar86._4_4_ = uStack_4;
  auVar86._0_4_ = uStack_78;
  auVar86._8_8_ = uVar55;
  auVar87 = _pcpyld(auVar86,auVar78);
  DAT_007ce9f4[0x50] = (*(u32*)((u8*)&auVar87 + 0));
  DAT_007ce9f4[0x51] = (*(u32*)((u8*)&auVar87 + 4));
  DAT_007ce9f4[0x52] = (*(u32*)((u8*)&auVar87 + 8));
  DAT_007ce9f4[0x53] = (*(u32*)((u8*)&auVar87 + 12));
  DAT_007ce9f4[0x54] = (*(u32*)((u8*)&auVar101 + 0));
  DAT_007ce9f4[0x55] = (*(u32*)((u8*)&auVar101 + 4));
  DAT_007ce9f4[0x56] = (*(u32*)((u8*)&auVar101 + 8));
  DAT_007ce9f4[0x57] = (*(u32*)((u8*)&auVar101 + 12));
  DAT_007ce9f4[0x58] = (*(u32*)((u8*)&auVar99 + 0));
  DAT_007ce9f4[0x59] = (*(u32*)((u8*)&auVar99 + 4));
  DAT_007ce9f4[0x5a] = (*(u32*)((u8*)&auVar99 + 8));
  DAT_007ce9f4[0x5b] = (*(u32*)((u8*)&auVar99 + 12));
  DAT_007ce9f4[0x5c] = (*(u32*)((u8*)&auVar65 + 0));
  DAT_007ce9f4[0x5d] = (*(u32*)((u8*)&auVar65 + 4));
  DAT_007ce9f4[0x5e] = (*(u32*)((u8*)&auVar65 + 8));
  DAT_007ce9f4[0x5f] = (*(u32*)((u8*)&auVar65 + 12));
  DAT_007ce9f4[0x60] = (*(u32*)((u8*)&auVar94 + 0));
  DAT_007ce9f4[0x61] = (*(u32*)((u8*)&auVar94 + 4));
  DAT_007ce9f4[0x62] = (*(u32*)((u8*)&auVar94 + 8));
  DAT_007ce9f4[99] = (*(u32*)((u8*)&auVar94 + 12));
  DAT_007ce9f4[100] = (*(u32*)((u8*)&auVar105 + 0));
  DAT_007ce9f4[0x65] = (*(u32*)((u8*)&auVar105 + 4));
  DAT_007ce9f4[0x66] = (*(u32*)((u8*)&auVar105 + 8));
  DAT_007ce9f4[0x67] = (*(u32*)((u8*)&auVar105 + 12));
  DAT_007ce9f4[0x68] = (*(u32*)((u8*)&auVar108 + 0));
  DAT_007ce9f4[0x69] = (*(u32*)((u8*)&auVar108 + 4));
  DAT_007ce9f4[0x6a] = (*(u32*)((u8*)&auVar108 + 8));
  DAT_007ce9f4[0x6b] = (*(u32*)((u8*)&auVar108 + 12));
  auVar36._8_8_ = auVar94._8_8_;
  auVar36._0_8_ = uStack_10;
  auVar94 = _pcpyld(auVar52,auVar36);
  DAT_007ce9f4[0x6c] = (*(u32*)((u8*)&auVar94 + 0));
  DAT_007ce9f4[0x6d] = (*(u32*)((u8*)&auVar94 + 4));
  DAT_007ce9f4[0x6e] = (*(u32*)((u8*)&auVar94 + 8));
  DAT_007ce9f4[0x6f] = (*(u32*)((u8*)&auVar94 + 12));
  DAT_007ce9f4[0x70] = (*(u32*)((u8*)&auVar95 + 0));
  DAT_007ce9f4[0x71] = (*(u32*)((u8*)&auVar95 + 4));
  DAT_007ce9f4[0x72] = (*(u32*)((u8*)&auVar95 + 8));
  DAT_007ce9f4[0x73] = (*(u32*)((u8*)&auVar95 + 12));
  puVar2 = (u32 *)(DAT_007ce9f4 + 0x74);
  DAT_007ce9f4 = DAT_007ce9f4 + 0x74;
  *puVar2 = auVar84._0_4_;
  puVar3[0x75] = auVar84._4_4_;
  puVar3[0x76] = auVar84._8_4_;
  puVar3[0x77] = auVar84._12_4_;
  puVar2 = (u32 *)(DAT_007ce9f4);
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  bVar7 = *(char *)(param_1 + 0x47) != -1;
  DAT_007ceab4 = (u32)bVar7;
  if (bVar7 || DAT_007ceab8 != 0) {
    DAT_007cddc0 = DAT_007cddc0 | 0x40;
  }
  else {
    DAT_007cddc0 = DAT_007cddc0 & 0xffffffffffffffbf;
  }
  auVar56._8_8_ = auVar65._8_8_;
  auVar41._8_8_ = in_v1_udw;
  auVar41._0_8_ = 0xfc007fffffffffff;
  auVar8._4_4_ = in_zero_hi;
  auVar8._0_4_ = in_zero_lo;
  auVar8._8_4_ = in_zero_udw;
  auVar8._12_4_ = in_register_0000000c;
  auVar94 = _pcpyld(auVar8,auVar41);
  uVar54 = auVar94._8_8_;
  auVar72._8_8_ = auVar87._8_8_;
  auVar72._4_4_ = DAT_009658ac;
  auVar72._0_4_ = DAT_009658a8;
  auVar56._0_8_ = 0x6c0103fb01000404;
  uVar40 = DAT_007cddc0 & 0x10;
  auVar80._0_8_ =
       CONCAT44((*(u32*)((u8*)&DAT_009658a0 + 4)),(u32)DAT_009658a0) & (*(u64*)((u8*)&auVar94 + 0)) |
       ((long)(int)((u32)DAT_007cddc0 | (u32)*(u8 *)(param_1 + 0x29)) & 0x7ffU) << 0x2f;
  auVar80._8_8_ = uVar55;
  auVar15._8_8_ = 0;
  auVar15._0_8_ = auVar89._8_8_;
  auVar73 = _pcpyld(auVar72,auVar80);
  (*(u32*)((u8*)&DAT_009658a0 + 0)) = (*(u32*)((u8*)&auVar73 + 0));
  auVar94 = _pcpyld(auVar56,auVar15 << 0x40);
  (*(u32*)((u8*)&DAT_009658a0 + 4)) = (*(u32*)((u8*)&auVar73 + 4));
  DAT_009658a8 = auVar73._8_4_;
  DAT_009658ac = auVar73._12_4_;
  *DAT_007ce9f4 = (u32)DAT_009658a0;
  puVar2[5] = auVar73._4_4_;
  puVar2[6] = auVar73._8_4_;
  puVar2[7] = auVar73._12_4_;
  puVar2[8] = auVar94._0_4_;
  puVar2[9] = auVar94._4_4_;
  puVar2[10] = auVar94._8_4_;
  puVar2[0xb] = auVar94._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 8;
  uVar79 = auVar94._8_8_;
  if (uVar40 == 0) {
    uVar24 = 0x3b808081;
  }
  else {
    uVar24 = 0x3b011b50;
  }
  ((code)FUN_0049cab0)(uVar24,param_1 + 0x44);
  puVar2 = (u32 *)(DAT_007ce9f4);
  auVar16._8_8_ = 0;
  auVar16._0_8_ = uVar79;
  auVar42._8_8_ = uVar54;
  auVar42._0_8_ = 0x6c0103fc01000404;
  auVar94 = _pcpyld(auVar42,auVar16 << 0x40);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar94 + 0));
  puVar2[1] = auVar94._4_4_;
  puVar2[2] = auVar94._8_4_;
  puVar2[3] = auVar94._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  ((code)FUN_0049cbd0)(*(u32 *)(param_1 + 0x1c),*(u32 *)(param_1 + 0x3c));
  puVar2 = (u32 *)(DAT_007ce9f4);
  bVar1 = *(u8 *)(param_1 + 0x28);
  auVar26._8_8_ = extraout_v0_udw;
  auVar26._0_8_ = 0x6c0303fd01000404;
  auVar17._8_8_ = 0;
  auVar17._0_8_ = auVar94._8_8_;
  auVar87 = _pcpyld(auVar26,auVar17 << 0x40);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar87 + 0));
  puVar2[1] = auVar87._4_4_;
  puVar2[2] = auVar87._8_4_;
  puVar2[3] = auVar87._12_4_;
  auVar65 = _DAT_00965930;
  auVar94 = _DAT_00965910;
  puVar2 = (u32 *)(DAT_007ce9f4);
  uVar40 = (u32)bVar1 & 7;
  auVar66._8_8_ = auVar87._8_8_;
  if (((DAT_007ceb04 == 0) || ((bVar1 & 4) != 0)) && ((DAT_007cdde8 == 0 || ((bVar1 & 4) == 0)))) {
    DAT_007ce9f4[4] = (u32)(DAT_00965910);
    puVar2[5] = auVar94._4_4_;
    puVar2[6] = auVar94._8_4_;
    puVar2[7] = auVar94._12_4_;
    auVar65 = _DAT_00965920;
    puVar2[8] = DAT_00965920;
    puVar2[9] = auVar65._4_4_;
    puVar2[10] = auVar65._8_4_;
    puVar2[0xb] = auVar65._12_4_;
    uVar55 = auVar65._8_8_;
    puVar2 = (u32 *)(DAT_007ce9f4);
  }
  else {
    uVar40 = uVar40 | 8;
    DAT_007ce9f4[4] = (u32)(DAT_00965930);
    puVar2[5] = auVar65._4_4_;
    puVar2[6] = auVar65._8_4_;
    puVar2[7] = auVar65._12_4_;
    auVar94 = _DAT_00965940;
    puVar2[8] = DAT_00965940;
    puVar2[9] = auVar94._4_4_;
    puVar2[10] = auVar94._8_4_;
    puVar2[0xb] = auVar94._12_4_;
    uVar55 = auVar94._8_8_;
    auVar94 = auVar65;
    puVar2 = (u32 *)(DAT_007ce9f4);
  }
  DAT_007ce9f4 = (u32 *)((u32)(puVar2 + 0xc));
  auVar57._8_8_ = auVar94._8_8_;
  DAT_007ceafc = 0;
  uVar79 = 0;
  if (DAT_007ceaac == 3) {
    uVar79 = 0x20;
    DAT_007ceafc = 0x20;
  }
  auVar43._8_8_ = uVar55;
  auVar43._0_8_ = uVar40;
  auVar57._0_8_ = (u32)DAT_007ceb00 << 0x20 | uVar79;
  auVar94 = _pcpyld(auVar57,auVar43);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar94 + 0));
  puVar2[0xd] = auVar94._4_4_;
  puVar2[0xe] = auVar94._8_4_;
  puVar2[0xf] = auVar94._12_4_;
  puVar2 = (u32 *)(DAT_007ce9f4);
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  auVar44._8_8_ = auVar94._8_8_;
  if (*(int *)(param_1 + 0x40) == 0) {
    auVar67._0_8_ = (long)(int)DAT_007ce9f4;
    auVar67._8_8_ = auVar66._8_8_;
    *DAT_007ce9f4 = in_zero_lo;
    puVar2[5] = in_zero_hi;
    puVar2[6] = in_zero_udw;
    puVar2[7] = in_register_0000000c;
    auVar37._8_8_ = extraout_v0_udw;
    auVar37._0_8_ = 0x5000000200000000;
    auVar14._8_8_ = 0;
    auVar14._0_8_ = auVar44._8_8_;
    puVar2[8] = in_zero_lo;
    puVar2[9] = in_zero_hi;
    puVar2[10] = in_zero_udw;
    puVar2[0xb] = in_register_0000000c;
    auVar94 = _pcpyld(auVar37,auVar14 << 0x40);
    puVar2[0xc] = auVar94._0_4_;
    puVar2[0xd] = auVar94._4_4_;
    puVar2[0xe] = auVar94._8_4_;
    puVar2[0xf] = auVar94._12_4_;
    auVar59._8_8_ = auVar57._8_8_;
    auVar59._0_8_ = 0xe;
    auVar38._8_8_ = auVar94._8_8_;
    auVar53._8_8_ = auVar44._8_8_;
    auVar53._0_8_ = 0x1000000000008001;
    auVar94 = _pcpyld(auVar59,auVar53);
    puVar2[0x10] = auVar94._0_4_;
    puVar2[0x11] = auVar94._4_4_;
    puVar2[0x12] = auVar94._8_4_;
    puVar2[0x13] = auVar94._12_4_;
    auVar38._0_8_ = 0x47;
    auVar45._8_8_ = auVar94._8_8_;
    auVar45._0_8_ = DAT_007cea40;
    auVar94 = _pcpyld(auVar38,auVar45);
    puVar2[0x14] = auVar94._0_4_;
    puVar2[0x15] = auVar94._4_4_;
    puVar2[0x16] = auVar94._8_4_;
    puVar2[0x17] = auVar94._12_4_;
  }
  else {
    auVar12._8_8_ = 0;
    auVar12._0_8_ = auVar44._8_8_;
    auVar27._8_8_ = extraout_v0_udw;
    auVar27._0_8_ = 0x5000000400000000;
    auVar73._0_8_ = (long)(int)DAT_007ce9f4;
    auVar94 = _pcpyld(auVar27,auVar12 << 0x40);
    *DAT_007ce9f4 = (*(u32*)((u8*)&auVar94 + 0));
    puVar2[5] = auVar94._4_4_;
    puVar2[6] = auVar94._8_4_;
    puVar2[7] = auVar94._12_4_;
    auVar66._0_8_ = 0xe;
    auVar28._8_8_ = auVar94._8_8_;
    auVar58._8_8_ = auVar57._8_8_;
    auVar58._0_8_ = 0x47;
    auVar28._0_8_ = 0x1000000000008003;
    auVar94 = _pcpyld(auVar66,auVar28);
    puVar2[8] = auVar94._0_4_;
    puVar2[9] = auVar94._4_4_;
    puVar2[10] = auVar94._8_4_;
    puVar2[0xb] = auVar94._12_4_;
    auVar44._0_8_ = 0x14;
    auVar67._8_8_ = auVar66._8_8_;
    auVar67._0_8_ = DAT_007cea40;
    auVar29._8_8_ = auVar94._8_8_;
    auVar29._0_8_ = 8;
    auVar94 = _pcpyld(auVar58,auVar67);
    puVar2[0xc] = auVar94._0_4_;
    puVar2[0xd] = auVar94._4_4_;
    puVar2[0xe] = auVar94._8_4_;
    puVar2[0xf] = auVar94._12_4_;
    auVar59._8_8_ = auVar94._8_8_;
    auVar59._0_8_ = DAT_007cea60;
    auVar94 = _pcpyld(auVar44,auVar59);
    puVar2[0x10] = auVar94._0_4_;
    puVar2[0x11] = auVar94._4_4_;
    puVar2[0x12] = auVar94._8_4_;
    puVar2[0x13] = auVar94._12_4_;
    auVar45._8_8_ = auVar94._8_8_;
    auVar45._0_8_ = DAT_007cea58;
    auVar94 = _pcpyld(auVar29,auVar45);
    puVar2[0x14] = auVar94._0_4_;
    puVar2[0x15] = auVar94._4_4_;
    puVar2[0x16] = auVar94._8_4_;
    puVar2[0x17] = auVar94._12_4_;
  }
  DAT_007ce9f4 = DAT_007ce9f4 + 0x14;
  auVar47._8_8_ = auVar45._8_8_;
  *(u8 *)(param_1 + 0x2b) =
       (u8)((int)(*(u8 *)(param_1 + 0x28) & 0x20) >> 5) |
       (u8)((int)(*(u8 *)(param_1 + 0x28) & 0x18) >> 2);
  puVar2 = (u32 *)(DAT_007ce9f4);
  uVar55 = auVar59._8_8_;
  puVar39 = (u32 *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + (u32)*(u8 *)(param_1 + 0x2b) * 4);
  auVar47._0_8_ = (long)(int)puVar39;
  uVar5 = *puVar39;
  if (DAT_007ceaf8 != uVar5) {
    auVar13._8_8_ = 0;
    auVar13._0_8_ = auVar67._8_8_;
    auVar67._0_8_ = auVar13._0_8_ << 0x40;
    auVar46._0_8_ = (u32)uVar5 << 0x20 | 0x50000000;
    auVar46._8_8_ = auVar47._8_8_;
    auVar47 = _pcpyld(auVar67,auVar46);
    *DAT_007ce9f4 = (*(u32*)((u8*)&auVar47 + 0));
    puVar2[1] = auVar47._4_4_;
    puVar2[2] = auVar47._8_4_;
    puVar2[3] = auVar47._12_4_;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    DAT_007ceaf8 = uVar5;
  }
  puVar2 = (u32 *)(DAT_007ce9f4);
  uVar79 = auVar73._8_8_;
  auVar81._8_8_ = auVar80._8_8_;
  uVar40 = auVar47._8_8_;
  auVar68._8_8_ = auVar67._8_8_;
  iVar6 = **(int **)(param_1 + 0x30);
  auVar81._0_8_ = ((long)*(int *)(*(int *)(param_1 + 4) + 0x14) | 0x2000000U) << 0x20 | 0x3000000;
  auVar68._0_8_ = (u32)*(u32 *)(iVar6 + 0x20) << 0x20 | 0x50000000;
  auVar94 = _pcpyld(auVar81,auVar68);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar94 + 0));
  puVar2[1] = auVar94._4_4_;
  puVar2[2] = auVar94._8_4_;
  puVar2[3] = auVar94._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  do {
    DI();
    SYNC(0x10);
  } while ((Status & 0x10000) != 0);
  *(int *)(iVar6 + 0x18) = *(int *)(iVar6 + 0x18) + 1;
  EI();
  *(int *)(iVar6 + 0x1c) = *(int *)(iVar6 + 0x1c) + 1;
  if (*(int *)(iVar6 + 0x1c) == 1) {
    ((code)FUN_004d51c0)();
  }
  uVar54 = auVar94._8_8_;
  ((code)FUN_004d59d0)(0,5);
  puVar2 = (u32 *)(DAT_007ce9f4);
  auVar18._8_8_ = 0;
  auVar18._0_8_ = uVar40;
  auVar30._8_8_ = extraout_v0_udw_00;
  auVar30._0_8_ = 0x50000004;
  auVar19._8_8_ = 0;
  auVar19._0_8_ = uVar79;
  auVar65 = _ppacw(auVar30,auVar18 << 0x40);
  auVar60._8_8_ = uVar55;
  auVar60._0_8_ = 0xe;
  auVar69._8_8_ = uVar54;
  auVar69._0_8_ = 0x10000004;
  auVar94 = _ppacw(auVar19 << 0x40,auVar69);
  auVar94 = _ppacw(auVar65,auVar94);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar94 + 0));
  puVar2[1] = auVar94._4_4_;
  puVar2[2] = auVar94._8_4_;
  puVar2[3] = auVar94._12_4_;
  auVar74._8_8_ = uVar79;
  auVar74._0_8_ = 0x42;
  auVar31._8_8_ = auVar94._8_8_;
  auVar70._8_8_ = uVar54;
  auVar70._0_8_ = 0x47;
  auVar31._0_8_ = 0x1000000000008003;
  auVar94 = _pcpyld(auVar60,auVar31);
  puVar2[4] = auVar94._0_4_;
  puVar2[5] = auVar94._4_4_;
  puVar2[6] = auVar94._8_4_;
  puVar2[7] = auVar94._12_4_;
  auVar61._8_8_ = uVar55;
  auVar61._0_8_ = 0x3d;
  auVar48._8_8_ = uVar40;
  auVar48._0_8_ = DAT_007cea68;
  auVar94 = _pcpyld(auVar74,auVar48);
  puVar2[8] = auVar94._0_4_;
  puVar2[9] = auVar94._4_4_;
  puVar2[10] = auVar94._8_4_;
  puVar2[0xb] = auVar94._12_4_;
  auVar49._8_8_ = auVar94._8_8_;
  auVar49._0_8_ = DAT_007cea40;
  auVar94 = _pcpyld(auVar70,auVar49);
  puVar2[0xc] = auVar94._0_4_;
  puVar2[0xd] = auVar94._4_4_;
  puVar2[0xe] = auVar94._8_4_;
  puVar2[0xf] = auVar94._12_4_;
  auVar50._8_8_ = auVar94._8_8_;
  auVar50._0_8_ = DAT_007cea50;
  auVar94 = _pcpyld(auVar61,auVar50);
  puVar2[0x10] = auVar94._0_4_;
  puVar2[0x11] = auVar94._4_4_;
  puVar2[0x12] = auVar94._8_4_;
  puVar2[0x13] = auVar94._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 0x14;
  return 1;
}

// FUN_0046E170 NONMATCHING



u64 FUN_0046e170(int param_1)

{
  u8 bVar1;
  int *piVar2;
  u32 *puVar3;
  int *piVar4;
  int iVar5;
  u8 bVar6;
  Vec128 auVar7;
  long lVar8;
  Vec128 auVar9;
  Vec128 auVar10;
  Vec128 auVar11;
  Vec128 auVar12;
  Vec128 auVar13;
  Vec128 auVar14;
  Vec128 auVar15;
  Vec128 auVar16;
  Vec128 auVar17;
  Vec128 auVar18;
  Vec128 auVar19;
  Vec128 auVar20;
  Vec128 auVar21;
  Vec128 auVar22;
  u32 uVar23;
  u32 *puVar24;
  u32 in_zero_lo;
  u32 in_zero_hi;
  u32 in_zero_udw;
  u32 in_register_0000000c;
  u32 uVar25;
  u64 uVar26;
  u64 extraout_v0_udw;
  Vec128 auVar27;
  Vec128 auVar28;
  Vec128 auVar29;
  Vec128 auVar30;
  u64 extraout_v0_udw_00;
  Vec128 auVar31;
  Vec128 auVar32;
  u32 extraout_v0_udw_01;
  Vec128 auVar33;
  Vec128 auVar34;
  Vec128 auVar35;
  Vec128 auVar36;
  Vec128 auVar37;
  u32 *puVar38;
  u32 uVar39;
  u64 in_v1_udw;
  Vec128 auVar40;
  u64 uVar51;
  Vec128 auVar41;
  Vec128 auVar42;
  Vec128 auVar43;
  Vec128 auVar44;
  Vec128 auVar45;
  Vec128 auVar46;
  Vec128 auVar47;
  Vec128 auVar48;
  Vec128 auVar49;
  Vec128 auVar50;
  u32 in_a0_udw;
  Vec128 auVar52;
  u32 uVar61;
  Vec128 auVar53;
  Vec128 auVar54;
  Vec128 auVar55;
  Vec128 auVar56;
  Vec128 auVar57;
  Vec128 auVar58;
  Vec128 auVar59;
  Vec128 auVar60;
  u8 in_a1_qw [16];
  Vec128 auVar62;
  Vec128 auVar63;
  Vec128 auVar64;
  u64 uVar68;
  Vec128 auVar65;
  Vec128 auVar66;
  Vec128 auVar67;
  Vec128 auVar69;
  Vec128 auVar70;
  Vec128 auVar71;
  Vec128 auVar72;
  Vec128 auVar73;
  Vec128 auVar74;
  u64 in_t0_udw;
  Vec128 auVar75;
  Vec128 auVar76;
  u64 in_t1_udw;
  Vec128 auVar77;
  Vec128 auVar78;
  Vec128 auVar79;
  Vec128 auVar80;
  u64 in_t2_udw;
  Vec128 auVar81;
  Vec128 auVar82;
  Vec128 auVar83;
  Vec128 auVar84;
  u64 in_t3_udw;
  u64 in_t4_udw;
  u64 in_t5_udw;
  Vec128 auVar85;
  Vec128 auVar86;
  Vec128 auVar87;
  u64 in_t7_udw;
  Vec128 auVar88;
  Vec128 auVar89;
  long lVar90;
  Vec128 auVar91;
  u32 uVar92;
  u32 in_s1_udw;
  u32 in_register_0000011c;
  u32 uVar93;
  u32 in_s2_udw;
  u32 in_register_0000012c;
  u32 in_s3_udw;
  u32 in_register_0000013c;
  u32 in_s5_udw;
  u32 in_register_0000015c;
  u32 in_s6_udw;
  u32 in_register_0000016c;
  u32 in_s7_udw;
  u32 in_register_0000017c;
  u64 uStack_18;
  u64 uStack_10;
  u64 uStack_8;
  
  uVar68 = DAT_007cea30;
  piVar2 = *(int **)(*(int *)(param_1 + 0x2c) + 8);
  puVar3 = (u32 *)*piVar2;
  lVar90 = (long)(int)puVar3;
  piVar2 = *(int **)((int)piVar2 + DAT_007ce738);
  lVar8 = *(long *)(piVar2 + 0xc);
  uVar25 = (u32)lVar8;
  uVar92 = (u32)((u32)lVar8 >> 0x20);
  piVar4 = (int *)*piVar2;
  uVar51 = *(u64 *)(piVar2 + 10);
  uVar93 = 0;
  if (lVar8 == 0x1000000) {
    uVar25 = (u32)DAT_007cea50;
    uVar92 = (u32)((u32)DAT_007cea50 >> 0x20);
  }
  uVar26 = *(u64 *)(piVar2 + 0xe);
  uStack_8 = 0;
  uVar23 = (u32)DAT_007cea40;
  uStack_10 = 0;
  uStack_18 = 0;
  DAT_007ceab8 = 0;
  if ((lVar90 != 0) && (((code)FUN_004f0f30)(*puVar3), (*(u8 *)(*(int *)lVar90 + 0x23) & 0xf) != 6)) {
    DAT_007ceab8 = 1;
  }
  uVar39 = (*(u64*)((u8*)&in_a1_qw + 8));
  if (piVar4 != (int *)0x0) {
    ((code)FUN_004f0f30)(*piVar4);
    uVar39 = (*(u64*)((u8*)&in_a1_qw + 8));
    ((code)FUN_004f1020)(*piVar4,1);
  }
  if (lVar90 != 0) {
    auVar59._8_8_ = 0;
    auVar59._0_8_ = uVar39;
    auVar59._0_8_ = auVar59._0_8_ << 0x40;
    ((code)FUN_004f1020)(*(u32 *)lVar90,0);
    uVar39 = auVar59._8_8_;
  }
  if ((piVar4 != (int *)0x0) && (*(int *)(*piVar4 + DAT_007ceaa8 + 0x58) == 0)) {
    ((code)FUN_004f1020)(*piVar4,1);
  }
  if ((lVar90 != 0) && (*(int *)(*(int *)lVar90 + DAT_007ceaa8 + 0x58) == 0)) {
    auVar70._8_8_ = 0;
    auVar70._0_8_ = uVar39;
    auVar70._0_8_ = auVar70._0_8_ << 0x40;
    ((code)FUN_004f1020)(*(int *)lVar90,0);
    uVar39 = auVar70._8_8_;
  }
  if (lVar90 == 0) {
    DAT_007ceabc = 0;
    DAT_007cddc0 = DAT_007cddc0 & 0xffffffffffffffef;
  }
  else {
    DAT_007cddc0 = DAT_007cddc0 | 0x10;
    DAT_007ceabc = *(u32 *)lVar90;
    ((code)FUN_004f1e20)(*(u32 *)lVar90,(int)&uStack_10 + 4,&uStack_10);
    ((code)FUN_004f1e40)(*(u32 *)lVar90,0x7cea60,*(u8 *)((u32 *)lVar90 + 0x14));
    DAT_007cea58 = (u32)((*(u32 *)((int)lVar90 + 0x50) & 0xf00) == 0x300);
    if ((*(u32 *)((int)lVar90 + 0x50) & 0xf000) == 0x3000) {
      DAT_007cea58 = DAT_007cea58 | 4;
    }
  }
  DAT_007cea40 = DAT_007cea40 | 1;
  if (piVar4 != (int *)0x0) {
    ((code)FUN_004f1e20)(*piVar4,(int)&uStack_18 + 4,&uStack_18);
    ((code)FUN_004f1e40)(*piVar4,&uStack_8,(char)piVar4[0x14]);
    uVar93 = (u32)((piVar4[0x14] & 0xf00U) == 0x300);
    if ((piVar4[0x14] & 0xf000U) == 0x3000) {
      uVar93 = uVar93 | 4;
    }
  }
  if ((((lVar90 != 0) && (*(int *)(*(int *)lVar90 + 0x14) < 9)) && (piVar4 != (int *)0x0)) &&
     (*(int *)(*piVar4 + 0x14) < 9)) {
    DAT_007ceabc = 0xffffffff;
  }
  ((code)FUN_004d59d0)(0,0x24);
  puVar3 = (u32 *)(DAT_007ce9f4);
  auVar89._8_8_ = 0;
  auVar89._0_8_ = in_a0_udw;
  auVar48._8_8_ = in_v1_udw;
  auVar48._0_8_ = 0x1000001e;
  auVar74 = _pcpyld(auVar89 << 0x40,auVar48);
  auVar58._8_8_ = in_a0_udw;
  auVar58._0_8_ = 0x6c0703bc;
  auVar49._8_8_ = in_v1_udw;
  auVar49._0_8_ = 0x1000101;
  auVar88._8_8_ = in_t7_udw;
  auVar88._0_8_ = 0xe;
  auVar70 = _ppacw(auVar58,auVar49);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar74 + 0));
  puVar3[1] = auVar74._4_4_;
  puVar3[2] = auVar74._8_4_;
  puVar3[3] = auVar74._12_4_;
  puVar24 = (u32 *)(DAT_007ce9f4);
  auVar91._8_8_ = 0;
  auVar91._0_8_ = in_a0_udw;
  auVar20._8_8_ = 0;
  auVar20._0_8_ = extraout_v0_udw_01;
  auVar59 = _ppacw(auVar91 << 0x40,auVar20 << 0x40);
  auVar70 = _ppacw(auVar70,auVar59);
  auVar72._8_8_ = auVar74._8_8_;
  DAT_007ce9f4[4] = (*(u32*)((u8*)&auVar70 + 0));
  DAT_007ce9f4[5] = (*(u32*)((u8*)&auVar70 + 4));
  DAT_007ce9f4[6] = (*(u32*)((u8*)&auVar70 + 8));
  DAT_007ce9f4[7] = (*(u32*)((u8*)&auVar70 + 12));
  auVar66._8_8_ = uVar39;
  auVar66._0_8_ = 0x1000000000008002;
  auVar74 = _pcpyld(auVar88,auVar66);
  auVar67._8_8_ = in_t4_udw;
  auVar67._0_8_ = 0x3d;
  auVar80._4_4_ = uVar92;
  auVar80._0_4_ = uVar25;
  auVar80._8_4_ = in_s1_udw;
  auVar80._12_4_ = in_register_0000011c;
  auVar67 = _pcpyld(auVar67,auVar80);
  auVar33._8_8_ = extraout_v0_udw_01;
  auVar33._0_8_ = 0x412;
  auVar85._8_8_ = in_t5_udw;
  auVar85._0_8_ = 6;
  auVar81._8_8_ = in_t2_udw;
  auVar81._0_8_ = 0x50000006;
  auVar21._4_4_ = in_register_0000013c;
  auVar21._0_4_ = in_s3_udw;
  auVar21._8_8_ = 0;
  auVar82 = _ppacw(auVar81,auVar21 << 0x40);
  auVar70 = _ppacw(auVar82,auVar59);
  auVar83._8_8_ = auVar82._8_8_;
  auVar83._0_8_ = 0x1000000000008005;
  auVar91 = _pcpyld(auVar88,auVar83);
  auVar77._8_8_ = in_t1_udw;
  auVar77._0_8_ = 0x43;
  auVar84._0_8_ =
       ((u32)((*(u8 *)(param_1 + 0x28) & 1) << 5 | 600 | (u32)*(u8 *)(param_1 + 0x29)) << 0xf
       | 0x30004000) << 0x20;
  auVar84._8_8_ = auVar83._8_8_;
  auVar87._8_4_ = in_s5_udw;
  auVar87._0_8_ = uVar51;
  auVar87._12_4_ = in_register_0000015c;
  auVar89 = _pcpyld(auVar77,auVar87);
  auVar59 = _pcpyld(auVar33,auVar84);
  DAT_007ce9f4[8] = (*(u32*)((u8*)&auVar59 + 0));
  DAT_007ce9f4[9] = (*(u32*)((u8*)&auVar59 + 4));
  DAT_007ce9f4[10] = (*(u32*)((u8*)&auVar59 + 8));
  DAT_007ce9f4[0xb] = (*(u32*)((u8*)&auVar59 + 12));
  auVar78._8_8_ = in_t1_udw;
  auVar78._0_8_ = 9;
  auVar86._4_4_ = 0;
  auVar86._0_4_ = uVar93;
  auVar86._8_4_ = in_s2_udw;
  auVar86._12_4_ = in_register_0000012c;
  auVar87 = _pcpyld(auVar78,auVar86);
  DAT_007ce9f4[0xc] = (*(u32*)((u8*)&auVar74 + 0));
  DAT_007ce9f4[0xd] = (*(u32*)((u8*)&auVar74 + 4));
  DAT_007ce9f4[0xe] = (*(u32*)((u8*)&auVar74 + 8));
  DAT_007ce9f4[0xf] = (*(u32*)((u8*)&auVar74 + 12));
  auVar34._8_8_ = auVar59._8_8_;
  auVar34._0_8_ = 0x48;
  auVar75._8_8_ = in_t0_udw;
  auVar75._0_8_ = 0x6c0103fa01000404;
  auVar79._8_8_ = in_t1_udw;
  auVar79._0_8_ = 0x4f;
  auVar10._4_4_ = (int)((u32)uVar26 >> 0x20);
  auVar10._0_4_ = uVar23 & 0x70000 | (u32)uVar26;
  auVar10._8_4_ = in_s6_udw;
  auVar10._12_4_ = in_register_0000016c;
  auVar59 = _pcpyld(auVar34,auVar10);
  auVar35._8_8_ = auVar34._8_8_;
  auVar35._0_8_ = 0x15;
  auVar11._8_4_ = in_s7_udw;
  auVar11._0_8_ = uVar68;
  auVar11._12_4_ = in_register_0000017c;
  auVar80 = _pcpyld(auVar79,auVar11);
  auVar9._8_4_ = in_s2_udw;
  auVar9._0_8_ = uStack_10;
  auVar9._12_4_ = in_register_0000012c;
  auVar82 = _pcpyld(auVar85,auVar9);
  DAT_007ce9f4[0x10] = (*(u32*)((u8*)&auVar82 + 0));
  DAT_007ce9f4[0x11] = (*(u32*)((u8*)&auVar82 + 4));
  DAT_007ce9f4[0x12] = (*(u32*)((u8*)&auVar82 + 8));
  DAT_007ce9f4[0x13] = (*(u32*)((u8*)&auVar82 + 12));
  auVar22._4_4_ = in_register_0000013c;
  auVar22._0_4_ = in_s3_udw;
  auVar22._8_8_ = 0;
  auVar86 = _pcpyld(auVar75,auVar22 << 0x40);
  auVar76._8_8_ = in_t0_udw;
  auVar76._0_8_ = DAT_007cea50;
  auVar82._8_8_ = in_t4_udw;
  auVar82._0_8_ = 0x3d;
  auVar82 = _pcpyld(auVar82,auVar76);
  DAT_007ce9f4[0x14] = (*(u32*)((u8*)&auVar82 + 0));
  DAT_007ce9f4[0x15] = (*(u32*)((u8*)&auVar82 + 4));
  DAT_007ce9f4[0x16] = (*(u32*)((u8*)&auVar82 + 8));
  DAT_007ce9f4[0x17] = (*(u32*)((u8*)&auVar82 + 12));
  DAT_007ce9f4[0x18] = (*(u32*)((u8*)&auVar74 + 0));
  DAT_007ce9f4[0x19] = (*(u32*)((u8*)&auVar74 + 4));
  DAT_007ce9f4[0x1a] = (*(u32*)((u8*)&auVar74 + 8));
  DAT_007ce9f4[0x1b] = (*(u32*)((u8*)&auVar74 + 12));
  auVar71._8_8_ = auVar74._8_8_;
  auVar71._0_8_ = uStack_18;
  auVar74._8_8_ = in_t3_udw;
  auVar74._0_8_ = 7;
  auVar74 = _pcpyld(auVar74,auVar71);
  DAT_007ce9f4[0x1c] = (*(u32*)((u8*)&auVar74 + 0));
  DAT_007ce9f4[0x1d] = (*(u32*)((u8*)&auVar74 + 4));
  DAT_007ce9f4[0x1e] = (*(u32*)((u8*)&auVar74 + 8));
  DAT_007ce9f4[0x1f] = (*(u32*)((u8*)&auVar74 + 12));
  DAT_007ce9f4[0x20] = (*(u32*)((u8*)&auVar67 + 0));
  DAT_007ce9f4[0x21] = (*(u32*)((u8*)&auVar67 + 4));
  DAT_007ce9f4[0x22] = (*(u32*)((u8*)&auVar67 + 8));
  DAT_007ce9f4[0x23] = (*(u32*)((u8*)&auVar67 + 12));
  DAT_007ce9f4[0x24] = (*(u32*)((u8*)&auVar70 + 0));
  DAT_007ce9f4[0x25] = (*(u32*)((u8*)&auVar70 + 4));
  DAT_007ce9f4[0x26] = (*(u32*)((u8*)&auVar70 + 8));
  DAT_007ce9f4[0x27] = (*(u32*)((u8*)&auVar70 + 12));
  DAT_007ce9f4[0x28] = (*(u32*)((u8*)&auVar91 + 0));
  DAT_007ce9f4[0x29] = (*(u32*)((u8*)&auVar91 + 4));
  DAT_007ce9f4[0x2a] = (*(u32*)((u8*)&auVar91 + 8));
  DAT_007ce9f4[0x2b] = (*(u32*)((u8*)&auVar91 + 12));
  DAT_007ce9f4[0x2c] = (*(u32*)((u8*)&auVar89 + 0));
  DAT_007ce9f4[0x2d] = (*(u32*)((u8*)&auVar89 + 4));
  DAT_007ce9f4[0x2e] = (*(u32*)((u8*)&auVar89 + 8));
  DAT_007ce9f4[0x2f] = (*(u32*)((u8*)&auVar89 + 12));
  DAT_007ce9f4[0x30] = (*(u32*)((u8*)&auVar87 + 0));
  DAT_007ce9f4[0x31] = (*(u32*)((u8*)&auVar87 + 4));
  DAT_007ce9f4[0x32] = (*(u32*)((u8*)&auVar87 + 8));
  DAT_007ce9f4[0x33] = (*(u32*)((u8*)&auVar87 + 12));
  DAT_007ce9f4[0x34] = (*(u32*)((u8*)&auVar59 + 0));
  DAT_007ce9f4[0x35] = (*(u32*)((u8*)&auVar59 + 4));
  DAT_007ce9f4[0x36] = (*(u32*)((u8*)&auVar59 + 8));
  DAT_007ce9f4[0x37] = (*(u32*)((u8*)&auVar59 + 12));
  auVar52._8_8_ = auVar70._8_8_;
  auVar60._8_8_ = auVar52._8_8_;
  auVar60._0_8_ = uStack_8;
  auVar59 = _pcpyld(auVar35,auVar60);
  DAT_007ce9f4[0x38] = (*(u32*)((u8*)&auVar59 + 0));
  DAT_007ce9f4[0x39] = (*(u32*)((u8*)&auVar59 + 4));
  DAT_007ce9f4[0x3a] = (*(u32*)((u8*)&auVar59 + 8));
  DAT_007ce9f4[0x3b] = (*(u32*)((u8*)&auVar59 + 12));
  DAT_007ce9f4[0x3c] = (*(u32*)((u8*)&auVar80 + 0));
  DAT_007ce9f4[0x3d] = (*(u32*)((u8*)&auVar80 + 4));
  DAT_007ce9f4[0x3e] = (*(u32*)((u8*)&auVar80 + 8));
  DAT_007ce9f4[0x3f] = (*(u32*)((u8*)&auVar80 + 12));
  puVar3 = (u32 *)(DAT_007ce9f4 + 0x40);
  DAT_007ce9f4 = DAT_007ce9f4 + 0x40;
  *puVar3 = auVar86._0_4_;
  puVar24[0x41] = auVar86._4_4_;
  puVar24[0x42] = auVar86._8_4_;
  puVar24[0x43] = auVar86._12_4_;
  puVar3 = (u32 *)(DAT_007ce9f4);
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  bVar6 = *(char *)(param_1 + 0x47) != -1;
  DAT_007ceab4 = (u32)bVar6;
  if (bVar6 || DAT_007ceab8 != 0) {
    DAT_007cddc0 = DAT_007cddc0 | 0x40;
  }
  else {
    DAT_007cddc0 = DAT_007cddc0 & 0xffffffffffffffbf;
  }
  auVar15._8_8_ = 0;
  auVar15._0_8_ = auVar82._8_8_;
  auVar40._8_8_ = in_v1_udw;
  auVar40._0_8_ = 0xfc007fffffffffff;
  auVar7._4_4_ = in_zero_hi;
  auVar7._0_4_ = in_zero_lo;
  auVar7._8_4_ = in_zero_udw;
  auVar7._12_4_ = in_register_0000000c;
  auVar59 = _pcpyld(auVar7,auVar40);
  uVar51 = auVar59._8_8_;
  auVar69._8_8_ = auVar74._8_8_;
  auVar69._4_4_ = DAT_009658ac;
  auVar69._0_4_ = DAT_009658a8;
  auVar52._0_8_ = 0x6c0103fb01000404;
  uVar39 = DAT_007cddc0 & 0x10;
  auVar72._0_8_ =
       CONCAT44((*(u32*)((u8*)&DAT_009658a0 + 4)),(u32)DAT_009658a0) & (*(u64*)((u8*)&auVar59 + 0)) |
       ((long)(int)((u32)DAT_007cddc0 | (u32)*(u8 *)(param_1 + 0x29)) & 0x7ffU) << 0x2f;
  auVar70 = _pcpyld(auVar69,auVar72);
  (*(u32*)((u8*)&DAT_009658a0 + 0)) = (*(u32*)((u8*)&auVar70 + 0));
  auVar59 = _pcpyld(auVar52,auVar15 << 0x40);
  (*(u32*)((u8*)&DAT_009658a0 + 4)) = (*(u32*)((u8*)&auVar70 + 4));
  DAT_009658a8 = auVar70._8_4_;
  DAT_009658ac = auVar70._12_4_;
  *DAT_007ce9f4 = (u32)DAT_009658a0;
  puVar3[5] = auVar70._4_4_;
  puVar3[6] = auVar70._8_4_;
  puVar3[7] = auVar70._12_4_;
  puVar3[8] = auVar59._0_4_;
  puVar3[9] = auVar59._4_4_;
  puVar3[10] = auVar59._8_4_;
  puVar3[0xb] = auVar59._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 8;
  uVar61 = auVar59._8_8_;
  if (uVar39 == 0) {
    uVar25 = 0x3b808081;
  }
  else {
    uVar25 = 0x3b011b50;
  }
  ((code)FUN_0049cab0)(uVar25,param_1 + 0x44);
  puVar3 = (u32 *)(DAT_007ce9f4);
  auVar16._8_8_ = 0;
  auVar16._0_8_ = uVar61;
  auVar41._8_8_ = uVar51;
  auVar41._0_8_ = 0x6c0103fc01000404;
  auVar59 = _pcpyld(auVar41,auVar16 << 0x40);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar59 + 0));
  puVar3[1] = auVar59._4_4_;
  puVar3[2] = auVar59._8_4_;
  puVar3[3] = auVar59._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  ((code)FUN_0049cbd0)(*(u32 *)(param_1 + 0x1c),*(u32 *)(param_1 + 0x3c));
  puVar3 = (u32 *)(DAT_007ce9f4);
  bVar1 = *(u8 *)(param_1 + 0x28);
  auVar27._8_8_ = extraout_v0_udw;
  auVar27._0_8_ = 0x6c0303fd01000404;
  auVar17._8_8_ = 0;
  auVar17._0_8_ = auVar59._8_8_;
  auVar74 = _pcpyld(auVar27,auVar17 << 0x40);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar74 + 0));
  puVar3[1] = auVar74._4_4_;
  puVar3[2] = auVar74._8_4_;
  puVar3[3] = auVar74._12_4_;
  auVar70 = _DAT_00965930;
  auVar59 = _DAT_00965910;
  puVar3 = (u32 *)(DAT_007ce9f4);
  uVar39 = (u32)bVar1 & 7;
  auVar62._8_8_ = auVar74._8_8_;
  if (((DAT_007ceb04 == 0) || ((bVar1 & 4) != 0)) && ((DAT_007cdde8 == 0 || ((bVar1 & 4) == 0)))) {
    DAT_007ce9f4[4] = (u32)(DAT_00965910);
    puVar3[5] = auVar59._4_4_;
    puVar3[6] = auVar59._8_4_;
    puVar3[7] = auVar59._12_4_;
    auVar70 = _DAT_00965920;
    puVar3[8] = DAT_00965920;
    puVar3[9] = auVar70._4_4_;
    puVar3[10] = auVar70._8_4_;
    puVar3[0xb] = auVar70._12_4_;
    uVar51 = auVar70._8_8_;
    puVar3 = (u32 *)(DAT_007ce9f4);
  }
  else {
    uVar39 = uVar39 | 8;
    DAT_007ce9f4[4] = (u32)(DAT_00965930);
    puVar3[5] = auVar70._4_4_;
    puVar3[6] = auVar70._8_4_;
    puVar3[7] = auVar70._12_4_;
    auVar59 = _DAT_00965940;
    puVar3[8] = DAT_00965940;
    puVar3[9] = auVar59._4_4_;
    puVar3[10] = auVar59._8_4_;
    puVar3[0xb] = auVar59._12_4_;
    uVar51 = auVar59._8_8_;
    auVar59 = auVar70;
    puVar3 = (u32 *)(DAT_007ce9f4);
  }
  DAT_007ce9f4 = (u32 *)((u32)(puVar3 + 0xc));
  auVar53._8_8_ = auVar59._8_8_;
  DAT_007ceafc = 0;
  uVar61 = 0;
  if (DAT_007ceaac == 3) {
    uVar61 = 0x20;
    DAT_007ceafc = 0x20;
  }
  auVar42._8_8_ = uVar51;
  auVar42._0_8_ = uVar39;
  auVar53._0_8_ = (u32)DAT_007ceb00 << 0x20 | uVar61;
  auVar59 = _pcpyld(auVar53,auVar42);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar59 + 0));
  puVar3[0xd] = auVar59._4_4_;
  puVar3[0xe] = auVar59._8_4_;
  puVar3[0xf] = auVar59._12_4_;
  puVar3 = (u32 *)(DAT_007ce9f4);
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  auVar43._8_8_ = auVar59._8_8_;
  if (*(int *)(param_1 + 0x40) == 0) {
    auVar63._0_8_ = (long)(int)DAT_007ce9f4;
    auVar63._8_8_ = auVar62._8_8_;
    *DAT_007ce9f4 = in_zero_lo;
    puVar3[5] = in_zero_hi;
    puVar3[6] = in_zero_udw;
    puVar3[7] = in_register_0000000c;
    auVar36._8_8_ = extraout_v0_udw;
    auVar36._0_8_ = 0x5000000200000000;
    auVar14._8_8_ = 0;
    auVar14._0_8_ = auVar43._8_8_;
    puVar3[8] = in_zero_lo;
    puVar3[9] = in_zero_hi;
    puVar3[10] = in_zero_udw;
    puVar3[0xb] = in_register_0000000c;
    auVar59 = _pcpyld(auVar36,auVar14 << 0x40);
    puVar3[0xc] = auVar59._0_4_;
    puVar3[0xd] = auVar59._4_4_;
    puVar3[0xe] = auVar59._8_4_;
    puVar3[0xf] = auVar59._12_4_;
    auVar55._8_8_ = auVar53._8_8_;
    auVar55._0_8_ = 0xe;
    auVar37._8_8_ = auVar59._8_8_;
    auVar50._8_8_ = auVar43._8_8_;
    auVar50._0_8_ = 0x1000000000008001;
    auVar59 = _pcpyld(auVar55,auVar50);
    puVar3[0x10] = auVar59._0_4_;
    puVar3[0x11] = auVar59._4_4_;
    puVar3[0x12] = auVar59._8_4_;
    puVar3[0x13] = auVar59._12_4_;
    auVar37._0_8_ = 0x47;
    auVar44._8_8_ = auVar59._8_8_;
    auVar44._0_8_ = DAT_007cea40;
    auVar59 = _pcpyld(auVar37,auVar44);
    puVar3[0x14] = auVar59._0_4_;
    puVar3[0x15] = auVar59._4_4_;
    puVar3[0x16] = auVar59._8_4_;
    puVar3[0x17] = auVar59._12_4_;
  }
  else {
    auVar12._8_8_ = 0;
    auVar12._0_8_ = auVar43._8_8_;
    auVar28._8_8_ = extraout_v0_udw;
    auVar28._0_8_ = 0x5000000400000000;
    auVar59 = _pcpyld(auVar28,auVar12 << 0x40);
    *DAT_007ce9f4 = (*(u32*)((u8*)&auVar59 + 0));
    puVar3[5] = auVar59._4_4_;
    puVar3[6] = auVar59._8_4_;
    puVar3[7] = auVar59._12_4_;
    auVar62._0_8_ = 0xe;
    auVar29._8_8_ = auVar59._8_8_;
    auVar54._8_8_ = auVar53._8_8_;
    auVar54._0_8_ = 0x47;
    auVar29._0_8_ = 0x1000000000008003;
    auVar59 = _pcpyld(auVar62,auVar29);
    puVar3[8] = auVar59._0_4_;
    puVar3[9] = auVar59._4_4_;
    puVar3[10] = auVar59._8_4_;
    puVar3[0xb] = auVar59._12_4_;
    auVar43._0_8_ = 0x14;
    auVar63._8_8_ = auVar62._8_8_;
    auVar63._0_8_ = DAT_007cea40;
    auVar30._8_8_ = auVar59._8_8_;
    auVar30._0_8_ = 8;
    auVar59 = _pcpyld(auVar54,auVar63);
    puVar3[0xc] = auVar59._0_4_;
    puVar3[0xd] = auVar59._4_4_;
    puVar3[0xe] = auVar59._8_4_;
    puVar3[0xf] = auVar59._12_4_;
    auVar55._8_8_ = auVar59._8_8_;
    auVar55._0_8_ = DAT_007cea60;
    auVar59 = _pcpyld(auVar43,auVar55);
    puVar3[0x10] = auVar59._0_4_;
    puVar3[0x11] = auVar59._4_4_;
    puVar3[0x12] = auVar59._8_4_;
    puVar3[0x13] = auVar59._12_4_;
    auVar44._8_8_ = auVar59._8_8_;
    auVar44._0_8_ = DAT_007cea58;
    auVar59 = _pcpyld(auVar30,auVar44);
    puVar3[0x14] = auVar59._0_4_;
    puVar3[0x15] = auVar59._4_4_;
    puVar3[0x16] = auVar59._8_4_;
    puVar3[0x17] = auVar59._12_4_;
  }
  DAT_007ce9f4 = DAT_007ce9f4 + 0x14;
  auVar46._8_8_ = auVar44._8_8_;
  *(u8 *)(param_1 + 0x2b) =
       (u8)((int)(*(u8 *)(param_1 + 0x28) & 0x20) >> 5) |
       (u8)((int)(*(u8 *)(param_1 + 0x28) & 0x18) >> 2);
  puVar3 = (u32 *)(DAT_007ce9f4);
  uVar51 = auVar55._8_8_;
  puVar38 = (u32 *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + (u32)*(u8 *)(param_1 + 0x2b) * 4);
  auVar46._0_8_ = (long)(int)puVar38;
  uVar93 = *puVar38;
  if (DAT_007ceaf8 != uVar93) {
    auVar13._8_8_ = 0;
    auVar13._0_8_ = auVar63._8_8_;
    auVar63._0_8_ = auVar13._0_8_ << 0x40;
    auVar45._0_8_ = (u32)uVar93 << 0x20 | 0x50000000;
    auVar45._8_8_ = auVar46._8_8_;
    auVar46 = _pcpyld(auVar63,auVar45);
    *DAT_007ce9f4 = (*(u32*)((u8*)&auVar46 + 0));
    puVar3[1] = auVar46._4_4_;
    puVar3[2] = auVar46._8_4_;
    puVar3[3] = auVar46._12_4_;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    DAT_007ceaf8 = uVar93;
  }
  puVar3 = (u32 *)(DAT_007ce9f4);
  uVar39 = auVar46._8_8_;
  auVar64._8_8_ = auVar63._8_8_;
  iVar5 = **(int **)(param_1 + 0x30);
  auVar73._0_8_ = ((long)*(int *)(*(int *)(param_1 + 4) + 0x14) | 0x2000000U) << 0x20 | 0x3000000;
  auVar73._8_8_ = auVar72._8_8_;
  auVar64._0_8_ = (u32)*(u32 *)(iVar5 + 0x20) << 0x20 | 0x50000000;
  auVar59 = _pcpyld(auVar73,auVar64);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar59 + 0));
  puVar3[1] = auVar59._4_4_;
  puVar3[2] = auVar59._8_4_;
  puVar3[3] = auVar59._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  do {
    DI();
    SYNC(0x10);
  } while ((Status & 0x10000) != 0);
  *(int *)(iVar5 + 0x18) = *(int *)(iVar5 + 0x18) + 1;
  EI();
  *(int *)(iVar5 + 0x1c) = *(int *)(iVar5 + 0x1c) + 1;
  if (*(int *)(iVar5 + 0x1c) == 1) {
    ((code)FUN_004d51c0)();
  }
  uVar68 = auVar59._8_8_;
  ((code)FUN_004d59d0)(0,3);
  puVar3 = (u32 *)(DAT_007ce9f4);
  auVar18._8_8_ = 0;
  auVar18._0_8_ = uVar39;
  auVar31._8_8_ = extraout_v0_udw_00;
  auVar31._0_8_ = 0x50000002;
  auVar19._8_8_ = 0;
  auVar19._0_8_ = auVar72._8_8_;
  auVar70 = _ppacw(auVar31,auVar18 << 0x40);
  auVar65._8_8_ = uVar68;
  auVar65._0_8_ = 0xe;
  auVar56._8_8_ = uVar51;
  auVar56._0_8_ = 0x10000002;
  auVar59 = _ppacw(auVar19 << 0x40,auVar56);
  auVar59 = _ppacw(auVar70,auVar59);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar59 + 0));
  puVar3[1] = auVar59._4_4_;
  puVar3[2] = auVar59._8_4_;
  puVar3[3] = auVar59._12_4_;
  auVar57._8_8_ = uVar51;
  auVar57._0_8_ = 0x3d;
  auVar32._8_8_ = auVar59._8_8_;
  auVar32._0_8_ = 0x1000000000008001;
  auVar59 = _pcpyld(auVar65,auVar32);
  puVar3[4] = auVar59._0_4_;
  puVar3[5] = auVar59._4_4_;
  puVar3[6] = auVar59._8_4_;
  puVar3[7] = auVar59._12_4_;
  auVar47._8_8_ = uVar39;
  auVar47._0_8_ = DAT_007cea50;
  auVar59 = _pcpyld(auVar57,auVar47);
  puVar3[8] = auVar59._0_4_;
  puVar3[9] = auVar59._4_4_;
  puVar3[10] = auVar59._8_4_;
  puVar3[0xb] = auVar59._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 0xc;
  return 1;
}

// FUN_0046EA80 NONMATCHING

void FUN_0046ea80(u64 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (int)param_1;
  iVar2 = *(int *)(*(int *)(*(int *)(iVar3 + 0x2c) + 8) + DAT_007ce738);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(iVar2 + 0x80);
  }
  iVar1 = *(int *)(*(int *)(iVar3 + 4) + 0x18);
  *(int *)(*(int *)(iVar3 + 4) + 0x18) = iVar1 + iVar2 * 0x10;
  (*(code *)((u8 *)PTR_FUN_006b4ee4)[iVar2])(param_1);
  *(int *)(*(int *)(iVar3 + 4) + 0x18) = iVar1;
  return;
}

// FUN_0046EB10 NONMATCHING

u32 FUN_0046eb10(int param_1,u32 *param_2)

{
  int iVar1;
  u32 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x18);
  if ((*(u32 *)(iVar1 + 8) & 0x1000000) == 0) {
    uVar2 = *(u32 *)(iVar1 + DAT_0095de18);
    ((code)FUN_004a1430)();
    ((code)FUN_0046b1b0)(*(u32 *)(param_1 + 0x2c),uVar2,*param_2);
  }
  return 1;
}

// FUN_0046EB90 NONMATCHING

u64 FUN_0046eb90(int param_1,u32 *param_2)

{
  u8 bVar1;
  int iVar2;
  u32 *puVar3;
  u32 uVar4;
  u32 uVar5;
  u32 *puVar6;
  u32 *puVar7;
  u64 uVar8;
  Vec128 auVar9;
  u32 uVar10;
  u32 uVar11;
  u32 uVar12;
  int *piVar13;
  u32 uVar14;
  float *pfVar15;
  u64 *puVar16;
  int iVar17;
  float *pfVar18;
  u64 uVar19;
  u64 extraout_v0_udw;
  Vec128 auVar20;
  Vec128 auVar21;
  u64 in_a0_udw;
  u32 in_a1_udw;
  u32 in_register_0000005c;
  u32 uVar22;
  u32 uVar23;
  Vec128 auVar24;
  u32 uVar25;
  u32 uVar26;
  u32 uVar27;
  u32 uVar28;
  u32 uVar29;
  u32 uVar30;
  int iVar31;
  u32 uVar32;
  int iVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  int aiStack_70 [12];
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_20;
  float fStack_1c;
  
  iVar2 = *(int *)(param_1 + 8);
  iVar33 = *(int *)(iVar2 + 0x18);
  puVar3 = *(u32 **)(iVar33 + DAT_0095de18);
  uVar4 = *puVar3;
  *(u32 *)(param_1 + 0xc) = *(u32 *)(iVar33 + 0x54);
  if (*(int *)(iVar33 + 0x18) == 1) {
    piVar13 = (int *)(iVar33 + DAT_007ce890);
    bVar1 = 0;
    if (((u32 *)*piVar13 != (u32 *)0x0) &&
       ((u32)*(u16 *)(*(int *)(iVar33 + 0x54) + 4) == *(u32 *)*piVar13)) {
      bVar1 = 1;
    }
    if (bVar1) {
      iVar33 = *piVar13;
    }
    else {
      piVar13 = (int *)((code)FUN_0049e5a0)((short)piVar13,*(u16 *)(*(int *)(iVar33 + 0x54) + 4));
      iVar33 = *piVar13;
    }
    *(int *)(param_1 + 0x10) = iVar33;
  }
  else {
    piVar13 = (int *)(iVar2 + DAT_007ce88c);
    bVar1 = 0;
    if (((u32 *)*piVar13 != (u32 *)0x0) &&
       ((u32)*(u16 *)(*(int *)(iVar33 + 0x54) + 4) == *(u32 *)*piVar13)) {
      bVar1 = 1;
    }
    if (bVar1) {
      iVar33 = *piVar13;
    }
    else {
      piVar13 = (int *)((code)FUN_0049e5a0)((short)piVar13,*(u16 *)(*(int *)(iVar33 + 0x54) + 4));
      iVar33 = *piVar13;
    }
    *(int *)(param_1 + 0x10) = iVar33;
  }
  if (*(short *)(*(int *)(param_1 + 0xc) + 4) == 0) {
    uVar19 = 0;
  }
  else {
    *(u32 *)(param_1 + 0x20) = *(u32 *)(*(int *)(iVar2 + 0x18) + 0x18);
    if (1 < *(int *)(param_1 + 0x20)) {
      *(float *)(param_1 + 0x1c) = *(float *)(iVar2 + 0x58) * *(float *)(iVar2 + 0x5c);
    }
    iVar33 = *(int *)(iVar2 + 0x18);
    if ((*(u32 *)(iVar33 + 8) & 0x1000000) == 0) {
      *(u32 *)(param_1 + 0x18) =
           CONCAT22((u16)(((u32)*(u8 *)(iVar33 + 0x18) << 0x18) >> 0x10) |
                    (u16)*(u32 *)(iVar33 + 8) & 0x9f,
                    *(u16 *)(*(int *)(param_1 + 0xc) + 6));
      *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) & 0xfffffffe;
      iVar31 = *(int *)(*(int *)(param_1 + 0x10) + 4);
      if (iVar31 != 0) {
        uVar32 = *(u32 *)(iVar31 + 0x28);
        uVar5 = *(u32 *)(param_1 + 0x18);
        if (uVar5 != uVar32) {
          if (((uVar5 >> 0x10 & 0xff) == (uVar32 >> 0x10 & 0xff)) &&
             (uVar5 >> 0x18 == uVar32 >> 0x18)) {
            *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 4;
          }
          else {
            *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 8;
          }
        }
        if (*(u16 *)(iVar33 + 0xc) != 0) {
          if ((*(u16 *)(iVar33 + 0xc) & 1) == 0) {
            *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 2;
            *(u32 *)(param_1 + 0x14) =
                 *(u32 *)(param_1 + 0x14) | (u32)*(u16 *)(iVar33 + 0xc) << 3;
          }
          else {
            *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 8;
          }
        }
        if (((*(u32 *)(iVar2 + 0x4c) & 1) != 0) &&
           (((long)*(int *)(iVar31 + 0x40) != (long)*(short *)(iVar2 + 0x52) ||
            ((long)*(int *)(iVar31 + 0x3c) != (long)*(short *)(iVar2 + 0x50))))) {
          *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 4;
        }
      }
    }
    *(u16 *)(*(int *)(iVar2 + 0x18) + 0xc) = 0;
    *(u32 *)(iVar2 + 0x4c) = *(u32 *)(iVar2 + 0x4c) & 0xfffffffe;
    iVar33 = DAT_00960070 + 0x20;
    uVar14 = ((code)FUN_004cb2f0)((short)*(u32 *)(iVar2 + 4));
    ((code)FUN_004c2f30)((short)*param_2,uVar14,iVar33);
    iVar31 = 2;
    pfVar15 = (float *)((code)FUN_004912b0)((short)iVar2);
    iVar33 = 5;
    pfVar18 = (float *)(DAT_00960070 + DAT_007ceaa4 + 0x60);
    do {
      if (-pfVar15[3] <
          (pfVar15[2] * pfVar18[2] + *pfVar15 * *pfVar18 + pfVar15[1] * pfVar18[1]) - pfVar18[3]) {
        iVar31 = 1;
        break;
      }
      pfVar18 = pfVar18 + 5;
      bVar1 = iVar33 != 0;
      iVar33 = iVar33 + -1;
    } while (bVar1);
    uVar32 = **(u32 **)(param_1 + 0xc);
    if ((uVar32 & 1) == 1) {
      *(u8 *)(param_1 + 0x29) = 4;
      *(u8 *)(param_1 + 0x28) = DAT_007ceaf4;
    }
    else if (((uVar32 & 0xff) == 0) || ((uVar32 & 2) == 2)) {
      *(u8 *)(param_1 + 0x29) = 3;
      *(u8 *)(param_1 + 0x28) = DAT_007ceaf4 | 4;
    }
    else if ((uVar32 & 0x10) == 0x10) {
      *(u8 *)(param_1 + 0x29) = 4;
      *(u8 *)(param_1 + 0x28) = DAT_007ceaf4;
    }
    else if ((uVar32 & 8) == 8) {
      *(u8 *)(param_1 + 0x29) = 2;
      *(u8 *)(param_1 + 0x28) = DAT_007ceaf4 | 0x10;
    }
    else {
      *(u8 *)(param_1 + 0x29) = 1;
      *(u8 *)(param_1 + 0x28) = DAT_007ceaf4 | 0x14;
    }
    if (iVar31 != 2) {
      *(u8 *)(param_1 + 0x28) = *(u8 *)(param_1 + 0x28) | 2;
    }
    *(u8 *)(param_1 + 0x2a) = (*(u32 *)(*(int *)(iVar2 + 0x18) + 8) & 0x40) != 0;
    if (DAT_0095de34 == (code)0) {
      iVar33 = *(int *)(param_1 + 8);
      iVar31 = *(int *)(iVar33 + 0x18);
      if ((*(u32 *)(iVar31 + 8) & 0x20) != 0) {
        DAT_0096007a = DAT_0096007a + 1;
        iVar17 = ((code)FUN_004cb2f0)((short)*(u32 *)(iVar33 + 4));
        ((code)FUN_004c32a0)((short)&stack0x00000000 + -0x60,iVar17);
        if ((*(u32 *)(iVar17 + 0xc) & 3) == 3) {
          fStack_20 = 1.0;
          fStack_1c = 1.0;
        }
        else {
          fStack_20 = SQRT(fStack_38 * fStack_38 + fStack_40 * fStack_40 + fStack_3c * fStack_3c);
          fStack_1c = fStack_20;
          if (0.0 < fStack_20) {
            fStack_1c = 1.0 / fStack_20;
          }
        }
        iVar31 = *(int *)(iVar31 + 0x54);
        aiStack_70[0] = *(int *)(*(int *)(iVar31 + 0xc) + iVar31 + 0x18) + 0xc;
        ((code)FUN_00499c20)(0x430,aiStack_70);
        for (puVar6 = *(u32 **)(iVar33 + 100); puVar6 != (u32 *)(iVar33 + 100);
            puVar6 = (u32 *)*puVar6) {
          iVar31 = puVar6[2];
          for (puVar7 = *(u32 **)(iVar31 + 0x40); puVar7 != (u32 *)(iVar31 + 0x40);
              puVar7 = (u32 *)*puVar7) {
            iVar17 = puVar7[2];
            if (((iVar17 != 0) && (*(short *)(iVar17 + 0x3c) != DAT_0096007a)) &&
               ((*(u8 *)(iVar17 + 2) & 1) != 0)) {
              *(short *)(iVar17 + 0x3c) = DAT_0096007a;
              iVar17 = ((code)FUN_004cb2f0)((short)*(u32 *)(puVar7[2] + 4));
              pfVar18 = (float *)((code)FUN_004912b0)((short)iVar33);
              fVar36 = pfVar18[1] - *(float *)(iVar17 + 0x34);
              fVar37 = *pfVar18 - *(float *)(iVar17 + 0x30);
              fVar34 = pfVar18[2] - *(float *)(iVar17 + 0x38);
              fVar35 = pfVar18[3] + *(float *)(puVar7[2] + 0x14);
              if (fVar34 * fVar34 + fVar37 * fVar37 + fVar36 * fVar36 < fVar35 * fVar35) {
                ((code)FUN_004a0430)((short)puVar7[2],aiStack_70);
              }
            }
          }
        }
      }
    }
    else {
      (*DAT_0095de34)(1,*(u32 *)(param_1 + 8));
    }
    puVar16 = (u64 *)((code)FUN_0046b510)((short)iVar2,puVar3);
    uVar32 = uVar4 * 4;
    ((code)FUN_004d59d0)(0,uVar32 + 2);
    auVar24._8_8_ = extraout_v0_udw;
    auVar24._0_8_ = 0x1000101;
    (*(u16*)((u8*)&auVar21 + 2)) = (u16)uVar32 & 0xff | 0x6c00;
    (*(u16*)((u8*)&auVar21 + 0)) = 700;
    auVar21._4_4_ = 0;
    auVar21._8_8_ = in_a0_udw;
    auVar24 = _ppacw(auVar21,auVar24);
    auVar20._0_8_ = (u32)uVar32 | 0x10000000;
    auVar20._8_8_ = extraout_v0_udw;
    auVar9._4_4_ = in_register_0000005c;
    auVar9._0_4_ = in_a1_udw;
    auVar9._8_8_ = 0;
    auVar21 = _ppacw(auVar9 << 0x40,auVar20);
    auVar21 = _ppacw(auVar24,auVar21);
    puVar6 = (u32 *)(DAT_007ce9f4 + 4);
    uVar32 = 0;
    *DAT_007ce9f4 = (*(u32*)((u8*)&auVar21 + 0));
    DAT_007ce9f4[1] = (*(u32*)((u8*)&auVar21 + 4));
    DAT_007ce9f4[2] = (*(u32*)((u8*)&auVar21 + 8));
    DAT_007ce9f4[3] = (*(u32*)((u8*)&auVar21 + 12));
    if (uVar4 != 0) {
      if (8 < uVar4) {
        do {
          uVar27 = *(u32 *)(puVar16 + 2);
          uVar28 = *(u32 *)((int)puVar16 + 0x14);
          uVar29 = *(u32 *)(puVar16 + 3);
          uVar30 = *(u32 *)((int)puVar16 + 0x1c);
          uVar32 = uVar32 + 8;
          uVar19 = puVar16[4];
          uVar25 = *(u32 *)(puVar16 + 5);
          uVar26 = *(u32 *)((int)puVar16 + 0x2c);
          uVar14 = *(u32 *)(puVar16 + 6);
          uVar10 = *(u32 *)((int)puVar16 + 0x34);
          uVar11 = *(u32 *)(puVar16 + 7);
          uVar12 = *(u32 *)((int)puVar16 + 0x3c);
          uVar8 = *puVar16;
          uVar22 = *(u32 *)(puVar16 + 1);
          uVar23 = *(u32 *)((int)puVar16 + 0xc);
          *puVar6 = (int)uVar8;
          puVar6[1] = (int)((u32)uVar8 >> 0x20);
          puVar6[2] = uVar22;
          puVar6[3] = uVar23;
          puVar6[4] = uVar27;
          puVar6[5] = uVar28;
          puVar6[6] = uVar29;
          puVar6[7] = uVar30;
          puVar6[8] = (int)uVar19;
          puVar6[9] = (int)((u32)uVar19 >> 0x20);
          puVar6[10] = uVar25;
          puVar6[0xb] = uVar26;
          puVar6[0xc] = uVar14;
          puVar6[0xd] = uVar10;
          puVar6[0xe] = uVar11;
          puVar6[0xf] = uVar12;
          uVar27 = *(u32 *)(puVar16 + 10);
          uVar28 = *(u32 *)((int)puVar16 + 0x54);
          uVar29 = *(u32 *)(puVar16 + 0xb);
          uVar30 = *(u32 *)((int)puVar16 + 0x5c);
          uVar19 = puVar16[0xc];
          uVar25 = *(u32 *)(puVar16 + 0xd);
          uVar26 = *(u32 *)((int)puVar16 + 0x6c);
          uVar14 = *(u32 *)(puVar16 + 0xe);
          uVar10 = *(u32 *)((int)puVar16 + 0x74);
          uVar11 = *(u32 *)(puVar16 + 0xf);
          uVar12 = *(u32 *)((int)puVar16 + 0x7c);
          uVar8 = puVar16[8];
          uVar22 = *(u32 *)(puVar16 + 9);
          uVar23 = *(u32 *)((int)puVar16 + 0x4c);
          puVar6[0x10] = (int)uVar8;
          puVar6[0x11] = (int)((u32)uVar8 >> 0x20);
          puVar6[0x12] = uVar22;
          puVar6[0x13] = uVar23;
          puVar6[0x14] = uVar27;
          puVar6[0x15] = uVar28;
          puVar6[0x16] = uVar29;
          puVar6[0x17] = uVar30;
          puVar6[0x18] = (int)uVar19;
          puVar6[0x19] = (int)((u32)uVar19 >> 0x20);
          puVar6[0x1a] = uVar25;
          puVar6[0x1b] = uVar26;
          puVar6[0x1c] = uVar14;
          puVar6[0x1d] = uVar10;
          puVar6[0x1e] = uVar11;
          puVar6[0x1f] = uVar12;
          uVar27 = *(u32 *)(puVar16 + 0x12);
          uVar28 = *(u32 *)((int)puVar16 + 0x94);
          uVar29 = *(u32 *)(puVar16 + 0x13);
          uVar30 = *(u32 *)((int)puVar16 + 0x9c);
          uVar19 = puVar16[0x14];
          uVar25 = *(u32 *)(puVar16 + 0x15);
          uVar26 = *(u32 *)((int)puVar16 + 0xac);
          uVar14 = *(u32 *)(puVar16 + 0x16);
          uVar10 = *(u32 *)((int)puVar16 + 0xb4);
          uVar11 = *(u32 *)(puVar16 + 0x17);
          uVar12 = *(u32 *)((int)puVar16 + 0xbc);
          uVar8 = puVar16[0x10];
          uVar22 = *(u32 *)(puVar16 + 0x11);
          uVar23 = *(u32 *)((int)puVar16 + 0x8c);
          puVar6[0x20] = (int)uVar8;
          puVar6[0x21] = (int)((u32)uVar8 >> 0x20);
          puVar6[0x22] = uVar22;
          puVar6[0x23] = uVar23;
          puVar6[0x24] = uVar27;
          puVar6[0x25] = uVar28;
          puVar6[0x26] = uVar29;
          puVar6[0x27] = uVar30;
          puVar6[0x28] = (int)uVar19;
          puVar6[0x29] = (int)((u32)uVar19 >> 0x20);
          puVar6[0x2a] = uVar25;
          puVar6[0x2b] = uVar26;
          puVar6[0x2c] = uVar14;
          puVar6[0x2d] = uVar10;
          puVar6[0x2e] = uVar11;
          puVar6[0x2f] = uVar12;
          uVar27 = *(u32 *)(puVar16 + 0x1a);
          uVar28 = *(u32 *)((int)puVar16 + 0xd4);
          uVar29 = *(u32 *)(puVar16 + 0x1b);
          uVar30 = *(u32 *)((int)puVar16 + 0xdc);
          uVar19 = puVar16[0x1c];
          uVar25 = *(u32 *)(puVar16 + 0x1d);
          uVar26 = *(u32 *)((int)puVar16 + 0xec);
          uVar14 = *(u32 *)(puVar16 + 0x1e);
          uVar10 = *(u32 *)((int)puVar16 + 0xf4);
          uVar11 = *(u32 *)(puVar16 + 0x1f);
          uVar12 = *(u32 *)((int)puVar16 + 0xfc);
          uVar8 = puVar16[0x18];
          uVar22 = *(u32 *)(puVar16 + 0x19);
          uVar23 = *(u32 *)((int)puVar16 + 0xcc);
          puVar6[0x30] = (int)uVar8;
          puVar6[0x31] = (int)((u32)uVar8 >> 0x20);
          puVar6[0x32] = uVar22;
          puVar6[0x33] = uVar23;
          puVar6[0x34] = uVar27;
          puVar6[0x35] = uVar28;
          puVar6[0x36] = uVar29;
          puVar6[0x37] = uVar30;
          puVar6[0x38] = (int)uVar19;
          puVar6[0x39] = (int)((u32)uVar19 >> 0x20);
          puVar6[0x3a] = uVar25;
          puVar6[0x3b] = uVar26;
          puVar6[0x3c] = uVar14;
          puVar6[0x3d] = uVar10;
          puVar6[0x3e] = uVar11;
          puVar6[0x3f] = uVar12;
          uVar27 = *(u32 *)(puVar16 + 0x22);
          uVar28 = *(u32 *)((int)puVar16 + 0x114);
          uVar29 = *(u32 *)(puVar16 + 0x23);
          uVar30 = *(u32 *)((int)puVar16 + 0x11c);
          uVar19 = puVar16[0x24];
          uVar25 = *(u32 *)(puVar16 + 0x25);
          uVar26 = *(u32 *)((int)puVar16 + 300);
          uVar14 = *(u32 *)(puVar16 + 0x26);
          uVar10 = *(u32 *)((int)puVar16 + 0x134);
          uVar11 = *(u32 *)(puVar16 + 0x27);
          uVar12 = *(u32 *)((int)puVar16 + 0x13c);
          uVar8 = puVar16[0x20];
          uVar22 = *(u32 *)(puVar16 + 0x21);
          uVar23 = *(u32 *)((int)puVar16 + 0x10c);
          puVar6[0x40] = (int)uVar8;
          puVar6[0x41] = (int)((u32)uVar8 >> 0x20);
          puVar6[0x42] = uVar22;
          puVar6[0x43] = uVar23;
          puVar6[0x44] = uVar27;
          puVar6[0x45] = uVar28;
          puVar6[0x46] = uVar29;
          puVar6[0x47] = uVar30;
          puVar6[0x48] = (int)uVar19;
          puVar6[0x49] = (int)((u32)uVar19 >> 0x20);
          puVar6[0x4a] = uVar25;
          puVar6[0x4b] = uVar26;
          puVar6[0x4c] = uVar14;
          puVar6[0x4d] = uVar10;
          puVar6[0x4e] = uVar11;
          puVar6[0x4f] = uVar12;
          uVar27 = *(u32 *)(puVar16 + 0x2a);
          uVar28 = *(u32 *)((int)puVar16 + 0x154);
          uVar29 = *(u32 *)(puVar16 + 0x2b);
          uVar30 = *(u32 *)((int)puVar16 + 0x15c);
          uVar19 = puVar16[0x2c];
          uVar25 = *(u32 *)(puVar16 + 0x2d);
          uVar26 = *(u32 *)((int)puVar16 + 0x16c);
          uVar14 = *(u32 *)(puVar16 + 0x2e);
          uVar10 = *(u32 *)((int)puVar16 + 0x174);
          uVar11 = *(u32 *)(puVar16 + 0x2f);
          uVar12 = *(u32 *)((int)puVar16 + 0x17c);
          uVar8 = puVar16[0x28];
          uVar22 = *(u32 *)(puVar16 + 0x29);
          uVar23 = *(u32 *)((int)puVar16 + 0x14c);
          puVar6[0x50] = (int)uVar8;
          puVar6[0x51] = (int)((u32)uVar8 >> 0x20);
          puVar6[0x52] = uVar22;
          puVar6[0x53] = uVar23;
          puVar6[0x54] = uVar27;
          puVar6[0x55] = uVar28;
          puVar6[0x56] = uVar29;
          puVar6[0x57] = uVar30;
          puVar6[0x58] = (int)uVar19;
          puVar6[0x59] = (int)((u32)uVar19 >> 0x20);
          puVar6[0x5a] = uVar25;
          puVar6[0x5b] = uVar26;
          puVar6[0x5c] = uVar14;
          puVar6[0x5d] = uVar10;
          puVar6[0x5e] = uVar11;
          puVar6[0x5f] = uVar12;
          uVar27 = *(u32 *)(puVar16 + 0x32);
          uVar28 = *(u32 *)((int)puVar16 + 0x194);
          uVar29 = *(u32 *)(puVar16 + 0x33);
          uVar30 = *(u32 *)((int)puVar16 + 0x19c);
          uVar19 = puVar16[0x34];
          uVar25 = *(u32 *)(puVar16 + 0x35);
          uVar26 = *(u32 *)((int)puVar16 + 0x1ac);
          uVar14 = *(u32 *)(puVar16 + 0x36);
          uVar10 = *(u32 *)((int)puVar16 + 0x1b4);
          uVar11 = *(u32 *)(puVar16 + 0x37);
          uVar12 = *(u32 *)((int)puVar16 + 0x1bc);
          uVar8 = puVar16[0x30];
          uVar22 = *(u32 *)(puVar16 + 0x31);
          uVar23 = *(u32 *)((int)puVar16 + 0x18c);
          puVar6[0x60] = (int)uVar8;
          puVar6[0x61] = (int)((u32)uVar8 >> 0x20);
          puVar6[0x62] = uVar22;
          puVar6[99] = uVar23;
          puVar6[100] = uVar27;
          puVar6[0x65] = uVar28;
          puVar6[0x66] = uVar29;
          puVar6[0x67] = uVar30;
          puVar6[0x68] = (int)uVar19;
          puVar6[0x69] = (int)((u32)uVar19 >> 0x20);
          puVar6[0x6a] = uVar25;
          puVar6[0x6b] = uVar26;
          puVar6[0x6c] = uVar14;
          puVar6[0x6d] = uVar10;
          puVar6[0x6e] = uVar11;
          puVar6[0x6f] = uVar12;
          uVar27 = *(u32 *)(puVar16 + 0x3a);
          uVar28 = *(u32 *)((int)puVar16 + 0x1d4);
          uVar29 = *(u32 *)(puVar16 + 0x3b);
          uVar30 = *(u32 *)((int)puVar16 + 0x1dc);
          uVar19 = puVar16[0x3c];
          uVar25 = *(u32 *)(puVar16 + 0x3d);
          uVar26 = *(u32 *)((int)puVar16 + 0x1ec);
          uVar14 = *(u32 *)(puVar16 + 0x3e);
          uVar10 = *(u32 *)((int)puVar16 + 500);
          uVar11 = *(u32 *)(puVar16 + 0x3f);
          uVar12 = *(u32 *)((int)puVar16 + 0x1fc);
          uVar8 = puVar16[0x38];
          uVar22 = *(u32 *)(puVar16 + 0x39);
          uVar23 = *(u32 *)((int)puVar16 + 0x1cc);
          puVar6[0x70] = (int)uVar8;
          puVar6[0x71] = (int)((u32)uVar8 >> 0x20);
          puVar6[0x72] = uVar22;
          puVar6[0x73] = uVar23;
          puVar16 = puVar16 + 0x40;
          puVar6[0x74] = uVar27;
          puVar6[0x75] = uVar28;
          puVar6[0x76] = uVar29;
          puVar6[0x77] = uVar30;
          puVar6[0x78] = (int)uVar19;
          puVar6[0x79] = (int)((u32)uVar19 >> 0x20);
          puVar6[0x7a] = uVar25;
          puVar6[0x7b] = uVar26;
          puVar6[0x7c] = uVar14;
          puVar6[0x7d] = uVar10;
          puVar6[0x7e] = uVar11;
          puVar6[0x7f] = uVar12;
          puVar6 = puVar6 + 0x80;
        } while (uVar32 < uVar4 - 8);
      }
      for (; uVar32 < uVar4; uVar32 = uVar32 + 1) {
        uVar19 = puVar16[2];
        uVar28 = *(u32 *)(puVar16 + 3);
        uVar29 = *(u32 *)((int)puVar16 + 0x1c);
        uVar14 = *(u32 *)(puVar16 + 4);
        uVar10 = *(u32 *)((int)puVar16 + 0x24);
        uVar11 = *(u32 *)(puVar16 + 5);
        uVar12 = *(u32 *)((int)puVar16 + 0x2c);
        uVar8 = puVar16[6];
        uVar26 = *(u32 *)(puVar16 + 7);
        uVar27 = *(u32 *)((int)puVar16 + 0x3c);
        uVar22 = *(u32 *)((int)puVar16 + 4);
        uVar23 = *(u32 *)(puVar16 + 1);
        uVar25 = *(u32 *)((int)puVar16 + 0xc);
        *puVar6 = *(u32 *)puVar16;
        puVar6[1] = uVar22;
        puVar6[2] = uVar23;
        puVar6[3] = uVar25;
        puVar16 = puVar16 + 8;
        puVar6[4] = (int)uVar19;
        puVar6[5] = (int)((u32)uVar19 >> 0x20);
        puVar6[6] = uVar28;
        puVar6[7] = uVar29;
        puVar6[8] = uVar14;
        puVar6[9] = uVar10;
        puVar6[10] = uVar11;
        puVar6[0xb] = uVar12;
        puVar6[0xc] = (int)uVar8;
        puVar6[0xd] = (int)((u32)uVar8 >> 0x20);
        puVar6[0xe] = uVar26;
        puVar6[0xf] = uVar27;
        puVar6 = puVar6 + 0x10;
      }
    }
    uVar19 = 1;
    DAT_007ce9f4 = (u32 *)((u32)(puVar6));
  }
  return uVar19;
}

// FUN_0046F400 NONMATCHING

u64 FUN_0046f400(u32 *param_1,u32 *param_2)

{
  long lVar1;
  u8 bVar2;
  Vec128 auVar3;
  float *pfVar4;
  float fVar5;
  u64 in_v0_udw;
  u32 in_v1_udw;
  u32 in_register_0000003c;
  u32 *puVar6;
  u64 in_a0_udw;
  Vec128 auVar7;
  Vec128 auVar8;
  u32 *puVar9;
  u32 in_a1_udw;
  u32 in_register_0000005c;
  Vec128 auVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  
  iVar14 = 0;
  iVar12 = DAT_0095ef98;
  iVar13 = DAT_0095efc4;
  if (0 < DAT_0095efc8) {
    do {
      iVar15 = 0;
      do {
        iVar11 = iVar12;
        puVar6 = param_1;
        puVar9 = param_2;
        iVar15 = iVar15 + 7;
        *puVar6 = *(u32 *)(iVar11 + 4);
        puVar6[1] = *(u32 *)(iVar11 + 8);
        *puVar9 = *(u32 *)(iVar11 + 0xc);
        puVar9[1] = *(u32 *)(iVar11 + 0x10);
        puVar9[2] = *(u32 *)(iVar11 + 0x14);
        puVar6[2] = *(u32 *)(iVar11 + 0x1c);
        puVar6[3] = *(u32 *)(iVar11 + 0x20);
        puVar9[3] = *(u32 *)(iVar11 + 0x24);
        puVar9[4] = *(u32 *)(iVar11 + 0x28);
        puVar9[5] = *(u32 *)(iVar11 + 0x2c);
        puVar6[4] = *(u32 *)(iVar11 + 0x34);
        puVar6[5] = *(u32 *)(iVar11 + 0x38);
        puVar9[6] = *(u32 *)(iVar11 + 0x3c);
        puVar9[7] = *(u32 *)(iVar11 + 0x40);
        puVar9[8] = *(u32 *)(iVar11 + 0x44);
        puVar6[6] = *(u32 *)(iVar11 + 0x4c);
        puVar6[7] = *(u32 *)(iVar11 + 0x50);
        puVar9[9] = *(u32 *)(iVar11 + 0x54);
        puVar9[10] = *(u32 *)(iVar11 + 0x58);
        puVar9[0xb] = *(u32 *)(iVar11 + 0x5c);
        puVar6[8] = *(u32 *)(iVar11 + 100);
        puVar6[9] = *(u32 *)(iVar11 + 0x68);
        puVar9[0xc] = *(u32 *)(iVar11 + 0x6c);
        puVar9[0xd] = *(u32 *)(iVar11 + 0x70);
        puVar9[0xe] = *(u32 *)(iVar11 + 0x74);
        puVar6[10] = *(u32 *)(iVar11 + 0x7c);
        puVar6[0xb] = *(u32 *)(iVar11 + 0x80);
        puVar9[0xf] = *(u32 *)(iVar11 + 0x84);
        puVar9[0x10] = *(u32 *)(iVar11 + 0x88);
        puVar9[0x11] = *(u32 *)(iVar11 + 0x8c);
        puVar6[0xc] = *(u32 *)(iVar11 + 0x94);
        puVar6[0xd] = *(u32 *)(iVar11 + 0x98);
        puVar9[0x12] = *(u32 *)(iVar11 + 0x9c);
        puVar9[0x13] = *(u32 *)(iVar11 + 0xa0);
        puVar9[0x14] = *(u32 *)(iVar11 + 0xa4);
        param_2 = puVar9 + 0x15;
        param_1 = puVar6 + 0xe;
        iVar12 = iVar11 + 0xa8;
      } while (iVar15 < 0x20);
      iVar14 = iVar14 + 1;
      iVar12 = iVar11 + 0x108;
      iVar13 = iVar13 + -0x28;
      puVar6[0xe] = *(u32 *)(iVar11 + 0xac);
      puVar6[0xf] = *(u32 *)(iVar11 + 0xb0);
      puVar9[0x15] = *(u32 *)(iVar11 + 0xb4);
      puVar9[0x16] = *(u32 *)(iVar11 + 0xb8);
      puVar9[0x17] = *(u32 *)(iVar11 + 0xbc);
      puVar6[0x10] = *(u32 *)(iVar11 + 0xc4);
      puVar6[0x11] = *(u32 *)(iVar11 + 200);
      puVar9[0x18] = *(u32 *)(iVar11 + 0xcc);
      puVar9[0x19] = *(u32 *)(iVar11 + 0xd0);
      puVar9[0x1a] = *(u32 *)(iVar11 + 0xd4);
      puVar6[0x12] = *(u32 *)(iVar11 + 0xdc);
      puVar6[0x13] = *(u32 *)(iVar11 + 0xe0);
      puVar9[0x1b] = *(u32 *)(iVar11 + 0xe4);
      puVar9[0x1c] = *(u32 *)(iVar11 + 0xe8);
      puVar9[0x1d] = *(u32 *)(iVar11 + 0xec);
      puVar6[0x14] = *(u32 *)(iVar11 + 0xf4);
      puVar6[0x15] = *(u32 *)(iVar11 + 0xf8);
      puVar9[0x1e] = *(u32 *)(iVar11 + 0xfc);
      puVar9[0x1f] = *(u32 *)(iVar11 + 0x100);
      puVar9[0x20] = *(u32 *)(iVar11 + 0x104);
      puVar6[0x16] = *(u32 *)(iVar11 + 0x10c);
      puVar6[0x17] = *(u32 *)(iVar11 + 0x110);
      param_1 = puVar6 + 0x18;
      puVar9[0x21] = *(u32 *)(iVar11 + 0x114);
      puVar9[0x22] = *(u32 *)(iVar11 + 0x118);
      puVar9[0x23] = *(u32 *)(iVar11 + 0x11c);
      param_2 = puVar9 + 0x24;
    } while (iVar14 < DAT_0095efc8);
  }
  iVar14 = 0;
  if (0 < iVar13) {
    if (8 < iVar13) {
      bVar2 = 0;
      if ((-1 < iVar13) && (iVar13 < 0x7fffffff)) {
        bVar2 = 1;
      }
      if (bVar2) {
        do {
          iVar14 = iVar14 + 8;
          *param_1 = *(u32 *)(iVar12 + 4);
          param_1[1] = *(u32 *)(iVar12 + 8);
          *param_2 = *(u32 *)(iVar12 + 0xc);
          param_2[1] = *(u32 *)(iVar12 + 0x10);
          param_2[2] = *(u32 *)(iVar12 + 0x14);
          param_1[2] = *(u32 *)(iVar12 + 0x1c);
          param_1[3] = *(u32 *)(iVar12 + 0x20);
          param_2[3] = *(u32 *)(iVar12 + 0x24);
          param_2[4] = *(u32 *)(iVar12 + 0x28);
          param_2[5] = *(u32 *)(iVar12 + 0x2c);
          param_1[4] = *(u32 *)(iVar12 + 0x34);
          param_1[5] = *(u32 *)(iVar12 + 0x38);
          param_2[6] = *(u32 *)(iVar12 + 0x3c);
          param_2[7] = *(u32 *)(iVar12 + 0x40);
          param_2[8] = *(u32 *)(iVar12 + 0x44);
          param_1[6] = *(u32 *)(iVar12 + 0x4c);
          param_1[7] = *(u32 *)(iVar12 + 0x50);
          param_2[9] = *(u32 *)(iVar12 + 0x54);
          param_2[10] = *(u32 *)(iVar12 + 0x58);
          param_2[0xb] = *(u32 *)(iVar12 + 0x5c);
          param_1[8] = *(u32 *)(iVar12 + 100);
          param_1[9] = *(u32 *)(iVar12 + 0x68);
          param_2[0xc] = *(u32 *)(iVar12 + 0x6c);
          param_2[0xd] = *(u32 *)(iVar12 + 0x70);
          param_2[0xe] = *(u32 *)(iVar12 + 0x74);
          param_1[10] = *(u32 *)(iVar12 + 0x7c);
          param_1[0xb] = *(u32 *)(iVar12 + 0x80);
          param_2[0xf] = *(u32 *)(iVar12 + 0x84);
          param_2[0x10] = *(u32 *)(iVar12 + 0x88);
          param_2[0x11] = *(u32 *)(iVar12 + 0x8c);
          param_1[0xc] = *(u32 *)(iVar12 + 0x94);
          param_1[0xd] = *(u32 *)(iVar12 + 0x98);
          param_2[0x12] = *(u32 *)(iVar12 + 0x9c);
          param_2[0x13] = *(u32 *)(iVar12 + 0xa0);
          param_2[0x14] = *(u32 *)(iVar12 + 0xa4);
          param_1[0xe] = *(u32 *)(iVar12 + 0xac);
          param_1[0xf] = *(u32 *)(iVar12 + 0xb0);
          param_1 = param_1 + 0x10;
          param_2[0x15] = *(u32 *)(iVar12 + 0xb4);
          param_2[0x16] = *(u32 *)(iVar12 + 0xb8);
          param_2[0x17] = *(u32 *)(iVar12 + 0xbc);
          iVar12 = iVar12 + 0xc0;
          param_2 = param_2 + 0x18;
        } while (iVar14 < iVar13 + -8);
      }
    }
    for (; iVar14 < iVar13; iVar14 = iVar14 + 1) {
      *param_1 = *(u32 *)(iVar12 + 4);
      param_1[1] = *(u32 *)(iVar12 + 8);
      param_1 = param_1 + 2;
      *param_2 = *(u32 *)(iVar12 + 0xc);
      param_2[1] = *(u32 *)(iVar12 + 0x10);
      param_2[2] = *(u32 *)(iVar12 + 0x14);
      iVar12 = iVar12 + 0x18;
      param_2 = param_2 + 3;
    }
  }
  lVar1 = ((code)FUN_004d59d0)(0,0xb);
  pfVar4 = (float *)DAT_007ce9f4;
  if (lVar1 == 0) {
    ((code)FUN_005225a8)(0x6b5750,s_G3_2DStroke_Node_c_006b5770,0x10a);
  }
  else {
    auVar8._8_8_ = in_v0_udw;
    auVar8._0_8_ = 0x1000101;
    auVar10._8_4_ = in_v1_udw;
    auVar10._0_8_ = 0x6c0903cf;
    auVar10._12_4_ = in_register_0000003c;
    auVar10 = _ppacw(auVar10,auVar8);
    auVar7._8_8_ = in_a0_udw;
    auVar7._0_8_ = 0x10000009;
    auVar3._4_4_ = in_register_0000005c;
    auVar3._0_4_ = in_a1_udw;
    auVar3._8_8_ = 0;
    auVar8 = _ppacw(auVar3 << 0x40,auVar7);
    auVar8 = _ppacw(auVar10,auVar8);
    *DAT_007ce9f4 = (*(u32*)((u8*)&auVar8 + 0));
    pfVar4[1] = auVar8._4_4_;
    pfVar4[2] = auVar8._8_4_;
    pfVar4[3] = auVar8._12_4_;
    fVar16 = DAT_0095efa4;
    fVar19 = DAT_0095efa0;
    fVar5 = DAT_0095ef58;
    pfVar4 = (float *)DAT_007ce9f4;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    *DAT_007ce9f4 = DAT_0095ef88[0x1c];
    pfVar4[5] = fVar19;
    pfVar4[6] = fVar5;
    pfVar4[7] = fVar16;
    pfVar4 = (float *)DAT_007ce9f4;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    if (DAT_0095ef88[0x1a] == 0.0) {
      fVar5 = 1.0;
      fVar19 = *DAT_0095ef88;
    }
    else {
      fVar5 = 0.50235295;
      fVar19 = *DAT_0095ef88;
    }
    fVar17 = DAT_0095ef88[1];
    fVar18 = DAT_0095ef88[2];
    fVar16 = DAT_0095ef88[3];
    *DAT_007ce9f4 = fVar19 * fVar5;
    pfVar4[5] = fVar17 * fVar5;
    pfVar4[6] = fVar18 * fVar5;
    pfVar4[7] = fVar16 * 0.50235295;
    pfVar4 = (float *)DAT_007ce9f4;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    fVar16 = DAT_0095ef88[7];
    fVar17 = DAT_0095ef88[8];
    fVar19 = DAT_0095ef88[9];
    *DAT_007ce9f4 = DAT_0095ef88[6] * fVar5;
    pfVar4[5] = fVar16 * fVar5;
    pfVar4[6] = fVar17 * fVar5;
    pfVar4[7] = fVar19 * 0.50235295;
    pfVar4 = (float *)DAT_007ce9f4;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    fVar16 = DAT_0095ef88[0xd];
    fVar17 = DAT_0095ef88[0xe];
    fVar19 = DAT_0095ef88[0xf];
    *DAT_007ce9f4 = DAT_0095ef88[0xc] * fVar5;
    pfVar4[5] = fVar16 * fVar5;
    pfVar4[6] = fVar17 * fVar5;
    pfVar4[7] = fVar19 * 0.50235295;
    pfVar4 = (float *)DAT_007ce9f4;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    fVar19 = DAT_0095ef88[0x15];
    fVar16 = DAT_0095ef88[0x13];
    fVar17 = DAT_0095ef88[0x14];
    *DAT_007ce9f4 = DAT_0095ef88[0x12] * fVar5;
    pfVar4[5] = fVar16 * fVar5;
    pfVar4[6] = fVar17 * fVar5;
    pfVar4[7] = fVar19 * 0.50235295;
    pfVar4 = (float *)DAT_007ce9f4;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    fVar5 = DAT_0095ef88[5];
    *DAT_007ce9f4 = DAT_0095ef88[4];
    pfVar4[5] = fVar5;
    pfVar4[6] = 0.0;
    pfVar4[7] = 0.0;
    pfVar4 = (float *)DAT_007ce9f4;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    fVar5 = DAT_0095ef88[0xb];
    *DAT_007ce9f4 = DAT_0095ef88[10];
    pfVar4[5] = fVar5;
    pfVar4[6] = 0.0;
    pfVar4[7] = 0.0;
    pfVar4 = (float *)DAT_007ce9f4;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    fVar5 = DAT_0095ef88[0x11];
    *DAT_007ce9f4 = DAT_0095ef88[0x10];
    pfVar4[5] = fVar5;
    pfVar4[6] = 0.0;
    pfVar4[7] = 0.0;
    pfVar4 = (float *)DAT_007ce9f4;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    fVar5 = DAT_0095ef88[0x17];
    *DAT_007ce9f4 = DAT_0095ef88[0x16];
    pfVar4[5] = fVar5;
    pfVar4[6] = 0.0;
    pfVar4[7] = 0.0;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
  }
  return 1;
}

// FUN_0046FDD0 NONMATCHING



u64 FUN_0046fdd0(int param_1)

{
  u8 bVar1;
  u32 uVar2;
  int iVar3;
  u8 bVar4;
  Vec128 auVar5;
  Vec128 auVar6;
  Vec128 auVar7;
  Vec128 auVar8;
  Vec128 auVar9;
  u32 *puVar10;
  u32 uVar11;
  u32 uVar12;
  Vec128 in_zero_qw;
  u32 uVar13;
  u32 uVar14;
  u64 extraout_v0_udw;
  Vec128 auVar15;
  Vec128 auVar16;
  Vec128 auVar17;
  Vec128 auVar18;
  u64 extraout_v0_udw_00;
  Vec128 auVar19;
  u64 extraout_v0_udw_01;
  Vec128 auVar20;
  Vec128 auVar21;
  Vec128 auVar22;
  u32 in_v1_udw;
  u64 uVar24;
  Vec128 auVar23;
  u32 uVar25;
  u32 in_a0_udw;
  Vec128 auVar26;
  Vec128 auVar27;
  u32 in_a1_udw;
  Vec128 auVar28;
  Vec128 auVar29;
  u32 in_a2_udw;
  Vec128 auVar30;
  Vec128 auVar31;
  
  ((code)FUN_004d59d0)(0,0xd);
  puVar10 = (u32 *)(DAT_007ce9f4);
  auVar31._8_8_ = 0;
  auVar31._0_8_ = in_v1_udw;
  auVar15._8_8_ = extraout_v0_udw;
  auVar15._0_8_ = 0x1000000a;
  auVar31 = _pcpyld(auVar31 << 0x40,auVar15);
  auVar5._8_8_ = 0;
  auVar5._0_8_ = in_a2_udw;
  auVar16._8_8_ = extraout_v0_udw;
  auVar16._0_8_ = 0x6c0103fa01000404;
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar31 + 0));
  puVar10[1] = auVar31._4_4_;
  puVar10[2] = auVar31._8_4_;
  puVar10[3] = auVar31._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  *(u8 *)(param_1 + 0x47) = 0xfe;
  puVar10 = (u32 *)(DAT_007ce9f4);
  auVar31 = _pcpyld(auVar16,auVar5 << 0x40);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar31 + 0));
  puVar10[1] = auVar31._4_4_;
  puVar10[2] = auVar31._8_4_;
  puVar10[3] = auVar31._12_4_;
  puVar10 = (u32 *)(DAT_007ce9f4);
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  bVar4 = *(char *)(param_1 + 0x47) != -1;
  DAT_007ceab4 = (u32)bVar4;
  if (bVar4 || DAT_007ceab8 != 0) {
    DAT_007cddc0 = DAT_007cddc0 | 0x40;
  }
  else {
    DAT_007cddc0 = DAT_007cddc0 & 0xffffffffffffffbf;
  }
  uVar14 = DAT_007cddc0;
  auVar30._8_8_ = in_a2_udw;
  auVar30._0_8_ = 0xfc007fffffffffff;
  auVar17._4_4_ = DAT_009658ac;
  auVar17._0_4_ = DAT_009658a8;
  auVar17._8_8_ = extraout_v0_udw;
  auVar31 = _pcpyld(in_zero_qw,auVar30);
  auVar26._0_8_ =
       CONCAT44((*(u32*)((u8*)&DAT_009658a0 + 4)),(u32)DAT_009658a0) & (*(u64*)((u8*)&auVar31 + 0)) |
       ((long)(int)((u32)DAT_007cddc0 | (u32)*(u8 *)(param_1 + 0x29)) & 0x7ffU) << 0x2f;
  auVar26._8_8_ = in_a0_udw;
  auVar31 = _pcpyld(auVar17,auVar26);
  (*(u32*)((u8*)&DAT_009658a0 + 0)) = (*(u32*)((u8*)&auVar31 + 0));
  (*(u32*)((u8*)&DAT_009658a0 + 4)) = (*(u32*)((u8*)&auVar31 + 4));
  DAT_009658a8 = auVar31._8_4_;
  DAT_009658ac = auVar31._12_4_;
  *DAT_007ce9f4 = (u32)DAT_009658a0;
  puVar10[5] = auVar31._4_4_;
  puVar10[6] = auVar31._8_4_;
  puVar10[7] = auVar31._12_4_;
  auVar6._8_8_ = 0;
  auVar6._0_8_ = auVar31._8_8_;
  auVar18._8_8_ = extraout_v0_udw;
  auVar18._0_8_ = 0x6c0103fb01000404;
  auVar31 = _pcpyld(auVar18,auVar6 << 0x40);
  puVar10[8] = auVar31._0_4_;
  puVar10[9] = auVar31._4_4_;
  puVar10[10] = auVar31._8_4_;
  puVar10[0xb] = auVar31._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 8;
  if ((uVar14 & 0x10) == 0) {
    uVar13 = 0x3b808081;
  }
  else {
    uVar13 = 0x3b011b50;
  }
  ((code)FUN_0049cab0)(uVar13,param_1 + 0x44);
  puVar10 = (u32 *)(DAT_007ce9f4);
  auVar7._8_8_ = 0;
  auVar7._0_8_ = in_a0_udw;
  auVar19._8_8_ = extraout_v0_udw_00;
  auVar19._0_8_ = 0x6c0103fc01000404;
  auVar31 = _pcpyld(auVar19,auVar7 << 0x40);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar31 + 0));
  puVar10[1] = auVar31._4_4_;
  puVar10[2] = auVar31._8_4_;
  puVar10[3] = auVar31._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  uVar24 = auVar31._8_8_;
  ((code)FUN_0049cbd0)(*(u32 *)(param_1 + 0x1c),*(u32 *)(param_1 + 0x3c));
  puVar10 = (u32 *)(DAT_007ce9f4);
  bVar1 = *(u8 *)(param_1 + 0x28);
  auVar8._8_8_ = 0;
  auVar8._0_8_ = in_a1_udw;
  auVar23._8_8_ = uVar24;
  auVar23._0_8_ = 0x6c0303fd01000404;
  uVar14 = (u32)bVar1 & 7;
  auVar31 = _pcpyld(auVar23,auVar8 << 0x40);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar31 + 0));
  puVar10[1] = auVar31._4_4_;
  puVar10[2] = auVar31._8_4_;
  puVar10[3] = auVar31._12_4_;
  auVar5 = _DAT_00965930;
  auVar31 = _DAT_00965910;
  puVar10 = (u32 *)(DAT_007ce9f4);
  if (((DAT_007ceb04 == 0) || ((bVar1 & 4) != 0)) && ((DAT_007cdde8 == 0 || ((bVar1 & 4) == 0)))) {
    DAT_007ce9f4[4] = (u32)(DAT_00965910);
    puVar10[5] = auVar31._4_4_;
    puVar10[6] = auVar31._8_4_;
    puVar10[7] = auVar31._12_4_;
    uVar12 = DAT_0096592c;
    uVar11 = DAT_00965928;
    uVar13 = DAT_00965924;
    puVar10[8] = DAT_00965920;
    puVar10[9] = uVar13;
    puVar10[10] = uVar11;
    puVar10[0xb] = uVar12;
    puVar10 = (u32 *)(DAT_007ce9f4);
  }
  else {
    uVar14 = uVar14 | 8;
    DAT_007ce9f4[4] = (u32)(DAT_00965930);
    puVar10[5] = auVar5._4_4_;
    puVar10[6] = auVar5._8_4_;
    puVar10[7] = auVar5._12_4_;
    uVar12 = DAT_0096594c;
    uVar11 = DAT_00965948;
    uVar13 = DAT_00965944;
    puVar10[8] = DAT_00965940;
    puVar10[9] = uVar13;
    puVar10[10] = uVar11;
    puVar10[0xb] = uVar12;
    auVar31 = auVar5;
    puVar10 = (u32 *)(DAT_007ce9f4);
  }
  DAT_007ce9f4 = (u32 *)((u32)(puVar10 + 0xc));
  DAT_007ceafc = 0;
  auVar27._8_8_ = auVar31._8_8_;
  uVar25 = 0;
  if (DAT_007ceaac == 3) {
    uVar25 = 0x20;
    DAT_007ceafc = 0x20;
  }
  auVar20._8_8_ = extraout_v0_udw_01;
  auVar20._0_8_ = uVar14;
  (*(u64*)((u8*)&auVar28 + 4)) = in_a1_udw;
  auVar28._0_4_ = DAT_007ceb00;
  auVar28._12_4_ = 0;
  auVar28._0_8_ = auVar28._0_8_ << 0x20;
  auVar27._0_8_ = (u32)DAT_007ceb00 << 0x20 | uVar25;
  auVar31 = _pcpyld(auVar27,auVar20);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar31 + 0));
  puVar10[0xd] = auVar31._4_4_;
  puVar10[0xe] = auVar31._8_4_;
  puVar10[0xf] = auVar31._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  *(u8 *)(param_1 + 0x2b) = *(int *)(DAT_0095ef84 + 0x14) != 1;
  puVar10 = (u32 *)(DAT_007ce9f4);
  uVar2 = *(u32 *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + (u32)*(u8 *)(param_1 + 0x2b) * 4);
  if (DAT_007ceaf8 != uVar2) {
    auVar9._8_8_ = 0;
    auVar9._0_8_ = in_a1_udw;
    auVar28._0_8_ = auVar9._0_8_ << 0x40;
    auVar21._0_8_ = (u32)uVar2 << 0x20 | 0x50000000;
    auVar21._8_8_ = extraout_v0_udw_01;
    auVar31 = _pcpyld(auVar28,auVar21);
    *DAT_007ce9f4 = (*(u32*)((u8*)&auVar31 + 0));
    puVar10[1] = auVar31._4_4_;
    puVar10[2] = auVar31._8_4_;
    puVar10[3] = auVar31._12_4_;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    DAT_007ceaf8 = uVar2;
  }
  auVar29._8_8_ = auVar28._8_8_;
  *(u32 *)(**(int **)(param_1 + 0x30) + 0x1c) = 1;
  puVar10 = (u32 *)(DAT_007ce9f4);
  iVar3 = **(int **)(param_1 + 0x30);
  auVar29._0_8_ = ((long)*(int *)(*(int *)(param_1 + 4) + 0x14) | 0x2000000U) << 0x20 | 0x3000000;
  auVar22._0_8_ = (u32)*(u32 *)(iVar3 + 0x20) << 0x20 | 0x50000000;
  auVar22._8_8_ = extraout_v0_udw_01;
  auVar31 = _pcpyld(auVar29,auVar22);
  *DAT_007ce9f4 = (*(u32*)((u8*)&auVar31 + 0));
  puVar10[1] = auVar31._4_4_;
  puVar10[2] = auVar31._8_4_;
  puVar10[3] = auVar31._12_4_;
  DAT_007ce9f4 = DAT_007ce9f4 + 4;
  do {
    DI();
    SYNC(0x10);
  } while ((Status & 0x10000) != 0);
  *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 1;
  EI();
  *(int *)(iVar3 + 0x1c) = *(int *)(iVar3 + 0x1c) + 1;
  if (*(int *)(iVar3 + 0x1c) == 1) {
    ((code)FUN_004d51c0)();
  }
  return 1;
}

// FUN_00470200 NONMATCHING

u64 FUN_00470200(float *param_1,float *param_2)

{
  u8 bVar1;
  Vec128 auVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  u64 extraout_v0_udw;
  Vec128 auVar6;
  u64 in_a0_udw;
  Vec128 auVar7;
  Vec128 auVar8;
  Vec128 auVar9;
  u8 *pbVar10;
  u32 in_a1_udw;
  u32 uVar11;
  Vec128 auVar12;
  int iVar13;
  int iVar14;
  u32 in_t1_udw;
  u32 in_register_0000009c;
  int iVar15;
  int iVar16;
  float *pfVar17;
  u32 uVar18;
  int iVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  
  iVar3 = (int)(DAT_0095ef8c);
  iVar4 = ((code)FUN_004c2090)(*(u32 *)(DAT_0095ef8c + 0x134));
  bVar1 = (*(u32 *)(iVar3 + 0x10) & 2) == 0;
  if (bVar1) {
    iVar13 = 1;
    uVar11 = 0;
  }
  else {
    iVar13 = 2;
    uVar11 = 0xff;
  }
  bVar1 = !bVar1;
  fVar23 = 0.0;
  iVar15 = 0;
  iVar14 = DAT_0095efc4;
  if (0 < DAT_0095efc8) {
    do {
      iVar16 = 0;
      DAT_0095ef94 = DAT_0095ef94 + iVar13 * 0xc;
      pbVar10 = (u8 *)(DAT_0095ef94 - iVar13);
      do {
        uVar18 = (u32)*pbVar10 | (uVar11 & pbVar10[bVar1]) << 8;
        if (uVar18 < 0x80) {
          lVar5 = (long)*(short *)(iVar3 + uVar18 * 2 + 0x24);
        }
        else {
          iVar19 = uVar18 - *(int *)(iVar3 + 0x124);
          lVar5 = -1;
          if ((-1 < iVar19) && (iVar19 < *(int *)(iVar3 + 0x128))) {
            lVar5 = (long)*(short *)(*(int *)(iVar3 + 300) + iVar19 * 2);
          }
        }
        if (lVar5 < 0) {
          *param_1 = 0.0;
          param_1[1] = 0.0;
          param_1[2] = 0.0;
          *param_2 = 0.0;
          param_2[1] = 0.0;
          fVar20 = *(float *)(iVar3 + 0xc);
        }
        else {
          pfVar17 = (float *)(iVar4 + (int)lVar5 * 0x20);
          *param_1 = pfVar17[2];
          param_1[1] = pfVar17[3];
          param_1[2] = *pfVar17;
          *param_2 = pfVar17[4];
          param_2[1] = pfVar17[5];
          fVar20 = *pfVar17 + *(float *)(iVar3 + 0xc);
        }
        param_1 = param_1 + 3;
        param_2 = param_2 + 2;
        fVar23 = fVar23 + fVar20;
        iVar16 = iVar16 + 1;
        pbVar10 = pbVar10 + -iVar13;
      } while (iVar16 < 0xc);
      iVar15 = iVar15 + 1;
      iVar14 = iVar14 + -0xc;
    } while (iVar15 < DAT_0095efc8);
  }
  iVar15 = 0;
  DAT_0095ef94 = DAT_0095ef94 + iVar14 * iVar13;
  pbVar10 = (u8 *)(DAT_0095ef94 - iVar13);
  if (0 < iVar14) {
    do {
      uVar18 = (u32)*pbVar10 | (uVar11 & pbVar10[bVar1]) << 8;
      if (uVar18 < 0x80) {
        lVar5 = (long)*(short *)(iVar3 + uVar18 * 2 + 0x24);
      }
      else {
        iVar16 = uVar18 - *(int *)(iVar3 + 0x124);
        lVar5 = -1;
        if ((-1 < iVar16) && (iVar16 < *(int *)(iVar3 + 0x128))) {
          lVar5 = (long)*(short *)(*(int *)(iVar3 + 300) + iVar16 * 2);
        }
      }
      if (lVar5 < 0) {
        *param_1 = 0.0;
        param_1[1] = 0.0;
        param_1[2] = 0.0;
        *param_2 = 0.0;
        param_2[1] = 0.0;
        fVar20 = *(float *)(iVar3 + 0xc);
      }
      else {
        pfVar17 = (float *)(iVar4 + (int)lVar5 * 0x20);
        *param_1 = pfVar17[2];
        param_1[1] = pfVar17[3];
        param_1[2] = *pfVar17;
        *param_2 = pfVar17[4];
        param_2[1] = pfVar17[5];
        fVar20 = *pfVar17 + *(float *)(iVar3 + 0xc);
      }
      param_1 = param_1 + 3;
      param_2 = param_2 + 2;
      fVar23 = fVar23 + fVar20;
      iVar15 = iVar15 + 1;
      pbVar10 = pbVar10 + -iVar13;
    } while (iVar15 < iVar14);
  }
  lVar5 = ((code)FUN_004d59d0)(0,9);
  pfVar17 = (float *)DAT_007ce9f4;
  if (lVar5 == 0) {
    ((code)FUN_005225a8)(0x6b58a0,s_G3_2DFont_Node_c_006b58c0,0x14a);
  }
  else {
    auVar7._8_8_ = in_a0_udw;
    auVar7._0_8_ = 0x6c0703cf;
    auVar12._8_8_ = extraout_v0_udw;
    auVar12._0_8_ = 0x1000101;
    auVar12 = _ppacw(auVar7,auVar12);
    auVar8._8_8_ = in_a0_udw;
    auVar8._0_8_ = 0x10000007;
    auVar2._8_8_ = 0;
    auVar2._0_8_ = in_a1_udw;
    auVar9 = _ppacw(auVar2 << 0x40,auVar8);
    auVar9 = _ppacw(auVar12,auVar9);
    *DAT_007ce9f4 = (*(u32*)((u8*)&auVar9 + 0));
    pfVar17[1] = auVar9._4_4_;
    pfVar17[2] = auVar9._8_4_;
    pfVar17[3] = auVar9._12_4_;
    fVar22 = DAT_0095efa4;
    fVar21 = DAT_0095efa0;
    fVar20 = DAT_0095ef58;
    pfVar17 = (float *)DAT_007ce9f4;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    auVar6._8_8_ = extraout_v0_udw;
    auVar6._0_8_ = 0x302dc00000000000;
    auVar9._8_4_ = in_t1_udw;
    auVar9._0_8_ = 0x412;
    auVar9._12_4_ = in_register_0000009c;
    auVar9 = _pcpyld(auVar9,auVar6);
    *DAT_007ce9f4 = DAT_0095ef88[0x1c];
    pfVar17[5] = fVar21;
    pfVar17[6] = fVar20;
    pfVar17[7] = fVar22;
    pfVar17 = (float *)DAT_007ce9f4;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    fVar21 = DAT_0095ef88[1];
    fVar22 = DAT_0095ef88[2];
    fVar20 = DAT_0095ef88[3];
    *DAT_007ce9f4 = *DAT_0095ef88 * 0.50235295;
    pfVar17[5] = fVar21 * 0.50235295;
    pfVar17[6] = fVar22 * 0.50235295;
    pfVar17[7] = fVar20 * 0.50235295;
    pfVar17 = (float *)DAT_007ce9f4;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    fVar21 = DAT_0095ef88[7];
    fVar22 = DAT_0095ef88[8];
    fVar20 = DAT_0095ef88[9];
    *DAT_007ce9f4 = DAT_0095ef88[6] * 0.50235295;
    pfVar17[5] = fVar21 * 0.50235295;
    pfVar17[6] = fVar22 * 0.50235295;
    pfVar17[7] = fVar20 * 0.50235295;
    pfVar17 = (float *)DAT_007ce9f4;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    fVar21 = DAT_0095ef88[0xd];
    fVar22 = DAT_0095ef88[0xe];
    fVar20 = DAT_0095ef88[0xf];
    *DAT_007ce9f4 = DAT_0095ef88[0xc] * 0.50235295;
    pfVar17[5] = fVar21 * 0.50235295;
    pfVar17[6] = fVar22 * 0.50235295;
    pfVar17[7] = fVar20 * 0.50235295;
    pfVar17 = (float *)DAT_007ce9f4;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    fVar21 = DAT_0095ef88[0x13];
    fVar22 = DAT_0095ef88[0x14];
    fVar20 = DAT_0095ef88[0x15];
    *DAT_007ce9f4 = DAT_0095ef88[0x12] * 0.50235295;
    pfVar17[5] = fVar21 * 0.50235295;
    pfVar17[6] = fVar22 * 0.50235295;
    pfVar17[7] = fVar20 * 0.50235295;
    pfVar17 = (float *)DAT_007ce9f4;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    *DAT_007ce9f4 = *(float *)(DAT_0095ef8c + 0xc);
    pfVar17[5] = DAT_0095efa8;
    pfVar17[6] = 0.0;
    pfVar17[7] = 0.0;
    pfVar17[8] = auVar9._0_4_;
    pfVar17[9] = auVar9._4_4_;
    pfVar17[10] = auVar9._8_4_;
    pfVar17[0xb] = auVar9._12_4_;
    DAT_007ce9f4 = DAT_007ce9f4 + 8;
  }
  DAT_0095efa8 = fVar23;
  return 1;
}

// FUN_004709E0 NONMATCHING



u64 FUN_004709e0(int param_1)

{
  u8 bVar1;
  u32 uVar2;
  int iVar3;
  u8 bVar4;
  Vec128 auVar5;
  Vec128 auVar6;
  Vec128 auVar7;
  Vec128 auVar8;
  Vec128 auVar9;
  u32 uVar10;
  u32 uVar11;
  u32 *puVar12;
  Vec128 in_zero_qw;
  u32 uVar13;
  u32 uVar14;
  u64 extraout_v0_udw;
  Vec128 auVar15;
  Vec128 auVar16;
  Vec128 auVar17;
  Vec128 auVar18;
  u64 extraout_v0_udw_00;
  Vec128 auVar19;
  u64 extraout_v0_udw_01;
  Vec128 auVar20;
  Vec128 auVar21;
  Vec128 auVar22;
  u32 in_v1_udw;
  u64 uVar24;
  Vec128 auVar23;
  u32 uVar25;
  u32 in_a0_udw;
  Vec128 auVar26;
  Vec128 auVar27;
  u32 in_a1_udw;
  Vec128 auVar28;
  Vec128 auVar29;
  u32 in_a2_udw;
  Vec128 auVar30;
  Vec128 auVar31;
  
  ((code)FUN_004d59d0)(0,0xd);
  auVar31._8_8_ = 0;
  auVar31._0_8_ = in_v1_udw;
  auVar15._8_8_ = extraout_v0_udw;
  auVar15._0_8_ = 0x1000000a;
  auVar31 = _pcpyld(auVar31 << 0x40,auVar15);
  auVar5._8_8_ = 0;
  auVar5._0_8_ = in_a2_udw;
  auVar16._8_8_ = extraout_v0_udw;
  auVar16._0_8_ = 0x6c0103fa01000404;
  *puGpffffbd04 = auVar31._0_4_;
  puGpffffbd04[1] = auVar31._4_4_;
  puGpffffbd04[2] = auVar31._8_4_;
  puGpffffbd04[3] = auVar31._12_4_;
  *(u8 *)(param_1 + 0x47) = 0xfe;
  auVar31 = _pcpyld(auVar16,auVar5 << 0x40);
  puGpffffbd04[4] = auVar31._0_4_;
  puGpffffbd04[5] = auVar31._4_4_;
  puGpffffbd04[6] = auVar31._8_4_;
  puGpffffbd04[7] = auVar31._12_4_;
  bVar4 = *(char *)(param_1 + 0x47) != -1;
  uGpffffbdc4 = (u32)bVar4;
  if (bVar4 || iGpffffbdc8 != 0) {
    uGpffffb0d0 = uGpffffb0d0 | 0x40;
  }
  else {
    uGpffffb0d0 = uGpffffb0d0 & 0xffffffffffffffbf;
  }
  auVar30._8_8_ = in_a2_udw;
  auVar30._0_8_ = 0xfc007fffffffffff;
  auVar17._4_4_ = DAT_009658ac;
  auVar17._0_4_ = DAT_009658a8;
  auVar17._8_8_ = extraout_v0_udw;
  auVar31 = _pcpyld(in_zero_qw,auVar30);
  auVar26._0_8_ =
       CONCAT44((*(u32*)((u8*)&DAT_009658a0 + 4)),(u32)DAT_009658a0) & (*(u64*)((u8*)&auVar31 + 0)) |
       ((long)(int)((u32)uGpffffb0d0 | (u32)*(u8 *)(param_1 + 0x29)) & 0x7ffU) << 0x2f;
  auVar26._8_8_ = in_a0_udw;
  auVar31 = _pcpyld(auVar17,auVar26);
  (*(u32*)((u8*)&DAT_009658a0 + 0)) = (*(u32*)((u8*)&auVar31 + 0));
  (*(u32*)((u8*)&DAT_009658a0 + 4)) = (*(u32*)((u8*)&auVar31 + 4));
  DAT_009658a8 = auVar31._8_4_;
  DAT_009658ac = auVar31._12_4_;
  puGpffffbd04[8] = (u32)DAT_009658a0;
  puGpffffbd04[9] = auVar31._4_4_;
  puGpffffbd04[10] = auVar31._8_4_;
  puGpffffbd04[0xb] = auVar31._12_4_;
  auVar6._8_8_ = 0;
  auVar6._0_8_ = auVar31._8_8_;
  auVar18._8_8_ = extraout_v0_udw;
  auVar18._0_8_ = 0x6c0103fb01000404;
  auVar31 = _pcpyld(auVar18,auVar6 << 0x40);
  puGpffffbd04[0xc] = auVar31._0_4_;
  puGpffffbd04[0xd] = auVar31._4_4_;
  puGpffffbd04[0xe] = auVar31._8_4_;
  puGpffffbd04[0xf] = auVar31._12_4_;
  puGpffffbd04 = puGpffffbd04 + 0x10;
  if ((uGpffffb0d0 & 0x10) == 0) {
    uVar13 = 0x3b808081;
  }
  else {
    uVar13 = 0x3b011b50;
  }
  ((code)FUN_0049cab0)(uVar13,param_1 + 0x44);
  auVar7._8_8_ = 0;
  auVar7._0_8_ = in_a0_udw;
  auVar19._8_8_ = extraout_v0_udw_00;
  auVar19._0_8_ = 0x6c0103fc01000404;
  auVar31 = _pcpyld(auVar19,auVar7 << 0x40);
  *puGpffffbd04 = auVar31._0_4_;
  puGpffffbd04[1] = auVar31._4_4_;
  puGpffffbd04[2] = auVar31._8_4_;
  puGpffffbd04[3] = auVar31._12_4_;
  puGpffffbd04 = puGpffffbd04 + 4;
  uVar24 = auVar31._8_8_;
  ((code)FUN_0049cbd0)(*(u32 *)(param_1 + 0x1c),*(u32 *)(param_1 + 0x3c));
  bVar1 = *(u8 *)(param_1 + 0x28);
  auVar8._8_8_ = 0;
  auVar8._0_8_ = in_a1_udw;
  auVar23._8_8_ = uVar24;
  auVar23._0_8_ = 0x6c0303fd01000404;
  uVar14 = (u32)bVar1 & 7;
  auVar31 = _pcpyld(auVar23,auVar8 << 0x40);
  *puGpffffbd04 = auVar31._0_4_;
  puGpffffbd04[1] = auVar31._4_4_;
  puGpffffbd04[2] = auVar31._8_4_;
  puGpffffbd04[3] = auVar31._12_4_;
  auVar5 = _DAT_00965930;
  auVar31 = _DAT_00965910;
  if (((iGpffffbe14 == 0) || ((bVar1 & 4) != 0)) && ((iGpffffb0f8 == 0 || ((bVar1 & 4) == 0)))) {
    puGpffffbd04[4] = (u32)(DAT_00965910);
    puGpffffbd04[5] = auVar31._4_4_;
    puGpffffbd04[6] = auVar31._8_4_;
    puGpffffbd04[7] = auVar31._12_4_;
    uVar11 = DAT_0096592c;
    uVar10 = DAT_00965928;
    uVar13 = DAT_00965924;
    puGpffffbd04[8] = DAT_00965920;
    puGpffffbd04[9] = uVar13;
    puGpffffbd04[10] = uVar10;
    puGpffffbd04[0xb] = uVar11;
  }
  else {
    uVar14 = uVar14 | 8;
    puGpffffbd04[4] = (u32)(DAT_00965930);
    puGpffffbd04[5] = auVar5._4_4_;
    puGpffffbd04[6] = auVar5._8_4_;
    puGpffffbd04[7] = auVar5._12_4_;
    uVar11 = DAT_0096594c;
    uVar10 = DAT_00965948;
    uVar13 = DAT_00965944;
    puGpffffbd04[8] = DAT_00965940;
    puGpffffbd04[9] = uVar13;
    puGpffffbd04[10] = uVar10;
    puGpffffbd04[0xb] = uVar11;
    auVar31 = auVar5;
  }
  uGpffffbe0c = 0;
  auVar27._8_8_ = auVar31._8_8_;
  uVar25 = 0;
  if (iGpffffbdbc == 3) {
    uVar25 = 0x20;
    uGpffffbe0c = 0x20;
  }
  auVar20._8_8_ = extraout_v0_udw_01;
  auVar20._0_8_ = uVar14;
  (*(u64*)((u8*)&auVar28 + 4)) = in_a1_udw;
  auVar28._0_4_ = uGpffffbe10;
  auVar28._12_4_ = 0;
  auVar28._0_8_ = auVar28._0_8_ << 0x20;
  auVar27._0_8_ = (u32)uGpffffbe10 << 0x20 | uVar25;
  auVar31 = _pcpyld(auVar27,auVar20);
  puGpffffbd04[0xc] = auVar31._0_4_;
  puGpffffbd04[0xd] = auVar31._4_4_;
  puGpffffbd04[0xe] = auVar31._8_4_;
  puGpffffbd04[0xf] = auVar31._12_4_;
  *(u8 *)(param_1 + 0x2b) = *(int *)(DAT_0095ef84 + 0x14) != 1;
  uVar2 = *(u32 *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + (u32)*(u8 *)(param_1 + 0x2b) * 4);
  puVar12 = puGpffffbd04 + 0x10;
  if (uGpffffbe08 != uVar2) {
    auVar9._8_8_ = 0;
    auVar9._0_8_ = in_a1_udw;
    auVar28._0_8_ = auVar9._0_8_ << 0x40;
    auVar21._0_8_ = (u32)uVar2 << 0x20 | 0x50000000;
    auVar21._8_8_ = extraout_v0_udw_01;
    auVar31 = _pcpyld(auVar28,auVar21);
    puGpffffbd04[0x10] = auVar31._0_4_;
    puGpffffbd04[0x11] = auVar31._4_4_;
    puGpffffbd04[0x12] = auVar31._8_4_;
    puGpffffbd04[0x13] = auVar31._12_4_;
    puVar12 = puGpffffbd04 + 0x14;
    uGpffffbe08 = uVar2;
  }
  puGpffffbd04 = puVar12;
  auVar29._8_8_ = auVar28._8_8_;
  *(u32 *)(**(int **)(param_1 + 0x30) + 0x1c) = 1;
  iVar3 = **(int **)(param_1 + 0x30);
  auVar29._0_8_ = ((long)*(int *)(*(int *)(param_1 + 4) + 0x14) | 0x2000000U) << 0x20 | 0x3000000;
  auVar22._0_8_ = (u32)*(u32 *)(iVar3 + 0x20) << 0x20 | 0x50000000;
  auVar22._8_8_ = extraout_v0_udw_01;
  auVar31 = _pcpyld(auVar29,auVar22);
  *puGpffffbd04 = auVar31._0_4_;
  puGpffffbd04[1] = auVar31._4_4_;
  puGpffffbd04[2] = auVar31._8_4_;
  puGpffffbd04[3] = auVar31._12_4_;
  puGpffffbd04 = puGpffffbd04 + 4;
  do {
    DI();
    SYNC(0x10);
  } while ((Status & 0x10000) != 0);
  *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 1;
  EI();
  *(int *)(iVar3 + 0x1c) = *(int *)(iVar3 + 0x1c) + 1;
  if (*(int *)(iVar3 + 0x1c) == 1) {
    ((code)FUN_004d51c0)();
  }
  return 1;
}

// FUN_00470E10 NONMATCHING

u64 FUN_00470e10(u32 *param_1,u32 *param_2)

{
  Vec128 auVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  float fVar5;
  u32 in_v0_udw;
  u32 in_register_0000002c;
  u64 in_v1_udw;
  u64 in_a0_udw;
  Vec128 auVar6;
  Vec128 auVar7;
  u32 in_a1_udw;
  int iVar8;
  Vec128 auVar9;
  int iVar10;
  long lVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  
  lVar11 = 0;
  iVar10 = DAT_0095ef98;
  iVar8 = DAT_0095ef9c;
  if (0 < CONCAT44(DAT_0095efc4 >> 0x1f,DAT_0095efc4 >> 1)) {
    do {
      lVar11 = (long)((int)lVar11 + 1);
      *param_1 = *(u32 *)(iVar10 + 4);
      param_1[1] = *(u32 *)(iVar10 + 8);
      *param_2 = *(u32 *)(iVar10 + 0xc);
      param_2[1] = *(u32 *)(iVar10 + 0x10);
      param_1[2] = *(u32 *)(iVar8 + 4);
      param_1[3] = *(u32 *)(iVar8 + 8);
      param_1 = param_1 + 4;
      param_2[2] = *(u32 *)(iVar8 + 0xc);
      param_2[3] = *(u32 *)(iVar8 + 0x10);
      param_2 = param_2 + 4;
      iVar10 = iVar10 + 0x18;
      iVar8 = iVar8 + -0x18;
    } while (lVar11 < CONCAT44(DAT_0095efc4 >> 0x1f,DAT_0095efc4 >> 1));
  }
  lVar11 = ((code)FUN_004d59d0)(0,0xc);
  if (lVar11 == 0) {
    ((code)FUN_005225a8)(0x6b59f0,s_G3_2DFill_Node_c_006b5a10,0xf3);
  }
  else {
    auVar7._8_4_ = in_v0_udw;
    auVar7._0_8_ = 0x1000101;
    auVar7._12_4_ = in_register_0000002c;
    auVar9._8_8_ = in_v1_udw;
    auVar9._0_8_ = 0x6c0a03cf;
    auVar9 = _ppacw(auVar9,auVar7);
    auVar6._8_8_ = in_a0_udw;
    auVar6._0_8_ = 0x1000000a;
    auVar1._8_8_ = 0;
    auVar1._0_8_ = in_a1_udw;
    auVar7 = _ppacw(auVar1 << 0x40,auVar6);
    auVar7 = _ppacw(auVar9,auVar7);
    *puGpffffbd04 = auVar7._0_4_;
    puGpffffbd04[1] = auVar7._4_4_;
    puGpffffbd04[2] = auVar7._8_4_;
    puGpffffbd04[3] = auVar7._12_4_;
    uVar4 = DAT_0095efa4;
    uVar3 = DAT_0095efa0;
    uVar2 = DAT_0095ef58;
    puGpffffbd04[4] = DAT_0095ef88[0x1c];
    puGpffffbd04[5] = uVar3;
    puGpffffbd04[6] = uVar2;
    puGpffffbd04[7] = uVar4;
    if (DAT_0095ef88[0x1a] == 0.0) {
      fVar5 = 1.0;
      fVar15 = *DAT_0095ef88;
    }
    else {
      fVar5 = 0.50235295;
      fVar15 = *DAT_0095ef88;
    }
    fVar13 = DAT_0095ef88[1];
    fVar14 = DAT_0095ef88[2];
    fVar12 = DAT_0095ef88[3];
    puGpffffbd04[8] = fVar15 * fVar5;
    puGpffffbd04[9] = fVar13 * fVar5;
    puGpffffbd04[10] = fVar14 * fVar5;
    puGpffffbd04[0xb] = fVar12 * 0.50235295;
    fVar12 = DAT_0095ef88[7];
    fVar13 = DAT_0095ef88[8];
    fVar15 = DAT_0095ef88[9];
    puGpffffbd04[0xc] = DAT_0095ef88[6] * fVar5;
    puGpffffbd04[0xd] = fVar12 * fVar5;
    puGpffffbd04[0xe] = fVar13 * fVar5;
    puGpffffbd04[0xf] = fVar15 * 0.50235295;
    fVar12 = DAT_0095ef88[0xd];
    fVar13 = DAT_0095ef88[0xe];
    fVar15 = DAT_0095ef88[0xf];
    puGpffffbd04[0x10] = DAT_0095ef88[0xc] * fVar5;
    puGpffffbd04[0x11] = fVar12 * fVar5;
    puGpffffbd04[0x12] = fVar13 * fVar5;
    puGpffffbd04[0x13] = fVar15 * 0.50235295;
    fVar15 = DAT_0095ef88[0x15];
    fVar12 = DAT_0095ef88[0x13];
    fVar13 = DAT_0095ef88[0x14];
    puGpffffbd04[0x14] = DAT_0095ef88[0x12] * fVar5;
    puGpffffbd04[0x15] = fVar12 * fVar5;
    puGpffffbd04[0x16] = fVar13 * fVar5;
    puGpffffbd04[0x17] = fVar15 * 0.50235295;
    fVar5 = DAT_0095ef88[5];
    puGpffffbd04[0x18] = DAT_0095ef88[4];
    puGpffffbd04[0x19] = fVar5;
    puGpffffbd04[0x1a] = 0;
    puGpffffbd04[0x1b] = 0;
    fVar5 = DAT_0095ef88[0xb];
    puGpffffbd04[0x1c] = DAT_0095ef88[10];
    puGpffffbd04[0x1d] = fVar5;
    puGpffffbd04[0x1e] = 0;
    puGpffffbd04[0x1f] = 0;
    fVar5 = DAT_0095ef88[0x11];
    puGpffffbd04[0x20] = DAT_0095ef88[0x10];
    puGpffffbd04[0x21] = fVar5;
    puGpffffbd04[0x22] = 0;
    puGpffffbd04[0x23] = 0;
    fVar5 = DAT_0095ef88[0x17];
    puGpffffbd04[0x24] = DAT_0095ef88[0x16];
    puGpffffbd04[0x25] = fVar5;
    puGpffffbd04[0x26] = 0;
    puGpffffbd04[0x27] = 0;
    uVar4 = DAT_0095efc0;
    uVar3 = DAT_0095efbc;
    uVar2 = DAT_0095efb0;
    puGpffffbd04[0x28] = DAT_0095efac;
    puGpffffbd04[0x29] = uVar2;
    puGpffffbd04[0x2a] = uVar3;
    puGpffffbd04[0x2b] = uVar4;
    puGpffffbd04 = puGpffffbd04 + 0x2c;
  }
  return 1;
}

// FUN_00471470 NONMATCHING



u64 FUN_00471470(int param_1)

{
  u8 bVar1;
  u32 uVar2;
  int iVar3;
  u8 bVar4;
  Vec128 auVar5;
  Vec128 auVar6;
  Vec128 auVar7;
  Vec128 auVar8;
  Vec128 auVar9;
  u32 uVar10;
  u32 uVar11;
  u32 *puVar12;
  Vec128 in_zero_qw;
  u32 uVar13;
  u32 uVar14;
  u64 extraout_v0_udw;
  Vec128 auVar15;
  Vec128 auVar16;
  Vec128 auVar17;
  Vec128 auVar18;
  u64 extraout_v0_udw_00;
  Vec128 auVar19;
  u64 extraout_v0_udw_01;
  Vec128 auVar20;
  Vec128 auVar21;
  Vec128 auVar22;
  u32 in_v1_udw;
  u64 uVar24;
  Vec128 auVar23;
  u32 uVar25;
  u32 in_a0_udw;
  Vec128 auVar26;
  Vec128 auVar27;
  u32 in_a1_udw;
  Vec128 auVar28;
  Vec128 auVar29;
  u32 in_a2_udw;
  Vec128 auVar30;
  Vec128 auVar31;
  
  ((code)FUN_004d59d0)(0,0xd);
  auVar31._8_8_ = 0;
  auVar31._0_8_ = in_v1_udw;
  auVar15._8_8_ = extraout_v0_udw;
  auVar15._0_8_ = 0x1000000a;
  auVar31 = _pcpyld(auVar31 << 0x40,auVar15);
  auVar5._8_8_ = 0;
  auVar5._0_8_ = in_a2_udw;
  auVar16._8_8_ = extraout_v0_udw;
  auVar16._0_8_ = 0x6c0103fa01000404;
  *puGpffffbd04 = auVar31._0_4_;
  puGpffffbd04[1] = auVar31._4_4_;
  puGpffffbd04[2] = auVar31._8_4_;
  puGpffffbd04[3] = auVar31._12_4_;
  *(u8 *)(param_1 + 0x47) = 0xfe;
  auVar31 = _pcpyld(auVar16,auVar5 << 0x40);
  puGpffffbd04[4] = auVar31._0_4_;
  puGpffffbd04[5] = auVar31._4_4_;
  puGpffffbd04[6] = auVar31._8_4_;
  puGpffffbd04[7] = auVar31._12_4_;
  bVar4 = *(char *)(param_1 + 0x47) != -1;
  uGpffffbdc4 = (u32)bVar4;
  if (bVar4 || iGpffffbdc8 != 0) {
    uGpffffb0d0 = uGpffffb0d0 | 0x40;
  }
  else {
    uGpffffb0d0 = uGpffffb0d0 & 0xffffffffffffffbf;
  }
  auVar30._8_8_ = in_a2_udw;
  auVar30._0_8_ = 0xfc007fffffffffff;
  auVar17._4_4_ = DAT_009658ac;
  auVar17._0_4_ = DAT_009658a8;
  auVar17._8_8_ = extraout_v0_udw;
  auVar31 = _pcpyld(in_zero_qw,auVar30);
  auVar26._0_8_ =
       CONCAT44((*(u32*)((u8*)&DAT_009658a0 + 4)),(u32)DAT_009658a0) & (*(u64*)((u8*)&auVar31 + 0)) |
       ((long)(int)((u32)uGpffffb0d0 | (u32)*(u8 *)(param_1 + 0x29)) & 0x7ffU) << 0x2f;
  auVar26._8_8_ = in_a0_udw;
  auVar31 = _pcpyld(auVar17,auVar26);
  (*(u32*)((u8*)&DAT_009658a0 + 0)) = (*(u32*)((u8*)&auVar31 + 0));
  (*(u32*)((u8*)&DAT_009658a0 + 4)) = (*(u32*)((u8*)&auVar31 + 4));
  DAT_009658a8 = auVar31._8_4_;
  DAT_009658ac = auVar31._12_4_;
  puGpffffbd04[8] = (u32)DAT_009658a0;
  puGpffffbd04[9] = auVar31._4_4_;
  puGpffffbd04[10] = auVar31._8_4_;
  puGpffffbd04[0xb] = auVar31._12_4_;
  auVar6._8_8_ = 0;
  auVar6._0_8_ = auVar31._8_8_;
  auVar18._8_8_ = extraout_v0_udw;
  auVar18._0_8_ = 0x6c0103fb01000404;
  auVar31 = _pcpyld(auVar18,auVar6 << 0x40);
  puGpffffbd04[0xc] = auVar31._0_4_;
  puGpffffbd04[0xd] = auVar31._4_4_;
  puGpffffbd04[0xe] = auVar31._8_4_;
  puGpffffbd04[0xf] = auVar31._12_4_;
  puGpffffbd04 = puGpffffbd04 + 0x10;
  if ((uGpffffb0d0 & 0x10) == 0) {
    uVar13 = 0x3b808081;
  }
  else {
    uVar13 = 0x3b011b50;
  }
  ((code)FUN_0049cab0)(uVar13,param_1 + 0x44);
  auVar7._8_8_ = 0;
  auVar7._0_8_ = in_a0_udw;
  auVar19._8_8_ = extraout_v0_udw_00;
  auVar19._0_8_ = 0x6c0103fc01000404;
  auVar31 = _pcpyld(auVar19,auVar7 << 0x40);
  *puGpffffbd04 = auVar31._0_4_;
  puGpffffbd04[1] = auVar31._4_4_;
  puGpffffbd04[2] = auVar31._8_4_;
  puGpffffbd04[3] = auVar31._12_4_;
  puGpffffbd04 = puGpffffbd04 + 4;
  uVar24 = auVar31._8_8_;
  ((code)FUN_0049cbd0)(*(u32 *)(param_1 + 0x1c),*(u32 *)(param_1 + 0x3c));
  bVar1 = *(u8 *)(param_1 + 0x28);
  auVar8._8_8_ = 0;
  auVar8._0_8_ = in_a1_udw;
  auVar23._8_8_ = uVar24;
  auVar23._0_8_ = 0x6c0303fd01000404;
  uVar14 = (u32)bVar1 & 7;
  auVar31 = _pcpyld(auVar23,auVar8 << 0x40);
  *puGpffffbd04 = auVar31._0_4_;
  puGpffffbd04[1] = auVar31._4_4_;
  puGpffffbd04[2] = auVar31._8_4_;
  puGpffffbd04[3] = auVar31._12_4_;
  auVar5 = _DAT_00965930;
  auVar31 = _DAT_00965910;
  if (((iGpffffbe14 == 0) || ((bVar1 & 4) != 0)) && ((iGpffffb0f8 == 0 || ((bVar1 & 4) == 0)))) {
    puGpffffbd04[4] = (u32)(DAT_00965910);
    puGpffffbd04[5] = auVar31._4_4_;
    puGpffffbd04[6] = auVar31._8_4_;
    puGpffffbd04[7] = auVar31._12_4_;
    uVar11 = DAT_0096592c;
    uVar10 = DAT_00965928;
    uVar13 = DAT_00965924;
    puGpffffbd04[8] = DAT_00965920;
    puGpffffbd04[9] = uVar13;
    puGpffffbd04[10] = uVar10;
    puGpffffbd04[0xb] = uVar11;
  }
  else {
    uVar14 = uVar14 | 8;
    puGpffffbd04[4] = (u32)(DAT_00965930);
    puGpffffbd04[5] = auVar5._4_4_;
    puGpffffbd04[6] = auVar5._8_4_;
    puGpffffbd04[7] = auVar5._12_4_;
    uVar11 = DAT_0096594c;
    uVar10 = DAT_00965948;
    uVar13 = DAT_00965944;
    puGpffffbd04[8] = DAT_00965940;
    puGpffffbd04[9] = uVar13;
    puGpffffbd04[10] = uVar10;
    puGpffffbd04[0xb] = uVar11;
    auVar31 = auVar5;
  }
  uGpffffbe0c = 0;
  auVar27._8_8_ = auVar31._8_8_;
  uVar25 = 0;
  if (iGpffffbdbc == 3) {
    uVar25 = 0x20;
    uGpffffbe0c = 0x20;
  }
  auVar20._8_8_ = extraout_v0_udw_01;
  auVar20._0_8_ = uVar14;
  (*(u64*)((u8*)&auVar28 + 4)) = in_a1_udw;
  auVar28._0_4_ = uGpffffbe10;
  auVar28._12_4_ = 0;
  auVar28._0_8_ = auVar28._0_8_ << 0x20;
  auVar27._0_8_ = (u32)uGpffffbe10 << 0x20 | uVar25;
  auVar31 = _pcpyld(auVar27,auVar20);
  puGpffffbd04[0xc] = auVar31._0_4_;
  puGpffffbd04[0xd] = auVar31._4_4_;
  puGpffffbd04[0xe] = auVar31._8_4_;
  puGpffffbd04[0xf] = auVar31._12_4_;
  *(u8 *)(param_1 + 0x2b) = *(int *)(DAT_0095ef84 + 0x14) != 1;
  uVar2 = *(u32 *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + (u32)*(u8 *)(param_1 + 0x2b) * 4);
  puVar12 = puGpffffbd04 + 0x10;
  if (uGpffffbe08 != uVar2) {
    auVar9._8_8_ = 0;
    auVar9._0_8_ = in_a1_udw;
    auVar28._0_8_ = auVar9._0_8_ << 0x40;
    auVar21._0_8_ = (u32)uVar2 << 0x20 | 0x50000000;
    auVar21._8_8_ = extraout_v0_udw_01;
    auVar31 = _pcpyld(auVar28,auVar21);
    puGpffffbd04[0x10] = auVar31._0_4_;
    puGpffffbd04[0x11] = auVar31._4_4_;
    puGpffffbd04[0x12] = auVar31._8_4_;
    puGpffffbd04[0x13] = auVar31._12_4_;
    puVar12 = puGpffffbd04 + 0x14;
    uGpffffbe08 = uVar2;
  }
  puGpffffbd04 = puVar12;
  auVar29._8_8_ = auVar28._8_8_;
  *(u32 *)(**(int **)(param_1 + 0x30) + 0x1c) = 1;
  iVar3 = **(int **)(param_1 + 0x30);
  auVar29._0_8_ = ((long)*(int *)(*(int *)(param_1 + 4) + 0x14) | 0x2000000U) << 0x20 | 0x3000000;
  auVar22._0_8_ = (u32)*(u32 *)(iVar3 + 0x20) << 0x20 | 0x50000000;
  auVar22._8_8_ = extraout_v0_udw_01;
  auVar31 = _pcpyld(auVar29,auVar22);
  *puGpffffbd04 = auVar31._0_4_;
  puGpffffbd04[1] = auVar31._4_4_;
  puGpffffbd04[2] = auVar31._8_4_;
  puGpffffbd04[3] = auVar31._12_4_;
  puGpffffbd04 = puGpffffbd04 + 4;
  do {
    DI();
    SYNC(0x10);
  } while ((Status & 0x10000) != 0);
  *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + 1;
  EI();
  *(int *)(iVar3 + 0x1c) = *(int *)(iVar3 + 0x1c) + 1;
  if (*(int *)(iVar3 + 0x1c) == 1) {
    ((code)FUN_004d51c0)();
  }
  return 1;
}

// FUN_004718A0 NONMATCHING

u64 FUN_004718a0(int param_1,u32 *param_2)

{
  u8 bVar1;
  int iVar2;
  u32 *puVar3;
  u32 uVar4;
  u32 uVar5;
  u32 *puVar6;
  u32 *puVar7;
  u64 uVar8;
  Vec128 auVar9;
  u32 uVar10;
  u32 uVar11;
  u32 uVar12;
  int *piVar13;
  u32 uVar14;
  float *pfVar15;
  u64 *puVar16;
  int iVar17;
  float *pfVar18;
  u64 uVar19;
  u64 extraout_v0_udw;
  Vec128 auVar20;
  Vec128 auVar21;
  u64 in_a0_udw;
  u32 in_a1_udw;
  u32 in_register_0000005c;
  u32 uVar22;
  u32 uVar23;
  Vec128 auVar24;
  u32 uVar25;
  u32 uVar26;
  u32 uVar27;
  u32 uVar28;
  u32 uVar29;
  u32 uVar30;
  int iVar31;
  u32 uVar32;
  int iVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  int aiStack_70 [12];
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_20;
  float fStack_1c;
  
  iVar2 = *(int *)(param_1 + 8);
  iVar33 = *(int *)(iVar2 + 0x18);
  puVar3 = *(u32 **)(iVar33 + DAT_0095de18);
  uVar4 = *puVar3;
  *(u32 *)(param_1 + 0xc) = *(u32 *)(iVar33 + 0x54);
  if (*(int *)(iVar33 + 0x18) == 1) {
    piVar13 = (int *)(iVar33 + iGpffffbba0);
    bVar1 = 0;
    if (((u32 *)*piVar13 != (u32 *)0x0) &&
       ((u32)*(u16 *)(*(int *)(iVar33 + 0x54) + 4) == *(u32 *)*piVar13)) {
      bVar1 = 1;
    }
    if (bVar1) {
      iVar33 = *piVar13;
    }
    else {
      piVar13 = (int *)((code)FUN_0049e5a0)((short)piVar13,*(u16 *)(*(int *)(iVar33 + 0x54) + 4));
      iVar33 = *piVar13;
    }
    *(int *)(param_1 + 0x10) = iVar33;
  }
  else {
    piVar13 = (int *)(iVar2 + iGpffffbb9c);
    bVar1 = 0;
    if (((u32 *)*piVar13 != (u32 *)0x0) &&
       ((u32)*(u16 *)(*(int *)(iVar33 + 0x54) + 4) == *(u32 *)*piVar13)) {
      bVar1 = 1;
    }
    if (bVar1) {
      iVar33 = *piVar13;
    }
    else {
      piVar13 = (int *)((code)FUN_0049e5a0)((short)piVar13,*(u16 *)(*(int *)(iVar33 + 0x54) + 4));
      iVar33 = *piVar13;
    }
    *(int *)(param_1 + 0x10) = iVar33;
  }
  if (*(short *)(*(int *)(param_1 + 0xc) + 4) == 0) {
    uVar19 = 0;
  }
  else {
    *(u32 *)(param_1 + 0x20) = *(u32 *)(*(int *)(iVar2 + 0x18) + 0x18);
    if (1 < *(int *)(param_1 + 0x20)) {
      *(float *)(param_1 + 0x1c) = *(float *)(iVar2 + 0x58) * *(float *)(iVar2 + 0x5c);
    }
    iVar33 = *(int *)(iVar2 + 0x18);
    if ((*(u32 *)(iVar33 + 8) & 0x1000000) == 0) {
      *(u32 *)(param_1 + 0x18) =
           CONCAT22((u16)(((u32)*(u8 *)(iVar33 + 0x18) << 0x18) >> 0x10) |
                    (u16)*(u32 *)(iVar33 + 8) & 0x9f,
                    *(u16 *)(*(int *)(param_1 + 0xc) + 6));
      *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) & 0xfffffffe;
      iVar31 = *(int *)(*(int *)(param_1 + 0x10) + 4);
      if (iVar31 != 0) {
        uVar32 = *(u32 *)(iVar31 + 0x28);
        uVar5 = *(u32 *)(param_1 + 0x18);
        if (uVar5 != uVar32) {
          if (((uVar5 >> 0x10 & 0xff) == (uVar32 >> 0x10 & 0xff)) &&
             (uVar5 >> 0x18 == uVar32 >> 0x18)) {
            *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 4;
          }
          else {
            *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 8;
          }
        }
        if (*(u16 *)(iVar33 + 0xc) != 0) {
          if ((*(u16 *)(iVar33 + 0xc) & 1) == 0) {
            *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 2;
            *(u32 *)(param_1 + 0x14) =
                 *(u32 *)(param_1 + 0x14) | (u32)*(u16 *)(iVar33 + 0xc) << 3;
          }
          else {
            *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 8;
          }
        }
        if (((*(u32 *)(iVar2 + 0x4c) & 1) != 0) &&
           (((long)*(int *)(iVar31 + 0x40) != (long)*(short *)(iVar2 + 0x52) ||
            ((long)*(int *)(iVar31 + 0x3c) != (long)*(short *)(iVar2 + 0x50))))) {
          *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 4;
        }
      }
    }
    *(u16 *)(*(int *)(iVar2 + 0x18) + 0xc) = 0;
    *(u32 *)(iVar2 + 0x4c) = *(u32 *)(iVar2 + 0x4c) & 0xfffffffe;
    iVar33 = DAT_00960070 + 0x20;
    uVar14 = ((code)FUN_004cb2f0)((short)*(u32 *)(iVar2 + 4));
    ((code)FUN_004c2f30)((short)*param_2,uVar14,iVar33);
    iVar31 = 2;
    pfVar15 = (float *)((code)FUN_004912b0)((short)iVar2);
    iVar33 = 5;
    pfVar18 = (float *)(DAT_00960070 + iGpffffbdb4 + 0x60);
    do {
      if (-pfVar15[3] <
          (pfVar15[2] * pfVar18[2] + *pfVar15 * *pfVar18 + pfVar15[1] * pfVar18[1]) - pfVar18[3]) {
        iVar31 = 1;
        break;
      }
      pfVar18 = pfVar18 + 5;
      bVar1 = iVar33 != 0;
      iVar33 = iVar33 + -1;
    } while (bVar1);
    uVar32 = **(u32 **)(param_1 + 0xc);
    if ((uVar32 & 1) == 1) {
      *(u8 *)(param_1 + 0x29) = 4;
      *(u8 *)(param_1 + 0x28) = bGpffffbe04;
    }
    else if (((uVar32 & 0xff) == 0) || ((uVar32 & 2) == 2)) {
      *(u8 *)(param_1 + 0x29) = 3;
      *(u8 *)(param_1 + 0x28) = bGpffffbe04 | 4;
    }
    else if ((uVar32 & 0x10) == 0x10) {
      *(u8 *)(param_1 + 0x29) = 4;
      *(u8 *)(param_1 + 0x28) = bGpffffbe04;
    }
    else if ((uVar32 & 8) == 8) {
      *(u8 *)(param_1 + 0x29) = 2;
      *(u8 *)(param_1 + 0x28) = bGpffffbe04 | 0x10;
    }
    else {
      *(u8 *)(param_1 + 0x29) = 1;
      *(u8 *)(param_1 + 0x28) = bGpffffbe04 | 0x14;
    }
    if (iVar31 != 2) {
      *(u8 *)(param_1 + 0x28) = *(u8 *)(param_1 + 0x28) | 2;
    }
    *(u8 *)(param_1 + 0x2a) = (*(u32 *)(*(int *)(iVar2 + 0x18) + 8) & 0x40) != 0;
    if (DAT_0095de34 == (code)0) {
      iVar33 = *(int *)(param_1 + 8);
      iVar31 = *(int *)(iVar33 + 0x18);
      if ((*(u32 *)(iVar31 + 8) & 0x20) != 0) {
        DAT_0096007a = DAT_0096007a + 1;
        iVar17 = ((code)FUN_004cb2f0)((short)*(u32 *)(iVar33 + 4));
        ((code)FUN_004c32a0)((short)&stack0x00000000 + -0x60,iVar17);
        if ((*(u32 *)(iVar17 + 0xc) & 3) == 3) {
          fStack_20 = 1.0;
          fStack_1c = 1.0;
        }
        else {
          fStack_20 = SQRT(fStack_38 * fStack_38 + fStack_40 * fStack_40 + fStack_3c * fStack_3c);
          fStack_1c = fStack_20;
          if (0.0 < fStack_20) {
            fStack_1c = 1.0 / fStack_20;
          }
        }
        iVar31 = *(int *)(iVar31 + 0x54);
        aiStack_70[0] = *(int *)(*(int *)(iVar31 + 0xc) + iVar31 + 0x18) + 0xc;
        ((code)FUN_00499c20)(0x430,aiStack_70);
        for (puVar6 = *(u32 **)(iVar33 + 100); puVar6 != (u32 *)(iVar33 + 100);
            puVar6 = (u32 *)*puVar6) {
          iVar31 = puVar6[2];
          for (puVar7 = *(u32 **)(iVar31 + 0x40); puVar7 != (u32 *)(iVar31 + 0x40);
              puVar7 = (u32 *)*puVar7) {
            iVar17 = puVar7[2];
            if (((iVar17 != 0) && (*(short *)(iVar17 + 0x3c) != DAT_0096007a)) &&
               ((*(u8 *)(iVar17 + 2) & 1) != 0)) {
              *(short *)(iVar17 + 0x3c) = DAT_0096007a;
              iVar17 = ((code)FUN_004cb2f0)((short)*(u32 *)(puVar7[2] + 4));
              pfVar18 = (float *)((code)FUN_004912b0)((short)iVar33);
              fVar36 = pfVar18[1] - *(float *)(iVar17 + 0x34);
              fVar37 = *pfVar18 - *(float *)(iVar17 + 0x30);
              fVar34 = pfVar18[2] - *(float *)(iVar17 + 0x38);
              fVar35 = pfVar18[3] + *(float *)(puVar7[2] + 0x14);
              if (fVar34 * fVar34 + fVar37 * fVar37 + fVar36 * fVar36 < fVar35 * fVar35) {
                ((code)FUN_004a0430)((short)puVar7[2],aiStack_70);
              }
            }
          }
        }
      }
    }
    else {
      (*DAT_0095de34)(1,*(u32 *)(param_1 + 8));
    }
    puVar16 = (u64 *)((code)FUN_0046b510)((short)iVar2,puVar3);
    if (puVar3[0xc] == 0) {
      uVar32 = uVar4 * 4;
      ((code)FUN_004d59d0)(0,uVar32 + 2);
      auVar24._8_8_ = extraout_v0_udw;
      auVar24._0_8_ = 0x1000101;
      (*(u16*)((u8*)&auVar21 + 2)) = (u16)uVar32 & 0xff | 0x6c00;
      (*(u16*)((u8*)&auVar21 + 0)) = 700;
      auVar21._4_4_ = 0;
      auVar21._8_8_ = in_a0_udw;
      auVar24 = _ppacw(auVar21,auVar24);
      auVar20._0_8_ = (u32)uVar32 | 0x10000000;
      auVar20._8_8_ = extraout_v0_udw;
      auVar9._4_4_ = in_register_0000005c;
      auVar9._0_4_ = in_a1_udw;
      auVar9._8_8_ = 0;
      auVar21 = _ppacw(auVar9 << 0x40,auVar20);
      auVar21 = _ppacw(auVar24,auVar21);
      puVar6 = puGpffffbd04 + 4;
      uVar32 = 0;
      *puGpffffbd04 = auVar21._0_4_;
      puGpffffbd04[1] = auVar21._4_4_;
      puGpffffbd04[2] = auVar21._8_4_;
      puGpffffbd04[3] = auVar21._12_4_;
      if (uVar4 != 0) {
        if (8 < uVar4) {
          do {
            uVar27 = *(u32 *)(puVar16 + 2);
            uVar28 = *(u32 *)((int)puVar16 + 0x14);
            uVar29 = *(u32 *)(puVar16 + 3);
            uVar30 = *(u32 *)((int)puVar16 + 0x1c);
            uVar32 = uVar32 + 8;
            uVar19 = puVar16[4];
            uVar25 = *(u32 *)(puVar16 + 5);
            uVar26 = *(u32 *)((int)puVar16 + 0x2c);
            uVar14 = *(u32 *)(puVar16 + 6);
            uVar10 = *(u32 *)((int)puVar16 + 0x34);
            uVar11 = *(u32 *)(puVar16 + 7);
            uVar12 = *(u32 *)((int)puVar16 + 0x3c);
            uVar8 = *puVar16;
            uVar22 = *(u32 *)(puVar16 + 1);
            uVar23 = *(u32 *)((int)puVar16 + 0xc);
            *puVar6 = (int)uVar8;
            puVar6[1] = (int)((u32)uVar8 >> 0x20);
            puVar6[2] = uVar22;
            puVar6[3] = uVar23;
            puVar6[4] = uVar27;
            puVar6[5] = uVar28;
            puVar6[6] = uVar29;
            puVar6[7] = uVar30;
            puVar6[8] = (int)uVar19;
            puVar6[9] = (int)((u32)uVar19 >> 0x20);
            puVar6[10] = uVar25;
            puVar6[0xb] = uVar26;
            puVar6[0xc] = uVar14;
            puVar6[0xd] = uVar10;
            puVar6[0xe] = uVar11;
            puVar6[0xf] = uVar12;
            uVar27 = *(u32 *)(puVar16 + 10);
            uVar28 = *(u32 *)((int)puVar16 + 0x54);
            uVar29 = *(u32 *)(puVar16 + 0xb);
            uVar30 = *(u32 *)((int)puVar16 + 0x5c);
            uVar19 = puVar16[0xc];
            uVar25 = *(u32 *)(puVar16 + 0xd);
            uVar26 = *(u32 *)((int)puVar16 + 0x6c);
            uVar14 = *(u32 *)(puVar16 + 0xe);
            uVar10 = *(u32 *)((int)puVar16 + 0x74);
            uVar11 = *(u32 *)(puVar16 + 0xf);
            uVar12 = *(u32 *)((int)puVar16 + 0x7c);
            uVar8 = puVar16[8];
            uVar22 = *(u32 *)(puVar16 + 9);
            uVar23 = *(u32 *)((int)puVar16 + 0x4c);
            puVar6[0x10] = (int)uVar8;
            puVar6[0x11] = (int)((u32)uVar8 >> 0x20);
            puVar6[0x12] = uVar22;
            puVar6[0x13] = uVar23;
            puVar6[0x14] = uVar27;
            puVar6[0x15] = uVar28;
            puVar6[0x16] = uVar29;
            puVar6[0x17] = uVar30;
            puVar6[0x18] = (int)uVar19;
            puVar6[0x19] = (int)((u32)uVar19 >> 0x20);
            puVar6[0x1a] = uVar25;
            puVar6[0x1b] = uVar26;
            puVar6[0x1c] = uVar14;
            puVar6[0x1d] = uVar10;
            puVar6[0x1e] = uVar11;
            puVar6[0x1f] = uVar12;
            uVar27 = *(u32 *)(puVar16 + 0x12);
            uVar28 = *(u32 *)((int)puVar16 + 0x94);
            uVar29 = *(u32 *)(puVar16 + 0x13);
            uVar30 = *(u32 *)((int)puVar16 + 0x9c);
            uVar19 = puVar16[0x14];
            uVar25 = *(u32 *)(puVar16 + 0x15);
            uVar26 = *(u32 *)((int)puVar16 + 0xac);
            uVar14 = *(u32 *)(puVar16 + 0x16);
            uVar10 = *(u32 *)((int)puVar16 + 0xb4);
            uVar11 = *(u32 *)(puVar16 + 0x17);
            uVar12 = *(u32 *)((int)puVar16 + 0xbc);
            uVar8 = puVar16[0x10];
            uVar22 = *(u32 *)(puVar16 + 0x11);
            uVar23 = *(u32 *)((int)puVar16 + 0x8c);
            puVar6[0x20] = (int)uVar8;
            puVar6[0x21] = (int)((u32)uVar8 >> 0x20);
            puVar6[0x22] = uVar22;
            puVar6[0x23] = uVar23;
            puVar6[0x24] = uVar27;
            puVar6[0x25] = uVar28;
            puVar6[0x26] = uVar29;
            puVar6[0x27] = uVar30;
            puVar6[0x28] = (int)uVar19;
            puVar6[0x29] = (int)((u32)uVar19 >> 0x20);
            puVar6[0x2a] = uVar25;
            puVar6[0x2b] = uVar26;
            puVar6[0x2c] = uVar14;
            puVar6[0x2d] = uVar10;
            puVar6[0x2e] = uVar11;
            puVar6[0x2f] = uVar12;
            uVar27 = *(u32 *)(puVar16 + 0x1a);
            uVar28 = *(u32 *)((int)puVar16 + 0xd4);
            uVar29 = *(u32 *)(puVar16 + 0x1b);
            uVar30 = *(u32 *)((int)puVar16 + 0xdc);
            uVar19 = puVar16[0x1c];
            uVar25 = *(u32 *)(puVar16 + 0x1d);
            uVar26 = *(u32 *)((int)puVar16 + 0xec);
            uVar14 = *(u32 *)(puVar16 + 0x1e);
            uVar10 = *(u32 *)((int)puVar16 + 0xf4);
            uVar11 = *(u32 *)(puVar16 + 0x1f);
            uVar12 = *(u32 *)((int)puVar16 + 0xfc);
            uVar8 = puVar16[0x18];
            uVar22 = *(u32 *)(puVar16 + 0x19);
            uVar23 = *(u32 *)((int)puVar16 + 0xcc);
            puVar6[0x30] = (int)uVar8;
            puVar6[0x31] = (int)((u32)uVar8 >> 0x20);
            puVar6[0x32] = uVar22;
            puVar6[0x33] = uVar23;
            puVar6[0x34] = uVar27;
            puVar6[0x35] = uVar28;
            puVar6[0x36] = uVar29;
            puVar6[0x37] = uVar30;
            puVar6[0x38] = (int)uVar19;
            puVar6[0x39] = (int)((u32)uVar19 >> 0x20);
            puVar6[0x3a] = uVar25;
            puVar6[0x3b] = uVar26;
            puVar6[0x3c] = uVar14;
            puVar6[0x3d] = uVar10;
            puVar6[0x3e] = uVar11;
            puVar6[0x3f] = uVar12;
            uVar27 = *(u32 *)(puVar16 + 0x22);
            uVar28 = *(u32 *)((int)puVar16 + 0x114);
            uVar29 = *(u32 *)(puVar16 + 0x23);
            uVar30 = *(u32 *)((int)puVar16 + 0x11c);
            uVar19 = puVar16[0x24];
            uVar25 = *(u32 *)(puVar16 + 0x25);
            uVar26 = *(u32 *)((int)puVar16 + 300);
            uVar14 = *(u32 *)(puVar16 + 0x26);
            uVar10 = *(u32 *)((int)puVar16 + 0x134);
            uVar11 = *(u32 *)(puVar16 + 0x27);
            uVar12 = *(u32 *)((int)puVar16 + 0x13c);
            uVar8 = puVar16[0x20];
            uVar22 = *(u32 *)(puVar16 + 0x21);
            uVar23 = *(u32 *)((int)puVar16 + 0x10c);
            puVar6[0x40] = (int)uVar8;
            puVar6[0x41] = (int)((u32)uVar8 >> 0x20);
            puVar6[0x42] = uVar22;
            puVar6[0x43] = uVar23;
            puVar6[0x44] = uVar27;
            puVar6[0x45] = uVar28;
            puVar6[0x46] = uVar29;
            puVar6[0x47] = uVar30;
            puVar6[0x48] = (int)uVar19;
            puVar6[0x49] = (int)((u32)uVar19 >> 0x20);
            puVar6[0x4a] = uVar25;
            puVar6[0x4b] = uVar26;
            puVar6[0x4c] = uVar14;
            puVar6[0x4d] = uVar10;
            puVar6[0x4e] = uVar11;
            puVar6[0x4f] = uVar12;
            uVar27 = *(u32 *)(puVar16 + 0x2a);
            uVar28 = *(u32 *)((int)puVar16 + 0x154);
            uVar29 = *(u32 *)(puVar16 + 0x2b);
            uVar30 = *(u32 *)((int)puVar16 + 0x15c);
            uVar19 = puVar16[0x2c];
            uVar25 = *(u32 *)(puVar16 + 0x2d);
            uVar26 = *(u32 *)((int)puVar16 + 0x16c);
            uVar14 = *(u32 *)(puVar16 + 0x2e);
            uVar10 = *(u32 *)((int)puVar16 + 0x174);
            uVar11 = *(u32 *)(puVar16 + 0x2f);
            uVar12 = *(u32 *)((int)puVar16 + 0x17c);
            uVar8 = puVar16[0x28];
            uVar22 = *(u32 *)(puVar16 + 0x29);
            uVar23 = *(u32 *)((int)puVar16 + 0x14c);
            puVar6[0x50] = (int)uVar8;
            puVar6[0x51] = (int)((u32)uVar8 >> 0x20);
            puVar6[0x52] = uVar22;
            puVar6[0x53] = uVar23;
            puVar6[0x54] = uVar27;
            puVar6[0x55] = uVar28;
            puVar6[0x56] = uVar29;
            puVar6[0x57] = uVar30;
            puVar6[0x58] = (int)uVar19;
            puVar6[0x59] = (int)((u32)uVar19 >> 0x20);
            puVar6[0x5a] = uVar25;
            puVar6[0x5b] = uVar26;
            puVar6[0x5c] = uVar14;
            puVar6[0x5d] = uVar10;
            puVar6[0x5e] = uVar11;
            puVar6[0x5f] = uVar12;
            uVar27 = *(u32 *)(puVar16 + 0x32);
            uVar28 = *(u32 *)((int)puVar16 + 0x194);
            uVar29 = *(u32 *)(puVar16 + 0x33);
            uVar30 = *(u32 *)((int)puVar16 + 0x19c);
            uVar19 = puVar16[0x34];
            uVar25 = *(u32 *)(puVar16 + 0x35);
            uVar26 = *(u32 *)((int)puVar16 + 0x1ac);
            uVar14 = *(u32 *)(puVar16 + 0x36);
            uVar10 = *(u32 *)((int)puVar16 + 0x1b4);
            uVar11 = *(u32 *)(puVar16 + 0x37);
            uVar12 = *(u32 *)((int)puVar16 + 0x1bc);
            uVar8 = puVar16[0x30];
            uVar22 = *(u32 *)(puVar16 + 0x31);
            uVar23 = *(u32 *)((int)puVar16 + 0x18c);
            puVar6[0x60] = (int)uVar8;
            puVar6[0x61] = (int)((u32)uVar8 >> 0x20);
            puVar6[0x62] = uVar22;
            puVar6[99] = uVar23;
            puVar6[100] = uVar27;
            puVar6[0x65] = uVar28;
            puVar6[0x66] = uVar29;
            puVar6[0x67] = uVar30;
            puVar6[0x68] = (int)uVar19;
            puVar6[0x69] = (int)((u32)uVar19 >> 0x20);
            puVar6[0x6a] = uVar25;
            puVar6[0x6b] = uVar26;
            puVar6[0x6c] = uVar14;
            puVar6[0x6d] = uVar10;
            puVar6[0x6e] = uVar11;
            puVar6[0x6f] = uVar12;
            uVar27 = *(u32 *)(puVar16 + 0x3a);
            uVar28 = *(u32 *)((int)puVar16 + 0x1d4);
            uVar29 = *(u32 *)(puVar16 + 0x3b);
            uVar30 = *(u32 *)((int)puVar16 + 0x1dc);
            uVar19 = puVar16[0x3c];
            uVar25 = *(u32 *)(puVar16 + 0x3d);
            uVar26 = *(u32 *)((int)puVar16 + 0x1ec);
            uVar14 = *(u32 *)(puVar16 + 0x3e);
            uVar10 = *(u32 *)((int)puVar16 + 500);
            uVar11 = *(u32 *)(puVar16 + 0x3f);
            uVar12 = *(u32 *)((int)puVar16 + 0x1fc);
            uVar8 = puVar16[0x38];
            uVar22 = *(u32 *)(puVar16 + 0x39);
            uVar23 = *(u32 *)((int)puVar16 + 0x1cc);
            puVar6[0x70] = (int)uVar8;
            puVar6[0x71] = (int)((u32)uVar8 >> 0x20);
            puVar6[0x72] = uVar22;
            puVar6[0x73] = uVar23;
            puVar16 = puVar16 + 0x40;
            puVar6[0x74] = uVar27;
            puVar6[0x75] = uVar28;
            puVar6[0x76] = uVar29;
            puVar6[0x77] = uVar30;
            puVar6[0x78] = (int)uVar19;
            puVar6[0x79] = (int)((u32)uVar19 >> 0x20);
            puVar6[0x7a] = uVar25;
            puVar6[0x7b] = uVar26;
            puVar6[0x7c] = uVar14;
            puVar6[0x7d] = uVar10;
            puVar6[0x7e] = uVar11;
            puVar6[0x7f] = uVar12;
            puVar6 = puVar6 + 0x80;
          } while (uVar32 < uVar4 - 8);
        }
        for (; uVar32 < uVar4; uVar32 = uVar32 + 1) {
          uVar19 = puVar16[2];
          uVar28 = *(u32 *)(puVar16 + 3);
          uVar29 = *(u32 *)((int)puVar16 + 0x1c);
          uVar14 = *(u32 *)(puVar16 + 4);
          uVar10 = *(u32 *)((int)puVar16 + 0x24);
          uVar11 = *(u32 *)(puVar16 + 5);
          uVar12 = *(u32 *)((int)puVar16 + 0x2c);
          uVar8 = puVar16[6];
          uVar26 = *(u32 *)(puVar16 + 7);
          uVar27 = *(u32 *)((int)puVar16 + 0x3c);
          uVar22 = *(u32 *)((int)puVar16 + 4);
          uVar23 = *(u32 *)(puVar16 + 1);
          uVar25 = *(u32 *)((int)puVar16 + 0xc);
          *puVar6 = *(u32 *)puVar16;
          puVar6[1] = uVar22;
          puVar6[2] = uVar23;
          puVar6[3] = uVar25;
          puVar16 = puVar16 + 8;
          puVar6[4] = (int)uVar19;
          puVar6[5] = (int)((u32)uVar19 >> 0x20);
          puVar6[6] = uVar28;
          puVar6[7] = uVar29;
          puVar6[8] = uVar14;
          puVar6[9] = uVar10;
          puVar6[10] = uVar11;
          puVar6[0xb] = uVar12;
          puVar6[0xc] = (int)uVar8;
          puVar6[0xd] = (int)((u32)uVar8 >> 0x20);
          puVar6[0xe] = uVar26;
          puVar6[0xf] = uVar27;
          puVar6 = puVar6 + 0x10;
        }
      }
      DAT_0095de38 = (u32)((u32 *)0x0);
      puGpffffbd04 = puVar6;
    }
    else {
      DAT_0095de38 = (u32 *)((u32)(puVar3 + 0xb));
    }
    uVar19 = 1;
  }
  return uVar19;
}

// FUN_00472130 NONMATCHING

void FUN_00472130(u64 param_1)

{
  if (DAT_0095de38 != 0) {
    ((code)FUN_0046b8e0)();
  }
  ((code)FUN_004a0e00)(param_1);
  return;
}

// FUN_00472170 NONMATCHING

void FUN_00472170(u64 param_1)

{
  if (DAT_0095de38 != 0) {
    ((code)FUN_0046b8e0)();
  }
  ((code)FUN_0046c5b0)(param_1);
  return;
}

// FUN_004721B0 NONMATCHING

void FUN_004721b0(u64 param_1)

{
  if (DAT_0095de38 != 0) {
    ((code)FUN_0046b8e0)();
  }
  ((code)FUN_0046cd90)(param_1);
  return;
}

// FUN_004721F0 NONMATCHING

void FUN_004721f0(u64 param_1)

{
  if (DAT_0095de38 != 0) {
    ((code)FUN_0046b8e0)();
  }
  ((code)FUN_0046d6f0)(param_1);
  return;
}

// FUN_00472230 NONMATCHING

void FUN_00472230(u64 param_1)

{
  if (DAT_0095de38 != 0) {
    ((code)FUN_0046b8e0)();
  }
  ((code)FUN_0046e170)(param_1);
  return;
}

// FUN_00472270 NONMATCHING



u64 FUN_00472270(int param_1)

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
  u64 extraout_v0_udw;
  Vec128 auVar14;
  Vec128 auVar15;
  Vec128 auVar16;
  Vec128 auVar17;
  Vec128 auVar18;
  u64 extraout_v0_udw_00;
  Vec128 auVar19;
  Vec128 auVar20;
  Vec128 auVar21;
  Vec128 auVar22;
  u64 extraout_v0_udw_01;
  Vec128 auVar23;
  u64 extraout_v0_udw_02;
  Vec128 auVar24;
  Vec128 auVar25;
  Vec128 auVar26;
  Vec128 auVar27;
  Vec128 auVar28;
  Vec128 auVar29;
  u64 uVar34;
  Vec128 auVar30;
  Vec128 auVar31;
  Vec128 auVar32;
  Vec128 auVar33;
  u8 bVar35;
  u32 *puVar36;
  u32 in_v1_udw;
  Vec128 auVar37;
  Vec128 auVar38;
  u32 uVar44;
  Vec128 auVar39;
  Vec128 auVar40;
  Vec128 auVar41;
  Vec128 auVar42;
  Vec128 auVar43;
  u32 uVar45;
  u32 in_a0_udw;
  Vec128 auVar46;
  Vec128 auVar47;
  Vec128 auVar48;
  Vec128 auVar49;
  Vec128 auVar50;
  Vec128 in_a1_qw;
  u32 uVar53;
  Vec128 auVar51;
  Vec128 auVar52;
  Vec128 auVar54;
  Vec128 auVar55;
  int iVar56;
  u64 *puVar57;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_34;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  puVar57 = (u64 *)**(int **)(*(int *)(*(int *)(param_1 + 0x2c) + 8) + iGpffffba48);
  if (puVar57 == (u64 *)0x0) {
    uStack_18 = 0x3f800000;
    uStack_2c = 0x3f800000;
    puVar57 = (u64 *)&uStack_40;
    uStack_40 = 0x3f800000;
    uStack_30 = 0;
    uStack_38 = 0;
    uStack_3c = 0;
    uStack_1c = 0;
    uStack_20 = 0;
    uStack_34 = uStack_34 | 0x20003;
    uStack_28 = 0;
    uStack_8 = 0;
    uStack_c = 0;
    uStack_10 = 0;
  }
  if (*(u32 **)(param_1 + 0x40) != (u32 *)0x0) {
    ((code)FUN_004f0f30)(**(u32 **)(param_1 + 0x40));
  }
  uVar53 = (*(u64*)((u8*)&in_a1_qw + 8));
  piVar1 = *(int **)(param_1 + 0x40);
  iVar56 = 0;
  if (piVar1 != (int *)0x0) {
    iVar56 = *piVar1;
  }
  uGpffffbdc8 = 0;
  if (iVar56 != 0) {
    bVar35 = *(u8 *)(iVar56 + 0x23) & 0xf;
    uGpffffbdc8 = (u32)(bVar35 == 1 || bVar35 == 5);
  }
  if (iVar56 != iGpffffbdcc) {
    if (iVar56 == 0) {
      uGpffffb0d0 = uGpffffb0d0 & 0xffffffffffffffef;
    }
    else {
      auVar15._8_8_ = 0;
      auVar15._0_8_ = uVar53;
      (*(u64*)((u8*)&in_a1_qw + 0)) = (*(u64*)((u8*)&auVar15 + 0)) << 0x40;
      uGpffffb0d0 = uGpffffb0d0 | 0x10;
      ((code)FUN_004f1020)(iVar56,0);
    }
    uVar53 = (*(u64*)((u8*)&in_a1_qw + 8));
    iGpffffbdcc = iVar56;
    if (piVar1 != (int *)0x0) {
      ((code)FUN_0049ca50)((char)piVar1[0x14]);
      uVar53 = (*(u64*)((u8*)&in_a1_qw + 8));
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
  ((code)FUN_004d59d0)(0,4);
  auVar37._8_8_ = in_v1_udw;
  auVar37._0_8_ = 0x6c0303bc01000404;
  auVar14._8_8_ = extraout_v0_udw;
  auVar14._0_8_ = 0x10000003;
  auVar15 = _pcpyld(auVar37,auVar14);
  auVar46._8_8_ = 0;
  auVar46._0_8_ = in_a0_udw;
  auVar46._0_8_ = auVar46._0_8_ << 0x40;
  *puGpffffbd04 = auVar15._0_4_;
  puGpffffbd04[1] = auVar15._4_4_;
  puGpffffbd04[2] = auVar15._8_4_;
  puGpffffbd04[3] = auVar15._12_4_;
  auVar16._8_8_ = auVar15._8_8_;
  auVar16._0_8_ = *puVar57;
  auVar15 = _pcpyld(auVar46,auVar16);
  puGpffffbd04[4] = auVar15._0_4_;
  puGpffffbd04[5] = auVar15._4_4_;
  puGpffffbd04[6] = auVar15._8_4_;
  puGpffffbd04[7] = auVar15._12_4_;
  auVar17._8_8_ = auVar15._8_8_;
  auVar17._0_8_ = puVar57[2];
  auVar15 = _pcpyld(auVar46,auVar17);
  puGpffffbd04[8] = auVar15._0_4_;
  puGpffffbd04[9] = auVar15._4_4_;
  puGpffffbd04[10] = auVar15._8_4_;
  puGpffffbd04[0xb] = auVar15._12_4_;
  auVar18._8_8_ = auVar15._8_8_;
  auVar18._0_8_ = puVar57[6];
  auVar15 = _pcpyld(auVar46,auVar18);
  puGpffffbd04[0xc] = auVar15._0_4_;
  puGpffffbd04[0xd] = auVar15._4_4_;
  puGpffffbd04[0xe] = auVar15._8_4_;
  puGpffffbd04[0xf] = auVar15._12_4_;
  puGpffffbd04 = puGpffffbd04 + 0x10;
  ((code)FUN_004d59d0)(0,0x12);
  auVar54._8_8_ = 0;
  auVar54._0_8_ = in_v1_udw;
  auVar19._8_8_ = extraout_v0_udw_00;
  auVar19._0_8_ = 0x1000000f;
  auVar54 = _pcpyld(auVar54 << 0x40,auVar19);
  auVar47._8_8_ = auVar46._8_8_;
  auVar8._8_8_ = 0;
  auVar8._0_8_ = uVar53;
  auVar20._8_8_ = extraout_v0_udw_00;
  auVar20._0_8_ = 0x6c0103fa01000404;
  *puGpffffbd04 = auVar54._0_4_;
  puGpffffbd04[1] = auVar54._4_4_;
  puGpffffbd04[2] = auVar54._8_4_;
  puGpffffbd04[3] = auVar54._12_4_;
  auVar15 = _pcpyld(auVar20,auVar8 << 0x40);
  puGpffffbd04[4] = auVar15._0_4_;
  puGpffffbd04[5] = auVar15._4_4_;
  puGpffffbd04[6] = auVar15._8_4_;
  puGpffffbd04[7] = auVar15._12_4_;
  auVar21._8_8_ = auVar15._8_8_;
  bVar3 = *(char *)(param_1 + 0x47) != -1;
  uGpffffbdc4 = (u32)bVar3;
  if (bVar3 || uGpffffbdc8 != 0) {
    uGpffffb0d0 = uGpffffb0d0 | 0x40;
  }
  else {
    uGpffffb0d0 = uGpffffb0d0 & 0xffffffffffffffbf;
  }
  auVar55._8_8_ = auVar54._8_8_;
  auVar55._0_8_ = 0xfc007fffffffffff;
  auVar21._4_4_ = DAT_009658ac;
  auVar21._0_4_ = DAT_009658a8;
  auVar4._4_4_ = in_zero_hi;
  auVar4._0_4_ = in_zero_lo;
  auVar4._8_4_ = in_zero_udw;
  auVar4._12_4_ = in_register_0000000c;
  auVar15 = _pcpyld(auVar4,auVar55);
  auVar47._0_8_ =
       CONCAT44((*(u32*)((u8*)&DAT_009658a0 + 4)),(u32)DAT_009658a0) & (*(u64*)((u8*)&auVar15 + 0)) |
       ((long)(int)((u32)uGpffffb0d0 | (u32)*(u8 *)(param_1 + 0x29)) & 0x7ffU) << 0x2f;
  auVar15 = _pcpyld(auVar21,auVar47);
  (*(u32*)((u8*)&DAT_009658a0 + 0)) = (*(u32*)((u8*)&auVar15 + 0));
  (*(u32*)((u8*)&DAT_009658a0 + 4)) = (*(u32*)((u8*)&auVar15 + 4));
  DAT_009658a8 = auVar15._8_4_;
  DAT_009658ac = auVar15._12_4_;
  puGpffffbd04[8] = (u32)DAT_009658a0;
  puGpffffbd04[9] = auVar15._4_4_;
  puGpffffbd04[10] = auVar15._8_4_;
  puGpffffbd04[0xb] = auVar15._12_4_;
  auVar5._8_8_ = 0;
  auVar5._0_8_ = auVar15._8_8_;
  auVar22._8_8_ = auVar21._8_8_;
  auVar22._0_8_ = 0x6c0103fb01000404;
  auVar15 = _pcpyld(auVar22,auVar5 << 0x40);
  puGpffffbd04[0xc] = auVar15._0_4_;
  puGpffffbd04[0xd] = auVar15._4_4_;
  puGpffffbd04[0xe] = auVar15._8_4_;
  puGpffffbd04[0xf] = auVar15._12_4_;
  puGpffffbd04 = puGpffffbd04 + 0x10;
  if ((uGpffffb0d0 & 0x10) == 0) {
    uVar13 = 0x3b808081;
  }
  else {
    uVar13 = 0x3b011b50;
  }
  ((code)FUN_0049cab0)(uVar13,param_1 + 0x44);
  auVar9._8_8_ = 0;
  auVar9._0_8_ = auVar47._8_8_;
  auVar23._8_8_ = extraout_v0_udw_01;
  auVar23._0_8_ = 0x6c0103fc01000404;
  auVar15 = _pcpyld(auVar23,auVar9 << 0x40);
  *puGpffffbd04 = auVar15._0_4_;
  puGpffffbd04[1] = auVar15._4_4_;
  puGpffffbd04[2] = auVar15._8_4_;
  puGpffffbd04[3] = auVar15._12_4_;
  puGpffffbd04 = puGpffffbd04 + 4;
  uVar34 = auVar15._8_8_;
  ((code)FUN_0049cbd0)(*(u32 *)(param_1 + 0x1c),*(u32 *)(param_1 + 0x3c));
  puVar12 = puGpffffbd04;
  bVar35 = *(u8 *)(param_1 + 0x28);
  auVar10._8_8_ = 0;
  auVar10._0_8_ = uVar53;
  auVar38._8_8_ = uVar34;
  auVar38._0_8_ = 0x6c0303fd01000404;
  auVar47._8_8_ = (u32)bVar35 & 7;
  auVar15 = _pcpyld(auVar38,auVar10 << 0x40);
  *puGpffffbd04 = auVar15._0_4_;
  puGpffffbd04[1] = auVar15._4_4_;
  puGpffffbd04[2] = auVar15._8_4_;
  puGpffffbd04[3] = auVar15._12_4_;
  auVar46 = _DAT_00965930;
  auVar15 = _DAT_00965910;
  if (((iGpffffbe14 == 0) || ((bVar35 & 4) != 0)) && ((iGpffffb0f8 == 0 || ((bVar35 & 4) == 0)))) {
    puGpffffbd04[4] = (u32)(DAT_00965910);
    puGpffffbd04[5] = auVar15._4_4_;
    puGpffffbd04[6] = auVar15._8_4_;
    puGpffffbd04[7] = auVar15._12_4_;
    auVar46 = _DAT_00965920;
    puGpffffbd04[8] = DAT_00965920;
    puGpffffbd04[9] = auVar46._4_4_;
    puGpffffbd04[10] = auVar46._8_4_;
    puGpffffbd04[0xb] = auVar46._12_4_;
    uVar44 = auVar46._8_8_;
  }
  else {
    auVar47._8_8_ = auVar47._8_8_ | 8;
    puGpffffbd04[4] = (u32)(DAT_00965930);
    puGpffffbd04[5] = auVar46._4_4_;
    puGpffffbd04[6] = auVar46._8_4_;
    puGpffffbd04[7] = auVar46._12_4_;
    auVar15 = _DAT_00965940;
    puGpffffbd04[8] = DAT_00965940;
    puGpffffbd04[9] = auVar15._4_4_;
    puGpffffbd04[10] = auVar15._8_4_;
    puGpffffbd04[0xb] = auVar15._12_4_;
    uVar44 = auVar15._8_8_;
    auVar15 = auVar46;
  }
  uGpffffbe0c = 0;
  auVar48._8_8_ = auVar15._8_8_;
  uVar45 = 0;
  if (iGpffffbdbc == 3) {
    uVar45 = 0x20;
    uGpffffbe0c = 0x20;
  }
  auVar24._8_8_ = extraout_v0_udw_02;
  auVar24._0_8_ = auVar47._8_8_;
  auVar48._0_8_ = (u32)uGpffffbe10 << 0x20 | uVar45;
  auVar15 = _pcpyld(auVar48,auVar24);
  puGpffffbd04[0xc] = auVar15._0_4_;
  puGpffffbd04[0xd] = auVar15._4_4_;
  puGpffffbd04[0xe] = auVar15._8_4_;
  puGpffffbd04[0xf] = auVar15._12_4_;
  puVar36 = puGpffffbd04 + 0x10;
  auVar49._8_8_ = auVar15._8_8_;
  if (*(int *)(param_1 + 0x40) == 0) {
    *puVar36 = in_zero_lo;
    puGpffffbd04[0x11] = in_zero_hi;
    puGpffffbd04[0x12] = in_zero_udw;
    puGpffffbd04[0x13] = in_register_0000000c;
    auVar32._8_8_ = extraout_v0_udw_02;
    auVar32._0_8_ = 0x5000000200000000;
    auVar11._8_8_ = 0;
    auVar11._0_8_ = uVar44;
    puGpffffbd04[0x14] = in_zero_lo;
    puGpffffbd04[0x15] = in_zero_hi;
    puGpffffbd04[0x16] = in_zero_udw;
    puGpffffbd04[0x17] = in_register_0000000c;
    auVar15 = _pcpyld(auVar32,auVar11 << 0x40);
    puGpffffbd04[0x18] = auVar15._0_4_;
    puGpffffbd04[0x19] = auVar15._4_4_;
    puGpffffbd04[0x1a] = auVar15._8_4_;
    puGpffffbd04[0x1b] = auVar15._12_4_;
    auVar50._8_8_ = auVar49._8_8_;
    auVar50._0_8_ = 0xe;
    auVar33._8_8_ = auVar15._8_8_;
    auVar42._8_8_ = uVar44;
    auVar42._0_8_ = 0x1000000000008001;
    auVar15 = _pcpyld(auVar50,auVar42);
    puGpffffbd04[0x1c] = auVar15._0_4_;
    puGpffffbd04[0x1d] = auVar15._4_4_;
    puGpffffbd04[0x1e] = auVar15._8_4_;
    puGpffffbd04[0x1f] = auVar15._12_4_;
    auVar33._0_8_ = 0x47;
    auVar43._8_8_ = auVar15._8_8_;
    auVar43._0_8_ = uGpffffbd50;
    auVar15 = _pcpyld(auVar33,auVar43);
    puGpffffbd04[0x20] = auVar15._0_4_;
    puGpffffbd04[0x21] = auVar15._4_4_;
    puGpffffbd04[0x22] = auVar15._8_4_;
    puGpffffbd04[0x23] = auVar15._12_4_;
    uVar34 = auVar15._8_8_;
  }
  else {
    auVar6._8_8_ = 0;
    auVar6._0_8_ = auVar49._8_8_;
    auVar25._8_8_ = extraout_v0_udw_02;
    auVar25._0_8_ = 0x5000000400000000;
    auVar15 = _pcpyld(auVar25,auVar6 << 0x40);
    auVar49._0_8_ = 0xe;
    *puVar36 = auVar15._0_4_;
    puGpffffbd04[0x11] = auVar15._4_4_;
    puGpffffbd04[0x12] = auVar15._8_4_;
    puGpffffbd04[0x13] = auVar15._12_4_;
    auVar26._8_8_ = auVar15._8_8_;
    auVar26._0_8_ = 0x1000000000008003;
    auVar15 = _pcpyld(auVar49,auVar26);
    puGpffffbd04[0x14] = auVar15._0_4_;
    puGpffffbd04[0x15] = auVar15._4_4_;
    puGpffffbd04[0x16] = auVar15._8_4_;
    puGpffffbd04[0x17] = auVar15._12_4_;
    auVar39._8_8_ = uVar44;
    auVar39._0_8_ = uGpffffbd50;
    auVar27._8_8_ = auVar15._8_8_;
    auVar27._0_8_ = 0x47;
    auVar15 = _pcpyld(auVar27,auVar39);
    puGpffffbd04[0x18] = auVar15._0_4_;
    puGpffffbd04[0x19] = auVar15._4_4_;
    puGpffffbd04[0x1a] = auVar15._8_4_;
    puGpffffbd04[0x1b] = auVar15._12_4_;
    auVar40._8_8_ = uVar44;
    auVar40._0_8_ = uGpffffbd70;
    auVar28._8_8_ = auVar15._8_8_;
    auVar28._0_8_ = 0x14;
    auVar15 = _pcpyld(auVar28,auVar40);
    puGpffffbd04[0x1c] = auVar15._0_4_;
    puGpffffbd04[0x1d] = auVar15._4_4_;
    puGpffffbd04[0x1e] = auVar15._8_4_;
    puGpffffbd04[0x1f] = auVar15._12_4_;
    auVar41._8_8_ = uVar44;
    auVar41._0_8_ = uGpffffbd68;
    auVar29._8_8_ = auVar15._8_8_;
    auVar29._0_8_ = 8;
    auVar15 = _pcpyld(auVar29,auVar41);
    puGpffffbd04[0x20] = auVar15._0_4_;
    puGpffffbd04[0x21] = auVar15._4_4_;
    puGpffffbd04[0x22] = auVar15._8_4_;
    puGpffffbd04[0x23] = auVar15._12_4_;
    uVar34 = auVar15._8_8_;
  }
  puGpffffbd04 = puGpffffbd04 + 0x24;
  auVar51._0_8_ = (long)(int)puVar36;
  auVar51._8_8_ = uVar53;
  *(u8 *)(param_1 + 0x2b) =
       (u8)((int)(*(u8 *)(param_1 + 0x28) & 0x20) >> 5) |
       (u8)((int)(*(u8 *)(param_1 + 0x28) & 0x18) >> 2);
  uVar2 = *(u32 *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + (u32)*(u8 *)(param_1 + 0x2b) * 4);
  if (uGpffffbe08 != uVar2) {
    auVar7._8_8_ = 0;
    auVar7._0_8_ = uVar53;
    auVar51._0_8_ = auVar7._0_8_ << 0x40;
    auVar30._0_8_ = (u32)uVar2 << 0x20 | 0x50000000;
    auVar30._8_8_ = uVar34;
    auVar15 = _pcpyld(auVar51,auVar30);
    *puGpffffbd04 = auVar15._0_4_;
    puVar12[0x25] = auVar15._4_4_;
    puVar12[0x26] = auVar15._8_4_;
    puVar12[0x27] = auVar15._12_4_;
    puGpffffbd04 = puVar12 + 0x28;
    uGpffffbe08 = uVar2;
  }
  auVar52._8_8_ = auVar51._8_8_;
  iVar56 = **(int **)(param_1 + 0x30);
  auVar52._0_8_ = ((long)*(int *)(*(int *)(param_1 + 4) + 0x14) | 0x2000000U) << 0x20 | 0x3000000;
  auVar31._0_8_ = (u32)*(u32 *)(iVar56 + 0x20) << 0x20 | 0x50000000;
  auVar31._8_8_ = uVar34;
  auVar15 = _pcpyld(auVar52,auVar31);
  *puGpffffbd04 = auVar15._0_4_;
  puGpffffbd04[1] = auVar15._4_4_;
  puGpffffbd04[2] = auVar15._8_4_;
  puGpffffbd04[3] = auVar15._12_4_;
  puGpffffbd04 = puGpffffbd04 + 4;
  do {
    DI();
    SYNC(0x10);
  } while ((Status & 0x10000) != 0);
  *(int *)(iVar56 + 0x18) = *(int *)(iVar56 + 0x18) + 1;
  EI();
  *(int *)(iVar56 + 0x1c) = *(int *)(iVar56 + 0x1c) + 1;
  if (*(int *)(iVar56 + 0x1c) == 1) {
    ((code)FUN_004d51c0)();
  }
  return 1;
}

// FUN_00472970 NONMATCHING



u64 FUN_00472970(int param_1)

{
  u8 bVar1;
  int *piVar2;
  u32 *puVar3;
  u32 uVar4;
  u32 uVar5;
  int iVar6;
  u8 bVar7;
  Vec128 auVar8;
  long lVar9;
  Vec128 auVar10;
  Vec128 auVar11;
  Vec128 auVar12;
  Vec128 auVar13;
  Vec128 auVar14;
  Vec128 auVar15;
  Vec128 auVar16;
  Vec128 auVar17;
  Vec128 auVar18;
  Vec128 auVar19;
  Vec128 auVar20;
  Vec128 auVar21;
  Vec128 auVar22;
  Vec128 auVar23;
  Vec128 auVar24;
  Vec128 auVar25;
  Vec128 auVar26;
  u32 in_zero_lo;
  u32 in_zero_hi;
  u32 in_zero_udw;
  u32 in_register_0000000c;
  u32 uVar27;
  u32 uVar28;
  u32 in_v0_udw;
  u32 in_register_0000002c;
  u64 extraout_v0_udw;
  Vec128 auVar29;
  Vec128 auVar30;
  Vec128 auVar31;
  Vec128 auVar32;
  u64 extraout_v0_udw_00;
  Vec128 auVar33;
  Vec128 auVar34;
  Vec128 auVar35;
  Vec128 auVar36;
  u32 *puVar37;
  u64 uVar38;
  u32 uVar39;
  u32 in_v1_udw;
  Vec128 auVar40;
  u64 uVar56;
  Vec128 auVar41;
  Vec128 auVar42;
  Vec128 auVar43;
  Vec128 auVar44;
  Vec128 auVar45;
  Vec128 auVar46;
  Vec128 auVar47;
  Vec128 auVar48;
  Vec128 auVar49;
  Vec128 auVar50;
  Vec128 auVar51;
  Vec128 auVar52;
  Vec128 auVar53;
  Vec128 auVar54;
  Vec128 auVar55;
  u32 in_a0_udw;
  Vec128 auVar57;
  Vec128 auVar58;
  Vec128 auVar59;
  Vec128 auVar60;
  Vec128 auVar61;
  Vec128 auVar62;
  Vec128 auVar63;
  Vec128 auVar64;
  Vec128 auVar65;
  Vec128 auVar66;
  Vec128 auVar67;
  Vec128 auVar68;
  Vec128 auVar69;
  Vec128 auVar70;
  u64 uVar73;
  Vec128 auVar71;
  Vec128 auVar72;
  u32 *puVar74;
  Vec128 auVar75;
  Vec128 auVar76;
  Vec128 auVar77;
  Vec128 auVar78;
  Vec128 auVar79;
  Vec128 auVar80;
  Vec128 auVar81;
  u64 in_t0_udw;
  Vec128 auVar82;
  Vec128 auVar83;
  Vec128 auVar84;
  Vec128 auVar85;
  u64 in_t1_udw;
  u64 in_t2_udw;
  Vec128 auVar86;
  u64 in_t3_udw;
  Vec128 auVar87;
  Vec128 auVar88;
  Vec128 auVar89;
  u64 in_t4_udw;
  Vec128 auVar90;
  Vec128 auVar91;
  u64 in_t5_udw;
  u64 in_t6_udw;
  Vec128 auVar92;
  Vec128 auVar93;
  u32 in_t7_udw;
  u32 in_register_000000fc;
  long lVar94;
  u8 in_s0_qw [16];
  u64 uVar97;
  Vec128 auVar95;
  Vec128 auVar96;
  u64 *puVar98;
  u64 *puVar99;
  long lVar100;
  Vec128 auVar101;
  u8 in_s5_qw [16];
  Vec128 auVar102;
  u32 uVar103;
  u32 in_s6_udw;
  u32 in_register_0000016c;
  u32 in_s7_udw;
  u32 in_register_0000017c;
  u32 in_s8_udw;
  u32 in_register_000001ec;
  u32 uStack_60;
  u32 uStack_5c;
  u32 uStack_58;
  u32 uStack_54;
  u32 uStack_50;
  u32 uStack_4c;
  u32 uStack_48;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u64 uStack_18;
  u64 uStack_10;
  u64 uStack_8;
  
  uVar73 = uGpffffbd40;
  piVar2 = *(int **)(*(int *)(param_1 + 0x2c) + 8);
  puVar3 = (u32 *)*piVar2;
  uVar97 = (*(u64*)((u8*)&in_s0_qw + 8));
  lVar94 = (long)(int)puVar3;
  piVar2 = *(int **)((int)piVar2 + iGpffffba48);
  lVar9 = *(long *)(piVar2 + 0x1c);
  uVar27 = (u32)lVar9;
  uVar103 = (u32)((u32)lVar9 >> 0x20);
  lVar100 = (long)piVar2[0x10];
  uVar56 = *(u64 *)(piVar2 + 0x1a);
  auVar76._8_8_ = 0;
  (*(u64*)((u8*)&auVar76 + 0)) = (*(u64*)((u8*)&in_s5_qw + 8));
  auVar88._0_8_ = auVar76._0_8_ << 0x40;
  if (lVar9 == 0x1000000) {
    uVar27 = (u32)uGpffffbd60;
    uVar103 = (u32)((u32)uGpffffbd60 >> 0x20);
  }
  uVar38 = *(u64 *)(piVar2 + 0x1e);
  uStack_8 = 0;
  puVar99 = (u64 *)*piVar2;
  puVar98 = (u64 *)piVar2[1];
  uVar5 = (u32)uGpffffbd50;
  if ((puVar99 == (u64 *)0x0) || (puVar98 == (u64 *)0x0)) {
    if (puVar99 == (u64 *)0x0) {
      puVar99 = (u64 *)&uStack_60;
    }
    if (puVar98 == (u64 *)0x0) {
      puVar98 = (u64 *)&uStack_60;
    }
    uStack_38 = 0x3f800000;
    uStack_4c = 0x3f800000;
    uStack_60 = 0x3f800000;
    uStack_50 = 0;
    uStack_58 = 0;
    uStack_5c = 0;
    uStack_3c = 0;
    uStack_40 = 0;
    uStack_54 = uStack_54 | 0x20003;
    uStack_48 = 0;
    uStack_28 = 0;
    uStack_2c = 0;
    uStack_30 = 0;
  }
  uStack_10 = 0;
  uStack_18 = 0;
  iGpffffbdc8 = 0;
  if ((lVar94 != 0) && (((code)FUN_004f0f30)(*puVar3), (*(u8 *)(*(int *)lVar94 + 0x23) & 0xf) != 6)) {
    iGpffffbdc8 = 1;
  }
  if (lVar100 != 0) {
    ((code)FUN_004f0f30)(*(u32 *)lVar100);
    ((code)FUN_004f1020)(*(u32 *)lVar100,1);
  }
  if (lVar94 != 0) {
    ((code)FUN_004f1020)(*(u32 *)lVar94,0);
  }
  if ((lVar100 != 0) && (*(int *)(*(int *)lVar100 + iGpffffbdb8 + 0x58) == 0)) {
    ((code)FUN_004f1020)(*(int *)lVar100,1);
  }
  if ((lVar94 != 0) && (*(int *)(*(int *)lVar94 + iGpffffbdb8 + 0x58) == 0)) {
    ((code)FUN_004f1020)(*(int *)lVar94,0);
  }
  if (lVar94 == 0) {
    uGpffffbdcc = 0;
    uGpffffb0d0 = uGpffffb0d0 & 0xffffffffffffffef;
  }
  else {
    uGpffffb0d0 = uGpffffb0d0 | 0x10;
    uGpffffbdcc = *(u32 *)lVar94;
    ((code)FUN_004f1e20)(*(u32 *)lVar94,(int)&uStack_10 + 4,&uStack_10);
    ((code)FUN_004f1e40)(*(u32 *)lVar94,(u8 *)uGpffffbd70,*(u8 *)((u32 *)lVar94 + 0x14));
    uGpffffbd68 = (u32)((*(u32 *)((int)lVar94 + 0x50) & 0xf00) == 0x300);
    if ((*(u32 *)((int)lVar94 + 0x50) & 0xf000) == 0x3000) {
      uGpffffbd68 = uGpffffbd68 | 4;
    }
  }
  uGpffffbd50 = uGpffffbd50 | 1;
  if (lVar100 != 0) {
    ((code)FUN_004f1e20)(*(u32 *)lVar100,(int)&uStack_18 + 4,&uStack_18);
    ((code)FUN_004f1e40)(*(u32 *)lVar100,&uStack_8,*(u8 *)((u32 *)lVar100 + 0x14));
    uVar4 = *(u32 *)((int)lVar100 + 0x50);
    auVar72._8_8_ = auVar88._8_8_;
    auVar79._8_8_ = 0;
    auVar79._0_8_ = auVar72._8_8_;
    auVar88._0_8_ = auVar79._0_8_ << 0x40;
    if ((uVar4 & 0xf00) == 0x300) {
      auVar72._0_8_ = 1;
      auVar88 = auVar72;
    }
    if ((uVar4 & 0xf000) == 0x3000) {
      auVar88._0_8_ = auVar88._0_8_ | 4;
    }
  }
  if ((((lVar94 != 0) && (*(int *)(*(int *)lVar94 + 0x14) < 9)) && (lVar100 != 0)) &&
     (*(int *)(*(int *)lVar100 + 0x14) < 9)) {
    uGpffffbdcc = 0xffffffff;
  }
  ((code)FUN_004d59d0)(0,0x27);
  auVar20._8_8_ = 0;
  auVar20._0_8_ = in_a0_udw;
  auVar48._8_8_ = in_v1_udw;
  auVar48._0_8_ = 0x10000021;
  auVar79 = _pcpyld(auVar20 << 0x40,auVar48);
  auVar63._8_8_ = in_a0_udw;
  auVar63._0_8_ = 0x6c0a03bc;
  auVar49._8_8_ = in_v1_udw;
  auVar49._0_8_ = 0x1000101;
  auVar86._8_8_ = in_t2_udw;
  auVar86._0_8_ = 0x3d;
  auVar76 = _ppacw(auVar63,auVar49);
  *puGpffffbd04 = auVar79._0_4_;
  puGpffffbd04[1] = auVar79._4_4_;
  puGpffffbd04[2] = auVar79._8_4_;
  puGpffffbd04[3] = auVar79._12_4_;
  auVar80._8_8_ = auVar79._8_8_;
  auVar21._8_8_ = 0;
  auVar21._0_8_ = in_a0_udw;
  auVar22._8_8_ = 0;
  auVar22._0_8_ = in_v1_udw;
  auVar72 = _ppacw(auVar21 << 0x40,auVar22 << 0x40);
  auVar76 = _ppacw(auVar76,auVar72);
  puGpffffbd04[4] = auVar76._0_4_;
  puGpffffbd04[5] = auVar76._4_4_;
  puGpffffbd04[6] = auVar76._8_4_;
  puGpffffbd04[7] = auVar76._12_4_;
  auVar75._8_8_ = auVar76._8_8_;
  auVar50._8_8_ = in_v1_udw;
  auVar50._0_8_ = 0x1000000000008002;
  auVar81._8_8_ = in_t5_udw;
  auVar81._0_8_ = 0xe;
  auVar79 = _pcpyld(auVar81,auVar50);
  auVar102._4_4_ = uVar103;
  auVar102._0_4_ = uVar27;
  auVar102._8_4_ = in_s6_udw;
  auVar102._12_4_ = in_register_0000016c;
  auVar76 = _pcpyld(auVar86,auVar102);
  auVar92._8_8_ = in_t6_udw;
  auVar92._0_8_ = 0x412;
  auVar87._8_8_ = in_t3_udw;
  auVar87._0_8_ = 6;
  auVar82._8_8_ = in_t0_udw;
  auVar82._0_8_ = 0x50000006;
  auVar23._4_4_ = in_register_0000016c;
  auVar23._0_4_ = in_s6_udw;
  auVar23._8_8_ = 0;
  auVar83 = _ppacw(auVar82,auVar23 << 0x40);
  auVar72 = _ppacw(auVar83,auVar72);
  auVar84._8_8_ = auVar83._8_8_;
  auVar90._8_8_ = in_t4_udw;
  auVar90._0_8_ = 0x1000000000008005;
  auVar84._0_8_ = 0x43;
  auVar25._8_4_ = in_register_000000fc;
  auVar25._0_8_ =
       CONCAT44(in_t7_udw,
                ((*(u8 *)(param_1 + 0x28) & 1) << 5 | 600 | (u32)*(u8 *)(param_1 + 0x29)) <<
                0xf) | 0x30004000;
  auVar25._12_4_ = 0;
  auVar83 = _pcpyld(auVar92,auVar25 << 0x20);
  puGpffffbd04[8] = auVar83._0_4_;
  puGpffffbd04[9] = auVar83._4_4_;
  puGpffffbd04[10] = auVar83._8_4_;
  puGpffffbd04[0xb] = auVar83._12_4_;
  auVar85._8_8_ = in_t5_udw;
  auVar85._0_8_ = 0xe;
  auVar91 = _pcpyld(auVar85,auVar90);
  puGpffffbd04[0xc] = auVar79._0_4_;
  puGpffffbd04[0xd] = auVar79._4_4_;
  puGpffffbd04[0xe] = auVar79._8_4_;
  puGpffffbd04[0xf] = auVar79._12_4_;
  auVar93._8_8_ = auVar83._8_8_;
  auVar93._0_8_ = uStack_10;
  auVar96._8_8_ = in_t5_udw;
  auVar96._0_8_ = 9;
  auVar102 = _pcpyld(auVar96,auVar88);
  auVar101._8_8_ = in_t5_udw;
  auVar101._0_8_ = 0x48;
  auVar11._4_4_ = (int)((u32)uVar38 >> 0x20);
  auVar11._0_4_ = uVar5 & 0x70000 | (u32)uVar38;
  auVar11._8_4_ = in_s8_udw;
  auVar11._12_4_ = in_register_000001ec;
  auVar101 = _pcpyld(auVar101,auVar11);
  auVar24._4_4_ = in_register_0000002c;
  auVar24._0_4_ = in_v0_udw;
  auVar26._8_4_ = in_v0_udw;
  auVar26._0_8_ = uVar73;
  auVar26._12_4_ = in_register_0000002c;
  auVar95._8_8_ = uVar97;
  auVar95._0_8_ = 0x4f;
  auVar10._8_4_ = in_s7_udw;
  auVar10._0_8_ = uVar56;
  auVar10._12_4_ = in_register_0000017c;
  auVar85 = _pcpyld(auVar84,auVar10);
  auVar80._0_8_ = 0x6c0103fa01000404;
  auVar88 = _pcpyld(auVar87,auVar93);
  puGpffffbd04[0x10] = auVar88._0_4_;
  puGpffffbd04[0x11] = auVar88._4_4_;
  puGpffffbd04[0x12] = auVar88._8_4_;
  puGpffffbd04[0x13] = auVar88._12_4_;
  auVar89._8_8_ = auVar88._8_8_;
  auVar89._0_8_ = uGpffffbd60;
  auVar96 = _pcpyld(auVar95,auVar26);
  auVar24._8_8_ = 0;
  auVar81 = _pcpyld(auVar80,auVar24 << 0x40);
  auVar88 = _pcpyld(auVar86,auVar89);
  puGpffffbd04[0x14] = auVar88._0_4_;
  puGpffffbd04[0x15] = auVar88._4_4_;
  puGpffffbd04[0x16] = auVar88._8_4_;
  puGpffffbd04[0x17] = auVar88._12_4_;
  puGpffffbd04[0x18] = auVar79._0_4_;
  puGpffffbd04[0x19] = auVar79._4_4_;
  puGpffffbd04[0x1a] = auVar79._8_4_;
  puGpffffbd04[0x1b] = auVar79._12_4_;
  auVar64._8_8_ = auVar79._8_8_;
  auVar64._0_8_ = uStack_18;
  auVar83._8_8_ = in_t1_udw;
  auVar83._0_8_ = 7;
  auVar88 = _pcpyld(auVar83,auVar64);
  puGpffffbd04[0x1c] = auVar88._0_4_;
  puGpffffbd04[0x1d] = auVar88._4_4_;
  puGpffffbd04[0x1e] = auVar88._8_4_;
  puGpffffbd04[0x1f] = auVar88._12_4_;
  puGpffffbd04[0x20] = auVar76._0_4_;
  puGpffffbd04[0x21] = auVar76._4_4_;
  puGpffffbd04[0x22] = auVar76._8_4_;
  puGpffffbd04[0x23] = auVar76._12_4_;
  auVar57._8_8_ = auVar88._8_8_;
  auVar65._0_8_ = *puVar99;
  auVar65._8_8_ = auVar57._8_8_;
  auVar51._8_8_ = auVar76._8_8_;
  auVar51._0_8_ = *puVar98;
  auVar76 = _pcpyld(auVar51,auVar65);
  puGpffffbd04[0x24] = auVar76._0_4_;
  puGpffffbd04[0x25] = auVar76._4_4_;
  puGpffffbd04[0x26] = auVar76._8_4_;
  puGpffffbd04[0x27] = auVar76._12_4_;
  auVar66._0_8_ = puVar98[2];
  auVar66._8_8_ = auVar57._8_8_;
  auVar52._8_8_ = auVar76._8_8_;
  auVar52._0_8_ = puVar99[2];
  auVar76 = _pcpyld(auVar66,auVar52);
  puGpffffbd04[0x28] = auVar76._0_4_;
  puGpffffbd04[0x29] = auVar76._4_4_;
  puGpffffbd04[0x2a] = auVar76._8_4_;
  puGpffffbd04[0x2b] = auVar76._12_4_;
  auVar67._0_8_ = puVar98[6];
  auVar67._8_8_ = auVar57._8_8_;
  auVar53._8_8_ = auVar76._8_8_;
  auVar53._0_8_ = puVar99[6];
  auVar76 = _pcpyld(auVar67,auVar53);
  puGpffffbd04[0x2c] = auVar76._0_4_;
  puGpffffbd04[0x2d] = auVar76._4_4_;
  puGpffffbd04[0x2e] = auVar76._8_4_;
  puGpffffbd04[0x2f] = auVar76._12_4_;
  puGpffffbd04[0x30] = auVar72._0_4_;
  puGpffffbd04[0x31] = auVar72._4_4_;
  puGpffffbd04[0x32] = auVar72._8_4_;
  puGpffffbd04[0x33] = auVar72._12_4_;
  puGpffffbd04[0x34] = auVar91._0_4_;
  puGpffffbd04[0x35] = auVar91._4_4_;
  puGpffffbd04[0x36] = auVar91._8_4_;
  puGpffffbd04[0x37] = auVar91._12_4_;
  puGpffffbd04[0x38] = auVar85._0_4_;
  puGpffffbd04[0x39] = auVar85._4_4_;
  puGpffffbd04[0x3a] = auVar85._8_4_;
  puGpffffbd04[0x3b] = auVar85._12_4_;
  puGpffffbd04[0x3c] = auVar102._0_4_;
  puGpffffbd04[0x3d] = auVar102._4_4_;
  puGpffffbd04[0x3e] = auVar102._8_4_;
  puGpffffbd04[0x3f] = auVar102._12_4_;
  puGpffffbd04[0x40] = auVar101._0_4_;
  puGpffffbd04[0x41] = auVar101._4_4_;
  puGpffffbd04[0x42] = auVar101._8_4_;
  puGpffffbd04[0x43] = auVar101._12_4_;
  auVar54._8_8_ = auVar76._8_8_;
  auVar54._0_8_ = uStack_8;
  auVar91._8_8_ = in_t5_udw;
  auVar91._0_8_ = 0x15;
  auVar76 = _pcpyld(auVar91,auVar54);
  puGpffffbd04[0x44] = auVar76._0_4_;
  puGpffffbd04[0x45] = auVar76._4_4_;
  puGpffffbd04[0x46] = auVar76._8_4_;
  puGpffffbd04[0x47] = auVar76._12_4_;
  puGpffffbd04[0x48] = auVar96._0_4_;
  puGpffffbd04[0x49] = auVar96._4_4_;
  puGpffffbd04[0x4a] = auVar96._8_4_;
  puGpffffbd04[0x4b] = auVar96._12_4_;
  puGpffffbd04[0x4c] = auVar81._0_4_;
  puGpffffbd04[0x4d] = auVar81._4_4_;
  puGpffffbd04[0x4e] = auVar81._8_4_;
  puGpffffbd04[0x4f] = auVar81._12_4_;
  auVar40._8_8_ = auVar76._8_8_;
  bVar7 = *(char *)(param_1 + 0x47) != -1;
  uGpffffbdc4 = (u32)bVar7;
  if (bVar7 || iGpffffbdc8 != 0) {
    uGpffffb0d0 = uGpffffb0d0 | 0x40;
  }
  else {
    uGpffffb0d0 = uGpffffb0d0 & 0xffffffffffffffbf;
  }
  auVar16._8_8_ = 0;
  auVar16._0_8_ = auVar85._8_8_;
  auVar40._0_8_ = 0xfc007fffffffffff;
  auVar8._4_4_ = in_zero_hi;
  auVar8._0_4_ = in_zero_lo;
  auVar8._8_4_ = in_zero_udw;
  auVar8._12_4_ = in_register_0000000c;
  auVar76 = _pcpyld(auVar8,auVar40);
  uVar56 = auVar76._8_8_;
  auVar77._8_8_ = auVar81._8_8_;
  auVar77._4_4_ = DAT_009658ac;
  auVar77._0_4_ = DAT_009658a8;
  auVar57._0_8_ = 0x6c0103fb01000404;
  auVar75._0_8_ =
       CONCAT44((*(u32*)((u8*)&DAT_009658a0 + 4)),(u32)DAT_009658a0) & (*(u64*)((u8*)&auVar76 + 0)) |
       ((long)(int)((u32)uGpffffb0d0 | (u32)*(u8 *)(param_1 + 0x29)) & 0x7ffU) << 0x2f;
  auVar88 = _pcpyld(auVar77,auVar75);
  (*(u32*)((u8*)&DAT_009658a0 + 0)) = (*(u32*)((u8*)&auVar88 + 0));
  auVar76 = _pcpyld(auVar57,auVar16 << 0x40);
  (*(u32*)((u8*)&DAT_009658a0 + 4)) = (*(u32*)((u8*)&auVar88 + 4));
  DAT_009658a8 = auVar88._8_4_;
  DAT_009658ac = auVar88._12_4_;
  puGpffffbd04[0x50] = (u32)DAT_009658a0;
  puGpffffbd04[0x51] = auVar88._4_4_;
  puGpffffbd04[0x52] = auVar88._8_4_;
  puGpffffbd04[0x53] = auVar88._12_4_;
  puGpffffbd04[0x54] = auVar76._0_4_;
  puGpffffbd04[0x55] = auVar76._4_4_;
  puGpffffbd04[0x56] = auVar76._8_4_;
  puGpffffbd04[0x57] = auVar76._12_4_;
  puGpffffbd04 = puGpffffbd04 + 0x58;
  uVar28 = auVar76._8_8_;
  if ((uGpffffb0d0 & 0x10) == 0) {
    uVar27 = 0x3b808081;
  }
  else {
    uVar27 = 0x3b011b50;
  }
  ((code)FUN_0049cab0)(uVar27,param_1 + 0x44);
  auVar17._8_8_ = 0;
  auVar17._0_8_ = uVar28;
  auVar41._8_8_ = uVar56;
  auVar41._0_8_ = 0x6c0103fc01000404;
  auVar76 = _pcpyld(auVar41,auVar17 << 0x40);
  *puGpffffbd04 = auVar76._0_4_;
  puGpffffbd04[1] = auVar76._4_4_;
  puGpffffbd04[2] = auVar76._8_4_;
  puGpffffbd04[3] = auVar76._12_4_;
  puGpffffbd04 = puGpffffbd04 + 4;
  ((code)FUN_0049cbd0)(*(u32 *)(param_1 + 0x1c),*(u32 *)(param_1 + 0x3c));
  puVar3 = puGpffffbd04;
  bVar1 = *(u8 *)(param_1 + 0x28);
  auVar29._8_8_ = extraout_v0_udw;
  auVar29._0_8_ = 0x6c0303fd01000404;
  auVar18._8_8_ = 0;
  auVar18._0_8_ = auVar76._8_8_;
  auVar79 = _pcpyld(auVar29,auVar18 << 0x40);
  *puGpffffbd04 = auVar79._0_4_;
  puGpffffbd04[1] = auVar79._4_4_;
  puGpffffbd04[2] = auVar79._8_4_;
  puGpffffbd04[3] = auVar79._12_4_;
  auVar88 = _DAT_00965930;
  auVar76 = _DAT_00965910;
  uVar28 = (u32)bVar1 & 7;
  auVar68._8_8_ = auVar79._8_8_;
  if (((iGpffffbe14 == 0) || ((bVar1 & 4) != 0)) && ((iGpffffb0f8 == 0 || ((bVar1 & 4) == 0)))) {
    puGpffffbd04[4] = (u32)(DAT_00965910);
    puGpffffbd04[5] = auVar76._4_4_;
    puGpffffbd04[6] = auVar76._8_4_;
    puGpffffbd04[7] = auVar76._12_4_;
    auVar88 = _DAT_00965920;
    puGpffffbd04[8] = DAT_00965920;
    puGpffffbd04[9] = auVar88._4_4_;
    puGpffffbd04[10] = auVar88._8_4_;
    puGpffffbd04[0xb] = auVar88._12_4_;
    uVar56 = auVar88._8_8_;
  }
  else {
    uVar28 = uVar28 | 8;
    puGpffffbd04[4] = (u32)(DAT_00965930);
    puGpffffbd04[5] = auVar88._4_4_;
    puGpffffbd04[6] = auVar88._8_4_;
    puGpffffbd04[7] = auVar88._12_4_;
    auVar76 = _DAT_00965940;
    puGpffffbd04[8] = DAT_00965940;
    puGpffffbd04[9] = auVar76._4_4_;
    puGpffffbd04[10] = auVar76._8_4_;
    puGpffffbd04[0xb] = auVar76._12_4_;
    uVar56 = auVar76._8_8_;
    auVar76 = auVar88;
  }
  auVar58._8_8_ = auVar76._8_8_;
  uGpffffbe0c = 0;
  uVar39 = 0;
  if (iGpffffbdbc == 3) {
    uVar39 = 0x20;
    uGpffffbe0c = 0x20;
  }
  auVar42._8_8_ = uVar56;
  auVar42._0_8_ = uVar28;
  auVar58._0_8_ = (u32)uGpffffbe10 << 0x20 | uVar39;
  auVar76 = _pcpyld(auVar58,auVar42);
  puGpffffbd04[0xc] = auVar76._0_4_;
  puGpffffbd04[0xd] = auVar76._4_4_;
  puGpffffbd04[0xe] = auVar76._8_4_;
  puGpffffbd04[0xf] = auVar76._12_4_;
  puVar74 = puGpffffbd04 + 0x10;
  auVar43._8_8_ = auVar76._8_8_;
  if (*(int *)(param_1 + 0x40) == 0) {
    auVar69._0_8_ = (long)(int)puVar74;
    auVar69._8_8_ = auVar68._8_8_;
    *puVar74 = in_zero_lo;
    puGpffffbd04[0x11] = in_zero_hi;
    puGpffffbd04[0x12] = in_zero_udw;
    puGpffffbd04[0x13] = in_register_0000000c;
    auVar35._8_8_ = extraout_v0_udw;
    auVar35._0_8_ = 0x5000000200000000;
    auVar15._8_8_ = 0;
    auVar15._0_8_ = auVar43._8_8_;
    puGpffffbd04[0x14] = in_zero_lo;
    puGpffffbd04[0x15] = in_zero_hi;
    puGpffffbd04[0x16] = in_zero_udw;
    puGpffffbd04[0x17] = in_register_0000000c;
    auVar76 = _pcpyld(auVar35,auVar15 << 0x40);
    puGpffffbd04[0x18] = auVar76._0_4_;
    puGpffffbd04[0x19] = auVar76._4_4_;
    puGpffffbd04[0x1a] = auVar76._8_4_;
    puGpffffbd04[0x1b] = auVar76._12_4_;
    auVar60._8_8_ = auVar58._8_8_;
    auVar60._0_8_ = 0xe;
    auVar36._8_8_ = auVar76._8_8_;
    auVar55._8_8_ = auVar43._8_8_;
    auVar55._0_8_ = 0x1000000000008001;
    auVar76 = _pcpyld(auVar60,auVar55);
    puGpffffbd04[0x1c] = auVar76._0_4_;
    puGpffffbd04[0x1d] = auVar76._4_4_;
    puGpffffbd04[0x1e] = auVar76._8_4_;
    puGpffffbd04[0x1f] = auVar76._12_4_;
    auVar36._0_8_ = 0x47;
    auVar44._8_8_ = auVar76._8_8_;
    auVar44._0_8_ = uGpffffbd50;
    auVar76 = _pcpyld(auVar36,auVar44);
    puGpffffbd04[0x20] = auVar76._0_4_;
    puGpffffbd04[0x21] = auVar76._4_4_;
    puGpffffbd04[0x22] = auVar76._8_4_;
    puGpffffbd04[0x23] = auVar76._12_4_;
  }
  else {
    auVar12._8_8_ = 0;
    auVar12._0_8_ = auVar43._8_8_;
    auVar30._8_8_ = extraout_v0_udw;
    auVar30._0_8_ = 0x5000000400000000;
    auVar76 = _pcpyld(auVar30,auVar12 << 0x40);
    *puVar74 = auVar76._0_4_;
    puGpffffbd04[0x11] = auVar76._4_4_;
    puGpffffbd04[0x12] = auVar76._8_4_;
    puGpffffbd04[0x13] = auVar76._12_4_;
    auVar68._0_8_ = 0xe;
    auVar31._8_8_ = auVar76._8_8_;
    auVar59._8_8_ = auVar58._8_8_;
    auVar59._0_8_ = 0x47;
    auVar31._0_8_ = 0x1000000000008003;
    auVar76 = _pcpyld(auVar68,auVar31);
    puGpffffbd04[0x14] = auVar76._0_4_;
    puGpffffbd04[0x15] = auVar76._4_4_;
    puGpffffbd04[0x16] = auVar76._8_4_;
    puGpffffbd04[0x17] = auVar76._12_4_;
    auVar43._0_8_ = 0x14;
    auVar69._8_8_ = auVar68._8_8_;
    auVar69._0_8_ = uGpffffbd50;
    auVar32._8_8_ = auVar76._8_8_;
    auVar32._0_8_ = 8;
    auVar76 = _pcpyld(auVar59,auVar69);
    puGpffffbd04[0x18] = auVar76._0_4_;
    puGpffffbd04[0x19] = auVar76._4_4_;
    puGpffffbd04[0x1a] = auVar76._8_4_;
    puGpffffbd04[0x1b] = auVar76._12_4_;
    auVar60._8_8_ = auVar76._8_8_;
    auVar60._0_8_ = uGpffffbd70;
    auVar76 = _pcpyld(auVar43,auVar60);
    puGpffffbd04[0x1c] = auVar76._0_4_;
    puGpffffbd04[0x1d] = auVar76._4_4_;
    puGpffffbd04[0x1e] = auVar76._8_4_;
    puGpffffbd04[0x1f] = auVar76._12_4_;
    auVar44._8_8_ = auVar76._8_8_;
    auVar44._0_8_ = uGpffffbd68;
    auVar76 = _pcpyld(auVar32,auVar44);
    puGpffffbd04[0x20] = auVar76._0_4_;
    puGpffffbd04[0x21] = auVar76._4_4_;
    puGpffffbd04[0x22] = auVar76._8_4_;
    puGpffffbd04[0x23] = auVar76._12_4_;
  }
  puGpffffbd04 = puGpffffbd04 + 0x24;
  auVar46._8_8_ = auVar44._8_8_;
  *(u8 *)(param_1 + 0x2b) =
       (u8)((int)(*(u8 *)(param_1 + 0x28) & 0x20) >> 5) |
       (u8)((int)(*(u8 *)(param_1 + 0x28) & 0x18) >> 2);
  uVar56 = auVar60._8_8_;
  puVar37 = (u32 *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + (u32)*(u8 *)(param_1 + 0x2b) * 4);
  auVar46._0_8_ = (long)(int)puVar37;
  uVar5 = *puVar37;
  if (uGpffffbe08 != uVar5) {
    auVar13._8_8_ = 0;
    auVar13._0_8_ = auVar69._8_8_;
    auVar69._0_8_ = auVar13._0_8_ << 0x40;
    auVar45._0_8_ = (u32)uVar5 << 0x20 | 0x50000000;
    auVar45._8_8_ = auVar46._8_8_;
    auVar46 = _pcpyld(auVar69,auVar45);
    *puGpffffbd04 = auVar46._0_4_;
    puVar3[0x25] = auVar46._4_4_;
    puVar3[0x26] = auVar46._8_4_;
    puVar3[0x27] = auVar46._12_4_;
    puGpffffbd04 = puVar3 + 0x28;
    uGpffffbe08 = uVar5;
  }
  auVar78._8_8_ = auVar77._8_8_;
  uVar28 = auVar46._8_8_;
  auVar70._8_8_ = auVar69._8_8_;
  iVar6 = **(int **)(param_1 + 0x30);
  auVar78._0_8_ = ((long)*(int *)(*(int *)(param_1 + 4) + 0x14) | 0x2000000U) << 0x20 | 0x3000000;
  auVar70._0_8_ = (u32)*(u32 *)(iVar6 + 0x20) << 0x20 | 0x50000000;
  auVar76 = _pcpyld(auVar78,auVar70);
  *puGpffffbd04 = auVar76._0_4_;
  puGpffffbd04[1] = auVar76._4_4_;
  puGpffffbd04[2] = auVar76._8_4_;
  puGpffffbd04[3] = auVar76._12_4_;
  puGpffffbd04 = puGpffffbd04 + 4;
  do {
    DI();
    SYNC(0x10);
  } while ((Status & 0x10000) != 0);
  *(int *)(iVar6 + 0x18) = *(int *)(iVar6 + 0x18) + 1;
  EI();
  *(int *)(iVar6 + 0x1c) = *(int *)(iVar6 + 0x1c) + 1;
  if (*(int *)(iVar6 + 0x1c) == 1) {
    ((code)FUN_004d51c0)();
  }
  uVar73 = auVar76._8_8_;
  ((code)FUN_004d59d0)(0,3);
  auVar19._8_8_ = 0;
  auVar19._0_8_ = uVar28;
  auVar33._8_8_ = extraout_v0_udw_00;
  auVar33._0_8_ = 0x50000002;
  auVar14._8_8_ = 0;
  auVar14._0_8_ = auVar78._8_8_;
  auVar88 = _ppacw(auVar33,auVar19 << 0x40);
  auVar71._8_8_ = uVar73;
  auVar71._0_8_ = 0xe;
  auVar61._8_8_ = uVar56;
  auVar61._0_8_ = 0x10000002;
  auVar76 = _ppacw(auVar14 << 0x40,auVar61);
  auVar76 = _ppacw(auVar88,auVar76);
  *puGpffffbd04 = auVar76._0_4_;
  puGpffffbd04[1] = auVar76._4_4_;
  puGpffffbd04[2] = auVar76._8_4_;
  puGpffffbd04[3] = auVar76._12_4_;
  auVar62._8_8_ = uVar56;
  auVar62._0_8_ = 0x3d;
  auVar34._8_8_ = auVar76._8_8_;
  auVar34._0_8_ = 0x1000000000008001;
  auVar76 = _pcpyld(auVar71,auVar34);
  puGpffffbd04[4] = auVar76._0_4_;
  puGpffffbd04[5] = auVar76._4_4_;
  puGpffffbd04[6] = auVar76._8_4_;
  puGpffffbd04[7] = auVar76._12_4_;
  auVar47._8_8_ = uVar28;
  auVar47._0_8_ = uGpffffbd60;
  auVar76 = _pcpyld(auVar62,auVar47);
  puGpffffbd04[8] = auVar76._0_4_;
  puGpffffbd04[9] = auVar76._4_4_;
  puGpffffbd04[10] = auVar76._8_4_;
  puGpffffbd04[0xb] = auVar76._12_4_;
  puGpffffbd04 = puGpffffbd04 + 0xc;
  return 1;
}

// FUN_00473340 NONMATCHING

void FUN_00473340(u64 param_1)

{
  if (DAT_0095de38 != 0) {
    ((code)FUN_0046b8e0)();
  }
  ((code)FUN_00472270)(param_1);
  return;
}

// FUN_00473380 NONMATCHING

void FUN_00473380(u64 param_1)

{
  if (DAT_0095de38 != 0) {
    ((code)FUN_0046b8e0)();
  }
  ((code)FUN_00472970)(param_1);
  return;
}

// FUN_004733C0 NONMATCHING

u64 FUN_004733c0(int param_1,int param_2)

{
  u32 *puVar1;
  int iVar2;
  u64 extraout_v0_udw;
  Vec128 auVar3;
  Vec128 auVar4;
  u64 in_v1_udw;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uStack_4;
  
  ((code)FUN_004d59d0)(0,4);
  puVar1 = puGpffffbd04;
  auVar3._8_8_ = extraout_v0_udw;
  auVar3._0_8_ = 0x10000003;
  auVar4._8_8_ = in_v1_udw;
  auVar4._0_8_ = 0x6c0302fd01000404;
  auVar4 = _pcpyld(auVar4,auVar3);
  *puGpffffbd04 = auVar4._0_4_;
  puGpffffbd04[1] = auVar4._4_4_;
  puGpffffbd04[2] = auVar4._8_4_;
  puGpffffbd04[3] = auVar4._12_4_;
  uVar7 = *(u32 *)(param_1 + 0x1c);
  uVar5 = *(u32 *)(param_1 + 0x20);
  uVar6 = *(u32 *)(param_1 + 0x24);
  puGpffffbd04[4] = *(u32 *)(param_1 + 0x18);
  puGpffffbd04[5] = uVar7;
  puGpffffbd04[6] = uVar5;
  puGpffffbd04[7] = uVar6;
  uVar7 = *(u32 *)(param_2 + 0x1c);
  uVar5 = *(u32 *)(param_2 + 0x20);
  uVar6 = *(u32 *)(param_2 + 0x24);
  puGpffffbd04[8] = *(u32 *)(param_2 + 0x18);
  puGpffffbd04[9] = uVar7;
  puGpffffbd04[10] = uVar5;
  puGpffffbd04[0xb] = uVar6;
  iVar2 = ((code)FUN_004cb2f0)(*(u32 *)(param_2 + 4));
  uVar5 = *(u32 *)(iVar2 + 0x24);
  uVar6 = *(u32 *)(iVar2 + 0x28);
  puVar1[0xc] = *(u32 *)(iVar2 + 0x20);
  puVar1[0xd] = uVar5;
  puVar1[0xe] = uVar6;
  puVar1[0xf] = uStack_4;
  puGpffffbd04 = puVar1 + 0x10;
  return 1;
}

// FUN_004734D0 NONMATCHING

u64 FUN_004734d0(u64 param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + iGpffffba80) != 0) {
    ((code)FUN_00494d50)(**(u32 **)(*(int *)(iVar1 + 0x18) + 0x20),0);
    if (*(int *)(*(int *)(iVar1 + iGpffffba80) + 0xc) != 0) {
      ((code)FUN_00475cb0)(param_1);
      ((code)FUN_00475c20)(param_1);
      (*DAT_0096017c)(*(u32 *)(*(int *)(iVar1 + iGpffffba80) + 0xc));
    }
    (*DAT_0096017c)(*(u32 *)(iVar1 + iGpffffba80));
    *(u32 *)(iVar1 + iGpffffba80) = 0;
  }
  return param_1;
}

// FUN_00473590 NONMATCHING

u8 FUN_00473590(void)

{
  u8 bVar1;
  long lVar2;
  
  lVar2 = ((code)FUN_004ca520)(4,0x12f,0x474bb0,0x474c60);
  uGpffffba84 = (u32)lVar2;
  if (lVar2 < 0) {
    bVar1 = 0;
  }
  else {
    lVar2 = ((code)FUN_00492c30)(4,0x12f,0x4734b0,0x4734d0,0);
    uGpffffba80 = (u32)lVar2;
    bVar1 = -1 < lVar2;
  }
  return bVar1;
}

// FUN_00473600 NONMATCHING

u32 FUN_00473600(int *param_1,u32 param_2)

{
  u8 bVar1;
  u8 bVar2;
  u8 bVar3;
  u8 bVar4;
  u8 bVar5;
  u8 bVar6;
  u8 bVar7;
  u8 bVar8;
  u8 bVar9;
  int iVar10;
  long lVar11;
  u32 uVar12;
  int iVar13;
  u32 uStack_10;
  
  bVar1 = (param_2 & 1) == 1;
  bVar2 = (param_2 & 2) == 2;
  bVar3 = (param_2 & 4) == 4;
  bVar4 = (param_2 & 8) == 8;
  uStack_10 = 0;
  bVar5 = (param_2 & 0x10) == 0x10;
  bVar6 = (param_2 & 0x20) == 0x20;
  bVar7 = (param_2 & 0x40) == 0x40;
  bVar8 = (param_2 & 0x80) == 0x80;
  bVar9 = (param_2 & 0x100) == 0x100;
  iVar13 = 0;
  param_1[0x2a] = param_1[0x2a] & 0xfffffe00;
  param_1[0x28] = 0;
  param_1[0xf] = 0;
  iVar10 = DAT_007bc900;
  if (bVar1) {
    param_1[0x28] = param_1[0x28] + 1;
    param_1[0x2a] = param_1[0x2a] | 1;
    iVar13 = iVar10 * *param_1;
  }
  iVar10 = DAT_007bc904;
  if (bVar4) {
    param_1[0x28] = param_1[0x28] + 1;
    param_1[0x2a] = param_1[0x2a] | 8;
    iVar13 = iVar13 + iVar10 * *param_1;
  }
  iVar10 = DAT_007bc908;
  if (bVar5) {
    param_1[0x28] = param_1[0x28] + 1;
    param_1[0x2a] = param_1[0x2a] | 0x10;
    iVar13 = iVar13 + iVar10 * *param_1;
  }
  iVar10 = DAT_007bc90c;
  if (bVar3) {
    param_1[0x28] = param_1[0x28] + 1;
    param_1[0x2a] = param_1[0x2a] | 4;
    iVar13 = iVar13 + iVar10 * *param_1;
  }
  iVar10 = DAT_007bc910;
  if (bVar2) {
    param_1[0x28] = param_1[0x28] + 1;
    param_1[0x2a] = param_1[0x2a] | 2;
    iVar13 = iVar13 + iVar10 * *param_1;
  }
  iVar10 = DAT_007bc914;
  if (bVar7) {
    param_1[0x28] = param_1[0x28] + 1;
    param_1[0x2a] = param_1[0x2a] | 0x40;
    iVar13 = iVar13 + iVar10 * *param_1;
  }
  iVar10 = DAT_007bc918;
  if (bVar6) {
    param_1[0x28] = param_1[0x28] + 1;
    param_1[0x2a] = param_1[0x2a] | 0x20;
    iVar13 = iVar13 + iVar10 * *param_1;
  }
  iVar10 = DAT_007bc91c;
  if (bVar8) {
    param_1[0x28] = param_1[0x28] + 1;
    param_1[0x2a] = param_1[0x2a] | 0x80;
    iVar13 = iVar13 + iVar10 * *param_1;
  }
  iVar10 = DAT_007bc920;
  if (bVar9) {
    param_1[0x28] = param_1[0x28] + 1;
    param_1[0x2a] = param_1[0x2a] | 0x100;
    iVar13 = iVar13 + iVar10 * *param_1;
  }
  lVar11 = (*DAT_00960178)(iVar13 + 0x10,0x3012f);
  if (lVar11 != 0) {
    uVar12 = (int)lVar11 + 0xfU & 0xfffffff0;
    iVar13 = 0;
    if (bVar1) {
      param_1[0x15] = uVar12;
      param_1[0x16] = 0xc;
      iVar13 = DAT_007bc900 * *param_1;
    }
    if (bVar4) {
      param_1[0x17] = uVar12 + iVar13;
      param_1[0x18] = 0x40;
      iVar13 = iVar13 + DAT_007bc904 * *param_1;
    }
    if (bVar5) {
      param_1[0x19] = uVar12 + iVar13;
      param_1[0x1a] = 0xc;
      iVar13 = iVar13 + DAT_007bc908 * *param_1;
    }
    if (bVar3) {
      param_1[0x1b] = uVar12 + iVar13;
      param_1[0x1c] = 8;
      iVar13 = iVar13 + DAT_007bc90c * *param_1;
    }
    if (bVar2) {
      param_1[0x1d] = uVar12 + iVar13;
      param_1[0x1e] = 4;
      iVar13 = iVar13 + DAT_007bc910 * *param_1;
    }
    if (bVar7) {
      param_1[0x1f] = uVar12 + iVar13;
      param_1[0x20] = 0x10;
      iVar13 = iVar13 + DAT_007bc914 * *param_1;
    }
    if (bVar6) {
      param_1[0x21] = uVar12 + iVar13;
      param_1[0x22] = 4;
      iVar13 = iVar13 + DAT_007bc918 * *param_1;
    }
    if (bVar8) {
      param_1[0x23] = uVar12 + iVar13;
      param_1[0x24] = 0x10;
      iVar13 = iVar13 + DAT_007bc91c * *param_1;
    }
    if (bVar9) {
      param_1[0x25] = uVar12 + iVar13;
      param_1[0x26] = 0x20;
    }
    param_1[0x29] = 0;
    uStack_10 = 1;
    param_1[3] = (int)lVar11;
  }
  return uStack_10;
}

// FUN_00473B10 NONMATCHING

u32 FUN_00473b10(int *param_1,u32 param_2)

{
  u8 bVar1;
  u8 bVar2;
  u8 bVar3;
  u8 bVar4;
  u8 bVar5;
  u8 bVar6;
  u8 bVar7;
  u8 bVar8;
  u8 bVar9;
  int iVar10;
  u32 uVar11;
  long lVar12;
  u32 uVar13;
  u32 uStack_10;
  
  bVar1 = (param_2 & 1) == 1;
  bVar2 = (param_2 & 2) == 2;
  bVar3 = (param_2 & 4) == 4;
  bVar4 = (param_2 & 8) == 8;
  uStack_10 = 0;
  bVar5 = (param_2 & 0x10) == 0x10;
  bVar6 = (param_2 & 0x20) == 0x20;
  bVar7 = (param_2 & 0x40) == 0x40;
  bVar8 = (param_2 & 0x80) == 0x80;
  bVar9 = (param_2 & 0x100) == 0x100;
  param_1[0x2a] = param_1[0x2a] & 0xfffffe00;
  param_1[0x28] = 0;
  uVar13 = DAT_007bc900;
  uVar11 = 0;
  if (bVar1) {
    param_1[0x28] = param_1[0x28] + 1;
    param_1[0x2a] = param_1[0x2a] | 1;
    uVar11 = uVar13;
  }
  iVar10 = DAT_007bc904;
  if (bVar4) {
    param_1[0x28] = param_1[0x28] + 1;
    uVar11 = uVar11 + iVar10;
    param_1[0x2a] = param_1[0x2a] | 8;
  }
  iVar10 = DAT_007bc908;
  if (bVar5) {
    param_1[0x28] = param_1[0x28] + 1;
    uVar11 = uVar11 + iVar10;
    param_1[0x2a] = param_1[0x2a] | 0x10;
  }
  iVar10 = DAT_007bc90c;
  if (bVar3) {
    param_1[0x28] = param_1[0x28] + 1;
    uVar11 = uVar11 + iVar10;
    param_1[0x2a] = param_1[0x2a] | 4;
  }
  iVar10 = DAT_007bc910;
  if (bVar2) {
    param_1[0x28] = param_1[0x28] + 1;
    uVar11 = uVar11 + iVar10;
    param_1[0x2a] = param_1[0x2a] | 2;
  }
  iVar10 = DAT_007bc914;
  if (bVar7) {
    param_1[0x28] = param_1[0x28] + 1;
    uVar11 = uVar11 + iVar10;
    param_1[0x2a] = param_1[0x2a] | 0x40;
  }
  iVar10 = DAT_007bc918;
  if (bVar6) {
    param_1[0x28] = param_1[0x28] + 1;
    uVar11 = uVar11 + iVar10;
    param_1[0x2a] = param_1[0x2a] | 0x20;
  }
  iVar10 = DAT_007bc91c;
  if (bVar8) {
    param_1[0x28] = param_1[0x28] + 1;
    uVar11 = uVar11 + iVar10;
    param_1[0x2a] = param_1[0x2a] | 0x80;
  }
  iVar10 = DAT_007bc920;
  if (bVar9) {
    param_1[0x28] = param_1[0x28] + 1;
    uVar11 = uVar11 + iVar10;
    param_1[0x2a] = param_1[0x2a] | 0x100;
  }
  if (bVar4) {
    uVar11 = uVar11 + 0xf & 0xfffffff0;
  }
  param_1[0x29] = uVar11;
  lVar12 = (*DAT_00960178)(uVar11 * *param_1 + 0x10,0x30000);
  if (lVar12 != 0) {
    uVar11 = (int)lVar12 + 0xfU & 0xfffffff0;
    uVar13 = 0;
    if (bVar1) {
      param_1[0x15] = uVar11;
      uVar13 = DAT_007bc900;
      param_1[0x16] = param_1[0x29];
    }
    if (bVar4) {
      param_1[0x17] = uVar11 + uVar13;
      uVar13 = uVar13 + DAT_007bc904;
      param_1[0x18] = param_1[0x29];
    }
    if (bVar5) {
      param_1[0x19] = uVar11 + uVar13;
      uVar13 = uVar13 + DAT_007bc908;
      param_1[0x1a] = param_1[0x29];
    }
    if (bVar3) {
      param_1[0x1b] = uVar11 + uVar13;
      uVar13 = uVar13 + DAT_007bc90c;
      param_1[0x1c] = param_1[0x29];
    }
    if (bVar2) {
      param_1[0x1d] = uVar11 + uVar13;
      uVar13 = uVar13 + DAT_007bc910;
      param_1[0x1e] = param_1[0x29];
    }
    if (bVar7) {
      param_1[0x1f] = uVar11 + uVar13;
      uVar13 = uVar13 + DAT_007bc914;
      param_1[0x20] = param_1[0x29];
    }
    if (bVar6) {
      param_1[0x21] = uVar11 + uVar13;
      uVar13 = uVar13 + DAT_007bc918;
      param_1[0x22] = param_1[0x29];
    }
    if (bVar8) {
      param_1[0x23] = uVar11 + uVar13;
      uVar13 = uVar13 + DAT_007bc91c;
      param_1[0x24] = param_1[0x29];
    }
    if (bVar9) {
      param_1[0x25] = uVar11 + uVar13;
      param_1[0x26] = param_1[0x29];
    }
    param_1[3] = (int)lVar12;
    uStack_10 = 1;
  }
  return uStack_10;
}

// FUN_00473FB0 NONMATCHING

u32 FUN_00473fb0(u32 param_1)

{
  u8 bVar1;
  u8 bVar2;
  u8 bVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar9;
  u32 uVar10;
  u32 uVar11;
  
  uVar8 = param_1 & 0x20000;
  uVar4 = param_1 & 4;
  uVar9 = param_1 & 0x40000;
  bVar1 = (param_1 & 1) == 1;
  bVar2 = (param_1 & 8) == 8;
  bVar3 = (param_1 & 0x20) == 0x20;
  uVar5 = param_1 & 0x40;
  uVar10 = param_1 & 0x80000;
  uVar6 = param_1 & 0x80;
  uVar11 = param_1 & 0x100000;
  uVar7 = param_1 & 0x100;
  if ((bVar2) && ((param_1 & 0x8000) == 0x8000)) {
    param_1 = 0x8000;
  }
  if ((bVar3) && (uVar8 == 0x20000)) {
    param_1 = param_1 & 0x20000;
  }
  if ((uVar5 == 0x40) && (uVar9 == 0x40000)) {
    param_1 = param_1 & 0x40000;
  }
  if ((uVar6 == 0x80) && (uVar10 == 0x80000)) {
    param_1 = param_1 & 0x80000;
  }
  if ((uVar7 == 0x100) && (uVar11 == 0x100000)) {
    param_1 = param_1 & 0x100000;
  }
  if ((bVar2) && (bVar1)) {
    param_1 = param_1 & 0xfffffffe;
  }
  if ((bVar2) && (uVar4 == 4)) {
    param_1 = param_1 & 0xfffffffb;
  }
  if ((bVar2) && (bVar3)) {
    param_1 = param_1 & 0xffffffdf;
  }
  if ((!bVar2) && (!bVar1)) {
    param_1 = param_1 | 1;
  }
  if ((param_1 & 0x30000000) == 0) {
    param_1 = param_1 | 0x10000000;
  }
  return param_1;
}

// FUN_00474160 NONMATCHING

u64 FUN_00474160(u64 param_1)

{
  int iVar1;
  long lVar2;
  
  iVar1 = *(int *)((int)param_1 + DAT_007ce770);
  lVar2 = 1;
  if (0 < *(int *)(iVar1 + 4)) {
    if (*(code **)(iVar1 + 0x1c) != (code *)0x0) {
      (**(code **)(iVar1 + 0x1c))
                (param_1,iVar1 + 0x50,*(int *)(iVar1 + 4),*(u32 *)(iVar1 + 0x40));
      *(u32 *)(iVar1 + 0x40) = 0;
    }
    if (*(code **)(iVar1 + 0x20) != (code *)0x0) {
      lVar2 = (**(code **)(iVar1 + 0x20))(param_1,iVar1 + 0x50,*(u32 *)(iVar1 + 4));
    }
    if (lVar2 == 1) {
      (**(code **)(iVar1 + 0x10))(param_1);
    }
  }
  return param_1;
}

// FUN_00474210 NONMATCHING

void FUN_00474210(u64 param_1,u64 param_2,u64 param_3)

{
  u64 uVar1;
  
  uVar1 = ((code)FUN_00473fb0)(param_2);
  ((code)FUN_00474260)(param_1,uVar1,param_3,0x77b1d0);
  return;
}

// FUN_00474260 NONMATCHING

long FUN_00474260(u32 param_1,u32 param_2,u64 param_3,u64 param_4)

{
  u32 *puVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  u32 uVar9;
  u32 *puVar10;
  long lVar11;
  long lVar12;
  u32 *puVar13;
  u32 *puVar14;
  int iVar15;
  long lVar16;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u8 uStack_4;
  u8 uStack_3;
  u8 uStack_2;
  u8 uStack_1;
  
  lVar16 = 0;
  lVar11 = ((code)FUN_00491880)();
  if ((lVar11 != 0) && (lVar12 = (*DAT_00960178)(0x140,0x3012f), lVar12 != 0)) {
    iVar15 = (int)lVar11;
    puVar14 = (u32 *)lVar12;
    puVar14[4] = *(u32 *)(iVar15 + 0x48);
    **(code **)(iVar15 + 0x48) = (code)FUN_00474160;
    if (*(int *)(iVar15 + 0x48) == 0) {
      **(code **)(iVar15 + 0x48) = (code)FUN_00490860;
    }
    *puVar14 = param_1;
    puVar14[1] = 0;
    puVar14[0x2a] = (int)param_2;
    puVar14[0x11] = (int)param_3;
    puVar14[0x10] = 0xffffffff;
    puVar14[0xf] = 0;
    puVar14[3] = 0;
    *(u32 **)(iVar15 + DAT_007ce770) = puVar14;
    ((code)FUN_00521250)(puVar14 + 5,param_4,0x10);
    if ((code *)puVar14[5] == (code *)0x0) {
      if ((param_2 & 0x20000000) == 0x20000000) {
        lVar16 = ((code)FUN_00473b10)(lVar12,param_2,param_3);
      }
      else {
        lVar16 = ((code)FUN_00473600)(lVar12,param_2,param_3);
      }
    }
    else {
      uVar9 = (*(code *)puVar14[5])(puVar14 + 0x14,*puVar14,param_2,param_3);
      puVar14[3] = uVar9;
    }
    if (lVar16 == 1) {
      uVar9 = *puVar14;
    }
    else {
      if (puVar14[3] == 0) goto LAB_004745f4;
      uVar9 = *puVar14;
    }
    lVar16 = (*(code *)puVar14[6])(lVar11,puVar14 + 0x14,uVar9,param_2,param_3);
    uVar8 = DAT_0077abdc;
    uVar7 = DAT_0077abd8;
    uVar6 = DAT_0077abd4;
    uVar5 = DAT_0077abd0;
    uVar4 = DAT_0077abcc;
    uVar3 = DAT_0077abc8;
    uVar2 = DAT_0077abc4;
    uVar9 = DAT_0077abc0;
    if (lVar16 == 1) {
      puVar10 = (u32 *)0x8;
      puVar13 = &uStack_10;
      puVar1 = puVar13;
      while (puVar1 != (u32 *)0x0) {
        *(u8 *)puVar13 = 0;
        puVar13 = (u32 *)((int)puVar13 + 1);
        puVar10 = (u32 *)((int)puVar10 + -1);
        puVar1 = puVar10;
      }
      uStack_1 = DAT_007cdbc3;
      uStack_2 = DAT_007cdbc2;
      uStack_4 = DAT_007cdbc0;
      uStack_3 = DAT_007cdbc1;
      ((code)FUN_00494d50)(**(u32 **)(*(int *)(iVar15 + 0x18) + 0x20),0);
      uStack_18 = (u32)DAT_007cdbb8;
      uStack_14 = (u32)((u32)DAT_007cdbb8 >> 0x20);
      puVar14[0x30] = uStack_18;
      puVar14[0x31] = uStack_14;
      puVar14[0x32] = 0;
      puVar14[0x2e] = uStack_10;
      puVar14[0x2f] = uStack_c;
      puVar14[0x4a] = 0x3f800000;
      puVar14[0x45] = 0x3f800000;
      puVar14[0x40] = 0x3f800000;
      puVar14[0x44] = 0;
      puVar14[0x42] = 0;
      puVar14[0x41] = 0;
      puVar14[0x49] = 0;
      puVar14[0x48] = 0;
      puVar14[0x46] = 0;
      puVar14[0x4e] = 0;
      puVar14[0x4d] = 0;
      puVar14[0x4c] = 0;
      puVar14[0x43] = puVar14[0x43] | 0x20003;
      *(u8 *)(puVar14 + 0x33) = uStack_4;
      *(u8 *)((int)puVar14 + 0xcd) = uStack_3;
      *(u8 *)((int)puVar14 + 0xce) = uStack_2;
      *(u8 *)((int)puVar14 + 0xcf) = uStack_1;
      *(u8 *)(puVar14 + 0x34) = uStack_4;
      *(u8 *)((int)puVar14 + 0xd1) = uStack_3;
      *(u8 *)((int)puVar14 + 0xd2) = uStack_2;
      *(u8 *)((int)puVar14 + 0xd3) = uStack_1;
      *(u8 *)(puVar14 + 0x35) = uStack_4;
      *(u8 *)((int)puVar14 + 0xd5) = uStack_3;
      *(u8 *)((int)puVar14 + 0xd6) = uStack_2;
      *(u8 *)((int)puVar14 + 0xd7) = uStack_1;
      *(u8 *)(puVar14 + 0x36) = uStack_4;
      *(u8 *)((int)puVar14 + 0xd9) = uStack_3;
      *(u8 *)((int)puVar14 + 0xda) = uStack_2;
      *(u8 *)((int)puVar14 + 0xdb) = uStack_1;
      *(u8 *)(puVar14 + 0x37) = uStack_4;
      *(u8 *)((int)puVar14 + 0xdd) = uStack_3;
      *(u8 *)((int)puVar14 + 0xde) = uStack_2;
      *(u8 *)((int)puVar14 + 0xdf) = uStack_1;
      puVar14[0x38] = uVar9;
      puVar14[0x39] = uVar2;
      puVar14[0x3a] = uVar3;
      puVar14[0x3b] = uVar4;
      puVar14[0x3c] = uVar5;
      puVar14[0x3d] = uVar6;
      puVar14[0x3e] = uVar7;
      puVar14[0x3f] = uVar8;
      (*DAT_00960094)(10,puVar14 + 0x2b);
      (*DAT_00960094)(0xb,puVar14 + 0x2c);
      (*DAT_00960094)(0xc,puVar14 + 0x2d);
      return lVar11;
    }
  }
LAB_004745f4:
  ((code)FUN_00491a80)(lVar11);
  return 0;
}



// FUN_00474630 thunk_FUN_00491a80 NONMATCHING

u32 thunk_FUN_00491a80(u64 param_1)

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
  (*DAT_0096018c)(*(u32 *)((int)(u8 *)DAT_00960070 + iRam007ce820),param_1);
  return 1;
}

// FUN_00474640 NONMATCHING

u32 FUN_00474640(int param_1,int *param_2,u32 param_3,u32 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + DAT_007ce770);
  if ((*(u32 *)(iVar1 + 0xa8) & param_3) == 0) {
    *param_2 = 0;
    param_2[1] = 0;
    return 0;
  }
  if (param_3 == 0x100) {
    iVar2 = *(int *)(iVar1 + 0x98);
    *param_2 = *(int *)(iVar1 + 0x94);
    param_2[1] = iVar2;
  }
  else if (param_3 == 0x80) {
    iVar2 = *(int *)(iVar1 + 0x90);
    *param_2 = *(int *)(iVar1 + 0x8c);
    param_2[1] = iVar2;
  }
  else if (param_3 == 0x40) {
    iVar2 = *(int *)(iVar1 + 0x80);
    *param_2 = *(int *)(iVar1 + 0x7c);
    param_2[1] = iVar2;
  }
  else if (param_3 == 0x20) {
    iVar2 = *(int *)(iVar1 + 0x88);
    *param_2 = *(int *)(iVar1 + 0x84);
    param_2[1] = iVar2;
  }
  else if (param_3 == 0x10) {
    iVar2 = *(int *)(iVar1 + 0x68);
    *param_2 = *(int *)(iVar1 + 100);
    param_2[1] = iVar2;
  }
  else if (param_3 == 8) {
    iVar2 = *(int *)(iVar1 + 0x60);
    *param_2 = *(int *)(iVar1 + 0x5c);
    param_2[1] = iVar2;
  }
  else if (param_3 == 4) {
    iVar2 = *(int *)(iVar1 + 0x70);
    *param_2 = *(int *)(iVar1 + 0x6c);
    param_2[1] = iVar2;
  }
  else if (param_3 == 2) {
    iVar2 = *(int *)(iVar1 + 0x78);
    *param_2 = *(int *)(iVar1 + 0x74);
    param_2[1] = iVar2;
  }
  else {
    if (param_3 != 1) {
      iVar1 = *(int *)(iVar1 + 0xa4);
      goto LAB_00474788;
    }
    iVar2 = *(int *)(iVar1 + 0x58);
    *param_2 = *(int *)(iVar1 + 0x54);
    param_2[1] = iVar2;
  }
  iVar1 = *(int *)(iVar1 + 0xa4);
LAB_00474788:
  if (iVar1 != 0) {
    param_2[1] = iVar1;
  }
  if ((*param_2 != 0) && ((param_4 & 0x40000000) == 0x40000000)) {
    *(u32 *)(*(int *)(param_1 + DAT_007ce770) + 0x3c) =
         *(u32 *)(*(int *)(param_1 + DAT_007ce770) + 0x3c) | param_4 | param_3;
  }
  return 1;
}

// FUN_004747F0 NONMATCHING

u32 FUN_004747f0(int *param_1)

{
  u32 *puVar1;
  
  puVar1 = (u32 *)((u8 *)param_1 + iGpffffba80);
  puVar1 = (u32 *)*puVar1;
  puVar1[0x10] = puVar1[0x10] | puVar1[0xf];
  puVar1[0xf] = 0;
  return (u32)param_1;
}

// FUN_00474820 NONMATCHING

u64 FUN_00474820(int param_1,long param_2,u32 param_3)

{
  int iVar1;
  int iVar2;
  Vec128 in_zero_qw;
  u64 in_v0_udw;
  Vec128 auVar3;
  
  iVar1 = *(int *)(param_1 + DAT_007ce770);
  iVar2 = *(int *)(iVar1 + 0x9c);
  if (param_2 == 2) {
    auVar3._8_8_ = in_v0_udw;
    auVar3._0_8_ = 0xffffffffffff0000;
    auVar3 = _pcpyld(in_zero_qw,auVar3);
    *(u32 *)(iVar2 + 200) = *(u32 *)(iVar2 + 200) & auVar3._0_8_;
    *(u32 *)(iVar2 + 200) = *(u32 *)(iVar2 + 200) | param_3 & 0xffff;
  }
  else {
    if (param_2 != 1) {
      return 0;
    }
    *(u32 *)(iVar2 + 0xb8) = param_3 & 0xff | (param_3 & 0xff000000) << 8;
    *(u32 *)(iVar1 + 0x40) = *(u32 *)(iVar1 + 0x40) & 0xefffffff;
  }
  return 1;
}

// FUN_004748C0 NONMATCHING

u64 FUN_004748c0(int param_1,long param_2)

{
  int iVar1;
  int iVar2;
  Vec128 in_zero_qw;
  long lVar3;
  u64 in_v0_udw;
  u64 extraout_v0_udw;
  Vec128 auVar4;
  Vec128 auVar5;
  u32 uVar6;
  
  iVar1 = *(int *)(param_1 + 0x4c);
  uVar6 = *(u32 *)(iVar1 + 200) | DAT_007cea40 & 0x70000;
  if (param_2 == 0) {
    auVar5._8_8_ = in_v0_udw;
    auVar5._0_8_ = 0xfffffffffffffffe;
    *(u64 *)(iVar1 + 0xd0) = 0;
    auVar5 = _pcpyld(in_zero_qw,auVar5);
    uVar6 = uVar6 & auVar5._0_8_;
  }
  else {
    iVar2 = *(int *)param_2;
    lVar3 = ((code)FUN_004f1020)(iVar2,1);
    if (lVar3 != 0) {
      ((code)FUN_004f1e40)(iVar2,iVar1 + 0xd0,(char)((int *)param_2)[0x14]);
      if ((*(u8 *)(iVar2 + 0x23) & 0xf) == 6) {
        auVar4._8_8_ = extraout_v0_udw;
        auVar4._0_8_ = 0xfffffffffffffffe;
        auVar5 = _pcpyld(in_zero_qw,auVar4);
        uVar6 = uVar6 & auVar5._0_8_;
      }
      else {
        uVar6 = uVar6 | 1;
      }
      if (*(int *)(iVar2 + 0x14) < 9) {
        DAT_007ceabc = 0xffffffff;
      }
    }
  }
  *(u32 *)(iVar1 + 200) = uVar6;
  return 1;
}

// FUN_004749A0 NONMATCHING

u64 FUN_004749a0(int param_1,long param_2)

{
  Vec128 in_zero_qw;
  u64 in_v0_udw;
  Vec128 auVar1;
  Vec128 auVar2;
  Vec128 auVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  
  if (param_2 != 0) {
    uVar5 = *(u32 *)((int)param_2 + 0x50);
    uVar4 = (uVar5 & 0xf00) >> 8;
    if ((uVar4 == 4) || (uVar4 == 2)) {
      return 0;
    }
    auVar2._8_8_ = in_v0_udw;
    auVar2._0_8_ = 3;
    if (uVar4 == 3) {
      uVar6 = 1;
    }
    else {
      if (uVar4 != 1) {
        return 0;
      }
      auVar1._8_8_ = in_v0_udw;
      auVar1._0_8_ = 0xfffffffffffffffc;
      auVar2 = _pcpyld(in_zero_qw,auVar1);
      uVar6 = 0;
    }
    auVar3._8_8_ = auVar2._8_8_;
    uVar5 = (uVar5 & 0xf000) >> 0xc;
    if ((uVar5 == 4) || (uVar5 == 2)) {
      return 0;
    }
    if (uVar5 == 3) {
      uVar6 = uVar6 | 4;
    }
    else {
      if (uVar5 != 1) {
        return 0;
      }
      auVar3._0_8_ = 0xfffffffffffffff3;
      auVar2 = _pcpyld(in_zero_qw,auVar3);
      uVar6 = uVar6 & auVar2._0_8_;
    }
    *(u32 *)(*(int *)(param_1 + 0x4c) + 0xc0) = uVar6;
  }
  return 1;
}

// FUN_00474A80 NONMATCHING

u32 FUN_00474a80(int param_1)

{
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  int iVar4;
  int iVar5;
  
  switch(*(u32 *)(param_1 + 0x5c)) {
  default:
    iVar5 = 2;
    break;
  case 1:
    iVar5 = 0;
    break;
  case 2:
    iVar5 = 1;
    break;
  case 5:
    iVar5 = 2;
    break;
  case 6:
    iVar5 = 3;
    break;
  case 7:
    iVar5 = 4;
    break;
  case 8:
    iVar5 = 5;
  }
  switch(*(u32 *)(param_1 + 0x60)) {
  default:
    iVar4 = 3;
    break;
  case 1:
    iVar4 = 0;
    break;
  case 2:
    iVar4 = 1;
    break;
  case 5:
    iVar4 = 2;
    break;
  case 6:
    iVar4 = 3;
    break;
  case 7:
    iVar4 = 4;
    break;
  case 8:
    iVar4 = 5;
  }
  uVar1 = *(u32 *)(iVar5 * 4 + iVar4 * 0x18 + 0x77b140);
  uVar3 = (u32)uVar1;
  if (uVar3 == 0xffffffff) {
    uVar2 = 0;
  }
  else {
    if ((iVar5 == 1) && (iVar4 == 1)) {
      uVar3 = CONCAT44(0x80,uVar1);
    }
    *(u32 *)(*(int *)(param_1 + 0x4c) + 0xb8) = uVar3;
    uVar2 = 1;
  }
  return uVar2;
}

// FUN_00474BB0 NONMATCHING

u64 FUN_00474bb0(u64 param_1)

{
  u32 uVar1;
  long lVar2;
  u32 *puVar3;
  
  lVar2 = (*DAT_00960178)(0x18,0x4012f);
  if (lVar2 == 0) {
    param_1 = 0;
  }
  else {
    puVar3 = (u32 *)lVar2;
    *(u32 **)((int)(u8 *)DAT_00960070 + DAT_007ce774) = puVar3;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0;
    puVar3[5] = 0;
    ((code)FUN_0047a3d0)(lVar2);
    ((code)FUN_00479030)(lVar2);
    uVar1 = ((code)FUN_0047ab70)();
    *puVar3 = uVar1;
    uVar1 = ((code)FUN_0047b1a0)();
    puVar3[5] = uVar1;
  }
  return param_1;
}

// FUN_00474C60 NONMATCHING

u64 FUN_00474c60(u64 param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)((int)(u8 *)DAT_00960070 + DAT_007ce774);
  if (piVar1 != (int *)0x0) {
    if (piVar1[2] != 0) {
      ((code)FUN_004f3010)();
    }
    if (piVar1[1] != 0) {
      ((code)FUN_004f3010)();
    }
    if (piVar1[4] != 0) {
      ((code)FUN_004f3010)();
    }
    if (piVar1[3] != 0) {
      ((code)FUN_004f3010)();
    }
    if (piVar1[5] != 0) {
      ((code)FUN_004f3010)();
    }
    if (*piVar1 != 0) {
      ((code)FUN_004f3010)();
    }
    (*DAT_0096017c)(piVar1);
  }
  return param_1;
}

// FUN_00474D30 NONMATCHING

void FUN_00474d30(int param_1,int param_2)

{
  u8 bVar1;
  u32 *puVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  long lVar7;
  int iVar8;
  u64 in_v1_udw;
  Vec128 auVar9;
  u32 in_a0_udw;
  u32 in_register_0000004c;
  long lVar10;
  long lVar11;
  long lVar12;
  long lVar13;
  long lVar14;
  u32 uVar15;
  u32 uVar16;
  u32 uVar17;
  u32 uVar18;
  u32 uVar19;
  u32 uVar20;
  u32 uVar21;
  u32 uVar22;
  u32 uVar23;
  u32 uVar24;
  long lVar25;
  u32 uVar26;
  u32 uVar27;
  u8 in_s2_qw [16];
  Vec128 auVar28;
  Vec128 auVar29;
  Vec128 auVar30;
  u32 in_s3_udw;
  u32 in_register_0000013c;
  long lVar31;
  u32 in_s4_udw;
  u32 in_register_0000014c;
  u32 *puVar32;
  long *plVar33;
  long *plVar34;
  u8 in_s5_qw [16];
  Vec128 auVar35;
  Vec128 auVar36;
  u8 in_s6_qw [16];
  Vec128 auVar37;
  Vec128 auVar38;
  Vec128 auVar39;
  Vec128 auVar40;
  
  iVar8 = param_2 * 0x20 + param_1;
  puVar2 = *(u32 **)(iVar8 + 4);
  iVar3 = *(int *)(param_1 + 0x124);
  (*(u64*)((u8*)&auVar28 + 8)) = (*(u64*)((u8*)&in_s2_qw + 8));
  uVar21 = *(u32 *)(param_1 + 0x40);
  uVar22 = *(u32 *)(param_1 + 0x44);
  lVar31 = *(long *)(param_1 + 0x40);
  uVar23 = *(u32 *)(param_1 + 0x48);
  uVar24 = *(u32 *)(param_1 + 0x4c);
  lVar6 = *(long *)(param_1 + 0x50);
  uVar19 = *(u32 *)(param_1 + 0x58);
  uVar20 = *(u32 *)(param_1 + 0x5c);
  lVar5 = *(long *)(param_1 + 0x60);
  uVar17 = *(u32 *)(param_1 + 0x68);
  uVar18 = *(u32 *)(param_1 + 0x6c);
  lVar7 = *(long *)(param_1 + 0x70);
  uVar15 = *(u32 *)(param_1 + 0x78);
  uVar16 = *(u32 *)(param_1 + 0x7c);
  lVar25 = *(long *)(param_1 + 0x80);
  uVar26 = *(u32 *)(param_1 + 0x88);
  uVar27 = *(u32 *)(param_1 + 0x8c);
  (*(u64*)((u8*)&auVar35 + 8)) = (*(u64*)((u8*)&in_s5_qw + 8));
  lVar14 = *(long *)(param_1 + 0x90);
  lVar13 = *(long *)(param_1 + 0x98);
  lVar12 = *(long *)(param_1 + 0xa0);
  lVar11 = *(long *)(param_1 + 0xa8);
  lVar10 = *(long *)(param_1 + 0xb0);
  iVar4 = *(int *)(*(int *)(param_1 + 0xfc) + 0x18);
  (*(u64*)((u8*)&auVar37 + 8)) = (*(u64*)((u8*)&in_s6_qw + 8));
  auVar37._0_8_ = 0x3000000001000101;
  auVar39._8_8_ = in_v1_udw;
  auVar39._0_8_ = 0x1700000000000000;
  auVar35._0_8_ = 0x10000002;
  auVar28._0_8_ =
       (u32)((*(int *)(param_1 + 0x130) + *(int *)(iVar8 + 4) + iVar3 * *(int *)(param_1 + 0x128))
              - 0x10) << 0x20 | 0x10000000;
  auVar36._8_4_ = in_s3_udw;
  auVar36._0_8_ = 0x1400000000000000;
  auVar36._12_4_ = in_register_0000013c;
  auVar40 = _pcpyld(auVar36,auVar28);
  auVar39 = _pcpyld(auVar39,auVar28);
  auVar9._8_8_ = in_v1_udw;
  auVar9._0_8_ = 0x1100000000000000;
  auVar29._8_8_ = auVar28._8_8_;
  auVar29._0_8_ = 0x4b0000004b000000;
  auVar36 = _pcpyld(auVar37,auVar35);
  *puVar2 = auVar36._0_4_;
  puVar2[1] = auVar36._4_4_;
  puVar2[2] = auVar36._8_4_;
  puVar2[3] = auVar36._12_4_;
  auVar36 = _pcpyld(auVar29,auVar29);
  puVar2[4] = auVar36._0_4_;
  puVar2[5] = auVar36._4_4_;
  puVar2[6] = auVar36._8_4_;
  puVar2[7] = auVar36._12_4_;
  auVar30._8_8_ = auVar36._8_8_;
  auVar30._0_8_ = lVar5 + lVar12;
  puVar32 = puVar2 + 0x1c;
  auVar38._0_8_ = (u32)*(u32 *)(*(int *)(param_1 + 0xfc) + 0x10) | 0x4000000;
  auVar38._8_8_ = auVar37._8_8_;
  auVar36 = _pcpyld(auVar9,auVar38);
  puVar2[8] = auVar36._0_4_;
  puVar2[9] = auVar36._4_4_;
  puVar2[10] = auVar36._8_4_;
  puVar2[0xb] = auVar36._12_4_;
  puVar2[0xc] = uVar21;
  puVar2[0xd] = uVar22;
  puVar2[0xe] = uVar23;
  puVar2[0xf] = uVar24;
  puVar2[0x10] = (int)lVar6;
  puVar2[0x11] = (int)((u32)lVar6 >> 0x20);
  puVar2[0x12] = uVar19;
  puVar2[0x13] = uVar20;
  puVar2[0x14] = (int)lVar5;
  puVar2[0x15] = (int)((u32)lVar5 >> 0x20);
  puVar2[0x16] = uVar17;
  puVar2[0x17] = uVar18;
  puVar2[0x18] = (int)lVar7;
  puVar2[0x19] = (int)((u32)lVar7 >> 0x20);
  puVar2[0x1a] = uVar15;
  puVar2[0x1b] = uVar16;
  if (iVar4 == 5) {
    *puVar32 = (int)lVar25;
    puVar2[0x1d] = (int)((u32)lVar25 >> 0x20);
    puVar2[0x1e] = uVar26;
    puVar2[0x1f] = uVar27;
    puVar32 = puVar2 + 0x20;
    lVar25 = lVar25 + lVar10;
  }
  *puVar32 = auVar40._0_4_;
  puVar32[1] = auVar40._4_4_;
  puVar32[2] = auVar40._8_4_;
  puVar32[3] = auVar40._12_4_;
  iVar8 = iVar3 + -2;
  plVar33 = (long *)(puVar32 + 4);
  if (iVar3 != 1) {
    do {
      lVar7 = lVar7 + lVar11;
      lVar6 = lVar6 + lVar13;
      lVar31 = lVar31 + lVar14;
      *plVar33 = lVar31;
      *(u32 *)(plVar33 + 1) = in_s4_udw;
      *(u32 *)((int)plVar33 + 0xc) = in_register_0000014c;
      plVar33[2] = lVar6;
      *(u32 *)(plVar33 + 3) = in_s3_udw;
      *(u32 *)((int)plVar33 + 0x1c) = in_register_0000013c;
      *(int *)(plVar33 + 4) = auVar30._0_4_;
      *(int *)((int)plVar33 + 0x24) = auVar30._4_4_;
      *(int *)(plVar33 + 5) = auVar30._8_4_;
      *(int *)((int)plVar33 + 0x2c) = auVar30._12_4_;
      plVar33[6] = lVar7;
      *(u32 *)(plVar33 + 7) = in_a0_udw;
      *(u32 *)((int)plVar33 + 0x3c) = in_register_0000004c;
      auVar30._0_8_ = auVar30._0_8_ + lVar12;
      plVar34 = plVar33 + 8;
      if (iVar4 == 5) {
        *(int *)plVar34 = (int)lVar25;
        *(int *)((int)plVar33 + 0x44) = (int)((u32)lVar25 >> 0x20);
        *(u32 *)(plVar33 + 9) = uVar26;
        *(u32 *)((int)plVar33 + 0x4c) = uVar27;
        plVar34 = plVar33 + 10;
        lVar25 = lVar25 + lVar10;
      }
      *(int *)plVar34 = auVar39._0_4_;
      *(int *)((int)plVar34 + 4) = auVar39._4_4_;
      *(int *)(plVar34 + 1) = auVar39._8_4_;
      *(int *)((int)plVar34 + 0xc) = auVar39._12_4_;
      plVar33 = plVar34 + 2;
      bVar1 = iVar8 != 0;
      iVar8 = iVar8 + -1;
    } while (bVar1);
  }
  auVar40._8_4_ = in_a0_udw;
  auVar40._0_8_ = 0x60000000;
  auVar40._12_4_ = in_register_0000004c;
  auVar36 = _pcpyld(auVar9,auVar40);
  *(int *)plVar33 = auVar36._0_4_;
  *(int *)((int)plVar33 + 4) = auVar36._4_4_;
  *(int *)(plVar33 + 1) = auVar36._8_4_;
  *(int *)((int)plVar33 + 0xc) = auVar36._12_4_;
  return;
}

// FUN_00474F20 NONMATCHING

void FUN_00474f20(int param_1,u32 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  u32 *puVar4;
  int iVar5;
  u32 uVar6;
  int iVar7;
  int iVar8;
  u32 *puVar9;
  u32 uVar10;
  u32 *puVar11;
  int *piVar12;
  
  piVar1 = *(int **)(param_1 + DAT_007ce770);
  puVar11 = (u32 *)piVar1[0x27];
  uVar10 = piVar1[0x2a];
  piVar12 = piVar1 + 0x14;
  if (puVar11[0x36] == 0) {
    if ((uVar10 & 0x20000000) == 0) {
      iVar8 = *piVar1;
      if ((uVar10 & 1) != 0) {
        piVar1[0x15] = param_2;
        param_2 = param_2 + iVar8 * 0x10 + 0xf & 0xfffffff0;
      }
      if ((uVar10 & 8) != 0) {
        piVar1[0x17] = param_2;
        param_2 = param_2 + iVar8 * DAT_007bc904 + 0xf & 0xfffffff0;
      }
      if ((uVar10 & 0x10) != 0) {
        piVar1[0x19] = param_2;
        param_2 = param_2 + iVar8 * DAT_007bc908 + 0xf & 0xfffffff0;
      }
      if ((uVar10 & 4) != 0) {
        piVar1[0x1b] = param_2;
        param_2 = param_2 + iVar8 * DAT_007bc90c + 0x4f & 0xfffffff0;
      }
      if ((uVar10 & 2) != 0) {
        piVar1[0x1d] = param_2;
        param_2 = param_2 + iVar8 * DAT_007bc910 + 0x4f & 0xfffffff0;
      }
      if ((uVar10 & 0x40) != 0) {
        piVar1[0x1f] = param_2;
        param_2 = param_2 + iVar8 * DAT_007bc914 + 0xf & 0xfffffff0;
      }
      if ((uVar10 & 0x20) != 0) {
        piVar1[0x21] = param_2;
        param_2 = param_2 + iVar8 * DAT_007bc918 + 0xf & 0xfffffff0;
      }
      if ((uVar10 & 0x80) != 0) {
        piVar1[0x23] = param_2;
        param_2 = param_2 + iVar8 * DAT_007bc91c + 0xf & 0xfffffff0;
      }
      if ((uVar10 & 0x100) != 0) {
        piVar1[0x25] = param_2;
      }
    }
    else {
      if ((uVar10 & 1) != 0) {
        piVar1[0x15] = param_2;
        param_2 = param_2 + 0x10;
      }
      if ((uVar10 & 8) != 0) {
        piVar1[0x17] = param_2;
        param_2 = DAT_007bc904 + param_2;
      }
      if ((uVar10 & 0x10) != 0) {
        piVar1[0x19] = param_2;
        param_2 = DAT_007bc908 + param_2;
      }
      if ((uVar10 & 4) != 0) {
        piVar1[0x1b] = param_2;
        param_2 = DAT_007bc90c + param_2;
      }
      if ((uVar10 & 2) != 0) {
        piVar1[0x1d] = param_2;
        param_2 = DAT_007bc910 + param_2;
      }
      if ((uVar10 & 0x40) != 0) {
        piVar1[0x1f] = param_2;
        param_2 = DAT_007bc914 + param_2;
      }
      if ((uVar10 & 0x20) != 0) {
        piVar1[0x21] = param_2;
        param_2 = DAT_007bc918 + param_2;
      }
      if ((uVar10 & 0x80) != 0) {
        piVar1[0x23] = param_2;
        param_2 = DAT_007bc91c + param_2;
      }
      if ((uVar10 & 0x100) != 0) {
        piVar1[0x25] = param_2;
      }
    }
  }
  else {
    uVar10 = 0;
    iVar8 = 0;
    puVar9 = puVar11;
    do {
      *puVar9 = 0x50000000;
      puVar9[1] = param_2;
      puVar9[2] = 0x3000000;
      puVar9[3] = *(u32 *)(puVar11[0x3f] + 0x14) | 0x2000000;
      puVar9[4] = 0;
      puVar9[5] = 0;
      iVar3 = puVar11[0x4a] + param_2 + puVar11[0x4c] + -0x20;
      puVar9[6] = iVar3;
      puVar9[7] = iVar3;
      iVar3 = puVar11[0x3f];
      param_2 = param_2 + puVar11[0x4c] + puVar11[0x49] * puVar11[0x4a];
      uVar6 = 0;
      if (*(int *)(iVar3 + 0x18) != 0) {
        iVar5 = 0;
        puVar4 = puVar11;
        do {
          iVar2 = *(int *)(iVar3 + iVar5 + 0x24);
          *(u32 *)((int)puVar11 + iVar2 * 4 + iVar8 + 0x140) = param_2;
          puVar4[0x11] = param_2;
          if (puVar11[iVar2 + 0x40] == 0) {
            iVar3 = puVar11[0x3f];
            iVar7 = *(int *)(iVar3 + iVar5 + 0x28) * puVar11[0x49] * 0x10;
          }
          else {
            iVar3 = puVar11[0x3f];
            iVar7 = *(int *)(iVar3 + iVar5 + 0x2c) * 0x10;
          }
          param_2 = param_2 + iVar7;
          if ((iVar2 - 3U < 2) && (puVar11[iVar2 + 0x40] == 0)) {
            param_2 = param_2 + 0x40;
          }
          uVar6 = uVar6 + 1;
          iVar5 = iVar5 + 0x18;
          puVar4 = puVar4 + 4;
        } while (uVar6 < *(u32 *)(iVar3 + 0x18));
      }
      ((code)FUN_00474d30)(puVar11,uVar10);
      uVar10 = uVar10 + 1;
      puVar9 = puVar9 + 8;
      iVar8 = iVar8 + 0x24;
    } while (uVar10 <= (u32)puVar11[0x3a]);
    uVar10 = 0;
    do {
      uVar10 = uVar10 + 3;
      piVar12[1] = puVar11[0x50];
      piVar12[3] = puVar11[0x51];
      piVar12[5] = puVar11[0x52];
      puVar11 = puVar11 + 3;
      piVar12 = piVar12 + 6;
    } while (uVar10 < 9);
  }
  return;
}

// FUN_004753D0 NONMATCHING

int FUN_004753d0(int param_1,u32 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_2 & 1) != 0) {
    iVar1 = param_1 * 0x10;
  }
  if ((param_2 & 8) != 0) {
    iVar1 = iVar1 + (param_1 * DAT_007bc904 + 0xfU & 0xfffffff0);
  }
  if ((param_2 & 0x10) != 0) {
    iVar1 = iVar1 + (param_1 * DAT_007bc908 + 0xfU & 0xfffffff0);
  }
  if ((param_2 & 4) != 0) {
    iVar1 = iVar1 + (param_1 * DAT_007bc90c + 0x4fU & 0xfffffff0);
  }
  if ((param_2 & 2) != 0) {
    iVar1 = iVar1 + (param_1 * DAT_007bc910 + 0x4fU & 0xfffffff0);
  }
  if ((param_2 & 0x40) != 0) {
    iVar1 = iVar1 + (param_1 * DAT_007bc914 + 0xfU & 0xfffffff0);
  }
  if ((param_2 & 0x20) != 0) {
    iVar1 = iVar1 + (param_1 * DAT_007bc918 + 0xfU & 0xfffffff0);
  }
  if ((param_2 & 0x80) != 0) {
    iVar1 = iVar1 + (param_1 * DAT_007bc91c + 0xfU & 0xfffffff0);
  }
  if ((param_2 & 0x100) != 0) {
    iVar1 = iVar1 + (param_1 * DAT_007bc920 + 0xfU & 0xfffffff0);
  }
  return iVar1;
}

// FUN_00475540 NONMATCHING

int FUN_00475540(int param_1,u64 param_2,u64 param_3,u32 param_4)

{
  u32 uVar1;
  u8 uVar2;
  u32 uVar3;
  int iVar4;
  u32 uVar5;
  int iVar6;
  int iVar7;
  u32 uVar8;
  u32 uVar9;
  u32 uVar10;
  u32 uVar11;
  u32 uVar12;
  u32 *puVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  u32 uVar17;
  int iVar18;
  int iVar19;
  int aiStack_30 [4];
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  
  iVar18 = 0;
  uVar1 = *(u32 *)(param_1 + 0x58);
  uVar12 = uVar1 & 4;
  uVar11 = uVar1 & 2;
  uVar10 = uVar1 & 0x40;
  uVar5 = uVar1 & 0x20;
  uVar9 = uVar1 & 0x80;
  uVar8 = uVar1 & 0x100;
  *(u32 *)(param_1 + 0x50) =
       (u32)(uVar8 == 0x100) +
       (u32)(uVar9 == 0x80) +
       (u32)(uVar5 == 0x20) +
       (u32)(uVar10 == 0x40) +
       (u32)(uVar11 == 2) +
       (u32)(uVar12 == 4) +
       (u32)((uVar1 & 0x10) == 0x10) + (u32)((uVar1 & 1) == 1) + (u32)((uVar1 & 8) == 8);
  if (((param_4 & 4) == 0) && ((uVar1 & 0xeee1fe18) == 0)) {
    iVar18 = 1;
  }
  uVar17 = 2;
  if ((param_4 & 2) == 0) {
    uVar17 = 1;
  }
  if ((param_4 & 0x10) == 0) {
    if (iVar18 == 0) {
      if ((uVar1 & 0x20000000) == 0) {
        *(u32 *)(param_1 + 0x54) = 0;
        uVar5 = 0;
        puVar13 = (u32 *)((u8 *)DAT_0077abe0);
        iVar6 = param_1;
        do {
          uVar5 = uVar5 + 3;
          *(u32 *)(iVar6 + 8) = *puVar13;
          *(u32 *)(iVar6 + 0x10) = puVar13[1];
          *(u32 *)(iVar6 + 0x18) = puVar13[2];
          puVar13 = puVar13 + 3;
          iVar6 = iVar6 + 0x18;
        } while (uVar5 < 9);
        iVar6 = ((code)FUN_004753d0)(param_2,uVar1);
      }
      else {
        uVar3 = 0;
        if ((uVar1 & 1) != 0) {
          uVar3 = 0x10;
        }
        if ((uVar1 & 8) != 0) {
          uVar3 = uVar3 + DAT_007bc904;
        }
        if ((uVar1 & 0x10) != 0) {
          uVar3 = uVar3 + DAT_007bc908;
        }
        if (uVar12 != 0) {
          uVar3 = uVar3 + DAT_007bc90c;
        }
        if (uVar11 != 0) {
          uVar3 = uVar3 + DAT_007bc910;
        }
        if (uVar10 != 0) {
          uVar3 = uVar3 + DAT_007bc914;
        }
        if (uVar5 != 0) {
          uVar3 = uVar3 + DAT_007bc918;
        }
        if (uVar9 != 0) {
          uVar3 = uVar3 + DAT_007bc91c;
        }
        if (uVar8 != 0) {
          uVar3 = uVar3 + DAT_007bc920;
        }
        if ((uVar1 & 9) != 0) {
          uVar3 = uVar3 + 0xf & 0xfffffff0;
        }
        *(u32 *)(param_1 + 0x54) = uVar3;
        uVar1 = 0;
        iVar6 = param_1;
        do {
          *(u32 *)(iVar6 + 8) = uVar3;
          uVar1 = uVar1 + 3;
          *(u32 *)(iVar6 + 0x10) = uVar3;
          *(u32 *)(iVar6 + 0x18) = uVar3;
          iVar6 = iVar6 + 0x18;
        } while (uVar1 < 9);
        iVar6 = (int)param_2 * uVar3;
      }
      if ((param_4 & 8) == 0) {
        iVar6 = (*DAT_00960178)(iVar6 + 400,0x3012f);
      }
      else {
        iVar6 = (*DAT_00960178)(400,0x3012f);
      }
      ((code)FUN_00521408)(iVar6,0,400);
    }
    else {
      *(u32 *)(param_1 + 0x54) = 0;
      uVar3 = 0;
      puVar13 = (u32 *)((u8 *)DAT_0077abe0);
      iVar6 = param_1;
      do {
        uVar3 = uVar3 + 3;
        *(u32 *)(iVar6 + 8) = *puVar13;
        *(u32 *)(iVar6 + 0x10) = puVar13[1];
        *(u32 *)(iVar6 + 0x18) = puVar13[2];
        puVar13 = puVar13 + 3;
        iVar6 = iVar6 + 0x18;
      } while (uVar3 < 9);
      uVar3 = (u32)((uVar1 & 0x40040) != 0);
      if ((uVar1 & 0x100100) != 0) {
        uVar3 = uVar3 + 2;
      }
      if ((uVar1 & 0x20020) != 0) {
        uVar3 = uVar3 + 4;
      }
      aiStack_30[0] = 0;
      iVar15 = 0;
      iVar7 = uVar3 * 0xa0;
      iVar16 = iVar7 + 0x77ac40;
      iVar14 = 0;
      uStack_1c = uVar10 != 0 ^ 1;
      uStack_18 = uVar5 != 0 ^ 1;
      uVar1 = *(u32 *)((u8 *)DAT_0077ac58 + iVar7);
      iVar19 = ((int)param_2 + -1) / *(int *)((u8 *)DAT_0077ac50 + iVar7) + 1;
      uStack_14 = uVar9 != 0 ^ 1;
      uStack_10 = uVar8 != 0 ^ 1;
      aiStack_30[3] = uVar12 != 0 ^ 1;
      uStack_20 = uVar11 != 0 ^ 1;
      iVar4 = (uVar1 + 1) * 0x10;
      if (uVar12 != 0) {
        iVar14 = 0x40;
      }
      if (uVar11 != 0) {
        iVar14 = iVar14 + 0x40;
      }
      uVar5 = 0;
      iVar6 = iVar16;
      if (uVar1 != 0) {
        do {
          if (aiStack_30[*(int *)(iVar6 + 0x24)] == 0) {
            iVar15 = iVar15 + *(int *)(iVar6 + 0x28) * 0x10;
          }
          else {
            iVar14 = iVar14 + *(int *)(iVar6 + 0x2c) * 0x10;
          }
          uVar5 = uVar5 + 1;
          iVar6 = iVar6 + 0x18;
        } while (uVar5 < uVar1);
      }
      if ((param_4 & 8) == 0) {
        iVar6 = (*DAT_00960178)(uVar17 * (iVar14 + 0x40 + iVar19 * (iVar4 + iVar15)) + 400,0x3012f);
      }
      else {
        iVar6 = (*DAT_00960178)(400,0x3012f);
      }
      if (iVar6 == 0) {
        return 0;
      }
      ((code)FUN_00521408)(iVar6,0,400);
      *(int *)(iVar6 + 0xfc) = iVar16;
      *(int *)(iVar6 + 0x124) = iVar19;
      *(u32 *)(iVar6 + 0x130) = 0x40;
      *(int *)(iVar6 + 0x134) = iVar14;
      *(int *)(iVar6 + 0x128) = iVar4;
      *(int *)(iVar6 + 300) = iVar15;
      ((code)FUN_00521250)(iVar6 + 0x100,aiStack_30,0x24);
      *(u32 *)(iVar6 + 0xf8) =
           *(u32 *)((u32)((param_4 & 0x20) != 0) * 4 + iVar16 + 0x1c);
      uVar1 = *(u32 *)((u8 *)DAT_0077ac58 + iVar7);
      uVar5 = 1;
      iVar4 = iVar16;
      if (1 < uVar1) {
        do {
          if (aiStack_30[*(int *)(iVar4 + 0x3c)] == 0) {
            uVar2 = (u8)*(u32 *)((u8 *)DAT_0077ac10 + *(int *)(iVar4 + 0x3c) * 4);
          }
          else {
            uVar2 = 0;
          }
          *(u8 *)(iVar6 + uVar5 + 0xf3) = uVar2;
          uVar5 = uVar5 + 1;
          uVar1 = *(u32 *)((u8 *)DAT_0077ac58 + iVar7);
          iVar4 = iVar4 + 0x18;
        } while (uVar5 < uVar1);
      }
      uVar5 = 0;
      iVar4 = iVar6;
      iVar14 = iVar6;
      if (uVar1 != 0) {
        do {
          if (aiStack_30[*(int *)(iVar16 + 0x24)] == 0) {
            *(u32 *)(iVar14 + 0x40) = *(u32 *)(iVar16 + 0x28) | 0x30000000;
            *(u32 *)(iVar14 + 0x4c) = *(u32 *)(iVar16 + 0x30);
            *(u32 *)(iVar4 + 0x90) = (u32)(u32)(*(int *)(iVar16 + 0x28) << 4) << 0x20;
          }
          else {
            *(u32 *)(iVar14 + 0x40) = *(u32 *)(iVar16 + 0x2c) | 0x30000000;
            *(u32 *)(iVar14 + 0x4c) = *(u32 *)(iVar16 + 0x34);
            *(u64 *)(iVar4 + 0x90) = 0;
          }
          uVar5 = uVar5 + 1;
          *(u32 *)(iVar14 + 0x48) = *(u32 *)(iVar16 + 0x38);
          iVar16 = iVar16 + 0x18;
          iVar4 = iVar4 + 8;
          iVar14 = iVar14 + 0x10;
        } while (uVar5 < *(u32 *)((u8 *)DAT_0077ac58 + iVar7));
      }
    }
    *(int *)(iVar6 + 0xd8) = iVar18;
    *(u32 *)(iVar6 + 0xe8) = uVar17 - 1;
    *(u32 *)(iVar6 + 0xe0) = uVar17 < 2 ^ 1;
    *(u64 *)(iVar6 + 200) = 0xe;
    if ((param_4 & 1) != 0) {
      *(u32 *)(iVar6 + 0xdc) = 1;
    }
    *(int *)(param_1 + 0x4c) = iVar6;
  }
  else {
    iVar6 = (*(code *)PTR_FUN_0077b250)(param_1,param_2,uVar1,param_4);
  }
  return iVar6;
}

// FUN_00475C20 NONMATCHING

void FUN_00475c20(int param_1)

{
  int iVar1;
  u32 uVar3;
  int *piVar2;
  
  if ((*(u32 *)(*(int *)(param_1 + iGpffffba80) + 0x44) & 0x10) == 0) {
    iVar1 = *(int *)(*(int *)(param_1 + iGpffffba80) + 0x9c);
    uVar3 = 0;
    piVar2 = (int *)iVar1;
    do {
      if (piVar2[0x4e] != 0) {
        FUN_004c47e0_typed(piVar2[0x4e]);
        piVar2[0x4e] = 0;
      }
      uVar3 = uVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (uVar3 <= *(u32 *)(iVar1 + 0xe8));
  }
  return;
}

// FUN_00475CB0 NONMATCHING

void FUN_00475cb0(int param_1)

{
  int iVar1;
  int iVar2;
  u32 uVar3;
  
  if (((*(u32 *)(*(int *)(param_1 + DAT_007ce770) + 0x44) & 0x10) == 0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + DAT_007ce770) + 0x9c), *(int *)(iVar1 + 0xd8) != 0)) {
    uVar3 = 0;
    iVar2 = iVar1;
    do {
      if (*(int *)(iVar2 + 0x10) != 0) {
        ((code)FUN_004d4df0)();
        ((code)FUN_004d4df0)();
      }
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 0x20;
    } while (uVar3 <= *(u32 *)(iVar1 + 0xe8));
  }
  return;
}

// FUN_00475D60 NONMATCHING

long FUN_00475d60(u64 param_1,u64 param_2,u64 param_3,u32 param_4,
                 u32 param_5)

{
  u8 bVar1;
  int iVar2;
  long lVar3;
  long lVar4;
  u64 uVar5;
  int iVar6;
  u32 uVar7;
  int iVar8;
  
  iVar6 = (int)param_2;
  iVar2 = *(int *)(iVar6 + 0x4c);
  bVar1 = (param_5 & 4) != 4;
  uVar7 = param_5 & 0x10;
  if (!bVar1) {
    uVar7 = 0;
  }
  iVar8 = (int)param_1;
  if (uVar7 == 0) {
    if (*(int *)(iVar2 + 0xd8) == 0) {
      if (bVar1 && (param_4 & 0xffffffffcff7ff78) == 0) {
        lVar3 = ((code)FUN_00478e80)(param_1,param_3,param_4);
        if (lVar3 == 1) {
          iVar8 = *(int *)(iVar8 + DAT_007ce770);
          **(code **)(iVar8 + 0x24) = (code)FUN_00477150;
          **(code **)(iVar8 + 0x28) = (code)FUN_00477610;
          if ((*(u32 *)(iVar6 + 0x58) & 4) == 4) {
            **(code **)(iVar8 + 0x34) = (code)FUN_00478280;
          }
          else {
            **(code **)(iVar8 + 0x34) = (code)FUN_00478100;
          }
          if ((*(u32 *)(iVar6 + 0x58) & 0x80) == 0x80) {
            **(code **)(iVar8 + 0x2c) = (code)FUN_00477eb0;
          }
          else if ((*(u32 *)(iVar6 + 0x58) & 0x80000) == 0x80000) {
            **(code **)(iVar8 + 0x2c) = (code)FUN_00477c90;
          }
          else {
            *(u32 *)(iVar8 + 0x2c) = 0;
          }
          if ((*(u32 *)(iVar6 + 0x58) & 2) == 2) {
            **(code **)(iVar8 + 0x30) = (code)FUN_00477a20;
          }
          else {
            **(code **)(iVar8 + 0x30) = (code)FUN_00477810;
          }
          *(u32 *)(iVar8 + 0x38) = 0;
          ((code)FUN_00474f20)(param_1,iVar2 + 400);
        }
      }
      else if (bVar1 && (param_4 & 0xffffffffcee17e10) == 0) {
        lVar3 = ((code)FUN_0047a210)(param_1,param_3,param_4);
        if (lVar3 == 1) {
          ((code)FUN_0047bf80)(param_1);
          iVar6 = *(int *)(iVar8 + DAT_007ce770);
          **(code **)(iVar6 + 0x24) = (code)FUN_00479170;
          *(u32 *)(iVar6 + 0x38) = 0;
          ((code)FUN_00474f20)(param_1,iVar2 + 400);
        }
      }
      else {
        ((code)FUN_00474f20)(param_1,iVar2 + 400);
        lVar3 = ((code)FUN_00486340)(param_1,param_3,param_4);
        if (lVar3 != 0) {
          *(u32 *)(iVar8 + 0x6c) =
               *(u32 *)(*(int *)((int)(u8 *)DAT_00960070 + DAT_007ce774) + 0x14);
          *(u8 **)(*(int *)(iVar8 + DAT_007ce770) + 0x20) = &LAB_00488b90;
        }
      }
    }
    else {
      lVar3 = ((code)FUN_00493710)(0,0,0);
      if (lVar3 == 0) {
        lVar3 = 0;
      }
      else {
        iVar6 = *(int *)((int)lVar3 + 0x5c);
        *(u32 *)(iVar6 + 4) = 0;
        *(u32 *)(iVar6 + 8) = 0;
        *(u32 *)(iVar6 + 0xc) = 0;
        *(u32 *)(iVar6 + 0x10) = 0x3f800000;
        lVar4 = ((code)FUN_004933d0)(lVar3);
        if (lVar4 == 0) {
          lVar3 = 0;
        }
        else {
          ((code)FUN_004919b0)(param_1,lVar3,0);
          ((code)FUN_00493b60)(lVar3);
          uVar5 = ((code)FUN_00494be0)();
          ((code)FUN_00495340)((int)lVar3 + 0x20,uVar5);
          ((code)FUN_00494cc0)(uVar5);
          iVar6 = *(int *)(iVar8 + DAT_007ce770);
          **(code **)(iVar6 + 0x1c) = (code)FUN_0047a510;
          *(u32 *)(iVar6 + 0x24) = 0;
          *(u32 *)(iVar6 + 0x28) = 0;
          *(u32 *)(iVar6 + 0x2c) = 0;
          *(u32 *)(iVar6 + 0x30) = 0;
          *(u32 *)(iVar6 + 0x34) = 0;
          *(u32 *)(iVar6 + 0x38) = 0;
          *(u32 *)(iVar8 + 0x6c) = **(u32 **)((int)(u8 *)DAT_00960070 + DAT_007ce774);
          if ((*(u32 *)(iVar6 + 0x44) & 8) == 0) {
            ((code)FUN_00474f20)(param_1,iVar2 + 400);
          }
          lVar3 = 1;
        }
      }
    }
  }
  else {
    ((code)FUN_00521250)(*(int *)(iVar8 + DAT_007ce770) + 0x14,0x77b250,0x10);
    lVar3 = (*(code *)PTR_FUN_0077b254)(param_1,param_2,param_3,param_4,param_5);
  }
  return lVar3;
}

// FUN_00476140 NONMATCHING

void FUN_00476140(u32 *param_1,long param_2,u32 param_3)

{
  char cVar1;
  u32 uVar2;
  u8 bVar3;
  u32 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = (int)param_2;
  iVar7 = iVar6;
  if (param_2 < 0) {
    iVar7 = iVar6 + 0xf;
  }
  iVar7 = iVar7 >> 4;
  iVar6 = iVar6 + iVar7 * -0x10;
  FlushCache(0);
  uVar2 = REG_DMAC_8_SPR_FROM_CHCR;
  if ((uVar2 & 0x100) != 0) {
    REG_DMAC_PCR = 0x100;
    SYNC(0);
    SYNC(0x10);
    do {
      cVar1 = getCopCondition(0,0);
    } while (cVar1 == '\0');
  }
  uVar2 = REG_DMAC_9_SPR_TO_CHCR;
  if ((uVar2 & 0x100) != 0) {
    REG_DMAC_PCR = 0x200;
    SYNC(0);
    SYNC(0x10);
    do {
      cVar1 = getCopCondition(0,0);
    } while (cVar1 == '\0');
    do {
      uVar2 = REG_DMAC_9_SPR_TO_CHCR;
    } while ((uVar2 & 0x100) != 0);
  }
  puVar4 = (u32 *)((u8 *)DAT_70000000);
  iVar5 = 0;
  do {
    *puVar4 = param_3;
    puVar4[1] = param_3;
    puVar4[2] = param_3;
    puVar4[3] = param_3;
    iVar5 = iVar5 + 8;
    puVar4[4] = param_3;
    puVar4[5] = param_3;
    puVar4[6] = param_3;
    puVar4[7] = param_3;
    puVar4[8] = param_3;
    puVar4[9] = param_3;
    puVar4[10] = param_3;
    puVar4[0xb] = param_3;
    puVar4[0xc] = param_3;
    puVar4[0xd] = param_3;
    puVar4[0xe] = param_3;
    puVar4[0xf] = param_3;
    puVar4[0x10] = param_3;
    puVar4[0x11] = param_3;
    puVar4[0x12] = param_3;
    puVar4[0x13] = param_3;
    puVar4[0x14] = param_3;
    puVar4[0x15] = param_3;
    puVar4[0x16] = param_3;
    puVar4[0x17] = param_3;
    puVar4[0x18] = param_3;
    puVar4[0x19] = param_3;
    puVar4[0x1a] = param_3;
    puVar4[0x1b] = param_3;
    puVar4[0x1c] = param_3;
    puVar4[0x1d] = param_3;
    puVar4[0x1e] = param_3;
    puVar4[0x1f] = param_3;
    puVar4 = puVar4 + 0x20;
  } while (iVar5 < 0x400);
  for (; 0x400 < iVar7; iVar7 = iVar7 + -0x400) {
    uVar2 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar2 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar1 = getCopCondition(0,0);
      } while (cVar1 == '\0');
    }
    REG_DMAC_STAT = 0x100;
    REG_DMAC_8_SPR_FROM_SADR = 0;
    REG_DMAC_8_SPR_FROM_MADR = (u32)(param_1);
    REG_DMAC_8_SPR_FROM_QWC = 0x400;
    REG_DMAC_8_SPR_FROM_CHCR = 0x100;
    SYNC(0);
    SYNC(0x10);
    param_1 = param_1 + 0x1000;
  }
  if (iVar7 != 0) {
    uVar2 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar2 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar1 = getCopCondition(0,0);
      } while (cVar1 == '\0');
    }
    REG_DMAC_STAT = 0x100;
    REG_DMAC_8_SPR_FROM_SADR = 0;
    REG_DMAC_8_SPR_FROM_MADR = (u32)(param_1);
    REG_DMAC_8_SPR_FROM_QWC = iVar7;
    REG_DMAC_8_SPR_FROM_CHCR = 0x100;
    SYNC(0);
    SYNC(0x10);
    param_1 = param_1 + iVar7 * 4;
  }
  if ((iVar6 != 0) && (iVar7 = 0, 0 < iVar6)) {
    if (8 < iVar6) {
      bVar3 = 0;
      if ((-1 < iVar6) && (iVar6 < 0x7fffffff)) {
        bVar3 = 1;
      }
      if (bVar3) {
        do {
          iVar7 = iVar7 + 8;
          *param_1 = DAT_70000000;
          param_1[1] = DAT_70000000;
          param_1[2] = DAT_70000000;
          param_1[3] = DAT_70000000;
          param_1[4] = DAT_70000000;
          param_1[5] = DAT_70000000;
          param_1[6] = DAT_70000000;
          param_1[7] = DAT_70000000;
          param_1 = param_1 + 8;
        } while (iVar7 < iVar6 + -8);
      }
    }
    for (; iVar7 < iVar6; iVar7 = iVar7 + 1) {
      *param_1 = DAT_70000000;
      param_1 = param_1 + 1;
    }
  }
  return;
}

// FUN_00476490 NONMATCHING



void FUN_00476490(u64 *param_1,long param_2,u64 *param_3)

{
  char cVar1;
  int iVar2;
  u32 uVar3;
  u64 uVar4;
  int iVar5;
  u32 *puVar6;
  int iVar7;
  int iVar8;
  u32 uStack_10;
  u32 uStack_c;
  
  iVar5 = (int)param_2;
  iVar8 = iVar5;
  if (param_2 < 0) {
    iVar8 = iVar5 + 0xf;
  }
  iVar8 = iVar8 >> 4;
  iVar2 = iVar8 * -0x10;
  FlushCache(0);
  uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
  if ((uVar3 & 0x100) != 0) {
    REG_DMAC_PCR = 0x100;
    SYNC(0);
    SYNC(0x10);
    do {
      cVar1 = getCopCondition(0,0);
    } while (cVar1 == '\0');
  }
  uVar3 = REG_DMAC_9_SPR_TO_CHCR;
  if ((uVar3 & 0x100) == 0) {
    uVar4 = *param_3;
  }
  else {
    REG_DMAC_PCR = 0x200;
    SYNC(0);
    SYNC(0x10);
    do {
      cVar1 = getCopCondition(0,0);
    } while (cVar1 == '\0');
    do {
      uVar3 = REG_DMAC_9_SPR_TO_CHCR;
    } while ((uVar3 & 0x100) != 0);
    uVar4 = *param_3;
  }
  puVar6 = (u32 *)((u8 *)DAT_70000000);
  iVar7 = 0;
  uStack_10 = (u32)uVar4;
  uStack_c = (u32)((u32)uVar4 >> 0x20);
  do {
    *puVar6 = uStack_10;
    puVar6[1] = uStack_c;
    puVar6[2] = uStack_10;
    puVar6[3] = uStack_c;
    iVar7 = iVar7 + 8;
    puVar6[4] = uStack_10;
    puVar6[5] = uStack_c;
    puVar6[6] = uStack_10;
    puVar6[7] = uStack_c;
    puVar6[8] = uStack_10;
    puVar6[9] = uStack_c;
    puVar6[10] = uStack_10;
    puVar6[0xb] = uStack_c;
    puVar6[0xc] = uStack_10;
    puVar6[0xd] = uStack_c;
    puVar6[0xe] = uStack_10;
    puVar6[0xf] = uStack_c;
    puVar6[0x10] = uStack_10;
    puVar6[0x11] = uStack_c;
    puVar6[0x12] = uStack_10;
    puVar6[0x13] = uStack_c;
    puVar6[0x14] = uStack_10;
    puVar6[0x15] = uStack_c;
    puVar6[0x16] = uStack_10;
    puVar6[0x17] = uStack_c;
    puVar6[0x18] = uStack_10;
    puVar6[0x19] = uStack_c;
    puVar6[0x1a] = uStack_10;
    puVar6[0x1b] = uStack_c;
    puVar6[0x1c] = uStack_10;
    puVar6[0x1d] = uStack_c;
    puVar6[0x1e] = uStack_10;
    puVar6[0x1f] = uStack_c;
    puVar6 = puVar6 + 0x20;
  } while (iVar7 < 0x400);
  for (; 0x400 < iVar8; iVar8 = iVar8 + -0x400) {
    uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar3 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar1 = getCopCondition(0,0);
      } while (cVar1 == '\0');
    }
    REG_DMAC_STAT = 0x100;
    REG_DMAC_8_SPR_FROM_SADR = 0;
    REG_DMAC_8_SPR_FROM_MADR = (u32)(param_1);
    REG_DMAC_8_SPR_FROM_QWC = 0x400;
    REG_DMAC_8_SPR_FROM_CHCR = 0x100;
    SYNC(0);
    SYNC(0x10);
    param_1 = param_1 + 0x800;
  }
  if (iVar8 != 0) {
    uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar3 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar1 = getCopCondition(0,0);
      } while (cVar1 == '\0');
    }
    REG_DMAC_STAT = 0x100;
    REG_DMAC_8_SPR_FROM_SADR = 0;
    REG_DMAC_8_SPR_FROM_MADR = (u32)(param_1);
    REG_DMAC_8_SPR_FROM_QWC = iVar8;
    REG_DMAC_8_SPR_FROM_CHCR = 0x100;
    SYNC(0);
    SYNC(0x10);
    param_1 = param_1 + iVar8 * 2;
  }
  if (iVar5 + iVar2 != 0) {
    *param_1 = _DAT_70000000;
  }
  return;
}

// FUN_00476720 NONMATCHING

void FUN_00476720(int param_1,long param_2,u64 *param_3)

{
  char cVar1;
  u64 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 *puVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = (int)param_2;
  if (param_2 < 0) {
    iVar8 = iVar8 + 0xf;
  }
  iVar8 = iVar8 >> 4;
  FlushCache(0);
  uVar3 = REG_DMAC_9_SPR_TO_CHCR;
  if ((uVar3 & 0x100) != 0) {
    REG_DMAC_PCR = 0x200;
    SYNC(0);
    SYNC(0x10);
    do {
      cVar1 = getCopCondition(0,0);
    } while (cVar1 == '\0');
    do {
      uVar3 = REG_DMAC_9_SPR_TO_CHCR;
    } while ((uVar3 & 0x100) != 0);
  }
  uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
  if ((uVar3 & 0x100) != 0) {
    REG_DMAC_PCR = 0x100;
    SYNC(0);
    SYNC(0x10);
    do {
      cVar1 = getCopCondition(0,0);
    } while (cVar1 == '\0');
  }
  puVar6 = (u32 *)((u8 *)DAT_70000000);
  iVar7 = 0;
  do {
    uVar2 = *param_3;
    uVar4 = *(u32 *)(param_3 + 1);
    uVar5 = *(u32 *)((int)param_3 + 0xc);
    iVar7 = iVar7 + 8;
    *puVar6 = (int)uVar2;
    puVar6[1] = (int)((u32)uVar2 >> 0x20);
    puVar6[2] = uVar4;
    puVar6[3] = uVar5;
    uVar2 = *param_3;
    uVar4 = *(u32 *)(param_3 + 1);
    uVar5 = *(u32 *)((int)param_3 + 0xc);
    puVar6[4] = (int)uVar2;
    puVar6[5] = (int)((u32)uVar2 >> 0x20);
    puVar6[6] = uVar4;
    puVar6[7] = uVar5;
    uVar2 = *param_3;
    uVar4 = *(u32 *)(param_3 + 1);
    uVar5 = *(u32 *)((int)param_3 + 0xc);
    puVar6[8] = (int)uVar2;
    puVar6[9] = (int)((u32)uVar2 >> 0x20);
    puVar6[10] = uVar4;
    puVar6[0xb] = uVar5;
    uVar2 = *param_3;
    uVar4 = *(u32 *)(param_3 + 1);
    uVar5 = *(u32 *)((int)param_3 + 0xc);
    puVar6[0xc] = (int)uVar2;
    puVar6[0xd] = (int)((u32)uVar2 >> 0x20);
    puVar6[0xe] = uVar4;
    puVar6[0xf] = uVar5;
    uVar2 = *param_3;
    uVar4 = *(u32 *)(param_3 + 1);
    uVar5 = *(u32 *)((int)param_3 + 0xc);
    puVar6[0x10] = (int)uVar2;
    puVar6[0x11] = (int)((u32)uVar2 >> 0x20);
    puVar6[0x12] = uVar4;
    puVar6[0x13] = uVar5;
    uVar2 = *param_3;
    uVar4 = *(u32 *)(param_3 + 1);
    uVar5 = *(u32 *)((int)param_3 + 0xc);
    puVar6[0x14] = (int)uVar2;
    puVar6[0x15] = (int)((u32)uVar2 >> 0x20);
    puVar6[0x16] = uVar4;
    puVar6[0x17] = uVar5;
    uVar2 = *param_3;
    uVar4 = *(u32 *)(param_3 + 1);
    uVar5 = *(u32 *)((int)param_3 + 0xc);
    puVar6[0x18] = (int)uVar2;
    puVar6[0x19] = (int)((u32)uVar2 >> 0x20);
    puVar6[0x1a] = uVar4;
    puVar6[0x1b] = uVar5;
    uVar2 = *param_3;
    uVar4 = *(u32 *)(param_3 + 1);
    uVar5 = *(u32 *)((int)param_3 + 0xc);
    puVar6[0x1c] = (int)uVar2;
    puVar6[0x1d] = (int)((u32)uVar2 >> 0x20);
    puVar6[0x1e] = uVar4;
    puVar6[0x1f] = uVar5;
    puVar6 = puVar6 + 0x20;
  } while (iVar7 < 0x400);
  for (; 0x400 < iVar8; iVar8 = iVar8 + -0x400) {
    uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar3 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar1 = getCopCondition(0,0);
      } while (cVar1 == '\0');
    }
    REG_DMAC_STAT = 0x100;
    REG_DMAC_8_SPR_FROM_SADR = 0;
    REG_DMAC_8_SPR_FROM_MADR = param_1;
    REG_DMAC_8_SPR_FROM_QWC = 0x400;
    REG_DMAC_8_SPR_FROM_CHCR = 0x100;
    SYNC(0);
    SYNC(0x10);
    param_1 = param_1 + 0x4000;
  }
  if (iVar8 != 0) {
    uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar3 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar1 = getCopCondition(0,0);
      } while (cVar1 == '\0');
    }
    REG_DMAC_STAT = 0x100;
    REG_DMAC_8_SPR_FROM_SADR = 0;
    REG_DMAC_8_SPR_FROM_MADR = param_1;
    REG_DMAC_8_SPR_FROM_QWC = iVar8;
    REG_DMAC_8_SPR_FROM_CHCR = 0x100;
    SYNC(0);
    SYNC(0x10);
  }
  return;
}

// FUN_00476980 NONMATCHING

void FUN_00476980(int param_1,long param_2,u64 *param_3)

{
  char cVar1;
  u64 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 *puVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = (int)param_2;
  if (param_2 < 0) {
    iVar8 = iVar8 + 0xf;
  }
  iVar8 = iVar8 >> 4;
  FlushCache(0);
  uVar3 = REG_DMAC_9_SPR_TO_CHCR;
  if ((uVar3 & 0x100) != 0) {
    REG_DMAC_PCR = 0x200;
    SYNC(0);
    SYNC(0x10);
    do {
      cVar1 = getCopCondition(0,0);
    } while (cVar1 == '\0');
    do {
      uVar3 = REG_DMAC_9_SPR_TO_CHCR;
    } while ((uVar3 & 0x100) != 0);
  }
  uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
  if ((uVar3 & 0x100) != 0) {
    REG_DMAC_PCR = 0x100;
    SYNC(0);
    SYNC(0x10);
    do {
      cVar1 = getCopCondition(0,0);
    } while (cVar1 == '\0');
  }
  puVar6 = (u32 *)((u8 *)DAT_70000000);
  iVar7 = 0;
  do {
    uVar2 = *param_3;
    uVar4 = *(u32 *)(param_3 + 1);
    uVar5 = *(u32 *)((int)param_3 + 0xc);
    iVar7 = iVar7 + 8;
    *puVar6 = (int)uVar2;
    puVar6[1] = (int)((u32)uVar2 >> 0x20);
    puVar6[2] = uVar4;
    puVar6[3] = uVar5;
    uVar2 = param_3[2];
    uVar4 = *(u32 *)(param_3 + 3);
    uVar5 = *(u32 *)((int)param_3 + 0x1c);
    puVar6[4] = (int)uVar2;
    puVar6[5] = (int)((u32)uVar2 >> 0x20);
    puVar6[6] = uVar4;
    puVar6[7] = uVar5;
    uVar2 = *param_3;
    uVar4 = *(u32 *)(param_3 + 1);
    uVar5 = *(u32 *)((int)param_3 + 0xc);
    puVar6[8] = (int)uVar2;
    puVar6[9] = (int)((u32)uVar2 >> 0x20);
    puVar6[10] = uVar4;
    puVar6[0xb] = uVar5;
    uVar2 = param_3[2];
    uVar4 = *(u32 *)(param_3 + 3);
    uVar5 = *(u32 *)((int)param_3 + 0x1c);
    puVar6[0xc] = (int)uVar2;
    puVar6[0xd] = (int)((u32)uVar2 >> 0x20);
    puVar6[0xe] = uVar4;
    puVar6[0xf] = uVar5;
    uVar2 = *param_3;
    uVar4 = *(u32 *)(param_3 + 1);
    uVar5 = *(u32 *)((int)param_3 + 0xc);
    puVar6[0x10] = (int)uVar2;
    puVar6[0x11] = (int)((u32)uVar2 >> 0x20);
    puVar6[0x12] = uVar4;
    puVar6[0x13] = uVar5;
    uVar2 = param_3[2];
    uVar4 = *(u32 *)(param_3 + 3);
    uVar5 = *(u32 *)((int)param_3 + 0x1c);
    puVar6[0x14] = (int)uVar2;
    puVar6[0x15] = (int)((u32)uVar2 >> 0x20);
    puVar6[0x16] = uVar4;
    puVar6[0x17] = uVar5;
    uVar2 = *param_3;
    uVar4 = *(u32 *)(param_3 + 1);
    uVar5 = *(u32 *)((int)param_3 + 0xc);
    puVar6[0x18] = (int)uVar2;
    puVar6[0x19] = (int)((u32)uVar2 >> 0x20);
    puVar6[0x1a] = uVar4;
    puVar6[0x1b] = uVar5;
    uVar2 = param_3[2];
    uVar4 = *(u32 *)(param_3 + 3);
    uVar5 = *(u32 *)((int)param_3 + 0x1c);
    puVar6[0x1c] = (int)uVar2;
    puVar6[0x1d] = (int)((u32)uVar2 >> 0x20);
    puVar6[0x1e] = uVar4;
    puVar6[0x1f] = uVar5;
    uVar2 = *param_3;
    uVar4 = *(u32 *)(param_3 + 1);
    uVar5 = *(u32 *)((int)param_3 + 0xc);
    puVar6[0x20] = (int)uVar2;
    puVar6[0x21] = (int)((u32)uVar2 >> 0x20);
    puVar6[0x22] = uVar4;
    puVar6[0x23] = uVar5;
    uVar2 = param_3[2];
    uVar4 = *(u32 *)(param_3 + 3);
    uVar5 = *(u32 *)((int)param_3 + 0x1c);
    puVar6[0x24] = (int)uVar2;
    puVar6[0x25] = (int)((u32)uVar2 >> 0x20);
    puVar6[0x26] = uVar4;
    puVar6[0x27] = uVar5;
    uVar2 = *param_3;
    uVar4 = *(u32 *)(param_3 + 1);
    uVar5 = *(u32 *)((int)param_3 + 0xc);
    puVar6[0x28] = (int)uVar2;
    puVar6[0x29] = (int)((u32)uVar2 >> 0x20);
    puVar6[0x2a] = uVar4;
    puVar6[0x2b] = uVar5;
    uVar2 = param_3[2];
    uVar4 = *(u32 *)(param_3 + 3);
    uVar5 = *(u32 *)((int)param_3 + 0x1c);
    puVar6[0x2c] = (int)uVar2;
    puVar6[0x2d] = (int)((u32)uVar2 >> 0x20);
    puVar6[0x2e] = uVar4;
    puVar6[0x2f] = uVar5;
    uVar2 = *param_3;
    uVar4 = *(u32 *)(param_3 + 1);
    uVar5 = *(u32 *)((int)param_3 + 0xc);
    puVar6[0x30] = (int)uVar2;
    puVar6[0x31] = (int)((u32)uVar2 >> 0x20);
    puVar6[0x32] = uVar4;
    puVar6[0x33] = uVar5;
    uVar2 = param_3[2];
    uVar4 = *(u32 *)(param_3 + 3);
    uVar5 = *(u32 *)((int)param_3 + 0x1c);
    puVar6[0x34] = (int)uVar2;
    puVar6[0x35] = (int)((u32)uVar2 >> 0x20);
    puVar6[0x36] = uVar4;
    puVar6[0x37] = uVar5;
    uVar2 = *param_3;
    uVar4 = *(u32 *)(param_3 + 1);
    uVar5 = *(u32 *)((int)param_3 + 0xc);
    puVar6[0x38] = (int)uVar2;
    puVar6[0x39] = (int)((u32)uVar2 >> 0x20);
    puVar6[0x3a] = uVar4;
    puVar6[0x3b] = uVar5;
    uVar2 = param_3[2];
    uVar4 = *(u32 *)(param_3 + 3);
    uVar5 = *(u32 *)((int)param_3 + 0x1c);
    puVar6[0x3c] = (int)uVar2;
    puVar6[0x3d] = (int)((u32)uVar2 >> 0x20);
    puVar6[0x3e] = uVar4;
    puVar6[0x3f] = uVar5;
    puVar6 = puVar6 + 0x40;
  } while (iVar7 < 0x200);
  for (; 0x400 < iVar8; iVar8 = iVar8 + -0x400) {
    uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar3 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar1 = getCopCondition(0,0);
      } while (cVar1 == '\0');
    }
    REG_DMAC_STAT = 0x100;
    REG_DMAC_8_SPR_FROM_SADR = 0;
    REG_DMAC_8_SPR_FROM_MADR = param_1;
    REG_DMAC_8_SPR_FROM_QWC = 0x400;
    REG_DMAC_8_SPR_FROM_CHCR = 0x100;
    SYNC(0);
    SYNC(0x10);
    param_1 = param_1 + 0x4000;
  }
  if (iVar8 != 0) {
    uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar3 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar1 = getCopCondition(0,0);
      } while (cVar1 == '\0');
    }
    REG_DMAC_STAT = 0x100;
    REG_DMAC_8_SPR_FROM_SADR = 0;
    REG_DMAC_8_SPR_FROM_MADR = param_1;
    REG_DMAC_8_SPR_FROM_QWC = iVar8;
    REG_DMAC_8_SPR_FROM_CHCR = 0x100;
    SYNC(0);
    SYNC(0x10);
  }
  return;
}

// FUN_00476C20 NONMATCHING

void FUN_00476c20(int param_1,int param_2,long param_3)

{
  char cVar1;
  u32 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (int)param_3;
  iVar4 = iVar3;
  if (param_3 < 0) {
    iVar4 = iVar3 + 0xf;
  }
  iVar4 = iVar4 >> 4;
  iVar3 = iVar3 + iVar4 * -0x10;
  FlushCache(0);
  uVar2 = REG_DMAC_8_SPR_FROM_CHCR;
  if ((uVar2 & 0x100) != 0) {
    REG_DMAC_PCR = 0x100;
    SYNC(0);
    SYNC(0x10);
    do {
      cVar1 = getCopCondition(0,0);
    } while (cVar1 == '\0');
  }
  uVar2 = REG_DMAC_9_SPR_TO_CHCR;
  if ((uVar2 & 0x100) != 0) {
    REG_DMAC_PCR = 0x200;
    SYNC(0);
    SYNC(0x10);
    do {
      cVar1 = getCopCondition(0,0);
    } while (cVar1 == '\0');
    do {
      uVar2 = REG_DMAC_9_SPR_TO_CHCR;
    } while ((uVar2 & 0x100) != 0);
  }
  for (; 0x400 < iVar4; iVar4 = iVar4 + -0x400) {
    uVar2 = REG_DMAC_9_SPR_TO_CHCR;
    if ((uVar2 & 0x100) != 0) {
      REG_DMAC_PCR = 0x200;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar1 = getCopCondition(0,0);
      } while (cVar1 == '\0');
      do {
        uVar2 = REG_DMAC_9_SPR_TO_CHCR;
      } while ((uVar2 & 0x100) != 0);
    }
    REG_DMAC_STAT = 0x200;
    REG_DMAC_9_SPR_TO_SADR = 0;
    REG_DMAC_9_SPR_TO_MADR = param_2;
    REG_DMAC_9_SPR_TO_QWC = 0x400;
    REG_DMAC_9_SPR_TO_CHCR = 0x100;
    SYNC(0);
    SYNC(0x10);
    uVar2 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar2 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar1 = getCopCondition(0,0);
      } while (cVar1 == '\0');
    }
    uVar2 = REG_DMAC_9_SPR_TO_CHCR;
    if ((uVar2 & 0x100) != 0) {
      REG_DMAC_PCR = 0x200;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar1 = getCopCondition(0,0);
      } while (cVar1 == '\0');
      do {
        uVar2 = REG_DMAC_9_SPR_TO_CHCR;
      } while ((uVar2 & 0x100) != 0);
    }
    REG_DMAC_STAT = 0x100;
    REG_DMAC_8_SPR_FROM_SADR = 0;
    REG_DMAC_8_SPR_FROM_MADR = param_1;
    REG_DMAC_8_SPR_FROM_QWC = 0x400;
    REG_DMAC_8_SPR_FROM_CHCR = 0x100;
    SYNC(0);
    SYNC(0x10);
    param_2 = param_2 + 0x4000;
    param_1 = param_1 + 0x4000;
  }
  if (iVar4 != 0) {
    uVar2 = REG_DMAC_9_SPR_TO_CHCR;
    if ((uVar2 & 0x100) != 0) {
      REG_DMAC_PCR = 0x200;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar1 = getCopCondition(0,0);
      } while (cVar1 == '\0');
      do {
        uVar2 = REG_DMAC_9_SPR_TO_CHCR;
      } while ((uVar2 & 0x100) != 0);
    }
    REG_DMAC_STAT = 0x200;
    REG_DMAC_9_SPR_TO_SADR = 0;
    REG_DMAC_9_SPR_TO_MADR = param_2;
    REG_DMAC_9_SPR_TO_QWC = iVar4;
    REG_DMAC_9_SPR_TO_CHCR = 0x100;
    SYNC(0);
    SYNC(0x10);
    uVar2 = REG_DMAC_9_SPR_TO_CHCR;
    if ((uVar2 & 0x100) != 0) {
      REG_DMAC_PCR = 0x200;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar1 = getCopCondition(0,0);
      } while (cVar1 == '\0');
      do {
        uVar2 = REG_DMAC_9_SPR_TO_CHCR;
      } while ((uVar2 & 0x100) != 0);
    }
    uVar2 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar2 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar1 = getCopCondition(0,0);
      } while (cVar1 == '\0');
    }
    REG_DMAC_STAT = 0x100;
    REG_DMAC_8_SPR_FROM_SADR = 0;
    REG_DMAC_8_SPR_FROM_MADR = param_1;
    REG_DMAC_8_SPR_FROM_QWC = iVar4;
    REG_DMAC_8_SPR_FROM_CHCR = 0x100;
    SYNC(0);
    SYNC(0x10);
    param_2 = param_2 + iVar4 * 0x10;
    param_1 = param_1 + iVar4 * 0x10;
  }
  if (iVar3 != 0) {
    ((code)FUN_00521250)(param_1,param_2,iVar3);
  }
  return;
}

// FUN_00477050 NONMATCHING

u8 FUN_00477050(int param_1)

{
  int iVar1;
  u8 bVar2;
  int iVar3;
  u32 uVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = *(int *)(*(int *)(param_1 + DAT_007ce770) + 0x9c);
  iVar5 = *(int *)(param_1 + DAT_007ce770) + 0x50;
  if (*(int *)(iVar1 + 0xd8) == 0) {
    bVar2 = 1;
  }
  else {
    if (*(int *)(iVar1 + 0xe4) < *(int *)(iVar1 + 0xe8)) {
      *(int *)(iVar1 + 0xe4) = *(int *)(iVar1 + 0xe4) + 1;
    }
    else {
      *(u32 *)(iVar1 + 0xe4) = 0;
    }
    if (*(int *)(iVar1 + 0xe8) != 0) {
      uVar4 = 0;
      iVar3 = 0;
      do {
        uVar4 = uVar4 + 3;
        *(u32 *)(iVar5 + 4) =
             *(u32 *)(iVar1 + *(int *)(iVar1 + 0xe4) * 0x24 + iVar3 + 0x140);
        *(u32 *)(iVar5 + 0xc) =
             *(u32 *)(iVar1 + *(int *)(iVar1 + 0xe4) * 0x24 + iVar3 + 0x144);
        iVar6 = iVar1 + *(int *)(iVar1 + 0xe4) * 0x24 + iVar3;
        iVar3 = iVar3 + 0xc;
        *(u32 *)(iVar5 + 0x14) = *(u32 *)(iVar6 + 0x148);
        iVar5 = iVar5 + 0x18;
      } while (uVar4 < 9);
    }
    bVar2 = *(int *)(*(int *)(iVar1 + 0xe4) * 0x20 + iVar1 + 0x10) == 0;
  }
  return bVar2;
}

// FUN_00477150 NONMATCHING

void FUN_00477150(int *param_1,int param_2,u64 param_3,u64 param_4,u32 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  u8 bVar7;
  
  iVar1 = *(int *)((int)param_3 + 0x4c);
  if (*(int *)(iVar1 + 0xe0) == 1) {
    iVar5 = *(int *)(iVar1 + 0xe4);
    *(int *)(iVar1 + 0xe4) = iVar5 + 1;
    if (*(int *)(iVar1 + 0xe8) < *(int *)(iVar1 + 0xe4)) {
      *(u32 *)(iVar1 + 0xe4) = 0;
    }
    piVar6 = (int *)(*(int *)(param_2 + 0x18) + DAT_007ce890);
    bVar7 = 0;
    if (((int *)*piVar6 != (int *)0x0) && (*(int *)*piVar6 == 1)) {
      bVar7 = 1;
    }
    if (bVar7) {
      iVar4 = *(int *)(iVar1 + 0xe4);
    }
    else {
      piVar6 = (int *)((code)FUN_0049e5a0)(piVar6,1);
      iVar4 = *(int *)(iVar1 + 0xe4);
    }
    iVar2 = *piVar6;
    iVar3 = *(int *)(iVar2 + 4);
    iVar4 = *(int *)(iVar4 * 4 + iVar1 + 0x138);
    *(int *)(iVar2 + 4) = iVar4;
    if (iVar4 != 0) {
      *(int *)(*(int *)(iVar2 + 4) + 0x10) = iVar2 + 4;
      *(u32 *)(*(int *)(iVar1 + 0xe4) * 4 + iVar1 + 0x138) = 0;
    }
    iVar5 = iVar5 * 4 + iVar1;
    *(int *)(iVar5 + 0x138) = iVar3;
    piVar6 = (int *)(iVar5 + 0x138);
    if (iVar3 != 0) {
      *(int **)(*piVar6 + 0x10) = piVar6;
    }
  }
  iVar5 = *(int *)(iVar1 + 0xe4);
  if ((param_5 & 0x10000000) == 0) {
    iVar4 = *(int *)(param_2 + 0x18);
  }
  else {
    ((code)FUN_00474a80)(param_3);
    iVar4 = *(int *)(param_2 + 0x18);
  }
  piVar6 = (int *)(iVar4 + DAT_007ce890);
  bVar7 = 0;
  if (((int *)*piVar6 != (int *)0x0) && (*(int *)*piVar6 == 1)) {
    bVar7 = 1;
  }
  if (bVar7) {
    iVar4 = *piVar6;
  }
  else {
    piVar6 = (int *)((code)FUN_0049e5a0)(piVar6,1);
    iVar4 = *piVar6;
  }
  if (*(int *)(iVar4 + 4) == 0) {
    param_1[2] = 0;
    param_1[1] = 0;
    *param_1 = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[10] = 0;
    param_1[0xb] = 0;
  }
  else {
    ((code)FUN_004d5e90)();
    param_1[2] = (u32)((param_5 & 2) == 2 || (param_5 & 0x2000) == 0x2000);
    param_1[1] = (u32)((param_5 & 0x80) == 0x80 || (param_5 & 0x80000) == 0x80000);
    *param_1 = 1;
    param_1[3] = (u32)((param_5 & 4) == 4 || (param_5 & 0x4000) == 0x4000);
    if (*param_1 != 0) {
      param_1[4] = *(int *)(iVar5 * 0x24 + iVar1 + 0x140);
      param_1[5] = 0x10;
    }
    if (param_1[2] != 0) {
      param_1[8] = *(int *)(iVar5 * 0x24 + iVar1 + 0x150);
      param_1[9] = 4;
    }
    if (param_1[1] != 0) {
      param_1[6] = *(int *)(iVar5 * 0x24 + iVar1 + 0x15c);
      param_1[7] = 0x10;
    }
    if (param_1[3] != 0) {
      param_1[10] = *(int *)(iVar5 * 0x24 + iVar1 + 0x14c);
      param_1[0xb] = 8;
    }
  }
  return;
}

// FUN_00477470 NONMATCHING

void FUN_00477470(int *param_1,u64 param_2,u64 param_3,u64 param_4,
                 u32 param_5)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)((int)param_3 + 0x4c);
  iVar2 = *(int *)(iVar1 + 0xe4);
  if ((param_5 & 0x10000000) != 0) {
    ((code)FUN_00474a80)(param_3);
  }
  ((code)FUN_004d5e90)();
  param_1[2] = (u32)((param_5 & 2) == 2 || (param_5 & 0x2000) == 0x2000);
  param_1[1] = (u32)((param_5 & 0x80) == 0x80 || (param_5 & 0x80000) == 0x80000);
  *param_1 = 1;
  param_1[3] = (u32)((param_5 & 4) == 4 || (param_5 & 0x4000) == 0x4000);
  if (*param_1 != 0) {
    param_1[4] = *(int *)(iVar2 * 0x24 + iVar1 + 0x140);
    param_1[5] = 0x10;
  }
  if (param_1[2] != 0) {
    param_1[8] = *(int *)(iVar2 * 0x24 + iVar1 + 0x150);
    param_1[9] = 4;
  }
  if (param_1[1] != 0) {
    param_1[6] = *(int *)(iVar2 * 0x24 + iVar1 + 0x15c);
    param_1[7] = 0x10;
  }
  if (param_1[3] != 0) {
    param_1[10] = *(int *)(iVar2 * 0x24 + iVar1 + 0x14c);
    param_1[0xb] = 8;
  }
  return;
}

// FUN_00477610 NONMATCHING

void FUN_00477610(int *param_1,u64 param_2,u64 param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  u8 bVar3;
  int iVar4;
  u32 *puVar5;
  u32 *puVar6;
  u32 *puVar7;
  u32 *puVar8;
  u32 *puVar9;
  u32 *puVar10;
  u32 *puVar11;
  u32 *puVar12;
  u32 *puVar13;
  u32 *puVar14;
  u32 *puVar15;
  u32 *puVar16;
  u32 *puVar17;
  u32 *puVar18;
  u32 *puVar19;
  u32 *puVar20;
  
  puVar5 = *(u32 **)(param_5 + 4);
  iVar1 = *(int *)(param_5 + 8);
  iVar2 = param_1[1];
  puVar6 = (u32 *)*param_1;
  if (iVar1 == iVar2) {
    ((code)FUN_00476c20)(puVar6,puVar5,param_4 * iVar2);
  }
  else {
    iVar4 = 0;
    if (0 < param_4) {
      if (8 < param_4) {
        bVar3 = 0;
        if ((-1 < param_4) && (param_4 < 0x7fffffff)) {
          bVar3 = 1;
        }
        if (bVar3) {
          do {
            puVar17 = (u32 *)((int)puVar5 + iVar1);
            puVar18 = (u32 *)((int)puVar6 + iVar2);
            puVar15 = (u32 *)((int)puVar17 + iVar1);
            puVar16 = (u32 *)((int)puVar18 + iVar2);
            puVar13 = (u32 *)((int)puVar15 + iVar1);
            puVar14 = (u32 *)((int)puVar16 + iVar2);
            puVar19 = (u32 *)((int)puVar13 + iVar1);
            puVar20 = (u32 *)((int)puVar14 + iVar2);
            puVar11 = (u32 *)((int)puVar19 + iVar1);
            puVar12 = (u32 *)((int)puVar20 + iVar2);
            puVar9 = (u32 *)((int)puVar11 + iVar1);
            *puVar6 = *puVar5;
            puVar10 = (u32 *)((int)puVar12 + iVar2);
            iVar4 = iVar4 + 8;
            puVar7 = (u32 *)((int)puVar9 + iVar1);
            puVar8 = (u32 *)((int)puVar10 + iVar2);
            puVar6[1] = puVar5[1];
            puVar6[2] = puVar5[2];
            puVar5 = (u32 *)((int)puVar7 + iVar1);
            puVar6 = (u32 *)((int)puVar8 + iVar2);
            *puVar18 = *puVar17;
            puVar18[1] = puVar17[1];
            puVar18[2] = puVar17[2];
            *puVar16 = *puVar15;
            puVar16[1] = puVar15[1];
            puVar16[2] = puVar15[2];
            *puVar14 = *puVar13;
            puVar14[1] = puVar13[1];
            puVar14[2] = puVar13[2];
            *puVar20 = *puVar19;
            puVar20[1] = puVar19[1];
            puVar20[2] = puVar19[2];
            *puVar12 = *puVar11;
            puVar12[1] = puVar11[1];
            puVar12[2] = puVar11[2];
            *puVar10 = *puVar9;
            puVar10[1] = puVar9[1];
            puVar10[2] = puVar9[2];
            *puVar8 = *puVar7;
            puVar8[1] = puVar7[1];
            puVar8[2] = puVar7[2];
          } while (iVar4 < param_4 + -8);
        }
      }
      for (; iVar4 < param_4; iVar4 = iVar4 + 1) {
        *puVar6 = *puVar5;
        puVar6[1] = puVar5[1];
        puVar6[2] = puVar5[2];
        puVar5 = (u32 *)((int)puVar5 + iVar1);
        puVar6 = (u32 *)((int)puVar6 + iVar2);
      }
    }
  }
  return;
}

// FUN_00477810 NONMATCHING

void FUN_00477810(u32 *param_1,int param_2,int param_3)

{
  u8 uVar1;
  u8 uVar2;
  u8 uVar3;
  int iVar4;
  u8 bVar5;
  u8 *puVar6;
  int iVar7;
  u8 *puVar8;
  u8 *puVar9;
  u8 *puVar10;
  u8 *puVar11;
  u8 *puVar12;
  u8 *puVar13;
  u8 *puVar14;
  
  puVar6 = (u8 *)*param_1;
  iVar4 = param_1[1];
  if (iVar4 == 4) {
    ((code)FUN_00476140)(puVar6,param_2 * 4,*(u32 *)(param_3 + 0x7c));
  }
  else {
    iVar7 = 0;
    if (0 < param_2) {
      if (8 < param_2) {
        bVar5 = 0;
        if ((-1 < param_2) && (param_2 < 0x7fffffff)) {
          bVar5 = 1;
        }
        if (bVar5) {
          do {
            puVar12 = puVar6 + iVar4;
            uVar1 = *(u8 *)(param_3 + 0x7d);
            puVar11 = puVar12 + iVar4;
            uVar2 = *(u8 *)(param_3 + 0x7e);
            puVar10 = puVar11 + iVar4;
            uVar3 = *(u8 *)(param_3 + 0x7f);
            puVar14 = puVar10 + iVar4;
            puVar13 = puVar14 + iVar4;
            iVar7 = iVar7 + 8;
            puVar9 = puVar13 + iVar4;
            puVar8 = puVar9 + iVar4;
            *puVar6 = *(u8 *)(param_3 + 0x7c);
            puVar6[1] = uVar1;
            puVar6[2] = uVar2;
            puVar6[3] = uVar3;
            puVar6 = puVar8 + iVar4;
            uVar1 = *(u8 *)(param_3 + 0x7d);
            uVar2 = *(u8 *)(param_3 + 0x7e);
            uVar3 = *(u8 *)(param_3 + 0x7f);
            *puVar12 = *(u8 *)(param_3 + 0x7c);
            puVar12[1] = uVar1;
            puVar12[2] = uVar2;
            puVar12[3] = uVar3;
            uVar1 = *(u8 *)(param_3 + 0x7d);
            uVar2 = *(u8 *)(param_3 + 0x7e);
            uVar3 = *(u8 *)(param_3 + 0x7f);
            *puVar11 = *(u8 *)(param_3 + 0x7c);
            puVar11[1] = uVar1;
            puVar11[2] = uVar2;
            puVar11[3] = uVar3;
            uVar1 = *(u8 *)(param_3 + 0x7d);
            uVar2 = *(u8 *)(param_3 + 0x7e);
            uVar3 = *(u8 *)(param_3 + 0x7f);
            *puVar10 = *(u8 *)(param_3 + 0x7c);
            puVar10[1] = uVar1;
            puVar10[2] = uVar2;
            puVar10[3] = uVar3;
            uVar1 = *(u8 *)(param_3 + 0x7d);
            uVar2 = *(u8 *)(param_3 + 0x7e);
            uVar3 = *(u8 *)(param_3 + 0x7f);
            *puVar14 = *(u8 *)(param_3 + 0x7c);
            puVar14[1] = uVar1;
            puVar14[2] = uVar2;
            puVar14[3] = uVar3;
            uVar1 = *(u8 *)(param_3 + 0x7d);
            uVar2 = *(u8 *)(param_3 + 0x7e);
            uVar3 = *(u8 *)(param_3 + 0x7f);
            *puVar13 = *(u8 *)(param_3 + 0x7c);
            puVar13[1] = uVar1;
            puVar13[2] = uVar2;
            puVar13[3] = uVar3;
            uVar1 = *(u8 *)(param_3 + 0x7d);
            uVar2 = *(u8 *)(param_3 + 0x7e);
            uVar3 = *(u8 *)(param_3 + 0x7f);
            *puVar9 = *(u8 *)(param_3 + 0x7c);
            puVar9[1] = uVar1;
            puVar9[2] = uVar2;
            puVar9[3] = uVar3;
            uVar1 = *(u8 *)(param_3 + 0x7d);
            uVar2 = *(u8 *)(param_3 + 0x7e);
            uVar3 = *(u8 *)(param_3 + 0x7f);
            *puVar8 = *(u8 *)(param_3 + 0x7c);
            puVar8[1] = uVar1;
            puVar8[2] = uVar2;
            puVar8[3] = uVar3;
          } while (iVar7 < param_2 + -8);
        }
      }
      for (; iVar7 < param_2; iVar7 = iVar7 + 1) {
        uVar1 = *(u8 *)(param_3 + 0x7d);
        uVar2 = *(u8 *)(param_3 + 0x7e);
        uVar3 = *(u8 *)(param_3 + 0x7f);
        *puVar6 = *(u8 *)(param_3 + 0x7c);
        puVar6[1] = uVar1;
        puVar6[2] = uVar2;
        puVar6[3] = uVar3;
        puVar6 = puVar6 + iVar4;
      }
    }
  }
  return;
}

// FUN_00477A20 NONMATCHING

void FUN_00477a20(u32 *param_1,int param_2,int param_3)

{
  u8 uVar1;
  u8 uVar2;
  u8 uVar3;
  int iVar4;
  int iVar5;
  u8 bVar6;
  u8 *puVar7;
  u8 *puVar8;
  u8 *puVar9;
  u8 *puVar10;
  u8 *puVar11;
  u8 *puVar12;
  u8 *puVar13;
  u8 *puVar14;
  u8 *puVar15;
  u8 *puVar16;
  u8 *puVar17;
  u8 *puVar18;
  u8 *puVar19;
  u8 *puVar20;
  int iVar21;
  u8 *puVar22;
  u8 *puVar23;
  
  iVar4 = param_1[1];
  iVar5 = *(int *)(param_3 + 0x28);
  puVar9 = *(u8 **)(param_3 + 0x24);
  puVar10 = (u8 *)*param_1;
  if (iVar5 == iVar4) {
    ((code)FUN_00476c20)(puVar10,puVar9,param_2 * iVar4);
  }
  else {
    iVar21 = 0;
    if (0 < param_2) {
      if (8 < param_2) {
        bVar6 = 0;
        if ((-1 < param_2) && (param_2 < 0x7fffffff)) {
          bVar6 = 1;
        }
        if (bVar6) {
          do {
            puVar19 = puVar9 + iVar5;
            uVar1 = puVar9[1];
            puVar23 = puVar19 + iVar5;
            uVar2 = puVar9[2];
            puVar20 = puVar10 + iVar4;
            uVar3 = puVar9[3];
            puVar18 = puVar20 + iVar4;
            puVar22 = puVar18 + iVar4;
            puVar17 = puVar23 + iVar5;
            puVar15 = puVar17 + iVar5;
            puVar16 = puVar22 + iVar4;
            puVar13 = puVar15 + iVar5;
            puVar14 = puVar16 + iVar4;
            puVar11 = puVar13 + iVar5;
            puVar12 = puVar14 + iVar4;
            puVar7 = puVar11 + iVar5;
            iVar21 = iVar21 + 8;
            *puVar10 = *puVar9;
            puVar8 = puVar12 + iVar4;
            puVar10[1] = uVar1;
            puVar9 = puVar7 + iVar5;
            puVar10[2] = uVar2;
            puVar10[3] = uVar3;
            uVar1 = puVar19[1];
            uVar2 = puVar19[2];
            uVar3 = puVar19[3];
            *puVar20 = *puVar19;
            puVar20[1] = uVar1;
            puVar20[2] = uVar2;
            puVar20[3] = uVar3;
            uVar1 = puVar23[1];
            uVar2 = puVar23[2];
            uVar3 = puVar23[3];
            *puVar18 = *puVar23;
            puVar18[1] = uVar1;
            puVar18[2] = uVar2;
            puVar18[3] = uVar3;
            uVar1 = puVar17[1];
            uVar2 = puVar17[2];
            uVar3 = puVar17[3];
            *puVar22 = *puVar17;
            puVar22[1] = uVar1;
            puVar22[2] = uVar2;
            puVar22[3] = uVar3;
            uVar1 = puVar15[1];
            uVar2 = puVar15[2];
            uVar3 = puVar15[3];
            *puVar16 = *puVar15;
            puVar16[1] = uVar1;
            puVar16[2] = uVar2;
            puVar16[3] = uVar3;
            uVar1 = puVar13[1];
            uVar2 = puVar13[2];
            uVar3 = puVar13[3];
            *puVar14 = *puVar13;
            puVar14[1] = uVar1;
            puVar14[2] = uVar2;
            puVar14[3] = uVar3;
            uVar1 = puVar11[1];
            uVar2 = puVar11[2];
            uVar3 = puVar11[3];
            *puVar12 = *puVar11;
            puVar12[1] = uVar1;
            puVar12[2] = uVar2;
            puVar12[3] = uVar3;
            uVar1 = puVar7[1];
            uVar2 = puVar7[2];
            uVar3 = puVar7[3];
            *puVar8 = *puVar7;
            puVar8[1] = uVar1;
            puVar8[2] = uVar2;
            puVar8[3] = uVar3;
            puVar10 = puVar8 + iVar4;
          } while (iVar21 < param_2 + -8);
        }
      }
      for (; iVar21 < param_2; iVar21 = iVar21 + 1) {
        uVar1 = puVar9[1];
        uVar2 = puVar9[2];
        uVar3 = puVar9[3];
        *puVar10 = *puVar9;
        puVar9 = puVar9 + iVar5;
        puVar10[1] = uVar1;
        puVar10[2] = uVar2;
        puVar10[3] = uVar3;
        puVar10 = puVar10 + iVar4;
      }
    }
  }
  return;
}

// FUN_00477C90 NONMATCHING

void FUN_00477c90(int *param_1,int param_2,int param_3)

{
  int iVar1;
  u8 bVar2;
  u32 *puVar3;
  u32 *puVar4;
  u32 *puVar5;
  u32 *puVar6;
  u32 *puVar7;
  u32 *puVar8;
  u32 *puVar9;
  u32 *puVar10;
  u32 *puVar11;
  u32 *puVar12;
  int iVar13;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  puVar12 = (u32 *)(param_3 + 0x90);
  iVar1 = param_1[1];
  puVar11 = (u32 *)*param_1;
  puVar10 = (u32 *)(param_3 + 0x98);
  if (iVar1 == 0x10) {
    uStack_10 = *(u32 *)(param_3 + 0x90);
    uStack_c = *(u32 *)(param_3 + 0x94);
    uStack_8 = *(u32 *)(param_3 + 0x98);
    uStack_4 = *(u32 *)(param_3 + 0x9c);
    ((code)FUN_00476720)(puVar11,param_2 * 0x10,&uStack_10);
  }
  else {
    iVar13 = 0;
    if (0 < param_2) {
      if (8 < param_2) {
        bVar2 = 0;
        if ((-1 < param_2) && (param_2 < 0x7fffffff)) {
          bVar2 = 1;
        }
        if (bVar2) {
          do {
            puVar9 = (u32 *)((int)puVar11 + iVar1);
            puVar8 = (u32 *)((int)puVar9 + iVar1);
            iVar13 = iVar13 + 8;
            puVar7 = (u32 *)((int)puVar8 + iVar1);
            puVar6 = (u32 *)((int)puVar7 + iVar1);
            puVar5 = (u32 *)((int)puVar6 + iVar1);
            puVar4 = (u32 *)((int)puVar5 + iVar1);
            *puVar11 = *puVar12;
            puVar3 = (u32 *)((int)puVar4 + iVar1);
            puVar11[1] = *(u32 *)(param_3 + 0x94);
            puVar11[2] = *puVar10;
            puVar11[3] = *(u32 *)(param_3 + 0x9c);
            puVar11 = (u32 *)((int)puVar3 + iVar1);
            *puVar9 = *puVar12;
            puVar9[1] = *(u32 *)(param_3 + 0x94);
            puVar9[2] = *puVar10;
            puVar9[3] = *(u32 *)(param_3 + 0x9c);
            *puVar8 = *puVar12;
            puVar8[1] = *(u32 *)(param_3 + 0x94);
            puVar8[2] = *puVar10;
            puVar8[3] = *(u32 *)(param_3 + 0x9c);
            *puVar7 = *puVar12;
            puVar7[1] = *(u32 *)(param_3 + 0x94);
            puVar7[2] = *puVar10;
            puVar7[3] = *(u32 *)(param_3 + 0x9c);
            *puVar6 = *puVar12;
            puVar6[1] = *(u32 *)(param_3 + 0x94);
            puVar6[2] = *puVar10;
            puVar6[3] = *(u32 *)(param_3 + 0x9c);
            *puVar5 = *puVar12;
            puVar5[1] = *(u32 *)(param_3 + 0x94);
            puVar5[2] = *puVar10;
            puVar5[3] = *(u32 *)(param_3 + 0x9c);
            *puVar4 = *puVar12;
            puVar4[1] = *(u32 *)(param_3 + 0x94);
            puVar4[2] = *puVar10;
            puVar4[3] = *(u32 *)(param_3 + 0x9c);
            *puVar3 = *puVar12;
            puVar3[1] = *(u32 *)(param_3 + 0x94);
            puVar3[2] = *puVar10;
            puVar3[3] = *(u32 *)(param_3 + 0x9c);
          } while (iVar13 < param_2 + -8);
        }
      }
      for (; iVar13 < param_2; iVar13 = iVar13 + 1) {
        *puVar11 = *puVar12;
        puVar11[1] = *(u32 *)(param_3 + 0x94);
        puVar11[2] = *puVar10;
        puVar11[3] = *(u32 *)(param_3 + 0x9c);
        puVar11 = (u32 *)((int)puVar11 + iVar1);
      }
    }
  }
  return;
}

// FUN_00477EB0 NONMATCHING

void FUN_00477eb0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  u8 bVar3;
  int iVar4;
  u32 *puVar5;
  u32 *puVar6;
  u32 *puVar7;
  u32 *puVar8;
  u32 *puVar9;
  u32 *puVar10;
  u32 *puVar11;
  u32 *puVar12;
  u32 *puVar13;
  u32 *puVar14;
  u32 *puVar15;
  u32 *puVar16;
  u32 *puVar17;
  u32 *puVar18;
  u32 *puVar19;
  u32 *puVar20;
  
  puVar6 = (u32 *)*param_1;
  iVar1 = *(int *)(param_3 + 0x40);
  iVar2 = param_1[1];
  puVar5 = *(u32 **)(param_3 + 0x3c);
  if (iVar1 == iVar2) {
    ((code)FUN_00476c20)(puVar6,puVar5,param_2 * iVar2);
  }
  else {
    iVar4 = 0;
    if (0 < param_2) {
      if (8 < param_2) {
        bVar3 = 0;
        if ((-1 < param_2) && (param_2 < 0x7fffffff)) {
          bVar3 = 1;
        }
        if (bVar3) {
          do {
            puVar17 = (u32 *)((int)puVar5 + iVar1);
            puVar18 = (u32 *)((int)puVar6 + iVar2);
            puVar15 = (u32 *)((int)puVar17 + iVar1);
            puVar16 = (u32 *)((int)puVar18 + iVar2);
            puVar13 = (u32 *)((int)puVar15 + iVar1);
            puVar14 = (u32 *)((int)puVar16 + iVar2);
            puVar19 = (u32 *)((int)puVar13 + iVar1);
            puVar20 = (u32 *)((int)puVar14 + iVar2);
            puVar11 = (u32 *)((int)puVar19 + iVar1);
            puVar12 = (u32 *)((int)puVar20 + iVar2);
            puVar9 = (u32 *)((int)puVar11 + iVar1);
            *puVar6 = *puVar5;
            puVar10 = (u32 *)((int)puVar12 + iVar2);
            iVar4 = iVar4 + 8;
            puVar7 = (u32 *)((int)puVar9 + iVar1);
            puVar8 = (u32 *)((int)puVar10 + iVar2);
            puVar6[1] = puVar5[1];
            puVar6[2] = puVar5[2];
            puVar6[3] = puVar5[3];
            puVar5 = (u32 *)((int)puVar7 + iVar1);
            puVar6 = (u32 *)((int)puVar8 + iVar2);
            *puVar18 = *puVar17;
            puVar18[1] = puVar17[1];
            puVar18[2] = puVar17[2];
            puVar18[3] = puVar17[3];
            *puVar16 = *puVar15;
            puVar16[1] = puVar15[1];
            puVar16[2] = puVar15[2];
            puVar16[3] = puVar15[3];
            *puVar14 = *puVar13;
            puVar14[1] = puVar13[1];
            puVar14[2] = puVar13[2];
            puVar14[3] = puVar13[3];
            *puVar20 = *puVar19;
            puVar20[1] = puVar19[1];
            puVar20[2] = puVar19[2];
            puVar20[3] = puVar19[3];
            *puVar12 = *puVar11;
            puVar12[1] = puVar11[1];
            puVar12[2] = puVar11[2];
            puVar12[3] = puVar11[3];
            *puVar10 = *puVar9;
            puVar10[1] = puVar9[1];
            puVar10[2] = puVar9[2];
            puVar10[3] = puVar9[3];
            *puVar8 = *puVar7;
            puVar8[1] = puVar7[1];
            puVar8[2] = puVar7[2];
            puVar8[3] = puVar7[3];
          } while (iVar4 < param_2 + -8);
        }
      }
      for (; iVar4 < param_2; iVar4 = iVar4 + 1) {
        *puVar6 = *puVar5;
        puVar6[1] = puVar5[1];
        puVar6[2] = puVar5[2];
        puVar6[3] = puVar5[3];
        puVar5 = (u32 *)((int)puVar5 + iVar1);
        puVar6 = (u32 *)((int)puVar6 + iVar2);
      }
    }
  }
  return;
}

// FUN_00478100 NONMATCHING

void FUN_00478100(int *param_1,int param_2,int param_3)

{
  int iVar1;
  u8 bVar2;
  u32 *puVar3;
  u32 *puVar4;
  u32 *puVar5;
  u32 *puVar6;
  u32 *puVar7;
  u32 *puVar8;
  u32 *puVar9;
  u32 *puVar10;
  int iVar11;
  u32 uVar12;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar1 = param_1[1];
  puVar10 = (u32 *)*param_1;
  if (iVar1 == 8) {
    uStack_8 = *(u32 *)(param_3 + 0x70);
    uStack_4 = *(u32 *)(param_3 + 0x74);
    ((code)FUN_00476490)(puVar10,param_2 * 8,&uStack_8);
  }
  else {
    iVar11 = 0;
    if (0 < param_2) {
      if (8 < param_2) {
        bVar2 = 0;
        if ((-1 < param_2) && (param_2 < 0x7fffffff)) {
          bVar2 = 1;
        }
        if (bVar2) {
          do {
            puVar9 = (u32 *)((int)puVar10 + iVar1);
            uVar12 = *(u32 *)(param_3 + 0x74);
            puVar8 = (u32 *)((int)puVar9 + iVar1);
            puVar7 = (u32 *)((int)puVar8 + iVar1);
            iVar11 = iVar11 + 8;
            puVar6 = (u32 *)((int)puVar7 + iVar1);
            puVar5 = (u32 *)((int)puVar6 + iVar1);
            puVar4 = (u32 *)((int)puVar5 + iVar1);
            puVar3 = (u32 *)((int)puVar4 + iVar1);
            *puVar10 = *(u32 *)(param_3 + 0x70);
            puVar10[1] = uVar12;
            puVar10 = (u32 *)((int)puVar3 + iVar1);
            uVar12 = *(u32 *)(param_3 + 0x74);
            *puVar9 = *(u32 *)(param_3 + 0x70);
            puVar9[1] = uVar12;
            uVar12 = *(u32 *)(param_3 + 0x74);
            *puVar8 = *(u32 *)(param_3 + 0x70);
            puVar8[1] = uVar12;
            uVar12 = *(u32 *)(param_3 + 0x74);
            *puVar7 = *(u32 *)(param_3 + 0x70);
            puVar7[1] = uVar12;
            uVar12 = *(u32 *)(param_3 + 0x74);
            *puVar6 = *(u32 *)(param_3 + 0x70);
            puVar6[1] = uVar12;
            uVar12 = *(u32 *)(param_3 + 0x74);
            *puVar5 = *(u32 *)(param_3 + 0x70);
            puVar5[1] = uVar12;
            uVar12 = *(u32 *)(param_3 + 0x74);
            *puVar4 = *(u32 *)(param_3 + 0x70);
            puVar4[1] = uVar12;
            uVar12 = *(u32 *)(param_3 + 0x74);
            *puVar3 = *(u32 *)(param_3 + 0x70);
            puVar3[1] = uVar12;
          } while (iVar11 < param_2 + -8);
        }
      }
      for (; iVar11 < param_2; iVar11 = iVar11 + 1) {
        uVar12 = *(u32 *)(param_3 + 0x74);
        *puVar10 = *(u32 *)(param_3 + 0x70);
        puVar10[1] = uVar12;
        puVar10 = (u32 *)((int)puVar10 + iVar1);
      }
    }
  }
  return;
}

// FUN_00478280 NONMATCHING

void FUN_00478280(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  u8 bVar3;
  int iVar4;
  u32 *puVar5;
  u32 *puVar6;
  u32 *puVar7;
  u32 *puVar8;
  u32 *puVar9;
  u32 *puVar10;
  u32 *puVar11;
  u32 *puVar12;
  u32 *puVar13;
  u32 *puVar14;
  u32 *puVar15;
  u32 *puVar16;
  u32 *puVar17;
  u32 *puVar18;
  u32 *puVar19;
  u32 uVar20;
  
  puVar6 = (u32 *)*param_1;
  iVar1 = *(int *)(param_3 + 0x20);
  iVar2 = param_1[1];
  puVar5 = *(u32 **)(param_3 + 0x1c);
  if (iVar1 == iVar2) {
    ((code)FUN_00476c20)(puVar6,puVar5,param_2 * iVar2);
  }
  else {
    iVar4 = 0;
    if (0 < param_2) {
      if (8 < param_2) {
        bVar3 = 0;
        if ((-1 < param_2) && (param_2 < 0x7fffffff)) {
          bVar3 = 1;
        }
        if (bVar3) {
          do {
            puVar17 = (u32 *)((int)puVar6 + iVar2);
            uVar20 = puVar5[1];
            puVar16 = (u32 *)((int)puVar17 + iVar2);
            puVar14 = (u32 *)((int)puVar16 + iVar2);
            iVar4 = iVar4 + 8;
            puVar19 = (u32 *)((int)puVar14 + iVar2);
            puVar12 = (u32 *)((int)puVar19 + iVar2);
            puVar10 = (u32 *)((int)puVar12 + iVar2);
            puVar8 = (u32 *)((int)puVar10 + iVar2);
            *puVar6 = *puVar5;
            puVar5 = (u32 *)((int)puVar5 + iVar1);
            puVar6[1] = uVar20;
            puVar15 = (u32 *)((int)puVar5 + iVar1);
            puVar13 = (u32 *)((int)puVar15 + iVar1);
            uVar20 = puVar5[1];
            puVar18 = (u32 *)((int)puVar13 + iVar1);
            puVar11 = (u32 *)((int)puVar18 + iVar1);
            puVar6 = (u32 *)((int)puVar8 + iVar2);
            puVar9 = (u32 *)((int)puVar11 + iVar1);
            puVar7 = (u32 *)((int)puVar9 + iVar1);
            *puVar17 = *puVar5;
            puVar5 = (u32 *)((int)puVar7 + iVar1);
            puVar17[1] = uVar20;
            uVar20 = puVar15[1];
            *puVar16 = *puVar15;
            puVar16[1] = uVar20;
            uVar20 = puVar13[1];
            *puVar14 = *puVar13;
            puVar14[1] = uVar20;
            uVar20 = puVar18[1];
            *puVar19 = *puVar18;
            puVar19[1] = uVar20;
            uVar20 = puVar11[1];
            *puVar12 = *puVar11;
            puVar12[1] = uVar20;
            uVar20 = puVar9[1];
            *puVar10 = *puVar9;
            puVar10[1] = uVar20;
            uVar20 = puVar7[1];
            *puVar8 = *puVar7;
            puVar8[1] = uVar20;
          } while (iVar4 < param_2 + -8);
        }
      }
      for (; iVar4 < param_2; iVar4 = iVar4 + 1) {
        uVar20 = puVar5[1];
        *puVar6 = *puVar5;
        puVar5 = (u32 *)((int)puVar5 + iVar1);
        puVar6[1] = uVar20;
        puVar6 = (u32 *)((int)puVar6 + iVar2);
      }
    }
  }
  return;
}

// FUN_00478440 NONMATCHING

u32 FUN_00478440(int param_1,u32 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x2c);
  iVar2 = *(int *)(param_1 + 8);
  iVar3 = *(int *)(iVar2 + DAT_007ce770);
  iVar4 = *(int *)(iVar3 + 0x9c);
  *(u32 *)(*(int *)(iVar4 + 0xe4) * 0x24 + iVar4 + 0x140) = param_2[3];
  *(u32 *)(*(int *)(iVar4 + 0xe4) * 0x24 + iVar4 + 0x150) = *param_2;
  *(u32 *)(*(int *)(iVar4 + 0xe4) * 0x24 + iVar4 + 0x14c) = param_2[1];
  *(u32 *)(*(int *)(iVar4 + 0xe4) * 0x24 + iVar4 + 0x15c) = param_2[2];
  **(code **)(iVar3 + 0x24) = (code)FUN_00477470;
  ((code)FUN_004861b0)(iVar2,iVar3 + 0x50,*(u32 *)(iVar1 + 4),0xffffffffefffffff);
  **(code **)(iVar3 + 0x24) = (code)FUN_00477150;
  return 1;
}

// FUN_00478520 NONMATCHING



u64 FUN_00478520(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  u32 uVar8;
  Vec128 auVar9;
  Vec128 auVar10;
  Vec128 auVar11;
  Vec128 auVar12;
  Vec128 auVar13;
  Vec128 auVar14;
  float *pfVar15;
  int iVar16;
  u32 uVar17;
  u64 uVar18;
  u64 uVar19;
  u64 uVar20;
  long lVar21;
  u64 extraout_v0_udw;
  u32 uVar31;
  u64 extraout_v0_udw_00;
  Vec128 auVar22;
  Vec128 auVar23;
  Vec128 auVar24;
  Vec128 auVar25;
  Vec128 auVar26;
  u64 extraout_v0_udw_01;
  Vec128 auVar27;
  Vec128 auVar28;
  u64 extraout_v0_udw_02;
  Vec128 auVar29;
  Vec128 auVar30;
  u64 in_v1_udw;
  Vec128 auVar32;
  Vec128 auVar33;
  Vec128 auVar34;
  Vec128 auVar35;
  Vec128 auVar36;
  u64 in_a0_udw;
  float fVar37;
  Vec128 auVar38;
  u32 uVar41;
  Vec128 auVar39;
  Vec128 auVar40;
  u64 in_a2_udw;
  Vec128 auVar42;
  int iVar43;
  float fVar44;
  
  iVar16 = DAT_00960070;
  iVar2 = *(int *)(param_1 + 8);
  iVar3 = *(int *)(param_1 + 4);
  iVar4 = *(int *)(DAT_00960070 + 0x60);
  iVar5 = *(int *)(iVar3 + 0x1f8);
  iVar6 = *(int *)(*(int *)(iVar2 + DAT_007ce770) + 4);
  iVar7 = *(int *)(*(int *)(iVar2 + DAT_007ce770) + 0x9c);
  fVar1 = (float)((iVar6 + iVar5 + -1) / iVar5);
  if ((*(int *)(iVar7 + 0xdc) == 1) &&
     ((iVar5 = **(int **)(param_1 + 0x30), iVar6 != *(int *)(iVar5 + 0x24) ||
      (*(float *)(iVar5 + 0x34) != fVar1)))) {
    *(int *)(iVar5 + 0x24) = iVar6;
    *(float *)(iVar5 + 0x34) = fVar1;
    ((code)FUN_0049dc70)(param_1);
    iVar5 = *(int *)(param_1 + 0x40);
  }
  else {
    iVar5 = *(int *)(param_1 + 0x40);
  }
  ((code)FUN_004749a0)(*(int *)(iVar2 + DAT_007ce770) + 0x50);
  ((code)FUN_004748c0)(*(int *)(iVar2 + DAT_007ce770) + 0x50,*(u32 *)(param_1 + 0x40));
  uVar18 = *(u64 *)(iVar7 + 0xb8);
  uVar17 = (u32)extraout_v0_udw;
  uVar31 = (u32)((u32)extraout_v0_udw >> 0x20);
  uVar19 = *(u64 *)(iVar7 + 200);
  uVar20 = *(u64 *)(iVar7 + 0xc0);
  lVar21 = ((code)FUN_004d59d0)(0,0xc);
  pfVar15 = (float *)DAT_007ce9f4;
  if (lVar21 == 0) {
    uVar18 = 0;
  }
  else {
    auVar32._8_8_ = in_v1_udw;
    auVar32._0_8_ = 0x6c0a03c601000404;
    auVar22._8_8_ = extraout_v0_udw_00;
    auVar22._0_8_ = 0x1000000a;
    auVar38 = _pcpyld(auVar32,auVar22);
    *DAT_007ce9f4 = (*(u32*)((u8*)&auVar38 + 0));
    pfVar15[1] = auVar38._4_4_;
    pfVar15[2] = auVar38._8_4_;
    pfVar15[3] = auVar38._12_4_;
    pfVar15 = (float *)DAT_007ce9f4;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    iVar43 = *(int *)(iVar4 + 0x10);
    fVar44 = *(float *)(iVar16 + 0x74);
    fVar37 = (float)(iVar6 - ((int)fVar1 + -1) * *(int *)(iVar3 + 0x1f8));
    uVar41 = CONCAT44(fVar37,fVar1);
    *DAT_007ce9f4 = -((float)*(int *)(iVar4 + 0xc) * *(float *)(iVar16 + 0x70) * 0.25);
    pfVar15[5] = -((float)iVar43 * fVar44 * 0.25);
    pfVar15[6] = fVar1;
    pfVar15[7] = fVar37;
    auVar38 = _DAT_00965910;
    pfVar15[8] = *(float *)&_DAT_00965910._0_4_;
    pfVar15[9] = auVar38._4_4_;
    pfVar15[10] = auVar38._8_4_;
    pfVar15[0xb] = auVar38._12_4_;
    auVar9 = _DAT_00965920;
    pfVar15[0xc] = DAT_00965920;
    pfVar15[0xd] = auVar9._4_4_;
    pfVar15[0xe] = auVar9._8_4_;
    pfVar15[0xf] = auVar9._12_4_;
    pfVar15 = (float *)DAT_007ce9f4;
    auVar23._8_8_ = auVar9._8_8_;
    DAT_007ce9f4 = DAT_007ce9f4 + 0xc;
    auVar33._8_8_ = auVar38._8_8_;
    auVar42._8_8_ = in_a2_udw;
    auVar42._0_8_ = 0x42412;
    auVar23._0_8_ =
         ((u32)(((u32)(iVar5 != 0) << 4 |
                   (u32)(*(int *)(*(int *)(iVar2 + DAT_007ce770) + 0xb4) == 1) << 6 | 0x200 |
                   (u32)((*(u8 *)(param_1 + 0x28) & 1) == 1) << 5 | 0xe) << 0xf) | 0x50004000) <<
         0x20;
    auVar38 = _pcpyld(auVar42,auVar23);
    *DAT_007ce9f4 = (*(u32*)((u8*)&auVar38 + 0));
    pfVar15[0xd] = auVar38._4_4_;
    pfVar15[0xe] = auVar38._8_4_;
    pfVar15[0xf] = auVar38._12_4_;
    auVar24._8_8_ = auVar38._8_8_;
    auVar24._0_8_ = 0x1000000000008005;
    auVar38._8_8_ = in_a0_udw;
    auVar38._0_8_ = 0xe;
    auVar38 = _pcpyld(auVar38,auVar24);
    pfVar15[0x10] = auVar38._0_4_;
    pfVar15[0x11] = auVar38._4_4_;
    pfVar15[0x12] = auVar38._8_4_;
    pfVar15[0x13] = auVar38._12_4_;
    auVar33._0_8_ = 0x43;
    auVar14._8_4_ = uVar17;
    auVar14._0_8_ = uVar18;
    auVar14._12_4_ = uVar31;
    auVar38 = _pcpyld(auVar33,auVar14);
    pfVar15[0x14] = auVar38._0_4_;
    pfVar15[0x15] = auVar38._4_4_;
    pfVar15[0x16] = auVar38._8_4_;
    pfVar15[0x17] = auVar38._12_4_;
    auVar34._8_8_ = auVar33._8_8_;
    auVar34._0_8_ = 9;
    auVar12._8_4_ = uVar17;
    auVar12._0_8_ = uVar20;
    auVar12._12_4_ = uVar31;
    auVar38 = _pcpyld(auVar34,auVar12);
    pfVar15[0x18] = auVar38._0_4_;
    pfVar15[0x19] = auVar38._4_4_;
    pfVar15[0x1a] = auVar38._8_4_;
    pfVar15[0x1b] = auVar38._12_4_;
    auVar35._8_8_ = auVar33._8_8_;
    auVar35._0_8_ = 0x48;
    auVar13._8_4_ = uVar17;
    auVar13._0_8_ = uVar19;
    auVar13._12_4_ = uVar31;
    auVar38 = _pcpyld(auVar35,auVar13);
    pfVar15[0x1c] = auVar38._0_4_;
    pfVar15[0x1d] = auVar38._4_4_;
    pfVar15[0x1e] = auVar38._8_4_;
    pfVar15[0x1f] = auVar38._12_4_;
    pfVar15 = (float *)DAT_007ce9f4;
    auVar25._8_8_ = auVar38._8_8_;
    DAT_007ce9f4 = DAT_007ce9f4 + 0x14;
    auVar25._0_8_ = *(u64 *)(iVar7 + 0xd0);
    auVar9._8_8_ = in_a0_udw;
    auVar9._0_8_ = 0x15;
    auVar38 = _pcpyld(auVar9,auVar25);
    auVar36._8_8_ = auVar33._8_8_;
    auVar36._0_8_ = 0x4f;
    *DAT_007ce9f4 = (*(u32*)((u8*)&auVar38 + 0));
    pfVar15[0x15] = auVar38._4_4_;
    pfVar15[0x16] = auVar38._8_4_;
    pfVar15[0x17] = auVar38._12_4_;
    auVar26._8_8_ = auVar38._8_8_;
    auVar26._0_8_ = DAT_007cea30;
    auVar38 = _pcpyld(auVar36,auVar26);
    pfVar15[0x18] = auVar38._0_4_;
    pfVar15[0x19] = auVar38._4_4_;
    pfVar15[0x1a] = auVar38._8_4_;
    pfVar15[0x1b] = auVar38._12_4_;
    DAT_007ce9f4 = DAT_007ce9f4 + 8;
    ((code)FUN_004d59d0)(0,5);
    pfVar15 = (float *)DAT_007ce9f4;
    auVar11._8_8_ = 0;
    auVar11._0_8_ = auVar33._8_8_;
    auVar27._8_8_ = extraout_v0_udw_01;
    auVar27._0_8_ = 0x10000002;
    auVar38 = _pcpyld(auVar11 << 0x40,auVar27);
    auVar39._8_8_ = 0;
    auVar39._0_8_ = uVar41;
    auVar39._0_8_ = auVar39._0_8_ << 0x40;
    auVar28._8_8_ = extraout_v0_udw_01;
    auVar28._0_8_ = 0x6c0103fb01000404;
    *DAT_007ce9f4 = (*(u32*)((u8*)&auVar38 + 0));
    pfVar15[1] = auVar38._4_4_;
    pfVar15[2] = auVar38._8_4_;
    pfVar15[3] = auVar38._12_4_;
    auVar38 = _pcpyld(auVar28,auVar39);
    pfVar15[4] = auVar38._0_4_;
    pfVar15[5] = auVar38._4_4_;
    pfVar15[6] = auVar38._8_4_;
    pfVar15[7] = auVar38._12_4_;
    DAT_007ce9f4 = DAT_007ce9f4 + 8;
    if (iVar5 != 0) {
      uVar17 = 0x3b011b50;
    }
    else {
      uVar17 = 0x3b808081;
    }
    ((code)FUN_0049cab0)(uVar17,param_1 + 0x44);
    if ((*(int *)(iVar7 + 0xdc) == 1) ||
       ((*(int **)(iVar2 + DAT_007ce770))[1] == **(int **)(iVar2 + DAT_007ce770))) {
      if ((*(u8 *)(param_1 + 0x28) & 1) == 1) {
        *(u8 *)(param_1 + 0x2b) = 0;
      }
      else {
        *(u8 *)(param_1 + 0x2b) = 1;
      }
    }
    else if ((*(u8 *)(param_1 + 0x28) & 1) == 1) {
      *(u8 *)(param_1 + 0x2b) = 2;
    }
    else {
      *(u8 *)(param_1 + 0x2b) = 3;
    }
    pfVar15 = (float *)DAT_007ce9f4;
    uVar8 = *(u32 *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + (u32)*(u8 *)(param_1 + 0x2b) * 4);
    if (DAT_007ceaf8 != uVar8) {
      auVar10._8_8_ = 0;
      auVar10._0_8_ = auVar39._8_8_;
      auVar39._0_8_ = auVar10._0_8_ << 0x40;
      auVar29._0_8_ = (u32)uVar8 << 0x20 | 0x50000000;
      auVar29._8_8_ = extraout_v0_udw_02;
      auVar38 = _pcpyld(auVar39,auVar29);
      *DAT_007ce9f4 = (*(u32*)((u8*)&auVar38 + 0));
      pfVar15[1] = auVar38._4_4_;
      pfVar15[2] = auVar38._8_4_;
      pfVar15[3] = auVar38._12_4_;
      DAT_007ce9f4 = DAT_007ce9f4 + 4;
      DAT_007ceaf8 = uVar8;
    }
    pfVar15 = (float *)DAT_007ce9f4;
    auVar40._8_8_ = auVar39._8_8_;
    iVar2 = **(int **)(param_1 + 0x30);
    auVar40._0_8_ = ((long)*(int *)(*(int *)(param_1 + 4) + 0x14) | 0x2000000U) << 0x20 | 0x3000000;
    auVar30._0_8_ = (u32)*(u32 *)(iVar2 + 0x20) << 0x20 | 0x50000000;
    auVar30._8_8_ = extraout_v0_udw_02;
    auVar38 = _pcpyld(auVar40,auVar30);
    *DAT_007ce9f4 = (*(u32*)((u8*)&auVar38 + 0));
    pfVar15[1] = auVar38._4_4_;
    pfVar15[2] = auVar38._8_4_;
    pfVar15[3] = auVar38._12_4_;
    DAT_007ce9f4 = DAT_007ce9f4 + 4;
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + 1;
    EI();
    *(int *)(iVar2 + 0x1c) = *(int *)(iVar2 + 0x1c) + 1;
    if (*(int *)(iVar2 + 0x1c) == 1) {
      ((code)FUN_004d51c0)();
    }
    uVar18 = 1;
  }
  return uVar18;
}

// FUN_00478A70 NONMATCHING

u64 FUN_00478a70(void)

{
  long lVar1;
  u64 uVar2;
  u64 uVar3;
  
  lVar1 = ((code)FUN_004f2f70)();
  uVar2 = 0;
  if (lVar1 != 0) {
    uVar2 = ((code)FUN_004f4640)(lVar1);
    lVar1 = ((code)FUN_004a3f10)();
    if (lVar1 == 0) {
      uVar2 = 0;
    }
    else {
      ((code)FUN_004f4950)(uVar2,0,lVar1,0);
      uVar3 = ((code)FUN_004f4830)(uVar2,*(u32 *)lVar1,0,0);
      ((code)FUN_00521250)(0x95d3d0,0x77e2e0,0x10);
      DAT_0095d3a8 = 0x6c000000;
      DAT_0095d3d8 = DAT_0095d3d8 | 0xd;
      ((code)FUN_00521250)(0x95d3c0,0x77e2c0,0x10);
      DAT_0095d3c8 = DAT_0095d3c8 & 0xffffdfff | 0xd;
      ((code)FUN_00521250)(0x95d3b0,0x77e2e0,0x10);
      DAT_0095d3b8 = 0x6400000d;
      ((code)FUN_00521250)(0x95d3a0,0x77e2f0,0x10);
      DAT_0095d3a8 = 0x6c00000d;
      ((code)FUN_004a35c0)(uVar3,0x95d3d0,8);
      ((code)FUN_004a35c0)(uVar3,0x95d3c0,4);
      ((code)FUN_004a35c0)(uVar3,0x95d3b0,6);
      ((code)FUN_004a35c0)(uVar3,0x95d3a0,7);
      ((code)FUN_004a3c10)(uVar3,4,0x35);
      uVar2 = ((code)FUN_004f3f80)(uVar2);
      uVar3 = ((code)FUN_004f4830)(uVar2,*(u32 *)lVar1,0,0);
      ((code)FUN_004a3d70)(uVar3,0xd4);
      ((code)FUN_004a3db0)(uVar3,0x77b1e0,4);
      ((code)FUN_004a3e30)(uVar3,2,0x4a0ce0);
      ((code)FUN_004a3e30)(uVar3,3,0x478440);
      ((code)FUN_004a3e30)(uVar3,4,0x478520);
    }
  }
  return uVar2;
}

// FUN_00478CC0 NONMATCHING

void FUN_00478cc0(int param_1,u32 *param_2)

{
  u32 uVar1;
  float *pfVar2;
  int *piVar3;
  int iVar4;
  float *pfVar5;
  u8 bVar6;
  int iVar7;
  u32 *puVar8;
  
  iVar7 = *(int *)(param_1 + 8);
  iVar4 = *(int *)(iVar7 + 0x18);
  puVar8 = (u32 *)(DAT_00960070 + 0x20);
  *(u32 *)(param_1 + 0xc) = *(u32 *)(iVar4 + 0x54);
  piVar3 = (int *)(iVar4 + iGpffffbba0);
  bVar6 = 0;
  if (((u32 *)*piVar3 != (u32 *)0x0) &&
     ((u32)*(u16 *)(*(int *)(iVar4 + 0x54) + 4) == *(u32 *)*piVar3)) {
    bVar6 = 1;
  }
  if (bVar6) {
    iVar4 = *piVar3;
  }
  else {
    piVar3 = (int *)((code)FUN_0049e5a0)(piVar3,*(u16 *)(*(int *)(iVar4 + 0x54) + 4));
    iVar4 = *piVar3;
  }
  *(int *)(param_1 + 0x10) = iVar4;
  iVar4 = 8;
  *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) & 0xfffffffe;
  param_2 = (u32 *)*param_2;
  do {
    iVar4 = iVar4 + -1;
    uVar1 = puVar8[1];
    *param_2 = *puVar8;
    puVar8 = puVar8 + 2;
    param_2[1] = uVar1;
    param_2 = param_2 + 2;
  } while (0 < iVar4);
  iVar4 = 2;
  pfVar2 = (float *)((code)FUN_004912b0)(iVar7);
  iVar7 = 5;
  pfVar5 = (float *)(DAT_00960070 + iGpffffbdb4 + 0x60);
  do {
    if (-pfVar2[3] < (pfVar2[2] * pfVar5[2] + *pfVar2 * *pfVar5 + pfVar2[1] * pfVar5[1]) - pfVar5[3]
       ) {
      iVar4 = 1;
      break;
    }
    pfVar5 = pfVar5 + 5;
    bVar6 = iVar7 != 0;
    iVar7 = iVar7 + -1;
  } while (bVar6);
  *(u8 *)(param_1 + 0x29) = 4;
  *(u8 *)(param_1 + 0x28) = uGpffffbe04;
  if (iVar4 != 2) {
    *(u8 *)(param_1 + 0x28) = *(u8 *)(param_1 + 0x28) | 2;
  }
  *(u8 *)(param_1 + 0x2a) = 1;
  return;
}

// FUN_00478E80 NONMATCHING

u32 FUN_00478e80(u64 param_1,u32 param_2)

{
  int iVar1;
  u16 uVar2;
  u32 uVar3;
  u32 *puVar4;
  u32 uVar5;
  long lVar6;
  long lVar7;
  u64 uVar8;
  int iVar9;
  
  lVar6 = ((code)FUN_00493710)(0,0,0);
  if (lVar6 == 0) {
    uVar5 = 0;
  }
  else {
    iVar9 = (int)lVar6;
    iVar1 = *(int *)(iVar9 + 0x5c);
    *(u32 *)(iVar1 + 4) = 0;
    *(u32 *)(iVar1 + 8) = 0;
    *(u32 *)(iVar1 + 0xc) = 0;
    *(u32 *)(iVar1 + 0x10) = 0x3f800000;
    lVar7 = ((code)FUN_004933d0)(lVar6);
    if (lVar7 == 0) {
      uVar5 = 0;
    }
    else {
      uVar8 = ((code)FUN_00494be0)();
      uVar3 = (u32)uVar8;
      *(u32 *)(uVar3 + 0xc) = 0x3e99999a;
      *(u32 *)(uVar3 + 0x10) = 0x3f800000;
      *(u32 *)(uVar3 + 0x14) = 0x3f800000;
      puVar4 = (u32 *)((code)FUN_004959c0)(0x1c);
      *puVar4 = *puVar4 & 0xffffff00 | (u32)*(u8 *)((int)(u8 *)DAT_0096009c + iGpffffbb60 + 1);
      *puVar4 = *puVar4 | 0x100;
      *(u16 *)(puVar4 + 1) = 1;
      uVar2 = ((code)FUN_00496580)();
      *(u16 *)((int)puVar4 + 6) = uVar2;
      puVar4[3] = 0;
      puVar4[2] = 0;
      puVar4[5] = param_2;
      puVar4[4] = 0;
      puVar4[6] = uVar3;
      *(u32 **)(iVar9 + 0x54) = puVar4;
      *(u32 *)(puVar4[6] + 8) =
           *(u32 *)(*(int *)((int)(u8 *)DAT_00960070 + iGpffffba84) + 4);
      if (puVar4[6] == 0) {
        uVar5 = 0;
      }
      else {
        ((code)FUN_00495340)(iVar9 + 0x20,uVar8);
        ((code)FUN_00494cc0)(uVar8);
        ((code)FUN_004919b0)(param_1,lVar6,0);
        *(u32 *)((int)param_1 + 0x6c) =
             *(u32 *)(*(int *)((int)(u8 *)DAT_00960070 + iGpffffba84) + 8);
        ((code)FUN_00493b60)(lVar6);
        uVar5 = 1;
      }
    }
  }
  return uVar5;
}

// FUN_00479030 NONMATCHING

u8 FUN_00479030(int param_1)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  long lVar4;
  u64 uVar5;
  u64 uVar6;
  
  uVar2 = ((code)FUN_00478a70)();
  *(u32 *)(param_1 + 4) = uVar2;
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == 0) {
    return 0;
  }
  lVar3 = ((code)FUN_004f2f70)();
  if (lVar3 != 0) {
    lVar4 = ((code)FUN_004f4640)(lVar3);
    if (lVar4 != 0) {
      uVar5 = ((code)FUN_0049ff00)();
      uVar6 = ((code)FUN_004f4950)(lVar4,0,uVar5,0);
      ((code)FUN_004f4830)(uVar6,*(u32 *)uVar5,0,0);
      lVar4 = ((code)FUN_004f3f80)(uVar6);
      if (lVar4 != 0) {
        uVar5 = ((code)FUN_004f4830)(lVar4,*(u32 *)uVar5,0,0);
        ((code)FUN_0049fe40)(uVar5,1,0x478cc0);
        ((code)FUN_0049fec0)(uVar5,iVar1);
        goto LAB_00479114;
      }
    }
    ((code)FUN_004f3010)(lVar3);
  }
  lVar3 = 0;
LAB_00479114:
  *(int *)(param_1 + 8) = (int)lVar3;
  return *(int *)(param_1 + 8) != 0;
}

// FUN_00479170 NONMATCHING

void FUN_00479170(int *param_1,int param_2,u64 param_3,u64 param_4,u32 param_5)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  int *piVar5;
  u8 bVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  int iVar10;
  int iVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  
  pfVar9 = (float *)(param_1 + 0xc);
  iVar7 = (int)param_3;
  iVar1 = *(int *)(iVar7 + 0x4c);
  pfVar8 = (float *)(param_1 + 0xf);
  if (*(int *)(iVar1 + 0xe0) == 1) {
    iVar4 = *(int *)(iVar1 + 0xe4);
    *(int *)(iVar1 + 0xe4) = iVar4 + 1;
    if (*(int *)(iVar1 + 0xe8) < *(int *)(iVar1 + 0xe4)) {
      *(u32 *)(iVar1 + 0xe4) = 0;
    }
    piVar5 = (int *)(*(int *)(param_2 + 0x18) + iGpffffbba0);
    bVar6 = 0;
    if (((int *)*piVar5 != (int *)0x0) && (*(int *)*piVar5 == 1)) {
      bVar6 = 1;
    }
    if (bVar6) {
      iVar10 = *(int *)(iVar1 + 0xe4);
    }
    else {
      piVar5 = (int *)((code)FUN_0049e5a0)(piVar5,1);
      iVar10 = *(int *)(iVar1 + 0xe4);
    }
    iVar11 = *piVar5;
    iVar2 = *(int *)(iVar11 + 4);
    iVar10 = *(int *)(iVar10 * 4 + iVar1 + 0x138);
    *(int *)(iVar11 + 4) = iVar10;
    if (iVar10 != 0) {
      *(int *)(*(int *)(iVar11 + 4) + 0x10) = iVar11 + 4;
      *(u32 *)(*(int *)(iVar1 + 0xe4) * 4 + iVar1 + 0x138) = 0;
    }
    iVar4 = iVar4 * 4 + iVar1;
    *(int *)(iVar4 + 0x138) = iVar2;
    piVar5 = (int *)(iVar4 + 0x138);
    if (iVar2 != 0) {
      *(int **)(*piVar5 + 0x10) = piVar5;
    }
  }
  iVar4 = *(int *)(iVar1 + 0xe4);
  if ((param_5 & 0x10000000) == 0) {
    iVar10 = *(int *)(param_2 + 0x18);
  }
  else {
    ((code)FUN_00474a80)(param_3);
    iVar10 = *(int *)(param_2 + 0x18);
  }
  piVar5 = (int *)(iVar10 + iGpffffbba0);
  bVar6 = 0;
  if (((int *)*piVar5 != (int *)0x0) && (*(int *)*piVar5 == 1)) {
    bVar6 = 1;
  }
  if (bVar6) {
    iVar10 = *piVar5;
  }
  else {
    piVar5 = (int *)((code)FUN_0049e5a0)(piVar5,1);
    iVar10 = *piVar5;
  }
  if (*(int *)(iVar10 + 4) == 0) {
    param_1[2] = 0;
    param_1[1] = 0;
    *param_1 = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[8] = 0;
    param_1[9] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    param_1[10] = 0;
    param_1[0xb] = 0;
  }
  else {
    pfVar3 = (float *)((code)FUN_004cb2f0)(*(u32 *)(DAT_00960070 + 4));
    if ((*(u32 *)(iVar7 + 0x58) & 0x8000) == 0x8000) {
      iVar10 = *(int *)(iVar7 + 0xb4);
      iVar11 = *(int *)(iVar7 + 0xb8);
      *pfVar9 = *(float *)(iVar7 + 0xb0);
      param_1[0xd] = iVar10;
      param_1[0xe] = iVar11;
      iVar10 = *(int *)(iVar7 + 0xc4);
      iVar11 = *(int *)(iVar7 + 200);
      *pfVar8 = *(float *)(iVar7 + 0xc0);
      param_1[0x10] = iVar10;
      param_1[0x11] = iVar11;
    }
    else if ((*(u32 *)(iVar7 + 0x58) & 0x20000) == 0x20000) {
      fVar15 = *pfVar3;
      fVar12 = pfVar3[2];
      fVar20 = pfVar3[4];
      fVar18 = pfVar3[5];
      fVar19 = pfVar3[6];
      fVar17 = -pfVar3[1];
      fVar13 = (float)((code)FUN_0052e878)(*(u32 *)(iVar7 + 0x78));
      fVar14 = (float)((code)FUN_0052e6d8)(*(u32 *)(iVar7 + 0x78));
      fVar16 = -fVar13;
      *pfVar9 = fVar14 * -fVar15 + fVar16 * fVar20;
      param_1[0xd] = (int)(fVar14 * fVar17 + fVar16 * fVar18);
      param_1[0xe] = (int)(fVar14 * -fVar12 + fVar16 * fVar19);
      *pfVar8 = fVar13 * -fVar15 + fVar14 * fVar20;
      param_1[0x10] = (int)(fVar13 * fVar17 + fVar14 * fVar18);
      param_1[0x11] = (int)(fVar13 * -fVar12 + fVar14 * fVar19);
    }
    else {
      *pfVar9 = -*pfVar3;
      param_1[0xd] = (int)-pfVar3[1];
      param_1[0xe] = (int)-pfVar3[2];
      *pfVar8 = pfVar3[4];
      param_1[0x10] = (int)pfVar3[5];
      param_1[0x11] = (int)pfVar3[6];
    }
    ((code)FUN_004d5e90)();
    param_1[2] = (u32)((param_5 & 0xfffffffffffbdfbd) != 0);
    param_1[1] = (u32)((param_5 & 0xffffffffffe7fe7f) != 0);
    *param_1 = 1;
    if (*param_1 != 0) {
      param_1[4] = *(int *)(iVar4 * 0x24 + iVar1 + 0x140);
      param_1[5] = 0x10;
    }
    if (param_1[2] != 0) {
      param_1[8] = *(int *)(iVar4 * 0x24 + iVar1 + 0x154);
      param_1[9] = 4;
    }
    if (param_1[1] != 0) {
      param_1[6] = *(int *)(iVar4 * 0x24 + iVar1 + 0x160);
      param_1[7] = 8;
    }
  }
  return;
}

// FUN_00479590 NONMATCHING

void FUN_00479590(int *param_1,u64 param_2,u64 param_3,u64 param_4,
                 u32 param_5)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  
  iVar3 = (int)param_3;
  pfVar5 = (float *)(param_1 + 0xc);
  iVar1 = *(int *)(iVar3 + 0x4c);
  pfVar4 = (float *)(param_1 + 0xf);
  pfVar2 = (float *)((code)FUN_004cb2f0)(*(u32 *)(DAT_00960070 + 4));
  if ((*(u32 *)(iVar3 + 0x58) & 0x8000) == 0x8000) {
    iVar6 = *(int *)(iVar3 + 0xb4);
    iVar7 = *(int *)(iVar3 + 0xb8);
    *pfVar5 = *(float *)(iVar3 + 0xb0);
    param_1[0xd] = iVar6;
    param_1[0xe] = iVar7;
    iVar6 = *(int *)(iVar3 + 0xc4);
    iVar7 = *(int *)(iVar3 + 200);
    *pfVar4 = *(float *)(iVar3 + 0xc0);
    param_1[0x10] = iVar6;
    param_1[0x11] = iVar7;
  }
  else if ((*(u32 *)(iVar3 + 0x58) & 0x20000) == 0x20000) {
    fVar11 = *pfVar2;
    fVar8 = pfVar2[2];
    fVar16 = pfVar2[4];
    fVar14 = pfVar2[5];
    fVar15 = pfVar2[6];
    fVar13 = -pfVar2[1];
    fVar9 = (float)((code)FUN_0052e878)(*(u32 *)(iVar3 + 0x78));
    fVar10 = (float)((code)FUN_0052e6d8)(*(u32 *)(iVar3 + 0x78));
    fVar12 = -fVar9;
    *pfVar5 = fVar10 * -fVar11 + fVar12 * fVar16;
    param_1[0xd] = (int)(fVar10 * fVar13 + fVar12 * fVar14);
    param_1[0xe] = (int)(fVar10 * -fVar8 + fVar12 * fVar15);
    *pfVar4 = fVar9 * -fVar11 + fVar10 * fVar16;
    param_1[0x10] = (int)(fVar9 * fVar13 + fVar10 * fVar14);
    param_1[0x11] = (int)(fVar9 * -fVar8 + fVar10 * fVar15);
  }
  else {
    *pfVar5 = -*pfVar2;
    param_1[0xd] = (int)-pfVar2[1];
    param_1[0xe] = (int)-pfVar2[2];
    *pfVar4 = pfVar2[4];
    param_1[0x10] = (int)pfVar2[5];
    param_1[0x11] = (int)pfVar2[6];
  }
  iVar3 = *(int *)(iVar1 + 0xe4);
  if ((param_5 & 0x10000000) != 0) {
    ((code)FUN_00474a80)(param_3);
  }
  ((code)FUN_004d5e90)();
  param_1[2] = (u32)((param_5 & 0xfffffffffffbdfbd) != 0);
  param_1[1] = (u32)((param_5 & 0xffffffffffe7fe7f) != 0);
  *param_1 = 1;
  if (*param_1 != 0) {
    param_1[4] = *(int *)(iVar3 * 0x24 + iVar1 + 0x140);
    param_1[5] = 0x10;
  }
  if (param_1[2] != 0) {
    param_1[8] = *(int *)(iVar3 * 0x24 + iVar1 + 0x154);
    param_1[9] = 4;
  }
  if (param_1[1] != 0) {
    param_1[6] = *(int *)(iVar3 * 0x24 + iVar1 + 0x160);
    param_1[7] = 8;
  }
  return;
}

// FUN_00479840 NONMATCHING

u32 FUN_00479840(int param_1,u32 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x2c);
  iVar2 = *(int *)(param_1 + 8);
  iVar3 = *(int *)(iVar2 + iGpffffba80);
  iVar4 = *(int *)(iVar3 + 0x9c);
  *(u32 *)(*(int *)(iVar4 + 0xe4) * 0x24 + iVar4 + 0x140) = param_2[1];
  *(u32 *)(*(int *)(iVar4 + 0xe4) * 0x24 + iVar4 + 0x154) = *param_2;
  *(u32 *)(*(int *)(iVar4 + 0xe4) * 0x24 + iVar4 + 0x160) = param_2[2];
  **(code **)(iVar3 + 0x24) = (code)FUN_00479590;
  ((code)FUN_004861b0)(iVar2,iVar3 + 0x50,*(u32 *)(iVar1 + 4) >> 2,0xffffffffefffffff);
  **(code **)(iVar3 + 0x24) = (code)FUN_00479170;
  return 1;
}

// FUN_00479900 NONMATCHING



u64 FUN_00479900(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  u32 uVar7;
  Vec128 auVar8;
  Vec128 auVar9;
  Vec128 auVar10;
  Vec128 auVar11;
  Vec128 auVar12;
  Vec128 auVar13;
  int iVar14;
  u32 uVar15;
  u64 uVar16;
  u64 uVar17;
  u64 uVar18;
  long lVar19;
  u64 extraout_v0_udw;
  u32 uVar29;
  u64 extraout_v0_udw_00;
  Vec128 auVar20;
  Vec128 auVar21;
  Vec128 auVar22;
  Vec128 auVar23;
  Vec128 auVar24;
  u64 extraout_v0_udw_01;
  Vec128 auVar25;
  Vec128 auVar26;
  u64 extraout_v0_udw_02;
  Vec128 auVar27;
  Vec128 auVar28;
  u64 in_v1_udw;
  Vec128 auVar30;
  Vec128 auVar31;
  Vec128 auVar32;
  Vec128 auVar33;
  Vec128 auVar34;
  u64 in_a0_udw;
  Vec128 auVar35;
  Vec128 auVar36;
  u32 uVar39;
  Vec128 auVar37;
  Vec128 auVar38;
  int iVar40;
  int iVar41;
  float fVar42;
  
  iVar14 = DAT_00960070;
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 4);
  iVar3 = *(int *)(DAT_00960070 + 0x60);
  iVar4 = *(int *)(iVar2 + 0x1f8);
  iVar5 = *(int *)(*(int *)(iVar1 + iGpffffba80) + 0x9c);
  iVar40 = *(int *)(*(int *)(iVar1 + iGpffffba80) + 4) * 4;
  iVar4 = (iVar40 + iVar4 + -1) / iVar4;
  if ((*(int *)(iVar5 + 0xdc) == 1) &&
     ((iVar6 = **(int **)(param_1 + 0x30), iVar40 != *(int *)(iVar6 + 0x24) ||
      (*(int *)(iVar6 + 0x34) != iVar4)))) {
    *(int *)(iVar6 + 0x24) = iVar40;
    *(int *)(iVar6 + 0x34) = iVar4;
    ((code)FUN_0049dc70)(param_1);
    iVar6 = *(int *)(param_1 + 0x40);
  }
  else {
    iVar6 = *(int *)(param_1 + 0x40);
  }
  ((code)FUN_004749a0)(*(int *)(iVar1 + iGpffffba80) + 0x50);
  ((code)FUN_004748c0)(*(int *)(iVar1 + iGpffffba80) + 0x50,*(u32 *)(param_1 + 0x40));
  uVar16 = *(u64 *)(iVar5 + 0xb8);
  uVar15 = (u32)extraout_v0_udw;
  uVar29 = (u32)((u32)extraout_v0_udw >> 0x20);
  uVar17 = *(u64 *)(iVar5 + 200);
  uVar18 = *(u64 *)(iVar5 + 0xc0);
  lVar19 = ((code)FUN_004d59d0)(0,0xc);
  if (lVar19 == 0) {
    uVar16 = 0;
  }
  else {
    auVar30._8_8_ = in_v1_udw;
    auVar30._0_8_ = 0x6c0a03c601000404;
    auVar20._8_8_ = extraout_v0_udw_00;
    auVar20._0_8_ = 0x1000000a;
    auVar35 = _pcpyld(auVar30,auVar20);
    *puGpffffbd04 = auVar35._0_4_;
    puGpffffbd04[1] = auVar35._4_4_;
    puGpffffbd04[2] = auVar35._8_4_;
    puGpffffbd04[3] = auVar35._12_4_;
    iVar41 = *(int *)(iVar3 + 0x10);
    fVar42 = *(float *)(iVar14 + 0x74);
    iVar40 = iVar40 - (iVar4 + -1) * *(int *)(iVar2 + 0x1f8);
    uVar39 = CONCAT44(iVar40,iVar4);
    puGpffffbd04[4] = -((float)*(int *)(iVar3 + 0xc) * *(float *)(iVar14 + 0x70) * 0.5);
    puGpffffbd04[5] = -((float)iVar41 * fVar42 * 0.5);
    puGpffffbd04[6] = iVar4;
    puGpffffbd04[7] = iVar40;
    auVar35 = _DAT_00965910;
    puGpffffbd04[8] = (u32)(DAT_00965910);
    puGpffffbd04[9] = auVar35._4_4_;
    puGpffffbd04[10] = auVar35._8_4_;
    puGpffffbd04[0xb] = auVar35._12_4_;
    auVar8 = _DAT_00965920;
    puGpffffbd04[0xc] = DAT_00965920;
    puGpffffbd04[0xd] = auVar8._4_4_;
    puGpffffbd04[0xe] = auVar8._8_4_;
    puGpffffbd04[0xf] = auVar8._12_4_;
    auVar21._8_8_ = auVar8._8_8_;
    auVar31._8_8_ = auVar35._8_8_;
    auVar36._8_8_ = uVar39;
    auVar36._0_8_ = 0x412;
    auVar21._0_8_ =
         ((u32)(((u32)(iVar6 != 0) << 4 |
                   (u32)(*(int *)(*(int *)(iVar1 + iGpffffba80) + 0xb4) == 1) << 6 | 0x200 |
                   (u32)((*(u8 *)(param_1 + 0x28) & 1) == 1) << 5 | 0xc) << 0xf) | 0x30004000) <<
         0x20;
    auVar35 = _pcpyld(auVar36,auVar21);
    puGpffffbd04[0x10] = auVar35._0_4_;
    puGpffffbd04[0x11] = auVar35._4_4_;
    puGpffffbd04[0x12] = auVar35._8_4_;
    puGpffffbd04[0x13] = auVar35._12_4_;
    auVar22._8_8_ = auVar35._8_8_;
    auVar22._0_8_ = 0x1000000000008005;
    auVar35._8_8_ = in_a0_udw;
    auVar35._0_8_ = 0xe;
    auVar35 = _pcpyld(auVar35,auVar22);
    puGpffffbd04[0x14] = auVar35._0_4_;
    puGpffffbd04[0x15] = auVar35._4_4_;
    puGpffffbd04[0x16] = auVar35._8_4_;
    puGpffffbd04[0x17] = auVar35._12_4_;
    auVar31._0_8_ = 0x43;
    auVar13._8_4_ = uVar15;
    auVar13._0_8_ = uVar16;
    auVar13._12_4_ = uVar29;
    auVar35 = _pcpyld(auVar31,auVar13);
    puGpffffbd04[0x18] = auVar35._0_4_;
    puGpffffbd04[0x19] = auVar35._4_4_;
    puGpffffbd04[0x1a] = auVar35._8_4_;
    puGpffffbd04[0x1b] = auVar35._12_4_;
    auVar32._8_8_ = auVar31._8_8_;
    auVar32._0_8_ = 9;
    auVar11._8_4_ = uVar15;
    auVar11._0_8_ = uVar18;
    auVar11._12_4_ = uVar29;
    auVar35 = _pcpyld(auVar32,auVar11);
    puGpffffbd04[0x1c] = auVar35._0_4_;
    puGpffffbd04[0x1d] = auVar35._4_4_;
    puGpffffbd04[0x1e] = auVar35._8_4_;
    puGpffffbd04[0x1f] = auVar35._12_4_;
    auVar33._8_8_ = auVar31._8_8_;
    auVar33._0_8_ = 0x48;
    auVar12._8_4_ = uVar15;
    auVar12._0_8_ = uVar17;
    auVar12._12_4_ = uVar29;
    auVar35 = _pcpyld(auVar33,auVar12);
    puGpffffbd04[0x20] = auVar35._0_4_;
    puGpffffbd04[0x21] = auVar35._4_4_;
    puGpffffbd04[0x22] = auVar35._8_4_;
    puGpffffbd04[0x23] = auVar35._12_4_;
    auVar23._8_8_ = auVar35._8_8_;
    auVar23._0_8_ = *(u64 *)(iVar5 + 0xd0);
    auVar8._8_8_ = in_a0_udw;
    auVar8._0_8_ = 0x15;
    auVar35 = _pcpyld(auVar8,auVar23);
    auVar34._8_8_ = auVar31._8_8_;
    auVar34._0_8_ = 0x4f;
    puGpffffbd04[0x24] = auVar35._0_4_;
    puGpffffbd04[0x25] = auVar35._4_4_;
    puGpffffbd04[0x26] = auVar35._8_4_;
    puGpffffbd04[0x27] = auVar35._12_4_;
    auVar24._8_8_ = auVar35._8_8_;
    auVar24._0_8_ = uGpffffbd40;
    auVar35 = _pcpyld(auVar34,auVar24);
    puGpffffbd04[0x28] = auVar35._0_4_;
    puGpffffbd04[0x29] = auVar35._4_4_;
    puGpffffbd04[0x2a] = auVar35._8_4_;
    puGpffffbd04[0x2b] = auVar35._12_4_;
    puGpffffbd04 = puGpffffbd04 + 0x2c;
    ((code)FUN_004d59d0)(0,5);
    auVar10._8_8_ = 0;
    auVar10._0_8_ = auVar31._8_8_;
    auVar25._8_8_ = extraout_v0_udw_01;
    auVar25._0_8_ = 0x10000002;
    auVar35 = _pcpyld(auVar10 << 0x40,auVar25);
    auVar37._8_8_ = 0;
    auVar37._0_8_ = uVar39;
    auVar37._0_8_ = auVar37._0_8_ << 0x40;
    auVar26._8_8_ = extraout_v0_udw_01;
    auVar26._0_8_ = 0x6c0103fb01000404;
    *puGpffffbd04 = auVar35._0_4_;
    puGpffffbd04[1] = auVar35._4_4_;
    puGpffffbd04[2] = auVar35._8_4_;
    puGpffffbd04[3] = auVar35._12_4_;
    auVar35 = _pcpyld(auVar26,auVar37);
    puGpffffbd04[4] = auVar35._0_4_;
    puGpffffbd04[5] = auVar35._4_4_;
    puGpffffbd04[6] = auVar35._8_4_;
    puGpffffbd04[7] = auVar35._12_4_;
    puGpffffbd04 = puGpffffbd04 + 8;
    if (iVar6 != 0) {
      uVar15 = 0x3b011b50;
    }
    else {
      uVar15 = 0x3b808081;
    }
    ((code)FUN_0049cab0)(uVar15,param_1 + 0x44);
    if ((*(int *)(iVar5 + 0xdc) == 1) ||
       ((*(int **)(iVar1 + iGpffffba80))[1] == **(int **)(iVar1 + iGpffffba80))) {
      if ((*(u8 *)(param_1 + 0x28) & 1) == 1) {
        *(u8 *)(param_1 + 0x2b) = 0;
      }
      else {
        *(u8 *)(param_1 + 0x2b) = 1;
      }
    }
    else if ((*(u8 *)(param_1 + 0x28) & 1) == 1) {
      *(u8 *)(param_1 + 0x2b) = 2;
    }
    else {
      *(u8 *)(param_1 + 0x2b) = 3;
    }
    uVar7 = *(u32 *)(*(int *)(*(int *)(param_1 + 4) + 0x18) + (u32)*(u8 *)(param_1 + 0x2b) * 4);
    if (uGpffffbe08 != uVar7) {
      auVar9._8_8_ = 0;
      auVar9._0_8_ = auVar37._8_8_;
      auVar37._0_8_ = auVar9._0_8_ << 0x40;
      auVar27._0_8_ = (u32)uVar7 << 0x20 | 0x50000000;
      auVar27._8_8_ = extraout_v0_udw_02;
      auVar35 = _pcpyld(auVar37,auVar27);
      *puGpffffbd04 = auVar35._0_4_;
      puGpffffbd04[1] = auVar35._4_4_;
      puGpffffbd04[2] = auVar35._8_4_;
      puGpffffbd04[3] = auVar35._12_4_;
      puGpffffbd04 = puGpffffbd04 + 4;
      uGpffffbe08 = uVar7;
    }
    auVar38._8_8_ = auVar37._8_8_;
    iVar4 = **(int **)(param_1 + 0x30);
    auVar38._0_8_ = ((long)*(int *)(*(int *)(param_1 + 4) + 0x14) | 0x2000000U) << 0x20 | 0x3000000;
    auVar28._0_8_ = (u32)*(u32 *)(iVar4 + 0x20) << 0x20 | 0x50000000;
    auVar28._8_8_ = extraout_v0_udw_02;
    auVar35 = _pcpyld(auVar38,auVar28);
    *puGpffffbd04 = auVar35._0_4_;
    puGpffffbd04[1] = auVar35._4_4_;
    puGpffffbd04[2] = auVar35._8_4_;
    puGpffffbd04[3] = auVar35._12_4_;
    puGpffffbd04 = puGpffffbd04 + 4;
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + 1;
    EI();
    *(int *)(iVar4 + 0x1c) = *(int *)(iVar4 + 0x1c) + 1;
    if (*(int *)(iVar4 + 0x1c) == 1) {
      ((code)FUN_004d51c0)();
    }
    uVar16 = 1;
  }
  return uVar16;
}

// FUN_00479E50 NONMATCHING

u64 FUN_00479e50(void)

{
  long lVar1;
  u64 uVar2;
  u64 uVar3;
  
  lVar1 = ((code)FUN_004f2f70)();
  uVar2 = 0;
  if (lVar1 != 0) {
    uVar2 = ((code)FUN_004f4640)(lVar1);
    lVar1 = ((code)FUN_004a3f10)();
    if (lVar1 == 0) {
      uVar2 = 0;
    }
    else {
      ((code)FUN_004f4950)(uVar2,0,lVar1,0);
      uVar3 = ((code)FUN_004f4830)(uVar2,*(u32 *)lVar1,0,0);
      ((code)FUN_00521250)(0x95d400,0x77e290,0x10);
      DAT_0095d408 = 0x6c00000d;
      ((code)FUN_00521250)(0x95d3f0,0x77e2c0,0x10);
      DAT_0095d3f8 = DAT_0095d3f8 & 0xffffdfff | 0xd;
      ((code)FUN_00521250)(0x95d3e0,0x77e2f0,0x10);
      DAT_0095d3e8 = 0x6400000d;
      ((code)FUN_004a35c0)(uVar3,0x95d3f0,4);
      ((code)FUN_004a35c0)(uVar3,0x95d400,6);
      ((code)FUN_004a35c0)(uVar3,0x95d3e0,7);
      ((code)FUN_004a3c10)(uVar3,3,0x50);
      uVar2 = ((code)FUN_004f3f80)(uVar2);
      uVar3 = ((code)FUN_004f4830)(uVar2,*(u32 *)lVar1,0,0);
      ((code)FUN_004a3d70)(uVar3,0xf0);
      ((code)FUN_004a3db0)(uVar3,0x77b1f0,4);
      ((code)FUN_004a3e30)(uVar3,2,0x4a0ce0);
      ((code)FUN_004a3e30)(uVar3,3,0x479840);
      ((code)FUN_004a3e30)(uVar3,4,0x479900);
    }
  }
  return uVar2;
}

// FUN_0047A050 NONMATCHING

void FUN_0047a050(int param_1,u32 *param_2)

{
  u32 uVar1;
  float *pfVar2;
  int *piVar3;
  int iVar4;
  float *pfVar5;
  u8 bVar6;
  int iVar7;
  u32 *puVar8;
  
  iVar7 = *(int *)(param_1 + 8);
  iVar4 = *(int *)(iVar7 + 0x18);
  puVar8 = (u32 *)(DAT_00960070 + 0x20);
  *(u32 *)(param_1 + 0xc) = *(u32 *)(iVar4 + 0x54);
  piVar3 = (int *)(iVar4 + iGpffffbba0);
  bVar6 = 0;
  if (((u32 *)*piVar3 != (u32 *)0x0) &&
     ((u32)*(u16 *)(*(int *)(iVar4 + 0x54) + 4) == *(u32 *)*piVar3)) {
    bVar6 = 1;
  }
  if (bVar6) {
    iVar4 = *piVar3;
  }
  else {
    piVar3 = (int *)((code)FUN_0049e5a0)(piVar3,*(u16 *)(*(int *)(iVar4 + 0x54) + 4));
    iVar4 = *piVar3;
  }
  *(int *)(param_1 + 0x10) = iVar4;
  iVar4 = 8;
  *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) & 0xfffffffe;
  param_2 = (u32 *)*param_2;
  do {
    iVar4 = iVar4 + -1;
    uVar1 = puVar8[1];
    *param_2 = *puVar8;
    puVar8 = puVar8 + 2;
    param_2[1] = uVar1;
    param_2 = param_2 + 2;
  } while (0 < iVar4);
  iVar4 = 2;
  pfVar2 = (float *)((code)FUN_004912b0)(iVar7);
  iVar7 = 5;
  pfVar5 = (float *)(DAT_00960070 + iGpffffbdb4 + 0x60);
  do {
    if (-pfVar2[3] < (pfVar2[2] * pfVar5[2] + *pfVar2 * *pfVar5 + pfVar2[1] * pfVar5[1]) - pfVar5[3]
       ) {
      iVar4 = 1;
      break;
    }
    pfVar5 = pfVar5 + 5;
    bVar6 = iVar7 != 0;
    iVar7 = iVar7 + -1;
  } while (bVar6);
  *(u8 *)(param_1 + 0x29) = 4;
  *(u8 *)(param_1 + 0x28) = uGpffffbe04;
  if (iVar4 != 2) {
    *(u8 *)(param_1 + 0x28) = *(u8 *)(param_1 + 0x28) | 2;
  }
  *(u8 *)(param_1 + 0x2a) = 1;
  return;
}

// FUN_0047A210 NONMATCHING

u32 FUN_0047a210(u64 param_1,int param_2)

{
  int iVar1;
  u16 uVar2;
  u32 uVar3;
  u32 *puVar4;
  u32 uVar5;
  long lVar6;
  long lVar7;
  u64 uVar8;
  int iVar9;
  
  lVar6 = ((code)FUN_00493710)(0,0,0);
  if (lVar6 == 0) {
    uVar5 = 0;
  }
  else {
    iVar9 = (int)lVar6;
    iVar1 = *(int *)(iVar9 + 0x5c);
    *(u32 *)(iVar1 + 4) = 0;
    *(u32 *)(iVar1 + 8) = 0;
    *(u32 *)(iVar1 + 0xc) = 0;
    *(u32 *)(iVar1 + 0x10) = 0x3f800000;
    lVar7 = ((code)FUN_004933d0)(lVar6);
    if (lVar7 == 0) {
      uVar5 = 0;
    }
    else {
      uVar8 = ((code)FUN_00494be0)();
      uVar3 = (u32)uVar8;
      *(u32 *)(uVar3 + 0xc) = 0x3e99999a;
      *(u32 *)(uVar3 + 0x10) = 0x3f800000;
      *(u32 *)(uVar3 + 0x14) = 0x3f800000;
      puVar4 = (u32 *)((code)FUN_004959c0)(0x1c);
      *puVar4 = *puVar4 & 0xffffff00 | (u32)*(u8 *)((int)(u8 *)DAT_0096009c + iGpffffbb60 + 1);
      *puVar4 = *puVar4 | 0x100;
      *(u16 *)(puVar4 + 1) = 1;
      uVar2 = ((code)FUN_00496580)();
      *(u16 *)((int)puVar4 + 6) = uVar2;
      puVar4[3] = 0;
      puVar4[2] = 0;
      puVar4[5] = param_2 << 2;
      puVar4[4] = 0;
      puVar4[6] = uVar3;
      *(u32 **)(iVar9 + 0x54) = puVar4;
      *(u32 *)(puVar4[6] + 8) =
           *(u32 *)(*(int *)((int)(u8 *)DAT_00960070 + iGpffffba84) + 0xc);
      if (puVar4[6] == 0) {
        uVar5 = 0;
      }
      else {
        ((code)FUN_00495340)(iVar9 + 0x20,uVar8);
        ((code)FUN_00494cc0)(uVar8);
        ((code)FUN_004919b0)(param_1,lVar6,0);
        *(u32 *)((int)param_1 + 0x6c) =
             *(u32 *)(*(int *)((int)(u8 *)DAT_00960070 + iGpffffba84) + 0x10);
        ((code)FUN_00493b60)(lVar6);
        uVar5 = 1;
      }
    }
  }
  return uVar5;
}

// FUN_0047A3D0 NONMATCHING

u8 FUN_0047a3d0(int param_1)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  long lVar4;
  u64 uVar5;
  u64 uVar6;
  
  uVar2 = ((code)FUN_00479e50)();
  *(u32 *)(param_1 + 0xc) = uVar2;
  iVar1 = *(int *)(param_1 + 0xc);
  if (iVar1 == 0) {
    return 0;
  }
  lVar3 = ((code)FUN_004f2f70)();
  if (lVar3 != 0) {
    lVar4 = ((code)FUN_004f4640)(lVar3);
    if (lVar4 != 0) {
      uVar5 = ((code)FUN_0049ff00)();
      uVar6 = ((code)FUN_004f4950)(lVar4,0,uVar5,0);
      ((code)FUN_004f4830)(uVar6,*(u32 *)uVar5,0,0);
      lVar4 = ((code)FUN_004f3f80)(uVar6);
      if (lVar4 != 0) {
        uVar5 = ((code)FUN_004f4830)(lVar4,*(u32 *)uVar5,0,0);
        ((code)FUN_0049fe40)(uVar5,1,0x47a050);
        ((code)FUN_0049fec0)(uVar5,iVar1);
        goto LAB_0047a4b4;
      }
    }
    ((code)FUN_004f3010)(lVar3);
  }
  lVar3 = 0;
LAB_0047a4b4:
  *(int *)(param_1 + 0x10) = (int)lVar3;
  return *(int *)(param_1 + 0x10) != 0;
}

// FUN_0047A510 NONMATCHING

u32 FUN_0047a510(u64 param_1,u64 param_2,u64 param_3,u32 param_4)

{
  u8 uVar1;
  u8 uVar2;
  u8 uVar3;
  u32 uVar4;
  u8 *puVar5;
  u32 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  u32 uVar10;
  
  iVar9 = (int)param_2;
  iVar8 = *(int *)(iVar9 + 0x4c);
  if (*(int *)(iVar8 + 0xe0) == 1) {
    if (*(int *)(iVar8 + 0xe4) < *(int *)(iVar8 + 0xe8)) {
      iVar7 = *(int *)(iVar8 + 0xe4) + 1;
    }
    else {
      iVar7 = 0;
    }
    iVar7 = iVar7 * 4 + iVar8;
    *(u32 *)(iVar7 + 0xec) = *(u32 *)(iVar7 + 0xec) | param_4;
    iVar8 = *(int *)(iVar8 + 0xe4) * 4 + iVar8;
    uVar4 = *(u32 *)(iVar8 + 0xec);
    if (uVar4 != 0) {
      *(u32 *)(iVar8 + 0xec) = 0;
      param_4 = param_4 | uVar4;
    }
  }
  if (param_4 != 0) {
    if ((param_4 & 0x10000000) != 0) {
      ((code)FUN_00474a80)(param_2);
    }
    if (((param_4 & 0x80000) != 0) && ((*(u32 *)(iVar9 + 0x58) & 0x80000) != 0)) {
      ((code)FUN_00521250)(*(u32 *)(iVar9 + 0x3c),iVar9 + 0x90,0x10);
    }
    if (((param_4 & 0x100000) != 0) && ((*(u32 *)(iVar9 + 0x58) & 0x100000) != 0)) {
      ((code)FUN_00521250)(*(u32 *)(iVar9 + 0x44),iVar9 + 0x90,0x20);
    }
    if (((param_4 & 0x2000) != 0) && ((*(u32 *)(iVar9 + 0x58) & 0x40042) == 0)) {
      puVar5 = *(u8 **)(iVar9 + 0x24);
      uVar1 = *(u8 *)(iVar9 + 0x7d);
      uVar2 = *(u8 *)(iVar9 + 0x7e);
      uVar3 = *(u8 *)(iVar9 + 0x7f);
      *puVar5 = *(u8 *)(iVar9 + 0x7c);
      puVar5[1] = uVar1;
      puVar5[2] = uVar2;
      puVar5[3] = uVar3;
    }
    if (((param_4 & 0x40000) != 0) && ((*(u32 *)(iVar9 + 0x58) & 0x40000) != 0)) {
      ((code)FUN_00521250)(*(u32 *)(iVar9 + 0x2c),iVar9 + 0x80,0x10);
    }
    if (((param_4 & 0x20000) != 0) && ((*(u32 *)(iVar9 + 0x58) & 0x20000) != 0)) {
      puVar6 = *(u32 **)(iVar9 + 0x34);
      *puVar6 = *(u32 *)(iVar9 + 0x78);
      puVar6[1] = *(u32 *)(iVar9 + 0x78);
    }
    if (((param_4 & 0x4000) != 0) && ((*(u32 *)(iVar9 + 0x58) & 4) == 0)) {
      puVar6 = *(u32 **)(iVar9 + 0x1c);
      uVar10 = *(u32 *)(iVar9 + 0x74);
      *puVar6 = *(u32 *)(iVar9 + 0x70);
      puVar6[1] = uVar10;
    }
  }
  return 1;
}

// FUN_0047A710 NONMATCHING



u64 FUN_0047a710(u64 param_1,int *param_2)

{
  int iVar1;
  u8 bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  Vec128 auVar8;
  Vec128 auVar9;
  Vec128 auVar10;
  Vec128 auVar11;
  Vec128 auVar12;
  Vec128 auVar13;
  Vec128 auVar14;
  u32 uVar15;
  u32 uVar16;
  int iVar17;
  u32 uVar18;
  long lVar19;
  u64 uVar20;
  u64 extraout_v0_udw;
  Vec128 auVar21;
  Vec128 auVar22;
  Vec128 auVar23;
  Vec128 auVar24;
  u64 extraout_v0_udw_00;
  Vec128 auVar25;
  u32 *puVar26;
  u64 in_v1_udw;
  Vec128 auVar27;
  Vec128 auVar28;
  Vec128 auVar29;
  int iVar30;
  u32 uVar31;
  u32 in_a0_udw;
  Vec128 auVar33;
  Vec128 auVar34;
  Vec128 auVar35;
  Vec128 auVar36;
  Vec128 auVar37;
  u32 in_a1_udw;
  u32 in_register_0000005c;
  u32 *puVar38;
  Vec128 auVar39;
  Vec128 auVar40;
  u64 in_a3_udw;
  u64 in_t0_udw;
  u32 uVar41;
  u32 uVar42;
  u32 in_t3_udw;
  u32 uVar43;
  float fVar44;
  float fVar45;
  float fVar46;
  u32 auStack_40 [16];
  Vec128 auVar32;
  
  iVar17 = DAT_00960070;
  iVar3 = *param_2;
  iVar4 = *(int *)(DAT_00960070 + 0x60);
  iVar5 = *(int *)(iVar3 + iGpffffba80);
  iVar6 = *(int *)(iVar5 + 0x9c);
  iVar30 = *(int *)(*(int *)(iVar6 + 0xfc) + 0x10);
  iVar1 = (*(int *)(iVar5 + 4) + -1) / iVar30;
  uVar43 = *(int *)(iVar5 + 4) - iVar1 * iVar30;
  if (*(int *)(iVar6 + 0xdc) != 0) {
    puVar26 = *(u32 **)(*(int *)(iVar6 + 0xe4) * 0x20 + iVar6 + 0x18);
    *puVar26 = 0x10000000;
    puVar26[2] = 0;
    puVar26 = (u32 *)
              (*(int *)(*(int *)(iVar6 + 0xe4) * 0x20 + iVar6 + 0x1c) +
              (*(int *)(*(int *)(iVar6 + 0xfc) + 0x18) + 1) * iVar1 * 0x10);
    *puVar26 = 0x20000000;
    puVar26[2] = uVar43 | 0x4000000;
    *(u32 **)(*(int *)(iVar6 + 0xe4) * 0x20 + iVar6 + 0x18) = puVar26;
  }
  FlushCache(0);
  puVar38 = (u32 *)(iVar17 + 0x20);
  puVar26 = auStack_40;
  iVar30 = 8;
  do {
    iVar30 = iVar30 + -1;
    uVar18 = puVar38[1];
    *puVar26 = *puVar38;
    puVar38 = puVar38 + 2;
    puVar26[1] = uVar18;
    puVar26 = puVar26 + 2;
  } while (0 < iVar30);
  ((code)FUN_004ec2b0)(auStack_40,0,0);
  piVar7 = (int *)**(int **)(*(int *)(iVar3 + 0x18) + 0x20);
  iVar3 = *piVar7;
  ((code)FUN_004749a0)(iVar5 + 0x50,iVar3);
  ((code)FUN_004748c0)(iVar5 + 0x50,iVar3);
  lVar19 = ((code)FUN_004d59d0)(0,0x12);
  if (lVar19 == 0) {
    uVar20 = 0;
  }
  else {
    auVar27._8_8_ = in_v1_udw;
    auVar27._0_8_ = 0x6c0503eb01000101;
    auVar21._8_8_ = extraout_v0_udw;
    auVar21._0_8_ = 0x1000000f;
    auVar22 = _pcpyld(auVar27,auVar21);
    *puGpffffbd04 = auVar22._0_4_;
    puGpffffbd04[1] = auVar22._4_4_;
    puGpffffbd04[2] = auVar22._8_4_;
    puGpffffbd04[3] = auVar22._12_4_;
    bVar2 = *(u8 *)(iVar6 + 0xf5);
    uVar41 = (u32)*(u8 *)(iVar6 + 0xf6);
    uVar42 = (u32)*(u8 *)(iVar6 + 0xf7);
    auVar39._8_8_ = 0;
    auVar39._0_8_ = in_t3_udw;
    auVar22._8_4_ = in_a1_udw;
    auVar22._0_8_ = 0x6c0203fa01000101;
    auVar22._12_4_ = in_register_0000005c;
    auVar22 = _pcpyld(auVar22,auVar39 << 0x40);
    puGpffffbd04[4] = (u32)*(u8 *)(iVar6 + 0xf4);
    puGpffffbd04[5] = (u32)bVar2;
    puGpffffbd04[6] = uVar41;
    puGpffffbd04[7] = uVar42;
    fVar46 = *(float *)(iVar5 + 0xbc);
    fVar44 = *(float *)(iVar5 + 0xb8) * 2.0;
    fVar45 = fVar46 * 2.0;
    puGpffffbd04[8] = *(float *)(iVar5 + 0xb8);
    puGpffffbd04[9] = fVar46;
    puGpffffbd04[10] = fVar44;
    puGpffffbd04[0xb] = fVar45;
    iVar30 = *(int *)(iVar4 + 0x10);
    fVar46 = *(float *)(iVar17 + 0x74);
    puGpffffbd04[0xc] = (float)*(int *)(iVar4 + 0xc) * -0.25 * *(float *)(iVar17 + 0x70);
    puGpffffbd04[0xd] = (float)iVar30 * -0.25 * fVar46;
    puGpffffbd04[0xe] = iVar1 + 1;
    puGpffffbd04[0xf] = uVar43;
    uVar16 = DAT_0096591c;
    uVar15 = DAT_00965918;
    uVar18 = DAT_00965914;
    puGpffffbd04[0x10] = (u32)(DAT_00965910);
    puGpffffbd04[0x11] = uVar18;
    puGpffffbd04[0x12] = uVar15;
    puGpffffbd04[0x13] = uVar16;
    auVar23 = _DAT_00965920;
    puGpffffbd04[0x14] = DAT_00965920;
    puGpffffbd04[0x15] = auVar23._4_4_;
    puGpffffbd04[0x16] = auVar23._8_4_;
    puGpffffbd04[0x17] = auVar23._12_4_;
    puGpffffbd04[0x18] = auVar22._0_4_;
    puGpffffbd04[0x19] = auVar22._4_4_;
    puGpffffbd04[0x1a] = auVar22._8_4_;
    puGpffffbd04[0x1b] = auVar22._12_4_;
    uVar31 = **(u32 **)(iVar6 + 0xfc);
    if (iVar3 != 0) {
      auVar23._0_8_ = 0x8000000000000;
      uVar31 = uVar31 | 0x8000000000000;
    }
    auVar24._8_8_ = auVar23._8_8_;
    if ((uGpffffb0d0 & 0x20) != 0) {
      uVar31 = uVar31 | 0x10000000000000;
    }
    if (*(int *)(iVar5 + 0xb4) != 0) {
      uVar31 = uVar31 | 0x20000000000000;
    }
    auVar32._8_8_ = in_a0_udw;
    auVar32._0_8_ = uVar31;
    auVar24._0_8_ = (*(u32 **)(iVar6 + 0xfc))[1];
    auVar22 = _pcpyld(auVar24,auVar32);
    puGpffffbd04[0x1c] = auVar22._0_4_;
    puGpffffbd04[0x1d] = auVar22._4_4_;
    puGpffffbd04[0x1e] = auVar22._8_4_;
    puGpffffbd04[0x1f] = auVar22._12_4_;
    if (iVar3 == 0) {
      uVar18 = 0x3b808081;
    }
    else {
      uVar18 = 0x3b011b50;
    }
    puGpffffbd04 = puGpffffbd04 + 0x20;
    ((code)FUN_0049cab0)(uVar18,piVar7 + 1);
    auVar13._8_8_ = 0;
    auVar13._0_8_ = in_a0_udw;
    auVar28._8_8_ = in_v1_udw;
    auVar28._0_8_ = 0x5000000600000000;
    auVar39 = _pcpyld(auVar28,auVar13 << 0x40);
    auVar29._8_8_ = in_v1_udw;
    auVar29._0_8_ = 0x1000000000008005;
    *puGpffffbd04 = auVar39._0_4_;
    puGpffffbd04[1] = auVar39._4_4_;
    puGpffffbd04[2] = auVar39._8_4_;
    puGpffffbd04[3] = auVar39._12_4_;
    auVar8._8_4_ = fVar44;
    auVar8._0_8_ = 0xe;
    auVar8._12_4_ = fVar45;
    auVar22 = _pcpyld(auVar8,auVar29);
    puGpffffbd04[4] = auVar22._0_4_;
    puGpffffbd04[5] = auVar22._4_4_;
    puGpffffbd04[6] = auVar22._8_4_;
    puGpffffbd04[7] = auVar22._12_4_;
    auVar33._0_8_ = *(u64 *)(iVar6 + 0xb8);
    auVar33._8_8_ = in_a0_udw;
    auVar40._8_8_ = auVar39._8_8_;
    auVar40._0_8_ = 0x15;
    auVar12._8_4_ = uVar41;
    auVar12._0_8_ = 0x43;
    auVar12._12_4_ = uVar42;
    auVar22 = _pcpyld(auVar12,auVar33);
    puGpffffbd04[8] = auVar22._0_4_;
    puGpffffbd04[9] = auVar22._4_4_;
    puGpffffbd04[10] = auVar22._8_4_;
    puGpffffbd04[0xb] = auVar22._12_4_;
    auVar34._8_8_ = auVar22._8_8_;
    auVar34._0_8_ = *(u64 *)(iVar6 + 0xc0);
    auVar11._8_8_ = in_t0_udw;
    auVar11._0_8_ = 9;
    auVar22 = _pcpyld(auVar11,auVar34);
    puGpffffbd04[0xc] = auVar22._0_4_;
    puGpffffbd04[0xd] = auVar22._4_4_;
    puGpffffbd04[0xe] = auVar22._8_4_;
    puGpffffbd04[0xf] = auVar22._12_4_;
    auVar35._8_8_ = auVar22._8_8_;
    auVar35._0_8_ = *(u64 *)(iVar6 + 200);
    auVar10._8_8_ = in_a3_udw;
    auVar10._0_8_ = 0x48;
    auVar22 = _pcpyld(auVar10,auVar35);
    puGpffffbd04[0x10] = auVar22._0_4_;
    puGpffffbd04[0x11] = auVar22._4_4_;
    puGpffffbd04[0x12] = auVar22._8_4_;
    puGpffffbd04[0x13] = auVar22._12_4_;
    auVar36._8_8_ = auVar22._8_8_;
    auVar36._0_8_ = *(u64 *)(iVar6 + 0xd0);
    auVar22 = _pcpyld(auVar40,auVar36);
    puGpffffbd04[0x14] = auVar22._0_4_;
    puGpffffbd04[0x15] = auVar22._4_4_;
    puGpffffbd04[0x16] = auVar22._8_4_;
    puGpffffbd04[0x17] = auVar22._12_4_;
    auVar37._8_8_ = auVar22._8_8_;
    auVar37._0_8_ = uGpffffbd40;
    auVar9._8_4_ = fVar44;
    auVar9._0_8_ = 0x4f;
    auVar9._12_4_ = fVar45;
    auVar22 = _pcpyld(auVar9,auVar37);
    puGpffffbd04[0x18] = auVar22._0_4_;
    puGpffffbd04[0x19] = auVar22._4_4_;
    puGpffffbd04[0x1a] = auVar22._8_4_;
    puGpffffbd04[0x1b] = auVar22._12_4_;
    uVar43 = *(u32 *)(iVar6 + 0xf8);
    puVar26 = puGpffffbd04 + 0x1c;
    if (uGpffffbe08 != uVar43) {
      auVar25._0_8_ = (u32)uVar43 << 0x20 | 0x50000000;
      auVar25._8_8_ = extraout_v0_udw_00;
      auVar14._4_4_ = fVar45;
      auVar14._0_4_ = fVar44;
      auVar14._8_8_ = 0;
      auVar22 = _pcpyld(auVar14 << 0x40,auVar25);
      *puVar26 = auVar22._0_4_;
      puGpffffbd04[0x1d] = auVar22._4_4_;
      puGpffffbd04[0x1e] = auVar22._8_4_;
      puGpffffbd04[0x1f] = auVar22._12_4_;
      puVar26 = puGpffffbd04 + 0x20;
      uGpffffbe08 = uVar43;
    }
    puGpffffbd04 = puVar26 + 4;
    puVar38 = (u32 *)(iVar6 + *(int *)(iVar6 + 0xe4) * 0x20);
    uVar18 = puVar38[1];
    uVar15 = puVar38[2];
    uVar16 = puVar38[3];
    *puVar26 = *puVar38;
    puVar26[1] = uVar18;
    puVar26[2] = uVar15;
    puVar26[3] = uVar16;
    ((code)FUN_0050d3a0)();
    puVar38[4] = puVar38[4] + 1;
    ((code)FUN_0050d3f0)();
    iVar1 = puVar38[5];
    puVar38[5] = iVar1 + 1;
    if (iVar1 == 0) {
      ((code)FUN_004d51c0)(puVar38 + 4);
    }
    uVar20 = 1;
  }
  return uVar20;
}

// FUN_0047AB70 NONMATCHING

long FUN_0047ab70(void)

{
  long lVar1;
  long lVar2;
  u64 uVar3;
  
  lVar1 = ((code)FUN_004f2f70)();
  if (lVar1 != 0) {
    lVar2 = ((code)FUN_004f4640)(lVar1);
    if (lVar2 != 0) {
      uVar3 = ((code)FUN_004f4950)(lVar2,0,0x77b210,0);
      lVar2 = ((code)FUN_004f3f80)(uVar3);
      if (lVar2 != 0) {
        return lVar1;
      }
    }
    ((code)FUN_004f3010)(lVar1);
  }
  return 0;
}

// FUN_0047ABF0 NONMATCHING

u32 FUN_0047abf0(int param_1,u32 *param_2)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  u32 *puVar4;
  u32 uVar5;
  float *pfVar6;
  int iVar7;
  u64 uVar8;
  int *piVar9;
  int iVar10;
  float *pfVar11;
  u8 bVar12;
  u32 *puVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  int aiStack_70 [4];
  u8 auStack_60 [32];
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_20;
  float fStack_1c;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar10 = *(int *)(iVar1 + 0x18);
  puVar13 = (u32 *)(DAT_00960070 + 0x20);
  *(u32 *)(param_1 + 0xc) = *(u32 *)(iVar10 + 0x54);
  piVar9 = (int *)(iVar10 + iGpffffbba0);
  bVar12 = 0;
  if (((u32 *)*piVar9 != (u32 *)0x0) &&
     ((u32)*(u16 *)(*(int *)(iVar10 + 0x54) + 4) == *(u32 *)*piVar9)) {
    bVar12 = 1;
  }
  if (bVar12) {
    iVar10 = *piVar9;
  }
  else {
    piVar9 = (int *)((code)FUN_0049e5a0)(piVar9,*(u16 *)(*(int *)(iVar10 + 0x54) + 4));
    iVar10 = *piVar9;
  }
  *(int *)(param_1 + 0x10) = iVar10;
  iVar10 = *(int *)(iVar1 + 0x18);
  if ((*(u32 *)(iVar10 + 8) & 0x1000000) == 0) {
    *(u32 *)(param_1 + 0x18) =
         (u32)*(u8 *)(iVar10 + 0x18) << 0x18 |
         (u32)*(u16 *)(*(int *)(param_1 + 0xc) + 6) | (*(u32 *)(iVar10 + 8) & 0x9f) << 0x10;
    *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) & 0xfffffffe;
    iVar7 = *(int *)(*(int *)(param_1 + 0x10) + 4);
    if (iVar7 != 0) {
      uVar3 = *(u32 *)(iVar7 + 0x28);
      uVar5 = *(u32 *)(param_1 + 0x18);
      if (uVar5 != uVar3) {
        if (((uVar5 >> 0x10 & 0xff) == (uVar3 >> 0x10 & 0xff)) && (uVar5 >> 0x18 == uVar3 >> 0x18))
        {
          *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 4;
        }
        else {
          *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 8;
        }
      }
      if (*(u16 *)(iVar10 + 0xc) != 0) {
        if ((*(u16 *)(iVar10 + 0xc) & 1) == 0) {
          *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 2;
          *(u32 *)(param_1 + 0x14) =
               *(u32 *)(param_1 + 0x14) | (u32)*(u16 *)(iVar10 + 0xc) << 3;
        }
        else {
          *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 8;
        }
      }
      if (((*(u32 *)(iVar1 + 0x4c) & 1) != 0) &&
         (((long)*(int *)(iVar7 + 0x40) != (long)*(short *)(iVar1 + 0x52) ||
          ((long)*(int *)(iVar7 + 0x3c) != (long)*(short *)(iVar1 + 0x50))))) {
        *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) | 4;
      }
    }
  }
  iVar10 = 8;
  *(u16 *)(*(int *)(iVar1 + 0x18) + 0xc) = 0;
  *(u32 *)(iVar1 + 0x4c) = *(u32 *)(iVar1 + 0x4c) & 0xfffffffe;
  param_2 = (u32 *)*param_2;
  do {
    iVar10 = iVar10 + -1;
    uVar2 = puVar13[1];
    *param_2 = *puVar13;
    puVar13 = puVar13 + 2;
    param_2[1] = uVar2;
    param_2 = param_2 + 2;
  } while (0 < iVar10);
  iVar7 = 2;
  pfVar6 = (float *)((code)FUN_004912b0)(iVar1);
  iVar10 = 5;
  pfVar11 = (float *)(DAT_00960070 + iGpffffbdb4 + 0x60);
  do {
    if (-pfVar6[3] <
        (pfVar6[2] * pfVar11[2] + *pfVar6 * *pfVar11 + pfVar6[1] * pfVar11[1]) - pfVar11[3]) {
      iVar7 = 1;
      break;
    }
    pfVar11 = pfVar11 + 5;
    bVar12 = iVar10 != 0;
    iVar10 = iVar10 + -1;
  } while (bVar12);
  uVar3 = **(u32 **)(param_1 + 0xc);
  if ((uVar3 & 1) == 1) {
    *(u8 *)(param_1 + 0x29) = 4;
    *(u8 *)(param_1 + 0x28) = bGpffffbe04;
  }
  else if (((uVar3 & 0xff) == 0) || ((uVar3 & 2) == 2)) {
    *(u8 *)(param_1 + 0x29) = 3;
    *(u8 *)(param_1 + 0x28) = bGpffffbe04 | 4;
  }
  else if ((uVar3 & 0x10) == 0x10) {
    *(u8 *)(param_1 + 0x29) = 4;
    *(u8 *)(param_1 + 0x28) = bGpffffbe04;
  }
  else if ((uVar3 & 8) == 8) {
    *(u8 *)(param_1 + 0x29) = 2;
    *(u8 *)(param_1 + 0x28) = bGpffffbe04 | 0x10;
  }
  else {
    *(u8 *)(param_1 + 0x29) = 1;
    *(u8 *)(param_1 + 0x28) = bGpffffbe04 | 0x14;
  }
  if (iVar7 != 2) {
    *(u8 *)(param_1 + 0x28) = *(u8 *)(param_1 + 0x28) | 2;
  }
  *(u8 *)(param_1 + 0x28) = *(u8 *)(param_1 + 0x28) | 2;
  *(u8 *)(param_1 + 0x2a) = (*(u32 *)(*(int *)(iVar1 + 0x18) + 8) & 0x40) != 0;
  iVar1 = *(int *)(param_1 + 8);
  iVar10 = *(int *)(iVar1 + 0x18);
  if ((*(u32 *)(iVar10 + 8) & 0x20) != 0) {
    DAT_0096007a = DAT_0096007a + 1;
    uVar8 = ((code)FUN_004cb2f0)(*(u32 *)(iVar1 + 4));
    ((code)FUN_004c32a0)(auStack_60,uVar8);
    if ((*(u32 *)((int)uVar8 + 0xc) & 3) == 3) {
      fStack_20 = 1.0;
      fStack_1c = 1.0;
    }
    else {
      fStack_20 = SQRT(fStack_38 * fStack_38 + fStack_40 * fStack_40 + fStack_3c * fStack_3c);
      fStack_1c = fStack_20;
      if (0.0 < fStack_20) {
        fStack_1c = 1.0 / fStack_20;
      }
    }
    iVar10 = *(int *)(iVar10 + 0x54);
    aiStack_70[0] = *(int *)(*(int *)(iVar10 + 0xc) + iVar10 + 0x18) + 0xc;
    ((code)FUN_00499c20)(0x4a0430,aiStack_70);
    for (puVar13 = *(u32 **)(iVar1 + 100); puVar13 != (u32 *)(iVar1 + 100);
        puVar13 = (u32 *)*puVar13) {
      iVar10 = puVar13[2];
      for (puVar4 = *(u32 **)(iVar10 + 0x40); puVar4 != (u32 *)(iVar10 + 0x40);
          puVar4 = (u32 *)*puVar4) {
        iVar7 = puVar4[2];
        if (((iVar7 != 0) && (*(short *)(iVar7 + 0x3c) != DAT_0096007a)) &&
           ((*(u8 *)(iVar7 + 2) & 1) != 0)) {
          *(short *)(iVar7 + 0x3c) = DAT_0096007a;
          iVar7 = ((code)FUN_004cb2f0)(*(u32 *)(puVar4[2] + 4));
          pfVar6 = (float *)((code)FUN_004912b0)(iVar1);
          fVar16 = pfVar6[1] - *(float *)(iVar7 + 0x34);
          fVar17 = *pfVar6 - *(float *)(iVar7 + 0x30);
          fVar14 = pfVar6[2] - *(float *)(iVar7 + 0x38);
          fVar15 = pfVar6[3] + *(float *)(puVar4[2] + 0x14);
          if (fVar14 * fVar14 + fVar17 * fVar17 + fVar16 * fVar16 < fVar15 * fVar15) {
            ((code)FUN_004a0430)(puVar4[2],aiStack_70);
          }
        }
      }
    }
  }
  return 1;
}

// FUN_0047B1A0 NONMATCHING

long FUN_0047b1a0(void)

{
  long lVar1;
  long lVar2;
  u64 uVar3;
  u64 uVar4;
  
  lVar1 = ((code)FUN_004f2f70)();
  if (lVar1 != 0) {
    lVar2 = ((code)FUN_004f4640)(lVar1);
    if (lVar2 != 0) {
      uVar3 = ((code)FUN_0049ff00)();
      uVar4 = ((code)FUN_004f4950)(lVar2,0,uVar3,0);
      ((code)FUN_004f4830)(uVar4,*(u32 *)uVar3,0,0);
      lVar2 = ((code)FUN_004f3f80)(uVar4);
      if (lVar2 != 0) {
        uVar3 = ((code)FUN_004f4830)(lVar2,*(u32 *)uVar3,0,0);
        ((code)FUN_0049fe40)(uVar3,1,0x47abf0);
        return lVar1;
      }
    }
    ((code)FUN_004f3010)(lVar1);
  }
  return 0;
}

// FUN_0047B280 NONMATCHING






u64 FUN_0047b280(u64 param_1,float *param_2,u32 param_3,u8 *param_4)

{
  u8 bVar1;
  u32 uVar2;
  float *pfVar3;
  u32 uVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  u64 uVar10;
  u32 uVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  uVar10 = 0x95c4a0;
  if (param_3 != 0) {
    iVar9 = (int)param_1;
    uVar2 = *(u32 *)(iVar9 + 0x6c);
    uVar11 = 0;
    iVar8 = 0;
    if ((param_3 != 0) && (param_3 != 0)) {
      do {
        ((code)FUN_004c6be0)(&fStack_20,iVar9 + 0x1c,param_2);
        if (((u32)param_2[3] & 3) == 3) {
          fStack_14 = *(float *)(iVar9 + 0x28);
        }
        else {
          fVar15 = param_2[2] * param_2[2] + *param_2 * *param_2 + param_2[1] * param_2[1];
          fVar14 = param_2[6] * param_2[6] + param_2[4] * param_2[4] + param_2[5] * param_2[5];
          fVar12 = param_2[10] * param_2[10] + param_2[8] * param_2[8] + param_2[9] * param_2[9];
          fVar13 = fVar14;
          if (fVar14 < fVar12) {
            fVar13 = fVar12;
          }
          if ((fVar15 < fVar13) && (fVar15 = fVar14, fVar14 < fVar12)) {
            fVar15 = fVar12;
          }
          fStack_14 = *(float *)(iVar9 + 0x28) * SQRT(fVar15);
        }
        uVar4 = 2;
        iVar5 = 5;
        pfVar6 = (float *)(DAT_00960070 + 0x94);
        do {
          if (fStack_14 <
              (fStack_18 * pfVar6[2] + fStack_20 * *pfVar6 + fStack_1c * pfVar6[1]) - pfVar6[3]) {
            uVar4 = 0;
            break;
          }
          pfVar6 = pfVar6 + 5;
          bVar1 = iVar5 != 0;
          iVar5 = iVar5 + -1;
        } while (bVar1);
        if (uVar4 == 2) {
          iVar5 = 5;
          pfVar6 = (float *)(DAT_00960070 + iGpffffbdb4 + 0x60);
          do {
            if (-fStack_14 <
                (fStack_18 * pfVar6[2] + fStack_20 * *pfVar6 + fStack_1c * pfVar6[1]) - pfVar6[3]) {
              uVar4 = 1;
              break;
            }
            pfVar6 = pfVar6 + 5;
            bVar1 = iVar5 != 0;
            iVar5 = iVar5 + -1;
          } while (bVar1);
        }
        if (uVar4 != 0) {
          iVar5 = 8;
          pfVar3 = (float *)((int)uVar10 + iVar8 * 0x50);
          pfVar6 = param_2;
          pfVar7 = pfVar3;
          do {
            iVar5 = iVar5 + -1;
            fVar13 = pfVar6[1];
            *pfVar7 = *pfVar6;
            pfVar6 = pfVar6 + 2;
            pfVar7[1] = fVar13;
            pfVar7 = pfVar7 + 2;
          } while (0 < iVar5);
          pfVar3[0xf] = (float)(uVar4 & 1);
          pfVar3[0x10] = (float)*param_4 / 255.0;
          pfVar3[0x11] = (float)param_4[1] / 255.0;
          pfVar3[0x12] = (float)param_4[2] / 255.0;
          iVar8 = iVar8 + 1;
          pfVar3[0x13] = (float)param_4[3] / 255.0;
          if (iVar8 == 0x30) {
            uVar10 = ((code)FUN_0046c330)(uVar10,0x30);
            ((code)FUN_004f2e70)(uVar2,param_1,1);
            iVar8 = 0;
          }
        }
        uVar11 = uVar11 + 1;
        param_2 = param_2 + 0x10;
        param_4 = param_4 + 4;
      } while (uVar11 < param_3);
    }
    if (iVar8 != 0) {
      ((code)FUN_0046c330)(uVar10,iVar8);
      ((code)FUN_004f2e70)(uVar2,param_1,1);
    }
  }
  return param_1;
}

// FUN_0047B750 NONMATCHING

u64 FUN_0047b750(u64 param_1,float *param_2,u32 param_3,float *param_4)

{
  u8 bVar1;
  u32 uVar2;
  u32 uVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  int iVar9;
  u64 uVar10;
  u32 uVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  uVar11 = 0;
  iVar4 = (int)param_1;
  uVar2 = *(u32 *)(iVar4 + 0x6c);
  uVar10 = 0x95c4a0;
  iVar9 = 0;
  if ((param_3 != 0) && (param_3 != 0)) {
    do {
      ((code)FUN_004c6be0)(&fStack_20,iVar4 + 0x1c,param_2);
      if (((u32)param_2[3] & 3) == 3) {
        fStack_14 = *(float *)(iVar4 + 0x28);
      }
      else {
        fVar14 = param_2[2] * param_2[2] + *param_2 * *param_2 + param_2[1] * param_2[1];
        fVar13 = param_2[6] * param_2[6] + param_2[4] * param_2[4] + param_2[5] * param_2[5];
        fVar12 = param_2[10] * param_2[10] + param_2[8] * param_2[8] + param_2[9] * param_2[9];
        fVar15 = fVar13;
        if (fVar13 < fVar12) {
          fVar15 = fVar12;
        }
        if ((fVar14 < fVar15) && (fVar14 = fVar13, fVar13 < fVar12)) {
          fVar14 = fVar12;
        }
        fStack_14 = *(float *)(iVar4 + 0x28) * SQRT(fVar14);
      }
      uVar3 = 2;
      iVar5 = 5;
      pfVar7 = (float *)(DAT_00960070 + 0x94);
      do {
        if (fStack_14 <
            (fStack_18 * pfVar7[2] + fStack_20 * *pfVar7 + fStack_1c * pfVar7[1]) - pfVar7[3]) {
          uVar3 = 0;
          break;
        }
        pfVar7 = pfVar7 + 5;
        bVar1 = iVar5 != 0;
        iVar5 = iVar5 + -1;
      } while (bVar1);
      if (uVar3 == 2) {
        iVar5 = 5;
        pfVar7 = (float *)(DAT_00960070 + iGpffffbdb4 + 0x60);
        do {
          if (-fStack_14 <
              (fStack_18 * pfVar7[2] + fStack_20 * *pfVar7 + fStack_1c * pfVar7[1]) - pfVar7[3]) {
            uVar3 = 1;
            break;
          }
          pfVar7 = pfVar7 + 5;
          bVar1 = iVar5 != 0;
          iVar5 = iVar5 + -1;
        } while (bVar1);
      }
      if (uVar3 != 0) {
        iVar5 = 8;
        pfVar8 = (float *)((int)uVar10 + iVar9 * 0x50);
        pfVar7 = param_2;
        pfVar6 = pfVar8;
        do {
          iVar5 = iVar5 + -1;
          fVar15 = pfVar7[1];
          *pfVar6 = *pfVar7;
          pfVar7 = pfVar7 + 2;
          pfVar6[1] = fVar15;
          pfVar6 = pfVar6 + 2;
        } while (0 < iVar5);
        iVar9 = iVar9 + 1;
        pfVar8[0xf] = (float)(uVar3 & 1);
        fVar12 = param_4[1];
        fVar15 = *param_4;
        fVar14 = param_4[2];
        pfVar8[0x10] = pfVar8[2] * fVar14 + *pfVar8 * fVar15 + pfVar8[1] * fVar12;
        pfVar8[0x11] = pfVar8[6] * fVar14 + pfVar8[4] * fVar15 + pfVar8[5] * fVar12;
        pfVar8[0x12] = pfVar8[10] * fVar14 + pfVar8[8] * fVar15 + pfVar8[9] * fVar12;
        if (iVar9 == 0x30) {
          uVar10 = ((code)FUN_0046c330)(uVar10,0x30);
          ((code)FUN_004f2e70)(uVar2,param_1,1);
          iVar9 = 0;
        }
      }
      uVar11 = uVar11 + 1;
      param_2 = param_2 + 0x10;
    } while (uVar11 < param_3);
  }
  if (iVar9 != 0) {
    ((code)FUN_0046c330)(uVar10,iVar9);
    ((code)FUN_004f2e70)(uVar2,param_1,1);
  }
  return param_1;
}

// FUN_0047BB40 NONMATCHING

long FUN_0047bb40(int param_1,int param_2,u32 param_3)

{
  long lVar1;
  int iVar2;
  u32 *puVar3;
  int iVar4;
  u32 *puStack_8;
  
  iVar2 = param_2 * 0x40 + 0x1c;
  if ((param_3 & 2) != 0) {
    iVar2 = iVar2 + param_2 * 4;
  }
  lVar1 = (*DAT_00960178)(iVar2 + 0x10,0x3012f);
  if (lVar1 == 0) {
    lVar1 = 0;
  }
  else {
    puVar3 = (u32 *)((int)lVar1 + 0xfU & 0xfffffff0);
    puVar3[1] = 0;
    puVar3[2] = 0;
    *puVar3 = 0;
    *(u32 **)(param_1 + 0x4c) = puVar3;
    ((code)FUN_00521408)(param_1 + 4,0,0x48);
    *(u32 **)(param_1 + 0xc) = puVar3 + 4;
    *(u32 *)(param_1 + 0x10) = 0x40;
    *(u32 *)(param_1 + 0x50) = 1;
    iVar2 = 0;
    *(u32 *)(param_1 + 0x54) = 0;
    *(u32 *)(param_1 + 0x58) = 8;
    puStack_8 = *(u32 **)(param_1 + 0xc);
    iVar4 = *(int *)(param_1 + 0x10);
    if (0 < param_2) {
      do {
        iVar2 = iVar2 + 1;
        puStack_8[10] = 0x3f800000;
        puStack_8[5] = 0x3f800000;
        *puStack_8 = 0x3f800000;
        puStack_8[4] = 0;
        puStack_8[2] = 0;
        puStack_8[1] = 0;
        puStack_8[9] = 0;
        puStack_8[8] = 0;
        puStack_8[6] = 0;
        puStack_8[0xe] = 0;
        puStack_8[0xd] = 0;
        puStack_8[0xc] = 0;
        puStack_8[3] = puStack_8[3] | 0x20003;
        puStack_8 = (u32 *)((int)puStack_8 + iVar4);
      } while (iVar2 < param_2);
    }
    if ((param_3 & 2) != 0) {
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0xc) + param_2 * 0x40;
      *(u32 *)(param_1 + 0x28) = 4;
      *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + 1;
      *(u32 *)(param_1 + 0x58) = *(u32 *)(param_1 + 0x58) | 2;
      ((code)FUN_00521408)(*(u32 *)(param_1 + 0x24),0xff,param_2 << 2);
    }
  }
  return lVar1;
}

// FUN_0047BD20 NONMATCHING

u32 FUN_0047bd20(u64 param_1)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  long lVar4;
  u64 uVar5;
  
  lVar3 = ((code)FUN_00493710)(0,0,0);
  if (lVar3 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = *(int *)((int)lVar3 + 0x5c);
    *(u32 *)(iVar1 + 4) = 0;
    *(u32 *)(iVar1 + 8) = 0;
    *(u32 *)(iVar1 + 0xc) = 0;
    *(u32 *)(iVar1 + 0x10) = 0x3f800000;
    lVar4 = ((code)FUN_004933d0)(lVar3);
    if (lVar4 == 0) {
      uVar2 = 0;
    }
    else {
      ((code)FUN_004919b0)(param_1,lVar3,0);
      ((code)FUN_00493b60)(lVar3);
      uVar5 = ((code)FUN_00494be0)();
      ((code)FUN_00495340)((int)lVar3 + 0x20,uVar5);
      ((code)FUN_00494cc0)(uVar5);
      uVar2 = 1;
      iVar1 = *(int *)((int)param_1 + iGpffffba80);
      *(u32 *)(iVar1 + 0x24) = 0;
      *(u32 *)(iVar1 + 0x28) = 0;
      *(u32 *)(iVar1 + 0x2c) = 0;
      *(u32 *)(iVar1 + 0x30) = 0;
      *(u32 *)(iVar1 + 0x34) = 0;
      *(u32 *)(iVar1 + 0x38) = 0;
    }
  }
  return uVar2;
}

// FUN_0047BE10 NONMATCHING

u64 FUN_0047be10(int param_1,int param_2,u64 param_3)

{
  u32 *puVar1;
  u32 uVar2;
  int iVar3;
  u32 uStack_8;
  u32 uStack_4;
  
  puVar1 = *(u32 **)(*(int *)(param_1 + iGpffffba80) + 0x9c);
  if (*(int *)(param_2 + 100) == 0) {
    uVar2 = *(u32 *)(param_2 + 0x58);
  }
  else {
    (*DAT_00960090)(0xc,1);
    (*DAT_00960094)(10,&uStack_4);
    (*DAT_00960090)(10,*(u32 *)(param_2 + 0x5c));
    (*DAT_00960094)(0xb,&uStack_8);
    (*DAT_00960090)(0xb,*(u32 *)(param_2 + 0x60));
    uVar2 = *(u32 *)(param_2 + 0x58);
  }
  if ((uVar2 & 2) == 0) {
    iVar3 = ((code)FUN_004cb2f0)(*(u32 *)(puVar1[2] + 4));
    ((code)FUN_004733c0)(puVar1[1],puVar1[2]);
    ((code)FUN_0047b750)(*puVar1,*(u32 *)(param_2 + 0xc),param_3,iVar3 + 0x20);
    iVar3 = *(int *)(param_2 + 100);
  }
  else {
    ((code)FUN_0047b280)(*puVar1,*(u32 *)(param_2 + 0xc),param_3,*(u32 *)(param_2 + 0x24));
    iVar3 = *(int *)(param_2 + 100);
  }
  if (iVar3 != 0) {
    (*DAT_00960090)(10,uStack_4);
    (*DAT_00960090)(0xb,uStack_8);
  }
  return 0;
}

// FUN_0047BF80 NONMATCHING

void FUN_0047bf80(int param_1)

{
  int iVar1;
  u32 uVar2;
  
  iVar1 = *(int *)(param_1 + iGpffffba80);
  **(code **)(iVar1 + 0x24) = (code)FUN_00488550;
  uVar2 = *(u32 *)(iVar1 + 0xa8);
  if ((uVar2 & 8) == 8) {
    if ((uVar2 & 0x1000000) == 0x1000000) {
      **(code **)(iVar1 + 0x28) = (code)FUN_00483170;
    }
    else {
      **(code **)(iVar1 + 0x28) = (code)FUN_00482a50;
    }
  }
  else if ((uVar2 & 0x8000) == 0x8000) {
    if ((uVar2 & 0x1000000) == 0x1000000) {
      **(code **)(iVar1 + 0x28) = (code)FUN_0047c8c0;
    }
    else {
      **(code **)(iVar1 + 0x28) = (code)FUN_0047c240;
    }
  }
  else if ((uVar2 & 0x20) == 0x20) {
    if ((uVar2 & 4) == 4) {
      if ((uVar2 & 0x1000000) == 0x1000000) {
        **(code **)(iVar1 + 0x28) = (code)FUN_00481860;
      }
      else {
        **(code **)(iVar1 + 0x28) = (code)FUN_0047e9e0;
      }
    }
    else if ((uVar2 & 0x1000000) == 0x1000000) {
      **(code **)(iVar1 + 0x28) = (code)FUN_0047fb10;
    }
    else {
      **(code **)(iVar1 + 0x28) = (code)FUN_0047cfd0;
    }
  }
  else if ((uVar2 & 4) == 4) {
    if ((uVar2 & 0x1000000) == 0x1000000) {
      **(code **)(iVar1 + 0x28) = (code)FUN_00480c30;
    }
    else {
      **(code **)(iVar1 + 0x28) = (code)FUN_0047de30;
    }
  }
  else if ((uVar2 & 0x1000000) == 0x1000000) {
    **(code **)(iVar1 + 0x28) = (code)FUN_0047c8c0;
  }
  else {
    **(code **)(iVar1 + 0x28) = (code)FUN_0047c240;
  }
  uVar2 = *(u32 *)(iVar1 + 0xa8);
  if ((uVar2 & 0x80) == 0x80) {
    **(code **)(iVar1 + 0x2c) = (code)FUN_00485750;
  }
  else if ((uVar2 & 0x100) == 0x100) {
    **(code **)(iVar1 + 0x2c) = (code)FUN_00485e20;
  }
  else if ((uVar2 & 0x80000) == 0x80000) {
    **(code **)(iVar1 + 0x2c) = (code)FUN_00485ef0;
  }
  else if ((uVar2 & 0x100000) == 0x100000) {
    **(code **)(iVar1 + 0x2c) = (code)FUN_00485ff0;
  }
  else {
    *(u32 *)(iVar1 + 0x2c) = 0;
  }
  uVar2 = *(u32 *)(iVar1 + 0xa8);
  if ((uVar2 & 2) == 2) {
    **(code **)(iVar1 + 0x30) = (code)FUN_004838e0;
  }
  else if ((uVar2 & 0x40) == 0x40) {
    **(code **)(iVar1 + 0x30) = (code)FUN_00485070;
  }
  else if ((uVar2 & 0x40000) == 0x40000) {
    **(code **)(iVar1 + 0x30) = (code)FUN_00485110;
  }
  else {
    **(code **)(iVar1 + 0x30) = (code)FUN_00485440;
  }
  if ((*(u32 *)(iVar1 + 0xa8) & 0x10) == 0x10) {
    *(u8 **)(iVar1 + 0x34) = &LAB_00486100;
  }
  *(u8 **)(iVar1 + 0x38) = &LAB_00488b80;
  return;
}

// FUN_0047C240 NONMATCHING

void FUN_0047c240(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5)

{
  int iVar1;
  char cVar2;
  u32 uVar3;
  int iVar4;
  u8 (*pauVar5) [16];
  u8 (*pauVar6) [16];
  u8 (*pauVar7) [16];
  u8 (*pauVar8) [16];
  int iVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  Vec128 auVar16;
  Vec128 auVar17;
  Vec128 auVar18;
  Vec128 auVar19;
  Vec128 auVar20;
  Vec128 auVar21;
  Vec128 auVar22;
  u32 uStack_14;
  u32 uStack_4;
  
  iVar9 = *(int *)(param_5 + 8);
  iVar1 = param_1[1];
  pauVar8 = *(u8 (**) [16])(param_5 + 4);
  pauVar7 = (u8 (*) [16])*param_1;
  fVar15 = *(float *)(param_5 + 0x70) * 0.5;
  fVar14 = *(float *)(param_5 + 0x74) * 0.5;
  fVar10 = *param_2 * fVar15;
  fVar11 = param_2[2] * fVar15;
  fVar13 = *param_3 * fVar14;
  fVar15 = param_2[1] * fVar15;
  fVar12 = param_3[1] * fVar14;
  fVar14 = param_3[2] * fVar14;
  if (iVar9 == iVar1) {
    FlushCache(0);
    uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar3 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar2 = getCopCondition(0,0);
      } while (cVar2 == '\0');
    }
    uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar3 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar2 = getCopCondition(0,0);
      } while (cVar2 == '\0');
    }
    if (0xcc < param_4) {
      do {
        uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
        }
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
          do {
            uVar3 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar3 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0;
        REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar8);
        REG_DMAC_9_SPR_TO_QWC = 0xcc;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
          do {
            uVar3 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar3 & 0x100) != 0);
        }
        pauVar6 = (u8 (*) [16])(u8 *)DAT_70000000;
        iVar9 = 0;
        pauVar5 = (u8 (*) [16])(u8 *)DAT_70000cc0;
        do {
          auVar16 = _lqc2(*pauVar6);
          auVar19._4_4_ = fVar15;
          auVar19._0_4_ = fVar10;
          auVar19._8_4_ = fVar11;
          auVar19._12_4_ = uStack_4;
          auVar17 = _lqc2(auVar19);
          auVar18._4_4_ = fVar12;
          auVar18._0_4_ = fVar13;
          auVar18._8_4_ = fVar14;
          auVar18._12_4_ = uStack_14;
          auVar18 = _lqc2(auVar18);
          auVar19 = _vsub(auVar16,auVar17);
          auVar20 = _vadd(auVar16,auVar17);
          auVar21 = _vadd(auVar16,auVar17);
          auVar22 = _vsub(auVar16,auVar17);
          auVar16 = _vsub(auVar19,auVar18);
          auVar17 = _vsub(auVar20,auVar18);
          auVar19 = _vadd(auVar21,auVar18);
          auVar18 = _vadd(auVar22,auVar18);
          auVar16 = _sqc2(auVar16);
          *(Vec128 *)pauVar5 = auVar16;
          auVar16 = _sqc2(auVar17);
          ((Vec128 *)pauVar5)[1] = auVar16;
          auVar16 = _sqc2(auVar19);
          ((Vec128 *)pauVar5)[2] = auVar16;
          auVar16 = _sqc2(auVar18);
          ((Vec128 *)pauVar5)[3] = auVar16;
          iVar9 = iVar9 + 1;
          pauVar5 = pauVar5 + 4;
          pauVar6 = pauVar6 + 1;
        } while (iVar9 < 0xcc);
        uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
        }
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
          do {
            uVar3 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar3 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x100;
        REG_DMAC_8_SPR_FROM_SADR = 0xcc0;
        REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar7);
        REG_DMAC_8_SPR_FROM_QWC = 0x330;
        REG_DMAC_8_SPR_FROM_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        param_4 = param_4 + -0xcc;
        pauVar8 = pauVar8 + 0xcc;
        pauVar7 = pauVar7 + 0x330;
      } while (0xcc < param_4);
    }
    if (param_4 != 0) {
      uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
      }
      uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
        do {
          uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar3 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = 0;
      REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar8);
      REG_DMAC_9_SPR_TO_QWC = param_4;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
        do {
          uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar3 & 0x100) != 0);
      }
      pauVar5 = (u8 (*) [16])(u8 *)DAT_70000000;
      pauVar8 = (u8 (*) [16])(u8 *)DAT_70000cc0;
      iVar9 = 0;
      if (0 < param_4) {
        do {
          auVar16 = _lqc2(*pauVar5);
          auVar21._4_4_ = fVar15;
          auVar21._0_4_ = fVar10;
          auVar21._8_4_ = fVar11;
          auVar21._12_4_ = uStack_4;
          auVar17 = _lqc2(auVar21);
          auVar20._4_4_ = fVar12;
          auVar20._0_4_ = fVar13;
          auVar20._8_4_ = fVar14;
          auVar20._12_4_ = uStack_14;
          auVar18 = _lqc2(auVar20);
          auVar19 = _vsub(auVar16,auVar17);
          auVar20 = _vadd(auVar16,auVar17);
          auVar21 = _vadd(auVar16,auVar17);
          auVar22 = _vsub(auVar16,auVar17);
          auVar16 = _vsub(auVar19,auVar18);
          auVar17 = _vsub(auVar20,auVar18);
          auVar19 = _vadd(auVar21,auVar18);
          auVar18 = _vadd(auVar22,auVar18);
          auVar16 = _sqc2(auVar16);
          *(Vec128 *)pauVar8 = auVar16;
          auVar16 = _sqc2(auVar17);
          ((Vec128 *)pauVar8)[1] = auVar16;
          auVar16 = _sqc2(auVar19);
          ((Vec128 *)pauVar8)[2] = auVar16;
          auVar16 = _sqc2(auVar18);
          ((Vec128 *)pauVar8)[3] = auVar16;
          iVar9 = iVar9 + 1;
          pauVar8 = pauVar8 + 4;
          pauVar5 = pauVar5 + 1;
        } while (iVar9 < param_4);
      }
      uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
      }
      uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
        do {
          uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar3 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x100;
      REG_DMAC_8_SPR_FROM_SADR = 0xcc0;
      REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar7);
      REG_DMAC_8_SPR_FROM_QWC = param_4 << 2;
      REG_DMAC_8_SPR_FROM_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
    }
  }
  else {
    iVar4 = 0;
    if (0 < param_4) {
      do {
        auVar18 = _lqc2(*pauVar8);
        auVar17._4_4_ = fVar15;
        auVar17._0_4_ = fVar10;
        auVar17._8_4_ = fVar11;
        auVar17._12_4_ = uStack_4;
        auVar17 = _lqc2(auVar17);
        auVar16._4_4_ = fVar12;
        auVar16._0_4_ = fVar13;
        auVar16._8_4_ = fVar14;
        auVar16._12_4_ = uStack_14;
        auVar16 = _lqc2(auVar16);
        auVar19 = _vsub(auVar18,auVar17);
        auVar20 = _vadd(auVar18,auVar17);
        auVar21 = _vadd(auVar18,auVar17);
        auVar22 = _vsub(auVar18,auVar17);
        auVar17 = _vsub(auVar19,auVar16);
        auVar18 = _vsub(auVar20,auVar16);
        auVar19 = _vadd(auVar21,auVar16);
        auVar20 = _vadd(auVar22,auVar16);
        auVar16 = _sqc2(auVar17);
        *(Vec128 *)pauVar7 = auVar16;
        auVar16 = _sqc2(auVar18);
        ((Vec128 *)pauVar7)[1] = auVar16;
        auVar16 = _sqc2(auVar19);
        ((Vec128 *)pauVar7)[2] = auVar16;
        auVar16 = _sqc2(auVar20);
        ((Vec128 *)pauVar7)[3] = auVar16;
        iVar4 = iVar4 + 1;
        pauVar7 = (u8 (*) [16])(*pauVar7 + iVar1 * 4);
        pauVar8 = (u8 (*) [16])(*pauVar8 + iVar9);
      } while (iVar4 < param_4);
    }
  }
  return;
}

// FUN_0047C8C0 NONMATCHING

void FUN_0047c8c0(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5)

{
  int iVar1;
  char cVar2;
  u32 uVar3;
  Vec128 auVar4;
  int iVar5;
  u8 (*pauVar6) [16];
  u8 (*pauVar7) [16];
  u8 (*pauVar8) [16];
  u8 (*pauVar9) [16];
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
  Vec128 auVar21;
  Vec128 auVar22;
  Vec128 auVar23;
  Vec128 auVar24;
  Vec128 auVar25;
  Vec128 auVar26;
  Vec128 auVar27;
  Vec128 auVar28;
  u32 uStack_24;
  u32 uStack_14;
  u32 uStack_4;
  
  iVar10 = *(int *)(param_5 + 8);
  iVar1 = param_1[1];
  pauVar8 = *(u8 (**) [16])(param_5 + 4);
  pauVar7 = (u8 (*) [16])*param_1;
  fVar11 = *(float *)(param_5 + 0x70) * 0.5;
  fVar20 = *(float *)(param_5 + 0x74) * 0.5;
  fVar13 = *param_2 * fVar11;
  fVar14 = param_2[1] * fVar11;
  fVar11 = param_2[2] * fVar11;
  fVar15 = *param_3 * fVar20;
  fVar12 = *(float *)(param_5 + 0x6c);
  fVar19 = *(float *)(param_5 + 0x68);
  fVar16 = param_3[1] * fVar20;
  fVar20 = param_3[2] * fVar20;
  fVar17 = fVar19 * *param_2 + fVar12 * *param_3;
  fVar18 = fVar19 * param_2[1] + fVar12 * param_3[1];
  fVar12 = fVar19 * param_2[2] + fVar12 * param_3[2];
  if (iVar10 == iVar1) {
    FlushCache(0);
    uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar3 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar2 = getCopCondition(0,0);
      } while (cVar2 == '\0');
    }
    uVar3 = REG_DMAC_9_SPR_TO_CHCR;
    if ((uVar3 & 0x100) != 0) {
      REG_DMAC_PCR = 0x200;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar2 = getCopCondition(0,0);
      } while (cVar2 == '\0');
      do {
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      } while ((uVar3 & 0x100) != 0);
    }
    if (0xcc < param_4) {
      do {
        uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
        }
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
          do {
            uVar3 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar3 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0;
        REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar8);
        REG_DMAC_9_SPR_TO_QWC = 0xcc;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
          do {
            uVar3 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar3 & 0x100) != 0);
        }
        pauVar9 = (u8 (*) [16])(u8 *)DAT_70000000;
        iVar10 = 0;
        pauVar6 = (u8 (*) [16])(u8 *)DAT_70000cc0;
        do {
          auVar21 = _lqc2(*pauVar9);
          auVar26._4_4_ = fVar14;
          auVar26._0_4_ = fVar13;
          auVar26._8_4_ = fVar11;
          auVar26._12_4_ = uStack_4;
          auVar22 = _lqc2(auVar26);
          auVar25._4_4_ = fVar16;
          auVar25._0_4_ = fVar15;
          auVar25._8_4_ = fVar20;
          auVar25._12_4_ = uStack_14;
          auVar23 = _lqc2(auVar25);
          auVar24._4_4_ = fVar18;
          auVar24._0_4_ = fVar17;
          auVar24._8_4_ = fVar12;
          auVar24._12_4_ = uStack_24;
          auVar28 = _lqc2(auVar24);
          auVar24 = _vsub(auVar21,auVar22);
          auVar25 = _vadd(auVar21,auVar22);
          auVar26 = _vadd(auVar21,auVar22);
          auVar27 = _vsub(auVar21,auVar22);
          auVar21 = _vsub(auVar24,auVar23);
          auVar22 = _vsub(auVar25,auVar23);
          auVar24 = _vadd(auVar26,auVar23);
          auVar25 = _vadd(auVar27,auVar23);
          auVar21 = _vadd(auVar21,auVar28);
          auVar22 = _vadd(auVar22,auVar28);
          auVar23 = _vadd(auVar24,auVar28);
          auVar24 = _vadd(auVar25,auVar28);
          auVar21 = _sqc2(auVar21);
          *(Vec128 *)pauVar6 = auVar21;
          auVar21 = _sqc2(auVar22);
          ((Vec128 *)pauVar6)[1] = auVar21;
          auVar21 = _sqc2(auVar23);
          ((Vec128 *)pauVar6)[2] = auVar21;
          auVar21 = _sqc2(auVar24);
          ((Vec128 *)pauVar6)[3] = auVar21;
          iVar10 = iVar10 + 1;
          pauVar6 = pauVar6 + 4;
          pauVar9 = pauVar9 + 1;
        } while (iVar10 < 0xcc);
        uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
        }
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
          do {
            uVar3 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar3 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x100;
        REG_DMAC_8_SPR_FROM_SADR = 0xcc0;
        REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar7);
        REG_DMAC_8_SPR_FROM_QWC = 0x330;
        REG_DMAC_8_SPR_FROM_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        param_4 = param_4 + -0xcc;
        pauVar8 = pauVar8 + 0xcc;
        pauVar7 = pauVar7 + 0x330;
      } while (0xcc < param_4);
    }
    if (param_4 != 0) {
      uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
      }
      uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
        do {
          uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar3 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = 0;
      REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar8);
      REG_DMAC_9_SPR_TO_QWC = param_4;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
        do {
          uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar3 & 0x100) != 0);
      }
      pauVar6 = (u8 (*) [16])(u8 *)DAT_70000000;
      pauVar8 = (u8 (*) [16])(u8 *)DAT_70000cc0;
      iVar10 = 0;
      if (0 < param_4) {
        do {
          auVar21 = _lqc2(*pauVar6);
          auVar4._4_4_ = fVar14;
          auVar4._0_4_ = fVar13;
          auVar4._8_4_ = fVar11;
          auVar4._12_4_ = uStack_4;
          auVar22 = _lqc2(auVar4);
          auVar28._4_4_ = fVar16;
          auVar28._0_4_ = fVar15;
          auVar28._8_4_ = fVar20;
          auVar28._12_4_ = uStack_14;
          auVar23 = _lqc2(auVar28);
          auVar27._4_4_ = fVar18;
          auVar27._0_4_ = fVar17;
          auVar27._8_4_ = fVar12;
          auVar27._12_4_ = uStack_24;
          auVar28 = _lqc2(auVar27);
          auVar24 = _vsub(auVar21,auVar22);
          auVar25 = _vadd(auVar21,auVar22);
          auVar26 = _vadd(auVar21,auVar22);
          auVar27 = _vsub(auVar21,auVar22);
          auVar21 = _vsub(auVar24,auVar23);
          auVar22 = _vsub(auVar25,auVar23);
          auVar24 = _vadd(auVar26,auVar23);
          auVar25 = _vadd(auVar27,auVar23);
          auVar21 = _vadd(auVar21,auVar28);
          auVar22 = _vadd(auVar22,auVar28);
          auVar23 = _vadd(auVar24,auVar28);
          auVar24 = _vadd(auVar25,auVar28);
          auVar21 = _sqc2(auVar21);
          *(Vec128 *)pauVar8 = auVar21;
          auVar21 = _sqc2(auVar22);
          ((Vec128 *)pauVar8)[1] = auVar21;
          auVar21 = _sqc2(auVar23);
          ((Vec128 *)pauVar8)[2] = auVar21;
          auVar21 = _sqc2(auVar24);
          ((Vec128 *)pauVar8)[3] = auVar21;
          iVar10 = iVar10 + 1;
          pauVar8 = pauVar8 + 4;
          pauVar6 = pauVar6 + 1;
        } while (iVar10 < param_4);
      }
      uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
      }
      uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
        do {
          uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar3 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x100;
      REG_DMAC_8_SPR_FROM_SADR = 0xcc0;
      REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar7);
      REG_DMAC_8_SPR_FROM_QWC = param_4 << 2;
      REG_DMAC_8_SPR_FROM_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
    }
  }
  else {
    iVar5 = 0;
    if (0 < param_4) {
      do {
        auVar24 = _lqc2(*pauVar8);
        auVar23._4_4_ = fVar14;
        auVar23._0_4_ = fVar13;
        auVar23._8_4_ = fVar11;
        auVar23._12_4_ = uStack_4;
        auVar23 = _lqc2(auVar23);
        auVar22._4_4_ = fVar16;
        auVar22._0_4_ = fVar15;
        auVar22._8_4_ = fVar20;
        auVar22._12_4_ = uStack_14;
        auVar22 = _lqc2(auVar22);
        auVar21._4_4_ = fVar18;
        auVar21._0_4_ = fVar17;
        auVar21._8_4_ = fVar12;
        auVar21._12_4_ = uStack_24;
        auVar28 = _lqc2(auVar21);
        auVar21 = _vsub(auVar24,auVar23);
        auVar25 = _vadd(auVar24,auVar23);
        auVar26 = _vadd(auVar24,auVar23);
        auVar27 = _vsub(auVar24,auVar23);
        auVar21 = _vsub(auVar21,auVar22);
        auVar23 = _vsub(auVar25,auVar22);
        auVar24 = _vadd(auVar26,auVar22);
        auVar25 = _vadd(auVar27,auVar22);
        auVar21 = _vadd(auVar21,auVar28);
        auVar22 = _vadd(auVar23,auVar28);
        auVar23 = _vadd(auVar24,auVar28);
        auVar24 = _vadd(auVar25,auVar28);
        auVar21 = _sqc2(auVar21);
        *(Vec128 *)pauVar7 = auVar21;
        auVar21 = _sqc2(auVar22);
        ((Vec128 *)pauVar7)[1] = auVar21;
        auVar21 = _sqc2(auVar23);
        ((Vec128 *)pauVar7)[2] = auVar21;
        auVar21 = _sqc2(auVar24);
        ((Vec128 *)pauVar7)[3] = auVar21;
        iVar5 = iVar5 + 1;
        pauVar7 = (u8 (*) [16])(*pauVar7 + iVar1 * 4);
        pauVar8 = (u8 (*) [16])(*pauVar8 + iVar10);
      } while (iVar5 < param_4);
    }
  }
  return;
}

// FUN_0047CFD0 NONMATCHING

float FUN_0047cfd0(u32 *param_1,u8 (*param_2) [12],u8 (*param_3) [12],
                  int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  u32 uVar5;
  u8 (*pauVar6) [16];
  int iVar7;
  float *pfVar8;
  u8 (*pauVar9) [16];
  float *pfVar10;
  u64 *puVar11;
  int iVar12;
  float *pfVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  u8 (*pauVar17) [16];
  float *pfVar18;
  u8 (*pauVar19) [16];
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
  Vec128 in_vf0;
  Vec128 auVar30;
  Vec128 auVar31;
  Vec128 auVar32;
  Vec128 auVar33;
  Vec128 auVar34;
  Vec128 auVar35;
  Vec128 auVar36;
  Vec128 auVar37;
  Vec128 auVar38;
  Vec128 auVar39;
  Vec128 extraout_vf10;
  Vec128 auVar40;
  Vec128 extraout_vf11;
  Vec128 auVar41;
  Vec128 extraout_vf12;
  Vec128 auVar42;
  Vec128 extraout_vf13;
  Vec128 auVar43;
  Vec128 auVar44;
  Vec128 auVar45;
  Vec128 auVar46;
  Vec128 auVar47;
  u32 in_vuI;
  u32 uStack_c;
  u32 uStack_4;
  
  iVar1 = *(int *)(param_5 + 0x38);
  fVar20 = *(float *)(param_5 + 0x74);
  iVar2 = *(int *)(param_5 + 8);
  iVar3 = param_1[1];
  pauVar19 = *(u8 (**) [16])(param_5 + 4);
  pfVar18 = *(float **)(param_5 + 0x34);
  pauVar17 = (u8 (*) [16])*param_1;
  fVar29 = *(float *)(param_5 + 0x70) * 0.5;
  fVar28 = fVar20 * 0.5;
  if (iVar2 == iVar3) {
    FlushCache(0);
    uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar5 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar4 = getCopCondition(0,0);
      } while (cVar4 == '\0');
    }
    uVar5 = REG_DMAC_9_SPR_TO_CHCR;
    if ((uVar5 & 0x100) != 0) {
      REG_DMAC_PCR = 0x200;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar4 = getCopCondition(0,0);
      } while (cVar4 == '\0');
      do {
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      } while ((uVar5 & 0x100) != 0);
    }
    DAT_70003f00 = *(u32 *)*param_2;
    DAT_70003f04 = *(u32 *)(*param_2 + 4);
    DAT_70003f08 = *(u32 *)(*param_2 + 8);
    DAT_70003f10 = *(u32 *)*param_3;
    DAT_70003f14 = *(u32 *)(*param_3 + 4);
    DAT_70003f18 = *(u32 *)(*param_3 + 8);
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    _ctc2(0x3fc90fdb);
    _vnop();
    _vnop();
    auVar40 = _vaddi(extraout_vf10,in_vuI);
    _ctc2(0x40490fdb);
    _vnop();
    _vnop();
    auVar40 = _vaddi(auVar40,in_vuI);
    _ctc2(0x40090fdb);
    _vnop();
    _vnop();
    auVar40 = _vaddi(auVar40,in_vuI);
    _ctc2(0xc0490fdb);
    _vnop();
    _vnop();
    auVar41 = _vaddi(extraout_vf11,in_vuI);
    fVar20 = -4.1415925;
    _ctc2(0xc08487ed);
    _vnop();
    _vnop();
    auVar41 = _vaddi(auVar41,in_vuI);
    _ctc2(0xb94fb21f);
    _vnop();
    _vnop();
    auVar41 = _vaddi(auVar41,in_vuI);
    _ctc2(0xbe2aaaa4);
    _vnop();
    _vnop();
    auVar42 = _vaddi(extraout_vf12,in_vuI);
    _ctc2(0x3c08873e);
    _vnop();
    _vnop();
    auVar42 = _vaddi(auVar42,in_vuI);
    _ctc2(0x362e9c14);
    _vnop();
    _vnop();
    auVar42 = _vaddi(auVar42,in_vuI);
    _ctc2(0x3f800000);
    _vnop();
    _vnop();
    auVar43 = _vaddi(extraout_vf13,in_vuI);
    EI();
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    auVar30._12_4_ = uRam70003f0c;
    auVar30._0_4_ = *(u32 *)*param_2;
    auVar30._4_4_ = *(u32 *)(*param_2 + 4);
    auVar30._8_4_ = *(u32 *)(*param_2 + 8 + 8);
    auVar30 = _lqc2(auVar30);
    auVar33._4_4_ = fVar29;
    auVar33._0_4_ = fVar29;
    auVar33._8_4_ = fVar29;
    auVar33._12_4_ = fVar29;
    auVar33 = _lqc2(auVar33);
    auVar31._12_4_ = uRam70003f1c;
    auVar31._0_4_ = *(u32 *)*param_3;
    auVar31._4_4_ = *(u32 *)(*param_3 + 4);
    auVar31._8_4_ = *(u32 *)(*param_3 + 8 + 8);
    auVar31 = _lqc2(auVar31);
    auVar34._4_4_ = fVar28;
    auVar34._0_4_ = fVar28;
    auVar34._8_4_ = fVar28;
    auVar34._12_4_ = fVar28;
    auVar34 = _lqc2(auVar34);
    _vnop();
    auVar39 = _vmul(auVar30,auVar33);
    auVar33 = _vmul(auVar31,auVar33);
    auVar30 = _vmul(auVar30,auVar34);
    auVar31 = _vmul(auVar31,auVar34);
    EI();
    DAT_70003f30 = fVar29;
    DAT_70003f34 = fVar29;
    DAT_70003f38 = fVar29;
    DAT_70003f3c = fVar29;
    DAT_70003f40 = fVar28;
    DAT_70003f44 = fVar28;
    DAT_70003f48 = fVar28;
    DAT_70003f4c = fVar28;
    if (0xbf < param_4) {
      do {
        uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
        }
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar5 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar5 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0;
        REG_DMAC_9_SPR_TO_MADR = (u32)(pfVar18);
        REG_DMAC_9_SPR_TO_QWC = 0x30;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar5 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar5 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0x300;
        REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar19);
        REG_DMAC_9_SPR_TO_QWC = 0xc0;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar5 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar5 & 0x100) != 0);
        }
        puVar11 = (u64 *)(u8 *)DAT_70000000;
        iVar14 = 0;
        pauVar6 = (u8 (*) [16])(u8 *)DAT_70000f00;
        pauVar9 = (u8 (*) [16])(u8 *)DAT_70000300;
        do {
          DAT_70003f20 = *(u32 *)puVar11;
          DAT_70003f24 = *(u32 *)((int)puVar11 + 4);
          DAT_70003f28 = *(u32 *)puVar11;
          fVar20 = *(float *)((int)puVar11 + 4);
          do {
            DI();
            SYNC(0x10);
          } while ((Status & 0x10000) != 0);
          auVar37._8_4_ = DAT_70003f28;
          auVar37._0_8_ = *puVar11;
          auVar37._12_4_ = fVar20;
          auVar34 = _lqc2(auVar37);
          auVar45 = _lqc2(*pauVar9);
          auVar47 = _lqc2(pauVar9[1]);
          auVar37 = _vabs(auVar34);
          _vaddabc(in_vf0,auVar40);
          _vmsubbc(auVar37,in_vf0);
          _vaddabc(in_vf0,auVar40);
          _vaddabc(in_vf0,auVar40);
          auVar37 = _vmsubbc(auVar34,in_vf0);
          _vaddabc(in_vf0,auVar41);
          _vaddabc(in_vf0,auVar41);
          auVar32 = _vmsubbc(auVar34,in_vf0);
          auVar34 = _vmini(auVar34,auVar37);
          auVar38 = _vmax(auVar34,auVar32);
          auVar34 = _vmul(auVar38,auVar38);
          auVar36 = _vmulbc(auVar38,auVar41);
          auVar32 = _vmulbc(auVar38,auVar42);
          auVar35 = _vmulbc(auVar38,auVar42);
          auVar37 = _vmul(auVar34,auVar34);
          auVar36 = _vmul(auVar36,auVar34);
          _vmula(auVar32,auVar34);
          auVar32 = _vmulbc(auVar38,auVar42);
          auVar34 = _vmul(auVar37,auVar37);
          _vmadda(auVar36,auVar37);
          _vmadda(auVar35,auVar37);
          _vmaddabc(auVar38,auVar43);
          auVar36 = _vmadd(auVar32,auVar34);
          auVar34 = _vmulbc(auVar39,auVar36);
          auVar37 = _vmulbc(auVar33,auVar36);
          auVar32 = _vmulbc(auVar30,auVar36);
          auVar35 = _vmulbc(auVar31,auVar36);
          auVar38 = _vsub(auVar34,auVar37);
          auVar44 = _vadd(auVar32,auVar35);
          auVar34 = _vmulbc(auVar39,auVar36);
          auVar37 = _vmulbc(auVar33,auVar36);
          auVar32 = _vmulbc(auVar30,auVar36);
          auVar35 = _vmulbc(auVar31,auVar36);
          auVar36 = _vsub(auVar34,auVar37);
          auVar46 = _vadd(auVar32,auVar35);
          auVar34 = _vsub(auVar45,auVar38);
          auVar37 = _vadd(auVar45,auVar38);
          auVar32 = _vadd(auVar45,auVar38);
          auVar35 = _vsub(auVar45,auVar38);
          auVar34 = _vsub(auVar34,auVar44);
          auVar37 = _vsub(auVar37,auVar44);
          auVar32 = _vadd(auVar32,auVar44);
          auVar35 = _vadd(auVar35,auVar44);
          auVar38 = _vsub(auVar47,auVar36);
          auVar44 = _vadd(auVar47,auVar36);
          auVar45 = _vadd(auVar47,auVar36);
          auVar47 = _vsub(auVar47,auVar36);
          auVar36 = _vsub(auVar38,auVar46);
          auVar38 = _vsub(auVar44,auVar46);
          auVar44 = _vadd(auVar45,auVar46);
          auVar45 = _vadd(auVar47,auVar46);
          auVar34 = _sqc2(auVar34);
          DAT_70003f2c = fVar20;
          *(Vec128 *)pauVar6 = auVar34;
          auVar34 = _sqc2(auVar37);
          ((Vec128 *)pauVar6)[1] = auVar34;
          auVar34 = _sqc2(auVar32);
          ((Vec128 *)pauVar6)[2] = auVar34;
          auVar34 = _sqc2(auVar35);
          ((Vec128 *)pauVar6)[3] = auVar34;
          auVar34 = _sqc2(auVar36);
          ((Vec128 *)pauVar6)[4] = auVar34;
          auVar34 = _sqc2(auVar38);
          ((Vec128 *)pauVar6)[5] = auVar34;
          auVar34 = _sqc2(auVar44);
          ((Vec128 *)pauVar6)[6] = auVar34;
          auVar34 = _sqc2(auVar45);
          ((Vec128 *)pauVar6)[7] = auVar34;
          EI();
          iVar14 = iVar14 + 2;
          pauVar9 = pauVar9 + 2;
          puVar11 = puVar11 + 1;
          pauVar6 = pauVar6 + 8;
        } while (iVar14 < 0xc0);
        uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
        }
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar5 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar5 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x100;
        REG_DMAC_8_SPR_FROM_SADR = 0xf00;
        REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar17);
        REG_DMAC_8_SPR_FROM_QWC = 0x300;
        REG_DMAC_8_SPR_FROM_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        param_4 = param_4 + -0xc0;
        pauVar19 = pauVar19 + 0xc0;
        pauVar17 = pauVar17 + 0x300;
        pfVar18 = pfVar18 + 0xc0;
      } while (0xbf < param_4);
    }
    if (3 < param_4) {
      iVar14 = param_4;
      if (param_4 < 0) {
        iVar14 = param_4 + 3;
      }
      iVar14 = iVar14 >> 2;
      iVar12 = iVar14 * 4;
      uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
      }
      uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar5 & 0x100) != 0);
      }
      iVar15 = iVar12 >> 2;
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = 0;
      REG_DMAC_9_SPR_TO_MADR = (u32)(pfVar18);
      iVar16 = iVar15;
      if (iVar12 < 0) {
        iVar16 = iVar12 + 3 >> 2;
      }
      REG_DMAC_9_SPR_TO_QWC = iVar16;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar5 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = iVar16 << 4;
      REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar19);
      REG_DMAC_9_SPR_TO_QWC = iVar12;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar5 & 0x100) != 0);
      }
      puVar11 = (u64 *)(u8 *)DAT_70000000;
      iVar7 = iVar15;
      if (iVar12 < 0) {
        iVar7 = iVar12 + 3 >> 2;
      }
      pauVar9 = (u8 (*) [16])(iVar16 << 4 | 0x70000000);
      pauVar6 = (u8 (*) [16])((iVar12 + iVar7) * 0x10 | 0x70000000);
      iVar16 = 0;
      if (0 < iVar12) {
        do {
          DAT_70003f20 = *(u32 *)puVar11;
          DAT_70003f24 = *(u32 *)((int)puVar11 + 4);
          DAT_70003f28 = *(u32 *)puVar11;
          fVar20 = *(float *)((int)puVar11 + 4);
          do {
            DI();
            SYNC(0x10);
          } while ((Status & 0x10000) != 0);
          auVar32._8_4_ = DAT_70003f28;
          auVar32._0_8_ = *puVar11;
          auVar32._12_4_ = fVar20;
          auVar34 = _lqc2(auVar32);
          auVar45 = _lqc2(*pauVar9);
          auVar47 = _lqc2(pauVar9[1]);
          auVar37 = _vabs(auVar34);
          _vaddabc(in_vf0,auVar40);
          _vmsubbc(auVar37,in_vf0);
          _vaddabc(in_vf0,auVar40);
          _vaddabc(in_vf0,auVar40);
          auVar37 = _vmsubbc(auVar34,in_vf0);
          _vaddabc(in_vf0,auVar41);
          _vaddabc(in_vf0,auVar41);
          auVar32 = _vmsubbc(auVar34,in_vf0);
          auVar34 = _vmini(auVar34,auVar37);
          auVar38 = _vmax(auVar34,auVar32);
          auVar34 = _vmul(auVar38,auVar38);
          auVar36 = _vmulbc(auVar38,auVar41);
          auVar32 = _vmulbc(auVar38,auVar42);
          auVar35 = _vmulbc(auVar38,auVar42);
          auVar37 = _vmul(auVar34,auVar34);
          auVar36 = _vmul(auVar36,auVar34);
          _vmula(auVar32,auVar34);
          auVar32 = _vmulbc(auVar38,auVar42);
          auVar34 = _vmul(auVar37,auVar37);
          _vmadda(auVar36,auVar37);
          _vmadda(auVar35,auVar37);
          _vmaddabc(auVar38,auVar43);
          auVar36 = _vmadd(auVar32,auVar34);
          auVar34 = _vmulbc(auVar39,auVar36);
          auVar37 = _vmulbc(auVar33,auVar36);
          auVar32 = _vmulbc(auVar30,auVar36);
          auVar35 = _vmulbc(auVar31,auVar36);
          auVar38 = _vsub(auVar34,auVar37);
          auVar44 = _vadd(auVar32,auVar35);
          auVar34 = _vmulbc(auVar39,auVar36);
          auVar37 = _vmulbc(auVar33,auVar36);
          auVar32 = _vmulbc(auVar30,auVar36);
          auVar35 = _vmulbc(auVar31,auVar36);
          auVar36 = _vsub(auVar34,auVar37);
          auVar46 = _vadd(auVar32,auVar35);
          auVar34 = _vsub(auVar45,auVar38);
          auVar37 = _vadd(auVar45,auVar38);
          auVar32 = _vadd(auVar45,auVar38);
          auVar35 = _vsub(auVar45,auVar38);
          auVar34 = _vsub(auVar34,auVar44);
          auVar37 = _vsub(auVar37,auVar44);
          auVar32 = _vadd(auVar32,auVar44);
          auVar35 = _vadd(auVar35,auVar44);
          auVar38 = _vsub(auVar47,auVar36);
          auVar44 = _vadd(auVar47,auVar36);
          auVar45 = _vadd(auVar47,auVar36);
          auVar47 = _vsub(auVar47,auVar36);
          auVar36 = _vsub(auVar38,auVar46);
          auVar38 = _vsub(auVar44,auVar46);
          auVar44 = _vadd(auVar45,auVar46);
          auVar45 = _vadd(auVar47,auVar46);
          auVar34 = _sqc2(auVar34);
          DAT_70003f2c = fVar20;
          *(Vec128 *)pauVar6 = auVar34;
          auVar34 = _sqc2(auVar37);
          ((Vec128 *)pauVar6)[1] = auVar34;
          auVar34 = _sqc2(auVar32);
          ((Vec128 *)pauVar6)[2] = auVar34;
          auVar34 = _sqc2(auVar35);
          ((Vec128 *)pauVar6)[3] = auVar34;
          auVar34 = _sqc2(auVar36);
          ((Vec128 *)pauVar6)[4] = auVar34;
          auVar34 = _sqc2(auVar38);
          ((Vec128 *)pauVar6)[5] = auVar34;
          auVar34 = _sqc2(auVar44);
          ((Vec128 *)pauVar6)[6] = auVar34;
          auVar34 = _sqc2(auVar45);
          ((Vec128 *)pauVar6)[7] = auVar34;
          EI();
          iVar16 = iVar16 + 2;
          pauVar9 = pauVar9 + 2;
          puVar11 = puVar11 + 1;
          pauVar6 = pauVar6 + 8;
        } while (iVar16 < iVar12);
      }
      uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
      }
      uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar5 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x100;
      if (iVar12 < 0) {
        iVar15 = iVar12 + 3 >> 2;
      }
      REG_DMAC_8_SPR_FROM_SADR = (iVar12 + iVar15) * 0x10;
      REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar17);
      REG_DMAC_8_SPR_FROM_QWC = iVar14 << 4;
      REG_DMAC_8_SPR_FROM_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      pfVar18 = pfVar18 + iVar15 * 4;
      pauVar17 = pauVar17 + iVar14 * 0x10;
      param_4 = param_4 + iVar14 * -4;
      pauVar19 = pauVar19 + iVar14 * 4;
    }
    iVar14 = 0;
    if (0 < param_4) {
      do {
        fVar20 = *pfVar18;
        auVar35._4_4_ = uStack_c;
        auVar35._0_4_ = fVar20;
        auVar35._8_4_ = fVar20;
        auVar35._12_4_ = uStack_4;
        auVar34 = _lqc2(auVar35);
        auVar44 = _lqc2(*pauVar19);
        auVar37 = _vabs(auVar34);
        _vaddabc(in_vf0,auVar40);
        _vmsubbc(auVar37,in_vf0);
        _vaddabc(in_vf0,auVar40);
        _vaddabc(in_vf0,auVar40);
        auVar37 = _vmsubbc(auVar34,in_vf0);
        _vaddabc(in_vf0,auVar41);
        _vaddabc(in_vf0,auVar41);
        auVar32 = _vmsubbc(auVar34,in_vf0);
        auVar34 = _vmini(auVar34,auVar37);
        auVar38 = _vmax(auVar34,auVar32);
        auVar34 = _vmul(auVar38,auVar38);
        auVar36 = _vmulbc(auVar38,auVar41);
        auVar32 = _vmulbc(auVar38,auVar42);
        auVar35 = _vmulbc(auVar38,auVar42);
        auVar37 = _vmul(auVar34,auVar34);
        auVar36 = _vmul(auVar36,auVar34);
        _vmula(auVar32,auVar34);
        auVar32 = _vmulbc(auVar38,auVar42);
        auVar34 = _vmul(auVar37,auVar37);
        _vmadda(auVar36,auVar37);
        _vmadda(auVar35,auVar37);
        _vmaddabc(auVar38,auVar43);
        auVar35 = _vmadd(auVar32,auVar34);
        auVar34 = _vmulbc(auVar39,auVar35);
        auVar37 = _vmulbc(auVar33,auVar35);
        auVar32 = _vmulbc(auVar30,auVar35);
        auVar35 = _vmulbc(auVar31,auVar35);
        auVar34 = _vsub(auVar34,auVar37);
        auVar37 = _vadd(auVar32,auVar35);
        auVar32 = _vsub(auVar44,auVar34);
        auVar35 = _vadd(auVar44,auVar34);
        auVar36 = _vadd(auVar44,auVar34);
        auVar38 = _vsub(auVar44,auVar34);
        auVar34 = _vsub(auVar32,auVar37);
        auVar32 = _vsub(auVar35,auVar37);
        auVar35 = _vadd(auVar36,auVar37);
        auVar37 = _vadd(auVar38,auVar37);
        auVar34 = _sqc2(auVar34);
        *(Vec128 *)pauVar17 = auVar34;
        auVar34 = _sqc2(auVar32);
        ((Vec128 *)pauVar17)[1] = auVar34;
        auVar34 = _sqc2(auVar35);
        ((Vec128 *)pauVar17)[2] = auVar34;
        auVar34 = _sqc2(auVar37);
        ((Vec128 *)pauVar17)[3] = auVar34;
        EI();
        iVar14 = iVar14 + 1;
        pauVar19 = (u8 (*) [16])(*pauVar19 + iVar2);
        pfVar18 = (float *)((int)pfVar18 + iVar1);
        pauVar17 = (u8 (*) [16])(*pauVar17 + iVar3 * 4);
      } while (iVar14 < param_4);
    }
  }
  else {
    iVar14 = 0;
    if (0 < param_4) {
      do {
        fVar20 = (float)((code)FUN_0052e878)(*pfVar18);
        fVar21 = (float)((code)FUN_0052e6d8)(*pfVar18);
        pfVar13 = (float *)(*pauVar17 + iVar3);
        pfVar10 = (float *)((int)pfVar13 + iVar3);
        fVar22 = -fVar20;
        pfVar8 = (float *)((int)pfVar10 + iVar3);
        iVar14 = iVar14 + 1;
        fVar25 = (fVar21 * *(float *)*param_2 + fVar22 * *(float *)*param_3) * fVar29;
        pfVar18 = (float *)((int)pfVar18 + iVar1);
        fVar27 = (fVar21 * *(float *)(*param_2 + 4) + fVar22 * *(float *)(*param_3 + 4)) * fVar29;
        fVar24 = (fVar20 * *(float *)(*param_2 + 4) + fVar21 * *(float *)(*param_3 + 4)) * fVar28;
        fVar23 = (fVar20 * *(float *)*param_2 + fVar21 * *(float *)*param_3) * fVar28;
        fVar26 = (fVar20 * *(float *)(*param_2 + 8) + fVar21 * *(float *)(*param_3 + 8)) * fVar28;
        fVar20 = (fVar21 * *(float *)(*param_2 + 8) + fVar22 * *(float *)(*param_3 + 8)) * fVar29;
        *(float *)*pauVar17 = *(float *)*pauVar19 + (-fVar25 - fVar23);
        *(float *)(*pauVar17 + 4) = *(float *)(*pauVar19 + 4) + (-fVar27 - fVar24);
        *(float *)(*pauVar17 + 8) = *(float *)(*pauVar19 + 8) + (-fVar20 - fVar26);
        pauVar17 = (u8 (*) [16])((int)pfVar8 + iVar3);
        *pfVar13 = *(float *)*pauVar19 + (fVar25 - fVar23);
        pfVar13[1] = *(float *)(*pauVar19 + 4) + (fVar27 - fVar24);
        pfVar13[2] = *(float *)(*pauVar19 + 8) + (fVar20 - fVar26);
        *pfVar10 = *(float *)*pauVar19 + fVar25 + fVar23;
        pfVar10[1] = *(float *)(*pauVar19 + 4) + fVar27 + fVar24;
        pfVar10[2] = *(float *)(*pauVar19 + 8) + fVar20 + fVar26;
        *pfVar8 = *(float *)*pauVar19 + -fVar25 + fVar23;
        pfVar8[1] = *(float *)(*pauVar19 + 4) + -fVar27 + fVar24;
        fVar20 = *(float *)(*pauVar19 + 8) + -fVar20 + fVar26;
        pauVar19 = (u8 (*) [16])(*pauVar19 + iVar2);
        pfVar8[2] = fVar20;
      } while (iVar14 < param_4);
    }
  }
  return fVar20;
}

// FUN_0047DE30 NONMATCHING

u32
FUN_0047de30(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  u32 uVar5;
  u8 (*pauVar6) [16];
  int iVar7;
  u8 (*pauVar8) [16];
  u8 (*pauVar9) [16];
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  u8 (*pauVar14) [16];
  u64 *puVar15;
  u8 (*pauVar16) [16];
  u8 (*pauVar17) [12];
  u8 (*pauVar18) [12];
  u32 uVar19;
  Vec128 auVar20;
  Vec128 auVar21;
  Vec128 auVar22;
  Vec128 auVar23;
  Vec128 auVar24;
  Vec128 auVar25;
  Vec128 auVar26;
  Vec128 auVar27;
  Vec128 auVar28;
  Vec128 auVar29;
  Vec128 auVar30;
  Vec128 auVar31;
  Vec128 auVar32;
  Vec128 auVar33;
  Vec128 auVar34;
  Vec128 auVar35;
  Vec128 auVar36;
  Vec128 auVar37;
  Vec128 auVar38;
  Vec128 auVar39;
  u32 in_vuI;
  u64 uStack_38;
  Vec128 auStack_30;
  Vec128 auStack_20;
  u64 uStack_8;
  
  iVar1 = *(int *)(param_5 + 8);
  iVar2 = param_1[1];
  pauVar16 = *(u8 (**) [16])(param_5 + 4);
  puVar15 = *(u64 **)(param_5 + 0x1c);
  iVar3 = *(int *)(param_5 + 0x20);
  pauVar14 = (u8 (*) [16])*param_1;
  if (iVar1 == iVar2) {
    FlushCache(0);
    uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar5 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar4 = getCopCondition(0,0);
      } while (cVar4 == '\0');
    }
    uVar5 = REG_DMAC_9_SPR_TO_CHCR;
    if ((uVar5 & 0x100) != 0) {
      REG_DMAC_PCR = 0x200;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar4 = getCopCondition(0,0);
      } while (cVar4 == '\0');
      do {
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      } while ((uVar5 & 0x100) != 0);
    }
    pauVar18 = (u8 (*) [12])param_2;
    DAT_70003f50 = *(u32 *)*pauVar18;
    DAT_70003f54 = *(u32 *)(*pauVar18 + 4);
    DAT_70003f58 = *(u32 *)(*pauVar18 + 8);
    pauVar17 = (u8 (*) [12])param_3;
    DAT_70003f60 = *(u32 *)*pauVar17;
    DAT_70003f64 = *(u32 *)(*pauVar17 + 4);
    DAT_70003f68 = *(u32 *)(*pauVar17 + 8);
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    uVar19 = 0x3f000000;
    _ctc2(0x3f000000);
    _vnop();
    _vnop();
    auVar20._12_4_ = uRam70003f5c;
    auVar20._0_4_ = *(u32 *)*pauVar18;
    auVar20._4_4_ = *(u32 *)(*pauVar18 + 4);
    auVar20._8_4_ = *(u32 *)(*pauVar18 + 8 + 8);
    auVar20 = _lqc2(auVar20);
    auVar21._12_4_ = DAT_70003f6c;
    auVar21._0_4_ = *(u32 *)*pauVar17;
    auVar21._4_4_ = *(u32 *)(*pauVar17 + 4);
    auVar21._8_4_ = *(u32 *)(*pauVar17 + 8 + 8);
    auVar21 = _lqc2(auVar21);
    auVar20 = _vmuli(auVar20,in_vuI);
    auVar21 = _vmuli(auVar21,in_vuI);
    EI();
    if (0xb7 < param_4) {
      do {
        uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
        }
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar5 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar5 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0;
        REG_DMAC_9_SPR_TO_MADR = (u32)(puVar15);
        REG_DMAC_9_SPR_TO_QWC = 0x5c;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar5 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar5 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0x5c0;
        REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar16);
        REG_DMAC_9_SPR_TO_QWC = 0xb8;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar5 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar5 & 0x100) != 0);
        }
        pauVar9 = (u8 (*) [16])(u8 *)DAT_70000000;
        iVar12 = 0;
        pauVar6 = (u8 (*) [16])(u8 *)DAT_70001140;
        pauVar8 = (u8 (*) [16])(u8 *)DAT_700005c0;
        do {
          do {
            DI();
            SYNC(0x10);
          } while ((Status & 0x10000) != 0);
          auVar22 = _lqc2(*pauVar9);
          auVar23 = _vmulbc(auVar20,auVar22);
          auVar24 = _vmulbc(auVar21,auVar22);
          auVar29 = _vmulbc(auVar20,auVar22);
          auVar30 = _vmulbc(auVar21,auVar22);
          auVar25 = _lqc2(*pauVar8);
          auVar31 = _lqc2(pauVar8[1]);
          auVar34 = _lqc2(pauVar8[2]);
          auVar22 = _lqc2(pauVar9[1]);
          auVar38 = _lqc2(pauVar8[3]);
          auVar32 = _vmulbc(auVar20,auVar22);
          auVar33 = _vmulbc(auVar21,auVar22);
          auVar36 = _vmulbc(auVar20,auVar22);
          auVar37 = _vmulbc(auVar21,auVar22);
          auVar22 = _vsub(auVar25,auVar23);
          auVar26 = _vadd(auVar25,auVar23);
          auVar27 = _vadd(auVar25,auVar23);
          auVar28 = _vsub(auVar25,auVar23);
          auVar22 = _vsub(auVar22,auVar24);
          auVar23 = _vsub(auVar26,auVar24);
          auVar25 = _vadd(auVar27,auVar24);
          auVar24 = _vadd(auVar28,auVar24);
          auVar26 = _vsub(auVar31,auVar29);
          auVar27 = _vadd(auVar31,auVar29);
          auVar28 = _vadd(auVar31,auVar29);
          auVar29 = _vsub(auVar31,auVar29);
          auVar26 = _vsub(auVar26,auVar30);
          auVar27 = _vsub(auVar27,auVar30);
          auVar28 = _vadd(auVar28,auVar30);
          auVar29 = _vadd(auVar29,auVar30);
          auVar30 = _vsub(auVar34,auVar32);
          auVar31 = _vadd(auVar34,auVar32);
          auVar35 = _vadd(auVar34,auVar32);
          auVar34 = _vsub(auVar34,auVar32);
          auVar30 = _vsub(auVar30,auVar33);
          auVar31 = _vsub(auVar31,auVar33);
          auVar32 = _vadd(auVar35,auVar33);
          auVar33 = _vadd(auVar34,auVar33);
          auVar34 = _vsub(auVar38,auVar36);
          auVar35 = _vadd(auVar38,auVar36);
          auVar39 = _vadd(auVar38,auVar36);
          auVar38 = _vsub(auVar38,auVar36);
          auVar34 = _vsub(auVar34,auVar37);
          auVar35 = _vsub(auVar35,auVar37);
          auVar36 = _vadd(auVar39,auVar37);
          auVar37 = _vadd(auVar38,auVar37);
          auVar22 = _sqc2(auVar22);
          *(Vec128 *)pauVar6 = auVar22;
          auVar22 = _sqc2(auVar23);
          ((Vec128 *)pauVar6)[1] = auVar22;
          auVar22 = _sqc2(auVar25);
          ((Vec128 *)pauVar6)[2] = auVar22;
          auVar22 = _sqc2(auVar24);
          ((Vec128 *)pauVar6)[3] = auVar22;
          auVar22 = _sqc2(auVar26);
          ((Vec128 *)pauVar6)[4] = auVar22;
          auVar22 = _sqc2(auVar27);
          ((Vec128 *)pauVar6)[5] = auVar22;
          auVar22 = _sqc2(auVar28);
          ((Vec128 *)pauVar6)[6] = auVar22;
          auVar22 = _sqc2(auVar29);
          ((Vec128 *)pauVar6)[7] = auVar22;
          auVar22 = _sqc2(auVar30);
          ((Vec128 *)pauVar6)[8] = auVar22;
          auVar22 = _sqc2(auVar31);
          ((Vec128 *)pauVar6)[9] = auVar22;
          auVar22 = _sqc2(auVar32);
          ((Vec128 *)pauVar6)[10] = auVar22;
          auVar22 = _sqc2(auVar33);
          ((Vec128 *)pauVar6)[0xb] = auVar22;
          auVar22 = _sqc2(auVar34);
          ((Vec128 *)pauVar6)[0xc] = auVar22;
          auVar22 = _sqc2(auVar35);
          ((Vec128 *)pauVar6)[0xd] = auVar22;
          auVar22 = _sqc2(auVar36);
          ((Vec128 *)pauVar6)[0xe] = auVar22;
          auVar22 = _sqc2(auVar37);
          ((Vec128 *)pauVar6)[0xf] = auVar22;
          EI();
          iVar12 = iVar12 + 4;
          pauVar9 = pauVar9 + 2;
          pauVar6 = pauVar6 + 0x10;
          pauVar8 = pauVar8 + 4;
        } while (iVar12 < 0xb8);
        uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
        }
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar5 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar5 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x100;
        REG_DMAC_8_SPR_FROM_SADR = 0x1140;
        REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar14);
        REG_DMAC_8_SPR_FROM_QWC = 0x2e0;
        REG_DMAC_8_SPR_FROM_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        param_4 = param_4 + -0xb8;
        pauVar16 = pauVar16 + 0xb8;
        pauVar14 = pauVar14 + 0x2e0;
        puVar15 = puVar15 + 0xb8;
      } while (0xb7 < param_4);
    }
    if (3 < param_4) {
      iVar12 = param_4;
      if (param_4 < 0) {
        iVar12 = param_4 + 3;
      }
      iVar12 = iVar12 >> 2;
      iVar13 = iVar12 * 4;
      uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
      }
      uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar5 & 0x100) != 0);
      }
      iVar10 = iVar13 >> 1;
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = 0;
      REG_DMAC_9_SPR_TO_MADR = (u32)(puVar15);
      iVar11 = iVar10;
      if (iVar13 < 0) {
        iVar11 = iVar13 + 1 >> 1;
      }
      REG_DMAC_9_SPR_TO_QWC = iVar11;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar5 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = iVar11 << 4;
      REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar16);
      REG_DMAC_9_SPR_TO_QWC = iVar13;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar5 & 0x100) != 0);
      }
      pauVar6 = (u8 (*) [16])(u8 *)DAT_70000000;
      iVar7 = iVar10;
      if (iVar13 < 0) {
        iVar7 = iVar13 + 1 >> 1;
      }
      pauVar9 = (u8 (*) [16])(iVar11 << 4 | 0x70000000);
      pauVar8 = (u8 (*) [16])((iVar13 + iVar7) * 0x10 | 0x70000000);
      iVar11 = 0;
      if (0 < iVar13) {
        do {
          do {
            DI();
            SYNC(0x10);
          } while ((Status & 0x10000) != 0);
          auVar22 = _lqc2(*pauVar6);
          auVar23 = _vmulbc(auVar20,auVar22);
          auVar24 = _vmulbc(auVar21,auVar22);
          auVar29 = _vmulbc(auVar20,auVar22);
          auVar30 = _vmulbc(auVar21,auVar22);
          auVar25 = _lqc2(*pauVar9);
          auVar31 = _lqc2(pauVar9[1]);
          auVar34 = _lqc2(pauVar9[2]);
          auVar22 = _lqc2(pauVar6[1]);
          auVar38 = _lqc2(pauVar9[3]);
          auVar32 = _vmulbc(auVar20,auVar22);
          auVar33 = _vmulbc(auVar21,auVar22);
          auVar36 = _vmulbc(auVar20,auVar22);
          auVar37 = _vmulbc(auVar21,auVar22);
          auVar22 = _vsub(auVar25,auVar23);
          auVar26 = _vadd(auVar25,auVar23);
          auVar27 = _vadd(auVar25,auVar23);
          auVar28 = _vsub(auVar25,auVar23);
          auVar22 = _vsub(auVar22,auVar24);
          auVar23 = _vsub(auVar26,auVar24);
          auVar25 = _vadd(auVar27,auVar24);
          auVar24 = _vadd(auVar28,auVar24);
          auVar26 = _vsub(auVar31,auVar29);
          auVar27 = _vadd(auVar31,auVar29);
          auVar28 = _vadd(auVar31,auVar29);
          auVar29 = _vsub(auVar31,auVar29);
          auVar26 = _vsub(auVar26,auVar30);
          auVar27 = _vsub(auVar27,auVar30);
          auVar28 = _vadd(auVar28,auVar30);
          auVar29 = _vadd(auVar29,auVar30);
          auVar30 = _vsub(auVar34,auVar32);
          auVar31 = _vadd(auVar34,auVar32);
          auVar35 = _vadd(auVar34,auVar32);
          auVar34 = _vsub(auVar34,auVar32);
          auVar30 = _vsub(auVar30,auVar33);
          auVar31 = _vsub(auVar31,auVar33);
          auVar32 = _vadd(auVar35,auVar33);
          auVar33 = _vadd(auVar34,auVar33);
          auVar34 = _vsub(auVar38,auVar36);
          auVar35 = _vadd(auVar38,auVar36);
          auVar39 = _vadd(auVar38,auVar36);
          auVar38 = _vsub(auVar38,auVar36);
          auVar34 = _vsub(auVar34,auVar37);
          auVar35 = _vsub(auVar35,auVar37);
          auVar36 = _vadd(auVar39,auVar37);
          auVar37 = _vadd(auVar38,auVar37);
          auVar22 = _sqc2(auVar22);
          *(Vec128 *)pauVar8 = auVar22;
          auVar22 = _sqc2(auVar23);
          ((Vec128 *)pauVar8)[1] = auVar22;
          auVar22 = _sqc2(auVar25);
          ((Vec128 *)pauVar8)[2] = auVar22;
          auVar22 = _sqc2(auVar24);
          ((Vec128 *)pauVar8)[3] = auVar22;
          auVar22 = _sqc2(auVar26);
          ((Vec128 *)pauVar8)[4] = auVar22;
          auVar22 = _sqc2(auVar27);
          ((Vec128 *)pauVar8)[5] = auVar22;
          auVar22 = _sqc2(auVar28);
          ((Vec128 *)pauVar8)[6] = auVar22;
          auVar22 = _sqc2(auVar29);
          ((Vec128 *)pauVar8)[7] = auVar22;
          auVar22 = _sqc2(auVar30);
          ((Vec128 *)pauVar8)[8] = auVar22;
          auVar22 = _sqc2(auVar31);
          ((Vec128 *)pauVar8)[9] = auVar22;
          auVar22 = _sqc2(auVar32);
          ((Vec128 *)pauVar8)[10] = auVar22;
          auVar22 = _sqc2(auVar33);
          ((Vec128 *)pauVar8)[0xb] = auVar22;
          auVar22 = _sqc2(auVar34);
          ((Vec128 *)pauVar8)[0xc] = auVar22;
          auVar22 = _sqc2(auVar35);
          ((Vec128 *)pauVar8)[0xd] = auVar22;
          auVar22 = _sqc2(auVar36);
          ((Vec128 *)pauVar8)[0xe] = auVar22;
          auVar22 = _sqc2(auVar37);
          ((Vec128 *)pauVar8)[0xf] = auVar22;
          EI();
          iVar11 = iVar11 + 4;
          pauVar6 = pauVar6 + 2;
          pauVar8 = pauVar8 + 0x10;
          pauVar9 = pauVar9 + 4;
        } while (iVar11 < iVar13);
      }
      uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
      }
      uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar5 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x100;
      if (iVar13 < 0) {
        iVar10 = iVar13 + 1 >> 1;
      }
      REG_DMAC_8_SPR_FROM_SADR = (iVar13 + iVar10) * 0x10;
      REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar14);
      REG_DMAC_8_SPR_FROM_QWC = iVar12 << 4;
      REG_DMAC_8_SPR_FROM_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      puVar15 = puVar15 + iVar10 * 2;
      pauVar14 = pauVar14 + iVar12 * 0x10;
      param_4 = param_4 + iVar12 * -4;
      pauVar16 = pauVar16 + iVar12 * 4;
    }
    iVar12 = 0;
    if (0 < param_4) {
      do {
        uVar19 = *(u32 *)((int)puVar15 + 4);
        do {
          DI();
          SYNC(0x10);
        } while ((Status & 0x10000) != 0);
        auVar23._8_8_ = uStack_8;
        auVar23._0_8_ = *puVar15;
        auVar22 = _lqc2(auVar23);
        auVar23 = _vmulbc(auVar20,auVar22);
        auVar22 = _vmulbc(auVar21,auVar22);
        auVar24 = _lqc2(*pauVar16);
        auVar25 = _vsub(auVar24,auVar23);
        auVar26 = _vadd(auVar24,auVar23);
        auVar27 = _vadd(auVar24,auVar23);
        auVar28 = _vsub(auVar24,auVar23);
        auVar23 = _vsub(auVar25,auVar22);
        auVar24 = _vsub(auVar26,auVar22);
        auVar25 = _vadd(auVar27,auVar22);
        auVar26 = _vadd(auVar28,auVar22);
        auVar22 = _sqc2(auVar23);
        *(Vec128 *)pauVar14 = auVar22;
        auVar22 = _sqc2(auVar24);
        ((Vec128 *)pauVar14)[1] = auVar22;
        auVar22 = _sqc2(auVar25);
        ((Vec128 *)pauVar14)[2] = auVar22;
        auVar22 = _sqc2(auVar26);
        ((Vec128 *)pauVar14)[3] = auVar22;
        EI();
        iVar12 = iVar12 + 1;
        puVar15 = (u64 *)((int)puVar15 + iVar3);
        pauVar14 = (u8 (*) [16])(*pauVar14 + iVar2 * 4);
        pauVar16 = (u8 (*) [16])(*pauVar16 + iVar1);
      } while (iVar12 < param_4);
    }
  }
  else {
    ((code)FUN_00521250)(auStack_20,param_2,0xc);
    ((code)FUN_00521250)(auStack_30,param_3,0xc);
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    uVar19 = 0x3f000000;
    _ctc2(0x3f000000);
    _vnop();
    _vnop();
    auVar20 = _lqc2(auStack_20);
    auVar21 = _lqc2(auStack_30);
    auVar20 = _vmuli(auVar20,in_vuI);
    auVar21 = _vmuli(auVar21,in_vuI);
    EI();
    iVar12 = 0;
    if (0 < param_4) {
      do {
        uVar19 = *(u32 *)((int)puVar15 + 4);
        do {
          DI();
          SYNC(0x10);
        } while ((Status & 0x10000) != 0);
        auVar22._8_8_ = uStack_38;
        auVar22._0_8_ = *puVar15;
        auVar22 = _lqc2(auVar22);
        auVar23 = _vmulbc(auVar20,auVar22);
        auVar22 = _vmulbc(auVar21,auVar22);
        auVar24 = _lqc2(*pauVar16);
        auVar25 = _vsub(auVar24,auVar23);
        auVar26 = _vadd(auVar24,auVar23);
        auVar27 = _vadd(auVar24,auVar23);
        auVar28 = _vsub(auVar24,auVar23);
        auVar23 = _vsub(auVar25,auVar22);
        auVar24 = _vsub(auVar26,auVar22);
        auVar25 = _vadd(auVar27,auVar22);
        auVar26 = _vadd(auVar28,auVar22);
        auVar22 = _sqc2(auVar23);
        *(Vec128 *)pauVar14 = auVar22;
        auVar22 = _sqc2(auVar24);
        ((Vec128 *)pauVar14)[1] = auVar22;
        auVar22 = _sqc2(auVar25);
        ((Vec128 *)pauVar14)[2] = auVar22;
        auVar22 = _sqc2(auVar26);
        ((Vec128 *)pauVar14)[3] = auVar22;
        EI();
        iVar12 = iVar12 + 1;
        puVar15 = (u64 *)((int)puVar15 + iVar3);
        pauVar14 = (u8 (*) [16])(*pauVar14 + iVar2 * 4);
        pauVar16 = (u8 (*) [16])(*pauVar16 + iVar1);
      } while (iVar12 < param_4);
    }
  }
  return uVar19;
}

// FUN_0047E9E0 NONMATCHING

u32 FUN_0047e9e0(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  u32 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  u8 (*pauVar11) [16];
  u32 *puVar12;
  u8 (*pauVar13) [16];
  u32 *puVar14;
  u8 (*pauVar15) [16];
  u64 *puVar16;
  int iVar17;
  u8 (*pauVar18) [16];
  u8 (*pauVar19) [16];
  u32 uVar20;
  Vec128 in_vf0;
  Vec128 auVar21;
  Vec128 auVar22;
  Vec128 auVar23;
  Vec128 auVar24;
  Vec128 auVar25;
  Vec128 auVar26;
  Vec128 auVar27;
  Vec128 auVar28;
  Vec128 in_vf10;
  Vec128 extraout_vf10;
  Vec128 auVar29;
  Vec128 in_vf11;
  Vec128 extraout_vf11;
  Vec128 auVar30;
  Vec128 in_vf12;
  Vec128 extraout_vf12;
  Vec128 auVar31;
  Vec128 in_vf13;
  Vec128 extraout_vf13;
  Vec128 auVar32;
  Vec128 auVar33;
  Vec128 auVar34;
  Vec128 auVar35;
  Vec128 auVar36;
  u32 in_vuI;
  u32 uStack_14;
  u32 uStack_4;
  
  iVar1 = *(int *)(param_5 + 8);
  pauVar13 = (u8 (*) [16])*param_1;
  pauVar15 = *(u8 (**) [16])(param_5 + 4);
  puVar14 = *(u32 **)(param_5 + 0x34);
  puVar12 = *(u32 **)(param_5 + 0x1c);
  iVar2 = *(int *)(param_5 + 0x38);
  iVar3 = *(int *)(param_5 + 0x20);
  iVar4 = param_1[1];
  if (iVar1 == iVar4) {
    FlushCache(0);
    uVar6 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar6 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar5 = getCopCondition(0,0);
      } while (cVar5 == '\0');
    }
    uVar6 = REG_DMAC_9_SPR_TO_CHCR;
    if ((uVar6 & 0x100) != 0) {
      REG_DMAC_PCR = 0x200;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar5 = getCopCondition(0,0);
      } while (cVar5 == '\0');
      do {
        uVar6 = REG_DMAC_9_SPR_TO_CHCR;
      } while ((uVar6 & 0x100) != 0);
    }
    DAT_70003f40 = *param_2 * 0.5;
    DAT_70003f44 = param_2[1] * 0.5;
    DAT_70003f48 = param_2[2] * 0.5;
    DAT_70003f50 = *param_3 * 0.5;
    DAT_70003f54 = param_3[1] * 0.5;
    DAT_70003f58 = param_3[2] * 0.5;
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    _ctc2(0x3fc90fdb);
    _vnop();
    _vnop();
    auVar29 = _vaddi(extraout_vf10,in_vuI);
    _ctc2(0x40490fdb);
    _vnop();
    _vnop();
    auVar29 = _vaddi(auVar29,in_vuI);
    _ctc2(0x40090fdb);
    _vnop();
    _vnop();
    auVar29 = _vaddi(auVar29,in_vuI);
    _ctc2(0xc0490fdb);
    _vnop();
    _vnop();
    auVar30 = _vaddi(extraout_vf11,in_vuI);
    uVar20 = 0xc08487ed;
    _ctc2(0xc08487ed);
    _vnop();
    _vnop();
    auVar30 = _vaddi(auVar30,in_vuI);
    _ctc2(0xb94fb21f);
    _vnop();
    _vnop();
    auVar30 = _vaddi(auVar30,in_vuI);
    _ctc2(0xbe2aaaa4);
    _vnop();
    _vnop();
    auVar31 = _vaddi(extraout_vf12,in_vuI);
    _ctc2(0x3c08873e);
    _vnop();
    _vnop();
    auVar31 = _vaddi(auVar31,in_vuI);
    _ctc2(0x362e9c14);
    _vnop();
    _vnop();
    auVar31 = _vaddi(auVar31,in_vuI);
    _ctc2(0x3f800000);
    _vnop();
    _vnop();
    auVar32 = _vaddi(extraout_vf13,in_vuI);
    EI();
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    auVar25._4_4_ = DAT_70003f44;
    auVar25._0_4_ = DAT_70003f40;
    auVar25._8_4_ = DAT_70003f48;
    auVar25._12_4_ = DAT_70003f4c;
    auVar27 = _lqc2(auVar25);
    auVar22._4_4_ = DAT_70003f54;
    auVar22._0_4_ = DAT_70003f50;
    auVar22._8_4_ = DAT_70003f58;
    auVar22._12_4_ = uRam70003f5c;
    auVar28 = _lqc2(auVar22);
    EI();
    if (0xaf < param_4) {
      do {
        uVar6 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar6 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar5 = getCopCondition(0,0);
          } while (cVar5 == '\0');
        }
        uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar6 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar5 = getCopCondition(0,0);
          } while (cVar5 == '\0');
          do {
            uVar6 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar6 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0;
        REG_DMAC_9_SPR_TO_MADR = (u32)(puVar14);
        REG_DMAC_9_SPR_TO_QWC = 0x2c;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar6 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar5 = getCopCondition(0,0);
          } while (cVar5 == '\0');
          do {
            uVar6 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar6 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0x2c0;
        REG_DMAC_9_SPR_TO_MADR = (u32)(puVar12);
        REG_DMAC_9_SPR_TO_QWC = 0x58;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar6 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar5 = getCopCondition(0,0);
          } while (cVar5 == '\0');
          do {
            uVar6 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar6 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0x840;
        REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar15);
        REG_DMAC_9_SPR_TO_QWC = 0xb0;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar6 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar5 = getCopCondition(0,0);
          } while (cVar5 == '\0');
          do {
            uVar6 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar6 & 0x100) != 0);
        }
        puVar16 = (u64 *)(u8 *)DAT_70000000;
        iVar17 = 0;
        pauVar11 = (u8 (*) [16])(u8 *)DAT_70001340;
        pauVar18 = (u8 (*) [16])(u8 *)DAT_70000840;
        pauVar19 = (u8 (*) [16])(u8 *)DAT_700002c0;
        do {
          DAT_70003f60 = *(u32 *)puVar16;
          DAT_70003f64 = *(u32 *)((int)puVar16 + 4);
          DAT_70003f68 = *(u32 *)puVar16;
          uVar20 = *(u32 *)((int)puVar16 + 4);
          do {
            DI();
            SYNC(0x10);
          } while ((Status & 0x10000) != 0);
          auVar23._8_4_ = DAT_70003f68;
          auVar23._0_8_ = *puVar16;
          auVar23._12_4_ = uVar20;
          auVar21 = _lqc2(auVar23);
          auVar25 = _vabs(auVar21);
          _vaddabc(in_vf0,auVar29);
          _vmsubbc(auVar25,in_vf0);
          _vaddabc(in_vf0,auVar29);
          _vaddabc(in_vf0,auVar29);
          auVar25 = _vmsubbc(auVar21,in_vf0);
          _vaddabc(in_vf0,auVar30);
          _vaddabc(in_vf0,auVar30);
          auVar22 = _vmsubbc(auVar21,in_vf0);
          auVar21 = _vmini(auVar21,auVar25);
          auVar26 = _vmax(auVar21,auVar22);
          auVar21 = _vmul(auVar26,auVar26);
          auVar24 = _vmulbc(auVar26,auVar30);
          auVar22 = _vmulbc(auVar26,auVar31);
          auVar23 = _vmulbc(auVar26,auVar31);
          auVar25 = _vmul(auVar21,auVar21);
          auVar24 = _vmul(auVar24,auVar21);
          _vmula(auVar22,auVar21);
          auVar22 = _vmulbc(auVar26,auVar31);
          auVar21 = _vmul(auVar25,auVar25);
          _vmadda(auVar24,auVar25);
          _vmadda(auVar23,auVar25);
          _vmaddabc(auVar26,auVar32);
          auVar21 = _vmadd(auVar22,auVar21);
          auVar24 = _lqc2(*pauVar18);
          auVar35 = _lqc2(pauVar18[1]);
          auVar25 = _lqc2(*pauVar19);
          _vmulabc(auVar27,auVar21);
          auVar22 = _vmsubbc(auVar28,auVar21);
          _vmulabc(auVar28,auVar21);
          auVar23 = _vmaddbc(auVar27,auVar21);
          _vmulabc(auVar27,auVar21);
          auVar26 = _vmsubbc(auVar28,auVar21);
          _vmulabc(auVar28,auVar21);
          auVar34 = _vmaddbc(auVar27,auVar21);
          auVar21 = _vmulbc(auVar22,auVar25);
          auVar22 = _vmulbc(auVar23,auVar25);
          auVar33 = _vmulbc(auVar26,auVar25);
          auVar34 = _vmulbc(auVar34,auVar25);
          auVar25 = _vsub(auVar24,auVar21);
          auVar23 = _vadd(auVar24,auVar21);
          auVar26 = _vadd(auVar24,auVar21);
          auVar24 = _vsub(auVar24,auVar21);
          auVar21 = _vsub(auVar25,auVar22);
          auVar25 = _vsub(auVar23,auVar22);
          auVar23 = _vadd(auVar26,auVar22);
          auVar22 = _vadd(auVar24,auVar22);
          auVar24 = _vsub(auVar35,auVar33);
          auVar26 = _vadd(auVar35,auVar33);
          auVar36 = _vadd(auVar35,auVar33);
          auVar35 = _vsub(auVar35,auVar33);
          auVar24 = _vsub(auVar24,auVar34);
          auVar26 = _vsub(auVar26,auVar34);
          auVar33 = _vadd(auVar36,auVar34);
          auVar34 = _vadd(auVar35,auVar34);
          auVar21 = _sqc2(auVar21);
          DAT_70003f6c = uVar20;
          *(Vec128 *)pauVar11 = auVar21;
          auVar21 = _sqc2(auVar25);
          ((Vec128 *)pauVar11)[1] = auVar21;
          auVar21 = _sqc2(auVar23);
          ((Vec128 *)pauVar11)[2] = auVar21;
          auVar21 = _sqc2(auVar22);
          ((Vec128 *)pauVar11)[3] = auVar21;
          auVar21 = _sqc2(auVar24);
          ((Vec128 *)pauVar11)[4] = auVar21;
          auVar21 = _sqc2(auVar26);
          ((Vec128 *)pauVar11)[5] = auVar21;
          auVar21 = _sqc2(auVar33);
          ((Vec128 *)pauVar11)[6] = auVar21;
          auVar21 = _sqc2(auVar34);
          ((Vec128 *)pauVar11)[7] = auVar21;
          EI();
          iVar17 = iVar17 + 2;
          pauVar18 = pauVar18 + 2;
          pauVar19 = pauVar19 + 1;
          puVar16 = puVar16 + 1;
          pauVar11 = pauVar11 + 8;
        } while (iVar17 < 0xb0);
        uVar6 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar6 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar5 = getCopCondition(0,0);
          } while (cVar5 == '\0');
        }
        uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar6 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar5 = getCopCondition(0,0);
          } while (cVar5 == '\0');
          do {
            uVar6 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar6 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x100;
        REG_DMAC_8_SPR_FROM_SADR = 0x1340;
        REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar13);
        REG_DMAC_8_SPR_FROM_QWC = 0x2c0;
        REG_DMAC_8_SPR_FROM_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        param_4 = param_4 + -0xb0;
        pauVar15 = pauVar15 + 0xb0;
        pauVar13 = pauVar13 + 0x2c0;
        puVar14 = puVar14 + 0xb0;
        puVar12 = puVar12 + 0x160;
      } while (0xaf < param_4);
    }
    if (3 < param_4) {
      iVar17 = param_4;
      if (param_4 < 0) {
        iVar17 = param_4 + 3;
      }
      iVar17 = iVar17 >> 2;
      uVar6 = REG_DMAC_8_SPR_FROM_CHCR;
      iVar7 = iVar17 * 4;
      if ((uVar6 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar5 = getCopCondition(0,0);
        } while (cVar5 == '\0');
      }
      uVar6 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar6 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar5 = getCopCondition(0,0);
        } while (cVar5 == '\0');
        do {
          uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar6 & 0x100) != 0);
      }
      iVar8 = iVar7 >> 2;
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = 0;
      REG_DMAC_9_SPR_TO_MADR = (u32)(puVar14);
      iVar9 = iVar8;
      if (iVar7 < 0) {
        iVar9 = iVar7 + 3 >> 2;
      }
      REG_DMAC_9_SPR_TO_QWC = iVar9;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar6 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar6 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar5 = getCopCondition(0,0);
        } while (cVar5 == '\0');
        do {
          uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar6 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = 0x2c0;
      iVar10 = iVar7 >> 1;
      REG_DMAC_9_SPR_TO_MADR = (u32)(puVar12);
      iVar9 = iVar10;
      if (iVar7 < 0) {
        iVar9 = iVar7 + 1 >> 1;
      }
      REG_DMAC_9_SPR_TO_QWC = iVar9;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar6 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar6 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar5 = getCopCondition(0,0);
        } while (cVar5 == '\0');
        do {
          uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar6 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = 0x840;
      REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar15);
      REG_DMAC_9_SPR_TO_QWC = iVar7;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar6 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar6 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar5 = getCopCondition(0,0);
        } while (cVar5 == '\0');
        do {
          uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar6 & 0x100) != 0);
      }
      puVar16 = (u64 *)(u8 *)DAT_70000000;
      pauVar19 = (u8 (*) [16])(u8 *)DAT_700002c0;
      pauVar18 = (u8 (*) [16])(u8 *)DAT_70000840;
      pauVar11 = (u8 (*) [16])(u8 *)DAT_70001340;
      iVar9 = 0;
      if (0 < iVar7) {
        do {
          DAT_70003f60 = *(u32 *)puVar16;
          DAT_70003f64 = *(u32 *)((int)puVar16 + 4);
          DAT_70003f68 = *(u32 *)puVar16;
          uVar20 = *(u32 *)((int)puVar16 + 4);
          do {
            DI();
            SYNC(0x10);
          } while ((Status & 0x10000) != 0);
          auVar24._8_4_ = DAT_70003f68;
          auVar24._0_8_ = *puVar16;
          auVar24._12_4_ = uVar20;
          auVar21 = _lqc2(auVar24);
          auVar25 = _vabs(auVar21);
          _vaddabc(in_vf0,auVar29);
          _vmsubbc(auVar25,in_vf0);
          _vaddabc(in_vf0,auVar29);
          _vaddabc(in_vf0,auVar29);
          auVar25 = _vmsubbc(auVar21,in_vf0);
          _vaddabc(in_vf0,auVar30);
          _vaddabc(in_vf0,auVar30);
          auVar22 = _vmsubbc(auVar21,in_vf0);
          auVar21 = _vmini(auVar21,auVar25);
          auVar26 = _vmax(auVar21,auVar22);
          auVar21 = _vmul(auVar26,auVar26);
          auVar24 = _vmulbc(auVar26,auVar30);
          auVar22 = _vmulbc(auVar26,auVar31);
          auVar23 = _vmulbc(auVar26,auVar31);
          auVar25 = _vmul(auVar21,auVar21);
          auVar24 = _vmul(auVar24,auVar21);
          _vmula(auVar22,auVar21);
          auVar22 = _vmulbc(auVar26,auVar31);
          auVar21 = _vmul(auVar25,auVar25);
          _vmadda(auVar24,auVar25);
          _vmadda(auVar23,auVar25);
          _vmaddabc(auVar26,auVar32);
          auVar21 = _vmadd(auVar22,auVar21);
          auVar24 = _lqc2(*pauVar18);
          auVar35 = _lqc2(pauVar18[1]);
          auVar25 = _lqc2(*pauVar19);
          _vmulabc(auVar27,auVar21);
          auVar22 = _vmsubbc(auVar28,auVar21);
          _vmulabc(auVar28,auVar21);
          auVar23 = _vmaddbc(auVar27,auVar21);
          _vmulabc(auVar27,auVar21);
          auVar26 = _vmsubbc(auVar28,auVar21);
          _vmulabc(auVar28,auVar21);
          auVar34 = _vmaddbc(auVar27,auVar21);
          auVar21 = _vmulbc(auVar22,auVar25);
          auVar22 = _vmulbc(auVar23,auVar25);
          auVar33 = _vmulbc(auVar26,auVar25);
          auVar34 = _vmulbc(auVar34,auVar25);
          auVar25 = _vsub(auVar24,auVar21);
          auVar23 = _vadd(auVar24,auVar21);
          auVar26 = _vadd(auVar24,auVar21);
          auVar24 = _vsub(auVar24,auVar21);
          auVar21 = _vsub(auVar25,auVar22);
          auVar25 = _vsub(auVar23,auVar22);
          auVar23 = _vadd(auVar26,auVar22);
          auVar22 = _vadd(auVar24,auVar22);
          auVar24 = _vsub(auVar35,auVar33);
          auVar26 = _vadd(auVar35,auVar33);
          auVar36 = _vadd(auVar35,auVar33);
          auVar35 = _vsub(auVar35,auVar33);
          auVar24 = _vsub(auVar24,auVar34);
          auVar26 = _vsub(auVar26,auVar34);
          auVar33 = _vadd(auVar36,auVar34);
          auVar34 = _vadd(auVar35,auVar34);
          auVar21 = _sqc2(auVar21);
          DAT_70003f6c = uVar20;
          *(Vec128 *)pauVar11 = auVar21;
          auVar21 = _sqc2(auVar25);
          ((Vec128 *)pauVar11)[1] = auVar21;
          auVar21 = _sqc2(auVar23);
          ((Vec128 *)pauVar11)[2] = auVar21;
          auVar21 = _sqc2(auVar22);
          ((Vec128 *)pauVar11)[3] = auVar21;
          auVar21 = _sqc2(auVar24);
          ((Vec128 *)pauVar11)[4] = auVar21;
          auVar21 = _sqc2(auVar26);
          ((Vec128 *)pauVar11)[5] = auVar21;
          auVar21 = _sqc2(auVar33);
          ((Vec128 *)pauVar11)[6] = auVar21;
          auVar21 = _sqc2(auVar34);
          ((Vec128 *)pauVar11)[7] = auVar21;
          EI();
          iVar9 = iVar9 + 2;
          pauVar18 = pauVar18 + 2;
          pauVar19 = pauVar19 + 1;
          puVar16 = puVar16 + 1;
          pauVar11 = pauVar11 + 8;
        } while (iVar9 < iVar7);
      }
      uVar6 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar6 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar5 = getCopCondition(0,0);
        } while (cVar5 == '\0');
      }
      uVar6 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar6 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar5 = getCopCondition(0,0);
        } while (cVar5 == '\0');
        do {
          uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar6 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x100;
      REG_DMAC_8_SPR_FROM_SADR = 0x1340;
      REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar13);
      REG_DMAC_8_SPR_FROM_QWC = iVar17 << 4;
      REG_DMAC_8_SPR_FROM_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      pauVar13 = pauVar13 + iVar17 * 0x10;
      pauVar15 = pauVar15 + iVar17 * 4;
      if (iVar7 < 0) {
        iVar8 = iVar7 + 3 >> 2;
      }
      puVar14 = puVar14 + iVar8 * 4;
      if (iVar7 < 0) {
        iVar10 = iVar7 + 1 >> 1;
      }
      param_4 = param_4 + iVar17 * -4;
      puVar12 = puVar12 + iVar10 * 4;
    }
    iVar17 = 0;
    if (0 < param_4) {
      do {
        DAT_70003f60 = *puVar14;
        DAT_70003f64 = *puVar12;
        DAT_70003f68 = *puVar14;
        uVar20 = puVar12[1];
        do {
          DI();
          SYNC(0x10);
        } while ((Status & 0x10000) != 0);
        auVar26._4_4_ = DAT_70003f64;
        auVar26._0_4_ = DAT_70003f60;
        auVar26._8_4_ = DAT_70003f68;
        auVar26._12_4_ = uVar20;
        auVar21 = _lqc2(auVar26);
        auVar25 = _vabs(auVar21);
        _vaddabc(in_vf0,auVar29);
        _vmsubbc(auVar25,in_vf0);
        _vaddabc(in_vf0,auVar29);
        _vaddabc(in_vf0,auVar29);
        auVar25 = _vmsubbc(auVar21,in_vf0);
        _vaddabc(in_vf0,auVar30);
        _vaddabc(in_vf0,auVar30);
        auVar22 = _vmsubbc(auVar21,in_vf0);
        auVar25 = _vmini(auVar21,auVar25);
        auVar33 = _vmax(auVar25,auVar22);
        auVar25 = _vmul(auVar33,auVar33);
        auVar26 = _vmulbc(auVar33,auVar30);
        auVar23 = _vmulbc(auVar33,auVar31);
        auVar24 = _vmulbc(auVar33,auVar31);
        auVar22 = _vmul(auVar25,auVar25);
        auVar26 = _vmul(auVar26,auVar25);
        _vmula(auVar23,auVar25);
        auVar23 = _vmulbc(auVar33,auVar31);
        auVar25 = _vmul(auVar22,auVar22);
        _vmadda(auVar26,auVar22);
        _vmadda(auVar24,auVar22);
        _vmaddabc(auVar33,auVar32);
        auVar25 = _vmadd(auVar23,auVar25);
        auVar23 = _lqc2(*pauVar15);
        _vmulabc(auVar27,auVar25);
        auVar22 = _vmsubbc(auVar28,auVar25);
        auVar22 = _vmulbc(auVar22,auVar21);
        _vmulabc(auVar28,auVar25);
        auVar25 = _vmaddbc(auVar27,auVar25);
        auVar21 = _vmulbc(auVar25,auVar21);
        auVar25 = _vsub(auVar23,auVar22);
        auVar24 = _vadd(auVar23,auVar22);
        auVar26 = _vadd(auVar23,auVar22);
        auVar33 = _vsub(auVar23,auVar22);
        auVar25 = _vsub(auVar25,auVar21);
        auVar22 = _vsub(auVar24,auVar21);
        auVar23 = _vadd(auVar26,auVar21);
        auVar24 = _vadd(auVar33,auVar21);
        auVar21 = _sqc2(auVar25);
        DAT_70003f6c = uVar20;
        *(Vec128 *)pauVar13 = auVar21;
        auVar21 = _sqc2(auVar22);
        ((Vec128 *)pauVar13)[1] = auVar21;
        auVar21 = _sqc2(auVar23);
        ((Vec128 *)pauVar13)[2] = auVar21;
        auVar21 = _sqc2(auVar24);
        ((Vec128 *)pauVar13)[3] = auVar21;
        EI();
        iVar17 = iVar17 + 1;
        pauVar15 = (u8 (*) [16])(*pauVar15 + iVar1);
        puVar12 = (u32 *)((int)puVar12 + iVar3);
        puVar14 = (u32 *)((int)puVar14 + iVar2);
        pauVar13 = (u8 (*) [16])(*pauVar13 + iVar4 * 4);
      } while (iVar17 < param_4);
    }
  }
  else {
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    _ctc2(0x3fc90fdb);
    _vnop();
    _vnop();
    auVar29 = _vaddi(in_vf10,in_vuI);
    _ctc2(0x40490fdb);
    _vnop();
    _vnop();
    auVar29 = _vaddi(auVar29,in_vuI);
    _ctc2(0x40090fdb);
    _vnop();
    _vnop();
    auVar29 = _vaddi(auVar29,in_vuI);
    _ctc2(0xc0490fdb);
    _vnop();
    _vnop();
    auVar30 = _vaddi(in_vf11,in_vuI);
    uVar20 = 0xc08487ed;
    _ctc2(0xc08487ed);
    _vnop();
    _vnop();
    auVar30 = _vaddi(auVar30,in_vuI);
    _ctc2(0xb94fb21f);
    _vnop();
    _vnop();
    auVar30 = _vaddi(auVar30,in_vuI);
    _ctc2(0xbe2aaaa4);
    _vnop();
    _vnop();
    auVar31 = _vaddi(in_vf12,in_vuI);
    _ctc2(0x3c08873e);
    _vnop();
    _vnop();
    auVar31 = _vaddi(auVar31,in_vuI);
    _ctc2(0x362e9c14);
    _vnop();
    _vnop();
    auVar31 = _vaddi(auVar31,in_vuI);
    _ctc2(0x3f800000);
    _vnop();
    _vnop();
    auVar32 = _vaddi(in_vf13,in_vuI);
    EI();
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    auVar28._4_4_ = param_2[1] * 0.5;
    auVar28._0_4_ = *param_2 * 0.5;
    auVar28._8_4_ = param_2[2] * 0.5;
    auVar28._12_4_ = uStack_4;
    auVar28 = _lqc2(auVar28);
    auVar27._4_4_ = param_3[1] * 0.5;
    auVar27._0_4_ = *param_3 * 0.5;
    auVar27._8_4_ = param_3[2] * 0.5;
    auVar27._12_4_ = uStack_14;
    auVar27 = _lqc2(auVar27);
    EI();
    iVar17 = 0;
    if (0 < param_4) {
      do {
        uVar20 = puVar12[1];
        do {
          DI();
          SYNC(0x10);
        } while ((Status & 0x10000) != 0);
        auVar21._4_4_ = *puVar12;
        auVar21._0_4_ = *puVar14;
        auVar21._8_4_ = *puVar14;
        auVar21._12_4_ = uVar20;
        auVar21 = _lqc2(auVar21);
        auVar25 = _vabs(auVar21);
        _vaddabc(in_vf0,auVar29);
        _vmsubbc(auVar25,in_vf0);
        _vaddabc(in_vf0,auVar29);
        _vaddabc(in_vf0,auVar29);
        auVar25 = _vmsubbc(auVar21,in_vf0);
        _vaddabc(in_vf0,auVar30);
        _vaddabc(in_vf0,auVar30);
        auVar22 = _vmsubbc(auVar21,in_vf0);
        auVar25 = _vmini(auVar21,auVar25);
        auVar33 = _vmax(auVar25,auVar22);
        auVar25 = _vmul(auVar33,auVar33);
        auVar26 = _vmulbc(auVar33,auVar30);
        auVar23 = _vmulbc(auVar33,auVar31);
        auVar24 = _vmulbc(auVar33,auVar31);
        auVar22 = _vmul(auVar25,auVar25);
        auVar26 = _vmul(auVar26,auVar25);
        _vmula(auVar23,auVar25);
        auVar23 = _vmulbc(auVar33,auVar31);
        auVar25 = _vmul(auVar22,auVar22);
        _vmadda(auVar26,auVar22);
        _vmadda(auVar24,auVar22);
        _vmaddabc(auVar33,auVar32);
        auVar25 = _vmadd(auVar23,auVar25);
        auVar23 = _lqc2(*pauVar15);
        _vmulabc(auVar28,auVar25);
        auVar22 = _vmsubbc(auVar27,auVar25);
        auVar22 = _vmulbc(auVar22,auVar21);
        _vmulabc(auVar27,auVar25);
        auVar25 = _vmaddbc(auVar28,auVar25);
        auVar21 = _vmulbc(auVar25,auVar21);
        auVar25 = _vsub(auVar23,auVar22);
        auVar24 = _vadd(auVar23,auVar22);
        auVar26 = _vadd(auVar23,auVar22);
        auVar33 = _vsub(auVar23,auVar22);
        auVar25 = _vsub(auVar25,auVar21);
        auVar22 = _vsub(auVar24,auVar21);
        auVar23 = _vadd(auVar26,auVar21);
        auVar24 = _vadd(auVar33,auVar21);
        auVar21 = _sqc2(auVar25);
        *(Vec128 *)pauVar13 = auVar21;
        auVar21 = _sqc2(auVar22);
        ((Vec128 *)pauVar13)[1] = auVar21;
        auVar21 = _sqc2(auVar23);
        ((Vec128 *)pauVar13)[2] = auVar21;
        auVar21 = _sqc2(auVar24);
        ((Vec128 *)pauVar13)[3] = auVar21;
        EI();
        iVar17 = iVar17 + 1;
        pauVar15 = (u8 (*) [16])(*pauVar15 + iVar1);
        puVar12 = (u32 *)((int)puVar12 + iVar3);
        puVar14 = (u32 *)((int)puVar14 + iVar2);
        pauVar13 = (u8 (*) [16])(*pauVar13 + iVar4 * 4);
      } while (iVar17 < param_4);
    }
  }
  return uVar20;
}

// FUN_0047FB10 NONMATCHING

u32
FUN_0047fb10(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  u32 uVar5;
  u8 (*pauVar6) [16];
  u8 (*pauVar7) [16];
  u64 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  u8 (*pauVar13) [16];
  u32 *puVar14;
  u8 (*pauVar15) [16];
  u8 (*pauVar16) [12];
  u8 (*pauVar17) [12];
  u32 uVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  Vec128 in_vf0;
  Vec128 auVar23;
  Vec128 auVar24;
  Vec128 auVar25;
  Vec128 auVar26;
  Vec128 auVar27;
  Vec128 auVar28;
  Vec128 auVar29;
  Vec128 auVar30;
  Vec128 auVar31;
  Vec128 auVar32;
  Vec128 extraout_vf10;
  Vec128 auVar33;
  Vec128 extraout_vf10_00;
  Vec128 extraout_vf11;
  Vec128 auVar34;
  Vec128 extraout_vf11_00;
  Vec128 extraout_vf12;
  Vec128 auVar35;
  Vec128 extraout_vf12_00;
  Vec128 extraout_vf13;
  Vec128 auVar36;
  Vec128 extraout_vf13_00;
  Vec128 auVar37;
  Vec128 auVar38;
  Vec128 auVar39;
  Vec128 auVar40;
  Vec128 auVar41;
  u32 in_vuI;
  u32 uStack_5c;
  u32 uStack_54;
  Vec128 auStack_30;
  Vec128 auStack_20;
  float fStack_10;
  float fStack_c;
  
  iVar1 = param_1[1];
  iVar2 = *(int *)(param_5 + 8);
  pauVar15 = *(u8 (**) [16])(param_5 + 4);
  puVar14 = *(u32 **)(param_5 + 0x34);
  iVar3 = *(int *)(param_5 + 0x38);
  pauVar13 = (u8 (*) [16])*param_1;
  fVar21 = *(float *)(param_5 + 0x70) * 0.5;
  fVar22 = *(float *)(param_5 + 0x74) * 0.5;
  if (iVar2 == iVar1) {
    FlushCache(0);
    uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar5 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar4 = getCopCondition(0,0);
      } while (cVar4 == '\0');
    }
    uVar5 = REG_DMAC_9_SPR_TO_CHCR;
    if ((uVar5 & 0x100) != 0) {
      REG_DMAC_PCR = 0x200;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar4 = getCopCondition(0,0);
      } while (cVar4 == '\0');
      do {
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      } while ((uVar5 & 0x100) != 0);
    }
    DAT_70003f70 = *(float *)(param_5 + 0x68) * (1.0 / fVar21) - 1.0;
    DAT_70003f74 = *(float *)(param_5 + 0x6c) * (1.0 / fVar22) - 1.0;
    DAT_70003f78 = *(float *)(param_5 + 0x68) * (1.0 / fVar21) + 1.0;
    DAT_70003f7c = *(float *)(param_5 + 0x6c) * (1.0 / fVar22) + 1.0;
    pauVar17 = (u8 (*) [12])param_2;
    DAT_70003f00 = *(u32 *)*pauVar17;
    DAT_70003f04 = *(u32 *)(*pauVar17 + 4);
    DAT_70003f08 = *(u32 *)(*pauVar17 + 8);
    pauVar16 = (u8 (*) [12])param_3;
    DAT_70003f10 = *(u32 *)*pauVar16;
    DAT_70003f14 = *(u32 *)(*pauVar16 + 4);
    DAT_70003f18 = *(u32 *)(*pauVar16 + 8);
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    _ctc2(0x3fc90fdb);
    _vnop();
    _vnop();
    auVar33 = _vaddi(extraout_vf10,in_vuI);
    _ctc2(0x40490fdb);
    _vnop();
    _vnop();
    auVar33 = _vaddi(auVar33,in_vuI);
    _ctc2(0x40090fdb);
    _vnop();
    _vnop();
    auVar33 = _vaddi(auVar33,in_vuI);
    _ctc2(0xc0490fdb);
    _vnop();
    _vnop();
    auVar34 = _vaddi(extraout_vf11,in_vuI);
    uVar18 = 0xc08487ed;
    _ctc2(0xc08487ed);
    _vnop();
    _vnop();
    auVar34 = _vaddi(auVar34,in_vuI);
    _ctc2(0xb94fb21f);
    _vnop();
    _vnop();
    auVar34 = _vaddi(auVar34,in_vuI);
    _ctc2(0xbe2aaaa4);
    _vnop();
    _vnop();
    auVar35 = _vaddi(extraout_vf12,in_vuI);
    _ctc2(0x3c08873e);
    _vnop();
    _vnop();
    auVar35 = _vaddi(auVar35,in_vuI);
    _ctc2(0x362e9c14);
    _vnop();
    _vnop();
    auVar35 = _vaddi(auVar35,in_vuI);
    _ctc2(0x3f800000);
    _vnop();
    _vnop();
    auVar36 = _vaddi(extraout_vf13,in_vuI);
    EI();
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    auVar27._12_4_ = uRam70003f0c;
    auVar27._0_4_ = *(u32 *)*pauVar17;
    auVar27._4_4_ = *(u32 *)(*pauVar17 + 4);
    auVar27._8_4_ = *(u32 *)(*pauVar17 + 8 + 8);
    auVar23 = _lqc2(auVar27);
    auVar37._4_4_ = fVar21;
    auVar37._0_4_ = fVar21;
    auVar37._8_4_ = fVar21;
    auVar37._12_4_ = fVar21;
    auVar26 = _lqc2(auVar37);
    auVar32._12_4_ = uRam70003f1c;
    auVar32._0_4_ = *(u32 *)*pauVar16;
    auVar32._4_4_ = *(u32 *)(*pauVar16 + 4);
    auVar32._8_4_ = *(u32 *)(*pauVar16 + 8 + 8);
    auVar24 = _lqc2(auVar32);
    auVar25._4_4_ = fVar22;
    auVar25._0_4_ = fVar22;
    auVar25._8_4_ = fVar22;
    auVar25._12_4_ = fVar22;
    auVar27 = _lqc2(auVar25);
    auVar28._4_4_ = DAT_70003f74;
    auVar28._0_4_ = DAT_70003f70;
    auVar28._8_4_ = DAT_70003f78;
    auVar28._12_4_ = DAT_70003f7c;
    auVar37 = _lqc2(auVar28);
    auVar32 = _vmul(auVar23,auVar26);
    auVar26 = _vmul(auVar24,auVar26);
    auVar23 = _vmul(auVar23,auVar27);
    auVar24 = _vmul(auVar24,auVar27);
    EI();
    DAT_70003f30 = fVar21;
    DAT_70003f34 = fVar21;
    DAT_70003f38 = fVar21;
    DAT_70003f3c = fVar21;
    DAT_70003f40 = fVar22;
    DAT_70003f44 = fVar22;
    DAT_70003f48 = fVar22;
    DAT_70003f4c = fVar22;
    if (0xbf < param_4) {
      do {
        uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
        }
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar5 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar5 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0;
        REG_DMAC_9_SPR_TO_MADR = (u32)(puVar14);
        REG_DMAC_9_SPR_TO_QWC = 0x30;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar5 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar5 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0x300;
        REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar15);
        REG_DMAC_9_SPR_TO_QWC = 0xc0;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar5 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar5 & 0x100) != 0);
        }
        puVar8 = (u64 *)(u8 *)DAT_70000000;
        iVar10 = 0;
        pauVar6 = (u8 (*) [16])(u8 *)DAT_70000f00;
        pauVar7 = (u8 (*) [16])(u8 *)DAT_70000300;
        do {
          DAT_70003f20 = *(u32 *)puVar8;
          DAT_70003f24 = *(u32 *)((int)puVar8 + 4);
          DAT_70003f28 = *(u32 *)puVar8;
          uVar18 = *(u32 *)((int)puVar8 + 4);
          do {
            DI();
            SYNC(0x10);
          } while ((Status & 0x10000) != 0);
          auVar29._8_4_ = DAT_70003f28;
          auVar29._0_8_ = *puVar8;
          auVar29._12_4_ = uVar18;
          auVar27 = _lqc2(auVar29);
          auVar39 = _lqc2(*pauVar7);
          auVar41 = _lqc2(pauVar7[1]);
          auVar30 = _vabs(auVar27);
          _vaddabc(in_vf0,auVar33);
          _vmsubbc(auVar30,in_vf0);
          _vaddabc(in_vf0,auVar33);
          _vaddabc(in_vf0,auVar33);
          auVar30 = _vmsubbc(auVar27,in_vf0);
          _vaddabc(in_vf0,auVar34);
          _vaddabc(in_vf0,auVar34);
          auVar25 = _vmsubbc(auVar27,in_vf0);
          auVar27 = _vmini(auVar27,auVar30);
          auVar31 = _vmax(auVar27,auVar25);
          auVar27 = _vmul(auVar31,auVar31);
          auVar29 = _vmulbc(auVar31,auVar34);
          auVar25 = _vmulbc(auVar31,auVar35);
          auVar28 = _vmulbc(auVar31,auVar35);
          auVar30 = _vmul(auVar27,auVar27);
          auVar29 = _vmul(auVar29,auVar27);
          _vmula(auVar25,auVar27);
          auVar25 = _vmulbc(auVar31,auVar35);
          auVar27 = _vmul(auVar30,auVar30);
          _vmadda(auVar29,auVar30);
          _vmadda(auVar28,auVar30);
          _vmaddabc(auVar31,auVar36);
          auVar29 = _vmadd(auVar25,auVar27);
          auVar27 = _vmulbc(auVar32,auVar29);
          auVar30 = _vmulbc(auVar26,auVar29);
          auVar25 = _vmulbc(auVar23,auVar29);
          auVar28 = _vmulbc(auVar24,auVar29);
          auVar31 = _vsub(auVar27,auVar30);
          auVar27 = _vmulbc(auVar32,auVar29);
          auVar30 = _vmulbc(auVar26,auVar29);
          auVar38 = _vadd(auVar25,auVar28);
          auVar25 = _vmulbc(auVar23,auVar29);
          auVar28 = _vmulbc(auVar24,auVar29);
          auVar29 = _vsub(auVar27,auVar30);
          _vmulabc(auVar38,auVar37);
          _vmaddabc(auVar31,auVar37);
          auVar27 = _vmaddbc(auVar39,in_vf0);
          auVar40 = _vadd(auVar25,auVar28);
          _vmulabc(auVar38,auVar37);
          _vmaddabc(auVar31,auVar37);
          auVar30 = _vmaddbc(auVar39,in_vf0);
          _vmulabc(auVar38,auVar37);
          _vmaddabc(auVar31,auVar37);
          auVar25 = _vmaddbc(auVar39,in_vf0);
          _vmulabc(auVar38,auVar37);
          _vmaddabc(auVar31,auVar37);
          auVar28 = _vmaddbc(auVar39,in_vf0);
          _vmulabc(auVar40,auVar37);
          _vmaddabc(auVar29,auVar37);
          auVar31 = _vmaddbc(auVar41,in_vf0);
          _vmulabc(auVar40,auVar37);
          _vmaddabc(auVar29,auVar37);
          auVar38 = _vmaddbc(auVar41,in_vf0);
          _vmulabc(auVar40,auVar37);
          _vmaddabc(auVar29,auVar37);
          auVar39 = _vmaddbc(auVar41,in_vf0);
          _vmulabc(auVar40,auVar37);
          _vmaddabc(auVar29,auVar37);
          auVar29 = _vmaddbc(auVar41,in_vf0);
          auVar27 = _sqc2(auVar27);
          DAT_70003f2c = uVar18;
          *(Vec128 *)pauVar6 = auVar27;
          auVar27 = _sqc2(auVar30);
          ((Vec128 *)pauVar6)[1] = auVar27;
          auVar27 = _sqc2(auVar25);
          ((Vec128 *)pauVar6)[2] = auVar27;
          auVar27 = _sqc2(auVar28);
          ((Vec128 *)pauVar6)[3] = auVar27;
          auVar27 = _sqc2(auVar31);
          ((Vec128 *)pauVar6)[4] = auVar27;
          auVar27 = _sqc2(auVar38);
          ((Vec128 *)pauVar6)[5] = auVar27;
          auVar27 = _sqc2(auVar39);
          ((Vec128 *)pauVar6)[6] = auVar27;
          auVar27 = _sqc2(auVar29);
          ((Vec128 *)pauVar6)[7] = auVar27;
          EI();
          iVar10 = iVar10 + 2;
          pauVar7 = pauVar7 + 2;
          puVar8 = puVar8 + 1;
          pauVar6 = pauVar6 + 8;
        } while (iVar10 < 0xc0);
        uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
        }
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar5 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar5 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x100;
        REG_DMAC_8_SPR_FROM_SADR = 0xf00;
        REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar13);
        REG_DMAC_8_SPR_FROM_QWC = 0x300;
        REG_DMAC_8_SPR_FROM_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        param_4 = param_4 + -0xc0;
        pauVar15 = pauVar15 + 0xc0;
        pauVar13 = pauVar13 + 0x300;
        puVar14 = puVar14 + 0xc0;
      } while (0xbf < param_4);
    }
    if (3 < param_4) {
      iVar10 = param_4;
      if (param_4 < 0) {
        iVar10 = param_4 + 3;
      }
      iVar10 = iVar10 >> 2;
      iVar9 = iVar10 * 4;
      uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
      }
      uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar5 & 0x100) != 0);
      }
      iVar11 = iVar9 >> 2;
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = 0;
      REG_DMAC_9_SPR_TO_MADR = (u32)(puVar14);
      iVar12 = iVar11;
      if (iVar9 < 0) {
        iVar12 = iVar9 + 3 >> 2;
      }
      REG_DMAC_9_SPR_TO_QWC = iVar12;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar5 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = 0x300;
      REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar15);
      REG_DMAC_9_SPR_TO_QWC = iVar9;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar5 & 0x100) != 0);
      }
      puVar8 = (u64 *)(u8 *)DAT_70000000;
      pauVar7 = (u8 (*) [16])(u8 *)DAT_70000300;
      pauVar6 = (u8 (*) [16])(u8 *)DAT_70000f00;
      iVar12 = 0;
      if (0 < iVar9) {
        do {
          DAT_70003f20 = *(u32 *)puVar8;
          DAT_70003f24 = *(u32 *)((int)puVar8 + 4);
          DAT_70003f28 = *(u32 *)puVar8;
          uVar18 = *(u32 *)((int)puVar8 + 4);
          do {
            DI();
            SYNC(0x10);
          } while ((Status & 0x10000) != 0);
          auVar31._8_4_ = DAT_70003f28;
          auVar31._0_8_ = *puVar8;
          auVar31._12_4_ = uVar18;
          auVar27 = _lqc2(auVar31);
          auVar39 = _lqc2(*pauVar7);
          auVar41 = _lqc2(pauVar7[1]);
          auVar30 = _vabs(auVar27);
          _vaddabc(in_vf0,auVar33);
          _vmsubbc(auVar30,in_vf0);
          _vaddabc(in_vf0,auVar33);
          _vaddabc(in_vf0,auVar33);
          auVar30 = _vmsubbc(auVar27,in_vf0);
          _vaddabc(in_vf0,auVar34);
          _vaddabc(in_vf0,auVar34);
          auVar25 = _vmsubbc(auVar27,in_vf0);
          auVar27 = _vmini(auVar27,auVar30);
          auVar31 = _vmax(auVar27,auVar25);
          auVar27 = _vmul(auVar31,auVar31);
          auVar29 = _vmulbc(auVar31,auVar34);
          auVar25 = _vmulbc(auVar31,auVar35);
          auVar28 = _vmulbc(auVar31,auVar35);
          auVar30 = _vmul(auVar27,auVar27);
          auVar29 = _vmul(auVar29,auVar27);
          _vmula(auVar25,auVar27);
          auVar25 = _vmulbc(auVar31,auVar35);
          auVar27 = _vmul(auVar30,auVar30);
          _vmadda(auVar29,auVar30);
          _vmadda(auVar28,auVar30);
          _vmaddabc(auVar31,auVar36);
          auVar29 = _vmadd(auVar25,auVar27);
          auVar27 = _vmulbc(auVar32,auVar29);
          auVar30 = _vmulbc(auVar26,auVar29);
          auVar25 = _vmulbc(auVar23,auVar29);
          auVar28 = _vmulbc(auVar24,auVar29);
          auVar31 = _vsub(auVar27,auVar30);
          auVar27 = _vmulbc(auVar32,auVar29);
          auVar30 = _vmulbc(auVar26,auVar29);
          auVar38 = _vadd(auVar25,auVar28);
          auVar25 = _vmulbc(auVar23,auVar29);
          auVar28 = _vmulbc(auVar24,auVar29);
          auVar29 = _vsub(auVar27,auVar30);
          _vmulabc(auVar38,auVar37);
          _vmaddabc(auVar31,auVar37);
          auVar27 = _vmaddbc(auVar39,in_vf0);
          auVar40 = _vadd(auVar25,auVar28);
          _vmulabc(auVar38,auVar37);
          _vmaddabc(auVar31,auVar37);
          auVar30 = _vmaddbc(auVar39,in_vf0);
          _vmulabc(auVar38,auVar37);
          _vmaddabc(auVar31,auVar37);
          auVar25 = _vmaddbc(auVar39,in_vf0);
          _vmulabc(auVar38,auVar37);
          _vmaddabc(auVar31,auVar37);
          auVar28 = _vmaddbc(auVar39,in_vf0);
          _vmulabc(auVar40,auVar37);
          _vmaddabc(auVar29,auVar37);
          auVar31 = _vmaddbc(auVar41,in_vf0);
          _vmulabc(auVar40,auVar37);
          _vmaddabc(auVar29,auVar37);
          auVar38 = _vmaddbc(auVar41,in_vf0);
          _vmulabc(auVar40,auVar37);
          _vmaddabc(auVar29,auVar37);
          auVar39 = _vmaddbc(auVar41,in_vf0);
          _vmulabc(auVar40,auVar37);
          _vmaddabc(auVar29,auVar37);
          auVar29 = _vmaddbc(auVar41,in_vf0);
          auVar27 = _sqc2(auVar27);
          DAT_70003f2c = uVar18;
          *(Vec128 *)pauVar6 = auVar27;
          auVar27 = _sqc2(auVar30);
          ((Vec128 *)pauVar6)[1] = auVar27;
          auVar27 = _sqc2(auVar25);
          ((Vec128 *)pauVar6)[2] = auVar27;
          auVar27 = _sqc2(auVar28);
          ((Vec128 *)pauVar6)[3] = auVar27;
          auVar27 = _sqc2(auVar31);
          ((Vec128 *)pauVar6)[4] = auVar27;
          auVar27 = _sqc2(auVar38);
          ((Vec128 *)pauVar6)[5] = auVar27;
          auVar27 = _sqc2(auVar39);
          ((Vec128 *)pauVar6)[6] = auVar27;
          auVar27 = _sqc2(auVar29);
          ((Vec128 *)pauVar6)[7] = auVar27;
          EI();
          iVar12 = iVar12 + 2;
          pauVar7 = pauVar7 + 2;
          puVar8 = puVar8 + 1;
          pauVar6 = pauVar6 + 8;
        } while (iVar12 < iVar9);
      }
      uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
      }
      uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar5 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x100;
      REG_DMAC_8_SPR_FROM_SADR = 0xf00;
      REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar13);
      REG_DMAC_8_SPR_FROM_QWC = iVar10 << 4;
      REG_DMAC_8_SPR_FROM_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      pauVar13 = pauVar13 + iVar10 * 0x10;
      pauVar15 = pauVar15 + iVar10 * 4;
      if (iVar9 < 0) {
        iVar11 = iVar9 + 3 >> 2;
      }
      param_4 = param_4 + iVar10 * -4;
      puVar14 = puVar14 + iVar11 * 4;
    }
    iVar10 = 0;
    if (0 < param_4) {
      do {
        DAT_70003f20 = *puVar14;
        uVar18 = *puVar14;
        do {
          DI();
          SYNC(0x10);
        } while ((Status & 0x10000) != 0);
        auVar38._4_4_ = DAT_70003f24;
        auVar38._0_4_ = DAT_70003f20;
        auVar38._8_4_ = uVar18;
        auVar38._12_4_ = DAT_70003f2c;
        auVar27 = _lqc2(auVar38);
        auVar38 = _lqc2(*pauVar15);
        auVar30 = _vabs(auVar27);
        _vaddabc(in_vf0,auVar33);
        _vmsubbc(auVar30,in_vf0);
        _vaddabc(in_vf0,auVar33);
        _vaddabc(in_vf0,auVar33);
        auVar30 = _vmsubbc(auVar27,in_vf0);
        _vaddabc(in_vf0,auVar34);
        _vaddabc(in_vf0,auVar34);
        auVar25 = _vmsubbc(auVar27,in_vf0);
        auVar27 = _vmini(auVar27,auVar30);
        auVar31 = _vmax(auVar27,auVar25);
        auVar27 = _vmul(auVar31,auVar31);
        auVar29 = _vmulbc(auVar31,auVar34);
        auVar25 = _vmulbc(auVar31,auVar35);
        auVar28 = _vmulbc(auVar31,auVar35);
        auVar30 = _vmul(auVar27,auVar27);
        auVar29 = _vmul(auVar29,auVar27);
        _vmula(auVar25,auVar27);
        auVar25 = _vmulbc(auVar31,auVar35);
        auVar27 = _vmul(auVar30,auVar30);
        _vmadda(auVar29,auVar30);
        _vmadda(auVar28,auVar30);
        _vmaddabc(auVar31,auVar36);
        auVar28 = _vmadd(auVar25,auVar27);
        auVar27 = _vmulbc(auVar32,auVar28);
        auVar30 = _vmulbc(auVar26,auVar28);
        auVar25 = _vmulbc(auVar23,auVar28);
        auVar28 = _vmulbc(auVar24,auVar28);
        auVar27 = _vsub(auVar27,auVar30);
        auVar30 = _vadd(auVar25,auVar28);
        _vmulabc(auVar30,auVar37);
        _vmaddabc(auVar27,auVar37);
        auVar25 = _vmaddbc(auVar38,in_vf0);
        _vmulabc(auVar30,auVar37);
        _vmaddabc(auVar27,auVar37);
        auVar28 = _vmaddbc(auVar38,in_vf0);
        _vmulabc(auVar30,auVar37);
        _vmaddabc(auVar27,auVar37);
        auVar29 = _vmaddbc(auVar38,in_vf0);
        _vmulabc(auVar30,auVar37);
        _vmaddabc(auVar27,auVar37);
        auVar30 = _vmaddbc(auVar38,in_vf0);
        auVar27 = _sqc2(auVar25);
        DAT_70003f28 = uVar18;
        *(Vec128 *)pauVar13 = auVar27;
        auVar27 = _sqc2(auVar28);
        ((Vec128 *)pauVar13)[1] = auVar27;
        auVar27 = _sqc2(auVar29);
        ((Vec128 *)pauVar13)[2] = auVar27;
        auVar27 = _sqc2(auVar30);
        ((Vec128 *)pauVar13)[3] = auVar27;
        EI();
        iVar10 = iVar10 + 1;
        pauVar15 = (u8 (*) [16])(*pauVar15 + iVar2);
        puVar14 = (u32 *)((int)puVar14 + iVar3);
        pauVar13 = (u8 (*) [16])(*pauVar13 + iVar1 * 4);
      } while (iVar10 < param_4);
    }
  }
  else {
    fVar19 = 1.0 / fVar21;
    fStack_10 = *(float *)(param_5 + 0x68) * fVar19;
    fVar20 = 1.0 / fVar22;
    fStack_c = *(float *)(param_5 + 0x6c) * fVar20;
    ((code)FUN_00521250)(auStack_20,param_2,0xc);
    ((code)FUN_00521250)(auStack_30,param_3,0xc);
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    _ctc2(0x3fc90fdb);
    _vnop();
    _vnop();
    auVar33 = _vaddi(extraout_vf10_00,in_vuI);
    _ctc2(0x40490fdb);
    _vnop();
    _vnop();
    auVar33 = _vaddi(auVar33,in_vuI);
    _ctc2(0x40090fdb);
    _vnop();
    _vnop();
    auVar33 = _vaddi(auVar33,in_vuI);
    _ctc2(0xc0490fdb);
    _vnop();
    _vnop();
    auVar34 = _vaddi(extraout_vf11_00,in_vuI);
    uVar18 = 0xc08487ed;
    _ctc2(0xc08487ed);
    _vnop();
    _vnop();
    auVar34 = _vaddi(auVar34,in_vuI);
    _ctc2(0xb94fb21f);
    _vnop();
    _vnop();
    auVar34 = _vaddi(auVar34,in_vuI);
    _ctc2(0xbe2aaaa4);
    _vnop();
    _vnop();
    auVar35 = _vaddi(extraout_vf12_00,in_vuI);
    _ctc2(0x3c08873e);
    _vnop();
    _vnop();
    auVar35 = _vaddi(auVar35,in_vuI);
    _ctc2(0x362e9c14);
    _vnop();
    _vnop();
    auVar35 = _vaddi(auVar35,in_vuI);
    _ctc2(0x3f800000);
    _vnop();
    _vnop();
    auVar36 = _vaddi(extraout_vf13_00,in_vuI);
    EI();
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    auVar27 = _lqc2(auStack_20);
    auVar24._4_4_ = fVar21;
    auVar24._0_4_ = fVar21;
    auVar24._8_4_ = fVar21;
    auVar24._12_4_ = fVar21;
    auVar32 = _lqc2(auVar24);
    auVar24 = _lqc2(auStack_30);
    auVar23._4_4_ = fVar22;
    auVar23._0_4_ = fVar22;
    auVar23._8_4_ = fVar22;
    auVar23._12_4_ = fVar22;
    auVar23 = _lqc2(auVar23);
    auVar26._4_4_ = *(float *)(param_5 + 0x6c) * fVar20 - 1.0;
    auVar26._0_4_ = *(float *)(param_5 + 0x68) * fVar19 - 1.0;
    auVar26._8_4_ = *(float *)(param_5 + 0x68) * fVar19 + 1.0;
    auVar26._12_4_ = *(float *)(param_5 + 0x6c) * fVar20 + 1.0;
    auVar37 = _lqc2(auVar26);
    auVar26 = _vmul(auVar27,auVar32);
    auVar32 = _vmul(auVar24,auVar32);
    auVar27 = _vmul(auVar27,auVar23);
    auVar23 = _vmul(auVar24,auVar23);
    EI();
    iVar10 = 0;
    if (0 < param_4) {
      do {
        uVar18 = *puVar14;
        do {
          DI();
          SYNC(0x10);
        } while ((Status & 0x10000) != 0);
        auVar30._4_4_ = uStack_5c;
        auVar30._0_4_ = uVar18;
        auVar30._8_4_ = uVar18;
        auVar30._12_4_ = uStack_54;
        auVar24 = _lqc2(auVar30);
        auVar38 = _lqc2(*pauVar15);
        auVar30 = _vabs(auVar24);
        _vaddabc(in_vf0,auVar33);
        _vmsubbc(auVar30,in_vf0);
        _vaddabc(in_vf0,auVar33);
        _vaddabc(in_vf0,auVar33);
        auVar30 = _vmsubbc(auVar24,in_vf0);
        _vaddabc(in_vf0,auVar34);
        _vaddabc(in_vf0,auVar34);
        auVar25 = _vmsubbc(auVar24,in_vf0);
        auVar24 = _vmini(auVar24,auVar30);
        auVar31 = _vmax(auVar24,auVar25);
        auVar24 = _vmul(auVar31,auVar31);
        auVar29 = _vmulbc(auVar31,auVar34);
        auVar25 = _vmulbc(auVar31,auVar35);
        auVar28 = _vmulbc(auVar31,auVar35);
        auVar30 = _vmul(auVar24,auVar24);
        auVar29 = _vmul(auVar29,auVar24);
        _vmula(auVar25,auVar24);
        auVar25 = _vmulbc(auVar31,auVar35);
        auVar24 = _vmul(auVar30,auVar30);
        _vmadda(auVar29,auVar30);
        _vmadda(auVar28,auVar30);
        _vmaddabc(auVar31,auVar36);
        auVar28 = _vmadd(auVar25,auVar24);
        auVar24 = _vmulbc(auVar26,auVar28);
        auVar30 = _vmulbc(auVar32,auVar28);
        auVar25 = _vmulbc(auVar27,auVar28);
        auVar28 = _vmulbc(auVar23,auVar28);
        auVar24 = _vsub(auVar24,auVar30);
        auVar30 = _vadd(auVar25,auVar28);
        _vmulabc(auVar30,auVar37);
        _vmaddabc(auVar24,auVar37);
        auVar25 = _vmaddbc(auVar38,in_vf0);
        _vmulabc(auVar30,auVar37);
        _vmaddabc(auVar24,auVar37);
        auVar28 = _vmaddbc(auVar38,in_vf0);
        _vmulabc(auVar30,auVar37);
        _vmaddabc(auVar24,auVar37);
        auVar29 = _vmaddbc(auVar38,in_vf0);
        _vmulabc(auVar30,auVar37);
        _vmaddabc(auVar24,auVar37);
        auVar30 = _vmaddbc(auVar38,in_vf0);
        auVar24 = _sqc2(auVar25);
        *(Vec128 *)pauVar13 = auVar24;
        auVar24 = _sqc2(auVar28);
        ((Vec128 *)pauVar13)[1] = auVar24;
        auVar24 = _sqc2(auVar29);
        ((Vec128 *)pauVar13)[2] = auVar24;
        auVar24 = _sqc2(auVar30);
        ((Vec128 *)pauVar13)[3] = auVar24;
        EI();
        iVar10 = iVar10 + 1;
        pauVar15 = (u8 (*) [16])(*pauVar15 + iVar2);
        puVar14 = (u32 *)((int)puVar14 + iVar3);
        pauVar13 = (u8 (*) [16])(*pauVar13 + iVar1 * 4);
      } while (iVar10 < param_4);
    }
  }
  return uVar18;
}

// FUN_00480C30 NONMATCHING

u32
FUN_00480c30(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  u32 uVar5;
  u8 (*pauVar6) [16];
  int iVar7;
  u8 (*pauVar8) [16];
  u8 (*pauVar9) [16];
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  u8 (*pauVar14) [16];
  u64 *puVar15;
  u8 (*pauVar16) [16];
  u8 (*pauVar17) [12];
  u8 (*pauVar18) [12];
  u32 uVar19;
  Vec128 in_vf0;
  Vec128 auVar20;
  Vec128 auVar21;
  Vec128 auVar22;
  Vec128 auVar23;
  Vec128 auVar24;
  Vec128 auVar25;
  Vec128 auVar26;
  Vec128 auVar27;
  Vec128 auVar28;
  Vec128 auVar29;
  Vec128 auVar30;
  Vec128 auVar31;
  Vec128 auVar32;
  Vec128 auVar33;
  Vec128 auVar34;
  Vec128 auVar35;
  Vec128 auVar36;
  Vec128 auVar37;
  Vec128 auVar38;
  u32 in_vuI;
  u64 uStack_48;
  Vec128 auStack_40;
  Vec128 auStack_30;
  u64 uStack_18;
  u64 uStack_8;
  
  iVar1 = param_1[1];
  iVar2 = *(int *)(param_5 + 8);
  pauVar16 = *(u8 (**) [16])(param_5 + 4);
  puVar15 = *(u64 **)(param_5 + 0x1c);
  iVar3 = *(int *)(param_5 + 0x20);
  pauVar14 = (u8 (*) [16])*param_1;
  if (iVar2 == iVar1) {
    FlushCache(0);
    uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar5 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar4 = getCopCondition(0,0);
      } while (cVar4 == '\0');
    }
    uVar5 = REG_DMAC_9_SPR_TO_CHCR;
    if ((uVar5 & 0x100) != 0) {
      REG_DMAC_PCR = 0x200;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar4 = getCopCondition(0,0);
      } while (cVar4 == '\0');
      do {
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      } while ((uVar5 & 0x100) != 0);
    }
    pauVar18 = (u8 (*) [12])param_2;
    DAT_70003f50 = *(u32 *)*pauVar18;
    DAT_70003f54 = *(u32 *)(*pauVar18 + 4);
    DAT_70003f58 = *(u32 *)(*pauVar18 + 8);
    pauVar17 = (u8 (*) [12])param_3;
    DAT_70003f60 = *(u32 *)*pauVar17;
    DAT_70003f64 = *(u32 *)(*pauVar17 + 4);
    DAT_70003f68 = *(u32 *)(*pauVar17 + 8);
    DAT_70003f90 = *(u32 *)(param_5 + 0x68);
    DAT_70003f94 = *(u32 *)(param_5 + 0x6c);
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    uVar19 = 0x3f000000;
    _ctc2(0x3f000000);
    _vnop();
    _vnop();
    auVar21._12_4_ = uRam70003f5c;
    auVar21._0_4_ = *(u32 *)*pauVar18;
    auVar21._4_4_ = *(u32 *)(*pauVar18 + 4);
    auVar21._8_4_ = *(u32 *)(*pauVar18 + 8 + 8);
    auVar20 = _lqc2(auVar21);
    auVar23._12_4_ = DAT_70003f6c;
    auVar23._0_4_ = *(u32 *)*pauVar17;
    auVar23._4_4_ = *(u32 *)(*pauVar17 + 4);
    auVar23._8_4_ = *(u32 *)(*pauVar17 + 8 + 8);
    auVar21 = _lqc2(auVar23);
    auVar24._8_8_ = uRam70003f98;
    auVar24._0_8_ = *(u64 *)(param_5 + 0x68);
    auVar22 = _lqc2(auVar24);
    _vmulabc(auVar20,auVar22);
    _vmaddabc(auVar21,auVar22);
    auVar22 = _vmadd(in_vf0,in_vf0);
    auVar20 = _vmuli(auVar20,in_vuI);
    auVar21 = _vmuli(auVar21,in_vuI);
    EI();
    if (0xb7 < param_4) {
      do {
        uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
        }
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar5 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar5 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0;
        REG_DMAC_9_SPR_TO_MADR = (u32)(puVar15);
        REG_DMAC_9_SPR_TO_QWC = 0x5c;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar5 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar5 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0x5c0;
        REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar16);
        REG_DMAC_9_SPR_TO_QWC = 0xb8;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar5 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar5 & 0x100) != 0);
        }
        pauVar9 = (u8 (*) [16])(u8 *)DAT_70000000;
        iVar12 = 0;
        pauVar6 = (u8 (*) [16])(u8 *)DAT_70001140;
        pauVar8 = (u8 (*) [16])(u8 *)DAT_700005c0;
        do {
          do {
            DI();
            SYNC(0x10);
          } while ((Status & 0x10000) != 0);
          auVar23 = _lqc2(*pauVar9);
          auVar24 = _vmulbc(auVar20,auVar23);
          auVar25 = _vmulbc(auVar21,auVar23);
          auVar29 = _vmulbc(auVar20,auVar23);
          auVar30 = _vmulbc(auVar21,auVar23);
          auVar23 = _lqc2(*pauVar8);
          auVar26 = _vadd(auVar23,auVar22);
          auVar23 = _lqc2(pauVar8[1]);
          auVar31 = _vadd(auVar23,auVar22);
          auVar23 = _lqc2(pauVar8[2]);
          auVar34 = _vadd(auVar23,auVar22);
          auVar23 = _lqc2(pauVar9[1]);
          auVar37 = _lqc2(pauVar8[3]);
          auVar38 = _vadd(auVar37,auVar22);
          auVar32 = _vmulbc(auVar20,auVar23);
          auVar33 = _vmulbc(auVar21,auVar23);
          auVar35 = _vmulbc(auVar20,auVar23);
          auVar36 = _vmulbc(auVar21,auVar23);
          auVar23 = _vsub(auVar26,auVar24);
          auVar37 = _vadd(auVar26,auVar24);
          auVar27 = _vadd(auVar26,auVar24);
          auVar28 = _vsub(auVar26,auVar24);
          auVar23 = _vsub(auVar23,auVar25);
          auVar24 = _vsub(auVar37,auVar25);
          auVar26 = _vadd(auVar27,auVar25);
          auVar25 = _vadd(auVar28,auVar25);
          auVar37 = _vsub(auVar31,auVar29);
          auVar27 = _vadd(auVar31,auVar29);
          auVar28 = _vadd(auVar31,auVar29);
          auVar29 = _vsub(auVar31,auVar29);
          auVar37 = _vsub(auVar37,auVar30);
          auVar27 = _vsub(auVar27,auVar30);
          auVar28 = _vadd(auVar28,auVar30);
          auVar29 = _vadd(auVar29,auVar30);
          auVar23 = _sqc2(auVar23);
          *(Vec128 *)pauVar6 = auVar23;
          auVar23 = _sqc2(auVar24);
          ((Vec128 *)pauVar6)[1] = auVar23;
          auVar23 = _sqc2(auVar26);
          ((Vec128 *)pauVar6)[2] = auVar23;
          auVar23 = _sqc2(auVar25);
          ((Vec128 *)pauVar6)[3] = auVar23;
          auVar23 = _sqc2(auVar37);
          ((Vec128 *)pauVar6)[4] = auVar23;
          auVar23 = _sqc2(auVar27);
          ((Vec128 *)pauVar6)[5] = auVar23;
          auVar23 = _sqc2(auVar28);
          ((Vec128 *)pauVar6)[6] = auVar23;
          auVar23 = _sqc2(auVar29);
          ((Vec128 *)pauVar6)[7] = auVar23;
          auVar23 = _vsub(auVar34,auVar32);
          auVar24 = _vadd(auVar34,auVar32);
          auVar25 = _vadd(auVar34,auVar32);
          auVar26 = _vsub(auVar34,auVar32);
          auVar23 = _vsub(auVar23,auVar33);
          auVar24 = _vsub(auVar24,auVar33);
          auVar25 = _vadd(auVar25,auVar33);
          auVar26 = _vadd(auVar26,auVar33);
          auVar37 = _vsub(auVar38,auVar35);
          auVar27 = _vadd(auVar38,auVar35);
          auVar28 = _vadd(auVar38,auVar35);
          auVar29 = _vsub(auVar38,auVar35);
          auVar37 = _vsub(auVar37,auVar36);
          auVar27 = _vsub(auVar27,auVar36);
          auVar28 = _vadd(auVar28,auVar36);
          auVar29 = _vadd(auVar29,auVar36);
          auVar23 = _sqc2(auVar23);
          ((Vec128 *)pauVar6)[8] = auVar23;
          auVar23 = _sqc2(auVar24);
          ((Vec128 *)pauVar6)[9] = auVar23;
          auVar23 = _sqc2(auVar25);
          ((Vec128 *)pauVar6)[10] = auVar23;
          auVar23 = _sqc2(auVar26);
          ((Vec128 *)pauVar6)[0xb] = auVar23;
          auVar23 = _sqc2(auVar37);
          ((Vec128 *)pauVar6)[0xc] = auVar23;
          auVar23 = _sqc2(auVar27);
          ((Vec128 *)pauVar6)[0xd] = auVar23;
          auVar23 = _sqc2(auVar28);
          ((Vec128 *)pauVar6)[0xe] = auVar23;
          auVar23 = _sqc2(auVar29);
          ((Vec128 *)pauVar6)[0xf] = auVar23;
          EI();
          iVar12 = iVar12 + 4;
          pauVar9 = pauVar9 + 2;
          pauVar6 = pauVar6 + 0x10;
          pauVar8 = pauVar8 + 4;
        } while (iVar12 < 0xb8);
        uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
        }
        uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar5 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar5 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar5 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x100;
        REG_DMAC_8_SPR_FROM_SADR = 0x1140;
        REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar14);
        REG_DMAC_8_SPR_FROM_QWC = 0x2e0;
        REG_DMAC_8_SPR_FROM_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        param_4 = param_4 + -0xb8;
        pauVar16 = pauVar16 + 0xb8;
        pauVar14 = pauVar14 + 0x2e0;
        puVar15 = puVar15 + 0xb8;
      } while (0xb7 < param_4);
    }
    if (3 < param_4) {
      iVar12 = param_4;
      if (param_4 < 0) {
        iVar12 = param_4 + 3;
      }
      iVar12 = iVar12 >> 2;
      iVar13 = iVar12 * 4;
      uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
      }
      uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar5 & 0x100) != 0);
      }
      iVar10 = iVar13 >> 1;
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = 0;
      REG_DMAC_9_SPR_TO_MADR = (u32)(puVar15);
      iVar11 = iVar10;
      if (iVar13 < 0) {
        iVar11 = iVar13 + 1 >> 1;
      }
      REG_DMAC_9_SPR_TO_QWC = iVar11;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar5 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = iVar11 << 4;
      REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar16);
      REG_DMAC_9_SPR_TO_QWC = iVar13;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar5 & 0x100) != 0);
      }
      pauVar6 = (u8 (*) [16])(u8 *)DAT_70000000;
      iVar7 = iVar10;
      if (iVar13 < 0) {
        iVar7 = iVar13 + 1 >> 1;
      }
      pauVar9 = (u8 (*) [16])(iVar11 << 4 | 0x70000000);
      pauVar8 = (u8 (*) [16])((iVar13 + iVar7) * 0x10 | 0x70000000);
      iVar11 = 0;
      if (0 < iVar13) {
        do {
          do {
            DI();
            SYNC(0x10);
          } while ((Status & 0x10000) != 0);
          auVar23 = _lqc2(*pauVar6);
          auVar24 = _vmulbc(auVar20,auVar23);
          auVar25 = _vmulbc(auVar21,auVar23);
          auVar29 = _vmulbc(auVar20,auVar23);
          auVar30 = _vmulbc(auVar21,auVar23);
          auVar23 = _lqc2(*pauVar9);
          auVar26 = _vadd(auVar23,auVar22);
          auVar23 = _lqc2(pauVar9[1]);
          auVar31 = _vadd(auVar23,auVar22);
          auVar23 = _lqc2(pauVar9[2]);
          auVar34 = _vadd(auVar23,auVar22);
          auVar23 = _lqc2(pauVar6[1]);
          auVar37 = _lqc2(pauVar9[3]);
          auVar38 = _vadd(auVar37,auVar22);
          auVar32 = _vmulbc(auVar20,auVar23);
          auVar33 = _vmulbc(auVar21,auVar23);
          auVar35 = _vmulbc(auVar20,auVar23);
          auVar36 = _vmulbc(auVar21,auVar23);
          auVar23 = _vsub(auVar26,auVar24);
          auVar37 = _vadd(auVar26,auVar24);
          auVar27 = _vadd(auVar26,auVar24);
          auVar28 = _vsub(auVar26,auVar24);
          auVar23 = _vsub(auVar23,auVar25);
          auVar24 = _vsub(auVar37,auVar25);
          auVar26 = _vadd(auVar27,auVar25);
          auVar25 = _vadd(auVar28,auVar25);
          auVar37 = _vsub(auVar31,auVar29);
          auVar27 = _vadd(auVar31,auVar29);
          auVar28 = _vadd(auVar31,auVar29);
          auVar29 = _vsub(auVar31,auVar29);
          auVar37 = _vsub(auVar37,auVar30);
          auVar27 = _vsub(auVar27,auVar30);
          auVar28 = _vadd(auVar28,auVar30);
          auVar29 = _vadd(auVar29,auVar30);
          auVar23 = _sqc2(auVar23);
          *(Vec128 *)pauVar8 = auVar23;
          auVar23 = _sqc2(auVar24);
          ((Vec128 *)pauVar8)[1] = auVar23;
          auVar23 = _sqc2(auVar26);
          ((Vec128 *)pauVar8)[2] = auVar23;
          auVar23 = _sqc2(auVar25);
          ((Vec128 *)pauVar8)[3] = auVar23;
          auVar23 = _sqc2(auVar37);
          ((Vec128 *)pauVar8)[4] = auVar23;
          auVar23 = _sqc2(auVar27);
          ((Vec128 *)pauVar8)[5] = auVar23;
          auVar23 = _sqc2(auVar28);
          ((Vec128 *)pauVar8)[6] = auVar23;
          auVar23 = _sqc2(auVar29);
          ((Vec128 *)pauVar8)[7] = auVar23;
          auVar23 = _vsub(auVar34,auVar32);
          auVar24 = _vadd(auVar34,auVar32);
          auVar25 = _vadd(auVar34,auVar32);
          auVar26 = _vsub(auVar34,auVar32);
          auVar23 = _vsub(auVar23,auVar33);
          auVar24 = _vsub(auVar24,auVar33);
          auVar25 = _vadd(auVar25,auVar33);
          auVar26 = _vadd(auVar26,auVar33);
          auVar37 = _vsub(auVar38,auVar35);
          auVar27 = _vadd(auVar38,auVar35);
          auVar28 = _vadd(auVar38,auVar35);
          auVar29 = _vsub(auVar38,auVar35);
          auVar37 = _vsub(auVar37,auVar36);
          auVar27 = _vsub(auVar27,auVar36);
          auVar28 = _vadd(auVar28,auVar36);
          auVar29 = _vadd(auVar29,auVar36);
          auVar23 = _sqc2(auVar23);
          ((Vec128 *)pauVar8)[8] = auVar23;
          auVar23 = _sqc2(auVar24);
          ((Vec128 *)pauVar8)[9] = auVar23;
          auVar23 = _sqc2(auVar25);
          ((Vec128 *)pauVar8)[10] = auVar23;
          auVar23 = _sqc2(auVar26);
          ((Vec128 *)pauVar8)[0xb] = auVar23;
          auVar23 = _sqc2(auVar37);
          ((Vec128 *)pauVar8)[0xc] = auVar23;
          auVar23 = _sqc2(auVar27);
          ((Vec128 *)pauVar8)[0xd] = auVar23;
          auVar23 = _sqc2(auVar28);
          ((Vec128 *)pauVar8)[0xe] = auVar23;
          auVar23 = _sqc2(auVar29);
          ((Vec128 *)pauVar8)[0xf] = auVar23;
          EI();
          iVar11 = iVar11 + 4;
          pauVar6 = pauVar6 + 2;
          pauVar8 = pauVar8 + 0x10;
          pauVar9 = pauVar9 + 4;
        } while (iVar11 < iVar13);
      }
      uVar5 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
      }
      uVar5 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar5 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar5 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar5 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x100;
      if (iVar13 < 0) {
        iVar10 = iVar13 + 1 >> 1;
      }
      REG_DMAC_8_SPR_FROM_SADR = (iVar13 + iVar10) * 0x10;
      REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar14);
      REG_DMAC_8_SPR_FROM_QWC = iVar12 << 4;
      REG_DMAC_8_SPR_FROM_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      puVar15 = puVar15 + iVar10 * 2;
      pauVar14 = pauVar14 + iVar12 * 0x10;
      param_4 = param_4 + iVar12 * -4;
      pauVar16 = pauVar16 + iVar12 * 4;
    }
    iVar12 = 0;
    if (0 < param_4) {
      do {
        uVar19 = *(u32 *)((int)puVar15 + 4);
        do {
          DI();
          SYNC(0x10);
        } while ((Status & 0x10000) != 0);
        auVar25._8_8_ = uStack_8;
        auVar25._0_8_ = *puVar15;
        auVar23 = _lqc2(auVar25);
        auVar24 = _vmulbc(auVar20,auVar23);
        auVar23 = _vmulbc(auVar21,auVar23);
        auVar25 = _lqc2(*pauVar16);
        auVar25 = _vadd(auVar25,auVar22);
        auVar26 = _vsub(auVar25,auVar24);
        auVar37 = _vadd(auVar25,auVar24);
        auVar27 = _vadd(auVar25,auVar24);
        auVar28 = _vsub(auVar25,auVar24);
        auVar24 = _vsub(auVar26,auVar23);
        auVar25 = _vsub(auVar37,auVar23);
        auVar26 = _vadd(auVar27,auVar23);
        auVar37 = _vadd(auVar28,auVar23);
        auVar23 = _sqc2(auVar24);
        *(Vec128 *)pauVar14 = auVar23;
        auVar23 = _sqc2(auVar25);
        ((Vec128 *)pauVar14)[1] = auVar23;
        auVar23 = _sqc2(auVar26);
        ((Vec128 *)pauVar14)[2] = auVar23;
        auVar23 = _sqc2(auVar37);
        ((Vec128 *)pauVar14)[3] = auVar23;
        EI();
        iVar12 = iVar12 + 1;
        puVar15 = (u64 *)((int)puVar15 + iVar3);
        pauVar14 = (u8 (*) [16])(*pauVar14 + iVar1 * 4);
        pauVar16 = (u8 (*) [16])(*pauVar16 + iVar2);
      } while (iVar12 < param_4);
    }
  }
  else {
    ((code)FUN_00521250)(auStack_30,param_2,0xc);
    ((code)FUN_00521250)(auStack_40,param_3,0xc);
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    uVar19 = 0x3f000000;
    _ctc2(0x3f000000);
    _vnop();
    _vnop();
    auVar21 = _lqc2(auStack_30);
    auVar22 = _lqc2(auStack_40);
    auVar20._8_8_ = uStack_18;
    auVar20._0_8_ = *(u64 *)(param_5 + 0x68);
    auVar20 = _lqc2(auVar20);
    _vmulabc(auVar21,auVar20);
    _vmaddabc(auVar22,auVar20);
    auVar23 = _vmadd(in_vf0,in_vf0);
    auVar20 = _vmuli(auVar21,in_vuI);
    auVar21 = _vmuli(auVar22,in_vuI);
    EI();
    iVar12 = 0;
    if (0 < param_4) {
      do {
        uVar19 = *(u32 *)((int)puVar15 + 4);
        do {
          DI();
          SYNC(0x10);
        } while ((Status & 0x10000) != 0);
        auVar22._8_8_ = uStack_48;
        auVar22._0_8_ = *puVar15;
        auVar22 = _lqc2(auVar22);
        auVar24 = _vmulbc(auVar20,auVar22);
        auVar22 = _vmulbc(auVar21,auVar22);
        auVar25 = _lqc2(*pauVar16);
        auVar25 = _vadd(auVar25,auVar23);
        auVar26 = _vsub(auVar25,auVar24);
        auVar37 = _vadd(auVar25,auVar24);
        auVar27 = _vadd(auVar25,auVar24);
        auVar28 = _vsub(auVar25,auVar24);
        auVar24 = _vsub(auVar26,auVar22);
        auVar25 = _vsub(auVar37,auVar22);
        auVar26 = _vadd(auVar27,auVar22);
        auVar37 = _vadd(auVar28,auVar22);
        auVar22 = _sqc2(auVar24);
        *(Vec128 *)pauVar14 = auVar22;
        auVar22 = _sqc2(auVar25);
        ((Vec128 *)pauVar14)[1] = auVar22;
        auVar22 = _sqc2(auVar26);
        ((Vec128 *)pauVar14)[2] = auVar22;
        auVar22 = _sqc2(auVar37);
        ((Vec128 *)pauVar14)[3] = auVar22;
        EI();
        iVar12 = iVar12 + 1;
        puVar15 = (u64 *)((int)puVar15 + iVar3);
        pauVar14 = (u8 (*) [16])(*pauVar14 + iVar1 * 4);
        pauVar16 = (u8 (*) [16])(*pauVar16 + iVar2);
      } while (iVar12 < param_4);
    }
  }
  return uVar19;
}

// FUN_00481860 NONMATCHING




u32 FUN_00481860(u32 *param_1,float *param_2,float *param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  u32 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  u64 *puVar11;
  u8 (*pauVar12) [16];
  u32 *puVar13;
  u8 (*pauVar14) [16];
  u8 (*pauVar15) [16];
  u64 *puVar16;
  int iVar17;
  u8 (*pauVar18) [16];
  u8 (*pauVar19) [16];
  u32 uVar20;
  float fVar21;
  float fVar22;
  Vec128 in_vf0;
  Vec128 auVar23;
  Vec128 auVar24;
  Vec128 auVar25;
  Vec128 auVar26;
  Vec128 auVar27;
  Vec128 auVar28;
  Vec128 auVar29;
  Vec128 auVar30;
  Vec128 in_vf10;
  Vec128 extraout_vf10;
  Vec128 auVar31;
  Vec128 in_vf11;
  Vec128 extraout_vf11;
  Vec128 auVar32;
  Vec128 in_vf12;
  Vec128 extraout_vf12;
  Vec128 auVar33;
  Vec128 in_vf13;
  Vec128 extraout_vf13;
  Vec128 auVar34;
  Vec128 auVar35;
  Vec128 auVar36;
  Vec128 auVar37;
  Vec128 auVar38;
  Vec128 auVar39;
  Vec128 auVar40;
  Vec128 auVar41;
  Vec128 auVar42;
  u32 in_vuI;
  u32 uStack_3c;
  u32 uStack_34;
  u32 uStack_14;
  u32 uStack_4;
  
  iVar1 = *(int *)(param_5 + 8);
  pauVar12 = (u8 (*) [16])*param_1;
  pauVar14 = *(u8 (**) [16])(param_5 + 4);
  puVar13 = *(u32 **)(param_5 + 0x34);
  puVar11 = *(u64 **)(param_5 + 0x1c);
  iVar2 = *(int *)(param_5 + 0x38);
  iVar3 = *(int *)(param_5 + 0x20);
  iVar4 = param_1[1];
  if (iVar1 == iVar4) {
    FlushCache(0);
    uVar6 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar6 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar5 = getCopCondition(0,0);
      } while (cVar5 == '\0');
    }
    uVar6 = REG_DMAC_9_SPR_TO_CHCR;
    if ((uVar6 & 0x100) != 0) {
      REG_DMAC_PCR = 0x200;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar5 = getCopCondition(0,0);
      } while (cVar5 == '\0');
      do {
        uVar6 = REG_DMAC_9_SPR_TO_CHCR;
      } while ((uVar6 & 0x100) != 0);
    }
    DAT_70003f40 = *param_2 * 0.5;
    DAT_70003f44 = param_2[1] * 0.5;
    DAT_70003f48 = param_2[2] * 0.5;
    DAT_70003f50 = *param_3 * 0.5;
    DAT_70003f54 = param_3[1] * 0.5;
    DAT_70003f58 = param_3[2] * 0.5;
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    _ctc2(0x3fc90fdb);
    _vnop();
    _vnop();
    auVar31 = _vaddi(extraout_vf10,in_vuI);
    _ctc2(0x40490fdb);
    _vnop();
    _vnop();
    auVar31 = _vaddi(auVar31,in_vuI);
    _ctc2(0x40090fdb);
    _vnop();
    _vnop();
    auVar31 = _vaddi(auVar31,in_vuI);
    _ctc2(0xc0490fdb);
    _vnop();
    _vnop();
    auVar32 = _vaddi(extraout_vf11,in_vuI);
    uVar20 = 0xc08487ed;
    _ctc2(0xc08487ed);
    _vnop();
    _vnop();
    auVar32 = _vaddi(auVar32,in_vuI);
    _ctc2(0xb94fb21f);
    _vnop();
    _vnop();
    auVar32 = _vaddi(auVar32,in_vuI);
    _ctc2(0xbe2aaaa4);
    _vnop();
    _vnop();
    auVar33 = _vaddi(extraout_vf12,in_vuI);
    _ctc2(0x3c08873e);
    _vnop();
    _vnop();
    auVar33 = _vaddi(auVar33,in_vuI);
    _ctc2(0x362e9c14);
    _vnop();
    _vnop();
    auVar33 = _vaddi(auVar33,in_vuI);
    _ctc2(0x3f800000);
    _vnop();
    _vnop();
    auVar34 = _vaddi(extraout_vf13,in_vuI);
    EI();
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    auVar24._4_4_ = DAT_70003f44;
    auVar24._0_4_ = DAT_70003f40;
    auVar24._8_4_ = DAT_70003f48;
    auVar24._12_4_ = DAT_70003f4c;
    auVar29 = _lqc2(auVar24);
    auVar25._4_4_ = DAT_70003f54;
    auVar25._0_4_ = DAT_70003f50;
    auVar25._8_4_ = DAT_70003f58;
    auVar25._12_4_ = uRam70003f5c;
    auVar30 = _lqc2(auVar25);
    auVar26._4_4_ = DAT_70003f64;
    auVar26._0_4_ = DAT_70003f60;
    auVar26._8_4_ = DAT_70003f68;
    auVar26._12_4_ = DAT_70003f6c;
    auVar35 = _lqc2(auVar26);
    EI();
    DAT_70003f60 = *(u32 *)(param_5 + 0x68);
    DAT_70003f64 = *(u32 *)(param_5 + 0x6c);
    DAT_70003f68 = *(u32 *)(param_5 + 0x68);
    DAT_70003f6c = *(u32 *)(param_5 + 0x6c);
    if (0xaf < param_4) {
      do {
        uVar6 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar6 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar5 = getCopCondition(0,0);
          } while (cVar5 == '\0');
        }
        uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar6 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar5 = getCopCondition(0,0);
          } while (cVar5 == '\0');
          do {
            uVar6 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar6 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0;
        REG_DMAC_9_SPR_TO_MADR = (u32)(puVar13);
        REG_DMAC_9_SPR_TO_QWC = 0x2c;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar6 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar5 = getCopCondition(0,0);
          } while (cVar5 == '\0');
          do {
            uVar6 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar6 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0x2c0;
        REG_DMAC_9_SPR_TO_MADR = (u32)(puVar11);
        REG_DMAC_9_SPR_TO_QWC = 0x58;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar6 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar5 = getCopCondition(0,0);
          } while (cVar5 == '\0');
          do {
            uVar6 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar6 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0x840;
        REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar14);
        REG_DMAC_9_SPR_TO_QWC = 0xb0;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar6 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar5 = getCopCondition(0,0);
          } while (cVar5 == '\0');
          do {
            uVar6 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar6 & 0x100) != 0);
        }
        puVar16 = (u64 *)(u8 *)DAT_70000000;
        iVar17 = 0;
        pauVar18 = (u8 (*) [16])(u8 *)DAT_70001340;
        pauVar19 = (u8 (*) [16])(u8 *)DAT_70000840;
        pauVar15 = (u8 (*) [16])(u8 *)DAT_700002c0;
        do {
          DAT_70003fa0 = *(u32 *)puVar16;
          DAT_70003fa4 = *(u32 *)((int)puVar16 + 4);
          DAT_70003fa8 = *(u32 *)puVar16;
          uVar20 = *(u32 *)((int)puVar16 + 4);
          do {
            DI();
            SYNC(0x10);
          } while ((Status & 0x10000) != 0);
          auVar28._8_4_ = DAT_70003fa8;
          auVar28._0_8_ = *puVar16;
          auVar28._12_4_ = uVar20;
          auVar23 = _lqc2(auVar28);
          auVar27 = _vabs(auVar23);
          _vaddabc(in_vf0,auVar31);
          _vmsubbc(auVar27,in_vf0);
          _vaddabc(in_vf0,auVar31);
          _vaddabc(in_vf0,auVar31);
          auVar27 = _vmsubbc(auVar23,in_vf0);
          _vaddabc(in_vf0,auVar32);
          _vaddabc(in_vf0,auVar32);
          auVar24 = _vmsubbc(auVar23,in_vf0);
          auVar23 = _vmini(auVar23,auVar27);
          auVar28 = _vmax(auVar23,auVar24);
          auVar23 = _vmul(auVar28,auVar28);
          auVar26 = _vmulbc(auVar28,auVar32);
          auVar24 = _vmulbc(auVar28,auVar33);
          auVar25 = _vmulbc(auVar28,auVar33);
          auVar27 = _vmul(auVar23,auVar23);
          auVar26 = _vmul(auVar26,auVar23);
          _vmula(auVar24,auVar23);
          auVar24 = _vmulbc(auVar28,auVar33);
          auVar23 = _vmul(auVar27,auVar27);
          _vmadda(auVar26,auVar27);
          _vmadda(auVar25,auVar27);
          _vmaddabc(auVar28,auVar34);
          auVar24 = _vmadd(auVar24,auVar23);
          auVar28 = _lqc2(*pauVar19);
          auVar40 = _lqc2(pauVar19[1]);
          auVar27 = _lqc2(*pauVar15);
          _vmulabc(auVar29,auVar24);
          auVar25 = _vmsubbc(auVar30,auVar24);
          auVar23 = _vadd(auVar35,auVar27);
          auVar27 = _vsub(auVar35,auVar27);
          _vmulabc(auVar30,auVar24);
          auVar26 = _vmaddbc(auVar29,auVar24);
          _vmulabc(auVar29,auVar24);
          auVar38 = _vmsubbc(auVar30,auVar24);
          _vmulabc(auVar30,auVar24);
          auVar39 = _vmaddbc(auVar29,auVar24);
          _vmulabc(auVar25,auVar27);
          auVar24 = _vmaddbc(auVar26,auVar27);
          _vmulabc(auVar25,auVar23);
          auVar36 = _vmaddbc(auVar26,auVar27);
          _vmulabc(auVar25,auVar23);
          auVar37 = _vmaddbc(auVar26,auVar23);
          _vmulabc(auVar25,auVar27);
          auVar25 = _vmaddbc(auVar26,auVar23);
          _vmulabc(auVar38,auVar27);
          auVar26 = _vmaddbc(auVar39,auVar27);
          _vmulabc(auVar38,auVar23);
          auVar41 = _vmaddbc(auVar39,auVar27);
          _vmulabc(auVar38,auVar23);
          auVar42 = _vmaddbc(auVar39,auVar23);
          _vmulabc(auVar38,auVar27);
          auVar38 = _vmaddbc(auVar39,auVar23);
          auVar23 = _vadd(auVar24,auVar28);
          auVar27 = _vadd(auVar36,auVar28);
          auVar24 = _vadd(auVar37,auVar28);
          auVar25 = _vadd(auVar25,auVar28);
          auVar26 = _vadd(auVar26,auVar40);
          auVar28 = _vadd(auVar41,auVar40);
          auVar36 = _vadd(auVar42,auVar40);
          auVar37 = _vadd(auVar38,auVar40);
          auVar23 = _sqc2(auVar23);
          DAT_70003fac = uVar20;
          *(Vec128 *)pauVar18 = auVar23;
          auVar23 = _sqc2(auVar27);
          ((Vec128 *)pauVar18)[1] = auVar23;
          auVar23 = _sqc2(auVar24);
          ((Vec128 *)pauVar18)[2] = auVar23;
          auVar23 = _sqc2(auVar25);
          ((Vec128 *)pauVar18)[3] = auVar23;
          auVar23 = _sqc2(auVar26);
          ((Vec128 *)pauVar18)[4] = auVar23;
          auVar23 = _sqc2(auVar28);
          ((Vec128 *)pauVar18)[5] = auVar23;
          auVar23 = _sqc2(auVar36);
          ((Vec128 *)pauVar18)[6] = auVar23;
          auVar23 = _sqc2(auVar37);
          ((Vec128 *)pauVar18)[7] = auVar23;
          EI();
          iVar17 = iVar17 + 2;
          pauVar19 = pauVar19 + 2;
          pauVar15 = pauVar15 + 1;
          puVar16 = puVar16 + 1;
          pauVar18 = pauVar18 + 8;
        } while (iVar17 < 0xb0);
        uVar6 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar6 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar5 = getCopCondition(0,0);
          } while (cVar5 == '\0');
        }
        uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar6 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar5 = getCopCondition(0,0);
          } while (cVar5 == '\0');
          do {
            uVar6 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar6 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x100;
        REG_DMAC_8_SPR_FROM_SADR = 0x1340;
        REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar12);
        REG_DMAC_8_SPR_FROM_QWC = 0x2c0;
        REG_DMAC_8_SPR_FROM_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        param_4 = param_4 + -0xb0;
        pauVar14 = pauVar14 + 0xb0;
        pauVar12 = pauVar12 + 0x2c0;
        puVar13 = puVar13 + 0xb0;
        puVar11 = puVar11 + 0xb0;
      } while (0xaf < param_4);
    }
    if (3 < param_4) {
      iVar17 = param_4;
      if (param_4 < 0) {
        iVar17 = param_4 + 3;
      }
      iVar17 = iVar17 >> 2;
      uVar6 = REG_DMAC_8_SPR_FROM_CHCR;
      iVar7 = iVar17 * 4;
      if ((uVar6 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar5 = getCopCondition(0,0);
        } while (cVar5 == '\0');
      }
      uVar6 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar6 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar5 = getCopCondition(0,0);
        } while (cVar5 == '\0');
        do {
          uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar6 & 0x100) != 0);
      }
      iVar8 = iVar7 >> 2;
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = 0;
      REG_DMAC_9_SPR_TO_MADR = (u32)(puVar13);
      iVar9 = iVar8;
      if (iVar7 < 0) {
        iVar9 = iVar7 + 3 >> 2;
      }
      REG_DMAC_9_SPR_TO_QWC = iVar9;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar6 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar6 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar5 = getCopCondition(0,0);
        } while (cVar5 == '\0');
        do {
          uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar6 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = 0x2c0;
      iVar10 = iVar7 >> 1;
      REG_DMAC_9_SPR_TO_MADR = (u32)(puVar11);
      iVar9 = iVar10;
      if (iVar7 < 0) {
        iVar9 = iVar7 + 1 >> 1;
      }
      REG_DMAC_9_SPR_TO_QWC = iVar9;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar6 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar6 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar5 = getCopCondition(0,0);
        } while (cVar5 == '\0');
        do {
          uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar6 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = 0x840;
      REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar14);
      REG_DMAC_9_SPR_TO_QWC = iVar7;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar6 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar6 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar5 = getCopCondition(0,0);
        } while (cVar5 == '\0');
        do {
          uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar6 & 0x100) != 0);
      }
      puVar16 = (u64 *)(u8 *)DAT_70000000;
      pauVar18 = (u8 (*) [16])(u8 *)DAT_700002c0;
      pauVar15 = (u8 (*) [16])(u8 *)DAT_70000840;
      pauVar19 = (u8 (*) [16])(u8 *)DAT_70001340;
      iVar9 = 0;
      if (0 < iVar7) {
        do {
          DAT_70003fa0 = *(u32 *)puVar16;
          DAT_70003fa4 = *(u32 *)((int)puVar16 + 4);
          DAT_70003fa8 = *(u32 *)puVar16;
          uVar20 = *(u32 *)((int)puVar16 + 4);
          do {
            DI();
            SYNC(0x10);
          } while ((Status & 0x10000) != 0);
          auVar36._8_4_ = DAT_70003fa8;
          auVar36._0_8_ = *puVar16;
          auVar36._12_4_ = uVar20;
          auVar23 = _lqc2(auVar36);
          auVar27 = _vabs(auVar23);
          _vaddabc(in_vf0,auVar31);
          _vmsubbc(auVar27,in_vf0);
          _vaddabc(in_vf0,auVar31);
          _vaddabc(in_vf0,auVar31);
          auVar27 = _vmsubbc(auVar23,in_vf0);
          _vaddabc(in_vf0,auVar32);
          _vaddabc(in_vf0,auVar32);
          auVar24 = _vmsubbc(auVar23,in_vf0);
          auVar23 = _vmini(auVar23,auVar27);
          auVar28 = _vmax(auVar23,auVar24);
          auVar23 = _vmul(auVar28,auVar28);
          auVar26 = _vmulbc(auVar28,auVar32);
          auVar24 = _vmulbc(auVar28,auVar33);
          auVar25 = _vmulbc(auVar28,auVar33);
          auVar27 = _vmul(auVar23,auVar23);
          auVar26 = _vmul(auVar26,auVar23);
          _vmula(auVar24,auVar23);
          auVar24 = _vmulbc(auVar28,auVar33);
          auVar23 = _vmul(auVar27,auVar27);
          _vmadda(auVar26,auVar27);
          _vmadda(auVar25,auVar27);
          _vmaddabc(auVar28,auVar34);
          auVar24 = _vmadd(auVar24,auVar23);
          auVar28 = _lqc2(*pauVar15);
          auVar40 = _lqc2(pauVar15[1]);
          auVar27 = _lqc2(*pauVar18);
          _vmulabc(auVar29,auVar24);
          auVar25 = _vmsubbc(auVar30,auVar24);
          auVar23 = _vadd(auVar35,auVar27);
          auVar27 = _vsub(auVar35,auVar27);
          _vmulabc(auVar30,auVar24);
          auVar26 = _vmaddbc(auVar29,auVar24);
          _vmulabc(auVar29,auVar24);
          auVar38 = _vmsubbc(auVar30,auVar24);
          _vmulabc(auVar30,auVar24);
          auVar39 = _vmaddbc(auVar29,auVar24);
          _vmulabc(auVar25,auVar27);
          auVar24 = _vmaddbc(auVar26,auVar27);
          _vmulabc(auVar25,auVar23);
          auVar36 = _vmaddbc(auVar26,auVar27);
          _vmulabc(auVar25,auVar23);
          auVar37 = _vmaddbc(auVar26,auVar23);
          _vmulabc(auVar25,auVar27);
          auVar25 = _vmaddbc(auVar26,auVar23);
          _vmulabc(auVar38,auVar27);
          auVar26 = _vmaddbc(auVar39,auVar27);
          _vmulabc(auVar38,auVar23);
          auVar41 = _vmaddbc(auVar39,auVar27);
          _vmulabc(auVar38,auVar23);
          auVar42 = _vmaddbc(auVar39,auVar23);
          _vmulabc(auVar38,auVar27);
          auVar38 = _vmaddbc(auVar39,auVar23);
          auVar23 = _vadd(auVar24,auVar28);
          auVar27 = _vadd(auVar36,auVar28);
          auVar24 = _vadd(auVar37,auVar28);
          auVar25 = _vadd(auVar25,auVar28);
          auVar26 = _vadd(auVar26,auVar40);
          auVar28 = _vadd(auVar41,auVar40);
          auVar36 = _vadd(auVar42,auVar40);
          auVar37 = _vadd(auVar38,auVar40);
          auVar23 = _sqc2(auVar23);
          DAT_70003fac = uVar20;
          *(Vec128 *)pauVar19 = auVar23;
          auVar23 = _sqc2(auVar27);
          ((Vec128 *)pauVar19)[1] = auVar23;
          auVar23 = _sqc2(auVar24);
          ((Vec128 *)pauVar19)[2] = auVar23;
          auVar23 = _sqc2(auVar25);
          ((Vec128 *)pauVar19)[3] = auVar23;
          auVar23 = _sqc2(auVar26);
          ((Vec128 *)pauVar19)[4] = auVar23;
          auVar23 = _sqc2(auVar28);
          ((Vec128 *)pauVar19)[5] = auVar23;
          auVar23 = _sqc2(auVar36);
          ((Vec128 *)pauVar19)[6] = auVar23;
          auVar23 = _sqc2(auVar37);
          ((Vec128 *)pauVar19)[7] = auVar23;
          EI();
          iVar9 = iVar9 + 2;
          pauVar15 = pauVar15 + 2;
          pauVar18 = pauVar18 + 1;
          puVar16 = puVar16 + 1;
          pauVar19 = pauVar19 + 8;
        } while (iVar9 < iVar7);
      }
      uVar6 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar6 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar5 = getCopCondition(0,0);
        } while (cVar5 == '\0');
      }
      uVar6 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar6 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar5 = getCopCondition(0,0);
        } while (cVar5 == '\0');
        do {
          uVar6 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar6 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x100;
      REG_DMAC_8_SPR_FROM_SADR = 0x1340;
      REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar12);
      REG_DMAC_8_SPR_FROM_QWC = iVar17 << 4;
      REG_DMAC_8_SPR_FROM_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      pauVar12 = pauVar12 + iVar17 * 0x10;
      pauVar14 = pauVar14 + iVar17 * 4;
      if (iVar7 < 0) {
        iVar8 = iVar7 + 3 >> 2;
      }
      puVar13 = puVar13 + iVar8 * 4;
      if (iVar7 < 0) {
        iVar10 = iVar7 + 1 >> 1;
      }
      param_4 = param_4 + iVar17 * -4;
      puVar11 = puVar11 + iVar10 * 2;
    }
    iVar17 = 0;
    if (0 < param_4) {
      do {
        DAT_70003fa0 = *puVar13;
        DAT_70003fa8 = *puVar13;
        DAT_70003f60 = *(u32 *)puVar11;
        uVar20 = *(u32 *)((int)puVar11 + 4);
        do {
          DI();
          SYNC(0x10);
        } while ((Status & 0x10000) != 0);
        auVar37._4_4_ = DAT_70003fa4;
        auVar37._0_4_ = DAT_70003fa0;
        auVar37._8_4_ = DAT_70003fa8;
        auVar37._12_4_ = DAT_70003fac;
        auVar23 = _lqc2(auVar37);
        auVar27 = _vabs(auVar23);
        _vaddabc(in_vf0,auVar31);
        _vmsubbc(auVar27,in_vf0);
        _vaddabc(in_vf0,auVar31);
        _vaddabc(in_vf0,auVar31);
        auVar27 = _vmsubbc(auVar23,in_vf0);
        _vaddabc(in_vf0,auVar32);
        _vaddabc(in_vf0,auVar32);
        auVar24 = _vmsubbc(auVar23,in_vf0);
        auVar23 = _vmini(auVar23,auVar27);
        auVar28 = _vmax(auVar23,auVar24);
        auVar23 = _vmul(auVar28,auVar28);
        auVar26 = _vmulbc(auVar28,auVar32);
        auVar24 = _vmulbc(auVar28,auVar33);
        auVar25 = _vmulbc(auVar28,auVar33);
        auVar27 = _vmul(auVar23,auVar23);
        auVar26 = _vmul(auVar26,auVar23);
        _vmula(auVar24,auVar23);
        auVar24 = _vmulbc(auVar28,auVar33);
        auVar23 = _vmul(auVar27,auVar27);
        _vmadda(auVar26,auVar27);
        _vmadda(auVar25,auVar27);
        _vmaddabc(auVar28,auVar34);
        auVar24 = _vmadd(auVar24,auVar23);
        auVar26 = _lqc2(*pauVar14);
        auVar38._8_4_ = DAT_70003f68;
        auVar38._0_8_ = *puVar11;
        auVar38._12_4_ = DAT_70003f6c;
        auVar27 = _lqc2(auVar38);
        _vmulabc(auVar29,auVar24);
        auVar25 = _vmsubbc(auVar30,auVar24);
        auVar23 = _vadd(auVar35,auVar27);
        auVar27 = _vsub(auVar35,auVar27);
        _vmulabc(auVar30,auVar24);
        auVar24 = _vmaddbc(auVar29,auVar24);
        _vmulabc(auVar25,auVar27);
        auVar28 = _vmaddbc(auVar24,auVar27);
        _vmulabc(auVar25,auVar23);
        auVar36 = _vmaddbc(auVar24,auVar27);
        _vmulabc(auVar25,auVar23);
        auVar37 = _vmaddbc(auVar24,auVar23);
        _vmulabc(auVar25,auVar27);
        auVar25 = _vmaddbc(auVar24,auVar23);
        auVar23 = _vadd(auVar28,auVar26);
        auVar27 = _vadd(auVar36,auVar26);
        auVar24 = _vadd(auVar37,auVar26);
        auVar25 = _vadd(auVar25,auVar26);
        auVar23 = _sqc2(auVar23);
        DAT_70003f64 = uVar20;
        *(Vec128 *)pauVar12 = auVar23;
        auVar23 = _sqc2(auVar27);
        ((Vec128 *)pauVar12)[1] = auVar23;
        auVar23 = _sqc2(auVar24);
        ((Vec128 *)pauVar12)[2] = auVar23;
        auVar23 = _sqc2(auVar25);
        ((Vec128 *)pauVar12)[3] = auVar23;
        EI();
        iVar17 = iVar17 + 1;
        pauVar14 = (u8 (*) [16])(*pauVar14 + iVar1);
        puVar11 = (u64 *)((int)puVar11 + iVar3);
        puVar13 = (u32 *)((int)puVar13 + iVar2);
        pauVar12 = (u8 (*) [16])(*pauVar12 + iVar4 * 4);
      } while (iVar17 < param_4);
    }
  }
  else {
    fVar21 = *(float *)(param_5 + 0x68) + *(float *)(param_5 + 0x68);
    fVar22 = *(float *)(param_5 + 0x6c) + *(float *)(param_5 + 0x6c);
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    _ctc2(0x3fc90fdb);
    _vnop();
    _vnop();
    auVar31 = _vaddi(in_vf10,in_vuI);
    _ctc2(0x40490fdb);
    _vnop();
    _vnop();
    auVar31 = _vaddi(auVar31,in_vuI);
    _ctc2(0x40090fdb);
    _vnop();
    _vnop();
    auVar31 = _vaddi(auVar31,in_vuI);
    _ctc2(0xc0490fdb);
    _vnop();
    _vnop();
    auVar32 = _vaddi(in_vf11,in_vuI);
    uVar20 = 0xc08487ed;
    _ctc2(0xc08487ed);
    _vnop();
    _vnop();
    auVar32 = _vaddi(auVar32,in_vuI);
    _ctc2(0xb94fb21f);
    _vnop();
    _vnop();
    auVar32 = _vaddi(auVar32,in_vuI);
    _ctc2(0xbe2aaaa4);
    _vnop();
    _vnop();
    auVar33 = _vaddi(in_vf12,in_vuI);
    _ctc2(0x3c08873e);
    _vnop();
    _vnop();
    auVar33 = _vaddi(auVar33,in_vuI);
    _ctc2(0x362e9c14);
    _vnop();
    _vnop();
    auVar33 = _vaddi(auVar33,in_vuI);
    _ctc2(0x3f800000);
    _vnop();
    _vnop();
    auVar34 = _vaddi(in_vf13,in_vuI);
    EI();
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    auVar35._4_4_ = param_2[1] * 0.5;
    auVar35._0_4_ = *param_2 * 0.5;
    auVar35._8_4_ = param_2[2] * 0.5;
    auVar35._12_4_ = uStack_4;
    auVar35 = _lqc2(auVar35);
    auVar30._4_4_ = param_3[1] * 0.5;
    auVar30._0_4_ = *param_3 * 0.5;
    auVar30._8_4_ = param_3[2] * 0.5;
    auVar30._12_4_ = uStack_14;
    auVar30 = _lqc2(auVar30);
    auVar29._4_4_ = fVar22;
    auVar29._0_4_ = fVar21;
    auVar29._8_4_ = fVar21;
    auVar29._12_4_ = fVar22;
    auVar29 = _lqc2(auVar29);
    EI();
    iVar17 = 0;
    if (0 < param_4) {
      do {
        uVar20 = *(u32 *)((int)puVar11 + 4);
        do {
          DI();
          SYNC(0x10);
        } while ((Status & 0x10000) != 0);
        auVar23._4_4_ = uStack_3c;
        auVar23._0_4_ = *puVar13;
        auVar23._8_4_ = *puVar13;
        auVar23._12_4_ = uStack_34;
        auVar23 = _lqc2(auVar23);
        auVar27 = _vabs(auVar23);
        _vaddabc(in_vf0,auVar31);
        _vmsubbc(auVar27,in_vf0);
        _vaddabc(in_vf0,auVar31);
        _vaddabc(in_vf0,auVar31);
        auVar27 = _vmsubbc(auVar23,in_vf0);
        _vaddabc(in_vf0,auVar32);
        _vaddabc(in_vf0,auVar32);
        auVar24 = _vmsubbc(auVar23,in_vf0);
        auVar23 = _vmini(auVar23,auVar27);
        auVar28 = _vmax(auVar23,auVar24);
        auVar23 = _vmul(auVar28,auVar28);
        auVar26 = _vmulbc(auVar28,auVar32);
        auVar24 = _vmulbc(auVar28,auVar33);
        auVar25 = _vmulbc(auVar28,auVar33);
        auVar27 = _vmul(auVar23,auVar23);
        auVar26 = _vmul(auVar26,auVar23);
        _vmula(auVar24,auVar23);
        auVar24 = _vmulbc(auVar28,auVar33);
        auVar23 = _vmul(auVar27,auVar27);
        _vmadda(auVar26,auVar27);
        _vmadda(auVar25,auVar27);
        _vmaddabc(auVar28,auVar34);
        auVar24 = _vmadd(auVar24,auVar23);
        auVar26 = _lqc2(*pauVar14);
        auVar27._8_4_ = fVar21;
        auVar27._0_8_ = *puVar11;
        auVar27._12_4_ = fVar22;
        auVar27 = _lqc2(auVar27);
        _vmulabc(auVar35,auVar24);
        auVar25 = _vmsubbc(auVar30,auVar24);
        auVar23 = _vadd(auVar29,auVar27);
        auVar27 = _vsub(auVar29,auVar27);
        _vmulabc(auVar30,auVar24);
        auVar24 = _vmaddbc(auVar35,auVar24);
        _vmulabc(auVar25,auVar27);
        auVar28 = _vmaddbc(auVar24,auVar27);
        _vmulabc(auVar25,auVar23);
        auVar36 = _vmaddbc(auVar24,auVar27);
        _vmulabc(auVar25,auVar23);
        auVar37 = _vmaddbc(auVar24,auVar23);
        _vmulabc(auVar25,auVar27);
        auVar25 = _vmaddbc(auVar24,auVar23);
        auVar23 = _vadd(auVar28,auVar26);
        auVar27 = _vadd(auVar36,auVar26);
        auVar24 = _vadd(auVar37,auVar26);
        auVar25 = _vadd(auVar25,auVar26);
        auVar23 = _sqc2(auVar23);
        *(Vec128 *)pauVar12 = auVar23;
        auVar23 = _sqc2(auVar27);
        ((Vec128 *)pauVar12)[1] = auVar23;
        auVar23 = _sqc2(auVar24);
        ((Vec128 *)pauVar12)[2] = auVar23;
        auVar23 = _sqc2(auVar25);
        ((Vec128 *)pauVar12)[3] = auVar23;
        EI();
        iVar17 = iVar17 + 1;
        pauVar14 = (u8 (*) [16])(*pauVar14 + iVar1);
        puVar11 = (u64 *)((int)puVar11 + iVar3);
        puVar13 = (u32 *)((int)puVar13 + iVar2);
        pauVar12 = (u8 (*) [16])(*pauVar12 + iVar4 * 4);
      } while (iVar17 < param_4);
    }
  }
  return uVar20;
}

// FUN_00482A50 NONMATCHING

u32
FUN_00482a50(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5)

{
  int iVar1;
  char cVar2;
  u32 uVar3;
  int iVar4;
  int iVar5;
  u8 (*pauVar6) [16];
  u8 (*pauVar7) [16];
  u8 (*pauVar8) [16];
  u8 (*pauVar9) [16];
  Vec128 auVar10;
  Vec128 auVar11;
  Vec128 auVar12;
  Vec128 auVar13;
  Vec128 auVar14;
  u32 in_vuI;
  
  pauVar9 = (u8 (*) [16])*param_1;
  iVar4 = *(int *)(param_5 + 0x10);
  iVar1 = param_1[1];
  pauVar8 = *(u8 (**) [16])(param_5 + 0xc);
  if (iVar4 == iVar1 << 2) {
    FlushCache(0);
    uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar3 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar2 = getCopCondition(0,0);
      } while (cVar2 == '\0');
    }
    uVar3 = REG_DMAC_9_SPR_TO_CHCR;
    if ((uVar3 & 0x100) != 0) {
      REG_DMAC_PCR = 0x200;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar2 = getCopCondition(0,0);
      } while (cVar2 == '\0');
      do {
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      } while ((uVar3 & 0x100) != 0);
    }
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    _ctc2(0x3f000000);
    _vnop();
    _vnop();
    EI();
    if (0x7e < param_4) {
      do {
        uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
        }
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
          do {
            uVar3 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar3 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0;
        REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar8);
        REG_DMAC_9_SPR_TO_QWC = 0x1fc;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
          do {
            uVar3 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar3 & 0x100) != 0);
        }
        pauVar7 = (u8 (*) [16])(u8 *)DAT_70000000;
        iVar4 = 0;
        pauVar6 = (u8 (*) [16])(u8 *)DAT_70001fc0;
        do {
          do {
            DI();
            SYNC(0x10);
          } while ((Status & 0x10000) != 0);
          auVar10 = _lqc2(*pauVar7);
          auVar11 = _lqc2(pauVar7[1]);
          _lqc2(pauVar7[2]);
          auVar12 = _lqc2(pauVar7[3]);
          auVar13 = _vmuli(auVar10,in_vuI);
          auVar14 = _vmuli(auVar11,in_vuI);
          auVar12 = _vadd(auVar12,auVar14);
          auVar12 = _vadd(auVar12,auVar13);
          auVar13 = _vsub(auVar12,auVar10);
          auVar14 = _vsub(auVar12,auVar11);
          auVar11 = _vsub(auVar13,auVar11);
          auVar10 = _sqc2(auVar12);
          ((Vec128 *)pauVar6)[3] = auVar10;
          auVar10 = _sqc2(auVar13);
          ((Vec128 *)pauVar6)[2] = auVar10;
          auVar10 = _sqc2(auVar14);
          *(Vec128 *)pauVar6 = auVar10;
          auVar10 = _sqc2(auVar11);
          ((Vec128 *)pauVar6)[1] = auVar10;
          pauVar7 = pauVar7 + 4;
          pauVar6 = pauVar6 + 4;
          EI();
          iVar4 = iVar4 + 1;
        } while (iVar4 < 0x7f);
        uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
        }
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
          do {
            uVar3 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar3 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x100;
        REG_DMAC_8_SPR_FROM_SADR = 0x1fc0;
        REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar9);
        REG_DMAC_8_SPR_FROM_QWC = 0x1fc;
        REG_DMAC_8_SPR_FROM_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        param_4 = param_4 + -0x7f;
        pauVar8 = pauVar8 + 0x1fc;
        pauVar9 = pauVar9 + 0x1fc;
      } while (0x7e < param_4);
    }
    if (param_4 != 0) {
      uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
      }
      uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
        do {
          uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar3 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = 0;
      REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar8);
      REG_DMAC_9_SPR_TO_QWC = param_4 << 2;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
        do {
          uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar3 & 0x100) != 0);
      }
      pauVar6 = (u8 (*) [16])(u8 *)DAT_70000000;
      pauVar8 = (u8 (*) [16])(u8 *)DAT_70001fc0;
      iVar4 = 0;
      if (0 < param_4) {
        do {
          do {
            DI();
            SYNC(0x10);
          } while ((Status & 0x10000) != 0);
          auVar10 = _lqc2(*pauVar6);
          auVar11 = _lqc2(pauVar6[1]);
          _lqc2(pauVar6[2]);
          auVar12 = _lqc2(pauVar6[3]);
          auVar13 = _vmuli(auVar10,in_vuI);
          auVar14 = _vmuli(auVar11,in_vuI);
          auVar12 = _vadd(auVar12,auVar14);
          auVar12 = _vadd(auVar12,auVar13);
          auVar13 = _vsub(auVar12,auVar10);
          auVar14 = _vsub(auVar12,auVar11);
          auVar11 = _vsub(auVar13,auVar11);
          auVar10 = _sqc2(auVar12);
          ((Vec128 *)pauVar8)[3] = auVar10;
          auVar10 = _sqc2(auVar13);
          ((Vec128 *)pauVar8)[2] = auVar10;
          auVar10 = _sqc2(auVar14);
          *(Vec128 *)pauVar8 = auVar10;
          auVar10 = _sqc2(auVar11);
          ((Vec128 *)pauVar8)[1] = auVar10;
          pauVar6 = pauVar6 + 4;
          pauVar8 = pauVar8 + 4;
          EI();
          iVar4 = iVar4 + 1;
        } while (iVar4 < param_4);
      }
      uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
      }
      uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
        do {
          uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar3 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x100;
      REG_DMAC_8_SPR_FROM_SADR = 0x1fc0;
      REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar9);
      REG_DMAC_8_SPR_FROM_QWC = param_4 << 2;
      REG_DMAC_8_SPR_FROM_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
    }
  }
  else {
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    _ctc2(0x3f000000);
    _vnop();
    _vnop();
    EI();
    iVar5 = 0;
    if (0 < param_4) {
      do {
        do {
          DI();
          SYNC(0x10);
        } while ((Status & 0x10000) != 0);
        auVar10 = _lqc2(*pauVar8);
        auVar11 = _lqc2(pauVar8[1]);
        _lqc2(pauVar8[2]);
        auVar12 = _lqc2(pauVar8[3]);
        auVar13 = _vmuli(auVar10,in_vuI);
        auVar14 = _vmuli(auVar11,in_vuI);
        auVar12 = _vadd(auVar12,auVar14);
        auVar12 = _vadd(auVar12,auVar13);
        auVar13 = _vsub(auVar12,auVar10);
        auVar14 = _vsub(auVar12,auVar11);
        auVar11 = _vsub(auVar13,auVar11);
        auVar10 = _sqc2(auVar12);
        ((Vec128 *)pauVar9)[3] = auVar10;
        auVar10 = _sqc2(auVar13);
        ((Vec128 *)pauVar9)[2] = auVar10;
        auVar10 = _sqc2(auVar14);
        *(Vec128 *)pauVar9 = auVar10;
        auVar10 = _sqc2(auVar11);
        ((Vec128 *)pauVar9)[1] = auVar10;
        pauVar8 = (u8 (*) [16])(*pauVar8 + iVar4);
        pauVar9 = (u8 (*) [16])(*pauVar9 + iVar1 * 4);
        EI();
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_4);
    }
  }
  return 0x3f000000;
}

// FUN_00483170 NONMATCHING

u32
FUN_00483170(u32 *param_1,u64 param_2,u64 param_3,int param_4,int param_5)

{
  int iVar1;
  char cVar2;
  u32 uVar3;
  int iVar4;
  u8 (*pauVar5) [16];
  u8 (*pauVar6) [16];
  int iVar7;
  u8 (*pauVar8) [16];
  u8 (*pauVar9) [16];
  Vec128 auVar10;
  Vec128 auVar11;
  Vec128 auVar12;
  Vec128 in_vf5;
  Vec128 extraout_vf5;
  Vec128 auVar13;
  Vec128 auVar14;
  Vec128 auVar15;
  u32 in_vuI;
  u64 uStack_8;
  
  iVar7 = param_1[1];
  iVar1 = *(int *)(param_5 + 0x10);
  pauVar9 = (u8 (*) [16])*param_1;
  pauVar8 = *(u8 (**) [16])(param_5 + 0xc);
  if (iVar1 == iVar7 << 2) {
    FlushCache(0);
    uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar3 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar2 = getCopCondition(0,0);
      } while (cVar2 == '\0');
    }
    uVar3 = REG_DMAC_9_SPR_TO_CHCR;
    if ((uVar3 & 0x100) != 0) {
      REG_DMAC_PCR = 0x200;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar2 = getCopCondition(0,0);
      } while (cVar2 == '\0');
      do {
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      } while ((uVar3 & 0x100) != 0);
    }
    DAT_70003fb0 = *(u32 *)(param_5 + 0x68);
    DAT_70003fb4 = *(u32 *)(param_5 + 0x6c);
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    _ctc2(0x3f000000);
    _vnop();
    _vnop();
    auVar10._8_8_ = uRam70003fb8;
    auVar10._0_8_ = *(u64 *)(param_5 + 0x68);
    _lqc2(auVar10);
    auVar13 = _vaddi(extraout_vf5,in_vuI);
    EI();
    if (0x7e < param_4) {
      do {
        uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
        }
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
          do {
            uVar3 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar3 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0;
        REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar8);
        REG_DMAC_9_SPR_TO_QWC = 0x1fc;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
          do {
            uVar3 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar3 & 0x100) != 0);
        }
        pauVar6 = (u8 (*) [16])(u8 *)DAT_70000000;
        iVar7 = 0;
        pauVar5 = (u8 (*) [16])(u8 *)DAT_70001fc0;
        do {
          do {
            DI();
            SYNC(0x10);
          } while ((Status & 0x10000) != 0);
          auVar10 = _lqc2(*pauVar6);
          auVar11 = _lqc2(pauVar6[1]);
          _lqc2(pauVar6[2]);
          auVar12 = _lqc2(pauVar6[3]);
          auVar14 = _vmulbc(auVar10,auVar13);
          auVar15 = _vmulbc(auVar11,auVar13);
          auVar12 = _vadd(auVar12,auVar15);
          auVar12 = _vadd(auVar12,auVar14);
          auVar14 = _vsub(auVar12,auVar10);
          auVar15 = _vsub(auVar12,auVar11);
          auVar11 = _vsub(auVar14,auVar11);
          auVar10 = _sqc2(auVar12);
          ((Vec128 *)pauVar5)[3] = auVar10;
          auVar10 = _sqc2(auVar14);
          ((Vec128 *)pauVar5)[2] = auVar10;
          auVar10 = _sqc2(auVar15);
          *(Vec128 *)pauVar5 = auVar10;
          auVar10 = _sqc2(auVar11);
          ((Vec128 *)pauVar5)[1] = auVar10;
          pauVar6 = pauVar6 + 4;
          pauVar5 = pauVar5 + 4;
          EI();
          iVar7 = iVar7 + 1;
        } while (iVar7 < 0x7f);
        uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
        }
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
          do {
            uVar3 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar3 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x100;
        REG_DMAC_8_SPR_FROM_SADR = 0x1fc0;
        REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar9);
        REG_DMAC_8_SPR_FROM_QWC = 0x1fc;
        REG_DMAC_8_SPR_FROM_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        param_4 = param_4 + -0x7f;
        pauVar8 = pauVar8 + 0x1fc;
        pauVar9 = pauVar9 + 0x1fc;
      } while (0x7e < param_4);
    }
    if (param_4 != 0) {
      uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
      }
      uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
        do {
          uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar3 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = 0;
      REG_DMAC_9_SPR_TO_MADR = (u32)(pauVar8);
      REG_DMAC_9_SPR_TO_QWC = param_4 << 2;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
        do {
          uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar3 & 0x100) != 0);
      }
      pauVar5 = (u8 (*) [16])(u8 *)DAT_70000000;
      pauVar8 = (u8 (*) [16])(u8 *)DAT_70001fc0;
      iVar7 = 0;
      if (0 < param_4) {
        do {
          do {
            DI();
            SYNC(0x10);
          } while ((Status & 0x10000) != 0);
          auVar10 = _lqc2(*pauVar5);
          auVar11 = _lqc2(pauVar5[1]);
          _lqc2(pauVar5[2]);
          auVar12 = _lqc2(pauVar5[3]);
          auVar14 = _vmulbc(auVar10,auVar13);
          auVar15 = _vmulbc(auVar11,auVar13);
          auVar12 = _vadd(auVar12,auVar15);
          auVar12 = _vadd(auVar12,auVar14);
          auVar14 = _vsub(auVar12,auVar10);
          auVar15 = _vsub(auVar12,auVar11);
          auVar11 = _vsub(auVar14,auVar11);
          auVar10 = _sqc2(auVar12);
          ((Vec128 *)pauVar8)[3] = auVar10;
          auVar10 = _sqc2(auVar14);
          ((Vec128 *)pauVar8)[2] = auVar10;
          auVar10 = _sqc2(auVar15);
          *(Vec128 *)pauVar8 = auVar10;
          auVar10 = _sqc2(auVar11);
          ((Vec128 *)pauVar8)[1] = auVar10;
          pauVar5 = pauVar5 + 4;
          pauVar8 = pauVar8 + 4;
          EI();
          iVar7 = iVar7 + 1;
        } while (iVar7 < param_4);
      }
      uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
      }
      uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
        do {
          uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar3 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x100;
      REG_DMAC_8_SPR_FROM_SADR = 0x1fc0;
      REG_DMAC_8_SPR_FROM_MADR = (u32)(pauVar9);
      REG_DMAC_8_SPR_FROM_QWC = param_4 << 2;
      REG_DMAC_8_SPR_FROM_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
    }
  }
  else {
    do {
      DI();
      SYNC(0x10);
    } while ((Status & 0x10000) != 0);
    _ctc2(0x3f000000);
    _vnop();
    _vnop();
    auVar13._8_8_ = uStack_8;
    auVar13._0_8_ = *(u64 *)(param_5 + 0x68);
    _lqc2(auVar13);
    auVar13 = _vaddi(in_vf5,in_vuI);
    EI();
    iVar4 = 0;
    if (0 < param_4) {
      do {
        do {
          DI();
          SYNC(0x10);
        } while ((Status & 0x10000) != 0);
        auVar10 = _lqc2(*pauVar8);
        auVar11 = _lqc2(pauVar8[1]);
        _lqc2(pauVar8[2]);
        auVar12 = _lqc2(pauVar8[3]);
        auVar14 = _vmulbc(auVar10,auVar13);
        auVar15 = _vmulbc(auVar11,auVar13);
        auVar12 = _vadd(auVar12,auVar15);
        auVar12 = _vadd(auVar12,auVar14);
        auVar14 = _vsub(auVar12,auVar10);
        auVar15 = _vsub(auVar12,auVar11);
        auVar11 = _vsub(auVar14,auVar11);
        auVar10 = _sqc2(auVar12);
        ((Vec128 *)pauVar9)[3] = auVar10;
        auVar10 = _sqc2(auVar14);
        ((Vec128 *)pauVar9)[2] = auVar10;
        auVar10 = _sqc2(auVar15);
        *(Vec128 *)pauVar9 = auVar10;
        auVar10 = _sqc2(auVar11);
        ((Vec128 *)pauVar9)[1] = auVar10;
        pauVar8 = (u8 (*) [16])(*pauVar8 + iVar1);
        pauVar9 = (u8 (*) [16])(*pauVar9 + iVar7 * 4);
        EI();
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_4);
    }
  }
  return 0x3f000000;
}

// FUN_004838E0 NONMATCHING

void FUN_004838e0(u32 *param_1,int param_2,int param_3)

{
  u8 uVar1;
  u8 uVar2;
  u8 uVar3;
  char cVar4;
  u8 bVar5;
  u32 *puVar6;
  u32 *puVar7;
  int iVar8;
  u32 *puVar9;
  u32 *puVar10;
  u32 *puVar11;
  u32 *puVar12;
  u32 *puVar13;
  u8 *puVar14;
  u32 *puVar15;
  u32 *puVar16;
  int iVar17;
  u32 *puVar18;
  u32 *puVar19;
  u32 *puVar20;
  u32 *puVar21;
  u32 *puVar22;
  u32 *puVar23;
  u32 *puVar24;
  u32 *puVar25;
  u32 *puVar26;
  u32 *puVar27;
  u32 *puVar28;
  u32 *puVar29;
  u32 *puVar30;
  u32 *puVar31;
  u32 *puVar32;
  u32 *puVar33;
  u32 *puVar34;
  u32 *puVar35;
  u32 *puVar36;
  u32 *puVar37;
  u32 *puVar38;
  u32 *puVar39;
  u32 *puVar40;
  u32 *puVar41;
  int iVar42;
  u32 *puVar43;
  u32 *puVar44;
  u32 *puVar45;
  float fVar46;
  u32 uVar47;
  
  iVar17 = param_1[1];
  iVar8 = *(int *)(param_3 + 0x28);
  param_1 = (u32 *)*param_1;
  puVar38 = *(u32 **)(param_3 + 0x24);
  if (iVar8 == iVar17) {
    FlushCache(0);
    uVar47 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar47 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar4 = getCopCondition(0,0);
      } while (cVar4 == '\0');
    }
    uVar47 = REG_DMAC_9_SPR_TO_CHCR;
    if ((uVar47 & 0x100) != 0) {
      REG_DMAC_PCR = 0x200;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar4 = getCopCondition(0,0);
      } while (cVar4 == '\0');
      do {
        uVar47 = REG_DMAC_9_SPR_TO_CHCR;
      } while ((uVar47 & 0x100) != 0);
    }
    if (0x330 < param_2) {
      do {
        uVar47 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar47 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
        }
        uVar47 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar47 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar47 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar47 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0;
        REG_DMAC_9_SPR_TO_MADR = (u32)(puVar38);
        REG_DMAC_9_SPR_TO_QWC = 0xcc;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar47 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar47 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar47 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar47 & 0x100) != 0);
        }
        puVar6 = (u32 *)((u8 *)DAT_70000000);
        iVar17 = 0;
        puVar14 = (u8 *)DAT_70000cc0;
        do {
          uVar1 = *(u8 *)((int)puVar6 + 1);
          iVar17 = iVar17 + 8;
          uVar2 = *(u8 *)((int)puVar6 + 2);
          uVar3 = *(u8 *)((int)puVar6 + 3);
          *puVar14 = *(u8 *)puVar6;
          puVar14[1] = uVar1;
          puVar14[2] = uVar2;
          puVar14[3] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 1);
          uVar2 = *(u8 *)((int)puVar6 + 2);
          uVar3 = *(u8 *)((int)puVar6 + 3);
          puVar14[4] = *(u8 *)puVar6;
          puVar14[5] = uVar1;
          puVar14[6] = uVar2;
          puVar14[7] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 1);
          uVar2 = *(u8 *)((int)puVar6 + 2);
          uVar3 = *(u8 *)((int)puVar6 + 3);
          puVar14[8] = *(u8 *)puVar6;
          puVar14[9] = uVar1;
          puVar14[10] = uVar2;
          puVar14[0xb] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 1);
          uVar2 = *(u8 *)((int)puVar6 + 2);
          uVar3 = *(u8 *)((int)puVar6 + 3);
          puVar14[0xc] = *(u8 *)puVar6;
          puVar14[0xd] = uVar1;
          puVar14[0xe] = uVar2;
          puVar14[0xf] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 5);
          uVar2 = *(u8 *)((int)puVar6 + 6);
          uVar3 = *(u8 *)((int)puVar6 + 7);
          puVar14[0x10] = *(u8 *)(puVar6 + 1);
          puVar14[0x11] = uVar1;
          puVar14[0x12] = uVar2;
          puVar14[0x13] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 5);
          uVar2 = *(u8 *)((int)puVar6 + 6);
          uVar3 = *(u8 *)((int)puVar6 + 7);
          puVar14[0x14] = *(u8 *)(puVar6 + 1);
          puVar14[0x15] = uVar1;
          puVar14[0x16] = uVar2;
          puVar14[0x17] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 5);
          uVar2 = *(u8 *)((int)puVar6 + 6);
          uVar3 = *(u8 *)((int)puVar6 + 7);
          puVar14[0x18] = *(u8 *)(puVar6 + 1);
          puVar14[0x19] = uVar1;
          puVar14[0x1a] = uVar2;
          puVar14[0x1b] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 5);
          uVar2 = *(u8 *)((int)puVar6 + 6);
          uVar3 = *(u8 *)((int)puVar6 + 7);
          puVar14[0x1c] = *(u8 *)(puVar6 + 1);
          puVar14[0x1d] = uVar1;
          puVar14[0x1e] = uVar2;
          puVar14[0x1f] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 9);
          uVar2 = *(u8 *)((int)puVar6 + 10);
          uVar3 = *(u8 *)((int)puVar6 + 0xb);
          puVar14[0x20] = *(u8 *)(puVar6 + 2);
          puVar14[0x21] = uVar1;
          puVar14[0x22] = uVar2;
          puVar14[0x23] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 9);
          uVar2 = *(u8 *)((int)puVar6 + 10);
          uVar3 = *(u8 *)((int)puVar6 + 0xb);
          puVar14[0x24] = *(u8 *)(puVar6 + 2);
          puVar14[0x25] = uVar1;
          puVar14[0x26] = uVar2;
          puVar14[0x27] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 9);
          uVar2 = *(u8 *)((int)puVar6 + 10);
          uVar3 = *(u8 *)((int)puVar6 + 0xb);
          puVar14[0x28] = *(u8 *)(puVar6 + 2);
          puVar14[0x29] = uVar1;
          puVar14[0x2a] = uVar2;
          puVar14[0x2b] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 9);
          uVar2 = *(u8 *)((int)puVar6 + 10);
          uVar3 = *(u8 *)((int)puVar6 + 0xb);
          puVar14[0x2c] = *(u8 *)(puVar6 + 2);
          puVar14[0x2d] = uVar1;
          puVar14[0x2e] = uVar2;
          puVar14[0x2f] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0xd);
          uVar2 = *(u8 *)((int)puVar6 + 0xe);
          uVar3 = *(u8 *)((int)puVar6 + 0xf);
          puVar14[0x30] = *(u8 *)(puVar6 + 3);
          puVar14[0x31] = uVar1;
          puVar14[0x32] = uVar2;
          puVar14[0x33] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0xd);
          uVar2 = *(u8 *)((int)puVar6 + 0xe);
          uVar3 = *(u8 *)((int)puVar6 + 0xf);
          puVar14[0x34] = *(u8 *)(puVar6 + 3);
          puVar14[0x35] = uVar1;
          puVar14[0x36] = uVar2;
          puVar14[0x37] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0xd);
          uVar2 = *(u8 *)((int)puVar6 + 0xe);
          uVar3 = *(u8 *)((int)puVar6 + 0xf);
          puVar14[0x38] = *(u8 *)(puVar6 + 3);
          puVar14[0x39] = uVar1;
          puVar14[0x3a] = uVar2;
          puVar14[0x3b] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0xd);
          uVar2 = *(u8 *)((int)puVar6 + 0xe);
          uVar3 = *(u8 *)((int)puVar6 + 0xf);
          puVar14[0x3c] = *(u8 *)(puVar6 + 3);
          puVar14[0x3d] = uVar1;
          puVar14[0x3e] = uVar2;
          puVar14[0x3f] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0x11);
          uVar2 = *(u8 *)((int)puVar6 + 0x12);
          uVar3 = *(u8 *)((int)puVar6 + 0x13);
          puVar14[0x40] = *(u8 *)(puVar6 + 4);
          puVar14[0x41] = uVar1;
          puVar14[0x42] = uVar2;
          puVar14[0x43] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0x11);
          uVar2 = *(u8 *)((int)puVar6 + 0x12);
          uVar3 = *(u8 *)((int)puVar6 + 0x13);
          puVar14[0x44] = *(u8 *)(puVar6 + 4);
          puVar14[0x45] = uVar1;
          puVar14[0x46] = uVar2;
          puVar14[0x47] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0x11);
          uVar2 = *(u8 *)((int)puVar6 + 0x12);
          uVar3 = *(u8 *)((int)puVar6 + 0x13);
          puVar14[0x48] = *(u8 *)(puVar6 + 4);
          puVar14[0x49] = uVar1;
          puVar14[0x4a] = uVar2;
          puVar14[0x4b] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0x11);
          uVar2 = *(u8 *)((int)puVar6 + 0x12);
          uVar3 = *(u8 *)((int)puVar6 + 0x13);
          puVar14[0x4c] = *(u8 *)(puVar6 + 4);
          puVar14[0x4d] = uVar1;
          puVar14[0x4e] = uVar2;
          puVar14[0x4f] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0x15);
          uVar2 = *(u8 *)((int)puVar6 + 0x16);
          uVar3 = *(u8 *)((int)puVar6 + 0x17);
          puVar14[0x50] = *(u8 *)(puVar6 + 5);
          puVar14[0x51] = uVar1;
          puVar14[0x52] = uVar2;
          puVar14[0x53] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0x15);
          uVar2 = *(u8 *)((int)puVar6 + 0x16);
          uVar3 = *(u8 *)((int)puVar6 + 0x17);
          puVar14[0x54] = *(u8 *)(puVar6 + 5);
          puVar14[0x55] = uVar1;
          puVar14[0x56] = uVar2;
          puVar14[0x57] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0x15);
          uVar2 = *(u8 *)((int)puVar6 + 0x16);
          uVar3 = *(u8 *)((int)puVar6 + 0x17);
          puVar14[0x58] = *(u8 *)(puVar6 + 5);
          puVar14[0x59] = uVar1;
          puVar14[0x5a] = uVar2;
          puVar14[0x5b] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0x15);
          uVar2 = *(u8 *)((int)puVar6 + 0x16);
          uVar3 = *(u8 *)((int)puVar6 + 0x17);
          puVar14[0x5c] = *(u8 *)(puVar6 + 5);
          puVar14[0x5d] = uVar1;
          puVar14[0x5e] = uVar2;
          puVar14[0x5f] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0x19);
          uVar2 = *(u8 *)((int)puVar6 + 0x1a);
          uVar3 = *(u8 *)((int)puVar6 + 0x1b);
          puVar14[0x60] = *(u8 *)(puVar6 + 6);
          puVar14[0x61] = uVar1;
          puVar14[0x62] = uVar2;
          puVar14[99] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0x19);
          uVar2 = *(u8 *)((int)puVar6 + 0x1a);
          uVar3 = *(u8 *)((int)puVar6 + 0x1b);
          puVar14[100] = *(u8 *)(puVar6 + 6);
          puVar14[0x65] = uVar1;
          puVar14[0x66] = uVar2;
          puVar14[0x67] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0x19);
          uVar2 = *(u8 *)((int)puVar6 + 0x1a);
          uVar3 = *(u8 *)((int)puVar6 + 0x1b);
          puVar14[0x68] = *(u8 *)(puVar6 + 6);
          puVar14[0x69] = uVar1;
          puVar14[0x6a] = uVar2;
          puVar14[0x6b] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0x19);
          uVar2 = *(u8 *)((int)puVar6 + 0x1a);
          uVar3 = *(u8 *)((int)puVar6 + 0x1b);
          puVar14[0x6c] = *(u8 *)(puVar6 + 6);
          puVar14[0x6d] = uVar1;
          puVar14[0x6e] = uVar2;
          puVar14[0x6f] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0x1d);
          uVar2 = *(u8 *)((int)puVar6 + 0x1e);
          uVar3 = *(u8 *)((int)puVar6 + 0x1f);
          puVar14[0x70] = *(u8 *)(puVar6 + 7);
          puVar14[0x71] = uVar1;
          puVar14[0x72] = uVar2;
          puVar14[0x73] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0x1d);
          uVar2 = *(u8 *)((int)puVar6 + 0x1e);
          uVar3 = *(u8 *)((int)puVar6 + 0x1f);
          puVar14[0x74] = *(u8 *)(puVar6 + 7);
          puVar14[0x75] = uVar1;
          puVar14[0x76] = uVar2;
          puVar14[0x77] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0x1d);
          uVar2 = *(u8 *)((int)puVar6 + 0x1e);
          uVar3 = *(u8 *)((int)puVar6 + 0x1f);
          puVar14[0x78] = *(u8 *)(puVar6 + 7);
          puVar14[0x79] = uVar1;
          puVar14[0x7a] = uVar2;
          puVar14[0x7b] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 0x1d);
          uVar2 = *(u8 *)((int)puVar6 + 0x1e);
          uVar3 = *(u8 *)((int)puVar6 + 0x1f);
          puVar14[0x7c] = *(u8 *)(puVar6 + 7);
          puVar6 = puVar6 + 8;
          puVar14[0x7d] = uVar1;
          puVar14[0x7e] = uVar2;
          puVar14[0x7f] = uVar3;
          puVar14 = puVar14 + 0x80;
        } while (iVar17 < 0x330);
        uVar47 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar47 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
        }
        uVar47 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar47 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar4 = getCopCondition(0,0);
          } while (cVar4 == '\0');
          do {
            uVar47 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar47 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x100;
        REG_DMAC_8_SPR_FROM_SADR = 0xcc0;
        REG_DMAC_8_SPR_FROM_MADR = (u32)(param_1);
        REG_DMAC_8_SPR_FROM_QWC = 0x330;
        REG_DMAC_8_SPR_FROM_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        param_2 = param_2 + -0x330;
        puVar38 = puVar38 + 0x330;
        param_1 = param_1 + 0xcc0;
      } while (0x330 < param_2);
    }
    if (3 < param_2) {
      iVar17 = param_2;
      if (param_2 < 0) {
        iVar17 = param_2 + 3;
      }
      iVar17 = iVar17 >> 2;
      iVar8 = iVar17 * 4;
      uVar47 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar47 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
      }
      uVar47 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar47 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar47 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar47 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = 0;
      REG_DMAC_9_SPR_TO_MADR = (u32)(puVar38);
      fVar46 = (float)iVar8 * 0.25;
      if (fVar46 < 2.1474836e+09) {
        uVar47 = (u32)fVar46;
      }
      else {
        uVar47 = (int)(fVar46 - 2.1474836e+09) | 0x80000000;
      }
      REG_DMAC_9_SPR_TO_QWC = uVar47;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar47 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar47 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar47 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar47 & 0x100) != 0);
      }
      puVar6 = (u32 *)((u8 *)DAT_70000000);
      iVar42 = 0;
      puVar14 = (u8 *)DAT_70000cc0;
      if (0 < iVar8) {
        if (8 < iVar8) {
          bVar5 = 0;
          if ((-1 < iVar8) && (iVar8 < 0x7fffffff)) {
            bVar5 = 1;
          }
          if (bVar5) {
            do {
              iVar42 = iVar42 + 8;
              uVar1 = *(u8 *)((int)puVar6 + 1);
              uVar2 = *(u8 *)((int)puVar6 + 2);
              uVar3 = *(u8 *)((int)puVar6 + 3);
              *puVar14 = *(u8 *)puVar6;
              puVar14[1] = uVar1;
              puVar14[2] = uVar2;
              puVar14[3] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 1);
              uVar2 = *(u8 *)((int)puVar6 + 2);
              uVar3 = *(u8 *)((int)puVar6 + 3);
              puVar14[4] = *(u8 *)puVar6;
              puVar14[5] = uVar1;
              puVar14[6] = uVar2;
              puVar14[7] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 1);
              uVar2 = *(u8 *)((int)puVar6 + 2);
              uVar3 = *(u8 *)((int)puVar6 + 3);
              puVar14[8] = *(u8 *)puVar6;
              puVar14[9] = uVar1;
              puVar14[10] = uVar2;
              puVar14[0xb] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 1);
              uVar2 = *(u8 *)((int)puVar6 + 2);
              uVar3 = *(u8 *)((int)puVar6 + 3);
              puVar14[0xc] = *(u8 *)puVar6;
              puVar14[0xd] = uVar1;
              puVar14[0xe] = uVar2;
              puVar14[0xf] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 5);
              uVar2 = *(u8 *)((int)puVar6 + 6);
              uVar3 = *(u8 *)((int)puVar6 + 7);
              puVar14[0x10] = *(u8 *)(puVar6 + 1);
              puVar14[0x11] = uVar1;
              puVar14[0x12] = uVar2;
              puVar14[0x13] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 5);
              uVar2 = *(u8 *)((int)puVar6 + 6);
              uVar3 = *(u8 *)((int)puVar6 + 7);
              puVar14[0x14] = *(u8 *)(puVar6 + 1);
              puVar14[0x15] = uVar1;
              puVar14[0x16] = uVar2;
              puVar14[0x17] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 5);
              uVar2 = *(u8 *)((int)puVar6 + 6);
              uVar3 = *(u8 *)((int)puVar6 + 7);
              puVar14[0x18] = *(u8 *)(puVar6 + 1);
              puVar14[0x19] = uVar1;
              puVar14[0x1a] = uVar2;
              puVar14[0x1b] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 5);
              uVar2 = *(u8 *)((int)puVar6 + 6);
              uVar3 = *(u8 *)((int)puVar6 + 7);
              puVar14[0x1c] = *(u8 *)(puVar6 + 1);
              puVar14[0x1d] = uVar1;
              puVar14[0x1e] = uVar2;
              puVar14[0x1f] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 9);
              uVar2 = *(u8 *)((int)puVar6 + 10);
              uVar3 = *(u8 *)((int)puVar6 + 0xb);
              puVar14[0x20] = *(u8 *)(puVar6 + 2);
              puVar14[0x21] = uVar1;
              puVar14[0x22] = uVar2;
              puVar14[0x23] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 9);
              uVar2 = *(u8 *)((int)puVar6 + 10);
              uVar3 = *(u8 *)((int)puVar6 + 0xb);
              puVar14[0x24] = *(u8 *)(puVar6 + 2);
              puVar14[0x25] = uVar1;
              puVar14[0x26] = uVar2;
              puVar14[0x27] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 9);
              uVar2 = *(u8 *)((int)puVar6 + 10);
              uVar3 = *(u8 *)((int)puVar6 + 0xb);
              puVar14[0x28] = *(u8 *)(puVar6 + 2);
              puVar14[0x29] = uVar1;
              puVar14[0x2a] = uVar2;
              puVar14[0x2b] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 9);
              uVar2 = *(u8 *)((int)puVar6 + 10);
              uVar3 = *(u8 *)((int)puVar6 + 0xb);
              puVar14[0x2c] = *(u8 *)(puVar6 + 2);
              puVar14[0x2d] = uVar1;
              puVar14[0x2e] = uVar2;
              puVar14[0x2f] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0xd);
              uVar2 = *(u8 *)((int)puVar6 + 0xe);
              uVar3 = *(u8 *)((int)puVar6 + 0xf);
              puVar14[0x30] = *(u8 *)(puVar6 + 3);
              puVar14[0x31] = uVar1;
              puVar14[0x32] = uVar2;
              puVar14[0x33] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0xd);
              uVar2 = *(u8 *)((int)puVar6 + 0xe);
              uVar3 = *(u8 *)((int)puVar6 + 0xf);
              puVar14[0x34] = *(u8 *)(puVar6 + 3);
              puVar14[0x35] = uVar1;
              puVar14[0x36] = uVar2;
              puVar14[0x37] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0xd);
              uVar2 = *(u8 *)((int)puVar6 + 0xe);
              uVar3 = *(u8 *)((int)puVar6 + 0xf);
              puVar14[0x38] = *(u8 *)(puVar6 + 3);
              puVar14[0x39] = uVar1;
              puVar14[0x3a] = uVar2;
              puVar14[0x3b] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0xd);
              uVar2 = *(u8 *)((int)puVar6 + 0xe);
              uVar3 = *(u8 *)((int)puVar6 + 0xf);
              puVar14[0x3c] = *(u8 *)(puVar6 + 3);
              puVar14[0x3d] = uVar1;
              puVar14[0x3e] = uVar2;
              puVar14[0x3f] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0x11);
              uVar2 = *(u8 *)((int)puVar6 + 0x12);
              uVar3 = *(u8 *)((int)puVar6 + 0x13);
              puVar14[0x40] = *(u8 *)(puVar6 + 4);
              puVar14[0x41] = uVar1;
              puVar14[0x42] = uVar2;
              puVar14[0x43] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0x11);
              uVar2 = *(u8 *)((int)puVar6 + 0x12);
              uVar3 = *(u8 *)((int)puVar6 + 0x13);
              puVar14[0x44] = *(u8 *)(puVar6 + 4);
              puVar14[0x45] = uVar1;
              puVar14[0x46] = uVar2;
              puVar14[0x47] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0x11);
              uVar2 = *(u8 *)((int)puVar6 + 0x12);
              uVar3 = *(u8 *)((int)puVar6 + 0x13);
              puVar14[0x48] = *(u8 *)(puVar6 + 4);
              puVar14[0x49] = uVar1;
              puVar14[0x4a] = uVar2;
              puVar14[0x4b] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0x11);
              uVar2 = *(u8 *)((int)puVar6 + 0x12);
              uVar3 = *(u8 *)((int)puVar6 + 0x13);
              puVar14[0x4c] = *(u8 *)(puVar6 + 4);
              puVar14[0x4d] = uVar1;
              puVar14[0x4e] = uVar2;
              puVar14[0x4f] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0x15);
              uVar2 = *(u8 *)((int)puVar6 + 0x16);
              uVar3 = *(u8 *)((int)puVar6 + 0x17);
              puVar14[0x50] = *(u8 *)(puVar6 + 5);
              puVar14[0x51] = uVar1;
              puVar14[0x52] = uVar2;
              puVar14[0x53] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0x15);
              uVar2 = *(u8 *)((int)puVar6 + 0x16);
              uVar3 = *(u8 *)((int)puVar6 + 0x17);
              puVar14[0x54] = *(u8 *)(puVar6 + 5);
              puVar14[0x55] = uVar1;
              puVar14[0x56] = uVar2;
              puVar14[0x57] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0x15);
              uVar2 = *(u8 *)((int)puVar6 + 0x16);
              uVar3 = *(u8 *)((int)puVar6 + 0x17);
              puVar14[0x58] = *(u8 *)(puVar6 + 5);
              puVar14[0x59] = uVar1;
              puVar14[0x5a] = uVar2;
              puVar14[0x5b] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0x15);
              uVar2 = *(u8 *)((int)puVar6 + 0x16);
              uVar3 = *(u8 *)((int)puVar6 + 0x17);
              puVar14[0x5c] = *(u8 *)(puVar6 + 5);
              puVar14[0x5d] = uVar1;
              puVar14[0x5e] = uVar2;
              puVar14[0x5f] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0x19);
              uVar2 = *(u8 *)((int)puVar6 + 0x1a);
              uVar3 = *(u8 *)((int)puVar6 + 0x1b);
              puVar14[0x60] = *(u8 *)(puVar6 + 6);
              puVar14[0x61] = uVar1;
              puVar14[0x62] = uVar2;
              puVar14[99] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0x19);
              uVar2 = *(u8 *)((int)puVar6 + 0x1a);
              uVar3 = *(u8 *)((int)puVar6 + 0x1b);
              puVar14[100] = *(u8 *)(puVar6 + 6);
              puVar14[0x65] = uVar1;
              puVar14[0x66] = uVar2;
              puVar14[0x67] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0x19);
              uVar2 = *(u8 *)((int)puVar6 + 0x1a);
              uVar3 = *(u8 *)((int)puVar6 + 0x1b);
              puVar14[0x68] = *(u8 *)(puVar6 + 6);
              puVar14[0x69] = uVar1;
              puVar14[0x6a] = uVar2;
              puVar14[0x6b] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0x19);
              uVar2 = *(u8 *)((int)puVar6 + 0x1a);
              uVar3 = *(u8 *)((int)puVar6 + 0x1b);
              puVar14[0x6c] = *(u8 *)(puVar6 + 6);
              puVar14[0x6d] = uVar1;
              puVar14[0x6e] = uVar2;
              puVar14[0x6f] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0x1d);
              uVar2 = *(u8 *)((int)puVar6 + 0x1e);
              uVar3 = *(u8 *)((int)puVar6 + 0x1f);
              puVar14[0x70] = *(u8 *)(puVar6 + 7);
              puVar14[0x71] = uVar1;
              puVar14[0x72] = uVar2;
              puVar14[0x73] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0x1d);
              uVar2 = *(u8 *)((int)puVar6 + 0x1e);
              uVar3 = *(u8 *)((int)puVar6 + 0x1f);
              puVar14[0x74] = *(u8 *)(puVar6 + 7);
              puVar14[0x75] = uVar1;
              puVar14[0x76] = uVar2;
              puVar14[0x77] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0x1d);
              uVar2 = *(u8 *)((int)puVar6 + 0x1e);
              uVar3 = *(u8 *)((int)puVar6 + 0x1f);
              puVar14[0x78] = *(u8 *)(puVar6 + 7);
              puVar14[0x79] = uVar1;
              puVar14[0x7a] = uVar2;
              puVar14[0x7b] = uVar3;
              uVar1 = *(u8 *)((int)puVar6 + 0x1d);
              uVar2 = *(u8 *)((int)puVar6 + 0x1e);
              uVar3 = *(u8 *)((int)puVar6 + 0x1f);
              puVar14[0x7c] = *(u8 *)(puVar6 + 7);
              puVar6 = puVar6 + 8;
              puVar14[0x7d] = uVar1;
              puVar14[0x7e] = uVar2;
              puVar14[0x7f] = uVar3;
              puVar14 = puVar14 + 0x80;
            } while (iVar42 < iVar8 + -8);
          }
        }
        for (; iVar42 < iVar8; iVar42 = iVar42 + 1) {
          uVar1 = *(u8 *)((int)puVar6 + 1);
          uVar2 = *(u8 *)((int)puVar6 + 2);
          uVar3 = *(u8 *)((int)puVar6 + 3);
          *puVar14 = *(u8 *)puVar6;
          puVar14[1] = uVar1;
          puVar14[2] = uVar2;
          puVar14[3] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 1);
          uVar2 = *(u8 *)((int)puVar6 + 2);
          uVar3 = *(u8 *)((int)puVar6 + 3);
          puVar14[4] = *(u8 *)puVar6;
          puVar14[5] = uVar1;
          puVar14[6] = uVar2;
          puVar14[7] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 1);
          uVar2 = *(u8 *)((int)puVar6 + 2);
          uVar3 = *(u8 *)((int)puVar6 + 3);
          puVar14[8] = *(u8 *)puVar6;
          puVar14[9] = uVar1;
          puVar14[10] = uVar2;
          puVar14[0xb] = uVar3;
          uVar1 = *(u8 *)((int)puVar6 + 1);
          uVar2 = *(u8 *)((int)puVar6 + 2);
          uVar3 = *(u8 *)((int)puVar6 + 3);
          puVar14[0xc] = *(u8 *)puVar6;
          puVar6 = puVar6 + 1;
          puVar14[0xd] = uVar1;
          puVar14[0xe] = uVar2;
          puVar14[0xf] = uVar3;
          puVar14 = puVar14 + 0x10;
        }
      }
      uVar47 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar47 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
      }
      uVar47 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar47 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar4 = getCopCondition(0,0);
        } while (cVar4 == '\0');
        do {
          uVar47 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar47 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x100;
      REG_DMAC_8_SPR_FROM_SADR = 0xcc0;
      REG_DMAC_8_SPR_FROM_MADR = (u32)(param_1);
      REG_DMAC_8_SPR_FROM_QWC = iVar8;
      REG_DMAC_8_SPR_FROM_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      if (2.1474836e+09 <= fVar46) {
        fVar46 = fVar46 - 2.1474836e+09;
      }
      puVar38 = puVar38 + (int)fVar46 * 4;
      param_1 = param_1 + iVar17 * 0x10;
      param_2 = param_2 + iVar17 * -4;
    }
    if ((param_2 != 0) && (iVar17 = 0, 0 < param_2)) {
      if (8 < param_2) {
        bVar5 = 0;
        if ((-1 < param_2) && (param_2 < 0x7fffffff)) {
          bVar5 = 1;
        }
        if (bVar5) {
          do {
            iVar17 = iVar17 + 8;
            uVar1 = *(u8 *)((int)puVar38 + 1);
            uVar2 = *(u8 *)((int)puVar38 + 2);
            uVar3 = *(u8 *)((int)puVar38 + 3);
            *(u8 *)param_1 = *(u8 *)puVar38;
            *(u8 *)((int)param_1 + 1) = uVar1;
            *(u8 *)((int)param_1 + 2) = uVar2;
            *(u8 *)((int)param_1 + 3) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 1);
            uVar2 = *(u8 *)((int)puVar38 + 2);
            uVar3 = *(u8 *)((int)puVar38 + 3);
            *(u8 *)(param_1 + 1) = *(u8 *)puVar38;
            *(u8 *)((int)param_1 + 5) = uVar1;
            *(u8 *)((int)param_1 + 6) = uVar2;
            *(u8 *)((int)param_1 + 7) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 1);
            uVar2 = *(u8 *)((int)puVar38 + 2);
            uVar3 = *(u8 *)((int)puVar38 + 3);
            *(u8 *)(param_1 + 2) = *(u8 *)puVar38;
            *(u8 *)((int)param_1 + 9) = uVar1;
            *(u8 *)((int)param_1 + 10) = uVar2;
            *(u8 *)((int)param_1 + 0xb) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 1);
            uVar2 = *(u8 *)((int)puVar38 + 2);
            uVar3 = *(u8 *)((int)puVar38 + 3);
            *(u8 *)(param_1 + 3) = *(u8 *)puVar38;
            *(u8 *)((int)param_1 + 0xd) = uVar1;
            *(u8 *)((int)param_1 + 0xe) = uVar2;
            *(u8 *)((int)param_1 + 0xf) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 5);
            uVar2 = *(u8 *)((int)puVar38 + 6);
            uVar3 = *(u8 *)((int)puVar38 + 7);
            *(u8 *)(param_1 + 4) = *(u8 *)(puVar38 + 1);
            *(u8 *)((int)param_1 + 0x11) = uVar1;
            *(u8 *)((int)param_1 + 0x12) = uVar2;
            *(u8 *)((int)param_1 + 0x13) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 5);
            uVar2 = *(u8 *)((int)puVar38 + 6);
            uVar3 = *(u8 *)((int)puVar38 + 7);
            *(u8 *)(param_1 + 5) = *(u8 *)(puVar38 + 1);
            *(u8 *)((int)param_1 + 0x15) = uVar1;
            *(u8 *)((int)param_1 + 0x16) = uVar2;
            *(u8 *)((int)param_1 + 0x17) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 5);
            uVar2 = *(u8 *)((int)puVar38 + 6);
            uVar3 = *(u8 *)((int)puVar38 + 7);
            *(u8 *)(param_1 + 6) = *(u8 *)(puVar38 + 1);
            *(u8 *)((int)param_1 + 0x19) = uVar1;
            *(u8 *)((int)param_1 + 0x1a) = uVar2;
            *(u8 *)((int)param_1 + 0x1b) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 5);
            uVar2 = *(u8 *)((int)puVar38 + 6);
            uVar3 = *(u8 *)((int)puVar38 + 7);
            *(u8 *)(param_1 + 7) = *(u8 *)(puVar38 + 1);
            *(u8 *)((int)param_1 + 0x1d) = uVar1;
            *(u8 *)((int)param_1 + 0x1e) = uVar2;
            *(u8 *)((int)param_1 + 0x1f) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 9);
            uVar2 = *(u8 *)((int)puVar38 + 10);
            uVar3 = *(u8 *)((int)puVar38 + 0xb);
            *(u8 *)(param_1 + 8) = *(u8 *)(puVar38 + 2);
            *(u8 *)((int)param_1 + 0x21) = uVar1;
            *(u8 *)((int)param_1 + 0x22) = uVar2;
            *(u8 *)((int)param_1 + 0x23) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 9);
            uVar2 = *(u8 *)((int)puVar38 + 10);
            uVar3 = *(u8 *)((int)puVar38 + 0xb);
            *(u8 *)(param_1 + 9) = *(u8 *)(puVar38 + 2);
            *(u8 *)((int)param_1 + 0x25) = uVar1;
            *(u8 *)((int)param_1 + 0x26) = uVar2;
            *(u8 *)((int)param_1 + 0x27) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 9);
            uVar2 = *(u8 *)((int)puVar38 + 10);
            uVar3 = *(u8 *)((int)puVar38 + 0xb);
            *(u8 *)(param_1 + 10) = *(u8 *)(puVar38 + 2);
            *(u8 *)((int)param_1 + 0x29) = uVar1;
            *(u8 *)((int)param_1 + 0x2a) = uVar2;
            *(u8 *)((int)param_1 + 0x2b) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 9);
            uVar2 = *(u8 *)((int)puVar38 + 10);
            uVar3 = *(u8 *)((int)puVar38 + 0xb);
            *(u8 *)(param_1 + 0xb) = *(u8 *)(puVar38 + 2);
            *(u8 *)((int)param_1 + 0x2d) = uVar1;
            *(u8 *)((int)param_1 + 0x2e) = uVar2;
            *(u8 *)((int)param_1 + 0x2f) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0xd);
            uVar2 = *(u8 *)((int)puVar38 + 0xe);
            uVar3 = *(u8 *)((int)puVar38 + 0xf);
            *(u8 *)(param_1 + 0xc) = *(u8 *)(puVar38 + 3);
            *(u8 *)((int)param_1 + 0x31) = uVar1;
            *(u8 *)((int)param_1 + 0x32) = uVar2;
            *(u8 *)((int)param_1 + 0x33) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0xd);
            uVar2 = *(u8 *)((int)puVar38 + 0xe);
            uVar3 = *(u8 *)((int)puVar38 + 0xf);
            *(u8 *)(param_1 + 0xd) = *(u8 *)(puVar38 + 3);
            *(u8 *)((int)param_1 + 0x35) = uVar1;
            *(u8 *)((int)param_1 + 0x36) = uVar2;
            *(u8 *)((int)param_1 + 0x37) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0xd);
            uVar2 = *(u8 *)((int)puVar38 + 0xe);
            uVar3 = *(u8 *)((int)puVar38 + 0xf);
            *(u8 *)(param_1 + 0xe) = *(u8 *)(puVar38 + 3);
            *(u8 *)((int)param_1 + 0x39) = uVar1;
            *(u8 *)((int)param_1 + 0x3a) = uVar2;
            *(u8 *)((int)param_1 + 0x3b) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0xd);
            uVar2 = *(u8 *)((int)puVar38 + 0xe);
            uVar3 = *(u8 *)((int)puVar38 + 0xf);
            *(u8 *)(param_1 + 0xf) = *(u8 *)(puVar38 + 3);
            *(u8 *)((int)param_1 + 0x3d) = uVar1;
            *(u8 *)((int)param_1 + 0x3e) = uVar2;
            *(u8 *)((int)param_1 + 0x3f) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0x11);
            uVar2 = *(u8 *)((int)puVar38 + 0x12);
            uVar3 = *(u8 *)((int)puVar38 + 0x13);
            *(u8 *)(param_1 + 0x10) = *(u8 *)(puVar38 + 4);
            *(u8 *)((int)param_1 + 0x41) = uVar1;
            *(u8 *)((int)param_1 + 0x42) = uVar2;
            *(u8 *)((int)param_1 + 0x43) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0x11);
            uVar2 = *(u8 *)((int)puVar38 + 0x12);
            uVar3 = *(u8 *)((int)puVar38 + 0x13);
            *(u8 *)(param_1 + 0x11) = *(u8 *)(puVar38 + 4);
            *(u8 *)((int)param_1 + 0x45) = uVar1;
            *(u8 *)((int)param_1 + 0x46) = uVar2;
            *(u8 *)((int)param_1 + 0x47) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0x11);
            uVar2 = *(u8 *)((int)puVar38 + 0x12);
            uVar3 = *(u8 *)((int)puVar38 + 0x13);
            *(u8 *)(param_1 + 0x12) = *(u8 *)(puVar38 + 4);
            *(u8 *)((int)param_1 + 0x49) = uVar1;
            *(u8 *)((int)param_1 + 0x4a) = uVar2;
            *(u8 *)((int)param_1 + 0x4b) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0x11);
            uVar2 = *(u8 *)((int)puVar38 + 0x12);
            uVar3 = *(u8 *)((int)puVar38 + 0x13);
            *(u8 *)(param_1 + 0x13) = *(u8 *)(puVar38 + 4);
            *(u8 *)((int)param_1 + 0x4d) = uVar1;
            *(u8 *)((int)param_1 + 0x4e) = uVar2;
            *(u8 *)((int)param_1 + 0x4f) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0x15);
            uVar2 = *(u8 *)((int)puVar38 + 0x16);
            uVar3 = *(u8 *)((int)puVar38 + 0x17);
            *(u8 *)(param_1 + 0x14) = *(u8 *)(puVar38 + 5);
            *(u8 *)((int)param_1 + 0x51) = uVar1;
            *(u8 *)((int)param_1 + 0x52) = uVar2;
            *(u8 *)((int)param_1 + 0x53) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0x15);
            uVar2 = *(u8 *)((int)puVar38 + 0x16);
            uVar3 = *(u8 *)((int)puVar38 + 0x17);
            *(u8 *)(param_1 + 0x15) = *(u8 *)(puVar38 + 5);
            *(u8 *)((int)param_1 + 0x55) = uVar1;
            *(u8 *)((int)param_1 + 0x56) = uVar2;
            *(u8 *)((int)param_1 + 0x57) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0x15);
            uVar2 = *(u8 *)((int)puVar38 + 0x16);
            uVar3 = *(u8 *)((int)puVar38 + 0x17);
            *(u8 *)(param_1 + 0x16) = *(u8 *)(puVar38 + 5);
            *(u8 *)((int)param_1 + 0x59) = uVar1;
            *(u8 *)((int)param_1 + 0x5a) = uVar2;
            *(u8 *)((int)param_1 + 0x5b) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0x15);
            uVar2 = *(u8 *)((int)puVar38 + 0x16);
            uVar3 = *(u8 *)((int)puVar38 + 0x17);
            *(u8 *)(param_1 + 0x17) = *(u8 *)(puVar38 + 5);
            *(u8 *)((int)param_1 + 0x5d) = uVar1;
            *(u8 *)((int)param_1 + 0x5e) = uVar2;
            *(u8 *)((int)param_1 + 0x5f) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0x19);
            uVar2 = *(u8 *)((int)puVar38 + 0x1a);
            uVar3 = *(u8 *)((int)puVar38 + 0x1b);
            *(u8 *)(param_1 + 0x18) = *(u8 *)(puVar38 + 6);
            *(u8 *)((int)param_1 + 0x61) = uVar1;
            *(u8 *)((int)param_1 + 0x62) = uVar2;
            *(u8 *)((int)param_1 + 99) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0x19);
            uVar2 = *(u8 *)((int)puVar38 + 0x1a);
            uVar3 = *(u8 *)((int)puVar38 + 0x1b);
            *(u8 *)(param_1 + 0x19) = *(u8 *)(puVar38 + 6);
            *(u8 *)((int)param_1 + 0x65) = uVar1;
            *(u8 *)((int)param_1 + 0x66) = uVar2;
            *(u8 *)((int)param_1 + 0x67) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0x19);
            uVar2 = *(u8 *)((int)puVar38 + 0x1a);
            uVar3 = *(u8 *)((int)puVar38 + 0x1b);
            *(u8 *)(param_1 + 0x1a) = *(u8 *)(puVar38 + 6);
            *(u8 *)((int)param_1 + 0x69) = uVar1;
            *(u8 *)((int)param_1 + 0x6a) = uVar2;
            *(u8 *)((int)param_1 + 0x6b) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0x19);
            uVar2 = *(u8 *)((int)puVar38 + 0x1a);
            uVar3 = *(u8 *)((int)puVar38 + 0x1b);
            *(u8 *)(param_1 + 0x1b) = *(u8 *)(puVar38 + 6);
            *(u8 *)((int)param_1 + 0x6d) = uVar1;
            *(u8 *)((int)param_1 + 0x6e) = uVar2;
            *(u8 *)((int)param_1 + 0x6f) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0x1d);
            uVar2 = *(u8 *)((int)puVar38 + 0x1e);
            uVar3 = *(u8 *)((int)puVar38 + 0x1f);
            *(u8 *)(param_1 + 0x1c) = *(u8 *)(puVar38 + 7);
            *(u8 *)((int)param_1 + 0x71) = uVar1;
            *(u8 *)((int)param_1 + 0x72) = uVar2;
            *(u8 *)((int)param_1 + 0x73) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0x1d);
            uVar2 = *(u8 *)((int)puVar38 + 0x1e);
            uVar3 = *(u8 *)((int)puVar38 + 0x1f);
            *(u8 *)(param_1 + 0x1d) = *(u8 *)(puVar38 + 7);
            *(u8 *)((int)param_1 + 0x75) = uVar1;
            *(u8 *)((int)param_1 + 0x76) = uVar2;
            *(u8 *)((int)param_1 + 0x77) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0x1d);
            uVar2 = *(u8 *)((int)puVar38 + 0x1e);
            uVar3 = *(u8 *)((int)puVar38 + 0x1f);
            *(u8 *)(param_1 + 0x1e) = *(u8 *)(puVar38 + 7);
            *(u8 *)((int)param_1 + 0x79) = uVar1;
            *(u8 *)((int)param_1 + 0x7a) = uVar2;
            *(u8 *)((int)param_1 + 0x7b) = uVar3;
            uVar1 = *(u8 *)((int)puVar38 + 0x1d);
            uVar2 = *(u8 *)((int)puVar38 + 0x1e);
            uVar3 = *(u8 *)((int)puVar38 + 0x1f);
            *(u8 *)(param_1 + 0x1f) = *(u8 *)(puVar38 + 7);
            puVar38 = puVar38 + 8;
            *(u8 *)((int)param_1 + 0x7d) = uVar1;
            *(u8 *)((int)param_1 + 0x7e) = uVar2;
            *(u8 *)((int)param_1 + 0x7f) = uVar3;
            param_1 = param_1 + 0x20;
          } while (iVar17 < param_2 + -8);
        }
      }
      for (; iVar17 < param_2; iVar17 = iVar17 + 1) {
        uVar1 = *(u8 *)((int)puVar38 + 1);
        uVar2 = *(u8 *)((int)puVar38 + 2);
        uVar3 = *(u8 *)((int)puVar38 + 3);
        *(u8 *)param_1 = *(u8 *)puVar38;
        *(u8 *)((int)param_1 + 1) = uVar1;
        *(u8 *)((int)param_1 + 2) = uVar2;
        *(u8 *)((int)param_1 + 3) = uVar3;
        uVar1 = *(u8 *)((int)puVar38 + 1);
        uVar2 = *(u8 *)((int)puVar38 + 2);
        uVar3 = *(u8 *)((int)puVar38 + 3);
        *(u8 *)(param_1 + 1) = *(u8 *)puVar38;
        *(u8 *)((int)param_1 + 5) = uVar1;
        *(u8 *)((int)param_1 + 6) = uVar2;
        *(u8 *)((int)param_1 + 7) = uVar3;
        uVar1 = *(u8 *)((int)puVar38 + 1);
        uVar2 = *(u8 *)((int)puVar38 + 2);
        uVar3 = *(u8 *)((int)puVar38 + 3);
        *(u8 *)(param_1 + 2) = *(u8 *)puVar38;
        *(u8 *)((int)param_1 + 9) = uVar1;
        *(u8 *)((int)param_1 + 10) = uVar2;
        *(u8 *)((int)param_1 + 0xb) = uVar3;
        uVar1 = *(u8 *)((int)puVar38 + 1);
        uVar2 = *(u8 *)((int)puVar38 + 2);
        uVar3 = *(u8 *)((int)puVar38 + 3);
        *(u8 *)(param_1 + 3) = *(u8 *)puVar38;
        puVar38 = puVar38 + 1;
        *(u8 *)((int)param_1 + 0xd) = uVar1;
        *(u8 *)((int)param_1 + 0xe) = uVar2;
        *(u8 *)((int)param_1 + 0xf) = uVar3;
        param_1 = param_1 + 4;
      }
    }
  }
  else {
    iVar42 = 0;
    if (0 < param_2) {
      if (8 < param_2) {
        bVar5 = 0;
        if ((-1 < param_2) && (param_2 < 0x7fffffff)) {
          bVar5 = 1;
        }
        if (bVar5) {
          do {
            puVar11 = (u32 *)((int)param_1 + iVar17 + iVar17);
            puVar40 = (u32 *)((int)puVar38 + iVar8);
            puVar6 = (u32 *)((int)puVar11 + iVar17);
            puVar21 = (u32 *)((int)puVar40 + iVar8);
            puVar41 = (u32 *)((int)puVar6 + iVar17);
            puVar18 = (u32 *)((int)puVar21 + iVar8);
            puVar39 = (u32 *)((int)puVar41 + iVar17);
            puVar15 = (u32 *)((int)puVar18 + iVar8);
            puVar44 = (u32 *)((int)puVar39 + iVar17);
            puVar13 = (u32 *)((int)puVar15 + iVar8);
            puVar43 = (u32 *)((int)puVar44 + iVar17);
            *param_1 = *puVar38;
            puVar22 = (u32 *)((int)puVar43 + iVar17);
            puVar20 = (u32 *)((int)puVar22 + iVar17);
            puVar10 = (u32 *)((int)puVar13 + iVar8);
            puVar19 = (u32 *)((int)puVar20 + iVar17);
            iVar42 = iVar42 + 8;
            puVar23 = (u32 *)((int)puVar19 + iVar17);
            puVar9 = (u32 *)((int)puVar10 + iVar8);
            puVar24 = (u32 *)((int)puVar23 + iVar17);
            *(u32 *)((int)param_1 + iVar17) = *puVar38;
            *puVar11 = *puVar38;
            puVar25 = (u32 *)((int)puVar24 + iVar17);
            puVar16 = (u32 *)((int)puVar25 + iVar17);
            puVar26 = (u32 *)((int)puVar16 + iVar17);
            puVar27 = (u32 *)((int)puVar26 + iVar17);
            puVar28 = (u32 *)((int)puVar27 + iVar17);
            puVar29 = (u32 *)((int)puVar28 + iVar17);
            puVar30 = (u32 *)((int)puVar29 + iVar17);
            puVar31 = (u32 *)((int)puVar30 + iVar17);
            puVar12 = (u32 *)((int)puVar31 + iVar17);
            puVar32 = (u32 *)((int)puVar12 + iVar17);
            *puVar6 = *puVar38;
            puVar33 = (u32 *)((int)puVar32 + iVar17);
            puVar34 = (u32 *)((int)puVar33 + iVar17);
            puVar35 = (u32 *)((int)puVar34 + iVar17);
            puVar36 = (u32 *)((int)puVar35 + iVar17);
            puVar37 = (u32 *)((int)puVar36 + iVar17);
            puVar45 = (u32 *)((int)puVar37 + iVar17);
            puVar38 = (u32 *)((int)puVar9 + iVar8);
            puVar6 = (u32 *)((int)puVar45 + iVar17);
            puVar11 = (u32 *)((int)puVar6 + iVar17);
            puVar7 = (u32 *)((int)puVar11 + iVar17);
            param_1 = (u32 *)((int)puVar7 + iVar17);
            *puVar41 = *puVar40;
            *puVar39 = *puVar40;
            *puVar44 = *puVar40;
            *puVar43 = *puVar40;
            *puVar22 = *puVar21;
            *puVar20 = *puVar21;
            *puVar19 = *puVar21;
            *puVar23 = *puVar21;
            *puVar24 = *puVar18;
            *puVar25 = *puVar18;
            *puVar16 = *puVar18;
            *puVar26 = *puVar18;
            *puVar27 = *puVar15;
            *puVar28 = *puVar15;
            *puVar29 = *puVar15;
            *puVar30 = *puVar15;
            *puVar31 = *puVar13;
            *puVar12 = *puVar13;
            *puVar32 = *puVar13;
            *puVar33 = *puVar13;
            *puVar34 = *puVar10;
            *puVar35 = *puVar10;
            *puVar36 = *puVar10;
            *puVar37 = *puVar10;
            *puVar45 = *puVar9;
            *puVar6 = *puVar9;
            *puVar11 = *puVar9;
            *puVar7 = *puVar9;
          } while (iVar42 < param_2 + -8);
        }
      }
      for (; iVar42 < param_2; iVar42 = iVar42 + 1) {
        puVar7 = (u32 *)((int)param_1 + iVar17);
        puVar11 = (u32 *)((int)puVar7 + iVar17);
        puVar6 = (u32 *)((int)puVar11 + iVar17);
        *param_1 = *puVar38;
        param_1 = (u32 *)((int)puVar6 + iVar17);
        *puVar7 = *puVar38;
        *puVar11 = *puVar38;
        *puVar6 = *puVar38;
        puVar38 = (u32 *)((int)puVar38 + iVar8);
      }
    }
  }
  return;
}

// FUN_00485070 NONMATCHING

void FUN_00485070(u32 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  u32 *puVar3;
  u32 *puVar4;
  u32 *puVar5;
  u32 *puVar6;
  int iVar7;
  
  iVar1 = param_1[1];
  iVar2 = *(int *)(param_3 + 0x30);
  param_1 = (u32 *)*param_1;
  if (iVar2 == iVar1 << 2) {
    ((code)FUN_00476c20)(param_1,*(u32 **)(param_3 + 0x2c),param_2 * iVar1 * 4);
  }
  else {
    iVar7 = 0;
    puVar6 = *(u32 **)(param_3 + 0x2c);
    if (0 < param_2) {
      do {
        puVar5 = (u32 *)((int)param_1 + iVar1);
        puVar4 = (u32 *)((int)puVar5 + iVar1);
        iVar7 = iVar7 + 1;
        puVar3 = (u32 *)((int)puVar4 + iVar1);
        *param_1 = *puVar6;
        param_1 = (u32 *)((int)puVar3 + iVar1);
        *puVar5 = puVar6[1];
        *puVar4 = puVar6[2];
        *puVar3 = puVar6[3];
        puVar6 = (u32 *)((int)puVar6 + iVar2);
      } while (iVar7 < param_2);
    }
  }
  return;
}

// FUN_00485110 NONMATCHING

void FUN_00485110(u32 *param_1,int param_2,int param_3)

{
  int iVar1;
  u8 bVar2;
  u32 *puVar3;
  u32 *puVar4;
  u32 *puVar5;
  u32 *puVar6;
  u32 *puVar7;
  u32 *puVar8;
  u32 *puVar9;
  u32 *puVar10;
  u32 *puVar11;
  u32 *puVar12;
  u32 *puVar13;
  u32 *puVar14;
  u32 *puVar15;
  u32 *puVar16;
  u32 *puVar17;
  u32 *puVar18;
  u32 *puVar19;
  u32 *puVar20;
  u32 *puVar21;
  u32 *puVar22;
  u32 *puVar23;
  u32 *puVar24;
  u32 *puVar25;
  u32 *puVar26;
  u32 *puVar27;
  int iVar28;
  u32 *puVar29;
  u32 *puVar30;
  u32 *puVar31;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  puVar10 = (u32 *)*param_1;
  iVar1 = param_1[1];
  if (iVar1 == 4) {
    uStack_10 = *(u32 *)(param_3 + 0x80);
    uStack_c = *(u32 *)(param_3 + 0x84);
    uStack_8 = *(u32 *)(param_3 + 0x88);
    uStack_4 = *(u32 *)(param_3 + 0x8c);
    ((code)FUN_00476720)(puVar10,param_2 << 4,&uStack_10);
  }
  else {
    iVar28 = 0;
    if (0 < param_2) {
      if (8 < param_2) {
        bVar2 = 0;
        if ((-1 < param_2) && (param_2 < 0x7fffffff)) {
          bVar2 = 1;
        }
        if (bVar2) {
          do {
            puVar12 = (u32 *)((int)puVar10 + iVar1 + iVar1);
            puVar11 = (u32 *)((int)puVar12 + iVar1);
            iVar28 = iVar28 + 8;
            puVar27 = (u32 *)((int)puVar11 + iVar1);
            puVar26 = (u32 *)((int)puVar27 + iVar1);
            puVar25 = (u32 *)((int)puVar26 + iVar1);
            *puVar10 = *(u32 *)(param_3 + 0x80);
            puVar24 = (u32 *)((int)puVar25 + iVar1);
            puVar23 = (u32 *)((int)puVar24 + iVar1);
            puVar22 = (u32 *)((int)puVar23 + iVar1);
            puVar30 = (u32 *)((int)puVar22 + iVar1);
            puVar29 = (u32 *)((int)puVar30 + iVar1);
            puVar21 = (u32 *)((int)puVar29 + iVar1);
            puVar20 = (u32 *)((int)puVar21 + iVar1);
            *(u32 *)((int)puVar10 + iVar1) = *(u32 *)(param_3 + 0x84);
            puVar19 = (u32 *)((int)puVar20 + iVar1);
            puVar18 = (u32 *)((int)puVar19 + iVar1);
            puVar17 = (u32 *)((int)puVar18 + iVar1);
            puVar16 = (u32 *)((int)puVar17 + iVar1);
            puVar15 = (u32 *)((int)puVar16 + iVar1);
            puVar14 = (u32 *)((int)puVar15 + iVar1);
            puVar3 = (u32 *)((int)puVar14 + iVar1);
            *puVar12 = *(u32 *)(param_3 + 0x88);
            puVar13 = (u32 *)((int)puVar3 + iVar1);
            puVar12 = (u32 *)((int)puVar13 + iVar1);
            puVar4 = (u32 *)((int)puVar12 + iVar1);
            puVar5 = (u32 *)((int)puVar4 + iVar1);
            puVar6 = (u32 *)((int)puVar5 + iVar1);
            *puVar11 = *(u32 *)(param_3 + 0x8c);
            puVar11 = (u32 *)((int)puVar6 + iVar1);
            puVar7 = (u32 *)((int)puVar11 + iVar1);
            puVar31 = (u32 *)((int)puVar7 + iVar1);
            puVar8 = (u32 *)((int)puVar31 + iVar1);
            puVar9 = (u32 *)((int)puVar8 + iVar1);
            puVar10 = (u32 *)((int)puVar9 + iVar1);
            *puVar27 = *(u32 *)(param_3 + 0x80);
            *puVar26 = *(u32 *)(param_3 + 0x84);
            *puVar25 = *(u32 *)(param_3 + 0x88);
            *puVar24 = *(u32 *)(param_3 + 0x8c);
            *puVar23 = *(u32 *)(param_3 + 0x80);
            *puVar22 = *(u32 *)(param_3 + 0x84);
            *puVar30 = *(u32 *)(param_3 + 0x88);
            *puVar29 = *(u32 *)(param_3 + 0x8c);
            *puVar21 = *(u32 *)(param_3 + 0x80);
            *puVar20 = *(u32 *)(param_3 + 0x84);
            *puVar19 = *(u32 *)(param_3 + 0x88);
            *puVar18 = *(u32 *)(param_3 + 0x8c);
            *puVar17 = *(u32 *)(param_3 + 0x80);
            *puVar16 = *(u32 *)(param_3 + 0x84);
            *puVar15 = *(u32 *)(param_3 + 0x88);
            *puVar14 = *(u32 *)(param_3 + 0x8c);
            *puVar3 = *(u32 *)(param_3 + 0x80);
            *puVar13 = *(u32 *)(param_3 + 0x84);
            *puVar12 = *(u32 *)(param_3 + 0x88);
            *puVar4 = *(u32 *)(param_3 + 0x8c);
            *puVar5 = *(u32 *)(param_3 + 0x80);
            *puVar6 = *(u32 *)(param_3 + 0x84);
            *puVar11 = *(u32 *)(param_3 + 0x88);
            *puVar7 = *(u32 *)(param_3 + 0x8c);
            *puVar31 = *(u32 *)(param_3 + 0x80);
            *puVar8 = *(u32 *)(param_3 + 0x84);
            *puVar9 = *(u32 *)(param_3 + 0x88);
            *puVar10 = *(u32 *)(param_3 + 0x8c);
            puVar10 = (u32 *)((int)puVar10 + iVar1);
          } while (iVar28 < param_2 + -8);
        }
      }
      for (; iVar28 < param_2; iVar28 = iVar28 + 1) {
        puVar4 = (u32 *)((int)puVar10 + iVar1);
        puVar12 = (u32 *)((int)puVar4 + iVar1);
        puVar3 = (u32 *)((int)puVar12 + iVar1);
        *puVar10 = *(u32 *)(param_3 + 0x80);
        puVar10 = (u32 *)((int)puVar3 + iVar1);
        *puVar4 = *(u32 *)(param_3 + 0x84);
        *puVar12 = *(u32 *)(param_3 + 0x88);
        *puVar3 = *(u32 *)(param_3 + 0x8c);
      }
    }
  }
  return;
}

// FUN_00485440 NONMATCHING

void FUN_00485440(u32 *param_1,int param_2,int param_3)

{
  int iVar1;
  u8 bVar2;
  u32 *puVar3;
  u32 *puVar4;
  u32 *puVar5;
  u32 *puVar6;
  u32 *puVar7;
  u32 *puVar8;
  u32 *puVar9;
  u32 *puVar10;
  u32 *puVar11;
  u32 *puVar12;
  u32 *puVar13;
  u32 *puVar14;
  u32 *puVar15;
  u32 *puVar16;
  u32 *puVar17;
  u32 *puVar18;
  u32 *puVar19;
  u32 *puVar20;
  u32 *puVar21;
  u32 *puVar22;
  u32 *puVar23;
  u32 *puVar24;
  u32 *puVar25;
  u32 *puVar26;
  u32 *puVar27;
  int iVar28;
  u32 *puVar29;
  u32 *puVar30;
  u32 *puVar31;
  
  puVar10 = (u32 *)*param_1;
  iVar1 = param_1[1];
  if (iVar1 == 4) {
    ((code)FUN_00476140)(puVar10,param_2 << 4,*(u32 *)(param_3 + 0x7c));
  }
  else {
    iVar28 = 0;
    if (0 < param_2) {
      if (8 < param_2) {
        bVar2 = 0;
        if ((-1 < param_2) && (param_2 < 0x7fffffff)) {
          bVar2 = 1;
        }
        if (bVar2) {
          do {
            puVar12 = (u32 *)((int)puVar10 + iVar1 + iVar1);
            puVar11 = (u32 *)((int)puVar12 + iVar1);
            iVar28 = iVar28 + 8;
            puVar27 = (u32 *)((int)puVar11 + iVar1);
            puVar26 = (u32 *)((int)puVar27 + iVar1);
            puVar25 = (u32 *)((int)puVar26 + iVar1);
            *puVar10 = *(u32 *)(param_3 + 0x7c);
            puVar24 = (u32 *)((int)puVar25 + iVar1);
            puVar23 = (u32 *)((int)puVar24 + iVar1);
            puVar22 = (u32 *)((int)puVar23 + iVar1);
            puVar30 = (u32 *)((int)puVar22 + iVar1);
            puVar29 = (u32 *)((int)puVar30 + iVar1);
            puVar21 = (u32 *)((int)puVar29 + iVar1);
            puVar20 = (u32 *)((int)puVar21 + iVar1);
            *(u32 *)((int)puVar10 + iVar1) = *(u32 *)(param_3 + 0x7c);
            puVar19 = (u32 *)((int)puVar20 + iVar1);
            puVar18 = (u32 *)((int)puVar19 + iVar1);
            puVar17 = (u32 *)((int)puVar18 + iVar1);
            puVar16 = (u32 *)((int)puVar17 + iVar1);
            puVar15 = (u32 *)((int)puVar16 + iVar1);
            puVar14 = (u32 *)((int)puVar15 + iVar1);
            puVar3 = (u32 *)((int)puVar14 + iVar1);
            *puVar12 = *(u32 *)(param_3 + 0x7c);
            puVar13 = (u32 *)((int)puVar3 + iVar1);
            puVar12 = (u32 *)((int)puVar13 + iVar1);
            puVar4 = (u32 *)((int)puVar12 + iVar1);
            puVar5 = (u32 *)((int)puVar4 + iVar1);
            puVar6 = (u32 *)((int)puVar5 + iVar1);
            *puVar11 = *(u32 *)(param_3 + 0x7c);
            puVar11 = (u32 *)((int)puVar6 + iVar1);
            puVar7 = (u32 *)((int)puVar11 + iVar1);
            puVar31 = (u32 *)((int)puVar7 + iVar1);
            puVar8 = (u32 *)((int)puVar31 + iVar1);
            puVar9 = (u32 *)((int)puVar8 + iVar1);
            puVar10 = (u32 *)((int)puVar9 + iVar1);
            *puVar27 = *(u32 *)(param_3 + 0x7c);
            *puVar26 = *(u32 *)(param_3 + 0x7c);
            *puVar25 = *(u32 *)(param_3 + 0x7c);
            *puVar24 = *(u32 *)(param_3 + 0x7c);
            *puVar23 = *(u32 *)(param_3 + 0x7c);
            *puVar22 = *(u32 *)(param_3 + 0x7c);
            *puVar30 = *(u32 *)(param_3 + 0x7c);
            *puVar29 = *(u32 *)(param_3 + 0x7c);
            *puVar21 = *(u32 *)(param_3 + 0x7c);
            *puVar20 = *(u32 *)(param_3 + 0x7c);
            *puVar19 = *(u32 *)(param_3 + 0x7c);
            *puVar18 = *(u32 *)(param_3 + 0x7c);
            *puVar17 = *(u32 *)(param_3 + 0x7c);
            *puVar16 = *(u32 *)(param_3 + 0x7c);
            *puVar15 = *(u32 *)(param_3 + 0x7c);
            *puVar14 = *(u32 *)(param_3 + 0x7c);
            *puVar3 = *(u32 *)(param_3 + 0x7c);
            *puVar13 = *(u32 *)(param_3 + 0x7c);
            *puVar12 = *(u32 *)(param_3 + 0x7c);
            *puVar4 = *(u32 *)(param_3 + 0x7c);
            *puVar5 = *(u32 *)(param_3 + 0x7c);
            *puVar6 = *(u32 *)(param_3 + 0x7c);
            *puVar11 = *(u32 *)(param_3 + 0x7c);
            *puVar7 = *(u32 *)(param_3 + 0x7c);
            *puVar31 = *(u32 *)(param_3 + 0x7c);
            *puVar8 = *(u32 *)(param_3 + 0x7c);
            *puVar9 = *(u32 *)(param_3 + 0x7c);
            *puVar10 = *(u32 *)(param_3 + 0x7c);
            puVar10 = (u32 *)((int)puVar10 + iVar1);
          } while (iVar28 < param_2 + -8);
        }
      }
      for (; iVar28 < param_2; iVar28 = iVar28 + 1) {
        puVar4 = (u32 *)((int)puVar10 + iVar1);
        puVar12 = (u32 *)((int)puVar4 + iVar1);
        puVar3 = (u32 *)((int)puVar12 + iVar1);
        *puVar10 = *(u32 *)(param_3 + 0x7c);
        puVar10 = (u32 *)((int)puVar3 + iVar1);
        *puVar4 = *(u32 *)(param_3 + 0x7c);
        *puVar12 = *(u32 *)(param_3 + 0x7c);
        *puVar3 = *(u32 *)(param_3 + 0x7c);
      }
    }
  }
  return;
}

// FUN_00485750 NONMATCHING

void FUN_00485750(int *param_1,int param_2,int param_3)

{
  int iVar1;
  char cVar2;
  u32 uVar3;
  u32 *puVar4;
  u32 *puVar5;
  u32 *puVar6;
  int iVar7;
  u32 *puVar8;
  u32 *puVar9;
  int iVar10;
  
  iVar10 = param_1[1];
  iVar1 = *(int *)(param_3 + 0x40);
  puVar9 = (u32 *)*param_1;
  puVar8 = *(u32 **)(param_3 + 0x3c);
  if (iVar1 == iVar10 << 1) {
    FlushCache(0);
    uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
    if ((uVar3 & 0x100) != 0) {
      REG_DMAC_PCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar2 = getCopCondition(0,0);
      } while (cVar2 == '\0');
    }
    uVar3 = REG_DMAC_9_SPR_TO_CHCR;
    if ((uVar3 & 0x100) != 0) {
      REG_DMAC_PCR = 0x200;
      SYNC(0);
      SYNC(0x10);
      do {
        cVar2 = getCopCondition(0,0);
      } while (cVar2 == '\0');
      do {
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      } while ((uVar3 & 0x100) != 0);
    }
    if (0x155 < param_2) {
      do {
        uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
        }
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
          do {
            uVar3 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar3 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x200;
        REG_DMAC_9_SPR_TO_SADR = 0;
        REG_DMAC_9_SPR_TO_MADR = (u32)(puVar8);
        REG_DMAC_9_SPR_TO_QWC = 0x155;
        REG_DMAC_9_SPR_TO_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
          do {
            uVar3 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar3 & 0x100) != 0);
        }
        iVar10 = 0;
        puVar4 = (u32 *)((u8 *)DAT_70000000);
        puVar5 = (u32 *)((u8 *)DAT_70001550);
        do {
          iVar10 = iVar10 + 1;
          *puVar5 = *puVar4;
          puVar5[1] = puVar4[3];
          puVar5[2] = puVar4[2];
          puVar5[3] = puVar4[3];
          puVar5[4] = puVar4[2];
          puVar5[5] = puVar4[1];
          puVar5[6] = *puVar4;
          puVar5[7] = puVar4[1];
          puVar5 = puVar5 + 8;
          puVar4 = puVar4 + 4;
        } while (iVar10 < 0x155);
        uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x100;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
        }
        uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        if ((uVar3 & 0x100) != 0) {
          REG_DMAC_PCR = 0x200;
          SYNC(0);
          SYNC(0x10);
          do {
            cVar2 = getCopCondition(0,0);
          } while (cVar2 == '\0');
          do {
            uVar3 = REG_DMAC_9_SPR_TO_CHCR;
          } while ((uVar3 & 0x100) != 0);
        }
        REG_DMAC_STAT = 0x100;
        REG_DMAC_8_SPR_FROM_SADR = 0x1550;
        REG_DMAC_8_SPR_FROM_MADR = (u32)(puVar9);
        REG_DMAC_8_SPR_FROM_QWC = 0x2aa;
        REG_DMAC_8_SPR_FROM_CHCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        param_2 = param_2 + -0x155;
        puVar8 = puVar8 + 0x554;
        puVar9 = puVar9 + 0xaa8;
      } while (0x155 < param_2);
    }
    if (param_2 != 0) {
      uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
      }
      uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
        do {
          uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar3 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x200;
      REG_DMAC_9_SPR_TO_SADR = 0;
      REG_DMAC_9_SPR_TO_MADR = (u32)(puVar8);
      REG_DMAC_9_SPR_TO_QWC = param_2;
      REG_DMAC_9_SPR_TO_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
      uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
        do {
          uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar3 & 0x100) != 0);
      }
      iVar10 = 0;
      puVar4 = (u32 *)((u8 *)DAT_70001550);
      puVar8 = (u32 *)((u8 *)DAT_70000000);
      if (0 < param_2) {
        do {
          iVar10 = iVar10 + 1;
          *puVar4 = *puVar8;
          puVar4[1] = puVar8[3];
          puVar4[2] = puVar8[2];
          puVar4[3] = puVar8[3];
          puVar4[4] = puVar8[2];
          puVar4[5] = puVar8[1];
          puVar4[6] = *puVar8;
          puVar4[7] = puVar8[1];
          puVar4 = puVar4 + 8;
          puVar8 = puVar8 + 4;
        } while (iVar10 < param_2);
      }
      uVar3 = REG_DMAC_8_SPR_FROM_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x100;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
      }
      uVar3 = REG_DMAC_9_SPR_TO_CHCR;
      if ((uVar3 & 0x100) != 0) {
        REG_DMAC_PCR = 0x200;
        SYNC(0);
        SYNC(0x10);
        do {
          cVar2 = getCopCondition(0,0);
        } while (cVar2 == '\0');
        do {
          uVar3 = REG_DMAC_9_SPR_TO_CHCR;
        } while ((uVar3 & 0x100) != 0);
      }
      REG_DMAC_STAT = 0x100;
      REG_DMAC_8_SPR_FROM_SADR = 0x1550;
      REG_DMAC_8_SPR_FROM_MADR = (u32)(puVar9);
      REG_DMAC_8_SPR_FROM_QWC = param_2 << 1;
      REG_DMAC_8_SPR_FROM_CHCR = 0x100;
      SYNC(0);
      SYNC(0x10);
    }
  }
  else {
    iVar7 = 0;
    if (0 < param_2) {
      do {
        puVar6 = (u32 *)((int)puVar9 + iVar10);
        puVar5 = (u32 *)((int)puVar6 + iVar10);
        iVar7 = iVar7 + 1;
        puVar4 = (u32 *)((int)puVar5 + iVar10);
        *puVar9 = *puVar8;
        puVar9[1] = puVar8[3];
        puVar9 = (u32 *)((int)puVar4 + iVar10);
        *puVar6 = puVar8[2];
        puVar6[1] = puVar8[3];
        *puVar5 = puVar8[2];
        puVar5[1] = puVar8[1];
        *puVar4 = *puVar8;
        puVar4[1] = puVar8[1];
        puVar8 = (u32 *)((int)puVar8 + iVar1);
      } while (iVar7 < param_2);
    }
  }
  return;
}

// FUN_00485E20 NONMATCHING

void FUN_00485e20(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  u32 *puVar3;
  u32 *puVar4;
  u32 *puVar5;
  u32 *puVar6;
  u32 *puVar7;
  int iVar8;
  
  iVar1 = param_1[1];
  iVar2 = *(int *)(param_3 + 0x48);
  puVar7 = (u32 *)*param_1;
  if (iVar2 == iVar1 << 2) {
    ((code)FUN_00476c20)(puVar7,*(u32 **)(param_3 + 0x44),param_2 * iVar1 * 4);
  }
  else {
    iVar8 = 0;
    puVar6 = *(u32 **)(param_3 + 0x44);
    if (0 < param_2) {
      do {
        puVar5 = (u32 *)((int)puVar7 + iVar1);
        puVar4 = (u32 *)((int)puVar5 + iVar1);
        iVar8 = iVar8 + 1;
        puVar3 = (u32 *)((int)puVar4 + iVar1);
        *puVar7 = *puVar6;
        puVar7[1] = puVar6[1];
        puVar7 = (u32 *)((int)puVar3 + iVar1);
        *puVar5 = puVar6[2];
        puVar5[1] = puVar6[3];
        *puVar4 = puVar6[4];
        puVar4[1] = puVar6[5];
        *puVar3 = puVar6[6];
        puVar3[1] = puVar6[7];
        puVar6 = (u32 *)((int)puVar6 + iVar2);
      } while (iVar8 < param_2);
    }
  }
  return;
}

// FUN_00485EF0 NONMATCHING

void FUN_00485ef0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  u32 *puVar2;
  u32 *puVar3;
  u32 *puVar4;
  u32 *puVar5;
  int iVar6;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar1 = param_1[1];
  if (iVar1 == 0x10) {
    uStack_20 = *(u32 *)(param_3 + 0x90);
    uStack_1c = *(u32 *)(param_3 + 0x9c);
    uStack_18 = *(u32 *)(param_3 + 0x98);
    uStack_14 = *(u32 *)(param_3 + 0x9c);
    uStack_10 = *(u32 *)(param_3 + 0x98);
    uStack_c = *(u32 *)(param_3 + 0x94);
    uStack_8 = *(u32 *)(param_3 + 0x90);
    uStack_4 = *(u32 *)(param_3 + 0x94);
    ((code)FUN_00476980)(*param_1,param_1[1] * param_2 * 4,&uStack_20);
  }
  else {
    puVar5 = (u32 *)*param_1;
    iVar6 = 0;
    if (0 < param_2) {
      do {
        puVar4 = (u32 *)((int)puVar5 + iVar1);
        puVar3 = (u32 *)((int)puVar4 + iVar1);
        iVar6 = iVar6 + 1;
        puVar2 = (u32 *)((int)puVar3 + iVar1);
        *puVar5 = *(u32 *)(param_3 + 0x90);
        puVar5[1] = *(u32 *)(param_3 + 0x9c);
        puVar5 = (u32 *)((int)puVar2 + iVar1);
        *puVar4 = *(u32 *)(param_3 + 0x98);
        puVar4[1] = *(u32 *)(param_3 + 0x9c);
        *puVar3 = *(u32 *)(param_3 + 0x98);
        puVar3[1] = *(u32 *)(param_3 + 0x94);
        *puVar2 = *(u32 *)(param_3 + 0x90);
        puVar2[1] = *(u32 *)(param_3 + 0x94);
      } while (iVar6 < param_2);
    }
  }
  return;
}

// FUN_00485FF0 NONMATCHING

void FUN_00485ff0(int *param_1,int param_2,int param_3)

{
  int iVar1;
  u32 *puVar2;
  u32 *puVar3;
  u32 *puVar4;
  u32 *puVar5;
  int iVar6;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar1 = param_1[1];
  if (iVar1 == 8) {
    uStack_20 = *(u32 *)(param_3 + 0x90);
    uStack_1c = *(u32 *)(param_3 + 0x94);
    uStack_18 = *(u32 *)(param_3 + 0x98);
    uStack_14 = *(u32 *)(param_3 + 0x9c);
    uStack_10 = *(u32 *)(param_3 + 0xa0);
    uStack_c = *(u32 *)(param_3 + 0xa4);
    uStack_8 = *(u32 *)(param_3 + 0xa8);
    uStack_4 = *(u32 *)(param_3 + 0xac);
    ((code)FUN_00476980)(*param_1,param_1[1] * param_2 * 4,&uStack_20);
  }
  else {
    puVar5 = (u32 *)*param_1;
    iVar6 = 0;
    if (0 < param_2) {
      do {
        puVar4 = (u32 *)((int)puVar5 + iVar1);
        puVar3 = (u32 *)((int)puVar4 + iVar1);
        iVar6 = iVar6 + 1;
        puVar2 = (u32 *)((int)puVar3 + iVar1);
        *puVar5 = *(u32 *)(param_3 + 0x90);
        puVar5[1] = *(u32 *)(param_3 + 0x94);
        puVar5 = (u32 *)((int)puVar2 + iVar1);
        *puVar4 = *(u32 *)(param_3 + 0x98);
        puVar4[1] = *(u32 *)(param_3 + 0x9c);
        *puVar3 = *(u32 *)(param_3 + 0xa0);
        puVar3[1] = *(u32 *)(param_3 + 0xa4);
        *puVar2 = *(u32 *)(param_3 + 0xa8);
        puVar2[1] = *(u32 *)(param_3 + 0xac);
      } while (iVar6 < param_2);
    }
  }
  return;
}

// FUN_004861B0 NONMATCHING

u32 FUN_004861b0(u64 param_1,u64 param_2,u32 param_3,u32 param_4)

{
  int iVar1;
  code *pcVar2;
  Vec128 auStack_50;
  int aiStack_40 [2];
  int aiStack_38 [2];
  int aiStack_30 [2];
  int aiStack_28 [2];
  u8 auStack_20 [12];
  u8 auStack_14 [20];
  
  if ((param_4 & 0x1e8000) != 0) {
    param_3 = **(u32 **)((int)param_1 + DAT_007ce770);
  }
  iVar1 = *(int *)((int)param_1 + DAT_007ce770);
  if (*(int *)(iVar1 + 0x24) == 0) {
    pcVar2 = *(code **)(iVar1 + 0x28);
  }
  else {
    ((code)FUN_00521408)(auStack_50,0,0x48);
    (**(code **)(iVar1 + 0x24))(auStack_50,param_1,param_2,param_3,param_4);
    pcVar2 = *(code **)(iVar1 + 0x28);
  }
  if ((pcVar2 != (code *)0x0) && (aiStack_40[0] != 0)) {
    (*pcVar2)(aiStack_40,auStack_20,auStack_14,param_3,param_2);
  }
  if ((*(code **)(iVar1 + 0x2c) != (code *)0x0) && (aiStack_38[0] != 0)) {
    (**(code **)(iVar1 + 0x2c))(aiStack_38,param_3,param_2);
  }
  if ((*(code **)(iVar1 + 0x30) != (code *)0x0) && (aiStack_30[0] != 0)) {
    (**(code **)(iVar1 + 0x30))(aiStack_30,param_3,param_2);
  }
  if ((*(code **)(iVar1 + 0x34) != (code *)0x0) && (aiStack_28[0] != 0)) {
    (**(code **)(iVar1 + 0x34))(aiStack_28,param_3,param_2);
  }
  if (*(code **)(iVar1 + 0x38) != (code *)0x0) {
    (**(code **)(iVar1 + 0x38))(auStack_50,param_1,param_2,param_3,param_4);
  }
  return 1;
}

// FUN_00486340 NONMATCHING

u32 FUN_00486340(u32 param_1,int param_2,u32 param_3)

{
  int iVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  u64 uVar5;
  u32 uVar6;
  u8 *puVar7;
  u32 *puVar8;
  int iVar9;
  int iVar10;
  u32 *puVar11;
  u32 *puVar12;
  short sVar13;
  short sVar14;
  int iVar15;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  if ((param_3 & 0x10) == 0x10) {
    uVar6 = 0x76;
  }
  else {
    uVar6 = 0xe;
  }
  if ((param_3 & 0x40042) != 0) {
    uVar6 = uVar6 | 8;
  }
  uVar5 = ((code)FUN_00493710)(param_2 << 2,param_2 << 1,uVar6);
  iVar4 = ((code)FUN_00494be0)();
  iVar15 = 0;
  *(u32 *)(iVar4 + 0xc) = 0x3e99999a;
  *(u32 *)(iVar4 + 0x10) = 0x3f800000;
  *(u32 *)(iVar4 + 0x14) = 0x3f800000;
  iVar10 = (int)uVar5;
  iVar1 = *(int *)(iVar10 + 0x5c);
  puVar8 = *(u32 **)(iVar10 + 0x34);
  puVar7 = *(u8 **)(iVar10 + 0x30);
  iVar10 = *(int *)(iVar10 + 0x2c);
  uStack_10 = 0x3e99999a;
  uStack_8 = 0x3f800000;
  puVar12 = *(u32 **)(iVar1 + 0x14);
  puVar11 = *(u32 **)(iVar1 + 0x18);
  uStack_c = 0x3f800000;
  if (0 < param_2) {
    sVar13 = 0;
    sVar2 = 1;
    sVar14 = 2;
    sVar3 = 3;
    do {
      *puVar12 = 0;
      puVar12[1] = 0;
      puVar12[2] = 0;
      *puVar8 = 0;
      puVar8[1] = 0;
      if (puVar7 != (u8 *)0x0) {
        *puVar7 = 0;
        puVar7[1] = 0;
        puVar7[2] = 0;
        puVar7[3] = 0xff;
        puVar7 = puVar7 + 4;
      }
      if (puVar11 != (u32 *)0x0) {
        *puVar11 = 0x3f800000;
        puVar11[1] = 0;
        puVar11[2] = 0;
        puVar11 = puVar11 + 3;
      }
      puVar12[3] = 0;
      puVar12[4] = 0;
      puVar12[5] = 0;
      puVar8[2] = 0;
      puVar8[3] = 0x3f800000;
      if (puVar7 != (u8 *)0x0) {
        *puVar7 = 0;
        puVar7[1] = 0;
        puVar7[2] = 0;
        puVar7[3] = 0xff;
        puVar7 = puVar7 + 4;
      }
      if (puVar11 != (u32 *)0x0) {
        *puVar11 = 0x3f800000;
        puVar11[1] = 0;
        puVar11[2] = 0;
        puVar11 = puVar11 + 3;
      }
      puVar12[6] = 0;
      puVar12[7] = 0;
      puVar12[8] = 0;
      puVar8[4] = 0x3f800000;
      puVar8[5] = 0x3f800000;
      if (puVar7 != (u8 *)0x0) {
        *puVar7 = 0;
        puVar7[1] = 0;
        puVar7[2] = 0;
        puVar7[3] = 0xff;
        puVar7 = puVar7 + 4;
      }
      if (puVar11 != (u32 *)0x0) {
        *puVar11 = 0x3f800000;
        puVar11[1] = 0;
        puVar11[2] = 0;
        puVar11 = puVar11 + 3;
      }
      puVar12[9] = 0;
      puVar12[10] = 0;
      puVar12[0xb] = 0;
      puVar8[6] = 0x3f800000;
      puVar12 = puVar12 + 0xc;
      puVar8[7] = 0;
      puVar8 = puVar8 + 8;
      if (puVar7 != (u8 *)0x0) {
        *puVar7 = 0;
        puVar7[1] = 0;
        puVar7[2] = 0;
        puVar7[3] = 0xff;
        puVar7 = puVar7 + 4;
      }
      if (puVar11 != (u32 *)0x0) {
        *puVar11 = 0x3f800000;
        puVar11[1] = 0;
        puVar11[2] = 0;
        puVar11 = puVar11 + 3;
      }
      ((code)FUN_00493210)(uVar5,iVar10,sVar14,sVar2,sVar13);
      iVar9 = iVar10 + 8;
      ((code)FUN_00493230)(uVar5,iVar10,iVar4);
      ((code)FUN_00493210)(uVar5,iVar9,sVar3,sVar14,sVar13);
      iVar10 = iVar10 + 0x10;
      ((code)FUN_00493230)(uVar5,iVar9,iVar4);
      iVar15 = iVar15 + 1;
      sVar13 = sVar13 + 4;
      sVar2 = sVar2 + 4;
      sVar3 = sVar3 + 4;
      sVar14 = sVar14 + 4;
    } while (iVar15 < param_2);
  }
  ((code)FUN_00492e20)(iVar1,&uStack_20);
  uStack_14 = 0x3f800000;
  *(u32 *)(iVar1 + 4) = uStack_20;
  *(u32 *)(iVar1 + 8) = uStack_1c;
  *(u32 *)(iVar1 + 0xc) = uStack_18;
  *(u32 *)(iVar1 + 0x10) = 0x3f800000;
  ((code)FUN_004933d0)(uVar5);
  ((code)FUN_004919b0)(param_1,uVar5,0);
  ((code)FUN_00493b60)(uVar5);
  ((code)FUN_00494cc0)(iVar4);
  ((code)FUN_004866c0)(param_1);
  return 1;
}

// FUN_004866C0 NONMATCHING

void FUN_004866c0(int param_1)

{
  int iVar1;
  u32 uVar2;
  
  iVar1 = *(int *)(param_1 + DAT_007ce770);
  **(code **)(iVar1 + 0x24) = (code)FUN_00488550;
  uVar2 = *(u32 *)(iVar1 + 0xa8);
  if ((uVar2 & 8) == 8) {
    if ((uVar2 & 0x1000000) == 0x1000000) {
      *(u8 **)(iVar1 + 0x28) = &LAB_00487ac0;
    }
    else {
      *(u8 **)(iVar1 + 0x28) = &LAB_00487990;
    }
  }
  else if ((uVar2 & 0x8000) == 0x8000) {
    if ((uVar2 & 0x1000000) == 0x1000000) {
      *(u8 **)(iVar1 + 0x28) = &LAB_00486ae0;
    }
    else {
      *(u8 **)(iVar1 + 0x28) = &LAB_00486980;
    }
  }
  else if ((uVar2 & 0x20) == 0x20) {
    if ((uVar2 & 4) == 4) {
      if ((uVar2 & 0x1000000) == 0x1000000) {
        **(code **)(iVar1 + 0x28) = (code)FUN_004876f0;
      }
      else {
        **(code **)(iVar1 + 0x28) = (code)FUN_00487030;
      }
    }
    else if ((uVar2 & 0x1000000) == 0x1000000) {
      **(code **)(iVar1 + 0x28) = (code)FUN_00487280;
    }
    else {
      **(code **)(iVar1 + 0x28) = (code)FUN_00486c80;
    }
  }
  else if ((uVar2 & 4) == 4) {
    if ((uVar2 & 0x1000000) == 0x1000000) {
      *(u8 **)(iVar1 + 0x28) = &LAB_00487520;
    }
    else {
      *(u8 **)(iVar1 + 0x28) = &LAB_00486ec0;
    }
  }
  else if ((uVar2 & 0x1000000) == 0x1000000) {
    *(u8 **)(iVar1 + 0x28) = &LAB_00486ae0;
  }
  else {
    *(u8 **)(iVar1 + 0x28) = &LAB_00486980;
  }
  uVar2 = *(u32 *)(iVar1 + 0xa8);
  if ((uVar2 & 0x80) == 0x80) {
    *(u8 **)(iVar1 + 0x2c) = &LAB_00488260;
  }
  else if ((uVar2 & 0x100) == 0x100) {
    *(u8 **)(iVar1 + 0x2c) = &LAB_004882f0;
  }
  else if ((uVar2 & 0x80000) == 0x80000) {
    *(u8 **)(iVar1 + 0x2c) = &LAB_00488390;
  }
  else if ((uVar2 & 0x100000) == 0x100000) {
    *(u8 **)(iVar1 + 0x2c) = &LAB_00488410;
  }
  else {
    *(u32 *)(iVar1 + 0x2c) = 0;
  }
  uVar2 = *(u32 *)(iVar1 + 0xa8);
  if ((uVar2 & 2) == 2) {
    **(code **)(iVar1 + 0x30) = (code)FUN_00487bf0;
  }
  else if ((uVar2 & 0x40) == 0x40) {
    *(u8 **)(iVar1 + 0x30) = &LAB_00487e80;
  }
  else if ((uVar2 & 0x40000) == 0x40000) {
    *(u8 **)(iVar1 + 0x30) = &LAB_00487ef0;
  }
  else {
    *(u8 **)(iVar1 + 0x30) = &LAB_004880b0;
  }
  if ((*(u32 *)(iVar1 + 0xa8) & 0x10) == 0x10) {
    *(u8 **)(iVar1 + 0x34) = &LAB_004884a0;
  }
  else {
    *(u32 *)(iVar1 + 0x34) = 0;
  }
  *(u8 **)(iVar1 + 0x38) = &LAB_00488b80;
  return;
}

// FUN_00486C80 NONMATCHING

void FUN_00486c80(int *param_1,float *param_2,float *param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  u32 *puVar8;
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
  
  iVar10 = 0;
  iVar1 = *(int *)(param_5 + 0x38);
  pfVar9 = *(float **)(param_5 + 4);
  iVar2 = *(int *)(param_5 + 8);
  puVar8 = *(u32 **)(param_5 + 0x34);
  pfVar7 = (float *)*param_1;
  iVar3 = param_1[1];
  fVar20 = *(float *)(param_5 + 0x70) * 0.5;
  fVar19 = *(float *)(param_5 + 0x74) * 0.5;
  if (0 < param_4) {
    do {
      fVar11 = (float)((code)FUN_0052e878)(*puVar8);
      fVar12 = (float)((code)FUN_0052e6d8)(*puVar8);
      pfVar6 = (float *)((int)pfVar7 + iVar3);
      pfVar5 = (float *)((int)pfVar6 + iVar3);
      fVar13 = -fVar11;
      pfVar4 = (float *)((int)pfVar5 + iVar3);
      iVar10 = iVar10 + 1;
      fVar16 = (fVar12 * *param_2 + fVar13 * *param_3) * fVar20;
      puVar8 = (u32 *)((int)puVar8 + iVar1);
      fVar18 = (fVar12 * param_2[1] + fVar13 * param_3[1]) * fVar20;
      fVar15 = (fVar11 * param_2[1] + fVar12 * param_3[1]) * fVar19;
      fVar14 = (fVar11 * *param_2 + fVar12 * *param_3) * fVar19;
      fVar17 = (fVar11 * param_2[2] + fVar12 * param_3[2]) * fVar19;
      fVar11 = (fVar12 * param_2[2] + fVar13 * param_3[2]) * fVar20;
      *pfVar7 = *pfVar9 + (-fVar16 - fVar14);
      pfVar7[1] = pfVar9[1] + (-fVar18 - fVar15);
      pfVar7[2] = pfVar9[2] + (-fVar11 - fVar17);
      pfVar7 = (float *)((int)pfVar4 + iVar3);
      *pfVar6 = *pfVar9 + (fVar16 - fVar14);
      pfVar6[1] = pfVar9[1] + (fVar18 - fVar15);
      pfVar6[2] = pfVar9[2] + (fVar11 - fVar17);
      *pfVar5 = *pfVar9 + fVar16 + fVar14;
      pfVar5[1] = pfVar9[1] + fVar18 + fVar15;
      pfVar5[2] = pfVar9[2] + fVar11 + fVar17;
      *pfVar4 = *pfVar9 + -fVar16 + fVar14;
      pfVar4[1] = pfVar9[1] + -fVar18 + fVar15;
      pfVar5 = pfVar9 + 2;
      pfVar9 = (float *)((int)pfVar9 + iVar2);
      pfVar4[2] = *pfVar5 + -fVar11 + fVar17;
    } while (iVar10 < param_4);
  }
  return;
}

// FUN_00487030 NONMATCHING

void FUN_00487030(int *param_1,float *param_2,float *param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  float *pfVar9;
  float *pfVar10;
  u32 *puVar11;
  int iVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  
  iVar12 = 0;
  iVar1 = *(int *)(param_5 + 8);
  pfVar8 = *(float **)(param_5 + 4);
  puVar11 = *(u32 **)(param_5 + 0x34);
  pfVar10 = *(float **)(param_5 + 0x1c);
  pfVar9 = (float *)*param_1;
  iVar2 = param_1[1];
  iVar3 = *(int *)(param_5 + 0x38);
  iVar4 = *(int *)(param_5 + 0x20);
  if (0 < param_4) {
    do {
      fVar14 = (float)((code)FUN_0052e878)(*puVar11);
      fVar15 = (float)((code)FUN_0052e6d8)(*puVar11);
      pfVar7 = (float *)((int)pfVar9 + iVar2);
      pfVar6 = (float *)((int)pfVar7 + iVar2);
      iVar12 = iVar12 + 1;
      pfVar5 = (float *)((int)pfVar6 + iVar2);
      fVar13 = -fVar14;
      puVar11 = (u32 *)((int)puVar11 + iVar3);
      fVar16 = *pfVar10 * 0.5;
      fVar19 = (fVar15 * *param_2 + fVar13 * *param_3) * fVar16;
      fVar20 = (fVar15 * param_2[1] + fVar13 * param_3[1]) * fVar16;
      fVar16 = (fVar15 * param_2[2] + fVar13 * param_3[2]) * fVar16;
      fVar13 = pfVar10[1] * 0.5;
      pfVar10 = (float *)((int)pfVar10 + iVar4);
      fVar17 = (fVar14 * *param_2 + fVar15 * *param_3) * fVar13;
      fVar18 = (fVar14 * param_2[1] + fVar15 * param_3[1]) * fVar13;
      fVar13 = (fVar14 * param_2[2] + fVar15 * param_3[2]) * fVar13;
      *pfVar9 = *pfVar8 + (-fVar19 - fVar17);
      pfVar9[1] = pfVar8[1] + (-fVar20 - fVar18);
      pfVar9[2] = pfVar8[2] + (-fVar16 - fVar13);
      pfVar9 = (float *)((int)pfVar5 + iVar2);
      *pfVar7 = *pfVar8 + (fVar19 - fVar17);
      pfVar7[1] = pfVar8[1] + (fVar20 - fVar18);
      pfVar7[2] = pfVar8[2] + (fVar16 - fVar13);
      *pfVar6 = *pfVar8 + fVar19 + fVar17;
      pfVar6[1] = pfVar8[1] + fVar20 + fVar18;
      pfVar6[2] = pfVar8[2] + fVar16 + fVar13;
      *pfVar5 = *pfVar8 + -fVar19 + fVar17;
      pfVar5[1] = pfVar8[1] + -fVar20 + fVar18;
      pfVar6 = pfVar8 + 2;
      pfVar8 = (float *)((int)pfVar8 + iVar1);
      pfVar5[2] = *pfVar6 + -fVar16 + fVar13;
    } while (iVar12 < param_4);
  }
  return;
}

// FUN_00487280 NONMATCHING

void FUN_00487280(int *param_1,float *param_2,float *param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  float *pfVar7;
  u32 *puVar8;
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
  
  iVar10 = 0;
  iVar1 = *(int *)(param_5 + 8);
  pfVar9 = *(float **)(param_5 + 4);
  puVar8 = *(u32 **)(param_5 + 0x34);
  pfVar7 = (float *)*param_1;
  iVar2 = param_1[1];
  fVar22 = *(float *)(param_5 + 0x70) * 0.5;
  iVar3 = *(int *)(param_5 + 0x38);
  fVar21 = *(float *)(param_5 + 0x74) * 0.5;
  if (0 < param_4) {
    do {
      fVar11 = (float)((code)FUN_0052e878)(*puVar8);
      fVar12 = (float)((code)FUN_0052e6d8)(*puVar8);
      iVar10 = iVar10 + 1;
      pfVar6 = (float *)((int)pfVar7 + iVar2);
      fVar14 = -fVar11;
      puVar8 = (u32 *)((int)puVar8 + iVar3);
      fVar18 = fVar12 * *param_2 + fVar14 * *param_3;
      pfVar4 = (float *)((int)pfVar6 + iVar2);
      pfVar5 = (float *)((int)pfVar4 + iVar2);
      fVar16 = fVar12 * param_2[1] + fVar14 * param_3[1];
      fVar15 = *(float *)(param_5 + 0x6c);
      fVar20 = fVar18 * fVar22;
      fVar17 = fVar12 * param_2[2] + fVar14 * param_3[2];
      fVar13 = fVar11 * *param_2 + fVar12 * *param_3;
      fVar14 = fVar11 * param_2[1] + fVar12 * param_3[1];
      fVar12 = fVar11 * param_2[2] + fVar12 * param_3[2];
      fVar11 = *(float *)(param_5 + 0x68);
      fVar19 = fVar13 * fVar21;
      fVar18 = fVar11 * fVar18 + fVar15 * fVar13;
      fVar13 = fVar11 * fVar16 + fVar15 * fVar14;
      fVar11 = fVar11 * fVar17 + fVar15 * fVar12;
      fVar17 = fVar17 * fVar22;
      fVar16 = fVar16 * fVar22;
      fVar12 = fVar12 * fVar21;
      *pfVar7 = *pfVar9 + fVar18 + (-fVar20 - fVar19);
      fVar14 = fVar14 * fVar21;
      pfVar7[1] = pfVar9[1] + fVar13 + (-fVar16 - fVar14);
      pfVar7[2] = pfVar9[2] + fVar11 + (-fVar17 - fVar12);
      pfVar7 = (float *)((int)pfVar5 + iVar2);
      *pfVar6 = *pfVar9 + fVar18 + (fVar20 - fVar19);
      pfVar6[1] = pfVar9[1] + fVar13 + (fVar16 - fVar14);
      pfVar6[2] = pfVar9[2] + fVar11 + (fVar17 - fVar12);
      *pfVar4 = *pfVar9 + fVar18 + fVar20 + fVar19;
      pfVar4[1] = pfVar9[1] + fVar13 + fVar16 + fVar14;
      pfVar4[2] = pfVar9[2] + fVar11 + fVar17 + fVar12;
      *pfVar5 = *pfVar9 + fVar18 + -fVar20 + fVar19;
      pfVar5[1] = pfVar9[1] + fVar13 + -fVar16 + fVar14;
      pfVar4 = pfVar9 + 2;
      pfVar9 = (float *)((int)pfVar9 + iVar1);
      pfVar5[2] = *pfVar4 + fVar11 + -fVar17 + fVar12;
    } while (iVar10 < param_4);
  }
  return;
}

// FUN_004876F0 NONMATCHING

void FUN_004876f0(int *param_1,float *param_2,float *param_3,long param_4,int param_5)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  float *pfVar7;
  float *pfVar8;
  u32 *puVar9;
  float *pfVar10;
  float *pfVar11;
  float *pfVar12;
  int iVar13;
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
  
  iVar13 = 0;
  iVar2 = *(int *)(param_5 + 8);
  pfVar10 = *(float **)(param_5 + 4);
  puVar9 = *(u32 **)(param_5 + 0x34);
  pfVar12 = *(float **)(param_5 + 0x1c);
  pfVar11 = (float *)*param_1;
  iVar3 = param_1[1];
  iVar4 = *(int *)(param_5 + 0x38);
  iVar5 = *(int *)(param_5 + 0x20);
  if (0 < param_4) {
    do {
      fVar14 = (float)((code)FUN_0052e878)(*puVar9);
      fVar15 = (float)((code)FUN_0052e6d8)(*puVar9);
      pfVar8 = (float *)((int)pfVar11 + iVar3);
      pfVar7 = (float *)((int)pfVar8 + iVar3);
      pfVar6 = (float *)((int)pfVar7 + iVar3);
      iVar13 = iVar13 + 1;
      fVar19 = -fVar14;
      puVar9 = (u32 *)((int)puVar9 + iVar4);
      fVar23 = fVar15 * *param_2 + fVar19 * *param_3;
      fVar25 = fVar15 * param_2[1] + fVar19 * param_3[1];
      fVar22 = *(float *)(param_5 + 0x6c);
      fVar20 = *(float *)(param_5 + 0x68);
      fVar19 = fVar15 * param_2[2] + fVar19 * param_3[2];
      fVar21 = fVar14 * *param_2 + fVar15 * *param_3;
      fVar24 = fVar14 * param_2[1] + fVar15 * param_3[1];
      fVar15 = fVar14 * param_2[2] + fVar15 * param_3[2];
      pfVar1 = pfVar12 + 1;
      fVar18 = fVar20 * fVar23 + fVar22 * fVar21;
      fVar17 = *pfVar12 * 0.5;
      pfVar12 = (float *)((int)pfVar12 + iVar5);
      fVar14 = *pfVar1 * 0.5;
      fVar23 = fVar23 * fVar17;
      fVar21 = fVar21 * fVar14;
      fVar16 = fVar20 * fVar25 + fVar22 * fVar24;
      fVar20 = fVar20 * fVar19 + fVar22 * fVar15;
      fVar24 = fVar24 * fVar14;
      fVar15 = fVar15 * fVar14;
      fVar25 = fVar25 * fVar17;
      fVar19 = fVar19 * fVar17;
      *pfVar11 = *pfVar10 + fVar18 + (-fVar23 - fVar21);
      pfVar11[1] = pfVar10[1] + fVar16 + (-fVar25 - fVar24);
      pfVar11[2] = pfVar10[2] + fVar20 + (-fVar19 - fVar15);
      pfVar11 = (float *)((int)pfVar6 + iVar3);
      *pfVar8 = *pfVar10 + fVar18 + (fVar23 - fVar21);
      pfVar8[1] = pfVar10[1] + fVar16 + (fVar25 - fVar24);
      pfVar8[2] = pfVar10[2] + fVar20 + (fVar19 - fVar15);
      *pfVar7 = *pfVar10 + fVar18 + fVar23 + fVar21;
      pfVar7[1] = pfVar10[1] + fVar16 + fVar25 + fVar24;
      pfVar7[2] = pfVar10[2] + fVar20 + fVar19 + fVar15;
      *pfVar6 = *pfVar10 + fVar18 + -fVar23 + fVar21;
      pfVar6[1] = pfVar10[1] + fVar16 + -fVar25 + fVar24;
      pfVar1 = pfVar10 + 2;
      pfVar10 = (float *)((int)pfVar10 + iVar2);
      pfVar6[2] = *pfVar1 + fVar20 + -fVar19 + fVar15;
    } while (iVar13 < (int)param_4);
  }
  return;
}

// FUN_00487BF0 NONMATCHING

void FUN_00487bf0(u32 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  u32 uVar3;
  u8 bVar4;
  u32 *puVar5;
  u32 *puVar6;
  u32 *puVar7;
  u32 *puVar8;
  u32 *puVar9;
  u32 *puVar10;
  u32 *puVar11;
  u32 *puVar12;
  u32 *puVar13;
  u32 *puVar14;
  u32 *puVar15;
  u32 *puVar16;
  u32 *puVar17;
  u32 *puVar18;
  u32 *puVar19;
  u32 *puVar20;
  int iVar21;
  u32 *puVar22;
  u32 *puVar23;
  u32 *puVar24;
  u32 *puVar25;
  u32 *puVar26;
  u32 *puVar27;
  u32 *puVar28;
  u32 *puVar29;
  u32 *puVar30;
  
  puVar6 = (u32 *)*param_1;
  iVar1 = param_1[1];
  puVar20 = *(u32 **)(param_3 + 0x24);
  iVar2 = *(int *)(param_3 + 0x28);
  iVar21 = 0;
  if (0 < param_2) {
    if (8 < param_2) {
      bVar4 = 0;
      if ((-1 < param_2) && (param_2 < 0x7fffffff)) {
        bVar4 = 1;
      }
      if (bVar4) {
        do {
          uVar3 = *puVar20;
          puVar8 = (u32 *)((int)puVar6 + iVar1 + iVar1);
          puVar7 = (u32 *)((int)puVar8 + iVar1);
          puVar9 = (u32 *)((int)puVar20 + iVar2 + iVar2);
          puVar18 = (u32 *)((int)puVar9 + iVar2);
          puVar13 = (u32 *)((int)puVar7 + iVar1);
          puVar28 = (u32 *)((int)puVar18 + iVar2);
          puVar11 = (u32 *)((int)puVar13 + iVar1);
          puVar12 = (u32 *)((int)puVar28 + iVar2);
          puVar10 = (u32 *)((int)puVar11 + iVar1);
          *puVar6 = uVar3;
          puVar5 = (u32 *)((int)puVar12 + iVar2);
          *(u32 *)((int)puVar6 + iVar1) = uVar3;
          puVar19 = (u32 *)((int)puVar10 + iVar1);
          *puVar8 = uVar3;
          iVar21 = iVar21 + 8;
          *puVar7 = uVar3;
          puVar8 = (u32 *)((int)puVar19 + iVar1);
          uVar3 = *(u32 *)((int)puVar20 + iVar2);
          puVar7 = (u32 *)((int)puVar8 + iVar1);
          puVar6 = (u32 *)((int)puVar7 + iVar1);
          puVar22 = (u32 *)((int)puVar6 + iVar1);
          puVar29 = (u32 *)((int)puVar22 + iVar1);
          puVar17 = (u32 *)((int)puVar29 + iVar1);
          puVar16 = (u32 *)((int)puVar17 + iVar1);
          *puVar13 = uVar3;
          *puVar11 = uVar3;
          *puVar10 = uVar3;
          *puVar19 = uVar3;
          uVar3 = *puVar9;
          puVar14 = (u32 *)((int)puVar5 + iVar2);
          puVar20 = (u32 *)((int)puVar14 + iVar2);
          *puVar8 = uVar3;
          *puVar7 = uVar3;
          *puVar6 = uVar3;
          *puVar22 = uVar3;
          puVar15 = (u32 *)((int)puVar16 + iVar1);
          puVar22 = (u32 *)((int)puVar15 + iVar1);
          puVar19 = (u32 *)((int)puVar22 + iVar1);
          puVar13 = (u32 *)((int)puVar19 + iVar1);
          puVar11 = (u32 *)((int)puVar13 + iVar1);
          puVar10 = (u32 *)((int)puVar11 + iVar1);
          puVar30 = (u32 *)((int)puVar10 + iVar1);
          puVar24 = (u32 *)((int)puVar30 + iVar1);
          puVar25 = (u32 *)((int)puVar24 + iVar1);
          puVar26 = (u32 *)((int)puVar25 + iVar1);
          puVar27 = (u32 *)((int)puVar26 + iVar1);
          uVar3 = *puVar18;
          puVar9 = (u32 *)((int)puVar27 + iVar1);
          puVar8 = (u32 *)((int)puVar9 + iVar1);
          puVar7 = (u32 *)((int)puVar8 + iVar1);
          puVar23 = (u32 *)((int)puVar7 + iVar1);
          *puVar29 = uVar3;
          puVar18 = (u32 *)((int)puVar23 + iVar1);
          *puVar17 = uVar3;
          puVar6 = (u32 *)((int)puVar18 + iVar1);
          *puVar16 = uVar3;
          *puVar15 = uVar3;
          uVar3 = *puVar28;
          *puVar22 = uVar3;
          *puVar19 = uVar3;
          *puVar13 = uVar3;
          *puVar11 = uVar3;
          uVar3 = *puVar12;
          *puVar10 = uVar3;
          *puVar30 = uVar3;
          *puVar24 = uVar3;
          *puVar25 = uVar3;
          uVar3 = *puVar5;
          *puVar26 = uVar3;
          *puVar27 = uVar3;
          *puVar9 = uVar3;
          *puVar8 = uVar3;
          uVar3 = *puVar14;
          *puVar7 = uVar3;
          *puVar23 = uVar3;
          *puVar18 = uVar3;
          *puVar6 = uVar3;
          puVar6 = (u32 *)((int)puVar6 + iVar1);
        } while (iVar21 < param_2 + -8);
      }
    }
    for (; iVar21 < param_2; iVar21 = iVar21 + 1) {
      uVar3 = *puVar20;
      puVar7 = (u32 *)((int)puVar6 + iVar1 + iVar1);
      puVar5 = (u32 *)((int)puVar7 + iVar1);
      *puVar6 = uVar3;
      puVar20 = (u32 *)((int)puVar20 + iVar2);
      *(u32 *)((int)puVar6 + iVar1) = uVar3;
      puVar6 = (u32 *)((int)puVar5 + iVar1);
      *puVar7 = uVar3;
      *puVar5 = uVar3;
    }
  }
  return;
}

// FUN_00488550 NONMATCHING

void FUN_00488550(int *param_1,int param_2,int param_3,int param_4,u32 param_5)

{
  int iVar1;
  u8 bVar2;
  u8 bVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  float *pfVar7;
  u32 uVar8;
  u32 *puVar9;
  float *pfVar10;
  float *pfVar11;
  int iVar12;
  int iVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  
  uVar6 = DAT_0077dcb8;
  uVar5 = DAT_0077dcb4;
  uVar4 = DAT_0077dcb0;
  pfVar10 = (float *)(param_1 + 0xc);
  iVar1 = *(int *)(param_2 + 0x18);
  pfVar11 = (float *)(param_1 + 0xf);
  if ((param_5 & 0x800000) == 0x800000) {
    iVar12 = *(int *)(iVar1 + 0x5c);
    iVar13 = **(int **)(param_2 + DAT_007ce770);
    ((code)FUN_00493370)(iVar1,2);
    iVar12 = *(int *)(iVar12 + 0x14);
    if (param_4 < iVar13) {
      if (8 < iVar13 - param_4) {
        bVar2 = 0;
        bVar3 = 0;
        if ((param_4 <= iVar13) && (iVar13 < 0x7fffffff)) {
          bVar3 = 1;
        }
        if ((bVar3) && (param_4 < 0x7fffffff)) {
          bVar2 = 1;
        }
        if (bVar2) {
          puVar9 = (u32 *)(iVar12 + param_4 * 0x30);
          do {
            *puVar9 = uVar4;
            param_4 = param_4 + 8;
            puVar9[1] = uVar5;
            puVar9[2] = uVar6;
            puVar9[3] = uVar4;
            puVar9[4] = uVar5;
            puVar9[5] = uVar6;
            puVar9[6] = uVar4;
            puVar9[7] = uVar5;
            puVar9[8] = uVar6;
            puVar9[9] = uVar4;
            puVar9[10] = uVar5;
            puVar9[0xb] = uVar6;
            puVar9[0xc] = uVar4;
            puVar9[0xd] = uVar5;
            puVar9[0xe] = uVar6;
            puVar9[0xf] = uVar4;
            puVar9[0x10] = uVar5;
            puVar9[0x11] = uVar6;
            puVar9[0x12] = uVar4;
            puVar9[0x13] = uVar5;
            puVar9[0x14] = uVar6;
            puVar9[0x15] = uVar4;
            puVar9[0x16] = uVar5;
            puVar9[0x17] = uVar6;
            puVar9[0x18] = uVar4;
            puVar9[0x19] = uVar5;
            puVar9[0x1a] = uVar6;
            puVar9[0x1b] = uVar4;
            puVar9[0x1c] = uVar5;
            puVar9[0x1d] = uVar6;
            puVar9[0x1e] = uVar4;
            puVar9[0x1f] = uVar5;
            puVar9[0x20] = uVar6;
            puVar9[0x21] = uVar4;
            puVar9[0x22] = uVar5;
            puVar9[0x23] = uVar6;
            puVar9[0x24] = uVar4;
            puVar9[0x25] = uVar5;
            puVar9[0x26] = uVar6;
            puVar9[0x27] = uVar4;
            puVar9[0x28] = uVar5;
            puVar9[0x29] = uVar6;
            puVar9[0x2a] = uVar4;
            puVar9[0x2b] = uVar5;
            puVar9[0x2c] = uVar6;
            puVar9[0x2d] = uVar4;
            puVar9[0x2e] = uVar5;
            puVar9[0x2f] = uVar6;
            puVar9[0x30] = uVar4;
            puVar9[0x31] = uVar5;
            puVar9[0x32] = uVar6;
            puVar9[0x33] = uVar4;
            puVar9[0x34] = uVar5;
            puVar9[0x35] = uVar6;
            puVar9[0x36] = uVar4;
            puVar9[0x37] = uVar5;
            puVar9[0x38] = uVar6;
            puVar9[0x39] = uVar4;
            puVar9[0x3a] = uVar5;
            puVar9[0x3b] = uVar6;
            puVar9[0x3c] = uVar4;
            puVar9[0x3d] = uVar5;
            puVar9[0x3e] = uVar6;
            puVar9[0x3f] = uVar4;
            puVar9[0x40] = uVar5;
            puVar9[0x41] = uVar6;
            puVar9[0x42] = uVar4;
            puVar9[0x43] = uVar5;
            puVar9[0x44] = uVar6;
            puVar9[0x45] = uVar4;
            puVar9[0x46] = uVar5;
            puVar9[0x47] = uVar6;
            puVar9[0x48] = uVar4;
            puVar9[0x49] = uVar5;
            puVar9[0x4a] = uVar6;
            puVar9[0x4b] = uVar4;
            puVar9[0x4c] = uVar5;
            puVar9[0x4d] = uVar6;
            puVar9[0x4e] = uVar4;
            puVar9[0x4f] = uVar5;
            puVar9[0x50] = uVar6;
            puVar9[0x51] = uVar4;
            puVar9[0x52] = uVar5;
            puVar9[0x53] = uVar6;
            puVar9[0x54] = uVar4;
            puVar9[0x55] = uVar5;
            puVar9[0x56] = uVar6;
            puVar9[0x57] = uVar4;
            puVar9[0x58] = uVar5;
            puVar9[0x59] = uVar6;
            puVar9[0x5a] = uVar4;
            puVar9[0x5b] = uVar5;
            puVar9[0x5c] = uVar6;
            puVar9[0x5d] = uVar4;
            puVar9[0x5e] = uVar5;
            puVar9[0x5f] = uVar6;
            puVar9 = puVar9 + 0x60;
          } while (param_4 < iVar13 + -8);
        }
      }
      if (param_4 < iVar13) {
        puVar9 = (u32 *)(iVar12 + param_4 * 0x30);
        do {
          *puVar9 = uVar4;
          param_4 = param_4 + 1;
          puVar9[1] = uVar5;
          puVar9[2] = uVar6;
          puVar9[3] = uVar4;
          puVar9[4] = uVar5;
          puVar9[5] = uVar6;
          puVar9[6] = uVar4;
          puVar9[7] = uVar5;
          puVar9[8] = uVar6;
          puVar9[9] = uVar4;
          puVar9[10] = uVar5;
          puVar9[0xb] = uVar6;
          puVar9 = puVar9 + 0xc;
        } while (param_4 < iVar13);
      }
    }
  }
  pfVar7 = (float *)((code)FUN_004cb2f0)(*(u32 *)(DAT_00960070 + 4));
  if ((*(u32 *)(param_3 + 0x58) & 0x8000) == 0x8000) {
    iVar12 = *(int *)(param_3 + 0xb4);
    iVar13 = *(int *)(param_3 + 0xb8);
    *pfVar10 = *(float *)(param_3 + 0xb0);
    param_1[0xd] = iVar12;
    param_1[0xe] = iVar13;
    iVar12 = *(int *)(param_3 + 0xc4);
    iVar13 = *(int *)(param_3 + 200);
    *pfVar11 = *(float *)(param_3 + 0xc0);
    param_1[0x10] = iVar12;
    param_1[0x11] = iVar13;
  }
  else if ((*(u32 *)(param_3 + 0x58) & 0x20000) == 0x20000) {
    fVar17 = *pfVar7;
    fVar14 = pfVar7[2];
    fVar22 = pfVar7[4];
    fVar20 = pfVar7[5];
    fVar21 = pfVar7[6];
    fVar19 = -pfVar7[1];
    fVar15 = (float)((code)FUN_0052e878)(*(u32 *)(param_3 + 0x78));
    fVar16 = (float)((code)FUN_0052e6d8)(*(u32 *)(param_3 + 0x78));
    fVar18 = -fVar15;
    *pfVar10 = fVar16 * -fVar17 + fVar18 * fVar22;
    param_1[0xd] = (int)(fVar16 * fVar19 + fVar18 * fVar20);
    param_1[0xe] = (int)(fVar16 * -fVar14 + fVar18 * fVar21);
    *pfVar11 = fVar15 * -fVar17 + fVar16 * fVar22;
    param_1[0x10] = (int)(fVar15 * fVar19 + fVar16 * fVar20);
    param_1[0x11] = (int)(fVar15 * -fVar14 + fVar16 * fVar21);
  }
  else {
    *pfVar10 = -*pfVar7;
    param_1[0xd] = (int)-pfVar7[1];
    param_1[0xe] = (int)-pfVar7[2];
    *pfVar11 = pfVar7[4];
    param_1[0x10] = (int)pfVar7[5];
    param_1[0x11] = (int)pfVar7[6];
  }
  uVar8 = (u32)((param_5 & 2) == 2);
  if (uVar8 == 0) {
    uVar8 = (u32)((param_5 & 0x2000) == 0x2000);
  }
  if (uVar8 == 0) {
    uVar8 = (u32)((param_5 & 0x40) == 0x40);
  }
  if (uVar8 == 0) {
    uVar8 = (u32)((param_5 & 0x40000) == 0x40000);
  }
  param_1[2] = uVar8;
  uVar8 = (u32)((param_5 & 0x80) == 0x80);
  if (uVar8 == 0) {
    uVar8 = (u32)((param_5 & 0x100) == 0x100);
  }
  if (uVar8 == 0) {
    uVar8 = (u32)((param_5 & 0x80000) == 0x80000);
  }
  if (uVar8 == 0) {
    uVar8 = (u32)((param_5 & 0x100000) == 0x100000);
  }
  param_1[1] = uVar8;
  *param_1 = 1;
  param_1[3] = (u32)((param_5 & 0x10) == 0x10);
  iVar12 = *(int *)(iVar1 + 0x5c);
  if (*param_1 != 0) {
    ((code)FUN_00493370)(iVar1,2);
    param_1[4] = *(int *)(iVar12 + 0x14);
    param_1[5] = 0xc;
  }
  if (param_1[2] != 0) {
    ((code)FUN_00493370)(iVar1,8);
    param_1[8] = *(int *)(iVar1 + 0x30);
    param_1[9] = 4;
  }
  if (param_1[1] != 0) {
    ((code)FUN_00493370)(iVar1,0x10);
    param_1[6] = *(int *)(iVar1 + 0x34);
    param_1[7] = 8;
  }
  if (param_1[3] != 0) {
    ((code)FUN_00493370)(iVar1,4);
    param_1[10] = *(int *)(iVar12 + 0x18);
    param_1[0xb] = 0xc;
  }
  return;
}

// FUN_0048D270 NONMATCHING

u64 FUN_0048d270(int param_1,int param_2,u64 param_3)

{
  int iVar1;
  u32 *puVar2;
  u32 *puVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  if (-1 < param_2) {
    if (*(int *)(param_1 + 0xc) == 2) {
      iVar1 = *(int *)(param_1 + 8) + -3;
    }
    else if (*(int *)(param_1 + 0xc) == 1) {
      iVar1 = *(int *)(param_1 + 8) + -2;
    }
    else {
      uStack_10 = 0x102;
      uStack_c = ((code)FUN_004c1d10)();
      ((code)FUN_004c1c50)(&uStack_10);
      iVar1 = 0;
    }
    if (param_2 < iVar1) {
      puVar2 = (u32 *)(*(int *)(param_1 + 0x14) + param_2 * 0xc);
      uVar4 = puVar2[1];
      uVar5 = puVar2[2];
      puVar3 = (u32 *)param_3;
      *puVar3 = *puVar2;
      puVar3[1] = uVar4;
      puVar3[2] = uVar5;
      return param_3;
    }
  }
  uStack_8 = 0x102;
  uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000003,0x77dcc0);
  ((code)FUN_004c1c50)(&uStack_8);
  return 0;
}

// FUN_0048D370 NONMATCHING

u64 FUN_0048d370(u64 param_1,int param_2,u32 *param_3)

{
  int iVar1;
  u32 *puVar2;
  long lVar3;
  int iVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  if (-1 < param_2) {
    iVar4 = (int)param_1;
    if (*(int *)(iVar4 + 0xc) == 2) {
      iVar1 = *(int *)(iVar4 + 8) + -3;
    }
    else if (*(int *)(iVar4 + 0xc) == 1) {
      iVar1 = *(int *)(iVar4 + 8) + -2;
    }
    else {
      uStack_10 = 0x102;
      uStack_c = ((code)FUN_004c1d10)();
      ((code)FUN_004c1c50)(&uStack_10);
      iVar1 = 0;
    }
    if (param_2 < iVar1) {
      uVar5 = param_3[1];
      uVar6 = param_3[2];
      puVar2 = (u32 *)(*(int *)(iVar4 + 0x14) + param_2 * 0xc);
      *puVar2 = *param_3;
      puVar2[1] = uVar5;
      puVar2[2] = uVar6;
      lVar3 = ((code)FUN_0048b910)(param_1,*(u32 *)(iVar4 + 0x14));
      if (lVar3 != 0) {
        return param_1;
      }
      return 0;
    }
  }
  uStack_8 = 0x102;
  uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000003,0x77dcc0);
  ((code)FUN_004c1c50)(&uStack_8);
  return 0;
}

// FUN_0048D480 NONMATCHING

u64 FUN_0048d480(float param_1,int param_2,long param_3,u64 param_4,long param_5)

{
  int iVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  u32 uVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  u32 uStack_8;
  u32 uStack_4;
  
  if (0.0 <= param_1) {
    iVar1 = *(int *)(param_2 + 0xc);
  }
  else {
    param_1 = -param_1;
    iVar1 = *(int *)(param_2 + 0xc);
  }
  if ((iVar1 == 2) && (1.0 < param_1)) {
    if (param_1 < 2.1474836e+09) {
      uVar5 = (u32)param_1;
    }
    else {
      uVar5 = (int)(param_1 - 2.1474836e+09) | 0x80000000;
    }
    param_1 = param_1 - (float)uVar5;
  }
  if (param_3 == 0xb) {
    if (param_1 <= 0.5) {
      param_1 = param_1 * (param_1 + param_1);
    }
    else {
      param_1 = param_1 * 4.0 + param_1 * -2.0 * param_1 + -1.0;
    }
  }
  else if (param_3 != 10) {
    uStack_8 = 0x102;
    uStack_4 = ((code)FUN_004c1d10)(1);
    ((code)FUN_004c1c50)(&uStack_8);
    return 0;
  }
  fVar6 = 1.0;
  if (param_1 == 1.0) {
    iVar2 = *(int *)(param_2 + 8) + -4;
    iVar1 = 0xff;
  }
  else {
    param_1 = (float)(*(int *)(param_2 + 8) + -3) * param_1;
    iVar2 = (int)param_1;
    fVar6 = (param_1 - (float)iVar2) * 256.0;
    iVar1 = (int)fVar6;
    fVar6 = fVar6 - (float)iVar1;
  }
  iVar1 = iVar1 * 4;
  pfVar3 = (float *)(param_2 + 0x38 + iVar2 * 0xc);
  fVar9 = *(float *)(DAT_007ce788 + iVar1);
  fVar8 = *(float *)(DAT_007ce784 + iVar1);
  fVar7 = *(float *)(DAT_007ce780 + iVar1);
  fVar10 = fVar6 * (((float *)(DAT_007ce788 + iVar1))[1] - fVar9) + fVar9 + 0.0;
  fVar11 = fVar6 * (((float *)(DAT_007ce784 + iVar1))[1] - fVar8) + fVar8 + 0.0;
  fVar8 = fVar6 * (((float *)(DAT_007ce780 + iVar1))[1] - fVar7) + fVar7 + 0.0;
  fVar9 = *(float *)(DAT_007ce77c + iVar1);
  fVar7 = ((float *)(DAT_007ce77c + iVar1))[1];
  pfVar4 = (float *)param_4;
  *pfVar4 = *pfVar3 * fVar10;
  pfVar4[1] = pfVar3[1] * fVar10;
  fVar7 = fVar6 * (fVar7 - fVar9) + fVar9 + 0.0;
  pfVar4[2] = pfVar3[2] * fVar10;
  *pfVar4 = pfVar3[3] * fVar11 + *pfVar4 + 0.0;
  pfVar4[1] = pfVar3[4] * fVar11 + pfVar4[1] + 0.0;
  pfVar4[2] = pfVar3[5] * fVar11 + pfVar4[2] + 0.0;
  *pfVar4 = pfVar3[6] * fVar8 + *pfVar4 + 0.0;
  pfVar4[1] = pfVar3[7] * fVar8 + pfVar4[1] + 0.0;
  pfVar4[2] = pfVar3[8] * fVar8 + pfVar4[2] + 0.0;
  *pfVar4 = pfVar3[9] * fVar7 + *pfVar4 + 0.0;
  pfVar4[1] = pfVar3[10] * fVar7 + pfVar4[1] + 0.0;
  pfVar4[2] = pfVar3[0xb] * fVar7 + pfVar4[2] + 0.0;
  if (param_5 != 0) {
    fVar9 = *(float *)(DAT_007ce798 + iVar1);
    fVar8 = *(float *)(DAT_007ce794 + iVar1);
    fVar7 = *(float *)(DAT_007ce790 + iVar1);
    fVar9 = fVar6 * (((float *)(DAT_007ce798 + iVar1))[1] - fVar9) + fVar9 + 0.0;
    fVar10 = fVar6 * (((float *)(DAT_007ce794 + iVar1))[1] - fVar8) + fVar8 + 0.0;
    fVar7 = fVar6 * (((float *)(DAT_007ce790 + iVar1))[1] - fVar7) + fVar7 + 0.0;
    fVar8 = *(float *)(DAT_007ce78c + iVar1);
    fVar6 = fVar6 * (((float *)(DAT_007ce78c + iVar1))[1] - fVar8) + fVar8 + 0.0;
    pfVar4 = (float *)param_5;
    *pfVar4 = *pfVar3 * fVar9;
    pfVar4[1] = pfVar3[1] * fVar9;
    pfVar4[2] = pfVar3[2] * fVar9;
    *pfVar4 = pfVar3[3] * fVar10 + *pfVar4 + 0.0;
    pfVar4[1] = pfVar3[4] * fVar10 + pfVar4[1] + 0.0;
    pfVar4[2] = pfVar3[5] * fVar10 + pfVar4[2] + 0.0;
    *pfVar4 = pfVar3[6] * fVar7 + *pfVar4 + 0.0;
    pfVar4[1] = pfVar3[7] * fVar7 + pfVar4[1] + 0.0;
    pfVar4[2] = pfVar3[8] * fVar7 + pfVar4[2] + 0.0;
    *pfVar4 = pfVar3[9] * fVar6 + *pfVar4 + 0.0;
    pfVar4[1] = pfVar3[10] * fVar6 + pfVar4[1] + 0.0;
    pfVar4[2] = pfVar3[0xb] * fVar6 + pfVar4[2] + 0.0;
    fVar6 = (float)((code)FUN_004c6970)(param_5,param_5);
    if (fVar6 == 0.0) {
      *pfVar4 = 0.0;
      pfVar4[1] = 1.0;
      pfVar4[2] = 0.0;
    }
  }
  return param_4;
}

// FUN_0048D960 NONMATCHING

u64 FUN_0048d960(u64 param_1)

{
  long lVar1;
  long lVar2;
  u64 uVar3;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_4;
  
  uVar3 = 0;
  lVar1 = ((code)FUN_004c58a0)(2,1,param_1);
  if (lVar1 != 0) {
    lVar2 = ((code)FUN_004c1600)(lVar1,0xc,0,&uStack_4);
    if (lVar2 != 0) {
      if ((uStack_4 < 0x35000) || (0x37002 < uStack_4)) {
        uStack_10 = 0x102;
        uStack_c = ((code)FUN_004c1d10)(0xffffffff80000004);
        ((code)FUN_004c1c50)(&uStack_10);
      }
      else {
        uVar3 = ((code)FUN_0048d0e0)(lVar1);
      }
    }
    ((code)FUN_004c5780)(lVar1,0);
  }
  return uVar3;
}

// FUN_0048DA30 NONMATCHING

u32 FUN_0048da30(u64 param_1)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 0x14) != 0) {
    (*DAT_0096017c)();
    *(u32 *)(iVar1 + 0x14) = 0;
  }
  if (*(int *)(iVar1 + 0x10) != 0) {
    (*DAT_0096017c)();
    *(u32 *)(iVar1 + 0x10) = 0;
  }
  (*DAT_0096017c)(param_1);
  return 1;
}

// FUN_0048DAB0 NONMATCHING

long FUN_0048dab0(int param_1,long param_2,u64 param_3)

{
  long lVar1;
  long lVar2;
  u8 *puVar3;
  int iVar4;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  u32 uStack_4;
  
  if (param_2 == 2) {
    iVar4 = (param_1 + 2) * 0xc + 0x44;
    lVar1 = (*DAT_00960178)(iVar4,0x3000c);
    if (lVar1 == 0) {
      uStack_10 = 0x102;
      uStack_c = ((code)FUN_004c1d10)(0xffffffff80000013,iVar4);
      ((code)FUN_004c1c50)(&uStack_10);
      return 0;
    }
    *(int *)((int)lVar1 + 8) = param_1 + 3;
  }
  else {
    if (param_2 != 1) {
      uStack_18 = 0x102;
      uStack_14 = ((code)FUN_004c1d10)();
      ((code)FUN_004c1c50)(&uStack_18);
      return 0;
    }
    iVar4 = (param_1 + 1) * 0xc + 0x44;
    lVar1 = (*DAT_00960178)(iVar4,0x3000c);
    if (lVar1 == 0) {
      uStack_8 = 0x102;
      uStack_4 = ((code)FUN_004c1d10)(0xffffffff80000013,iVar4);
      ((code)FUN_004c1c50)(&uStack_8);
      return 0;
    }
    *(int *)((int)lVar1 + 8) = param_1 + 2;
  }
  puVar3 = (u8 *)lVar1;
  *(u32 *)(puVar3 + 0x10) = 0;
  puVar3[0x18] = 0;
  *(int *)(puVar3 + 0xc) = (int)param_2;
  *puVar3 = 0xc;
  lVar2 = ((code)FUN_0048b910)(lVar1,param_3);
  if (lVar2 == 0) {
    (*DAT_0096017c)(lVar1);
    lVar1 = 0;
  }
  else {
    *puVar3 = 0xc;
    lVar2 = (*DAT_00960178)(param_1 * 0xc,0x3000c);
    *(int *)(puVar3 + 0x14) = (int)lVar2;
    if (lVar2 == 0) {
      (*DAT_0096017c)(lVar1);
      uStack_20 = 0x102;
      uStack_1c = ((code)FUN_004c1d10)(0xffffffff80000013,param_1 * 0xc);
      ((code)FUN_004c1c50)(&uStack_20);
      lVar1 = 0;
    }
    else {
      ((code)FUN_00521250)(*(u32 *)(puVar3 + 0x14),param_3,param_1 * 0xc);
    }
  }
  return lVar1;
}

// FUN_0048DCF0 NONMATCHING

u8 FUN_0048dcf0(void)

{
  long lVar1;
  
  lVar1 = ((code)FUN_004ca520)(0,0x102,0x48cfa0,0x48cf00);
  return -1 < lVar1;
}

// FUN_0048DD70 NONMATCHING

void FUN_0048dd70(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*param_1 != 0) {
    (*DAT_0096017c)();
    *param_1 = 0;
  }
  if (param_1[1] == 3) {
    piVar1 = (int *)param_1[3];
    iVar2 = 0;
    if (0 < param_1[2]) {
      do {
        if (*piVar1 != 0) {
          (*DAT_0096017c)();
        }
        iVar2 = iVar2 + 1;
        piVar1 = piVar1 + 1;
      } while (iVar2 < param_1[2]);
    }
  }
  if (param_1[3] != 0) {
    (*DAT_0096017c)();
    param_1[3] = 0;
  }
  return;
}

// FUN_0048DE50 NONMATCHING

void FUN_0048de50(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  if ((*param_2 != 0) && (*param_1 = 0, *param_2 != 0)) {
    iVar1 = (*DAT_00960164)();
    iVar1 = (*DAT_00960178)(iVar1 + 1,0x30002);
    *param_1 = iVar1;
    if (*param_1 != 0) {
      (*DAT_0096013c)(*param_1,*param_2);
    }
  }
  if (param_2[3] != 0) {
    iVar2 = ((code)FUN_0048efe0)(param_1[1]);
    iVar1 = param_1[2];
    iVar3 = (*DAT_00960178)(iVar1 * iVar2,0x3011f);
    param_1[3] = iVar3;
    if (param_1[1] == 3) {
      piVar5 = (int *)param_2[3];
      piVar4 = (int *)param_1[3];
      iVar1 = 0;
      if (0 < param_1[2]) {
        do {
          if (*piVar5 == 0) {
            *piVar4 = 0;
          }
          else {
            *piVar4 = 0;
            if (*piVar5 != 0) {
              iVar2 = (*DAT_00960164)();
              iVar2 = (*DAT_00960178)(iVar2 + 1,0x30002);
              *piVar4 = iVar2;
              if (*piVar4 != 0) {
                (*DAT_0096013c)(*piVar4,*piVar5);
              }
            }
          }
          iVar1 = iVar1 + 1;
          piVar5 = piVar5 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar1 < param_1[2]);
      }
    }
    else {
      ((code)FUN_00521250)(param_1[3],param_2[3],iVar1 * iVar2);
    }
  }
  return;
}
