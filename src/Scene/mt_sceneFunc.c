#include "temporary.h"
#include "Scene/mt_sceneFunc.h"
#include "Scene/mt_scene.h"
#include "Scene/resrcManager.h"
#include "Kernel/Kwln/kwlnTask.h"
#include "libm.h"
#include "Event/Comu/comuFunction.h"

extern u32 DAT_007ce420;
extern u32 DAT_007ce66c;
#pragma alias DAT_0095b070_raw_abs DAT_0095b070
extern u8 DAT_0095b070_raw_abs[];
extern u32 FUN_0035bb40(u32 param_1,u32 param_2,u32 param_3);
extern u32 FUN_0017e050(long param_1,long param_2,long param_3);
extern u32 FUN_0027c2b0(void);
extern u32 FUN_0027c330(void);
extern u32 FUN_0016dce0(s16 param_1);
extern void K_Assert(const char *file,s32 line);
extern char D_006A3280[];
extern s8 datGetSocialLinkLevel(s16 socialLink);
extern u32 datSocialLinkLevelIsNotZero(s16 socialLink);
extern u32 func_00172a50(s32 socialLink);
extern u32 func_00171960(s32 socialLink,s16 value);
extern s8 func_0016dd20(s16 socialLink);
extern void func_0016e410(s16 socialLink,s8 level);
extern s32 func_003c2570(s32 socialLink);
extern s32 clndGetCurrentMonth(void);
extern s32 clndGetCurrentDay(void);
extern u32 func_003c2b40(s32 *month,s32 *day);
extern u32 func_003c2c50(u8 socialLink);
extern s8 func_0016df30(s16 socialLink);
extern u32 datGetNextExp(s16 pcId);
extern u32 func_0016d280(s32 exp);
extern s16 *datGetActiveSocialLinkPtr(void);
extern u32 func_003c3e80(s32 param_1);
extern u32 adminiGetNowSeqId(void);
extern u32 adminiGetNextSeqId(void);
extern s32 FUN_00172160(long socialLink);
extern s32 FUN_001717c0(long socialLink);
extern s32 FUN_00172660(long socialLink);
#pragma alias FUN_003be1c0_typed FUN_003be1c0
extern u32 FUN_003be1c0_typed(long param_1,s32 param_2);
#pragma alias FUN_003be1c0_wide FUN_003be1c0
extern u32 FUN_003be1c0_wide(long param_1,long param_2);
#pragma alias FUN_003be2a0_typed FUN_003be2a0
extern u32 FUN_003be2a0_typed(...);
#pragma alias FUN_003be020_typed FUN_003be020
extern u32 FUN_003be020_typed(u32 param_1, u8 *param_2, u32 param_3);
extern void adminiChangeSeq(s32 type,void *seq,s32 size,s32 arg4);
extern void FUN_0016f1f0(int param_1,int param_2);
#pragma alias FUN_0016f190_comu FUN_0016f190
extern u32 FUN_0016f190_comu(int param_1);
extern u32 DAT_0095b280;
extern u16* DAT_0095b2a0;
#pragma alias DAT_0095b2a0_abs DAT_0095b2a0
extern u8 DAT_0095b2a0_abs[];
#pragma alias DAT_0095b2a8_abs DAT_0095b2a8
extern u8 DAT_0095b2a8_abs[];
extern u32 DAT_0095b2a8;
#pragma alias DAT_0095b710_ptr_abs DAT_0095b710
extern u8 *DAT_0095b710_ptr_abs[];
extern u32 DAT_0095b730;
extern u32 LAB_003be5a0;

typedef int (*code)(...);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))
#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif
#ifndef ABS
#define ABS(x) ((x) < 0 ? -(x) : (x))
#endif
extern u32 DAT_0067ef00;
extern u32 DAT_006a2da0;
extern u32 DAT_006a2da8;
#pragma alias DAT_0067ef00_abs DAT_0067ef00
extern int DAT_0067ef00_abs[];
#pragma alias DAT_006a2da0_abs DAT_006a2da0
extern u8 DAT_006a2da0_abs[];
#pragma alias DAT_006a2da8_abs DAT_006a2da8
extern u8 DAT_006a2da8_abs[];
#pragma alias DAT_006a2f18_abs DAT_006a2f18
extern u8 DAT_006a2f18_abs[];
#pragma alias DAT_006a2f20_abs DAT_006a2f20
extern u8 DAT_006a2f20_abs[];
#pragma alias DAT_006a2f28_abs DAT_006a2f28
extern u8 DAT_006a2f28_abs[];
#pragma alias DAT_006a2f30_abs DAT_006a2f30
extern u8 DAT_006a2f30_abs[];
#pragma alias DAT_006a2f38_abs DAT_006a2f38
extern u8 DAT_006a2f38_abs[];
#pragma alias DAT_006a2f40_abs DAT_006a2f40
extern u8 DAT_006a2f40_abs[];
extern u32 DAT_006a2ed8;
extern u32 DAT_006a2ee0;
extern u32 DAT_006a2ee8;
extern u32 DAT_006a2ef0;
extern u32 DAT_006a2ef8;
extern u32 DAT_006a2f00;
extern u32 DAT_006a2f08;
extern u32 DAT_006a2f10;
#pragma alias DAT_006a2ed8_abs DAT_006a2ed8
extern u8 DAT_006a2ed8_abs[];
#pragma alias DAT_006a2ee0_abs DAT_006a2ee0
extern u8 DAT_006a2ee0_abs[];
#pragma alias DAT_006a2ee8_abs DAT_006a2ee8
extern u8 DAT_006a2ee8_abs[];
#pragma alias DAT_006a2ef0_abs DAT_006a2ef0
extern u8 DAT_006a2ef0_abs[];
#pragma alias DAT_006a2ef8_abs DAT_006a2ef8
extern u8 DAT_006a2ef8_abs[];
#pragma alias DAT_006a2f00_abs DAT_006a2f00
extern u8 DAT_006a2f00_abs[];
#pragma alias DAT_006a2f08_abs DAT_006a2f08
extern u8 DAT_006a2f08_abs[];
#pragma alias DAT_006a2f10_abs DAT_006a2f10
extern u8 DAT_006a2f10_abs[];
extern u32 DAT_006a2f18;
extern u32 DAT_006a2f20;
extern u32 DAT_006a2f28;
extern u32 DAT_006a2f30;
extern u32 DAT_006a2f38;
extern u32 DAT_006a2f40;
extern u32 DAT_006a2f48;
extern char DAT_006a2e10[];
extern char DAT_006a2df0[];
extern u32 DAT_006a2f50;
extern f32 DAT_007cad5c;
extern f32 DAT_007cada0;
extern u32 DAT_007caea4;
extern f32 DAT_007caf1c;
extern f32 DAT_007cb0b8;
extern f32 DAT_007cd560;
extern f32 DAT_007cd564;
extern u16 DAT_007ce658;
extern s16 DAT_007ce65c;
extern u16 DAT_007ce660;
extern u16 DAT_007ce664;
extern u32 DAT_007ce668;
extern f32 DAT_0095aff0;
extern f32 DAT_0095aff4;
extern f32 DAT_0095aff8;
extern f32 DAT_0095affc;
#pragma alias DAT_0095aff0_abs DAT_0095aff0
extern u8 DAT_0095aff0_abs[];
extern u32 DAT_0095b000;
extern short * DAT_0095b070;
#pragma alias DAT_0095b070_ptr DAT_0095b070
extern u8 DAT_0095b070_ptr[];
extern u32 DAT_0095b074;
extern u32 DAT_0095b078;
extern u32 DAT_0095b0f8;
extern u32 DAT_0095b178;
extern u32 DAT_0095b1f8;
extern u32 DAT_0095b204;
extern u32 DAT_0095b208;
extern u32 DAT_0095b20c;
extern u32 DAT_0095b210;
extern u32 DAT_0095b218;
extern u32 DAT_0095b21c;
extern u32 DAT_0095b220;
extern u32 DAT_0095b224;
extern u32 DAT_0095b238;
extern u32 DAT_0095b240;
extern u32 DAT_0095b244;
extern u32 DAT_0095b248;
extern u32 DAT_0095b24c;
extern u32 DAT_0095b254;
extern u32 DAT_0095b258;
extern u32 DAT_0095b25c;
extern u32 DAT_0095b260;
extern u32 DAT_0095b264;
extern u32 DAT_0095b268;
extern u32 DAT_0095b26c;
extern u32 DAT_0095b270;
extern u32 DAT_0095b274;
extern u32 DAT_0095b278;
extern u32 DAT_0095b27c;
extern u32 DAT_0095b284;
extern u32 DAT_0095b288;
extern u32 * DAT_0095b28c;
extern u32 DAT_0095b290;
extern u32 DAT_0095b294;
extern u32 DAT_0095b298;
extern u16 * DAT_0095b29c;
extern u32 DAT_0095b2a4;
extern u32 DAT_0095b2b4;
extern u32 DAT_0095b434;
extern u32 DAT_0095b440;
extern u32 DAT_0095b444;
extern u32 DAT_0095b448;
extern u32 DAT_0095b44c;
extern u32 DAT_0095b454;
extern u32 DAT_0095b458;
extern u32 DAT_0095b45c;
extern u32 DAT_0095b460;
extern u32 DAT_0095b474;
extern u32 DAT_0095b47c;
extern u32 DAT_0095b480;
extern u32 DAT_0095b484;
extern u32 DAT_0095b488;
extern u32 DAT_0095b4a0;
extern u32 DAT_0095b4a8;
extern u32 DAT_0095b4b4;
extern u32 DAT_0095b4c0;
extern u32 DAT_0095b4d0;
extern u32 DAT_0095b4d4;
extern u32 DAT_0095b4e0;
extern u32 DAT_0095b4f0;
extern u32 DAT_0095b568;
extern u32 DAT_0095b5e0;
extern u32 DAT_0095b658;
#pragma alias DAT_0095b658_ptr DAT_0095b658
extern u8 DAT_0095b658_ptr[];
extern u32 DAT_0095b65c;
extern u32 DAT_0095b660;
#pragma alias DAT_0095b660_ptr DAT_0095b660
extern u8 DAT_0095b660_ptr[];
extern u32 DAT_0095b664;
extern u32 DAT_0095b668;
#pragma alias DAT_0095b668_ptr DAT_0095b668
extern u8 DAT_0095b668_ptr[];
extern u32 DAT_0095b66c;
extern u32 DAT_0095b670;
extern u32 DAT_0095b674;
extern u32 DAT_0095b678;
extern u32 DAT_0095b67c;
extern u32 DAT_0095b680;
extern u32 DAT_0095b684;
extern u32 DAT_0095b688;
extern u32 DAT_0095b68c;
extern u32 DAT_0095b690;
extern u32 DAT_0095b694;
extern u32 DAT_0095b698;
extern u32 DAT_0095b69c;
extern u32 DAT_0095b6a0;
extern u32 DAT_0095b6a4;
extern u32 DAT_0095b6a8;
extern u32 DAT_0095b6ac;
extern u32 DAT_0095b6b0;
extern u32 DAT_0095b6b4;
extern u32 DAT_0095b6b8;
extern u32 DAT_0095b6bc;
extern u32 DAT_0095b6c0;
extern u32 DAT_0095b6c4;
extern u32 DAT_0095b6c8;
extern u32 DAT_0095b6cc;
extern u32 DAT_0095b6d0;
extern u32 DAT_0095b6d4;
extern u32 DAT_0095b6d8;
extern u32 DAT_0095b6dc;
extern u32 DAT_0095b6e0;
extern u32 DAT_0095b6e4;
extern u32 DAT_0095b6e8;
extern u32 DAT_0095b6ec;
extern u32 DAT_0095b6f0;
extern u32 * DAT_0095b6f4;
extern u32 DAT_0095b6f8;
extern u32 DAT_0095b6fc;
extern u32 DAT_0095b700;
extern u32 DAT_0095b704;
extern u32 DAT_0095b708;
extern u32 DAT_0095b70c;
extern u32 DAT_0095b710;
extern u32 DAT_0095b714;
extern u32 DAT_0095b718;
extern u32 DAT_0095b71c;
extern u32 DAT_0095b720;
extern u32 DAT_0095b724;
extern u32 DAT_0095b728;
#pragma alias DAT_0095b070_abs DAT_0095b070
extern u8 DAT_0095b070_abs[];

#pragma alias DAT_0095b074_abs DAT_0095b074
#pragma alias DAT_0095b078_abs DAT_0095b078
#pragma alias DAT_0095b0f8_abs DAT_0095b0f8
#pragma alias DAT_0095b178_abs DAT_0095b178
#pragma alias DAT_0095b1f8_abs DAT_0095b1f8
#pragma alias DAT_0095b204_abs DAT_0095b204
#pragma alias DAT_0095b208_abs DAT_0095b208
#pragma alias DAT_0095b20c_abs DAT_0095b20c
#pragma alias DAT_0095b210_abs DAT_0095b210
#pragma alias DAT_0095b218_abs DAT_0095b218
#pragma alias DAT_0095b21c_abs DAT_0095b21c
#pragma alias DAT_0095b220_abs DAT_0095b220
#pragma alias DAT_0095b224_abs DAT_0095b224
#pragma alias DAT_0095b238_abs DAT_0095b238
#pragma alias DAT_0095b240_abs DAT_0095b240
#pragma alias DAT_0095b244_abs DAT_0095b244
#pragma alias DAT_0095b248_abs DAT_0095b248
#pragma alias DAT_0095b24c_abs DAT_0095b24c
#pragma alias DAT_0095b254_abs DAT_0095b254
#pragma alias DAT_0095b258_abs DAT_0095b258
#pragma alias DAT_0095b25c_abs DAT_0095b25c
#pragma alias DAT_0095b260_abs DAT_0095b260
#pragma alias DAT_0095b264_abs DAT_0095b264
#pragma alias DAT_0095b268_abs DAT_0095b268
#pragma alias DAT_0095b26c_abs DAT_0095b26c
#pragma alias DAT_0095b270_abs DAT_0095b270
#pragma alias DAT_0095b274_abs DAT_0095b274
#pragma alias DAT_0095b278_abs DAT_0095b278
#pragma alias DAT_0095b27c_abs DAT_0095b27c
#pragma alias DAT_0095b284_abs DAT_0095b284
#pragma alias DAT_0095b288_abs DAT_0095b288
#pragma alias DAT_0095b290_abs DAT_0095b290
#pragma alias DAT_0095b294_abs DAT_0095b294
#pragma alias DAT_0095b298_abs DAT_0095b298
#pragma alias DAT_0095b2a4_abs DAT_0095b2a4
#pragma alias DAT_0095b2b4_abs DAT_0095b2b4
#pragma alias DAT_0095b434_abs DAT_0095b434
#pragma alias DAT_0095b440_abs DAT_0095b440
#pragma alias DAT_0095b444_abs DAT_0095b444
#pragma alias DAT_0095b448_abs DAT_0095b448
#pragma alias DAT_0095b44c_abs DAT_0095b44c
#pragma alias DAT_0095b454_abs DAT_0095b454
#pragma alias DAT_0095b458_abs DAT_0095b458
#pragma alias DAT_0095b45c_abs DAT_0095b45c
#pragma alias DAT_0095b460_abs DAT_0095b460
#pragma alias DAT_0095b474_abs DAT_0095b474
#pragma alias DAT_0095b47c_abs DAT_0095b47c
#pragma alias DAT_0095b480_abs DAT_0095b480
#pragma alias DAT_0095b484_abs DAT_0095b484
#pragma alias DAT_0095b488_abs DAT_0095b488
#pragma alias DAT_0095b4a0_abs DAT_0095b4a0
#pragma alias DAT_0095b4a8_abs DAT_0095b4a8
#pragma alias DAT_0095b4b4_abs DAT_0095b4b4
#pragma alias DAT_0095b4c0_abs DAT_0095b4c0
#pragma alias DAT_0095b4d0_abs DAT_0095b4d0
#pragma alias DAT_0095b4d4_abs DAT_0095b4d4
#pragma alias DAT_0095b4e0_abs DAT_0095b4e0
#pragma alias DAT_0095b4f0_abs DAT_0095b4f0
#pragma alias DAT_0095b568_abs DAT_0095b568
#pragma alias DAT_0095b5e0_abs DAT_0095b5e0
#pragma alias DAT_0095b658_abs DAT_0095b658
#pragma alias DAT_0095b65c_abs DAT_0095b65c
#pragma alias DAT_0095b660_abs DAT_0095b660
#pragma alias DAT_0095b664_abs DAT_0095b664
#pragma alias DAT_0095b668_abs DAT_0095b668
#pragma alias DAT_0095b66c_abs DAT_0095b66c
#pragma alias DAT_0095b670_abs DAT_0095b670
#pragma alias DAT_0095b674_abs DAT_0095b674
#pragma alias DAT_0095b678_abs DAT_0095b678
#pragma alias DAT_0095b67c_abs DAT_0095b67c
#pragma alias DAT_0095b680_abs DAT_0095b680
#pragma alias DAT_0095b684_abs DAT_0095b684
#pragma alias DAT_0095b688_abs DAT_0095b688
#pragma alias DAT_0095b68c_abs DAT_0095b68c
#pragma alias DAT_0095b690_abs DAT_0095b690
#pragma alias DAT_0095b694_abs DAT_0095b694
#pragma alias DAT_0095b698_abs DAT_0095b698
#pragma alias DAT_0095b69c_abs DAT_0095b69c
#pragma alias DAT_0095b6a0_abs DAT_0095b6a0
#pragma alias DAT_0095b6a4_abs DAT_0095b6a4
#pragma alias DAT_0095b6a8_abs DAT_0095b6a8
#pragma alias DAT_0095b6ac_abs DAT_0095b6ac
#pragma alias DAT_0095b6b0_abs DAT_0095b6b0
#pragma alias DAT_0095b6b4_abs DAT_0095b6b4
#pragma alias DAT_0095b6b8_abs DAT_0095b6b8
#pragma alias DAT_0095b6bc_abs DAT_0095b6bc
#pragma alias DAT_0095b6c0_abs DAT_0095b6c0
#pragma alias DAT_0095b6c4_abs DAT_0095b6c4
#pragma alias DAT_0095b6c8_abs DAT_0095b6c8
#pragma alias DAT_0095b6cc_abs DAT_0095b6cc
#pragma alias DAT_0095b6d0_abs DAT_0095b6d0
#pragma alias DAT_0095b6d4_abs DAT_0095b6d4
#pragma alias DAT_0095b6d8_abs DAT_0095b6d8
#pragma alias DAT_0095b6dc_abs DAT_0095b6dc
#pragma alias DAT_0095b6e0_abs DAT_0095b6e0
#pragma alias DAT_0095b6e4_abs DAT_0095b6e4
#pragma alias DAT_0095b6e8_abs DAT_0095b6e8
#pragma alias DAT_0095b6ec_abs DAT_0095b6ec
#pragma alias DAT_0095b6f0_abs DAT_0095b6f0
#pragma alias DAT_0095b6f4_abs DAT_0095b6f4
#pragma alias DAT_0095b6f8_abs DAT_0095b6f8
#pragma alias DAT_0095b6fc_abs DAT_0095b6fc
#pragma alias DAT_0095b700_abs DAT_0095b700
#pragma alias DAT_0095b704_abs DAT_0095b704
#pragma alias DAT_0095b708_abs DAT_0095b708
#pragma alias DAT_0095b70c_abs DAT_0095b70c
#pragma alias DAT_0095b710_abs DAT_0095b710
#pragma alias DAT_0095b714_abs DAT_0095b714
#pragma alias DAT_0095b718_abs DAT_0095b718
#pragma alias DAT_0095b71c_abs DAT_0095b71c
#pragma alias DAT_0095b720_abs DAT_0095b720
#pragma alias DAT_0095b724_abs DAT_0095b724
#pragma alias DAT_0095b728_abs DAT_0095b728
extern u8 DAT_0095b070_abs[];
extern u8 DAT_0095b074_abs[];
extern u8 DAT_0095b078_abs[];
extern u8 DAT_0095b0f8_abs[];
extern u8 DAT_0095b178_abs[];
extern u8 DAT_0095b1f8_abs[];
extern u8 DAT_0095b204_abs[];
extern u8 DAT_0095b208_abs[];
extern u8 DAT_0095b20c_abs[];
extern u8 DAT_0095b210_abs[];
extern u8 DAT_0095b218_abs[];
extern u8 DAT_0095b21c_abs[];
extern u8 DAT_0095b220_abs[];
extern u8 DAT_0095b224_abs[];
extern u8 DAT_0095b238_abs[];
extern u8 DAT_0095b240_abs[];
extern u8 DAT_0095b244_abs[];
extern u8 DAT_0095b248_abs[];
extern u8 DAT_0095b24c_abs[];
extern u8 DAT_0095b254_abs[];
extern u8 DAT_0095b258_abs[];
extern u8 DAT_0095b25c_abs[];
extern u8 DAT_0095b260_abs[];
extern u8 DAT_0095b264_abs[];
extern u8 DAT_0095b268_abs[];
extern u8 DAT_0095b26c_abs[];
extern u8 DAT_0095b270_abs[];
extern u8 DAT_0095b274_abs[];
extern u8 DAT_0095b278_abs[];
extern u8 DAT_0095b27c_abs[];
extern u8 DAT_0095b284_abs[];
extern u8 DAT_0095b288_abs[];
extern u8 DAT_0095b290_abs[];
extern u8 DAT_0095b294_abs[];
extern u8 DAT_0095b298_abs[];
extern u8 DAT_0095b2a4_abs[];
extern u8 DAT_0095b2b4_abs[];
extern u8 DAT_0095b434_abs[];
extern u8 DAT_0095b440_abs[];
extern u8 DAT_0095b444_abs[];
extern u8 DAT_0095b448_abs[];
extern u8 DAT_0095b44c_abs[];
extern u8 DAT_0095b454_abs[];
extern u8 DAT_0095b458_abs[];
extern u8 DAT_0095b45c_abs[];
extern u8 DAT_0095b460_abs[];
extern u8 DAT_0095b474_abs[];
extern u8 DAT_0095b47c_abs[];
extern u8 DAT_0095b480_abs[];
extern u8 DAT_0095b484_abs[];
extern u8 DAT_0095b488_abs[];
extern u8 DAT_0095b4a0_abs[];
extern u8 DAT_0095b4a8_abs[];
extern u8 DAT_0095b4b4_abs[];
extern u8 DAT_0095b4c0_abs[];
extern u8 DAT_0095b4d0_abs[];
extern u8 DAT_0095b4d4_abs[];
extern u8 DAT_0095b4e0_abs[];
extern u8 DAT_0095b4f0_abs[];
extern u8 DAT_0095b568_abs[];
extern u8 DAT_0095b5e0_abs[];
extern u8 DAT_0095b658_abs[];
extern u8 DAT_0095b65c_abs[];
extern u8 DAT_0095b660_abs[];
extern u8 DAT_0095b664_abs[];
extern u8 DAT_0095b668_abs[];
extern u8 DAT_0095b66c_abs[];
extern u8 DAT_0095b670_abs[];
extern u8 DAT_0095b674_abs[];
extern u8 DAT_0095b678_abs[];
extern u8 DAT_0095b67c_abs[];
extern u8 DAT_0095b680_abs[];
extern u8 DAT_0095b684_abs[];
extern u8 DAT_0095b688_abs[];
extern u8 DAT_0095b68c_abs[];
extern u8 DAT_0095b690_abs[];
extern u8 DAT_0095b694_abs[];
extern u8 DAT_0095b698_abs[];
extern u8 DAT_0095b69c_abs[];
extern u8 DAT_0095b6a0_abs[];
extern u8 DAT_0095b6a4_abs[];
extern u8 DAT_0095b6a8_abs[];
extern u8 DAT_0095b6ac_abs[];
extern u8 DAT_0095b6b0_abs[];
extern u8 DAT_0095b6b4_abs[];
extern u8 DAT_0095b6b8_abs[];
extern u8 DAT_0095b6bc_abs[];
extern u8 DAT_0095b6c0_abs[];
extern u8 DAT_0095b6c4_abs[];
extern u8 DAT_0095b6c8_abs[];
extern u8 DAT_0095b6cc_abs[];
extern u8 DAT_0095b6d0_abs[];
extern u8 DAT_0095b6d4_abs[];
extern u8 DAT_0095b6d8_abs[];
extern u8 DAT_0095b6dc_abs[];
extern u8 DAT_0095b6e0_abs[];
extern u8 DAT_0095b6e4_abs[];
extern u8 DAT_0095b6e8_abs[];
extern u8 DAT_0095b6ec_abs[];
extern u8 DAT_0095b6f0_abs[];
extern u8 DAT_0095b6f4_abs[];
extern u8 DAT_0095b6f8_abs[];
extern u8 DAT_0095b6fc_abs[];
extern u8 DAT_0095b700_abs[];
extern u8 DAT_0095b704_abs[];
extern u8 DAT_0095b708_abs[];
extern u8 DAT_0095b70c_abs[];
extern u8 DAT_0095b710_abs[];
extern u8 DAT_0095b714_abs[];
extern u8 DAT_0095b718_abs[];
extern u8 DAT_0095b71c_abs[];
extern u8 DAT_0095b720_abs[];
extern u8 DAT_0095b724_abs[];
extern u8 DAT_0095b728_abs[];

 

extern code DAT_00960178;
extern code DAT_0096017c;
extern code DAT_00960184;
extern u8 * PTR_s_event_SiteibiEvent_bf_007cd570;
extern u8 * PTR_s_event_comuPack_pak_007cd568;
extern u8 * PTR_s_event_comuTable_bin_007cd56c;
extern u8 * PTR_s_icon_ICON1_EPL_006a3130[];
extern u16 * puGpffffa850;
extern float fGpffff8228;
extern code DAT_00960178;
extern code DAT_0096017c;
extern code DAT_00960184;

