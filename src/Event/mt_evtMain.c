#include "temporary.h"

typedef int code(...);
typedef struct {
  u64 xy;
  f32 z;
} EvtPosition65430;
typedef u8 bool;
#pragma alias FUN_00393e30_evt_main FUN_00393e30
extern void FUN_00393e30_evt_main(u32 param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5,code *(*param_6)(int));

extern u8 D_0069DFF0[];
extern u8 D_0069E088[];
extern u8 DAT_006a0000[];
#pragma alias DAT_006a0000_65430_abs DAT_006a0000
extern u8 DAT_006a0000_65430_abs[];
extern u8 DAT_0069ffd0[];
extern u8 DAT_0069dd98[];
extern u8 DAT_0069de20[];
extern int FUN_003b5d10(...);
void FUN_003969b0(int param_1);
#pragma alias FUN_003b55b0_evt_main FUN_003b55b0
extern u8 *FUN_003b55b0_evt_main(int param_1);
#pragma alias FUN_003b5d10_evt_main FUN_003b5d10
extern u8 *FUN_003b5d10_evt_main(u16 param_1);
#pragma alias FUN_0039f710_evt_main FUN_0039f710
extern u32 FUN_0039f710_evt_main(int *param_1);
#pragma alias FUN_003bb390_evt FUN_003bb390
extern void FUN_003bb390_evt(float param_1,u32 param_2);
extern u32 FUN_003b8e80(u32 param_1,float param_2,u32 param_3);
#pragma alias FUN_004c31b0_evt_main FUN_004c31b0
extern void FUN_004c31b0_evt_main(void *matrix, void *axis, f32 angle, s32 mode);
#pragma alias FUN_004c35d0_evt_main FUN_004c35d0
extern void FUN_004c35d0_evt_main(void *matrix, void *vector, s32 mode);
#pragma alias FUN_004c6c60_evt_main FUN_004c6c60
extern void FUN_004c6c60_evt_main(void *out, void *in, void *matrix);
/* W419 typed float + nested call: FUN_0036db20 nd 927 -> 869, object 1564 -> 1560. */
extern f32 FUN_001a4600(u32 param_1);
#pragma alias FUN_003bb010_evt_main FUN_003bb010
extern void FUN_003bb010_evt_main(u16 param_1,u8 param_2);
#pragma alias FUN_003bb1d0_evt_main FUN_003bb1d0
extern void FUN_003bb1d0_evt_main(u16 param_1,s32 param_2,u8 param_3,s8 param_4,s8 param_5);
extern u32 DAT_0069d590;
#pragma alias DAT_0069d590_abs DAT_0069d590
extern s8 DAT_0069d590_abs[];
#pragma alias DAT_0069d580_abs DAT_0069d580
extern s8 DAT_0069d580_abs[];
#pragma alias DAT_0069e068_abs DAT_0069e068
extern s8 DAT_0069e068_abs[];
#pragma alias DAT_0069e078_abs DAT_0069e078
extern s8 DAT_0069e078_abs[];
typedef struct {
  u8 pad_00[0x80];
  s32 count;
  int *head;
  int *tail;
} MtEvtNodeList;
#pragma alias mtEvtInsertPriorityNode FUN_00361b60
extern void mtEvtInsertPriorityNode(int *node, MtEvtNodeList *list);
#pragma alias mtEvtCreateMainTask FUN_0036f3b0
extern void mtEvtCreateMainTask(u64 taskArg,u32 mode);
extern u32 DAT_0069d5c8;
extern u32 DAT_0069d5d0;
extern u32 DAT_0069d5d8;
extern u32 DAT_0069d5e0;
extern u32 DAT_0069d5e8;
extern u32 DAT_0069d5f0;
#pragma alias DAT_0069d5c8_abs DAT_0069d5c8
extern u8 DAT_0069d5c8_abs[];
#pragma alias DAT_0069d5d0_abs DAT_0069d5d0
extern u8 DAT_0069d5d0_abs[];
#pragma alias DAT_0069d5d8_abs DAT_0069d5d8
extern u8 DAT_0069d5d8_abs[];
#pragma alias DAT_0069d5e0_abs DAT_0069d5e0
extern u8 DAT_0069d5e0_abs[];
#pragma alias DAT_0069d5e8_abs DAT_0069d5e8
extern u8 DAT_0069d5e8_abs[];
#pragma alias DAT_0069d5f0_abs DAT_0069d5f0
extern u8 DAT_0069d5f0_abs[];
extern u32 DAT_0069d5f8;
extern u32 DAT_0069d600;
extern u32 DAT_0069d608;
extern u32 DAT_0069d610;
extern u32 DAT_0069d618;
extern u32 DAT_0069d620;
extern u32 DAT_0069d628;
extern u32 DAT_0069d630;
#pragma alias DAT_0069d5f8_abs DAT_0069d5f8
#pragma alias DAT_0069d600_abs DAT_0069d600
#pragma alias DAT_0069d608_abs DAT_0069d608
#pragma alias DAT_0069d610_abs DAT_0069d610
#pragma alias DAT_0069d618_abs DAT_0069d618
#pragma alias DAT_0069d620_abs DAT_0069d620
#pragma alias DAT_0069d628_abs DAT_0069d628
#pragma alias DAT_0069d630_abs DAT_0069d630
extern u8 DAT_0069d5f8_abs[];
extern u8 DAT_0069d600_abs[];
extern u8 DAT_0069d608_abs[];
extern u8 DAT_0069d610_abs[];
extern u8 DAT_0069d618_abs[];
extern u8 DAT_0069d620_abs[];
extern u8 DAT_0069d628_abs[];
extern u8 DAT_0069d630_abs[];
extern f32 FUN_001a1190(void);
extern u64 DAT_0069d6e8;
extern f32 DAT_0069d6f0;
extern u8 DAT_0069d580[];
extern u8 DAT_0069d7a0[];
#pragma alias DAT_0069d6e8_abs DAT_0069d6e8
#pragma alias DAT_0069d6f0_abs DAT_0069d6f0
extern u64 DAT_0069d6e8_abs[];
extern f32 DAT_0069d6f0_abs[];
#pragma alias DAT_0069d700_abs DAT_0069d700
#pragma alias DAT_0069d720_abs DAT_0069d720
extern u8 DAT_0069d700_abs[];
extern u8 DAT_0069d720_abs[];
#pragma alias DAT_0069d738_abs DAT_0069d738
extern u8 DAT_0069d738_abs[];
#pragma alias DAT_0069d748_abs DAT_0069d748
extern u8 DAT_0069d748_abs[];
extern u8 DAT_0069d910;
extern u32 DAT_0069de40;
extern u32 DAT_0069e180;
extern u32 DAT_0069e1a0;
extern u32 DAT_0069e1a2;
#pragma alias DAT_0069e1a2_byte DAT_0069e1a2
extern char DAT_0069e1a2_byte[];
extern u32 DAT_0069e1aa;
extern u32 DAT_0069e420;
extern u32 DAT_0069e422;
extern u32 DAT_006a0270;
extern u32 DAT_006a0bf8;
extern u32 DAT_006a0c00;
extern u32 DAT_007cadc0;
extern u32 DAT_007cadd0;
extern u32 DAT_007cae18;
extern u32 DAT_007cafec;
extern u32 DAT_007cb0cc;
extern u32 DAT_007cb110;
extern u32 DAT_007cb120;
extern u32 DAT_007cb124;
extern u32 DAT_007cca68;
extern u32 DAT_007cca6c;
extern u32 DAT_007ccd20;
extern u32 DAT_007cce48;
extern u32 DAT_007cce4c;
extern u32 DAT_007cce78;
extern u32 DAT_007ccf94;
extern u32 DAT_007cd130;
extern u32 DAT_007cdeac;
extern u32 DAT_007ce5d8;
extern int DAT_007ce5e4;
extern u32 DAT_007ce5e8;
extern u32 DAT_007ce5ec;
extern u32 DAT_007ce5f0;
extern u32 DAT_007ce5f4;
extern u32 DAT_007ce5f8;
extern u32 DAT_007ce5fc;
extern u32 DAT_007ce600;
extern u32 DAT_007ce604;
extern u32 DAT_007ce608;
extern u32 DAT_007ce60c;
extern u32 DAT_007e094c;
extern u32 DAT_007e094e;
#pragma alias DAT_007e094e_abs DAT_007e094e
extern u8 DAT_007e094e_abs[];
extern u32 DAT_007e0952;
#pragma alias DAT_007e094c_2390 DAT_007e094c
extern u8 DAT_007e094c_2390[];
#pragma alias DAT_007e0952_2390 DAT_007e0952
extern u8 DAT_007e0952_2390[];
extern u32 DAT_007e095e;
extern u32 DAT_007e095f;
extern u32 DAT_007e0960;
extern u32 DAT_007e0961;
#pragma alias DAT_007e094c_628f0_abs DAT_007e094c
#pragma alias DAT_007e0952_628f0_abs DAT_007e0952
#pragma alias DAT_007e095e_628f0_abs DAT_007e095e
#pragma alias DAT_007e095f_628f0_abs DAT_007e095f
#pragma alias DAT_007e0960_628f0_abs DAT_007e0960
#pragma alias DAT_007e0961_628f0_abs DAT_007e0961
extern u8 DAT_007e094c_628f0_abs[];
extern u8 DAT_007e0952_628f0_abs[];
extern u8 DAT_007e095e_628f0_abs[];
extern u8 DAT_007e095f_628f0_abs[];
extern u8 DAT_007e0960_628f0_abs[];
extern u8 DAT_007e0961_628f0_abs[];
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
extern u32 DAT_009585bc;
extern u32 DAT_009585c0;
extern u32 DAT_009585d0;
extern u32 DAT_00958700;
#pragma alias DAT_00958700_abs DAT_00958700
extern u8 DAT_00958700_abs[];
extern u32 DAT_00958704;
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
extern u32 DAT_00958850;
extern u32 DAT_00958890;
extern u32 DAT_00958894;
extern u32 DAT_00958898;
extern u32 DAT_009588a0;
extern u32 DAT_009588a4;
extern u32 DAT_009588a8;
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
extern u32 DAT_00960090;
extern u32 DAT_009600a0;
extern u32 DAT_0096017c;
extern u32 DAT_00960184;
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
extern u8 *PTR_s_CREATE_0069da70;
extern u8 *PTR_s_CREATE_0069ee30;
extern u8 *PTR_s_DELETE_0069ee38;
extern u8 *PTR_s_DIRECT_0069e9c0;
extern u8 *PTR_s_DIRECT_0069f9a0;
extern u8 *PTR_s_DIRECT_0069fa88;
extern u8 *PTR_s_DIRECT_007ccda0;
extern u8 *PTR_s_DIRECT_007cd258;
extern u8 *PTR_s_DISABLE_0069e6c8;
extern u8 *PTR_s_DISPONOFF_007ccaa8;
extern u8 *PTR_s_FADEOUT_0069ee14;
extern u8 *PTR_s_FADEOUT_WAIT_007ccf9c;
extern u8 *PTR_s_FADE_IN_007cce88;
extern u8 *PTR_s_FALSE_007ccdb8;
extern u8 *PTR_s_GAKURYOKU_0069feb0;
extern u8 *PTR_s_HAMETU_006a01cc;
extern u8 *PTR_s_HIRU_SASO_0069d880;
extern u8 *PTR_s_KAIKIN_006a01c0;
extern u8 *PTR_s_KEYFREE_007ccfbc;
extern u8 *PTR_s_KUCHI_0069ee18;
extern u8 *PTR_s_LENGTH_007cd22c;
extern u8 *PTR_s_L_FLAG_NOTUSE_0069e990;
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
extern u8 *PTR_s_RELEASE_0069ee28;
extern u8 *PTR_s_REPEAT_007ccd88;
extern u8 *PTR_s_REVERSE_006a01c8;
extern u8 *PTR_s_SAVE_PROJ_;
extern u8 *PTR_s_SOUTAI_007ccd78;
extern u8 *PTR_s_SPEED_007cd228;
extern u8 *PTR_s_START_0069e100;
extern u8 *PTR_s_START_0069ee24;
extern u8 *PTR_s_START_007ccf50;
extern u32 fGpffff80d0;
extern u32 fGpffff8294;
extern u32 fGpffff8438;
extern u8 gp0xffff9d98;
extern u8 gp0xffff9db8;
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
extern u8 gp0xffffa3b8;
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
#pragma alias s_FIELD_EDIT_GO_abs s_FIELD_EDIT_GO__0069ddc0
extern u8 s_FIELD_EDIT_GO_abs[];
 
extern char *s_FIELD_EFFECT_MODE_0069dbf0;
extern char *s_FRAME_SET_OK__0069dda8;
#pragma alias s_FRAME_SET_OK_abs s_FRAME_SET_OK__0069dda8
extern u8 s_FRAME_SET_OK_abs[];
 
extern char *s_HOKAN_MODE_0069db48;
extern char *s_KEYFREE_SELECT_0069dd20;
extern char *s_KOMA_MODE_0069dc28;
extern char *s_MESSAGE_STOP_0069dd08;
extern char *s_MESSAGE_TYPE_0069de08;
#pragma alias s_MESSAGE_TYPE_abs s_MESSAGE_TYPE_0069de08
extern u8 s_MESSAGE_TYPE_abs[];
 
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
#pragma alias s_VOICE_FILE_LOAD_abs s_VOICE_FILE_LOAD__0069ddd0
extern u8 s_VOICE_FILE_LOAD_abs[];
 
extern char *s_WAIT_MODE_SELECT_0069dcf0;
#pragma alias s_BATTLE_BLUR_USE_abs s_BATTLE_BLUR_USE__0069ddf0
extern u8 s_BATTLE_BLUR_USE_abs[];
extern u32 uGpffff841c;
#pragma alias fGpffff841c_evt uGpffff841c
extern f32 fGpffff841c_evt;
extern s16 uGpffff9d78;
extern s16 uGpffff9d7c;
extern u32 uGpffffa4b8;
extern u32 uGpffffa4bc;
extern u32 uGpffffa628;
extern u32 uGpffffa62c;
extern u32 uGpffffa650;
extern u32 uGpffffa654;
extern u32 uGpffffb8ec;
extern u32 uGpffffb900;
extern u32 uGpffffb924;

bool FUN_0036d320(int param_1);
bool FUN_0036f480(void);
bool FUN_00372c40(u64 param_1);
code * FUN_0036d500(void);
code * FUN_0036d5f0(void);
code * FUN_0036e140(int param_1);
code * FUN_0036e690(int param_1);
code * FUN_0036ed30(int param_1);
code * FUN_0036edd0(void);
code * FUN_0036ee30(void);
float FUN_0038a220(int param_1);
float FUN_0038a900(int param_1);
u8 FUN_003b86c0(f32 param_1, u32 param_2, u32 param_3);
u32 FUN_003b8730(f32 param_1, u16 param_2, void *param_3);
u32 FUN_003b89f0(f32 param_1, u16 param_2, char *param_3, u32 param_4);
int FUN_00361830(int param_1);
int FUN_00361ee0(int param_1,int param_2);
int FUN_00361f20(int param_1);
int FUN_00361f60(int param_1,int param_2);
int FUN_00361fe0(int param_1,int param_2);
int FUN_0036be60(u64 param_1,int param_2,int param_3);
int FUN_0036fda0(u64 param_1,u64 param_2,u64 param_3);
int FUN_00371dd0(u64 param_1,u64 param_2,u64 param_3);
int FUN_00372790(u64 param_1,u64 param_2,u64 param_3);
int FUN_00375000(u64 param_1,u64 param_2,u64 param_3);
int FUN_0037caf0(u64 param_1,u64 param_2,u64 param_3);
int FUN_0037d5d0(u64 param_1,u64 param_2,u64 param_3);
int FUN_0037e1b0(u64 param_1,u64 param_2,u64 param_3);
int FUN_0037ead0(u64 param_1,u64 param_2,u64 param_3);
int FUN_0037f3d0(u64 param_1,u64 param_2,u64 param_3);
int FUN_0037fae0(u64 param_1,u64 param_2,u64 param_3);
int FUN_00380200(u64 param_1,u64 param_2,u64 param_3);
int FUN_003806f0(u64 param_1,u64 param_2,u64 param_3);
int FUN_00380d70(u64 param_1,u64 param_2,u64 param_3);
int FUN_00381280(u64 param_1,u64 param_2,u64 param_3);
int FUN_003819b0(u64 param_1,u64 param_2,u64 param_3);
int FUN_003820e0(u64 param_1,u64 param_2,u64 param_3);
int FUN_00382500(u64 param_1,u64 param_2,u64 param_3);
int FUN_00382840(u64 param_1,u64 param_2,u64 param_3);
int FUN_00382d60(u64 param_1,u64 param_2,u64 param_3);
int FUN_00383360(u64 param_1,u64 param_2,u64 param_3);
int FUN_00383d80(u64 param_1,u64 param_2,u64 param_3);
int FUN_00384370(u64 param_1,u64 param_2,u64 param_3);
int FUN_00384780(u64 param_1,u64 param_2,u64 param_3);
int FUN_00385520(u64 param_1,u64 param_2,u64 param_3);
int FUN_003863c0(void);
int FUN_00388df0(int param_1,int param_2);
int FUN_00361ca0(int param_1,int param_2);
u32 FUN_00361350(int *param_1,int param_2,int param_3);
u32 FUN_00361dd0(int param_1,u32 param_2,u16 param_3,u32 param_4);
long FUN_00374af0(u64 param_1,u64 param_2,u64 param_3);
#pragma alias FUN_00386ae0_evt FUN_00386ae0
extern u32 FUN_00386ae0_evt(u32 param_1,u32 param_2);
long FUN_00386ae0(u64 param_1,u64 param_2);
#pragma alias FUN_0038c540_evt FUN_0038c540
extern void FUN_0038c540_evt(int param_1,int param_2,int param_3,u32 param_4,u32 *param_5,u32 *param_6);
#pragma alias FUN_003b5d10_evt FUN_003b5d10
#pragma alias FUN_003b8310_evt FUN_003b8310
extern u32 FUN_003b8310_evt(u16 param_1,int param_2);
extern u32 FUN_003b5d10_evt(u32 param_1);
#pragma alias FUN_00360ed0_evt FUN_00360ed0
extern u32 FUN_00360ed0_evt(u32 param_1);
#pragma alias FUN_003b9550_evt FUN_003b9550
extern void FUN_003b9550_evt(u32 param_1,u32 param_2);
#pragma alias FUN_00388df0_evt FUN_00388df0
extern u32 FUN_00388df0_evt(u32 param_1,u32 *param_2);
#pragma alias FUN_003b8ff0_evt FUN_003b8ff0
extern u32 FUN_003b8ff0_evt(float param_1,u32 param_2,u32 param_3,u16 param_4,u16 param_5,u32 param_6,u32 param_7);
#pragma alias FUN_003b9260_evt FUN_003b9260
extern u32 FUN_003b9260_evt(float param_1,u32 param_2,u32 param_3,u16 param_4,u16 param_5,u32 param_6,u32 param_7);
#pragma alias FUN_003b8ff0_evt_wide FUN_003b8ff0
extern u32 FUN_003b8ff0_evt_wide(float param_1,u32 param_2,u32 param_3,s32 param_4,s32 param_5,u32 param_6,s32 param_7);
#pragma alias FUN_003b9260_evt_wide FUN_003b9260
extern u32 FUN_003b9260_evt_wide(float param_1,u32 param_2,u32 param_3,s32 param_4,s32 param_5,u32 param_6,s32 param_7);
#pragma alias FUN_003b8e10_evt FUN_003b8e10
extern u64 FUN_003b8e10_evt(u16 param_1,u8 param_2,short param_3,u32 param_4);
u64 FUN_003952d0(u64 param_1,int param_2,s16 param_3);
u64 FUN_003952b0(u64 param_1,int param_2);
u64 FUN_003952a0(u64 param_1,int param_2);
u32 FUN_00397870(int param_1,long param_2,u32 *param_3,u32 *param_4,u32 *param_5,u32 *param_6);
void FUN_00396f50(int param_1);
u32 FUN_00396c70(int param_1,int param_2,int param_3,long param_4,long param_5,long param_6,long param_7,float param_8);
long FUN_0038ab00(int param_1,u64 param_2);
short FUN_0036f640(int param_1);
#pragma alias FUN_0036f640_evt FUN_0036f640
extern int FUN_0036f640_evt(int param_1);
u16 * FUN_00362290(int param_1);
u16 * FUN_00362310(int param_1);
u16 * FUN_00364470(u32 param_1,int param_2);
u16 * FUN_003645c0(u32 param_1,int param_2);
u16 * FUN_003646d0(u32 param_1,int param_2);
u16 * FUN_00364b10(u32 param_1,int param_2);
u16 * FUN_003655f0(u32 param_1,int param_2,int param_3);
u16 * FUN_00366540(u32 param_1,int param_2,int param_3,int param_4);
#pragma alias FUN_00366540_evt_u32 FUN_00366540
extern u32 FUN_00366540_evt_u32(u32 param_1,int param_2,int param_3,int param_4);
u32 FUN_00368d70(u64 param_1,u64 param_2,int param_3);
u32 FUN_0036d470(int param_1);
u32 FUN_0036da10(int param_1);
u32 FUN_0036db20(int param_1);
u32 FUN_0036e260(int param_1);
u32 FUN_0036e2f0(int param_1);
u32 FUN_0036f4c0(void);
u32 FUN_00370230(int param_1,int param_2,int param_3);
u32 FUN_00371710(int param_1,int param_2,int param_3);
u32 FUN_00372260(int param_1,int param_2,int param_3);
u32 FUN_00373700(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_00374c90(int param_1,int param_2,int param_3);
u32 FUN_00375350(int param_1,int param_2,int param_3);
u32 FUN_00375590(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_003756e0(int param_1,int param_2,int param_3);
u32 FUN_00375900(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_00375a40(int param_1,int param_2,int param_3);
u32 FUN_00375d70(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_00375f30(int param_1,int param_2,int param_3);
u32 FUN_003798f0(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_0037a150(int param_1,int param_2,int param_3);
u32 FUN_0037a2b0(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_0037a4d0(int param_1,int param_2,int param_3);
u32 FUN_0037acc0(int param_1,int param_2,int param_3);
u32 FUN_0037afc0(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_0037b2e0(int param_1,int param_2,int param_3);
u32 FUN_0037b5d0(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_0037ba80(int param_1,int param_2,int param_3);
u32 FUN_0037be50(u64 param_1,u64 param_2,u64 param_3);
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
u32 FUN_00384d30(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_003851f0(int param_1,int param_2,int param_3);
u32 FUN_00386cd0(void);
u32 FUN_00386e10(int param_1);
u32 FUN_00386e30(int param_1);
u32 FUN_0038a0b0(int param_1);
u32 FUN_0038a4b0(u32 param_1,int param_2,u32 *param_3,u32 *param_4);
u32 FUN_0038d6f0(long param_1);
u32 FUN_0038d980(void);
u32 FUN_0038e860(long param_1,u64 param_2);
#pragma alias FUN_0038e860_i FUN_0038e860
extern u32 FUN_0038e860_i(int param_1,int param_2);
u32 FUN_003670f0(int param_1,int param_2,int param_3);
u64 FUN_00366f90(u64 param_1,u64 param_2,u32 param_3);
u32 FUN_00367190(int param_1,int param_2,int param_3);
u32 FUN_00367440(int param_1,int param_2,int param_3);
u64 FUN_00367230(u64 param_1,u64 param_2,int param_3);
u64 FUN_003674b0(u64 param_1,u64 param_2,u32 *param_3);
u64 FUN_00367a20(u64 param_1,u64 param_2,int param_3);
u64 FUN_00367cb0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00367d70(u64 param_1,u64 param_2,int param_3);
u64 FUN_00367e00(u64 param_1,u64 param_2,int param_3);
u64 FUN_00367ec0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00368020(u64 param_1,u64 param_2,int param_3);
u64 FUN_003680e0(u64 param_1,u64 param_2,int param_3);
u64 FUN_003682f0(u64 param_1,u64 param_2,int param_3);
u64 FUN_003683a0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00368440(u64 param_1,u64 param_2,int param_3);
u64 FUN_003684d0(u64 param_1,u64 param_2,int param_3,int param_4);
u64 FUN_003685c0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00368680(u64 param_1,u64 param_2,int param_3);
u32 FUN_00368710(int param_1,int param_2,int param_3);
u64 FUN_003687b0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00368830(u64 param_1,u64 param_2,int param_3);
u64 FUN_003688d0(u64 param_1,u64 param_2,int param_3,int param_4);
u32 FUN_003689c0(int param_1,int param_2,int param_3);
u64 FUN_00368a30(u64 param_1,u64 param_2,int param_3,int param_4);
u64 FUN_00368b00(u64 param_1,int param_2,int param_3);
u64 FUN_00368c10(u64 param_1,u64 param_2,int param_3);
u64 FUN_00368cb0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00368f20(u64 param_1,int param_2,u8 *param_3);
u64 FUN_00369320(u64 param_1,int param_2,u64 param_3);
u32 FUN_003698a0(u64 param_1,u64 param_2,int param_3);
u64 FUN_00369a20(int param_1,u64 param_2,int param_3);
u64 FUN_0036be10(u64 param_1,u64 param_2,u32 param_3);
u64 FUN_0036cc30(u64 param_1,u64 param_2,u8 *param_3);
u64 FUN_0036f500(long param_1);
#pragma alias FUN_0036f500_s32 FUN_0036f500
extern s32 FUN_0036f500_s32(long param_1);
u64 FUN_003709d0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_003715b0(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_00379f30(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_0037a640(u64 param_1,u64 param_2,u64 param_3);
u64 FUN_0037abd0(u64 param_1,u64 param_2,u64 param_3);
u32 FUN_00385bd0(int param_1,u64 param_2);
u32 FUN_00385cd0(int param_1);
u32 FUN_00385e20(int param_1);
u32 FUN_00385f00(int param_1);
u32 FUN_00385f90(int param_1);
u32 FUN_00386060(int param_1);
u32 FUN_00386130(int param_1,u32 *param_2,u32 *param_3);
u32 FUN_00386230(int param_1,u32 *param_2,u32 *param_3);
u32 FUN_00386310(int param_1);
u64 FUN_00386430(int param_1,short param_2,u32 param_3);
u32 FUN_003865f0(int param_1);
u32 FUN_00386780(int param_1,u32 param_2,u32 param_3,u32 param_4);
u32 FUN_00386860(int param_1,u32 param_2,u32 param_3,u32 param_4);
u32 FUN_00386940(u32 param_1,int param_2,u32 param_3);
u32 FUN_00386a00(int param_1,u32 param_2);
u64 FUN_0038da10(u16 *param_1);
s8 FUN_0036fa40(int param_1);
#pragma alias FUN_0036fa40_wide FUN_0036fa40
extern s32 FUN_0036fa40_wide(int param_1);
u8 FUN_00373590(u64 param_1,u64 param_2,u64 param_3);
void FUN_00361050(int param_1,u32 param_2);
void FUN_00361070(int param_1);
void FUN_00361140(u8 *param_1,u16 *param_2);
#pragma alias FUN_00361140_raw FUN_00361140
extern void FUN_00361140_raw();
void FUN_00361200(int param_1,int param_2);
void FUN_00361270(int param_1);
void FUN_00361890(int *param_1,int param_2);
void FUN_00361980(int param_1);
void FUN_00361b60(int *param_1,int param_2);
void FUN_00361c30(int param_1,int param_2);
void FUN_00361d60(int param_1,u16 param_2,u32 param_3);
void FUN_00362100(void);
void FUN_00362110(void);
void FUN_00362120(int param_1,int param_2,int param_3);
#pragma alias FUN_00362120_evt FUN_00362120
extern void FUN_00362120_evt(int param_1,int param_2,int param_3);
void FUN_00362240(int param_1);
void FUN_00362390(int param_1);
void FUN_003625e0(void);
void FUN_003628f0(void);
void FUN_00362f20(int param_1);
void FUN_00362fa0(int param_1);
void FUN_00362ff0(int param_1);
void FUN_00363030(int *param_1,u16 *param_2,u32 param_3,u8 *param_4);
void FUN_003638e0(int *param_1,int param_2,int param_3,u32 param_4,int param_5);
void FUN_003648e0(int param_1,u32 param_2,int param_3);
void FUN_00364a30(u32 param_1,int param_2);
void FUN_00364e40(u32 param_1,int param_2,int param_3);
void FUN_003650c0(int param_1,u64 param_2,int param_3);
void FUN_00365250(u32 param_1,u64 param_2,int param_3);
void FUN_00365360(u32 param_1,u64 param_2,int param_3);
#pragma alias FUN_003650c0_i FUN_003650c0
#pragma alias FUN_00365250_i FUN_00365250
#pragma alias FUN_00365360_i FUN_00365360
extern void FUN_003650c0_i(int param_1,int param_2,int param_3);
extern void FUN_00365250_i(u32 param_1,int param_2,int param_3);
extern void FUN_00365360_i(u32 param_1,int param_2,int param_3);
void FUN_00365430(int param_1,int param_2);
void FUN_003657e0(int param_1,int param_2);
void FUN_003658b0(u32 param_1,int param_2);
void FUN_00365a40(u32 param_1,int param_2);
void FUN_00365b70(u32 param_1,u32 param_2);
void FUN_00365cd0(u32 param_1,int param_2);
void FUN_00365f80(u32 param_1,u32 param_2);
void FUN_00366210(u32 param_1,int param_2);
void FUN_00366330(u32 param_1,int param_2);
void FUN_003663f0(u32 param_1,int param_2);
void FUN_00366660(u32 param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5);
void FUN_00366970(u32 param_1,u32 param_2);
void FUN_00366ac0(u32 param_1,u32 param_2);
void FUN_0036d030(int param_1);
void FUN_0036efb0(void);
void FUN_0036f000(int param_1);
void FUN_0036f260(void);
void FUN_0036f370(int param_1);
void FUN_0036f3b0(u64 param_1,u32 param_2);
void FUN_0036f490(int param_1);
void FUN_0036f4d0(void);
void FUN_0036f5f0(u32 param_1,u16 param_2,u16 param_3,int param_4);
void FUN_0036f680(long param_1,long param_2,int param_3,int param_4,u64 param_5, u16 param_6,u16 param_7);
void FUN_0036f900(u64 param_1,int param_2,int param_3,int param_4,int param_5, u64 param_6,u64 param_7,long param_8,code *param_9);
void FUN_0036fa80(int param_1,int param_2,int param_3,int param_4);
void FUN_003702a0(int param_1,int param_2,int param_3,u64 param_4);
void FUN_00371350(int param_1,int param_2,int param_3,int param_4);
void FUN_00371790(u64 param_1,u64 param_2,u32 param_3);
void FUN_003722d0(u64 param_1,u64 param_2,u32 param_3);
void FUN_003747a0(int param_1,int param_2,int param_3,u64 param_4);
void FUN_00374d30(u64 param_1,u64 param_2,u32 param_3);
void FUN_003753c0(u64 param_1,u64 param_2,u32 param_3);
void FUN_00375750(u64 param_1,u64 param_2,u32 param_3);
void FUN_00375ab0(u64 param_1,u64 param_2,u32 param_3);
void FUN_003760a0(int param_1,int param_2,u32 param_3,u16 *param_4,int param_5);
void FUN_003797b0(u64 param_1,u64 param_2,int param_3,int param_4);
void FUN_00379c30(int param_1,int param_2,int param_3,int param_4);
void FUN_0037a1e0(int param_1,int param_2,int param_3,int param_4);
void FUN_0037a560(int param_1,int param_2,int param_3,int param_4);
void FUN_0037a790(int param_1,int param_2,int param_3,u64 param_4);
void FUN_0037ad30(int param_1,int param_2,int param_3,int param_4);
void FUN_0037b350(int param_1,int param_2,int param_3,int param_4);
void FUN_0037baf0(int param_1,int param_2,int param_3,u64 param_4);
void FUN_0037c350(int param_1,int param_2,int param_3,u64 param_4);
void FUN_0037cf50(u32 *param_1,u32 *param_2,u32 *param_3);
void FUN_0037cfe0(void);
void FUN_0037d540(int param_1,int param_2,long param_3,int param_4);
void FUN_0037dfc0(int param_1,int param_2,int param_3,u64 param_4);
void FUN_0037e460(u64 param_1,u64 param_2,u32 param_3);
void FUN_0037f0c0(int param_1,int param_2,int param_3,int param_4);
void FUN_0037f650(u64 param_1,u64 param_2,u32 param_3);
void FUN_0037ff80(int param_1,int param_2,int param_3,u64 param_4);
void FUN_00380380(u64 param_1,u64 param_2,u32 param_3);
void FUN_00380a30(int param_1,int param_2,int param_3,int param_4);
void FUN_00381110(int param_1,int param_2,int param_3,int param_4);
void FUN_00381540(u64 param_1,u64 param_2,u32 param_3);
void FUN_00381c60(u64 param_1,u64 param_2,u32 param_3);
void FUN_00382390(int param_1,int param_2,int param_3,int param_4);
void FUN_00382760(int param_1,int param_2,int param_3,int param_4);
void FUN_00382c80(int param_1,int param_2,int param_3,int param_4);
void FUN_00382f30(int param_1,int param_2,int param_3,u64 param_4);
void FUN_00383880(int param_1,int param_2,int param_3,u64 param_4);
void FUN_003840d0(int param_1,int param_2,int param_3,u64 param_4);
void FUN_00384520(int param_1,int param_2,int param_3,u64 param_4);
void FUN_00384a50(int param_1,int param_2,int param_3,u64 param_4);
void FUN_00385260(int param_1,int param_2,int param_3,u64 param_4);
void FUN_003858c0(void);
void FUN_00385990(u32 param_1,int param_2,int param_3,int param_4,u32 param_5, u32 param_6);
void FUN_00385b20(int param_1);
void FUN_00385b90(void);
#pragma alias FUN_00385b90_evt_main FUN_00385b90
extern void FUN_00385b90_evt_main(u32 param_1);
void FUN_00385ba0(void);
void FUN_00386110(u32 *param_1,u32 *param_2);
void FUN_00386210(u32 *param_1,u32 *param_2);
void FUN_00386390(u32 *param_1,u32 *param_2,u32 *param_3,u32 *param_4);
void FUN_00386aa0(void);
void FUN_00386b70(int param_1,int param_2,int param_3);
#pragma alias FUN_00386b70_evt_main FUN_00386b70
extern void FUN_00386b70_evt_main(int param_1,int param_2,int param_3);
#pragma alias FUN_005225a8_evt_main FUN_005225a8
extern void FUN_005225a8_evt_main(void *param_1);
#pragma alias FUN_00195020_evt_main FUN_00195020
extern void FUN_00195020_evt_main(u32 param_1);
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
void FUN_00389d80(u64 param_1,u64 param_2);
void FUN_00389f40(void);
void FUN_0038a0c0(int param_1,int param_2);
extern void FUN_001a4580(int param_1,float param_2);
void FUN_0038a140(u32 param_1,u32 *param_2);
void FUN_0038a180(int param_1,int param_2);
void FUN_0038a260(u32 param_1,int param_2,int param_3,int param_4,u32 param_5, u64 param_6,u64 param_7,u64 param_8,u64 param_9);
void FUN_0038a590(int param_1,long param_2);
void FUN_0038a620(int param_1,long param_2);
void FUN_0038a6c0(int param_1);
void FUN_0038a730(int param_1);
void FUN_0038a7c0(u32 *param_1,u32 *param_2);
void FUN_0038a920(int param_1,u16 *param_2,int param_3);
void FUN_0038af70(u16 *param_1);
void FUN_0038b140(long param_1);
void FUN_0038b2c0(u16 *param_1,u32 *param_2,u32 *param_3,u64 param_4, long param_5);
void FUN_0038b550(long param_1,u64 param_2,u64 param_3,u64 param_4);
void FUN_0038b600(u32 *param_1,u32 *param_2);
void FUN_0038b6e0(u64 param_1,int param_2,int param_3);
void FUN_0038b960(int param_1,long param_2,short param_3);
void FUN_0038bc70(int param_1,short param_2,int param_3);
void FUN_0038c460(long param_1,int param_2,int *param_3,u32 *param_4);
void FUN_0038c540(int param_1,u64 param_2,u64 param_3,u64 param_4, u32 *param_5,u32 *param_6);
void FUN_0038c830(u64 param_1,long param_2);
#pragma alias FUN_00362290_2390 FUN_00362290
extern u16 *FUN_00362290_2390();
#pragma alias FUN_00362310_2390 FUN_00362310
extern u16 *FUN_00362310_2390();
#pragma alias FUN_0038c830_2390 FUN_0038c830
extern void FUN_0038c830_2390(int param_1,int param_2);
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











// FUN_00361350 NONMATCHING


u32 FUN_00361350(int *param_1,int param_2,int param_3)



{

  u32 uVar1;

u32 lVar2;

  int *piVar3;

u32 lVar4;

  u16 *puVar5;

  int iVar6;

  u8 auStack_60[0x20];

  u32 uStack_4;

  u32 uStack_8;

  

  lVar4 = 0;

  piVar3 = param_1;

  iVar6 = *piVar3;

  if ((iVar6 == 0x19) || (iVar6 == 0x18)) {
    ;
  } else {
    switch (iVar6) {
    case 10:
      lVar4 = FUN_00386ae0_evt(0x30,9);

      if (lVar4 == 0) {
        FUN_0019d3f0((const char *)(DAT_006a0000 - 0x2a80),0x207);

      }

      FUN_0038c540_evt(param_3,(int)param_1,param_2,lVar4,&uStack_4,&uStack_8);

      break;
    default:
      break;
    }
  }

  lVar2 = FUN_00386ae0_evt(0x54,8);

  if (lVar2 == 0) {

    FUN_0019d3f0((const char *)(DAT_006a0000 - 0x2a80),0x232);

  }

  FUN_00521408(lVar2,0,0x54);

  puVar5 = (u16 *)lVar2;

  *puVar5 = (short)param_2;

  *(u32 *)(puVar5 + 2) = 0xffffffff;

  *(u32 *)(puVar5 + 0x20) = 0;

  *(int *)(puVar5 + 0x1c) = *piVar3;

  FUN_00361140((u8 *)param_1,(u16 *)lVar2);

  iVar6 = (int)param_3;

  switch(*piVar3) {

  case 0:

  case 2:

    *(f32 *)(puVar5 + 8) = fGpffff841c_evt;

    uVar1 = FUN_00361fe0(iVar6 + piVar3[2] * 0x20 + 0x54,param_3);

    *(u32 *)(puVar5 + 2) = uVar1;

    break;

  case 1:

    uVar1 = FUN_00361fe0(iVar6 + piVar3[2] * 0x20 + 0x54,param_3);

    *(u32 *)(puVar5 + 2) = uVar1;

    *(u8 *)(puVar5 + 8) = 0;

    *(u8 *)(puVar5 + 0xb) = 0;

    *(u8 *)((int)puVar5 + 0x17) = 0x14;

    break;

  case 0x30:

    *(u8 *)(puVar5 + 8) = 0;

    *(char *)(puVar5 + 0x18) = (char)piVar3[1];

    break;

  case 3:

    uVar1 = FUN_00361fe0(iVar6 + piVar3[2] * 0x20 + 0x54,param_3);

    *(u32 *)(puVar5 + 2) = uVar1;

    *(s8 *)(puVar5 + 8) = -1;

    puVar5[9] = 0;

    *(u8 *)(puVar5 + 10) = 0;

    *(s8 *)((int)puVar5 + 0x15) = -1;
    ((s16 *)puVar5)[0xb] = -1;

    puVar5[0xc] = 0;

    break;
  case 4:

  case 5:

  case 7:

  case 8:

  case 0xb:

  case 0xd:

  case 0xe:

  case 0xf:

  case 0x10:

  case 0x11:

  case 0x13:

  case 0x17:

  case 0x19:

  case 0x1b:

  case 0x1c:

  case 0x1d:

  case 0x1e:

  case 0x1f:

  case 0x20:

  case 0x22:

  case 0x25:

  case 0x26:

  case 0x28:

  case 0x2a:

  case 0x2b:

  case 0x2c:

  case 0x2d:

  case 0x2e:

  case 0x2f:

  case 0x31:

  case 0x32:

    break;

  case 0x12:

    uVar1 = FUN_00361fe0(iVar6 + piVar3[2] * 0x20 + 0x54,param_3);

    *(u32 *)(puVar5 + 2) = uVar1;

    puVar5[8] = 0;

    ((s16 *)puVar5)[9] = -1;

    *(u8 *)(puVar5 + 8) = 0;

    break;

  case 0x14:

  case 0x15:

    uVar1 = FUN_00361fe0(iVar6 + piVar3[2] * 0x20 + 0x54,param_3);

    *(u32 *)(puVar5 + 2) = uVar1;

    *(s8 *)(puVar5 + 8) = -1;

    *(u8 *)((int)puVar5 + 0x11) = 0;

    puVar5[9] = 0;

    *(s8 *)(puVar5 + 10) = -1;

    *(s8 *)((int)puVar5 + 0x15) = -1;

    *(s8 *)(puVar5 + 0xb) = -1;

    *(s8 *)((int)puVar5 + 0x17) = -1;

    puVar5[0xc] = 0;

    break;

  case 0x1a:

    uVar1 = FUN_00361fe0(iVar6 + piVar3[2] * 0x20 + 0x54,param_3);

    *(u32 *)(puVar5 + 2) = uVar1;

    *(s8 *)(puVar5 + 8) = -1;

    puVar5[9] = 0;

    *(u8 *)(puVar5 + 10) = 0;

    *(s8 *)((int)puVar5 + 0x15) = -1;

    ((s16 *)puVar5)[0xb] = -1;

    puVar5[0xc] = 0;

    break;

  case 9:

    uVar1 = FUN_00361fe0(iVar6 + piVar3[2] * 0x20 + 0x54,param_3);

    *(u32 *)(puVar5 + 2) = uVar1;

    ((s16 *)puVar5)[8] = -1;

    puVar5[9] = 1;

    break;

  case 0xc:

    puVar5[8] = 1;

    puVar5[9] = 0x80;

    *(u32 *)(puVar5 + 10) = 0;

    break;

  case 0x16:

    puVar5[8] = 1;

    break;

  case 10:

    *(int *)(puVar5 + 0x24) = (int)lVar4;

    *(u32 *)(puVar5 + 8) = uStack_4;

    *(u32 *)(puVar5 + 10) = uStack_8;

    puVar5[0xc] = (short)piVar3[1];

    *(u32 *)(puVar5 + 2) = 0;

    break;

  case 6:

    puVar5[8] = 0;

    ((s16 *)puVar5)[9] = -1;

    break;

  case 0x18:

    uVar1 = FUN_00361fe0(iVar6 + piVar3[2] * 0x20 + 0x54,param_3);

    *(u32 *)(puVar5 + 2) = uVar1;

    FUN_00521408(auStack_60,0,0x20);

    *(u8 *)(puVar5 + 8) = auStack_60[0x14];

    *(u8 *)((int)puVar5 + 0x11) = auStack_60[0x18];

    puVar5[10] = *(u32 *)auStack_60;

    puVar5[0xb] = *(u32 *)(auStack_60 + 4);

    *(u8 *)(puVar5 + 0xc) = auStack_60[8];

    *(u8 *)((int)puVar5 + 0x19) = auStack_60[9];

    *(u8 *)(puVar5 + 0xd) = auStack_60[10];

    *(u8 *)((int)puVar5 + 0x1b) = auStack_60[0xb];

    *(f32 *)(puVar5 + 0xe) = *(f32 *)(auStack_60 + 0x10);

    *(f32 *)(puVar5 + 0x10) = *(f32 *)(auStack_60 + 0xc);

    *(u8 *)(puVar5 + 0x12) = auStack_60[0x1c];

    break;

  case 0x21:

    puVar5[8] = 0x1e;

    *(u32 *)(puVar5 + 0xc) = 0;

    *(u32 *)(puVar5 + 0xe) = 0x44200000;

    *(u32 *)(puVar5 + 0x10) = 0xc4430000;

    *(u32 *)(puVar5 + 0x12) = 0x42000000;

    *(u32 *)(puVar5 + 0x14) = 0;

    *(u32 *)(puVar5 + 0x16) = 0x420c0000;

    break;

  case 0x23:

    *(char *)((int)puVar5 + 0x11) = (char)piVar3[1];

    if (piVar3[1] == 1) {

      puVar5[10] = 0x17c;

    }

    break;

  case 0x24:

    *(char *)((int)puVar5 + 0x11) = (char)piVar3[1];

    break;

  case 0x27:

    *(u8 *)(puVar5 + 8) = 0;

    break;

  case 0x29:

    *(u8 *)(puVar5 + 8) = 0;

    FUN_0038d790(lVar2);

    break;

  default:

    FUN_0019d3f0((const char *)(DAT_006a0000 - 0x2a80),0x375);

    break;

  }
  return lVar2;

}


// FUN_00361830


int FUN_00361830(int param_1)



{

  int iVar1;

  int iVar2;
  int iVar3;

  

  if (*(int *)(param_1 + 0x164) == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = *(int *)(*(int *)(param_1 + 0x164) + 0x6c);
    iVar2 = 0;
    iVar3 = *(int *)(param_1 + 0x160) + *(int *)(param_1 + 0x15c);

    while (iVar2 < iVar3 && iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 0x4c);
      iVar2 = iVar2 + 1;
    }

  }

  return iVar1;

}


// FUN_00361890


void FUN_00361890(int *param_1,int param_2)



{

  int iVar1;

  

  iVar1 = (int)param_2;

  if (*(int *)(iVar1 + 0x50) == 0) {

    param_1[0x1b] = *(int *)(iVar1 + 0x4c);

  }

  else {

    *(u32 *)(*(int *)(iVar1 + 0x50) + 0x4c) = *(u32 *)(iVar1 + 0x4c);

  }

  if (*(int *)(iVar1 + 0x4c) == 0) {

    param_1[0x1c] = *(int *)(iVar1 + 0x50);

  }

  else {

    *(u32 *)(*(int *)(iVar1 + 0x4c) + 0x50) = *(u32 *)(iVar1 + 0x50);

  }

  *(u32 *)(iVar1 + 0x50) = 0;

  *(u32 *)(iVar1 + 0x4c) = 0;

  param_1[0x1a] = param_1[0x1a] + -1;

  if (*(int *)(iVar1 + 0x48) != 0) {

    if (*param_1 != 0x12) {

      FUN_00386b70_evt_main(*(int *)(iVar1 + 0x48),9,0);

    }

    *(u32 *)(iVar1 + 0x48) = 0;

  }

  if (*(int *)(iVar1 + 0x40) != 0) {

    FUN_00386b70(*(int *)(iVar1 + 0x40),10,0x130);

    *(u32 *)(iVar1 + 0x40) = 0;

  }

  FUN_00386b70_evt_main(param_2,8,0x54);

  return;

}


// Transferred the matched node-walk shape: hoist the bound once, then advance
// the link before incrementing the counter. This improves nd216 -> nd189 at
// unchanged size 480/480; hidden-argument probes reached 504/480 and were reverted.
// FUN_00361980 NONMATCHING


void FUN_00361980(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int iVar4;
  int iVar5;

  

  iVar2 = (int)param_1;

  piVar1 = *(int **)(iVar2 + 0x164);

  if (piVar1 == (int *)0x0) {

    FUN_0019d3f0((int)DAT_0069d580,0x3f5);

  }

  if (*(int *)(iVar2 + 0x164) == 0) {

    iVar4 = 0;

  }

  else {

    iVar4 = *(int *)(*(int *)(iVar2 + 0x164) + 0x6c);
    iVar3 = 0;
    iVar5 = *(int *)(iVar2 + 0x160) + *(int *)(iVar2 + 0x15c);
    for (; (iVar3 < iVar5 && (iVar4 != 0));) {
      iVar4 = *(int *)(iVar4 + 0x4c);
      iVar3 = iVar3 + 1;
    }

  }

  iVar3 = *piVar1;

  switch (iVar3) {
  case 3:
  case 0x1a:
  case 0x14:
  case 0x15:
    if (-1 < *(char *)(iVar4 + 0x10)) {
      FUN_00362100();
    }
    break;
  case 0x12:
    FUN_00362110();
    break;
  }

  FUN_00361200((int)piVar1,iVar4);

  if (*(int *)(iVar4 + 0x48) != 0) {

    if (*piVar1 != 0x12) {

      FUN_00386b70_evt_main(*(int *)(iVar4 + 0x48),9,0);

    }

    *(u32 *)(iVar4 + 0x48) = 0;

  }

  if (*(int *)(iVar4 + 0x40) != 0) {

    FUN_00386b70(*(int *)(iVar4 + 0x40),10,0x130);

    *(u32 *)(iVar4 + 0x40) = 0;

  }

  FUN_00386b70(iVar4,8,0x54);

  if (*(int *)(iVar2 + 0x160) == 0) {

    if (0 < *(int *)(iVar2 + 0x15c)) {

      *(int *)(iVar2 + 0x15c) = *(int *)(iVar2 + 0x15c) + -1;

    }

  }

  else if (*(int *)(iVar2 + 0x15c) < 1) {

    *(int *)(iVar2 + 0x160) = *(int *)(iVar2 + 0x160) + -1;

  }

  else {

    *(int *)(iVar2 + 0x15c) = *(int *)(iVar2 + 0x15c) + -1;

  }

  return;

}


// FUN_00361B60


void FUN_00361b60(int *param_1,int param_2)



{

  int *piVar1;
  MtEvtNodeList *list;

  list = (MtEvtNodeList *)param_2;
  piVar1 = list->head;
  if (piVar1 == (int *)0x0) {

    list->head = param_1;

    list->tail = param_1;

    param_1[0x25] = 0;

    param_1[0x26] = 0;

  }

  else {

    for (; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x25]) {

      if (DAT_0069d590_abs[*param_1] < DAT_0069d590_abs[*piVar1]) {

        if (piVar1[0x26] == 0) {
          list->head = param_1;
          piVar1[0x26] = (int)param_1;
          param_1[0x26] = 0;
          param_1[0x25] = (int)piVar1;
        }
        else {
          *(int **)(piVar1[0x26] + 0x94) = param_1;
          param_1[0x26] = piVar1[0x26];
          param_1[0x25] = (int)piVar1;
          piVar1[0x26] = (int)param_1;
        }

        break;

      }

    }

    if (piVar1 == (int *)0x0) {

      *(int **)((int)list->tail + 0x94) = param_1;

      param_1[0x26] = (int)list->tail;

      param_1[0x25] = 0;

      list->tail = param_1;

    }

  }

  list->count = list->count + 1;

  return;

}


// FUN_00361c30


void FUN_00361c30(int param_1,int param_2)



{

  if (*(int *)(param_1 + 0x98) == 0) {

    *(u32 *)(param_2 + 0x84) = *(u32 *)(param_1 + 0x94);

  }

  else {

    *(u32 *)(*(int *)(param_1 + 0x98) + 0x94) = *(u32 *)(param_1 + 0x94);

  }

  if (*(int *)(param_1 + 0x94) == 0) {

    *(u32 *)(param_2 + 0x88) = *(u32 *)(param_1 + 0x98);

  }

  else {

    *(u32 *)(*(int *)(param_1 + 0x94) + 0x98) = *(u32 *)(param_1 + 0x98);

  }

  *(u32 *)(param_1 + 0x98) = 0;

  *(u32 *)(param_1 + 0x94) = 0;

  *(int *)(param_2 + 0x80) = *(int *)(param_2 + 0x80) + -1;

  return;

}


// FUN_00361CA0

int FUN_00361ca0(int param_1,int param_2)



{

  int lVar1;

  int *piVar2;
  u32 iVar3;
  

  lVar1 = FUN_00386ae0_evt(0x9c,7);

  if (lVar1 == 0) {
    return 0;
  }

  FUN_00521408(lVar1,0,0x9c);

  piVar2 = (int *)lVar1;

  *piVar2 = param_1;

  iVar3 = piVar2[2] = -1;

  *(u16 *)(piVar2 + 3) = 0;

  piVar2[0x19] = 0;
  switch (param_1) {
  case 0x30:
    *(u8 *)((int)piVar2 + 0x22) = (u8)iVar3;
    break;
  }
  FUN_00361b60((int *)lVar1,param_2);


  return lVar1;

}


// FUN_00361D60


void FUN_00361d60(int param_1,u16 param_2,u32 param_3)



{

  int lVar1;

  int iVar2;

  

  if (param_1 != 0) {

    iVar2 = (int)param_1;

    *(u16 *)(iVar2 + 0xc) = param_2;

    lVar1 = FUN_003b5d10(*(u16 *)(iVar2 + 0xc));

    if (lVar1 != 0) {

      *(u32 *)(iVar2 + 0x58) = *(u32 *)(lVar1 + 0x28);

    }

    else {

      *(u32 *)(iVar2 + 0x58) = 0;

    }

    *(u32 *)(iVar2 + 0x38) = param_3;

  }

  return;

}


// FUN_00361DD0


u32 FUN_00361dd0(int param_1,u32 param_2,u16 param_3,u32 param_4)
{
  u32 lVar1;
  u32 lVar2;
  int *piVar3;
  int iVar4;
  u32 initValue;

  lVar1 = FUN_00386ae0_evt(0x9c,7);
  if (lVar1 == 0) {
    lVar1 = 0;
  } else {
    FUN_00521408(lVar1,0,0x9c);
    piVar3 = (int *)lVar1;
    *piVar3 = param_1;
    initValue = piVar3[2] = -1;
    *(u16 *)(piVar3 + 3) = 0;
    piVar3[0x19] = 0;
    switch (param_1) {
    case 0x30:
      *(u8 *)((int)piVar3 + 0x22) = (u8)initValue;
      break;
    }
    FUN_00361b60((int *)lVar1,param_2);
  }
  if ((lVar1 != 0) && (lVar1 != 0)) {
    iVar4 = (int)lVar1;
    *(u16 *)(iVar4 + 0xc) = param_3;
    lVar2 = FUN_003b5d10(*(u16 *)(iVar4 + 0xc));
    if (lVar2 != 0) {
      *(u32 *)(iVar4 + 0x58) = *(u32 *)((int)lVar2 + 0x28);
    } else {
      *(u32 *)(iVar4 + 0x58) = 0;
    }
    *(u32 *)(iVar4 + 0x38) = param_4;
  }
  return lVar1;
}


// FUN_00361ee0


int FUN_00361ee0(int param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  

  iVar1 = 0;

  for (piVar2 = *(int **)(param_2 + 0x84); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0x25]) {

    if (*piVar2 == param_1) {

      iVar1 = iVar1 + 1;

    }

  }

  return iVar1;

}


// FUN_00361f20


int FUN_00361f20(int param_1)



{

  int iVar1;

  int iVar2;

  

  iVar1 = 0;

  for (iVar2 = *(int *)(param_1 + 0x84); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x94)) {

    iVar1 = iVar1 + 1;

  }

  return iVar1;

}


/* W367 pragma probe: opt_loop_invariants on nd 61 -> 36; off nd 61; object 116/128. */
#pragma opt_loop_invariants on
// FUN_00361F60 NONMATCHING


int FUN_00361f60(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;

  iVar1 = 0;
  for (piVar2 = *(int **)(param_2 + 0x84); piVar2 != (int *)0x0;
       piVar2 = (int *)piVar2[0x25]) {
    if (param_1 == 2) {
      if (*piVar2 == 5) {
        continue;
      }
      if (*piVar2 != 0x13) {
        goto add_value;
      }
      continue;
    }
    if (param_1 == 3) {
      if ((*piVar2 == 5) || (*piVar2 == 0x13)) {
        goto add_value;
      }
    }
    continue;
add_value:
    iVar1 = iVar1 + piVar2[0x1a];
  }
  return iVar1;
}


// Two honest branch-layout attempts were measured and reverted: an early return
// from the search loop regressed nd108 -> nd173/size260 -> 264; inverting the
// call test plus an early post-loop return regressed to nd118/size272.
#pragma opt_loop_invariants reset
// FUN_00361FE0 NONMATCHING


int FUN_00361fe0(int param_1,int param_2)



{

  int lVar1;

  int iVar2;

  

  if (param_1 == 0) {

    FUN_0019d3f0((int)(DAT_006a0000 - 0x2a80),0x58b);

  }
  if (param_1 == 0) {
    FUN_0019d3f0((int)(DAT_006a0000 - 0x2a80),0x571);

  }

  for (iVar2 = 0; iVar2 < *(int *)(param_2 + 0x50); iVar2 = iVar2 + 1) {
    lVar1 = FUN_00524128(param_1,param_2 + iVar2 * 0x20 + 0x54);
    if (lVar1 == 0) goto LAB_00362080;
  }
  iVar2 = -1;
LAB_00362080:
  if (iVar2 < 0) {
    iVar2 = *(int *)(param_2 + 0x50);
    if (0 < iVar2) {
      FUN_0019d3f0((int)(DAT_006a0000 - 0x2a80),0x592);
    }
    FUN_00524270(param_2 + iVar2 * 0x20 + 0x54,param_1);
    *(int *)(param_2 + 0x50) = *(int *)(param_2 + 0x50) + 1;
  }

  return iVar2;

}


// FUN_00362100


void FUN_00362100(void)



{

  return;

}


// FUN_00362110


void FUN_00362110(void)



{

  return;

}


// FUN_00362120


void FUN_00362120(int param_1,int param_2,int param_3)



{

  int *piVar4;

  u16 sVar1;

  u16 *puVar2;

  int iVar3;

  iVar3 = FUN_003b5d00();

  if (iVar3 != 0) {

    for (piVar4 = *(int **)(param_3 + 0x84); piVar4 != (int *)0x0; piVar4 = (int *)piVar4[0x25]) {

      if (((*piVar4 == 1) || (*piVar4 == 0x30)) && (sVar1 = (u16)piVar4[3], sVar1 != 0)) {

        if (piVar4[0x19] == 1) {

          FUN_003b8310(sVar1,0);

        }

        else if (param_1 == 0) {

          FUN_003b8310_evt(sVar1,1);

        }

        else {

          FUN_003b8310(sVar1,0);

        }

      }

    }

    for (puVar2 = (u16 *)FUN_003b5d50(7); puVar2 != (u16 *)0x0;

        puVar2 = *(u16 **)(puVar2 + 0x7c)) {

      if (param_1 == 0) {

        FUN_003b8310(*puVar2,1);

      }

      else {

        FUN_003b8310(*puVar2,0);

      }

    }

  }

  return;

}


// FUN_00362240


void FUN_00362240(int param_1)



{

  if (*(int *)(param_1 + 0x77c) == 1) {

    FUN_00362120_evt(0,*(int *)(param_1 + 0x18),param_1);

  }

  else {

    FUN_00362120_evt(1,*(int *)(param_1 + 0x18),param_1);

  }

  return;

}


#pragma push
#pragma opt_loop_invariants on
// FUN_00362290


u16 * FUN_00362290(int param_1)



{

  u16 *puVar1;

  u16 *puVar2;

  int iVar3;

  int *piVar5;

  int iVar4;
  

  puVar2 = (u16 *)0x0;

  iVar4 = 99999;

  for (piVar5 = *(int **)(param_1 + 0x84); piVar5 != (int *)0x0; piVar5 = (int *)piVar5[0x25]) {

    if (*piVar5 == 2) {

      for (puVar1 = (u16 *)piVar5[0x1b]; puVar1 != (u16 *)0x0;

          puVar1 = *(u16 **)(puVar1 + 0x26)) {

        if (*(int *)(param_1 + 0x18) < (int)(u32)*puVar1) {

          iVar3 = (u32)*puVar1 - *(int *)(param_1 + 0x18);

          if (iVar3 < iVar4) {

            iVar4 = iVar3;

            puVar2 = puVar1;

          }

        }

      }

    }

  }

  return puVar2;

}
#pragma pop


#pragma push
#pragma opt_loop_invariants on
// FUN_00362310


u16* FUN_00362310(int param_1)
{
    u16* candidate;
    u16* nearest;
    int distance;
    u32 candidateTime;
    int currentTime;
    int* group;
    int nearestDistance;

    nearest = NULL;
    nearestDistance = 99999;
    for (group = *(int**)(param_1 + 0x84); group != NULL; group = (int*)group[0x25])
    {
        if (*group == 2)
        {
            for (candidate = (u16*)group[0x1b]; candidate != NULL;
                 candidate = *(u16**)(candidate + 0x26))
            {
                candidateTime = *(volatile /* Removing this function's qualifier batch loses FUN_00362310 (MATCH nd0 -> MISMATCH nd74, size 128 -> 136) - measured W170. */ u16*)candidate;
                currentTime = *(volatile /* Removing this function's qualifier batch loses FUN_00362310 (MATCH nd0 -> MISMATCH nd74, size 128 -> 136) - measured W170. */ int*)(param_1 + 0x18);
                if ((int)candidateTime < currentTime)
                {
                    distance = currentTime - candidateTime;
                    if (distance < nearestDistance)
                    {
                        nearestDistance = distance;
                        nearest = candidate;
                    }
                }
            }
        }
    }
    return nearest;
}
#pragma pop

// FUN_00362390


void FUN_00362390(int param_1)



{

  int iVar2;

  int lVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  

  iVar4 = 0;

  iVar5 = (int)param_1;

  if ((*(u16 *)DAT_007e0952_2390 & 2) != 0) {

    lVar3 = (int)FUN_00362290_2390();

    if (lVar3 != 0) {

      iVar4 = (u32)*(u16 *)lVar3 - *(int *)(iVar5 + 0x18);

    }

  }

  else {

    if ((*(u16 *)DAT_007e0952_2390 & 1) != 0) {

      lVar3 = (int)FUN_00362310_2390();

      if (lVar3 != 0) {

        iVar4 = (u32)*(u16 *)lVar3 - *(int *)(iVar5 + 0x18);

      }

    }

    else {
      if (((*(u16 *)DAT_007e094c_2390 & 0x2000) != 0) &&
          ((*(u16 *)DAT_007e0952_2390 & 8) != 0) &&
          (*(int *)(iVar5 + 0x18) > 0)) {
        iVar4 = 100;
      }
      else if (((*(u16 *)DAT_007e094c_2390 & 0x8000) != 0) &&
               ((*(u16 *)DAT_007e0952_2390 & 4) != 0) &&
               (*(int *)(iVar5 + 0x18) > 0)) {
        iVar4 = -100;
      }
      else if (((*(u16 *)DAT_007e0952_2390 & 0x8000) != 0) &&
               (*(int *)(iVar5 + 0x18) > 0)) {
        iVar4 = -1;
      }
      else if (((*(u16 *)DAT_007e0952_2390 & 0x2000) != 0) &&
               (*(int *)(iVar5 + 0x18) < *(int *)(iVar5 + 0xc) - 1)) {
        iVar4 = 1;
      }
      else if ((*(u16 *)DAT_007e0952_2390 & 4) != 0) {
        iVar4 = -10;
      }
      else if ((*(u16 *)DAT_007e0952_2390 & 8) != 0) {
        iVar4 = 10;
      }
      else if ((*(u16 *)DAT_007e094e_abs & 0x100) != 0) {
        if (*(int *)(iVar5 + 0x18) != *(int *)(iVar5 + 0x10)) {
          iVar4 = *(int *)(iVar5 + 0x10) - *(int *)(iVar5 + 0x18);
          *(u32 *)(iVar5 + 4) &= ~0x20;
          *(u32 *)(iVar5 + 4) &= ~0x8000;
        }
      }
    }

  }

  if (iVar4 != 0) {

    FUN_00362fa0(param_1);

    iVar6 = *(int *)(iVar5 + 0x18) + iVar4;

    if (iVar6 < 0) {

      iVar6 = 0;

    }

    iVar2 = *(int *)(iVar5 + 0xc) + -1;

    if (iVar2 < iVar6) {

      iVar6 = iVar2;

    }

    FUN_0038c830_2390(param_1,iVar6);

    *(int *)(iVar5 + 0x28) = iVar6;

    *(u32 *)(iVar5 + 0x24) = 1;

    if (0 < iVar4) {

      FUN_003b83d0(iVar4);

    }

  }

  return;

}


// FUN_003625E0 NONMATCHING


void FUN_003625e0(void)



{

  int lVar1;

  int iVar2;

  RwMatrix matrix;
  RwV4d direction;
  RwV4d rotationY;
  RwV4d rotationX;
  RwV3d transformed;

  

  *(u64 *)&direction.x = *(u64 *)DAT_0069d5c8_abs;
  *(u32 *)&direction.z = *(u32 *)DAT_0069d5d0_abs;
  *(u64 *)&rotationY.x = *(u64 *)DAT_0069d5d8_abs;
  *(u32 *)&rotationY.z = *(u32 *)DAT_0069d5e0_abs;
  *(u64 *)&rotationX.x = *(u64 *)DAT_0069d5e8_abs;
  *(u32 *)&rotationX.z = *(u32 *)DAT_0069d5f0_abs;

  lVar1 = FUN_0038a0b0(0);

  if ((lVar1 == 1) && (lVar1 = FUN_003b5d10(0x1e59), lVar1 != 0)) {

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
    matrix.flags |= rwMATRIXTYPEORTHONORMAL | rwMATRIXINTERNALIDENTITY;

    iVar2 = (int)lVar1;

    FUN_004c31b0_evt_main(&matrix,&rotationX,*(float *)(iVar2 + 0x10),2);
    FUN_004c31b0_evt_main(&matrix,&rotationY,*(float *)(iVar2 + 0x14),2);
    FUN_004c35d0_evt_main(&matrix,(void *)(iVar2 + 4),2);
    FUN_004c6c60_evt_main(&transformed,&direction,&matrix);

    if (DAT_007e095f < 0x3c) {

      *(float *)(iVar2 + 4) = transformed.x * 13.0f + *(float *)(iVar2 + 4);
      *(float *)(iVar2 + 8) = transformed.y * 13.0f + *(float *)(iVar2 + 8);
      *(float *)(iVar2 + 0xc) = transformed.z * 13.0f + *(float *)(iVar2 + 0xc);

    }

    else if (0xbb < DAT_007e095f) {

      *(float *)(iVar2 + 4) = (*(float *)(iVar2 + 4)) - transformed.x * 13.0f;
      *(float *)(iVar2 + 8) = (*(float *)(iVar2 + 8)) - transformed.y * 13.0f;
      *(float *)(iVar2 + 0xc) = (*(float *)(iVar2 + 0xc)) - transformed.z * 13.0f;

    }

    if (DAT_007e095e < 0x3c) {

      *(float *)(iVar2 + 0x14) = *(float *)(iVar2 + 0x14) + 2.5f;

    }

    else if (DAT_007e095e < 0xbc) {

      if (DAT_007e0960 < 0x3c) {

        *(float *)(iVar2 + 0x14) = *(float *)(iVar2 + 0x14) + 2.5f;

      }

      else if (DAT_007e0960 < 0xbc) {

        if (DAT_007e0961 < 0x3c) {

          *(float *)(iVar2 + 0x10) = *(float *)(iVar2 + 0x10) + 2.5f;

        }

        else if (0xbb < DAT_007e0961) {

          *(float *)(iVar2 + 0x10) = *(float *)(iVar2 + 0x10) - 2.5f;

        }

      }

      else {

        *(float *)(iVar2 + 0x14) = *(float *)(iVar2 + 0x14) - 2.5f;

      }

    }

    else {

      *(float *)(iVar2 + 0x14) = *(float *)(iVar2 + 0x14) - 2.5f;

    }

  }

  return;

}


/* W367 pragma probe: opt_propagation off nd 1120 -> 1076; on nd 1120; object 1504/1584. */
/* W415: outer flag inversion + ascending state switch + state-1 float width + scalar declaration order nd1076->814; object1504->1508/window1584. Negative copy setup with iVar5 before puVar6 nd823->825 (object1508) was reverted. */
#pragma opt_propagation off
// FUN_003628F0 NONMATCHING
void FUN_003628f0(void)



{

  u32 uVar1;

  u32 uVar2;

  u32 *puVar3;

  u32 lVar4;

  u32 *puVar6;

  int iVar5;

  int iVar7;

  f32 fVar8;
  RwMatrix matrix;

  RwV3d outputA;

  RwV3d outputB;

  RwV3d transformedA;

  RwV3d transformedB;

  RwV4d stack60;

  RwV4d stack50;

  RwV4d stack30;

  RwV4d stack20;

  u32 auStack_100 [16];

  

  *(u64 *)&stack20.x = *(u64 *)DAT_0069d5f8_abs;
  *(u32 *)&stack20.z = *(u32 *)DAT_0069d600_abs;
  *(u64 *)&stack30.x = *(u64 *)DAT_0069d608_abs;
  *(u32 *)&stack30.z = *(u32 *)DAT_0069d610_abs;
  *(u64 *)&stack50.x = *(u64 *)DAT_0069d618_abs;
  *(u32 *)&stack50.z = *(u32 *)DAT_0069d620_abs;
  *(u64 *)&stack60.x = *(u64 *)DAT_0069d628_abs;
  *(u32 *)&stack60.z = *(u32 *)DAT_0069d630_abs;

  lVar4 = FUN_0038a0b0(0);

  if ((lVar4 == 1) && (lVar4 = FUN_003b5d10(0x1e59), lVar4 != 0)) {

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
    matrix.flags |= rwMATRIXTYPEORTHONORMAL | rwMATRIXINTERNALIDENTITY;

    FUN_004c31b0_evt_main(&matrix,&stack60,0.0f,2);
    iVar7 = (int)lVar4;
    FUN_004c31b0_evt_main(&matrix,&stack50,*(float *)(iVar7 + 0x14),2);
    FUN_004c35d0_evt_main(&matrix,(void *)(iVar7 + 4),2);
    FUN_004c6c60_evt_main(&transformedA,&stack20,&matrix);
    FUN_004c6c60_evt_main(&transformedB,&stack30,&matrix);

    if ((*(u16 *)DAT_007e094c_628f0_abs & 0x10) != 0) {



    if ((*(u16 *)DAT_007e0952_628f0_abs & 8) != 0) {

      switch (iGpffffb8f0) {

      case 1:

        *(f32 *)(iVar7 + 8) = 0x2f3;

        *(u32 *)(iVar7 + 0x10) = 0x41a00000;

        *(u32 *)(iVar7 + 0x14) = 0x43590000;

        *(u32 *)(iVar7 + 0x18) = 0;

        *(u32 *)(iVar7 + 0x100) = 0x420c0000;

        uGpffffb8ec = 1;

        iGpffffb8f0 = 2;

        return;

      case 2:

        *(u32 *)(iVar7 + 8) = 0x43fa0000;

        *(u32 *)(iVar7 + 0x10) = 0x41a80000;

        *(u32 *)(iVar7 + 0x14) = 0x42da0000;

        *(u32 *)(iVar7 + 0x18) = 0;

        *(u32 *)(iVar7 + 0x100) = 0x420c0000;

        uGpffffb8ec = 2;

        lVar4 = FUN_001a11d0();

        if (lVar4 == 0) {

          iGpffffb8f0 = 0;

          return;

        }

        iGpffffb8f0 = 3;

        return;

      case 3:

        iGpffffb8f0 = 0;

        uGpffffb8ec = 3;

        lVar4 = FUN_001a11d0();

        if (lVar4 != 1) {

          return;

        }

        fVar8 = FUN_001a1190();

        puVar3 = (u32 *)FUN_001a1150();

        puVar6 = auStack_100;

        iVar5 = 8;

        do {

          uVar1 = *puVar3;

          uVar2 = puVar3[1];

          puVar3 = puVar3 + 2;

          iVar5 = iVar5 + -1;

          *puVar6 = uVar1;

          puVar6[1] = uVar2;

          puVar6 = puVar6 + 2;

        } while (0 < iVar5);

        FUN_003b7ac0(auStack_100,&outputA,&outputB);

        *(f32 *)(iVar7 + 0x100) = fVar8;

        *(f32 *)(iVar7 + 4) = outputB.x;

        *(f32 *)(iVar7 + 8) = outputB.y;

        *(f32 *)(iVar7 + 0xc) = outputB.z;

        *(f32 *)(iVar7 + 0x10) = outputA.x;

        *(f32 *)(iVar7 + 0x14) = outputA.y;

        *(f32 *)(iVar7 + 0x18) = outputA.z;

        return;

      default:

        *(u32 *)(iVar7 + 8) = 0x43fa0000;

        *(u32 *)(iVar7 + 0x10) = 0x41d00000;

        *(u32 *)(iVar7 + 0x14) = 0x42ec0000;

        *(u32 *)(iVar7 + 0x18) = 0;

        *(u32 *)(iVar7 + 0x100) = 0x420c0000;

        uGpffffb8ec = 0;

        iGpffffb8f0 = 1;

        break;

      }

    }
      }
      else {
      uGpffffb8ec = 0;

      iGpffffb8f0 = 0;

      if (DAT_007e095f_628f0_abs[0] < 0x3c) {

        *(float *)(iVar7 + 4) = transformedA.x * 10.0f + *(float *)(iVar7 + 4);
        *(float *)(iVar7 + 8) = transformedA.y * 10.0f + *(float *)(iVar7 + 8);
        *(float *)(iVar7 + 0xc) = transformedA.z * 10.0f + *(float *)(iVar7 + 0xc);

      }

      else if (0xbb < DAT_007e095f_628f0_abs[0]) {

        *(float *)(iVar7 + 4) = (*(float *)(iVar7 + 4)) - transformedA.x * 10.0f;
        *(float *)(iVar7 + 8) = (*(float *)(iVar7 + 8)) - transformedA.y * 10.0f;
        *(float *)(iVar7 + 0xc) = (*(float *)(iVar7 + 0xc)) - transformedA.z * 10.0f;

      }

      if (DAT_007e095e_628f0_abs[0] < 0x3c) {

        *(float *)(iVar7 + 4) = transformedB.x * 10.0f + *(float *)(iVar7 + 4);
        *(float *)(iVar7 + 8) = transformedB.y * 10.0f + *(float *)(iVar7 + 8);
        *(float *)(iVar7 + 0xc) = transformedB.z * 10.0f + *(float *)(iVar7 + 0xc);

      }

      else if (0xbb < DAT_007e095e_628f0_abs[0]) {

        *(float *)(iVar7 + 4) = (*(float *)(iVar7 + 4)) - transformedB.x * 10.0f;
        *(float *)(iVar7 + 8) = (*(float *)(iVar7 + 8)) - transformedB.y * 10.0f;
        *(float *)(iVar7 + 0xc) = (*(float *)(iVar7 + 0xc)) - transformedB.z * 10.0f;

      }

      if (DAT_007e0960_628f0_abs[0] < 0x3c) {

        *(float *)(iVar7 + 0x14) = *(float *)(iVar7 + 0x14) + 1.0f;

      }

      else if (0xbb < DAT_007e0960_628f0_abs[0]) {

        *(float *)(iVar7 + 0x14) = *(float *)(iVar7 + 0x14) - 1.0f;

      }

      if ((*(u16 *)DAT_007e0952_628f0_abs & 4) == 0) {

        if ((*(u16 *)DAT_007e0952_628f0_abs & 1) == 0) {

          if (DAT_007e0961_628f0_abs[0] < 0x3c) {

            *(float *)(iVar7 + 0x10) = *(float *)(iVar7 + 0x10) + 1.0f;

          }

          else if (0xbb < DAT_007e0961_628f0_abs[0]) {

            *(float *)(iVar7 + 0x10) = *(float *)(iVar7 + 0x10) - 1.0f;

          }

        }

        else {

          *(float *)(iVar7 + 8) = *(float *)(iVar7 + 8) - 10.0f;

        }

      }

      else {

        *(float *)(iVar7 + 8) = *(float *)(iVar7 + 8) + 10.0f;

      }

      if ((*(u16 *)DAT_007e0952_628f0_abs & 8) == 0) {

        if ((*(u16 *)DAT_007e0952_628f0_abs & 2) != 0) {

          *(float *)(iVar7 + 0x100) = *(float *)(iVar7 + 0x100) - 1.0f;

        }

      }

      else {

        *(float *)(iVar7 + 0x100) = *(float *)(iVar7 + 0x100) + 1.0f;

      }
      }

  }

  return;

}




#pragma opt_propagation reset
// FUN_00362F20


void FUN_00362f20(int param_1)
{
  u32 lVar1;

  lVar1 = FUN_003b5d00();
  if (lVar1 == 0) {
    return;
  }

  lVar1 = FUN_0038a0b0(param_1);

  switch (lVar1) {
  case 0:
    FUN_0038a0c0(param_1,1);
    break;
  case 1:
    FUN_0038a0c0(param_1,0);
    break;
  default:
    break;
  }

  return;
}


// FUN_00362FA0


void FUN_00362fa0(int param_1)



{

  int lVar1;

  

  if ((*(int *)(param_1 + 8) != 0) && (lVar1 = FUN_0039eee0(param_1 + 0x82c), lVar1 != 0)) {

    FUN_0039f350(param_1 + 0x82c);

  }

  return;

}


// FUN_00362FF0


void FUN_00362ff0(int param_1)



{

  if ((param_1 != 0) && (*(int *)((int)param_1 + 0x8c) != 0)) {

    FUN_00386d50(param_1);

  }

  return;

}


/* W367 pragma probe: opt_dead_assignments off nd 1471 -> 1426; on nd 1471; object 2220/2224. Stacked loop invariants exceeded the window (nd 1465, object 2228/2224). */
#pragma opt_dead_assignments off
// FUN_00363030 NONMATCHING


void FUN_00363030(int *param_1,u16 *param_2,u32 param_3,u8 *param_4)



{

  u16 uVar1;

  char cVar2;

  u8 uVar3;

  u16 uVar4;

  short sVar5;

  u32 uVar6;

  u32 uVar7;

  u64 uVar8;

  u32 lVar9;

  int iVar10;

  int iVar11;

  int iVar12;
  u8 *iVar13;

  u32 auStack_10 [3];

  u16 uStack_2;

  

  iVar10 = *param_1;

  iVar13 = param_4;

    switch (iVar10) {
  case 0x1:
  case 0x2:
  case 0x6:
  case 0xc:
  case 0xa:
  case 0xb:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x16:
  case 0x17:
  case 0x1b:
  case 0x3:
  case 0x1a:
  case 0x14:
  case 0x15:
  case 0x12:
    break;
  case 0x29:
    if (param_3 == *param_2) {
      FUN_0039e1b0(param_4,param_2);
    }
    break;
  case 0x5:
      if (((*(u32 *)(iVar13 + 4) & 0x10) == 0) && (param_3 == *param_2)) {

        FUN_005225a8(0x69d640,param_3);

        cVar2 = (char)param_2[9];

        if (cVar2 == '\x03') {

          FUN_00395350(4,param_2[8]);

        }

        else if (cVar2 == '\x02') {


          uVar8 = FUN_00386e10((int)param_4);
          FUN_003952d0(uVar8,param_2[8],3);

        }

        else if (cVar2 == '\x01') {

          FUN_00395350(3,param_2[8]);

        }

        else if (cVar2 == '\0') {


          uVar8 = FUN_00386e10((int)param_4);
          FUN_003952d0(uVar8,param_2[8],3);

          FUN_005225a8(0x69d660,param_2[8]);

        }

      }

    
    break;
  case 0x32:
      if (param_3 == *param_2) {

        if ((char)param_2[8] == '\x01') {

          FUN_0010a4e0(0,*(u8 *)((int)param_2 + 0x11),(char)param_2[9],

                       *(u8 *)((int)param_2 + 0x13));

        }

        else if ((char)param_2[8] == '\0') {

          FUN_0010a4e0(1,*(u8 *)((int)param_2 + 0x11),(char)param_2[9],

                       *(u8 *)((int)param_2 + 0x13));

        }

      }

    
    break;
  case 0x13:
      if (((*(u32 *)(iVar13 + 4) & 0x10) == 0) && (param_3 == *param_2)) {

        switch(param_2[8]) {

        case 0:

          FUN_00395270(param_2[9]);

          break;

        case 1:


          uVar8 = FUN_00386e10((int)param_4);
          FUN_003952b0(uVar8,param_2[9]);

          break;

        case 2:

          FUN_00108fd0(0x78);

          break;

        case 3:


          uVar8 = FUN_00386e10((int)param_4);
          FUN_003952a0(uVar8,param_2[9]);

          break;

        case 4:

        case 5:

          break;

        case 6:

          FUN_00108f70();

          break;

        default:

          FUN_0019d3f0(0x69d580,0xa56);

        }

      }

    
    break;
  case 0x7:
      if ((param_2[1] == 0) && (param_2[8] == 0)) {

        *(u32 *)(iVar13 + 4) = *(u32 *)(iVar13 + 4) & 0xfffffffd;

        FUN_003bcc80();

      }

      else if (param_3 == *param_2) {

        *(u32 *)(iVar13 + 4) = *(u32 *)(iVar13 + 4) | 2;

        FUN_003bcbf0(param_2[1],param_2[8]);

      }

    
    break;
  case 0x1c:
      if (param_3 == *param_2) {

        if ((char)param_2[8] == '\0') {

          FUN_00103c30(param_2[10],param_2[0xb],param_2[0xc],param_2[0xd]);

        }

        else if ((char)param_2[8] == '\x01') {

          FUN_00103cb0();

        }

      }

    
    break;
  case 0x1d:
      if (*(int *)(iVar13 + 0x924) != 0) {

        lVar9 = FUN_00195460();

        if (lVar9 == 1) {

          FUN_00195020(*(u32 *)(iVar13 + 0x924));

        }

        *(u32 *)(iVar13 + 0x924) = 0;

      }

      uVar6 = FUN_0010bc20(*(u32 *)(iVar13 + 0x92c),param_2[8]);

      *(u32 *)(iVar13 + 0x924) = uVar6;

      *(u32 *)(iVar13 + 4) = *(u32 *)(iVar13 + 4) | 0x4000;

    
    break;
  case 0x20:
    break;
  case 0x2a:
    if (param_3 == *param_2) {

      uVar4 = FUN_0016c920(1);

      lVar9 = -1;

      switch(uVar4) {

      case 0:

        lVar9 = (long)(short)param_2[0xb];

        break;

      case 1:

        lVar9 = (long)(short)param_2[0xc];

        break;

      case 2:

        lVar9 = (long)(short)param_2[0xd];

        break;

      case 3:

        lVar9 = (long)(short)param_2[10];

        break;

      case 4:

        lVar9 = (long)(short)param_2[9];

        break;

      case 5:

        lVar9 = (long)(short)param_2[8];

      }

      if (lVar9 != -1) {

        *(int *)(iVar13 + 0x28) = (int)lVar9;

        *(u32 *)(iVar13 + 0x24) = 1;

      }

    }

  
    break;
  case 0x2c:
    if ((param_3 == *param_2) && (sVar5 = FUN_0016dd40(), sVar5 != 0xff)) {

      cVar2 = FUN_0016dba0();

      lVar9 = FUN_00395230(cVar2 * 5);

      if (lVar9 != 1) {

        uVar1 = param_2[9];

      }

      else {

        uVar1 = param_2[8];

      }

      *(int *)(iVar13 + 0x28) = (int)(short)uVar1;

      *(u32 *)(iVar13 + 0x24) = 1;

    }

  
    break;
  case 0x2d:
    if ((param_3 == *param_2) && ((char)param_2[8] != '\0')) {

      iVar11 = 0;

      uVar7 = FUN_0016de50((char)param_2[8] + -1);

      auStack_10[0] = (u32)(u8)param_2[10];

      auStack_10[1] = (u32)*(u8 *)((int)param_2 + 0x15);

      auStack_10[2] = (u32)(u8)param_2[0xb];

      for (iVar10 = 0;

          (iVar12 = -1, iVar10 < 4 &&

          (iVar12 = iVar10, (int)auStack_10[iVar10] < (int)(uVar7 & 0xff))); iVar10 = iVar10 + 1) {

      }

      if (iVar12 == -1) {

        iVar11 = (int)(short)param_2[0xf];

      }

      else if (iVar12 == 2) {

        iVar11 = (int)(short)param_2[0xe];

      }

      else if (iVar12 == 1) {

        iVar11 = (int)(short)param_2[0xd];

      }

      else if (iVar12 == 0) {

        iVar11 = (int)(short)param_2[0xc];

      }

      else {

        FUN_0019d3f0(0x69d580,0xb21);

      }

      *(int *)(iVar13 + 0x28) = iVar11;

      *(u32 *)(iVar13 + 0x24) = 1;

    }

  
    break;
  case 0x2e:
    if ((param_3 == *param_2) && (sVar5 = FUN_0016dd40(), sVar5 != 0xff)) {

      lVar9 = FUN_003c2ee0(sVar5);

      if (lVar9 == 0) {

        uVar1 = param_2[9];

      }

      else {

        iVar10 = (int)lVar9;

        FUN_0039eef0(iVar13 + 0x82c,7,*(u32 *)(iVar10 + 8));

        lVar9 = FUN_003c4130(*(u32 *)(iVar10 + 4),*(u32 *)(iVar10 + 8));

        if (lVar9 != 0) {

          FUN_0039ef30(iVar13 + 0x82c,8,lVar9);

        }

        uVar3 = FUN_003bea20(0,iVar10 + 0xc);

        lVar9 = FUN_003c3f40(uVar3);

        if (lVar9 != 0) {

          FUN_0039ef30(iVar13 + 0x82c,9,lVar9);

        }

        lVar9 = FUN_00172c50(&uStack_2);

        if ((lVar9 != 0) && (lVar9 = FUN_003c3fe0(uStack_2), lVar9 != 0)) {

          FUN_0039ef30(iVar13 + 0x82c,10,lVar9);

        }

        uVar1 = param_2[8];

      }

      *(int *)(iVar13 + 0x28) = (int)(short)uVar1;

      *(u32 *)(iVar13 + 0x24) = 1;

    }

  
    break;
  default:
    break;
  }

  return;

}


#pragma opt_dead_assignments reset
/* W367 pragma probe: opt_lifetimes on nd 1957 -> 1953; off nd 1957; object 2828/2960. */
#pragma opt_lifetimes on
// FUN_003638E0 NONMATCHING


void FUN_003638e0(int *param_1,int param_2,int param_3,u32 param_4,int param_5)



{

  char cVar1;

  u32 uVar2;

  u32 lVar3;

  int lVar4;

  u32 uVar5;

  long uVar6;

  u32 uVar7;

  u16 *puVar8;

  int iVar9;

  int iVar10;

  long uVar11;

  int iVar12;

  u32 uVar13;

  u16 *puVar14;

  int lVar15;

  long lVar16;

  long lVar17;

  float fVar18;

  u32 iStack_10;

  u32 iStack_c;

  u32 iStack_8;

  u32 iStack_4;

  

  uVar7 = 1;

  iVar12 = (int)param_5;

  uVar2 = *(u32 *)(iVar12 + 4);

  puVar14 = (u16 *)param_3;

  if (param_3 != 0) {

    uVar13 = (u32)*puVar14;

  }

  else {

    uVar13 = *(u32 *)(iVar12 + 0x10);

  }

  puVar8 = (u16 *)param_2;

  if (param_2 != 0) {

    uVar5 = (u32)*puVar8;

  }

  else {

    uVar5 = *(u32 *)(iVar12 + 0x14);

  }

  if (uVar5 - uVar13 != 0) {

    fVar18 = (float)(int)(param_4 - uVar13) / (float)(int)(uVar5 - uVar13);

  }

  else {

    fVar18 = 0.0f;

  }

  iVar9 = *param_1;

  if (iVar9 == 0x24) {

    if (param_3 == 0) {

      if ((uVar2 & 8) == 0) {

        FUN_00397030(param_1[1]);

      }

    }

    else if (param_4 == *puVar14) {

      cVar1 = (char)puVar14[8];

      if (cVar1 == '\x02') {

        FUN_00396f50(param_1[1]);

      }

      else if (cVar1 == '\x01') {

        lVar3 = FUN_00396ed0(param_1[1]);

        if (lVar3 == 1) {

          iVar9 = param_1[1];

          if (iVar9 == 2) {

            *(u32 *)(iVar12 + 4) = *(u32 *)(iVar12 + 4) | 0x800;

          }

          else if (iVar9 == 1) {

            *(u32 *)(iVar12 + 4) = *(u32 *)(iVar12 + 4) | 0x400;

          }

          else if (iVar9 == 0) {

            *(u32 *)(iVar12 + 4) = *(u32 *)(iVar12 + 4) | 0x200;

          }

        }

        FUN_00396e30(param_1[1]);

      }

      else if (cVar1 == '\0') {

        lVar17 = 0;

        lVar16 = 0;

        lVar15 = 0;

        lVar3 = 0;

        uVar11 = (long)(short)puVar14[0xe];

        uVar6 = (long)(short)puVar14[0xf];

        if ((char)puVar14[0x10] == '\0') {

          lVar17 = (long)(short)puVar14[10];

          lVar16 = (long)(short)puVar14[0xb];

          lVar15 = (long)(short)puVar14[0xc];

          lVar3 = (long)(short)puVar14[0xd];

        }

        else if (((char)puVar14[0x10] == '\x01') &&

                (lVar4 = FUN_00397870(param_5,*(u8 *)((int)puVar14 + 0x21),&iStack_4,

                                      &iStack_8,&iStack_c,&iStack_10), lVar4 == 1)) {

          lVar17 = (long)iStack_4;

          lVar16 = (long)iStack_8;

          lVar15 = (long)iStack_c;

          lVar3 = (long)iStack_10;

        }

        FUN_00396c70(param_1[1],uVar11,uVar6,lVar17,lVar16,lVar15,lVar3,fVar18);

      }

    }

  }

  else if (iVar9 == 0x2b) {

    if (param_3 == 0) {

      if (((uVar2 & 8) == 0) && (param_4 == *(u32 *)(iVar12 + 0x10))) {

        FUN_0016d6b0(1,*(u16 *)(iVar12 + 0x8d4));

      }

    }

    else if (param_4 == *puVar14) {

      lVar3 = -1;

      switch((char)puVar14[8]) {

      case '\0':

        lVar3 = 5;

        break;

      case '\x01':

        lVar3 = 4;

        break;

      case '\x02':

        lVar3 = 3;

        break;

      case '\x03':

        lVar3 = 0;

        break;

      case '\x04':

        lVar3 = 1;

        break;

      case '\x05':

        lVar3 = 2;

      }

      if (lVar3 != -1) {

        FUN_00172820(lVar3);

      }

    }

  }

  else if (iVar9 == 0x27) {

    if ((param_3 != 0) && (*puVar14 == param_4)) {

      if ((char)puVar14[8] != '\0') {

        FUN_0036f490(1);

        iGpffffb904 = (int)(short)puVar14[10];

      }

      else {

        iGpffffb904 = 0;

        FUN_0036f490(0);

      }

      FUN_005225a8(0x69d680,uGpffffb900,iGpffffb904);

    }

  }

  else if (iVar9 != 0x19) {

    if (iVar9 == 8) {

      if (param_3 == 0) {

        *(u32 *)(iVar12 + 4) = *(u32 *)(iVar12 + 4) & 0xfffffffb;

      }

      else {

        if (puVar14[10] == 0) {

          uVar11 = puVar14[8];

          uVar6 = puVar14[9];

        }

        else {

          puVar8 = *(u16 **)(puVar14 + 0x26);

          if (puVar8 == (u16 *)0x0) {

            uVar11 = puVar14[8];

            uVar6 = puVar14[9];

          }

          else {

            iVar10 = param_4 - *puVar14;

            iVar9 = (u32)*puVar8 - (u32)*puVar14;

            uVar2 = (int)(short)puVar14[8] * (iVar9 - iVar10);

            uVar11 = (u16)((int)((uVar2 | (int)uVar2 >> 0x1f) + (short)puVar8[8] * iVar10) /

                             iVar9);

            uVar2 = (int)(short)puVar14[9] * (iVar9 - iVar10);

            uVar6 = (u16)((int)((uVar2 | (int)uVar2 >> 0x1f) + (short)puVar8[9] * iVar10) / iVar9

                            );

          }

        }

        if ((uVar11 == 0) && (uVar6 == 0)) {

          *(u32 *)(iVar12 + 4) = *(u32 *)(iVar12 + 4) & 0xfffffffb;

        }

        else {

          *(u32 *)(iVar12 + 4) = *(u32 *)(iVar12 + 4) | 4;

        }

      }

    }

    else if (iVar9 == 0x11) {

      if (param_3 != 0) {

        iVar9 = *(int *)(puVar14 + 0x24);

      }

      else {

        iVar9 = 0;

      }

      if (param_2 != 0) {

        iVar10 = *(int *)(puVar8 + 0x24);

      }

      else {

        iVar10 = 0;

      }

      if ((iVar9 != 0) || (iVar10 != 0)) {

        if (DAT_009584fc >> 0x18 == 0) {

          *(u32 *)(iVar12 + 0xfc) = 0;

        }

        else {

          *(u32 *)(iVar12 + 0xfc) = 1;

        }

      }

    }

    else if (iVar9 == 0x10) {

      if (param_3 != 0) {

        iVar9 = *(int *)(puVar14 + 0x24);

      }

      else {

        iVar9 = 0;

      }

      if (param_2 != 0) {

        iVar10 = *(int *)(puVar8 + 0x24);

      }

      else {

        iVar10 = 0;

      }

      if ((iVar9 != 0) || (iVar10 != 0)) {

        if (DAT_009584d0 >> 0x18 == 0) {

          *(u32 *)(iVar12 + 0xf8) = 0;

        }

        else {

          *(u32 *)(iVar12 + 0xf8) = 1;

        }

      }

    }

    else if (iVar9 == 0x1b) {

      if (param_3 != 0) {

        iVar9 = *(int *)(puVar14 + 0x24);

      }

      else {

        iVar9 = 0;

      }

      if (param_2 != 0) {

        iVar10 = *(int *)(puVar8 + 0x24);

      }

      else {

        iVar10 = 0;

      }

      if ((iVar9 != 0) || (iVar10 != 0)) {

        if (DAT_00958580 >> 0x18 == 0) {

          *(u32 *)(iVar12 + 0x278) = 0;

        }

        else {

          *(u32 *)(iVar12 + 0x278) = 1;

        }

      }

    }

    else if (iVar9 == 0x17) {

      if (param_3 != 0) {

        iVar9 = *(int *)(puVar14 + 0x24);

      }

      else {

        iVar9 = 0;

      }

      if (param_2 != 0) {

        iVar10 = *(int *)(puVar8 + 0x24);

      }

      else {

        iVar10 = 0;

      }

      if ((iVar9 != 0) || (iVar10 != 0)) {

        if (DAT_0095855c >> 0x18 == 0) {

          *(u32 *)(iVar12 + 0x100) = 0;

        }

        else {

          *(u32 *)(iVar12 + 0x100) = 1;

        }

      }

    }

    else if (iVar9 == 0xf) {

      if (param_3 != 0) {

        iVar9 = *(int *)(puVar14 + 0x24);

      }

      else {

        iVar9 = 0;

      }

      if (param_2 != 0) {

        iVar10 = *(int *)(puVar8 + 0x24);

      }

      else {

        iVar10 = 0;

      }

      if ((iVar9 != 0) || (iVar10 != 0)) {

        if (DAT_0095852c >> 0x18 == 0) {

          *(u32 *)(iVar12 + 0xf4) = 0;

        }

        else {

          *(u32 *)(iVar12 + 0xf4) = 1;

        }

      }

    }

    else if (iVar9 == 0xe) {

      if (param_3 != 0) {

        iVar9 = *(int *)(puVar14 + 0x24);

      }

      else {

        iVar9 = 0;

      }

      if (param_2 != 0) {

        iVar10 = *(int *)(puVar8 + 0x24);

      }

      else {

        iVar10 = 0;

      }

      if ((iVar9 != 0) || (iVar10 != 0)) {

        if (DAT_009584a4 >> 0x18 == 0) {

          *(u32 *)(iVar12 + 0xf0) = 0;

        }

        else {

          *(u32 *)(iVar12 + 0xf0) = 1;

        }

      }

    }

    else if (iVar9 == 0xd) {

      if (param_3 != 0) {

        iVar9 = *(int *)(puVar14 + 0x24);

      }

      else {

        iVar9 = 0;

      }

      if (param_2 != 0) {

        iVar10 = *(int *)(puVar8 + 0x24);

      }

      else {

        iVar10 = 0;

      }

      if ((iVar9 != 0) || (iVar10 != 0)) {

        if (DAT_00958470 >> 0x18 == 0) {

          *(u32 *)(iVar12 + 0xec) = 0;

        }

        else {

          *(u32 *)(iVar12 + 0xec) = 1;

        }

      }

    }

    else if (iVar9 != 0xb) {

      if (iVar9 == 10) {

        if (param_3 == 0) {

          iVar9 = 0;

        }

        else {

          iVar9 = *(int *)(puVar14 + 0x24);

          uVar7 = *(u32 *)(puVar14 + 2);

        }

        if (param_2 != 0) {

          iVar10 = *(int *)(puVar8 + 0x24);

        }

        else {

          iVar10 = 0;

        }

        if ((iVar9 != 0) || (iVar10 != 0)) {

          FUN_00394070(uVar7,iVar9,iVar10,0x958440);

          cVar1 = *(char *)((int)param_1 + 0x22);

          if (cVar1 != '\0') {

            if (cVar1 == '\x01') {

              if (param_3 != 0) {

                FUN_0038d560(param_1[1],1,0,(u32 *)0x958440,(u32 *)0x958450,(u32 *)0x958460);

              }

            }

            else {

              lVar3 = 0;

              if (cVar1 == '\x03') {

                lVar3 = (int)FUN_003b5d10_evt_main((short)param_1[9]);

                if (lVar3 == 0) {

                  return;

                }

                if (param_3 == 0) {

                  return;

                }

                if ((puVar14[1] != 0) && ((int)((u32)*puVar14 + (u32)puVar14[1]) < (int)param_4))

                {

                  return;

                }

              }

              else if (cVar1 == '\x02') {

                if (param_3 == 0) {

                  return;

                }

                if (((*puVar14 == param_4) && (puVar14[0xe] == 1)) &&

                   ((*(u32 *)(iVar12 + 4) & 1) == 0)) {

                  return;

                }

              }

              else {

                FUN_0019d3f0(0x69d580,0xd69);

              }

              FUN_0038d560(param_1[1],*(u8 *)((int)param_1 + 0x22),lVar3,(u32 *)0x958440,(u32 *)0x958450,

                           (u32 *)0x958460);

            }

          }

        }

      }

      else if (iVar9 == 6) {

        if (param_3 == 0) {

          if (((uVar2 & 8) == 0) && (*(int *)(iVar12 + 0x8dc) == 1)) {

            FUN_005225a8(0x69d670);

            FUN_001071b0();

            *(u32 *)(iVar12 + 0x8dc) = 0;

          }

        }

        else if (((uVar2 & 0x10) == 0) && (*puVar14 == param_4)) {

          if (puVar14[8] == 1) {

            if (puVar14[9] == 7) {

              *(u8 *)(iVar12 + 0x4c) = *(u8 *)(iVar12 + 0x4c) | 4;

            }

            else {

              *(u32 *)(iVar12 + 0x8dc) = 1;

              lVar3 = FUN_00108570();

              if (lVar3 == 1) {

                FUN_00108670(puVar14[9]);

                if (puVar14[1] != 0) {

                  FUN_001086a0(puVar14[1]);

                }

              }

            }

          }

          else if (puVar14[8] == 0) {

            *(u32 *)(iVar12 + 0x8dc) = 1;

            FUN_001085c0();

            if (puVar14[1] != 0) {

              FUN_001086a0(puVar14[1]);

            }

          }

        }

      }

    }

  }

  return;

}


// b210 floor: the only residual is call-argument setup order. At +0xc8/+0xcc,
// retail loads a2 before a0; at +0xec..+0x100, retail loads v0/addiu/andi,
// a3/t0 before a0, while b210 emits the independent a0 load first.
#pragma opt_lifetimes reset
// FUN_00364470

u16 * FUN_00364470(u32 param_1,int param_2)
{
  u16 *puVar1;
  u32 uVar2;
  int lVar3;
  u16 *puVar5;
  u32 uVar4;
  f32 stack[3];

  uVar4 = 0xffffffff;
  puVar5 = (u16 *)0x0;
  for (puVar1 = *(u16 **)(param_2 + 0x6c); puVar1 != (u16 *)0x0;
      puVar1 = *(u16 **)(puVar1 + 0x26)) {
    if (((((char)puVar1[8] == '\x04') && (lVar3 = FUN_00360ed0(puVar1), lVar3 != 0)) &&
        (uVar2 = (u32)*puVar1, (int)uVar2 <= (int)param_1)) && ((int)uVar4 < (int)uVar2)) {
      uVar4 = uVar2;
      puVar5 = puVar1;
    }
  }
  if (puVar5 == (u16 *)0x0) {
    return puVar5;
  }
  if (*puVar5 != param_1) {
    return puVar5;
  }
  stack[0] = 0;
  stack[1] = *(f32 *)(puVar5 + 10);
  stack[2] = 0;
  {
    short third;
    u16 first;
    third = *(volatile short *)(puVar5 + 0x12);
    first = *(volatile u16 *)(param_2 + 0xc);
    FUN_003b8b30(first,stack,third,0);
  }
  if ((char)puVar5[0x14] != '\0') {
    FUN_003bb1d0_evt_main(*(u16 *)(param_2 + 0xc),2,(u8)(*(char *)((int)puVar5 + 0x29) + 1),
                          (char)puVar5[0x15],*(char *)((int)puVar5 + 0x2b));
    FUN_005225a8((const char *)(DAT_006a0000 - 0x2960));
  }
  return puVar5;
}

// W295: the "call-argument setup order" here was fixable: retail loads the lh
// (arg3) before the stack fills and the lhu (arg1) last - two volatile-ordered
// temps reproduce it (same lever as FUN_00364470).
// FUN_003645C0

u16 * FUN_003645c0(u32 param_1,int param_2)
{
  u16 *puVar1;
  u32 uVar2;
  int lVar3;
  u16 *puVar5;
  u32 uVar4;
  f32 stack[3];

  uVar4 = 0xffffffff;
  puVar5 = (u16 *)0x0;
  for (puVar1 = *(u16 **)(param_2 + 0x6c); puVar1 != (u16 *)0x0;
      puVar1 = *(u16 **)(puVar1 + 0x26)) {
    if (((((char)puVar1[8] == '\n') && (lVar3 = FUN_00360ed0(puVar1), lVar3 != 0)) &&
        (uVar2 = (u32)*puVar1, (int)uVar2 <= (int)param_1)) && ((int)uVar4 < (int)uVar2)) {
      uVar4 = uVar2;
      puVar5 = puVar1;
    }
  }
  if (puVar5 == (u16 *)0x0) {
    return puVar5;
  }
  if (*puVar5 != param_1) {
    return puVar5;
  }
  {
    short third;
    u16 first;
    third = *(volatile short *)(puVar5 + 10);
    stack[2] = *(f32 *)(puVar5 + 0xc);
    stack[1] = stack[2];
    stack[0] = stack[2];
    first = *(volatile u16 *)(param_2 + 0xc);
    FUN_003b8c30(first,stack,third);
  }
  return puVar5;
}


/* W415: reordering only the cVar1==0/1 branches regressed nd 280 -> 286; switching
   on explicit cases 0, 1, and 2 instead gives nd 272, object 504/528. */
/* W367 pragma probe: opt_common_subs off nd 296 -> 280; on nd 296; object 512/528. */
#pragma opt_common_subs off
// FUN_003646D0 NONMATCHING


u16 * FUN_003646d0(u32 param_1,int param_2)



{

  char cVar1;

  u16 uVar2;

  u16 *puVar3;

  u8 *puVar4;

  u32 uVar5;

  u8 *puVar6;

  u32 lVar7;

  u32 lVar8;

  u8 *puVar9;

  u32 uVar10;

  u16 *puVar11;

  f32 uVar12;

  u8 auStack_10 [4];

  u32 uStack_c;

  u32 uStack_4;

  

  uVar10 = 0xffffffff;

  puVar11 = (u16 *)0x0;

  for (puVar3 = *(u16 **)(param_2 + 0x6c); puVar3 != (u16 *)0x0;

      puVar3 = *(u16 **)(puVar3 + 0x26)) {

    if (((((char)puVar3[8] == '\x03') && (puVar3[0xb] != 0)) &&

        (lVar7 = FUN_00360ed0_evt((u32)puVar3), lVar7 != 0)) &&

       ((uVar5 = (u32)*puVar3, (int)uVar5 <= (int)param_1 && ((int)uVar10 < (int)uVar5)))) {

      uVar10 = uVar5;

      puVar11 = puVar3;

    }

  }

  if ((puVar11 != (u16 *)0x0) && (*puVar11 == param_1)) {

    uVar2 = puVar11[0xb];

    cVar1 = (char)puVar11[10];

    switch (cVar1) {

    case '\0':

      FUN_003b8470(*(u16 *)(param_2 + 0xc),uVar2);

      break;

    case '\x01':

      uVar12 = FUN_0038a900(*(u8 *)((int)puVar11 + 0x15));

      uStack_4 = 0;

      lVar7 = FUN_003b5d10_evt(*(u16 *)(param_2 + 0xc));

      lVar8 = FUN_003b5d10_evt(uVar2);

      if ((lVar7 != 0) && (lVar8 != 0)) {

        FUN_003b86c0(uVar12,lVar7,(int)lVar8 + 4);

        lVar8 = FUN_003b8690((int)lVar7 + 4,(int)lVar8 + 4,&uStack_4);

        if (lVar8 == 1) {

          puVar6 = (u8 *)0xc;

          puVar9 = auStack_10;

          puVar4 = puVar9;

          while (puVar4 != (u8 *)0x0) {

            *puVar9 = 0;

            puVar9 = puVar9 + 1;

            puVar6 = puVar6 + -1;

            puVar4 = puVar6;

          }

          uStack_c = uStack_4;

          FUN_003b8a60(lVar7,auStack_10,0xf,0);

        }

      }

      FUN_005225a8((const char *)(DAT_006a0000 - 0x2950));

      break;

    case '\x02':

      break;

    }

  }

  return puVar11;

}


#pragma opt_common_subs reset
// FUN_003648E0


void FUN_003648e0(int param_1,u32 param_2,int param_3)



{

  u16 *puVar1;

  int lVar2;

  u32 uVar3;

  u16 *puVar5;
  u32 uVar4;

  

  uVar4 = 0xffffffff;

  puVar5 = (u16 *)0x0;

  for (puVar1 = *(u16 **)(param_3 + 0x6c); puVar1 != (u16 *)0x0;

      puVar1 = *(u16 **)(puVar1 + 0x26)) {

    if (((((char)puVar1[8] == '\0') && (lVar2 = FUN_00360ed0(puVar1), lVar2 != 0)) &&

        (uVar3 = (u32)*puVar1, (int)uVar3 <= (int)param_2)) && ((int)uVar4 < (int)uVar3)) {

      uVar4 = uVar3;

      puVar5 = puVar1;

    }

  }

  if (puVar5 == (u16 *)0x0) {
    if ((*(u32 *)(param_1 + 4) & 8) == 0) {
      if ((*(u32 *)(param_3 + 0x58) & 2) != 0) {
        FUN_003b9550(*(u16 *)(param_3 + 0xc),1);
      }
      else {
        FUN_003b9550(*(u16 *)(param_3 + 0xc),0);
      }
    }
    return;
  }

  if (*puVar5 == param_2) {
    if ((char)puVar5[10] == '\0') {
      FUN_003b9550(*(u16 *)(param_3 + 0xc),1);
    }
    else {
      FUN_003b9550(*(u16 *)(param_3 + 0xc),0);
    }
  }

  return;

}


// FUN_00364A30


void FUN_00364a30(u32 param_1,int param_2)



{

  u16 *puVar1;

  int lVar2;

  u32 uVar3;

  u16 *puVar5;

  u32 uVar4;

  

  uVar4 = 0xffffffff;

  puVar5 = (u16 *)0x0;

  for (puVar1 = *(u16 **)(param_2 + 0x6c); puVar1 != (u16 *)0x0;

      puVar1 = *(u16 **)(puVar1 + 0x26)) {

    if (((char)puVar1[8] == '\t') && (lVar2 = FUN_00360ed0(puVar1), lVar2 != 0)) {

      uVar3 = (u32)*puVar1;

      if (((int)uVar3 <= (int)param_1) && ((int)uVar4 < (int)uVar3)) {

        uVar4 = uVar3;

        puVar5 = puVar1;

      }

    }

  }

  if ((puVar5 != (u16 *)0x0) && (*puVar5 == param_1)) {

    lVar2 = (char)puVar5[10] == '\0';
    FUN_003bb180(*(u16 *)(param_2 + 0xc),lVar2);

  }

  return;

}


// FUN_00364B10 NONMATCHING


u16 * FUN_00364b10(u32 param_1,int param_2)



{

  char cVar1;

  u16 *puVar2;

  u8 *puVar3;

  u16 uVar4;

  u32 uVar5;

  int iVar6;

  u8 *puVar7;

  u32 lVar8;

  u8 *puVar9;

  u32 uVar10;

  u16 *puVar11;

  f32 uVar12;

  char acStack_170 [304];

  u32 uStack_40;
  u32 uStack_3c;
  u32 uStack_38;
  u32 uStack_30;
  u32 uStack_2c;
  u32 uStack_28;

  u8 auStack_20 [4];

  u32 uStack_1c;

  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;

  u32 uStack_4;

  

  uVar10 = 0xffffffff;

  puVar11 = (u16 *)0x0;

  for (puVar2 = *(u16 **)(param_2 + 0x6c); puVar2 != (u16 *)0x0;

      puVar2 = *(u16 **)(puVar2 + 0x26)) {

    if (((((char)puVar2[8] == '\x01') && (lVar8 = FUN_00360ed0(puVar2), lVar8 != 0)) &&

        (uVar5 = (u32)*puVar2, (int)uVar5 <= (int)param_1)) && ((int)uVar10 < (int)uVar5)) {

      uVar10 = uVar5;

      puVar11 = puVar2;

    }

  }

  if ((puVar11 != (u16 *)0x0) && (*puVar11 == param_1)) {

    cVar1 = (char)puVar11[10];
    switch (cVar1) {
    case '\0':
      uStack_10 = *(u32 *)(puVar11 + 0xc);
      uStack_c = *(u32 *)(puVar11 + 0xe);
      uStack_8 = *(u32 *)(puVar11 + 0x10);
      if (*(char *)((int)puVar11 + 0x15) == '\0') {
        uVar12 = FUN_0038a900(puVar11[0xb]);
        lVar8 = FUN_003b8730(uVar12,*(u16 *)(param_2 + 0xc),&uStack_10);
        if (lVar8 == 1) {
          *(u32 *)(param_2 + 100) = (u32)(*(char *)((int)puVar11 + 0x25) != '\0');
          if ((char)puVar11[0x1a] != '\0') {
            FUN_003bb1d0(*(u16 *)(param_2 + 0xc),1,*(char *)((int)puVar11 + 0x35) + '\x01',
                         (char)puVar11[0x1b],*(u8 *)((int)puVar11 + 0x37));
          }
          if ((char)puVar11[0x13] == '\0') {
            iVar6 = FUN_003b5d10(*(u16 *)(param_2 + 0xc));
            lVar8 = FUN_003b8690(iVar6 + 4,&uStack_10,&uStack_4);
            if (lVar8 == 1) {
              puVar7 = (u8 *)0xc;
              puVar9 = auStack_20;
              puVar3 = puVar9;
              while (puVar3 != (u8 *)0x0) {
                *puVar9 = 0;
                puVar9 = puVar9 + 1;
                puVar7 = puVar7 + -1;
                puVar3 = puVar7;
              }
              uStack_1c = uStack_4;
              FUN_003b8b30(*(u16 *)(param_2 + 0xc),auStack_20,0xf,0);
            }
          }
        }
      }
      break;
    case '\x01':
      FUN_0038d840((char *)(*(u32 *)(puVar11 + 0x20)),(u8 *)acStack_170,0);
      if (*(char *)((int)puVar11 + 0x15) == '\0') {
        uVar12 = FUN_0038a900(puVar11[0xb]);
        uVar4 = puVar11[0x12];
        cVar1 = *(char *)((int)puVar11 + 0x25);
        if ((char)puVar11[0x1a] != '\0') {
          FUN_003bb1d0(*(u16 *)(param_2 + 0xc),1,*(char *)((int)puVar11 + 0x35) + '\x01',
                       (char)puVar11[0x1b],*(u8 *)((int)puVar11 + 0x37));
        }
        if ('\0' < acStack_170[0]) {
          FUN_003b89f0(uVar12,*(u16 *)(param_2 + 0xc),acStack_170,(char)uVar4 != '\0');
          *(u32 *)(param_2 + 100) = (u32)(cVar1 != '\0');
          FUN_005225a8((const char *)(DAT_006a0000 - 0x2930));
        }
      }
      break;
    case '\x02':
      lVar8 = FUN_003b5d10(*(u16 *)(param_2 + 0xc));
      if (lVar8 != 0) {
        uStack_30 = *(u32 *)(puVar11 + 0xc);
        uStack_2c = *(u32 *)(puVar11 + 0xe);
        uStack_28 = *(u32 *)(puVar11 + 0x10);
        uStack_40 = *(u32 *)(puVar11 + 0x14);
        uStack_3c = *(u32 *)(puVar11 + 0x16);
        uStack_38 = 0;
        FUN_003b7460(lVar8,&uStack_30,&uStack_40,0);
      }
      break;
    }

  }

  return puVar11;

}


extern void FUN_00319090(void *param_1, f32 param_2);

// FUN_00364E40 NONMATCHING


void FUN_00364e40(u32 param_1,int param_2,int param_3)



{

  u16 *puVar1;

  u8 *puVar2;

  u8 *puVar3;

  int lVar4;

  u8 *puVar5;

  int iVar6;

  int iVar7;

  u16 *puVar8;

  float uVar9;

  u8 auStack_60 [32];

  u8 auStack_40 [32];

  u8 auStack_20 [16];

  u32 stack[3];

  

  iVar7 = 0;

  iVar6 = (int)(*(u16 *)(param_3 + 0xc) & 0xfc00) >> 10;

  if (iVar6 == 1) {

    lVar4 = FUN_003b5d10();

    if (lVar4 != 0) {

      iVar7 = *(int *)((int)lVar4 + 0x128);

    }

  }

  else if ((iVar6 == 3) && (lVar4 = FUN_003b5d10(), lVar4 != 0)) {

    iVar7 = *(int *)((int)lVar4 + 0x128);

  }

  puVar8 = (u16 *)0x0;

  for (puVar1 = *(u16 **)(param_3 + 0x6c); puVar1 != (u16 *)0x0;

      puVar1 = *(u16 **)(puVar1 + 0x26)) {

    if (((((char)puVar1[8] == '\x06') && (lVar4 = FUN_00360ed0(puVar1), lVar4 != 0)) &&

        ((int)(u32)*puVar1 <= (int)param_1)) && (puVar8 = puVar1, *puVar1 == param_1)) {

      if ((char)puVar1[10] == '\0') {

        if (iVar7 != 0) {

          uVar9 = *(float *)&DAT_007cadd0;

          if ((*(char *)((int)puVar1 + 0x15) != '\x01') &&

             (uVar9 = *(float *)&DAT_007cafec, *(char *)((int)puVar1 + 0x15) != '\0')) {

            uVar9 = 0.0f;

          }

          puVar3 = (u8 *)0xc;

          puVar5 = auStack_20;

          puVar2 = puVar5;

          while (puVar2 != (u8 *)0x0) {

            *puVar5 = 0;

            puVar5 = puVar5 + 1;

            puVar3 = puVar3 + -1;

            puVar2 = puVar3;

          }

          stack[0] = *(u32 *)(puVar1 + 0xc);

          stack[1] = *(u32 *)(puVar1 + 0xe);

          stack[2] = 0;

          FUN_003b79a0(auStack_60,auStack_20,stack);

          FUN_00319090((void *)iVar7,uVar9);

          FUN_00319100(iVar7,auStack_40);

        }

      }

      else if ((((char)puVar1[10] == '\x01') && (iVar7 != 0)) &&

              (lVar4 = FUN_003191d0(iVar7), lVar4 == 1)) {

        FUN_00319090((void *)iVar7,*(float *)&DAT_007cafec);

        FUN_00319190(iVar7);

      }

    }

  }

  if ((((puVar8 == (u16 *)0x0) && (*(u32 *)(param_2 + 0x10) == param_1)) && (iVar7 != 0)) &&

     (lVar4 = FUN_003191d0(iVar7), lVar4 == 1)) {

    FUN_00319090((void *)iVar7,*(float *)&DAT_007cafec);

    FUN_00319190(iVar7);

  }

  return;

}


// The first divergence suggests a 0x000ffc00 mask, but that informed spelling
// regressed nd219 -> nd224 and size392 -> 396, so it was reverted.
/* W367 pragma probe: opt_common_subs off nd 239 -> 170; on nd 239; object 400/400. */
#pragma opt_common_subs off
// FUN_003650C0 NONMATCHING


void FUN_003650c0(int param_1,u64 param_2,int param_3)



{

  u16 *puVar1;

  u32 lVar2;

  int iVar3;

  int iVar4;

  u16 *puVar5;

  

  iVar4 = 0;

  iVar3 = (int)(*(u16 *)(param_3 + 0xc) & 0xFC00) >> 10;

  switch (iVar3) {
  case 3:
    lVar2 = FUN_003b5d10();
    if (lVar2 != 0) {
      iVar4 = *(int *)((int)lVar2 + 0x128);
    }
    break;
  case 1:
    lVar2 = FUN_003b5d10();
    if (lVar2 != 0) {
      iVar4 = *(int *)((int)lVar2 + 0x128);
    }
    break;
  }

  if (iVar4 != 0) {

    puVar5 = (u16 *)0x0;

    for (puVar1 = *(u16 **)(param_3 + 0x6c); puVar1 != (u16 *)0x0;

        puVar1 = *(u16 **)(puVar1 + 0x26)) {

      if (((((char)puVar1[8] == '\a') && (lVar2 = FUN_00360ed0(puVar1), lVar2 != 0)) &&

          (*puVar1 <= param_1)) && (puVar5 = puVar1, *puVar1 == param_1)) {

        if ((char)puVar1[10] == '\0') {

          if (iVar4 != 0) {

            FUN_0039e880(param_2,iVar4,*(char *)((int)puVar1 + 0x15),(char)puVar1[0xb],

                         *(u32 *)(puVar1 + 0xc));

          }

        }

        else if (((char)puVar1[10] == '\x01') && (iVar4 != 0)) {

          FUN_0039ea20(iVar4,*(char *)((int)puVar1 + 0x15));

        }

      }

    }

    if ((puVar5 == (u16 *)0x0) && (iVar4 != 0)) {

      FUN_0039e820(iVar4);

    }

  }

  return;

}


// Corrected the case-0 byte contract to u8 (retail lbu). The seven remaining
// differing words are b210 call-argument setup order at +0x8c/+0x90 and
// +0xc8/+0xcc: retail materializes a1 before the independent a0 load.
#pragma opt_common_subs reset
// FUN_00365250


void FUN_00365250(u32 param_1,u64 param_2,int param_3)



{

  u16 *puVar1;

  u32 lVar2;

  u32 uStack_4;

  

  for (puVar1 = *(u16 **)(param_3 + 0x6c); puVar1 != (u16 *)0x0;

      puVar1 = *(u16 **)(puVar1 + 0x26)) {

    if (((((char)puVar1[8] == '\x05') && (lVar2 = FUN_00360ed0(puVar1), lVar2 != 0)) &&

        ((int)(u32)*puVar1 <= (int)param_1)) && (*puVar1 == param_1)) {

      switch (*(char *)((int)puVar1 + 0x15)) {
      case 0:
        FUN_003bb010_evt_main(*(u16 *)(param_3 + 0xc),(u8)puVar1[10]);
        break;
      case 1:
        uStack_4 = 0;
        lVar2 = FUN_00397630(param_2,(char)puVar1[10],&uStack_4);
        if (lVar2 == 1) {
          FUN_003bb010_evt_main(*(u16 *)(param_3 + 0xc),(u8)uStack_4);
        }
        break;
      }

    }

  }

  return;

}


// FUN_00365360


void FUN_00365360(u32 param_1,u64 param_2,int param_3)



{

  u16 *puVar1;

  int lVar2;

  u32 uVar3;

  u32 uVar4;

  u16 uVar7;

  u8 uVar8;

  short sVar6;

  u32 uVar5;

  

  uVar4 = 0xffffffff;

  for (puVar1 = *(u16 **)(param_3 + 0x6c); puVar1 != (u16 *)0x0;

      puVar1 = *(u16 **)(puVar1 + 0x26)) {

    if ((((char)puVar1[8] == '\b') && (lVar2 = FUN_00360ed0(puVar1), lVar2 != 0)) &&

       (uVar3 = (u32)*puVar1, (int)uVar3 <= (int)param_1)) {

      if ((int)uVar4 < (int)uVar3) {

        uVar4 = uVar3;

      }

      if (uVar3 == param_1) {

        uVar5 = 0;
        if (*(char *)((int)puVar1 + 0x19) != '\0') {
          uVar5 = 1;
        }
        sVar6 = *(volatile /* Removing this function's qualifier batch loses FUN_00365360 (MATCH nd0 -> MISMATCH nd6, size 208 -> 208) - measured W170. */ short *)((int)puVar1 + 0x14);
        uVar7 = *(volatile /* Removing this function's qualifier batch loses FUN_00365360 (MATCH nd0 -> MISMATCH nd6, size 208 -> 208) - measured W170. */ u16 *)(param_3 + 0xc);
        uVar8 = (u8)puVar1[0xc];
        FUN_003b8e10_evt(uVar7,uVar8,sVar6,uVar5);

      }

    }

  }

  return;

}


// Caller-specific absolute BYTE-base loads reproduce retail's shared DAT offsets.
// A typed aggregate assignment and early stack-pointer local now reproduce
// retail's load/store staging; five reloc-masked words remain as b210 choices:
// a1 setup, v0/v1 load coloring, and independent store/call setup.
/* W414 direct-width negative: replacing the EvtPosition65430 aggregate copy
 * with direct `xy`/`z` loads from DAT_006a0000_65430_abs emits lwc1/swc1,
 * but reorders the load/store schedule and measures nd17 (436/448) versus
 * the existing aggregate nd4. Reverted; do not retry this field split. */
// FUN_00365430 NONMATCHING


void FUN_00365430(int param_1,int param_2)



{

  int *piVar1;

  u32 lVar2;
  int iVar3;
  EvtPosition65430 position;
  EvtPosition65430 *positionPtr;

  

  iVar3 = (int)param_2;

  for (piVar1 = *(int **)(iVar3 + 0x84); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x25]) {

    if (((*piVar1 == 1) || (*piVar1 == 0x30)) &&

       (lVar2 = FUN_003b5d10_evt((u16)piVar1[3]), lVar2 != 0)) {

      if (((*(u32 *)(iVar3 + 4) & 8) == 0) && (param_1 == *(int *)(iVar3 + 0x10))) {

        FUN_003b78b0((u16)piVar1[3],piVar1 + 0xf,piVar1 + 0x12);
        positionPtr = &position;
        position = *(EvtPosition65430 *)(DAT_006a0000_65430_abs - 0x2918);
        FUN_003b7930((u16)piVar1[3],positionPtr);
        FUN_003b8f30((u16)piVar1[3]);
        FUN_003b8e10((u16)piVar1[3],*(u8 *)((int)piVar1 + 0x57),0,0);

        piVar1[0x19] = 0;

      }

      FUN_003646d0(param_1,(int)piVar1);

      FUN_00364b10(param_1,(int)piVar1);

      FUN_00364470(param_1,(int)piVar1);

      FUN_003645c0(param_1,(int)piVar1);

      FUN_003648e0(param_2,param_1,(int)piVar1);

      FUN_00364a30(param_1,(int)piVar1);

      FUN_003650c0_i(param_1,param_2,(int)piVar1);

      FUN_00364e40(param_1,param_2,(int)piVar1);

      FUN_00365250_i(param_1,param_2,(int)piVar1);

      FUN_00365360_i(param_1,param_2,(int)piVar1);

    }

  }

  return;

}


// FUN_003655F0 NONMATCHING


u16 * FUN_003655f0(u32 param_1,int param_2,int param_3)



{

  u16 *puVar1;

  u32 uVar2;

  u32 lVar3;

  u16 *puVar4;

  u32 uVar5;

  float stack20[3];

  float stack10[3];

  

  puVar4 = (u16 *)0x0;

  uVar5 = 0xffffffff;

  for (puVar1 = *(u16 **)(param_2 + 0x6c); puVar1 != (u16 *)0x0;

      puVar1 = *(u16 **)(puVar1 + 0x26)) {

    lVar3 = FUN_00360ed0(puVar1);

    if (((lVar3 != 0) && (uVar2 = (u32)*puVar1, (int)uVar2 <= (int)param_1)) &&

       ((int)uVar5 < (int)uVar2)) {

      uVar5 = uVar2;

      puVar4 = puVar1;

    }

  }

  switch (puVar4 != (u16 *)0x0) {
  case 1:
    switch (*puVar4 == param_1) {
    case 1:
      lVar3 = FUN_003b5d10(*(u16 *)(param_2 + 0xc));
      switch (lVar3 != 0) {
      case 1:
        switch ((char)puVar4[9]) {
        case 0:
          FUN_003bb400(0x1e58);
          stack20[0] = *(float *)(puVar4 + 0xc);
          stack20[1] = *(float *)(puVar4 + 0xe);
          stack20[2] = *(float *)(puVar4 + 0x10);
          stack10[0] = *(float *)(puVar4 + 0x12);
          stack10[1] = *(float *)(puVar4 + 0x14);
          stack10[2] = 0.0f;
          FUN_003b87f0(*(u16 *)(param_2 + 0xc),stack20,puVar4[1],(char)puVar4[0x18]);
          FUN_003b8b30(*(u16 *)(param_2 + 0xc),stack10,puVar4[1],(u8)puVar4[0x18]);
          FUN_003b8e80(*(u16 *)(param_2 + 0xc),*(float *)(puVar4 + 0x16),puVar4[1]);
          FUN_005225a8(DAT_0069d700_abs,puVar4[1]);
          break;
        case 1:
          if ((int)(puVar4[10] & 0xfc00) >> 10 != 0) {
            FUN_003bb390_evt((float)(int)(short)puVar4[0xb],0x1e58);
            FUN_005225a8(DAT_0069d720_abs);
          }
          break;
        }
        break;
      }
      break;
    }
    break;
  }

  return puVar4;

}


// FUN_003657E0


void FUN_003657e0(int param_1,int param_2)



{

  int iVar3;

  u32 lVar2;

  int *piVar1;

  

  iVar3 = (int)param_2;

  for (piVar1 = *(int **)(iVar3 + 0x84); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x25]) {

    if (*piVar1 == 0x21) {

      if (param_1 == *(int *)(iVar3 + 0x10)) {

        FUN_003bb400(0x1e58);

        FUN_003b78b0((u16)piVar1[3],piVar1 + 0xf,piVar1 + 0x12);

        FUN_003b8f30((u16)piVar1[3]);

        lVar2 = FUN_003b5d10(0x1e58);

        if (lVar2 != 0) {

          *(f32 *)((int)lVar2 + 0x100) = *(f32 *)(iVar3 + 0x8d0);

        }

      }

      FUN_003655f0(param_1,(int)piVar1,iVar3);

    }

  }

  return;

}


// FUN_003658B0 NONMATCHING


void FUN_003658b0(u32 param_1,int param_2)



{

  u16 *puVar1;

  u32 uVar2;

  u32 lVar3;

  u32 uVar4;

  int *piVar5;

  float fVar6;

  

  for (piVar5 = *(int **)(param_2 + 0x84); piVar5 != (int *)0x0; piVar5 = (int *)piVar5[0x25]) {

    if (*piVar5 == 0x2f) {

      uVar4 = 0xffffffff;

      for (puVar1 = (u16 *)piVar5[0x1b]; puVar1 != (u16 *)0x0;

          puVar1 = *(u16 **)(puVar1 + 0x26)) {

        lVar3 = FUN_00360ed0(puVar1);

        if (lVar3 != 0) {

          uVar2 = (u32)*puVar1;

          if (((int)uVar2 <= (int)param_1) && ((int)uVar4 < (int)uVar2)) {

            uVar4 = uVar2;

          }

          lVar3 = FUN_003b5d10(puVar1[9]);

          if ((lVar3 != 0) && (*puVar1 == param_1)) {

            switch ((char)puVar1[8]) {
            case 0:
              if ((char)puVar1[10] == '\0') {
                FUN_003b9500(lVar3,1);
              }
              else {
                FUN_003b9500(lVar3,0);
              }
              break;
            case 1:
              if ((short)puVar1[0xd] < 1) {
                fVar6 = 1.0f;
              }
              else {
                fVar6 = (float)(int)(short)puVar1[0xd] / 100.0f;
              }
              FUN_003b8ff0_evt(fVar6,lVar3,0,(char)puVar1[10],puVar1[0xb],
                           *(char *)((int)puVar1 + 0x15) == '\0',puVar1[0xc]);
              break;
            }
            ;

          }

        }

      }

    }

  }

  return;

}

// FUN_00365A40

void FUN_00365a40(u32 param_1,int param_2)
{
  u16 uVar1;
  int *piVar6;
  u16 *puVar2;
  u32 uVar3;
  u32 lVar4;
  u32 uVar5;

  for (piVar6 = *(int **)(param_2 + 0x84); piVar6 != (int *)0x0; piVar6 = (int *)piVar6[0x25]) {
    if (*piVar6 == 0x31) {
      uVar5 = 0xffffffff;
      for (puVar2 = (u16 *)piVar6[0x1b]; puVar2 != (u16 *)0x0;
          puVar2 = *(u16 **)(puVar2 + 0x26)) {
        lVar4 = FUN_00360ed0_evt((u32)puVar2);
        if (lVar4 != 0) {
          uVar3 = (u32)*puVar2;
          if (((int)uVar3 <= (int)param_1) && ((int)uVar5 < (int)uVar3)) {
            uVar5 = uVar3;
          }
          uVar1 = puVar2[9];
          lVar4 = FUN_003b5d10_evt(uVar1);
          if ((lVar4 != 0) && (*puVar2 == param_1)) {
            switch ((char)puVar2[8]) {
            case 0:
              if ((char)puVar2[10] == '\0') {
                FUN_003b9550_evt(uVar1,1);
              } else {
                FUN_003b9550_evt(uVar1,0);
              }
              break;
            }
          }
        }
      }
    }
  }
}



// FUN_00365B70


void FUN_00365b70(u32 param_1,u32 param_2)



{

  char cVar1;

  u32 lVar3;

  u32 uVar4;

  int *piVar7;

  

  for (piVar7 = *(int **)((int)param_2 + 0x84); piVar7 != (int *)0x0; piVar7 = (int *)piVar7[0x25])

  {

    if (*piVar7 == 0x23) {


      u16 *puVar2;

      u16 *puVar6;

      u32 uVar5;

      for (puVar2 = (uVar5 = 0xffffffff, puVar6 = (u16 *)0x0, (u16 *)piVar7[0x1b]); puVar2 != (u16 *)0x0;

          puVar2 = *(u16 **)(puVar2 + 0x26)) {

        lVar3 = FUN_00360ed0(puVar2);

        if (lVar3 != 0) {

          uVar4 = (u32)*puVar2;

          if (((int)uVar4 <= (int)param_1) && ((int)uVar5 < (int)uVar4)) {

            uVar5 = uVar4;

            puVar6 = puVar2;

          }

          if (((uVar4 == param_1) && (cVar1 = (char)puVar2[8], cVar1 != '\x03')) &&

             (cVar1 != '\x02')) {

            switch (cVar1) {
            case 0:
              FUN_00395430(param_2,piVar7[1],(s16)puVar2[0xc],(s16)puVar2[0xd],(s16)puVar2[0xe]);
              break;
            case 1:
              FUN_003954e0(piVar7[1]);
              break;
            }

          }

        }

      }

      if ((puVar6 == (u16 *)0x0) && (*(u32 *)((int)param_2 + 0x10) == param_1)) {

        FUN_003954e0(piVar7[1]);

      }

    }

  }

  return;

}


/* W415 negatives: reordering cVar1 branches ascending made nd 368 -> 377
   (object 644/688); an explicit 0..3 switch made nd 368 -> 376
   (object 652/688). Both probes were reverted.
   W417 negatives: switch-only nd 368 -> 376; untyped float locals exceeded
   the window; vector aggregate form before width fixes exceeded the window.
   W422 negative: changing the first state load cast from int to u32 stayed
   nd2/object684/window688; the v1->a0 branch-load coloring was unchanged. */
// FUN_00365CD0


void FUN_00365cd0(u32 param_1,int param_2)



{

  char cVar1;
  u8 mode;

  short uVar2;

  int *piVar8;

  u16 *puVar3;

  int lVar7;

  u16 sVar4;

  u16 uVar5;

  u32 lVar6;

  RwV3d pos0;

  RwV3d pos1;

  RwV3d pos2;
  RwV3d pos3;

  


  if (*(int *)(param_2 + 0x710) != 0) {
    if (param_1 == *(u32 *)(param_2 + 0x10)) {
      FUN_003969b0(*(int *)(param_2 + 0x710));

    }

    for (piVar8 = *(int **)(param_2 + 0x84); piVar8 != (int *)0x0; piVar8 = (int *)piVar8[0x25]) {

      if (*piVar8 == 0x25) {

        for (lVar7 = 0; lVar7 < 0x10; lVar7 = lVar7 + 1) {

          for (puVar3 = (u16 *)piVar8[0x1b]; puVar3 != (u16 *)0x0;

              puVar3 = *(u16 **)(puVar3 + 0x26)) {

            if ((((*(char *)((int)puVar3 + 0x11) == lVar7) &&

                 (lVar6 = FUN_00360ed0(puVar3), lVar6 != 0)) && ((int)(u32)*puVar3 <= (int)param_1)

                ) && (*puVar3 == param_1)) {

              cVar1 = (char)puVar3[8];
switch (cVar1) {
              case 0:
                FUN_00396760(*(u32 *)(param_2 + 0x710),lVar7,(char)puVar3[9],
                             *(char *)((int)puVar3 + 0x13) != '\0');
                sVar4 = FUN_003968a0(*(u32 *)(param_2 + 0x710),lVar7);
                if (sVar4 != 0) {
                  pos0.x = *(float *)((int)puVar3 + 0x14);
                  pos0.y = *(float *)((int)puVar3 + 0x18);
                  pos0.z = *(float *)((int)puVar3 + 0x1c);
                  pos1.x = *(float *)((int)puVar3 + 0x20);
                  pos1.y = *(float *)((int)puVar3 + 0x24);
                  pos1.z = *(float *)((int)puVar3 + 0x28);
                  FUN_003b78b0(sVar4,&pos0,&pos1);
                  FUN_005225a8(DAT_0069d738_abs);
                }
                break;
              case 1:
                sVar4 = FUN_003968a0(*(u32 *)(param_2 + 0x710),lVar7);
                if (sVar4 != 0) {
                  pos2.x = *(float *)((int)puVar3 + 0x14);
                  pos2.y = *(float *)((int)puVar3 + 0x18);
                  pos2.z = *(float *)((int)puVar3 + 0x1c);
                  pos3.x = *(float *)((int)puVar3 + 0x20);
                  pos3.y = *(float *)((int)puVar3 + 0x24);
                  pos3.z = *(float *)((int)puVar3 + 0x28);
                  uVar2 = puVar3[9];
                  FUN_003b87f0(sVar4,&pos2,uVar2,0);
                  FUN_003b8b30(sVar4,&pos3,uVar2,0);
                  FUN_005225a8(DAT_0069d748_abs);
                }
                break;
              case 2:
                FUN_00396910(*(u32 *)(param_2 + 0x710),lVar7);
                break;
              case 3:
                uVar5 = FUN_003968a0(*(u32 *)(param_2 + 0x710),lVar7);
                uVar2 = *(short *)((int)puVar3 + 0x14);
                mode = *(u8 *)((int)puVar3 + 0x12);
                FUN_003b8e10(uVar5,mode,uVar2,0);
                break;
              }
            }

          }

        }

      }

    }


  }
  return;

}


// FUN_00365F80 NONMATCHING


void FUN_00365f80(u32 param_1,u32 param_2)



{

  u16 *puVar1;

  bool bVar2;

  bool bVar3;


  short sVar5;

  u32 lVar6;

  int iVar7;

  int *piVar8;

  int iVar9;

  int iVar10;

  int iStack_8;

  int iStack_4;

  

  iStack_4 = 0;

  iStack_8 = 0;

  bVar2 = false;

  bVar3 = false;

  iVar7 = -1;

  sVar5 = 0;

  if (((param_2 != 0) && (iVar9 = (int)param_2, *(int *)(iVar9 + 8) != 0)) &&

     (lVar6 = FUN_0039eee0(iVar9 + 0x82c), lVar6 != 0)) {

    iVar10 = iVar7;

    for (piVar8 = *(int **)(iVar9 + 0x84); piVar8 != (int *)0x0; piVar8 = (int *)piVar8[0x25]) {

      if (*piVar8 == 4) {

        for (puVar1 = (u16 *)piVar8[0x1b]; puVar1 != (u16 *)0x0;

            puVar1 = *(u16 **)(puVar1 + 0x26)) {

          lVar6 = FUN_00360ed0(puVar1);

          if (((lVar6 != 0) && ((*(u32 *)(iVar9 + 4) & 0x10) == 0)) &&

             ((lVar6 = FUN_0038a4b0(param_2,(int)puVar1,(u32 *)&iStack_4,(u32 *)&iStack_8), lVar6 != 0 &&

              (*puVar1 == param_1)))) {

            lVar6 = FUN_0039f750(iVar9 + 0x82c,iStack_4);


            if (lVar6 == 0) {

              if ((char)puVar1[10] == '\0') {

                bVar2 = true;

              }

              iVar7 = iStack_4;

              if ((char)puVar1[0xb] == '\x01') {

                bVar3 = true;

              }

            }

            else {

              if ((iStack_8 == 0) || (10 < iStack_8)) {

                sVar5 = -1;

              }

              else {

                sVar5 = (short)iStack_8 + -1;

              }

              *(short *)(iVar9 + 0x266) = sVar5;

              if ((char)puVar1[10] == '\0') {

                bVar2 = true;

              }

              FUN_005225a8(0x69d760,iStack_4,param_1,sVar5 + -200);

              iVar10 = iStack_4;

            }

          }

        }

      }

    }

    if ((iVar7 != -1) || (iVar10 != -1)) {

      if (bVar2) {

        if (bVar3) {

          *(u32 *)(iVar9 + 4) = *(u32 *)(iVar9 + 4) | 0x8000;

        }

        else {

          *(u32 *)(iVar9 + 4) = *(u32 *)(iVar9 + 4) | 0x20;

        }

      }

      if (bVar3) {

        if ((*(u8 *)(iVar9 + 0x4c) & 8) != 0) {

          FUN_003c9790(iVar7);

        }

      }

      else {

        FUN_0039f210(iVar9 + 0x82c,iVar7,iVar10,sVar5);

      }

    }

  }

  return;

}


/* W367 pragma probe: opt_loop_invariants on nd 103 -> 91; off nd 103; object 288/288. */
#pragma opt_loop_invariants on
// FUN_00366210 NONMATCHING


void FUN_00366210(u32 param_1,int param_2)



{

  int *piVar1;

  u32 lVar2;

  u16 *puStack_4 = (u16 *)0x0;

  u32 uStack_8 = 0;

  for (piVar1 = *(int **)(param_2 + 0x84); (piVar1 != (int *)0x0 && (*piVar1 != 0x22));
      piVar1 = (int *)piVar1[0x25]) {
  }

  if (((piVar1 != (int *)0x0) &&

      (FUN_0038c460((long)piVar1,param_1,(int *)&puStack_4,(u32 *)&uStack_8), puStack_4 != (u16 *)0x0)) &&

     (*puStack_4 == param_1)) {

    if ((char)puStack_4[8] == '\0') {
      if (((lVar2 = FUN_0039eee0(param_2 + 0x82c), lVar2 != 0)) &&
          (lVar2 = FUN_0039f6e0(param_2 + 0x82c), lVar2 == 0)) {
        *(u32 *)(param_2 + 4) = *(u32 *)(param_2 + 4) | 0x20;
        FUN_005225a8(0x7cca70);
      }
    }
    else if ((char)puStack_4[8] == '\x01') {
      lVar2 = FUN_00108710();
      if (lVar2 == 0) {
        *(u32 *)(param_2 + 4) = *(u32 *)(param_2 + 4) | 0x2000;
      }
    }

  }

  return;

}


#pragma opt_loop_invariants reset
// FUN_00366330


void FUN_00366330(u32 param_1,int param_2)
{
  int *piVar3;

  u16 *puVar1;

  u32 lVar2;

  piVar3 = *(int **)(param_2 + 0x84);
  goto outer_check;
outer_body:
  if (*piVar3 == 0x26) {
    puVar1 = (u16 *)piVar3[0x1b];
    goto inner_check;
inner_body:
    lVar2 = FUN_00360ed0(puVar1);
    if ((lVar2 != 0) && (*puVar1 == param_1)) {
      *(int *)(param_2 + 0x28) = (int)(short)puVar1[8];
      *(u32 *)(param_2 + 0x24) = 1;
      return;
    }
    puVar1 = *(u16 **)(puVar1 + 0x26);
inner_check:
    if (puVar1 != (u16 *)0x0) goto inner_body;
  }
  piVar3 = (int *)piVar3[0x25];
outer_check:
  if (piVar3 != (int *)0x0) goto outer_body;
}


// FUN_003663F0


void FUN_003663f0(u32 param_1,int param_2)
{
  u16 *puVar1;
  u32 lVar2;
  int iVar3;
  int *piVar4;
  u32 aStack[4];

  piVar4 = *(int **)(param_2 + 0x84);
  goto outer_check;
outer_body:
  if (*piVar4 == 0x28) {
    puVar1 = (u16 *)piVar4[0x1b];
    goto inner_check;
inner_body:
    if ((FUN_00360ed0_evt((u32)puVar1) != 0) && (*puVar1 == param_1)) {
      iVar3 = 0;
      aStack[0] = (u32)(s32)(s8)*(u8 *)((u8 *)puVar1 + 0x10);
      aStack[1] = (u32)(s32)(s8)*(u8 *)((u8 *)puVar1 + 0x11);
      aStack[2] = (u32)(s32)(s8)*(u8 *)((u8 *)puVar1 + 0x12);
      aStack[3] = (u32)(s32)(s8)*(u8 *)((u8 *)puVar1 + 0x13);
      lVar2 = FUN_00388df0_evt(4,aStack);
      switch (lVar2) {
      case 0:
        iVar3 = (int)(short)puVar1[0xc];
        break;
      case 1:
        iVar3 = (int)(short)puVar1[0xd];
        break;
      case 2:
        iVar3 = (int)(short)puVar1[0xe];
        break;
      case 3:
        iVar3 = (int)(short)puVar1[0xf];
        break;
      }
      *(int *)(param_2 + 0x28) = iVar3;
      *(u32 *)(param_2 + 0x24) = 1;
      return;
    }
    puVar1 = *(u16 **)(puVar1 + 0x26);
inner_check:
    if (puVar1 != (u16 *)0x0) goto inner_body;
  }
  piVar4 = (int *)piVar4[0x25];
outer_check:
  if (piVar4 != (int *)0x0) goto outer_body;
}


// FUN_00366540


u16 * FUN_00366540(u32 param_1,int param_2,int param_3,int param_4)
{
  u16 *puVar1;
  char mode;
  u32 lVar2;
  u16 *puVar4;
  s32 uVar3;
  int iStack_4;
  u32 uStack_8;

  puVar4 = (u16 *)0x0;
  uVar3 = -1;
  puVar1 = *(u16 **)(param_2 + 0x6c);
  while (puVar1 != (u16 *)0x0) {
    if (*puVar1 <= param_3) {
      mode = (char)puVar1[0x11];
      if (mode == '\0') {
        lVar2 = (int)(char)puVar1[10];
      }
      else {
        if (mode != '\x01') {
          goto next;
        }
        iStack_4 = 0;
        uStack_8 = 0;
        lVar2 = FUN_003976f0(param_1,*(char *)((int)puVar1 + 0x15),&iStack_4,&uStack_8);
        if (lVar2 == 0) {
          goto next;
        }
        lVar2 = iStack_4;
      }
      if (((uVar3 < *puVar1) && ((char)puVar1[8] == '\x02')) &&
          (lVar2 == param_4) && (FUN_00360ed0(puVar1) == 1)) {
        uVar3 = *puVar1;
        puVar4 = puVar1;
      }
    }
next:
    puVar1 = *(u16 **)(puVar1 + 0x26);
  }
  return puVar4;
}


/* W367 pragma probe: opt_lifetimes on nd 404 -> 301; off nd 404; object 780/784. */
#pragma opt_lifetimes on
// FUN_00366660 NONMATCHING


void FUN_00366660(u32 param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5)



{

  u32 bVar1;

  char cVar2;

  u32 lVar3;

  int iVar4;

  u16 *puVar5;

  u32 uVar6;

  u32 uVar7;

  int iVar8;

  int unaff_s8;

  float fVar9;

  int uStack_20;

  int iStack_10;

  u32 uStack_c;

  int iStack_8;

  u8 auStack_4 [4];

  

  iVar8 = 0;

  puVar5 = (u16 *)param_2;

  iVar4 = (int)(*puVar5 & 0xffc00) >> 10;

  if (iVar4 == 1) {

    iVar8 = *(int *)(puVar5 + 0x94);

  }

  else if (iVar4 == 3) {

    iVar8 = *(int *)(puVar5 + 0x94);

  }

  if ((iVar8 != 0) && (lVar3 = FUN_003185b0(iVar8,0), lVar3 != 0)) {

    for (uVar7 = 0; (int)uVar7 < 4; uVar7 = uVar7 + 1) {

      lVar3 = FUN_003185b0(iVar8,uVar7 & 0xffff);

      if ((lVar3 != 0) && (lVar3 = FUN_00366540_evt_u32(param_4,param_3,param_1,uVar7), lVar3 != 0)) {

        puVar5 = (u16 *)lVar3;

        if ((char)puVar5[0xb] != '\0') {
          bVar1 = 1;
        }
        else {
          bVar1 = 0;
        }

        cVar2 = (char)puVar5[0x11];

        if (bVar1) {

          FUN_00318870(iVar8,uVar7 & 0xffff);

        }

        if (*puVar5 == param_1) {

          if (cVar2 == '\0') {

            unaff_s8 = (int)*(char *)((int)puVar5 + 0x15);

            uStack_20 = *(char *)((int)puVar5 + 0x17);

          }

          else if (cVar2 == '\x01') {

            lVar3 = FUN_003976f0(param_4,*(char *)((int)puVar5 + 0x15),auStack_4,&iStack_8);

            if (lVar3 != 1) goto LAB_00366928;

            unaff_s8 = iStack_8;

            uStack_20 = *(char *)((int)puVar5 + 0x17);

          }

          if (*(s16 *)((u8 *)puVar5 + 0x20) < 1) {

            iVar4 = 0;

          }

          else {

            iVar4 = (int)(float)*(s16 *)((u8 *)puVar5 + 0x20);

          }

          if (*(s16 *)((u8 *)puVar5 + 0x28) < 1) {

            fVar9 = 1.0f;

          }

          else {

            fVar9 = (float)*(s16 *)((u8 *)puVar5 + 0x28) / 100.0f;

          }

          FUN_003b8ff0_evt_wide(fVar9,param_2,uVar7,unaff_s8,uStack_20,bVar1,iVar4);

          if (*(char *)((int)puVar5 + 0x23) == '\x01') {

            if (cVar2 != '\0') {

              if ((cVar2 != '\x01') ||

                 (lVar3 = FUN_003976f0(param_4,(char)puVar5[0x12],&uStack_c,&iStack_10), lVar3 != 1)

                 ) goto LAB_00366928;

              lVar3 = (u32)iStack_10;

              uVar6 = uStack_c;

            }

            else {

              lVar3 = (long)(char)puVar5[0x12];

              uVar6 = uVar7;

            }

            if (*(s16 *)((u8 *)puVar5 + 0x2a) < 1) {

              fVar9 = 1.0f;

            }

            else {

              fVar9 = (float)*(s16 *)((u8 *)puVar5 + 0x2a) / 100.0f;

            }

            FUN_003b9260_evt_wide(fVar9,(u32)param_2,uVar6,(u32)lVar3,
                                  *(s16 *)((u8 *)puVar5 + 0x26),
                                  *(char *)((int)puVar5 + 0x25) == '\0',0);

          }

          *(u16 **)((int)param_3 + uVar7 * 4 + 0x74) = puVar5;

        }

      }

LAB_00366928:;

    }

  }

  return;

}


#pragma opt_lifetimes reset
/* W367 pragma probe: opt_lifetimes on nd 135 -> 125; off nd 135; object 300/336. */
#pragma opt_lifetimes on
// FUN_00366970 NONMATCHING


void FUN_00366970(u32 param_1,u32 param_2)
{
  u8 *event;
  u8 *candidate;
  u8 *matched;

  event = (u8 *)FUN_003b5d00();
  if (event != NULL) {
    candidate = *(u8 **)(event + 4);
    while (candidate != NULL) {
      matched = NULL;
      event = *(u8 **)(param_2 + 0x84);
      while (event != NULL) {
        if (*(u8 **)(event + 0x38) == candidate) {
          matched = event;
          break;
        }
        event = *(u8 **)(event + 0x94);
      }
      if (matched != NULL) {
        FUN_00366660(param_1,(u32)candidate,(u32)event,param_2,0);
      }
      candidate = *(u8 **)(candidate + 0xf8);
    }

    candidate = (u8 *)FUN_003b5d50(3);
    while (candidate != NULL) {
      matched = NULL;
      event = *(u8 **)(param_2 + 0x84);
      while (event != NULL) {
        if (*(u8 **)(event + 0x38) == candidate) {
          matched = event;
          break;
        }
        event = *(u8 **)(event + 0x94);
      }
      if (matched != NULL) {
        FUN_00366660(param_1,(u32)candidate,(u32)event,param_2,0);
      }
      candidate = *(u8 **)(candidate + 0xf8);
    }
  }
}


#pragma opt_lifetimes reset
/* W367 stacked probe: opt_loop_invariants + opt_lifetimes nd 451 -> 431; singles 447/436; object 984/992. */
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
// FUN_00366AC0 NONMATCHING


void FUN_00366ac0(u32 param_1,u32 param_2)



{

  u32 uVar1;

  int *piVar2;

  u16 *puVar3;

  u32 bVar4;

  int lVar5;

  int iVar6;

  int iVar7;

  int unaff_s2;

  

  iVar6 = (int)param_2;

  uVar1 = *(u32 *)(iVar6 + 4);

  uVar1 &= 0xfffffffd;
  *(u32 *)(iVar6 + 4) = uVar1;
  uVar1 &= 0xfffffffb;
  *(u32 *)(iVar6 + 4) = uVar1;

  *(u32 *)(iVar6 + 0xec) = 0;

  *(u32 *)(iVar6 + 0xf0) = 0;

  *(u32 *)(iVar6 + 0xf8) = 0;

  *(u32 *)(iVar6 + 0xfc) = 0;

  *(u32 *)(iVar6 + 0xf4) = 0;

  *(u32 *)(iVar6 + 0x100) = 0;

  *(u32 *)(iVar6 + 0x278) = 0;

  FUN_0038ca00();

  FUN_00366970(param_1,param_2);

  FUN_00365430(param_1,param_2);

  FUN_003657e0(param_1,param_2);

  FUN_003658b0(param_1,param_2);

  FUN_00365a40(param_1,param_2);

  FUN_00365b70(param_1,param_2);

  FUN_00365cd0(param_1,param_2);

  FUN_00365f80(param_1,param_2);

  for (piVar2 = *(int **)(iVar6 + 0x84); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0x25]) {

    iVar7 = *piVar2;

    if (iVar7 != 1) {

      if ((((((iVar7 == 0x2e) || (iVar7 == 0x2d)) || (iVar7 == 0x2c)) ||

           ((iVar7 == 0x2a || (iVar7 == 0x1d)))) ||

          ((iVar7 == 0x1c || ((iVar7 == 7 || (iVar7 == 0x13)))))) ||

         ((iVar7 == 0x32 || ((iVar7 == 5 || (iVar7 == 0x29)))))) {

        bVar4 = true;

      }

      else {

        bVar4 = false;

      }

      if (bVar4) {

        for (puVar3 = (u16 *)piVar2[0x1b]; puVar3 != (u16 *)0x0;

            puVar3 = *(u16 **)(puVar3 + 0x26)) {

          lVar5 = FUN_00360ed0(puVar3);

          if ((lVar5 != 0) &&

             (((unaff_s2 == 0 && (param_1 == *puVar3)) ||

              ((0 < unaff_s2 &&

               (((int)(u32)*puVar3 <= (int)param_1 &&

                ((int)param_1 < (int)((u32)*puVar3 + (int)unaff_s2))))))))) {

            FUN_00363030(piVar2,puVar3,param_1,(u8 *)param_2);

          }

        }

      }

    }

  }

  for (piVar2 = *(int **)(iVar6 + 0x84); piVar2 != (int *)0x0; piVar2 = (int *)piVar2[0x25]) {

    iVar7 = *piVar2;

    if ((((iVar7 == 0x24) || (iVar7 == 0x2b)) || (iVar7 == 0x27)) || ((iVar7 == 10 || (iVar7 == 6)))

       ) {

      bVar4 = true;

    }

    else {

      bVar4 = false;

    }

    if (bVar4) {

      iVar7 = piVar2[8];

      for (puVar3 = (u16 *)piVar2[0x1b];

          (puVar3 != (u16 *)0x0 &&

          ((lVar5 = FUN_00360ed0(puVar3), lVar5 == 0 ||

           ((int)((u32)*puVar3 + (int)(short)iVar7) <= (int)param_1))));

          puVar3 = *(u16 **)(puVar3 + 0x26)) {

      }

      if (puVar3 == (u16 *)0x0) {

        iVar7 = piVar2[0x1c];

      }

      else {

        iVar7 = *(int *)(puVar3 + 0x28);

      }

      lVar5 = FUN_0036f500_s32(*piVar2);

      if (lVar5 == 1) {

        while ((iVar7 != 0 && (lVar5 = FUN_00360ed0(iVar7), lVar5 != 1))) {

          iVar7 = *(int *)(iVar7 + 0x50);

        }

      }

      FUN_003638e0(piVar2,(u32)puVar3,iVar7,param_1,param_2);

    }

  }

  FUN_00366210(param_1,param_2);

  FUN_00366330(param_1,param_2);

  FUN_003663f0(param_1,param_2);

  if (((*(u32 *)(iVar6 + 4) & 1) != 0) && ((*(u32 *)(iVar6 + 4) & 2) == 0)) {

    FUN_003bcc80();

  }

  return;

}


#pragma opt_lifetimes reset
#pragma opt_loop_invariants reset
// FUN_00366EA0
u32 FUN_00366ea0(void)
{
  return 0;
}

// FUN_00366EB0


int FUN_00366eb0(int param_1,int param_2,int param_3)



{

  int iVar2;

  int iVar1;

  int iVar3;
  int iVar4;

  

  iVar3 = (int)param_3;

  if (*(int *)(iVar3 + 0x164) == 0) {

    iVar2 = 0;

  }

  else {


    iVar2 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);
    iVar1 = 0;
    iVar4 = *(int *)(iVar3 + 0x160) + *(int *)(iVar3 + 0x15c);
    for (;
        (iVar1 < iVar4 && (iVar2 != 0));
        iVar2 = *(int *)(iVar2 + 0x4c), iVar1 = iVar1 + 1) {
    }

  }

  if (iVar2 == 0) {
    return 0;
  }
  *(u32 *)(iVar2 + 0x14) = *(u32 *)(iVar3 + 0x16c);

  *(short *)(iVar2 + 0x20) = (short)*(u32 *)(iVar3 + 0x198);

  *(char *)(iVar2 + 0x22) = (char)*(u32 *)(iVar3 + 0x19c);

  *(char *)(iVar2 + 0x23) = (char)*(u32 *)(iVar3 + 0x1a0);

  *(char *)(iVar2 + 0x24) = (char)*(u32 *)(iVar3 + 0x1a4);

  *(char *)(iVar2 + 0x25) = (char)*(u32 *)(iVar3 + 0x1a8);

  *(short *)(iVar2 + 0x26) = (short)*(u32 *)(iVar3 + 0x1ac);

  *(short *)(iVar2 + 0x28) = (short)*(u32 *)(iVar3 + 0x1b0);

  *(short *)(iVar2 + 0x2a) = (short)*(u32 *)(iVar3 + 0x1b4);

  FUN_0036f640(param_3);

  return 0;

}


// Removed an invented cast-only base local so the function uses param_3 directly.
// This improves nd245 -> nd244 at unchanged size348/352; the remaining first
// divergence is saved-register coloring and load/branch scheduling.
/* W367 pragma probe: opt_common_subs off nd 244 -> 212; on nd 244; object 348/352. */
#pragma opt_common_subs off
// FUN_00366F90 NONMATCHING


u64 FUN_00366f90(u64 param_1,u64 param_2,u32 param_3)



{

  int iVar1;

  u16 *puVar2;


  int iVar4;

  


  iVar4 = *(volatile int *)(param_3 + 0x110);
  iVar1 = *(volatile int *)(param_3 + 0x108);
  iVar1 += iVar4;

  if (iVar1 == 0) {

    *(u8 *)(*(int *)(param_3 + 0x164) + 0x22) = 0;

  }

  else if (iVar1 == 1) {

    *(u8 *)(*(int *)(param_3 + 0x164) + 0x22) = 1;

  }

  else if (iVar1 == 2) {

    *(u8 *)(*(int *)(param_3 + 0x164) + 0x22) = 2;

  }

  else {

    *(u8 *)(*(int *)(param_3 + 0x164) + 0x22) = 3;

    iVar4 = 0;

    iVar1 = *(int *)(param_3 + 0x108) + *(int *)(param_3 + 0x110) + -3;

    *(u16 *)(*(int *)(param_3 + 0x164) + 0x24) = 0;

    for (puVar2 = (u16 *)FUN_003b5d50(); puVar2 != (u16 *)0x0;

        puVar2 = *(u16 **)(puVar2 + 0x7c)) {

      if (iVar4 == iVar1) {

        *(u16 *)(*(int *)(param_3 + 0x164) + 0x24) = *puVar2;

        break;

      }

      iVar4 = iVar4 + 1;

    }

    if (*(short *)(*(int *)(param_3 + 0x164) + 0x24) == 0) {

      for (puVar2 = (u16 *)FUN_003b5d50(1); puVar2 != (u16 *)0x0;

          puVar2 = *(u16 **)(puVar2 + 0x7c)) {

        if (iVar4 == iVar1) {

          *(u16 *)(*(int *)(param_3 + 0x164) + 0x24) = *puVar2;

          break;

        }

        iVar4 = iVar4 + 1;

      }

    }

  }

  FUN_0036f640(param_3);

  return 0;

}


#pragma opt_common_subs reset
// FUN_003670F0

u32 FUN_003670f0(int param_1,int param_2,int param_3)



{

  int iVar2;

  int iVar1;

  int iVar3;

  int iVar4;

  

  iVar3 = (int)param_3;

  if (*(int *)(iVar3 + 0x164) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);
    iVar1 = 0;
    iVar4 = *(int *)(iVar3 + 0x160) + *(int *)(iVar3 + 0x15c);
    for (; (iVar1 < iVar4 && (iVar2 != 0)); iVar1 = iVar1 + 1) {
      iVar2 = *(int *)(iVar2 + 0x4c);
    }

  }

  if (iVar2 == 0) {
    return 0;
  }

  *(u32 *)(iVar2 + 0x14) = *(u32 *)(iVar3 + 0x16c);

  FUN_0036f640_evt(param_3);

  return 0;

}


// FUN_00367190


u32 FUN_00367190(int param_1,int param_2,int param_3)



{

  int iVar2;

  int iVar1;

  int iVar3;

  int iVar4;


  

  iVar3 = (int)param_3;

  if (*(int *)(iVar3 + 0x164) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);

    iVar1 = 0;

    iVar4 = *(int *)(iVar3 + 0x160) + *(int *)(iVar3 + 0x15c);

    for (;

        (iVar1 < iVar4 && (iVar2 != 0));) {

      iVar2 = *(int *)(iVar2 + 0x4c);

      iVar1 = iVar1 + 1;

    }

  }

  if (iVar2 == 0) {

    return 0;

  }

  *(u32 *)(iVar2 + 0x14) = *(u32 *)(iVar3 + 0x19c);

  *(short *)(iVar2 + 0x18) = (short)*(u32 *)(iVar3 + 0x1a0);

  FUN_0036f640(param_3);

  return 0;

}


// FUN_00367230 NONMATCHING


u64 FUN_00367230(u64 param_1,u64 param_2,int param_3)



{

  int *piVar1;
  int hasWork;

  int iVar2;

  int iVar4;

  int iVar3;
  int limit;

  

  iVar2 = (int)param_3;
  hasWork = *(int *)(iVar2 + 0x238);
  piVar1 = *(int **)(iVar2 + 0x164);
  if (piVar1 == (int *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = piVar1[0x1b];
    iVar3 = 0;
    limit = *(int *)(iVar2 + 0x160) + *(int *)(iVar2 + 0x15c);
    while ((iVar3 < limit) && (iVar4 != 0)) {
      iVar4 = *(int *)(iVar4 + 0x4c);
      iVar3 = iVar3 + 1;
    }
  }
  if ((iVar4 != 0) && (hasWork != 0)) {
    switch (*piVar1) {
    case 1:
    case 0x30:

      if (*(int *)(iVar2 + 400) == 3) {

        *(u32 *)(iVar2 + 400) = 0;

        *(int *)(iVar2 + 0x1b8) = (int)*(char *)(iVar4 + 0x28);

        *(int *)(iVar2 + 0x1bc) = (int)*(char *)(iVar4 + 0x29);

        *(int *)(iVar2 + 0x1c0) = (int)*(char *)(iVar4 + 0x2a);

        *(int *)(iVar2 + 0x1c4) = (int)*(char *)(iVar4 + 0x2b);

        FUN_0036f5f0(0x2e,0xc,0x18,param_3);

        return 0;

      }

      *(float *)(iVar4 + 0x14) = (float)*(int *)(iVar2 + 0x198);

      *(short *)(iVar4 + 0x24) = (short)*(u32 *)(iVar2 + 0x16c);

      FUN_0038a620(param_3,1);

      break;
    default:
      FUN_0019d3f0(DAT_0069d580_abs,0x1aa3);
      break;
    }

    FUN_0036f640(param_3);

  }

  return 0;

}


// FUN_00367390


u64 FUN_00367390(u64 param_1,u64 param_2,int param_3)



{

  struct Pair {
    short a;
    short b;
    short c;
    short d;
  };
  struct Pair *src;
  struct Pair *dst;

  int iVar6;

  int iVar4;

  int iVar5;

  int iVar7;

  

  iVar5 = (int)param_3;

  if (*(int *)(iVar5 + 0x164) == 0) {

    iVar6 = 0;

  }

  else {

    iVar6 = *(int *)(*(int *)(iVar5 + 0x164) + 0x6c);

    iVar4 = 0;

    iVar7 = *(int *)(iVar5 + 0x160) + *(int *)(iVar5 + 0x15c);

    for (; (iVar4 < iVar7 && (iVar6 != 0));) {

      iVar6 = *(int *)(iVar6 + 0x4c);

      iVar4 = iVar4 + 1;

    }

  }

  if (iVar6 == 0) {

    return 0;

  }

  src = (struct Pair *)(iVar5 + 0x784);
  dst = (struct Pair *)(iVar6 + 8);
  *dst = *src;

  FUN_0036f640(param_3);

  return 0;

}


// FUN_00367440

u32 FUN_00367440(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;
  int iVar4;

  

  iVar3 = (int)param_3;

  if (*(int *)(iVar3 + 0x164) != 0) {

    iVar1 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);
    iVar2 = 0;
    iVar4 = *(int *)(iVar3 + 0x160) + *(int *)(iVar3 + 0x15c);

    for (; (iVar2 < iVar4 && (iVar1 != 0));) {
      iVar1 = *(int *)(iVar1 + 0x4c);
      iVar2 = iVar2 + 1;
    }

  }

  FUN_0036f640(param_3);

  return 0;

}


/* W367 pragma probe: opt_common_subs off nd 836 -> 766; on nd 836; object 1388/1392. */
#pragma opt_common_subs off
// FUN_003674B0 NONMATCHING


u64 FUN_003674b0(u64 param_1,u64 param_2,u32 *param_3)



{

  int *piVar1;

  u32 *puVar2;

  int iVar3;

  int iVar5;
  int iVar6;

  u8 *iVar4;

  u32 *puStack_28;

  int *piStack_24;

  u8 auStack_20 [4];

  int iStack_1c;

  float *puStack_18;

  float *puStack_14;

  float *puStack_10;

  float *puStack_c;

  float *puStack_8;

  u32 uStack_4;

  

  piVar1 = *(int **)((int)param_3 + 0x164);

  iVar4 = (u8 *)param_3;

  if (piVar1 == (int *)0x0) {

    iVar5 = 0;

  }

  else {

    iVar5 = piVar1[0x1b];
    iVar3 = 0;
    iVar6 = *(int *)(iVar4 + 0x160) + *(int *)(iVar4 + 0x15c);
    for (;
        (iVar3 < iVar6 && (iVar5 != 0));
        iVar5 = *(int *)(iVar5 + 0x4c), iVar3 = iVar3 + 1) {
    }

  }

  switch(*(u32 *)(iVar4 + 0x16c)) {

  case 0:

    *(short *)(iVar5 + 0x14) = (short)*(u32 *)(iVar4 + 0x198);

    *(short *)(iVar5 + 0x16) = (short)*(u32 *)(iVar4 + 0x19c);

    *(short *)(iVar5 + 0x18) = (short)*(u32 *)(iVar4 + 0x1a0);

    *(short *)(iVar5 + 0x1a) = (short)*(u32 *)(iVar4 + 0x1a4);

    *(short *)(iVar5 + 0x1c) = (short)*(u32 *)(iVar4 + 0x1a8);

    break;

  case 1:

    *(short *)(iVar5 + 0x14) = (short)*(u32 *)(iVar4 + 0x198);

    *(short *)(iVar5 + 0x16) = (short)*(u32 *)(iVar4 + 0x19c);

    *(short *)(iVar5 + 0x18) = (short)*(u32 *)(iVar4 + 0x1a0);

    break;

  case 2:

    *(u32 *)(iVar4 + 0x3c) = *(u32 *)(iVar4 + 0x198);

    *(u32 *)(iVar4 + 0x40) = *(u32 *)(iVar4 + 0x19c);

    *(char *)(iVar4 + 0x46) = (char)*(u32 *)(iVar4 + 0x1a0);

    *(short *)(iVar4 + 0x48) = (short)*(u32 *)(iVar4 + 0x1a4);

    break;

  case 3:

    *(char *)(iVar4 + 0x44) = (char)*(u32 *)(iVar4 + 0x198);

    break;

  case 4:

    puVar2 = *(u32 **)(iVar5 + 0x48);

    puVar2[8] = *(u32 *)(iVar4 + 0x198);

    puVar2[9] = *(u32 *)(iVar4 + 0x19c);

    puVar2[10] = *(u32 *)(iVar4 + 0x1a0);

    *puVar2 = *(u32 *)(iVar4 + 0x1a4);

    puVar2[1] = *(u32 *)(iVar4 + 0x1a8);

    puVar2[2] = *(u32 *)(iVar4 + 0x1ac);

    puVar2[4] = *(u32 *)(iVar4 + 0x1b4);

    puVar2[5] = *(u32 *)(iVar4 + 0x1b0);

    FUN_0038b140(*(u32 *)(iVar4 + 0x210));

    break;

  case 5:

    *(short *)(iVar5 + 0x14) = (short)*(u32 *)(iVar4 + 0x198);

    *(short *)(iVar5 + 0x16) = (short)*(u32 *)(iVar4 + 0x19c);

    *(short *)(iVar5 + 0x18) = (short)*(u32 *)(iVar4 + 0x1a0);

    *(short *)(iVar5 + 0x1a) = (short)*(u32 *)(iVar4 + 0x1a4);

    *(short *)(iVar5 + 0x1c) = (short)*(u32 *)(iVar4 + 0x1a8);

    *(short *)(iVar5 + 0x1e) = (short)*(u32 *)(iVar4 + 0x1ac);

    break;

  case 6:

    switch (*(char *)(iVar5 + 0x10)) {
    case 0:
      *(char *)(iVar5 + 0x11) = (char)*(u32 *)(iVar4 + 0x198);
      *(char *)(iVar5 + 0x12) = (char)*(u32 *)(iVar4 + 0x19c);
      *(char *)(iVar5 + 0x13) = (char)*(u32 *)(iVar4 + 0x1a0);
      break;
    }

    break;

  case 7:

    *(char *)(iVar5 + 0x11) = (char)*(u32 *)(iVar4 + 0x198);

    *(short *)(iVar5 + 0x12) = (short)*(u32 *)(iVar4 + 0x19c);

    break;

  case 0xc:

    switch (*piVar1) {
    case 1:
    case 0x30:
      switch (*(char *)(iVar5 + 0x10)) {
      case 6:
        uStack_4 = 0;
        puStack_8 = (float *)0x0;
        FUN_00386210(&uStack_4,(u32 *)&puStack_8);
        *(float *)(iVar5 + 0x18) = puStack_8[0];
        *(float *)(iVar5 + 0x1c) = puStack_8[1];
        *(u32 *)(iVar5 + 0x20) = 0;
        break;
      }
      break;
    }

    break;
  case 8:

    iVar3 = *piVar1;
    switch (iVar3) {
    case 0x25:
      puStack_c = (float *)0x0;
      puStack_10 = (float *)0x0;
      FUN_00386110((u32 *)&puStack_c,(u32 *)&puStack_10);
      *(float *)(iVar5 + 0x14) = puStack_c[0];
      *(float *)(iVar5 + 0x18) = puStack_c[1];
      *(float *)(iVar5 + 0x1c) = puStack_c[2];
      *(float *)(iVar5 + 0x20) = puStack_10[0];
      *(float *)(iVar5 + 0x24) = puStack_10[1];
      *(float *)(iVar5 + 0x28) = puStack_10[2];
      break;
    case 1:
    case 0x30:
      switch (*(char *)(iVar5 + 0x10)) {
      case 1:
        puStack_14 = (float *)0x0;
        puStack_18 = (float *)0x0;
        FUN_00386110((u32 *)&puStack_14,(u32 *)&puStack_18);
        switch (*(char *)(iVar5 + 0x14)) {
        case 0:
          *(float *)(iVar5 + 0x18) = puStack_14[0];
          *(float *)(iVar5 + 0x1c) = puStack_14[1];
          *(float *)(iVar5 + 0x20) = puStack_14[2];
          break;
        case 2:
          *(float *)(iVar5 + 0x18) = puStack_14[0];
          *(float *)(iVar5 + 0x1c) = puStack_14[1];
          *(float *)(iVar5 + 0x20) = puStack_14[2];
          *(float *)(iVar5 + 0x28) = puStack_18[0];
          *(float *)(iVar5 + 0x2c) = puStack_18[1];
          break;
        }
        break;
      }
      break;
    }

    break;

  case 9:

    *(u32 *)(iVar5 + 0x18) = *(u32 *)(iVar4 + 0x198);

    *(u32 *)(iVar5 + 0x1c) = *(u32 *)(iVar4 + 0x19c);

    *(u32 *)(iVar5 + 0x20) = *(u32 *)(iVar4 + 0x1a0);

    *(u32 *)(iVar5 + 0x24) = *(u32 *)(iVar4 + 0x1a4);

    *(u32 *)(iVar5 + 0x28) = *(u32 *)(iVar4 + 0x1a8);

    *(u32 *)(iVar5 + 0x2c) = *(u32 *)(iVar4 + 0x1ac);

    FUN_0038a620((int)param_3,2);

    break;

  case 10:

    switch (*piVar1) {
    case 0x21:
      iStack_1c = 0;
      FUN_00386390((u32 *)&iStack_1c,(u32 *)auStack_20,(u32 *)&piStack_24,(u32 *)&puStack_28);
      *(u16 *)(iVar5 + 0x14) = *(u16 *)(iStack_1c + *piStack_24 * 2);
      *(short *)(iVar5 + 0x16) = (short)*puStack_28;
      break;
    }

    break;

  case 0xb:

    *(char *)(iVar4 + 0x45) = (char)*(u32 *)(iVar4 + 0x198);

    break;


  case 0xd:

    *(short *)(iVar5 + 0x14) = (short)*(u32 *)(iVar4 + 0x198);

    *(short *)(iVar5 + 0x16) = (short)*(u32 *)(iVar4 + 0x19c);

    *(short *)(iVar5 + 0x18) = (short)*(u32 *)(iVar4 + 0x1a0);

    *(short *)(iVar5 + 0x1a) = (short)*(u32 *)(iVar4 + 0x1a4);

    break;

  case 0xe:

    switch (*piVar1) {
    case 1:
    case 0x30:
      *(short *)(iVar5 + 0x14) = (short)*(u32 *)(iVar4 + 0x198);
      *(char *)(iVar5 + 0x18) = (char)*(u32 *)(iVar4 + 0x19c);
      *(char *)(iVar5 + 0x19) = (char)*(u32 *)(iVar4 + 0x1a0);
      break;
    }

    break;

  case 0xf:

    switch (*piVar1) {
    case 0x25:
      *(char *)(iVar5 + 0x11) = (char)*(u32 *)(iVar4 + 0x198);
      *(short *)(iVar5 + 0x14) = (short)*(u32 *)(iVar4 + 0x19c);
      *(char *)(iVar5 + 0x12) = (char)*(u32 *)(iVar4 + 0x1a0);
      break;
    }

    break;

  case 0x10:

    *(short *)(iVar5 + 0x14) = (short)*(u32 *)(iVar4 + 0x198);

    *(u32 *)(iVar5 + 0x18) = *(u32 *)(iVar4 + 0x19c);

    break;

  case 0x11:

    *(short *)(iVar4 + 0x4a) = (short)*(u32 *)(iVar4 + 0x198);

  }

  FUN_0036f640((int)param_3);

  return 0;

}


#pragma opt_common_subs reset
// FUN_00367A20


u64 FUN_00367a20(u64 param_1,u64 param_2,int param_3)



{

  char cVar1;

  int iVar2;

  u32 uVar3;

  u8 *lVar4;

  int iVar5;

  int iVar6;

  int iVar7;
  int limit;

  RwV4d source1;
  RwV4d target1;
  RwV4d source2;
  RwV4d target2;

  

  iVar6 = (int)param_3;

  iVar2 = *(int *)(iVar6 + 0x164);

  if (iVar2 == 0) {

    iVar7 = 0;

  }

  else {

    iVar7 = *(int *)(iVar2 + 0x6c);
    iVar5 = 0;
    limit = *(int *)(iVar6 + 0x160) + *(int *)(iVar6 + 0x15c);
    while ((iVar5 < limit) && (iVar7 != 0)) {
      iVar7 = *(int *)(iVar7 + 0x4c);
      iVar5 = iVar5 + 1;
    }

  }

  *(char *)(iVar7 + 0x14) = (char)*(u32 *)(iVar6 + 0x198);

  *(char *)(iVar7 + 0x15) = (char)*(u32 *)(iVar6 + 0x19c);

  *(short *)(iVar7 + 0x16) = (short)*(u32 *)(iVar6 + 0x1a0);

  *(char *)(iVar7 + 0x24) = (char)*(u32 *)(iVar6 + 0x1a4);

  *(char *)(iVar7 + 0x25) = (char)*(u32 *)(iVar6 + 0x1a8);

  *(char *)(iVar7 + 0x26) = (char)*(u32 *)(iVar6 + 0x1ac);

  if ((*(char *)(iVar7 + 0x14) == '\x01') && (*(int *)(iVar7 + 0x40) == 0)) {

    FUN_0038d790(iVar7);

  }

  if ((*(int *)(iVar6 + 400) == 6) && (*(int *)(iVar6 + 0x198) != 2)) {

    *(u32 *)(param_3 + 400) = 0;

    *(int *)(iVar6 + 0x1b8) = (int)*(char *)(iVar7 + 0x34);

    *(int *)(iVar6 + 0x1bc) = (int)*(char *)(iVar7 + 0x35);

    *(int *)(iVar6 + 0x1c0) = (int)*(char *)(iVar7 + 0x36);

    *(int *)(iVar6 + 0x1c4) = (int)*(char *)(iVar7 + 0x37);

    FUN_0036f5f0(0x2e,0xc,0x18,param_3);

  }

  else if (*(int *)(iVar6 + 400) == 7) {

    cVar1 = *(char *)(iVar7 + 0x14);

    if (cVar1 == '\0') {

      source1.x = *(f32 *)(iVar7 + 0x18);
      source1.y = *(f32 *)(iVar7 + 0x1c);
      source1.z = *(f32 *)(iVar7 + 0x20);
      target1.x = 0.0f;
      target1.y = 0.0f;
      target1.z = 0.0f;
      uVar3 = FUN_00386130(param_3,(u32 *)&source1,(u32 *)&target1);

      *(u32 *)(iVar6 + 0xe8) = uVar3;

      FUN_0036f5f0(0x1a,0,0,param_3);

    }

    else if (cVar1 == '\x01') {

      lVar4 = FUN_003b5d10_evt_main(*(u16 *)(iVar2 + 0xc));

      if (lVar4 != 0) {

        FUN_0037cf50((u32 *)(*(u32 *)(iVar7 + 0x40)),(u32 *)(lVar4 + 4),(u32 *)(lVar4 + 0x10));

        FUN_0036f5f0(0x1c,0xc,0x1c,param_3);

      }

    }

    else if (cVar1 == '\x02') {

      source2.x = *(f32 *)(iVar7 + 0x18);
      source2.y = *(f32 *)(iVar7 + 0x1c);
      source2.z = *(f32 *)(iVar7 + 0x20);
      target2.x = *(f32 *)(iVar7 + 0x28);
      target2.y = *(f32 *)(iVar7 + 0x2c);
      target2.z = 0.0f;
      uVar3 = FUN_00386130(param_3,(u32 *)&source2,(u32 *)&target2);

      *(u32 *)(iVar6 + 0xe8) = uVar3;

      FUN_0036f5f0(0x1a,0,0,param_3);

    }

  }

  else {

    FUN_0036f640(param_3);

  }

  return 0;

}


// FUN_00367CB0


u64 FUN_00367cb0(u64 param_1,u64 param_2,int param_3)



{

  u32 uVar1;

  u32 uVar2;

  int iVar5;

  int iVar3;

  u32 *puVar7;

  u32 *puVar6;

  int iVar4;

  

  iVar4 = (int)param_3;

  if (*(int *)(iVar4 + 0x164) == 0) {

    iVar5 = 0;

  }

  else {

    iVar5 = *(int *)(*(int *)(iVar4 + 0x164) + 0x6c);
    iVar3 = 0;
    iVar4 = *(int *)(iVar4 + 0x160) + *(int *)(iVar4 + 0x15c);
    for (; (iVar3 < iVar4 && (iVar5 != 0));) {

      iVar5 = *(int *)(iVar5 + 0x4c);
      iVar3 = iVar3 + 1;

    }

  }

  puVar7 = *(u32 **)(iVar5 + 0x40);

  if (puVar7 != (u32 *)0x0) {

    puVar6 = (u32 *)DAT_00958700_abs;

    iVar4 = 0x26;

    do {

      uVar1 = *puVar6;

      uVar2 = puVar6[1];

      puVar6 = puVar6 + 2;

      iVar4 = iVar4 + -1;

      *puVar7 = uVar1;

      puVar7[1] = uVar2;

      puVar7 = puVar7 + 2;

    } while (0 < iVar4);

  }

  FUN_0036f640(param_3);

  return 0;

}


// FUN_00367D70


u64 FUN_00367d70(u64 param_1,u64 param_2,int param_3)



{

  int iVar2;

  int iVar1;

  int iVar3;

  int iVar4;

  

  iVar3 = (int)param_3;

  if (*(int *)(iVar3 + 0x164) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);

    iVar1 = 0;

    iVar4 = *(int *)(iVar3 + 0x160) + *(int *)(iVar3 + 0x15c);

    for (; (iVar1 < iVar4 && (iVar2 != 0));) {

      iVar2 = *(int *)(iVar2 + 0x4c);

      iVar1 = iVar1 + 1;

    }

  }

  *(char *)(iVar2 + 0x15) = (char)*(u32 *)(iVar3 + 0x198);

  *(char *)(iVar2 + 0x14) = (char)*(u32 *)(iVar3 + 0x19c);

  FUN_0036f640(param_3);

  return 0;

}


// FUN_00367E00


u64 FUN_00367e00(u64 param_1,u64 param_2,int param_3)



{

  int iVar2;

  int iVar1;

  int iVar3;

  int iVar4;

  

  iVar3 = (int)param_3;

  if (*(int *)(iVar3 + 0x164) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);

    iVar1 = 0;

    iVar4 = *(int *)(iVar3 + 0x160) + *(int *)(iVar3 + 0x15c);

    for (; (iVar1 < iVar4 && (iVar2 != 0));) {

      iVar2 = *(int *)(iVar2 + 0x4c);

      iVar1 = iVar1 + 1;

    }

  }

  *(short *)(iVar2 + 0x1c) = (short)*(u32 *)(iVar3 + 0x198);

  *(short *)(iVar2 + 0x1e) = (short)*(u32 *)(iVar3 + 0x19c);

  *(char *)(iVar2 + 0x20) = (char)*(u32 *)(iVar3 + 0x1a0);

  *(short *)(iVar2 + 0x14) = (short)*(u32 *)(iVar3 + 0x1a4);

  *(short *)(iVar2 + 0x16) = (short)*(u32 *)(iVar3 + 0x1a8);

  *(short *)(iVar2 + 0x18) = (short)*(u32 *)(iVar3 + 0x1ac);

  *(short *)(iVar2 + 0x1a) = (short)*(u32 *)(iVar3 + 0x1b0);

  *(char *)(iVar2 + 0x22) = (char)*(u32 *)(iVar3 + 0x1b4);

  FUN_0036f640(param_3);

  return 0;

}


// FUN_00367EC0


u64 FUN_00367ec0(u64 param_1,u64 param_2,int param_3)



{

  int iVar1;

  u32 uVar2;

  u32 lVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int limit;

  f32 source[3];

  f32 target[3];

  

  iVar5 = (int)param_3;

  iVar1 = *(int *)(iVar5 + 0x164);

  if (iVar1 == 0) {

    iVar6 = 0;

  }

  else {

    iVar6 = *(int *)(iVar1 + 0x6c);
    iVar4 = 0;
    limit = *(int *)(iVar5 + 0x160) + *(int *)(iVar5 + 0x15c);
    while ((iVar4 < limit) && (iVar6 != 0)) {
      iVar6 = *(int *)(iVar6 + 0x4c);
      iVar4 = iVar4 + 1;
    }

  }

  *(char *)(iVar6 + 0x14) = (char)*(u32 *)(iVar5 + 0x198);

  *(char *)(iVar6 + 0x15) = (char)*(u32 *)(iVar5 + 0x19c);

  if (*(int *)(iVar5 + 0x198) != 0) {

    *(u32 *)(iVar6 + 0x18) = 0;

    *(u32 *)(iVar6 + 0x1c) = 0;

    *(u32 *)(iVar6 + 0x20) = 0;

  }

  if ((*(int *)(iVar5 + 400) == 2) && (*(int *)(iVar5 + 0x198) == 0)) {

    if (((iVar1 != 0) && (lVar3 = FUN_003b5d10(*(u16 *)(iVar1 + 0xc)), lVar3 != 0)) &&

       (*(char *)(iVar6 + 0x14) == '\0')) {

      iVar1 = (int)lVar3;

      source[0] = *(f32 *)(iVar1 + 4);

      source[1] = *(f32 *)(iVar1 + 8);

      source[2] = *(f32 *)(iVar1 + 0xc);

      target[0] = *(f32 *)(iVar6 + 0x18);

      target[1] = *(f32 *)(iVar6 + 0x1c);

      target[2] = 0.0f;

      uVar2 = FUN_00386230(param_3,(u32 *)source,(u32 *)target);

      *(u32 *)(iVar5 + 0xe8) = uVar2;

      FUN_0036f5f0(0x1a,0,0,param_3);

    }

  }

  else {

    FUN_0036f640(param_3);

  }

  return 0;

}


// FUN_00368020


u64 FUN_00368020(u64 param_1,u64 param_2,int param_3)



{

  int iVar2;

  int iVar1;

  int iVar3;

  int iVar4;

  

  iVar3 = (int)param_3;

  if (*(int *)(iVar3 + 0x164) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);

    iVar1 = 0;

    iVar4 = *(int *)(iVar3 + 0x160) + *(int *)(iVar3 + 0x15c);

    for (; (iVar1 < iVar4 && (iVar2 != 0));) {

      iVar2 = *(int *)(iVar2 + 0x4c);

      iVar1 = iVar1 + 1;

    }

  }

  *(char *)(iVar2 + 0x10) = (char)*(u32 *)(iVar3 + 0x198);

  *(char *)(iVar2 + 0x11) = (char)*(u32 *)(iVar3 + 0x19c);

  *(char *)(iVar2 + 0x12) = (char)*(u32 *)(iVar3 + 0x1a0);

  *(char *)(iVar2 + 0x13) = (char)*(u32 *)(iVar3 + 0x1a4);

  *(short *)(iVar2 + 0x18) = (short)*(u32 *)(iVar3 + 0x1a8);

  *(short *)(iVar2 + 0x1a) = (short)*(u32 *)(iVar3 + 0x1ac);

  *(short *)(iVar2 + 0x1c) = (short)*(u32 *)(iVar3 + 0x1b0);

  *(short *)(iVar2 + 0x1e) = (short)*(u32 *)(iVar3 + 0x1b4);

  FUN_0036f640(param_3);

  return 0;

}


// FUN_003680E0 NONMATCHING


u64 FUN_003680e0(u64 param_1,u64 param_2,int param_3)



{

  char cVar1;

  int *piVar2;

  u8 *puVar3;

  u8 *puVar4;

  u8 *puVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int limit;

  u8 auStack_20 [16];

  u8 auStack_10 [16];

  

  iVar7 = (int)param_3;

  piVar2 = *(int **)(iVar7 + 0x164);

  if (piVar2 == (int *)0x0) {

    iVar8 = 0;

  }

  else {

    iVar8 = piVar2[0x1b];
    iVar6 = 0;
    limit = *(int *)(iVar7 + 0x160) + *(int *)(iVar7 + 0x15c);
    while ((iVar6 < limit) && (iVar8 != 0)) {
      iVar8 = *(int *)(iVar8 + 0x4c);
      iVar6 = iVar6 + 1;
    }

  }

  iVar6 = *(int *)(iVar7 + 400);

  if (iVar6 == 0) {

    puVar4 = (u8 *)0xc;

    puVar5 = auStack_10;

    puVar3 = puVar5;

    while (puVar3 != (u8 *)0x0) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

      puVar4 = puVar4 + -1;

      puVar3 = puVar4;

    }

    puVar4 = (u8 *)0xc;

    puVar5 = auStack_20;

    puVar3 = puVar5;

    while (puVar3 != (u8 *)0x0) {

      *puVar5 = 0;

      puVar5 = puVar5 + 1;

      puVar4 = puVar4 + -1;

      puVar3 = puVar4;

    }

    if ((*piVar2 == 0x29) &&

       ((*(char *)(iVar8 + 0x10) == '\x05' || (*(char *)(iVar8 + 0x10) == '\0')))) {

      if (*(int *)(iVar8 + 0x40) == 0) {

        FUN_0038d790(iVar8);

      }

      FUN_0037cf50((u32 *)(*(u32 *)(iVar8 + 0x40)),(u32 *)auStack_10,(u32 *)auStack_20);

      FUN_0036f5f0(0x1c,0xc,0x1c,param_3);

    }

  }

  else if (iVar6 == 1) {

    if ((*piVar2 == 0x29) &&

       ((((cVar1 = *(char *)(iVar8 + 0x10), cVar1 == '\x03' || (cVar1 == '\x04')) ||

         (cVar1 == '\x05')) || (cVar1 == '\0')))) {

      *(u32 *)(iVar7 + 0x108) = 0;

      *(u32 *)(iVar7 + 0x110) = 0;

      *(u32 *)(iVar7 + 0x660) = 3;

      FUN_0036f5f0(10,0x26,0xd,param_3);

    }

  }

  else if (iVar6 == 2) {

    FUN_0036f640(param_3);

  }

  return 0;

}


// FUN_003682F0


u64 FUN_003682f0(u64 param_1,u64 param_2,int param_3)



{

  int iVar2;

  int iVar1;

  int iVar3;

  int iVar4;

  

  iVar3 = (int)param_3;

  if (*(int *)(iVar3 + 0x164) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);

    iVar1 = 0;

    iVar4 = *(int *)(iVar3 + 0x160) + *(int *)(iVar3 + 0x15c);

    for (; (iVar1 < iVar4 && (iVar2 != 0));) {

      iVar2 = *(int *)(iVar2 + 0x4c);

      iVar1 = iVar1 + 1;

    }

  }

  *(short *)(iVar2 + 0x10) = (short)*(u32 *)(iVar3 + 0x198);

  *(short *)(iVar2 + 0x12) = (short)*(u32 *)(iVar3 + 0x19c);

  *(short *)(iVar2 + 0x14) = (short)*(u32 *)(iVar3 + 0x1a0);

  *(short *)(iVar2 + 0x16) = (short)*(u32 *)(iVar3 + 0x1a4);

  *(short *)(iVar2 + 0x18) = (short)*(u32 *)(iVar3 + 0x1a8);

  *(short *)(iVar2 + 0x1a) = (short)*(u32 *)(iVar3 + 0x1ac);

  FUN_0036f640(param_3);

  return 0;

}


// FUN_003683A0


u64 FUN_003683a0(u64 param_1,u64 param_2,int param_3)



{

  int iVar2;

  int iVar1;

  int iVar3;

  int iVar4;

  

  iVar3 = (int)param_3;

  if (*(int *)(iVar3 + 0x164) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);

    iVar1 = 0;

    iVar4 = *(int *)(iVar3 + 0x160) + *(int *)(iVar3 + 0x15c);

    for (; (iVar1 < iVar4 && (iVar2 != 0));) {

      iVar2 = *(int *)(iVar2 + 0x4c);

      iVar1 = iVar1 + 1;

    }

  }

  *(char *)(iVar2 + 0x14) = (char)*(u32 *)(iVar3 + 0x198);

  *(char *)(iVar2 + 0x15) = (char)*(u32 *)(iVar3 + 0x19c);

  *(char *)(iVar2 + 0x16) = (char)*(u32 *)(iVar3 + 0x1a0);

  *(u32 *)(iVar2 + 0x18) = *(u32 *)(iVar3 + 0x1a4);

  FUN_0036f640(param_3);

  return 0;

}


// FUN_00368440


u64 FUN_00368440(u64 param_1,u64 param_2,int param_3)



{

  int iVar2;

  int iVar1;

  int iVar3;

  int iVar4;

  

  iVar3 = (int)param_3;

  if (*(int *)(iVar3 + 0x164) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);

    iVar1 = 0;

    iVar4 = *(int *)(iVar3 + 0x160) + *(int *)(iVar3 + 0x15c);

    for (; (iVar1 < iVar4 && (iVar2 != 0));) {

      iVar2 = *(int *)(iVar2 + 0x4c);

      iVar1 = iVar1 + 1;

    }

  }

  *(short *)(iVar2 + 0x10) = (short)*(u32 *)(iVar3 + 0x198);

  *(short *)(iVar2 + 0x12) = (short)*(u32 *)(iVar3 + 0x19c);

  FUN_0036f640(param_3);

  return 0;

}


// FUN_003684D0


u64 FUN_003684d0(u64 param_1,u64 param_2,int param_3,int param_4)
{
  int iVar2;
  int iVar1;
  int iVar3;
  int iVar4;
  int context;

  iVar3 = param_3;
  context = iVar3;
  if (*(int *)(iVar3 + 0x164) == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);
    iVar1 = 0;
    iVar4 = *(int *)(context + 0x160) + *(int *)(context + 0x15c);
    for (;
        (iVar1 < iVar4 && (iVar2 != 0));
        iVar2 = *(int *)(iVar2 + 0x4c), iVar1 = iVar1 + 1) {
    }
  }
  if (*(int *)(context + 400) == 6) {
    *(u32 *)(context + 0x108) = 0;
    *(u32 *)(context + 0x110) = 0;
    *(u32 *)(context + 0x660) = 3;
    FUN_0036f5f0(10,0x26,0xd,param_3);
  }
  else {
    *(char *)(iVar2 + 0x14) = (char)*(u32 *)(context + 0x198);
    *(char *)(iVar2 + 0x15) = (char)*(u32 *)(context + 0x19c);
    *(char *)(iVar2 + 0x18) = (char)*(u32 *)(context + 0x1a0);
    *(char *)(iVar2 + 0x19) = (char)*(u32 *)(context + 0x1a4);
    *(char *)(iVar2 + 0x1a) = (char)*(u32 *)(context + 0x1a8);
    *(char *)(iVar2 + 0x1b) = (char)*(u32 *)(context + 0x1ac);
    FUN_0036f640(param_3);
  }
  return 0;
}


// FUN_003685C0


u64 FUN_003685c0(u64 param_1,u64 param_2,int param_3)



{

  int iVar2;

  int iVar1;

  int iVar3;

  int iVar4;

  

  iVar3 = (int)param_3;

  if (*(int *)(iVar3 + 0x164) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);

    iVar1 = 0;

    iVar4 = *(int *)(iVar3 + 0x160) + *(int *)(iVar3 + 0x15c);

    for (; (iVar1 < iVar4 && (iVar2 != 0));) {

      iVar2 = *(int *)(iVar2 + 0x4c);

      iVar1 = iVar1 + 1;

    }

  }

  *(char *)(iVar2 + 0x10) = (char)*(u32 *)(iVar3 + 0x198);

  *(char *)(iVar2 + 0x14) = (char)*(u32 *)(iVar3 + 0x19c);

  *(char *)(iVar2 + 0x15) = (char)*(u32 *)(iVar3 + 0x1a0);

  *(char *)(iVar2 + 0x16) = (char)*(u32 *)(iVar3 + 0x1a4);

  *(short *)(iVar2 + 0x18) = (short)*(u32 *)(iVar3 + 0x1a8);

  *(short *)(iVar2 + 0x1a) = (short)*(u32 *)(iVar3 + 0x1ac);

  *(short *)(iVar2 + 0x1c) = (short)*(u32 *)(iVar3 + 0x1b0);

  *(short *)(iVar2 + 0x1e) = (short)*(u32 *)(iVar3 + 0x1b4);

  FUN_0036f640(param_3);

  return 0;

}


// FUN_00368680


u64 FUN_00368680(u64 param_1,u64 param_2,int param_3)



{

  int iVar2;

  int iVar1;

  int iVar3;

  int iVar4;

  

  iVar3 = (int)param_3;

  if (*(int *)(iVar3 + 0x164) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);

    iVar1 = 0;

    iVar4 = *(int *)(iVar3 + 0x160) + *(int *)(iVar3 + 0x15c);

    for (; (iVar1 < iVar4 && (iVar2 != 0));) {

      iVar2 = *(int *)(iVar2 + 0x4c);

      iVar1 = iVar1 + 1;

    }

  }

  *(short *)(iVar2 + 0x10) = (short)*(u32 *)(iVar3 + 0x198);

  *(short *)(iVar2 + 0x12) = (short)*(u32 *)(iVar3 + 0x19c);

  FUN_0036f640(param_3);

  return 0;

}


// FUN_00368710


u32 FUN_00368710(int param_1,int param_2,int param_3)



{

  int *piVar1;

  int iVar4;

  int iVar3;

  int iVar2;
  int iVar5;

  

  iVar3 = (int)param_3;

  piVar1 = *(int **)(iVar3 + 0x164);

  if (piVar1 == (int *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar4 = piVar1[0x1b];

    iVar2 = 0;
    iVar5 = *(int *)(iVar3 + 0x160) + *(int *)(iVar3 + 0x15c);

    for (;

        (iVar2 < iVar5 && (iVar4 != 0));) {

      iVar4 = *(int *)(iVar4 + 0x4c);

      iVar2 = iVar2 + 1;

    }

  }

  switch (*piVar1) {

  case 0x21:
    *(char *)(iVar4 + 0x30) = (char)*(u32 *)(iVar3 + 0x198);

    break;

  default:
    break;

  }

  FUN_0036f640(param_3);

  return 0;

}


// FUN_003687B0


u64 FUN_003687b0(u64 param_1,u64 param_2,int param_3)



{

  int iVar2;

  int iVar1;

  int iVar3;

  int iVar4;

  

  iVar3 = (int)param_3;

  if (*(int *)(iVar3 + 0x164) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);

    iVar1 = 0;

    iVar4 = *(int *)(iVar3 + 0x160) + *(int *)(iVar3 + 0x15c);

    for (; (iVar1 < iVar4 && (iVar2 != 0));) {

      iVar2 = *(int *)(iVar2 + 0x4c);

      iVar1 = iVar1 + 1;

    }

  }

  *(short *)(iVar2 + 0x14) = (short)*(u32 *)(iVar3 + 0x198);

  FUN_0036f640(param_3);

  return 0;

}


// FUN_00368830


u64 FUN_00368830(u64 param_1,u64 param_2,int param_3)



{

  int iVar2;

  int iVar1;

  int iVar3;

  int iVar4;

  

  iVar3 = (int)param_3;

  if (*(int *)(iVar3 + 0x164) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);

    iVar1 = 0;

    iVar4 = *(int *)(iVar3 + 0x160) + *(int *)(iVar3 + 0x15c);

    for (; (iVar1 < iVar4 && (iVar2 != 0));) {

      iVar2 = *(int *)(iVar2 + 0x4c);

      iVar1 = iVar1 + 1;

    }

  }

  *(char *)(iVar2 + 0x14) = (char)*(u32 *)(iVar3 + 0x198);

  *(char *)(iVar2 + 0x15) = (char)*(u32 *)(iVar3 + 0x19c);

  *(short *)(iVar2 + 0x16) = (short)*(u32 *)(iVar3 + 0x1a0);

  *(short *)(iVar2 + 0x18) = (short)*(u32 *)(iVar3 + 0x1a4);

  *(short *)(iVar2 + 0x1a) = (short)*(u32 *)(iVar3 + 0x1a8);

  FUN_0036f640(param_3);

  return 0;

}


// FUN_003688D0


u64 FUN_003688d0(u64 param_1,u64 param_2,int param_3,int param_4)



{

  int iVar2;

  int iVar1;

  int iVar3;
  int iVar4;

  int context;

  

  iVar3 = (int)param_3;
  context = iVar3;


  if (*(int *)(iVar3 + 0x164) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);

    iVar1 = 0;
    iVar4 = *(int *)(context + 0x160) + *(int *)(context + 0x15c);

    for (;
        (iVar1 < iVar4 && (iVar2 != 0));
        iVar2 = *(int *)(iVar2 + 0x4c), iVar1 = iVar1 + 1) {
    }

  }

  if (*(int *)(context + 400) == 4) {

    *(u32 *)(context + 0x108) = 0;

    *(u32 *)(context + 0x110) = 0;

    *(u32 *)(context + 0x660) = 3;

    FUN_0036f5f0(10,0x26,0xd,context);

  }

  else {

    *(short *)(iVar2 + 0x14) = (short)*(u32 *)(context + 0x198);

    *(short *)(iVar2 + 0x16) = (short)*(u32 *)(context + 0x19c);

    *(short *)(iVar2 + 0x18) = (short)*(u32 *)(context + 0x1a0);

    *(short *)(iVar2 + 0x1a) = (short)*(u32 *)(context + 0x1a4);

    *(short *)(iVar2 + 0x1e) = (short)*(u32 *)(context + 0x1ac);

    *(short *)(iVar2 + 0x20) = (short)*(u32 *)(context + 0x1b0);

    *(char *)(iVar2 + 0x24) = (char)*(short *)(context + 0x1b4);

    FUN_0036f640(context);

  }

  return 0;

}


// FUN_003689C0


u32 FUN_003689c0(int param_1,int param_2,int param_3)



{

  int iVar1;

  int iVar2;

  int iVar3;
  int iVar4;

  

  iVar3 = (int)param_3;

  if (*(int *)(iVar3 + 0x164) != 0) {

    iVar1 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);
    iVar2 = 0;
    iVar4 = *(int *)(iVar3 + 0x160) + *(int *)(iVar3 + 0x15c);
    for (; (iVar2 < iVar4 && (iVar1 != 0));) {

      iVar1 = *(int *)(iVar1 + 0x4c);
      iVar2 = iVar2 + 1;

    }

  }

  FUN_0036f640(param_3);

  return 0;

}


// FUN_00368A30


u64 FUN_00368a30(u64 param_1,u64 param_2,int param_3,int param_4)



{

  int iVar2;

  int iVar1;

  int iVar3;

  int iVar4;
  int context;


  

  iVar3 = (int)param_3;

  context = iVar3;

  if (*(int *)(iVar3 + 0x164) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);

    iVar1 = 0;
    iVar4 = *(int *)(context + 0x160) + *(int *)(context + 0x15c);

    for (;
        (iVar1 < iVar4 && (iVar2 != 0));

        iVar2 = *(int *)(iVar2 + 0x4c), iVar1 = iVar1 + 1) {
    }

  }

  if (*(int *)(context + 400) == 1) {

    *(u32 *)(context + 0x108) = 0;

    *(u32 *)(context + 0x110) = 0;

    *(u32 *)(context + 0x660) = 3;

    FUN_0036f5f0(10,0xd,7,context);

  }

  else {

    *(char *)(iVar2 + 0x14) = (char)*(u32 *)(context + 0x198);

    *(char *)(iVar2 + 0x18) = (char)*(u32 *)(context + 0x1a0);

    FUN_0036f640(context);

  }

  return 0;

}


// FUN_00368B00


u64 FUN_00368b00(u64 param_1,int param_2,int param_3)



{

  int *piVar1;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar1;

  int iVar6;

  

  iVar3 = (int)param_3;

  piVar1 = *(int **)(iVar3 + 0x164);

  if (piVar1 == (int *)0x0) {

    iVar4 = 0;

  }

  else {
    iVar4 = piVar1[0x1b];
    {
      int iVar6 = 0;

      iVar1 = *(int *)(iVar3 + 0x160) + *(int *)(iVar3 + 0x15c);
      for (; (iVar6 < iVar1 && (iVar4 != 0));
          iVar4 = *(int *)(iVar4 + 0x4c), iVar6 = iVar6 + 1) {
      }
    }


  }

  switch (*piVar1) {
  case 1:
  case 0x30:
    switch (*(char *)(iVar4 + 0x10)) {
    case 1:
      *(char *)(iVar4 + 0x34) = (char)*(u32 *)(iVar3 + 0x1b8);
      *(char *)(iVar4 + 0x35) = (char)*(u32 *)(iVar3 + 0x1bc);
      *(char *)(iVar4 + 0x36) = (char)*(u32 *)(iVar3 + 0x1c0);
      *(char *)(iVar4 + 0x37) = (char)*(u32 *)(iVar3 + 0x1c4);
      break;
    case 4:
      *(char *)(iVar4 + 0x28) = (char)*(u32 *)(iVar3 + 0x1b8);
      *(char *)(iVar4 + 0x29) = (char)*(u32 *)(iVar3 + 0x1bc);
      *(char *)(iVar4 + 0x2a) = (char)*(u32 *)(iVar3 + 0x1c0);
      *(char *)(iVar4 + 0x2b) = (char)*(u32 *)(iVar3 + 0x1c4);
      break;
    }
    break;
  }

  FUN_0036f640(param_3);

  return 0;

}


// FUN_00368C10


u64 FUN_00368c10(u64 param_1,u64 param_2,int param_3)



{

  int iVar2;

  int iVar1;

  int iVar3;

  int iVar4;

  

  iVar3 = (int)param_3;

  if (*(int *)(iVar3 + 0x164) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(*(int *)(iVar3 + 0x164) + 0x6c);

    iVar1 = 0;

    iVar4 = *(int *)(iVar3 + 0x160) + *(int *)(iVar3 + 0x15c);

    for (; (iVar1 < iVar4 && (iVar2 != 0));) {

      iVar2 = *(int *)(iVar2 + 0x4c);

      iVar1 = iVar1 + 1;

    }

  }

  *(char *)(iVar2 + 0x10) = (char)*(u32 *)(iVar3 + 0x198);

  *(char *)(iVar2 + 0x11) = (char)*(u32 *)(iVar3 + 0x19c);

  *(char *)(iVar2 + 0x12) = (char)*(u32 *)(iVar3 + 0x1a0);

  *(char *)(iVar2 + 0x13) = (char)*(u32 *)(iVar3 + 0x1a4);

  FUN_0036f640(param_3);

  return 0;

}


// FUN_00368CB0


u64 FUN_00368cb0(u64 param_1,u64 param_2,int param_3)



{

  int iVar5;

  int iVar3;

  int iVar1;

  int iVar2;

  int iVar4;

  

  iVar2 = (int)param_3;

  iVar5 = *(int *)(iVar2 + 0x16c);

  if (*(int *)(iVar2 + 0x164) == 0) {

    iVar3 = 0;

  }

  else {

    iVar3 = *(int *)(*(int *)(iVar2 + 0x164) + 0x6c);

    iVar1 = 0;

    iVar4 = *(int *)(iVar2 + 0x160) + *(int *)(iVar2 + 0x15c);

    for (; (iVar1 < iVar4 && (iVar3 != 0));) {

      iVar3 = *(int *)(iVar3 + 0x4c);

      iVar1 = iVar1 + 1;

    }

  }

  if (iVar3 == 0) {

    return 0;

  }

  *(short *)(iVar3 + 0x10) = (short)iVar5;

  *(char *)(iVar3 + 0x15) = (char)*(u32 *)(iVar2 + 0x198);

  *(char *)(iVar3 + 0x16) = (char)*(u32 *)(iVar2 + 0x19c);

  if ((*(short *)(iVar3 + 0x10) >> 0xc & 0xfU) != 0) {

    *(u16 *)(iVar3 + 0x12) = 0;

  }

  FUN_0036f640(param_3);

  return 0;

}


// FUN_00368D70


u32 FUN_00368d70(u64 param_1,u64 param_2,int param_3)



{

  int iVar1;
  int iVar6;
  int bVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;

  

  iVar6 = (int)param_3;
  bVar2 = false;
  iVar1 = *(int *)(iVar6 + 0x104);

  switch (iVar1) {
  case 0:
  case 1:
  case 2:

    FUN_00386e20(param_3,uGpffff9d78);

    FUN_00386e40(param_3,uGpffff9d7c);

    uVar4 = FUN_00386e10(param_3);

    uVar5 = FUN_00386e30(param_3);

    FUN_00523ac8(iVar6 + 0x144,(int)DAT_0069d7a0,uVar4,uVar5);

    iVar1 = *(int *)(iVar6 + 0x104);

    if (iVar1 == 0) {

      FUN_0038e860_i(1,param_3);

    }

    else if (iVar1 == 1) {

      uVar4 = FUN_00386e10(param_3);

      uVar5 = FUN_00386e30(param_3);

      FUN_00393e30_evt_main((u32)param_3,uVar4,uVar5,0,0,FUN_0036e690);

    }

    else if (iVar1 == 2) {

      uVar4 = FUN_00386e10(param_3);

      uVar5 = FUN_00386e30(param_3);

      FUN_00393e30_evt_main((u32)param_3,uVar4,uVar5,0,1,FUN_0036e690);

    }

    bVar2 = true;

    break;
  default:

    FUN_0019d3f0((int)DAT_0069d580,0x1efb);
  }


  if (bVar2) {
    uVar3 = 0xffffffff;
  }
  else {
    uVar3 = 0;
  }

  return uVar3;

}


/* W367 pragma probe: opt_loop_invariants on nd 296 -> 275; off nd 296; object 996/1024. */
#pragma opt_loop_invariants on
// FUN_00368F20 NONMATCHING


u64 FUN_00368f20(u64 param_1,int param_2,u8 *param_3)



{

  char cVar1;

  u16 *puVar2;

  int iVar8;

  u32 characterKind;

  int lVar3;

  int iVar6;

  u16 selectedId;

  u8 *iVar5;

  int listIndex;
  int eventKind;
  int opcodeOffset;

  union EvtPackedValue {
    u32 value;
    struct {
      u16 low;
      u16 high;
    } half;
  } packedNoEntry, packedEntry;

  

  iVar5 = param_3;

  if (*(int *)(iVar5 + 0x164) == 0) {

    iVar6 = 0;

  }

  else {

    listIndex = 0;

    for (iVar6 = *(int *)(*(int *)(iVar5 + 0x164) + 0x6c);

        (listIndex < *(int *)(iVar5 + 0x160) + *(int *)(iVar5 + 0x15c) && (iVar6 != 0));

        iVar6 = *(int *)(iVar6 + 0x4c)) {

      listIndex = listIndex + 1;

    }

  }

  if (iVar6 == 0) {
    return 0;
  }
  lVar3 = FUN_003b5d00();
  if (lVar3 == 0) {
    return 0;
  }
  {

    if (*(int *)(iVar5 + 0x108) + *(int *)(iVar5 + 0x110) == 0) {

      puVar2 = (u16 *)0x0;

    }

    else {

      puVar2 = (u16 *)0x0;

      iVar8 = 0;

      for (characterKind = 0; (int)characterKind < 0x16; characterKind = characterKind + 1) {

        if (*(u32 *)(iVar5 + 0x660) == characterKind) {

          for (puVar2 = (u16 *)FUN_003b5430(lVar3,characterKind & 0xff); puVar2 != (u16 *)0x0;

              puVar2 = *(u16 **)(puVar2 + 0x7c)) {

            iVar8 = iVar8 + 1;

            if (iVar8 == *(int *)(iVar5 + 0x108) + *(int *)(iVar5 + 0x110)) {

              characterKind = 0x16;

              break;

            }

          }

        }

      }

    }

    if (puVar2 == (u16 *)0x0) {

      selectedId = 0;

    }

    else {

      selectedId = (u32)*puVar2;

    }


    if (param_2 == 0x17) {

      if (puVar2 == (u16 *)0x0) {

        packedNoEntry.value = *(u32 *)(iVar5 + 0x16c);
        packedNoEntry.half.high = selectedId;
        *(u32 *)(iVar5 + 0x16c) = packedNoEntry.value;

      }

      else {

        packedEntry.value = *(u32 *)(iVar5 + 0x16c);
        packedEntry.half.high = selectedId;
        *(u32 *)(iVar5 + 0x16c) = packedEntry.value;

      }

    }

    else {

      eventKind = **(int **)(iVar5 + 0x164);

      opcodeOffset = eventKind * 0xc;
      cVar1 = DAT_0069e1a2_byte[opcodeOffset + *(int *)(iVar5 + 0x158)];

      switch (cVar1) {
      case '\r':
        switch (eventKind) {
        case 0x14:
        case 0x15:
          *(s8 *)(*(int *)(iVar5 + 0x114) + iVar6 + 0x14) = -1;
          break;
        }
        break;
      case '\x1d':
        switch (eventKind) {
        case 0x2f:
        case 0x31:
          *(short *)(iVar6 + 0x12) = selectedId;
          break;
        }
        break;
      case '\x1c':
        switch (eventKind) {
        case 0x29:
          switch (*(char *)(iVar6 + 0x10)) {
          case 0:
          case 3:
          case 4:
          case 5:
            *(short *)(iVar6 + 0x14) = selectedId;
            *(int *)(iVar5 + 0x198) = (s16)selectedId;
            break;
          case 2:
            *(short *)(iVar6 + 0x1c) = selectedId;
            *(u32 *)(iVar5 + 0x1b0) = selectedId;
            break;
          case 7:
            if (*(int *)(iVar5 + 400) == 4) {
              *(short *)(iVar6 + 0x1c) = selectedId;
              *(int *)(iVar5 + 0x1a8) = (s16)selectedId;
            }
            FUN_005225a8(DAT_0069d7a0 + 0x10);
            break;
          case 9:
            *(short *)(iVar6 + 0x16) = selectedId;
            *(int *)(iVar5 + 0x19c) = (s16)selectedId;
          }
          break;
        }
        break;
      case '\n':
        switch (eventKind) {
        case 3:
        case 0x1a:
          *(s16 *)(iVar6 + 0x16) = -1;
          break;
        case 9:
          break;
        case 0x12:
          *(s16 *)(iVar6 + 0x12) = -1;
          break;
        }
        break;
      case '\x13':
        if (*(char *)(iVar6 + 0x10) == '\x03') {
          *(s16 *)(iVar6 + 0x14) = -1;
        }
        break;
      }

    }

    FUN_0036f640((int)param_3);

  }

  return 0;

}


#pragma opt_loop_invariants reset
/* W367 pragma probe: opt_loop_invariants on nd 886 -> 879; off nd 886; object 1396/1408. */
#pragma opt_loop_invariants on
// FUN_00369320 NONMATCHING


u64 FUN_00369320(u64 param_1,int param_2,u64 param_3)



{

  char cVar1;

  int iVar2;

  int *piVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  u8 uVar7;

  u16 uVar8;

  

  iVar5 = (int)param_3;

  iVar2 = *(int *)(iVar5 + 0x16c);

  uVar7 = (u8)iVar2;

  if (*(int *)(iVar5 + 0xdc) == 0) {

    iVar4 = *(int *)(iVar5 + 0x104);

    if (iVar4 == 0xb) {
      FUN_00397510(param_3,iVar2);
      FUN_00393f30(param_3,0x36e690);
      FUN_0036f640(param_3);
      FUN_0036f640(param_3);
      return 0;
    }
    if (iVar4 == 6) {
      FUN_0038b6e0(param_3,iVar2,*(u32 *)(iVar5 + 0x18));
      FUN_0038b960(param_3,*(u32 *)(iVar5 + 0x18),iVar2);
      FUN_0038bc70(param_3,*(u32 *)(iVar5 + 0x18),iVar2);
      FUN_0036f640(param_3);
      return 0;
    }
    if (iVar4 == 5) {
      *(int *)(iVar5 + 0xc) = iVar2 + 1;
      FUN_0036f640(param_3);
      return 0;
    }

  }

  else if ((*(int *)(iVar5 + 0xdc) == 1) && (param_2 == 0xf)) {

    if ((&DAT_0069e422)[*(int *)(iVar5 + 0x268) + **(int **)(iVar5 + 0x164) * 0xc] == '\x03') {

      *(u8 *)((int)*(int **)(iVar5 + 0x164) + 0x22) = uVar7;

    }

    FUN_0036f640(param_3);

    return 0;

  }


  piVar3 = *(int **)(iVar5 + 0x164);
  if (piVar3 == (int *)0x0) {

    iVar4 = 0;

  }

  else {

    iVar6 = 0;

    for (iVar4 = piVar3[0x1b];

        (iVar6 < *(int *)(iVar5 + 0x160) + *(int *)(iVar5 + 0x15c) && (iVar4 != 0));

        iVar4 = *(int *)(iVar4 + 0x4c)) {

      iVar6 = iVar6 + 1;

    }

  }

  if (iVar4 != 0) {

    iVar6 = *piVar3;

    cVar1 = (&DAT_0069e1a2)[*(int *)(iVar5 + 0x158) + iVar6 * 0xc];

    if (cVar1 == '\x19') {

      if (*(char *)(iVar4 + 0x10) == '\x02') {

        *(u8 *)(iVar4 + 0x11) = uVar7;

      }

    }

    else {

      uVar8 = (u16)iVar2;

      if (cVar1 == '\x17') {

        if (*(char *)(iVar4 + 0x10) == '\0') {

          *(u16 *)(iVar4 + 0x14) = uVar8;

        }

        else if (*(char *)(iVar4 + 0x10) == '\x01') {

          *(u16 *)(iVar4 + 0x14) = uVar8;

        }

      }

      else if (cVar1 != '\x13') {

        if (cVar1 == '\a') {

          *(u16 *)(iVar4 + 0x12) = uVar8;

        }

        else if (cVar1 != '\x15') {

          if (cVar1 == '\b') {

            if (iVar6 == 0x30) {

              *(u8 *)(iVar4 + 0x31) = uVar7;

            }

            else if (iVar6 == 0x26) {

              *(u16 *)(iVar4 + 0x10) = uVar8;

            }

            else if (iVar6 == 2) {

              *(u16 *)(iVar4 + 0x16) = uVar8;

            }

            else if (iVar6 == 0x1e) {

              *(u16 *)(iVar4 + 0x10) = uVar8;

            }

            else if (iVar6 == 6) {

              *(u16 *)(iVar4 + 0x12) = uVar8;

            }

            else if (iVar6 == 0x1d) {

              *(u16 *)(iVar4 + 0x10) = uVar8;

            }

            else if (iVar6 != 0x1c) {

              if (iVar6 == 4) {

                *(u16 *)(iVar4 + 0x10) = uVar8;

              }

              else if (iVar6 == 0x12) {

                *(u8 *)(iVar4 + 0x14) = uVar7;

              }

              else if (iVar6 == 0xc) {

                *(int *)(iVar4 + 0x14) = iVar2;

              }

              else if ((iVar6 == 0x1a) || (iVar6 == 3)) {

                *(u8 *)(iVar4 + 0x15) = uVar7;

              }

              else if (iVar6 == 0x13) {

                *(u16 *)(iVar4 + 0x12) = uVar8;

              }

              else if (iVar6 == 5) {

                *(u16 *)(iVar4 + 0x10) = uVar8;

              }

            }

          }

          else if (cVar1 == '\x06') {

            *(float *)(iVar4 + 0x10) = fGpffff8438 * *(float *)(iVar5 + 0x184);

          }

          else if (cVar1 != '\x05') {

            if (cVar1 == '\x04') {

              *(u16 *)(iVar4 + 0x12) = uVar8;

            }

            else if (cVar1 == '\x1c') {

              if (iVar6 == 5) {

                if ((*(char *)(iVar4 + 0x12) == '\0') || (*(char *)(iVar4 + 0x12) == '\x02')) {

                  *(u16 *)(iVar4 + 0x10) = uVar8;

                }

                else {

                  *(u16 *)(iVar4 + 0x14) = uVar8;

                }

              }

              else if (iVar6 == 0x27) {

                *(u16 *)(iVar4 + 0x14) = uVar8;

              }

            }

            else if (cVar1 == '\x03') {

              if (iVar6 == 0x1f) {

                *(u16 *)(iVar4 + 0x12) = uVar8;

              }

              else if (iVar6 == 0xc) {

                *(u16 *)(iVar4 + 0x12) = uVar8;

              }

              else if (iVar6 == 8) {

                *(u16 *)(iVar4 + 0x10) = uVar8;

              }

            }

            else if (cVar1 == '\x02') {

              if (iVar6 == 7) {

                *(u16 *)(iVar4 + 0x10) = uVar8;

              }

            }

            else if (cVar1 == '\x01') {

              *(u16 *)(iVar4 + 2) = uVar8;

            }

          }

        }

      }

    }

    FUN_0036f640(param_3);

  }

  return 0;

}


// Removing the decompiler's apparent t0 call-output assignment regressed
// nd224 -> nd234 at unchanged size376/384, so the assignment was restored.
#pragma opt_loop_invariants reset
// FUN_003698A0 NONMATCHING


u32 FUN_003698a0(u64 param_1,u64 param_2,int param_3)
{
  char cVar1;
  int *piVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  int limit;
  int extraout_t0;

  iVar5 = (int)param_3;
  piVar2 = *(int **)(iVar5 + 0x164);
  if (piVar2 == (int *)0x0) {
    psVar3 = (short *)0x0;
  }
  else {
    psVar3 = (short *)piVar2[0x1b];
    iVar4 = 0;
    limit = *(int *)(iVar5 + 0x160) + *(int *)(iVar5 + 0x15c);
    while ((iVar4 < limit) && (psVar3 != (short *)0x0)) {
      psVar3 = *(short **)(psVar3 + 0x26);
      iVar4 = iVar4 + 1;
    }
  }
  if (psVar3 != (short *)0x0) {
    iVar4 = *piVar2;
    cVar1 = (&DAT_0069e1a2)[*(int *)(iVar5 + 0x158) + iVar4 * 0xc];
    if (cVar1 == '\x0f') {
      psVar3[1] = (short)*(u32 *)(iVar5 + 0x16c);
    }
    else if (cVar1 == '\t') {
      if (iVar4 == 0x21) {
        psVar3[8] = (short)*(u32 *)(iVar5 + 0x16c);
      }
      else if (iVar4 == 0x12) {
        psVar3[8] = (short)*(u32 *)(iVar5 + 0x16c);
      }
      else if ((((iVar4 == 0x15) || (iVar4 == 0x14)) || (iVar4 == 0x1a)) || (iVar4 == 3)) {
        psVar3[9] = (short)*(u32 *)(iVar5 + 0x16c);
      }
    }
    else if (cVar1 == '\0') {
      *psVar3 = (short)*(u32 *)(iVar5 + 0x16c) - (short)piVar2[8];
      FUN_00361270(*(u32 *)(iVar5 + 0x164));
      param_3 = extraout_t0;
    }
    FUN_0036f640(param_3);
  }
  return 0;
}


// FUN_00369A20 NONMATCHING
u64 FUN_00369a20(int param_1,u64 param_2,int param_3)



{

  char cVar1;

  u16 uVar2;

  u16 uVar3;

  u16 uVar4;

  int *piVar5;

  u32 *puVar6;

  int lVar7;

  int iVar8;

  u16 *puVar9;

  u8 *iVar10;

  u32 uVar11;

  u32 uVar12;

  u32 uVar13;

  f32 afStack_20[3];

  f32 afStack_10[3];

  
  iVar10 = (u8 *)param_3;

  if (param_1 == -4) {

    if (*(int *)(iVar10 + 0x158) == 0) {

      *(u32 *)(iVar10 + 0x268) = 0;

    }

    else {

      *(u32 *)(iVar10 + 0x268) = 1;

    }

    FUN_0036f5f0(0xf,0xc,0x1c,param_3);

  }

  else {

    piVar5 = *(int **)(iVar10 + 0x164);

    if (*(int *)(iVar10 + 0x160) + *(int *)(iVar10 + 0x15c) < piVar5[0x1a]) {

      if (param_1 == -2) {

        *(u32 *)(iVar10 + 0x168) = 0xffffffff;

        *(u32 *)(iVar10 + 0x118) = 0;

        *(u32 *)(iVar10 + 0x11c) = 3;

        *(char **)(iVar10 + 0x120) = s_DELETE_FRAME_OK__0069db30;

        *(u8 ***)(iVar10 + 0x124) = &PTR_DAT_0069d930;

        FUN_0036f5f0(2,0x12,0xb,param_3);

        return 0;

      }

      if (param_1 != -3) {

        *(int *)(iVar10 + 0x168) =

             (int)((char *)&DAT_0069e1a2)[*(int *)(iVar10 + 0x158) + *piVar5 * 0xc];

        piVar5 = *(int **)(iVar10 + 0x164);

        if (piVar5 == (int *)0x0) {

          puVar9 = (u16 *)0x0;

        }

        else {

          iVar8 = 0;

          for (puVar9 = (u16 *)piVar5[0x1b];

              (iVar8 < *(int *)(iVar10 + 0x160) + *(int *)(iVar10 + 0x15c) &&

              (puVar9 != (u16 *)0x0)); puVar9 = *(u16 **)(puVar9 + 0x26)) {

            iVar8 = iVar8 + 1;

          }

        }

        switch(*(u32 *)(iVar10 + 0x168)) {

        case 0:

          *(u32 *)(iVar10 + 0x16c) = (u32)*puVar9 + (int)(short)piVar5[8];

          *(int *)(iVar10 + 0x170) = (int)*(short *)(*(int *)(iVar10 + 0x164) + 0x20);

          *(int *)(iVar10 + 0x174) = *(int *)(iVar10 + 0xc) + -1;

          FUN_0036f5f0(6,0xf,10,param_3);

          break;

        case 1:

          *(u32 *)(iVar10 + 0x16c) = (u32)puVar9[1];

          *(u32 *)(iVar10 + 0x170) = 0;

          *(u32 *)(iVar10 + 0x174) = 10000;

          if ((**(int **)(iVar10 + 0x164) != 10) ||

             (*(char *)((int)*(int **)(iVar10 + 0x164) + 0x22) == '\x03')) {

            FUN_0036f5f0(7,0xf,10,param_3);

          }

          break;

        case 2:

          if (*piVar5 == 7) {

            *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[8];

            *(u32 *)(iVar10 + 0x170) = 0;

            *(u32 *)(iVar10 + 0x174) = 3000;

            FUN_0036f5f0(7,0xf,10,param_3);

          }

          break;

        case 3:

          iVar8 = *piVar5;

          if (iVar8 == 0x1f) {

            *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[9];

            *(u32 *)(iVar10 + 0x170) = 0;

            *(u32 *)(iVar10 + 0x174) = 0xff;

          }

          else if (iVar8 == 0xc) {

            *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[9];

            *(u32 *)(iVar10 + 0x170) = 0xffffff01;

            *(u32 *)(iVar10 + 0x174) = 0xff;

          }

          else if (iVar8 == 8) {

            *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[8];

            *(u32 *)(iVar10 + 0x170) = 0;

            *(u32 *)(iVar10 + 0x174) = 0xff;

          }

          if ((**(int **)(iVar10 + 0x164) != 0x1f) || (puVar9[8] != 0)) {

            FUN_0036f5f0(7,0xf,10,param_3);

          }

          break;

        case 4:

          *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[9];

          *(u32 *)(iVar10 + 0x170) = 0xffffff01;

          *(u32 *)(iVar10 + 0x174) = 0xff;

          FUN_0036f5f0(7,0xf,10,param_3);

          break;

        case 5:

          iVar8 = *piVar5;

          if (iVar8 == 0x19) {

            *(int *)(iVar10 + 0x118) = (int)(short)puVar9[10];

          }

          else if (iVar8 == 0x18) {

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[8];

          }

          else if ((((iVar8 == 0x17) || (iVar8 == 0xf)) || (iVar8 == 0x11)) ||

                  (((iVar8 == 0x10 || (iVar8 == 0xe)) || ((iVar8 == 0xd || (iVar8 == 0xb)))))) {

            *(int *)(iVar10 + 0x118) = (int)(short)puVar9[8];

          }

          else if (iVar8 == 10) {

            *(u32 *)(iVar10 + 0x118) = *(u32 *)(puVar9 + 2);

          }

          else if (iVar8 == 8) {

            *(int *)(iVar10 + 0x118) = (int)(short)puVar9[10];

          }

          *(u32 *)(iVar10 + 0x11c) = 2;

          *(char **)(iVar10 + 0x120) = s_HOKAN_MODE_0069db48;

          *(u8 **)(iVar10 + 0x124) = &gp0xffff9dd0;

          FUN_0036f5f0(2,0x12,10,param_3);

          break;

        case 6:

          *(float *)(iVar10 + 0x184) = fGpffff80d0 * *(float *)(puVar9 + 8);

          *(u32 *)(iVar10 + 0x188) = 0x3f800000;

          *(u32 *)(iVar10 + 0x18c) = 0x43340000;

          FUN_0036f5f0(8,0xf,10,param_3);

          break;

        case 7:

          *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[9];

          *(u32 *)(iVar10 + 0x170) = 0;

          *(u32 *)(iVar10 + 0x174) = 0x7f;

          FUN_0036f5f0(7,0xf,10,param_3);

          break;

        case 8:

          iVar8 = *piVar5;

          if (iVar8 == 0x26) {

            *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[8];

            *(u32 *)(iVar10 + 0x170) = *(u32 *)(iVar10 + 0x10);

            *(u32 *)(iVar10 + 0x174) = *(u32 *)(iVar10 + 0x14);

            FUN_0036f5f0(7,0xf,10,param_3);

          }

          else if (iVar8 == 2) {

            *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[0xb];

            *(u32 *)(iVar10 + 0x170) = 0;

            *(u32 *)(iVar10 + 0x174) = 999;

            FUN_0036f5f0(7,0xf,10,param_3);

          }

          else if (iVar8 == 1) {

            *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[0x10];

            *(u32 *)(iVar10 + 0x170) = 0;

            *(u32 *)(iVar10 + 0x174) = 999;

            FUN_0036f5f0(7,0xf,10,param_3);

          }

          else if (iVar8 == 0x1e) {

            *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[8];

            *(u32 *)(iVar10 + 0x170) = 0;

            *(u32 *)(iVar10 + 0x174) = 0x3c;

            FUN_0036f5f0(7,0xf,10,param_3);

          }

          else if (iVar8 == 0x1d) {

            *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[8];

            *(u32 *)(iVar10 + 0x170) = 0;

            *(u32 *)(iVar10 + 0x174) = 0xb4;

            FUN_0036f5f0(7,0xf,10,param_3);

          }

          else if (iVar8 != 0x1c) {

            if (iVar8 == 6) {

              *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[9];

              if (puVar9[8] == 0) {

                *(u32 *)(iVar10 + 0x170) = 0xffffffff;

              }

              else {

                *(u32 *)(iVar10 + 0x170) = 0;

              }

              *(u32 *)(iVar10 + 0x174) = 7;

              FUN_0036f5f0(7,0xf,10,param_3);

            }

            else if (iVar8 == 4) {

              *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[8];

              *(u32 *)(iVar10 + 0x170) = 0;

              *(u32 *)(iVar10 + 0x174) = 500;

              FUN_0036f5f0(7,0xf,10,param_3);

            }

            else if (iVar8 == 0x12) {

              *(int *)(iVar10 + 0x16c) = (int)(char)puVar9[10];

              *(u32 *)(iVar10 + 0x170) = 0;

              *(u32 *)(iVar10 + 0x174) = 2;

              FUN_0036f5f0(7,0xf,10,param_3);

            }

            else if (iVar8 == 0xc) {

              *(u32 *)(iVar10 + 0x16c) = *(u32 *)(puVar9 + 10);

              *(u32 *)(iVar10 + 0x170) = 0;

              *(u32 *)(iVar10 + 0x174) = 0xff;

              FUN_0036f5f0(7,0xf,10,param_3);

            }

            else if ((iVar8 == 0x1a) || (iVar8 == 3)) {

              *(int *)(iVar10 + 0x16c) = (int)*(char *)((int)puVar9 + 0x15);

              *(u32 *)(iVar10 + 0x170) = 0xffffffff;

              *(u32 *)(iVar10 + 0x174) = 0x7f;

              FUN_0036f5f0(7,0xf,10,param_3);

            }

            else if (iVar8 == 0x13) {

              *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[9];

              if (puVar9[8] == 3) {

                *(u32 *)(iVar10 + 0x170) = 0xffffffff;

              }

              else {

                *(u32 *)(iVar10 + 0x170) = 0;

              }

              *(u32 *)(iVar10 + 0x174) = 0xff;

              FUN_0036f5f0(7,0xf,10,param_3);

            }

            else if (iVar8 == 5) {

              *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[8];

              *(u32 *)(iVar10 + 0x170) = 0;

              *(u32 *)(iVar10 + 0x174) = 10000;

              FUN_0036f5f0(7,0xf,10,param_3);

            }

          }

          break;

        case 9:

          *(u32 *)(iVar10 + 0x170) = 0;

          *(u32 *)(iVar10 + 0x174) = 10000;

          iVar8 = **(int **)(iVar10 + 0x164);

          if (iVar8 != 0x21) {

            if (iVar8 == 0x12) {

              *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[8];

              FUN_0036f5f0(6,0xf,10,param_3);

            }

            else if (((iVar8 == 0x15) || (iVar8 == 0x14)) || ((iVar8 == 0x1a || (iVar8 == 3)))) {

              *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[9];

              FUN_0036f5f0(6,0xf,10,param_3);

            }

          }

          break;

        case 10:

          *(u32 *)(iVar10 + 0x108) = 0;

          *(u32 *)(iVar10 + 0x110) = 0;

          *(u32 *)(iVar10 + 0x660) = 8;

          FUN_0036f5f0(10,0xd,7,param_3);

          break;

        case 0xb:

          iVar8 = *piVar5;

          if (iVar8 == 0x19) {

            *(int *)(iVar10 + 0x118) = (int)(short)puVar9[8];

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_ON_OFF_MODE_0069db58;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9dd0;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0x16) {

            *(int *)(iVar10 + 0x118) = (int)(short)puVar9[8];

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_ON_OFF_MODE_0069db58;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9dd0;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 9) {

            *(int *)(iVar10 + 0x118) = (int)(short)puVar9[9];

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_ON_OFF_MODE_0069db58;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9dd0;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          break;

        case 0xc:

          iVar8 = *piVar5;

          if (iVar8 == 0x2f) {

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[8];

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_FIELDOBJ_EDIT_PARAM_0069dd80;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9d98;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0x2b) {

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[8];

            *(u32 *)(iVar10 + 0x11c) = 6;

            *(char **)(iVar10 + 0x120) = s_COND_ON_SELECT_0069dd60;

            *(u8 ***)(iVar10 + 0x124) = &PTR_DAT_0069db10;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0x29) {

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[8];

            *(u32 *)(iVar10 + 0x11c) = 0xe;

            *(char **)(iVar10 + 0x120) = s_CUSTOM_EVENT_SELECT_0069dd40;

            *(u8 ***)(iVar10 + 0x124) = &PTR_s_HIRU_SASO_0069d880;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0x27) {

            *(u32 *)(iVar10 + 0x118) = 0;

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_KEYFREE_SELECT_0069dd20;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9f30;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 4) {

            *(u32 *)(iVar10 + 0x118) = 0;

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_MESSAGE_STOP_0069dd08;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9f20;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0x22) {

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[8];

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_WAIT_MODE_SELECT_0069dcf0;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9f10;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0x1d) {

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[10];

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_END_STOP_MODE_0069dcd8;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9f08;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if ((((iVar8 == 0x15) || (iVar8 == 0x14)) || (iVar8 == 0x1a)) || (iVar8 == 3)) {

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[0xc];

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_FADE_MODE_0069dcc8;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9f00;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0x18) {

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[0x12];

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_PRIORITY_0069dcb8;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9ef8;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0x20) {

            *(int *)(iVar10 + 0x118) = (int)(short)puVar9[8];

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_BISTA_MODE_0069dca8;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9ee0;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0x1f) {

            *(int *)(iVar10 + 0x118) = (int)(short)puVar9[8];

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_SELECT_MODE_0069dc98;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9ed8;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0x1e) {

            *(int *)(iVar10 + 0x118) = (int)(short)puVar9[9];

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_TIMEI_FADE_DOWN_UP_0069dc80;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9ec0;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 10) {

            *(int *)(iVar10 + 0x118) = (int)(short)puVar9[0xe];

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_CONFIG_DRAW_STOP_0069dc60;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9ea8;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0x1c) {

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[8];

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_PADACT_TYPE_0069dc48;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9e98;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0x25) {

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[8];

            *(u32 *)(iVar10 + 0x11c) = 4;

            *(char **)(iVar10 + 0x120) = s_EFFECT_MODE_0069dc38;

            *(u8 ***)(iVar10 + 0x124) = &PTR_s_CREATE_0069da70;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0x24) {

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[8];

            *(u32 *)(iVar10 + 0x11c) = 3;

            *(char **)(iVar10 + 0x120) = s_KOMA_MODE_0069dc28;

            *(u8 ***)(iVar10 + 0x124) = &PTR_DAT_0069da60;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0x23) {

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[8];

            *(u32 *)(iVar10 + 0x11c) = 4;

            *(char **)(iVar10 + 0x120) = s_B_UP_CONTROL_SELECT_0069dc10;

            *(u8 ***)(iVar10 + 0x124) = &PTR_DAT_0069da50;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0x31) {

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[8];

            *(u32 *)(iVar10 + 0x11c) = 1;

            *(char **)(iVar10 + 0x120) = s_FIELD_EFFECT_MODE_0069dbf0;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9db8;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0x21) {

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[9];

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_CAMERA_CONTROL_TYPE_0069dbd0;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9e48;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0x30) {

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[8];

            *(u32 *)(iVar10 + 0x11c) = 0xb;

            *(char **)(iVar10 + 0x120) = s_UNIT_CONTROL_TYPE_0069dbb0;

            *(u8 ***)(iVar10 + 0x124) = &PTR_DAT_0069da10;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 1) {

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[8];

            *(u32 *)(iVar10 + 0x11c) = 0xb;

            *(char **)(iVar10 + 0x120) = s_UNIT_CONTROL_TYPE_0069dbb0;

            *(u8 ***)(iVar10 + 0x124) = &PTR_DAT_0069da10;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0x13) {

            *(int *)(iVar10 + 0x118) = (int)(short)puVar9[8];

            *(u32 *)(iVar10 + 0x11c) = 7;

            *(char **)(iVar10 + 0x120) = s_CONTROL_TYPE_0069db98;

            *(u8 ***)(iVar10 + 0x124) = &PTR_DAT_0069d960;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 5) {

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[9];

            *(u32 *)(iVar10 + 0x11c) = 4;

            *(char **)(iVar10 + 0x120) = s_ADX_SE_MODE_0069db88;

            *(u8 **)(iVar10 + 0x124) = &DAT_0069d910;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 6) {

            *(int *)(iVar10 + 0x118) = (int)(short)puVar9[8];

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_FADE_TYPE_0069db78;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9df8;

            FUN_0036f5f0(2,0x12,10,param_3);

          }

          else if (iVar8 == 0xc) {

            *(int *)(iVar10 + 0x118) = (int)(short)puVar9[8];

            *(u32 *)(iVar10 + 0x11c) = 3;

            *(char **)(iVar10 + 0x120) = s_TRANS_MODE_0069db68;

            *(u8 ***)(iVar10 + 0x124) = &PTR_s_NORMAL_0069d940;

            FUN_0036f5f0(2,0xd8,0x78,param_3);

          }

          break;

        case 0xd:

          iVar8 = *piVar5;

          if (iVar8 != 6) {

            if (iVar8 == 0x19) {

              *(u32 *)(iVar10 + 0x284) = 0;

              *(u32 *)(iVar10 + 0x288) = 0;

              *(u32 *)(iVar10 + 0x28c) = 1;

              FUN_0036f5f0(0xb,0,0,param_3);

            }

            else if (iVar8 == 0x18) {

              *(u32 *)(iVar10 + 0x274) = 0;

              *(u32 *)(*(int *)(iVar10 + 0x164) + 0x34) = 1;

              FUN_0036f5f0(0xb,0,0,param_3);

            }

            else if ((((((iVar8 != 0x11) && (iVar8 != 0x10)) && (iVar8 != 0x1b)) &&

                      ((iVar8 != 0x17 && (iVar8 != 0xf)))) && (iVar8 != 0xe)) &&

                    ((iVar8 != 0xd && (iVar8 != 0xb)))) {

              if (iVar8 == 0x24) {

                if ((char)puVar9[8] == '\0') {

                  *(int *)(iVar10 + 0x198) = (int)(short)puVar9[0xe];

                  *(int *)(iVar10 + 0x19c) = (int)(short)puVar9[0xf];

                  *(int *)(iVar10 + 0x1a0) = (int)(char)puVar9[0x10];

                  *(int *)(iVar10 + 0x1a4) = (int)(short)puVar9[10];

                  *(int *)(iVar10 + 0x1a8) = (int)(short)puVar9[0xb];

                  *(int *)(iVar10 + 0x1ac) = (int)(short)puVar9[0xc];

                  *(int *)(iVar10 + 0x1b0) = (int)(short)puVar9[0xd];

                  *(int *)(iVar10 + 0x1b4) = (int)(char)puVar9[0x11];

                  FUN_0036f5f0(0x1e,0xd,0x14,param_3);

                }

              }

              else if (iVar8 == 10) {

                puVar6 = *(u32 **)(puVar9 + 0x24);

                uVar11 = FUN_0038ab00(*(u8 *)(*(int *)(iVar10 + 0x164) + 0x22),

                                      *(u16 *)(*(int *)(iVar10 + 0x164) + 0x24));

                *(u32 *)(iVar10 + 0x210) = uVar11;

                *(u32 *)(iVar10 + 0x198) = puVar6[8];

                *(u32 *)(iVar10 + 0x19c) = puVar6[9];

                *(u32 *)(iVar10 + 0x1a0) = puVar6[10];

                *(u32 *)(iVar10 + 0x1a4) = *puVar6;

                *(u32 *)(iVar10 + 0x1a8) = puVar6[1];

                *(u32 *)(iVar10 + 0x1ac) = puVar6[2];

                *(u32 *)(iVar10 + 0x1b0) = puVar6[5];

                *(u32 *)(iVar10 + 0x1b4) = puVar6[4];

                *(u32 *)(iVar10 + 0x1b8) = puVar6[6];

                *(u32 *)(iVar10 + 0x16c) = 4;

                uVar11 = FUN_00385cd0(param_3);

                *(u32 *)(iVar10 + 0xe8) = uVar11;

                FUN_0036f5f0(0x1a,0,0,param_3);

              }

              else if ((iVar8 == 0x15) || (iVar8 == 0x14)) {

                *(u32 *)(iVar10 + 0x114) = 0;

                FUN_0036f5f0(0xc,10,7,param_3);

              }

            }

          }

          break;

        case 0xf:

          *(u32 *)(iVar10 + 0x170) = 0;

          *(u32 *)(iVar10 + 0x174) = 10000;

          *(u32 *)(iVar10 + 0x16c) = (u32)puVar9[1];

          FUN_0036f5f0(6,0xf,10,param_3);

          break;

        case 0x10:

          iVar8 = *piVar5;

          if ((iVar8 == 0x1a) || (iVar8 == 3)) {

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[10];

          }

          else if ((iVar8 == 0x15) || (iVar8 == 0x14)) {

            *(int *)(iVar10 + 0x118) = (int)*(char *)((int)puVar9 + 0x11);

          }

          *(u32 *)(iVar10 + 0x11c) = 2;

          *(char **)(iVar10 + 0x120) = s_ON_OFF_MODE_0069db58;

          *(u8 **)(iVar10 + 0x124) = &gp0xffff9dd0;

          FUN_0036f5f0(2,0x12,10,param_3);

          break;

        case 0x11:

          *(int *)(iVar10 + 0x198) = (int)*(char *)((int)puVar9 + 0x15);

          *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[8];

          *(int *)(iVar10 + 0x19c) = (int)(char)puVar9[0xb];

          *(u32 *)(iVar10 + 0x214) = 0;

          *(u32 *)(iVar10 + 0x170) = 0;

          iVar8 = (int)FUN_0039f710_evt_main((int *)(iVar10 + 0x82c));

          *(int *)(iVar10 + 0x174) = iVar8 + -1;

          FUN_0036f5f0(0xd,0xf,10,param_3);

          break;

        case 0x12:

          uVar2 = puVar9[5];

          uVar3 = puVar9[6];

          uVar4 = puVar9[7];

          *(u16 *)(iVar10 + 0x784) = puVar9[4];

          *(u16 *)(iVar10 + 0x786) = uVar2;

          *(u16 *)(iVar10 + 0x788) = uVar3;

          *(u16 *)(iVar10 + 0x78a) = uVar4;

          FUN_0036f5f0(0xe,0xf,10,param_3);

          break;

        case 0x13:

          switch((char)puVar9[8]) {

          case '\0':

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[10];

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_ON_OFF_MODE_0069db58;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9dd8;

            FUN_0036f5f0(2,0x12,10,param_3);

            break;

          case '\x01':

            *(u32 *)(iVar10 + 400) = 0;

            *(int *)(iVar10 + 0x198) = (int)(char)puVar9[10];

            *(int *)(iVar10 + 0x19c) = (int)*(char *)((int)puVar9 + 0x15);

            *(int *)(iVar10 + 0x1a0) = (int)(short)puVar9[0xb];

            *(int *)(iVar10 + 0x1a4) = (int)(char)puVar9[0x12];

            *(int *)(iVar10 + 0x1a8) = (int)*(char *)((int)puVar9 + 0x25);

            *(int *)(iVar10 + 0x1ac) = (int)(char)puVar9[0x13];

            FUN_0036f5f0(0x1b,0xd,0xd,param_3);

            break;

          case '\x02':

            lVar7 = (int)FUN_003b5d10_evt_main((u16)piVar5[3]);

            if (lVar7 != 0) {

              *(u32 *)(iVar10 + 0x16c) = *(u32 *)(puVar9 + 10);

              *(u32 *)(iVar10 + 0x21c) = 0;

              *(u32 *)(iVar10 + 0x170) = 0;

              *(u32 *)(iVar10 + 0x174) = 1000;

              *(int *)(iVar10 + 0x23c) = (int)lVar7;

              *(int *)(iVar10 + 0x198) = (int)(short)puVar9[0x10];

              *(int *)(iVar10 + 0x19c) = (int)(char)puVar9[0x11];

              *(int *)(iVar10 + 0x1a0) = (int)*(char *)((int)puVar9 + 0x23);

              *(int *)(iVar10 + 0x1a4) = (int)(char)puVar9[0x12];

              *(int *)(iVar10 + 0x1a8) = (int)*(char *)((int)puVar9 + 0x25);

              *(int *)(iVar10 + 0x1ac) = (int)(short)puVar9[0x13];

              *(int *)(iVar10 + 0x1b0) = (int)(short)puVar9[0x14];

              *(int *)(iVar10 + 0x1b4) = (int)(short)puVar9[0x15];

              FUN_0036f5f0(0x10,0xf,10,param_3);

            }

            break;

          case '\x03':

            FUN_0038a590(param_3,1);

            *(u32 *)(iVar10 + 0x220) = 0;

            *(u32 *)(iVar10 + 0x16c) = *(u32 *)(puVar9 + 10);

            FUN_0036f5f0(0x17,0xf,0x19,param_3);

            break;

          case '\x04':

            lVar7 = (int)FUN_003b5d10_evt_main((u16)piVar5[3]);

            if (lVar7 != 0) {

              *(u32 *)(iVar10 + 400) = 0;

              FUN_0038a590(param_3,1);

              iVar8 = (int)lVar7;

              *(int *)(iVar10 + 0x238) = iVar8;

              uVar11 = *(u32 *)(iVar8 + 0x14);

              uVar12 = *(u32 *)(iVar8 + 0x18);

              *(u32 *)(iVar10 + 0x22c) = *(u32 *)(iVar8 + 0x10);

              *(u32 *)(iVar10 + 0x230) = uVar11;

              *(u32 *)(iVar10 + 0x234) = uVar12;

              *(u32 *)(iVar10 + 0x170) = 0;

              *(u32 *)(iVar10 + 0x174) = 600;

              *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[0x12];

              *(int *)(iVar10 + 0x198) = (int)*(float *)(puVar9 + 10);

              *(u32 *)(iVar10 + 0x19c) = 0;

              FUN_0036f5f0(0x19,0xc,0x19,param_3);

            }

            break;

          case '\x05':

            *(u32 *)(iVar10 + 400) = 0;

            *(int *)(iVar10 + 0x198) = (int)*(char *)((int)puVar9 + 0x15);

            *(int *)(iVar10 + 0x19c) = (int)(char)puVar9[10];

            FUN_0036f5f0(0x1d,0xc,0x17,param_3);

            break;

          case '\x06':

            *(u32 *)(iVar10 + 400) = 0;

            *(int *)(iVar10 + 0x198) = (int)(char)puVar9[10];

            *(int *)(iVar10 + 0x19c) = (int)*(char *)((int)puVar9 + 0x15);

            FUN_0036f5f0(0x1f,0xc,0x17,param_3);

            break;

          case '\a':

            *(u32 *)(iVar10 + 400) = 0;

            *(int *)(iVar10 + 0x198) = (int)(char)puVar9[10];

            *(int *)(iVar10 + 0x19c) = (int)*(char *)((int)puVar9 + 0x15);

            *(int *)(iVar10 + 0x1a0) = (int)(char)puVar9[0xb];

            *(u32 *)(iVar10 + 0x1a4) = *(u32 *)(puVar9 + 0xc);

            FUN_0036f5f0(0x23,0xc,0x12,param_3);

            break;

          case '\b':

            uVar11 = FUN_00386780(param_3,puVar9[10],(char)puVar9[0xc],

                                  *(u8 *)((int)puVar9 + 0x19));

            *(u32 *)(iVar10 + 0xe8) = uVar11;

            FUN_0036f5f0(0x1a,10,0x12,param_3);

            break;

          case '\t':

            *(int *)(iVar10 + 0x118) = (int)(char)puVar9[10];

            *(u32 *)(iVar10 + 0x11c) = 2;

            *(char **)(iVar10 + 0x120) = s_ON_OFF_MODE_0069db58;

            *(u8 **)(iVar10 + 0x124) = &gp0xffff9dd8;

            FUN_0036f5f0(2,0x12,10,param_3);

            break;

          case '\n':

            uVar11 = FUN_00386940(*(u32 *)(puVar9 + 0xc),param_3,puVar9[10]);

            *(u32 *)(iVar10 + 0xe8) = uVar11;

            FUN_0036f5f0(0x1a,10,0x12,param_3);

          }

          break;

        case 0x14:

          *(u32 *)(iVar10 + 0x108) = 0;

          *(u32 *)(iVar10 + 0x110) = 0;

          FUN_0036f5f0(0x15,0xf,10,param_3);

          break;

        case 0x16:

          *(u32 *)(iVar10 + 400) = 0;

          FUN_0038a590(param_3,1);

          break;

        case 0x17:

          cVar1 = (char)puVar9[8];
          switch (cVar1) {
          case '\0':
            *(int *)(iVar10 + 0x198) = (int)(short)puVar9[10];
            *(int *)(iVar10 + 0x19c) = (int)(short)puVar9[0xb];
            *(int *)(iVar10 + 0x1a0) = (int)(short)puVar9[0xc];
            *(int *)(iVar10 + 0x1a4) = (int)(short)puVar9[0xd];
            *(int *)(iVar10 + 0x1a8) = (int)(short)puVar9[0xe];
            uVar11 = FUN_00385bd0(param_3,*(u32 *)(iVar10 + 0x92c));
            *(u32 *)(iVar10 + 0xe8) = uVar11;
            FUN_0036f5f0(0x1a,0,0,param_3);
            break;
          case '\x01':
            break;
          case '\x02':
            *(u32 *)(iVar10 + 0x118) = 0;
            *(u32 *)(iVar10 + 0x11c) = 2;
            *(u8 **)(iVar10 + 0x120) = &gp0xffff9e58;
            *(u8 **)(iVar10 + 0x124) = &gp0xffff9f58;
            FUN_0036f5f0(2,0x12,10,param_3);
            break;
          case '\x03':
            *(u32 *)(iVar10 + 0x118) = 0;
            *(u32 *)(iVar10 + 0x11c) = 2;
            *(u8 **)(iVar10 + 0x120) = &gp0xffff9e60;
            *(u8 **)(iVar10 + 0x124) = &gp0xffff9f58;
            FUN_0036f5f0(2,0x12,10,param_3);
            break;
          }

          break;

        case 0x19:

          cVar1 = (char)puVar9[8];
          switch (cVar1) {
          case '\0':
            *(int *)(iVar10 + 0x198) = (int)*(char *)((int)puVar9 + 0x11);
            *(int *)(iVar10 + 0x19c) = (int)(char)puVar9[9];
            *(int *)(iVar10 + 0x1a0) = (int)*(char *)((int)puVar9 + 0x13);
            uVar11 = FUN_00385f90(param_3);
            *(u32 *)(iVar10 + 0xe8) = uVar11;
            FUN_0036f5f0(0x1a,0,0,param_3);
            break;
          case '\x01':
            *(int *)(iVar10 + 0x198) = (int)*(char *)((int)puVar9 + 0x11);
            *(int *)(iVar10 + 0x19c) = (int)(short)puVar9[9];
            uVar11 = FUN_00386060(param_3);
            *(u32 *)(iVar10 + 0xe8) = uVar11;
            FUN_0036f5f0(0x1a,0,0,param_3);
            break;
          case '\x02':
            *(int *)(iVar10 + 0x16c) = (int)*(char *)((int)puVar9 + 0x11);
            *(u32 *)(iVar10 + 0x170) = 0;
            *(u32 *)(iVar10 + 0x174) = 0x10;
            FUN_0036f5f0(7,0xd,0x11,param_3);
            break;
          case '\x03':
            uVar11 = FUN_00386860(param_3,*(u8 *)((int)puVar9 + 0x11),puVar9[10],
                                  (char)puVar9[9]);
            *(u32 *)(iVar10 + 0xe8) = uVar11;
            FUN_0036f5f0(0x1a,10,0x12,param_3);
            break;
          }

          break;

        case 0x1a:

          if ((*piVar5 == 0x25) && (((char)puVar9[8] == '\0' || ((char)puVar9[8] == '\x01')))) {

            afStack_10[0] = *(f32 *)(puVar9 + 10);

            afStack_10[1] = *(f32 *)(puVar9 + 0xc);

            afStack_10[2] = *(f32 *)(puVar9 + 0xe);

            afStack_20[0] = *(f32 *)(puVar9 + 0x10);

            afStack_20[1] = *(f32 *)(puVar9 + 0x12);
            afStack_20[2] = *(f32 *)(puVar9 + 0x14);

            uVar11 = FUN_00386130(param_3,(u32 *)afStack_10,(u32 *)afStack_20);


            *(u32 *)(iVar10 + 0xe8) = uVar11;

            FUN_0036f5f0(0x1a,0,0,param_3);

          }

          break;

        case 0x1b:

          switch ((char)puVar9[9]) {
          case '\0':
            lVar7 = (int)FUN_003b5d10_evt_main(0x1e59);
            if (lVar7 != 0) {
              FUN_0038a590(param_3,2);
              *(u32 *)(iVar10 + 0x198) = *(u32 *)(puVar9 + 0xc);
              *(u32 *)(iVar10 + 0x19c) = *(u32 *)(puVar9 + 0xe);
              *(u32 *)(iVar10 + 0x1a0) = *(u32 *)(puVar9 + 0x10);
              *(u32 *)(iVar10 + 0x1a4) = *(u32 *)(puVar9 + 0x12);
              *(u32 *)(iVar10 + 0x1a8) = *(u32 *)(puVar9 + 0x14);
              *(u32 *)(iVar10 + 0x1ac) = *(u32 *)(puVar9 + 0x16);
              uVar11 = FUN_00386310(param_3);
              *(u32 *)(iVar10 + 0xe8) = uVar11;
              FUN_0036f5f0(0x1a,0,0,param_3);
            }
            break;
          case '\x01':
            uVar11 = FUN_00386430(param_3,puVar9[10],puVar9[0xb]);
            *(u32 *)(iVar10 + 0xe8) = uVar11;
            FUN_0036f5f0(0x1a,0,0,param_3);
            break;
          }

          break;

        case 0x1c:

          iVar8 = *piVar5;

          if (iVar8 == 0x2e) {

            *(u32 *)(iVar10 + 400) = 0;

            *(int *)(iVar10 + 0x198) = (int)(short)puVar9[8];

            *(int *)(iVar10 + 0x19c) = (int)(short)puVar9[9];

            FUN_0036f5f0(0x27,0xc,0x12,param_3);

          }

          else if (iVar8 == 0x2d) {

            *(u32 *)(iVar10 + 400) = 0;

            *(int *)(iVar10 + 0x198) = (int)(char)puVar9[8];

            *(u32 *)(iVar10 + 0x19c) = (u32)(u8)puVar9[10];

            *(u32 *)(iVar10 + 0x1a0) = (u32)*(u8 *)((int)puVar9 + 0x15);

            *(u32 *)(iVar10 + 0x1a4) = (u32)(u8)puVar9[0xb];

            *(int *)(iVar10 + 0x1a8) = (int)(short)puVar9[0xc];

            *(int *)(iVar10 + 0x1ac) = (int)(short)puVar9[0xd];

            *(int *)(iVar10 + 0x1b0) = (int)(short)puVar9[0xe];

            *(int *)(iVar10 + 0x1b4) = (int)(short)puVar9[0xf];

            FUN_0036f5f0(0x26,0xf,0x10,param_3);

          }

          else if (iVar8 == 0x2c) {

            *(u32 *)(iVar10 + 400) = 0;

            *(int *)(iVar10 + 0x198) = (int)(short)puVar9[8];

            *(int *)(iVar10 + 0x19c) = (int)(short)puVar9[9];

            FUN_0036f5f0(0x24,0xd,0x15,param_3);

          }

          else if (iVar8 == 0x2a) {

            *(u32 *)(iVar10 + 400) = 0;

            *(int *)(iVar10 + 0x198) = (int)(short)puVar9[8];

            *(int *)(iVar10 + 0x19c) = (int)(short)puVar9[9];

            *(int *)(iVar10 + 0x1a0) = (int)(short)puVar9[10];

            *(int *)(iVar10 + 0x1a4) = (int)(short)puVar9[0xb];

            *(int *)(iVar10 + 0x1a8) = (int)(short)puVar9[0xc];

            *(int *)(iVar10 + 0x1ac) = (int)(short)puVar9[0xd];

            FUN_0036f5f0(0x22,0xd,0x15,param_3);

          }

          else if (iVar8 == 0x29) {

            switch((char)puVar9[8]) {

            case '\0':

              *(u32 *)(iVar10 + 400) = 0;

              *(int *)(iVar10 + 0x198) = (int)(short)puVar9[10];

              FUN_0036f5f0(0x21,0xd,0x11,param_3);

              break;

            case '\x02':

              *(u32 *)(iVar10 + 400) = 0;

              *(int *)(iVar10 + 0x198) = (int)(char)puVar9[10];

              *(int *)(iVar10 + 0x19c) = (int)*(char *)((int)puVar9 + 0x15);

              *(int *)(iVar10 + 0x1a0) = (int)(char)puVar9[0xc];

              *(int *)(iVar10 + 0x1a4) = (int)*(char *)((int)puVar9 + 0x19);

              *(int *)(iVar10 + 0x1a8) = (int)(char)puVar9[0xd];

              *(int *)(iVar10 + 0x1ac) = (int)*(char *)((int)puVar9 + 0x1b);

              *(int *)(iVar10 + 0x1b0) = (int)(short)puVar9[0xe];

              FUN_0036f5f0(0x25,0xd,0x15,param_3);

              break;

            case '\x03':

              *(u32 *)(iVar10 + 400) = 0;

              *(int *)(iVar10 + 0x198) = (int)(short)puVar9[10];

              FUN_0036f5f0(0x21,0xd,0x11,param_3);

              break;

            case '\x04':

              *(u32 *)(iVar10 + 400) = 0;

              *(int *)(iVar10 + 0x198) = (int)(short)puVar9[10];

              FUN_0036f5f0(0x21,0xd,0x11,param_3);

              break;

            case '\x05':

              *(u32 *)(iVar10 + 400) = 0;

              *(int *)(iVar10 + 0x198) = (int)(short)puVar9[10];

              FUN_0036f5f0(0x21,0xd,0x11,param_3);

              break;

            case '\x06':

              *(u32 *)(iVar10 + 400) = 0;

              *(int *)(iVar10 + 0x198) = (int)(short)puVar9[10];

              FUN_0036f5f0(0x29,0xd,0x11,param_3);

              break;

            case '\a':

              *(u32 *)(iVar10 + 400) = 0;

              *(int *)(iVar10 + 0x198) = (int)(short)puVar9[10];

              *(int *)(iVar10 + 0x19c) = (int)(short)puVar9[0xb];

              *(int *)(iVar10 + 0x1a0) = (int)(short)puVar9[0xc];

              *(int *)(iVar10 + 0x1a4) = (int)(short)puVar9[0xd];

              *(int *)(iVar10 + 0x1a8) = (int)(short)puVar9[0xe];

              *(int *)(iVar10 + 0x1ac) = (int)(short)puVar9[0xf];

              *(int *)(iVar10 + 0x1b0) = (int)(short)puVar9[0x10];

              *(int *)(iVar10 + 0x1b4) = (int)(char)puVar9[0x12];

              FUN_0036f5f0(0x2b,0xd,0x11,param_3);

              break;

            case '\t':

              *(u32 *)(iVar10 + 400) = 0;

              *(int *)(iVar10 + 0x198) = (int)(char)puVar9[10];

              *(int *)(iVar10 + 0x19c) = (int)(short)puVar9[0xb];

              *(int *)(iVar10 + 0x1a0) = (int)(char)puVar9[0xc];

              FUN_0036f5f0(0x2d,0xd,0x11,param_3);

            }

          }

          else if (iVar8 == 0x1c) {

            if (((char)puVar9[8] != '\x01') && ((char)puVar9[8] == '\0')) {

              uVar11 = FUN_00386680(param_3,puVar9[10],puVar9[0xb],puVar9[0xc],puVar9[0xd]);

              *(u32 *)(iVar10 + 0xe8) = uVar11;

              FUN_0036f5f0(0x1a,0,0,param_3);

            }

          }

          else if (iVar8 == 0x2f) {

            if ((char)puVar9[8] == '\x01') {

              *(u32 *)(iVar10 + 400) = 0;

              *(int *)(iVar10 + 0x198) = (int)(char)puVar9[10];

              *(int *)(iVar10 + 0x19c) = (int)*(char *)((int)puVar9 + 0x15);

              *(int *)(iVar10 + 0x1a0) = (int)(short)puVar9[0xb];

              *(int *)(iVar10 + 0x1a4) = (int)(short)puVar9[0xc];

              *(int *)(iVar10 + 0x1a8) = (int)(short)puVar9[0xd];

              FUN_0036f5f0(0x2a,0xe,0x10,param_3);

            }

            else if ((char)puVar9[8] == '\0') {

              *(int *)(iVar10 + 0x118) = (int)(char)puVar9[10];

              *(u32 *)(iVar10 + 0x11c) = 2;

              *(char **)(iVar10 + 0x120) = s_ON_OFF_MODE_0069db58;

              *(u8 **)(iVar10 + 0x124) = &gp0xffff9dd8;

              FUN_0036f5f0(2,0x12,10,param_3);

            }

          }

          else if (iVar8 == 0x32) {

            *(u32 *)(iVar10 + 400) = 0;

            *(int *)(iVar10 + 0x198) = (int)(char)puVar9[8];

            *(int *)(iVar10 + 0x19c) = (int)*(char *)((int)puVar9 + 0x11);

            *(int *)(iVar10 + 0x1a0) = (int)(char)puVar9[9];

            *(int *)(iVar10 + 0x1a4) = (int)*(char *)((int)puVar9 + 0x13);

            FUN_0036f5f0(0x2f,0xe,0x11,param_3);

          }

          else if (iVar8 == 0x31) {

            if ((char)puVar9[8] == '\0') {

              *(int *)(iVar10 + 0x118) = (int)(char)puVar9[10];

              *(u32 *)(iVar10 + 0x11c) = 2;

              *(char **)(iVar10 + 0x120) = s_ON_OFF_MODE_0069db58;

              *(u8 **)(iVar10 + 0x124) = &gp0xffff9dd8;

              FUN_0036f5f0(2,0x12,10,param_3);

            }

          }

          else if (iVar8 == 0x21) {

            if ((char)puVar9[9] == '\0') {

              *(u32 *)(iVar10 + 400) = 0;

              *(int *)(iVar10 + 0x198) = (int)(char)puVar9[0x18];

              puVar6 = (u32 *)FUN_003b55b0_evt_main(*(u32 *)(iVar10 + 0x198));

              uVar13 = puVar6[1];

              uVar11 = puVar6[2];

              uVar12 = puVar6[3];

              *(u32 *)(iVar10 + 0x84c) = *puVar6;

              *(u32 *)(iVar10 + 0x850) = uVar13;

              *(u32 *)(iVar10 + 0x854) = uVar11;

              *(u32 *)(iVar10 + 0x858) = uVar12;

              FUN_0036f5f0(0x28,10,0x17,param_3);

            }

          }

          else if (iVar8 == 0x27) {

            *(int *)(iVar10 + 0x16c) = (int)(short)puVar9[10];

            *(u32 *)(iVar10 + 0x170) = 0;

            *(u32 *)(iVar10 + 0x174) = 0x7f;

            FUN_0036f5f0(7,0xf,10,param_3);

          }

          else if (iVar8 == 0x28) {

            *(u32 *)(iVar10 + 400) = 0;

            *(int *)(iVar10 + 0x198) = (int)(char)puVar9[8];

            *(int *)(iVar10 + 0x19c) = (int)*(char *)((int)puVar9 + 0x11);

            *(int *)(iVar10 + 0x1a0) = (int)(char)puVar9[9];

            *(int *)(iVar10 + 0x1a4) = (int)*(char *)((int)puVar9 + 0x13);

            *(int *)(iVar10 + 0x1a8) = (int)(short)puVar9[0xc];

            *(int *)(iVar10 + 0x1ac) = (int)(short)puVar9[0xd];

            *(int *)(iVar10 + 0x1b0) = (int)(short)puVar9[0xe];

            *(int *)(iVar10 + 0x1b4) = (int)(short)puVar9[0xf];

            FUN_0036f5f0(0x20,0xd,0x12,param_3);

          }

          break;

        case 0x1d:

          if (*piVar5 == 0x31) {

            *(u32 *)(iVar10 + 0x108) = 0;

            *(u32 *)(iVar10 + 0x110) = 0;

            *(u32 *)(iVar10 + 0x864) = 0;

            *(u32 *)(iVar10 + 0x660) = 0xb;

            FUN_0036f5f0(10,0xd,7,param_3);

          }

          else if (*piVar5 == 0x2f) {

            *(u32 *)(iVar10 + 0x108) = 0;

            *(u32 *)(iVar10 + 0x110) = 0;

            *(u32 *)(iVar10 + 0x860) = 0;

            *(u32 *)(iVar10 + 0x660) = 10;

            FUN_0036f5f0(10,0xd,7,param_3);

          }

        }

      }

    }

    else if (param_1 == 1) {

        FUN_00361350((int *)piVar5,*(u32 *)(iVar10 + 0x18),0);

    }

  }

  return 0;

}


// FUN_0036BE10


u64 FUN_0036be10(u64 param_1,u64 param_2,u32 param_3)



{

  FUN_0036f5f0(5,0xc,3,param_3);

  FUN_005225a8(&DAT_0069dd98);

  return 0;

}


// FUN_0036BE60 NONMATCHING


int FUN_0036be60(u64 param_1,int param_2,int param_3)



{

  u8 bVar1;

  char cVar2;

  short sVar3;

  u32 lVar4;

  int iVar5;

  int iVar6;

  int iVar7;
  u8 *pVar;

  

  bVar1 = 0;

  iVar7 = (int)param_3;
  pVar = (u8 *)param_3;

  switch (param_2) {
  case 1:

    iVar6 = *(int *)(iVar7 + 0x104);

    switch (iVar6) {
    case 3:

      if (*(int *)(iVar7 + 0x118) == 0) {

        iVar6 = *(int *)(pVar + 0x18);

        *(int *)(pVar + 0x10) = iVar6;

        if (*(int *)(pVar + 0x14) < iVar6) {

          *(int *)(pVar + 0x14) = iVar6;

        }

        bVar1 = 1;

      }

      else {

        FUN_0036f640(param_3);

      }

      break;
    case 4:

      if (*(int *)(iVar7 + 0x118) == 0) {

        iVar6 = *(int *)(pVar + 0x18);

        *(int *)(pVar + 0x14) = iVar6;

        if (iVar6 < *(int *)(pVar + 0x10)) {

          *(int *)(pVar + 0x10) = iVar6;

        }

        bVar1 = 1;

      }

      else {

        FUN_0036f640(param_3);

      }

      break;
    case 0xe:

      if (*(int *)(iVar7 + 0x118) == 0) {

        *(char *)(iVar7 + 0x4c) = *(char *)(iVar7 + 0x4c) & -2;

      }

      else {

        *(char *)(iVar7 + 0x4c) = *(char *)(iVar7 + 0x4c) | 1;

      }

      FUN_0036f640(param_3);

      break;
    case 0x10:

      if (*(int *)(iVar7 + 0x118) == 0) {

        *(char *)(iVar7 + 0x4c) = *(char *)(iVar7 + 0x4c) & -5;

      }

      else {

        *(char *)(iVar7 + 0x4c) = *(char *)(iVar7 + 0x4c) | 4;

      }

      FUN_0036f640(param_3);

      break;
    case 0xf:

      if (*(int *)(iVar7 + 0x118) == 0) {

        *(char *)(iVar7 + 0x4c) = *(char *)(iVar7 + 0x4c) & -3;

      }

      else {

        *(char *)(iVar7 + 0x4c) = *(char *)(iVar7 + 0x4c) | 2;

      }

      FUN_0036f640(param_3);

      break;
    case 8:

      if ((*(int *)(iVar7 + 0x118) == 0) && (lVar4 = FUN_003b5d00(), lVar4 != 0)) {

        FUN_003897f0(param_3);

        FUN_00388ff0(param_3);

        FUN_003bb340();

        FUN_00397450();

        FUN_0039eb90();

        FUN_0039e7c0();

        FUN_0036efb0();

        *(u32 *)(iVar7 + 4) = *(u32 *)(iVar7 + 4) | 0x100;

      }

      FUN_0036f640(param_3);

      break;
    }
    break;
  case 0xf:

    lVar4 = FUN_0036fa40_wide(param_3);

    if (lVar4 == 2) {

      *(char *)(*(int *)(iVar7 + 0x164) + 0x22) = (char)*(u32 *)(iVar7 + 0x118);

      FUN_0036f640(param_3);

    }

    break;
  case 5:

    if (*(int *)(iVar7 + 0x164) == 0) {

      iVar6 = 0;

    }

    else {

      iVar5 = 0;

      for (iVar6 = *(int *)(*(int *)(iVar7 + 0x164) + 0x6c);

          (iVar5 < *(int *)(iVar7 + 0x160) + *(int *)(iVar7 + 0x15c) && (iVar6 != 0));

          iVar6 = *(int *)(iVar6 + 0x4c)) {

        iVar5 = iVar5 + 1;

      }

    }

    if (iVar6 == 0) {

      FUN_0019d3f0(0x69d580,0x2804);

    }

    iVar5 = *(int *)(iVar7 + 0x168);

    if (iVar5 == 0xc) {

      iVar5 = **(int **)(iVar7 + 0x164);

      if (iVar5 == 0x1d) {

        *(char *)(iVar6 + 0x14) = (char)*(u32 *)(iVar7 + 0x118);

      }

      else if ((((iVar5 == 0x15) || (iVar5 == 0x14)) || (iVar5 == 0x1a)) || (iVar5 == 3)) {

        *(char *)(iVar6 + 0x18) = (char)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 0x18) {

        *(char *)(iVar6 + 0x24) = (char)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 0x25) {

        if ((long)*(char *)(iVar6 + 0x10) != (long)*(int *)(iVar7 + 0x118)) {

          *(u8 *)(iVar6 + 0x11) = 0;

          *(u8 *)(iVar6 + 0x12) = 0;

          *(u8 *)(iVar6 + 0x13) = 0;

          *(u32 *)(iVar6 + 0x14) = 0;

          *(u32 *)(iVar6 + 0x18) = 0;

          *(u32 *)(iVar6 + 0x1c) = 0;

          *(u32 *)(iVar6 + 0x20) = 0;

          *(u32 *)(iVar6 + 0x24) = 0;

          *(u32 *)(iVar6 + 0x28) = 0;

          iVar5 = *(int *)(iVar7 + 0x118);

          if (iVar5 == 3) {

            *(u8 *)(iVar6 + 0x12) = 0xff;

            *(u16 *)(iVar6 + 0x14) = 0;

          }

          else if (iVar5 == 2) {

            *(u8 *)(iVar6 + 0x11) = 0;

          }

          else if (iVar5 == 1) {

            *(u8 *)(iVar6 + 0x11) = 0;

            *(u16 *)(iVar6 + 0x12) = 0x1e;

            *(u32 *)(iVar6 + 0x14) = 0;

            *(u32 *)(iVar6 + 0x18) = 0;

            *(u32 *)(iVar6 + 0x1c) = 0;

            *(u32 *)(iVar6 + 0x20) = 0;

            *(u32 *)(iVar6 + 0x24) = 0;

            *(u32 *)(iVar6 + 0x28) = 0;

          }

          else if (iVar5 == 0) {

            *(u8 *)(iVar6 + 0x11) = 0;

            *(u8 *)(iVar6 + 0x12) = 0;

            *(u32 *)(iVar6 + 0x14) = 0;

            *(u32 *)(iVar6 + 0x18) = 0;

            *(u32 *)(iVar6 + 0x1c) = 0;

            *(u32 *)(iVar6 + 0x20) = 0;

            *(u32 *)(iVar6 + 0x24) = 0;

            *(u32 *)(iVar6 + 0x28) = 0;

          }

          *(char *)(iVar6 + 0x10) = (char)*(u32 *)(iVar7 + 0x118);

        }

      }

      else if (iVar5 == 0x24) {

        *(char *)(iVar6 + 0x10) = (char)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 0x23) {

        cVar2 = (char)*(u32 *)(iVar7 + 0x118);

        *(char *)(iVar6 + 0x10) = cVar2;

        if ((long)cVar2 != (long)*(int *)(iVar7 + 0x118)) {

          *(u32 *)(iVar6 + 0x14) = 0;

          *(u32 *)(iVar6 + 0x18) = 0;

        }

      }

      else if (iVar5 == 0x21) {

        if ((long)*(char *)(iVar6 + 0x12) != (long)*(int *)(iVar7 + 0x118)) {

          *(u16 *)(iVar6 + 0x10) = 0x1e;

          *(u32 *)(iVar6 + 0x2c) = 0;

          *(u32 *)(iVar6 + 0x30) = 0;

          if (*(int *)(iVar7 + 0x118) == 1) {

            *(u32 *)(iVar6 + 0x14) = 0;

            *(u16 *)(iVar6 + 0x16) = 900;

            *(u32 *)(iVar6 + 0x18) = 0;

            *(u32 *)(iVar6 + 0x1c) = 0;

            *(u32 *)(iVar6 + 0x20) = 0;

            *(u32 *)(iVar6 + 0x24) = 0;

            *(u32 *)(iVar6 + 0x28) = 0;

          }

          else if (*(int *)(iVar7 + 0x118) == 0) {

            *(u32 *)(iVar6 + 0x14) = 0;

            *(u32 *)(iVar6 + 0x18) = 0;

            *(u32 *)(iVar6 + 0x1c) = 0x44200000;

            *(u32 *)(iVar6 + 0x20) = 0xc4430000;

            *(u32 *)(iVar6 + 0x24) = 0x42000000;

            *(u32 *)(iVar6 + 0x28) = 0;

          }

          *(char *)(iVar6 + 0x12) = (char)*(u32 *)(iVar7 + 0x118);

        }

      }

      else if ((iVar5 == 0x30) || (iVar5 == 1)) {

        if ((long)*(char *)(iVar6 + 0x10) != (long)*(int *)(iVar7 + 0x118)) {

          *(u32 *)(iVar6 + 0x14) = 0;

          *(u32 *)(iVar6 + 0x18) = 0;

          *(u32 *)(iVar6 + 0x1c) = 0;

          *(u32 *)(iVar6 + 0x20) = 0;

          *(u32 *)(iVar6 + 0x24) = 0;

          *(u32 *)(iVar6 + 0x28) = 0;

          *(u32 *)(iVar6 + 0x2c) = 0;

          switch(*(u32 *)(iVar7 + 0x118)) {

          case 0:

            *(u32 *)(iVar6 + 0x14) = 0;

            *(u32 *)(iVar6 + 0x18) = 0;

            *(u32 *)(iVar6 + 0x1c) = 0;

            break;

          case 1:

            *(u8 *)(iVar6 + 0x14) = 0;

            *(u8 *)(iVar6 + 0x15) = 0;

            *(u16 *)(iVar6 + 0x16) = 5;

            *(u32 *)(iVar6 + 0x18) = 0;

            *(u32 *)(iVar6 + 0x1c) = 0;

            *(u32 *)(iVar6 + 0x20) = 0;

            *(u32 *)(iVar6 + 0x24) = 0;

            *(u32 *)(iVar6 + 0x28) = 0;

            *(u32 *)(iVar6 + 0x2c) = 0;

            *(u8 *)(iVar6 + 0x34) = 0;

            *(u8 *)(iVar6 + 0x35) = 0;

            *(u8 *)(iVar6 + 0x36) = 0xd;

            *(u8 *)(iVar6 + 0x37) = 6;

            break;

          case 2:

            *(u8 *)(iVar6 + 0x14) = 0;

            *(u8 *)(iVar6 + 0x15) = 0;

            *(u8 *)(iVar6 + 0x16) = 0;

            *(u8 *)(iVar6 + 0x17) = 0;

            *(u32 *)(iVar6 + 0x18) = 0;

            *(u32 *)(iVar6 + 0x1c) = 0;

            *(u32 *)(iVar6 + 0x20) = 0;

            *(u16 *)(iVar6 + 0x28) = 100;

            *(u16 *)(iVar6 + 0x2a) = 100;

            break;

          case 3:

            *(u8 *)(iVar6 + 0x14) = 1;

            *(u8 *)(iVar6 + 0x15) = 5;

            *(u16 *)(iVar6 + 0x16) = 0;

            *(u32 *)(iVar6 + 0x18) = 0;

            *(u32 *)(iVar6 + 0x1c) = 0;

            break;

          case 4:

            *(u32 *)(iVar6 + 0x14) = 0;

            *(u32 *)(iVar6 + 0x18) = 0;

            *(u32 *)(iVar6 + 0x1c) = 0;

            *(u32 *)(iVar6 + 0x20) = 0;

            *(u16 *)(iVar6 + 0x24) = 0x14;

            *(u8 *)(iVar6 + 0x28) = 0;

            *(u8 *)(iVar6 + 0x29) = 0;

            *(u8 *)(iVar6 + 0x2a) = 0xd;

            *(u8 *)(iVar6 + 0x2b) = 6;

            break;

          case 5:

            *(u32 *)(iVar6 + 0x14) = 0;

            *(u32 *)(iVar6 + 0x18) = 0;

            *(u32 *)(iVar6 + 0x1c) = 0;

            *(u32 *)(iVar6 + 0x20) = 0;

            break;

          case 6:

            *(u32 *)(iVar6 + 0x14) = 0;

            *(u32 *)(iVar6 + 0x18) = 0;

            *(u32 *)(iVar6 + 0x1c) = 0;

            *(u32 *)(iVar6 + 0x20) = 0;

            *(u32 *)(iVar6 + 0x24) = 0;

            break;

          case 7:

            *(u32 *)(iVar6 + 0x14) = 0;

            *(u32 *)(iVar6 + 0x18) = 0;

            *(u32 *)(iVar6 + 0x1c) = 0;

            break;

          case 8:

            *(u16 *)(iVar6 + 0x14) = 0;

            *(u8 *)(iVar6 + 0x18) = 0xff;

            *(u8 *)(iVar6 + 0x18) = 0;

            break;

          default:

            *(u32 *)(iVar6 + 0x14) = 0;

            *(u32 *)(iVar6 + 0x18) = 0;

            *(u32 *)(iVar6 + 0x1c) = 0;

            break;

          case 10:

            *(u16 *)(iVar6 + 0x14) = 0;

            *(u32 *)(iVar6 + 0x18) = 0x3f800000;

          }

        }

        *(char *)(iVar6 + 0x10) = (char)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 0x2f) {

        if ((long)*(char *)(iVar6 + 0x10) != (long)*(int *)(iVar7 + 0x118)) {

          *(u32 *)(iVar6 + 0x14) = 0;

          *(u32 *)(iVar6 + 0x18) = 0;

          if (*(int *)(iVar7 + 0x118) == 1) {

            *(u8 *)(iVar6 + 0x15) = 1;

            *(u16 *)(iVar6 + 0x1a) = 100;

          }

        }

        *(char *)(iVar6 + 0x10) = (char)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 0x2b) {

        *(char *)(iVar6 + 0x10) = (char)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 0x29) {

        *(char *)(iVar6 + 0x10) = (char)*(u32 *)(iVar7 + 0x118);

        *(u32 *)(iVar6 + 0x14) = 0;

        *(u32 *)(iVar6 + 0x18) = 0;

        *(u32 *)(iVar6 + 0x1c) = 0;

        *(u32 *)(iVar6 + 0x20) = 0;

        *(u32 *)(iVar6 + 0x24) = 0;

      }

      else if (iVar5 == 0x27) {

        *(char *)(iVar6 + 0x10) = (char)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 4) {

        *(char *)(iVar6 + 0x14) = (char)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 0x20) {

        *(short *)(iVar6 + 0x10) = (short)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 0x1f) {

        *(short *)(iVar6 + 0x10) = (short)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 0x1e) {

        *(short *)(iVar6 + 0x12) = (short)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 10) {

        *(short *)(iVar6 + 0x1c) = (short)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 0x22) {

        *(char *)(iVar6 + 0x10) = (char)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 0x31) {

        *(char *)(iVar6 + 0x10) = (char)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 0x1c) {

        if ((long)*(char *)(iVar6 + 0x10) != (long)*(int *)(iVar7 + 0x118)) {

          *(u32 *)(iVar6 + 0x14) = 0;

          *(u32 *)(iVar6 + 0x18) = 0;

        }

        *(char *)(iVar6 + 0x10) = (char)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 0x13) {

        *(short *)(iVar6 + 0x10) = (short)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 5) {

        cVar2 = (char)*(u16 *)(iVar7 + 0x118);

        *(char *)(iVar6 + 0x12) = cVar2;

        if ((cVar2 == '\x03') || (cVar2 == '\x01')) {

          *(u16 *)(iVar6 + 0x10) = 10;

        }

        else if ((cVar2 == '\x02') || (cVar2 == '\0')) {

          *(u16 *)(iVar6 + 0x10) = 0;

        }

        else {

          FUN_0019d3f0(0x69d580,0x2881);

        }

      }

      else if (iVar5 == 6) {

        sVar3 = (short)*(u32 *)(iVar7 + 0x118);

        *(short *)(iVar6 + 0x10) = sVar3;

        if (sVar3 == 0) {

          *(u16 *)(iVar6 + 0x12) = 0xffff;

        }

        else {

          *(u16 *)(iVar6 + 0x12) = 0;

        }

      }

      else if (iVar5 == 0xc) {

        *(short *)(iVar6 + 0x10) = (short)*(u32 *)(iVar7 + 0x118);

        *(u32 *)(iVar7 + 0xe4) = 0;

      }

    }

    else if (iVar5 == 0x1c) {

      if (**(int **)(iVar7 + 0x164) == 0x31) {

        *(char *)(iVar6 + 0x14) = (char)*(u32 *)(iVar7 + 0x118);

      }

      else if (**(int **)(iVar7 + 0x164) == 0x2f) {

        if (*(char *)(iVar6 + 0x10) == '\0') {

          *(char *)(iVar6 + 0x14) = (char)*(u32 *)(iVar7 + 0x118);

        }

        else if (*(char *)(iVar6 + 0x10) == '\x01') {

          *(char *)(iVar6 + 0x14) = (char)*(u32 *)(iVar7 + 0x118);

        }

      }

    }

    else if (iVar5 == 0x13) {

      if (*(char *)(iVar6 + 0x10) == '\t') {

        *(char *)(iVar6 + 0x14) = (char)*(u32 *)(iVar7 + 0x118);

      }

      else if (*(char *)(iVar6 + 0x10) == '\0') {

        *(char *)(iVar6 + 0x14) = (char)*(u32 *)(iVar7 + 0x118);

      }

    }

    else if (iVar5 == 0x17) {

      if ((*(char *)(iVar6 + 0x10) == '\x03') || (*(char *)(iVar6 + 0x10) == '\x02')) {

        *(char *)(iVar6 + 0x14) = (char)*(u32 *)(iVar7 + 0x118);

      }

    }

    else if (iVar5 == 0x10) {

      iVar5 = **(int **)(iVar7 + 0x164);

      if ((iVar5 == 0x1a) || (iVar5 == 3)) {

        *(char *)(iVar6 + 0x14) = (char)*(u32 *)(iVar7 + 0x118);

      }

      else if ((iVar5 == 0x15) || (iVar5 == 0x14)) {

        *(char *)(iVar6 + 0x11) = (char)*(u32 *)(iVar7 + 0x118);

      }

    }

    else if (iVar5 == 0xb) {

      iVar5 = **(int **)(iVar7 + 0x164);

      if (iVar5 == 0x19) {

        *(short *)(iVar6 + 0x10) = (short)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 0x16) {

        *(short *)(iVar6 + 0x10) = (short)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 9) {

        *(short *)(iVar6 + 0x12) = (short)*(u32 *)(iVar7 + 0x118);

      }

    }

    else if (iVar5 == 5) {

      iVar5 = **(int **)(iVar7 + 0x164);

      if (iVar5 == 0x19) {

        *(short *)(iVar6 + 0x14) = (short)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 0x18) {

        *(char *)(iVar6 + 0x10) = (char)*(u32 *)(iVar7 + 0x118);

      }

      else if ((((iVar5 == 0x1b) || (iVar5 == 0x17)) || (iVar5 == 0xf)) ||

              (((iVar5 == 0x11 || (iVar5 == 0x10)) ||

               ((iVar5 == 0xe || ((iVar5 == 0xd || (iVar5 == 0xb)))))))) {

        *(short *)(iVar6 + 0x10) = (short)*(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 10) {

        *(u32 *)(iVar6 + 4) = *(u32 *)(iVar7 + 0x118);

      }

      else if (iVar5 == 8) {

        *(short *)(iVar6 + 0x14) = (short)*(u32 *)(iVar7 + 0x118);

      }

    }

    else if (iVar5 == -1) {

      if (*(int *)(iVar7 + 0x118) == 0) {

        FUN_00361980(param_3);

      }

      else if (*(int *)(iVar7 + 0x118) == 2) {

        if (*(int *)(iVar7 + 0x164) == 0) {

          FUN_0019d3f0(0x69d580,0x44c);

        }

        while (lVar4 = FUN_00361830(param_3), lVar4 != 0) {

          FUN_00361980(param_3);

        }

      }

    }

    else {

      FUN_0019d3f0(0x69d580,0x29c5);

    }


    break;

  }
  FUN_0036f640(param_3);
  return -(u32)bVar1;

}


// FUN_0036CC30


u64 FUN_0036cc30(u64 param_1,u64 param_2,u8 *param_3)



{

  u32 uVar1;

  u32 lVar2;
  u32 flag;
  u32 menuFlag;

  u8 *iVar3;

  int iStack_4;

  

  iVar3 = param_3;

  switch(*(u32 *)(iVar3 + 0x104)) {

  case 0:

  case 1:

  case 2:

    *(u32 *)(iVar3 + 0x128) = 0;

    *(u32 *)(iVar3 + 300) = 0;

    FUN_0036f5f0(9,0x13,5,(int)param_3);

    break;

  case 5:

    *(int *)(iVar3 + 0x16c) = *(int *)(iVar3 + 0xc) + -1;

    *(u32 *)(iVar3 + 0x170) = *(u32 *)(iVar3 + 0x14);

    *(u32 *)(iVar3 + 0x174) = 10000;

    FUN_0036f5f0(7,0xf,10,(int)param_3);

    break;

  case 3:

  case 4:

    *(u32 *)(iVar3 + 0x118) = 0;

    *(u32 *)(iVar3 + 0x11c) = 2;

    *(char **)(iVar3 + 0x120) = (char *)s_FRAME_SET_OK_abs;

    *(u8 ***)(iVar3 + 0x124) = &PTR_DAT_007ccc50;

    FUN_0036f5f0(2,0x13,5,(int)param_3);

    break;

  case 6:

    *(u32 *)(iVar3 + 0x16c) = 0;

    *(u32 *)(iVar3 + 0x170) = 0xffffec78;

    *(u32 *)(iVar3 + 0x174) = 5000;

    FUN_0036f5f0(7,0xf,10,(int)param_3);

    break;

  case 7:

    *(u32 *)(iVar3 + 0x16c) = 2;

    *(u32 *)(iVar3 + 0x198) = *(u32 *)(iVar3 + 0x3c);

    *(u32 *)(iVar3 + 0x19c) = *(u32 *)(iVar3 + 0x40);

    *(u32 *)(iVar3 + 0x1a0) = (u32)*(u8 *)(iVar3 + 0x46);

    *(int *)(iVar3 + 0x1a4) = (int)*(short *)(iVar3 + 0x48);

    uVar1 = FUN_00385e20((int)param_3);

    *(u32 *)(iVar3 + 0xe8) = uVar1;

    FUN_0036f5f0(0x1a,0xf,10,(int)param_3);

    break;

  case 8:

    *(u32 *)(iVar3 + 0x118) = 0;

    *(u32 *)(iVar3 + 0x11c) = 2;

    *(char **)(iVar3 + 0x120) = (char *)s_FIELD_EDIT_GO_abs;

    *(u8 ***)(iVar3 + 0x124) = &PTR_DAT_007ccc50;

    FUN_0036f5f0(2,0x13,5,(int)param_3);

    break;

  case 9:

    *(u32 *)(iVar3 + 0x16c) = 3;

    uVar1 = FUN_00385f00((int)param_3);

    *(u32 *)(iVar3 + 0xe8) = uVar1;

    FUN_0036f5f0(0x1a,0xf,10,(int)param_3);

    break;

  case 10:

    uVar1 = FUN_003865f0((int)param_3);

    *(u32 *)(iVar3 + 0xe8) = uVar1;

    FUN_0036f5f0(0x1a,0xf,10,(int)param_3);

    break;

  case 0xb:

    lVar2 = FUN_00397520(param_3,&iStack_4);

    if (lVar2 == 1) {

      *(u32 *)(iVar3 + 0x170) = 0;

      uVar1 = FUN_00397500(param_3);

      *(u32 *)(iVar3 + 0x16c) = uVar1;

      *(int *)(iVar3 + 0x174) = iStack_4 + -1;

      FUN_0036f5f0(7,0xf,10,(int)param_3);

    }

    break;

  case 0xc:

    FUN_0036f5f0(0x2c,0xc,0x12,(int)param_3);

    break;

  case 0xd:

    flag = 0;
    if (*(u16 *)(iVar3 + 0x4a) != 0) {
      flag = 1;
    }
    uVar1 = FUN_00386a00((int)param_3,flag);

    *(u32 *)(iVar3 + 0xe8) = uVar1;

    FUN_0036f5f0(0x1a,0xf,10,(int)param_3);

    break;

  case 0xe:

    menuFlag = 0;
    if ((*(s8 *)(iVar3 + 0x4c) & 1) != 0) {
      menuFlag = 1;
    }
    *(u32 *)(iVar3 + 0x118) = menuFlag;

    *(u32 *)(iVar3 + 0x11c) = 2;

    *(char **)(iVar3 + 0x120) = (char *)s_VOICE_FILE_LOAD_abs;

    *(u8 ***)(iVar3 + 0x124) = &PTR_DAT_007ccc58;

    FUN_0036f5f0(2,0x13,5,(int)param_3);

    break;

  case 0x10:

    menuFlag = 0;
    if ((*(s8 *)(iVar3 + 0x4c) & 4) != 0) {
      menuFlag = 1;
    }
    *(u32 *)(iVar3 + 0x118) = menuFlag;

    *(u32 *)(iVar3 + 0x11c) = 2;

    *(char **)(iVar3 + 0x120) = (char *)s_BATTLE_BLUR_USE_abs;

    *(u8 ***)(iVar3 + 0x124) = &PTR_DAT_007ccc58;

    FUN_0036f5f0(2,0x13,5,(int)param_3);

    break;

  case 0xf:

    menuFlag = 0;
    if ((*(s8 *)(iVar3 + 0x4c) & 2) != 0) {
      menuFlag = 1;
    }
    *(u32 *)(iVar3 + 0x118) = menuFlag;

    *(u32 *)(iVar3 + 0x11c) = 2;

    *(char **)(iVar3 + 0x120) = (char *)s_MESSAGE_TYPE_abs;

    *(u8 ***)(iVar3 + 0x124) = &PTR_s_NORMAL_007ccc60;

    FUN_0036f5f0(2,0x13,5,(int)param_3);

    break;

  default:

    FUN_0019d3f0((int)DAT_0069d580,0x2aae);

  }

  return 0;

}


/* W367 pragma probe: opt_common_subs off nd 72 -> 61; on nd 72; object 744/752. */
/* W418 negative: typed FUN_00195460(u32) routing in FUN_0036d030 and FUN_0036db20 produced no metric changes; reverted. */
#pragma opt_common_subs off
// FUN_0036D030 NONMATCHING


void FUN_0036d030(int param_1)



{

  u32 uVar1;

  int lVar2;

  int iVar3;

  int iVar4;

  

  if (param_1 != 0) {

    iVar4 = (int)param_1;

    if (((*(u32 *)(iVar4 + 4) & 0x20) != 0) && (lVar2 = FUN_0039f6e0(iVar4 + 0x82c), lVar2 == 1)) {

      *(u32 *)(iVar4 + 4) = *(u32 *)(iVar4 + 4) & 0xffffffdf;

    }

    if (((*(u32 *)(iVar4 + 4) & 0x8000) != 0) && ((*(s8 *)(iVar4 + 0x4c) & 8) != 0)) {

      lVar2 = FUN_003c7850();

      if (lVar2 == 0) {

        FUN_003c7700();

        *(u32 *)(iVar4 + 4) = *(u32 *)(iVar4 + 4) & 0xffff7fff;

      }

      FUN_003c7b90();

    }

    if (((*(u32 *)(iVar4 + 4) & 0x200) != 0) && (lVar2 = FUN_00396ed0(0), lVar2 != 1)) {

      *(u32 *)(iVar4 + 4) = *(u32 *)(iVar4 + 4) & 0xfffffdff;

    }

    if (((*(u32 *)(iVar4 + 4) & 0x400) != 0) && (lVar2 = FUN_00396ed0(1), lVar2 != 1)) {

      *(u32 *)(iVar4 + 4) = *(u32 *)(iVar4 + 4) & 0xfffffbff;

    }

    if (((*(u32 *)(iVar4 + 4) & 0x800) != 0) && (lVar2 = FUN_00396ed0(2), lVar2 != 1)) {

      *(u32 *)(iVar4 + 4) = *(u32 *)(iVar4 + 4) & 0xfffff7ff;

    }

    if (((*(u32 *)(iVar4 + 4) & 0x1000) != 0) && (lVar2 = FUN_003cf630(), lVar2 == 0)) {

      *(u32 *)(iVar4 + 4) = *(u32 *)(iVar4 + 4) & 0xffffefff;

    }

    if (((*(u32 *)(iVar4 + 4) & 0x2000) != 0) && (lVar2 = FUN_00108710(), lVar2 == 1)) {

      *(u32 *)(iVar4 + 4) = *(u32 *)(iVar4 + 4) & 0xffffdfff;

    }

    if (((*(u32 *)(iVar4 + 4) & 0x4000) != 0) &&

       (lVar2 = FUN_00195460(*(u32 *)(iVar4 + 0x924)), lVar2 == 0)) {

      *(u32 *)(iVar4 + 4) = *(u32 *)(iVar4 + 4) & 0xffffbfff;

      *(u32 *)(iVar4 + 0x924) = 0;

    }

    uVar1 = *(u32 *)(iVar4 + 4);

    if (((((((uVar1 & 1) == 0) && ((uVar1 & 0x20) == 0)) && ((uVar1 & 0x200) == 0)) &&

         (((uVar1 & 0x400) == 0 && ((uVar1 & 0x800) == 0)))) &&

        (((uVar1 & 0x1000) == 0 && (((uVar1 & 0x20000) == 0 && ((uVar1 & 0x2000) == 0)))))) &&

       (((uVar1 & 0x4000) == 0 && ((uVar1 & 0x8000) == 0)))) {

      iVar3 = 0;

    }

    else {

      iVar3 = 1;

    }

    if (*(int *)(iVar4 + 0x77c) != iVar3) {

      *(int *)(iVar4 + 0x77c) = iVar3;

      if (iVar3 != 1) {

        FUN_00362120(1,*(u32 *)(iVar4 + 0x18),param_1);

      }

      else {

        FUN_00362120(0,*(u32 *)(iVar4 + 0x18),param_1);

      }

      FUN_005225a8(DAT_0069de20);

    }

  }

  return;

}


#pragma opt_common_subs reset
// FUN_0036D320


bool FUN_0036d320(int param_1)
{
  int iVar1;
  bool bVar2;

  iVar1 = *(int *)(param_1 + 0xd4);
  if (iVar1 == 0x1a) {
    iVar1 = *(int *)(param_1 + 0x16c);
    switch (iVar1) {
    case 4:
    case 0:
    case 1:
    case 6:
    case 8:
    case 9:
    case 10:
    case 0xc:
    case 0xd:
      return false;
    default:
      return true;
    }
  }
  else if (iVar1 == 0x17) {
    bVar2 = false;
  }
  else if (iVar1 == 0x19) {
    bVar2 = false;
  }
  else if (iVar1 == 0x18) {
    bVar2 = false;
  }
  else if (iVar1 == 0x13) {
    bVar2 = false;
  }
  else if (iVar1 == 0x1c) {
    bVar2 = false;
  }
  else if (iVar1 == 10) {
    bVar2 = false;
  }
  else if (iVar1 == 0x28) {
    bVar2 = false;
  }
  else {
    bVar2 = iVar1 != 0x2e;
  }
  return bVar2;
}


// FUN_0036D470


u32 FUN_0036d470(int param_1)
{
  int *piVar1;
  int iVar2;
  u32 uVar3;

  uVar3 = 0;
  if (param_1 == 0) {
    return uVar3;
  }
  piVar1 = *(int **)((int)param_1 + 0x164);
  if (piVar1 == (int *)0x0) {
    return uVar3;
  }
  iVar2 = *piVar1;
  if (*(int *)((int)param_1 + 0xd4) == 5) {
    if ((iVar2 == 3) || (iVar2 == 0x1a) || (iVar2 == 0x11)) {
      return uVar3;
    }
    if (iVar2 == 0x21) {
      uVar3 = 0xfffffffa;
    }
  }
  return uVar3;
}


// FUN_0036D500


code * FUN_0036d500(void)



{

  int iVar1;

  u32 uVar2;

  u32 lVar3;

  u32 uVar4;

  u32 uVar5;
  int iVar6;

  

  uVar2 = FUN_0035ae10();

  iVar1 = (int)uVar2;

  lVar3 = FUN_00195460(*(u32 *)(iVar1 + 0x930));

  if (lVar3 == 0) {
    iVar6 = DAT_007ce5e4;
    if (iVar6 >= 5) {

      uVar4 = FUN_00386e10(uVar2);

      uVar5 = FUN_00386e30(uVar2);

      FUN_00393e30(uVar2,uVar4,uVar5,0,0,FUN_0036e690);

      *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) & 0xfffffeff;

      FUN_0038a0c0(uVar2,FUN_0038a0b0(uVar2));

      DAT_007ce5e4 = 0;

      return (code *)FUN_0036e690;

    }

    DAT_007ce5e4 = iVar6 + 1;

  }

  else {

    DAT_007ce5e4 = 0;

  }

  return (code *)0x0;

}


/* W415: moving FUN_0036f5f0 before the conditional FUN_0035adb0 restored
   the retail adjacent call order and reduced nd 633 -> 630 (object 1024/1056). */
// FUN_0036D5F0 NONMATCHING


code * FUN_0036d5f0(void)



{

  bool bVar1;

  bool bVar2;

  short sVar3;

  u32 uVar4;

  code *pcVar5;

  u32 uVar6;

  int lVar7;

  int iVar8;

  short *psVar9;

  int iVar10;

  short sVar11;

  int iVar12;

  int lVar13;

  int iVar14;

  int iVar15;

  

  bVar2 = false;

  lVar13 = 0;

  uVar6 = FUN_0035ae10();

  FUN_00385b20(uVar6);

  FUN_00362ff0(uVar6);

  FUN_00395910(uVar6);

  iVar10 = (int)uVar6;

  if ((*(u32 *)(iVar10 + 4) & 0x100) != 0) {

    uVar4 = FUN_001e2370(*(u32 *)(iVar10 + 0x92c));

    *(u32 *)(iVar10 + 0x930) = uVar4;

    pcVar5 = (code *)FUN_0036d500;

  }

  else {

    *(u16 *)(iVar10 + 0x22) = 3;

    sVar11 = 0;

    for (iVar12 = 1; bVar1 = bVar2, iVar12 <= *(int *)(iVar10 + 0xd0); iVar12 = iVar12 + 1) {

      sVar3 = FUN_0036d470(uVar6);

      *(short *)(iVar10 + 0x20) = sVar3;

      iVar8 = iVar10 + iVar12 * 8;

      iVar14 = (int)*(short *)(iVar8 + 0x92) + (int)sVar3;

      iVar15 = (int)*(short *)(iVar8 + 0x94) + (int)*(short *)(iVar10 + 0x22);

      psVar9 = (short *)(iVar8 + 0x90);

      if (0x2f < *(short *)(iVar8 + 0x90)) {

        FUN_0019d3f0(0x69d580,0x2c2d);

      }

      lVar7 = FUN_0036d320(uVar6);

      if (lVar7 != 0) {

        lVar13 = FUN_00385860(*psVar9,iVar12,iVar14,iVar15,uVar6);

      }

      else {

        if ((long)*(int *)(iVar10 + 0xd4) == (long)*psVar9) {

          lVar13 = FUN_00385860((long)*psVar9,iVar12,iVar14,iVar15,uVar6);

        }

      }

      lVar7 = (long)*psVar9;

      if ((*(int *)(iVar10 + 0xd4) == lVar7) && (lVar7 != 0xf)) {

        if (lVar7 == 5) {

          FUN_00385860(0xf,iVar12,*(short *)(iVar10 + 0x20) + 0xc,*(short *)(iVar10 + 0x22) + 0x1c,

                       uVar6);

        }

        else if (lVar7 == 4) {

          FUN_00385860(5,iVar12,*(short *)(iVar10 + 0x20) + 0xc,*(short *)(iVar10 + 0x22) + 3,uVar6)

          ;

          FUN_00385860(0xf,iVar12,*(short *)(iVar10 + 0x20) + 0xc,*(short *)(iVar10 + 0x22) + 0x1c,

                       uVar6);

        }

      }

      if (lVar13 != 0) {

        if (lVar13 != 2) {

          if (lVar13 == -1) {

            FUN_0036f640(uVar6);

          }

          else if ((*(code **)(&DAT_0069de40 + *psVar9 * 4) != (code *)0x0) &&

                  (lVar13 = (*(code *)(&DAT_0069de40 + *psVar9 * 4))(lVar13,sVar11,uVar6),

                  lVar13 != 0)) {

            bVar1 = true;

            if (lVar13 == 1) {

              return (code *)0x0;

            }

            if (lVar13 != -1) {

              bVar1 = bVar2;

            }

          }

        }

        break;

      }

      sVar11 = *psVar9;

    }

    if ((DAT_007e094e & 0x10) != 0) {

      if (*(int *)(iVar10 + 0xdc) == 1) {

        if (*(int *)(iVar10 + 0xd0) == 1) {

          if (*(int *)(iVar10 + 0xe8) != 0) {

            FUN_0035adb0();

            *(u32 *)(iVar10 + 0xe8) = 0;

          }

          *(u32 *)(iVar10 + 0xdc) = 0;

          bVar1 = true;

        }

      }

      else if (*(int *)(iVar10 + 0xdc) == 0) {

        *(u32 *)(iVar10 + 0xd4) = 0;

        *(u32 *)(iVar10 + 0xd0) = 0;

        *(int *)(iVar10 + 0xdc) = *(int *)(iVar10 + 0xdc) + 1;

        *(u32 *)(iVar10 + 0x780) = 0;

        FUN_0036f5f0(4,1,3,uVar6);

        if (*(int *)(iVar10 + 0xe8) != 0) {

          FUN_0035adb0();

          *(u32 *)(iVar10 + 0xe8) = 0;

        }

      }

    }

    if (*(int *)(iVar10 + 0xd4) == 0) {

      bVar1 = true;

    }

    if (bVar1) {

      *(u32 *)(iVar10 + 0xd4) = 0;

      *(u32 *)(iVar10 + 0xd0) = 0;

      *(u32 *)(iVar10 + 0xdc) = 0;

      FUN_0038a730(uVar6);

      *(u32 *)(iVar10 + 0x1c) = 0xffffffff;

      FUN_005225a8(0x69df00);

      pcVar5 = (code *)FUN_0036e690;

    }

    else {

      pcVar5 = (code *)0x0;

    }

  }

  return pcVar5;

}


// b210 floor after an informed type attempt regressed and was reverted: all 22
// remaining words are cyclic saved-register coloring (ours s1/s0/s3/s2 versus
// retail s3/s2/s1/s0), including the dependent moves/sign extensions/branches.
// FUN_0036DA10 NONMATCHING


u32 FUN_0036da10(int param_1)



{


  int iVar4;
  int iVar5;


  short uVar1;
  short sVar2;

  int iVar3;


  u32 lVar7;

  

  iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x94);

  iVar4 = *(int *)(iVar3 + 0x10);

  iVar5 = *(int *)(iVar3 + 0x14);

  uVar1 = *(u8 *)(iVar3 + 0x1a);

  sVar2 = *(short *)(iVar3 + 0x1c);

  if ((iVar4 == 0) && (iVar5 == 0)) {
    return 0;
  }
  if ((*(u32 *)(param_1 + 4) & 8) != 0) {
    return 1;
  }
  lVar7 = FUN_003b5620(iVar4,iVar5);
  if (lVar7 == 0) {
    return 0;
  }
  FUN_003b5760(iVar4,iVar5);
  FUN_003b58c0(uVar1);
  if (sVar2 != 0) {
    FUN_003b5980(sVar2);
  }
  FUN_005225a8((const char *)(DAT_006a0000 - 0x20e0),iVar4,iVar5);
  return 1;


}


/* W415 negative: inserting the retail FUN_0019d3f0(..., 0x2d61) after
   FUN_003942f0 raised nd 927 -> 984 and object 1564 -> 1584, over the 1568-byte window. */
/* W367 pragma probe: opt_common_subs off nd 977 -> 927; on nd 977; object 1564/1568. */
#pragma opt_common_subs off
// FUN_0036DB20 NONMATCHING


u32 FUN_0036db20(int param_1)



{

  int iVar1;

  u32 uVar2;

  int iVar3;

  u32 uVar5;
  u32 uVar4;

  u32 uVar6;

  u32 lVar7;

  int iVar8;
  u32 *state;

  int iStack_4;

  

  iVar1 = *(int *)(param_1 + 0x3c);
  state = (u32 *)(iVar1 + 0x960);

  switch(*state) {

  case 0:

    FUN_0036f000(iVar1);

    FUN_00361070(iVar1);

    *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 1;

    *state = 1;

    *(f32 *)(iVar1 + 0x8d0) = FUN_001a4600(FUN_00198590());

  case 1:

    if (*(int *)(iVar1 + 0x934) == 0) {

      uVar4 = FUN_00386e10(iVar1);

      uVar5 = FUN_00386e30(iVar1);

      uVar6 = FUN_00397500(iVar1);

      uVar2 = FUN_00397f80(uVar4,uVar5,uVar6,*(u32 *)(iVar1 + 0x964));

      *(u32 *)(iVar1 + 0x934) = uVar2;

    }

    uVar4 = FUN_00386e10(iVar1);

    uVar5 = FUN_00386e30(iVar1);

    FUN_005225a8((const char *)(DAT_006a0000 - 0x20b0),uVar4,uVar5);

    *state = 2;

switchD_0036db68_caseD_2:

    lVar7 = FUN_00398060(*(u32 *)(iVar1 + 0x934));

    if (lVar7 != 0) {

      *state = 3;

switchD_0036db68_caseD_3:

      iVar3 = FUN_003980e0(*(u32 *)(iVar1 + 0x934));

      lVar7 = FUN_00394270();

      FUN_003942f0(iVar1 + 0x82c,lVar7,*(u32 *)(iVar3 + 0x34),*(u32 *)(iVar3 + 0x38),

                   *(u32 *)(iVar3 + 0x3c));


      iVar8 = (int)lVar7;

      *(u32 *)(iVar8 + 8) = *(u32 *)(iVar3 + 0x28);

      *(u32 *)(iVar8 + 0x70) = *(u32 *)(iVar3 + 0x2c);

      *(u32 *)(iVar8 + 0x7c) = *(u32 *)(iVar3 + 0x30);

      *(u32 *)(iVar8 + 0x114) = *(u32 *)(iVar3 + 0x1c);

      *(u32 *)(iVar8 + 0x118) = *(u32 *)(iVar3 + 0x20);

      *(u32 *)(iVar8 + 0x11c) = *(u32 *)(iVar3 + 0x24);

      *(u32 *)(iVar8 + 0x120) = *(u32 *)(iVar3 + 0xc);

      *(u32 *)(iVar8 + 0x124) = *(u32 *)(iVar3 + 0x10);

      *(int *)(iVar1 + 8) = iVar8;

      *state = 4;

      FUN_005225a8(0x69df70);

switchD_0036db68_caseD_4:

      lVar7 = FUN_0036da10(iVar1);

      if (lVar7 == 0) {

        *state = 6;

      }

      else {

        *state = 5;

        FUN_005225a8(0x69dfa0);

      }

    }

    break;

  case 2:

    goto switchD_0036db68_caseD_2;

  case 3:

    goto switchD_0036db68_caseD_3;

  case 4:

    goto switchD_0036db68_caseD_4;

  case 5:

    lVar7 = FUN_003b5a10();

    if (lVar7 != 0) {

      if (((*(u32 *)(iVar1 + 4) & 8) == 0) &&

         (*(char *)(*(int *)(*(int *)(iVar1 + 8) + 0x94) + 0x18) != '\0')) {

        *(u32 *)(iVar1 + 0x974) = 1;

      }

      else {

        *(u32 *)(iVar1 + 0x974) = 0;

      }

      *state = 6;

    }

    break;

  case 6:

    if (*(int *)(iVar1 + 0x974) < 1) {

      *state = 8;

    }

    else {

      DAT_007ce5e8 = FUN_00316e00(0,2,0);

      *state = 7;

    }

    break;

  case 7:

    lVar7 = FUN_00316f70(DAT_007ce5e8);

    if (lVar7 == 1) {

      DAT_007ce5ec = FUN_003b6000(0,DAT_007ce5e8);

      FUN_001a0dc0(DAT_007ce5ec,1);

      *(int *)(iVar1 + 0x974) = *(int *)(iVar1 + 0x974) + -1;

      *state = 6;

    }

    break;

  case 8:

    for (iVar3 = FUN_003b5d50(3); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0xf8)) {

      FUN_0031be80(*(u32 *)(iVar3 + 0x128));

    }

    *state = 9;

  case 9:

    uVar2 = FUN_003964c0();

    *(u32 *)(iVar1 + 0x710) = uVar2;

    for (iVar3 = 0; iVar3 < *(int *)(*(int *)(iVar1 + 8) + 0x44); iVar3 = iVar3 + 1) {

      iVar8 = *(int *)(*(int *)(iVar1 + 8) + 0x40) + iVar3 * 0x10;

      if (*(int *)(iVar8 + 8) == 4) {

        FUN_00396480(*(u32 *)(iVar1 + 0x710),

                     *(int *)(*(int *)(iVar1 + 8) + 0x10) + *(int *)(iVar8 + 4));

      }

    }

    FUN_003965d0(*(u32 *)(iVar1 + 0x710));

    *state = 10;

    break;

  case 10:

    lVar7 = FUN_003965f0(*(u32 *)(iVar1 + 0x710));

    if (lVar7 == 0) {

      return 0;

    }

    *state = 0xb;

  case 0xb:

    FUN_003912f0(*(u32 *)(iVar1 + 8),iVar1);

    *state = 0xc;

switchD_0036db68_caseD_c:

    *state = 0xe;

    break;

  case 0xc:

    goto switchD_0036db68_caseD_c;

  case 0xd:

    lVar7 = FUN_00195460(*(u32 *)(iVar1 + 0x8d8));

    if (lVar7 == 1) {

      return 0;

    }

    *state = 0xe;

  case 0xe:

    if ((*(u8 *)(iVar1 + 0x4c) & 1) == 0) {

      *state = 0x10;

    }

    else {

      uVar4 = FUN_00386e10(iVar1);

      uVar5 = FUN_00386e30(iVar1);

      uVar2 = FUN_0010a770(*(u32 *)(iVar1 + 0x92c),2,0,2,uVar4,uVar5);

      *(u32 *)(iVar1 + 0x93c) = uVar2;

      *state = 0xf;

    }

    break;

  case 0xf:

    lVar7 = FUN_0010a720(*(u32 *)(iVar1 + 0x93c));

    if (lVar7 != 0) {

      *state = 0x10;

      goto switchD_0036db68_caseD_10;

    }

    break;

  case 0x10:

switchD_0036db68_caseD_10:

    iVar3 = FUN_003980e0(*(u32 *)(iVar1 + 0x934));

    *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) & 0xffffff7f;

    uVar4 = FUN_00386e10(iVar1);

    uVar5 = FUN_00386e30(iVar1);

    uVar6 = FUN_00397500(iVar1);

    lVar7 = FUN_003bd8b0(uVar4,uVar5,uVar6);

    if ((lVar7 != -1) && (lVar7 != 0)) {

      FUN_00395270(lVar7);

    }

    if ((*(u32 *)(iVar1 + 4) & 8) == 0) {

      FUN_003890e0(iVar1);

    }

    lVar7 = FUN_00397520(iVar1,&iStack_4);

    if (((lVar7 == 1) && (*(int *)(iVar3 + 0x14) < iStack_4)) && (-1 < *(int *)(iVar3 + 0x14))) {

      FUN_00397510(iVar1,*(int *)(iVar3 + 0x14));

      FUN_00393f30(iVar1,0x36e690);

    }

    return *(u32 *)(iVar1 + 0x978);

  }

  return 0;

}


#pragma opt_common_subs reset
// FUN_0036E140


code * FUN_0036e140(int param_1)
{
  u32 *puVar1;
  code *pcVar2;
  u32 lVar3;

  puVar1 = *(u32 **)(param_1 + 0x3c);
  if ((puVar1[1] & 8) != 0) {
    lVar3 = FUN_0039e6f0();
    if ((lVar3 == 1) && ((*(u16 *)DAT_007e094e_abs & 0x200) != 0)) {
      if (puVar1[0x23] != 0) {
        puVar1[0x23] = 0;
      }
      else {
        puVar1[0x23] = 1;
      }
    }
  }
  else {
    if ((*(u16 *)DAT_007e094e_abs & 0x200) != 0) {
      if (puVar1[0x23] != 0) {
        puVar1[0x23] = 0;
      }
      else {
        puVar1[0x23] = 1;
      }
    }
  }
  if ((puVar1 != 0) && (puVar1[0x23] != 0)) {
    FUN_00386d50((int)puVar1);
  }
  lVar3 = FUN_00195460(puVar1[0x24e]);
  if (lVar3 == 0) {
    puVar1[1] = puVar1[1] & 0xfffdffff;
    puVar1[0x24e] = 0;
    pcVar2 = (code *)FUN_0036e690;
  }
  else {
    pcVar2 = (code *)0x0;
  }
  return pcVar2;
}


// FUN_0036E260


u32 FUN_0036e260(int param_1)



{

  int iVar1;

  u32 uVar2;

  int lVar3;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  lVar3 = FUN_00108710();
  if (lVar3 == 0) {
    FUN_005225a8(DAT_0069ffd0);
    uVar2 = 0;
    goto LAB_0036e2d0;
  }
  if ((*(s8 *)(iVar1 + 0x4c) & 4) == 0) {
    goto LAB_0036e2cc;
  }
  lVar3 = FUN_002ff310();
  if (lVar3 == 1) {
    goto LAB_0036e2cc;
  }
  uVar2 = 0;
  goto LAB_0036e2d0;
LAB_0036e2cc:
  uVar2 = 0xffffffff;
LAB_0036e2d0:
  return uVar2;

}


/* W415: swapping case-2's FUN_00316e00 and fallback FUN_003b5d10 layout
   restored the retail call order and reduced nd 645 -> 618 (object 928/928). */
// FUN_0036E2F0 NONMATCHING


u32 FUN_0036e2f0(int param_1)



{

  u8 uVar1;

  u8 uVar2;

  u8 uVar3;

  int iVar4;

  int iVar5;

  u16 sVar6;

  u32 uVar7;

  u8 *puVar8;

  u32 lVar9;

  u32 uVar10;

  u32 *puVar11;

  u32 *puVar12;

  int iVar13;

  

  iVar4 = *(int *)(param_1 + 0x3c);

  puVar11 = (u32 *)(iVar4 + 0x8e0);

  switch(*(u32 *)(iVar4 + 0x8e0)) {

  case 0:

    FUN_00397450();

    *puVar11 = 1;

    lVar9 = FUN_003b5d00();

    if (lVar9 == 0) {

      *puVar11 = 4;

    }

    break;

  case 1:

    for (iVar13 = 0; iVar13 < *(int *)(iVar4 + 0x8e4); iVar13 = iVar13 + 1) {

      if (puVar11[iVar13 + 0xb] == 0) {

        lVar9 = FUN_00386ae0(0x9c,7);


          FUN_00521408(lVar9,0,0x9c);

          puVar12 = (u32 *)lVar9;

          *puVar12 = 1;

          puVar12[2] = 0xffffffff;

          *(u16 *)(puVar12 + 3) = 0;

          puVar12[0x19] = 0;

          FUN_00361b60((int *)lVar9,iVar4);


        puVar11[iVar13 + 0xb] = (int)lVar9;

        FUN_0038f8c0(*(u32 *)(iVar4 + 8),iVar4,lVar9,iVar13 + 900U & 0x3ff | 0xc00);

      }

    }

    *puVar11 = 2;

    break;

  case 2:

    iVar13 = *(int *)(iVar4 + 0x918);

    if (iVar13 >= *(int *)(iVar4 + 0x8e4)) {

      *puVar11 = 4;

    }

    else {

      if (puVar11[iVar13 * 3 + 3] == 0) {

        iVar5 = puVar11[iVar13 + 0xb];

        if (iVar5 != 0) {

          *(u16 *)(iVar5 + 0xc) = (short)iVar13 + 900U & 0x3ff | 0xc00;

          lVar9 = (int)FUN_003b5d10_evt_main(*(u16 *)(iVar5 + 0xc));

          if (lVar9 != 0) {

            *(u32 *)(iVar5 + 0x58) = *(u32 *)((int)lVar9 + 0x28);

          }

          else {

            *(u32 *)(iVar5 + 0x58) = 0;

          }

          *(u32 *)(iVar5 + 0x38) = 0;

        }

      }

      else {

        uVar7 = FUN_00316e00(*(u16 *)(puVar11 + iVar13 * 3 + 2),

                             puVar11[iVar13 * 3 + 3] & 0xffff,0);

        *(u32 *)(iVar4 + 0x91c) = uVar7;

        *puVar11 = 3;

      }

      *(int *)(iVar4 + 0x918) = *(int *)(iVar4 + 0x918) + 1;

    }

    break;

  case 3:

    lVar9 = FUN_00316f70(*(u32 *)(iVar4 + 0x91c));

    if (lVar9 == 1) {

      iVar13 = *(int *)(iVar4 + 0x918);

      sVar6 = FUN_003b6270(iVar13 + 900U & 0xffff,3,*(u32 *)(iVar4 + 0x91c));
      if (sVar6 == 0) {
        FUN_0019d3f0(DAT_0069ffd0,0x2eb7);
      }


      FUN_003b9550(sVar6,1);

      uVar10 = (u32)FUN_003b5d10_evt_main(sVar6);

      FUN_0038d910(uVar10);

      iVar5 = puVar11[iVar13 + 0xb];

      if (iVar5 != 0) {

        *(short *)(iVar5 + 0xc) = sVar6;

        lVar9 = (int)FUN_003b5d10_evt_main(*(u16 *)(iVar5 + 0xc));

        if (lVar9 != 0) {

          *(u32 *)(iVar5 + 0x58) = *(u32 *)((int)lVar9 + 0x28);

        }

        else {

          *(u32 *)(iVar5 + 0x58) = 0;

        }

        *(int *)(iVar5 + 0x38) = (int)uVar10;

      }

      puVar8 = (u8 *)FUN_00318b00(*(u32 *)((int)uVar10 + 0x128));

      iVar13 = puVar11[iVar13 + 0xb];

      uVar1 = puVar8[1];

      uVar2 = puVar8[2];

      uVar3 = puVar8[3];

      *(u8 *)(iVar13 + 0x54) = *puVar8;

      *(u8 *)(iVar13 + 0x55) = uVar1;

      *(u8 *)(iVar13 + 0x56) = uVar2;

      *(u8 *)(iVar13 + 0x57) = uVar3;

      *(int *)(iVar4 + 0x918) = *(int *)(iVar4 + 0x918) + 1;

      *puVar11 = 2;

    }

    break;

  case 4:

    *puVar11 = 5;

    break;

  case 5:

    *(u32 *)(iVar4 + 4) = *(u32 *)(iVar4 + 4) & 0xfffeffff;

    return *(u32 *)(iVar4 + 0x920);

  }

  return 0;

}


/* W367 pragma probe: opt_propagation off nd 1100 -> 1093; on nd 1100; object 1688/1696. */
#pragma opt_propagation off
// FUN_0036E690 NONMATCHING


code * FUN_0036e690(int param_1)



{

  int iVar1;

  bool bVar2;

  code *pcVar3;

  u32 lVar4;

  int iVar5;

  u32 uVar6;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  pcVar3 = (code *)0x0;

  FUN_00385b20(iVar1);

  uVar6 = *(u32 *)(iVar1 + 4);

  if ((uVar6 & 0x40000) == 0) {

    if ((uVar6 & 0x80) == 0) {

      if ((uVar6 & 0x10000) == 0) {

        if ((uVar6 & 0x20000) == 0) {

          FUN_00362ff0(iVar1);

          if (*(int *)(iVar1 + 0x18) != *(int *)(iVar1 + 0x1c)) {

            FUN_00366ac0(*(int *)(iVar1 + 0x18),iVar1);

          }

          *(u32 *)(iVar1 + 0x1c) = *(u32 *)(iVar1 + 0x18);

          if ((*(int *)(iVar1 + 0xdc) == 0) && ((DAT_007e094e & 0x200) != 0)) {

            if ((*(u32 *)(iVar1 + 4) & 8) == 0) {

              if (*(int *)(iVar1 + 0x8c) == 0) {

                *(u32 *)(iVar1 + 0x8c) = 1;

              }

              else {

                *(u32 *)(iVar1 + 0x8c) = 0;

              }

            }

            else {

              lVar4 = FUN_0039e6f0();

              if (lVar4 == 1) {

                if (*(int *)(iVar1 + 0x8c) == 0) {

                  *(u32 *)(iVar1 + 0x8c) = 1;

                }

                else {

                  *(u32 *)(iVar1 + 0x8c) = 0;

                }

              }

            }

          }

          DAT_007ce5d8 = (u32)(*(int *)(iVar1 + 0x8c) == 1);

          if ((DAT_007e094e & 1) != 0) {

            if ((*(u32 *)(iVar1 + 4) & 8) == 0) {

              lVar4 = FUN_00195340(0x69dfe0);

              if (lVar4 == 0) {

                FUN_001a7020(0);

              }

              else {

                FUN_001a7060(0);

              }

            }

            else {

              lVar4 = FUN_0039e6f0();

              if (lVar4 == 1) {

                lVar4 = FUN_00195340(0x69dfe0);

                if (lVar4 == 0) {

                  FUN_001a7020(0);

                }

                else {

                  FUN_001a7060(0);

                }

              }

            }

          }

          if ((*(u32 *)(iVar1 + 4) & 8) == 0) {

            if ((DAT_007e094e & 2) == 0) {

              FUN_003625e0();

              lVar4 = FUN_003b5d00();

              if ((lVar4 != 0) && ((DAT_007e094e & 0x80) != 0)) {

                FUN_00362f20(iVar1);

              }

              if ((DAT_007e094e & 0x800) != 0) {

                uVar6 = *(u32 *)(iVar1 + 4);

                if (((((((uVar6 & 1) == 0) && ((uVar6 & 0x20) == 0)) && ((uVar6 & 0x200) == 0)) &&

                     (((uVar6 & 0x400) == 0 && ((uVar6 & 0x800) == 0)))) &&

                    (((uVar6 & 0x1000) == 0 && (((uVar6 & 0x20000) == 0 && ((uVar6 & 0x2000) == 0)))

                     ))) && (((uVar6 & 0x4000) == 0 && ((uVar6 & 0x8000) == 0)))) {

                  bVar2 = false;

                }

                else {

                  bVar2 = true;

                }

                if (bVar2) {

                  if ((uVar6 & 1) != 0) {

                    *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) & 0xfffffffe;

                  }

                }

                else {

                  *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 1;

                }

              }

              if ((*(u32 *)(iVar1 + 4) & 1) != 0) {

                FUN_00362390(iVar1);

              }

            }

            else {

              *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 1;

              pcVar3 = (code *)FUN_0036d5f0;

            }

          }

          FUN_0038ca80(iVar1);

          if ((*(int *)(iVar1 + 8) != 0) && (lVar4 = FUN_0039eee0(iVar1 + 0x82c), lVar4 != 0)) {

            FUN_0039f410(iVar1 + 0x82c);

          }

          FUN_0036d030(iVar1);

          if (((((*(u32 *)(iVar1 + 4) & 8) == 0) || (lVar4 = FUN_0039e6f0(), lVar4 != 1)) ||

              ((DAT_007e094c & 4) == 0)) || ((DAT_007e094c & 8) == 0)) {

            lVar4 = FUN_00386e10(iVar1);

            if ((((lVar4 == 0x50) && (lVar4 = FUN_00386e30(iVar1), lVar4 == 1)) ||

                ((lVar4 = FUN_00386e10(iVar1), lVar4 == 0x50 &&

                 (lVar4 = FUN_00386e30(iVar1), lVar4 == 5)))) &&

               ((0x1e < *(int *)(iVar1 + 0x18) && ((DAT_007e094e & 0x800) != 0)))) {

              FUN_00108f70();

              if ((*(u8 *)(iVar1 + 0x4c) & 4) != 0) {

                FUN_002ff260(1);

              }

              *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 0x40000;

              pcVar3 = (code *)0x0;

            }

            else {

              uVar6 = *(u32 *)(iVar1 + 4) & 8;

              if ((uVar6 == 0) || (*(int *)(iVar1 + 0x18) < *(int *)(iVar1 + 0x14))) {

                iVar5 = *(int *)(iVar1 + 0x18);

                if (*(int *)(iVar1 + 0x77c) == 0) {

                  if (iVar5 < *(int *)(iVar1 + 0x14)) {

                    iVar5 = iVar5 + 1;

                  }

                  else if (uVar6 == 0) {

                    *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) ^ 1;

                  }

                }

                if (*(int *)(iVar1 + 0x24) != 0) {

                  iVar5 = *(int *)(iVar1 + 0x28);

                  *(u32 *)(iVar1 + 0x24) = 0;

                }

                *(int *)(iVar1 + 0x18) = iVar5;

                if (pcVar3 == (code *)FUN_0036d5f0) {

                  *(u32 *)(iVar1 + 0xd4) = 0;

                  *(u32 *)(iVar1 + 0xd0) = 0;

                  *(u32 *)(iVar1 + 0xdc) = 0;

                  FUN_0038a6c0(iVar1);

                  FUN_0036f5f0(1,2,2,iVar1);

                  if ((*(int *)(iVar1 + 8) != 0) &&

                     (lVar4 = FUN_0039eee0(iVar1 + 0x82c), lVar4 != 0)) {

                    FUN_0039f350(iVar1 + 0x82c);

                  }

                  FUN_003970d0();

                  FUN_003cf440();

                  FUN_00108f70();

                  if (*(int *)(iVar1 + 0x8dc) == 1) {

                    FUN_001071b0();

                    *(u32 *)(iVar1 + 0x8dc) = 0;

                  }

                  FUN_0038a0c0(iVar1,1);

                }

              }

              else {

                if ((*(u8 *)(iVar1 + 0x4c) & 4) != 0) {

                  FUN_002ff260(1);

                }

                *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 0x40000;

                pcVar3 = (code *)0x0;

              }

            }

          }

          else {

            if ((*(u8 *)(iVar1 + 0x4c) & 4) != 0) {

              FUN_002ff260();

            }

            *(u32 *)(iVar1 + 4) = *(u32 *)(iVar1 + 4) | 0x40000;

            pcVar3 = (code *)0x0;

          }

        }

        else {

          pcVar3 = (code *)FUN_0036e140;

        }

      }

      else {

        pcVar3 = (code *)FUN_0036e2f0;

      }

    }

    else {

      pcVar3 = (code *)FUN_0036db20;

    }

  }

  else {

    pcVar3 = (code *)FUN_0036e260;

  }

  return pcVar3;

}


#pragma opt_propagation reset
// FUN_0036ED30


code * FUN_0036ed30(int param_1)



{

  int iVar1;

  int uVar2;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  FUN_003951a0(0xa10);

  FUN_003953e0(*(u32 *)(iVar1 + 0x92c));

  FUN_00396410(param_1);

  uVar2 = FUN_00198590();

  FUN_001a4580(uVar2,35.0f);

  FUN_001a0420(1);

  FUN_0038a0c0(iVar1,0);

  return (code *)FUN_0036e690;

}


// FUN_0036EDD0


code * FUN_0036edd0(void)
{
  int iVar1;

  iVar1 = FUN_0035ae10();
  if ((*(u32 *)(iVar1 + 4) & 0x80) != 0) {
    return (code *)FUN_0036db20;
  }
  FUN_005225a8(&D_0069DFF0);
  return (code *)FUN_0036ed30;
}


// FUN_0036EE30


code * FUN_0036ee30(void)



{


  u32 uVar2;

  u32 uVar3;


  u32 uVar5;

  int iVar6;

  

  uVar2 = FUN_0035ae10();

  FUN_0036f370(uVar2);

  iVar6 = (int)uVar2;

  if (*(int *)(iVar6 + 0x934) == 0) {

    FUN_0019d3f0((const char *)(DAT_006a0000 - 0x2a80),0x306f);

  }

  {
    int iVar1;

  iVar1 = FUN_003980e0(*(u32 *)(iVar6 + 0x934));

  FUN_00386e20(uVar2,*(u32 *)(iVar1 + 0xc));

  FUN_00386e40(uVar2,*(u32 *)(iVar1 + 0x10));

  FUN_00397510(uVar2,*(u32 *)(iVar1 + 0x14));
  }

  uVar5 = FUN_00386e10(uVar2);

  FUN_00523ac8(iVar6 + 0x144,(const char *)(DAT_006a0000 - 0x2860),uVar5,FUN_00386e30(uVar2));

  uVar5 = FUN_00386e10(uVar2);

  FUN_005225a8((const char *)(DAT_006a0000 - 0x1fd0),uVar5,FUN_00386e30(uVar2));

  *(u32 *)(iVar6 + 4) = 0;

  *(u32 *)(iVar6 + 0x8c) = 0;

  *(u32 *)(iVar6 + 4) = *(u32 *)(iVar6 + 4) | 8;

  uVar3 = FUN_00386e10(uVar2);

  FUN_00393e30(uVar2,uVar3,FUN_00386e30(uVar2),FUN_00397500(uVar2),0,FUN_0036edd0);

  return (code *)FUN_0036edd0;

}


// FUN_0036EFB0


void FUN_0036efb0(void)



{

  int lVar1;

  

  lVar1 = FUN_003b5d10(0x400);

  if (lVar1 != 0) {

    FUN_003174e0(*(u32 *)((u16 *)lVar1 + 0x94));

    FUN_003b7090(*(u16 *)lVar1);

  }

  return;

}


// FUN_0036F000 NONMATCHING


void FUN_0036f000(int param_1)



{

  int iVar1;

  u32 lVar2;

  int iVar3;

  

  FUN_003cf440();

  FUN_00395420();

  FUN_00103cb0();

  FUN_003bcc80();

  FUN_003970d0();

  FUN_0038ca00();

  iVar3 = (int)param_1;

  if ((*(int *)(iVar3 + 8) != 0) && (lVar2 = FUN_0039eee0(iVar3 + 0x82c), lVar2 != 0)) {

    FUN_0039f350(iVar3 + 0x82c);

  }

  FUN_0038d720(param_1);

  if ((*(u32 *)(iVar3 + 4) & 8) == 0) {

    FUN_00108f70();

  }

  if (*(int *)(iVar3 + 0x924) != 0) {

    FUN_00195020(*(int *)(iVar3 + 0x924));

    *(u32 *)(iVar3 + 0x924) = 0;

  }

  if (param_1 == 0) {

    FUN_0019d3f0(DAT_0069d580_abs,0x167);

  }

  FUN_0039eb90();

  FUN_00396530(*(u32 *)(iVar3 + 0x710));

  *(u32 *)(iVar3 + 0x710) = 0;

  if ((*(u32 *)(iVar3 + 4) & 8) == 0) {

    lVar2 = FUN_003b5d10(0x400);

    if (lVar2 != 0) {

      FUN_003174e0(*(u32 *)((u16 *)lVar2 + 0x94));

      FUN_003b7090(*(u16 *)lVar2);

    }

    FUN_00388ff0(param_1);

    FUN_003b5ab0();

    FUN_005225a8(DAT_0069e068_abs);

  }

  if (((*(u32 *)(iVar3 + 4) & 8) == 0) && (*(int *)(iVar3 + 0x8dc) == 1)) {

    FUN_001071b0();

    *(u32 *)(iVar3 + 0x8dc) = 0;

    FUN_005225a8(DAT_0069e078_abs);

  }

  FUN_0035ae50();

  FUN_0035ae60();

  FUN_0035ae70();

  FUN_0035ae80();

  while (iVar1 = *(int *)(iVar3 + 0x84), iVar1 != 0) {

    while (*(int *)(iVar1 + 0x6c) != 0) {

      FUN_00361890((int *)iVar1,*(int *)(iVar1 + 0x6c));

    }

    FUN_00361c30(iVar1,param_1);

    FUN_00386b70(0,7,0x9c);

  }

  if (*(int *)(iVar3 + 8) != 0) {

    FUN_00394c30(*(int *)(iVar3 + 8),iVar3 + 0x82c);

    *(u32 *)(iVar3 + 8) = 0;

  }

  if ((*(int *)(iVar3 + 0x938) != 0) && (lVar2 = FUN_00195460(), lVar2 == 1)) {

    FUN_00195020(*(u32 *)(iVar3 + 0x938));

    *(u32 *)(iVar3 + 0x938) = 0;

  }

  return;

}


// FUN_0036F260


void FUN_0036f260(void)



{

  char cVar1;

  int uVar2;

  u32 *puVar3;

  

  uVar2 = FUN_0035ae10();

  FUN_0036f000(uVar2);

  puVar3 = (u32 *)uVar2;

  if ((puVar3[1] & 8) == 0) {

    FUN_00389f40();

  }

  FUN_003bb340();

  if ((((puVar3[1] & 8) != 0) && (cVar1 = *(char *)((int)puVar3 + 0x45), '\0' < cVar1)) &&

     (cVar1 < '\t')) {

    FUN_0016ddd0(cVar1 + -1);

  }

  if (((puVar3[1] & 8) == 0) && (puVar3[0x24d] != 0)) {

    FUN_00195020_evt_main(puVar3[0x24d]);

    puVar3[0x24d] = 0;

  }

  FUN_001a0420(0);

  FUN_00385b90_evt_main((u32)puVar3);

  FUN_003951a0(0x1419);

  FUN_003cf440();

  FUN_00386b70_evt_main(*puVar3,0,0x990);

  FUN_00386cd0();

  FUN_005225a8_evt_main(&D_0069E088);

  return;

}


// FUN_0036F370


void FUN_0036f370(int param_1)



{

  *(u32 *)(param_1 + 0x928) = DAT_007cdeac;

  FUN_003858c0();

  FUN_00386aa0();

  FUN_00395170(0x1419);

  return;

}


// FUN_0036F3B0


void FUN_0036f3b0(u64 param_1,u32 param_2)



{

  int iVar1;

  u32 uVar2;

  u32 lVar3;

  

  lVar3 = FUN_00386ae0_evt(0x990,0);

  iVar1 = (int)lVar3;

  if (lVar3 == 0) {

    FUN_0019d3f0((const char *)(DAT_006a0000 - 0x2a80),0x31aa);

  }

  FUN_00521408(lVar3,0,0x990);

  *(int *)iVar1 = iVar1;

  FUN_0036f4d0();

  FUN_0036f490(0);

  uVar2 = FUN_00194b20(param_1,(const char *)(DAT_006a0000 - 0x1f60),0xf,FUN_0036ee30,FUN_0036f260,lVar3);

  *(u32 *)(iVar1 + 0x92c) = uVar2;

  *(u32 *)(iVar1 + 0x934) = param_2;

  return;

}


// FUN_0036f480


bool FUN_0036f480(void)



{

  return DAT_007ce5f0 != 0;

}


// FUN_0036F490


void FUN_0036f490(int param_1)
{
  if (param_1 == 1) {
    DAT_007ce5f0 = 1;
  }
  else {
    DAT_007ce5f0 = 0;
  }
}



// FUN_0036f4c0


u32 FUN_0036f4c0(void)



{

  return DAT_007ce5f4;

}


// FUN_0036F4D0


void FUN_0036f4d0(void)



{

  FUN_00521408(&DAT_007ce5f0,0,8);

  return;

}

