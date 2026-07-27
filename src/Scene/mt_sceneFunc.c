#include "temporary.h"
#include "Scene/mt_sceneFunc.h"
#include "Scene/mt_scene.h"
#include "Scene/resrcManager.h"
#include "Kernel/Kwln/kwlnTask.h"
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
extern u32 DAT_006a2ed8;
extern u32 DAT_006a2ee0;
extern u32 DAT_006a2ee8;
extern u32 DAT_006a2ef0;
extern u32 DAT_006a2ef8;
extern u32 DAT_006a2f00;
extern u32 DAT_006a2f08;
extern u32 DAT_006a2f10;
extern u32 DAT_006a2f18;
extern u32 DAT_006a2f20;
extern u32 DAT_006a2f28;
extern u32 DAT_006a2f30;
extern u32 DAT_006a2f38;
extern u32 DAT_006a2f40;
extern u32 DAT_006a2f48;
extern char DAT_006a2df0[];
extern u32 DAT_006a2f50;
extern u32 DAT_007cad5c;
extern u32 DAT_007cada0;
extern u32 DAT_007caea4;
extern u32 DAT_007caf1c;
extern f32 DAT_007cb0b8;
extern u32 DAT_007cd560;
extern u32 DAT_007cd564;
extern u32 DAT_007ce658;
extern u32 DAT_007ce65c;
extern u32 DAT_007ce660;
extern u32 DAT_007ce664;
extern u32 DAT_007ce668;
extern u32 DAT_0095aff0;
extern u32 DAT_0095aff4;
extern u32 DAT_0095aff8;
extern u32 DAT_0095affc;
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
  float value[3];
} __attribute__((packed)) SceneVecBits;
#pragma alias DAT_006a2f48_abs DAT_006a2f48
extern SceneVecBits DAT_006a2f48_abs[];
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
                  u32 param_5,u32 param_6,float param_7);
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
#pragma alias FUN_00100d80_typed_scene FUN_00100d80
extern void *FUN_00100d80_typed_scene(const char *param_1,u32 param_2);

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
void FUN_003bb390(u32 param_2,u16 param_3,float param_1);
void FUN_003bb400(u32 param_1);
void FUN_003bb450(float param_1,u32 param_2,u32 param_3,u32 param_4,  float *param_5,float *param_6);
void FUN_003bb620(u32 param_1,u32 *param_2,int param_3);
void FUN_003bb7a0(Resrc* param_1);
void FUN_003bb9b0(float *param_1);
#pragma alias FUN_003bb9b0_scene_typed FUN_003bb9b0
extern void FUN_003bb9b0_scene_typed(float *param_1);
void FUN_003bba70(int param_1);
void FUN_003bbaa0(float *param_1,float *param_2,float *param_3);
void FUN_003bbb90(const float *param_1,float *param_2);
void FUN_003bbc90(float param_1,float *param_2,float *param_3,float *param_4,float *param_5,  float *param_6,float *param_7);
void FUN_003bbd40(float param_1,char *param_2,float *param_3);
float FUN_003bbed0(float param_1,float param_2,u32 param_3);
void FUN_003bbfd0(float param_1,float param_2,float *param_3,float *param_4,
                  float *param_5,float *param_6,float *param_7);
float FUN_003bc0e0(char *param_1);
float FUN_003bc220(char *param_1,float param_2,float param_3,float *param_4,u32 *param_5);
/* Retail call: FUN_003b8ff0 + 0x160. */
#pragma alias FUN_00318770_scene_typed FUN_00318770
extern void FUN_00318770_scene_typed(float param_1,u32 param_2,u32 param_3,u32 param_4);
/* Retail calls: FUN_003bbd40 + 0x0ac, + 0x178; FUN_003bc220 + 0x110, + 0x138, + 0x2a0, + 0x2d8, + 0x3e0, + 0x408; FUN_003bc730 + 0x0e0, + 0x118. */
#pragma alias FUN_003bbc90_scene_typed FUN_003bbc90
extern void FUN_003bbc90_scene_typed(float param_1,...);
/* Retail call: FUN_003bbed0 + 0x0d4. */
#pragma alias FUN_003bbd40_scene_typed FUN_003bbd40
extern void FUN_003bbd40_scene_typed(float param_1,...);
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


#pragma push
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
  float source10;
  float source14;
  float source18;
  struct V3 *input;

  input = (struct V3 *)param_2;
  values = *input;
  source10 = 0.0f;
  source14 = 0.0f;
  source18 = 0.0f;

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

    fVar2 = *(volatile float *)(param_2 + 0);
    fVar3 = *(volatile float *)(param_2 + 1);
    fVar1 = *(volatile float *)(param_2 + 2);

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
#pragma push
#pragma opt_rebuildconditionals off
 
// FUN_003B8CE0