extern float FUN_004c69f0();
#pragma alias FUN_003951d0_i32 FUN_003951d0
extern int FUN_003951d0_i32(int param_1);
extern float FUN_004c6ac0();
#pragma alias FUN_004c6ac0_scene_vec FUN_004c6ac0
extern float FUN_004c6ac0_scene_vec(const RwV3d *param_1);
#pragma alias FUN_004c69f0_scene_typed FUN_004c69f0
extern float FUN_004c69f0_scene_typed(float *dst,const float *src);
#pragma alias FUN_0052e9a0_scene_typed FUN_0052e9a0
extern u32 FUN_0052e9a0_scene_typed(u32 value);
#pragma alias FUN_005318a0_scene_typed FUN_005318a0
extern float FUN_005318a0_scene_typed(u32 value);
typedef struct SceneVecBits {
  u64 xy;
  float z;
} __attribute__((packed)) SceneVecBits;
#pragma alias DAT_006a2f48_abs DAT_006a2f48
extern SceneVecBits DAT_006a2f48_abs[];
#pragma alias DAT_006a2f50_abs DAT_006a2f50
extern float DAT_006a2f50_abs[];
void FUN_003bcc80();
void FUN_003bceb0(int param);
void FUN_0034fd70(Model* mdl, s32 type);
void FUN_003bc940();
void FUN_003b9610(Resrc* param);
void FUN_003bb7a0(Resrc* param);

typedef struct ResrcType7 ResrcType7;
struct ResrcType7
{
    Resrc base;
    u8 unkData_100[8];
    s32 unk_108;
};

typedef struct SceneInterpWork SceneInterpWork;
struct SceneInterpWork
{
  u8 pad0[0x10];
  float value10;
  float value14;
  float value18;
  u8 pad1[0xc];
  u32 flags28;
  u8 pad2[0x38];
  float value64;
  float value68;
  float value6c;
  float value70;
  float value74;
  float value78;
  u8 value7c;
  u8 value7d;
  u8 pad3[2];
  u32 value80;
  u32 value84;
};



/* Region 0x390000-0x3CFFFF recovered prototypes */
void* MT_SceneFunc_UpdateSceneMngTask(KwlnTask* sceneMngTask);
void MT_SceneFunc_DestroySceneMngTask(KwlnTask* sceneMngTask);
void* MT_SceneFunc_UpdateSceneMngDrawTask(KwlnTask* sceneMngDrawTask);
KwlnTask* MT_SceneFunc_CreateTasks();
u32 FUN_003b88c0(float param_1,Resrc *param_2,u32 *param_3,u32 param_4,u32 param_5);
#pragma alias FUN_003b88c0_scene FUN_003b88c0
extern u32 FUN_003b88c0_scene(Resrc *param_1,u32 param_2,float param_3,u32 param_4);
u32 FUN_003b89f0(u32 param_1,u32 param_2,float param_3,u32 param_4);
u8 FUN_003b8a60(SceneInterpWork *param_1,float *param_2,u32 param_3,u8 param_4);
u32  FUN_003b8b30(u64 param_1,float *param_2,u32 param_3,u8 param_4);
u32 FUN_003b8c30(u64 param_1,float *param_2,u32 param_3);
u32 FUN_003b8ce0(u32 param_1,u8 param_2,u32 param_3,u32 param_4);
#pragma alias FUN_003b8ce0_scene FUN_003b8ce0
extern u64 FUN_003b8ce0_scene(u32 param_1,u64 param_2,u64 param_3,u64 param_4);
u64 FUN_003b8e10(u64 param_1,u64 param_2,u64 param_3,u64 param_4);
u32 FUN_003b8e80(u32 param_1,float param_2,u32 param_3);
u32 FUN_003b8f30(void);
u32  FUN_003b8ff0(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
                  u32 param_5,int param_6,float param_7);
 #pragma alias FUN_003b8ff0_typed FUN_003b8ff0
extern u32 FUN_003b8ff0_typed(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
                               u32 param_5,u32 param_6,float param_7);
u32  FUN_003b91c0(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
                  u32 param_5,u32 param_6,float param_7);
u32  FUN_003b9260(u32 *param_1,u32 param_2,u32 param_3,u32 param_4,  u32 param_5,u32 param_6,float param_7);
#pragma alias FUN_003b9260_typed FUN_003b9260
extern u32 FUN_003b9260_typed(u32 *param_1,u32 param_2,u32 param_3,u32 param_4,  u32 param_5,u32 param_6,float param_7);
u32  FUN_003b9320(u32 param_1,u32 param_2,u32 param_3,u32 param_4,  u32 param_5,u32 param_6,float param_7);
void FUN_003b93c0(u32 param_1,short param_2,short param_3,short param_4,

                 short param_5);
#pragma alias FUN_003b8ff0_scene FUN_003b8ff0
extern u32 FUN_003b8ff0_scene(float param_1,u32 param_2,u32 param_3,u16 param_4,u16 param_5,u32 param_6,u32 param_7);
#pragma alias FUN_00530da0_scene FUN_00530da0
extern u32 FUN_00530da0_scene(float param_1);
#pragma alias FUN_003bc0e0_scene FUN_003bc0e0
extern float FUN_003bc0e0_scene(char *param_1);
#pragma alias DAT_00960178_abs DAT_00960178
extern code DAT_00960178_abs[];
#pragma alias DAT_0096017c_abs DAT_0096017c
extern code DAT_0096017c_abs[];
#pragma alias FUN_00100d80_typed_scene FUN_00100d80
extern void *FUN_00100d80_typed_scene(const char *param_1,u32 param_2);
extern void FUN_005225f8(u32 base, int count, int size, int (*cmp)(int *, int *));

// Note: FUN_003bd130 keeps an absolute table base in retail.
#pragma alias DAT_0095b000_abs DAT_0095b000
extern u8 DAT_0095b000_abs[];

extern void FUN_0019d3f0(const char *param_1,u32 param_2);
#pragma alias FUN_003b9260_scene FUN_003b9260
extern u32 FUN_003b9260_scene(float param_1,u32 param_2,u32 param_3,u16 param_4,u16 param_5,u32 param_6,u32 param_7);
u32 FUN_003b9500(Resrc* param_1,int param_2);
u32 FUN_003b9550(u64 param_1,int param_2);
u32 FUN_003b95a0(void);
void FUN_003b9610(Resrc* param_1);
u32 FUN_003baa70(char *param_1);
u32 FUN_003bac40(Resrc *param_1,u32 param_2);
u32 FUN_003bb010(u64 param_1,u32 param_2);
void FUN_003bb060(u16 param_1,u8 param_2);
u32 FUN_003bb0c0(u16* param_1,int param_2);
u32 FUN_003bb180(u16 param_1,int param_2);
u32  FUN_003bb1d0(u16 param_1,u8 param_2,u8 param_3,u16 param_4,  u16 param_5);
u32 FUN_003bb280(void);
void FUN_003bb340(void);
#pragma alias FUN_004c31b0_sceneFunc FUN_004c31b0
extern void FUN_004c31b0_sceneFunc(RwMatrix *matrix, const RwV3d *axis,
                                   f32 angle, s32 mode);
#pragma alias FUN_001a4580_sceneF FUN_001a4580
extern void FUN_001a4580_sceneF(int handle, float value);
#pragma alias FUN_003bc900_sceneI FUN_003bc900
extern int FUN_003bc900_sceneI(float *out);
void FUN_003bb390(u32 param_2,u16 param_3,float param_1);
void FUN_003bb400(u32 param_1);
void FUN_003bb450(float *param_2,float param_1,float param_3,float param_4,float param_5,float *param_6);
#pragma alias FUN_003bb450_scene_typed FUN_003bb450
extern void FUN_003bb450_scene_typed(float *param_1,float param_2,float param_3,float param_4,float param_5,float *param_6);
void FUN_003bb620(u32 *param_2,int param_3,float param_1);
void FUN_003bb7a0(Resrc* param_1);
void FUN_003bb9b0(float *param_1);
#pragma alias FUN_003bb9b0_scene_typed FUN_003bb9b0
extern void FUN_003bb9b0_scene_typed(float *param_1);
void FUN_003bba70(int param_1);
void FUN_003bbaa0(float *param_1,float *param_2,float *param_3);
#pragma alias FUN_003bbaa0_scene_typed FUN_003bbaa0
extern void FUN_003bbaa0_scene_typed(float *param_1, float *param_2, float *param_3);
#pragma alias FUN_003baa70_scene_typed FUN_003baa70
extern u32 FUN_003baa70_scene_typed(char *param_1);
/* W418 negative: routing raw FUN_004c69f0/FUN_004c6ac0 calls through typed float aliases in FUN_003b9610/FUN_003bc220 produced no metric changes; reverted. */
void FUN_003bbb90(const float *param_1,float *param_2);
void FUN_003bbc90(float param_1,float *param_2,float *param_3,float *param_4,float *param_5,  float *param_6,float *param_7);
void FUN_003bbd40(float param_1,char *param_2,float *param_3);
float FUN_003bbed0(u32 param_3,float param_1,float param_2);
float FUN_003bbfd0(float param_1,float param_2,float *param_3,float *param_4,
                  float *param_5,float *param_6,float *param_7);
float FUN_003bc0e0(char *param_1);
float FUN_003bc220(char *param_1,float param_2,float param_3,float *param_4,u32 *param_5);
/* Retail call: FUN_003b8ff0 + 0x160. */
#pragma alias FUN_00318770_scene_typed FUN_00318770
extern void FUN_00318770_scene_typed(u32 param_1, u16 param_2, float param_3);
// Retail animation helpers use the model/slot/id widths directly.
#pragma alias FUN_003186e0_scene_typed FUN_003186e0
extern u32 FUN_003186e0_scene_typed(u32 param_1, u16 param_2, s16 param_3);
#pragma alias FUN_003182d0_scene_typed FUN_003182d0
extern u32 FUN_003182d0_scene_typed(u32 param_1, u16 param_2, s16 param_3,
                                    u16 param_4, u16 param_5);
#pragma alias FUN_003189f0_scene_typed FUN_003189f0
extern void FUN_003189f0_scene_typed(u32 param_1, u16 param_2, float param_3);
/* Retail calls: FUN_003bc220 + 0x1e8, + 0x494. */
#pragma alias FUN_003bbb90_scene_typed FUN_003bbb90
extern void FUN_003bbb90_scene_typed(const float *param_1, u32 *param_2);
/* Retail calls: FUN_003bbd40 + 0x0ac, + 0x178; FUN_003bc220 + 0x110, + 0x138, + 0x2a0, + 0x2d8, + 0x3e0, + 0x408; FUN_003bc730 + 0x0e0, + 0x118. */
#pragma alias FUN_003bbc90_scene_typed FUN_003bbc90
extern void FUN_003bbc90_scene_typed(float param_1,...);
/* Retail call: FUN_003bbed0 + 0x0d4. */
#pragma alias FUN_003bbd40_scene_typed FUN_003bbd40
extern void FUN_003bbd40_scene_typed(char *param_1,float param_2,float *param_3);
/* Retail calls: FUN_003b9610 + 0x52c, + 0x978. */
#pragma alias FUN_003bbed0_scene_typed FUN_003bbed0
extern float FUN_003bbed0_scene_typed(float param_1,float param_2,...);
/* Retail call: FUN_003bc0e0 + 0x0d8. */
#pragma alias FUN_003bbfd0_scene_typed FUN_003bbfd0
extern float FUN_003bbfd0_scene_typed(float param_1,float param_2,...);
/* Retail call: FUN_003b9610 + 0x604. */
#pragma alias FUN_003bc220_scene_typed FUN_003bc220
extern float FUN_003bc220_scene_typed(char *param_1,float param_2,float param_3,...);
float FUN_003bc730(char *param_1,int param_2);
int FUN_003bc8f0(char *param_1);
u8 FUN_003bc900(float *param_1);
void FUN_003bc940(void);
void FUN_003bcbf0(int param_1,int param_2);
void FUN_003bcc80(void);
int FUN_003bcda0(int *param_1,int *param_2);
void FUN_003bceb0(int param_1);
void FUN_003bd130(void);
u32 FUN_003bd1c0(u32 param_1);
#pragma alias FUN_003bd1c0_mt FUN_003bd1c0
extern u32 FUN_003bd1c0_mt(u32 param_1);
u32 FUN_003bd230(void);
void FUN_003bd280(void);
short ** FUN_003bd870(void);
u32 * FUN_003bd880(void);
u32 * FUN_003bd890(void);
u32 * FUN_003bd8a0(void);
u32 FUN_003bd8b0(u32 param_1,u32 param_2,u32 param_3);
u16 FUN_003bd9a0(u32 param_1,u32 param_2);
u32 FUN_003bda60(u32 param_1,u32 param_2,u32 param_3,u32 param_4);
float FUN_003bdb80(void);
u32 FUN_003bdba0(void);
u16 FUN_003bdbb0(void);

/* Region call-cast macros */
#define FUN_003b88c0(...) ((u32 (*)(...))FUN_003b88c0)(__VA_ARGS__)
#define FUN_003b89f0(...) ((u32 (*)(...))FUN_003b89f0)(__VA_ARGS__)
#define FUN_003b8a60(...) ((u8 (*)(...))FUN_003b8a60)(__VA_ARGS__)
#define FUN_003b8b30(...) ((u32 (*)(...))FUN_003b8b30)(__VA_ARGS__)
#define FUN_003b8c30(...) ((u32 (*)(...))FUN_003b8c30)(__VA_ARGS__)
#define FUN_003b8ce0(...) ((u32 (*)(...))FUN_003b8ce0)(__VA_ARGS__)
#define FUN_003b8e10(...) ((u64 (*)(...))FUN_003b8e10)(__VA_ARGS__)
#define FUN_003b8e80(...) ((u32 (*)(...))FUN_003b8e80)(__VA_ARGS__)
#define FUN_003b8f30(...) ((u32 (*)(...))FUN_003b8f30)(__VA_ARGS__)
#define FUN_003b8ff0(...) ((u32 (*)(...))FUN_003b8ff0)(__VA_ARGS__)
#define FUN_003b91c0(...) ((u64 (*)(...))FUN_003b91c0)(__VA_ARGS__)
#define FUN_003b9260(...) ((u32 (*)(...))FUN_003b9260)(__VA_ARGS__)
#define FUN_003b9320(...) ((u64 (*)(...))FUN_003b9320)(__VA_ARGS__)
#define FUN_003b93c0(...) ((void (*)(...))FUN_003b93c0)(__VA_ARGS__)
#define FUN_003b9500(...) ((u32 (*)(...))FUN_003b9500)(__VA_ARGS__)
#define FUN_003b9550(...) ((u64 (*)(...))FUN_003b9550)(__VA_ARGS__)
#define FUN_003b95a0(...) ((u32 (*)(...))FUN_003b95a0)(__VA_ARGS__)
#define FUN_003b9610(...) ((void (*)(...))FUN_003b9610)(__VA_ARGS__)
#define FUN_003baa70(...) ((u32 (*)(...))FUN_003baa70)(__VA_ARGS__)
#define FUN_003bac40(...) ((u32 (*)(...))FUN_003bac40)(__VA_ARGS__)
#define FUN_003bb010(...) ((u32 (*)(...))FUN_003bb010)(__VA_ARGS__)
#define FUN_003bb060(...) ((void (*)(...))FUN_003bb060)(__VA_ARGS__)
#define FUN_003bb0c0(...) ((u32 (*)(...))FUN_003bb0c0)(__VA_ARGS__)
#define FUN_003bb180(...) ((u32 (*)(...))FUN_003bb180)(__VA_ARGS__)
#define FUN_003bb1d0(...) ((u32 (*)(...))FUN_003bb1d0)(__VA_ARGS__)
#define FUN_003bb280(...) ((u32 (*)(...))FUN_003bb280)(__VA_ARGS__)
#define FUN_003bb340(...) ((void (*)(...))FUN_003bb340)(__VA_ARGS__)
#define FUN_003bb390(...) ((void (*)(...))FUN_003bb390)(__VA_ARGS__)
#define FUN_003bb400(...) ((void (*)(...))FUN_003bb400)(__VA_ARGS__)
#define FUN_003bb450(...) ((void (*)(...))FUN_003bb450)(__VA_ARGS__)
#define FUN_003bb620(...) ((void (*)(...))FUN_003bb620)(__VA_ARGS__)
#define FUN_003bb7a0(...) ((void (*)(...))FUN_003bb7a0)(__VA_ARGS__)
#define FUN_003bb9b0(...) ((void (*)(...))FUN_003bb9b0)(__VA_ARGS__)
#define FUN_003bba70(...) ((void (*)(...))FUN_003bba70)(__VA_ARGS__)
#define FUN_003bbaa0(...) ((void (*)(...))FUN_003bbaa0)(__VA_ARGS__)
#define FUN_003bbb90(...) ((void (*)(...))FUN_003bbb90)(__VA_ARGS__)
#define FUN_003bbc90(...) ((void (*)(...))FUN_003bbc90)(__VA_ARGS__)
#define FUN_003bbd40(...) ((void (*)(...))FUN_003bbd40)(__VA_ARGS__)
#define FUN_003bbed0(...) ((float (*)(...))FUN_003bbed0)(__VA_ARGS__)
#define FUN_003bbfd0(...) ((void (*)(...))FUN_003bbfd0)(__VA_ARGS__)
#define FUN_003bc0e0(...) ((float (*)(...))FUN_003bc0e0)(__VA_ARGS__)
#define FUN_003bc220(...) ((float (*)(...))FUN_003bc220)(__VA_ARGS__)
#define FUN_003bc730(...) ((float (*)(...))FUN_003bc730)(__VA_ARGS__)
#define FUN_003bc8f0(...) ((int (*)(...))FUN_003bc8f0)(__VA_ARGS__)
#define FUN_003bc900(...) ((u8 (*)(...))FUN_003bc900)(__VA_ARGS__)
#define FUN_003bc940(...) ((void (*)(...))FUN_003bc940)(__VA_ARGS__)
#define FUN_003bcbf0(...) ((void (*)(...))FUN_003bcbf0)(__VA_ARGS__)
#define FUN_003bcc80(...) ((void (*)(...))FUN_003bcc80)(__VA_ARGS__)
#define FUN_003bcda0(...) ((int (*)(...))FUN_003bcda0)(__VA_ARGS__)
#define FUN_003bceb0(...) ((void (*)(...))FUN_003bceb0)(__VA_ARGS__)
#define FUN_003bd130(...) ((void (*)(...))FUN_003bd130)(__VA_ARGS__)
#define FUN_003bd1c0(...) ((u64 (*)(...))FUN_003bd1c0)(__VA_ARGS__)
#define FUN_003bd230(...) ((u32 (*)(...))FUN_003bd230)(__VA_ARGS__)
#define FUN_003bd280(...) ((void (*)(...))FUN_003bd280)(__VA_ARGS__)
#define FUN_003bd870(...) ((short ** (*)(...))FUN_003bd870)(__VA_ARGS__)
#define FUN_003bd880(...) ((u32 * (*)(...))FUN_003bd880)(__VA_ARGS__)
#define FUN_003bd890(...) ((u32 * (*)(...))FUN_003bd890)(__VA_ARGS__)
#define FUN_003bd8a0(...) ((u32 * (*)(...))FUN_003bd8a0)(__VA_ARGS__)
#define FUN_003bd8b0(...) ((u32 (*)(...))FUN_003bd8b0)(__VA_ARGS__)
#define FUN_003bd9a0(...) ((u16 (*)(...))FUN_003bd9a0)(__VA_ARGS__)
#define FUN_003bda60(...) ((u32 (*)(...))FUN_003bda60)(__VA_ARGS__)
#define FUN_003bdb80(...) ((float (*)(...))FUN_003bdb80)(__VA_ARGS__)
#define FUN_003bdba0(...) ((u32 (*)(...))FUN_003bdba0)(__VA_ARGS__)
#define FUN_003bdbb0(...) ((u16 (*)(...))FUN_003bdbb0)(__VA_ARGS__)





#undef FUN_003b88c0
// FUN_003B88C0
u32 FUN_003b88c0(float param_1,Resrc *param_2,u32 *param_3,u32 param_4,u32 param_5)
{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  u32 *puVar4;
  int iVar5;
  float fVar6;

  if (param_2 == 0) {
    return 0;
  }

  iVar3 = (int)param_2;
  uVar1 = param_2->flags;
  uVar1 = uVar1 | 1;
  param_2->flags = uVar1;
  uVar1 = uVar1 & 0xffffffbf;
  param_2->flags = uVar1;
  if (param_4 == 1) {
    param_2->flags = param_2->flags | 0x40;
  }
  *(float *)(iVar3 + 0x58) = param_1;
  *(u8 *)(iVar3 + 0x50) = 2;
  *(u32 *)(iVar3 + 0x5c) = 0;
  if (*(u32 *)(iVar3 + 0x54) == 0) {
    uVar2 = (u32)(*DAT_00960178_abs)(0x130,0x40000);
    *(u32 *)(iVar3 + 0x54) = uVar2;
    if (uVar2 == 0) {
      FUN_0019d3f0("mt_sceneFunc.c",0x23b);
    }
  }
  puVar4 = *(u32 **)(iVar3 + 0x54);
  iVar5 = 0x26;
  do {
    uVar1 = *param_3;
    uVar2 = param_3[1];
    param_3 += 2;
    iVar5--;
    *puVar4 = uVar1;
    puVar4[1] = uVar2;
    puVar4 += 2;
  } while (0 < iVar5);
  fVar6 = FUN_003bc0e0_scene(*(char **)(iVar3 + 0x54));
  *(float *)(iVar3 + 0x60) = fVar6;
  uVar2 = FUN_00530da0_scene(fVar6);
  FUN_005225a8(DAT_006a2df0,uVar2);
  return 1;
}
#define FUN_003b88c0(...) ((u32 (*)(...))FUN_003b88c0)(__VA_ARGS__)
#undef FUN_003b89f0
// FUN_003B89F0

u32 FUN_003b89f0(u32 param_1,u32 param_2,float param_3,u32 param_4)



{

  u32 lVar1;
  u32 uVar2;

  

  lVar1 = FUN_003b5d10();

  if (lVar1 != 0) {

    uVar2 = FUN_003b88c0_scene((Resrc *)lVar1,param_2,param_3,param_4);

  }

  else {

    uVar2 = 0;

  }

  return uVar2;

}
#define FUN_003b89f0(...) ((u32 (*)(...))FUN_003b89f0)(__VA_ARGS__)
#undef FUN_003b8a60
#undef FUN_003bba70
#undef FUN_003bb9b0

// FUN_003B8A60


u8 FUN_003b8a60(SceneInterpWork *param_1,float *param_2,u32 param_3,u8 param_4)
{
  struct V3 {
    float x;
    float y;
    float z;
  } values;
  struct V3 *input;

  input = (struct V3 *)param_2;
  values = *input;

  if (param_1 == 0) {
    return 0;
  }

  FUN_003bba70((int)param_1);
  FUN_003bb9b0((float *)&values);
  param_1->flags28 |= 4;
  *(struct V3 *)&param_1->value64 =
      *(struct V3 *)&param_1->value10;
  *(struct V3 *)&param_1->value70 = values;
  param_1->value7c = 0;
  param_1->value7d = param_4;
  param_1->value80 = param_3;
  param_1->value84 = 0;

  return 1;
}

#define FUN_003bba70(...) ((void (*)(...))FUN_003bba70)(__VA_ARGS__)
#define FUN_003bb9b0(...) ((void (*)(...))FUN_003bb9b0)(__VA_ARGS__)
#define FUN_003b8a60(...) ((u8 (*)(...))FUN_003b8a60)(__VA_ARGS__)
#undef FUN_003b8b30
#undef FUN_003bba70
#undef FUN_003bb9b0
// FUN_003B8B30


u32

FUN_003b8b30(u64 param_1,float *param_2,u32 param_3,u8 param_4)



{

  u32 uVar1;


  int iVar3;

  struct V3 {
    float x;
    float y;
    float z;
  } values;
  struct V3 *input;
  

  iVar3 = FUN_003b5d10();

  if (iVar3 == 0) {

    uVar1 = 0;

  }

  else {

    input = (struct V3 *)param_2;
    values = *input;

    if (iVar3 == 0) {

      uVar1 = 0;

    }

    else {

      FUN_003bba70(iVar3);

      FUN_003bb9b0((float *)&values);


      *(u32 *)(iVar3 + 0x28) = *(u32 *)(iVar3 + 0x28) | 4;

      *(struct V3 *)(iVar3 + 0x64) = *(struct V3 *)(iVar3 + 0x10);
      *(struct V3 *)(iVar3 + 0x70) = values;
      *(u8 *)(iVar3 + 0x7c) = 0;

      *(u8 *)(iVar3 + 0x7d) = param_4;

      *(u32 *)(iVar3 + 0x80) = param_3;

      *(u32 *)(iVar3 + 0x84) = 0;

      uVar1 = 1;

    }

  }

  return uVar1;

}
#define FUN_003b8b30(...) ((u32 (*)(...))FUN_003b8b30)(__VA_ARGS__)
#define FUN_003bba70(...) ((void (*)(...))FUN_003bba70)(__VA_ARGS__)
#define FUN_003bb9b0(...) ((void (*)(...))FUN_003bb9b0)(__VA_ARGS__)
#undef FUN_003b8c30
// FUN_003B8C30


u32 FUN_003b8c30(u64 param_1,float *param_2,u32 param_3)


