#include "temporary.h"

typedef int (*code)(...);
typedef struct YajimaVec2 {
  f32 x;
  f32 y;
} YajimaVec2;
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
#ifndef SQRT
#define SQRT(x) sqrtf(x)
#endif
extern f32 sqrtf(f32 value);
extern u32 DAT_006b4608;
extern u32 DAT_006b4610;
extern u32 DAT_006b4618;
extern u32 DAT_006b4620;
extern u8 DAT_006b4630[];
extern u8 DAT_006b45e0[];
extern u8 DAT_006b4510[];
extern u8 DAT_006b4bc0[];
extern u8 DAT_006b4a60[];
extern u8 DAT_006b45f8[];
extern u8 DAT_006b4a00[];
extern u8 DAT_006b4a18[];
extern u8 DAT_006b4a30[];
extern u8 DAT_006b4be0[];
extern u8 DAT_006b4b50[];
extern u8 DAT_006b4b30[];
extern u8 DAT_006b4b68[];
extern u32 DAT_006b4650;
extern u8 DAT_006b44f0[];
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
extern int DAT_007bc610[];
extern u32 DAT_007bc6b0;
extern u32 DAT_007bc730;
extern u32 DAT_007caf94;
extern float DAT_007cafa8;
extern float DAT_007cafc0;
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
#pragma alias DAT_0086be00_abs DAT_0086be00
extern u8 DAT_0086be00_abs[];
extern u32 DAT_0086e6e8;
extern u8 DAT_0086e6a0[];
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
#pragma alias DAT_008717e8_rows DAT_008717e8
#pragma alias DAT_008717a0_bytes DAT_008717a0
extern u8 DAT_008717a0_bytes[];
#pragma alias DAT_0086eda0_bytes DAT_0086eda0
extern u8 DAT_0086eda0_bytes[];
#pragma alias DAT_006b4650_bytes DAT_006b4650
extern u8 DAT_006b4650_bytes[];
#pragma alias DAT_006b4652_bytes DAT_006b4652
extern u8 DAT_006b4652_bytes[];
#pragma alias DAT_006b4608_abs DAT_006b4608
extern u8 DAT_006b4608_abs[];
#pragma alias DAT_006b4610_abs DAT_006b4610
extern u8 DAT_006b4610_abs[];
#pragma alias DAT_006b4618_abs DAT_006b4618
extern u8 DAT_006b4618_abs[];
#pragma alias DAT_006b4620_abs DAT_006b4620
extern u8 DAT_006b4620_abs[];
#pragma alias FUN_001b9120_u32 FUN_001b9120
#pragma alias FUN_0035bc00_u32 FUN_0035bc00
extern u32 FUN_0035bc00_u32(int param_1,u32 param_2,u32 param_3,int param_4);
extern int FUN_001b9120_u32(void);
#pragma alias FUN_001a91b0_call FUN_001a91b0
#pragma alias fGpffff82d0 uGpffff82d0
extern float fGpffff82d0;
extern void FUN_001a91b0_call(u32 param_1, void *param_2);
#pragma alias FUN_001a91b0_ret FUN_001a91b0
extern u64 FUN_001a91b0_ret(u32 param_1, void *param_2);
extern void FUN_00195020_y2(void);
#pragma alias FUN_0045afd0_call FUN_0045afd0
extern u32 FUN_0045afd0_call(float param_1,int param_2,int param_3,int param_4,int param_5,
                              int param_6,u8 param_7,u8 param_8,short param_9);
#pragma alias FUN_0045afd0_call2 FUN_0045afd0
extern u32 FUN_0045afd0_call2(int param_2,int param_3,int param_4,int param_5,int param_6,
                               u8 param_7,u8 param_8,short param_9,float param_1);
#pragma alias FUN_0045afd0_call3 FUN_0045afd0
extern u32 FUN_0045afd0_call3(int param_2,int param_3,int param_4,int param_5,int param_6,
                               float param_1,u8 param_7,u8 param_8,short param_9);
#pragma alias FUN_0045b190_arg FUN_0045b190
extern u32 FUN_0045b190_arg(int param_1);
#pragma alias FUN_00439520_arg FUN_00439520
extern void FUN_00439520_arg(int param_1);
#pragma alias FUN_0045bd90_arg FUN_0045bd90
extern void FUN_0045bd90_arg(int param_1);
extern u32 DAT_008717e8_rows[];
#pragma alias DAT_008717f4_rows DAT_008717f4
extern u32 DAT_008717f4_rows[];
#pragma alias DAT_0087190c_rows DAT_0087190c
extern u32 DAT_0087190c_rows[];
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
#pragma alias DAT_0095c0e0_abs DAT_0095c0e0
extern u8 DAT_0095c0e0_abs[];
#pragma alias DAT_0095c0e4_abs DAT_0095c0e4
extern u8 DAT_0095c0e4_abs[];
#pragma alias DAT_0095c0e8_abs DAT_0095c0e8
extern u8 DAT_0095c0e8_abs[];
#pragma alias DAT_0095c0ec_abs DAT_0095c0ec
extern u8 DAT_0095c0ec_abs[];
#pragma alias DAT_0095c0f0_abs DAT_0095c0f0
extern u8 DAT_0095c0f0_abs[];
#pragma alias DAT_0095c0f4_abs DAT_0095c0f4
extern u8 DAT_0095c0f4_abs[];
#pragma alias DAT_0095c0f8_abs DAT_0095c0f8
extern u8 DAT_0095c0f8_abs[];
#pragma alias DAT_0095c0fc_abs DAT_0095c0fc
extern u8 DAT_0095c0fc_abs[];
#pragma alias DAT_0095c100_abs DAT_0095c100
extern u8 DAT_0095c100_abs[];
extern u32 DAT_0095c0e4;
extern u32 DAT_0095c0e8;
extern u32 DAT_0095c0ec;
extern u32 DAT_0095c0f0;
extern u32 DAT_0095c0f4;
extern u32 DAT_0095c0f8;
extern u32 DAT_0095c0fc;
extern u32 DAT_0095c100;
extern u32 DAT_0095c110;
#pragma alias DAT_0095c110_abs DAT_0095c110
extern u8 DAT_0095c110_abs[];
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
extern f32 DAT_00960088;
extern code DAT_00960090;
extern code DAT_009600a0;
extern code DAT_0096017c;
#pragma alias DAT_0087190c_abs DAT_0087190c
#pragma alias DAT_007e094e_abs DAT_007e094e
#pragma alias DAT_007e0952_abs DAT_007e0952
#pragma alias DAT_007e0958_abs DAT_007e0958
#pragma alias DAT_007e095a_abs DAT_007e095a
#pragma alias DAT_007bc730_abs DAT_007bc730
extern u8 DAT_007e094e_abs[];
extern u8 DAT_007e0952_abs[];
extern u8 DAT_007e0958_abs[];
extern u8 DAT_007e095a_abs[];
extern u8 DAT_007bc730_abs[];
#pragma alias DAT_0086e80c_abs DAT_0086e80c
extern u8 DAT_0086e80c_abs[];
#pragma alias DAT_0086e6e8_abs DAT_0086e6e8
extern u8 DAT_0086e6e8_abs[];
#pragma alias FUN_00195020_call FUN_00195020
extern void FUN_00195020_call(u32 param_1);
extern u8 DAT_0087190c_abs[];
#pragma alias DAT_0086ede8_abs DAT_0086ede8
extern u8 DAT_0086ede8_abs[];
#pragma alias DAT_0086edf4_abs DAT_0086edf4
extern u8 DAT_0086edf4_abs[];
#pragma alias DAT_0086ef0c_abs DAT_0086ef0c
#pragma alias DAT_0086ef10_abs DAT_0086ef10
extern u8 DAT_0086ef10_abs[];
#pragma alias DAT_0086ef08_abs DAT_0086ef08
extern u8 DAT_0086ef08_abs[];
extern u8 DAT_0086ef0c_abs[];
#pragma alias DAT_00871948_abs DAT_00871948
extern u8 DAT_00871948_abs[];
#pragma alias FUN_00456410_noarg FUN_00456410
#pragma alias FUN_004c6ac0_vec FUN_004c6ac0
extern float FUN_004c6ac0_vec(const RwV3d *param_1);
#pragma alias FUN_001124b0_u32 FUN_001124b0
extern void FUN_001124b0_u32(u32 param_1);
#pragma alias iGpffffb9fc_ptr iGpffffb9fc
extern u8 *iGpffffb9fc_ptr;
#pragma alias DAT_0096017c_task DAT_0096017c
extern void (*DAT_0096017c_task[])(u32);
#pragma alias FUN_00100ec0_arg FUN_00100ec0
extern void FUN_00100ec0_arg(u32 param_1);
#pragma alias FUN_004d0f00_arg FUN_004d0f00
#pragma alias DAT_0086e6a0_rows DAT_0086e6a0
extern u8 DAT_0086e6a0_rows[][0x1c0];
extern void FUN_004d0f00_arg(u32 param_1);
extern void FUN_00456410_noarg(void);
#pragma alias DAT_0096017c_abs DAT_0096017c
extern code DAT_0096017c_abs[];
extern code DAT_00960184;
#pragma alias DAT_00960184_abs DAT_00960184
extern code DAT_00960184_abs[];
#pragma alias FUN_00194b80_u32 FUN_00194b80
extern u32 FUN_00194b80_u32(u64, u32, u8 *, u32 (*)(int), void (*)(int), u32);
extern u32 PTR_DAT_006b46f0;
extern u32 PTR_DAT_006b4720;
extern u32 PTR_DAT_006b4de0;
extern u32 PTR_FUN_006b4e60;
extern u8 cGpffffb9cc;
extern u32 fGpffff8110;
extern f32 fGpffff8248;
extern u32 fGpffff82d8;
extern u32 gp0xffffae24;
extern u32 gp0xffffb9f7;
extern u32 iGpffffb418;
extern u32 iGpffffb5a0;
extern u32 iGpffffb9fc;
extern u32 iGpffffba08;
extern u32 iGpffffba20;
extern u32 iGpffffba24;
extern float uGpffff82b8;
extern float uGpffff82d0;
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

extern u32 FUN_00100d80(u32 param_1, int param_2);
#pragma alias FUN_00100d80_ptr FUN_00100d80
extern u32 FUN_00100d80_ptr(const char *param_1, int param_2);
extern code FUN_00100ec0;
extern code FUN_001016b0;
#pragma alias FUN_001016b0_typed FUN_001016b0
extern s32 FUN_001016b0_typed(void *cdvd);
extern code FUN_00102100;
#pragma alias FUN_00102100_typed FUN_00102100
extern void *FUN_00102100_typed(void *cdvd, s32 fileIdx, u32 *fileSize);
extern void FUN_001023a0(u32 param_1);
extern int FUN_00108570(void);
extern int FUN_001085c0(void);
extern code FUN_00108670;
#pragma alias FUN_00108670_typed FUN_00108670
extern void FUN_00108670_typed(s16 type);
extern int FUN_00108710(void);
extern code FUN_00108fd0;
#pragma alias FUN_00108fd0_va FUN_00108fd0
extern void FUN_00108fd0_va(u32 value, ...);
extern void FUN_0010a4e0(int param_1, int param_2, int param_3, int param_4);
extern u32 FUN_0010c1a0(int param_1, u32 param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8);
extern u32 FUN_0010c3a0(u32 param_1, int *param_2, int param_3);
extern code FUN_00111f30;
#pragma alias FUN_00111f30_typed FUN_00111f30
extern s32 FUN_00111f30_typed(void *maestroBlob);
#pragma alias FUN_00111f30_long FUN_00111f30
extern s32 FUN_00111f30_long(void *maestroBlob);
extern code FUN_001120c0;
#pragma alias FUN_001120c0_typed FUN_001120c0
extern void FUN_001120c0_typed(void);
extern code FUN_00112370;
#pragma alias FUN_00112370_typed FUN_00112370
extern u32 FUN_00112370_typed(const char *path);
extern code FUN_00112420;
#pragma alias FUN_00112420_typed FUN_00112420
extern void *FUN_00112420_typed(void *source);
extern code FUN_001124b0;
extern code FUN_001126b0;
extern code FUN_00112740;
extern void FUN_001127d0(u32 param_1, u32 param_2);
extern code FUN_00113a30;
#pragma alias FUN_00113a30_va FUN_00113a30
extern void FUN_00113a30_va(f32 first, ...);
extern void FUN_001140d0(u32 param_1, u32 param_2, u32 param_3, u64 param_4, u32 param_5, u32 param_6, u32 param_7);
extern u32 FUN_001158b0(int param_1, u32 param_2, u32 param_3);
#pragma alias FUN_00115980_arg FUN_00115980
extern void FUN_00115980(u32 param_1);
extern void FUN_00115980_arg(u32 param_1);
#pragma alias FUN_001159f0_va FUN_001159f0
extern void FUN_001159f0_va(f32 first, ...);
#pragma alias FUN_001159f0_3f FUN_001159f0
extern void FUN_001159f0_3f(f32 x, f32 y, f32 depth);
#pragma alias FUN_001159f0_3fv FUN_001159f0
extern void FUN_001159f0_3fv(f32 x, f32 y, f32 depth, ...);
#pragma alias FUN_00115bc0_3fv FUN_00115bc0
extern void FUN_00115bc0_3fv(f32 x, f32 y, f32 depth, ...);
#pragma alias FUN_00115bc0_3f FUN_00115bc0
extern void FUN_00115bc0_3f(f32 x, f32 y, f32 depth);
extern code FUN_001159f0;
extern code FUN_00115bc0;
#pragma alias FUN_00115bc0_va FUN_00115bc0
extern void FUN_00115bc0_va(f32 first, ...);
extern u8 FUN_0016c470(s16 id);
extern short FUN_0016c4f0(u16 param_1);
extern code FUN_0016c570;
extern code FUN_0016c5f0;
#pragma alias FUN_0016c5f0_typed FUN_0016c5f0
extern u16 FUN_0016c5f0_typed(s16 pcId);
extern code FUN_0016c920;
#pragma alias FUN_0016c920_typed FUN_0016c920
extern s16 FUN_0016c920_typed(u16 id);
extern u32 FUN_0016c970(u16 param_1);
extern code FUN_0016cf40;
#pragma alias FUN_0016cf40_typed FUN_0016cf40
extern void FUN_0016cf40_typed(s16 pcId, s16 hp);
extern code FUN_0016cf90;
#pragma alias FUN_0016cf90_typed FUN_0016cf90
extern void FUN_0016cf90_typed(s16 pcId, s16 sp);
extern code FUN_0016f190;
#pragma alias FUN_0016f190_typed FUN_0016f190
extern s32 FUN_0016f190_typed(s32 flag);
extern code FUN_0016f1f0;
#pragma alias FUN_0016f1f0_typed FUN_0016f1f0
extern void FUN_0016f1f0_typed(s32 flag, int enabled);
extern code FUN_0016f490;
#pragma alias FUN_0016f490_typed FUN_0016f490
extern s32 FUN_0016f490_typed(s16 pcId);
extern code FUN_00170a40;
#pragma alias FUN_00170a40_typed FUN_00170a40
extern u16 FUN_00170a40_typed(s16 pcId, s16 index);
extern code FUN_00170ab0;
#pragma alias FUN_00170ab0_typed FUN_00170ab0
extern s16 FUN_00170ab0_typed(s16 pcId, s16 index);
extern code FUN_00170b20;
#pragma alias FUN_00170b20_typed FUN_00170b20
extern void FUN_00170b20_typed(s16 pcId, s16 index, u16 value);
extern code FUN_00170b90;
#pragma alias FUN_00170b90_typed FUN_00170b90
extern void FUN_00170b90_typed(s16 pcId, s16 index, u16 value);
extern int FUN_00173300(void);
extern code FUN_00173380;
#pragma alias FUN_00173380_typed FUN_00173380
extern u16 *FUN_00173380_typed(u16 param_1);
extern code FUN_00177410;
#pragma alias FUN_00177410_typed FUN_00177410
extern void FUN_00177410_typed(u8 *param_1, u8 *param_2);
extern code FUN_0017b500;
#pragma alias FUN_0017b500_ret FUN_0017b500
extern short FUN_0017b500_ret(s16 player, u64 value);
extern s32 FUN_0017b5b0(u32 param_1, u32 param_2);
extern code FUN_0017b660;
#pragma alias FUN_0017b660_2arg FUN_0017b660
extern long FUN_0017b660_2arg(u16 param_1, u16 param_2);
#pragma alias FUN_0017b660_1arg FUN_0017b660
extern long FUN_0017b660_1arg(u16 param_1);
extern code FUN_0017b860;
#pragma alias FUN_0017b860_typed FUN_0017b860
extern s32 FUN_0017b860_typed(s16 player, s16 sourcePlayer, u64 id, u64 value);
extern void FUN_0017be10(int param_1, int param_2, u16 param_3, int param_4, void *param_5, void *param_6, void *param_7);
extern code FUN_001831e0;
#pragma alias FUN_001831e0_typed FUN_001831e0
extern void FUN_001831e0_typed(s16 param_1, u32 param_2, int param_3);
extern code FUN_0018bee0;
#pragma alias FUN_0018bee0_typed FUN_0018bee0
extern void FUN_0018bee0_typed(u32 param_1, u16 param_2, int param_3);
extern code FUN_0018c0c0;
#pragma alias FUN_0018c0c0_typed FUN_0018c0c0
extern void FUN_0018c0c0_typed(u32 object, s32 enabled);
extern code FUN_0018eb30;
#pragma alias FUN_0018eb30_typed FUN_0018eb30
extern void FUN_0018eb30_typed(u32 object, s32 enabled);
extern code FUN_00194b20;
#pragma alias FUN_00194b20_u32 FUN_00194b20
extern u32 FUN_00194b20_u32(u64, u8 *, u32, u32 (*)(int), void (*)(int), u32);
extern code FUN_00194b80;
extern code FUN_00195020;
extern long FUN_00195460(u32 param_1);
extern code FUN_00198590;
#pragma alias FUN_00198590_typed FUN_00198590
extern int FUN_00198590_typed(void);
extern code FUN_001a0040;
#pragma alias FUN_001a0040_typed FUN_001a0040
extern void FUN_001a0040_typed(u32 visible, u32 updateField);
extern int FUN_001a0250(void);
extern int FUN_001a02c0(void);
extern code FUN_001a0dc0;
#pragma alias FUN_001a0dc0_typed FUN_001a0dc0
extern void FUN_001a0dc0_typed(u16 resTypeId, u32 visible);
extern code FUN_001a5320;
#pragma alias FUN_001a5320_typed FUN_001a5320
extern u32 FUN_001a5320_typed(u32 param_1);
extern code FUN_001a56b0;
#pragma alias FUN_001a56b0_typed FUN_001a56b0
extern void FUN_001a56b0_typed(u32 param_1, int param_2);
extern code FUN_001a56c0;
#pragma alias FUN_001a56c0_typed FUN_001a56c0
extern void FUN_001a56c0_typed(u32 param_1, u32 param_2);
extern code FUN_001a56d0;
#pragma alias FUN_001a56d0_typed FUN_001a56d0
extern void FUN_001a56d0_typed(u32 param_1, void *param_2);
extern code FUN_001a5700;
#pragma alias FUN_001a5700_typed FUN_001a5700
extern void FUN_001a5700_typed(u32 param_1, void *param_2);
extern code FUN_001a57a0;
#pragma alias FUN_001a57a0_typed FUN_001a57a0
extern void FUN_001a57a0_typed(u32 param_1, u32 param_2, u32 param_3);
extern code FUN_001a5aa0;
#pragma alias FUN_001a5aa0_typed FUN_001a5aa0
extern f32 FUN_001a5aa0_typed(const void *matrix);
extern code FUN_001a91b0;
extern code FUN_001a9390;
#pragma alias FUN_001a9390_typed FUN_001a9390
extern void FUN_001a9390_typed(void *task, s32 index, u16 value);
extern code FUN_001a9760;
#pragma alias FUN_001a9760_typed FUN_001a9760
extern void FUN_001a9760_typed(void *task, u32 value, void *position, u32 sound, u32 flags);
extern code FUN_001aaa20;
#pragma alias FUN_001aaa20_typed FUN_001aaa20
extern void *FUN_001aaa20_typed(void *parent, u32 value);
extern code FUN_001aaac0;
#pragma alias FUN_001aaac0_typed FUN_001aaac0
extern void FUN_001aaac0_typed(void *task, u32 value);
extern code FUN_001acc30;
#pragma alias FUN_001acc30_typed FUN_001acc30
extern u32 FUN_001acc30_typed(void *param_1, void *param_2);
extern code FUN_001ad870;
#pragma alias FUN_001ad870_typed FUN_001ad870
extern void FUN_001ad870_typed(void *collisCtlTask, u32 flags);
extern int FUN_001ad910(u32 param_1);
extern int FUN_001ad920(u32 param_1);
extern void FUN_001ad940(void *param_1, u32 param_2);
extern code FUN_001adc20;
#pragma alias FUN_001adc20_typed FUN_001adc20
extern void FUN_001adc20_typed(void *collisCtlTask, const void *position);
extern code FUN_001adff0;
extern code FUN_001af930;
#pragma alias FUN_001af930_typed FUN_001af930
extern void *FUN_001af930_typed(void *parent, void *resource);
extern code FUN_001afa20;
#pragma alias FUN_001afa20_typed FUN_001afa20
extern u32 FUN_001afa20_typed(f32 duration, void *task, void *position);
extern code FUN_001aff70;
#pragma alias FUN_001aff70_typed FUN_001aff70
extern u32 FUN_001aff70_typed(void *task, s32 duration);
extern code FUN_001b0020;
#pragma alias FUN_001b0020_typed FUN_001b0020
extern void FUN_001b0020_typed(u32 param_1, void *param_2, s32 param_3);
extern void FUN_001b00c0(u32 param_1);
extern code FUN_001b01b0;
#pragma alias FUN_001b01b0_typed FUN_001b01b0
extern u32 *FUN_001b01b0_typed(void *task, s32 index);
extern code FUN_001b01d0;
#pragma alias FUN_001b01d0_typed FUN_001b01d0
extern void FUN_001b01d0_typed(void *task, s32 index, const void *point);
extern long FUN_001b0220(u32 param_1);
extern code FUN_001b0230;
#pragma alias FUN_001b0230_typed FUN_001b0230
extern void FUN_001b0230_typed(void *task, s32 pointCount);
extern void FUN_001b0240(u32 param_1, int param_2);
extern code FUN_001b0250;
#pragma alias FUN_001b0250_typed FUN_001b0250
extern void FUN_001b0250_typed(u32 param_1, int param_2);
extern void FUN_001b0260(u32 param_1, int param_2);
extern code FUN_001b9120;
extern void FUN_001bf220(void *param_1, u16 param_2, u16 param_3);
extern long FUN_001c6450(u32 param_1, u32 param_2, u32 param_3, void *param_4);
 #pragma alias FUN_001c6450_typed FUN_001c6450
 extern u32 FUN_001c6450_typed(u32 param_1,void *param_2,float param_3,float param_4);
 #pragma alias FUN_001c6450_f32 FUN_001c6450
 extern u32 FUN_001c6450_f32(u32 param_1,void *param_2,float param_3,float param_4);
extern code FUN_001c65e0;
#pragma alias FUN_001c65e0_typed FUN_001c65e0
 #pragma alias FUN_001c6720_u32 FUN_001c6720
 extern u32 FUN_001c6720_u32(u32 param_1,u32 param_2);
extern u32 FUN_001c65e0_typed(void *param_1);
extern long FUN_001c6720(u32 param_1, u32 param_2);
extern code FUN_001c6d70;
extern code FUN_001c6dd0;
#pragma alias FUN_001c6d70_typed FUN_001c6d70
extern long FUN_001c6d70_typed(u32 param_1, void *param_2);
#pragma alias FUN_001c6dd0_typed FUN_001c6dd0
extern long FUN_001c6dd0_typed(u32 param_1, void *param_2);
extern long FUN_001c7130(u32 param_1, u32 param_2);
#pragma alias FUN_001c7160_f32 FUN_001c7160
extern long FUN_001c7160_f32(f32 param_1, void *param_2, void *param_3);
extern long FUN_001c7160(u32 param_1, void *param_2, void *param_3);
#pragma alias FUN_001c7160_i32 FUN_001c7160
extern int FUN_001c7160_i32(u32 param_1, void *param_2, void *param_3);
 #pragma alias FUN_001c7270_u32 FUN_001c7270
 extern u32 FUN_001c7270_u32(u32 param_1,u32 param_2);
extern code FUN_001c7b10;
#pragma alias FUN_001c7b10_typed FUN_001c7b10
extern u32 FUN_001c7b10_typed(const void *fldUnit);
extern void FUN_001cd670(u32 param_1, int param_2);
extern code FUN_001d0110;
#pragma alias FUN_001d0110_typed FUN_001d0110
extern void FUN_001d0110_typed(void *unit);
extern code FUN_001d22a0;
#pragma alias FUN_001d22a0_typed FUN_001d22a0
extern void FUN_001d22a0_typed(void *work);
extern void FUN_001d3810(u32 param_1, int param_2);
extern code FUN_001d8b00;
#pragma alias FUN_001d8b00_typed FUN_001d8b00
extern void *FUN_001d8b00_typed(void *parent, void *pc, void *ec);
extern code FUN_001d8c60;
#pragma alias FUN_001d8c60_typed FUN_001d8c60
extern void FUN_001d8c60_typed(u32 paused);
extern long FUN_001d8d80(u32 param_1);
extern code FUN_001d8e60;
#pragma alias FUN_001d8e60_typed FUN_001d8e60
extern u32 FUN_001d8e60_typed(void *owner, void *pc, void *ec);
extern code FUN_001dde00;
#pragma alias FUN_001dde00_typed FUN_001dde00
extern u32 FUN_001dde00_typed(s32 mode);
extern code FUN_001ded40;
#pragma alias FUN_001ded40_typed FUN_001ded40
extern s32 FUN_001ded40_typed(s32 charId);
extern void FUN_001e1360(u32 param_1, int param_2);
extern code FUN_001e13c0;
#pragma alias FUN_001e13c0_typed FUN_001e13c0
extern f32 FUN_001e13c0_typed(void);
extern code FUN_00269690;
#pragma alias FUN_00269690_typed FUN_00269690
extern u32 FUN_00269690_typed(s32 mode, s32 index, u32 flags);
extern code FUN_002699a0;
#pragma alias FUN_002699a0_typed FUN_002699a0
extern void FUN_002699a0_typed(u32 param_1);
extern code FUN_002699d0;
#pragma alias FUN_002699d0_typed FUN_002699d0
extern void FUN_002699d0_typed(u32 param_1);
extern code FUN_00269a10;
#pragma alias FUN_00269a10_typed FUN_00269a10
extern void FUN_00269a10_typed(u32 param_1, void *param_2);
extern code FUN_00269c80;
extern code FUN_00269ca0;
extern code FUN_002ff340;
#pragma alias FUN_002ff340_typed FUN_002ff340
extern void *FUN_002ff340_typed(u16 pcId);
extern code FUN_002ff760;
extern code FUN_002ff790;
#pragma alias FUN_002ff790_typed FUN_002ff790
extern u32 FUN_002ff790_typed(void *genusBase);
extern code FUN_00316e00;
#pragma alias FUN_00316e00_typed FUN_00316e00
extern u32 FUN_00316e00_typed(u16 type, u16 id, u32 readMode);
extern code FUN_00316f70;
#pragma alias FUN_00316f70_typed FUN_00316f70
extern s32 FUN_00316f70_typed(s32 param_1);
extern code FUN_003174e0;
extern u64 FUN_003182d0(u32 param_1, u32 param_2, u64 param_3, u64 param_4, u64 param_5);
extern code FUN_00318540;
#pragma alias FUN_00318540_typed FUN_00318540
extern s16 FUN_00318540_typed(void *mdl, u16 slotIdx);
extern int FUN_00318b60(u32 param_1);
extern code FUN_00318ed0;
#pragma alias FUN_00318ed0_typed FUN_00318ed0
extern s32 FUN_00318ed0_typed(u32 param_1, int param_2, float *param_3);
extern code FUN_0031c1d0;
#pragma alias FUN_0031c1d0_typed FUN_0031c1d0
extern void FUN_0031c1d0_typed(u32 model);
extern code FUN_0035bb40;
#pragma alias FUN_0035bb40_typed FUN_0035bb40
extern u32 FUN_0035bb40_typed(s32 type, u32 list, s32 index);
extern code FUN_0035bc00;
extern code FUN_0035c1a0;
#pragma alias FUN_0035c1a0_typed FUN_0035c1a0
extern void FUN_0035c1a0_typed(u32 task, s32 value);
extern code FUN_003952d0;
#pragma alias FUN_003952d0_typed FUN_003952d0
extern u64 FUN_003952d0_typed(u64 param_1, int param_2, s16 param_3);
extern code FUN_003b2cb0;
#pragma alias FUN_003b2cb0_va FUN_003b2cb0
extern void FUN_003b2cb0_va(f32 first, ...);
extern code FUN_003b5d10;
#pragma alias FUN_003b5d10_eb90 FUN_003b5d10
extern u32 FUN_003b5d10_eb90(u32 param_1);
extern code FUN_003b5d50;
#pragma alias FUN_003b5d50_typed FUN_003b5d50
extern void *FUN_003b5d50_typed(u32 resType);
extern code FUN_003b6030;
#pragma alias FUN_003b6030_typed FUN_003b6030
extern u16 FUN_003b6030_typed(u16 resId, s32 param_2, void *mdl);
extern code FUN_003b7090;
extern code FUN_003bb010;
#pragma alias FUN_003bb010_typed FUN_003bb010
extern u32 FUN_003bb010_typed(u64 param_1, u32 param_2);
extern code FUN_003c72d0;
extern code FUN_003c7430;
extern code FUN_003c74e0;
extern code FUN_003c7560;
extern code FUN_003c75b0;
extern code FUN_003c77a0;
extern code FUN_003c7850;
extern code FUN_003c78d0;
extern code FUN_003c7b90;
extern float FUN_00421fe0(int param_1, int param_2, int param_3, u16 param_4, int param_5);
extern float FUN_004221a0(float param_1, float param_2, float param_3, float param_4, int param_5);
extern code FUN_004222d0;
#pragma alias FUN_004222d0_typed FUN_004222d0
extern void FUN_004222d0_typed(float *param_1,char param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,short param_8);
extern u32 FUN_004229d0(int param_1, u64 param_2, int param_3);
extern void FUN_00422c10(u32 param_1, int param_2);
extern void FUN_00422c30(u32 param_1, u64 param_2, void *param_3);
extern void FUN_00422c90(u32 param_1, int param_2, int param_3, int param_4, int param_5);
extern code FUN_00423fe0;
#pragma alias FUN_00423fe0_typed FUN_00423fe0
extern void FUN_00423fe0_typed(float *param_1, char param_2, short param_3, short param_4, short param_5, short param_6);
extern code FUN_00427830;
#pragma alias FUN_00427830_typed FUN_00427830
extern u64 FUN_00427830_typed(float param_1,int param_2,u32 param_3,u64 param_4,u32 param_5,
                               char *param_6,char *param_7,int param_8);
extern code FUN_00427a10;
#pragma alias FUN_00427a10_typed FUN_00427a10
extern u64 FUN_00427a10_typed(float param_1,int param_2,u32 param_3,u64 param_4,u32 param_5,
                               char *param_6,char *param_7,int param_8);
extern code FUN_00427db0;
#pragma alias FUN_00427db0_typed FUN_00427db0
extern void FUN_00427db0_typed(int object, u64 value);
extern code FUN_00427de0;
#pragma alias FUN_00427de0_typed FUN_00427de0
extern void FUN_00427de0_typed(int param_1,u8 param_2,u8 param_3,u8 param_4, u8 param_5);
extern code FUN_00427e20;
#pragma alias FUN_00427e20_typed FUN_00427e20
extern void FUN_00427e20_typed(float param_1,float param_2,u32 param_3);
extern void FUN_00427e50(u32 param_1, int param_2);
extern code FUN_00427e60;
#pragma alias FUN_00427e60_typed FUN_00427e60
extern void FUN_00427e60_typed(int param_1, u8 param_2);
extern code FUN_00427e70;
#pragma alias FUN_00427e70_typed FUN_00427e70
extern void FUN_00427e70_typed(float param_1,float param_2,float param_3,u32 param_4,int param_5,
                               int param_6,u32 param_7);
extern code FUN_00429e80;
#pragma alias FUN_00429e80_typed FUN_00429e80
extern void FUN_00429e80_typed(int param_1, u8 param_2);
extern int FUN_00488f30(void);
extern code FUN_004c31b0;
#pragma alias FUN_004c31b0_ym FUN_004c31b0
extern void FUN_004c31b0_ym(f32 angle, void *matrix, const void *axis, u32 mode);
extern code FUN_004c3880;
#pragma alias FUN_004c3880_typed FUN_004c3880
extern void FUN_004c3880_typed(u32 param_1);
extern code FUN_004c38c0;
#pragma alias FUN_004c38c0_typed FUN_004c38c0
extern u32 FUN_004c38c0_typed(void);
extern float FUN_004c69f0(float *param_1, float *param_2);
extern code FUN_004c6ac0;
extern code FUN_004c6be0;
#pragma alias FUN_004c6be0_typed FUN_004c6be0
extern void FUN_004c6be0_typed(float *out, const float *basis, void *source);
extern code FUN_004d0f00;
extern u32 FUN_004d1260(u32 param_1, int param_2);
#pragma alias FUN_004d1260_ptr FUN_004d1260
extern u32 FUN_004d1260_ptr(const char *param_1, int param_2);
extern code FUN_004d7f60;
#pragma alias FUN_004d7f60_typed FUN_004d7f60
extern void FUN_004d7f60_typed(u32 param_1, u32 param_2);
extern code FUN_00521250;
#pragma alias FUN_00521250_typed FUN_00521250
extern void FUN_00521250_typed(void *destination, const void *source, u32 size);
extern code FUN_00521408;
extern code FUN_00523e68;
extern code FUN_00524388;
#pragma alias FUN_00524388_str FUN_00524388
extern u32 FUN_00524388_str(const char *param_1);
extern code FUN_00524670;
#pragma alias FUN_00524670_typed FUN_00524670
extern int FUN_00524670_typed(u64 param_1, u8 (*param_2)[16], u32 param_3);
extern void FUN_00524828(void *param_1, void *param_2, int param_3);
#pragma alias FUN_00524828_u64 FUN_00524828
extern void FUN_00524828_u64(void *param_1,u64 param_2,int param_3);
extern code FUN_0052e878;
extern code FUN_0052ea18;
#pragma alias FUN_00269c80_f32 FUN_00269c80
extern f32 FUN_00269c80_f32(f32 value);
#pragma alias FUN_00269ca0_f32 FUN_00269ca0
extern f32 FUN_00269ca0_f32(f32 value);
#pragma alias FUN_0052ea18_f32 FUN_0052ea18
extern f32 FUN_0052ea18_f32(f32 x, f32 y);

char FUN_00435440(char param_1);
char FUN_0043bc20(char param_1);
float FUN_0045b4e0(int param_1);
float FUN_004693a0(int param_1);
float FUN_0047cfd0(u32 *param_1,u8 (*param_2) [12],u8 (*param_3) [12], int param_4,int param_5);
float FUN_004a9560(float param_1,int param_2,u8 *param_3);
float FUN_004aa2c0(void);
int * FUN_00496cd0(u32 param_1,u32 *param_2,u64 param_3,u16 *param_4);
int * FUN_004ac120(int *param_1,u64 param_2);
int * FUN_004ac240(int *param_1);
int FUN_0044f120(RwV3d param_1);
int FUN_0044f170(RwV3d param_1);
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
short FUN_00453460(void);
u32 * FUN_0048f580(u64 param_1,int *param_2,int param_3,u32 param_4);
u32 * FUN_0048fbd0(u64 param_1,u64 param_2,u64 param_3,u32 param_4);
u32 * FUN_004a7e40(u32 *param_1,u32 param_2,u32 param_3,char *param_4);
u32 * FUN_004a8980(u32 *param_1,u64 param_2,u32 param_3,u64 param_4);
u32 * FUN_004a90f0(void);
u32 * FUN_004a9a80(u64 param_1);
u32 * FUN_004ab8c0(void);
u32 FUN_00431880(int param_1);
u32 FUN_00431aa0(int param_1);
u32 FUN_00432050(int param_1);
u32 FUN_00432600(int param_1);
u32 FUN_00432bb0(int param_1);
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
u32 FUN_0043ca30(int param_1);
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
u32 FUN_0045a280(int param_1,int param_2);
u32 FUN_0045af40(void);
u32 FUN_0045afd0(float param_1,long param_2,int param_3,int param_4,int param_5,int param_6, u8 param_7,u8 param_8,short param_9);
u32 FUN_0045b190(long param_1);
u32 FUN_0045b420(int param_1,float *param_2);
u32 FUN_0045df00(int param_1);
u32 FUN_0045e3e0(int param_1);
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
u32 FUN_00430180(u64 param_1);
u64 FUN_00430060(int param_1);
u64 FUN_00430bb0(int param_1);
u32 FUN_00431110(u64 param_1,YajimaVec2 param_2,char param_3,u8 param_4);
u64 FUN_004312b0(int param_1);
u32 FUN_00431670(int param_1,char param_2,u32 param_3);
u64 FUN_00439f60(u64 param_1,char param_2);
u64 FUN_0043a0b0(u64 param_1,char param_2);
u32 FUN_0043c690(u32 param_1);
u32 FUN_00447e70(u64 param_1,u8 param_2,u8 param_3);
u64 FUN_0044aaf0(int param_1);
u64 FUN_0044ad20(u64 param_1,char param_2);
u64 FUN_0044e560(int param_1);
u32 FUN_004542c0(char param_1);
u64 FUN_00454620(char param_1);
u64 FUN_00455e00(u64 param_1);
u64 FUN_004560d0(u32 param_1,float param_2,float param_3,float param_4,u32 param_5,u32 param_6);
u32 FUN_004579b0(u64 param_1);
u64 FUN_00457a40(u64 param_1);
u64 FUN_00458630(u64 param_1,char param_2,u8 param_3);
u32 FUN_00459f60(u64 param_1,u16 param_2,char param_3);
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
u32 FUN_00435260(char param_1);
s8 FUN_004353f0(int param_1);
u8 FUN_00435810(void);
u8 FUN_004359f0(int param_1,u8 param_2,u8 param_3,u32 *param_4, u8 param_5,u8 param_6);
u8 FUN_0043c730(char param_1);
u8 FUN_0043c7f0(char param_1);
char FUN_00449c90(u64 param_1,char param_2);
u8 FUN_0044a420(int param_1,int param_2,int param_3);
u32 FUN_0044f060(float param_1,int param_2,float *param_3);
u32 FUN_0044f1c0(float param_1,float *param_2,float *param_3);
u8 FUN_0044fab0(int param_1);
char FUN_00453480(void);
u8 FUN_00454400(u32 *param_1,char param_2);
u8 FUN_00454520(float *param_1,char param_2);
u8 FUN_00454a70(char param_1,float *param_2);
u8 FUN_00454d00(float *param_1);
char FUN_00457390(char param_1);
char FUN_004573d0(char param_1);
int FUN_0045a3b0(void);
u8 FUN_0045af90(int param_1);
int FUN_0045b480(int param_1);
int FUN_0045b4b0(int param_1);
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
void FUN_00430270(RwV4d* output, int object);
void FUN_004302a0(int param_1);
void FUN_004302b0(void);
void FUN_00430630(int param_1);
void FUN_00430780(u64 param_1,int param_2,int param_3,int param_4);
void FUN_00430a40(char param_1);
void FUN_004310e0(int param_1);
void FUN_004311f0(void *param_1,int param_2,int param_3);
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
void FUN_00435c00(int param_1);
void FUN_00437e00(void);
void FUN_00437e80(u32 *param_1,char param_2);
void FUN_00438010(int param_1);
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
void FUN_00448060(int param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6);
void FUN_00448cf0(int param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6,int param_7);
void FUN_00449d10(int param_1);
void FUN_00449d60(u64 param_1);
void FUN_00449ed0(void);
void FUN_00449fa0(void);
void FUN_0044a240(float param_1,float param_2,float param_3,float param_4,int param_5 ,char param_6);
void FUN_0044a330(float param_1,float param_2,float param_3,float param_4,int param_5 ,char param_6);
void FUN_0044a630(int param_1);
void FUN_0044a790(u32 *param_1);
void FUN_0044a990(int param_1,u32 *param_2);
void FUN_0044acf0(int param_1);
void FUN_0044af60(u64 param_1);
void FUN_0044b7d0(int param_1);
void FUN_0044beb0(int param_1);
void FUN_0044d600(int param_1);
void FUN_0044dfc0(int param_1);
void FUN_0044e530(int param_1,u8 param_2);
void FUN_0044f270(float *param_1,float *param_2);
#pragma alias FUN_0044f270_ret FUN_0044f270
extern u32 FUN_0044f270_ret(float *param_1, float *param_2);
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
void FUN_004561d0(float param_1,float param_2,int param_3);
void FUN_004561f0(float param_1,int param_2);
void FUN_004563b0(f32 param_1, int param_2);
void FUN_004563c0(int param_1,u8 param_2);
void FUN_004563d0(int object, RwV2d value);
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
void FUN_00456a90(u32 param_1,char param_2,char param_3);
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
void FUN_0045bcb0(int param_1,u64 param_2);
void FUN_0045bd90(u64 param_1);
void FUN_0045c530(int param_1);
void FUN_0045c8c0(int param_1,int param_2);
void FUN_0045cdd0(int param_1,long param_2);
void FUN_0045ce90(int param_1);
void FUN_0045d990(int param_1,long param_2);
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
extern float DAT_007cafa8;
extern float DAT_007cafc0;
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
extern u32 DAT_007ce710;
extern u32 DAT_007ce718;
extern u32 DAT_007e094e;
extern u32 DAT_007e0952;
extern u32 DAT_007e0958;
extern u32 DAT_007e095a;
extern u32 DAT_0086be00;
extern u32 DAT_0086e6e8;
extern u8 DAT_0086e6a0[];
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
#pragma alias DAT_0095c220_abs DAT_0095c220
extern u8 DAT_0095c220_abs[];
extern u32 DAT_0095c221;
extern u32 DAT_0095c23e;
extern u32 DAT_0095c23f;
extern u32 DAT_0095c240;
#pragma alias DAT_0095c240_abs DAT_0095c240
extern u8 DAT_0095c240_abs[];
extern u32 DAT_0095c241;
extern f32 DAT_00960088;
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
extern f32 fGpffff8248;
extern u32 fGpffff82d8;
extern u32 gp0xffffae24;
extern u32 gp0xffffb9f7;
extern u32 iGpffffb418;
extern u32 iGpffffb5a0;
extern u32 iGpffffb9fc;
extern u32 iGpffffba08;
extern u32 iGpffffba20;
extern u32 iGpffffba24;
extern float uGpffff82b8;
extern float uGpffff82d0;
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

extern code FUN_00100ec0;
extern code FUN_001016b0;
extern code FUN_00102100;


extern code FUN_00108670;

extern code FUN_00108f70;
extern code FUN_00108fd0;
extern code FUN_00109040;
extern code FUN_00111f30;
extern code FUN_001120c0;
#pragma alias FUN_001126b0_typed FUN_001126b0
extern f32 FUN_001126b0_typed(void *particle);
#pragma alias FUN_00112740_typed FUN_00112740
extern f32 FUN_00112740_typed(void *particle);
#pragma alias FUN_0016c570_typed FUN_0016c570
extern u32 FUN_0016c570_typed(u16 id);
#pragma alias FUN_0052e878_typed FUN_0052e878
extern f32 FUN_0052e878_typed(f32 angle);
extern code FUN_00112370;
extern code FUN_00112420;
extern code FUN_001124b0;
extern code FUN_001126b0;
extern code FUN_00112740;
extern code FUN_00113a30;

extern code FUN_001159f0;
extern code FUN_00115bc0;
extern u8 FUN_0016c470(s16 id);
extern code FUN_0016c570;
extern code FUN_0016c5f0;
extern code FUN_0016c920;
extern code FUN_0016cf40;
extern code FUN_0016cf90;
extern code FUN_0016f190;
extern code FUN_0016f1f0;
extern code FUN_0016f490;
extern code FUN_00170a40;
extern code FUN_00170ab0;
extern code FUN_00170b20;
extern code FUN_00170b90;

extern code FUN_00173380;
extern code FUN_00177410;
extern code FUN_0017b500;
extern code FUN_0017b660;
extern code FUN_0017b860;
extern code FUN_001831e0;
extern code FUN_0018bee0;
extern code FUN_0018c0c0;
extern code FUN_0018eb30;
extern code FUN_00194b20;
extern code FUN_00194b80;
extern code FUN_00195020;
extern code FUN_00195290;
extern code FUN_00198590;
extern code FUN_001a0040;


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
extern code FUN_001adc20;
extern code FUN_001adff0;
extern code FUN_001af930;
extern code FUN_001aff70;
extern code FUN_001b0020;
extern code FUN_001b01b0;
extern code FUN_001b01d0;
extern code FUN_001b0230;
extern code FUN_001b0250;
extern code FUN_001b9120;
extern code FUN_001c65e0;
extern code FUN_001c6d70;
extern code FUN_001c6dd0;
extern code FUN_001c7270;
extern code FUN_001c7b10;
extern code FUN_001d0110;
extern code FUN_001d22a0;
extern code FUN_001d8b00;
extern code FUN_001d8c60;
extern code FUN_001d8e60;
extern code FUN_001dde00;
extern code FUN_001ded40;
extern code FUN_001e13c0;
extern code FUN_00269690;
extern code FUN_002699a0;
extern code FUN_002699d0;
extern code FUN_00269a10;
extern code FUN_00269c80;
extern code FUN_00269ca0;
extern code FUN_002ff340;
extern code FUN_002ff760;
extern code FUN_00316e00;
extern code FUN_00316f70;
extern code FUN_003174e0;
extern code FUN_00318540;
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
extern code FUN_004222d0;
extern code FUN_00423fe0;
extern code FUN_00427830;
extern code FUN_00427a10;
extern code FUN_00427db0;
extern code FUN_00427de0;
extern code FUN_00427e20;
extern code FUN_00427e60;
extern code FUN_00427e70;
extern code FUN_00429e80;
extern code FUN_00469DC0;
extern code FUN_00474630;
extern code FUN_00488dd0;
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
extern code FUN_0052e6d8;
extern code FUN_0052e878;
extern code FUN_0052ea18;
extern code FUN_005316d0;

char FUN_00435440(char param_1);
char FUN_0043bc20(char param_1);
float FUN_0045b4e0(int param_1);
float FUN_004693a0(int param_1);
float FUN_0047cfd0(u32 *param_1,u8 (*param_2) [12],u8 (*param_3) [12], int param_4,int param_5);
float FUN_004a9560(float param_1,int param_2,u8 *param_3);
float FUN_004aa2c0(void);
int * FUN_00496cd0(u32 param_1,u32 *param_2,u64 param_3,u16 *param_4);
int * FUN_004ac120(int *param_1,u64 param_2);
int * FUN_004ac240(int *param_1);
int FUN_0044f120(RwV3d param_1);
int FUN_0044f170(RwV3d param_1);
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
short FUN_00453460(void);
u32 * FUN_0048f580(u64 param_1,int *param_2,int param_3,u32 param_4);
u32 * FUN_0048fbd0(u64 param_1,u64 param_2,u64 param_3,u32 param_4);
u32 * FUN_004a7e40(u32 *param_1,u32 param_2,u32 param_3,char *param_4);
u32 * FUN_004a8980(u32 *param_1,u64 param_2,u32 param_3,u64 param_4);
u32 * FUN_004a90f0(void);
u32 * FUN_004a9a80(u64 param_1);
u32 * FUN_004ab8c0(void);
u32 FUN_00431880(int param_1);
u32 FUN_00431aa0(int param_1);
u32 FUN_00432050(int param_1);
u32 FUN_00432600(int param_1);
u32 FUN_00432bb0(int param_1);
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
u32 FUN_0043ca30(int param_1);
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
u32 FUN_0045a280(int param_1,int param_2);
u32 FUN_0045af40(void);
u32 FUN_0045afd0(float param_1,long param_2,int param_3,int param_4,int param_5,int param_6, u8 param_7,u8 param_8,short param_9);
u32 FUN_0045b190(long param_1);
u32 FUN_0045b420(int param_1,float *param_2);
u32 FUN_0045df00(int param_1);
u32 FUN_0045e3e0(int param_1);
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
u32 FUN_00430180(u64 param_1);
u64 FUN_00430060(int param_1);
u64 FUN_00430bb0(int param_1);
u32 FUN_00431110(u64 param_1,YajimaVec2 param_2,char param_3,u8 param_4);
u32 FUN_00431670(int param_1,char param_2,u32 param_3);
u64 FUN_00439f60(u64 param_1,char param_2);
u64 FUN_00439f60(u64 param_1,char param_2);
u64 FUN_0043a0b0(u64 param_1,char param_2);
u32 FUN_00447e70(u64 param_1,u8 param_2,u8 param_3);
u64 FUN_0044aaf0(int param_1);
u64 FUN_0044aaf0(int param_1);
u64 FUN_0044ad20(u64 param_1,char param_2);
u64 FUN_0044e560(int param_1);
u32 FUN_004542c0(char param_1);
u64 FUN_00455e00(u64 param_1);
u64 FUN_00455e00(u64 param_1);
u64 FUN_004560d0(u32 param_1,float param_2,float param_3,float param_4,u32 param_5,u32 param_6);
u64 FUN_00457a40(u64 param_1);
u64 FUN_00457a40(u64 param_1);
u64 FUN_00458630(u64 param_1,char param_2,u8 param_3);
u32 FUN_00459f60(u64 param_1,u16 param_2,char param_3);
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
u32 FUN_00435260(char param_1);
s8 FUN_004353f0(int param_1);
u8 FUN_00435810(void);
u8 FUN_004359f0(int param_1,u8 param_2,u8 param_3,u32 *param_4, u8 param_5,u8 param_6);
u8 FUN_0043c730(char param_1);
u8 FUN_0043c7f0(char param_1);
char FUN_00449c90(u64 param_1,char param_2);
u8 FUN_0044a420(int param_1,int param_2,int param_3);
u32 FUN_0044f060(float param_1,int param_2,float *param_3);
u32 FUN_0044f1c0(float param_1,float *param_2,float *param_3);
u8 FUN_0044fab0(int param_1);
char FUN_00453480(void);
u8 FUN_00454400(u32 *param_1,char param_2);
u8 FUN_00454520(float *param_1,char param_2);
u8 FUN_00454a70(char param_1,float *param_2);
u8 FUN_00454d00(float *param_1);
char FUN_00457390(char param_1);
char FUN_004573d0(char param_1);
int FUN_0045a3b0(void);
u8 FUN_0045af90(int param_1);
int FUN_0045b480(int param_1);
int FUN_0045b4b0(int param_1);
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
void FUN_00430270(RwV4d* output, int object);
void FUN_004302a0(int param_1);
void FUN_004302b0(void);
void FUN_00430630(int param_1);
void FUN_00430780(u64 param_1,int param_2,int param_3,int param_4);
void FUN_00430a40(char param_1);
void FUN_004310e0(int param_1);
void FUN_004311f0(void *param_1,int param_2,int param_3);
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
void FUN_00435c00(int param_1);
void FUN_00437e00(void);
void FUN_00437e80(u32 *param_1,char param_2);
void FUN_00438010(int param_1);
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
void FUN_00448060(int param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6);
void FUN_00448cf0(int param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6,int param_7);
void FUN_00449d10(int param_1);
void FUN_00449d60(u64 param_1);
void FUN_00449ed0(void);
void FUN_00449fa0(void);
void FUN_0044a240(float param_1,float param_2,float param_3,float param_4,int param_5 ,char param_6);
void FUN_0044a330(float param_1,float param_2,float param_3,float param_4,int param_5 ,char param_6);
void FUN_0044a630(int param_1);
void FUN_0044a790(u32 *param_1);
void FUN_0044a990(int param_1,u32 *param_2);
void FUN_0044acf0(int param_1);
void FUN_0044af60(u64 param_1);
void FUN_0044b7d0(int param_1);
void FUN_0044beb0(int param_1);
void FUN_0044d600(int param_1);
void FUN_0044dfc0(int param_1);
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
void FUN_004561d0(float param_1,float param_2,int param_3);
void FUN_004561f0(float param_1,int param_2);
void FUN_004563b0(f32 param_1, int param_2);
void FUN_004563c0(int param_1,u8 param_2);
void FUN_004563d0(int object, RwV2d value);
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
void FUN_00456a90(u32 param_1,char param_2,char param_3);
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
void FUN_0045bcb0(int param_1,u64 param_2);
void FUN_0045bd90(u64 param_1);
void FUN_0045c530(int param_1);
void FUN_0045c8c0(int param_1,int param_2);
void FUN_0045cdd0(int param_1,long param_2);
void FUN_0045ce90(int param_1);
void FUN_0045d990(int param_1,long param_2);
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

// FUN_00430060

u64 FUN_00430060(int param_1)

{
  short *psVar1;
  u32 uVar2;
  int iVar3;
  float fVar4;
  
  psVar1 = *(short **)(param_1 + 0x3c);
  if ((char)psVar1[0xc] == '\0') {
    return 0;
  }
  uVar2 = FUN_001158b0(0,DAT_007ce6e4,4);
  fVar4 = (float)FUN_001126b0_typed((void*)uVar2);
  *(int *)(psVar1 + 8) = (int)fVar4;
  fVar4 = (float)FUN_00112740_typed((void*)uVar2);
  *(int *)(psVar1 + 10) = (int)fVar4;
  iVar3 = (int)uVar2;
  *(float *)(iVar3 + 0x2c) = 4.0f;
  *(float *)(iVar3 + 0x10) = (float)(int)*psVar1;
  *(float *)(iVar3 + 0x14) = (float)(int)psVar1[1];
  *(u8 *)(iVar3 + 0x18) = 0;
  FUN_001127d0(uVar2,1);
  FUN_00115980_arg(uVar2);
  return 0;
}

// FUN_00430150

void FUN_00430150(int param_1)

{
  DAT_0096017c_abs[0](*(u32 *)(param_1 + 0x3c));
  return;
}

// FUN_00430180

u32 FUN_00430180(u64 param_1)
{
  u32 lVar1;
  u32 uVar2;
  u16 *puVar3;
  
  lVar1 = (*DAT_00960184_abs)(1,0x1c,0x40000);
  if (lVar1 == 0) {
    return 0;
  }
  uVar2 = FUN_00194b20_u32(param_1,DAT_006b44f0,0x18a7,
                           (u32 (*)(int))FUN_00430060,FUN_00430150,lVar1);
  puVar3 = (u16 *)lVar1;
  puVar3[1] = 0;
  *puVar3 = 0;
  *(u32 *)(puVar3 + 2) = 0x3f800000;
  *(u8 *)(puVar3 + 0xc) = 0;
  return uVar2;
}

// FUN_00430220

void FUN_00430220(int param_1,u64 param_2)

{
  u8 *puVar1;

  puVar1 = (u8 *)*(int *)(param_1 + 0x3c);
  *(u16 *)puVar1 = (short)(int)*(float *)&param_2;
  *(u16 *)(puVar1 + 2) = (short)(int)*((float *)&param_2 + 1);
  *(u8 *)(puVar1 + 0x18) = 1;
  return;
}

// FUN_00430270

void FUN_00430270(RwV4d* output, int object)
{
    RwV4d* source = (RwV4d*)(*(int*)(object + 0x3c) + 8);

    *output = *source;
}

// FUN_004302A0

void FUN_004302a0(int param_1)

{
  *(u8 *)(*(int *)(param_1 + 0x3c) + 0x18) = 0;
  return;
}

// FUN_004302B0

void FUN_004302b0(void)

{
  u32 uVar1;
  u32 bVar;
  uVar1 = FUN_00100d80_ptr((const char *)(DAT_006b4510),0);
  FUN_001023a0(uVar1);
  DAT_007ce6e4 = FUN_00112370_typed((const char *)(DAT_006b4510));
  do {
    FUN_001120c0_typed();
    bVar = (FUN_00111f30_long((void*)(DAT_007ce6e4)) != 0);
    bVar = bVar ^ 1;
  } while (bVar != 0);
  FUN_00100ec0_arg(uVar1);
  uVar1 = FUN_00100d80_ptr((const char *)(DAT_006b4510 + 0x18),0);
  FUN_001023a0(uVar1);
  *(u32 *)DAT_0095c0e0_abs = FUN_004d1260_ptr((const char *)(DAT_006b4510 + 0x18),0);
  FUN_00100ec0_arg(uVar1);
  uVar1 = FUN_00100d80_ptr((const char *)(DAT_006b4510 + 0x28),0);
  FUN_001023a0(uVar1);
  *(u32 *)DAT_0095c0e4_abs = FUN_004d1260_ptr((const char *)(DAT_006b4510 + 0x28),0);
  FUN_00100ec0_arg(uVar1);
  uVar1 = FUN_00100d80_ptr((const char *)(DAT_006b4510 + 0x38),0);
  FUN_001023a0(uVar1);
  *(u32 *)DAT_0095c0e8_abs = FUN_004d1260_ptr((const char *)(DAT_006b4510 + 0x38),0);
  FUN_00100ec0_arg(uVar1);
  uVar1 = FUN_00100d80_ptr((const char *)(DAT_006b4510 + 0x48),0);
  FUN_001023a0(uVar1);
  *(u32 *)DAT_0095c0ec_abs = FUN_004d1260_ptr((const char *)(DAT_006b4510 + 0x48),0);
  FUN_00100ec0_arg(uVar1);
  uVar1 = FUN_00100d80_ptr((const char *)(DAT_006b4510 + 0x58),0);
  FUN_001023a0(uVar1);
  *(u32 *)DAT_0095c0f0_abs = FUN_004d1260_ptr((const char *)(DAT_006b4510 + 0x58),0);
  FUN_00100ec0_arg(uVar1);
  uVar1 = FUN_00100d80_ptr((const char *)(DAT_006b4510 + 0x68),0);
  FUN_001023a0(uVar1);
  *(u32 *)DAT_0095c0f4_abs = FUN_004d1260_ptr((const char *)(DAT_006b4510 + 0x68),0);
  FUN_00100ec0_arg(uVar1);
  uVar1 = FUN_00100d80_ptr((const char *)(DAT_006b4510 + 0x78),0);
  FUN_001023a0(uVar1);
  *(u32 *)DAT_0095c0f8_abs = FUN_004d1260_ptr((const char *)(DAT_006b4510 + 0x78),0);
  FUN_00100ec0_arg(uVar1);
  uVar1 = FUN_00100d80_ptr((const char *)(DAT_006b4510 + 0x88),0);
  FUN_001023a0(uVar1);
  *(u32 *)DAT_0095c0fc_abs = FUN_004d1260_ptr((const char *)(DAT_006b4510 + 0x88),0);
  FUN_00100ec0_arg(uVar1);
  uVar1 = FUN_00100d80_ptr((const char *)(DAT_006b4510 + 0x98),0);
  FUN_001023a0(uVar1);
  *(u32 *)DAT_0095c100_abs = FUN_004d1260_ptr((const char *)(DAT_006b4510 + 0x98),0);
  FUN_00100ec0_arg(uVar1);
  uVar1 = FUN_00100d80_ptr((const char *)(DAT_006b4510 + 0xb0),0);
  FUN_001023a0(uVar1);
  DAT_007ce6e0 = FUN_004d1260_ptr((const char *)(DAT_006b4510 + 0xb0),0);
  FUN_00100ec0_arg(uVar1);
  return;
}

// FUN_00430630

void FUN_00430630(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  iVar2 = FUN_001158b0(0,DAT_007ce6e4,0);
  *(int *)(iVar1 + 0x4c) = iVar2;
  *(u8 *)(iVar2 + 0x18) = 0xff;
  *(u32 *)(*(int *)(iVar1 + 0x4c) + 0x10) = 0x40e00000;
  *(u32 *)(*(int *)(iVar1 + 0x4c) + 0x14) = 0x43630000;
  *(u32 *)(*(int *)(iVar1 + 0x4c) + 0x2c) = 0x42480000;
  iVar2 = FUN_001158b0(0,DAT_007ce6e4,1);
  *(int *)(iVar1 + 0x50) = iVar2;
  *(u8 *)(iVar2 + 0x18) = 0xff;
  *(u32 *)(*(int *)(iVar1 + 0x50) + 0x10) = 0x42be0000;
  *(u32 *)(*(int *)(iVar1 + 0x50) + 0x14) = 0x43630000;
  *(u32 *)(*(int *)(iVar1 + 0x50) + 0x2c) = 0x42480000;
  iVar2 = FUN_001158b0(0,DAT_007ce6e4,2);
  *(int *)(iVar1 + 0x54) = iVar2;
  *(u8 *)(iVar2 + 0x18) = 0xff;
  *(u32 *)(*(int *)(iVar1 + 0x54) + 0x10) = 0x40e00000;
  iVar3 = 0x139;
  *(float *)(*(int *)(iVar1 + 0x54) + 0x14) = (float)iVar3;
  *(u32 *)(*(int *)(iVar1 + 0x54) + 0x2c) = 0x42480000;
  iVar2 = FUN_001158b0(0,DAT_007ce6e4,3);
  *(int *)(iVar1 + 0x58) = iVar2;
  *(u8 *)(iVar2 + 0x18) = 0xff;
  *(u32 *)(*(int *)(iVar1 + 0x58) + 0x10) = 0x42be0000;
  iVar3 = 0x139;
  *(float *)(*(int *)(iVar1 + 0x58) + 0x14) = (float)iVar3;
  *(u32 *)(*(int *)(iVar1 + 0x58) + 0x2c) = 0x42480000;
  return;
}

// FUN_00430780 NONMATCHING

void FUN_00430780(u64 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  u32 uVar2;
  u8 uVar3;
  u16 uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar5 = (float)FUN_0052e878_typed(DAT_007cb134 * (float)param_4);
  fVar7 = fVar5 * 0.5f + 0.5f;
  fVar5 = (float)FUN_0052e878_typed(DAT_007cb138 * (float)param_4);
  fVar8 = fVar5 * -255.0f + 255.0f;
  uVar2 = FUN_001158b0(0,DAT_007ce6e4,0xd);
  iVar1 = (int)uVar2;
  *(float *)(iVar1 + 0x2c) = 1.0f;
  fVar5 = (float)FUN_001126b0_typed((void*)uVar2);
  fVar5 = fVar7 * (fVar5 / 2.0f);
  fVar6 = (float)FUN_001126b0_typed((void*)uVar2);
  *(float *)(iVar1 + 0x10) = (float)param_2 + ((*(float *)&param_1 + 0.0f) - fVar5) + fVar6 / 4.0f;
  fVar5 = (float)FUN_00112740_typed((void*)uVar2);
  fVar5 = fVar7 * (fVar5 / 2.0f);
  fVar6 = (float)FUN_00112740_typed((void*)uVar2);
  *(float *)(iVar1 + 0x14) = (float)param_3 + ((*((float *)&param_1 + 1) + 0.0f) - fVar5) + fVar6 / 4.0f;
  if (fVar8 < 2.1474836e+09f) {
    uVar3 = (u8)(int)fVar8;
  }
  else {
    uVar3 = (u8)(int)(fVar8 - 2.1474836e+09f);
  }
  *(u8 *)(iVar1 + 0x18) = uVar3;
  fVar7 = fVar7 * 4096.0f;
  if (fVar7 < 2.1474836e+09f) {
    uVar4 = (u16)(int)fVar7;
  }
  else {
    uVar4 = (u16)(int)(fVar7 - 2.1474836e+09f);
  }
  *(u16 *)(iVar1 + 0x28) = uVar4;
  if (fVar7 < 2.1474836e+09f) {
    uVar4 = (u16)(int)fVar7;
  }
  else {
    uVar4 = (u16)(int)(fVar7 - 2.1474836e+09f);
  }
  *(u16 *)(iVar1 + 0x2a) = uVar4;
  FUN_001127d0(uVar2,1);
  FUN_00115980_arg(uVar2);
  return;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00430A40




void FUN_00430a40(char param_1)

{
  int iVar1;
  u32 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_001b9120_u32();
  iVar1 = *(int *)(*(int *)(iVar1 + 0x18) + 0x3c);
  for (iVar4 = 0; iVar4 < 5; iVar4 = iVar4 + 1) {
    iVar3 = (int)((u8 *)iVar1 + param_1 * 5 + iVar4);
    *(char *)(iVar3 + 0x8e2) = (char)(iVar4 << 2);
    *(u8 *)(iVar3 + 0x8d3) = 0;
    iVar3 = iVar1 + (param_1 + -1) * 10 + iVar4 * 2;
    uVar2 = FUN_00488f30();
    *(short *)(iVar3 + 0x8f6) = (short)(int)(8.0f - (float)(uVar2 & 0xf));
    uVar2 = FUN_00488f30();
    *(short *)(iVar3 + 0x914) = (short)(int)(8.0f - (float)(uVar2 & 0xf));
  }
  return;
}

#pragma pop
// FUN_00430BB0 NONMATCHING

u64 FUN_00430bb0(int param_1)

{
  char cVar1;
  char *pcVar2;
  u32 uVar3;
  
  pcVar2 = *(char **)((int)param_1 + 0x3c);
  cVar1 = *pcVar2;
  switch(cVar1) {
  case 0:
    if (pcVar2[0x7d] == '\0') {
      uVar3 = FUN_004229d0(param_1,*(u64 *)(pcVar2 + 0x14),3);
      *(float *)(pcVar2 + 0x5c) = *(float *)(pcVar2 + 0x14);
      *(u32 *)(pcVar2 + 0x24) = 0xd3;
      *(u32 *)(pcVar2 + 0x28) = 0x4c;
      FUN_00422c30(*(u32 *)(pcVar2 + 4),*(u64 *)(pcVar2 + 0x5c),pcVar2 + 0x1c);
      FUN_00422c90(*(u32 *)(pcVar2 + 4),0,0,0,0);
      FUN_00422c10(*(u32 *)(pcVar2 + 4),1);
      uVar3 = FUN_004229d0(param_1,*(u64 *)(pcVar2 + 0x14),3);
      *(u32 *)(pcVar2 + 8) = uVar3;
      *(float *)(pcVar2 + 100) = *(float *)(pcVar2 + 0x14) - 76.0f;
      *(u32 *)(pcVar2 + 0x34) = 0x4c;
      *(u32 *)(pcVar2 + 0x38) = 0xca;
      FUN_00422c30(*(u32 *)(pcVar2 + 8),*(u64 *)(pcVar2 + 100),pcVar2 + 0x2c);
      FUN_00422c90(*(u32 *)(pcVar2 + 8),0,0,0,0);
      FUN_00422c10(*(u32 *)(pcVar2 + 8),1);
      uVar3 = FUN_004229d0(param_1,*(u64 *)(pcVar2 + 0x14),3);
      *(u32 *)(pcVar2 + 0xc) = uVar3;
      *(float *)(pcVar2 + 0x6c) = *(float *)(pcVar2 + 0x14) - 76.0f;
      *(u32 *)(pcVar2 + 0x44) = 0xca;
      *(u32 *)(pcVar2 + 0x48) = 0x4c;
      FUN_00422c30(*(u32 *)(pcVar2 + 0xc),*(u64 *)(pcVar2 + 0x6c),pcVar2 + 0x3c);
      FUN_00422c90(*(u32 *)(pcVar2 + 0xc),0,0,0,0);
      FUN_00422c10(*(u32 *)(pcVar2 + 0xc),1);
      uVar3 = FUN_004229d0(param_1,*(u64 *)(pcVar2 + 0x14),3);
      *(u32 *)(pcVar2 + 0x10) = uVar3;
      *(float *)(pcVar2 + 0x74) = *(float *)(pcVar2 + 0x14) + 126.0f;
      *(u32 *)(pcVar2 + 0x54) = 0x55;
      *(u32 *)(pcVar2 + 0x58) = 0xca;
      FUN_00422c30(*(u32 *)(pcVar2 + 0x10),*(u64 *)(pcVar2 + 0x74),pcVar2 + 0x4c);
      FUN_00422c90(*(u32 *)(pcVar2 + 0x10),0,0,0,0);
      FUN_00422c10(*(u32 *)(pcVar2 + 0x10),1);
    }
    else {
      uVar3 = FUN_004229d0(param_1,*(u64 *)(pcVar2 + 0x14),3);
      *(float *)(pcVar2 + 0x5c) = *(float *)(pcVar2 + 0x14);
      *(u32 *)(pcVar2 + 0x60) = 0;
      *(u32 *)(pcVar2 + 0x24) = 0x140;
      *(u32 *)(pcVar2 + 0x28) = 0xca;
      FUN_00422c30(*(u32 *)(pcVar2 + 4),*(u64 *)(pcVar2 + 0x5c),pcVar2 + 0x1c);
      FUN_00422c90(*(u32 *)(pcVar2 + 4),0,0,0,0);
      FUN_00422c10(*(u32 *)(pcVar2 + 4),1);
      uVar3 = FUN_004229d0(param_1,*(u64 *)(pcVar2 + 0x14),3);
      *(u32 *)(pcVar2 + 8) = uVar3;
      *(float *)(pcVar2 + 100) = *(float *)(pcVar2 + 0x14) - 76.0f;
      *(u32 *)(pcVar2 + 0x68) = 0;
      *(u32 *)(pcVar2 + 0x34) = 0x4c;
      *(u32 *)(pcVar2 + 0x38) = 0xca;
      FUN_00422c30(*(u32 *)(pcVar2 + 8),*(u64 *)(pcVar2 + 100),pcVar2 + 0x2c);
      FUN_00422c90(*(u32 *)(pcVar2 + 8),0,0,0,0);
      FUN_00422c10(*(u32 *)(pcVar2 + 8),1);
      uVar3 = FUN_004229d0(param_1,*(u64 *)(pcVar2 + 0x14),3);
      *(u32 *)(pcVar2 + 0xc) = uVar3;
      *(float *)(pcVar2 + 0x6c) = *(float *)(pcVar2 + 0x14) - 76.0f;
      *(u32 *)(pcVar2 + 0x44) = 0xca;
      *(u32 *)(pcVar2 + 0x48) = 0x4c;
      FUN_00422c30(*(u32 *)(pcVar2 + 0xc),*(u64 *)(pcVar2 + 0x6c),pcVar2 + 0x3c);
      FUN_00422c90(*(u32 *)(pcVar2 + 0xc),0,0,0,0);
      FUN_00422c10(*(u32 *)(pcVar2 + 0xc),1);
      uVar3 = FUN_004229d0(param_1,*(u64 *)(pcVar2 + 0x14),3);
      *(u32 *)(pcVar2 + 0x10) = uVar3;
      *(float *)(pcVar2 + 0x74) = *(float *)(pcVar2 + 0x14) + 126.0f;
      *(u32 *)(pcVar2 + 0x54) = 0x140;
      *(u32 *)(pcVar2 + 0x58) = 0xca;
      FUN_00422c30(*(u32 *)(pcVar2 + 0x10),*(u64 *)(pcVar2 + 0x74),pcVar2 + 0x4c);
      FUN_00422c90(*(u32 *)(pcVar2 + 0x10),0,0,0,0);
      FUN_00422c10(*(u32 *)(pcVar2 + 0x10),1);
    }
    *pcVar2 = '\x01';
    break;
  case 1:
  case 2:
  default:
    break;
  }
  return 0;
}

// FUN_004310E0

void FUN_004310e0(int param_1)

{
  DAT_0096017c_abs[0](*(u32 *)(param_1 + 0x3c));
  return;
}

// FUN_00431110 NONMATCHING

u32 FUN_00431110(u64 param_1,YajimaVec2 param_2,char param_3,u8 param_4)

{
  int uVar3;
  u8 *puVar4;
  u32 lVar1;
  u32 uVar2;
  
  lVar1 = (*DAT_00960184_abs)(1,0x80,0x40000);
  if (lVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00194b20_u32(param_1,DAT_006b45e0,0x18a6,(u32 (*)(int))FUN_00430bb0,FUN_004310e0,lVar1);
    puVar4 = (u8 *)lVar1;
    *puVar4 = 0;
    *(YajimaVec2 *)(puVar4 + 0x14) = param_2;
    uVar3 = (int)param_3 >> 1;
    if (param_3 < '\0') {
      uVar3 = (param_3 + 1) >> 1;
    }
    puVar4[0x7c] = uVar3;
    puVar4[0x7d] = param_4;
  }
  return uVar2;
}

// FUN_004311F0 NONMATCHING

void FUN_004311f0(void *param_1,int param_2,int param_3)

{
  float fStack_8;
  u32 uStack_4;
  float fStack_0;
  float fVar1;
  float fVar2;
  float fVar3;
  
  fVar3 = 800.0f;
  uStack_4 = 0;
  if (param_2 >= 0) {
    fVar1 = (float)param_2;
  }
  else {
    fVar1 = (float)(int)(((u32)param_2 >> 1) | (param_2 & 1));
    fVar1 = fVar1 + fVar1;
  }
  fStack_0 = 800.0f * fVar1;
  if (param_3 >= 0) {
    fVar2 = (float)param_3;
  }
  else {
    fVar2 = (float)(int)(((u32)param_3 >> 1) | (param_3 & 1));
    fVar2 = fVar2 + fVar2;
  }
  fVar3 = 800.0f * fVar2;
  fStack_8 = fVar3;
  *(float *)((u8 *)param_1 + 0) = fStack_0;
  *(u32 *)((u8 *)param_1 + 4) = uStack_4;
  *(float *)((u8 *)param_1 + 8) = fVar3;
}

// FUN_004312B0 NONMATCHING

u64 FUN_004312b0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  u8 uVar4;
  u8 uVar5;
  short sVar6;
  long lVar7;
  u8 bVar8;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  iVar2 = *(int *)((int)param_1 + 0x3c);
  bVar8 = 0;
  iVar3 = *(int *)(iVar2 + 4);
  if ((((u8 *)DAT_008717e8)[iVar3 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar3 * 0x70] != 0)) {
    bVar8 = 1;
  }
  if ((bVar8) && (*(char *)(iVar2 + 0x1215) != '\x01')) {
    sVar6 = FUN_0043c910((char)iVar3);
    if (sVar6 == 0) {
      *(u8 *)(iVar2 + 1) = 6;
    }
    else if (*(char *)(iVar2 + 0x1217) == '\x01') {
      FUN_0043a2f0(param_1);
    }
    else if (*(char *)(iVar2 + 0x1238) == '\x01') {
      FUN_0043a960(param_1);
    }
    else if (*(char *)(iVar2 + 0x1254) == '\x01') {
      FUN_0043bf50(param_1);
    }
    else {
      cVar1 = *(char *)(iVar2 + 1);
      if (cVar1 == '\x06') {
        lVar7 = FUN_002ff790_typed((void *)(((u8 *)DAT_008717e8)[*(int *)(iVar2 + 4) * 0x70]));
        if (lVar7 == 0) {
          if (cGpffffb9cc == '\0') {
            FUN_0043c7a0(*(u8 *)(iVar2 + 4),1);
          }
          else {
            FUN_0043c7a0(*(u8 *)(iVar2 + 4),2);
          }
        }
      }
      else if (cVar1 == '\x05') {
        FUN_00439520_arg(param_1);
      }
      else if (cVar1 == '\x02') {
        FUN_00438010(param_1);
        *(u8 *)(iVar2 + 0x1214) = 1;
      }
      else if (cVar1 == '\x01') {
        FUN_00435c00(param_1);
        *(u8 *)(iVar2 + 0x1214) = 0;
      }
      else if (cVar1 == '\0') {
        uVar4 = FUN_001ad910(*(u32 *)(DAT_008717f4 + 0x1e0));
        uVar5 = FUN_001ad920(*(u32 *)(DAT_008717f4 + 0x1e0));
        FUN_004311f0(&uStack_10,uVar4,uVar5);
        *(u32 *)(iVar2 + 0xd0) = uStack_10;
        *(u32 *)(iVar2 + 0xd4) = uStack_c;
        *(u32 *)(iVar2 + 0xd8) = uStack_8;
        uVar4 = FUN_0044f120(*(RwV3d *)(iVar2 + 0xd0));
        *(u8 *)(iVar2 + 0xdc) = uVar4;
        uVar4 = FUN_0044f170(*(RwV3d *)(iVar2 + 0xd0));
        *(u8 *)(iVar2 + 0xdd) = uVar4;
        *(u8 *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xdc);
        *(u8 *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xdd);
        if (cGpffffb9cc == '\0') {
          FUN_0043c7a0(*(u8 *)(iVar2 + 4),1);
          *(u8 *)(iVar2 + 0x1214) = 0;
        }
        else if (cGpffffb9cc == '\x01') {
          FUN_0043c7a0(*(u8 *)(iVar2 + 4),2);
          *(u8 *)(iVar2 + 0x1214) = 1;
        }
        else if (cGpffffb9cc == '\x02') {
          FUN_0043c7a0(*(u8 *)(iVar2 + 4),3);
          *(u8 *)(iVar2 + 0x1214) = 0;
        }
        lVar7 = FUN_002ff790_typed((void *)(((u8 *)DAT_008717e8)[*(int *)(iVar2 + 4) * 0x70]));
        if (lVar7 == 1) {
          FUN_0043c7a0(*(u8 *)(iVar2 + 4),6);
        }
      }
    }
  }
  return 0;
}

// FUN_00431630

void FUN_00431630(int param_1)

{
  ((u8 *)&gp0xffffb9f7)[*(int *)(*(int *)(param_1 + 0x3c) + 4)] = 0;
  DAT_0096017c_abs[0](*(u32 *)(param_1 + 0x3c));
  return;
}

// FUN_00431670 NONMATCHING

u32 FUN_00431670(int param_1,char param_2,u32 param_3)

{
  u32 uVar1;
  u32 lVar2;
  u32 uVar3;
  int iVar4;
  u32 uVar5;
  u8 *puVar6;
  
  lVar2 = (*DAT_00960184)(1,0x1264,0x40000);
  if (lVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00194b80_u32(param_1,10,DAT_006b45f8,(u32 (*)(int))FUN_004312b0,FUN_00431630,lVar2);
    uVar1 = FUN_003b5d10_eb90(0x400);
    puVar6 = (u8 *)lVar2;
    *(u32 *)(puVar6 + 8) = uVar1;
    uVar5 = (u32)param_2;
    uVar1 = FUN_003b5d10_eb90(uVar5 & 0x3ff | 0x400);
    *(u32 *)(puVar6 + 0xc) = uVar1;
    *puVar6 = 0;
    puVar6[0x1223] = 0;
    puVar6[0x1220] = 0;
    puVar6[1] = 0;
    *(int *)(puVar6 + 4) = (int)param_2;
    *(u32 *)(puVar6 + 0x24) = param_3;
    if (uVar5 == 3) {
      puVar6[0x101] = 2;
    }
    else if (uVar5 == 2) {
      puVar6[0x101] = 1;
    }
    else if (uVar5 == 1) {
      puVar6[0x101] = 0;
    }
    puVar6[0x102] = 1;
    puVar6[0x107] = 0;
    puVar6[0x108] = 0;
    puVar6[0x1214] = 0;
    ((u8 *)gp0xffffb9f7)[*(int *)(puVar6 + 4)] = 0;
    puVar6[0x1215] = 0;
    puVar6[0x1216] = uGpffffae20;
    puVar6[0x1217] = 0;
    puVar6[0x1238] = 0;
    puVar6[0x123b] = 0;
    iVar4 = (param_2 * 8 - (int)param_2) * 0x40;
    if (((u8 *)DAT_0087193a)[iVar4] != '\0') {
      puVar6[1] = ((u8 *)DAT_0087193a)[iVar4];
      if (cGpffffb9cc == '\0') {
        puVar6[0x1214] = 0;
      }
      else if (cGpffffb9cc == '\x01') {
        puVar6[0x1214] = 1;
      }
      else if (cGpffffb9cc == '\x02') {
        puVar6[0x1214] = 0;
      }
    }
    if (((u8 *)DAT_0087193c)[iVar4] == '\x01') {
      puVar6[0x1215] = 1;
    }
  }
  return uVar3;
}

// FUN_00431880 NONMATCHING




u32 FUN_00431880(int param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  u8 uVar4;
  int iVar5;
  
  iVar3 = *(int *)(param_1 + 0x3c);
  uVar4 = FUN_0044f120(*(RwV3d *)(iVar3 + 0xd0));
  *(u8 *)(iVar3 + 0xdc) = uVar4;
  uVar4 = FUN_0044f170(*(RwV3d *)(iVar3 + 0xd0));
  *(u8 *)(iVar3 + 0xdd) = uVar4;
  *(u8 *)(iVar3 + 0xf8) = *(u8 *)(iVar3 + 0xdc);
  *(u8 *)(iVar3 + 0xf9) = *(u8 *)(iVar3 + 0xdd);
  iVar5 = *(char *)(iVar3 + 0xdd) * 0x10 + *(char *)(iVar3 + 0xdc) + iVar3;
  *(char *)(iVar5 + 0x109) = *(char *)(iVar5 + 0x109) + '\x01';
  if (*(int *)(iVar3 + 4) == 2) {
    cVar1 = *(char *)(iVar3 + 0xdd);
    cVar2 = *(char *)(iVar3 + 0xdc);
    if (((u32)*(u8 *)(cVar1 * 0x10 + cVar2 + iVar3 + 0x109) % 3 == 0) &&
       (iVar5 = FUN_001b9120_u32(), *(char *)(iVar5 + cVar1 * 0x100 + cVar2 * 0x10 + 0x4a) == '\x03')) {
      return 1;
    }
    if ((*(u8 *)(cVar1 * 0x10 + cVar2 + iVar3 + 0x109) & 3) != 0) {
      return 0;
    }
    iVar5 = FUN_001b9120_u32();
    cVar1 = *(char *)(iVar5 + *(char *)(iVar3 + 0xdd) * 0x100 + *(char *)(iVar3 + 0xdc) * 0x10 +
                     0x4a);
  }
  else {
    cVar1 = *(char *)(iVar3 + 0xdd);
    cVar2 = *(char *)(iVar3 + 0xdc);
    if (((u32)*(u8 *)(cVar1 * 0x10 + cVar2 + iVar3 + 0x109) % 5 == 0) &&
       (iVar5 = FUN_001b9120_u32(), *(char *)(iVar5 + cVar1 * 0x100 + cVar2 * 0x10 + 0x4a) == '\x03')) {
      return 1;
    }
    if ((u32)*(u8 *)(cVar1 * 0x10 + cVar2 + iVar3 + 0x109) % 9 != 0) {
      return 0;
    }
    iVar5 = FUN_001b9120_u32();
    cVar1 = *(char *)(iVar5 + *(char *)(iVar3 + 0xdd) * 0x100 + *(char *)(iVar3 + 0xdc) * 0x10 +
                     0x4a);
  }
  if (cVar1 != '\x01') {
    return 0;
  }
  return 1;
}

// FUN_00431AA0

u32 FUN_00431aa0(int param_1)
{
  char cVar1;
  int iVar2;
  int iVar3;

  iVar2 = *(int *)((int)param_1 + 0x3c);
  cVar1 = *(char *)(iVar2 + 0x102);
  switch (cVar1) {
  case '\x04':
    goto case4;
  }
  switch (cVar1) {
  case '\x03':
    goto case3;
  }
  switch (cVar1) {
  case '\x02':
    goto case2;
  }
  switch (cVar1) {
  case '\x01':
    goto case1;
  }
  goto done;

case1:
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 2) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) - 1;
    FUN_004332f0(param_1);
    return 2;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 1) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) - 1;
    FUN_004332f0(param_1);
    return 1;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 8) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) + 1;
    FUN_004332f0(param_1);
    return 4;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 4) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) + 1;
    FUN_004332f0(param_1);
    return 3;
  }
  goto done;

case2:
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 4) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) + 1;
    FUN_004332f0(param_1);
    return 3;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 2) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) - 1;
    FUN_004332f0(param_1);
    return 2;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 1) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) - 1;
    FUN_004332f0(param_1);
    return 1;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 8) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) + 1;
    FUN_004332f0(param_1);
    return 4;
  }
  goto done;
case3:
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 8) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) + 1;
    FUN_004332f0(param_1);
    return 4;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 4) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) + 1;
    FUN_004332f0(param_1);
    return 3;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 2) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) - 1;
    FUN_004332f0(param_1);
    return 2;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 1) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) - 1;
    FUN_004332f0(param_1);
    return 1;
  }
  goto done;


case4:
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 1) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) - 1;
    FUN_004332f0(param_1);
    return 1;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 8) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) + 1;
    FUN_004332f0(param_1);
    return 4;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 4) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) + 1;
    FUN_004332f0(param_1);
    return 3;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 2) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) - 1;
    FUN_004332f0(param_1);
    return 2;
  }

done:
  return 0;
}

// FUN_00432050

u32 FUN_00432050(int param_1)
{
  char cVar1;
  int iVar2;
  int iVar3;

  iVar2 = *(int *)((int)param_1 + 0x3c);
  cVar1 = *(char *)(iVar2 + 0x102);
  switch (cVar1) {
  case '\x04':
    goto case4;
  }
  switch (cVar1) {
  case '\x03':
    goto case3;
  }
  switch (cVar1) {
  case '\x02':
    goto case2;
  }
  switch (cVar1) {
  case '\x01':
    goto case1;
  }
  goto done;

case1:
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 8) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) + 1;
    FUN_004332f0(param_1);
    return 4;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 1) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) - 1;
    FUN_004332f0(param_1);
    return 1;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 2) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) - 1;
    FUN_004332f0(param_1);
    return 2;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 4) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) + 1;
    FUN_004332f0(param_1);
    return 3;
  }
  goto done;

case2:
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 1) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) - 1;
    FUN_004332f0(param_1);
    return 1;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 2) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) - 1;
    FUN_004332f0(param_1);
    return 2;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 4) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) + 1;
    FUN_004332f0(param_1);
    return 3;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 8) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) + 1;
    FUN_004332f0(param_1);
    return 4;
  }
  goto done;

case3:
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 2) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) - 1;
    FUN_004332f0(param_1);
    return 2;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 4) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) + 1;
    FUN_004332f0(param_1);
    return 3;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 8) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) + 1;
    FUN_004332f0(param_1);
    return 4;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 1) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) - 1;
    FUN_004332f0(param_1);
    return 1;
  }
  goto done;

case4:
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 4) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) + 1;
    FUN_004332f0(param_1);
    return 3;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 8) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) + 1;
    FUN_004332f0(param_1);
    return 4;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 1) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) - 1;
    FUN_004332f0(param_1);
    return 1;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 2) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) - 1;
    FUN_004332f0(param_1);
    return 2;
  }

done:
  return 0;
}

// FUN_00432600

u32 FUN_00432600(int param_1)
{
  char cVar1;
  int iVar2;
  int iVar3;

  iVar2 = *(int *)((int)param_1 + 0x3c);
  cVar1 = *(char *)(iVar2 + 0x102);
  switch (cVar1) {
  case '\x04':
    goto case4;
  }
  switch (cVar1) {
  case '\x03':
    goto case3;
  }
  switch (cVar1) {
  case '\x02':
    goto case2;
  }
  switch (cVar1) {
  case '\x01':
    goto case1;
  }
  goto done;

case1:
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 1) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) - 1;
    FUN_004333d0(param_1);
    return 1;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 8) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) + 1;
    FUN_004333d0(param_1);
    return 4;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 2) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) - 1;
    FUN_004333d0(param_1);
    return 2;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 4) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) + 1;
    FUN_004333d0(param_1);
    return 3;
  }
  goto done;

case2:
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 2) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) - 1;
    FUN_004333d0(param_1);
    return 2;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 1) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) - 1;
    FUN_004333d0(param_1);
    return 1;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 4) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) + 1;
    FUN_004333d0(param_1);
    return 3;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 8) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) + 1;
    FUN_004333d0(param_1);
    return 4;
  }
  goto done;

case3:
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 4) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) + 1;
    FUN_004333d0(param_1);
    return 3;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 2) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) - 1;
    FUN_004333d0(param_1);
    return 2;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 8) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) + 1;
    FUN_004333d0(param_1);
    return 4;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 1) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) - 1;
    FUN_004333d0(param_1);
    return 1;
  }
  goto done;

case4:
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 8) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) + 1;
    FUN_004333d0(param_1);
    return 4;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 4) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) + 1;
    FUN_004333d0(param_1);
    return 3;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 1) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) - 1;
    FUN_004333d0(param_1);
    return 1;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 2) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) - 1;
    FUN_004333d0(param_1);
    return 2;
  }

done:
  return 0;
}

// FUN_00432BB0

u32 FUN_00432bb0(int param_1)
{
  char cVar1;
  int iVar2;
  int iVar3;

  iVar2 = *(int *)((int)param_1 + 0x3c);
  cVar1 = *(char *)(iVar2 + 0x102);
  switch (cVar1) {
  case '\x04':
    goto case4;
  }
  switch (cVar1) {
  case '\x03':
    goto case3;
  }
  switch (cVar1) {
  case '\x02':
    goto case2;
  }
  switch (cVar1) {
  case '\x01':
    goto case1;
  }
  goto done;

case1:
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 1) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) - 1;
    FUN_004333d0(param_1);
    return 1;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 2) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) - 1;
    FUN_004333d0(param_1);
    return 2;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 8) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) + 1;
    FUN_004333d0(param_1);
    return 4;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 4) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) + 1;
    FUN_004333d0(param_1);
    return 3;
  }
  goto done;

case2:
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 2) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) - 1;
    FUN_004333d0(param_1);
    return 2;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 4) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) + 1;
    FUN_004333d0(param_1);
    return 3;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 1) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) - 1;
    FUN_004333d0(param_1);
    return 1;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 8) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) + 1;
    FUN_004333d0(param_1);
    return 4;
  }
  goto done;

case3:
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 4) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) + 1;
    FUN_004333d0(param_1);
    return 3;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 8) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) + 1;
    FUN_004333d0(param_1);
    return 4;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 2) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) - 1;
    FUN_004333d0(param_1);
    return 2;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 1) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) - 1;
    FUN_004333d0(param_1);
    return 1;
  }
  goto done;

case4:
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 8) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) + 1;
    FUN_004333d0(param_1);
    return 4;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 1) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) - 1;
    FUN_004333d0(param_1);
    return 1;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 4) != 0) {
    *(char *)(iVar2 + 0xf9) = *(u8 *)(iVar2 + 0xf9) + 1;
    FUN_004333d0(param_1);
    return 3;
  }
  iVar3 = FUN_001b9120_u32();
  if ((*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x53)
      & 2) != 0) {
    *(char *)(iVar2 + 0xf8) = *(u8 *)(iVar2 + 0xf8) - 1;
    FUN_004333d0(param_1);
    return 2;
  }

done:
  return 0;
}

// FUN_00433160 NONMATCHING

u32 FUN_00433160(int param_1)

{
  int cVar1;
  int cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  u32 uVar6;
  
  iVar3 = *(int *)(param_1 + 0x3c);
  uVar6 = 0;
  cVar1 = *(char *)(iVar3 + 0xdd);
  cVar2 = *(char *)(iVar3 + 0xdc);
  if ((*(u8 *)(cVar1 * 0x10 + cVar2 + iVar3 + 0x10a) == '\0') &&
     (iVar5 = FUN_001b9120_u32(), (*(u8 *)(iVar5 + cVar1 * 0x100 + cVar2 * 0x10 + 0x53) & 8) != 0)) {
    uVar6 = 4;
  }
  else {
    if (*(u8 *)(cVar1 * 0x10 + cVar2 + iVar3 + 0x108) == '\0') {
      cVar1 = *(char *)(iVar3 + 0xdd);
      cVar2 = *(char *)(iVar3 + 0xdc);
      iVar5 = FUN_001b9120_u32();
      if ((*(u8 *)(iVar5 + cVar1 * 0x100 + cVar2 * 0x10 + 0x53) & 2) != 0) {
        return 2;
      }
    }
    iVar5 = (int)cVar2;
    if (*(u8 *)(cVar1 * 0x10 + iVar5 + iVar3 + 0xf9) == '\0') {
      cVar1 = *(char *)(iVar3 + 0xdd);
      iVar5 = (int)*(char *)(iVar3 + 0xdc);
      iVar4 = FUN_001b9120_u32();
      if ((*(u8 *)(iVar4 + cVar1 * 0x100 + iVar5 * 0x10 + 0x53) & 1) != 0) {
        return 1;
      }
    }
    if ((*(u8 *)(cVar1 * 0x10 + iVar5 + iVar3 + 0x119) == '\0') &&
       (iVar5 = FUN_001b9120_u32(),
       (*(u8 *)(iVar5 + *(char *)(iVar3 + 0xdd) * 0x100 + *(char *)(iVar3 + 0xdc) * 0x10 + 0x53) &
       4) != 0)) {
      uVar6 = 3;
    }
  }
  return uVar6;
}

// FUN_004332F0

void FUN_004332f0(int param_1)
{
  u8 *iVar2;
  int iVar3;
  int cVar1;

  iVar2 = (u8 *)*(int *)(param_1 + 0x3c);
  iVar3 = FUN_001b9120_u32();
  if (*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x4f) ==
      2) {
    iVar3 = FUN_001b9120_u32();
    cVar1 = *(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 +
                     0x4a);
    iVar3 = FUN_001b9120_u32();
    if (cVar1 == *(u8 *)(iVar3 + (u32)*(u8 *)(iVar2 + 0xf9) * 0x100 +
                           (u32)*(u8 *)(iVar2 + 0xf8) * 0x10 + 0x4a)) {
      iVar3 = *(int *)(iVar2 + 0x20c) + 1;
      *(int *)(iVar2 + 0x20c) = iVar3;
      if (8 < iVar3) {
        *(u8 *)(iVar2 + 0x101) = *(char *)(iVar2 + 0x101) ^ 1;
        *(int *)(iVar2 + 0x20c) = 0;
      }
    }
    else {
      *(int *)(iVar2 + 0x20c) = 0;
    }
  }
}

// FUN_004333D0

void FUN_004333d0(int param_1)
{
  u8 *iVar2;
  int iVar3;
  int cVar1;


  iVar2 = (u8 *)*(int *)(param_1 + 0x3c);
  iVar3 = FUN_001b9120_u32();
  if (*(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x4f) ==
      2) {
    iVar3 = FUN_001b9120_u32();
    cVar1 = *(u8 *)(iVar3 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 +
                     0x4a);
    iVar3 = FUN_001b9120_u32();
    if (cVar1 == *(u8 *)(iVar3 + (u32)*(u8 *)(iVar2 + 0xf9) * 0x100 +
                           (u32)*(u8 *)(iVar2 + 0xf8) * 0x10 + 0x4a)) {
      iVar3 = *(int *)(iVar2 + 0x20c);
      iVar3 = iVar3 + 1;
      *(int *)(iVar2 + 0x20c) = iVar3;
      if (8 < iVar3) {
        if (*(char *)(iVar2 + 0x101) == '\x02') {
          *(u8 *)(iVar2 + 0x101) = 3;
        }
        else {
          *(u8 *)(iVar2 + 0x101) = 2;
        }
        *(u32 *)(iVar2 + 0x20c) = 0;
      }
    }
    else {
      *(u32 *)(iVar2 + 0x20c) = 0;
    }
  }
}

// FUN_004334D0

void FUN_004334d0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x3c);
  iVar1 = FUN_001b9120_u32();
  if (*(u8 *)(iVar1 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x4f) ==
      2) {
    iVar1 = FUN_001b9120_u32();
    if (*(u8 *)(iVar1 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x49)
        == 1) {
      *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
              ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0x10a) =
          *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                  ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0x10a) + 1;
      *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
              ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0x119) =
          *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                  ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0x119) + 1;
      *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
              ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0x11a) =
          *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                  ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0x11a) + 1;
    }
    else {
      iVar1 = FUN_001b9120_u32();
      if ((*(u8 *)(iVar1 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 +
                    -0xb7) == 1) &&
         (iVar1 = FUN_001b9120_u32(),
         *(u8 *)(iVar1 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + -0xb1)
         == 2)) {
        *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0x10a) =
            *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                    ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0x10a) + 1;
        *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0xf9) =
            *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                    ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0xf9) + 1;
        *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0xfa) =
            *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                    ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0xfa) + 1;
      }
      else {
        iVar1 = FUN_001b9120_u32();
        if ((*(u8 *)(iVar1 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 +
                      0x39) == 1) &&
           (iVar1 = FUN_001b9120_u32(),
           *(u8 *)(iVar1 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 + 0x3f
                    ) == 2)) {
          *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                  ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0x108) =
              *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                      ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0x108) + 1;
          *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                  ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0x119) =
              *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                      ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0x119) + 1;
          *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                  ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0x118) =
              *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                      ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0x118) + 1;
        }
        else {
          iVar1 = FUN_001b9120_u32();
          if ((*(u8 *)(iVar1 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 +
                        -199) == 1) &&
             (iVar1 = FUN_001b9120_u32(),
             *(u8 *)(iVar1 + *(char *)(iVar2 + 0xdd) * 0x100 + *(char *)(iVar2 + 0xdc) * 0x10 +
                      -0xc1) == 2)) {
            *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                    ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0x108) =
                *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                        ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0x108) + 1;
            *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                    ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0xf9) =
                *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                        ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0xf9) + 1;
            *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                    ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0xf8) =
                *(u8 *)((u32)*(u8 *)(iVar2 + 0xf9) * 0x10 +
                        ((u32)*(u8 *)(iVar2 + 0xf8) + iVar2) + 0xf8) + 1;
          }
        }
      }
    }
  }
  return;
}

// FUN_00433810

u32 FUN_00433810(char param_1,char param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  u32 uVar6;
  
  uVar6 = 0;
  iVar4 = param_2 * 0x100;
  iVar2 = param_1 * 0x10;
  iVar1 = FUN_001b9120_u32();
  iVar1 = iVar1 + iVar4;
  iVar1 = iVar1 + iVar2;
  if (*(u8 *)(iVar1 + 0x4f) == 2) {
    iVar1 = FUN_001b9120_u32();
    iVar1 = iVar1 + iVar4;
    iVar1 = iVar1 + iVar2;
    iVar5 = (int)param_2;
    iVar3 = (int)param_1;
    if (*(u8 *)(iVar1 + 0x49) == 1) {
      uVar6 = iVar3 + iVar5 * 0x10 & 0xff;
    }
    else {
      iVar1 = FUN_001b9120_u32();
      iVar1 = iVar1 + iVar4;
      iVar1 = iVar1 + iVar2;
      if ((*(u8 *)(iVar1 + -0xb7) == 1) &&
         (iVar1 = FUN_001b9120_u32(),
         iVar1 = iVar1 + iVar4,
         iVar1 = iVar1 + iVar2,
         *(u8 *)(iVar1 + -0xb1) == 2)) {
        uVar6 = (int)param_1 + (param_2 + -1) * 0x10 & 0xff;
      }
      else {
        iVar1 = FUN_001b9120_u32();
        iVar1 = iVar1 + iVar4;
        iVar1 = iVar1 + iVar2;
        if ((*(u8 *)(iVar1 + 0x39) == 1) &&
           (iVar1 = FUN_001b9120_u32(),
           iVar1 = iVar1 + iVar4,
           iVar1 = iVar1 + iVar2,
           *(u8 *)(iVar1 + 0x3f) == 2)) {
          uVar6 = iVar3 + -1 + iVar5 * 0x10 & 0xff;
        }
        else {
          iVar1 = FUN_001b9120_u32();
          iVar1 = iVar1 + iVar4;
          iVar1 = iVar1 + iVar2;
          if ((*(u8 *)(iVar1 + -199) == 1) &&
             (iVar1 = FUN_001b9120_u32(),
             iVar1 = iVar1 + iVar4,
             iVar1 = iVar1 + iVar2,
             *(u8 *)(iVar1 + -0xc1) == 2)) {
            uVar6 = iVar3 + -1 + (param_2 + -1) * 0x10 & 0xff;
          }
        }
      }
    }
  }
  return uVar6;
}

// FUN_004339D0 NONMATCHING

u32 FUN_004339d0(int param_1)
{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  u32 uVar5;
  u8 bVar6;

  iVar3 = *(int *)(param_1 + 0x3c);
  cVar1 = *(char *)(iVar3 + 0xdc);
  cVar2 = *(char *)(iVar3 + 0xdd);
  bVar6 = *(u8 *)(cVar2 * 0x10 + cVar1 + iVar3 + 0x109);
  uVar5 = 0;
  iVar4 = FUN_001b9120_u32();
  if (((*(u8 *)(iVar4 + cVar2 * 0x100 + cVar1 * 0x10 + 0x53) & 1) != 0) &&
     (*(u8 *)(cVar2 * 0x10 + cVar1 + iVar3 + 0xf9) <= bVar6)) {
    *(char *)(iVar3 + 0xf9) = *(char *)(iVar3 + 0xf9) + -1;
    iVar4 = FUN_001b9120_u32();
    iVar4 = *(u8 *)(iVar4 + (u32)*(u8 *)(iVar3 + 0xf9) * 0x100 +
                    (u32)*(u8 *)(iVar3 + 0xf8) * 0x10 + 0x4a);
    switch (iVar4) {
    case 4:
      iVar4 = 0;
      break;
    default:
      iVar4 = 0;
      break;
    }
    bVar6 = *(u8 *)(*(char *)(iVar3 + 0xdd) * 0x10 +
                    *(char *)(iVar3 + 0xdc) + iVar3 + 0xf9);
    if (iVar4 == 0) {
      *(u8 *)(iVar3 + 0x102) = 1;
      uVar5 = 1;
    }
    *(char *)(iVar3 + 0xf9) = *(char *)(iVar3 + 0xf9) + '\x01';
  }
  cVar1 = *(char *)(iVar3 + 0xdd);
  cVar2 = *(char *)(iVar3 + 0xdc);
  iVar4 = FUN_001b9120_u32();
  if (((*(u8 *)(iVar4 + cVar1 * 0x100 + cVar2 * 0x10 + 0x53) & 2) != 0) &&
     (*(u8 *)(cVar1 * 0x10 + cVar2 + iVar3 + 0x108) <= bVar6)) {
    *(char *)(iVar3 + 0xf8) = *(char *)(iVar3 + 0xf8) + -1;
    iVar4 = FUN_001b9120_u32();
    iVar4 = *(u8 *)(iVar4 + (u32)*(u8 *)(iVar3 + 0xf9) * 0x100 +
                    (u32)*(u8 *)(iVar3 + 0xf8) * 0x10 + 0x4a);
    switch (iVar4) {
    case 4:
      iVar4 = 0;
      break;
    default:
      iVar4 = 0;
      break;
    }
    bVar6 = *(u8 *)(*(char *)(iVar3 + 0xdd) * 0x10 +
                    *(char *)(iVar3 + 0xdc) + iVar3 + 0x108);
    if (iVar4 == 0) {
      *(u8 *)(iVar3 + 0x102) = 2;
      uVar5 = 2;
    }
    *(char *)(iVar3 + 0xf8) = *(char *)(iVar3 + 0xf8) + '\x01';
  }
  cVar1 = *(char *)(iVar3 + 0xdd);
  cVar2 = *(char *)(iVar3 + 0xdc);
  iVar4 = FUN_001b9120_u32();
  if (((*(u8 *)(iVar4 + cVar1 * 0x100 + cVar2 * 0x10 + 0x53) & 8) != 0) &&
     (*(u8 *)(cVar1 * 0x10 + cVar2 + iVar3 + 0x10a) <= bVar6)) {
    *(char *)(iVar3 + 0xf8) = *(char *)(iVar3 + 0xf8) + '\x01';
    iVar4 = FUN_001b9120_u32();
    iVar4 = *(u8 *)(iVar4 + (u32)*(u8 *)(iVar3 + 0xf9) * 0x100 +
                    (u32)*(u8 *)(iVar3 + 0xf8) * 0x10 + 0x4a);
    switch (iVar4) {
    case 4:
      iVar4 = 0;
      break;
    default:
      iVar4 = 0;
      break;
    }
    bVar6 = *(u8 *)(*(char *)(iVar3 + 0xdd) * 0x10 +
                    *(char *)(iVar3 + 0xdc) + iVar3 + 0x10a);
    if (iVar4 == 0) {
      *(u8 *)(iVar3 + 0x102) = 4;
      uVar5 = 4;
    }
    *(char *)(iVar3 + 0xf8) = *(char *)(iVar3 + 0xf8) + -1;
  }
  cVar1 = *(char *)(iVar3 + 0xdd);
  cVar2 = *(char *)(iVar3 + 0xdc);
  iVar4 = FUN_001b9120_u32();
  if (((*(u8 *)(iVar4 + cVar1 * 0x100 + cVar2 * 0x10 + 0x53) & 4) != 0) &&
     (*(u8 *)(cVar1 * 0x10 + cVar2 + iVar3 + 0x119) <= bVar6)) {
    *(char *)(iVar3 + 0xf9) = *(char *)(iVar3 + 0xf9) + '\x01';
    iVar4 = FUN_001b9120_u32();
    iVar4 = *(u8 *)(iVar4 + (u32)*(u8 *)(iVar3 + 0xf9) * 0x100 +
                    (u32)*(u8 *)(iVar3 + 0xf8) * 0x10 + 0x4a);
    switch (iVar4) {
    case 4:
      iVar4 = 0;
      break;
    default:
      iVar4 = 0;
      break;
    }
    bVar6 = *(u8 *)(*(char *)(iVar3 + 0xdd) * 0x10 +
                    *(char *)(iVar3 + 0xdc) + iVar3 + 0x119);
    if (iVar4 == 0) {
      *(u8 *)(iVar3 + 0x102) = 3;
      uVar5 = 3;
    }
    *(char *)(iVar3 + 0xf9) = *(char *)(iVar3 + 0xf9) + -1;
  }
  return uVar5;
}

// FUN_00433DE0 NONMATCHING

u32 FUN_00433de0(int param_1)

{
  u8 bVar1;
  u8 bVar2;
  u8 *puVar3;
  u32 uVar4;
  u32 uVar5;
  int iVar6;
  u32 uVar7;
  
  puVar3 = *(u8 **)(param_1 + 0x3c);
  uVar4 = (u32)(u8)puVar3[0x103] + (u32)(u8)puVar3[0x104] * 0x10;
  if ((puVar3[0xf8] == '\0') && (puVar3[0xf9] == '\0')) {
    *puVar3 = 0x20;
    uVar5 = 1;
  }
  else {
    bVar1 = puVar3[0xf9];
    bVar2 = puVar3[0xf8];
    iVar6 = FUN_001b9120_u32();
    if ((*(u8 *)(iVar6 + (u32)bVar1 * 0x100 + (u32)bVar2 * 0x10 + 0x53) & 1) != 0) {
      uVar7 = (u32)bVar2 + (bVar1 - 1) * 0x10 & 0xff;
      if ((*(short *)(puVar3 + uVar7 * 8 + 0x210) == 0) &&
         (*(short *)(puVar3 + uVar7 * 8 + 0x212) == 0)) {
        *(u16 *)(puVar3 + uVar7 * 8 + 0x210) = (u16)bVar2;
        *(u16 *)(puVar3 + uVar7 * 8 + 0x212) = (u8)puVar3[0xf9] - 1;
        *(u16 *)(puVar3 + uVar7 * 8 + 0x214) = (u16)(u8)puVar3[0xf8];
        *(u16 *)(puVar3 + uVar7 * 8 + 0x216) = (u16)(u8)puVar3[0xf9];
        *(u32 *)(puVar3 + *(int *)(puVar3 + 0x20c) * 4 + 0xa10) = uVar7;
        *(int *)(puVar3 + 0x20c) = *(int *)(puVar3 + 0x20c) + 1;
        if ((*(u16 *)(puVar3 + uVar7 * 8 + 0x210) == (u16)(u8)puVar3[0x103]) &&
           (*(u16 *)(puVar3 + uVar7 * 8 + 0x212) == (u16)(u8)puVar3[0x104])) {
          uVar4 = uVar4 & 0xff;
          *(u16 *)(puVar3 + uVar4 * 8 + 0x210) = (u16)(u8)puVar3[0x103];
          *(u16 *)(puVar3 + uVar4 * 8 + 0x212) = (u16)(u8)puVar3[0x104];
          *(u16 *)(puVar3 + uVar4 * 8 + 0x214) = (u16)(u8)puVar3[0x103];
          *(u16 *)(puVar3 + uVar4 * 8 + 0x216) = (u8)puVar3[0x104] + 1;
          return 2;
        }
      }
    }
    bVar1 = puVar3[0xf9];
    bVar2 = puVar3[0xf8];
    iVar6 = FUN_001b9120_u32();
    if ((*(u8 *)(iVar6 + (u32)bVar1 * 0x100 + (u32)bVar2 * 0x10 + 0x53) & 2) != 0) {
      iVar6 = (bVar2 - 1) + (u32)bVar1 * 0x10;
      if ((*(short *)(puVar3 + iVar6 * 8 + 0x210) == 0) &&
         (*(short *)(puVar3 + iVar6 * 8 + 0x212) == 0)) {
        *(u16 *)(puVar3 + iVar6 * 8 + 0x210) = (u8)puVar3[0xf8] - 1;
        *(u16 *)
         (puVar3 + (((u8)puVar3[0xf8] - 1) + (u32)(u8)puVar3[0xf9] * 0x10) * 8 + 0x212) =
             (u16)(u8)puVar3[0xf9];
        *(u16 *)
         (puVar3 + (((u8)puVar3[0xf8] - 1) + (u32)(u8)puVar3[0xf9] * 0x10) * 8 + 0x214) =
             (u16)(u8)puVar3[0xf8];
        *(u16 *)
         (puVar3 + (((u8)puVar3[0xf8] - 1) + (u32)(u8)puVar3[0xf9] * 0x10) * 8 + 0x216) =
             (u16)(u8)puVar3[0xf9];
        *(u32 *)(puVar3 + *(int *)(puVar3 + 0x20c) * 4 + 0xa10) =
             ((u8)puVar3[0xf8] - 1) + (u32)(u8)puVar3[0xf9] * 0x10;
        *(int *)(puVar3 + 0x20c) = *(int *)(puVar3 + 0x20c) + 1;
        iVar6 = ((u8)puVar3[0xf8] - 1) + (u32)(u8)puVar3[0xf9] * 0x10;
        if ((*(u16 *)(puVar3 + iVar6 * 8 + 0x210) == (u16)(u8)puVar3[0x103]) &&
           (*(u16 *)(puVar3 + iVar6 * 8 + 0x212) == (u16)(u8)puVar3[0x104])) {
          uVar4 = uVar4 & 0xff;
          *(u16 *)(puVar3 + uVar4 * 8 + 0x210) = (u16)(u8)puVar3[0x103];
          *(u16 *)(puVar3 + uVar4 * 8 + 0x212) = (u16)(u8)puVar3[0x104];
          *(u16 *)(puVar3 + uVar4 * 8 + 0x214) = (u8)puVar3[0x103] + 1;
          *(u16 *)(puVar3 + uVar4 * 8 + 0x216) = (u16)(u8)puVar3[0x104];
          return 2;
        }
      }
    }
    bVar1 = puVar3[0xf9];
    bVar2 = puVar3[0xf8];
    iVar6 = FUN_001b9120_u32();
    if ((*(u8 *)(iVar6 + (u32)bVar1 * 0x100 + (u32)bVar2 * 0x10 + 0x53) & 8) != 0) {
      iVar6 = bVar2 + 1 + (u32)bVar1 * 0x10;
      if ((*(short *)(puVar3 + iVar6 * 8 + 0x210) == 0) &&
         (*(short *)(puVar3 + iVar6 * 8 + 0x212) == 0)) {
        *(u16 *)(puVar3 + iVar6 * 8 + 0x210) = (u8)puVar3[0xf8] + 1;
        *(u16 *)(puVar3 + ((u8)puVar3[0xf8] + 1 + (u32)(u8)puVar3[0xf9] * 0x10) * 8 + 0x212)
             = (u16)(u8)puVar3[0xf9];
        *(u16 *)(puVar3 + ((u8)puVar3[0xf8] + 1 + (u32)(u8)puVar3[0xf9] * 0x10) * 8 + 0x214)
             = (u16)(u8)puVar3[0xf8];
        *(u16 *)(puVar3 + ((u8)puVar3[0xf8] + 1 + (u32)(u8)puVar3[0xf9] * 0x10) * 8 + 0x216)
             = (u16)(u8)puVar3[0xf9];
        *(u32 *)(puVar3 + *(int *)(puVar3 + 0x20c) * 4 + 0xa10) =
             (u8)puVar3[0xf8] + 1 + (u32)(u8)puVar3[0xf9] * 0x10;
        *(int *)(puVar3 + 0x20c) = *(int *)(puVar3 + 0x20c) + 1;
        iVar6 = (u8)puVar3[0xf8] + 1 + (u32)(u8)puVar3[0xf9] * 0x10;
        if ((*(u16 *)(puVar3 + iVar6 * 8 + 0x210) == (u16)(u8)puVar3[0x103]) &&
           (*(u16 *)(puVar3 + iVar6 * 8 + 0x212) == (u16)(u8)puVar3[0x104])) {
          uVar4 = uVar4 & 0xff;
          *(u16 *)(puVar3 + uVar4 * 8 + 0x210) = (u16)(u8)puVar3[0x103];
          *(u16 *)(puVar3 + uVar4 * 8 + 0x212) = (u16)(u8)puVar3[0x104];
          *(u16 *)(puVar3 + uVar4 * 8 + 0x214) = (u8)puVar3[0x103] - 1;
          *(u16 *)(puVar3 + uVar4 * 8 + 0x216) = (u16)(u8)puVar3[0x104];
          return 2;
        }
      }
    }
    bVar1 = puVar3[0xf9];
    bVar2 = puVar3[0xf8];
    iVar6 = FUN_001b9120_u32();
    if ((*(u8 *)(iVar6 + (u32)bVar1 * 0x100 + (u32)bVar2 * 0x10 + 0x53) & 4) != 0) {
      iVar6 = (u32)bVar2 + (bVar1 + 1) * 0x10;
      if ((*(short *)(puVar3 + iVar6 * 8 + 0x210) == 0) &&
         (*(short *)(puVar3 + iVar6 * 8 + 0x212) == 0)) {
        *(u16 *)(puVar3 + iVar6 * 8 + 0x210) = (u16)(u8)puVar3[0xf8];
        *(short *)(puVar3 + ((u32)(u8)puVar3[0xf8] + ((u8)puVar3[0xf9] + 1) * 0x10) * 8 + 0x212
                  ) = (short)((u8)puVar3[0xf9] + 1);
        *(u16 *)
         (puVar3 + ((u32)(u8)puVar3[0xf8] + ((u8)puVar3[0xf9] + 1) * 0x10) * 8 + 0x214) =
             (u16)(u8)puVar3[0xf8];
        *(u16 *)
         (puVar3 + ((u32)(u8)puVar3[0xf8] + ((u8)puVar3[0xf9] + 1) * 0x10) * 8 + 0x216) =
             (u16)(u8)puVar3[0xf9];
        *(u32 *)(puVar3 + *(int *)(puVar3 + 0x20c) * 4 + 0xa10) =
             (u32)(u8)puVar3[0xf8] + ((u8)puVar3[0xf9] + 1) * 0x10;
        *(int *)(puVar3 + 0x20c) = *(int *)(puVar3 + 0x20c) + 1;
        iVar6 = (u32)(u8)puVar3[0xf8] + ((u8)puVar3[0xf9] + 1) * 0x10;
        if ((*(u16 *)(puVar3 + iVar6 * 8 + 0x210) == (u16)(u8)puVar3[0x103]) &&
           (*(u16 *)(puVar3 + iVar6 * 8 + 0x212) == (u16)(u8)puVar3[0x104])) {
          uVar4 = uVar4 & 0xff;
          *(u16 *)(puVar3 + uVar4 * 8 + 0x210) = (u16)(u8)puVar3[0x103];
          *(u16 *)(puVar3 + uVar4 * 8 + 0x212) = (u16)(u8)puVar3[0x104];
          *(u16 *)(puVar3 + uVar4 * 8 + 0x214) = (u16)(u8)puVar3[0x103];
          *(u16 *)(puVar3 + uVar4 * 8 + 0x216) = (u8)puVar3[0x104] - 1;
          return 2;
        }
      }
    }
    uVar5 = 0;
  }
  return uVar5;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_004343D0 NONMATCHING

void FUN_004343d0(int param_1)

{
  u8 bVar1;
  short uVar2;
  short uVar3;
  int iVar4;
  int bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar4 = *(int *)(param_1 + 0x3c);
  bVar5 = 0;
  iVar6 = 0;
  *(u32 *)(iVar4 + 0x20c) = 0;
  for (iVar8 = 0; iVar8 < 0x100; iVar8 = iVar8 + 1) {
    iVar7 = iVar4 + iVar8 * 4;
    *(u16 *)(iVar7 + 0xe10) = 0;
    *(u16 *)(iVar7 + 0xe12) = 0;
  }
  bVar1 = *(u8 *)(iVar4 + 0x104);
  *(u16 *)(*(int *)(iVar4 + 0x20c) * 4 + iVar4 + 0xe10) = (u16)*(u8 *)(iVar4 + 0x103);
  *(u16 *)(*(int *)(iVar4 + 0x20c) * 4 + iVar4 + 0xe12) = (u16)bVar1;
  do {
    iVar8 = iVar4 + *(int *)(iVar4 + 0x20c) * 4;
    iVar8 = iVar4 + ((int)*(short *)(iVar8 + 0xe10) + *(short *)(iVar8 + 0xe12) * 0x10) * 8;
    uVar2 = *(u16 *)(iVar8 + 0x214);
    uVar3 = *(u16 *)(iVar8 + 0x216);
    *(int *)(iVar4 + 0x20c) = *(int *)(iVar4 + 0x20c) + 1;
    if ((uVar2 == *(u8 *)(iVar4 + 0x105)) && (uVar3 == *(u8 *)(iVar4 + 0x106))) {
      bVar5 = 1;
    }
    else {
      iVar8 = iVar4 + ((int)(short)uVar2 + (short)uVar3 * 0x10) * 8;
      *(u16 *)(iVar4 + *(int *)(iVar4 + 0x20c) * 4 + 0xe10) = *(u16 *)(iVar8 + 0x210);
      *(u16 *)(iVar4 + *(int *)(iVar4 + 0x20c) * 4 + 0xe12) = *(u16 *)(iVar8 + 0x212);
    }
    iVar6 = iVar6 + 1;
    if (99 < iVar6) {
      bVar5 = 1;
    }
  } while (!bVar5);
  return;
}

#pragma pop
// FUN_004344F0 NONMATCHING

void FUN_004344f0(float param_1,float *param_2,int param_3,float *param_4,float *param_5)

{
  char cVar1;
  int iVar2;
  u64 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fStack_60;
  float fStack_5c;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  fVar9 = *(float *)DAT_006b4610_abs;
  uVar3 = *(u64 *)DAT_006b4608_abs;
  fStack_10 = *param_4;
  fVar4 = param_4[1];
  fVar5 = param_4[2];
  fStack_20 = *param_5;
  fStack_1c = param_5[1];
  fStack_18 = param_5[2];
  iVar2 = *(int *)(param_3 + 0x3c);
  fStack_30 = fStack_10 - fStack_20;
  fStack_2c = fVar4 - fStack_1c;
  fStack_28 = fVar5 - fStack_18;
  fStack_c = fVar4;
  fStack_8 = fVar5;
  fVar6 = (float)FUN_004c69f0(&fStack_30,&fStack_30);
  fVar6 = fVar6 - param_1;
  fVar8 = fStack_2c * fVar6;
  fVar7 = fStack_10 - fStack_30 * fVar6;
  fVar6 = fVar5 - fStack_28 * fVar6;
  fStack_40 = fStack_10 - fVar7;
  fStack_3c = fVar4 - fVar8;
  fStack_38 = fVar5 - fVar6;
  FUN_004c69f0(&fStack_40,&fStack_40);
  fStack_5c = *(float *)((u8 *)&uVar3 + 4);
  fVar5 = fStack_3c * fVar9 - fStack_38 * fStack_5c;
  fStack_60 = *(float *)&uVar3;
  fVar9 = fStack_38 * fStack_60 - fStack_40 * fVar9;
  fVar4 = fStack_40 * fStack_5c - fStack_3c * fStack_60;
  cVar1 = *(char *)((int)(u8 *)DAT_007ce6e4 + *(int *)(iVar2 + 4) + 3);
  if (cVar1 == '\x03') {
    fStack_40 = fVar5 * 60.0f;
    fStack_3c = fVar9 * 60.0f;
    fStack_38 = fVar4 * 60.0f;
  }
  else if (cVar1 == '\x02') {
    fStack_40 = fVar5 * -40.0f;
    fStack_3c = fVar9 * -40.0f;
    fStack_38 = fVar4 * -40.0f;
  }
  else if (cVar1 == '\x01') {
    fStack_40 = fVar5 * 20.0f;
    fStack_3c = fVar9 * 20.0f;
    fStack_38 = fVar4 * 20.0f;
  }
  *param_2 = fVar7 + fStack_40;
  param_2[1] = fVar8 + fStack_3c;
  param_2[2] = fVar6 + fStack_38;
  return;
}

// FUN_00434770 NONMATCHING

u32 FUN_00434770(float param_1,float param_2,u64 param_3,float *param_4)

{
  int iVar1;
  int iVar2;
  u32 uVar3;
  float fVar4;
  float uVar5;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  fStack_10 = *param_4;
  fStack_8 = param_4[2];
  iVar2 = *(int *)((int)param_3 + 0x3c);
  uVar3 = 0;
  fStack_c = 0.0f;
  *(u32 *)(iVar2 + 0xe4) = 0;
  fStack_20 = fStack_10 - *(float *)(iVar2 + 0xe0);
  fStack_1c = 0.0f - *(float *)(iVar2 + 0xe4);
  fStack_18 = fStack_8 - *(float *)(iVar2 + 0xe8);
  fVar4 = (float)FUN_004c69f0(&fStack_20,&fStack_20);
  fStack_1c = 0.0f;
  if (param_2 <= fVar4) {
    FUN_004344f0(param_1,(float *)(&uStack_30),param_3,(float *)(iVar2 + 0xe0),&fStack_10);
    uVar5 = FUN_001e13c0_typed();
    FUN_001afa20_typed((uVar5),(void*)(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170)),(void*)(&uStack_30));
    *(u32 *)(iVar2 + 0xe0) = uStack_30;
    *(u32 *)(iVar2 + 0xe4) = uStack_2c;
    *(u32 *)(iVar2 + 0xe8) = uStack_28;
  }
  else {
    iVar1 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0xc) + 0x128));
    fStack_20 = fStack_10 - *(float *)(iVar1 + 0x30);
    iVar1 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0xc) + 0x128));
    fStack_1c = fStack_c - *(float *)(iVar1 + 0x34);
    iVar2 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0xc) + 0x128));
    fStack_18 = fStack_8 - *(float *)(iVar2 + 0x38);
    fVar4 = (float)FUN_004c69f0(&fStack_20,&fStack_20);
    if (fVar4 < param_1) {
      uVar3 = 1;
    }
  }
  return uVar3;
}

// FUN_00434920 NONMATCHING

u32 FUN_00434920(float param_1,float param_2,int param_3,float *param_4)

{
  char cVar1;
  int iVar2;
  u64 uVar3;
  float fVar4;
  float fVar5;
  u32 uVar6;
  float fVar7;
  float uVar8;
  float fVar9;
  float fStack_40;
  float fStack_3c;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  fStack_10 = *param_4;
  fStack_c = param_4[1];
  fStack_8 = param_4[2];
  iVar2 = *(int *)(param_3 + 0x3c);
  uVar6 = 0;
  FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0xc) + 0x128));
  fVar5 = fStack_8;
  fVar4 = *(float *)DAT_006b4620_abs;
  uVar3 = *(u64 *)DAT_006b4618_abs;
  fStack_20 = *(float *)(iVar2 + 0xe0) - fStack_10;
  fStack_1c = *(float *)(iVar2 + 0xe4) - fStack_c;
  fStack_18 = *(float *)(iVar2 + 0xe8) - fStack_8;
  fVar9 = fStack_c;
  fVar7 = (float)FUN_004c69f0(&fStack_20,&fStack_20);
  if (param_2 <= fVar7) {
    cVar1 = *(char *)((int)(u8 *)DAT_007ce6e4 + *(int *)(iVar2 + 4) + 3);
    if (cVar1 == '\x03') {
      fStack_30 = fStack_10 + fStack_20 * param_1;
      fStack_2c = fVar9 + fStack_1c * param_1;
      fStack_28 = fVar5 + fStack_18 * param_1;
    }
    else {
      fStack_40 = *(float *)&uVar3;
      fStack_3c = *(float *)((u8 *)&uVar3 + 4);
      if (cVar1 == '\x02') {
        fStack_30 = fStack_10 + fStack_20 * 150.0f;
        fStack_2c = fVar9 + fStack_1c * 150.0f;
        fStack_28 = fVar5 + fStack_18 * 150.0f;
        fStack_20 = fStack_10 - fStack_30;
        fStack_1c = fVar9 - fStack_2c;
        fStack_18 = fVar5 - fStack_28;
        FUN_004c69f0(&fStack_20,&fStack_20);
        fStack_30 = fStack_30 + (fStack_1c * fVar4 - fStack_18 * fStack_3c) * 80.0f;
        fStack_2c = fStack_2c + (fStack_18 * fStack_40 - fStack_20 * fVar4) * 80.0f;
        fStack_28 = fStack_28 + (fStack_20 * fStack_3c - fStack_1c * fStack_40) * 80.0f;
      }
      else if (cVar1 == '\x01') {
        fStack_30 = fStack_10 + fStack_20 * 150.0f;
        fStack_2c = fVar9 + fStack_1c * 150.0f;
        fStack_28 = fVar5 + fStack_18 * 150.0f;
        fStack_20 = fStack_10 - fStack_30;
        fStack_1c = fVar9 - fStack_2c;
        fStack_18 = fVar5 - fStack_28;
        FUN_004c69f0(&fStack_20,&fStack_20);
        fStack_30 = fStack_30 + (fStack_1c * fVar4 - fStack_18 * fStack_3c) * -80.0f;
        fStack_2c = fStack_2c + (fStack_18 * fStack_40 - fStack_20 * fVar4) * -80.0f;
        fStack_28 = fStack_28 + (fStack_20 * fStack_3c - fStack_1c * fStack_40) * -80.0f;
      }
    }
    uVar8 = FUN_001e13c0_typed();
    FUN_001afa20_typed((uVar8),(void*)(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170)),(void*)(&fStack_30));
    *(float *)(iVar2 + 0xe0) = fStack_30;
    *(float *)(iVar2 + 0xe4) = fStack_2c;
    *(float *)(iVar2 + 0xe8) = fStack_28;
  }
  else if (fVar7 < param_1) {
    uVar6 = 1;
  }
  return uVar6;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00434C90 NONMATCHING

void FUN_00434c90(char param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  u8 *base;

  base = (u8 *)&DAT_007ce6e8;
  for (iVar2 = 1; iVar2 < 4; iVar2 = iVar2 + 1) {
    iVar3 = 0;
    for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {
      if (iVar2 == (char)base[iVar1]) {
        iVar3 = 1;
      }
    }
    if (iVar3 == 0) {
      base[(char)(param_1 - 1)] = (u8)iVar2;
      return;
    }
  }
}

#pragma pop
// FUN_00434D30 NONMATCHING

void FUN_00434d30(void)

{
  char cVar1;
  int uVar2;
  int iVar3;
  
  for (iVar3 = 1; iVar3 < 4; iVar3 = iVar3 + 1) {
    if (*(int *)((u8 *)DAT_008717a0_bytes + iVar3 * 0x1c0) != 0) {
      uVar2 = iVar3;
      cVar1 = FUN_0043c7f0(uVar2);
      if (cVar1 != '\x06') {
        cVar1 = FUN_0043c7f0(uVar2);
        if (cVar1 == '\x05') {
          *(u8 *)(*(int *)(*(int *)((u8 *)DAT_008717a0_bytes + iVar3 * 0x1c0) + 0x3c) + 0x1214) = 1;
        }
        else if (*(char *)(*(int *)(*(int *)((u8 *)DAT_008717a0_bytes + iVar3 * 0x1c0) + 0x3c) + 0x1222) ==
                 '\0') {
          FUN_0043c7a0(uVar2,2);
        }
      }
    }
  }
  DAT_007ce6bc = 1;
  for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
    ((u8 *)DAT_007ce6e8)[iVar3] = 0;
  }
}
// FUN_00434E60 NONMATCHING
void FUN_00434e60(void)

{
  char cVar1;
  int uVar2;
  int iVar3;
  
  for (iVar3 = 1; iVar3 < 4; iVar3 = iVar3 + 1) {
    if (*(int *)((u8 *)DAT_008717a0_bytes + iVar3 * 0x1c0) != 0) {
      uVar2 = iVar3;
      cVar1 = FUN_0043c7f0(uVar2);
      if (cVar1 != '\x06') {
        cVar1 = FUN_0043c7f0(uVar2);
        if (cVar1 == '\x05') {
          *(u8 *)(*(int *)(*(int *)((u8 *)DAT_008717a0_bytes + iVar3 * 0x1c0) + 0x3c) + 0x1214) = 0;
        }
        else if (*(char *)(*(int *)(*(int *)((u8 *)DAT_008717a0_bytes + iVar3 * 0x1c0) + 0x3c) + 0x1222) ==
                 '\0') {
          FUN_0043c7a0(uVar2,1);
        }
      }
    }
  }
  DAT_007ce6bc = 0;
  return;
}

// FUN_00434F60

void FUN_00434f60(u8 param_1)
{
  *(u8 *)&DAT_007ce6c0 = param_1;
}

// FUN_00434F70

void FUN_00434f70(void)

{
  s32 lVar1;
  int iVar2;
  u8 *puVar1;
  u8 *puVar2;
  u32 *puVar3;
  
  *(u8 *)&DAT_007ce6bc = 0;
  *(u8 *)&DAT_007ce6c0 = 0;
  iVar2 = 0;
  puVar1 = (u8 *)&DAT_007ce6e8;
  for (; iVar2 < 3; iVar2 = iVar2 + 1) {
    puVar1[iVar2] = 0;
  }
  lVar1 = FUN_0016f190_typed(0x1414);
  if (lVar1 == 0) {
    iVar2 = 0;
    puVar2 = DAT_0095c110_abs;
    for (; iVar2 < 0x100; iVar2 = iVar2 + 1) {
      puVar2[iVar2] = 0;
    }
  }
  *(s16 *)&DAT_007ce6f4 = -1;
  *(u8 *)&DAT_007ce6f0 = 0;
  *(u8 *)&DAT_007ce6c4 = 0;
  *(u8 *)&DAT_007ce6c8 = 0;
  *(u8 *)&DAT_007cdb10 = 1;
  iVar2 = 0;
  puVar3 = (u32 *)DAT_0086be00_abs;
  for (; iVar2 < 8; iVar2 = iVar2 + 1) {
    puVar3[iVar2 * 4] = 0;
  }
  FUN_00455cf0();
  return;
}

#pragma push
#pragma opt_rebuildconditionals off
#pragma opt_loop_invariants on
// FUN_00435060

void FUN_00435060(u8 param_1)
{
  u8 *base;
  int iVar2;
  u8 *puVar1;
  int valid;

  iVar2 = 1;
  for (; iVar2 < 4; iVar2 = iVar2 + 1) {
    base = DAT_008717a0_bytes;
    valid = 0;
    puVar1 = base + iVar2 * 0x1c0;
    if ((*(int *)(puVar1 + 0x48) != 0) && (*(int *)(puVar1 + 0x54) != 0)) {
      valid = 1;
    }
    valid = valid != 0;
    if (valid == 1) {
      *(u8 *)(*(int *)(*(int *)(puVar1 + 0x16c) + 0x3c) + 0x1215) = param_1;
    }
  }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants on
// FUN_004350E0 NONMATCHING

void FUN_004350e0(char param_1,char param_2)

{
  int iVar1;
  short sVar3;
  short sVar4;
  u16 uVar5;
  int iVar6;
  
  for (iVar6 = 1; iVar6 < 4; iVar6 = iVar6 + 1) {
    if ((DAT_008717e8_rows[iVar6 * 0x70 + 0x12] != 0) &&
        (DAT_008717e8_rows[iVar6 * 0x70 + 0x15] != 0) &&
        (param_1 != iVar6)) {
      iVar1 = *(int *)(*(int *)((u8 *)DAT_0087190c + iVar6 * 0x1c0) + 0x3c);
      *(char *)(iVar1 + 0x1215) = param_2;
      if (param_2 == '\x01') {
        FUN_001b0260(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x170),1);
        sVar3 = FUN_00318540_typed((void *)(*(u32 *)(*(int *)(iVar1 + 0xc) + 0x128)),0);
        sVar4 = FUN_001ded40_typed(*(u16 *)((u8 *)DAT_00871948 + iVar6 * 0x1c0));
        if (sVar3 == sVar4) {
          uVar5 = FUN_001dde00_typed(*(u16 *)((u8 *)DAT_00871948 + iVar6 * 0x1c0));
          FUN_003182d0(*(u32 *)(*(int *)(iVar1 + 0xc) + 0x128),0,uVar5,8,1);
        }
      }
      else {
        FUN_001b0260(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x170),0);
      }
    }
  }
  return;
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals off
// FUN_00435260

u32 FUN_00435260(char param_1)
{
  int bVar1;
  int uVar2;
  u32 *puVar3;
  
  bVar1 = 0;
  puVar3 = DAT_008717e8_rows + (int)param_1 * 0x70;
  if ((*puVar3 != 0) &&
      (DAT_008717f4_rows[(int)param_1 * 0x70] != 0)) {
    bVar1 = 1;
  }
  bVar1 = bVar1 != 0;
  uVar2 = 1;
  if (bVar1 == 1) {
    uVar2 = *(char *)(*(int *)(DAT_0087190c_rows[(int)param_1 * 0x70] + 0x3c) + 0x1215);
  }
  return uVar2;
}

#pragma pop
// FUN_004352E0

#pragma push
#pragma opt_rebuildconditionals off
#pragma opt_loop_invariants on
u32 FUN_004352e0(void)
{
  u8 *base;
  int iVar2;
  u8 *row;
  int valid;

  iVar2 = 1;
  for (; iVar2 < 4; iVar2 = iVar2 + 1) {
    base = DAT_008717a0_bytes;
    valid = 0;
    row = base + iVar2 * 0x1c0;
    if ((*(int *)(row + 0x48) != 0) && (*(int *)(row + 0x54) != 0)) {
      valid = 1;
    }
    valid = valid != 0;
    if ((valid == 1) &&
        (*(char *)(*(int *)(*(int *)(row + 0x16c) + 0x3c) + 0x1215) == '\x01')) {
      return 1;
    }
  }
  return 0;
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals off
#pragma opt_loop_invariants on
// FUN_00435370

void FUN_00435370(u8 param_1)
{
  u8 *base;
  int iVar2;
  u8 *puVar1;
  int valid;

  iVar2 = 1;
  for (; iVar2 < 4; iVar2 = iVar2 + 1) {
    base = DAT_008717a0_bytes;
    valid = 0;
    puVar1 = base + iVar2 * 0x1c0;
    if ((*(int *)(puVar1 + 0x48) != 0) && (*(int *)(puVar1 + 0x54) != 0)) {
      valid = 1;
    }
    valid = valid != 0;
    if (valid == 1) {
      *(u8 *)(*(int *)(*(int *)(puVar1 + 0x16c) + 0x3c) + 0x1216) = param_1;
    }
  }
  *(u8 *)&DAT_007cdb10 = param_1;
}
#pragma pop
// FUN_004353F0
s8 FUN_004353f0(int param_1)

{
  s8 uVar1;
  
  uVar1 = 0;
  if (**(u16 **)(param_1 + 0x48) == 0) {
    uVar1 = *(char *)(*(int *)(*(int *)(param_1 + 0x16c) + 0x3c) + 1);
  }
  else if (**(u16 **)(param_1 + 0x48) == 1) {
    uVar1 = *(char *)(*(int *)(*(int *)(param_1 + 0x16c) + 0x3c) + 2);
  }
  return uVar1;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00435440 NONMATCHING

char FUN_00435440(char param_1)

{
  u8 bVar1;
  u32 uVar2;
  u32 uVar3;
  long lVar4;
  char cVar5;
  int iVar6;
  
  cVar5 = '\0';
  for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {
    bVar1 = 0;
    if ((((u8 *)DAT_008717e8)[iVar6 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar6 * 0x70] != 0)) {
      bVar1 = 1;
    }
    if (bVar1) {
      if (iVar6 == 0) {
        uVar2 = FUN_0016c5f0_typed(1);
        uVar3 = FUN_0016c4f0(1);
        if (((long)(uVar3 & 0xffff) < (long)(short)(((uVar2 & 0xffff) * 100) / 100)) &&
           (lVar4 = FUN_001c7160_f32(500.0f,(u8 *)DAT_008717a0 + param_1 * 0x1c0,(u8 *)DAT_008717a0), lVar4 == 1))
        {
          cVar5 = cVar5 + '\x01';
        }
      }
      else {
        uVar2 = FUN_0016c5f0_typed(*(u16 *)((u8 *)DAT_00871948 + (char)iVar6 * 0x1c0));
        uVar3 = FUN_0043c910((char)iVar6);
        if (((long)(uVar3 & 0xffff) < (long)(short)(((uVar2 & 0xffff) * 100) / 100)) &&
           (lVar4 = FUN_001c7160_f32(500.0f,(u8 *)DAT_008717a0 + param_1 * 0x1c0,
                                 (u8 *)DAT_008717a0 + iVar6 * 0x1c0), lVar4 == 1)) {
          cVar5 = cVar5 + '\x01';
        }
      }
    }
  }
  return cVar5;
}

#pragma pop
#pragma push
#pragma opt_loop_invariants on
// FUN_00435660 NONMATCHING

u16 FUN_00435660(char param_1)

{
  short sVar1;
  u8 bVar2;
  u32 uVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  long lVar8;
  
  lVar8 = 0;
  do {
    if (3 < lVar8) {
      return 0xffff;
    }
    iVar7 = (int)lVar8;
    if (lVar8 != param_1) {
      bVar2 = 0;
      iVar5 = iVar7 * 0x1c0;
      if (((short *)((u8 *)DAT_008717e8)[iVar7 * 0x70] != (short *)0x0) &&
         (((u8 *)DAT_008717f4)[iVar7 * 0x70] != 0)) {
        bVar2 = 1;
      }
      if (bVar2) {
        if (lVar8 == 0) {
          uVar3 = FUN_0016c970(*(u16 *)((u8 *)DAT_00871948 + iVar5));
          if ((uVar3 & 0x80) != 0) {
            iVar4 = FUN_001c7160_i32(500.0f,(u8 *)DAT_008717a0 + param_1 * 0x1c0,(u8 *)DAT_008717a0);
joined_r0x004357c4:
            if (iVar4 == 1) {
              return (short)lVar8;
            }
          }
        }
        else {
          cVar6 = '\0';
          sVar1 = *(short *)((u8 *)DAT_008717e8)[iVar7 * 0x70];
          if (sVar1 == 0) {
            cVar6 = *(char *)(*(int *)(*(int *)((u8 *)DAT_0087190c + iVar5) + 0x3c) + 1);
          }
          else if (sVar1 == 1) {
            cVar6 = *(char *)(*(int *)(*(int *)((u8 *)DAT_0087190c + iVar5) + 0x3c) + 2);
          }
          if ((cVar6 == '\x01') &&
             (uVar3 = FUN_0016c970(*(u16 *)((u8 *)DAT_00871948 + iVar5)), (uVar3 & 0x80) != 0)) {
            iVar4 = FUN_001c7160_i32(500.0f,(u8 *)DAT_008717a0 + param_1 * 0x1c0,(u8 *)DAT_008717a0 + iVar5);
            goto joined_r0x004357c4;
          }
        }
      }
    }
    lVar8 = (long)(iVar7 + 1);
  } while( 1 );
}

#pragma pop
// FUN_00435810 NONMATCHING

u8 FUN_00435810(void)

{
  short sVar1;
  u8 bVar2;
  u16 uVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  u8 uVar9;
  u16 uVar10;
  
  uVar10 = 0;
  uVar9 = 0xff;
  for (iVar7 = 1; iVar7 < 4; iVar7 = iVar7 + 1) {
    bVar2 = 0;
    iVar5 = iVar7 * 0x1c0;
    if ((((u8 *)DAT_008717e8)[iVar7 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar7 * 0x70] != 0)) {
      bVar2 = 1;
    }
    if (bVar2) {
      iVar4 = (int)FUN_00173380_typed(*(u16 *)((u8 *)DAT_00871948 + iVar7 * 0x1c0));
      cVar6 = '\0';
      if (*(short *)((u8 *)DAT_008717e8)[iVar7 * 0x70] == 0) {
        cVar6 = *(char *)(*(int *)(*(int *)((u8 *)DAT_0087190c + iVar5) + 0x3c) + 1);
      }
      else if (*(short *)((u8 *)DAT_008717e8)[iVar7 * 0x70] == 1) {
        cVar6 = *(char *)(*(int *)(*(int *)((u8 *)DAT_0087190c + iVar5) + 0x3c) + 2);
      }
      if (cVar6 == '\x01') {
        for (iVar8 = 0; iVar8 < 8; iVar8 = iVar8 + 1) {
          sVar1 = *(short *)(iVar4 + iVar8 * 2);
          if (sVar1 != 0) {
            if (sVar1 == 0xca) {
              uVar3 = FUN_0016c570_typed(*(u16 *)((u8 *)DAT_00871948 + iVar5));
              if (uVar10 < uVar3) {
                uVar9 = (char)iVar7;
                uVar10 = uVar3;
              }
            }
            else if (sVar1 == 0xcb) {
              uVar3 = FUN_0016c570_typed(*(u16 *)((u8 *)DAT_00871948 + iVar5));
              if (uVar10 < uVar3) {
                uVar9 = (char)iVar7;
                uVar10 = uVar3;
              }
            }
          }
        }
      }
    }
  }
  return uVar9;
}

// FUN_004359F0 NONMATCHING

u8 FUN_004359f0(int param_1,u8 param_2,u8 param_3,u32 *param_4,
                 u8 param_5,u8 param_6)

{
  int iVar1;
  int iVar2;
  u8 bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  u32 uVar8;
  u32 uVar9;
  u32 uVar10;
  
  uVar10 = *param_4;
  uVar8 = param_4[1];
  uVar9 = param_4[2];
  iVar1 = *(int *)((int)param_1 + 0x3c);
  *(u8 *)(iVar1 + 0xdc) = param_2;
  *(u8 *)(iVar1 + 0xf8) = param_2;
  *(u8 *)(iVar1 + 0xdd) = param_3;
  *(u8 *)(iVar1 + 0xf9) = param_3;
  *(u32 *)(iVar1 + 0xd0) = uVar10;
  *(u32 *)(iVar1 + 0xd8) = uVar9;
  FUN_001b00c0(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x170));
  FUN_001b0240(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x170),0);
  for (iVar6 = 0; iVar6 < 0x100; iVar6 = iVar6 + 1) {
    iVar7 = iVar1 + iVar6 * 8;
    *(u16 *)(iVar7 + 0x210) = 0;
    *(u16 *)(iVar7 + 0x212) = 0;
    *(u16 *)(iVar7 + 0x214) = 0;
    *(u16 *)(iVar7 + 0x216) = 0;
    *(u32 *)(iVar1 + iVar6 * 4 + 0xa10) = 0;
  }
  *(u32 *)(iVar1 + 0x20c) = 0;
  *(u8 *)(iVar1 + 0x105) = param_2;
  *(u8 *)(iVar1 + 0x106) = param_3;
  *(u8 *)(iVar1 + 0x103) = param_5;
  *(u8 *)(iVar1 + 0x104) = param_6;
  *(u32 *)(iVar1 + 0xe0) = uVar10;
  *(u32 *)(iVar1 + 0xe4) = uVar8;
  *(u32 *)(iVar1 + 0xe8) = uVar9;
  bVar3 = 0;
  do {
    cVar4 = FUN_00433de0(param_1);
    iVar1 = *(int *)((int)param_1 + 0x3c);
    iVar6 = *(int *)(iVar1 + 0xa10);
    *(u32 *)(iVar1 + 0x20c) = 0;
    for (iVar7 = 0; iVar7 < 0xff; iVar7 = iVar7 + 1) {
      iVar5 = iVar1 + iVar7 * 4;
      iVar2 = *(int *)(iVar5 + 0xa14);
      *(int *)(iVar5 + 0xa10) = iVar2;
      if (iVar2 != 0) {
        *(int *)(iVar1 + 0x20c) = *(int *)(iVar1 + 0x20c) + 1;
      }
    }
    iVar6 = iVar1 + iVar6 * 8;
    *(char *)(iVar1 + 0xf8) = (char)*(u16 *)(iVar6 + 0x210);
    *(char *)(iVar1 + 0xf9) = (char)*(u16 *)(iVar6 + 0x212);
    if (cVar4 == '\x01') {
      cVar4 = '\x02';
      bVar3 = 1;
    }
  } while (cVar4 != '\x02');
  if (!bVar3) {
    FUN_004343d0(param_1);
  }
  return !bVar3;
}

#pragma push
#pragma opt_loop_invariants on
// Preserve every helper-facing vector as one aggregate; the remaining normalized diff is a stack/codegen floor.
// FUN_00435C00 NONMATCHING

void FUN_00435c00(int param_1)

{
  u8 bVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  u8 uVar5;
  u8 uVar6;
  u8 uVar7;
  short sVar8;
  short uVar9;
  u16 uVar10;
  int iVar11;
  int iVar12;
  int lVar13;
  int uVar14;
  int lVar15;
  u32 uVar16;
  u8 uVar17;
  u8 bVar18;
  int iVar19;
  u32 uVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  u32 uVar25;
  float in_f21;
  float unaff_f20;
  struct {
    float fStack_220[4];
    float fStack_210[4];
    float fStack_200[4];
    float fStack_1f0[4];
    float fStack_1e0[4];
    float fStack_1d0[4];
    float fStack_1c0[4];
    float fStack_1b0[4];
    float fStack_1a0[4];
    float fStack_190[4];
    float fStack_180[4];
    float fStack_170[4];
    float fStack_160[4];
    float fStack_150[4];
    float fStack_140[4];
    float fStack_130[4];
    float fStack_120[4];
    float fStack_110[4];
    float fStack_100[4];
    float fStack_f0[4];
    float fStack_e0[4];
    float fStack_d0[4];
    float fStack_c0[4];
    float fStack_b0[4];
    float fStack_a0[4];
    float fStack_90[4];
    float fStack_80[4];
    u32 uStack_70[4];
    u32 uStack_60[4];
    float fStack_50[4];
    float fStack_40[4];
    u8 auStack_30[16];
    u8 auStack_20[16];
    float afStack_10[4];
  } stack;
#define fStack_220 stack.fStack_220
#define fStack_210 stack.fStack_210
#define fStack_200 stack.fStack_200
#define fStack_1f0 stack.fStack_1f0
#define fStack_1e0 stack.fStack_1e0
#define fStack_1d0 stack.fStack_1d0
#define fStack_1c0 stack.fStack_1c0
#define fStack_1b0 stack.fStack_1b0
#define fStack_1a0 stack.fStack_1a0
#define fStack_190 stack.fStack_190
#define fStack_180 stack.fStack_180
#define fStack_170 stack.fStack_170
#define fStack_160 stack.fStack_160
#define fStack_150 stack.fStack_150
#define fStack_140 stack.fStack_140
#define fStack_130 stack.fStack_130
#define fStack_120 stack.fStack_120
#define fStack_110 stack.fStack_110
#define fStack_100 stack.fStack_100
#define fStack_f0 stack.fStack_f0
#define fStack_e0 stack.fStack_e0
#define fStack_d0 stack.fStack_d0
#define fStack_c0 stack.fStack_c0
#define fStack_b0 stack.fStack_b0
#define fStack_a0 stack.fStack_a0
#define fStack_90 stack.fStack_90
#define fStack_80 stack.fStack_80
#define uStack_70 stack.uStack_70
#define uStack_60 stack.uStack_60
#define fStack_50 stack.fStack_50
#define fStack_40 stack.fStack_40
#define auStack_30 stack.auStack_30
#define auStack_20 stack.auStack_20
#define afStack_10 stack.afStack_10
  
  iVar2 = *(int *)((int)param_1 + 0x3c);
  iVar12 = DAT_007ce290;
  lVar13 = FUN_0016c970(*(u16 *)((u8 *)DAT_00871948 + *(int *)(iVar2 + 4) * 0x1c0));
  if (lVar13 != 0) {
    iVar19 = *(int *)(iVar2 + 4);
    cVar3 = FUN_00435810();
    if (iVar19 == cVar3) {
      FUN_00456670(param_1,(char)iVar19);
    }
  }
  sVar8 = FUN_00435660(*(u8 *)(iVar2 + 4));
  if (sVar8 != -1) {
    iVar19 = *(int *)(iVar2 + 4);
    cVar3 = FUN_00435810();
    if (iVar19 == cVar3) {
      uVar9 = FUN_00435660((char)iVar19);
      *(u16 *)(iVar2 + 0x1226) = uVar9;
      FUN_00456a90(param_1,*(s8 *)(iVar2 + 4),(s8)uVar9);
    }
  }
  cVar3 = *(char *)(iVar2 + 4);
  for (iVar19 = 1; iVar19 < 4; iVar19 = iVar19 + 1) {
    if (iVar19 != cVar3) {
      bVar18 = 0;
      if ((((u8 *)DAT_008717e8)[iVar19 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar19 * 0x70] != 0)) {
        bVar18 = 1;
      }
      if (((bVar18) && (cVar4 = FUN_004353f0((int)((u8 *)DAT_008717a0 + iVar19 * 0x1c0)), cVar4 == '\x06')) &&
         (lVar13 = FUN_001c7160_f32(500.0f,(u8 *)DAT_008717a0 + cVar3 * 0x1c0,
                                (u8 *)DAT_008717a0 + iVar19 * 0x1c0), lVar13 == 1)) {
        cVar3 = (char)iVar19;
        goto LAB_00435de4;
      }
    }
  }
  cVar3 = '\0';
LAB_00435de4:
  if (cVar3 != '\0') {
    cVar3 = *(char *)(iVar2 + 4);
    for (iVar19 = 1; iVar19 < 4; iVar19 = iVar19 + 1) {
      if (iVar19 != cVar3) {
        bVar18 = 0;
        if ((((u8 *)DAT_008717e8)[iVar19 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar19 * 0x70] != 0)) {
          bVar18 = 1;
        }
        if (((bVar18) && (cVar4 = FUN_004353f0((int)((u8 *)DAT_008717a0 + iVar19 * 0x1c0)), cVar4 == '\x06')) &&
           (lVar13 = FUN_001c7160_f32(500.0f,(u8 *)DAT_008717a0 + cVar3 * 0x1c0,
                                  (u8 *)DAT_008717a0 + iVar19 * 0x1c0), lVar13 == 1)) {
          uVar17 = (u8)iVar19;
          goto LAB_00435ed4;
        }
      }
    }
    uVar17 = 0;
LAB_00435ed4:
    sVar8 = FUN_0043c910(uVar17);
    if (sVar8 == 0) {
      cVar3 = *(char *)(iVar2 + 4);
      for (iVar19 = 1; iVar19 < 4; iVar19 = iVar19 + 1) {
        if (iVar19 != cVar3) {
          bVar18 = 0;
          if ((((u8 *)DAT_008717e8)[iVar19 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar19 * 0x70] != 0)) {
            bVar18 = 1;
          }
          if (((bVar18) && (cVar4 = FUN_004353f0((int)((u8 *)DAT_008717a0 + iVar19 * 0x1c0)), cVar4 == '\x06'))
           && (lVar13 = FUN_001c7160_f32(500.0f,(u8 *)DAT_008717a0 + cVar3 * 0x1c0,
                                       (u8 *)DAT_008717a0 + iVar19 * 0x1c0), lVar13 == 1)) {
            uVar17 = (u8)iVar19;
            goto LAB_00435fc8;
          }
        }
      }
      uVar17 = 0;
LAB_00435fc8:
      sVar8 = FUN_0043c180(uVar17);
      if (sVar8 == 0) {
        cVar3 = *(char *)(iVar2 + 4);
      for (iVar19 = 1; iVar19 < 4; iVar19 = iVar19 + 1) {
        if (iVar19 != cVar3) {
            bVar18 = 0;
            if ((((u8 *)DAT_008717e8)[iVar19 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar19 * 0x70] != 0)) {
              bVar18 = 1;
            }
            if (((bVar18) && (cVar4 = FUN_004353f0((int)((u8 *)DAT_008717a0 + iVar19 * 0x1c0)), cVar4 == '\x06')
               ) && (lVar13 = FUN_001c7160_f32(500.0f,(u8 *)DAT_008717a0 + cVar3 * 0x1c0,
                                            (u8 *)DAT_008717a0 + iVar19 * 0x1c0), lVar13 == 1)) {
              uVar17 = (u8)iVar19;
              goto LAB_004360c0;
            }
          }
        }
        uVar17 = 0;
LAB_004360c0:
        iVar19 = *(int *)(iVar2 + 4);
        sVar8 = FUN_0043c340(uVar17);
        if (iVar19 == sVar8) {
          cVar3 = (char)iVar19;
          for (iVar19 = 1; iVar19 < 4; iVar19 = iVar19 + 1) {
            if (iVar19 != cVar3) {
              bVar18 = 0;
              if ((((u8 *)DAT_008717e8)[iVar19 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar19 * 0x70] != 0)) {
                bVar18 = 1;
              }
              if (((bVar18) &&
                  (cVar4 = FUN_004353f0((int)((u8 *)DAT_008717a0 + iVar19 * 0x1c0)), cVar4 == '\x06')) &&
                 (lVar13 = FUN_001c7160_f32(500.0f,(u8 *)DAT_008717a0 + cVar3 * 0x1c0,
                                        (u8 *)DAT_008717a0 + iVar19 * 0x1c0), lVar13 == 1)) {
                cVar3 = (char)iVar19;
                goto LAB_004361c0;
              }
            }
          }
          cVar3 = '\0';
LAB_004361c0:
          *(short *)(iVar2 + 0x1226) = (short)cVar3;
          *(u8 *)(iVar2 + 0x1254) = 1;
          *(u8 *)(iVar2 + 0x1255) = 0;
        }
      }
      else {
        cVar3 = *(char *)(iVar2 + 4);
        for (iVar19 = 1; iVar19 < 4; iVar19 = iVar19 + 1) {
          if (iVar19 != cVar3) {
            bVar18 = 0;
            if ((((u8 *)DAT_008717e8)[iVar19 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar19 * 0x70] != 0)) {
              bVar18 = 1;
            }
            if (((bVar18) && (cVar4 = FUN_004353f0((int)((u8 *)DAT_008717a0 + iVar19 * 0x1c0)), cVar4 == '\x06')
               ) && (lVar13 = FUN_001c7160_f32(500.0f,(u8 *)DAT_008717a0 + cVar3 * 0x1c0,
                                            (u8 *)DAT_008717a0 + iVar19 * 0x1c0), lVar13 == 1)) {
              uVar17 = (u8)iVar19;
              goto LAB_004362c0;
            }
          }
        }
        uVar17 = 0;
LAB_004362c0:
        iVar19 = *(int *)(iVar2 + 4);
        sVar8 = FUN_0043c180(uVar17);
        if (iVar19 == sVar8) {
          cVar3 = (char)iVar19;
          for (iVar19 = 1; iVar19 < 4; iVar19 = iVar19 + 1) {
            if (iVar19 != cVar3) {
              bVar18 = 0;
              if ((((u8 *)DAT_008717e8)[iVar19 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar19 * 0x70] != 0)) {
                bVar18 = 1;
              }
              if (((bVar18) &&
                  (cVar4 = FUN_004353f0((int)((u8 *)DAT_008717a0 + iVar19 * 0x1c0)), cVar4 == '\x06')) &&
                   (lVar13 = FUN_001c7160_f32(500.0f,(u8 *)DAT_008717a0 + cVar3 * 0x1c0,
                                        (u8 *)DAT_008717a0 + iVar19 * 0x1c0), lVar13 == 1)) {
                cVar3 = (char)iVar19;
                goto LAB_004363c0;
              }
            }
          }
          cVar3 = '\0';
LAB_004363c0:
          *(short *)(iVar2 + 0x1226) = (short)cVar3;
          *(u8 *)(iVar2 + 0x1254) = 1;
          *(u8 *)(iVar2 + 0x1255) = 0;
        }
      }
    }
  }
  switch(*(s8 *)(iVar2 + 0x1223)) {
  case 0:
    FUN_001b0240(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170),1);
    FUN_001b00c0(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
    lVar13 = FUN_001c7130(800.0f,*(u32 *)(iVar2 + 0x24));
    if (lVar13 == 0) {
      lVar13 = FUN_001a0250();
      if ((lVar13 == 1) || (lVar13 = FUN_001a02c0(), lVar13 == 1)) {
        *(u8 *)(iVar2 + 0x1223) = 1;
      }
      else {
        *(u8 *)(iVar2 + 0x1223) = 0xd;
      }
    }
    else {
      uVar14 = FUN_00318b60(((u8 *)DAT_008717f0)[*(int *)(iVar2 + 4) * 0x70]);
      iVar19 = FUN_00318b60(DAT_008717f0);
      lVar13 = FUN_001c6450(*(u32 *)(iVar12 + 0x10),*(u32 *)(iVar12 + 0x14),uVar14,
                            (void *)(iVar19 + 0x30));
      if (lVar13 == 1) {
        if (DAT_007ce6c0 == '\x01') {
          if ((*(char *)(iVar2 + 0x1223) < '\n') || ('\f' < *(char *)(iVar2 + 0x1223))) {
            *(u8 *)(iVar2 + 0x1223) = 10;
          }
        }
        else if ((DAT_007ce6c0 == '\0') && (*(char *)(iVar2 + 0x1223) != '\a')) {
          *(u8 *)(iVar2 + 0x1223) = 7;
          iVar12 = *(int *)(iVar2 + 4);
          if (iVar12 == 3) {
            if (DAT_007ce6d4 == '\x01') {
              FUN_00437e00();
            }
          }
          else if (iVar12 == 2) {
            if (DAT_007ce6d0 == '\x01') {
              FUN_00437e00();
            }
          }
          else if ((iVar12 == 1) && (DAT_007ce6cc == '\x01')) {
            FUN_00437e00();
          }
        }
      }
      else {
        lVar13 = FUN_001a0250();
        if ((lVar13 == 1) || (lVar13 = FUN_001a02c0(), lVar13 == 1)) {
          *(u8 *)(iVar2 + 0x1223) = 1;
        }
        else {
          *(u8 *)(iVar2 + 0x1223) = 0xd;
        }
      }
    }
    if (*(char *)(iVar2 + 0x1222) == '\x01') {
      *(u8 *)(iVar2 + 0x1222) = 0;
    }
    break;
  case 7:
    *(u8 *)((int)(u8 *)DAT_007ce6e4 + *(int *)(iVar2 + 4) + 3) = 0;
    uVar20 = *(u32 *)(iVar2 + 0x24);
    iVar12 = FUN_00318b60(DAT_008717f0);
    fStack_90[0] = *(float *)(iVar12 + 0x30);
    fStack_90[1] = *(float *)(iVar12 + 0x34);
    fStack_90[2] = *(float *)(iVar12 + 0x38);
    iVar12 = FUN_00318b60(DAT_008719b0);
    fStack_a0[0] = *(float *)(iVar12 + 0x30);
    fStack_a0[1] = *(float *)(iVar12 + 0x34);
    fStack_a0[2] = *(float *)(iVar12 + 0x38);
    fStack_80[0] = fStack_90[0] - fStack_a0[0];
    fStack_80[1] = fStack_90[1] - fStack_a0[1];
    fStack_80[2] = fStack_90[2] - fStack_a0[2];
    FUN_004c69f0(fStack_80,fStack_80);
    lVar13 = FUN_001c7130(800.0f,uVar20);
    if (lVar13 == 0) {
      *(u8 *)(iVar2 + 0x1223) = 1;
    }
    else {
      FUN_001b0240(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170),0);
      *(char *)((int)(u8 *)DAT_007ce6e4 + *(int *)(iVar2 + 4) + 3) = (char)*(int *)(iVar2 + 4);
      FUN_001b00c0(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
      iVar12 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0xc) + 0x128));
      uVar20 = *(u32 *)(iVar12 + 0x34);
      uVar25 = *(u32 *)(iVar12 + 0x38);
      *(u32 *)(iVar2 + 0xe0) = *(u32 *)(iVar12 + 0x30);
      *(u32 *)(iVar2 + 0xe4) = uVar20;
      *(u32 *)(iVar2 + 0xe8) = uVar25;
      *(u8 *)(iVar2 + 0x1223) = 8;
    }
    break;
  case 8:
    if (DAT_007ce6bc == '\x01') {
      FUN_00434d30();
    }
    else {
      lVar13 = FUN_0043a0b0(param_1,*(u8 *)(iVar2 + 4));
      if (lVar13 == 1) {
        FUN_0043c7a0(*(u8 *)(iVar2 + 4),5);
      }
      else {
        lVar13 = FUN_001c7130(800.0f,*(u32 *)(iVar2 + 0x24));
        if (lVar13 == 0) {
          *(u8 *)(iVar2 + 0x1223) = 1;
        }
        else {
          uVar20 = *(u32 *)(iVar2 + 0x24);
          iVar12 = FUN_00318b60(DAT_008717f0);
          fStack_c0[0] = *(float *)(iVar12 + 0x30);
          fStack_c0[1] = *(float *)(iVar12 + 0x34);
          fStack_c0[2] = *(float *)(iVar12 + 0x38);
          iVar12 = FUN_00318b60(DAT_008719b0);
          fStack_d0[0] = *(float *)(iVar12 + 0x30);
          fStack_d0[1] = *(float *)(iVar12 + 0x34);
          fStack_d0[2] = *(float *)(iVar12 + 0x38);
          fStack_b0[0] = fStack_c0[0] - fStack_d0[0];
          fStack_b0[1] = fStack_c0[1] - fStack_d0[1];
          fStack_b0[2] = fStack_c0[2] - fStack_d0[2];
          FUN_004c69f0(fStack_b0,fStack_b0);
          lVar13 = FUN_001c7130(150.0f,uVar20);
          if (lVar13 == 0) {
            *(u8 *)(iVar2 + 0x1223) = 9;
          }
          else {
            FUN_001b00c0(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
          }
        }
      }
    }
    break;
  case 9:
    if (DAT_007ce6bc == '\x01') {
      FUN_00434d30();
    }
    else {
      lVar13 = FUN_0043a0b0(param_1,*(u8 *)(iVar2 + 4));
      if (lVar13 == 1) {
        FUN_0043c7a0(*(u8 *)(iVar2 + 4),5);
      }
      else {
        iVar12 = *(int *)(iVar2 + 4);
        if (iVar12 == 3) {
          in_f21 = 300.0f;
          unaff_f20 = 400.0f;
        }
        else if (iVar12 == 2) {
          in_f21 = 200.0f;
          unaff_f20 = 250.0f;
        }
        else if (iVar12 == 1) {
          in_f21 = 200.0f;
          unaff_f20 = 250.0f;
        }
        iVar12 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 8) + 0x128));
        lVar13 = FUN_00434920(in_f21,unaff_f20,param_1,(float *)(iVar12 + 0x30));
        if (lVar13 != 0) {
          *(u8 *)(iVar2 + 0x1223) = 8;
        }
      }
    }
    break;
  case 10:
    *(u8 *)((int)(u8 *)DAT_007ce6e4 + *(int *)(iVar2 + 4) + 3) = 0;
    uVar20 = *(u32 *)(iVar2 + 0x24);
    iVar12 = FUN_00318b60(DAT_008717f0);
    fStack_f0[0] = *(float *)(iVar12 + 0x30);
    fStack_f0[1] = *(float *)(iVar12 + 0x34);
    fStack_f0[2] = *(float *)(iVar12 + 0x38);
    iVar12 = FUN_00318b60(DAT_008719b0);
    fStack_100[0] = *(float *)(iVar12 + 0x30);
    fStack_100[1] = *(float *)(iVar12 + 0x34);
    fStack_100[2] = *(float *)(iVar12 + 0x38);
    fStack_e0[0] = fStack_f0[0] - fStack_100[0];
    fStack_e0[1] = fStack_f0[1] - fStack_100[1];
    fStack_e0[2] = fStack_f0[2] - fStack_100[2];
    FUN_004c69f0(fStack_e0,fStack_e0);
    lVar13 = FUN_001c7130(800.0f,uVar20);
    if (lVar13 == 0) {
      lVar13 = FUN_001a0250();
      if ((lVar13 == 1) || (lVar13 = FUN_001a02c0(), lVar13 == 1)) {
        *(u8 *)(iVar2 + 0x1223) = 1;
      }
      else {
        *(u8 *)(iVar2 + 0x1223) = 0xd;
      }
    }
    else {
      FUN_00434c90(*(u8 *)(iVar2 + 4));
      FUN_001b00c0(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
      *(u8 *)(iVar2 + 0x1223) = 0xb;
    }
    FUN_001b0240(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170),0);
    break;
  case 0xb:
    cVar3 = *(char *)((int)(u8 *)DAT_007ce6e4 + *(int *)(iVar2 + 4) + 3);
    if (cVar3 == '\x03') {
      uVar20 = *(u32 *)(iVar2 + 0x24);
      iVar12 = FUN_00318b60(DAT_008717f0);
      fStack_180[0] = *(float *)(iVar12 + 0x30);
      fStack_180[1] = *(float *)(iVar12 + 0x34);
      fStack_180[2] = *(float *)(iVar12 + 0x38);
      iVar12 = FUN_00318b60(DAT_008719b0);
      fStack_190[0] = *(float *)(iVar12 + 0x30);
      fStack_190[1] = *(float *)(iVar12 + 0x34);
      fStack_190[2] = *(float *)(iVar12 + 0x38);
      fStack_170[0] = fStack_180[0] - fStack_190[0];
      fStack_170[1] = fStack_180[1] - fStack_190[1];
      fStack_170[2] = fStack_180[2] - fStack_190[2];
      FUN_004c69f0(fStack_170,fStack_170);
      lVar13 = FUN_001c7130(150.0f,uVar20);
      if (lVar13 == 0) {
        iVar12 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0xc) + 0x128));
        uVar20 = *(u32 *)(iVar12 + 0x34);
        uVar25 = *(u32 *)(iVar12 + 0x38);
        *(u32 *)(iVar2 + 0xe0) = *(u32 *)(iVar12 + 0x30);
        *(u32 *)(iVar2 + 0xe4) = uVar20;
        *(u32 *)(iVar2 + 0xe8) = uVar25;
        *(u8 *)(iVar2 + 0x1223) = 0xc;
      }
    }
    else if (cVar3 == '\x02') {
      uVar20 = *(u32 *)(iVar2 + 0x24);
      iVar12 = FUN_00318b60(DAT_008717f0);
      fStack_150[0] = *(float *)(iVar12 + 0x30);
      fStack_150[1] = *(float *)(iVar12 + 0x34);
      fStack_150[2] = *(float *)(iVar12 + 0x38);
      iVar12 = FUN_00318b60(DAT_008719b0);
      fStack_160[0] = *(float *)(iVar12 + 0x30);
      fStack_160[1] = *(float *)(iVar12 + 0x34);
      fStack_160[2] = *(float *)(iVar12 + 0x38);
      fStack_140[0] = fStack_150[0] - fStack_160[0];
      fStack_140[1] = fStack_150[1] - fStack_160[1];
      fStack_140[2] = fStack_150[2] - fStack_160[2];
      FUN_004c69f0(fStack_140,fStack_140);
      lVar13 = FUN_001c7130(150.0f,uVar20);
      if (lVar13 == 0) {
        iVar12 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0xc) + 0x128));
        uVar20 = *(u32 *)(iVar12 + 0x34);
        uVar25 = *(u32 *)(iVar12 + 0x38);
        *(u32 *)(iVar2 + 0xe0) = *(u32 *)(iVar12 + 0x30);
        *(u32 *)(iVar2 + 0xe4) = uVar20;
        *(u32 *)(iVar2 + 0xe8) = uVar25;
        *(u8 *)(iVar2 + 0x1223) = 0xc;
      }
    }
    else if (cVar3 == '\x01') {
      uVar20 = *(u32 *)(iVar2 + 0x24);
      iVar12 = FUN_00318b60(DAT_008717f0);
      fStack_120[0] = *(float *)(iVar12 + 0x30);
      fStack_120[1] = *(float *)(iVar12 + 0x34);
      fStack_120[2] = *(float *)(iVar12 + 0x38);
      iVar12 = FUN_00318b60(DAT_008719b0);
      fStack_130[0] = *(float *)(iVar12 + 0x30);
      fStack_130[1] = *(float *)(iVar12 + 0x34);
      fStack_130[2] = *(float *)(iVar12 + 0x38);
      fStack_110[0] = fStack_120[0] - fStack_130[0];
      fStack_110[1] = fStack_120[1] - fStack_130[1];
      fStack_110[2] = fStack_120[2] - fStack_130[2];
      FUN_004c69f0(fStack_110,fStack_110);
      lVar13 = FUN_001c7130(150.0f,uVar20);
      if (lVar13 == 0) {
        iVar12 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0xc) + 0x128));
        uVar20 = *(u32 *)(iVar12 + 0x34);
        uVar25 = *(u32 *)(iVar12 + 0x38);
        *(u32 *)(iVar2 + 0xe0) = *(u32 *)(iVar12 + 0x30);
        *(u32 *)(iVar2 + 0xe4) = uVar20;
        *(u32 *)(iVar2 + 0xe8) = uVar25;
        *(u8 *)(iVar2 + 0x1223) = 0xc;
      }
      else {
        FUN_001b00c0(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
      }
    }
    break;
  case 0xc:
    cVar3 = *(char *)((int)(u8 *)DAT_007ce6e4 + *(int *)(iVar2 + 4) + 3);
    if (cVar3 == '\x03') {
      cVar3 = '\0';
      for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
        if (((u8 *)DAT_007ce6e8)[iVar12] == '\x02') {
          cVar3 = (char)iVar12;
        }
      }
      iVar12 = FUN_00318b60(((u8 *)DAT_008717f0)[(char)(cVar3 + '\x01') * 0x70]);
      lVar13 = FUN_00434770(125.0f,200.0f,param_1,(float *)(iVar12 + 0x30));
      if (lVar13 != 0) {
        *(u8 *)(iVar2 + 0x1223) = 0xb;
      }
      cVar3 = '\0';
      for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
        if (((u8 *)DAT_007ce6e8)[iVar12] == '\x02') {
          cVar3 = (char)iVar12;
        }
      }
      iVar12 = FUN_00318b60(((u8 *)DAT_008717f0)[*(int *)(iVar2 + 4) * 0x70]);
      iVar19 = FUN_00318b60(((u8 *)DAT_008717f0)[(char)(cVar3 + '\x01') * 0x70]);
      fStack_200[0] = *(float *)(iVar19 + 0x30);
      fStack_200[1] = *(float *)(iVar19 + 0x34);
      fStack_200[2] = *(float *)(iVar19 + 0x38);
      fStack_210[0] = *(float *)(iVar12 + 0x30);
      fStack_210[1] = *(float *)(iVar12 + 0x34);
      fStack_210[2] = *(float *)(iVar12 + 0x38);
      fStack_220[0] = fStack_200[0] - fStack_210[0];
      fStack_220[1] = fStack_200[1] - fStack_210[1];
      fStack_220[2] = fStack_200[2] - fStack_210[2];
      fVar21 = (float)FUN_004c69f0(fStack_220,fStack_220);
      fStack_220[1] = 0.0f;
      if (800.0f <= fVar21) {
        lVar13 = FUN_001a0250();
        if ((lVar13 == 1) || (lVar13 = FUN_001a02c0(), lVar13 == 1)) {
          *(u8 *)(iVar2 + 0x1223) = 1;
        }
        else {
          *(u8 *)(iVar2 + 0x1223) = 0xd;
        }
      }
    }
    else if (cVar3 == '\x02') {
      cVar3 = '\0';
      for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
        if (((u8 *)DAT_007ce6e8)[iVar12] == '\x01') {
          cVar3 = (char)iVar12;
        }
      }
      iVar12 = FUN_00318b60(((u8 *)DAT_008717f0)[(char)(cVar3 + '\x01') * 0x70]);
      lVar13 = FUN_00434770(125.0f,200.0f,param_1,(float *)(iVar12 + 0x30));
      if (lVar13 != 0) {
        *(u8 *)(iVar2 + 0x1223) = 0xb;
      }
      cVar3 = '\0';
      for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
        if (((u8 *)DAT_007ce6e8)[iVar12] == '\x01') {
          cVar3 = (char)iVar12;
        }
      }
      iVar12 = FUN_00318b60(((u8 *)DAT_008717f0)[*(int *)(iVar2 + 4) * 0x70]);
      iVar19 = FUN_00318b60(((u8 *)DAT_008717f0)[(char)(cVar3 + '\x01') * 0x70]);
      fStack_1d0[0] = *(float *)(iVar19 + 0x30);
      fStack_1d0[1] = *(float *)(iVar19 + 0x34);
      fStack_1d0[2] = *(float *)(iVar19 + 0x38);
      fStack_1e0[0] = *(float *)(iVar12 + 0x30);
      fStack_1e0[1] = *(float *)(iVar12 + 0x34);
      fStack_1e0[2] = *(float *)(iVar12 + 0x38);
      fStack_1f0[0] = fStack_1d0[0] - fStack_1e0[0];
      fStack_1f0[1] = fStack_1d0[1] - fStack_1e0[1];
      fStack_1f0[2] = fStack_1d0[2] - fStack_1e0[2];
      fVar21 = (float)FUN_004c69f0(fStack_1f0,fStack_1f0);
      fStack_1f0[1] = 0.0f;
      if (800.0f <= fVar21) {
        lVar13 = FUN_001a0250();
        if ((lVar13 == 1) || (lVar13 = FUN_001a02c0(), lVar13 == 1)) {
          *(u8 *)(iVar2 + 0x1223) = 1;
        }
        else {
          *(u8 *)(iVar2 + 0x1223) = 0xd;
        }
      }
    }
    else if (cVar3 == '\x01') {
      iVar12 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 8) + 0x128));
      lVar13 = FUN_00434770(125.0f,200.0f,param_1,(float *)(iVar12 + 0x30));
      if (lVar13 != 0) {
        *(u8 *)(iVar2 + 0x1223) = 0xb;
      }
      iVar12 = FUN_00318b60(((u8 *)DAT_008717f0)[*(int *)(iVar2 + 4) * 0x70]);
      iVar19 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 8) + 0x128));
      fStack_1a0[0] = *(float *)(iVar19 + 0x30);
      fStack_1a0[1] = *(float *)(iVar19 + 0x34);
      fStack_1a0[2] = *(float *)(iVar19 + 0x38);
      fStack_1b0[0] = *(float *)(iVar12 + 0x30);
      fStack_1b0[1] = *(float *)(iVar12 + 0x34);
      fStack_1b0[2] = *(float *)(iVar12 + 0x38);
      fStack_1c0[0] = fStack_1a0[0] - fStack_1b0[0];
      fStack_1c0[1] = fStack_1a0[1] - fStack_1b0[1];
      fStack_1c0[2] = fStack_1a0[2] - fStack_1b0[2];
      fVar21 = (float)FUN_004c69f0(fStack_1c0,fStack_1c0);
      fStack_1c0[1] = 0.0f;
      if (800.0f <= fVar21) {
        lVar13 = FUN_001a0250();
        if ((lVar13 == 1) || (lVar13 = FUN_001a02c0(), lVar13 == 1)) {
          *(u8 *)(iVar2 + 0x1223) = 1;
        }
        else {
          *(u8 *)(iVar2 + 0x1223) = 0xd;
        }
      }
    }
    break;
  case 1:
    afStack_10[0] = (float)(int)*(char *)(iVar2 + 0xdc) * 800.0f;
    afStack_10[2] = (float)(int)*(char *)(iVar2 + 0xdd) * 800.0f;
    *(u8 *)(iVar2 + 0x1235) = 0;
    uVar17 = FUN_001ad910(*(u32 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x54) + 0x1e0));
    uVar5 = FUN_001ad920(*(u32 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x54) + 0x1e0));
    uVar6 = FUN_001ad910(*(u32 *)(DAT_008717f4 + 0x1e0));
    uVar7 = FUN_001ad920(*(u32 *)(DAT_008717f4 + 0x1e0));
    lVar13 = FUN_004359f0(param_1,uVar17,uVar5,(u32 *)(afStack_10),uVar6,uVar7);
    if (lVar13 == 1) {
      *(u8 *)(iVar2 + 0x1223) = 3;
    }
    else {
      FUN_00437e80((u32 *)(auStack_20),0);
      iVar12 = FUN_001ad920(*(u32 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x54) + 0x1e0));
      iVar19 = FUN_001b9120_u32();
      iVar11 = FUN_001ad910(*(u32 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x54) + 0x1e0));
      if (*(char *)(iVar19 + iVar12 * 0x100 + iVar11 * 0x10 + 0x53) == '\0') {
        FUN_00437e80((u32 *)(auStack_30),*(u8 *)(iVar2 + 4));
        uVar17 = FUN_0044f120(*(RwV3d *)(auStack_30));
        uVar5 = FUN_0044f170(*(RwV3d *)(auStack_30));
      }
      else {
        uVar17 = FUN_001ad910(*(u32 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x54) + 0x1e0));
        uVar5 = FUN_001ad920(*(u32 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x54) + 0x1e0));
      }
      uVar6 = FUN_0044f120(*(RwV3d *)(auStack_20));
      uVar7 = FUN_0044f170(*(RwV3d *)(auStack_20));
      lVar13 = FUN_004359f0(param_1,uVar17,uVar5,(u32 *)(afStack_10),uVar6,uVar7);
      if (lVar13 == 1) {
        *(u8 *)(iVar2 + 0x1223) = 3;
        *(u8 *)(iVar2 + 0x1235) = 1;
      }
      else {
        *(u8 *)(iVar2 + 0x1223) = 5;
      }
    }
    break;
  case 3:
    if (*(int *)(iVar2 + 0x20c) == 0) {
      *(u8 *)(iVar2 + 0x1223) = 5;
    }
    else {
      iVar12 = *(int *)(iVar2 + 0x20c) + -1;
      *(int *)(iVar2 + 0x20c) = iVar12;
      *(float *)(iVar2 + 0xec) = (float)(int)*(short *)(iVar12 * 4 + iVar2 + 0xe10) * 800.0f;
      *(float *)(iVar2 + 0xf4) =
           (float)(int)*(short *)(*(int *)(iVar2 + 0x20c) * 4 + iVar2 + 0xe12) * 800.0f;
      uVar9 = FUN_0044f120(*(RwV3d *)(iVar2 + 0xec));
      uVar10 = FUN_0044f170(*(RwV3d *)(iVar2 + 0xec));
      FUN_001bf220(uStack_70,uVar9,uVar10);
      *(u32 *)(iVar2 + 0xec) = uStack_70[0];
      *(u32 *)(iVar2 + 0xf0) = uStack_70[1];
      *(u32 *)(iVar2 + 0xf4) = uStack_70[2];
      *(u8 *)(iVar2 + 0x1223) = 4;
    }
    break;
  case 4:
    lVar13 = FUN_001afa20_typed((DAT_007cafa8),(void*)(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170)),(void*)(iVar2 + 0xec))
    ;
    if (lVar13 == 0) {
      lVar13 = FUN_001ad910(*(u32 *)(DAT_008717f4 + 0x1e0));
      lVar15 = FUN_001ad910(*(u32 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x54) + 0x1e0));
      if (lVar13 == lVar15) {
        lVar13 = FUN_001ad920(*(u32 *)(DAT_008717f4 + 0x1e0));
        lVar15 = FUN_001ad920(*(u32 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x54) + 0x1e0));
        if (lVar13 == lVar15) {
          *(u8 *)(iVar2 + 0x1223) = 0;
        }
      }
    }
    else {
      *(u32 *)(iVar2 + 0xe0) = *(u32 *)(iVar2 + 0xec);
      *(u32 *)(iVar2 + 0xe4) = *(u32 *)(iVar2 + 0xf0);
      *(u32 *)(iVar2 + 0xe8) = *(u32 *)(iVar2 + 0xf4);
      *(u32 *)(iVar2 + 0xd0) = *(u32 *)(iVar2 + 0xec);
      *(u32 *)(iVar2 + 0xd4) = *(u32 *)(iVar2 + 0xf0);
      *(u32 *)(iVar2 + 0xd8) = *(u32 *)(iVar2 + 0xf4);
      *(u8 *)(iVar2 + 0x1223) = 3;
      *(u32 *)(iVar2 + 0xfc) = 0;
    }
    break;
  case 5:
    lVar13 = FUN_001ad910(*(u32 *)(DAT_008717f4 + 0x1e0));
    lVar15 = FUN_001ad910(*(u32 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x54) + 0x1e0));
    if (lVar13 == lVar15) {
      lVar13 = FUN_001ad920(*(u32 *)(DAT_008717f4 + 0x1e0));
      lVar15 = FUN_001ad920(*(u32 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x54) + 0x1e0));
      if (lVar13 != lVar15) goto LAB_00437890;
      *(u8 *)(iVar2 + 0x1223) = 0;
    }
    else {
LAB_00437890:
      bVar1 = *(u8 *)(iVar2 + 0x104);
      uVar16 = FUN_001ad920(*(u32 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x54) + 0x1e0));
      if ((bVar1 == uVar16) &&
         (bVar1 = *(u8 *)(iVar2 + 0x103),
         uVar16 = FUN_001ad910(*(u32 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x54) + 0x1e0)),
         bVar1 == uVar16)) {
        if (*(char *)(iVar2 + 0x1235) != '\0') {
          FUN_001b0240(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170),0);
          iVar12 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 8) + 0x128));
          lVar13 = FUN_001afa20_typed((DAT_007cafa8),(void*)(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170)),(void*)(iVar12 + 0x30));
          if (lVar13 == 0) {
            return;
          }
          *(u8 *)(iVar2 + 0x1223) = 6;
          return;
        }
        *(u8 *)(iVar2 + 0x1223) = 1;
      }
    }
    lVar13 = FUN_001b0220(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
    if (lVar13 == 0) {
      *(u8 *)(iVar2 + 0x1223) = 1;
    }
    break;
  case 6:
    lVar13 = FUN_001b0220(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
    if (lVar13 == 0) {
      *(u8 *)(iVar2 + 0x1223) = 1;
    }
    break;
  case 0xd:
    FUN_001b00c0(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
    iVar12 = (int)FUN_003b5d50_typed(0x12);
    fVar21 = 8000.0f;
    for (; iVar12 != 0; iVar12 = *(int *)(iVar12 + 0xf8)) {
      iVar19 = FUN_00318b60(((u8 *)DAT_008717f0)[*(int *)(iVar2 + 4) * 0x70]);
      fStack_40[0] = *(float *)(iVar12 + 0x100) - *(float *)(iVar19 + 0x30);
      iVar19 = FUN_00318b60(((u8 *)DAT_008717f0)[*(int *)(iVar2 + 4) * 0x70]);
      fStack_40[1] = *(float *)(iVar12 + 0x104) - *(float *)(iVar19 + 0x34);
      iVar19 = FUN_00318b60(((u8 *)DAT_008717f0)[*(int *)(iVar2 + 4) * 0x70]);
      fStack_40[2] = *(float *)(iVar12 + 0x108) - *(float *)(iVar19 + 0x38);
      fVar22 = (float)FUN_004c69f0(fStack_40,fStack_40);
      if (fVar22 < fVar21) {
        uVar20 = *(u32 *)(iVar12 + 0x104);
        uVar25 = *(u32 *)(iVar12 + 0x108);
        *(u32 *)(iVar2 + 0x1228) = *(u32 *)(iVar12 + 0x100);
        *(u32 *)(iVar2 + 0x122c) = uVar20;
        *(u32 *)(iVar2 + 0x1230) = uVar25;
        fVar21 = fVar22;
      }
    }
    lVar13 = FUN_001afa20_typed((DAT_007cafa8),(void*)(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170)),(void*)(iVar2 + 0x1228));
    if (lVar13 != 0) {
      *(u8 *)(iVar2 + 0x1223) = 0xe;
    }
    break;
  case 0xe:
    iVar12 = (int)FUN_003b5d50_typed(0x12);
    fVar21 = 8000.0f;
    cVar3 = '\0';
    bVar18 = 0;
    iVar19 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 8) + 0x128));
    fStack_50[0] = *(float *)(iVar2 + 0x1228) - *(float *)(iVar19 + 0x30);
    iVar19 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 8) + 0x128));
    fStack_50[1] = *(float *)(iVar2 + 0x122c) - *(float *)(iVar19 + 0x34);
    iVar19 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 8) + 0x128));
    fStack_50[2] = *(float *)(iVar2 + 0x1230) - *(float *)(iVar19 + 0x38);
    fVar22 = (float)FUN_004c69f0(fStack_50,fStack_50);
    for (; iVar12 != 0; iVar12 = *(int *)(iVar12 + 0xf8)) {
      if (*(float *)(iVar12 + 0x100) != *(float *)(iVar2 + 0x1228)) {
        if (*(float *)(iVar12 + 0x108) != *(float *)(iVar2 + 0x1230)) {
          fStack_50[0] = *(float *)(iVar12 + 0x100) - *(float *)(iVar2 + 0x1228);
          fStack_50[1] = *(float *)(iVar12 + 0x104) - *(float *)(iVar2 + 0x122c);
          fStack_50[2] = *(float *)(iVar12 + 0x108) - *(float *)(iVar2 + 0x1230);
          fVar23 = (float)FUN_004c69f0(fStack_50,fStack_50);
          iVar19 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 8) + 0x128));
          fStack_50[0] = *(float *)(iVar12 + 0x100) - *(float *)(iVar19 + 0x30);
          iVar19 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 8) + 0x128));
          fStack_50[1] = *(float *)(iVar12 + 0x104) - *(float *)(iVar19 + 0x34);
          iVar19 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 8) + 0x128));
          fStack_50[2] = *(float *)(iVar12 + 0x108) - *(float *)(iVar19 + 0x38);
          fVar24 = (float)FUN_004c69f0(fStack_50,fStack_50);
          if ((fVar24 < fVar22) && (fVar23 + fVar24 < fVar21)) {
            uStack_60[0] = *(u32 *)(iVar12 + 0x100);
            uStack_60[1] = *(u32 *)(iVar12 + 0x104);
            uStack_60[2] = *(u32 *)(iVar12 + 0x108);
            uVar20 = *(u32 *)(iVar12 + 0x104);
            uVar25 = *(u32 *)(iVar12 + 0x108);
            *(u32 *)(iVar2 + 0x1228) = *(u32 *)(iVar12 + 0x100);
            *(u32 *)(iVar2 + 0x122c) = uVar20;
            *(u32 *)(iVar2 + 0x1230) = uVar25;
            *(char *)(iVar2 + 0x1234) = cVar3;
            bVar18 = 1;
            fVar21 = fVar23 + fVar24;
          }
        }
      }
      cVar3 = cVar3 + '\x01';
    }
    lVar13 = FUN_001c7130(500.0f,*(u32 *)(iVar2 + 0x24));
    if (lVar13 == 1) {
      *(u8 *)(iVar2 + 0x1223) = 10;
    }
    else {
      lVar13 = FUN_001b0220(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
      if (lVar13 == 0) {
        iVar12 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 8) + 0x128));
        lVar13 = FUN_001afa20_typed((DAT_007cafa8),(void*)(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170)),(void*)(iVar12 + 0x30));
        if (lVar13 != 0) {
          *(u8 *)(iVar2 + 0x1223) = 0xf;
        }
      }
      else if (bVar18) {
        FUN_001afa20_typed((DAT_007cafa8),(void*)(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170)),(void *)(uStack_60));
      }
    }
    break;
  case 0xf:
    lVar13 = FUN_001c7130(500.0f,*(u32 *)(iVar2 + 0x24));
    if (lVar13 == 1) {
      *(u8 *)(iVar2 + 0x1223) = 10;
    }
    else {
      lVar13 = FUN_001b0220(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
      if (lVar13 == 0) {
        *(u8 *)(iVar2 + 0x1223) = 0xe;
      }
    }
  case 2:
    break;
  }
  return;
}
#undef fStack_220
#undef fStack_210
#undef fStack_200
#undef fStack_1f0
#undef fStack_1e0
#undef fStack_1d0
#undef fStack_1c0
#undef fStack_1b0
#undef fStack_1a0
#undef fStack_190
#undef fStack_180
#undef fStack_170
#undef fStack_160
#undef fStack_150
#undef fStack_140
#undef fStack_130
#undef fStack_120
#undef fStack_110
#undef fStack_100
#undef fStack_f0
#undef fStack_e0
#undef fStack_d0
#undef fStack_c0
#undef fStack_b0
#undef fStack_a0
#undef fStack_90
#undef fStack_80
#undef uStack_70
#undef uStack_60
#undef fStack_50
#undef fStack_40
#undef auStack_30
#undef auStack_20
#undef afStack_10

#pragma pop
// FUN_00437E00

void FUN_00437e00(void)

{
  FUN_00456410_noarg();
  return;
}

// FUN_00437E20

u32 FUN_00437e20(char param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(*(int *)(*(int *)((u8 *)DAT_0087190c_abs + param_1 * 0x1c0) + 0x3c) + 0x1223);
  if (cVar1 < '\a') goto outside;
  if (!(cVar1 < '\r')) goto outside;
  return 0;
outside:
  return 1;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00437E80 NONMATCHING

void FUN_00437e80(u32 *param_1,char param_2)

{
  int iVar1;
  int iVar2;
  u32 uVar3;
  u32 uVar4;
  float fVar5;
  float fVar6;
  u64 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  fVar6 = 8000.0f;
  fStack_28 = 0.0f;
  uStack_30 = 0;
  iVar2 = (int)param_2;
  for (uVar4 = 0; (int)uVar4 < 0x10; uVar4 = uVar4 + 1) {
    for (uVar3 = 0; (int)uVar3 < 0x10; uVar3 = uVar3 + 1) {
      iVar1 = FUN_001b9120_u32();
      if (*(char *)(uVar4 * 0x10 + iVar1 + uVar3 * 0x100 + 0x4a) == '\b') {
        FUN_001bf220(&fStack_10,uVar4 & 0xffff,uVar3 & 0xffff);
        iVar1 = FUN_00318b60(((u8 *)DAT_008717f0)[iVar2 * 0x70]);
        fStack_20 = fStack_10 - *(float *)(iVar1 + 0x30);
        iVar1 = FUN_00318b60(((u8 *)DAT_008717f0)[iVar2 * 0x70]);
        fStack_1c = fStack_c - *(float *)(iVar1 + 0x34);
        iVar1 = FUN_00318b60(((u8 *)DAT_008717f0)[iVar2 * 0x70]);
        fStack_18 = fStack_8 - *(float *)(iVar1 + 0x38);
        fVar5 = (float)FUN_004c69f0(&fStack_20,&fStack_20);
        if (fVar5 < fVar6) {
          uStack_30 = CONCAT44(*(u32 *)&fStack_c,*(u32 *)&fStack_10);
          fStack_28 = fStack_8;
          fVar6 = fVar5;
        }
      }
    }
  }
  *(float *)param_1 = *(float *)&uStack_30;
  *(float *)(param_1 + 1) = *((float *)&uStack_30 + 1);
  *(float *)(param_1 + 2) = fStack_28;
  return;
}

#pragma pop
#pragma push
#pragma opt_loop_invariants on
// FUN_00438010 NONMATCHING

void FUN_00438010(int param_1)

{
  u16 uVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  short sVar5;
  u16 uVar6;
  u16 uVar7;
  short sVar8;
  u32 uVar9;
  long lVar10;
  u8 uVar11;
  u8 bVar12;
  char cVar13;
  int iVar14;
  int iVar15;
  u32 uStack_70 [3];
  u32 uStack_60 [3];
  u8 auStack_50 [16];
  float fStack_40 [3];
  float fStack_30 [3];
  float fStack_20 [3];
  float fStack_10 [3];
  
  iVar14 = DAT_007ce290;
  iVar2 = *(int *)((int)param_1 + 0x3c);
  lVar10 = FUN_00439f60(param_1,*(u8 *)(iVar2 + 4));
  if (lVar10 == 1) {
    FUN_0043c7a0(*(u8 *)(iVar2 + 4),5);
  }
  else {
    FUN_00439400(*(u8 *)(iVar2 + 4));
    lVar10 = FUN_0016c970(*(u16 *)((u8 *)DAT_00871948 + *(int *)(iVar2 + 4) * 0x1c0));
    if (lVar10 != 0) {
      FUN_00456670(param_1,*(u8 *)(iVar2 + 4));
    }
    cVar13 = *(char *)(iVar2 + 4);
    for (iVar15 = 1; (long)iVar15 < 4; iVar15 = iVar15 + 1) {
      if ((long)iVar15 != (long)cVar13) {
        bVar12 = 0;
        if ((((u8 *)DAT_008717e8)[iVar15 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar15 * 0x70] != 0)) {
          bVar12 = 1;
        }
        if (((bVar12) && (cVar4 = FUN_004353f0((int)((u8 *)DAT_008717a0 + iVar15 * 0x1c0)), cVar4 == '\x06')) &&
           (lVar10 = FUN_001c7160(500.0f,(u8 *)DAT_008717a0 + cVar13 * 0x1c0,
                                  (u8 *)DAT_008717a0 + iVar15 * 0x1c0), lVar10 == 1)) {
          cVar13 = (char)iVar15;
          goto LAB_004381a4;
        }
      }
    }
    cVar13 = '\0';
LAB_004381a4:
    if (cVar13 != '\0') {
      cVar13 = *(char *)(iVar2 + 4);
      for (iVar15 = 1; (long)iVar15 < 4; iVar15 = iVar15 + 1) {
        if ((long)iVar15 != (long)cVar13) {
          bVar12 = 0;
          if ((((u8 *)DAT_008717e8)[iVar15 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar15 * 0x70] != 0)) {
            bVar12 = 1;
          }
          if (((bVar12) && (cVar4 = FUN_004353f0((int)((u8 *)DAT_008717a0 + iVar15 * 0x1c0)), cVar4 == '\x06'))
             && (lVar10 = FUN_001c7160(500.0f,(u8 *)DAT_008717a0 + cVar13 * 0x1c0,
                                       (u8 *)DAT_008717a0 + iVar15 * 0x1c0), lVar10 == 1)) {
            uVar11 = (u8)iVar15;
            goto LAB_00438294;
          }
        }
      }
      uVar11 = 0;
LAB_00438294:
      sVar5 = FUN_0043c910(uVar11);
      if (sVar5 == 0) {
        cVar13 = *(char *)(iVar2 + 4);
        for (iVar15 = 1; (long)iVar15 < 4; iVar15 = iVar15 + 1) {
          if ((long)iVar15 != (long)cVar13) {
            bVar12 = 0;
            if ((((u8 *)DAT_008717e8)[iVar15 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar15 * 0x70] != 0)) {
              bVar12 = 1;
            }
            if (((bVar12) && (cVar4 = FUN_004353f0((int)((u8 *)DAT_008717a0 + iVar15 * 0x1c0)), cVar4 == '\x06')
                ) && (lVar10 = FUN_001c7160(500.0f,(u8 *)DAT_008717a0 + cVar13 * 0x1c0,
                                            (u8 *)DAT_008717a0 + iVar15 * 0x1c0), lVar10 == 1)) {
              uVar11 = (u8)iVar15;
              goto LAB_00438388;
            }
          }
        }
        uVar11 = 0;
LAB_00438388:
        sVar5 = FUN_0043c180(uVar11);
        if (sVar5 == 0) {
          cVar13 = *(char *)(iVar2 + 4);
          for (iVar15 = 1; (long)iVar15 < 4; iVar15 = iVar15 + 1) {
            if ((long)iVar15 != (long)cVar13) {
              bVar12 = 0;
              if ((((u8 *)DAT_008717e8)[iVar15 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar15 * 0x70] != 0)) {
                bVar12 = 1;
              }
              if (((bVar12) &&
                  (cVar4 = FUN_004353f0((int)((u8 *)DAT_008717a0 + iVar15 * 0x1c0)), cVar4 == '\x06')) &&
                  (lVar10 = FUN_001c7160(500.0f,(u8 *)DAT_008717a0 + cVar13 * 0x1c0,
                                        (u8 *)DAT_008717a0 + iVar15 * 0x1c0), lVar10 == 1)) {
                uVar11 = (u8)iVar15;
                goto LAB_00438480;
              }
            }
          }
          uVar11 = 0;
LAB_00438480:
          iVar15 = *(int *)(iVar2 + 4);
          sVar5 = FUN_0043c340(uVar11);
          if ((long)iVar15 == (long)sVar5) {
            cVar13 = (char)iVar15;
            for (iVar15 = 1; (long)iVar15 < 4; iVar15 = iVar15 + 1) {
              if ((long)iVar15 != (long)cVar13) {
                bVar12 = 0;
                if ((((u8 *)DAT_008717e8)[iVar15 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar15 * 0x70] != 0))
                {
                  bVar12 = 1;
                }
                if (((bVar12) &&
                    (cVar4 = FUN_004353f0((int)((u8 *)DAT_008717a0 + iVar15 * 0x1c0)), cVar4 == '\x06')) &&
                   (lVar10 = FUN_001c7160(500.0f,(u8 *)DAT_008717a0 + cVar13 * 0x1c0,
                                          (u8 *)DAT_008717a0 + iVar15 * 0x1c0), lVar10 == 1)) {
                  cVar13 = (char)iVar15;
                  goto LAB_00438580;
                }
              }
            }
            cVar13 = '\0';
LAB_00438580:
            *(short *)(iVar2 + 0x1226) = (short)cVar13;
            *(u8 *)(iVar2 + 0x1254) = 1;
            *(u8 *)(iVar2 + 0x1255) = 0;
          }
        }
        else {
          cVar13 = *(char *)(iVar2 + 4);
          for (iVar15 = 1; (long)iVar15 < 4; iVar15 = iVar15 + 1) {
            if ((long)iVar15 != (long)cVar13) {
              bVar12 = 0;
              if ((((u8 *)DAT_008717e8)[iVar15 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar15 * 0x70] != 0)) {
                bVar12 = 1;
              }
              if (((bVar12) &&
                  (cVar4 = FUN_004353f0((int)((u8 *)DAT_008717a0 + iVar15 * 0x1c0)), cVar4 == '\x06')) &&
                  (lVar10 = FUN_001c7160(500.0f,(u8 *)DAT_008717a0 + cVar13 * 0x1c0,
                                        (u8 *)DAT_008717a0 + iVar15 * 0x1c0), lVar10 == 1)) {
                uVar11 = (u8)iVar15;
                goto LAB_00438680;
              }
            }
          }
          uVar11 = 0;
LAB_00438680:
          iVar15 = *(int *)(iVar2 + 4);
          sVar5 = FUN_0043c180(uVar11);
          if ((long)iVar15 == (long)sVar5) {
            cVar13 = (char)iVar15;
            for (iVar15 = 1; (long)iVar15 < 4; iVar15 = iVar15 + 1) {
              if ((long)iVar15 != (long)cVar13) {
                bVar12 = 0;
                if ((((u8 *)DAT_008717e8)[iVar15 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar15 * 0x70] != 0))
                {
                  bVar12 = 1;
                }
                if (((bVar12) &&
                    (cVar4 = FUN_004353f0((int)((u8 *)DAT_008717a0 + iVar15 * 0x1c0)), cVar4 == '\x06')) &&
                   (lVar10 = FUN_001c7160(500.0f,(u8 *)DAT_008717a0 + cVar13 * 0x1c0,
                                          (u8 *)DAT_008717a0 + iVar15 * 0x1c0), lVar10 == 1)) {
                  cVar13 = (char)iVar15;
                  goto LAB_00438780;
                }
              }
            }
            cVar13 = '\0';
LAB_00438780:
            *(short *)(iVar2 + 0x1226) = (short)cVar13;
            *(u8 *)(iVar2 + 0x1254) = 1;
            *(u8 *)(iVar2 + 0x1255) = 0;
          }
        }
      }
    }
    switch(*(u8 *)(iVar2 + 0x1220)) {
    case 0:
      FUN_001b0240(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170),1);
      uVar11 = FUN_001ad910(*(u32 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x54) + 0x1e0));
      *(u8 *)(iVar2 + 0xdc) = uVar11;
      *(u8 *)(iVar2 + 0xf8) = uVar11;
      uVar11 = FUN_001ad920(*(u32 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x54) + 0x1e0));
      *(u8 *)(iVar2 + 0xdd) = uVar11;
      *(u8 *)(iVar2 + 0xf9) = uVar11;
      *(float *)(iVar2 + 0xd0) = (float)(int)*(char *)(iVar2 + 0xdc) * 800.0f;
      *(float *)(iVar2 + 0xd8) = (float)(int)*(char *)(iVar2 + 0xdd) * 800.0f;
      FUN_001b00c0(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
      iVar14 = *(int *)(iVar2 + 4);
      if (iVar14 == 3) {
        *(u8 *)(iVar2 + 0x101) = 2;
      }
      else if (iVar14 == 2) {
        *(u8 *)(iVar2 + 0x101) = 1;
      }
      else if (iVar14 == 1) {
        *(u8 *)(iVar2 + 0x101) = 0;
      }
      *(u8 *)(iVar2 + 0x102) = 1;
      *(u8 *)(iVar2 + 0x1220) = 1;
    case 1:
      do {
        cVar13 = *(char *)(iVar2 + 0x101);
        if (cVar13 == '\0') {
          uVar11 = FUN_00431aa0(param_1);
          *(u8 *)(iVar2 + 0x100) = uVar11;
          *(u8 *)(iVar2 + 0x102) = uVar11;
        }
        else if (cVar13 == '\x01') {
          uVar11 = FUN_00432050(param_1);
          *(u8 *)(iVar2 + 0x100) = uVar11;
          *(u8 *)(iVar2 + 0x102) = uVar11;
        }
        else if (cVar13 == '\x02') {
          uVar11 = FUN_00432600(param_1);
          *(u8 *)(iVar2 + 0x100) = uVar11;
          *(u8 *)(iVar2 + 0x102) = uVar11;
        }
        else if (cVar13 == '\x03') {
          uVar11 = FUN_00432bb0(param_1);
          *(u8 *)(iVar2 + 0x100) = uVar11;
          *(u8 *)(iVar2 + 0x102) = uVar11;
        }
        iVar14 = *(int *)((int)param_1 + 0x3c);
        if (('\0' < *(char *)(iVar14 + (u32)*(u8 *)(iVar14 + 0xf8) +
                              (u32)*(u8 *)(iVar14 + 0xf9) * 0x10 + 0x109)) &&
           (cVar13 = FUN_00433160(param_1), cVar13 != '\0')) {
          *(char *)(iVar2 + 0x100) = cVar13;
          *(char *)(iVar2 + 0x102) = cVar13;
          *(u8 *)(iVar2 + 0x101) = *(u8 *)(iVar2 + 0x101) ^ 1;
        }
        if (*(char *)(iVar2 + 0x100) == '\0') {
          FUN_001b0240(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170),0);
          FUN_001b00c0(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
          FUN_00437e80((u32 *)(auStack_50),*(u8 *)(iVar2 + 4));
          lVar10 = FUN_001afa20_typed((DAT_007cafa8),(void*)(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170)),(void*)(auStack_50));
          if (lVar10 != 0) {
            *(u8 *)(iVar2 + 0x1220) = 5;
            goto switchD_004387bc_caseD_5;
          }
          break;
        }
      } while (*(char *)(iVar2 + 0x100) == '\0');
      *(u8 *)(iVar2 + 0x1220) = 2;
    case 2:
      uVar7 = FUN_0044f120(*(RwV3d *)(iVar2 + 0xd0));
      uVar6 = FUN_0044f170(*(RwV3d *)(iVar2 + 0xd0));
      FUN_001bf220(uStack_60,uVar7,uVar6);
      *(u32 *)(iVar2 + 0xe0) = uStack_60[0];
      *(u32 *)(iVar2 + 0xe4) = uStack_60[1];
      *(u32 *)(iVar2 + 0xe8) = uStack_60[2];
      cVar13 = *(char *)(iVar2 + 0x100);
      if (cVar13 == '\x04') {
        *(float *)(iVar2 + 0xec) = *(float *)(iVar2 + 0xd0) + 800.0f;
        *(u32 *)(iVar2 + 0xf4) = *(u32 *)(iVar2 + 0xd8);
      }
      else if (cVar13 == '\x03') {
        *(u32 *)(iVar2 + 0xec) = *(u32 *)(iVar2 + 0xd0);
        *(float *)(iVar2 + 0xf4) = *(float *)(iVar2 + 0xd8) + 800.0f;
      }
      else if (cVar13 == '\x02') {
        *(float *)(iVar2 + 0xec) = *(float *)(iVar2 + 0xd0) - 800.0f;
        *(u32 *)(iVar2 + 0xf4) = *(u32 *)(iVar2 + 0xd8);
      }
      else if (cVar13 == '\x01') {
        *(u32 *)(iVar2 + 0xec) = *(u32 *)(iVar2 + 0xd0);
        *(float *)(iVar2 + 0xf4) = *(float *)(iVar2 + 0xd8) - 800.0f;
      }
      uVar7 = FUN_0044f120(*(RwV3d *)(iVar2 + 0xec));
      uVar6 = FUN_0044f170(*(RwV3d *)(iVar2 + 0xec));
      FUN_001bf220(uStack_70,uVar7,uVar6);
      *(u32 *)(iVar2 + 0xec) = uStack_70[0];
      *(u32 *)(iVar2 + 0xf0) = uStack_70[1];
      *(u32 *)(iVar2 + 0xf4) = uStack_70[2];
      *(u8 *)(iVar2 + 0x1220) = 3;
      break;
    case 3:
      lVar10 = FUN_001afa20_typed((DAT_007cafa8),(void*)(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170)),(void*)(iVar2 + 0xec));
      if ((lVar10 != 0) &&
         ((iVar14 = FUN_00488f30(), 9 < (short)(iVar14 % 100) ||
          (lVar10 = FUN_001aff70_typed((void *)(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170)),0x3c), lVar10 != 0)
          ))) {
        *(u32 *)(iVar2 + 0xd0) = *(u32 *)(iVar2 + 0xec);
        *(u32 *)(iVar2 + 0xd4) = *(u32 *)(iVar2 + 0xf0);
        *(u32 *)(iVar2 + 0xd8) = *(u32 *)(iVar2 + 0xf4);
        *(u8 *)(iVar2 + 0x1220) = 1;
        cVar13 = FUN_00431880(param_1);
        if (cVar13 == '\x01') {
          *(u8 *)(iVar2 + 0x1220) = 4;
        }
        FUN_004334d0(param_1);
        *(u32 *)(iVar2 + 0xfc) = 0;
      }
      break;
    case 4:
      uVar11 = FUN_004339d0(param_1);
      *(u8 *)(iVar2 + 0x100) = uVar11;
      *(u8 *)(iVar2 + 0x1220) = 2;
      break;
    case 5:
switchD_004387bc_caseD_5:
      lVar10 = FUN_001b0220(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
      if (lVar10 == 0) {
        *(u8 *)(iVar2 + 0x1220) = 0;
      }
      break;
    case 6:
      lVar10 = ((code)FUN_001c7270)(*(u32 *)(iVar14 + 0x14),*(u32 *)(iVar2 + 0x24));
      *(int *)(iVar2 + 0x28) = (int)lVar10;
      if (lVar10 == 0) {
        if (DAT_007ce6bc == '\0') {
          FUN_0043c7a0(*(u8 *)(iVar2 + 4),1);
          *(u8 *)(iVar2 + 0x1214) = 0;
        }
        else if (DAT_007ce6bc == '\x01') {
          FUN_0043c7a0(*(u8 *)(iVar2 + 4),2);
          *(u8 *)(iVar2 + 0x1214) = 1;
        }
        *(u8 *)(iVar2 + 0x1222) = 0;
        return;
      }
      FUN_001b00c0(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
      FUN_001b0240(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170),0);
      iVar14 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x50));
      fStack_10[0] = *(float *)(iVar14 + 0x30);
      fStack_10[1] = *(float *)(iVar14 + 0x34);
      fStack_10[2] = *(float *)(iVar14 + 0x38);
      iVar14 = *(int *)(iVar2 + 0x28);
      fStack_20[0] = *(float *)(iVar14 + 0x10c);
      fStack_20[1] = *(float *)(iVar14 + 0x110);
      fStack_20[2] = *(float *)(iVar14 + 0x114);
      fStack_30[0] = fStack_10[0] - fStack_20[0];
      fStack_30[1] = fStack_10[1] - fStack_20[1];
      fStack_30[2] = fStack_10[2] - fStack_20[2];
      FUN_004c69f0(fStack_30,fStack_30);
      fStack_40[0] = fStack_30[0] * 200.0f + fStack_20[0];
      fStack_40[1] = fStack_30[1] * 200.0f + fStack_20[1];
      fStack_40[2] = fStack_30[2] * 200.0f + fStack_20[2];
      FUN_001afa20_typed((DAT_007cafa8),(void*)(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170)),(void*)fStack_40);
      *(u8 *)(iVar2 + 0x1220) = 7;
    case 7:
      lVar10 = FUN_001b0220(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
      if (lVar10 == 0) {
        piVar3 = *(int **)(iVar2 + 0x28);
        if (piVar3 == (int *)0x0) {
          if (DAT_007ce6bc == '\0') {
            FUN_0043c7a0(*(u8 *)(iVar2 + 4),1);
            *(u8 *)(iVar2 + 0x1214) = 0;
          }
          else if (DAT_007ce6bc == '\x01') {
            FUN_0043c7a0(*(u8 *)(iVar2 + 4),2);
            *(u8 *)(iVar2 + 0x1214) = 1;
          }
          *(u8 *)(iVar2 + 0x1222) = 0;
        }
        else if (*piVar3 == 0) {
          if (DAT_007ce6bc == '\0') {
            FUN_0043c7a0(*(u8 *)(iVar2 + 4),1);
            *(u8 *)(iVar2 + 0x1214) = 0;
          }
          else if (DAT_007ce6bc == '\x01') {
            FUN_0043c7a0(*(u8 *)(iVar2 + 4),2);
            *(u8 *)(iVar2 + 0x1214) = 1;
          }
          *(u8 *)(iVar2 + 0x1222) = 0;
        }
        else if (piVar3[1] == 1) {
          if (DAT_007ce6bc == '\0') {
            FUN_0043c7a0(*(u8 *)(iVar2 + 4),1);
            *(u8 *)(iVar2 + 0x1214) = 0;
          }
          else if (DAT_007ce6bc == '\x01') {
            FUN_0043c7a0(*(u8 *)(iVar2 + 4),2);
            *(u8 *)(iVar2 + 0x1214) = 1;
          }
          *(u8 *)(iVar2 + 0x1222) = 0;
        }
        else {
          FUN_00456620(*(u8 *)(iVar2 + 4));
          if (*(int *)(iVar2 + 0x2c) != 0) {
            *(u32 *)(iVar2 + 0x2c) = 0;
          }
          uVar9 = FUN_0043c690(*(u32 *)(iVar2 + 0x28));
          *(u32 *)(iVar2 + 0x2c) = uVar9;
          uVar1 = *(u16 *)(*(int *)(*(int *)(iVar2 + 0x28) + 0x11c) + 2);
          if (uVar1 != 0xfb5) {
            if (uVar1 < 4000) {
              iVar14 = *(int *)(iVar2 + 4);
              if (iVar14 == 1) {
                DAT_007ce6cc = 1;
              }
              else if (iVar14 == 2) {
                DAT_007ce6d0 = 1;
              }
              else if (iVar14 == 3) {
                DAT_007ce6d4 = 1;
              }
              uVar7 = FUN_0016f490_typed(*(short *)((u8 *)DAT_00871948 + *(int *)(iVar2 + 4) * 0x1c0) + 0x100);
              FUN_001831e0_typed(*(short *)((u8 *)DAT_00871948 + *(int *)(iVar2 + 4) * 0x1c0) + 0x100,uVar7,
                           *(int *)(iVar2 + 0x28) + 0x120);
            }
            else {
              iVar14 = *(int *)(iVar2 + 4);
              if (iVar14 == 1) {
                DAT_007ce6cc = 1;
              }
              else if (iVar14 == 2) {
                DAT_007ce6d0 = 1;
              }
              else if (iVar14 == 3) {
                DAT_007ce6d4 = 1;
              }
              bVar12 = 0;
              for (iVar14 = 0; iVar14 < 0x14; iVar14 = iVar14 + 1) {
                sVar5 = *(short *)(*(int *)(*(int *)(iVar2 + 0x28) + 0x11c) + 2);
                uVar7 = (u16)iVar14;
                sVar8 = FUN_00170a40_typed(*(u16 *)((u8 *)DAT_00871948 + *(int *)(iVar2 + 4) * 0x1c0),
                                     uVar7);
                if (sVar5 == sVar8) {
                  FUN_00170b20_typed(*(u16 *)((u8 *)DAT_00871948 + *(int *)(iVar2 + 4) * 0x1c0),uVar7,
                               sVar5);
                  sVar5 = FUN_00170ab0_typed(*(u16 *)((u8 *)DAT_00871948 + *(int *)(iVar2 + 4) * 0x1c0),
                                       uVar7);
                  iVar14 = (int)sVar5 +
                           (u32)*(u8 *)(*(int *)(*(int *)(iVar2 + 0x28) + 0x11c) + 6);
                  if (99 < iVar14) {
                    iVar14 = 99;
                  }
                  FUN_00170b90_typed(*(u16 *)((u8 *)DAT_00871948 + *(int *)(iVar2 + 4) * 0x1c0),uVar7,
                               (short)iVar14);
                  bVar12 = 1;
                  break;
                }
              }
              if (!bVar12) {
                for (iVar14 = 0; iVar14 < 0x14; iVar14 = iVar14 + 1) {
                  uVar7 = (u16)iVar14;
                  sVar5 = FUN_00170ab0_typed(*(u16 *)((u8 *)DAT_00871948 + *(int *)(iVar2 + 4) * 0x1c0),
                                       uVar7);
                  if (sVar5 < 1) {
                    FUN_00170b20_typed(*(u16 *)((u8 *)DAT_00871948 + *(int *)(iVar2 + 4) * 0x1c0),uVar7,
                                 *(u16 *)(*(int *)(*(int *)(iVar2 + 0x28) + 0x11c) + 2));
                    FUN_00170b90_typed(*(u16 *)((u8 *)DAT_00871948 + *(int *)(iVar2 + 4) * 0x1c0),uVar7,
                                 *(u8 *)(*(int *)(*(int *)(iVar2 + 0x28) + 0x11c) + 6));
                    break;
                  }
                }
              }
            }
          }
          *(u16 *)((u8 *)DAT_0087194a + *(int *)(iVar2 + 4) * 0x1c0) =
               *(u16 *)(*(int *)(*(int *)(iVar2 + 0x28) + 0x11c) + 2);
          *(u16 *)((u8 *)DAT_0087194c + *(int *)(iVar2 + 4) * 0x1c0) =
               (u16)*(u8 *)(*(int *)(*(int *)(iVar2 + 0x28) + 0x11c) + 7);
          *(u32 *)(*(int *)(iVar2 + 0x28) + 4) = 1;
          *(u8 *)(iVar2 + 0x1220) = 8;
          *(u8 *)(iVar2 + 0x1222) = 0;
        }
      }
      break;
    case 8:
      lVar10 = FUN_00195460(*(u32 *)(iVar2 + 0x2c));
      if (lVar10 == 0) {
        if (DAT_007ce6bc == '\0') {
          FUN_0043c7a0(*(u8 *)(iVar2 + 4),1);
          *(u8 *)(iVar2 + 0x1214) = 0;
        }
        else if (DAT_007ce6bc == '\x01') {
          FUN_0043c7a0(*(u8 *)(iVar2 + 4),2);
          *(u8 *)(iVar2 + 0x1214) = 1;
        }
        *(u32 *)(iVar2 + 0x2c) = 0;
      }
    }
  }
  return;
}

#pragma pop
// FUN_00439400 NONMATCHING

void FUN_00439400(char param_1)

{
  int iVar1;
  u8 bVar2;
  int iVar3;
  u32 lVar4;
  u32 uVar5;
  int iVar6;
  
  iVar3 = iGpffffb5a0;
  iVar6 = (int)param_1;
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0087190c + iVar6 * 0x1c0) + 0x3c);
  if (((*(char *)(iVar1 + 0x1222) != '\x01') &&
      (lVar4 = FUN_001c7270_u32(*(u32 *)(iGpffffb5a0 + 0x14),*(u32 *)(iVar1 + 0x24)),
       lVar4 != 0)) && (*(int *)((int)lVar4 + 4) != 1)) {
    bVar2 = 0;
    if (((u8 *)DAT_008717e8)[iVar6 * 0x70] != 0) {
      bVar2 = ((u8 *)DAT_008717f4)[iVar6 * 0x70] != 0;
    }
    if (bVar2) {
      uVar5 = FUN_00318b60(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x50));
      lVar4 = FUN_001c6450_typed(uVar5,(void *)(lVar4 + 0x10c),
                                 *(float *)(iVar3 + 0x10),*(float *)(iVar3 + 0x14));
      if (lVar4 == 1) {
        *(u8 *)(iVar1 + 0x1222) = 1;
        *(u8 *)(iVar1 + 0x1220) = 6;
      }
    }
  }
  return;
}

// FUN_00439520 NONMATCHING

void FUN_00439520(u64 param_1)

{
  int iVar1;
  u8 uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  u32 uVar6;
  long lVar7;
  u64 uVar8;
  long lVar9;
  float fVar10;
  float fVar11;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  u64 uStack_20;
  float fStack_18;
  u64 uStack_10;
  float fStack_8;
  
  iVar4 = iGpffffb5a0;
  iVar1 = *(int *)((int)param_1 + 0x3c);
  switch(*(u8 *)(iVar1 + 0x1218)) {
  case 0:
    lVar9 = FUN_001c6720(*(u32 *)(iGpffffb5a0 + 4),*(u32 *)(iVar1 + 0x24));
    if (lVar9 == 0) {
      FUN_001b0240(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x170),0);
      FUN_001b00c0(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x170));
      if (cGpffffb9cc == '\0') {
        lVar9 = FUN_001c6720(*(u32 *)(iVar4 + 0x14),(u32)(u8 *)DAT_008717a0);
        lVar7 = FUN_001c7130(800.0f,*(u32 *)(iVar1 + 0x24));
        if (lVar7 == 0) {
          lVar9 = FUN_001c6720(*(u32 *)(iVar4 + 0x14),*(u32 *)(iVar1 + 0x24));
        }
      }
      else {
        lVar9 = FUN_001c6720(*(u32 *)(iVar4 + 0x14),*(u32 *)(iVar1 + 0x24));
      }
      if (lVar9 == 0) {
        if (*(char *)(iVar1 + 0x1214) == '\x01') {
          FUN_0043c7a0(*(u8 *)(iVar1 + 4),2);
        }
        else if (*(char *)(iVar1 + 0x1214) == '\0') {
          FUN_0043c7a0(*(u8 *)(iVar1 + 4),1);
        }
      }
      else {
        iVar4 = FUN_00318b60(*(u32 *)((int)lVar9 + 0x50));
        iVar5 = FUN_00318b60(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x50));
        fStack_30 = *(float *)(iVar5 + 0x30);
        fStack_2c = *(float *)(iVar5 + 0x34);
        fStack_28 = *(float *)(iVar5 + 0x38);
        fStack_40 = *(float *)(iVar4 + 0x30);
        fVar10 = *(float *)(iVar4 + 0x34);
        fVar11 = *(float *)(iVar4 + 0x38);
        fStack_50 = fStack_30 - fStack_40;
        fStack_4c = fStack_2c - fVar10;
        fStack_48 = fStack_28 - fVar11;
        fStack_3c = fVar10;
        fStack_38 = fVar11;
        FUN_004c69f0(&fStack_50,&fStack_50);
        fStack_60 = fStack_50 * 200.0f + fStack_40;
        fStack_5c = fStack_4c * 200.0f + fVar10;
        fStack_58 = fStack_48 * 200.0f + fVar11;
        uStack_10 = CONCAT44(fStack_5c,fStack_60);
        fStack_8 = fStack_58;
        FUN_001afa20_typed((uGpffff82b8),(void*)(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x170)),(void*)(&uStack_10));
        *(u8 *)(iVar1 + 0x1218) = 1;
      }
    }
    else {
      *(u8 *)(iVar1 + 0x1218) = 2;
    }
    break;
  case 1:
    lVar9 = FUN_001b0220(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x170));
    if (lVar9 == 0) {
      if (*(int *)(iVar1 + 0x1258) != 0) {
        *(u32 *)(iVar1 + 0x1258) = 0;
      }
      *(u8 *)(iVar1 + 0x1218) = 2;
    }
    break;
  case 2:
    FUN_001b0240(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x170),0);
    lVar9 = FUN_001c6720(*(u32 *)(iVar4 + 0x14),*(u32 *)(iVar1 + 0x24));
    if (lVar9 == 0) {
      *(u8 *)(iVar1 + 0x1218) = 4;
    }
    else {
      lVar7 = FUN_001c6720(*(u32 *)(iVar4 + 4),*(u32 *)(iVar1 + 0x24));
      if (lVar7 == 0) {
        iVar4 = FUN_001c6720(*(u32 *)(iVar4 + 0x14),*(u32 *)(iVar1 + 0x24));
        iVar4 = FUN_00318b60(*(u32 *)(iVar4 + 0x50));
        iVar5 = FUN_00318b60(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x50));
        fStack_70 = *(float *)(iVar5 + 0x30);
        fStack_6c = *(float *)(iVar5 + 0x34);
        fStack_68 = *(float *)(iVar5 + 0x38);
        fStack_80 = *(float *)(iVar4 + 0x30);
        fVar10 = *(float *)(iVar4 + 0x34);
        fVar11 = *(float *)(iVar4 + 0x38);
        fStack_90 = fStack_70 - fStack_80;
        fStack_8c = fStack_6c - fVar10;
        fStack_88 = fStack_68 - fVar11;
        fStack_7c = fVar10;
        fStack_78 = fVar11;
        FUN_004c69f0(&fStack_90,&fStack_90);
        fStack_18 = fStack_88 * 200.0f + fVar11;
        uStack_20 = CONCAT44(fStack_8c * 200.0f + fVar10,fStack_90 * 200.0f + fStack_80);
        FUN_001afa20_typed((uGpffff82b8),(void*)(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x170)),(void*)(&uStack_20));
        *(u8 *)(iVar1 + 0x1218) = 1;
      }
      else {
        lVar7 = FUN_001d8d80(lVar9);
        iVar4 = (int)lVar9;
        if (lVar7 == 0) {
          uVar6 = (u32)FUN_001d8b00_typed((void *)(param_1),(void *)(*(u32 *)(iVar1 + 0x24)),(void *)(lVar9));
          *(u32 *)(iVar1 + 0x1258) = uVar6;
          *(u8 *)(iVar1 + 0x1218) = 3;
          FUN_00453490(*(u32 *)(iVar4 + 0x16c));
          if (*(int *)(iVar4 + 0x18c) == 4) {
            if (((u8 *)DAT_0087193b)[*(int *)(iVar1 + 4) * 0x1c0] == '\0') {
              FUN_00456530((char)*(int *)(iVar1 + 4));
            }
          }
          else if (((u8 *)DAT_0087193b)[*(int *)(iVar1 + 4) * 0x1c0] == '\0') {
            FUN_00456580((char)*(int *)(iVar1 + 4));
          }
          FUN_0044e530(lVar9,*(u8 *)(iVar1 + 4));
          uVar2 = FUN_0016c470(*(u16 *)((u8 *)DAT_00871948 + *(int *)(iVar1 + 4) * 0x1c0));
          *(u8 *)(iVar1 + 0x121a) = uVar2;
        }
        else {
          uVar8 = FUN_001d8d80(lVar9);
          FUN_001d8e60_typed((void *)(uVar8),(void *)(*(u32 *)(iVar1 + 0x24)),(void *)(0));
          uVar6 = FUN_001d8d80(lVar9);
          *(u32 *)(iVar1 + 0x1258) = uVar6;
          FUN_00453490(*(u32 *)(iVar4 + 0x16c));
          *(u8 *)(iVar1 + 0x1218) = 3;
          uVar2 = FUN_0016c470(*(u16 *)((u8 *)DAT_00871948 + *(int *)(iVar1 + 4) * 0x1c0));
          *(u8 *)(iVar1 + 0x121a) = uVar2;
        }
      }
    }
    break;
  case 3:
    lVar9 = FUN_00195460(*(u32 *)(iVar1 + 0x1258));
    if (lVar9 == 0) {
      ((u8 *)DAT_0087193b)[*(int *)(iVar1 + 4) * 0x1c0] = 0;
      *(u8 *)(iVar1 + 0x1218) = 4;
      *(u8 *)(iVar1 + 0x1215) = 0;
      if (*(char *)(iVar1 + 0x1222) == '\x01') {
        *(u8 *)(iVar1 + 0x1222) = 0;
      }
      lVar9 = FUN_002ff790_typed((void *)(((u8 *)DAT_008717e8)[*(int *)(iVar1 + 4) * 0x70]));
      if (lVar9 == 1) {
        *(u8 *)(iVar1 + 0x1218) = 4;
        *(u8 *)(iVar1 + 1) = 6;
        *(u8 *)(iVar1 + 0x1223) = 0;
        *(u8 *)(iVar1 + 0x1220) = 0;
        *(u8 *)(iVar1 + 0x1218) = 0;
      }
    }
    lVar9 = FUN_002ff790_typed((void *)(((u8 *)DAT_008717e8)[*(int *)(iVar1 + 4) * 0x70]));
    if (lVar9 == 1) {
      ((u8 *)DAT_0087193b)[*(int *)(iVar1 + 4) * 0x1c0] = 0;
      *(u8 *)(iVar1 + 0x1218) = 4;
      *(u8 *)(iVar1 + 1) = 6;
      *(u8 *)(iVar1 + 0x1223) = 0;
      *(u8 *)(iVar1 + 0x1220) = 0;
      *(u8 *)(iVar1 + 0x1218) = 0;
      if (*(char *)(iVar1 + 0x1222) == '\x01') {
        *(u8 *)(iVar1 + 0x1222) = 0;
      }
    }
    break;
  case 4:
    sVar3 = FUN_0016c920_typed(*(u16 *)((u8 *)DAT_00871948 + *(int *)(iVar1 + 4) * 0x1c0));
    if (sVar3 == 3) {
      FUN_004564e0(*(u8 *)(iVar1 + 4));
    }
    sVar3 = FUN_0016c920_typed(*(u16 *)((u8 *)DAT_00871948 + *(int *)(iVar1 + 4) * 0x1c0));
    if (sVar3 == 4) {
      FUN_004565d0(*(u8 *)(iVar1 + 4));
    }
    else {
      sVar3 = FUN_0016c920_typed(*(u16 *)((u8 *)DAT_00871948 + *(int *)(iVar1 + 4) * 0x1c0));
      if (sVar3 == 5) {
        FUN_004565d0(*(u8 *)(iVar1 + 4));
      }
    }
    if (*(char *)(iVar1 + 0x1214) == '\x01') {
      FUN_0043c7a0(*(u8 *)(iVar1 + 4),2);
    }
    else if (*(char *)(iVar1 + 0x1214) == '\0') {
      FUN_0043c7a0(*(u8 *)(iVar1 + 4),1);
    }
    break;
  case 5:
    lVar9 = FUN_001d8d80((int)((u8 *)DAT_0086eda0 + *(char *)(iVar1 + 0x1219) * 0x1c0));
    *(int *)(iVar1 + 0x1258) = (int)lVar9;
    if (lVar9 == 0) {
      *(u8 *)(iVar1 + 0x1218) = 4;
    }
    else {
      *(u8 *)(iVar1 + 0x1218) = 6;
      if (*(int *)((u8 *)DAT_0086ef2c + *(char *)(iVar1 + 0x1219) * 0x1c0) == 4) {
        if (((u8 *)DAT_0087193b)[*(int *)(iVar1 + 4) * 0x1c0] == '\0') {
          FUN_00456530((char)*(int *)(iVar1 + 4));
        }
      }
      else if (((u8 *)DAT_0087193b)[*(int *)(iVar1 + 4) * 0x1c0] == '\0') {
        FUN_00456580((char)*(int *)(iVar1 + 4));
      }
    }
    break;
  case 6:
    lVar9 = FUN_00195460(*(u32 *)(iVar1 + 0x1258));
    if (lVar9 == 0) {
      *(u8 *)(iVar1 + 0x1218) = 4;
      *(u8 *)(iVar1 + 0x1215) = 0;
      ((u8 *)DAT_0087193b)[*(int *)(iVar1 + 4) * 0x1c0] = 0;
      if (*(char *)(iVar1 + 0x1222) == '\x01') {
        *(u8 *)(iVar1 + 0x1222) = 0;
      }
      lVar9 = FUN_002ff790_typed((void *)(((u8 *)DAT_008717e8)[*(int *)(iVar1 + 4) * 0x70]));
      if (lVar9 == 1) {
        *(u8 *)(iVar1 + 0x1218) = 4;
        *(u8 *)(iVar1 + 1) = 6;
        *(u8 *)(iVar1 + 0x1223) = 0;
        *(u8 *)(iVar1 + 0x1220) = 0;
        *(u8 *)(iVar1 + 0x1218) = 0;
      }
    }
    lVar9 = FUN_002ff790_typed((void *)(((u8 *)DAT_008717e8)[*(int *)(iVar1 + 4) * 0x70]));
    if (lVar9 == 1) {
      ((u8 *)DAT_0087193b)[*(int *)(iVar1 + 4) * 0x1c0] = 0;
      *(u8 *)(iVar1 + 0x1218) = 4;
      *(u8 *)(iVar1 + 1) = 6;
      *(u8 *)(iVar1 + 0x1223) = 0;
      *(u8 *)(iVar1 + 0x1220) = 0;
      *(u8 *)(iVar1 + 0x1218) = 0;
      if (*(char *)(iVar1 + 0x1222) == '\x01') {
        *(u8 *)(iVar1 + 0x1222) = 0;
      }
    }
  }
  return;
}

// FUN_00439F60 NONMATCHING

u64 FUN_00439f60(u64 param_1,char param_2)

{
  int iVar1;
  int iVar2;
  u32 lVar3;
  u32 uVar4;
  long lVar5;
  
  iVar1 = iGpffffb5a0;
  iVar2 = *(int *)(*(int *)((u8 *)DAT_0087190c + param_2 * 0x1c0) + 0x3c);
  lVar3 = FUN_001c6720(*(u32 *)(iGpffffb5a0 + 0x14),*(u32 *)(iVar2 + 0x24));
  if (*(char *)(iVar2 + 0x1216) == '\0') {
    if (lVar3 != 0) {
      uVar4 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x50));
      iVar2 = FUN_00318b60(*(u32 *)((int)lVar3 + 0x50));
      lVar3 = FUN_001c6450(*(u32 *)(iVar1 + 0x10),*(u32 *)(iVar1 + 0x14),uVar4,
                           (void *)(iVar2 + 0x30));
      if (lVar3 == 1) {
        return 1;
      }
    }
  }
  else if (lVar3 != 0) {
    uVar4 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x50));
    iVar2 = FUN_00318b60(*(u32 *)((int)lVar3 + 0x50));
    lVar5 = FUN_001c6450(*(u32 *)(iVar1 + 0x10),*(u32 *)(iVar1 + 0x14),uVar4,
                         (void *)(iVar2 + 0x30));
    if ((lVar5 == 1) && (lVar3 = FUN_001d8d80(lVar3), lVar3 != 0)) {
      return 1;
    }
  }
  return 0;
}

// FUN_0043A0B0 NONMATCHING

u64 FUN_0043a0b0(u64 param_1,char param_2)

{
  int iVar1;
  int iVar2;
  u32 lVar3;
  u32 uVar4;
  
  iVar1 = iGpffffb5a0;
  iVar2 = *(int *)(*(int *)((u8 *)DAT_0087190c + param_2 * 0x1c0) + 0x3c);
  lVar3 = FUN_001c6720_u32(*(u32 *)(iGpffffb5a0 + 0x14),(u32)(u8 *)DAT_008717a0);
  if ((*(char *)(iVar2 + 0x1216) == '\0') && (lVar3 != 0)) {
    uVar4 = FUN_00318b60(((u8 *)DAT_008717f0)[param_2 * 0x70]);
    iVar2 = FUN_00318b60(*(u32 *)((int)lVar3 + 0x50));
    lVar3 = FUN_001c6450_f32(uVar4,(void *)(iVar2 + 0x30),
                             *(float *)(iVar1 + 0x10),*(float *)(iVar1 + 0x14));
    if (lVar3 == 1) {
      return 1;
    }
  }
  return 0;
}

// FUN_0043A1A0

void FUN_0043a1a0(char param_1,u8 param_2)

{
  int iVar1;
  u8 uVar2;
  
  iVar1 = *(int *)(*(int *)(DAT_0087190c_abs + param_1 * 0x1c0) + 0x3c);
  if (param_1 != '\0') {
    *(u8 *)(iVar1 + 1) = 5;
    *(u8 *)(iVar1 + 0x1218) = 5;
    *(u8 *)(iVar1 + 0x1219) = param_2;
    uVar2 = FUN_0016c470(*(s16 *)(DAT_00871948_abs + *(int *)(iVar1 + 4) * 0x1c0));
    *(u8 *)(iVar1 + 0x121a) = uVar2;
  }
  return;
}

// FUN_0043A230

u32 FUN_0043a230(char param_1)

{
  char cVar1;
  int bVar2;
  u32 uVar3;
  int iVar4;
  
  bVar2 = 0;
  iVar4 = (int)param_1;
  if ((DAT_008717e8_rows[iVar4 * 0x70] != 0) &&
      (DAT_008717f4_rows[iVar4 * 0x70] != 0)) {
    bVar2 = 1;
  }
  bVar2 = bVar2 != 0;
  if (bVar2 == 1) {
    iVar4 = DAT_0087190c_rows[iVar4 * 0x70];
    if (*(char *)(*(int *)(iVar4 + 0x3c) + 1) == '\x05') {
      cVar1 = *(char *)(*(int *)(iVar4 + 0x3c) + 0x1218);
      if (cVar1 == '\x03' || cVar1 == '\x06') {
        return 1;
      }
    }
  }
  return 0;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_0043A2F0 NONMATCHING

void FUN_0043a2f0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  u8 bVar4;
  short sVar5;
  short sVar6;
  u16 uVar7;
  int iVar8;
  u64 uVar9;
  long lVar10;
  
  iVar2 = *(int *)(param_1 + 0x3c);
  cVar1 = *(char *)(iVar2 + 0x1236);
  if (cVar1 == '\x02') {
    return;
  }
  if (cVar1 != '\x01') {
    if (cVar1 != '\0') {
      return;
    }
    cVar1 = *(char *)(iVar2 + 0x1260);
    if (((cVar1 != '\0') && (cVar1 != '\x01')) && (cVar1 != '\x02')) {
      iVar8 = *(int *)(iVar2 + 4) * 0x1c0;
      uVar9 = FUN_0035bc00_u32(10,*(u32 *)((u8 *)DAT_00871954 + iVar8),
                           *(u32 *)((u8 *)DAT_00871958 + iVar8),0);
      FUN_0035c1a0_typed(uVar9,(s32)((u8 *)DAT_008717a0 + *(int *)(iVar2 + 4) * 0x1c0));
      *(u8 *)(iVar2 + 0x1217) = 0;
      return;
    }
    iVar8 = FUN_001b9120_u32();
    if (*(int *)(iVar8 + 0xc) == 0) {
      return;
    }
    iVar8 = FUN_001b9120_u32();
    if (*(int *)(iVar8 + 0x24) == 0) {
      return;
    }
    iVar8 = FUN_001b9120_u32();
    if (*(int *)(iVar8 + 8) == 0) {
      return;
    }
    if (*(int *)(iVar2 + 0x125c) != 0) {
      *(u32 *)(iVar2 + 0x125c) = 0;
    }
    uVar9 = FUN_0035bb40_typed(10,*(u32 *)((u8 *)DAT_00871954 + *(int *)(iVar2 + 4) * 0x1c0),
                         *(u8 *)(iVar2 + 0x1260));
    *(int *)(iVar2 + 0x125c) = (int)uVar9;
    FUN_0035c1a0_typed(uVar9,(s32)((u8 *)DAT_008717a0 + *(int *)(iVar2 + 4) * 0x1c0));
    FUN_001b0260(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170),1);
    sVar5 = FUN_00318540_typed((void *)(*(u32 *)(*(int *)(iVar2 + 0xc) + 0x128)),0);
    sVar6 = FUN_001ded40_typed(*(u16 *)((u8 *)DAT_00871948 + *(int *)(iVar2 + 4) * 0x1c0));
    if (sVar5 == sVar6) {
      uVar7 = FUN_001dde00_typed(*(u16 *)((u8 *)DAT_00871948 + *(int *)(iVar2 + 4) * 0x1c0));
      FUN_003182d0(*(u32 *)(*(int *)(iVar2 + 0xc) + 0x128),0,uVar7,8,1);
    }
    cVar1 = *(char *)(iVar2 + 4);
    for (iVar8 = 1; (long)iVar8 < 4; iVar8 = iVar8 + 1) {
      bVar4 = 0;
      if ((((u8 *)DAT_008717e8)[iVar8 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar8 * 0x70] != 0)) {
        bVar4 = 1;
      }
      if ((bVar4) && ((long)cVar1 != (long)iVar8)) {
        iVar3 = *(int *)(*(int *)((u8 *)DAT_0087190c + iVar8 * 0x1c0) + 0x3c);
        *(u8 *)(iVar3 + 0x1215) = 1;
        FUN_001b0260(*(u32 *)(*(int *)(iVar3 + 0x24) + 0x170),1);
        sVar5 = FUN_00318540_typed((void *)(*(u32 *)(*(int *)(iVar3 + 0xc) + 0x128)),0);
        sVar6 = FUN_001ded40_typed(*(u16 *)((u8 *)DAT_00871948 + iVar8 * 0x1c0));
        if (sVar5 == sVar6) {
          uVar7 = FUN_001dde00_typed(*(u16 *)((u8 *)DAT_00871948 + iVar8 * 0x1c0));
          FUN_003182d0(*(u32 *)(*(int *)(iVar3 + 0xc) + 0x128),0,uVar7,8,1);
        }
      }
    }
    FUN_004532d0(1);
    iVar8 = FUN_001b9120_u32();
    FUN_001e1360(*(u32 *)(iVar8 + 0xc),1);
    iVar8 = FUN_001b9120_u32();
    FUN_001d3810(*(u32 *)(iVar8 + 0x24),1);
    iVar8 = FUN_001b9120_u32();
    FUN_001cd670(*(u32 *)(iVar8 + 8),1);
    FUN_001d8c60_typed(1);
    iVar8 = FUN_001b9120_u32();
    if (*(int *)(iVar8 + 0x18) != 0) {
      iVar8 = FUN_001b9120_u32();
      FUN_00429e80_typed(*(u32 *)(iVar8 + 0x18),0);
    }
    iVar8 = FUN_001b9120_u32();
    if (*(int *)(iVar8 + 0x28) != 0) {
      iVar8 = FUN_001b9120_u32();
      FUN_0018c0c0_typed(*(u32 *)(iVar8 + 0x28),0);
    }
    iVar8 = FUN_001b9120_u32();
    if (*(int *)(iVar8 + 0x2c) != 0) {
      iVar8 = FUN_001b9120_u32();
      FUN_0018eb30_typed(*(u32 *)(iVar8 + 0x2c),0);
    }
    *(u8 *)(iVar2 + 0x1236) = 1;
  }
  lVar10 = FUN_00195460(*(u32 *)(iVar2 + 0x125c));
  if (lVar10 == 0) {
    if (*(char *)(iVar2 + 0x1260) == '\0') {
      iVar8 = *(int *)(iVar2 + 4);
      if (iVar8 == 3) {
        uGpffffb9e4 = 0;
      }
      else if (iVar8 == 2) {
        uGpffffb9e0 = 0;
      }
      else if (iVar8 == 1) {
        uGpffffb9dc = 0;
      }
    }
    cVar1 = *(char *)(iVar2 + 0x1260);
    if (((cVar1 == '\0') || (cVar1 == '\x01')) || (cVar1 == '\x02')) {
      cVar1 = *(char *)(iVar2 + 4);
      for (iVar8 = 1; (long)iVar8 < 4; iVar8 = iVar8 + 1) {
        bVar4 = 0;
        if ((((u8 *)DAT_008717e8)[iVar8 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar8 * 0x70] != 0)) {
          bVar4 = 1;
        }
        if ((bVar4) && ((long)cVar1 != (long)iVar8)) {
          iVar3 = *(int *)(*(int *)((u8 *)DAT_0087190c + iVar8 * 0x1c0) + 0x3c);
          *(u8 *)(iVar3 + 0x1215) = 0;
          FUN_001b0260(*(u32 *)(*(int *)(iVar3 + 0x24) + 0x170),0);
        }
      }
      FUN_001b0260(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170),0);
      FUN_004532d0(0);
      iVar8 = FUN_001b9120_u32();
      FUN_001e1360(*(u32 *)(iVar8 + 0xc),0);
      iVar8 = FUN_001b9120_u32();
      FUN_001d3810(*(u32 *)(iVar8 + 0x24),0);
      iVar8 = FUN_001b9120_u32();
      FUN_001cd670(*(u32 *)(iVar8 + 8),0);
      FUN_001d8c60_typed(0);
      iVar8 = FUN_001b9120_u32();
      if (*(int *)(iVar8 + 0x18) != 0) {
        iVar8 = FUN_001b9120_u32();
        FUN_00429e80_typed(*(u32 *)(iVar8 + 0x18),1);
      }
      iVar8 = FUN_001b9120_u32();
      if (*(int *)(iVar8 + 0x28) != 0) {
        iVar8 = FUN_001b9120_u32();
        FUN_0018c0c0_typed(*(u32 *)(iVar8 + 0x28),1);
      }
      iVar8 = FUN_001b9120_u32();
      if (*(int *)(iVar8 + 0x2c) != 0) {
        iVar8 = FUN_001b9120_u32();
        FUN_0018eb30_typed(*(u32 *)(iVar8 + 0x2c),1);
      }
    }
    *(u8 *)(iVar2 + 0x1217) = 0;
  }
  return;
}

#pragma pop
// FUN_0043A960

void FUN_0043a960(int param_1)
{
  s8 *puVar1;
  
  puVar1 = (s8 *)*(u8 **)(param_1 + 0x3c);
  switch (*(char *)(puVar1 + 0x1237)) {
  case 0:
    puVar1[0x1237] = *(char *)(puVar1 + 0x1237) + 1;
    break;
  case 1:
    puVar1[0x1237] = *(char *)(puVar1 + 0x1237) + 1;
    break;
  case 2:
    puVar1[0x1238] = 0;
    puVar1[0x1239] = -1;
    *(s16 *)(puVar1 + 0x1226) = -1;
    break;
  }
  return;
}

// The duration values selected by cases 0xc0 through 0xc5 are one contiguous
// six-element vector: the later selector indexes every case, including c4/c5.
// Keeping the last two values as separate scalar locals changes the generated
// stack layout and can eliminate their writes under MWCC alias analysis.
// The signed result from FUN_0017b5b0 also preserves the retail sign path.
// FUN_0043A9D0 NONMATCHING

u32 FUN_0043a9d0(u64 param_1,u64 param_2,char param_3)

{
  u8 bVar1;
  u8 bVar2;
  u8 bVar3;
  char cVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  int iVar9;
  u32 uVar10;
  int iVar11;
  long lVar12;
  s32 uVar13;
  short sVar14;
  int iVar15;
  u16 *puVar16;
  short *psVar17;
  int iVar18;
  int iVar19;
  u8 *puVar20;
  short unaff_s3_lo;
  short sVar21;
  int iVar22;
  u32 uVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float unaff_f20;
  char cStack_70;
  u16 uStack_60;
  short sStack_50;
  float afStack_30 [6];
  int iStack_4;
  u8 auStack_8 [4];
  u8 auStack_c [4];
  
  uVar23 = 0xffffffff;
  bVar1 = 0;
  cStack_70 = '\x01';
  bVar2 = 0;
  bVar3 = 0;
  iVar19 = (char)param_1 * 0x1c0;
  iVar8 = (int)FUN_00173380_typed(*(u16 *)((u8 *)DAT_00871948 + iVar19));
  puVar20 = (u8 *)DAT_008717a0 + iVar19;
  for (iVar15 = 0; iVar15 < 8; iVar15 = iVar15 + 1) {
    sVar5 = *(short *)(iVar8 + iVar15 * 2);
    if (sVar5 != 0) {
      switch(sVar5) {
      case 0xc0:
      case 0xc1:
      case 0xc2:
      case 0xc3:
      case 0xc4:
      case 0xc5:
        lVar12 = FUN_0017b660_1arg(*(u16 *)((u8 *)DAT_00871948 + iVar19));
        if (lVar12 == 0) {
          bVar2 = 1;
        }
        bVar1 = 1;
      }
    }
  }
  if (!bVar1) {
    return 3;
  }
  if (!bVar2) {
    return 4;
  }
  cVar4 = FUN_00435440(param_1);
  if (cVar4 == '\0') {
    return 2;
  }
  cVar4 = (char)param_2;
  iVar15 = (int)cVar4;
  iVar9 = iVar15 * 8 - (int)cVar4;
  lVar12 = FUN_002ff790_typed((void *)(((u8 *)DAT_008717e8)[iVar9 * 0x10]));
  if (lVar12 == 1) {
    bVar1 = 0;
    goto LAB_0043acec;
  }
  bVar1 = 0;
  if (((u8 *)DAT_008717e8)[iVar9 * 0x10] != 0) {
    bVar1 = ((u8 *)DAT_008717f4)[iVar9 * 0x10] != 0;
  }
  if (bVar1) {
    if (iVar15 == 0) {
      uVar10 = FUN_0016c5f0_typed(1);
      uVar13 = FUN_0016c4f0(1);
      if ((long)(uVar13 & 0xffff) < (long)(short)(((uVar10 & 0xffff) * 100) / 100)) {
        lVar12 = FUN_001c7160(500.0f,puVar20,(u8 *)DAT_008717a0);
joined_r0x0043acd8:
        bVar1 = 1;
        if (lVar12 == 1) goto LAB_0043acec;
      }
    }
    else {
      uVar10 = FUN_0016c5f0_typed(*(u16 *)((u8 *)DAT_00871948 + iVar9 * 0x40));
      uVar13 = FUN_0043c910(param_2);
      if ((long)(uVar13 & 0xffff) < (long)(short)(((uVar10 & 0xffff) * 100) / 100)) {
        lVar12 = FUN_001c7160(500.0f,puVar20,(u8 *)DAT_008717a0 + iVar9 * 0x40);
        goto joined_r0x0043acd8;
      }
    }
  }
  bVar1 = 0;
LAB_0043acec:
  if (bVar1) {
    if (param_3 == '\x01') {
      cStack_70 = FUN_00435440(param_1);
    }
    if (iVar15 == 0) {
      sStack_50 = FUN_0016c5f0_typed(1);
      sVar5 = FUN_0016c4f0(1);
      sStack_50 = sStack_50 - sVar5;
      sVar5 = FUN_0016c4f0(1);
      uVar10 = FUN_0016c5f0_typed(1);
      uStack_60 = 1;
    }
    else {
      puVar16 = (u16 *)((u8 *)DAT_00871948 + cVar4 * 0x1c0);
      sStack_50 = FUN_0016c5f0_typed(*puVar16);
      sVar5 = FUN_0043c910(param_2);
      sStack_50 = sStack_50 - sVar5;
      sVar5 = FUN_0016c4f0(*puVar16);
      uVar10 = FUN_0016c5f0_typed(*puVar16);
      uStack_60 = *puVar16;
    }
    sVar14 = (short)(((uVar10 & 0xffff) * 100) / 100);
    iVar9 = (int)cStack_70;
    do {
      sVar21 = -1;
      iVar22 = (int)(short)(sVar14 - sVar5) - (int)sVar5;
      for (iVar18 = 0; iVar18 < 8; iVar18 = iVar18 + 1) {
        psVar17 = (short *)(iVar8 + iVar18 * 2);
        if (*psVar17 != 0) {
          switch(*psVar17) {
          case 0xc0:
            lVar12 = FUN_0017b660_1arg(*(u16 *)((u8 *)DAT_00871948 + iVar19));
            if (lVar12 == 0) {
              puVar16 = (u16 *)(iVar8 + iVar18 * 2);
              FUN_0017be10(1,1,*puVar16,0,&iStack_4,auStack_8,auStack_c);
              afStack_30[0] = (float)iStack_4;
              uVar13 = FUN_0017b5b0(1,*puVar16);
              if (uVar13 >= 0) {
                fVar24 = (float)(int)uVar13;
              }
              else {
                fVar24 = (float)(uVar13 & 0xffffffff);
              }
              fVar25 = (float)iVar22 / afStack_30[0];
              fVar26 = 0.0f;
              if (fVar25 < 1.0f) {
                fVar26 = (float)(int)(short)(int)((1.0f - fVar25) * 10.0f) / 10.0f;
              }
              fVar24 = fVar24 * fVar25 + fVar26 * fVar24;
              if (sVar21 == -1) {
                sVar21 = 0;
                unaff_s3_lo = *psVar17;
                unaff_f20 = fVar24;
              }
              else if (fVar24 < unaff_f20) {
                sVar21 = 0;
                unaff_s3_lo = *psVar17;
                unaff_f20 = fVar24;
              }
            }
            break;
          case 0xc1:
            lVar12 = FUN_0017b660_1arg(*(u16 *)((u8 *)DAT_00871948 + iVar19));
            if (lVar12 == 0) {
              puVar16 = (u16 *)(iVar8 + iVar18 * 2);
              FUN_0017be10(1,1,*puVar16,0,&iStack_4,auStack_8,auStack_c);
              afStack_30[1] = (float)iStack_4;
              uVar13 = FUN_0017b5b0(1,*puVar16);
              if (uVar13 >= 0) {
                fVar24 = (float)(int)uVar13;
              }
              else {
                fVar24 = (float)(uVar13 & 0xffffffff);
              }
              fVar25 = (float)iVar22 / afStack_30[1];
              fVar26 = 0.0f;
              if (fVar25 < 1.0f) {
                fVar26 = (float)(int)(short)(int)((1.0f - fVar25) * 10.0f) / 10.0f;
              }
              fVar24 = fVar24 * fVar25 + fVar26 * fVar24;
              if (sVar21 == -1) {
                sVar21 = 1;
                unaff_s3_lo = *psVar17;
                unaff_f20 = fVar24;
              }
              else if (fVar24 < unaff_f20) {
                sVar21 = 1;
                unaff_s3_lo = *psVar17;
                unaff_f20 = fVar24;
              }
            }
            break;
          case 0xc2:
            lVar12 = FUN_0017b660_1arg(*(u16 *)((u8 *)DAT_00871948 + iVar19));
            if (lVar12 == 0) {
              puVar16 = (u16 *)(iVar8 + iVar18 * 2);
              FUN_0017be10(1,1,*puVar16,0,&iStack_4,auStack_8,auStack_c);
              afStack_30[2] = (float)(int)sStack_50;
              uVar13 = FUN_0017b5b0(1,*puVar16);
              if (uVar13 >= 0) {
                fVar24 = (float)(int)uVar13;
              }
              else {
                fVar24 = (float)(uVar13 & 0xffffffff);
              }
              fVar25 = (float)iVar22 / afStack_30[2];
              fVar26 = 0.0f;
              if (fVar25 < 1.0f) {
                fVar26 = (float)(int)(short)(int)((1.0f - fVar25) * 10.0f) / 10.0f;
              }
              fVar24 = fVar24 * fVar25 + fVar26 * fVar24;
              if (sVar21 == -1) {
                sVar21 = 2;
                unaff_s3_lo = *psVar17;
                unaff_f20 = fVar24;
              }
              else if (fVar24 < unaff_f20) {
                sVar21 = 2;
                unaff_s3_lo = *psVar17;
                unaff_f20 = fVar24;
              }
            }
            break;
          case 0xc3:
            lVar12 = FUN_0017b660_1arg(*(u16 *)((u8 *)DAT_00871948 + iVar19));
            if (lVar12 == 0) {
              puVar16 = (u16 *)(iVar8 + iVar18 * 2);
              FUN_0017be10(1,1,*puVar16,0,&iStack_4,auStack_8,auStack_c);
              afStack_30[3] = (float)iStack_4;
              iVar11 = FUN_0017b5b0(1,*puVar16);
              fVar26 = (float)iVar22 / afStack_30[3];
              fVar24 = 0.0f;
              if (fVar26 < 1.0f) {
                fVar24 = (float)(int)(short)(int)((1.0f - fVar26) * 10.0f) / 10.0f;
              }
              fVar24 = (float)(u32)(iVar11 / iVar9) * fVar26 +
                       fVar24 * (float)(u32)(iVar11 / iVar9);
              if (sVar21 == -1) {
                sVar21 = 3;
                unaff_s3_lo = *psVar17;
                unaff_f20 = fVar24;
              }
              else if (fVar24 < unaff_f20) {
                sVar21 = 3;
                unaff_s3_lo = *psVar17;
                unaff_f20 = fVar24;
              }
            }
            break;
          case 0xc4:
            lVar12 = FUN_0017b660_1arg(*(u16 *)((u8 *)DAT_00871948 + iVar19));
            if (lVar12 == 0) {
              puVar16 = (u16 *)(iVar8 + iVar18 * 2);
              FUN_0017be10(1,1,*puVar16,0,&iStack_4,auStack_8,auStack_c);
              afStack_30[4] = (float)iStack_4;
              iVar11 = FUN_0017b5b0(1,*puVar16);
              fVar26 = (float)iVar22 / afStack_30[4];
              fVar24 = 0.0f;
              if (fVar26 < 1.0f) {
                fVar24 = (float)(int)(short)(int)((1.0f - fVar26) * 10.0f) / 10.0f;
              }
              fVar24 = (float)(u32)(iVar11 / iVar9) * fVar26 +
                       fVar24 * (float)(u32)(iVar11 / iVar9);
              if (sVar21 == -1) {
                sVar21 = 4;
                unaff_s3_lo = *psVar17;
                unaff_f20 = fVar24;
              }
              else if (fVar24 < unaff_f20) {
                sVar21 = 4;
                unaff_s3_lo = *psVar17;
                unaff_f20 = fVar24;
              }
            }
            break;
          case 0xc5:
            lVar12 = FUN_0017b660_1arg(*(u16 *)((u8 *)DAT_00871948 + iVar19));
            if (lVar12 == 0) {
              puVar16 = (u16 *)(iVar8 + iVar18 * 2);
              FUN_0017be10(1,1,*puVar16,0,&iStack_4,auStack_8,auStack_c);
              afStack_30[5] = (float)(int)sStack_50;
              iVar11 = FUN_0017b5b0(1,*puVar16);
              fVar26 = (float)iVar22 / afStack_30[5];
              fVar24 = 0.0f;
              if (fVar26 < 1.0f) {
                fVar24 = (float)(int)(short)(int)((1.0f - fVar26) * 10.0f) / 10.0f;
              }
              fVar24 = (float)(u32)(iVar11 / iVar9) * fVar26 +
                       fVar24 * (float)(u32)(iVar11 / iVar9);
              if (sVar21 == -1) {
                sVar21 = 5;
                unaff_s3_lo = *psVar17;
                unaff_f20 = fVar24;
              }
              else if (fVar24 < unaff_f20) {
                sVar21 = 5;
                unaff_s3_lo = *psVar17;
                unaff_f20 = fVar24;
              }
            }
          }
        }
      }
      if (sVar21 == -1) break;
      sVar5 = (short)(int)((float)(int)sVar5 + afStack_30[sVar21]);
      FUN_0017b860_typed(*(u16 *)((u8 *)DAT_00871948 + iVar19),uStack_60,unaff_s3_lo,0);
      sVar6 = FUN_0017b500_ret(*(u16 *)((u8 *)DAT_00871948 + iVar19),unaff_s3_lo);
      if (sVar6 == 1) {
        sVar6 = FUN_0016c4f0(*(u16 *)((u8 *)DAT_00871948 + iVar19));
        sVar7 = FUN_0017b5b0(*(u16 *)((u8 *)DAT_00871948 + iVar19),unaff_s3_lo);
        FUN_0016cf40_typed(*(u16 *)((u8 *)DAT_00871948 + iVar19),sVar6 - sVar7);
      }
      else if (sVar6 == 2) {
        sVar6 = FUN_0016c570_typed(*(u16 *)((u8 *)DAT_00871948 + iVar19));
        sVar7 = FUN_0017b5b0(*(u16 *)((u8 *)DAT_00871948 + iVar19),unaff_s3_lo);
        FUN_0016cf90_typed(*(u16 *)((u8 *)DAT_00871948 + iVar19),sVar6 - sVar7);
      }
      if (((sVar21 == 5) || (sVar21 == 4)) || (sVar21 == 3)) {
        for (iVar18 = 0; iVar18 < 4; iVar18 = iVar18 + 1) {
          if (iVar18 != iVar15) {
            bVar1 = 0;
            if ((((u8 *)DAT_008717e8)[iVar18 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar18 * 0x70] != 0)) {
              bVar1 = 1;
            }
            if ((bVar1) &&
               (lVar12 = FUN_001c7160(500.0f,puVar20,(u8 *)DAT_008717a0 + iVar18 * 0x1c0),
               lVar12 == 1)) {
              FUN_0017b860_typed(*(u16 *)((u8 *)DAT_00871948 + iVar19),
                           *(u16 *)((u8 *)DAT_00871948 + iVar18 * 0x1c0),unaff_s3_lo,0);
            }
          }
        }
        bVar3 = 1;
      }
      uVar23 = 1;
    } while ((long)sVar5 < CONCAT44((int)(((long)sVar14 << 0x30) >> 0x3f),(int)sVar14));
    if (sVar21 == -1) {
      uVar23 = 0;
    }
    if (((short)uVar23 == 1) && (bVar3)) {
      uVar23 = 5;
    }
  }
  else {
    uVar23 = 2;
  }
  return uVar23;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_0043B980 NONMATCHING

short FUN_0043b980(char param_1,u64 param_2)

{
  short sVar1;
  char cVar2;
  u16 uVar3;
  int iVar4;
  long lVar5;
  u32 uVar6;
  int iVar7;
  short *psVar8;
  short sVar9;
  int iVar10;
  u8 auStack_c [4];
  u8 auStack_8 [4];
  u8 auStack_4 [4];
  
  sVar9 = -1;
  if ((char)param_2 == '\0') {
    uVar3 = 1;
  }
  else {
    uVar3 = *(u16 *)((u8 *)DAT_00871948 + (char)param_2 * 0x1c0);
  }
  iVar7 = param_1 * 0x1c0;
  iVar4 = (int)FUN_00173380_typed(*(u16 *)((u8 *)DAT_00871948 + iVar7));
  iVar10 = 0;
  do {
    if (7 < iVar10) {
      return sVar9;
    }
    psVar8 = (short *)(iVar4 + iVar10 * 2);
    sVar1 = *psVar8;
    if (sVar1 != 0) {
      if (sVar1 == 0xca) {
        lVar5 = FUN_0016c970(uVar3);
        if ((lVar5 == 0x80) &&
           (lVar5 = FUN_0017b660_2arg(*(u16 *)((u8 *)DAT_00871948 + iVar7),*psVar8), lVar5 == 0)) {
          psVar8 = (short *)(iVar4 + iVar10 * 2);
          FUN_0017be10(*(u16 *)((u8 *)DAT_00871948 + iVar7),uVar3,*psVar8,0,auStack_4,auStack_8,
                       auStack_c);
          return *psVar8;
        }
        cVar2 = FUN_0043bc20(param_2);
        if ((('\0' < cVar2) && (uVar6 = FUN_0016c970(uVar3), (uVar6 & 0x80) != 0)) &&
           (lVar5 = FUN_0017b660_2arg(*(u16 *)((u8 *)DAT_00871948 + iVar7),*psVar8), lVar5 == 0)) {
          psVar8 = (short *)(iVar4 + iVar10 * 2);
          FUN_0017be10(*(u16 *)((u8 *)DAT_00871948 + iVar7),uVar3,*psVar8,0,auStack_4,auStack_8,
                       auStack_c);
          sVar9 = *psVar8;
        }
      }
      else if (((sVar1 == 0xcb) && (lVar5 = FUN_0016c970(uVar3), lVar5 != 0)) &&
              (lVar5 = FUN_0017b660_2arg(*(u16 *)((u8 *)DAT_00871948 + iVar7),*psVar8), lVar5 == 0)) {
        FUN_0017be10(*(u16 *)((u8 *)DAT_00871948 + iVar7),uVar3,*psVar8,0,auStack_4,auStack_8,
                     auStack_c);
        cVar2 = FUN_0043bc20(param_2);
        if ('\x01' < cVar2) {
          return *psVar8;
        }
        sVar9 = *psVar8;
      }
    }
    iVar10 = iVar10 + 1;
  } while( 1 );
}

#pragma pop
// FUN_0043BC20 NONMATCHING

char FUN_0043bc20(char param_1)

{
  u16 uVar1;
  u32 uVar2;
  char cVar3;
  
  if (param_1 == '\0') {
    uVar1 = 1;
  }
  else {
    uVar1 = *(u16 *)((u8 *)DAT_00871948 + param_1 * 0x1c0);
  }
  cVar3 = 0;
  uVar2 = FUN_0016c970(uVar1);
  if ((uVar2 & 1) != 0) {
    cVar3 = cVar3 + 1;
  }
  uVar2 = FUN_0016c970(uVar1);
  if ((uVar2 & 4) != 0) {
    cVar3 = cVar3 + '\x01';
  }
  uVar2 = FUN_0016c970(uVar1);
  if ((uVar2 & 8) != 0) {
    cVar3 = cVar3 + '\x01';
  }
  FUN_0016c970(uVar1);
  uVar2 = FUN_0016c970(uVar1);
  if ((uVar2 & 0x20) != 0) {
    cVar3 = cVar3 + '\x01';
  }
  uVar2 = FUN_0016c970(uVar1);
  if ((uVar2 & 0x40) != 0) {
    cVar3 = cVar3 + '\x01';
  }
  uVar2 = FUN_0016c970(uVar1);
  if ((uVar2 & 0x80) != 0) {
    cVar3 = cVar3 + '\x01';
  }
  return cVar3;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_0043BDA0 NONMATCHING

short FUN_0043bda0(char param_1,char param_2)

{
  short sVar1;
  int iVar2;
  long lVar3;
  short *psVar4;
  int iVar5;
  short sVar6;
  int iVar7;
  u8 auStack_c [4];
  u8 auStack_8 [4];
  u8 auStack_4 [4];
  
  sVar6 = -1;
  iVar5 = param_1 * 0x1c0;
  iVar2 = (int)FUN_00173380_typed(*(u16 *)((u8 *)DAT_00871948 + iVar5));
  iVar7 = 0;
  do {
    if (7 < iVar7) {
      return sVar6;
    }
    psVar4 = (short *)(iVar2 + iVar7 * 2);
    sVar1 = *psVar4;
    if (sVar1 != 0) {
      if (sVar1 == 0xcc) {
        lVar3 = FUN_0017b660_1arg(*(u16 *)((u8 *)DAT_00871948 + iVar5));
        if ((lVar3 == 0) &&
           (FUN_0017be10(*(u16 *)((u8 *)DAT_00871948 + iVar5),
                         *(u16 *)((u8 *)DAT_00871948 + param_2 * 0x1c0),*psVar4,0,auStack_4,
                         auStack_8,auStack_c), sVar6 != 0xcd)) {
          sVar6 = *psVar4;
        }
      }
      else if ((sVar1 == 0xcd) &&
              (lVar3 = FUN_0017b660_1arg(*(u16 *)((u8 *)DAT_00871948 + iVar5)), lVar3 == 0)) {
        psVar4 = (short *)(iVar2 + iVar7 * 2);
        FUN_0017be10(*(u16 *)((u8 *)DAT_00871948 + iVar5),
                     *(u16 *)((u8 *)DAT_00871948 + param_2 * 0x1c0),*psVar4,0,auStack_4,auStack_8,
                     auStack_c);
        return *psVar4;
      }
    }
    iVar7 = iVar7 + 1;
  } while( 1 );
}

#pragma pop
// FUN_0043BF50 NONMATCHING

void FUN_0043bf50(u64 param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar2 = *(int *)((int)param_1 + 0x3c);
  cVar1 = *(char *)(iVar2 + 0x1255);
  if (cVar1 == '\x02') {
    *(u8 *)(iVar2 + 0x1254) = 0;
  }
  else {
    if (cVar1 != '\x01') {
      if (cVar1 != '\0') {
        return;
      }
      FUN_001b00c0(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
      FUN_001b0240(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170),0);
      iVar3 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x50));
      fStack_10 = *(float *)(iVar3 + 0x30);
      fStack_c = *(float *)(iVar3 + 0x34);
      fStack_8 = *(float *)(iVar3 + 0x38);
      FUN_001ad940(&fStack_50,
                   *(u32 *)(((u8 *)DAT_008717f4)[*(short *)(iVar2 + 0x1226) * 0x70] + 0x1e0));
      fStack_20 = fStack_50;
      fStack_1c = fStack_4c;
      fStack_18 = fStack_48;
      fStack_30 = fStack_10 - fStack_50;
      fStack_2c = fStack_c - fStack_4c;
      fStack_28 = fStack_8 - fStack_48;
      FUN_004c69f0(&fStack_30,&fStack_30);
      fStack_40 = fStack_30 * 200.0f + fStack_20;
      fStack_3c = fStack_2c * 200.0f + fStack_4c;
      fStack_38 = fStack_28 * 200.0f + fStack_48;
      FUN_001afa20_typed((uGpffff82b8),(void*)(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170)),(void*)(&fStack_40));
      *(u8 *)(iVar2 + 0x1255) = 1;
    }
    lVar4 = FUN_001b0220(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
    if (lVar4 == 0) {
      FUN_00456ea0(param_1,*(u8 *)(iVar2 + 4),*(u8 *)(iVar2 + 0x1226));
      *(u8 *)(iVar2 + 0x1255) = 2;
      if (cGpffffb9cc == '\x01') {
        FUN_0043c7a0(*(u8 *)(iVar2 + 4),2);
      }
      else if (cGpffffb9cc == '\0') {
        FUN_0043c7a0(*(u8 *)(iVar2 + 4),1);
      }
    }
  }
  return;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_0043C180 NONMATCHING

u16 FUN_0043c180(char param_1)

{
  short sVar1;
  u8 bVar2;
  u16 uVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  u16 uVar7;
  u16 uVar8;
  int iVar9;
  int iVar10;
  
  uVar8 = 0;
  uVar7 = 0;
  for (iVar10 = 1; (long)iVar10 < 4; iVar10 = iVar10 + 1) {
    if ((long)param_1 != (long)iVar10) {
      bVar2 = 0;
      if ((((u8 *)DAT_008717e8)[iVar10 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar10 * 0x70] != 0)) {
        bVar2 = 1;
      }
      if ((bVar2) && (lVar5 = FUN_001c7160(500.0f,(u8 *)DAT_008717a0 + param_1 * 0x1c0,(u8 *)DAT_008717a0 + iVar10 * 0x1c0), lVar5 == 1))
      {
        iVar6 = iVar10 * 0x1c0;
        iVar4 = (int)FUN_00173380_typed(*(u16 *)((u8 *)DAT_00871948 + iVar6));
        for (iVar9 = 0; iVar9 < 8; iVar9 = iVar9 + 1) {
          sVar1 = *(short *)(iVar4 + iVar9 * 2);
          if (((sVar1 != 0) && (sVar1 == 0xcd)) &&
             (lVar5 = FUN_0017b660_1arg(*(u16 *)((u8 *)DAT_00871948 + iVar6)), lVar5 == 0)) {
            uVar3 = FUN_0016c570_typed(*(u16 *)((u8 *)DAT_00871948 + iVar6));
            if (uVar7 < uVar3) {
              uVar8 = (u16)iVar10;
              uVar7 = uVar3;
            }
          }
        }
      }
    }
  }
  return uVar8;
}

#pragma pop
#pragma push
#pragma opt_loop_invariants on
// FUN_0043C340 NONMATCHING

u16 FUN_0043c340(char param_1)

{
  short sVar1;
  u8 bVar2;
  u16 uVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  u16 uVar7;
  u16 uVar8;
  int iVar9;
  int iVar10;
  
  uVar8 = 0;
  uVar7 = 0;
  for (iVar10 = 1; (long)iVar10 < 4; iVar10 = iVar10 + 1) {
    if ((long)param_1 != (long)iVar10) {
      bVar2 = 0;
      if ((((u8 *)DAT_008717e8)[iVar10 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar10 * 0x70] != 0)) {
        bVar2 = 1;
      }
      if ((bVar2) && (lVar5 = FUN_001c7160(500.0f,(u8 *)DAT_008717a0 + param_1 * 0x1c0,(u8 *)DAT_008717a0 + iVar10 * 0x1c0), lVar5 == 1))
      {
        iVar6 = iVar10 * 0x1c0;
        iVar4 = (int)FUN_00173380_typed(*(u16 *)((u8 *)DAT_00871948 + iVar6));
        for (iVar9 = 0; iVar9 < 8; iVar9 = iVar9 + 1) {
          sVar1 = *(short *)(iVar4 + iVar9 * 2);
          if (((sVar1 != 0) && (sVar1 == 0xcc)) &&
             (lVar5 = FUN_0017b660_1arg(*(u16 *)((u8 *)DAT_00871948 + iVar6)), lVar5 == 0)) {
            uVar3 = FUN_0016c570_typed(*(u16 *)((u8 *)DAT_00871948 + iVar6));
            if (uVar7 < uVar3) {
              uVar8 = (u16)iVar10;
              uVar7 = uVar3;
            }
          }
        }
      }
    }
  }
  return uVar8;
}

#pragma pop
// FUN_0043C500

u32 FUN_0043c500(int param_1)
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  u32 lVar4;

  pcVar2 = *(char **)(param_1 + 0x3c);
  cVar1 = *pcVar2;
  switch (cVar1) {
  case '\0':
    lVar4 = FUN_003b5d10_eb90(*(u16 *)(*(int *)(pcVar2 + 8) + 8));
    *(int *)(pcVar2 + 4) = (int)lVar4;
    if (lVar4 == 0) {
      *pcVar2 = '\x02';
      break;
    }
    iVar3 = *(int *)((int)lVar4 + 0x104);
    if (iVar3 == 0) {
      *pcVar2 = '\x02';
      break;
    }
    FUN_003182d0(iVar3,0,1,0,0);
    *pcVar2 = '\x01';
  case '\x01':
    iVar3 = *(int *)(*(int *)(pcVar2 + 4) + 0x104);
    if (iVar3 == 0) {
      *pcVar2 = '\x02';
      FUN_001d22a0_typed((void *)(*(u32 *)(pcVar2 + 8)));
    }
    else if ((*(u32 *)(*(int *)(pcVar2 + 4) + 0x28) & 2) != 0) {
      if (*(u8 *)(iVar3 + 0xee) == '\x01') {
        FUN_001d22a0_typed((void *)(*(u32 *)(pcVar2 + 8)));
        *pcVar2 = '\x02';
      }
    }
    else {
      FUN_001d22a0_typed((void *)(*(u32 *)(pcVar2 + 8)));
      *pcVar2 = '\x02';
    }
    break;
  case '\x02':
    return 0xffffffff;
  case '\x03':
    break;
  }
  return 0;
}

// FUN_0043C660

void FUN_0043c660(int param_1)

{
  DAT_0096017c_abs[0](*(u32 *)(param_1 + 0x3c));
  return;
}

// FUN_0043C690

u32 FUN_0043c690(u32 param_1)

{
  u32 lVar1;
  u32 uVar2;
  
  lVar1 = (*DAT_00960184_abs)(1,0xc,0x40000);
  if (lVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00194b80_u32(0,10,DAT_006b4630,FUN_0043c500,FUN_0043c660,lVar1);
    *(u8 *)lVar1 = 0;
    *(u32 *)((u8 *)lVar1 + 8) = param_1;
  }
  return uVar2;
}

// FUN_0043C730

u8 FUN_0043c730(char param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0087190c_abs + param_1 * 0x1c0) + 0x3c);
  if (*(char *)(iVar1 + 0x1217) != '\x01') goto check_second;
  return 0;
check_second:
  if (*(char *)(iVar1 + 0x1238) != '\x01') goto check_third;
  return 0;
check_third:
  return *(char *)(iVar1 + 0x1254) != '\x01';
}

// FUN_0043C7A0

void FUN_0043c7a0(char param_1,u8 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0087190c_abs + param_1 * 0x1c0) + 0x3c);
  *(u8 *)(iVar1 + 1) = param_2;
  *(u8 *)(iVar1 + 0x1223) = 0;
  *(u8 *)(iVar1 + 0x1224) = 0;
  *(u8 *)(iVar1 + 0x1220) = 0;
  *(u8 *)(iVar1 + 0x1221) = 0;
  *(u8 *)(iVar1 + 0x1218) = 0;
  return;
}

// FUN_0043C7F0 NONMATCHING

u8 FUN_0043c7f0(char param_1)

{
  u8 bVar1;
  u8 uVar2;
  int iVar3;
  
  if (param_1 == '\0') {
    uVar2 = 0;
  }
  else if (param_1 < '\x04') {
    bVar1 = 0;
    iVar3 = (int)param_1;
    if ((((u8 *)DAT_008717e8)[iVar3 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar3 * 0x70] != 0)) {
      bVar1 = 1;
    }
    if (bVar1) {
      uVar2 = *(u8 *)(*(int *)(*(int *)((u8 *)DAT_0087190c + iVar3 * 0x1c0) + 0x3c) + 1);
    }
    else {
      uVar2 = 6;
    }
  }
  else {
    bVar1 = 0;
    iVar3 = param_1 * 0x1c0;
    if ((*(int *)((u8 *)DAT_0086e6e8 + iVar3) != 0) && (*(int *)((u8 *)DAT_0086e6f4 + iVar3) != 0)) {
      bVar1 = 1;
    }
    if (bVar1) {
      uVar2 = *(u8 *)(*(int *)(((u8 *)DAT_0086e80c)[param_1 * 0x70] + 0x3c) + 2);
    }
    else {
      uVar2 = 6;
    }
  }
  return uVar2;
}

// FUN_0043C910 NONMATCHING

u32 FUN_0043c910(char param_1)

{
  u8 bVar1;
  u32 uVar2;
  
  if (param_1 == '\0') {
    uVar2 = FUN_0016c5f0_typed(1);
  }
  else if (param_1 < '\x04') {
    bVar1 = 0;
    if ((((u8 *)DAT_008717e8)[param_1 * 0x70] != 0) && (((u8 *)DAT_008717f4)[param_1 * 0x70] != 0)) {
      bVar1 = 1;
    }
    if (bVar1) {
      uVar2 = (u32)*(u16 *)(*(int *)(((u8 *)DAT_008717e8)[param_1 * 0x70] + 4) + 8);
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    bVar1 = 0;
    if ((*(int *)((u8 *)DAT_0086e6e8 + param_1 * 0x1c0) != 0) &&
       (*(int *)((u8 *)DAT_0086e6f4 + param_1 * 0x1c0) != 0)) {
      bVar1 = 1;
    }
    if (bVar1) {
      uVar2 = (u32)*(u16 *)(*(int *)(*(int *)((u8 *)DAT_0086e6e8 + param_1 * 0x1c0) + 4) + 8);
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_0043CA30 NONMATCHING

u32 FUN_0043ca30(int param_1)

{
  char cVar1;
  char *puVar2;
  char cVar3;
  char cVar4;
  int iVar5;
  u32 uVar6;
  u32 uVar7;
  int lVar8;
  short sVar9;
  short sVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  u8 bVar14;
  int lVar15;
  short *psVar16;
  int iVar17;
  u8 uVar18;
  u16 uVar19;
  float fVar20;
  int uVar21;
  float fVar22;
  float fVar23;
  u8 auStack_4 [4];
  int iStack_8;
  int iStack_c;
  int iStack_10;
  int iStack_14;
  int iStack_18;
  int iStack_1c;
  int iStack_20;
  int iStack_24;
  int iStack_28;
  int iStack_2c;
  int iStack_30;
  int iStack_34;
  int iStack_38;
  float afStack_40 [2];
  float afStack_48 [2];
  float afStack_50 [2];
  float afStack_58 [2];
  float afStack_60 [2];
  float fStack_64;
  float fStack_68;
  float fStack_6c;
  float fStack_70;
  float fStack_74;
  float fStack_78;
  float fStack_7c;
  u8 auStack_80 [4];
  float afStack_88 [2];
  float fStack_8c;
  float fStack_90;
  float fStack_94;
  float fStack_98;
  float afStack_a0 [2];
  u32 uStack_a4;
  u32 uStack_a8;
  float afStack_b0 [2];
  float fStack_b4;
  float fStack_b8;
  float fStack_bc;
  float fStack_c0;
  u32 uStack_c4;
  u32 uStack_c8;
  u32 uStack_cc;
  u32 uStack_d0;
  u32 uStack_d4;
  u32 uStack_d8;
  u32 uStack_dc;
  u32 uStack_e0;
  
  puVar2 = *(char **)((int)param_1 + 0x3c);
  switch(*puVar2) {
  case 0:
    uVar6 = FUN_00100d80(0x6b4820,1);
    *(u32 *)(puVar2 + 0x24c) = uVar6;
    *puVar2 = 1;
  case 1:
    lVar8 = FUN_001016b0_typed((void *)(*(u32 *)(puVar2 + 0x24c)));
    if (lVar8 != 0) {
      if (puVar2[0x251] == '\0') {
        FUN_00449ed0();
        uVar6 = FUN_00100d80(0x6b4840,0);
        *(u32 *)(puVar2 + 0x240) = uVar6;
        *(u8 *)(DAT_007ce6ec + 0xac) = puVar2[0x250];
        *puVar2 = 2;
        FUN_001a0040_typed(0,0);
      }
      else {
        *puVar2 = 4;
        if (puVar2[0x250] == '\0') {
          *puVar2 = 6;
        }
      }
    }
    break;
  case 2:
    lVar8 = FUN_001016b0_typed((void *)(*(u32 *)(puVar2 + 0x240)));
    if (lVar8 != 0) {
      uVar6 = (*DAT_00960184)(1,*(u32 *)(*(int *)(puVar2 + 0x240) + 0x118),0x40000);
      *(u32 *)(puVar2 + 0x248) = uVar6;
      *(u32 *)(puVar2 + 0x244) = *(u32 *)(*(int *)(puVar2 + 0x240) + 0x118);
      FUN_00521250_typed((void *)(*(u32 *)(puVar2 + 0x248)),(const void *)(*(u32 *)(*(int *)(puVar2 + 0x240) + 0x110)),*(u32 *)(*(int *)(puVar2 + 0x240) + 0x118));
      uVar6 = FUN_0035bc00_u32(10,*(u32 *)(puVar2 + 0x248),*(u32 *)(puVar2 + 0x244),0);
      *(u32 *)(puVar2 + 0x23c) = uVar6;
      if (*(int *)(puVar2 + 0x240) != 0) {
        FUN_00100ec0_arg(*(u32 *)(puVar2 + 0x240));
        *(u32 *)(puVar2 + 0x240) = 0;
      }
      *puVar2 = 3;
    }
    break;
  case 3:
    lVar8 = FUN_00195460(*(u32 *)(puVar2 + 0x23c));
    if ((lVar8 == 0) && (*puVar2 = 4, puVar2[0x250] == '\0')) {
      *puVar2 = 6;
    }
    break;
  case 4:
    uVar7 = (u64)FUN_00102100_typed((void *)(*(u32 *)(puVar2 + 0x24c)),0,(u32 *)(auStack_4));
    uVar6 = (u32)FUN_00112420_typed((void *)(uVar7));
    *(u32 *)(puVar2 + 4) = uVar6;
    *puVar2 = 5;
    break;
  case 5:
    lVar8 = FUN_00111f30_typed((void*)(*(u32 *)(puVar2 + 4)));
    if (lVar8 == 1) {
      for (iVar17 = 0; iVar17 < 0x38; iVar17 = iVar17 + 1) {
        if (((u8 *)DAT_006b46d0)[iVar17 * 6] != -1) {
          piVar11 = (int *)(puVar2 + iVar17 * 4 + 8);
          iVar13 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),(u32)((u8 *)DAT_006b46d6)[iVar17 * 3]);
          *piVar11 = iVar13;
          *(u8 *)(iVar13 + 0x18) = 0xff;
          *(float *)(*piVar11 + 0x10) = (float)(int)((u8 *)DAT_006b46d2)[iVar17 * 3];
          *(float *)(*piVar11 + 0x14) = (float)(int)((u8 *)DAT_006b46d4)[iVar17 * 3];
          *(float *)(*piVar11 + 0x2c) = 3.0f;
        }
      }
      for (iVar17 = 0; iVar17 < 6; iVar17 = iVar17 + 1) {
        iVar13 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),0x1c);
        *(int *)(puVar2 + iVar17 * 4 + 0x33c) = iVar13;
        *(u8 *)(iVar13 + 0x18) = 0xff;
        *(u16 *)(puVar2 + iVar17 * 6 + 0x356) = 0;
        *(u16 *)(puVar2 + iVar17 * 6 + 0x354) = 0x14;
        puVar2[iVar17 + 0x378] = (char)*(u32 *)(DAT_007ce6ec + 0xc0) * (char)iVar17;
      }
      *puVar2 = 8;
    }
    break;
  case 6:
    uVar7 = (u64)FUN_00102100_typed((void *)(*(u32 *)(puVar2 + 0x24c)),2,(u32 *)(auStack_4));
    uVar6 = (u32)FUN_00112420_typed((void *)(uVar7));
    *(u32 *)(puVar2 + 4) = uVar6;
    *puVar2 = 7;
    break;
  case 7:
    lVar8 = FUN_00111f30_typed((void*)(*(u32 *)(puVar2 + 4)));
    if (lVar8 == 1) {
      *puVar2 = 10;
    }
    break;
  case 8:
    uVar7 = (u64)FUN_00102100_typed((void *)(*(u32 *)(puVar2 + 0x24c)),1,(u32 *)(auStack_4));
    uVar6 = (u32)FUN_00112420_typed((void *)(uVar7));
    *(u32 *)(puVar2 + 0xe8) = uVar6;
    *puVar2 = 9;
    break;
  case 9:
    lVar8 = FUN_00111f30_typed((void*)(*(u32 *)(puVar2 + 0xe8)));
    if (lVar8 == 1) {
      *puVar2 = 10;
    }
    break;
  case 10:
    *puVar2 = 0xb;
    break;
  case 0xb:
    uVar6 = FUN_0010c1a0(0,0x6b4860,0,0,0,0,0,0);
    *(u32 *)(puVar2 + 0x380) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b4890,0,0,0,0,0,0);
    *(u32 *)(puVar2 + 900) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b48b0,0,0,0,0,0,0);
    *(u32 *)(puVar2 + 0x388) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b48d0,0,0,0,0,0,0);
    *(u32 *)(puVar2 + 0x38c) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b48f0,0,0,0,0,0,0);
    *(u32 *)(puVar2 + 0x390) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b4910,0,0,0,0,0,0);
    *(u32 *)(puVar2 + 0x394) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b4930,0,0,0,0,0,0);
    *(u32 *)(puVar2 + 0x398) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b4950,0,0,0,0,0,0);
    *(u32 *)(puVar2 + 0x39c) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b4970,0,0,0,0,0,0);
    *(u32 *)(puVar2 + 0x3a0) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b4990,0,0,0,0,0,0);
    *(u32 *)(puVar2 + 0x3a4) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b49b0,0,0,0,0,0,0);
    *(u32 *)(puVar2 + 0x3a8) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b49d0,0,0,0,0,0,0);
    *(u32 *)(puVar2 + 0x3ac) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b49e0,0,0,0,0,0,0);
    *(u32 *)(puVar2 + 0x3b0) = uVar6;
    *puVar2 = 0xc;
  case 0xc:
    uVar6 = FUN_0010c3a0(*(u32 *)(puVar2 + 0x380),&iStack_8,0);
    *(u32 *)(puVar2 + 0x274) = uVar6;
    if (iStack_8 != 0) {
      *puVar2 = 0xd;
    }
    break;
  case 0xd:
    uVar6 = FUN_0010c3a0(*(u32 *)(puVar2 + 900),&iStack_c,0);
    *(u32 *)(puVar2 + 0x278) = uVar6;
    if (iStack_c != 0) {
      *puVar2 = 0xe;
    }
    break;
  case 0xe:
    uVar6 = FUN_0010c3a0(*(u32 *)(puVar2 + 0x388),&iStack_10,0);
    *(u32 *)(puVar2 + 0x27c) = uVar6;
    if (iStack_10 != 0) {
      *puVar2 = 0xf;
    }
    break;
  case 0xf:
    uVar6 = FUN_0010c3a0(*(u32 *)(puVar2 + 0x38c),&iStack_14,0);
    *(u32 *)(puVar2 + 0x280) = uVar6;
    if (iStack_14 != 0) {
      *puVar2 = 0x10;
    }
    break;
  case 0x10:
    uVar6 = FUN_0010c3a0(*(u32 *)(puVar2 + 0x390),&iStack_18,0);
    *(u32 *)(puVar2 + 0x284) = uVar6;
    if (iStack_18 != 0) {
      *puVar2 = 0x11;
    }
    break;
  case 0x11:
    uVar6 = FUN_0010c3a0(*(u32 *)(puVar2 + 0x394),&iStack_1c,0);
    *(u32 *)(puVar2 + 0x288) = uVar6;
    if (iStack_1c != 0) {
      *puVar2 = 0x12;
    }
    break;
  case 0x12:
    uVar6 = FUN_0010c3a0(*(u32 *)(puVar2 + 0x398),&iStack_20,0);
    *(u32 *)(puVar2 + 0x3c8) = uVar6;
    if (iStack_20 != 0) {
      *puVar2 = 0x13;
    }
    break;
  case 0x13:
    uVar6 = FUN_0010c3a0(*(u32 *)(puVar2 + 0x39c),&iStack_24,0);
    *(u32 *)(puVar2 + 0x3cc) = uVar6;
    if (iStack_24 != 0) {
      *puVar2 = 0x14;
    }
    break;
  case 0x14:
    uVar6 = FUN_0010c3a0(*(u32 *)(puVar2 + 0x3a0),&iStack_28,0);
    *(u32 *)(puVar2 + 0x3d0) = uVar6;
    if (iStack_28 != 0) {
      *puVar2 = 0x15;
    }
    break;
  case 0x15:
    uVar6 = FUN_0010c3a0(*(u32 *)(puVar2 + 0x3a4),&iStack_2c,0);
    *(u32 *)(puVar2 + 0x3d4) = uVar6;
    if (iStack_2c != 0) {
      *puVar2 = 0x16;
    }
    break;
  case 0x16:
    uVar6 = FUN_0010c3a0(*(u32 *)(puVar2 + 0x3a8),&iStack_30,0);
    *(u32 *)(puVar2 + 0x3d8) = uVar6;
    if (iStack_30 != 0) {
      *puVar2 = 0x17;
    }
    break;
  case 0x17:
    uVar6 = FUN_0010c3a0(*(u32 *)(puVar2 + 0x3ac),&iStack_34,0);
    *(u32 *)(puVar2 + 0x424) = uVar6;
    if (iStack_34 != 0) {
      *puVar2 = 0x18;
    }
    break;
  case 0x18:
    uVar6 = FUN_0010c3a0(*(u32 *)(puVar2 + 0x3b0),&iStack_38,0);
    *(u32 *)(puVar2 + 0x428) = uVar6;
    if (iStack_38 != 0) {
      FUN_00100ec0_arg(*(u32 *)(puVar2 + 0x24c));
      *puVar2 = 0x1a;
    }
    break;
  case 0x1a:
    for (iVar17 = 0; iVar17 < 6; iVar17 = iVar17 + 1) {
      iVar13 = **(int **)(puVar2 + iVar17 * 4 + 0x274);
      uVar6 = *(u32 *)(iVar13 + 0x10);
      *(u32 *)(puVar2 + 0x308) = uVar6;
      *(u32 *)(puVar2 + 0x2b0) = uVar6;
      uVar6 = *(u32 *)(iVar13 + 0xc);
      *(u32 *)(puVar2 + 0x304) = uVar6;
      *(u32 *)(puVar2 + 0x2ac) = uVar6;
      FUN_00423fe0_typed((float *)(&uStack_c8),1,0x280,0x280,*(u16 *)(puVar2 + 0x304),
                   *(u16 *)(puVar2 + 0x308));
      *(u32 *)(puVar2 + iVar17 * 8 + 0x2cc) = uStack_c8;
      *(u32 *)(puVar2 + iVar17 * 8 + 0x2d0) = uStack_c4;
    }
    for (iVar17 = 0; iVar17 < 5; iVar17 = iVar17 + 1) {
      iVar13 = **(int **)(puVar2 + iVar17 * 4 + 0x3c8);
      *(u32 *)(puVar2 + 0x3fc) = *(u32 *)(iVar13 + 0x10);
      *(u32 *)(puVar2 + 0x3f8) = *(u32 *)(iVar13 + 0xc);
    }
    *(u32 *)(puVar2 + 0x470) = 0;
    *(u32 *)(puVar2 + 0x46c) = 0;
    *(float *)(puVar2 + 0x474) = 350.0f - (float)((1 - (char)puVar2[0x250]) * 0x40);
    *(u32 *)(puVar2 + 0x478) = 0;
    puVar2[0x447] = 0;
    puVar2[1099] = 0xff;
    for (iVar17 = 0; iVar17 < 2; iVar17 = iVar17 + 1) {
      iVar13 = **(int **)(puVar2 + iVar17 * 4 + 0x424);
      puVar2[iVar17 * 4 + 0x446] = 0xff;
      puVar2[iVar17 * 4 + 0x445] = 0xff;
      puVar2[iVar17 * 4 + 0x444] = 0xff;
      *(u32 *)(puVar2 + iVar17 * 0x10 + 0x458) = *(u32 *)(iVar13 + 0x10);
      *(u32 *)(puVar2 + iVar17 * 0x10 + 0x454) = *(u32 *)(iVar13 + 0xc);
      uVar7 = FUN_00427830_typed(15.0f,param_1,*(u32 *)(puVar2 + iVar17 * 4 + 0x424),
                           *(u64 *)(puVar2 + iVar17 * 8 + 0x46c),
                           *(u32 *)(puVar2 + iVar17 * 4 + 0x444),
                           puVar2 + iVar17 * 0x10 + 0x44c,puVar2 + iVar17 * 0x10 + 0x44c,2);
      *(int *)(puVar2 + iVar17 * 4 + 0x42c) = (int)uVar7;
      FUN_00427e50(uVar7,1);
      FUN_00427e60_typed(*(u32 *)(puVar2 + iVar17 * 4 + 0x42c),1);
    }
    if (*(char *)(DAT_007ce6ec + 0xad) < '\x06') {
      FUN_00427e50(*(u32 *)(puVar2 + 0x430),1);
    }
    FUN_00427e20_typed(640.0f,448.0f,*(u32 *)(puVar2 + 0x42c));
    FUN_00427e20_typed(256.0f,448.0f,*(u32 *)(puVar2 + 0x430));
    for (iVar17 = 0; iVar17 < 6; iVar17 = iVar17 + 1) {
      puVar2[iVar17 * 4 + 0x2b5] = 0xff;
      puVar2[iVar17 * 4 + 0x2b6] = 0xff;
      puVar2[iVar17 * 4 + 0x2b4] = 0xff;
      puVar2[iVar17 * 4 + 0x2b7] = 0;
      uVar7 = FUN_00427a10_typed((float)(8 - iVar17),param_1,*(u32 *)(puVar2 + iVar17 * 4 + 0x274),
                           *(u64 *)(puVar2 + iVar17 * 8 + 0x2cc),
                           *(u32 *)(puVar2 + iVar17 * 4 + 0x2b4),puVar2 + 0x2fc,
                           puVar2 + 0x2a4,1);
      *(int *)(puVar2 + iVar17 * 4 + 0x28c) = (int)uVar7;
      FUN_00427e50(uVar7,1);
    }
    iVar17 = (int)(char)(*(char *)(DAT_007ce6ec + 0xad) + -1);
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xad)) {
      iVar12 = (int)lVar8;
      iVar13 = *(int *)(puVar2 + 0x2ac);
      if (iVar13 < 0) {
        iVar13 = iVar13 + 1;
      }
      *(float *)(puVar2 + iVar12 * 8 + 0x2cc) = (float)((iVar13 >> 1) + 0x15e);
      iVar13 = *(int *)(puVar2 + 0x2b0);
      if (iVar13 < 0) {
        iVar13 = iVar13 + 1;
      }
      *(float *)(puVar2 + iVar12 * 8 + 0x2d0) =
           (float)((iVar13 >> 1) + *(int *)((u8 *)DAT_007bc460 + iVar17 * 4) + (iVar17 - iVar12) * 0x40);
      FUN_00427db0_typed(*(u32 *)(puVar2 + iVar12 * 4 + 0x28c),
                   *(u64 *)(puVar2 + iVar12 * 8 + 0x2cc));
      FUN_00427de0_typed(*(u32 *)(puVar2 + iVar12 * 4 + 0x28c),0xff,0xff,0xff,0xff);
      FUN_00427e50(*(u32 *)(puVar2 + iVar12 * 4 + 0x28c),1);
      lVar8 = iVar12 + 1;
    }
    for (iVar17 = 0; iVar17 < 5; iVar17 = iVar17 + 1) {
      puVar2[iVar17 * 4 + 0x409] = 0xff;
      puVar2[iVar17 * 4 + 0x40a] = 0xff;
      puVar2[iVar17 * 4 + 0x408] = 0xff;
      puVar2[iVar17 * 4 + 0x40b] = 0;
      uVar7 = FUN_00427830_typed(1.0f,param_1,*(u32 *)(puVar2 + iVar17 * 4 + 0x3c8),
                           *(u64 *)(puVar2 + iVar17 * 8 + 0x2cc),
                           *(u32 *)(puVar2 + iVar17 * 4 + 0x408),puVar2 + 0x3f0,
                           puVar2 + 0x3f0,2);
      *(int *)(puVar2 + iVar17 * 4 + 0x3dc) = (int)uVar7;
      FUN_00427de0_typed(uVar7,puVar2[iVar17 * 4 + 0x408],puVar2[iVar17 * 4 + 0x409],
                   puVar2[iVar17 * 4 + 0x40a],puVar2[iVar17 * 4 + 0x40b]);
      FUN_00427e50(*(u32 *)(puVar2 + iVar17 * 4 + 0x3dc),1);
    }
    *puVar2 = 0x1c;
    FUN_0044a990((int)(puVar2),(u32*)(*(u32 *)(puVar2 + 0x424)));
    if (puVar2[0x251] == '\0') {
      FUN_001085c0();
    }
    break;
  case 0x1b:
    FUN_0044a990((int)(puVar2),(u32*)(*(u32 *)(puVar2 + 0x424)));
    cVar4 = '\0';
    puVar2[0x253] = 0;
    lVar8 = 0;
    while( 1 ) {
      cVar3 = *(char *)(DAT_007ce6ec + 0xad);
      if (cVar3 <= lVar8) break;
      if (*(char *)(DAT_007ce6ec + (int)lVar8 + 0xa6) == '\0') {
        cVar4 = cVar4 + '\x01';
        puVar2[0x254] = puVar2[0x254] + '\x01';
      }
      lVar8 = lVar8 + 1;
    }
    if (cVar3 == 6) {
      cVar4 = cVar3;
    }
    cVar4 = cVar4 + -1;
    for (iVar17 = 0; iVar17 < 6; iVar17 = iVar17 + 1) {
      FUN_00427e50(*(u32 *)(puVar2 + iVar17 * 4 + 0x28c),1);
    }
    for (iVar17 = 0; iVar17 < 5; iVar17 = iVar17 + 1) {
      FUN_00427e50(*(u32 *)(puVar2 + iVar17 * 4 + 0x3dc),1);
    }
    lVar8 = 0;
    while( 1 ) {
      cVar3 = *(char *)(DAT_007ce6ec + 0xad);
      if (cVar3 <= lVar8) break;
      iVar13 = (int)lVar8;
      iVar17 = *(int *)(puVar2 + 0x2ac);
      if (iVar17 < 0) {
        iVar17 = iVar17 + 1;
      }
      *(float *)(puVar2 + iVar13 * 8 + 0x2cc) =
           (float)((iVar17 >> 1) + 0x15e + (1 - *(char *)(DAT_007ce6ec + 0xac)) * -0x40);
      iVar17 = *(int *)(puVar2 + 0x2b0);
      if (iVar17 < 0) {
        iVar17 = iVar17 + 1;
      }
      *(float *)(puVar2 + iVar13 * 8 + 0x2d0) =
           (float)((iVar17 >> 1) + *(int *)((u8 *)DAT_007bc460 + cVar4 * 4) + (cVar4 - iVar13) * 0x40);
      FUN_00427db0_typed(*(u32 *)(puVar2 + iVar13 * 4 + 0x28c),
                   *(u64 *)(puVar2 + iVar13 * 8 + 0x2cc));
      FUN_00427de0_typed(*(u32 *)(puVar2 + iVar13 * 4 + 0x28c),puVar2[iVar13 * 4 + 0x2b4],
                   puVar2[iVar13 * 4 + 0x2b5],puVar2[iVar13 * 4 + 0x2b6],puVar2[iVar13 * 4 + 0x2b7])
      ;
      if (*(char *)(DAT_007ce6ec + iVar13 + 0xa6) == '\0') {
        FUN_00427e50(*(u32 *)(puVar2 + iVar13 * 4 + 0x28c),0);
        FUN_00427de0_typed(*(u32 *)(puVar2 + iVar13 * 4 + 0x28c),puVar2[iVar13 * 4 + 0x2b4],
                     puVar2[iVar13 * 4 + 0x2b5],puVar2[iVar13 * 4 + 0x2b6],0);
        puVar2[0x253] = puVar2[0x253] + '\x01';
      }
      lVar8 = iVar13 + 1;
    }
    if (cVar3 == 6) {
      puVar2[0x253] = cVar3;
    }
    for (iVar17 = 0; iVar17 < 6; iVar17 = iVar17 + 1) {
      if (*(char *)(DAT_007ce6ec + iVar17 + 0xa6) == '\x01') {
        *(float *)(puVar2 + 0x400) = (float)((1 - *(char *)(DAT_007ce6ec + 0xac)) * -0x40 + 0x15e);
        *(float *)(puVar2 + 0x404) =
             (float)(*(int *)((u8 *)DAT_007bc460 + cVar4 * 4) + (cVar4 - iVar17) * 0x40 + 0x40);
        if (iVar17 != 0) {
          FUN_00427db0_typed(*(u32 *)(puVar2 + iVar17 * 4 + 0x3d8),*(u64 *)(puVar2 + 0x400))
          ;
          FUN_00427de0_typed(*(u32 *)(puVar2 + iVar17 * 4 + 0x3d8),0xff,0xff,0xff,0);
          FUN_00427e50(*(u32 *)(puVar2 + iVar17 * 4 + 0x3d8),0);
        }
      }
    }
    *puVar2 = 0x1d;
    break;
  case 0x1c:
    FUN_0044a990((int)(puVar2),(u32*)(*(u32 *)(puVar2 + 0x424)));
    if ((puVar2[0x251] != '\0') || (lVar8 = FUN_00108710(), lVar8 != 0)) {
      if (puVar2[0x251] == '\0') {
        *puVar2 = 0x1b;
      }
      else if ((puVar2[0x251] == '\x01') && (*(char *)(DAT_007ce6ec + 0xa5) == '\x01')) {
        *puVar2 = 0x1b;
      }
    }
    break;
  case 0x1d:
    FUN_0044a990((int)(puVar2),(u32*)(*(u32 *)(puVar2 + 0x424)));
    if (*(char *)(DAT_007ce6ec + 0xac) == '\0') {
      for (iVar17 = 0; iVar17 < 6; iVar17 = iVar17 + 1) {
        *(short *)(DAT_007ce6ec + iVar17 * 6 + 0x7e) = (short)(iVar17 << 2) + (short)iVar17;
        *(u16 *)(DAT_007ce6ec + iVar17 * 6 + 0x7c) = 0;
      }
      for (iVar17 = 0; iVar17 < 3; iVar17 = iVar17 + 1) {
        *(u16 *)(puVar2 + iVar17 * 6 + 0x484) = 0;
        *(u16 *)(puVar2 + iVar17 * 6 + 0x486) = 0;
        *(u16 *)(puVar2 + iVar17 * 6 + 0x488) = 0;
        puVar2[iVar17 + 0x496] = (char)iVar17 * '\x03' + '\x01';
      }
      *(float *)(puVar2 + 0x8a4) = 256.0f;
      *(u32 *)(puVar2 + 0x8a8) = 0x43d78000;
      *(u32 *)(puVar2 + 0x8b4) = 0x10;
      *(u32 *)(puVar2 + 0x8b8) = 0;
      uVar7 = FUN_004229d0(param_1,*(u64 *)(puVar2 + 0x8a4),1);
      *(int *)(puVar2 + 0x8a0) = (int)uVar7;
      FUN_00422c30(uVar7,*(u64 *)(puVar2 + 0x8a4),puVar2 + 0x8ac);
      FUN_00422c90(*(u32 *)(puVar2 + 0x8a0),0,0x6a,0xc3,0xff);
      FUN_00422c10(*(u32 *)(puVar2 + 0x8a0),5);
      *puVar2 = 0x1f;
      if (*(char *)(DAT_007ce6ec + 0xaf) == '\x01') {
        *(u16 *)(puVar2 + 0x256) = 0;
        *puVar2 = 0x20;
        if (*(char *)(DAT_007ce6ec + 0xae) == '\x01') {
          *puVar2 = 0x21;
        }
      }
      FUN_003952d0_typed(0,0x2c5,3);
    }
    else if (*(char *)(DAT_007ce6ec + 0xac) == '\x01') {
      cVar4 = *(char *)(DAT_007ce6ec + 0xa0);
      puVar2[0x940] = cVar4;
      if (cVar4 < '\x06') {
        puVar2[0x93f] = cVar4;
      }
      else {
        puVar2[0x93f] = 6;
      }
      if (*(char *)(DAT_007ce6ec + 0xa0) < '\a') {
        for (lVar8 = 0; lVar8 < *(char *)(DAT_007ce6ec + 0xa0); lVar8 = lVar8 + 1) {
          iVar17 = DAT_007ce6ec + (int)lVar8 * 4;
          if ((*(char *)(iVar17 + 4) == *(char *)(DAT_007ce6ec + 0xa4)) &&
             (*(short *)(iVar17 + 6) == *(short *)(DAT_007ce6ec + 0xa2))) {
            puVar2[0x93e] = (char)lVar8;
          }
        }
      }
      lVar8 = 0;
      while (lVar8 < (char)puVar2[0x93f]) {
        iVar17 = (int)lVar8;
        *(u32 *)(puVar2 + iVar17 * 8 + 0x8e0) = 0xc3480000;
        *(float *)(puVar2 + iVar17 * 8 + 0x8e4) =
             (float)((char)puVar2[0x93f] * 0xe + iVar17 * -0x1c + 0xca);
        *(u32 *)(puVar2 + 0x918) = 0xf5;
        *(u32 *)(puVar2 + 0x91c) = 0x20;
        *(u16 *)(puVar2 + iVar17 * 6 + 0x8bc) = 0xf;
        *(u16 *)(puVar2 + iVar17 * 6 + 0x8be) = 0;
        *(u16 *)(puVar2 + iVar17 * 6 + 0x8c0) = 0;
        puVar2[iVar17 + 0x938] = (char)lVar8 * '\x02';
        lVar8 = iVar17 + 1;
      }
      for (iVar17 = 0; iVar17 < 6; iVar17 = iVar17 + 1) {
        iVar13 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),5);
        *(int *)(puVar2 + iVar17 * 4 + 0x4d8) = iVar13;
        *(u8 *)(iVar13 + 0x18) = 0xff;
        iVar13 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),0x34);
        *(int *)(puVar2 + iVar17 * 4 + 0x4f0) = iVar13;
        *(u8 *)(iVar13 + 0x18) = 0xff;
      }
      iVar17 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b47ae);
      *(int *)(puVar2 + 0x868) = iVar17;
      *(u8 *)(iVar17 + 0x18) = 0xff;
      iVar17 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b481a);
      *(int *)(puVar2 + 0x86c) = iVar17;
      *(u8 *)(iVar17 + 0x18) = 0xff;
      for (iVar17 = 0; iVar17 < 6; iVar17 = iVar17 + 1) {
        iVar13 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),8);
        *(int *)(puVar2 + iVar17 * 4 + 0x4a8) = iVar13;
        *(u8 *)(iVar13 + 0x18) = 0xff;
        iVar13 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),0x35);
        *(int *)(puVar2 + iVar17 * 4 + 0x4c0) = iVar13;
        *(u8 *)(iVar13 + 0x18) = 0xff;
        for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
          for (iVar12 = 0; iVar12 < 10; iVar12 = iVar12 + 1) {
            iVar5 = FUN_001158b0(0,*(u32 *)(puVar2 + 0xe8),iVar12 + 0xb);
            *(int *)(puVar2 + iVar12 * 4 + iVar13 * 0x30 + iVar17 * 0x90 + 0x508) = iVar5;
            *(u8 *)(iVar5 + 0x18) = 0xff;
          }
          iVar12 = iVar13 * 0x30 + iVar17 * 0x90;
          iVar5 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),0x19);
          *(int *)(puVar2 + iVar12 + 0x530) = iVar5;
          *(u8 *)(iVar5 + 0x18) = 0xff;
          iVar5 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),0x1a);
          *(int *)(puVar2 + iVar12 + 0x534) = iVar5;
          *(u8 *)(iVar5 + 0x18) = 0xff;
        }
        *(u16 *)(puVar2 + iVar17 * 6 + 0x87c) = 1;
      }
      FUN_00449d10(param_1);
      if ('\x06' < (char)puVar2[0x940]) {
        *(float *)(puVar2 + 0x950) = (float)(0x70 / (*(char *)(DAT_007ce6ec + 0xa0) + -6));
      }
      for (iVar17 = 0; iVar17 < 6; iVar17 = iVar17 + 1) {
        puVar2[iVar17 + 0x378] = (char)(iVar17 << 1);
      }
      *(u32 *)(DAT_007ce6ec + 0xb0) = 0xf;
      *(u32 *)(DAT_007ce6ec + 0xb4) = 0xf;
      *(u32 *)(DAT_007ce6ec + 0xb8) = 5;
      *(u32 *)(DAT_007ce6ec + 0xbc) = 0x14;
      *(u32 *)(DAT_007ce6ec + 0xc4) = 5;
      for (iVar17 = 0; iVar17 < 6; iVar17 = iVar17 + 1) {
        *(short *)(DAT_007ce6ec + iVar17 * 6 + 0x7c) = (short)iVar17 * 2 + 10;
        *(u16 *)(DAT_007ce6ec + iVar17 * 6 + 0x7e) = 0;
      }
      FUN_00449d60(param_1);
      *puVar2 = 0x22;
    }
    break;
  case 0x1f:
    bVar14 = 0;
    cVar4 = puVar2[0x254];
    sVar10 = (cVar4 + -1) * 5 + 0xf;
    FUN_0044a990((int)(puVar2),(u32*)(*(u32 *)(puVar2 + 0x424)));
    if (*(int *)(DAT_007ce6ec + 0xb0) < 1) {
      cVar3 = FUN_00449fe0(17.0f,17.0f,500.0f,
                           (float)((6 - (char)puVar2[0x253]) * 0x20 + 0x20),param_1,0xf);
      if (cVar3 == '\x01') {
        bVar14 = 1;
      }
    }
    else {
      *(int *)(DAT_007ce6ec + 0xb0) = *(int *)(DAT_007ce6ec + 0xb0) + -1;
      bVar14 = 1;
    }
    if (*(int *)(DAT_007ce6ec + 0xb4) < 1) {
      fVar22 = (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x19c);
      cVar3 = FUN_0044a110(0xc2c80000,0x43e20000,fVar22,fVar22,param_1,10);
      if (cVar3 == '\x01') {
        bVar14 = 1;
      }
    }
    else {
      *(int *)(DAT_007ce6ec + 0xb4) = *(int *)(DAT_007ce6ec + 0xb4) + -1;
      bVar14 = 1;
    }
    lVar8 = 0;
    while (lVar8 < (char)puVar2[0x254]) {
      iVar17 = (int)lVar8;
      FUN_004222d0_typed((float*)(afStack_40),(char)(0),(int)(700),(int)(0x110),(int)(0x19f),(int)(0x19f),(int)(*(u16 *)(DAT_007ce6ec + iVar17 * 6 + 0x7c)),(short)(0xf));
      FUN_0044a240(afStack_40[0],(float)(iVar17 * -0x40 + 0x19f + (6 - (char)puVar2[0x253]) * -0x20)
                   ,0,5.0f,param_1,0x1d);
      if (lVar8 == (char)puVar2[0x254] + -1) {
        FUN_0044a240(afStack_40[0],
                     (float)((iVar17 + 1) * -0x40 + 0x19f + (6 - (char)puVar2[0x253]) * -0x20),0,
                     5.0f,param_1,0x1d);
      }
      for (iVar13 = 0; iVar13 < 7; iVar13 = iVar13 + 1) {
        FUN_0044a240(afStack_40[0],
                     (float)(iVar13 * 8 + 0x167 + (6 - (char)puVar2[0x253]) * -0x20 + iVar17 * -0x40
                            ),0,5.0f,param_1,0x1e);
      }
      FUN_0044a240(afStack_40[0] + 308.0f,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,3.0f,
                   param_1,(char)lVar8 + '\x05');
      FUN_0044a240(afStack_40[0] + 250.0f,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,3.0f,
                   param_1,0xb);
      if (lVar8 == *(char *)(DAT_007ce6ec + 0xa4) + -1) {
        FUN_0044a240(afStack_40[0],
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x163 + iVar17 * -0x40),0,
                     5.0f,param_1,0x1c);
        if (*(short *)(DAT_007ce6ec + iVar17 * 6 + 0x7e) < 0) {
          for (iVar13 = 0; iVar13 < 2; iVar13 = iVar13 + 1) {
            if ((char)puVar2[iVar13 + 0x496] < '\0') {
              FUN_004222d0_typed((float*)(afStack_48),(char)(0),(int)(700),(int)(0x110),(int)(0x19f),(int)(0x19f),(int)(*(u16 *)(puVar2 + iVar13 * 6 + 0x484)),(short)(0xf));
              uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),0x20);
              iVar12 = (int)uVar7;
              *(float *)(iVar12 + 0x2c) = 3.0f;
              *(u8 *)(iVar12 + 0x18) = 0;
              *(float *)(iVar12 + 0x10) = afStack_48[0] - 17.0f;
              *(float *)(iVar12 + 0x14) =
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x162 + iVar17 * -0x40);
              FUN_001127d0(uVar7,1);
              FUN_00115980_arg(uVar7);
              sVar9 = *(short *)(puVar2 + iVar13 * 6 + 0x484);
              if (sVar9 < 0xf) {
                *(short *)(puVar2 + iVar13 * 6 + 0x484) = sVar9 + 1;
                bVar14 = 1;
              }
            }
            else {
              puVar2[iVar13 + 0x496] = puVar2[iVar13 + 0x496] + -1;
              bVar14 = 1;
            }
          }
        }
        FUN_0044a240(afStack_40[0] - 17.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x162 + iVar17 * -0x40),0,
                     3.0f,param_1,0x1a);
        FUN_0044a240(afStack_40[0] - 15.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x174 + iVar17 * -0x40),0,
                     3.0f,param_1,0x1b);
        FUN_0044a240(afStack_40[0] + 308.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,
                     3.0f,param_1,(char)lVar8 + '\x0f');
        FUN_0044a240(afStack_40[0] + 250.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,
                     3.0f,param_1,0x15);
      }
      lVar8 = iVar17 + 1;
    }
    if (*(char *)(DAT_007ce6ec + 0xad) == '\x06') {
      fVar22 = (float)FUN_00421fe0(0,0,0xff,*(u16 *)(DAT_007ce6ec + 0x7c),0xf);
      if (fVar22 < 2147483648.0f) {
        uVar21 = (int)fVar22;
      }
      else {
        uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
      }
      FUN_001140d0(4.0f,*(u32 *)(puVar2 + 0x474),*(u32 *)(puVar2 + 0x478),
                   uVar21 | 0xffffff00,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    for (lVar8 = 0; lVar8 < *(char *)(DAT_007ce6ec + 0xad); lVar8 = lVar8 + 1) {
      iVar17 = DAT_007ce6ec + (int)lVar8 * 6;
      sVar9 = *(short *)(iVar17 + 0x7e);
      if (sVar9 < 0) {
        cVar3 = FUN_0044a420(param_1,lVar8,0xf);
        if (cVar3 == '\x01') {
          bVar14 = 1;
        }
      }
      else {
        *(short *)(iVar17 + 0x7e) = sVar9 + -1;
        bVar14 = 1;
      }
    }
    fVar22 = (float)FUN_004221a0(0,(float)(int)(short)(cVar4 * 0x40 + 0x10),
                                 (float)(int)*(short *)(puVar2 + 0x87c),(float)(int)sVar10,0);
    *(int *)(puVar2 + 0x8b8) = (int)fVar22;
    *(float *)(puVar2 + 0x8a8) = (433.0f - fVar22) - (float)((6 - (char)puVar2[0x253]) * 0x20);
    FUN_00422c30(*(u32 *)(puVar2 + 0x8a0),*(u64 *)(puVar2 + 0x8a4),puVar2 + 0x8ac);
    if (*(short *)(puVar2 + 0x87c) < sVar10) {
      *(short *)(puVar2 + 0x87c) = *(short *)(puVar2 + 0x87c) + 1;
      bVar14 = 1;
    }
    *(short *)(puVar2 + 0x256) = *(short *)(puVar2 + 0x256) + 1;
    if ((!bVar14) && ((int)((char)puVar2[0x254] * 5 + 0x1e) <= (int)*(short *)(puVar2 + 0x256))) {
      for (iVar17 = 0; iVar17 < 3; iVar17 = iVar17 + 1) {
        *(u16 *)(puVar2 + iVar17 * 6 + 0x484) = 0;
        *(u16 *)(puVar2 + iVar17 * 6 + 0x486) = 0;
        *(u16 *)(puVar2 + iVar17 * 6 + 0x488) = 0;
        puVar2[iVar17 + 0x496] = (char)iVar17 * '\x03' + '\x01';
      }
      *(u16 *)(puVar2 + 0x256) = 0;
      *puVar2 = 0x24;
    }
    break;
  case 0x20:
    bVar14 = 0;
    cVar4 = *(char *)(DAT_007ce6ec + 0xa4);
    sVar10 = (cVar4 + -1) * 5 + 0xf;
    FUN_0044a990((int)(puVar2),(u32*)(*(u32 *)(puVar2 + 0x424)));
    if (*(int *)(DAT_007ce6ec + 0xb0) < 1) {
      cVar3 = FUN_00449fe0(17.0f,17.0f,500.0f,
                           (float)((6 - (char)puVar2[0x253]) * 0x20 + 0x20),param_1,0xf);
      if (cVar3 == '\x01') {
        bVar14 = 1;
      }
    }
    else {
      *(int *)(DAT_007ce6ec + 0xb0) = *(int *)(DAT_007ce6ec + 0xb0) + -1;
      bVar14 = 1;
    }
    if (*(int *)(DAT_007ce6ec + 0xb4) < 1) {
      fVar22 = (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x19c);
      cVar3 = FUN_0044a110(0xc2c80000,0x43e20000,fVar22,fVar22,param_1,10);
      if (cVar3 == '\x01') {
        bVar14 = 1;
      }
    }
    else {
      *(int *)(DAT_007ce6ec + 0xb4) = *(int *)(DAT_007ce6ec + 0xb4) + -1;
      bVar14 = 1;
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xa4)) {
      iVar17 = (int)lVar8;
      FUN_004222d0_typed((float*)(afStack_50),(char)(0),(int)(700),(int)(0x110),(int)(0x19f),(int)(0x19f),(int)(*(u16 *)(DAT_007ce6ec + iVar17 * 6 + 0x7c)),(short)(0xf));
      FUN_0044a240(afStack_50[0],(float)(iVar17 * -0x40 + 0x19f + (6 - (char)puVar2[0x253]) * -0x20)
                   ,0,5.0f,param_1,0x1d);
      if (lVar8 == *(char *)(DAT_007ce6ec + 0xa4) + -1) {
        FUN_0044a240(afStack_50[0],
                     (float)((iVar17 + 1) * -0x40 + 0x19f + (6 - (char)puVar2[0x253]) * -0x20),0,
                     5.0f,param_1,0x1d);
      }
      for (iVar13 = 0; iVar13 < 7; iVar13 = iVar13 + 1) {
        FUN_0044a240(afStack_50[0],
                     (float)(iVar13 * 8 + 0x167 + (6 - (char)puVar2[0x253]) * -0x20 + iVar17 * -0x40
                            ),0,5.0f,param_1,0x1e);
      }
      FUN_0044a240(afStack_50[0] + 308.0f,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,3.0f,
                   param_1,(char)lVar8 + '\x05');
      FUN_0044a240(afStack_50[0] + 250.0f,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,3.0f,
                   param_1,0xb);
      if (lVar8 == *(char *)(DAT_007ce6ec + 0xa4) + -1) {
        FUN_0044a240(afStack_50[0],
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x163 + iVar17 * -0x40),0,
                     5.0f,param_1,0x1c);
        if (*(short *)(DAT_007ce6ec + iVar17 * 6 + 0x7e) < 0) {
          for (iVar13 = 0; iVar13 < 2; iVar13 = iVar13 + 1) {
            if ((char)puVar2[iVar13 + 0x496] < '\0') {
              FUN_004222d0_typed((float*)(afStack_58),(char)(0),(int)(700),(int)(0x110),(int)(0x19f),(int)(0x19f),(int)(*(u16 *)(puVar2 + iVar13 * 6 + 0x484)),(short)(0xf));
              uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),0x20);
              iVar12 = (int)uVar7;
              *(float *)(iVar12 + 0x2c) = 3.0f;
              *(u8 *)(iVar12 + 0x18) = 0;
              *(float *)(iVar12 + 0x10) = afStack_58[0] - 17.0f;
              *(float *)(iVar12 + 0x14) =
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x163 + iVar17 * -0x40);
              FUN_001127d0(uVar7,1);
              FUN_00115980_arg(uVar7);
              sVar9 = *(short *)(puVar2 + iVar13 * 6 + 0x484);
              if (sVar9 < 0xf) {
                *(short *)(puVar2 + iVar13 * 6 + 0x484) = sVar9 + 1;
                bVar14 = 1;
              }
            }
            else {
              puVar2[iVar13 + 0x496] = puVar2[iVar13 + 0x496] + -1;
              bVar14 = 1;
            }
          }
        }
        FUN_0044a240(afStack_50[0] - 17.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x163 + iVar17 * -0x40),0,
                     3.0f,param_1,0x1a);
        FUN_0044a240(afStack_50[0] - 15.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x174 + iVar17 * -0x40),0,
                     3.0f,param_1,0x1b);
        FUN_0044a240(afStack_50[0] + 308.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,
                     3.0f,param_1,(char)lVar8 + '\x0f');
        FUN_0044a240(afStack_50[0] + 250.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,
                     3.0f,param_1,0x15);
      }
      lVar8 = iVar17 + 1;
    }
    if (*(char *)(DAT_007ce6ec + 0xad) == '\x06') {
      fVar22 = (float)FUN_00421fe0(0,0,0xff,*(u16 *)(DAT_007ce6ec + 0x7c),0xf);
      if (fVar22 < 2147483648.0f) {
        uVar21 = (int)fVar22;
      }
      else {
        uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
      }
      FUN_001140d0(4.0f,*(u32 *)(puVar2 + 0x474),*(u32 *)(puVar2 + 0x478),
                   uVar21 | 0xffffff00,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    for (lVar8 = 0; lVar8 < *(char *)(DAT_007ce6ec + 0xa4); lVar8 = lVar8 + 1) {
      iVar17 = DAT_007ce6ec + (int)lVar8 * 6;
      sVar9 = *(short *)(iVar17 + 0x7e);
      if (sVar9 < 0) {
        cVar3 = FUN_0044a420(param_1,lVar8,0xf);
        if (cVar3 == '\x01') {
          bVar14 = 1;
        }
      }
      else {
        *(short *)(iVar17 + 0x7e) = sVar9 + -1;
        bVar14 = 1;
      }
    }
    fVar22 = (float)FUN_004221a0(0,(float)(int)(short)(cVar4 * 0x40 + 0x10),
                                 (float)(int)*(short *)(puVar2 + 0x87c),(float)(int)sVar10,0);
    *(int *)(puVar2 + 0x8b8) = (int)fVar22;
    *(float *)(puVar2 + 0x8a8) = (433.0f - fVar22) - (float)((6 - (char)puVar2[0x253]) * 0x20);
    FUN_00422c30(*(u32 *)(puVar2 + 0x8a0),*(u64 *)(puVar2 + 0x8a4),puVar2 + 0x8ac);
    if (*(short *)(puVar2 + 0x87c) < sVar10) {
      *(short *)(puVar2 + 0x87c) = *(short *)(puVar2 + 0x87c) + 1;
      bVar14 = 1;
    }
    *(short *)(puVar2 + 0x256) = *(short *)(puVar2 + 0x256) + 1;
    if ((!bVar14) && ((int)((char)puVar2[0x254] * 5 + 0x2d) <= (int)*(short *)(puVar2 + 0x256))) {
      for (iVar17 = 0; iVar17 < 3; iVar17 = iVar17 + 1) {
        *(u16 *)(puVar2 + iVar17 * 6 + 0x484) = 0;
        *(u16 *)(puVar2 + iVar17 * 6 + 0x486) = 0;
        *(u16 *)(puVar2 + iVar17 * 6 + 0x488) = 0;
        puVar2[iVar17 + 0x496] = (char)iVar17 * '\x03' + '\x01';
      }
      *(u16 *)(puVar2 + 0x87c) = 0;
      *(u16 *)(puVar2 + 0x882) = 0;
      *(u16 *)(puVar2 + 0x256) = 0;
      *puVar2 = 0x27;
    }
    break;
  case 0x21:
    bVar14 = 0;
    cVar4 = *(char *)(DAT_007ce6ec + 0xa4);
    sVar10 = (cVar4 + -1) * 5 + 0xf;
    FUN_0044a990((int)(puVar2),(u32*)(*(u32 *)(puVar2 + 0x424)));
    if (*(int *)(DAT_007ce6ec + 0xb0) < 1) {
      cVar3 = FUN_00449fe0(17.0f,17.0f,500.0f,
                           (float)((6 - (char)puVar2[0x253]) * 0x20 + 0x20),param_1,0xf);
      if (cVar3 == '\x01') {
        bVar14 = 1;
      }
    }
    else {
      *(int *)(DAT_007ce6ec + 0xb0) = *(int *)(DAT_007ce6ec + 0xb0) + -1;
      bVar14 = 1;
    }
    if (*(int *)(DAT_007ce6ec + 0xb4) < 1) {
      fVar22 = (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x19c);
      cVar3 = FUN_0044a110(0xc2c80000,0x43e20000,fVar22,fVar22,param_1,10);
      if (cVar3 == '\x01') {
        bVar14 = 1;
      }
    }
    else {
      *(int *)(DAT_007ce6ec + 0xb4) = *(int *)(DAT_007ce6ec + 0xb4) + -1;
      bVar14 = 1;
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xa4)) {
      iVar17 = (int)lVar8;
      FUN_004222d0_typed((float*)(afStack_60),(char)(0),(int)(700),(int)(0x110),(int)(0x19f),(int)(0x19f),(int)(*(u16 *)(DAT_007ce6ec + iVar17 * 6 + 0x7c)),(short)(0xf));
      FUN_0044a240(afStack_60[0],(float)(iVar17 * -0x40 + 0x19f + (6 - (char)puVar2[0x253]) * -0x20)
                   ,0,5.0f,param_1,0x1d);
      FUN_0044a240(afStack_60[0],
                   (float)((iVar17 + 1) * -0x40 + 0x19f + (6 - (char)puVar2[0x253]) * -0x20),0,
                   5.0f,param_1,0x1d);
      for (iVar13 = 0; iVar13 < 7; iVar13 = iVar13 + 1) {
        FUN_0044a240(afStack_60[0],
                     (float)(iVar13 * 8 + 0x167 + (6 - (char)puVar2[0x253]) * -0x20 + iVar17 * -0x40
                            ),0,5.0f,param_1,0x1e);
      }
      FUN_0044a240(afStack_60[0],(float)((6 - (char)puVar2[0x253]) * -0x20 + 0x163 + iVar17 * -0x40)
                   ,0,5.0f,param_1,0x1c);
      FUN_0044a240(afStack_60[0] + 308.0f,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,3.0f,
                   param_1,(char)lVar8 + '\x05');
      FUN_0044a240(afStack_60[0] + 250.0f,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,3.0f,
                   param_1,0xb);
      FUN_0044a240(afStack_60[0] - 17.0f,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x163 + iVar17 * -0x40),0,3.0f,
                   param_1,0x1a);
      FUN_0044a240(afStack_60[0] - 15.0f,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x174 + iVar17 * -0x40),0,3.0f,
                   param_1,0x1b);
      lVar8 = iVar17 + 1;
    }
    for (lVar8 = 0; lVar8 < *(char *)(DAT_007ce6ec + 0xa4); lVar8 = lVar8 + 1) {
      iVar17 = DAT_007ce6ec + (int)lVar8 * 6;
      sVar9 = *(short *)(iVar17 + 0x7e);
      if (sVar9 < 0) {
        cVar3 = FUN_0044a420(param_1,lVar8,0xf);
        if (cVar3 == '\x01') {
          bVar14 = 1;
        }
      }
      else {
        *(short *)(iVar17 + 0x7e) = sVar9 + -1;
        bVar14 = 1;
      }
    }
    fVar22 = (float)FUN_004221a0(0,(float)(int)(short)(cVar4 * 0x40 + 0x10),
                                 (float)(int)*(short *)(puVar2 + 0x87c),(float)(int)sVar10,0);
    *(int *)(puVar2 + 0x8b8) = (int)fVar22;
    *(float *)(puVar2 + 0x8a8) = (433.0f - fVar22) - (float)((6 - (char)puVar2[0x254]) * 0x20);
    FUN_00422c30(*(u32 *)(puVar2 + 0x8a0),*(u64 *)(puVar2 + 0x8a4),puVar2 + 0x8ac);
    if (*(short *)(puVar2 + 0x87c) < sVar10) {
      *(short *)(puVar2 + 0x87c) = *(short *)(puVar2 + 0x87c) + 1;
      bVar14 = 1;
    }
    *(short *)(puVar2 + 0x256) = *(short *)(puVar2 + 0x256) + 1;
    if ((!bVar14) && ((int)((char)puVar2[0x254] * 5 + 0x2d) <= (int)*(short *)(puVar2 + 0x256))) {
      for (iVar17 = 0; iVar17 < 3; iVar17 = iVar17 + 1) {
        *(u16 *)(puVar2 + iVar17 * 6 + 0x484) = 0;
        *(u16 *)(puVar2 + iVar17 * 6 + 0x486) = 0;
        *(u16 *)(puVar2 + iVar17 * 6 + 0x488) = 0;
        puVar2[iVar17 + 0x496] = (char)iVar17 * '\x03' + '\x01';
      }
      *(u16 *)(puVar2 + 0x87c) = 0;
      *(u16 *)(puVar2 + 0x882) = 0;
      *(u16 *)(puVar2 + 0x256) = 0;
      *puVar2 = 0x29;
    }
    break;
  case 0x22:
    bVar14 = 0;
    FUN_0044a990((int)(puVar2),(u32*)(*(u32 *)(puVar2 + 0x424)));
    if (*(char *)(DAT_007ce6ec + 0xad) == '\x06') {
      FUN_001140d0(4.0f,*(u32 *)(puVar2 + 0x474),*(u32 *)(puVar2 + 0x478),
                   0xffffffffffffffff,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xad)) {
      iVar17 = (int)lVar8;
      cVar4 = *(char *)(DAT_007ce6ec + iVar17 + 0xa6);
      if (cVar4 == '\0') {
        iVar13 = DAT_007ce6ec + iVar17 * 6;
        fVar22 = (float)FUN_00421fe0(0,0,0xff,*(u16 *)(iVar13 + 0x7e),
                                     *(u16 *)(iVar13 + 0x7c));
        if (fVar22 < 2147483648.0f) {
          uVar21 = (int)fVar22;
        }
        else {
          uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
        }
        FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2d0) - 64.0f,uVar21 | 0xffffff00,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x274));
        iVar13 = DAT_007ce6ec + iVar17 * 6;
        if (*(short *)(iVar13 + 0x7e) < *(short *)(iVar13 + 0x7c)) {
          *(short *)(iVar13 + 0x7e) = *(short *)(iVar13 + 0x7e) + 1;
          bVar14 = 1;
        }
      }
      else if ((cVar4 == '\x01') && (lVar8 != 0)) {
        iVar13 = DAT_007ce6ec + iVar17 * 6;
        fVar22 = (float)FUN_00421fe0(0,0,0xff,*(u16 *)(iVar13 + 0x7e),
                                     *(u16 *)(iVar13 + 0x7c));
        iVar13 = DAT_007ce6ec + iVar17 * 6;
        if (*(short *)(iVar13 + 0x7e) < *(short *)(iVar13 + 0x7c)) {
          *(short *)(iVar13 + 0x7e) = *(short *)(iVar13 + 0x7e) + 1;
          bVar14 = 1;
        }
        if (fVar22 < 2147483648.0f) {
          uVar21 = (int)fVar22;
        }
        else {
          uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
        }
        FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2c8) - 64.0f,uVar21 | 0xffffff00,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x3c4));
      }
      lVar8 = iVar17 + 1;
    }
    FUN_004222d0_typed((float*)(&fStack_68),(char)(0),(int)(0xffffffffffffff9c),(int)(DAT_006b46d2),(int)(DAT_006b46d4),(int)(DAT_006b46d4),(int)(*(u16 *)(puVar2 + DAT_006b46d0 * 6 + 0xee)),(short)(0x14));
    if (*(short *)(puVar2 + DAT_006b46d0 * 6 + 0xee) < 0x14) {
      *(short *)(puVar2 + DAT_006b46d0 * 6 + 0xee) =
           *(short *)(puVar2 + DAT_006b46d0 * 6 + 0xee) + 1;
      bVar14 = 1;
    }
    uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b46d0);
    iVar17 = (int)uVar7;
    *(u8 *)(iVar17 + 0x18) = 0;
    *(float *)(iVar17 + 0x10) = fStack_68;
    *(float *)(iVar17 + 0x14) = fStack_64;
    *(float *)(iVar17 + 0x2c) = 3.0f;
    FUN_001127d0(uVar7,1);
    FUN_00115980_arg(uVar7);
    if (*(int *)(DAT_007ce6ec + 0xb0) < 1) {
      FUN_004222d0_typed((float*)(&fStack_68),(char)(0),(int)(DAT_006b46d8),(int)(DAT_006b46d8),(int)(0xffffffffffffff6a),(int)(DAT_006b46da + (6 - (char)puVar2[0x93f]) * 0x12),(int)(*(u16 *)(puVar2 + DAT_006b46d6 * 6 + 0xee)),(short)(10));
      if (*(short *)(puVar2 + DAT_006b46d6 * 6 + 0xee) < 10) {
        *(short *)(puVar2 + DAT_006b46d6 * 6 + 0xee) =
             *(short *)(puVar2 + DAT_006b46d6 * 6 + 0xee) + 1;
        bVar14 = 1;
      }
      uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b46d6);
      iVar17 = (int)uVar7;
      *(u8 *)(iVar17 + 0x18) = 0;
      *(float *)(iVar17 + 0x10) = fStack_68;
      *(float *)(iVar17 + 0x14) = fStack_64;
      *(float *)(iVar17 + 0x2c) = 3.0f;
      FUN_001127d0(uVar7,1);
      FUN_00115980_arg(uVar7);
      uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b46dc);
      iVar17 = (int)uVar7;
      *(u8 *)(iVar17 + 0x18) = 0;
      *(float *)(iVar17 + 0x10) = (float)(int)DAT_006b46de;
      *(float *)(iVar17 + 0x14) = fStack_64;
      *(float *)(iVar17 + 0x2c) = 3.0f;
      FUN_001127d0(uVar7,1);
      FUN_00115980_arg(uVar7);
    }
    else {
      *(int *)(DAT_007ce6ec + 0xb0) = *(int *)(DAT_007ce6ec + 0xb0) + -1;
      bVar14 = 1;
    }
    if (*(int *)(DAT_007ce6ec + 0xb4) < 1) {
      FUN_004222d0_typed((float*)(&fStack_68),(char)(0),(int)(DAT_006b46e4),(int)(DAT_006b46e4),(int)(500),(int)(DAT_006b46e6 + (6 - (char)puVar2[0x93f]) * -0x12),(int)(*(u16 *)(puVar2 + DAT_006b46e2 * 6 + 0xee)),(short)(10));
      if (*(short *)(puVar2 + DAT_006b46e2 * 6 + 0xee) < 10) {
        *(short *)(puVar2 + DAT_006b46e2 * 6 + 0xee) =
             *(short *)(puVar2 + DAT_006b46e2 * 6 + 0xee) + 1;
        bVar14 = 1;
      }
      uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b46e2);
      iVar17 = (int)uVar7;
      *(u8 *)(iVar17 + 0x18) = 0;
      *(float *)(iVar17 + 0x10) = fStack_68;
      *(float *)(iVar17 + 0x14) = fStack_64;
      *(float *)(iVar17 + 0x2c) = 3.0f;
      FUN_001127d0(uVar7,1);
      FUN_00115980_arg(uVar7);
    }
    else {
      *(int *)(DAT_007ce6ec + 0xb4) = *(int *)(DAT_007ce6ec + 0xb4) + -1;
      bVar14 = 1;
    }
    if (*(int *)(DAT_007ce6ec + 0xb8) < 1) {
      lVar8 = 0;
      if ('\0' < (char)puVar2[0x93f]) {
        while (lVar8 < (char)puVar2[0x93f]) {
          iVar17 = (int)lVar8;
          if ((char)puVar2[iVar17 + 0x938] < '\x01') {
            psVar16 = (short *)(puVar2 + iVar17 * 6 + 0x8be);
            FUN_004222d0_typed((float*)(&fStack_68),(char)(2),(int)((short)(int)*(float *)(puVar2 + iVar17 * 8 + 0x8e0)),(int)((short)PTR_DAT_006b46f0),(int)((short)(int)*(float *)(puVar2 + iVar17 * 8 + 0x8e4)),(int)((short)(int)*(float *)(puVar2 + iVar17 * 8 + 0x8e4)),(int)(*(u16 *)(puVar2 + iVar17 * 6 + 0x8be)),(short)(10));
            if (*psVar16 < 10) {
              fStack_70 = (fStack_68 - 240.0f) - 20.0f;
            }
            else {
              fStack_70 = fStack_68 - 240.0f;
            }
            fStack_6c = fStack_64 - 3.0f;
            iVar13 = DAT_007ce6ec + (iVar17 + (char)puVar2[0x941]) * 4;
            FUN_00448060(param_1,(char)lVar8,*(u64 *)(&fStack_70),
                         *(u8 *)(iVar13 + 4),*(u16 *)(iVar13 + 6),0);
            *(u8 *)(*(int *)(puVar2 + iVar17 * 4 + 0x4f0) + 0x18) = 0;
            *(float *)(*(int *)(puVar2 + iVar17 * 4 + 0x4f0) + 0x10) = fStack_68 - 233.0f;
            *(float *)(*(int *)(puVar2 + iVar17 * 4 + 0x4f0) + 0x14) = fStack_64;
            *(u32 *)(*(int *)(puVar2 + iVar17 * 4 + 0x4f0) + 0x2c) = 5.0f;
            *(u32 *)(*(int *)(puVar2 + iVar17 * 4 + 0x4d8) + 0x2c) = 5.0f;
            *(u8 *)(*(int *)(puVar2 + iVar17 * 4 + 0x4d8) + 0x18) = 0;
            *(float *)(*(int *)(puVar2 + iVar17 * 4 + 0x4d8) + 0x10) = fStack_68;
            *(float *)(*(int *)(puVar2 + iVar17 * 4 + 0x4d8) + 0x14) = fStack_64;
            if (*psVar16 < 10) {
              *psVar16 = *psVar16 + 1;
              bVar14 = 1;
            }
          }
          else {
            puVar2[iVar17 + 0x938] = puVar2[iVar17 + 0x938] + -1;
          }
          lVar8 = iVar17 + 1;
        }
      }
    }
    else {
      bVar14 = 1;
      *(int *)(DAT_007ce6ec + 0xb8) = *(int *)(DAT_007ce6ec + 0xb8) + -1;
    }
    if ('\x06' < (char)puVar2[0x940]) {
      if (*(int *)(DAT_007ce6ec + 0xbc) < 1) {
        uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b4712);
        fVar22 = (float)FUN_00421fe0(0,0xff,0,*(u16 *)(puVar2 + DAT_006b4712 * 6 + 0xee),5);
        *(short *)(puVar2 + DAT_006b4712 * 6 + 0xf0) = (short)(int)fVar22;
        iVar17 = (int)uVar7;
        *(float *)(iVar17 + 0x2c) = 4.0f;
        *(char *)(iVar17 + 0x18) = (char)*(u16 *)(puVar2 + DAT_006b4712 * 6 + 0xf0);
        *(float *)(iVar17 + 0x10) = (float)(int)DAT_006b4714;
        *(float *)(iVar17 + 0x14) = (float)(int)DAT_006b4716;
        FUN_001127d0(uVar7,1);
        FUN_00115980_arg(uVar7);
        if (*(short *)(puVar2 + DAT_006b4712 * 6 + 0xee) < 5) {
          *(short *)(puVar2 + DAT_006b4712 * 6 + 0xee) =
               *(short *)(puVar2 + DAT_006b4712 * 6 + 0xee) + 1;
          bVar14 = 1;
        }
        uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b4718);
        fVar22 = (float)FUN_00421fe0(0,0xff,0,*(u16 *)(puVar2 + DAT_006b4718 * 6 + 0xee),5);
        *(short *)(puVar2 + DAT_006b4718 * 6 + 0xf0) = (short)(int)fVar22;
        iVar17 = (int)uVar7;
        *(float *)(iVar17 + 0x2c) = 4.0f;
        *(char *)(iVar17 + 0x18) = (char)*(u16 *)(puVar2 + DAT_006b4718 * 6 + 0xf0);
        *(float *)(iVar17 + 0x10) = (float)(int)DAT_006b471a;
        *(float *)(iVar17 + 0x14) = (float)(int)DAT_006b471c;
        FUN_001127d0(uVar7,1);
        FUN_00115980_arg(uVar7);
        if (*(short *)(puVar2 + DAT_006b4718 * 6 + 0xee) < 5) {
          *(short *)(puVar2 + DAT_006b4718 * 6 + 0xee) =
               *(short *)(puVar2 + DAT_006b4718 * 6 + 0xee) + 1;
          bVar14 = 1;
        }
        uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b471e);
        fVar22 = (float)FUN_00421fe0(0,0xff,0,*(u16 *)(puVar2 + DAT_006b471e * 6 + 0xee),5);
        *(short *)(puVar2 + DAT_006b471e * 6 + 0xf0) = (short)(int)fVar22;
        iVar17 = (int)uVar7;
        *(float *)(iVar17 + 0x2c) = 3.0f;
        *(char *)(iVar17 + 0x18) = (char)*(u16 *)(puVar2 + DAT_006b471e * 6 + 0xf0);
        *(float *)(iVar17 + 0x10) = (float)(int)(short)PTR_DAT_006b4720;
        *(u32 *)(iVar17 + 0x14) = 0x43808000;
        FUN_001127d0(uVar7,1);
        FUN_00115980_arg(uVar7);
        if (*(short *)(puVar2 + DAT_006b471e * 6 + 0xee) < 5) {
          *(short *)(puVar2 + DAT_006b471e * 6 + 0xee) =
               *(short *)(puVar2 + DAT_006b471e * 6 + 0xee) + 1;
          bVar14 = 1;
        }
      }
      else {
        bVar14 = 1;
        *(int *)(DAT_007ce6ec + 0xbc) = *(int *)(DAT_007ce6ec + 0xbc) + -1;
      }
    }
    if (*(int *)(DAT_007ce6ec + 0xc4) < 1) {
      lVar15 = 0;
      lVar8 = (int)(char)puVar2[0x254];
      if (0 < lVar8) {
      while (lVar8 = (int)(char)puVar2[0x254], lVar15 < lVar8) {
          iVar17 = (int)lVar15;
          if ((char)puVar2[iVar17 + 0x378] < '\x01') {
            sVar10 = DAT_006b478e + (short)lVar15 * -0x40 + (6 - (char)puVar2[0x253]) * -0x20;
            FUN_004222d0_typed((float*)(&fStack_68),(char)(2),(int)(700),(int)(DAT_006b478c),(int)(sVar10),(int)(sVar10),(int)(*(u16 *)(puVar2 + iVar17 * 6 + 0x356)),(short)(10));
            sVar10 = *(short *)(puVar2 + iVar17 * 6 + 0x356);
            if (sVar10 < 10) {
              *(short *)(puVar2 + iVar17 * 6 + 0x356) = sVar10 + 1;
              bVar14 = 1;
            }
          }
          else {
            puVar2[iVar17 + 0x378] = puVar2[iVar17 + 0x378] + -1;
            bVar14 = 1;
          }
          *(u32 *)(*(int *)(puVar2 + iVar17 * 4 + 0x33c) + 0x2c) = 5.0f;
          *(u8 *)(*(int *)(puVar2 + iVar17 * 4 + 0x33c) + 0x18) = 0;
          *(float *)(*(int *)(puVar2 + iVar17 * 4 + 0x33c) + 0x10) = fStack_68;
          *(float *)(*(int *)(puVar2 + iVar17 * 4 + 0x33c) + 0x14) = fStack_64;
          lVar15 = iVar17 + 1;
        }
      }
      lVar15 = 0;
      if (0 < lVar8) {
        while (lVar15 < (char)puVar2[0x254]) {
          uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b479c);
          iVar17 = (int)uVar7;
          *(float *)(iVar17 + 0x2c) = 5.0f;
          *(float *)(iVar17 + 0x10) = (float)(int)DAT_006b479e;
          iVar13 = (int)lVar15;
          *(float *)(iVar17 + 0x14) =
               (float)((int)DAT_006b47a0 + iVar13 * -0x40 + (6 - (char)puVar2[0x253]) * -0x20);
          if (*(short *)(puVar2 + iVar13 * 6 + 0x356) < 10) {
            *(u8 *)(iVar17 + 0x18) = 0xff;
          }
          else {
            *(u8 *)(iVar17 + 0x18) = 0;
          }
          FUN_001127d0(uVar7,1);
          FUN_00115980_arg(uVar7);
          lVar15 = iVar13 + 1;
        }
      }
      lVar8 = 0;
      while (lVar8 < (char)puVar2[0x254]) {
        iVar17 = (int)lVar8;
        if (9 < *(short *)(puVar2 + iVar17 * 6 + 0x356)) {
          for (iVar13 = 0; iVar13 < 7; iVar13 = iVar13 + 1) {
            uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b47a2);
            iVar12 = (int)uVar7;
            *(float *)(iVar12 + 0x2c) = 5.0f;
            *(u8 *)(iVar12 + 0x18) = 0;
            *(float *)(iVar12 + 0x10) = (float)(int)DAT_006b47a4;
            *(float *)(iVar12 + 0x14) =
                 (float)((int)DAT_006b47a6 + iVar13 * 8 + (6 - (char)puVar2[0x253]) * -0x20 +
                        iVar17 * -0x40);
            FUN_001127d0(uVar7,1);
            FUN_00115980_arg(uVar7);
          }
        }
        lVar8 = iVar17 + 1;
      }
      if (9 < *(short *)(puVar2 + (char)puVar2[0x254] * 6 + 0x350)) {
        uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b479c);
        iVar17 = (int)uVar7;
        *(float *)(iVar17 + 0x2c) = 5.0f;
        *(u8 *)(iVar17 + 0x18) = 0;
        *(float *)(iVar17 + 0x10) = (float)(int)DAT_006b479e;
        *(float *)(iVar17 + 0x14) =
             (float)((int)DAT_006b47a0 + (char)puVar2[0x253] * -0x40 +
                    (6 - (char)puVar2[0x254]) * -0x20);
        FUN_001127d0(uVar7,1);
        FUN_00115980_arg(uVar7);
      }
    }
    else {
      *(int *)(DAT_007ce6ec + 0xc4) = *(int *)(DAT_007ce6ec + 0xc4) + -1;
      bVar14 = 1;
    }
    if (!bVar14) {
      FUN_00447f90((float *)(&uStack_d0),param_1,puVar2[0x93e] + puVar2[0x941]);
      *(u32 *)(puVar2 + 0x944) = uStack_d0;
      *(u32 *)(puVar2 + 0x948) = uStack_cc;
      *puVar2 = 0x23;
    }
    break;
  case 0x23:
    FUN_0044a990((int)(puVar2),(u32*)(*(u32 *)(puVar2 + 0x424)));
    FUN_0044a240((float)(int)DAT_006b46d8,(float)(int)DAT_006b46da,0,3.0f,param_1,DAT_006b46d6
                );
    FUN_0044a240((float)(int)DAT_006b46de,(float)(int)DAT_006b46e0,0,3.0f,param_1,DAT_006b46dc
                );
    FUN_0044a240((float)(int)DAT_006b46d2,(float)(int)DAT_006b46d4,0,3.0f,param_1,DAT_006b46d0
                );
    FUN_0044a240((float)(int)DAT_006b46e4,
                 (float)((int)DAT_006b46e6 + (6 - (char)puVar2[0x93f]) * -0xe),0,3.0f,param_1,
                 DAT_006b46e2);
    *(u8 *)(*(int *)(puVar2 + 0x868) + 0x18) = 0xff;
    *(u8 *)(*(int *)(puVar2 + 0x86c) + 0x18) = 0xff;
    lVar8 = 0;
    if ('\0' < (char)puVar2[0x93f]) {
      while (lVar8 < (char)puVar2[0x93f]) {
        fVar22 = (float)(int)(short)PTR_DAT_006b46f0;
        iVar13 = (int)lVar8;
        fVar23 = *(float *)(puVar2 + iVar13 * 8 + 0x8e4);
        fStack_78 = fVar22 - 240.0f;
        fStack_74 = fVar23 - 3.0f;
        iVar17 = DAT_007ce6ec + (iVar13 + (char)puVar2[0x941]) * 4;
        FUN_00448060(param_1,(char)lVar8,*(u64 *)(&fStack_78),*(u8 *)(iVar17 + 4),
                     *(u16 *)(iVar17 + 6),1);
        psVar16 = (short *)(puVar2 + iVar13 * 6 + 0x8bc);
        if (*(short *)(puVar2 + iVar13 * 6 + 0x8bc) < 0xf) {
          fVar20 = (float)FUN_00421fe0(1,0,0xff,*(short *)(puVar2 + iVar13 * 6 + 0x8bc),0xf);
          *(u32 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x2c) = 3.0f;
          *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x10) = fVar22;
          *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x14) = fVar23;
          *(char *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x18) = (char)(int)fVar20;
          *(u32 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x2c) = 3.0f;
          *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x10) = fVar22 - 233.0f;
          *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x14) = fVar23;
          *(char *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x18) = (char)(int)fVar20;
          *psVar16 = *psVar16 + 1;
        }
        if (lVar8 == (char)puVar2[0x93e]) {
          *(u8 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4f0) + 0x18) = 0xff;
          *(u8 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4d8) + 0x18) = 0xff;
          *psVar16 = 0;
          *(u8 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x18) = 0;
          *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x10) = fVar22 - 233.0f;
          *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x14) = fVar23;
          *(u32 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x2c) = 5.0f;
          *(u32 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x2c) = 5.0f;
          *(u8 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x18) = 0;
          *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x10) = fVar22;
          *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x14) = fVar23;
        }
        else {
          iVar17 = DAT_007ce6ec + (iVar13 + (char)puVar2[0x941]) * 4;
          if ((*(char *)(DAT_007ce6ec + 0xa4) == *(char *)(iVar17 + 4)) &&
             (*(short *)(DAT_007ce6ec + 0xa2) == *(short *)(iVar17 + 6))) {
            *(u32 *)(*(int *)(puVar2 + 0x868) + 0x2c) = 4.0f;
            *(u8 *)(*(int *)(puVar2 + 0x868) + 0x18) = 0;
            *(float *)(*(int *)(puVar2 + 0x868) + 0x10) = fVar22;
            *(float *)(*(int *)(puVar2 + 0x868) + 0x14) = fVar23;
            *(u32 *)(*(int *)(puVar2 + 0x86c) + 0x2c) = 4.0f;
            *(u8 *)(*(int *)(puVar2 + 0x86c) + 0x18) = 0;
            *(float *)(*(int *)(puVar2 + 0x86c) + 0x10) = fVar22 - 233.0f;
            *(float *)(*(int *)(puVar2 + 0x86c) + 0x14) = fVar23;
          }
          else {
            *(u8 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4f0) + 0x18) = 0;
            *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4f0) + 0x10) = fVar22 - 233.0f;
            *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4f0) + 0x14) = fVar23;
            *(u32 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4f0) + 0x2c) = 5.0f;
            *(u32 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4d8) + 0x2c) = 5.0f;
            *(u8 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4d8) + 0x18) = 0;
            *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4d8) + 0x10) = fVar22;
            *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4d8) + 0x14) = fVar23;
          }
        }
        lVar8 = iVar13 + 1;
      }
    }
    cVar4 = *(char *)(((int)(char)puVar2[0x93e] + (int)(char)puVar2[0x941]) * 4 + DAT_007ce6ec + 4);
    *(u32 *)(*(int *)(puVar2 + DAT_006b4796 * 4 + 8) + 0x2c) = 3.0f;
    *(u8 *)(*(int *)(puVar2 + DAT_006b4796 * 4 + 8) + 0x18) = 0;
    *(float *)(*(int *)(puVar2 + DAT_006b4796 * 4 + 8) + 0x10) = (float)(int)DAT_006b4798;
    iVar17 = cVar4 + -1;
    *(float *)(*(int *)(puVar2 + DAT_006b4796 * 4 + 8) + 0x14) =
         (float)((int)DAT_006b479a + iVar17 * -0x40 + (6 - *(char *)(DAT_007ce6ec + 0xad)) * -0x20);
    lVar8 = 0;
    while (lVar8 < (char)puVar2[0x254]) {
      iVar13 = (int)lVar8;
      if (lVar8 == iVar17) {
        *(u16 *)(puVar2 + iVar13 * 6 + 0x354) = 0;
        *(u8 *)(*(int *)(puVar2 + iVar13 * 4 + 0x33c) + 0x18) = 0xff;
        *(u32 *)(*(int *)(puVar2 + DAT_006b478a * 4 + 8) + 0x2c) = 4.0f;
        *(u8 *)(*(int *)(puVar2 + DAT_006b478a * 4 + 8) + 0x18) = 0;
        *(float *)(*(int *)(puVar2 + DAT_006b478a * 4 + 8) + 0x10) = (float)(int)DAT_006b478c;
        *(float *)(*(int *)(puVar2 + DAT_006b478a * 4 + 8) + 0x14) =
             (float)((int)DAT_006b478e + iVar13 * -0x40 + (6 - (char)puVar2[0x253]) * -0x20);
      }
      else {
        *(u32 *)(*(int *)(puVar2 + iVar13 * 4 + 0x33c) + 0x2c) = 5.0f;
        *(u8 *)(*(int *)(puVar2 + iVar13 * 4 + 0x33c) + 0x18) = 0;
        *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x33c) + 0x10) = (float)(int)DAT_006b477a;
        *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x33c) + 0x14) =
             (float)((int)DAT_006b477c + iVar13 * -0x40 + (6 - (char)puVar2[0x253]) * -0x20);
      }
      if (*(short *)(puVar2 + iVar13 * 6 + 0x354) < 0x14) {
        fVar22 = (float)FUN_00421fe0(1,0,0xff,*(short *)(puVar2 + iVar13 * 6 + 0x354),0x14);
        uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b478a);
        iVar12 = (int)uVar7;
        *(float *)(iVar12 + 0x2c) = 4.0f;
        *(char *)(iVar12 + 0x18) = (char)(int)fVar22;
        *(float *)(iVar12 + 0x10) = (float)(int)DAT_006b478c;
        *(float *)(iVar12 + 0x14) =
             (float)((int)DAT_006b478e + iVar13 * -0x40 + (6 - (char)puVar2[0x253]) * -0x20);
        FUN_001127d0(uVar7,1);
        FUN_00115980_arg(uVar7);
        *(short *)(puVar2 + iVar13 * 6 + 0x354) = *(short *)(puVar2 + iVar13 * 6 + 0x354) + 1;
      }
      lVar8 = iVar13 + 1;
    }
    FUN_0044a240((float)(int)DAT_006b4792,
                 (float)((int)DAT_006b4794 + iVar17 * -0x40 + (6 - (char)puVar2[0x253]) * -0x20),0,
                 5.0f,param_1,DAT_006b4790);
    for (lVar8 = 0; lVar8 < (char)puVar2[0x254]; lVar8 = lVar8 + 1) {
      for (iVar17 = 0; iVar17 < 7; iVar17 = iVar17 + 1) {
        FUN_0044a240((float)(int)DAT_006b47a4,
                     (float)((int)DAT_006b47a6 + iVar17 * 8 + (6 - (char)puVar2[0x253]) * -0x20 +
                            (int)lVar8 * -0x40),0,5.0f,param_1,DAT_006b47a2);
      }
    }
    *(u32 *)(*(int *)(puVar2 + DAT_006b4796 * 4 + 8) + 0x2c) = 3.0f;
    *(u8 *)(*(int *)(puVar2 + DAT_006b4796 * 4 + 8) + 0x18) = 0;
    *(float *)(*(int *)(puVar2 + DAT_006b4796 * 4 + 8) + 0x10) = (float)(int)DAT_006b4798;
    *(float *)(*(int *)(puVar2 + DAT_006b4796 * 4 + 8) + 0x14) =
         (float)((int)DAT_006b479a + (*(char *)(DAT_007ce6ec + 0xa4) + -1) * -0x40 +
                (6 - (char)puVar2[0x253]) * -0x20);
    *(u32 *)(*(int *)(puVar2 + DAT_006b4784 * 4 + 8) + 0x2c) = 3.0f;
    *(u8 *)(*(int *)(puVar2 + DAT_006b4784 * 4 + 8) + 0x18) = 0;
    *(float *)(*(int *)(puVar2 + DAT_006b4784 * 4 + 8) + 0x10) = (float)(int)DAT_006b4786;
    *(float *)(*(int *)(puVar2 + DAT_006b4784 * 4 + 8) + 0x14) =
         (float)((int)DAT_006b4788 + (*(char *)(DAT_007ce6ec + 0xa4) + -1) * -0x40 +
                (6 - (char)puVar2[0x253]) * -0x20);
    *(u32 *)(*(int *)(puVar2 + DAT_006b477e * 4 + 8) + 0x2c) = 4.0f;
    *(u8 *)(*(int *)(puVar2 + DAT_006b477e * 4 + 8) + 0x18) = 0;
    *(float *)(*(int *)(puVar2 + DAT_006b477e * 4 + 8) + 0x10) = (float)(int)DAT_006b4780;
    *(float *)(*(int *)(puVar2 + DAT_006b477e * 4 + 8) + 0x14) =
         (float)((int)DAT_006b4782 + (*(char *)(DAT_007ce6ec + 0xa4) + -1) * -0x40 +
                (6 - (char)puVar2[0x253]) * -0x20);
    iVar17 = 0;
    if (0 < (char)puVar2[0x254] + 1) {
      for (; iVar17 < (char)puVar2[0x254] + 1; iVar17 = iVar17 + 1) {
        FUN_0044a240((float)(int)DAT_006b479e,
                     (float)((int)DAT_006b47a0 + iVar17 * -0x40 + (6 - (char)puVar2[0x253]) * -0x20)
                     ,0,5.0f,param_1,DAT_006b479c);
      }
    }
    if ('\x06' < (char)puVar2[0x940]) {
      FUN_0044a240((float)(int)DAT_006b4714,(float)(int)DAT_006b4716,0,4.0f,param_1,
                   DAT_006b4712);
      FUN_0044a240((float)(int)DAT_006b471a,(float)(int)DAT_006b471c,0,4.0f,param_1,
                   DAT_006b4718);
      FUN_0044a240((float)(int)(short)PTR_DAT_006b4720,
                   257.0f - *(float *)(puVar2 + 0x950) * (float)(int)(char)puVar2[0x941],0,3.0f
                   ,param_1,DAT_006b471e);
    }
    if (*(char *)(DAT_007ce6ec + 0xad) == '\x06') {
      FUN_001140d0(4.0f,*(u32 *)(puVar2 + 0x474),*(u32 *)(puVar2 + 0x478),
                   0xffffffffffffffff,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xad)) {
      iVar17 = (int)lVar8;
      cVar4 = *(char *)(DAT_007ce6ec + iVar17 + 0xa6);
      if (cVar4 == '\0') {
        FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2d0) - 64.0f,0xffffffffffffffff,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x274));
      }
      else if ((cVar4 == '\x01') && (lVar8 != 0)) {
        FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2c8) - 64.0f,0xffffffffffffffff,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x3c4));
      }
      lVar8 = iVar17 + 1;
    }
    *(u32 *)(*(int *)(puVar2 + DAT_006b4796 * 4 + 8) + 0x10) =
         *(u32 *)(puVar2 + 0x944);
    *(u32 *)(*(int *)(puVar2 + DAT_006b4796 * 4 + 8) + 0x14) =
         *(u32 *)(puVar2 + 0x948);
    *(u8 *)(*(int *)(puVar2 + DAT_006b4796 * 4 + 8) + 0x18) = 0xff;
    lVar8 = 0;
    while (lVar8 < (char)puVar2[0x254]) {
      iVar17 = (int)lVar8;
      if (*(short *)(puVar2 + iVar17 * 6 + 0x880) == 0) {
        sVar10 = *(short *)(puVar2 + iVar17 * 6 + 0x87c);
        if (sVar10 < 1) {
          if (*(char *)(DAT_007ce6ec + ((int)(char)puVar2[0x93e] + (int)(char)puVar2[0x941]) * 4 + 4
                       ) + -1 == lVar8) {
            fVar22 = (float)FUN_00421fe0(1,0xff,0,sVar10,1);
          }
          else {
            fVar22 = (float)FUN_00421fe0(1,0,0xff,sVar10,1);
          }
          fVar23 = (float)((int)DAT_006b479a + iVar17 * -0x40 + (6 - (char)puVar2[0x253]) * -0x20 +
                          0x20) - 32.0f;
          iVar13 = (int)DAT_006b4798;
          uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b4796);
          iVar12 = (int)uVar7;
          *(float *)(iVar12 + 0x2c) = 4.0f;
          *(float *)(iVar12 + 0x10) = (float)iVar13;
          *(float *)(iVar12 + 0x14) = fVar23;
          *(char *)(iVar12 + 0x18) = (char)(int)fVar22;
          FUN_001127d0(uVar7,1);
          FUN_00115980_arg(uVar7);
          *(short *)(puVar2 + iVar17 * 6 + 0x87c) = *(short *)(puVar2 + iVar17 * 6 + 0x87c) + 1;
        }
        else if (*(char *)(DAT_007ce6ec + ((int)(char)puVar2[0x93e] + (int)(char)puVar2[0x941]) * 4
                          + 4) + -1 == lVar8) {
          fVar22 = (float)((int)DAT_006b479a + iVar17 * -0x40 + (6 - (char)puVar2[0x253]) * -0x20 +
                          0x20) - 32.0f;
          iVar13 = (int)DAT_006b4798;
          uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b4796);
          iVar12 = (int)uVar7;
          *(float *)(iVar12 + 0x2c) = 4.0f;
          *(float *)(iVar12 + 0x10) = (float)iVar13;
          *(float *)(iVar12 + 0x14) = fVar22;
          *(u8 *)(iVar12 + 0x18) = 0;
          FUN_001127d0(uVar7,1);
          FUN_00115980_arg(uVar7);
        }
      }
      else {
        *(short *)(puVar2 + iVar17 * 6 + 0x880) = *(short *)(puVar2 + iVar17 * 6 + 0x880) + -1;
      }
      lVar8 = iVar17 + 1;
    }
    if (puVar2[600] == '\x01') {
      lVar8 = FUN_00108710();
      if (lVar8 != 0) {
        FUN_0044a630(param_1);
        FUN_001085c0();
        *puVar2 = 0x2f;
      }
    }
    else if (((DAT_007e0952 & 0x1000) == 0) && ((DAT_007e095a & 0x1000) == 0)) {
      if (((DAT_007e0952 & 0x4000) == 0) && ((DAT_007e095a & 0x4000) == 0)) {
        if ((DAT_007e0952 & 0x40) == 0) {
          if ((DAT_007e0952 & 0x20) == 0) {
            if ((DAT_007e0952 & 4) == 0) {
              if ((DAT_007e0952 & 8) != 0) {
                cVar4 = puVar2[0x941];
                sVar10 = *(char *)(((int)(char)puVar2[0x93e] + (int)cVar4) * 4 + DAT_007ce6ec + 4) +
                         -1;
                if (cVar4 == '\0') {
                  puVar2[0x93e] = 0;
                }
                else if (cVar4 < '\x06') {
                  puVar2[0x941] = 0;
                }
                else {
                  puVar2[0x941] = cVar4 + -6;
                }
                sVar9 = *(char *)(((int)(char)puVar2[0x93e] + (int)(char)puVar2[0x941]) * 4 +
                                  DAT_007ce6ec + 4) + -1;
                if (sVar9 != sVar10) {
                  *(u16 *)(puVar2 + sVar10 * 6 + 0x87c) = 0;
                  *(u16 *)(puVar2 + sVar9 * 6 + 0x87c) = 0;
                  *(u16 *)(puVar2 + sVar10 * 6 + 0x880) = 0;
                  *(u16 *)(puVar2 + sVar9 * 6 + 0x880) = 0;
                }
                FUN_0010a4e0(0,0,0,0);
              }
            }
            else {
              cVar4 = puVar2[0x941];
              sVar10 = *(char *)(((int)(char)puVar2[0x93e] + (int)cVar4) * 4 + DAT_007ce6ec + 4) +
                       -1;
              if ((int)cVar4 == ((int)(char)puVar2[0x940] - (int)(char)puVar2[0x93f])) {
                puVar2[0x93e] = (puVar2[0x940] - cVar4) + -1;
              }
              else {
                puVar2[0x941] = cVar4 + '\x06';
                if (((int)(char)puVar2[0x940] - (int)(char)puVar2[0x93f]) <= (int)(char)(cVar4 + '\x06')) {
                  puVar2[0x941] = (char)((int)(char)puVar2[0x940] - (int)(char)puVar2[0x93f]);
                }
              }
              sVar9 = *(char *)(((int)(char)puVar2[0x93e] + (int)(char)puVar2[0x941]) * 4 +
                                DAT_007ce6ec + 4) + -1;
              if (sVar9 != sVar10) {
                *(u16 *)(puVar2 + sVar10 * 6 + 0x87c) = 0;
                *(u16 *)(puVar2 + sVar9 * 6 + 0x87c) = 0;
                *(u16 *)(puVar2 + sVar10 * 6 + 0x880) = 0;
                *(u16 *)(puVar2 + sVar9 * 6 + 0x880) = 0;
              }
              FUN_0010a4e0(0,0,0,0);
            }
          }
          else {
            FUN_00108570();
            FUN_00108670_typed(5);
            puVar2[600] = 1;
            FUN_0010a4e0(0,0,0,2);
            if (puVar2[0x251] == '\0') {
              FUN_001a0040_typed(1,0);
            }
          }
        }
        else {
          puVar2[0x49b] = *(u8 *)(DAT_007ce6ec + 0xa4);
          puVar2[0x49c] = (char)*(u16 *)(DAT_007ce6ec + 0xa2);
          puVar2[0x499] = *(u8 *)(DAT_007ce6ec + 0xa4);
          puVar2[0x49a] =
               *(u8 *)
                (((int)(char)puVar2[0x93e] + (int)(char)puVar2[0x941]) * 4 + DAT_007ce6ec + 4);
          *(u8 *)(DAT_007ce6ec + 0xa4) =
               *(u8 *)
                (((int)(char)puVar2[0x93e] + (int)(char)puVar2[0x941]) * 4 + DAT_007ce6ec + 4);
          *(u16 *)(DAT_007ce6ec + 0xa2) =
               *(u16 *)
                (((int)(char)puVar2[0x93e] + (int)(char)puVar2[0x941]) * 4 + DAT_007ce6ec + 6);
          *puVar2 = 0x2b;
          if (puVar2[0x251] == '\0') {
            FUN_001a0040_typed(1,0);
          }
          FUN_0010a4e0(0,0,0,1);
        }
      }
      else {
        cVar4 = puVar2[0x941];
        cVar3 = puVar2[0x93e];
        sVar10 = *(char *)(((int)cVar3 + (int)cVar4) * 4 + DAT_007ce6ec + 4) + -1;
        if ((char)puVar2[0x940] < '\a') {
          if (cVar3 < '\x01') {
            puVar2[0x93e] = puVar2[0x93f] + -1;
          }
          else {
            puVar2[0x93e] = cVar3 + -1;
          }
        }
        else if (cVar3 < '\x02') {
          if (cVar4 < '\x01') {
            if (cVar3 < '\x01') {
              puVar2[0x93e] = 5;
              puVar2[0x941] = puVar2[0x940] - puVar2[0x93f];
            }
            else {
              puVar2[0x93e] = cVar3 + -1;
            }
          }
          else {
            puVar2[0x941] = cVar4 + -1;
          }
        }
        else {
          puVar2[0x93e] = cVar3 + -1;
        }
        FUN_00447f90((float *)(&uStack_e0),param_1,puVar2[0x93e] + puVar2[0x941]);
        *(u32 *)(puVar2 + 0x944) = uStack_e0;
        *(u32 *)(puVar2 + 0x948) = uStack_dc;
        sVar9 = *(char *)(((int)(char)puVar2[0x93e] + (int)(char)puVar2[0x941]) * 4 + DAT_007ce6ec +
                         4) + -1;
        if (sVar9 != sVar10) {
          *(u16 *)(puVar2 + sVar10 * 6 + 0x87c) = 0;
          *(u16 *)(puVar2 + sVar9 * 6 + 0x87c) = 0;
          *(u16 *)(puVar2 + sVar10 * 6 + 0x880) = 0;
          *(u16 *)(puVar2 + sVar9 * 6 + 0x880) = 0;
        }
        FUN_0010a4e0(0,0,0,0);
      }
    }
    else {
      cVar4 = puVar2[0x941];
      cVar3 = puVar2[0x93e];
      lVar8 = (int)cVar3;
      sVar10 = *(char *)(((int)cVar3 + (int)cVar4) * 4 + DAT_007ce6ec + 4) + -1;
      if ((char)puVar2[0x940] < '\a') {
        if (lVar8 < (char)puVar2[0x93f] + -1) {
          puVar2[0x93e] = cVar3 + '\x01';
        }
        else {
          puVar2[0x93e] = 0;
        }
      }
      else {
        cVar1 = puVar2[0x93f];
        if (lVar8 < cVar1 + -2) {
          puVar2[0x93e] = cVar3 + '\x01';
        }
        else if ((int)cVar4 < ((int)(char)puVar2[0x940] - (int)cVar1)) {
          puVar2[0x941] = cVar4 + '\x01';
        }
        else if (lVar8 < cVar1 + -1) {
          puVar2[0x93e] = cVar3 + '\x01';
        }
        else {
          puVar2[0x93e] = 0;
          puVar2[0x941] = 0;
        }
      }
      FUN_00447f90((float *)(&uStack_d8),param_1,puVar2[0x93e] + puVar2[0x941]);
      *(u32 *)(puVar2 + 0x944) = uStack_d8;
      *(u32 *)(puVar2 + 0x948) = uStack_d4;
      sVar9 = *(char *)(((int)(char)puVar2[0x93e] + (int)(char)puVar2[0x941]) * 4 + DAT_007ce6ec + 4
                       ) + -1;
      if (sVar9 != sVar10) {
        *(u16 *)(puVar2 + sVar10 * 6 + 0x87c) = 0;
        *(u16 *)(puVar2 + sVar9 * 6 + 0x87c) = 0;
        *(u16 *)(puVar2 + sVar10 * 6 + 0x880) = 0;
        *(u16 *)(puVar2 + sVar9 * 6 + 0x880) = 0;
      }
      FUN_0010a4e0(0,0,0,0);
    }
    break;
  case 0x24:
    for (iVar17 = 0; iVar17 < 3; iVar17 = iVar17 + 1) {
      *(u16 *)(puVar2 + iVar17 * 6 + 0x484) = 0;
      *(u16 *)(puVar2 + iVar17 * 6 + 0x486) = 0;
      *(u16 *)(puVar2 + iVar17 * 6 + 0x488) = 0;
      puVar2[iVar17 + 0x496] = (char)iVar17 * '\x02';
    }
    *puVar2 = 0x25;
  case 0x25:
    bVar14 = 0;
    FUN_0044a990((int)(puVar2),(u32*)(*(u32 *)(puVar2 + 0x424)));
    fVar22 = (float)((6 - (char)puVar2[0x253]) * 0x20 + 0x20);
    FUN_00449fe0(17.0f,17.0f,fVar22,fVar22,param_1,0);
    fVar22 = (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x19c);
    FUN_0044a110(0x43e20000,0x43e20000,fVar22,fVar22,param_1,0);
    lVar8 = 0;
    while (lVar8 < (char)puVar2[0x254]) {
      iVar17 = (int)lVar8;
      FUN_0044a240(0x43880000,(float)(iVar17 * -0x40 + 0x19f + (6 - (char)puVar2[0x253]) * -0x20),0,
                   5.0f,param_1,0x1d);
      if (lVar8 == (char)puVar2[0x254] + -1) {
        FUN_0044a240(0x43880000,
                     (float)((iVar17 + 1) * -0x40 + 0x19f + (6 - (char)puVar2[0x253]) * -0x20),0,
                     5.0f,param_1,0x1d);
      }
      for (iVar13 = 0; iVar13 < 7; iVar13 = iVar13 + 1) {
        FUN_0044a240(0x43880000,
                     (float)(iVar13 * 8 + 0x167 + (6 - (char)puVar2[0x253]) * -0x20 + iVar17 * -0x40
                            ),0,5.0f,param_1,0x1e);
      }
      cVar3 = (char)lVar8;
      FUN_0044a240(0x44110000,(float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,
                   3.0f,param_1,cVar3 + '\x05');
      FUN_0044a240(0x44028000,(float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,
                   3.0f,param_1,0xb);
      cVar4 = *(char *)(DAT_007ce6ec + 0xa4);
      sVar10 = (short)lVar8;
      if (*(char *)(DAT_007ce6ec + 0xae) == cVar4) {
        iVar13 = cVar4 + -1;
        if (lVar8 == iVar13) {
          sVar10 = (6 - (char)puVar2[0x253]) * -0x20 + 0x163 + sVar10 * -0x40;
          FUN_004222d0_typed((float*)(auStack_80),(char)(2),(int)(0x110),(int)(0x110),(int)(sVar10),(int)((short)iVar13 * 0x40 + sVar10 + (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),(int)(*(u16 *)(puVar2 + 0x486)),(short)(10));
          if (*(short *)(puVar2 + 0x486) < 10) {
            *(short *)(puVar2 + 0x486) = *(short *)(puVar2 + 0x486) + 1;
            bVar14 = 1;
          }
          FUN_0044a240(0x43880000,
                       (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x163 + iVar17 * -0x40),0,
                       5.0f,param_1,0x1c);
          FUN_0044a240(255.0f,fStack_7c - 1.0f,0,3.0f,param_1,0x1a);
          FUN_0044a240(0x43808000,fStack_7c + 17.0f,0,3.0f,param_1,0x1b);
          FUN_0044a240(0x44110000,
                       (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,
                       3.0f,param_1,cVar3 + '\x0f');
          FUN_0044a240(0x44028000,
                       (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,
                       3.0f,param_1,0x15);
        }
      }
      else if (lVar8 == cVar4 + -1) {
        uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),0x1c);
        iVar13 = (int)uVar7;
        *(float *)(iVar13 + 0x2c) = 5.0f;
        fVar22 = (float)FUN_004221a0(0,255.0f,(float)(int)*(short *)(puVar2 + 0x486),10.0f,
                                     0);
        *(short *)(puVar2 + 0x488) = (short)(int)fVar22;
        *(char *)(iVar13 + 0x18) = (char)(int)fVar22;
        *(u32 *)(iVar13 + 0x10) = 0x43880000;
        *(float *)(iVar13 + 0x14) =
             (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x163 + iVar17 * -0x40);
        FUN_001127d0(uVar7,1);
        FUN_00115980_arg(uVar7);
        for (iVar13 = 1; iVar13 < 3; iVar13 = iVar13 + 1) {
          if ((char)puVar2[iVar13 + 0x496] < '\0') {
            sVar9 = (6 - (char)puVar2[0x253]) * -0x20 + 0x163 + sVar10 * -0x40;
            FUN_004222d0_typed((float*)(auStack_80),(char)(2),(int)(0x110),(int)(0x110),(int)(sVar9),(int)((*(char *)(DAT_007ce6ec + 0xa4) + -1) * 0x40 +
                         sVar9 + (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),(int)(*(u16 *)(puVar2 + iVar13 * 6 + 0x486)),(short)(10));
            sVar9 = *(short *)(puVar2 + iVar13 * 6 + 0x486);
            if (sVar9 < 10) {
              *(short *)(puVar2 + iVar13 * 6 + 0x486) = sVar9 + 1;
              bVar14 = 1;
            }
            uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),0x20);
            iVar12 = (int)uVar7;
            *(float *)(iVar12 + 0x2c) = 3.0f;
            *(u8 *)(iVar12 + 0x18) = 0;
            *(float *)(iVar12 + 0x10) = 255.0f;
            *(float *)(iVar12 + 0x14) = fStack_7c + 2.0f;
            FUN_001127d0(uVar7,1);
            FUN_00115980_arg(uVar7);
          }
          else {
            puVar2[iVar13 + 0x496] = puVar2[iVar13 + 0x496] + -1;
            bVar14 = 1;
          }
        }
        sVar10 = (6 - (char)puVar2[0x253]) * -0x20 + 0x163 + sVar10 * -0x40;
        FUN_004222d0_typed((float*)(auStack_80),(char)(2),(int)(0x110),(int)(0x110),(int)(sVar10),(int)((*(char *)(DAT_007ce6ec + 0xa4) + -1) * 0x40 +
                     sVar10 + (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),(int)(*(u16 *)(puVar2 + 0x486)),(short)(10));
        if (*(short *)(puVar2 + 0x486) < 10) {
          *(short *)(puVar2 + 0x486) = *(short *)(puVar2 + 0x486) + 1;
          bVar14 = 1;
        }
        FUN_0044a240(255.0f,fStack_7c - 1.0f,0,3.0f,param_1,0x1a);
        FUN_0044a240(0x43808000,fStack_7c + 17.0f,0,3.0f,param_1,0x1b);
        fVar22 = (float)FUN_004221a0(0,255.0f,(float)(int)*(short *)(puVar2 + 0x486),10.0f,
                                     0);
        *(short *)(puVar2 + 0x488) = (short)(int)fVar22;
        FUN_0044a240(0x44110000,(float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),
                     (float)(int)(short)(int)fVar22,3.0f,param_1,cVar3 + '\x0f');
        fVar22 = (float)FUN_004221a0(0,255.0f,(float)(int)*(short *)(puVar2 + 0x486),10.0f,
                                     0);
        *(short *)(puVar2 + 0x488) = (short)(int)fVar22;
        FUN_0044a240(0x44028000,(float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),
                     (float)(int)(short)(int)fVar22,3.0f,param_1,0x15);
      }
      lVar8 = iVar17 + 1;
    }
    if (*(char *)(DAT_007ce6ec + 0xae) != *(char *)(DAT_007ce6ec + 0xa4)) {
      fVar22 = (float)FUN_004221a0(255.0f,0,(float)(int)*(short *)(puVar2 + 0x486),10.0f,0)
      ;
      *(short *)(puVar2 + 0x488) = (short)(int)fVar22;
      FUN_0044a240(0x44110000,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 +
                          (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),
                   (float)(int)(short)(int)fVar22,3.0f,param_1,
                   *(char *)(DAT_007ce6ec + 0xae) + '\x0e');
      FUN_0044a240(0x44028000,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 +
                          (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),
                   (float)(int)*(short *)(puVar2 + 0x488),3.0f,param_1,0x15);
      FUN_0044a240(0x43880000,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x163 +
                          (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),
                   (float)(int)*(short *)(puVar2 + 0x488),5.0f,param_1,0x1c);
    }
    if (*(char *)(DAT_007ce6ec + 0xad) == '\x06') {
      FUN_001140d0(4.0f,*(u32 *)(puVar2 + 0x474),*(u32 *)(puVar2 + 0x478),
                   0xffffffffffffffff,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xad)) {
      iVar17 = (int)lVar8;
      cVar4 = *(char *)(DAT_007ce6ec + iVar17 + 0xa6);
      if (cVar4 == '\0') {
        FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2d0) - 64.0f,0xffffffffffffffff,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x274));
      }
      else if ((cVar4 == '\x01') && (lVar8 != 0)) {
        FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2c8) - 64.0f,0xffffffffffffffff,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x3c4));
      }
      lVar8 = iVar17 + 1;
    }
    *(short *)(puVar2 + 0x256) = *(short *)(puVar2 + 0x256) + 1;
    if ((!bVar14) && (0x22 < *(short *)(puVar2 + 0x256))) {
      *puVar2 = 0x26;
      *(u16 *)(puVar2 + 0xee) = 0;
      *(u16 *)(puVar2 + 0xf4) = 0;
      *(u16 *)(puVar2 + 0x87c) = 0;
      for (iVar17 = 0; iVar17 < 6; iVar17 = iVar17 + 1) {
        *(u16 *)(DAT_007ce6ec + iVar17 * 6 + 0x7e) = 0;
      }
      *(u16 *)(puVar2 + 0x256) = 0;
    }
    break;
  case 0x26:
    FUN_0044a990((int)(puVar2),(u32*)(*(u32 *)(puVar2 + 0x424)));
    cVar4 = FUN_00449fe0(17.0f,17.0f,(float)((6 - (char)puVar2[0x253]) * 0x20 + 0x20),
                         0xc2200000,param_1,10);
    fVar22 = (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x19c);
    cVar3 = FUN_0044a110(0x43e20000,0x44398000,fVar22,fVar22,param_1,10);
    bVar14 = cVar3 == '\x01' || cVar4 == '\x01';
    lVar8 = 0;
    while (lVar8 < (char)puVar2[0x254]) {
      iVar17 = (int)lVar8;
      FUN_004222d0_typed((float*)(afStack_88),(char)(0),(int)(0x110),(int)(700),(int)(0x19f),(int)(0x19f),(int)(*(u16 *)(DAT_007ce6ec + iVar17 * 6 + 0x7e)),(short)(10));
      FUN_0044a240(afStack_88[0],(float)(iVar17 * -0x40 + 0x19f + (6 - (char)puVar2[0x253]) * -0x20)
                   ,0,5.0f,param_1,0x1d);
      if (lVar8 == *(char *)(DAT_007ce6ec + 0xae) + -1) {
        FUN_0044a240(afStack_88[0],
                     (float)((iVar17 + 1) * -0x40 + 0x19f + (6 - (char)puVar2[0x253]) * -0x20),0,
                     5.0f,param_1,0x1d);
      }
      for (iVar13 = 0; iVar13 < 7; iVar13 = iVar13 + 1) {
        FUN_0044a240(afStack_88[0],
                     (float)(iVar13 * 8 + 0x167 + (6 - (char)puVar2[0x253]) * -0x20 + iVar17 * -0x40
                            ),0,5.0f,param_1,0x1e);
      }
      FUN_0044a240(afStack_88[0] - 17.0f,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x162 +
                          (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),0,3.0f,param_1,0x1a);
      FUN_0044a240(afStack_88[0] - 15.0f,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x174 +
                          (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),0,3.0f,param_1,0x1b);
      if (lVar8 == *(char *)(DAT_007ce6ec + 0xae) + -1) {
        FUN_0044a240(afStack_88[0] + 308.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,
                     3.0f,param_1,(char)lVar8 + '\x0f');
        FUN_0044a240(afStack_88[0] + 250.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,
                     3.0f,param_1,0x15);
      }
      else {
        FUN_0044a240(afStack_88[0] + 308.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,
                     3.0f,param_1,(char)lVar8 + '\x05');
        FUN_0044a240(afStack_88[0] + 250.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,
                     3.0f,param_1,0xb);
      }
      iVar13 = DAT_007ce6ec + iVar17 * 6;
      sVar10 = *(short *)(iVar13 + 0x7e);
      if (sVar10 < 10) {
        *(short *)(iVar13 + 0x7e) = sVar10 + 1;
        bVar14 = 1;
      }
      lVar8 = iVar17 + 1;
    }
    if (*(char *)(DAT_007ce6ec + 0xad) == '\x06') {
      fVar22 = (float)FUN_00421fe0(0,0xff,0,*(u16 *)(DAT_007ce6ec + 0x7e),10);
      if (fVar22 < 2147483648.0f) {
        uVar21 = (int)fVar22;
      }
      else {
        uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
      }
      FUN_001140d0(4.0f,*(u32 *)(puVar2 + 0x474),*(u32 *)(puVar2 + 0x478),
                   uVar21 | 0xffffff00,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xad)) {
      iVar17 = (int)lVar8;
      fVar22 = (float)FUN_00421fe0(0,0xff,0,*(u16 *)(DAT_007ce6ec + iVar17 * 6 + 0x7e),10);
      if (fVar22 < 2147483648.0f) {
        uVar21 = (int)fVar22;
      }
      else {
        uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
      }
      cVar4 = *(char *)(DAT_007ce6ec + iVar17 + 0xa6);
      if (cVar4 == '\0') {
        FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2d0) - 64.0f,uVar21 | 0xffffff00,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x274));
      }
      else if ((cVar4 == '\x01') && (lVar8 != 0)) {
        iVar13 = DAT_007ce6ec + iVar17 * 6;
        sVar10 = *(short *)(iVar13 + 0x7e);
        if (sVar10 < 10) {
          *(short *)(iVar13 + 0x7e) = sVar10 + 1;
          bVar14 = 1;
        }
        FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2c8) - 64.0f,uVar21 | 0xffffff00,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x3c4));
      }
      lVar8 = iVar17 + 1;
    }
    FUN_004222d0_typed((float*)(afStack_88),(char)(0),(int)(0x110),(int)(700),(int)(0x19f),(int)(0x19f),(int)(*(u16 *)(DAT_007ce6ec + 0x7e)),(short)(10));
    *(float *)(puVar2 + 0x8a4) = afStack_88[0] - 16.0f;
    FUN_00422c30(*(u32 *)(puVar2 + 0x8a0),*(u64 *)(puVar2 + 0x8a4),puVar2 + 0x8ac);
    if (puVar2[600] == '\x01') {
      lVar8 = FUN_00108710();
      if (lVar8 != 0) {
        FUN_001085c0();
        *puVar2 = 0x2f;
      }
    }
    else if ((!bVar14) && (puVar2[0x251] != '\x01')) {
      FUN_00108570();
      FUN_00108670_typed(5);
      puVar2[600] = 1;
    }
    break;
  case 0x27:
    bVar14 = 0;
    FUN_0044a990((int)(puVar2),(u32*)(*(u32 *)(puVar2 + 0x424)));
    fVar22 = (float)((6 - (char)puVar2[0x253]) * 0x20 + 0x20);
    FUN_00449fe0(17.0f,17.0f,fVar22,fVar22,param_1,0);
    fVar22 = (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x19c);
    FUN_0044a110(0x43e20000,0x43e20000,fVar22,fVar22,param_1,0);
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xa4)) {
      iVar17 = (int)lVar8;
      FUN_0044a240(0x43880000,(float)(iVar17 * -0x40 + 0x19f + (6 - (char)puVar2[0x253]) * -0x20),0,
                   5.0f,param_1,0x1d);
      if (lVar8 == *(char *)(DAT_007ce6ec + 0xa4) + -1) {
        FUN_0044a240(0x43880000,
                     (float)((iVar17 + 1) * -0x40 + 0x19f + (6 - (char)puVar2[0x253]) * -0x20),0,
                     5.0f,param_1,0x1d);
      }
      for (iVar13 = 0; iVar13 < 7; iVar13 = iVar13 + 1) {
        FUN_0044a240(0x43880000,
                     (float)(iVar13 * 8 + 0x167 + (6 - (char)puVar2[0x253]) * -0x20 + iVar17 * -0x40
                            ),0,5.0f,param_1,0x1e);
      }
      FUN_0044a240(0x44110000,(float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,
                   3.0f,param_1,(char)lVar8 + '\x05');
      FUN_0044a240(0x44028000,(float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,
                   3.0f,param_1,0xb);
      if (lVar8 == *(char *)(DAT_007ce6ec + 0xa4) + -1) {
        if (*(short *)(puVar2 + 0x87c) < 7) {
          fVar22 = (float)FUN_004221a0(0,255.0f,(float)(int)*(short *)(puVar2 + 0x87c),
                                       7.0f,0);
          *(short *)(puVar2 + 0x488) = (short)(int)fVar22;
          FUN_0044a240(0x43880000,
                       (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x163 + iVar17 * -0x40),
                       (float)(int)(short)(int)fVar22,5.0f,param_1,0x1c);
        }
        for (iVar13 = 0; iVar13 < 2; iVar13 = iVar13 + 1) {
          if ((char)puVar2[iVar13 + 0x496] < '\0') {
            psVar16 = (short *)(puVar2 + iVar13 * 6 + 0x484);
            sVar10 = (6 - (char)puVar2[0x253]) * -0x20 + 0x163;
            FUN_004222d0_typed((float*)(&fStack_98),(char)(0),(int)(0x110),(int)(0x110),(int)(sVar10 + (short)lVar8 * -0x40),(int)(sVar10 + (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),(int)(*(u16 *)(puVar2 + iVar13 * 6 + 0x484)),(short)(0xf));
            if (*psVar16 < 0xf) {
              uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),0x20);
              iVar12 = (int)uVar7;
              *(float *)(iVar12 + 0x2c) = 3.0f;
              *(u8 *)(iVar12 + 0x18) = 0;
              *(float *)(iVar12 + 0x10) = fStack_98 - 17.0f;
              *(float *)(iVar12 + 0x14) = fStack_94 - 1.0f;
              FUN_001127d0(uVar7,1);
              FUN_00115980_arg(uVar7);
              *psVar16 = *psVar16 + 1;
              bVar14 = 1;
            }
          }
          else {
            uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),0x20);
            iVar12 = (int)uVar7;
            *(float *)(iVar12 + 0x2c) = 3.0f;
            *(u8 *)(iVar12 + 0x18) = 0;
            *(float *)(iVar12 + 0x10) = 255.0f;
            *(float *)(iVar12 + 0x14) =
                 (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x162 + iVar17 * -0x40);
            FUN_001127d0(uVar7,1);
            FUN_00115980_arg(uVar7);
            puVar2[iVar13 + 0x496] = puVar2[iVar13 + 0x496] + -1;
            bVar14 = 1;
          }
        }
        sVar10 = (6 - (char)puVar2[0x253]) * -0x20 + 0x163;
        FUN_004222d0_typed((float*)(&fStack_90),(char)(1),(int)(0x110),(int)(0x110),(int)(sVar10 + (short)lVar8 * -0x40),(int)(sVar10 + (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),(int)(*(u16 *)(puVar2 + 0x87c)),(short)(0xf));
        FUN_0044a240(fStack_90 - 17.0f,fStack_8c - 1.0f,0,3.0f,param_1,0x1a);
        FUN_0044a240(fStack_90 - 15.0f,fStack_8c + 17.0f,0,3.0f,param_1,0x1b);
        fVar22 = (float)FUN_004221a0(0,255.0f,(float)(int)*(short *)(puVar2 + 0x87c),15.0f,
                                     0);
        *(short *)(puVar2 + 0x488) = (short)(int)fVar22;
        FUN_0044a240(0x44110000,(float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),
                     (float)(int)(short)(int)fVar22,3.0f,param_1,0x1b);
        FUN_0044a240(0x44028000,(float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),
                     (float)(int)*(short *)(puVar2 + 0x488),3.0f,param_1,0x15);
      }
      fVar22 = (float)FUN_004221a0(255.0f,0,(float)(int)*(short *)(puVar2 + 0x87c),15.0f,0)
      ;
      *(short *)(puVar2 + 0x488) = (short)(int)fVar22;
      FUN_0044a240(0x43880000,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x163 +
                          (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),
                   (float)(int)(short)(int)fVar22,5.0f,param_1,0x1c);
      FUN_004222d0_typed((float*)(&fStack_90),(char)(0),(int)(700),(int)(0x110),(int)(0x19f),(int)(0x19f),(int)(*(u16 *)(puVar2 + 0x87c)),(short)(0xf));
      FUN_0044a240(fStack_90,
                   (float)(*(char *)(DAT_007ce6ec + 0xae) * -0x40 + 0x19f +
                          (6 - (char)puVar2[0x253]) * -0x20),0,5.0f,param_1,0x1d);
      for (iVar13 = 0; iVar13 < 7; iVar13 = iVar13 + 1) {
        FUN_0044a240(fStack_90,
                     (float)(iVar13 * 8 + 0x167 + (6 - (char)puVar2[0x253]) * -0x20 +
                            (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),0,5.0f,param_1,0x1e
                    );
      }
      FUN_0044a240(fStack_90 + 250.0f,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 +
                          (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),0,3.0f,param_1,0x15);
      if (*(short *)(puVar2 + 0x87c) < 0xf) {
        bVar14 = 1;
      }
      else if (*(short *)(puVar2 + 0x882) < 0xf) {
        uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),*(char *)(DAT_007ce6ec + 0xae) + 0xe);
        iVar13 = (int)uVar7;
        *(float *)(iVar13 + 0x2c) = 3.0f;
        fVar23 = (float)FUN_00421fe0(0,0,0xff,*(u16 *)(puVar2 + 0x882),0xf);
        fVar22 = (float)FUN_004221a0(1.0f,DAT_007caf94,(float)(int)*(short *)(puVar2 + 0x882),
                                     15.0f,0);
        sVar10 = *(char *)(DAT_007ce6ec + 0xae) + -1;
        FUN_004222d0_typed((float*)(&fStack_90),(char)(0),(int)(0x244),(int)(0x238),(int)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + sVar10 * -0x40),(int)((6 - (char)puVar2[0x253]) * -0x20 + 0x166 + sVar10 * -0x40),(int)(*(u16 *)(puVar2 + 0x882)),(short)(0xf));
        if (fVar23 < 2147483648.0f) {
          uVar18 = (u8)(int)fVar23;
        }
        else {
          uVar18 = (u8)(int)(fVar23 - 2147483648.0f);
        }
        *(u8 *)(iVar13 + 0x18) = uVar18;
        *(float *)(iVar13 + 0x10) = fStack_90;
        *(float *)(iVar13 + 0x14) = fStack_8c;
        fVar22 = fVar22 * 4096.0f;
        if (fVar22 < 2147483648.0f) {
          uVar19 = (u16)(int)fVar22;
        }
        else {
          uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
        }
        *(u16 *)(iVar13 + 0x28) = uVar19;
        if (fVar22 < 2147483648.0f) {
          uVar19 = (u16)(int)fVar22;
        }
        else {
          uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
        }
        *(u16 *)(iVar13 + 0x2a) = uVar19;
        FUN_001127d0(uVar7,1);
        FUN_00115980_arg(uVar7);
        *(short *)(puVar2 + 0x882) = *(short *)(puVar2 + 0x882) + 1;
        bVar14 = 1;
      }
      lVar8 = iVar17 + 1;
    }
    if (*(char *)(DAT_007ce6ec + 0xad) == '\x06') {
      FUN_001140d0(4.0f,*(u32 *)(puVar2 + 0x474),*(u32 *)(puVar2 + 0x478),
                   0xffffffffffffffff,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xa4)) {
      iVar17 = (int)lVar8;
      cVar4 = *(char *)(DAT_007ce6ec + iVar17 + 0xa6);
      if (cVar4 == '\0') {
        FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2d0) - 64.0f,0xffffffffffffffff,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x274));
      }
      else if ((cVar4 == '\x01') && (lVar8 != 0)) {
        FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2c8) - 64.0f,0xffffffffffffffff,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x3c4));
      }
      lVar8 = iVar17 + 1;
    }
    if (*(short *)(puVar2 + 0x87c) < 0xf) {
      fVar22 = (float)FUN_00421fe0(0,0,0xff,*(short *)(puVar2 + 0x87c),0xf);
      if (fVar22 < 2147483648.0f) {
        uVar21 = (int)fVar22;
      }
      else {
        uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
      }
      iVar17 = (int)*(char *)(DAT_007ce6ec + 0xae);
      FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2c4) - 128.0f,
                   *(float *)(puVar2 + iVar17 * 8 + 0x2c8) - 64.0f,uVar21 | 0xffffff00,0x100,0x80,
                   *(u32 *)(puVar2 + iVar17 * 4 + 0x270));
      for (iVar17 = 0; iVar17 < 3; iVar17 = iVar17 + 1) {
        iVar13 = (int)*(char *)(DAT_007ce6ec + 0xae);
        FUN_00427e70_typed(4.0f,*(float *)(puVar2 + iVar13 * 8 + 0x2c4) - 128.0f,
                     *(float *)(puVar2 + iVar13 * 8 + 0x2c8) - 64.0f,uVar21 | 0xffffff00,0x100,0x80,
                     *(u32 *)(puVar2 + iVar13 * 4 + 0x270));
      }
    }
    else {
      iVar17 = (int)*(char *)(DAT_007ce6ec + 0xae);
      FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2c4) - 128.0f,
                   *(float *)(puVar2 + iVar17 * 8 + 0x2c8) - 64.0f,0xffffffffffffffff,0x100,0x80,
                   *(u32 *)(puVar2 + iVar17 * 4 + 0x270));
    }
    if (*(short *)(puVar2 + 0x87c) < 0xf) {
      for (iVar17 = 0; iVar17 < 3; iVar17 = iVar17 + 1) {
        uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),*(char *)(DAT_007ce6ec + 0xae) + 0xe);
        iVar13 = (int)uVar7;
        *(float *)(iVar13 + 0x2c) = 3.0f;
        fVar23 = (float)FUN_00421fe0(2,0xff,0,*(u16 *)(puVar2 + 0x87c),0xf);
        fVar22 = (float)FUN_004221a0(10.0f,1.0f,(float)(int)*(short *)(puVar2 + 0x87c),
                                     15.0f,1);
        FUN_004222d0_typed((float*)(&fStack_90),(char)(0),(int)(0x20),(int)(0x244),(int)(100),(int)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 +
                     (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),(int)(*(u16 *)(puVar2 + 0x87c)),(short)(0xf));
        if (fVar23 < 2147483648.0f) {
          uVar18 = (u8)(int)fVar23;
        }
        else {
          uVar18 = (u8)(int)(fVar23 - 2147483648.0f);
        }
        *(u8 *)(iVar13 + 0x18) = uVar18;
        *(float *)(iVar13 + 0x10) = fStack_90;
        *(float *)(iVar13 + 0x14) = fStack_8c;
        fVar22 = fVar22 * 4096.0f;
        if (fVar22 < 2147483648.0f) {
          uVar19 = (u16)(int)fVar22;
        }
        else {
          uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
        }
        *(u16 *)(iVar13 + 0x28) = uVar19;
        if (fVar22 < 2147483648.0f) {
          uVar19 = (u16)(int)fVar22;
        }
        else {
          uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
        }
        *(u16 *)(iVar13 + 0x2a) = uVar19;
        *(u32 *)
         (*(int *)(*(int *)(iVar13 + 8) + 0x184) + *(char *)(DAT_007ce6ec + 0xae) * 0x80 + 0x72c) =
             1;
        FUN_001127d0(uVar7,1);
        FUN_00115980_arg(uVar7);
      }
    }
    else {
      uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),*(char *)(DAT_007ce6ec + 0xae) + 0xe);
      iVar17 = (int)uVar7;
      *(float *)(iVar17 + 0x2c) = 3.0f;
      fVar23 = (float)FUN_00421fe0(1,0xff,0,*(u16 *)(puVar2 + 0x87c),0xf);
      fVar22 = (float)FUN_004221a0(10.0f,1.0f,(float)(int)*(short *)(puVar2 + 0x87c),
                                   15.0f,1);
      FUN_004222d0_typed((float*)(&fStack_90),(char)(0),(int)(0x20),(int)(0x244),(int)(100),(int)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 +
                   (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),(int)(*(u16 *)(puVar2 + 0x87c)),(short)(0xf));
      if (fVar23 < 2147483648.0f) {
        uVar18 = (u8)(int)fVar23;
      }
      else {
        uVar18 = (u8)(int)(fVar23 - 2147483648.0f);
      }
      *(u8 *)(iVar17 + 0x18) = uVar18;
      *(float *)(iVar17 + 0x10) = fStack_90;
      *(float *)(iVar17 + 0x14) = fStack_8c;
      *(u32 *)
       (*(char *)(DAT_007ce6ec + 0xae) * 0x80 + *(int *)(*(int *)(iVar17 + 8) + 0x184) + 0x72c) = 0;
      fVar22 = fVar22 * 4096.0f;
      if (fVar22 < 2147483648.0f) {
        uVar19 = (u16)(int)fVar22;
      }
      else {
        uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
      }
      *(u16 *)(iVar17 + 0x28) = uVar19;
      if (fVar22 < 2147483648.0f) {
        uVar19 = (u16)(int)fVar22;
      }
      else {
        uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
      }
      *(u16 *)(iVar17 + 0x2a) = uVar19;
      FUN_001127d0(uVar7,1);
      FUN_00115980_arg(uVar7);
    }
    fVar22 = (float)FUN_004221a0((float)(*(char *)(DAT_007ce6ec + 0xa4) * 0x40 + 0x10),
                                 (float)(*(char *)(DAT_007ce6ec + 0xae) * 0x40 + 0x10),
                                 (float)(int)*(short *)(puVar2 + 0x87c),15.0f,1);
    iVar17 = *(char *)(DAT_007ce6ec + 0xa4) * 0x40;
    *(int *)(puVar2 + 0x8b8) = (int)((fVar22 + 16.0f + (float)iVar17) - (float)(iVar17 + 0x10));
    *(float *)(puVar2 + 0x8a8) = (433.0f - fVar22) - (float)((6 - (char)puVar2[0x253]) * 0x20);
    FUN_00422c30(*(u32 *)(puVar2 + 0x8a0),*(u64 *)(puVar2 + 0x8a4),puVar2 + 0x8ac);
    if (*(short *)(puVar2 + 0x87c) < 0xf) {
      *(short *)(puVar2 + 0x87c) = *(short *)(puVar2 + 0x87c) + 1;
      bVar14 = 1;
    }
    *(short *)(puVar2 + 0x256) = *(short *)(puVar2 + 0x256) + 1;
    if ((!bVar14) && (0x31 < *(short *)(puVar2 + 0x256))) {
      *(u16 *)(puVar2 + 0xee) = 0;
      *(u16 *)(puVar2 + 0xf4) = 0;
      *(u16 *)(puVar2 + 0x87c) = 0;
      for (iVar17 = 0; iVar17 < 6; iVar17 = iVar17 + 1) {
        *(u16 *)(DAT_007ce6ec + iVar17 * 6 + 0x7e) = 0;
      }
      *(u16 *)(puVar2 + 0x256) = 0;
      *puVar2 = 0x28;
    }
    break;
  case 0x28:
    uVar21 = 0xffffffff;
    FUN_0044a990((int)(puVar2),(u32*)(*(u32 *)(puVar2 + 0x424)));
    cVar4 = FUN_00449fe0(17.0f,17.0f,(float)((6 - (char)puVar2[0x253]) * 0x20 + 0x20),
                         0xc2200000,param_1,10);
    fVar22 = (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x19c);
    cVar3 = FUN_0044a110(0x43e20000,0x44398000,fVar22,fVar22,param_1,10);
    bVar14 = cVar3 == '\x01' || cVar4 == '\x01';
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xae)) {
      iVar17 = (int)lVar8;
      FUN_004222d0_typed((float*)(afStack_a0),(char)(0),(int)(0x110),(int)(700),(int)(0x19f),(int)(0x19f),(int)(*(u16 *)(DAT_007ce6ec + iVar17 * 6 + 0x7e)),(short)(10));
      FUN_0044a240(afStack_a0[0],(float)(iVar17 * -0x40 + 0x19f + (6 - (char)puVar2[0x253]) * -0x20)
                   ,0,5.0f,param_1,0x1d);
      if (lVar8 == *(char *)(DAT_007ce6ec + 0xae) + -1) {
        FUN_0044a240(afStack_a0[0],
                     (float)((iVar17 + 1) * -0x40 + 0x19f + (6 - (char)puVar2[0x253]) * -0x20),0,
                     5.0f,param_1,0x1d);
      }
      for (iVar13 = 0; iVar13 < 7; iVar13 = iVar13 + 1) {
        FUN_0044a240(afStack_a0[0],
                     (float)(iVar13 * 8 + 0x167 + (6 - (char)puVar2[0x253]) * -0x20 + iVar17 * -0x40
                            ),0,5.0f,param_1,0x1e);
      }
      FUN_0044a240(afStack_a0[0] - 17.0f,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x162 +
                          (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),0,3.0f,param_1,0x1a);
      FUN_0044a240(afStack_a0[0] - 15.0f,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x174 +
                          (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),0,3.0f,param_1,0x1b);
      if (lVar8 == *(char *)(DAT_007ce6ec + 0xae) + -1) {
        FUN_0044a240(afStack_a0[0] + 308.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,
                     3.0f,param_1,(char)lVar8 + '\x0f');
        FUN_0044a240(afStack_a0[0] + 250.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,
                     3.0f,param_1,0x15);
      }
      else {
        FUN_0044a240(afStack_a0[0] + 308.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,
                     3.0f,param_1,(char)lVar8 + '\x05');
        FUN_0044a240(afStack_a0[0] + 250.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,
                     3.0f,param_1,0xb);
      }
      iVar13 = DAT_007ce6ec + iVar17 * 6;
      sVar10 = *(short *)(iVar13 + 0x7e);
      if (sVar10 < 10) {
        *(short *)(iVar13 + 0x7e) = sVar10 + 1;
        bVar14 = 1;
      }
      lVar8 = iVar17 + 1;
    }
    if (*(char *)(DAT_007ce6ec + 0xad) == '\x06') {
      fVar22 = (float)FUN_00421fe0(0,0xff,0,*(u16 *)(DAT_007ce6ec + 0x7e),10);
      if (fVar22 < 2147483648.0f) {
        uVar21 = (int)fVar22;
      }
      else {
        uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
      }
      uVar21 = uVar21 | 0xffffff00;
      FUN_001140d0(4.0f,*(u32 *)(puVar2 + 0x474),*(u32 *)(puVar2 + 0x478),uVar21
                   ,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xa4)) {
      iVar17 = (int)lVar8;
      fVar22 = (float)FUN_00421fe0(0,0xff,0,*(u16 *)(DAT_007ce6ec + iVar17 * 6 + 0x7e),10);
      if (fVar22 < 2147483648.0f) {
        uVar21 = (int)fVar22;
      }
      else {
        uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
      }
      uVar21 = uVar21 | 0xffffff00;
      cVar4 = *(char *)(DAT_007ce6ec + iVar17 + 0xa6);
      if (cVar4 == '\0') {
        FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2d0) - 64.0f,uVar21,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x274));
      }
      else if ((cVar4 == '\x01') && (lVar8 != 0)) {
        FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2c8) - 64.0f,uVar21,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x3c4));
      }
      lVar8 = iVar17 + 1;
    }
    iVar17 = (int)*(char *)(DAT_007ce6ec + 0xae);
    FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2c4) - 128.0f,
                 *(float *)(puVar2 + iVar17 * 8 + 0x2c8) - 64.0f,uVar21,0x100,0x80,
                 *(u32 *)(puVar2 + iVar17 * 4 + 0x270));
    FUN_004222d0_typed((float*)(afStack_a0),(char)(0),(int)(0x110),(int)(700),(int)(0x19f),(int)(0x19f),(int)(*(u16 *)(DAT_007ce6ec + 0x7e)),(short)(10));
    *(float *)(puVar2 + 0x8a4) = afStack_a0[0] - 16.0f;
    FUN_00422c30(*(u32 *)(puVar2 + 0x8a0),*(u64 *)(puVar2 + 0x8a4),puVar2 + 0x8ac);
    if (puVar2[600] == '\x01') {
      lVar8 = FUN_00108710();
      if (lVar8 != 0) {
        FUN_0016f1f0_typed(0x141d,0);
        return 0xffffffff;
      }
    }
    else if ((!bVar14) && (puVar2[0x251] != '\x01')) {
      FUN_00108570();
      FUN_00108670_typed(5);
      puVar2[600] = 1;
    }
    break;
  case 0x29:
    bVar14 = 0;
    FUN_0044a990((int)(puVar2),(u32*)(*(u32 *)(puVar2 + 0x424)));
    fVar22 = (float)((6 - (char)puVar2[0x253]) * 0x20 + 0x20);
    FUN_00449fe0(17.0f,17.0f,fVar22,fVar22,param_1,0);
    fVar22 = (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x19c);
    FUN_0044a110(0x43e20000,0x43e20000,fVar22,fVar22,param_1,0);
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xa4)) {
      iVar13 = (int)lVar8;
      FUN_0044a240(0x43880000,(float)(iVar13 * -0x40 + 0x19f + (6 - (char)puVar2[0x253]) * -0x20),0,
                   5.0f,param_1,0x1d);
      FUN_0044a240(0x43880000,
                   (float)((iVar13 + 1) * -0x40 + 0x19f + (6 - (char)puVar2[0x253]) * -0x20),0,
                   5.0f,param_1,0x1d);
      for (iVar17 = 0; iVar17 < 7; iVar17 = iVar17 + 1) {
        FUN_0044a240(0x43880000,
                     (float)(iVar17 * 8 + 0x167 + (6 - (char)puVar2[0x253]) * -0x20 + iVar13 * -0x40
                            ),0,5.0f,param_1,0x1e);
      }
      FUN_0044a240(0x43880000,(float)((6 - (char)puVar2[0x253]) * -0x20 + 0x163 + iVar13 * -0x40),0,
                   5.0f,param_1,0x1c);
      FUN_0044a240(0x44110000,(float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar13 * -0x40),0,
                   3.0f,param_1,(char)lVar8 + '\x05');
      FUN_0044a240(0x44028000,(float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar13 * -0x40),0,
                   3.0f,param_1,0xb);
      FUN_0044a240(255.0f,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x163 +
                          (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),0,3.0f,param_1,0x1a);
      FUN_0044a240(0x43808000,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x174 +
                          (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),0,3.0f,param_1,0x1b);
      if (0xe < *(short *)(puVar2 + 0x87c)) {
        uVar6 = FUN_00421fe0(0,0xff,0,*(u16 *)(puVar2 + 0x882),0xf);
        FUN_0044a240(0x44028000,(float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar13 * -0x40),
                     uVar6,3.0f,param_1,0x15);
      }
      if (*(short *)(puVar2 + 0x87c) < 0xf) {
        bVar14 = 1;
      }
      else if (*(short *)(puVar2 + 0x882) < 0xf) {
        uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),*(char *)(DAT_007ce6ec + 0xae) + 0xe);
        iVar17 = (int)uVar7;
        *(float *)(iVar17 + 0x2c) = 3.0f;
        fVar23 = (float)FUN_00421fe0(0,0,0xff,*(u16 *)(puVar2 + 0x882),0xf);
        fVar22 = (float)FUN_004221a0(1.0f,DAT_007caf94,(float)(int)*(short *)(puVar2 + 0x882),
                                     15.0f,0);
        sVar10 = *(char *)(DAT_007ce6ec + 0xae) + -1;
        FUN_004222d0_typed((float*)(&uStack_a8),(char)(0),(int)(0x244),(int)(0x238),(int)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + sVar10 * -0x40),(int)((6 - (char)puVar2[0x253]) * -0x20 + 0x166 + sVar10 * -0x40),(int)(*(u16 *)(puVar2 + 0x882)),(short)(0xf));
        if (fVar23 < 2147483648.0f) {
          uVar18 = (u8)(int)fVar23;
        }
        else {
          uVar18 = (u8)(int)(fVar23 - 2147483648.0f);
        }
        *(u8 *)(iVar17 + 0x18) = uVar18;
        *(u32 *)(iVar17 + 0x10) = uStack_a8;
        *(u32 *)(iVar17 + 0x14) = uStack_a4;
        fVar22 = fVar22 * 4096.0f;
        if (fVar22 < 2147483648.0f) {
          uVar19 = (u16)(int)fVar22;
        }
        else {
          uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
        }
        *(u16 *)(iVar17 + 0x28) = uVar19;
        if (fVar22 < 2147483648.0f) {
          uVar19 = (u16)(int)fVar22;
        }
        else {
          uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
        }
        *(u16 *)(iVar17 + 0x2a) = uVar19;
        FUN_001127d0(uVar7,1);
        FUN_00115980_arg(uVar7);
        *(short *)(puVar2 + 0x882) = *(short *)(puVar2 + 0x882) + 1;
        bVar14 = 1;
      }
      lVar8 = iVar13 + 1;
    }
    if (*(char *)(DAT_007ce6ec + 0xad) == '\x06') {
      FUN_001140d0(4.0f,*(u32 *)(puVar2 + 0x474),*(u32 *)(puVar2 + 0x478),
                   0xffffffffffffffff,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xa4)) {
      iVar17 = (int)lVar8;
      cVar4 = *(char *)(DAT_007ce6ec + iVar17 + 0xa6);
      if (cVar4 == '\0') {
        FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2d0) - 64.0f,0xffffffffffffffff,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x274));
      }
      else if ((cVar4 == '\x01') && (lVar8 != 0)) {
        FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2c8) - 64.0f,0xffffffffffffffff,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x3c4));
      }
      lVar8 = iVar17 + 1;
    }
    fVar22 = (float)FUN_00421fe0(0,0,0xff,*(u16 *)(puVar2 + 0x87c),0xf);
    if (fVar22 < 2147483648.0f) {
      uVar21 = (int)fVar22;
    }
    else {
      uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
    }
    iVar17 = (int)*(char *)(DAT_007ce6ec + 0xae);
    FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2c4) - 128.0f,
                 *(float *)(puVar2 + iVar17 * 8 + 0x2c8) - 64.0f,uVar21 | 0xffffff00,0x100,0x80,
                 *(u32 *)(puVar2 + iVar17 * 4 + 0x270));
    if (*(short *)(puVar2 + 0x87c) < 0xf) {
      for (iVar17 = 0; iVar17 < 3; iVar17 = iVar17 + 1) {
        uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),*(char *)(DAT_007ce6ec + 0xae) + 0xe);
        iVar13 = (int)uVar7;
        *(float *)(iVar13 + 0x2c) = 3.0f;
        fVar23 = (float)FUN_00421fe0(2,0xff,0,*(u16 *)(puVar2 + 0x87c),0xf);
        fVar22 = (float)FUN_004221a0(10.0f,1.0f,(float)(int)*(short *)(puVar2 + 0x87c),
                                     15.0f,1);
        FUN_004222d0_typed((float*)(&uStack_a8),(char)(0),(int)(0x20),(int)(0x244),(int)(100),(int)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 +
                     (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),(int)(*(u16 *)(puVar2 + 0x87c)),(short)(0xf));
        if (fVar23 < 2147483648.0f) {
          uVar18 = (u8)(int)fVar23;
        }
        else {
          uVar18 = (u8)(int)(fVar23 - 2147483648.0f);
        }
        *(u8 *)(iVar13 + 0x18) = uVar18;
        *(u32 *)(iVar13 + 0x10) = uStack_a8;
        *(u32 *)(iVar13 + 0x14) = uStack_a4;
        fVar22 = fVar22 * 4096.0f;
        if (fVar22 < 2147483648.0f) {
          uVar19 = (u16)(int)fVar22;
        }
        else {
          uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
        }
        *(u16 *)(iVar13 + 0x28) = uVar19;
        if (fVar22 < 2147483648.0f) {
          uVar19 = (u16)(int)fVar22;
        }
        else {
          uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
        }
        *(u16 *)(iVar13 + 0x2a) = uVar19;
        *(u32 *)
         (*(int *)(*(int *)(iVar13 + 8) + 0x184) + *(char *)(DAT_007ce6ec + 0xae) * 0x80 + 0x72c) =
             1;
        FUN_001127d0(uVar7,1);
        FUN_00115980_arg(uVar7);
      }
    }
    else {
      uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),*(char *)(DAT_007ce6ec + 0xae) + 0xe);
      iVar17 = (int)uVar7;
      *(float *)(iVar17 + 0x2c) = 3.0f;
      fVar23 = (float)FUN_00421fe0(1,0xff,0,*(u16 *)(puVar2 + 0x87c),0xf);
      fVar22 = (float)FUN_004221a0(10.0f,1.0f,(float)(int)*(short *)(puVar2 + 0x87c),
                                   15.0f,1);
      FUN_004222d0_typed((float*)(&uStack_a8),(char)(0),(int)(0x20),(int)(0x244),(int)(100),(int)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 +
                   (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),(int)(*(u16 *)(puVar2 + 0x87c)),(short)(0xf));
      if (fVar23 < 2147483648.0f) {
        uVar18 = (u8)(int)fVar23;
      }
      else {
        uVar18 = (u8)(int)(fVar23 - 2147483648.0f);
      }
      *(u8 *)(iVar17 + 0x18) = uVar18;
      *(u32 *)(iVar17 + 0x10) = uStack_a8;
      *(u32 *)(iVar17 + 0x14) = uStack_a4;
      fVar22 = fVar22 * 4096.0f;
      if (fVar22 < 2147483648.0f) {
        uVar19 = (u16)(int)fVar22;
      }
      else {
        uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
      }
      *(u16 *)(iVar17 + 0x28) = uVar19;
      if (fVar22 < 2147483648.0f) {
        uVar19 = (u16)(int)fVar22;
      }
      else {
        uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
      }
      *(u16 *)(iVar17 + 0x2a) = uVar19;
      *(u32 *)
       (*(char *)(DAT_007ce6ec + 0xae) * 0x80 + *(int *)(*(int *)(iVar17 + 8) + 0x184) + 0x72c) = 0;
      FUN_001127d0(uVar7,1);
      FUN_00115980_arg(uVar7);
    }
    fVar22 = (float)FUN_004221a0((float)(*(char *)(DAT_007ce6ec + 0xa4) * 0x40 + 0x10),
                                 (float)(*(char *)(DAT_007ce6ec + 0xae) * 0x40 + 0x10),
                                 (float)(int)*(short *)(puVar2 + 0x87c),15.0f,1);
    iVar17 = *(char *)(DAT_007ce6ec + 0xa4) * 0x40;
    *(int *)(puVar2 + 0x8b8) = (int)((fVar22 + 16.0f + (float)iVar17) - (float)(iVar17 + 0x10));
    *(float *)(puVar2 + 0x8a8) = (433.0f - fVar22) - (float)((6 - (char)puVar2[0x254]) * 0x20);
    FUN_00422c30(*(u32 *)(puVar2 + 0x8a0),*(u64 *)(puVar2 + 0x8a4),puVar2 + 0x8ac);
    if (*(short *)(puVar2 + 0x87c) < 0xf) {
      *(short *)(puVar2 + 0x87c) = *(short *)(puVar2 + 0x87c) + 1;
      bVar14 = 1;
    }
    *(short *)(puVar2 + 0x256) = *(short *)(puVar2 + 0x256) + 1;
    if ((!bVar14) && (0x31 < *(short *)(puVar2 + 0x256))) {
      *(u16 *)(puVar2 + 0xee) = 0;
      *(u16 *)(puVar2 + 0xf4) = 0;
      *(u16 *)(puVar2 + 0x87c) = 0;
      for (iVar17 = 0; iVar17 < 6; iVar17 = iVar17 + 1) {
        *(u16 *)(DAT_007ce6ec + iVar17 * 6 + 0x7e) = 0;
      }
      *(u16 *)(puVar2 + 0x256) = 0;
      *puVar2 = 0x2a;
    }
    break;
  case 0x2a:
    FUN_0044a990((int)(puVar2),(u32*)(*(u32 *)(puVar2 + 0x424)));
    cVar4 = FUN_00449fe0(17.0f,17.0f,(float)((6 - (char)puVar2[0x253]) * 0x20 + 0x20),
                         0xc2200000,param_1,10);
    fVar22 = (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x19c);
    cVar3 = FUN_0044a110(0x43e20000,0x44398000,fVar22,fVar22,param_1,10);
    bVar14 = cVar3 == '\x01' || cVar4 == '\x01';
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xae)) {
      iVar17 = (int)lVar8;
      FUN_004222d0_typed((float*)(afStack_b0),(char)(0),(int)(0x110),(int)(700),(int)(0x19f),(int)(0x19f),(int)(*(u16 *)(DAT_007ce6ec + iVar17 * 6 + 0x7e)),(short)(10));
      FUN_0044a240(afStack_b0[0],(float)(iVar17 * -0x40 + 0x19f + (6 - (char)puVar2[0x253]) * -0x20)
                   ,0,5.0f,param_1,0x1d);
      FUN_0044a240(afStack_b0[0],
                   (float)((iVar17 + 1) * -0x40 + 0x19f + (6 - (char)puVar2[0x253]) * -0x20),0,
                   5.0f,param_1,0x1d);
      for (iVar13 = 0; iVar13 < 7; iVar13 = iVar13 + 1) {
        FUN_0044a240(afStack_b0[0],
                     (float)(iVar13 * 8 + 0x167 + (6 - (char)puVar2[0x253]) * -0x20 + iVar17 * -0x40
                            ),0,5.0f,param_1,0x1e);
      }
      FUN_0044a240(afStack_b0[0] - 17.0f,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x163 +
                          (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),0,3.0f,param_1,0x1a);
      FUN_0044a240(afStack_b0[0] - 15.0f,
                   (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x174 +
                          (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),0,3.0f,param_1,0x1b);
      if (lVar8 == *(char *)(DAT_007ce6ec + 0xae) + -1) {
        FUN_0044a240(afStack_b0[0] + 308.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,
                     3.0f,param_1,(char)lVar8 + '\x0f');
        FUN_0044a240(afStack_b0[0] + 250.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,
                     3.0f,param_1,0x15);
      }
      else {
        FUN_0044a240(afStack_b0[0] + 308.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,
                     3.0f,param_1,(char)lVar8 + '\x05');
        FUN_0044a240(afStack_b0[0] + 250.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,
                     3.0f,param_1,0xb);
      }
      iVar13 = DAT_007ce6ec + iVar17 * 6;
      sVar10 = *(short *)(iVar13 + 0x7e);
      if (sVar10 < 10) {
        *(short *)(iVar13 + 0x7e) = sVar10 + 1;
        bVar14 = 1;
      }
      lVar8 = iVar17 + 1;
    }
    if (*(char *)(DAT_007ce6ec + 0xad) == '\x06') {
      fVar22 = (float)FUN_00421fe0(0,0xff,0,*(u16 *)(DAT_007ce6ec + 0x7e),10);
      if (fVar22 < 2147483648.0f) {
        uVar21 = (int)fVar22;
      }
      else {
        uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
      }
      FUN_001140d0(4.0f,*(u32 *)(puVar2 + 0x474),*(u32 *)(puVar2 + 0x478),
                   uVar21 | 0xffffff00,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xa4)) {
      iVar17 = (int)lVar8;
      fVar22 = (float)FUN_00421fe0(0,0xff,0,*(u16 *)(DAT_007ce6ec + iVar17 * 6 + 0x7e),10);
      if (fVar22 < 2147483648.0f) {
        uVar21 = (int)fVar22;
      }
      else {
        uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
      }
      cVar4 = *(char *)(DAT_007ce6ec + iVar17 + 0xa6);
      if (cVar4 == '\0') {
        FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2d0) - 64.0f,uVar21 | 0xffffff00,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x274));
      }
      else if ((cVar4 == '\x01') && (lVar8 != 0)) {
        FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2c8) - 64.0f,uVar21 | 0xffffff00,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x3c4));
      }
      lVar8 = iVar17 + 1;
    }
    FUN_004222d0_typed((float*)(afStack_b0),(char)(0),(int)(0x110),(int)(700),(int)(0x19f),(int)(0x19f),(int)(*(u16 *)(DAT_007ce6ec + 0x7e)),(short)(10));
    *(float *)(puVar2 + 0x8a4) = afStack_b0[0] - 16.0f;
    FUN_00422c30(*(u32 *)(puVar2 + 0x8a0),*(u64 *)(puVar2 + 0x8a4),puVar2 + 0x8ac);
    if (puVar2[600] == '\x01') {
      lVar8 = FUN_00108710();
      if (lVar8 != 0) {
        FUN_0016f1f0_typed(0x141d,0);
        return 0xffffffff;
      }
    }
    else if ((!bVar14) && (puVar2[0x251] != '\x01')) {
      FUN_00108570();
      FUN_00108670_typed(5);
      puVar2[600] = 1;
    }
    break;
  case 0x2b:
    for (iVar17 = 0; iVar17 < 3; iVar17 = iVar17 + 1) {
      *(u16 *)(puVar2 + iVar17 * 6 + 0x484) = 0;
      *(u16 *)(puVar2 + iVar17 * 6 + 0x486) = 0;
      *(u16 *)(puVar2 + iVar17 * 6 + 0x488) = 0;
      puVar2[iVar17 + 0x496] = (char)iVar17 * '\x02';
    }
    *(u16 *)(puVar2 + 0x1a6) = 0;
    *(u16 *)(puVar2 + 0x1a8) = 0;
    *(u16 *)(puVar2 + 0x1aa) = 0;
    *(u16 *)(puVar2 + 0x876) = 0;
    *(u16 *)(puVar2 + 0x878) = 0;
    *(u16 *)(puVar2 + 0x87a) = 0;
    *(u16 *)(puVar2 + 0x870) = 0;
    *puVar2 = 0x2c;
  case 0x2c:
    bVar14 = 0;
    FUN_0044a990((int)(puVar2),(u32*)(*(u32 *)(puVar2 + 0x424)));
    FUN_0044a240((float)(int)DAT_006b46d8,(float)(int)DAT_006b46da,0,3.0f,param_1,DAT_006b46d6
                );
    FUN_0044a240((float)(int)DAT_006b46de,(float)(int)DAT_006b46e0,0,3.0f,param_1,DAT_006b46dc
                );
    FUN_0044a240((float)(int)DAT_006b46d2,(float)(int)DAT_006b46d4,0,3.0f,param_1,DAT_006b46d0
                );
    FUN_0044a240((float)(int)DAT_006b46e4,
                 (float)((int)DAT_006b46e6 + (6 - (char)puVar2[0x93f]) * -0xe),0,3.0f,param_1,
                 DAT_006b46e2);
    *(u8 *)(*(int *)(puVar2 + 0x868) + 0x18) = 0xff;
    *(u8 *)(*(int *)(puVar2 + 0x86c) + 0x18) = 0xff;
    lVar8 = 0;
    if ('\0' < (char)puVar2[0x93f]) {
      while (lVar8 < (char)puVar2[0x93f]) {
        fStack_c0 = (float)(int)(short)PTR_DAT_006b46f0;
        iVar13 = (int)lVar8;
        fStack_bc = *(float *)(puVar2 + iVar13 * 8 + 0x8e4);
        fStack_b8 = fStack_c0 - 240.0f;
        fStack_b4 = fStack_bc - 3.0f;
        fVar22 = (float)FUN_00421fe0(2,0,0xff,*(u16 *)(puVar2 + 0x870),0xf);
        iVar17 = DAT_007ce6ec + (iVar13 + (char)puVar2[0x941]) * 4;
        FUN_00448cf0(param_1,(char)lVar8,*(u64 *)(&fStack_b8),*(u8 *)(iVar17 + 4),
                     *(u16 *)(iVar17 + 6),1,(short)(int)fVar22);
        iVar17 = DAT_007ce6ec + (iVar13 + (char)puVar2[0x941]) * 4;
        if ((puVar2[0x49b] != *(char *)(iVar17 + 4)) &&
           ((int)(char)puVar2[0x49c] != (int)*(short *)(iVar17 + 6))) {
          if (*(short *)(puVar2 + iVar13 * 6 + 0x8bc) < 0xf) {
            fVar22 = (float)FUN_00421fe0(2,0,0xff,*(short *)(puVar2 + iVar13 * 6 + 0x8bc),0xf);
            *(u32 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x2c) = 3.0f;
            *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x10) = fStack_c0;
            *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x14) = fStack_bc;
            *(char *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x18) = (char)(int)fVar22;
            *(u32 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x2c) = 3.0f;
            *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x10) = fStack_c0 - 233.0f;
            *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x14) = fStack_bc;
            *(char *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x18) = (char)(int)fVar22;
            *(short *)(puVar2 + iVar13 * 6 + 0x8bc) = *(short *)(puVar2 + iVar13 * 6 + 0x8bc) + 1;
          }
        }
        if (lVar8 == (char)puVar2[0x93e]) {
          *(u8 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4f0) + 0x18) = 0xff;
          *(u8 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4d8) + 0x18) = 0xff;
          *(u16 *)(puVar2 + iVar13 * 6 + 0x8bc) = 0;
          *(u32 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x2c) = 3.0f;
          *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x10) = fStack_c0 - 233.0f;
          *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x14) = fStack_bc;
          *(u8 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x18) = 0;
          *(u32 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x2c) = 5.0f;
          *(u8 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x18) = 0;
          *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x10) = fStack_c0;
          *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x14) = fStack_bc;
        }
        else {
          iVar17 = DAT_007ce6ec + (iVar13 + (char)puVar2[0x941]) * 4;
          if ((puVar2[0x49b] == *(char *)(iVar17 + 4)) &&
             ((int)(char)puVar2[0x49c] == (int)*(short *)(iVar17 + 6))) {
            *(u8 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4f0) + 0x18) = 0;
            *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4f0) + 0x10) = fStack_c0 - 233.0f;
            *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4f0) + 0x14) = fStack_bc;
            *(u32 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4f0) + 0x2c) = 5.0f;
            *(u32 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4d8) + 0x2c) = 5.0f;
            *(u8 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4d8) + 0x18) = 0;
            *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4d8) + 0x10) = fStack_c0;
            *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4d8) + 0x14) = fStack_bc;
            if (*(short *)(puVar2 + 0x870) < 0xf) {
              fVar22 = (float)FUN_00421fe0(1,0,0xff,*(short *)(puVar2 + 0x870),0xf);
              *(u32 *)(*(int *)(puVar2 + 0x868) + 0x2c) = 3.0f;
              *(char *)(*(int *)(puVar2 + 0x868) + 0x18) = (char)(int)fVar22;
              *(float *)(*(int *)(puVar2 + 0x868) + 0x10) = fStack_c0;
              *(float *)(*(int *)(puVar2 + 0x868) + 0x14) = fStack_bc;
              *(u32 *)(*(int *)(puVar2 + 0x86c) + 0x2c) = 3.0f;
              *(char *)(*(int *)(puVar2 + 0x86c) + 0x18) = (char)(int)fVar22;
              *(float *)(*(int *)(puVar2 + 0x86c) + 0x10) = fStack_c0 - 233.0f;
              *(float *)(*(int *)(puVar2 + 0x86c) + 0x14) = fStack_bc;
              *(short *)(puVar2 + 0x870) = *(short *)(puVar2 + 0x870) + 1;
              bVar14 = 1;
            }
          }
          else {
            *(u8 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4f0) + 0x18) = 0;
            *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4f0) + 0x10) = fStack_c0 - 233.0f;
            *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4f0) + 0x14) = fStack_bc;
            *(u32 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4f0) + 0x2c) = 5.0f;
            *(u32 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4d8) + 0x2c) = 5.0f;
            *(u8 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4d8) + 0x18) = 0;
            *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4d8) + 0x10) = fStack_c0;
            *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4d8) + 0x14) = fStack_bc;
          }
        }
        lVar8 = iVar13 + 1;
      }
    }
    iVar17 = *(char *)(((int)(char)puVar2[0x93e] + (int)(char)puVar2[0x941]) * 4 + DAT_007ce6ec + 4)
             + -1;
    lVar8 = 0;
    while (lVar8 < (char)puVar2[0x254]) {
      iVar13 = (int)lVar8;
      if (lVar8 == iVar17) {
        *(u8 *)(*(int *)(puVar2 + iVar13 * 4 + 0x33c) + 0x18) = 0xff;
        *(u32 *)(*(int *)(puVar2 + DAT_006b478a * 4 + 8) + 0x2c) = 4.0f;
        *(u8 *)(*(int *)(puVar2 + DAT_006b478a * 4 + 8) + 0x18) = 0;
        *(float *)(*(int *)(puVar2 + DAT_006b478a * 4 + 8) + 0x10) = (float)(int)DAT_006b478c;
        *(float *)(*(int *)(puVar2 + DAT_006b478a * 4 + 8) + 0x14) =
             (float)((int)DAT_006b478e + iVar13 * -0x40 + (6 - (char)puVar2[0x253]) * -0x20);
      }
      else {
        *(u32 *)(*(int *)(puVar2 + iVar13 * 4 + 0x33c) + 0x2c) = 5.0f;
        *(u8 *)(*(int *)(puVar2 + iVar13 * 4 + 0x33c) + 0x18) = 0;
        *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x33c) + 0x10) = (float)(int)DAT_006b477a;
        *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x33c) + 0x14) =
             (float)((int)DAT_006b477c + iVar13 * -0x40 + (6 - (char)puVar2[0x253]) * -0x20);
      }
      lVar8 = iVar13 + 1;
    }
    *(u32 *)(*(int *)(puVar2 + DAT_006b4784 * 4 + 8) + 0x2c) = 3.0f;
    *(u8 *)(*(int *)(puVar2 + DAT_006b4784 * 4 + 8) + 0x18) = 0;
    *(float *)(*(int *)(puVar2 + DAT_006b4784 * 4 + 8) + 0x10) = (float)(int)DAT_006b4786;
    *(float *)(*(int *)(puVar2 + DAT_006b4784 * 4 + 8) + 0x14) =
         (float)((int)DAT_006b4788 + (*(char *)(DAT_007ce6ec + 0xa4) + -1) * -0x40 +
                (6 - (char)puVar2[0x253]) * -0x20);
    *(float *)(*(int *)(puVar2 + DAT_006b477e * 4 + 8) + 0x10) = (float)(int)DAT_006b4780;
    *(float *)(*(int *)(puVar2 + DAT_006b477e * 4 + 8) + 0x14) =
         (float)((int)DAT_006b4782 + (*(char *)(DAT_007ce6ec + 0xa4) + -1) * -0x40 +
                (6 - (char)puVar2[0x253]) * -0x20);
    if (puVar2[0x49b] != *(char *)(DAT_007ce6ec + 0xa4)) {
      uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b477e);
      fVar22 = (float)FUN_00421fe0(1,0,0xff,*(u16 *)(puVar2 + 0x876),7);
      if (*(short *)(puVar2 + 0x876) < 7) {
        *(short *)(puVar2 + 0x876) = *(short *)(puVar2 + 0x876) + 1;
        bVar14 = 1;
      }
      iVar13 = (int)uVar7;
      *(char *)(iVar13 + 0x18) = (char)(int)fVar22;
      *(float *)(iVar13 + 0x2c) = 3.0f;
      *(float *)(iVar13 + 0x10) = (float)(int)DAT_006b4780;
      *(float *)(iVar13 + 0x14) =
           (float)((int)DAT_006b4782 + ((char)puVar2[0x499] + -1) * -0x40 +
                  (6 - (char)puVar2[0x253]) * -0x20);
      FUN_001127d0(uVar7,1);
      FUN_00115980_arg(uVar7);
      for (iVar13 = 0; iVar13 < 3; iVar13 = iVar13 + 1) {
        if ((char)puVar2[iVar13 + 0x496] < '\x01') {
          uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b477e);
          FUN_004222d0_typed((float*)(&fStack_c0),(char)(0),(int)(DAT_006b4780 + 1),(int)(DAT_006b4780 + 1),(int)(DAT_006b4782 + ((char)puVar2[0x499] + -1) * -0x40 +
                       (6 - (char)puVar2[0x253]) * -0x20),(int)(DAT_006b4782 + ((char)puVar2[0x49a] + -1) * -0x40 +
                       (6 - (char)puVar2[0x253]) * -0x20),(int)(*(u16 *)(puVar2 + iVar13 * 6 + 0x486)),(short)(7));
          sVar10 = *(short *)(puVar2 + iVar13 * 6 + 0x486);
          if (sVar10 < 7) {
            *(short *)(puVar2 + iVar13 * 6 + 0x486) = sVar10 + 1;
            bVar14 = 1;
          }
          iVar12 = (int)uVar7;
          *(char *)(iVar12 + 0x18) = -1 - (char)(0xff / (iVar13 + 1));
          *(float *)(iVar12 + 0x2c) = 5.0f;
          *(float *)(iVar12 + 0x10) = fStack_c0;
          *(float *)(iVar12 + 0x14) = fStack_bc;
          FUN_001127d0(uVar7,1);
          FUN_00115980_arg(uVar7);
        }
        else {
          puVar2[iVar13 + 0x496] = puVar2[iVar13 + 0x496] + -1;
          bVar14 = 1;
        }
      }
    }
    FUN_0044a240((float)(int)DAT_006b4792,
                 (float)((int)DAT_006b4794 + iVar17 * -0x40 + (6 - (char)puVar2[0x253]) * -0x20),0,
                 4.0f,param_1,DAT_006b4790);
    for (lVar8 = 0; lVar8 < (char)puVar2[0x254]; lVar8 = lVar8 + 1) {
      for (iVar17 = 0; iVar17 < 7; iVar17 = iVar17 + 1) {
        FUN_0044a240((float)(int)DAT_006b47a4,
                     (float)((int)DAT_006b47a6 + iVar17 * 8 + (6 - (char)puVar2[0x253]) * -0x20 +
                            (int)lVar8 * -0x40),0,5.0f,param_1,DAT_006b47a2);
      }
    }
    iVar17 = 0;
    if (0 < (char)puVar2[0x254] + 1) {
      for (; iVar17 < (char)puVar2[0x254] + 1; iVar17 = iVar17 + 1) {
        FUN_0044a240((float)(int)DAT_006b479e,
                     (float)((int)DAT_006b47a0 + iVar17 * -0x40 + (6 - (char)puVar2[0x253]) * -0x20)
                     ,0,5.0f,param_1,DAT_006b479c);
      }
    }
    if ('\x06' < (char)puVar2[0x940]) {
      FUN_0044a240((float)(int)DAT_006b4714,(float)(int)DAT_006b4716,0,4.0f,param_1,
                   DAT_006b4712);
      FUN_0044a240((float)(int)DAT_006b471a,(float)(int)DAT_006b471c,0,4.0f,param_1,
                   DAT_006b4718);
      FUN_0044a240((float)(int)(short)PTR_DAT_006b4720,
                   257.0f - *(float *)(puVar2 + 0x950) * (float)(int)(char)puVar2[0x941],0,3.0f
                   ,param_1,DAT_006b471e);
    }
    lVar8 = 0;
    while (lVar8 < (char)puVar2[0x254]) {
      iVar17 = (int)lVar8;
      if (*(short *)(puVar2 + iVar17 * 6 + 0x880) == 0) {
        sVar10 = *(short *)(puVar2 + iVar17 * 6 + 0x87c);
        if (sVar10 < 1) {
          if (*(char *)(DAT_007ce6ec + ((int)(char)puVar2[0x93e] + (int)(char)puVar2[0x941]) * 4 + 4
                       ) + -1 == lVar8) {
            fVar22 = (float)FUN_00421fe0(1,0xff,0,sVar10,1);
          }
          else {
            fVar22 = (float)FUN_00421fe0(1,0,0xff,sVar10,1);
          }
          fVar23 = (float)((int)DAT_006b479a + iVar17 * -0x40 + (6 - (char)puVar2[0x253]) * -0x20 +
                          0x20) - 32.0f;
          iVar13 = (int)DAT_006b4798;
          uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b4796);
          iVar12 = (int)uVar7;
          *(float *)(iVar12 + 0x2c) = 4.0f;
          *(float *)(iVar12 + 0x10) = (float)iVar13;
          *(float *)(iVar12 + 0x14) = fVar23;
          *(char *)(iVar12 + 0x18) = (char)(int)fVar22;
          FUN_001127d0(uVar7,1);
          FUN_00115980_arg(uVar7);
          *(short *)(puVar2 + iVar17 * 6 + 0x87c) = *(short *)(puVar2 + iVar17 * 6 + 0x87c) + 1;
        }
        else if (*(char *)(DAT_007ce6ec + ((int)(char)puVar2[0x93e] + (int)(char)puVar2[0x941]) * 4
                          + 4) + -1 == lVar8) {
          fVar22 = (float)((int)DAT_006b479a + iVar17 * -0x40 + (6 - (char)puVar2[0x253]) * -0x20 +
                          0x20) - 32.0f;
          iVar13 = (int)DAT_006b4798;
          uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b4796);
          iVar12 = (int)uVar7;
          *(float *)(iVar12 + 0x2c) = 4.0f;
          *(float *)(iVar12 + 0x10) = (float)iVar13;
          *(float *)(iVar12 + 0x14) = fVar22;
          *(u8 *)(iVar12 + 0x18) = 0;
          FUN_001127d0(uVar7,1);
          FUN_00115980_arg(uVar7);
        }
      }
      else {
        *(short *)(puVar2 + iVar17 * 6 + 0x880) = *(short *)(puVar2 + iVar17 * 6 + 0x880) + -1;
      }
      lVar8 = iVar17 + 1;
    }
    if (*(char *)(DAT_007ce6ec + 0xad) == '\x06') {
      FUN_001140d0(4.0f,*(u32 *)(puVar2 + 0x474),*(u32 *)(puVar2 + 0x478),
                   0xffffffffffffffff,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xad)) {
      iVar17 = (int)lVar8;
      cVar4 = *(char *)(DAT_007ce6ec + iVar17 + 0xa6);
      if (cVar4 == '\0') {
        FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2d0) - 64.0f,0xffffffffffffffff,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x274));
      }
      else if ((cVar4 == '\x01') && (lVar8 != 0)) {
        FUN_001140d0(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2c8) - 64.0f,0xffffffffffffffff,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x3c4));
      }
      lVar8 = iVar17 + 1;
    }
    if (puVar2[600] == '\x01') {
      lVar8 = FUN_00108710();
      if (lVar8 != 0) {
        FUN_0044a630(param_1);
        FUN_001085c0();
        *puVar2 = 0x2f;
      }
    }
    else if ((puVar2[0x49b] == *(char *)(DAT_007ce6ec + 0xa4)) &&
            ((int)(char)puVar2[0x49c] == (int)*(short *)(DAT_007ce6ec + 0xa2))) {
      FUN_00108570();
      FUN_00108670_typed(5);
      puVar2[600] = 1;
    }
    else if (!bVar14) {
      if (puVar2[0x251] == '\x01') {
        *puVar2 = 0x23;
      }
      else {
        FUN_0044a630(param_1);
        *puVar2 = 0x2d;
      }
    }
    break;
  case 0x2d:
    if (*(int *)(puVar2 + 0x23c) != 0) {
      *(u32 *)(puVar2 + 0x23c) = 0;
    }
    cVar4 = FUN_00449c90(param_1,puVar2[0x93e] + puVar2[0x941]);
    uVar6 = FUN_0035bc00_u32(10,*(u32 *)(puVar2 + 0x248),*(u32 *)(puVar2 + 0x244),
                         cVar4 + 1);
    *(u32 *)(puVar2 + 0x23c) = uVar6;
    *puVar2 = 0x30;
    break;
  case 0x2e:
    FUN_00108570();
    FUN_00108670_typed(5);
    *puVar2 = 0x2f;
    break;
  case 0x2f:
    lVar8 = FUN_00108710();
    if (lVar8 != 0) {
      FUN_0016f1f0_typed(0x141d,0);
      return 0xffffffff;
    }
    break;
  case 0x30:
    cVar4 = puVar2[0x252];
    puVar2[0x252] = cVar4 + '\x01';
    if ('\x13' < (char)(cVar4 + '\x01')) {
      FUN_0016f1f0_typed(0x141d,0);
      return 0xffffffff;
    }
  }
  return 0;
}

#pragma pop
#pragma push
#pragma opt_loop_invariants on
// FUN_00447AD0 NONMATCHING

void FUN_00447ad0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  u32 *puVar6;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  for (iVar4 = 0; iVar4 < 6; iVar4 = iVar4 + 1) {
    iVar3 = iVar1 + iVar4 * 4;
    puVar6 = (u32 *)(iVar3 + 0x274);
    if (*puVar6 != 0) {
      FUN_004d0f00_arg(*puVar6);
      *puVar6 = 0;
    }
  }
  for (iVar4 = 0; iVar4 < 5; iVar4 = iVar4 + 1) {
    iVar3 = iVar1 + iVar4 * 4;
    puVar6 = (u32 *)(iVar3 + 0x3c8);
    if (*puVar6 != 0) {
      FUN_004d0f00_arg(*puVar6);
      *puVar6 = 0;
    }
  }
  for (iVar4 = 0; iVar4 < 2; iVar4 = iVar4 + 1) {
    iVar3 = iVar1 + iVar4 * 4;
    puVar6 = (u32 *)(iVar3 + 0x424);
    if (*puVar6 != 0) {
      FUN_004d0f00_arg(*puVar6);
      *puVar6 = 0;
    }
  }
  puVar6 = (u32 *)(iVar1 + 4);
  if (*puVar6 != 0) {
    FUN_001124b0_u32(*puVar6);
    *puVar6 = 0;
  }
  puVar6 = (u32 *)(iVar1 + 0xe8);
  if (*puVar6 != 0) {
    FUN_001124b0_u32(*puVar6);
    *puVar6 = 0;
  }
  for (iVar4 = 0; iVar4 < 0x38; iVar4 = iVar4 + 1) {
    iVar3 = iVar1 + iVar4 * 4;
    puVar6 = (u32 *)(iVar3 + 8);
    if (*puVar6 != 0) {
      FUN_00115980_arg(*puVar6);
      *puVar6 = 0;
    }
  }
  for (iVar4 = 0; iVar4 < 6; iVar4 = iVar4 + 1) {
    iVar3 = iVar1 + iVar4 * 4;
    puVar6 = (u32 *)(iVar3 + 0x4a8);
    if (*puVar6 != 0) {
      FUN_00115980_arg(*puVar6);
      *puVar6 = 0;
    }
    puVar6 = (u32 *)(iVar3 + 0x4c0);
    if (*puVar6 != 0) {
      FUN_00115980_arg(*puVar6);
      *puVar6 = 0;
    }
    puVar6 = (u32 *)(iVar3 + 0x4f0);
    if (*puVar6 != 0) {
      FUN_00115980_arg(*puVar6);
      *puVar6 = 0;
    }
    puVar6 = (u32 *)(iVar3 + 0x4d8);
    if (*puVar6 != 0) {
      FUN_00115980_arg(*puVar6);
      *puVar6 = 0;
    }
    for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
      for (iVar5 = 0; iVar5 < 0xc; iVar5 = iVar5 + 1) {
        iVar2 = iVar1 + iVar4 * 0x90 + iVar3 * 0x30 + iVar5 * 4;
        puVar6 = (u32 *)(iVar2 + 0x508);
        if (*puVar6 != 0) {
          FUN_00115980_arg(*puVar6);
          *puVar6 = 0;
        }
      }
    }
  }
  for (iVar4 = 0; iVar4 < 6; iVar4 = iVar4 + 1) {
    iVar3 = iVar1 + iVar4 * 4;
    puVar6 = (u32 *)(iVar3 + 0x33c);
    if (*puVar6 != 0) {
      FUN_00115980_arg(*puVar6);
      *puVar6 = 0;
    }
  }
  puVar6 = (u32 *)(iVar1 + 0x868);
  if (*puVar6 != 0) {
    FUN_00115980_arg(*puVar6);
    *puVar6 = 0;
  }
  puVar6 = (u32 *)(iVar1 + 0x86c);
  if (*puVar6 != 0) {
    FUN_00115980_arg(*puVar6);
    *puVar6 = 0;
  }
  if (*(char *)(iVar1 + 0x251) == '\0') {
    FUN_001a0040_typed(1,0);
    FUN_00449fa0();
    (*DAT_0096017c)(*(u32 *)(iVar1 + 0x248));
  }
  if (DAT_007ce6ac != 0) {
    FUN_00195020_y2();
    DAT_007ce6ac = 0;
  }
  FUN_002699a0_typed(*(u32 *)(iVar1 + 0x47c));
  (*DAT_0096017c)(*(u32 *)(param_1 + 0x3c));
  return;
}

#pragma pop
// FUN_00447E70

u32 FUN_00447e70(u64 param_1,u8 param_2,u8 param_3)

{
  u32 uVar1;
  u32 uVar3;
  u32 lVar2;
  u8 *puVar4;
  
  lVar2 = (*DAT_00960184_abs)(1,0x95c,0x40000);
  if (lVar2 == 0) {
    return 0;
  }
  else {
    uVar3 = FUN_00194b80_u32(param_1,0x106f,DAT_006b4a00,(u32 (*)(int))FUN_0043ca30,FUN_00447ad0,lVar2);
    puVar4 = (u8 *)lVar2;
    *puVar4 = 0;
    *(u32 *)(puVar4 + 0x30c) = 0x3f800000;
    puVar4[0x93e] = 0;
    puVar4[0x941] = 0;
    puVar4[0x251] = param_3;
    puVar4[0x250] = param_2;
    puVar4[0x252] = 0;
    *(u16 *)(puVar4 + 0x256) = 0;
    puVar4[600] = 0;
    puVar4[0x259] = 0;
    *(u32 *)(puVar4 + 0x480) = 0;
    uVar1 = FUN_00269690_typed(1,0x18,0x10);
    *(u32 *)(puVar4 + 0x47c) = uVar1;
    *(u16 *)(puVar4 + 0x958) = 0;
    *(u16 *)(puVar4 + 0x95a) = 6;
    *(u16 *)(puVar4 + 0x956) = 0;
    *(u16 *)(puVar4 + 0x954) = 0;
    FUN_0016f1f0_typed(0x141d,1);
  }
  return uVar3;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00447F90 NONMATCHING

void FUN_00447f90(float *param_1,int param_2,char param_3)

{
  char cVar1;
  char cVar2;
  int iVar3;
  long lVar4;
  
  cVar1 = *(char *)(param_3 * 4 + DAT_007ce6ec + 4);
  iVar3 = (int)DAT_006b479a;
  cVar2 = *(char *)(*(int *)(param_2 + 0x3c) + 0x253);
  for (lVar4 = 0; lVar4 < *(char *)(DAT_007ce6ec + 0xa0); lVar4 = (long)((int)lVar4 + 1)) {
  }
  *param_1 = (float)(int)DAT_006b4798;
  param_1[1] = (float)(iVar3 + (cVar1 + -1) * -0x40 + (6 - cVar2) * -0x20 + 0x20) - 32.0f;
  return;
}

#pragma pop
#pragma push
#pragma opt_loop_invariants on
// FUN_00448060 NONMATCHING

void FUN_00448060(int param_1,u8 param_2,u64 param_3,char param_4,short param_5,
                 char param_6)

{
  int iVar1;
  int iVar2;
  int iVar4;
  u64 uVar3;
  char cVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  short sVar9;
  char cVar10;
  int iVar11;
  long lVar12;
  float fVar13;
  float fVar14;
  u32 uVar15;
  float afStack_8[2];
  
  iVar2 = *(int *)((int)param_1 + 0x3c);
  cVar8 = '\0';
  cVar10 = '\0';
  cVar5 = *(char *)(iVar2 + 0x93e);
  if (param_6 == '\0') {
    cVar5 = -1;
  }
  for (iVar7 = 0; iVar7 < 0x100; iVar7 = iVar7 + 1) {
  }
  afStack_8[0] = *(float *)&param_3;
  afStack_8[0] = afStack_8[0] + 127.0f;
  afStack_8[1] = *((float *)&param_3 + 1);
  afStack_8[1] = afStack_8[1] + 10.0f;
  lVar12 = (long)cVar5;
  iVar7 = (int)(char)param_2;
  iVar4 = (int)((long)((u32)param_2 << 0x38) >> 0x3f);
  if ((long)((u32)param_2 << 0x38) >> 0x38 == lVar12) {
    iVar1 = 0;
    fVar14 = afStack_8[0] + 15.0f;
    for (; iVar1 < 2; iVar1 = iVar1 + 1) {
      uVar15 = 255.0f;
      iVar6 = iVar2 + iVar1 * 2;
      if (*(short *)(iVar6 + 0x958) == 0) {
        if (*(short *)(iVar6 + 0x954) < 0x17) {
          *(short *)(iVar6 + 0x954) = *(short *)(iVar6 + 0x954) + 1;
        }
        uVar15 = FUN_004221a0(0,255.0f,(float)(int)*(short *)(iVar6 + 0x954),23.0f,2);
      }
      else {
        *(short *)(iVar6 + 0x958) = *(short *)(iVar6 + 0x958) + -1;
      }
      iVar6 = iVar2 + iVar1 * 2;
      fVar13 = (float)FUN_004221a0(afStack_8[0],fVar14,(float)(int)*(short *)(iVar6 + 0x954),23.0f,
                                   1);
      FUN_0044a240((float)(1 - iVar1) * 20.0f + (fVar13 - 90.0f) + 0.0f,afStack_8[1],uVar15,3.0f,
                   param_1,9);
      fVar13 = (float)FUN_004221a0(afStack_8[0],afStack_8[0] - 15.0f,(float)(int)*(short *)(iVar6 + 0x954),
                                   23.0f,1);
      FUN_0044a240((float)iVar1 * 20.0f + fVar13 + 61.0f + 0.0f,afStack_8[1],uVar15,3.0f,param_1,0x36
                  );
    }
    if (*(short *)(iVar2 + 0x956) == 0x17) {
      for (iVar1 = 0; iVar1 < 2; iVar1 = iVar1 + 1) {
        iVar6 = iVar2 + iVar1 * 2;
        *(u16 *)(iVar6 + 0x954) = 0;
        *(short *)(iVar6 + 0x958) = ((short)(iVar1 * 2) + (short)iVar1) * 2;
      }
    }
  }
  else if (((*(char *)(DAT_007ce6ec + 0xa4) == param_4) &&
           (*(short *)(DAT_007ce6ec + 0xa2) == param_5)) && (param_6 == '\x01')) {
    iVar1 = 0;
    fVar14 = afStack_8[0] + 61.0f;
    for (; iVar1 < 2; iVar1 = iVar1 + 1) {
      FUN_0044a240((afStack_8[0] - 90.0f) + (float)iVar1 * 20.0f,afStack_8[1] + 2.0f,0,3.0f,param_1,0x26)
      ;
      FUN_0044a240(fVar14 + (float)iVar1 * 20.0f,afStack_8[1] + 2.0f,0,3.0f,param_1,0x26);
    }
  }
  iVar1 = (int)param_5;
  if (param_5 < 10) {
    sVar9 = param_5;
    if (CONCAT44(iVar4,iVar7) != lVar12) {
      if (((*(char *)(DAT_007ce6ec + 0xa4) == param_4) &&
          (*(short *)(DAT_007ce6ec + 0xa2) == param_5)) && (param_6 == '\x01')) {
        FUN_0044a240(afStack_8[0] - 20.0f,afStack_8[1],0,3.0f,param_1,(char)param_5 + '(');
      }
      else {
        FUN_0044a330(afStack_8[0] - 20.0f,afStack_8[1],0,3.0f,param_1,(char)param_5 + '\v');
      }
    }
  }
  else if (param_5 < 100) {
    cVar8 = (char)(iVar1 / 10);
    sVar9 = (short)(iVar1 % 10);
    if (CONCAT44(iVar4,iVar7) != lVar12) {
      cVar5 = (char)(iVar1 % 10);
      if (((*(char *)(DAT_007ce6ec + 0xa4) == param_4) &&
          (*(short *)(DAT_007ce6ec + 0xa2) == param_5)) && (param_6 == '\x01')) {
        FUN_0044a240(afStack_8[0] - 30.0f,afStack_8[1],0,3.0f,param_1,cVar8 + '(');
        FUN_0044a240(afStack_8[0] - 10.0f,afStack_8[1],0,3.0f,param_1,cVar5 + '(');
      }
      else {
        FUN_0044a330(afStack_8[0] - 30.0f,afStack_8[1],0,3.0f,param_1,cVar8 + '\v');
        FUN_0044a330(afStack_8[0] - 10.0f,afStack_8[1],0,3.0f,param_1,cVar5 + '\v');
      }
    }
  }
  else {
    cVar10 = (char)(iVar1 / 100);
    iVar11 = (int)(short)(iVar1 / 100);
    iVar6 = (iVar1 + iVar11 * -100) / 10;
    cVar8 = (char)iVar6;
    iVar1 = iVar1 - (iVar11 * 100 + (short)iVar6 * 10);
    sVar9 = (short)iVar1;
    if (CONCAT44(iVar4,iVar7) != lVar12) {
      cVar5 = (char)iVar1;
      if (((*(char *)(DAT_007ce6ec + 0xa4) == param_4) &&
          (*(short *)(DAT_007ce6ec + 0xa2) == param_5)) && (param_6 == '\x01')) {
        FUN_0044a240(afStack_8[0] - 40.0f,afStack_8[1],0,3.0f,param_1,cVar10 + '(');
        FUN_0044a240(afStack_8[0] - 20.0f,afStack_8[1],0,3.0f,param_1,cVar8 + '(');
        FUN_0044a240(afStack_8[0],afStack_8[1],0,3.0f,param_1,cVar5 + '(');
      }
      else {
        FUN_0044a330(afStack_8[0] - 40.0f,afStack_8[1],0,3.0f,param_1,cVar10 + '\v');
        FUN_0044a330(afStack_8[0] - 20.0f,afStack_8[1],0,3.0f,param_1,cVar8 + '\v');
        FUN_0044a330(afStack_8[0],afStack_8[1],0,3.0f,param_1,cVar5 + '\v');
      }
    }
  }
  if (CONCAT44(iVar4,iVar7) != lVar12) {
    if (((*(char *)(DAT_007ce6ec + 0xa4) == param_4) &&
        (*(short *)(DAT_007ce6ec + 0xa2) == param_5)) && (param_6 == '\x01')) {
      uVar3 = FUN_001158b0(0,*(u32 *)(iVar2 + 4),0x32);
      iVar2 = (int)uVar3;
      *(u8 *)(iVar2 + 0x18) = 0;
      if (param_5 < 10) {
        *(float *)(iVar2 + 0x10) = afStack_8[0] + 4.0f;
      }
      else if (param_5 < 100) {
        *(float *)(iVar2 + 0x10) = afStack_8[0] + 14.0f;
      }
      else {
        *(float *)(iVar2 + 0x10) = afStack_8[0] + 24.0f;
      }
      *(float *)(iVar2 + 0x14) = afStack_8[1];
      *(float *)(iVar2 + 0x2c) = 3.0f;
      FUN_001127d0(uVar3,1);
      FUN_00115980(uVar3);
    }
    else {
      uVar3 = FUN_001158b0(0,*(u32 *)(iVar2 + 4),0x1a);
      iVar2 = (int)uVar3;
      *(u8 *)(iVar2 + 0x18) = 0;
      if (param_5 < 10) {
        *(float *)(iVar2 + 0x10) = afStack_8[0] + 4.0f;
      }
      else if (param_5 < 100) {
        *(float *)(iVar2 + 0x10) = afStack_8[0] + 14.0f;
      }
      else {
        *(float *)(iVar2 + 0x10) = afStack_8[0] + 24.0f;
      }
      *(float *)(iVar2 + 0x14) = afStack_8[1];
      *(float *)(iVar2 + 0x2c) = 3.0f;
      FUN_001127d0(uVar3,1);
      FUN_00115980(uVar3);
    }
  }
  else {
    cVar5 = (char)sVar9;
    if (param_5 < 10) {
      FUN_0044a240(afStack_8[0] + 4.0f,afStack_8[1],0,3.0f,param_1,0x19);
      FUN_0044a240(afStack_8[0] - 20.0f,afStack_8[1],0,3.0f,param_1,cVar5 + '\x0f');
    }
    else if (param_5 < 100) {
      FUN_0044a240(afStack_8[0] + 14.0f,afStack_8[1],0,3.0f,param_1,0x19);
      FUN_0044a240(afStack_8[0] - 30.0f,afStack_8[1],0,3.0f,param_1,cVar8 + '\x0f');
      FUN_0044a240(afStack_8[0] - 10.0f,afStack_8[1],0,3.0f,param_1,cVar5 + '\x0f');
    }
    else {
      FUN_0044a240(afStack_8[0] + 24.0f,afStack_8[1],0,3.0f,param_1,0x19);
      FUN_0044a240(afStack_8[0] - 40.0f,afStack_8[1],0,3.0f,param_1,cVar10 + '\x0f');
      FUN_0044a240(afStack_8[0] - 20.0f,afStack_8[1],0,3.0f,param_1,cVar8 + '\x0f');
      FUN_0044a240(afStack_8[0],afStack_8[1],0,3.0f,param_1,cVar5 + '\x0f');
    }
  }
  return;
}

#pragma pop
#pragma push
#pragma opt_loop_invariants on
// FUN_00448CF0 NONMATCHING

void FUN_00448cf0(int param_1,u8 param_2,u64 param_3,char param_4,short param_5,
                 char param_6,int param_7)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar6;
  int iVar7;
  u64 uVar5;
  u8 bVar8;
  int iVar9;
  int iVar10;
  long lVar11;
  char cVar12;
  char cVar13;
  int iVar14;
  float fVar15;
  float fVar16;
  u32 uVar17;
  float afStack_8[2];
  Vec128 auVar18;
  Vec128 auVar19;
  
  iVar4 = *(int *)((int)param_1 + 0x3c);
  cVar12 = '\0';
  cVar13 = '\0';
  bVar8 = *(u8 *)(iVar4 + 0x93e);
  if (param_6 == '\0') {
    bVar8 = 0xff;
  }
  for (iVar10 = 0; iVar10 < 0x100; iVar10 = iVar10 + 1) {
  }
  afStack_8[0] = *(float *)&param_3;
  afStack_8[0] = afStack_8[0] + 127.0f;
  afStack_8[1] = *((float *)&param_3 + 1);
  afStack_8[1] = afStack_8[1] + 10.0f;
  iVar10 = (int)(char)bVar8;
  iVar6 = (int)((long)((u32)bVar8 << 0x38) >> 0x3f);
  iVar2 = (int)(char)param_2;
  iVar7 = (int)((long)((u32)param_2 << 0x38) >> 0x3f);
  auVar18._0_8_ = CONCAT44(iVar6,iVar10);
  auVar19._0_8_ = CONCAT44(iVar7,iVar2);
  if (auVar19._0_8_ == auVar18._0_8_) {
    fVar16 = afStack_8[0] + 15.0f;
    for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {
      uVar17 = 255.0f;
      iVar9 = iVar4 + iVar3 * 2;
      if (*(short *)(iVar9 + 0x958) == 0) {
        if (*(short *)(iVar9 + 0x954) < 0x17) {
          *(short *)(iVar9 + 0x954) = *(short *)(iVar9 + 0x954) + 1;
        }
        uVar17 = FUN_004221a0(0,255.0f,(float)(int)*(short *)(iVar9 + 0x954),23.0f,2);
      }
      else {
        *(short *)(iVar9 + 0x958) = *(short *)(iVar9 + 0x958) + -1;
      }
      iVar9 = iVar4 + iVar3 * 2;
      fVar15 = (float)FUN_004221a0(afStack_8[0],fVar16,(float)(int)*(short *)(iVar9 + 0x954),23.0f,
                                   1);
      FUN_0044a240((float)(1 - iVar3) * 20.0f + (fVar15 - 90.0f) + 0.0f,afStack_8[1],uVar17,3.0f,
                   param_1,9);
      fVar15 = (float)FUN_004221a0(afStack_8[0],afStack_8[0] - 15.0f,(float)(int)*(short *)(iVar9 + 0x954),
                                   23.0f,1);
      FUN_0044a240((float)iVar3 * 20.0f + fVar15 + 61.0f + 0.0f,afStack_8[1],uVar17,3.0f,param_1,0x36
                  );
    }
    if (*(short *)(iVar4 + 0x956) == 0x17) {
      for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {
        iVar9 = iVar4 + iVar3 * 2;
        *(u16 *)(iVar9 + 0x954) = 0;
        *(short *)(iVar9 + 0x958) = ((short)(iVar3 * 2) + (short)iVar3) * 2;
      }
    }
  }
  else if (((*(char *)(iGpffffb9fc + 0xa4) == param_4) &&
           (*(short *)(iGpffffb9fc + 0xa2) == param_5)) && (param_6 == '\x01')) {
    fVar16 = afStack_8[0] + 61.0f;
    for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {
      FUN_0044a240((afStack_8[0] - 90.0f) + (float)iVar3 * 20.0f,afStack_8[1] + 2.0f,0,3.0f,param_1,0x26)
      ;
      FUN_0044a240(fVar16 + (float)iVar3 * 20.0f,afStack_8[1] + 2.0f,0,3.0f,param_1,0x26);
    }
  }
  lVar11 = (long)param_5;
  iVar3 = (int)param_5;
  if (lVar11 < 10) {
    if (auVar19._0_8_ != auVar18._0_8_) {
      cVar1 = (char)param_5;
      if (((*(char *)(iVar4 + 0x49b) == param_4) && (*(char *)(iVar4 + 0x49c) == lVar11)) &&
         (param_6 == '\x01')) {
        FUN_0044a330(afStack_8[0] - 20.0f,afStack_8[1],0,3.0f,param_1,cVar1 + '\v');
        FUN_0044a240(afStack_8[0] - 20.0f,afStack_8[1],(float)param_7,3.0f,param_1,cVar1 + '(');
      }
      else {
        FUN_0044a330(afStack_8[0] - 20.0f,afStack_8[1],0,3.0f,param_1,cVar1 + '\v');
      }
    }
  }
  else if (lVar11 < 100) {
    cVar12 = (char)(iVar3 / 10);
    param_5 = (short)(iVar3 % 10);
    if (auVar19._0_8_ != auVar18._0_8_) {
      cVar1 = (char)(iVar3 % 10);
      if (((*(char *)(iVar4 + 0x49b) == param_4) && (*(char *)(iVar4 + 0x49c) == lVar11)) &&
         (param_6 == '\x01')) {
        FUN_0044a330(afStack_8[0] - 30.0f,afStack_8[1],0,3.0f,param_1,cVar12 + '\v');
        FUN_0044a330(afStack_8[0] - 10.0f,afStack_8[1],0,3.0f,param_1,cVar1 + '\v');
        FUN_0044a240(afStack_8[0] - 30.0f,afStack_8[1],(float)param_7,3.0f,param_1,cVar12 + '(');
        FUN_0044a240(afStack_8[0] - 10.0f,afStack_8[1],(float)param_7,3.0f,param_1,cVar1 + '(');
      }
      else {
        FUN_0044a330(afStack_8[0] - 30.0f,afStack_8[1],0,3.0f,param_1,cVar12 + '\v');
        FUN_0044a330(afStack_8[0] - 10.0f,afStack_8[1],0,3.0f,param_1,cVar1 + '\v');
      }
    }
  }
  else {
    cVar13 = (char)(iVar3 / 100);
    iVar14 = (int)(short)(iVar3 / 100);
    iVar9 = (iVar3 + iVar14 * -100) / 10;
    cVar12 = (char)iVar9;
    iVar3 = iVar3 - (iVar14 * 100 + (short)iVar9 * 10);
    param_5 = (short)iVar3;
    if (auVar19._0_8_ != auVar18._0_8_) {
      cVar1 = (char)iVar3;
      if (((*(char *)(iVar4 + 0x49b) == param_4) && (*(char *)(iVar4 + 0x49c) == lVar11)) &&
         (param_6 == '\x01')) {
        FUN_0044a330(afStack_8[0] - 40.0f,afStack_8[1],0,3.0f,param_1,cVar13 + '\v');
        FUN_0044a330(afStack_8[0] - 20.0f,afStack_8[1],0,3.0f,param_1,cVar12 + '\v');
        FUN_0044a330(afStack_8[0],afStack_8[1],0,3.0f,param_1,cVar1 + '\v');
        FUN_0044a240(afStack_8[0] - 40.0f,afStack_8[1],(float)param_7,3.0f,param_1,cVar13 + '(');
        FUN_0044a240(afStack_8[0] - 20.0f,afStack_8[1],(float)param_7,3.0f,param_1,cVar12 + '(');
        FUN_0044a240(afStack_8[0],afStack_8[1],(float)param_7,3.0f,param_1,cVar1 + '(');
      }
      else {
        FUN_0044a330(afStack_8[0] - 40.0f,afStack_8[1],0,3.0f,param_1,cVar13 + '\v');
        FUN_0044a330(afStack_8[0] - 20.0f,afStack_8[1],0,3.0f,param_1,cVar12 + '\v');
        FUN_0044a330(afStack_8[0],afStack_8[1],0,3.0f,param_1,cVar1 + '\v');
      }
    }
  }
  if (auVar19._0_8_ == auVar18._0_8_) {
    uVar5 = FUN_001158b0(0,*(u32 *)(iVar4 + 4),0x19);
    iVar4 = (int)uVar5;
    *(u8 *)(iVar4 + 0x18) = 0;
    if (lVar11 < 10) {
      *(float *)(iVar4 + 0x10) = afStack_8[0] + 4.0f;
    }
    else if (lVar11 < 100) {
      *(float *)(iVar4 + 0x10) = afStack_8[0] + 14.0f;
    }
    else {
      *(float *)(iVar4 + 0x10) = afStack_8[0] + 24.0f;
    }
    *(float *)(iVar4 + 0x14) = afStack_8[1];
    *(float *)(iVar4 + 0x2c) = 3.0f;
    FUN_001127d0(uVar5,1);
    FUN_00115980(uVar5);
    cVar1 = (char)param_5;
    if (lVar11 < 10) {
      FUN_0044a240(afStack_8[0] + 4.0f,afStack_8[1],0,3.0f,param_1,0x19);
      FUN_0044a240(afStack_8[0] - 20.0f,afStack_8[1],0,3.0f,param_1,cVar1 + '\x0f');
    }
    else if (lVar11 < 100) {
      FUN_0044a240(afStack_8[0] + 14.0f,afStack_8[1],0,3.0f,param_1,0x19);
      FUN_0044a240(afStack_8[0] - 30.0f,afStack_8[1],0,3.0f,param_1,cVar12 + '\x0f');
      FUN_0044a240(afStack_8[0] - 10.0f,afStack_8[1],0,3.0f,param_1,cVar1 + '\x0f');
    }
    else {
      FUN_0044a240(afStack_8[0] + 24.0f,afStack_8[1],0,3.0f,param_1,0x19);
      FUN_0044a240(afStack_8[0] - 40.0f,afStack_8[1],0,3.0f,param_1,cVar13 + '\x0f');
      FUN_0044a240(afStack_8[0] - 20.0f,afStack_8[1],0,3.0f,param_1,cVar12 + '\x0f');
      FUN_0044a240(afStack_8[0],afStack_8[1],0,3.0f,param_1,cVar1 + '\x0f');
    }
  }
  else if (((*(char *)(iVar4 + 0x49b) == param_4) && (*(char *)(iVar4 + 0x49c) == lVar11)) &&
          (param_6 == '\x01')) {
    uVar5 = FUN_001158b0(0,*(u32 *)(iVar4 + 4),0x1a);
    iVar10 = (int)uVar5;
    *(u8 *)(iVar10 + 0x18) = 0;
    if (lVar11 < 10) {
      *(float *)(iVar10 + 0x10) = afStack_8[0] + 4.0f;
    }
    else if (lVar11 < 100) {
      *(float *)(iVar10 + 0x10) = afStack_8[0] + 14.0f;
    }
    else {
      *(float *)(iVar10 + 0x10) = afStack_8[0] + 24.0f;
    }
    *(float *)(iVar10 + 0x14) = afStack_8[1];
    *(float *)(iVar10 + 0x2c) = 3.0f;
    FUN_001127d0(uVar5,1);
    FUN_00115980(uVar5);
    uVar5 = FUN_001158b0(0,*(u32 *)(iVar4 + 4),0x32);
    iVar4 = (int)uVar5;
    *(char *)(iVar4 + 0x18) = (char)param_7;
    if (lVar11 < 10) {
      *(float *)(iVar4 + 0x10) = afStack_8[0] + 4.0f;
    }
    else if (lVar11 < 100) {
      *(float *)(iVar4 + 0x10) = afStack_8[0] + 14.0f;
    }
    else {
      *(float *)(iVar4 + 0x10) = afStack_8[0] + 24.0f;
    }
    *(float *)(iVar4 + 0x14) = afStack_8[1];
    *(float *)(iVar4 + 0x2c) = 3.0f;
    FUN_001127d0(uVar5,1);
    FUN_00115980(uVar5);
  }
  else {
    uVar5 = FUN_001158b0(0,*(u32 *)(iVar4 + 4),0x1a);
    iVar4 = (int)uVar5;
    *(u8 *)(iVar4 + 0x18) = 0;
    if (lVar11 < 10) {
      *(float *)(iVar4 + 0x10) = afStack_8[0] + 4.0f;
    }
    else if (lVar11 < 100) {
      *(float *)(iVar4 + 0x10) = afStack_8[0] + 14.0f;
    }
    else {
      *(float *)(iVar4 + 0x10) = afStack_8[0] + 24.0f;
    }
    *(float *)(iVar4 + 0x14) = afStack_8[1];
    *(float *)(iVar4 + 0x2c) = 3.0f;
    FUN_001127d0(uVar5,1);
    FUN_00115980(uVar5);
  }
  return;
}
#pragma pop

// FUN_00449C90

char FUN_00449c90(u64 param_1,char param_2)
{
  u8 *puVar1;
  char *puVar2;
  int iVar3;
  int iVar2;
  short sVar1;
  short sVar2;
  
  iVar2 = 0;
  puVar1 = (u8 *)iGpffffb9fc + param_2 * 4;
  puVar2 = (char *)DAT_006b4650_bytes;
  for (; iVar2 < 0x1e; iVar2 = iVar2 + 1) {
    iVar3 = iVar2 * 4;
    if (*(char *)(puVar1 + 4) == puVar2[iVar3]) {
      sVar1 = *(short *)(puVar2 + iVar3 + 2);
      sVar2 = *(short *)(puVar1 + 6);
      if (sVar1 == sVar2) {
        return (long)iVar2;
      }
    }
  }
  return (long)-1;
}

// FUN_00449D10

void FUN_00449d10(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  for (iVar3 = 0; iVar3 < 0x38; iVar3 = iVar3 + 1) {
    iVar2 = iVar1 + iVar3 * 6;
    *(u16 *)(iVar2 + 0xec) = 0;
    *(u16 *)(iVar2 + 0xee) = 0;
    *(u16 *)(iVar2 + 0xf0) = 0;
  }
  return;
}

// FUN_00449D60 NONMATCHING

void FUN_00449d60(u64 param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  u8 bVar4;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar3 = *(int *)((int)param_1 + 0x3c);
  bVar4 = 0;
  do {
    if (*(char *)(iVar3 + 0x940) < '\a') {
      if ((long)*(char *)(iVar3 + 0x93e) < (long)(*(char *)(iVar3 + 0x93f) + -1)) {
        *(char *)(iVar3 + 0x93e) = *(char *)(iVar3 + 0x93e) + '\x01';
      }
      else {
        *(u8 *)(iVar3 + 0x93e) = 0;
      }
    }
    else {
      cVar1 = *(char *)(iVar3 + 0x93e);
      cVar2 = *(char *)(iVar3 + 0x93f);
      if ((long)cVar1 < (long)(cVar2 + -2)) {
        *(char *)(iVar3 + 0x93e) = cVar1 + '\x01';
      }
      else if ((long)*(char *)(iVar3 + 0x941) < (long)((int)*(char *)(iVar3 + 0x940) - (int)cVar2))
      {
        *(char *)(iVar3 + 0x941) = *(char *)(iVar3 + 0x941) + '\x01';
      }
      else if ((long)cVar1 < (long)(cVar2 + -1)) {
        *(char *)(iVar3 + 0x93e) = cVar1 + '\x01';
      }
      else {
        *(u8 *)(iVar3 + 0x93e) = 0;
        *(u8 *)(iVar3 + 0x941) = 0;
      }
    }
    FUN_00447f90((float *)(&uStack_8),param_1,*(char *)(iVar3 + 0x93e) + *(char *)(iVar3 + 0x941));
    *(u32 *)(iVar3 + 0x944) = uStack_8;
    *(u32 *)(iVar3 + 0x948) = uStack_4;
    if (*(short *)(iGpffffb9fc + ((int)*(char *)(iVar3 + 0x93e) + (int)*(char *)(iVar3 + 0x941)) * 4
                  + 6) == *(short *)(iGpffffb9fc + 0xa2)) {
      bVar4 = 1;
    }
  } while (!bVar4);
  return;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00449ED0

void FUN_00449ed0(void)

{
  int iVar1;
  int iVar2;
  
  iGpffffb9fc = (*DAT_00960184_abs)(1,200,0x40000);
  for (iVar1 = 0; iVar1 < 0x1e; iVar1 = iVar1 + 1) {
    *(u8 *)(iGpffffb9fc + iVar1 * 4 + 4) = 0;
    *(u16 *)(iGpffffb9fc + iVar1 * 4 + 6) = 0;
  }
  *(u8 *)(iGpffffb9fc + 0xa0) = 0;
  *(u16 *)(iGpffffb9fc + 0xa2) = 1;
  *(u8 *)(iGpffffb9fc + 0xa4) = 1;
  *(u8 *)(iGpffffb9fc + 0xa5) = 0;
  *(u8 *)(iGpffffb9fc + 0xac) = 0;
  *(u8 *)(iGpffffb9fc + 0xad) = 1;
  iVar1 = 2;
  for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
    *(u8 *)(iGpffffb9fc + iVar2 + 0xa6) = (u8)iVar1;
  }
  return;
}
#pragma pop

// FUN_00449FA0

void FUN_00449fa0(void)

{
  if (iGpffffb9fc_ptr != 0) {
    DAT_0096017c_task[0]((u32)iGpffffb9fc_ptr);
    iGpffffb9fc_ptr = 0;
  }
  return;
}

// FUN_00449FE0 NONMATCHING

u32
FUN_00449fe0(float param_1,float param_2,float param_3,float param_4,int param_5,short param_6)

{
  int iVar3;
  u32 uVar4;
  u32 uVar5;
  float fStack_8;
  float fStack_4;
  
  iVar3 = *(int *)(param_5 + 0x3c);
  uVar5 = 0;
  fStack_8 = param_2;
  fStack_4 = param_4;
  if (param_6 != 0) {
    FUN_004222d0_typed((float*)(&fStack_8),(char)(0),(int)((short)(int)param_1),(int)((short)(int)param_2),(int)((short)(int)param_3),(int)((short)(int)param_4),(int)(*(u16 *)(iVar3 + 0xee)),(short)(param_6));
    if (*(short *)(iVar3 + 0xee) < param_6) {
      *(short *)(iVar3 + 0xee) = *(short *)(iVar3 + 0xee) + 1;
      uVar5 = 1;
    }
  }
  uVar4 = FUN_001158b0(0,*(u32 *)(iVar3 + 4),0);
  iVar3 = (int)uVar4;
  *(u8 *)(iVar3 + 0x18) = 0;
  *(float *)(iVar3 + 0x10) = fStack_8;
  *(float *)(iVar3 + 0x14) = fStack_4;
  *(float *)(iVar3 + 0x2c) = 3.0f;
  FUN_001127d0(uVar4,1);
  FUN_00115980(uVar4);
  return uVar5;
}

// FUN_0044A110 NONMATCHING

u32
FUN_0044a110(float param_1,float param_2,float param_3,float param_4,int param_5,short param_6)

{
  int iVar3;
  u32 uVar4;
  u32 uVar5;
  float fStack_8;
  float fStack_4;
  
  iVar3 = *(int *)(param_5 + 0x3c);
  uVar5 = 0;
  fStack_8 = param_2;
  fStack_4 = param_4;
  if (param_6 != 0) {
    FUN_004222d0_typed((float*)(&fStack_8),(char)(0),(int)((short)(int)param_1),(int)((short)(int)param_2),(int)((short)(int)param_3),(int)((short)(int)param_4),(int)(*(u16 *)(iVar3 + 0xf4)),(short)(param_6));
    if (*(short *)(iVar3 + 0xf4) < param_6) {
      *(short *)(iVar3 + 0xf4) = *(short *)(iVar3 + 0xf4) + 1;
      uVar5 = 1;
    }
  }
  uVar4 = FUN_001158b0(0,*(u32 *)(iVar3 + 4),1);
  iVar3 = (int)uVar4;
  *(u8 *)(iVar3 + 0x18) = 0;
  *(float *)(iVar3 + 0x10) = fStack_8;
  *(float *)(iVar3 + 0x14) = fStack_4;
  *(float *)(iVar3 + 0x2c) = 3.0f;
  FUN_001127d0(uVar4,1);
  FUN_00115980(uVar4);
  return uVar5;
}

// FUN_0044A240 NONMATCHING

void FUN_0044a240(float param_1,float param_2,float param_3,float param_4,int param_5
                 ,char param_6)

{
  u8 uVar3;
  u32 uVar4;
  u32 uVar2;
  int iVar1;
  
  uVar2 = FUN_001158b0(0,*(u32 *)(*(int *)(param_5 + 0x3c) + 4),param_6);
  *(float *)(uVar2 + 0x2c) = param_4;
  if (2.1474836e+09f > param_3) {
    uVar3 = (u8)(int)param_3;
  }
  else {
    uVar4 = 0x80000000;
    uVar3 = (u8)(uVar4 | (int)(param_3 - 2.1474836e+09f));
  }
  *(u8 *)(uVar2 + 0x18) = uVar3;
  *(float *)(uVar2 + 0x10) = param_1;
  *(float *)(uVar2 + 0x14) = param_2;
  FUN_001127d0(uVar2,1);
  FUN_00115980(uVar2);
  return;
}

// FUN_0044A330 NONMATCHING

void FUN_0044a330(float param_1,float param_2,float param_3,float param_4,int param_5
                 ,char param_6)

{
  u8 uVar3;
  u32 uVar4;
  u32 uVar2;
  int iVar1;
  
  uVar2 = FUN_001158b0(0,*(u32 *)(*(int *)(param_5 + 0x3c) + 0xe8),param_6);
  iVar1 = (int)uVar2;
  *(float *)(iVar1 + 0x2c) = param_4;
  if (2.1474836e+09f > param_3) {
    uVar3 = (u8)(int)param_3;
  }
  else {
    uVar4 = 0x80000000;
    uVar3 = (u8)(uVar4 | (int)(param_3 - 2.1474836e+09f));
  }
  *(u8 *)(iVar1 + 0x18) = uVar3;
  *(float *)(iVar1 + 0x10) = param_1;
  *(float *)(iVar1 + 0x14) = param_2;
  FUN_001127d0(uVar2,1);
  FUN_00115980(uVar2);
  return;
}

// FUN_0044A420 NONMATCHING

u8 FUN_0044a420(int param_1,int param_2,int param_3)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  u8 bVar7;
  int iVar8;
  float fVar9;
  u32 uVar10;
  
  iVar3 = *(int *)(param_1 + 0x3c);
  bVar7 = 0;
  iVar8 = (int)param_2;
  iVar6 = iVar8 * 6;
  fVar9 = (float)FUN_00421fe0(0,0,0xff,*(u16 *)(iVar6 + iGpffffb9fc + 0x7c),param_3);
  if (fVar9 < 2.1474836e+09f) {
    uVar10 = (u32)fVar9;
  }
  else {
    uVar10 = (int)(fVar9 - 2.1474836e+09f) | 0x80000000;
  }
  cVar1 = *(char *)(iGpffffb9fc + 0xa6 + iVar8);
  if (cVar1 == '\0') {
    iVar4 = iVar8 * 8 + iVar3;
    FUN_001140d0(4.0f,*(float *)(iVar4 + 0x2cc) - 128.0f,*(float *)(iVar4 + 0x2d0) - 64.0f,
                 uVar10 | 0xffffff00,0x100,0x80,*(u32 *)(iVar8 * 4 + iVar3 + 0x274));
    psVar5 = (short *)(iGpffffb9fc + 0x7c + iVar6);
    sVar2 = *psVar5;
    if (sVar2 < (short)param_3) {
      *psVar5 = sVar2 + 1;
      bVar7 = 1;
    }
  }
  else if ((cVar1 == '\x01') && (param_2 != 0)) {
    psVar5 = (short *)(iGpffffb9fc + 0x7c + iVar6);
    sVar2 = *psVar5;
    bVar7 = sVar2 < (short)param_3;
    if (bVar7) {
      *psVar5 = sVar2 + 1;
    }
    iVar6 = iVar8 * 8 + iVar3;
    FUN_001140d0(4.0f,*(float *)(iVar6 + 0x2cc) - 128.0f,*(float *)(iVar6 + 0x2c8) - 64.0f,
                 uVar10 | 0xffffff00,0x100,0x80,*(u32 *)(iVar8 * 4 + iVar3 + 0x3c4));
  }
  return bVar7;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_0044A630 NONMATCHING

void FUN_0044a630(int param_1)

{
  int iVar1;
  long lVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  for (lVar2 = 0; lVar2 < *(char *)(iVar1 + 0x93f); lVar2 = (long)((int)lVar2 + 1)) {
    iVar3 = iVar1 + (int)lVar2 * 4;
    *(u8 *)(*(int *)(iVar3 + 0x4a8) + 0x18) = 0xff;
    *(u8 *)(*(int *)(iVar3 + 0x4c0) + 0x18) = 0xff;
    *(u8 *)(*(int *)(iVar3 + 0x4f0) + 0x18) = 0xff;
    *(u8 *)(*(int *)(iVar3 + 0x4d8) + 0x18) = 0xff;
  }
  *(u8 *)(*(int *)(DAT_006b46d0 * 4 + iVar1 + 8) + 0x18) = 0xff;
  *(u8 *)(*(int *)(DAT_006b4784 * 4 + iVar1 + 8) + 0x18) = 0xff;
  *(u8 *)(*(int *)(DAT_006b477e * 4 + iVar1 + 8) + 0x18) = 0xff;
  *(u8 *)(*(int *)(DAT_006b478a * 4 + iVar1 + 8) + 0x18) = 0xff;
  *(u8 *)(*(int *)(iVar1 + 0x868) + 0x18) = 0xff;
  *(u8 *)(*(int *)(iVar1 + 0x86c) + 0x18) = 0xff;
  for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
    *(u8 *)(*(int *)(iVar1 + iVar3 * 4 + 0x33c) + 0x18) = 0xff;
  }
  for (iVar3 = 0; iVar3 < 0x38; iVar3 = iVar3 + 1) {
    if (((u8 *)DAT_006b46d0)[iVar3 * 6] != -1) {
      *(u8 *)(*(int *)(iVar1 + iVar3 * 4 + 8) + 0x18) = 0xff;
    }
  }
  return;
}

#pragma pop
// FUN_0044A790 NONMATCHING

void FUN_0044a790(u32 *param_1)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  float fVar4;
  f32 fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  iVar3 = param_1[3];
  iVar1 = FUN_00198590_typed();
  fVar10 = 1.0f / *(float *)(iVar1 + 0x80);
  fVar9 = (float)*(int *)(iVar3 + 0x480) / 180.0f;
  pfVar2 = (float *)(param_1[4] * 0x40 + *(int *)*param_1);
  fVar4 = *(float *)(param_1 + 1);
  fVar8 = *(float *)(param_1 + 2) * 448.0f;
  fVar6 = fVar4 * 640.0f - 320.0f;
  fVar7 = SQRT(fVar6 * fVar6 + (fVar8 - 224.0f) * (fVar8 - 224.0f));
  fVar5 = FUN_0052ea18_f32(fVar8 - 224.0f, fVar6);
  fVar6 = (float)FUN_0052e878_typed(fGpffff8248 * (fVar7 / 200.0f - fVar9) * 2.0f);
  fVar9 = fVar6 * 20.0f + fVar7 + 0.0f;
  fVar6 = FUN_00269c80_f32(fVar5);
  fVar7 = fVar9 * fVar6 + 320.0f;
  fVar6 = FUN_00269ca0_f32(fVar5);
  *pfVar2 = fVar4 * 640.0f;
  pfVar2[1] = fVar8;
  pfVar2[4] = fVar7 / 640.0f;
  pfVar2[5] = (fVar9 * fVar6 + 224.0f) / 448.0f;
  pfVar2[8] = 255.0f;
  pfVar2[9] = 255.0f;
  pfVar2[10] = 255.0f;
  pfVar2[0xb] = 255.0f;
  pfVar2[2] = DAT_00960088 - 100.0f;
  pfVar2[6] = fVar10;
  return;
}

// FUN_0044A990 NONMATCHING

void FUN_0044a990(int param_1,u32 *param_2)

{
  int iVar1;
  code *pcStack_8;
  int iStack_4;
  
  iVar1 = *(int *)(param_1 + 0x480) + 1;
  *(int *)(param_1 + 0x480) = iVar1;
  *(int *)(param_1 + 0x480) = iVar1 % 0xb4;
  iStack_4 = param_1;
  (*DAT_00960090)(6,1);
  (*DAT_00960090)(7,2);
  (*DAT_00960090)(8,1);
  (*DAT_00960090)(9,2);
  (*DAT_00960090)(0xc,1);
  (*DAT_00960090)(0xb,6);
  (*DAT_00960090)(10,5);
  (*DAT_00960090)(2,4);
  FUN_004d7f60_typed(2,0x44);
  FUN_004d7f60_typed(3,0x717fb);
  (*DAT_00960090)(1,*param_2);
  FUN_002699d0_typed(*(u32 *)(param_1 + 0x47c));
  pcStack_8 = (code *)&FUN_0044a790;
  FUN_00269a10_typed(*(u32 *)(param_1 + 0x47c),&pcStack_8);
  return;
}

// FUN_0044AAF0 NONMATCHING

u64 FUN_0044aaf0(int param_1)

{
  char cVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  u8 bVar5;
  
  iVar2 = *(int *)((int)param_1 + 0x3c);
  bVar5 = 0;
  iVar4 = *(char *)(iVar2 + 1) * 0x1c0;
  if ((*(int *)((u8 *)DAT_0086ede8 + iVar4) != 0) && (*(int *)((u8 *)DAT_0086edf4 + iVar4) != 0)) {
    bVar5 = 1;
  }
  if (!bVar5) {
    *(u8 *)(iVar2 + 2) = 6;
  }
  if (*(char *)(iVar2 + 0x40) != '\x01') {
    lVar3 = FUN_001a0250();
    if ((lVar3 == 1) || (lVar3 = FUN_001a02c0(), lVar3 == 1)) {
      iVar4 = *(char *)(iVar2 + 1) * 0x1c0;
      if ((*(int *)((u8 *)DAT_0086ef2c + iVar4) == 4) ||
         (lVar3 = FUN_001c7160(2400.0f,(u8 *)DAT_0086eda0 + iVar4,(u8 *)DAT_008717a0), lVar3 != 0)) {
        cVar1 = *(char *)(iVar2 + 2);
        if (cVar1 != '\x06') {
          if (cVar1 == '\x05') {
            FUN_0044dfc0(param_1);
          }
          else if (cVar1 == '\x04') {
            FUN_0044af60(param_1);
          }
          else if (cVar1 == '\x03') {
            FUN_0044beb0(param_1);
            ((u8 *)DAT_0095c210)[*(char *)(iVar2 + 1)] = 1;
          }
        }
      }
      else {
        FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
      }
    }
    else {
      FUN_00454110(param_1);
    }
  }
  return 0;
}

// FUN_0044ACF0

void FUN_0044acf0(int param_1)

{
  DAT_0096017c_abs[0](*(u32 *)(param_1 + 0x3c));
  return;
}

// FUN_0044AD20 NONMATCHING




u64 FUN_0044ad20(u64 param_1,char param_2)

{
  u32 uVar1;
  long lVar2;
  u64 uVar3;
  int *piVar4;
  int iVar5;
  u8 *puVar6;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  lVar2 = (*DAT_00960184)(1,0x1098,0x40000);
  if (lVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00194b80_u32(param_1,10,DAT_006b4a18,(u32 (*)(int))FUN_0044aaf0,FUN_0044acf0,lVar2);
    puVar6 = (u8 *)lVar2;
    *puVar6 = 0;
    puVar6[2] = 4;
    iVar5 = param_2 * 0x1c0;
    piVar4 = (int *)((u8 *)DAT_0086ef2c + iVar5);
    if (*piVar4 == 4) {
      puVar6[2] = 3;
      uVar1 = (u32)FUN_001aaa20_typed((void *)(uVar3),(u32)((u8 *)DAT_0086eda0 + iVar5));
      *(u32 *)(puVar6 + 0x10) = uVar1;
    }
    puVar6[3] = 0;
    puVar6[4] = 0;
    puVar6[5] = 0;
    puVar6[1] = param_2;
    puVar6[0x40] = 0;
    if (((u8 *)DAT_0086ef3a)[iVar5] != '\0') {
      puVar6[0x18] = ((u8 *)DAT_0086ef38)[param_2 * 0x1c0];
      puVar6[0x8c] = (u8)((u8 *)DAT_0086ef39)[param_2 * 0x1c0] >> 4;
      puVar6[0x8b] = ((u8 *)DAT_0086ef39)[param_2 * 0x1c0] & 0xf;
      puVar6[2] = ((u8 *)DAT_0086ef3a)[iVar5];
      if (*piVar4 == 3) {
        if (puVar6[2] == '\x03') {
          puVar6[3] = 0x11;
        }
      }
      else if (puVar6[2] == '\x03') {
        puVar6[7] = 0;
        puVar6[3] = 1;
      }
    }
    if (((u8 *)DAT_0086ef3c)[iVar5] == '\x01') {
      puVar6[0x40] = 1;
    }
    if (*piVar4 == 4) {
      FUN_00452f70(&uStack_10,uVar3);
      *(u32 *)(puVar6 + 0x28) = uStack_10;
      *(u32 *)(puVar6 + 0x2c) = uStack_c;
      *(u32 *)(puVar6 + 0x30) = uStack_8;
    }
  }
  return uVar3;
}

// FUN_0044AF60 NONMATCHING






void FUN_0044af60(u64 param_1)

{
  int iVar1;
  char cVar2;
  u8 uVar3;
  u8 uVar4;
  u8 uVar5;
  u8 uVar6;
  u16 uVar7;
  u16 uVar8;
  int iVar9;
  long lVar10;
  int iVar11;
  int iVar12;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u8 auStack_20 [16];
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  iVar1 = *(int *)((int)param_1 + 0x3c);
  iVar11 = *(char *)(iVar1 + 1) * 0x1c0;
  iVar12 = iGpffffb5a0 + *(int *)((u8 *)DAT_0086ef2c + iVar11) * 0x40;
  switch(*(u8 *)(iVar1 + 4)) {
  case 0:
    uVar3 = FUN_001ad910(*(u32 *)(*(int *)((u8 *)DAT_0086edf4 + iVar11) + 0x1e0));
    *(u8 *)(iVar1 + 0x5c) = uVar3;
    uVar3 = FUN_001ad920(*(u32 *)
                          (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    *(u8 *)(iVar1 + 0x5d) = uVar3;
    FUN_001ad940(&uStack_10,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    *(u32 *)(iVar1 + 0x50) = uStack_10;
    *(u32 *)(iVar1 + 0x54) = uStack_c;
    *(u32 *)(iVar1 + 0x58) = uStack_8;
    *(u32 *)(iVar1 + 0x60) = *(u32 *)(iVar1 + 0x50);
    *(u32 *)(iVar1 + 100) = *(u32 *)(iVar1 + 0x54);
    *(u32 *)(iVar1 + 0x68) = *(u32 *)(iVar1 + 0x58);
    *(u32 *)(iVar1 + 0x6c) = *(u32 *)(iVar1 + 0x60);
    *(u32 *)(iVar1 + 0x70) = *(u32 *)(iVar1 + 100);
    *(u32 *)(iVar1 + 0x74) = *(u32 *)(iVar1 + 0x68);
    ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 0;
    *(u8 *)(iVar1 + 4) = 1;
  case 1:
    uVar3 = FUN_0044e560(param_1);
    *(u8 *)(iVar1 + 0x8a) = uVar3;
    FUN_0044fab0(param_1);
    break;
  case 2:
    switch(*(u8 *)(iVar1 + 0x8a)) {
    case 0:
      *(u32 *)(iVar1 + 0x6c) = *(u32 *)(iVar1 + 0x60);
      *(float *)(iVar1 + 0x74) = *(float *)(iVar1 + 0x68) - (float)*(u16 *)(iVar1 + 0x92);
      break;
    case 1:
      *(u32 *)(iVar1 + 0x74) = *(u32 *)(iVar1 + 0x68);
      *(float *)(iVar1 + 0x6c) = *(float *)(iVar1 + 0x60) - (float)*(u16 *)(iVar1 + 0x92);
      break;
    case 2:
      *(u32 *)(iVar1 + 0x6c) = *(u32 *)(iVar1 + 0x60);
      *(float *)(iVar1 + 0x74) = *(float *)(iVar1 + 0x68) + (float)*(u16 *)(iVar1 + 0x92);
      break;
    case 3:
      *(u32 *)(iVar1 + 0x74) = *(u32 *)(iVar1 + 0x68);
      *(float *)(iVar1 + 0x6c) = *(float *)(iVar1 + 0x60) + (float)*(u16 *)(iVar1 + 0x92);
      break;
    case 4:
      *(float *)(iVar1 + 0x6c) = *(float *)(iVar1 + 0x60) + (float)(*(u16 *)(iVar1 + 0x92) >> 1);
      *(float *)(iVar1 + 0x74) = *(float *)(iVar1 + 0x68) - (float)(*(u16 *)(iVar1 + 0x92) >> 1);
      break;
    case 5:
      *(float *)(iVar1 + 0x6c) = *(float *)(iVar1 + 0x60) + (float)(*(u16 *)(iVar1 + 0x92) >> 1);
      *(float *)(iVar1 + 0x74) = *(float *)(iVar1 + 0x68) + (float)(*(u16 *)(iVar1 + 0x92) >> 1);
      break;
    case 6:
      *(float *)(iVar1 + 0x6c) = *(float *)(iVar1 + 0x60) - (float)(*(u16 *)(iVar1 + 0x92) >> 1);
      *(float *)(iVar1 + 0x74) = *(float *)(iVar1 + 0x68) - (float)(*(u16 *)(iVar1 + 0x92) >> 1);
      break;
    case 7:
      *(float *)(iVar1 + 0x6c) = *(float *)(iVar1 + 0x60) - (float)(*(u16 *)(iVar1 + 0x92) >> 1);
      *(float *)(iVar1 + 0x74) = *(float *)(iVar1 + 0x68) + (float)(*(u16 *)(iVar1 + 0x92) >> 1);
    }
    *(u8 *)(iVar1 + 4) = 3;
    FUN_0044fab0(param_1);
    break;
  case 3:
    cVar2 = FUN_0044fab0(param_1);
    if (cVar2 == '\x01') {
      return;
    }
    FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0),
                 *(u32 *)(iVar12 + 0x20));
    lVar10 = FUN_001afa20_typed((*(u32 *)(iVar12 + 8)),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0)),(void*)(iVar1 + 0x6c));
    if (lVar10 == 0) {
      return;
    }
    *(u32 *)(iVar1 + 0x60) = *(u32 *)(iVar1 + 0x6c);
    *(u32 *)(iVar1 + 100) = *(u32 *)(iVar1 + 0x70);
    *(u32 *)(iVar1 + 0x68) = *(u32 *)(iVar1 + 0x74);
    *(u8 *)(iVar1 + 4) = 4;
  case 4:
    cVar2 = FUN_0044fab0(param_1);
    if (cVar2 != '\x01') {
      iVar11 = *(int *)(iVar12 + 0x18);
      iVar9 = FUN_00488f30();
      lVar10 = FUN_001aff70_typed((void *)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0)),iVar11 + (short)(iVar9 % (*(int *)(iVar12 + 0x1c) - iVar11)));
      if (lVar10 != 0) {
        *(u8 *)(iVar1 + 4) = 1;
      }
    }
    break;
  case 5:
    uVar3 = FUN_001ad910(*(u32 *)(*(int *)((u8 *)DAT_0086edf4 + iVar11) + 0x1e0));
    uVar4 = FUN_001ad920(*(u32 *)
                          (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(auStack_20,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    uVar5 = FUN_0044f120(*(RwV3d *)(*(int *)((u8 *)DAT_0086ef08 + *(char *)(iVar1 + 1) * 0x1c0) + 0x100));
    uVar6 = FUN_0044f170(*(RwV3d *)(*(int *)((u8 *)DAT_0086ef08 + iVar11) + 0x100));
    lVar10 = FUN_00453ed0(*(u8 *)(iVar1 + 1),uVar3,uVar4,(u32 *)auStack_20,uVar5,uVar6);
    if (lVar10 == 1) {
      *(u8 *)(iVar1 + 4) = 6;
    }
    ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 2;
    break;
  case 6:
    if (*(int *)(iVar1 + 0x94) == 0) {
      *(u8 *)(iVar1 + 4) = 8;
    }
    else {
      iVar11 = *(int *)(iVar1 + 0x94) + -1;
      *(int *)(iVar1 + 0x94) = iVar11;
      *(float *)(iVar1 + 0x6c) = (float)(int)*(short *)(iVar9 * 4 + iVar1 + 0xc98) * 800.0;
      *(float *)(iVar1 + 0x74) =
           (float)(int)*(short *)(*(int *)(iVar1 + 0x94) * 4 + iVar1 + 0xc9a) * 800.0f;
      uVar7 = FUN_0044f120(*(RwV3d *)(iVar1 + 0x6c));
      uVar8 = FUN_0044f170(*(RwV3d *)(iVar1 + 0x6c));
      FUN_001bf220(&uStack_30,uVar7,uVar8);
      *(u32 *)(iVar1 + 0x6c) = uStack_30;
      *(u32 *)(iVar1 + 0x70) = uStack_2c;
      *(u32 *)(iVar1 + 0x74) = uStack_28;
      *(u8 *)(iVar1 + 4) = 7;
    }
    break;
  case 7:
    FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10 + iVar11),0);
    lVar10 = FUN_001afa20_typed((*(u32 *)(iVar12 + 0xc)),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0)),(void*)(iVar1 + 0x6c));
    if (lVar10 != 0) {
      *(u32 *)(iVar1 + 0x60) = *(u32 *)(iVar1 + 0x6c);
      *(u32 *)(iVar1 + 100) = *(u32 *)(iVar1 + 0x70);
      *(u32 *)(iVar1 + 0x68) = *(u32 *)(iVar1 + 0x74);
      *(u32 *)(iVar1 + 0x50) = *(u32 *)(iVar1 + 0x6c);
      *(u32 *)(iVar1 + 0x54) = *(u32 *)(iVar1 + 0x70);
      *(u32 *)(iVar1 + 0x58) = *(u32 *)(iVar1 + 0x74);
      *(u8 *)(iVar1 + 4) = 6;
    }
    break;
  case 8:
    lVar10 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + iVar11));
    if (lVar10 == 0) {
      FUN_004543c0(*(u8 *)(iVar1 + 1),4);
      ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 0;
    }
  }
  return;
}

// FUN_0044B7D0 NONMATCHING

void FUN_0044b7d0(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  long lVar6;
  int iVar7;
  short sVar8;
  u8 bVar9;
  u8 auStack_30 [16];
  u8 auStack_20 [16];
  float afStack_10 [2];
  float fStack_8;
  
  iVar2 = iGpffffb5a0;
  iVar1 = *(int *)(param_1 + 0x3c);
  switch(*(u8 *)(iVar1 + 4)) {
  case 0:
    ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 0;
    *(u8 *)(iVar1 + 4) = 1;
  case 1:
    cVar3 = FUN_0044ffb0(param_1);
    if (cVar3 == '\x01') {
      FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0),0);
      FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
      *(char *)(iVar1 + 7) = (char)*(u32 *)(iVar2 + 100);
      *(u8 *)(iVar1 + 4) = 9;
    }
    else {
      iVar7 = FUN_00488f30();
      bVar9 = (u8)((iVar7 % 200) / 0x19);
      iVar7 = FUN_00488f30();
      sVar8 = (short)((iVar7 % 4000) / 10);
      FUN_001ad940(afStack_10,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
      if (bVar9 < 8) {
        iVar7 = (int)sVar8;
        switch(bVar9) {
        case 0:
          fStack_8 = fStack_8 - (float)iVar7;
          break;
        case 1:
          afStack_10[0] = afStack_10[0] - (float)iVar7;
          break;
        case 2:
          fStack_8 = fStack_8 + (float)iVar7;
          break;
        case 3:
          afStack_10[0] = afStack_10[0] + (float)iVar7;
          break;
        case 4:
          iVar7 = (int)sVar8;
          if (sVar8 < 0) {
            iVar7 = iVar7 + 1;
          }
          fStack_8 = fStack_8 - (float)(iVar7 >> 1);
          afStack_10[0] = afStack_10[0] + (float)(iVar7 >> 1);
          break;
        case 5:
          iVar7 = (int)sVar8;
          if (sVar8 < 0) {
            iVar7 = iVar7 + 1;
          }
          fStack_8 = fStack_8 + (float)(iVar7 >> 1);
          afStack_10[0] = afStack_10[0] + (float)(iVar7 >> 1);
          break;
        case 6:
          iVar7 = (int)sVar8;
          if (sVar8 < 0) {
            iVar7 = iVar7 + 1;
          }
          fStack_8 = fStack_8 - (float)(iVar7 >> 1);
          afStack_10[0] = afStack_10[0] - (float)(iVar7 >> 1);
          break;
        case 7:
          iVar7 = (int)sVar8;
          if (sVar8 < 0) {
            iVar7 = iVar7 + 1;
          }
          fStack_8 = fStack_8 + (float)(iVar7 >> 1);
          afStack_10[0] = afStack_10[0] - (float)(iVar7 >> 1);
        }
      }
      FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0),
                   *(u32 *)(iVar2 + 0x60));
      lVar5 = FUN_001afa20_typed((*(u32 *)(iVar2 + 0x48)),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0)),(void*)(afStack_10))
      ;
      if (lVar5 != 0) {
        iVar7 = *(int *)(iVar2 + 0x58);
        iVar4 = FUN_00488f30();
        FUN_001aff70_typed((void *)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0)),iVar7 + (short)(iVar4 % (*(int *)(iVar2 + 0x5c) - iVar7)));
        *(u8 *)(iVar1 + 4) = 2;
      }
    }
    break;
  case 2:
    cVar3 = FUN_0044ffb0(param_1);
    if (cVar3 == '\x01') {
      FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0),0);
      FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
      *(char *)(iVar1 + 7) = (char)*(u32 *)(iVar2 + 100);
      *(u8 *)(iVar1 + 4) = 9;
    }
    else {
      lVar5 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
      if (lVar5 == 0) {
        *(u8 *)(iVar1 + 4) = 1;
      }
    }
    break;
  case 5:
    FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0),0);
    iVar7 = *(char *)(iVar1 + 1) * 0x1c0;
    lVar5 = FUN_001afa20_typed((*(u32 *)(iVar2 + 0x48)),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + iVar7)),(void*)(*(int *)((u8 *)DAT_0086ef08 + iVar7) + 0x100));
    if (lVar5 == 0) {
      return;
    }
    *(u8 *)(iVar1 + 4) = 6;
  case 6:
    lVar5 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
    if (lVar5 == 0) {
      *(u8 *)(iVar1 + 4) = 5;
      lVar5 = FUN_0044f120(*(RwV3d *)(*(int *)((u8 *)DAT_0086ef08 + *(char *)(iVar1 + 1) * 0x1c0) + 0x100));
      FUN_001ad940(auStack_20,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
      lVar6 = FUN_0044f120(*(RwV3d *)(auStack_20));
      if (lVar5 == lVar6) {
        lVar5 = FUN_0044f170(*(RwV3d *)(*(int *)((u8 *)DAT_0086ef08 + *(char *)(iVar1 + 1) * 0x1c0) + 0x100));
        FUN_001ad940(auStack_30,
                     *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0)
                    );
        lVar6 = FUN_0044f170(*(RwV3d *)(auStack_30));
        if (lVar5 == lVar6) {
          FUN_004543c0(*(u8 *)(iVar1 + 1),4);
          ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 0;
        }
      }
    }
    break;
  case 9:
    if (*(char *)(iVar1 + 7) < '\x01') {
      FUN_004543c0(*(u8 *)(iVar1 + 1),3);
    }
    else {
      *(char *)(iVar1 + 7) = *(char *)(iVar1 + 7) + -1;
    }
  }
  return;
}

// FUN_0044BEB0 NONMATCHING

void FUN_0044beb0(int param_1)
{
  char cVar1;
  char cVar2;
  int iVar3;
  u8 uVar4;
  u8 uVar5;
  u8 uVar6;
  u8 uVar7;
  u16 uVar8;
  u16 uVar9;
  short sVar10;
  short sVar11;
  int iVar12;
  u32 uVar13;
  int uVar14;
  int lVar15;
  int lVar16;
  u8 bVar17;
  int iVar18;
  int iVar19;
  u8 auStack_150 [16];
  u8 auStack_140 [16];
  u8 auStack_130 [16];
  u8 auStack_120 [16];
  u8 auStack_110 [16];
  u8 auStack_100 [16];
  u8 auStack_f0 [16];
  u8 auStack_e0 [16];
  u32 uStack_d0[3];
  u8 auStack_c0 [16];
  u8 auStack_b0 [16];
  u8 auStack_a0 [16];
  u32 uStack_90[4];
  u32 uStack_80[4];
  u32 uStack_70[3];
  u8 auStack_60 [16];
  u8 auStack_50 [16];
  u8 auStack_40 [16];
  u32 uStack_30[3];
  float fStack_20[3];
  float fStack_10[3];
  
  iVar3 = *(int *)((int)param_1 + 0x3c);
  cVar1 = *(char *)(iVar3 + 1);
  iVar18 = cVar1 * 0x1c0;
  iVar12 = *(int *)((u8 *)DAT_0086ef2c + iVar18);
  iVar19 = iGpffffb5a0 + iVar12 * 0x40;
  cVar2 = *(char *)(iVar3 + 3);
  if (('\x01' < cVar2) && (cVar2 < '\a')) {
    FUN_004501b0(cVar1);
    return;
  }
  if (('\x06' < cVar2) && (cVar2 < '\f')) {
    FUN_00450b30(cVar1);
    return;
  }
  if (cVar2 == '\x19') {
    lVar15 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + iVar18));
    if (lVar15 != 0) {
      return;
    }
    FUN_004543c0(*(u8 *)(iVar3 + 1),4);
    ((u8 *)DAT_0095c210)[*(char *)(iVar3 + 1)] = 0;
    return;
  }
  if (cVar2 == '\x18') {
    FUN_00454f50(cVar1,*(u8 *)(iVar3 + 0x18));
    return;
  }
  if (cVar2 == '\x17') {
    lVar15 = FUN_00195460(*(u32 *)(iVar3 + 0x14));
    if (lVar15 != 0) {
      return;
    }
    *(u8 *)(iVar3 + 3) = 0x13;
    return;
  }
  if (cVar2 != '\x16') {
    if (cVar2 == '\x15') {
      lVar15 = FUN_004523c0(param_1,*(u8 *)(iVar3 + 1));
      if (lVar15 == 1) {
        return;
      }
      FUN_001ad940(auStack_e0,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x1e0));
      FUN_001ad940(auStack_f0,
                   *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0));
      lVar15 = FUN_0044f1c0(*(float *)(iVar19 + 4),(float *)auStack_e0,(float *)auStack_f0);
      if (lVar15 == 1) {
        uVar14 = FUN_00318b60(*(u32 *)
                               (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x128));
        FUN_001ad940(auStack_100,
                     *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0));
        lVar15 = FUN_001c6450(*(u32 *)(iVar19 + 0x10),*(u32 *)(iVar19 + 0x14),uVar14,
                              auStack_100);
        if (lVar15 == 1) {
          FUN_004543c0(*(u8 *)(iVar3 + 1),5);
          ((u8 *)DAT_0095c210)[*(char *)(iVar3 + 1)] = 1;
          FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0));
          FUN_001aaac0_typed((void*)(*(u32 *)(iVar3 + 0x10)),1);
          return;
        }
      }
      lVar15 = FUN_001ad910(*(u32 *)
                             (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x1e0));
      lVar16 = FUN_001ad910(*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0)
                           );
      if (lVar15 == lVar16) {
        lVar15 = FUN_001ad920(*(u32 *)
                               (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x1e0));
        lVar16 = FUN_001ad920(*(u32 *)
                               (((u8 *)DAT_008717f4)[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0));
        if (lVar15 == lVar16) {
          FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0));
          FUN_001ad940(auStack_110,
                       *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0));
          FUN_001afa20_typed((*(u32 *)(iVar19 + 0xc)),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0)),(void*)(auStack_110));
          FUN_001b0240(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0),0);
          *(u8 *)(iVar3 + 3) = 0x16;
          return;
        }
      }
      FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0),0);
      lVar15 = FUN_001afa20_typed((*(u32 *)(iVar19 + 0xc)),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0)),(void*)(iVar3 + 0x6c));
      if (lVar15 == 0) {
        return;
      }
      *(u32 *)(iVar3 + 0x60) = *(u32 *)(iVar3 + 0x6c);
      *(u32 *)(iVar3 + 100) = *(u32 *)(iVar3 + 0x70);
      *(u32 *)(iVar3 + 0x68) = *(u32 *)(iVar3 + 0x74);
      *(u32 *)(iVar3 + 0x50) = *(u32 *)(iVar3 + 0x6c);
      *(u32 *)(iVar3 + 0x54) = *(u32 *)(iVar3 + 0x70);
      *(u32 *)(iVar3 + 0x58) = *(u32 *)(iVar3 + 0x74);
      *(u8 *)(iVar3 + 3) = 0x14;
      return;
    }
    if (cVar2 == '\x14') {
      lVar15 = FUN_004523c0(param_1,*(u8 *)(iVar3 + 1));
      if (lVar15 == 1) {
        return;
      }
      if (*(int *)(iVar3 + 0x94) != 0) {
        iVar12 = *(int *)(iVar3 + 0x94) + -1;
        *(int *)(iVar3 + 0x94) = iVar12;
        *(float *)(iVar3 + 0x6c) = (float)(int)*(short *)(iVar12 * 4 + iVar3 + 0xc98) * 800.0f;
        *(float *)(iVar3 + 0x74) =
             (float)(int)*(short *)(*(int *)(iVar3 + 0x94) * 4 + iVar3 + 0xc9a) * 800.0f;
        uVar8 = FUN_0044f120(*(RwV3d *)(iVar3 + 0x6c));
        uVar9 = FUN_0044f170(*(RwV3d *)(iVar3 + 0x6c));
        FUN_001bf220(uStack_d0,uVar8,uVar9);
        *(u32 *)(iVar3 + 0x6c) = uStack_d0[0];
        *(u32 *)(iVar3 + 0x70) = uStack_d0[1];
        *(u32 *)(iVar3 + 0x74) = uStack_d0[2];
        *(u8 *)(iVar3 + 3) = 0x15;
        return;
      }
      *(u8 *)(iVar3 + 3) = 0x16;
      return;
    }
    if (cVar2 != '\x13') {
      if (cVar2 != '\x12') {
        if (cVar2 == '\x11') {
          FUN_00451d70(param_1);
          return;
        }
        if (cVar2 == '\x10') {
          return;
        }
        if (cVar2 == '\x0f') {
          lVar15 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + iVar18));
          if (lVar15 != 0) {
            return;
          }
          *(u8 *)(iVar3 + 3) = 0x10;
          bVar17 = 0;
          iVar12 = *(char *)(iVar3 + 1) * 0x1c0;
          if ((*(int *)((u8 *)DAT_0086ede8 + iVar12) != 0) && (*(int *)((u8 *)DAT_0086edf4 + iVar12) != 0)) {
            bVar17 = 1;
          }
          if (bVar17) {
            ((u8 *)DAT_0086ef38)[iVar12] = 0;
            ((u8 *)DAT_0086ef39)[*(char *)(iVar3 + 1) * 0x1c0] = 0;
            ((u8 *)DAT_0086ef3a)[*(char *)(iVar3 + 1) * 0x1c0] = 0;
            ((u8 *)DAT_0086ef3b)[*(char *)(iVar3 + 1) * 0x1c0] = 0;
          }
          FUN_004542c0(*(u8 *)(iVar3 + 1));
          return;
        }
        if (cVar2 == '\x0e') {
          FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10 + iVar18),0);
          lVar15 = FUN_001afa20_typed((*(u32 *)(iVar19 + 0xc)),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0)),(void*)(iVar3 + 0x6c));
          if (lVar15 == 0) {
            return;
          }
          *(u32 *)(iVar3 + 0x60) = *(u32 *)(iVar3 + 0x6c);
          *(u32 *)(iVar3 + 100) = *(u32 *)(iVar3 + 0x70);
          *(u32 *)(iVar3 + 0x68) = *(u32 *)(iVar3 + 0x74);
          *(u32 *)(iVar3 + 0x50) = *(u32 *)(iVar3 + 0x6c);
          *(u32 *)(iVar3 + 0x54) = *(u32 *)(iVar3 + 0x70);
          *(u32 *)(iVar3 + 0x58) = *(u32 *)(iVar3 + 0x74);
          *(u8 *)(iVar3 + 3) = 0xd;
          return;
        }
        if (cVar2 == '\r') {
          if (*(int *)(iVar3 + 0x94) != 0) {
            iVar12 = *(int *)(iVar3 + 0x94) + -1;
            *(int *)(iVar3 + 0x94) = iVar12;
            *(float *)(iVar3 + 0x6c) = (float)(int)*(short *)(iVar12 * 4 + iVar3 + 0xc98) * 800.0f;
            *(float *)(iVar3 + 0x74) =
                 (float)(int)*(short *)(*(int *)(iVar3 + 0x94) * 4 + iVar3 + 0xc9a) * 800.0f;
            uVar8 = FUN_0044f120(*(RwV3d *)(iVar3 + 0x6c));
            uVar9 = FUN_0044f170(*(RwV3d *)(iVar3 + 0x6c));
            FUN_001bf220(uStack_70,uVar8,uVar9);
            *(u32 *)(iVar3 + 0x6c) = uStack_70[0];
            *(u32 *)(iVar3 + 0x70) = uStack_70[1];
            *(u32 *)(iVar3 + 0x74) = uStack_70[2];
            *(u8 *)(iVar3 + 3) = 0xe;
            return;
          }
          *(u8 *)(iVar3 + 3) = 0xf;
          return;
        }
        if (cVar2 == '\f') {
          *(u8 *)(iVar3 + 0x48) = uGpffffb9cc;
          FUN_001b0240(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0),0);
          lVar15 = FUN_004514a0(*(u8 *)(iVar3 + 1));
          if (lVar15 == 0) {
            FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0));
            FUN_001ad940(auStack_40,
                         *(u32 *)
                          (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x1e0));
            uVar8 = FUN_0044f120(*(RwV3d *)(auStack_40));
            FUN_001ad940(auStack_50,
                         *(u32 *)
                          (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x1e0));
            uVar9 = FUN_0044f170(*(RwV3d *)(auStack_50));
            FUN_001bf220(uStack_30,uVar8,uVar9);
            *(u32 *)(iVar3 + 0x6c) = uStack_30[0];
            *(u32 *)(iVar3 + 0x70) = uStack_30[1];
            *(u32 *)(iVar3 + 0x74) = uStack_30[2];
            *(u8 *)(iVar3 + 3) = 0xf;
            return;
          }
          uVar4 = FUN_001ad910(*(u32 *)
                                (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x1e0));
          uVar5 = FUN_001ad920(*(u32 *)
                                (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x1e0));
          FUN_001ad940(auStack_60,
                       *(u32 *)
                        (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x1e0));
          lVar15 = FUN_00453ed0(*(u8 *)(iVar3 + 1),uVar4,uVar5,(u32 *)auStack_60,
                                *(u8 *)(iVar3 + 0x8b),*(u8 *)(iVar3 + 0x8c));
          if (lVar15 == 1) {
            *(u8 *)(iVar3 + 3) = 0xd;
            return;
          }
          *(u8 *)(iVar3 + 3) = 0xf;
          return;
        }
        if (cVar2 != '\x01') {
          if (cVar2 != '\0') {
            return;
          }
          FUN_001ad940(fStack_20,*(u32 *)(*(int *)((u8 *)DAT_0086edf4 + iVar18) + 0x1e0));
          fStack_10[0] = fStack_20[0];
          fStack_10[1] = fStack_20[1] + 100.0f;
          fStack_10[2] = fStack_20[2];
          iVar12 = FUN_001b9120_u32();
          uVar14 = FUN_001a91b0_ret(*(u32 *)(iVar12 + 0x1208),fStack_10);
          iVar12 = FUN_001b9120_u32();
          FUN_001a9390_typed((void *)(*(u32 *)(iVar12 + 0x1208)),uVar14,3);
          lVar15 = FUN_001c7130(2400.0f,(u32)((u8 *)DAT_0086eda0 + *(char *)(iVar3 + 1) * 0x1c0));
          if (lVar15 == 1) {
            FUN_0010a4e0(1,8,3,4);
          }
          *(char *)(iVar3 + 7) = (char)*(u32 *)(iVar19 + 0x24);
          FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0),0);
          FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0));
          FUN_001b0240(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0),0);
          *(u8 *)(iVar3 + 3) = 1;
          return;
        }
        if ('\0' < *(char *)(iVar3 + 7)) {
          *(char *)(iVar3 + 7) = *(char *)(iVar3 + 7) + -1;
          return;
        }
        if (iVar12 != 5) {
          if (iVar12 == 4) {
            *(u8 *)(iVar3 + 3) = 0x12;
            return;
          }
          if (iVar12 == 3) {
            *(u8 *)(iVar3 + 3) = 0xc;
            return;
          }
          if (iVar12 == 2) {
            lVar15 = FUN_001c65e0_typed((void*)((u8 *)DAT_0086eda0 + iVar18));
            if (lVar15 == 1) {
              *(u8 *)(iVar3 + 3) = 7;
              return;
            }
            *(u8 *)(iVar3 + 3) = 0x18;
            return;
          }
          if (iVar12 != 1) {
            return;
          }
          lVar15 = FUN_001c65e0_typed((void*)((u8 *)DAT_0086eda0 + iVar18));
          if (lVar15 == 1) {
            *(u8 *)(iVar3 + 3) = 2;
            return;
          }
          *(u8 *)(iVar3 + 3) = 0x18;
          return;
        }
        lVar15 = FUN_001c65e0_typed((void*)((u8 *)DAT_0086eda0 + iVar18));
        if (lVar15 == 1) {
          *(u8 *)(iVar3 + 3) = 2;
          return;
        }
        *(u8 *)(iVar3 + 3) = 0x18;
        return;
      }
      for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {
        bVar17 = 0;
        if ((((u8 *)DAT_008717e8)[iVar12 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar12 * 0x70] != 0)) {
          bVar17 = 1;
        }
        if (bVar17) {
          sVar10 = FUN_0043c910((char)iVar12);
          if (sVar10 != 0) {
            *(char *)(iVar3 + 0x18) = (char)iVar12;
          }
        }
      }
      FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0));
      FUN_001ad940(uStack_80,
                   *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0));
      *(u32 *)(iVar3 + 0x1c) = uStack_80[0];
      *(u32 *)(iVar3 + 0x20) = uStack_80[1];
      *(u32 *)(iVar3 + 0x24) = uStack_80[2];
      *(u8 *)(iVar3 + 3) = 0x13;
    }
    lVar15 = FUN_004523c0(param_1,*(u8 *)(iVar3 + 1));
    if (lVar15 == 1) {
      return;
    }
    sVar10 = FUN_001ad910(*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0));
    sVar11 = FUN_001ad920(*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0));
    iVar12 = FUN_001b9120_u32();
    if (*(char *)(iVar12 + sVar11 * 0x100 + sVar10 * 0x10 + 0x4a) == '\b') {
      FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0));
      FUN_001ad940(uStack_90,
                   *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0));
      *(u32 *)(iVar3 + 0x1c) = uStack_90[0];
      *(u32 *)(iVar3 + 0x20) = uStack_90[1];
      *(u32 *)(iVar3 + 0x24) = uStack_90[2];
      uVar4 = FUN_001ad910(*(u32 *)
                            (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x1e0));
      uVar5 = FUN_001ad920(*(u32 *)
                            (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x1e0));
      FUN_001ad940(auStack_a0,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x1e0));
      uVar6 = FUN_0044f120(*(RwV3d *)(iVar3 + 0x28));
      uVar7 = FUN_0044f170(*(RwV3d *)(iVar3 + 0x28));
      lVar15 = FUN_00453ed0(*(u8 *)(iVar3 + 1),uVar4,uVar5,(u32 *)auStack_a0,uVar6,uVar7);
      if (lVar15 == 1) {
        FUN_001b0240(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0),0);
        *(u8 *)(iVar3 + 3) = 0x14;
        return;
      }
      *(u8 *)(iVar3 + 3) = 0x12;
      return;
    }
    uVar4 = FUN_001ad910(*(u32 *)
                          (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x1e0));
    uVar5 = FUN_001ad920(*(u32 *)
                          (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(auStack_b0,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x1e0));
    lVar15 = FUN_00453ed0(*(u8 *)(iVar3 + 1),uVar4,uVar5,(u32 *)auStack_b0,(char)sVar10,
                          (char)sVar11);
    if (lVar15 == 1) {
      FUN_001b0240(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0),0);
      *(u8 *)(iVar3 + 3) = 0x14;
      return;
    }
    FUN_001ad940(auStack_c0,*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0)
                );
    lVar15 = FUN_001afa20_typed((*(u32 *)(iVar19 + 0xc)),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0)),(void*)(auStack_c0));
    if (lVar15 != 1) {
      return;
    }
    *(u8 *)(iVar3 + 3) = 0x16;
    return;
  }
  lVar15 = FUN_004523c0(param_1,*(u8 *)(iVar3 + 1));
  if (lVar15 == 1) {
    return;
  }
  FUN_001ad940(auStack_120,
               *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x1e0));
  FUN_001ad940(auStack_130,*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0))
  ;
  lVar15 = FUN_0044f1c0(*(float *)(iVar19 + 4),(float *)auStack_120,(float *)auStack_130);
  if (lVar15 == 1) {
    uVar14 = FUN_00318b60(*(u32 *)
                           (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x128));
    FUN_001ad940(auStack_140,
                 *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0));
    lVar15 = FUN_001c6450(*(u32 *)(iVar19 + 0x10),*(u32 *)(iVar19 + 0x14),uVar14,
                          auStack_140);
    if (lVar15 == 1) {
      FUN_004543c0(*(u8 *)(iVar3 + 1),5);
      ((u8 *)DAT_0095c210)[*(char *)(iVar3 + 1)] = 1;
      FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0));
      FUN_001aaac0_typed((void*)(*(u32 *)(iVar3 + 0x10)),1);
      return;
    }
  }
  else {
    lVar15 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0));
    if (lVar15 == 0) {
      lVar15 = FUN_001ad910(*(u32 *)
                             (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x1e0));
      lVar16 = FUN_001ad910(*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0)
                           );
      if (lVar15 == lVar16) {
        lVar15 = FUN_001ad920(*(u32 *)
                               (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar3 + 1) * 0x1c0) + 0x1e0));
        lVar16 = FUN_001ad920(*(u32 *)
                               (((u8 *)DAT_008717f4)[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0));
        if (lVar15 == lVar16) {
          FUN_001b0240(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0),0);
          FUN_001ad940(auStack_150,
                       *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0));
          lVar15 = FUN_001afa20_typed((*(u32 *)(iVar19 + 0xc)),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0)),(void*)(auStack_150));
          if (lVar15 == 0) {
            return;
          }
          goto LAB_0044d510;
        }
      }
      iVar12 = FUN_001ad920(*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0)
                           );
      iVar18 = FUN_001b9120_u32();
      iVar19 = FUN_001ad910(*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0)
                           );
      if (*(char *)(iVar18 + iVar12 * 0x100 + iVar19 * 0x10 + 0x4a) == '\b') {
        FUN_001b0020_typed((u32)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0)),(void*)(iVar3 + 0x34),(s32)(5));
        if (*(int *)(iVar3 + 0x14) != 0) {
          *(u32 *)(iVar3 + 0x14) = 0;
        }
        uVar13 = FUN_00459f60(param_1,5,0);
        *(u32 *)(iVar3 + 0x14) = uVar13;
        *(u8 *)(iVar3 + 3) = 0x17;
        return;
      }
    }
  }
LAB_0044d510:
  lVar15 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0));
  if (lVar15 == 0) {
    *(u8 *)(iVar3 + 3) = 0x13;
  }
  return;
}

// FUN_0044D600 NONMATCHING

void FUN_0044d600(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  u64 uVar5;
  long lVar6;
  u32 uVar7;
  u32 uStack_120;
  u32 uStack_11c;
  u32 uStack_118;
  u32 uStack_114;
  u32 uStack_110;
  u32 uStack_10c;
  u8 auStack_100 [16];
  u8 auStack_f0 [16];
  u8 auStack_e0 [16];
  u8 auStack_d0 [16];
  u8 auStack_c0 [16];
  u8 auStack_b0 [16];
  u8 auStack_a0 [16];
  u8 auStack_90 [16];
  u8 auStack_80 [16];
  u32 uStack_70;
  float fStack_6c;
  u32 uStack_68;
  u8 auStack_60 [16];
  u8 auStack_50 [16];
  u8 auStack_40 [16];
  u32 uStack_30;
  float fStack_2c;
  u32 uStack_28;
  u32 uStack_20;
  float fStack_1c;
  u32 uStack_18;
  u32 uStack_10;
  float fStack_c;
  u32 uStack_8;
  
  iVar2 = DAT_007ce290;
  iVar1 = *(int *)(param_1 + 0x3c);
  cVar3 = *(char *)(iVar1 + 3);
  if (cVar3 == '\x19') {
    lVar6 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
    if (lVar6 == 0) {
      FUN_004543c0(*(u8 *)(iVar1 + 1),4);
      ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 0;
    }
  }
  else if (cVar3 == '\x18') {
    FUN_00454f50(*(u8 *)(iVar1 + 1),*(u8 *)(iVar1 + 0x18));
  }
  else if ((cVar3 != '\b') && (cVar3 != '\a')) {
    if (cVar3 == '\x05') {
      FUN_001ad940(auStack_e0,*(u32 *)(DAT_008717f4 + 0x1e0));
      lVar6 = FUN_00454520((float *)auStack_e0,*(u8 *)(iVar1 + 1));
      if (lVar6 == 1) {
        FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
        *(u8 *)(iVar1 + 3) = 2;
      }
      else {
        uVar5 = FUN_00318b60(*(u32 *)
                              (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x128));
        FUN_001ad940(auStack_f0,*(u32 *)(DAT_008717f4 + 0x1e0));
        lVar6 = FUN_001c6450(*(u32 *)(iVar2 + 0x50),*(u32 *)(iVar2 + 0x44),uVar5,
                             auStack_f0);
        if (lVar6 == 1) {
          FUN_004543c0(*(u8 *)(iVar1 + 1),5);
        }
        else {
          lVar6 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
          if (lVar6 == 0) {
            FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
            FUN_001ad940(auStack_100,*(u32 *)(DAT_008717f4 + 0x1e0));
            FUN_001b0020_typed((u32)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0)),(void*)(auStack_100),(s32)(5));
            *(u8 *)(iVar1 + 3) = 4;
          }
        }
      }
    }
    else if (cVar3 == '\x04') {
      FUN_001ad940(auStack_90,*(u32 *)(DAT_008717f4 + 0x1e0));
      lVar6 = FUN_00454400((u32*)(auStack_90),(char)(*(u8 *)(iVar1 + 1)));
      if (lVar6 == 0) {
        FUN_004543c0(*(u8 *)(iVar1 + 1),4);
        ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 0;
      }
      else {
        FUN_001ad940(auStack_a0,
                     *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0)
                    );
        FUN_001ad940(auStack_b0,*(u32 *)(DAT_008717f4 + 0x1e0));
        lVar6 = FUN_0044f1c0(*(float *)(iVar2 + 0x54) * 3.0f,(float *)auStack_a0,(float *)auStack_b0);
        if (lVar6 == 0) {
          FUN_004543c0(*(u8 *)(iVar1 + 1),4);
          ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 0;
        }
        else {
          FUN_001ad940(auStack_c0,*(u32 *)(DAT_008717f4 + 0x1e0));
          lVar6 = FUN_00454520((float *)auStack_c0,*(u8 *)(iVar1 + 1));
          if (lVar6 == 1) {
            FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
            *(u8 *)(iVar1 + 3) = 2;
          }
          else {
            uVar5 = FUN_00318b60(*(u32 *)
                                  (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x128));
            FUN_001ad940(auStack_d0,*(u32 *)(DAT_008717f4 + 0x1e0));
            lVar6 = FUN_001c6450(*(u32 *)(iVar2 + 0x50),*(u32 *)(iVar2 + 0x44),uVar5,
                                 auStack_d0);
            if (lVar6 == 1) {
              FUN_004543c0(*(u8 *)(iVar1 + 1),5);
            }
            else {
              lVar6 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
              if (lVar6 == 0) {
                FUN_00454620(*(u8 *)(iVar1 + 1));
                *(u8 *)(iVar1 + 3) = 5;
              }
            }
          }
        }
      }
    }
    else if (cVar3 == '\x03') {
      cVar3 = FUN_0044f300(*(u8 *)(iVar1 + 1));
      if (cVar3 != '\x01') {
        uVar5 = FUN_00318b60(*(u32 *)
                              (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x128));
        FUN_001ad940(auStack_80,*(u32 *)(DAT_008717f4 + 0x1e0));
        lVar6 = FUN_001c6450(*(u32 *)(iVar2 + 0x50),*(u32 *)(iVar2 + 0x44),uVar5,
                             auStack_80);
        if (lVar6 == 1) {
          FUN_004543c0(*(u8 *)(iVar1 + 1),5);
        }
        else {
          lVar6 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
          if (lVar6 == 0) {
            *(u8 *)(iVar1 + 3) = 2;
          }
          if (*(char *)(iVar1 + 8) < '\x01') {
            *(u8 *)(iVar1 + 3) = 2;
          }
          else {
            *(char *)(iVar1 + 8) = *(char *)(iVar1 + 8) + -1;
          }
        }
      }
    }
    else if (cVar3 == '\x02') {
      FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
      FUN_001ad940(auStack_40,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
      FUN_001ad940(auStack_50,*(u32 *)(DAT_008717f4 + 0x1e0));
      uVar7 = FUN_0044f270_ret((float *)(auStack_40),(float *)(auStack_50));
      *(u32 *)(iVar1 + 0x44) = uVar7;
      FUN_001ad940(auStack_60,*(u32 *)(DAT_008717f4 + 0x1e0));
      lVar6 = FUN_00454520((float *)auStack_60,*(u8 *)(iVar1 + 1));
      if (lVar6 == 0) {
        *(u8 *)(iVar1 + 3) = 4;
      }
      else {
        FUN_001ad940(&uStack_70,*(u32 *)(DAT_008717f4 + 0x1e0));
        uStack_20 = uStack_70;
        fStack_1c = fStack_6c;
        uStack_18 = uStack_68;
        uStack_114 = uStack_70;
        uStack_10c = uStack_68;
        uStack_120 = uStack_70;
        uStack_118 = uStack_68;
        *(float *)&uStack_11c = 400.0f;
        uStack_110 = 0xc3c80000;
        FUN_001acc30_typed((void*)(&uStack_120),(void*)(&uStack_20));
        if (fStack_1c <= 50.0f) {
          FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0),0);
          lVar6 = FUN_001afa20_typed((*(u32 *)(iVar2 + 0x4c)),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0)),(void*)(&uStack_20));
          if (lVar6 != 0) {
            *(char *)(iVar1 + 8) = (char)*(u32 *)(iVar2 + 0x68);
            *(u8 *)(iVar1 + 3) = 3;
          }
        }
        else {
          FUN_004543c0(*(u8 *)(iVar1 + 1),4);
          ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 0;
        }
      }
    }
    else if (cVar3 == '\x01') {
      if (*(char *)(iVar1 + 7) < '\x01') {
        *(u8 *)(iVar1 + 3) = 2;
      }
      else {
        *(char *)(iVar1 + 7) = *(char *)(iVar1 + 7) + -1;
      }
    }
    else if (cVar3 == '\0') {
      FUN_001ad940(&uStack_30,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
      uStack_10 = uStack_30;
      uStack_8 = uStack_28;
      fStack_c = fStack_2c + 100.0f;
      iVar4 = FUN_001b9120_u32();
      uVar5 = FUN_001a91b0_ret(*(u32 *)(iVar4 + 0x1208),&uStack_10);
      iVar4 = FUN_001b9120_u32();
      FUN_001a9390_typed((void *)(*(u32 *)(iVar4 + 0x1208)),uVar5,3);
      lVar6 = FUN_001c7130(2400.0f,(u32)((u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0));
      if (lVar6 == 1) {
        FUN_0010a4e0(1,8,3,4);
      }
      *(char *)(iVar1 + 7) = (char)*(u32 *)(iVar2 + 100);
      FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0),0);
      FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
      FUN_001b0240(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0),0);
      *(u8 *)(iVar1 + 3) = 1;
    }
  }
  return;
}

// FUN_0044DFC0 NONMATCHING

void FUN_0044dfc0(int param_1)

{
  char cVar1;
  int iVar2;
  u32 uVar3;
  long lVar4;
  u64 uVar5;
  int iVar6;
  u8 bVar7;
  
  iVar2 = *(int *)((int)param_1 + 0x3c);
  cVar1 = *(char *)(iVar2 + 5);
  if (cVar1 == '\x03') {
    lVar4 = FUN_00195460(*(u32 *)(iVar2 + 0xc));
    if (lVar4 == 0) {
      bVar7 = 0;
      iVar6 = *(char *)(iVar2 + 1) * 0x1c0;
      if ((*(int *)((u8 *)DAT_0086ede8 + iVar6) != 0) && (*(int *)((u8 *)DAT_0086edf4 + iVar6) != 0)) {
        bVar7 = 1;
      }
      if (bVar7) {
        FUN_004543c0(*(char *)(iVar2 + 1),4);
        ((u8 *)DAT_0095c210)[*(char *)(iVar2 + 1)] = 0;
        if (*(int *)((u8 *)DAT_0086ef2c + *(char *)(iVar2 + 1) * 0x1c0) == 4) {
          FUN_001aaac0_typed((void*)(*(u32 *)(iVar2 + 0x10)),0);
          FUN_004543c0(*(u8 *)(iVar2 + 1),3);
        }
      }
      else {
        *(u8 *)(iVar2 + 2) = 6;
      }
    }
  }
  else if (cVar1 == '\x02') {
    if (*(int *)(iVar2 + 0xc) != 0) {
      *(u32 *)(iVar2 + 0xc) = 0;
    }
    lVar4 = FUN_001d8d80((int)((u8 *)DAT_008717a0 + *(char *)(iVar2 + 0x18) * 0x1c0));
    *(int *)(iVar2 + 0xc) = (int)lVar4;
    if (lVar4 == 0) {
      FUN_004543c0(*(u8 *)(iVar2 + 1),4);
      ((u8 *)DAT_0095c210)[*(char *)(iVar2 + 1)] = 0;
      if (*(int *)((u8 *)DAT_0086ef2c + *(char *)(iVar2 + 1) * 0x1c0) == 4) {
        FUN_001aaac0_typed((void*)(*(u32 *)(iVar2 + 0x10)),0);
        FUN_004543c0(*(u8 *)(iVar2 + 1),3);
      }
    }
    else {
      *(u8 *)(iVar2 + 5) = 3;
    }
  }
  else if (cVar1 == '\x01') {
    lVar4 = FUN_00195460(*(u32 *)(iVar2 + 0xc));
    if (lVar4 == 0) {
      bVar7 = 0;
      iVar6 = *(char *)(iVar2 + 1) * 0x1c0;
      if ((*(int *)((u8 *)DAT_0086ede8 + iVar6) != 0) && (*(int *)((u8 *)DAT_0086edf4 + iVar6) != 0)) {
        bVar7 = 1;
      }
      if (bVar7) {
        if (*(int *)((u8 *)DAT_0086ef2c + iVar6) == 4) {
          FUN_001aaac0_typed((void*)(*(u32 *)(iVar2 + 0x10)),0);
          FUN_004543c0(*(u8 *)(iVar2 + 1),3);
        }
        else {
          FUN_004543c0(*(u8 *)(iVar2 + 1),4);
          ((u8 *)DAT_0095c210)[*(char *)(iVar2 + 1)] = 0;
        }
      }
      else {
        *(u8 *)(iVar2 + 2) = 6;
      }
    }
  }
  else if (cVar1 == '\0') {
    FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
    FUN_001b0240(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0),0);
    if (*(int *)(iVar2 + 0xc) != 0) {
      *(u32 *)(iVar2 + 0xc) = 0;
    }
    lVar4 = FUN_001c7b10_typed((const void *)((u8 *)DAT_008717a0 + *(char *)(iVar2 + 0x18) * 0x1c0));
    if (lVar4 == 1) {
      lVar4 = FUN_001d8d80((int)((u8 *)DAT_008717a0 + *(char *)(iVar2 + 0x18) * 0x1c0));
      if (lVar4 == 0) {
        DAT_007ce6f4 = (short)*(char *)(iVar2 + 1);
        DAT_007ce6f0 = *(u8 *)(iVar2 + 0x18);
        *(u8 *)(iVar2 + 5) = 1;
        FUN_004532d0(1);
        FUN_00435060(1);
      }
    }
    else {
      lVar4 = FUN_001d8d80((int)((u8 *)DAT_008717a0 + *(char *)(iVar2 + 0x18) * 0x1c0));
      if (lVar4 == 0) {
        lVar4 = FUN_002ff790_typed((void *)(((u8 *)DAT_008717e8)[*(char *)(iVar2 + 0x18) * 0x70]));
        if (lVar4 == 1) {
          FUN_004543c0(*(u8 *)(iVar2 + 1),4);
          ((u8 *)DAT_0095c210)[*(char *)(iVar2 + 1)] = 0;
        }
        else {
          uVar3 = (u32)FUN_001d8b00_typed((void *)(param_1),(void *)((u8 *)DAT_008717a0 + *(char *)(iVar2 + 0x18) * 0x1c0),(void *)((u8 *)DAT_0086eda0 + *(char *)(iVar2 + 1) * 0x1c0));
          *(u32 *)(iVar2 + 0xc) = uVar3;
          *(u8 *)(iVar2 + 5) = 1;
          FUN_0043a1a0(*(u8 *)(iVar2 + 0x18),*(u8 *)(iVar2 + 1));
        }
      }
      else {
        uVar5 = FUN_001d8d80((int)((u8 *)DAT_008717a0 + *(char *)(iVar2 + 0x18) * 0x1c0));
        FUN_001d8e60_typed((void *)(uVar5),(void *)(0),(void *)((u8 *)DAT_0086eda0 + *(char *)(iVar2 + 1) * 0x1c0));
        uVar3 = FUN_001d8d80((int)((u8 *)DAT_008717a0 + *(char *)(iVar2 + 0x18) * 0x1c0));
        *(u32 *)(iVar2 + 0xc) = uVar3;
        *(u8 *)(iVar2 + 5) = 1;
      }
    }
  }
  return;
}

// FUN_0044E530

void FUN_0044e530(int param_1,u8 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x16c) + 0x3c);
  *(u8 *)(iVar1 + 2) = 5;
  *(u8 *)(iVar1 + 5) = 2;
  *(u8 *)(iVar1 + 0x18) = param_2;
  return;
}

// FUN_0044E560 NONMATCHING






u64 FUN_0044e560(int param_1)

{
  int iVar1;
  u8 uVar2;
  int iVar3;
  int iVar4;
  long lVar5;
  u32 *puVar6;
  u64 uVar7;
  u64 uVar8;
  short sVar9;
  float fVar10;
  u16 uVar11;
  float fStack_10;
  u32 uStack_c;
  float fStack_8;
  
  iVar1 = *(int *)((int)param_1 + 0x3c);
  uVar8 = 0;
  uVar7 = 0xffffffffffffffff;
  sVar9 = 0;
  puVar6 = (u32 *)
           (DAT_007ce290 + *(int *)((u8 *)DAT_0086ef2c + *(char *)(iVar1 + 1) * 0x1c0) * 0x40);
  uVar2 = FUN_0044f120(*(RwV3d *)(iVar1 + 0x60));
  *(u8 *)(iVar1 + 0x5c) = uVar2;
  uVar2 = FUN_0044f170(*(RwV3d *)(iVar1 + 0x60));
  *(u8 *)(iVar1 + 0x5d) = uVar2;
  do {
    iVar3 = FUN_00488f30();
    iVar4 = FUN_00488f30();
    fVar10 = (float)(int)(short)((iVar4 % 4000) / 10) + 400.0f;
    if (fVar10 < 2.1474836e+09f) {
      uVar11 = (u16)(int)fVar10;
    }
    else {
      uVar11 = (u16)(int)(fVar10 - 2.1474836e+09f);
    }
    *(u16 *)(iVar1 + 0x92) = uVar11;
    switch((char)((iVar3 % 200) / 0x19)) {
    case '\0':
      fStack_10 = *(float *)(iVar1 + 0x60);
      uStack_c = *(u32 *)(iVar1 + 100);
      fStack_8 = *(float *)(iVar1 + 0x68) - (float)*(u16 *)(iVar1 + 0x92);
      lVar5 = FUN_0044f060(*puVar6,param_1,&fStack_10);
      if (((lVar5 == 1) && (lVar5 = FUN_00454400((u32*)(&fStack_10),(char)(*(u8 *)(iVar1 + 1))), lVar5 == 1)
          ) && (lVar5 = FUN_00454d00(&fStack_10), lVar5 == 1)) {
        uVar2 = FUN_0044f120(*(RwV3d *)(&fStack_10));
        *(u8 *)(iVar1 + 0x78) = uVar2;
        uVar2 = FUN_0044f170(*(RwV3d *)(&fStack_10));
        *(u8 *)(iVar1 + 0x79) = uVar2;
        if (((long)*(char *)(iVar1 + 0x5c) == (u32)*(u8 *)(iVar1 + 0x78)) &&
           ((long)*(char *)(iVar1 + 0x5d) == (u32)*(u8 *)(iVar1 + 0x79))) {
          uVar8 = 1;
          uVar7 = 0;
          *(u8 *)(iVar1 + 4) = 2;
        }
        else {
          iVar3 = FUN_001b9120_u32();
          if ((*(u8 *)(iVar3 + *(char *)(iVar1 + 0x5d) * 0x100 + *(char *)(iVar1 + 0x5c) * 0x10 +
                        0x53) & 1) != 0) {
            uVar8 = 1;
            uVar7 = 0;
            *(u8 *)(iVar1 + 4) = 2;
          }
        }
      }
      break;
    case '\x01':
      uStack_c = *(u32 *)(iVar1 + 100);
      fStack_8 = *(float *)(iVar1 + 0x68);
      fStack_10 = *(float *)(iVar1 + 0x60) - (float)*(u16 *)(iVar1 + 0x92);
      lVar5 = FUN_0044f060(*puVar6,param_1,&fStack_10);
      if (((lVar5 == 1) && (lVar5 = FUN_00454400((u32*)(&fStack_10),(char)(*(u8 *)(iVar1 + 1))), lVar5 == 1)
          ) && (lVar5 = FUN_00454d00(&fStack_10), lVar5 == 1)) {
        uVar2 = FUN_0044f120(*(RwV3d *)(&fStack_10));
        *(u8 *)(iVar1 + 0x78) = uVar2;
        uVar2 = FUN_0044f170(*(RwV3d *)(&fStack_10));
        *(u8 *)(iVar1 + 0x79) = uVar2;
        if (((long)*(char *)(iVar1 + 0x5c) == (u32)*(u8 *)(iVar1 + 0x78)) &&
           ((long)*(char *)(iVar1 + 0x5d) == (u32)*(u8 *)(iVar1 + 0x79))) {
          uVar7 = 1;
          *(u8 *)(iVar1 + 4) = 2;
          uVar8 = uVar7;
        }
        else {
          iVar3 = FUN_001b9120_u32();
          if ((*(u8 *)(iVar3 + *(char *)(iVar1 + 0x5d) * 0x100 + *(char *)(iVar1 + 0x5c) * 0x10 +
                        0x53) & 2) != 0) {
            uVar7 = 1;
            *(u8 *)(iVar1 + 4) = 2;
            uVar8 = uVar7;
          }
        }
      }
      break;
    case '\x02':
      fStack_10 = *(float *)(iVar1 + 0x60);
      uStack_c = *(u32 *)(iVar1 + 100);
      fStack_8 = *(float *)(iVar1 + 0x68) + (float)*(u16 *)(iVar1 + 0x92);
      lVar5 = FUN_0044f060(*puVar6,param_1,&fStack_10);
      if (((lVar5 == 1) && (lVar5 = FUN_00454400((u32*)(&fStack_10),(char)(*(u8 *)(iVar1 + 1))), lVar5 == 1)
          ) && (lVar5 = FUN_00454d00(&fStack_10), lVar5 == 1)) {
        uVar2 = FUN_0044f120(*(RwV3d *)(&fStack_10));
        *(u8 *)(iVar1 + 0x78) = uVar2;
        uVar2 = FUN_0044f170(*(RwV3d *)(&fStack_10));
        *(u8 *)(iVar1 + 0x79) = uVar2;
        if (((long)*(char *)(iVar1 + 0x5c) == (u32)*(u8 *)(iVar1 + 0x78)) &&
           ((long)*(char *)(iVar1 + 0x5d) == (u32)*(u8 *)(iVar1 + 0x79))) {
          uVar7 = 2;
          *(u8 *)(iVar1 + 4) = 2;
          uVar8 = 1;
        }
        else {
          iVar3 = FUN_001b9120_u32();
          if ((*(u8 *)(iVar3 + *(char *)(iVar1 + 0x5d) * 0x100 + *(char *)(iVar1 + 0x5c) * 0x10 +
                        0x53) & 4) != 0) {
            uVar7 = 2;
            *(u8 *)(iVar1 + 4) = 2;
            uVar8 = 1;
          }
        }
      }
      break;
    case '\x03':
      uStack_c = *(u32 *)(iVar1 + 100);
      fStack_8 = *(float *)(iVar1 + 0x68);
      fStack_10 = *(float *)(iVar1 + 0x60) + (float)*(u16 *)(iVar1 + 0x92);
      lVar5 = FUN_0044f060(*puVar6,param_1,&fStack_10);
      if (((lVar5 == 1) && (lVar5 = FUN_00454400((u32*)(&fStack_10),(char)(*(u8 *)(iVar1 + 1))), lVar5 == 1)
          ) && (lVar5 = FUN_00454d00(&fStack_10), lVar5 == 1)) {
        uVar2 = FUN_0044f120(*(RwV3d *)(&fStack_10));
        *(u8 *)(iVar1 + 0x78) = uVar2;
        uVar2 = FUN_0044f170(*(RwV3d *)(&fStack_10));
        *(u8 *)(iVar1 + 0x79) = uVar2;
        if (((long)*(char *)(iVar1 + 0x5c) == (u32)*(u8 *)(iVar1 + 0x78)) &&
           ((long)*(char *)(iVar1 + 0x5d) == (u32)*(u8 *)(iVar1 + 0x79))) {
          uVar7 = 3;
          *(u8 *)(iVar1 + 4) = 2;
          uVar8 = 1;
        }
        else {
          iVar3 = FUN_001b9120_u32();
          if ((*(u8 *)(iVar3 + *(char *)(iVar1 + 0x5d) * 0x100 + *(char *)(iVar1 + 0x5c) * 0x10 +
                        0x53) & 8) != 0) {
            uVar7 = 3;
            *(u8 *)(iVar1 + 4) = 2;
            uVar8 = 1;
          }
        }
      }
      break;
    case '\x04':
      uStack_c = *(u32 *)(iVar1 + 100);
      fStack_8 = (float)(*(u16 *)(iVar1 + 0x92) >> 1);
      fStack_10 = *(float *)(iVar1 + 0x60) + fStack_8;
      fStack_8 = *(float *)(iVar1 + 0x68) - fStack_8;
      lVar5 = FUN_0044f060(*puVar6,param_1,&fStack_10);
      if (((lVar5 == 1) && (lVar5 = FUN_00454400((u32*)(&fStack_10),(char)(*(u8 *)(iVar1 + 1))), lVar5 == 1)
          ) && (lVar5 = FUN_00454d00(&fStack_10), lVar5 == 1)) {
        uVar2 = FUN_0044f120(*(RwV3d *)(&fStack_10));
        *(u8 *)(iVar1 + 0x78) = uVar2;
        uVar2 = FUN_0044f170(*(RwV3d *)(&fStack_10));
        *(u8 *)(iVar1 + 0x79) = uVar2;
        if (((long)*(char *)(iVar1 + 0x5c) == (u32)*(u8 *)(iVar1 + 0x78)) &&
           ((long)*(char *)(iVar1 + 0x5d) == (u32)*(u8 *)(iVar1 + 0x79))) {
          uVar7 = 4;
          *(u8 *)(iVar1 + 4) = 2;
          uVar8 = 1;
        }
      }
      break;
    case '\x05':
      uStack_c = *(u32 *)(iVar1 + 100);
      fStack_8 = (float)(*(u16 *)(iVar1 + 0x92) >> 1);
      fStack_10 = *(float *)(iVar1 + 0x60) + fStack_8;
      fStack_8 = *(float *)(iVar1 + 0x68) + fStack_8;
      lVar5 = FUN_0044f060(*puVar6,param_1,&fStack_10);
      if (((lVar5 == 1) && (lVar5 = FUN_00454400((u32*)(&fStack_10),(char)(*(u8 *)(iVar1 + 1))), lVar5 == 1)
          ) && (lVar5 = FUN_00454d00(&fStack_10), lVar5 == 1)) {
        uVar2 = FUN_0044f120(*(RwV3d *)(&fStack_10));
        *(u8 *)(iVar1 + 0x78) = uVar2;
        uVar2 = FUN_0044f170(*(RwV3d *)(&fStack_10));
        *(u8 *)(iVar1 + 0x79) = uVar2;
        if (((long)*(char *)(iVar1 + 0x5c) == (u32)*(u8 *)(iVar1 + 0x78)) &&
           ((long)*(char *)(iVar1 + 0x5d) == (u32)*(u8 *)(iVar1 + 0x79))) {
          uVar7 = 5;
          *(u8 *)(iVar1 + 4) = 2;
          uVar8 = 1;
        }
      }
      break;
    case '\x06':
      uStack_c = *(u32 *)(iVar1 + 100);
      fStack_8 = (float)(*(u16 *)(iVar1 + 0x92) >> 1);
      fStack_10 = *(float *)(iVar1 + 0x60) - fStack_8;
      fStack_8 = *(float *)(iVar1 + 0x68) - fStack_8;
      lVar5 = FUN_0044f060(*puVar6,param_1,&fStack_10);
      if (((lVar5 == 1) && (lVar5 = FUN_00454400((u32*)(&fStack_10),(char)(*(u8 *)(iVar1 + 1))), lVar5 == 1)
          ) && (lVar5 = FUN_00454d00(&fStack_10), lVar5 == 1)) {
        uVar2 = FUN_0044f120(*(RwV3d *)(&fStack_10));
        *(u8 *)(iVar1 + 0x78) = uVar2;
        uVar2 = FUN_0044f170(*(RwV3d *)(&fStack_10));
        *(u8 *)(iVar1 + 0x79) = uVar2;
        if (((long)*(char *)(iVar1 + 0x5c) == (u32)*(u8 *)(iVar1 + 0x78)) &&
           ((long)*(char *)(iVar1 + 0x5d) == (u32)*(u8 *)(iVar1 + 0x79))) {
          uVar7 = 6;
          *(u8 *)(iVar1 + 4) = 2;
          uVar8 = 1;
        }
      }
      break;
    case '\a':
      uStack_c = *(u32 *)(iVar1 + 100);
      fStack_8 = (float)(*(u16 *)(iVar1 + 0x92) >> 1);
      fStack_10 = *(float *)(iVar1 + 0x60) - fStack_8;
      fStack_8 = *(float *)(iVar1 + 0x68) + fStack_8;
      lVar5 = FUN_0044f060(*puVar6,param_1,&fStack_10);
      if (((lVar5 == 1) && (lVar5 = FUN_00454400((u32*)(&fStack_10),(char)(*(u8 *)(iVar1 + 1))), lVar5 == 1)
          ) && (lVar5 = FUN_00454d00(&fStack_10), lVar5 == 1)) {
        uVar2 = FUN_0044f120(*(RwV3d *)(&fStack_10));
        *(u8 *)(iVar1 + 0x78) = uVar2;
        uVar2 = FUN_0044f170(*(RwV3d *)(&fStack_10));
        *(u8 *)(iVar1 + 0x79) = uVar2;
        if (((long)*(char *)(iVar1 + 0x5c) == (u32)*(u8 *)(iVar1 + 0x78)) &&
           ((long)*(char *)(iVar1 + 0x5d) == (u32)*(u8 *)(iVar1 + 0x79))) {
          uVar7 = 7;
          *(u8 *)(iVar1 + 4) = 2;
          uVar8 = 1;
        }
      }
    }
    if ((char)uVar8 == '\0') {
      sVar9 = sVar9 + 1;
    }
    if (99 < sVar9) {
      sVar9 = 0;
      uVar8 = 1;
      iVar3 = *(int *)((int)param_1 + 0x3c);
      *(u8 *)(iVar3 + 2) = 4;
      *(u8 *)(iVar3 + 4) = 5;
    }
  } while ((char)uVar8 == '\0');
  return uVar7;
}

// FUN_0044F060

u32 FUN_0044f060(float param_1,int param_2,float *param_3)
{
  int iVar1;
  int iVar2;
  int bVar1;
  float fVar2;
  RwV3d input;
  RwV3d delta;
  
  input = *(RwV3d *)param_3;
  iVar2 = *(volatile int *)(param_2 + 0x3c);
  bVar1 = 0;
  iVar1 = *(int *)(DAT_0086ef08_abs + *(char *)(iVar2 + 1) * 0x1c0);
  delta.x = *(float *)(iVar1 + 0x100) - input.x;
  delta.y = *(float *)(iVar1 + 0x104) - input.y;
  delta.z = *(float *)(iVar1 + 0x108) - input.z;
  fVar2 = FUN_004c6ac0_vec(&delta);
  if (fVar2 < param_1) {
    bVar1 = 1;
  }
  return bVar1;
}

// FUN_0044F120

int FUN_0044f120(RwV3d param_1)

{
  return (int)((param_1.x + 400.0f) / 800.0f);
}

// FUN_0044F170

int FUN_0044f170(RwV3d param_1)

{
  return (int)((param_1.z + 400.0f) / 800.0f);
}

// FUN_0044F1C0

u32 FUN_0044f1c0(float param_1,float *param_2,float *param_3)
{
  float fVar1;
  int bVar1;
  RwV3d first;
  RwV3d second;
  RwV3d delta;
  
  
  first = *(RwV3d *)param_2;
  second = *(RwV3d *)param_3;
  bVar1 = 0;
  delta.x = first.x - second.x;
  delta.y = first.y - second.y;
  delta.z = first.z - second.z;
  fVar1 = FUN_004c6ac0_vec(&delta);
  if (fVar1 < param_1) {
    bVar1 = 1;
  }
  return bVar1;
}

// FUN_0044F270

void FUN_0044f270(float *param_1,float *param_2)

{
  RwV3d first;
  RwV3d second;
  RwV3d delta;
  
  first = *(RwV3d *)param_1;
  second = *(RwV3d *)param_2;
  delta.x = first.x - second.x;
  delta.y = first.y - second.y;
  delta.z = first.z - second.z;
  FUN_004c6ac0_vec(&delta);
  return;
}

// FUN_0044F300 NONMATCHING

u32 FUN_0044f300(char param_1)

{
  int iVar1;
  char cVar2;
  long lVar3;
  long lVar4;
  u64 uVar5;
  char cVar6;
  int *piVar7;
  int iVar8;
  u32 uVar9;
  float fVar10;
  float fVar11;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  float fStack_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  u8 auStack_90 [16];
  u8 auStack_80 [16];
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  u8 auStack_50 [16];
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0086ef0c + param_1 * 0x1c0) + 0x3c);
  uVar9 = 0;
  iVar8 = DAT_007ce290 + *(int *)((u8 *)DAT_0086ef2c + *(char *)(iVar1 + 1) * 0x1c0) * 0x40;
  if ((DAT_007ce6bc == '\x01') && (*(int *)((u8 *)DAT_0086ef2c + *(char *)(iVar1 + 1) * 0x1c0) == 2)) {
    uVar9 = 0;
  }
  else {
    FUN_001ad940(&fStack_20,*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar1 + 0x18) * 0x70] + 0x1e0)
                );
    FUN_001ad940(&fStack_10,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    fStack_a0 = fStack_10;
    fStack_9c = fStack_c;
    fStack_98 = fStack_8;
    fStack_b0 = fStack_20;
    fStack_ac = fStack_1c;
    fStack_a8 = fStack_18;
    fStack_c0 = fStack_10 - fStack_20;
    fStack_bc = fStack_c - fStack_1c;
    fStack_b8 = fStack_8 - fStack_18;
    fVar10 = (float)FUN_004c6ac0_vec((const RwV3d*)(&fStack_c0));
    lVar3 = FUN_001c6d70_typed(*(u32 *)(iVar8 + 0x14),(u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0);
    if (lVar3 != 0) {
      lVar3 = FUN_001c6dd0_typed(*(u32 *)(iVar8 + 0x14),(u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0);
      if (*(char *)(iVar1 + 0x18) != lVar3) {
        FUN_001ad940(&fStack_40,
                     *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar1 + 0x18) * 0x70] + 0x1e0));
        FUN_001ad940(&fStack_30,
                     *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0)
                    );
        fStack_d0 = fStack_30;
        fStack_cc = fStack_2c;
        fStack_c8 = fStack_28;
        fStack_e0 = fStack_40;
        fStack_dc = fStack_3c;
        fStack_d8 = fStack_38;
        fStack_f0 = fStack_30 - fStack_40;
        fStack_ec = fStack_2c - fStack_3c;
        fStack_e8 = fStack_28 - fStack_38;
        fVar11 = (float)FUN_004c6ac0_vec((const RwV3d*)(&fStack_f0));
        cVar6 = (char)lVar3;
        if (fVar11 < fVar10) {
          FUN_001ad940(auStack_50,
                       *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar1 + 0x18) * 0x70] + 0x1e0));
          lVar4 = FUN_00454400((u32*)(auStack_50),(char)(*(u8 *)(iVar1 + 1)));
          if (lVar4 == 1) {
            lVar4 = FUN_001c65e0_typed((void*)((u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0));
            if (lVar4 == 1) {
              if (cVar6 == '\0') {
                FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                *(u8 *)(iVar1 + 0x18) = 0;
                uVar9 = 1;
                ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
              }
              else {
                cVar2 = FUN_00437e20(cVar6);
                if (cVar2 == '\x01') {
                  FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                  *(char *)(iVar1 + 0x18) = cVar6;
                  uVar9 = 1;
                  ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
                }
              }
            }
            else {
              lVar4 = FUN_0016f190_typed(0xc65);
              if (lVar4 == 0) {
                *(char *)(iVar1 + 0x18) = cVar6;
                uVar9 = 1;
                ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
                FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                *(u8 *)(iVar1 + 3) = 0x18;
              }
            }
          }
        }
        fVar11 = *(float *)(iVar8 + 4);
        piVar7 = (int *)((u8 *)DAT_008717f4 + (int)lVar3 * 0x70);
        FUN_001ad940(&fStack_70,*(u32 *)(*piVar7 + 0x1e0));
        FUN_001ad940(&fStack_60,
                     *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0)
                    );
        fStack_100 = fStack_60;
        fStack_fc = fStack_5c;
        fStack_f8 = fStack_58;
        fStack_110 = fStack_70;
        fStack_10c = fStack_6c;
        fStack_108 = fStack_68;
        fStack_120 = fStack_60 - fStack_70;
        fStack_11c = fStack_5c - fStack_6c;
        fStack_118 = fStack_58 - fStack_68;
        fVar10 = (float)FUN_004c6ac0_vec((const RwV3d*)(&fStack_120));
        if (fVar10 < fVar11) {
          uVar5 = FUN_00318b60(*(u32 *)
                                (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x128));
          FUN_001ad940(auStack_80,*(u32 *)(*piVar7 + 0x1e0));
          lVar3 = FUN_001c6450(*(u32 *)(iVar8 + 0x10),*(u32 *)(iVar8 + 0x14),uVar5,
                               auStack_80);
          if (lVar3 == 1) {
            FUN_001ad940(auStack_90,*(u32 *)(*piVar7 + 0x1e0));
            lVar3 = FUN_00454400((u32*)(auStack_90),(char)(*(u8 *)(iVar1 + 1)));
            if (lVar3 == 1) {
              iVar8 = *(char *)(iVar1 + 1) * 0x1c0;
              if (*(int *)((u8 *)DAT_0086ef2c + iVar8) == 3) {
                if (cVar6 == '\0') {
                  FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                  *(u8 *)(iVar1 + 0x18) = 0;
                  uVar9 = 1;
                  ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
                }
                else {
                  cVar2 = FUN_00437e20(cVar6);
                  if (cVar2 == '\x01') {
                    FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                    *(char *)(iVar1 + 0x18) = cVar6;
                    uVar9 = 1;
                    ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
                  }
                }
              }
              else {
                lVar3 = FUN_001c65e0_typed((void*)((u8 *)DAT_0086eda0 + iVar8));
                if (lVar3 == 1) {
                  if (cVar6 == '\0') {
                    FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                    *(u8 *)(iVar1 + 0x18) = 0;
                    uVar9 = 1;
                    ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
                  }
                  else {
                    cVar2 = FUN_00437e20(cVar6);
                    if (cVar2 == '\x01') {
                      FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                      *(char *)(iVar1 + 0x18) = cVar6;
                      uVar9 = 1;
                      ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
                    }
                  }
                }
                else {
                  lVar3 = FUN_0016f190_typed(0xc65);
                  if (lVar3 == 0) {
                    *(char *)(iVar1 + 0x18) = cVar6;
                    uVar9 = 1;
                    ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
                    FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                    *(u8 *)(iVar1 + 3) = 0x18;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar9;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_0044FAB0 NONMATCHING

u8 FUN_0044fab0(int param_1)

{
  int iVar1;
  u8 uVar2;
  char cVar3;
  long lVar4;
  u64 uVar5;
  u8 uVar6;
  u8 bVar7;
  int iVar8;
  int iVar9;
  u8 auStack_20 [16];
  u8 auStack_10 [16];
  
  iVar1 = *(int *)(param_1 + 0x3c);
  iVar8 = DAT_007ce290 + *(int *)((u8 *)DAT_0086ef2c + *(char *)(iVar1 + 1) * 0x1c0) * 0x40;
  if ((*(char *)(iVar1 + 0x41) != '\x01') &&
     ((DAT_007ce6bc != '\x01' || (*(int *)((u8 *)DAT_0086ef2c + *(char *)(iVar1 + 1) * 0x1c0) != 2)))) {
    for (iVar9 = 0; iVar9 < 4; iVar9 = iVar9 + 1) {
      bVar7 = 0;
      if ((((u8 *)DAT_008717e8)[iVar9 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar9 * 0x70] != 0)) {
        bVar7 = 1;
      }
      if (((bVar7) && (lVar4 = FUN_002ff790_typed((void *)(((u8 *)DAT_008717e8)[iVar9 * 0x70])), lVar4 != 1)) &&
         (lVar4 = ((code)FUN_001c6d70)(*(u32 *)(iVar8 + 0x14),
                               (u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0), lVar4 != 0)) {
        uVar5 = FUN_00318b60(*(u32 *)
                              (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x128));
        FUN_001ad940(auStack_10,*(u32 *)(((u8 *)DAT_008717f4)[iVar9 * 0x70] + 0x1e0));
        lVar4 = FUN_001c6450(*(u32 *)(iVar8 + 0x10),*(u32 *)(iVar8 + 0x14),uVar5,
                             auStack_10);
        if (lVar4 == 1) {
          FUN_001ad940(auStack_20,*(u32 *)(((u8 *)DAT_008717f4)[iVar9 * 0x70] + 0x1e0));
          lVar4 = FUN_00454400((u32*)(auStack_20),(char)(*(u8 *)(iVar1 + 1)));
          if (lVar4 == 1) {
            uVar2 = ((code)FUN_001c6dd0)(*(u32 *)(iVar8 + 0x14),
                                 (u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0);
            uVar6 = (u8)iVar9;
            if (*(int *)((u8 *)DAT_0086ef2c + *(char *)(iVar1 + 1) * 0x1c0) == 3) {
              if ((iVar9 != 0) && (cVar3 = FUN_00437e20(uVar6), cVar3 == '\x01')) {
                FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                *(u8 *)(iVar1 + 0x18) = uVar2;
                ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
                return 1;
              }
              lVar4 = FUN_001c7130(*(u32 *)(iVar8 + 0x14),(u32)((u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0));
              if (lVar4 == 1) {
                FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                *(u8 *)(iVar1 + 0x18) = 0;
                ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
                return 1;
              }
            }
            else {
              lVar4 = FUN_001c65e0_typed((void*)((u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0));
              if (lVar4 == 1) {
                if (iVar9 == 0) {
                  lVar4 = FUN_001c7130(*(u32 *)(iVar8 + 0x14),(u32)((u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0));
                  if (lVar4 == 1) {
                    FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                    *(u8 *)(iVar1 + 0x18) = 0;
                    ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
                    return 1;
                  }
                }
                else {
                  cVar3 = FUN_00437e20(uVar6);
                  if (cVar3 == '\x01') {
                    FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                    *(u8 *)(iVar1 + 0x18) = uVar2;
                    ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
                    return 1;
                  }
                }
              }
              else {
                lVar4 = FUN_0016f190_typed(0xc65);
                if (lVar4 == 0) {
                  if (iVar9 == 0) {
                    lVar4 = FUN_001c7130(*(u32 *)(iVar8 + 0x14),(u32)((u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0));
                    if (lVar4 == 1) {
                      *(u8 *)(iVar1 + 0x18) = 0;
                      ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
                      FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                      *(u8 *)(iVar1 + 3) = 0x18;
                      return 1;
                    }
                  }
                  else {
                    cVar3 = FUN_00437e20(uVar6);
                    if (cVar3 == '\x01') {
                      *(u8 *)(iVar1 + 0x18) = uVar6;
                      ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
                      FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                      *(u8 *)(iVar1 + 3) = 0x18;
                      return 1;
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
  return 0;
}

#pragma pop
// FUN_0044FFB0 NONMATCHING

u32 FUN_0044ffb0(int param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  u64 uVar4;
  u8 bVar5;
  u32 uVar6;
  u8 auStack_10 [16];
  
  iVar2 = DAT_007ce290;
  iVar1 = *(int *)(param_1 + 0x3c);
  uVar6 = 0;
  if (*(char *)(iVar1 + 0x41) == '\x01') {
    uVar6 = 0;
  }
  else {
    bVar5 = 0;
    if ((DAT_008717e8 != 0) && (DAT_008717f4 != 0)) {
      bVar5 = 1;
    }
    if (((bVar5) && (lVar3 = FUN_002ff790_typed((void *)(DAT_008717e8)), lVar3 != 1)) &&
       (lVar3 = ((code)FUN_001c6d70)(*(u32 *)(iVar2 + 0x54),
                             (u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0), lVar3 != 0)) {
      uVar4 = FUN_00318b60(*(u32 *)
                            (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x128));
      FUN_001ad940(auStack_10,*(u32 *)(DAT_008717f4 + 0x1e0));
      lVar3 = FUN_001c6450(*(u32 *)(iVar2 + 0x50),*(u32 *)(iVar2 + 0x54),uVar4,
                           auStack_10);
      if (lVar3 == 1) {
        lVar3 = FUN_001c65e0_typed((void*)((u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0));
        if (lVar3 == 1) {
          FUN_004543c0(*(u8 *)(iVar1 + 1),3);
          *(u8 *)(iVar1 + 0x18) = 0;
          uVar6 = 1;
          ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
        }
        else {
          lVar3 = FUN_0016f190_typed(0xc65);
          if (lVar3 == 0) {
            *(u8 *)(iVar1 + 0x18) = 0;
            uVar6 = 1;
            ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
            FUN_004543c0(*(u8 *)(iVar1 + 1),3);
            *(u8 *)(iVar1 + 3) = 0x18;
          }
        }
      }
    }
  }
  return uVar6;
}

// FUN_004501B0 NONMATCHING

void FUN_004501b0(char param_1)

{
  char cVar1;
  int iVar2;
  char cVar3;
  long lVar4;
  u64 uVar5;
  int iVar6;
  u32 uVar7;
  float fVar8;
  float fVar9;
  u32 uStack_160;
  u32 uStack_15c;
  u32 uStack_158;
  u32 uStack_154;
  u32 uStack_150;
  u32 uStack_14c;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  float fStack_130;
  float fStack_12c;
  float fStack_128;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  u8 auStack_e0 [16];
  u8 auStack_d0 [16];
  u8 auStack_c0 [16];
  u8 auStack_b0 [16];
  u8 auStack_a0 [16];
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  u8 auStack_70 [16];
  u8 auStack_60 [16];
  u32 uStack_50;
  float fStack_4c;
  u32 uStack_48;
  u8 auStack_40 [16];
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  u32 uStack_10;
  float fStack_c;
  u32 uStack_8;
  
  iVar2 = *(int *)(*(int *)((u8 *)DAT_0086ef0c + param_1 * 0x1c0) + 0x3c);
  cVar3 = *(char *)(iVar2 + 1);
  iVar6 = DAT_007ce290 + *(int *)((u8 *)DAT_0086ef2c + cVar3 * 0x1c0) * 0x40;
  cVar1 = *(char *)(iVar2 + 3);
  switch (cVar1) {
  case '\x02':
    FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + cVar3 * 0x1c0));
    FUN_001ad940(&fStack_30,*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0)
                );
    FUN_001ad940(&fStack_20,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x1e0));
    fStack_f0 = fStack_20;
    fStack_ec = fStack_1c;
    fStack_e8 = fStack_18;
    fStack_100 = fStack_30;
    fStack_fc = fStack_2c;
    fStack_f8 = fStack_28;
    fStack_110 = fStack_20 - fStack_30;
    fStack_10c = fStack_1c - fStack_2c;
    fStack_108 = fStack_18 - fStack_28;
    uVar7 = FUN_004c6ac0_vec((const RwV3d*)(&fStack_110));
    *(u32 *)(iVar2 + 0x44) = uVar7;
    FUN_001ad940(auStack_40,*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0)
                );
    lVar4 = FUN_00454520((float *)auStack_40,*(u8 *)(iVar2 + 1));
    if (lVar4 == 0) {
      *(u8 *)(iVar2 + 3) = 4;
    }
    else {
      FUN_001ad940(&uStack_50,
                   *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
      uStack_10 = uStack_50;
      fStack_c = fStack_4c;
      uStack_8 = uStack_48;
      uStack_154 = uStack_50;
      uStack_14c = uStack_48;
      uStack_160 = uStack_50;
      uStack_158 = uStack_48;
      *(float *)&uStack_15c = 400.0f;
      uStack_150 = 0xc3c80000;
      FUN_001acc30_typed((void*)(&uStack_160),(void*)(&uStack_10));
      if (fStack_c <= 50.0f) {
        FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0),0);
        lVar4 = FUN_001afa20_typed((*(u32 *)(iVar6 + 0xc)),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0)),(void*)(&uStack_10));
        if (lVar4 != 0) {
          *(char *)(iVar2 + 8) = (char)*(u32 *)(iVar6 + 0x28);
          *(u8 *)(iVar2 + 3) = 3;
        }
      }
      else {
        FUN_004543c0(*(u8 *)(iVar2 + 1),4);
        ((u8 *)DAT_0095c210)[*(char *)(iVar2 + 1)] = 0;
      }
    }
    break;
  case '\x03':
    cVar3 = FUN_0044f300(cVar3);
    if (cVar3 != '\x01') {
      uVar5 = FUN_00318b60(*(u32 *)
                            (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x128));
      FUN_001ad940(auStack_60,
                   *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
      lVar4 = FUN_001c6450(*(u32 *)(iVar6 + 0x10),*(u32 *)(iVar6 + 4),uVar5,auStack_60
                          );
      if (lVar4 == 1) {
        FUN_004543c0(*(u8 *)(iVar2 + 1),5);
      }
      else {
        lVar4 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
        if (lVar4 == 0) {
          *(u8 *)(iVar2 + 3) = 2;
        }
        if (*(char *)(iVar2 + 8) < '\x01') {
          *(u8 *)(iVar2 + 3) = 2;
        }
        else {
          *(char *)(iVar2 + 8) = *(char *)(iVar2 + 8) + -1;
        }
      }
    }
    break;
  case '\x04':
    FUN_001ad940(auStack_70,*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0)
                );
    lVar4 = FUN_00454400((u32*)(auStack_70),(char)(cVar3));
    if (lVar4 == 0) {
      FUN_004543c0(*(u8 *)(iVar2 + 1),4);
      ((u8 *)DAT_0095c210)[*(char *)(iVar2 + 1)] = 0;
    }
    else {
      fVar8 = *(float *)(iVar6 + 0x14);
      FUN_001ad940(&fStack_90,
                   *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
      FUN_001ad940(&fStack_80,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x1e0));
      fStack_120 = fStack_80;
      fStack_11c = fStack_7c;
      fStack_118 = fStack_78;
      fStack_130 = fStack_90;
      fStack_12c = fStack_8c;
      fStack_128 = fStack_88;
      fStack_140 = fStack_80 - fStack_90;
      fStack_13c = fStack_7c - fStack_8c;
      fStack_138 = fStack_78 - fStack_88;
      fVar9 = (float)FUN_004c6ac0_vec((const RwV3d*)(&fStack_140));
      if (fVar9 < fVar8 * 3.0f) {
        FUN_001ad940(auStack_a0,
                     *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
        lVar4 = FUN_00454520((float *)auStack_a0,*(u8 *)(iVar2 + 1));
        if (lVar4 == 1) {
          FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
          *(u8 *)(iVar2 + 3) = 2;
        }
        else {
          uVar5 = FUN_00318b60(*(u32 *)
                                (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x128));
          FUN_001ad940(auStack_b0,
                       *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
          lVar4 = FUN_001c6450(*(u32 *)(iVar6 + 0x10),*(u32 *)(iVar6 + 4),uVar5,
                               auStack_b0);
          if (lVar4 == 1) {
            FUN_004543c0(*(u8 *)(iVar2 + 1),5);
          }
          else {
            lVar4 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
            if (lVar4 == 0) {
              FUN_00454620(*(u8 *)(iVar2 + 1));
              *(u8 *)(iVar2 + 3) = 5;
            }
          }
        }
      }
      else {
        FUN_004543c0(*(u8 *)(iVar2 + 1),4);
        ((u8 *)DAT_0095c210)[*(char *)(iVar2 + 1)] = 0;
      }
    }
    break;
  case '\x05':
    FUN_001ad940(auStack_c0,*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0)
                );
    lVar4 = FUN_00454520((float *)auStack_c0,cVar3);
    if (lVar4 == 1) {
      FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
      *(u8 *)(iVar2 + 3) = 2;
    }
    else {
      uVar5 = FUN_00318b60(*(u32 *)
                            (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x128));
      FUN_001ad940(auStack_d0,
                   *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
      lVar4 = FUN_001c6450(*(u32 *)(iVar6 + 0x10),*(u32 *)(iVar6 + 4),uVar5,auStack_d0
                          );
      if (lVar4 == 1) {
        FUN_004543c0(*(u8 *)(iVar2 + 1),5);
      }
      else {
        lVar4 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
        if (lVar4 == 0) {
          FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
          FUN_001ad940(auStack_e0,
                       *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
          FUN_001b0020_typed((u32)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0)),(void*)(auStack_e0),(s32)(5));
          *(u8 *)(iVar2 + 3) = 4;
        }
      }
    }
    break;
  }
  return;
}

// FUN_00450B30 NONMATCHING

void FUN_00450b30(char param_1)

{
  char cVar1;
  int iVar2;
  char cVar3;
  long lVar4;
  u64 uVar5;
  int iVar6;
  u32 uVar7;
  float fVar8;
  float fVar9;
  u32 uStack_160;
  u32 uStack_15c;
  u32 uStack_158;
  u32 uStack_154;
  u32 uStack_150;
  u32 uStack_14c;
  float fStack_140;
  float fStack_13c;
  float fStack_138;
  float fStack_130;
  float fStack_12c;
  float fStack_128;
  float fStack_120;
  float fStack_11c;
  float fStack_118;
  float fStack_110;
  float fStack_10c;
  float fStack_108;
  float fStack_100;
  float fStack_fc;
  float fStack_f8;
  float fStack_f0;
  float fStack_ec;
  float fStack_e8;
  u8 auStack_e0 [16];
  u8 auStack_d0 [16];
  u8 auStack_c0 [16];
  u8 auStack_b0 [16];
  u8 auStack_a0 [16];
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  u8 auStack_70 [16];
  u8 auStack_60 [16];
  u32 uStack_50;
  float fStack_4c;
  u32 uStack_48;
  u8 auStack_40 [16];
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  u32 uStack_10;
  float fStack_c;
  u32 uStack_8;
  
  iVar2 = *(int *)(*(int *)((u8 *)DAT_0086ef0c + param_1 * 0x1c0) + 0x3c);
  cVar3 = *(char *)(iVar2 + 1);
  iVar6 = iGpffffb5a0 + *(int *)((u8 *)DAT_0086ef2c + cVar3 * 0x1c0) * 0x40;
  cVar1 = *(char *)(iVar2 + 3);
  switch (cVar1) {
  case '\a':
    FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + cVar3 * 0x1c0));
    FUN_001ad940(&fStack_30,*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0)
                );
    FUN_001ad940(&fStack_20,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x1e0));
    fStack_f0 = fStack_20;
    fStack_ec = fStack_1c;
    fStack_e8 = fStack_18;
    fStack_100 = fStack_30;
    fStack_fc = fStack_2c;
    fStack_f8 = fStack_28;
    fStack_110 = fStack_20 - fStack_30;
    fStack_10c = fStack_1c - fStack_2c;
    fStack_108 = fStack_18 - fStack_28;
    uVar7 = FUN_004c6ac0_vec((const RwV3d*)(&fStack_110));
    *(u32 *)(iVar2 + 0x44) = uVar7;
    FUN_001ad940(auStack_40,*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0)
                );
    lVar4 = FUN_00454520((float *)auStack_40,*(u8 *)(iVar2 + 1));
    if (lVar4 == 0) {
      *(u8 *)(iVar2 + 3) = 9;
    }
    else {
      FUN_001ad940(&uStack_50,
                   *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
      uStack_10 = uStack_50;
      fStack_c = fStack_4c;
      uStack_8 = uStack_48;
      uStack_154 = uStack_50;
      uStack_14c = uStack_48;
      uStack_160 = uStack_50;
      uStack_158 = uStack_48;
      *(float *)&uStack_15c = 400.0f;
      uStack_150 = 0xc3c80000;
      FUN_001acc30_typed((void*)(&uStack_160),(void*)(&uStack_10));
      if (fStack_c <= 50.0f) {
        FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0),0);
        lVar4 = FUN_001afa20_typed((*(u32 *)(iVar6 + 0xc)),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0)),(void*)(&uStack_10));
        if (lVar4 != 0) {
          *(char *)(iVar2 + 8) = (char)*(u32 *)(iVar6 + 0x28);
          *(u8 *)(iVar2 + 3) = 8;
        }
      }
      else {
        *(u8 *)(iVar2 + 3) = 9;
      }
    }
    break;
  case '\b':
    cVar3 = FUN_0044f300(cVar3);
    if (cVar3 != '\x01') {
      uVar5 = FUN_00318b60(*(u32 *)
                            (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x128));
      FUN_001ad940(auStack_60,
                   *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
      lVar4 = FUN_001c6450(*(u32 *)(iVar6 + 0x10),*(u32 *)(iVar6 + 4),uVar5,auStack_60
                          );
      if (lVar4 == 1) {
        FUN_004543c0(*(u8 *)(iVar2 + 1),5);
      }
      else {
        lVar4 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
        if (lVar4 == 0) {
          *(u8 *)(iVar2 + 3) = 7;
        }
        if (*(char *)(iVar2 + 8) < '\x01') {
          *(u8 *)(iVar2 + 3) = 7;
        }
        else {
          *(char *)(iVar2 + 8) = *(char *)(iVar2 + 8) + -1;
        }
      }
    }
    break;
  case '\t':
    FUN_001ad940(auStack_70,*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0)
                );
    lVar4 = FUN_00454400((u32*)(auStack_70),(char)(cVar3));
    if (lVar4 == 0) {
      FUN_004543c0(*(u8 *)(iVar2 + 1),4);
      ((u8 *)DAT_0095c210)[*(char *)(iVar2 + 1)] = 0;
    }
    else {
      fVar8 = *(float *)(iVar6 + 0x14);
      FUN_001ad940(&fStack_90,
                   *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
      FUN_001ad940(&fStack_80,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x1e0));
      fStack_120 = fStack_80;
      fStack_11c = fStack_7c;
      fStack_118 = fStack_78;
      fStack_130 = fStack_90;
      fStack_12c = fStack_8c;
      fStack_128 = fStack_88;
      fStack_140 = fStack_80 - fStack_90;
      fStack_13c = fStack_7c - fStack_8c;
      fStack_138 = fStack_78 - fStack_88;
      fVar9 = (float)FUN_004c6ac0_vec((const RwV3d*)(&fStack_140));
      if (fVar9 < fVar8 * 3.0f) {
        FUN_001ad940(auStack_a0,
                     *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
        lVar4 = FUN_00454520((float *)auStack_a0,*(u8 *)(iVar2 + 1));
        if (lVar4 == 1) {
          FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
          *(u8 *)(iVar2 + 3) = 7;
        }
        else {
          uVar5 = FUN_00318b60(*(u32 *)
                                (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x128));
          FUN_001ad940(auStack_b0,
                       *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
          lVar4 = FUN_001c6450(*(u32 *)(iVar6 + 0x10),*(u32 *)(iVar6 + 4),uVar5,
                               auStack_b0);
          if (lVar4 == 1) {
            FUN_004543c0(*(u8 *)(iVar2 + 1),5);
          }
          else {
            lVar4 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
            if (lVar4 == 0) {
              FUN_00454620(*(u8 *)(iVar2 + 1));
              *(u8 *)(iVar2 + 3) = 10;
            }
          }
        }
      }
      else {
        FUN_004543c0(*(u8 *)(iVar2 + 1),4);
        ((u8 *)DAT_0095c210)[*(char *)(iVar2 + 1)] = 0;
      }
    }
    break;
  case '\n':
    FUN_001ad940(auStack_c0,*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0)
                );
    lVar4 = FUN_00454520((float *)auStack_c0,cVar3);
    if (lVar4 == 1) {
      FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
      *(u8 *)(iVar2 + 3) = 7;
    }
    else {
      uVar5 = FUN_00318b60(*(u32 *)
                            (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x128));
      FUN_001ad940(auStack_d0,
                   *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
      lVar4 = FUN_001c6450(*(u32 *)(iVar6 + 0x10),*(u32 *)(iVar6 + 4),uVar5,auStack_d0
                          );
      if (lVar4 == 1) {
        FUN_004543c0(*(u8 *)(iVar2 + 1),5);
      }
      else {
        lVar4 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
        if (lVar4 == 0) {
          FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
          FUN_001ad940(auStack_e0,
                       *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
          FUN_001b0020_typed((u32)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0)),(void*)(auStack_e0),(s32)(5));
          *(u8 *)(iVar2 + 3) = 9;
        }
      }
    }
    break;
  }
  return;
}

// FUN_004514A0 NONMATCHING

u32 FUN_004514a0(char param_1)

{
  short sVar1;
  u64 uVar2;
  int iVar3;
  u32 uVar4;
  char cVar5;
  u8 uVar6;
  int iVar7;
  u32 uVar8;
  float *pfVar9;
  long lVar10;
  int iVar11;
  short sVar12;
  long lVar13;
  short sVar14;
  short sVar15;
  int iVar16;
  int iVar17;
  long lVar18;
  float fVar19;
  float fVar20;
  float unaff_f20;
  int iStack_6b0;
  int iStack_6ac;
  short sStack_6a0;
  short asStack_692 [257];
  short asStack_490 [256];
  short asStack_290 [256];
  u32 uStack_90;
  float fStack_88;
  u64 uStack_80;
  float fStack_78;
  u32 uStack_70;
  float fStack_68;
  u32 uStack_60;
  float fStack_58;
  u64 uStack_50;
  float fStack_48;
  u64 uStack_40;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  u64 uStack_20;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar7 = param_1 * 0x1c0;
  iStack_6b0 = *(int *)(*(int *)((u8 *)DAT_0086ef0c + iVar7) + 0x3c);
  iStack_6ac = iStack_6b0 >> 0x1f;
  fVar20 = 0.0f;
  sStack_6a0 = 0;
  lVar18 = 1;
  sVar15 = -1;
  pfVar9 = (float *)(iGpffffb5a0 + *(int *)((u8 *)DAT_0086ef2c + iVar7) * 0x40);
  FUN_001ad940(&uStack_20,*(u32 *)(*(int *)((u8 *)DAT_0086edf4 + iVar7) + 0x1e0));
  FUN_001ad940(&fStack_30,
               *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iStack_6b0 + 0x18) * 0x70] + 0x1e0));
  fStack_2c = 0.0f;
  uStack_80 = uStack_20;
  fStack_78 = fStack_18;
  uStack_40 = uStack_20;
  uVar2 = uStack_40;
  fStack_38 = fStack_18;
  uStack_40 = uStack_20;
  sVar14 = (short)(int)(((float)uStack_40 + 400.0f) / 800.0f);
  uStack_50 = uStack_20;
  fStack_48 = fStack_18;
  sVar12 = (short)(int)((fStack_18 + 400.0f) / 800.0f);
  uStack_90 = (u32)(u32)fStack_30;
  fStack_88 = fStack_28;
  uStack_70 = uStack_90;
  fStack_68 = fStack_28;
  uStack_60 = uStack_90;
  fStack_58 = fStack_28;
  sVar1 = (short)(int)((*pfVar9 * 3.0f) / 800.0f);
  for (iVar7 = 0; iVar7 < 0x100; iVar7 = iVar7 + 1) {
    asStack_490[iVar7] = 0;
    asStack_290[iVar7] = -1;
    asStack_692[iVar7 + 1] = 0;
  }
  lVar10 = (long)(short)((short)(int)((fStack_30 + 400.0f) / 800.0f) +
                        (short)(int)((fStack_28 + 400.0f) / 800.0f) * 0x10);
  uStack_40 = uVar2;
  if (lVar10 == (int)sVar14 + sVar12 * 0x10) {
    iVar16 = sVar12 * 0x100;
    iVar17 = sVar14 * 0x10;
    iVar7 = FUN_001b9120_u32();
    if ((*(u8 *)(iVar7 + iVar16 + iVar17 + 0x53) & 1) != 0) {
      fStack_10 = (float)(int)sVar14 * 800.0f - fStack_30;
      fStack_c = unaff_f20 - fStack_2c;
      fStack_8 = (float)(sVar12 + -1) * 800.0f - fStack_28;
      fVar19 = (float)FUN_004c69f0(&fStack_10,&fStack_10);
      if (0.0f < fVar19) {
        sVar15 = 1;
        fVar20 = fVar19;
      }
    }
    iVar7 = FUN_001b9120_u32();
    if ((*(u8 *)(iVar7 + iVar16 + iVar17 + 0x53) & 2) != 0) {
      fStack_10 = (float)(sVar14 + -1) * 800.0f - fStack_30;
      fStack_c = unaff_f20 - fStack_2c;
      fStack_8 = (float)(int)sVar12 * 800.0f - fStack_28;
      fVar19 = (float)FUN_004c69f0(&fStack_10,&fStack_10);
      if (fVar20 < fVar19) {
        sVar15 = 2;
        fVar20 = fVar19;
      }
    }
    iVar7 = FUN_001b9120_u32();
    if ((*(u8 *)(iVar7 + iVar16 + iVar17 + 0x53) & 8) != 0) {
      fStack_10 = (float)(sVar14 + 1) * 800.0f - fStack_30;
      fStack_c = unaff_f20 - fStack_2c;
      fStack_8 = (float)(int)sVar12 * 800.0f - fStack_28;
      fVar19 = (float)FUN_004c69f0(&fStack_10,&fStack_10);
      if (fVar20 < fVar19) {
        sVar15 = 3;
        fVar20 = fVar19;
      }
    }
    iVar7 = FUN_001b9120_u32();
    if ((*(u8 *)(iVar7 + iVar16 + iVar17 + 0x53) & 4) != 0) {
      fStack_10 = (float)(int)sVar14 * 800.0f - fStack_30;
      fStack_c = unaff_f20 - fStack_2c;
      fStack_8 = (float)(sVar12 + 1) * 800.0f - fStack_28;
      fVar19 = (float)FUN_004c69f0(&fStack_10,&fStack_10);
      if (fVar20 < fVar19) {
        sVar15 = 4;
      }
    }
    if (sVar15 == -1) {
      return 0;
    }
    if (sVar15 == 4) {
      sVar12 = sVar12 + 1;
    }
    else if (sVar15 == 3) {
      sVar14 = sVar14 + 1;
    }
    else if (sVar15 == 2) {
      sVar14 = sVar14 + -1;
    }
    else if (sVar15 == 1) {
      sVar12 = sVar12 + -1;
    }
  }
  iVar7 = (int)sVar14 + sVar12 * 0x10;
  asStack_490[0] = (short)iVar7;
  asStack_692[asStack_490[0] + 1] = 1;
  do {
    sVar15 = 0;
    for (lVar13 = 0; lVar13 < (short)lVar18; lVar13 = (long)((int)lVar13 + 1)) {
      sVar12 = asStack_490[(int)lVar13];
      uVar8 = (u32)sVar12;
      iVar16 = (int)sVar12;
      if ((long)uVar8 < 0) {
        iVar16 = iVar16 + 0xf;
      }
      iVar17 = (iVar16 >> 4) * 0x100;
      iVar16 = (int)(uVar8 & 0xf);
      if (((long)uVar8 < 0) && ((uVar8 & 0xf) != 0)) {
        iVar16 = iVar16 + -0x10;
      }
      iVar16 = iVar16 * 0x10;
      iVar3 = FUN_001b9120_u32();
      iVar11 = (int)sVar12;
      if ((((*(u8 *)(iVar3 + iVar17 + iVar16 + 0x53) & 1) != 0) &&
          (*(short *)((int)&iStack_6b0 + iVar11 * 2) == 0)) && (lVar10 != iVar11 + -0x10)) {
        asStack_290[sVar15] = (short)(iVar11 + -0x10);
        sVar15 = sVar15 + 1;
        *(u16 *)((int)&iStack_6b0 + iVar11 * 2) = 1;
      }
      iVar3 = FUN_001b9120_u32();
      if ((((*(u8 *)(iVar3 + iVar17 + iVar16 + 0x53) & 8) != 0) && (asStack_692[iVar11 + 2] == 0))
         && (lVar10 != iVar11 + 1)) {
        asStack_290[sVar15] = (short)(iVar11 + 1);
        sVar15 = sVar15 + 1;
        asStack_692[iVar11 + 2] = 1;
      }
      iVar3 = FUN_001b9120_u32();
      if ((((*(u8 *)(iVar3 + iVar17 + iVar16 + 0x53) & 2) != 0) && (asStack_692[iVar11] == 0)) &&
         (lVar10 != iVar11 + -1)) {
        asStack_290[sVar15] = (short)(iVar11 + -1);
        sVar15 = sVar15 + 1;
        asStack_692[iVar11] = 1;
      }
      iVar3 = FUN_001b9120_u32();
      if ((((*(u8 *)(iVar3 + iVar17 + iVar16 + 0x53) & 4) != 0) &&
          (asStack_692[iVar11 + 0x11] == 0)) && (lVar10 != iVar11 + 0x10)) {
        asStack_290[sVar15] = (short)(iVar11 + 0x10);
        sVar15 = sVar15 + 1;
        asStack_692[iVar11 + 0x11] = 1;
      }
    }
    lVar18 = (long)sVar15;
    lVar13 = 0;
    while (lVar13 < lVar18) {
      iVar16 = (int)lVar13;
      asStack_490[iVar16] = -1;
      asStack_490[iVar16] = asStack_290[iVar16];
      asStack_290[iVar16] = -1;
      lVar13 = (long)(iVar16 + 1);
    }
    sStack_6a0 = sStack_6a0 + 1;
    if (CONCAT44((int)((long)((u32)(u32)(int)sVar1 << 0x30) >> 0x3f),(int)sVar1) <=
        (long)sStack_6a0) {
      sVar15 = 0;
    }
  } while (sVar15 != 0);
  uVar8 = (u32)asStack_490[0];
  if (uVar8 == (long)iVar7) {
    uVar4 = 0;
  }
  else {
    cVar5 = (char)(uVar8 & 0xf);
    if (((long)uVar8 < 0) && ((uVar8 & 0xf) != 0)) {
      cVar5 = cVar5 + -0x10;
    }
    *(char *)(iStack_6b0 + 0x8b) = cVar5;
    uVar6 = (u8)((int)asStack_490[0] >> 4);
    if ((long)uVar8 < 0) {
      uVar6 = (u8)(asStack_490[0] + 0xf >> 4);
    }
    *(u8 *)(iStack_6b0 + 0x8c) = uVar6;
    uVar4 = 1;
  }
  return uVar4;
}

// FUN_00451D70 NONMATCHING

void FUN_00451d70(int param_1)

{
  char cVar1;
  int iVar2;
  u8 uVar3;
  u8 uVar4;
  long lVar5;
  u8 auStack_40 [16];
  u8 auStack_30 [8];
  float fStack_28;
  float afStack_20 [4];
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  iVar2 = *(int *)(param_1 + 0x3c);
  cVar1 = *(char *)(iVar2 + 0x8b);
  if ((cVar1 == '\0') && (*(char *)(iVar2 + 0x8c) == '\0')) {
    lVar5 = FUN_004514a0(*(u8 *)(iVar2 + 1));
    if (lVar5 == 0) {
      FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
      FUN_001ad940(auStack_30,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x1e0));
      FUN_001ad940(afStack_20,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x1e0));
      FUN_001bf220(&uStack_10,(int)((afStack_20[0] + 400.0f) / 800.0f) & 0xffff,
                   (int)((fStack_28 + 400.0f) / 800.0f) & 0xffff);
      *(u32 *)(iVar2 + 0x6c) = uStack_10;
      *(u32 *)(iVar2 + 0x70) = uStack_c;
      *(u32 *)(iVar2 + 0x74) = uStack_8;
      *(u8 *)(iVar2 + 3) = 0xf;
    }
  }
  else {
    uVar3 = FUN_001ad910(*(u32 *)
                          (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x1e0));
    uVar4 = FUN_001ad920(*(u32 *)
                          (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(auStack_40,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x1e0));
    lVar5 = FUN_00453ed0(*(u8 *)(iVar2 + 1),uVar3,uVar4,(u32 *)auStack_40,cVar1,
                         *(u8 *)(iVar2 + 0x8c));
    if (lVar5 == 1) {
      *(u8 *)(iVar2 + 3) = 0xd;
    }
    else {
      *(u8 *)(iVar2 + 3) = 0xf;
    }
  }
  return;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00452010 NONMATCHING

void FUN_00452010(float *param_1)

{
  char cVar1;
  char cVar2;
  u8 bVar3;
  int iVar4;
  char cVar5;
  char cVar6;
  char cVar7;
  char cVar8;
  int iVar9;
  int iVar10;
  char cVar11;
  int unaff_s8_lo;
  char cStack_60;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  FUN_001ad940(&fStack_30,*(u32 *)(DAT_008717f4 + 0x1e0));
  fStack_10 = fStack_30;
  fStack_c = fStack_2c;
  fStack_8 = fStack_28;
  cVar8 = '\0';
  cVar1 = (char)(int)((fStack_30 + 400.0f) / 800.0f);
  cVar7 = (char)(int)((fStack_28 + 400.0f) / 800.0f);
  iVar10 = 0;
  do {
    if (0xf < iVar10) {
      if (cVar8 == '\0') {
        *param_1 = fStack_10;
        param_1[1] = fStack_c;
        param_1[2] = fStack_8;
      }
      else {
        *param_1 = (float)unaff_s8_lo * 800.0;
        param_1[1] = 0.0f;
        param_1[2] = (float)(int)cStack_60 * 800.0f;
      }
      return;
    }
    cVar6 = cVar1 + (char)iVar10;
    cVar11 = cVar1 - (char)iVar10;
    for (iVar9 = 0; iVar9 < 0x10; iVar9 = iVar9 + 1) {
      cVar2 = (char)iVar9;
      if ((cVar6 < '\0') || ('\x0f' < cVar6)) {
LAB_004521bc:
        bVar3 = 0;
      }
      else {
        cVar5 = cVar7 + cVar2;
        if ((cVar5 < '\0') || ('\x0f' < cVar5)) goto LAB_004521bc;
        iVar4 = FUN_001b9120_u32();
        if ((*(char *)(cVar6 * 0x10 + iVar4 + cVar5 * 0x100 + 0x48) != '\x01') ||
           (iVar4 = FUN_001b9120_u32(), *(char *)(cVar6 * 0x10 + iVar4 + cVar5 * 0x100 + 0x4a) == '\b'))
        goto LAB_004521bc;
        bVar3 = 1;
      }
      if (bVar3) {
        if ((long)cVar8 <= (long)(iVar10 + iVar9)) {
          cVar8 = (char)(iVar10 + iVar9);
          unaff_s8_lo = (int)cVar6;
          cStack_60 = cVar7 + cVar2;
        }
      }
      if ((cVar11 < '\0') || ('\x0f' < cVar11)) {
LAB_00452294:
        bVar3 = 0;
      }
      else {
        cVar5 = cVar7 - cVar2;
        if ((cVar5 < '\0') || ('\x0f' < cVar5)) goto LAB_00452294;
        iVar4 = FUN_001b9120_u32();
        if ((*(char *)(cVar11 * 0x10 + iVar4 + cVar5 * 0x100 + 0x48) != '\x01') ||
           (iVar4 = FUN_001b9120_u32(), *(char *)(cVar11 * 0x10 + iVar4 + cVar5 * 0x100 + 0x4a) == '\b')
           ) goto LAB_00452294;
        bVar3 = 1;
      }
      if (bVar3) {
        if ((long)cVar8 <= (long)(iVar10 + iVar9)) {
          cVar8 = (char)(iVar10 + iVar9);
          unaff_s8_lo = (int)cVar11;
          cStack_60 = cVar7 - cVar2;
        }
      }
    }
    iVar10 = iVar10 + 1;
  } while( 1 );
}

#pragma pop
// FUN_004523C0 NONMATCHING

u32 FUN_004523c0(u64 param_1,char param_2)

{
  int iVar1;
  u8 uVar2;
  u8 uVar3;
  u8 uVar4;
  u8 uVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  u64 uVar9;
  long lVar10;
  int iVar11;
  int iVar12;
  long lVar13;
  float fVar14;
  float fVar15;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_80;
  float fStack_7c;
  float fStack_78;
  u8 auStack_70 [16];
  u8 auStack_60 [16];
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  u8 auStack_30 [16];
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0086ef0c + param_2 * 0x1c0) + 0x3c);
  iVar11 = iGpffffb5a0 + *(int *)((u8 *)DAT_0086ef2c + *(char *)(iVar1 + 1) * 0x1c0) * 0x40;
  lVar13 = 0;
  do {
    if (3 < lVar13) {
      return 0;
    }
    iVar12 = (int)lVar13;
    if (lVar13 != *(char *)(iVar1 + 0x18)) {
      sVar6 = FUN_0043c910((char)lVar13);
      if (sVar6 != 0) {
        fVar15 = *(float *)(iVar11 + 0x14);
        FUN_001ad940(&fStack_20,*(u32 *)(((u8 *)DAT_008717f4)[iVar12 * 0x70] + 0x1e0));
        FUN_001ad940(&fStack_10,
                     *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0)
                    );
        fStack_80 = fStack_10;
        fStack_7c = fStack_c;
        fStack_78 = fStack_8;
        fStack_90 = fStack_20;
        fStack_8c = fStack_1c;
        fStack_88 = fStack_18;
        fStack_a0 = fStack_10 - fStack_20;
        fStack_9c = fStack_c - fStack_1c;
        fStack_98 = fStack_8 - fStack_18;
        fVar14 = (float)FUN_004c6ac0_vec((const RwV3d*)(&fStack_a0));
        if (fVar14 < fVar15) {
          uVar9 = FUN_00318b60(*(u32 *)
                                (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x128));
          FUN_001ad940(auStack_30,*(u32 *)(((u8 *)DAT_008717f4)[iVar12 * 0x70] + 0x1e0));
          lVar10 = FUN_001c6450(*(u32 *)(iVar11 + 0x10),*(u32 *)(iVar11 + 0x14),uVar9,
                                auStack_30);
          if (lVar10 == 1) {
            fVar15 = *(float *)(iVar11 + 0x14);
            FUN_001ad940(&fStack_50,
                         *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar1 + 0x18) * 0x70] + 0x1e0));
            FUN_001ad940(&fStack_40,
                         *(u32 *)
                          (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
            fStack_b0 = fStack_40;
            fStack_ac = fStack_3c;
            fStack_a8 = fStack_38;
            fStack_c0 = fStack_50;
            fStack_bc = fStack_4c;
            fStack_b8 = fStack_48;
            fStack_d0 = fStack_40 - fStack_50;
            fStack_cc = fStack_3c - fStack_4c;
            fStack_c8 = fStack_38 - fStack_48;
            fVar14 = (float)FUN_004c6ac0_vec((const RwV3d*)(&fStack_d0));
            if (fVar15 <= fVar14) {
              sVar6 = FUN_001ad910(*(u32 *)(((u8 *)DAT_008717f4)[iVar12 * 0x70] + 0x1e0));
              sVar7 = FUN_001ad920(*(u32 *)(((u8 *)DAT_008717f4)[iVar12 * 0x70] + 0x1e0));
              iVar8 = FUN_001b9120_u32();
              if (*(char *)(iVar8 + sVar7 * 0x100 + sVar6 * 0x10 + 0x4a) != '\b') {
                FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
                uVar2 = FUN_001ad910(*(u32 *)
                                      (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) +
                                      0x1e0));
                uVar3 = FUN_001ad920(*(u32 *)
                                      (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) +
                                      0x1e0));
                FUN_001ad940(auStack_70,
                             *(u32 *)
                              (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
                uVar4 = FUN_001ad910(*(u32 *)(((u8 *)DAT_008717f4)[iVar12 * 0x70] + 0x1e0));
                uVar5 = FUN_001ad920(*(u32 *)(((u8 *)DAT_008717f4)[iVar12 * 0x70] + 0x1e0));
                FUN_00453ed0(*(u8 *)(iVar1 + 1),uVar2,uVar3,(u32 *)auStack_70,uVar4,uVar5);
                FUN_001b0240(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0),0);
                *(char *)(iVar1 + 0x18) = (char)lVar13;
                *(u8 *)(iVar1 + 3) = 0x14;
                return 1;
              }
              fVar15 = *(float *)(iVar1 + 0x28);
              fVar14 = *(float *)(iVar1 + 0x30);
              uVar2 = FUN_001ad910(*(u32 *)
                                    (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0)
                                  );
              uVar3 = FUN_001ad920(*(u32 *)
                                    (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0)
                                  );
              FUN_001ad940(auStack_60,
                           *(u32 *)
                            (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
              lVar13 = FUN_00453ed0(*(u8 *)(iVar1 + 1),uVar2,uVar3,(u32 *)auStack_60,
                                    (char)(int)((fVar15 + 400.0f) / 800.0f),
                                    (char)(int)((fVar14 + 400.0f) / 800.0f));
              if (lVar13 == 1) {
                FUN_001b0240(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0),0);
                *(u8 *)(iVar1 + 3) = 0x14;
              }
            }
          }
        }
      }
    }
    lVar13 = (long)(iVar12 + 1);
  } while( 1 );
}

// FUN_00452A70 NONMATCHING

u32 FUN_00452a70(char param_1,char param_2)

{
  int iVar1;
  u8 uVar2;
  u8 uVar3;
  u8 uVar4;
  u8 uVar5;
  short sVar6;
  short sVar7;
  int iVar8;
  u32 uVar9;
  long lVar10;
  int *piVar11;
  float fVar12;
  float fVar13;
  u8 auStack_70 [16];
  u8 auStack_60 [16];
  u32 uStack_50;
  u32 uStack_4c;
  u32 uStack_48;
  u8 auStack_40 [8];
  float fStack_38;
  u8 auStack_30 [4];
  float fStack_2c;
  float afStack_20 [4];
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0086ef0c + param_1 * 0x1c0) + 0x3c);
  sVar6 = FUN_001ad910(*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar1 + 0x18) * 0x70] + 0x1e0));
  sVar7 = FUN_001ad920(*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar1 + 0x18) * 0x70] + 0x1e0));
  piVar11 = (int *)((u8 *)DAT_008717f4 + param_2 * 0x70);
  FUN_001ad940(afStack_20,*(u32 *)(*piVar11 + 0x1e0));
  fStack_10 = afStack_20[0] - *(float *)(iVar1 + 0x1c);
  FUN_001ad940(auStack_30,*(u32 *)(*piVar11 + 0x1e0));
  fStack_c = fStack_2c - *(float *)(iVar1 + 0x20);
  FUN_001ad940(auStack_40,*(u32 *)(*piVar11 + 0x1e0));
  fStack_8 = fStack_38 - *(float *)(iVar1 + 0x24);
  fVar12 = (float)FUN_004c69f0(&fStack_10,&fStack_10);
  if (1600.0f <= fVar12) {
    FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
    FUN_001ad940(&uStack_50,*(u32 *)(*piVar11 + 0x1e0));
    *(u32 *)(iVar1 + 0x1c) = uStack_50;
    *(u32 *)(iVar1 + 0x20) = uStack_4c;
    *(u32 *)(iVar1 + 0x24) = uStack_48;
    iVar8 = FUN_001b9120_u32();
    if (*(char *)(iVar8 + sVar7 * 0x100 + sVar6 * 0x10 + 0x4a) == '\b') {
      FUN_001ad910(*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar1 + 0x18) * 0x70] + 0x1e0));
      FUN_001ad920(*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar1 + 0x18) * 0x70] + 0x1e0));
      fVar13 = *(float *)(iVar1 + 0x28);
      fVar12 = *(float *)(iVar1 + 0x30);
      uVar2 = FUN_001ad910(*(u32 *)
                            (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
      uVar3 = FUN_001ad920(*(u32 *)
                            (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
      FUN_001ad940(auStack_60,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
      lVar10 = FUN_00453ed0(*(u8 *)(iVar1 + 1),uVar2,uVar3,(u32 *)auStack_60,
                            (char)(int)((fVar13 + 400.0f) / 800.0f),
                            (char)(int)((fVar12 + 400.0f) / 800.0f));
      if (lVar10 == 1) {
        FUN_001b0240(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0),0);
        *(u8 *)(iVar1 + 3) = 0x14;
      }
      uVar9 = 1;
    }
    else {
      uVar2 = FUN_001ad910(*(u32 *)
                            (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
      uVar3 = FUN_001ad920(*(u32 *)
                            (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
      FUN_001ad940(auStack_70,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
      uVar4 = FUN_001ad910(*(u32 *)(((u8 *)DAT_008717f4)[param_2 * 0x70] + 0x1e0));
      uVar5 = FUN_001ad920(*(u32 *)(((u8 *)DAT_008717f4)[param_2 * 0x70] + 0x1e0));
      FUN_00453ed0(*(u8 *)(iVar1 + 1),uVar2,uVar3,(u32 *)auStack_70,uVar4,uVar5);
      *(u8 *)(iVar1 + 3) = 0x14;
      uVar9 = 1;
    }
  }
  else {
    uVar9 = 0;
  }
  return uVar9;
}

// FUN_00452F70 NONMATCHING

void FUN_00452f70(u32 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  u32 uVar5;
  u32 uVar6;
  u32 unaff_s6_lo;
  u32 uVar7;
  u32 unaff_s7_lo;
  u32 uVar8;
  u32 uStack_50;
  u32 uStack_4c;
  u32 uStack_48;
  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  iVar1 = *(int *)(param_2 + 0x3c);
  for (uVar5 = 0; uVar6 = unaff_s6_lo, uVar8 = unaff_s7_lo, uVar7 = unaff_s6_lo, (int)uVar5 < 0x10;
      uVar5 = uVar5 + 1) {
    for (uVar6 = 0; (int)uVar6 < 0x10; uVar6 = uVar6 + 1) {
      iVar4 = FUN_001b9120_u32();
      if ((*(char *)(uVar5 * 0x100 + iVar4 + uVar6 * 0x10 + 0x49) == '\x01') &&
         (iVar4 = FUN_001b9120_u32(), uVar8 = uVar5, uVar7 = uVar6,
         *(char *)(uVar5 * 0x100 + iVar4 + uVar6 * 0x10 + 0x4a) == '\b')) goto LAB_00453278;
    }
  }
LAB_00453278:
  for (; (int)uVar6 < (int)(uVar7 + 2); uVar6 = uVar6 + 1) {
    iVar4 = uVar6 * 0x10;
    for (uVar5 = uVar8; (int)uVar5 < (int)(uVar8 + 2); uVar5 = uVar5 + 1) {
      iVar3 = uVar5 * 0x100;
      iVar2 = FUN_001b9120_u32();
      if (((*(u8 *)(iVar4 + iVar2 + iVar3 + 0x53) & 1) != 0) &&
         (iVar2 = FUN_001b9120_u32(), *(char *)(iVar4 + iVar2 + iVar3 + -0xb6) != '\b')) {
        FUN_001bf220(&uStack_10,uVar6 & 0xffff,uVar5 - 1 & 0xffff);
        FUN_001bf220(&uStack_20,uVar6 & 0xffff,uVar5 & 0xffff);
        *(u32 *)(iVar1 + 0x34) = uStack_20;
        *(u32 *)(iVar1 + 0x38) = uStack_1c;
        *(u32 *)(iVar1 + 0x3c) = uStack_18;
      }
      iVar2 = FUN_001b9120_u32();
      if (((*(u8 *)(iVar4 + iVar2 + iVar3 + 0x53) & 2) != 0) &&
         (iVar2 = FUN_001b9120_u32(), *(char *)(iVar4 + iVar2 + iVar3 + 0x3a) != '\b')) {
        FUN_001bf220(&uStack_10,uVar6 - 1 & 0xffff,uVar5 & 0xffff);
        FUN_001bf220(&uStack_30,uVar6 & 0xffff,uVar5 & 0xffff);
        *(u32 *)(iVar1 + 0x34) = uStack_30;
        *(u32 *)(iVar1 + 0x38) = uStack_2c;
        *(u32 *)(iVar1 + 0x3c) = uStack_28;
      }
      iVar2 = FUN_001b9120_u32();
      if (((*(u8 *)(iVar4 + iVar2 + iVar3 + 0x53) & 4) != 0) &&
         (iVar2 = FUN_001b9120_u32(), *(char *)(iVar4 + iVar2 + iVar3 + 0x14a) != '\b')) {
        FUN_001bf220(&uStack_10,uVar6 & 0xffff,uVar5 + 1 & 0xffff);
        FUN_001bf220(&uStack_40,uVar6 & 0xffff,uVar5 & 0xffff);
        *(u32 *)(iVar1 + 0x34) = uStack_40;
        *(u32 *)(iVar1 + 0x38) = uStack_3c;
        *(u32 *)(iVar1 + 0x3c) = uStack_38;
      }
      iVar2 = FUN_001b9120_u32();
      if (((*(u8 *)(iVar4 + iVar2 + iVar3 + 0x53) & 8) != 0) &&
         (iVar2 = FUN_001b9120_u32(), *(char *)(iVar4 + iVar2 + iVar3 + 0x5a) != '\b')) {
        FUN_001bf220(&uStack_10,uVar6 + 1 & 0xffff,uVar5 & 0xffff);
        FUN_001bf220(&uStack_50,uVar6 & 0xffff,uVar5 & 0xffff);
        *(u32 *)(iVar1 + 0x34) = uStack_50;
        *(u32 *)(iVar1 + 0x38) = uStack_4c;
        *(u32 *)(iVar1 + 0x3c) = uStack_48;
      }
    }
  }
  *param_1 = uStack_10;
  param_1[1] = uStack_c;
  param_1[2] = uStack_8;
  return;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_004532D0

void FUN_004532d0(char param_1)
{
  u8 *base;
  u8 *puVar1;
  int iVar2;
  int iVar3;
  int valid;

  iVar3 = 0;
  for (; iVar3 < 0x18; iVar3 = iVar3 + 1) {
    base = DAT_0086ede8_abs;
    valid = 0;
    puVar1 = base + iVar3 * 0x1c0;
    if ((*(int *)(puVar1 + 0x48) != 0) && (*(int *)(puVar1 + 0x54) != 0)) {
      valid = 1;
    }
    valid = valid != 0;
    if (valid == 1) {
      iVar2 = *(int *)(*(int *)(puVar1 + 0x16c) + 0x3c);
      *(char *)(iVar2 + 0x40) = param_1;
      if (param_1 == '\0') {
        FUN_001b0260(*(u32 *)(DAT_0086ef10_abs + *(char *)(iVar2 + 1) * 0x1c0 + 0x170),0);
      }
      else {
        FUN_001b0260(*(u32 *)(DAT_0086ef10_abs + *(char *)(iVar2 + 1) * 0x1c0 + 0x170),1);
      }
    }
  }
  return;
}

#pragma pop
#pragma push
#pragma opt_rebuildconditionals off
#pragma opt_loop_invariants on
// FUN_004533E0

void FUN_004533e0(u8 param_1)
{
  u8 *base;
  int iVar2;
  u8 *puVar1;
  int valid;

  iVar2 = 0;
  for (; iVar2 < 0x18; iVar2 = iVar2 + 1) {
    base = DAT_0086eda0_bytes;
    valid = 0;
    puVar1 = base + iVar2 * 0x1c0;
    if ((*(int *)(puVar1 + 0x48) != 0) && (*(int *)(puVar1 + 0x54) != 0)) {
      valid = 1;
    }
    valid = valid != 0;
    if (valid == 1) {
      *(u8 *)(*(int *)(*(int *)(puVar1 + 0x16c) + 0x3c) + 0x41) = param_1;
    }
  }
}
#pragma pop

// FUN_00453460

short FUN_00453460(void)

{
  return uGpffffba04;
}

// FUN_00453470

void FUN_00453470(u16 param_1)
{
  *(u16 *)&DAT_007ce6f4 = param_1;
}

// FUN_00453480

char FUN_00453480(void)

{
  return uGpffffba00;
}

// FUN_00453490

void FUN_00453490(int param_1)

{
  **(u8 **)(param_1 + 0x3c) = 6;
  return;
}

// FUN_004534B0 NONMATCHING






u32 FUN_004534b0(char param_1)

{
  u8 bVar1;
  u8 *puVar2;
  u32 uVar3;
  u32 uVar4;
  int iVar5;
  long lVar6;
  u32 uVar7;
  float afStack_10 [2];
  float fStack_8;
  
  puVar2 = *(u8 **)(*(int *)((u8 *)DAT_0086ef0c + param_1 * 0x1c0) + 0x3c);
  uVar3 = (u32)(u8)puVar2[0x8b] + (u32)(u8)puVar2[0x8c] * 0x10;
  if ((puVar2[0x78] == '\0') && (puVar2[0x79] == '\0')) {
    *puVar2 = 0x2a;
    uVar4 = 1;
  }
  else {
    bVar1 = puVar2[0x78];
    iVar5 = FUN_001b9120_u32();
    if ((*(u8 *)(iVar5 + (u32)(u8)puVar2[0x79] * 0x100 + (u32)bVar1 * 0x10 + 0x53) & 1) != 0)
    {
      afStack_10[0] = (float)bVar1 * 800.0f;
      fStack_8 = (float)(int)((u8)puVar2[0x79] - 1) * 800.0f;
      lVar6 = FUN_00454400((u32*)(afStack_10),(char)(puVar2[1]));
      if ((lVar6 == 1) || (*(int *)((u8 *)DAT_0086ef2c + (char)puVar2[1] * 0x1c0) == 4)) {
        uVar7 = (u32)(u8)puVar2[0x78] + ((u8)puVar2[0x79] - 1) * 0x10 & 0xff;
        if ((*(short *)(puVar2 + uVar7 * 8 + 0x98) == 0) &&
           (*(short *)(puVar2 + uVar7 * 8 + 0x9a) == 0)) {
          *(u16 *)(puVar2 + uVar7 * 8 + 0x98) = (u16)(u8)puVar2[0x78];
          *(u16 *)(puVar2 + uVar7 * 8 + 0x9a) = (u8)puVar2[0x79] - 1;
          *(u16 *)(puVar2 + uVar7 * 8 + 0x9c) = (u16)(u8)puVar2[0x78];
          *(u16 *)(puVar2 + uVar7 * 8 + 0x9e) = (u16)(u8)puVar2[0x79];
          *(u32 *)(puVar2 + *(int *)(puVar2 + 0x94) * 4 + 0x898) = uVar7;
          *(int *)(puVar2 + 0x94) = *(int *)(puVar2 + 0x94) + 1;
          if ((*(u16 *)(puVar2 + uVar7 * 8 + 0x98) == (u16)(u8)puVar2[0x8b]) &&
             (*(u16 *)(puVar2 + uVar7 * 8 + 0x9a) == (u16)(u8)puVar2[0x8c])) {
            uVar3 = uVar3 & 0xff;
            *(u16 *)(puVar2 + uVar3 * 8 + 0x98) = (u16)(u8)puVar2[0x8b];
            *(u16 *)(puVar2 + uVar3 * 8 + 0x9a) = (u16)(u8)puVar2[0x8c];
            *(u16 *)(puVar2 + uVar3 * 8 + 0x9c) = (u16)(u8)puVar2[0x8b];
            *(u16 *)(puVar2 + uVar3 * 8 + 0x9e) = (u8)puVar2[0x8c] + 1;
            return 2;
          }
        }
      }
    }
    bVar1 = puVar2[0x78];
    iVar5 = FUN_001b9120_u32();
    if ((*(u8 *)(iVar5 + (u32)(u8)puVar2[0x79] * 0x100 + (u32)bVar1 * 0x10 + 0x53) & 2) != 0)
    {
      afStack_10[0] = (float)(int)(bVar1 - 1) * 800.0f;
      fStack_8 = (float)(u8)puVar2[0x79] * 800.0f;
      lVar6 = FUN_00454400((u32*)(afStack_10),(char)(puVar2[1]));
      if ((lVar6 == 1) || (*(int *)((u8 *)DAT_0086ef2c + (char)puVar2[1] * 0x1c0) == 4)) {
        iVar5 = ((u8)puVar2[0x78] - 1) + (u32)(u8)puVar2[0x79] * 0x10;
        if ((*(short *)(puVar2 + iVar5 * 8 + 0x98) == 0) &&
           (*(short *)(puVar2 + iVar5 * 8 + 0x9a) == 0)) {
          *(short *)(puVar2 + iVar5 * 8 + 0x98) = (short)((u8)puVar2[0x78] - 1);
          *(u16 *)
           (puVar2 + (((u8)puVar2[0x78] - 1) + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x9a) =
               (u16)(u8)puVar2[0x79];
          *(u16 *)
           (puVar2 + (((u8)puVar2[0x78] - 1) + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x9c) =
               (u16)(u8)puVar2[0x78];
          *(u16 *)
           (puVar2 + (((u8)puVar2[0x78] - 1) + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x9e) =
               (u16)(u8)puVar2[0x79];
          *(u32 *)(puVar2 + *(int *)(puVar2 + 0x94) * 4 + 0x898) =
               ((u8)puVar2[0x78] - 1) + (u32)(u8)puVar2[0x79] * 0x10;
          *(int *)(puVar2 + 0x94) = *(int *)(puVar2 + 0x94) + 1;
          iVar5 = ((u8)puVar2[0x78] - 1) + (u32)(u8)puVar2[0x79] * 0x10;
          if ((*(u16 *)(puVar2 + iVar5 * 8 + 0x98) == (u16)(u8)puVar2[0x8b]) &&
             (*(u16 *)(puVar2 + iVar5 * 8 + 0x9a) == (u16)(u8)puVar2[0x8c])) {
            uVar3 = uVar3 & 0xff;
            *(u16 *)(puVar2 + uVar3 * 8 + 0x98) = (u16)(u8)puVar2[0x8b];
            *(u16 *)(puVar2 + uVar3 * 8 + 0x9a) = (u16)(u8)puVar2[0x8c];
            *(u16 *)(puVar2 + uVar3 * 8 + 0x9c) = (u8)puVar2[0x8b] + 1;
            *(u16 *)(puVar2 + uVar3 * 8 + 0x9e) = (u16)(u8)puVar2[0x8c];
            return 2;
          }
        }
      }
    }
    bVar1 = puVar2[0x78];
    iVar5 = FUN_001b9120_u32();
    if ((*(u8 *)(iVar5 + (u32)(u8)puVar2[0x79] * 0x100 + (u32)bVar1 * 0x10 + 0x53) & 8) != 0)
    {
      afStack_10[0] = (float)(bVar1 + 1) * 800.0f;
      fStack_8 = (float)(u8)puVar2[0x79] * 800.0f;
      lVar6 = FUN_00454400((u32*)(afStack_10),(char)(puVar2[1]));
      if ((lVar6 == 1) || (*(int *)((u8 *)DAT_0086ef2c + (char)puVar2[1] * 0x1c0) == 4)) {
        iVar5 = (u8)puVar2[0x78] + 1 + (u32)(u8)puVar2[0x79] * 0x10;
        if ((*(short *)(puVar2 + iVar5 * 8 + 0x98) == 0) &&
           (*(short *)(puVar2 + iVar5 * 8 + 0x9a) == 0)) {
          *(short *)(puVar2 + iVar5 * 8 + 0x98) = (short)((u8)puVar2[0x78] + 1);
          *(u16 *)
           (puVar2 + ((u8)puVar2[0x78] + 1 + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x9a) =
               (u16)(u8)puVar2[0x79];
          *(u16 *)
           (puVar2 + ((u8)puVar2[0x78] + 1 + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x9c) =
               (u16)(u8)puVar2[0x78];
          *(u16 *)
           (puVar2 + ((u8)puVar2[0x78] + 1 + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x9e) =
               (u16)(u8)puVar2[0x79];
          *(u32 *)(puVar2 + *(int *)(puVar2 + 0x94) * 4 + 0x898) =
               (u8)puVar2[0x78] + 1 + (u32)(u8)puVar2[0x79] * 0x10;
          *(int *)(puVar2 + 0x94) = *(int *)(puVar2 + 0x94) + 1;
          iVar5 = (u8)puVar2[0x78] + 1 + (u32)(u8)puVar2[0x79] * 0x10;
          if ((*(u16 *)(puVar2 + iVar5 * 8 + 0x98) == (u16)(u8)puVar2[0x8b]) &&
             (*(u16 *)(puVar2 + iVar5 * 8 + 0x9a) == (u16)(u8)puVar2[0x8c])) {
            uVar3 = uVar3 & 0xff;
            *(u16 *)(puVar2 + uVar3 * 8 + 0x98) = (u16)(u8)puVar2[0x8b];
            *(u16 *)(puVar2 + uVar3 * 8 + 0x9a) = (u16)(u8)puVar2[0x8c];
            *(u16 *)(puVar2 + uVar3 * 8 + 0x9c) = (u8)puVar2[0x8b] - 1;
            *(u16 *)(puVar2 + uVar3 * 8 + 0x9e) = (u16)(u8)puVar2[0x8c];
            return 2;
          }
        }
      }
    }
    bVar1 = puVar2[0x78];
    iVar5 = FUN_001b9120_u32();
    if ((*(u8 *)(iVar5 + (u32)(u8)puVar2[0x79] * 0x100 + (u32)bVar1 * 0x10 + 0x53) & 4) != 0)
    {
      afStack_10[0] = (float)bVar1 * 800.0f;
      fStack_8 = (float)((u8)puVar2[0x79] + 1) * 800.0f;
      lVar6 = FUN_00454400((u32*)(afStack_10),(char)(puVar2[1]));
      if ((lVar6 == 1) || (*(int *)((u8 *)DAT_0086ef2c + (char)puVar2[1] * 0x1c0) == 4)) {
        iVar5 = (u32)(u8)puVar2[0x78] + ((u8)puVar2[0x79] + 1) * 0x10;
        if ((*(short *)(puVar2 + iVar5 * 8 + 0x98) == 0) &&
           (*(short *)(puVar2 + iVar5 * 8 + 0x9a) == 0)) {
          *(u16 *)(puVar2 + iVar5 * 8 + 0x98) = (u16)(u8)puVar2[0x78];
          *(short *)(puVar2 + ((u32)(u8)puVar2[0x78] + ((u8)puVar2[0x79] + 1) * 0x10) * 8 +
                              0x9a) = (short)((u8)puVar2[0x79] + 1);
          *(u16 *)
           (puVar2 + ((u32)(u8)puVar2[0x78] + ((u8)puVar2[0x79] + 1) * 0x10) * 8 + 0x9c) =
               (u16)(u8)puVar2[0x78];
          *(u16 *)
           (puVar2 + ((u32)(u8)puVar2[0x78] + ((u8)puVar2[0x79] + 1) * 0x10) * 8 + 0x9e) =
               (u16)(u8)puVar2[0x79];
          *(u32 *)(puVar2 + *(int *)(puVar2 + 0x94) * 4 + 0x898) =
               (u32)(u8)puVar2[0x78] + ((u8)puVar2[0x79] + 1) * 0x10;
          *(int *)(puVar2 + 0x94) = *(int *)(puVar2 + 0x94) + 1;
          iVar5 = (u32)(u8)puVar2[0x78] + ((u8)puVar2[0x79] + 1) * 0x10;
          if ((*(u16 *)(puVar2 + iVar5 * 8 + 0x98) == (u16)(u8)puVar2[0x8b]) &&
             (*(u16 *)(puVar2 + iVar5 * 8 + 0x9a) == (u16)(u8)puVar2[0x8c])) {
            uVar3 = uVar3 & 0xff;
            *(u16 *)(puVar2 + uVar3 * 8 + 0x98) = (u16)(u8)puVar2[0x8b];
            *(u16 *)(puVar2 + uVar3 * 8 + 0x9a) = (u16)(u8)puVar2[0x8c];
            *(u16 *)(puVar2 + uVar3 * 8 + 0x9c) = (u16)(u8)puVar2[0x8b];
            *(u16 *)(puVar2 + uVar3 * 8 + 0x9e) = (u8)puVar2[0x8c] - 1;
            return 2;
          }
        }
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}

// FUN_00453D90 NONMATCHING
void FUN_00453d90(char param_1)
{
  int iVar4;
  u8 bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  short sVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  int iVar9;
  int iVar10;
  u8 bVar1;
  u8 bVar2;

  iVar4 = *(int *)(*(int *)(DAT_0086ef0c_abs + param_1 * 0x1c0) + 0x3c);
  bVar5 = 0;
  iVar6 = 0;
  *(u32 *)(iVar4 + 0x94) = 0;
  iVar8 = 0;
  while (iVar8 < 0x100) {
    iVar7 = iVar4 + iVar8 * 4;
    *(u16 *)(iVar7 + 0xc98) = 0;
    *(u16 *)(iVar7 + 0xc9a) = 0;
    iVar8 = iVar8 + 1;
  }
  bVar2 = *(volatile u8 *)(iVar4 + 0x8b);
  bVar1 = *(volatile u8 *)(iVar4 + 0x8c);
  iVar7 = *(int *)(iVar4 + 0x94);
  iVar8 = iVar4 + iVar7 * 4;
  *(u16 *)(iVar8 + 0xc98) = bVar2;
  iVar7 = *(int *)(iVar4 + 0x94);
  iVar8 = iVar4 + iVar7 * 4;
  *(u16 *)(iVar8 + 0xc9a) = bVar1;
  do {
    iVar8 = iVar4 + iVar7 * 4;
    sVar2 = *(short *)(iVar8 + 0xc9a);
    iVar9 = (int)sVar2 << 4;
    sVar3 = *(short *)(iVar8 + 0xc98);
    iVar9 = iVar9 + (int)sVar3;
    iVar9 = iVar4 + iVar9 * 8;
    sVar4 = *(short *)(iVar9 + 0x9c);
    sVar5 = *(short *)(iVar9 + 0x9e);
    *(int *)(iVar4 + 0x94) = iVar7 + 1;
    if ((sVar4 == *(u8 *)(iVar4 + 0x8d)) && (sVar5 == *(u8 *)(iVar4 + 0x8e))) {
      bVar5 = 1;
    }
    else {
      iVar9 = iVar4 + ((int)sVar4 + (int)sVar5 * 0x10) * 8;
      sVar4 = *(short *)(iVar9 + 0x98);
      iVar7 = *(int *)(iVar4 + 0x94);
      iVar8 = iVar4 + iVar7 * 4;
      *(u16 *)(iVar8 + 0xc98) = sVar4;
      sVar5 = *(short *)(iVar9 + 0x9a);
      iVar7 = *(int *)(iVar4 + 0x94);
      iVar8 = iVar4 + iVar7 * 4;
      *(u16 *)(iVar8 + 0xc9a) = sVar5;
    }
    iVar6 = iVar6 + 1;
    if (99 < iVar6) {
      bVar5 = 1;
    }
  } while (!bVar5);
}

// FUN_00453ED0 NONMATCHING

u32
FUN_00453ed0(char param_1,char param_2,char param_3,u32 *param_4,char param_5,char param_6)

{
  int iVar1;
  int iVar2;
  u8 bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  u32 uVar9;
  u32 uVar10;
  u32 uVar11;
  
  uVar11 = *param_4;
  uVar9 = param_4[1];
  uVar10 = param_4[2];
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0086ef0c + param_1 * 0x1c0) + 0x3c);
  *(char *)(iVar1 + 0x5c) = param_2;
  *(char *)(iVar1 + 0x78) = param_2;
  *(char *)(iVar1 + 0x5d) = param_3;
  *(char *)(iVar1 + 0x79) = param_3;
  *(u32 *)(iVar1 + 0x50) = uVar11;
  *(u32 *)(iVar1 + 0x54) = uVar9;
  *(u32 *)(iVar1 + 0x58) = uVar10;
  for (iVar5 = 0; iVar5 < 0x100; iVar5 = iVar5 + 1) {
    iVar7 = iVar1 + iVar5 * 8;
    *(u16 *)(iVar7 + 0x98) = 0;
    *(u16 *)(iVar7 + 0x9a) = 0;
    *(u16 *)(iVar7 + 0x9c) = 0;
    *(u16 *)(iVar7 + 0x9e) = 0;
    *(u32 *)(iVar1 + iVar5 * 4 + 0x898) = 0;
  }
  *(u32 *)(iVar1 + 0x94) = 0;
  *(char *)(iVar1 + 0x8d) = param_2;
  *(char *)(iVar1 + 0x8e) = param_3;
  *(char *)(iVar1 + 0x8b) = param_5;
  *(char *)(iVar1 + 0x8c) = param_6;
  *(u32 *)(iVar1 + 0x60) = uVar11;
  *(u32 *)(iVar1 + 100) = uVar9;
  *(u32 *)(iVar1 + 0x68) = uVar10;
  if ((param_2 == param_5) && (param_3 == param_6)) {
    uVar9 = 0;
  }
  else {
    bVar3 = 0;
    do {
      cVar4 = FUN_004534b0(*(u8 *)(iVar1 + 1));
      iVar5 = *(int *)(*(int *)((u8 *)DAT_0086ef0c + *(char *)(iVar1 + 1) * 0x1c0) + 0x3c);
      iVar7 = *(int *)(iVar5 + 0x898);
      *(u32 *)(iVar5 + 0x94) = 0;
      for (iVar8 = 0; iVar8 < 0xff; iVar8 = iVar8 + 1) {
        iVar6 = iVar5 + iVar8 * 4;
        iVar2 = *(int *)(iVar6 + 0x89c);
        *(int *)(iVar6 + 0x898) = iVar2;
        if (iVar2 != 0) {
          *(int *)(iVar5 + 0x94) = *(int *)(iVar5 + 0x94) + 1;
        }
      }
      iVar7 = iVar5 + iVar7 * 8;
      *(char *)(iVar5 + 0x78) = (char)*(u16 *)(iVar7 + 0x98);
      *(char *)(iVar5 + 0x79) = (char)*(u16 *)(iVar7 + 0x9a);
      if (cVar4 == '\x01') {
        cVar4 = '\x02';
        bVar3 = 1;
      }
    } while (cVar4 != '\x02');
    if (bVar3) {
      uVar9 = 0;
    }
    else {
      FUN_00453d90(*(u8 *)(iVar1 + 1));
      uVar9 = 1;
    }
  }
  return uVar9;
}
// FUN_00454110


void FUN_00454110(int param_1)
{
  char cVar1;
  int iVar2;

  iVar2 = *(int *)(param_1 + 0x3c);
  cVar1 = *(char *)(iVar2 + 2);
  switch (cVar1) {
  case '\x03':
    FUN_0044d600(param_1);
    break;
  case '\x04':
    FUN_0044b7d0(param_1);
    break;
  case '\x05':
    FUN_001b00c0(*(u32 *)(DAT_0086ef10_abs + *(char *)(iVar2 + 1) * 0x1c0));
    FUN_001b0240(*(u32 *)(DAT_0086ef10_abs + *(char *)(iVar2 + 1) * 0x1c0),0);
    *(s16 *)&DAT_007ce6f4 = (short)*(char *)(iVar2 + 1);
    *(u8 *)&DAT_007ce6f0 = 0;
    break;
  case '\x06':
    break;
  default:
    break;
  }
  return;
}

// FUN_004541F0

u32 FUN_004541f0(int param_1)
{
  char *pcVar1;
  int iVar2;

  pcVar1 = *(char **)(param_1 + 0x3c);
  switch (*pcVar1) {
  case '\0':
    *(float *)(pcVar1 + 8) = *(float *)(pcVar1 + 8) + 100.0f;
    iVar2 = FUN_001b9120_u32();
    FUN_001a91b0_call(*(u32 *)(iVar2 + 0x1204),pcVar1 + 4);
    *pcVar1 = '\x01';
    break;
  case '\x01':
    return 0xffffffff;
  default:
    break;
  }
  return 0;
}

// FUN_00454290

void FUN_00454290(int param_1)

{
  DAT_0096017c_abs[0](*(u32 *)(param_1 + 0x3c));
  return;
}

// FUN_004542C0 NONMATCHING

u32 FUN_004542c0(char param_1)

{
  u32 lVar1;
  u32 uVar2;
  u8 *puVar3;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  lVar1 = (*DAT_00960184_abs)(1,0x10,0x40000);
  if (lVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00194b80_u32(0,0x106f,DAT_006b4a30,FUN_004541f0,FUN_00454290,lVar1);
    puVar3 = (u8 *)lVar1;
    *puVar3 = 0;
    FUN_001ad940(&uStack_10,*(u32 *)(*(int *)((u8 *)DAT_0086edf4 + param_1 * 0x1c0) + 0x1e0));
    *(u32 *)(puVar3 + 4) = uStack_10;
    *(u32 *)(puVar3 + 8) = uStack_c;
    *(u32 *)(puVar3 + 0xc) = uStack_8;
    FUN_001d0110_typed((void *)((u8 *)DAT_0086eda0 + param_1 * 0x1c0));
  }
  return uVar2;
}

// FUN_004543C0

void FUN_004543c0(char param_1,u8 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0086ef0c_abs + param_1 * 0x1c0) + 0x3c);
  *(u8 *)(iVar1 + 2) = param_2;
  *(u8 *)(iVar1 + 3) = 0;
  *(u8 *)(iVar1 + 4) = 0;
  *(u8 *)(iVar1 + 5) = 0;
  return;
}

// FUN_00454400 NONMATCHING

u8 FUN_00454400(u32 *param_1,char param_2)

{
  u8 bVar1;
  long lVar2;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_24;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_10;
  float fStack_c;
  u32 uStack_8;
  
  uStack_30 = *param_1;
  fStack_c = (float)param_1[1];
  uStack_28 = param_1[2];
  *(float *)&uStack_2c = 400.0f;
  uStack_20 = 0xc3c80000;
  if (*(int *)((u8 *)DAT_0086ef2c +
              *(char *)(*(int *)(*(int *)((u8 *)DAT_0086ef0c + param_2 * 0x1c0) + 0x3c) + 1) * 0x1c0) ==
      4) {
    bVar1 = 1;
  }
  else {
    uStack_24 = uStack_30;
    uStack_1c = uStack_28;
    uStack_10 = uStack_30;
    uStack_8 = uStack_28;
    lVar2 = FUN_001acc30_typed((void*)(&uStack_30),(void*)(&uStack_10));
    if (lVar2 == 1) {
      bVar1 = fStack_c <= 50.0;
    }
    else {
      bVar1 = 0;
    }
  }
  return bVar1;
}

// FUN_00454520 NONMATCHING

u8 FUN_00454520(float *param_1,char param_2)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  struct {
    float v20[4];
    float v10[4];
  } stack;
#define fStack_20 stack.v20[0]
#define fStack_1c stack.v20[1]
#define fStack_18 stack.v20[2]
#define fStack_10 stack.v10[0]
#define fStack_c stack.v10[1]
#define fStack_8 stack.v10[2]
  
  fStack_10 = *param_1;
  fStack_c = param_1[1];
  fStack_8 = param_1[2];
  stack.v10[3] = 0.0f;
  stack.v20[3] = 0.0f;
  iVar1 = *(char *)(*(int *)(*(int *)((u8 *)DAT_0086ef0c + param_2 * 0x1c0) + 0x3c) + 1) * 0x1c0;
  pfVar2 = (float *)(DAT_007ce290 + *(int *)((u8 *)DAT_0086ef2c + iVar1) * 0x40);
  iVar1 = *(int *)((u8 *)DAT_0086ef08 + iVar1);
  fStack_20 = *(float *)(iVar1 + 0x100) - fStack_10;
  fStack_1c = *(float *)(iVar1 + 0x104) - fStack_c;
  fStack_18 = *(float *)(iVar1 + 0x108) - fStack_8;
  fVar3 = (float)FUN_004c6ac0_vec((const RwV3d*)(&fStack_20));
  return fVar3 < *pfVar2;
}
#undef fStack_20
#undef fStack_1c
#undef fStack_18
#undef fStack_10
#undef fStack_c
#undef fStack_8

// FUN_00454620 NONMATCHING

u64 FUN_00454620(char param_1)

{
  int iVar1;
  int iVar2;
  u8 bVar3;
  long lVar4;
  int iVar5;
  float *pfVar6;
  float fVar7;
  float afStack_c0 [4];
  float fStack_b4;
  u32 uStack_b0;
  float fStack_ac;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float afStack_90 [4];
  
#define fStack_90 afStack_90[0]
#define fStack_8c afStack_90[1]
#define fStack_88 afStack_90[2]
  u8 auStack_80 [16];
  u8 auStack_70 [16];
  float fStack_78;
  float fStack_6c;
  float afStack_60 [4];
  u8 auStack_50 [16];
  float fStack_48;
  u8 auStack_40 [16];
  float fStack_3c;
  float afStack_30 [4];
  float afStack_20 [4];
  float afStack_10 [4];
  
#define fStack_20 afStack_20[0]
#define fStack_1c afStack_20[1]
#define fStack_18 afStack_20[2]
#define fStack_10 afStack_10[0]
#define fStack_c afStack_10[1]
#define fStack_8 afStack_10[2]
  
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0086ef0c + param_1 * 0x1c0) + 0x3c);
  pfVar6 = (float *)(DAT_007ce290 + *(int *)((u8 *)DAT_0086ef2c + *(char *)(iVar1 + 1) * 0x1c0) * 0x40);
  FUN_001ad940(afStack_30,*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar1 + 0x18) * 0x70] + 0x1e0));
  fStack_10 = afStack_30[0] -
              *(float *)(*(int *)((u8 *)DAT_0086ef08 + *(char *)(iVar1 + 1) * 0x1c0) + 0x100);
  FUN_001ad940(auStack_40,*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar1 + 0x18) * 0x70] + 0x1e0));
  fStack_c = fStack_3c - *(float *)(*(int *)((u8 *)DAT_0086ef08 + *(char *)(iVar1 + 1) * 0x1c0) + 0x104);
  FUN_001ad940(auStack_50,*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar1 + 0x18) * 0x70] + 0x1e0));
  fStack_8 = fStack_48 - *(float *)(*(int *)((u8 *)DAT_0086ef08 + *(char *)(iVar1 + 1) * 0x1c0) + 0x108);
  FUN_004c69f0(&fStack_10,&fStack_10);
  fVar7 = *pfVar6;
  iVar5 = *(char *)(iVar1 + 1) * 0x1c0;
  iVar2 = *(int *)((u8 *)DAT_0086ef08 + iVar5);
  fStack_10 = fStack_10 * fVar7 + *(float *)(iVar2 + 0x100) + 0.0f;
  fStack_c = fStack_c * fVar7 + *(float *)(iVar2 + 0x104);
  fStack_8 = fStack_8 * fVar7 + *(float *)(iVar2 + 0x108);
  FUN_001ad940(afStack_60,*(u32 *)(*(int *)((u8 *)DAT_0086edf4 + iVar5) + 0x1e0));
  fStack_20 = fStack_10 - afStack_60[0];
  FUN_001ad940(auStack_70,
               *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
  fStack_1c = fStack_c - fStack_6c;
  FUN_001ad940(auStack_80,
               *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
  fStack_18 = fStack_8 - fStack_78;
  fVar7 = (float)FUN_004c6ac0_vec((const RwV3d*)(&fStack_20));
  if (150.0f < fVar7) {
    fStack_90 = fStack_10;
    fStack_8c = fStack_c;
    fStack_98 = fStack_8;
    fStack_88 = fStack_8;
    fStack_b4 = fStack_10;
    fStack_ac = fStack_8;
    afStack_c0[0] = fStack_10;
    afStack_c0[2] = fStack_8;
    afStack_c0[3] = 0.0f;
    afStack_c0[1] = 400.0f;
    uStack_b0 = 0xc3c80000;
    fStack_a0 = fStack_90;
    fStack_9c = fStack_8c;
    if (*(int *)((u8 *)DAT_0086ef2c +
                *(char *)(*(int *)(*(int *)((u8 *)DAT_0086ef0c + *(char *)(iVar1 + 1) * 0x1c0) + 0x3c) +
                         1) * 0x1c0) == 4) {
      bVar3 = 1;
    }
    else {
      lVar4 = FUN_001acc30_typed((void*)(afStack_c0),(void*)(&fStack_90));
      bVar3 = 1;
      if (lVar4 == 1) {
        if (50.0f < fStack_8c) {
          bVar3 = 0;
        }
      }
      else {
        bVar3 = 0;
      }
    }
    if ((bVar3) &&
       (lVar4 = FUN_001afa20_typed((pfVar6[3]),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0)),(void*)(&fStack_10)), lVar4 == 1)) {
      return 1;
    }
  }
  return 0;
}
#undef fStack_20
#undef fStack_1c
#undef fStack_18
#undef fStack_10
#undef fStack_c
#undef fStack_8
#undef fStack_90
#undef fStack_8c
#undef fStack_88

// FUN_00454A70 NONMATCHING

u8 FUN_00454a70(char param_1,float *param_2)

{
  int iVar1;
  u8 bVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  float fVar7;
  float afStack_60 [3];
  float fStack_54;
  u32 uStack_50;
  float fStack_4c;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  fStack_10 = *param_2;
  fStack_c = param_2[1];
  fStack_8 = param_2[2];
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0086ef0c + param_1 * 0x1c0) + 0x3c);
  iVar5 = *(char *)(iVar1 + 1) * 0x1c0;
  pfVar6 = (float *)(DAT_007ce290 + *(int *)((u8 *)DAT_0086ef2c + iVar5) * 0x40);
  iVar5 = *(int *)((u8 *)DAT_0086ef08 + iVar5);
  fStack_20 = fStack_10 - *(float *)(iVar5 + 0x100);
  fStack_1c = fStack_c - *(float *)(iVar5 + 0x104);
  fStack_18 = fStack_8 - *(float *)(iVar5 + 0x108);
  FUN_004c69f0(&fStack_20,&fStack_20);
  fVar7 = *pfVar6;
  iVar4 = *(char *)(iVar1 + 1) * 0x1c0;
  iVar5 = *(int *)((u8 *)DAT_0086ef08 + iVar4);
  afStack_60[0] = fStack_20 * fVar7 + *(float *)(iVar5 + 0x100) + 0.0;
  fStack_1c = fStack_1c * fVar7 + *(float *)(iVar5 + 0x104);
  afStack_60[2] = fStack_18 * fVar7 + *(float *)(iVar5 + 0x108);
  afStack_60[1] = 400.0;
  uStack_50 = 0xc3c80000;
  fStack_54 = afStack_60[0];
  fStack_4c = afStack_60[2];
  fStack_38 = afStack_60[2];
  fStack_28 = afStack_60[2];
  fStack_20 = afStack_60[0];
  fStack_18 = afStack_60[2];
  fStack_30 = afStack_60[0];
  fStack_2c = fStack_1c;
  fStack_40 = afStack_60[0];
  fStack_3c = fStack_1c;
  if (*(int *)((u8 *)DAT_0086ef2c +
              *(char *)(*(int *)(*(int *)((u8 *)DAT_0086ef0c + iVar4) + 0x3c) + 1) * 0x1c0) == 4) {
    bVar2 = 1;
  }
  else {
    lVar3 = FUN_001acc30_typed((void*)(afStack_60),(void*)(&fStack_30));
    bVar2 = 1;
    if (lVar3 == 1) {
      if (50.0 < fStack_2c) {
        bVar2 = 0;
      }
    }
    else {
      bVar2 = 0;
    }
  }
  if (bVar2) {
    FUN_001afa20_typed((pfVar6[3]),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0)),(void*)(&fStack_20))
    ;
  }
  return bVar2;
}

// FUN_00454D00 NONMATCHING

u8 FUN_00454d00(float *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  
  iVar2 = (int)(char)(int)((*param_1 + 400.0f) / 800.0f);
  fVar5 = ((*param_1 + 0.0f) - (float)iVar2 * 800.0f) + 400.0f;
  iVar3 = (int)(char)(int)((param_1[2] + 400.0f) / 800.0f);
  fVar4 = ((param_1[2] + 0.0f) - (float)iVar3 * 800.0f) + 400.0f;
  iVar3 = iVar3 * 0x100;
  iVar2 = iVar2 * 0x10;
  iVar1 = FUN_001b9120_u32();
  if (*(char *)(iVar1 + iVar3 + iVar2 + 0x48) != '\x01') {
    return 0;
  }
  if (fVar4 < 150.0f) {
    if ((150.0f <= fVar5) && (fVar5 <= 650.0f)) {
      iVar1 = FUN_001b9120_u32();
      return (*(u8 *)(iVar1 + iVar3 + iVar2 + 0x53) & 1) != 0;
    }
  }
  else if (650.0f < fVar4) {
    if ((150.0f <= fVar5) && (fVar5 <= 650.0f)) {
      iVar1 = FUN_001b9120_u32();
      return (*(u8 *)(iVar1 + iVar3 + iVar2 + 0x53) & 4) != 0;
    }
  }
  else {
    if (fVar5 < 150.0f) {
      iVar1 = FUN_001b9120_u32();
      return (*(u8 *)(iVar1 + iVar3 + iVar2 + 0x53) & 2) != 0;
    }
    if (650.0f < fVar5) {
      iVar1 = FUN_001b9120_u32();
      return (*(u8 *)(iVar1 + iVar3 + iVar2 + 0x53) & 8) != 0;
    }
  }
  return 1;
}

// FUN_00454F50 NONMATCHING

void FUN_00454f50(char param_1,char param_2)

{
  int iVar1;
  u8 bVar2;
  long lVar3;
  int iVar4;
  short sVar5;
  float *pfVar6;
  int iVar7;
  int *piVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float afStack_2b0 [3];
  float fStack_2a4;
  u32 uStack_2a0;
  float fStack_29c;
  float afStack_290 [3];
  float fStack_284;
  u32 uStack_280;
  float fStack_27c;
  float fStack_270;
  float fStack_26c;
  float fStack_268;
  u64 uStack_260;
  float fStack_258;
  float fStack_250;
  float fStack_24c;
  float fStack_248;
  float fStack_240;
  float fStack_23c;
  float fStack_238;
  u64 uStack_230;
  float fStack_228;
  u64 uStack_220;
  float fStack_218;
  u8 auStack_210 [8];
  float fStack_208;
  u8 auStack_200 [4];
  float fStack_1fc;
  float afStack_1f0 [4];
  u8 auStack_1e0 [8];
  float fStack_1d8;
  u8 auStack_1d0 [4];
  float fStack_1cc;
  float afStack_1c0 [4];
  u8 auStack_1b0 [8];
  float fStack_1a8;
  u8 auStack_1a0 [4];
  float fStack_19c;
  float afStack_190 [4];
  u8 auStack_180 [8];
  float fStack_178;
  u8 auStack_170 [4];
  float fStack_16c;
  float afStack_160 [4];
  u8 auStack_150 [8];
  float fStack_148;
  u8 auStack_140 [8];
  float fStack_138;
  u8 auStack_130 [4];
  float fStack_12c;
  u8 auStack_120 [4];
  float fStack_11c;
  float afStack_110 [4];
  float afStack_100 [4];
  u8 auStack_f0 [8];
  float fStack_e8;
  u8 auStack_e0 [8];
  float fStack_d8;
  u8 auStack_d0 [4];
  float fStack_cc;
  u8 auStack_c0 [4];
  float fStack_bc;
  float afStack_b0 [4];
  float afStack_a0 [4];
  u8 auStack_90 [8];
  float fStack_88;
  u8 auStack_80 [8];
  float fStack_78;
  u8 auStack_70 [4];
  float fStack_6c;
  u8 auStack_60 [4];
  float fStack_5c;
  float afStack_50 [4];
  float afStack_40 [4];
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  u64 uStack_20;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0086ef0c + param_1 * 0x1c0) + 0x3c);
  uStack_20 = *(u64 *)&DAT_006b4a48;
  fStack_18 = *(float *)&DAT_006b4a50;
  iVar4 = *(char *)(iVar1 + 1) * 0x1c0;
  iVar7 = DAT_007ce290 + *(int *)((u8 *)DAT_0086ef2c + iVar4) * 0x40;
  FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + iVar4));
  iVar4 = FUN_00488f30();
  sVar5 = (short)(iVar4 % 100);
  if (sVar5 < 0x32) {
    piVar8 = (int *)((u8 *)DAT_008717f4 + param_2 * 0x70);
    FUN_001ad940(afStack_40,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(afStack_50,*(u32 *)(*piVar8 + 0x1e0));
    fStack_10 = afStack_40[0] - afStack_50[0];
    FUN_001ad940(auStack_60,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(auStack_70,*(u32 *)(*piVar8 + 0x1e0));
    fStack_c = fStack_5c - fStack_6c;
    FUN_001ad940(auStack_80,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(auStack_90,*(u32 *)(*piVar8 + 0x1e0));
    fStack_8 = fStack_78 - fStack_88;
  }
  else {
    piVar8 = (int *)((u8 *)DAT_008717f4 + param_2 * 0x70);
    FUN_001ad940(afStack_b0,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(afStack_a0,*(u32 *)(*piVar8 + 0x1e0));
    fStack_10 = afStack_a0[0] - afStack_b0[0];
    FUN_001ad940(auStack_d0,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(auStack_c0,*(u32 *)(*piVar8 + 0x1e0));
    fStack_c = fStack_bc - fStack_cc;
    FUN_001ad940(auStack_f0,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(auStack_e0,*(u32 *)(*piVar8 + 0x1e0));
    fStack_8 = fStack_d8 - fStack_e8;
  }
  fVar9 = (float)FUN_004c69f0(&fStack_10,&fStack_10);
  if (fVar9 < 300.0f) {
    piVar8 = (int *)((u8 *)DAT_008717f4 + param_2 * 0x70);
    FUN_001ad940(afStack_100,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(afStack_110,*(u32 *)(*piVar8 + 0x1e0));
    fStack_10 = afStack_100[0] - afStack_110[0];
    FUN_001ad940(auStack_120,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(auStack_130,*(u32 *)(*piVar8 + 0x1e0));
    fStack_c = fStack_11c - fStack_12c;
    FUN_001ad940(auStack_140,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(auStack_150,*(u32 *)(*piVar8 + 0x1e0));
    fStack_8 = fStack_138 - fStack_148;
    FUN_004c69f0(&fStack_10,&fStack_10);
    fVar10 = fStack_10 * 400.0f;
    fVar11 = fStack_c * 400.0f;
    fVar9 = fStack_8 * 400.0f;
    FUN_001ad940(afStack_160,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    fStack_30 = fVar10 + afStack_160[0];
    FUN_001ad940(auStack_170,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    fStack_2c = fVar11 + fStack_16c;
    FUN_001ad940(auStack_180,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    afStack_290[2] = fVar9 + fStack_178;
    uStack_260 = CONCAT44(*(u32 *)&fStack_2c,*(u32 *)&fStack_30);
    fStack_284 = fStack_30;
    afStack_290[0] = fStack_30;
    afStack_290[1] = 400.0f;
    uStack_280 = 0xc3c80000;
    fStack_27c = afStack_290[2];
    fStack_258 = afStack_290[2];
    uStack_220 = uStack_260;
    fStack_218 = afStack_290[2];
    fStack_28 = afStack_290[2];
    if (*(int *)((u8 *)DAT_0086ef2c +
                *(char *)(*(int *)(*(int *)((u8 *)DAT_0086ef0c + *(char *)(iVar1 + 1) * 0x1c0) + 0x3c) +
                         1) * 0x1c0) == 4) {
      bVar2 = 1;
    }
    else {
      lVar3 = FUN_001acc30_typed((void*)(afStack_290),(void*)(&uStack_220));
      bVar2 = 1;
      if (lVar3 == 1) {
        if (50.0f < *((float *)&uStack_220 + 1)) {
          bVar2 = 0;
        }
      }
      else {
        bVar2 = 0;
      }
    }
    if (!bVar2) {
      FUN_001ad940(&fStack_30,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    }
    if (sVar5 < 0x32) {
      piVar8 = (int *)((u8 *)DAT_008717f4 + param_2 * 0x70);
      FUN_001ad940(afStack_190,*(u32 *)(*piVar8 + 0x1e0));
      fStack_10 = fStack_30 - afStack_190[0];
      FUN_001ad940(auStack_1a0,*(u32 *)(*piVar8 + 0x1e0));
      fStack_c = fStack_2c - fStack_19c;
      FUN_001ad940(auStack_1b0,*(u32 *)(*piVar8 + 0x1e0));
      fStack_8 = fStack_28 - fStack_1a8;
    }
    else {
      piVar8 = (int *)((u8 *)DAT_008717f4 + param_2 * 0x70);
      FUN_001ad940(afStack_1c0,*(u32 *)(*piVar8 + 0x1e0));
      fStack_10 = afStack_1c0[0] - fStack_30;
      FUN_001ad940(auStack_1d0,*(u32 *)(*piVar8 + 0x1e0));
      fStack_c = fStack_1cc - fStack_2c;
      FUN_001ad940(auStack_1e0,*(u32 *)(*piVar8 + 0x1e0));
      fStack_8 = fStack_1d8 - fStack_28;
    }
    FUN_004c69f0(&fStack_10,&fStack_10);
    fStack_30 = fStack_30 + (fStack_c * fStack_18 - fStack_8 * *((float *)&uStack_20 + 1)) * 400.0f;
    fStack_2c = fStack_2c + (fStack_8 * *(float *)&uStack_20 - fStack_10 * fStack_18) * 400.0f;
    fStack_28 = fStack_28 + (fStack_10 * *((float *)&uStack_20 + 1) - fStack_c * *(float *)&uStack_20) * 400.0f;
  }
  else {
    fVar12 = fStack_8 * *(float *)&uStack_20;
    fVar9 = fStack_10 * fStack_18;
    fVar11 = (fStack_c * fStack_18 - fStack_8 * *((float *)&uStack_20 + 1)) * 400.0f;
    fVar10 = (fStack_10 * *((float *)&uStack_20 + 1) - fStack_c * *(float *)&uStack_20) * 400.0f;
    FUN_001ad940(afStack_1f0,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    fStack_30 = fVar11 + afStack_1f0[0];
    FUN_001ad940(auStack_200,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    fStack_2c = (fVar12 - fVar9) * 400.0f + fStack_1fc;
    FUN_001ad940(auStack_210,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    fStack_28 = fVar10 + fStack_208;
  }
  FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0),0);
  uStack_230 = CONCAT44(*(u32 *)&fStack_2c,*(u32 *)&fStack_30);
  fStack_228 = fStack_28;
  iVar4 = *(char *)(*(int *)(*(int *)((u8 *)DAT_0086ef0c + *(char *)(iVar1 + 1) * 0x1c0) + 0x3c) + 1) *
          0x1c0;
  pfVar6 = (float *)(DAT_007ce290 + *(int *)((u8 *)DAT_0086ef2c + iVar4) * 0x40);
  iVar4 = *(int *)((u8 *)DAT_0086ef08 + iVar4);
  fStack_240 = *(float *)(iVar4 + 0x100) - fStack_30;
  fStack_23c = *(float *)(iVar4 + 0x104) - fStack_2c;
  fStack_238 = *(float *)(iVar4 + 0x108) - fStack_28;
  fVar9 = (float)FUN_004c6ac0_vec((const RwV3d*)(&fStack_240));
  if (fVar9 < *pfVar6) {
    fStack_250 = fStack_30;
    fStack_24c = fStack_2c;
    fStack_268 = fStack_28;
    fStack_248 = fStack_28;
    fStack_2a4 = fStack_30;
    fStack_29c = fStack_28;
    afStack_2b0[0] = fStack_30;
    afStack_2b0[2] = fStack_28;
    afStack_2b0[1] = 400.0f;
    uStack_2a0 = 0xc3c80000;
    fStack_270 = fStack_250;
    fStack_26c = fStack_24c;
    if (*(int *)((u8 *)DAT_0086ef2c +
                *(char *)(*(int *)(*(int *)((u8 *)DAT_0086ef0c + *(char *)(iVar1 + 1) * 0x1c0) + 0x3c) +
                         1) * 0x1c0) == 4) {
      bVar2 = 1;
    }
    else {
      lVar3 = FUN_001acc30_typed((void*)(afStack_2b0),(void*)(&fStack_250));
      bVar2 = 1;
      if (lVar3 == 1) {
        if (50.0f < fStack_24c) {
          bVar2 = 0;
        }
      }
      else {
        bVar2 = 0;
      }
    }
    if (bVar2) {
      FUN_001afa20_typed((*(u32 *)(iVar7 + 0xc)),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0)),(void*)(&fStack_30));
      *(u8 *)(iVar1 + 3) = 0x19;
      FUN_0010a4e0(1,8,3,6);
    }
  }
  else {
    lVar3 = FUN_00454a70(*(u8 *)(iVar1 + 1),&fStack_30);
    if (lVar3 == 1) {
      *(u8 *)(iVar1 + 3) = 0x19;
      FUN_0010a4e0(1,8,3,6);
    }
  }
  return;
}

// FUN_00455B50 NONMATCHING

void FUN_00455b50(void)

{
  u8 bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  for (iVar2 = 1; iVar2 < 4; iVar2 = iVar2 + 1) {
    iVar4 = 0;
    if ((((u8 *)DAT_008717e8)[iVar2 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar2 * 0x70] != 0)) {
      iVar4 = 1;
    }
    if (iVar4 != 0) {
      iVar3 = iVar2 * 0x1c0;
      iVar4 = *(int *)(*(int *)((u8 *)DAT_0087190c + iVar3) + 0x3c);
      ((u8 *)DAT_0087193c)[iVar3] = 0;
      if (*(char *)(iVar4 + 0x1215) == '\x01') {
        ((u8 *)DAT_0087193c)[iVar3] = 1;
      }
      iVar3 = iVar2 * 0x1c0;
      ((u8 *)DAT_0087193a)[iVar3] = *(u8 *)(iVar4 + 1);
      ((u8 *)DAT_0087193b)[iVar3] = 0;
      if (*(char *)(iVar4 + 1) == '\x05') {
        ((u8 *)DAT_0087193b)[iVar3] = 1;
      }
    }
  }
  for (iVar2 = 0; iVar2 < 0x18; iVar2 = iVar2 + 1) {
    bVar1 = 0;
    if ((*(int *)((u8 *)DAT_0086ede8 + iVar2 * 0x1c0) != 0) &&
       (*(int *)((u8 *)DAT_0086edf4 + iVar2 * 0x1c0) != 0)) {
      bVar1 = 1;
    }
    if (bVar1) {
      iVar3 = iVar2 * 0x1c0;
      iVar4 = *(int *)(*(int *)((u8 *)DAT_0086ef0c + iVar3) + 0x3c);
      ((u8 *)DAT_0086ef38)[iVar3] = *(u8 *)(iVar4 + 0x18);
      ((u8 *)DAT_0086ef39)[iVar3] = *(char *)(iVar4 + 0x8b) + *(char *)(iVar4 + 0x8c) * '\x10';
      ((u8 *)DAT_0086ef3a)[iVar3] = *(u8 *)(iVar4 + 2);
      ((u8 *)DAT_0086ef3b)[iVar3] = 0;
      ((u8 *)DAT_0086ef3c)[iVar3] = 0;
      if (*(char *)(iVar4 + 0x40) == '\x01') {
        ((u8 *)DAT_0086ef3c)[iVar3] = 1;
      }
    }
  }
  return;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00455CF0 NONMATCHING

void FUN_00455cf0(void)

{
  u8 bVar1;
  int iVar2;
  int iVar3;
  
  for (iVar3 = 1; iVar3 < 4; iVar3 = iVar3 + 1) {
    bVar1 = 0;
    if ((((u8 *)DAT_008717e8)[iVar3 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar3 * 0x70] != 0)) {
      bVar1 = 1;
    }
    if (bVar1) {
      ((u8 *)DAT_0087193a)[iVar3 * 0x1c0] = 0;
      ((u8 *)DAT_0087193c)[iVar3 * 0x1c0] = 0;
    }
  }
  for (iVar3 = 0; iVar3 < 0x18; iVar3 = iVar3 + 1) {
    bVar1 = 0;
    if ((*(int *)((u8 *)DAT_0086ede8 + iVar3 * 0x1c0) != 0) &&
       (*(int *)((u8 *)DAT_0086edf4 + iVar3 * 0x1c0) != 0)) {
      bVar1 = 1;
    }
    if (bVar1) {
      iVar2 = iVar3 * 0x1c0;
      ((u8 *)DAT_0086ef38)[iVar2] = 0;
      ((u8 *)DAT_0086ef39)[iVar2] = 0;
      ((u8 *)DAT_0086ef3a)[iVar2] = 0;
      ((u8 *)DAT_0086ef3b)[iVar2] = 0;
      ((u8 *)DAT_0086ef3c)[iVar2] = 0;
    }
  }
  return;
}

#pragma pop
#pragma push
#pragma opt_loop_invariants on
// FUN_00455E00 NONMATCHING

u64 FUN_00455e00(u64 param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  u32 uVar4;
  int iVar5;
  u64 uVar6;
  float fVar7;
  
  pcVar3 = *(char **)((int)param_1 + 0x3c);
  if ((pcVar3[0x148] != '\0') && (cVar2 = *pcVar3, cVar2 != '\x03')) {
    if (cVar2 != '\x02') {
      if (cVar2 != '\x01') {
        if (cVar2 != '\0') {
          return 0;
        }
        *pcVar3 = '\x01';
      }
      uVar4 = FUN_003b5d10_eb90(0x400);
      *(u32 *)(pcVar3 + 0x144) = uVar4;
      *pcVar3 = '\x02';
    }
    (*DAT_00960090)(6,1);
    (*DAT_00960090)(7,2);
    (*DAT_00960090)(8,1);
    (*DAT_00960090)(10,5);
    (*DAT_00960090)(0xb,6);
    (*DAT_00960090)(9,2);
    (*DAT_00960090)(0xc,1);
    (*DAT_00960090)(1,DAT_007ce6e0);
    (*DAT_00960090)(2,3);
    iVar5 = FUN_00198590_typed();
    fVar7 = *(float *)(iVar5 + 0x80);
    for (iVar5 = 0; iVar5 < 4; iVar5 = iVar5 + 1) {
      *(float *)(pcVar3 + iVar5 * 0x40 + 0x18) = DAT_00960088 - *(float *)(pcVar3 + 0x128);
      *(float *)(pcVar3 + iVar5 * 0x40 + 0x28) = 1.0f / fVar7;
      pcVar1 = pcVar3 + iVar5 * 0x40 + 0x30;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\x7f';
      pcVar1[3] = 'C';
      pcVar1 = pcVar3 + iVar5 * 0x40 + 0x34;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\x7f';
      pcVar1[3] = 'C';
      pcVar1 = pcVar3 + iVar5 * 0x40 + 0x38;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\x7f';
      pcVar1[3] = 'C';
      pcVar1 = pcVar3 + iVar5 * 0x40 + 0x3c;
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\x7f';
      pcVar1[3] = 'C';
    }
    pcVar3[0x20] = '\0';
    pcVar3[0x21] = '\0';
    pcVar3[0x22] = '\0';
    pcVar3[0x23] = '\0';
    pcVar3[0x24] = '\0';
    pcVar3[0x25] = '\0';
    pcVar3[0x26] = '\0';
    pcVar3[0x27] = '\0';
    *(u32 *)(pcVar3 + 0x60) = *(u32 *)(pcVar3 + 0x13c);
    pcVar3[100] = '\0';
    pcVar3[0x65] = '\0';
    pcVar3[0x66] = '\0';
    pcVar3[0x67] = '\0';
    pcVar3[0xa0] = '\0';
    pcVar3[0xa1] = '\0';
    pcVar3[0xa2] = '\0';
    pcVar3[0xa3] = '\0';
    *(u32 *)(pcVar3 + 0xa4) = *(u32 *)(pcVar3 + 0x140);
    *(u32 *)(pcVar3 + 0xe0) = *(u32 *)(pcVar3 + 0x13c);
    *(u32 *)(pcVar3 + 0xe4) = *(u32 *)(pcVar3 + 0x140);
    uVar6 = FUN_00318b60(*(u32 *)(*(int *)(pcVar3 + 0x144) + 0x128));
    uVar4 = FUN_001a5aa0_typed((const void *)(uVar6));
    FUN_004561f0(uVar4,param_1);
    (*DAT_009600a0)(4,pcVar3 + 0x10,4);
  }
  return 0;
}

#pragma pop
// FUN_00456050

void FUN_00456050(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  if (*(int *)(iVar1 + 4) != 0) {
    FUN_00100ec0_arg(*(u32 *)(iVar1 + 4));
    *(u32 *)(iVar1 + 4) = 0;
  }
  if (*(int *)(iVar1 + 8) != 0) {
    FUN_004d0f00_arg(*(u32 *)(iVar1 + 8));
    *(u32 *)(iVar1 + 8) = 0;
  }
  (*DAT_0096017c_task)(*(u32 *)(param_1 + 0x3c));
  return;
}

// FUN_004560D0 NONMATCHING

u64 FUN_004560d0(u32 param_1,float param_2,float param_3,float param_4,u32 param_5,u32 param_6)
{
  int lVar1;
  u32 uVar2;
  u8 *puVar3;

  lVar1 = (*DAT_00960184)(1,0x150,0x40000);
  if (lVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00194b20_u32(param_1,DAT_006b4a60,0x18a6,(u32 (*)(int))FUN_00455e00,FUN_00456050,lVar1);
    puVar3 = (u8 *)lVar1;
    *puVar3 = 0;
    *(float *)(puVar3 + 0x120) = param_2;
    *(float *)(puVar3 + 0x124) = param_3;
    *(u32 *)(puVar3 + 0x118) = param_5;
    *(u32 *)(puVar3 + 0x11c) = param_6;
    *(u32 *)(puVar3 + 0x138) = 0;
    puVar3[0x148] = 0;
    *(float *)(puVar3 + 0x128) = param_4;
    *(float *)(puVar3 + 0x13c) = 0.8125f;
    *(float *)(puVar3 + 0x140) = 0.8125f;
  }
  return uVar2;
}

// FUN_004561D0

void FUN_004561d0(float param_1, float param_2, int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_3 + 0x3c);
  *(float *)(iVar1 + 0x120) = param_1;
  *(float *)(iVar1 + 0x124) = param_2;
  return;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_004561F0 NONMATCHING

void FUN_004561f0(float param_1,int param_2)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  int iVar4;
  u64 uVar5;
  int iVar6;
  u32 *puVar7;
  u32 *puVar8;
  u32 auStack_90 [8];
  float afStack_70 [12];
  u32 auStack_40 [12];
  u64 uStack_10;
  u32 uStack_8;
  
  iVar1 = *(int *)(param_2 + 0x3c);
  uStack_10 = DAT_006b4a78;
  uStack_8 = DAT_006b4a80;
  puVar8 = (u32 *)DAT_006b4a90;
  puVar7 = auStack_90;
  iVar6 = 4;
  do {
    uVar2 = *puVar8;
    uVar3 = puVar8[1];
    puVar8 = puVar8 + 2;
    iVar6 = iVar6 + -1;
    *puVar7 = uVar2;
    puVar7[1] = uVar3;
    puVar7 = puVar7 + 2;
  } while (0 < iVar6);
  for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {
    auStack_40[iVar6 * 3] = auStack_90[iVar6 * 2];
    auStack_40[iVar6 * 3 + 2] = auStack_90[iVar6 * 2 + 1];
    auStack_40[iVar6 * 3 + 1] = 0;
  }
  uVar5 = FUN_004c38c0_typed();
  if (0.0f <= param_1) {
    param_1 = param_1 - 180.0f;
  }
  else {
    param_1 = param_1 + 180.0f;
  }
  FUN_004c31b0_ym(param_1 + *(float *)(iVar1 + 0x138),(void *)(uVar5),(const void *)(&uStack_10),2);
  for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {
    FUN_004c6be0_typed((float *)(afStack_70 + iVar6 * 3),(const float *)(auStack_40 + iVar6 * 3),(void *)(uVar5));
    iVar4 = iVar1 + iVar6 * 0x40;
    *(float *)(iVar4 + 0x10) = *(float *)(iVar1 + 0x120) + afStack_70[iVar6 * 3];
    *(float *)(iVar4 + 0x14) = *(float *)(iVar1 + 0x124) + afStack_70[iVar6 * 3 + 2];
  }
  FUN_004c3880_typed(uVar5);
  return;
}

#pragma pop
// FUN_004563B0

void FUN_004563b0(f32 param_1, int param_2)

{
  *(f32 *)(*(int *)(param_2 + 0x3c) + 0x138) = param_1;
  return;
}

// FUN_004563C0

void FUN_004563c0(int param_1,u8 param_2)

{
  *(u8 *)(*(int *)(param_1 + 0x3c) + 300) = param_2;
  return;
}

// FUN_004563D0

void FUN_004563d0(int object, RwV2d value)
{
    RwV2d* destination = (RwV2d*)(*(int*)(object + 0x3c) + 0x130);

    *destination = value;
}

// FUN_00456400

void FUN_00456400(int param_1,u8 param_2)

{
  *(u8 *)(*(int *)(param_1 + 0x3c) + 0x148) = param_2;
  return;
}

// FUN_00456410

void FUN_00456410(char param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0087190c_abs + param_1 * 0x1c0) + 0x3c);
  *(u8 *)(iVar1 + 0x1260) = 0;
  *(u8 *)(iVar1 + 0x1217) = 1;
  *(u8 *)(iVar1 + 0x1236) = 0;
  return;
}

// FUN_00456450

void FUN_00456450(char param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0087190c_abs + param_1 * 0x1c0) + 0x3c);
  *(u8 *)(iVar1 + 0x1260) = 1;
  *(u8 *)(iVar1 + 0x1217) = 1;
  *(u8 *)(iVar1 + 0x1236) = 0;
  return;
}

// FUN_00456490

void FUN_00456490(char param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0087190c_abs + param_1 * 0x1c0) + 0x3c);
  *(u8 *)(iVar1 + 0x1260) = 2;
  *(u8 *)(iVar1 + 0x1217) = 1;
  *(u8 *)(iVar1 + 0x1236) = 0;
  return;
}

// FUN_004564E0

void FUN_004564e0(char param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0087190c_abs + param_1 * 0x1c0) + 0x3c);
  *(u8 *)(iVar1 + 0x1260) = 3;
  *(u8 *)(iVar1 + 0x1217) = 1;
  *(u8 *)(iVar1 + 0x1236) = 0;
  return;
}

// FUN_00456530

void FUN_00456530(char param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0087190c_abs + param_1 * 0x1c0) + 0x3c);
  *(u8 *)(iVar1 + 0x1260) = 4;
  *(u8 *)(iVar1 + 0x1217) = 1;
  *(u8 *)(iVar1 + 0x1236) = 0;
  return;
}

// FUN_00456580

void FUN_00456580(char param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0087190c_abs + param_1 * 0x1c0) + 0x3c);
  *(u8 *)(iVar1 + 0x1260) = 5;
  *(u8 *)(iVar1 + 0x1217) = 1;
  *(u8 *)(iVar1 + 0x1236) = 0;
  return;
}

// FUN_004565D0

void FUN_004565d0(char param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0087190c_abs + param_1 * 0x1c0) + 0x3c);
  *(u8 *)(iVar1 + 0x1260) = 6;
  *(u8 *)(iVar1 + 0x1217) = 1;
  *(u8 *)(iVar1 + 0x1236) = 0;
  return;
}

// FUN_00456620

void FUN_00456620(char param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0087190c_abs + param_1 * 0x1c0) + 0x3c);
  *(u8 *)(iVar1 + 0x1260) = 7;
  *(u8 *)(iVar1 + 0x1217) = 1;
  *(u8 *)(iVar1 + 0x1236) = 0;
  return;
}

// FUN_00456670 NONMATCHING

void FUN_00456670(u64 param_1,u64 param_2)

{
  u8 bVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  long lVar6;
  u64 uVar7;
  int iVar8;
  char cVar9;
  u16 *puVar10;
  u64 uVar11;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;
  u32 uStack_20;
  u32 uStack_1c;
  u32 uStack_18;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  cVar9 = (char)param_2;
  iVar8 = cVar9 * 0x1c0;
  iVar5 = *(int *)(*(int *)((u8 *)DAT_0087190c + iVar8) + 0x3c);
  cVar2 = *(char *)(iVar5 + 0x123b) + '\x01';
  *(char *)(iVar5 + 0x123b) = cVar2;
  if (cVar2 < '2') {
    FUN_001ad940(&uStack_20,*(u32 *)(((u8 *)DAT_008717f4)[cVar9 * 0x70] + 0x1e0));
    *(u32 *)(iVar5 + 0x123c) = uStack_20;
    *(u32 *)(iVar5 + 0x1240) = uStack_1c;
    *(u32 *)(iVar5 + 0x1244) = uStack_18;
  }
  else {
    *(u8 *)(iVar5 + 0x123b) = 0;
    for (iVar5 = 1; (long)iVar5 < 4; iVar5 = iVar5 + 1) {
      bVar1 = 0;
      if ((((u8 *)DAT_008717e8)[iVar5 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar5 * 0x70] != 0)) {
        bVar1 = 1;
      }
      if ((bVar1) && ((long)iVar5 != (long)cVar9)) {
        cVar2 = FUN_004573d0((char)iVar5);
        if (((long)cVar9 == (long)cVar2) && (cVar2 = FUN_00457390((char)iVar5), cVar2 == '\x03')) {
          return;
        }
      }
    }
    sVar3 = FUN_0043b980(param_2,param_2);
    if (sVar3 != -1) {
      FUN_001ad940(&uStack_30,*(u32 *)(((u8 *)DAT_008717f4)[cVar9 * 0x70] + 0x1e0));
      uStack_10 = uStack_30;
      uStack_c = uStack_2c;
      uStack_8 = uStack_28;
      uVar11 = 0xffffffffffffffff;
      lVar6 = FUN_001c7130(2400.0f,(u32)((u8 *)DAT_008717a0 + cVar9 * 0x1c0));
      uVar7 = 1;
      if (lVar6 == 1) {
        FUN_0010a4e0(1,8,3,1);
        uVar7 = uVar11;
      }
      else {
        uVar11 = 3;
      }
      iVar5 = FUN_001b9120_u32();
      FUN_001a9760_typed((void *)(*(u32 *)(iVar5 + 0x10)),6,(void *)(&uStack_10),uVar11,uVar7);
      sVar3 = FUN_0043b980(param_2,param_2);
      if (sVar3 == 0xca) {
        FUN_0017b860_typed(*(u16 *)((u8 *)DAT_00871948 + cVar9 * 0x1c0),
                     *(u16 *)((u8 *)DAT_00871948 + cVar9 * 0x1c0),0xca,0);
      }
      else if (sVar3 == 0xcb) {
        FUN_0017b860_typed(*(u16 *)((u8 *)DAT_00871948 + cVar9 * 0x1c0),
                     *(u16 *)((u8 *)DAT_00871948 + cVar9 * 0x1c0),0xcb,0);
      }
      sVar4 = FUN_0017b500_ret(*(u16 *)((u8 *)DAT_00871948 + iVar8),sVar3);
      if (sVar4 == 1) {
        puVar10 = (u16 *)((u8 *)DAT_00871948 + cVar9 * 0x1c0);
        sVar4 = FUN_0016c4f0(*puVar10);
        sVar3 = FUN_0017b5b0(*puVar10,sVar3);
        FUN_0016cf40_typed(*puVar10,sVar4 - sVar3);
      }
      else if (sVar4 == 2) {
        puVar10 = (u16 *)((u8 *)DAT_00871948 + cVar9 * 0x1c0);
        sVar4 = FUN_0016c570_typed(*puVar10);
        sVar3 = FUN_0017b5b0(*puVar10,sVar3);
        FUN_0016cf90_typed(*puVar10,sVar4 - sVar3);
      }
      FUN_00457340(param_2,2,param_2);
    }
  }
  return;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00456A90 NONMATCHING

void FUN_00456a90(u32 param_1,char param_2,char param_3) { u8 bVar1;
char cVar2;
short sVar3;
u16 uVar4;
short sVar5;
int iVar6;
long lVar7;
u32 uVar8;
char cVar9;
int iVar10;
char cVar11;
u64 uVar12;
u16 *puVar13;
u32 uStack_40;
u32 uStack_3c;
u32 uStack_38;
u32 uStack_30;
u32 uStack_2c;
u32 uStack_28;
u32 uStack_20;
u32 uStack_1c;
u32 uStack_18;
u32 uStack_10;
u32 uStack_c;
u32 uStack_8;

cVar11 = (char)param_2;
iVar10 = *(int *)(*(int *)((u8 *)DAT_0087190c + cVar11 * 0x1c0) + 0x3c);
cVar2 = *(char *)(iVar10 + 0x123b) + '\x01';
*(char *)(iVar10 + 0x123b) = cVar2;
cVar9 = (char)param_3;
if (cVar2 < '2') {
  FUN_001ad940(&uStack_20,*(u32 *)(((u8 *)DAT_008717f4)[cVar11 * 0x70] + 0x1e0));
  *(u32 *)(iVar10 + 0x123c) = uStack_20;
  *(u32 *)(iVar10 + 0x1240) = uStack_1c;
  *(u32 *)(iVar10 + 0x1244) = uStack_18;
  FUN_001ad940(&uStack_30,*(u32 *)(((u8 *)DAT_008717f4)[cVar9 * 0x70] + 0x1e0));
  *(u32 *)(iVar10 + 0x1248) = uStack_30;
  *(u32 *)(iVar10 + 0x124c) = uStack_2c;
  *(u32 *)(iVar10 + 0x1250) = uStack_28;
}
else {
  *(u8 *)(iVar10 + 0x123b) = 0;
  for (iVar10 = 1; (long)iVar10 < 4; iVar10 = iVar10 + 1) {
    bVar1 = 0;
    if ((((u8 *)DAT_008717e8)[iVar10 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar10 * 0x70] != 0)) {
      bVar1 = 1;
    }
    if ((bVar1) && ((long)iVar10 != (long)cVar11)) {
      cVar2 = FUN_004573d0((char)iVar10);
      if ((cVar9 == cVar2) && (cVar2 = FUN_00457390((char)iVar10), cVar2 == '\x03')) {
        return;
      }
    }
  }
  sVar3 = FUN_0043b980(param_2,param_3);
  if (sVar3 != -1) {
    iVar10 = cVar9 * 0x1c0;
    FUN_001ad940(&uStack_40,*(u32 *)(((u8 *)DAT_008717f4)[cVar9 * 0x70] + 0x1e0));
    uStack_10 = uStack_40;
    uStack_c = uStack_3c;
    uStack_8 = uStack_38;
    uVar12 = 0xffffffffffffffff;
    lVar7 = FUN_001c7130(2400.0f,(u32)((u8 *)DAT_008717a0 + iVar10));
    uVar8 = 1;
    if (lVar7 == 1) {
      FUN_0010a4e0(1,8,3,1);
      uVar8 = uVar12;
    }
    else {
      uVar12 = 3;
    }
    iVar6 = FUN_001b9120_u32();
    FUN_001a9760_typed((void *)(*(u32 *)(iVar6 + 0x10)),6,(void *)(&uStack_10),uVar12,uVar8);
    uVar4 = FUN_0043b980(param_2,param_3);
    FUN_0017b860_typed(*(u16 *)((u8 *)DAT_00871948 + cVar11 * 0x1c0),
                 *(u16 *)((u8 *)DAT_00871948 + iVar10),uVar4,0);
    sVar3 = FUN_0017b500_ret(*(u16 *)((u8 *)DAT_00871948 + cVar11 * 0x1c0),uVar4);
    if (sVar3 == 1) {
      puVar13 = (u16 *)((u8 *)DAT_00871948 + cVar11 * 0x1c0);
      sVar3 = FUN_0016c4f0(*puVar13);
      sVar5 = FUN_0017b5b0(*puVar13,uVar4);
      FUN_0016cf40_typed(*puVar13,sVar3 - sVar5);
    }
    else if (sVar3 == 2) {
      puVar13 = (u16 *)((u8 *)DAT_00871948 + cVar11 * 0x1c0);
      sVar3 = FUN_0016c570_typed(*puVar13);
      sVar5 = FUN_0017b5b0(*puVar13,uVar4);
      FUN_0016cf90_typed(*puVar13,sVar3 - sVar5);
    }
    FUN_00457340(param_2,3,param_3);
  }
}
return; }

#pragma pop
#pragma push
#pragma opt_loop_invariants on
// FUN_00456EA0 NONMATCHING

void FUN_00456ea0(u64 param_1,u64 param_2,u64 param_3)

{
  int iVar1;
  u8 bVar2;
  char cVar3;
  short sVar4;
  u16 uVar5;
  u16 uVar6;
  short sVar7;
  int iVar8;
  long lVar9;
  char cVar10;
  int iVar11;
  u16 *puVar12;
  char cVar13;
  u64 uVar14;
  u64 uVar15;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  cVar13 = (char)param_2;
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0087190c + cVar13 * 0x1c0) + 0x3c);
  iVar11 = 1;
  cVar10 = (char)param_3;
  do {
    if (3 < (long)iVar11) {
      sVar4 = FUN_0043bda0(param_2,param_3);
      if (sVar4 != -1) {
        iVar11 = cVar10 * 0x1c0;
        FUN_001ad940(&fStack_40,*(u32 *)(((u8 *)DAT_008717f4)[cVar10 * 0x70] + 0x1e0));
        fStack_10 = fStack_40;
        fStack_c = fStack_3c;
        fStack_8 = fStack_38;
        uVar14 = 0xffffffffffffffff;
        FUN_00318ed0_typed(*(u32 *)(((u8 *)DAT_008717f4)[cVar10 * 0x70] + 0x128),2,(float *)(&fStack_20));
        fStack_30 = (fStack_20 + fStack_10) / 2.0f;
        fStack_2c = (fStack_1c + fStack_c) / 2.0f;
        fStack_28 = (fStack_18 + fStack_8) / 2.0f;
        lVar9 = FUN_001c7130(2400.0f,(u32)((u8 *)DAT_008717a0 + iVar11));
        if (lVar9 == 1) {
          FUN_0010a4e0(1,8,3,2);
          uVar15 = uVar14;
        }
        else {
          uVar15 = 3;
          uVar14 = 2;
        }
        fStack_2c = fStack_2c - 80.0f;
        iVar8 = FUN_001b9120_u32();
        FUN_001a9760_typed((void *)(*(u32 *)(iVar8 + 0x10)),2,(void *)(&fStack_30),uVar15,uVar14);
        iVar8 = FUN_001b9120_u32();
        if (*(int *)(iVar8 + 0x28) != 0) {
          iVar8 = FUN_001b9120_u32();
          FUN_0018bee0_typed(*(u32 *)(iVar8 + 0x28),*(u16 *)((u8 *)DAT_00871948 + iVar11),0);
        }
        uVar5 = FUN_0043bda0(param_2,*(u8 *)(iVar1 + 0x1226));
        FUN_0017b860_typed(*(u16 *)((u8 *)DAT_00871948 + cVar13 * 0x1c0),
                     *(u16 *)((u8 *)DAT_00871948 + cVar10 * 0x1c0),uVar5,0);
        lVar9 = FUN_002ff790_typed((void *)(((u8 *)DAT_008717e8)[cVar10 * 0x70]));
        if (lVar9 == 0) {
          uVar6 = FUN_001dde00_typed(*(u16 *)((u8 *)DAT_00871948 + cVar10 * 0x1c0));
          FUN_003182d0(((u8 *)DAT_008717f0)[cVar10 * 0x70],0,uVar6,0,1);
        }
        sVar4 = FUN_0017b500_ret(*(u16 *)((u8 *)DAT_00871948 + cVar13 * 0x1c0),uVar5);
        if (sVar4 == 1) {
          puVar12 = (u16 *)((u8 *)DAT_00871948 + cVar13 * 0x1c0);
          sVar4 = FUN_0016c4f0(*puVar12);
          sVar7 = FUN_0017b5b0(*puVar12,uVar5);
          FUN_0016cf40_typed(*puVar12,sVar4 - sVar7);
        }
        else if (sVar4 == 2) {
          puVar12 = (u16 *)((u8 *)DAT_00871948 + cVar13 * 0x1c0);
          sVar4 = FUN_0016c570_typed(*puVar12);
          sVar7 = FUN_0017b5b0(*puVar12,uVar5);
          FUN_0016cf90_typed(*puVar12,sVar4 - sVar7);
        }
        FUN_00457340(param_2,4,param_3);
      }
      return;
    }
    bVar2 = 0;
    if ((((u8 *)DAT_008717e8)[iVar11 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar11 * 0x70] != 0)) {
      bVar2 = 1;
    }
    if ((bVar2) && ((long)iVar11 != (long)cVar13)) {
      cVar3 = FUN_004573d0((char)iVar11);
      if ((cVar10 == cVar3) && (cVar3 = FUN_00457390((char)iVar11), cVar3 == '\x04')) {
        return;
      }
    }
    iVar11 = iVar11 + 1;
  } while( 1 );
}

#pragma pop
// FUN_00457340

void FUN_00457340(char param_1,u8 param_2,char param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)((u8 *)DAT_0087190c_abs + param_1 * 0x1c0) + 0x3c);
  *(u8 *)(iVar1 + 0x1238) = 1;
  *(u8 *)(iVar1 + 0x1237) = 0;
  *(u8 *)(iVar1 + 0x1239) = param_2;
  *(short *)(iVar1 + 0x1226) = (short)param_3;
  return;
}

// FUN_00457390

char FUN_00457390(char param_1)

{
  return *(char *)(*(int *)(*(int *)((u8 *)DAT_0087190c_abs + param_1 * 0x1c0) + 0x3c) + 0x1239);
}

// FUN_004573D0

char FUN_004573d0(char param_1)

{
  return *(char *)(*(int *)(*(int *)((u8 *)DAT_0087190c_abs + param_1 * 0x1c0) + 0x3c) + 0x1226);
}

// FUN_00457410

int FUN_00457410(void)

{
  int result;
  int index;
  u8 *base;
  int *entry;
  
  result = 0;
  index = 0;
  base = (u8 *)DAT_0086e6a0;
  while (index < 4) {
    entry = (int *)(base + index * 0x1c0);
    if (entry[0x12] == 0) {
      result = (int)entry;
      break;
    }
    index = index + 1;
  }
  return result;
}

// FUN_00457470 NONMATCHING

u32 FUN_00457470(int param_1)

{
  u16 uVar1;
  u32 uVar2;
  long lVar3;
  int iVar4;
  u64 uStack_10;
  u32 uStack_8;
  
  uStack_10 = DAT_006b4b20;
  uStack_8 = DAT_006b4b28;
  iVar4 = param_1 * 0x1c0;
  if (*(int *)((u8 *)DAT_0086e6e8 + iVar4) == 0) {
    uVar2 = 1;
  }
  else if (*(int *)((u8 *)DAT_0086e6f4 + iVar4) == 0) {
    lVar3 = FUN_00316f70_typed(*(u32 *)((u8 *)DAT_0086e6f0 + iVar4));
    if (lVar3 == 0) {
      uVar2 = 0;
    }
    else {
      uVar1 = FUN_003b6030_typed(param_1 + 10U & 0xffff,0,(void *)(*(u32 *)((u8 *)DAT_0086e6f0 + iVar4)));
      uVar2 = FUN_003b5d10_eb90(uVar1);
      *(u32 *)((u8 *)DAT_0086e6f4 + iVar4) = uVar2;
      FUN_003182d0(*(u32 *)((u8 *)DAT_0086e6f0 + iVar4),0,0,0x10,1);
      ((code)FUN_001adff0)(*(u32 *)(*(int *)((u8 *)DAT_0086e808 + iVar4) + 0x10c),
                   *(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar4) + 0x1e0),&uStack_10);
      FUN_001adc20_typed((void *)(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar4) + 0x1e0)),(const void *)(*(int *)((u8 *)DAT_0086e808 + iVar4) + 0x100));
      FUN_001a0dc0_typed(**(u16 **)((u8 *)DAT_0086e6f4 + iVar4),1);
      FUN_001ad870_typed((void *)(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar4) + 0x1e0)),2.0f);
      uVar2 = (u32)FUN_001af930_typed((void *)(0),(void *)(*(u32 *)((u8 *)DAT_0086e6f4 + iVar4)));
      *(u32 *)((u8 *)DAT_0086e810 + iVar4) = uVar2;
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}

// FUN_004575E0 NONMATCHING

u32 FUN_004575e0(int param_1)

{
  u8 *puVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u64 uVar5;
  long lVar6;
  int iVar7;
  
  puVar1 = *(u8 **)(param_1 + 0x3c);
  switch(*puVar1) {
  case 0:
    *puVar1 = 1;
    break;
  case 1:
    uVar2 = FUN_003b5d10_eb90(0x3c00);
    lVar6 = FUN_00457410();
    if (lVar6 != 0) {
      uVar3 = (u32)FUN_002ff340_typed(2);
      iVar7 = (int)lVar6;
      *(u32 *)(iVar7 + 0x48) = uVar3;
      uVar5 = FUN_00316e00_typed(9,0x201,0);
      FUN_0031c1d0_typed(uVar5);
      *(int *)(iVar7 + 0x50) = (int)uVar5;
      *(u16 *)(iVar7 + 0x1a8) = 2;
      uVar4 = FUN_00173300();
      *(u32 *)(iVar7 + 0x184) = uVar4 & 0xff;
      *(u32 *)(iVar7 + 0x168) = uVar2;
    }
    *puVar1 = 2;
  case 2:
    lVar6 = FUN_00457470(0);
    if (lVar6 == 1) {
      DAT_0086e80c = FUN_00458630(0,0,0);
      *puVar1 = 3;
    }
    break;
  case 3:
    uVar2 = FUN_003b5d10_eb90(0x4400);
    lVar6 = FUN_00457410();
    if (lVar6 != 0) {
      uVar3 = (u32)FUN_002ff340_typed(4);
      iVar7 = (int)lVar6;
      *(u32 *)(iVar7 + 0x48) = uVar3;
      uVar5 = FUN_00316e00_typed(9,0x400,0);
      FUN_0031c1d0_typed(uVar5);
      *(int *)(iVar7 + 0x50) = (int)uVar5;
      *(u16 *)(iVar7 + 0x1a8) = 4;
      uVar4 = FUN_00173300();
      *(u32 *)(iVar7 + 0x184) = uVar4 & 0xff;
      *(u32 *)(iVar7 + 0x168) = uVar2;
    }
    *puVar1 = 4;
  case 4:
    lVar6 = FUN_00457470(1);
    if (lVar6 == 1) {
      DAT_0086e9cc = FUN_00458630(0,1,2);
      *puVar1 = 5;
    }
    break;
  case 5:
    uVar2 = FUN_003b5d10_eb90(0x4000);
    lVar6 = FUN_00457410();
    if (lVar6 != 0) {
      uVar3 = (u32)FUN_002ff340_typed(6);
      iVar7 = (int)lVar6;
      *(u32 *)(iVar7 + 0x48) = uVar3;
      uVar5 = FUN_00316e00_typed(9,0x600,0);
      FUN_0031c1d0_typed(uVar5);
      *(int *)(iVar7 + 0x50) = (int)uVar5;
      *(u16 *)(iVar7 + 0x1a8) = 6;
      uVar4 = FUN_00173300();
      *(u32 *)(iVar7 + 0x184) = uVar4 & 0xff;
      *(u32 *)(iVar7 + 0x168) = uVar2;
    }
    *puVar1 = 6;
  case 6:
    lVar6 = FUN_00457470(2);
    if (lVar6 == 1) {
      DAT_0086eb8c = FUN_00458630(0,2,2);
      *puVar1 = 7;
    }
    break;
  case 7:
    uVar2 = FUN_003b5d10_eb90(0x4401);
    lVar6 = FUN_00457410();
    if (lVar6 != 0) {
      uVar3 = (u32)FUN_002ff340_typed(3);
      iVar7 = (int)lVar6;
      *(u32 *)(iVar7 + 0x48) = uVar3;
      uVar5 = FUN_00316e00_typed(9,0x300,0);
      FUN_0031c1d0_typed(uVar5);
      *(int *)(iVar7 + 0x50) = (int)uVar5;
      *(u16 *)(iVar7 + 0x1a8) = 3;
      uVar4 = FUN_00173300();
      *(u32 *)(iVar7 + 0x184) = uVar4 & 0xff;
      *(u32 *)(iVar7 + 0x168) = uVar2;
    }
    *puVar1 = 8;
    break;
  case 8:
    lVar6 = FUN_00457470(3);
    if (lVar6 == 1) {
      DAT_0086ed4c = FUN_00458630(0,3,2);
      *puVar1 = 9;
    }
    break;
  case 9:
    return 0xffffffff;
  }
  return 0;
}

// FUN_00457980

void FUN_00457980(int param_1)

{
  DAT_0096017c_abs[0](*(u32 *)(param_1 + 0x3c));
  return;
}

// FUN_004579B0

u32 FUN_004579b0(u64 param_1)

{
  u32 lVar1;
  u32 uVar2;
  
  lVar1 = (*DAT_00960184_abs)(1,1,0x40000);
  if (lVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00194b80_u32(param_1,10,DAT_006b4b30,FUN_004575e0,FUN_00457980,lVar1);
    *(u8 *)lVar1 = 0;
  }
  return uVar2;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00457A40 NONMATCHING

u64 FUN_00457a40(u64 param_1)

{
  char cVar1;
  char cVar2;
  u8 *puVar3;
  u32 uVar4;
  int iVar5;
  long lVar6;
  int iVar7;
  int iVar8;
  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;
  
  puVar3 = *(u8 **)((int)param_1 + 0x3c);
  cVar1 = puVar3[2];
  iVar7 = cVar1 * 0x1c0;
  iVar8 = cVar1 * 0x1c;
  if (puVar3[8] != '\x01') {
    cVar2 = puVar3[7];
    if (cVar2 == '\x01') {
      FUN_00195460(*(u32 *)(puVar3 + 0x10));
    }
    else if (cVar2 == '\x02') {
      lVar6 = FUN_00458cb0(param_1,cVar1,0);
      if ((lVar6 != 1) && (lVar6 = FUN_00195460(*(u32 *)(puVar3 + 0x10)), lVar6 == 0)) {
        *(u32 *)(puVar3 + 0x10) = 0;
        FUN_001b0020_typed((u32)(*(u32 *)((u8 *)DAT_0086e810 + iVar7)),(void*)(puVar3 + 0x1c),(s32)(*(u16 *)((u8 *)DAT_006b4ac6 + iVar8)));
        puVar3[7] = 3;
        if (*(int *)(puVar3 + 0x10) != 0) {
          *(u32 *)(puVar3 + 0x10) = 0;
        }
        uVar4 = FUN_00459f60(param_1,*(u16 *)((u8 *)DAT_006b4ac6 + iVar8),0);
        *(u32 *)(puVar3 + 0x10) = uVar4;
      }
    }
    else if (cVar2 == '\x03') {
      lVar6 = FUN_00458cb0(param_1,cVar1,0);
      if ((lVar6 != 1) && (lVar6 = FUN_00195460(*(u32 *)(puVar3 + 0x10)), lVar6 == 0)) {
        *(u32 *)(puVar3 + 0x10) = 0;
        puVar3[7] = 4;
        if (*(int *)(puVar3 + 0x10) != 0) {
          *(u32 *)(puVar3 + 0x10) = 0;
        }
        uVar4 = FUN_00459f60(param_1,*(u16 *)((u8 *)DAT_006b4ac8 + iVar8),0);
        *(u32 *)(puVar3 + 0x10) = uVar4;
      }
    }
    else if (cVar2 == '\x04') {
      lVar6 = FUN_00458cb0(param_1,cVar1,0);
      if ((lVar6 != 1) && (lVar6 = FUN_00195460(*(u32 *)(puVar3 + 0x10)), lVar6 == 0)) {
        *(u32 *)(puVar3 + 0x10) = 0;
        FUN_003bb010_typed(**(u16 **)((u8 *)DAT_0086e6f4 + iVar7),2);
        puVar3[7] = 5;
        if (*(int *)(puVar3 + 0x10) != 0) {
          *(u32 *)(puVar3 + 0x10) = 0;
        }
        uVar4 = FUN_00459f60(param_1,*(u16 *)((u8 *)DAT_006b4ac8 + iVar8),0);
        *(u32 *)(puVar3 + 0x10) = uVar4;
      }
    }
    else if (cVar2 == '\x05') {
      lVar6 = FUN_00458cb0(param_1,cVar1,0);
      if ((lVar6 != 1) && (lVar6 = FUN_00195460(*(u32 *)(puVar3 + 0x10)), lVar6 == 0)) {
        *(u32 *)(puVar3 + 0x10) = 0;
        puVar3[7] = 6;
        if (*(int *)(puVar3 + 0x10) != 0) {
          *(u32 *)(puVar3 + 0x10) = 0;
        }
        uVar4 = FUN_00459f60(param_1,*(u16 *)((u8 *)DAT_006b4ac4 + iVar8),0);
        *(u32 *)(puVar3 + 0x10) = uVar4;
      }
    }
    else if (cVar2 == '\x06') {
      lVar6 = FUN_00458cb0(param_1,cVar1,0);
      if ((lVar6 != 1) && (lVar6 = FUN_00195460(*(u32 *)(puVar3 + 0x10)), lVar6 == 0)) {
        if (puVar3[2] == '\x01') {
          iVar5 = FUN_003b5d10_eb90(0x4402);
          uStack_10 = *(u32 *)(iVar5 + 0x100);
          uStack_c = *(u32 *)(iVar5 + 0x104);
          uStack_8 = *(u32 *)(iVar5 + 0x108);
          FUN_001b0020_typed((u32)(*(u32 *)((u8 *)DAT_0086e810 + iVar7)),(void*)(&uStack_10),(s32)(*(u16 *)((u8 *)DAT_006b4ac6 + iVar8)));
        }
        else if (puVar3[2] == '\x03') {
          iVar5 = FUN_003b5d10_eb90(0x4403);
          uStack_10 = *(u32 *)(iVar5 + 0x100);
          uStack_c = *(u32 *)(iVar5 + 0x104);
          uStack_8 = *(u32 *)(iVar5 + 0x108);
          FUN_001b0020_typed((u32)(*(u32 *)((u8 *)DAT_0086e810 + iVar7)),(void*)(&uStack_10),(s32)(*(u16 *)((u8 *)DAT_006b4ac6 + iVar8)));
        }
        else {
          FUN_001b0020_typed((u32)(*(u32 *)((u8 *)DAT_0086e810 + iVar7)),(void*)(puVar3 + 0x30),(s32)(*(u16 *)((u8 *)DAT_006b4ac6 + iVar8)));
        }
        puVar3[7] = 7;
        if (*(int *)(puVar3 + 0x10) != 0) {
          *(u32 *)(puVar3 + 0x10) = 0;
        }
        uVar4 = FUN_00459f60(param_1,*(u16 *)((u8 *)DAT_006b4ac6 + iVar8),0);
        *(u32 *)(puVar3 + 0x10) = uVar4;
      }
    }
    else if (cVar2 == '\a') {
      lVar6 = FUN_00458cb0(param_1,cVar1,0);
      if ((lVar6 != 1) && (lVar6 = FUN_00195460(*(u32 *)(puVar3 + 0x10)), lVar6 == 0)) {
        *(u32 *)(puVar3 + 0x10) = 0;
        for (lVar6 = 0; lVar6 < *(short *)(puVar3 + 0x28); lVar6 = (long)((int)lVar6 + 1)) {
          FUN_001b01d0_typed((void *)(*(u32 *)((u8 *)DAT_0086e810 + iVar7)),lVar6,(const void *)(puVar3 + (int)lVar6 * 0x18 + 0x2c));
        }
        FUN_001b0230_typed((void *)(*(u32 *)((u8 *)DAT_0086e810 + iVar7)),(s32)lVar6);
        FUN_001b0260(*(u32 *)((u8 *)DAT_0086e810 + iVar7),1);
        lVar6 = FUN_00459e00(puVar3[2]);
        if (lVar6 == 1) {
          for (iVar7 = 0; iVar7 < 4; iVar7 = iVar7 + 1) {
            FUN_001b0260(*(u32 *)((u8 *)DAT_0086e810 + iVar7 * 0x1c0),0);
            FUN_00458920(((u8 *)DAT_0086e80c)[iVar7 * 0x70]);
          }
        }
        else {
          puVar3[7] = 8;
        }
      }
    }
    else if (cVar2 == '\b') {
      FUN_00459790(param_1,cVar1);
    }
    else if ((*(int *)(puVar3 + 0xc) != 0) || (lVar6 = FUN_00458cb0(param_1,cVar1,0), lVar6 != 1)) {
      switch(*puVar3) {
      case 1:
        if (puVar3[1] != '\x02') {
          *(u16 *)(puVar3 + 4) = 0;
          FUN_001b0240(*(u32 *)((u8 *)DAT_0086e810 + iVar7),1);
          *puVar3 = 2;
        }
        break;
      case 2:
        cVar1 = puVar3[2];
        if (cVar1 != '\x03') {
          if (cVar1 == '\x02') {
            lVar6 = FUN_003b5d10_eb90(*(u16 *)(puVar3 + 4) & 0x3ff | 0x4000);
            if (lVar6 != 0) {
              if (puVar3[0x14] == '\x01') {
                lVar6 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086e810 + iVar7));
                if (lVar6 == 0) {
                  if (*(short *)(puVar3 + 0x16) < 0x3c) {
                    *(short *)(puVar3 + 0x16) = *(short *)(puVar3 + 0x16) + 1;
                  }
                  else {
                    puVar3[0x14] = 0;
                  }
                }
              }
              else {
                iVar8 = FUN_003b5d10_eb90(*(u16 *)(puVar3 + 4) & 0x3ff | 0x4000);
                uStack_10 = *(u32 *)(iVar8 + 0x100);
                uStack_c = *(u32 *)(iVar8 + 0x104);
                uStack_8 = *(u32 *)(iVar8 + 0x108);
                FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086e810 + iVar7),5);
                lVar6 = FUN_001afa20_typed(((float)*(int *)((u8 *)DAT_007bc6b0 + (char)puVar3[6] * 4)),(void*)(*(u32 *)((u8 *)DAT_0086e810 + iVar7)),(void*)(&uStack_10));
                if (lVar6 != 0) {
                  *(short *)(puVar3 + 0x18) = *(short *)(puVar3 + 0x18) + 1;
                  lVar6 = FUN_00458a80(puVar3[2],puVar3[4]);
                  if (lVar6 == 1) {
                    puVar3[0x14] = 1;
                    *(u16 *)(puVar3 + 0x16) = 0;
                  }
                  *(short *)(puVar3 + 4) = *(short *)(puVar3 + 4) + 1;
                }
              }
            }
          }
          else if (((cVar1 != '\x01') && (cVar1 == '\0')) &&
                  (lVar6 = FUN_003b5d10_eb90(*(u16 *)(puVar3 + 4) & 0x3ff | 0x3c00), lVar6 != 0)) {
            if (puVar3[0x14] == '\x01') {
              lVar6 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086e810 + iVar7));
              if (lVar6 == 0) {
                if (*(short *)(puVar3 + 0x16) < 0x3c) {
                  *(short *)(puVar3 + 0x16) = *(short *)(puVar3 + 0x16) + 1;
                }
                else {
                  puVar3[0x14] = 0;
                }
              }
            }
            else {
              iVar8 = FUN_003b5d10_eb90(*(u16 *)(puVar3 + 4) & 0x3ff | 0x3c00);
              uStack_10 = *(u32 *)(iVar8 + 0x100);
              uStack_c = *(u32 *)(iVar8 + 0x104);
              uStack_8 = *(u32 *)(iVar8 + 0x108);
              FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086e810 + iVar7),5);
              lVar6 = FUN_001afa20_typed(((float)*(int *)((u8 *)DAT_007bc6b0 + (char)puVar3[6] * 4)),(void*)(*(u32 *)((u8 *)DAT_0086e810 + iVar7)),(void*)(&uStack_10));
              if (lVar6 != 0) {
                lVar6 = FUN_00458a80(puVar3[2],puVar3[4]);
                if (lVar6 == 1) {
                  puVar3[0x14] = 1;
                  *(u16 *)(puVar3 + 0x16) = 0;
                }
                *(short *)(puVar3 + 4) = *(short *)(puVar3 + 4) + 1;
              }
            }
          }
        }
        if (puVar3[6] == '\x02') {
          if (0x1f < *(short *)(puVar3 + 4)) {
            *puVar3 = 3;
          }
        }
        else if ((long)(((char)puVar3[6] + 1) * 8) <= (long)*(short *)(puVar3 + 4)) {
          *puVar3 = 3;
        }
        break;
      case 3:
        if ((puVar3[2] == '\0') && (lVar6 = FUN_004589e0(), lVar6 == 1)) {
          if (*(int *)(puVar3 + 0xc) != 0) {
            *(u32 *)(puVar3 + 0xc) = 0;
          }
          if (puVar3[6] == '\x02') {
            FUN_00459d60();
            for (iVar7 = 0; iVar7 < 4; iVar7 = iVar7 + 1) {
              FUN_001b0260(*(u32 *)((u8 *)DAT_0086e810 + iVar7 * 0x1c0),1);
              FUN_00458870(((u8 *)DAT_0086e80c)[iVar7 * 0x70]);
            }
            if (*(int *)(puVar3 + 0xc) != 0) {
              *(u32 *)(puVar3 + 0xc) = 0;
            }
            iVar7 = FUN_001b9120_u32();
            iVar8 = FUN_001b9120_u32();
            uVar4 = FUN_0035bc00_u32(10,*(u32 *)(iVar7 + 0x1048),*(u32 *)(iVar8 + 0x104c),
                                 (char)puVar3[6] + 0x11);
            *(u32 *)(puVar3 + 0xc) = uVar4;
            iVar7 = FUN_001b9120_u32();
            FUN_001e1360(*(u32 *)(iVar7 + 0xc),1);
            iVar7 = FUN_001b9120_u32();
            FUN_001d3810(*(u32 *)(iVar7 + 0x24),1);
            iVar7 = FUN_001b9120_u32();
            FUN_001cd670(*(u32 *)(iVar7 + 8),1);
            *puVar3 = 5;
          }
          else {
            lVar6 = 0;
            while (lVar6 < 4) {
              iVar7 = (int)lVar6;
              if ((char)puVar3[2] != lVar6) {
                FUN_001b0260(*(u32 *)((u8 *)DAT_0086e810 + iVar7 * 0x1c0),1);
                FUN_004589d0(((u8 *)DAT_0086e80c)[iVar7 * 0x70],1);
              }
              lVar6 = (long)(iVar7 + 1);
            }
            iVar7 = FUN_001b9120_u32();
            uVar4 = FUN_0035bb40_typed(10,*(u32 *)(iVar7 + 0x1048),(char)puVar3[6] + 0x11);
            *(u32 *)(puVar3 + 0xc) = uVar4;
            iVar7 = FUN_001b9120_u32();
            FUN_001e1360(*(u32 *)(iVar7 + 0xc),1);
            iVar7 = FUN_001b9120_u32();
            FUN_001d3810(*(u32 *)(iVar7 + 0x24),1);
            iVar7 = FUN_001b9120_u32();
            FUN_001cd670(*(u32 *)(iVar7 + 8),1);
            *puVar3 = 4;
          }
        }
        break;
      case 4:
        lVar6 = FUN_00195460(*(u32 *)(puVar3 + 0xc));
        if (lVar6 == 0) {
          *(u32 *)(puVar3 + 0xc) = 0;
          iVar7 = FUN_001b9120_u32();
          FUN_001e1360(*(u32 *)(iVar7 + 0xc),0);
          iVar7 = FUN_001b9120_u32();
          FUN_001d3810(*(u32 *)(iVar7 + 0x24),0);
          iVar7 = FUN_001b9120_u32();
          FUN_001cd670(*(u32 *)(iVar7 + 8),0);
          if (puVar3[6] == '\x02') {
            FUN_00458b60();
          }
          else {
            FUN_00458b00();
            lVar6 = 0;
            while (lVar6 < 4) {
              iVar7 = (int)lVar6;
              if ((char)puVar3[2] != lVar6) {
                FUN_001b0260(*(u32 *)((u8 *)DAT_0086e810 + iVar7 * 0x1c0),0);
                FUN_004589d0(((u8 *)DAT_0086e80c)[iVar7 * 0x70],0);
              }
              lVar6 = (long)(iVar7 + 1);
            }
          }
        }
      }
    }
  }
  return 0;
}

#pragma pop
// FUN_00458600

void FUN_00458600(int param_1)

{
  DAT_0096017c_abs[0](*(u32 *)(param_1 + 0x3c));
  return;
}

// FUN_00458630 NONMATCHING

u64 FUN_00458630(u64 param_1,char param_2,u8 param_3)

{
  int lVar1;
  u64 uVar2;
  u64 uVar3;
  int iVar4;
  int iVar5;
  u8 *puVar6;
  u32 uStack_18;
  u32 uStack_14;
  u32 uStack_10;
  u8 uStack_8;
  u8 uStack_7;
  u8 uStack_6;
  u8 uStack_5;
  u8 uStack_4;
  u8 uStack_3;
  u8 uStack_2;
  u8 uStack_1;
  
  iVar4 = param_2 * 0x1c0;
  iVar5 = param_2 * 0x1c;
  lVar1 = (*DAT_00960184)(1,0x4b4,0x40000);
  if (lVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00194b80_u32(param_1,10,DAT_006b4b50,(u32 (*)(int))FUN_00457a40,FUN_00458600,lVar1);
    puVar6 = (u8 *)lVar1;
    *puVar6 = 0;
    puVar6[1] = param_3;
    puVar6[2] = param_2;
    puVar6[6] = 0;
    puVar6[7] = 0;
    puVar6[0x14] = 0;
    *(u16 *)(puVar6 + 0x16) = 0;
    *(u32 *)(puVar6 + 0x10) = 0;
    *(u16 *)(puVar6 + 0x18) = 0;
    puVar6[8] = 0;
    *(float *)&uStack_14 = 50.0f;
    uStack_10 = 0;
    uStack_18 = 0;
    uStack_4 = 0xff;
    uStack_3 = 0;
    uStack_2 = 0;
    uStack_1 = 0x80;
    uStack_8 = 0;
    uStack_7 = 0xff;
    uStack_6 = 0;
    uStack_5 = 0x80;
    uVar3 = FUN_001a5320_typed(uVar2);
    *(int *)(puVar6 + 0x4ac) = (int)uVar3;
    FUN_001a56c0_typed(uVar3,*(u32 *)((u8 *)DAT_0086e6f0 + iVar4));
    FUN_001a5700_typed(*(u32 *)(puVar6 + 0x4ac),(void *)(&uStack_4));
    FUN_001a56d0_typed(*(u32 *)(puVar6 + 0x4ac),(void *)(&uStack_18));
    FUN_001a57a0_typed(*(u32 *)((u8 *)DAT_006b4ab8 + iVar5),*(u32 *)((u8 *)DAT_006b4ab4 + iVar5),
                 *(u32 *)(puVar6 + 0x4ac));
    FUN_001a56b0_typed(*(u32 *)(puVar6 + 0x4ac),0);
    uVar3 = FUN_001a5320_typed(uVar2);
    *(int *)(puVar6 + 0x4b0) = (int)uVar3;
    FUN_001a56c0_typed(uVar3,*(u32 *)((u8 *)DAT_0086e6f0 + iVar4));
    FUN_001a5700_typed(*(u32 *)(puVar6 + 0x4b0),(void *)(&uStack_8));
    FUN_001a56d0_typed(*(u32 *)(puVar6 + 0x4b0),(void *)(&uStack_18));
    FUN_001a57a0_typed(360.0f,*(u32 *)((u8 *)DAT_006b4ab0 + iVar5),*(u32 *)(puVar6 + 0x4b0));
    FUN_001a56b0_typed(*(u32 *)(puVar6 + 0x4b0),0);
  }
  return uVar2;
}

// FUN_00458850

void FUN_00458850(int param_1)

{
  **(u8 **)(param_1 + 0x3c) = 1;
  return;
}

// FUN_00458870

void FUN_00458870(int param_1)

{
  *(u8 *)(*(int *)(param_1 + 0x3c) + 7) = 1;
  return;
}

// FUN_00458890

void FUN_00458890(void)
{
  int iVar1;
  u8 *row;

  for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
    row = DAT_0086e6e8_abs + iVar1 * 0x1c0;
    if (*(int *)(row + 0x48) != 0) {
      FUN_001b0260(*(u32 *)(row + 0x170),1);
      FUN_004589d0(*(u32 *)(row + 0x16c),1);
    }
  }
}

// FUN_00458920

void FUN_00458920(int param_1)

{
  *(u8 *)(*(int *)(param_1 + 0x3c) + 7) = 0;
  return;
}

// FUN_00458930

void FUN_00458930(void)
{
  u8 *row;
  int iVar1;

  for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
    row = DAT_0086e6e8_abs + iVar1 * 0x1c0;
    if (*(int *)(row + 0x48) != 0) {
      if (*(char *)(*(int *)(*(int *)(row + 0x16c) + 0x3c) + 7) != '\b') {
        FUN_001b0260(*(u32 *)(row + 0x170),0);
      }
      FUN_004589d0(*(u32 *)(row + 0x16c),0);
    }
  }
}

// FUN_004589D0

void FUN_004589d0(int param_1,u8 param_2)

{
  *(u8 *)(*(int *)(param_1 + 0x3c) + 8) = param_2;
  return;
}

// FUN_004589E0

u32 FUN_004589e0(void)
{
  long lVar1;
  int iVar2;
  u8 *row;

  for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
    row = DAT_0086e6a0_rows[iVar2];
    lVar1 = FUN_001b0220(*(u32 *)(row + 0x170));
    if (lVar1 != 0) {
      return 0;
    }
    if (*(char *)(*(int *)(*(int *)(row + 0x16c) + 0x3c) + 7) > 0) {
      return 0;
    }
  }
  return 1;
}

// FUN_00458A80

#pragma push
#pragma opt_loop_invariants on
u32 FUN_00458a80(char param_1,char param_2)
{
  int iVar1;
  int iVar2;
  iVar2 = 0;
  iVar1 = (int)(DAT_007bc610 + param_1 * 10);
  do {
    if ((long)param_2 == (long)*(int *)(iVar1 + iVar2 * 4)) {
      return 1;
    }
    iVar2 = iVar2 + 1;
  } while (*(int *)(iVar1 + iVar2 * 4) != -1);
  return 0;
}
#pragma pop
#pragma opt_loop_invariants on
// FUN_00458B00

void FUN_00458b00(void)
{
  u8 *puVar1;
  int iVar2;
  
  for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
    puVar1 = *(u8 **)((u8 *)DAT_0086e6a0_rows[iVar2] + 0x16c);
    puVar1 = *(u8 **)(puVar1 + 0x3c);
    *(s8 *)(puVar1 + 6) = *(s8 *)(puVar1 + 6) + 1;
    *puVar1 = 2;
  }
  return;
}
// FUN_00458B60
#pragma push
#pragma opt_loop_invariants on

void FUN_00458b60(void)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
    **(u8 **)(*(int *)(DAT_0086e6a0 + iVar1 * 0x1c0 + 0x16c) + 0x3c) = 6;
  }
  return;
}
#pragma pop

#pragma alias FUN_002ff760_y2 FUN_002ff760
#pragma alias FUN_003174e0_y2 FUN_003174e0
#pragma alias FUN_003b7090_y2 FUN_003b7090
#pragma alias FUN_00195020_y2 FUN_00195020
extern void FUN_002ff760_y2(u32 param_1);
extern void FUN_003174e0_y2(u32 param_1);
extern void FUN_003b7090_y2(u32 param_1);
#pragma alias FUN_00195020_call2 FUN_00195020
extern void FUN_00195020_call2(u32 param_1);
#pragma push
#pragma opt_rebuildconditionals off
// FUN_00458BB0
void FUN_00458bb0(void)
{
  int bVar2;
  int iVar3;
  u8 *field50;
  u32 field54;
  u8 *field16c;
  u8 *field170;
  u8 *row;

  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
    bVar2 = 0;
    row = DAT_0086e6a0_rows[iVar3];
    if ((*(int *)(row + 0x48) != 0) && (*(int *)(row + 0x54) != 0)) {
      bVar2 = 1;
    }
    bVar2 = bVar2 != 0;
    if (bVar2 == 1) {
      FUN_002ff760_y2(*(u32 *)(row + 0x48));
      field50 = *(u8 **)(row + 0x50);
      if (field50 != (u8 *)0) {
        FUN_003174e0_y2((u32)field50);
      }
      field54 = *(u32 *)(row + 0x54);
      if (field54 != 0) {
        FUN_003b7090_y2(**(u16 **)(row + 0x54));
      }
      field170 = *(u8 **)(row + 0x170);
      if (field170 != (u8 *)0) {
        FUN_00195020_call2((u32)field170);
      }
      field16c = *(u8 **)(row + 0x16c);
      if (field16c != (u8 *)0) {
        FUN_00195020_call2((u32)field16c);
      }
      *(u32 *)(row + 0x50) = 0;
      *(u32 *)(row + 0x54) = 0;
      *(u32 *)(row + 0x16c) = 0;
      *(u32 *)(row + 0x170) = 0;
      *(u32 *)(row + 0x48) = 0;
    }
  }
}
#pragma pop

// FUN_00458CB0 NONMATCHING

u32 FUN_00458cb0(u64 param_1,char param_2,char param_3)

{
  char cVar1;
  int iVar2;
  u16 uVar3;
  short sVar4;
  int iVar5;
  u32 uVar6;
  int iVar7;
  long lVar8;
  u64 uVar9;
  int iVar10;
  int iVar11;
  u8 bVar12;
  int *piVar13;
  long lVar14;
  u64 unaff_s5;
  int iVar15;
  u32 uVar16;
  u32 uStack_70;
  u32 uStack_6c;
  u32 uStack_68;
  u8 auStack_60 [16];
  u32 uStack_50;
  u32 uStack_4c;
  u32 uStack_48;
  u8 auStack_40 [16];
  u8 auStack_30 [16];
  u8 auStack_20 [16];
  u8 auStack_10 [16];
  
  lVar14 = (long)param_2;
  iVar7 = (int)param_2;
  iVar10 = iVar7 * 0x1c;
  bVar12 = 0;
  iVar11 = iVar7 * 0x1c0;
  if ((*(int *)((u8 *)DAT_0086e6e8 + iVar11) != 0) && (*(int *)((u8 *)DAT_0086e6f4 + iVar11) != 0)) {
    bVar12 = 1;
  }
  if (bVar12) {
    for (iVar15 = 0; iVar15 < 4; iVar15 = iVar15 + 1) {
      bVar12 = 0;
      if ((((u8 *)DAT_008717e8)[iVar15 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar15 * 0x70] != 0)) {
        bVar12 = 1;
      }
      if (bVar12) {
        iVar2 = *(int *)(((u8 *)DAT_0086e80c)[iVar7 * 0x70] + 0x3c);
        piVar13 = (int *)((u8 *)DAT_008717f4 + iVar15 * 0x70);
        iVar5 = FUN_00318b60(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar11) + 0x128));
        FUN_001ad940(auStack_10,*(u32 *)(*piVar13 + 0x1e0));
        lVar8 = FUN_0044f1c0(*(float *)((u8 *)DAT_006b4abc + iVar10),(float *)(iVar5 + 0x30),(float *)auStack_10);
        if (lVar8 == 1) {
          *(u8 *)(iVar2 + 7) = 1;
          if (lVar14 == 0) {
            unaff_s5 = 0xd;
            FUN_003182d0(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar11) + 0x128),0,2,8,0);
          }
          else if (lVar14 == 1) {
            FUN_003182d0(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar11) + 0x128),0,1,8,0);
            unaff_s5 = 0xf;
          }
          else if (lVar14 == 2) {
            FUN_003182d0(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar11) + 0x128),0,2,8,0);
            unaff_s5 = 0xe;
          }
          else if (lVar14 == 3) {
            unaff_s5 = 0x10;
          }
          FUN_00459d60();
          FUN_003bb010_typed(**(u16 **)((u8 *)DAT_0086e6f4 + iVar11),1);
          if (*(int *)(iVar2 + 0x10) != 0) {
            *(u32 *)(iVar2 + 0x10) = 0;
          }
          uVar6 = FUN_00459f60(param_1,*(u16 *)((u8 *)DAT_006b4ac0 + iVar10),unaff_s5);
          *(u32 *)(iVar2 + 0x10) = uVar6;
          iVar10 = FUN_001b9120_u32();
          FUN_001e1360(*(u32 *)(iVar10 + 0xc),1);
          iVar10 = FUN_001b9120_u32();
          FUN_001d3810(*(u32 *)(iVar10 + 0x24),1);
          iVar10 = FUN_001b9120_u32();
          FUN_001cd670(*(u32 *)(iVar10 + 8),1);
          lVar8 = 0;
          while (lVar8 < 4) {
            iVar11 = (int)lVar8;
            iVar10 = iVar11 * 0x1c0;
            FUN_001b0260(*(u32 *)((u8 *)DAT_0086e810 + iVar10),1);
            if (lVar14 != lVar8) {
              uVar3 = FUN_001dde00_typed(*(u16 *)((u8 *)DAT_0086e848 + iVar10));
              FUN_003182d0(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar10) + 0x128),0,uVar3,8,1);
              *(u8 *)(*(int *)(((u8 *)DAT_0086e80c)[iVar11 * 0x70] + 0x3c) + 7) = 1;
            }
            lVar8 = (long)(iVar11 + 1);
          }
          return 1;
        }
        iVar5 = FUN_00318b60(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar11) + 0x128));
        FUN_001ad940(auStack_20,*(u32 *)(*piVar13 + 0x1e0));
        lVar8 = FUN_0044f1c0(*(float *)((u8 *)DAT_006b4ab4 + iVar10),(float *)(iVar5 + 0x30),(float *)auStack_20);
        if (lVar8 == 1) {
          uVar9 = FUN_00318b60(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar11) + 0x128));
          FUN_001ad940(auStack_30,*(u32 *)(*piVar13 + 0x1e0));
          lVar8 = FUN_001c6450(*(u32 *)((u8 *)DAT_006b4ab8 + iVar10),
                               *(u32 *)((u8 *)DAT_006b4ab4 + iVar10),uVar9,auStack_30);
          if (lVar8 == 1) {
            *(u8 *)(iVar2 + 7) = 1;
            if (lVar14 == 0) {
              unaff_s5 = 0xd;
              FUN_003182d0(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar11) + 0x128),0,2,8,0);
            }
            else if (lVar14 == 1) {
              FUN_003182d0(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar11) + 0x128),0,1,8,0);
              unaff_s5 = 0xf;
            }
            else if (lVar14 == 2) {
              FUN_003182d0(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar11) + 0x128),0,2,8,0);
              unaff_s5 = 0xe;
            }
            else if (lVar14 == 3) {
              unaff_s5 = 0x10;
            }
            FUN_00459d60();
            FUN_003bb010_typed(**(u16 **)((u8 *)DAT_0086e6f4 + iVar11),1);
            if (*(int *)(iVar2 + 0x10) != 0) {
              *(u32 *)(iVar2 + 0x10) = 0;
            }
            uVar6 = FUN_00459f60(param_1,*(u16 *)((u8 *)DAT_006b4ac0 + iVar10),unaff_s5);
            *(u32 *)(iVar2 + 0x10) = uVar6;
            iVar10 = FUN_001b9120_u32();
            FUN_001e1360(*(u32 *)(iVar10 + 0xc),1);
            iVar10 = FUN_001b9120_u32();
            FUN_001d3810(*(u32 *)(iVar10 + 0x24),1);
            iVar10 = FUN_001b9120_u32();
            FUN_001cd670(*(u32 *)(iVar10 + 8),1);
            lVar8 = 0;
            while (lVar8 < 4) {
              iVar11 = (int)lVar8;
              iVar10 = iVar11 * 0x1c0;
              FUN_001b0260(*(u32 *)((u8 *)DAT_0086e810 + iVar10),1);
              if (lVar14 != lVar8) {
                uVar3 = FUN_001dde00_typed(*(u16 *)((u8 *)DAT_0086e848 + iVar10));
                FUN_003182d0(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar10) + 0x128),0,uVar3,8,1);
                *(u8 *)(*(int *)(((u8 *)DAT_0086e80c)[iVar11 * 0x70] + 0x3c) + 7) = 1;
              }
              lVar8 = (long)(iVar11 + 1);
            }
            return 1;
          }
          iVar5 = FUN_00318b60(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar11) + 0x128));
          FUN_001ad940(auStack_40,*(u32 *)(*piVar13 + 0x1e0));
          lVar8 = FUN_0044f1c0(*(float *)((u8 *)DAT_006b4ab0 + iVar10),(float *)(iVar5 + 0x30),(float *)auStack_40);
          if ((lVar8 == 1) && (param_3 == '\x01')) {
            FUN_003bb010_typed(**(u16 **)((u8 *)DAT_0086e6f4 + iVar11),0);
            if (*(int *)(iVar2 + 0x10) != 0) {
              *(u32 *)(iVar2 + 0x10) = 0;
            }
            uVar6 = FUN_00459f60(param_1,*(u16 *)((u8 *)DAT_006b4ac2 + iVar10),0);
            *(u32 *)(iVar2 + 0x10) = uVar6;
            *(u8 *)(iVar2 + 7) = 2;
            lVar8 = 0;
            while (lVar8 < 4) {
              iVar7 = (int)lVar8;
              iVar10 = iVar7 * 0x1c0;
              FUN_001b0260(*(u32 *)((u8 *)DAT_0086e810 + iVar10),1);
              uVar3 = FUN_001dde00_typed(*(u16 *)((u8 *)DAT_0086e848 + iVar10));
              FUN_003182d0(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar10) + 0x128),0,uVar3,8,1);
              if (lVar14 != lVar8) {
                cVar1 = *(char *)(*(int *)(((u8 *)DAT_0086e80c)[iVar7 * 0x70] + 0x3c) + 7);
                if ((cVar1 == '\0') || (cVar1 == '\b')) {
                  *(u8 *)(*(int *)(((u8 *)DAT_0086e80c)[iVar7 * 0x70] + 0x3c) + 7) = 8;
                }
              }
              lVar8 = (long)(iVar7 + 1);
            }
            FUN_001ad940(&uStack_50,*(u32 *)(*piVar13 + 0x1e0));
            *(u32 *)(iVar2 + 0x1c) = uStack_50;
            *(u32 *)(iVar2 + 0x20) = uStack_4c;
            *(u32 *)(iVar2 + 0x24) = uStack_48;
            sVar4 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086e810 + iVar11));
            *(short *)(iVar2 + 0x28) = sVar4;
            if (sVar4 == 0) {
              lVar14 = FUN_003b5d10_eb90(*(u16 *)(iVar2 + 4) & 0x3ff | 0x3c00);
              if (lVar14 == 0) {
                *(u32 *)(iVar2 + 0x30) = *(u32 *)(iVar2 + 0x1c);
                *(u32 *)(iVar2 + 0x34) = *(u32 *)(iVar2 + 0x20);
                *(u32 *)(iVar2 + 0x38) = *(u32 *)(iVar2 + 0x24);
              }
              else {
                iVar10 = FUN_003b5d10_eb90(*(u16 *)(iVar2 + 4) & 0x3ff | 0x3c00);
                uVar6 = *(u32 *)(iVar10 + 0x104);
                uVar16 = *(u32 *)(iVar10 + 0x108);
                *(u32 *)(iVar2 + 0x30) = *(u32 *)(iVar10 + 0x100);
                *(u32 *)(iVar2 + 0x34) = uVar6;
                *(u32 *)(iVar2 + 0x38) = uVar16;
              }
            }
            for (iVar10 = 0; iVar7 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086e810 + iVar11)),
                iVar10 < iVar7; iVar10 = iVar10 + 1) {
              uVar9 = (u32)FUN_001b01b0_typed((void *)(*(u32 *)((u8 *)DAT_0086e810 + iVar11)),iVar10);
              FUN_00521250_typed((void *)(iVar2 + iVar10 * 0x18 + 0x2c),(const void *)(uVar9),0x18);
            }
            FUN_001b00c0(*(u32 *)((u8 *)DAT_0086e810 + iVar11));
            FUN_001b0260(*(u32 *)((u8 *)DAT_0086e810 + iVar11),0);
            return 1;
          }
        }
        else {
          iVar5 = FUN_00318b60(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar11) + 0x128));
          FUN_001ad940(auStack_60,*(u32 *)(*piVar13 + 0x1e0));
          lVar8 = FUN_0044f1c0(*(float *)((u8 *)DAT_006b4ab0 + iVar10),(float *)(iVar5 + 0x30),(float *)auStack_60);
          if ((lVar8 == 1) && (param_3 == '\x01')) {
            FUN_003bb010_typed(**(u16 **)((u8 *)DAT_0086e6f4 + iVar11),0);
            if (*(int *)(iVar2 + 0x10) != 0) {
              *(u32 *)(iVar2 + 0x10) = 0;
            }
            uVar6 = FUN_00459f60(param_1,*(u16 *)((u8 *)DAT_006b4ac2 + iVar10),0);
            *(u32 *)(iVar2 + 0x10) = uVar6;
            *(u8 *)(iVar2 + 7) = 2;
            lVar8 = 0;
            while (lVar8 < 4) {
              iVar7 = (int)lVar8;
              iVar10 = iVar7 * 0x1c0;
              FUN_001b0260(*(u32 *)((u8 *)DAT_0086e810 + iVar10),1);
              uVar3 = FUN_001dde00_typed(*(u16 *)((u8 *)DAT_0086e848 + iVar10));
              FUN_003182d0(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar10) + 0x128),0,uVar3,8,1);
              if (lVar14 != lVar8) {
                cVar1 = *(char *)(*(int *)(((u8 *)DAT_0086e80c)[iVar7 * 0x70] + 0x3c) + 7);
                if ((cVar1 == '\0') || (cVar1 == '\b')) {
                  *(u8 *)(*(int *)(((u8 *)DAT_0086e80c)[iVar7 * 0x70] + 0x3c) + 7) = 8;
                }
              }
              lVar8 = (long)(iVar7 + 1);
            }
            FUN_001ad940(&uStack_70,*(u32 *)(*piVar13 + 0x1e0));
            *(u32 *)(iVar2 + 0x1c) = uStack_70;
            *(u32 *)(iVar2 + 0x20) = uStack_6c;
            *(u32 *)(iVar2 + 0x24) = uStack_68;
            sVar4 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086e810 + iVar11));
            *(short *)(iVar2 + 0x28) = sVar4;
            if (sVar4 == 0) {
              lVar14 = FUN_003b5d10_eb90(*(u16 *)(iVar2 + 4) & 0x3ff | 0x3c00);
              if (lVar14 == 0) {
                *(u32 *)(iVar2 + 0x30) = *(u32 *)(iVar2 + 0x1c);
                *(u32 *)(iVar2 + 0x34) = *(u32 *)(iVar2 + 0x20);
                *(u32 *)(iVar2 + 0x38) = *(u32 *)(iVar2 + 0x24);
              }
              else {
                iVar10 = FUN_003b5d10_eb90(*(u16 *)(iVar2 + 4) & 0x3ff | 0x3c00);
                uVar6 = *(u32 *)(iVar10 + 0x104);
                uVar16 = *(u32 *)(iVar10 + 0x108);
                *(u32 *)(iVar2 + 0x30) = *(u32 *)(iVar10 + 0x100);
                *(u32 *)(iVar2 + 0x34) = uVar6;
                *(u32 *)(iVar2 + 0x38) = uVar16;
              }
            }
            for (iVar10 = 0; iVar7 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086e810 + iVar11)),
                iVar10 < iVar7; iVar10 = iVar10 + 1) {
              uVar9 = (u32)FUN_001b01b0_typed((void *)(*(u32 *)((u8 *)DAT_0086e810 + iVar11)),iVar10);
              FUN_00521250_typed((void *)(iVar2 + iVar10 * 0x18 + 0x2c),(const void *)(uVar9),0x18);
            }
            FUN_001b00c0(*(u32 *)((u8 *)DAT_0086e810 + iVar11));
            FUN_001b0260(*(u32 *)((u8 *)DAT_0086e810 + iVar11),0);
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

// FUN_00459790 NONMATCHING

u32 FUN_00459790(u64 param_1,char param_2)

{
  int iVar1;
  u16 uVar2;
  int iVar3;
  u32 uVar4;
  long lVar5;
  u64 uVar6;
  int iVar7;
  int iVar8;
  u8 bVar9;
  int iVar10;
  long lVar11;
  u64 unaff_s4;
  int iVar12;
  int *piVar13;
  u8 auStack_30 [16];
  u8 auStack_20 [16];
  u8 auStack_10 [16];
  
  lVar11 = (long)param_2;
  iVar10 = (int)param_2;
  iVar7 = iVar10 * 0x1c;
  bVar9 = 0;
  iVar8 = iVar10 * 0x1c0;
  if ((*(int *)((u8 *)DAT_0086e6e8 + iVar8) != 0) && (*(int *)((u8 *)DAT_0086e6f4 + iVar8) != 0)) {
    bVar9 = 1;
  }
  if (bVar9) {
    for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {
      bVar9 = 0;
      if ((((u8 *)DAT_008717e8)[iVar12 * 0x70] != 0) && (((u8 *)DAT_008717f4)[iVar12 * 0x70] != 0)) {
        bVar9 = 1;
      }
      if (bVar9) {
        iVar1 = *(int *)(((u8 *)DAT_0086e80c)[iVar10 * 0x70] + 0x3c);
        piVar13 = (int *)((u8 *)DAT_008717f4 + iVar12 * 0x70);
        iVar3 = FUN_00318b60(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar8) + 0x128));
        FUN_001ad940(auStack_10,*(u32 *)(*piVar13 + 0x1e0));
        lVar5 = FUN_0044f1c0(*(float *)((u8 *)DAT_006b4abc + iVar7),(float *)(iVar3 + 0x30),(float *)auStack_10);
        if (lVar5 == 1) {
          *(u8 *)(iVar1 + 7) = 1;
          if (lVar11 == 0) {
            unaff_s4 = 0xd;
            FUN_003182d0(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar8) + 0x128),0,2,8,0);
          }
          else if (lVar11 == 1) {
            FUN_003182d0(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar8) + 0x128),0,1,8,0);
            unaff_s4 = 0xf;
          }
          else if (lVar11 == 2) {
            FUN_003182d0(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar8) + 0x128),0,2,8,0);
            unaff_s4 = 0xe;
          }
          else if (lVar11 == 3) {
            unaff_s4 = 0x10;
          }
          FUN_00459d60();
          FUN_003bb010_typed(**(u16 **)((u8 *)DAT_0086e6f4 + iVar8),1);
          if (*(int *)(iVar1 + 0x10) != 0) {
            *(u32 *)(iVar1 + 0x10) = 0;
          }
          uVar4 = FUN_00459f60(param_1,*(u16 *)((u8 *)DAT_006b4ac0 + iVar7),unaff_s4);
          *(u32 *)(iVar1 + 0x10) = uVar4;
          iVar7 = FUN_001b9120_u32();
          FUN_001e1360(*(u32 *)(iVar7 + 0xc),1);
          iVar7 = FUN_001b9120_u32();
          FUN_001d3810(*(u32 *)(iVar7 + 0x24),1);
          iVar7 = FUN_001b9120_u32();
          FUN_001cd670(*(u32 *)(iVar7 + 8),1);
          lVar5 = 0;
          while (lVar5 < 4) {
            iVar8 = (int)lVar5;
            iVar7 = iVar8 * 0x1c0;
            FUN_001b0260(*(u32 *)((u8 *)DAT_0086e810 + iVar7),1);
            if (lVar11 != lVar5) {
              uVar2 = FUN_001dde00_typed(*(u16 *)((u8 *)DAT_0086e848 + iVar7));
              FUN_003182d0(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar7) + 0x128),0,uVar2,8,1);
              *(u8 *)(*(int *)(((u8 *)DAT_0086e80c)[iVar8 * 0x70] + 0x3c) + 7) = 1;
            }
            lVar5 = (long)(iVar8 + 1);
          }
          return 1;
        }
        iVar3 = FUN_00318b60(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar8) + 0x128));
        FUN_001ad940(auStack_20,*(u32 *)(*piVar13 + 0x1e0));
        lVar5 = FUN_0044f1c0(*(float *)((u8 *)DAT_006b4ab4 + iVar7),(float *)(iVar3 + 0x30),(float *)auStack_20);
        if (lVar5 == 1) {
          uVar6 = FUN_00318b60(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar8) + 0x128));
          FUN_001ad940(auStack_30,*(u32 *)(*piVar13 + 0x1e0));
          lVar5 = FUN_001c6450(*(u32 *)((u8 *)DAT_006b4ab8 + iVar7),
                               *(u32 *)((u8 *)DAT_006b4ab4 + iVar7),uVar6,auStack_30);
          if (lVar5 == 1) {
            *(u8 *)(iVar1 + 7) = 1;
            if (lVar11 == 0) {
              unaff_s4 = 0xd;
              FUN_003182d0(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar8) + 0x128),0,2,8,0);
            }
            else if (lVar11 == 1) {
              FUN_003182d0(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar8) + 0x128),0,1,8,0);
              unaff_s4 = 0xf;
            }
            else if (lVar11 == 2) {
              FUN_003182d0(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar8) + 0x128),0,2,8,0);
              unaff_s4 = 0xe;
            }
            else if (lVar11 == 3) {
              unaff_s4 = 0x10;
            }
            FUN_00459d60();
            FUN_003bb010_typed(**(u16 **)((u8 *)DAT_0086e6f4 + iVar8),1);
            if (*(int *)(iVar1 + 0x10) != 0) {
              *(u32 *)(iVar1 + 0x10) = 0;
            }
            uVar4 = FUN_00459f60(param_1,*(u16 *)((u8 *)DAT_006b4ac0 + iVar7),unaff_s4);
            *(u32 *)(iVar1 + 0x10) = uVar4;
            iVar7 = FUN_001b9120_u32();
            FUN_001e1360(*(u32 *)(iVar7 + 0xc),1);
            iVar7 = FUN_001b9120_u32();
            FUN_001d3810(*(u32 *)(iVar7 + 0x24),1);
            iVar7 = FUN_001b9120_u32();
            FUN_001cd670(*(u32 *)(iVar7 + 8),1);
            lVar5 = 0;
            while (lVar5 < 4) {
              iVar8 = (int)lVar5;
              iVar7 = iVar8 * 0x1c0;
              FUN_001b0260(*(u32 *)((u8 *)DAT_0086e810 + iVar7),1);
              if (lVar11 != lVar5) {
                uVar2 = FUN_001dde00_typed(*(u16 *)((u8 *)DAT_0086e848 + iVar7));
                FUN_003182d0(*(u32 *)(*(int *)((u8 *)DAT_0086e6f4 + iVar7) + 0x128),0,uVar2,8,1);
                *(u8 *)(*(int *)(((u8 *)DAT_0086e80c)[iVar8 * 0x70] + 0x3c) + 7) = 1;
              }
              lVar5 = (long)(iVar8 + 1);
            }
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

// FUN_00459D60

void FUN_00459d60(void)
{
  int iVar2;
  int iVar1;
  int iVar3;

  for (iVar2 = 0; iVar2 < 4; iVar2 = iVar2 + 1) {
    iVar1 = *(int *)(DAT_0086e80c_abs + iVar2 * 0x1c0 + 0x16c);
    iVar1 = *(int *)(iVar1 + 0x3c);
    iVar3 = *(int *)(iVar1 + 0x4ac);
    if (iVar3 != 0) {
      FUN_00195020_call(iVar3);
      *(u32 *)(iVar1 + 0x4ac) = 0;
    }
    iVar3 = *(int *)(iVar1 + 0x4b0);
    if (iVar3 != 0) {
      FUN_00195020_call(iVar3);
      *(u32 *)(iVar1 + 0x4b0) = 0;
    }
  }
  return;
}

#pragma opt_loop_invariants on
// FUN_00459E00

u32 FUN_00459e00(char param_1)
{
  int iVar1;
  int iParam;
  int iVar3;
  u8 *puVar1;
  u8 *puVar2;
  
  iVar1 = 0;
  iParam = param_1;
  iVar3 = iVar1 + 8;
  puVar2 = DAT_0086e80c_abs;
  goto loop_test;
loop_body:
  if (iParam == iVar1) {
    goto loop_increment;
  }
  puVar1 = puVar2 + iVar1 * 0x1c0;
  if (iVar3 == *(char *)(*(int *)(*(int *)(puVar1 + 0x16c) + 0x3c) + 7)) {
    goto loop_increment;
  }
  return 0;
loop_increment:
  iVar1 = iVar1 + 1;
loop_test:
  if (iVar1 < iVar3 - 4) {
    goto loop_body;
  }
  return 1;
}
#pragma opt_loop_invariants off

// FUN_00459E80

u32 FUN_00459e80(int param_1)
{
  short *psVar1;
  int iVar2;
  int iVar3;
  short sVar1;
  
  psVar1 = *(short **)(param_1 + 0x3c);
  if (psVar1[1] < *psVar1) {
    psVar1[1] = psVar1[1] + 1;
    goto done_zero;
  }
  if (psVar1[2] != 0) {
    if (*(int *)(psVar1 + 4) != 0) {
      *(u32 *)(psVar1 + 4) = 0;
    }
    iVar2 = FUN_001b9120_u32();
    iVar3 = FUN_001b9120_u32();
    {
      u32 uVar1;
      u32 uVar2;
      uVar1 = *(volatile u32 *)(iVar3 + 0x104c);
      sVar1 = *(volatile short *)(psVar1 + 2);
      uVar2 = *(u32 *)(iVar2 + 0x1048);
      *(u32 *)(psVar1 + 4) =
        FUN_0035bc00_u32(10,uVar2,uVar1,sVar1);
    }
  }
  return 0xffffffff;
done_zero:
  return 0;
}

// FUN_00459F30

void FUN_00459f30(int param_1)

{
  DAT_0096017c_abs[0](*(u32 *)(param_1 + 0x3c));
  return;
}

// FUN_00459F60

u32 FUN_00459f60(u64 param_1,u16 param_2,char param_3)
{
  u32 lVar1;
  u32 uVar2;
  u16 *puVar3;
  
  lVar1 = (*DAT_00960184_abs)(1,0xc,0x40000);
  if (lVar1 == 0) {
    return 0;
  }
  uVar2 = FUN_00194b80_u32(param_1,10,DAT_006b4b68,FUN_00459e80,FUN_00459f30,lVar1);
  puVar3 = (u16 *)lVar1;
  *puVar3 = param_2;
  puVar3[1] = 0;
  puVar3[2] = (short)param_3;
  return uVar2;
}

// FUN_0045A020 NONMATCHING

u32 FUN_0045a020(int param_1)

{
  u32 *puVar1;
  long lVar2;
  u32 uVar3;
  
  puVar1 = *(u32 **)(param_1 + 0x3c);
  if (*(char *)((int)puVar1 + 0x5d) != '\x01') {
    switch(*(u8 *)(puVar1 + 1)) {
    case 0:
      uVar3 = FUN_00112370_typed((const char *)(DAT_006b4bc0));
      *puVar1 = uVar3;
      *(u8 *)(puVar1 + 1) = 1;
    case 1:
      lVar2 = FUN_00111f30_typed((void*)(*puVar1));
      if (lVar2 == 1) {
        *(u8 *)(puVar1 + 1) = 2;
      }
      break;
    case 2:
      if (*(char *)((int)puVar1 + 5) == '\x01') {
        *(u8 *)(puVar1 + 1) = 3;
        *(u16 *)((int)puVar1 + 6) = 0;
        *(u16 *)((int)puVar1 + 10) = 0;
      }
      break;
    case 3:
      uVar3 = FUN_004221a0(uGpffff82d4,1.0f,(float)(int)*(short *)(puVar1 + 0x11),10.0f,0);
      puVar1[0x12] = uVar3;
      *(u16 *)((int)puVar1 + 10) = 0;
      if (*(short *)((int)puVar1 + 6) < 10) {
        *(short *)((int)puVar1 + 6) = *(short *)((int)puVar1 + 6) + 1;
      }
      if (*(short *)(puVar1 + 0x11) < 10) {
        *(short *)(puVar1 + 0x11) = *(short *)(puVar1 + 0x11) + 1;
      }
      else {
        *(float *)(puVar1 + 0x12) = 1.0f;
        *(u8 *)(puVar1 + 1) = 4;
      }
      FUN_0045a490();
      break;
    case 4:
      FUN_0045a490();
      FUN_0045ace0();
      break;
    case 5:
      uVar3 = FUN_004221a0(1.0f,uGpffff82d4,(float)(int)*(short *)(puVar1 + 0x11),10.0f,0);
      puVar1[0x12] = uVar3;
      if (*(short *)(puVar1 + 0x11) < 10) {
        *(short *)(puVar1 + 0x11) = *(short *)(puVar1 + 0x11) + 1;
      }
      else {
        puVar1[0x12] = uGpffff82d4;
        *(u8 *)(puVar1 + 1) = 6;
      }
      FUN_0045a490();
      break;
    case 6:
      return 0xffffffff;
    }
  }
  return 0;
}

// FUN_0045A220

void FUN_0045a220(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x3c);
  if (*piVar1 != 0) {
    FUN_001124b0_u32(*piVar1);
    *piVar1 = 0;
  }
  DAT_0096017c_abs[0](*(u32 *)(param_1 + 0x3c));
  uGpffffba08 = 0;
  return;
}

// FUN_0045A280 NONMATCHING

u32 FUN_0045a280(int param_1,int param_2)

{
  char cVar1;
  u32 uVar2;
  int lVar3;
  int iVar4;
  
  lVar3 = (*DAT_00960184_abs)(1,0x60,0x40000);
  if (lVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00194b80_u32(param_1,0x106f,DAT_006b4be0,FUN_0045a020,FUN_0045a220,lVar3);
    iVar4 = (int)lVar3;
    *(u8 *)(iVar4 + 4) = 0;
    *(u8 *)(iVar4 + 5) = 0;
    *(u16 *)(iVar4 + 0x44) = 0;
    *(u32 *)(iVar4 + 0x48) = 0;
    *(u8 *)(iVar4 + 0x42) = 0;
    *(u8 *)(iVar4 + 0x43) = 0;
    *(u8 *)(iVar4 + 0x4c) = 1;
    *(int *)(iVar4 + 0x50) = param_2;
    cVar1 = (char)(param_2 / 0x3c);
    *(char *)(iVar4 + 0x54) = cVar1 / '\n';
    *(char *)(iVar4 + 0x55) = cVar1 % '\n';
    cVar1 = (char)(param_2 % 0x3c);
    *(char *)(iVar4 + 0x56) = cVar1 / '\n';
    *(char *)(iVar4 + 0x57) = cVar1 % '\n';
    *(u8 *)(iVar4 + 0x5c) = 0;
    *(u8 *)(iVar4 + 0x5d) = 0;
    uGpffffba08 = uVar2;
  }
  return uVar2;
}

// FUN_0045A3B0

int FUN_0045a3b0(void)

{
  int bVar1;
  
  if (iGpffffba08 == 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = '\x01' < *(char *)(*(int *)(iGpffffba08 + 0x3c) + 4);
  }
  return bVar1;
}

// FUN_0045A3E0

void FUN_0045a3e0(void)

{
  if (iGpffffba08 != 0) {
    *(u8 *)(*(int *)(iGpffffba08 + 0x3c) + 5) = 1;
  }
  return;
}

// FUN_0045A430

void FUN_0045a430(char param_1)

{
  int iVar1;
  
  if (iGpffffba08 != 0) {
    iVar1 = *(int *)(iGpffffba08 + 0x3c);
    *(char *)(iVar1 + 0x4c) = param_1;
    if (param_1 == '\0') {
      *(int *)(iVar1 + 0x58) = iGpffffb418 - *(char *)(iVar1 + 0x5c);
    }
    else {
      *(char *)(iVar1 + 0x5c) = (char)(iGpffffb418 - *(int *)(iVar1 + 0x58));
    }
  }
  return;
}

// FUN_0045A490 NONMATCHING

void FUN_0045a490(void)

{
  struct YRuntimeWork {
    u32 data[0x12];
    float rate;
  } *puVar1;
  int iVar2;
  u64 uVar3;
  u16 uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  puVar1 = *(struct YRuntimeWork **)(iGpffffba08 + 0x3c);
  if (iGpffffba08 != 0) {
    uVar3 = FUN_001158b0(0,puVar1->data[0],0);
    iVar2 = (int)uVar3;
    *(char *)(iVar2 + 0x18) = (char)*(u16 *)((int)puVar1 + 10);
    fVar5 = (float)FUN_001126b0_typed((void*)uVar3);
    fVar7 = puVar1->rate;
    fVar8 = 16.0f - fVar7 * (fVar5 / 2.0f);
    fVar6 = (float)FUN_001126b0_typed((void*)uVar3);
    fVar8 += fVar6 / 2.0f;
    fVar5 = (float)FUN_00112740_typed((void*)uVar3);
    fVar7 = puVar1->rate;
    fVar6 = 140.0f - fVar7 * (fVar5 / 2.0f);
    fVar7 = (float)FUN_00112740_typed((void*)uVar3);
    fVar6 += fVar7 / 2.0f;
    *(float *)(iVar2 + 0x10) = fVar8;
    *(float *)(iVar2 + 0x14) = fVar6;
    fVar7 = puVar1->rate;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x28) = uVar4 & 0xff;
    fVar7 = puVar1->rate;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x2a) = uVar4 & 0xff;
    *(float *)(iVar2 + 0x2c) = 5.0f;
    FUN_001127d0(uVar3,1);
    FUN_00115980(uVar3);
    uVar3 = FUN_001158b0(0,puVar1->data[0],0x14);
    iVar2 = (int)uVar3;
    fVar7 = puVar1->rate;
    *(float *)(iVar2 + 0x10) = fVar7 * 67.0f + fVar8 + 0.0f;
    *(float *)(iVar2 + 0x14) = fVar7 * 20.0f + fVar6 + 0.0f;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x28) = uVar4 & 0xff;
    fVar7 = puVar1->rate;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x2a) = uVar4 & 0xff;
    *(float *)(iVar2 + 0x2c) = 4.0f;
    FUN_001127d0(uVar3,1);
    FUN_00115980(uVar3);
    uVar3 = FUN_001158b0(0,puVar1->data[0],*(char *)((u8 *)puVar1 + 0x54) + 10);
    iVar2 = (int)uVar3;
    *(char *)(iVar2 + 0x18) = (char)*(u16 *)((int)puVar1 + 10);
    fVar7 = puVar1->rate;
    *(float *)(iVar2 + 0x10) = fVar7 * 8.0f + fVar8 + 0.0f;
    *(float *)(iVar2 + 0x14) = fVar7 * 20.0f + fVar6 + 0.0f;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x28) = uVar4 & 0xff;
    fVar7 = puVar1->rate;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x2a) = uVar4 & 0xff;
    *(float *)(iVar2 + 0x2c) = 4.0f;
    FUN_001127d0(uVar3,1);
    FUN_00115980(uVar3);
    uVar3 = FUN_001158b0(0,puVar1->data[0],*(char *)((u8 *)puVar1 + 0x55) + 10);
    iVar2 = (int)uVar3;
    *(char *)(iVar2 + 0x18) = (char)*(u16 *)((int)puVar1 + 10);
    fVar7 = puVar1->rate;
    *(float *)(iVar2 + 0x10) = fVar7 * 38.0f + fVar8 + 0.0f;
    *(float *)(iVar2 + 0x14) = fVar7 * 20.0f + fVar6 + 0.0f;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x28) = uVar4 & 0xff;
    fVar7 = puVar1->rate;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x2a) = uVar4 & 0xff;
    *(float *)(iVar2 + 0x2c) = 4.0f;
    FUN_001127d0(uVar3,1);
    FUN_00115980(uVar3);
    uVar3 = FUN_001158b0(0,puVar1->data[0],*(char *)((u8 *)puVar1 + 0x56) + 10);
    iVar2 = (int)uVar3;
    *(char *)(iVar2 + 0x18) = (char)*(u16 *)((int)puVar1 + 10);
    fVar7 = puVar1->rate;
    *(float *)(iVar2 + 0x10) = fVar7 * 76.0f + fVar8 + 0.0f;
    *(float *)(iVar2 + 0x14) = fVar7 * 20.0f + fVar6 + 0.0f;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x28) = uVar4 & 0xff;
    fVar7 = puVar1->rate;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x2a) = uVar4 & 0xff;
    *(float *)(iVar2 + 0x2c) = 4.0f;
    FUN_001127d0(uVar3,1);
    FUN_00115980(uVar3);
    uVar3 = FUN_001158b0(0,puVar1->data[0],*(char *)((u8 *)puVar1 + 0x57) + 10);
    iVar2 = (int)uVar3;
    *(char *)(iVar2 + 0x18) = (char)*(u16 *)((int)puVar1 + 10);
    fVar7 = puVar1->rate;
    *(float *)(iVar2 + 0x10) = fVar7 * 106.0f + fVar8 + 0.0f;
    *(float *)(iVar2 + 0x14) = fVar7 * 20.0f + fVar6 + 0.0f;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x28) = uVar4 & 0xff;
    fVar7 = puVar1->rate;
    fVar5 = fVar7 * 4096.0f;
    if (fVar5 < 2.1474836e+09f) {
      uVar4 = (u16)(int)fVar5;
    }
    else {
      uVar4 = (u16)(int)(fVar5 - 2.1474836e+09f);
    }
    *(u16 *)(iVar2 + 0x2a) = uVar4 & 0xff;
    *(float *)(iVar2 + 0x2c) = 4.0f;
    FUN_001127d0(uVar3,1);
    FUN_00115980(uVar3);
  }
  return;
}

// FUN_0045ACE0 NONMATCHING

void FUN_0045ace0(void)

{
  u32 *puVar1;
  u64 uVar2;
  char cVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  u8 uVar7;
  float fVar8;
  
  if ((iGpffffba08 != 0) && (puVar1 = *(u32 **)(iGpffffba08 + 0x3c), iGpffffba08 != 0)) {
    if ((*(char *)(puVar1 + 0x13) == '\0') && (puVar1[0x14] != 0)) {
      *(char *)((int)puVar1 + 0x43) = (char)uGpffffb418 - (char)puVar1[0x16];
    }
    for (lVar5 = 0; lVar5 < 9; lVar5 = (long)((int)lVar5 + 1)) {
      if (*(char *)((int)puVar1 + 0x42) == lVar5) {
        iVar4 = (int)lVar5 * 6;
        uVar2 = FUN_001158b0(0,*puVar1,((u8 *)DAT_006b4b80)[iVar4]);
        fVar8 = (float)FUN_0052e878_typed(fGpffff82d8 * (float)(int)*(char *)((int)puVar1 + 0x43));
        fVar8 = fVar8 * -255.0f + 255.0f;
        if (fVar8 < 2.1474836e+09f) {
          uVar7 = (u8)(int)fVar8;
        }
        else {
          uVar7 = (u8)(int)(fVar8 - 2.1474836e+09f);
        }
        iVar6 = (int)uVar2;
        *(u8 *)(iVar6 + 0x18) = uVar7;
        *(float *)(iVar6 + 0x10) = (float)(int)*(short *)((u8 *)DAT_006b4b82 + iVar4);
        *(float *)(iVar6 + 0x14) = (float)(int)*(short *)((u8 *)DAT_006b4b84 + iVar4);
        *(float *)(iVar6 + 0x2c) = 3.0f;
        FUN_001127d0(uVar2,1);
        FUN_00115980_arg(uVar2);
      }
    }
    if (((*(char *)(puVar1 + 0x13) == '\0') && (puVar1[0x14] != 0)) &&
       ('\x1d' < *(char *)((int)puVar1 + 0x43))) {
      puVar1[0x16] = uGpffffb418;
      cVar3 = *(char *)((int)puVar1 + 0x42) + '\x01';
      *(char *)((int)puVar1 + 0x42) = cVar3;
      if ('\b' < cVar3) {
        *(u8 *)((int)puVar1 + 0x42) = 0;
      }
      iVar4 = puVar1[0x14] + -1;
      puVar1[0x14] = iVar4;
      cVar3 = (char)(iVar4 / 0x3c);
      *(char *)(puVar1 + 0x15) = cVar3 / '\n';
      *(char *)((int)puVar1 + 0x55) = cVar3 % '\n';
      cVar3 = (char)(iVar4 % 0x3c);
      *(char *)((int)puVar1 + 0x56) = cVar3 / '\n';
      *(char *)((int)puVar1 + 0x57) = cVar3 % '\n';
    }
  }
  return;
}

// FUN_0045AF40

u32 FUN_0045af40(void)

{
  u32 uVar1;
  
  if (iGpffffba08 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *(u32 *)(*(int *)(iGpffffba08 + 0x3c) + 0x50);
  }
  return uVar1;
}

// FUN_0045AF70

void FUN_0045af70(u8 param_1)

{
  if (iGpffffba08 != 0) {
    *(u8 *)(*(int *)(iGpffffba08 + 0x3c) + 0x5d) = param_1;
  }
  return;
}

// FUN_0045AF90

u8 FUN_0045af90(int param_1)

{
  if (param_1 != 0) goto clear;
  return 1;
clear:
  *(u32 *)(param_1 + 0x80) = 0;
  *(u32 *)(param_1 + 0x84) = 0;
  *(u32 *)(param_1 + 0x88) = 0;
  *(u32 *)(param_1 + 0x8c) = 0;
  *(u32 *)(param_1 + 0x90) = 0;
  *(u32 *)(param_1 + 0x94) = 0;
  return 0;
}

// FUN_0045AFD0 NONMATCHING

u32
FUN_0045afd0(float param_1,long param_2,int param_3,int param_4,int param_5,int param_6,
            u8 param_7,u8 param_8,short param_9)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  float *pfVar4;
  
  iVar3 = (int)param_2;
  if (param_2 == 0) {
    uVar2 = 1;
  }
  else if (*(int *)(iVar3 + 0x84) < 4) {
    pfVar4 = (float *)(iVar3 + *(int *)(iVar3 + 0x84) * 0x20);
    *(short *)((int)pfVar4 + 0x1e) = param_9;
    if (param_9 < 1) {
      *(u16 *)((int)pfVar4 + 0x1e) = 1;
    }
    *pfVar4 = (float)param_3;
    pfVar4[1] = (float)param_4;
    pfVar4[2] = (float)param_5;
    pfVar4[3] = (float)param_6;
    pfVar4[6] = param_1;
    if (0.0f < param_1) {
      pfVar4[4] = param_1 * (pfVar4[2] - *pfVar4);
      pfVar4[5] = pfVar4[6] * (pfVar4[3] - pfVar4[1]);
    }
    else if (param_1 < 0.0f) {
      pfVar4[4] = *pfVar4;
      pfVar4[5] = pfVar4[1];
    }
    else {
      pfVar4[4] = (pfVar4[2] - *pfVar4) / (float)(int)*(short *)((int)pfVar4 + 0x1e);
      pfVar4[5] = (pfVar4[3] - pfVar4[1]) / (float)(int)*(short *)((int)pfVar4 + 0x1e);
    }
    *(u8 *)(pfVar4 + 7) = param_7;
    *(u8 *)((int)pfVar4 + 0x1d) = param_8;
    if (*(char *)(pfVar4 + 7) < '\0') {
      *(u8 *)(pfVar4 + 7) = 0;
    }
    if (*(char *)((int)pfVar4 + 0x1d) < '\0') {
      *(u8 *)((int)pfVar4 + 0x1d) = 0;
    }
    *(u32 *)(iVar3 + 0x80) = 0;
    *(int *)(iVar3 + 0x84) = *(int *)(iVar3 + 0x84) + 1;
    *(u32 *)(iVar3 + 0x88) = 0;
    *(u32 *)(iVar3 + 0x90) = 0;
    *(int *)(iVar3 + 0x94) =
         *(int *)(iVar3 + 0x94) +
         (int)*(char *)((int)pfVar4 + 0x1d) +
         (int)*(short *)((int)pfVar4 + 0x1e) + (int)*(char *)(pfVar4 + 7);
    uVar1 = *(u32 *)(iVar3 + 0x8c);
    *(u32 *)(iVar3 + 0x8c) = uVar1 | 1;
    *(u32 *)(iVar3 + 0x8c) = uVar1 & 0xfffffffd | 1;
    uVar2 = 0;
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}

// FUN_0045B190 NONMATCHING

u32 FUN_0045b190(long param_1)

{
  char cVar1;
  u32 uVar2;
  int iVar3;
  long lVar4;
  float *pfVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  if (param_1 == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    iVar6 = (int)param_1;
    if ((*(u32 *)(iVar6 + 0x8c) & 2) == 0) {
      if ((*(u32 *)(iVar6 + 0x8c) & 1) == 0) {
        uVar2 = 0;
      }
      else {
        if ((*(int *)(iVar6 + 0x80) == 0) && (*(int *)(iVar6 + 0x88) == 0)) {
          *(u32 *)(iVar6 + 0x90) = 0;
        }
        pfVar5 = (float *)(iVar6 + *(int *)(iVar6 + 0x80) * 0x20);
        cVar1 = *(char *)(pfVar5 + 7);
        lVar4 = (long)*(int *)(iVar6 + 0x88);
        if (cVar1 <= lVar4) {
          iVar3 = (int)cVar1 + (int)*(short *)((int)pfVar5 + 0x1e);
          if (lVar4 < iVar3) {
            if (lVar4 == iVar3 + -1) {
              *pfVar5 = pfVar5[2];
              pfVar5[1] = pfVar5[3];
            }
            else if (pfVar5[6] < 0.0f) {
              fVar8 = (fGpffff8110 * (float)(*(int *)(iVar6 + 0x88) - (int)cVar1)) /
                      (float)(int)*(short *)((int)pfVar5 + 0x1e);
              fVar9 = pfVar5[4];
              fVar7 = (float)FUN_0052e878_typed(fVar8);
              *pfVar5 = (pfVar5[2] - fVar9) * fVar7 + fVar9 + 0.0f;
              fVar9 = pfVar5[5];
              fVar7 = (float)FUN_0052e878_typed(fVar8);
              pfVar5[1] = (pfVar5[3] - fVar9) * fVar7 + fVar9 + 0.0f;
            }
            else {
              *pfVar5 = *pfVar5 + pfVar5[4];
              pfVar5[1] = pfVar5[1] + pfVar5[5];
              if (0.0f < pfVar5[6]) {
                pfVar5[4] = pfVar5[6] * (pfVar5[2] - *pfVar5);
                pfVar5[5] = pfVar5[6] * (pfVar5[3] - pfVar5[1]);
              }
            }
          }
          else if (*(char *)((int)pfVar5 + 0x1d) + iVar3 + -1 <= lVar4) {
            iVar3 = *(int *)(iVar6 + 0x80) + 1;
            *(int *)(iVar6 + 0x80) = iVar3;
            if (*(int *)(iVar6 + 0x84) <= iVar3) {
              *(u32 *)(iVar6 + 0x88) = 0;
              *(u32 *)(iVar6 + 0x90) = 0;
              *(int *)(iVar6 + 0x80) = *(int *)(iVar6 + 0x80) + -1;
              *(u32 *)(iVar6 + 0x8c) = *(u32 *)(iVar6 + 0x8c) | 2;
              return 2;
            }
            *(u32 *)(iVar6 + 0x88) = 0;
            return 1;
          }
        }
        *(int *)(iVar6 + 0x88) = *(int *)(iVar6 + 0x88) + 1;
        *(int *)(iVar6 + 0x90) = *(int *)(iVar6 + 0x90) + 1;
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 2;
    }
  }
  return uVar2;
}

// FUN_0045B420

u32 FUN_0045b420(int param_1,float *param_2)
{
  struct Pair2 { float x; float y; };
  struct Pair2 *puVar1;
  struct Pair2 *puVar2;
  
  if ((param_1 == 0) || (param_2 == (float *)0)) {
    return 1;
  }
  if (*(int *)(param_1 + 0x84) < 1) {
    return 2;
  }
  puVar1 = (struct Pair2 *)(param_1 + (*(int *)(param_1 + 0x80) << 5));
  puVar2 = (struct Pair2 *)param_2;
  *puVar2 = *puVar1;
  return 0;
}

// FUN_0045B480

int FUN_0045b480(int param_1)

{
  int bVar1;
  
  if (param_1 == 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = !((*(u32 *)((int)param_1 + 0x8c) & 2) > 0);
  }
  return bVar1;
}

// FUN_0045B4B0

int FUN_0045b4b0(int param_1)

{
  int bVar1;
  
  if (param_1 == 0) {
    bVar1 = 1;
  }
  else {
    bVar1 = !((*(u32 *)((int)param_1 + 0x8c) & 1) > 0);
  }
  return bVar1;
}

// FUN_0045B4E0 NONMATCHING

float FUN_0045b4e0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  
  iVar3 = (int)param_1;
  if (param_1 == 0) {
    fVar5 = 0.0f;
  }
  else if ((*(u32 *)(iVar3 + 0x8c) & 2) == 0) {
    if ((*(u32 *)(iVar3 + 0x8c) & 1) == 0) {
      fVar5 = 0.0f;
    }
    else {
      iVar2 = *(int *)(iVar3 + 0x94);
      if (iVar2 < 1) {
        fVar5 = 0.0f;
      }
      else {
        cVar1 = *(char *)(iVar3 + 0x1c);
        iVar4 = *(int *)(iVar3 + 0x90);
        if ((long)iVar4 < (long)cVar1) {
          fVar5 = 0.0f;
        }
        else {
          iVar3 = (int)*(char *)(*(int *)(iVar3 + 0x84) * 0x20 + iVar3 + -3);
          if (iVar4 < iVar2 - iVar3) {
            iVar4 = iVar4 - cVar1;
            iVar3 = (iVar2 - cVar1) - iVar3;
            if ((iVar4 < 1) || (iVar3 < 1)) {
              fVar5 = 0.0f;
            }
            else {
              fVar5 = (float)iVar4 / (float)iVar3;
              if (fVar5 < 0.0f) {
                fVar5 = 0.0f;
              }
              else if (1.0f < fVar5) {
                fVar5 = 1.0f;
              }
            }
          }
          else {
            fVar5 = 1.0f;
          }
        }
      }
    }
  }
  else {
    fVar5 = 1.0f;
  }
  return fVar5;
}

// FUN_0045B620 NONMATCHING

void FUN_0045b620(float param_1,float param_2,float param_3,float param_4,u64 param_5,
                 char param_6,int param_7)

{
  int iVar1;
  u64 uVar2;
  u16 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  
  uVar2 = FUN_001158b0(0,uGpffffba28,param_5);
  iVar1 = (int)uVar2;
  *(u32 *)(iVar1 + 0x2c) = 0;
  *(float *)(iVar1 + 0x10) = param_1;
  *(float *)(iVar1 + 0x14) = param_2;
  fVar4 = (float)FUN_001126b0_typed((void*)uVar2);
  fVar5 = (float)FUN_00112740_typed((void*)uVar2);
  *(char *)(iVar1 + 0x18) = -1 - param_6;
  param_3 = param_3 * 4096.0f;
  if (param_3 < 2.1474836e+09f) {
    uVar3 = (u16)(int)param_3;
  }
  else {
    uVar3 = (u16)(int)(param_3 - 2.1474836e+09f);
  }
  *(u16 *)(iVar1 + 0x28) = uVar3;
  param_4 = param_4 * 4096.0f;
  if (param_4 < 2.1474836e+09f) {
    uVar3 = (u16)(int)param_4;
  }
  else {
    uVar3 = (u16)(int)(param_4 - 2.1474836e+09f);
  }
  *(u16 *)(iVar1 + 0x2a) = uVar3;
  if (param_7 == 1) {
    fVar6 = (float)FUN_001126b0_typed((void*)uVar2);
    fVar7 = (float)FUN_00112740_typed((void*)uVar2);
    *(float *)(iVar1 + 0x10) = param_1 - ((fVar6 - fVar4) + 0.5f) / 2.0f;
    *(float *)(iVar1 + 0x14) = param_2 - ((fVar7 - fVar5) + 0.5f) / 2.0f;
  }
  FUN_001127d0(uVar2,1);
  FUN_00115980_arg(uVar2);
  return;
}

// FUN_0045B830

void FUN_0045b830(int param_1,long param_2)
{
  int iVar1;
  int iVar4;
  int iVar3;
  int iVar2;

  iVar1 = *(int *)(param_1 + 0x3c);
  if (param_2 == 0) {
    iVar4 = 0xed;
    iVar2 = 0x31;
    iVar3 = iVar2;
  }
  else if (param_2 == 1) {
    iVar4 = 0xed;
    iVar3 = 0x31;
    iVar2 = 0x1d;
  }
  else {
    iVar4 = 0xed;
    iVar2 = 0x31;
    iVar3 = 0x1d;
  }
  FUN_0045af90(iVar1 + 0x2a8);
  FUN_0045afd0_call3(iVar1 + 0x2a8,iVar4,iVar3,iVar4,iVar2,uGpffff82d0,0,0,10);
  return;
}

// FUN_0045B8F0 NONMATCHING

void FUN_0045b8f0(int param_1)
{
  int iVar1;
  int iVar2;
  u32 bVar1;

  iVar1 = *(int *)(param_1 + 0x3c);
  *(u32 *)(iVar1 + 0x28) = *(u32 *)(iVar1 + 0x1c);
  *(u32 *)(iVar1 + 0x2c) = *(u32 *)(iVar1 + 0x20);
  *(u32 *)(iVar1 + 0x30) = *(u32 *)(iVar1 + 0x24);
  bVar1 = ((*(u16 *)DAT_007e0952_abs & 0x4000) != 0);
  if (bVar1 == 0) {
    bVar1 = ((*(u16 *)DAT_007e095a_abs & 0x4000) != 0);
  }
  if (bVar1) {
    u8 *p094e = DAT_007e094e_abs;
    u8 *p0958 = DAT_007e0958_abs;
    u8 *ptable = DAT_007bc730_abs;
    do {
      iVar2 = *(int *)(iVar1 + 0x20) + 1;
      *(int *)(iVar1 + 0x20) = iVar2;
      if (5 < iVar2) {
        if ((*(u16 *)p094e & 0x4000) == 0 &&
            (*(u16 *)p0958 & 0x4000) == 0) {
          *(u32 *)(iVar1 + 0x20) = *(u32 *)(iVar1 + 0x2c);
        }
        else {
          *(u32 *)(iVar1 + 0x20) = 0;
        }
      }
    } while (*(short *)(ptable + *(int *)(iVar1 + 0x1c) * 2 +
                         *(int *)(iVar1 + 0x20) * 0x28) < 0);
  }
  if ((*(u16 *)DAT_007e0952_abs & 0x1000) != 0 ||
      (*(u16 *)DAT_007e095a_abs & 0x1000) != 0) {
    do {
      iVar2 = *(int *)(iVar1 + 0x20) - 1;
      *(int *)(iVar1 + 0x20) = iVar2;
      if (iVar2 < 0) {
        if ((*(u16 *)DAT_007e094e_abs & 0x1000) == 0 &&
            (*(u16 *)DAT_007e0958_abs & 0x1000) == 0) {
          *(u32 *)(iVar1 + 0x20) = *(u32 *)(iVar1 + 0x2c);
        }
        else {
          *(u32 *)(iVar1 + 0x20) = 5;
        }
      }
    } while (*(short *)(DAT_007bc730_abs + *(int *)(iVar1 + 0x1c) * 2 +
                         *(int *)(iVar1 + 0x20) * 0x28) < 0);
  }
  if ((*(u16 *)DAT_007e0952_abs & 0x2000) != 0 ||
      (*(u16 *)DAT_007e095a_abs & 0x2000) != 0) {
    do {
      iVar2 = *(int *)(iVar1 + 0x1c) + 1;
      *(int *)(iVar1 + 0x1c) = iVar2;
      if (0x13 < iVar2) {
        if ((*(u16 *)DAT_007e094e_abs & 0x2000) == 0 &&
            (*(u16 *)DAT_007e0958_abs & 0x2000) == 0) {
          *(u32 *)(iVar1 + 0x1c) = *(u32 *)(iVar1 + 0x28);
        }
        else {
          *(u32 *)(iVar1 + 0x1c) = 0;
        }
      }
    } while (*(short *)(DAT_007bc730_abs + *(int *)(iVar1 + 0x1c) * 2 +
                         *(int *)(iVar1 + 0x20) * 0x28) < 0);
  }
  if ((*(u16 *)DAT_007e0952_abs & 0x8000) != 0 ||
      (*(u16 *)DAT_007e095a_abs & 0x8000) != 0) {
    do {
      iVar2 = *(int *)(iVar1 + 0x1c) - 1;
      *(int *)(iVar1 + 0x1c) = iVar2;
      if (iVar2 < 0) {
        if ((*(u16 *)DAT_007e094e_abs & 0x8000) == 0 &&
            (*(u16 *)DAT_007e0958_abs & 0x8000) == 0) {
          *(u32 *)(iVar1 + 0x1c) = *(u32 *)(iVar1 + 0x28);
        }
        else {
          *(u32 *)(iVar1 + 0x1c) = 0x13;
        }
      }
    } while (*(short *)(DAT_007bc730_abs + *(int *)(iVar1 + 0x1c) * 2 +
                         *(int *)(iVar1 + 0x20) * 0x28) < 0);
  }
  iVar2 = *(int *)(iVar1 + 0x1c) % 5 + *(int *)(iVar1 + 0x20) * 5;
  *(int *)(iVar1 + 0x24) = iVar2;
  iVar2 = iVar2 + (*(int *)(iVar1 + 0x1c) / 5) * 0x1e;
  *(int *)(iVar1 + 0x24) = iVar2;
  if (iVar2 != *(int *)(iVar1 + 0x30)) {
    *(u32 *)(iVar1 + 0x34) = *(u32 *)(iVar1 + 0x28);
    *(u32 *)(iVar1 + 0x38) = *(u32 *)(iVar1 + 0x2c);
    *(u32 *)(iVar1 + 0x3c) = *(u32 *)(iVar1 + 0x30);
    FUN_0010a4e0(0,0,0,0);
  }
}

// FUN_0045BCB0

void FUN_0045bcb0(int param_1,u64 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)((int)param_1 + 0x3c);
  if ((int)iGpffffba20 < 0x10) {
    if ((int)iGpffffba20 < 8) {
      FUN_00524828_u64((u8 *)DAT_0095c240_abs + iGpffffba20 * 2,param_2,2);
    }
    else {
      FUN_00524828_u64((u8 *)DAT_0095c220_abs + (iGpffffba20 + -8) * 2,param_2,2);
    }
    iGpffffba20 = iGpffffba20 + 1;
    if ((int)iGpffffba20 < 0x10) goto LAB_0045bd50;
    iGpffffba20 = 0xf;
    goto LAB_0045bd70;
LAB_0045bd50:
    if (iGpffffba20 == 8) {
      *(u32 *)(iVar1 + 0x1c34) = 1;
      FUN_0045b830(param_1,1);
    }
LAB_0045bd70:
    ;
  }
  return;
}

// FUN_0045BD90 NONMATCHING

void FUN_0045bd90(u64 param_1)

{
  int iVar1;
  u8 bVar2;
  u32 uVar3;
  int iVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  u8 auStack_4 [4];
  
  iVar1 = *(int *)((int)param_1 + 0x3c);
  for (iVar7 = 0; iVar7 < 6; iVar7 = iVar7 + 1) {
    *(u32 *)(iVar1 + iVar7 * 4 + 0x1c50) = 0;
  }
  *(u16 *)(iVar1 + 0x1c4c) = 0;
  bVar2 = 0;
  if (iGpffffba24 == 0) {
    iVar7 = 0;
    for (iVar6 = 0; iVar6 < 8; iVar6 = iVar6 + 1) {
      lVar5 = FUN_00524670_typed((u64)((u8 *)gp0xffffae24),(u8(*)[16])((u8 *)DAT_0095c240 + iVar6 * 2),2);
      if (lVar5 == 0) {
        iVar7 = iVar7 + 1;
      }
    }
    if (iVar7 < 8) {
      iVar7 = 0;
      for (iVar6 = 0; iVar6 < 8; iVar6 = iVar6 + 1) {
        lVar5 = FUN_00524670_typed((u64)((u8 *)gp0xffffae24),(u8(*)[16])((u8 *)DAT_0095c220 + iVar6 * 2),2);
        if (lVar5 == 0) {
          iVar7 = iVar7 + 1;
        }
      }
      if (iVar7 < 8) {
        bVar2 = 1;
        *(u16 *)(iVar1 + 0x1c4c) = 1;
      }
    }
  }
  if ((((DAT_007e094e & 0x800) == 0) && ((DAT_007e0958 & 0x800) == 0)) || (!bVar2)) {
    *(u16 *)(iVar1 + 0x1c44) = 0;
    *(u16 *)(iVar1 + 0x1c38) = 0;
    iVar7 = 0;
    if (iGpffffba24 < 1) {
      if (iGpffffba20 < 8) {
        uVar3 = FUN_00524388_str((const char*)(0x95c240));
        iVar6 = iGpffffba20;
        if (uVar3 >> 1 != 0) {
          lVar5 = FUN_00524670_typed((u64)((u8 *)gp0xffffae24),(u8(*)[16])((u8 *)DAT_0095c240 + iGpffffba20 * 2),2);
          if (lVar5 == 0) {
            bVar2 = 0;
            do {
              iVar6 = iVar6 + 1;
              if (7 < iVar6) goto LAB_0045bfe0;
              lVar5 = FUN_00524670_typed((u64)((u8 *)gp0xffffae24),(u8(*)[16])((u8 *)DAT_0095c240 + iVar6 * 2),2);
            } while (lVar5 == 0);
            bVar2 = 1;
LAB_0045bfe0:
            if (bVar2) {
              iVar7 = 0x14;
            }
          }
          else {
            iVar7 = 0x15;
          }
        }
      }
      else {
        uVar3 = FUN_00524388_str((const char*)(0x95c220));
        iVar6 = iGpffffba20;
        if (uVar3 >> 1 != 0) {
          lVar5 = FUN_00524670_typed((u64)((u8 *)gp0xffffae24),(u8(*)[16])((u8 *)DAT_0095c220 + (iGpffffba20 + -8) * 2),2);
          if (lVar5 == 0) {
            bVar2 = 0;
            for (iVar6 = iVar6 + -7; iVar6 < 8; iVar6 = iVar6 + 1) {
              lVar5 = FUN_00524670_typed((u64)((u8 *)gp0xffffae24),(u8(*)[16])((u8 *)DAT_0095c220 + iVar6 * 2),2);
              if (lVar5 != 0) {
                bVar2 = 1;
                break;
              }
            }
            if (bVar2) {
              iVar7 = 0x1e;
            }
          }
          else {
            iVar7 = 0x1f;
          }
        }
      }
    }
    else {
      iVar7 = 10;
    }
    if (iVar7 != 0) {
      *(u16 *)(iVar1 + 0x1c38) = 1;
    }
    if (((DAT_007e094e & 0x20) != 0) || ((DAT_007e0958 & 0x20) != 0)) {
      if (iVar7 == 0x1f) {
        FUN_00524828((u8 *)DAT_0095c220 + (iGpffffba20 + -8) * 2,(u8 *)gp0xffffae24,2);
      }
      else if (iVar7 == 0x1e) {
        for (iVar6 = iGpffffba20 + -7; iVar6 < 8; iVar6 = iVar6 + 1) {
          iVar4 = iVar6 * 2;
          ((u8 *)DAT_0095c21e)[iVar4] = ((u8 *)DAT_0095c220)[iVar4];
          ((u8 *)DAT_0095c21f)[iVar4] = ((u8 *)DAT_0095c221)[iVar4];
        }
        FUN_00524828((void *)0x95c22e,(u8 *)gp0xffffae24,2);
      }
      else if (iVar7 == 0x15) {
        FUN_00524828((u8 *)DAT_0095c240 + iGpffffba20 * 2,(u8 *)gp0xffffae24,2);
      }
      else {
        iVar6 = iGpffffba20;
        if (iVar7 == 0x14) {
          while (iVar6 = iVar6 + 1, iVar6 < 8) {
            iVar4 = iVar6 * 2;
            ((u8 *)DAT_0095c23e)[iVar4] = ((u8 *)DAT_0095c240)[iVar4];
            ((u8 *)DAT_0095c23f)[iVar4] = ((u8 *)DAT_0095c241)[iVar4];
          }
          FUN_00524828((void *)0x95c24e,(u8 *)gp0xffffae24,2);
        }
        else if (iVar7 == 10) {
          if (iGpffffba20 < 8) {
            FUN_00524828((u8 *)DAT_0095c240 + iGpffffba20 * 2,(u8 *)gp0xffffae24,2);
          }
          else {
            FUN_00524828((u8 *)DAT_0095c220 + (iGpffffba20 + -8) * 2,(u8 *)gp0xffffae24,2);
          }
        }
        else {
          iVar7 = 0;
        }
      }
      if (iVar7 != 0) {
        *(u32 *)(iVar1 + 0x1c50) = 1;
        FUN_0010a4e0(0,0,0,2);
        return;
      }
    }
    *(u16 *)(iVar1 + 0x1c3c) = 0;
    if (5 >= iGpffffba24) {
      *(u16 *)(iVar1 + 0x1c3c) = 1;
    }
    if (((DAT_007e094e & 0x40) == 0 && (DAT_007e0958 & 0x40) == 0) || (5 < iGpffffba24)) {
      *(u16 *)(iVar1 + 0x1c40) = 0;
      if (0 < iGpffffba20) {
        *(u16 *)(iVar1 + 0x1c40) = 1;
      }
      if (((DAT_007e094e & 4) != 0 || (DAT_007e0958 & 4) != 0) && (0 < iGpffffba20)) {
        iGpffffba20 = iGpffffba20 + -1;
        if (iGpffffba20 == 7) {
          *(u32 *)(iVar1 + 0x1c34) = 2;
          FUN_0045b830(param_1,2);
        }
        *(u32 *)(iVar1 + 0x1c58) = 1;
        FUN_0010a4e0(0,0,0,0);
      }
      *(u16 *)(iVar1 + 0x1c48) = 0;
      if (iGpffffba20 < 0xf) {
        *(u16 *)(iVar1 + 0x1c48) = 1;
      }
      if (((DAT_007e094e & 8) != 0 || (DAT_007e0958 & 8) != 0) && (iGpffffba20 < 0xf)) {
        iGpffffba20 = iGpffffba20 + 1;
        if (iGpffffba20 == 8) {
          *(u32 *)(iVar1 + 0x1c34) = 1;
          FUN_0045b830(param_1,1);
        }
        *(u32 *)(iVar1 + 0x1c60) = 1;
        FUN_0010a4e0(0,0,0,0);
      }
      FUN_0045b8f0(param_1);
    }
    else {
      FUN_00521250_typed((void *)(auStack_4),(const void *)(((u8 *)PTR_DAT_006b4de0)[*(int *)(iVar1 + 0x20)] + *(int *)(iVar1 + 0x1c) * 2),2);
      FUN_0045bcb0(param_1,*(u64 *)(auStack_4));
      FUN_0010a4e0(0,0,0,1);
    }
  }
  else {
    *(u32 *)(iVar1 + 0x14) = 3;
    *(u32 *)(iVar1 + 0x1c64) = 1;
    FUN_0010a4e0(0,0,0,1);
  }
  return;
}

// FUN_0045C530 NONMATCHING

void FUN_0045c530(int param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  if (*(int *)(iVar1 + 0x14) == 1) {
    if (*(int *)(iVar1 + 0x24) == *(int *)(iVar1 + 0x30)) {
      iVar2 = *(int *)(iVar1 + 0x1c30) + 1;
      *(int *)(iVar1 + 0x1c30) = iVar2;
      if (0x59 < iVar2) {
        *(u32 *)(iVar1 + 0x1c30) = 0;
        iVar4 = (*(int *)(iVar1 + 0x1c) % 5) * 0x1b;
        iVar2 = *(int *)(iVar1 + 0x1c) / 5;
        if (iVar2 == 3) {
          iVar4 = iVar4 + 0x1da;
        }
        else if (iVar2 == 2) {
          iVar4 = iVar4 + 0x146;
        }
        else if (iVar2 == 1) {
          iVar4 = iVar4 + 0xb2;
        }
        else if (iVar2 == 0) {
          iVar4 = iVar4 + 0x1e;
        }
        iVar2 = *(int *)(iVar1 + 0x20) * 0x19 + 0xe5;
        FUN_0045af90(iVar1 + 0xe0);
        FUN_0045afd0(DAT_007cafc0,iVar1 + 0xe0,iVar4,iVar2,iVar4,iVar2,0,0,0x3c);
      }
    }
    else {
      *(u32 *)(iVar1 + 0x1c30) = 0;
    }
    lVar3 = FUN_0045b4b0(iVar1 + 0xe0);
    if ((lVar3 == 0) && (lVar3 = FUN_0045b480(iVar1 + 0xe0), lVar3 != 0)) {
      FUN_0045b190(iVar1 + 0xe0);
      iVar4 = *(int *)(iVar1 + 0x20);
      iVar5 = (*(int *)(iVar1 + 0x1c) % 5) * 0x1b;
      iVar2 = *(int *)(iVar1 + 0x1c) / 5;
      if (iVar2 == 3) {
        iVar5 = iVar5 + 0x1da;
      }
      else if (iVar2 == 2) {
        iVar5 = iVar5 + 0x146;
      }
      else if (iVar2 == 1) {
        iVar5 = iVar5 + 0xb2;
      }
      else if (iVar2 == 0) {
        iVar5 = iVar5 + 0x1e;
      }
      fVar7 = (float)FUN_0045b4e0(iVar1 + 0xe0);
      if (fVar7 < 0.5f) {
        fVar6 = fVar7 * 255.0f;
        if (2.1474836e+09f <= fVar6) {
          fVar6 = fVar6 - 2.1474836e+09f;
        }
      }
      else {
        fVar7 = 1.0f - fVar7;
        fVar6 = fVar7 * 255.0f;
        if (2.1474836e+09f <= fVar6) {
          fVar6 = fVar6 - 2.1474836e+09f;
        }
      }
      FUN_0045b620((float)(iVar5 + -0xc),(float)(iVar4 * 0x19 + 0xd9),fVar7 + 1.0f,fVar7 + 1.0f,0xf,
                   (int)fVar6 & 0xff,1);
    }
  }
  else {
    lVar3 = FUN_0045b4b0(iVar1 + 0xe0);
    if (lVar3 == 0) {
      FUN_0045af90(iVar1 + 0xe0);
    }
  }
  return;
}

// FUN_0045C8C0 NONMATCHING

void FUN_0045c8c0(int param_1,int param_2)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  short *psVar7;
  short *psVar8;
  int iVar9;
  float fVar10;
  float fVar11;
  int aiStack_70 [26];
  float fStack_8;
  float fStack_4;
  
  iVar4 = *(int *)(param_1 + 0x3c);
  piVar6 = (int *)DAT_006b4e00;
  piVar5 = aiStack_70;
  iVar3 = 0xc;
  do {
    iVar9 = *piVar6;
    iVar1 = piVar6[1];
    piVar6 = piVar6 + 2;
    iVar3 = iVar3 + -1;
    *piVar5 = iVar9;
    piVar5[1] = iVar1;
    piVar5 = piVar5 + 2;
  } while (0 < iVar3);
  iVar3 = iVar4 + param_2 * 0x130;
  iVar9 = iVar3 + 0x1510;
  iVar3 = iVar3 + 0x15a8;
  iVar4 = iVar4 + param_2 * 4;
  psVar8 = (short *)(iVar4 + 0x1c38);
  psVar7 = (short *)(iVar4 + 0x1c3a);
  if (*(short *)(iVar4 + 0x1c38) == 3) {
    if (*psVar7 != 3) {
      iVar4 = aiStack_70[param_2 * 4 + 2];
      iVar3 = aiStack_70[param_2 * 4 + 3];
      FUN_0045af90(iVar9);
      FUN_0045afd0(DAT_007cafc0,iVar9,iVar4,iVar3 + 0x1e,iVar4,iVar3,0,0,10);
      *psVar7 = *psVar8;
    }
    FUN_0045b190(iVar9);
    FUN_0045b4e0(iVar9);
    FUN_0045b420((iVar9),(float*)(&fStack_8));
    FUN_001159f0_3f((float)(int)fStack_8,(float)(int)fStack_4,0);
  }
  else {
    if (*(int *)(iVar4 + 0x1c50) != 0) {
      *(u32 *)(iVar4 + 0x1c50) = 0;
      iVar4 = aiStack_70[param_2 * 4 + 2];
      iVar1 = aiStack_70[param_2 * 4 + 3];
      FUN_0045af90(iVar3);
      FUN_0045afd0(DAT_007cafc0,iVar3,iVar4,iVar1,iVar4,iVar1,0,0,10);
    }
    lVar2 = FUN_0045b4b0(iVar3);
    if ((lVar2 == 0) && (lVar2 = FUN_0045b480(iVar3), lVar2 != 0)) {
      FUN_0045b190(iVar3);
      fVar11 = (float)FUN_0045b4e0(iVar3);
      fVar10 = (1.0f - fVar11) * 128.0f;
      if (fVar10 < 2147483648.0f) {
        iVar1 = (int)fVar10 & 0xff;
      }
      else {
        iVar1 = ((int)(fVar10 - 2147483648.0f) | 0x80000000) & 0xff;
      }
      FUN_0045b420((iVar3),(float*)(&fStack_8));
      fVar11 = fVar11 / 3.0f + 1.0f;
      FUN_0045b620((float)(int)fStack_8,(float)(int)fStack_4,fVar11,fVar11,aiStack_70[param_2 * 4],
                   iVar1,1);
    }
    if (*psVar8 != *psVar7) {
      if (*psVar8 == 0) {
        iVar4 = aiStack_70[param_2 * 4 + 2];
        iVar3 = aiStack_70[param_2 * 4 + 3];
        FUN_0045af90(iVar9);
        FUN_0045afd0(DAT_007cafc0,iVar9,iVar4,iVar3,iVar4,iVar3,0,0,10);
      }
      *psVar7 = *psVar8;
    }
    FUN_0045b190(iVar9);
    FUN_0045b4e0(iVar9);
    FUN_0045b420((iVar9),(float*)(&fStack_8));
    FUN_001159f0_3f((float)(int)fStack_8,(float)(int)fStack_4,0);
    FUN_001159f0_3f((float)(int)fStack_8,(float)(int)fStack_4,0);
  }
  return;
}

// FUN_0045CDD0

void FUN_0045cdd0(int param_1,long param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)((int)param_1 + 0x3c);
  if ((param_2 == 0) && (*(int *)(iVar1 + 0x14) != 1)) {
    for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
      *(u16 *)(iVar1 + iVar2 * 4 + 0x1c38) = 0;
    }
  }
  FUN_0045c8c0(param_1,0);
  FUN_0045c8c0(param_1,1);
  FUN_0045c8c0(param_1,2);
  FUN_0045c8c0(param_1,4);
  FUN_0045c8c0(param_1,5);
  return;
}

// FUN_0045CE90 NONMATCHING

void FUN_0045ce90(int param_1)

{
  int iVar1;
  u32 uVar2;
  long lVar3;
  int iVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  u32 uVar12;
  int iVar13;
  int iVar14;
  union {
    struct {
      u32 uStack_20;
      u32 uStack_1c;
      u32 uStack_18;
      u32 uStack_14;
      u32 uStack_10;
      u32 uStack_c;
    } words;
    float afStack_8[2];
  } scratch;
#define uStack_20 scratch.words.uStack_20
#define uStack_1c scratch.words.uStack_1c
#define uStack_18 scratch.words.uStack_18
#define uStack_14 scratch.words.uStack_14
#define uStack_10 scratch.words.uStack_10
#define uStack_c scratch.words.uStack_c
#define fStack_8 scratch.afStack_8[0]
#define fStack_4 scratch.afStack_8[1]
  
  iVar10 = *(int *)((int)param_1 + 0x3c);
  FUN_001159f0_3fv(0,0,0,param_1,(u8 *)DAT_007ce718,0xa4,0);
  FUN_0045b190(iVar10 + 0x2a8);
  FUN_0045b4e0(iVar10 + 0x2a8);
  FUN_0045b420((iVar10 + 0x2a8),(float*)(&fStack_8));
  iVar13 = (int)fStack_8;
  iVar14 = (int)fStack_4;
  FUN_001159f0_3f((float)iVar13,(float)iVar14,0);
  FUN_001159f0_3f((float)(iVar13 + 0x69),(float)iVar14,0);
  FUN_001159f0_3f((float)iVar13,(float)(iVar14 + 0x14),0);
  FUN_001159f0_3f((float)(iVar13 + 0x69),(float)(iVar14 + 0x14),0);
  FUN_0045cdd0(param_1,0);
  iVar13 = *(int *)((int)param_1 + 0x3c);
  FUN_001159f0_3f(229.0f,150.0f,0);
  FUN_001159f0_3f(229.0f,182.0f,0);
  FUN_00115bc0_3f(412.0f,179.0f,0);
  if (*(int *)(iVar13 + 0x14) != 3) {
    if (DAT_007ce710 < 8) {
      iVar14 = 0x97;
      iVar13 = DAT_007ce710;
    }
    else {
      iVar13 = DAT_007ce710 + -8;
      iVar14 = 0xb7;
    }
    FUN_001159f0_3f((float)(iVar13 * 0x1c + 0xe3),(float)iVar14,0);
  }
  FUN_0045b4e0(iVar10 + 0x210);
  FUN_0045b420((iVar10 + 0x210),(float*)(&fStack_8));
  FUN_001159f0_3f(4.0f,(float)(int)fStack_4,0);
  FUN_001159f0_3f(321.0f,(float)(int)fStack_4,0);
  iVar13 = *(int *)(iVar10 + 0x24) / 5;
  iVar14 = *(int *)(iVar10 + 0x30);
  iVar1 = *(int *)(iVar10 + 0x3c);
  for (iVar4 = 0; iVar4 < 0x18; iVar4 = iVar4 + 1) {
    iVar9 = (iVar4 / 6) * 0x94 + 0x1b;
    iVar8 = (iVar4 % 6) * 0x19 + 0xe5;
    FUN_001159f0_3fv((float)iVar9,(float)iVar8,0,uStack_c,DAT_007ce718,0x1b,0);
    if (*(int *)(iVar10 + 0x14) != 3) {
      if ((iVar13 != iVar14 / 5) && (iVar4 == iVar1 / 5)) {
        iVar11 = iVar10 + iVar4 * 0x98 + 0x340;
        FUN_0045af90(iVar11);
        FUN_0045afd0(DAT_007cafc0,iVar11,0,0,0,0,0,0,0x14);
      }
      iVar11 = iVar10 + iVar4 * 0x98 + 0x340;
      FUN_0045b190(iVar11);
      if (iVar4 == iVar13) {
        FUN_001159f0_3fv((float)iVar9,(float)iVar8,0,uStack_10,DAT_007ce718,0x1c,0);
      }
      else {
        lVar3 = FUN_0045b480(iVar11);
        if (lVar3 != 0) {
          float fVar15;
          fVar15 = (float)FUN_0045b4e0(iVar11);
          fVar15 = (1.0f - fVar15) * 255.0f;
          if (2.1474836e+09f <= fVar15) {
            fVar15 = fVar15 - 2.1474836e+09f;
          }
          FUN_001159f0_3fv((float)iVar9,(float)iVar8,0,uStack_14,DAT_007ce718,0x1c,
                       0xff - ((int)fVar15 & 0xffU) & 0xff);
        }
      }
    }
  }
  FUN_0045c530(param_1);
  if (*(int *)(iVar10 + 0x14) != 3) {
    iVar14 = (*(int *)(iVar10 + 0x1c) % 5) * 0x1b;
    iVar13 = *(int *)(iVar10 + 0x1c) / 5;
    if (iVar13 == 3) {
      iVar14 = iVar14 + 0x1da;
    }
    else if (iVar13 == 2) {
      iVar14 = iVar14 + 0x146;
    }
    else if (iVar13 == 1) {
      iVar14 = iVar14 + 0xb2;
    }
    else if (iVar13 == 0) {
      iVar14 = iVar14 + 0x1e;
    }
    FUN_001159f0_3fv((float)(iVar14 + -0xc),(float)(*(int *)(iVar10 + 0x20) * 0x19 + 0xd9),0,uStack_18,
                 DAT_007ce718,0xf,0);
  }
  for (iVar13 = 0; iVar13 < 6; iVar13 = iVar13 + 1) {
    for (iVar14 = 0; iVar14 < 0x14; iVar14 = iVar14 + 1) {
      if (-1 < *(short *)((u8 *)DAT_007bc730 + iVar14 * 2 + iVar13 * 0x28)) {
        iVar4 = (iVar14 % 5) * 0x1b;
        iVar1 = iVar14 / 5;
        if (iVar1 == 3) {
          iVar4 = iVar4 + 0x1da;
        }
        else if (iVar1 == 2) {
          iVar4 = iVar4 + 0x146;
        }
        else if (iVar1 == 1) {
          iVar4 = iVar4 + 0xb2;
        }
        else if (iVar1 == 0) {
          iVar4 = iVar4 + 0x1e;
        }
        uVar5 = 0x2e;
        uVar6 = 0x3c;
        uVar7 = 0x44;
        if (((*(int *)(iVar10 + 0x14) != 3) && (iVar14 == *(int *)(iVar10 + 0x1c))) &&
           (iVar13 == *(int *)(iVar10 + 0x20))) {
          uVar5 = 0xe0;
          uVar6 = 0xe0;
          uVar7 = 0xe0;
        }
        FUN_00115bc0_3fv((float)iVar4,(float)(iVar13 * 0x19 + 0xe5),0,uStack_1c,DAT_007ce718,
                     *(short *)((u8 *)DAT_007bc730 + iVar14 * 2 + iVar13 * 0x28) + 0x20,0x19,uVar5,uVar6,
                     uVar7);
      }
    }
  }
  if ((*(int *)(iVar10 + 0x14) == 3) && (*(int *)(iVar10 + 8) == 0)) {
    FUN_001159f0_3fv(0,0x42cc0000,0,uStack_20,DAT_007ce718,0xac,0);
  }
  uVar2 = FUN_00524388_str((const char*)(0x95c240));
  if (uVar2 >> 1 != 0) {
    uVar2 = FUN_00524388_str((const char*)(0x95c240));
    iVar10 = 0xe6;
    for (uVar12 = 0; uVar12 < uVar2 >> 1; uVar12 = uVar12 + 1) {
      FUN_00524828((void *)0x7ce6fc,(u8 *)DAT_0095c240 + uVar12 * 2,2);
      FUN_003b2cb0_va(0,iVar10,0x79,0xffffffffffffffff,5,0,0x7ce6fc,0,0);
      iVar10 = iVar10 + 0x1c;
    }
  }
  uVar2 = FUN_00524388_str((const char*)(0x95c220));
  if (uVar2 >> 1 != 0) {
    uVar2 = FUN_00524388_str((const char*)(0x95c220));
    iVar10 = 0xe6;
    for (uVar12 = 0; uVar12 < uVar2 >> 1; uVar12 = uVar12 + 1) {
      FUN_00524828((void *)0x7ce6fc,(u8 *)DAT_0095c220 + uVar12 * 2,2);
      FUN_003b2cb0_va(0,iVar10,0x99,0xffffffffffffffff,5,0,0x7ce6fc,0,0);
      iVar10 = iVar10 + 0x1c;
    }
  }
  return;
}
#undef uStack_20
#undef uStack_1c
#undef uStack_18
#undef uStack_14
#undef uStack_10
#undef uStack_c
#undef fStack_8
#undef fStack_4

#pragma push
#pragma opt_loop_invariants on
// FUN_0045D990 NONMATCHING

void FUN_0045d990(int param_1,long param_2)

{
  int iVar1;
  short sVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  u32 uStack_c;
  float afStack_8 [2];
  
  
  iVar3 = *(int *)((int)param_1 + 0x3c);
  if ((-1 < param_2) && (lVar4 = FUN_0045b4b0(iVar3 + 0x178), lVar4 == 0)) {
    fVar9 = (float)FUN_0045b4e0(iVar3 + 0x178);
    fVar9 = fVar9 * 255.0f;
    if (2.1474836e+09f <= fVar9) {
      fVar9 = fVar9 - 2.1474836e+09f;
    }
    FUN_001159f0_3fv(0,0,0,param_1,(u8 *)DAT_007ce718,0xa4,
                     0xff - ((int)fVar9 & 0xffU) & 0xff);
  }
  if (0 < param_2) {
    FUN_0045cdd0(param_1,1);
    lVar4 = FUN_0045b4b0(iVar3 + 0x210);
    if (lVar4 == 0) {
      FUN_0045b420((iVar3 + 0x210),afStack_8);
      fVar9 = (float)FUN_0045b4e0(iVar3 + 0x210);
      fVar9 = fVar9 * 255.0f;
      if (2.1474836e+09f <= fVar9) {
        fVar9 = fVar9 - 2.1474836e+09f;
      }
      FUN_001159f0_3fv(4.0f,(float)(int)afStack_8[1],0,param_1,
                       (u8 *)DAT_007ce718,0,
                       0xff - ((int)fVar9 & 0xffU) & 0xff);
      FUN_001159f0_3fv(321.0f,(float)(int)afStack_8[1],0,param_1,
                       (u8 *)DAT_007ce718,1,
                       0xff - ((int)fVar9 & 0xffU) & 0xff);
    }
  }
  if (1 < param_2) {
    for (iVar8 = 0; iVar8 < 0x18; iVar8 = iVar8 + 1) {
      iVar6 = iVar3 + iVar8 * 0x98 + 0x340;
      lVar4 = FUN_0045b4b0(iVar6);
      if (lVar4 == 0) {
        fVar9 = (float)FUN_0045b4e0(iVar6);
        fVar9 = fVar9 * 255.0f;
        if (2.1474836e+09f <= fVar9) {
          fVar9 = fVar9 - 2.1474836e+09f;
        }
        FUN_001159f0_3fv((float)((iVar8 / 6) * 0x94 + 0x1b),
                         (float)((iVar8 % 6) * 0x19 + 0xe5),0,param_1,
                         (u8 *)DAT_007ce718,0x1b,
                         0xff - ((int)fVar9 & 0xffU) & 0xff);
      }
    }
  }
  if (1 < param_2) {
    for (iVar8 = 0; iVar8 < 6; iVar8 = iVar8 + 1) {
      iVar6 = iVar3 + iVar8 * 0x98;
      lVar4 = FUN_0045b4b0(iVar6 + 0x1180);
      if (lVar4 == 0) {
        for (iVar5 = 0; iVar5 < 0x14; iVar5 = iVar5 + 1) {
          sVar2 = *(short *)((u8 *)DAT_007bc730 + iVar5 * 2 + iVar8 * 0x28);
          if (-1 < sVar2) {
            iVar7 = (iVar5 % 5) * 0x1b;
            iVar1 = iVar5 / 5;
            if (iVar1 == 3) {
              iVar7 = iVar7 + 0x1da;
            }
            else if (iVar1 == 2) {
              iVar7 = iVar7 + 0x146;
            }
            else if (iVar1 == 1) {
              iVar7 = iVar7 + 0xb2;
            }
            else if (iVar1 == 0) {
              iVar7 = iVar7 + 0x1e;
            }
            fVar9 = (float)FUN_0045b4e0(iVar6 + 0x1180);
            fVar9 = fVar9 * 230.0f;
            if (2.1474836e+09f <= fVar9) {
              fVar9 = fVar9 - 2.1474836e+09f;
            }
            FUN_0045b420((iVar6 + 0x1180),afStack_8);
            FUN_00115bc0_3fv((float)iVar7,(float)(iVar8 * 0x19 + 0xe5 + (int)afStack_8[1]),0,uStack_c,
                         DAT_007ce718,sVar2 + 0x20,0xff - ((int)fVar9 & 0xffU) & 0xff,0x2e,0x3c,0x44);
          }
        }
      }
    }
  }
  return;
}

#pragma alias DAT_007ce700_y2 DAT_007ce700
extern u8 DAT_006b4c00[];
extern u32 DAT_007ce700_y2;
#pragma alias FUN_003c72d0_y2 FUN_003c72d0
#pragma alias FUN_003c7430_y2 FUN_003c7430
#pragma alias FUN_003c74e0_y2 FUN_003c74e0
#pragma alias FUN_003c7560_y2 FUN_003c7560
#pragma alias FUN_003c75b0_y2 FUN_003c75b0
#pragma alias FUN_003c77a0_y2 FUN_003c77a0
#pragma alias FUN_003c7850_y2 FUN_003c7850
#pragma alias FUN_003c78d0_y2 FUN_003c78d0
#pragma alias FUN_003c7b90_y2 FUN_003c7b90
extern void FUN_003c72d0_y2(void *param_1);
extern void FUN_003c7430_y2(int param_1);
extern void FUN_003c74e0_y2(int param_1);
extern void FUN_003c7560_y2(int param_1);
extern u32 FUN_003c75b0_y2(void);
extern void FUN_003c77a0_y2(void);
extern u32 FUN_003c7850_y2(void);
extern u32 FUN_003c78d0_y2(void);
extern void FUN_003c7b90_y2(void);
// FUN_0045DF00
u32 FUN_0045df00(int param_1)
{
  int *state;
  int mode;

  state = (int *)*(u32 *)(param_1 + 0x3c);
  mode = state[4];
  switch (mode) {
  case 0:
    DAT_007ce700_y2 = 0;
    FUN_003c77a0_y2();
    FUN_003c72d0_y2(DAT_006b4c00);
    FUN_003c7430_y2(1);
    FUN_003c74e0_y2(0);
    FUN_003c7560_y2(0);
    state[4] = 1;
    break;
  case 1:
    if (FUN_003c7850_y2() != 0) {
      FUN_003c7b90_y2();
      if (FUN_003c78d0_y2() == 0) {
        DAT_007ce700_y2 = FUN_003c75b0_y2();
      }
    }
    else {
      state[4] = 2;
    }
    break;
  case 2:
    FUN_003c77a0_y2();
    state[4] = 0;
    return DAT_007ce700_y2;
  default:
    break;
  }
  return 0xffffffff;
}
// FUN_0045E010
u8 FUN_0045e010(int param_1)
{
  int iVar1;
  int lVar2;

  iVar1 = *(int *)(param_1 + 0x3c);
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_0045af90(iVar1 + 0x178);
    FUN_0045afd0_call3(iVar1 + 0x178,0,0,0,0,DAT_007cafc0,0,10,0x14);
    *(u32 *)(iVar1 + 8) = 1;
  }
  FUN_0045b190_arg(iVar1 + 0x178);
  lVar2 = FUN_0045b480(iVar1 + 0x178);
  if (lVar2 == 0) {
    *(u32 *)(iVar1 + 8) = 0;
    return 1;
  }
  return 0;
}

// FUN_0045E0C0

u8 FUN_0045e0c0(int param_1)

{
  int iVar1;
  int lVar2;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  if (*(int *)(iVar1 + 8) == 0) {
    FUN_0045af90(iVar1 + 0x210);
    FUN_0045afd0_call3(iVar1 + 0x210,4,0xe3,4,0xc5,DAT_007cafc0,0,0,10);
    *(u32 *)(iVar1 + 8) = 1;
  }
  FUN_0045b190_arg(iVar1 + 0x210);
  lVar2 = FUN_0045b480(iVar1 + 0x210);
  if (lVar2 == 0) {
    *(u32 *)(iVar1 + 8) = 0;
    return 1;
  }
  return 0;
}

#pragma pop
#pragma push
#pragma opt_loop_invariants on
// FUN_0045E170 NONMATCHING

u8 FUN_0045e170(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  if (*(int *)(iVar1 + 8) == 0) {
    DAT_007ce704 = 0;
    *(u32 *)(iVar1 + 8) = 1;
  }
  if ((DAT_007ce704 < 6) && (*(int *)(iVar1 + 0x18) % 6 == 0)) {
    for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
      iVar4 = iVar1 + (DAT_007ce704 + iVar3 * 6) * 0x98 + 0x340;
      FUN_0045af90(iVar4);
      FUN_0045afd0(DAT_007cafc0,iVar4,0,0,0,0,0,0,6);
    }
    FUN_0045afd0(DAT_007cafc0,iVar1 + DAT_007ce704 * 0x98 + 0x1180,0,0xfffffffffffffffe,0,0,0,0,0xc)
    ;
    DAT_007ce704 = DAT_007ce704 + 1;
  }
  for (iVar3 = 0; iVar3 < 0x18; iVar3 = iVar3 + 1) {
    iVar4 = iVar1 + iVar3 * 0x98 + 0x340;
    iVar2 = FUN_0045b4b0(iVar4);
    if (iVar2 == 0) {
      FUN_0045b190(iVar4);
    }
  }
  iVar4 = 0;
  for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
    iVar2 = FUN_0045b4b0(iVar1 + iVar3 * 0x98 + 0x1180);
    if (iVar2 == 0) {
      iVar5 = iVar1 + iVar3 * 0x98 + 0x1180;
      FUN_0045b190(iVar5);
      iVar2 = FUN_0045b480(iVar5);
      if (iVar2 == 0) {
        iVar4 = iVar4 + 1;
      }
    }
  }
  if (iVar4 != 6) {
    *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + 1;
  }
  else {
    *(u32 *)(iVar1 + 8) = 0;
    *(u32 *)(iVar1 + 0x18) = 0;
  }
  return iVar4 == 6;
}

#pragma pop
#pragma push
#pragma opt_loop_invariants on
// FUN_0045E3E0 NONMATCHING

u32 FUN_0045e3e0(int param_1)

{
  u32 *puVar1;
  long lVar2;
  int iVar3;
  float fVar4;
  
  puVar1 = *(u32 **)((int)param_1 + 0x3c);
  if (DAT_007ce718 == 0) {
    return 0;
  }
  iVar3 = puVar1[1];
  if (iVar3 == 3) {
    return 0xffffffff;
  }
  if (iVar3 == 2) {
    if (puVar1[5] == 1) {
      FUN_0045bd90_arg(param_1);
      if ((puVar1[5] != 2) && (puVar1[5] == 3)) {
        puVar1[2] = 0;
        puVar1[4] = 0;
      }
    }
    else if (puVar1[5] == 3) {
      if (puVar1[2] == 0) {
        lVar2 = FUN_0045df00(param_1);
        if (lVar2 == 0) {
          iVar3 = 0xe;
          do {
            lVar2 = FUN_00524670_typed((u64)(0x7cdb14),(u8(*)[16])((u8 *)DAT_0095c240 + iVar3),2);
            if (lVar2 != 0) break;
            ((u8 *)DAT_0095c240)[iVar3] = 0;
            ((u8 *)DAT_0095c241)[iVar3] = 0;
            iVar3 = iVar3 + -2;
          } while (-1 < iVar3);
          iVar3 = 0xe;
          do {
            lVar2 = FUN_00524670_typed((u64)(0x7cdb14),(u8(*)[16])((u8 *)DAT_0095c220 + iVar3),2);
            if (lVar2 != 0) break;
            ((u8 *)DAT_0095c220)[iVar3] = 0;
            ((u8 *)DAT_0095c221)[iVar3] = 0;
            iVar3 = iVar3 + -2;
          } while (-1 < iVar3);
          FUN_00177410_typed((u8 *)(DAT_0095c240),(u8 *)(DAT_0095c220));
          puVar1[6] = 0;
          puVar1[2] = 1;
        }
        else if (lVar2 == 1) {
          puVar1[5] = 1;
        }
      }
      else {
        if (puVar1[6] == 0) {
          FUN_00108fd0_va(0x1e);
        }
        if (0x1d < (int)puVar1[6]) {
          puVar1[6] = 0;
          puVar1[1] = 3;
          return 0;
        }
        puVar1[6] = puVar1[6] + 1;
      }
    }
    FUN_0045ce90(param_1);
    if ((puVar1[5] == 3) && (puVar1[2] == 1)) {
      fVar4 = ((float)(int)puVar1[6] * 255.0f) / 30.0f;
      if (2.1474836e+09f <= fVar4) {
        fVar4 = fVar4 - 2.1474836e+09f;
      }
      FUN_00113a30_va(0,0,0,(int)fVar4 & 0xff,0x280,0x1e0);
    }
  }
  else if (iVar3 == 1) {
    if (((int)puVar1[3] < 3) && (lVar2 = (*(code *)((u8 *)PTR_FUN_006b4e60)[puVar1[3]])(), lVar2 == 1)) {
      puVar1[3] = puVar1[3] + 1;
    }
    FUN_0045d990(param_1,puVar1[3]);
    if (2 < (int)puVar1[3]) {
      puVar1[3] = 0;
      puVar1[2] = 0;
      puVar1[6] = 0;
      puVar1[5] = 1;
      puVar1[1] = 2;
      puVar1[0x70d] = 0;
      FUN_0045b830(param_1,0);
    }
  }
  else if (iVar3 == 0) {
    for (iVar3 = 0; iVar3 < 6; iVar3 = iVar3 + 1) {
      *(u16 *)(puVar1 + iVar3 + 0x70e) = 3;
      *(u16 *)((int)puVar1 + iVar3 * 4 + 0x1c3a) = 0;
    }
    *puVar1 = 0;
    puVar1[5] = 0;
    puVar1[1] = 1;
  }
  return 0;
}
#pragma pop

// FUN_0045E7B0

void FUN_0045e7b0(int param_1)

{
  DAT_0096017c_abs[0](*(u32 *)(param_1 + 0x3c));
  return;
}