u32 FUN_003b8ce0(u32 param_1,u8 param_2,u32 param_3,u32 param_4)
{
    u32 uVar1;
    int iVar2;
    u16 *puVar3;
    volatile u8 *puVar5;
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
    puVar5 = (volatile u8 *)iVar2;
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
#pragma pop
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
// FUN_003B8FF0 NONMATCHING

u32 FUN_003b8ff0(u32 param_1,u32 param_2,u32 param_3,u32 param_4,u32 param_5,
                 u32 param_6,float param_7)
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
  lVar2 = FUN_003186e0(uVar1,param_2 & 0xffff,(short)param_3);
  if (lVar2 != 0) {
    goto complete;
  }
  FUN_003189f0(uVar1,param_2 & 0xffff,param_3);
  FUN_003182d0(uVar1,param_2 & 0xffff,(short)param_3,param_4,uVar3);
  if (0 < param_6) {
    FUN_00318770_scene_typed((float)(int)param_6,uVar1,param_2 & 0xffff,param_3);
  }
  FUN_005225a8(0x6a2e10,uVar1,param_2,param_3);
complete:
  *(u32 *)(param_1 + 0x14) = *(u32 *)(param_1 + 0x14) & 0xffffdfff;
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

  float fStack_88;

  float fStack_84;

  float fStack_80;

  float fStack_78;

  float fStack_74;

  float fStack_70;

  u32 uStack_68;

  u32 uStack_64;

  u32 uStack_60;

  u32 uStack_58;

  u32 uStack_54;

  u32 uStack_50;

  volatile float fStack_48;

  volatile float fStack_44;

  volatile float fStack_40;

  volatile float fStack_38;

  volatile float fStack_34;

  volatile float fStack_30;

  float fStack_28;

  float fStack_24;

  float fStack_20;

  volatile float fStack_18;

  volatile float fStack_14;

  volatile float fStack_10;

  u8 auStack_8 [3];

  char cStack_5;

  u8 uStack_4;

  u8 uStack_3;

  u8 uStack_2;

  char cStack_1;

  

  iVar10 = 0;

  if (param_1 != 0) {

    puVar8 = (u16 *)param_1;

    uVar1 = *(u32 *)(puVar8 + 0x14);

    if ((uVar1 & 0x20) == 0) {

      if ((uVar1 & 8) == 0) {

        iVar10 = 1;

      }

    }

    else {

      iVar10 = *(int *)(puVar8 + 0x7a);

      *(u32 *)(puVar8 + 0x14) = uVar1 & 0xffffffdf;

      puVar8[0x7a] = 0;

      puVar8[0x7b] = 0;

    }

    if (iVar10 < 0) {

      iVar10 = 0;

    }

    if ((*(u32 *)(puVar8 + 0x14) & 1) != 0) {

      fStack_18 = *(float *)(puVar8 + 0x1c);

      fStack_14 = *(float *)(puVar8 + 0x1e);

      fStack_10 = *(float *)(puVar8 + 0x20);

      fStack_28 = *(float *)(puVar8 + 2);

      fStack_24 = *(float *)(puVar8 + 4);

      fStack_20 = *(float *)(puVar8 + 6);

      cVar9 = (char)puVar8[0x28];

      if (cVar9 == '\0') {

        fStack_38 = fStack_18 - fStack_28;

        fStack_34 = fStack_14 - fStack_24;

        fStack_30 = fStack_10 - fStack_20;

        fVar11 = (float)FUN_004c6ac0(&fStack_38);

        iVar6 = iVar10;

        do {

          if (fVar11 <= *(float *)(puVar8 + 0x2c)) {

            *(float *)(puVar8 + 2) = fStack_18;

            *(float *)(puVar8 + 4) = fStack_14;

            *(float *)(puVar8 + 6) = fStack_10;

            *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffffe;

            FUN_005225a8(0x6a2e40);

            break;

          }

          FUN_004c69f0(&fStack_48,&fStack_38);

          if (0 < iVar6) {

            *(float *)(puVar8 + 2) =

                 fStack_48 * *(float *)(puVar8 + 0x2c) + *(float *)(puVar8 + 2) + 0.0f;

            *(float *)(puVar8 + 4) =

                 fStack_44 * *(float *)(puVar8 + 0x2c) + *(float *)(puVar8 + 4) + 0.0f;

            *(float *)(puVar8 + 6) =

                 fStack_40 * *(float *)(puVar8 + 0x2c) + *(float *)(puVar8 + 6) + 0.0f;

          }

          iVar6 = iVar6 + -1;

        } while (0 < iVar6);

        FUN_003b7460(puVar8,puVar8 + 2,0,0);

      }

      else if (cVar9 == '\x01') {

        fStack_38 = fStack_18 - *(float *)(puVar8 + 0x16);

        fStack_34 = fStack_14 - *(float *)(puVar8 + 0x18);

        fStack_30 = fStack_10 - *(float *)(puVar8 + 0x1a);

        if (*(u32 *)(puVar8 + 0x30) == 0) {

          *(float *)(puVar8 + 2) = fStack_18;

          *(float *)(puVar8 + 4) = fStack_14;

          *(float *)(puVar8 + 6) = fStack_10;

          *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffffe;

          FUN_005225a8(0x6a2e60);

        }

        else {

          fStack_38 = fStack_38 / (float)*(u32 *)(puVar8 + 0x30);

          fStack_34 = fStack_34 / (float)*(u32 *)(puVar8 + 0x30);

          fStack_30 = fStack_30 / (float)*(u32 *)(puVar8 + 0x30);

          switch(*(u8 *)((int)puVar8 + 0x51)) {

          case 0:

            *(float *)(puVar8 + 2) =

                 fStack_38 * (float)*(u32 *)(puVar8 + 0x2e) + *(float *)(puVar8 + 0x16) + 0.0f;

            *(float *)(puVar8 + 4) =

                 fStack_34 * (float)*(u32 *)(puVar8 + 0x2e) + *(float *)(puVar8 + 0x18) + 0.0f;

            *(float *)(puVar8 + 6) =

                 fStack_30 * (float)*(u32 *)(puVar8 + 0x2e) + *(float *)(puVar8 + 0x1a) + 0.0f;

            break;

          case 1:

          case 2:

          case 3:

          case 4:

          case 5:

            fVar11 = (float)FUN_003bbed0_scene_typed((float)*(u32 *)(puVar8 + 0x30),

                                         (float)*(u32 *)(puVar8 + 0x2e));

            *(float *)(puVar8 + 2) = fStack_38 * fVar11 + *(float *)(puVar8 + 0x16) + 0.0f;

            *(float *)(puVar8 + 4) = fStack_34 * fVar11 + *(float *)(puVar8 + 0x18) + 0.0f;

            *(float *)(puVar8 + 6) = fStack_30 * fVar11 + *(float *)(puVar8 + 0x1a) + 0.0f;

          }

          if (*(u32 *)(puVar8 + 0x2e) < *(u32 *)(puVar8 + 0x30)) {

            *(u32 *)(puVar8 + 0x2e) = *(u32 *)(puVar8 + 0x2e) + iVar10;

          }

          else {

            *(float *)(puVar8 + 2) = fStack_18;

            *(float *)(puVar8 + 4) = fStack_14;

            *(float *)(puVar8 + 6) = fStack_10;

            *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffffe;

          }

        }

        FUN_003b7460(puVar8,puVar8 + 2,0,0);

      }

      else if (cVar9 == '\x02') {

        FUN_003bc220_scene_typed((char *)*(u32 *)(puVar8 + 0x2a),*(float *)(puVar8 + 0x2e),
                     *(float *)(puVar8 + 0x30),&uStack_58,&uStack_68);

        if (*(float *)(puVar8 + 0x30) <= *(float *)(puVar8 + 0x2e)) {

          if ((*(u32 *)(puVar8 + 0x14) & 0x40) == 0) {

            *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xfffffffe;

          }

          else {

            *(float *)(puVar8 + 0x2e) = *(float *)(puVar8 + 0x2e) - *(float *)(puVar8 + 0x30);

          }

        }

        *(u32 *)(puVar8 + 2) = uStack_58;

        *(u32 *)(puVar8 + 4) = uStack_54;

        *(u32 *)(puVar8 + 6) = uStack_50;

        for (iVar6 = 0; iVar6 < iVar10; iVar6 = iVar6 + 1) {

          *(float *)(puVar8 + 0x2e) = *(float *)(puVar8 + 0x2e) + *(float *)(puVar8 + 0x2c);

        }

        FUN_003b7460(puVar8,0,puVar8 + 8,0);

        if ((*(u32 *)(puVar8 + 0x14) & 8) == 0) {

          *(u32 *)(puVar8 + 8) = uStack_68;

          *(u32 *)(puVar8 + 10) = uStack_64;

          *(u32 *)(puVar8 + 0xc) = uStack_60;

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

        FUN_003bbaa0(puVar8 + 0x32,puVar8 + 0x38,&fStack_78);

        fVar11 = (float)*(u32 *)(puVar8 + 0x40);

        fStack_74 = fStack_74 / fVar11;

        switch(*(u8 *)((int)puVar8 + 0x7d)) {

        case 0:

          uVar1 = *(u32 *)(puVar8 + 0x42);

          fStack_88 = (fStack_78 / fVar11) * (float)uVar1 + *(float *)(puVar8 + 0x32) + 0.0f;

          fStack_84 = fStack_74 * (float)uVar1 + *(float *)(puVar8 + 0x34) + 0.0f;

          fStack_80 = (fStack_70 / fVar11) * (float)uVar1 + *(float *)(puVar8 + 0x36) + 0.0f;

          break;

        case 1:

        case 2:

        case 3:

        case 4:

        case 5:

          fVar12 = (float)FUN_003bbed0_scene_typed((float)*(u32 *)(puVar8 + 0x40),

                                       (float)*(u32 *)(puVar8 + 0x42),

                                       *(u8 *)((int)puVar8 + 0x7d));

          fStack_88 = (fStack_78 / fVar11) * fVar12 + *(float *)(puVar8 + 0x32) + 0.0f;

          fStack_84 = fStack_74 * fVar12 + *(float *)(puVar8 + 0x34) + 0.0f;

          fStack_80 = (fStack_70 / fVar11) * fVar12 + *(float *)(puVar8 + 0x36) + 0.0f;

        }

        *(float *)(puVar8 + 8) = fStack_88;

        *(float *)(puVar8 + 10) = fStack_84;

        *(float *)(puVar8 + 0xc) = fStack_80;

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

    FUN_003bb9b0(puVar8 + 8);

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

             *(float *)(puVar8 + 0x44) + 0.0f;

        *(float *)(puVar8 + 0x10) =

             ((*(float *)(puVar8 + 0x4c) - *(float *)(puVar8 + 0x46)) / fVar11) * (float)uVar1 +

             *(float *)(puVar8 + 0x46) + 0.0f;

        *(float *)(puVar8 + 0x12) =

             ((*(float *)(puVar8 + 0x4e) - *(float *)(puVar8 + 0x48)) / fVar11) * (float)uVar1 +

             *(float *)(puVar8 + 0x48) + 0.0f;

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

                 * (float)*(u32 *)(puVar8 + 0x5e) + (float)(u8)puVar8[0x5a] + 0.0f;

        if (2147483648.0f <= fVar11) {

          fVar11 = fVar11 - 2147483648.0f;

        }

        cVar9 = (char)(int)fVar11;

        *(int *)(puVar8 + 0x5e) = *(int *)(puVar8 + 0x5e) + iVar10;

      }

      else {

        cVar9 = *(char *)((int)puVar8 + 0xb5);

        *(u32 *)(puVar8 + 0x14) = uVar1 & 0xffffbfff;

      }

      iVar6 = (int)(*puVar8 & 0xffc00) >> 10;

      if (iVar6 == 6) {

        FUN_00350040(*(u32 *)(puVar8 + 0x82),auStack_8);

        cStack_5 = cVar9;

        FUN_0034ff90(*(u32 *)(puVar8 + 0x82),auStack_8);

      }

      else if (iVar6 == 3) {

        puVar4 = (u8 *)FUN_00318b00(*(u32 *)(puVar8 + 0x94));

        uStack_4 = *puVar4;

        uStack_3 = puVar4[1];

        uStack_2 = puVar4[2];

        cStack_1 = cVar9;

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

        FUN_00318ad0(*(u32 *)(puVar8 + 0x94),&uStack_4);

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

             + *(float *)(puVar8 + 0x62) + 0.0f;

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

        FUN_003b8ff0(*(u32 *)(puVar5 + 10),param_1,*(int *)puVar5,*(u32 *)(puVar5 + 2)

                     ,*(u32 *)(puVar5 + 4),*(u32 *)(puVar5 + 6),

                     *(u32 *)(puVar5 + 8));

        *(u32 *)(puVar8 + 0x14) = *(u32 *)(puVar8 + 0x14) & 0xffffdfff;

      }

    }

    puVar5 = puVar8 + 0x54;

    cVar9 = (char)puVar8[0x54];

    if ((cVar9 == '\x02') || (cVar9 == '\x01')) {

      if (cVar9 == '\x01') {

        if ((*(u32 *)(puVar8 + 0x14) & 1) == 0) {

          *(u8 *)puVar5 = 0;

          sVar3 = FUN_003baa70(puVar8 + 2);

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

          sVar3 = FUN_003baa70(puVar8 + 2);

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

            sVar3 = FUN_003baa70(puVar8 + 2);

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
// FUN_003BAA70 NONMATCHING


u32 FUN_003baa70(char *param_1)



{

  int iVar1;

  long lVar2;

  u32 uVar3;

  u32 uVar4;

  float fVar5;

  u64 uStack_20;

  u32 uStack_18;

  int iStack_10;

  int iStack_c;

  int iStack_8;

  

  iVar1 = FUN_003b5d50(0x15);

  uVar4 = *puGpffffa850;

  uVar3 = puGpffffa850[1];

  if (((0x13 < uVar4) && (uVar4 < 0x1d)) && (0x31 < uVar3)) {

    uVar3 = uVar3 - 0x31;

  }

  if (*(int *)(&DAT_0067ef00 + uVar4 * 4) != 0) {

    uVar4 = (u32)*(u8 *)(*(int *)(&DAT_0067ef00 + uVar4 * 4) + uVar3);

    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xf8)) {

      uStack_20 = DAT_006a2da0;

      uStack_18 = DAT_006a2da8;

      iStack_10 = iVar1 + 0x11c;

      iStack_c = iVar1 + 0x128;

      iStack_8 = iVar1 + 0x134;

      lVar2 = FUN_001aaad0(param_1,&iStack_10,&uStack_20);

      if (lVar2 == 1) {

        fVar5 = *(float *)((int)param_1 + 4);

        if ((fVar5 < *(float *)(iStack_10 + 4) + 100.0f) &&

           (*(float *)(iStack_10 + 4) - 100.0f < fVar5)) {

          return *(u32 *)(iVar1 + 0x14c);

        }

      }

      iStack_10 = iVar1 + 0x128;

      iStack_c = iVar1 + 0x134;

      iStack_8 = iVar1 + 0x140;

      lVar2 = FUN_001aaad0(param_1,&iStack_10,&uStack_20);

      if (lVar2 == 1) {

        fVar5 = *(float *)((int)param_1 + 4);

        if ((fVar5 < *(float *)(iStack_10 + 4) + 100.0f) &&

           (*(float *)(iStack_10 + 4) - 100.0f < fVar5)) {

          return *(u32 *)(iVar1 + 0x14c);

        }

      }

    }

  }

  else {

    uVar4 = 0;

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
// FUN_003BB450 NONMATCHING


void FUN_003bb450(float param_1,u32 param_2,u32 param_3,u32 param_4,

                 float *param_5,float *param_6)



{

  float fVar1;

  float fVar2;

  u32 uStack_b0;

  u32 uStack_ac;

  u32 uStack_a8;

  u32 uStack_a4;

  u32 uStack_a0;

  u32 uStack_9c;

  u32 uStack_98;

  u32 uStack_90;

  u32 uStack_8c;

  u32 uStack_88;

  u32 uStack_80;

  u32 uStack_7c;

  u32 uStack_78;

  u64 uStack_70;

  u32 uStack_68;

  u64 uStack_60;

  u32 uStack_58;

  u64 uStack_50;

  u32 uStack_48;

  float fStack_20;

  float fStack_1c;

  float fStack_18;

  u64 uStack_10;

  u32 uStack_8;

  

  uStack_10 = DAT_006a2ed8;

  uStack_8 = DAT_006a2ee0;

  uStack_50 = DAT_006a2ee8;

  uStack_48 = DAT_006a2ef0;

  uStack_60 = DAT_006a2ef8;

  uStack_58 = DAT_006a2f00;

  uStack_70 = DAT_006a2f08;

  uStack_68 = DAT_006a2f10;

  uStack_88 = 0x3f800000;

  uStack_9c = 0x3f800000;

  uStack_b0 = 0x3f800000;

  uStack_a0 = 0;

  uStack_a8 = 0;

  uStack_ac = 0;

  uStack_8c = 0;

  uStack_90 = 0;

  uStack_98 = 0;

  uStack_78 = 0;

  uStack_7c = 0;

  uStack_80 = 0;

  uStack_a4 = uStack_a4 | 0x20003;

  FUN_004c31b0(param_3,&uStack_b0,&uStack_60,1);

  FUN_004c31b0(param_2,&uStack_b0,&uStack_50,1);

  FUN_004c31b0(param_4,&uStack_b0,&uStack_70,1);

  FUN_004c6c60(&fStack_20,&uStack_10,&uStack_b0);

  fVar1 = param_5[1];

  fVar2 = param_5[2];

  *param_6 = (*param_5 + 0.0f) - fStack_20 * param_1;

  param_6[1] = (fVar1 + 0.0f) - fStack_1c * param_1;

  param_6[2] = (fVar2 + 0.0f) - fStack_18 * param_1;

  return;

}
#define FUN_003bb450(...) ((void (*)(...))FUN_003bb450)(__VA_ARGS__)
#undef FUN_003bb620
// FUN_003BB620 NONMATCHING


void FUN_003bb620(u32 param_1,u32 *param_2,int param_3)



{

  u32 uVar1;

  u32 uVar2;

  long lVar3;

  int iVar4;

  u64 *puVar5;

  u32 *puVar6;

  u32 auStack_d0 [16];

  u64 uStack_90;

  u32 uStack_88;

  float afStack_50 [2];

  float fStack_48;

  u64 uStack_40;

  u32 uStack_38;

  u32 uStack_30;

  u32 uStack_2c;

  u32 uStack_28;

  u32 uStack_20;

  u32 uStack_1c;

  u32 uStack_18;

  float fStack_10;

  u32 uStack_c;

  float fStack_8;

  

  fStack_10 = *(float *)(param_3 + 4);

  uStack_c = *(u32 *)(param_3 + 8);

  fStack_8 = *(float *)(param_3 + 0xc);

  uStack_20 = *(u32 *)(param_3 + 0x10);

  uStack_1c = *(u32 *)(param_3 + 0x14);

  uStack_18 = *(u32 *)(param_3 + 0x18);

  if ((*(short *)(param_3 + 0x10c) != 0) && (lVar3 = FUN_003b5d10(), lVar3 != 0)) {

    iVar4 = (int)lVar3;

    fStack_10 = *(float *)(iVar4 + 4);

    uStack_c = *(u32 *)(iVar4 + 8);

    fStack_8 = *(float *)(iVar4 + 0xc);

    param_1 = *(u32 *)(param_3 + 0x104);

    FUN_003b79a0(auStack_d0,&fStack_10,&uStack_20);

    puVar6 = auStack_d0;

    puVar5 = &uStack_90;

    iVar4 = 8;

    do {

      uVar1 = *puVar6;

      uVar2 = puVar6[1];

      puVar6 = puVar6 + 2;

      iVar4 = iVar4 + -1;

      *(u32 *)puVar5 = uVar1;

      *(u32 *)((int)puVar5 + 4) = uVar2;

      puVar5 = puVar5 + 1;

    } while (0 < iVar4);

    uStack_40 = uStack_90;

    uStack_38 = uStack_88;

    FUN_004c69f0(afStack_50,&uStack_40);

    fStack_10 = (fStack_10 + 0.0f) - afStack_50[0] * 15.0f;

    fStack_8 = (fStack_8 + 0.0f) - fStack_48 * 15.0f;

  }

  FUN_003bb450(param_1,uStack_20,uStack_1c,uStack_18,&fStack_10,&uStack_30);

  *param_2 = uStack_30;

  param_2[1] = uStack_2c;

  param_2[2] = uStack_28;

  return;

}
#define FUN_003bb620(...) ((void (*)(...))FUN_003bb620)(__VA_ARGS__)
#undef FUN_003bb7a0
// FUN_003BB7A0 NONMATCHING


void FUN_003bb7a0(Resrc* param_1)



{

  int iVar1;

  long lVar2;

  u32 *puVar3;

  long lVar4;

  int iVar6;

  u32 uStack_58;

  u32 uStack_54;

  u32 uStack_50;

  u32 uStack_48;

  u32 uStack_44;

  u64 uStack_40;

  u32 uStack_38;

  u64 uStack_30;

  u32 uStack_28;

  u64 uStack_20;

  u32 uStack_18;

  u32 uStack_10;

  u32 uStack_c;

  u32 uStack_8;

  u64 uVar5;

  

  lVar4 = FUN_00198590();

  uStack_20 = DAT_006a2f18;

  uStack_18 = DAT_006a2f20;

  uStack_30 = DAT_006a2f28;

  uStack_28 = DAT_006a2f30;

  uStack_40 = DAT_006a2f38;

  uStack_38 = DAT_006a2f40;

  iVar1 = *(int *)((int)lVar4 + 4);

  if (((param_1 != 0) && (lVar4 != 0)) && (iVar1 != 0)) {

    FUN_003bb620(0,&uStack_10,param_1);

    iVar6 = (int)param_1;

    *(u32 *)(iVar6 + 4) = uStack_10;

    *(u32 *)(iVar6 + 8) = uStack_c;

    *(u32 *)(iVar6 + 0xc) = uStack_8;

    uVar5 = FUN_004c38c0();

    puVar3 = (u32 *)uVar5;

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

    FUN_004c31b0(*(u32 *)(iVar6 + 0x14),uVar5,&uStack_20,1);

    FUN_004c31b0(*(u32 *)(iVar6 + 0x10),uVar5,&uStack_30,1);

    FUN_004c31b0(*(u32 *)(iVar6 + 0x18),uVar5,&uStack_40,1);

    FUN_004c35d0(uVar5,&uStack_10,2);

    lVar2 = FUN_003bc900(&uStack_48);

    if (lVar2 == 1) {

      uStack_58 = uStack_48;

      uStack_54 = uStack_44;

      uStack_50 = 0;

      FUN_004c35d0(uVar5,&uStack_58);

    }

    FUN_004cb930(iVar1);

    FUN_004cb7f0(iVar1,uVar5,0);

    FUN_004c3880(uVar5);

    FUN_001a4580(*(u32 *)(iVar6 + 0x100),lVar4);

  }

  return;

}
#define FUN_003bb7a0(...) ((void (*)(...))FUN_003bb7a0)(__VA_ARGS__)
#undef FUN_003bb9b0
#pragma push
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
// FUN_003BBAA0 NONMATCHING


void FUN_003bbaa0(float *param_1,float *param_2,float *param_3)



{

  int iVar1;

  float fVar2;

  float afStack_20 [4];

  float fStack_10;

  float fStack_c;

  float fStack_8;

  

  fStack_10 = *param_2 - *param_1;

  fStack_c = param_2[1] - param_1[1];

  fStack_8 = param_2[2] - param_1[2];

  FUN_003bb9b0_scene_typed(&fStack_10);

  afStack_20[0] = fStack_10;

  afStack_20[1] = fStack_c;

  afStack_20[2] = fStack_8;

  for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {

    fVar2 = afStack_20[iVar1];

    if (180.0f < fVar2) {

      afStack_20[iVar1] = -(360.0f - fVar2);

    }

  }

  *param_3 = afStack_20[0];

  param_3[1] = afStack_20[1];

  param_3[2] = afStack_20[2];

  return;

}
#define FUN_003bbaa0(...) ((void (*)(...))FUN_003bbaa0)(__VA_ARGS__)
#undef FUN_003bbb90
// FUN_003BBB90 NONMATCHING


void FUN_003bbb90(const float *param_1,float *param_2)
{
  u32 uVar1;
  float fVar2;
  float afStack_20 [4];
  SceneVecBits source;

  source = DAT_006a2f48_abs[0];
  fVar2 = FUN_004c69f0_scene_typed(afStack_20,param_1);
  if (fVar2 == 0.0f) {
    param_2[0] = 0.0f;
    param_2[1] = 0.0f;
    param_2[2] = 0.0f;
  }
  else {
    afStack_20[1] = 0.0f;
    uVar1 = FUN_00530da0_scene(afStack_20[2] * source.value[2] +
                         afStack_20[0] * source.value[0] +
                         afStack_20[1] * source.value[1]);
    uVar1 = FUN_0052e9a0_scene_typed(uVar1);
    fVar2 = FUN_005318a0_scene_typed(uVar1);
    fVar2 = fGpffff8228 * fVar2;
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
// FUN_003BBC90 NONMATCHING


void FUN_003bbc90(float param_1,float *param_2,float *param_3,float *param_4,float *param_5,

                 float *param_6,float *param_7)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  

  fVar8 = 1.0f - param_1;

  fVar11 = fVar8 * fVar8 * fVar8;

  fVar9 = param_1 * fVar8 * fVar8 * 3.0f;

  fVar10 = fVar8 * 3.0f * param_1 * param_1;

  param_1 = param_1 * param_1 * param_1;

  fVar8 = *param_3;

  fVar1 = param_3[1];

  fVar2 = param_3[2];

  fVar3 = param_3[3];

  fVar4 = *param_4;

  fVar5 = param_4[1];

  fVar6 = param_4[2];

  fVar7 = param_4[3];

  *param_5 = *param_2 * fVar11 + param_2[1] * fVar9 + param_2[2] * fVar10 + param_2[3] * param_1;

  *param_6 = fVar8 * fVar11 + fVar1 * fVar9 + fVar2 * fVar10 + fVar3 * param_1;

  *param_7 = fVar4 * fVar11 + fVar5 * fVar9 + fVar6 * fVar10 + fVar7 * param_1;

  return;

}
#define FUN_003bbc90(...) ((void (*)(...))FUN_003bbc90)(__VA_ARGS__)
#undef FUN_003bbd40
// FUN_003BBD40 NONMATCHING


void FUN_003bbd40(float param_1,char *param_2,float *param_3)



{

  char cVar1;

  int iVar2;

  int iVar3;


  float fVar5;

  float auStack_10 [4];

  float auStack_20 [4];

  float auStack_30 [4];

  

  cVar1 = *param_2;

  if ('\0' < cVar1) {


    if (!(param_1 < 1.0f)) {

      for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

        iVar2 = iVar3 * 0xc + (cVar1 + -1) * 0x24;

        auStack_10[iVar3] = *(float *)(param_2 + iVar2 + 4);

        auStack_20[iVar3] = *(float *)(param_2 + iVar2 + 8);

        auStack_30[iVar3] = *(float *)(param_2 + iVar2 + 0xc);

      }

      FUN_003bbc90_scene_typed(1.0f,auStack_10,auStack_20,auStack_30,param_3,param_3 + 1,param_3 + 2);

    }

    else {

      fVar5 = 1.0f / (float)(int)cVar1;

      for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

        iVar2 = iVar3 * 0xc + (int)(param_1 / fVar5) * 0x24;

        auStack_10[iVar3] = *(float *)(param_2 + iVar2 + 4);

        auStack_20[iVar3] = *(float *)(param_2 + iVar2 + 8);

        auStack_30[iVar3] = *(float *)(param_2 + iVar2 + 0xc);

      }

      while (param_1 >= fVar5) {

        param_1 = param_1 - fVar5;

      }

      FUN_003bbc90_scene_typed(param_1 / fVar5,auStack_10,auStack_20,auStack_30,param_3,param_3 + 1,param_3 + 2);

    }

  }

  return;

}
#define FUN_003bbd40(...) ((void (*)(...))FUN_003bbd40)(__VA_ARGS__)
#undef FUN_003bbed0
// FUN_003BBED0 NONMATCHING


float FUN_003bbed0(float param_1,float param_2,u32 param_3)
{
  float *pfVar1;
  u8 auStack[0x138];

  if (5 < param_3) {
    FUN_0019d3f0("mt_sceneFunc.c",0x980);
  }
  if (param_1 == 0.0f) {
    param_2 = 1.0f;
  }
  else {
    param_2 = param_2 / param_1;
  }
  pfVar1 = (float *)FUN_003b55b0(param_3);
  auStack[0] = 1;
  *(u32 *)(auStack + 4) = 0;
  *(u32 *)(auStack + 8) = 0;
  *(u32 *)(auStack + 0xc) = 0;
  *(float *)(auStack + 0x10) = pfVar1[0];
  *(float *)(auStack + 0x14) = pfVar1[2];
  *(u32 *)(auStack + 0x18) = 0;
  *(float *)(auStack + 0x1c) = pfVar1[1];
  *(float *)(auStack + 0x20) = pfVar1[3];
  *(u32 *)(auStack + 0x24) = 0;
  *(u32 *)(auStack + 0x28) = 0x3f800000;
  *(u32 *)(auStack + 0x2c) = 0x3f800000;
  *(u32 *)(auStack + 0x30) = 0;
  FUN_003bbd40_scene_typed(param_2,auStack,(float *)(auStack + 0x130));
  return *(float *)(auStack + 0x134) * param_1;
}
#define FUN_003bbed0(...) ((float (*)(...))FUN_003bbed0)(__VA_ARGS__)
#undef FUN_003bbfd0
// FUN_003BBFD0 NONMATCHING

void FUN_003bbfd0(float param_1,float param_2,float *param_3,float *param_4,
                  float *param_5,float *param_6,float *param_7)
{
  RwV3d delta;
  float first_x;
  float second_x;
  float first_y;
  float second_y;
  float first_z;
  float second_z;

  FUN_003bbc90_scene_typed(param_1,param_3,param_4,param_5,&first_x,&first_y,&first_z);
  FUN_003bbc90_scene_typed(param_2,param_3,param_4,param_5,&second_x,&second_y,&second_z);
  delta.x = second_x - first_x;
  delta.y = second_y - first_y;
  delta.z = second_z - first_z;
  FUN_004c6ac0_scene_vec(&delta);
  *param_6 = first_x;
  param_6[1] = first_y;
  param_6[2] = first_z;
  *param_7 = second_x;
  param_7[1] = second_y;
  param_7[2] = second_z;
  return;
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

  float fStack_b8;

  float fStack_b4;

  float fStack_b0;

  float fStack_a8;

  float fStack_a4;

  float fStack_a0;

  float fStack_98;

  float fStack_94;

  float fStack_90;

  u8 auStack_88 [16];

  float fStack_78;

  float fStack_74;

  float fStack_70;

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

        fStack_a8 = fStack_20 - fStack_1c;

        fStack_a4 = fStack_28 - fStack_24;

        fStack_a0 = fStack_30 - fStack_2c;

        fVar5 = (float)FUN_004c6ac0(&fStack_a8);

        fStack_58 = fStack_20;

        fStack_54 = fStack_28;

        fStack_50 = fStack_30;

        fVar8 = fVar8 + fVar5;

        if (param_2 <= fVar8) {
          fVar8 = 1.0f - (fVar8 - param_2) / fVar5;

          fStack_68 = fStack_20 - fStack_1c;

          fStack_64 = fStack_28 - fStack_24;

          fStack_60 = fStack_30 - fStack_2c;

          *param_4 = fStack_68 * fVar8 + fStack_1c + 0.0f;

          param_4[1] = fStack_64 * fVar8 + fStack_24 + 0.0f;

          param_4[2] = fStack_60 * fVar8 + fStack_2c + 0.0f;

          fVar9 = fVar9 + fVar6 * fVar8;

          FUN_003bbc90_scene_typed(fVar9,auStack_d0,auStack_e0,auStack_f0,&fStack_34,&fStack_3c,&fStack_44);

          FUN_003bbc90_scene_typed(fVar9 - DAT_007caf1c,auStack_d0,auStack_e0,auStack_f0,&fStack_38,&fStack_40,

                       &fStack_48);

          fStack_b8 = fStack_38 - fStack_34;

          fStack_b4 = fStack_40 - fStack_3c;

          fStack_b0 = fStack_48 - fStack_44;

          FUN_004c6ac0(&fStack_b8);

          fStack_78 = fStack_34 - fStack_38;

          fStack_74 = fStack_3c - fStack_40;

          fStack_70 = fStack_44 - fStack_48;

          FUN_004c69f0(auStack_88,&fStack_78);

          FUN_003bbb90(auStack_88,param_5);

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

    FUN_003bbc90(DAT_007caea4,auStack_d0,auStack_e0,auStack_f0,&fStack_4,&fStack_c,&fStack_14);

    FUN_003bbc90(0x3f800000,auStack_d0,auStack_e0,auStack_f0,&fStack_8,&fStack_10,&fStack_18);

    fStack_98 = fStack_8 - fStack_4;

    fStack_94 = fStack_10 - fStack_c;

    fStack_90 = fStack_18 - fStack_14;

    FUN_004c6ac0(&fStack_98);

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

    FUN_003bbb90(auStack_88,param_5);

    fVar6 = 1.0f;

  }

  return fVar6;

}
#define FUN_003bc220(...) ((float (*)(...))FUN_003bc220)(__VA_ARGS__)
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
#pragma optimization_level 1
#undef FUN_003bc900
// FUN_003BC900


u8 FUN_003bc900(float *param_1)



{

  if (*(u16 *)&DAT_007ce658 == 0) {
    return 0;
  }
  param_1[0] = *(volatile float *)(uintptr_t)0x0095aff0;
  param_1[1] = *(volatile float *)(uintptr_t)0x0095aff4;
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

  

  afStack_10[0] = DAT_007cd560;

  afStack_10[1] = (float)DAT_007cd564;

  if (DAT_007ce658 == 0) {

    DAT_0095aff0 = 0;

    DAT_0095aff4 = 0;

    DAT_0095aff8 = 0;

    DAT_0095affc = 0;

  }

  else if (DAT_007ce65c == 0) {

    DAT_007ce658 = 0;

  }

  else {

    afStack_10[2] = DAT_007cada0 * (float)DAT_007ce660;

    afStack_10[3] = DAT_007cada0 * (float)DAT_007ce664;

    for (iVar1 = 0; iVar1 < 2; iVar1 = iVar1 + 1) {

      fVar6 = afStack_10[iVar1 + 2];

      if (fVar6 != 0.0f) {

        fVar3 = (float)FUN_00358030(0);

        fVar4 = afStack_10[iVar1 + 2];

        fVar5 = fVar4 * 0.5f + fVar4 * fVar3 * 0.5f;

        pfVar2 = (float *)(&DAT_0095aff0 + iVar1);

        fVar3 = *pfVar2;

        if (fVar4 * afStack_10[iVar1] <= ABS(fVar3)) {

          if (fVar3 <= 0.0f) {

            *pfVar2 = fVar3 + fVar5;

          }

          else {

            *pfVar2 = fVar3 - fVar5;

          }

        }

        else {

          fVar3 = (float)FUN_00358030(0);

          *pfVar2 = fVar5 * (fVar3 - 0.5f) * 2.0f + *pfVar2 + 0.0f;

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

      DAT_007ce660 = DAT_007ce660 - (short)((int)(u32)DAT_007ce660 / (DAT_007ce65c + 5));

      DAT_007ce664 = DAT_007ce664 - (short)((int)(u32)DAT_007ce664 / (DAT_007ce65c + 5));

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
#undef FUN_003bcda0
// FUN_003BCDA0 NONMATCHING


int FUN_003bcda0(int *param_1,int *param_2)
{
  int matrix;
  int second;
  RwV3d origin;
  RwV3d first;
  RwV3d secondPos;
  RwV3d firstDelta;
  RwV3d secondDelta;

  matrix = FUN_00198590();
  matrix = FUN_004cb2f0(*(u32 *)(matrix + 4));
  origin.x = *(float *)(matrix + 0x30);
  origin.y = *(float *)(matrix + 0x34);
  origin.z = *(float *)(matrix + 0x38);

  second = *param_2;
  FUN_0034ffc0(*(u32 *)(*param_1 + 0x104),&secondPos);
  FUN_0034ffc0(*(u32 *)(second + 0x104),&first);

  firstDelta.x = first.x - origin.x;
  firstDelta.y = first.y - origin.y;
  firstDelta.z = first.z - origin.z;
  secondDelta.x = secondPos.x - origin.x;
  secondDelta.y = secondPos.y - origin.y;
  secondDelta.z = secondPos.z - origin.z;

  return (int)(FUN_004c6ac0(&firstDelta) - FUN_004c6ac0(&secondDelta));
}
#define FUN_003bcda0(...) ((int (*)(...))FUN_003bcda0)(__VA_ARGS__)
#undef FUN_003bceb0
// FUN_003BCEB0 NONMATCHING


void FUN_003bceb0(int param_1)



{

  u32 uVar1;

  int iVar2;

  int iVar3;

  

  iVar3 = 0;

  for (iVar2 = param_1; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xf8)) {

    if ((((*(u32 *)(iVar2 + 0x28) & 2) != 0) && (*(int *)(iVar2 + 0x104) != 0)) &&

       (*(char *)(iVar2 + 0x100) == '\0')) {

      iVar3 = iVar3 + 1;

    }

  }

  uVar1 = (*DAT_00960178)(iVar3 << 2,0x40000);

  iVar2 = 0;

  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0xf8)) {

    if ((((*(u32 *)(param_1 + 0x28) & 2) != 0) && (*(int *)(param_1 + 0x104) != 0)) &&

       (*(char *)(param_1 + 0x100) == '\0')) {

      *(int *)((int)uVar1 + iVar2 * 4) = param_1;

      iVar2 = iVar2 + 1;

    }

  }

  FUN_005225f8(uVar1,iVar3,4,0x3bcda0);

  for (iVar2 = 0; iVar2 < iVar3; iVar2 = iVar2 + 1) {

    FUN_0034fd70((Model *)*(u32 *)(*(int *)((int)uVar1 + iVar2 * 4) + 0x104),3);

  }

  (*DAT_0096017c)(uVar1);

  return;

}
#define FUN_003bceb0(...) ((void (*)(...))FUN_003bceb0)(__VA_ARGS__)
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
      asm volatile("" : "+m"(*ppVar2));

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
// FUN_003BD8B0 NONMATCHING


u32 FUN_003bd8b0(u32 param_1,u32 param_2,u32 param_3)



{

  u32 uVar1;

  u16 *puVar2;

  int iVar3;

  

  iVar3 = 0;

  do {

    if (DAT_0095b720 <= iVar3) {

      if (((int)param_1 < 0) || (499 < (int)param_1)) {
        if (((int)param_1 < 0x3de) || (999 < (int)param_1)) {

          uVar1 = 0xffffffff;

        }

        else {

          uVar1 = 0;

        }

      }

      else {

        uVar1 = 0;

      }

      return uVar1;

    }

    puVar2 = (u16 *)(DAT_0095b71c + iVar3 * 6);

    if (*(u8 *)((int)puVar2 + 3) == 0xff) {

      if ((param_1 == *puVar2) && (param_2 == (u8)puVar2[1])) {

        return (u32)(u8)puVar2[2];

      }

    }

    else if (((param_1 == *puVar2) && (param_2 == (u8)puVar2[1])) &&

            (param_3 == *(u8 *)((int)puVar2 + 3))) {

      return (u32)(u8)puVar2[2];

    }

    iVar3 = iVar3 + 1;

  } while( 1 );

}
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
// FUN_003BDA60 NONMATCHING



u32 FUN_003bda60(u32 param_1,u32 param_2,u32 param_3,u32 param_4)



{

  int iVar1;

  long lVar2;

  u8 *pbVar3;

  int iVar4;

  

  iVar1 = DAT_0095b674;

  iVar4 = 0;

  do {

    if (iVar1 <= iVar4) {

      return 0xffffffff;

    }

    pbVar3 = (u8 *)(DAT_0095b670 + iVar4 * 10);

    if ((((param_1 == *pbVar3) && (param_2 == pbVar3[1])) && (param_3 == *(u16 *)(pbVar3 + 2)))

       && (param_4 == pbVar3[4])) {

      if (*(short *)(pbVar3 + 8) == 0) {

        return (u32)*(u16 *)(pbVar3 + 6);

      }

      lVar2 = FUN_003951d0();

      if (lVar2 != 1) {

        return (u32)*(u16 *)(iVar4 * 10 + DAT_0095b670 + 6);

      }

    }

    iVar4 = iVar4 + 1;

  } while( 1 );

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