{

  int iVar1;

  u32 lVar2;


  u32 uVar3;
  u32 uVar4;
  float fVar1;

  float fVar2;

  float fVar3;

  

  lVar2 = FUN_003b5d10();

  if (lVar2 == 0) {

    uVar3 = 0;

  }

  else if (lVar2 == 0) {

    uVar3 = 0;

  }

  else {

    iVar1 = (int)lVar2;

    *(u32 *)(iVar1 + 0x28) = *(u32 *)(iVar1 + 0x28) | 0x8000;

    fVar1 = *(float *)(iVar1 + 0x1c);

    fVar2 = *(float *)(iVar1 + 0x20);

    fVar3 = *(float *)(iVar1 + 0x24);

    *(float *)(iVar1 + 0x88) = fVar1;

    *(float *)(iVar1 + 0x8c) = fVar2;

    *(float *)(iVar1 + 0x90) = fVar3;

    fVar2 = *(volatile /* Removing this function's qualifier batch loses FUN_003b8c30 (MATCH nd0 -> MISMATCH nd6, size 168 -> 168) - measured W170. */ float *)(param_2 + 0);
    fVar3 = *(volatile /* Removing this function's qualifier batch loses FUN_003b8c30 (MATCH nd0 -> MISMATCH nd6, size 168 -> 168) - measured W170. */ float *)(param_2 + 1);
    fVar1 = *(volatile /* Removing this function's qualifier batch loses FUN_003b8c30 (MATCH nd0 -> MISMATCH nd6, size 168 -> 168) - measured W170. */ float *)(param_2 + 2);

    *(float *)(iVar1 + 0x94) = fVar2;

    *(float *)(iVar1 + 0x98) = fVar3;

    *(float *)(iVar1 + 0x9c) = fVar1;

    *(u32 *)(iVar1 + 0xa0) = param_3;

    *(u32 *)(iVar1 + 0xa4) = 0;

    uVar3 = 1;

  }

  return uVar3;

}
#define FUN_003b8c30(...) ((u32 (*)(...))FUN_003b8c30)(__VA_ARGS__)
#undef FUN_003b8ce0
 
// FUN_003B8CE0

u32 FUN_003b8ce0(u32 param_1,u8 param_2,u32 param_3,u32 param_4)
{
    u32 uVar1;
    int iVar2;
    u16 *puVar3;
    volatile /* Removing this function's qualifier batch loses FUN_003b8ce0 (MATCH nd0 -> MISMATCH nd8, size 300 -> 300) - measured W170. */ u8 *puVar5;
    u8 bVar4;
    u8 bVar5;
    u8 bVar6;
    u8 bVar7;
    u8 bVar8;
    u8 auStack_8[8];

    if (param_1 == 0)
    {
        uVar1 = 0;
        goto end;
    }

    puVar3 = (u16 *)param_1;
    iVar2 = (int)(*puVar3 & 0xffc00) >> 10;
    if (iVar2 == 6)
    {
        goto type6;
    }
    switch (iVar2)
    {
    case 3:
        goto type3;
    default:
        goto unknown;
    }

type3:
    iVar2 = FUN_00318b00(*(u32 *)(puVar3 + 0x94));
    puVar5 = (volatile /* Removing this function's qualifier batch loses FUN_003b8ce0 (MATCH nd0 -> MISMATCH nd8, size 300 -> 300) - measured W170. */ u8 *)iVar2;
    bVar5 = puVar5[0];
    bVar6 = puVar5[1];
    bVar7 = puVar5[2];
    bVar8 = puVar5[3];
    auStack_8[4] = bVar5;
    auStack_8[5] = bVar6;
    auStack_8[6] = bVar7;
    auStack_8[7] = bVar8;
    bVar4 = auStack_8[7];

    if (param_4 == 1)
    {
        *(u8 *)(puVar3 + 0x60) = 1;
    }
    else
    {
        *(u8 *)(puVar3 + 0x60) = 0;
    }
    goto finish;

type6:
    FUN_00350040(*(u32 *)(puVar3 + 0x82), auStack_8);
    bVar4 = auStack_8[3];
    goto finish;

unknown:
    uVar1 = 0;
    goto end;

finish:
    *(u32 *)(puVar3 + 0x14) = *(u32 *)(puVar3 + 0x14) | 0x4000;
    *(u8 *)(puVar3 + 0x5a) = bVar4;
    *(u8 *)((int)puVar3 + 0xb5) = param_2;
    *(u32 *)(puVar3 + 0x5c) = param_3;
    *(u32 *)((u8 *)puVar3 + 0xbc) = 0;
    uVar1 = 1;
    goto end;

end:
    return uVar1;
}
#define FUN_003b8ce0(...) ((u32 (*)(...))FUN_003b8ce0)(__VA_ARGS__)
#undef FUN_003b8e10
// FUN_003B8E10

u64 FUN_003b8e10(u64 param_1,u64 param_2,u64 param_3,u64 param_4)



{

  u32 lVar1;

  u64 uVar2;
  

  lVar1 = FUN_003b5d10();

  if (lVar1 != 0) {

    uVar2 = FUN_003b8ce0_scene(lVar1,param_2,param_3,param_4);

  }

  else {

    uVar2 = 0;

  }

  return uVar2;

}
#define FUN_003b8e10(...) ((u64 (*)(...))FUN_003b8e10)(__VA_ARGS__)
#undef FUN_003b8e80
// FUN_003B8E80


u32 FUN_003b8e80(u32 param_1,float param_2,u32 param_3)


{

  u16 *puVar1;

  u32 uVar2;

  u32 lVar3;

  
  lVar3 = FUN_003b5d10();


  if (lVar3 == 0) {

    uVar2 = 0;

  }

  else if (lVar3 == 0) {

    uVar2 = 0;

  }

  else {

    puVar1 = (u16 *)lVar3;

    if ((int)(*puVar1 & 0xffc00) >> 10 != 7) {

      uVar2 = 0;

    }

    else {

      *(u32 *)(puVar1 + 0x14) = *(u32 *)(puVar1 + 0x14) | 0x400;

      *(float *)(puVar1 + 0x62) = *(float *)(puVar1 + 0x80);

      *(float *)(puVar1 + 100) = param_2;

      *(u32 *)(puVar1 + 0x66) = param_3;

      *(u32 *)(puVar1 + 0x68) = 0;

      uVar2 = 1;

    }

  }

  return uVar2;

}
#define FUN_003b8e80(...) ((u32 (*)(...))FUN_003b8e80)(__VA_ARGS__)
#undef FUN_003b8f30
// FUN_003B8F30


u32 FUN_003b8f30(void)



{

  u32 uVar1;

  int iVar2;

  u32 uVar3;

  u32 lVar4;

  

  lVar4 = FUN_003b5d10();

  if (lVar4 == 0) {

    uVar3 = 0;

  }

  else if (lVar4 == 0) {

    uVar3 = 0;

  }

  else {

    iVar2 = (int)lVar4;

    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xfffffffe;
    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xfffffffb;
    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xffff7fff;
    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xffffffbf;
    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xfffffbff;
    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xfffff7ff;
    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xffffefff;
    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xffffdfff;
    *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xffffbfff;

    uVar3 = 1;

  }

  return uVar3;

}
#define FUN_003b8f30(...) ((u32 (*)(...))FUN_003b8f30)(__VA_ARGS__)
#undef FUN_003b8ff0
// FUN_003B8FF0

u32 FUN_003b8ff0(u32 param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5,
                 int param_6,float param_7)
{
  u32 uVar3;
  u32 uVar1;
  u32 lVar2;
  int iVar3;

  if (param_1 == 0) {
    return 0;
  }
  iVar3 = (int)(*(u16 *)param_1 & 0xffc00) >> 10;
  if (iVar3 == 10) {
    goto type10;
  }
  if (iVar3 == 3) {
    goto type3;
  }
  if (iVar3 == 2) {
    goto type2;
  }
  switch (iVar3) {
  case 1:
    goto type1;
  default:
    goto unknown;
  }

type1:
  uVar1 = *(u32 *)(param_1 + 0x128);
  goto selected;
type2:
  uVar1 = *(u32 *)(param_1 + 0x118);
  goto selected;
type3:
  uVar1 = *(u32 *)(param_1 + 0x128);
  goto selected;
type10:
  uVar1 = *(u32 *)(param_1 + 0x104);
  goto selected;
unknown:
  return 0;

selected:
  uVar3 = 0;
  if (param_5 == 1) {
    uVar3 |= 1;
  }
  lVar2 = FUN_003186e0_scene_typed(uVar1,param_2,param_3);
  if (lVar2 != 0) {
    goto complete;
  }
  FUN_003189f0_scene_typed(uVar1,param_2,param_7);
  FUN_003182d0_scene_typed(uVar1,param_2,param_3,param_4,uVar3);
  if (0 < param_6) {
    FUN_00318770_scene_typed(uVar1,param_2,(float)(int)param_6);
  }
  FUN_005225a8(DAT_006a2e10,uVar1,param_2,param_3);
complete:
  *(u32 *)(param_1 + 0x28) = *(u32 *)(param_1 + 0x28) & 0xffffdfff;
  return 1;
}
#define FUN_003b8ff0(...) ((u32 (*)(...))FUN_003b8ff0)(__VA_ARGS__)
#undef FUN_003b91c0
// FUN_003B91C0


u32

FUN_003b91c0(u32 param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5,

            u32 param_6,float param_7)



{

  u32 lVar1;

  u32 uVar2;

  

  lVar1 = FUN_003b5d10();

  if (lVar1 != 0) {

    uVar2 = FUN_003b8ff0_typed((u32)lVar1,param_2,param_3,param_4,param_5,param_6,param_7);

  }

  else {

    uVar2 = 0;

  }

  return uVar2;

}
#define FUN_003b91c0(...) ((u64 (*)(...))FUN_003b91c0)(__VA_ARGS__)
#undef FUN_003b9260
// FUN_003B9260


u32
FUN_003b9260(u32 *param_1,u32 param_2,u32 param_3,u32 param_4,
              u32 param_5,u32 param_6,float param_7)
{
    u32 uVar1;
    int iVar2;
    u16 *puVar3;
    u16 *puVar4;

    puVar4 = (u16 *)param_1;
    if (param_1 == 0)
    {
        uVar1 = 0;
        goto end;
    }

    iVar2 = (int)(*puVar4 & 0xffc00) >> 10;
    if (iVar2 == 3)
    {
        goto type3;
    }
    if (iVar2 == 2)
    {
        goto type2;
    }
    switch (iVar2)
    {
    case 1:
        goto type1;
    default:
        goto unknown;
    }

type1:
    puVar3 = puVar4 + 0x88;
    goto finish;

type2:
    puVar3 = puVar4 + 0x80;
    goto finish;

type3:
    puVar3 = puVar4 + 0x88;
    goto finish;

unknown:
    uVar1 = 0;
    goto end;

finish:
    *(u32 *)(puVar4 + 0x14) = *(u32 *)(puVar4 + 0x14) | 0x2000;
    *(u32 *)puVar3 = param_2;
    *(u32 *)(puVar3 + 2) = param_3;
    *(u32 *)(puVar3 + 4) = param_4;
    *(u32 *)(puVar3 + 6) = param_5;
    *(u32 *)(puVar3 + 8) = param_6;
    *(float *)(puVar3 + 10) = param_7;
    uVar1 = 1;
    goto end;
end:
    return uVar1;
}

#define FUN_003b9260(...) ((u32 (*)(...))FUN_003b9260)(__VA_ARGS__)
#undef FUN_003b9320
#pragma push
/* Removing this loses FUN_003b9320 (MATCH nd0 -> MISMATCH nd34) - measured W161. */
#pragma opt_rebuildconditionals off
// FUN_003B9320


u32
FUN_003b9320(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
             u32 param_5,u32 param_6,float param_7)
{
    u32 *puVar3;
    u32 uVar2;

    puVar3 = (u32 *)FUN_003b5d10();
    if (puVar3 == 0)
    {
        goto zero;
    }
    uVar2 = FUN_003b9260_typed(puVar3,param_2,param_3,param_4,
                               param_5,param_6,param_7);
    goto end;

zero:
    uVar2 = 0;

end:
    return uVar2;
}

#pragma pop
#define FUN_003b9320(...) ((u64 (*)(...))FUN_003b9320)(__VA_ARGS__)
#undef FUN_003b93c0
// FUN_003B93C0


void FUN_003b93c0(u32 param_1,short param_2,short param_3,short param_4,

                 short param_5)



{

  u32 uVar1;

  u32 uVar3;

  u32 lVar2;
  u32 lVar4;

  

  uVar1 = (u16)param_1;

  uVar1 = (u16)(uVar1 & 0x3ff | 0xc00);

  uVar3 = (u32)param_4;

  if (uVar3 == -1) {

    lVar2 = FUN_003b5d10(uVar1);

    if (lVar2 != 0) {

      FUN_003b8ff0_typed(lVar2,0,param_2,param_3,1,0,1.0f);

    }

    goto end;

  }

  lVar4 = FUN_003b5d10(uVar1);

  if (lVar4 == 0) {

    goto second_done;

  }

  FUN_003b8ff0_typed(lVar4,0,param_2,param_3,0,0,1.0f);

second_done:

  lVar2 = FUN_003b5d10(uVar1);

  if (lVar2 != 0) {

    FUN_003b9260_typed((u32 *)lVar2,0,uVar3,param_5,1,0,1.0f);

  }

end:

  return;

}
#define FUN_003b93c0(...) ((void (*)(...))FUN_003b93c0)(__VA_ARGS__)
#undef FUN_003b9500
// FUN_003B9500


u32 FUN_003b9500(Resrc* param_1,int param_2)



{

  u32 uVar1;

  int iVar2;

  

  iVar2 = (int)param_1;

  if (param_1 == 0) {

    uVar1 = 0;

  }

  else {

    if (param_2 == 1) {

      *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) | 2;

    }

    else {

      *(u32 *)(iVar2 + 0x28) = *(u32 *)(iVar2 + 0x28) & 0xfffffffd;

    }

    uVar1 = 1;

  }

  return uVar1;

}
#define FUN_003b9500(...) ((u32 (*)(...))FUN_003b9500)(__VA_ARGS__)
#undef FUN_003b9550
// FUN_003B9550


u32 FUN_003b9550(u64 param_1,int param_2)



{
  Resrc* lVar1;

  lVar1 = (Resrc*)FUN_003b5d10();

  if (lVar1 != 0) {
    return (FUN_003b9500)(lVar1,param_2);
  }

  return 0;
}
#define FUN_003b9550(...) ((u64 (*)(...))FUN_003b9550)(__VA_ARGS__)
#undef FUN_003b95a0
// FUN_003B95A0


u32 FUN_003b95a0(void)



{
  u32 uVar1;
  Resrc* lVar2;

  lVar2 = (Resrc*)FUN_003b5d10();

  if (lVar2 == 0) {
    uVar1 = 0;
  }
  else if (lVar2 == 0) {
    uVar1 = 0;
  }
  else if ((*(u32 *)((int)lVar2 + 0x28) & 1) != 0) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }

  return uVar1;
}
#define FUN_003b95a0(...) ((u32 (*)(...))FUN_003b95a0)(__VA_ARGS__)
#undef FUN_003b9610
// FUN_003B9610 NONMATCHING








void FUN_003b9610(Resrc* param_1)



{

  u32 uVar1;

  u32 uVar2;

  short sVar3;

  u8 *puVar4;

  u16 *puVar5;

  int iVar6;

  int iVar7;

  u16 *puVar8;

  char cVar9;

  int iVar10;

  float fVar11;

  float fVar12;


  struct {
    float m_fStack_88;
    float m_fStack_84;
    float m_fStack_80;
    float m_fStack_78;
    float m_fStack_74;
    float m_fStack_70;
    u32 m_uStack_68;
    u32 m_uStack_64;
    u32 m_uStack_60;
    u32 m_uStack_58;
    u32 m_uStack_54;
    u32 m_uStack_50;
    float m_fStack_48;
    float m_fStack_44;
    float m_fStack_40;
    float m_fStack_38;
    float m_fStack_34;
    float m_fStack_30;
    float m_fStack_28;
    float m_fStack_24;
    float m_fStack_20;
    float m_fStack_18;
    float m_fStack_14;
    float m_fStack_10;
    u8 m_auStack_8[4];
    u8 m_color[4];
  } stack;

  

  iVar10 = 0;

  if (param_1 != 0) {

    puVar8 = (u16 *)param_1;

    uVar1 = *(u32 *)(puVar8 + 0x14);

    if ((uVar1 & 0x20) != 0) {

      iVar10 = *(int *)(puVar8 + 0x7a);

      *(u32 *)(puVar8 + 0x14) = uVar1 & 0xffffffdf;

      *(u32 *)(puVar8 + 0x7a) = 0;

    }

    else if ((uVar1 & 8) == 0) {

      iVar10 = 1;

    }

    if (iVar10 < 0) {

      iVar10 = 0;

    }

    if ((*(u32 *)(puVar8 + 0x14) & 1) != 0) {

      stack.m_fStack_18 = *(float *)(puVar8 + 0x1c);

      stack.m_fStack_14 = *(float *)(puVar8 + 0x1e);

      stack.m_fStack_10 = *(float *)(puVar8 + 0x20);

      stack.m_fStack_28 = *(float *)(puVar8 + 2);

      stack.m_fStack_24 = *(float *)(puVar8 + 4);

      stack.m_fStack_20 = *(float *)(puVar8 + 6);

      cVar9 = (char)puVar8[0x28];

      if (cVar9 == '\0') {

        stack.m_fStack_38 = stack.m_fStack_18 - stack.m_fStack_28;

        stack.m_fStack_34 = stack.m_fStack_14 - stack.m_fStack_24;

        stack.m_fStack_30 = stack.m_fStack_10 - stack.m_fStack_20;

        fVar11 = (float)FUN_004c6ac0(&stack.m_fStack_38);

        iVar6 = iVar10;

        do {

          if (fVar11 <= *(float *)(puVar8 + 0x2c)) {

            *(float *)(puVar8 + 2) = stack.m_fStack_18;

            *(float *)(puVar8 + 4) = stack.m_fStack_14;

            *(float *)(puVar8 + 6) = stack.m_fStack_10;

            *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffffe;

            FUN_005225a8(0x6a2e40);

            break;

          }

          FUN_004c69f0(&stack.m_fStack_48,&stack.m_fStack_38);

          if (0 < iVar6) {

            *(float *)(puVar8 + 2) =

                 stack.m_fStack_48 * *(float *)(puVar8 + 0x2c) + *(float *)(puVar8 + 2);

            *(float *)(puVar8 + 4) =

                 stack.m_fStack_44 * *(float *)(puVar8 + 0x2c) + *(float *)(puVar8 + 4);

            *(float *)(puVar8 + 6) =

                 stack.m_fStack_40 * *(float *)(puVar8 + 0x2c) + *(float *)(puVar8 + 6);

          }

          iVar6 = iVar6 + -1;

        } while (0 < iVar6);

        FUN_003b7460(puVar8,puVar8 + 2,0,0);

      }

      else if (cVar9 == '\x01') {

        stack.m_fStack_38 = stack.m_fStack_18 - *(float *)(puVar8 + 0x16);

        stack.m_fStack_34 = stack.m_fStack_14 - *(float *)(puVar8 + 0x18);

        stack.m_fStack_30 = stack.m_fStack_10 - *(float *)(puVar8 + 0x1a);

        if (*(u32 *)(puVar8 + 0x30) == 0) {

          *(float *)(puVar8 + 2) = stack.m_fStack_18;

          *(float *)(puVar8 + 4) = stack.m_fStack_14;

          *(float *)(puVar8 + 6) = stack.m_fStack_10;

          *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffffe;

          FUN_005225a8(0x6a2e60);

        }

        else {

          stack.m_fStack_38 = stack.m_fStack_38 / (float)*(u32 *)(puVar8 + 0x30);

          stack.m_fStack_34 = stack.m_fStack_34 / (float)*(u32 *)(puVar8 + 0x30);

          stack.m_fStack_30 = stack.m_fStack_30 / (float)*(u32 *)(puVar8 + 0x30);

          switch(*(u8 *)((int)puVar8 + 0x51)) {

          case 0:

            *(float *)(puVar8 + 2) =

                 stack.m_fStack_38 * (float)*(u32 *)(puVar8 + 0x2e) + *(float *)(puVar8 + 0x16);

            *(float *)(puVar8 + 4) =

                 stack.m_fStack_34 * (float)*(u32 *)(puVar8 + 0x2e) + *(float *)(puVar8 + 0x18);

            *(float *)(puVar8 + 6) =

                 stack.m_fStack_30 * (float)*(u32 *)(puVar8 + 0x2e) + *(float *)(puVar8 + 0x1a);

            break;

          case 1:

          case 2:

          case 3:

          case 4:

          case 5:

            fVar11 = (float)FUN_003bbed0_scene_typed((float)*(u32 *)(puVar8 + 0x30),

                                         (float)*(u32 *)(puVar8 + 0x2e));

            *(float *)(puVar8 + 2) = stack.m_fStack_38 * fVar11 + *(float *)(puVar8 + 0x16);

            *(float *)(puVar8 + 4) = stack.m_fStack_34 * fVar11 + *(float *)(puVar8 + 0x18);

            *(float *)(puVar8 + 6) = stack.m_fStack_30 * fVar11 + *(float *)(puVar8 + 0x1a);

          }

          if (*(u32 *)(puVar8 + 0x2e) < *(u32 *)(puVar8 + 0x30)) {

            *(u32 *)(puVar8 + 0x2e) = *(u32 *)(puVar8 + 0x2e) + iVar10;

          }

          else {

            *(float *)(puVar8 + 2) = stack.m_fStack_18;

            *(float *)(puVar8 + 4) = stack.m_fStack_14;

            *(float *)(puVar8 + 6) = stack.m_fStack_10;

            *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffffe;

          }

        }

        FUN_003b7460(puVar8,puVar8 + 2,0,0);

      }

      else if (cVar9 == '\x02') {

        FUN_003bc220_scene_typed((char *)*(u32 *)(puVar8 + 0x2a),*(float *)(puVar8 + 0x2e),
                     *(float *)(puVar8 + 0x30),&stack.m_uStack_58,&stack.m_uStack_68);

        if (*(float *)(puVar8 + 0x30) <= *(float *)(puVar8 + 0x2e)) {

          if ((*(u32 *)(puVar8 + 0x14) & 0x40) == 0) {

            *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffffe;

          }

          else {

            *(float *)(puVar8 + 0x2e) = *(float *)(puVar8 + 0x2e) - *(float *)(puVar8 + 0x30);

          }

        }

        *(u32 *)(puVar8 + 2) = stack.m_uStack_58;

        *(u32 *)(puVar8 + 4) = stack.m_uStack_54;

        *(u32 *)(puVar8 + 6) = stack.m_uStack_50;

        for (iVar6 = 0; iVar6 < iVar10; iVar6 = iVar6 + 1) {

          *(float *)(puVar8 + 0x2e) = *(float *)(puVar8 + 0x2e) + *(float *)(puVar8 + 0x2c);

        }

        FUN_003b7460(puVar8,0,puVar8 + 8,0);

        if ((*(u32 *)(puVar8 + 0x14) & 8) == 0) {

          *(u32 *)(puVar8 + 8) = stack.m_uStack_68;

          *(u32 *)(puVar8 + 10) = stack.m_uStack_64;

          *(u32 *)(puVar8 + 0xc) = stack.m_uStack_60;

        FUN_003b7460(puVar8,0,puVar8 + 8,0);

        }

      }

    }

    if ((*(u32 *)(puVar8 + 0x14) & 4) != 0) {

      if (*(int *)(puVar8 + 0x40) == 0) {

        *(u32 *)(puVar8 + 8) = *(u32 *)(puVar8 + 0x38);

        *(u32 *)(puVar8 + 10) = *(u32 *)(puVar8 + 0x3a);

        *(u32 *)(puVar8 + 0xc) = *(u32 *)(puVar8 + 0x3c);

        *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffffb;

        FUN_003b7460(puVar8,0,puVar8 + 8,0);

      }

      else if (*(int *)(puVar8 + 0x42) == 0) {

        *(int *)(puVar8 + 0x42) = iVar10;

      }

      else {

        FUN_003bbaa0_scene_typed((float *)(puVar8 + 0x32), (float *)(puVar8 + 0x38), &stack.m_fStack_78);

        fVar11 = (float)*(u32 *)(puVar8 + 0x40);

        stack.m_fStack_74 = stack.m_fStack_74 / fVar11;

        switch(*(u8 *)((int)puVar8 + 0x7d)) {

        case 0:

          uVar1 = *(u32 *)(puVar8 + 0x42);

          stack.m_fStack_88 = (stack.m_fStack_78 / fVar11) * (float)uVar1 + *(float *)(puVar8 + 0x32);

          stack.m_fStack_84 = stack.m_fStack_74 * (float)uVar1 + *(float *)(puVar8 + 0x34);

          stack.m_fStack_80 = (stack.m_fStack_70 / fVar11) * (float)uVar1 + *(float *)(puVar8 + 0x36);

          break;

        case 1:

        case 2:

        case 3:

        case 4:

        case 5:

          fVar12 = (float)FUN_003bbed0_scene_typed((float)*(u32 *)(puVar8 + 0x40),

                                       (float)*(u32 *)(puVar8 + 0x42),

                                       *(u8 *)((int)puVar8 + 0x7d));

          stack.m_fStack_88 = (stack.m_fStack_78 / fVar11) * fVar12 + *(float *)(puVar8 + 0x32);

          stack.m_fStack_84 = stack.m_fStack_74 * fVar12 + *(float *)(puVar8 + 0x34);

          stack.m_fStack_80 = (stack.m_fStack_70 / fVar11) * fVar12 + *(float *)(puVar8 + 0x36);

        }

        *(float *)(puVar8 + 8) = stack.m_fStack_88;

        *(float *)(puVar8 + 10) = stack.m_fStack_84;

        *(float *)(puVar8 + 0xc) = stack.m_fStack_80;

        if (*(u32 *)(puVar8 + 0x42) < *(u32 *)(puVar8 + 0x40)) {

          *(u32 *)(puVar8 + 0x42) = *(u32 *)(puVar8 + 0x42) + iVar10;

        }

        else {

          *(u32 *)(puVar8 + 8) = *(u32 *)(puVar8 + 0x38);

          *(u32 *)(puVar8 + 10) = *(u32 *)(puVar8 + 0x3a);

          *(u32 *)(puVar8 + 0xc) = *(u32 *)(puVar8 + 0x3c);

          *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffffb;

        }

        if (iVar10 != 0) {

          FUN_003b7460(puVar8,0,puVar8 + 8,0);

        }

      }

    }

    FUN_003bb9b0_scene_typed((float *)(puVar8 + 8));

    if ((*(u32 *)(puVar8 + 0x14) & 0x8000) != 0) {

      if (*(u32 *)(puVar8 + 0x50) == 0) {

        *(u32 *)(puVar8 + 0xe) = *(u32 *)(puVar8 + 0x4a);

        *(u32 *)(puVar8 + 0x10) = *(u32 *)(puVar8 + 0x4c);

        *(u32 *)(puVar8 + 0x12) = *(u32 *)(puVar8 + 0x4e);

        *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xffff7fff;

        FUN_003b7460(puVar8,0,0,puVar8 + 0xe);

      }

      else {

        fVar11 = (float)*(u32 *)(puVar8 + 0x50);

        uVar1 = *(u32 *)(puVar8 + 0x52);

        *(float *)(puVar8 + 0xe) =

             ((*(float *)(puVar8 + 0x4a) - *(float *)(puVar8 + 0x44)) / fVar11) * (float)uVar1 +

             *(float *)(puVar8 + 0x44);

        *(float *)(puVar8 + 0x10) =

             ((*(float *)(puVar8 + 0x4c) - *(float *)(puVar8 + 0x46)) / fVar11) * (float)uVar1 +

             *(float *)(puVar8 + 0x46);

        *(float *)(puVar8 + 0x12) =

             ((*(float *)(puVar8 + 0x4e) - *(float *)(puVar8 + 0x48)) / fVar11) * (float)uVar1 +

             *(float *)(puVar8 + 0x48);

        if (*(u32 *)(puVar8 + 0x52) < *(u32 *)(puVar8 + 0x50)) {

          *(u32 *)(puVar8 + 0x52) = *(u32 *)(puVar8 + 0x52) + iVar10;

        }

        else {

          *(u32 *)(puVar8 + 0xe) = *(u32 *)(puVar8 + 0x4a);

          *(u32 *)(puVar8 + 0x10) = *(u32 *)(puVar8 + 0x4c);

          *(u32 *)(puVar8 + 0x12) = *(u32 *)(puVar8 + 0x4e);

          *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xffff7fff;

        }

        if (iVar10 != 0) {

          FUN_003b7460(puVar8,0,0,puVar8 + 0xe);

        }

      }

    }

    uVar1 = *(u32 *)(puVar8 + 0x14);

    if ((uVar1 & 0x4000) != 0) {

      uVar2 = *(u32 *)(puVar8 + 0x5c);

      if (uVar2 == 0) {

        cVar9 = *(char *)((int)puVar8 + 0xb5);

        *(u32 *)(puVar8 + 0x14) = uVar1 & 0xffffbfff;

      }

      else if (*(u32 *)(puVar8 + 0x5e) < uVar2) {

        fVar11 = (((float)*(u8 *)((int)puVar8 + 0xb5) - (float)(u8)puVar8[0x5a]) / (float)uVar2)

                 * (float)*(u32 *)(puVar8 + 0x5e) + (float)(u8)puVar8[0x5a];

        cVar9 = (char)(u32)fVar11;

        *(int *)(puVar8 + 0x5e) = *(int *)(puVar8 + 0x5e) + iVar10;

      }

      else {

        cVar9 = *(char *)((int)puVar8 + 0xb5);

        *(u32 *)(puVar8 + 0x14) = uVar1 & 0xffffbfff;

      }

      iVar6 = (int)(*puVar8 & 0xffc00) >> 10;

      if (iVar6 == 6) {

        FUN_00350040(*(u32 *)(puVar8 + 0x82),stack.m_auStack_8);

        stack.m_auStack_8[3] = cVar9;

        FUN_0034ff90(*(u32 *)(puVar8 + 0x82),stack.m_auStack_8);

      }

      else if (iVar6 == 3) {

        puVar4 = (u8 *)FUN_00318b00(*(u32 *)(puVar8 + 0x94));

        stack.m_color[0] = puVar4[0];
        stack.m_color[1] = puVar4[1];
        stack.m_color[2] = puVar4[2];
        stack.m_color[3] = cVar9;

        if (cVar9 == -1) {

          FUN_00319070(*(u32 *)(puVar8 + 0x94));

        }

        else if ((char)puVar8[0x60] == '\0') {

          FUN_00319070(*(u32 *)(puVar8 + 0x94));

        }

        else {

          FUN_00319050(*(u32 *)(puVar8 + 0x94));

          FUN_005225a8(0x6a2e80);

        }

        FUN_00318ad0(*(u32 *)(puVar8 + 0x94),stack.m_color);

      }

    }

    if (((*(u32 *)(puVar8 + 0x14) & 0x400) != 0) && ((int)(*puVar8 & 0xffc00) >> 10 == 7)) {

      iVar6 = *(int *)(puVar8 + 0x66);

      fVar11 = *(float *)(puVar8 + 100);

      if (iVar6 < 1) {

        *(float *)(puVar8 + 0x80) = fVar11;

        *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffbff;

      }

      else {

        *(float *)(puVar8 + 0x80) =

             ((fVar11 - *(float *)(puVar8 + 0x62)) / (float)iVar6) * (float)*(u32 *)(puVar8 + 0x2e)

             + *(float *)(puVar8 + 0x62);

        if (*(int *)(puVar8 + 0x68) < iVar6) {

          *(int *)(puVar8 + 0x68) = *(int *)(puVar8 + 0x68) + iVar10;

        }

        else {

          *(float *)(puVar8 + 0x80) = fVar11;

          *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffbff;

        }

      }

    }

    iVar6 = (int)(*puVar8 & 0xffc00) >> 10;

    if (iVar6 == 1) {

      for (iVar6 = 0; iVar6 < 3; iVar6 = iVar6 + 1) {

        if (*(int *)(puVar8 + iVar6 * 2 + 0x80) != 0) {

          FUN_0034fd30();

        }

      }

    }

    else if (iVar6 == 3) {

      for (iVar6 = 0; iVar6 < 3; iVar6 = iVar6 + 1) {

        if (*(int *)(puVar8 + iVar6 * 2 + 0x80) != 0) {

          FUN_0034fd30();

        }

      }

    }

    else if ((iVar6 == 6) && (*(int *)(puVar8 + 0x82) != 0)) {

      FUN_0034fd30();

    }

    if ((*(u32 *)(puVar8 + 0x14) & 0x2000) != 0) {

      puVar5 = (u16 *)0x0;

      iVar6 = 0;

      iVar7 = (int)(*puVar8 & 0xffc00) >> 10;

      if (iVar7 == 3) {

        puVar5 = puVar8 + 0x88;

        iVar6 = *(int *)(puVar8 + 0x94);

      }

      else if (iVar7 == 2) {

        puVar5 = puVar8 + 0x80;

        iVar6 = *(int *)(puVar8 + 0x8c);

      }

      else if (iVar7 == 1) {

        puVar5 = puVar8 + 0x88;

        iVar6 = *(int *)(puVar8 + 0x94);

      }

      if ((puVar5 != (u16 *)0x0) && (*(char *)(*(int *)puVar5 * 0x9c + iVar6 + 0xee) == '\x01'))

      {

        FUN_003b8ff0_typed(*(u32 *)(puVar5 + 10),(u32)param_1,*(int *)puVar5,*(u32 *)(puVar5 + 2),
                          *(u32 *)(puVar5 + 4),*(u32 *)(puVar5 + 6),
                          *(float *)(puVar5 + 8));

        *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xffffdfff;

      }

    }

    puVar5 = puVar8 + 0x54;

    cVar9 = (char)puVar8[0x54];

    if ((cVar9 == '\x02') || (cVar9 == '\x01')) {

      if (cVar9 == '\x01') {

        if ((*(u32 *)(puVar8 + 0x14) & 1) == 0) {

          *(u8 *)puVar5 = 0;

          sVar3 = FUN_003baa70_scene_typed((char *)(puVar8 + 2));

          FUN_0010a4e0(0,(char)puVar8[0x55],1,(u16)*(u8 *)((int)puVar8 + 0xa9) + sVar3 * 4);

          *(char *)((int)puVar8 + 0xa9) = *(char *)((int)puVar8 + 0xa9) + '\x01';

          if (*(u8 *)((int)puVar8 + 0xa9) < 4) {

            return;

          }

          *(u8 *)((int)puVar8 + 0xa9) = 0;

          return;

        }

      }

      else {

        if (cVar9 != '\x02') {

          return;

        }

        if ((*(u32 *)(puVar8 + 0x14) & 4) == 0) {

          *(u8 *)puVar5 = 0;

          sVar3 = FUN_003baa70_scene_typed((char *)(puVar8 + 2));

          FUN_0010a4e0(0,(char)puVar8[0x55],1,(u16)*(u8 *)((int)puVar8 + 0xa9) + sVar3 * 4);

          *(char *)((int)puVar8 + 0xa9) = *(char *)((int)puVar8 + 0xa9) + '\x01';

          if (*(u8 *)((int)puVar8 + 0xa9) < 4) {

            return;

          }

          *(u8 *)((int)puVar8 + 0xa9) = 0;

          return;

        }

      }

      if (iVar10 != 0) {

        if (puVar8[0x58] == 0) {

          if (puVar8[0x56] == 0) {

            sVar3 = FUN_003baa70_scene_typed((char *)(puVar8 + 2));

            FUN_0010a4e0(0,(char)puVar8[0x55],1,(u16)*(u8 *)((int)puVar8 + 0xa9) + sVar3 * 4);

            *(char *)((int)puVar8 + 0xa9) = *(char *)((int)puVar8 + 0xa9) + '\x01';

            if (3 < *(u8 *)((int)puVar8 + 0xa9)) {

              *(u8 *)((int)puVar8 + 0xa9) = 0;

            }

          }

          puVar8[0x56] = puVar8[0x56] + 1;

          if (puVar8[0x57] <= puVar8[0x56]) {

            if (puVar8[0x57] == 0) {

              *(u8 *)puVar5 = 0;

            }

            else {

              puVar8[0x56] = 0;

            }

          }

        }

        else {

          puVar8[0x58] = puVar8[0x58] - 1;

        }

      }

    }

  }
  

  return;

}
#define FUN_003b9610(...) ((void (*)(...))FUN_003b9610)(__VA_ARGS__)
#undef FUN_003baa70
/* W390 measured: the `SceneVecBits` whole-aggregate copy of the 12-byte
 * {u64 xy; f32 z;} header is what reproduces retail's TWO separate
 * lui/LO16 materializations of DAT_006a2da0 (nd 57 -> 4, with the two
 * upper-bound comparison orientations flipped to `fVar5 < base + 100.0f`).
 * Splitting it back into typed per-field assignments
 * (`blk.xy = *(u64*)DAT_006a2da0_abs; blk.z = *(f32*)DAT_006a2da8_abs;`)
 * collapses those to ONE base register and measures nd 45 - do not retry.
 * Residual nd 4 is a b210 aggregate-copy WIDTH floor: retail moves the
 * tail as ld + lwc1/swc1 (12 bytes exactly), while b210 blits the packed
 * 12-byte struct as ld/sd + ld/sd (16 bytes, over-reading 4). No natural
 * 12-byte struct with a u64 member exists - alignment forces 16.
 *
 * W408 re-probed the split five more ways; the nd4 aggregate copy still wins
 * and every alternative is worse. Measured, all at 464/464 unless noted:
 *   8-byte {u64} aggregate + separate f32 assignment          nd 8
 *   same, with the f32 load through a volatile cast           nd 8
 *   same, sourcing the f32 from the DAT_006a2da8_abs alias    nd 8
 *   12-byte {u32,u32,f32} aggregate (dodges u64 alignment)    nd 241, 476B
 *   u64 field assignment + aggregate f32 assignment           nd 45
 * `opt_common_subs off` was tried to stop the two global addresses being
 * merged: it makes this function nd 327 at 508B, over its window. The two
 * separate lui/LO16 materializations retail needs are produced by the
 * aggregate copy itself, not by defeating CSE. Treat nd4 as final. */
