#include "temporary.h"

typedef int (*code)(...);
typedef u8 bool;
#pragma alias FUN_00396270_f32 FUN_00396270
extern void FUN_00396270_f32(f32, int, f32 *);
typedef u32 undefined3;
typedef struct {
  u8 _pad_d8[0xd8];
  int menuId;
  u32 _pad_dc;
  u32 menuArg;
  u8 _pad_e4[0x860];
  u32 resourceHandles[7];
} EvtMenuState;
typedef struct {
  f32 x;
  f32 y;
  f32 z;
} EvtVec3;
typedef struct {
  f32 x;
  f32 y;
  f32 z;
  f32 dx;
  f32 dy;
  f32 dz;
} EvtRay;

void FUN_003957d0(f32 value, u64 object, u32* data);

extern u32 DAT_0069d590;
extern u32 DAT_0069d5c8;
extern u32 DAT_0069d5d0;
extern u32 DAT_0069d5d8;
extern u32 DAT_0069d5e0;
extern u32 DAT_0069d5e8;
extern u32 DAT_0069d5f0;
extern u32 DAT_0069d5f8;
extern u32 DAT_0069d600;
extern u32 DAT_0069d608;
extern u32 DAT_0069d610;
extern u32 DAT_0069d618;
extern u32 DAT_0069d620;
extern u32 DAT_0069d628;
extern u32 DAT_0069d630;
extern u32 DAT_0069d6e8;
extern u32 DAT_0069d6f0;
extern u8 DAT_0069d910;
extern u32 DAT_0069de40;
extern u32 DAT_0069e180;
#pragma alias DAT_0069e180_char DAT_0069e180
extern char DAT_0069e180_char[];
extern char DAT_0069e1a0[];
extern char DAT_0069e1a2[];
extern char DAT_0069e1aa[];
#pragma alias s_evtMenu_0069ea10 DAT_0069ea10
extern char s_evtMenu_0069ea10[];
#pragma alias s_evtMenu_0069ea00 DAT_0069ea00
extern char s_evtMenu_0069ea00[];
#pragma alias s_evtMenu_0069e9e0 DAT_0069e9e0
extern char s_evtMenu_0069e9e0[];
extern char DAT_0069ebd8[];
#pragma alias s_evtMenuTextFormat_007ccd58 DAT_007ccd58
extern char s_evtMenuTextFormat_007ccd58[];
extern char DAT_007cd010;
extern char DAT_007cd020;
extern char DAT_007cd02c;
extern char DAT_007cd038;
extern char DAT_007cd09c;
#pragma alias DAT_0069e888_abs DAT_0069e888
extern u8 DAT_0069e888_abs[];
#pragma alias DAT_0069f948_abs DAT_0069f948
extern u8 DAT_0069f948_abs[];
#pragma alias DAT_0069f958_abs DAT_0069f958
extern u8 DAT_0069f958_abs[];
#pragma alias DAT_0069f968_abs DAT_0069f968
extern u8 DAT_0069f968_abs[];
#pragma alias DAT_0069f978_abs DAT_0069f978
extern u8 DAT_0069f978_abs[];
#pragma alias DAT_0069fdf0_abs DAT_0069fdf0
extern u8 DAT_0069fdf0_abs[];
#pragma alias DAT_0069fe30_abs DAT_0069fe30
#pragma alias DAT_0069fe10_abs DAT_0069fe10
extern u8 DAT_0069fe10_abs[];
extern u8 DAT_0069fe30_abs[];
#pragma alias DAT_0069ff60_abs DAT_0069ff60
extern u8 DAT_0069ff60_abs[];
#pragma alias DAT_0069ff80_abs DAT_0069ff80
extern u8 DAT_0069ff80_abs[];
#pragma alias DAT_0069ffa0_abs DAT_0069ffa0
extern u8 DAT_0069ffa0_abs[];
#pragma alias DAT_0069ffc0_abs DAT_0069ffc0
extern u8 DAT_0069ffc0_abs[];
extern u32 DAT_0069e420;
#pragma alias DAT_0069e420_abs DAT_0069e420
extern u8 DAT_0069e420_abs[];
#pragma alias DAT_0069e422_abs DAT_0069e422
extern u8 DAT_0069e422_abs[];
extern s8 DAT_0069e422[];
extern code DAT_006a0270[];
extern u32 DAT_006a0bf8;
extern u32 DAT_006a0c00;
extern char DAT_006a0330[];
extern f32 DAT_007cadc0;
extern u32 DAT_007cadd0;
extern u32 DAT_007cae18;
extern u32 DAT_007cafec;
extern f32 DAT_007cb088;
extern f32 DAT_007cb0cc;
extern f32 DAT_007cb110;
typedef struct EvtMenuClampWork {
  u8 pad_000[0xd4];
  s32 state;
  u8 pad_0d8[0xac];
  f32 value;
  f32 minimum;
  f32 maximum;
} EvtMenuClampWork;
extern u32 DAT_007cb120;
#pragma alias DAT_007cb120_f32 DAT_007cb120
extern f32 DAT_007cb120_f32;
#pragma alias DAT_007cb124_f32 DAT_007cb124
extern f32 DAT_007cb124_f32;
extern u32 DAT_007cb124;
extern s16 DAT_007cca68;
extern s16 DAT_007cca6c;
extern u32 DAT_007ccd20;
extern f32 DAT_007cce48;
extern f32 DAT_007cce4c;
extern u32 DAT_007cce78;
extern u32 DAT_007ccf94;
extern u32 DAT_007cd130;
extern u32 DAT_007cdeac;
extern u32 DAT_007ce5d8;
extern u32 DAT_007ce5e4;
extern u32 DAT_007ce5e8;
extern u32 DAT_007ce5ec;
extern u32 DAT_007ce5f0;
extern u32 DAT_007ce5f4;
extern u32 DAT_007ce5f8;
extern u32 DAT_007ce5fc;
extern u32 DAT_007ce600;
extern u32 DAT_007ce604;
extern u32 DAT_007ce608;
extern s32 DAT_007ce60c;
extern u16 DAT_007e094c;
#pragma alias DAT_007e094c_abs DAT_007e094c
extern u8 DAT_007e094c_abs[];
extern u16 DAT_007e094e;
#pragma alias DAT_007e094e_abs DAT_007e094e
extern u8 DAT_007e094e_abs[];
extern u16 DAT_007e0952;
#pragma alias DAT_007e0952_abs DAT_007e0952
extern u8 DAT_007e0952_abs[];
extern u32 DAT_007e095e;
extern u32 DAT_007e095f;
extern u32 DAT_007e0960;
extern u32 DAT_007e0961;
extern u32 DAT_00958470;
extern u32 DAT_009584a4;
extern u32 DAT_009584d0;
extern u32 DAT_009584fc;
extern u32 DAT_0095852c;
extern u32 DAT_0095855c;
extern u32 DAT_00958580;
extern u32 DAT_009585a8;
extern u32 DAT_009585ac;
extern u32 DAT_009585b0;
extern u32 DAT_009585b8;
#pragma alias DAT_009585b8_f32 DAT_009585b8
extern f32 DAT_009585b8_f32;
#pragma alias DAT_009585bc_f32 DAT_009585bc
extern f32 DAT_009585bc_f32;
#pragma alias DAT_009585c0_f32 DAT_009585c0
extern f32 DAT_009585c0_f32;
#pragma alias DAT_009585b8_abs DAT_009585b8
extern u8 DAT_009585b8_abs[];
#pragma alias DAT_009585a8_abs DAT_009585a8
extern u8 DAT_009585a8_abs[];
extern u32 DAT_009585bc;
extern u32 DAT_009585c0;
extern u32 DAT_009585d0;
extern u32 DAT_00958700;
#pragma alias DAT_00958700_abs DAT_00958700
extern u8 DAT_00958700_abs[];
#pragma alias DAT_00958700_f32 DAT_00958700
extern f32 DAT_00958700_f32[];
extern u32 DAT_00958704;
#pragma alias DAT_00958704_f32 DAT_00958704
extern f32 DAT_00958704_f32;
#pragma alias DAT_00958708_f32 DAT_00958708
extern f32 DAT_00958708_f32;
#pragma alias DAT_0095870c_f32 DAT_0095870c
extern f32 DAT_0095870c_f32;
#pragma alias DAT_00958710_f32 DAT_00958710
extern f32 DAT_00958710_f32;
#pragma alias DAT_00958714_f32 DAT_00958714
extern f32 DAT_00958714_f32;
#pragma alias DAT_00958718_f32 DAT_00958718
extern f32 DAT_00958718_f32;
#pragma alias DAT_0095871c_f32 DAT_0095871c
extern f32 DAT_0095871c_f32;
#pragma alias DAT_00958720_f32 DAT_00958720
extern f32 DAT_00958720_f32;
#pragma alias DAT_00958724_f32 DAT_00958724
extern f32 DAT_00958724_f32;
#pragma alias DAT_00958728_f32 DAT_00958728
extern f32 DAT_00958728_f32;
#pragma alias DAT_0095872c_f32 DAT_0095872c
extern f32 DAT_0095872c_f32;
#pragma alias DAT_00958730_f32 DAT_00958730
extern f32 DAT_00958730_f32;
#pragma alias DAT_00958734_f32 DAT_00958734
extern f32 DAT_00958734_f32;
#pragma alias DAT_00958738_f32 DAT_00958738
extern f32 DAT_00958738_f32;
#pragma alias DAT_0095873c_f32 DAT_0095873c
extern f32 DAT_0095873c_f32;
#pragma alias DAT_00958740_f32 DAT_00958740
extern f32 DAT_00958740_f32;
#pragma alias DAT_00958744_f32 DAT_00958744
extern f32 DAT_00958744_f32;
#pragma alias DAT_00958748_f32 DAT_00958748
extern f32 DAT_00958748_f32;
#pragma alias DAT_0095874c_f32 DAT_0095874c
extern f32 DAT_0095874c_f32;
#pragma alias DAT_00958750_f32 DAT_00958750
extern f32 DAT_00958750_f32;
#pragma alias DAT_00958754_f32 DAT_00958754
extern f32 DAT_00958754_f32;
#pragma alias DAT_009585b8_f32_abs DAT_009585b8
extern f32 DAT_009585b8_f32_abs[];
#pragma alias DAT_009585bc_f32_abs DAT_009585bc
extern f32 DAT_009585bc_f32_abs[];
#pragma alias DAT_009585c0_f32_abs DAT_009585c0
extern f32 DAT_009585c0_f32_abs[];
#pragma alias DAT_00958700_f32_abs DAT_00958700
extern f32 DAT_00958700_f32_abs[];
#pragma alias DAT_00958704_f32_abs DAT_00958704
extern f32 DAT_00958704_f32_abs[];
#pragma alias DAT_00958708_f32_abs DAT_00958708
extern f32 DAT_00958708_f32_abs[];
#pragma alias DAT_0095870c_f32_abs DAT_0095870c
extern f32 DAT_0095870c_f32_abs[];
#pragma alias DAT_00958710_f32_abs DAT_00958710
extern f32 DAT_00958710_f32_abs[];
#pragma alias DAT_00958714_f32_abs DAT_00958714
extern f32 DAT_00958714_f32_abs[];
#pragma alias DAT_00958718_f32_abs DAT_00958718
extern f32 DAT_00958718_f32_abs[];
#pragma alias DAT_0095871c_f32_abs DAT_0095871c
extern f32 DAT_0095871c_f32_abs[];
#pragma alias DAT_00958720_f32_abs DAT_00958720
extern f32 DAT_00958720_f32_abs[];
#pragma alias DAT_00958724_f32_abs DAT_00958724
extern f32 DAT_00958724_f32_abs[];
#pragma alias DAT_00958728_f32_abs DAT_00958728
extern f32 DAT_00958728_f32_abs[];
#pragma alias DAT_0095872c_f32_abs DAT_0095872c
extern f32 DAT_0095872c_f32_abs[];
#pragma alias DAT_00958730_f32_abs DAT_00958730
extern f32 DAT_00958730_f32_abs[];
#pragma alias DAT_00958734_f32_abs DAT_00958734
extern f32 DAT_00958734_f32_abs[];
#pragma alias DAT_00958738_f32_abs DAT_00958738
extern f32 DAT_00958738_f32_abs[];
#pragma alias DAT_0095873c_f32_abs DAT_0095873c
extern f32 DAT_0095873c_f32_abs[];
#pragma alias DAT_00958740_f32_abs DAT_00958740
extern f32 DAT_00958740_f32_abs[];
#pragma alias DAT_00958744_f32_abs DAT_00958744
extern f32 DAT_00958744_f32_abs[];
#pragma alias DAT_00958748_f32_abs DAT_00958748
extern f32 DAT_00958748_f32_abs[];
#pragma alias DAT_0095874c_f32_abs DAT_0095874c
extern f32 DAT_0095874c_f32_abs[];
#pragma alias DAT_00958750_f32_abs DAT_00958750
extern f32 DAT_00958750_f32_abs[];
#pragma alias DAT_00958754_f32_abs DAT_00958754
extern f32 DAT_00958754_f32_abs[];
extern u32 DAT_00958708;
extern u32 DAT_0095870c;
extern u32 DAT_00958710;
extern u32 DAT_00958714;
extern u32 DAT_00958718;
extern u32 DAT_0095871c;
extern u32 DAT_00958720;
extern u32 DAT_00958724;
extern u32 DAT_00958728;
extern u32 DAT_0095872c;
extern u32 DAT_00958730;
extern u32 DAT_00958734;
extern u32 DAT_00958738;
extern u32 DAT_0095873c;
extern u32 DAT_00958740;
extern u32 DAT_00958744;
extern u32 DAT_00958748;
extern u32 DAT_0095874c;
extern u32 DAT_00958750;
extern u32 DAT_00958754;
extern u32 DAT_00958830;
extern u32 DAT_00958834;
extern u32 DAT_00958838;
extern u32 DAT_00958840;
extern u32 DAT_00958844;
extern u32 DAT_00958848;
#pragma alias DAT_00958830_f32_abs DAT_00958830
extern f32 DAT_00958830_f32_abs[];
#pragma alias DAT_00958834_f32_abs DAT_00958834
extern f32 DAT_00958834_f32_abs[];
#pragma alias DAT_00958838_f32_abs DAT_00958838
extern f32 DAT_00958838_f32_abs[];
#pragma alias DAT_00958840_f32_abs DAT_00958840
extern f32 DAT_00958840_f32_abs[];
#pragma alias DAT_00958844_f32_abs DAT_00958844
extern f32 DAT_00958844_f32_abs[];
#pragma alias DAT_00958848_f32_abs DAT_00958848
extern f32 DAT_00958848_f32_abs[];
extern u32 DAT_00958850;
#pragma alias DAT_00958a60_abs DAT_00958a60
extern u8 DAT_00958a60_abs[];
#pragma alias DAT_00958850_abs DAT_00958850
extern u8 DAT_00958850_abs[];
extern u32 DAT_00958890;
extern u32 DAT_00958894;
extern u32 DAT_00958898;
extern u32 DAT_009588a0;
extern u32 DAT_009588a4;
extern u32 DAT_009588a8;
#pragma alias DAT_00958890_abs DAT_00958890
#pragma alias DAT_00958894_abs DAT_00958894
#pragma alias DAT_00958898_abs DAT_00958898
#pragma alias DAT_009588a0_abs DAT_009588a0
#pragma alias DAT_009588a4_abs DAT_009588a4
#pragma alias DAT_009588a8_abs DAT_009588a8
extern u8 DAT_00958890_abs[];
extern u8 DAT_00958894_abs[];
extern u8 DAT_00958898_abs[];
extern u8 DAT_009588a0_abs[];
extern u8 DAT_009588a4_abs[];
extern u8 DAT_009588a8_abs[];
#pragma alias DAT_006a0030_abs DAT_006a0030
extern u8 DAT_006a0030_abs[];
#pragma alias DAT_006a0080_abs DAT_006a0080
extern u8 DAT_006a0080_abs[];
#pragma alias DAT_006a01e0_abs DAT_006a01e0
extern u8 DAT_006a01e0_abs[];
#pragma alias DAT_006a01a0_abs DAT_006a01a0
extern u8 DAT_006a01a0_abs[];
#pragma alias DAT_006a01c0_abs PTR_s_KAIKIN_006a01c0
extern f32 DAT_006a01c0_abs[];
#pragma alias DAT_006a01c4_abs PTR_DAT_006a01c4
extern f32 DAT_006a01c4_abs[];
#pragma alias DAT_006a01c8_abs PTR_s_REVERSE_006a01c8
extern f32 DAT_006a01c8_abs[];
#pragma alias DAT_006a01cc_abs PTR_s_HAMETU_006a01cc
extern f32 DAT_006a01cc_abs[];
#pragma alias DAT_006a01d0_abs DAT_006a01d0
extern u8 DAT_006a01d0_abs[];
#pragma alias DAT_006a0230_abs DAT_006a0230
extern u8 DAT_006a0230_abs[];
#pragma alias DAT_006a0350_abs DAT_006a0350
extern u8 DAT_006a0350_abs[];
#pragma alias DAT_006a03f0_abs DAT_006a03f0
extern u8 DAT_006a03f0_abs[];
#pragma alias DAT_006a0530_abs DAT_006a0530
extern u8 DAT_006a0530_abs[];
#pragma alias DAT_006a05c0_abs DAT_006a05c0
extern u8 DAT_006a05c0_abs[];
#pragma alias DAT_006a0610_abs DAT_006a0610
extern u8 DAT_006a0610_abs[];
#pragma alias DAT_006a0670_abs DAT_006a0670
extern u8 DAT_006a0670_abs[];
#pragma alias DAT_006a06b0_abs DAT_006a06b0
extern u8 DAT_006a06b0_abs[];
#pragma alias DAT_006a06d0_abs DAT_006a06d0
extern u8 DAT_006a06d0_abs[];
#pragma alias DAT_006a06f0_abs DAT_006a06f0
extern u8 DAT_006a06f0_abs[];
#pragma alias DAT_006a0730_abs DAT_006a0730
extern u8 DAT_006a0730_abs[];
#pragma alias DAT_006a0780_abs DAT_006a0780
extern u8 DAT_006a0780_abs[];
#pragma alias DAT_006a07e0_abs DAT_006a07e0
extern u8 DAT_006a07e0_abs[];
#pragma alias DAT_006a0890_abs DAT_006a0890
extern u8 DAT_006a0890_abs[];
#pragma alias DAT_006a0920_abs DAT_006a0920
extern u8 DAT_006a0920_abs[];
#pragma alias DAT_006a0990_abs DAT_006a0990
extern u8 DAT_006a0990_abs[];
#pragma alias DAT_006a09f0_abs DAT_006a09f0
extern u8 DAT_006a09f0_abs[];
extern u32 DAT_009588b0;
extern u32 DAT_009588b4;
extern u32 DAT_009588b8;
extern u32 DAT_009588bc;
extern u32 DAT_009588c0;
extern u32 DAT_009588c4;
extern u32 DAT_009588c8;
extern u32 DAT_009588cc;
extern u32 DAT_009588d0;
extern u32 DAT_009588d4;
extern u32 DAT_009588d8;
extern u32 DAT_009588dc;
extern u32 DAT_009588e0;
extern u32 DAT_009588e4;
extern u32 DAT_009588e8;
extern u32 DAT_009588ec;
extern u32 DAT_00958970;
extern u32 DAT_00958978;
extern u32 DAT_0095897a;
extern u32 DAT_0095897c;
extern u32 DAT_0095897e;
extern u32 DAT_00958980;
extern u32 DAT_009589c8;
extern u32 DAT_009589cc;
extern u32 DAT_009589d0;
extern u32 DAT_009589e0;
extern u32 DAT_009589e4;
extern u32 DAT_009589e8;
extern u32 DAT_00958a60;
extern u32 DAT_00958a90;
extern u32 DAT_00960088;
extern code DAT_00960090;
extern code DAT_009600a0;
extern code DAT_0096017c;
extern code DAT_00960184;
extern u8 *PTR_DAT_0069d930;
extern u8 *PTR_DAT_0069d960;
extern u8 *PTR_DAT_0069da10;
extern u8 *PTR_DAT_0069da50;
extern u8 *PTR_DAT_0069da60;
extern u8 *PTR_DAT_0069db10;
extern u8 *PTR_DAT_0069ed90;
extern u8 *PTR_DAT_0069ede0;
extern u8 *PTR_DAT_0069ee10;
extern u8 *PTR_DAT_0069ee20;
extern u8 *PTR_DAT_0069ee40;
extern u8 *PTR_DAT_0069ee44;
extern u8 *PTR_DAT_0069ee48;
extern u8 *PTR_DAT_0069ee50;
extern u8 *PTR_DAT_0069ee54;
extern u8 *PTR_DAT_0069ee58;
extern u8 *PTR_DAT_0069eeb0;
extern u8 *PTR_DAT_0069eed0;
extern u8 *PTR_DAT_0069f9a4;
extern u8 *PTR_DAT_0069f9a8;
extern u8 *PTR_DAT_0069f9d8;
extern u8 *PTR_DAT_0069f9e0;
extern u8 *PTR_DAT_0069fa80;
extern u8 *PTR_DAT_006a01c4;
extern u8 *PTR_DAT_007cca5c;
extern u8 *PTR_DAT_007cca88;
extern u8 *PTR_DAT_007ccc50;
extern u8 *PTR_DAT_007ccc58;
extern u8 *PTR_DAT_007ccd8c;
extern u8 *PTR_DAT_007ccda4;
extern u8 *PTR_DAT_007ccdbc;
extern u8 *PTR_DAT_007ccf54;
extern u8 *PTR_DAT_007ccf60;
extern u8 *PTR_DAT_007ccf64;
extern u8 *PTR_DAT_007ccf7c;
extern u8 *PTR_DAT_007ccfa8;
extern u8 *PTR_DAT_007cd230;
extern u8 *PTR_DAT_007cd234;
extern u8 *PTR_DAT_007cd238;
extern u8 *PTR_DAT_007cd23c;
extern u8 *PTR_DAT_007cd25c;
extern u8 *PTR_DAT_007cd2d4;
extern u8 *PTR_DAT_007cd3d0;
extern code PTR_LAB_007ba6f0[];
extern code PTR_LAB_007ba740[];
extern code PTR_LAB_007ba7f0[];
extern code PTR_LAB_007ba810[];
extern code PTR_LAB_007ba830[];
extern code PTR_LAB_007ba850[];
extern code PTR_LAB_007ba9f0[];
extern code PTR_LAB_007baa30[];
extern code PTR_LAB_007baa70[];
extern code PTR_LAB_007baaf0[];
extern code PTR_LAB_007bab30[];
extern u8 *PTR_s_ACTIVE_0069f9dc;
extern u8 *PTR_s_ACTIVE_007ccf14;
extern u8 *PTR_s_ALPHA_0069ee3c;
extern u8 *PTR_s_BEZIER_0069fa84;
extern u8 *PTR_s_CAPTURE_007ccf78;
extern u8 *PTR_s_COMSE_007cd3d4;
#pragma alias PTR_DAT_007cd3d0_f32 PTR_DAT_007cd3d0
extern f32 PTR_DAT_007cd3d0_f32;
#pragma alias PTR_s_COMSE_007cd3d4_f32 PTR_s_COMSE_007cd3d4
extern f32 PTR_s_COMSE_007cd3d4_f32;
extern u8 *PTR_s_CREATE_0069da70;
extern u8 *PTR_s_CREATE_0069ee30;
extern u8 *PTR_s_DELETE_0069ee38;
extern u8 *PTR_s_DIRECT_0069e9c0;
#pragma alias PTR_s_DIRECT_0069e9c0_abs PTR_s_DIRECT_0069e9c0
extern u8 *PTR_s_DIRECT_0069e9c0_abs[];
extern u8 *PTR_s_DIRECT_0069f9a0;
extern u8 *PTR_s_DIRECT_0069fa88;
extern u8 *PTR_s_DIRECT_007ccda0;
extern u8 *PTR_s_DIRECT_007cd258;
#pragma alias PTR_s_DIRECT_007cd258_f32 PTR_s_DIRECT_007cd258
extern f32 PTR_s_DIRECT_007cd258_f32;
extern f32 PTR_DAT_007cd25c_f32;
#pragma alias PTR_DAT_007cd25c_f32 PTR_DAT_007cd25c
#pragma alias PTR_s_DISABLE_0069e6c8_abs PTR_s_DISABLE_0069e6c8
extern u8 *PTR_s_DISABLE_0069e6c8_abs[];
extern u8 *PTR_s_DISPONOFF_007ccaa8;
extern u8 *PTR_s_FADEOUT_0069ee14;
extern u8 *PTR_s_FADEOUT_WAIT_007ccf9c;
extern u8 *PTR_s_FADE_IN_007cce88;
extern u8 *PTR_s_FALSE_007ccdb8;
extern u8 *PTR_s_GAKURYOKU_0069feb0;
#pragma alias PTR_s_GAKURYOKU_0069feb0_abs PTR_s_GAKURYOKU_0069feb0
extern u8 *PTR_s_GAKURYOKU_0069feb0_abs[];
extern u8 *PTR_s_HAMETU_006a01cc;
extern u8 *PTR_s_HIRU_SASO_0069d880;
extern u8 *PTR_s_KAIKIN_006a01c0;
extern u8 *PTR_s_KEYFREE_007ccfbc;
extern u8 gp0xffffa2d0;
extern u8 *PTR_s_KUCHI_0069ee18;
extern u8 *PTR_s_LENGTH_007cd22c;
extern u8 *PTR_s_L_FLAG_NOTUSE_0069e990;
#pragma alias PTR_s_L_FLAG_NOTUSE_0069e990_abs PTR_s_L_FLAG_NOTUSE_0069e990
extern u8 *PTR_s_L_FLAG_NOTUSE_0069e990_abs[];
extern u8 *PTR_s_MEPACHI_0069ee1c;
extern u8 *PTR_s_MES_WAIT_007ccf98;
extern u8 *PTR_s_MOVE_D_0069ee34;
extern u8 *PTR_s_MOVE_D_007ccf10;
extern u8 *PTR_s_NORMAL_0069d940;
extern u8 *PTR_s_NORMAL_007ccc60;
extern u8 *PTR_s_NORMAL_007cd2d0;
extern u8 *PTR_s_NOSTOP_007ccfac;
extern u8 *PTR_s_NO_KEYFREE_007ccfb8;
extern u8 *PTR_s_OFFSET_0069e6a0;
#pragma alias PTR_s_OFFSET_0069e6a0_abs PTR_s_OFFSET_0069e6a0
extern u8 *PTR_s_OFFSET_0069e6a0_abs[];
extern u8 *PTR_s_RELEASE_0069ee28;
extern u8 *PTR_s_REPEAT_007ccd88;
extern u8 *PTR_s_REVERSE_006a01c8;
extern u8 *PTR_s_SAVE_PROJ_;
#pragma alias PTR_s_SAVE_PROJ_abs PTR_s_SAVE_PROJ_
extern u8 *PTR_s_SAVE_PROJ_abs[];
extern u8 *PTR_s_SOUTAI_007ccd78;
extern u8 *PTR_s_SPEED_007cd228;
extern u8 *PTR_s_START_0069e100;
#pragma alias PTR_s_START_0069e100_abs PTR_s_START_0069e100
extern u8 *PTR_s_START_0069e100_abs[];
extern u8 *PTR_s_START_0069ee24;
extern u8 *PTR_s_START_007ccf50;
extern u32 fGpffff80d0;
extern f32 fGpffff8294;
extern u32 fGpffff8438;
extern s16 gp0xffff9d78;
extern s16 gp0xffff9d7c;
extern u8 gp0xffff9dd0;
extern u8 gp0xffff9dd8;
extern u8 gp0xffff9df8;
extern u8 gp0xffff9e48;
extern u8 gp0xffff9e58;
extern u8 gp0xffff9e60;
extern u8 gp0xffff9e98;
extern u8 gp0xffff9ea8;
extern u8 gp0xffff9ec0;
extern u8 gp0xffff9ed8;
extern u8 gp0xffff9ee0;
extern u8 gp0xffff9ef8;
extern u8 gp0xffff9f00;
extern u8 gp0xffff9f08;
extern u8 gp0xffff9f10;
extern u8 gp0xffff9f20;
extern u8 gp0xffff9f30;
extern u8 gp0xffff9f58;
extern u8 gp0xffffa050;
extern u8 gp0xffffa100;
extern u8 gp0xffffa000;
extern u8 gp0xffffa028;
extern u8 gp0xffffa058;
extern u8 gp0xffffa060;
extern u8 gp0xffffa068;
extern u8 gp0xffffa070;
extern u8 gp0xffffa0b8;
extern u8 gp0xffffa130;
extern u8 gp0xffffa134;
extern u8 gp0xffffa138;
extern u8 gp0xffffa140;
extern u8 gp0xffffa148;
extern u8 gp0xffffa150;
extern u8 gp0xffffa350;
extern u8 gp0xffffa108;
extern u8 DAT_0069ea58[];
extern u8 DAT_0069e6f0[];
extern u8 DAT_0069f170[];
#pragma alias DAT_0069e6b8_abs DAT_0069e6b8
extern u8 DAT_0069e6b8_abs[];
#pragma alias DAT_0069e878_abs DAT_0069e878
extern u8 DAT_0069e878_abs[];
#pragma alias DAT_0069fc20_abs DAT_0069fc20
extern u8 DAT_0069fc20_abs[];
#pragma alias DAT_0069fcf0_abs DAT_0069fcf0
extern u8 DAT_0069fcf0_abs[];
#pragma alias DAT_0069fd60_abs DAT_0069fd60
extern u8 DAT_0069fd60_abs[];
#pragma alias DAT_0069fdb0_abs DAT_0069fdb0
extern u8 DAT_0069fdb0_abs[];
#pragma alias DAT_0069fa40_abs DAT_0069fa40
extern u8 DAT_0069fa40_abs[];
#pragma alias DAT_0069fa50_abs DAT_0069fa50
extern u8 DAT_0069fa50_abs[];
#pragma alias DAT_0069fa60_abs DAT_0069fa60
extern u8 DAT_0069fa60_abs[];
#pragma alias DAT_0069fd08_abs DAT_0069fd08
extern u8 DAT_0069fd08_abs[];
#pragma alias DAT_0069fd18_abs DAT_0069fd18
extern u8 DAT_0069fd18_abs[];
#pragma alias DAT_0069fd30_abs DAT_0069fd30
extern u8 DAT_0069fd30_abs[];
#pragma alias DAT_0069fd48_abs DAT_0069fd48
extern u8 DAT_0069fd48_abs[];
#pragma alias DAT_007cd020_abs DAT_007cd020
extern u8 DAT_007cd020_abs[];
#pragma alias DAT_007cd0a8_abs DAT_007cd0a8
extern u8 DAT_007cd0a8_abs[];
#pragma alias DAT_007cd2f0_abs DAT_007cd2f0
extern u8 DAT_007cd2f0_abs[];
#pragma alias DAT_0069ea58_abs DAT_0069ea58
extern u8 DAT_0069ea58_abs[];
extern u8 DAT_0069ea68[];
extern u8 DAT_0069eb28[];
extern u8 DAT_0069eb48[];
extern u8 DAT_0069eb58[];
extern u8 DAT_0069ea78[];
#pragma alias DAT_0069ea78_abs DAT_0069ea78
extern u8 DAT_0069ea78_abs[];
extern u8 DAT_0069ea88[];
extern u8 DAT_0069eaa0[];
#pragma alias DAT_0069ea88_abs DAT_0069ea88
extern u8 DAT_0069ea88_abs[];
extern u8 DAT_0069ec48[];
extern u8 DAT_0069ec60[];
extern u8 DAT_0069ec80[];
extern u8 DAT_0069fd78[];
#pragma alias DAT_0069f8b0_abs DAT_0069f8b0
extern u8 DAT_0069f990[];
extern u8 DAT_0069f8b0_abs[];
#pragma alias DAT_0069fb70_abs DAT_0069fb70
extern u8 DAT_0069fb70_abs[];
extern u8 DAT_0069fd88[];
extern u8 DAT_0069fd98[];
extern u8 DAT_0069ec08[];
extern u8 DAT_0069ec18[];
extern u8 DAT_0069ec28[];
#pragma alias DAT_0069ec08_abs DAT_0069ec08
extern u8 DAT_0069ec08_abs[];
#pragma alias DAT_0069ec18_abs DAT_0069ec18
extern u8 DAT_0069ec18_abs[];
#pragma alias DAT_0069ec28_abs DAT_0069ec28
extern u8 DAT_0069ec28_abs[];
extern u8 DAT_0069ec38[];
extern u8 DAT_0069ecb8[];
extern u8 DAT_0069eca0[];
#pragma alias DAT_0069eca0_abs DAT_0069eca0
extern u8 DAT_0069eca0_abs[];
extern u8 DAT_0069ecc8[];
extern u8 DAT_0069ece0[];
extern u8 DAT_0069ed00[];
extern u8 DAT_0069ed20[];
extern u8 DAT_0069ed40[];
extern u8 DAT_0069ed60[];
extern u8 DAT_0069eb38[];
extern u8 DAT_0069fc68[];
extern u8 DAT_0069fc50[];
extern u8 DAT_0069f9c0[];
extern u8 DAT_0069fa70[];
extern u8 DAT_0069fa30[];
extern u8 DAT_0069fb58[];
extern u8 DAT_0069fb88[];
extern u8 DAT_0069fbd8[];
extern u8 DAT_0069fbf0[];
extern u8 DAT_0069fc10[];
#pragma alias DAT_0069fb98_abs DAT_0069fb98
extern u8 DAT_0069fb98_abs[];
#pragma alias DAT_0069fba8_abs DAT_0069fba8
extern u8 DAT_0069fba8_abs[];
#pragma alias DAT_0069fbc0_abs DAT_0069fbc0
extern u8 DAT_0069fbc0_abs[];
extern u8 DAT_007ccca8[];
extern u8 DAT_007cd260[];
extern u8 DAT_0069fc78[];
extern u8 DAT_0069fc88[];
extern u8 DAT_0069fc98[];
extern u8 DAT_0069fca8[];
extern u8 DAT_0069fcb8[];
extern u8 DAT_0069fcc8[];
extern u8 DAT_0069fcd8[];
extern u8 DAT_0069ff10[];
extern u8 DAT_0069ff20[];
extern u8 DAT_0069ff30[];
extern u8 DAT_0069ff40[];
extern u8 DAT_0069ff50[];
#pragma alias DAT_0069ead8_f32 DAT_0069ead8
extern f32 DAT_0069ead8_f32[];
#pragma alias DAT_0069eadc_f32 DAT_0069eadc
extern f32 DAT_0069eadc_f32[];
#pragma alias DAT_0069eae0_f32 DAT_0069eae0
extern f32 DAT_0069eae0_f32[];
#pragma alias DAT_0069eb18_f32 DAT_0069eb18
extern f32 DAT_0069eb18_f32[];
#pragma alias DAT_0069eb1c_f32 DAT_0069eb1c
extern f32 DAT_0069eb1c_f32[];
#pragma alias DAT_0069eb20_f32 DAT_0069eb20
extern f32 DAT_0069eb20_f32[];
extern u8 gp0xffff9fb8;
extern u8 gp0xffffa118;
extern u8 gp0xffffa120;
extern u8 gp0xffffa128;
extern u8 gp0xffffa160;
extern u8 gp0xffffa168;
extern u8 gp0xffffa170;
extern u8 gp0xffffa178;
extern u8 gp0xffffa180;
extern u8 gp0xffffa570;
#pragma alias gp0xffffa578_f32 gp0xffffa578
extern f32 gp0xffffa578_f32[];
#pragma alias gp0xffffa578_f32v gp0xffffa578
extern f32 gp0xffffa578_f32v;


extern u8 gp0xffffa580;
extern u8 gp0xffffa588;
extern u8 gp0xffffa590;
extern u8 gp0xffffa598;
extern u8 gp0xffffa5a0;
extern u8 gp0xffffa5a8;
extern u8 gp0xffffa5b0;
extern u8 gp0xffffa5b8;
extern u8 gp0xffffa5c0;
extern u8 gp0xffffa5c8;
extern u8 gp0xffffa5d0;
extern u8 gp0xffffa668;
extern u8 gp0xffffa670;
extern u8 gp0xffffa678;
extern u8 gp0xffffa680;
extern u8 gp0xffffa6e8;
extern u8 gp0xffffa0b8;
extern u8 gp0xffffa0c0;
extern u8 gp0xffffa3b8;
extern u8 gp0xffffa330;
extern u8 gp0xffffa600;
extern u8 gp0xffffa068;
extern u8 gp0xffffa6c8;
#pragma alias gp0xffffa3b8_arr gp0xffffa3b8
extern u8 gp0xffffa3b8_arr[];
extern u8 DAT_0069ffe0[];
#pragma alias DAT_0069ffe0_abs DAT_0069ffe0
extern u8 DAT_0069ffe0_abs[];
extern u8 gp0xffffa608;
extern u8 gp0xffffa610;
extern u8 gp0xffffa618;
extern u8 gp0xffffa460;
extern u8 gp0xffffa498;
extern u8 gp0xffffa4a0;
extern u8 gp0xffffa4a8;
extern u8 gp0xffffa4b0;
extern u8 gp0xffffa4c0;
extern u8 gp0xffffa4c8;
extern u8 gp0xffffa4d0;
extern u8 gp0xffffa4d8;
extern u8 gp0xffffa4e8;
extern u8 gp0xffffa4f0;
extern u8 gp0xffffa4f8;
extern u8 gp0xffffa500;
extern u8 gp0xffffa508;
extern u8 gp0xffffa510;
extern u8 gp0xffffa518;
extern u8 gp0xffffa630;
extern u8 gp0xffffa638;
extern u8 gp0xffffa640;
extern u8 gp0xffffa648;
extern u8 gp0xffffa688;
extern u8 gp0xffffa690;
extern u8 gp0xffffa698;
extern u8 gp0xffffa6a0;
extern u32 iGpffffb8f0;
extern u32 iGpffffb904;
extern u32 iGpffffb920;
extern u32 iGpffffb924;
extern char *s_1234567890A_0069f7c0;
#pragma alias s_1234567890A_0069f7c0_abs s_1234567890A_0069f7c0
extern u8 s_1234567890A_0069f7c0_abs[];
extern char *s_ADX_SE_MODE_0069db88;
extern char *s_BATTLE_BLUR_USE__0069ddf0;
extern char *s_BISTA_MODE_0069dca8;
extern char *s_B_UP_CONTROL_SELECT_0069dc10;
extern char *s_CAMERA_CONTROL_TYPE_0069dbd0;
extern char *s_COND_ON_SELECT_0069dd60;
extern char *s_CONFIG_DRAW_STOP_0069dc60;
extern char *s_CONTROL_TYPE_0069db98;
extern char *s_CUSTOM_EVENT_SELECT_0069dd40;
extern char *s_DELETE_FRAME_OK__0069db30;
extern char *s_EFFECT_MODE_0069dc38;
extern char *s_END_STOP_MODE_0069dcd8;
extern char *s_FADE_MODE_0069dcc8;
extern char *s_FADE_TYPE_0069db78;
extern char *s_FIELDOBJ_EDIT_PARAM_0069dd80;
extern char *s_FIELD_EDIT_GO__0069ddc0;
extern char *s_FIELD_EFFECT_MODE_0069dbf0;
extern char *s_FRAME_SET_OK__0069dda8;
extern char *s_HOKAN_MODE_0069db48;
extern char *s_KEYFREE_SELECT_0069dd20;
extern char *s_KOMA_MODE_0069dc28;
extern char *s_MESSAGE_STOP_0069dd08;
extern char *s_MESSAGE_TYPE_0069de08;
extern char *s_ON_OFF_MODE_0069db58;
extern char *s_PADACT_TYPE_0069dc48;
extern char *s_PATH_APPLY_MODE_0069e6e0;
extern char *s_PRIORITY_0069dcb8;
extern char *s_SELECT_MODE_0069dc98;
extern char *s_STAGE_0069f1b0;
extern char *s_TIMEI_FADE_DOWN_UP_0069dc80;
extern char *s_TRANS_MODE_0069db68;
extern char *s_UNIT_CONTROL_TYPE_0069dbb0;
extern char *s_VOICE_FILE_LOAD__0069ddd0;
extern char *s_WAIT_MODE_SELECT_0069dcf0;
extern u32 uGpffff841c;
extern u32 uGpffff9d78;
extern u32 uGpffff9d7c;
extern u32 uGpffffa4b8;
extern u32 uGpffffa4bc;
extern f32 uGpffffa628;
extern f32 uGpffffa62c;
extern u32 uGpffffa650;
extern u32 uGpffffa654;
#pragma alias gp0xffffa650_f32 uGpffffa650
extern f32 gp0xffffa650_f32;
#pragma alias gp0xffffa654_f32 uGpffffa654
extern f32 gp0xffffa654_f32;
extern u32 uGpffffb8ec;
extern u32 uGpffffb900;
extern u32 uGpffffb924;

u32 FUN_003b5d00(void);
bool FUN_0036d320(int param_1);
bool FUN_0036f480(void);
bool FUN_00372c40(int param_1);
#pragma alias FUN_00372c40_ptr FUN_00372c40
extern bool FUN_00372c40_ptr(int param_1);
code * FUN_0036e690(int param_1);
code * FUN_0036ed30(u64 param_1);
code * FUN_0036edd0(void);
code * FUN_0036ee30(void);
float FUN_0038a220(int param_1);
#pragma alias FUN_00523ac8_evt4 FUN_00523ac8
extern void FUN_00523ac8_evt4(u8 *param_1,const char *param_2,void *param_3,void *param_4);
float FUN_0038a900(int param_1);
int FUN_00361830(int param_1);
int FUN_00361ee0(int param_1,int param_2);
int FUN_00361f20(int param_1);
int FUN_00361f60(int param_1,int param_2);
int FUN_00361fe0(long param_1,int param_2);
int FUN_0036be60(u64 param_1,long param_2,u64 param_3);
int FUN_0036fda0(int param_1,int param_2,int param_3);
int FUN_00371dd0(int param_1,int param_2,int param_3);
int FUN_00372790(int param_1,int param_2,int param_3);
int FUN_00375000(int param_1,int param_2,int param_3);
int FUN_0037caf0(int param_1,int param_2,int param_3);
int FUN_0037d5d0(int param_1,int param_2,int param_3);
int FUN_0037e1b0(int param_1,int param_2,int param_3);
int FUN_0037ead0(int param_1,int param_2,int param_3);
int FUN_0037f3d0(int param_1,int param_2,int param_3);
int FUN_0037fae0(u64 param_1,u64 param_2,u64 param_3);
int FUN_00380200(int param_1,int param_2,int param_3);
int FUN_003806f0(int param_1,int param_2,int param_3);
int FUN_00380d70(int param_1,int param_2,int param_3);
int FUN_00381280(int param_1,int param_2,int param_3);
int FUN_003819b0(int param_1,int param_2,int param_3);
int FUN_003820e0(int param_1,int param_2,int param_3);
int FUN_00382500(int param_1,int param_2,int param_3);
int FUN_00382840(int param_1,int param_2,int param_3);
int FUN_00382d60(int param_1,int param_2,int param_3);
int FUN_00383360(int param_1,int param_2,int param_3);
int FUN_00383d80(int param_1,int param_2,int param_3);
int FUN_00384370(int param_1,int param_2,int param_3);
int FUN_00384780(int param_1,int param_2,int param_3);
int FUN_00385520(int param_1,int param_2,int param_3);
int FUN_003863c0(void);
int FUN_00388df0(int param_1,int param_2);
int FUN_0038a480(int param_1,int param_2,int param_3,int param_4);
long FUN_00361350(u64 param_1,u64 param_2,u64 param_3);
long FUN_00361ca0(int param_1,u64 param_2);
long FUN_00361dd0(int param_1,u64 param_2,u16 param_3,u32 param_4);
s32 FUN_00374af0(s32 param_1,s32 param_2,s32 param_3);
long FUN_00386ae0(u64 param_1,u64 param_2);
long FUN_0038ab00(int param_1,u64 param_2);
int FUN_0036f640(int param_1);
u16 * FUN_00362290(int param_1);
u16 * FUN_00362310(int param_1);
u16 * FUN_00364470(u32 param_1,int param_2);
u16 * FUN_003645c0(u32 param_1,int param_2);
u16 * FUN_003646d0(u32 param_1,int param_2);
u16 * FUN_00364b10(u32 param_1,int param_2);
u16 * FUN_003655f0(u32 param_1,int param_2);
u16 * FUN_00366540(u64 param_1,int param_2,long param_3,long param_4);
u32 FUN_00368d70(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_0036d470(long param_1);
u32 FUN_0036da10(int param_1);
u32 FUN_0036db20(int param_1);
u32 FUN_0036e260(int param_1);
u32 FUN_0036e2f0(int param_1);
u32 FUN_0036f4c0(void);
u32 FUN_00370230(int param_1,int param_2,int param_3);
u32 FUN_00371710(int param_1,int param_2,int param_3);
u32 FUN_00372260(int param_1,int param_2,int param_3);
u32 FUN_00373700(int param_1,int param_2,int param_3);
u32 FUN_00374c90(int param_1,int param_2,int param_3);
u32 FUN_00375350(int param_1,int param_2,int param_3);
u32 FUN_00375590(int param_1,int param_2,int param_3);
u32 FUN_003756e0(int param_1,int param_2,int param_3);
u32 FUN_00375900(int param_1,int param_2,int param_3);
u32 FUN_00375a40(int param_1,int param_2,int param_3);
u32 FUN_00375d70(int param_1,int param_2,int param_3);
u32 FUN_00375f30(int param_1,int param_2,int param_3);
u32 FUN_003798f0(int param_1,int param_2,int param_3);
u32 FUN_0037a150(int param_1,int param_2,u8 *param_3);
u32 FUN_0037a2b0(int param_1,int param_2,int param_3);
u32 FUN_0037a4d0(int param_1,int param_2,int param_3);
u32 FUN_0037acc0(int param_1,int param_2,int param_3);
u32 FUN_0037afc0(int param_1,int param_2,int param_3);
u32 FUN_0037b2e0(int param_1,int param_2,int param_3);
u32 FUN_0037b5d0(int param_1,int param_2,int param_3);
u32 FUN_0037ba80(int param_1,int param_2,int param_3);
u32 FUN_0037be50(int param_1,int param_2,int param_3);
u32 FUN_0037c2e0(int param_1,int param_2,int param_3);
u32 FUN_0037d4d0(int param_1,int param_2,int param_3);
u32 FUN_0037df50(int param_1,int param_2,int param_3);
u32 FUN_0037e3f0(int param_1,int param_2,int param_3);
u32 FUN_0037f050(int param_1,int param_2,int param_3);
u32 FUN_0037f5e0(int param_1,int param_2,int param_3);
u32 FUN_0037ff10(int param_1,int param_2,int param_3);
u32 FUN_00380310(int param_1,int param_2,int param_3);
u32 FUN_003809c0(int param_1,int param_2,int param_3);
u32 FUN_003810a0(int param_1,int param_2,int param_3);
u32 FUN_003814d0(int param_1,int param_2,int param_3);
u32 FUN_00381bf0(int param_1,int param_2,int param_3);
u32 FUN_00382320(int param_1,int param_2,int param_3);
u32 FUN_003826f0(int param_1,int param_2,int param_3);
u32 FUN_00382c10(int param_1,int param_2,int param_3);
u32 FUN_00382ec0(int param_1,int param_2,int param_3);
u32 FUN_00383810(int param_1,int param_2,int param_3);
u32 FUN_00384060(int param_1,int param_2,int param_3);
u32 FUN_003844b0(int param_1,int param_2,int param_3);
u32 FUN_003849e0(int param_1,int param_2,int param_3);
u32 FUN_00384d30(int param_1,int param_2,int param_3);
u32 FUN_003851f0(int param_1,int param_2,int param_3);
u32 FUN_00386cd0(void);
u32 FUN_00386e10(int param_1);
u32 FUN_00386e30(int param_1);
u32 FUN_0038a0b0(int param_1);
u32 FUN_0038a4b0(u64 param_1,int param_2,u32 *param_3,u32 *param_4);
u32 FUN_0038d6f0(long param_1);
u32 FUN_0038d980(void);
u32 FUN_0038e860(long param_1,u64 param_2);
u64 FUN_00366eb0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00366f90(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_003670f0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00367190(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00367230(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00367390(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00367440(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_003674b0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00367a20(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00367cb0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00367d70(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00367e00(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00367ec0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00368020(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_003680e0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_003682f0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_003683a0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00368440(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_003684d0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_003685c0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00368680(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00368710(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_003687b0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00368830(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_003688d0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_003689c0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00368a30(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00368b00(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00368c10(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00368cb0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00368f20(u64 param_1,long param_2,u64 param_3);
u64 FUN_00369320(u64 param_1,long param_2,u64 param_3);
u64 FUN_003698a0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00369a20(int param_1,u64 param_2,u64 param_3);
u64 FUN_0036be10(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_0036cc30(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_0036f500(int param_1);
u64 FUN_003709d0(int param_1,int param_2,u8 *param_3);
u32 FUN_003715b0(int param_1,int param_2,int param_3);
u64 FUN_00379f30(int param_1,int param_2,int param_3);
u32 FUN_0037a640(int param_1,int param_2,int param_3);
u32 FUN_0037abd0(int param_1,int param_2,int param_3);
u32 FUN_00385bd0(int param_1,u64 param_2);
u32 FUN_00385cd0(int param_1);
u32 FUN_00385e20(int param_1);
u32 FUN_00385f00(int param_1);
u32 FUN_00386060(int param_1);
u32 FUN_00386130(int param_1,f32 *param_2,f32 *param_3);
u32 FUN_00386230(int param_1,u32 *param_2,u32 *param_3);
u32 FUN_00386310(int param_1);
u32 FUN_00386430(int param_1,u16 param_2,u32 param_3);
u32 FUN_003865f0(int param_1);
u32 FUN_00386780(int param_1,u32 param_2,u32 param_3,u32 param_4);
u32 FUN_00386860(int param_1,u32 param_2,u32 param_3,u32 param_4);
u32 FUN_00386940(int param_1,int param_2,f32 param_3);
u32 FUN_00386a00(int param_1,u32 param_2);
u64 FUN_0038da10(u16 *param_1);
s8 FUN_0036fa40(int param_1);
u64 FUN_00373590(u64 param_1,u64 param_2,int param_3);
void FUN_00361050(int param_1,u32 param_2);
void FUN_00361070(u64 param_1);
void FUN_00361140(int param_1,u16 *param_2);
void FUN_00361200(int param_1,int param_2);
void FUN_00361270(long param_1);
void FUN_00361890(int *param_1,u64 param_2);
void FUN_00361980(u64 param_1);
void FUN_00361b60(int *param_1,int param_2);
void FUN_00361c30(int param_1,int param_2);
void FUN_00361d60(long param_1,u16 param_2,u32 param_3);
void FUN_00362100(void);
void FUN_00362110(void);
void FUN_00362120(long param_1,u64 param_2,int param_3);
void FUN_00362240(int param_1);
void FUN_00362390(u64 param_1);
void FUN_003625e0(u64 param_1);
#pragma alias FUN_003625e0_i FUN_003625e0
extern void FUN_003625e0_i(s32 param_1);
void FUN_003628f0(u64 param_1);
void FUN_00362f20(u64 param_1);
void FUN_00362fa0(int param_1);
void FUN_00362ff0(long param_1);
void FUN_00363030(int *param_1,u16 *param_2,u32 param_3,u64 param_4);
void FUN_003638e0(int *param_1,long param_2,long param_3,u32 param_4,u64 param_5);
void FUN_003648e0(int param_1,u32 param_2,int param_3);
void FUN_00364a30(u32 param_1,int param_2);
void FUN_00364e40(u32 param_1,int param_2,int param_3);
void FUN_003650c0(u32 param_1,u64 param_2,int param_3);
void FUN_00365250(u32 param_1,u64 param_2,int param_3);
void FUN_00365360(u32 param_1,u64 param_2,int param_3);
void FUN_00365430(int param_1,u64 param_2);
void FUN_003657e0(int param_1,u64 param_2);
void FUN_003658b0(u32 param_1,int param_2);
void FUN_00365a40(u32 param_1,int param_2);
void FUN_00365b70(u32 param_1,u64 param_2);
void FUN_00365cd0(u32 param_1,int param_2);
void FUN_00365f80(u32 param_1,long param_2);
void FUN_00366210(u32 param_1,int param_2);
void FUN_00366330(u32 param_1,int param_2);
void FUN_003663f0(u32 param_1,int param_2);
void FUN_00366660(u32 param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_00366970(u64 param_1,u64 param_2);
void FUN_00366ac0(u32 param_1,u64 param_2);
void FUN_0036d030(long param_1);
void FUN_0036efb0(void);
void FUN_0036f000(long param_1);
void FUN_0036f260(void);
void FUN_0036f370(int param_1);
void FUN_00350040(int param_1,u32 *param_2);
void FUN_003722d0(u32 param_1,u32 param_2,u32 param_3,u8 *param_4);
void FUN_0036f490(int param_1);
void FUN_0036f4d0(void);
void FUN_0036f5f0(u32 param_1,u16 param_2,u16 param_3,int param_4);
void FUN_0036f680(int param_1,int param_2,int param_3,int param_4,u64 param_5, int param_6,int param_7);
#pragma alias FUN_0036f680_ret FUN_0036f680
extern u32 FUN_0036f680_ret(int param_1,int param_2,int param_3,int param_4,
                            u64 param_5,int param_6,int param_7);
#pragma alias FUN_0036f680_ptr2 FUN_0036f680
extern void FUN_0036f680_ptr2(int param_1,u32 *param_2,int param_3,int param_4,
                              u64 param_5,int param_6,int param_7);
#pragma alias FUN_0036f680_ret_ptr2 FUN_0036f680
extern u32 FUN_0036f680_ret_ptr2(int param_1,u32 *param_2,int param_3,int param_4,
                                 u64 param_5,int param_6,int param_7);
void FUN_0036f900(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,int param_7,int param_8,code *param_9);
#pragma alias FUN_0036f900_evt FUN_0036f900
extern void FUN_0036f900_evt(int param_1,int param_2,int param_3,int param_4,
                             int param_5,int param_6,int param_7,code *param_8,
                             code *param_9);
void FUN_0036fa80(int param_1,int param_2,int param_3,int param_4);
void FUN_003702a0(int param_1,int param_2,int param_3,int param_4);
void FUN_00371350(int param_1,int param_2,int param_3,u8 *param_4);
void FUN_00371790(int param_1,int param_2,u32 param_3,u8 *param_4);
void FUN_003722d0(u32 param_1,u32 param_2,u32 param_3,u8 *param_4);
void FUN_003747a0(int param_1,int param_2,int param_3,int param_4);
void FUN_00374d30(int param_1,int param_2,u32 param_3,u8 *param_4);
void FUN_003753c0(int param_1,int param_2,u32 param_3,u8 *param_4);
void FUN_00375750(int param_1,int param_2,u32 param_3,u8 *param_4);
void FUN_00375ab0(int param_1,int param_2,u32 param_3,u8 *param_4);
void FUN_003760a0(int param_1,int param_2,u32 param_3,u16 *param_4,int param_5);
void FUN_003797b0(int param_1,int param_2,int param_3,int param_4);
void FUN_00379c30(int param_1,int param_2,int param_3,int param_4);
void FUN_0037a1e0(int param_1,int param_2,int param_3,int param_4);
void FUN_0037a560(int param_1,int param_2,int param_3,int param_4);
void FUN_0037a790(int param_1,int param_2,int param_3,int param_4);
void FUN_0037ad30(int param_1,int param_2,int param_3,int param_4);
void FUN_0037b350(int param_1,int param_2,int param_3,int param_4);
void FUN_0037baf0(int param_1,int param_2,int param_3,int param_4);
void FUN_0037c350(int param_1,int param_2,int param_3,int param_4);
void FUN_0037cf50(u32 *param_1,u32 *param_2,u32 *param_3);
void FUN_0037cfe0(void);
void FUN_0037d540(int param_1,int param_2,long param_3,int param_4);
void FUN_0037e460(u32 param_1,u32 param_2,u32 param_3,u8 *param_4);


void FUN_0037f0c0(int param_1,int param_2,int param_3,int param_4);
void FUN_0037f650(int param_1,int param_2,u32 param_3,u8 *param_4);
void FUN_0037ff80(int param_1,int param_2,int param_3,int param_4);
void FUN_00380380(int param_1,int param_2,u32 param_3,u8 *param_4);
void FUN_00380a30(int param_1,int param_2,int param_3,int param_4);
void FUN_00381110(int param_1,int param_2,int param_3,int param_4);
void FUN_00381540(int param_1,int param_2,u32 param_3,u8 *param_4);
int FUN_00382d60(int param_1,int param_2,int param_3);
void FUN_00382390(int param_1,int param_2,int param_3,int param_4);
void FUN_00382760(int param_1,int param_2,int param_3,int param_4);
void FUN_00382c80(int param_1,int param_2,int param_3,int param_4);
void FUN_00382f30(int param_1,int param_2,int param_3,int param_4);
void FUN_00383880(int param_1,int param_2,int param_3,int param_4);
void FUN_003840d0(int param_1,int param_2,int param_3,int param_4);
void FUN_00384520(int param_1,int param_2,int param_3,int param_4);
void FUN_00384a50(int param_1,int param_2,int param_3,int param_4);
void FUN_00385260(int param_1,int param_2,int param_3,int param_4);
void FUN_003858c0(int param_1);
void FUN_00385990(u32 param_1,int param_2,int param_3,int param_4,u32 param_5, f32 param_6);
#pragma alias FUN_00385990_f32 FUN_00385990
extern void FUN_00385990_f32(u32 param_1,int param_2,int param_3,int param_4,
                              int param_5,f32 param_6);
void FUN_00100710(u32 task,RwV2d pos);
void FUN_00100740(u32 task,RwRect rect);
void FUN_00100770(u32 task,f32 zOffset);
void FUN_00100780(u32 task,RwRGBA color);
void FUN_00385b20(int param_1);
void FUN_00385b90(void);
void FUN_00385ba0(void);
void FUN_00386110(u32 *param_1,u32 *param_2);
void FUN_00386210(u32 *param_1,u32 *param_2);
void FUN_00386390(u32 *param_1,u32 *param_2,u32 *param_3,u32 *param_4);
void FUN_00386aa0(void);
void FUN_00386b70(u64 param_1,long param_2,int param_3);
void FUN_00386c40(int param_1,int param_2);
void FUN_00386d50(int param_1);
void FUN_00386e20(int param_1,u32 param_2);
void FUN_00386e40(int param_1,u32 param_2);
void FUN_00386e50(void);
void FUN_00386f70(float param_1,float *param_2,float *param_3,u8 *param_4);
void FUN_003877c0(float param_1,int param_2,int param_3,u32 *param_4,u8 *param_5);
void FUN_00388000(float param_1,u32 param_2,float *param_3,float *param_4,u32 *param_5 ,u32 *param_6,u32 *param_7,u8 *param_8,long param_9);
void FUN_00388a40(float param_1,float *param_2,float *param_3,u8 *param_4);
void FUN_00388ff0(int param_1);
void FUN_003890e0(int param_1);
void FUN_003897f0(int param_1);
void FUN_00389b50(int *param_1);
void FUN_00389d80(int param_1,int param_2);
void FUN_00389f40(void);
void FUN_0038a0c0(int param_1,long param_2);
void FUN_0038a140(u32 param_1,u32 *param_2);
void FUN_0038a180(int param_1,int param_2);
#pragma alias evtMenuDrawText FUN_0038a260
extern void evtMenuDrawText(s32 x, s32 y, f32 depth, s32 color,
                            const char *format, ...);
#pragma alias FUN_003185b0_evt_u32 FUN_003185b0
extern u32 FUN_003185b0_evt_u32(u32 param_1,u16 param_2);
#pragma alias FUN_00318620_evt_u32 FUN_00318620
extern u32 FUN_00318620_evt_u32(u32 param_1,u16 param_2,s16 param_3);
#pragma alias FUN_00530da0_evt FUN_00530da0
extern u32 FUN_00530da0_evt(f32 param_1);

u32 FUN_00397870(int param_1,long param_2,u32 *param_3,u32 *param_4,u32 *param_5,u32 *param_6);
#pragma alias FUN_00397870_i FUN_00397870
extern u32 FUN_00397870_i(int param_1,int param_2,u32 *param_3,u32 *param_4,u32 *param_5,u32 *param_6);
void FUN_0038a590(int param_1,long param_2);
void FUN_0038a620(int param_1,long param_2);
void FUN_0038a6c0(int param_1);
void FUN_0038a730(int param_1);
void FUN_0038a7c0(u32 *param_1,u32 *param_2);
#pragma alias FUN_0038a7c0_vec FUN_0038a7c0
void FUN_0038a7c0_vec(EvtVec3 *param_1,EvtVec3 *param_2);
#pragma alias FUN_001acc30_vec FUN_001acc30
u32 FUN_001acc30_vec(EvtRay *param_1,EvtVec3 *param_2);
#pragma alias FUN_003bb9b0_vec FUN_003bb9b0
void FUN_003bb9b0_vec(EvtVec3 *param_1);
#pragma alias FUN_003b79a0_vec FUN_003b79a0
void FUN_003b79a0_vec(u8 *param_1,EvtVec3 *param_2,EvtVec3 *param_3);
void FUN_0038a920(int param_1,u16 *param_2,int param_3);
void FUN_0038af70(u16 *param_1);
void FUN_0038b140(long param_1);
void FUN_0038b2c0(u16 *param_1,u32 *param_2,u32 *param_3,u32 *param_4, long param_5);
void FUN_0038b550(long param_1,u32 *param_2,u32 *param_3,u32 *param_4);
void FUN_0038b600(u32 *param_1,u32 *param_2);
void FUN_0038b6e0(u64 param_1,int param_2,int param_3);
void FUN_0038b960(int param_1,long param_2,short param_3);
void FUN_0038bc70(int param_1,short param_2,int param_3);
void FUN_0038c460(long param_1,int param_2,int *param_3,u32 *param_4);
void FUN_0038c540(int param_1,u64 param_2,u64 param_3,u64 param_4, u32 *param_5,u32 *param_6);
void FUN_0038c830(u64 param_1,long param_2);
void FUN_0038ca00(void);
void FUN_0038ca80(u64 param_1);
void FUN_0038cc10(int param_1,u16 *param_2,long param_3);
void FUN_0038d560(long param_1,long param_2,u32 param_3,u32 *param_4, u32 *param_5,u32 *param_6);
void FUN_0038d6b0(long param_1,u32 param_2);
void FUN_0038d720(int param_1);
void FUN_0038d790(int param_1);
void FUN_0038d840(char *param_1,u8 *param_2,int param_3);
void FUN_0038d910(u64 param_1);
void FUN_0038dad0(u32 param_1,long param_2,u64 param_3);
void FUN_0038e660(u64 param_1,int param_2,int param_3);
void FUN_0038f0f0(u64 param_1);
void FUN_0038f440(int param_1,u64 param_2,int param_3);
void FUN_0038f8c0(long param_1,u64 param_2,long param_3,short param_4);
void FUN_0038fa10(int param_1,u64 param_2);
void FUN_0038ffb0(int param_1,u64 param_2);

extern u8 DAT_006a0000[];
#pragma alias DAT_006a0000_abs DAT_006a0000
extern u8 DAT_006a0000_abs[];
#pragma push
#pragma opt_propagation off
// FUN_0036F500


u64 FUN_0036f500(int param_1)



{

  extern void FUN_0019d3f0(const char *,int);
  u64 uVar1;

  int iVar2;

  char *pcVar3;
  char *pcVar4;

  int iVar5;
  int iVar6;
  int iVar7;
  int lVar4;

  

  if (param_1 < 0x33) goto valid_param;
  FUN_0019d3f0((const char *)(DAT_006a0000 - 0x1bf8),0xa0);
valid_param:
  ;

  iVar2 = param_1 * 0xc;

  pcVar3 = (char *)(DAT_006a0000 - 0x1e56) + iVar2;

  if (*pcVar3 == '\x01') {

    uVar1 = 1;

  }

  else if (*pcVar3 == '\x02') {

    uVar1 = 0;

  }

  else {
    lVar4 = 0;
    pcVar4 = (char *)(DAT_006a0000 - 0x1e60) + iVar2;
    iVar5 = *(short *)pcVar4;
    iVar7 = 0x12;


    for (; lVar4 < iVar5; lVar4 = lVar4 + 1) {

      iVar6 = *(char *)(pcVar4 + lVar4 + 2);
      if (iVar6 != iVar7) {
        continue;
      }

      *pcVar3 = '\x01';
      return 1;

    }

    *pcVar3 = '\x02';
    uVar1 = 0;

  }

  return uVar1;

}
#pragma pop


// FUN_0036F5F0


void FUN_0036f5f0(u32 param_1,u16 param_2,u16 param_3,int param_4)



{

  int iVar1;

  

  iVar1 = *(int *)(param_4 + 0xd0) + 1;

  *(int *)(param_4 + 0xd0) = iVar1;

  iVar1 = iVar1 * 8;
  *(short *)(iVar1 + param_4 + 0x90) = (short)(param_1 & 0xff);
  iVar1 = *(int *)(param_4 + 0xd0) * 8;
  *(u16 *)(iVar1 + param_4 + 0x92) = param_2;
  iVar1 = *(int *)(param_4 + 0xd0) * 8;
  *(u16 *)(iVar1 + param_4 + 0x94) = param_3;

  *(u32 *)(param_4 + 0xd4) = param_1 & 0xff;

  return;

}


// FUN_0036F640


int FUN_0036f640(int param_1)



{

  int sVar1;

  int iVar2;

  

  if (*(int *)((u8 *)param_1 + 0xd0) == 0) {

    *(u32 *)(param_1 + 0xd4) = 0;

    sVar1 = 0;

  }

  else {

    iVar2 = *(int *)(param_1 + 0xd0) + -1;

    *(int *)(param_1 + 0xd0) = iVar2;

    iVar2 = iVar2 * 8;
    iVar2 += param_1;

    sVar1 = *(short *)(iVar2 + 0x90);

    *(int *)(param_1 + 0xd4) = (int)sVar1;

  }

  return sVar1;

}


extern u8 DAT_007e0000[];
// Force absolute addressing to match retail's DAT_007e0000 accesses.
#pragma alias DAT_007e0000_abs DAT_007e0000
extern u8 DAT_007e0000_abs[];
// FUN_0036F680


void FUN_0036f680(int param_1,int param_2,int param_3,int param_4,u64 param_5,

                 int param_6,int param_7)



{

  int *piVar1;

  int *piVar2;

  

  if ((param_2 != 0) && (1 < param_3)) {

    piVar2 = (int *)param_2;

    piVar1 = (int *)param_1;

    if ((*(u16 *)(DAT_007e0000_abs + 0x94e) & param_7) != 0) {
      if (param_1 == 0) {
        if (0 < *piVar2) {
          *piVar2 = *piVar2 + -1;
        }
        else if (param_3 < param_4) {
          *piVar2 = param_3 + -1;
        }
        else {
          *piVar2 = param_4 + -1;
        }
      }
      else if (0 < *piVar2) {
        *piVar2 = *piVar2 + -1;
      }
      else if (0 < *piVar1) {
        *piVar1 = *piVar1 + -1;
      }
      else if (param_4 < param_3) {
        *piVar1 = param_3 - param_4;
        *piVar2 = param_4 + -1;
      }
      else {
        *piVar2 = param_3 + -1;
      }
    }
    else if ((*(u16 *)(DAT_007e0000_abs + 0x952) & param_7) != 0) {
      if (param_1 == 0) {
        if (0 < *piVar2) {
          *piVar2 = *piVar2 + -1;
        }
      }
      else if (0 < *piVar2) {
        *piVar2 = *piVar2 + -1;
      }
      else if (0 < *piVar1) {
        *piVar1 = *piVar1 + -1;
      }
    }
    if ((*(u16 *)(DAT_007e0000_abs + 0x94e) & param_6) != 0) {
      if (param_1 == 0) {
        if (*piVar2 < param_4 + -1) {
          *piVar2 = *piVar2 + 1;
        }
        else {
          *piVar2 = 0;
        }
      }
      else if (*piVar2 < param_4 + -1) {
        *piVar2 = *piVar2 + 1;
      }
      else if (*piVar1 + param_4 < param_3) {
        *piVar1 = *piVar1 + 1;
      }
      else {
        *piVar1 = 0;
        *piVar2 = 0;
      }
    }
    else if ((*(u16 *)(DAT_007e0000_abs + 0x952) & param_6) != 0) {
      if (param_1 == 0) {
        if (*piVar2 < param_4 + -1) {
          *piVar2 = *piVar2 + 1;
        }
      }
      else if (*piVar2 < param_4 + -1) {
        *piVar2 = *piVar2 + 1;
      }
      else if (*piVar1 + param_4 < param_3) {
        *piVar1 = *piVar1 + 1;
      }
    }

  }

  return;

}


// FUN_0036F900 NONMATCHING


void FUN_0036f900(int param_1,int param_2,int param_3,int param_4,int param_5,
                 int param_6,int param_7,int param_8,code *param_9)



{

  int iVar1;
  int iVar2;


  

  iVar1 = 0;

  FUN_00385990_f32(param_7,(int)param_1 * 0xc,param_2 * 0xc,param_3 * 0xc,
                   param_4 * 0xc,(float)FUN_0038a220(*(u32 *)((int)param_7 + 0xe0)) + 1.0f);

  if (param_8 != 0) {
    iVar2 = ((code)param_8)(param_1,param_2,param_7);
    param_2 = param_2 + iVar2;
    iVar1 = iVar1 + iVar2;
  }

  for (; iVar1 < param_4; iVar1 = iVar1 + 1) {
    if (param_9 != (code *)0x0) {
      ((code)param_9)(param_1,param_2,param_5,param_7);
      param_5 = param_5 + 1;
      param_2 = param_2 + 1;
    }
  }
  return;

}


// FUN_0036FA40


s8 FUN_0036fa40(int object)
{
    s32 index = **(s32**)(object + 0x164);
    s8* entry;

    index *= 3;
    entry = DAT_0069e422 + index * 4;
    return *(entry + *(s32*)(object + 0x268));
}


// FUN_0036FA80 NONMATCHING


void FUN_0036fa80(int param_1,int param_2,int param_3,int param_4)



{


  char cVar2;
  int *piVar3;
  int iVar6;
  int iVar11;
  s32 lVar8;
  int iVar9;
  f32 uVar10;

  

  iVar9 = 0;

  piVar3 = *(int **)(param_4 + 0x164);

  if (param_3 != 1) {
    switch (param_3) {
    case 0:

    lVar8 = 0;
    iVar11 = param_2 * 0xc;
    iVar6 = (param_2 + 1) * 0xc;

    for (; lVar8 < *(short *)(DAT_0069e420_abs + *piVar3 * 0xc);

        lVar8 = lVar8 + 1) {
      int iVar5;
      s32 uVar7;
      s32 cVar1;
      
      

      cVar1 = *(char *)((int)(DAT_0069e420_abs + *piVar3 * 0xc) + (int)lVar8 + 2);

      iVar5 = (param_1 + iVar9) * 0xc;

      uVar10 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));

      evtMenuDrawText(iVar5, iVar11, uVar10, 0xe, (const char *)PTR_s_OFFSET_0069e6a0_abs[cVar1]);

      if ((lVar8 == *(int *)(param_4 + 0x268)) && (*(int *)(param_4 + 0xd4) == 0xf)) {

        uVar7 = 4;

      }

      else {

        uVar7 = 0;

      }

      switch (cVar1) {
      case '\0':
        uVar10 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
        evtMenuDrawText(iVar5, iVar6, uVar10, uVar7, (const char *)&gp0xffffa060, *(short *)(*(int *)(param_4 + 0x164) + 0x20));
        break;

      case '\x01': {
        int *piVar4;
        piVar4 = *(int **)(param_4 + 0x164);
        cVar2 = *(char *)((u8 *)piVar4 + 0x22);
        if (cVar2 < '\x03') {
          uVar10 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
          evtMenuDrawText(iVar5, iVar6, uVar10, uVar7, (const char *)&gp0xffffa068, (u32)PTR_s_DISABLE_0069e6c8_abs[cVar2]);
        }
        else {
          uVar10 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
          evtMenuDrawText(iVar5, iVar6, uVar10, uVar7, (const char *)&gp0xffffa070, *(u16 *)((u8 *)piVar4 + 0x24));
        }
        break;
      }

      case '\x02':
        if (*(char *)(*(int *)(param_4 + 0x164) + 0x22) == '\0') {
          uVar10 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
          evtMenuDrawText(iVar5, iVar6, uVar10, uVar7, (const char *)&gp0xffffa070 + 8);
        }
        else {
          uVar10 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
          evtMenuDrawText(iVar5, iVar6, uVar10, uVar7, (const char *)&gp0xffffa070 + 0x10);
        }
        break;

      case '\x03':
        uVar10 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
        evtMenuDrawText(iVar5, iVar6, uVar10, uVar7, (const char *)&gp0xffffa060, *(char *)(*(int *)(param_4 + 0x164) + 0x22));
        break;
      }

      iVar9 = iVar9 + (char)(&DAT_007ccd20)[cVar1];

    }

      break;
    }
  }

  return;

}


// FUN_0036FDA0 NONMATCHING


int FUN_0036fda0(int param_1,int param_2,int param_3)



{

  char cVar1;

  short sVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  

  iVar5 = (int)param_3;

  piVar3 = *(int **)(iVar5 + 0x164);

  if (piVar3 == (int *)0x0) {

    iVar5 = 0;

  }

  else if (*(short *)(DAT_0069e420_abs + *piVar3 * 0xc) == 0) {

    iVar5 = 0;

  }

  else {

    FUN_0036f900(param_1,param_2,0x1c,3,0,1,param_3,0,(code *)FUN_0036fa80);

    if (*(int *)(iVar5 + 0xd4) != 0xf) {

      iVar5 = 0;

    }

    else {

      sVar2 = *(short *)(DAT_0069e420_abs + *piVar3 * 0xc);

      if (((long)sVar2 <= (long)*(int *)(iVar5 + 0x268)) && (0 < (long)sVar2)) {

        *(int *)(iVar5 + 0x268) = sVar2 + -1;

      }

      iVar6 = *piVar3 * 0xc;

      iVar4 = *(int *)(iVar5 + 0x268);

      cVar1 = DAT_0069e422_abs[iVar4 + iVar6];

      if ((*(u16 *)DAT_007e094e_abs & 0x2000) == 0) {
        if ((*(u16 *)DAT_007e094e_abs & 0x8000) == 0) {
          if ((*(u16 *)DAT_007e094e_abs & 0x40) != 0) {

            if (cVar1 == '\x03') {

              *(int *)(iVar5 + 0x16c) = (int)*(char *)(*(int *)(iVar5 + 0x164) + 0x22);

              *(u32 *)(iVar5 + 0x170) = 0xffffffff;

              *(u32 *)(iVar5 + 0x174) = 4;

              iVar4 = *(int *)(iVar5 + 0xd0) + 1;

              *(int *)(iVar5 + 0xd0) = iVar4;

              *(u16 *)(iVar4 * 8 + iVar5 + 0x90) = 7;

              *(u16 *)(*(int *)(iVar5 + 0xd0) * 8 + iVar5 + 0x92) = 0xf;

              *(u16 *)(*(int *)(iVar5 + 0xd0) * 8 + iVar5 + 0x94) = 10;

              *(u32 *)(iVar5 + 0xd4) = 7;

            }

            else if (cVar1 == '\x02') {

              *(int *)(iVar5 + 0x118) = (int)*(char *)(*(int *)(iVar5 + 0x164) + 0x22);

              *(u32 *)(iVar5 + 0x11c) = 2;

              *(char **)(iVar5 + 0x120) = s_PATH_APPLY_MODE_0069e6e0;

              *(u8 ***)(iVar5 + 0x124) = &PTR_s_SOUTAI_007ccd78;

              iVar4 = *(int *)(iVar5 + 0xd0) + 1;

              *(int *)(iVar5 + 0xd0) = iVar4;

              *(u16 *)(iVar4 * 8 + iVar5 + 0x90) = 2;

              *(u16 *)(*(int *)(iVar5 + 0xd0) * 8 + iVar5 + 0x92) = 0x12;

              *(u16 *)(*(int *)(iVar5 + 0xd0) * 8 + iVar5 + 0x94) = 10;

              *(u32 *)(iVar5 + 0xd4) = 2;

            }

            else if (cVar1 == '\x01') {

              *(u32 *)(iVar5 + 0x108) = 0;

              *(u32 *)(iVar5 + 0x110) = 0;

              iVar4 = *(int *)(iVar5 + 0xd0) + 1;

              *(int *)(iVar5 + 0xd0) = iVar4;

              *(u16 *)(iVar4 * 8 + iVar5 + 0x90) = 0x11;

              *(u16 *)(*(int *)(iVar5 + 0xd0) * 8 + iVar5 + 0x92) = 0xf;

              *(u16 *)(*(int *)(iVar5 + 0xd0) * 8 + iVar5 + 0x94) = 10;

              *(u32 *)(iVar5 + 0xd4) = 0x11;

            }

            else if (cVar1 == '\0') {

              *(int *)(iVar5 + 0x16c) = (int)*(short *)(*(int *)(iVar5 + 0x164) + 0x20);

              *(u32 *)(iVar5 + 0x170) = 0;

              *(int *)(iVar5 + 0x174) = *(int *)(iVar5 + 0xc) + -1;

              iVar4 = *(int *)(iVar5 + 0xd0) + 1;

              *(int *)(iVar5 + 0xd0) = iVar4;

              *(u16 *)(iVar4 * 8 + iVar5 + 0x90) = 7;

              *(u16 *)(*(int *)(iVar5 + 0xd0) * 8 + iVar5 + 0x92) = 0xf;

              *(u16 *)(*(int *)(iVar5 + 0xd0) * 8 + iVar5 + 0x94) = 10;

              *(u32 *)(iVar5 + 0xd4) = 7;

            }

            return 1;

          }

          if ((*(u16 *)DAT_007e094e_abs & 0x1000) != 0) {

            if (iVar4 != 0) {

              *(u32 *)(iVar5 + 0x158) = 1;

            }

            else {

              *(u32 *)(iVar5 + 0x158) = 0;

            }

            iVar6 = 0;

            for (iVar4 = piVar3[0x1b]; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x4c)) {

              iVar6 = iVar6 + 1;

            }

            if (iVar6 + -0x14 >= 0) {

              *(int *)(iVar5 + 0x160) = iVar6 + -0x13;

              *(u32 *)(iVar5 + 0x15c) = 0x13;

            }

            else {

              *(u32 *)(iVar5 + 0x160) = 0;

              *(int *)(iVar5 + 0x15c) = iVar6;

            }

            return -1;

          }

          if ((*(u16 *)DAT_007e094e_abs & 0x4000) != 0) {

            if (iVar4 != 0) {

              *(u32 *)(iVar5 + 0x158) = 1;

            }

            else {

              *(u32 *)(iVar5 + 0x158) = 0;

            }

            *(u32 *)(iVar5 + 0x160) = 0;

            *(u32 *)(iVar5 + 0x15c) = 0;

            return -1;

          }

        }

        else if (iVar4 < 1) {

          if (*(short *)(DAT_0069e420_abs + iVar6) != 0) {

            iVar4 = *(short *)(DAT_0069e420_abs + iVar6) + -1;

          }

          else {

            iVar4 = 0;

          }

          *(int *)(iVar5 + 0x268) = iVar4;

        }

        else {

          *(int *)(iVar5 + 0x268) = iVar4 + -1;

        }

      }

      else if (iVar4 < *(short *)(DAT_0069e420_abs + iVar6) + -1) {

        *(int *)(iVar5 + 0x268) = iVar4 + 1;

      }

      else {

        *(u32 *)(iVar5 + 0x268) = 0;

      }

      iVar5 = -(u32)((*(u16 *)DAT_007e094e_abs & 0x20) != 0);

    }

  }

  return iVar5;

}


// FUN_00370230


u32 FUN_00370230(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069e6f0);

  return 2;

}


/* opt_common_subs off: default nd919/1840B -> nd274/1836B; retained. */
#pragma opt_common_subs off
/* opt_lifetimes on: default nd274/1836B -> nd134/1836B; retained. */
#pragma push
#pragma opt_lifetimes on
// FUN_003702A0 NONMATCHING


void FUN_003702a0(int param_1,int param_2,int param_3,int param_4)



{

  int lVar1;

  int iVar2;

  u32 uVar3;

  u32 uVar4;

  int iVar5;

  int iVar6;

  u32 uVar7;

  u32 uVar9;

  f32 uVar8;

  u8 *apuStack_30 [8];

  u32 uStack_10;

  u32 uStack_c;

  u32 uStack_8;

  u32 uStack_4;

  

  uVar3 = 0;

  iVar6 = 0;

  apuStack_30[4] = PTR_s_REPEAT_007ccd88;
  apuStack_30[5] = PTR_DAT_007ccd8c;

  apuStack_30[2] = PTR_s_DIRECT_007ccda0;

  apuStack_30[3] = PTR_DAT_007ccda4;

  apuStack_30[0] = PTR_s_FALSE_007ccdb8;

  apuStack_30[1] = PTR_DAT_007ccdbc;

  iVar2 = (int)param_4;

  uVar9 = *(u32 *)(*(int *)(iVar2 + 0x23c) + 0x128);

  FUN_00521408(&uStack_4,0,4);

  uStack_4 = *(u32 *)(iVar2 + 0x16c);

  if (*(int *)(iVar2 + 0x21c) == param_3) {

    uVar3 = 4;

  }

  for (uVar4 = 0; (int)uVar4 < 4; uVar4 = uVar4 + 1) {

    lVar1 = FUN_003185b0_evt_u32(uVar9,uVar4 & 0xffff);

    if (lVar1 == 1) {

      iVar6 = iVar6 + 1;

    }

  }

  uVar7 = (u32)(char)uStack_4;

  iVar5 = *(int *)(iVar2 + 0x19c);

  switch(param_3) {

  case 0:

    uVar8 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar8, uVar3, (const char *)0x69e708, apuStack_30[iVar5 + 2]);

    break;

  case 1:

    if (iVar5 == 0) {

      uVar8 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar8, uVar3, (const char *)0x69e720, uVar7, iVar6);

    }

    else if (iVar5 == 1) {

      uVar8 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar8, uVar3, (const char *)0x69e740);

    }

    break;

  case 2:

    if (iVar5 == 0) {

      iVar6 = 0;

      for (iVar5 = 0; iVar5 < 0x40; iVar5 = iVar5 + 1) {

        lVar1 = FUN_00318620_evt_u32(uVar9,uVar7 & 0xffff,(short)iVar5);

        if (lVar1 == 1) {

          iVar6 = iVar6 + 1;

        }

      }

      uVar8 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar8, uVar3, (const char *)0x69e750, (((u8 *)&uStack_4)[1]), iVar6);

    }

    else if (iVar5 == 1) {

      lVar1 = FUN_003976f0(param_4,(((u8 *)&uStack_4)[1]),&uStack_8,&uStack_c);

      if (lVar1 == 1) {

        uVar8 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar8, uVar3, (const char *)0x69e770, (((u8 *)&uStack_4)[1]), uStack_8, uStack_c);

      }

      else {

        uVar8 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar8, uVar3, (const char *)0x69e790, (((u8 *)&uStack_4)[1]));

      }

    }

    break;

  case 3:

    uVar8 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar8, uVar3, (const char *)0x69e7a8, apuStack_30[(((u8 *)&uStack_4)[2]) + 4]);

    break;

  case 4:

    uVar8 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar8, uVar3, (const char *)0x69e7b8, (((u8 *)&uStack_4)[3]));

    break;

  case 5:

    uVar8 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar8, uVar3, (const char *)0x69e7c8, *(u32 *)(iVar2 + 0x198));

    break;

  case 6:

    uVar8 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar8, uVar3, (const char *)0x69e7d8, *(u32 *)(iVar2 + 0x1b0));

    break;

  case 7:

    iVar6 = *(int *)(iVar2 + 0x1a0);

    if (iVar6 < 2) {

      uVar8 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar8, uVar3, (const char *)0x69e7e8, apuStack_30[iVar6]);

    }

    break;

  case 8:

    if (iVar5 == 0) {

      uVar8 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar8, uVar3, (const char *)0x69e7f8, *(u32 *)(iVar2 + 0x1a4));

    }

    else if (iVar5 == 1) {

      lVar1 = FUN_003976f0(param_4,*(u32 *)(iVar2 + 0x1a4),&uStack_10,apuStack_30 + 7);

      if (lVar1 == 1) {

        uVar8 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar8, uVar3, (const char *)0x69e810, *(u32 *)(iVar2 + 0x1a4), uStack_10, apuStack_30[7]);

      }

      else {

        uVar8 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar8, uVar3, (const char *)0x69e830, *(u32 *)(iVar2 + 0x1a4));

      }

    }

    break;

  case 9:

    iVar6 = *(int *)(iVar2 + 0x1a8);

    if (iVar6 < 2) {

      uVar8 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar8, uVar3, (const char *)0x69e848, apuStack_30[iVar6 + 4]);

    }

    break;

  case 10:

    uVar8 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar8, uVar3, (const char *)0x69e858, *(u32 *)(iVar2 + 0x1ac));

    break;

  case 0xb:

    uVar8 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar8, uVar3, (const char *)0x69e868, *(u32 *)(iVar2 + 0x1b4));

  }

  return;

}
#pragma pop
#pragma opt_common_subs reset


/* opt_loop_invariants on: default nd1738/2420B -> nd1719/2424B; retained. */
#pragma opt_loop_invariants on
// FUN_003709D0 NONMATCHING


u64 FUN_003709d0(int param_1,int param_2,u8 *param_3)



{

  int iVar2;

  int iVar1;

  u64 uVar3;

  int lVar4;

  int lVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  u8 uVar9;

  union {
    u32 raw;
    struct {
      s8 type;
      s8 index;
      s8 enabled;
      s8 volume;
    } fields;
  } selection;

  

  iVar2 = 0;

  iVar6 = 0;
  FUN_00521408(&selection,0,4);



  iVar7 = (int)param_3;


  if (*(int *)(iVar7 + 0x23c) == 0) {

    return 0xffffffffffffffff;

  }

  iVar1 = *(int *)(*(int *)(iVar7 + 0x23c) + 0x128);

  
  if (*(int *)(iVar7 + 0x19c) >= 2) {
  
    *(u32 *)(iVar7 + 0x19c) = 0;
  
  }
  
  FUN_0036f900(param_1,param_2,0x19,0xf,0,1,(int)param_3,0x370230,0);
  
  if (*(int *)(iVar7 + 0xd4) != 0x10) {
  
    uVar3 = 0;
  
  }
  
  else {
  
    if ((DAT_007e0952 & 0x1000) == 0) {
  
      if ((DAT_007e0952 & 0x4000) != 0) {
  
        if (*(int *)(iVar7 + 0x21c) != 0xb) {
  
          *(int *)(iVar7 + 0x21c) = *(int *)(iVar7 + 0x21c) + 1;
  
        }
  
        else {
  
          *(u32 *)(iVar7 + 0x21c) = 0;
  
        }
  
      }
  
    }
  
    else if (*(int *)(iVar7 + 0x21c) == 0) {
  
      *(u32 *)(iVar7 + 0x21c) = 0xb;
  
    }
  
    else {
  
      *(int *)(iVar7 + 0x21c) = *(int *)(iVar7 + 0x21c) + -1;
  
    }
  
    selection.raw = *(u32 *)(iVar7 + 0x16c);

    uVar9 = selection.fields.type;
  
    if (iVar1 != 0) {
  
      iVar6 = 0;
  
      for (iVar8 = 0; iVar8 < 0x40; iVar8 = iVar8 + 1) {
  
        lVar5 = FUN_00318620_evt_u32(iVar1,uVar9,(s16)iVar8);
  
        if (lVar5 == 1) {
  
          iVar6 = iVar6 + 1;
  
        }
  
      }
  
    }
  
    iVar8 = *(int *)(iVar7 + 0x19c);
  
    if (iVar8 == 1) {
  
      selection.fields.type = 0;
  
    }
  
    switch(*(u32 *)(iVar7 + 0x21c)) {
  
    case 0:
  
      if ((DAT_007e0952 & 0x2000) != 0) {
  
        if (iVar8 >= 1) {
  
          iVar8 = 0;
  
        }
  
        else {
  
          iVar8 = iVar8 + 1;
  
        }
  
        selection.fields.type = 0;
        selection.fields.index = 0;
  
        *(u32 *)(iVar7 + 0x1a0) = 0;
  
        *(u32 *)(iVar7 + 0x1a4) = 0;
  
        *(u32 *)(iVar7 + 0x1a8) = 0;
  
        *(u32 *)(iVar7 + 0x1ac) = 0;
  
      }
  
      if ((DAT_007e0952 & 0x8000) != 0) {
  
        if (iVar8 != 0) {
  
          iVar8 = iVar8 + -1;
  
        }
  
        else {
  
          iVar8 = 1;
  
        }
  
        selection.fields.type = 0;
        selection.fields.index = 0;
  
        *(u32 *)(iVar7 + 0x1a0) = 0;
  
        *(u32 *)(iVar7 + 0x1a4) = 0;
  
        *(u32 *)(iVar7 + 0x1a8) = 0;
  
        *(u32 *)(iVar7 + 0x1ac) = 0;
  
      }
  
      break;
  
    case 1:
  
      if (iVar8 == 0) {
  
        if ((DAT_007e0952 & 0x2000) != 0) {
  
          do {
  
            if (selection.fields.type >= 3) {

              selection.fields.type = 0;
  
            }
  
            else {
  
              selection.fields.type++;
  
            }
  
            lVar5 = FUN_003185b0_evt_u32(iVar1,(u16)selection.raw);
  
          } while (lVar5 == 0);
  
        }
  
        else {
  
          if ((DAT_007e0952 & 0x8000) != 0) {
  
            do {
  
              if (selection.fields.type >= 1) {

                selection.fields.type--;
  
              }
  
              else {
  
                selection.fields.type = 3;
  
              }
  
              lVar5 = FUN_003185b0_evt_u32(iVar1,(u16)selection.raw);
  
            } while (lVar5 == 0);
  
          }
  
        }
  
        uVar9 = selection.fields.type;
  
        lVar5 = 0;
  
        for (iVar2 = 0; iVar2 < 0x40; iVar2 = iVar2 + 1) {
  
          lVar4 = FUN_00318620_evt_u32(iVar1,uVar9,(s16)iVar2);
  
          if (lVar4 == 1) {
  
            lVar5 = (long)((int)lVar5 + 1);
  
          }
  
        }
  
        if (lVar5 <= selection.fields.index) {

          selection.fields.index = 0;
  
        }
  
      }
  
      break;
  
    case 2:
  
      if (iVar8 == 0) {
  
        if ((DAT_007e0952 & 0x2000) == 0) {
  
          if ((DAT_007e0952 & 0x8000) != 0) {
  
            if (selection.fields.index >= 1) {

              selection.fields.index--;
  
            }
  
            else {
  
              selection.fields.index = (s8)iVar6 - 1;
  
            }
  
          }
  
        }
  
        else if ((long)selection.fields.index < (long)(iVar6 + -1)) {

          selection.fields.index++;
  
        }
  
        else {
  
          selection.fields.index = 0;
  
        }
  
      }
  
      else if (iVar8 == 1) {
  
        if ((DAT_007e0952 & 0x2000) == 0) {
  
          if ((DAT_007e0952 & 0x8000) != 0) {
  
            if (selection.fields.index != 0) {

              selection.fields.index--;
  
            }
  
            else {
  
              selection.fields.index = 9;
  
            }
  
          }
  
        }
  
        else if (selection.fields.index < 9) {

          selection.fields.index++;
  
        }
  
        else {
  
          selection.fields.index = 0;
  
        }
  
      }
  
      break;
  
    case 3:
  
      if (((DAT_007e0952 & 0x2000) != 0) || ((DAT_007e0952 & 0x8000) != 0)) {
  
        selection.fields.enabled = selection.fields.enabled == 0;
  
      }
  
      break;
  
    case 4:
  
      if ((DAT_007e0952 & 0x2000) != 0) {
  
        if (selection.fields.volume >= 100) {

          selection.fields.volume = 0;
  
        }
  
        else {
  
          selection.fields.volume++;
  
        }
  
      }
  
      if ((DAT_007e0952 & 0x8000) != 0) {
  
        if (selection.fields.volume >= 1) {

          selection.fields.volume--;
  
        }
  
        else {
  
          selection.fields.volume = 100;
  
        }
  
      }
  
      break;
  
    case 5:
  
      if ((DAT_007e0952 & 0x2000) != 0) {
  
        *(int *)(iVar7 + 0x198) = *(int *)(iVar7 + 0x198) + 1;
  
      }
  
      else {
  
        if ((DAT_007e0952 & 8) != 0) {
  
          *(int *)(iVar7 + 0x198) = *(int *)(iVar7 + 0x198) + 10;
  
        }
  
        else {
  
          if ((DAT_007e0952 & 0x8000) != 0) {
  
            *(int *)(iVar7 + 0x198) = *(int *)(iVar7 + 0x198) + -1;
  
          }
  
          else {
  
            if ((DAT_007e0952 & 4) != 0) {
  
              *(int *)(iVar7 + 0x198) = *(int *)(iVar7 + 0x198) + -10;
  
            }
  
          }
  
        }
  
      }
  
      if (*(int *)(iVar7 + 0x198) < 0) {
  
        *(u32 *)(iVar7 + 0x198) = 0;
  
      }
  
      break;
  
    case 6:
  
      if ((DAT_007e0952 & 0x2000) != 0) {
  
        iVar2 = 1;
  
      }
  
      else {
  
        if ((DAT_007e0952 & 0x8000) != 0) {
  
          iVar2 = -1;
  
        }
  
        else {
  
          if ((DAT_007e0952 & 4) != 0) {
  
            iVar2 = -10;
  
          }
  
          else {
  
            if ((DAT_007e0952 & 8) != 0) {
  
              iVar2 = 10;
  
            }
  
          }
  
        }
  
      }
  
      iVar2 = *(int *)(iVar7 + 0x1b0) + iVar2;
  
      *(int *)(iVar7 + 0x1b0) = iVar2;
  
      if (500 < iVar2) {
  
        *(u32 *)(iVar7 + 0x1b0) = 500;
  
      }
  
      if (*(int *)(iVar7 + 0x1b0) < 10) {
  
        *(u32 *)(iVar7 + 0x1b0) = 10;
  
      }
  
      break;
  
    case 7:
  
      if (((DAT_007e0952 & 0x2000) != 0) || ((DAT_007e0952 & 0x8000) != 0)) {
  
        *(u32 *)(iVar7 + 0x1a0) = (u32)(*(int *)(iVar7 + 0x1a0) == 0);
  
      }
  
      break;
  
    case 8:
  
      if (iVar8 == 0) {
  
        if ((DAT_007e0952 & 0x2000) == 0) {
  
          if ((DAT_007e0952 & 0x8000) != 0) {
  
            if (*(int *)(iVar7 + 0x1a4) >= 1) {
  
              *(int *)(iVar7 + 0x1a4) = *(int *)(iVar7 + 0x1a4) + -1;
  
            }
  
            else {
  
              *(int *)(iVar7 + 0x1a4) = iVar6 + -1;
  
            }
  
          }
  
        }
  
        else if (*(int *)(iVar7 + 0x1a4) < iVar6 + -1) {
  
          *(int *)(iVar7 + 0x1a4) = *(int *)(iVar7 + 0x1a4) + 1;
  
        }
  
        else {
  
          *(u32 *)(iVar7 + 0x1a4) = 0;
  
        }
  
      }
  
      else if (iVar8 == 1) {
  
        if ((DAT_007e0952 & 0x2000) == 0) {
  
          if ((DAT_007e0952 & 0x8000) != 0) {
  
            if (*(int *)(iVar7 + 0x1a4) != 0) {
  
              *(int *)(iVar7 + 0x1a4) = *(int *)(iVar7 + 0x1a4) + -1;
  
            }
  
            else {
  
              *(u32 *)(iVar7 + 0x1a4) = 9;
  
            }
  
          }
  
        }
  
        else if (*(int *)(iVar7 + 0x1a4) < 9) {
  
          *(int *)(iVar7 + 0x1a4) = *(int *)(iVar7 + 0x1a4) + 1;
  
        }
  
        else {
  
          *(u32 *)(iVar7 + 0x1a4) = 0;
  
        }
  
      }
  
      break;
  
    case 9:
  
      if (((DAT_007e0952 & 0x2000) != 0) || ((DAT_007e0952 & 0x8000) != 0)) {
  
        *(u32 *)(iVar7 + 0x1a8) = (u32)(*(int *)(iVar7 + 0x1a8) == 0);
  
      }
  
      break;
  
    case 10:
  
      if ((DAT_007e0952 & 0x2000) != 0) {
  
        iVar2 = 1;
  
      }
  
      else {
  
        if ((DAT_007e0952 & 0x8000) != 0) {
  
          iVar2 = -1;
  
        }
  
      }
  
      iVar2 = *(int *)(iVar7 + 0x1ac) + iVar2;
  
      *(int *)(iVar7 + 0x1ac) = iVar2;
  
      if (100 < iVar2) {
  
        *(u32 *)(iVar7 + 0x1ac) = 100;
  
      }
  
      if (*(int *)(iVar7 + 0x1ac) < 0) {
  
        *(u32 *)(iVar7 + 0x1ac) = 0;
  
      }
  
      break;
  
    case 0xb:
  
      if ((DAT_007e0952 & 0x2000) != 0) {
  
        iVar2 = 1;
  
      }
  
      else {
  
        if ((DAT_007e0952 & 0x8000) != 0) {
  
          iVar2 = -1;
  
        }
  
        else {
  
          if ((DAT_007e0952 & 4) != 0) {
  
            iVar2 = -10;
  
          }
  
          else {
  
            if ((DAT_007e0952 & 8) != 0) {
  
              iVar2 = 10;
  
            }
  
          }
  
        }
  
      }
  
      iVar2 = *(int *)(iVar7 + 0x1b4) + iVar2;
  
      *(int *)(iVar7 + 0x1b4) = iVar2;
  
      if (500 < iVar2) {
  
        *(u32 *)(iVar7 + 0x1b4) = 500;
  
      }
  
      if (*(int *)(iVar7 + 0x1b4) < 10) {
  
        *(u32 *)(iVar7 + 0x1b4) = 10;
  
      }
  
    }
  
    *(u32 *)(iVar7 + 0x16c) = selection.raw;
  
    *(int *)(iVar7 + 0x19c) = iVar8;
  
    if ((DAT_007e094e & 0x40) != 0) {
  
      lVar5 = FUN_00318620_evt_u32(iVar1,(u16)selection.raw,selection.fields.index);
  
      if (lVar5 == 1) {
  
        return 1;
  
      }
  
    }
  
    if ((DAT_007e094e & 0x20) != 0) {
  
      uVar3 = 0xffffffffffffffff;
  
    }
  
    else {
  
      uVar3 = 0;
  
    }
  
  }

  return uVar3;

}
#pragma opt_loop_invariants reset


/* opt_lifetimes on: default nd326/592B -> nd320/592B; retained. */
#pragma push
#pragma opt_lifetimes on
// FUN_00371350 NONMATCHING


void FUN_00371350(int param_1,int param_2,int param_3,u8 *param_4)



{

  u16 *puVar1;

  u32 uVar2;

  int iVar3;

  f32 uVar4;

  

  iVar3 = 0;

  if (param_3 == *(int *)(param_4 + 0x108) + *(int *)(param_4 + 0x110)) {

    uVar2 = 4;

  }

  else {

    uVar2 = 0;

  }

  if (param_3 != 0) {

    if (param_3 == 1) {

      uVar4 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar4, uVar2, (const char *)&gp0xffffa058);

      return;

    }

    if (param_3 == 2) {

      uVar4 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar4, uVar2, (const char *)DAT_0069e6b8_abs);

      return;

    }

  }

  else {

    uVar4 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar4, uVar2, (const char *)&gp0xffffa050);

  }

  iVar3 += 3;

  for (puVar1 = (u16 *)FUN_003b5d50(3); puVar1 != (u16 *)0x0;

      puVar1 = *(u16 **)(puVar1 + 0x7c)) {

    if (iVar3 == param_3) {

      uVar4 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar4, uVar2, (const char *)DAT_0069e878_abs, *puVar1);

      return;

    }

    iVar3 = iVar3 + 1;

  }

  puVar1 = (u16 *)FUN_003b5d50(1);

  while( true) {

    if (puVar1 == (u16 *)0x0) {
      return;
    }

    if (iVar3 == param_3) break;

    puVar1 = *(u16 **)(puVar1 + 0x7c);

    iVar3 = iVar3 + 1;

  }

  uVar4 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar4, uVar2, (const char *)DAT_0069e878_abs, *puVar1);

  return;

}
#pragma pop


// FUN_003715B0 NONMATCHING


u32 FUN_003715b0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int uVar3;

  int iVar4;

  
  iVar4 = 0xf;

  iVar1 = 0;

  iVar1 = iVar1 + FUN_003b5df0(3);

  iVar1 = iVar1 + FUN_003b5df0(1);

  iVar2 = (int)param_3;

  FUN_0036f900(param_1,param_2,0x14,iVar4,*(u32 *)(iVar2 + 0x108),iVar1 + 3,param_3,0,
               (code *)FUN_00371350);

  if (*(int *)(iVar2 + 0xd4) != 0x11) {
    return 0;
  }
    if (iVar1 + 3 < 0xf) {
      iVar4 = iVar1 + 3;
    }

    FUN_0036f680(iVar2 + 0x108,iVar2 + 0x110,iVar1 + 3,iVar4,0,0x4000,0x1000);
    FUN_0036f680(0,0,1,1,0,0x2000,0x8000);

    if ((*(u16 *)DAT_007e094e_abs & 0x40) != 0) {
      return 1;
    }
    if ((*(u16 *)DAT_007e094e_abs & 0x20) != 0) {
      return -1;
    }
    return 0;

}


// FUN_00371710


u32 FUN_00371710(int param_1,int param_2,int param_3)



{

  u32 uVar1;

  f32 uVar2;

  

  uVar1 = *(u32 *)(param_3 + 0xe0);

  uVar2 = FUN_0038a220(uVar1);

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar2, 0, (const char *)DAT_0069e888_abs, uVar1);

  return 2;

}


// FUN_00371790 NONMATCHING
void FUN_00371790(int param_1,int param_2,u32 param_3,u8 *param_4)
{
  u8 *puVar1;
  int iVar2;
  u32 *puVar3;
  u8 **ppuVar4;
  u32 auStack_30[11];
  u32 auStack_50[7];
  u16 uStack_2;
  u32 uVar1;
  u32 uVar2;
  u32 uVar3;
  int iVar4;
  f32 fVar5;
  s32 lVar6;

  ppuVar4 = PTR_s_L_FLAG_NOTUSE_0069e990_abs;
  puVar3 = auStack_30;
  iVar2 = 0xb;
  do {
    puVar1 = *ppuVar4;
    ppuVar4 = ppuVar4 + 1;
    iVar2 = iVar2 - 1;
    *puVar3 = (u32)puVar1;
    puVar3 = puVar3 + 1;
  } while (0 < iVar2);
  ppuVar4 = PTR_s_DIRECT_0069e9c0_abs;
  puVar3 = auStack_50;
  iVar2 = 7;
  do {
    puVar1 = *ppuVar4;
    ppuVar4 = ppuVar4 + 1;
    iVar2 = iVar2 - 1;
    *puVar3 = (u32)puVar1;
    puVar3 = puVar3 + 1;
  } while (0 < iVar2);
  uStack_2 = 0;
  iVar4 = 0;
  uVar1 = *(u32 *)(param_4 + 0x198);
  if (*(int *)(param_4 + 0x214) == (int)param_3) {
    iVar4 = 4;
  }
  uVar2 = *(u32 *)(param_4 + 0x16c);
  uVar3 = uVar2 & 0xfff;
  switch (param_3) {
  case 0:
    fVar5 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar5, 0, (const char *)&gp0xffffa100, auStack_50[uVar1]);
    break;
  case 1:
    if (uVar1 != 0) {
      lVar6 = FUN_00397580(param_4,uVar1 - 1,&uStack_2);
      if (lVar6 == 1) {
        if (uStack_2 == 0xffff) {
          fVar5 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
          evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar5, iVar4, (const char *)&gp0xffffa108, (u32)uStack_2);
          fVar5 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
          evtMenuDrawText((param_1 + 9) * 0xc, param_2 * 0xc, fVar5, iVar4, s_evtMenu_0069ea10, (u32)uStack_2);
          if (FUN_0039f750(param_4 + 0x82c,(u32)uStack_2) == 0) {
            fVar5 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
            evtMenuDrawText((param_1 + 0x12) * 0xc, param_2 * 0xc, fVar5, iVar4, s_evtMenu_0069e9e0);
          } else {
            fVar5 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
            evtMenuDrawText((param_1 + 0x12) * 0xc, param_2 * 0xc, fVar5, iVar4, (const char *)(void *)0x69e9f0);
          }
        }
        else {
          fVar5 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
          evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar5, iVar4, (const char *)&gp0xffffa108, (u32)uStack_2);
          fVar5 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
          evtMenuDrawText((param_1 + 9) * 0xc, param_2 * 0xc, fVar5, iVar4, s_evtMenu_0069ea00, (u32)uStack_2);
        }
      }
    }
    else {
      fVar5 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar5, iVar4, (const char *)&gp0xffffa108, uVar3);
      if (FUN_0039f750(param_4 + 0x82c,uVar3) == 0) {
        fVar5 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
        evtMenuDrawText((param_1 + 0x12) * 0xc, param_2 * 0xc, fVar5, iVar4, s_evtMenu_0069e9e0);
      }
      else {
        fVar5 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
        evtMenuDrawText((param_1 + 0x12) * 0xc, param_2 * 0xc, fVar5, iVar4, (const char *)(void *)0x69e9f0);
      }
    }
    break;
  case 2:
    if (uVar1 == 6) {
      break;
    }
    fVar5 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar5, iVar4, (const char *)&gp0xffffa100, auStack_30[((uVar2 >> 12) & 0xf)]);
    break;
  case 3:
    if (*(int *)(param_4 + 0x19c) == 0) {
      fVar5 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar5, iVar4, (const char *)(void *)0x69ea20);
    } else {
      fVar5 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar5, iVar4, (const char *)(void *)0x69ea40);
    }
    break;
  case 4:
    break;
  case 5:
    fVar5 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar5, iVar4, (const char *)(void *)0x69ea58);
    break;
  case 6:
    fVar5 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar5, iVar4, (const char *)(void *)0x69ea68);
    break;
  case 7:
    fVar5 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar5, iVar4, (const char *)(void *)0x69ea78);
    break;
  case 8:
    fVar5 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar5, iVar4, (const char *)(void *)0x69ea88);
    break;
  }
}


/* opt_propagation off: default nd701/1124B -> nd691/1124B; retained. */
#pragma push
#pragma opt_propagation off
// FUN_00371DD0 NONMATCHING


int FUN_00371dd0(int param_1,int param_2,int param_3)



{

  int iVar1;

  long lVar2;

  int iVar6;

  u32 uVar5;

  u32 uVar4;

  int iVar3;

  int iVar7;

  u16 uStack_2;

  

  iVar6 = 0;

  uStack_2 = 0;

  FUN_0036f900(param_1,param_2,0x1e,10,0,1,param_3,
               (int)(code *)FUN_00371710,(code *)FUN_00371790);

  iVar7 = (int)param_3;

  if (*(int *)(iVar7 + 0xd4) != 0xd) {
    return 0;
  }

    iVar3 = *(int *)(iVar7 + 0x198);

    uVar4 = *(u32 *)(iVar7 + 0x16c) & 0xfff;

    uVar5 = (int)*(u32 *)(iVar7 + 0x16c) >> 0xc & 0xf;

    iVar1 = *(int *)(iVar7 + 0x214);

    switch (iVar1) {
    case 0:
      if ((DAT_007e0952 & 0x8000) == 0) {
        if ((DAT_007e0952 & 0x2000) != 0) {
          if (iVar3 >= 6) {
            iVar3 = 0;
          }
          else {
            iVar3 = iVar3 + 1;
          }
          uVar4 = 0;
          uVar5 = 0;
        }
      }
      else {
        if (iVar3 != 0) {
          iVar3 = iVar3 + -1;
        }
        else {
          iVar3 = 6;
        }
        uVar4 = 0;
        uVar5 = 0;
      }
      break;
    case 1:
      switch(iVar3) {
      case 0:
        if ((DAT_007e0952 & 0x8000) == 0) {
          if ((DAT_007e0952 & 0x2000) != 0) {
            iVar6 = 1;
          }
        }
        else {
          iVar6 = -1;
        }
        uVar4 = uVar4 + iVar6;
        if ((int)uVar4 < *(int *)(iVar7 + 0x170)) {
          uVar4 = *(u32 *)(iVar7 + 0x174);
        }
        if (*(int *)(iVar7 + 0x174) < (int)uVar4) {
          uVar4 = 0;
        }
        *(u32 *)(iVar7 + 0x16c) = uVar4 | uVar5 << 0xc;
        break;
      case 1:
      case 2:
      case 3:
      case 4:
      case 5:
        if ((DAT_007e0952 & 0x8000) == 0) {
          if ((DAT_007e0952 & 0x2000) != 0) {
            iVar6 = 1;
          }
        }
        else {
          iVar6 = -1;
        }
        uVar4 = uVar4 + iVar6;
        if (*(int *)(iVar7 + 0x174) < (int)(uVar4 + uStack_2)) {
          uVar4 = 0;
        }
        if ((int)uVar4 < 0) {
          uVar4 = *(int *)(iVar7 + 0x174) - (u32)uStack_2;
        }
      }
      break;
    case 2:
      if ((DAT_007e0952 & 0x8000) == 0) {
        if ((DAT_007e0952 & 0x2000) != 0) {
          if (uVar5 >= 10) {
            uVar5 = 0;
          }
          else {
            uVar5 = uVar5 + 1;
          }
        }
      }
      else if (uVar5 == 0) {
        uVar5 = 10;
      }
      else {
        uVar5 = uVar5 - 1;
      }
      *(u32 *)(iVar7 + 0x16c) = uVar4 | uVar5 << 0xc;
      break;
    case 3:
      if (((DAT_007e0952 & 0x8000) != 0) || ((DAT_007e0952 & 0x2000) != 0)) {
        *(u32 *)(iVar7 + 0x19c) = (u32)(*(int *)(iVar7 + 0x19c) == 0);
      }
      break;
    }

    *(u32 *)(iVar7 + 0x16c) = uVar4 | uVar5 << 0xc;

    *(int *)(iVar7 + 0x198) = iVar3;

    if ((DAT_007e0952 & 0x1000) == 0) {

      if ((DAT_007e0952 & 0x4000) != 0) {

        if (*(int *)(iVar7 + 0x214) >= 3) {

          *(u32 *)(iVar7 + 0x214) = 0;

        }

        else {

          *(int *)(iVar7 + 0x214) = *(int *)(iVar7 + 0x214) + 1;

        }

      }

    }

    else if (*(int *)(iVar7 + 0x214) == 0) {

      *(u32 *)(iVar7 + 0x214) = 3;

    }

    else {

      *(int *)(iVar7 + 0x214) = *(int *)(iVar7 + 0x214) + -1;

    }

    lVar2 = FUN_00397580(param_3,uVar5 - 1,&uStack_2);

    if ((DAT_007e094e & 0x40) != 0) {

      if ((lVar2 == 0) &&

         ((((iVar3 == 5 || (iVar3 == 4)) || (iVar3 == 3)) || ((iVar3 == 2 || (iVar3 == 1)))))) {

        return 0;

      }

      lVar2 = FUN_0039eee0(iVar7 + 0x82c);

      if (lVar2 == 1) {

        if (iVar3 - 1U < 5) {

          return 1;

        }

        if (uVar5 != 0) {

          lVar2 = FUN_0039f750(iVar7 + 0x82c,uVar4);

          if (lVar2 == 1) {

            return 1;

          }

        }

        else {

          lVar2 = FUN_0039f750(iVar7 + 0x82c,uVar4);

          if (lVar2 == 0) {

            return 1;

          }

        }

      }

    }

    iVar6 = -(u32)((DAT_007e094e & 0x20) != 0);


  return iVar6;

}
#pragma pop


// FUN_00372260


u32 FUN_00372260(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069eaa0);

  return 2;

}


/* opt_dead_assignments off: default nd638/1192B -> nd620/1192B; retained. */
#pragma push
#pragma opt_dead_assignments off
// FUN_003722D0 NONMATCHING


void FUN_003722d0(u32 param_1,u32 param_2,u32 param_3,u8 *param_4)
{
  f32 local0[3];
  f32 local1[3];
  int iVar3;
  f32 fVar1;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;

  iVar3 = 0;
  *(RwV3d *)local0 = *(RwV3d *)DAT_0069ead8_f32;
  *(RwV3d *)local1 = *(RwV3d *)DAT_0069eb18_f32;
  if (*(int *)(param_4 + 0x218) == (int)param_3) {
    iVar3 = 4;
  }
  switch (param_3) {
  case 0:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    uVar4 = param_1 * 0xc;
    uVar5 = param_2 * 0xc;
    uVar6 = ((u32 *)local0)[*(s8 *)(param_4 + 0x788)];
    evtMenuDrawText(uVar4, uVar5, fVar1, iVar3, (const char *)(u32)&gp0xffffa118, uVar6);
    break;
  case 1:
    if (*(s8 *)(param_4 + 0x788) != 0) {
      fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar1, iVar3, (const char *)(u32)DAT_0069eb28, (u32)*(s16 *)(param_4 + 0x784));
    }
    else {
      fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar1, iVar3, (const char *)(u32)&gp0xffffa120);
    }
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0xc) * 0xc, param_2 * 0xc, fVar1, 0, (const char *)(u32)DAT_0069eb38);
    break;
  case 2:
    if (*(s8 *)(param_4 + 0x788) != 0) {
      fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar1, iVar3, (const char *)(u32)&gp0xffffa128, (u32)*(s16 *)(param_4 + 0x786));
    }
    else {
      fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar1, iVar3, (const char *)(u32)&gp0xffffa120);
    }
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0xc) * 0xc, param_2 * 0xc, fVar1, 0, (const char *)(u32)DAT_0069eb48);
    break;
  case 3:
    if (*(s8 *)(param_4 + 0x788) == 2) {
      fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar1, iVar3, (const char *)(u32)&gp0xffffa118, ((u32 *)local1)[*(u8 *)(param_4 + 0x78a)]);
    }
    else {
      fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar1, iVar3, (const char *)(u32)&gp0xffffa120);
    }
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0xc) * 0xc, param_2 * 0xc, fVar1, 0, (const char *)(u32)DAT_0069eb58);
    break;
  case 4:
    break;
  case 5:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar1, iVar3, (const char *)(u32)DAT_0069ea58);
    break;
  case 6:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar1, iVar3, (const char *)(u32)DAT_0069ea68);
    break;
  case 7:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar1, iVar3, (const char *)(u32)DAT_0069ea78);
    break;
  case 8:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar1, iVar3, (const char *)(u32)DAT_0069ea88);
    break;
  }
}
#pragma pop


/* opt_lifetimes on: default nd795/1128B -> nd792/1128B; retained. */
#pragma push
#pragma opt_lifetimes on
// FUN_00372790 NONMATCHING


int FUN_00372790(int param_1,int param_2,int param_3)



{

  char cVar1;

  int iVar2;

  int sVar3;

  int iVar4;

  int iVar5;

  int sVar6;

  


  iVar5 = param_3;

  if ((*(char *)(iVar5 + 0x788) < '\0') || ('\x02' < *(char *)(iVar5 + 0x788))) {

    *(u8 *)(iVar5 + 0x788) = 0;

  }

  if (*(short *)(iVar5 + 0x784) < 0) {

    *(u16 *)(iVar5 + 0x784) = 0;

  }

  sVar3 = 0;
  iVar4 = 0;
  FUN_0036f900(param_1,param_2,0x1b,0xc,0,1,param_3,0x372260,0);
  sVar6 = 0;

  if (*(int *)(iVar5 + 0xd4) != 0xe) {

    iVar4 = 0;

  }

  else {

    iVar2 = *(int *)(iVar5 + 0x218);

    if (iVar2 == 3) {

      if (*(char *)(iVar5 + 0x788) == '\x02') {

        if ((DAT_007e0952 & 0x8000) != 0) {

          iVar4 = -1;

        }

        else {

          if ((DAT_007e0952 & 0x2000) != 0) {

            iVar4 = 1;

          }

        }

        iVar4 = (u32)*(u8 *)(iVar5 + 0x78a) + iVar4;

        if (iVar4 < 0) {

          iVar4 = 2;

        }

        if (2 < iVar4) {

          iVar4 = 0;

        }

        *(char *)(iVar5 + 0x78a) = (char)iVar4;

      }

    }

    else if (iVar2 == 2) {

      cVar1 = *(char *)(iVar5 + 0x788);

      if (cVar1 == '\x02') {

        sVar6 = 1;

      }

      else if (cVar1 == '\x01') {

        sVar6 = 10;

      }

      else if (cVar1 == '\0') {

        sVar6 = 10;

      }

      if ((DAT_007e0952 & 0x8000) != 0) {

        sVar3 = -1;

      }

      else {

        if ((DAT_007e0952 & 0x2000) != 0) {

          sVar3 = 1;

        }

        else {

          if ((DAT_007e0952 & 4) != 0) {

            sVar3 = -10;

          }

          else {

            if ((DAT_007e0952 & 8) != 0) {

              sVar3 = 10;

            }

            else {

              if ((DAT_007e0952 & 1) != 0) {

                sVar3 = -100;

              }

              else {

                if ((DAT_007e0952 & 2) != 0) {

                  sVar3 = 100;

                }

              }

            }

          }

        }

      }

      sVar3 = *(short *)(iVar5 + 0x786) + sVar3;

      *(short *)(iVar5 + 0x786) = sVar3;

      if (sVar3 < 0) {

        *(u16 *)(iVar5 + 0x786) = 0;

      }

      if (sVar6 <= *(short *)(iVar5 + 0x786)) {

        *(short *)(iVar5 + 0x786) = sVar6;

      }

    }

    else if (iVar2 == 1) {

      cVar1 = *(char *)(iVar5 + 0x788);

      if (cVar1 == '\x02') {

        sVar6 = 4999;

      }

      else if (cVar1 == '\x01') {

        sVar6 = 9;

      }

      else if (cVar1 == '\0') {

        sVar6 = 0;

      }

      if ((DAT_007e0952 & 0x8000) != 0) {

        sVar3 = -1;

      }

      else {

        if ((DAT_007e0952 & 0x2000) != 0) {

          sVar3 = 1;

        }

        else {

          if ((DAT_007e0952 & 4) != 0) {

            sVar3 = -10;

          }

          else {

            if ((DAT_007e0952 & 8) != 0) {

              sVar3 = 10;

            }

            else {

              if ((DAT_007e0952 & 1) != 0) {

                sVar3 = -100;

              }

              else {

                if ((DAT_007e0952 & 2) != 0) {

                  sVar3 = 100;

                }

              }

            }

          }

        }

      }

      sVar3 = *(short *)(iVar5 + 0x784) + sVar3;

      *(short *)(iVar5 + 0x784) = sVar3;

      if (sVar3 < 0) {

        *(u16 *)(iVar5 + 0x784) = 0;

      }

      if (sVar6 <= *(short *)(iVar5 + 0x784)) {

        *(short *)(iVar5 + 0x784) = sVar6;

      }

    }

    else if (iVar2 == 0) {

      if ((DAT_007e0952 & 0x8000) != 0) {

        if (*(char *)(iVar5 + 0x788) < '\x01') {

          *(u8 *)(iVar5 + 0x788) = 2;

        }

        else {

          *(char *)(iVar5 + 0x788) = *(char *)(iVar5 + 0x788) + -1;

        }

        *(u16 *)(iVar5 + 0x786) = 0;

        *(u16 *)(iVar5 + 0x784) = 0;

        *(u8 *)(iVar5 + 0x78a) = 0;

      }

      else {

        if ((DAT_007e0952 & 0x2000) != 0) {

          if (*(char *)(iVar5 + 0x788) < '\x02') {

            *(char *)(iVar5 + 0x788) = *(char *)(iVar5 + 0x788) + '\x01';

          }

          else {

            *(u8 *)(iVar5 + 0x788) = 0;

          }

          *(u16 *)(iVar5 + 0x786) = 0;

          *(u16 *)(iVar5 + 0x784) = 0;

          *(u8 *)(iVar5 + 0x78a) = 0;

        }

      }

    }

    if ((DAT_007e0952 & 0x1000) == 0) {

      if ((DAT_007e0952 & 0x4000) != 0) {

        if (*(int *)(iVar5 + 0x218) < 3) {

          *(int *)(iVar5 + 0x218) = *(int *)(iVar5 + 0x218) + 1;

        }

        else {

          *(u32 *)(iVar5 + 0x218) = 0;

        }

      }

    }

    else if (*(int *)(iVar5 + 0x218) < 1) {

      *(u32 *)(iVar5 + 0x218) = 3;

    }

    else {

      *(int *)(iVar5 + 0x218) = *(int *)(iVar5 + 0x218) + -1;

    }

    if ((DAT_007e094e & 0x40) == 0) {

      iVar4 = -(u32)((DAT_007e094e & 0x20) != 0);

    }

    else {

      iVar4 = 1;

    }

  }

  return iVar4;

}
#pragma pop


// FUN_00372C40 NONMATCHING


bool FUN_00372c40(int param_1)



{

  u32 bVar1;

  int sVar2;

  int iVar3;

  u32 uVar4;

  int lVar5;

  char cVar6;

  u32 uVar10;

  int iVar7;

  int iVar8;

  char *pcVar9;

  float fVar11;

  f32 uVar12;

  float fVar13;

  

  iVar7 = param_1;


  iVar3 = FUN_00361830(param_1);

  if (*(int *)(param_1 + 0x274) == 0) {

    uVar10 = 6;

  }

  else {

    uVar10 = 0;

  }

  uVar12 = FUN_0038a220(*(u32 *)(iVar7 + 0xe0));

  evtMenuDrawText(0x78, 0x78, uVar12, 0, (const char *)&gp0xffffa130);

  uVar12 = FUN_0038a220(*(u32 *)(iVar7 + 0xe0));

  evtMenuDrawText(0x78, 0x78, uVar12, uVar10, (const char *)&gp0xffffa060, *(short *)(iVar3 + 0x14));

  if (*(int *)(iVar7 + 0x274) == 1) {

    uVar10 = 6;

  }

  else {

    uVar10 = 0;

  }

  uVar12 = FUN_0038a220(*(u32 *)(iVar7 + 0xe0));

  evtMenuDrawText(0x78, 0x84, uVar12, 0, (const char *)&gp0xffffa134);

  uVar12 = FUN_0038a220(*(u32 *)(iVar7 + 0xe0));

  evtMenuDrawText(0x78, 0x84, uVar12, uVar10, (const char *)&gp0xffffa060, *(short *)(iVar3 + 0x16));

  if (*(int *)(iVar7 + 0x274) == 5) {

    uVar10 = 6;

  }

  else {

    uVar10 = 0;

  }

  uVar12 = FUN_0038a220(*(u32 *)(iVar7 + 0xe0));

  evtMenuDrawText(0x78, 0xb4, uVar12, 0, (const char *)&gp0xffffa138);

  uVar12 = FUN_0038a220(*(u32 *)(iVar7 + 0xe0));

  evtMenuDrawText(0x78, 0xb4, uVar12, uVar10, (const char *)&gp0xffffa060, *(u8 *)(iVar3 + 0x1b));

  uVar10 = 6;

  if (*(int *)(iVar7 + 0x274) != 6) {

    uVar10 = 0;

  }

  uVar12 = FUN_0038a220(*(u32 *)(iVar7 + 0xe0));

  evtMenuDrawText(0x78, 0xc0, uVar12, 0, (const char *)&gp0xffffa140);

  cVar6 = *(char *)(iVar3 + 0x11);

  if (cVar6 == '\x02') {

    uVar12 = FUN_0038a220(*(u32 *)(iVar7 + 0xe0));

    evtMenuDrawText(0x78, 0xc0, uVar12, uVar10, (const char *)(void *)0x69eb88);

  }

  else if (cVar6 == '\x01') {

    uVar12 = FUN_0038a220(*(u32 *)(iVar7 + 0xe0));

    evtMenuDrawText(0x78, 0xc0, uVar12, uVar10, (const char *)(void *)0x69eb78);

  }

  else if (cVar6 == '\0') {

    uVar12 = FUN_0038a220(*(u32 *)(iVar7 + 0xe0));

    evtMenuDrawText(0x78, 0xc0, uVar12, uVar10, (const char *)(void *)0x69eb68);

  }

  if (*(int *)(iVar7 + 0x274) == 7) {

    uVar10 = 6;

  }

  else {

    uVar10 = 0;

  }

  uVar12 = FUN_0038a220(*(u32 *)(iVar7 + 0xe0));

  evtMenuDrawText(0x78, 0xcc, uVar12, 0, (const char *)&gp0xffffa148);

  uVar12 = FUN_0038a220(*(u32 *)(iVar7 + 0xe0));

  uVar4 = FUN_00530da0_evt(*(f32 *)(iVar3 + 0x1c));

  evtMenuDrawText(0x78, 0xcc, uVar12, uVar10, (const char *)(void *)0x69eb98, uVar4);

  if (*(int *)(iVar7 + 0x274) == 8) {

    uVar10 = 6;

  }

  else {

    uVar10 = 0;

  }

  uVar12 = FUN_0038a220(*(u32 *)(iVar7 + 0xe0));

  evtMenuDrawText(0x78, 0xd8, uVar12, 0, (const char *)&gp0xffffa150);

  uVar12 = FUN_0038a220(*(u32 *)(iVar7 + 0xe0));

  uVar4 = FUN_00530da0_evt(*(f32 *)(iVar3 + 0x20));

  evtMenuDrawText(0x78, 0xd8, uVar12, uVar10, (const char *)(void *)0x69eb98, uVar4);

  lVar5 = 0;

  if ((DAT_007e0952 & 0x4000) == 0) {

    if ((DAT_007e0952 & 0x1000) == 0) {

      if ((DAT_007e0952 & 0x8000) == 0) {

        if ((DAT_007e0952 & 0x2000) == 0) {

          if ((DAT_007e0952 & 1) == 0) {

            if ((DAT_007e0952 & 2) != 0) {

              lVar5 = 10;

            }

          }

          else {

            lVar5 = -10;

          }

        }

        else {

          lVar5 = 1;

        }

      }

      else {

        lVar5 = -1;

      }

    }

    else if (*(int *)(iVar7 + 0x274) < 1) {

      *(u32 *)(iVar7 + 0x274) = 8;

    }

    else {

      *(int *)(iVar7 + 0x274) = *(int *)(iVar7 + 0x274) + -1;

    }

  }

  else if (*(int *)(iVar7 + 0x274) < 8) {

    *(int *)(iVar7 + 0x274) = *(int *)(iVar7 + 0x274) + 1;

  }

  else {

    *(u32 *)(iVar7 + 0x274) = 0;

  }

  if (lVar5 != 0) {

    iVar8 = (int)lVar5;

    cVar6 = (char)lVar5;

    switch(*(u32 *)(iVar7 + 0x274)) {

    case 0:

      sVar2 = *(short *)(iVar3 + 0x14) + (short)lVar5;

      *(short *)(iVar3 + 0x14) = sVar2;

      if (sVar2 < -500) {

        *(u16 *)(iVar3 + 0x14) = 0xfe0c;

      }

      if (1000 < *(short *)(iVar3 + 0x14)) {

        *(u16 *)(iVar3 + 0x14) = 1000;

      }

      break;

    case 1:

      sVar2 = *(short *)(iVar3 + 0x16) + (short)lVar5;

      *(short *)(iVar3 + 0x16) = sVar2;

      if (sVar2 < -500) {

        *(u16 *)(iVar3 + 0x16) = 0xfe0c;

      }

      if (1000 < *(short *)(iVar3 + 0x16)) {

        *(u16 *)(iVar3 + 0x16) = 1000;

      }

      break;

    case 2:

      pcVar9 = (char *)(iVar3 + 0x18);

      iVar8 = (u32)*(u8 *)(iVar3 + 0x18) + iVar8;

      if (iVar8 < 0xff) {

        if (iVar8 < 1) {

          *pcVar9 = '\0';

        }

        else {

          *pcVar9 = *(u8 *)(iVar3 + 0x18) + (u8)cVar6;

        }

      }

      else {

        *pcVar9 = -1;

      }

      break;

    case 3:

      pcVar9 = (char *)(iVar3 + 0x19);

      iVar8 = (u32)*(u8 *)(iVar3 + 0x19) + iVar8;

      if (iVar8 < 0xff) {

        if (iVar8 < 1) {

          *pcVar9 = '\0';

        }

        else {

          *pcVar9 = *(u8 *)(iVar3 + 0x19) + (u8)cVar6;

        }

      }

      else {

        *pcVar9 = -1;

      }

      break;

    case 4:

      pcVar9 = (char *)(iVar3 + 0x1a);

      iVar8 = (u32)*(u8 *)(iVar3 + 0x1a) + iVar8;

      if (iVar8 < 0xff) {

        if (iVar8 < 1) {

          *pcVar9 = '\0';

        }

        else {

          *pcVar9 = *(u8 *)(iVar3 + 0x1a) + (u8)cVar6;

        }

      }

      else {

        *pcVar9 = -1;

      }

      break;

    case 5:

      pcVar9 = (char *)(iVar3 + 0x1b);

      iVar8 = (u32)*(u8 *)(iVar3 + 0x1b) + iVar8;

      if (iVar8 < 0xff) {

        if (iVar8 < 1) {

          *pcVar9 = '\0';

        }

        else {

          *pcVar9 = *(u8 *)(iVar3 + 0x1b) + (u8)cVar6;

        }

      }

      else {

        *pcVar9 = -1;

      }

      break;

    case 6:

      cVar6 = *(char *)(iVar3 + 0x11) + cVar6;

      *(char *)(iVar3 + 0x11) = cVar6;

      if ((cVar6 <= lVar5) && (lVar5 < 0)) {

        *(u8 *)(iVar3 + 0x11) = 2;

      }

      if (((iVar8 + 2) <= *(char *)(iVar3 + 0x11)) && (0 < lVar5)) {

        *(u8 *)(iVar3 + 0x11) = 0;

      }

      if (*(char *)(iVar3 + 0x11) < '\0') {

        *(u8 *)(iVar3 + 0x11) = 0;

      }

      if ('\x02' < *(char *)(iVar3 + 0x11)) {

        *(u8 *)(iVar3 + 0x11) = 2;

      }

      break;

    case 7:

      fVar13 = (float)iVar8 / 100.0f;

      fVar11 = *(float *)(iVar3 + 0x1c) + fVar13;

      *(float *)(iVar3 + 0x1c) = fVar11;

      if ((fVar11 <= fVar13 + -10.0f) && (fVar13 < 0.0f)) {

        *(u32 *)(iVar3 + 0x1c) = 0x41200000;

      }

      if ((fVar13 + 10.0f <= *(float *)(iVar3 + 0x1c)) && (0.0f < fVar13)) {

        *(u32 *)(iVar3 + 0x1c) = 0xc1200000;

      }

      if (*(float *)(iVar3 + 0x1c) < -10.0f) {

        *(u32 *)(iVar3 + 0x1c) = 0xc1200000;

      }

      if (10.0f < *(float *)(iVar3 + 0x1c)) {

        *(u32 *)(iVar3 + 0x1c) = 0x41200000;

      }

      break;

    case 8:

      fVar13 = (float)iVar8 / 100.0f;

      fVar11 = *(float *)(iVar3 + 0x20) + fVar13;

      *(float *)(iVar3 + 0x20) = fVar11;

      if ((fVar11 <= fVar13 + -10.0f) && (fVar13 < 0.0f)) {

        *(u32 *)(iVar3 + 0x20) = 0x41200000;

      }

      if ((fVar13 + 10.0f <= *(float *)(iVar3 + 0x20)) && (0.0f < fVar13)) {

        *(u32 *)(iVar3 + 0x20) = 0xc1200000;

      }

      if (*(float *)(iVar3 + 0x20) < -10.0f) {

        *(u32 *)(iVar3 + 0x20) = 0xc1200000;

      }

      if (10.0f < *(float *)(iVar3 + 0x20)) {

        *(u32 *)(iVar3 + 0x20) = 0x41200000;

      }

    }

  }

  bVar1 = (DAT_007e094e & 0x20) == 0;
  if (!bVar1) {
    *(u32 *)(*(int *)(iVar7 + 0x164) + 0x34) = 0;
    FUN_005225a8(0x69eba8);
  }
  return bVar1;

}


// FUN_00373590
u64 FUN_00373590(u64 param_1,u64 param_2,int param_3)
{
  int iVar1;
  char cVar2;
  u64 uVar3;
  int iVar4;

  iVar4 = param_3;
  cVar2 = '\x01';
  iVar1 = **(int **)(iVar4 + 0x164);
  FUN_00361830(param_3);
  switch (iVar1) {
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x17:
  case 0x1b:
    break;

  case 0x10:
    iVar1 = *(int *)(iVar4 + 0xe8);
    if (iVar1 == 0) {
      return cVar2;
    }
    break;

  case 0x11:
    iVar1 = *(int *)(iVar4 + 0xe8);
    if (iVar1 == 0) {
      return cVar2;
    }
    break;

  case 0x18:
    cVar2 = FUN_00372c40_ptr(param_3);
    break;

  case 0x19:
  case 6:
    break;

  default:
    if ((*(u16 *)DAT_007e094e_abs & 0x800) != 0) {
      cVar2 = '\0';
    }
    break;
  }
LAB_003736a4:
  if (!cVar2) {
    if (*(int *)(iVar4 + 0xe8) != 0) {
      FUN_0035adb0(*(int *)(iVar4 + 0xe8),1);
      *(u32 *)(iVar4 + 0xe8) = 0;
    }
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


#pragma alias FUN_001a42f0_evt_f32 FUN_001a42f0
extern f32 *FUN_001a42f0_evt_f32(int param_1,int param_2);
/* opt_dead_assignments off: default nd3053/4240B -> nd3051/4240B; retained. */
#pragma push
#pragma opt_dead_assignments off
// FUN_00373700 NONMATCHING


u32 FUN_00373700(int param_1,int param_2,int param_3)



{

  int iVar1;

  bool bVar2;

  u8 *puVar3;

  float *piVar4;

  u8 *puVar5;

  int iVar6;

  int iVar7;

  u32 *puVar8;

  u32 uVar9;

  int lVar10;

  u8 *puVar11;


  float fVar13;

  float fVar14;

  u8 auStack_1c0 [64];

  u8 auStack_180 [64];

  EvtRay rayIn;

  u8 auStack_120 [64];

  f32 vecE0[4];

  f32 vecD0[4];

  EvtVec3 vecB8;

  EvtVec3 vecA8;

  EvtVec3 vec98;

  EvtVec3 vec88;

  EvtVec3 rayOut;

  float fStack_68;

  float fStack_64;

  float fStack_60;

  u8 auStack_58 [16];

  EvtVec3 vec48;


  EvtVec3 vecA;

  EvtVec3 vecB;


  u8 auStack_18 [4];

  int *piStack_14;

  int *piStack_10;

  int iStack_c;

  float *pfStack_8;

  float *pfStack_4;

  

  bVar2 = true;

  fVar13 = 5.0f;
  fVar14 = 2.0f;


  iVar1 = *(int *)(param_3 + 0x16c);

  switch(iVar1) {

  case 0:

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),0);

    *(u32 *)(param_3 + 0x198) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),1);

    *(u32 *)(param_3 + 0x19c) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),2);

    *(u32 *)(param_3 + 0x1a0) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),3);

    *(u32 *)(param_3 + 0x1a4) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),4);

    *(u32 *)(param_3 + 0x1a8) = *puVar8;

    FUN_00395550(param_3,*(u32 *)(param_3 + 0x198),*(u32 *)(param_3 + 0x19c));

    break;

  case 1:

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),0);

    *(u32 *)(param_3 + 0x198) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),1);

    *(u32 *)(param_3 + 0x19c) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),2);

    *(u32 *)(param_3 + 0x1a0) = *puVar8;

    FUN_00395550(param_3,*(u32 *)(param_3 + 0x198),*(u32 *)(param_3 + 0x19c));

    break;

  case 2:

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),0);

    *(u32 *)(param_3 + 0x198) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),1);

    *(u32 *)(param_3 + 0x19c) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),2);

    *(u32 *)(param_3 + 0x1a0) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),3);

    *(u32 *)(param_3 + 0x1a4) = *puVar8;

    break;

  case 3:

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),0);

    *(u32 *)(param_3 + 0x198) = *puVar8;

    break;

  case 4:

    piVar4 = FUN_001a42f0_evt_f32(*(u32 *)(param_3 + 0xe8),0);
    *(float *)(param_3 + 0x198) = *piVar4;

    piVar4 = FUN_001a42f0_evt_f32(*(u32 *)(param_3 + 0xe8),1);
    *(float *)(param_3 + 0x19c) = *piVar4;

    piVar4 = FUN_001a42f0_evt_f32(*(u32 *)(param_3 + 0xe8),2);
    *(float *)(param_3 + 0x1a0) = *piVar4;

    piVar4 = FUN_001a42f0_evt_f32(*(u32 *)(param_3 + 0xe8),3);
    *(float *)(param_3 + 0x1a4) = *piVar4;

    piVar4 = FUN_001a42f0_evt_f32(*(u32 *)(param_3 + 0xe8),4);
    *(float *)(param_3 + 0x1a8) = *piVar4;

    piVar4 = FUN_001a42f0_evt_f32(*(u32 *)(param_3 + 0xe8),5);

    *(float *)(param_3 + 0x1ac) = *piVar4;

    *(float *)(param_3 + 0x1b0) =
        (float)*(int *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),6);

    *(float *)(param_3 + 0x1b4) =
        (float)*(int *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),7);

    vecD0[0] = *(float *)(param_3 + 0x198);

    vecD0[1] = *(float *)(param_3 + 0x19c);

    vecD0[2] = *(float *)(param_3 + 0x1a0);

    vecD0[3] = 0.0f;

    vecE0[0] = *(float *)(param_3 + 0x1a4);

    vecE0[1] = *(float *)(param_3 + 0x1a8);

    vecE0[2] = *(float *)(param_3 + 0x1ac);

    vecE0[3] = 0.0f;

    vec48.x = *(float *)(param_3 + 0x1b4);

    vec48.y = *(float *)(param_3 + 0x1b0);

    vec48.z = 0.0f;

    FUN_0038b550(*(u32 *)(param_3 + 0x210),(u32 *)vecD0,(u32 *)vecE0,(u32 *)&vec48);

    puVar5 = (u8 *)0xc;

    puVar11 = auStack_58;

    puVar3 = puVar11;

    while (puVar3 != (u8 *)0x0) {

      *puVar11 = 0;

      puVar11 = puVar11 + 1;

      puVar5 = puVar5 + -1;

      puVar3 = puVar5;

    }

    lVar10 = FUN_00198590();

    FUN_0038b600((u32 *)auStack_120,(u32 *)&vec48);

    if (lVar10 != 0) {

      iVar6 = FUN_004cb2f0(*(u32 *)((int)lVar10 + 4));

      fStack_68 = *(float *)(iVar6 + 0x20) * 40.0f + *(float *)(iVar6 + 0x30) + 0.0f;
      fStack_64 = *(float *)(iVar6 + 0x24) * 40.0f + *(float *)(iVar6 + 0x34) + 0.0f;
      fStack_60 = *(float *)(iVar6 + 0x28) * 40.0f + *(float *)(iVar6 + 0x38) + 0.0f;

      FUN_004c35d0(auStack_120,&fStack_68,2);

    }

    FUN_003957d0(10.0f, param_3, (u32*)auStack_120);

    FUN_003625e0(param_3);

    break;

  case 5:

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),2);

    *(u32 *)(param_3 + 0x198) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),3);

    *(u32 *)(param_3 + 0x19c) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),4);

    *(u32 *)(param_3 + 0x1a0) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),5);

    *(u32 *)(param_3 + 0x1a4) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),0);

    *(u32 *)(param_3 + 0x1a8) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),1);

    *(u32 *)(param_3 + 0x1ac) = *puVar8;

    break;

  case 6:

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),0);

    *(u32 *)(param_3 + 0x198) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),1);

    *(u32 *)(param_3 + 0x19c) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),2);

    *(u32 *)(param_3 + 0x1a0) = *puVar8;

    break;

  case 7:

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),0);

    *(u32 *)(param_3 + 0x198) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),1);

    *(u32 *)(param_3 + 0x19c) = *puVar8;

    break;

  case 8:

    iVar6 = **(int **)(param_3 + 0x164);

    iVar7 = FUN_00361830(param_3);

    if (((*(u16 *)DAT_007e094c_abs) & 0x10) != 0) {

      fVar13 = fVar13 * 10.0f;
      fVar14 = fVar14 * 10.0f;

    }

    FUN_003625e0(param_3);

    FUN_0038a7c0_vec(&vecA,&vecB);

    FUN_00386110((u32 *)&pfStack_4,(u32 *)&pfStack_8);

    if (((*(u16 *)DAT_007e094c_abs) & 0x1000) != 0) {

      *pfStack_4 = vecA.x * fVar13 + *pfStack_4 + 0.0f;
      pfStack_4[1] = vecA.y * fVar13 + pfStack_4[1] + 0.0f;
      pfStack_4[2] = vecA.z * fVar13 + pfStack_4[2] + 0.0f;

    }

    else {

      if (((*(u16 *)DAT_007e094c_abs) & 0x4000) != 0) {

        *pfStack_4 = (*pfStack_4 + 0.0f) - vecA.x * fVar13;
        pfStack_4[1] = (pfStack_4[1] + 0.0f) - vecA.y * fVar13;
        pfStack_4[2] = (pfStack_4[2] + 0.0f) - vecA.z * fVar13;

      }

    }

    if (((*(u16 *)DAT_007e094c_abs) & 0x2000) != 0) {

      *pfStack_4 = (*pfStack_4 + 0.0f) - vecB.x * fVar13;
      pfStack_4[1] = (pfStack_4[1] + 0.0f) - vecB.y * fVar13;
      pfStack_4[2] = (pfStack_4[2] + 0.0f) - vecB.z * fVar13;

    }

    else {

      if (((*(u16 *)DAT_007e094c_abs) & 0x8000) != 0) {

        *pfStack_4 = vecB.x * fVar13 + *pfStack_4 + 0.0f;
        pfStack_4[1] = vecB.y * fVar13 + pfStack_4[1] + 0.0f;
        pfStack_4[2] = vecB.z * fVar13 + pfStack_4[2] + 0.0f;

      }

    }

    if (((*(u16 *)DAT_007e094c_abs) & 4) != 0) {

      pfStack_4[1] = pfStack_4[1] + fVar13 / 2.0f;

    }

    else {

      if (((*(u16 *)DAT_007e094c_abs) & 1) != 0) {

        pfStack_4[1] = pfStack_4[1] - fVar13 / 2.0f;

      }

    }

    if (((*(u16 *)DAT_007e094c_abs) & 8) != 0) {

      pfStack_8[1] = pfStack_8[1] - fVar14;

    }

    else {

      if (((*(u16 *)DAT_007e094c_abs) & 2) != 0) {

        pfStack_8[1] = pfStack_8[1] + fVar14;

      }

    }

    fVar14 = DAT_00958848_f32_abs[0];

    fVar13 = DAT_00958844_f32_abs[0];

    if (((*(u16 *)DAT_007e0952_abs) & 0x100) != 0) {

      DAT_00958840_f32_abs[0] = *pfStack_4;

      DAT_00958844_f32_abs[0] = pfStack_4[1];

      DAT_00958848_f32_abs[0] = pfStack_4[2];

      DAT_00958830_f32_abs[0] = *pfStack_8;

      DAT_00958834_f32_abs[0] = pfStack_8[1];

      DAT_00958838_f32_abs[0] = pfStack_8[2];

    }

    else {

      if (((*(u16 *)DAT_007e0952_abs) & 0x800) != 0) {

        *pfStack_4 = DAT_00958840_f32_abs[0];

        pfStack_4[1] = fVar13;

        pfStack_4[2] = fVar14;

        fVar14 = DAT_00958838_f32_abs[0];

        fVar13 = DAT_00958834_f32_abs[0];

        *pfStack_8 = DAT_00958830_f32_abs[0];

        pfStack_8[1] = fVar13;

        pfStack_8[2] = fVar14;

      }

    }

    if (((*(u16 *)DAT_007e094e_abs & 0x200) != 0) &&

       ((((FUN_005225a8(0x69ebc0), iVar6 == 0x25 && (*(char *)(iVar7 + 0x10) == '\0')) &&

         (*(char *)(iVar7 + 0x13) == '\x01')) || ((iVar6 == 1 || (iVar6 == 0x30)))))) {

      FUN_00362f20(param_3);

    }

    if (((*(u16 *)DAT_007e094c_abs) & 0x80) != 0) {
      rayIn.x = *pfStack_4;
      rayIn.y = pfStack_4[1];
      rayIn.z = pfStack_4[2];
      rayIn.dx = *pfStack_4;
      rayIn.dy = pfStack_4[2];
      rayIn.dz = pfStack_4[1] - 1000.0f;

      lVar10 = FUN_001acc30_vec(&rayIn,&rayOut);

      if (lVar10 == 1) {

        *pfStack_4 = rayOut.x;
        pfStack_4[1] = rayOut.y;
        pfStack_4[2] = rayOut.z;

      }

    }

    vec88.x = *pfStack_4;
    vec88.y = pfStack_4[1];
    vec88.z = pfStack_4[2];

    vec98.x = *pfStack_8;
    vec98.y = pfStack_8[1];
    vec98.z = pfStack_8[2];

    FUN_003bb9b0_vec(&vec98);

    *pfStack_8 = vec98.x;
    pfStack_8[1] = vec98.y;
    pfStack_8[2] = vec98.z;

    FUN_003b79a0_vec(auStack_180,&vec88,&vec98);

    FUN_003957d0(100.0f, param_3, (u32*)auStack_180);

    break;

  case 9:

    lVar10 = FUN_003b5d10(0x1e59);

    if (lVar10 != 0) {

      iVar6 = (int)lVar10;

      *(float *)(iVar6 + 4) = *(float *)(param_3 + 0x198);

      *(float *)(iVar6 + 8) = *(float *)(param_3 + 0x19c);

      *(float *)(iVar6 + 0xc) = *(float *)(param_3 + 0x1a0);

      *(float *)(iVar6 + 0x10) = *(float *)(param_3 + 0x1a4);

      *(float *)(iVar6 + 0x14) = *(float *)(param_3 + 0x1a8);

      *(float *)(iVar6 + 0x100) = *(float *)(param_3 + 0x1ac);

      FUN_003628f0(param_3);

      *(float *)(param_3 + 0x198) = *(float *)(iVar6 + 4);

      *(float *)(param_3 + 0x19c) = *(float *)(iVar6 + 8);

      *(float *)(param_3 + 0x1a0) = *(float *)(iVar6 + 0xc);

      *(float *)(param_3 + 0x1a4) = *(float *)(iVar6 + 0x10);

      *(float *)(param_3 + 0x1a8) = *(float *)(iVar6 + 0x14);

      *(float *)(param_3 + 0x1ac) = *(float *)(iVar6 + 0x100);


    }

    break;

  case 10:

    iStack_c = 0;

    FUN_003625e0(param_3);

    FUN_00386390((u32 *)&iStack_c,(u32 *)&piStack_10,(u32 *)&piStack_14,(u32 *)auStack_18);

    lVar10 = FUN_003b5d10(*(u16 *)(iStack_c + *piStack_14 * 2));

    if (lVar10 != 0) {

      FUN_00396270(0x42340000,param_3,(int)lVar10 + 4);

    }

    lVar10 = FUN_003863c0();

    if (lVar10 == 1) {

      if ((DAT_007e0952 & 0x2000) == 0) {

        if ((DAT_007e0952 & 0x8000) != 0) {

          if (*piStack_14 != 0) {

            *piStack_14 = *piStack_14 + -1;

          }

          else {

            *piStack_14 = *piStack_10 + -1;

          }

        }

      }

      else if (*piStack_14 == *piStack_10 + -1) {

        *piStack_14 = 0;

      }

      else {

        *piStack_14 = *piStack_14 + 1;

      }

    }

    break;

  case 0xb:

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),0);

    *(u32 *)(param_3 + 0x198) = *puVar8;

    break;

  case 0xc:

    FUN_003625e0(param_3);

    FUN_00386210((u32 *)&pfStack_4,(u32 *)&pfStack_8);

    if (((*(u16 *)DAT_007e094c_abs) & 0x2000) != 0) {

      pfStack_8[1] = pfStack_8[1] - 2.0f;

    }

    else {

      if (((*(u16 *)DAT_007e094c_abs) & 0x8000) != 0) {

        pfStack_8[1] = pfStack_8[1] + 2.0f;

      }

    }

    if (((*(u16 *)DAT_007e094c_abs) & 0x1000) != 0) {

      *pfStack_8 = *pfStack_8 + 2.0f;

    }

    else {

      if (((*(u16 *)DAT_007e094c_abs) & 0x4000) != 0) {

        *pfStack_8 = *pfStack_8 - 2.0f;

      }

    }

    if (((*(u16 *)DAT_007e094c_abs) & 0x100) != 0) {

      *pfStack_8 = 0.0f;
      pfStack_8[1] = 0.0f;

    }

    vecA8.x = *pfStack_4;
    vecA8.y = pfStack_4[1];
    vecA8.z = pfStack_4[2];

    vecB8.x = *pfStack_8;
    vecB8.y = pfStack_8[1];
    vecB8.z = pfStack_8[2];

    FUN_003bb9b0_vec(&vecB8);

    *pfStack_8 = vecB8.x;
    pfStack_8[1] = vecB8.y;
    pfStack_8[2] = vecB8.z;

    FUN_003b79a0_vec(auStack_1c0,&vecA8,&vecB8);

    FUN_003957d0(100.0f, param_3, (u32*)auStack_1c0);

    break;

  case 0xd:

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),0);

    *(u32 *)(param_3 + 0x198) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),1);

    *(u32 *)(param_3 + 0x19c) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),2);

    *(u32 *)(param_3 + 0x1a0) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),3);

    *(u32 *)(param_3 + 0x1a4) = *puVar8;

    break;

  case 0xe:

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),0);

    *(u32 *)(param_3 + 0x198) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),1);

    *(u32 *)(param_3 + 0x19c) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),2);

    *(u32 *)(param_3 + 0x1a0) = *puVar8;

    break;

  case 0xf:

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),0);

    *(u32 *)(param_3 + 0x198) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),1);

    *(u32 *)(param_3 + 0x19c) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),2);

    *(u32 *)(param_3 + 0x1a0) = *puVar8;

    break;

  case 0x10:

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),0);

    *(u32 *)(param_3 + 0x198) = *puVar8;

    puVar8 = (u32 *)FUN_001a42f0(*(u32 *)(param_3 + 0xe8),1);

    *(u32 *)(param_3 + 0x19c) = *puVar8;

    break;

  case 0x11:

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),0);

    *(u32 *)(param_3 + 0x198) = *puVar8;

    break;

  case 0x12:

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),0);

    *(u32 *)(param_3 + 0x198) = *puVar8;

    puVar8 = (u32 *)FUN_001a41b0(*(u32 *)(param_3 + 0xe8),1);

    *(u32 *)(param_3 + 0x19c) = *puVar8;

    break;

  default:

    if (((*(u16 *)DAT_007e094e_abs) & 0x800) != 0) {

      bVar2 = false;

    }

  }

  if (((*(u16 *)DAT_007e094e_abs) & 0x20) == 0) {

    if (((*(u16 *)DAT_007e094e_abs) & 0x40) != 0 && (*(int *)(param_3 + 0xe8) != 0)) {

      if (iVar1 == 8) {

        FUN_0038a0c0(param_3,1);

      }

      FUN_00195020(*(u32 *)(param_3 + 0xe8));

      *(u32 *)(param_3 + 0xe8) = 0;

      return 1;

    }

  }

  else if (*(int *)(param_3 + 0xe8) != 0) {

    FUN_00195020();

    *(u32 *)(param_3 + 0xe8) = 0;

    if (iVar1 == 8) {

      FUN_0038a0c0(param_3,1);

    }

    else if (iVar1 == 9) {

      FUN_0038a620(param_3,2);

    }

    else if (iVar1 == 4) {

      FUN_0038b140(*(u32 *)(param_3 + 0x210));

    }

    return 0xffffffff;

  }

  if (bVar2) {

    uVar9 = 0;

  }

  else {

    if (*(int *)(param_3 + 0xe8) != 0) {

      FUN_0035adb0(*(int *)(param_3 + 0xe8),1);

      *(u32 *)(param_3 + 0xe8) = 0;

    }

    uVar9 = 1;

  }

  return uVar9;

}
#pragma pop


// FUN_003747A0


void FUN_003747a0(int param_1,int param_2,int param_3,int param_4)



{

  int iVar4;

  u16 *puVar5;

  u8 *puVar6;

  int lVar7;

  int iVar8;

  u32 uVar9;

  int iVar10;

  u32 uVar11;

  f32 uVar12;

  u8 auStack_50 [72];

  f32 fStack_4;

  f32 fStack_8;

  

  iVar8 = (int)param_4;

  if (param_3 == *(int *)(iVar8 + 0x108) + *(int *)(iVar8 + 0x110)) {

    uVar11 = 4;

  }

  else {

    uVar11 = 0;

  }

  if (param_3 == 0) {

    uVar12 = FUN_0038a220(*(u32 *)(iVar8 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar12, uVar11, (const char *)&gp0xffffa160);

  }

  else {

    lVar7 = FUN_003b5d00();

    if (lVar7 != 0) {

      if (*(int *)(iVar8 + 0x108) + *(int *)(iVar8 + 0x110) == 0) {

        if (*(int *)(iVar8 + 0x660) == 10) {

          if (*(int *)(iVar8 + 0x860) != 0) {

            FUN_00318ad0(*(int *)(iVar8 + 0x860),iVar8 + 0x85c);

            *(u32 *)(iVar8 + 0x860) = 0;

          }

        }

        else if ((*(int *)(iVar8 + 0x660) == 0xb) && (*(int *)(iVar8 + 0x864) != 0)) {

          FUN_0034ff90(*(int *)(iVar8 + 0x864),iVar8 + 0x85c);

          *(u32 *)(iVar8 + 0x864) = 0;

        }

      }

      iVar10 = 0;

      for (uVar9 = 0; (int)uVar9 < 0x16; uVar9 = uVar9 + 1) {

        if (*(u32 *)(iVar8 + 0x660) == uVar9) {

          for (puVar5 = (u16 *)FUN_003b5430(lVar7,uVar9 & 0xff); puVar5 != (u16 *)0x0;

              puVar5 = *(u16 **)(puVar5 + 0x7c)) {

            iVar10 = iVar10 + 1;

            if ((iVar10 == *(int *)(iVar8 + 0x108) + *(int *)(iVar8 + 0x110)) &&

               (puVar5 != (u16 *)0x0)) {

              if (*(int *)(iVar8 + 0x660) == 10) {

                fStack_4 = DAT_007cce48;

                iVar4 = *(int *)(iVar8 + 0x860);

                if (iVar4 != *(int *)(puVar5 + 0x82)) {

                  if (iVar4 != 0) {

                    FUN_00318ad0(iVar4,iVar8 + 0x85c);

                    *(u32 *)(iVar8 + 0x860) = 0;

                  }

                  puVar6 = (u8 *)FUN_00318b00(*(u32 *)(puVar5 + 0x82));

                  *(RwRGBA *)(iVar8 + 0x85c) = *(RwRGBA *)puVar6;

                  *(u32 *)(iVar8 + 0x860) = *(u32 *)(puVar5 + 0x82);

                  FUN_00318ad0(*(u32 *)(puVar5 + 0x82),&fStack_4);

                }

              }

              else if (*(int *)(iVar8 + 0x660) == 0xb) {

                fStack_8 = DAT_007cce4c;

                iVar4 = *(int *)(iVar8 + 0x864);

                if (iVar4 != *(int *)(puVar5 + 0x82)) {

                  if (iVar4 != 0) {

                    FUN_0034ff90(iVar4,iVar8 + 0x85c);

                    *(u32 *)(iVar8 + 0x864) = 0;

                  }

                  FUN_00350040(*(u32 *)(puVar5 + 0x82),(u32 *)(iVar8 + 0x85c));

                  *(u32 *)(iVar8 + 0x864) = *(u32 *)(puVar5 + 0x82);

                  FUN_0034ff90(*(u32 *)(puVar5 + 0x82),&fStack_8);

                }

              }

              else {

                FUN_00396270_f32(50.0f,param_4,(f32 *)(puVar5 + 2));

              }

            }

            if (iVar10 == param_3) {

              FUN_00523ac8(auStack_50,DAT_0069ebd8,*puVar5 & 0x3ff);

              uVar12 = FUN_0038a220(*(u32 *)(iVar8 + 0xe0));

              evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar12, uVar11, (const char *)&gp0xffffa068, auStack_50);

              return;

            }

          }

        }

      }

    }

  }

  return;

}


#pragma opt_common_subs off
#pragma opt_lifetimes on
// FUN_00374AF0 NONMATCHING


s32 FUN_00374af0(s32 param_1,s32 param_2,s32 param_3)
{
  int iVar1;
  s32 result;
  int iVar3;
  int iVar4;
  int callCount;

  iVar3 = param_3;
  iVar4 = 0xd;
  iVar1 = FUN_003b5df0(*(u32 *)(iVar3 + 0x660));
  callCount = iVar1 + 1;
  FUN_0036f900(param_1,param_2,0xc,0xd,*(u32 *)(iVar3 + 0x108),callCount,param_3,0,
               (code *)FUN_003747a0);
  if (*(int *)(iVar3 + 0xd4) != 10) {
    return 0;
  }
  if (iVar1 + 1 < 0xd) {
    iVar4 = iVar1 + 1;
  }

  FUN_003625e0_i(param_3);
  callCount = iVar1 + 1;
  FUN_0036f680(iVar3 + 0x108,iVar3 + 0x110,callCount,iVar4,0,0x4000,0x1000);
  FUN_0036f680(0,0,1,1,0,0x2000,0x8000);
  if ((*(u16 *)DAT_007e094e_abs & 0x40) != 0) {
    result = 1;
  }
  else if ((*(u16 *)DAT_007e094e_abs & 0x20) != 0) {
    result = -1;
  }
  else {
    result = 0;
  }
  if ((((result == -1) || (result == 1)) && (*(int *)(iVar3 + 0x660) == 10)) &&
     (*(int *)(iVar3 + 0x860) != 0)) {
    FUN_00318ad0(*(int *)(iVar3 + 0x860),iVar3 + 0x85c);
    *(u32 *)(iVar3 + 0x860) = 0;
  }
  return result;
}


#pragma opt_lifetimes reset
#pragma opt_common_subs reset
// FUN_00374C90


u32 FUN_00374c90(int param_1,int param_2,int param_3)



{
  f32 uVar1;
  u8 auStack_20 [32];

  

  FUN_00523ac8(auStack_20,DAT_006a0000_abs - 0x1410,
               *(s16 *)((u8 *)&DAT_007cca68 - 0x6288),
               *(s16 *)((u8 *)&DAT_007cca6c - 0x6284));

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));
  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)&gp0xffffa068 - 0x5f98, (void *)auStack_20);
  return 2;

}


// FUN_00374D30


void FUN_00374d30(int param_1,int param_2,u32 param_3,u8 *param_4)
{
  int iVar2;
  int iVar3;
  u8 *pcVar4;
  f32 fVar1;

  pcVar4 = param_4;
  iVar3 = 0;
  if (*(int *)(pcVar4 + 0x12c) == (int)param_3) {
    iVar3 = 4;
  }

  switch (param_3) {
  case 0: {
    s32 scaledY = param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(pcVar4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, fVar1, 0xe, (const char *)&gp0xffffa168);
    fVar1 = FUN_0038a220(*(u32 *)(pcVar4 + 0xe0));
    evtMenuDrawText((param_1 + 8) * 0xc, scaledY, fVar1, iVar3, (const char *)&gp0xffffa170, (u32)*(s16 *)&gp0xffff9d78);
    break;
  }
  case 1:
    iVar2 = param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(pcVar4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, iVar2, fVar1, 0xe, (const char *)&gp0xffffa178);
    fVar1 = FUN_0038a220(*(u32 *)(pcVar4 + 0xe0));
    evtMenuDrawText((param_1 + 8) * 0xc, iVar2, fVar1, iVar3, (const char *)&gp0xffffa180, (u32)*(s16 *)&gp0xffff9d7c);
    break;
  case 2:
    break;
  case 3:
    fVar1 = FUN_0038a220(*(u32 *)(pcVar4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar1, iVar3, (const char *)DAT_0069ec08_abs);
    break;
  case 4:
    fVar1 = FUN_0038a220(*(u32 *)(pcVar4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar1, iVar3, (const char *)DAT_0069ec18_abs);
    break;
  case 5:
    fVar1 = FUN_0038a220(*(u32 *)(pcVar4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar1, iVar3, (const char *)DAT_0069ea78_abs);
    break;
  case 6:
    fVar1 = FUN_0038a220(*(u32 *)(pcVar4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar1, iVar3, (const char *)DAT_0069ea88_abs);
    break;
  case 7:
    fVar1 = FUN_0038a220(*(u32 *)(pcVar4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar1, iVar3, (const char *)DAT_0069ec28_abs);
    break;
  }
}


// FUN_00375000 NONMATCHING


int FUN_00375000(int param_1,int param_2,int param_3)



{

  int iVar1;

  

  FUN_0036f900(param_1,param_2,0x12,0xb,0,8,param_3,0x374c90,(code *)0x374d30);

  iVar1 = (int)param_3;

  if (*(int *)(iVar1 + 0xd4) != 9) {

    iVar1 = 0;

  }

  else {

    if ((*(u16*)DAT_007e094e_abs & 0x1000) != 0) {

      *(u32 *)(iVar1 + 300) = *(u32 *)(iVar1 + 300) ^ 1;

    }

    if ((*(u16*)DAT_007e094e_abs & 0x4000) != 0) {

      *(u32 *)(iVar1 + 300) = *(u32 *)(iVar1 + 300) ^ 1;

    }

    if ((*(u16*)DAT_007e0952_abs & 0x8000) != 0) {

      switch (*(int *)(iVar1 + 300)) {
      case 0:
        if (0 < DAT_007cca68) {
          DAT_007cca68 = DAT_007cca68 + -1;
        }
        break;
      case 1:
        if (1 < DAT_007cca6c) {
          DAT_007cca6c = DAT_007cca6c + -1;
        }
        break;
      }

    }

    if ((*(u16*)DAT_007e0952_abs & 0x2000) != 0) {

      if (*(int *)(iVar1 + 300) == 1) {
        if (DAT_007cca6c < 999) {
          DAT_007cca6c = DAT_007cca6c + 1;
        }
      }
      else if ((*(int *)(iVar1 + 300) == 0) && (DAT_007cca68 < 999)) {
        DAT_007cca68 = DAT_007cca68 + 1;
      }

    }

    if ((*(u16*)DAT_007e0952_abs & 4) != 0) {

      if (*(int *)(iVar1 + 300) == 1) {
        if ((1 < DAT_007cca6c) && (DAT_007cca6c = DAT_007cca6c + -10, DAT_007cca6c < 1)) {
          DAT_007cca6c = 1;
        }
      }
      else if (*(int *)(iVar1 + 300) == 0) {
        DAT_007cca68 = DAT_007cca68 + -10;
      }

    }

    if ((*(u16*)DAT_007e0952_abs & 1) != 0) {

      if (*(int *)(iVar1 + 300) == 1) {
        DAT_007cca6c = DAT_007cca6c + -100;
      }
      else if (*(int *)(iVar1 + 300) == 0) {
        DAT_007cca68 = DAT_007cca68 + -100;
      }

    }

    if ((*(u16*)DAT_007e0952_abs & 8) != 0) {

      if (*(int *)(iVar1 + 300) == 1) {
        DAT_007cca6c = DAT_007cca6c + 10;
      }
      else if (*(int *)(iVar1 + 300) == 0) {
        DAT_007cca68 = DAT_007cca68 + 10;
      }

    }

    if ((*(u16*)DAT_007e0952_abs & 2) != 0) {

      if (*(int *)(iVar1 + 300) == 1) {
        DAT_007cca6c = DAT_007cca6c + 100;
      }
      else if (*(int *)(iVar1 + 300) == 0) {
        DAT_007cca68 = DAT_007cca68 + 100;
      }

    }

    if (999 < DAT_007cca68) {

      DAT_007cca68 = 999;

    }

    if (DAT_007cca68 < 0) {

      DAT_007cca68 = 0;

    }

    if (DAT_007cca6c < 1) {

      DAT_007cca6c = 1;

    }

    if (999 < DAT_007cca6c) {

      DAT_007cca6c = 999;

    }

    if ((*(u16*)DAT_007e094e_abs & 0x40) != 0) {

      iVar1 = 1;

    }

    else {

      iVar1 = -(u32)((*(u16*)DAT_007e094e_abs & 0x20) != 0);

    }

  }

  return iVar1;

}


// FUN_00375350


u32 FUN_00375350(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069ec38);

  return 2;

}


// FUN_003753C0


void FUN_003753c0(int param_1,int param_2,u32 param_3,u8 *param_4)



{

  f32 fVar1;

  u32 uVar1;



  switch (param_3) {

  case 0:

    fVar1 = FUN_0038a220(*(u32 *)((u8 *)param_4 + 0xe0));

    uVar1 = FUN_00530da0_evt(*(f32 *)((u8 *)param_4 + 0x184));

    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 4, (const char *)DAT_0069ec48, uVar1);

    break;

  case 1:
    break;

  case 2:

    fVar1 = FUN_0038a220(*(u32 *)((u8 *)param_4 + 0xe0));

    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 0, (const char *)DAT_0069ec60);

    break;

  case 3:

    fVar1 = FUN_0038a220(*(u32 *)((u8 *)param_4 + 0xe0));

    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 0, (const char *)DAT_0069ec80);

    break;

  case 4:

    fVar1 = FUN_0038a220(*(u32 *)((u8 *)param_4 + 0xe0));

    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 0, (const char *)DAT_0069ea78);

    break;

  case 5:

    fVar1 = FUN_0038a220(*(u32 *)((u8 *)param_4 + 0xe0));

    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 0, (const char *)DAT_0069ea88);

    break;

  }

}


// b210 floor: the remaining nd19 is callback argument setup ordering at +0x1c..+0x34;
// the clamp/input body and its 332-byte object otherwise match retail instruction-for-instruction.
// FUN_00375590


u32 FUN_00375590(int param_1,int param_2,int param_3)



{

  u32 uVar1;

  EvtMenuClampWork *work;

  float fVar3;

  

  FUN_0036f900_evt(param_1,param_2,0x16,9,0,1,param_3,(code *)FUN_00375350,
                   (code *)FUN_003753c0);

  work = (EvtMenuClampWork *)param_3;

  if (work->state != 8) {

    uVar1 = 0;

  }

  else {

    if ((*(u16 *)DAT_007e094e_abs & 0x40) != 0) {

      uVar1 = 1;

    }

    else {

      if ((*(u16 *)DAT_007e094e_abs & 0x20) != 0) {

        uVar1 = 0xffffffff;

      }

      else {

        fVar3 = 0.0f;
        if ((*(u16 *)DAT_007e0952_abs & 0x8000) != 0) {
          fVar3 = DAT_007cb0cc;
        }
        else if ((*(u16 *)DAT_007e0952_abs & 0x2000) != 0) {
          fVar3 = DAT_007cb088;
        }

        if ((*(u16 *)DAT_007e0952_abs & 0x1000) != 0) {

          fVar3 = -1.0;

        }

        else {

          if ((*(u16 *)DAT_007e0952_abs & 0x4000) != 0) {

            fVar3 = 1.0;

          }

        }
        work->value = work->value + fVar3;

        if (work->value < work->minimum) {

          work->value = work->minimum;

        }

        if (!(work->value < work->maximum)) {

          work->value = work->maximum;

        }

        uVar1 = 0;

      }

    }

  }

  return uVar1;

}


// FUN_003756E0


u32 FUN_003756e0(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069ec38);

  return 2;

}


// FUN_00375750


void FUN_00375750(int param_1,int param_2,u32 param_3,u8 *param_4)
{
  f32 fVar1;

  switch (param_3) {
  case 0:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 4, (const char *)&gp0xffffa108, *(u32 *)(param_4 + 0x16c));
    break;
  case 1:
    break;
  case 2:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 0, (const char *)DAT_0069ea58_abs);
    break;
  case 3:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 0, (const char *)DAT_0069eca0_abs);
    break;
  case 4:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 0, (const char *)DAT_0069ea78_abs);
    break;
  case 5:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 0, (const char *)DAT_0069ea88_abs);
    break;
  }
}


// FUN_00375900


u32 FUN_00375900(int param_1,int param_2,int param_3)



{

  typedef struct {
    u8 pad0[0xd4];
    int state;
    u8 padD8[0x94];
    int value;
    int lowerBound;
    int upperBound;
  } EvtMenuRangeState;
  int iVar2;
  u32 uVar1;
  EvtMenuRangeState *menu;
  int *value;

  

  FUN_0036f900_evt(param_1,param_2,0x16,9,0,1,param_3,(code *)FUN_003756e0,
                   (code *)FUN_00375750);

  menu = (EvtMenuRangeState *)param_3;

  if (menu->state != 7) {

    uVar1 = 0;

  }

  else {

    if ((*(u16 *)DAT_007e094e_abs & 0x40) != 0) {

      uVar1 = 1;

    }

    else {

      if ((*(u16 *)DAT_007e094e_abs & 0x20) != 0) {

        uVar1 = 0xffffffff;

      }

      else {

        iVar2 = 0;

        if ((*(u16 *)DAT_007e0952_abs & 0x8000) != 0) {

          iVar2 = -1;

        }

        else {

          if ((*(u16 *)DAT_007e0952_abs & 0x2000) != 0) {

            iVar2 = 1;

          }

        }

        if ((*(u16 *)DAT_007e0952_abs & 0x1000) != 0) {

          iVar2 = -10;

        }

        else {

          if ((*(u16 *)DAT_007e0952_abs & 0x4000) != 0) {

            iVar2 = 10;

          }

        }

        value = &menu->value;
        *value += iVar2;
        iVar2 = *value;

        if (iVar2 < menu->lowerBound) {

          menu->value = menu->lowerBound;

        }

        if (menu->value >= menu->upperBound) {
          menu->value = menu->upperBound;

        }

        uVar1 = 0;

      }

    }

  }

  return uVar1;

}


// FUN_00375A40


u32 FUN_00375a40(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069ecb8);

  return 2;

}


// FUN_00375AB0


void FUN_00375ab0(int param_1,int param_2,u32 param_3,u8 *param_4)
{
  f32 fVar1;

  switch (param_3) {
  case 0:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 0, (const char *)(void *)&gp0xffffa108, *(u32 *)(param_4 + 0x16c));
    break;
  case 1:
    break;
  case 2:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 0, (const char *)(void *)DAT_0069ecc8);
    break;
  case 3:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 0, (const char *)(void *)DAT_0069ece0);
    break;
  case 4:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 0, (const char *)(void *)DAT_0069ed00);
    break;
  case 5:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 0, (const char *)(void *)DAT_0069ea78);
    break;
  case 6:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 0, (const char *)(void *)DAT_0069ea88);
    break;
  case 7:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 0, (const char *)(void *)DAT_0069ed20);
    break;
  case 8:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 0, (const char *)(void *)DAT_0069ed40);
    break;
  case 9:
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((int)(param_1 * 0xc), (int)(param_2 * 0xc), fVar1, 0, (const char *)(void *)DAT_0069ed60);
    break;
  }
}


// FUN_00375D70 NONMATCHING


u32 FUN_00375d70(int param_1,int param_2,int param_3)



{

  u32 uVar1;

  int iVar2;

  int iVar3;

  

  FUN_0036f900_evt(param_1,param_2,0x16,0xb,0,1,param_3,
               (code *)FUN_00375a40,(code *)FUN_00375ab0);

  iVar3 = (int)param_3;

  if (*(int *)(iVar3 + 0xd4) == 6) goto process_75d70;
  uVar1 = 0;
  goto done_75d70;
process_75d70:

    if ((*(u16 *)DAT_007e094e_abs & 0x40) != 0) {
      uVar1 = 1;
      goto done_75d70;
    }


    if ((*(u16 *)DAT_007e094e_abs & 0x20) != 0) {
      uVar1 = 0xffffffff;
      goto done_75d70;
    }

        iVar2 = 0;

        if ((*(u16 *)DAT_007e0952_abs & 0x8000) == 0) goto set_75d70_dir1;
        iVar2 = -1;
        goto done_75d70_dir1;
set_75d70_dir1:
        if ((*(u16 *)DAT_007e0952_abs & 0x2000) == 0) goto done_75d70_dir1;
        iVar2 = 1;
done_75d70_dir1:
        if ((*(u16 *)DAT_007e0952_abs & 0x1000) == 0) goto set_75d70_dir2;
        iVar2 = -10;
        goto done_75d70_dir2;
set_75d70_dir2:
        if ((*(u16 *)DAT_007e0952_abs & 0x4000) == 0) goto done_75d70_dir2;
        iVar2 = 10;
done_75d70_dir2:
        if ((*(u16 *)DAT_007e0952_abs & 4) == 0) goto set_75d70_dir3;
        iVar2 = -100;
        goto done_75d70_dir3;
set_75d70_dir3:
        if ((*(u16 *)DAT_007e0952_abs & 8) == 0) goto done_75d70_dir3;
        iVar2 = 100;
done_75d70_dir3:


        if ((*(u16 *)DAT_007e094e_abs & 0x80) != 0) {

          iVar2 = *(int *)(iVar3 + 0x18) - *(int *)(iVar3 + 0x16c);

        }

        iVar2 = *(int *)(iVar3 + 0x16c) + iVar2;

        *(int *)(iVar3 + 0x16c) = iVar2;

        if (iVar2 < *(int *)(iVar3 + 0x170)) {

          *(int *)(iVar3 + 0x16c) = *(int *)(iVar3 + 0x170);

        }

        if (*(int *)(iVar3 + 0x174) <= *(int *)(iVar3 + 0x16c)) {

          *(int *)(iVar3 + 0x16c) = *(int *)(iVar3 + 0x174);

        }

        if (((DAT_007e094c & 0x800) != 0) && (*(int *)(iVar3 + 0x18) != *(int *)(iVar3 + 0x16c))) {

          *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x16c);

          FUN_00362240(param_3);

        }

        uVar1 = 0;




done_75d70:


  return uVar1;

}


// FUN_00375F30


u32 FUN_00375f30(int param_1,int param_2,int param_3)



{

  char cVar1;

  int iVar2;

  int iVar5;

  int iVar6;

  short *psVar3;

  int iVar4;

  int iVar7;

  f32 uVar6;

  

  iVar7 = **(int **)(param_3 + 0x164);
  iVar5 = iVar7;
  iVar5 = 0;
  psVar3 = (short *)(DAT_0069e1a0 + iVar7 * 0xc);
  iVar6 = param_2 * 0xc;

  while (iVar5 < *psVar3) {

    iVar4 = iVar5;

    cVar1 = *(char *)((int)psVar3 + iVar4 + 2);

    if (cVar1 == '\x15') {

      *(u8 **)(param_3 + 0x27c) = (u8 *)&DAT_007cce78;

      *(u32 *)(param_3 + 0x280) = 0;

      uVar6 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, iVar6, uVar6, 0xe, (const char *)&gp0xffffa068, *(u32 *)(param_3 + 0x27c));

      iVar2 = *(int *)(param_3 + 0x280);
      param_1 = param_1 + iVar2;

    }

    else {

      uVar6 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, iVar6, uVar6, 0xe, (const char *)&gp0xffffa068, *(u32 *)(PTR_s_START_0069e100_abs + cVar1));

      iVar2 = (int)DAT_0069e180_char[*(char *)((int)psVar3 + iVar4 + 2)];
      param_1 = param_1 + iVar2;

    }


    iVar5 = iVar4 + 1;

  }

  return 1;

}


/* opt_lifetimes on: default nd10238/14020B -> nd10038/14020B; retained. */
#pragma push
#pragma opt_lifetimes on
// FUN_003760A0 NONMATCHING


void FUN_003760a0(int param_1,int param_2_in,u32 param_3,u16 *param_4,int param_5)



{

  u8 bVar1;

  char cVar2;

  u16 uVar3;

  u8 *puVar4;

  u32 uVar5;

  u64 uVar6;

  short *psVar7;

  u32 uVar8;

  int iVar9;

  u32 *puVar10;

  u8 **ppuVar11;

  u32 uVar12;

  u32 uVar13;

  int iVar14;

  int lVar15;

  u8 *puVar16;

  int iVar17;

  int param_2;

  f32 uVar18;

  u32 uStack_f0;

  u32 auStack_d0 [8];

  u32 auStack_b0 [8];

  u8 *apuStack_90 [4];

  u8 *apuStack_80 [6];

  u8 *apuStack_68 [4];


  u8 *apuStack_40 [4];

  u8 *apuStack_30 [4];


  u8 *apuStack_8 [2];

  

  apuStack_8[0] = PTR_s_MOVE_D_007ccf10;

  apuStack_8[1] = PTR_s_ACTIVE_007ccf14;

  apuStack_80[0] = PTR_DAT_0069ee10;

  apuStack_80[1] = PTR_s_FADEOUT_0069ee14;

  apuStack_80[2] = PTR_s_KUCHI_0069ee18;

  apuStack_80[3] = PTR_s_MEPACHI_0069ee1c;


  apuStack_90[0] = PTR_s_CREATE_0069ee30;

  apuStack_90[1] = PTR_s_MOVE_D_0069ee34;

  apuStack_90[2] = PTR_s_DELETE_0069ee38;

  apuStack_90[3] = PTR_s_ALPHA_0069ee3c;


  apuStack_30[2] = PTR_DAT_007ccf60;

  apuStack_30[3] = PTR_DAT_007ccf64;

  apuStack_30[0] = PTR_s_CAPTURE_007ccf78;

  apuStack_30[1] = PTR_DAT_007ccf7c;

  apuStack_40[0] = PTR_DAT_0069ee40;

  apuStack_40[1] = PTR_DAT_0069ee44;

  apuStack_40[2] = PTR_DAT_0069ee48;


  apuStack_68[2] = PTR_DAT_007ccfa8;

  apuStack_68[3] = PTR_s_NOSTOP_007ccfac;

  apuStack_68[0] = PTR_s_NO_KEYFREE_007ccfb8;

  apuStack_68[1] = PTR_s_KEYFREE_007ccfbc;

  ppuVar11 = &PTR_DAT_0069eeb0;

  puVar10 = auStack_b0;

  iVar9 = 3;

  do {

    puVar16 = *ppuVar11;

    puVar4 = ppuVar11[1];

    ppuVar11 = ppuVar11 + 2;

    iVar9 = iVar9 + -1;

    *puVar10 = (u32)puVar16;

    puVar10[1] = (u32)puVar4;

    puVar10 = puVar10 + 2;

  } while (0 < iVar9);

  uVar13 = 0;

  iVar9 = **(int **)(param_5 + 0x164);

  psVar7 = (short *)(DAT_0069e1a0 + iVar9 * 0xc);

  param_2 = param_2_in * 0xc;

  lVar15 = 0;

  while (lVar15 < *psVar7) {

    uVar12 = param_3;

    if (*(int *)(param_5 + 0x158) != lVar15) {

      uVar12 = 0;

    }

    iVar14 = (int)lVar15;

    switch(*(u8 *)((int)psVar7 + iVar14 + 2)) {

    case 0:

      uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd010, (u32)*param_4 + (int)*(short *)(*(int *)(param_5 + 0x164) + 0x20));

      break;

    case 1:

      if (iVar9 == 10) {

        if (*(char *)(*(int *)(param_5 + 0x164) + 0x22) != '\x03') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd018);

        }

        else {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd010, param_4[1]);

        }

      }

      else {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd010, param_4[1]);

      }

      break;

    case 2:

      if (iVar9 == 7) {

        uVar13 = (u32)(short)param_4[8];

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd010, uVar13);

      }

      break;

    case 3:

      if (iVar9 == 0x1f) {

        uVar13 = (u32)(short)param_4[9];

      }

      else if (iVar9 == 0xc) {

        uVar13 = (u32)(short)param_4[9];

      }

      else if (iVar9 == 8) {

        uVar13 = (u32)(short)param_4[8];

      }

      if ((iVar9 == 0x1f) && (param_4[8] == 0)) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd030);

      }

      else {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd010, uVar13);

      }

      break;

    case 4:

      uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd010, param_4[9]);

      break;

    case 5:

      if (iVar9 == 0x19) {

        uVar13 = (u32)(short)param_4[10];

      }

      else if (iVar9 == 0x18) {

        uVar13 = (u32)(char)param_4[8];

      }

      else if ((((iVar9 == 0x1b) || (iVar9 == 0x17)) || (iVar9 == 0xf)) ||

              (((iVar9 == 0x11 || (iVar9 == 0x10)) ||

               ((iVar9 == 0xe || ((iVar9 == 0xd || (iVar9 == 0xb)))))))) {

        uVar13 = (u32)(short)param_4[8];

      }

      else if (iVar9 == 10) {

        uVar13 = (u32)*(int *)(param_4 + 2);

      }

      else if (iVar9 == 8) {

        uVar13 = (u32)(short)param_4[10];

      }

      if (uVar13 != 0) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd034);

      }

      else {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd038);

      }

      break;

    case 6:

      uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

      uVar5 = FUN_00530da0_evt(DAT_007cadc0 * *(float *)(param_4 + 8));

      evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)(void *)0x7cd0a0, uVar5);

      break;

    case 7:

    case 0x16:

      break;

    case 8:

      if (iVar9 == 0x26) {

        uVar13 = (u32)(short)param_4[8];

      }

      else if (iVar9 == 2) {

        uVar13 = (u32)(short)param_4[0xb];

      }

      else if (iVar9 == 6) {

        uVar13 = (u32)(short)param_4[9];

      }

      else if (iVar9 == 0x1e) {

        uVar13 = (u32)(short)param_4[8];

      }

      else if (iVar9 == 0x1d) {

        uVar13 = (u32)(short)param_4[8];

      }

      else if (iVar9 != 0x1c) {

        if (iVar9 == 4) {

          uVar13 = (u32)(short)param_4[8];

        }

        else if (iVar9 == 0x12) {

          uVar13 = (u32)(char)param_4[10];

        }

        else if (iVar9 == 0xc) {

          uVar13 = (u32)*(int *)(param_4 + 10);

        }

        else if (iVar9 == 0x1a) {

          uVar13 = (u32)*(char *)((int)param_4 + 0x15);

        }

        else if (iVar9 == 3) {

          uVar13 = (u32)*(char *)((int)param_4 + 0x15);

        }

        else if (iVar9 == 0x13) {

          uVar13 = (u32)(short)param_4[9];

        }

        else if (iVar9 == 5) {

          uVar13 = (u32)(short)param_4[8];

        }

      }

      uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd0a8, uVar13);

      break;

    case 9:

      if (iVar9 == 0x21) {

        uVar13 = (u32)(short)param_4[8];

      }

      else if ((iVar9 == 0x15) || (iVar9 == 0x14)) {

        uVar13 = (u32)(short)param_4[9];

      }

      else if (iVar9 == 0x12) {

        uVar13 = (u32)(short)param_4[8];

      }

      else if (iVar9 == 0x1a) {

        uVar13 = (u32)(short)param_4[9];

      }

      else if (iVar9 == 3) {

        uVar13 = (u32)(short)param_4[9];

      }

      uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd010, uVar13);

      break;

    case 10:

      if (iVar9 == 0x12) {

        uVar13 = (u32)(short)param_4[9];

      }

      else if (iVar9 == 9) {

        uVar13 = (u32)(short)param_4[8];

      }

      else if (iVar9 == 0x1a) {

        uVar13 = (u32)(short)param_4[0xb];

      }

      else if (iVar9 == 3) {

        uVar13 = (u32)(short)param_4[0xb];

      }

      if ((long)uVar13 < 0) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69ef50);

      }

      else {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd0b0, param_5 + (int)uVar13 * 0x20 + 0x54);

      }

      break;

    case 0xb:

      if (iVar9 == 0x19) {

        uVar13 = (u32)(short)param_4[8];

      }

      else if (iVar9 == 0x16) {

        uVar13 = (u32)(short)param_4[8];

      }

      else if (iVar9 == 9) {

        uVar13 = (u32)(short)param_4[9];

      }

      if (uVar13 != 0) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd09c);

      }

      else {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd038);

      }

      break;

    case 0xc:

      if (iVar9 == 4) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, apuStack_68[(char)param_4[10] + 2]);

      }

      else if (iVar9 == 0x22) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, apuStack_68[(char)param_4[8] + 4])

        ;

      }

      else if (iVar9 == 0x1d) {

        if ((char)param_4[10] != '\0') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69ef40);

        }

        else {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd040);

        }

      }

      else if (((iVar9 == 0x15) || (iVar9 == 0x14)) || ((iVar9 == 0x1a || (iVar9 == 3)))) {

        if ((char)param_4[0xc] != '\0') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd098);

        }

        else {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd090);

        }

      }

      else if (iVar9 == 0x18) {

        if ((char)param_4[0x12] != '\0') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd088);

        }

        else {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd080);

        }

      }

      else if (iVar9 == 0x20) {

        if (param_4[8] != 0) {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd078);

        }

        else {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd070);

        }

      }

      else if (iVar9 == 0x1f) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, apuStack_30[(short)param_4[8]]);

      }

      else if (iVar9 == 0x1e) {

        if (param_4[9] != 0) {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd068);

        }

        else {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd060);

        }

      }

      else if (iVar9 == 5) {

        cVar2 = (char)param_4[9];

        if (cVar2 == '\x03') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69ef30);

        }

        else if (cVar2 == '\x02') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69ef20);

        }

        else if (cVar2 == '\x01') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69ef10);

        }

        else if (cVar2 == '\0') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69ef00);

        }

      }

      else if (iVar9 == 10) {

        if (param_4[0xe] != 0) {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd058);

        }

        else {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd050);

        }

      }

      else if (iVar9 == 0x1c) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, apuStack_30[(char)param_4[8] + 4])

        ;

      }

      else if (iVar9 == 0x2f) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, (&PTR_DAT_007cca88)[(char)param_4[8]]);

      }

      else if (iVar9 == 0x2b) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, auStack_b0[(char)param_4[8]]);

      }

      else if (iVar9 == 0x29) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, (&PTR_s_HIRU_SASO_0069d880)[(char)param_4[8]]);

      }

      else if (iVar9 == 0x27) {

        uVar3 = param_4[8];

        if ((char)uVar3 < '\x02') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, apuStack_68[(char)uVar3]);

        }

      }

      else if (iVar9 == 0x25) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, apuStack_90[(char)param_4[8]]);

      }

      else if (iVar9 == 0x24) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, apuStack_30[(char)param_4[8] + 6])

        ;

      }

      else if (iVar9 == 0x23) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, apuStack_80[(char)param_4[8]]);

      }

      else if (iVar9 == 0x31) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, (&PTR_s_DISPONOFF_007ccaa8)[(char)param_4[8]]);

      }

      else if (iVar9 == 0x21) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, apuStack_8[(char)param_4[9]]);

      }

      else if (iVar9 == 0x30) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, (&PTR_DAT_0069ede0)[(char)param_4[8]]);

      }

      else if (iVar9 == 1) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, (&PTR_DAT_0069ede0)[(char)param_4[8]]);

      }

      else if (iVar9 == 0x13) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, (&PTR_DAT_0069ed90)[(short)param_4[8]]);

      }

      else if (iVar9 == 6) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, (&PTR_s_FADE_IN_007cce88)[(short)param_4[8]]);

      }

      else if (iVar9 == 0xc) {

        uVar3 = param_4[8];

        if (uVar3 == 2) {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd04c);

        }

        else if (uVar3 == 1) {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd048);

        }

        else if (uVar3 == 0) {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd040);

        }

      }

      break;

    case 0xd:

      if ((iVar9 == 0x24) && ((char)param_4[8] != '\0')) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd020);

      }

      else if ((iVar9 == 0x24) && ((char)param_4[8] == '\0')) {

        if ((char)param_4[0x10] == '\0') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd024);

        }

        else if ((char)param_4[0x10] == '\x01') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd028);

        }

      }

      else {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd02c);

      }

      break;

    case 0xe:

      uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

      uVar5 = FUN_00530da0_evt(*(f32 *)(param_4 + 8));

      uVar6 = FUN_00530da0(*(u32 *)(param_4 + 10));

      evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69eef0, uVar5, uVar6);

      break;

    case 0xf:

      if ((((iVar9 == 0x1a) || (iVar9 == 0x15)) || (iVar9 == 0x14)) || (iVar9 == 3)) {

        uVar13 = (u32)param_4[1];

      }

      uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd010, uVar13);

      break;

    case 0x10:

      if ((iVar9 == 0x1a) || (iVar9 == 3)) {

        uVar13 = (u32)(char)param_4[10];

      }

      else if ((iVar9 == 0x15) || (iVar9 == 0x14)) {

        uVar13 = (u32)*(char *)((int)param_4 + 0x11);

      }

      if (uVar13 != 0) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd09c);

      }

      else {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd038);

      }

      break;

    case 0x11:

      bVar1 = *(u8 *)((int)param_4 + 0x15);

      uVar3 = param_4[8];

      uVar13 = (u32)(short)uVar3;

      if (bVar1 < 7) {

        switch(bVar1) {

        case 0:

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd0b8, uVar13 & 0xfff);

          break;

        default:

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd0c0, (char)bVar1 + -1, uVar13 & 0xfff)

          ;

          break;

        case 6:

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd0c8);

        }

      }

      switch(bVar1) {

      case 0:

      case 1:

      case 2:

      case 3:

      case 4:

      case 5:

        uVar8 = (int)(short)uVar3 >> 0xc & 0xf;

        if (uVar8 != 0) {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText((param_1 + 6) * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd0cc, uVar8 - 1);

        }

        else {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText((param_1 + 6) * 0xc, param_2, uVar18, uVar12, (const char *)0x7ccf90);

        }

      }

      break;

    case 0x12:

      cVar2 = (char)param_4[6];

      if (cVar2 == '\0') {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd0d0);

      }

      else if (cVar2 == '\x02') {

        iVar17 = param_1 * 0xc;

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(iVar17, param_2, uVar18, uVar12, (const char *)0x69ef70, param_4[4], param_4[5]);

        cVar2 = (char)param_4[7];

        if (cVar2 == '\0') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(iVar17, param_2, uVar18, uVar12, (const char *)0x7cd0d4);

        }

        else if (cVar2 == '\x01') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(iVar17, param_2, uVar18, uVar12, (const char *)0x7cd0d8);

        }

        else if (cVar2 == '\x02') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(iVar17, param_2, uVar18, uVar12, (const char *)0x7cd0dc);

        }

      }

      else if (cVar2 == '\x01') {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69ef60, param_4[4], param_4[5]);

      }

      break;

    case 0x13:

      switch((char)param_4[8]) {

      case '\0':

        if ((char)param_4[10] != '\0') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd038);

        }

        else {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd09c);

        }

        break;

      case '\x01':

        cVar2 = (char)param_4[10];

        if (cVar2 == '\x02') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd0e8);

        }

        else if (cVar2 == '\x01') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd0e4);

        }

        else if (cVar2 == '\0') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd0e0);

        }

        if ((char)param_4[10] != '\x02') {

          if (*(char *)((int)param_4 + 0x15) == '\x01') {

            uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

            evtMenuDrawText((param_1 + 2) * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd0f8, param_4[0xb]);

          }

          else if (*(char *)((int)param_4 + 0x15) == '\0') {

            uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

            evtMenuDrawText((param_1 + 2) * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd0ec, (short)param_4[0xb] + 1)

            ;

            if ((char)param_4[0x12] == '\x01') {

              uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

              evtMenuDrawText((param_1 + 6) * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd0f0, (short)param_4[0xb] + 1);

            }

            if (*(char *)((int)param_4 + 0x25) == '\x01') {

              uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

              evtMenuDrawText((param_1 + 8) * 0xc, param_2, uVar18, uVar12, (const char *)0x7ccf84, (short)param_4[0xb] + 1);

            }

          }

        }

        break;

      case '\x02':

        if ((char)param_4[0x11] == '\0') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69ef80, (char)param_4[10], *(u8 *)((int)param_4 + 0x15), apuStack_30[(char)param_4[0xb] + 2], *(u8 *)((int)param_4 + 0x17));

        }

        else if ((char)param_4[0x11] == '\x01') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69ef98, *(u8 *)((int)param_4 + 0x15), apuStack_30[(char)param_4[0xb] + 2], *(u8 *)((int)param_4 + 0x17), param_4[0x10]);

        }

        break;

      case '\x03':

        uVar13 = (u32)(short)param_4[0xb];

        if (uVar13 != 0) {

          uVar3 = param_4[10];

          if ((char)uVar3 < '\x04') {

            uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

            evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, apuStack_40[(char)uVar3]);

          }

          cVar2 = *(char *)((int)param_4 + 0x15);

          if (cVar2 < '\x03') {

            uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

            evtMenuDrawText((param_1 + 2) * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, apuStack_68[cVar2 + 6]);

          }

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText((param_1 + 4) * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd100, uVar13);

        }

        else {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69ef50);

        }

        break;

      case '\x04':

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        uVar5 = FUN_00530da0(*(u32 *)(param_4 + 10));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd108, uVar5);

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText((param_1 + 7) * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd110, param_4[0x12]);

        break;

      case '\x05':

        if (*(char *)((int)param_4 + 0x15) == '\x01') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd118, (char)param_4[10]);

        }

        else if (*(char *)((int)param_4 + 0x15) == '\0') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd0b8, (char)param_4[10]);

        }

        break;

      case '\x06':

        if ((char)param_4[10] == '\x01') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69efc8);

        }

        else if ((char)param_4[10] == '\0') {

          if (*(char *)((int)param_4 + 0x15) != '\0') {

            uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

            evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69efb8);

          }

          else {

            uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

            evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69efa8);

          }

        }

        break;

      case '\a':

        if ((char)param_4[10] != '\0') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd128, *(u8 *)((int)param_4 + 0x15));

        }

        else {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd120, *(u8 *)((int)param_4 + 0x15));

        }

        break;

      case '\b':

        if (*(char *)((int)param_4 + 0x19) != '\0') {

          puVar16 = (u8 *)&DAT_007cd130;

        }

        else {

          puVar16 = (u8 *)&DAT_007ccf94;

        }

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69efd8, param_4[10], (char)param_4[0xc], puVar16);

        break;

      case '\t':

        if ((char)param_4[10] != '\0') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd038);

        }

        else {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd09c);

        }

        break;

      case '\n':

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        uVar5 = FUN_00530da0(*(u32 *)(param_4 + 0xc));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69efe8, param_4[10], uVar5);

        break;

      default:

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd134);

      }

      break;

    case 0x14:

      uVar13 = 0;

      if ((((iVar9 == 0x11) || (iVar9 == 0x17)) || (iVar9 == 0xf)) || (iVar9 == 0xe)) {

        uVar13 = (u32)(short)param_4[0xc];

      }

      else {

        FUN_0019d3f0(0x69e408,0x1363);

      }

      if (uVar13 == 0) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd138);

      }

      else if (uVar13 == 1) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd13c);

      }

      else {

        iVar17 = (int)uVar13 + -2;

        uVar13 = (u32)iVar17;

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, param_5 + iVar17 * 0x20 + 0x54);

      }

      break;

    case 0x15:

      uVar13 = 0;

      uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd0a8, 0);

      break;

    case 0x17:

      cVar2 = (char)param_4[8];

      if (cVar2 == '\0') {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69eff8, param_4[0xc], param_4[0xd], param_4[0xe]);

      }

      else if (cVar2 == '\x01') {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd020);

      }

      else if (cVar2 == '\x02') {

        if ((char)param_4[10] != '\0') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd09c);

        }

        else {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd038);

        }

      }

      else if (cVar2 == '\x03') {

        if ((char)param_4[10] != '\0') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd09c);

        }

        else {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd038);

        }

      }

      break;

    case 0x18:

      uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd160);

      break;

    case 0x19:

      cVar2 = (char)param_4[8];

      if (cVar2 == '\x03') {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69f018, *(u8 *)((int)param_4 + 0x11), param_4[10], (char)param_4[9]);

      }

      else if (cVar2 == '\x02') {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd0cc, *(u8 *)((int)param_4 + 0x11));

      }

      else if (cVar2 == '\x01') {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd158, *(u8 *)((int)param_4 + 0x11), param_4[9]);

      }

      else if (cVar2 == '\0') {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69f008, *(u8 *)((int)param_4 + 0x11), (char)param_4[9]);

      }

      break;

    case 0x1a:

      if (iVar9 == 0x25) {

        if (((char)param_4[8] == '\x01') || ((char)param_4[8] == '\0')) {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd140);

        }

        else {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd020);

        }

      }

      break;

    case 0x1b:

      if ((char)param_4[9] == '\0') {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd148);

      }

      else if ((char)param_4[9] == '\x01') {

        uVar3 = param_4[10];

        if ((int)((int)(short)uVar3 & 0xffc00U) >> 10 == 0) {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd0d0);

        }

        else {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd150, uVar3 & 0x3ff);

        }

      }

      break;

    case 0x1c:

      if (iVar9 == 0x2c) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69f148, param_4[8], param_4[9]);

      }

      else if (iVar9 == 0x2a) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69f130, param_4[8], param_4[9], param_4[10], param_4[0xb]);

      }

      else if (iVar9 == 0x29) {

        switch((char)param_4[8]) {

        case '\0':

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd02c);

          break;

        case '\x01':

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd020);

          break;

        case '\x02':

          if ((char)param_4[10] != '\0') {

            uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

            evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7ccf80);

          }

          else {

            uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

            evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd178);

          }

          ppuVar11 = &PTR_DAT_0069eed0;

          puVar10 = auStack_d0;

          iVar17 = 4;

          do {

            puVar16 = *ppuVar11;

            puVar4 = ppuVar11[1];

            ppuVar11 = ppuVar11 + 2;

            iVar17 = iVar17 + -1;

            *puVar10 = (u32)puVar16;

            puVar10[1] = (u32)puVar4;

            puVar10 = puVar10 + 2;

          } while (0 < iVar17);

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText((param_1 + 2) * 0xc, param_2, uVar18, uVar12, s_evtMenuTextFormat_007ccd58, auStack_d0[*(char *)((int)param_4 + 0x15)]);

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText((param_1 + 6) * 0xc, param_2, uVar18, uVar12, (const char *)0x69f0c8, (char)param_4[0xc], *(u8 *)((int)param_4 + 0x19), (char)param_4[0xd], *(u8 *)((int)param_4 + 0x1b));

          break;

        case '\x03':

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd02c);

          break;

        case '\x04':

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd02c);

          break;

        case '\x05':

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd02c);

          break;

        case '\x06':

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69f0d8, param_4[10]);

          break;

        case '\a':

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd02c, param_4[10], param_4[0xb], param_4[0xc], param_4[0xd]);

          break;

        case '\b':

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd020);

          break;

        case '\t':

          cVar2 = (char)param_4[10];

          if (cVar2 == '\x03') {

            uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

            evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69f118, param_4[0xb] & 0x3ff);

          }

          else if (cVar2 == '\x02') {

            uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

            evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69f108, param_4[0xb] & 0x3ff);

          }

          else if (cVar2 == '\x01') {

            uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

            evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69f0f8, param_4[0xb] & 0x3ff);

          }

          else if (cVar2 == '\0') {

            uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

            evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69f0e8, param_4[0xb] & 0x3ff, (char)param_4[0xc]);

          }

          break;

        case '\n':

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd020);

          break;

        case '\v':

        case '\f':

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd020);

        }

      }

      else if (iVar9 == 0x2e) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69f0b8, param_4[8], param_4[9]);

      }

      else if (iVar9 == 0x2f) {

        if ((char)param_4[8] == '\x01') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd170, (char)param_4[10]);

          if (*(char *)((int)param_4 + 0x15) != '\0') {

            uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

            evtMenuDrawText((param_1 + 5) * 0xc, param_2, uVar18, uVar12, (const char *)0x7ccf5c);

          }

          else {

            uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

            evtMenuDrawText((param_1 + 5) * 0xc, param_2, uVar18, uVar12, (const char *)0x7ccf58);

          }

        }

        else if ((char)param_4[8] == '\0') {

          if ((char)param_4[10] != '\0') {

            uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

            evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd038);

          }

          else {

            uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

            evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd09c);

          }

        }

      }

      else if (iVar9 == 0x31) {

        if ((char)param_4[10] != '\0') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd038);

        }

        else {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd09c);

        }

      }

      else if (iVar9 == 0x32) {

        if ((char)param_4[8] == '\x01') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd16c);

        }

        else if ((char)param_4[8] == '\0') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd168);

        }

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText((param_1 + 2) * 0xc, param_2, uVar18, uVar12, (const char *)0x69f0a8, *(u8 *)((int)param_4 + 0x11), (char)param_4[9], *(u8 *)((int)param_4 + 0x13));

      }

      else if (iVar9 == 0x27) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69f098, param_4[10]);

      }

      else if (iVar9 == 5) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, &DAT_007cd02c);

      }

      else if (iVar9 == 0x1c) {

        if ((char)param_4[8] == '\x01') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69f088);

        }

        else if ((char)param_4[8] == '\0') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69f070, param_4[10], param_4[0xb], param_4[0xc], param_4[0xd]);

        }

      }

      else if (iVar9 == 0x21) {

        if ((char)param_4[9] != '\0') {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69f060);

        }

        else {

          uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

          evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd0a8, (char)param_4[0x18]);

        }

      }

      else if (iVar9 == 0x2d) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69f050, param_4[0xc], param_4[0xd], param_4[0xe], param_4[0xf]);

      }

      else if (iVar9 == 0x28) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69f030, (char)param_4[8], *(u8 *)((int)param_4 + 0x11), (char)param_4[9], *(u8 *)((int)param_4 + 0x13));

      }

      break;

    case 0x1d:

      iVar17 = 0;

      uStack_f0 = 0;

      uVar8 = 0;

      if (iVar9 == 0x31) {

        uVar8 = (u32)param_4[9];

        iVar17 = (int)(uVar8 & 0xffc00) >> 10;

        uStack_f0 = uVar8 & 0x3ff;

      }

      else if (iVar9 == 0x2f) {

        uVar8 = (u32)param_4[9];

        iVar17 = (int)(uVar8 & 0xffc00) >> 10;

        uStack_f0 = uVar8 & 0x3ff;

      }

      if (uVar8 != 0) {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x69f158, iVar17, uStack_f0);

      }

      else {

        uVar18 = FUN_0038a220(*(u32 *)(param_5 + 0xe0));

        evtMenuDrawText(param_1 * 0xc, param_2, uVar18, uVar12, (const char *)0x7cd180);

      }

      break;

    default:

      FUN_0019d3f0(0x69e408,0x14fe);

    }

    param_1 = param_1 + DAT_0069e180_char[*(char *)((int)psVar7 + iVar14 + 2)];

    lVar15 = iVar14 + 1;

  }

  return;

}
#pragma pop


// FUN_003797B0


void FUN_003797b0(int param_1,int param_2,int param_3,int param_4)
{
  int count;
  int iVar1;
  u16 *entry;
  int state;
  s32 style;
  f32 depth;

  count = *(int *)(*(int *)(param_4 + 0x164) + 0x68);
  if (param_3 < count + 1) {
    if (param_3 == count) {
      entry = NULL;
    }
    else {
      entry = *(u16 **)(*(int *)(param_4 + 0x164) + 0x6c);
      for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 1) {
        entry = *(u16 **)((u8 *)entry + 0x4c);
      }
    }
    if (param_3 == *(int *)(param_4 + 0x160) + *(int *)(param_4 + 0x15c)) {
      state = *(int *)(param_4 + 0xd4);
      if (state == 5) {
        style = 4;
      }
      else {
        style = 5;
      }
    }
    else {
      style = 0;
    }
    if (entry != NULL) {
      FUN_003760a0(param_1,param_2,style,entry,param_4);
    }
    else {
      if (style == 0) {
        style = 8;
      }
      depth = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, depth, style, (const char *)DAT_0069f170);
    }
  }
}


// FUN_003798F0 NONMATCHING


u32 FUN_003798f0(int param_1,int param_2,int param_3)



{

  int *piVar1;

  u32 uVar2;

  u32 uVar3;
  u32 extraout_a2;

  int lVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int iVar9;

  

  iVar7 = (int)param_3;

  if (*(int *)(iVar7 + 0x80) == 0) {

    uVar2 = 0;

  }

  else {

    piVar1 = *(int **)(iVar7 + 0x164);

    if (*(short *)(DAT_0069e1a0 + *piVar1 * 0xc) == 0) {

      uVar2 = 0xffffffff;

    }

    else {

      FUN_0036f900(param_1,param_2,0x28,0x12,*(u32 *)(iVar7 + 0x160),piVar1[0x1a] + 1,param_3

                   ,0x375f30,0);

      if (*(int *)(iVar7 + 0xd4) != 5) {

        uVar2 = 0;

      }

      else {

        iVar8 = piVar1[0x1a] + 1;

        iVar9 = 0x11;

        if (iVar8 < 0x11) {

          iVar9 = iVar8;

        }

        if (*(short *)(&DAT_0069e420 + *piVar1 * 0xc) != 0) {

          if ((DAT_007e094e & 0x1000) == 0) {

            if ((DAT_007e094e & 0x4000) != 0) {

              iVar6 = 0;

              for (iVar5 = piVar1[0x1b]; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0x4c)) {

                iVar6 = iVar6 + 1;

              }

              if (iVar6 == *(int *)(iVar7 + 0x160) + *(int *)(iVar7 + 0x15c)) {

                return 0xfffffffc;

              }

            }

          }

          else if (*(int *)(iVar7 + 0x160) + *(int *)(iVar7 + 0x15c) == 0) {

            return 0xfffffffc;

          }

        }

        FUN_0036f680(iVar7 + 0x160,iVar7 + 0x15c,iVar8,iVar9,0,0x4000,0x1000);
        uVar3 = extraout_a2;

        FUN_0036f680(0,iVar7 + 0x158,uVar3,uVar3,0,0x2000,0x8000);

        if ((DAT_007e094e & 0x40) != 0) {

          uVar2 = 1;

        }

        else {

          if ((DAT_007e094e & 0x20) != 0) {

            uVar2 = 0xffffffff;

          }

          else {

            uVar2 = 0;

          }

        }

        if ((DAT_007e094c & 0x10) != 0) {

          if ((DAT_007e094e & 0x100) != 0) {

            FUN_005225a8(0x69f188);

            FUN_00389b50(piVar1);

          }

          if ((DAT_007e094e & 0x800) != 0) {

            FUN_005225a8(0x69f198);

            FUN_00389d80(param_3,(int)piVar1);

          }

        }

        else {

          if ((DAT_007e094e & 0x80) != 0) {

            uVar2 = 0xfffffffe;

          }

          if ((DAT_007e094e & 0x100) == 0) {

            if (((DAT_007e094e & 0x800) != 0) && (lVar4 = FUN_00361830(param_3), lVar4 != 0)) {

              FUN_0038a180(*piVar1,lVar4);

              FUN_005225a8(&gp0xffffa4a0);

            }

          }

          else {

            lVar4 = FUN_00361830(param_3);

            if (lVar4 != 0) {

              FUN_0038a140(*piVar1,(u32 *)lVar4);

              FUN_005225a8(&gp0xffffa498);

            }

          }

        }

      }

    }

  }

  return uVar2;

}


/* opt_loop_invariants on: default nd380/756B -> nd364/744B; retained. */
#pragma opt_loop_invariants on
/* opt_propagation off: default nd364/744B -> nd346/744B; retained. */
#pragma push
#pragma opt_propagation off
// FUN_00379C30 NONMATCHING


void FUN_00379c30(int param_1,int param_2,int param_3,int param_4)



{

  char acStack_600 [1536];

  f32 uVar11;

  u32 uVar10;

  u32 uVar9;

  int *piVar8;

  char *pcVar7;

  char *pcVar6;

  int iVar5;

  u16 uVar4;

  int sVar3;

  char cVar2;

  char cVar1;

  

  pcVar7 = s_STAGE_0069f1b0;

  pcVar6 = acStack_600;

  iVar5 = 0x2fd;

  do {

    cVar1 = *pcVar7;

    cVar2 = pcVar7[1];

    pcVar7 = pcVar7 + 2;

    iVar5 = iVar5 + -1;

    *pcVar6 = cVar1;

    pcVar6[1] = cVar2;

    pcVar6 = pcVar6 + 2;

  } while (0 < iVar5);

  if ((*(int *)(param_4 + 0x80) != 0) && (param_3 < *(int *)(param_4 + 0x80))) {

    piVar8 = *(int **)(param_4 + 0x84);

    for (iVar5 = 0; iVar5 < param_3; iVar5 = iVar5 + 1) {

      piVar8 = (int *)piVar8[0x25];

    }

    if (param_3 == *(int *)(param_4 + 0x154) + *(int *)(param_4 + 0x150)) {

      uVar9 = 4;

      if (*(int *)(param_4 + 0xd4) == 4) {

        *(u32 *)(param_4 + 0x158) = 0;

        *(u32 *)(param_4 + 0x15c) = 0;

        *(u32 *)(param_4 + 0x160) = 0;

        *(int **)(param_4 + 0x164) = piVar8;

      }

      else {

        uVar9 = 5;

      }

      sVar3 = *(short *)(param_4 + 0x22);

      iVar5 = piVar8[2];

      if (-1 < iVar5) {

        uVar11 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));

        evtMenuDrawText((param_1 + 0xe) * 0xc, (sVar3 + 2) * 0xc, uVar11, 0, (const char *)(void *)(param_4 + iVar5 * 0x20 + 0x54))

        ;

      }

    }

    else {

      uVar9 = 0;

    }

    if ((((int)(*(u16 *)(piVar8 + 3) & 0xffc00) >> 10 == 3) &&

        (uVar10 = *(u16 *)(piVar8 + 3) & 0x3ff, 899 < uVar10)) && (uVar10 < 0x387)) {

      uVar11 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar11, uVar9, (const char *)(void *)0x69f7b0, uVar10 - 900);

    }

    else {

      param_2 = param_2 * 0xc;

      uVar11 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));

      evtMenuDrawText(param_1 * 0xc, param_2, uVar11, uVar9, (const char *)acStack_600 + *piVar8 * 0x1e);

      uVar4 = *(u16 *)(piVar8 + 3);

      iVar5 = (int)(uVar4 & 0xfc00) >> 10;

      if (iVar5 == 1) {

        uVar11 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));

        evtMenuDrawText((param_1 + 4) * 0xc, param_2, uVar11, uVar9, (const char *)&gp0xffffa4a8, uVar4 & 0x3ff);

      }

      else if (iVar5 == 3) {

        uVar11 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));

        evtMenuDrawText((param_1 + 4) * 0xc, param_2, uVar11, uVar9, (const char *)&gp0xffffa460, uVar4 & 0x3ff);

      }

    }

  }

  return;

}
#pragma pop
#pragma opt_loop_invariants reset


// FUN_00379F30 NONMATCHING


u64 FUN_00379f30(int param_1,int param_2,int param_3)



{

  int *piVar1;

  int iVar2;

  int lVar3;

  u64 uVar4;

  u64 extraout_a2;

  int iVar5;

  int iVar6;

  

  iVar6 = (int)param_3;

  FUN_0036f900(param_1,param_2,9,0xf,*(u32 *)(iVar6 + 0x154),*(u32 *)(iVar6 + 0x80),

               param_3,0,0);

  piVar1 = *(int **)(iVar6 + 0x164);

  if (piVar1 != (int *)0x0) {

    iVar2 = *piVar1;

    if (iVar2 == 1) {

      lVar3 = FUN_003b5d10((short)piVar1[3]);

      if (lVar3 != 0) {

        FUN_00396270(0x42480000,param_3,(int)lVar3 + 4);

      }

    }

    else if ((iVar2 == 10) && (*(char *)((int)piVar1 + 0x22) == '\x03')) {

      lVar3 = FUN_003b5d10((short)piVar1[9]);

      if (lVar3 != 0) {

        FUN_00396270(0x42480000,param_3,(int)lVar3 + 4);

      }

    }

    else if ((iVar2 == 0x30) && (lVar3 = FUN_003b5d10((short)piVar1[3]), lVar3 != 0)) {

      FUN_00396270(0x42480000,param_3,(int)lVar3 + 4);

    }

    *(int **)(iVar6 + 0x780) = piVar1;

  }

  if (*(int *)(iVar6 + 0xd4) == 4) {

    iVar2 = *(int *)(iVar6 + 0x80);

    if (iVar2 == 0) {

      uVar4 = 0;

    }

    else {

      iVar5 = 0xf;

      if (iVar2 < 0xf) {

        iVar5 = iVar2;

      }

      FUN_0036f680(iVar6 + 0x154,iVar6 + 0x150,iVar2,iVar5,0,0x4000,0x1000);

      FUN_0036f680(0,0,1,1,0,0x2000,0x8000);

      uVar4 = extraout_a2;

      if ((DAT_007e094e & 0x40) == 0) {

        if ((DAT_007e094e & 0x20) == 0) {

          uVar4 = 0;

        }

        else {

          uVar4 = 0xffffffffffffffff;

        }

      }

      FUN_003625e0(param_3);

    }

  }

  else {

    uVar4 = 0;

  }

  return uVar4;

}


// FUN_0037A150


u32 FUN_0037a150(int param_1,int param_2,u8 *param_3)



{

  f32 uVar1;

  u8 auStack_10 [16];
  FUN_00523ac8_evt4(auStack_10,(const char *)&gp0xffffa4b0,(void *)(param_3 + 0x130),(void *)(param_3 + 0x13c));

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)auStack_10);

  return 2;

}


// FUN_0037A1E0


void FUN_0037a1e0(int param_1,int param_2,int param_3,int param_4)



{

  int iVar1;
  int iVar2;
  u8 *puVar1;
  f32 uVar2;


  param_1 = param_1 + 0xc;
  iVar1 = 0;
  puVar1 = (u8 *)s_1234567890A_0069f7c0_abs + param_3 * 0xc;
  iVar2 = param_2 * 0xc;

  for (; iVar1 < 0xb;) {
    uVar2 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, iVar2, uVar2, 0, (const char *)*(s8 *)(puVar1 + iVar1));

    iVar1 = iVar1 + 1;
    param_1 = param_1 + 0xc0;
  }

  return;

}


/* opt_lifetimes on: default nd371/524B -> nd370/524B; retained. */
#pragma push
#pragma opt_lifetimes on
// FUN_0037A2B0 NONMATCHING


u32 FUN_0037a2b0(int param_1,int param_2,int param_3)



{

  char cVar1;

  u32 uVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  

  FUN_0036f900(param_1,param_2,0xe,6,0,4,param_3,0x37a150,0);

  iVar5 = (int)param_3;

  if (*(int *)(iVar5 + 0xd4) != 3) {

    uVar2 = 0;

  }

  else {

    FUN_0036f680(0,iVar5 + 300,4,4,0,0x4000,0x1000);

    FUN_0036f680(0,iVar5 + 0x128,0xb,0xb,0,0x2000,0x8000);

    if ((DAT_007e094e & 0x40) != 0) {

      iVar3 = 1;

    }

    else {

      if ((DAT_007e094e & 0x20) == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = -1;

      }

    }

    if (iVar3 < 0) {

      uVar2 = 0xffffffff;

    }

    else {

      if (iVar3 == 1) {

        cVar1 = s_1234567890A_0069f7c0[*(int *)(iVar5 + 0x128) + *(int *)(iVar5 + 300) * 0xc];

        if ((*(int *)(iVar5 + 300) == 3) && (3 < *(int *)(iVar5 + 0x128))) {

          if ((cVar1 == 'K') || (cVar1 == 'O')) {

            if (*(char *)(iVar5 + 0x130) != '\0') {

              return 1;

            }

          }

          else if ((cVar1 == 'S') || (cVar1 == 'B')) {

            for (iVar3 = 0; *(char *)(iVar5 + iVar3 + 0x130) != '\0'; iVar3 = iVar3 + 1) {

            }

            if (0 < iVar3) {

              *(u8 *)(iVar5 + iVar3 + 0x12f) = 0;

            }

          }

        }

        else {

          iVar3 = 0;

          while( true ) {

            iVar4 = iVar5 + iVar3;

            if (*(char *)(iVar4 + 0x130) == '\0') break;

            iVar3 = iVar3 + 1;

          }

          if (iVar3 < 8) {

            *(char *)(iVar4 + 0x130) = cVar1;

            *(u8 *)(iVar4 + 0x131) = 0;

          }

        }

      }

      uVar2 = 0;

    }

  }

  return uVar2;

}
#pragma pop


// FUN_0037A4D0


u32 FUN_0037a4d0(int param_1,int param_2,int param_3)



{

  int iVar1;

  u32 uVar2;

  f32 fVar3;

  

  iVar1 = *(int *)(param_3 + 0x120);

  if (iVar1 == 0) {

    uVar2 = 0;

  }

  else {

    fVar3 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, fVar3, 0, (const char *)(void *)iVar1);

    uVar2 = 2;

  }

  return uVar2;

}


// FUN_0037A560


void FUN_0037a560(int param_1,int param_2,int param_3,int param_4)



{

  u32 uVar1;

  f32 uVar2;

  

  if (param_3 < *(int *)(param_4 + 0x11c)) {

    if (*(int *)(param_4 + 0x118) == param_3) {

      if (*(int *)(param_4 + 0xd4) == 2) {

        uVar1 = 4;

      }

      else {

        uVar1 = 5;

      }

    }

    else {

      uVar1 = 0;

    }

    uVar2 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar2, (int)uVar1, (const char *)(void *)*(u32 *)(*(int *)(param_4 + 0x124) + param_3 * 4));

  }

  return;

}


// FUN_0037A640 NONMATCHING


u32 FUN_0037a640(int param_1,int param_2,int param_3)
{
  int rowCount;
  u16 buttons;
  if (*(int *)(param_3 + 0x120) == 0) {
    rowCount = 10;
  }
  else {
    rowCount = FUN_00524388(*(int *)(param_3 + 0x120));
    if (rowCount < 6) {
      rowCount = 6;
    }
  }
  FUN_0036f900_evt(param_1,param_2,rowCount,*(int *)(param_3 + 0x11c) + 3,0,
               *(int *)(param_3 + 0x11c),param_3,(code *)FUN_0037a4d0,
               (code *)FUN_0037a560);
  if (*(int *)(param_3 + 0xd4) != 2) {
    return 0;
  }
  FUN_0036f680_ptr2(0,(u32 *)((u8 *)(uintptr_t)param_3 + 0x118),
               *(u32 *)(param_3 + 0x11c),
               *(u32 *)(param_3 + 0x11c),0,0x4000,0x1000);
  FUN_0036f680(0,0,1,1,0,0x2000,0x8000);
  buttons = *(u16 *)DAT_007e094e_abs;
  if ((buttons & 0x40) != 0) {
    return 1;
  }
  if ((buttons & 0x20) != 0) {
    return -1;
  }
  return 0;
}


// FUN_0037A790


void FUN_0037a790(int param_1,int param_2,int param_3,int param_4)



{

  char cVar1;

  u8 *puVar2;

  int lVar3;

  u32 uVar4;

  u8 **ppuVar7;

  u32 *puVar6;

  int iVar5;

  u32 uVar8;
  int y;

  f32 uVar9;

  u32 auStack_60 [17];

  RwV2d auStack_10;

  u8 auStack_4 [4];

  

  ppuVar7 = PTR_s_SAVE_PROJ_abs;

  puVar6 = auStack_60;

  iVar5 = 0x11;

  do {

    puVar2 = *ppuVar7;

    ppuVar7 = ppuVar7 + 1;

    iVar5 = iVar5 + -1;

    *puVar6 = (u32)puVar2;

    puVar6 = puVar6 + 1;

  } while (0 < iVar5);

  auStack_10 = *(RwV2d *)&uGpffffa4b8;

  if (param_3 < 0x11) {

    iVar5 = (int)param_4;

    if (*(int *)(iVar5 + 0x104) == param_3) {

      if (*(int *)(iVar5 + 0xd4) == 1) {

        uVar8 = 4;

      }

      else {

        uVar8 = 5;

      }

    }

    else {

      uVar8 = 0;

    }

    y = param_2 * 0xc;

    uVar9 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, y, uVar9, uVar8, (const char *)(void *)auStack_60[param_3]);

    if (param_3 == 7) {

      uVar9 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));

      evtMenuDrawText((param_1 + 9) * 0xc, y, uVar9, uVar8, (const char *)DAT_0069f948_abs, *(u32 *)(iVar5 + 0x3c), *(u32 *)(iVar5 + 0x40), *(u8 *)(iVar5 + 0x46), *(s16 *)(iVar5 + 0x48));

    }

    else if (param_3 == 10) {

      cVar1 = *(char *)(iVar5 + 0x45);

      if (cVar1 == '\0') {

        uVar9 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));

        evtMenuDrawText((param_1 + 10) * 0xc, y, uVar9, uVar8, (const char *)DAT_0069f958_abs);

      }

      else {

        uVar9 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));

        evtMenuDrawText((param_1 + 10) * 0xc, y, uVar9, uVar8, (const char *)&gp0xffffa4c0, cVar1);

      }

    }

    else if (param_3 == 9) {

      uVar9 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));

      evtMenuDrawText((param_1 + 10) * 0xc, y, uVar9, uVar8, (const char *)&gp0xffffa4c8, ((u32 *)&auStack_10)[*(char *)(iVar5 + 0x44)]);

    }

    else if (param_3 == 0xb) {

      lVar3 = FUN_00397520(param_4,auStack_4);

      if (lVar3 == 0) {

        uVar9 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));

        evtMenuDrawText((param_1 + 10) * 0xc, y, uVar9, uVar8, (const char *)DAT_0069f968_abs);

      }

      else {

        uVar9 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));

        uVar4 = FUN_00397500(param_4);

        evtMenuDrawText((param_1 + 10) * 0xc, y, uVar9, uVar8, (const char *)DAT_0069f978_abs, (void *)uVar4);

      }

    }

    else if (param_3 == 0xe) {

      if ((*(s8 *)(iVar5 + 0x4c) & 1) != 0) {

        uVar9 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));

        evtMenuDrawText((param_1 + 0xb) * 0xc, y, uVar9, uVar8, (const char *)&gp0xffffa4d8);

      }

      else {

        uVar9 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));

        evtMenuDrawText((param_1 + 0xb) * 0xc, y, uVar9, uVar8, (const char *)&gp0xffffa4d0);

      }

    }

    else if (param_3 == 0x10) {

      if ((*(s8 *)(iVar5 + 0x4c) & 4) != 0) {

        uVar9 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));

        evtMenuDrawText((param_1 + 0xc) * 0xc, y, uVar9, uVar8, (const char *)&gp0xffffa4d8);

      }

      else {

        uVar9 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));

        evtMenuDrawText((param_1 + 0xc) * 0xc, y, uVar9, uVar8, (const char *)&gp0xffffa4d0);

      }

    }

  }

  return;

}


// FUN_0037ABD0 NONMATCHING


u32 FUN_0037abd0(int param_1,int param_2,int param_3)
{
  FUN_0036f900(param_1,param_2,0x16,0x11,0,0x11,param_3,0,(code *)FUN_0037a790);

  if (*(int *)((int)param_3 + 0xd4) != 1) {
    return 0;
  }
  else {
    u32 result = FUN_0036f680_ret_ptr2(0,(u32 *)((u8 *)(uintptr_t)param_3 + 0x104),
                                       0x11,0x11,0,0x4000,0x1000);
    FUN_0036f680(0,0,result,result,0,0x2000,0x8000);

    if ((*(u16 *)DAT_007e094e_abs & 0x40) != 0) {
      return 1;
    }
    if ((*(u16 *)DAT_007e094e_abs & 0x20) != 0) {
      return -1;
    }
    return 0;
  }
}


// FUN_0037ACC0


u32 FUN_0037acc0(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069f990);

  return 2;

}


// FUN_0037AD30 NONMATCHING


void FUN_0037ad30(int param_1,int param_2,int param_3,int param_4)
{
  u32 sVar1;
  u32 uVar2;
  f32 uVar3;
  u8 auStack_50 [64];
  u8 *apuStack_10 [3];
  u32 uStack_4;

  uVar2 = 0;
  apuStack_10[0] = PTR_s_DIRECT_0069f9a0;
  apuStack_10[1] = PTR_DAT_0069f9a4;
  apuStack_10[2] = PTR_DAT_0069f9a8;
  uStack_4 = *(u32 *)(param_4 + 0x16c);
  if (*(int *)(param_4 + 0x220) == param_3) {
    uVar2 = 4;
  }
  if (param_3 == 2) {
    param_2 = param_2 * 0xc;
    uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2, uVar3, 0, (const char *)&gp0xffffa4f8);
    sVar1 = ((u16 *)&uStack_4)[1];
    if (((u16 *)&uStack_4)[1] != 0) {
      uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0xc) * 0xc, param_2, uVar3, uVar2, (const char *)&gp0xffffa070, sVar1);
    }
    else {
      uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0xc) * 0xc, param_2, uVar3, uVar2, (const char *)&gp0xffffa500);
    }
  }
  else if (param_3 == 1) {
    uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar3, 0, (const char *)&gp0xffffa4e8);
    FUN_00523ac8(auStack_50,&gp0xffffa4f0,(((u8 *)&uStack_4)[1]) + 1);
    uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0xc) * 0xc, param_2 * 0xc, uVar3, uVar2, (const char *)&gp0xffffa068, (u32)auStack_50);
  }
  else if (param_3 == 0) {
    uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar3, 0, (const char *)(void *)0x69f9b0);
    uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0xc) * 0xc, param_2 * 0xc, uVar3, uVar2, (const char *)&gp0xffffa068, (u32)apuStack_10[(char)uStack_4]);
  }
  return;
}


// FUN_0037AFC0 NONMATCHING


u32 FUN_0037afc0(int param_1,int param_2,int param_3)



{

  int iVar2;

  u32 uVar4;

  int iVar5;

  u32 uStack_4;

  

  FUN_0036f900(param_1,param_2,0x14,6,0,1,param_3,0x37acc0,0);

  iVar5 = (int)param_3;

  if (*(int *)(iVar5 + 0xd4) != 0x17) {

    uVar4 = 0;

  }

  else {

    if ((DAT_007e0952 & 0x1000) == 0) {

      if ((DAT_007e0952 & 0x4000) != 0) {

        if (*(int *)(iVar5 + 0x220) != 3) {

          *(int *)(iVar5 + 0x220) = *(int *)(iVar5 + 0x220) + 1;

        }

        else {

          *(u32 *)(iVar5 + 0x220) = 0;

        }

      }

    }

    else if (*(int *)(iVar5 + 0x220) == 0) {

      *(u32 *)(iVar5 + 0x220) = 2;

    }

    else {

      *(int *)(iVar5 + 0x220) = *(int *)(iVar5 + 0x220) + -1;

    }

    uStack_4 = *(u32 *)(iVar5 + 0x16c);

    FUN_003625e0_i(param_3);

    iVar2 = *(int *)(iVar5 + 0x220);
    ((u16 *)&uStack_4)[1] = (u16)(uStack_4 >> 0x10);


    if (iVar2 == 2) {
      u16 *puVar3;

      puVar3 = (u16 *)FUN_003b5d10(((u16 *)&uStack_4)[1]);

      if ((DAT_007e0952 & 0x2000) == 0) {

        if ((DAT_007e0952 & 0x8000) != 0) {

          if (puVar3 != (u16 *)0x0) {

            puVar3 = *(u16 **)(puVar3 + 0x7e);

          }

          else {

            puVar3 = (u16 *)FUN_003b5da0(8);

          }

        }

      }

      else if (puVar3 == (u16 *)0x0) {

        puVar3 = (u16 *)FUN_003b5d50(8);

      }

      else {

        puVar3 = *(u16 **)(puVar3 + 0x7c);

      }


      if (puVar3 == (u16 *)0x0) {

        uStack_4 = uStack_4 & 0xffff;

      }

      else {

        ((u16 *)&uStack_4)[1] = *puVar3;

        FUN_00396270_f32(20.0f,param_3,(f32 *)(puVar3 + 2));


      }

    }

    else {


      if (iVar2 == 1) {


        if ((DAT_007e0952 & 0x2000) == 0) {

          if ((DAT_007e0952 & 0x8000) != 0) {

            if (((s8 *)&uStack_4)[1] >= 1) {
              ((s8 *)&uStack_4)[1]--;


            }

            else {

              ((s8 *)&uStack_4)[1] = 99;


            }

          }

        }

        else if (((s8 *)&uStack_4)[1] + 1 < 100) {
          ((s8 *)&uStack_4)[1]++;


        }

        else {

          ((s8 *)&uStack_4)[1] = 0;


        }

      }

      else if (iVar2 == 0) {


        if ((DAT_007e0952 & 0x2000) == 0) {

          if ((DAT_007e0952 & 0x8000) != 0) {

            if (((s8 *)&uStack_4)[0] >= 1) {
              ((s8 *)&uStack_4)[0]--;


            }

            else {

              ((s8 *)&uStack_4)[0] = 2;


            }

          }

        }

        else if (((s8 *)&uStack_4)[0] + 1 < 3) {
          ((s8 *)&uStack_4)[0]++;


        }

        else {

          ((s8 *)&uStack_4)[0] = 0;


        }

      }

    }


    *(u32 *)(iVar5 + 0x16c) = uStack_4;

    if ((DAT_007e094e & 0x40) != 0) {

      FUN_0038a620(param_3,1);

      uVar4 = 1;

    }

    else {

      if ((DAT_007e094e & 0x20) == 0) {

        uVar4 = 0;

      }

      else {

        FUN_0038a620(param_3,1);

        uVar4 = 0xffffffff;

      }

    }

  }

  return uVar4;

}


// FUN_0037B2E0


u32 FUN_0037b2e0(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069f9c0);

  return 2;

}


// FUN_0037B350 NONMATCHING


void FUN_0037b350(int param_1,int param_2,int param_3,int param_4)
{
  u32 uStack_4;
  u8 *apuStack_10 [3];
  f32 uVar3;
  u32 uVar2;
  u32 sVar1;

  uVar2 = 0;
  apuStack_10[0] = PTR_DAT_0069f9d8;
  apuStack_10[1] = PTR_s_ACTIVE_0069f9dc;
  apuStack_10[2] = PTR_DAT_0069f9e0;
  uStack_4 = *(u32 *)(param_4 + 0x19c);
  if (*(int *)(param_4 + 0x228) == param_3) {
    uVar2 = 4;
  }

  switch (param_3) {
  case 0:
    uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar3, 0, (const char *)(void *)0x69f9e8);
    uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0xc) * 0xc, param_2 * 0xc, uVar3, uVar2, (const char *)&gp0xffffa068, (u32)apuStack_10[(char)uStack_4]);
    break;
  case 1:
    param_2 = param_2 * 0xc;
    uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2, uVar3, 0, (const char *)&gp0xffffa4f8);
    sVar1 = ((u16 *)&uStack_4)[1];
    if (((u16 *)&uStack_4)[1] == 0) {
      uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0xc) * 0xc, param_2, uVar3, uVar2, (const char *)&gp0xffffa500);
    }
    else {
      uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0xc) * 0xc, param_2, uVar3, uVar2, (const char *)&gp0xffffa070, sVar1);
    }
    break;
  case 2:
    uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar3, 0, (const char *)(void *)0x69f9f8);
    uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0xc) * 0xc, param_2 * 0xc, uVar3, uVar2, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1a0));
    break;
  }
}


// FUN_0037B5D0 NONMATCHING


u32 FUN_0037b5d0(int param_1,int param_2,int param_3)



{

  u16 *puVar2;

  u32 uVar3;

  int lVar4;

  u32 uVar5;

  int iVar6;

  int iVar7;

  union {
    u32 raw;
    struct {
      s8 type;
      u8 pad;
      u16 id;
    } fields;
  } selection;

  

  lVar4 = FUN_003b5d00();

  if (lVar4 == 0) {

    uVar3 = 0xffffffff;

  }

  else {

    FUN_0036f900(param_1,param_2,0x14,7,0,1,param_3,0x37b2e0,0);

    iVar7 = (int)param_3;

    if (*(int *)(iVar7 + 0xd4) != 0x18) {

      uVar3 = 0;

    }

    else {

      if ((DAT_007e0952 & 0x1000) == 0) {

        if ((DAT_007e0952 & 0x4000) != 0) {

          if (*(int *)(iVar7 + 0x228) != 2) {

            *(int *)(iVar7 + 0x228) = *(int *)(iVar7 + 0x228) + 1;

          }

          else {

            *(u32 *)(iVar7 + 0x228) = 0;

          }

        }

      }

      else if (*(int *)(iVar7 + 0x228) == 0) {

        *(u32 *)(iVar7 + 0x228) = 2;

      }

      else {

        *(int *)(iVar7 + 0x228) = *(int *)(iVar7 + 0x228) + -1;

      }

      selection.raw = *(u32 *)(iVar7 + 0x19c);

      FUN_003625e0(param_3);

      iVar6 = *(int *)(iVar7 + 0x228);

      if (iVar6 == 2) {

        uVar5 = 0;

        if ((DAT_007e0952 & 0x2000) != 0) {

          uVar5 = 1;

        }

        else {

          if ((DAT_007e0952 & 0x8000) != 0) {

            uVar5 = 0xffffffffffffffff;

          }

          else {

            if ((DAT_007e0952 & 8) != 0) {

              uVar5 = 10;

            }

            else {

              if ((DAT_007e0952 & 4) != 0) {

                uVar5 = 0xfffffffffffffff6;

              }

            }

          }

        }

        uVar3 = FUN_0038a480(*(u32 *)(iVar7 + 0x1a0),uVar5,0,2000);

        *(u32 *)(iVar7 + 0x1a0) = uVar3;

      }

      else {

        selection.fields.type = (s8)selection.raw;

        if (iVar6 == 1) {

          iVar6 = 0;

          selection.fields.id = (u16)(selection.raw >> 0x10);
          puVar2 = (u16 *)FUN_003b5d10(selection.fields.id);

          if (selection.fields.type != 2) {
            if (selection.fields.type == 1) {

              if (puVar2 != (u16 *)0x0) {

                iVar6 = (int)(*puVar2 & 0xffc00) >> 10;

              }

              else {

                iVar6 = 3;

              }

            }

            else if (selection.fields.type == 0) {

              iVar6 = 8;

            }

          }

          if ((DAT_007e0952 & 0x2000) == 0) {

            if ((DAT_007e0952 & 0x8000) != 0) {

              if (puVar2 != (u16 *)0x0) {

                puVar2 = *(u16 **)(puVar2 + 0x7e);

                if ((puVar2 == (u16 *)0x0) && (iVar6 == 1)) {

                  puVar2 = (u16 *)FUN_003b5da0(3);

                }

              }

              else {

                if (iVar6 != 3) {

                  puVar2 = (u16 *)FUN_003b5da0(iVar6);

                }

                else {

                  puVar2 = (u16 *)FUN_003b5da0(1);

                  if (puVar2 == (u16 *)0x0) {

                    puVar2 = (u16 *)FUN_003b5da0(3);

                  }

                }

              }

            }

          }

          else if (puVar2 == (u16 *)0x0) {

            puVar2 = (u16 *)FUN_003b5d50(iVar6);

            if ((iVar6 == 3) && (puVar2 == (u16 *)0x0)) {

              puVar2 = (u16 *)FUN_003b5d50(1);

            }

          }

          else {

            puVar2 = *(u16 **)(puVar2 + 0x7c);

            if ((puVar2 == (u16 *)0x0) && (iVar6 == 3)) {

              puVar2 = (u16 *)FUN_003b5d50(1);

              FUN_005225a8(0x69fa10);

            }

          }


          if (puVar2 == (u16 *)0x0) {

            selection.raw &= 0xffff;

          }

          else {

            selection.fields.id = *puVar2;

            FUN_00396270(0x41a00000,param_3,puVar2 + 2);


          }

        }

        else if (iVar6 == 0) {

          selection.raw = (selection.raw & 0xff) | ((selection.raw >> 8) << 8);

          if ((DAT_007e0952 & 0x2000) != 0) {

            if (selection.fields.type + 1 >= 3) {
              selection.raw = (u16)((short)(selection.raw >> 8) << 8);

            }

            else {

              selection.fields.type++;

            }

            selection.raw = (u32)(u16)selection.raw;

          }

          else {

            if ((DAT_007e0952 & 0x8000) != 0) {

              if (selection.fields.type >= 1) {
                selection.fields.type--;

              }

              else {

                selection.fields.type = 2;

              }

              selection.raw = (u32)(u16)selection.raw;

            }

          }

        }

      }

      *(u32 *)(iVar7 + 0x19c) = selection.raw;

      if ((DAT_007e094e & 0x40) != 0) {

        FUN_0038a620(param_3,1);

        uVar3 = 1;

      }

      else {

        if ((DAT_007e094e & 0x20) == 0) {

          uVar3 = 0;

        }

        else {

          FUN_0038a620(param_3,1);

          uVar3 = 0xffffffff;

        }

      }

    }

  }

  return uVar3;

}


// FUN_0037BA80


u32 FUN_0037ba80(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069fa30);

  return 2;

}


// FUN_0037BAF0


void FUN_0037baf0(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  u32 uVar2;
  int iVar3;
  f32 uVar4;
  int y;

  uVar2 = 0;
  iVar1 = FUN_00361830(param_4);
  iVar3 = (int)param_4;
  if (*(int *)(iVar3 + 400) == param_3) {
    uVar2 = 4;
  }
  switch (param_3) {
  case 0:
    y = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, y, uVar4, 0, (const char *)&gp0xffffa508);
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText((param_1 + 0xc) * 0xc, y, uVar4, uVar2,
                    (const char *)&gp0xffffa3b8, *(u32 *)(iVar3 + 0x198));
    break;
  case 1:
    y = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, y, uVar4, 0, (const char *)&gp0xffffa510);
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText((param_1 + 0xc) * 0xc, y, uVar4, uVar2,
                    (const char *)&gp0xffffa3b8, *(u32 *)(iVar3 + 0x19c));
    break;
  case 2:
    y = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, y, uVar4, 0, (const char *)DAT_0069fa40_abs);
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText((param_1 + 0xc) * 0xc, y, uVar4, uVar2,
                    (const char *)&gp0xffffa3b8, *(u32 *)(iVar3 + 0x16c));
    break;
  case 3:
    y = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, y, uVar4, 0, (const char *)DAT_0069fa50_abs);
    switch (**(int **)(iVar3 + 0x164)) {
    case 1:
    case 0x30:
      if (*(char *)(iVar1 + 0x28) != '\0') {
        uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
        evtMenuDrawText((param_1 + 0xc) * 0xc, y, uVar4, uVar2,
                        (const char *)DAT_0069fa60_abs, *(char *)(iVar1 + 0x29),
                        *(char *)(iVar1 + 0x2a), *(char *)(iVar1 + 0x2b));
      }
      else {
        uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
        evtMenuDrawText((param_1 + 0xc) * 0xc, y, uVar4, uVar2,
                        (const char *)&gp0xffffa0b8);
      }
      break;
    default:
      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
      evtMenuDrawText((param_1 + 0xd) * 0xc, y, uVar4, uVar2,
                      (const char *)&gp0xffffa518);
      break;
    }
    break;
  }
}


// FUN_0037BE50 NONMATCHING


u32 FUN_0037be50(int param_1,int param_2,int param_3)



{

  u16 *puVar1;

  int iVar2;

  u32 uVar3;

  u32 lVar4;

  int iVar5;

  u64 uVar6;

  u32 uVar7;

  u8 auStack_60 [64];

  float afStack_20[3];

  u32 auStack_10[3];

  

  uVar6 = 0;

  iVar5 = (int)param_3;

  puVar1 = *(u16 **)(iVar5 + 0x238);

  lVar4 = FUN_003b5d00();

  if (lVar4 == 0) {

    uVar3 = 0xffffffff;

  }

  else {

    FUN_0036f900(param_1,param_2,0x1b,6,0,1,param_3,0x37ba80,0);

    if (*(int *)(iVar5 + 0xd4) != 0x19) {

      uVar3 = 0;

    }

    else {

      if ((DAT_007e0952 & 0x1000) == 0) {

        if ((DAT_007e0952 & 0x4000) != 0) {

          if (*(int *)(iVar5 + 400) == 3) {

            *(u32 *)(iVar5 + 400) = 0;

          }

          else {

            *(int *)(iVar5 + 400) = *(int *)(iVar5 + 400) + 1;

          }

        }

      }

      else if (*(int *)(iVar5 + 400) == 0) {

        *(u32 *)(iVar5 + 400) = 3;

      }

      else {

        *(int *)(iVar5 + 400) = *(int *)(iVar5 + 400) + -1;

      }

      FUN_003625e0(param_3);

      iVar2 = *(int *)(iVar5 + 400);

      switch (iVar2) {
      case 0:
        if ((DAT_007e0952 & 0x2000) != 0) {
          *(int *)(iVar5 + 0x198) = *(int *)(iVar5 + 0x198) + 5;
        }
        else {
          if ((DAT_007e0952 & 8) != 0) {
            *(int *)(iVar5 + 0x198) = *(int *)(iVar5 + 0x198) + 10;
          }
          else {
            if ((DAT_007e0952 & 0x8000) != 0) {
              *(int *)(iVar5 + 0x198) = *(int *)(iVar5 + 0x198) + -5;
            }
            else {
              if ((DAT_007e0952 & 4) != 0) {
                *(int *)(iVar5 + 0x198) = *(int *)(iVar5 + 0x198) + -10;
              }
            }
          }
        }
        FUN_003bb9b0(puVar1 + 8);
        break;

      case 1:
        if ((DAT_007e0952 & 0x2000) != 0) {
          *(int *)(iVar5 + 0x19c) = *(int *)(iVar5 + 0x19c) + 5;
        }
        else {
          if ((DAT_007e0952 & 8) != 0) {
            *(int *)(iVar5 + 0x19c) = *(int *)(iVar5 + 0x19c) + 10;
          }
          else {
            if ((DAT_007e0952 & 0x8000) != 0) {
              *(int *)(iVar5 + 0x19c) = *(int *)(iVar5 + 0x19c) + -5;
            }
            else {
              if ((DAT_007e0952 & 4) != 0) {
                *(int *)(iVar5 + 0x19c) = *(int *)(iVar5 + 0x19c) + -10;
              }
            }
          }
        }
        FUN_003bb9b0(puVar1 + 8);
        break;

      case 2:
        if ((DAT_007e0952 & 0x2000) != 0) {
          uVar6 = 1;
        }
        else {
          if ((DAT_007e0952 & 8) != 0) {
            uVar6 = 10;
          }
          else {
            if ((DAT_007e0952 & 0x8000) != 0) {
              uVar6 = 0xffffffffffffffff;
            }
            else {
              if ((DAT_007e0952 & 4) != 0) {
                uVar6 = 0xfffffffffffffff6;
              }
            }
          }
        }
        break;
      }

      auStack_10[0] = *(u32 *)(puVar1 + 2);

      auStack_10[1] = *(u32 *)(puVar1 + 4);

      auStack_10[2] = *(u32 *)(puVar1 + 6);

      afStack_20[0] = (float)*(int *)(iVar5 + 0x19c);

      afStack_20[1] = (float)*(int *)(iVar5 + 0x198);

      afStack_20[2] = 0.0f;

      FUN_003bb9b0(afStack_20);

      *(int *)(iVar5 + 0x19c) = (int)afStack_20[0];

      *(int *)(iVar5 + 0x198) = (int)afStack_20[1];

      FUN_003b79a0(auStack_60,auStack_10,afStack_20);

      FUN_003957d0(150.0f, param_3, (u32*)auStack_60);

      uVar3 = FUN_0038a480(*(u32 *)(iVar5 + 0x16c),uVar6,*(u32 *)(iVar5 + 0x170),

                           *(u32 *)(iVar5 + 0x174));

      *(u32 *)(iVar5 + 0x16c) = uVar3;

      FUN_003b7460(puVar1,0,puVar1 + 8,0);

      if ((int)(*puVar1 & 0xffc00) >> 10 == 7) {

        FUN_00396270(20.0f,param_3,puVar1 + 2);

      }

      else {

        FUN_00396270(50.0f,param_3,puVar1 + 2);

      }

      if ((DAT_007e094e & 0x40) != 0) {

        uVar3 = 1;

      }

      else {

        if ((DAT_007e094e & 0x20) == 0) {

          uVar3 = 0;

        }

        else {

          uVar3 = *(u32 *)(iVar5 + 0x230);

          uVar7 = *(u32 *)(iVar5 + 0x234);

          *(u32 *)(puVar1 + 8) = *(u32 *)(iVar5 + 0x22c);

          *(u32 *)(puVar1 + 10) = uVar3;

          *(u32 *)(puVar1 + 0xc) = uVar7;

          FUN_003b7460(puVar1,0,puVar1 + 8,0);

          FUN_0038a620(param_3,1);

          uVar3 = 0xffffffff;

        }

      }

    }

  }

  return uVar3;

}


// FUN_0037C2E0


u32 FUN_0037c2e0(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069fa70);

  return 2;

}


// FUN_0037C350 NONMATCHING


void FUN_0037c350(int param_1,int param_2,int param_3,int param_4)



{

  int iVar1;

  u32 uVar2;

  int iVar3;
  int scaledY;

  f32 uVar4;

  u8 *apuStack_28 [9];

  u8 auStack_b0 [64];

  u8 auStack_70 [72];

  

  uVar2 = 0;

  apuStack_28[0] = PTR_DAT_007cd238;
  apuStack_28[1] = PTR_DAT_007cd23c;
  apuStack_28[2] = PTR_DAT_007cd230;
  apuStack_28[3] = PTR_DAT_007cd234;
  apuStack_28[4] = PTR_s_SPEED_007cd228;
  apuStack_28[5] = PTR_s_LENGTH_007cd22c;
  apuStack_28[6] = PTR_DAT_0069fa80;
  apuStack_28[7] = PTR_s_BEZIER_0069fa84;
  apuStack_28[8] = PTR_s_DIRECT_0069fa88;

  iVar1 = FUN_00361830(param_4);

  iVar3 = (int)param_4;

  if (*(int *)(iVar3 + 400) == param_3) {

    uVar2 = 4;

  }
  scaledY = param_2 * 0xc;

  switch(param_3) {

  case 0:

    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0, (const char *)0x69fa90);

    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

    evtMenuDrawText((param_1 + 0xc) * 0xc, scaledY, uVar4, uVar2, (const char *)0x7ccd58, apuStack_28[*(int *)(iVar3 + 0x198) + 6]);

    break;

  case 1:


    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0, (const char *)0x69faa0);

    if (*(int *)(iVar3 + 0x198) != 2) {

      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

      evtMenuDrawText((param_1 + 0xc) * 0xc, scaledY, uVar4, uVar2, (const char *)0x7ccd58, apuStack_28[*(int *)(iVar3 + 0x19c) + 4]);

    }

    else {

      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

      evtMenuDrawText((param_1 + 0xc) * 0xc, scaledY, uVar4, uVar2, (const char *)0x7cd240);

    }

    break;

  case 2:


    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0, (const char *)0x69fab0);

    if (*(int *)(iVar3 + 0x198) == 2) {

      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

      evtMenuDrawText((param_1 + 0xc) * 0xc, scaledY, uVar4, uVar2, (const char *)0x7cd240);

    }

    else if (*(int *)(iVar3 + 0x19c) == 0) {

      FUN_00523ac8(auStack_70,0x7cd1e0,*(int *)(iVar3 + 0x1a0) + 1);

      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

      evtMenuDrawText((param_1 + 0xc) * 0xc, scaledY, uVar4, uVar2, (const char *)0x7ccd58, auStack_70);

    }

    else {

      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

      evtMenuDrawText((param_1 + 0xc) * 0xc, scaledY, uVar4, uVar2, (const char *)0x7cd0a8, *(u32 *)(iVar3 + 0x1a0));

    }

    break;

  case 3:


    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0, (const char *)0x69fac0);

    if (1 < *(int *)(iVar3 + 0x1a4)) {

      *(u32 *)(iVar3 + 0x1a4) = 0;

    }

    if (*(int *)(iVar3 + 0x198) != 2) {

      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

      evtMenuDrawText((param_1 + 0xc) * 0xc, scaledY, uVar4, uVar2, (const char *)0x7ccd58, apuStack_28[*(int *)(iVar3 + 0x1a4) + 2]);

    }

    else {

      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

      evtMenuDrawText((param_1 + 0xc) * 0xc, scaledY, uVar4, uVar2, (const char *)0x7cd240);

    }

    break;

  case 4:


    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0, (const char *)0x69fad0);

    if (1 < *(int *)(iVar3 + 0x1a8)) {

      *(u32 *)(iVar3 + 0x1a8) = 0;

    }

    if (*(int *)(iVar3 + 0x198) != 2) {

      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

      evtMenuDrawText((param_1 + 0xc) * 0xc, scaledY, uVar4, uVar2, (const char *)0x7ccd58, apuStack_28[*(int *)(iVar3 + 0x1a8) + 2]);

    }

    else {

      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

      evtMenuDrawText((param_1 + 0xc) * 0xc, scaledY, uVar4, uVar2, (const char *)0x7cd240);

    }

    break;

  case 5:


    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0, (const char *)0x69fae0);

    if (1 < *(int *)(iVar3 + 0x1a8)) {

      *(u32 *)(iVar3 + 0x1a8) = 0;

    }

    if (*(int *)(iVar3 + 0x198) == 0) {

      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

      evtMenuDrawText((param_1 + 0xc) * 0xc, scaledY, uVar4, uVar2, (const char *)0x7ccd58, apuStack_28[*(int *)(iVar3 + 0x1ac)]);

    }

    else {

      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

      evtMenuDrawText((param_1 + 0xc) * 0xc, scaledY, uVar4, uVar2, (const char *)0x7cd240);

    }

    break;

  case 6:


    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0, (const char *)0x7cd248);

    if (*(int *)(iVar3 + 0x198) != 2) {

      if (*(char *)(iVar1 + 0x34) != '\0') {

        FUN_00523ac8(auStack_b0,0x69faf0,0x7ccdb0,*(u8 *)(iVar1 + 0x35),

                     *(u8 *)(iVar1 + 0x36),*(u8 *)(iVar1 + 0x37));

      }

      else {

        FUN_00523ac8(auStack_b0,0x7ccd58,0x7ccda8);

      }

      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

      evtMenuDrawText((param_1 + 0xc) * 0xc, scaledY, uVar4, uVar2, (const char *)0x7ccd58, auStack_b0);

    }

    else {

      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

      evtMenuDrawText((param_1 + 0xc) * 0xc, scaledY, uVar4, uVar2, (const char *)0x7cd250);

    }

    break;

  case 7:

    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, uVar2, (const char *)0x69fb00);

  }

  return;

}


// FUN_0037CAF0 NONMATCHING


int FUN_0037caf0(int param_1,int param_2,int param_3)



{

  long lVar1;

  int iVar2;

  

  lVar1 = FUN_003b5d00();

  if (lVar1 == 0) {

    return -1;

  }

  FUN_0036f900(param_1,param_2,0x1a,0xb,0,1,param_3,0x37c2e0,0);

  iVar2 = (int)param_3;

  if (*(int *)(iVar2 + 0xd4) != 0x1b) {

    return 0;

  }

  if ((DAT_007e0952 & 0x1000) == 0) {

    if ((DAT_007e0952 & 0x4000) != 0) {

      if (*(int *)(iVar2 + 400) == 7) {

        *(u32 *)(iVar2 + 400) = 0;

      }

      else {

        *(int *)(iVar2 + 400) = *(int *)(iVar2 + 400) + 1;

      }

    }

  }

  else if (*(int *)(iVar2 + 400) == 0) {

    *(u32 *)(iVar2 + 400) = 7;

  }

  else {

    *(int *)(iVar2 + 400) = *(int *)(iVar2 + 400) + -1;

  }

  switch(*(u32 *)(iVar2 + 400)) {

  case 0:

    if ((DAT_007e0952 & 0x2000) == 0) {

      if ((DAT_007e0952 & 0x8000) != 0) {

        if (*(int *)(iVar2 + 0x198) < 1) {

          *(u32 *)(iVar2 + 0x198) = 2;

        }

        else {

          *(int *)(iVar2 + 0x198) = *(int *)(iVar2 + 0x198) + -1;

        }

      }

    }

    else if (*(int *)(iVar2 + 0x198) < 2) {

      *(int *)(iVar2 + 0x198) = *(int *)(iVar2 + 0x198) + 1;

    }

    else {

      *(u32 *)(iVar2 + 0x198) = 0;

    }

    break;

  case 1:

    if (*(int *)(iVar2 + 0x198) != 2) {

      if ((DAT_007e0952 & 0x2000) != 0) {

        if (*(int *)(iVar2 + 0x19c) < 1) {

          *(int *)(iVar2 + 0x19c) = *(int *)(iVar2 + 0x19c) + 1;

        }

        else {

          *(u32 *)(iVar2 + 0x19c) = 0;

        }

        *(u32 *)(iVar2 + 0x1a0) = 0;

      }

      else {

        if ((DAT_007e0952 & 0x8000) != 0) {

          if (*(int *)(iVar2 + 0x19c) < 1) {

            *(u32 *)(iVar2 + 0x19c) = 1;

          }

          else {

            *(int *)(iVar2 + 0x19c) = *(int *)(iVar2 + 0x19c) + -1;

          }

          *(u32 *)(iVar2 + 0x1a0) = 0;

        }

      }

    }

    break;

  case 2:

    if (*(int *)(iVar2 + 0x198) != 2) {

      if (*(int *)(iVar2 + 0x19c) == 0) {

        if ((DAT_007e0952 & 0x2000) == 0) {

          if ((DAT_007e0952 & 0x8000) != 0) {

            if (*(int *)(iVar2 + 0x1a0) < 1) {

              *(u32 *)(iVar2 + 0x1a0) = 99;

            }

            else {

              *(int *)(iVar2 + 0x1a0) = *(int *)(iVar2 + 0x1a0) + -1;

            }

          }

        }

        else if (*(int *)(iVar2 + 0x1a0) < 99) {

          *(int *)(iVar2 + 0x1a0) = *(int *)(iVar2 + 0x1a0) + 1;

        }

        else {

          *(u32 *)(iVar2 + 0x1a0) = 0;

        }

      }

      else if ((DAT_007e0952 & 0x2000) == 0) {

        if ((DAT_007e0952 & 8) != 0) {

          *(int *)(iVar2 + 0x1a0) = *(int *)(iVar2 + 0x1a0) + 10;

        }

        else {

          if ((DAT_007e0952 & 0x8000) != 0) {

            *(int *)(iVar2 + 0x1a0) = *(int *)(iVar2 + 0x1a0) + -1;

          }

          else {

            if ((DAT_007e0952 & 4) != 0) {

              *(int *)(iVar2 + 0x1a0) = *(int *)(iVar2 + 0x1a0) + -10;

            }

          }

        }

      }

      else {

        *(int *)(iVar2 + 0x1a0) = *(int *)(iVar2 + 0x1a0) + 1;

      }

      break;

    }

  case 3:

    if ((*(int *)(iVar2 + 0x198) != 2) &&

       (((DAT_007e0952 & 0x2000) != 0 || ((DAT_007e0952 & 0x8000) != 0)))) {

      *(u32 *)(iVar2 + 0x1a4) = (u32)(*(int *)(iVar2 + 0x1a4) == 0);

    }

    break;

  case 4:

    if ((*(int *)(iVar2 + 0x198) != 2) &&

       (((DAT_007e0952 & 0x2000) != 0 || ((DAT_007e0952 & 0x8000) != 0)))) {

      *(u32 *)(iVar2 + 0x1a8) = (u32)(*(int *)(iVar2 + 0x1a8) == 0);

    }

    break;

  case 5:

    if ((*(int *)(iVar2 + 0x198) == 0) &&

       (((DAT_007e0952 & 0x2000) != 0 || ((DAT_007e0952 & 0x8000) != 0)))) {

      *(u32 *)(iVar2 + 0x1ac) = (u32)(*(int *)(iVar2 + 0x1ac) == 0);

    }

  }

  if ((DAT_007e094e & 0x40) == 0) {

    iVar2 = -(u32)((DAT_007e094e & 0x20) != 0);

  }

  else {

    iVar2 = 1;

  }

  return iVar2;

}


// FUN_0037CF50


void FUN_0037cf50(u32 *param_1,u32 *param_2,u32 *param_3)



{

  u32 uVar1;

  u32 uVar2;
  struct Vec3 { f32 x; f32 y; f32 z; };

  u32 *puVar4;
  int iVar3;

  

  DAT_007ce5fc = 0;

  puVar4 = (u32 *)DAT_00958700_abs;
  iVar3 = 0x26;

  do {

    uVar1 = *param_1;

    uVar2 = param_1[1];

    param_1 = param_1 + 2;

    iVar3 = iVar3 + -1;

    *puVar4 = uVar1;

    puVar4[1] = uVar2;

    puVar4 = puVar4 + 2;

  } while (0 < iVar3);

  *(struct Vec3 *)DAT_009585b8_abs = *(struct Vec3 *)param_2;
  *(struct Vec3 *)DAT_009585a8_abs = *(struct Vec3 *)param_3;

  return;

}


/* opt_loop_invariants on: default nd749/1072B -> nd748/1052B; retained. */
#pragma opt_loop_invariants on
/* opt_propagation off: default nd748/1044B -> nd714/1044B; retained. */
#pragma push
#pragma opt_propagation off
// FUN_0037CFE0 NONMATCHING


void FUN_0037cfe0(void)
{
  typedef struct EvtMenuTransformResult {
    u8 matrix[32];
    RwV3d direction;
  } EvtMenuTransformResult;
  typedef struct EvtMenuCurveSamples {
    f32 x[4];
    f32 y[4];
    f32 z[4];
  } EvtMenuCurveSamples;
  u32 entry;

  entry = (u32)DAT_00958700_abs[1];
  if (entry < 8) {
    if (entry == 0) {
      EvtMenuTransformResult transform;
      EvtMenuCurveSamples origin;
      RwV3d normalized;
      RwV3d scaled;

      origin.x[0] = DAT_009585b8_f32_abs[0];
      origin.y[0] = DAT_009585bc_f32_abs[0];
      origin.z[0] = DAT_009585c0_f32_abs[0];
      FUN_003b79a0(&transform,DAT_009585b8_abs,DAT_009585a8_abs);
      FUN_004c69f0(&normalized,&transform.direction);
      DAT_00958704_f32_abs[0] = DAT_009585b8_f32_abs[0];
      DAT_00958708_f32_abs[0] = DAT_009585bc_f32_abs[0];
      DAT_0095870c_f32_abs[0] = DAT_009585c0_f32_abs[0];
      scaled.x = normalized.x * 200.0f;
      scaled.y = normalized.y * 200.0f;
      scaled.z = normalized.z * 200.0f;
      DAT_00958710_f32_abs[0] = DAT_009585b8_f32_abs[0] + DAT_007cb120_f32 * scaled.x;
      DAT_00958714_f32_abs[0] = DAT_009585bc_f32_abs[0] + DAT_007cb120_f32 * scaled.y;
      DAT_00958718_f32_abs[0] = DAT_009585c0_f32_abs[0] + DAT_007cb120_f32 * scaled.z;
      DAT_0095871c_f32_abs[0] = DAT_009585b8_f32_abs[0] + DAT_007cb124_f32 * scaled.x;
      DAT_00958720_f32_abs[0] = DAT_009585bc_f32_abs[0] + DAT_007cb124_f32 * scaled.y;
      DAT_00958724_f32_abs[0] = DAT_009585c0_f32_abs[0] + DAT_007cb124_f32 * scaled.z;
      DAT_00958728_f32_abs[0] = DAT_009585b8_f32_abs[0] + scaled.x;
      DAT_0095872c_f32_abs[0] = DAT_009585bc_f32_abs[0] + scaled.y;
      DAT_00958730_f32_abs[0] = DAT_009585c0_f32_abs[0] + scaled.z;
      FUN_005225a8(0x69fb20,0,4);
      (((u8 *)&DAT_00958700)[1]) = (((u8 *)&DAT_00958700)[1]) + 1;
    } else {
      EvtMenuCurveSamples samples;
      RwV3d curveStart;
      RwV3d curveEnd;
      RwV3d delta;
      RwV3d normalized;
      RwV3d offset120;
      RwV3d offset124;
      RwV3d offsetFull;
      u32 argX;
      u32 argY;
      u32 argZ;
      int outputIndex;
      int sampleBase;
      int i;
      f32 *baseX;
      f32 *baseY;
      f32 *baseZ;

      if (entry != 1) {
        sampleBase = (entry - 1) * 3;
      } else {
        sampleBase = 0;
      }
      for (i = 0; i < 4; i = i + 1) {
        samples.x[i] = DAT_00958700_f32[sampleBase * 3 + i * 3 + 1];
        samples.y[i] = DAT_00958700_f32[sampleBase * 3 + i * 3 + 2];
        samples.z[i] = DAT_00958700_f32[sampleBase * 3 + i * 3 + 3];
      }
      FUN_003bbc90(DAT_007cae18,samples.x,samples.y,samples.z,
                   &curveStart.x,&curveStart.y,&curveStart.z);
      FUN_003bbc90(0x3f800000,samples.x,samples.y,samples.z,
                   &curveEnd.x,&curveEnd.y,&curveEnd.z);
      delta.x = curveEnd.x - curveStart.x;
      delta.y = curveEnd.y - curveStart.y;
      delta.z = curveEnd.z - curveStart.z;
      FUN_004c69f0(&normalized,&delta);
      argX = FUN_00530da0_evt(delta.x);
      argY = FUN_00530da0_evt(delta.y);
      argZ = FUN_00530da0_evt(delta.z);
      FUN_005225a8(0x69fb40,argX,argY,argZ);
      offset120.x = DAT_007cb120_f32 * (normalized.x * 200.0f);
      offset120.y = DAT_007cb120_f32 * (normalized.y * 200.0f);
      offset120.z = DAT_007cb120_f32 * (normalized.z * 200.0f);
      outputIndex = sampleBase * 0xc;
      baseX = DAT_00958728_f32_abs + sampleBase * 3;
      DAT_00958734_f32_abs[outputIndex] = *baseX + offset120.x;
      baseY = DAT_0095872c_f32_abs + sampleBase * 3;
      DAT_00958738_f32_abs[outputIndex] = *baseY + offset120.y;
      baseZ = DAT_00958730_f32_abs + sampleBase * 3;
      DAT_0095873c_f32_abs[outputIndex] = *baseZ + offset120.z;
      offset124.x = DAT_007cb124_f32 * (normalized.x * 200.0f);
      offset124.y = DAT_007cb124_f32 * (normalized.y * 200.0f);
      offset124.z = DAT_007cb124_f32 * (normalized.z * 200.0f);
      DAT_00958740_f32_abs[outputIndex] = *baseX + offset124.x;
      DAT_00958744_f32_abs[outputIndex] = *baseY + offset124.y;
      DAT_00958748_f32_abs[outputIndex] = *baseZ + offset124.z;
      offsetFull.x = normalized.x * 200.0f;
      offsetFull.y = normalized.y * 200.0f;
      offsetFull.z = normalized.z * 200.0f;
      DAT_0095874c_f32_abs[outputIndex] = *baseX + offsetFull.x;
      DAT_00958750_f32_abs[outputIndex] = *baseY + offsetFull.y;
      DAT_00958754_f32_abs[outputIndex] = *baseZ + offsetFull.z;
    }
  }
}
#pragma pop
#pragma opt_loop_invariants reset


// FUN_0037D4D0


u32 FUN_0037d4d0(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069fb58);

  return 2;

}


// FUN_0037D540

void FUN_0037d540(int param_1,int param_2,long param_3,int param_4)



{
  f32 uVar1;

  switch (param_3) {
  case 0:
    uVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));

    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069fb70_abs, *(u8 *)(0x958700 + 1));
    break;
  default:
    break;
  }
  return;
}


/* opt_loop_invariants on: default nd1666/2300B -> nd1637/2268B; retained. */
#pragma opt_loop_invariants on
/* opt_lifetimes on: default nd1637/2268B -> nd1633/2268B; retained. */
#pragma push
#pragma opt_lifetimes on
// FUN_0037D5D0 NONMATCHING


int FUN_0037d5d0(int param_1,int param_2,int param_3)



{
  typedef struct EvtMenuVectorTable {
    u_long128 data[0x13];
  } EvtMenuVectorTable;

  RwV3d *pfVar2;

  u16 uVar3;

  RwV3d *pfVar4;

  u32 lVar5;

  f32 uVar6;

  f32 uVar7;

  RwV3d *pfVar8;

  int iVar9;

  int iVar10;

  int iVar13;

  RwV3d collisionBase;

  RwV3d collisionInput;




  RwV3d direction2 = {0};

  RwV3d collisionOutput;




  RwV3d direction1 = {0};




  


  lVar5 = FUN_003b5d00();

  if (lVar5 == 0) {

    iVar10 = -1;

  }

  else {

    FUN_0036f900(param_1,param_2,0x14,4,0,1,param_3,0x37d4d0,0);

    FUN_00395930(param_3,0x958700,DAT_007ce5fc);

    if (*(int *)((int)param_3 + 0xd4) != 0x1c) {

      iVar10 = 0;

    }

    else {

      FUN_003625e0_i(param_3);

      FUN_0038a7c0((u32 *)&direction1,(u32 *)&direction2);

      iVar10 = DAT_007ce5fc;

      pfVar8 = (RwV3d *)DAT_00958704_f32_abs + DAT_007ce5fc;

      if ((DAT_007e094c & 0x10) != 0) { iVar13 = (u32)(((u8 *)&DAT_00958700)[1]) * 3 + 1;
      
      if ((DAT_007e094e & 8) != 0) {
      
        FUN_0037cfe0();
      
      }
      
      else {
      
        if ((DAT_007e094e & 2) == 0) {
      
          if ((DAT_007e094e & 0x80) != 0) {
      
            for (iVar9 = 0; iVar9 < iVar13; iVar9 = iVar9 + 1) {
      
              ((RwV3d *)DAT_00958704_f32_abs)[iVar9].y = pfVar8->y;
      
            }
      
          }
      
        }
      
        else {
      
          if ((((u8 *)&DAT_00958700)[1]) == 0) {
      
            (((u8 *)&DAT_00958700)[1]) = 0;
      
          }
      
          else {
      
            (((u8 *)&DAT_00958700)[1]) = (((u8 *)&DAT_00958700)[1]) - 1;
      
          }
      
          if ((int)((u32)(((u8 *)&DAT_00958700)[1]) * 3 + 1) <= DAT_007ce5fc) {
      
            DAT_007ce5fc = (u32)(((u8 *)&DAT_00958700)[1]) * 3;
      
          }
      
        }
      
      }
      
      uVar3 = DAT_007e094c;
      
      if ((DAT_007e094c & 0x1000) != 0) {
      
        for (iVar10 = 0; iVar10 < iVar13; iVar10 = iVar10 + 1) {
      
          ((RwV3d *)DAT_00958704_f32_abs)[iVar10].x =
              ((RwV3d *)DAT_00958704_f32_abs)[iVar10].x + direction1.x * 5.0f;
          ((RwV3d *)DAT_00958704_f32_abs)[iVar10].y =
              ((RwV3d *)DAT_00958704_f32_abs)[iVar10].y + direction1.y * 5.0f;
          ((RwV3d *)DAT_00958704_f32_abs)[iVar10].z =
              ((RwV3d *)DAT_00958704_f32_abs)[iVar10].z + direction1.z * 5.0f;
      
        }
      
      }
      
      else {
      
        if ((DAT_007e094c & 0x4000) != 0) {
      
          for (iVar10 = 0; iVar10 < iVar13; iVar10 = iVar10 + 1) {
      
            ((RwV3d *)DAT_00958704_f32_abs)[iVar10].x =
                ((RwV3d *)DAT_00958704_f32_abs)[iVar10].x - direction1.x * 5.0f;
            ((RwV3d *)DAT_00958704_f32_abs)[iVar10].y =
                ((RwV3d *)DAT_00958704_f32_abs)[iVar10].y - direction1.y * 5.0f;
            ((RwV3d *)DAT_00958704_f32_abs)[iVar10].z =
                ((RwV3d *)DAT_00958704_f32_abs)[iVar10].z - direction1.z * 5.0f;
      
          }
      
        }
      
      }
      
      if ((uVar3 & 0x2000) != 0) {
      
        for (iVar10 = 0; iVar10 < iVar13; iVar10 = iVar10 + 1) {
      
          ((RwV3d *)DAT_00958704_f32_abs)[iVar10].x =
              ((RwV3d *)DAT_00958704_f32_abs)[iVar10].x - direction2.x * 5.0f;
          ((RwV3d *)DAT_00958704_f32_abs)[iVar10].y =
              ((RwV3d *)DAT_00958704_f32_abs)[iVar10].y - direction2.y * 5.0f;
          ((RwV3d *)DAT_00958704_f32_abs)[iVar10].z =
              ((RwV3d *)DAT_00958704_f32_abs)[iVar10].z - direction2.z * 5.0f;
      
        }
      
      }
      
      else {
      
        if ((uVar3 & 0x8000) != 0) {
      
          for (iVar10 = 0; iVar10 < iVar13; iVar10 = iVar10 + 1) {
      
            ((RwV3d *)DAT_00958704_f32_abs)[iVar10].x =
                ((RwV3d *)DAT_00958704_f32_abs)[iVar10].x + direction2.x * 5.0f;
            ((RwV3d *)DAT_00958704_f32_abs)[iVar10].y =
                ((RwV3d *)DAT_00958704_f32_abs)[iVar10].y + direction2.y * 5.0f;
            ((RwV3d *)DAT_00958704_f32_abs)[iVar10].z =
                ((RwV3d *)DAT_00958704_f32_abs)[iVar10].z + direction2.z * 5.0f;
      
          }
      
        }
      
      }
      
      uVar3 = DAT_007e0952;
      
      if ((DAT_007e0952 & 4) != 0) {
      
        for (iVar10 = 0; iVar10 < iVar13; iVar10 = iVar10 + 1) {
      
          ((RwV3d *)DAT_00958704_f32_abs)[iVar10].y =
              ((RwV3d *)DAT_00958704_f32_abs)[iVar10].y + 5.0f;
      
        }
      
      }
      
      else {
      
        if ((DAT_007e0952 & 1) != 0) {
      
          for (iVar10 = 0; iVar10 < iVar13; iVar10 = iVar10 + 1) {
      
            ((RwV3d *)DAT_00958704_f32_abs)[iVar10].y =
                ((RwV3d *)DAT_00958704_f32_abs)[iVar10].y - 5.0f;
      
          }
      
        }
      
      }
      
      
      if ((uVar3 & 0x100) != 0) {
        *(EvtMenuVectorTable *)&DAT_009585d0 =
            *(EvtMenuVectorTable *)&DAT_00958700;
      } else if ((uVar3 & 0x800) != 0) {
        *(EvtMenuVectorTable *)&DAT_00958700 =
            *(EvtMenuVectorTable *)&DAT_009585d0;
      } } else { if ((DAT_007e0952 & 8) == 0) {
      
        if ((DAT_007e0952 & 2) != 0) {
      
          if (DAT_007ce5fc < 1) {
      
            DAT_007ce5fc = (u32)(((u8 *)&DAT_00958700)[1]) * 3;
      
          }
      
          else {
      
            DAT_007ce5fc = DAT_007ce5fc + -1;
      
          }
      
        }
      
      }
      
      else if (DAT_007ce5fc < (int)((u32)(((u8 *)&DAT_00958700)[1]) * 3)) {
      
        DAT_007ce5fc = DAT_007ce5fc + 1;
      
      }
      
      else {
      
        DAT_007ce5fc = 0;
      
      }
      
      if ((DAT_007e094c & 0x1000) != 0) {
      
        pfVar8->x = direction1.x * 5.0f + pfVar8->x + 0.0f;
        pfVar8->y = direction1.y * 5.0f + pfVar8->y + 0.0f;
        pfVar8->z = direction1.z * 5.0f + pfVar8->z + 0.0f;
      
      }
      
      else {
      
        if ((DAT_007e094c & 0x4000) != 0) {
      
        pfVar8->x = (pfVar8->x + 0.0f) - direction1.x * 5.0f;
          pfVar8->y = pfVar8->y - direction1.y * 5.0f;
          pfVar8->z = pfVar8->z - direction1.z * 5.0f;
      
        }
      
      }
      
      if ((DAT_007e094c & 0x2000) != 0) {
      
        pfVar8->x = (pfVar8->x + 0.0f) - direction2.x * 5.0f;
        pfVar8->y = (pfVar8->y + 0.0f) - direction2.y * 5.0f;
        pfVar8->z = (pfVar8->z + 0.0f) - direction2.z * 5.0f;
      
      }
      
      else {
      
        if ((DAT_007e094c & 0x8000) != 0) {
      
          pfVar8->x = direction2.x * 5.0f + pfVar8->x + 0.0f;
          pfVar8->y = direction2.y * 5.0f + pfVar8->y + 0.0f;
          pfVar8->z = direction2.z * 5.0f + pfVar8->z + 0.0f;
      
        }
      
      }
      
      if ((DAT_007e094c & 0x80) == 0) {
      
        if ((DAT_007e0952 & 4) != 0) {
      
          pfVar8->y = pfVar8->y + 5.0f;
      
        }
      
        else {
      
          if ((DAT_007e0952 & 1) != 0) {
      
            pfVar8->y = pfVar8->y - 5.0f;
      
          }
      
        }
      
      }
      
      else {
      
        collisionBase = *pfVar8;

        collisionInput = collisionBase;
        collisionInput.y = collisionInput.y - 1000.0f;
      
      
        lVar5 = FUN_001acc30(&collisionInput,&collisionOutput);
      
      
        if (lVar5 == 1) {
      
      
          *pfVar8 = collisionOutput;
      
        }
      
      }
      
      uVar7 = DAT_00958848_f32_abs[0];
      
      uVar6 = DAT_00958844_f32_abs[0];
      
      iVar10 = DAT_007ce5fc;
      
      if ((DAT_007e0952 & 0x100) == 0) {
      
        if ((DAT_007e0952 & 0x800) != 0) {
      
          pfVar8->x = DAT_00958840_f32_abs[0];
          pfVar8->y = uVar6;
          pfVar8->z = uVar7;
      
        }
      
      }
      
      else {
      
        DAT_00958840_f32_abs[0] = pfVar8->x;
        DAT_00958844_f32_abs[0] = pfVar8->y;
        DAT_00958848_f32_abs[0] = pfVar8->z;
      
        DAT_00958838 = 0;
      
        DAT_00958834 = 0;
      
        DAT_00958830 = 0;
      
      } }

      if ((DAT_007e094e & 0x40) == 0) {

        iVar10 = -(u32)((DAT_007e094e & 0x20) != 0);

      }

      else {

        iVar10 = 1;

      }

    }

  }

  return iVar10;

}
#pragma pop
#pragma opt_loop_invariants reset


// FUN_0037DF50


u32 FUN_0037df50(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069fb88);

  return 2;

}


// FUN_0037DFC0


void FUN_0037dfc0(int column, int row, int item, int menu)
{
  typedef union EvtMenuLabel {
    f32 storage;
    u8 *text;
  } EvtMenuLabel;
  u32 colour = 0;
  EvtMenuLabel labels[2];

  *(RwV2d *)labels = *(RwV2d *)&PTR_s_DIRECT_007cd258_f32;

  if (*(int *)(menu + 0x190) == item) {
    colour = 4;
  }

  switch (item) {
  case 0:
    if (*(int *)(menu + 0x198) < 2) {
      int y = row * 0xc;
      int x = column * 0xc;
      f32 scale = FUN_0038a220(*(u32 *)(menu + 0xe0));

      evtMenuDrawText(x, y, scale, 0, (const char *)&gp0xffff9fb8);
      scale = FUN_0038a220(*(u32 *)(menu + 0xe0));
      evtMenuDrawText(x, y, scale, colour, (const char *)DAT_0069fb98_abs,
                      labels[*(int *)(menu + 0x198)].text);
    }
    break;

  case 1:
    {
      int y = row * 0xc;
      int x = column * 0xc;
      u8 *detail;
      f32 scale = FUN_0038a220(*(u32 *)(menu + 0xe0));

      evtMenuDrawText(x, y, scale, 0, (const char *)&gp0xffffa570);
      scale = FUN_0038a220(*(u32 *)(menu + 0xe0));
      evtMenuDrawText(x, y, scale, colour, (const char *)DAT_0069fba8_abs,
                      *(u32 *)(menu + 0x19c));

      if (*(int *)(menu + 0x198) == 1) {
        detail = 0;
        if (FUN_00397630(menu, *(u32 *)(menu + 0x19c), &detail) == 1) {
          scale = FUN_0038a220(*(u32 *)(menu + 0xe0));
          evtMenuDrawText(x, y, scale, colour,
                          (const char *)DAT_0069fbc0_abs, detail);
        }
      }
    }
    break;
  }
}


/* opt_lifetimes on: default nd397/556B -> nd384/556B; retained. */
#pragma push
#pragma opt_lifetimes on
// FUN_0037E1B0 NONMATCHING


int FUN_0037e1b0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  iVar1 = 0;

  FUN_0036f900(param_1,param_2,0x14,5,0,1,param_3,0x37df50,0);

  iVar2 = (int)param_3;

  if (*(int *)(iVar2 + 0xd4) != 0x1d) {

    iVar1 = 0;

  }

  else {

    if ((DAT_007e0952 & 0x1000) == 0) {

      if ((DAT_007e0952 & 0x4000) != 0) {

        if (*(int *)(iVar2 + 400) == 1) {

          *(u32 *)(iVar2 + 400) = 0;

        }

        else {

          *(int *)(iVar2 + 400) = *(int *)(iVar2 + 400) + 1;

        }

      }

    }

    else if (*(int *)(iVar2 + 400) == 0) {

      *(u32 *)(iVar2 + 400) = 1;

    }

    else {

      *(int *)(iVar2 + 400) = *(int *)(iVar2 + 400) + -1;

    }

    if (*(int *)(iVar2 + 400) == 1) {

      if (*(int *)(iVar2 + 0x198) == 0) {

        iVar1 = 0x19;

      }

      else if (*(int *)(iVar2 + 0x198) == 1) {

        iVar1 = 10;

      }

      if ((DAT_007e0952 & 0x2000) != 0) {

        *(int *)(iVar2 + 0x19c) = *(int *)(iVar2 + 0x19c) + 1;

      }

      else {

        if ((DAT_007e0952 & 0x8000) != 0) {

          *(int *)(iVar2 + 0x19c) = *(int *)(iVar2 + 0x19c) + -1;

        }

      }

      if (*(int *)(iVar2 + 0x19c) >= iVar1) {

        *(u32 *)(iVar2 + 0x19c) = 0;

      }

      else {

        if (*(int *)(iVar2 + 0x19c) < 0) {

          *(int *)(iVar2 + 0x19c) = iVar1 + -1;

        }

      }

    }

    else if (*(int *)(iVar2 + 400) == 0) {

      if ((DAT_007e0952 & 0x2000) != 0) {

        if (*(int *)(iVar2 + 0x198) < 1) {

          *(int *)(iVar2 + 0x198) = *(int *)(iVar2 + 0x198) + 1;

        }

        else {

          *(u32 *)(iVar2 + 0x198) = 0;

        }

        *(u32 *)(iVar2 + 0x19c) = 0;

      }

      else {

        if ((DAT_007e0952 & 0x8000) != 0) {

          if (*(int *)(iVar2 + 0x198) == 0) {

            *(u32 *)(iVar2 + 0x198) = 1;

          }

          else {

            *(int *)(iVar2 + 0x198) = *(int *)(iVar2 + 0x198) + -1;

          }

          *(u32 *)(iVar2 + 0x19c) = 0;

        }

      }

    }

    if ((DAT_007e094e & 0x40) == 0) {

      iVar1 = -(u32)((DAT_007e094e & 0x20) != 0);

    }

    else {

      iVar1 = 1;

    }

  }

  return iVar1;

}
#pragma pop


// FUN_0037E3F0


u32 FUN_0037e3f0(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));
  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069fbd8);

  return 2;

}


// FUN_0037E460
void FUN_0037e460(u32 param_1,u32 param_2,u32 param_3,u8 *param_4)
{
  RwV2d local0;
  u32 local1_3;
  u32 local1_2;
  u32 local1_1;
  u32 local1_0;
  int iVar3;
  f32 fVar1;
  iVar3 = 0;
  local0 = *(RwV2d *)&gp0xffffa578_f32v;
  if (*(int *)(param_4 + 0x190) == (int)param_3) {
    iVar3 = 4;
  }
  switch (param_3) {
  case 0: {
    s32 scaledY = param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, fVar1, 0, (const char *)&gp0xffffa580);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0xa) * 0xc, scaledY, fVar1, iVar3, (const char *)&gp0xffffa588, *(u32 *)(param_4 + 0x198));
    break;
  }
  case 1: {
    s32 scaledY = param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, fVar1, 0, (const char *)&gp0xffffa590);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0xa) * 0xc, scaledY, fVar1, iVar3, (const char *)&gp0xffffa588, *(u32 *)(param_4 + 0x19c));
    break;
  }
  case 2: {
    if (*(int *)(param_4 + 0x1a0) < 2) {
      s32 scaledY = param_2 * 0xc;
      fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText(param_1 * 0xc, scaledY, fVar1, 0, (const char *)&gp0xffffa570);
      fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0xa) * 0xc, scaledY, fVar1, iVar3, (const char *)&gp0xffffa598, ((u32 *)&local0)[*(int *)(param_4 + 0x1a0)]);
    }
    break;
  }
  case 3: {
    s32 scaledY = param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, fVar1, 0, (const char *)&gp0xffffa5a0);
    if (*(int *)(param_4 + 0x1a0) == 0) {
      fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0xa) * 0xc, scaledY, fVar1, iVar3, (const char *)&gp0xffffa588, *(u32 *)(param_4 + 0x1a4));
    }
    else {
      fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0xa) * 0xc, scaledY, fVar1, iVar3, (const char *)&gp0xffffa5a8);
    }
    break;
  }
  case 4: {
    s32 scaledY = param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, fVar1, 0, (const char *)&gp0xffffa5b0);
    if (*(int *)(param_4 + 0x1a0) == 0) {
      fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0xa) * 0xc, scaledY, fVar1, iVar3, (const char *)&gp0xffffa588, *(u32 *)(param_4 + 0x1a8));
    }
    else {
      fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0xa) * 0xc, scaledY, fVar1, iVar3, (const char *)&gp0xffffa5a8);
    }
    break;
  }
  case 5: {
    s32 scaledY = param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, fVar1, 0, (const char *)&gp0xffffa5b8);
    if (*(int *)(param_4 + 0x1a0) == 0) {
      fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0xa) * 0xc, scaledY, fVar1, iVar3, (const char *)&gp0xffffa588, *(u32 *)(param_4 + 0x1ac));
    }
    else {
      fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0xa) * 0xc, scaledY, fVar1, iVar3, (const char *)&gp0xffffa5a8);
    }
    break;
  }
  case 6: {
    s32 scaledY = param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, fVar1, 0, (const char *)&gp0xffffa5c8);
    if (*(int *)(param_4 + 0x1a0) == 0) {
      fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0xa) * 0xc, scaledY, fVar1, iVar3, (const char *)&gp0xffffa588, *(u32 *)(param_4 + 0x1b0));
    }
    else {
      fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0xa) * 0xc, scaledY, fVar1, iVar3, (const char *)&gp0xffffa5a8);
    }
    break;
  }
  case 7: {
    s32 scaledY = param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, fVar1, 0, (const char *)&gp0xffffa5d0);
    if (*(int *)(param_4 + 0x1a0) == 0) {
      fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0xa) * 0xc, scaledY, fVar1, iVar3, (const char *)&gp0xffffa588);
    }
    else {
      if (FUN_00397870_i((int)param_4,*(int *)(param_4 + 0x1b4),&local1_3,&local1_2,&local1_1,&local1_0) == 1) {
        fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
        evtMenuDrawText((param_1 + 0xa) * 0xc, scaledY, fVar1, iVar3, (const char *)DAT_0069fbf0, *(u32 *)(param_4 + 0x1b4), local1_3, local1_2, local1_1, local1_0);
      }
      else {
        fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
        evtMenuDrawText((param_1 + 0xa) * 0xc, scaledY, fVar1, iVar3, (const char *)DAT_0069fc10);
      }
    }
    break;
  }
  }
}


// FUN_0037EAD0 NONMATCHING
int FUN_0037ead0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  iVar1 = 0;

  FUN_0036f900(param_1,param_2,0x19,0xb,0,1,param_3,0x37e3f0,0);

  iVar2 = (int)param_3;

  if (*(int *)(iVar2 + 0xd4) != 0x1e) {

    iVar1 = 0;

  }

  else {

    if ((*(u16 *)DAT_007e0952_abs & 0x1000) == 0) {

      if ((*(u16 *)DAT_007e0952_abs & 0x4000) != 0) {

        if (*(int *)(iVar2 + 400) == 7) {

          *(u32 *)(iVar2 + 400) = 0;

        }

        else {

          *(int *)(iVar2 + 400) = *(int *)(iVar2 + 400) + 1;

        }

      }

    }

    else if (*(int *)(iVar2 + 400) == 0) {

      *(u32 *)(iVar2 + 400) = 7;

    }

    else {

      *(int *)(iVar2 + 400) = *(int *)(iVar2 + 400) + -1;

    }

    switch(*(u32 *)(iVar2 + 400)) {

    case 0:

      if ((*(u16 *)DAT_007e0952_abs & 0x2000) != 0) {

        iVar1 = 1;

      }

      else {

        if ((*(u16 *)DAT_007e0952_abs & 0x8000) != 0) {

          iVar1 = -1;

        }

        else {

          if ((*(u16 *)DAT_007e0952_abs & 4) != 0) {

            iVar1 = -10;

          }

          else {

            if ((*(u16 *)DAT_007e0952_abs & 8) != 0) {

              iVar1 = 10;

            }

          }

        }

      }

      iVar1 = *(int *)(iVar2 + 0x198) + iVar1;

      *(int *)(iVar2 + 0x198) = iVar1;

      if (iVar1 >= 0x200) {

        *(u32 *)(iVar2 + 0x198) = 0x200;

      }

      else {

        if (iVar1 < -0x200) {

          *(u32 *)(iVar2 + 0x198) = 0xfffffe00;

        }

      }

      break;

    case 1:

      if ((*(u16 *)DAT_007e0952_abs & 0x2000) != 0) {

        iVar1 = 1;

      }

      else {

        if ((*(u16 *)DAT_007e0952_abs & 0x8000) != 0) {

          iVar1 = -1;

        }

        else {

          if ((*(u16 *)DAT_007e0952_abs & 4) != 0) {

            iVar1 = -10;

          }

          else {

            if ((*(u16 *)DAT_007e0952_abs & 8) != 0) {

              iVar1 = 10;

            }

          }

        }

      }

      iVar1 = *(int *)(iVar2 + 0x19c) + iVar1;

      *(int *)(iVar2 + 0x19c) = iVar1;

      if (iVar1 >= 0x200) {

        *(u32 *)(iVar2 + 0x19c) = 0x200;

      }

      else {

        if (iVar1 < -0x200) {

          *(u32 *)(iVar2 + 0x19c) = 0xfffffe00;

        }

      }

      break;

    case 2:

      if ((DAT_007e0952 & 0x2000) == 0) {

        if ((DAT_007e0952 & 0x8000) != 0) {

          if (*(int *)(iVar2 + 0x1a0) == 0) {

            *(u32 *)(iVar2 + 0x1a0) = 1;

          }

          else {

            *(int *)(iVar2 + 0x1a0) = *(int *)(iVar2 + 0x1a0) + -1;

          }

        }

      }

      else if (*(int *)(iVar2 + 0x1a0) < 1) {

        *(int *)(iVar2 + 0x1a0) = *(int *)(iVar2 + 0x1a0) + 1;

      }

      else {

        *(u32 *)(iVar2 + 0x1a0) = 0;

      }

      if (*(int *)(iVar2 + 0x1a0) == 1) {

        *(u32 *)(iVar2 + 0x1a4) = 0;

        *(u32 *)(iVar2 + 0x1a8) = 0;

        *(u32 *)(iVar2 + 0x1ac) = 0;

        *(u32 *)(iVar2 + 0x1b0) = 0;

      }

      else if (*(int *)(iVar2 + 0x1a0) == 0) {

        *(u32 *)(iVar2 + 0x1b4) = 0;

      }

      break;

    case 3:

      if (*(int *)(iVar2 + 0x1a0) == 0) {

        if ((DAT_007e0952 & 0x2000) != 0) {

          iVar1 = 1;

        }

        else {

          if ((DAT_007e0952 & 0x8000) != 0) {

            iVar1 = -1;

          }

        }

        iVar1 = *(int *)(iVar2 + 0x1a4) + iVar1;

        *(int *)(iVar2 + 0x1a4) = iVar1;

        if (iVar1 >= 0x100) {

          *(u32 *)(iVar2 + 0x1a4) = 0xff;

        }

        else {

          if (iVar1 < 0) {

            *(u32 *)(iVar2 + 0x1a4) = 0;

          }

        }

      }

      break;

    case 4:

      if (*(int *)(iVar2 + 0x1a0) == 0) {

        if ((DAT_007e0952 & 0x2000) != 0) {

          iVar1 = 1;

        }

        else {

          if ((DAT_007e0952 & 0x8000) != 0) {

            iVar1 = -1;

          }

        }

        iVar1 = *(int *)(iVar2 + 0x1a8) + iVar1;

        *(int *)(iVar2 + 0x1a8) = iVar1;

        if (iVar1 >= 0x100) {

          *(u32 *)(iVar2 + 0x1a8) = 0xff;

        }

        else {

          if (iVar1 < 0) {

            *(u32 *)(iVar2 + 0x1a8) = 0;

          }

        }

      }

      break;

    case 5:

      if (*(int *)(iVar2 + 0x1a0) == 0) {

        if ((DAT_007e0952 & 0x2000) != 0) {

          iVar1 = 1;

        }

        else {

          if ((DAT_007e0952 & 0x8000) != 0) {

            iVar1 = -1;

          }

        }

        iVar1 = *(int *)(iVar2 + 0x1ac) + iVar1;

        *(int *)(iVar2 + 0x1ac) = iVar1;

        if (iVar1 >= 0x10) {

          *(u32 *)(iVar2 + 0x1ac) = 0xf;

        }

        else {

          if (iVar1 < 0) {

            *(u32 *)(iVar2 + 0x1ac) = 0;

          }

        }

      }

      break;

    case 6:

      if (*(int *)(iVar2 + 0x1a0) == 0) {

        if ((DAT_007e0952 & 0x2000) != 0) {

          iVar1 = 1;

        }

        else {

          if ((DAT_007e0952 & 0x8000) != 0) {

            iVar1 = -1;

          }

        }

        iVar1 = *(int *)(iVar2 + 0x1b0) + iVar1;

        *(int *)(iVar2 + 0x1b0) = iVar1;

        if (iVar1 >= 0x10) {

          *(u32 *)(iVar2 + 0x1b0) = 0xf;

        }

        else {

          if (iVar1 < 0) {

            *(u32 *)(iVar2 + 0x1b0) = 0;

          }

        }

      }

      break;

    case 7:

      if ((DAT_007e0952 & 0x2000) != 0) {

        iVar1 = 1;

      }

      else {

        if ((DAT_007e0952 & 0x8000) != 0) {

          iVar1 = -1;

        }

      }

      iVar1 = *(int *)(iVar2 + 0x1b4) + iVar1;

      *(int *)(iVar2 + 0x1b4) = iVar1;

      if (iVar1 >= 10) {

        *(u32 *)(iVar2 + 0x1b4) = 9;

      }

      else {

        if (iVar1 < 0) {

          *(u32 *)(iVar2 + 0x1b4) = 0;

        }

      }

    }

    if ((DAT_007e094e & 0x40) == 0) {

      iVar1 = -(u32)((DAT_007e094e & 0x20) != 0);

    }

    else {

      iVar1 = 1;

    }

  }

  return iVar1;

}


// FUN_0037F050


u32 FUN_0037f050(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069fc20_abs);

  return 2;

}


/* opt_lifetimes on: default nd504/780B -> nd503/780B; retained. */
#pragma push
#pragma opt_lifetimes on
// FUN_0037F0C0 NONMATCHING


void FUN_0037f0c0(int param_1,int param_2,int param_3,int param_4)
{
  u32 uVar2;
  f32 uVar3;
  int iVar5;
  u32 uStack_8;
  u32 uStack_c;

  uVar2 = 0;
  uStack_8 = (u32)PTR_s_NORMAL_007cd2d0;
  uStack_c = (u32)PTR_DAT_007cd2d4;
  if (*(int *)(param_4 + 400) == param_3) {
    uVar2 = 4;
  }
  if (param_3 == 2) {
    if (*(int *)(param_4 + 0x198) == 1) {
      uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 9) * 0xc, param_2 * 0xc, uVar3, uVar2, (const char *)0x7cd2e8);
    }
    else if (*(int *)(param_4 + 0x198) == 0) {
      uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 9) * 0xc, param_2 * 0xc, uVar3, uVar2, (const char *)0x69fc40);
    }
  }
  else if (param_3 == 1) {
    iVar5 = param_2 * 0xc;
    uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, iVar5, uVar3, 0, (const char *)0x7cd218);
    if (*(int *)(param_4 + 0x198) == 1) {
      uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 9) * 0xc, iVar5, uVar3, uVar2, (const char *)0x7cd2e0);
    }
    else if ((*(int *)(param_4 + 0x198) == 0) && (*(int *)(param_4 + 0x19c) < 2)) {
      uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 9) * 0xc, iVar5, uVar3, uVar2, (const char *)0x7ccd58, (*(int *)(param_4 + 0x19c) == 0) ? uStack_8 : uStack_c);
    }
  }
  else if (param_3 == 0) {
    iVar5 = param_2 * 0xc;
    uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, iVar5, uVar3, 0, (const char *)0x7cd2d8);
    if (*(int *)(param_4 + 0x198) == 1) {
      uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 9) * 0xc, iVar5, uVar3, uVar2, (const char *)0x69efc8);
    }
    else if (*(int *)(param_4 + 0x198) == 0) {
      uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 9) * 0xc, iVar5, uVar3, uVar2, (const char *)0x69fc30);
    }
  }
  return;
}
#pragma pop


// FUN_0037F3D0 NONMATCHING


int FUN_0037f3d0(int param_1,int param_2,int param_3)



{

  int iVar1;

  

  FUN_0036f900(param_1,param_2,0x14,5,0,1,param_3,0x37f050,0);

  iVar1 = (int)param_3;

  if (*(int *)(iVar1 + 0xd4) != 0x1f) {

    iVar1 = 0;

  }

  else {

    if ((DAT_007e0952 & 0x1000) == 0) {

      if ((DAT_007e0952 & 0x4000) != 0) {

        if (*(int *)(iVar1 + 400) != 2) {

          *(int *)(iVar1 + 400) = *(int *)(iVar1 + 400) + 1;

        }

        else {

          *(u32 *)(iVar1 + 400) = 0;

        }

      }

    }

    else if (*(int *)(iVar1 + 400) == 0) {

      *(u32 *)(iVar1 + 400) = 2;

    }

    else {

      *(int *)(iVar1 + 400) = *(int *)(iVar1 + 400) + -1;

    }

    if (*(int *)(iVar1 + 400) == 1) {

      if ((DAT_007e0952 & 0x2000) == 0) {

        if ((DAT_007e0952 & 0x8000) != 0) {

          if (*(int *)(iVar1 + 0x19c) != 0) {

            *(int *)(iVar1 + 0x19c) = *(int *)(iVar1 + 0x19c) + -1;

          }

          else {

            *(u32 *)(iVar1 + 0x19c) = 1;

          }

        }

      }

      else if (*(int *)(iVar1 + 0x19c) < 1) {

        *(int *)(iVar1 + 0x19c) = *(int *)(iVar1 + 0x19c) + 1;

      }

      else {

        *(u32 *)(iVar1 + 0x19c) = 0;

      }

    }

    else if (*(int *)(iVar1 + 400) == 0) {

      if ((DAT_007e0952 & 0x2000) != 0) {

        if (*(int *)(iVar1 + 0x198) >= 1) {

          *(u32 *)(iVar1 + 0x198) = 0;

        }

        else {

          *(int *)(iVar1 + 0x198) = *(int *)(iVar1 + 0x198) + 1;

        }

        *(u32 *)(iVar1 + 0x19c) = 0;

      }

      else {

        if ((DAT_007e0952 & 0x8000) != 0) {

          if (*(int *)(iVar1 + 0x198) != 0) {

            *(int *)(iVar1 + 0x198) = *(int *)(iVar1 + 0x198) + -1;

          }

          else {

            *(u32 *)(iVar1 + 0x198) = 1;

          }

          *(u32 *)(iVar1 + 0x19c) = 0;

        }

      }

    }

    if ((DAT_007e094e & 0x40) != 0) {

      iVar1 = 1;

    }

    else {

      iVar1 = -(u32)((DAT_007e094e & 0x20) != 0);

    }

  }

  return iVar1;

}


// FUN_0037F5E0


u32 FUN_0037f5e0(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069fc50);

  return 2;

}


// FUN_0037F650


void FUN_0037f650(int param_1,int param_2,u32 param_3,u8 *param_4)
{
  int iVar3;


  f32 fVar1;

  iVar3 = 0;
  if (*(int *)(param_4 + 0x190) == (int)param_3) {
    iVar3 = 4;
  }

  switch (param_3) {
  case 0: {
    s32 scaledY = (int)param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)(param_1 * 0xc), scaledY, fVar1, 0, (const char *)DAT_0069fc68);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)((param_1 + 0xd) * 0xc), scaledY, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x198));
    break;
  }
  case 1: {
    s32 scaledY = (int)param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)(param_1 * 0xc), scaledY, fVar1, 0, (const char *)DAT_0069fc78);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)((param_1 + 0xd) * 0xc), scaledY, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x19c));
    break;
  }
  case 2: {
    s32 scaledY = (int)param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)(param_1 * 0xc), scaledY, fVar1, 0, (const char *)DAT_0069fc88);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)((param_1 + 0xd) * 0xc), scaledY, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1a0));
    break;
  }
  case 3: {
    s32 scaledY = (int)param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)(param_1 * 0xc), scaledY, fVar1, 0, (const char *)DAT_0069fc98);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)((param_1 + 0xd) * 0xc), scaledY, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1a4));
    break;
  }
  case 4: {
    s32 scaledY = ((int)param_2 + 1) * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)(param_1 * 0xc), scaledY, fVar1, 0, (const char *)DAT_0069fca8);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)((param_1 + 0xd) * 0xc), scaledY, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1a8));
    break;
  }
  case 5: {
    s32 scaledY = ((int)param_2 + 1) * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)(param_1 * 0xc), scaledY, fVar1, 0, (const char *)DAT_0069fcb8);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)((param_1 + 0xd) * 0xc), scaledY, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1ac));
    break;
  }
  case 6: {
    s32 scaledY = ((int)param_2 + 1) * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)(param_1 * 0xc), scaledY, fVar1, 0, (const char *)DAT_0069fcc8);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)((param_1 + 0xd) * 0xc), scaledY, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1b0));
    break;
  }
  case 7: {
    s32 scaledY = ((int)param_2 + 1) * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)(param_1 * 0xc), scaledY, fVar1, 0, (const char *)DAT_0069fcd8);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)((param_1 + 0xd) * 0xc), scaledY, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1b4));
    break;
  }
  }
}


// FUN_0037FAE0 NONMATCHING


int FUN_0037fae0(u64 param_1,u64 param_2,u64 param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = 0;

  iVar2 = 0;

  FUN_0036f900(param_1,param_2,0x17,0xc,0,1,param_3,0x37f5e0,0);

  iVar4 = (int)param_3;

  if (*(int *)(iVar4 + 0xd4) != 0x20) {

    iVar2 = 0;

  }

  else {

    if ((DAT_007e0952 & 0x1000) == 0) {

      if ((DAT_007e0952 & 0x4000) != 0) {

        if (*(int *)(iVar4 + 400) == 7) {

          *(u32 *)(iVar4 + 400) = 0;

        }

        else {

          *(int *)(iVar4 + 400) = *(int *)(iVar4 + 400) + 1;

        }

      }

    }

    else if (*(int *)(iVar4 + 400) == 0) {

      *(u32 *)(iVar4 + 400) = 7;

    }

    else {

      *(int *)(iVar4 + 400) = *(int *)(iVar4 + 400) + -1;

    }

    iVar1 = *(int *)(iVar4 + 400);

    switch(iVar1) {

    case 0:

    case 1:

    case 2:

    case 3:

      if ((DAT_007e0952 & 0x2000) != 0) {

        iVar3 = 1;

      }

      else {

        if ((DAT_007e0952 & 8) != 0) {

          iVar3 = 10;

        }

        else {

          if ((DAT_007e0952 & 2) != 0) {

            iVar3 = 100;

          }

          else {

            if ((DAT_007e0952 & 0x8000) != 0) {

              iVar3 = -1;

            }

            else {

              if ((DAT_007e0952 & 4) != 0) {

                iVar3 = -10;

              }

              else {

                if ((DAT_007e0952 & 1) != 0) {

                  iVar3 = -100;

                }

              }

            }

          }

        }

      }

      if (iVar1 == 3) {

        iVar2 = *(int *)(iVar4 + 0x1a4);

      }

      else if (iVar1 == 2) {

        iVar2 = *(int *)(iVar4 + 0x1a0);

      }

      else if (iVar1 == 1) {

        iVar2 = *(int *)(iVar4 + 0x19c);

      }

      else if (iVar1 == 0) {

        iVar2 = *(int *)(iVar4 + 0x198);

      }

      iVar2 = iVar2 + iVar3;

      if (100 < iVar2) {

        iVar2 = 100;

      }

      if (iVar2 < 0) {

        iVar2 = 0;

      }

      if (iVar1 == 3) {

        *(int *)(iVar4 + 0x1a4) = iVar2;

      }

      else if (iVar1 == 2) {

        *(int *)(iVar4 + 0x1a0) = iVar2;

      }

      else if (iVar1 == 1) {

        *(int *)(iVar4 + 0x19c) = iVar2;

      }

      else if (iVar1 == 0) {

        *(int *)(iVar4 + 0x198) = iVar2;

      }

      break;

    case 4:

    case 5:

    case 6:

    case 7:

      if ((DAT_007e0952 & 0x2000) != 0) {

        iVar3 = 1;

      }

      else {

        if ((DAT_007e0952 & 8) != 0) {

          iVar3 = 10;

        }

        else {

          if ((DAT_007e0952 & 2) != 0) {

            iVar3 = 100;

          }

          else {

            if ((DAT_007e0952 & 0x8000) != 0) {

              iVar3 = -1;

            }

            else {

              if ((DAT_007e0952 & 4) != 0) {

                iVar3 = -10;

              }

              else {

                if ((DAT_007e0952 & 1) != 0) {

                  iVar3 = -100;

                }

              }

            }

          }

        }

      }

      if (iVar1 == 7) {

        iVar2 = *(int *)(iVar4 + 0x1b4);

      }

      else if (iVar1 == 6) {

        iVar2 = *(int *)(iVar4 + 0x1b0);

      }

      else if (iVar1 == 5) {

        iVar2 = *(int *)(iVar4 + 0x1ac);

      }

      else if (iVar1 == 4) {

        iVar2 = *(int *)(iVar4 + 0x1a8);

      }

      iVar2 = iVar2 + iVar3;

      if (30000 < iVar2) {

        iVar2 = 30000;

      }

      if (iVar2 < 0) {

        iVar2 = 0;

      }

      if (iVar1 == 7) {

        *(int *)(iVar4 + 0x1b4) = iVar2;

      }

      else if (iVar1 == 6) {

        *(int *)(iVar4 + 0x1b0) = iVar2;

      }

      else if (iVar1 == 5) {

        *(int *)(iVar4 + 0x1ac) = iVar2;

      }

      else if (iVar1 == 4) {

        *(int *)(iVar4 + 0x1a8) = iVar2;

      }

    }

    if ((DAT_007e094e & 0x40) == 0) {

      iVar2 = -(u32)((DAT_007e094e & 0x20) != 0);

    }

    else {

      iVar2 = 1;

    }

  }

  return iVar2;

}


// FUN_0037FF10


u32 FUN_0037ff10(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069fcf0_abs);

  return 2;

}


// FUN_0037FF80


void FUN_0037ff80(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  u32 uVar2;
  int iVar3;
  f32 uVar4;
  int y;

  uVar2 = 0;
  iVar1 = FUN_00361830(param_4);
  iVar3 = (int)param_4;
  if (*(int *)(iVar3 + 400) == param_3) {
    uVar2 = 4;
  }
  switch (param_3) {
  case 0:
    y = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, y, uVar4, 0, (const char *)DAT_0069fd08_abs);
    switch (*(char *)(iVar1 + 0x10)) {
    case 0:
    case 5:
      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
      evtMenuDrawText((param_1 + 0x10) * 0xc, y, uVar4, uVar2,
                      (const char *)DAT_0069fd18_abs);
      break;
    default:
      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
      evtMenuDrawText((param_1 + 0x10) * 0xc, y, uVar4, uVar2,
                      (const char *)&gp0xffffa330);
      break;
    }
    break;
  case 1:
    y = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, y, uVar4, 0,
                    (const char *)DAT_0069fd30_abs);
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText((param_1 + 0x10) * 0xc, y, uVar4, uVar2,
                    (const char *)&gp0xffffa3b8, *(u32 *)(iVar3 + 0x198) & 0x3ff);
    break;
  case 2:
    y = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, y, uVar4, 0,
                    (const char *)&gp0xffffa600);
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText((param_1 + 0x10) * 0xc, y, uVar4, uVar2,
                    (const char *)DAT_0069fd48_abs);
    break;
  }
}


// FUN_00380200


int FUN_00380200(int param_1,int param_2,int param_3)



{

  typedef struct {
    u8 pad0[0xd4];
    int state;
    u8 padD8[0xb8];
    int selection;
  } EvtMenuSelectionState;
  int result;
  EvtMenuSelectionState *menu;

  

  FUN_0036f900_evt(param_1,param_2,0x17,6,0,1,param_3,(code *)FUN_0037ff10,
                   (code *)FUN_0037ff80);

  menu = (EvtMenuSelectionState *)param_3;

  if (menu->state != 0x21) {

    result = 0;

  }

  else {

    if ((*(u16 *)DAT_007e0952_abs & 0x1000) != 0) {
      if (menu->selection == 0) {
        menu->selection = 2;
      }
      else {
        menu->selection = menu->selection - 1;
      }
    }
    else if ((*(u16 *)DAT_007e0952_abs & 0x4000) != 0) {
      if (menu->selection == 2) {
        menu->selection = 0;
      }
      else {
        menu->selection = menu->selection + 1;
      }
    }

    if ((*(u16 *)DAT_007e094e_abs & 0x40) != 0) {

      result = 1;

    }

    else {

      result = -(u32)((*(u16 *)DAT_007e094e_abs & 0x20) != 0);

    }

  }

  return result;

}


// FUN_00380310


u32 FUN_00380310(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069fd60_abs);
  return 2;

}
// FUN_00380380


void FUN_00380380(int param_1,int param_2,u32 param_3,u8 *param_4)
{
  int iVar3;
  f32 fVar1;

  iVar3 = 0;
  if (*(int *)(param_4 + 0x190) == (int)param_3) {
    iVar3 = 4;
  }

  switch (param_3) {
  case 0: {
    int iVar2;
    iVar2 = param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, iVar2, fVar1, 0, (const char *)&gp0xffffa608);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0x10) * 0xc, iVar2, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x198));
    break;
  }
  case 1: {
    int iVar2;
    iVar2 = param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, iVar2, fVar1, 0, (const char *)DAT_0069fd78);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0x10) * 0xc, iVar2, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x19c));
    break;
  }
  case 2: {
    int iVar2;
    iVar2 = param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, iVar2, fVar1, 0, (const char *)&gp0xffffa610);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0x10) * 0xc, iVar2, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1a0));
    break;
  }
  case 3: {
    int iVar2;
    iVar2 = param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, iVar2, fVar1, 0, (const char *)&gp0xffffa618);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0x10) * 0xc, iVar2, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1a4));
    break;
  }
  case 4: {
    int iVar2;
    iVar2 = param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, iVar2, fVar1, 0, (const char *)DAT_0069fd88);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0x10) * 0xc, iVar2, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1a8));
    break;
  }
  case 5: {
    int iVar2;
    iVar2 = param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, iVar2, fVar1, 0, (const char *)DAT_0069fd98);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0x10) * 0xc, iVar2, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1ac));
    break;
  }
  }
}

// FUN_003806F0 NONMATCHING


int FUN_003806f0(int param_1,int param_2,int param_3)



{

  u32 uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = 0;

  iVar2 = 0;

  FUN_0036f900(param_1,param_2,0x17,10,0,1,param_3,0x380310,0);

  iVar4 = (int)param_3;

  if (*(int *)(iVar4 + 0xd4) == 0x22) {

    if ((DAT_007e0952 & 0x1000) == 0) {

      if ((DAT_007e0952 & 0x4000) != 0) {

        if (*(int *)(iVar4 + 400) == 5) {

          *(u32 *)(iVar4 + 400) = 0;

        }

        else {

          *(int *)(iVar4 + 400) = *(int *)(iVar4 + 400) + 1;

        }

      }

    }

    else if (*(int *)(iVar4 + 400) == 0) {

      *(u32 *)(iVar4 + 400) = 5;

    }

    else {

      *(int *)(iVar4 + 400) = *(int *)(iVar4 + 400) + -1;

    }

    uVar1 = *(u32 *)(iVar4 + 400);

    switch(uVar1) {

    case 0:

    case 1:

    case 2:

    case 3:

    case 4:

    case 5:

      if ((DAT_007e0952 & 0x2000) == 0) {

        if ((DAT_007e0952 & 8) == 0) {

          if ((DAT_007e0952 & 2) == 0) {

            if ((DAT_007e0952 & 0x8000) == 0) {

              if ((DAT_007e0952 & 4) == 0) {

                if ((DAT_007e0952 & 1) != 0) {

                  iVar3 = -100;

                }

              }

              else {

                iVar3 = -10;

              }

            }

            else {

              iVar3 = -1;

            }

          }

          else {

            iVar3 = 100;

          }

        }

        else {

          iVar3 = 10;

        }

      }

      else {

        iVar3 = 1;

      }

      switch(uVar1) {

      case 0:

        iVar2 = *(int *)(iVar4 + 0x198);

        break;

      case 1:

        iVar2 = *(int *)(iVar4 + 0x19c);

        break;

      case 2:

        iVar2 = *(int *)(iVar4 + 0x1a0);

        break;

      case 3:

        iVar2 = *(int *)(iVar4 + 0x1a4);

        break;

      case 4:

        iVar2 = *(int *)(iVar4 + 0x1a8);

        break;

      case 5:

        iVar2 = *(int *)(iVar4 + 0x1ac);

      }

      iVar2 = iVar2 + iVar3;

      if (30000 < iVar2) {

        iVar2 = 30000;

      }

      if (iVar2 < 0) {

        iVar2 = 0;

      }

      switch(uVar1) {

      case 0:

        *(int *)(iVar4 + 0x198) = iVar2;

        break;

      case 1:

        *(int *)(iVar4 + 0x19c) = iVar2;

        break;

      case 2:

        *(int *)(iVar4 + 0x1a0) = iVar2;

        break;

      case 3:

        *(int *)(iVar4 + 0x1a4) = iVar2;

        break;

      case 4:

        *(int *)(iVar4 + 0x1a8) = iVar2;

        break;

      case 5:

        *(int *)(iVar4 + 0x1ac) = iVar2;

      }

    }

    if ((DAT_007e094e & 0x40) == 0) {

      iVar2 = -(u32)((DAT_007e094e & 0x20) != 0);

    }

    else {

      iVar2 = 1;

    }

  }

  else {

    iVar2 = 0;

  }

  return iVar2;

}


// FUN_003809C0


u32 FUN_003809c0(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069fdb0_abs);

  return 2;

}


// FUN_00380A30


void FUN_00380a30(int param_1,int param_2,int param_3,int param_4)



{

  int iVar1;

  u32 uVar2;

  f32 uVar3;

  RwV2d auStack_8;

  

  uVar2 = 0;

  auStack_8 = *(RwV2d *)&uGpffffa628;

  if (*(int *)(param_4 + 400) == param_3) {

    uVar2 = 4;

  }

  switch (param_3) {
  case 0: {
    s32 scaledY = param_2 * 0xc;
    uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar3, 0, (const char *)&gp0xffffa630);
    iVar1 = *(int *)(param_4 + 0x198);
    if (iVar1 < 2) {
      uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0x10) * 0xc, scaledY, uVar3, uVar2, (const char *)&gp0xffffa068, ((u32 *)&auStack_8)[iVar1]);
    }
    break;
  }
  case 1: {
    s32 scaledY = param_2 * 0xc;
    uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar3, 0, (const char *)&gp0xffffa638);
    uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0x10) * 0xc, scaledY, uVar3, uVar2, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x19c));
    break;
  }
  case 2: {
    s32 scaledY = param_2 * 0xc;
    uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar3, 0, (const char *)(DAT_006a0000_abs - 0x238));
    if (*(int *)(param_4 + 0x198) == 0) {
      uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0x10) * 0xc, scaledY, uVar3, uVar2, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1a0));
    } else {
      uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0x10) * 0xc, scaledY, uVar3, uVar2, (const char *)&gp0xffffa640);
    }
    break;
  }
  case 3: {
    s32 scaledY = param_2 * 0xc;
    uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar3, 0, (const char *)(DAT_006a0000_abs - 0x228));
    if (*(int *)(param_4 + 0x198) == 0) {
      uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0x10) * 0xc, scaledY, uVar3, uVar2, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1a4));
    } else {
      uVar3 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0x10) * 0xc, scaledY, uVar3, uVar2, (const char *)&gp0xffffa640);
    }
    break;
  }
  }

  return;

}


// FUN_00380D70 NONMATCHING


int FUN_00380d70(int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar2 = 0;
  FUN_0036f900_evt(param_1,param_2,0x17,7,0,1,param_3,(code *)FUN_003809c0,
                   (code *)FUN_00380a30);
  iVar3 = (int)param_3;
  switch (*(int *)(iVar3 + 0xd4)) {
  case 0x23:
    if ((*(u16 *)DAT_007e0952_abs & 0x1000) != 0) {
      if (*(int *)(iVar3 + 400) == 0) {
        *(u32 *)(iVar3 + 400) = 3;
      } else {
        *(int *)(iVar3 + 400) = *(int *)(iVar3 + 400) + -1;
      }
    } else if ((*(u16 *)DAT_007e0952_abs & 0x4000) != 0) {
      if (*(int *)(iVar3 + 400) == 3) {
        *(u32 *)(iVar3 + 400) = 0;
      } else {
        *(int *)(iVar3 + 400) = *(int *)(iVar3 + 400) + 1;
      }
    }

    iVar1 = *(int *)(iVar3 + 400);
    switch (iVar1) {
    case 0:
      if ((DAT_007e0952 & 0x8000) != 0 || (DAT_007e0952 & 0x2000) != 0) {
        *(u32 *)(iVar3 + 0x198) = (u32)(*(int *)(iVar3 + 0x198) == 0);
        *(u32 *)(iVar3 + 0x1a4) = 0;
        *(u32 *)(iVar3 + 0x1a0) = 0;
        *(u32 *)(iVar3 + 0x19c) = 0;
      }
      break;
    case 1:
      if ((*(u16 *)DAT_007e0952_abs & 0x2000) == 0) {
        if ((*(u16 *)DAT_007e0952_abs & 0x8000) != 0) {
          iVar2 = -1;
        }
      } else {
        iVar2 = 1;
      }
      iVar2 = *(int *)(iVar3 + 0x19c) + iVar2;
      if (2 < iVar2) {
        iVar2 = 2;
      }
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      *(int *)(iVar3 + 0x19c) = iVar2;
      break;
    case 2:
      if (*(int *)(iVar3 + 0x198) != 1) {
        if ((*(u16 *)DAT_007e0952_abs & 0x2000) == 0) {
          if ((*(u16 *)DAT_007e0952_abs & 0x8000) != 0) {
            iVar2 = -1;
          }
        } else {
          iVar2 = 1;
        }
        iVar2 = *(int *)(iVar3 + 0x1a0) + iVar2;
        if (9 < iVar2) {
          iVar2 = 9;
        }
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        *(int *)(iVar3 + 0x1a0) = iVar2;
      }
      break;
    case 3:
      if (*(int *)(iVar3 + 0x198) != 1) {
        if ((*(u16 *)DAT_007e0952_abs & 0x2000) == 0) {
          if ((*(u16 *)DAT_007e0952_abs & 8) == 0) {
            if ((*(u16 *)DAT_007e0952_abs & 2) == 0) {
              if ((*(u16 *)DAT_007e0952_abs & 0x8000) == 0) {
                if ((*(u16 *)DAT_007e0952_abs & 4) == 0) {
                  if ((*(u16 *)DAT_007e0952_abs & 1) != 0) {
                    iVar2 = -100;
                  }
                } else {
                  iVar2 = -10;
                }
              } else {
                iVar2 = -1;
              }
            } else {
              iVar2 = 100;
            }
          } else {
            iVar2 = 10;
          }
        } else {
          iVar2 = 1;
        }
        iVar2 = *(int *)(iVar3 + 0x1a4) + iVar2;
        if (0xffff < iVar2) {
          iVar2 = 0xffff;
        }
        if (iVar2 < 0) {
          iVar2 = 0;
        }
        *(int *)(iVar3 + 0x1a4) = iVar2;
      }
      break;
    }

    if ((DAT_007e094e & 0x40) == 0) {
      iVar2 = -(u32)((DAT_007e094e & 0x20) != 0);
    } else {
      iVar2 = 1;
    }
    break;
  default:
    iVar2 = 0;
    break;
  }
  return iVar2;
}


// FUN_003810A0


u32 FUN_003810a0(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069fdf0_abs);

  return 2;

}


// FUN_00381110


void FUN_00381110(int param_1,int param_2,int param_3,int param_4)



{

  int iVar1;
  int iVar2;
  f32 uVar2;


  iVar1 = 0;
  if (*(int *)(param_4 + 400) == param_3) {
    iVar1 = 4;
  }

  switch (param_3) {
  case 0:
    goto FUN_00381110_case0;
  case 1:
    goto FUN_00381110_case1;
  default:
    goto FUN_00381110_done;
  }

FUN_00381110_case0:
  iVar2 = param_2 * 0xc;
  uVar2 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
  evtMenuDrawText(param_1 * 0xc, iVar2, uVar2, 0, (const char *)(void *)DAT_0069fe10_abs);

  uVar2 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
  evtMenuDrawText((param_1 + 0x18) * 0xc, iVar2, uVar2, iVar1, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x198));
  goto FUN_00381110_done;

FUN_00381110_case1:
  iVar2 = param_2 * 0xc;
  uVar2 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
  evtMenuDrawText(param_1 * 0xc, iVar2, uVar2, 0, (const char *)(void *)&gp0xffffa648);

  uVar2 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
  evtMenuDrawText((param_1 + 0x18) * 0xc, iVar2, uVar2, iVar1, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x19c));

FUN_00381110_done:

  return;

}


// FUN_00381280 NONMATCHING


int FUN_00381280(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  

  iVar3 = 0;

  iVar2 = 0;

  FUN_0036f900(param_1,param_2,0x1d,7,0,1,param_3,0x3810a0,0);

  iVar4 = (int)param_3;

  if (*(int *)(iVar4 + 0xd4) == 0x24) {

    if ((DAT_007e0952 & 0x1000) == 0) {

      if ((DAT_007e0952 & 0x4000) != 0) {

        if (*(int *)(iVar4 + 400) == 1) {

          *(u32 *)(iVar4 + 400) = 0;

        }

        else {

          *(int *)(iVar4 + 400) = *(int *)(iVar4 + 400) + 1;

        }

      }

    }

    else if (*(int *)(iVar4 + 400) == 0) {

      *(u32 *)(iVar4 + 400) = 1;

    }

    else {

      *(int *)(iVar4 + 400) = *(int *)(iVar4 + 400) + -1;

    }

    iVar1 = *(int *)(iVar4 + 400);

    switch (iVar1) {
    case 0:
    case 1:

      if ((DAT_007e0952 & 0x2000) == 0) {

        if ((DAT_007e0952 & 8) == 0) {

          if ((DAT_007e0952 & 2) == 0) {

            if ((DAT_007e0952 & 0x8000) == 0) {

              if ((DAT_007e0952 & 4) == 0) {

                if ((DAT_007e0952 & 1) != 0) {

                  iVar3 = -100;

                }

              }

              else {

                iVar3 = -10;

              }

            }

            else {

              iVar3 = -1;

            }

          }

          else {

            iVar3 = 100;

          }

        }

        else {

          iVar3 = 10;

        }

      }

      else {

        iVar3 = 1;

      }

      if (iVar1 == 1) {

        iVar2 = *(int *)(iVar4 + 0x19c);

      }

      else if (iVar1 == 0) {

        iVar2 = *(int *)(iVar4 + 0x198);

      }

      iVar2 = iVar2 + iVar3;

      if (30000 < iVar2) {

        iVar2 = 30000;

      }

      if (iVar2 < 0) {

        iVar2 = 0;

      }

      if (iVar1 == 1) {

        *(int *)(iVar4 + 0x19c) = iVar2;

      }

      else if (iVar1 == 0) {

        *(int *)(iVar4 + 0x198) = iVar2;

      }

      break;
    }

    if ((DAT_007e094e & 0x40) == 0) {

      iVar2 = -(u32)((DAT_007e094e & 0x20) != 0);

    }

    else {

      iVar2 = 1;

    }

  }

  else {

    iVar2 = 0;

  }

  return iVar2;

}


// FUN_003814D0


u32 FUN_003814d0(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069fe30_abs);

  return 2;

}


/* opt_lifetimes on: default nd762/1124B -> nd761/1124B; retained. */
#pragma push
#pragma opt_lifetimes on
// FUN_00381540 NONMATCHING
void FUN_00381540(int param_1,int param_2,u32 param_3,u8 *param_4)
{
  u8 *puVar1;
  u8 *puVar2;
  int iVar3;
  u8 **puVar4;
  u8 **ppuVar5;
  u8 *auStack_30[8];
  f32 uStack_8;
  f32 uStack_4;
  int iVar6;
  u32 uVar7;
  f32 fVar8;

  uStack_8 = gp0xffffa650_f32;
  uStack_4 = gp0xffffa654_f32;
  ppuVar5 = PTR_s_GAKURYOKU_0069feb0_abs;
  puVar4 = auStack_30;
  iVar3 = 4;
  do {
    puVar1 = *ppuVar5;
    puVar2 = ppuVar5[1];
    ppuVar5 = ppuVar5 + 2;
    iVar3 = iVar3 - 1;
    *puVar4 = puVar1;
    puVar4[1] = puVar2;
    puVar4 = puVar4 + 2;
  } while (0 < iVar3);
  iVar6 = 0;
  if (*(int *)(param_4 + 0x190) == (int)param_3) {
    iVar6 = 4;
  }
  switch (param_3) {
  case 0: {
    s32 scaledY = param_2 * 0xc;
    fVar8 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, 0, fVar8, 0, (const char *)&gp0xffffa570);
    uVar7 = *(u32 *)(param_4 + 0x198);
    if (uVar7 < 2) {
      fVar8 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0xc) * 0xc, scaledY, fVar8, iVar6, (const char *)&gp0xffffa068, ((u32 *)&uStack_8)[uVar7]);
    }
    break;
  }
  case 1: {
    s32 scaledY = param_2 * 0xc;
    fVar8 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, 0, fVar8, 0, (const char *)&gp0xffffa000);
    uVar7 = *(u32 *)(param_4 + 0x19c);
    if (uVar7 < 8) {
      fVar8 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
      evtMenuDrawText((param_1 + 0xc) * 0xc, scaledY, fVar8, iVar6, (const char *)&gp0xffffa068, (u32)auStack_30[uVar7]);
    }
    break;
  }
  case 2:
    iVar3 = param_2 * 0xc;
    fVar8 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, 0, fVar8, 0, (const char *)(void *)0x69fed0);
    fVar8 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0xc) * 0xc, iVar3, fVar8, iVar6, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1a0));
    break;
  case 3:
    iVar3 = param_2 * 0xc;
    fVar8 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, 0, fVar8, 0, (const char *)(void *)0x69fee0);
    fVar8 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0xc) * 0xc, iVar3, fVar8, iVar6, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1a4));
    break;
  case 4:
    iVar3 = param_2 * 0xc;
    fVar8 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, 0, fVar8, 0, (const char *)(void *)0x69fef0);
    fVar8 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0xc) * 0xc, iVar3, fVar8, iVar6, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1a8));
    break;
  case 5:
    iVar3 = param_2 * 0xc;
    fVar8 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, 0, fVar8, 0, (const char *)(void *)0x69ff00);
    fVar8 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0xc) * 0xc, iVar3, fVar8, iVar6, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1ac));
    break;
  case 6:
    iVar3 = param_2 * 0xc;
    fVar8 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, 0, fVar8, 0, (const char *)&gp0xffffa028);
    uVar7 = *(u32 *)(param_4 + 0x1b0) & 0x3ff;
    fVar8 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0xc) * 0xc, iVar3, fVar8, iVar6, (const char *)&gp0xffffa068, uVar7);
    break;
  }
}
#pragma pop


// FUN_003819B0 NONMATCHING


int FUN_003819b0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  iVar2 = 0;

  FUN_0036f900(param_1,param_2,0x19,9,0,1,param_3,0x3814d0,0);

  iVar1 = (int)param_3;

  if (*(int *)(iVar1 + 0xd4) != 0x25) {

    iVar2 = 0;

  }

  else {

    if ((DAT_007e0952 & 0x1000) == 0) {

      if ((DAT_007e0952 & 0x4000) != 0) {

        if (*(int *)(iVar1 + 400) == 6) {

          *(u32 *)(iVar1 + 400) = 0;

        }

        else {

          *(int *)(iVar1 + 400) = *(int *)(iVar1 + 400) + 1;

        }

      }

    }

    else if (*(int *)(iVar1 + 400) == 0) {

      *(u32 *)(iVar1 + 400) = 6;

    }

    else {

      *(int *)(iVar1 + 400) = *(int *)(iVar1 + 400) + -1;

    }

    switch(*(int *)(iVar1 + 400)) {

    case 0:

      if (((DAT_007e0952 & 0x2000) != 0) || ((DAT_007e0952 & 0x8000) != 0)) {

        *(u32 *)(iVar1 + 0x198) = (u32)(*(int *)(iVar1 + 0x198) == 0);

      }

      break;

    case 1:

      if ((DAT_007e0952 & 0x2000) != 0) {

        iVar2 = 1;

      }

      else {

        if ((DAT_007e0952 & 0x8000) != 0) {

          iVar2 = -1;

        }

      }

      iVar2 = *(int *)(iVar1 + 0x19c) + iVar2;

      if (7 < iVar2) {

        iVar2 = 0;

      }

      if (iVar2 < 0) {

        iVar2 = 7;

      }

      *(int *)(iVar1 + 0x19c) = iVar2;

      break;

    case 2:

    case 3:

    case 4:

    case 5:

      if ((DAT_007e0952 & 0x2000) != 0) {

        iVar2 = 1;

      }

      else {

        if ((DAT_007e0952 & 0x8000) != 0) {

          iVar2 = -1;

        }

      }

      iVar1 = *(int *)(iVar1 + 400) * 4 + iVar1;

      iVar2 = *(int *)(iVar1 + 0x198) + iVar2;

      if (0x14 < iVar2) {

        iVar2 = 0x14;

      }

      if (iVar2 < 0) {

        iVar2 = 0;

      }

      *(int *)(iVar1 + 0x198) = iVar2;

    }

    if ((DAT_007e094e & 0x40) == 0) {

      iVar2 = -(u32)((DAT_007e094e & 0x20) != 0);

    }

    else {

      iVar2 = 1;

    }

  }

  return iVar2;

}


// FUN_00381BF0


u32 FUN_00381bf0(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069ff10);

  return 2;

}


// FUN_00381C60


void FUN_00381c60(int param_1,int param_2,u32 param_3,u8 *param_4)
{
  int iVar3;
  f32 fVar1;

  iVar3 = 0;
  if (*(int *)(param_4 + 0x190) == (int)param_3) {
    iVar3 = 4;
  }

  switch (param_3) {
  case 0: {
    s32 scaledY = param_2 * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)(param_1 * 0xc), scaledY, fVar1, 0, (const char *)DAT_0069ff20);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)((param_1 + 0x10) * 0xc), scaledY, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x198));
    break;
  }
  case 1: {
    s32 scaledY = (param_2 + 1) * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)(param_1 * 0xc), scaledY, fVar1, 0, (const char *)DAT_0069ff30);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)((param_1 + 0x10) * 0xc), scaledY, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x19c));
    break;
  }
  case 2: {
    s32 scaledY = (param_2 + 1) * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)(param_1 * 0xc), scaledY, fVar1, 0, (const char *)DAT_0069ff40);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)((param_1 + 0x10) * 0xc), scaledY, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1a0));
    break;
  }
  case 3: {
    s32 scaledY = (param_2 + 1) * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)(param_1 * 0xc), scaledY, fVar1, 0, (const char *)DAT_0069ff50);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)((param_1 + 0x10) * 0xc), scaledY, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1a4));
    break;
  }
  case 4: {
    s32 scaledY = (param_2 + 2) * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)(param_1 * 0xc), scaledY, fVar1, 0, (const char *)&gp0xffffa668);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)((param_1 + 0x10) * 0xc), scaledY, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1a8));
    break;
  }
  case 5: {
    s32 scaledY = (param_2 + 2) * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)(param_1 * 0xc), scaledY, fVar1, 0, (const char *)&gp0xffffa670);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)((param_1 + 0x10) * 0xc), scaledY, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1ac));
    break;
  }
  case 6: {
    s32 scaledY = (param_2 + 2) * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)(param_1 * 0xc), scaledY, fVar1, 0, (const char *)&gp0xffffa678);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)((param_1 + 0x10) * 0xc), scaledY, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1b0));
    break;
  }
  case 7: {
    s32 scaledY = (param_2 + 2) * 0xc;
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)(param_1 * 0xc), scaledY, fVar1, 0, (const char *)&gp0xffffa680);
    fVar1 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((u32)((param_1 + 0x10) * 0xc), scaledY, fVar1, iVar3, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x1b4));
    break;
  }
  }
}


// FUN_003820E0 NONMATCHING


int FUN_003820e0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = 0;

  iVar3 = 0;

  FUN_0036f900(param_1,param_2,0x19,0xd,0,1,param_3,0x381bf0,0);

  iVar1 = (int)param_3;

  if (*(int *)(iVar1 + 0xd4) == 0x26) {

    if ((DAT_007e0952 & 0x1000) == 0) {

      if ((DAT_007e0952 & 0x4000) != 0) {

        if (*(int *)(iVar1 + 400) == 7) {

          *(u32 *)(iVar1 + 400) = 0;

        }

        else {

          *(int *)(iVar1 + 400) = *(int *)(iVar1 + 400) + 1;

        }

      }

    }

    else if (*(int *)(iVar1 + 400) == 0) {

      *(u32 *)(iVar1 + 400) = 7;

    }

    else {

      *(int *)(iVar1 + 400) = *(int *)(iVar1 + 400) + -1;

    }

    if ((DAT_007e0952 & 0x2000) == 0) {

      if ((DAT_007e0952 & 8) == 0) {

        if ((DAT_007e0952 & 2) == 0) {

          if ((DAT_007e0952 & 0x8000) == 0) {

            if ((DAT_007e0952 & 4) == 0) {

              if ((DAT_007e0952 & 1) != 0) {

                iVar2 = -100;

              }

            }

            else {

              iVar2 = -10;

            }

          }

          else {

            iVar2 = -1;

          }

        }

        else {

          iVar2 = 100;

        }

      }

      else {

        iVar2 = 10;

      }

    }

    else {

      iVar2 = 1;

    }

    if (iVar2 != 0) {

      switch(*(int *)(iVar1 + 400)) {

      case 0:

        iVar3 = 8;

        break;

      case 1:

      case 2:

      case 3:

        iVar3 = 0xfa;

        break;

      case 4:

      case 5:

      case 6:

      case 7:

        iVar3 = 60000;

      }

      iVar1 = *(int *)(iVar1 + 400) * 4 + iVar1;

      iVar2 = *(int *)(iVar1 + 0x198) + iVar2;

      if (iVar3 < iVar2) {

        iVar2 = iVar3;

      }

      if (iVar2 < 0) {

        iVar2 = 0;

      }

      *(int *)(iVar1 + 0x198) = iVar2;

    }

    if ((DAT_007e094e & 0x40) == 0) {

      iVar2 = -(u32)((DAT_007e094e & 0x20) != 0);

    }

    else {

      iVar2 = 1;

    }

  }

  else {

    iVar2 = 0;

  }

  return iVar2;

}


// FUN_00382320


u32 FUN_00382320(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069ff60_abs);

  return 2;

}


// FUN_00382390


void FUN_00382390(int param_1,int param_2,int param_3,int param_4)
{
  int uVar1;
  f32 uVar2;
  int iVar2;

  uVar1 = 0;
  if (*(int *)(param_4 + 400) == param_3) {
    uVar1 = 4;
  }

  switch (param_3) {
  case 0:
    goto FUN_00382390_case0;
  case 1:
    goto FUN_00382390_case1;
  default:
    goto FUN_00382390_done;
  }

FUN_00382390_case0:
  iVar2 = param_2 * 0xc;
  uVar2 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
  evtMenuDrawText(param_1 * 0xc, iVar2, uVar2, 0, (const char *)DAT_0069ff80_abs);

  uVar2 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
  evtMenuDrawText((param_1 + 0x1a) * 0xc, iVar2, uVar2, uVar1, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x198));
  goto FUN_00382390_done;

FUN_00382390_case1:
  iVar2 = param_2 * 0xc;
  uVar2 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
  evtMenuDrawText(param_1 * 0xc, iVar2, uVar2, 0, (const char *)DAT_0069ffa0_abs);

  uVar2 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
  evtMenuDrawText((param_1 + 0x1a) * 0xc, iVar2, uVar2, uVar1, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x19c));

FUN_00382390_done:
  return;
}


// FUN_00382500 NONMATCHING


int FUN_00382500(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  iVar2 = 0;

  FUN_0036f900(param_1,param_2,0x1e,5,0,1,param_3,0x382320,0);

  iVar1 = (int)param_3;

  if (*(int *)(iVar1 + 0xd4) != 0x27) {

    iVar1 = 0;

  }

  else {

    if ((DAT_007e0952 & 0x1000) == 0) {

      if ((DAT_007e0952 & 0x4000) != 0) {

        if (*(int *)(iVar1 + 400) == 2) {

          *(u32 *)(iVar1 + 400) = 0;

        }

        else {

          *(int *)(iVar1 + 400) = *(int *)(iVar1 + 400) + 1;

        }

      }

    }

    else if (*(int *)(iVar1 + 400) == 0) {

      *(u32 *)(iVar1 + 400) = 2;

    }

    else {

      *(int *)(iVar1 + 400) = *(int *)(iVar1 + 400) + -1;

    }

    if ((DAT_007e0952 & 0x2000) != 0) {

      iVar2 = 1;

    }

    else {

      if ((DAT_007e0952 & 8) != 0) {

        iVar2 = 10;

      }

      else {

        if ((DAT_007e0952 & 2) != 0) {

          iVar2 = 100;

        }

        else {

          if ((DAT_007e0952 & 0x8000) != 0) {

            iVar2 = -1;

          }

          else {

            if ((DAT_007e0952 & 4) != 0) {

              iVar2 = -10;

            }

            else {

              if ((DAT_007e0952 & 1) != 0) {

                iVar2 = -100;

              }

            }

          }

        }

      }

    }

    if (iVar2 != 0) {

      iVar1 = *(int *)(iVar1 + 400) * 4 + iVar1;

      iVar2 = *(int *)(iVar1 + 0x198) + iVar2;

      if (60000 < iVar2) {

        iVar2 = 60000;

      }

      if (iVar2 < 0) {

        iVar2 = 0;

      }

      *(int *)(iVar1 + 0x198) = iVar2;

    }

    if ((DAT_007e094e & 0x40) == 0) {

      iVar1 = -(u32)((DAT_007e094e & 0x20) != 0);

    }

    else {

      iVar1 = 1;

    }

  }

  return iVar1;

}


// FUN_003826F0


u32 FUN_003826f0(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069ffc0_abs);

  return 2;

}


// FUN_00382760
void FUN_00382760(int param_1,int param_2,int param_3,int param_4)
{
  u32 uVar1;
  f32 fVar2;
  int iVar3;

  uVar1 = 0;
  if (*(int *)(param_4 + 400) == param_3) {
    uVar1 = 4;
  }
  switch (param_3) {
  case 0:
    iVar3 = param_2 * 0xc;
    fVar2 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((int)(param_1 * 0xc), iVar3, fVar2, 0, (const char *)(void *)DAT_0069ffe0_abs);
    fVar2 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((int)((param_1 + 0x1a) * 0xc), iVar3, fVar2, uVar1, (const char *)(void *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x198));
    break;
  default:
    return;
  }
}


#pragma alias FUN_003b55b0_evt_f32 FUN_003b55b0
extern f32 *FUN_003b55b0_evt_f32(int param_1);
/* opt_propagation off: default nd701/944B -> nd654/944B; retained. */
#pragma push
#pragma opt_propagation off
// FUN_00382840 NONMATCHING


int FUN_00382840(int param_1,int param_2,int param_3)



{

  float *puVar1;

  int iVar2;

  

  FUN_0036f900(param_1,param_2,0x1e,5,0,1,param_3,0x3826f0,0);

  iVar2 = param_3;

  if (*(int *)(iVar2 + 0xd4) != 0x28) {

    iVar2 = 0;

  }

  else {

    if (*(int *)(iVar2 + 400) == 0) {

      if ((DAT_007e0952 & 0x2000) != 0) {

        if (*(int *)(iVar2 + 0x198) < 5) {

          *(int *)(iVar2 + 0x198) = *(int *)(iVar2 + 0x198) + 1;

        }

        else {

          *(u32 *)(iVar2 + 0x198) = 0;

        }

        puVar1 = FUN_003b55b0_evt_f32(*(u32 *)(iVar2 + 0x198));

        *(float *)(iVar2 + 0x84c) = puVar1[0];

        *(float *)(iVar2 + 0x850) = puVar1[1];

        *(float *)(iVar2 + 0x854) = puVar1[2];

        *(float *)(iVar2 + 0x858) = puVar1[3];

      }

      else {

        if ((DAT_007e0952 & 0x8000) != 0) {

          if (*(int *)(iVar2 + 0x198) < 1) {

            *(u32 *)(iVar2 + 0x198) = 5;

          }

          else {

            *(int *)(iVar2 + 0x198) = *(int *)(iVar2 + 0x198) + -1;

          }

          puVar1 = FUN_003b55b0_evt_f32(*(u32 *)(iVar2 + 0x198));

          *(float *)(iVar2 + 0x84c) = puVar1[0];

          *(float *)(iVar2 + 0x850) = puVar1[1];

          *(float *)(iVar2 + 0x854) = puVar1[2];

          *(float *)(iVar2 + 0x858) = puVar1[3];

        }

      }

      if (((DAT_007e0952 & 0x80) != 0) && (*(int *)(iVar2 + 0x198) != 0)) {

        FUN_003b55d0(*(int *)(iVar2 + 0x198),iVar2 + 0x84c);

      }

    }

    if (*(int *)(iVar2 + 0x198) != 0) {

      if (DAT_007e095f < 0x3c) {

        *(float *)(iVar2 + 0x854) = *(float *)(iVar2 + 0x854) + fGpffff8294;

      }

      else if (0xbb < DAT_007e095f) {

        *(float *)(iVar2 + 0x854) = *(float *)(iVar2 + 0x854) - fGpffff8294;

      }

      if (DAT_007e095e < 0x3c) {

        *(float *)(iVar2 + 0x84c) = *(float *)(iVar2 + 0x84c) - fGpffff8294;

      }

      else if (0xbb < DAT_007e095e) {

        *(float *)(iVar2 + 0x84c) = *(float *)(iVar2 + 0x84c) + fGpffff8294;

      }

      if (DAT_007e0961 < 0x3c) {

        *(float *)(iVar2 + 0x858) = *(float *)(iVar2 + 0x858) + fGpffff8294;

      }

      else if (0xbb < DAT_007e0961) {

        *(float *)(iVar2 + 0x858) = *(float *)(iVar2 + 0x858) - fGpffff8294;

      }

      if (DAT_007e0960 < 0x3c) {

        *(float *)(iVar2 + 0x850) = *(float *)(iVar2 + 0x850) - fGpffff8294;

      }

      else if (0xbb < DAT_007e0960) {

        *(float *)(iVar2 + 0x850) = *(float *)(iVar2 + 0x850) + fGpffff8294;

      }

      if (1.0f < *(float *)(iVar2 + 0x854)) {

        *(u32 *)(iVar2 + 0x854) = 0x3f800000;

      }

      if (*(float *)(iVar2 + 0x854) < 0.0f) {

        *(u32 *)(iVar2 + 0x854) = 0;

      }

      if (1.0f < *(float *)(iVar2 + 0x84c)) {

        *(u32 *)(iVar2 + 0x84c) = 0x3f800000;

      }

      if (*(float *)(iVar2 + 0x84c) < 0.0f) {

        *(u32 *)(iVar2 + 0x84c) = 0;

      }

      if (1.0f < *(float *)(iVar2 + 0x858)) {

        *(u32 *)(iVar2 + 0x858) = 0x3f800000;

      }

      if (*(float *)(iVar2 + 0x858) < 0.0f) {

        *(u32 *)(iVar2 + 0x858) = 0;

      }

      if (1.0f < *(float *)(iVar2 + 0x850)) {

        *(u32 *)(iVar2 + 0x850) = 0x3f800000;

      }

      if (*(float *)(iVar2 + 0x850) < 0.0f) {

        *(u32 *)(iVar2 + 0x850) = 0;

      }

    }

    FUN_00396250(param_3,iVar2 + 0x84c);

    if ((DAT_007e094e & 0x40) == 0) {

      iVar2 = -(u32)((DAT_007e094e & 0x20) != 0);

    }

    else {

      iVar2 = 1;

    }

  }

  return iVar2;

}
#pragma pop


// FUN_00382C10


u32 FUN_00382c10(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_006a0000_abs - 8);

  return 2;

}


// FUN_00382C80
void FUN_00382c80(int param_1,int param_2,int param_3,int param_4)
{
  u32 uVar1;
  f32 fVar2;
  int iVar3;

  uVar1 = 0;
  if (*(int *)(param_4 + 400) == param_3) {
    uVar1 = 4;
  }
  switch (param_3) {
  case 0:
    iVar3 = param_2 * 0xc;
    fVar2 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, iVar3, fVar2, 0, (const char *)(void *)(DAT_006a0000_abs + 0x10));
    fVar2 = FUN_0038a220(*(u32 *)(param_4 + 0xe0));
    evtMenuDrawText((param_1 + 0x19) * 0xc, iVar3, fVar2, uVar1, (const char *)&gp0xffffa3b8, *(u32 *)(param_4 + 0x198));
    break;
  default:
    return;
  }
}


// FUN_00382D60


int FUN_00382d60(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  iVar1 = 0;

  FUN_0036f900_evt(param_1,param_2,0x1e,5,0,1,param_3,(code *)FUN_00382c10,(code *)FUN_00382c80);

  iVar2 = (int)param_3;

  if (*(int *)(iVar2 + 0xd4) != 0x29) {
    return 0;
  }

    switch (*(int *)(iVar2 + 400)) {
    case 0:

      if ((*(u16 *)DAT_007e0952_abs & 0x2000) != 0) {
        iVar1 = 1;
      }
      else if ((*(u16 *)DAT_007e0952_abs & 0x8000) != 0) {
        iVar1 = -1;
      }

      if ((*(u16 *)DAT_007e0952_abs & 8) != 0) {

        iVar1 = 10;

      }

      if ((*(u16 *)DAT_007e0952_abs & 4) != 0) {

        iVar1 = -10;

      }

      if ((*(u16 *)DAT_007e0952_abs & 2) != 0) {

        iVar1 = 100;

      }

      if ((*(u16 *)DAT_007e0952_abs & 1) != 0) {

        iVar1 = -100;

      }
      *(int *)(iVar2 + 0x198) = *(int *)(iVar2 + 0x198) + iVar1;

      if (*(int *)(iVar2 + 0x198) < 0) {
        *(int *)(param_3 + 0x198) = 0;

      }

      if (30000 < *(int *)(iVar2 + 0x198)) {

        *(int *)(param_3 + 0x198) = 30000;

      }

    break;
    }

    if ((*(u16 *)DAT_007e094e_abs & 0x40) != 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = -(u32)((*(u16 *)DAT_007e094e_abs & 0x20) != 0);
    }
  return iVar1;


}


// FUN_00382EC0


u32 FUN_00382ec0(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_006a0030_abs);

  return 2;

}


/* opt_lifetimes on: default nd364/1072B -> nd344/1072B; retained. */
#pragma push
#pragma opt_lifetimes on
// FUN_00382F30 NONMATCHING


void FUN_00382f30(int param_1,int param_2,int param_3,int param_4)



{

  int iVar1;

  int lVar2;

  int iVar3;

  u32 uVar4;

  int iVar5;

  f32 uVar6;
  u32 uVar7;

  
  iVar1 = FUN_00361830(param_4);

  uVar4 = 0;


  iVar5 = (int)param_4;

  if (*(int *)(iVar5 + 400) == param_3) {

    uVar4 = 4;

  }

  switch (param_3) {
  case 0:
    uVar6 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar6, 0, (const char *)&gp0xffffa688);
    iVar3 = 0;
    lVar2 = FUN_003b5d10(*(u16 *)(iVar1 + 0x12));
    if (lVar2 != 0) {
      uVar7 = *(u32 *)((int)lVar2 + 0x104);
      for (iVar1 = 0; iVar1 < 0x40; iVar1 = iVar1 + 1) {
        lVar2 = FUN_00318620_evt_u32(uVar7,0,(short)iVar1);
        if (lVar2 == 1) {
          iVar3 = iVar3 + 1;
        }
      }
    }
    uVar6 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));
    evtMenuDrawText((param_1 + 0x10) * 0xc, param_2 * 0xc, uVar6, uVar4, (const char *)&gp0xffffa3b8, *(u32 *)(iVar5 + 0x198));
    uVar6 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));
    evtMenuDrawText((param_1 + 0x13) * 0xc, param_2 * 0xc, uVar6, uVar4, (const char *)(void *)(DAT_006a0000_abs + 0x48), (u32)iVar3);
    break;
  case 1:
    param_2 = param_2 * 0xc;
    uVar6 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, param_2, uVar6, 0, (const char *)&gp0xffffa690);
    if (*(int *)(iVar5 + 0x19c) == 1) {
      uVar6 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));
      evtMenuDrawText((param_1 + 0x10) * 0xc, param_2, uVar6, uVar4, (const char *)&gp0xffffa6a0);
    }
    else if (*(int *)(iVar5 + 0x19c) == 0) {
      uVar6 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));
      evtMenuDrawText((param_1 + 0x10) * 0xc, param_2, uVar6, uVar4, (const char *)&gp0xffffa698);
    }
    break;
  case 2: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar6 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar6, 0, (const char *)(void *)(DAT_006a0000_abs + 0x58));
    uVar6 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));
    evtMenuDrawText((param_1 + 0x10) * 0xc, scaledY, uVar6, uVar4, (const char *)&gp0xffffa3b8, *(u32 *)(iVar5 + 0x1a0));
    break;
  }
  case 3: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar6 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar6, 0, (const char *)(void *)(DAT_006a0000_abs + 0x68));
    uVar6 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));
    evtMenuDrawText((param_1 + 0x10) * 0xc, scaledY, uVar6, uVar4, (const char *)&gp0xffffa3b8, *(u32 *)(iVar5 + 0x1a4));
    break;
  }
  case 4: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar6 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar6, 0, (const char *)&gp0xffffa4e8);
    uVar6 = FUN_0038a220(*(u32 *)(iVar5 + 0xe0));
    evtMenuDrawText((param_1 + 0x10) * 0xc, scaledY, uVar6, uVar4, (const char *)&gp0xffffa3b8, *(u32 *)(iVar5 + 0x1a8));
    break;
  }
  }

  return;

}
#pragma pop


/* opt_lifetimes on: default nd912/1172B -> nd908/1172B; retained. */
#pragma push
#pragma opt_lifetimes on
// FUN_00383360 NONMATCHING


int FUN_00383360(int param_1,int param_2,int param_3)



{

  u32 uVar1;

  int iVar2;

  int lVar3;

  int iVar4;

  int iVar5;

  

  iVar2 = FUN_00361830(param_3);

  FUN_0036f900(param_1,param_2,0x1e,9,0,1,param_3,0x382ec0,0);

  iVar5 = (int)param_3;

  if (*(int *)(iVar5 + 0xd4) != 0x2a) {

    iVar2 = 0;

  }

  else {

    if ((DAT_007e0952 & 0x1000) == 0) {

      if ((DAT_007e0952 & 0x4000) != 0) {

        if (*(int *)(iVar5 + 400) != 5) {

          *(int *)(iVar5 + 400) = *(int *)(iVar5 + 400) + 1;

        }

        else {

          *(u32 *)(iVar5 + 400) = 0;

        }

      }

    }

    else if (*(int *)(iVar5 + 400) == 0) {

      *(u32 *)(iVar5 + 400) = 5;

    }

    else {

      *(int *)(iVar5 + 400) = *(int *)(iVar5 + 400) + -1;

    }

    iVar4 = *(int *)(iVar5 + 400);

    if (iVar4 == 4) {

      if ((DAT_007e0952 & 0x2000) != 0) {

        *(int *)(iVar5 + 0x1a8) = *(int *)(iVar5 + 0x1a8) + 1;

      }

      else {

        if ((DAT_007e0952 & 8) != 0) {

          *(int *)(iVar5 + 0x1a8) = *(int *)(iVar5 + 0x1a8) + 10;

        }

        else {

          if ((DAT_007e0952 & 0x8000) != 0) {

            *(int *)(iVar5 + 0x1a8) = *(int *)(iVar5 + 0x1a8) + -1;

          }

          else {

            if ((DAT_007e0952 & 4) != 0) {

              *(int *)(iVar5 + 0x1a8) = *(int *)(iVar5 + 0x1a8) + -10;

            }

          }

        }

      }

      if (500 < *(int *)(iVar5 + 0x1a8)) {

        *(u32 *)(iVar5 + 0x1a8) = 500;

      }

      if (*(int *)(iVar5 + 0x1a8) < 10) {

        *(u32 *)(iVar5 + 0x1a8) = 10;

      }

    }

    else if (iVar4 == 3) {

      if ((DAT_007e0952 & 0x2000) != 0) {

        *(int *)(iVar5 + 0x1a4) = *(int *)(iVar5 + 0x1a4) + 1;

      }

      else {

        if ((DAT_007e0952 & 8) != 0) {

          *(int *)(iVar5 + 0x1a4) = *(int *)(iVar5 + 0x1a4) + 10;

        }

        else {

          if ((DAT_007e0952 & 0x8000) != 0) {

            *(int *)(iVar5 + 0x1a4) = *(int *)(iVar5 + 0x1a4) + -1;

          }

          else {

            if ((DAT_007e0952 & 4) != 0) {

              *(int *)(iVar5 + 0x1a4) = *(int *)(iVar5 + 0x1a4) + -10;

            }

          }

        }

      }

      if (*(int *)(iVar5 + 0x1a4) < 0) {

        *(u32 *)(iVar5 + 0x1a4) = 0;

      }

    }

    else if (iVar4 == 2) {

      if ((DAT_007e0952 & 0x2000) != 0) {

        *(int *)(iVar5 + 0x1a0) = *(int *)(iVar5 + 0x1a0) + 1;

      }

      else {

        if ((DAT_007e0952 & 8) != 0) {

          *(int *)(iVar5 + 0x1a0) = *(int *)(iVar5 + 0x1a0) + 10;

        }

        else {

          if ((DAT_007e0952 & 0x8000) != 0) {

            *(int *)(iVar5 + 0x1a0) = *(int *)(iVar5 + 0x1a0) + -1;

          }

          else {

            if ((DAT_007e0952 & 4) != 0) {

              *(int *)(iVar5 + 0x1a0) = *(int *)(iVar5 + 0x1a0) + -10;

            }

          }

        }

      }

      if (*(int *)(iVar5 + 0x1a0) < 0) {

        *(u32 *)(iVar5 + 0x1a0) = 0;

      }

    }

    else if (iVar4 == 1) {

      if (((DAT_007e0952 & 0x2000) != 0) || ((DAT_007e0952 & 0x8000) != 0)) {

        *(u32 *)(iVar5 + 0x19c) = (u32)(*(int *)(iVar5 + 0x19c) == 0);

      }

    }

    else if (iVar4 == 0) {

      iVar4 = 0;

      lVar3 = FUN_003b5d10(*(u16 *)(iVar2 + 0x12));

      if (lVar3 != 0) {

        uVar1 = *(u32 *)((int)lVar3 + 0x104);

        for (iVar2 = 0; iVar2 < 0x40; iVar2 = iVar2 + 1) {

          lVar3 = FUN_00318620(uVar1,0,(short)iVar2);

          if (lVar3 == 1) {

            iVar4 = iVar4 + 1;

          }

        }

      }

      if ((DAT_007e0952 & 0x2000) != 0) {

        *(int *)(iVar5 + 0x198) = *(int *)(iVar5 + 0x198) + 1;

      }

      else {

        if ((DAT_007e0952 & 8) != 0) {

          *(int *)(iVar5 + 0x198) = *(int *)(iVar5 + 0x198) + 10;

        }

        else {

          if ((DAT_007e0952 & 0x8000) != 0) {

            *(int *)(iVar5 + 0x198) = *(int *)(iVar5 + 0x198) + -1;

          }

          else {

            if ((DAT_007e0952 & 4) != 0) {

              *(int *)(iVar5 + 0x198) = *(int *)(iVar5 + 0x198) + -10;

            }

          }

        }

      }

      if (iVar4 <= *(int *)(iVar5 + 0x198)) {

        *(int *)(iVar5 + 0x198) = iVar4 + -1;

      }

      if (*(int *)(iVar5 + 0x198) < 0) {

        *(u32 *)(iVar5 + 0x198) = 0;

      }

    }

    if ((DAT_007e094e & 0x40) != 0) {

      iVar2 = 1;

    }

    else {

      iVar2 = -(u32)((DAT_007e094e & 0x20) != 0);

    }

  }

  return iVar2;

}
#pragma pop


// FUN_00383810


u32 FUN_00383810(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_006a0080_abs);

  return 2;

}


// FUN_00383880


void FUN_00383880(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  u32 uVar2;
  int iVar3;
  f32 uVar4;

  uVar2 = 0;
  iVar1 = FUN_00361830(param_4);
  iVar3 = (int)param_4;
  if (*(int *)(iVar3 + 400) == param_3) {
    uVar2 = 4;
  }
  switch (param_3) {
  case 0: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0,
                    (const char *)(void *)(DAT_006a0000_abs + 0xa0));
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText((param_1 + 0x18) * 0xc, scaledY, uVar4, uVar2,
                    (const char *)&gp0xffffa3b8, *(u32 *)(iVar3 + 0x198));
    break;
  }
  case 1: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0,
                    (const char *)(void *)(DAT_006a0000_abs + 0xc0));
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText((param_1 + 0x18) * 0xc, scaledY, uVar4, uVar2,
                    (const char *)&gp0xffffa3b8, *(u32 *)(iVar3 + 0x19c));
    break;
  }
  case 2: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0,
                    (const char *)(void *)(DAT_006a0000_abs + 0xe0));
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText((param_1 + 0x18) * 0xc, scaledY, uVar4, uVar2,
                    (const char *)&gp0xffffa3b8, *(u32 *)(iVar3 + 0x1a0));
    break;
  }
  case 3: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0,
                    (const char *)(void *)(DAT_006a0000_abs + 0x100));
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText((param_1 + 0x18) * 0xc, scaledY, uVar4, uVar2,
                    (const char *)&gp0xffffa3b8, *(u32 *)(iVar3 + 0x1a4));
    break;
  }
  case 4: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0,
                    (const char *)(void *)(DAT_006a0000_abs + 0x118));
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText((param_1 + 0x18) * 0xc, scaledY, uVar4, uVar2,
                    (const char *)&gp0xffffa3b8, *(u32 *)(iVar3 + 0x1a8) & 0x3ff);
    break;
  }
  case 5: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0,
                    (const char *)(void *)(DAT_006a0000_abs + 0x130));
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText((param_1 + 0x18) * 0xc, scaledY, uVar4, uVar2,
                    (const char *)&gp0xffffa3b8, *(u32 *)(iVar3 + 0x1ac) & 0x3ff);
    break;
  }
  case 6: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0,
                    (const char *)(void *)(DAT_006a0000_abs + 0x148));
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText((param_1 + 0x18) * 0xc, scaledY, uVar4, uVar2,
                    (const char *)&gp0xffffa3b8, *(u32 *)(iVar3 + 0x1b0) & 0x3ff);
    break;
  }
  case 7: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0,
                    (const char *)&gp0xffffa630);
    switch (*(int *)(iVar3 + 0x1b4)) {
    case 0:
      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
      evtMenuDrawText((param_1 + 0x18) * 0xc, scaledY, uVar4, uVar2,
                      (const char *)&gp0xffffa350);
      break;
    case 1:
      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
      evtMenuDrawText((param_1 + 0x18) * 0xc, scaledY, uVar4, uVar2,
                      (const char *)(void *)(DAT_006a0000_abs + 0x158));
      break;
    }
    break;
  }
  }
}


// FUN_00383D80 NONMATCHING


int FUN_00383d80(int param_1,int param_2,int param_3)



{

  u32 uVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  

  FUN_00361830(param_3);

  FUN_0036f900(param_1,param_2,0x23,0xb,0,1,param_3,0x383810,(code *)FUN_00383880);

  iVar2 = (int)param_3;

  if (*(int *)(iVar2 + 0xd4) == 0x2b) {

    if ((DAT_007e0952 & 0x1000) == 0) {

      if ((DAT_007e0952 & 0x4000) != 0) {

        if (*(int *)(iVar2 + 400) == 7) {

          *(u32 *)(iVar2 + 400) = 0;

        }

        else {

          *(int *)(iVar2 + 400) = *(int *)(iVar2 + 400) + 1;

        }

      }

    }

    else if (*(int *)(iVar2 + 400) == 0) {

      *(u32 *)(iVar2 + 400) = 7;

    }

    else {

      *(int *)(iVar2 + 400) = *(int *)(iVar2 + 400) + -1;

    }

    uVar1 = *(u32 *)(iVar2 + 400);

    if (uVar1 < 8) {

      iVar4 = uVar1 * 4;

      switch(uVar1) {

      default:

        if ((DAT_007e0952 & 0x2000) == 0) {

          if ((DAT_007e0952 & 8) == 0) {

            if ((DAT_007e0952 & 0x8000) == 0) {

              if ((DAT_007e0952 & 4) != 0) {

                *(int *)(iVar4 + iVar2 + 0x198) = *(int *)(iVar4 + iVar2 + 0x198) + -10;

              }

            }

            else {

              *(int *)(iVar4 + iVar2 + 0x198) = *(int *)(iVar4 + iVar2 + 0x198) + -1;

            }

          }

          else {

            *(int *)(iVar4 + iVar2 + 0x198) = *(int *)(iVar4 + iVar2 + 0x198) + 10;

          }

        }

        else {

          *(int *)(iVar4 + iVar2 + 0x198) = *(int *)(iVar4 + iVar2 + 0x198) + 1;

        }

        iVar2 = uVar1 * 4 + iVar2;

        piVar3 = (int *)(iVar2 + 0x198);

        if (*(int *)(iVar2 + 0x198) < 0) {

          *piVar3 = 0;

        }

        if (30000 < *piVar3) {

          *piVar3 = 30000;

        }

        break;

      case 4:

        break;

      case 7:

        if ((DAT_007e0952 & 0x2000) == 0) {

          if ((DAT_007e0952 & 8) == 0) {

            if ((DAT_007e0952 & 0x8000) == 0) {

              if ((DAT_007e0952 & 4) != 0) {

                *(int *)(iVar2 + 0x1b4) = *(int *)(iVar2 + 0x1b4) + -10;

              }

            }

            else {

              *(int *)(iVar2 + 0x1b4) = *(int *)(iVar2 + 0x1b4) + -1;

            }

          }

          else {

            *(int *)(iVar2 + 0x1b4) = *(int *)(iVar2 + 0x1b4) + 10;

          }

        }

        else {

          *(int *)(iVar2 + 0x1b4) = *(int *)(iVar2 + 0x1b4) + 1;

        }

        if (*(int *)(iVar2 + 0x1b4) < 0) {

          *(u32 *)(iVar2 + 0x1b4) = 1;

        }

        if (1 < *(int *)(iVar2 + 0x1b4)) {

          *(u32 *)(iVar2 + 0x1b4) = 0;

        }

      }

    }

    if ((DAT_007e094e & 0x40) == 0) {

      iVar2 = -(u32)((DAT_007e094e & 0x20) != 0);

    }

    else {

      iVar2 = 1;

    }

  }

  else {

    iVar2 = 0;

  }

  return iVar2;

}


// FUN_00384060


u32 FUN_00384060(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_0069f8b0_abs);

  return 2;

}


// FUN_003840D0


void FUN_003840d0(int param_1,int param_2,int param_3,int param_4)
{
  u32 uVar1;
  int iVar2;
  f32 uVar3;

  uVar1 = 0;
  FUN_00361830(param_4);
  iVar2 = (int)param_4;
  if (*(int *)(iVar2 + 400) == param_3) {
    uVar1 = 4;
  }
  switch (param_3) {
  case 0: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar3, 0, (const char *)(void *)(DAT_006a0000_abs + 0x168));
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText((param_1 + 0x18) * 0xc, scaledY, uVar3, uVar1, (const char *)&gp0xffffa3b8, *(u32 *)(iVar2 + 0x198));
    break;
  }
  case 1: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar3, 0, (const char *)(void *)DAT_0069ff20);
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText((param_1 + 0x18) * 0xc, scaledY, uVar3, uVar1, (const char *)&gp0xffffa3b8, *(u32 *)(iVar2 + 0x198));
    break;
  }
  case 2: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar3, 0, (const char *)(void *)(DAT_006a0000_abs + 0x178));
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText((param_1 + 0x18) * 0xc, scaledY, uVar3, uVar1, (const char *)&gp0xffffa3b8, *(u32 *)(iVar2 + 0x198));
    break;
  }
  case 3: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar3, 0, (const char *)(void *)(DAT_006a0000_abs + 0x188));
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText((param_1 + 0x18) * 0xc, scaledY, uVar3, uVar1, (const char *)&gp0xffffa2d0, *(u32 *)(iVar2 + 0x198));
    break;
  }
  }
  return;
}


// FUN_00384370


int FUN_00384370(int param_1,int param_2,int param_3)



{

  int iVar1;
  int iVar2;
  typedef struct {
    u8 pad[0x190];
    int field190;
  } EvtMenuState;
  EvtMenuState *pState;
  pState = (EvtMenuState *)param_3;
  FUN_00361830(param_3);

  FUN_0036f900_evt(param_1,param_2,0x1e,9,0,1,param_3,
                   (code *)&FUN_00384060,(code *)&FUN_003840d0);

  iVar1 = *(int *)(param_3 + 0xd4);

  if (iVar1 != 0x2c) {

    iVar1 = 0;

  }

  else {

    if ((*(u16 *)DAT_007e0952_abs & 0x1000) != 0) {

      iVar2 = pState->field190;
      if (iVar2 == 0) {
        pState->field190 = 3;

      }

      else {

        pState->field190 = iVar2 + -1;

      }

    }

    else {

      if ((*(u16 *)DAT_007e0952_abs & 0x4000) != 0) {

        iVar2 = pState->field190;
        if (iVar2 == 3) {
          pState->field190 = 0;

        }

        else {

          pState->field190 = iVar2 + 1;

        }

      }

    }
    if ((*(u16 *)DAT_007e094e_abs & 0x40) != 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = -(u32)((*(u16 *)DAT_007e094e_abs & 0x20) != 0);
    }


  }

  return iVar1;

}


// FUN_003844B0


u32 FUN_003844b0(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_006a01a0_abs);

  return 2;

}


// FUN_00384520


void FUN_00384520(int param_1,int param_2,int param_3,int param_4)
{
  u32 uVar1;
  int iVar2;
  f32 uVar3;
  RwV4d apuStack_10;

  uVar1 = 0;
  apuStack_10 = *(RwV4d *)DAT_006a01c0_abs;
  FUN_00361830(param_4);
  iVar2 = (int)param_4;
  if (*(int *)(iVar2 + 400) == param_3) {
    uVar1 = 4;
  }
  switch (param_3) {
  case 0: {
    s32 scaledY = param_2 * 0xc;
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar3, 0, (const char *)&gp0xffffa630);
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText((param_1 + 0x14) * 0xc, scaledY, uVar3, uVar1,
                    (const char *)&gp0xffffa068, ((u32 *)&apuStack_10)[*(int *)(iVar2 + 0x198)]);
    break;
  }
  case 1: {
    s32 scaledY = param_2 * 0xc;
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar3, 0, (const char *)DAT_006a01d0_abs);
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText((param_1 + 0x14) * 0xc, scaledY, uVar3, uVar1,
                    (const char *)&gp0xffffa3b8, *(u32 *)(iVar2 + 0x19c) & 0x3ff);
    break;
  }
  case 2:
    if (*(int *)(iVar2 + 0x198) == 0) {
      s32 scaledY = param_2 * 0xc;
      uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
      evtMenuDrawText(param_1 * 0xc, scaledY, uVar3, 0, (const char *)&gp0xffffa6c8);
      uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
      evtMenuDrawText((param_1 + 0x14) * 0xc, scaledY, uVar3, uVar1,
                      (const char *)&gp0xffffa3b8, *(u32 *)(iVar2 + 0x1a0));
    }
    break;
  }
}


/* opt_lifetimes on: default nd337/572B -> nd331/572B; retained. */
#pragma push
#pragma opt_lifetimes on
// FUN_00384780 NONMATCHING


int FUN_00384780(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  iVar1 = 1;

  FUN_00361830(param_3);

  FUN_0036f900(param_1,param_2,0x1e,6,0,1,param_3,0x3844b0,(code *)FUN_00384520);


  iVar2 = (int)param_3;

  if (*(int *)(iVar2 + 0xd4) == 0x2d) goto matched;

  iVar1 = 0;

  goto done;

matched:

    if (*(int *)(iVar2 + 0x198) == 0) {

      iVar1 = 2;

    }

    if ((DAT_007e0952 & 0x1000) == 0) {

      if ((DAT_007e0952 & 0x4000) != 0) {

        if (*(int *)(iVar2 + 400) == iVar1) {

          *(u32 *)(iVar2 + 400) = 0;

        }

        else {

          *(int *)(iVar2 + 400) = *(int *)(iVar2 + 400) + 1;

        }

      }

    }

    else if (*(int *)(iVar2 + 400) == 0) {

      *(int *)(iVar2 + 400) = iVar1;

    }

    else {

      *(int *)(iVar2 + 400) = *(int *)(iVar2 + 400) + -1;

    }

    if (*(int *)(iVar2 + 400) == 2) {

      if ((DAT_007e0952 & 0x2000) != 0) {

        *(int *)(iVar2 + 0x1a0) = *(int *)(iVar2 + 0x1a0) + 1;

      }

      if ((DAT_007e0952 & 0x8000) != 0) {

        *(int *)(iVar2 + 0x1a0) = *(int *)(iVar2 + 0x1a0) + -1;

      }

      if (*(int *)(iVar2 + 0x1a0) >= 0x1e) {

        *(u32 *)(iVar2 + 0x1a0) = 0;

      }

      else {

        if (*(int *)(iVar2 + 0x1a0) < 0) {

          *(u32 *)(iVar2 + 0x1a0) = 0x1d;

        }

      }

    }

    else if (*(int *)(iVar2 + 400) == 0) {

      if ((DAT_007e0952 & 0x2000) != 0) {

        *(int *)(iVar2 + 0x198) = *(int *)(iVar2 + 0x198) + 1;

        *(u32 *)(iVar2 + 0x19c) = 0;

        *(u32 *)(iVar2 + 0x1a0) = 0;

      }

      if ((DAT_007e0952 & 0x8000) != 0) {

        *(int *)(iVar2 + 0x198) = *(int *)(iVar2 + 0x198) + -1;

        *(u32 *)(iVar2 + 0x19c) = 0;

        *(u32 *)(iVar2 + 0x1a0) = 0;

      }

      if (*(int *)(iVar2 + 0x198) >= 4) {

        *(u32 *)(iVar2 + 0x198) = 0;

      }

      else {

        if (*(int *)(iVar2 + 0x198) < 0) {

          *(u32 *)(iVar2 + 0x198) = 3;

        }

      }

    }

    if ((DAT_007e094e & 0x40) == 0) {

      iVar1 = -(u32)((DAT_007e094e & 0x20) != 0);

    }

    else {

      iVar1 = 1;

    }


done:
  return iVar1;

}
#pragma pop


// FUN_003849E0


u32 FUN_003849e0(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_006a01e0_abs);

  return 2;

}


// FUN_00384A50


void FUN_00384a50(int param_1,int param_2,int param_3,int param_4)



{

  u32 uVar1;

  int iVar2;

  f32 uVar3;

  

  uVar1 = 0;

  FUN_00361830(param_4);

  iVar2 = (int)param_4;

  if (*(int *)(iVar2 + 400) == param_3) {

    uVar1 = 4;

  }

  switch (param_3) {
  case 0: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar3, 0, (const char *)(void *)(DAT_006a0000_abs + 0x1f0));
    if (*(int *)(iVar2 + 0x1b8) == 0) {
      uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
      evtMenuDrawText((param_1 + 0x14) * 0xc, scaledY, uVar3, uVar1, (const char *)&gp0xffffa0b8);
    }
    else {
      uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
      evtMenuDrawText((param_1 + 0x14) * 0xc, scaledY, uVar3, uVar1, (const char *)&gp0xffffa0c0);
    }
    break;
  }
  case 1: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar3, 0, (const char *)(void *)(DAT_006a0000_abs + 0x200));
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText((param_1 + 0x14) * 0xc, scaledY, uVar3, uVar1, (const char *)&gp0xffffa3b8, *(u32 *)(iVar2 + 0x1bc));
    break;
  }
  case 2: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar3, 0, (const char *)(void *)(DAT_006a0000_abs + 0x210));
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText((param_1 + 0x14) * 0xc, scaledY, uVar3, uVar1, (const char *)&gp0xffffa3b8, *(u32 *)(iVar2 + 0x1c0));
    break;
  }
  case 3: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar3, 0, (const char *)(void *)(DAT_006a0000_abs + 0x220));
    uVar3 = FUN_0038a220(*(u32 *)(iVar2 + 0xe0));
    evtMenuDrawText((param_1 + 0x14) * 0xc, scaledY, uVar3, uVar1, (const char *)&gp0xffffa3b8, *(u32 *)(iVar2 + 0x1c4));
    break;
  }
  }

  return;

}


// FUN_00384D30 NONMATCHING






u32 FUN_00384d30(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  u32 uVar3;

  int iVar4;

  

  iVar2 = FUN_00361830(param_3);

  FUN_0036f900(param_1,param_2,0x1e,6,0,1,param_3,0x3849e0,(code *)FUN_00384a50);

  iVar4 = (int)param_3;

  if (*(int *)(iVar4 + 0xd4) != 0x2e) {

    uVar3 = 0;

  }

  else {

    if (((*(u16 *)DAT_007e0952_abs) & 0x1000) == 0) {

      if (((*(u16 *)DAT_007e0952_abs) & 0x4000) != 0) {

        if (*(int *)(iVar4 + 400) == 3) {

          *(u32 *)(iVar4 + 400) = 0;

        }

        else {

          *(int *)(iVar4 + 400) = *(int *)(iVar4 + 400) + 1;

        }

      }

    }

    else if (*(int *)(iVar4 + 400) == 0) {

      *(u32 *)(iVar4 + 400) = 3;

    }

    else {

      *(int *)(iVar4 + 400) = *(int *)(iVar4 + 400) + -1;

    }

    if ((DAT_007e094c & 0x10) != 0) {

      if (((*(u16 *)DAT_007e0952_abs) & 0x2000) != 0) {

        DAT_007ce5f8 = DAT_007ce5f8 + 1;

      }

      else {

        if (((*(u16 *)DAT_007e0952_abs) & 0x8000) != 0) {

          DAT_007ce5f8 = DAT_007ce5f8 - 1;

        }

      }

      if (2 < DAT_007ce5f8) {

        DAT_007ce5f8 = 0;

      }

      if (DAT_007ce5f8 == 2) {

        *(u32 *)(iVar4 + 0x1c0) = 8;

        *(u32 *)(iVar4 + 0x1c4) = 6;

      }

      else if (DAT_007ce5f8 == 1) {

        *(u32 *)(iVar4 + 0x1c0) = 0xd;

        *(u32 *)(iVar4 + 0x1c4) = 6;

      }

    }

    else {

      DAT_007ce5f8 = 0;

      iVar1 = *(int *)(iVar4 + 400);

      switch (iVar1) {
      case 0:
        if (((*(u16 *)DAT_007e0952_abs) & 0x2000) != 0 ||
            ((*(u16 *)DAT_007e0952_abs) & 0x8000) != 0) {
          *(u32 *)(iVar4 + 0x1b8) = (u32)(*(int *)(iVar4 + 0x1b8) == 0);
        }
        break;
      case 1:
        if (((*(u16 *)DAT_007e0952_abs) & 0x2000) != 0) {
          *(int *)(iVar4 + 0x1bc) = *(int *)(iVar4 + 0x1bc) + 1;
        }
        if (((*(u16 *)DAT_007e0952_abs) & 0x8000) != 0) {
          *(int *)(iVar4 + 0x1bc) = *(int *)(iVar4 + 0x1bc) + -1;
        }
        if (*(int *)(iVar4 + 0x1bc) >= 4) {
          *(u32 *)(iVar4 + 0x1bc) = 0;
        }
        else if (*(int *)(iVar4 + 0x1bc) < 0) {
          *(u32 *)(iVar4 + 0x1bc) = 3;
        }
        break;
      case 2:
        if (((*(u16 *)DAT_007e0952_abs) & 0x2000) != 0) {
          *(int *)(iVar4 + 0x1c0) = *(int *)(iVar4 + 0x1c0) + 1;
        }
        if (((*(u16 *)DAT_007e0952_abs) & 0x8000) != 0) {
          *(int *)(iVar4 + 0x1c0) = *(int *)(iVar4 + 0x1c0) + -1;
        }
        if (*(int *)(iVar4 + 0x1c0) >= 0x3d) {
          *(u32 *)(iVar4 + 0x1c0) = 0;
        }
        else if (*(int *)(iVar4 + 0x1c0) < 0) {
          *(u32 *)(iVar4 + 0x1c0) = 0x3c;
        }
        break;
      case 3:
        if (((*(u16 *)DAT_007e0952_abs) & 0x2000) != 0) {
          *(int *)(iVar4 + 0x1c4) = *(int *)(iVar4 + 0x1c4) + 1;
        }
        if (((*(u16 *)DAT_007e0952_abs) & 0x8000) != 0) {
          *(int *)(iVar4 + 0x1c4) = *(int *)(iVar4 + 0x1c4) + -1;
        }
        if (*(int *)(iVar4 + 0x1c4) >= 0x3d) {
          *(u32 *)(iVar4 + 0x1c4) = 0;
        }
        else if (*(int *)(iVar4 + 0x1c4) < 0) {
          *(u32 *)(iVar4 + 0x1c4) = 0x3c;
        }
        break;
      }

    }

    if ((DAT_007e094e & 0x40) != 0) {

      if ((**(int **)(iVar4 + 0x164) == 0x30) || (**(int **)(iVar4 + 0x164) == 1)) {

        if (*(char *)(iVar2 + 0x10) == '\x04') {

          *(u32 *)(iVar4 + 400) = 3;

        }

        else if (*(char *)(iVar2 + 0x10) == '\x01') {

          *(u32 *)(iVar4 + 400) = 6;

        }

      }

      uVar3 = 1;

    }

    else {

      if ((DAT_007e094e & 0x20) == 0) {

        uVar3 = 0;

      }

      else {

        if ((**(int **)(iVar4 + 0x164) == 0x30) || (**(int **)(iVar4 + 0x164) == 1)) {

          if (*(char *)(iVar2 + 0x10) == '\x04') {

            *(u32 *)(iVar4 + 400) = 3;

          }

          else if (*(char *)(iVar2 + 0x10) == '\x01') {

            *(u32 *)(iVar4 + 400) = 6;

          }

        }

        uVar3 = 0xffffffff;

      }

    }

  }

  return uVar3;

}


// FUN_003851F0


u32 FUN_003851f0(int param_1,int param_2,int param_3)



{

  f32 uVar1;

  

  uVar1 = FUN_0038a220(*(u32 *)(param_3 + 0xe0));

  evtMenuDrawText(param_1 * 0xc, param_2 * 0xc, uVar1, 0, (const char *)DAT_006a0230_abs);

  return 2;

}


// FUN_00385260


void FUN_00385260(int param_1,int param_2,int param_3,int param_4)



{

  int iVar1;

  u32 uVar2;

  int iVar3;

  f32 uVar4;

  RwV2d afStack_8;

  

  uVar2 = 0;
  afStack_8 = *(RwV2d *)&PTR_DAT_007cd3d0_f32;


  FUN_00361830(param_4);

  iVar3 = (int)param_4;

  if (*(int *)(iVar3 + 400) == param_3) {

    uVar2 = 4;

  }

  switch (param_3) {
  case 0: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0, (const char *)(void *)(DAT_006a0000_abs + 0x240));
    iVar1 = *(int *)(iVar3 + 0x198);
    if (iVar1 < 2) {
      uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
      evtMenuDrawText((param_1 + 0x14) * 0xc, scaledY, uVar4, uVar2, (const char *)&gp0xffffa068, ((u32 *)&afStack_8)[iVar1]);
    }
    break;
  }
  case 1: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0, (const char *)&gp0xffffa6e8);
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText((param_1 + 0x14) * 0xc, scaledY, uVar4, uVar2, (const char *)&gp0xffffa3b8, *(u32 *)(iVar3 + 0x19c));
    break;
  }
  case 2: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0, (const char *)(void *)(DAT_006a0000_abs + 0x250));
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText((param_1 + 0x14) * 0xc, scaledY, uVar4, uVar2, (const char *)&gp0xffffa3b8, *(u32 *)(iVar3 + 0x1a0));
    break;
  }
  case 3: {
    s32 scaledY;
    scaledY = param_2 * 0xc;
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText(param_1 * 0xc, scaledY, uVar4, 0, (const char *)(void *)(DAT_006a0000_abs + 0x260));
    uVar4 = FUN_0038a220(*(u32 *)(iVar3 + 0xe0));
    evtMenuDrawText((param_1 + 0x14) * 0xc, scaledY, uVar4, uVar2, (const char *)&gp0xffffa3b8, *(u32 *)(iVar3 + 0x1a4));
    break;
  }
  }

  return;

}


// FUN_00385520 NONMATCHING


int FUN_00385520(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  

  FUN_00361830(param_3);

  FUN_0036f900(param_1,param_2,0x1e,6,0,1,param_3,0x3851f0,(code *)FUN_00385260);

  iVar2 = (int)param_3;

  if (*(int *)(iVar2 + 0xd4) != 0x2f) {

    iVar2 = 0;

  }

  else {

    if ((DAT_007e0952 & 0x1000) == 0) {

      if ((DAT_007e0952 & 0x4000) != 0) {

        if (*(int *)(iVar2 + 400) != 3) {

          *(int *)(iVar2 + 400) = *(int *)(iVar2 + 400) + 1;

        }

        else {

          *(u32 *)(iVar2 + 400) = 0;

        }

      }

    }

    else if (*(int *)(iVar2 + 400) == 0) {

      *(u32 *)(iVar2 + 400) = 3;

    }

    else {

      *(int *)(iVar2 + 400) = *(int *)(iVar2 + 400) + -1;

    }

    iVar1 = *(int *)(iVar2 + 400);

    if (iVar1 == 3) {

      if ((DAT_007e0952 & 0x2000) != 0) {

        *(int *)(iVar2 + 0x1a4) = *(int *)(iVar2 + 0x1a4) + 1;

      }

      if ((DAT_007e0952 & 0x8000) != 0) {

        *(int *)(iVar2 + 0x1a4) = *(int *)(iVar2 + 0x1a4) + -1;

      }

      if (*(int *)(iVar2 + 0x1a4) >= 0x80) {

        *(u32 *)(iVar2 + 0x1a4) = 0;

      }

      else {

        if (*(int *)(iVar2 + 0x1a4) < 0) {

          *(u32 *)(iVar2 + 0x1a4) = 0x7f;

        }

      }

    }

    else if (iVar1 == 2) {

      if ((DAT_007e0952 & 0x2000) != 0) {

        *(int *)(iVar2 + 0x1a0) = *(int *)(iVar2 + 0x1a0) + 1;

      }

      if ((DAT_007e0952 & 0x8000) != 0) {

        *(int *)(iVar2 + 0x1a0) = *(int *)(iVar2 + 0x1a0) + -1;

      }

      if (*(int *)(iVar2 + 0x1a0) >= 5) {

        *(u32 *)(iVar2 + 0x1a0) = 0;

      }

      else {

        if (*(int *)(iVar2 + 0x1a0) < 0) {

          *(u32 *)(iVar2 + 0x1a0) = 4;

        }

      }

    }

    else if (iVar1 == 1) {

      if ((DAT_007e0952 & 0x2000) != 0) {

        *(int *)(iVar2 + 0x19c) = *(int *)(iVar2 + 0x19c) + 1;

      }

      if ((DAT_007e0952 & 0x8000) != 0) {

        *(int *)(iVar2 + 0x19c) = *(int *)(iVar2 + 0x19c) + -1;

      }

      if (*(int *)(iVar2 + 0x19c) >= 2) {

        *(u32 *)(iVar2 + 0x19c) = 0;

      }

      else {

        if (*(int *)(iVar2 + 0x19c) < 0) {

          *(u32 *)(iVar2 + 0x19c) = 1;

        }

      }

    }

    else if (iVar1 == 0) {

      if ((DAT_007e0952 & 0x2000) != 0) {

        *(int *)(iVar2 + 0x198) = *(int *)(iVar2 + 0x198) + 1;

      }

      else {

        if ((DAT_007e0952 & 0x8000) != 0) {

          *(int *)(iVar2 + 0x198) = *(int *)(iVar2 + 0x198) + -1;

        }

      }

      if (*(int *)(iVar2 + 0x198) >= 2) {

        *(u32 *)(iVar2 + 0x198) = 0;

      }

      else {

        if (*(int *)(iVar2 + 0x198) < 0) {

          *(u32 *)(iVar2 + 0x198) = 1;

        }

      }

    }

    if ((DAT_007e094e & 0x40) != 0) {

      iVar2 = 1;

    }

    else {

      iVar2 = -(u32)((DAT_007e094e & 0x20) != 0);

    }

  }

  return iVar2;

}


// FUN_00385860


u32 FUN_00385860(int param_1,u32 param_2,u32 param_3,u32 param_4,EvtMenuState *param_5)



{

  u32 uVar1;
  code *entry;
  
  entry = &DAT_006a0270[param_1];
  if (*entry == 0) {
    uVar1 = 0;
  }
  else {
    param_5->menuId = param_1;
    param_5->menuArg = param_2;
    uVar1 = (*entry)(param_3,param_4,param_5);
  }
  return uVar1;

}


#pragma alias FUN_001005b0_evt FUN_001005b0
extern u32 FUN_001005b0_evt(f32 scale,u32 resource,u64 flags,void *params,u32 color);
// FUN_003858C0


void FUN_003858c0(int param_1)



{

  u32 *puVar1;


  int iVar3;


  u32 auStack_20[8];

  

  auStack_20[0] = 0;

  auStack_20[1] = 0;

  auStack_20[2] = 0x82;

  auStack_20[3] = 0x120;

  auStack_20[4] = 0;

  auStack_20[5] = 0;

  ((u8 *)(auStack_20 + 7))[3] = 0xb4;
  ((u8 *)(auStack_20 + 7))[0] = 0x0a;
  ((u8 *)(auStack_20 + 7))[2] = 0x0a;
  ((u8 *)(auStack_20 + 7))[1] = 0x40;


  for (iVar3 = 0; iVar3 < 7; iVar3 = iVar3 + 1) {
    ((EvtMenuState *)param_1)->resourceHandles[iVar3] =
        FUN_001005b0_evt(2.0f,*(u32 *)(param_1 + 0x92c),
                         *(u64 *)(auStack_20 + 4),
                         &auStack_20[0],auStack_20[7]);

    puVar1 = (u32 *)FUN_00100570(((EvtMenuState *)param_1)->resourceHandles[iVar3]);

    *puVar1 = 0;

  }

  return;

}


// FUN_00385990


void FUN_00385990(u32 param_1,int param_2,int param_3,int param_4,u32 param_5,
                  f32 param_6)



{

  char cVar1;

  int iVar2;
  int iVar4;

  u32 *puVar3;

  RwV2d pos;
  RwRect rect;
  RwRGBA color;


  

  if (*(char *)(param_1 + 0x940) < 7) goto skip_error;
  FUN_0019d3f0((const char *)(DAT_006a0000_abs - 0x1bf8),0x2bf7);
skip_error:
  ;

  cVar1 = *(char *)(param_1 + 0x940);
  *(char *)(param_1 + 0x940) = cVar1 + '\x01';

  iVar4 = cVar1 * 4;
  iVar4 = iVar4 + param_1;
  iVar2 = *(int *)(iVar4 + 0x944);

  if (iVar2 != 0) {

    puVar3 = (u32 *)FUN_00100570(iVar2);

    *puVar3 = 1;

    if (*(int *)(param_1 + 0xd8) != 0xb) {

      pos.x = (f32)param_2;
      pos.y = (f32)param_3;
      FUN_00100710(iVar2,pos);
      FUN_00100770(iVar2,param_6);
      rect.x = 0;
      rect.y = 0;
      rect.w = param_4;
      rect.h = param_5;
      FUN_00100740(iVar2,rect);
      if (*(int *)(param_1 + 0xd4) == *(int *)(param_1 + 0xd8)) {
        color.a = 0xd2;
        color.r = 0x1e;
        color.b = 0x1e;
        color.g = 0x50;
      }
      else {
        color.a = 0x64;
        color.r = 0x0a;
        color.b = 0x0a;
        color.g = 0x3c;
      }

      FUN_00100780(iVar2,color);

    }

  }

  return;

}


// FUN_00385B20


void FUN_00385b20(int param_1)



{

  u32 *puVar1;

  int iVar2;
  int iVar3;

  

  *(u8 *)(param_1 + 0x940) = 0;

  for (iVar2 = 0; iVar2 < 7; iVar2 = iVar2 + 1) {

    if ((iVar3 = *(int *)(param_1 + iVar2 * 4 + 0x944)) != 0) {

      puVar1 = (u32 *)FUN_00100570(iVar3);

      *puVar1 = 0;

    }

  }

  return;

}


// FUN_00385b90


void FUN_00385b90(void)



{

  return;

}


// FUN_00385BA0


void FUN_00385ba0(void)



{
  FUN_005225a8(DAT_006a0330,0);

  return;

}


// FUN_00385BD0


u32 FUN_00385bd0(int param_1,u64 param_2)



{

  u32 uVar1;

  u32 *puVar2;

  u32 uVar3;

  

  uVar3 = FUN_001a3ae0(param_2,0x10,0x40);

  FUN_001a3dc0(uVar3, DAT_006a0350_abs, 5);

  FUN_001a3bf0(uVar3,1);

  uVar1 = *(u32 *)(param_1 + 0x198);

  puVar2 = (u32 *)FUN_001a41b0(uVar3,0);

  *puVar2 = uVar1;

  uVar1 = *(u32 *)(param_1 + 0x19c);

  puVar2 = (u32 *)FUN_001a41b0(uVar3,1);

  *puVar2 = uVar1;

  uVar1 = *(u32 *)(param_1 + 0x1a0);

  puVar2 = (u32 *)FUN_001a41b0(uVar3,2);

  *puVar2 = uVar1;

  uVar1 = *(u32 *)(param_1 + 0x1a4);

  puVar2 = (u32 *)FUN_001a41b0(uVar3,3);

  *puVar2 = uVar1;

  uVar1 = *(u32 *)(param_1 + 0x1a8);

  puVar2 = (u32 *)FUN_001a41b0(uVar3,4);

  *puVar2 = uVar1;

  *(u32 *)(param_1 + 0x16c) = 0;

  return uVar3;

}


// FUN_00385CD0


u32 FUN_00385cd0(int param_1)



{

  u32 uVar3;
  int iVar6;

  u32 *puVar1;

  int *piVar2;

  float fVar4;

  float fVar5;

  

  uVar3 = FUN_001a3ae0(*(u32 *)(param_1 + 0x92c),200,0x140);

  FUN_001a3dc0(uVar3, DAT_006a03f0_abs, 8);

  FUN_001a3bf0(uVar3,1);

  fVar5 = *(float *)(param_1 + 0x198);

  puVar1 = (u32 *)FUN_001a42f0(uVar3,0);

  *(float *)puVar1 = fVar5;

  fVar5 = *(float *)(param_1 + 0x19c);

  puVar1 = (u32 *)FUN_001a42f0(uVar3,1);

  *(float *)puVar1 = fVar5;

  fVar5 = *(float *)(param_1 + 0x1a0);

  puVar1 = (u32 *)FUN_001a42f0(uVar3,2);

  *(float *)puVar1 = fVar5;

  fVar5 = *(float *)(param_1 + 0x1a4);

  puVar1 = (u32 *)FUN_001a42f0(uVar3,3);

  *(float *)puVar1 = fVar5;

  fVar5 = *(float *)(param_1 + 0x1a8);

  puVar1 = (u32 *)FUN_001a42f0(uVar3,4);

  *(float *)puVar1 = fVar5;

  fVar5 = *(float *)(param_1 + 0x1ac);

  puVar1 = (u32 *)FUN_001a42f0(uVar3,5);

  *(float *)puVar1 = fVar5;

  iVar6 = (int)*(float *)(param_1 + 0x1b0);

  piVar2 = (int *)FUN_001a41b0(uVar3,6);

  *piVar2 = iVar6;

  iVar6 = (int)*(float *)(param_1 + 0x1b4);

  piVar2 = (int *)FUN_001a41b0(uVar3,7);

  *piVar2 = iVar6;

  return uVar3;

}


// FUN_00385E20


u32 FUN_00385e20(int param_1)



{

  u32 uVar1;

  u32 *puVar2;

  u32 uVar3;

  

  uVar3 = FUN_001a3ae0(*(u32 *)(param_1 + 0x92c),0xf0,0x80);

  FUN_001a3dc0(uVar3, DAT_006a0530_abs, 4);

  FUN_001a3bf0(uVar3,1);

  uVar1 = *(u32 *)(param_1 + 0x198);

  puVar2 = (u32 *)FUN_001a41b0(uVar3,0);

  *puVar2 = uVar1;

  uVar1 = *(u32 *)(param_1 + 0x19c);

  puVar2 = (u32 *)FUN_001a41b0(uVar3,1);

  *puVar2 = uVar1;

  uVar1 = *(u32 *)(param_1 + 0x1a0);

  puVar2 = (u32 *)FUN_001a41b0(uVar3,2);

  *puVar2 = uVar1;

  uVar1 = *(u32 *)(param_1 + 0x1a4);

  puVar2 = (u32 *)FUN_001a41b0(uVar3,3);

  *puVar2 = uVar1;

  return uVar3;

}


// FUN_00385F00


u32 FUN_00385f00(int param_1)


{

  int cVar1;

  int *piVar2;

  u32 uVar3;
  

  uVar3 = FUN_001a3ae0(*(u32 *)(param_1 + 0x92c),0xf0,0x80);

  FUN_001a3dc0(uVar3, DAT_006a05c0_abs, 1);

  FUN_001a3bf0(uVar3,1);

  cVar1 = *(char *)(param_1 + 0x44);

  piVar2 = (int *)FUN_001a41b0(uVar3,0);

  *piVar2 = (int)cVar1;

  return uVar3;

}


// FUN_00385F90


u32 FUN_00385f90(int param_1)



{

  u32 uVar1;

  u32 *puVar2;

  u32 uVar3;

  

  uVar3 = FUN_001a3ae0(*(u32 *)(param_1 + 0x92c),0xaa,300);

  FUN_001a3dc0(uVar3, DAT_006a0610_abs, 3);

  FUN_001a3bf0(uVar3,1);

  *(u32 *)(param_1 + 0x16c) = 6;

  uVar1 = *(u32 *)(param_1 + 0x198);

  puVar2 = (u32 *)FUN_001a41b0(uVar3,0);

  *puVar2 = uVar1;

  uVar1 = *(u32 *)(param_1 + 0x19c);

  puVar2 = (u32 *)FUN_001a41b0(uVar3,1);

  *puVar2 = uVar1;

  uVar1 = *(u32 *)(param_1 + 0x1a0);

  puVar2 = (u32 *)FUN_001a41b0(uVar3,2);

  *puVar2 = uVar1;

  return uVar3;

}


// FUN_00386060


u32 FUN_00386060(int param_1)


{

  u32 uVar1;

  u32 *puVar2;

  u32 uVar3;
  

  uVar3 = FUN_001a3ae0(*(u32 *)(param_1 + 0x92c),0xaa,300);

  FUN_001a3dc0(uVar3, DAT_006a0670_abs, 2);

  FUN_001a3bf0(uVar3,1);

  *(u32 *)(param_1 + 0x16c) = 7;

  uVar1 = *(u32 *)(param_1 + 0x198);

  puVar2 = (u32 *)FUN_001a41b0(uVar3,0);

  *puVar2 = uVar1;

  uVar1 = *(u32 *)(param_1 + 0x19c);

  puVar2 = (u32 *)FUN_001a41b0(uVar3,1);

  *puVar2 = uVar1;

  return uVar3;

}


// FUN_00386110


void FUN_00386110(u32 *param_1,u32 *param_2)



{

  *param_1 = (u32)(uintptr_t)DAT_009588a0_abs;
  *param_2 = (u32)(uintptr_t)DAT_00958890_abs;

  return;

}


// FUN_00386130


u32 FUN_00386130(int param_1,f32 *param_2,f32 *param_3)


{

  u32 uVar1;
  struct Vec3 { f32 x; f32 y; f32 z; };
  

  uVar1 = FUN_001a3ae0(*(u32 *)(param_1 + 0x92c),0xaa,300);

  FUN_001a3dc0(uVar1, DAT_006a06b0_abs, 1);

  FUN_001a3bf0(uVar1,1);

  *(u32 *)(param_1 + 0x16c) = 8;
  *(struct Vec3 *)DAT_009588a0_abs = *(struct Vec3 *)param_2;
  *(struct Vec3 *)DAT_00958890_abs = *(struct Vec3 *)param_3;


  return uVar1;

}


// FUN_00386210


void FUN_00386210(u32 *param_1,u32 *param_2)



{

  *param_1 = (u32)(uintptr_t)DAT_009588a0_abs;
  *param_2 = (u32)(uintptr_t)DAT_00958890_abs;

  return;

}


// FUN_00386230


u32 FUN_00386230(int param_1,u32 *param_2,u32 *param_3)



{

  u32 uVar1;
  struct Vec3 { f32 x; f32 y; f32 z; };

  

  uVar1 = FUN_001a3ae0(*(u32 *)(param_1 + 0x92c),0xaa,300);

  FUN_001a3dc0(uVar1, DAT_006a06d0_abs, 1);

  FUN_001a3bf0(uVar1,1);

  *(u32 *)(param_1 + 0x16c) = 0xc;

  *(struct Vec3 *)DAT_009588a0_abs = *(struct Vec3 *)param_2;

  *(struct Vec3 *)DAT_00958890_abs = *(struct Vec3 *)param_3;

  return uVar1;

}


// FUN_00386310


u32 FUN_00386310(int param_1)



{

  u32 uVar1;

  

  uVar1 = FUN_001a3ae0(*(u32 *)(param_1 + 0x92c),0x10,0x60);

  FUN_001a3dc0(uVar1, DAT_006a06f0_abs, 1);

  FUN_001a3bf0(uVar1,1);

  *(u32 *)(param_1 + 0x16c) = 9;

  return uVar1;

}


// FUN_00386390


void FUN_00386390(u32 *param_1,u32 *param_2,u32 *param_3,u32 *param_4)



{

  *param_1 = (u32)(uintptr_t)DAT_00958850_abs;

  *param_2 = (u32)(uintptr_t)&DAT_007ce60c;

  *param_3 = (u32)(uintptr_t)&DAT_007ce608;

  *param_4 = DAT_007ce604;

  return;

}


// FUN_003863C0


int FUN_003863c0(void)



{

  int iVar1;
  int iVar2;
  
  iVar1 = -1;
  for (iVar2 = 0; iVar2 < 2; iVar2 = iVar2 + 1) {
    if (FUN_001a4510(DAT_007ce600) == iVar2) {
      iVar1 = iVar2;
      break;
    }
  }


  return iVar1;

}
// FUN_00386430 NONMATCHING


u32 FUN_00386430(int param_1,u16 param_2,u32 param_3)
{

  u32 *puVar2;
  u32 uVar4;
  int iVar5;

  uVar4 = FUN_001a3ae0(*(u32 *)(param_1 + 0x92c),0x10,0x60);
  DAT_007ce600 = (u32)uVar4;
  FUN_001a3dc0(uVar4, DAT_006a0730_abs, 2);
  FUN_001a3bf0(uVar4,1);
  *(u32 *)(param_1 + 0x16c) = 10;
  DAT_007ce604 = FUN_001a41b0(uVar4,0);
  puVar2 = (u32 *)FUN_001a41b0(uVar4,0);
  *puVar2 = param_3;
  DAT_007ce60c = 0;
  {
    u16 *puVar3;
    u16 *table;
    puVar3 = (u16 *)FUN_003b5d50(3);
    table = (u16 *)DAT_00958850_abs;
    while (puVar3 != NULL) {
      s32 count;
      count = DAT_007ce60c;
      if (count >= 0x1e) {
        break;
      }
      table[count] = *puVar3;
      DAT_007ce60c = count + 1;
      puVar3 = *(u16 **)(puVar3 + 0x7c);
    }
  }

  {
    u16 *puVar3;
    u16 *table;
    puVar3 = (u16 *)FUN_003b5d50(1);
    table = (u16 *)DAT_00958850_abs;
    while (puVar3 != NULL) {
      s32 count;
      count = DAT_007ce60c;
      if (count >= 0x1e) {
        break;
      }
      table[count] = *puVar3;
      DAT_007ce60c = count + 1;
      puVar3 = *(u16 **)(puVar3 + 0x7c);
    }
  }

  DAT_007ce608 = 0;
  {
    u16 *table;
    s32 count;
    s32 selected;
    iVar5 = 0;
    selected = param_2;
    count = DAT_007ce60c;
    table = (u16 *)DAT_00958850_abs;
    while (iVar5 < count) {
      if (selected == table[iVar5] && selected != 0) {
        DAT_007ce608 = iVar5;
        break;
      }
      iVar5 = iVar5 + 1;
    }
  }

  return uVar4;
}


// FUN_003865F0


u32 FUN_003865f0(int param_1)



{

  s32 cVar1;

  int *piVar2;

  u32 uVar3;

  

  uVar3 = FUN_001a3ae0(*(u32 *)(param_1 + 0x92c),0xf0,0x80);

  FUN_001a3dc0(uVar3, DAT_006a0780_abs, 1);

  FUN_001a3bf0(uVar3,1);

  *(u32 *)(param_1 + 0x16c) = 0xb;

  cVar1 = *(s8 *)(param_1 + 0x45);

  piVar2 = (int *)FUN_001a41b0(uVar3,0);

  *piVar2 = cVar1;

  return uVar3;

}


// FUN_00386680


u32

FUN_00386680(int param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5

            )



{

  u32 *puVar1;

  u32 uVar2;

  

  uVar2 = FUN_001a3ae0(*(u32 *)(param_1 + 0x92c),0xbe,0x100);

  FUN_001a3dc0(uVar2, DAT_006a07e0_abs, 4);

  FUN_001a3bf0(uVar2,1);

  *(u32 *)(param_1 + 0x16c) = 0xd;

  puVar1 = (u32 *)FUN_001a41b0(uVar2,0);

  *puVar1 = param_2;

  puVar1 = (u32 *)FUN_001a41b0(uVar2,1);

  *puVar1 = param_3;

  puVar1 = (u32 *)FUN_001a41b0(uVar2,2);

  *puVar1 = param_4;

  puVar1 = (u32 *)FUN_001a41b0(uVar2,3);

  *puVar1 = param_5;

  return uVar2;

}


// FUN_00386780


u32 FUN_00386780(int param_1,u32 param_2,u32 param_3,u32 param_4)



{

  u32 *puVar1;

  u32 uVar2;

  

  uVar2 = FUN_001a3ae0(*(u32 *)(param_1 + 0x92c),0xbe,0x100);

  FUN_001a3dc0(uVar2, DAT_006a0890_abs, 3);

  FUN_001a3bf0(uVar2,1);

  *(u32 *)(param_1 + 0x16c) = 0xe;

  puVar1 = (u32 *)FUN_001a41b0(uVar2,0);

  *puVar1 = param_2;

  puVar1 = (u32 *)FUN_001a41b0(uVar2,1);

  *puVar1 = param_3;

  puVar1 = (u32 *)FUN_001a41b0(uVar2,2);

  *puVar1 = param_4;

  return uVar2;

}


// FUN_00386860


u32 FUN_00386860(int param_1,u32 param_2,u32 param_3,u32 param_4)



{

  u32 *puVar1;

  u32 uVar2;

  

  uVar2 = FUN_001a3ae0(*(u32 *)(param_1 + 0x92c),0xbe,0x100);

  FUN_001a3dc0(uVar2, DAT_006a0920_abs, 3);

  FUN_001a3bf0(uVar2,1);

  *(u32 *)(param_1 + 0x16c) = 0xf;

  puVar1 = (u32 *)FUN_001a41b0(uVar2,0);

  *puVar1 = param_2;

  puVar1 = (u32 *)FUN_001a41b0(uVar2,1);

  *puVar1 = param_3;

  puVar1 = (u32 *)FUN_001a41b0(uVar2,2);

  *puVar1 = param_4;

  return uVar2;

}


// FUN_00386940


u32 FUN_00386940(int param_1,int param_2,f32 param_3)



{

  u32 *puVar1;

  u32 uVar2;

  

  uVar2 = FUN_001a3ae0(*(u32 *)(param_1 + 0x92c),0xbe,0x100);

  FUN_001a3dc0(uVar2, DAT_006a0990_abs, 2);

  FUN_001a3bf0(uVar2,1);

  *(u32 *)(param_1 + 0x16c) = 0x10;

  puVar1 = (u32 *)FUN_001a41b0(uVar2,0);

  *puVar1 = param_2;

  puVar1 = (u32 *)FUN_001a42f0(uVar2,1);

  *(f32 *)puVar1 = param_3;

  return uVar2;

}


// FUN_00386A00


u32 FUN_00386a00(int param_1,u32 param_2)


{

  u32 *puVar1;

  u32 uVar2;
  

  uVar2 = FUN_001a3ae0(*(u32 *)(param_1 + 0x92c),0xbe,0x100);

  FUN_001a3dc0(uVar2, DAT_006a09f0_abs, 1);

  FUN_001a3bf0(uVar2,1);

  *(u32 *)(param_1 + 0x16c) = 0x11;

  puVar1 = (u32 *)FUN_001a41b0(uVar2,0);

  *puVar1 = param_2;

  return uVar2;

}


// FUN_00386AA0


void FUN_00386aa0(void)
{
  int iVar1;
  u32 *puVar2;

  iVar1 = 0;
  puVar2 = (u32 *)DAT_00958a60_abs;
  while (iVar1 < 0xd) {
    if (iVar1 != 0) {
      puVar2[iVar1] = 0;
    }
    iVar1 = iVar1 + 1;
  }
}