// FUN_003BAA70 NONMATCHING


u32 FUN_003baa70(char *param_1)



{

  int lVar2;
  int tbl;

  u32 uVar3;

  u32 uVar4;

  int iVar1;

  float fVar5;

  struct SceneBlk {
    u64 xy;
    f32 z;
    u32 pad;
    int addrs[3];
  } blk;

  

  iVar1 = FUN_003b5d50(0x15);

  uVar4 = ((u32 *)puGpffffa850)[0];

  uVar3 = ((u32 *)puGpffffa850)[1];

  if (((uVar4 >= 0x14) && (uVar4 < 0x1d)) && (uVar3 >= 0x32)) {

    uVar3 = uVar3 - 0x31;

  }

  tbl = DAT_0067ef00_abs[uVar4];

  if (tbl == 0) {
    return 0;
  }

  uVar4 = (u32)*(u8 *)(tbl + uVar3);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xf8)) {

      *(SceneVecBits *)&blk.xy = *(SceneVecBits *)DAT_006a2da0_abs;

      blk.addrs[0] = iVar1 + 0x11c;

      blk.addrs[1] = iVar1 + 0x128;

      blk.addrs[2] = iVar1 + 0x134;

      lVar2 = FUN_001aaad0(param_1,blk.addrs,&blk);

      if (lVar2 == 1) {

        if (((fVar5 = *(float *)((int)param_1 + 4)) < *(float *)(blk.addrs[0] + 4) + 100.0f) &&

           (fVar5 > *(float *)(blk.addrs[0] + 4) - 100.0f)) {

          uVar4 = *(u32 *)(iVar1 + 0x14c);
          break;

        }

      }

      blk.addrs[0] = iVar1 + 0x128;

      blk.addrs[1] = iVar1 + 0x134;

      blk.addrs[2] = iVar1 + 0x140;

      lVar2 = FUN_001aaad0(param_1,blk.addrs,&blk);

      if (lVar2 == 1) {

        if (((fVar5 = *(float *)((int)param_1 + 4)) < *(float *)(blk.addrs[0] + 4) + 100.0f) &&

           (fVar5 > *(float *)(blk.addrs[0] + 4) - 100.0f)) {

          uVar4 = *(u32 *)(iVar1 + 0x14c);
          break;

        }

      }

    }

  return uVar4;

}
#define FUN_003baa70(...) ((u32 (*)(...))FUN_003baa70)(__VA_ARGS__)
#undef FUN_003bac40
// FUN_003BAC40 NONMATCHING


u32 FUN_003bac40(Resrc *param_1,u32 param_2)



{

  u8 bVar1;

  char cVar2;

  u8 bVar3;

  u32 uVar4;

  u32 lVar5;

  u32 uVar6;

  int iVar7;

  u16 *puVar8;

  

  if (param_1 == 0) {

    uVar4 = 0;

  }

  else {

    puVar8 = (u16 *)param_1;

    iVar7 = (int)(*puVar8 & 0xffc00) >> 10;

    if (iVar7 == 1) {

      if (param_2 == '\n') {

        if (*(int *)(puVar8 + 0x84) != 0) {

          FUN_0034fd10();

          FUN_005225a8(0x6a2ea0);

        }

        else {

          lVar5 = FUN_003bd1c0_mt(10);

          if (lVar5 != 0) {

            lVar5 = FUN_0034fcd0(lVar5);

            *(int *)(puVar8 + 0x84) = (int)lVar5;

            if (lVar5 == 0) {

              FUN_0019d3f0("mt_sceneFunc.c",0x69a);

            }

            FUN_005225a8(0x6a2ec0);

          }

        }

      }

      else {

        bVar1 = (char)puVar8[0x86] != '\0';

        bVar3 = !bVar1;

        iVar7 = *(int *)(puVar8 + (u32)bVar3 * 2 + 0x80);

        if (iVar7 != 0) {

          uVar6 = (*DAT_00960184)(1,8,0x40000);

          lVar5 = FUN_00194b20(0,0x6a2db0,0x1cef,0x3b8210,0x3b8270,uVar6);

          if (lVar5 != 0) {

            *(u32 *)uVar6 = 2;

            ((u32 *)uVar6)[1] = iVar7;

          }

          (puVar8 + (u32)bVar3 * 2 + 0x80)[0] = 0;

          (puVar8 + (u32)bVar3 * 2 + 0x80)[1] = 0;

        }

        lVar5 = FUN_003bd1c0_mt(param_2);

        if (lVar5 != 0) {

          lVar5 = FUN_0034fcd0(lVar5);

          *(int *)(puVar8 + (u32)bVar1 * 2 + 0x80) = (int)lVar5;

          if (lVar5 == 0) {

            FUN_0019d3f0("mt_sceneFunc.c",0x6b3);

          }

        }

        *(u8 *)(puVar8 + 0x86) = (char)puVar8[0x86] == '\0';

      }

    }

    else {

      if (iVar7 != 3) {

        return 0;

      }

      if (param_2 == '\n') {

        if (*(int *)(puVar8 + 0x84) != 0) {

          FUN_0034fd10();

          FUN_005225a8(0x6a2ea0);

        }

        else {

          lVar5 = FUN_003bd1c0_mt(10);

          if (lVar5 != 0) {

            uVar4 = FUN_0034fcd0(lVar5);

            *(u32 *)(puVar8 + 0x84) = uVar4;

            FUN_005225a8(0x6a2ec0);

            if (*(int *)(puVar8 + 0x84) == 0) {

              FUN_0019d3f0("mt_sceneFunc.c",0x6c8);

            }

          }

        }

      }

      else {

        cVar2 = (char)puVar8[0x86];

        bVar1 = cVar2 == '\0';

        *(u8 *)(puVar8 + 0x86) = cVar2 == '\0';

        iVar7 = *(int *)(puVar8 + (u32)bVar1 * 2 + 0x80);

        if (iVar7 != 0) {

          uVar6 = (*DAT_00960184)(1,8,0x40000);

          lVar5 = FUN_00194b20(0,0x6a2db0,0x1cef,0x3b8210,0x3b8270,uVar6);

          if (lVar5 != 0) {

            *(u32 *)uVar6 = 2;

            ((u32 *)uVar6)[1] = iVar7;

          }

          (puVar8 + (u32)bVar1 * 2 + 0x80)[0] = 0;

          (puVar8 + (u32)bVar1 * 2 + 0x80)[1] = 0;

        }

        lVar5 = FUN_003bd1c0_mt(param_2);

        if (lVar5 != 0) {

          lVar5 = FUN_0034fcd0(lVar5);

          *(int *)(puVar8 + (u32)(cVar2 != '\0') * 2 + 0x80) = (int)lVar5;

          if (lVar5 == 0) {

            FUN_0019d3f0("mt_sceneFunc.c",0x6e3);

          }

        }

      }

    }

    uVar4 = 1;

  }

  return uVar4;

}
#define FUN_003bac40(...) ((u32 (*)(...))FUN_003bac40)(__VA_ARGS__)
#undef FUN_003bac40
#undef FUN_003bb010
// FUN_003BB010


u32 FUN_003bb010(u64 param_1,u32 param_2)



{

  Resrc *lVar1;


  

  lVar1 = (Resrc *)FUN_003b5d10();

  if (lVar1 != 0) {

    return FUN_003bac40(lVar1,param_2);

  }

  return 0;

}
#define FUN_003bb010(...) ((u32 (*)(...))FUN_003bb010)(__VA_ARGS__)
#undef FUN_003bb060
#undef FUN_003bac40
// FUN_003BB060


void FUN_003bb060(u16 param_1,u8 param_2)



{
  Resrc *lVar1;

  

  lVar1 = (Resrc *)FUN_003b5d10((u16)(param_1 & 0x3ff | 0xc00));

  if (lVar1 != 0) {

    FUN_003bac40(lVar1,(u8)(param_2 & 0xff));

  }

  return;

}
#define FUN_003bac40(...) ((u32 (*)(...))FUN_003bac40)(__VA_ARGS__)
#define FUN_003bb060(...) ((void (*)(...))FUN_003bb060)(__VA_ARGS__)
#undef FUN_003bb0c0
// FUN_003BB0C0


u32 FUN_003bb0c0(u16* param_1,int param_2)



{

  u32 uVar1;

  int iVar2;

  u16 *puVar3;

  int iVar4;

  

  iVar4 = 0;

  if (param_1 == 0) {

    uVar1 = 0;

  }

  else {

    puVar3 = (u16 *)param_1;

    iVar2 = (int)(*puVar3 & 0xffc00) >> 10;

    if (iVar2 == 3) goto case1;
    switch (iVar2) {
    case 1:
      goto case3;
    default:
      goto switch_end;
    }
case3:
    iVar4 = *(int *)(puVar3 + 0xf2);
    goto switch_end;
case1:
    iVar4 = *(int *)(puVar3 + 0xf8);
switch_end:
    if (iVar4 == 0) {

      uVar1 = 0;

    }

    else {

      if (param_2 == 1) {

        FUN_0019c310(iVar4,3);

      }

      else {

        FUN_0019c310(iVar4,0);

      }

      uVar1 = 1;

    }

  }

  return uVar1;

}
#define FUN_003bb0c0(...) ((u32 (*)(...))FUN_003bb0c0)(__VA_ARGS__)
#undef FUN_003bb180
// FUN_003BB180


u32 FUN_003bb180(u16 param_1,int param_2)
{
  Resrc *lVar1;

  lVar1 = MT_Scene_GetRes(param_1);
  if (lVar1 != 0) {
    return (FUN_003bb0c0)((u16 *)lVar1,param_2);
  }

  return 0;
}
#define FUN_003bb180(...) ((u32 (*)(...))FUN_003bb180)(__VA_ARGS__)
#undef FUN_003bb1d0
// FUN_003BB1D0


u32

FUN_003bb1d0(u16 param_1,u8 param_2,u8 param_3,u16 param_4,

            u16 param_5)



{
  u32 lVar3;
  u32 uVar2;
  u8 *puVar4;

  lVar3 = (u32)MT_Scene_GetRes(param_1);

  if (lVar3 == 0) {
    uVar2 = 0;
  }
  else if (lVar3 == 0) {
    uVar2 = 0;
  }
  else {
    puVar4 = (u8 *)(lVar3 + 0xa8);
    FUN_00521408(puVar4,0,10);
    puVar4[0] = param_2;
    puVar4[1] = 0;
    puVar4[2] = param_3;
    *(u16 *)(puVar4 + 6) = param_4;
    *(u16 *)(puVar4 + 8) = param_5;
    uVar2 = 1;
  }

  return uVar2;

}
#define FUN_003bb1d0(...) ((u32 (*)(...))FUN_003bb1d0)(__VA_ARGS__)
#undef FUN_003bb280
// FUN_003BB280


u32 FUN_003bb280(void)



{

  int iVar1;

  u32 uVar2;

  u32 lVar3;

  u16 *puVar4;

  lVar3 = FUN_003b5d10();

  if (lVar3 == 0) {

    uVar2 = 0;

  }

  else if (lVar3 == 0) {

    uVar2 = 0;

  }

  else {

    puVar4 = (u16 *)lVar3;

    if (((*puVar4 & 0xffc00) >> 10) != 7) {

      uVar2 = 0;

    }

    else {

      for (iVar1 = FUN_003b5d50(7); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xf8)) {

        *(u32 *)(iVar1 + 0x108) = 0;

      }

      uVar2 = 1;

      *(u32 *)(lVar3 + 0x108) = uVar2;

    }
  }

  return uVar2;

}

#define FUN_003bb280(...) ((u32 (*)(...))FUN_003bb280)(__VA_ARGS__)
#undef FUN_003bb340
// FUN_003BB340


void FUN_003bb340(void)



{

  int iVar1;

  

  for (iVar1 = FUN_003b5d50(7); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xf8)) {

    *(u32 *)(iVar1 + 0x108) = 0;

  }

  return;

}
#define FUN_003bb340(...) ((void (*)(...))FUN_003bb340)(__VA_ARGS__)
#undef FUN_003bb390
// FUN_003BB390


void FUN_003bb390(u32 param_2,u16 param_3,float param_1)



{

  u16 localParam3;
  u16 localParam2;
  Resrc *lVar1;
  localParam3 = param_3;
  localParam2 = param_2;
  if ((RESRC_GET_TYPE(localParam2) == RESRC_TYPE_07) && (lVar1 = (Resrc*)FUN_003b5d10(param_2), lVar1 != 0)) {

    *(u16 *)((u8*)lVar1 + 0x10c) = localParam3;

    *(float *)((u8*)lVar1 + 0x104) = param_1;

  }

  return;

}
#define FUN_003bb390(...) ((void (*)(...))FUN_003bb390)(__VA_ARGS__)
#undef FUN_003bb400
// FUN_003BB400


void FUN_003bb400(u32 param_1)



{

  u16 localParam1;
  Resrc *lVar1;
  localParam1 = (u16)param_1;
  if ((RESRC_GET_TYPE(localParam1) == RESRC_TYPE_07) && (lVar1 = (Resrc*)FUN_003b5d10(param_1), lVar1 != 0)) {

    *(u16 *)((int)lVar1 + 0x10c) = 0;
    *(u32 *)((int)lVar1 + 0x104) = 0;

  }

  return;

}
#define FUN_003bb400(...) ((void (*)(...))FUN_003bb400)(__VA_ARGS__)
#undef FUN_003bb450
/* W386 measurement: retail emits two consecutive sw $v0, 0x68($sp)
 * stores of 1.0f from one lui $v0, 0x3f80; our source emits one.
 * The eleven downstream scanner offset rows are the resulting one-slot
 * shift, not independent defects. Measured source forms: plain duplicate
 * (460 bytes), volatile-cast first (460), volatile-cast second (460), and
 * pointer-to-volatile (472), against this function's 464-byte window.
 * The pointer form preserves both stores only as addiu $v1,$sp,0x68 plus
 * indirect sws, so it cannot match retail and exceeds the window. The stack
 * map is matrix at sp+0x40, matrix.at.z at sp+0x68; axis3 starts at
 * sp+0x80 (axis2 +0x90, axis1 +0xa0, transformed +0xd0, source +0xc0,
 * axis0 +0xe0), with no local overlap at sp+0x68.
 */
/* W390 measured: nd 72 -> 4 by copying the axis2 {u64 xy; f32 z;} header as
 * ONE `SceneVecBits` aggregate instead of two per-field assignments, which
 * reproduces retail's two separate lui/LO16 materializations of DAT_006a2ef8
 * and removed the offset shift the W386 note above describes. The two dead
 * `xy`/`z` loads that used to feed axis2 were deleted with no nd change.
 * Residual nd 4 is the same b210 aggregate-copy WIDTH floor as FUN_003BAA70:
 * retail moves the tail via lwc1/swc1 (12 bytes), b210 blits ld/sd (16). */
/* W414 direct-width probes: replacing the aggregate with
 * `axis2.raw.xy = *(u64 *)DAT_006a2ef8_abs; axis2.raw.z =
 * *(f32 *)(DAT_006a2ef8_abs + 8);` emits the right lwc1/swc1 width but
 * reorders the surrounding load/store schedule (nd 68, 460/464). A byte
 * destination-pointer split reduces this only to nd 10 (460/464) but emits
 * indirect stores through the materialized stack pointer. RwV3d aggregate
 * and memcpy(12) forms exceed the 464-byte window (nd255/472 and nd302/472).
 * All were reverted; the existing nd4 aggregate copy remains the best form. */
// FUN_003BB450 NONMATCHING


void FUN_003bb450(float *input, float scale, float angle_y, float angle_x,
                 float angle_z, float *result)
{
  typedef union SceneVector {
    RwV3d value;
    struct {
      u64 xy;
      f32 z;
      u32 pad;
    } raw;
  } SceneVector;
  SceneVector axis0;
  SceneVector transformed;
  SceneVector source;
  SceneVector output;
  SceneVector axis1;
  SceneVector axis2;
  SceneVector axis3;
  RwMatrix matrix;
  u64 xy;
  f32 z;

  xy = *(u64 *)DAT_006a2ed8_abs;
  z = *(f32 *)DAT_006a2ee0_abs;
  axis0.raw.xy = xy;
  axis0.raw.z = z;
  xy = *(u64 *)DAT_006a2ee8_abs;
  z = *(f32 *)DAT_006a2ef0_abs;
  axis1.raw.xy = xy;
  axis1.raw.z = z;
  *(SceneVecBits *)&axis2.raw.xy = *(SceneVecBits *)DAT_006a2ef8_abs;
  xy = *(volatile u64 *)DAT_006a2f08_abs;
  z = *(volatile f32 *)DAT_006a2f10_abs;
  axis3.raw.xy = xy;
  axis3.raw.z = z;

  matrix.at.z = 1.0f;
  matrix.up.y = 1.0f;
  matrix.right.x = 1.0f;
  matrix.up.x = 0.0f;
  matrix.right.z = 0.0f;
  matrix.right.y = 0.0f;
  matrix.at.y = 0.0f;
  matrix.at.x = 0.0f;
  matrix.up.z = 0.0f;
  matrix.pos.z = 0.0f;
  matrix.pos.y = 0.0f;
  matrix.pos.x = 0.0f;
  matrix.flags |= 0x20003;

  FUN_004c31b0_sceneFunc(&matrix, &axis2.value, angle_x, 1);
  FUN_004c31b0_sceneFunc(&matrix, &axis1.value, angle_y, 1);
  FUN_004c31b0_sceneFunc(&matrix, &axis3.value, angle_z, 1);
  FUN_004c6c60(&transformed.value, &axis0.value, &matrix);

  source.value = *(RwV3d *)input;
  output.value.x = source.value.x - transformed.value.x * scale;
  output.value.y = source.value.y - transformed.value.y * scale;
  output.value.z = source.value.z - transformed.value.z * scale;
  *(RwV3d *)result = output.value;
}
#define FUN_003bb450(...) ((void (*)(...))FUN_003bb450)(__VA_ARGS__)
#undef FUN_003bb450
#undef FUN_003bb620
/* W406 aggregate-width probes: the packed-pragma local aggregate measured normalized_diff 132 with object/window 384/384, while explicit no-local member-copy forms measured normalized_diff 13/14. The volatile scalar-source copy below is the best measured form (normalized_diff 4, object/window 376/384); do not alter the shared SceneVecBits typedef. */
/* W414 direct stack-store negative: removing the `dest` pointer and writing
 * `direction` directly emits stack-addressed stores but reorders the local
 * aggregate staging, measuring nd17 (376/384) versus retained nd4. Reverted. */
// FUN_003BB620 NONMATCHING


void FUN_003bb620(u32 *param_2,int param_3,float param_1)



{

  u32 uVar1;

  u32 uVar2;

  int lVar3;

  u16 mode;

  u32 *puVar6;

  u64 *puVar5;

  int cnt;

  u64 dstbuf[8];

  u32 auStack_d0 [16];

  float src1[3];

  float src2[3];

  float out[3];

  f32 direction[3];

  float normal[3];
  u64 xy;
  f32 z;
  u8 *dest;


  float t0;
  float t1;
  float t2;

  

  t0 = *(volatile float *)(param_3 + 4);
  t1 = *(volatile float *)(param_3 + 8);
  t2 = *(volatile float *)(param_3 + 0xc);
  *(volatile float *)&src1[0] = t0;
  *(volatile float *)&src1[1] = t1;
  *(volatile float *)&src1[2] = t2;

  t0 = *(volatile float *)(param_3 + 0x10);
  t1 = *(volatile float *)(param_3 + 0x14);
  t2 = *(volatile float *)(param_3 + 0x18);
  *(volatile float *)&src2[0] = t0;
  *(volatile float *)&src2[1] = t1;
  *(volatile float *)&src2[2] = t2;

  mode = *(u16 *)(param_3 + 0x10c);

  if ((mode != 0) && (lVar3 = FUN_003b5d10(mode), lVar3 != 0)) {

    src1[0] = *(float *)((int)lVar3 + 4);

    src1[1] = *(float *)((int)lVar3 + 8);

    src1[2] = *(float *)((int)lVar3 + 0xc);

    param_1 = *(float *)(param_3 + 0x104);

    FUN_003b79a0(auStack_d0,src1,src2);

    puVar6 = auStack_d0;

    puVar5 = dstbuf;

    cnt = 8;

    do {

      uVar1 = *puVar6;

      uVar2 = puVar6[1];

      puVar6 = puVar6 + 2;

      cnt = cnt + -1;

      *(u32 *)puVar5 = uVar1;

      *(u32 *)((int)puVar5 + 4) = uVar2;

      puVar5 = puVar5 + 1;

    } while (0 < cnt);

    dest = (u8 *)direction;
    xy = *(volatile u64 *)dstbuf;
    z = *(volatile f32 *)((u8 *)dstbuf + 8);
    *(u64 *)dest = xy;
    *(f32 *)(dest + 8) = z;
    FUN_004c69f0(normal,direction);

    src1[0] = src1[0] - normal[0] * 15.0f;

    src1[2] = src1[2] - normal[2] * 15.0f;

  }

  FUN_003bb450_scene_typed(src1,param_1,src2[0],src2[1],src2[2],out);

  t0 = *(volatile float *)&out[0];
  t1 = *(volatile float *)&out[1];
  t2 = *(volatile float *)&out[2];
  *(float *)param_2 = t0;
  *(float *)(param_2 + 1) = t1;
  *(float *)(param_2 + 2) = t2;

  return;

}
#define FUN_003bb450(...) ((void (*)(...))FUN_003bb450)(__VA_ARGS__)
#define FUN_003bb620(...) ((void (*)(...))FUN_003bb620)(__VA_ARGS__)
#undef FUN_003bb7a0
// FUN_003BB7A0


void FUN_003bb7a0(Resrc* param_1)



{

  int lVar2;

  int lVar4;

  int iVar1;

  u32 *puVar3;

  float outv[4];

  float vec0[4];
  float vec1[4];
  float vec2[4];

  struct { u64 pad0; float v[6]; } sc;

  u64 txy;
  f32 tz;
  f32 fc;
  f32 fb;
  f32 fa;

  

  lVar4 = FUN_00198590();

  txy = *(volatile u64 *)DAT_006a2f18_abs;
  tz = *(volatile f32 *)DAT_006a2f20_abs;
  *(volatile u64 *)vec0 = txy;
  *(volatile f32 *)&vec0[2] = tz;
  txy = *(volatile u64 *)DAT_006a2f28_abs;
  tz = *(volatile f32 *)DAT_006a2f30_abs;
  *(volatile u64 *)vec1 = txy;
  *(volatile f32 *)&vec1[2] = tz;
  txy = *(volatile u64 *)DAT_006a2f38_abs;
  tz = *(volatile f32 *)DAT_006a2f40_abs;
  *(volatile u64 *)vec2 = txy;
  *(volatile f32 *)&vec2[2] = tz;

  iVar1 = *(int *)((int)lVar4 + 4);

  if (((param_1 == 0) || (lVar4 == 0)) || (iVar1 == 0)) {
    return;
  }
  else {

    (FUN_003bb620)((u32 *)outv,(int)param_1,0.0f);

    fa = *(volatile f32 *)&outv[0];
    fb = *(volatile f32 *)&outv[1];
    fc = *(volatile f32 *)&outv[2];
    *(float *)((int)param_1 + 4) = fa;
    *(float *)((int)param_1 + 8) = fb;
    *(float *)((int)param_1 + 0xc) = fc;

    puVar3 = (u32 *)FUN_004c38c0();

    puVar3[10] = 0x3f800000;

    puVar3[5] = 0x3f800000;

    *puVar3 = 0x3f800000;

    puVar3[4] = 0;

    puVar3[2] = 0;

    puVar3[1] = 0;

    puVar3[9] = 0;

    puVar3[8] = 0;

    puVar3[6] = 0;

    puVar3[0xe] = 0;

    puVar3[0xd] = 0;

    puVar3[0xc] = 0;

    puVar3[3] = puVar3[3] | 0x20003;

    FUN_004c31b0_sceneFunc((RwMatrix *)puVar3,(const RwV3d *)vec0,*(f32 *)((int)param_1 + 0x14),1);
    FUN_004c31b0_sceneFunc((RwMatrix *)puVar3,(const RwV3d *)vec1,*(f32 *)((int)param_1 + 0x10),1);
    FUN_004c31b0_sceneFunc((RwMatrix *)puVar3,(const RwV3d *)vec2,*(f32 *)((int)param_1 + 0x18),1);

    FUN_004c35d0((int)puVar3,outv,2);

    lVar2 = FUN_003bc900_sceneI(&sc.v[4]);

    if (lVar2 == 1) {

      sc.v[0] = sc.v[4];
      sc.v[1] = sc.v[5];
      sc.v[2] = 0.0f;
      FUN_004c35d0((int)puVar3,sc.v,1);

    }

    FUN_004cb930(iVar1);

    FUN_004cb7f0(iVar1,(int)puVar3,0);

    FUN_004c3880((int)puVar3);

    FUN_001a4580_sceneF((int)lVar4,*(f32 *)((int)param_1 + 0x100));

  }

  return;

}
#define FUN_003bb7a0(...) ((void (*)(...))FUN_003bb7a0)(__VA_ARGS__)
#undef FUN_003bb9b0
#pragma push
/* Removing this loses FUN_003bb9b0 (MATCH nd0 -> MISMATCH nd143) - measured W161. */
#pragma opt_loop_invariants on
// FUN_003BB9B0


void FUN_003bb9b0(float *param_1)



{

  int iVar2;
  float afStack_10 [4];

  afStack_10[0] = *param_1;
  afStack_10[1] = param_1[1];
  afStack_10[2] = param_1[2];
  for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
    while (afStack_10[iVar2] >= 360.0f) {
      afStack_10[iVar2] = afStack_10[iVar2] - 360.0f;
    }
    while (afStack_10[iVar2] < 0.0f) {
      afStack_10[iVar2] = afStack_10[iVar2] + 360.0f;
    }
  }

  *param_1 = afStack_10[0];

  param_1[1] = afStack_10[1];

  param_1[2] = afStack_10[2];

  return;

}
#pragma pop
#define FUN_003bb9b0(...) ((void (*)(...))FUN_003bb9b0)(__VA_ARGS__)
#undef FUN_003bba70
// FUN_003BBA70


void FUN_003bba70(int param_1)



{

  (FUN_003bb9b0)((float *)(param_1 + 0x10));

  return;

}
#define FUN_003bba70(...) ((void (*)(...))FUN_003bba70)(__VA_ARGS__)
#undef FUN_003bbaa0
#pragma push
/* opt_loop_invariants on: measured off nd 95, object 236/240; on nd 0, object 228/240 (MATCH); retain on. */
#pragma opt_loop_invariants on
// FUN_003BBAA0


void FUN_003bbaa0(float *param_1,float *param_2,float *param_3)
{
  int iVar1;
  float delta[4];
  float adjusted[4];
  const float wrap = 360.0f;
  const float limit = 180.0f;

  delta[0] = param_2[0] - param_1[0];
  delta[1] = param_2[1] - param_1[1];
  delta[2] = param_2[2] - param_1[2];
  FUN_003bb9b0_scene_typed(delta);
  adjusted[0] = delta[0];
  adjusted[1] = delta[1];
  adjusted[2] = delta[2];
  for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {
    if (adjusted[iVar1] <= limit) {
      continue;
    }
    adjusted[iVar1] = -(wrap - adjusted[iVar1]);
  }
  param_3[0] = adjusted[0];
  param_3[1] = adjusted[1];
  param_3[2] = adjusted[2];
}
#pragma pop
#define FUN_003bbaa0(...) ((void (*)(...))FUN_003bbaa0)(__VA_ARGS__)
#undef FUN_003bbb90
// FUN_003BBB90


void FUN_003bbb90(const float *param_1,float *param_2)
{
  u32 uVar1;
  float fVar2;
  u64 txy;
  float tz;
  SceneVecBits source;
  float afStack_20 [4];

  txy = ((volatile SceneVecBits *)DAT_006a2f48_abs)->xy;
  tz = *(volatile float *)DAT_006a2f50_abs;
  *(volatile u64 *)&source.xy = txy;
  *(volatile float *)&source.z = tz;
  fVar2 = FUN_004c69f0_scene_typed(afStack_20,param_1);
  if (fVar2 == 0.0f) {
    param_2[0] = 0.0f;
    param_2[1] = 0.0f;
    param_2[2] = 0.0f;
  }
  else {
    afStack_20[1] = 0.0f;
    uVar1 = FUN_00530da0_scene(afStack_20[0] * ((float *)&source.xy)[0] +
                         afStack_20[1] * ((float *)&source.xy)[1] +
                         afStack_20[2] * source.z);
    uVar1 = FUN_0052e9a0_scene_typed(uVar1);
    fVar2 = fGpffff8228 * FUN_005318a0_scene_typed(uVar1);
    if (afStack_20[0] < 0.0f) {
      fVar2 = fVar2 * -1.0f;
    }
    param_2[1] = fVar2;
    param_2[0] = 0.0f;
    param_2[2] = 0.0f;
  }
}
#define FUN_003bbb90(...) ((void (*)(...))FUN_003bbb90)(__VA_ARGS__)
#undef FUN_003bbc90
// FUN_003BBC90


void FUN_003bbc90(float t, float *x, float *y, float *z, float *outX,
                  float *outY, float *outZ)
{
  float oneMinus = 1.0f - t;
  float oneMinusSquared = oneMinus * oneMinus;
  float w0;
  float w1;
  float w2;
  float w3;
  float tSquared;
  float rx;

  RwV3d result;
  w0 = oneMinus * oneMinusSquared;
  rx = x[0] * w0;
  w1 = t * (3.0f * oneMinusSquared);
  rx += x[1] * w1;
  tSquared = t * t;
  w2 = (3.0f * oneMinus) * tSquared;
  rx += x[2] * w2;
  w3 = t * tSquared;
  rx += x[3] * w3;
  result.x = rx;
  rx = y[0] * w0;
  rx += y[1] * w1;
  rx += y[2] * w2;
  rx += y[3] * w3;
  result.y = rx;
  rx = z[0] * w0;
  rx += z[1] * w1;
  rx += z[2] * w2;
  rx += z[3] * w3;
  result.z = rx;

  *outX = result.x;
  *outY = result.y;
  *outZ = result.z;
}
#define FUN_003bbc90(...) ((void (*)(...))FUN_003bbc90)(__VA_ARGS__)
#undef FUN_003bbd40
/* opt_lifetimes on: measured nd 62 -> 0, object 400/400 -> 400/400. */
#pragma opt_lifetimes on
// FUN_003BBD40


void FUN_003bbd40(float param_1,char *param_2,float *param_3)



{

  char cVar1;

  int iVar2;

  int segmentIndex;
  int iVar3;


  float fVar5;

  float auStack_10 [4];

  float auStack_20 [4];

  float auStack_30 [4];

  

  cVar1 = *param_2;

  if ('\0' < cVar1) {


    if (!(param_1 < 1.0f)) {

      iVar3 = 0;
      segmentIndex = cVar1 - 1;
      param_2 += segmentIndex * 0x24;

      for (; iVar3 < 4; iVar3 = iVar3 + 1) {

        iVar2 = iVar3 * 0xc;

        auStack_10[iVar3] = *(float *)(param_2 + iVar2 + 4);

        auStack_20[iVar3] = *(float *)(param_2 + iVar2 + 8);

        auStack_30[iVar3] = *(float *)(param_2 + iVar2 + 0xc);

      }

      FUN_003bbc90_scene_typed(1.0f,auStack_10,auStack_20,auStack_30,param_3,param_3 + 1,param_3 + 2);

    }

    else {

      fVar5 = 1.0f / (float)(int)cVar1;

      segmentIndex = (int)(param_1 / fVar5);
      iVar3 = 0;
      param_2 += segmentIndex * 0x24;

      for (; iVar3 < 4; iVar3 = iVar3 + 1) {

        iVar2 = iVar3 * 0xc;

        auStack_10[iVar3] = *(float *)(param_2 + iVar2 + 4);

        auStack_20[iVar3] = *(float *)(param_2 + iVar2 + 8);

        auStack_30[iVar3] = *(float *)(param_2 + iVar2 + 0xc);

      }

      while (param_1 > fVar5) {

        param_1 = param_1 - fVar5;

      }

      FUN_003bbc90_scene_typed(param_1 / fVar5,auStack_10,auStack_20,auStack_30,param_3,param_3 + 1,param_3 + 2);

    }

  }

  return;

}
#define FUN_003bbd40(...) ((void (*)(...))FUN_003bbd40)(__VA_ARGS__)
#pragma opt_lifetimes reset
#undef FUN_003bbed0
// FUN_003BBED0


float FUN_003bbed0(u32 param_3,float param_1,float param_2)
{
  float *pfVar1;
  u8 auStack[0x138];

  if (param_3 >= 6) {
    FUN_0019d3f0("mt_sceneFunc.c",0x980);
  }
  if (param_1 == 0.0f) {
    param_2 = 1.0f;
  }
  else {
    param_2 = param_2 / param_1;
  }
  auStack[0] = 1;
  *(u32 *)(auStack + 4) = 0;
  *(u32 *)(auStack + 8) = 0;
  *(u32 *)(auStack + 0xc) = 0;
  pfVar1 = (float *)FUN_003b55b0(param_3);
  *(float *)(auStack + 0x10) = pfVar1[0];
  *(float *)(auStack + 0x14) = pfVar1[2];
  *(u32 *)(auStack + 0x18) = 0;
  *(float *)(auStack + 0x1c) = pfVar1[1];
  *(float *)(auStack + 0x20) = pfVar1[3];
  *(u32 *)(auStack + 0x24) = 0;
  *(u32 *)(auStack + 0x28) = 0x3f800000;
  *(u32 *)(auStack + 0x2c) = 0x3f800000;
  *(u32 *)(auStack + 0x30) = 0;
  FUN_003bbd40_scene_typed((char *)auStack,param_2,(float *)(auStack + 0x130));
  return *(float *)(auStack + 0x134) * param_1;
}
#define FUN_003bbed0(...) ((float (*)(...))FUN_003bbed0)(__VA_ARGS__)
#undef FUN_003bbfd0
// FUN_003BBFD0

float FUN_003bbfd0(float param_1,float param_2,float *param_3,float *param_4,
                  float *param_5,float *param_6,float *param_7)
{
  RwV3d delta;
  float first_x;
  float second_x;
  float first_y;
  float second_y;
  float first_z;
  float second_z;
  float first_len;

  FUN_003bbc90_scene_typed(param_1,param_3,param_4,param_5,&first_x,&first_y,&first_z);
  FUN_003bbc90_scene_typed(param_2,param_3,param_4,param_5,&second_x,&second_y,&second_z);
  delta.x = second_x - first_x;
  delta.y = second_y - first_y;
  delta.z = second_z - first_z;
  first_len = FUN_004c6ac0_scene_vec(&delta);
  *param_6 = first_x;
  param_6[1] = first_y;
  param_6[2] = first_z;
  *param_7 = second_x;
  param_7[1] = second_y;
  param_7[2] = second_z;
  return first_len;
}
#define FUN_003bbfd0(...) ((void (*)(...))FUN_003bbfd0)(__VA_ARGS__)
#undef FUN_003bc0e0
// FUN_003BC0E0


float FUN_003bc0e0(char *param_1)



{

  int iVar1;

  int lVar2;

  int iVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float scale;

  float auStack_10 [4];

  float auStack_20 [4];

  float auStack_30 [4];

  float auStack_40 [4];

  float auStack_50 [4];

  

  fVar5 = 0.0f;

  for (lVar2 = 0; lVar2 < *param_1; lVar2 = lVar2 + 1) {

    {
      char *curve;
      int copyIndex;

      copyIndex = 0;
      curve = param_1 + lVar2 * 0x24;
      for (; copyIndex < 4; copyIndex = copyIndex + 1) {

        iVar1 = copyIndex * 0xc;

        auStack_30[copyIndex] = *(float *)(curve + iVar1 + 4);

        auStack_40[copyIndex] = *(float *)(curve + iVar1 + 8);

        auStack_50[copyIndex] = *(float *)(curve + iVar1 + 0xc);

      }
    }

    fVar6 = 0.0f;

    for (iVar3 = 0; iVar3 < 0x14; iVar3 = iVar3 + 1) {

      fVar4 = (float)iVar3;
      scale = DAT_007cb0b8;
      fVar4 = fVar4 * scale;
      fVar4 = FUN_003bbfd0_scene_typed(fVar4,(float)(iVar3 + 1) * scale,
                   auStack_30,auStack_40,auStack_50,auStack_10,auStack_20);

      fVar6 = fVar6 + fVar4;

    }

    fVar5 = fVar5 + fVar6;

  }

  return fVar5;

}
#define FUN_003bc0e0(...) ((float (*)(...))FUN_003bc0e0)(__VA_ARGS__)
#undef FUN_003bc220
/* opt_lifetimes on: measured nd 952 -> 949, object 1272/1296 -> 1272/1296. */
#pragma opt_lifetimes on
// FUN_003BC220 NONMATCHING


float FUN_003bc220(char *param_1,float param_2,float param_3,float *param_4,u32 *param_5)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int lVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  u32 auStack_f0 [4];

  u32 auStack_e0 [4];

  u32 auStack_d0 [6];

  RwV3d tangent;
  RwV3d segment;
  RwV3d finalSegment;

  u8 auStack_88 [16];

  RwV3d direction;

  float fStack_68;

  float fStack_64;

  float fStack_60;

  float fStack_58;

  float fStack_54;

  float fStack_50;

  float fStack_48;

  float fStack_44;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  float fStack_34;

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_c;

  float fStack_8;

  float fStack_4;

  

  fVar8 = 0.0f;

  cVar1 = *param_1;

  fVar6 = (1.0f / (float)(int)cVar1) / 20.0f;

  fVar7 = 0.0f;

  if (param_3 > param_2) {

    for (lVar4 = 0; lVar4 < *param_1; lVar4 = (long)((int)lVar4 + 1)) {

      for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

        iVar2 = iVar3 + (int)lVar4 * 3;

        auStack_d0[iVar3] = *(u32 *)(param_1 + iVar2 * 0xc + 4);
        auStack_e0[iVar3] = *(u32 *)(param_1 + iVar2 * 0xc + 8);
        auStack_f0[iVar3] = *(u32 *)(param_1 + iVar2 * 0xc + 0xc);

      }

      for (iVar3 = 0; iVar3 < 0x14; iVar3 = iVar3 + 1) {

        fVar9 = (float)iVar3 * DAT_007cad5c;

        FUN_003bbc90_scene_typed(fVar9,auStack_d0,auStack_e0,auStack_f0,&fStack_1c,&fStack_24,&fStack_2c);

        FUN_003bbc90_scene_typed((float)(iVar3 + 1) * DAT_007cad5c,auStack_d0,auStack_e0,auStack_f0,&fStack_20,

                     &fStack_28,&fStack_30);

        segment.x = fStack_20 - fStack_1c;
        segment.y = fStack_28 - fStack_24;
        segment.z = fStack_30 - fStack_2c;
        fVar5 = (float)FUN_004c6ac0(&segment);

        fStack_58 = fStack_20;

        fStack_54 = fStack_28;

        fStack_50 = fStack_30;

        fVar8 = fVar8 + fVar5;

        if (param_2 <= fVar8) {
          fVar8 = 1.0f - (fVar8 - param_2) / fVar5;

          fStack_68 = fStack_20 - fStack_1c;

          fStack_64 = fStack_28 - fStack_24;

          fStack_60 = fStack_30 - fStack_2c;

          *param_4 = fStack_68 * fVar8 + fStack_1c;

          param_4[1] = fStack_64 * fVar8 + fStack_24;

          param_4[2] = fStack_60 * fVar8 + fStack_2c;

          fVar9 = fVar9 + fVar6 * fVar8;

          FUN_003bbc90_scene_typed(fVar9,auStack_d0,auStack_e0,auStack_f0,&fStack_34,&fStack_3c,&fStack_44);

          FUN_003bbc90_scene_typed(fVar9 - DAT_007caf1c,auStack_d0,auStack_e0,auStack_f0,&fStack_38,&fStack_40,

                       &fStack_48);

          tangent.x = fStack_38 - fStack_34;
          tangent.y = fStack_40 - fStack_3c;
          tangent.z = fStack_48 - fStack_44;
          FUN_004c6ac0(&tangent);

          direction.x = fStack_34 - fStack_38;
          direction.y = fStack_3c - fStack_40;
          direction.z = fStack_44 - fStack_48;
          FUN_004c69f0(auStack_88,&direction);

          FUN_003bbb90_scene_typed((const float *)auStack_88,param_5);

          return fVar7 + fVar6 * fVar8;

        }

        fVar7 = fVar7 + fVar6;

      }

    }

    fVar6 = 0.0f;

  }

  else {

    for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

      iVar2 = iVar3 * 0xc + (cVar1 + -1) * 0x24;

      auStack_d0[iVar3] = *(u32 *)(param_1 + iVar2 + 4);
      auStack_e0[iVar3] = *(u32 *)(param_1 + iVar2 + 8);
      auStack_f0[iVar3] = *(u32 *)(param_1 + iVar2 + 0xc);

    }

    FUN_003bbc90_scene_typed(DAT_007caea4,auStack_d0,auStack_e0,auStack_f0,&fStack_4,&fStack_c,&fStack_14);

    FUN_003bbc90_scene_typed(1.0f,auStack_d0,auStack_e0,auStack_f0,&fStack_8,&fStack_10,&fStack_18);

    finalSegment.x = fStack_8 - fStack_4;
    finalSegment.y = fStack_10 - fStack_c;
    finalSegment.z = fStack_18 - fStack_14;
    FUN_004c6ac0(&finalSegment);

    fStack_58 = fStack_8;

    fStack_54 = fStack_10;

    fStack_50 = fStack_18;

    *param_4 = fStack_8;

    param_4[1] = fStack_10;

    param_4[2] = fStack_18;

    fStack_68 = fStack_8 - fStack_4;

    fStack_64 = fStack_10 - fStack_c;

    fStack_60 = fStack_18 - fStack_14;

    FUN_004c69f0(auStack_88,&fStack_68);

    FUN_003bbb90_scene_typed((const float *)auStack_88,param_5);

    fVar6 = 1.0f;

  }

  return fVar6;

}
#define FUN_003bc220(...) ((float (*)(...))FUN_003bc220)(__VA_ARGS__)
#pragma opt_lifetimes reset
#undef FUN_003bc730
// FUN_003BC730


float FUN_003bc730(char *param_1,int param_2)
{
  int iVar1;
  int lVar4;
  int iVar3;
  int iVar2;
  float fVar5;
  float fVar6;
  float auStack_40 [4];
  float auStack_50 [4];
  float auStack_60 [4];
  RwV3d delta;
  float fStack_4;
  float fStack_8;
  float fStack_c;
  float fStack_10;
  float fStack_14;
  float fStack_18;

  fVar6 = 0.0f;
  iVar3 = 0;
  lVar4 = 0;
  while (lVar4 < *param_1) {
    if (iVar3 == param_2) {
      return fVar6;
    }
    {
      int pointBase;
      int copyIndex;

      copyIndex = 0;
      pointBase = lVar4 * 3;
      for (; copyIndex < 4; copyIndex = copyIndex + 1) {
        iVar1 = copyIndex + pointBase;
        auStack_40[copyIndex] = *(float *)(param_1 + iVar1 * 0xc + 4);
        auStack_50[copyIndex] = *(float *)(param_1 + iVar1 * 0xc + 8);
        auStack_60[copyIndex] = *(float *)(param_1 + iVar1 * 0xc + 0xc);
      }
    }
    for (iVar2 = 0; iVar2 < 0x14; iVar2 = iVar2 + 1) {
      FUN_003bbc90_scene_typed((float)iVar2 * DAT_007cb0b8,auStack_40,auStack_50,auStack_60,&fStack_4,&fStack_c,
                   &fStack_14);
      FUN_003bbc90_scene_typed((float)(iVar2 + 1) * DAT_007cb0b8,auStack_40,auStack_50,auStack_60,&fStack_8,
                   &fStack_10,&fStack_18);
      delta.x = fStack_8 - fStack_4;
      delta.y = fStack_10 - fStack_c;
      delta.z = fStack_18 - fStack_14;
      fVar5 = FUN_004c6ac0_scene_vec(&delta);
      fVar6 = fVar6 + fVar5;
    }
    iVar3 = iVar3 + 1;
    lVar4 = lVar4 + 1;
  }
  return 0.0f;
}
#define FUN_003bc730(...) ((float (*)(...))FUN_003bc730)(__VA_ARGS__)
#undef FUN_003bc8f0
// FUN_003BC8F0


int FUN_003bc8f0(char *param_1)



{

  return *param_1 + -1;

}
#define FUN_003bc8f0(...) ((int (*)(...))FUN_003bc8f0)(__VA_ARGS__)
/* optimization_level 1: measured O2 nd 18, object 56/64; O1 nd 0, object 60/64 (MATCH); retain O1. */
#pragma optimization_level 1
#undef FUN_003bc900
// FUN_003BC900


u8 FUN_003bc900(float *param_1)



{

  if (*(u16 *)&DAT_007ce658 == 0) {
    return 0;
  }
  param_1[0] = *(float *)(uintptr_t)0x0095aff0;
  param_1[1] = *(float *)(uintptr_t)0x0095aff4;
  return 1;

}
#define FUN_003bc900(...) ((u8 (*)(...))FUN_003bc900)(__VA_ARGS__)
#pragma optimization_level 2
#undef FUN_003bc940
// FUN_003BC940 NONMATCHING








void FUN_003bc940(void)



{

  int iVar1;

  float *pfVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float afStack_10 [4];
  f32 ha;
  f32 hb;

  

  ha = *(volatile f32 *)&DAT_007cd560;
  hb = *(volatile f32 *)&DAT_007cd564;
  afStack_10[0] = ha;
  afStack_10[1] = hb;

  if (DAT_007ce658 == 0) {

    ((f32*)DAT_0095aff0_abs)[0] = 0;

    ((f32*)DAT_0095aff0_abs)[1] = 0;

    ((f32*)DAT_0095aff0_abs)[2] = 0;

    ((f32*)DAT_0095aff0_abs)[3] = 0;

  }

  else if (DAT_007ce65c == 0) {

    DAT_007ce658 = 0;

  }

  else {

    ha = (float)DAT_007ce660;
    afStack_10[2] = ha * DAT_007cada0;

    ha = (float)DAT_007ce664;
    afStack_10[3] = ha * DAT_007cada0;

    for (iVar1 = 0; iVar1 < 2; iVar1 = iVar1 + 1) {

      fVar6 = afStack_10[iVar1 + 2];

      if (fVar6 != 0.0f) {

        fVar3 = (float)FUN_00358030(0);

        fVar4 = afStack_10[iVar1 + 2];

        fVar5 = fVar4 * 0.5f + fVar4 * fVar3 * 0.5f;

        pfVar2 = (f32*)DAT_0095aff0_abs + iVar1;

        fVar3 = *pfVar2;

        if (fVar4 * afStack_10[iVar1] <= fabsf(fVar3)) {

          if (fVar3 <= 0.0f) {

            *pfVar2 = fVar3 + fVar5;

          }

          else {

            *pfVar2 = fVar3 - fVar5;

          }

        }

        else {

          fVar3 = (float)FUN_00358030(0);

          *pfVar2 = fVar5 * (fVar3 - 0.5f) * 2.0f + *pfVar2;

        }

        if (*pfVar2 < -fVar6) {

          *pfVar2 = -fVar6;

        }

        if (fVar6 < *pfVar2) {

          *pfVar2 = fVar6;

        }

      }

    }

    if (0 < DAT_007ce65c) {

      DAT_007ce660 = DAT_007ce660 - (u16)((u32)DAT_007ce660 / (DAT_007ce65c + 5));

      DAT_007ce664 = DAT_007ce664 - (u16)((u32)DAT_007ce664 / (DAT_007ce65c + 5));

      DAT_007ce65c = DAT_007ce65c + -1;

    }

  }

  return;

}
#define FUN_003bc940(...) ((void (*)(...))FUN_003bc940)(__VA_ARGS__)
#undef FUN_003bcbf0
// FUN_003BCBF0


void FUN_003bcbf0(int param_1,int param_2)



{
  if (param_2 == 0) {
    *(u16 *)&DAT_007ce658 = 0;
  }
  else {
    *(u16 *)&DAT_007ce658 = 1;
    if (param_1 == 0) {
      *(short *)&DAT_007ce65c = -1;
    }
    else {
      *(u16 *)&DAT_007ce65c = (short)param_1;
    }
    *(u16 *)&DAT_007ce664 = param_2 * 10;
    *(u16 *)&DAT_007ce660 = (*(u16 *)&DAT_007ce664 << 2) / 10;
    FUN_003500a0(param_1,(short)param_2);
  }
  return;

}
#define FUN_003bcbf0(...) ((void (*)(...))FUN_003bcbf0)(__VA_ARGS__)
#undef FUN_003bcc80
// FUN_003BCC80


void FUN_003bcc80(void)



{

  *(u16 *)&DAT_007ce658 = 0;

  FUN_003500e0();

  return;

}
#define FUN_003bcc80(...) ((void (*)(...))FUN_003bcc80)(__VA_ARGS__)
#pragma push
/* Removing this loses FUN_003bccb0 (MATCH nd0 -> MISMATCH nd14) - measured W161. */
#pragma opt_loop_invariants on
// FUN_003bccb0
void* MT_SceneFunc_UpdateSceneMngTask(KwlnTask* sceneMngTask)
{
    s32 i;
    Resrc* res;
    ResrcType7* type7Res;
    s32 type7Status;

    (FUN_003bc940)();
    for (i = 1; i < RESRC_TYPE_MAX; i++)
    {
        for (res = MT_Scene_GetResListHead(i); res != NULL; res = res->next)
        {
            (FUN_003b9610)(res);
        }
    }

    type7Res = (ResrcType7*)MT_Scene_GetResListHead(7);
    type7Status = 1;
    for (; type7Res != NULL; type7Res = (ResrcType7*)type7Res->base.next)
    {
        if (type7Res->unk_108 == type7Status)
        {
            (FUN_003bb7a0)((Resrc*)type7Res);
            break;
        }
    }

    return KWLNTASK_CONTINUE;
}
#pragma pop

// FUN_003bcd80
void MT_SceneFunc_DestroySceneMngTask(KwlnTask* sceneMngTask)
{
    (FUN_003bcc80)();
}
#undef FUN_003bcda0
// FUN_003BCDA0


int FUN_003bcda0(int *param_1,int *param_2)
{
  int matrix;
  int second;
  struct {
    RwV3d origin;
    u32 pad0;
    RwV3d secondDelta;
    u32 pad1;
    RwV3d firstDelta;
    u32 pad2;
  } vectors;
  RwMatrix secondPos;
  RwMatrix first;
  RwV3d *firstPosition;
  RwV3d *secondPosition;
  float oy;
  float oz;

  matrix = FUN_00198590();
  matrix = FUN_004cb2f0(*(u32 *)(matrix + 4));
  vectors.origin = ((RwMatrix *)matrix)->pos;

  second = *param_2;
  FUN_0034ffc0(*(u32 *)(*param_1 + 0x104),&secondPos);
  FUN_0034ffc0(*(u32 *)(second + 0x104),&first);
  firstPosition = &secondPos.pos;
  secondPosition = &first.pos;

  vectors.firstDelta.x = firstPosition->x - vectors.origin.x;
  oy = *(volatile float *)&vectors.origin.y;
  vectors.firstDelta.y = firstPosition->y - oy;
  oz = *(volatile float *)&vectors.origin.z;
  vectors.firstDelta.z = firstPosition->z - oz;
  vectors.secondDelta.x = secondPosition->x - vectors.origin.x;
  vectors.secondDelta.y = secondPosition->y - oy;
  vectors.secondDelta.z = secondPosition->z - oz;

  return (int)(FUN_004c6ac0(&vectors.firstDelta) - FUN_004c6ac0(&vectors.secondDelta));
}
#define FUN_003bcda0(...) ((int (*)(...))FUN_003bcda0)(__VA_ARGS__)
#undef FUN_003bceb0
// FUN_003BCEB0


void FUN_003bceb0(int param_1)



{

  u32 uVar1;

  int iVar2;

  int j;
  int iVar3;
  int originalHead;

  

  iVar3 = 0;

  originalHead = param_1;

  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0xf8)) {

    if (((*(u32 *)(param_1 + 0x28) & 2) != 0) && (*(int *)(param_1 + 0x104) != 0)) {

      switch (*(char *)(param_1 + 0x100)) {

      case 0:

        iVar3 = iVar3 + 1;

      }

    }

  }

  uVar1 = (*DAT_00960178_abs)(iVar3 << 2,0x40000);

  j = 0;

  param_1 = originalHead;

  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0xf8)) {

    if (((*(u32 *)(param_1 + 0x28) & 2) != 0) && (*(int *)(param_1 + 0x104) != 0)) {

      switch (*(char *)(param_1 + 0x100)) {

      case 0:

        *(int *)((int)uVar1 + j * 4) = param_1;

        j = j + 1;

      }

    }

  }

  FUN_005225f8(uVar1,iVar3,4,FUN_003bcda0);

  for (iVar2 = 0; iVar2 < iVar3; iVar2 = iVar2 + 1) {

    FUN_0034fd70((Model *)*(u32 *)(*(int *)((int)uVar1 + iVar2 * 4) + 0x104),3);

  }

  (*DAT_0096017c_abs)(uVar1);

  return;

}
#define FUN_003bceb0(...) ((void (*)(...))FUN_003bceb0)(__VA_ARGS__)
// FUN_003bd010
void* MT_SceneFunc_UpdateSceneMngDrawTask(KwlnTask* sceneMngDrawTask)
{
    Resrc* res;

    res = MT_Scene_GetResListHead(6);
    (FUN_003bceb0)((int)res);
    for (; res != NULL; res = res->next)
    {
        if ((res->flags & 2) != 0 && *(Model**)((u8*)res + 0x104) != NULL)
        {
            switch (*(s8*)((u8*)res + 0x100))
            {
            case 0:
                break;
            case 1:
                FUN_0034fd70(*(Model**)((u8*)res + 0x104), 6);
                break;
            default:
                break;
            }
        }
    }

    return KWLNTASK_CONTINUE;
}
// FUN_003bd0b0
KwlnTask* MT_SceneFunc_CreateTasks()
{
    KwlnTask* sceneMngTask;

    sceneMngTask = kwlnTaskCreate(NULL,
                                  "SceneManager Task",
                                  110,
                                  MT_SceneFunc_UpdateSceneMngTask,
                                  MT_SceneFunc_DestroySceneMngTask,
                                  NULL);


    kwlnTaskCreate(sceneMngTask,
                   "SceneManager Draw",
                   2109,
                   MT_SceneFunc_UpdateSceneMngDrawTask,
                   NULL,
                   NULL);

    return sceneMngTask;
}
#undef FUN_003bd130
// FUN_003BD130


void FUN_003bd130(void)



{

  void *pVar1;

  void **ppVar2;

  int iVar2;

  

  for (iVar2 = 0; iVar2 < 0x19; iVar2 = iVar2 + 1) {

    if (PTR_s_icon_ICON1_EPL_006a3130[iVar2] != (u8 *)0x0) {

      ppVar2 = (void **)(DAT_0095b000_abs + iVar2 * 4);
      /* Removing this barrier loses FUN_003bd130 (MATCH nd0 -> MISMATCH nd18) - measured W164. */
      asm ("" : "+m"(*ppVar2));

      pVar1 = FUN_00100d80_typed_scene((const char *)PTR_s_icon_ICON1_EPL_006a3130[iVar2],0);

      *ppVar2 = pVar1;

      FUN_001023a0(pVar1);

    }

  }

  return;

}
#define FUN_003bd130(...) ((void (*)(...))FUN_003bd130)(__VA_ARGS__)
#undef FUN_003bd1c0
// FUN_003BD1C0


u32 FUN_003bd1c0(u32 param_1)
{
  u8 auStack_4[4];
  u8 **ppuVar1;

  if (0x19 < param_1) {
    return 0;
  }

  ppuVar1 = (u8 **)PTR_s_icon_ICON1_EPL_006a3130 + param_1;
  if (*ppuVar1 == (u8 *)0x0) {
    return 0;
  }

  return FUN_001021c0(*ppuVar1, auStack_4);
}
#define FUN_003bd1c0(...) ((u64 (*)(...))FUN_003bd1c0)(__VA_ARGS__)
#undef FUN_003bd230
// FUN_003BD230


u32 FUN_003bd230(void)



{

  u8 uVar1;

  

  FUN_0035ed20(0);

  uVar1 = FUN_0035ed20(1);

  (FUN_003bb010)(0x400,uVar1);

  return 1;

}
#define FUN_003bd230(...) ((u32 (*)(...))FUN_003bd230)(__VA_ARGS__)
#define DAT_0095b074 (*(u32 *)DAT_0095b074_abs)
#define DAT_0095b1f8 (*(u32 *)DAT_0095b1f8_abs)
#define DAT_0095b208 (*(u32 *)DAT_0095b208_abs)
#define DAT_0095b20c (*(u32 *)DAT_0095b20c_abs)
#define DAT_0095b210 (*(u32 *)DAT_0095b210_abs)
#define DAT_0095b218 (*(u32 *)DAT_0095b218_abs)
#define DAT_0095b21c (*(u32 *)DAT_0095b21c_abs)
#define DAT_0095b220 (*(u32 *)DAT_0095b220_abs)
#define DAT_0095b224 (*(u32 *)DAT_0095b224_abs)
#define DAT_0095b238 (*(u32 *)DAT_0095b238_abs)
#define DAT_0095b240 (*(u32 *)DAT_0095b240_abs)
#define DAT_0095b244 (*(u32 *)DAT_0095b244_abs)
#define DAT_0095b248 (*(u32 *)DAT_0095b248_abs)
#define DAT_0095b24c (*(u32 *)DAT_0095b24c_abs)
#define DAT_0095b254 (*(u32 *)DAT_0095b254_abs)
#define DAT_0095b258 (*(u32 *)DAT_0095b258_abs)
#define DAT_0095b25c (*(u32 *)DAT_0095b25c_abs)
#define DAT_0095b260 (*(u32 *)DAT_0095b260_abs)
#define DAT_0095b264 (*(u32 *)DAT_0095b264_abs)
#define DAT_0095b268 (*(u32 *)DAT_0095b268_abs)
#define DAT_0095b26c (*(u32 *)DAT_0095b26c_abs)
#define DAT_0095b270 (*(u32 *)DAT_0095b270_abs)
#define DAT_0095b274 (*(u32 *)DAT_0095b274_abs)
#define DAT_0095b278 (*(u32 *)DAT_0095b278_abs)
#define DAT_0095b27c (*(u32 *)DAT_0095b27c_abs)
#define DAT_0095b284 (*(u32 *)DAT_0095b284_abs)
#define DAT_0095b288 (*(u32 *)DAT_0095b288_abs)
#define DAT_0095b290 (*(u32 *)DAT_0095b290_abs)
#define DAT_0095b294 (*(u32 *)DAT_0095b294_abs)
#define DAT_0095b298 (*(u32 *)DAT_0095b298_abs)
#define DAT_0095b2a4 (*(u32 *)DAT_0095b2a4_abs)
#define DAT_0095b434 (*(u32 *)DAT_0095b434_abs)
#define DAT_0095b440 (*(u32 *)DAT_0095b440_abs)
#define DAT_0095b444 (*(u32 *)DAT_0095b444_abs)
#define DAT_0095b448 (*(u32 *)DAT_0095b448_abs)
#define DAT_0095b44c (*(u32 *)DAT_0095b44c_abs)
#define DAT_0095b454 (*(u32 *)DAT_0095b454_abs)
#define DAT_0095b458 (*(u32 *)DAT_0095b458_abs)
#define DAT_0095b45c (*(u32 *)DAT_0095b45c_abs)
#define DAT_0095b460 (*(u32 *)DAT_0095b460_abs)
#define DAT_0095b474 (*(u32 *)DAT_0095b474_abs)
#define DAT_0095b47c (*(u32 *)DAT_0095b47c_abs)
#define DAT_0095b480 (*(u32 *)DAT_0095b480_abs)
#define DAT_0095b484 (*(u32 *)DAT_0095b484_abs)
#define DAT_0095b488 (*(u32 *)DAT_0095b488_abs)
#define DAT_0095b4a0 (*(u32 *)DAT_0095b4a0_abs)
#define DAT_0095b4a8 (*(u32 *)DAT_0095b4a8_abs)
#define DAT_0095b4b4 (*(u32 *)DAT_0095b4b4_abs)
#define DAT_0095b4c0 (*(u32 *)DAT_0095b4c0_abs)
#define DAT_0095b4d0 (*(u32 *)DAT_0095b4d0_abs)
#define DAT_0095b4d4 (*(u32 *)DAT_0095b4d4_abs)
#define DAT_0095b4e0 (*(u32 *)DAT_0095b4e0_abs)
#define DAT_0095b658 (*(u32 *)DAT_0095b658_abs)
#define DAT_0095b65c (*(u32 *)DAT_0095b65c_abs)
#define DAT_0095b660 (*(u32 *)DAT_0095b660_abs)
#define DAT_0095b664 (*(u32 *)DAT_0095b664_abs)
#define DAT_0095b668 (*(u32 *)DAT_0095b668_abs)
#define DAT_0095b66c (*(u32 *)DAT_0095b66c_abs)
#define DAT_0095b670 (*(u32 *)DAT_0095b670_abs)
#define DAT_0095b674 (*(u32 *)DAT_0095b674_abs)
#define DAT_0095b678 (*(u32 *)DAT_0095b678_abs)
#define DAT_0095b67c (*(u32 *)DAT_0095b67c_abs)
#define DAT_0095b680 (*(u32 *)DAT_0095b680_abs)
#define DAT_0095b684 (*(u32 *)DAT_0095b684_abs)
#define DAT_0095b688 (*(u32 *)DAT_0095b688_abs)
#define DAT_0095b68c (*(u32 *)DAT_0095b68c_abs)
#define DAT_0095b690 (*(u32 *)DAT_0095b690_abs)
#define DAT_0095b694 (*(u32 *)DAT_0095b694_abs)
#define DAT_0095b698 (*(u32 *)DAT_0095b698_abs)
#define DAT_0095b69c (*(u32 *)DAT_0095b69c_abs)
#define DAT_0095b6a0 (*(u32 *)DAT_0095b6a0_abs)
#define DAT_0095b6a4 (*(u32 *)DAT_0095b6a4_abs)
#define DAT_0095b6a8 (*(u32 *)DAT_0095b6a8_abs)
#define DAT_0095b6ac (*(u32 *)DAT_0095b6ac_abs)
#define DAT_0095b6b0 (*(u32 *)DAT_0095b6b0_abs)
#define DAT_0095b6b4 (*(u32 *)DAT_0095b6b4_abs)
#define DAT_0095b6b8 (*(u32 *)DAT_0095b6b8_abs)
#define DAT_0095b6bc (*(u32 *)DAT_0095b6bc_abs)
#define DAT_0095b6c4 (*(u32 *)DAT_0095b6c4_abs)
#define DAT_0095b6c8 (*(u32 *)DAT_0095b6c8_abs)
#define DAT_0095b6cc (*(u32 *)DAT_0095b6cc_abs)
#define DAT_0095b6d0 (*(u32 *)DAT_0095b6d0_abs)
#define DAT_0095b6d4 (*(u32 *)DAT_0095b6d4_abs)
#define DAT_0095b6d8 (*(u32 *)DAT_0095b6d8_abs)
#define DAT_0095b6dc (*(u32 *)DAT_0095b6dc_abs)
#define DAT_0095b6e0 (*(u32 *)DAT_0095b6e0_abs)
#define DAT_0095b6e4 (*(u32 *)DAT_0095b6e4_abs)
#define DAT_0095b6e8 (*(u32 *)DAT_0095b6e8_abs)
#define DAT_0095b6ec (*(u32 *)DAT_0095b6ec_abs)
#define DAT_0095b6f0 (*(u32 *)DAT_0095b6f0_abs)
#define DAT_0095b6f4 (*(u32 **)DAT_0095b6f4_abs)
#define DAT_0095b6f8 (*(u32 *)DAT_0095b6f8_abs)
#define DAT_0095b6fc (*(u32 *)DAT_0095b6fc_abs)
#define DAT_0095b700 (*(u32 *)DAT_0095b700_abs)
#define DAT_0095b704 (*(u32 *)DAT_0095b704_abs)
#define DAT_0095b708 (*(u32 *)DAT_0095b708_abs)
#define DAT_0095b70c (*(u32 *)DAT_0095b70c_abs)
#define DAT_0095b710 (*(u32 *)DAT_0095b710_abs)
#define DAT_0095b714 (*(u32 *)DAT_0095b714_abs)
#define DAT_0095b718 (*(u32 *)DAT_0095b718_abs)
#define DAT_0095b71c (*(u32 *)DAT_0095b71c_abs)
#define DAT_0095b720 (*(u32 *)DAT_0095b720_abs)
#define DAT_0095b724 (*(u32 *)DAT_0095b724_abs)
#define DAT_0095b728 (*(u32 *)DAT_0095b728_abs)
#define DAT_0095b070 (*(short **)DAT_0095b070_abs)

#undef FUN_003bd280
/* opt_loop_invariants on: measured nd 725 -> 716, object 1520/1520 -> 1516/1520; opt_lifetimes on alone: nd 725 -> 721, object 1520/1520 -> 1520/1520; stacked: nd 717, object 1516/1520 (worse than loop alone; retained loop only). */
#pragma opt_loop_invariants on
// FUN_003BD280 NONMATCHING


void FUN_003bd280(void)



{

  u32 uVar1;

  int iVar2;

  int *piVar3;

  u8 auStack_4 [4];

  

  uVar1 = FUN_00100d80(PTR_s_event_comuPack_pak_007cd568,1);

  DAT_007ce668 = (u32)uVar1;

  FUN_001023a0(uVar1);

  DAT_0095b070 = (short *)FUN_001021c0(PTR_s_event_comuTable_bin_007cd56c,auStack_4);

  DAT_0095b074 = FUN_001021c0(PTR_s_event_SiteibiEvent_bf_007cd570,auStack_4);

  if (*DAT_0095b070 != 1) {

    FUN_005225a8(0x6a3200);

    DAT_0095b070 = (short *)0x0;

  }

  else {

    piVar3 = (int *)(DAT_0095b070 + 2);

    for (iVar2 = 0; iVar2 < 0x90; iVar2 = iVar2 + 1) {

      if (*piVar3 != 0) {

        *(int *)(&DAT_0095b078 + iVar2 * 4) = (int)DAT_0095b070 + *piVar3;

      }

      else {

        *(u32 *)(&DAT_0095b078 + iVar2 * 4) = 0;

      }

      *(int *)(&DAT_0095b2b4 + iVar2 * 4) = piVar3[1];

      piVar3 = piVar3 + 2;

    }

    FUN_005225a8(0x6a3250,*DAT_0095b070,(char)DAT_0095b070[1]);

    for (iVar2 = 0; iVar2 < 0x1e; iVar2 = iVar2 + 1) {

      *(u32 *)(&DAT_0095b4f0 + iVar2 * 4) = *(u32 *)(&DAT_0095b078 + iVar2 * 4);

    }

    for (iVar2 = 0; iVar2 < 0x1e; iVar2 = iVar2 + 1) {

      *(u32 *)(&DAT_0095b568 + iVar2 * 4) = *(u32 *)(&DAT_0095b0f8 + iVar2 * 4);

    }

    for (iVar2 = 0; iVar2 < 0x1e; iVar2 = iVar2 + 1) {

      *(u32 *)(&DAT_0095b5e0 + iVar2 * 4) = *(u32 *)(&DAT_0095b178 + iVar2 * 4);

    }

    if (DAT_0095b1f8 != 0) {

      DAT_0095b658 = DAT_0095b1f8;

      DAT_0095b65c = DAT_0095b434 / 0x18;

    }

    if (DAT_0095b220 != 0) {

      DAT_0095b660 = DAT_0095b220;

      DAT_0095b664 = DAT_0095b45c >> 2;

    }

    if (DAT_0095b224 != 0) {

      DAT_0095b668 = DAT_0095b224;

      DAT_0095b66c = DAT_0095b460 / 6;

    }

    DAT_0095b670 = DAT_0095b238;

    DAT_0095b674 = DAT_0095b474 / 10;

    DAT_0095b678 = DAT_0095b204;

    DAT_0095b67c = DAT_0095b440 / 3;

    DAT_0095b680 = DAT_0095b208;

    DAT_0095b684 = DAT_0095b444 / 3;

    DAT_0095b688 = DAT_0095b20c;

    DAT_0095b68c = DAT_0095b448 / 5;

    DAT_0095b690 = DAT_0095b210;

    DAT_0095b694 = DAT_0095b44c / 5;

    DAT_0095b698 = DAT_0095b218;

    DAT_0095b69c = DAT_0095b454 / 5;

    DAT_0095b6a0 = DAT_0095b21c;

    DAT_0095b6a4 = DAT_0095b458 / 3;

    DAT_0095b6a8 = DAT_0095b240;

    DAT_0095b6ac = DAT_0095b47c / 0x18;

    DAT_0095b6b0 = DAT_0095b244;

    DAT_0095b6b4 = DAT_0095b480 >> 1;

    DAT_0095b6b8 = DAT_0095b248;

    DAT_0095b6bc = DAT_0095b484 >> 4;

    DAT_0095b6c0 = DAT_0095b2a4;

    DAT_0095b6c4 = DAT_0095b4e0 / 3;

    DAT_0095b6c8 = DAT_0095b24c;

    DAT_0095b6cc = DAT_0095b488 >> 1;

    DAT_0095b6f8 = DAT_0095b254;

    DAT_0095b6fc = DAT_0095b274;

    DAT_0095b700 = DAT_0095b270;

    DAT_0095b704 = DAT_0095b258;

    DAT_0095b708 = DAT_0095b25c;

    DAT_0095b70c = DAT_0095b260;

    DAT_0095b710 = DAT_0095b264;

    DAT_0095b714 = DAT_0095b4a0 / 0x1a;

    DAT_0095b6d8 = DAT_0095b278;

    DAT_0095b6dc = DAT_0095b4b4 / 5;

    DAT_0095b6d0 = DAT_0095b26c;

    DAT_0095b6d4 = DAT_0095b4a8 / 0xc;

    DAT_0095b718 = DAT_0095b268;

    DAT_0095b6e0 = DAT_0095b27c;

    DAT_0095b6e4 = DAT_0095b284;

    DAT_0095b6e8 = DAT_0095b4c0 / 0xc;

    DAT_0095b6ec = DAT_0095b288;

    DAT_0095b6f4 = DAT_0095b28c;

    DAT_0095b6f0 = DAT_0095b290;

    DAT_0095b71c = DAT_0095b294;

    DAT_0095b720 = DAT_0095b4d0 / 6;

    DAT_0095b724 = DAT_0095b298;

    DAT_0095b728 = DAT_0095b4d4 >> 3;

  }

  return;

}
#define FUN_003bd280(...) ((void (*)(...))FUN_003bd280)(__VA_ARGS__)
#pragma opt_loop_invariants reset
#undef DAT_0095b074
#undef DAT_0095b1f8
#undef DAT_0095b208
#undef DAT_0095b20c
#undef DAT_0095b210
#undef DAT_0095b218
#undef DAT_0095b21c
#undef DAT_0095b220
#undef DAT_0095b224
#undef DAT_0095b238
#undef DAT_0095b240
#undef DAT_0095b244
#undef DAT_0095b248
#undef DAT_0095b24c
#undef DAT_0095b254
#undef DAT_0095b258
#undef DAT_0095b25c
#undef DAT_0095b260
#undef DAT_0095b264
#undef DAT_0095b268
#undef DAT_0095b26c
#undef DAT_0095b270
#undef DAT_0095b274
#undef DAT_0095b278
#undef DAT_0095b27c
#undef DAT_0095b284
#undef DAT_0095b288
#undef DAT_0095b290
#undef DAT_0095b294
#undef DAT_0095b298
#undef DAT_0095b2a4
#undef DAT_0095b434
#undef DAT_0095b440
#undef DAT_0095b444
#undef DAT_0095b448
#undef DAT_0095b44c
#undef DAT_0095b454
#undef DAT_0095b458
#undef DAT_0095b45c
#undef DAT_0095b460
#undef DAT_0095b474
#undef DAT_0095b47c
#undef DAT_0095b480
#undef DAT_0095b484
#undef DAT_0095b488
#undef DAT_0095b4a0
#undef DAT_0095b4a8
#undef DAT_0095b4b4
#undef DAT_0095b4c0
#undef DAT_0095b4d0
#undef DAT_0095b4d4
#undef DAT_0095b4e0
#undef DAT_0095b658
#undef DAT_0095b65c
#undef DAT_0095b660
#undef DAT_0095b664
#undef DAT_0095b668
#undef DAT_0095b66c
#undef DAT_0095b670
#undef DAT_0095b674
#undef DAT_0095b678
#undef DAT_0095b67c
#undef DAT_0095b680
#undef DAT_0095b684
#undef DAT_0095b688
#undef DAT_0095b68c
#undef DAT_0095b690
#undef DAT_0095b694
#undef DAT_0095b698
#undef DAT_0095b69c
#undef DAT_0095b6a0
#undef DAT_0095b6a4
#undef DAT_0095b6a8
#undef DAT_0095b6ac
#undef DAT_0095b6b0
#undef DAT_0095b6b4
#undef DAT_0095b6b8
#undef DAT_0095b6bc
#undef DAT_0095b6c4
#undef DAT_0095b6c8
#undef DAT_0095b6cc
#undef DAT_0095b6d0
#undef DAT_0095b6d4
#undef DAT_0095b6d8
#undef DAT_0095b6dc
#undef DAT_0095b6e0
#undef DAT_0095b6e4
#undef DAT_0095b6e8
#undef DAT_0095b6ec
#undef DAT_0095b6f0
#undef DAT_0095b6f4
#undef DAT_0095b6f8
#undef DAT_0095b6fc
#undef DAT_0095b700
#undef DAT_0095b704
#undef DAT_0095b708
#undef DAT_0095b70c
#undef DAT_0095b710
#undef DAT_0095b714
#undef DAT_0095b718
#undef DAT_0095b71c
#undef DAT_0095b720
#undef DAT_0095b724
#undef DAT_0095b728
#undef DAT_0095b070
#undef FUN_003bd870
// FUN_003BD870


short ** FUN_003bd870(void)
{
  return (short **)DAT_0095b070_ptr;
}
#define FUN_003bd870(...) ((short ** (*)(...))FUN_003bd870)(__VA_ARGS__)
#undef FUN_003bd880
// FUN_003BD880


u32 * FUN_003bd880(void)
{
  return (u32 *)DAT_0095b658_ptr;
}
#define FUN_003bd880(...) ((u32 * (*)(...))FUN_003bd880)(__VA_ARGS__)
#undef FUN_003bd890
// FUN_003BD890


u32 * FUN_003bd890(void)
{
  return (u32 *)DAT_0095b660_ptr;
}
#define FUN_003bd890(...) ((u32 * (*)(...))FUN_003bd890)(__VA_ARGS__)
#undef FUN_003bd8a0
// FUN_003BD8A0


u32 * FUN_003bd8a0(void)
{
  return (u32 *)DAT_0095b668_ptr;
}
#define FUN_003bd8a0(...) ((u32 * (*)(...))FUN_003bd8a0)(__VA_ARGS__)
#undef FUN_003bd8b0
#pragma push
/* opt_loop_invariants on: measured off nd 43, object 236/240; on nd 0, object 236/240 (MATCH); retain on. */
#pragma opt_loop_invariants on
// FUN_003BD8B0


u32 FUN_003bd8b0(u32 id, u32 variant, u32 subVariant)
{
  typedef struct SceneLookupEntry {
    u16 id;
    u8 variant;
    u8 subVariant;
    u8 result;
    u8 pad;
  } SceneLookupEntry;
  int index = 0;
  SceneLookupEntry *entries = *(SceneLookupEntry **)DAT_0095b71c_abs;
  int count = *(int *)DAT_0095b720_abs;
  u32 wildcard = 0xff;

  for (; index < count; index++) {
    SceneLookupEntry *entry = &entries[index];

    if (entry->subVariant == wildcard) {
      if (id == entry->id && variant == entry->variant) {
        return entry->result;
      }
    } else if (id == entry->id && variant == entry->variant
               && subVariant == entry->subVariant) {
      return entry->result;
    }
  }

  if ((s32)id >= 0 && (s32)id < 500) {
    return 0;
  }
  if ((s32)id >= 990 && (s32)id < 1000) {
    return 0;
  }
  return (u32)-1;
}
#pragma pop
#define FUN_003bd8b0(...) ((u32 (*)(...))FUN_003bd8b0)(__VA_ARGS__)
#undef FUN_003bd9a0
// FUN_003BD9A0


u16 FUN_003bd9a0(u32 param_1,u32 param_2)
{
  int iVar1;
  u32 base;
  int count;
  int iVar2;

  iVar2 = 0;
  base = *(u32 *)DAT_0095b724_abs;
  count = *(int *)DAT_0095b728_abs;
  goto LAB_003bd9f0;
LAB_003bd9b0:
  iVar1 = iVar2 * 8;
  if (param_1 != *(u16 *)(base + iVar1)) {
    goto LAB_003bda30;
  }
  if (param_2 != *(u8 *)(base + iVar1 + 2)) {
    goto LAB_003bda30;
  }
  if (FUN_003951d0_i32(0xa88) == 1) {
    return *(u16 *)(iVar1 + (int)*(u32 *)DAT_0095b724_abs + 4);
  }
  return *(u16 *)(iVar1 + (int)*(u32 *)DAT_0095b724_abs + 6);
LAB_003bda30:
  iVar2 = iVar2 + 1;
LAB_003bd9f0:
  if (iVar2 < count) {
    goto LAB_003bd9b0;
  }
  return 0;
}
#define FUN_003bd9a0(...) ((u16 (*)(...))FUN_003bd9a0)(__VA_ARGS__)
#undef FUN_003bda60
// FUN_003BDA60



u32 FUN_003bda60(u32 param_1,u32 param_2,u32 param_3,u32 param_4)



{

  int iVar1;

  int lVar2;

  u8 *pbVar3;

  int iVar4;
  int off;
  u32 uv;

  

  iVar1 = *(int *)DAT_0095b674_abs;

  for (iVar4 = 0; iVar4 < iVar1; iVar4 = iVar4 + 1) {

    pbVar3 = (u8 *)*(int *)DAT_0095b670_abs;

    off = iVar4 * 10;

    pbVar3 = pbVar3 + off;

    if ((((param_1 == *pbVar3) && (param_2 == pbVar3[1])) && (param_3 == *(u16 *)(pbVar3 + 2)))

       && (param_4 == pbVar3[4])) {

      uv = *(u16 *)(pbVar3 + 8);

      if (uv == 0) goto ret1;

      lVar2 = FUN_003951d0(uv);

      if (lVar2 == 1) goto next;

      return (u32)*(u16 *)(off + *(int *)DAT_0095b670_abs + 6);

ret1:
      return (u32)*(u16 *)(pbVar3 + 6);

next:;

    }

  }

  return 0xffffffff;

}
#define FUN_003bda60(...) ((u32 (*)(...))FUN_003bda60)(__VA_ARGS__)
#undef FUN_003bdb80
// FUN_003BDB80


float FUN_003bdb80(void)



{

  return **(float **)0x0095b6f4;

}
#define FUN_003bdb80(...) ((float (*)(...))FUN_003bdb80)(__VA_ARGS__)
#undef FUN_003bdba0
// FUN_003BDBA0


u32 FUN_003bdba0(void)



{

  return *(u32 *)0x0095b6f0;

}
#define FUN_003bdba0(...) ((u32 (*)(...))FUN_003bdba0)(__VA_ARGS__)
#undef FUN_003bdbb0
// FUN_003BDBB0


u16 FUN_003bdbb0(void)



{

  return **(u16 **)0x0095b29c;

}
#define FUN_003bdbb0(...) ((u16 (*)(...))FUN_003bdbb0)(__VA_ARGS__)

// FUN_003BDBD0 NONMATCHING


void FUN_003bdbd0(int param_1)
{
  extern u32 FUN_0016e100(s16 param_1);
  extern s8 FUN_0016dba0(s16 param_1);
  u32 bVar2;
  s8 cVar3;
  s16 sVar1;
  u32 lVar4;
  int iVar5;

  lVar4 = FUN_0016dce0((s16)param_1);
  if ((lVar4 != 0) && (lVar4 = FUN_00172a50((s16)param_1), lVar4 != 0)) {
    for (iVar5 = 0; iVar5 < 6; iVar5 = iVar5 + 1) {
      if (param_1 != iVar5 + 6) {
        lVar4 = FUN_0016dce0((s16)(iVar5 + 6));
        if (lVar4 == 0) {
          FUN_0019d3f0("comuFunction.c",0x1b6);
        }

        if (FUN_0016e100((s16)(iVar5 + 6)) == 0) {
          bVar2 = 0;
        }
        else if (FUN_00172a50((s16)(iVar5 + 6)) == 0) {
          bVar2 = 0;
        }
        else {
          cVar3 = FUN_0016dba0((s16)(iVar5 + 6));
          if ((long)cVar3 >= (long)(u32)*(u8 *)(*(u32 *)DAT_0095b2a8_abs + iVar5)) {
            bVar2 = 1;
          }
          else {
            bVar2 = 0;
          }
        }

        if (bVar2) {
          sVar1 = *(volatile /* Removing this qualifier worsens FUN_003bdbd0 (NONMATCHING nd41 -> NONMATCHING nd49, size 360 -> 360) - measured W170. */ s16 *)(*(u32 *)DAT_0095b2a0_abs);
          FUN_00171960(iVar5 + 6,(s32)sVar1);
        }
      }
    }
  }
}
#define FUN_003bdbd0(...) ((void (*)(...))FUN_003bdbd0)(__VA_ARGS__)
#undef FUN_003bdd40

// FUN_003BDD40

u32 *FUN_003bdd40(void)
{
  return (u32 *)DAT_0095b678_abs;
}
#define FUN_003bdd40(...) ((u32 * (*)(...))FUN_003bdd40)(__VA_ARGS__)
#undef FUN_003bdd50

// FUN_003BDD50

u32 *FUN_003bdd50(void)
{
  return (u32 *)DAT_0095b6a8_abs;
}
#define FUN_003bdd50(...) ((u32 * (*)(...))FUN_003bdd50)(__VA_ARGS__)
#undef FUN_003bdd60

// FUN_003BDD60


void FUN_003bdd60(u32 param_1,u32 param_2)



{

  FUN_0035bb40(param_1,*(u32 *)0x0095b074,param_2);

  return;

}
#define FUN_003bdd60(...) ((void (*)(...))FUN_003bdd60)(__VA_ARGS__)
#undef FUN_003bdd90

// FUN_003BDD90


u32 FUN_003bdd90(int param_1)



{

  u32 uVar1;
  int iVar2;
  u32 *puVar1;
  puVar1 = (u32 *)DAT_0095b070_raw_abs;

  

  if (0x1e < param_1) {

    uVar1 = 0;

  }

  else {

    uVar1 = puVar1[param_1 + 0x15c];

  }

  return uVar1;

}
#define FUN_003bdd90(...) ((u32 (*)(...))FUN_003bdd90)(__VA_ARGS__)
#undef FUN_003bddd0

// FUN_003BDDD0

u32 FUN_003bddd0(void)
{
  return *(u32 *)0x0095b280;
}
#define FUN_003bddd0(...) ((u32 (*)(...))FUN_003bddd0)(__VA_ARGS__)
#undef FUN_003bdde0

// FUN_003BDDE0


void FUN_003bdde0(void)



{
  extern u32 FUN_0016e100(s16 param_1);
  /* This caller uses the s32 ABI; the settled callers above intentionally materialize long arguments. */
  extern s32 FUN_001717c0(s32 param_1);
  extern s32 FUN_00172160(s32 param_1);
  extern s8 FUN_0016dba0(s16 param_1);
  extern void FUN_00171960(s32 param_1,s32 param_2);
  extern s16 FUN_00171ac0(s32 param_1);
  extern void FUN_00171c40(s32 param_1,s32 param_2);

  char cVar1;

  short sVar2;

  u32 uVar3;

  int iVar4;

  

  for (iVar4 = 0; iVar4 < 0x1e; iVar4 = iVar4 + 1) {


    if ((((uVar3 = FUN_0016e100((short)iVar4), uVar3 != 0) &&

          (uVar3 = FUN_001717c0(iVar4), uVar3 != 1)) &&

         (uVar3 = FUN_00172160(iVar4), uVar3 != 1)) &&

        (cVar1 = FUN_0016dba0((short)iVar4), cVar1 != '\n')) {

      FUN_00171960(iVar4,1);

      sVar2 = FUN_00171ac0(iVar4);

      if (sVar2 < 1) {

        FUN_00171c40(iVar4,1);

      }

    }

  }

  return;

}
#define FUN_003bdde0(...) ((void (*)(...))FUN_003bdde0)(__VA_ARGS__)
#undef FUN_003bded0

// FUN_003BDED0


u32 FUN_003bded0(u64 param_1)



{

  extern s8 FUN_0016dba0(s16 param_1);
  char cVar1;
  s32 lVar3;

  

  cVar1 = FUN_0016dba0((short)param_1);
  if (cVar1 == '\n') {
    return 5;
  }
  lVar3 = FUN_00172160(param_1);
  if (lVar3 == 1) {
    return 4;
  }
  lVar3 = FUN_001717c0(param_1);
  if (lVar3 == 1) {
    return 3;
  }
  lVar3 = FUN_00172660(param_1);
  if (lVar3 == 1) {
    lVar3 = FUN_003be1c0_typed(param_1,cVar1 + 1);
    if (lVar3 == 1) {
      return 2;
    }
    return 1;
  }
  return 0;

}
#define FUN_003bded0(...) ((u32 (*)(...))FUN_003bded0)(__VA_ARGS__)
#undef FUN_003bdfc0

// FUN_003BDFC0


u8 FUN_003bdfc0(int param_1)



{

  u32 lVar1;

  

  lVar1 = FUN_0016dce0((short)param_1);

  if (lVar1 == 0) {

    FUN_0019d3f0("comuFunction.c",0x291);

  }

  return *(u8 *)(*(u32 *)0x0095b700 + param_1);

}
#define FUN_003bdfc0(...) ((u8 (*)(...))FUN_003bdfc0)(__VA_ARGS__)
#undef FUN_003be020

// FUN_003BE020 NONMATCHING

u32 FUN_003be020(int param_1,int param_2,u32 param_3)



{

  u8 bVar1;

  u8 bVar2;

  s16 uVar3;

  s16 uVar4;

  int iVar5;

  int iVar6;

  char cVar7;

  u8 *pbVar8;

  s16 *puVar9;

  int lVar10;

  u32 uVar11;

  int iVar12;

  

  iVar6 = DAT_0095b6cc;

  iVar5 = DAT_0095b6c8;

  iVar12 = 0;

  do {

    if (iVar6 <= iVar12) {

      return 0;

    }

    pbVar8 = (u8 *)(iVar5 + iVar12 * 2);

    bVar1 = *pbVar8;

    uVar11 = (u32)bVar1;

    if (param_3 == uVar11) {

      bVar2 = pbVar8[1];

      lVar10 = FUN_00172a50(bVar1);

      if (lVar10 != 0) {

        lVar10 = FUN_0016e100(bVar1);

        if (lVar10 == 1) {

          cVar7 = FUN_0016dba0(bVar1);

          lVar10 = (s32)(s8)cVar7;

        }

        else {

          lVar10 = 0;

        }

        if ((s32)bVar2 <= lVar10 &&

           (lVar10 < 1 ||

            (FUN_001717c0(uVar11) != 1 &&

             FUN_00172160(uVar11) != 1))) {

          puVar9 = (s16 *)(*(int *)DAT_0095b70c_abs + (bVar1 - 6) * 6);

          uVar3 = puVar9[1];

          uVar4 = puVar9[2];

          *(u16 *)(param_2 + 0x2a) = *puVar9;

          *(u16 *)(param_2 + 0x2c) = uVar3;

          *(u16 *)(param_2 + 0x2e) = uVar4;

          *(u8 *)(param_2 + 1) = bVar1;

          return 1;

        }

      }

    }

    iVar12 = iVar12 + 1;

  } while( 1 );

}
#define FUN_003be020(...) ((u32 (*)(...))FUN_003be020)(__VA_ARGS__)
#undef FUN_003be1a0

// FUN_003BE1A0


u8 FUN_003be1a0(int param_1)



{

  return *(int *)(param_1 + 4) == 3;

}
#define FUN_003be1a0(...) ((u8 (*)(...))FUN_003be1a0)(__VA_ARGS__)
#undef FUN_003be1c0

// FUN_003BE1C0


u32 FUN_003be1c0(u32 param_1,s32 param_2)



{
  int iVar1;
  u32 lVar2;
  int iVar2;
  int iVar3;
  u8 *pbBase;

  iVar1 = *(u32 *)DAT_0095b714_abs;


  if (param_2 < 2) {
    return 0;
  }

  iVar3 = 0;
  iVar2 = (int)param_2 * 2;
  for (; iVar3 < iVar1; iVar3 = iVar3 + 1) {
    pbBase = DAT_0095b710_ptr_abs[0];
    if (((param_1 == pbBase[iVar3 * 0x1a]) &&
        (*(u16 *)(iVar2 + (int)pbBase + iVar3 * 0x1a + 4) != 0)) &&
       (lVar2 = FUN_0016f190_comu(*(u16 *)(iVar2 + (int)pbBase +
                                            iVar3 * 0x1a + 4)),
        lVar2 == 0)) {
      return 1;
    }
  }

  return 0;
}
#define FUN_003be1c0(...) ((u32 (*)(...))FUN_003be1c0)(__VA_ARGS__)
#undef FUN_003be2a0

/* opt_loop_invariants on: measured nd 928 -> 876, object 1588/1600 -> 1588/1600; opt_lifetimes on alone: nd 928 -> 926, object 1588/1600 -> 1584/1600; stacked: nd 874, object 1584/1600 (retained). */
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
/* W415 probes: two-argument aliases regressed nd874 -> 999 (object 1576/1600); retail passes the guarded byte as a third argument, retained below (nd888, object 1584/1600). */
// FUN_003BE2A0 NONMATCHING
u32 FUN_003be2a0(int param_1,int *param_2,u32 param_3,u32 param_4,u8 *param_5)




{

  u16 uVar1;

  u16 uVar2;

  u16 uVar3;

  char cVar4;

  u16 *puVar5;

  s32 lVar6;

  u8 *pbVar7;

  u16 uVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  int iVar12;

  u32 uVar13;

  u8 *puVar14;

  u16 auStack_44 [32];

  

  puVar14 = param_5;
  uVar13 = 0;

  lVar6 = FUN_0016dce0((s16)param_3);

  if (lVar6 == 0) {

    FUN_0019d3f0("comuFunction.c",0x32a);

  }

  FUN_00521408(puVar14,0,0x38);


  *puVar14 = (char)param_3;

  puVar14[2] = (char)param_4;

  cVar4 = FUN_0016dba0((s16)param_3);


  if (cVar4 >= '\x01') {

    if (param_4 < 8) {

      iVar9 = (int)param_3;

      iVar11 = (int)cVar4;

      switch(param_4) {

      case 0:

        if (*(int *)((u8 *)DAT_0095b070_abs + iVar9 * 4 + 0x480) == 0) {

          FUN_0019d3f0("comuFunction.c",0x339);

        }

        cVar4 = FUN_0016dd20((s16)param_3);

        lVar6 = (s32)cVar4;

        if (9 < lVar6) {

          lVar6 = 9;

        }

        iVar12 = *(int *)((u8 *)DAT_0095b070_abs + iVar9 * 4 + 0x480) + ((int)lVar6 + (iVar11 + -1) * 10) * 0xe;

        uVar13 = 2;

        uVar8 = *(u16 *)(iVar12 + 10);

        uVar2 = *(u16 *)(iVar12 + 0xc);

        *(u16 *)(puVar14 + 0x1e) = *(u16 *)(iVar12 + 8);

        *(u16 *)(puVar14 + 0x20) = uVar8;

        *(u16 *)(puVar14 + 0x22) = uVar2;

        uVar8 = *(u16 *)(iVar12 + 0x10);

        uVar2 = *(u16 *)(iVar12 + 0x12);

        *(u16 *)(puVar14 + 0x24) = *(u16 *)(iVar12 + 0xe);

        *(u16 *)(puVar14 + 0x26) = uVar8;

        *(u16 *)(puVar14 + 0x28) = uVar2;

        if ((*(char *)(iVar12 + 0x14) != '\0') &&

           (lVar6 = FUN_003be020_typed(param_3,param_5,(u32)*(u8 *)(iVar12 + 0x14)), lVar6 == 1)) {

          uVar13 = 3;

        }

        break;

      case 1:

        if (*(int *)((u8 *)DAT_0095b070_abs + iVar9 * 4 + 0x4f8) == 0) {

          FUN_0019d3f0("comuFunction.c",0x351);

        }

        iVar12 = *(int *)((u8 *)DAT_0095b070_abs + iVar9 * 4 + 0x4f8) + (iVar11 + -1) * 0x18;

        uVar2 = *(u16 *)(iVar12 + 10);

        uVar1 = *(u16 *)(iVar12 + 0xc);

        *(u16 *)(puVar14 + 0x1e) = *(u16 *)(iVar12 + 8);

        *(u16 *)(puVar14 + 0x20) = uVar2;

        *(u16 *)(puVar14 + 0x22) = uVar1;

        uVar2 = *(u16 *)(iVar12 + 0x10);

        uVar1 = *(u16 *)(iVar12 + 0x12);

        *(u16 *)(puVar14 + 0x24) = *(u16 *)(iVar12 + 0xe);

        *(u16 *)(puVar14 + 0x26) = uVar2;

        *(u16 *)(puVar14 + 0x28) = uVar1;

        uVar2 = *(u16 *)(iVar12 + 0x16);

        uVar1 = *(u16 *)(iVar12 + 0x18);

        *(u16 *)(puVar14 + 0x2a) = *(u16 *)(iVar12 + 0x14);

        *(u16 *)(puVar14 + 0x2c) = uVar2;

        *(u16 *)(puVar14 + 0x2e) = uVar1;

        uVar2 = *(u16 *)(iVar12 + 0x1c);

        uVar1 = *(u16 *)(iVar12 + 0x1e);

        *(u16 *)(puVar14 + 0x30) = *(u16 *)(iVar12 + 0x1a);

        *(u16 *)(puVar14 + 0x32) = uVar2;

        *(u16 *)(puVar14 + 0x34) = uVar1;

        uVar13 = 3;

        if (param_1 == 1) {

          FUN_0016e410(param_3,cVar4 + '\x01');

        }

        break;

      case 2:

        for (iVar12 = 0; iVar12 < DAT_0095b714; iVar12 = iVar12 + 1) {
          pbVar7 = (u8 *)DAT_0095b710_ptr_abs + iVar12 * 0x1a;


          if (param_3 == *pbVar7) {

            pbVar7 = pbVar7 + 2;

            goto LAB_003be5a0;

          }

        }

        pbVar7 = (u8 *)0x0;

LAB_003be5a0:

        if (pbVar7 == (u8 *)0x0) {

          FUN_0019d3f0("comuFunction.c",0x365);

        }

        uVar8 = *(u16 *)(pbVar7 + 2);

        uVar2 = *(u16 *)(pbVar7 + 4);

        *(u16 *)(puVar14 + 0x1e) = *(u16 *)pbVar7;

        *(u16 *)(puVar14 + 0x20) = uVar8;

        *(u16 *)(puVar14 + 0x22) = uVar2;

        uVar13 = 1;

        break;

      case 3:

        puVar5 = (u16 *)(DAT_0095b6f8 + iVar9 * 6);

        uVar8 = puVar5[1];

        uVar2 = puVar5[2];

        *(u16 *)(puVar14 + 0x1e) = *puVar5;

        *(u16 *)(puVar14 + 0x20) = uVar8;

        *(u16 *)(puVar14 + 0x22) = uVar2;

        puVar14[0x23] = 0;

        uVar13 = 1;

        break;

      case 4:

        puVar5 = (u16 *)(DAT_0095b704 + iVar9 * 6);

        uVar8 = puVar5[1];

        uVar2 = puVar5[2];

        *(u16 *)(puVar14 + 0x1e) = *puVar5;

        *(u16 *)(puVar14 + 0x20) = uVar8;

        *(u16 *)(puVar14 + 0x22) = uVar2;

        uVar13 = 1;

        break;

      case 5:

        if (*(int *)((u8 *)DAT_0095b070_abs + iVar9 * 4 + 0x480) == 0) {

          FUN_0019d3f0("comuFunction.c",0x37d);

        }

        iVar12 = *(int *)((u8 *)DAT_0095b070_abs + iVar9 * 4 + 0x480);

        uVar8 = *(u16 *)(iVar12 + 0x4f6);

        uVar2 = *(u16 *)(iVar12 + 0x4f8);

        *(u16 *)(puVar14 + 0x1e) = *(u16 *)(iVar12 + 0x4f4);

        *(u16 *)(puVar14 + 0x20) = uVar8;

        *(u16 *)(puVar14 + 0x22) = uVar2;

        uVar13 = 1;

        break;

      case 6:
        lVar6 = FUN_00172a50((s16)param_3);

        if (lVar6 == 0) {

          FUN_0019d3f0("comuFunction.c",0x388);

        }

        iVar12 = FUN_003c2570(param_3);

        puVar5 = (u16 *)(DAT_0095b708 + (iVar12 + (iVar9 + -6) * 4) * 6);

        uVar8 = puVar5[1];

        uVar2 = puVar5[2];

        *(u16 *)(puVar14 + 0x1e) = *puVar5;

        *(u16 *)(puVar14 + 0x20) = uVar8;

        *(u16 *)(puVar14 + 0x22) = uVar2;

        uVar13 = 1;

        break;

      case 7:
        puVar5 = (u16 *)DAT_0095b6a8_abs;
        iVar12 = *(u32 *)puVar5;

        iVar9 = 0;

        for (iVar10 = 0; iVar10 < *((u32 *)puVar5 + 1); iVar10 = iVar10 + 1) {

          if (param_3 == *(u8 *)(iVar12 + iVar10 * 0x18)) {

            if (0x1f < iVar9) break;

            auStack_44[iVar9] = (u16)iVar10;

            iVar9 = iVar9 + 1;

          }

        }

        if (iVar9 == 0) {

          FUN_0019d3f0("comuFunction.c",0x3b3);

          return 0;

        }

        if (param_1 != 1) {

          if ((cVar4 < '\x02') || ('\t' < cVar4)) {

            FUN_0019d3f0("comuFunction.c",0x3ca);

          }

          uVar3 = auStack_44[iVar11 - 2];

        }

        else {

          uVar3 = auStack_44[*param_2];

        }

        iVar12 = iVar12 + (u32)uVar3 * 0x18;

        uVar8 = *(u16 *)(iVar12 + 4);

        uVar2 = *(u16 *)(iVar12 + 6);

        *(u16 *)(puVar14 + 0x1e) = *(u16 *)(iVar12 + 2);

        *(u16 *)(puVar14 + 0x20) = uVar8;

        *(u16 *)(puVar14 + 0x22) = uVar2;

        uVar8 = *(u16 *)(iVar12 + 10);

        uVar2 = *(u16 *)(iVar12 + 0xc);

        *(u16 *)(puVar14 + 0x24) = *(u16 *)(iVar12 + 8);

        *(u16 *)(puVar14 + 0x26) = uVar8;

        *(u16 *)(puVar14 + 0x28) = uVar2;

        for (iVar11 = 0; iVar11 < 5; iVar11 = iVar11 + 1) {

          *(u16 *)(puVar14 + iVar11 * 2 + 0x14) = *(u16 *)(iVar12 + iVar11 * 2 + 0xe);

        }

        uVar13 = 2;

      }

    }

    *(u32 *)(puVar14 + 4) = uVar13;

    uVar13 = 1;

  }

  else {

    uVar13 = 0;

  }

  return uVar13;

}
#define FUN_003be2a0(...) ((u32 (*)(...))FUN_003be2a0)(__VA_ARGS__)
#pragma opt_lifetimes reset
#pragma opt_loop_invariants reset
#undef FUN_003be8e0

// FUN_003BE8E0
u32 FUN_003be8e0(long param_1,u64 param_2)
{
  s32 var_7;
  s8 cVar1;
  s32 lVar2;

  if ((param_1 >= 0x1e) || (param_1 < 0)) {
    K_Assert(D_006A3280,0x3e8);
  }

  cVar1 = datGetSocialLinkLevel((s16)param_1);
  if (cVar1 == '\n') {
    var_7 = 5;
  }
  else {
    lVar2 = FUN_00172160(param_1);
    if (lVar2 == 1) {
      var_7 = 4;
    }
    else {
      lVar2 = FUN_001717c0(param_1);
      if (lVar2 == 1) {
        var_7 = 3;
      }
      else {
        lVar2 = FUN_00172660(param_1);
        if (lVar2 == 1) {
          lVar2 = FUN_003be1c0_typed(param_1,cVar1 + 1);
          if (lVar2 == 1) {
            var_7 = 2;
          }
          else {
            var_7 = 1;
          }
        }
        else {
          var_7 = 0;
        }
      }
    }
  }

  FUN_003be2a0_typed(0,0,param_1,var_7,param_2);
  return 1;
}
#define FUN_003be8e0(...) ((u32 (*)(...))FUN_003be8e0)(__VA_ARGS__)
#undef FUN_003bea20

// FUN_003BEA20


u8 FUN_003bea20(int param_1,int param_2)



{
  u8 *pbVar1;
  int iVar2;
  int iVar3;

  if (!(param_1 < 4)) {

    FUN_0019d3f0("comuFunction.c",0x3f9);

  }

  iVar2 = (int)param_1 * 6;
  iVar3 = param_2;
  param_2 = iVar2;
  param_2 += iVar3;
  pbVar1 = (u8 *)(param_2 + 0x1e);
  if (!(*(u8 *)(param_2 + 0x1e) < 0x2a)) {

    FUN_0019d3f0("comuFunction.c",0x3fb);

  }

  return *pbVar1;

}
#define FUN_003bea20(...) ((u8 (*)(...))FUN_003bea20)(__VA_ARGS__)
#undef FUN_003beab0

// FUN_003BEAB0


u32 FUN_003beab0(u32 param_1,u32 param_2,int *param_3)



{
  u8 *pbVar1;
  u8 *pbBase;
  int iVar2;

  iVar2 = 0;
  pbBase = *(u8 **)(0x0095b718);
  goto check;
loop:
  pbVar1 = pbBase + iVar2 * 0x20;
  if (param_1 != *pbVar1) goto next;
  if (param_2 != pbVar1[1]) goto next;
  *param_3 = iVar2;
  return 1;
next:
  iVar2 = iVar2 + 1;
check:
  if (iVar2 < 0x40) goto loop;
  return 0;
}

#define FUN_003beab0(...) ((u32 (*)(...))FUN_003beab0)(__VA_ARGS__)
#undef FUN_003beb10

// FUN_003BEB10


int FUN_003beb10(int param_1)



{
  u32 base;

  if ((param_1 < 0) || !(param_1 < 0x40)) {

    FUN_0019d3f0("comuFunction.c",0x416);

  }

  base = *(u32 *)0x0095b718;
  return base + param_1 * 0x20;

}
#define FUN_003beb10(...) ((int (*)(...))FUN_003beb10)(__VA_ARGS__)
#undef FUN_003beb70

// FUN_003BEB70


void FUN_003beb70(int param_1)



{

  u32 lVar1;

  

  lVar1 = FUN_0016dce0((short)param_1);

  if (lVar1 == 0) {

    FUN_0019d3f0("comuFunction.c",0x422);

  }

  FUN_0016f1f0(param_1 + 0x9d0,1);

  return;

}
#define FUN_003beb70(...) ((void (*)(...))FUN_003beb70)(__VA_ARGS__)
#undef FUN_003bebd0

// FUN_003BEBD0


u8 FUN_003bebd0(int param_1)



{

  u32 lVar1;

  

  lVar1 = FUN_0016dce0((short)param_1);

  if (lVar1 == 0) {

    FUN_0019d3f0("comuFunction.c",0x42b);

  }

  lVar1 = FUN_0016f190_comu(param_1 + 0x9d0);

  if (lVar1 == 1) {

    return 1;

  }

  return 0;

}
#define FUN_003bebd0(...) ((u8 (*)(...))FUN_003bebd0)(__VA_ARGS__)
#undef FUN_003bec50

// FUN_003BEC50


void FUN_003bec50(void)



{

  int iVar1;

  

  for (iVar1 = 0; iVar1 < 0x1e; iVar1 = iVar1 + 1) {

    FUN_0016f1f0(iVar1 + 0x9d0,0);

  }

  return;

}
#define FUN_003bec50(...) ((void (*)(...))FUN_003bec50)(__VA_ARGS__)
#undef FUN_003beca0

/* opt_common_subs off: measured nd 279 -> 238, object 472/480 -> 472/480. */
#pragma opt_common_subs off
// FUN_003BECA0 NONMATCHING


int FUN_003beca0(int param_1)



{

  u8 bVar1;

  u8 bVar2;

  u8 bVar3;

  int iVar4;

  int iVar5;

  char cVar6;

  u32 uVar7;

  u32 uVar8;

  int lVar9;

  u8 *pbVar10;

  int iVar11;

  int iVar12;

  u32 uStack_8;

  u32 uStack_4;

  

  iVar5 = DAT_0095b6dc;

  iVar4 = DAT_0095b6d8;

  iVar11 = 0;

  uStack_4 = 0;

  uStack_8 = 0;

  uVar7 = FUN_0017d920();

  uVar8 = FUN_0017da40();

  lVar9 = FUN_003c2b40(&uStack_4,&uStack_8);

  if (lVar9 != 0) {

    for (iVar12 = 0; iVar12 < iVar5; iVar12 = iVar12 + 1) {

      pbVar10 = (u8 *)(iVar4 + iVar12 * 5);

      if ((uVar7 == *pbVar10) && (uVar8 == pbVar10[1])) {

        bVar1 = pbVar10[2];

        bVar2 = pbVar10[3];

        bVar3 = pbVar10[4];

        cVar6 = FUN_0016dba0(bVar1);

        lVar9 = (long)cVar6;

        if ((((long)(u32)bVar2 <= lVar9) && (lVar9 <= (long)(u32)bVar3)) &&

           ((lVar9 != 9 || (lVar9 = FUN_00172660(bVar1), lVar9 != 1)))) {

          lVar9 = FUN_0016dce0(bVar1);

          if (lVar9 == 0) {

            FUN_0019d3f0("comuFunction.c",0x42b);

          }

          lVar9 = FUN_0016f190(bVar1 + 0x9d0);

          if ((lVar9 != 1) && (lVar9 = FUN_003c2c50(bVar1), lVar9 != 0)) {

            *(u32 *)(param_1 + iVar11 * 4) = (u32)bVar1;

            iVar11 = iVar11 + 1;

          }

        }

      }

    }

  }

  else {

    iVar11 = 0;

  }

  return iVar11;

}
#define FUN_003beca0(...) ((int (*)(...))FUN_003beca0)(__VA_ARGS__)
#pragma opt_common_subs reset
#undef FUN_003bee80

/* opt_loop_invariants on: measured nd 441 -> 420, object 664/688 -> 664/688; opt_lifetimes on alone: nd 441 -> 438, object 664/688 -> 668/688; stacked: nd 419, object 664/688 (retained). */
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
// FUN_003BEE80 NONMATCHING


u8 * FUN_003bee80(u16 param_1,int *param_2)



{

  u16 uVar1;

  u16 uVar2;

  char cVar3;

  char cVar4;

  int iVar5;

  u64 uVar6;

  u32 uVar7;

  u32 uVar8;

  u16 *puVar9;

  int iVar10;

  u32 uVar11;

  int iVar12;

  int iVar13;

  

  cVar3 = FUN_0016df30(param_1);

  iVar13 = 0;

  uVar6 = FUN_0016c7e0(1);

  uVar7 = FUN_0016d280(uVar6);

  iVar12 = -1;

  uVar11 = 9999;

  for (iVar5 = 1; iVar5 < 0x100; iVar5 = iVar5 + 1) {

    puVar9 = (u16 *)(DAT_007ce420 + iVar5 * 0xe);

    if (((((long)cVar3 == (u32)(u8)puVar9[1]) && (uVar1 = *puVar9, (uVar1 & 0x10) == 0)) &&

        ((uVar1 & 8) == 0)) &&

       (((uVar1 & 0x40) == 0 || (cVar4 = FUN_0016dba0(param_1), cVar4 == '\n')))) {

      uVar8 = (u32)*(u8 *)(DAT_007ce420 + iVar5 * 0xe + 3);

      if ((uVar7 & 0xff) < uVar8) {

        if (uVar8 < uVar11) {

          uVar11 = uVar8;

          iVar12 = iVar5;

        }

      }

      else {

        if (!(iVar13 < 0xf)) {

          FUN_0019d3f0("comuFunction.c",0x4b2);

        }

        *(short *)(&DAT_0095b730 + iVar13 * 2) = (short)iVar5;

        iVar13 = iVar13 + 1;

      }

    }

  }

  if (iVar12 != -1) {

    if (!(iVar13 < 0xf)) {

      FUN_0019d3f0("comuFunction.c",0x4c4);

    }

    *(short *)(&DAT_0095b730 + iVar13 * 2) = (short)iVar12;

    iVar13 = iVar13 + 1;

  }

  *param_2 = iVar13;

  iVar12 = DAT_007ce420;

  for (iVar5 = 0; iVar5 < iVar13 + -1; iVar5 = iVar5 + 1) {

    iVar10 = iVar5;

    while (iVar10 = iVar10 + 1, iVar10 < iVar13) {

      uVar1 = *(u16 *)(&DAT_0095b730 + iVar5 * 2);

      uVar2 = *(u16 *)(&DAT_0095b730 + iVar10 * 2);

      if (*(u8 *)(iVar12 + (u32)uVar2 * 0xe + 3) < *(u8 *)(iVar12 + (u32)uVar1 * 0xe + 3)) {

        *(u16 *)(&DAT_0095b730 + iVar5 * 2) = uVar2;

        *(u16 *)(&DAT_0095b730 + iVar10 * 2) = uVar1;

      }

    }

  }

  if (iVar13 == 0) {

    FUN_0019d3f0("comuFunction.c",0x4dd);

  }

  return (u8*)&DAT_0095b730;

}
#define FUN_003bee80(...) ((u8 * (*)(...))FUN_003bee80)(__VA_ARGS__)
#pragma opt_lifetimes reset
#pragma opt_loop_invariants reset
#undef FUN_003bf130

// FUN_003BF130


u32 FUN_003bf130(void)



{

  u32 uVar1;

  u32 lVar2;

  

  lVar2 = FUN_0027c2b0();

  if ((lVar2 == 0) && (lVar2 = FUN_0027c330(), lVar2 == -1)) {

    uVar1 = 1;

  }

  else {

    uVar1 = 0;

  }

  return uVar1;

}
#define FUN_003bf130(...) ((u32 (*)(...))FUN_003bf130)(__VA_ARGS__)
#undef FUN_003bf180

// FUN_003BF180


void FUN_003bf180(u32 param_1,u32 param_2,u32 param_3)



{
  struct {
    u8 data[12];
    u32 param_1;
    u32 param_2;
    u32 param_3;
    u32 pad;
  } packet;

  FUN_00521408(packet.data,0,0x1c);

  packet.param_1 = param_1;
  packet.param_2 = param_2;
  packet.param_3 = param_3;

  FUN_0027c080(3,packet.data,0x1c,0);
  return;
}
#define FUN_003bf180(...) ((void (*)(...))FUN_003bf180)(__VA_ARGS__)
#undef FUN_003bf200

// FUN_003BF200


u32 FUN_003bf200(long param_1,long param_2,long param_3,long param_4)



{

  u32 bVar1;

  u32 lVar2;

  

  if (param_3 == 0xff) {

    lVar2 = FUN_0017e050(param_4,param_1,param_2);

    bVar1 = lVar2 == 1;

  }

  else if ((param_1 == param_3) && (param_2 == param_4)) {

    bVar1 = 1;

  }

  else {

    bVar1 = 0;

  }

  return bVar1;

}
#define FUN_003bf200(...) ((u32 (*)(...))FUN_003bf200)(__VA_ARGS__)
#undef FUN_003bf270

// FUN_003BF270


u32

FUN_003bf270(long param_1,long param_2,long param_3,long param_4,long param_5,long param_6)



{
  if (param_3 > param_5 || ((param_3 == param_5) && (param_6 < param_4))) {
    if (param_3 <= param_1) {
      if (param_3 == param_1) {
        if (param_4 <= param_2) {
          return 1;
        }
      } else {
        return 1;
      }
    } else {
      if (!(param_5 < param_1)) {
        if (param_5 == param_1) {
          if (!(param_6 < param_2)) {
            return 1;
          }
        } else {
          return 1;
        }
      }
    }
  } else if ((param_3 <= param_1) && (param_1 <= param_5)) {
    if (param_3 == param_1) {
      if (param_4 <= param_2) {
        return 1;
      }
    } else {
      if (param_5 == param_1) {
        if (!(param_6 < param_2)) {
          return 1;
        }
      } else {
        return 1;
      }
    }
  }
  return 0;
}
#define FUN_003bf270(...) ((u32 (*)(...))FUN_003bf270)(__VA_ARGS__)
#undef FUN_003bf370

// FUN_003BF370


u32 FUN_003bf370(void)
{
  int iVar1;
  u32 bVar2;
  u32 bVar3;
  int *piVar3;
  int iVar4;
  u32 lVar5;
  u8 auStack_20 [28];

  piVar3 = (int *)FUN_00195540();
  iVar4 = FUN_001717b0();
  iVar1 = *piVar3;
  switch (iVar1) {
  case 0:
    DAT_007ce66c = 0;
    *piVar3 = 1;
    break;
  case 1:
    lVar5 = FUN_003c3e80(iVar4 + 0x1e4);
    if (lVar5 == 0) {
      *piVar3 = 2;
    }
    break;
  case 2:
    piVar3[1] = 0;
    piVar3[2] = 2;
    *piVar3 = 3;
    break;
  case 3:
    if (piVar3[1] >= piVar3[2]) {
      piVar3[1] = 0;
      piVar3[2] = 0;
      bVar3 = 1;
    }
    else {
      piVar3[1] = piVar3[1] + 1;
      bVar3 = 0;
    }
    if (bVar3 == 0) {
      break;
    }
    FUN_00521408(auStack_20,0,0x1c);
    ((u32 *)auStack_20)[3] = 0x35d;
    ((u32 *)auStack_20)[4] = 1;
    ((u32 *)auStack_20)[5] = 0;
    FUN_0027c080(3,auStack_20,0x1c,0);
    *piVar3 = 4;
    break;
  case 4:
    lVar5 = FUN_0027c2b0();
    if (lVar5 != 0) goto case4_false;
    lVar5 = FUN_0027c330();
    if (lVar5 != -1) goto case4_false;
    bVar2 = 1;
    goto case4_check;
case4_false:
    bVar2 = 0;
case4_check:
    if (bVar2 != 1) {
      break;
    }
    return 0xffffffff;
  }
  return 0;
}
#define FUN_003bf370(...) ((u32 (*)(...))FUN_003bf370)(__VA_ARGS__)
#undef FUN_003bf510

// FUN_003BF510


u32 FUN_003bf510(void)



{
  int iVar1;
  int *piVar3;
  int iVar4;
  u32 lVar5;
  u32 bVar2;

  piVar3 = (int *)FUN_00195540();
  iVar4 = FUN_001717b0();
  iVar1 = *piVar3;

  switch (iVar1) {
  case 0:
    *piVar3 = 1;
    break;
  case 1:
    lVar5 = FUN_003c3e80(iVar4 + 0x248);
    if (lVar5 == 0) {
      *piVar3 = 2;
    }
    break;
  case 2:
    return 0xffffffff;
  case 3:
    lVar5 = FUN_0027c2b0();
    if (lVar5 != 0) goto case3_false;
    lVar5 = FUN_0027c330();
    if (lVar5 != -1) goto case3_false;
    bVar2 = 1;
    goto case3_check;
case3_false:
    bVar2 = 0;
case3_check:
    if (bVar2 != 1) {
      break;
    }
    return 0xffffffff;
  default:
    break;
  }

  return 0;
}
#define FUN_003bf510(...) ((u32 (*)(...))FUN_003bf510)(__VA_ARGS__)
#undef FUN_003bf610

// FUN_003BF610

u32 FUN_003bf610(void)
{
  int iVar1;
  u32 bVar2;
  int *piVar3;
  u32 lVar4;
  u16 auStack_20 [14];

  piVar3 = (int *)FUN_00195540();
  iVar1 = *piVar3;
  switch (iVar1) {
  case 0:
    piVar3[1] = 0;
    piVar3[2] = 2;
    *piVar3 = 1;
    break;
  case 1:
    FUN_00521408(auStack_20,0,0x1c);
    auStack_20[0] = 7;
    auStack_20[1] = 1;
    auStack_20[2] = 0;
    auStack_20[4] = 0;
    FUN_0027c080(2,auStack_20,0x1c,0);
    *piVar3 = 2;
    break;
  case 2:
    lVar4 = FUN_0027c2b0();
    if ((lVar4 == 0) && (lVar4 = FUN_0027c330(), lVar4 == -1)) {
      bVar2 = 1;
    }
    else {
      bVar2 = 0;
    }
    if (bVar2 == 1) {
      return 0xffffffff;
    }
    break;
  }
  return 0;
}
#define FUN_003bf610(...) ((u32 (*)(...))FUN_003bf610)(__VA_ARGS__)
