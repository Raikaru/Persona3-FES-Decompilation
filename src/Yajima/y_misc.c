#include "Yajima/y_misc.h"
#include "Yajima/y_runtime.h"
#include "temporary.h"
typedef struct YajimaVec2 {
    f32 x;
    f32 y;
} YajimaVec2;
typedef struct YajimaVec3 {
    f32 x;
    f32 y;
    f32 z;
} YajimaVec3;
typedef struct YajimaVec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} YajimaVec4;
typedef struct YajimaColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} YajimaColor;
typedef struct YajimaVec16 {
    f32 lane[16];
} YajimaVec16;
typedef struct YajimaPackedRow {
    u8 pad[0x8c0];
    YajimaVec2 value;
} __attribute__((packed)) YajimaPackedRow;
typedef struct YajimaPackedEntry {
    u8 pad[0x8d8];
    s8 counter;
    u8 pad_8d9[0xe];
    s8 delay;
} __attribute__((packed)) YajimaPackedEntry;
typedef struct YVec3f { f32 x, y, z; } YVec3f;
typedef struct YPositionWork {
    u8 pad_000[4];
    u32 resource;
    u8 pad_008[0xe6];
    s16 counter0;
    u8 pad_0f0[4];
    s16 counter1;
} YPositionWork;
#ifndef Y_MISC_RW_TYPES
#define Y_MISC_RW_TYPES
#ifndef RWPLCORE_H
typedef struct RwV2d { f32 x; f32 y; } RwV2d;
typedef struct RwV3d { f32 x; f32 y; f32 z; } RwV3d;
typedef struct RwV4dTag { f32 x; f32 y; f32 z; f32 w; } RwV4d;
typedef struct RwMatrixTag {
    RwV3d right;
    u32 flags;
    RwV3d up;
    u32 pad1;
    RwV3d at;
    u32 pad2;
    RwV3d pos;
    u32 pad3;
} RwMatrix;
typedef struct RwCamera RwCamera;
typedef struct RwFrame RwFrame;
#endif
#endif
#pragma alias RwCameraBeginUpdate_u32 RwCameraBeginUpdate
extern int RwCameraBeginUpdate_u32(u32 camera);
#pragma alias RwCameraEndUpdate_u32 RwCameraEndUpdate
extern void RwCameraEndUpdate_u32(u32 camera);
#pragma alias RpSkyRenderStateSet_u32 RpSkyRenderStateSet
extern int RpSkyRenderStateSet_u32(int state, u32 param);
RwCamera *RwCameraBeginUpdate(RwCamera *camera);
RwCamera *RwCameraEndUpdate(RwCamera *camera);
extern u32 mdlCreateFromRmdMemory(u32, u32, u32, u32, u32);
extern u32 func_0010c3a0(u32, void *, u32);
#pragma alias mdlCreateFromRmdMemory_ptr mdlCreateFromRmdMemory
extern void *mdlCreateFromRmdMemory_ptr(u32, u32, u32, u32, u32);
#pragma alias func_0010c3a0_ptr func_0010c3a0
extern void *func_0010c3a0_ptr(u32, void *, u32);
typedef int (*code)(...);
char cGpffffb9d4;
char cGpffffb9d8;
char cGpffffb9ec;
int iGpffffb5c0;
int *piGpffffa850;
u8 uGpffffb9ec;
u32 uGpffffb9f4;
extern u8 cGpffffb9c0;
extern u8* iGpffffb9b8;
static inline uintptr_t Yajima_AddOffsetFirst(uintptr_t offset, uintptr_t base)
{
  return offset + base;
}
static inline u32 Yajima_AddIntOffsetFirst(u32 offset, u32 base)
{
  return offset + base;
}
static inline float Yajima_AddFloatFirst(float first, float second)
{
  return first + second;
}
extern f32 sinf(f32 value);
extern f32 FUN_001126b0_y2(u32 param_1);
extern f32 FUN_00112740_y2(u32 param_1);
code DAT_00960178;
#pragma alias DAT_00960178_abs DAT_00960178
extern void *(*DAT_00960178_abs[])(u32, u32);

/* FUSION_EXACT_PROTOS */
u16 func_00170a40(s16 pcId, s16 index);
s16 func_00170ab0(s16 pcId, s16 index);
void func_00170b20(s16 pcId, s16 index, u16 value);
void func_00170b90(s16 pcId, s16 index, u16 value);
s32 func_0016f490(s16 pcId);
u16 datGetEquipmentId(s16 pcId, s32 equipmentIdx);
u32 FUN_00421de0(s8 param_1, s8 param_2, s8 param_3, s8 param_4, s8 param_5);
u32 FUN_00424230(void);
u8 FUN_004242b0(void);
u32 FUN_00424310(void);
u32 FUN_00424370(void);
u32 FUN_004243d0(void);
u32 FUN_00424470(void);
u32 FUN_00424480(void);
u32 FUN_004244a0(void);
u32 FUN_004244e0(void);
u32 FUN_004245c0(void);
u32 FUN_00424730(void);
u32 FUN_00424880(void);
u32 FUN_004249b0(void);
u32 FUN_00424b60(void);
u32 FUN_00424f10(void);
void FUN_00424f80(void);
u32 FUN_00425020(void);
u32 FUN_00425070(void);
u32 FUN_004250b0(void);
u32 FUN_004250e0(void);
u32 FUN_00425190(void);
u32 FUN_00425220(void);
u32 FUN_00425270(void);
u32 FUN_004252a0(void);
u32 FUN_004252d0(void);
u32 FUN_00425320(void);
u32 FUN_00425360(void);
u32 FUN_004253d0(void);
u32 FUN_00425480(void);
u32 FUN_004254c0(void);
u32 FUN_00425530(void);
u32 FUN_00425580(void);
u32 FUN_004255d0(void);
u32 FUN_00425640(void);
u32 FUN_00425690(int param_1);
void FUN_00425ba0(int param_1);
u32 FUN_00425c60(u64 param_1,u8 param_2);
void FUN_00425d10(int param_1,u8 param_2);
void FUN_00425d30(int param_1,u8 param_2,u8 param_3);
u32 FUN_00425d50(s8 param_1,s8 param_2);
void FUN_00426040(int param_1,u8 param_2);
void FUN_00426050(int param_1);
u8 FUN_00426070(int param_1);
u32 * FUN_00426090(void);
u64 FUN_004260a0(int param_1);
void FUN_004264a0(int param_1);
u32 FUN_004264d0(u64 param_1,s8 param_2);
u32 FUN_00426590(int param_1);
void FUN_00427640(int param_1);
u32 FUN_00427670(u32 param_3,u32 param_4, char param_5,u8 param_6, float param_1,float param_2);
#pragma alias FUN_00427670_typed FUN_00427670
extern u32 FUN_00427670_typed(float param_1,float param_2,int param_3,u32 param_4, char param_5,u8 param_6);
u32 FUN_00427830(int param_2, u32 param_3, YajimaVec2 param_4, u32 param_5,
                  float param_1, YajimaVec4 *param_6, YajimaVec4 *param_7, int param_8);
extern u32 FUN_00427830(int param_2, u32 param_3, YajimaVec2 param_4, u32 param_5, float param_1, YajimaVec4 *param_6, YajimaVec4 *param_7, int param_8);
u32 FUN_00427a10(int param_2, u32 param_3, YajimaVec2 param_4, u32 param_5,
                  float param_1, YajimaVec4 *param_6, YajimaVec4 *param_7, int param_8);
extern u32 FUN_00427a10(int param_2, u32 param_3, YajimaVec2 param_4, u32 param_5, float param_1, YajimaVec4 *param_6, YajimaVec4 *param_7, int param_8);
u32 FUN_00427bf0(u32 param_6, u32 param_7, YajimaVec2 param_8, u32 param_9,
                  float param_1, float param_2, float param_3, float param_4,
                  float param_5, YajimaVec4 *param_10);
void FUN_00427db0_y2(int object, YajimaVec2 value);
void FUN_00427de0_y2(int param_1,u8 param_2,u8 param_3,u8 param_4, u8 param_5);
void FUN_00427e20_y2(float param_1,float param_2,int param_3);
void FUN_00427e50_y2(int param_1,u8 param_2);
void FUN_00427e60_y2(int param_1,u8 param_2);
void FUN_00427e70_y2(float param_1,u32 param_4,float param_2,float param_3,int param_5,int param_6, u32 *param_7);
u32 FUN_004281f0(u32 param_1);
void FUN_00429c60(int param_1);
u32 FUN_00429d40(u32 param_1,u64 param_2);
void FUN_00429e80_y2(int param_1,u8 param_2);
void FUN_00429e90(int param_1,u8 param_2);
float FUN_00429ef0(float param_1,char param_2);
float FUN_00429fe0(float param_1,char param_2);
float FUN_0042a0d0(float param_1,float *param_2);
float FUN_0042a180(float param_1,u32 *param_2);
float FUN_0042a230(float param_1,char param_2);
float FUN_0042a310(float param_1,char param_2);
float FUN_0042a3f0(float param_1,float *param_2);
float FUN_0042a4a0(float param_1,u32 *param_2);
void FUN_0042a550(int param_1,u32 param_2,u32 param_3,u32 param_4);
u8 FUN_0042aa40(int param_1,u32 param_2,u32 param_3);
void FUN_0042ac60(int param_1,int param_2);
void FUN_0042adb0(int param_1);
void FUN_0042b050(int param_1);
void FUN_0042b540(int param_1);
u8 FUN_0042ba30(void);
void FUN_0042ba50(u32 param_1);
void FUN_0042bc10(int param_1);
void FUN_0042bd80();
#pragma alias FUN_0042bd80_typed FUN_0042bd80
extern void FUN_0042bd80_typed(u64 param_1);
void FUN_0042bfd0(int param_1);
void FUN_0042c0a0(int param_1,char param_2,short param_3,short param_4,int param_5,int param_6);
void FUN_0042cd80(int param_1);
void FUN_0042cfc0(int param_1,u16 param_2,u16 param_3,int param_4,int param_5);
void FUN_0042dd90(int param_1,short param_2,u16 param_3,int param_4,int param_5);
void FUN_0042ea60(int param_1,u16 param_2,u16 param_3,int param_4,int param_5);
void FUN_0042f440(int param_1,short param_2,short param_3,int param_4,int param_5);
void FUN_0042fd80(float *param_1,int param_2);
#pragma alias FUN_004560d0_typed FUN_004560d0_y2
extern u32 FUN_004560d0_typed(u32 param_1,float param_2,float param_3,float param_4,u32 param_5,u32 param_6);
#pragma alias FUN_00423fe0_vec2 FUN_00423fe0
extern void FUN_00423fe0_vec2(YajimaVec2 *param_1,int param_2,int param_3,int param_4,int param_5,int param_6);
#pragma alias FUN_004c31b0_ymisc FUN_004c31b0_y2
extern void FUN_004c31b0_ymisc(void *matrix,const void *axis,f32 angle,s32 mode);
#pragma alias FUN_004c6be0_ymisc FUN_004c6be0_y2
extern void FUN_004c6be0_ymisc(float *out,const float *in,u32 matrix);
void FUN_004563b0_y2(f32 value, int object);
int FUN_0044f120_y2();
int FUN_0044f170_y2();
extern int FUN_00488f30(void);
extern void FUN_00430780_y2(f32, YajimaVec2, s32, s32, s32);
#pragma alias DAT_006b4470_abs DAT_006b4470
extern char DAT_006b4470_abs[];
/* FUSION_GLOBALS */
u32 DAT_0087190c;
u32 DAT_0095c0e0;
u32 DAT_006b44c0;
u32 DAT_006b44c8;
u32 DAT_006b44d0;
u32 DAT_006b44d8;
u32 DAT_006b44e0;
u32 DAT_006b44e8;
#pragma alias DAT_006b44d0_abs DAT_006b44d0
extern u8 DAT_006b44d0_abs[];
#pragma alias DAT_006b44d8_abs DAT_006b44d8
extern u8 DAT_006b44d8_abs[];
#pragma alias DAT_006b44e0_abs DAT_006b44e0
extern u8 DAT_006b44e0_abs[];
#pragma alias DAT_006b44e8_abs DAT_006b44e8
extern u8 DAT_006b44e8_abs[];
float DAT_007cb134;
float DAT_007cb138;
u32 DAT_007ce0cc;
u8 *DAT_007ce6a8;
u32 DAT_007ce6ac;
u8 DAT_007ce6b0;
u32 DAT_007ce6b4;
u32 DAT_007ce6b8;
u32 DAT_007ce6c4;
u32 DAT_007ce6c8;
u32 DAT_007ce6cc;
u32 DAT_007ce6d0;
u32 DAT_007ce6d4;
#pragma alias DAT_007ce6cc_byte DAT_007ce6cc
#pragma alias DAT_007ce6d0_byte DAT_007ce6d0
#pragma alias DAT_007ce6d4_byte DAT_007ce6d4
extern u8 DAT_007ce6cc_byte;
extern u8 DAT_007ce6d0_byte;
extern u8 DAT_007ce6d4_byte;
u32 DAT_007ce6d8;
u32 DAT_007ce6dc;
u32 DAT_007ce6e4;
u32 DAT_007ce6ec;
#pragma alias DAT_007ce6ec_abs DAT_007ce6ec
extern u32 DAT_007ce6ec_abs;
#pragma alias DAT_0086be00_abs DAT_0086be00
extern u8 DAT_0086be00_abs[];
#pragma alias DAT_0086be04_abs DAT_0086be04
extern u8 DAT_0086be04_abs[];
#pragma alias DAT_0086be0c_abs DAT_0086be0c
extern u8 DAT_0086be0c_abs[];
u32 DAT_007ce6f8;
u16 DAT_007e094c[];
#pragma alias DAT_007e094c_u32 DAT_007e094c
extern u32 DAT_007e094c_u32;
u32 DAT_007e0988;
u32 DAT_0086be00;
u32 DAT_0086be04;
u32 DAT_0086be08;
u32 DAT_0086be0c;
u32 DAT_0086be80;
u32 DAT_0086bf8c;
u32 DAT_0086bf90;
u32 DAT_0086bf94;
u32 DAT_0086e580;
float DAT_0086e684;
#pragma alias DAT_0086e684_abs DAT_0086e684
extern u8 DAT_0086e684_abs[];
u32 DAT_0086e688;
u32 DAT_0086e68c;
extern u8 DAT_0086e6a0[];
u32 DAT_0086e80c;
u32 DAT_0086eda0;
#pragma alias DAT_0086eda0_abs DAT_0086eda0
extern u8 DAT_0086eda0_abs[];
u32 DAT_0086ede8;
u32 DAT_0086edf4;
#pragma alias DAT_0086edf4_abs DAT_0086edf4
extern u8 DAT_0086edf4_abs[];
u32 DAT_0086ef2c;
u32 DAT_008717a0;
#pragma alias DAT_008717a0_unit_rows DAT_008717a0
extern YRuntimeUnitRow DAT_008717a0_unit_rows[];
#pragma alias DAT_008717a0_unit_rows_abs DAT_008717a0
extern YRuntimeUnitRow DAT_008717a0_unit_rows_abs[];
u32 DAT_008717e8_y2[];
#pragma alias DAT_008717e8_abs DAT_008717e8_y2
extern u8 DAT_008717e8_abs[];
#pragma alias DAT_008717e8_ptr DAT_008717e8_y2
extern u32 *DAT_008717e8_ptr;
int DAT_008717f4_y2[];
#pragma alias DAT_008717f4_abs DAT_008717f4_y2
extern u8 DAT_008717f4_abs[];
#pragma alias DAT_008717f4_ptr DAT_008717f4_y2
extern int *DAT_008717f4_ptr;
u32 DAT_00871948;
u32 DAT_008719a8;
u32 DAT_008719b4;
u32 DAT_00871b08;
u32 DAT_00871b68;
u32 DAT_00871b74;
u32 DAT_00871cc8;
u32 DAT_00871d28;
u32 DAT_00871d34;
u32 DAT_00871e88;
#pragma alias DAT_008719a8_abs DAT_008719a8
#pragma alias DAT_008719b4_abs DAT_008719b4
#pragma alias DAT_00871b08_abs DAT_00871b08
#pragma alias DAT_00871b68_abs DAT_00871b68
#pragma alias DAT_00871b74_abs DAT_00871b74
#pragma alias DAT_00871cc8_abs DAT_00871cc8
#pragma alias DAT_00871d28_abs DAT_00871d28
#pragma alias DAT_00871d34_abs DAT_00871d34
#pragma alias DAT_00871e88_abs DAT_00871e88
extern u32 DAT_008719a8_abs[];
extern u32 DAT_008719b4_abs[];
extern u16 DAT_00871b08_abs[];
extern u32 DAT_00871b68_abs[];
extern u32 DAT_00871b74_abs[];
extern u16 DAT_00871cc8_abs[];
extern u32 DAT_00871d28_abs[];
extern u32 DAT_00871d34_abs[];
extern u16 DAT_00871e88_abs[];
u32 DAT_0095be9c;
u32 DAT_0095bea0;
u32 DAT_0095bea4;
u32 DAT_0095bea8;
u32 DAT_0095beac;
u32 DAT_0095beb0;
u32 DAT_0095beb4;
u32 DAT_0095bec0;
#pragma alias DAT_0095bea0_abs DAT_0095bea0
extern u8 DAT_0095bea0_abs[];
#pragma alias DAT_0095bec0_abs DAT_0095bec0
extern u8 DAT_0095bec0_abs[];
u32 DAT_0095bec4;
u32 DAT_0095bec8;
u32 DAT_0095becc;
u32 DAT_0095bed0;
u32 DAT_0095bed4;
u32 DAT_0095bee0;
#pragma alias DAT_0095bee0_abs DAT_0095bee0
extern u8 DAT_0095bee0_abs[];
extern u8 DAT_006b4490[];
extern u8 DAT_006b44b0[];
u32 DAT_0095bfe0;
#pragma alias DAT_0095bfe0_abs DAT_0095bfe0
extern u8 DAT_0095bfe0_abs[];
u8 DAT_0095c100_y2[];
u8 DAT_0095c110[];
u8 DAT_0095c210_y2[];
float DAT_00960088;
#pragma alias DAT_00960088_abs DAT_00960088
extern u8 DAT_00960088_abs[];
code DAT_00960090;
 #pragma alias DAT_00960090_abs DAT_00960090
 extern u8 DAT_00960090_abs[];
code DAT_009600a0;
#pragma alias DAT_009600a0_abs DAT_009600a0
extern u8 DAT_009600a0_abs[];
extern code DAT_0096017c;
 #pragma alias DAT_0096017c_abs DAT_0096017c
extern code DAT_0096017c_abs[];
#pragma alias FUN_004264d0_u32 FUN_004264d0
extern u32 FUN_004264d0_u32(u32 param_1,s8 param_2);
#pragma alias FUN_004d0f00_arg FUN_004d0f00_y2
extern void FUN_004d0f00_arg(u32 param_1);
#pragma alias FUN_00115980_arg FUN_00115980
extern void FUN_00115980_arg(u32 param_1);
#pragma alias FUN_00194b80_u32_y2 FUN_00194b80_y2
extern u32 FUN_00194b80_u32_y2(u32, u32, u8 *, u32 (*)(int), void (*)(int), u32);
#pragma alias FUN_00194b20_u32 FUN_00194b20_y2
extern u32 FUN_00194b20_u32(u32, u8 *, u32, u32 (*)(int), void (*)(int), u32);
code DAT_00960184;
extern char DAT_006b4400[];
extern u8 DAT_006b4430[];
#pragma alias DAT_00960184_abs DAT_00960184
extern code DAT_00960184_abs[];
u32 LAB_00425aec[];
u8 *PTR_DAT_007cd540;
/* FUSION_PROTOS */
#include "sce/eeregs.h"
#include "Kosaka/k_assert.h"

#pragma alias DAT_008717e8_y2 DAT_008717e8
#pragma alias DAT_008717f4_y2 DAT_008717f4
#pragma alias DAT_0095c100_y2 DAT_0095c100
#pragma alias DAT_0095c210_y2 DAT_0095c210
#pragma alias FUN_00194b80_u32_y2 FUN_00194b80_u32
#pragma alias FUN_001126b0_y2 FUN_001126b0
#pragma alias FUN_00112740_y2 FUN_00112740
#pragma alias FUN_001158b0_y2 FUN_001158b0
#pragma alias FUN_00194b20_y2 FUN_00194b20
#pragma alias FUN_00194b80_y2 FUN_00194b80
#pragma alias FUN_003bb010_y2 FUN_003bb010
#pragma alias FUN_004229d0_y2 FUN_004229d0
#pragma alias FUN_00422c10_y2 FUN_00422c10
#pragma alias FUN_00422c30_y2 FUN_00422c30
#pragma alias FUN_00427db0_y2 FUN_00427db0
#pragma alias FUN_00427de0_y2 FUN_00427de0
#pragma alias FUN_00427e20_y2 FUN_00427e20
#pragma alias FUN_00427e50_y2 FUN_00427e50
#pragma alias FUN_00427e60_y2 FUN_00427e60
#pragma alias FUN_00427e70_y2 FUN_00427e70
#pragma alias FUN_00429e80_y2 FUN_00429e80
#pragma alias FUN_004c31b0_y2 FUN_004c31b0
#pragma alias FUN_004c69f0_y2 FUN_004c69f0
#pragma alias FUN_004c6be0_y2 FUN_004c6be0
#pragma alias FUN_004d0f00_y2 FUN_004d0f00
#pragma alias FUN_004d1260_y2 FUN_004d1260
#pragma alias FUN_0044f120_y2 FUN_0044f120
#pragma alias FUN_0044f170_y2 FUN_0044f170
#pragma alias FUN_004352e0_y2 FUN_004352e0
#pragma alias FUN_0043a230_y2 FUN_0043a230
#pragma alias FUN_0043a9d0_y2 FUN_0043a9d0
#pragma alias FUN_0045a280_y2 FUN_0045a280
#pragma alias FUN_0045af40_y2 FUN_0045af40
#pragma alias FUN_00430180_y2 FUN_00430180
#pragma alias FUN_00431110_y2 FUN_00431110
#pragma alias FUN_00447e70_y2 FUN_00447e70
#pragma alias FUN_004560d0_y2 FUN_004560d0
#pragma alias FUN_00435260_y2 FUN_00435260
#pragma alias FUN_004353f0_y2 FUN_004353f0
#pragma alias FUN_0043c730_y2 FUN_0043c730
#pragma alias FUN_0045a3b0_y2 FUN_0045a3b0
#pragma alias FUN_00430220_y2 FUN_00430220
#pragma alias FUN_00430270_y2 FUN_00430270
#pragma alias FUN_004302a0_y2 FUN_004302a0
#pragma alias FUN_00430630_y2 FUN_00430630
#pragma alias FUN_00430780_y2 FUN_00430780
#pragma alias FUN_00430a40_y2 FUN_00430a40
#pragma alias FUN_00449fa0_y2 FUN_00449fa0
#pragma alias FUN_004561d0_y2 FUN_004561d0
#pragma alias FUN_004563b0_y2 FUN_004563b0
#pragma alias FUN_004563c0_y2 FUN_004563c0
#pragma alias FUN_004563d0_y2 FUN_004563d0
#pragma alias FUN_00456400_y2 FUN_00456400
#pragma alias FUN_00456450_y2 FUN_00456450
#pragma alias FUN_00456490_y2 FUN_00456490
#pragma alias FUN_00458850_y2 FUN_00458850
#pragma alias FUN_0045a3e0_y2 FUN_0045a3e0
#pragma alias FUN_0045a430_y2 FUN_0045a430
#pragma alias prologue_y2 prologue
#pragma alias DAT_007e094e_y2 DAT_007e094e_y2
#pragma alias DAT_007e0958_y2 DAT_007e0958_y2
#pragma alias DAT_0095c110_y2 DAT_0095c110_y2
#pragma alias DAT_00960088_y2 DAT_00960088_y2
#pragma alias fGpffff8110_y2 fGpffff8110_y2
#pragma alias fGpffff8248_y2 fGpffff8248_y2
#pragma alias FUN_00194b20_u32_y2 FUN_00194b20_u32_y2
#pragma alias FUN_00423fe0_y2 FUN_00423fe0_y2
#pragma alias FUN_00427830_y2 FUN_00427830_y2
#pragma alias FUN_00427a10_y2 FUN_00427a10_y2
#pragma alias FUN_004c3880_y2 FUN_004c3880_y2
#pragma alias FUN_004c38c0_y2 FUN_004c38c0_y2
#pragma alias FUN_00433810_y2 FUN_00433810_y2
#pragma alias FUN_004944b0_y2 FUN_004944b0_y2
#pragma alias FUN_0049c3d0_y2 FUN_0049c3d0_y2
#pragma alias FUN_0049c480_y2 FUN_0049c480_y2
#pragma alias FUN_004c2f30_y2 FUN_004c2f30_y2
#pragma alias FUN_004c32a0_y2 FUN_004c32a0_y2
#pragma alias FUN_004c35d0_y2 FUN_004c35d0_y2
#pragma alias FUN_004c6c60_y2 FUN_004c6c60_y2
#pragma alias FUN_004cb7f0_y2 FUN_004cb7f0_y2
#pragma alias FUN_004f1ed0_y2 FUN_004f1ed0_y2
#pragma alias FUN_004f1f80_y2 FUN_004f1f80_y2

extern f32 cosf(f32);
extern f32 FUN_0016bc00(u32 param_1,u32 param_2);
extern int kwlnTaskGetWorkData(void);
float fGpffff8110;
float fGpffff81fc;
float fGpffff8248;
float fGpffff82cc;
float fGpffff8328;
float fGpffffad78;
u32 uGpffffad78;
extern u8 DAT_006b3070[];
extern char DAT_007cb790[];
extern char DAT_007cb780[];
extern char DAT_007cb760[];
extern char DAT_007cb740[];
#pragma alias K_View_GetFov_typed K_View_GetFov
f32 K_View_GetFov_typed(RwCamera *camera);
#pragma alias K_View_SetFov_typed K_View_SetFov
void K_View_SetFov_typed(RwCamera *camera,f32 fov);
#pragma alias mdlAnimSet_u32 mdlAnimSet
extern u32 mdlAnimSet_u32(u32 mdl, u32 slotIdx, s16 id, u32 blendFrameCount,
                          u32 flags);
#pragma alias FUN_004cb890_typed FUN_004cb890
extern void FUN_004cb890_typed(RwFrame *frame,f32 amount,const RwV3d *axis,u32 mode);
#pragma alias FUN_004cb750_typed FUN_004cb750
extern void FUN_004cb750_typed(u32 frame,void *axis,u32 mode);
#pragma alias FUN_0034fdb0_fcl FUN_0034fdb0
extern void FUN_0034fdb0_fcl(u32 param_1, u16 param_2);
extern f32 func_0020c500(const f32 *value,f32 scale);
extern void func_0020c320(s32 unused,const f32 *source,f32 scale,void *viewport);
extern void FUN_003c7070_typed(f32 t, void *out, const void *a, const void *b);
#pragma alias FUN_003c7070_typed FUN_003c7070
extern f32 FUN_004c69f0_typed(RwV3d *out, const RwV3d *in);
#pragma alias FUN_004c69f0_typed FUN_004c69f0_y2
extern void FUN_004c3760_typed(RwMatrix *out, const RwMatrix *in, u32 mode);
#pragma alias FUN_004c3760_typed FUN_004c3760
#pragma alias FUN_0034fe30_fcl FUN_0034fe30
extern void FUN_0034fe30_fcl(s32, f32, f32, f32);
#pragma alias RwMatrixRotate_fcl RwMatrixRotate
extern void *RwMatrixRotate_fcl(void *, const void *, f32, s32);
#pragma alias FUN_004bdde0_fcl FUN_004bdde0
extern void FUN_004c2f30(void *out,const void *left,const void *right);
extern void FUN_004bdde0_fcl(f32, s32, const void *, s32);
f32 FUN_0016ba00(u32 param_1, u32 param_2);
f32 FUN_0016ba80(u32 param_1, u32 param_2);
f32 FUN_0016bb00(u32 param_1, u32 param_2);
f32 FUN_0016bb80(u32 param_1, u32 param_2);
u32 FUN_00417160(void *param_1);
u32 FUN_00417330(u64 param_1,u32 param_2);
u32 FUN_00417380(void);
u32 FUN_004173e0(void);
u64 FUN_00417410(void);
u64 FUN_00417540(void);
u64 FUN_00417590(void);
u64 FUN_004175e0(void);
u64 FUN_00417630(void);
void FUN_00417680(void);
u32 FUN_004176f0(int param_1,u16 param_2,int param_3);
u64 FUN_004177e0(int param_1);
u32 FUN_004178c0(int param_1);
int * FUN_00418030(void);
void FUN_004180a0(u32 *param_1);
void FUN_004180e0(u32 *param_1,s16 param_2);
#pragma alias FUN_004180e0_alloc FUN_004180e0
extern u16 *FUN_004180e0_alloc(u32 param_1,s16 param_2);
u64 FUN_00418130(u64 param_1,char *param_2);
u64 FUN_00418230(u64 param_1,u8 *param_2);
u8 FUN_00418390(int param_1,int *param_2);
u8 FUN_00418510(int param_1,int *param_2);
u32 FUN_00418880(int param_1,int *param_2);
u32 FUN_00418c10(u64 param_1,int *param_2);
u8 FUN_00418c70(int param_1,int *param_2);
u8 FUN_00419050(int param_1,int *param_2);
u32 FUN_004195f0(int param_1,int *param_2);
u32 FUN_00419730(u64 param_1,int *param_2);
u32 FUN_00419790(int param_1,int param_2);
u32 FUN_004198f0(int param_1,int param_2);
u32 FUN_00419a30(u64 param_1,int *param_2);
u32 FUN_00419a70(u64 param_1,int *param_2);
u32 FUN_00419b00(int param_1);
u32 FUN_00419b20(int param_1);
u32 FUN_00419b40(int param_1);
u32 FUN_00419b80(int param_1);
u32 FUN_00419c10(int param_1,int *param_2);
u8 FUN_00419f20(int param_1,int *param_2);
u32 FUN_0041a2c0(int param_1,int *param_2);
u32 FUN_0041a310(u64 param_1,int param_2);
u8 FUN_0041a3f0(u64 param_1,int param_2);
u32 FUN_0041a730(u64 param_1,int param_2);
u8 FUN_0041a900(u64 param_1,int param_2);
u8 FUN_0041abc0(int param_1,int *param_2);
u32 FUN_0041ae20(int param_1);
u8 FUN_0041aff0(int param_1,int param_2);
u8 FUN_0041b530(int param_1);
#pragma alias FUN_0041b530_u32 FUN_0041b530
u32 FUN_0041b530_u32(int param_1);
void FUN_0041b550(int param_1);
u8 FUN_0041b5c0(int param_1,u32 *param_2);
#pragma alias FUN_0041b5c0_u32 FUN_0041b5c0
extern u32 FUN_0041b5c0_u32(int param_1,u32 *param_2);
u64 FUN_0041b810(int param_1);
u64 FUN_0041b950(int param_1);
u64 FUN_0041ba60(int param_1);
u64 FUN_0041baf0(int param_1);
void *FUN_0041bc90(void *param_1,void *param_2,void *param_3,int param_4,void *param_5);
u32 FUN_0041be50(int param_1);
void FUN_0041beb0();
void FUN_0041bee0();
void FUN_0041bf10(int param_1,u32 param_2);
void FUN_0041bf80(u32 *param_1);
void FUN_0041c140(u32 param_1,u32 param_2,u32 param_3,int param_4);
s32 FUN_003c44d0(s32 param_1,code param_2,code param_3,s32 param_4);
void FUN_0041c180(int param_1,int param_2,int param_3);
void FUN_0040e3c0(u32 param_1,u32 param_2,u8 param_3,u32 param_4);
#pragma alias FUN_00418130_abs FUN_00418130
extern code FUN_00418130_abs[];
#pragma alias FUN_00418230_abs FUN_00418230
extern code FUN_00418230_abs[];
u32 DAT_006b2cf0;
u32 DAT_006b2d70;
u32 DAT_006b2db0;
u32 DAT_006b2de0;
u32 DAT_006b2e00;
u32 DAT_006b2e10;
u32 DAT_006b2e18;
u32 DAT_006b2e38[];
u32 DAT_006b2e3c[];
u32 DAT_006b2e40[];
u32 DAT_006b2e48;
u32 DAT_006b2e4c;
u32 DAT_006b2e50;
#pragma alias DAT_006b2e48_abs DAT_006b2e48
extern f32 DAT_006b2e48_abs[];
#pragma alias DAT_006b2e4c_abs DAT_006b2e4c
extern f32 DAT_006b2e4c_abs[];
#pragma alias DAT_006b2e50_abs DAT_006b2e50
extern f32 DAT_006b2e50_abs[];
u32 DAT_006b2e58;
u32 DAT_006b2e5c;
u32 DAT_006b2e60;
RwV3d DAT_006b2e68;
RwV3d DAT_006b2e78;
u32 DAT_006b2e90;
#pragma alias DAT_006b2e90_abs DAT_006b2e90
extern s16 DAT_006b2e90_abs[];
u32 DAT_006b2eb0;
RwV3d DAT_006b2ed8;
RwV3d DAT_006b2ee8;
u32 DAT_006b2f00;
RwV3d DAT_006b2f18;
RwV3d DAT_006b2f28;
u32 DAT_006b2f40;
u64 DAT_006b2f68;
u32 DAT_006b2f70;
u64 DAT_006b2f78;
u32 DAT_006b2f80;
u64 DAT_006b2f88;
f32 DAT_006b2f90;
u32 DAT_006b2fa0;
RwV3d DAT_006b2fb8;
u32 DAT_006b2fd0;
RwV3d DAT_006b2ff8;
RwV3d DAT_006b3008;
u32 DAT_006b3020;
u64 DAT_006b3038;
f32 DAT_006b3040;
u32 DAT_006b3050;
RwV3d DAT_006b3090;
u32 DAT_006b30a0;
u32 DAT_006b3f60;
u32 DAT_007cda6c;
extern float DAT_007cdae0;
extern float DAT_007cdae4;
extern u8 DAT_006b2aa0[];
u16 DAT_007e094e[];
u16 DAT_007e0956[];
u16 DAT_007e0958[];
#pragma alias DAT_007e094e_0041ae20 DAT_007e094e
extern u16 DAT_007e094e_0041ae20[];
#pragma alias DAT_007e0958_0041ae20 DAT_007e0958
extern u16 DAT_007e0958_0041ae20[];
u8 DAT_007e095e[];
u8 DAT_007e095f[];
u8 DAT_007e0960[];
u8 DAT_007e0961[];
extern char DAT_006b2ae8[];
extern char DAT_006b2af8[];
extern char DAT_006b2b10[];
extern char DAT_006b2b20[];
extern char DAT_006b2b40[];
extern char DAT_006b2ad0[];
u32 LAB_00417fb0[];
u32 LAB_0041b798[];

// FUN_00417160


u32 FUN_00417160(void *param_1)



{

  u32 uVar4;

  u32 uVar1;

  int iVar2;

  u32 lVar3;


  

  lVar3 = (u32)(*DAT_00960178_abs)(0x60,0x40000);
  if (lVar3 == 0) {

    K_Assert(DAT_006b2ad0,0x215);

  }

  memset((void*)lVar3,0,0x60);


  memcpy((void*)((int)lVar3 + 0x1c),(const void*)param_1,0x18);
  uVar1 = (u32)FUN_00418030();


  *(u32 *)((int)lVar3 + 0x3c) = uVar1;

  iVar2 = kwlnGetMainCamera();

  *(u32 *)((int)lVar3 + 0x38) = *(u32 *)(iVar2 + 4);

  uVar1 = FUN_003c44d0(0,0,0,0);

  *(u32 *)((int)lVar3 + 0x40) = uVar1;

  uVar4 = (u32)kwlnTaskCreate(0,DAT_006b2ae8,10,FUN_00417410,FUN_00417680,(void *)lVar3);

  uVar1 = (u32)kwlnTaskCreate(uVar4,DAT_006b2af8,0x18a6,FUN_00417540,0,(void *)lVar3);

  *(u32 *)((int)lVar3 + 8) = uVar1;

  uVar1 = (u32)kwlnTaskCreate(uVar4,DAT_006b2b10,0x83d,FUN_00417590,0,(void *)lVar3);

  *(u32 *)((int)lVar3 + 0xc) = uVar1;

  uVar1 = (u32)kwlnTaskCreate(uVar4,DAT_006b2b20,0x106f,FUN_004175e0,0,(void *)lVar3);

  *(u32 *)((int)lVar3 + 0x10) = uVar1;

  uVar1 = (u32)kwlnTaskCreate(uVar4,DAT_006b2b40,0x147a,FUN_00417630,0,(void *)lVar3);

  *(u32 *)((int)lVar3 + 0x14) = uVar1;

  uVar1 = FUN_003cda60(uVar4,0);

  *(u32 *)((int)lVar3 + 0x18) = uVar1;

  *(u32 *)((int)lVar3 + 4) = *(u32 *)((int)lVar3 + 4) | 2;

  return uVar4;

}

// FUN_00417330


u32 FUN_00417330(u64 param_1,u32 param_2)



{

  int iVar1;

  

  iVar1 = kwlnTaskGetWorkData();

  iVar1 = FUN_003c4910(*(int *)(iVar1 + 0x40),*(u16 *)(*(int *)(iVar1 + 0x40) + 0x10) + 1,4);

  **(u32 **)(iVar1 + 0x14) = param_2;

  return 1;

}

// FUN_00417380


u32 FUN_00417380(void)
{
  u32 uVar1;
  int iVar2;

  iVar2 = kwlnTaskGetWorkData();
  uVar1 = *(u32 *)(iVar2 + 4);
  if (((uVar1 & 4) != 0) || ((uVar1 & 2) != 0) || (FUN_0041b530_u32(iVar2) != 0)) {
    return 1;
  }
  return 0;
}

// FUN_004173E0


u32 FUN_004173e0(void)



{

  int iVar1;

  

  iVar1 = kwlnTaskGetWorkData();

  return *(u32 *)(iVar1 + 0x18);

}

// FUN_00417410


u64 FUN_00417410(void)
{
  int iVar1;
  int *piVar3;

  piVar3 = (int *)kwlnTaskGetWorkData();
  iVar1 = *piVar3;
  switch (iVar1) {
  case 0:
    *piVar3 = 1;
    FUN_004177e0((int)piVar3);
  case 1:
    if (FUN_004178c0((int)piVar3) == 0) {
      goto complete;
    }
    *piVar3 = 2;
    piVar3[1] = piVar3[1] & 0xfffffffd;
  case 2:
    if (FUN_0041b530_u32((int)piVar3) == 0) {
      goto complete;
    }
    *piVar3 = 3;
  case 3:
    FUN_0041b550((int)piVar3);
    *piVar3 = 4;
    piVar3[1] |= 4;
    piVar3[1] |= 1;
  case 4:
    break;
  default:
    goto complete;
  }
  if (FUN_0041b5c0_u32((int)piVar3,(u32 *)piVar3[17]) != 0) {
    *piVar3 = 2;
    piVar3[1] = piVar3[1] & 0xfffffffb;
  }
complete:
  return 0;
}

// FUN_00417540


u64 FUN_00417540(void)



{

  int uVar1;

  

  uVar1 = kwlnTaskGetWorkData();

  if ((*(u32 *)((int)uVar1 + 4) & 1) == 0) {
    return 0;
  }
  FUN_0041b810(uVar1);

  return 0;

}

// FUN_00417590


u64 FUN_00417590(void)



{

  int uVar1;

  

  uVar1 = kwlnTaskGetWorkData();

  if ((*(u32 *)((int)uVar1 + 4) & 1) == 0) {
    return 0;
  }
  FUN_0041b950(uVar1);

  return 0;

}

// FUN_004175E0


u64 FUN_004175e0(void)



{

  int uVar1;

  

  uVar1 = kwlnTaskGetWorkData();

  if ((*(u32 *)((int)uVar1 + 4) & 1) == 0) {
    return 0;
  }
  FUN_0041ba60(uVar1);

  return 0;

}

// FUN_00417630


u64 FUN_00417630(void)



{

  int uVar1;

  

  uVar1 = kwlnTaskGetWorkData();

  if ((*(u32 *)((int)uVar1 + 4) & 1) == 0) {
    return 0;
  }
  FUN_0041baf0(uVar1);

  return 0;

}

// FUN_00417680


void FUN_00417680(void)



{

  int iVar1;

  

  iVar1 = kwlnTaskGetWorkData();

  if (*(int *)(iVar1 + 0x34) != 0) {

    FUN_003c45f0(*(u32 *)(*(int *)(iVar1 + 0x34) + 0x14));

  }


  FUN_004180a0((u32 *)(*(u32 *)(iVar1 + 0x3c)));
  FUN_003c45f0(*(u32 *)(iVar1 + 0x40));

  DAT_0096017c_abs[0](iVar1);

  return;

}

// FUN_004176F0


u32 FUN_004176f0(int param_1,u16 param_2,int param_3)



{

  int iVar1;

  u16 *puVar2;

  u32 uVar3;

  u32 uVar4;

  

  uVar4 = 0;

  if (param_3 != 0) {

    uVar4 = strlen((const char*)param_3);

  }

  if (((param_1 == 0) || (iVar1 = *(int *)((int)param_1 + 0x34), iVar1 == 0)) ||

     (*(int *)(iVar1 + 0x14) == 0)) {

    K_Assert(DAT_006b2ad0,0x2cd);

  }

  iVar1 = *(int *)(*(int *)((int)param_1 + 0x34) + 0x14);

  uVar3 = FUN_003c4910(iVar1,*(u16 *)(iVar1 + 0x10) + 1,(int)uVar4 + 9);

  puVar2 = *(u16 **)((int)uVar3 + 0x14);

  *puVar2 = param_2;

  if (uVar4 != 0) {

    *(u16 **)(puVar2 + 2) = puVar2 + 4;

    memcpy((void*)(puVar2 + 4),(const void*)param_3,uVar4 & 0xffff);

  }

  else {

    *(u32 *)(puVar2 + 2) = 0;

  }

  return uVar3;

}

// FUN_004177E0


u64 FUN_004177e0(int param_1)
{
  #pragma alias DAT_006b2cf0_abs DAT_006b2cf0
  extern u32 DAT_006b2cf0_abs[];
  #pragma alias FUN_004176f0_s16 FUN_004176f0
  u32 FUN_004176f0_s16(int,s16,int);
  u32 *puVar5;
  u32 *puVar4;
  int iVar3;
  u32 uVar1;
  u32 uVar2;
  u32 uVar8;
  u32 uVar6;
  u32 auStack_80[32];

  puVar5 = DAT_006b2cf0_abs;
  puVar4 = auStack_80;
  iVar3 = 0x10;
  do {
    uVar1 = *puVar5;
    uVar2 = puVar5[1];
    puVar5 = puVar5 + 2;
    iVar3 = iVar3 + -1;
    *puVar4 = uVar1;
    puVar4[1] = uVar2;
    puVar4 = puVar4 + 2;
  } while (0 < iVar3);

  iVar3 = FUN_003c44d0(0x1c,0,0,0);
  puVar4 = *(u32 **)(iVar3 + 0x24);
  *puVar4 = 0;
  puVar4[5] = iVar3;
  *(u32 **)((int)param_1 + 0x34) = puVar4;

  for (uVar6 = 0; uVar6 < 0x10; uVar6 = uVar6 + 1) {
    FUN_004176f0_s16(param_1,
                     ((struct { s16 a; s16 pad; int b; } *)auStack_80)[uVar6].a,
                     ((struct { s16 a; s16 pad; int b; } *)auStack_80)[uVar6].b);
  }
  FUN_004180e0(*(u32 **)(param_1 + 0x3c),0x40);
  return 0;
}

// FUN_004178C0 NONMATCHING


u32 FUN_004178c0(int param_1)



{

  u8 uVar1;

  u8 uVar2;

  u8 cVar3;

  int *piVar4;

  int *iVar5;

  u8 *pcVar6;

  u32 uVar7;

  u8 bVar8;


  u32 uVar10;


  void *uVar12;

  s32 lVar13;
  void *model;

  int iVar14;
  u16 *puVar9;

  u32 *puVar11;

  u32 *puVar15;

  u32 *puVar16;

  u8 *puVar17;

  u8 *puVar18;
  u16 *puVar20;

  u32 uVar19;

  u8 auStack_b0[16];

  u32 auStack_a0 [8];

  u32 auStack_80 [12];

  u32 auStack_50 [14];

  u64 uStack_18;

  u32 uStack_10;

  u32 uStack_c;

  int iStack_8;

  int iStack_4;

  

  piVar4 = *(int **)(param_1 + 0x34);

  bVar8 = 0;

  iVar5 = *(int **)(piVar4[5] + 0xc);

  pcVar6 = *(u8 **)((u8 *)iVar5 + 0x14);

  switch (*piVar4) {
  case 0:
    goto LAB_00417918;
  case 1:
    goto LAB_00417a90;
  default:
    goto LAB_00417ffc;
  }

LAB_00417918:
  cVar3 = *pcVar6;

    switch (cVar3) {
    case '\x01':
      iVar14 = H_Cdvd_CacheFindFile(*(u32 *)(pcVar6 + 4),&iStack_4);
      piVar4[2] = iVar14;
      bVar8 = 1;
      break;

    case '\x02':
      iVar14 = H_Cdvd_CacheFindFile(*(u32 *)(pcVar6 + 4),&iStack_4);
      piVar4[2] = iVar14;
      break;

    case '\x03':
      if (*(int *)(pcVar6 + 4) == 0) {
        K_Assert(DAT_006b2ad0,0x324);
      }
      iVar14 = H_Cdvd_CacheFindFile(*(u32 *)(pcVar6 + 4),&iStack_4);
      piVar4[2] = iVar14;
      piVar4[6] = iStack_4;
      break;

    case '@':
      if (pcVar6[1] == '\x03') {
        FUN_003cdba0(*(u32 *)(param_1 + 0x18),*(u16 *)(param_1 + 0x22));
      }
      break;

    case '\x05': {
      puVar9 = FUN_004180e0_alloc(*(u32 *)(param_1 + 0x3c),*(s16 *)pcVar6);
      func_00219c90(*(u32 *)(puVar9 + 4));
      iVar14 = H_Cdvd_CacheFindFile(0x6b2e20,&iStack_4);
      piVar4[2] = iVar14;
      bVar8 = 1;
      }
      break;

    case '\x06':
      for (iVar14 = 0; iVar14 < *(short *)(param_1 + 0x20) + 2; iVar14 = iVar14 + 1) {
        func_0021ab80(*(u16 *)(param_1 + iVar14 * 2 + 0x24));
      }
      break;
    }

    *piVar4 = 1;


LAB_00417a90:
  cVar3 = *pcVar6;

  switch (cVar3) {
  case '\x01': {
    if ((bVar8 || (lVar13 = H_Cdvd_IsFileLoaded(piVar4[1]), lVar13 != 0))) {
      if (piVar4[1] != 0) {
        piVar4[2] = *(int *)(piVar4[1] + 0x110);
      }

      puVar9 = FUN_004180e0_alloc(*(u32 *)(param_1 + 0x3c),4);
      uVar10 = FUN_0034fcd0(piVar4[2]);
      *(u32 *)(puVar9 + 4) = uVar10;
      *puVar9 = *puVar9 | 2;

      if (piVar4[1] != 0) {
        H_Cdvd_Destroy(piVar4[1]);
      }

      piVar4[1] = 0;
      bVar8 = 1;

      puVar16 = &DAT_006b2d70;
      puVar15 = auStack_50;
      iVar14 = 0xd;
      do {
        uVar10 = *puVar16;
        puVar16 = puVar16 + 1;
        iVar14 = iVar14 + -1;
        *puVar15 = uVar10;
        puVar15 = puVar15 + 1;
      } while (0 < iVar14);
      *(u32 *)(puVar9 + 2) = auStack_50[(u8)pcVar6[1]];
    }
    }
    break;

  case '\x02': {
    if (((piVar4[2] != 0) || (bVar8)) ||
       (lVar13 = H_Cdvd_IsFileLoaded(piVar4[1]), lVar13 != 0)) {
      if (piVar4[1] != 0) {
        piVar4[2] = *(int *)(piVar4[1] + 0x110);
      }

      if (piVar4[3] == 0) {
        iVar14 = func_0010c1a0(0,*(u32 *)(pcVar6 + 4),0,0,0,0,0,0);
        piVar4[3] = iVar14;
      }

      puVar16 = &DAT_006b2db0;
      puVar15 = auStack_80;
      iVar14 = 6;
      do {
        uVar10 = *puVar16;
        uVar7 = puVar16[1];
        puVar16 = puVar16 + 2;
        iVar14 = iVar14 + -1;
        *puVar15 = uVar10;
        puVar15[1] = uVar7;
        puVar15 = puVar15 + 2;
      } while (0 < iVar14);

      puVar16 = &DAT_006b2de0;
      puVar15 = auStack_a0;
      iVar14 = 4;
      do {
        uVar10 = *puVar16;
        uVar7 = puVar16[1];
        puVar16 = puVar16 + 2;
        iVar14 = iVar14 + -1;
        *puVar15 = uVar10;
        puVar15[1] = uVar7;
        puVar15 = puVar15 + 2;
      } while (0 < iVar14);

      puVar18 = (u8 *)(&DAT_006b2e00);
      puVar17 = auStack_b0;
      iVar14 = 8;
      do {
        uVar1 = *puVar18;
        uVar2 = puVar18[1];
        puVar18 = puVar18 + 2;
        iVar14 = iVar14 + -1;
        *puVar17 = uVar1;
        puVar17[1] = uVar2;
        puVar17 = puVar17 + 2;
      } while (0 < iVar14);

      uVar12 = func_0010c3a0_ptr(piVar4[3],&iStack_8,0);
      if (iStack_8 != 0) {
        puVar9 = FUN_004180e0_alloc(*(u32 *)(param_1 + 0x3c),4);
        puVar11 = (u32 *)FUN_0041bc90(auStack_80,auStack_a0,auStack_b0,4,uVar12);
        *(u32 **)(puVar9 + 4) = puVar11;
        *puVar11 = *puVar11 | 1;
        *puVar9 = *puVar9 | 0x10;
        piVar4[3] = 0;
        if (piVar4[1] != 0) {
          H_Cdvd_Destroy(piVar4[1]);
        }
        piVar4[1] = 0;
        bVar8 = 1;
      }
    }
    }
    break;

  case '\x03': {
    if (piVar4[4] == 0) {
      model = mdlCreateFromRmdMemory_ptr(0xb,0x101,piVar4[2],piVar4[6],0);
      piVar4[4] = (int)model;
      if (model == 0) goto LAB_00417fb0;
    }

    lVar13 = mdlStreamRead(piVar4[4]);
    if (lVar13 != 0) {
      puVar9 = FUN_004180e0_alloc(*(u32 *)(param_1 + 0x3c),*(s16 *)pcVar6);
      *(int *)(puVar9 + 4) = piVar4[4];
      *puVar9 = *puVar9 | 4;
      if (piVar4[1] != 0) {
        H_Cdvd_Destroy(piVar4[1]);
      }
      piVar4[1] = 0;
      bVar8 = 1;
      piVar4[4] = 0;
    }
    }
    break;

  case '@':
    if ((pcVar6[1] == '\x03') &&
       (lVar13 = FUN_003cdc80(*(u32 *)(param_1 + 0x18)), lVar13 != 0)) {
      bVar8 = 1;
    }
    break;

  case '\x05':
    func_00219d90();
    if ((bVar8) || (lVar13 = H_Cdvd_IsFileLoaded(piVar4[1]), lVar13 != 0)) {
      if (piVar4[1] != 0) {
        piVar4[2] = *(int *)(piVar4[1] + 0x110);
      }
      func_0021b4a0(piVar4[2]);
      if (piVar4[1] != 0) {
        H_Cdvd_Destroy(piVar4[1]);
      }
      piVar4[1] = 0;
      bVar8 = 1;
    }
    break;

  case '\x06': {
    func_00219d90();
    lVar13 = func_0021a120();
    if (lVar13 == 0) {
      puVar20 = FUN_004180e0_alloc(*(u32 *)(param_1 + 0x3c),4);
      *(int *)(*(int *)(puVar20 + 4) + 4) = *(short *)(param_1 + 0x20) + 2;
      for (uVar19 = 0; (int)uVar19 < *(short *)(param_1 + 0x20) + 2; uVar19 = uVar19 + 1) {
        uStack_18 = DAT_006b2e10;
        uStack_10 = DAT_006b2e18;
        uStack_c = DAT_007cda6c;
        puVar9 = FUN_004180e0_alloc(*(u32 *)(param_1 + 0x3c),(u16)((uVar19 & 0xff) << 8) | 6);
        *puVar9 = *puVar9 | 0x10;
        *(u16 **)(*(int *)(puVar20 + 4) + uVar19 * 4 + 8) = puVar9;
        func_00209f00(*(u32 *)(puVar9 + 4));
        func_0020c590(*(u32 *)(puVar9 + 4),*(u16 *)(param_1 + uVar19 * 2 + 0x24));
        func_0020cc80(*(u32 *)(puVar9 + 4),&uStack_c);
        sflResSetSpriteScale((void *)*(u32 *)(puVar9 + 4),(const f32 *)&uStack_18);
        func_0020c7a0(*(u32 *)(puVar9 + 4),*(u32 *)(param_1 + 0x38));
      }
      bVar8 = 1;
    }
    }
    break;
  }

LAB_00417fb0:

  if (bVar8) {

    lVar13 = FUN_003c49e0(piVar4[5],piVar4[5] + 4,iVar5);

    if (lVar13 == 0) {

      FUN_003c45f0(piVar4[5]);

      *(u32 *)(param_1 + 0x34) = 0;

      return 1;

    }

    *piVar4 = 0;

  }

LAB_00417ffc:
  return 0;

}

// FUN_00418030


int * FUN_00418030(void)



{

  int *piVar1;
  int iVar2;

  
  iVar2 = FUN_003c44d0(0x14,(code)FUN_00418130_abs,(code)FUN_00418230_abs,0);

  piVar1 = *(int **)(iVar2 + 0x24);

  *piVar1 = iVar2;

  iVar2 = FUN_003c44d0(0,0,0,0);

  piVar1[1] = iVar2;

  return piVar1;

}

// FUN_004180A0


void FUN_004180a0(u32 *param_1)



{

  FUN_003c45f0(*param_1);

  FUN_003c45f0(param_1[1]);

  return;

}

// FUN_004180E0


void FUN_004180e0(u32 *param_1,s16 param_2)
{
  FUN_003c4910(*param_1,param_2,0xc);
  /* Preserve retail's in-register payload write through the call result. */
  __asm__ volatile (
      "lw $v0, 0x14($v0)\n"
      "sh %0, 2($v0)"
      : : "r"(param_2) : "$v0", "memory");

  return;
}

// FUN_00418130


u64 FUN_00418130(u64 param_1,char *param_2)



{

  u8 cVar1;

  int iVar2;

  void *uVar3;

  

  iVar2 = *(int *)(param_2 + 0x14);

  cVar1 = *param_2;

  switch (cVar1) {
  case 4:
    uVar3 = (*DAT_00960178_abs)(0x20,0x40000);
    *(void **)(iVar2 + 8) = uVar3;
    memset(uVar3,0,0x20);
    break;
  case 5:
    uVar3 = (*DAT_00960178_abs)(0x2730,0x40000);
    *(void **)(iVar2 + 8) = uVar3;
    memset(uVar3,0,0x2730);
    break;
  case 6:
    uVar3 = (*DAT_00960178_abs)(0xfa8,0x40000);
    *(void **)(iVar2 + 8) = uVar3;
    memset(uVar3,0,0xfa8);
    break;
  }

  return 0;

}

// FUN_00418230


u64 FUN_00418230(u64 param_1,u8 *param_2)



{

  int iVar1;

  u32 lVar2;

  

  iVar1 = *(int *)(param_2 + 0x14);

  switch(*param_2) {

  case 1:

    FUN_0034fcf0(*(u32 *)(iVar1 + 8));

    break;

  case 2:


    lVar2 = FUN_0041be50(*(u32 *)(iVar1 + 8));
    if (lVar2 != 0) {

      FUN_004d0f00_y2(lVar2);

    }

    break;

  case 3:

    mdlDestroy(*(u32 *)(iVar1 + 8));

    break;

  case 4:

    (*DAT_0096017c_abs)(*(u32 *)(iVar1 + 8));

    break;

  case 5:

    func_0021a1b0();

    (*DAT_0096017c_abs)(*(u32 *)(iVar1 + 8));

    break;

  case 6:

    func_0020ac80(*(u32 *)(iVar1 + 8));

    (*DAT_0096017c_abs)(*(u32 *)(iVar1 + 8));

    break;

  case 7:

  case 8:

    break;

  }


  return 0;

}

// FUN_00418340
u8 FUN_00418340(int param_1,int *param_2)
{
  s16 *puVar4;
  int *piVar5;

  puVar4 = (s16 *)param_2[1];
  piVar5 = (int *)*param_2;
  *puVar4 = *puVar4 | *(s16 *)(piVar5 + 3);
  *puVar4 = *puVar4 & (s16)~piVar5[4];
  return 1;
}

// FUN_00418390


u8 FUN_00418390(int param_1,int *param_2)



{

  char cVar1;

  s16 uVar2;

  s16 uVar3;

  s16 *puVar4;

  int *piVar5;

  int iVar6;
  int iVar7;
  long lVar8;
  int iVar9;

  

  puVar4 = (s16 *)param_2[1];

  piVar5 = (int *)*param_2;

  cVar1 = (char)piVar5[1];

  switch (cVar1) {
  case '\x01':
    FUN_0034fd10(*(u32 *)(puVar4 + 4));
    break;
  case '\x02':
    if ((piVar5[3] & 0x200U) != 0) {
      iVar7 = param_2[3];
      iVar7 = (iVar7 << 8) - iVar7;
      iVar7 = iVar7 / piVar5[2];
      iVar7 = iVar7 | 0xffffff00;
      FUN_0041bf10(*(u32 *)(puVar4 + 4),iVar7);
    }
    break;
  case '@':
    if (*(char *)((int)piVar5 + 5) == '\x03') {
      if ((piVar5[3] & 1U) != 0) {
        FUN_003cde00(*(u32 *)(param_1 + 0x18),1);
      }
      else {
        if ((piVar5[4] & 1U) != 0) {
          FUN_003cde70(*(u32 *)(param_1 + 0x18),1);
        }
      }
    }
    break;
  }

  uVar2 = *(s16 *)(piVar5 + 3);

  uVar3 = *puVar4;

  *puVar4 = uVar3 | uVar2;
  lVar8 = (long)(s16)(~piVar5[4]);
  lVar8 = (long)(s16)*puVar4 & (u64)lVar8;
  *puVar4 = lVar8;

  iVar6 = *(int *)(*(int *)(param_1 + 0x3c) + 8) - *piVar5;

  param_2[3] = iVar6;

  return piVar5[2] <= iVar6;

}

// FUN_00418510 NONMATCHING


u8 FUN_00418510(int param_1,int *param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  u32 uVar5;

  f32 fVar18;
  f32 spriteScale;
  u8 auStack_80 [72];

  float spriteInput[2];

  u32 auStack_30 [4];

  RwV3d vector;

  RwV3d position;

  

  iVar2 = param_2[1];

  iVar3 = *param_2;

  uVar5 = *(u32 *)(param_1 + 0x38);

  auStack_30[0] = DAT_006b2e38[0];
  auStack_30[1] = DAT_006b2e3c[0];
  auStack_30[2] = DAT_006b2e40[0];

  position.x = (float)(*(int *)(iVar3 + 0xc) / 0xffff);

  position.y = (float)(*(int *)(iVar3 + 0x10) / 0xffff);

  position.z = (float)(*(int *)(iVar3 + 0x14) / 0xffff);

  if ((*(u32 *)(iVar3 + 0x18) & 4) != 0) {

    iVar4 = kwlnGetMainCamera();

    vector.x = (-(position.x - 320.0f) * *(float *)(iVar4 + 0x68)) / 320.0f;
    vector.y = (-(position.y - 224.0f) * *(float *)(iVar4 + 0x6c)) / 224.0f;
    vector.z = 1.0f;

    RwV3dNormalize(&vector,&vector);

    iVar4 = *(int *)(param_1 + 0x38);

    FUN_004c32a0(auStack_80,iVar4 + 0x10);

    FUN_004c6c60(&vector,&vector,auStack_80);

    vector.x = vector.x * position.z;

    vector.y = vector.y * position.z;

    vector.z = vector.z * position.z;

    position.x = *(float *)(iVar4 + 0x40) + vector.x;

    position.y = *(float *)(iVar4 + 0x44) + vector.y;

    position.z = *(float *)(iVar4 + 0x48) + vector.z;

  }

  cVar1 = *(char *)(iVar3 + 4);

  switch (cVar1) {
  case '\x01':
    FUN_0034fdf0(*(u32 *)(iVar2 + 8),&position);
    break;
  case '\x02':
    FUN_0041beb0(*(u32 *)(iVar2 + 8),&position,
                 auStack_30[*(u32 *)(iVar3 + 0x18) & 3]);
    break;
  case '\x03':
    mdlTranslate(*(u32 *)(iVar2 + 8),&position,
                 auStack_30[*(u32 *)(iVar3 + 0x18) & 3]);
    break;
  case '\x06':
    spriteInput[0] = (float)(*(int *)(iVar3 + 0xc) / 0xffff);
    spriteInput[1] = (float)(*(int *)(iVar3 + 0x10) / 0xffff);
    spriteScale = (float)(*(int *)(iVar3 + 0x14) / 0xffff);
    fVar18 = func_0020c500((const f32 *)(iVar2 + 8),spriteScale);
    func_0020c320(iVar2 + 8,spriteInput,fVar18,&position);
    sflResSetSpritePosition((void *)*(u32 *)(iVar2 + 8),(float *)&position);
    break;
  case '@':
    if ((*(char *)(iVar3 + 5) != '\x02') && (*(char *)(iVar3 + 5) == '\x01')) {
      FUN_004cb750_typed(uVar5,&position,auStack_30[*(u32 *)(iVar3 + 0x18) & 3]);
    }
    break;
  }

  iVar2 = param_2[3];

  param_2[3] = iVar2 + 1;

  return *(int *)(iVar3 + 8) <= iVar2 + 1;

}

// FUN_00418880 NONMATCHING

u32 FUN_00418880(int param_1,int *param_2)



{

  char cVar1;

  int iVar2;

  int iVar3;

  u32 uVar4;

  int iVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  RwMatrix matrix;

  u8 auStack_60 [64];

  f32 auStack_20 [4];

  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;

  

  iVar2 = param_2[1];

  iVar3 = *param_2;

  uVar4 = *(u32 *)(param_1 + 0x38);

  auStack_20[0] = *DAT_006b2e48_abs;
  auStack_20[1] = *DAT_006b2e4c_abs;
  auStack_20[2] = *DAT_006b2e50_abs;

  uStack_10 = 0x3f800000;
  uStack_c = 0;
  uStack_8 = 0;
  RwMatrixRotate((void*)auStack_60,(void*)&uStack_10,(float)(*(int *)(iVar3 + 0xc) / 0xffff),0);

  uStack_10 = 0;
  uStack_c = 0x3f800000;
  uStack_8 = 0;
  RwMatrixRotate((void*)auStack_60,(void*)&uStack_10,(float)(*(int *)(iVar3 + 0x10) / 0xffff),2);

  uStack_10 = 0;
  uStack_c = 0;
  uStack_8 = 0x3f800000;
  RwMatrixRotate((void*)auStack_60,(void*)&uStack_10,(float)(*(int *)(iVar3 + 0x14) / 0xffff),2);

  cVar1 = *(char *)(iVar3 + 4);
  if (cVar1 == '\x01') {
    FUN_0034fe30_fcl((float)(*(int *)(iVar3 + 0xc) / 0xffff),(float)(*(int *)(iVar3 + 0x10) / 0xffff),
                     (float)(*(int *)(iVar3 + 0x14) / 0xffff),*(u32 *)(iVar2 + 8));
  }
  else if (cVar1 == '\x02') {
    FUN_0041bee0(*(u32 *)(iVar2 + 8),auStack_60,
                 *(u32 *)&auStack_20[*(u32 *)(iVar3 + 0x18) & 3]);
  }
  else if (cVar1 == '\x03') {
    mdl00318a70(*(u32 *)(iVar2 + 8),auStack_60,*(u32 *)&auStack_20[*(u32 *)(iVar3 + 0x18) & 3]);
  }
  else if (cVar1 == '\x06') {
    iVar5 = *(int *)(iVar2 + 8);
    fVar10 = *(float *)(iVar5 + 0x14);
    fVar12 = *(float *)(iVar5 + 0x10);
    fVar11 = *(float *)(iVar5 + 0x18);
    fVar8 = *(float *)(iVar5 + 0x1c);
    fVar7 = 2.0f / (fVar8 * fVar8 + fVar11 * fVar11 + fVar12 * fVar12 + fVar10 * fVar10);
    fVar9 = fVar12 * fVar7;
    fVar6 = fVar10 * fVar7;
    fVar7 = fVar11 * fVar7;
    matrix.right.x = 1.0f - (fVar10 * fVar6 + fVar11 * fVar7);
    matrix.right.y = fVar12 * fVar6 + fVar7 * fVar8;
    matrix.right.z = fVar11 * fVar9 - fVar6 * fVar8;
    matrix.up.x = fVar12 * fVar6 - fVar7 * fVar8;
    matrix.up.y = 1.0f - (fVar11 * fVar7 + fVar12 * fVar9);
    matrix.up.z = fVar10 * fVar7 + fVar9 * fVar8;
    matrix.at.x = fVar11 * fVar9 + fVar6 * fVar8;
    matrix.at.y = fVar10 * fVar7 - fVar9 * fVar8;
    matrix.at.z = 1.0f - (fVar12 * fVar9 + fVar10 * fVar6);
    matrix.pos.x = 0.0f;
    matrix.pos.y = 0.0f;
    matrix.pos.z = 0.0f;
    matrix.flags = 3;
    FUN_004c3760(&matrix,auStack_60,*(u32 *)&auStack_20[*(u32 *)(iVar3 + 0x18) & 3]);
    FUN_004bdcb0((void *)(iVar5 + 0x10),&matrix);
  }
  else if (cVar1 == '@') {
    if ((*(char *)(iVar3 + 5) != '\x02') && (*(char *)(iVar3 + 5) == '\x01')) {
      FUN_004cb7f0(uVar4,auStack_60,*(u32 *)&auStack_20[*(u32 *)(iVar3 + 0x18) & 3]);
    }
  }

  return 1;

}

// FUN_00418C10


u32 FUN_00418c10(u64 param_1,int *param_2)



{

  extern void K_View_SetFov(RwCamera*, float);
  u32 uVar1;

  uVar1 = kwlnGetMainCamera();
  K_View_SetFov((RwCamera *)uVar1,
                (float)(*(int *)(*param_2 + 0xc) / 0xffff));
  return 1;


}

// FUN_00418C70 NONMATCHING


u8 FUN_00418c70(int param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  u32 uVar3;
  int iVar4;
  u32 *puVar5;
  u32 *puVar6;
  float fVar9;
  u32 uVar10;
  float fVar11;
  f32 fVar12;
  RwMatrix matrix;
  float afStack_a8 [2];
  float afStack_b0 [3];

  iVar4 = param_2[1];
  iVar1 = *param_2;
  iVar2 = *(int *)(param_1 + 0x38);
  if (param_2[3] == 0) {
    switch (*(char *)(iVar1 + 4)) {
    case '\x01':
    case '\x02':
    case '\x03':
      break;
    case '\x06':
      sflResGetSpritePosition((const void *)*(u32 *)(iVar4 + 8),(f32 *)(param_2 + 0x18));
      break;
    case '@':
      switch (*(char *)(iVar1 + 5)) {
      case '\x01':
        *(RwV3d *)(param_2 + 0x18) = *(RwV3d *)(iVar2 + 0x40);
        break;
      case '\x02':
        break;
      }
      break;
    }
  }
  fVar11 = (float)param_2[0x18];
  fVar9 = (float)sinf(fGpffff81fc +
                              (fGpffff8248 * (float)param_2[3]) / (float)*(int *)(iVar1 + 8));
  afStack_b0[0] = fVar11 + (((fVar11 + (float)(*(int *)(iVar1 + 0xc) / 0xffff)) - fVar11) *
                       (fVar9 + 1.0f)) / 2.0f;
  fVar11 = (float)param_2[0x19];
  fVar9 = (float)sinf(fGpffff81fc +
                              (fGpffff8248 * (float)param_2[3]) / (float)*(int *)(iVar1 + 8));
  afStack_b0[1] = fVar11 + (((fVar11 + (float)(*(int *)(iVar1 + 0x10) / 0xffff)) - fVar11) *
                      (fVar9 + 1.0f)) / 2.0f;
  fVar11 = (float)param_2[0x1a];
  fVar9 = (float)sinf(fGpffff81fc +
                              (fGpffff8248 * (float)param_2[3]) / (float)*(int *)(iVar1 + 8));
  afStack_b0[2] = fVar11 + (((fVar11 + (float)(*(int *)(iVar1 + 0x14) / 0xffff)) - fVar11) *
                      (fVar9 + 1.0f)) / 2.0f;
  switch (*(char *)(iVar1 + 4)) {
  case '\x01':
  case '\x02':
  case '\x03':
    break;
  case '\x06':
    afStack_a8[0] = (float)(*(int *)(iVar1 + 0xc) / 0xffff);
    afStack_a8[1] = (float)(*(int *)(iVar1 + 0x10) / 0xffff);
    fVar12 = (float)(*(int *)(iVar1 + 0x14) / 0xffff);
    fVar12 = func_0020c500((const f32 *)(iVar4 + 8),fVar12);
    func_0020c320(iVar4 + 8,afStack_a8,fVar12,afStack_b0);
    sflResSetSpritePosition((void *)*(u32 *)(iVar4 + 8),afStack_b0);
    break;
  case '@':
    switch (*(char *)(iVar1 + 5)) {
    case '\x01':
      puVar6 = (u32 *)(iVar2 + 0x10);
      puVar5 = (u32 *)&matrix;
      iVar4 = 8;
      do {
        uVar10 = *puVar6;
        uVar3 = puVar6[1];
        puVar6 = puVar6 + 2;
        iVar4 = iVar4 + -1;
        *puVar5 = uVar10;
        puVar5[1] = uVar3;
        puVar5 = puVar5 + 2;
      } while (0 < iVar4);
      matrix.pos.x = afStack_b0[0];
      matrix.pos.y = afStack_b0[1];
      matrix.pos.z = afStack_b0[2];
      FUN_004cb7f0(iVar2,&matrix,0);
      break;
    }
    break;
  }
  iVar4 = param_2[3];
  param_2[3] = iVar4 + 1;
  return *(int *)(iVar1 + 8) <= iVar4 + 1;
}

// FUN_00419050 NONMATCHING


u8 FUN_00419050(int param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  float *pfVar7;

  int *piVar8;

  float *pfVar9;

  int *piVar10;

  float fVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  float fVar17;

  u8 auStack_100[16];

  u8 auStack_f0[32];

  u8 auStack_e0[32];

  float fStack_d0;

  float fStack_cc;

  float fStack_c8;

  float fStack_c4;

  u8 auStack_c0[16];

  u8 auStack_b0[16];

  int aiStack_a0 [16];

  float afStack_60 [5];

  float fStack_4c;

  float fStack_48;

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  u32 uStack_30;

  u32 uStack_2c;

  u32 uStack_28;

  float auStack_20 [4];

  u32 uStack_10;
  u32 uStack_c;
  u32 uStack_8;

  

  iVar1 = param_2[1];

  iVar2 = *param_2;

  iVar3 = *(int *)(param_1 + 0x38);

  auStack_20[0] = *(float *)&DAT_006b2e58;
  auStack_20[1] = *(float *)&DAT_006b2e5c;
  auStack_20[2] = *(float *)&DAT_006b2e60;


  if (param_2[3] == 0) {
    switch (*(char *)(iVar2 + 4)) {
    case '\x01':
    case '\x02':
    case '\x03':
      break;
    case '\x06':
      iVar6 = *(int *)(iVar1 + 8);
      fVar15 = *(float *)(iVar6 + 0x14);
      fVar17 = *(float *)(iVar6 + 0x10);
      fVar16 = *(float *)(iVar6 + 0x18);
      fVar14 = *(float *)(iVar6 + 0x1c);
      fVar12 = 2.0f / (fVar14 * fVar14 + fVar16 * fVar16 + fVar17 * fVar17 + fVar15 * fVar15);
      fVar13 = fVar17 * fVar12;
      fVar11 = fVar15 * fVar12;
      fVar12 = fVar16 * fVar12;
      afStack_60[0] = 1.0f - (fVar15 * fVar11 + fVar16 * fVar12);
      afStack_60[1] = fVar17 * fVar11 + fVar12 * fVar14;
      afStack_60[2] = fVar16 * fVar13 - fVar11 * fVar14;
      afStack_60[4] = fVar17 * fVar11 - fVar12 * fVar14;
      fStack_4c = 1.0f - (fVar16 * fVar12 + fVar17 * fVar13);
      fStack_48 = fVar15 * fVar12 + fVar13 * fVar14;
      fStack_40 = fVar16 * fVar13 + fVar11 * fVar14;
      fStack_3c = fVar15 * fVar12 - fVar13 * fVar14;
      fStack_38 = 1.0f - (fVar17 * fVar13 + fVar15 * fVar11);
      uStack_30 = 0;
      uStack_2c = 0;
      uStack_28 = 0;
      afStack_60[3] = 4.2039e-45f;
      pfVar9 = afStack_60;
      pfVar7 = (float *)(param_2 + 8);
      iVar6 = 8;
      do {
        fVar11 = *pfVar9;
        fVar12 = pfVar9[1];
        pfVar9 = pfVar9 + 2;
        iVar6 = iVar6 + -1;
        *pfVar7 = fVar11;
        pfVar7[1] = fVar12;
        pfVar7 = pfVar7 + 2;
      } while (0 < iVar6);
      break;
    case '@':
      switch (*(char *)(iVar2 + 5)) {
      case '\x01':
        piVar10 = (int *)(iVar3 + 0x10);
        piVar8 = param_2 + 8;
        iVar6 = 8;
        do {
          iVar4 = *piVar10;
          iVar5 = piVar10[1];
          piVar10 = piVar10 + 2;
          iVar6 = iVar6 + -1;
          *piVar8 = iVar4;
          piVar8[1] = iVar5;
          piVar8 = piVar8 + 2;
        } while (0 < iVar6);
        break;
      case '\x02':
        break;
      }
      break;
    }
  }

  uStack_10 = 0x3f800000;
  uStack_c = 0;
  uStack_8 = 0;
  RwMatrixRotate((void*)afStack_60,(void*)&uStack_10,(float)(*(int *)(iVar2 + 0xc) / 0xffff),0);

  uStack_10 = 0;
  uStack_c = 0x3f800000;
  uStack_8 = 0;
  RwMatrixRotate((void*)afStack_60,(void*)&uStack_10,(float)(*(int *)(iVar2 + 0x10) / 0xffff),2);

  uStack_10 = 0;
  uStack_c = 0;
  uStack_8 = 0x3f800000;
  RwMatrixRotate((void*)afStack_60,(void*)&uStack_10,(float)(*(int *)(iVar2 + 0x14) / 0xffff),2);

  piVar10 = param_2 + 8;

  piVar8 = aiStack_a0;

  iVar6 = 8;

  do {

    iVar4 = *piVar10;

    iVar5 = piVar10[1];

    piVar10 = piVar10 + 2;

    iVar6 = iVar6 + -1;

    *piVar8 = iVar4;

    piVar8[1] = iVar5;

    piVar8 = piVar8 + 2;

  } while (0 < iVar6);

  FUN_004c3760_typed((RwMatrix *)aiStack_a0,(const RwMatrix *)afStack_60,auStack_20[*(u32 *)(iVar2 + 0x18) & 3]);

  RtQuatConvertFromMatrix(auStack_c0,aiStack_a0);

  RtQuatConvertFromMatrix(auStack_b0,param_2 + 8);

  memcpy(auStack_e0,auStack_b0,0x10);

  memcpy(auStack_f0,auStack_c0,0x10);

  fVar11 = (float)sinf(fGpffff81fc +

                               (fGpffff8248 * (float)param_2[3]) / (float)*(int *)(iVar2 + 8));

  FUN_003c7070_typed((fVar11 + 1.0f) / 2.0f,auStack_100,auStack_e0,auStack_f0);

  memcpy(&fStack_d0,auStack_100,0x10);

  switch (*(char *)(iVar2 + 4)) {
  case '\x01':
  case '\x02':
  case '\x03':
    break;
  case '@':
    switch (*(char *)(iVar2 + 5)) {
    case '\x02':
      break;
    case '\x01':
      fVar12 = 2.0f / (fStack_c4 * fStack_c4 +
                     fStack_c8 * fStack_c8 + fStack_d0 * fStack_d0 + fStack_cc * fStack_cc);
      fVar14 = fStack_d0 * fVar12;
      fVar11 = fStack_cc * fVar12;
      fVar12 = fStack_c8 * fVar12;
      afStack_60[0] = 1.0f - (fStack_cc * fVar11 + fStack_c8 * fVar12);
      afStack_60[1] = fStack_d0 * fVar11 + fVar12 * fStack_c4;
      afStack_60[2] = fStack_c8 * fVar14 - fVar11 * fStack_c4;
      afStack_60[4] = fStack_d0 * fVar11 - fVar12 * fStack_c4;
      fStack_4c = 1.0f - (fStack_c8 * fVar12 + fStack_d0 * fVar14);
      fStack_48 = fStack_cc * fVar12 + fVar14 * fStack_c4;
      fStack_40 = fStack_c8 * fVar14 + fVar11 * fStack_c4;
      fStack_3c = fStack_cc * fVar12 - fVar14 * fStack_c4;
      fStack_38 = 1.0f - (fStack_d0 * fVar14 + fStack_cc * fVar11);
      uStack_30 = 0;
      uStack_2c = 0;
      uStack_28 = 0;
      afStack_60[3] = 4.2039e-45f;
      RwMatrixTranslate((void*)afStack_60,(void*)(iVar3 + 0x40),0);
      FUN_004cb7f0(iVar3,afStack_60,0);
      break;
    }
    break;
  case '\x06':
    iVar1 = *(int *)(iVar1 + 8);
    *(float *)(iVar1 + 0x10) = fStack_d0;
    *(float *)(iVar1 + 0x14) = fStack_cc;
    *(float *)(iVar1 + 0x18) = fStack_c8;
    *(float *)(iVar1 + 0x1c) = fStack_c4;
    break;
  }

  iVar1 = param_2[3];

  param_2[3] = iVar1 + 1;

  return *(int *)(iVar2 + 8) <= iVar1 + 1;

}

// FUN_004195F0


u32 FUN_004195f0(int param_1,int *param_2)
{
  int iVar1;
  int lVar2;
  int *piVar2;

  piVar2 = *(int **)(param_2 + 1);
  iVar1 = *param_2;
  switch (*(char *)(iVar1 + 4)) {
  case '@':
    switch (*(char *)(iVar1 + 5)) {
    case 1:
      break;
    case 2:
      lVar2 = MT_Scene_GetRes((*(u32 *)(iVar1 + 0xc) & 0x3ff | 0xc00) & 0xffff);
      if (lVar2 != 0) {
        mdlAnimSet(*(u32 *)((int)lVar2 + 0x128),0,
                   (short)((int)*(u32 *)(iVar1 + 0xc) >> 0x10),
                   *(u32 *)(iVar1 + 0x10) & 0xffff,(int)*(u32 *)(iVar1 + 0x10) >> 0x10 & 0xffff);
      }
      break;
    case 3:
      FUN_003cdcd0(*(u32 *)(param_1 + 0x18),
                   (short)((int)*(u32 *)(iVar1 + 0xc) >> 0x10),
                   *(u32 *)(iVar1 + 0x10) & 0xffff,(int)*(u32 *)(iVar1 + 0x10) >> 0x10 & 0xffff);
      break;
    }
    break;
  case 3:
    mdlAnimSet(*(u32 *)(piVar2 + 2),0,
               (short)((int)*(u32 *)(iVar1 + 0xc) >> 0x10),
               *(u32 *)(iVar1 + 0x10) & 0xffff,(int)*(u32 *)(iVar1 + 0x10) >> 0x10 & 0xffff);
    break;
  }
  return 1;
}

// FUN_00419730


u32 FUN_00419730(u64 param_1,int *param_2)



{

  u32 uVar1;

  

  uVar1 = *(u32 *)(*param_2 + 0xc);

  if ((uVar1 & 0xffff) != 0xffff) {
    uVar1 = (uVar1 & 0x3ff) | 0xc00;
    uVar1 = uVar1 & 0xffff;
  }
  else {
    uVar1 = 0x400;
  }

  FUN_003bb010_y2(uVar1,*(u8 *)(*param_2 + 0x14));

  return 1;

}

// FUN_00419790


u32 FUN_00419790(int param_1,int param_2)



{

  u32 uVar1;

  int iVar2;

  int iVar3;

  float fVar4;

  u8 auStack_70 [64];

  RwV3d uStack_10;

  RwV3d uStack_20;

  RwV3d uStack_30;

  

  iVar2 = *(int *)(param_2 + 4);

  uVar1 = *(u16 *)(param_1 + 0x22);
  uStack_10 = DAT_006b2e68;

  uStack_20 = DAT_006b2e78;

  iVar3 = *(int *)((int)kwlnGetMainCamera() + 4) + 0x10;

  uStack_30.x = uStack_30.y = uStack_30.z = FUN_0016ba00(0,uVar1);

  fVar4 = (float)FUN_0016ba80(0,uVar1);

  uStack_10.x = uStack_10.x + fVar4;

  fVar4 = (float)FUN_0016bb00(0,uVar1);

  uStack_10.y = uStack_10.y + fVar4;

  fVar4 = (float)FUN_0016bb80(0,uVar1);

  uStack_10.z = uStack_10.z + fVar4;

  RwMatrixRotate_fcl((void*)auStack_70,(void*)&uStack_20,180.0f,0);

  RwMatrixTranslate((void*)auStack_70,(void*)&uStack_10,2);

  FUN_004c2f30((void*)auStack_70,(void*)auStack_70,(void*)iVar3);

  mdl00318a70(*(u32 *)(iVar2 + 8),auStack_70,0);

  mdlScale(*(u32 *)(iVar2 + 8),&uStack_30,1);

  return 1;

}

#pragma push
#pragma opt_loop_invariants on
/* measured opt_loop_invariants: off nd11/obj308, on nd10/obj308; retained */
/* W420 negative: fVar declaration/parameter-alias probes stayed nd10/object308/window320/rate0.032468; u16 probe nd15/object308/window320/rate0.048701 versus baseline nd10/object308/window320/rate0.032468; reverted. */

// FUN_004198F0 NONMATCHING


u32 FUN_004198f0(int param_1,int param_2)



{

  short sVar1;
  u32 uVar3;
  int lVar4;
  short *psVar8;
  u16 *psVar6;
  u32 uVar7;
  int iVar5;
  float fVar9;
  u16 asStack_20 [16];
  u32 sVar2;

  

  sVar2 = *(u16 *)(param_1 + 0x22);

  if (*(int *)(param_2 + 0xc) == 0) {

    fVar9 = (float)FUN_0016bc00(0,sVar2);

    FUN_003cdcd0(*(u32 *)(param_1 + 0x18),(short)(int)fVar9,0,0);

  }

  lVar4 = FUN_003cdd80(*(u32 *)(param_1 + 0x18));

  if (lVar4 != 0) {

    psVar8 = DAT_006b2e90_abs;

    psVar6 = asStack_20;

    iVar5 = 0xd;

    do {
      sVar1 = *psVar8;

      psVar8 = psVar8 + 1;

      iVar5 = iVar5 + -1;

      *psVar6 = sVar1;

      psVar6 = psVar6 + 1;

    } while (0 < iVar5);

    for (uVar7 = 0; uVar7 < 0xd; uVar7 = uVar7 + 1) {

      if ((u16)sVar2 == asStack_20[uVar7]) {

        return 1;

      }

    }

    FUN_003cdcd0(*(u32 *)(param_1 + 0x18),0,0x1e,1);

    uVar3 = 1;

  }

  else {

    *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;

    uVar3 = 0;

  }

  return uVar3;

}
#pragma opt_loop_invariants off
#pragma pop

// FUN_00419A30


u32 FUN_00419a30(u64 param_1,int *param_2)



{

  int iVar1;

  

  iVar1 = *param_2;

  func_0010a4e0(1,*(s16 *)(iVar1 + 0xc),*(s16 *)(iVar1 + 0x10),
               *(s16 *)(iVar1 + 0x14));

  return 1;

}

// FUN_00419A70


u32 FUN_00419a70(u64 param_1,int *param_2)



{

  int iVar1;

  u32 uVar2;

  

  iVar1 = *param_2;

  if (*(int *)(iVar1 + 0xc) != 0) {

    H_Fade_FadeOut();

  }

  else {

    H_Fade_FadeIn();

  }

  uVar2 = *(u32 *)(iVar1 + 0x18);

  H_Fade_SetCustomColor((u8)(uVar2 >> 0x18),(u8)(uVar2 >> 0x10),(u8)(uVar2 >> 8));

  H_Fade_SetType(*(s16 *)(iVar1 + 0x10));

  H_Fade_SetDuration(*(s16 *)(iVar1 + 0x14));

  return 1;

}

// FUN_00419B00
u32 FUN_00419b00(int param_1)
{
  int iVar1;
  u32 uVar2;

  iVar1 = *(int *)(param_1 + 0x3c);
  uVar2 = *(u32 *)(iVar1 + 0x10) | 2;
  *(u32 *)(iVar1 + 0x10) = uVar2;
  return 1;
}

// FUN_00419B20
u32 FUN_00419b20(int param_1)
{
  int iVar1;
  u32 uVar2;

  iVar1 = *(int *)(param_1 + 0x3c);
  uVar2 = *(u32 *)(iVar1 + 0x10) | 1;
  *(u32 *)(iVar1 + 0x10) = uVar2;
  return 1;
}

// FUN_00419B40
u32 FUN_00419b40(int param_1)
{
  int iVar1;
  int iVar2;
  u32 uVar3;

  iVar1 = *(int *)(param_1 + 0x3c);
  iVar2 = *(int *)(iVar1 + 4);
  if ((u32)*(u16 *)(iVar2 + 0x10) < 2) {
    uVar3 = *(u32 *)(iVar1 + 0x10) | 1;
    *(u32 *)(iVar1 + 0x10) = uVar3;
    return 1;
  }
  return 0;
}

// FUN_00419B80


u32 FUN_00419b80(int param_1)



{
  extern void K_View_SetFov(RwCamera*, float);

  int lVar1;
  u32 uVar2;

  
  if (*(int *)(param_1 + 0x38) != 0)
    goto resource_ready;
  return 1;

resource_ready:
  lVar1 = MT_Scene_GetResListHead(0x14);
  if (lVar1 == 0)
    goto done;

  FUN_004cb7f0(*(u32 *)(param_1 + 0x38),*(u32 *)((int)lVar1 + 0x108),0);
  uVar2 = kwlnGetMainCamera();
  K_View_SetFov((RwCamera*)uVar2,*(float *)((int)lVar1 + 0x104));

done:
  return 1;


}

// FUN_00419C10
u32 FUN_00419c10(int param_1,int *param_2)
{
  int *piVar1;
  u32 uVar2;
  u32 uVar3;
  int iVar4;
  struct {
    float colors[4];
    u8 gap[12];
    u8 bytes[4];
  } stack;

  piVar1 = (int *)*param_2;
  uVar2 = *(u32 *)((int)piVar1 + 0xc);
  uVar3 = *(u32 *)((int)piVar1 + 0x14);
  iVar4 = *(int *)((int)piVar1 + 0x10);
  stack.colors[0] = (float)((uVar2 >> 0x18) & 0xff);
  stack.colors[1] = (float)((uVar2 >> 0x10) & 0xff);
  stack.colors[2] = (float)((uVar2 >> 8) & 0xff);
  stack.colors[3] = (float)(uVar2 & 0xff);

  switch (*(char *)((int)piVar1 + 4)) {
  case '@':
    switch (*(char *)((int)piVar1 + 5)) {
    case '\x03':
      switch (iVar4) {
      case 0:
        stack.bytes[0] = (u8)stack.colors[0];
        stack.bytes[1] = (u8)stack.colors[1];
        stack.bytes[2] = (u8)stack.colors[2];
        stack.bytes[3] = (u8)stack.colors[3];
        FUN_003cdf40(*(u32 *)(param_1 + 0x18),stack.bytes);
        break;
      case 1:
        FUN_003ce060(*(u32 *)(param_1 + 0x18),stack.colors);
        break;
      case 2:
        FUN_003ce180(*(u32 *)(param_1 + 0x18),stack.colors,uVar3);
        break;
      }
      break;
    }
    break;
  }
  return 1;
}

// FUN_00419F20 NONMATCHING
u8 FUN_00419f20(int param_1,int *param_2)



{

  int *piVar1;

  int iVar2;

  int iVar3;
  int lVar4;

  int iVar5;

  float *pfVar6;

  float *pfVar7;

  int iVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float afStack_c8 [10];

  RwMatrix matrix;

  float afStack_70 [14];

  float afStack_60 [12];

  float fStack_30;

  float fStack_2c;

  float fStack_28;

  RwV3d axis;

  RwV3d center;

  

  pfVar7 = (float *)&DAT_006b2eb0;

  pfVar6 = afStack_70 + 4;

  iVar5 = 5;

  do {

    fVar9 = *pfVar7;

    fVar11 = pfVar7[1];

    pfVar7 = pfVar7 + 2;

    iVar5 = iVar5 + -1;

    *pfVar6 = fVar9;

    pfVar6[1] = fVar11;

    pfVar6 = pfVar6 + 2;

  } while (0 < iVar5);

  center = DAT_006b2ed8;

  piVar1 = (int *)*param_2;

  axis = DAT_006b2ee8;

  pfVar7 = (float *)&DAT_006b2f00;

  pfVar6 = afStack_c8 + 2;

  iVar5 = 5;

  do {

    fVar9 = *pfVar7;

    pfVar7 = pfVar7 + 1;

    iVar5 = iVar5 + -1;

    *pfVar6 = fVar9;

    pfVar6 = pfVar6 + 1;

  } while (0 < iVar5);

  if (((char)piVar1[1] == '@') && (*(char *)((int)piVar1 + 5) == '\0')) {

    fVar9 = (float)sinf((fGpffff8110 * (float)param_2[3]) / (float)piVar1[2]);

    fGpffffad78 = fVar9 * 20.0f + 35.0f;

    lVar4 = FUN_003c4b50(**(int **)(param_1 + 0x3c),**(int **)(param_1 + 0x3c) + 4,4);

    fVar9 = center.z;

    if (lVar4 != 0) {

      iVar5 = *(int *)(*(int *)((int)lVar4 + 0x14) + 8);


      for (iVar8 = 0; iVar8 < *(int *)(iVar5 + 4); iVar8 = iVar8 + 1) {

        iVar2 = *(int *)(*(int *)(iVar5 + iVar8 * 4 + 8) + 8);

        fVar10 = (float)cosf((float)iVar8 * afStack_70[*(int *)(iVar5 + 4) * 2 + 1] +

                                     afStack_70[*(int *)(iVar5 + 4) * 2] + 0.0f);

        iVar3 = *(int *)(iVar5 + 4);

        fStack_30 = afStack_c8[iVar3] * fVar10;

        fStack_2c = (float)sinf((float)iVar8 * afStack_70[iVar3 * 2 + 1] +

                                        afStack_70[iVar3 * 2] + 0.0f);

        fStack_2c = -afStack_c8[*(int *)(iVar5 + 4)] * fStack_2c;

        fStack_28 = 0.0f;

        RwMatrixRotate((void*)&matrix,(void*)&axis,fGpffffad78,0);

        FUN_004c6c60(&fStack_30,&fStack_30,&matrix);

        fStack_30 = fStack_30 + center.x;

        fStack_2c = fStack_2c + fVar11;

        fStack_28 = fStack_28 + fVar9;

        FUN_004bdde0_fcl(fGpffffad78,iVar2 + 0x10,&axis,0);

        sflResSetSpritePosition((void *)iVar2,&fStack_30);

      }

    }

    lVar4 = FUN_003c4b50(**(int **)(param_1 + 0x3c),**(int **)(param_1 + 0x3c) + 4,2);

    if (lVar4 != 0) {

      iVar5 = *(int *)((int)lVar4 + 0x14);

      fStack_30 = 0.0f;

      fStack_2c = 23.0f;

      fStack_28 = 550.0f;

      RwMatrixRotate((void*)&matrix,(void*)&axis,fGpffffad78,0);
      FUN_0041bee0(*(u32 *)(iVar5 + 8),&matrix,0);
      FUN_0041beb0(*(u32 *)(iVar5 + 8),&fStack_30,2);



    }

  }

  iVar5 = *(int *)(*(int *)(param_1 + 0x3c) + 8) - *piVar1;

  param_2[3] = iVar5;

  return piVar1[2] <= iVar5;

}

// FUN_0041A2C0
u32 FUN_0041a2c0(int param_1, int* param_2)
{
    mdlAnimSet_u32(*(u32*)(param_2[1] + 8), 0, *(s16*)(param_1 + 0x20),
                   *(u32*)(*param_2 + 0x10) & 0xffff,
                   ((s32)*(u32*)(*param_2 + 0x10) >> 16) & 0xffff);
    return 1;
}

// FUN_0041A310


u32 FUN_0041a310(u64 param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  RwV3d uStack_10;

  RwV3d uStack_20;

  

  iVar1 = *(int *)(*(int *)(param_2 + 4) + 8);

  uStack_10 = DAT_006b2f18;

  uStack_20 = DAT_006b2f28;

  for (iVar3 = 0; iVar3 < *(int *)(iVar1 + 4); iVar3 = iVar3 + 1) {

    iVar2 = *(int *)(*(int *)(iVar1 + iVar3 * 4 + 8) + 8);

    FUN_004bdde0_fcl(35.0f,iVar2 + 0x10,&uStack_10,0);

    FUN_004bdde0_fcl(180.0f,iVar2 + 0x10,&uStack_20,1);

  }

  return 1;

}

// FUN_0041A3F0 NONMATCHING


u8 FUN_0041a3f0(u64 param_1,int param_2)



{

  u32 *puVar1;

  float fVar2;

  u32 uVar3;

  int iVar4;

  float *pfVar5;

  float *pfVar6;

  u32 uVar7;

  u32 uVar8;

  float fVar9;

  float fVar10;

  float afStack_d8 [10];

  u8 auStack_b0 [48];

  float afStack_80 [16];

  float fStack_40;

  float fStack_3c;

  float fStack_38;

  RwV3d center;

  u64 uStack_20;

  u32 uStack_18;

  u64 uStack_10;

  u32 uStack_8;

  

  puVar1 = *(u32 **)(*(int *)(param_2 + 4) + 8);

  pfVar6 = (float *)&DAT_006b2f40;

  pfVar5 = afStack_80 + 4;

  iVar4 = 5;

  do {

    fVar2 = *pfVar6;

    fVar10 = pfVar6[1];

    pfVar6 = pfVar6 + 2;

    iVar4 = iVar4 + -1;

    *pfVar5 = fVar2;

    pfVar5[1] = fVar10;

    pfVar5 = pfVar5 + 2;

  } while (0 < iVar4);

  uStack_10 = DAT_006b2f68;

  uStack_8 = DAT_006b2f70;

  uStack_20 = DAT_006b2f78;

  uStack_18 = DAT_006b2f80;

  *(u64 *)&center = DAT_006b2f88;

  center.z = DAT_006b2f90;

  pfVar6 = (float *)&DAT_006b2fa0;

  pfVar5 = afStack_d8 + 2;

  iVar4 = 5;

  do {

    fVar2 = *pfVar6;

    pfVar6 = pfVar6 + 1;

    iVar4 = iVar4 + -1;

    *pfVar5 = fVar2;

    pfVar5 = pfVar5 + 1;

  } while (0 < iVar4);

  if (*(int *)(param_2 + 0xc) == 0) {

    func_0010a4e0(1,10,7,0);

    func_0010a4e0(1,0,6,1);

  }
  fVar2 = center.z;

  fVar10 = center.y;


  for (uVar8 = 0; (int)uVar8 < (int)puVar1[1]; uVar8 = uVar8 + 1) {

    iVar4 = *(int *)(puVar1[uVar8 + 2] + 8);

    if (*(int *)(param_2 + 0xc) == uVar8 << 1) {

      *puVar1 = *puVar1 | 1 << (uVar8 & 0x1f);

      *(u16 *)puVar1[uVar8 + 2] = *(u16 *)puVar1[uVar8 + 2] | 1;

    }

    uVar7 = 1 << (uVar8 & 0x1f);

    if ((*puVar1 & uVar7) != 0) {

      fVar9 = (float)cosf((float)(int)uVar8 * afStack_80[puVar1[1] * 2 + 1] +

                                  afStack_80[puVar1[1] * 2] + 0.0f);

      uVar3 = puVar1[1];

      fStack_40 = afStack_d8[uVar3] * fVar9;

      fStack_3c = (float)sinf((float)(int)uVar8 * afStack_80[uVar3 * 2 + 1] +

                                      afStack_80[uVar3 * 2] + 0.0f);

      fStack_3c = -afStack_d8[puVar1[1]] * fStack_3c;

      fStack_38 = 0.0f;

      RwMatrixRotate((void*)auStack_b0,(void*)&uStack_10,*(float*)&(u32){0x420c0000},0);

      FUN_004c6c60(&fStack_40,&fStack_40,auStack_b0);

      fStack_40 = fStack_40 + center.x;

      fStack_3c = fStack_3c + fVar10;

      fStack_38 = fStack_38 + fVar2;

      FUN_004bdde0(0xc20c0000,iVar4 + 0x10,&uStack_10,0);

      FUN_004bdde0(0x43340000,iVar4 + 0x10,&uStack_20,2);

      sflResSetSpritePosition((void *)iVar4,&fStack_40);

      *puVar1 = *puVar1 & ~uVar7;

    }

  }

  iVar4 = *(int *)(param_2 + 0xc) + 1;

  *(int *)(param_2 + 0xc) = iVar4;

  return (int)(puVar1[1] * 2 + 2) < iVar4;

}

#pragma push
#pragma opt_loop_invariants on
/* measured opt_loop_invariants: off nd51/obj452, on nd49/obj452; retained */
/* W420 negative: typed FUN_004bdde0_fcl probe nd174/object460/window464/rate0.378261; 3-argument alias probe nd161/object456/window464/rate0.353070 versus baseline nd49/object452/window464/rate0.108407; reverted. */

// FUN_0041A730 NONMATCHING


u32 FUN_0041a730(u64 param_1,int param_2)



{

  u32 *puVar1;

  int iVar2;

  u32 uVar3;

  u32 uVar4;

  RwV3d position;

  

  puVar1 = *(u32 **)(*(int *)(param_2 + 4) + 8);

  position = DAT_006b2fb8;

  if (*(int *)(param_2 + 0xc) == 0) {

    func_0010a4e0(1,10,7,0);

  }

  for (uVar4 = 0; (int)uVar4 < (int)puVar1[1]; uVar4 = uVar4 + 1) {

    iVar2 = *(int *)(puVar1[uVar4 + 2] + 8);

    if (*(int *)(param_2 + 0xc) == uVar4 << 1) {

      *puVar1 = *puVar1 | 1 << uVar4;

      func_0010a4e0(1,(short)uVar4,6,3);

    }

    uVar3 = 1 << uVar4;
    if (((*puVar1 & uVar3) != 0) &&

       (FUN_004bdde0(0xc1f00000,iVar2 + 0x10,&position),
       (float)*(int *)(param_2 + 0xc) == (Yajima_AddFloatFirst((float)(int)(uVar4 << 1), 6.0f)) - 1.0f)) {

      *puVar1 = *puVar1 & ~uVar3;

    }

  }

  *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;

  return (float)*(int *)(param_2 + 0xc) > (float)(int)(puVar1[1] << 1) + 6.0f;

}
#pragma opt_loop_invariants off
#pragma pop

// FUN_0041A900 NONMATCHING


u8 FUN_0041a900(u64 param_1,int param_2)



{

  int iVar1;

  float fVar9;

  float fVar10;

  float fVar7;

  float fVar8;

  float fVar2;

  u32 uVar3;

  int iVar4;

  float *pfVar5;

  float *pfVar6;

  float afStack_70 [10];

  RwMatrix matrix;

  float afStack_c8 [5];

  RwV3d axis;

  RwV3d center;

  RwV3d position;

  

  iVar1 = *(int *)(*(int *)(param_2 + 4) + 8);

  pfVar6 = (float *)&DAT_006b2fd0;

  pfVar5 = afStack_70;

  iVar4 = 5;

  do {

    fVar2 = *pfVar6;

    fVar7 = pfVar6[1];

    pfVar6 = pfVar6 + 2;

    iVar4 = iVar4 + -1;

    *pfVar5 = fVar2;

    pfVar5[1] = fVar7;

    pfVar5 = pfVar5 + 2;

  } while (0 < iVar4);

  axis = DAT_006b2ff8;

  center = DAT_006b3008;

  pfVar6 = (float *)&DAT_006b3020;

  pfVar5 = afStack_c8;

  iVar4 = 5;

  do {

    fVar2 = *pfVar6;

    pfVar6 = pfVar6 + 1;

    iVar4 = iVar4 + -1;

    *pfVar5 = fVar2;

    pfVar5 = pfVar5 + 1;

  } while (0 < iVar4);

  fVar7 = (float)sinf(fGpffff81fc +

                              (fGpffff8248 * (5.0f - (float)*(int *)(param_2 + 0xc))) / 5.0f);

  fVar9 = (afStack_c8[*(int *)(iVar1 + 4)] * (fVar7 + 1.0f)) / 2.0f;

  fVar10 = -fVar9;

  fVar7 = center.y;

  fVar2 = center.z;

  for (iVar4 = 0; iVar4 < *(int *)(iVar1 + 4); iVar4 = iVar4 + 1) {

    uVar3 = *(u32 *)(*(int *)(iVar1 + iVar4 * 4 + 8) + 8);

    fVar8 = (float)cosf((float)iVar4 * afStack_70[*(int *)(iVar1 + 4) * 2 + 1] +

                                afStack_70[*(int *)(iVar1 + 4) * 2] + 0.0f);

    position.x = fVar9 * fVar8;

    position.y = (float)sinf((float)iVar4 * afStack_70[*(int *)(iVar1 + 4) * 2 + 1] +

                                    afStack_70[*(int *)(iVar1 + 4) * 2] + 0.0f);

    position.y = fVar10 * position.y;

    position.z = 0.0f;

    RwMatrixRotate((void*)&matrix,(void*)&axis,*(float*)&uGpffffad78,0);

    FUN_004c6c60(&position,&position,&matrix);

    position.x = position.x + center.x;

    position.y = position.y + fVar7;

    position.z = position.z + fVar2;

    sflResSetSpritePosition((void *)uVar3,(const f32 *)&position);

  }

  *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;

  if ((float)*(int *)(param_2 + 0xc) <= 5.0f) {
    return 0;
  }
  return 1;

}

// FUN_0041ABC0 NONMATCHING


u8 FUN_0041abc0(int param_1,int *param_2)



{

  int iVar1;

  u32 uVar2;

  int lVar3;

  int iVar4;

  u32 *puVar5;

  u32 *puVar6;

  u16 *puVar7;

  RwMatrix matrix;

  u32 auStack_40 [8];

  RwV3d position;

  RwV3d direction;

  

  iVar1 = *param_2;

  *(u64 *)&position = DAT_006b3038;

  position.z = DAT_006b3040;

  puVar6 = &DAT_006b3050;

  puVar5 = auStack_40;

  iVar4 = 5;

  do {

    uVar2 = *puVar6;

    puVar6 = puVar6 + 1;

    iVar4 = iVar4 + -1;

    *puVar5 = uVar2;

    puVar5 = puVar5 + 1;

  } while (0 < iVar4);

  lVar3 = FUN_003c4b50(**(int **)(param_1 + 0x3c),**(int **)(param_1 + 0x3c) + 4,

                       *(u16 *)(auStack_40 + *(short *)(param_1 + 0x20)));

  if (lVar3 != 0) {

    puVar7 = *(u16 **)((int)lVar3 + 0x14);

  }

  else {

    puVar7 = (u16 *)0x0;

  }

  iVar4 = kwlnGetMainCamera();

  direction.x = (-(position.x - 320.0f) * *(float *)(iVar4 + 0x68)) / 320.0f;

  direction.y = (-(position.y - 224.0f) * *(float *)(iVar4 + 0x6c)) / 224.0f;

  direction.z = 1.0f;

  RwV3dNormalize(&direction,&direction);

  iVar4 = *(int *)(param_1 + 0x38);

  FUN_004c32a0(&matrix,iVar4 + 0x10);

  FUN_004c6c60(&direction,&direction,&matrix);

  direction.x = direction.x * position.z;

  direction.y = direction.y * position.z;

  direction.z = direction.z * position.z;

  position.x = *(float *)(iVar4 + 0x40) + direction.x;

  position.y = *(float *)(iVar4 + 0x44) + direction.y;

  position.z = *(float *)(iVar4 + 0x48) + direction.z;

  FUN_0034fdf0(*(u32 *)(puVar7 + 4),&position);

  if (param_2[3] == 0) {

    FUN_0034fd10(*(u32 *)(puVar7 + 4));

    *puVar7 = *puVar7 | 1;

  }

  iVar4 = param_2[3];

  param_2[3] = iVar4 + 1;

  return *(int *)(iVar1 + 8) <= iVar4 + 1;

}

#pragma push
/* measured opt_loop_invariants: off MISMATCH nd24/obj80, on MATCH nd0/obj80; retained */

#pragma opt_loop_invariants on
// FUN_0041ADD0
u32 FUN_0041add0(int param_1, int *param_2)
{
  int i;
  int mask;
  s16 *entry;

  param_2 = (int *)((int *)param_2[1])[2];
  mask = -2;
  for (i = 0; i < param_2[1]; i = i + 1) {
    entry = *(s16 **)(param_2 + i + 2);
    *entry = *entry & mask;
  }
  return 1;
}
#pragma opt_loop_invariants off
#pragma pop


#pragma push
/* measured opt_loop_invariants: off MISMATCH nd33/obj452, on MATCH nd0/obj452; retained */

#pragma opt_loop_invariants on
// FUN_0041AE20


u32 FUN_0041ae20(int param_1)



{

  int *piVar1;

  u32 uVar2;

  int iVar3;
  int node;
  short type;

  

  if (*(int *)(*(int *)(param_1 + 0x3c) + 8) == 0) {

    func_0010a370(3,DAT_006b3070);

    func_001a0040(1,1);

    func_001a0150(0xc00,1);

    func_001a0150(0xc01,1);

    func_001a0150(0xc02,1);

    printf(DAT_007cb790,DAT_007cb780,0x22);
    printf(DAT_007cb760);
    H_Dbprt_FmtLog(DAT_007cb740);

  }

  if ((((DAT_007e094e_0041ae20[0] & 0x40) != 0) ||
       ((DAT_007e0958_0041ae20[0] & 0x40) != 0)) &&

     (*(int *)(*(int *)(param_1 + 0x3c) + 8) < 0x15e)) {

    func_00109f60(3,0);

    *(u32 *)(*(int *)(param_1 + 0x3c) + 8) = 0x563;

  }

  iVar3 = *(int *)(param_1 + 0x3c);

  if (*(int *)(iVar3 + 8) == 0x582) {

    for (node = *(int *)(*(int *)(iVar3 + 4) + 0xc); node != 0; node = *(int *)(node + 0x10)) {
      piVar1 = *(int **)(node + 0x14);
      type = *(short *)(*piVar1 + 6);
      if ((type == 6) || (type == 7)) {

        piVar1[3] = piVar1[3] + 1000;

      }

    }

    uVar2 = 1;

  }

  else if ((*(int *)(iVar3 + 8) == 400) || ((*(u32 *)(iVar3 + 0x10) & 1) != 0)) {

    func_00109f60(3,0);

    uVar2 = 1;

  }

  else {

    uVar2 = 0;

  }

  return uVar2;

}
#pragma opt_loop_invariants off
#pragma pop

// FUN_0041AFF0 NONMATCHING
u8 FUN_0041aff0(int param_1,int param_2)
{
  int iVar1;
  u8 *clear;
  int count;
  u8 bVar3;
  float fVar6;
  float fVar7;
  RwV3d direction;
  RwV3d cameraPosition;
  RwV3d negativePosition;
  RwV3d movement;
  iVar1 = *(int *)(param_1 + 0x38);
  fVar7 = 0.0f;
  direction = DAT_006b3090;
  bVar3 = 0;
  count = 0xc;
  clear = (u8 *)&movement;
  while (count != 0) {
    *clear = 0;
    clear++;
    count--;
  }
  if (((DAT_007e094e[0] & 0x80) != 0) || ((DAT_007e0958[0] & 0x80) != 0)) {
    *(u32 *)(param_2 + 0x10) = *(u32 *)(param_2 + 0x10) ^ 1;
  }
  if (*(int *)(param_2 + 0x10) == 0) {
    bVar3 = (*(u32 *)(*(int *)(param_1 + 0x3c) + 0x10) & 1) != 0;
  }
  else {
    *(int *)(*(int *)(param_1 + 0x3c) + 8) =
      *(int *)(*(int *)(param_1 + 0x3c) + 8) + -1;
    if (((DAT_007e094e_0041ae20[0] & 8) != 0) ||
        ((DAT_007e0958_0041ae20[0] & 8) != 0)) {
      *(u32 *)(*(int *)(param_1 + 0x3c) + 8) = 499;
    }
    fVar6 = (float)DAT_007e095e[0] - 128.0f;
    if ((fVar6 < -48.0f) || (48.0f <= fVar6)) {
      fVar7 = 0.0f - fGpffff82cc * fVar6;
      bVar3 = 1;
    }
    fVar6 = (float)DAT_007e095f[0] - 128.0f;
    if ((fVar6 < -48.0f) || (48.0f <= fVar6)) {
      direction = *(RwV3d *)(iVar1 + 0x10);
      fVar7 = (fVar7 + 0.0f) - fGpffff82cc * fVar6;
      bVar3 = 1;
    }
    fVar6 = (float)DAT_007e0961[0] - 128.0f;
    if ((fVar6 < -48.0f) || (48.0f <= fVar6)) {
      movement = *(RwV3d *)(iVar1 + 0x30);
      FUN_004c69f0_typed(&movement,&movement);
      fVar6 = fGpffff8328 * fVar6;
      movement.x = movement.x * fVar6;
      movement.y = movement.y * fVar6;
      movement.z = movement.z * fVar6;
      bVar3 = 1;
    }
    fVar6 = (float)DAT_007e0960[0] - 128.0f;
    if ((fVar6 < -48.0f) || (48.0f <= fVar6)) {
      movement = *(RwV3d *)(iVar1 + 0x10);
      FUN_004c69f0_typed(&movement,&movement);
      fVar6 = fGpffff8328 * fVar6;
      movement.x = movement.x * fVar6;
      movement.y = movement.y * fVar6;
      movement.z = movement.z * fVar6;
      bVar3 = 1;
    }
    if (((DAT_007e094c[0] & 4) == 0) && ((DAT_007e0956[0] & 4) == 0)) {
      if (((DAT_007e094c[0] & 8) != 0) || ((DAT_007e0956[0] & 8) != 0)) {
        movement.y = movement.y + 10.0f;
        bVar3 = 1;
      }
    }
    else {
      movement.y = movement.y - 10.0f;
      bVar3 = 1;
    }
    if (bVar3) {
      cameraPosition = *(RwV3d *)(iVar1 + 0x40);
      negativePosition.x = cameraPosition.x * -1.0f;
      negativePosition.y = cameraPosition.y * -1.0f;
      negativePosition.z = cameraPosition.z * -1.0f;
      FUN_004cb750_typed(iVar1,&negativePosition,2);
      FUN_004cb890_typed((RwFrame *)iVar1,fVar7,&direction,2);
      FUN_004cb750_typed(iVar1,&movement,2);
      FUN_004cb750_typed(iVar1,&cameraPosition,2);
    }
    bVar3 = 0;
  }
  return bVar3;
}

// FUN_0041B530


u8 FUN_0041b530(int param_1)



{

  return *(int *)(*(int *)(param_1 + 0x40) + 4) != 0;

}

// FUN_0041B550 MATCHING


#pragma optimization_level 2
void FUN_0041b550(int param_1)
{
  u32 *effect_data;
  u32 *model_data;

  effect_data = *(u32 **)(param_1 + 0x40);
  model_data = *(u32 **)(effect_data + 1);
  *(u32 *)(param_1 + 0x44) =
      (u32)DAT_006b2aa0 + *(u32 *)*(u32 **)(model_data + 5) * 8;
  *(u32 *)(*(u32 *)(param_1 + 0x3c) + 8) = 0;
  *(u32 *)(*(u32 *)(param_1 + 0x3c) + 0x10) &= ~1;
  FUN_003c49e0(*(int *)(param_1 + 0x40), *(int *)(param_1 + 0x40) + 4,
               (int *)model_data);
}

// W416 width fix: cast uVar8 to s16 at the FUN_003c4b50 argument; nd388/584 -> 350/588, window592.
// FUN_0041B5C0 NONMATCHING


u8 FUN_0041b5c0(int param_1,u32 *param_2)



{

  u8 bVar1;

  int *piVar2;

  int iVar3;

  int iVar4;

  int lVar5;

  int iVar6;

  int *piVar7;

  u16 uVar8;

  int *piVar9;

  int iVar10;

  int *piVar11;

  int aiStack_80 [32];

  

  piVar2 = *(int **)((int)param_1 + 0x3c);

  piVar11 = (int *)*param_2;

  for (iVar10 = 0; iVar10 < (int)param_2[1]; iVar10 = iVar10 + 1) {

    if (*piVar11 == piVar2[2]) {

      piVar9 = (int *)(&DAT_006b30a0);

      piVar7 = aiStack_80;

      iVar6 = 0x1d;

      do {

        iVar4 = *piVar9;

        piVar9 = piVar9 + 1;

        iVar6 = iVar6 + -1;

        *piVar7 = iVar4;

        piVar7 = piVar7 + 1;

      } while (0 < iVar6);

      uVar8 = *(u16 *)(piVar11 + 1);

      if ('?' < (char)*(u8 *)(piVar11 + 1)) {

        uVar8 = (u16)*(u8 *)(piVar11 + 1);

      }

      lVar5 = FUN_003c4b50(*piVar2,*piVar2 + 4,(s16)uVar8);

      if (lVar5 != 0) {

        iVar6 = *(int *)((int)lVar5 + 0x14);

        iVar4 = FUN_003c4910(piVar2[1],*(u16 *)(piVar2[1] + 0x10) + 1,0x8c);

        piVar7 = *(int **)(iVar4 + 0x14);

        *piVar7 = (int)(piVar7 + 0x1c);

        memcpy(piVar7 + 0x1c,piVar11,0x1c);

        piVar7[1] = iVar6;

        piVar7[2] = aiStack_80[*(short *)((int)piVar11 + 6)];

      }

      piVar2[3] = piVar2[3] + 1;

    }

    piVar11 = piVar11 + 7;

  }

  iVar10 = piVar2[1];

  iVar6 = *(int *)(iVar10 + 0xc);

  do {

    do {

      iVar4 = iVar6;

      if (iVar4 == 0) {

LAB_0041b798:

        iVar10 = piVar2[2];

        piVar2[2] = iVar10 + 1;

        if (0x1ffffffe < iVar10 + 1) {

          piVar2[2] = 0x1fffffff;

        }

        bVar1 = (piVar2[4] & 1U) != 0;

        if (bVar1) {

          *(u32 *)((int)param_1 + 0x44) = 0;

        }

        return bVar1;

      }

      iVar3 = *(int *)(iVar4 + 0x14);

      iVar6 = *(int *)(iVar4 + 0x10);

      if (*(int *)(iVar3 + 8) == 0) {

        K_Assert(DAT_006b2ad0,0x833);

      }

      lVar5 = (*(code *)(iVar3 + 8))(param_1,iVar3);

    } while (lVar5 == 0);

    if ((piVar2[4] & 2U) != 0) {

      piVar2[4] = piVar2[4] & 0xfffffffd;

      FUN_003c4a90(iVar10,iVar10 + 4);

      goto LAB_0041b798;

    }

    FUN_003c49e0(iVar10,iVar10 + 4,iVar4);

  } while( 1 );

}

// FUN_0041B810


u64 FUN_0041b810(int param_1)



{

  char cVar1;

  s16 *puVar2;

  int iVar3;

  int iVar4;

  

  for (iVar4 = *(int *)(**(int **)(param_1 + 0x3c) + 0xc); iVar4 != 0;

      iVar4 = *(int *)(iVar4 + 0x10)) {

    puVar2 = *(s16 **)(iVar4 + 0x14);

    if (((*puVar2 & 2) != 0) && ((*puVar2 & 1) != 0)) {

      cVar1 = (char)puVar2[1];

      switch (cVar1) {
      case 1:
        if ((FUN_0034fdb0(*(u32 *)(puVar2 + 4),5), *(int *)(puVar2 + 2) != 0)) {
          iVar3 = FUN_00350070(*(u32 *)(puVar2 + 4));
          if (iVar3 < *(int *)(puVar2 + 2)) {
            continue;
          }
          *puVar2 = *puVar2 & -2;
        }
        break;
      case 2:
        FUN_0041bf80(*(u32 **)(puVar2 + 4));
        break;
      case 6:
        func_0020ac90(*(u32 *)(puVar2 + 4));
        func_0020b250(*(u32 *)(puVar2 + 4));
        break;
      case 3:
        FUN_00317a20(*(u32 *)(puVar2 + 4));
        break;
      default:
        break;
      }

    }

  }

  return 0;

}

// FUN_0041B950


u64 FUN_0041b950(int param_1)
{
  char cVar1;
  s16 *puVar2;
  int iVar3;
  int iVar4;

  for (iVar4 = *(int *)(**(int **)(param_1 + 0x3c) + 0xc); iVar4 != 0;
      iVar4 = *(int *)(iVar4 + 0x10)) {
    puVar2 = *(s16 **)(iVar4 + 0x14);
    if (((*puVar2 & 4) != 0) && ((*puVar2 & 1) != 0)) {
      cVar1 = (char)puVar2[1];
      switch (cVar1) {
      case 1:
        FUN_0034fdb0_fcl(*(u32 *)(puVar2 + 4), 2);
        if (*(int *)(puVar2 + 2) != 0) {
          iVar3 = FUN_00350070(*(u32 *)(puVar2 + 4));
          if (!(iVar3 < *(int *)(puVar2 + 2))) {
            *puVar2 = *puVar2 & ~1;
          }
        }
        break;
      case 3:
        FUN_00317a20(*(u32 *)(puVar2 + 4));
        break;
      case 2:
        FUN_0041bf80(*(u32 **)(puVar2 + 4));
        break;
      }
    }
  }
  return 0;
}

// FUN_0041BA60 MATCHING


u64 FUN_0041ba60(int param_1)
{
  s16 *puVar1;
  int iVar2;

  for (iVar2 = *(int *)(**(int **)(param_1 + 0x3c) + 0xc); iVar2 != 0;
      iVar2 = *(int *)(iVar2 + 0x10)) {
    puVar1 = *(s16 **)(iVar2 + 0x14);
    if (((*puVar1 & 8) != 0) && ((*puVar1 & 1) != 0)) {
      switch ((char)puVar1[1]) {
      case 2:
        FUN_0041bf80(*(u32 **)(puVar1 + 4));
        break;
      default:
        break;
      }
    }
  }
  return 0;
}

// FUN_0041BAF0


u64 FUN_0041baf0(int param_1)



{

  char cVar1;

  s16 *puVar2;

  RwCamera *uVar3;

  RwCamera *lVar4;

  int iVar5;

  float uVar6;

  

  uVar3 = (RwCamera *)kwlnGetMainCamera();

  uVar6 = K_View_GetFov_typed(uVar3);

  uVar3 = (RwCamera *)kwlnGetMainCamera();

  K_View_SetFov_typed(uVar3,30.0f);

  uVar3 = (RwCamera *)kwlnGetMainCamera();

    lVar4 = RwCameraBeginUpdate(uVar3);

  if (lVar4 == 0) {
    return 0;
  }

  kwlnSetFlags(0x40000002,0);

  kwlnSetFlags(2,1);

  for (iVar5 = *(int *)(**(int **)(param_1 + 0x3c) + 0xc); iVar5 != 0;
      iVar5 = *(int *)(iVar5 + 0x10)) {
    puVar2 = *(s16 **)(iVar5 + 0x14);
    if (((*puVar2 & 0x10) != 0) && ((*puVar2 & 1) != 0)) {
      cVar1 = (char)puVar2[1];
      switch (cVar1) {
      case 3:
        FUN_00317a20(*(u32 *)(puVar2 + 4));
        break;
      case 6:
        func_0020ac90(*(u32 *)(puVar2 + 4));
        func_0020b250(*(u32 *)(puVar2 + 4));
        break;
      case 2:
        FUN_0041bf80(*(u32 **)(puVar2 + 4));
        break;
      default:
        break;
      }
    }
  }

  uVar3 = (RwCamera *)kwlnGetMainCamera();

  K_View_SetFov_typed(uVar3,uVar6);

  uVar3 = (RwCamera *)kwlnGetMainCamera();

  RwCameraEndUpdate(uVar3);

  return 0;

}

// FUN_0041BC90


void *FUN_0041bc90(void *param_1,void *param_2,void *param_3,int param_4,void *param_5)
{
  RwV3d *positions;
  RwV2d *texcoords;
  u8 *colors;
  int count;
  void *context;
  u8 *result = 0;
  int alloc_size;
  int i;
  int offset;
  u8 *entry;
  RwV3d position;

  positions = (RwV3d *)param_1;
  texcoords = (RwV2d *)param_2;
  colors = (u8 *)param_3;
  count = param_4;
  context = param_5;
  if (((positions == 0) || (count < 1)) || (context == 0)) {
    K_Assert(DAT_006b2ad0,0x8e7);
  }
  alloc_size = count * 0x24 + 0x14;
  result = (u8 *)(*DAT_00960178_abs)(alloc_size,0x40000);
  memset(result,0,alloc_size);
  *(void **)(result + 0xc) = context;
  *(int *)(result + 8) = count;
  *(u8 **)(result + 4) = result + 0x14;

  i = 0;
  goto check;
loop:
  position.x = positions[i].x;
  position.y = positions[i].y;
  position.z = positions[i].z;
  offset = i * 0x24;
  entry = *(u8 **)(result + 4) + offset;
  *(RwV3d *)entry = position;
  *(f32 *)(*(u8 **)(result + 4) + offset + 0x1c) = texcoords[i].x;
  *(f32 *)(*(u8 **)(result + 4) + offset + 0x20) = texcoords[i].y;
  entry = *(u8 **)(result + 4) + offset;
  *(u8 *)(entry + 0xc) = colors[i * 4];
  *(u8 *)(entry + 0xd) = colors[i * 4 + 1];
  *(u8 *)(entry + 0xe) = colors[i * 4 + 2];
  *(u8 *)(entry + 0xf) = colors[i * 4 + 3];
  i++;
check:
  if (i < count) {
    goto loop;
  }
  *(u32 *)(result + 0x10) = FUN_004c38c0();
  return result;
}

// FUN_0041BE50


u32 FUN_0041be50(int param_1)



{

  u32 uVar1;

  

  uVar1 = 0;

  if (param_1 != 0) {

    uVar1 = *(u32 *)((int)param_1 + 0xc);

    FUN_004c3880(*(u32 *)((int)param_1 + 0x10));

    (*DAT_0096017c_abs)(param_1);

  }

  return uVar1;

}

// FUN_0041BEB0


void FUN_0041beb0(int param_1)



{

  FUN_004c35d0(*(u32 *)(param_1 + 0x10));

  return;

}

// FUN_0041BEE0


void FUN_0041bee0(int param_1)



{

  FUN_004c3760(*(u32 *)(param_1 + 0x10));

  return;

}

// FUN_0041BF10


void FUN_0041bf10(int param_1,u32 param_2)



{

  int iVar1;

  int iVar2;
  u8 bVar1;
  u8 bVar2;
  u8 bVar3;
  u8 bVar4;

  

  for (iVar2 = 0,
       bVar1 = (u8)((u32)param_2 >> 0x18),
       bVar2 = (u8)((u32)param_2 >> 0x10),
       bVar3 = (u8)((u32)param_2 >> 8),
       bVar4 = (u8)param_2;
       iVar2 < *(int *)(param_1 + 8);
       iVar2 = iVar2 + 1) {

    iVar1 = *(int *)(param_1 + 4) + iVar2 * 0x24;

    *(char *)(iVar1 + 0xc) = bVar1;
    *(char *)(iVar1 + 0xd) = bVar2;
    *(char *)(iVar1 + 0xe) = bVar3;
    *(char *)(iVar1 + 0xf) = bVar4;

  }

  return;

}

/* W420 negative: post-match declaration/callback-order probes stayed nd7/object448/window448/rate0.015625; pointer declaration nd11/object448/window448/rate0.024554; iVar3 placement nd8/object448/window448/rate0.017857; while spelling grew nd86/object456/window448/rate0.188596; reverted. */
// FUN_0041BF80


void FUN_0041bf80(u32 *param_1)



{

  u32 uVar1;

  u32 uVar2;

  int lVar4;

  u32 *puVar6;

  u32 *puVar5;

  int iVar3;

  code *callback;

  u32 auStack_40 [16];

  

  callback = (code *)&DAT_00960090_abs;

  (*callback)(9,2);

  (*callback)(0x14,2);

  (*callback)(8,0);

  (*callback)(6,0);

  (*callback)(0xe,0);

  (*callback)(0xc,1);

  (*callback)(7,2);

  (*callback)(10,5);

  (*callback)(0xb,6);

  (*callback)(1,*(u32 *)param_1[3]);

  RpSkyRenderStateSet(2,(void*)0x48);

  RpSkyRenderStateSet(3,(void*)0x71801);

  if ((*param_1 & 1) != 0) {

    iVar3 = kwlnGetMainCamera();

    FUN_004c2f30(auStack_40,(const void *)param_1[4],(const void *)(*(int *)(iVar3 + 4) + 0x10));

  }

  else {

    puVar6 = (u32 *)param_1[4];

    puVar5 = auStack_40;

    iVar3 = 8;

    do {

      uVar1 = *puVar6;

      uVar2 = puVar6[1];

      puVar6 = puVar6 + 2;

      iVar3 = iVar3 + -1;

      *puVar5 = uVar1;

      puVar5[1] = uVar2;

      puVar5 = puVar5 + 2;

    } while (0 < iVar3);

  }

  lVar4 = FUN_004f1ed0(param_1[1],(u16)param_1[2],auStack_40,1);

  if (lVar4 != 0) {

    FUN_004f2150(4);

    FUN_004f1f80();

  }

  return;

}

// FUN_0041C140
void FUN_0041c140(u32 param_1,u32 param_2,u32 param_3,int param_4)
{
  struct Pair {
    float a;
    float b;
  } pair;

  pair = *(struct Pair *)&DAT_007cdae0;
  FUN_0040e3c0(param_1,param_2,param_3,((u32 *)&pair)[param_4]);
  return;
}

// FUN_0041C180 NONMATCHING


void FUN_0041c180(int param_1,int param_2,int param_3)
{
  u32 bigBuf[12][84];
  u32 smallBuf[12][8];
  u32 s0;
  u32 *puVar6;
  u32 *puVar7;
  u32 uVar2;
  u32 uVar3;
  int iVar5;
  u32 result;

  if (param_2 == 5) {
    if (param_3 == 0) {
      s0 = *(u32 *)(param_1 + 0x3ac);
      puVar7 = &DAT_006b3f60;
      puVar6 = bigBuf[1];
      iVar5 = 0x2a;
      do {
        uVar2 = *puVar7;
        uVar3 = puVar7[1];
        puVar7 = puVar7 + 2;
        iVar5 = iVar5 + -1;
        *puVar6 = uVar2;
        puVar6[1] = uVar3;
        puVar6 = puVar6 + 2;
      } while (0 < iVar5);
      bigBuf[1][0] = 5;
      *(u16 *)&bigBuf[1][6] = 0;
      bigBuf[1][7] = 5;
      *(u16 *)&bigBuf[1][13] = 0;
      bigBuf[1][14] = 5;
      *(u16 *)&bigBuf[1][20] = 0;
      bigBuf[1][21] = 5;
      *(u16 *)&bigBuf[1][27] = 0;
      bigBuf[1][28] = 5;
      *(u16 *)&bigBuf[1][34] = 0;
      bigBuf[1][35] = 5;
      *(u16 *)&bigBuf[1][41] = 0;
      bigBuf[1][42] = 5;
      *(u16 *)&bigBuf[1][48] = 0;
      bigBuf[1][49] = 5;
      *(u16 *)&bigBuf[1][55] = 0;
      bigBuf[1][56] = 5;
      *(u16 *)&bigBuf[1][62] = 0;
      bigBuf[1][63] = 5;
      *(u16 *)&bigBuf[1][69] = 0;
      bigBuf[1][70] = 5;
      *(u16 *)&bigBuf[1][76] = 0;
      bigBuf[1][77] = 5;
      *(u16 *)&bigBuf[1][83] = 0;
      memcpy(smallBuf[1], &bigBuf[1][70], 0x1c);
      result = FUN_003dffc0(s0, 5, smallBuf[1][1]);
      fclCombineList003df100(result, smallBuf[1]);
      **(u16 **)(result + 0x34) = 0;
    }
    else if (param_3 == 1) {
      s0 = *(u32 *)(param_1 + 0x3ac);
      puVar7 = &DAT_006b3f60;
      puVar6 = bigBuf[0];
      iVar5 = 0x2a;
      do {
        uVar2 = *puVar7;
        uVar3 = puVar7[1];
        puVar7 = puVar7 + 2;
        iVar5 = iVar5 + -1;
        *puVar6 = uVar2;
        puVar6[1] = uVar3;
        puVar6 = puVar6 + 2;
      } while (0 < iVar5);
      bigBuf[0][0] = 5;
      *(u16 *)&bigBuf[0][6] = 0;
      bigBuf[0][7] = 5;
      *(u16 *)&bigBuf[0][13] = 0;
      bigBuf[0][14] = 5;
      *(u16 *)&bigBuf[0][20] = 0;
      bigBuf[0][21] = 5;
      *(u16 *)&bigBuf[0][27] = 0;
      bigBuf[0][28] = 5;
      *(u16 *)&bigBuf[0][34] = 0;
      bigBuf[0][35] = 5;
      *(u16 *)&bigBuf[0][41] = 0;
      bigBuf[0][42] = 5;
      *(u16 *)&bigBuf[0][48] = 0;
      bigBuf[0][49] = 5;
      *(u16 *)&bigBuf[0][55] = 0;
      bigBuf[0][56] = 5;
      *(u16 *)&bigBuf[0][62] = 0;
      bigBuf[0][63] = 5;
      *(u16 *)&bigBuf[0][69] = 0;
      bigBuf[0][70] = 5;
      *(u16 *)&bigBuf[0][76] = 0;
      bigBuf[0][77] = 5;
      *(u16 *)&bigBuf[0][83] = 0;
      memcpy(smallBuf[0], &bigBuf[0][77], 0x1c);
      result = FUN_003dffc0(s0, 5, smallBuf[0][1]);
      fclCombineList003df100(result, smallBuf[0]);
      **(u16 **)(result + 0x34) = 0;
    }
  }
  else if (param_2 == 4) {
    if (param_3 == 0) {
      s0 = *(u32 *)(param_1 + 0x3ac);
      puVar7 = &DAT_006b3f60;
      puVar6 = bigBuf[3];
      iVar5 = 0x2a;
      do {
        uVar2 = *puVar7;
        uVar3 = puVar7[1];
        puVar7 = puVar7 + 2;
        iVar5 = iVar5 + -1;
        *puVar6 = uVar2;
        puVar6[1] = uVar3;
        puVar6 = puVar6 + 2;
      } while (0 < iVar5);
      bigBuf[3][0] = 4;
      *(u16 *)&bigBuf[3][6] = 0;
      bigBuf[3][7] = 4;
      *(u16 *)&bigBuf[3][13] = 0;
      bigBuf[3][14] = 4;
      *(u16 *)&bigBuf[3][20] = 0;
      bigBuf[3][21] = 4;
      *(u16 *)&bigBuf[3][27] = 0;
      bigBuf[3][28] = 4;
      *(u16 *)&bigBuf[3][34] = 0;
      bigBuf[3][35] = 4;
      *(u16 *)&bigBuf[3][41] = 0;
      bigBuf[3][42] = 4;
      *(u16 *)&bigBuf[3][48] = 0;
      bigBuf[3][49] = 4;
      *(u16 *)&bigBuf[3][55] = 0;
      bigBuf[3][56] = 4;
      *(u16 *)&bigBuf[3][62] = 0;
      bigBuf[3][63] = 4;
      *(u16 *)&bigBuf[3][69] = 0;
      bigBuf[3][70] = 4;
      *(u16 *)&bigBuf[3][76] = 0;
      bigBuf[3][77] = 4;
      *(u16 *)&bigBuf[3][83] = 0;
      memcpy(smallBuf[3], &bigBuf[3][56], 0x1c);
      result = FUN_003dffc0(s0, 4, smallBuf[3][1]);
      fclCombineList003df100(result, smallBuf[3]);
    }
    else if (param_3 == 1) {
      s0 = *(u32 *)(param_1 + 0x3ac);
      puVar7 = &DAT_006b3f60;
      puVar6 = bigBuf[2];
      iVar5 = 0x2a;
      do {
        uVar2 = *puVar7;
        uVar3 = puVar7[1];
        puVar7 = puVar7 + 2;
        iVar5 = iVar5 + -1;
        *puVar6 = uVar2;
        puVar6[1] = uVar3;
        puVar6 = puVar6 + 2;
      } while (0 < iVar5);
      bigBuf[2][0] = 4;
      *(u16 *)&bigBuf[2][6] = 0;
      bigBuf[2][7] = 4;
      *(u16 *)&bigBuf[2][13] = 0;
      bigBuf[2][14] = 4;
      *(u16 *)&bigBuf[2][20] = 0;
      bigBuf[2][21] = 4;
      *(u16 *)&bigBuf[2][27] = 0;
      bigBuf[2][28] = 4;
      *(u16 *)&bigBuf[2][34] = 0;
      bigBuf[2][35] = 4;
      *(u16 *)&bigBuf[2][41] = 0;
      bigBuf[2][42] = 4;
      *(u16 *)&bigBuf[2][48] = 0;
      bigBuf[2][49] = 4;
      *(u16 *)&bigBuf[2][55] = 0;
      bigBuf[2][56] = 4;
      *(u16 *)&bigBuf[2][62] = 0;
      bigBuf[2][63] = 4;
      *(u16 *)&bigBuf[2][69] = 0;
      bigBuf[2][70] = 4;
      *(u16 *)&bigBuf[2][76] = 0;
      bigBuf[2][77] = 4;
      *(u16 *)&bigBuf[2][83] = 0;
      memcpy(smallBuf[2], &bigBuf[2][63], 0x1c);
      result = FUN_003dffc0(s0, 4, smallBuf[2][1]);
      fclCombineList003df100(result, smallBuf[2]);
    }
  }
  else if (param_2 == 6) {
    if (param_3 == 0) {
      s0 = *(u32 *)(param_1 + 0x3ac);
      puVar7 = &DAT_006b3f60;
      puVar6 = bigBuf[7];
      iVar5 = 0x2a;
      do {
        uVar2 = *puVar7;
        uVar3 = puVar7[1];
        puVar7 = puVar7 + 2;
        iVar5 = iVar5 + -1;
        *puVar6 = uVar2;
        puVar6[1] = uVar3;
        puVar6 = puVar6 + 2;
      } while (0 < iVar5);
      bigBuf[7][0] = 1;
      *(u16 *)&bigBuf[7][6] = 0;
      bigBuf[7][7] = 1;
      *(u16 *)&bigBuf[7][13] = 0;
      bigBuf[7][14] = 1;
      *(u16 *)&bigBuf[7][20] = 0;
      bigBuf[7][21] = 1;
      *(u16 *)&bigBuf[7][27] = 0;
      bigBuf[7][28] = 1;
      *(u16 *)&bigBuf[7][34] = 0;
      bigBuf[7][35] = 1;
      *(u16 *)&bigBuf[7][41] = 0;
      bigBuf[7][42] = 1;
      *(u16 *)&bigBuf[7][48] = 0;
      bigBuf[7][49] = 1;
      *(u16 *)&bigBuf[7][55] = 0;
      bigBuf[7][56] = 1;
      *(u16 *)&bigBuf[7][62] = 0;
      bigBuf[7][63] = 1;
      *(u16 *)&bigBuf[7][69] = 0;
      bigBuf[7][70] = 1;
      *(u16 *)&bigBuf[7][76] = 0;
      bigBuf[7][77] = 1;
      *(u16 *)&bigBuf[7][83] = 0;
      memcpy(smallBuf[7], &bigBuf[7][42], 0x1c);
      result = FUN_003dffc0(s0, 1, smallBuf[7][1]);
      fclCombineList003df100(result, smallBuf[7]);
      s0 = *(u32 *)(param_1 + 0x3ac);
      puVar7 = &DAT_006b3f60;
      puVar6 = bigBuf[6];
      iVar5 = 0x2a;
      do {
        uVar2 = *puVar7;
        uVar3 = puVar7[1];
        puVar7 = puVar7 + 2;
        iVar5 = iVar5 + -1;
        *puVar6 = uVar2;
        puVar6[1] = uVar3;
        puVar6 = puVar6 + 2;
      } while (0 < iVar5);
      bigBuf[6][0] = 2;
      *(u16 *)&bigBuf[6][6] = 0;
      bigBuf[6][7] = 2;
      *(u16 *)&bigBuf[6][13] = 0;
      bigBuf[6][14] = 2;
      *(u16 *)&bigBuf[6][20] = 0;
      bigBuf[6][21] = 2;
      *(u16 *)&bigBuf[6][27] = 0;
      bigBuf[6][28] = 2;
      *(u16 *)&bigBuf[6][34] = 0;
      bigBuf[6][35] = 2;
      *(u16 *)&bigBuf[6][41] = 0;
      bigBuf[6][42] = 2;
      *(u16 *)&bigBuf[6][48] = 0;
      bigBuf[6][49] = 2;
      *(u16 *)&bigBuf[6][55] = 0;
      bigBuf[6][56] = 2;
      *(u16 *)&bigBuf[6][62] = 0;
      bigBuf[6][63] = 2;
      *(u16 *)&bigBuf[6][69] = 0;
      bigBuf[6][70] = 2;
      *(u16 *)&bigBuf[6][76] = 0;
      bigBuf[6][77] = 2;
      *(u16 *)&bigBuf[6][83] = 0;
      memcpy(smallBuf[6], &bigBuf[6][21], 0x1c);
      result = FUN_003dffc0(s0, 2, smallBuf[6][1]);
      fclCombineList003df100(result, smallBuf[6]);
      s0 = *(u32 *)(param_1 + 0x3ac);
      puVar7 = &DAT_006b3f60;
      puVar6 = bigBuf[5];
      iVar5 = 0x2a;
      do {
        uVar2 = *puVar7;
        uVar3 = puVar7[1];
        puVar7 = puVar7 + 2;
        iVar5 = iVar5 + -1;
        *puVar6 = uVar2;
        puVar6[1] = uVar3;
        puVar6 = puVar6 + 2;
      } while (0 < iVar5);
      bigBuf[5][0] = 3;
      *(u16 *)&bigBuf[5][6] = 0;
      bigBuf[5][7] = 3;
      *(u16 *)&bigBuf[5][13] = 0;
      bigBuf[5][14] = 3;
      *(u16 *)&bigBuf[5][20] = 0;
      bigBuf[5][21] = 3;
      *(u16 *)&bigBuf[5][27] = 0;
      bigBuf[5][28] = 3;
      *(u16 *)&bigBuf[5][34] = 0;
      bigBuf[5][35] = 3;
      *(u16 *)&bigBuf[5][41] = 0;
      bigBuf[5][42] = 3;
      *(u16 *)&bigBuf[5][48] = 0;
      bigBuf[5][49] = 3;
      *(u16 *)&bigBuf[5][55] = 0;
      bigBuf[5][56] = 3;
      *(u16 *)&bigBuf[5][62] = 0;
      bigBuf[5][63] = 3;
      *(u16 *)&bigBuf[5][69] = 0;
      bigBuf[5][70] = 3;
      *(u16 *)&bigBuf[5][76] = 0;
      bigBuf[5][77] = 3;
      *(u16 *)&bigBuf[5][83] = 0;
      memcpy(smallBuf[5], &bigBuf[5][35], 0x1c);
      result = FUN_003dffc0(s0, 3, smallBuf[5][1]);
      fclCombineList003df100(result, smallBuf[5]);
    }
    else if (param_3 == 1) {
      s0 = *(u32 *)(param_1 + 0x3ac);
      puVar7 = &DAT_006b3f60;
      puVar6 = bigBuf[4];
      iVar5 = 0x2a;
      do {
        uVar2 = *puVar7;
        uVar3 = puVar7[1];
        puVar7 = puVar7 + 2;
        iVar5 = iVar5 + -1;
        *puVar6 = uVar2;
        puVar6[1] = uVar3;
        puVar6 = puVar6 + 2;
      } while (0 < iVar5);
      bigBuf[4][0] = 1;
      *(u16 *)&bigBuf[4][6] = 0;
      bigBuf[4][7] = 1;
      *(u16 *)&bigBuf[4][13] = 0;
      bigBuf[4][14] = 1;
      *(u16 *)&bigBuf[4][20] = 0;
      bigBuf[4][21] = 1;
      *(u16 *)&bigBuf[4][27] = 0;
      bigBuf[4][28] = 1;
      *(u16 *)&bigBuf[4][34] = 0;
      bigBuf[4][35] = 1;
      *(u16 *)&bigBuf[4][41] = 0;
      bigBuf[4][42] = 1;
      *(u16 *)&bigBuf[4][48] = 0;
      bigBuf[4][49] = 1;
      *(u16 *)&bigBuf[4][55] = 0;
      bigBuf[4][56] = 1;
      *(u16 *)&bigBuf[4][62] = 0;
      bigBuf[4][63] = 1;
      *(u16 *)&bigBuf[4][69] = 0;
      bigBuf[4][70] = 1;
      *(u16 *)&bigBuf[4][76] = 0;
      bigBuf[4][77] = 1;
      *(u16 *)&bigBuf[4][83] = 0;
      memcpy(smallBuf[4], &bigBuf[4][49], 0x1c);
      result = FUN_003dffc0(s0, 1, smallBuf[4][1]);
      fclCombineList003df100(result, smallBuf[4]);
      s0 = *(u32 *)(param_1 + 0x3ac);
      puVar7 = &DAT_006b3f60;
      puVar6 = bigBuf[3];
      iVar5 = 0x2a;
      do {
        uVar2 = *puVar7;
        uVar3 = puVar7[1];
        puVar7 = puVar7 + 2;
        iVar5 = iVar5 + -1;
        *puVar6 = uVar2;
        puVar6[1] = uVar3;
        puVar6 = puVar6 + 2;
      } while (0 < iVar5);
      bigBuf[3][0] = 2;
      *(u16 *)&bigBuf[3][6] = 0;
      bigBuf[3][7] = 2;
      *(u16 *)&bigBuf[3][13] = 0;
      bigBuf[3][14] = 2;
      *(u16 *)&bigBuf[3][20] = 0;
      bigBuf[3][21] = 2;
      *(u16 *)&bigBuf[3][27] = 0;
      bigBuf[3][28] = 2;
      *(u16 *)&bigBuf[3][34] = 0;
      bigBuf[3][35] = 2;
      *(u16 *)&bigBuf[3][41] = 0;
      bigBuf[3][42] = 2;
      *(u16 *)&bigBuf[3][48] = 0;
      bigBuf[3][49] = 2;
      *(u16 *)&bigBuf[3][55] = 0;
      bigBuf[3][56] = 2;
      *(u16 *)&bigBuf[3][62] = 0;
      bigBuf[3][63] = 2;
      *(u16 *)&bigBuf[3][69] = 0;
      bigBuf[3][70] = 2;
      *(u16 *)&bigBuf[3][76] = 0;
      bigBuf[3][77] = 2;
      *(u16 *)&bigBuf[3][83] = 0;
      memcpy(smallBuf[3], &bigBuf[3][56], 0x1c);
      result = FUN_003dffc0(s0, 2, smallBuf[3][1]);
      fclCombineList003df100(result, smallBuf[3]);
      s0 = *(u32 *)(param_1 + 0x3ac);
      puVar7 = &DAT_006b3f60;
      puVar6 = bigBuf[2];
      iVar5 = 0x2a;
      do {
        uVar2 = *puVar7;
        uVar3 = puVar7[1];
        puVar7 = puVar7 + 2;
        iVar5 = iVar5 + -1;
        *puVar6 = uVar2;
        puVar6[1] = uVar3;
        puVar6 = puVar6 + 2;
      } while (0 < iVar5);
      bigBuf[2][0] = 3;
      *(u16 *)&bigBuf[2][6] = 0;
      bigBuf[2][7] = 3;
      *(u16 *)&bigBuf[2][13] = 0;
      bigBuf[2][14] = 3;
      *(u16 *)&bigBuf[2][20] = 0;
      bigBuf[2][21] = 3;
      *(u16 *)&bigBuf[2][27] = 0;
      bigBuf[2][28] = 3;
      *(u16 *)&bigBuf[2][34] = 0;
      bigBuf[2][35] = 3;
      *(u16 *)&bigBuf[2][41] = 0;
      bigBuf[2][42] = 3;
      *(u16 *)&bigBuf[2][48] = 0;
      bigBuf[2][49] = 3;
      *(u16 *)&bigBuf[2][55] = 0;
      bigBuf[2][56] = 3;
      *(u16 *)&bigBuf[2][62] = 0;
      bigBuf[2][63] = 3;
      *(u16 *)&bigBuf[2][69] = 0;
      bigBuf[2][70] = 3;
      *(u16 *)&bigBuf[2][76] = 0;
      bigBuf[2][77] = 3;
      *(u16 *)&bigBuf[2][83] = 0;
      memcpy(smallBuf[2], &bigBuf[2][63], 0x1c);
      result = FUN_003dffc0(s0, 3, smallBuf[2][1]);
      fclCombineList003df100(result, smallBuf[2]);
    }
  }
  else if (param_2 == 0) {
    if (param_3 == 0) {
      s0 = *(u32 *)(param_1 + 0x3ac);
      puVar7 = &DAT_006b3f60;
      puVar6 = bigBuf[11];
      iVar5 = 0x2a;
      do {
        uVar2 = *puVar7;
        uVar3 = puVar7[1];
        puVar7 = puVar7 + 2;
        iVar5 = iVar5 + -1;
        *puVar6 = uVar2;
        puVar6[1] = uVar3;
        puVar6 = puVar6 + 2;
      } while (0 < iVar5);
      bigBuf[11][0] = 0;
      *(u16 *)&bigBuf[11][6] = 0;
      bigBuf[11][7] = 0;
      *(u16 *)&bigBuf[11][13] = 0;
      bigBuf[11][14] = 0;
      *(u16 *)&bigBuf[11][20] = 0;
      bigBuf[11][21] = 0;
      *(u16 *)&bigBuf[11][27] = 0;
      bigBuf[11][28] = 0;
      *(u16 *)&bigBuf[11][34] = 0;
      bigBuf[11][35] = 0;
      *(u16 *)&bigBuf[11][41] = 0;
      bigBuf[11][42] = 0;
      *(u16 *)&bigBuf[11][48] = 0;
      bigBuf[11][49] = 0;
      *(u16 *)&bigBuf[11][55] = 0;
      bigBuf[11][56] = 0;
      *(u16 *)&bigBuf[11][62] = 0;
      bigBuf[11][63] = 0;
      *(u16 *)&bigBuf[11][69] = 0;
      bigBuf[11][70] = 0;
      *(u16 *)&bigBuf[11][76] = 0;
      bigBuf[11][77] = 0;
      *(u16 *)&bigBuf[11][83] = 0;
      memcpy(smallBuf[11], &bigBuf[11][0], 0x1c);
      result = FUN_003dffc0(s0, 0, smallBuf[11][1]);
      fclCombineList003df100(result, smallBuf[11]);
    }
    else if (param_3 == 1) {
      s0 = *(u32 *)(param_1 + 0x3ac);
      puVar7 = &DAT_006b3f60;
      puVar6 = bigBuf[10];
      iVar5 = 0x2a;
      do {
        uVar2 = *puVar7;
        uVar3 = puVar7[1];
        puVar7 = puVar7 + 2;
        iVar5 = iVar5 + -1;
        *puVar6 = uVar2;
        puVar6[1] = uVar3;
        puVar6 = puVar6 + 2;
      } while (0 < iVar5);
      bigBuf[10][0] = 0;
      *(u16 *)&bigBuf[10][6] = 0;
      bigBuf[10][7] = 0;
      *(u16 *)&bigBuf[10][13] = 0;
      bigBuf[10][14] = 0;
      *(u16 *)&bigBuf[10][20] = 0;
      bigBuf[10][21] = 0;
      *(u16 *)&bigBuf[10][27] = 0;
      bigBuf[10][28] = 0;
      *(u16 *)&bigBuf[10][34] = 0;
      bigBuf[10][35] = 0;
      *(u16 *)&bigBuf[10][41] = 0;
      bigBuf[10][42] = 0;
      *(u16 *)&bigBuf[10][48] = 0;
      bigBuf[10][49] = 0;
      *(u16 *)&bigBuf[10][55] = 0;
      bigBuf[10][56] = 0;
      *(u16 *)&bigBuf[10][62] = 0;
      bigBuf[10][63] = 0;
      *(u16 *)&bigBuf[10][69] = 0;
      bigBuf[10][70] = 0;
      *(u16 *)&bigBuf[10][76] = 0;
      bigBuf[10][77] = 0;
      *(u16 *)&bigBuf[10][83] = 0;
      memcpy(smallBuf[10], &bigBuf[10][7], 0x1c);
      result = FUN_003dffc0(s0, 0, smallBuf[10][1]);
      fclCombineList003df100(result, smallBuf[10]);
    }
  }
  return;
}






























































// FUN_004241d0
u32 Y_Misc_GetT0Count()
{
    return DGET_T0_COUNT();
}
#ifndef Y_MISC_RW_TYPES
typedef struct RwV2d { f32 x; f32 y; } RwV2d;
typedef struct RwV3d { f32 x; f32 y; f32 z; } RwV3d;
typedef struct RwV4dTag { f32 x; f32 y; f32 z; f32 w; } RwV4d;
#endif

// HARVESTED 3D-42FF

// FUN_004241E0


void FUN_004241e0(u64 param_1,s8 *param_2)
{
  u32 uVar1;
  u32 *puVar2;
  uVar1 = FUN_00421de0(*param_2,param_2[1],param_2[2],param_2[3],param_2[4]);
  puVar2 = (u32 *)FUN_00421760();
  *puVar2 = uVar1;
  return;
}

// FUN_00424230


u32 FUN_00424230(void)
{
  int *piVar1;
  u32 *puVar2;
  u32 uVar3;
  piVar1 = (int *)FUN_00421760();
  if (*piVar1 != 0) {
    puVar2 = (u32 *)FUN_00421760();
    uVar3 = FUN_00421ef0(*puVar2);
    if (uVar3 == 1) {
      puVar2 = (u32 *)FUN_00421760();
      kwlnTaskDestroyWithHierarchy(*puVar2);
      puVar2 = (u32 *)FUN_00421760();
      *puVar2 = 0;
      return 0;
    }
  }
  return 0xffffffff;
}

// FUN_004242B0


u8 FUN_004242b0(void)
{
  u32 *puVar1;
  u32 uVar2;
  puVar1 = (u32 *)FUN_00421760();
  uVar2 = kwlnTaskExists(*puVar1);
  if (uVar2 == 1) {
    return 0;
  }
  puVar1 = (u32 *)FUN_00421760();
  *puVar1 = 0;
  return 1;
}

// FUN_00424310


u32 FUN_00424310(void)



{

  u8 auStack_8 [8];

  

  auStack_8[0] = scrGetIntPara(0);

  func_00109f60(4,0);

  adminiChangeSeq(4,auStack_8,5,0);

  return 1;

}

// FUN_00424370


u32 FUN_00424370(void)
{
  u8 uVar1;
  u32 uVar2;
  u32 *puVar3;

  uVar1 = scrGetIntPara(0);
  *(u8 *)(DAT_007ce6a8 + 6) = uVar1;
  uVar2 = FUN_004264d0_u32(0, *(s8 *)((u8 *)DAT_007ce6a8 + 6));
  puVar3 = FUN_00426090();
  *puVar3 = uVar2;
  return 1;
}

// FUN_004243D0


u32 FUN_004243d0(void)



{

  u8 uVar1;

  

  uVar1 = scrGetIntPara(0);

  *DAT_007ce6a8 = uVar1;

  uVar1 = scrGetIntPara(1);

  DAT_007ce6a8[1] = uVar1;

  uVar1 = scrGetIntPara(2);

  DAT_007ce6a8[2] = uVar1;

  uVar1 = scrGetIntPara(3);

  DAT_007ce6a8[3] = uVar1;

  uVar1 = scrGetIntPara(4);

  DAT_007ce6a8[4] = uVar1;

  uVar1 = scrGetIntPara(5);

  DAT_007ce6a8[5] = uVar1;

  DAT_007ce6b0 = 0;

  return 1;

}

// FUN_00424470
u32 FUN_00424470(void)
{
  u32 uVar1;

  uVar1 = 1;
  cGpffffb9c0 = uVar1;
  return uVar1;
}

// FUN_00424480
u32 FUN_00424480(void)
{
  return *(char *)(iGpffffb9b8 + 8) == 1;
}

// FUN_004244A0
u32 FUN_004244a0(void)
{
  u8 uVar1;

  uVar1 = scrGetIntPara(0);
  *(u8 *)(DAT_007ce6a8 + 10) = uVar1;
  iGpffffb9b8[9] = 1;
  return 1;
}

// FUN_004244E0


u32 FUN_004244e0(void)



{

  short sVar1;

  int iVar4;

  int lVar3;

  int iVar2;

  

  lVar3 = scrGetIntPara(0);

  if ((0 < lVar3) && (lVar3 < 0xc)) {

    iVar2 = func_0016f490((short)(lVar3 + 0x100));

    for (iVar4 = 0; iVar4 < 0x14; iVar4 = iVar4 + 1) {

      sVar1 = func_00170ab0((short)lVar3,(short)iVar4);

      if (0 < sVar1) {

        iVar2 = iVar2 + 1;

      }

    }

    scrSetIntReturnVal(iVar2);

  }
  else {
    scrSetIntReturnVal(0);
  }

  return 1;

}

// FUN_004245C0


u32 FUN_004245c0(void)
{
  int iVar4;
  int iVar5;
  int lVar6;
  int iVar8;
  u32 uVar7;
  u16 uVar2;
  short sVar3;

  uVar7 = 0xffffffffffffffff;
  lVar6 = scrGetIntPara(0);
  iVar4 = scrGetIntPara(1);
  if ((0 < lVar6) && (lVar6 < 0xc)) {
    iVar5 = func_0016f490(lVar6 + 0x100);
    if ((iVar4 < iVar5) && (0 < iVar5)) {
      uVar2 = datGetEquipmentId(lVar6 + 0x100,iVar4);
      scrSetIntReturnVal(uVar2);
      return 1;
    } else {
      for (iVar8 = 0; iVar8 < 0x14; iVar8 = iVar8 + 1) {
        sVar3 = func_00170ab0(lVar6,(short)iVar8);
        if (0 < sVar3) {
          if (iVar4 == iVar5) {
            uVar7 = func_00170a40(lVar6,(short)iVar8);
            uVar7 = uVar7 & 0xffff;
          }
          iVar5 = iVar5 + 1;
        }
      }
      scrSetIntReturnVal(uVar7);
    }
  } else {
    scrSetIntReturnVal(0);
  }
  return 1;
}

// FUN_00424730


u32 FUN_00424730(void)
{
  s32 result = -1;
  s32 type = scrGetIntPara(0);
  s32 index = scrGetIntPara(1);
  s32 count;
  s32 i;

  if ((type > 0) && (type < 12)) {
    count = func_0016f490((s16)(type + 0x100));
    if ((index < count) && (count > 0)) {
      scrSetIntReturnVal(1);
      return 1;
    } else {
      for (i = 0; i < 20; i++) {
        if (func_00170ab0((s16)type, (s16)i) > 0) {
          if (index == count) {
            result = func_00170ab0((s16)type, (s16)i);
          }
          count++;
        }
      }
      scrSetIntReturnVal(result);
    }
  } else {
    scrSetIntReturnVal(0);
  }
  return 1;
}

// MWCC b210 register-colouring floor: retail swaps $s1/$s2 throughout the function.
// Moving the result declaration after the type initializer regressed nd10 -> nd19 and was reverted.
// W416 measured negative: retail offset 84 and ours both use the same dsll32/dsra32 shift 0x10 pair; the residual is register colouring.
// FUN_00424880 NONMATCHING


u32 FUN_00424880(void)
{
  s32 result = 0;
  s32 type = scrGetIntPara(0);
  s32 index = scrGetIntPara(1);
  s32 count;

  if ((type > 0) && (type < 12)) {
    count = func_0016f490((s16)(type + 0x100));
    if ((index < count) && (count > 0)) {
      result = func_0016f810((s16)(type + 0x100), index);
      scrSetIntReturnVal((u8)result);
      return 1;
    }
    for (index = 0; index < 20; index++) {
      if (func_00170ab0((s16)type, (s16)index) > 0) {
        result = 0;
      }
    }
    scrSetIntReturnVal(result);
  } else {
    scrSetIntReturnVal(0);
  }
  return 1;
}

// FUN_004249B0


u32 FUN_004249b0(void)



{

  char bVar1;

  int uVar2;

  u32 active;

  int iVar4;

  

  bVar1 = 0;

  uVar2 = scrGetIntPara(0);

  if ((0 < uVar2) && (uVar2 < 0xc)) {

    for (iVar4 = 0; iVar4 < 0x14; iVar4 = iVar4 + 1) {


      func_00170b20((short)uVar2,(short)iVar4,0);

      func_00170b90((short)uVar2,(short)iVar4,0);

      func_0016fea0((short)(uVar2 + 0x100),iVar4,0);

    }


    active = (0 != DAT_008719a8_abs[0]);
    if (active) {
      active = (0 != DAT_008719b4_abs[0]);
    }
    if (active && DAT_00871b08_abs[0] == uVar2) {
      DAT_007ce6cc_byte = 0;
      bVar1 = 1;
    }

    active = (0 != DAT_00871b68_abs[0]);
    if (active) {
      active = (0 != DAT_00871b74_abs[0]);
    }
    if (active && DAT_00871cc8_abs[0] == uVar2) {
      DAT_007ce6d0_byte = 0;
      bVar1 = 1;
    }

    active = (0 != DAT_00871d28_abs[0]);
    if (active) {
      active = (0 != DAT_00871d34_abs[0]);
    }
    if (active && DAT_00871e88_abs[0] == uVar2) {
      DAT_007ce6d4_byte = 0;
      bVar1 = 1;
    }

  }

  if ((s8)bVar1 == 0) {

    DAT_007ce6cc_byte = 0;

    DAT_007ce6d0_byte = 0;

    DAT_007ce6d4_byte = 0;

  }

  return 1;

}

// FUN_00424B60 NONMATCHING


u32 FUN_00424b60(void)
{
  u8 bVar1;
  u8 bVar2;
  short sVar3;
  int iVar4;
  int lVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  short unaff_s5_lo;
  YRuntimeUnitRow *selectedRow;
  YajimaVec3 pos;
  YajimaVec3 copiedPos;
  char acStack_4 [4];

  sVar8 = 2;
  bVar2 = 0;
  iVar7 = 0;
  FUN_0016f3e0(0,0);
  sVar3 = scrGetIntPara(0);
  {
    int scanIndex;
    YRuntimeUnitRow *rows = DAT_008717a0_unit_rows_abs;
    for (scanIndex = 0; scanIndex < 4; scanIndex = scanIndex + 1) {
      YRuntimeUnitRow *row = &rows[scanIndex];
      acStack_4[scanIndex] = '\0';
      bVar1 = 0;
      if ((row->unk_048 != 0) && (row->unk_054 != 0)) {
        bVar1 = 1;
      }
      if ((bVar1) && ((long)sVar3 == row->unit_id)) {
        unaff_s5_lo = (short)scanIndex;
      }
    }
  }
  selectedRow = &DAT_008717a0_unit_rows_abs[unaff_s5_lo];
  for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {
    YRuntimeUnitRow *row = &DAT_008717a0_unit_rows_abs[iVar6];
    bVar1 = 0;
    if ((row->unk_048 != 0) && (row->unk_054 != 0)) {
      bVar1 = 1;
    }
    if ((bVar1) &&
       (lVar5 = K_FldEvent_AreUnitsWithinDist(0x43fa0000,selectedRow), lVar5 == 1)) {
      sVar3 = FUN_0043a9d0_y2((char)unaff_s5_lo,(char)iVar6,0);
      if (sVar3 != 2) {
        sVar8 = sVar3;
      }
      if ((sVar3 == 0) || (sVar3 == 1)) {
        bVar2 = 1;
        acStack_4[iVar6] = '\x01';
      }
      else if (sVar3 == 5) {
        for (iVar4 = 0; iVar4 < 4; iVar4 = iVar4 + 1) {
          YRuntimeUnitRow *row = &DAT_008717a0_unit_rows_abs[iVar4];
          bVar1 = 0;
          if ((row->unk_048 != 0) && (row->unk_054 != 0)) {
            bVar1 = 1;
          }
          if ((bVar1) &&
             (lVar5 = K_FldEvent_AreUnitsWithinDist(0x43fa0000,selectedRow), lVar5 == 1)) {
            acStack_4[iVar4] = '\x01';
            bVar2 = 1;
          }
        }
      }
    }
  }
  for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {
    if (acStack_4[iVar6] == '\x01') {
      iVar7 = iVar7 + 1;
      K_FldFrame_CtlCopyPos(&pos,*(u32 *)((u8 *)DAT_008717a0_unit_rows_abs[iVar6].unk_054 + 0x1e0));
      copiedPos = pos;
      iVar4 = K_Field_Get();
      func_001a9760(*(u32 *)(iVar4 + 0x10),6,&copiedPos,3,1);
      FUN_0016f3e0(0,iVar7);
    }
  }
  if ((bVar2) && (sVar8 == 4)) {
    sVar8 = 0;
  }
  if (sVar8 == 5) {
    sVar8 = 1;
  }
  scrSetIntReturnVal(sVar8);
  return 1;
}

// FUN_00424F10


u32 FUN_00424f10(void)
{
  s16 uVar1;
  int iVar2;

  iVar2 = scrGetUnkF0();
  if (*(u16 *)(iVar2 + 0x1aa) == 0xfb5) {
    uVar1 = 0;
    goto done;
  }
  if ((*(u16 *)(iVar2 + 0x1ac) & 1) != 0) {
    uVar1 = 1;
    goto done;
  }
  uVar1 = 2;
done:
  scrSetIntReturnVal(uVar1);
  return 1;
}

// FUN_00424F80


void FUN_00424f80(void)



{
  u8 *entry;
  u32 bVar1;
  int iVar2;

  for (iVar2 = 1; iVar2 < 4; iVar2 = iVar2 + 1) {
    bVar1 = 0;
    entry = DAT_008717e8_abs + iVar2 * 0x1c0;
    if ((*(u32 *)(entry + 0x48) != 0) && (*(u32 *)(entry + 0x54) != 0)) {
      bVar1 = 1;
    }
    bVar1 = bVar1 > 0;
    if (bVar1 == 1) {
      func_001b00c0(*(u32 *)
                    (*(int *)(*(int *)(*(int *)(entry + 0x16c) + 0x3c) + 0x24) +
                    0x170));
    }
  }

  return;

}

// FUN_00425020


u32 FUN_00425020(void)



{

  if (DAT_007ce6ac != 0) {

    DAT_007ce6ac = 0;

  }

  DAT_007ce6ac = FUN_00447e70_y2(0,1,0);

  return 1;

}

// FUN_00425070


u32 FUN_00425070(void)
{
  if (DAT_007ce6ac != 0) {
    return 0;
  }
  FUN_00449fa0_y2();
  return 1;
}

// FUN_004250B0


u32 FUN_004250b0(void)



{

  u8 uVar1;

  

  uVar1 = scrGetIntPara(0);

  *(u8 *)(DAT_007ce6ec + 0xad) = uVar1;

  return 1;

}

// FUN_004250E0


u32 FUN_004250e0(void)



{

  char cVar1;

  char uVar2;

  u16 uVar3;

  int iVar4;

  

  cVar1 = scrGetIntPara(0);

  uVar2 = scrGetIntPara(1);

  uVar3 = scrGetIntPara(2);

  iVar4 = (char)(cVar1 + -1) * 6;

  *(u16 *)((u8 *)(uintptr_t)Yajima_AddOffsetFirst(
      (uintptr_t)iVar4, (uintptr_t)DAT_007ce6ec_abs) + 0x7c) = uVar3;

  *(u16 *)((u8 *)(uintptr_t)Yajima_AddOffsetFirst(
      (uintptr_t)iVar4, (uintptr_t)DAT_007ce6ec_abs) + 0x7e) = 0;

  *(u16 *)((u8 *)(uintptr_t)Yajima_AddOffsetFirst(
      (uintptr_t)iVar4, (uintptr_t)DAT_007ce6ec_abs) + 0x80) = 0;

  *(u8 *)((u8 *)(uintptr_t)Yajima_AddOffsetFirst(
      (uintptr_t)(char)(cVar1 + -1), (uintptr_t)DAT_007ce6ec_abs) + 0xa6) = uVar2;

  return 1;

}

// FUN_00425190


u32 FUN_00425190(void)



{

  int iVar1;

  u8 uVar2;

  u16 uVar3;

  int lVar4;

  

  lVar4 = scrGetIntPara(0);


  if (lVar4 != 0) {
    iVar1 = (int)DAT_007ce6ec_abs;

    uVar2 = scrGetIntPara(0);

    *(u8 *)((u8 *)(uintptr_t)Yajima_AddOffsetFirst(
        (u32)*(s8 *)(iVar1 + 0xa0) * 4, (uintptr_t)iVar1) + 4) = uVar2;

    iVar1 = (int)DAT_007ce6ec_abs;

    uVar3 = scrGetIntPara(1);

    *(u16 *)((u8 *)(uintptr_t)Yajima_AddOffsetFirst(
        (u32)*(s8 *)(iVar1 + 0xa0) * 4, (uintptr_t)iVar1) + 6) = uVar3;

    *(char *)(DAT_007ce6ec_abs + 0xa0) = *(char *)(DAT_007ce6ec_abs + 0xa0) + '\x01';

  }

  return 1;

}

// FUN_00425220


u32 FUN_00425220(void)



{

  u8 uVar1;

  u16 uVar2;

  

  uVar1 = scrGetIntPara(0);

  *(u8 *)(DAT_007ce6ec + 0xa4) = uVar1;

  uVar2 = scrGetIntPara(1);

  *(u16 *)(DAT_007ce6ec + 0xa2) = uVar2;

  return 1;

}

// FUN_00425270


u32 FUN_00425270(void)



{

  u8 uVar1;

  

  uVar1 = scrGetIntPara(0);

  *(u8 *)(DAT_007ce6ec + 0xae) = uVar1;

  return 1;

}

// FUN_004252A0


u32 FUN_004252a0(void)



{

  u8 uVar1;

  

  uVar1 = scrGetIntPara(0);

  *(u8 *)(DAT_007ce6ec + 0xaf) = uVar1;

  return 1;

}

// FUN_004252D0


u32 FUN_004252d0(void)



{

  if (DAT_007ce6ac != 0) {

    DAT_007ce6ac = 0;

  }

  DAT_007ce6ac = FUN_00447e70_y2(0,0,0);

  return 1;

}

// FUN_00425320


u32 FUN_00425320(void)
{
  if (DAT_007ce6ac != 0) {
    return 0;
  }
  FUN_00449fa0_y2();
  return 1;
}

// FUN_00425360


u32 FUN_00425360(void)
{
  int iVar1;
  for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
    FUN_00458850_y2(*(u32 *)(DAT_0086e6a0 + iVar1 * 0x1c0 + 0x16c));
  }
  return 1;
}

// FUN_004253D0


u32 FUN_004253d0(void)



{

  short sVar1;

  u32 uVar2;

  int iVar3;

  int iVar4;

  

  sVar1 = scrGetIntPara(0);

  iVar4 = sVar1 * 0x10;

  uVar2 = scrGetIntPara(1);

  *(u32 *)(DAT_0086be00_abs + iVar4) = uVar2;

  iVar3 = scrGetIntPara(2);

  *(float *)(DAT_0086be04_abs + iVar4) = (float)iVar3;

  iVar3 = scrGetIntPara(3);

  *(float *)(DAT_0086be0c_abs + iVar4) = (float)iVar3;

  return 1;

}

// FUN_00425480


u32 FUN_00425480(void)



{

  u32 uVar1;

  

  uVar1 = scrGetIntPara(0);

  FUN_0045a280_y2(0,uVar1);

  return 1;

}

// FUN_004254C0


u32 FUN_004254c0(void)
{
  u32 uVar1;
  uVar1 = 0;
  if (DAT_007ce6f8 == 0) {
    scrSetIntReturnVal(-1);
  }
  if (FUN_0045a3b0_y2() == 1) {
    uVar1 = 1;
  }
  scrSetIntReturnVal(uVar1);
  return 1;
}

// FUN_00425530


u32 FUN_00425530(void)



{

  if (DAT_007ce6f8 == 0) {

    scrSetIntReturnVal(-1);

  }

  FUN_0045a3e0_y2();

  scrSetIntReturnVal(0);

  return 1;

}

// FUN_00425580


u32 FUN_00425580(void)



{

  if (DAT_007ce6f8 == 0) {

    scrSetIntReturnVal(-1);

  }

  Y_TimeLimit_Stop();

  scrSetIntReturnVal(0);

  return 1;

}

// FUN_004255D0


u32 FUN_004255d0(void)



{

  int iVar1;

  

  iVar1 = scrGetIntPara(0);

  if (DAT_007ce6f8 == 0) {

    scrSetIntReturnVal(-1);

  }

  FUN_0045a430_y2((s8)iVar1);

  scrSetIntReturnVal(0);

  return 1;

}

// FUN_00425640


u32 FUN_00425640(void)
{
  u32 uVar1;
  if (DAT_007ce6f8 == 0) {
    scrSetIntReturnVal(-1);
  }
  uVar1 = FUN_0045af40_y2();
  scrSetIntReturnVal(uVar1);
  return 1;
}

// FUN_00425690 NONMATCHING


u32 FUN_00425690(int param_1)



{

  char cVar1;

  char *pcVar2;

  u32 uVar3;

  int iVar4;

  int iVar5;

  u32 *puVar6;

  u32 uVar7;

  u32 uVar8;

  u32 uVar9;

  int lVar10;

  YajimaVec4 ambientColor;

  YajimaVec4 directionalColor;

  float auStack_70[16];

  float *puVar6f;

  float *puVar11;
  u32 uStack_4;

  

  pcVar2 = *(char **)(param_1 + 0x3c);

  iVar4 = MT_Scene_GetResListHead(4);

  iVar5 = kwlnGetAmbientLight();

  ambientColor = *(YajimaVec4 *)(iVar5 + 0x18);

  iVar5 = kwlnGetDirectionalLight();

  directionalColor = *(YajimaVec4 *)(iVar5 + 0x18);

  iVar5 = kwlnGetDirectionalLight();

  puVar11 = (float *)(*(int *)(iVar5 + 4) + 0x10);

  puVar6f = auStack_70;
  iVar5 = 8;

  do {
    *puVar6f = *puVar11;
    puVar6f[1] = puVar11[1];
    puVar11 = puVar11 + 2;
    iVar5 = iVar5 + -1;
    puVar6f = puVar6f + 2;
  } while (0 < iVar5);

  uVar8 = kwlnGetWorld(DAT_007ce0cc);

  uVar9 = func_00198580();

  FUN_0049c480(uVar8,uVar9);

  uVar8 = kwlnGetAmbientLight();

  uVar9 = K_Scene_GetFldAmbLightColor();

  FUN_004944b0(uVar8,(u32 *)uVar9);

  uVar8 = kwlnGetDirectionalLight();

  FUN_004944b0(uVar8,(u32 *)(iVar4 + 0x110));

  iVar5 = kwlnGetDirectionalLight();

  FUN_004cb7f0(*(u32 *)(iVar5 + 4),iVar4 + 0x120,0);

  uVar8 = kwlnGetMainCamera();

  lVar10 = RwCameraBeginUpdate_u32(uVar8);

  if (lVar10 != 0) {

    cVar1 = *pcVar2;

    switch (cVar1) {
    case '\0':
      puVar6 = (u32 *)FUN_00421760();
      uVar8 = FUN_00421f10(*puVar6);
      for (iVar4 = 1; iVar4 < 7; iVar4 = iVar4 + 1) {
        uVar9 = H_Cdvd_ArchiveGetFile(uVar8,iVar4 + -1,&uStack_4);
        uVar7 = mdlCreateFromRmdMemory(0,0,uVar9,uStack_4,0);
        *(u32 *)(&DAT_0095be9c + iVar4 * 4) = uVar7;
      }
      for (iVar4 = 0; iVar4 < 6; iVar4 = iVar4 + 1) {
        uVar9 = H_Cdvd_ArchiveGetFile(uVar8,iVar4 + 6,&uStack_4);
        uVar7 = mdlCreateFromRmdMemory(0,0,uVar9,uStack_4,0);
        (&DAT_0095bec0)[iVar4] = uVar7;
      }
      *pcVar2 = '\x01';
    case '\x01':
      lVar10 = mdlStreamRead(DAT_0095bec0);
      if (((((lVar10 == 0) || (lVar10 = mdlStreamRead(DAT_0095bec4), lVar10 == 0)) ||
           (lVar10 = mdlStreamRead(DAT_0095bec8), lVar10 == 0)) ||
          ((((lVar10 = mdlStreamRead(DAT_0095becc), lVar10 == 0 ||
             (lVar10 = mdlStreamRead(DAT_0095bed0), lVar10 == 0)) ||
            ((lVar10 = mdlStreamRead(DAT_0095bed4), lVar10 == 0 ||
             ((lVar10 = mdlStreamRead(DAT_0095bea0), lVar10 == 0 ||
              (lVar10 = mdlStreamRead(DAT_0095bea4), lVar10 == 0)))))) ||
           (lVar10 = mdlStreamRead(DAT_0095bea8), lVar10 == 0)))) ||
         (((lVar10 = mdlStreamRead(DAT_0095beac), lVar10 == 0 ||
            (lVar10 = mdlStreamRead(DAT_0095beb0), lVar10 == 0)) ||
           (lVar10 = mdlStreamRead(DAT_0095beb4), lVar10 == 0)))) goto LAB_00425aec;
      mdlAnimSet((&DAT_0095bec0)[pcVar2[1]],0,0,0,1);
      *pcVar2 = '\x02';
    case '\x02':
      FUN_00317a20((&DAT_0095bec0)[pcVar2[1]]);
      FUN_00317a20((&DAT_0095bea0)[pcVar2[3]]);
      break;
    case '\x03':
      FUN_00317a20((&DAT_0095bea0)[pcVar2[3]]);
      break;
    case '\x04':
      FUN_00317a20((&DAT_0095bec0)[pcVar2[2]]);
      break;
    default:
      goto LAB_00425aec;
    }

  }

LAB_00425aec:

  uVar8 = kwlnGetMainCamera();

  RwCameraEndUpdate_u32(uVar8);

  uVar8 = kwlnGetWorld(DAT_007ce0cc);

  uVar9 = func_00198580();

  FUN_0049c3d0(uVar8,uVar9);

  uVar8 = kwlnGetAmbientLight();

  FUN_004944b0(uVar8,(u32 *)&ambientColor);

  uVar8 = kwlnGetDirectionalLight();

  FUN_004944b0(uVar8,(u32 *)&directionalColor);

  iVar4 = kwlnGetDirectionalLight();

  FUN_004cb7f0(*(u32 *)(iVar4 + 4),auStack_70,0);

  return 0;

}

// FUN_00425BA0


void FUN_00425ba0(int param_1)



{

  int object = param_1;
  {
    int iVar1;
    for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
      if (((u32 *)DAT_0095bec0_abs)[iVar1] != 0) {
        mdlDestroy(((u32 *)DAT_0095bec0_abs)[iVar1]);
      }
    }
  }
  {
    int iVar1;
    for (iVar1 = 0; iVar1 < 6; iVar1 = iVar1 + 1) {
      if (((u32 *)DAT_0095bea0_abs)[iVar1] != 0) {
        mdlDestroy(((u32 *)DAT_0095bea0_abs)[iVar1]);
      }
    }
  }
  (DAT_0096017c_abs[0x5f])(*(u32 *)(object + 0x3c));

  return;

}

// FUN_00425C60


u32 FUN_00425c60(u64 param_1,u8 param_2)
{
  u8 *lVar1;
  u32 uVar2;

  lVar1 = (u8 *)(uintptr_t)(*DAT_00960184_abs)(1,4,0x40000);

  if (lVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = kwlnTaskCreate(param_1, DAT_006b4400, 0x831,
                           (void *)FUN_00425690, (void *)FUN_00425ba0,
                           lVar1);

    lVar1[0] = 0;
    lVar1[1] = param_2;
    lVar1[2] = 0;
  }

  return uVar2;
}

// FUN_00425D10


void FUN_00425d10(int param_1,u8 param_2)



{

  u8 *puVar1;

  

  puVar1 = *(u8 **)(param_1 + 0x3c);

  puVar1[1] = param_2;

  *puVar1 = 1;

  return;

}

// FUN_00425D30

void FUN_00425d30(int param_1,u8 param_2,u8 param_3)
{
  u8 *work;

  work = *(u8 **)(param_1 + 0x3c);
  work[1] = param_2;
  work[2] = param_3;
  *(u8 *)&DAT_007ce6b4 = param_2;
}

// FUN_00425D50 NONMATCHING


u32 FUN_00425d50(s8 param_1,s8 param_2)



{

  u32 uVar1;

  

  uVar1 = 0;

  switch(param_1) {

  case 0:

    switch(param_2) {

    case 0:

      break;

    case 1:

      uVar1 = 1;

      break;

    case 2:

      uVar1 = 2;

      break;

    case 3:

      uVar1 = 3;

      break;

    case 4:

      uVar1 = 4;

      break;

    case 5:

      uVar1 = 5;

    }

    break;

  case 1:

    switch(param_2) {

    case 0:

      uVar1 = 1;

      break;

    case 1:

      break;

    case 2:

      uVar1 = 2;

      break;

    case 3:

      uVar1 = 3;

      break;

    case 4:

      uVar1 = 4;

      break;

    case 5:

      uVar1 = 5;

    }

    break;

  case 2:

    switch(param_2) {

    case 0:

      uVar1 = 1;

      break;

    case 1:

      uVar1 = 2;

      break;

    case 2:

      break;

    case 3:

      uVar1 = 3;

      break;

    case 4:

      uVar1 = 4;

      break;

    case 5:

      uVar1 = 5;

    }

    break;

  case 3:

    switch(param_2) {

    case 0:

      uVar1 = 1;

      break;

    case 1:

      uVar1 = 2;

      break;

    case 2:

      uVar1 = 3;

      break;

    case 3:

      break;

    case 4:

      uVar1 = 4;

      break;

    case 5:

      uVar1 = 5;

    }

    break;

  case 4:

    switch(param_2) {

    case 0:

      uVar1 = 1;

      break;

    case 1:

      uVar1 = 2;

      break;

    case 2:

      uVar1 = 3;

      break;

    case 3:

      uVar1 = 4;

      break;

    case 4:

      break;

    case 5:

      uVar1 = 5;

    }

    break;

  case 5:

    switch(param_2) {

    case 0:

      uVar1 = 1;

      break;

    case 1:

      uVar1 = 2;

      break;

    case 2:

      uVar1 = 3;

      break;

    case 3:

      uVar1 = 4;

      break;

    case 4:

      uVar1 = 5;

    }

  }

  return uVar1;

}

// FUN_00426040


void FUN_00426040(int param_1,u8 param_2)



{

  *(u8 *)(*(int *)(param_1 + 0x3c) + 3) = param_2;

  return;

}

// FUN_00426050


void FUN_00426050(int param_1)



{

  **(u8 **)(param_1 + 0x3c) = 3;

  return;

}

// FUN_00426070


u8 FUN_00426070(int param_1)



{

  return **(char **)(param_1 + 0x3c) != '\x02';

}

// FUN_00426090


u32 * FUN_00426090(void)



{

  return &DAT_007ce6b8;

}

// W415 ORDER probe negative: ascending switch measured nd474/992 -> nd483/1000; rejected.
// FUN_004260A0 NONMATCHING


u64 FUN_004260a0(int param_1)



{

  char *pcVar1;

  u32 uVar2;

  u32 uVar3;

  u8 uVar4;

  char cVar5;

  int iVar6;

  int iVar7;

  u32 uVar8;

  u32 uVar9;

  int lVar10;

  YajimaVec4 ambientColor;

  YajimaVec4 directionalColor;

  u32 auStack_60 [16];

  u32 *puVar11;

  u32 *puVar12;

  

  iVar6 = MT_Scene_GetResListHead(4);

  pcVar1 = *(char **)(param_1 + 0x3c);

  iVar7 = kwlnGetAmbientLight();

  ambientColor = *(YajimaVec4 *)(iVar7 + 0x18);

  iVar7 = kwlnGetDirectionalLight();

  directionalColor = *(YajimaVec4 *)(iVar7 + 0x18);

  iVar7 = kwlnGetDirectionalLight();

  puVar12 = (u32 *)(*(int *)(iVar7 + 4) + 0x10);

  puVar11 = auStack_60;

  iVar7 = 8;

  do {

    uVar2 = *puVar12;

    uVar3 = puVar12[1];

    puVar12 = puVar12 + 2;

    iVar7 = iVar7 + -1;

    *puVar11 = uVar2;

    puVar11[1] = uVar3;

    puVar11 = puVar11 + 2;

  } while (0 < iVar7);

  uVar8 = kwlnGetWorld(DAT_007ce0cc);

  uVar9 = func_00198580();

  FUN_0049c480(uVar8,uVar9);

  uVar8 = kwlnGetAmbientLight();

  uVar9 = K_Scene_GetFldAmbLightColor();

  FUN_004944b0(uVar8,(u32 *)uVar9);

  uVar8 = kwlnGetDirectionalLight();

  FUN_004944b0(uVar8,(u32 *)(iVar6 + 0x110));

  iVar7 = kwlnGetDirectionalLight();

  FUN_004cb7f0(*(u32 *)(iVar7 + 4),iVar6 + 0x120,0);

  uVar8 = kwlnGetMainCamera();

  lVar10 = RwCameraBeginUpdate_u32(uVar8);

  if (lVar10 != 0) {

    cVar5 = *pcVar1;

    if (cVar5 == '\x02') {

      FUN_00317a20((&DAT_0095bec0)[DAT_007ce6b4]);

      *(u8 *)(DAT_007ce6a8 + 8) = 1;

    }

    else if (cVar5 == '\x01') {
      uVar4 = FUN_00425d50(1,(u8)pcVar1[1]);

      FUN_00317a20((&DAT_0095bec0)[DAT_007ce6b4]);

      if ((DAT_007e094c_u32 & 0x20) != 0) {

        mdlAnimSetSpeed((&DAT_0095bec0)[DAT_007ce6b4],0,2.0f);

      }

      else {

        mdlAnimSetSpeed((&DAT_0095bec0)[DAT_007ce6b4],0,1.0f);

      }

      if (*(char *)((&DAT_0095bec0)[DAT_007ce6b4] + 0xee) == '\x01') {

        *pcVar1 = '\x02';

        DAT_007ce6b4 = pcVar1[1];

        mdlAnimSet((&DAT_0095bec0)[DAT_007ce6b4],0,0,0,0);

      }

    }

    else if (cVar5 == '\0') {

      uVar4 = FUN_00425d50(0,(u8)pcVar1[1]);

      mdlAnimSet((&DAT_0095bec0)[DAT_007ce6b4],0,uVar4,0,0);

      *pcVar1 = '\x01';


      if (cVar5 == '\0') {

        DAT_007ce6b4 = pcVar1[1];

        mdlAnimSet((&DAT_0095bec0)[DAT_007ce6b4],0,0,0,0);

        *pcVar1 = '\x02';

      }

    }

  }

  uVar8 = kwlnGetMainCamera();

  RwCameraEndUpdate_u32(uVar8);

  uVar8 = kwlnGetWorld(DAT_007ce0cc);

  uVar9 = func_00198580();

  FUN_0049c3d0(uVar8,uVar9);

  uVar8 = kwlnGetAmbientLight();

  FUN_004944b0(uVar8,(u32 *)&ambientColor);

  uVar8 = kwlnGetDirectionalLight();

  FUN_004944b0(uVar8,(u32 *)&directionalColor);

  iVar6 = kwlnGetDirectionalLight();

  FUN_004cb7f0(*(u32 *)(iVar6 + 4),auStack_60,0);

  return 0;

}

// FUN_004264A0


void FUN_004264a0(int param_1)



{

  DAT_0096017c_abs[0](*(u32 *)(param_1 + 0x3c));

  return;

}

// FUN_004264D0


u32 FUN_004264d0(u64 param_1,s8 param_2)



{

  u32 lVar1;

  u32 uVar2;

  

  memset(&DAT_007ce6b8,0,4);

  lVar1 = (*DAT_00960184_abs)(1,2,0x40000);

  if (lVar1 == 0) {

    uVar2 = 0;

  }

  else {

    uVar2 = kwlnTaskCreate(param_1,DAT_006b4400 + 0x20,0x831,FUN_004260a0,FUN_004264a0,lVar1);

    *(u8 *)lVar1 = 0;

    ((u8 *)lVar1)[1] = param_2;

    DAT_007ce6b8 = (u32)uVar2;

    *(u8 *)(DAT_007ce6a8 + 8) = 0;

  }

  return uVar2;

}

// FUN_00426590 NONMATCHING
 #define DAT_00960090 Yajima_setState


u32 FUN_00426590(int param_1)



{

  char cVar1;

  char *pcVar2;
  char *entry;
  char *color;

  int iVar3;

  u32 uVar4;

  float fVar5;

  float fVar6;
  code *Yajima_setState;

  

  pcVar2 = *(char **)(param_1 + 0x3c);

  cVar1 = pcVar2[0x18c];
  Yajima_setState = (code *)&DAT_00960090_abs;

  if (cVar1 == '\0') {

    (*DAT_00960090)(6,1);

    (*DAT_00960090)(7,2);

    (*DAT_00960090)(8,1);

    (*DAT_00960090)(10,5);

    (*DAT_00960090)(0xb,6);

    (*DAT_00960090)(9,1);

    (*DAT_00960090)(0xc,1);

    (*DAT_00960090)(1,**(u32 **)(pcVar2 + 0x13c));

    (*DAT_00960090)(2,3);

    RpSkyRenderStateSet_u32(2,0x44);

    RpSkyRenderStateSet_u32(3,0x717fb);

  }

  else if (cVar1 == '\x01') {

    (*DAT_00960090)(6);

    (*DAT_00960090)(7,2);

    (*DAT_00960090)(8,1);

    (*DAT_00960090)(10,5);

    (*DAT_00960090)(0xb,6);

    (*DAT_00960090)(9,2);

    (*DAT_00960090)(0xc,1);

    (*DAT_00960090)(1,**(u32 **)(pcVar2 + 0x13c));

    (*DAT_00960090)(2,3);

    RpSkyRenderStateSet_u32(2,0x44);

    RpSkyRenderStateSet_u32(3,0x717fb);

  }

  else if (cVar1 == '\x02') {

    (*DAT_00960090)(6);

    (*DAT_00960090)(7,2);

    (*DAT_00960090)(8,1);

    (*DAT_00960090)(10,5);

    (*DAT_00960090)(0xb,6);

    (*DAT_00960090)(9,2);

    (*DAT_00960090)(0xc,1);

    (*DAT_00960090)(1,**(u32 **)(pcVar2 + 0x13c));

    (*DAT_00960090)(2,3);

    RpSkyRenderStateSet_u32(2,0x48);

    RpSkyRenderStateSet_u32(3,0x71801);

  }

  if (pcVar2[0x150] != '\x01') {

    cVar1 = *pcVar2;

    if (cVar1 != '\x02') {

      if ((cVar1 == '\x01') || (cVar1 == '\0')) {

        iVar3 = kwlnGetMainCamera();

        fVar5 = 1.0f / *(float *)(iVar3 + 0x80);

        cVar1 = pcVar2[0x141];

        switch (cVar1) { case '\0': if (pcVar2[0x150] == '\0') {
        
          for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
            entry = pcVar2 + iVar3 * 0x40;
            color = pcVar2 + iVar3 * 4 + 0x110;
        
            *(float *)(entry + 0x18) = DAT_00960088 - *(float *)(pcVar2 + 0x130);
        
            *(float *)(entry + 0x28) = fVar5;
        
            *(float *)(entry + 0x30) = (float)(u8)color[0];
        
            *(float *)(entry + 0x34) = (float)(u8)color[1];
        
            *(float *)(entry + 0x38) = (float)(u8)color[2];
        
            *(float *)(entry + 0x3c) = (float)(u8)color[3];
        
          }
        
        }
        
        else if (pcVar2[0x150] == '\x01') {
        
          return 0;
        
        }
        
        *(u32 *)(pcVar2 + 0x20) = *(u32 *)(pcVar2 + 0x17c);
        
        *(u32 *)(pcVar2 + 0x24) = *(u32 *)(pcVar2 + 0x180);
        
        *(u32 *)(pcVar2 + 0x60) = *(u32 *)(pcVar2 + 0x174);
        
        *(u32 *)(pcVar2 + 100) = *(u32 *)(pcVar2 + 0x180);
        
        *(u32 *)(pcVar2 + 0xa0) = *(u32 *)(pcVar2 + 0x17c);
        
        *(u32 *)(pcVar2 + 0xa4) = *(u32 *)(pcVar2 + 0x178);
        
        *(u32 *)(pcVar2 + 0xe0) = *(u32 *)(pcVar2 + 0x174);
        
        *(u32 *)(pcVar2 + 0xe4) = *(u32 *)(pcVar2 + 0x178);
        
        cVar1 = pcVar2[0x140];
        
        if (cVar1 == '\x03') {
        
          *(u32 *)(pcVar2 + 0x90) = *(u32 *)(pcVar2 + 0x134);
        
          *(u32 *)(pcVar2 + 0x94) = *(u32 *)(pcVar2 + 0x138);
        
          *(float *)(pcVar2 + 0x10) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(u32 *)(pcVar2 + 0x14) = *(u32 *)(pcVar2 + 0x138);
        
          *(u32 *)(pcVar2 + 0xd0) = *(u32 *)(pcVar2 + 0x134);
        
          *(float *)(pcVar2 + 0xd4) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
          *(float *)(pcVar2 + 0x50) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(float *)(pcVar2 + 0x54) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
        }
        
        else if (cVar1 == '\x02') {
        
          *(u32 *)(pcVar2 + 0xd0) = *(u32 *)(pcVar2 + 0x134);
        
          *(u32 *)(pcVar2 + 0xd4) = *(u32 *)(pcVar2 + 0x138);
        
          *(float *)(pcVar2 + 0x90) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(u32 *)(pcVar2 + 0x94) = *(u32 *)(pcVar2 + 0x138);
        
          *(u32 *)(pcVar2 + 0x50) = *(u32 *)(pcVar2 + 0x134);
        
          *(float *)(pcVar2 + 0x54) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
          *(float *)(pcVar2 + 0x10) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(float *)(pcVar2 + 0x14) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
        }
        
        else if (cVar1 == '\x01') {
        
          *(u32 *)(pcVar2 + 0x50) = *(u32 *)(pcVar2 + 0x134);
        
          *(u32 *)(pcVar2 + 0x54) = *(u32 *)(pcVar2 + 0x138);
        
          *(float *)(pcVar2 + 0xd0) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(u32 *)(pcVar2 + 0xd4) = *(u32 *)(pcVar2 + 0x138);
        
          *(u32 *)(pcVar2 + 0x10) = *(u32 *)(pcVar2 + 0x134);
        
          *(float *)(pcVar2 + 0x14) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
          *(float *)(pcVar2 + 0x90) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(float *)(pcVar2 + 0x94) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
        }
        
        else if (cVar1 == '\0') {
        
          *(u32 *)(pcVar2 + 0x10) = *(u32 *)(pcVar2 + 0x134);
        
          *(u32 *)(pcVar2 + 0x14) = *(u32 *)(pcVar2 + 0x138);
        
          *(float *)(pcVar2 + 0x50) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(u32 *)(pcVar2 + 0x54) = *(u32 *)(pcVar2 + 0x138);
        
          *(u32 *)(pcVar2 + 0x90) = *(u32 *)(pcVar2 + 0x134);
        
          *(float *)(pcVar2 + 0x94) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
          *(float *)(pcVar2 + 0xd0) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(float *)(pcVar2 + 0xd4) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
        }
        
        (*DAT_009600a0)(4,pcVar2 + 0x10,4); break; case '\x01': for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
          entry = pcVar2 + iVar3 * 0x40;
          color = pcVar2 + iVar3 * 4 + 0x110;
        
          *(float *)(entry + 0x18) = DAT_00960088 - *(float *)(pcVar2 + 0x130);
        
          *(float *)(entry + 0x28) = fVar5;
        
          *(float *)(entry + 0x30) = (float)(u8)color[0];
        
          *(float *)(entry + 0x34) = (float)(u8)color[1];
        
          *(float *)(entry + 0x38) = (float)(u8)color[2];
        
          *(float *)(entry + 0x3c) = (float)(u8)color[3];
        
        }
        
        *(u32 *)(pcVar2 + 0x20) = 0;
        
        *(u32 *)(pcVar2 + 0x24) = 0;
        
        *(float *)(pcVar2 + 0x10) =
        
             *(float *)(pcVar2 + 0x134) -
        
             ((float)*(int *)(pcVar2 + 0x128) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        *(float *)(pcVar2 + 0x14) =
        
             *(float *)(pcVar2 + 0x138) -
        
             ((float)*(int *)(pcVar2 + 300) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        *(float *)(pcVar2 + 0x60) = 1.0f;
        
        *(u32 *)(pcVar2 + 0x64) = 0;
        
        *(float *)(pcVar2 + 0x50) =
        
             *(float *)(pcVar2 + 0x134) +
        
             ((float)*(int *)(pcVar2 + 0x128) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        *(float *)(pcVar2 + 0x54) =
        
             *(float *)(pcVar2 + 0x138) -
        
             ((float)*(int *)(pcVar2 + 300) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        *(u32 *)(pcVar2 + 0xa0) = 0;
        
        *(float *)(pcVar2 + 0xa4) = 1.0f;
        
        *(float *)(pcVar2 + 0x90) =
        
             *(float *)(pcVar2 + 0x134) -
        
             ((float)*(int *)(pcVar2 + 0x128) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        *(float *)(pcVar2 + 0x94) =
        
             *(float *)(pcVar2 + 0x138) +
        
             ((float)*(int *)(pcVar2 + 300) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        *(float *)(pcVar2 + 0xe0) = 1.0f;
        
        *(float *)(pcVar2 + 0xe4) = 1.0f;
        
        *(float *)(pcVar2 + 0xd0) =
        
             *(float *)(pcVar2 + 0x134) +
        
             ((float)*(int *)(pcVar2 + 0x128) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        *(float *)(pcVar2 + 0xd4) =
        
             *(float *)(pcVar2 + 0x138) +
        
             ((float)*(int *)(pcVar2 + 300) * *(float *)(pcVar2 + 0x14c)) / 2.0f;
        
        (*DAT_009600a0)(4,pcVar2 + 0x10,4); break; case '\x02': for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
          entry = pcVar2 + iVar3 * 0x40;
          color = pcVar2 + iVar3 * 4 + 0x110;
        
          *(float *)(entry + 0x18) = DAT_00960088 - *(float *)(pcVar2 + 0x130);
        
          *(float *)(entry + 0x28) = fVar5;
        
          *(float *)(entry + 0x30) = (float)(u8)color[0];
        
          *(float *)(entry + 0x34) = (float)(u8)color[1];
        
          *(float *)(entry + 0x38) = (float)(u8)color[2];
        
          *(float *)(entry + 0x3c) = (float)(u8)color[3];
        
        }
        
        *(u32 *)(pcVar2 + 0x20) = 0;
        
        *(u32 *)(pcVar2 + 0x24) = 0;
        
        *(u32 *)(pcVar2 + 0x10) = *(u32 *)(pcVar2 + 0x134);
        
        *(u32 *)(pcVar2 + 0x14) = *(u32 *)(pcVar2 + 0x138);
        
        *(float *)(pcVar2 + 0x60) = 1.0f;
        
        *(u32 *)(pcVar2 + 0x64) = 0;
        
        *(float *)(pcVar2 + 0x50) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128);
        
        *(u32 *)(pcVar2 + 0x54) = *(u32 *)(pcVar2 + 0x138);
        
        *(u32 *)(pcVar2 + 0xa0) = 0;
        
        *(float *)(pcVar2 + 0xa4) = 1.0f;
        
        *(u32 *)(pcVar2 + 0x90) = *(u32 *)(pcVar2 + 0x134);
        
        *(float *)(pcVar2 + 0x94) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
        *(float *)(pcVar2 + 0xe0) = 1.0f;
        
        *(float *)(pcVar2 + 0xe4) = 1.0f;
        
        *(float *)(pcVar2 + 0xd0) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128);
        
        *(float *)(pcVar2 + 0xd4) = *(float *)(pcVar2 + 0x138) + (float)*(int *)(pcVar2 + 300);
        
        (*DAT_009600a0)(4,pcVar2 + 0x10,4); break; case '\x03': for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
          entry = pcVar2 + iVar3 * 0x40;
          color = pcVar2 + iVar3 * 4 + 0x110;
        
          *(float *)(entry + 0x18) = DAT_00960088 - *(float *)(pcVar2 + 0x130);
        
          *(float *)(entry + 0x28) = fVar5;
        
          *(float *)(entry + 0x30) = (float)(u8)color[0];
        
          *(float *)(entry + 0x34) = (float)(u8)color[1];
        
          *(float *)(entry + 0x38) = (float)(u8)color[2];
        
          *(float *)(entry + 0x3c) = (float)(u8)color[3];
        
        }
        
        *(u32 *)(pcVar2 + 0x20) = 0;
        
        *(u32 *)(pcVar2 + 0x24) = 0;
        
        *(u32 *)(pcVar2 + 0x10) = *(u32 *)(pcVar2 + 0x134);
        
        *(u32 *)(pcVar2 + 0x14) = *(u32 *)(pcVar2 + 0x138);
        
        *(u32 *)(pcVar2 + 0x60) = *(u32 *)(pcVar2 + 0x174);
        
        *(u32 *)(pcVar2 + 0x64) = 0;
        
        *(float *)(pcVar2 + 0x50) = *(float *)(pcVar2 + 0x134) + *(float *)(pcVar2 + 0x184);
        
        *(u32 *)(pcVar2 + 0x54) = *(u32 *)(pcVar2 + 0x138);
        
        *(u32 *)(pcVar2 + 0xa0) = 0;
        
        *(u32 *)(pcVar2 + 0xa4) = *(u32 *)(pcVar2 + 0x178);
        
        *(u32 *)(pcVar2 + 0x90) = *(u32 *)(pcVar2 + 0x134);
        
        *(float *)(pcVar2 + 0x94) = *(float *)(pcVar2 + 0x138) + *(float *)(pcVar2 + 0x188);
        
        *(u32 *)(pcVar2 + 0xe0) = *(u32 *)(pcVar2 + 0x174);
        
        *(u32 *)(pcVar2 + 0xe4) = *(u32 *)(pcVar2 + 0x178);
        
        *(float *)(pcVar2 + 0xd0) = *(float *)(pcVar2 + 0x134) + *(float *)(pcVar2 + 0x184);
        
        *(float *)(pcVar2 + 0xd4) = *(float *)(pcVar2 + 0x138) + *(float *)(pcVar2 + 0x188);
        
        (*DAT_009600a0)(4,pcVar2 + 0x10,4); break; case '\x04': for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {
          entry = pcVar2 + iVar3 * 0x40;
          color = pcVar2 + iVar3 * 4 + 0x110;
        
          *(float *)(entry + 0x18) = DAT_00960088 - *(float *)(pcVar2 + 0x130);
        
          *(float *)(entry + 0x28) = fVar5;
        
          *(float *)(entry + 0x30) = (float)(u8)color[0];
        
          *(float *)(entry + 0x34) = (float)(u8)color[1];
        
          *(float *)(entry + 0x38) = (float)(u8)color[2];
        
          *(float *)(entry + 0x3c) = (float)(u8)color[3];
        
        }
        
        for (iVar3 = 0; iVar3 < *(int *)(pcVar2 + 300); iVar3 = iVar3 + 1) {
        
          *(u32 *)(pcVar2 + 0x20) = 0;
        
          fVar5 = (float)iVar3;
        
          *(float *)(pcVar2 + 0x24) = (1.0f / (float)*(int *)(pcVar2 + 300)) * fVar5;
        
          *(float *)(pcVar2 + 0x60) = 1.0f;
        
          *(float *)(pcVar2 + 100) = (1.0f / (float)*(int *)(pcVar2 + 300)) * fVar5;
        
          *(u32 *)(pcVar2 + 0xa0) = 0;
        
          fVar6 = (float)(iVar3 + 1);
        
          *(float *)(pcVar2 + 0xa4) = (1.0f / (float)*(int *)(pcVar2 + 300)) * fVar6;
        
          *(float *)(pcVar2 + 0xe0) = 1.0f;
        
          *(float *)(pcVar2 + 0xe4) = (1.0f / (float)*(int *)(pcVar2 + 300)) * fVar6;
        
          *(u32 *)(pcVar2 + 0x10) = *(u32 *)(pcVar2 + 0x134);
        
          *(float *)(pcVar2 + 0x14) = *(float *)(pcVar2 + 0x138) + fVar5;
        
          *(float *)(pcVar2 + 0x50) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(float *)(pcVar2 + 0x54) = *(float *)(pcVar2 + 0x138) + fVar5;
        
          *(u32 *)(pcVar2 + 0x90) = *(u32 *)(pcVar2 + 0x134);
        
          *(float *)(pcVar2 + 0x94) = *(float *)(pcVar2 + 0x138) + fVar6;
        
          *(float *)(pcVar2 + 0xd0) = *(float *)(pcVar2 + 0x134) + (float)*(int *)(pcVar2 + 0x128)
        
          ;
        
          *(float *)(pcVar2 + 0xd4) = *(float *)(pcVar2 + 0x138) + fVar6;
        
          (*DAT_009600a0)(4,pcVar2 + 0x10,4);
        
        } break; }

        *pcVar2 = '\x01';

      }

      uVar4 = 0;

    }

    else {

      uVar4 = 0xffffffff;

    }

  }

  else {

    uVar4 = 0;

  }

  return uVar4;

}
 #undef DAT_00960090

// FUN_00427640


void FUN_00427640(int param_1)



{

  DAT_0096017c_abs[0](*(u32 *)(param_1 + 0x3c));

  return;

}

#pragma push
#pragma opt_loop_invariants on
// FUN_00427670


u32 FUN_00427670(u32 param_3, u32 param_4, char param_5, u8 param_6,
                 float param_1, float param_2)
{
  u32 allocation;
  u32 result;
  int i;
  u8 *work;

  allocation = DAT_00960184_abs[0](1, 400, 0x40000);
  if (allocation == 0) {
    return 0;
  }

  result = FUN_00194b20_u32(param_3, DAT_006b4430, 0x18a7,
                           FUN_00426590, FUN_00427640, allocation);
  work = (u8 *)allocation;
  work[0] = 0;
  for (i = 0; i < 4; i++) {
    work[i * 4 + 0x111] = 0xff;
    work[i * 4 + 0x112] = 0xff;
    work[i * 4 + 0x110] = 0xff;
    work[i * 4 + 0x113] = 0xff;
    *(u32 *)(work + i * 8 + 0x158) = 0;
    *(u32 *)(work + i * 8 + 0x154) = 0;
  }
  *(float *)(work + 0x134) = 100.0f;
  *(float *)(work + 0x138) = 100.0f;
  if (param_5 >= 5) {
    *(float *)(work + 0x17c) = 0.015625f;
    *(float *)(work + 0x180) = 0.015625f;
    *(float *)(work + 0x178) = 0.578125f;
    *(float *)(work + 0x174) = 0.578125f;
    *(u32 *)(work + 0x12c) = 0x25;
    *(u32 *)(work + 0x128) = 0x25;
  }
  else {
    *(float *)(work + 0x17c) = 0.03125f;
    *(float *)(work + 0x180) = 0.03125f;
    *(float *)(work + 0x178) = 0.59375f;
    *(float *)(work + 0x174) = 0.59375f;
    *(u32 *)(work + 0x12c) = 0x13;
    *(u32 *)(work + 0x128) = 0x13;
  }
  *(float *)(work + 0x130) = 5.0f;
  *(float *)(work + 0x14c) = 1.0f;
  *(float *)(work + 0x174) = param_1;
  *(float *)(work + 0x178) = param_2;
  *(u32 *)(work + 0x13c) = param_4;
  work[0x140] = param_6;
  work[0x141] = 0;
  work[0x150] = 1;
  work[0x18c] = 0;
  return result;
}
#pragma pop

// FUN_00427830


u32
FUN_00427830(int param_2, u32 param_3, YajimaVec2 param_4, u32 param_5,
             float param_1, YajimaVec4 *param_6, YajimaVec4 *param_7, int param_8)
{
  int iVar1;
  u32 uVar2;
  u8 *puVar3;
  YajimaVec4 size;
  YajimaVec4 rect;

  size = *param_6;
  rect = *param_7;
  puVar3 = (u8 *)(*DAT_00960184_abs)(1, 400, 0x40000);
  if (puVar3 == 0) {
    return 0;
  }
  uVar2 = FUN_00194b80_u32_y2(param_2, 0x106f, (u8 *)DAT_006b4400 + 0x40,
                           FUN_00426590, FUN_00427640, (u32)puVar3);
  *puVar3 = 0;
  for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
    u8 *entry = puVar3 + iVar1 * 4;
    *(YajimaColor *)(entry + 0x110) = *(YajimaColor *)&param_5;
    *(u32 *)(puVar3 + iVar1 * 8 + 0x158) = 0;
    *(u32 *)(puVar3 + iVar1 * 8 + 0x154) = 0;
  }
  *(YajimaVec2 *)(puVar3 + 0x134) = param_4;
  *(YajimaVec4 *)(puVar3 + 0x120) = rect;
  *(float *)(puVar3 + 0x130) = param_1;
  *(u32 *)(puVar3 + 0x13c) = param_3;
  puVar3[0x141] = param_8;
  *(float *)(puVar3 + 0x14c) = 1.0f;
  *(float *)(puVar3 + 0x144) =
      (1.0f / (float)*(s32 *)&size.z) * (float)*(s32 *)&rect.z;
  *(float *)(puVar3 + 0x148) =
      (1.0f / (float)*(s32 *)&size.w) * (float)*(s32 *)&rect.w;
  puVar3[0x150] = 0;
  puVar3[0x18c] = 0;
  return uVar2;
}

// FUN_00427A10


u32
FUN_00427a10(int param_2, u32 param_3, YajimaVec2 param_4, u32 param_5,
             float param_1, YajimaVec4 *param_6, YajimaVec4 *param_7, int param_8)
{
  int iVar1;
  u32 uVar2;
  u8 *puVar3;
  YajimaVec4 size;
  YajimaVec4 rect;

  size = *param_6;
  rect = *param_7;
  puVar3 = (u8 *)(*DAT_00960184_abs)(1, 400, 0x40000);
  if (puVar3 == 0) {
    return 0;
  }
  uVar2 = FUN_00194b20_u32(param_2, (u8 *)DAT_006b4400 + 0x40, 0x18a6,
                           FUN_00426590, FUN_00427640, (u32)puVar3);
  *puVar3 = 0;
  for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
    u8 *entry = puVar3 + iVar1 * 4;
    *(YajimaColor *)(entry + 0x110) = *(YajimaColor *)&param_5;
    *(u32 *)(puVar3 + iVar1 * 8 + 0x158) = 0;
    *(u32 *)(puVar3 + iVar1 * 8 + 0x154) = 0;
  }
  *(YajimaVec2 *)(puVar3 + 0x134) = param_4;
  *(YajimaVec4 *)(puVar3 + 0x120) = rect;
  *(float *)(puVar3 + 0x130) = param_1;
  *(u32 *)(puVar3 + 0x13c) = param_3;
  puVar3[0x141] = param_8;
  *(float *)(puVar3 + 0x14c) = 1.0f;
  *(float *)(puVar3 + 0x144) =
      (1.0f / (float)*(s32 *)&size.z) * (float)*(s32 *)&rect.z;
  *(float *)(puVar3 + 0x148) =
      (1.0f / (float)*(s32 *)&size.w) * (float)*(s32 *)&rect.w;
  puVar3[0x150] = 0;
  puVar3[0x18c] = 0;
  return uVar2;
}

// FUN_00427BF0


u32
FUN_00427bf0(u32 param_6, u32 param_7, YajimaVec2 param_8, u32 param_9,
             float param_1, float param_2, float param_3, float param_4,
             float param_5, YajimaVec4 *param_10)
{
  int iVar1;
  u32 uVar2;
  u8 *puVar3;
  YajimaVec4 rect;

  rect = *param_10;
  puVar3 = (u8 *)(*DAT_00960184_abs)(1, 400, 0x40000);
  if (puVar3 == 0) {
    return 0;
  }
  uVar2 = FUN_00194b20_u32(param_6, (u8 *)DAT_006b4400 + 0x40, 0x18a7,
                           FUN_00426590, FUN_00427640, (u32)puVar3);
  *puVar3 = 0;
  for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
    u8 *entry = puVar3 + iVar1 * 4;
    *(YajimaColor *)(entry + 0x110) = *(YajimaColor *)&param_9;
    *(u32 *)(puVar3 + iVar1 * 8 + 0x158) = 0;
    *(u32 *)(puVar3 + iVar1 * 8 + 0x154) = 0;
  }
  *(YajimaVec2 *)(puVar3 + 0x134) = param_8;
  *(YajimaVec4 *)(puVar3 + 0x120) = rect;
  *(float *)(puVar3 + 0x130) = param_1;
  *(u32 *)(puVar3 + 0x13c) = param_7;
  puVar3[0x141] = 3;
  *(float *)(puVar3 + 0x14c) = 1.0f;
  puVar3[0x150] = 1;
  *(float *)(puVar3 + 0x174) = param_4;
  *(float *)(puVar3 + 0x178) = param_5;
  *(float *)(puVar3 + 0x184) = param_2;
  *(float *)(puVar3 + 0x188) = param_3;
  puVar3[0x18c] = 0;
  return uVar2;
}

// FUN_00427DB0


void FUN_00427db0_y2(int object, YajimaVec2 value)
{
    YajimaVec2* destination = (YajimaVec2*)(*(int*)(object + 0x3c) + 0x134);

    *destination = value;
}

// FUN_00427DE0


void FUN_00427de0_y2(int param_1,u8 param_2,u8 param_3,u8 param_4,

                 u8 param_5)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

    iVar2 = iVar1 + iVar3 * 4;

    *(u8 *)(iVar2 + 0x110) = param_2;

    *(u8 *)(iVar2 + 0x112) = param_4;

    *(u8 *)(iVar2 + 0x111) = param_3;

    *(u8 *)(iVar2 + 0x113) = param_5;

  }

  return;

}

// FUN_00427E20


void FUN_00427e20_y2(float param_1,float param_2,int param_3)



{

  int iVar1;

  

  iVar1 = *(int *)(param_3 + 0x3c);

  *(int *)(iVar1 + 0x128) = (int)param_1;

  *(int *)(iVar1 + 300) = (int)param_2;

  return;

}

// FUN_00427E50


void FUN_00427e50_y2(int param_1,u8 param_2)



{

  *(u8 *)(*(int *)(param_1 + 0x3c) + 0x150) = param_2;

  return;

}

// FUN_00427E60


void FUN_00427e60_y2(int param_1,u8 param_2)



{

  *(u8 *)(*(int *)(param_1 + 0x3c) + 0x18c) = param_2;

  return;

}

#define DAT_00960090 Yajima_setState

/* W327 measured: opt_loop_invariants on reduces normalized_diff 574 -> 566 (object 896/896 -> 872/896). */
#pragma opt_loop_invariants on
// FUN_00427E70 NONMATCHING


void FUN_00427e70_y2(float depth, u32 color, float x, float y, int width, int height,
                  u32 *raster)
{
  YajimaVec16 vertices[4];
  float positions[4][2];
  code *Yajima_setState;
  int camera;
  int i;
  u32 red;
  u32 green;
  u32 blue;
  u32 alpha;
  float reciprocalZ;

  camera = kwlnGetMainCamera();
  reciprocalZ = 1.0f / *(float *)(camera + 0x80);
  alpha = ((color & 0xff000000) >> 24) & 0xff;
  blue = ((color & 0xff0000) >> 16) & 0xff;
  green = ((color & 0xff00) >> 8) & 0xff;
  red = color & 0xff;
  Yajima_setState = (code *)&DAT_00960090_abs;

  (*DAT_00960090)(6, 1);
  (*DAT_00960090)(7, 2);
  (*DAT_00960090)(8, 1);
  (*DAT_00960090)(9, 2);
  (*DAT_00960090)(0xc, 1);
  (*DAT_00960090)(0xb, 6);
  (*DAT_00960090)(10, 5);
  (*DAT_00960090)(2, 4);
  RpSkyRenderStateSet_u32(2, 0x48);
  RpSkyRenderStateSet_u32(3, 0x71801);

  positions[0][0] = x;
  positions[0][1] = y;
  positions[3][0] = x + (float)width;
  positions[3][1] = y + (float)height;
  positions[1][0] = x + (float)width;
  positions[1][1] = y;
  positions[2][0] = x;
  positions[2][1] = y + (float)height;

  for (i = 0; i < 4; i++) {
    vertices[i].lane[2] = *(float *)DAT_00960088_abs - depth;
    vertices[i].lane[6] = reciprocalZ;
    vertices[i].lane[8] = (float)alpha;
    vertices[i].lane[9] = (float)blue;
    vertices[i].lane[10] = (float)green;
    vertices[i].lane[11] = (float)red;
    vertices[i].lane[0] = positions[i][0];
    vertices[i].lane[1] = positions[i][1];
  }

  vertices[0].lane[4] = 0.0f;
  vertices[0].lane[5] = 0.0f;
  vertices[1].lane[4] = 1.0f;
  vertices[1].lane[5] = 0.0f;
  vertices[2].lane[4] = 0.0f;
  vertices[2].lane[5] = 1.0f;
  vertices[3].lane[4] = 1.0f;
  vertices[3].lane[5] = 1.0f;
  (*DAT_00960090)(1, *raster);
  (*(code *)DAT_009600a0_abs)(4, vertices, 4);
}

#pragma opt_loop_invariants reset
#undef DAT_00960090

/* measured typed globals: 6780/6768; opt_dead_assignments off: 6764/6768 nd5016; + opt_lifetimes on: 6764/6768 nd5012; retained */
#pragma opt_dead_assignments off
#pragma opt_lifetimes on
// W419 YMisc4 negative: inverted 0x865 branch arms to put 0x29ef0/0x29fe0 first; nd5012 -> 5017, object 6764/6764; rejected.
// FUN_004281F0 NONMATCHING


u32 FUN_004281f0(u32 param_1)



{

  char *pcVar1;

  u8 bVar2;

  u8 uVar3;

  u8 uVar4;

  char cVar5;

  char cVar6;

  int iVar7;

  int iVar8;

  int *piVar9;

  int iVar10;

  int lVar11;

  u32 uVar12;

  int iVar13;

  int lVar14;

  int iVar15;


  int iVar17;


  int iVar19;

  char *pcVar20;

  int lVar21;

  int iVar22;

  int iVar23;

  float fVar24;

  float fVar25;

  u32 uVar26;

  YajimaVec3 vec;

  YajimaVec3 vec2;

  u8 auStack_a0 [16];

  u8 auStack_90 [8];


  u8 auStack_80 [8];


  u32 uStack_68;

  u32 uStack_64;

  u32 uStack_60;

  u32 uStack_58;

  u32 uStack_54;

  u32 uStack_50;

  float fStack_40;

  float fStack_3c;
  float fStack_38;

  float fStack_34;

  u64 uStack_30;
  YajimaVec2 packedCoord;

  u32 uStack_2c;

  u32 uStack_28;

  int iStack_24;

  int iStack_20;

  int iStack_1c;

  int iStack_18;

  int iStack_14;

  int iStack_10;

  int iStack_c;

  int iStack_8;

  int iStack_4;

  

  pcVar1 = *(char **)((int)param_1 + 0x3c);

  pcVar1[0x938] = '\0';

  pcVar1[0x939] = '\0';

  pcVar1[0x93a] = '\0';

  if (pcVar1[0x864] != '\0') {

    for (iVar15 = 0; iVar15 < 4; iVar15 = iVar15 + 1) {

      if (*(int *)(pcVar1 + iVar15 * 4 + 0x4c) != 0) {

        *(u8 *)(*(int *)(pcVar1 + iVar15 * 4 + 0x4c) + 0x18) = 0;

      }

    }

  }

  else {

    if ((*pcVar1 == '\x0e') || (*pcVar1 == '\x12')) {

      for (iVar15 = 0; iVar15 < 0x10; iVar15 = iVar15 + 1) {

        for (iVar17 = 0; iVar17 < 0x10; iVar17 = iVar17 + 1) {

          if (*(int *)(pcVar1 + iVar17 * 8 + iVar15 * 0x80 + 0x5c) != 0) {

            *(u8 *)

             (*(int *)(*(int *)(pcVar1 + iVar17 * 8 + iVar15 * 0x80 + 0x5c) + 0x3c) + 0x150) = 1;

          }

        }

      }

      if ((DAT_008717e8_ptr != 0 && DAT_008717f4_ptr != 0) && (*(int *)(pcVar1 + 0x898) != 0)) {

        FUN_00456400_y2(*(int *)(pcVar1 + 0x898),0);

      }

      for (iVar15 = 0; iVar15 < 4; iVar15 = iVar15 + 1) {

        if (*(int *)(pcVar1 + iVar15 * 4 + 0x4c) != 0) {

          *(u8 *)(*(int *)(pcVar1 + iVar15 * 4 + 0x4c) + 0x18) = 0xff;

        }

      }

      if (*(int *)(pcVar1 + 0xb1c) != 0) {

        FUN_004302a0_y2();

      }

      return 0;

    }

  }

  switch(*pcVar1) {

  case '\0':

    *pcVar1 = '\x13';

    lVar14 = func_001a01c0();

    if (lVar14 == 1) {

      lVar14 = K_Scene_001a0250();

      if (lVar14 == 1) {

        *pcVar1 = '\x01';

      }

      else {

        lVar14 = func_001a02c0();

        if (lVar14 != 1) {

          *pcVar1 = '\x0f';

        }

        else {

          *pcVar1 = '\x01';

        }

      }

    }

    break;

  case '\x01':

    *pcVar1 = '\x02';

  case '\x02':

    uVar26 = FUN_00431110_y2(param_1,*(u64 *)(pcVar1 + 0x85c),pcVar1[0xb28],0);

    *(u32 *)(pcVar1 + 0xb24) = uVar26;

    *pcVar1 = '\r';

    break;

  case '\x03':

    uVar26 = func_0010c3a0(*(u32 *)(pcVar1 + 0x874),&iStack_4,0);

    *(u32 *)(pcVar1 + 0x28) = uVar26;

    if (iStack_4 != 0) {

      H_Cdvd_Destroy(*(u32 *)(pcVar1 + 4));

      *pcVar1 = '\x04';

    }

    break;

  case '\x04':

    uVar26 = func_0010c3a0(*(u32 *)(pcVar1 + 0x878),&iStack_8,0);

    *(u32 *)(pcVar1 + 0x2c) = uVar26;

    if (iStack_8 != 0) {

      H_Cdvd_Destroy(*(u32 *)(pcVar1 + 8));

      *pcVar1 = '\x05';

    }

    break;

  case '\x05':

    uVar26 = func_0010c3a0(*(u32 *)(pcVar1 + 0x87c),&iStack_c,0);

    *(u32 *)(pcVar1 + 0x30) = uVar26;

    if (iStack_c != 0) {

      H_Cdvd_Destroy(*(u32 *)(pcVar1 + 0xc));

      *pcVar1 = '\x06';

    }

    break;

  case '\x06':

    uVar26 = func_0010c3a0(*(u32 *)(pcVar1 + 0x880),&iStack_10,0);

    *(u32 *)(pcVar1 + 0x34) = uVar26;

    if (iStack_10 != 0) {

      H_Cdvd_Destroy(*(u32 *)(pcVar1 + 0x10));

      *pcVar1 = '\a';

    }

    break;

  case '\a':

    uVar26 = func_0010c3a0(*(u32 *)(pcVar1 + 0x884),&iStack_14,0);

    *(u32 *)(pcVar1 + 0x38) = uVar26;

    if (iStack_14 != 0) {

      H_Cdvd_Destroy(*(u32 *)(pcVar1 + 0x14));

      *pcVar1 = '\b';

    }

    break;

  case '\b':

    uVar26 = func_0010c3a0(*(u32 *)(pcVar1 + 0x888),&iStack_18,0);

    *(u32 *)(pcVar1 + 0x3c) = uVar26;

    if (iStack_18 != 0) {

      H_Cdvd_Destroy(*(u32 *)(pcVar1 + 0x18));

      *pcVar1 = '\t';

    }

    break;

  case '\t':

    uVar26 = func_0010c3a0(*(u32 *)(pcVar1 + 0x88c),&iStack_1c,0);

    *(u32 *)(pcVar1 + 0x40) = uVar26;

    if (iStack_1c != 0) {

      H_Cdvd_Destroy(*(u32 *)(pcVar1 + 0x1c));

      *pcVar1 = '\n';

    }

    break;

  case '\n':

    uVar26 = func_0010c3a0(*(u32 *)(pcVar1 + 0x890),&iStack_20,0);

    *(u32 *)(pcVar1 + 0x44) = uVar26;

    if (iStack_20 != 0) {

      H_Cdvd_Destroy(*(u32 *)(pcVar1 + 0x20));

      *pcVar1 = '\v';

    }

    break;

  case '\v':

    uVar26 = func_0010c3a0(*(u32 *)(pcVar1 + 0x894),&iStack_24,0);

    *(u32 *)(pcVar1 + 0x48) = uVar26;

    if (iStack_24 != 0) {

      H_Cdvd_Destroy(*(u32 *)(pcVar1 + 0x24));

      *pcVar1 = '\f';

    }

    break;

  case '\f':


    if (*(int *)(pcVar1 + 0xb20) != 0) {

      pcVar1[0xb20] = '\0';

      pcVar1[0xb21] = '\0';

      pcVar1[0xb22] = '\0';

      pcVar1[0xb23] = '\0';

    }

    uVar12 = FUN_004229d0_y2(param_1,*(u64 *)(pcVar1 + 0x85c),2);

    *(int *)(pcVar1 + 0xb20) = (int)uVar12;

    FUN_00422c30_y2(uVar12,*(u64 *)(pcVar1 + 0x85c),auStack_80);

    FUN_00422c10_y2(*(u32 *)(pcVar1 + 0xb20),10);

    FUN_00422cd0(*(u32 *)(pcVar1 + 0xb20),1);

    uVar26 = FUN_00431110_y2(param_1,*(u64 *)(pcVar1 + 0x85c),pcVar1[0xb28],0);

    *(u32 *)(pcVar1 + 0xb24) = uVar26;

    *pcVar1 = '\r';

    break;

  case '\r':


    if (*(int *)(pcVar1 + 0xb1c) != 0) {

      pcVar1[0xb1c] = '\0';

      pcVar1[0xb1d] = '\0';

      pcVar1[0xb1e] = '\0';

      pcVar1[0xb1f] = '\0';

    }

    FUN_0042bd80_typed(param_1);

    uVar26 = FUN_00430180_y2(param_1);

    *(u32 *)(pcVar1 + 0xb1c) = uVar26;

    FUN_0042bfd0(param_1);

    for (iVar15 = 0; iVar15 < 3; iVar15 = iVar15 + 1) {
      bVar2 = 0;

      if (((&DAT_008719a8)[iVar15 * 0x70] != 0) &&
          ((&DAT_008719b4)[iVar15 * 0x70] != 0)) {
        bVar2 = 1;
      }

      if (bVar2) {
        cVar6 = pcVar1[0xb29];
        fVar24 = FUN_00429ef0((float)cVar6,0);
        fVar24 = *(float *)(pcVar1 + 0x85c) + fVar24;
        fVar25 = FUN_00429ef0((float)cVar6,(char)(iVar15 + 1));
        fVar24 = fVar24 - fVar25;

        iVar17 = (int)cVar6;
        if (cVar6 < '\0') {
          iVar17 = iVar17 + 3;
        }

        *(float *)(pcVar1 + iVar15 * 8 + 0x8c0) =
            (float)(iVar17 >> 2) + fVar24 + 2.0f;

        cVar6 = pcVar1[0xb29];
        fVar24 = FUN_00429fe0((float)cVar6,0);
        fVar24 = *(float *)(pcVar1 + 0x860) + fVar24;
        fVar25 = FUN_00429fe0((float)cVar6,(char)(iVar15 + 1));
        fVar24 = fVar24 - fVar25;

        iVar17 = (int)cVar6;
        if (cVar6 < '\0') {
          iVar17 = iVar17 + 3;
        }

        *(float *)(pcVar1 + iVar15 * 8 + 0x8c4) =
            (float)(iVar17 >> 2) + fVar24 + 2.0f;

        FUN_00430a40_y2((char)(iVar15 + 1));
      }
    }

    for (iVar15 = 0; iVar15 < 0x18; iVar15 = iVar15 + 1) {
      bVar2 = 0;

      if ((*(int *)(&DAT_0086ede8 + iVar15 * 0x1c0) != 0) &&
          (*(int *)(&DAT_0086edf4 + iVar15 * 0x1c0) != 0)) {
        bVar2 = 1;
      }

      if (bVar2) {
        cVar6 = pcVar1[0xb29];
        fVar24 = FUN_00429ef0((float)cVar6,0);
        fVar24 = *(float *)(pcVar1 + 0x85c) + fVar24;
        fVar25 = FUN_0042a230((float)cVar6,(char)iVar15);
        fVar24 = fVar24 - fVar25;

        iVar17 = (int)cVar6;
        if (cVar6 < '\0') {
          iVar17 = iVar17 + 3;
        }

        *(float *)(pcVar1 + iVar15 * 8 + 0x93c) =
            (float)(iVar17 >> 2) + fVar24 + 2.0f - (float)((int)cVar6 << 1);

        cVar6 = pcVar1[0xb29];
        fVar24 = FUN_00429fe0((float)cVar6,0);
        fVar24 = *(float *)(pcVar1 + 0x860) + fVar24;
        fVar25 = FUN_0042a310((float)cVar6,(char)iVar15);
        fVar24 = fVar24 - fVar25;

        iVar17 = (int)cVar6;
        if (cVar6 < '\0') {
          iVar17 = iVar17 + 3;
        }

        *(float *)(pcVar1 + iVar15 * 8 + 0x940) =
            (float)(iVar17 >> 2) + fVar24 + 2.0f - (float)((int)cVar6 << 1);
      }

      DAT_0095c210_y2[iVar15] = 0;
    }

    for (iVar15 = 0; iVar15 < 0x20; iVar15 = iVar15 + 1) {
      if (*(int *)(&DAT_0086be80 + iVar15 * 0x138) != 0) {
        cVar6 = pcVar1[0xb29];
        fVar24 = FUN_00429ef0((float)cVar6,0);
        fVar24 = *(float *)(pcVar1 + 0x85c) + fVar24;
        fVar25 = FUN_0042a3f0((float)cVar6,
            (float *)(&DAT_0086be80 + iVar15 * 0x138 + 0x10c));
        fVar24 = fVar24 - fVar25;

        iVar17 = (int)cVar6;
        if (cVar6 < '\0') {
          iVar17 = iVar17 + 3;
        }

        *(float *)(pcVar1 + iVar15 * 8 + 0xa00) =
            (float)(iVar17 >> 2) + fVar24 + 2.0f - (float)((int)cVar6 << 1);

        cVar6 = pcVar1[0xb29];
        fVar24 = FUN_00429fe0((float)cVar6,0);
        fVar24 = *(float *)(pcVar1 + 0x860) + fVar24;
        fVar25 = FUN_0042a4a0((float)cVar6,
            (u32 *)(&DAT_0086be80 + iVar15 * 0x138 + 0x10c));
        fVar24 = fVar24 - fVar25;

        iVar17 = (int)cVar6;
        if (cVar6 < '\0') {
          iVar17 = iVar17 + 3;
        }

        *(float *)(pcVar1 + iVar15 * 8 + 0xa04) =
            (float)(iVar17 >> 2) + fVar24 + 2.0f - (float)((int)cVar6 << 1);
      }
    }

    if (DAT_0086e580 == 1) {
      cVar6 = pcVar1[0xb29];
      fVar24 = FUN_00429ef0((float)cVar6,0);
      fVar24 = *(float *)(pcVar1 + 0x85c) + fVar24;
      fVar25 = FUN_0042a3f0((float)cVar6,&DAT_0086e684);
      fVar24 = fVar24 - fVar25;

      iVar15 = (int)cVar6;
      if (cVar6 < '\0') {
        iVar15 = iVar15 + 3;
      }

      *(float *)(pcVar1 + 0xb00) =
          (float)(iVar15 >> 2) + fVar24 + 2.0f - (float)((int)cVar6 << 1);

      cVar6 = pcVar1[0xb29];
      fVar24 = FUN_00429fe0((float)cVar6,0);
      fVar24 = *(float *)(pcVar1 + 0x860) + fVar24;
      fVar25 = FUN_0042a4a0((float)cVar6,(u32 *)&DAT_0086e684);
      fVar24 = fVar24 - fVar25;

      iVar15 = (int)cVar6;
      if (cVar6 < '\0') {
        iVar15 = iVar15 + 3;
      }

      *(float *)(pcVar1 + 0xb04) =
          (float)(iVar15 >> 2) + fVar24 + 2.0f - (float)((int)cVar6 << 1);

      cVar6 = FUN_0044f120_y2((u32)&DAT_0086e684);
      pcVar1[0xb08] = cVar6;

      cVar6 = FUN_0044f170_y2((u32)&DAT_0086e684);
      pcVar1[0xb09] = cVar6;
    }

    FUN_0042fd80((float *)&vec,param_1);
    vec2 = vec;

    cVar6 = FUN_0044f120_y2(&vec2);
    pcVar1[0xb0b] = cVar6;

    cVar6 = FUN_0044f170_y2(&vec2);
    pcVar1[0xb0c] = cVar6;

    FUN_00430630_y2(param_1);

    *pcVar1 = '\x0e';

    DAT_007ce6dc = 1;

    break;

  case '\x0e':

    for (iVar15 = 0; iVar15 < 0x10; iVar15 = iVar15 + 1) {

      for (iVar17 = 0; iVar17 < 0x10; iVar17 = iVar17 + 1) {

        iVar13 = iVar17 * 8 + iVar15 * 0x80;

        lVar14 = kwlnTaskExists(*(u32 *)(pcVar1 + iVar13 + 0x5c));

        if (lVar14 == 1) {

          *(u8 *)(*(int *)(*(int *)(pcVar1 + iVar13 + 0x5c) + 0x3c) + 0x150) = 1;

        }

      }

    }

    if (DAT_008717e8_ptr != 0 && DAT_008717f4_ptr != 0) {

      FUN_00423fe0(&fStack_38,0,0x7e,0x7e,4,4);

      *(float *)(pcVar1 + 0x89c) = *(float *)(pcVar1 + 0x85c) + fStack_38;

      *(float *)(pcVar1 + 0x8a0) = *(float *)(pcVar1 + 0x860) + fStack_34;

      FUN_004561d0_y2(*(u32 *)(pcVar1 + 0x89c),*(u32 *)(pcVar1 + 0x8a0),

                   *(u32 *)(pcVar1 + 0x898));

      FUN_00456400_y2(*(u32 *)(pcVar1 + 0x898),1);

      uVar3 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4_y2 + 0x1e0));

      uVar4 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4_y2 + 0x1e0));
      FUN_0042a550(param_1,0,(s8)uVar3,(s8)uVar4);


      if (DAT_007ce6c4 == '\0') {

        cVar6 = pcVar1[0xb0b];

        cVar5 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4_y2 + 0x1e0));

        if ((cVar6 == cVar5) &&

           (cVar6 = pcVar1[0xb0c], cVar5 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4_y2 + 0x1e0)),

           cVar6 == cVar5)) {

          DAT_007ce6c4 = '\x01';

          DAT_007ce6d8 = 1;

        }

        else {

          iVar15 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4_y2 + 0x1e0));

          iVar17 = K_Field_Get();

          iVar13 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4_y2 + 0x1e0));

          if (*(char *)(iVar17 + iVar15 * 0x100 + iVar13 * 0x10 + 0x4a) == '\b') {

            DAT_007ce6c4 = '\x01';

            DAT_007ce6d8 = 1;

          }

        }

      }

      if (((DAT_007ce6c8 == '\0') &&

          (cVar6 = pcVar1[0xb08], cVar5 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4_y2 + 0x1e0)),

          cVar6 == cVar5)) &&

         (cVar6 = pcVar1[0xb09], cVar5 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4_y2 + 0x1e0)),

         cVar6 == cVar5)) {

        DAT_007ce6c8 = '\x01';

      }

    }

    if (DAT_008719a8 != 0 && DAT_008719b4 != 0) {

      uVar3 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008719b4 + 0x1e0));

      uVar4 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008719b4 + 0x1e0));
      FUN_0042a550(param_1,1,(s8)uVar3,(s8)uVar4);


    }

    if (DAT_00871b68 != 0 && DAT_00871b74 != 0) {

      uVar3 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_00871b74 + 0x1e0));

      uVar4 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_00871b74 + 0x1e0));
      FUN_0042a550(param_1,2,(s8)uVar3,(s8)uVar4);


    }

    if (DAT_00871d28 != 0 && DAT_00871d34 != 0) {

      uVar3 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_00871d34 + 0x1e0));

      uVar4 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_00871d34 + 0x1e0));
      FUN_0042a550(param_1,3,(s8)uVar3,(s8)uVar4);


    }

    for (iVar15 = 0; iVar15 < pcVar1[0xb28] + 4; iVar15 = iVar15 + 1) {

      for (iVar17 = 0; iVar17 < pcVar1[0xb28] + 4; iVar17 = iVar17 + 1) {

        iVar7 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4_y2 + 0x1e0));

        iVar13 = (int)pcVar1[0xb28];

        if (pcVar1[0xb28] < '\0') {

          iVar13 = iVar13 + 1;

        }

        iVar7 = iVar17 + (iVar7 - (iVar13 >> 1));

        iVar19 = iVar7 + -2;

        iVar8 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4_y2 + 0x1e0));

        iVar13 = (int)pcVar1[0xb28];

        if (pcVar1[0xb28] < '\0') {

          iVar13 = iVar13 + 1;

        }

        iVar13 = iVar15 + (iVar8 - (iVar13 >> 1)) + -2;

        if (((-1 < iVar19) && (-1 < iVar13)) && ((iVar19 < 0x10 && (iVar13 < 0x10)))) {

          iVar22 = iVar13 * 0x100;

          iVar23 = iVar19 * 0x10;

          iVar8 = K_Field_Get();

          if ((*(char *)(iVar8 + iVar22 + iVar23 + 0x48) == '\x01') &&

             (iVar8 = K_Field_Get(), *(char *)(iVar8 + iVar22 + iVar23 + 0x49) == '\x01')) {

            iVar8 = iVar19 + iVar13 * 0x10;

            piVar9 = (int *)(pcVar1 + iVar8 * 8 + 0x5c);

            lVar14 = kwlnTaskExists(*(u32 *)(pcVar1 + iVar8 * 8 + 0x5c));

            if (lVar14 == 1) {

              *(u8 *)(*(int *)(*piVar9 + 0x3c) + 0x150) = 0;

              if (*(char *)(iVar13 * 0x10 + iVar7 + 0x95c10e) != '\x01') {

                iVar7 = *(int *)(*piVar9 + 0x3c);

                for (iVar8 = 0; iVar8 < 4; iVar8 = iVar8 + 1) {

                  iVar10 = iVar7 + iVar8 * 4;

                  *(u8 *)(iVar10 + 0x110) = 0xff;

                  *(u8 *)(iVar10 + 0x112) = 0xff;

                  *(u8 *)(iVar10 + 0x111) = 0xff;

                  *(u8 *)(iVar10 + 0x113) = 0;

                }

              }

              else {

                iVar7 = *(int *)(*piVar9 + 0x3c);

                for (iVar8 = 0; iVar8 < 4; iVar8 = iVar8 + 1) {

                  iVar10 = iVar7 + iVar8 * 4;

                  *(u8 *)(iVar10 + 0x110) = 0xff;

                  *(u8 *)(iVar10 + 0x112) = 0xff;

                  *(u8 *)(iVar10 + 0x111) = 0xff;

                  *(u8 *)(iVar10 + 0x113) = 0xff;

                }

              }

              if (pcVar1[0x865] != '\0') {
                cVar6 = pcVar1[0xb29];
                fVar24 = FUN_0042a0d0((float)cVar6,(float *)(pcVar1 + 0x868));
                fStack_40 = (*(float *)(pcVar1 + 0x85c) +
                             (float)(cVar6 * iVar17) + fVar24) -
                            (float)((int)cVar6 << 1);

                cVar5 = pcVar1[0xb29];
                fVar24 = FUN_0042a180((float)cVar5,(u32 *)(pcVar1 + 0x868));
                fStack_3c = (*(float *)(pcVar1 + 0x860) +
                             (float)(cVar5 * iVar15) + fVar24) -
                            (float)((int)cVar5 << 1);
              }
              else {
                cVar6 = pcVar1[0xb29];
                fVar24 = FUN_00429ef0((float)cVar6,0);
                fStack_40 = (*(float *)(pcVar1 + 0x85c) +
                             (float)(cVar6 * iVar17) + fVar24) -
                            (float)((int)cVar6 << 1);

                cVar5 = pcVar1[0xb29];
                fVar24 = FUN_00429fe0((float)cVar5,0);
                fStack_3c = (*(float *)(pcVar1 + 0x860) +
                             (float)(cVar5 * iVar15) + fVar24) -
                            (float)((int)cVar5 << 1);
              }

              iVar7 = *(int *)(*piVar9 + 0x3c);

              *(float *)(iVar7 + 0x134) = fStack_40;

              *(float *)(iVar7 + 0x138) = fStack_3c;

            }

            FUN_0042c0a0(param_1,1,(s16)iVar19,(s16)iVar13,iVar17,iVar15);
            FUN_0042c0a0(param_1,2,(s16)iVar19,(s16)iVar13,iVar17,iVar15);
            FUN_0042c0a0(param_1,3,(s16)iVar19,(s16)iVar13,iVar17,iVar15);
            FUN_0042cfc0(param_1,(u16)iVar19,(u16)iVar13,iVar17,iVar15);
            FUN_0042dd90(param_1,(short)iVar19,(u16)iVar13,iVar17,iVar15);
            FUN_0042ea60(param_1,(u16)iVar19,(u16)iVar13,iVar17,iVar15);
            FUN_0042f440(param_1,(short)iVar19,(short)iVar13,iVar17,iVar15);
          }









          if (((DAT_007ce6c4 == '\x01') &&

              (iVar13 = K_Field_Get(), *(char *)(iVar13 + iVar22 + iVar23 + 0x4a) == '\b')) &&

             (iVar13 = K_Field_Get(), *(char *)(iVar13 + iVar22 + iVar23 + 0x49) == '\x01')) {

            FUN_00430270_y2(auStack_a0,*(u32 *)(pcVar1 + 0xb1c));

            if (pcVar1[0x865] != '\0') {
              cVar6 = pcVar1[0xb29];
              fVar24 = *(float *)(pcVar1 + 0x85c) +
                       (float)(cVar6 * iVar17) +
                       FUN_0042a0d0((float)cVar6,(float *)(pcVar1 + 0x868));
              cVar6 = pcVar1[0xb29];
              fVar24 -= FUN_0042a3f0((float)cVar6,(float *)(pcVar1 + 0xb10)) +
                        (float)((int)cVar6 << 1);
              iVar7 = (int)cVar6;
              iVar13 = iVar7;
              if (cVar6 < '\0') iVar13 = iVar13 + 1;
              packedCoord.x = (float)(iVar13 >> 1) + fVar24 - 6.0f;

              cVar6 = pcVar1[0xb29];
              fVar24 = *(float *)(pcVar1 + 0x860) +
                       (float)(cVar6 * iVar15) +
                       FUN_0042a180((float)cVar6,(u32 *)(pcVar1 + 0x868));
              cVar6 = pcVar1[0xb29];
              fVar24 -= FUN_0042a4a0((float)cVar6,(u32 *)(pcVar1 + 0xb10)) +
                        (float)((int)cVar6 << 1);
              iVar13 = (int)cVar6;
              if (cVar6 < '\0') iVar13 = iVar13 + 1;
              packedCoord.y = (float)(iVar13 >> 1) + fVar24;
            }
            else {
              cVar6 = pcVar1[0xb29];
              fVar24 = *(float *)(pcVar1 + 0x85c) +
                       (float)(cVar6 * iVar17) +
                       FUN_00429ef0((float)cVar6,0);
              cVar6 = pcVar1[0xb29];
              fVar24 -= FUN_0042a3f0((float)cVar6,(float *)(pcVar1 + 0xb10)) +
                        (float)((int)cVar6 << 1);
              iVar7 = (int)cVar6;
              iVar13 = iVar7;
              if (cVar6 < '\0') iVar13 = iVar7 + 1;
              packedCoord.x = (float)(iVar13 >> 1) + fVar24 - 6.0f;

              cVar6 = pcVar1[0xb29];
              fVar24 = *(float *)(pcVar1 + 0x860) +
                       (float)(cVar6 * iVar15) +
                       FUN_00429fe0((float)cVar6,0);
              cVar6 = pcVar1[0xb29];
              fVar24 -= FUN_0042a4a0((float)cVar6,(u32 *)(pcVar1 + 0xb10)) +
                        (float)((int)cVar6 << 1);
              iVar13 = (int)cVar6;
              if (cVar6 < '\0') iVar13 = iVar13 + 1;
              packedCoord.y = (float)(iVar13 >> 1) + fVar24;
            }

            packedCoord.y = packedCoord.y - 6.0f;

            FUN_00430220_y2(*(u32 *)(pcVar1 + 0xb1c),*(u64 *)&packedCoord);

          }

        }

      }

    }


    FUN_0042cd80(param_1);
    break;

  case '\x0f':

    cVar6 = FUN_0042aa40(param_1,*(u32 *)PTR_DAT_007cd540,

                         *(u32 *)(PTR_DAT_007cd540 + 4));

    pcVar1[0xb2a] = cVar6;

    *pcVar1 = '\x10';

    break;

  case '\x10':

    lVar21 = 0;

    for (lVar14 = 0; lVar14 < pcVar1[0xb2a]; lVar14 = (long)((int)lVar14 + 1)) {

      lVar11 = H_Cdvd_IsFileLoaded(*(u32 *)(pcVar1 + (int)lVar14 * 4 + 4));

      if (lVar11 == 1) {

        lVar21 = (long)((int)lVar21 + 1);

      }

    }

    if (lVar21 == pcVar1[0xb2a]) {



      if (*(int *)(pcVar1 + 0xb20) != 0) {

        pcVar1[0xb20] = '\0';

        pcVar1[0xb21] = '\0';

        pcVar1[0xb22] = '\0';

        pcVar1[0xb23] = '\0';

      }

      uVar12 = FUN_004229d0_y2(param_1,*(u64 *)(pcVar1 + 0x85c),2);

      *(int *)(pcVar1 + 0xb20) = (int)uVar12;

      FUN_00422c30_y2(uVar12,*(u64 *)(pcVar1 + 0x85c),auStack_90);

      FUN_00422c10_y2(*(u32 *)(pcVar1 + 0xb20),10);

      FUN_00422cd0(*(u32 *)(pcVar1 + 0xb20),1);

      lVar14 = 0;

      while (lVar14 < pcVar1[0xb2a]) {

        iVar15 = (int)lVar14;

        pcVar20 = pcVar1 + iVar15 * 4 + 4;

        if (*(int *)(pcVar1 + iVar15 * 4 + 4) != 0) {

          H_Cdvd_Destroy(*(u32 *)pcVar20);

          pcVar20[0] = '\0';

          pcVar20[1] = '\0';

          pcVar20[2] = '\0';

          pcVar20[3] = '\0';

        }

        lVar14 = (long)(iVar15 + 1);

      }

      FUN_0042ac60(param_1,*(u64 *)PTR_DAT_007cd540);
      *pcVar1 = '\x11';

    }

    break;

  case '\x11':

    FUN_0042ba50(param_1);

    uVar26 = FUN_00431110_y2(param_1,*(u64 *)(pcVar1 + 0x85c),pcVar1[0xb28],1);

    *(u32 *)(pcVar1 + 0xb24) = uVar26;
    FUN_0042bc10(param_1);


    DAT_007ce6dc = 1;

    FUN_00430630_y2(param_1);

    *pcVar1 = '\x12';

    break;

  case '\x12':

    FUN_00422cd0(*(u32 *)(pcVar1 + 0xb20),1);

    if (DAT_008717e8_ptr != 0 && DAT_008717f4_ptr != 0) {

      FUN_00456400_y2(*(u32 *)(pcVar1 + 0x898),1);

    }

    for (lVar14 = 0; lVar14 < pcVar1[0xb2a]; lVar14 = (long)((int)lVar14 + 1)) {

      *(u8 *)(*(int *)(*(int *)(pcVar1 + (int)lVar14 * 8 + 0x5c) + 0x3c) + 0x150) = 0;

    }




    FUN_0042adb0(param_1);
    FUN_0042b050(param_1);
    FUN_0042b540(param_1);
    break;

  case '\x13':

    return 0xffffffff;

  }

  if ((DAT_007e0988 & 0x10) != 0) {

    uStack_58 = 0;

    uStack_54 = 0;

    uStack_50 = 0;

    uVar26 = RwV3dLength((const RwV3d *)&uStack_58);

    uVar12 = FUN_00530da0(uVar26);

    printf((const char *)0x6b4458,uVar12);

  }

  return 0;

}

#pragma opt_lifetimes reset
#pragma opt_dead_assignments reset
// FUN_00429C60


void FUN_00429c60(int param_1)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  for (iVar3 = 0; iVar3 < 9; iVar3 = iVar3 + 1) {

    iVar2 = iVar1 + iVar3 * 4 + 0x28;
    if (*(int *)iVar2 != 0) {
      FUN_004d0f00_arg(*(u32 *)iVar2);
      *(u32 *)iVar2 = 0;
    }


  }

  for (iVar3 = 0; iVar3 < 4; iVar3 = iVar3 + 1) {

    iVar2 = iVar1 + iVar3 * 4 + 0x4c;
    if (*(int *)iVar2 != 0) {
      FUN_00115980_arg(*(u32 *)iVar2);
      *(u32 *)iVar2 = 0;
    }


  }

  DAT_0096017c_abs[0](*(u32 *)(param_1 + 0x3c));

  return;

}

// FUN_00429D40 NONMATCHING


u32 FUN_00429d40(u32 param_1,u64 param_2)



{

  u32 lVar1;

  u32 uVar2;


  short sVar3;
  u8 *puVar4;


  

  lVar1 = func_001ddd30();

  if (lVar1 == 0) {

    uVar2 = 0;

  }

  else {

    lVar1 = (*DAT_00960184_abs)(1,0xbb4,0x40000);

    if (lVar1 == 0) {

      uVar2 = 0;

    }

    else {

      uVar2 = kwlnTaskCreateWithAutoPriority(param_1,0x106f,DAT_006b4470_abs,FUN_004281f0,FUN_00429c60,lVar1);
      puVar4 = (u8 *)lVar1;

      *(YajimaVec2 *)(puVar4 + 0x85c) = *(YajimaVec2 *)&param_2;
      *puVar4 = 0;

      puVar4[0x9fe] = 0;

      puVar4[0x9ff] = 0;

      puVar4[0xb28] = 7;
      puVar4[0xb29] = 0x12;

      *(s16 *)(puVar4 + 0xb90) = -1;

      puVar4[0xb0a] = 1;

      *(u16 *)(puVar4 + 0x9fc) = 0;

      for (sVar3 = 0; sVar3 < 3; sVar3 = sVar3 + 1) {
        *(u16 *)(puVar4 + sVar3 * 2 + 0x932) = 0;

      }

      puVar4[0x865] = 0;

      puVar4[0x864] = 0;

      uGpffffb9ec = 0;

    }

  }

  return uVar2;

}

// FUN_00429E80


void FUN_00429e80_y2(int param_1,u8 param_2)



{

  *(u8 *)(*(int *)(param_1 + 0x3c) + 0x864) = param_2;

  return;

}

// FUN_00429E90


void FUN_00429e90(int param_1,u8 param_2)



{

  int iVar1;

  YajimaVec3 local_20;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  *(u8 *)(iVar1 + 0x865) = param_2;

  K_FldFrame_CtlCopyPos(&local_20,*(u32 *)(DAT_008717f4_y2[0] + 0x1e0));

  *(YajimaVec3 *)(iVar1 + 0x868) = local_20;

  return;

}

// FUN_00429EF0


float FUN_00429ef0(float param_1,char param_2)
{
  int iVar1;
  YajimaVec3 saved;
  YajimaVec3 pos;
  float x;
  float z;
  float y;
  float grid;
  float base;
  float delta;
  float ratio;
  float half;

  K_FldFrame_CtlCopyPos(&pos,
      *(u32 *)(*(u32 *)(DAT_008717f4_abs + (s32)(s8)param_2 * 0x1c0) + 0x1e0));
  saved = *(YajimaVec3 *)&pos;
  iVar1 = K_FldFrame_CtlGetXGrid(
      *(u32 *)(*(u32 *)(DAT_008717f4_abs + (s32)(s8)param_2 * 0x1c0) + 0x1e0));
  base = (float)iVar1;
  grid = base * 800.0f;
  base = grid - 400.0f;
  delta = saved.x - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return (float)(int)(half + 0.0f - delta * ratio);
}

// FUN_00429FE0


float FUN_00429fe0(float param_1,char param_2)
{
  int iVar1;
  YajimaVec3 saved;
  YajimaVec3 pos;
  float x;
  float z;
  float y;
  float grid;
  float base;
  float delta;
  float ratio;
  float half;

  K_FldFrame_CtlCopyPos(&pos,
      *(u32 *)(*(u32 *)(DAT_008717f4_abs + (s32)(s8)param_2 * 0x1c0) + 0x1e0));
  saved = *(YajimaVec3 *)&pos;
  iVar1 = K_FldFrame_CtlGetZGrid(
      *(u32 *)(*(u32 *)(DAT_008717f4_abs + (s32)(s8)param_2 * 0x1c0) + 0x1e0));
  base = (float)iVar1;
  grid = base * 800.0f;
  base = grid - 400.0f;
  delta = saved.z - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return (float)(int)(half + 0.0f - delta * ratio);
}

// FUN_0042A0D0


float FUN_0042a0d0(float param_1,float *param_2)
{
  int iVar1;
  YajimaVec3 pos = *(YajimaVec3 *)param_2;
  float grid;
  float base;
  float delta;
  float ratio;
  float half;

  iVar1 = FUN_0044f120_y2(&pos);
  base = (float)iVar1;
  grid = base * 800.0f;
  base = grid - 400.0f;
  delta = pos.x - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return (float)(int)(half + 0.0f - delta * ratio);
}

// FUN_0042A180


float FUN_0042a180(float param_1,u32 *param_2)
{
  int iVar1;
  YajimaVec3 pos = *(YajimaVec3 *)param_2;
  float grid;
  float base;
  float delta;
  float ratio;
  float half;

  iVar1 = FUN_0044f170_y2(&pos);
  base = (float)iVar1;
  grid = base * 800.0f;
  base = grid - 400.0f;
  delta = pos.z - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return (float)(int)(half + 0.0f - delta * ratio);
}

// FUN_0042A230


float FUN_0042a230(float param_1,char param_2)
{
  int iVar1;
  YajimaVec3 saved;
  YajimaVec3 pos;
  float z;
  float x;
  float y;
  float grid;
  float base;
  float delta;
  float ratio;
  float half;
  K_FldFrame_CtlCopyPos(&pos,
      *(u32 *)(*(u32 *)(DAT_0086edf4_abs + (s32)(s8)param_2 * 0x1c0) + 0x1e0));
  saved = *(YajimaVec3 *)&pos;
  iVar1 = K_FldFrame_CtlGetXGrid(
      *(u32 *)(*(u32 *)(DAT_0086edf4_abs + (s32)(s8)param_2 * 0x1c0) + 0x1e0));
  base = (float)iVar1;
  grid = base * 800.0f;
  base = grid - 400.0f;
  delta = saved.x - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return half + 0.0f - delta * ratio;
}

// FUN_0042A310


float FUN_0042a310(float param_1,char param_2)
{
  int iVar1;
  YajimaVec3 saved;
  YajimaVec3 pos;
  float x;
  float z;
  float y;
  float grid;
  float base;
  float delta;
  float ratio;
  float half;

  K_FldFrame_CtlCopyPos(&pos,
      *(u32 *)(*(u32 *)(DAT_0086edf4_abs + (s32)(s8)param_2 * 0x1c0) + 0x1e0));
  saved = *(YajimaVec3 *)&pos;
  iVar1 = K_FldFrame_CtlGetZGrid(
      *(u32 *)(*(u32 *)(DAT_0086edf4_abs + (s32)(s8)param_2 * 0x1c0) + 0x1e0));
  base = (float)iVar1;
  grid = base * 800.0f;
  base = grid - 400.0f;
  delta = saved.z - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return half + 0.0f - delta * ratio;
}

// FUN_0042A3F0


float FUN_0042a3f0(float param_1,float *param_2)
{
  int iVar1;
  YajimaVec3 pos = *(YajimaVec3 *)param_2;
  float grid;
  float base;
  float delta;
  float ratio;
  float half;

  iVar1 = FUN_0044f120_y2(&pos);
  base = (float)iVar1;
  grid = base * 800.0f;
  base = grid - 400.0f;
  delta = pos.x - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return half + 0.0f - delta * ratio;
}

// FUN_0042A4A0


float FUN_0042a4a0(float param_1,u32 *param_2)
{
  int iVar1;
  YajimaVec3 pos = *(YajimaVec3 *)param_2;
  float grid;
  float base;
  float delta;
  float ratio;
  float half;

  iVar1 = FUN_0044f170_y2(&pos);
  base = (float)iVar1;
  grid = base * 800.0f;
  base = grid - 400.0f;
  delta = pos.z - base;
  ratio = param_1 / 800.0f;
  half = param_1 / 2.0f;
  return half + 0.0f - delta * ratio;
}

// FUN_0042A550 NONMATCHING


void FUN_0042a550(int param_1,u32 param_2,u32 param_3,u32 param_4)



{

  char cVar1;

  YRuntimeUnitRow *row;
  char cVar2;

  u32 uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int lVar7;

  char cVar8;

  int iVar9;

  int iVar10;

  int iVar11;

  

  iVar5 = *(int *)(param_1 + 0x3c);

  uVar3 = FUN_00433810(param_3,param_4);

  cVar8 = (char)param_3;

  cVar1 = (char)param_4;

  if ((uVar3 & 0xff) != 0) {

    DAT_0095c110[uVar3 & 0xff] = 1;

  }

  else {

    DAT_0095c110[cVar1 * 0x10 + (int)cVar8] = 1;

  }

  iVar10 = cVar1 * 0x100;

  iVar11 = cVar8 * 0x10;

  iVar4 = K_Field_Get();

  iVar6 = (int)cVar8;

  if ((*(u8 *)(iVar4 + iVar10 + iVar11 + 0x53) & 8) != 0) {

    uVar3 = FUN_00433810(cVar8 + '\x01',param_4);

    if ((uVar3 & 0xff) != 0) {

      DAT_0095c110[uVar3 & 0xff] = 1;

    }

    else {

      *(u8 *)(cVar1 * 0x10 + iVar6 + 0x95c111) = 1;

    }

  }

  iVar4 = K_Field_Get();

  iVar9 = (int)cVar1;

  if ((*(u8 *)(iVar4 + iVar10 + iVar11 + 0x53) & 2) != 0) {

    uVar3 = FUN_00433810(cVar8 + -1,param_4);

    if ((uVar3 & 0xff) != 0) {

      DAT_0095c110[uVar3 & 0xff] = 1;

    }

    else {

      *(u8 *)(iVar9 * 0x10 + iVar6 + 0x95c10f) = 1;

    }

  }

  iVar4 = K_Field_Get();

  if ((*(u8 *)(iVar4 + iVar10 + iVar11 + 0x53) & 1) != 0) {

    uVar3 = FUN_00433810(param_3,cVar1 + -1);

    if ((uVar3 & 0xff) != 0) {

      DAT_0095c110[uVar3 & 0xff] = 1;

    }

    else {

      *(u8 *)((int)&DAT_0095c100_y2 + iVar9 * 0x10 + iVar6) = 1;

    }

  }

  iVar4 = K_Field_Get();

  if ((*(u8 *)(iVar4 + iVar10 + iVar11 + 0x53) & 4) != 0) {

    uVar3 = FUN_00433810(param_3,cVar1 + '\x01');

    if ((uVar3 & 0xff) != 0) {

      DAT_0095c110[uVar3 & 0xff] = 1;

    }

    else {

      *(u8 *)(iVar9 * 0x10 + iVar6 + 0x95c120) = 1;

    }

  }

  cVar8 = (char)param_2;

  if (cVar8 != '\0') {
    row = (YRuntimeUnitRow *)&DAT_008717a0 + cVar8;

    cVar1 = FUN_00435260_y2(param_2);

    if (cVar1 == '\0') {

      cVar1 = FUN_004353f0_y2(row);

      if (((cVar1 != '\x01') && (cGpffffb9d8 == '\0')) &&

         (DAT_0095c110[*(char *)(iVar5 + 0xb09) * 0x10 + (int)*(char *)(iVar5 + 0xb08)] == '\x01'

         )) {

        FUN_00456490_y2(param_2);

        cGpffffb9d8 = '\x01';

      }

      if (cGpffffb9d4 == '\0') {

        cVar1 = *(char *)(iVar5 + 0xb0b);

        cVar2 = K_FldFrame_CtlGetXGrid(*(u32 *)((u8 *)row->unk_054 + 0x1e0));

        if ((cVar1 == cVar2) &&

           (cVar1 = *(char *)(iVar5 + 0xb0c),

           cVar2 = K_FldFrame_CtlGetZGrid(*(u32 *)((u8 *)row->unk_054 + 0x1e0)),

           cVar1 == cVar2)) {

          lVar7 = FUN_0043c730_y2(param_2);

          if (lVar7 == 1) {

            cVar8 = FUN_004353f0_y2(row);

            if (cVar8 != '\x01') {

              FUN_00456450_y2(param_2);

            }

            cGpffffb9d4 = '\x01';

          }

        }

        else {

          iVar5 = K_FldFrame_CtlGetZGrid(*(u32 *)((u8 *)row->unk_054 + 0x1e0));

          iVar4 = K_Field_Get();

          iVar6 = K_FldFrame_CtlGetXGrid(*(u32 *)((u8 *)row->unk_054 + 0x1e0));

          if (*(char *)(iVar4 + iVar5 * 0x100 + iVar6 * 0x10 + 0x4a) == '\b') {

            cGpffffb9d4 = '\x01';

          }

        }

      }

    }

  }

  else {

    lVar7 = FUN_004352e0_y2();

    if (((lVar7 == 0) && (cGpffffb9d8 == '\0')) &&

       (DAT_0095c110[*(char *)(iVar5 + 0xb09) * 0x10 + (int)*(char *)(iVar5 + 0xb08)] == '\x01'))

    {

      cGpffffb9d8 = '\x01';

    }

  }

  return;

}

// W416 measured negative: retail offsets 48/112 have 0x18 extensions, while ours has matching 0x18 pairs at 44/48 and 116/120; layout, not width.
// FUN_0042AA40 NONMATCHING


u8 FUN_0042aa40(int param_1, u32 param_2, u32 param_3)
{
  struct FileEntry {
    int count;
    int category;
    u16 primary;
    u16 secondary;
    u8 padding[0x1c];
  };
  int work;
  char group;
  struct FileEntry *table;
  int i;
  short selected;
  char category;
  char result;
  int clearIndex;
  u32 request;

  work = *(int *)(param_1 + 0x3c);
  group = (char)param_2 - 0x1f;
  for (i = 0; i < 10; i++) {
    *(short *)(work + i * 2 + 0xb7c) = -1;
  }
  *(short *)(work + 0xb90) = -1;

  table = (struct FileEntry *)(iGpffffb5c0 +
      (((group * 0xf0 + group) * 4)));
  for (i = 0; i < table->count; i++) {
    if ((param_2 == table[i].primary) &&
        (param_3 == table[i].secondary)) {
      *(short *)(work + 0xb90) = i;
    }
  }
  selected = *(short *)(work + 0xb90);
  if (selected == -1) {
    return 0;
  }

  category = *(char *)&table[selected].category;
  result = 0;
  for (i = 0; i < table->count; i++) {
    if (category == table[i].category) {
      for (clearIndex = 0; clearIndex < 0xff; clearIndex++) {
        DAT_0095bee0_abs[clearIndex] = 0;
      }
      *(short *)(work + result * 2 + 0xb7c) = i;
      sprintf((char *)DAT_0095bee0_abs, (const char *)DAT_006b4490, param_2,
              (char *)table[i].secondary);
      request = H_Cdvd_Request(DAT_0095bee0_abs, 0);
      *(u32 *)(work + result * 4 + 4) = request;
      result++;
    }
  }
  return result;
}
// W419 YMisc4 negative: swapped address-add operands in FUN_0042ac60 to match retail addu ordering; nd 2 -> 230, object 332 -> 340/window336; rejected.
// W419 YMisc4 negative: splitting the case-index load address expression in FUN_0042ac60 regressed normalized_diff 1 -> 163 bytes, object 332 -> 336/window336 (rate .003012 -> .485119); reverted.
// FUN_0042AC60


void FUN_0042ac60(int param_1,int param_2)
{
  int iVar1;
  int cVar2;
  u32 uVar3;
  int *piVar4;
  u8 *puVar5;
  int iVar5;
  int iVar6;
  int iVar8;
  int iVar7;

  iVar1 = *(int *)(param_1 + 0x3c);
  cVar2 = (s8)(param_2 - 0x1f);
  iVar6 = cVar2 * 0xf0;
  iVar6 = (iVar6 + (int)cVar2) * 4;
  piVar4 = (int *)(iVar6 + iGpffffb5c0);
  cVar2 = *(char *)((u8 *)(uintptr_t)Yajima_AddOffsetFirst(
      *(short *)(iVar1 + 0xb90) * 0x28, (uintptr_t)piVar4) + 4);
  iVar8 = 0;
  iVar7 = 0;
  for (; iVar8 < *(int *)(iVar6 + iGpffffb5c0); ) {
    piVar4 = (int *)(iVar6 + iGpffffb5c0 + iVar8 * 0x28);
    if (cVar2 == piVar4[1]) {
      iVar5 = 0;
      puVar5 = DAT_0095bfe0_abs;
      for (; iVar5 < 0xff; iVar5 = iVar5 + 1) {
        puVar5[iVar5] = 0;
      }
      sprintf((char *)DAT_0095bfe0_abs, (const char *)DAT_006b44b0,param_2,*(u16 *)((int)piVar4 + 10));
      uVar3 = FUN_004d1260_y2(DAT_0095bfe0_abs,0);
      *(u32 *)(iVar1 + iVar7 * 4 + 0x28) = uVar3;
      iVar7 = iVar7 + 1;
    }
    iVar8 = iVar8 + 1;
  }
  return;
}

// FUN_0042ADB0 NONMATCHING


void FUN_0042adb0(int param_1)



{

  int iVar1;

  u32 *puVar2;

  u32 uVar3;

  int iVar4;

  long lVar5;

  float fVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  YajimaVec3 posCamera;
  YajimaVec3 transformed;
  YajimaVec3 delta;
  YajimaVec3 posTarget;

  YajimaVec4 rotScratch;
  u32 uStack_20;

  float fStack_18;

  float fStack_14;

  float fStack_10;

  float fStack_8;

  float fStack_4;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  K_FldFrame_CtlCopyPos(&posCamera,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

  posTarget = posCamera;



  ((u32 *)&rotScratch)[0] = DAT_006b44c0;

  ((u32 *)&rotScratch)[1] = 0;

  ((u32 *)&rotScratch)[2] = DAT_006b44c8;

  if (*(char *)(iVar1 + 0x865) == '\x01') {

    posTarget = *(YajimaVec3 *)(iVar1 + 0x868);



  }

  uVar3 = FUN_004c38c0();

  puVar2 = (u32 *)uVar3;

  puVar2[10] = 0x3f800000;

  puVar2[5] = 0x3f800000;

  *puVar2 = 0x3f800000;

  puVar2[4] = 0;

  puVar2[2] = 0;

  puVar2[1] = 0;

  puVar2[9] = 0;

  puVar2[8] = 0;

  puVar2[6] = 0;

  puVar2[0xe] = 0;

  puVar2[0xd] = 0;

  puVar2[0xc] = 0;

  puVar2[3] = puVar2[3] | 0x20003;

  FUN_004c31b0_ymisc((void *)uVar3,(const void *)&rotScratch,
                 *(float *)(*(short *)(iVar1 + 0xb90) * 0x28 +
                            *piGpffffa850 * 0x3c4 + iGpffffb5c0 - 0x74a0),2);

  delta.x = *(float *)(iVar1 + 0xba4) - posTarget.x;

  delta.y = *(float *)(iVar1 + 0xba8) - posTarget.y;

  delta.z = *(float *)(iVar1 + 0xbac) - posTarget.z;

  FUN_004c6be0_ymisc((float *)&transformed,(const float *)&delta,uVar3);

  fVar6 = *(float *)(iVar1 + 0xba4);

  iVar4 = *(short *)(iVar1 + 0xb90) * 0x28 + *piGpffffa850 * 0x3c4 + iGpffffb5c0;

  fVar8 = *(float *)(iVar4 + -0x749c);

  fVar9 = *(float *)(iVar4 + -0x74a8);

  fVar7 = *(float *)(iVar1 + 0xbac);

  fVar10 = *(float *)(iVar4 + -0x7494);

  fVar11 = *(float *)(iVar4 + -0x74a4);

  for (lVar5 = 0; lVar5 < *(char *)(iVar1 + 0xb2a); lVar5 = (long)((int)lVar5 + 1)) {

    iVar4 = iVar1 + (int)lVar5 * 8;

    fStack_8 = *(float *)(iVar4 + 0xb2c) +

               ((63.0f - (((fVar6 - transformed.x) - fVar8) * 2.25f) / 100.0f) - fVar9);

    fStack_4 = *(float *)(iVar4 + 0xb30) +

               ((63.0f - (((fVar7 - transformed.z) - fVar10) * 2.25f) / 100.0f) - fVar11);

    iVar4 = *(int *)(*(int *)(iVar4 + 0x5c) + 0x3c);

    *(float *)(iVar4 + 0x134) = fStack_8;

    *(float *)(iVar4 + 0x138) = fStack_4;

  }

  FUN_004c3880(uVar3);

  return;

}

// FUN_0042B050 NONMATCHING


void FUN_0042b050(int param_1)



{

  int iVar1;

  u8 bVar2;

  u32 *puVar3;
  YRuntimeUnitRow *row;

  int iVar4;

  u32 uVar5;

  u32 uVar6;

  int iVar7;

  float fVar8;


  float fVar10;

  float fVar11;


  float fVar12;
  float fStack_50;

  u32 uStack_4c;

  float fStack_48;

  float afStack_40 [4];

  u64 uStack_30;


  float afStack_20 [2];
  float fStack_18;

  float fStack_10;


  float fStack_8;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  K_FldFrame_CtlCopyPos(&fStack_50,*(u32 *)(DAT_008717f4_y2 + 0x1e0));

  fStack_10 = fStack_50;


  fStack_8 = fStack_48;

  uStack_30 = DAT_006b44d0;


  if (*(char *)(iVar1 + 0x865) == '\x01') {

    fStack_10 = *(float *)(iVar1 + 0x868);


    fStack_8 = *(float *)(iVar1 + 0x870);

  }


  for (iVar7 = 1; iVar7 < 4; iVar7 = iVar7 + 1) {
    row = (YRuntimeUnitRow *)&DAT_008717a0 + iVar7;

    bVar2 = 0;

    if ((row->unk_048 != 0) && (row->unk_054 != 0)) {

      bVar2 = 1;

    }

    if (bVar2) {

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

      K_FldFrame_CtlCopyPos(afStack_20,*(u32 *)((u8 *)row->unk_054 + 0x1e0));

      FUN_004c31b0_ymisc((void *)uVar5,(const void *)&uStack_30,
                     *(float *)(iGpffffb5c0 + *piGpffffa850 * 0x3c4 +
                                *(short *)(iVar1 + 0xb90) * 0x28 - 0x74a0),2);

      iVar4 = iGpffffb5c0 + *piGpffffa850 * 0x3c4 + *(short *)(iVar1 + 0xb90) * 0x28;
      fVar11 = 63.0f - ((((*(float *)(iVar1 + 0xba4) - (*(float *)(iVar4 + -0x749c) - afStack_20[0])) *
                         2.25f) / 100.0f) * 2.25f) / 100.0f;
      fVar12 = 63.0f - ((((*(float *)(iVar1 + 0xbac) - (*(float *)(iVar4 + -0x7494) - fStack_18)) *
                         2.25f) / 100.0f) * 2.25f) / 100.0f;



      afStack_40[0] = ((afStack_20[0] - fStack_10) * 2.25f) / 100.0f;
      afStack_40[2] = ((fStack_18 - fStack_8) * 2.25f) / 100.0f;

      afStack_40[1] = 0.0f;

      FUN_004c6be0_ymisc(afStack_40,afStack_40,uVar5);

      uVar6 = FUN_001158b0_y2(0,uGpffffb9f4,7);

      iVar4 = (int)uVar6;

      *(u32 *)(iVar4 + 0x2c) = 0x40000000;

      fVar8 = (float)func_001126b0(uVar6);

      *(float *)(iVar4 + 0x10) = (afStack_40[0] + *(float *)(iVar1 + 0x85c) + fVar11) - fVar8 / 2.0f;

      fVar8 = (float)func_00112740(uVar6);

      *(float *)(iVar4 + 0x14) = (afStack_40[2] + *(float *)(iVar1 + 0x860) + fVar12) - fVar8 / 2.0f;

      *(u8 *)(iVar4 + 0x18) = 0xff;

      fVar10 = *(float *)(iVar1 + 0x85c);

      fVar8 = (float)func_001126b0(uVar6);

      if ((((fVar10 < ((afStack_40[0] + fVar10 + fVar11) - fVar8 / 2.0f) + 8.0f) &&

           (fVar10 = *(float *)(iVar1 + 0x860), fVar8 = (float)func_00112740(uVar6),

           fVar10 < ((afStack_40[2] + fVar10 + fVar12) - fVar8 / 2.0f) + 8.0f)) &&

          (fVar10 = *(float *)(iVar1 + 0x85c), fVar8 = (float)func_001126b0(uVar6),

          ((afStack_40[0] + fVar10 + fVar11) - fVar8 / 2.0f) + 12.0f < fVar10 + 126.0f)) &&

         (fVar10 = *(float *)(iVar1 + 0x860), fVar8 = (float)func_00112740(uVar6),

         ((afStack_40[2] + fVar10 + fVar12) - fVar8 / 2.0f) + 12.0f < fVar10 + 126.0f)) {

        *(u8 *)(iVar4 + 0x18) = 0;

      }

      func_001127d0(uVar6,1);

      FUN_00115980(uVar6);

      FUN_004c3880(uVar5);

    }

  }

  return;

}

// FUN_0042B540 NONMATCHING


void FUN_0042b540(int param_1)



{

  int iVar1;

  u8 bVar2;

  u32 *puVar3;
  YRuntimeUnitRow *row;

  u32 uVar4;

  u32 uVar5;

  int iVar6;

  int iVar7;

  float fVar8;

  float fVar10;

  float fVar11;

  float fVar12;

  float fStack_50;

  u32 uStack_4c;

  float fStack_48;

  float afStack_40 [4];

  u64 uStack_30;


  float afStack_20 [2];

  float fStack_18;

  float fStack_10;


  float fStack_8;

  

  iVar1 = *(int *)(param_1 + 0x3c);

  K_FldFrame_CtlCopyPos(&fStack_50,*(u32 *)(DAT_008717f4_y2 + 0x1e0));

  fStack_10 = fStack_50;

  fStack_8 = fStack_48;

  uStack_30 = DAT_006b44e0;


  if (*(char *)(iVar1 + 0x865) == '\x01') {

    fStack_10 = *(float *)(iVar1 + 0x868);


    fStack_8 = *(float *)(iVar1 + 0x870);

  }

  for (iVar7 = 0; iVar7 < 0x18; iVar7 = iVar7 + 1) {

    bVar2 = 0;

    row = (YRuntimeUnitRow *)DAT_0086e6a0 + iVar7 + 4;
    if ((row->unk_048 != 0) && (row->unk_054 != 0)) {

      bVar2 = 1;

    }

    if (bVar2) {

      uVar4 = FUN_004c38c0();

      puVar3 = (u32 *)uVar4;

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

      K_FldFrame_CtlCopyPos(afStack_20,*(u32 *)((u8 *)row->unk_054 + 0x1e0));

      FUN_004c31b0_ymisc((void *)uVar4,(const void *)&uStack_30,
                     *(float *)(iGpffffb5c0 + *piGpffffa850 * 0x3c4 +
                                *(short *)(iVar1 + 0xb90) * 0x28 - 0x74a0),2);

      iVar6 = iGpffffb5c0 + *piGpffffa850 * 0x3c4 + *(short *)(iVar1 + 0xb90) * 0x28;

      fVar11 = 63.0f - ((((*(float *)(iVar1 + 0xba4) - (*(float *)(iVar6 + -0x749c) - afStack_20[0]))
                         * 2.25f) / 100.0f) * 2.25f) / 100.0f;

      fVar12 = 63.0f - ((((*(float *)(iVar1 + 0xbac) - (*(float *)(iVar6 + -0x7494) - fStack_18)) *
                         2.25f) / 100.0f) * 2.25f) / 100.0f;


      afStack_40[0] = ((afStack_20[0] - fStack_10) * 2.25f) / 100.0f;

      afStack_40[2] = ((fStack_18 - fStack_8) * 2.25f) / 100.0f;

      afStack_40[1] = 0.0f;

      FUN_004c6be0_ymisc(afStack_40,afStack_40,uVar4);

      uVar5 = FUN_001158b0_y2(0,uGpffffb9f4,0xb);

      iVar6 = (int)uVar5;

      *(u32 *)(iVar6 + 0x2c) = 0x40000000;

      fVar8 = (float)func_001126b0(uVar5);

      *(float *)(iVar6 + 0x10) = (afStack_40[0] + *(float *)(iVar1 + 0x85c) + fVar11) - fVar8 / 2.0f;

      fVar8 = (float)func_00112740(uVar5);

      *(float *)(iVar6 + 0x14) = (afStack_40[2] + *(float *)(iVar1 + 0x860) + fVar12) - fVar8 / 2.0f;

      *(u8 *)(iVar6 + 0x18) = 0xff;

      fVar10 = *(float *)(iVar1 + 0x85c);

      fVar8 = (float)func_001126b0(uVar5);

      if ((((fVar10 < ((afStack_40[0] + fVar10 + fVar11) - fVar8 / 2.0f) + 8.0f) &&

           (fVar10 = *(float *)(iVar1 + 0x860), fVar8 = (float)func_00112740(uVar5),

           fVar10 < ((afStack_40[2] + fVar10 + fVar12) - fVar8 / 2.0f) + 8.0f)) &&

          (fVar10 = *(float *)(iVar1 + 0x85c), fVar8 = (float)func_001126b0(uVar5),

          ((afStack_40[0] + fVar10 + fVar11) - fVar8 / 2.0f) + 12.0f < fVar10 + 126.0f)) &&

         (fVar10 = *(float *)(iVar1 + 0x860), fVar8 = (float)func_00112740(uVar5),

         ((afStack_40[2] + fVar10 + fVar12) - fVar8 / 2.0f) + 12.0f < fVar10 + 126.0f)) {

        *(u8 *)(iVar6 + 0x18) = 0;

      }

      func_001127d0(uVar5,1);

      FUN_00115980(uVar5);

      FUN_004c3880(uVar4);

    }

  }

  return;

}

// FUN_0042BA30


u8 FUN_0042ba30(void)



{

  return cGpffffb9ec == '\x01';

}

// FUN_0042BA50 NONMATCHING


void FUN_0042ba50(u32 param_1)



{

  int iVar1;
  int *piVar2;

  u32 uVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  int lVar8;

  float fVar9;

  float fVar10;

  YajimaVec4 result;

  int iStack_18;

  int iStack_14;

  YajimaColor color;

  

  iVar1 = *(int *)((int)param_1 + 0x3c);

  lVar8 = 0;

  while (lVar8 < *(char *)(iVar1 + 0xb2a)) {

    iVar7 = lVar8;

    iVar4 = iVar1 + iVar7 * 2;

    iVar6 = iVar1 + iVar7 * 8;

    *(float *)(iVar6 + 0xb2c) =

         *(float *)(iVar1 + 0x85c) +

         *(float *)(iGpffffb5c0 + *piGpffffa850 * 0x3c4 + *(short *)(iVar4 + 0xb7c) * 0x28 + -0x74a8

                   );

    *(float *)(iVar6 + 0xb30) =

         *(float *)(iVar1 + 0x860) +

         *(float *)(iGpffffb5c0 + *piGpffffa850 * 0x3c4 + *(short *)(iVar4 + 0xb7c) * 0x28 + -0x74a4

                   );

    piVar2 = *(int **)(iVar1 + iVar7 * 4 + 0x28);

    iVar5 = *piVar2;

    iStack_14 = *(int *)(iVar5 + 0x10);

    iStack_18 = *(int *)(iVar5 + 0xc);

    color.a = 0xff;
    color.g = 0xff;
    color.b = 0xff;
    color.r = 0xff;

    iVar5 = iGpffffb5c0 + *piGpffffa850 * 0x3c4 + *(short *)(iVar4 + 0xb7c) * 0x28;

    fVar10 = *(float *)(iVar5 + -0x74ac);

    fVar9 = *(float *)(iVar5 + -0x74b0);

    uVar3 = FUN_00427bf0(param_1, (u32)piVar2, *(YajimaVec2 *)(iVar6 + 0xb2c),
                         *(u32 *)&color, 5.0f, fVar9, fVar10,
                         fVar9 / (float)iStack_18, fVar10 / (float)iStack_14,
                         &result);

    *(u32 *)(iVar6 + 0x5c) = uVar3;

    lVar8 = iVar7 + 1;

  }

  return;

}

/* W327 measured: opt_common_subs off reduces normalized_diff 240 -> 218 (object 360/368 -> 364/368). */
/* W409 measured: baseline NONMATCHING 364/368 nd218; missing helper call plus int loop cleanup 352/368 nd214. */
#pragma opt_common_subs off
// FUN_0042BC10 NONMATCHING


void FUN_0042bc10(int param_1)



{

  int iVar1;

  u32 uVar2;

  int lVar3;

  YajimaVec2 offset;



  

  iVar1 = *(int *)((int)param_1 + 0x3c);

  if (*(u32 *)DAT_008717e8_abs != 0) {

    if (*(int *)(iVar1 + 0x898) != 0) {

      *(u32 *)(iVar1 + 0x898) = 0;

    }

    FUN_00423fe0_vec2(&offset,0,0x7e,0x7e,0x20,0x20);

    *(float *)(iVar1 + 0x89c) = *(float *)(iVar1 + 0x85c) + offset.x;
    *(float *)(iVar1 + 0x8a0) = *(float *)(iVar1 + 0x860) + offset.y;

    uVar2 = FUN_004560d0_typed(param_1,*(float *)(iVar1 + 0x89c),
                               *(float *)(iVar1 + 0x8a0),1.0f,0x20,0x20);

    *(u32 *)(iVar1 + 0x898) = uVar2;

    FUN_004563c0_y2(uVar2,*(char *)(iVar1 + 0xb90));

    FUN_004563d0_y2(*(u32 *)(iVar1 + 0x898),*(u64 *)(iVar1 + 0x85c));

    FUN_004563b0_y2(*(f32 *)(iGpffffb5c0 + *piGpffffa850 * 0x3c4 +
                             *(short *)(iVar1 + 0xb90) * 0x28 - 0x74a0),
                    *(u32 *)(iVar1 + 0x898));

    *(u32 *)(iVar1 + 0xba4) = 0;

    *(u32 *)(iVar1 + 0xbac) = 0;
    FUN_0042adb0(param_1);


    for (lVar3 = 0; lVar3 < *(char *)(iVar1 + 0xb2a); lVar3 = lVar3 + 1) {

      *(u8 *)(*(int *)(*(int *)(iVar1 + (int)lVar3 * 8 + 0x5c) + 0x3c) + 0x150) = 1;

    }

  }

  return;

}
#pragma opt_common_subs reset

/* W212: first divergence is the prologue_y2 (ours 0xc0-byte frame, retail 0xb0),
 * followed by different nested-loop induction lifetimes.  FUN_0042fd80 has a
 * grid scan but no per-cell allocation/update body, so its template is not transferable. */
// FUN_0042BD80 NONMATCHING


void FUN_0042bd80(int param_1)



{

  u8 uVar1;

  u8 bVar2;

  u8 *work;

  int iVar4;

  int *piVar5;

  int iVar6;

  int iVar8;

  int iVar7;

  

  work = *(u8 **)((int)param_1 + 0x3c);

  for (iVar7 = 0; iVar7 < 0x10; iVar7 = iVar7 + 1) {

    iVar6 = iVar7 * 0x100;


    for (iVar8 = 0; iVar8 < 0x10; iVar8 = iVar8 + 1) {

      iVar4 = K_Field_Get();

      if (*(char *)(iVar6 + iVar4 + iVar8 * 0x10 + 0x48) == '\x01') {

        iVar4 = K_Field_Get();

        if (*(char *)(iVar6 + iVar4 + iVar8 * 0x10 + 0x49) == '\x01') {

          piVar5 = (int *)(work + iVar7 * 0x80 + iVar8 * 8 + 0x5c);

          if (*piVar5 != 0) {

            *piVar5 = 0;

          }


          K_Field_Get();

          iVar4 = K_Field_Get();

          if (*(u8 *)(iVar6 + iVar4 + iVar8 * 0x10 + 0x4a) < 5) {

            iVar4 = K_Field_Get();

            bVar2 = *(u8 *)(iVar6 + iVar4 + iVar8 * 0x10 + 0x4a);

            iVar4 = K_Field_Get();

            uVar1 = *(u8 *)(iVar6 + iVar4 + iVar8 * 0x10 + 0x4a);

            iVar4 = K_Field_Get();

            iVar4 = FUN_00427670_typed(0.625f,0.625f,param_1,(&DAT_0095c0e0)[bVar2],uVar1,

                                 *(u8 *)(iVar6 + iVar4 + iVar8 * 0x10 + 0x4e));

            *piVar5 = iVar4;

          }

          else {

            iVar4 = K_Field_Get();

            bVar2 = *(u8 *)(iVar6 + iVar4 + iVar8 * 0x10 + 0x4a);

            iVar4 = K_Field_Get();

            uVar1 = *(u8 *)(iVar6 + iVar4 + iVar8 * 0x10 + 0x4a);

            iVar4 = K_Field_Get();

            iVar4 = FUN_00427670_typed(0.59375f,0.59375f,param_1,(&DAT_0095c0e0)[bVar2],uVar1,

                                 *(u8 *)(iVar6 + iVar4 + iVar8 * 0x10 + 0x4e));

            *piVar5 = iVar4;

          }

          *(u8 *)(*(int *)(*piVar5 + 0x3c) + 0x150) = 1;

          *(u8 *)(work + iVar7 * 0x80 + iVar8 * 8 + 0x60) = 0;

        }

      }

    }

  }

  return;

}

// FUN_0042BFD0


void FUN_0042bfd0(int param_1)



{

  char *iVar1;
  int ready;
  u32 oldHandle;

  u32 uVar2;

  YajimaVec2 offset;

  

  iVar1 = *(char **)((int)param_1 + 0x3c);
  ready = *(u32 *)DAT_008717e8_abs != 0;
  if (ready) {
    ready = *(u32 *)DAT_008717f4_abs != 0;
  }
  if (ready) {

    oldHandle = *(u32 *)(iVar1 + 0x898);
    if (oldHandle != 0) {

      *(u32 *)(iVar1 + 0x898) = 0;

    }

    FUN_00423fe0_vec2(&offset,0,0x7e,0x7e,0x20,0x20);

    *(float *)(iVar1 + 0x89c) = *(float *)(iVar1 + 0x85c) + offset.x;
    *(float *)(iVar1 + 0x8a0) = *(float *)(iVar1 + 0x860) + offset.y;
    uVar2 = FUN_004560d0_typed(param_1,*(float *)(iVar1 + 0x89c),
                               *(float *)(iVar1 + 0x8a0),1.0f,0x20,0x20);
    *(u32 *)(iVar1 + 0x898) = uVar2;

  }

  return;

}

// FUN_0042C0A0 NONMATCHING


void FUN_0042c0a0(int param_1,char param_2,short param_3,short param_4,int param_5,int param_6)



{

  char cVar1;

  char cVar2;

  char cVar3;

  short sVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  u32 uVar8;

  u32 uVar9;

  int iVar10;


  u8 bVar11;

  int *piVar12;

  float *pfVar13;

  short *psVar14;

  float *pfVar15;

  u8 uVar16;

  float fVar17;

  u32 uVar18;

  float fVar19;
  YRuntimeUnitRow *row;
  float *paramSlot;



  iVar10 = *(int *)(param_1 + 0x3c);
  paramSlot = (float *)(iVar10 + (int)param_2 * 8 + 0x8b8);

  bVar11 = 0;

  iVar7 = (int)param_2;
  row = &DAT_008717a0_unit_rows[iVar7];

  if ((row->unk_048 != 0) && (row->unk_054 != 0)) {

    bVar11 = 1;

  }

  if (bVar11) {

    sVar4 = K_FldFrame_CtlGetXGrid(*(u32 *)((u8 *)row->unk_054 + 0x1e0));

    if ((param_3 == sVar4) &&

       (sVar4 = K_FldFrame_CtlGetZGrid(*(u32 *)((u8 *)row->unk_054 + 0x1e0)),

       param_4 == sVar4)) {

      if (*(char *)(iVar10 + 0x865) == '\0') {
        YajimaVec3 savedMain;

        YajimaVec3 posMain;

        YajimaVec3 savedObj;

        YajimaVec3 posObj;


        cVar1 = *(char *)(iVar10 + 0xb29);
        K_FldFrame_CtlCopyPos(&posMain,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

        savedMain = *(YajimaVec3 *)&posMain;

        iVar5 = K_FldFrame_CtlGetXGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

        fVar17 = savedMain.x - ((float)iVar5 * 800.0f - 400.0f);

        uVar18 = 0x40000000;

        cVar2 = *(char *)(iVar10 + 0xb29);

        piVar12 = DAT_008717f4_y2 + param_2 * 0x70;

        K_FldFrame_CtlCopyPos(&posObj,*(u32 *)(*piVar12 + 0x1e0));

        savedObj = *(YajimaVec3 *)&posObj;

        iVar6 = K_FldFrame_CtlGetXGrid(*(u32 *)(*piVar12 + 0x1e0));

        cVar3 = *(char *)(iVar10 + 0xb29);

        pfVar15 = paramSlot;

        iVar5 = (int)cVar3;

        if (cVar3 < '\0') {

          iVar5 = iVar5 + 1;

        }

        *pfVar15 = ((float)(iVar5 >> 1) +

                   ((((*(float *)(iVar10 + 0x85c) + (float)(cVar3 * param_5)) -

                     (float)(int)(((float)(int)cVar2 / 2.0f + 0.0f) -

                                 (savedObj.x - ((float)iVar6 * 800.0f - 400.0f)) *

                                 ((float)(int)cVar2 / 800.0f))) +

                    (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -

                                fVar17 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar3 << 1)))

                   - 8.0f;

        cVar1 = *(char *)(iVar10 + 0xb29);

        K_FldFrame_CtlCopyPos(&posMain,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

        savedMain = *(YajimaVec3 *)&posMain;

        iVar5 = K_FldFrame_CtlGetZGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

        fVar17 = savedMain.z - ((float)iVar5 * 800.0f - 400.0f);

        fVar19 = (float)(int)*(char *)(iVar10 + 0xb29);

        K_FldFrame_CtlCopyPos(&posObj,*(u32 *)(*piVar12 + 0x1e0));

        savedObj = *(YajimaVec3 *)&posObj;

        iVar6 = K_FldFrame_CtlGetZGrid(*(u32 *)(*piVar12 + 0x1e0));

        cVar2 = *(char *)(iVar10 + 0xb29);

        pfVar13 = paramSlot + 1;

        iVar5 = (int)cVar2;

        if (cVar2 < '\0') {

          iVar5 = iVar5 + 1;

        }

        *pfVar13 = ((float)(iVar5 >> 1) +

                   ((((*(float *)(iVar10 + 0x860) + (float)(cVar2 * param_6)) -

                     (float)(int)((fVar19 / 2.0f + 0.0f) -

                                 (savedObj.z - ((float)iVar6 * 800.0f - 400.0f)) *

                                 (fVar19 / 800.0f))) +

                    (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -

                                fVar17 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar2 << 1)))

                   - 8.0f;

      }

      else {
        YajimaVec3 savedObj1;

        YajimaVec3 posObj1;

        YajimaVec3 worldPos1;

        YajimaVec3 savedObj2;

        YajimaVec3 posObj2;

        YajimaVec3 worldPos2;

        cVar1 = *(char *)(iVar10 + 0xb29);

        worldPos1 = *(YajimaVec3 *)(iVar10 + 0x868);

        iVar5 = FUN_0044f120_y2(&worldPos1);

        fVar17 = worldPos1.x - ((float)iVar5 * 800.0f - 400.0f);

        uVar18 = 0x40000000;

        cVar2 = *(char *)(iVar10 + 0xb29);

        piVar12 = DAT_008717f4_y2 + param_2 * 0x70;

        K_FldFrame_CtlCopyPos(&posObj1,*(u32 *)(*piVar12 + 0x1e0));

        savedObj1 = *(YajimaVec3 *)&posObj1;

        iVar6 = K_FldFrame_CtlGetXGrid(*(u32 *)(*piVar12 + 0x1e0));

        cVar3 = *(char *)(iVar10 + 0xb29);

        pfVar15 = paramSlot;

        iVar5 = (int)cVar3;

        if (cVar3 < '\0') {

          iVar5 = iVar5 + 1;

        }

        *pfVar15 = ((float)(iVar5 >> 1) +

                   ((((*(float *)(iVar10 + 0x85c) + (float)(cVar3 * param_5)) -

                     (float)(int)(((float)(int)cVar2 / 2.0f + 0.0f) -

                                 (savedObj1.x - ((float)iVar6 * 800.0f - 400.0f)) *

                                 ((float)(int)cVar2 / 800.0f))) +

                    (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -

                                fVar17 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar3 << 1)))

                   - 8.0f;

        cVar1 = *(char *)(iVar10 + 0xb29);

        worldPos2 = *(YajimaVec3 *)(iVar10 + 0x868);

        iVar5 = FUN_0044f170_y2(&worldPos2);

        fVar17 = worldPos2.z - ((float)iVar5 * 800.0f - 400.0f);

        fVar19 = (float)(int)*(char *)(iVar10 + 0xb29);

        K_FldFrame_CtlCopyPos(&posObj2,*(u32 *)(*piVar12 + 0x1e0));

        savedObj2 = *(YajimaVec3 *)&posObj2;

        iVar6 = K_FldFrame_CtlGetZGrid(*(u32 *)(*piVar12 + 0x1e0));

        cVar2 = *(char *)(iVar10 + 0xb29);

        pfVar13 = paramSlot + 1;

        iVar5 = (int)cVar2;

        if (cVar2 < '\0') {

          iVar5 = iVar5 + 1;

        }

        *pfVar13 = ((float)(iVar5 >> 1) +

                   ((((*(float *)(iVar10 + 0x860) + (float)(cVar2 * param_6)) -

                     (float)(int)((fVar19 / 2.0f + 0.0f) -

                                 (savedObj2.z - ((float)iVar6 * 800.0f - 400.0f)) *

                                 (fVar19 / 800.0f))) +

                    (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -

                                fVar17 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar2 << 1)))

                   - 8.0f;

      }

      if (*(float *)(iVar10 + 0x85c) < *pfVar15 + 8.0f) {

        if (((*(float *)(iVar10 + 0x860) < *pfVar13 + 8.0f) &&

            (*pfVar15 + 12.0f < *(float *)(iVar10 + 0x85c) + 126.0f)) &&

           (*pfVar13 + 12.0f < *(float *)(iVar10 + 0x860) + 126.0f)) {

          *(u8 *)(param_2 + iVar10 + 0x937) = 1;

          uVar8 = datGetBadStatusNoDown(*(u16 *)(&DAT_00871948 + iVar7 * 0x1c0));
          if ((uVar8 & 0x80) != 0) {
            iVar7 = param_2 * 2 + iVar10;
            psVar14 = (short *)(iVar7 + 0x930);
            fVar17 = (float)sinf(DAT_007cb134 * (float)(int)*psVar14);
            fVar17 = fVar17 * -128.0f + 128.0f;
            sVar4 = *psVar14;
            *psVar14 = sVar4 + 1;
            if (0x28 < (short)(sVar4 + 1)) {
              *psVar14 = 0;
            }
            uVar9 = FUN_001158b0_y2(0,DAT_007ce6e4,10);
            iVar7 = (int)uVar9;
            *(u32 *)(iVar7 + 0x2c) = 0x40400000;
            *(float *)(iVar7 + 0x10) = paramSlot[0] + 3.0f;
            *(float *)(iVar7 + 0x14) = paramSlot[1] + 3.0f;
            if (fVar17 < 2.1474836e+09f) {
              uVar16 = (u8)(int)fVar17;
            }
            else {
              uVar16 = (u8)(int)(fVar17 - 2.1474836e+09f);
            }
            *(u8 *)(iVar7 + 0x18) = uVar16;
            func_001127d0(uVar9,1);
            FUN_00115980(uVar9);
            uVar9 = FUN_001158b0_y2(0,DAT_007ce6e4,8);
            iVar7 = (int)uVar9;
            *(u32 *)(iVar7 + 0x2c) = uVar18;
            *(u32 *)(iVar7 + 0x10) = *(u32 *)(iVar10 + 0x8b8);
            *(u32 *)(iVar7 + 0x14) = *(u32 *)(iVar10 + 0x8bc);
            *(u8 *)(iVar7 + 0x18) = 0;
            func_001127d0(uVar9,1);
            FUN_00115980(uVar9);
          }
          else {
            uVar8 = datGetBadStatusNoDown(*(u16 *)(&DAT_00871948 + iVar7 * 0x1c0));
            if ((uVar8 & 0x80000) != 0) {
              iVar7 = param_2 * 2 + iVar10;
              psVar14 = (short *)(iVar7 + 0x930);
              fVar17 = (float)sinf(DAT_007cb134 * (float)(int)*psVar14);
              fVar17 = fVar17 * -128.0f + 128.0f;
              sVar4 = *psVar14;
              *psVar14 = sVar4 + 1;
              if (0x28 < (short)(sVar4 + 1)) {
                *psVar14 = 0;
              }
              uVar9 = FUN_001158b0_y2(0,DAT_007ce6e4,10);
              iVar7 = (int)uVar9;
              *(u32 *)(iVar7 + 0x2c) = 0x40400000;
              *(float *)(iVar7 + 0x10) = paramSlot[0] + 3.0f;
              *(float *)(iVar7 + 0x14) = paramSlot[1] + 3.0f;
              if (fVar17 < 2.1474836e+09f) {
                uVar16 = (u8)(int)fVar17;
              }
              else {
                uVar16 = (u8)(int)(fVar17 - 2.1474836e+09f);
              }
              *(u8 *)(iVar7 + 0x18) = uVar16;
              func_001127d0(uVar9,1);
              FUN_00115980(uVar9);
              uVar9 = FUN_001158b0_y2(0,DAT_007ce6e4,9);
              iVar7 = (int)uVar9;
              *(u32 *)(iVar7 + 0x2c) = uVar18;
              *(u32 *)(iVar7 + 0x10) = *(u32 *)(iVar10 + 0x8b8);
              *(u32 *)(iVar7 + 0x14) = *(u32 *)(iVar10 + 0x8bc);
              *(u8 *)(iVar7 + 0x18) = 0;
              func_001127d0(uVar9,1);
              FUN_00115980(uVar9);
            }
            else {
              uVar9 = FUN_001158b0_y2(0,DAT_007ce6e4,7);
              iVar10 = (int)uVar9;
              *(u32 *)(iVar10 + 0x2c) = uVar18;
              *(float *)(iVar10 + 0x10) = *pfVar15;
              *(float *)(iVar10 + 0x14) = *pfVar13;
              *(u8 *)(iVar10 + 0x18) = 0;
              func_001127d0(uVar9,1);
              FUN_00115980(uVar9);
            }
          }

        }

      }

    }

  }

  return;

}


// FUN_0042CD80 NONMATCHING








void FUN_0042cd80(int param_1)
{
  u8 *work;
  YajimaPackedRow *row;
  YajimaPackedEntry *entry;
  s8 *counter;
  s8 *delay;
  s16 *offsetX;
  s16 *offsetY;
  u32 random;
  s32 outer;
  s32 inner;
  s32 end;

  work = *(u8 **)(param_1 + 0x3c);
  for (outer = 0; outer < 3; outer++) {
    if ((*(s8 *)(work + outer + 0x938) == 1) &&
        (FUN_0043a230_y2((s8)(outer + 1)) == 1)) {
      inner = outer * 5;
      row = (YajimaPackedRow *)(work + outer * 8);
      end = (outer + 1) * 5;
      for (; inner < end; inner++) {
        entry = (YajimaPackedEntry *)(work + inner);
        counter = &entry->counter;
        offsetY = (s16 *)(work + inner * 2 + 0x914);
        offsetX = (s16 *)(work + inner * 2 + 0x8f6);
        FUN_00430780_y2(8.0f, row->value,
                     *(s8 *)offsetX, *(s8 *)offsetY, entry->counter);
        delay = &entry->delay;
        if (entry->delay < 1) {
        entry->counter++;
        if (entry->counter > 20) {
            random = FUN_00488f30();
            *offsetX = (s16)(8.0f - (f32)(random & 0xf));
            random = FUN_00488f30();
            *offsetY = (s16)(8.0f - (f32)(random & 0xf));
            *counter = 0;
            *delay = 4;
          }
        }
        else {
          (*delay)--;
        }
        }
      }
    }
  }

/* W327 measured: opt_loop_invariants on reduces normalized_diff 2541 -> 2533 (object 3304/3536 -> 3328/3536). */
#pragma opt_loop_invariants on
// FUN_0042CFC0 NONMATCHING


void FUN_0042cfc0(int param_1,u16 param_2,u16 param_3,int param_4,int param_5)



{

  char cVar1;

  char cVar2;

  char cVar3;

  int iVar4;

  short sVar5;

  int iVar6;

  int iVar7;

  int lVar8;

  u32 uVar9;

  int iVar10;

  u8 bVar11;

  int *piVar12;

  float *pfVar13;

  float *pfVar14;

  int iVar15;

  int iVar16;

  u8 uVar17;

  float fVar18;

  float fVar19;

  u32 uStack_160;

  u32 uStack_15c;

  float fStack_158;

  u32 uStack_150;

  u32 uStack_14c;

  float fStack_148;

  u32 uStack_140;

  u32 uStack_13c;

  float fStack_138;

  u32 uStack_130;

  u32 uStack_12c;

  float fStack_128;

  float fStack_120;

  u32 uStack_11c;

  u32 uStack_118;

  float fStack_110;

  u32 uStack_10c;

  u32 uStack_108;

  float fStack_100;

  u32 uStack_fc;

  u32 uStack_f8;

  float fStack_f0;

  u32 uStack_ec;

  u32 uStack_e8;

  u32 uStack_e0;

  u32 uStack_dc;

  float fStack_d8;

  u32 uStack_d0;

  u32 uStack_cc;

  float fStack_c8;

  u32 uStack_c0;

  u32 uStack_bc;

  float fStack_b8;

  float fStack_b0;

  u32 uStack_ac;

  u32 uStack_a8;

  float fStack_a0;

  u32 uStack_9c;

  u32 uStack_98;

  float fStack_90;

  u32 uStack_8c;

  u32 uStack_88;

  u32 uStack_80;

  u32 uStack_7c;

  float fStack_78;

  u32 uStack_70;

  u32 uStack_6c;

  float fStack_68;

  u32 uStack_60;

  u32 uStack_5c;

  float fStack_58;

  u32 uStack_50;

  u32 uStack_4c;

  float fStack_48;

  float fStack_40;

  u32 uStack_3c;

  u32 uStack_38;

  float fStack_30;

  u32 uStack_2c;

  u32 uStack_28;

  float fStack_20;

  u32 uStack_1c;

  u32 uStack_18;

  float fStack_10;

  u32 uStack_c;

  u32 uStack_8;

  
  YajimaVec3 posMain0;
  YajimaVec3 savedMain0;
  YajimaVec3 posObj0;
  YajimaVec3 savedObj0;
  YajimaVec3 worldPos1;
  YajimaVec3 posObj1;
  YajimaVec3 savedObj1;
  YajimaVec3 worldPos2;
  YajimaVec3 posObj2;
  YajimaVec3 savedObj2;
  YajimaVec3 posObj3;
  YajimaVec3 savedObj3;
  YajimaVec3 posMain3;
  YajimaVec3 savedMain3;
  YajimaVec3 posObj4;
  YajimaVec3 savedObj4;
  YajimaVec3 posMain4;
  YajimaVec3 savedMain4;

  iVar4 = *(int *)(param_1 + 0x3c);

  for (iVar15 = 0; iVar15 < 0x18; iVar15 = iVar15 + 1) {

    iVar10 = (iVar15 * 7) << 6;

    if ((*(int *)(DAT_0086eda0_abs + iVar10 + 0x48) != 0) &&
        (*(int *)(DAT_0086eda0_abs + iVar10 + 0x54) != 0)) {

      lVar8 = K_FldFrame_CtlGetXGrid(*(u32 *)(*(int *)(DAT_0086eda0_abs + iVar10 + 0x54) + 0x1e0));

      if (((short)param_2 == lVar8) &&
         (lVar8 = K_FldFrame_CtlGetZGrid(*(u32 *)(*(int *)(DAT_0086eda0_abs + iVar10 + 0x54) + 0x1e0)),
         (short)param_3 == lVar8)) {

        cVar3 = (char)iVar15;

        if (*(char *)(iVar4 + 0x865) == '\0') {

          cVar1 = *(char *)(iVar4 + 0xb29);

          K_FldFrame_CtlCopyPos(&posMain0,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          savedMain0 = posMain0;

          iVar6 = K_FldFrame_CtlGetXGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          fVar18 = savedMain0.x - ((float)iVar6 * 800.0f - 400.0f);

          fVar19 = (float)(int)*(char *)(iVar4 + 0xb29);

          piVar12 = (int *)(DAT_0086eda0_abs + cVar3 * 0x1c0 + 0x54);

          K_FldFrame_CtlCopyPos(&posObj0,*(u32 *)(*piVar12 + 0x1e0));

          savedObj0 = posObj0;

          iVar7 = K_FldFrame_CtlGetXGrid(*(u32 *)(*piVar12 + 0x1e0));

          cVar2 = *(char *)(iVar4 + 0xb29);

          iVar16 = iVar4 + iVar15 * 8;

          pfVar14 = (float *)(iVar16 + 0x93c);

          iVar6 = (int)cVar2;

          if (cVar2 < '\0') {

            iVar6 = iVar6 + 1;

          }

          *pfVar14 = ((float)(iVar6 >> 1) +

                     ((((*(float *)(iVar4 + 0x85c) + (float)(cVar2 * param_4)) -

                       ((fVar19 / 2.0f + 0.0f) -

                       (savedObj0.x - ((float)iVar7 * 800.0f - 400.0f)) * (fVar19 / 800.0f))) +

                      (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -

                                  fVar18 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar2 << 1))

                     ) - 8.0f;

          cVar1 = *(char *)(iVar4 + 0xb29);

          K_FldFrame_CtlCopyPos(&posMain0,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          savedMain0 = posMain0;

          iVar6 = K_FldFrame_CtlGetZGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          fVar18 = savedMain0.z - ((float)iVar6 * 800.0f - 400.0f);

          fVar19 = (float)(int)*(char *)(iVar4 + 0xb29);

          K_FldFrame_CtlCopyPos(&posObj0,*(u32 *)(*piVar12 + 0x1e0));

          savedObj0 = posObj0;

          iVar7 = K_FldFrame_CtlGetZGrid(*(u32 *)(*piVar12 + 0x1e0));

          cVar2 = *(char *)(iVar4 + 0xb29);

          pfVar13 = (float *)(iVar16 + 0x940);

          iVar6 = (int)cVar2;

          if (cVar2 < '\0') {

            iVar6 = iVar6 + 1;

          }

          *pfVar13 = ((float)(iVar6 >> 1) +

                     ((((*(float *)(iVar4 + 0x860) + (float)(cVar2 * param_5)) -

                       ((fVar19 / 2.0f + 0.0f) -

                       (savedObj0.z - ((float)iVar7 * 800.0f - 400.0f)) * (fVar19 / 800.0f))) +

                      (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -
                                  fVar18 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar2 << 1))

                     ) - 8.0f;

        }

        else {

          cVar1 = *(char *)(iVar4 + 0xb29);

          worldPos1 = *(YajimaVec3 *)(iVar4 + 0x868);

          iVar6 = FUN_0044f120_y2(&worldPos1);

          fVar18 = worldPos1.x - ((float)iVar6 * 800.0f - 400.0f);

          fVar19 = (float)(int)*(char *)(iVar4 + 0xb29);

          piVar12 = (int *)(DAT_0086eda0_abs + cVar3 * 0x1c0 + 0x54);

          K_FldFrame_CtlCopyPos(&posObj1,*(u32 *)(*piVar12 + 0x1e0));

          savedObj1 = posObj1;

          iVar7 = K_FldFrame_CtlGetXGrid(*(u32 *)(*piVar12 + 0x1e0));

          cVar2 = *(char *)(iVar4 + 0xb29);

          iVar16 = iVar4 + iVar15 * 8;

          pfVar14 = (float *)(iVar16 + 0x93c);

          iVar6 = (int)cVar2;

          if (cVar2 < '\0') {

            iVar6 = iVar6 + 1;

          }

          *pfVar14 = ((float)(iVar6 >> 1) +

                     ((((*(float *)(iVar4 + 0x85c) + (float)(cVar2 * param_4)) -

                       ((fVar19 / 2.0f + 0.0f) -

                       (savedObj1.x - ((float)iVar7 * 800.0f - 400.0f)) * (fVar19 / 800.0f))) +

                      (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -

                                  fVar18 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar2 << 1))

                     ) - 8.0f;

          cVar1 = *(char *)(iVar4 + 0xb29);

          worldPos2 = *(YajimaVec3 *)(iVar4 + 0x868);

          iVar6 = FUN_0044f170_y2(&worldPos2);

          fVar18 = worldPos2.z - ((float)iVar6 * 800.0f - 400.0f);

          fVar19 = (float)(int)*(char *)(iVar4 + 0xb29);

          K_FldFrame_CtlCopyPos(&posObj2,*(u32 *)(*piVar12 + 0x1e0));

          savedObj2 = posObj2;

          iVar7 = K_FldFrame_CtlGetZGrid(*(u32 *)(*piVar12 + 0x1e0));

          cVar2 = *(char *)(iVar4 + 0xb29);

          pfVar13 = (float *)(iVar16 + 0x940);

          iVar6 = (int)cVar2;

          if (cVar2 < '\0') {

            iVar6 = iVar6 + 1;

          }

          *pfVar13 = ((float)(iVar6 >> 1) +

                     ((((*(float *)(iVar4 + 0x860) + (float)(cVar2 * param_5)) -

                       ((fVar19 / 2.0f + 0.0f) -

                       (savedObj2.z - ((float)iVar7 * 800.0f - 400.0f)) * (fVar19 / 800.0f))) +

                      (float)(int)(((float)(int)cVar1 / 2.0f + 0.0f) -

                                  fVar18 * ((float)(int)cVar1 / 800.0f))) - (float)((int)cVar2 << 1))

                     ) - 8.0f;

        }

        lVar8 = K_FldEvent_AreUnitsWithinDist(0x44fa0000,&DAT_0086eda0 + iVar10,0x8717a0);

        if (lVar8 == 1) {

          if (*(int *)(&DAT_0086ef2c + iVar10) == 4) {

            fVar18 = (float)sinf(DAT_007cb138 * (float)(int)*(short *)(iVar4 + 0x9fc));

            fVar18 = fVar18 * -100.0f + 100.0f;

            sVar5 = *(short *)(iVar4 + 0x9fc) + 1;

            *(short *)(iVar4 + 0x9fc) = sVar5;

            if (0x14 < sVar5) {

              *(u16 *)(iVar4 + 0x9fc) = 0;

            }

            uVar9 = FUN_001158b0_y2(0,DAT_007ce6e4,0xb);

            iVar10 = (int)uVar9;

            *(u32 *)(iVar10 + 0x2c) = 0x40000000;

            *(float *)(iVar10 + 0x10) = *pfVar14;

            *(float *)(iVar10 + 0x14) = *pfVar13;

            if (fVar18 < 2.1474836e+09f) {

              uVar17 = (u8)(int)fVar18;

            }

            else {

              uVar17 = (u8)(int)(fVar18 - 2.1474836e+09f);

            }

            *(u8 *)(iVar10 + 0x18) = uVar17;

            func_001127d0(uVar9,1);

            FUN_00115980(uVar9);

          }

          else {

            uVar9 = FUN_001158b0_y2(0,DAT_007ce6e4,0xb);

            iVar10 = (int)uVar9;

            *(u32 *)(iVar10 + 0x2c) = 0x40000000;

            *(float *)(iVar10 + 0x10) = *pfVar14;

            *(float *)(iVar10 + 0x14) = *pfVar13;

            *(u8 *)(iVar10 + 0x18) = 0;

            func_001127d0(uVar9,1);

            FUN_00115980(uVar9);

          }

        }

        else if (*(int *)(DAT_0086eda0_abs + iVar10 + 0x54) != 0) {

          cVar1 = *(char *)(iVar4 + 0xb29);

          piVar12 = (int *)(DAT_0086eda0_abs + cVar3 * 0x1c0 + 0x54);

          K_FldFrame_CtlCopyPos(&posObj3,*(u32 *)(*piVar12 + 0x1e0));

          savedObj3 = posObj3;

          iVar10 = K_FldFrame_CtlGetXGrid(*(u32 *)(*piVar12 + 0x1e0));

          fVar18 = savedObj3.x - ((float)iVar10 * 800.0f - 400.0f);

          fVar19 = (float)(int)*(char *)(iVar4 + 0xb29);

          K_FldFrame_CtlCopyPos(&posMain3,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          savedMain3 = posMain3;

          iVar6 = K_FldFrame_CtlGetXGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          cVar3 = *(char *)(iVar4 + 0xb29);

          iVar10 = (int)cVar3;

          if (cVar3 < '\0') {

            iVar10 = iVar10 + 3;

          }

          *pfVar14 = ((float)(iVar10 >> 2) +

                      ((*(float *)(iVar4 + 0x85c) +

                       (float)(int)((fVar19 / 2.0f + 0.0f) -

                                   (savedMain3.x - ((float)iVar6 * 800.0f - 400.0f)) * (fVar19 / 800.0f)))

                      - (((float)(int)cVar1 / 2.0f + 0.0f) - fVar18 * ((float)(int)cVar1 / 800.0f))) +

                     2.0f) - (float)((int)cVar3 << 1);

          cVar3 = *(char *)(iVar4 + 0xb29);

          K_FldFrame_CtlCopyPos(&posObj4,*(u32 *)(*piVar12 + 0x1e0));

          savedObj4 = posObj4;

          iVar10 = K_FldFrame_CtlGetZGrid(*(u32 *)(*piVar12 + 0x1e0));

          fVar18 = savedObj4.z - ((float)iVar10 * 800.0f - 400.0f);

          fVar19 = (float)(int)*(char *)(iVar4 + 0xb29);

          K_FldFrame_CtlCopyPos(&posMain4,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          savedMain4 = posMain4;

          iVar6 = K_FldFrame_CtlGetZGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          cVar1 = *(char *)(iVar4 + 0xb29);

          iVar10 = (int)cVar1;

          if (cVar1 < '\0') {

            iVar10 = iVar10 + 3;

          }

          *pfVar13 = ((float)(iVar10 >> 2) +

                      ((*(float *)(iVar4 + 0x860) +

                       (float)(int)((fVar19 / 2.0f + 0.0f) -

                                   (savedMain4.z - ((float)iVar6 * 800.0f - 400.0f)) * (fVar19 / 800.0f))

                       ) - (((float)(int)cVar3 / 2.0f + 0.0f) - fVar18 * ((float)(int)cVar3 / 800.0f)))

                     + 2.0f) - (float)((int)cVar1 << 1);

          DAT_0095c210_y2[iVar15] = 0;

        }

      }

    }

  }

  return;

}
#pragma opt_loop_invariants reset

/*
 * The retail routine keeps collision positions as contiguous three-float
 * temporaries before deriving grid coordinates and distance checks.
 * Reconstruct those aggregate copies here so all vector components remain
 * live across helper calls instead of being eliminated as unrelated scalars.
 */
// FUN_0042DD90 NONMATCHING


void FUN_0042dd90(int param_1,short param_2,u16 param_3,int param_4,int param_5)



{

  char cVar1;

  int iVar2;

  char cVar3;


  int iVar5;

  int iVar6;

  u32 uVar7;

  long lVar8;

  u64 uVar9;

  int iVar10;

  int iVar11;

  u8 uVar12;

  u8 uVar13;

  float *pfVar14;

  int iVar15;

  float fVar16;

  float fVar17;

  float fVar18;

  u32 uStack_e0;

  u32 uStack_dc;

  float fStack_d8;

  float fStack_d0;

  u32 uStack_cc;

  float fStack_c8;

  float fStack_c0;

  u32 uStack_bc;

  u32 uStack_b8;

  float fStack_b0;

  u32 uStack_ac;

  u32 uStack_a8;

  u32 uStack_a0;

  u32 uStack_9c;

  float fStack_98;

  u32 uStack_90;

  u32 uStack_8c;

  float fStack_88;

  float fStack_80;

  u32 uStack_7c;

  float fStack_78;

  float fStack_70;

  u32 uStack_6c;

  u32 uStack_68;

  float fStack_60;

  u32 uStack_5c;

  u32 uStack_58;

  float fStack_50;

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


  

  iVar2 = *(int *)(param_1 + 0x3c);

  for (iVar15 = 0; iVar15 < 8; iVar15 = iVar15 + 1) {

    if (*(int *)(&DAT_0086be00 + iVar15 * 0x10) != 0) {

      lVar8 = FUN_0044f120_y2(&DAT_0086be04 + iVar15 * 0x10);

      if (((short)param_2 == lVar8) &&

         (lVar8 = FUN_0044f170_y2(&DAT_0086be04 + iVar15 * 0x10),

         (short)param_3 == lVar8)) {

        if (*(char *)(iVar2 + 0x865) == '\0') {
          YajimaVec3 savedMain;
          YajimaVec3 posMain;
          YajimaVec3 worldPos1;
          YajimaVec3 worldPos2;




          cVar3 = *(char *)(iVar2 + 0xb29);

          K_FldFrame_CtlCopyPos(&posMain,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          savedMain = *(YajimaVec3 *)&posMain;



          iVar5 = K_FldFrame_CtlGetXGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          fVar17 = savedMain.x - ((float)iVar5 * 800.0f - 400.0f);



          fVar18 = (float)(int)*(char *)(iVar2 + 0xb29);

          iVar10 = iVar15 * 0x10;

          pfVar14 = (float *)(&DAT_0086be04 + iVar10);

          worldPos1 = *(YajimaVec3 *)(&DAT_0086be04 + iVar10);

          iVar6 = FUN_0044f120_y2(&worldPos1);


          cVar1 = *(char *)(iVar2 + 0xb29);

          iVar11 = (int)cVar1;

          iVar5 = iVar11;

          if (cVar1 < '\0') {

            iVar5 = iVar11 + 1;

          }

          fVar18 = ((float)(iVar5 >> 1) +

                   ((((*(float *)(iVar2 + 0x85c) + (float)(cVar1 * param_4)) -

                     ((fVar18 / 2.0f + 0.0f) -

                     (worldPos1.x - ((float)iVar6 * 800.0f - 400.0f)) * (fVar18 / 800.0f))) +


                    (float)(int)(((float)(int)cVar3 / 2.0f + 0.0f) -

                                fVar17 * ((float)(int)cVar3 / 800.0f))) - (float)((int)cVar1 << 1)))

                   - 8.0f;

          K_FldFrame_CtlCopyPos(&posMain,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          savedMain = *(YajimaVec3 *)&posMain;



          iVar5 = K_FldFrame_CtlGetZGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          fVar17 = savedMain.z - ((float)iVar5 * 800.0f - 400.0f);


          cVar3 = *(char *)(iVar2 + 0xb29);

          worldPos2 = *(YajimaVec3 *)(&DAT_0086be04 + iVar10);

          iVar6 = FUN_0044f170_y2(&worldPos2);


          cVar1 = *(char *)(iVar2 + 0xb29);

          iVar5 = (int)cVar1;

          if (cVar1 < '\0') {

            iVar5 = iVar5 + 1;

          }

          fVar17 = (float)(iVar5 >> 1) +

                   ((((*(float *)(iVar2 + 0x860) + (float)(cVar1 * param_5)) -

                     (((float)(int)cVar3 / 2.0f + 0.0f) -

                     (worldPos2.z - ((float)iVar6 * 800.0f - 400.0f)) * ((float)(int)cVar3 / 800.0f))) +


                    (float)(int)(((float)iVar11 / 2.0f + 0.0f) - fVar17 * ((float)iVar11 / 800.0f))) -

                   (float)((int)cVar1 << 1));

        }

        else {
          YajimaVec3 worldPos1;
          YajimaVec3 worldPos2;


          cVar3 = *(char *)(iVar2 + 0xb29);

          worldPos1 = *(YajimaVec3 *)(iVar2 + 0x868);

          iVar5 = FUN_0044f120_y2(&worldPos1);


          fVar17 = worldPos1.x - ((float)iVar5 * 800.0f - 400.0f);


          fVar18 = (float)(int)*(char *)(iVar2 + 0xb29);

          iVar10 = iVar15 * 0x10;

          pfVar14 = (float *)(&DAT_0086be04 + iVar10);

          worldPos2 = *(YajimaVec3 *)(&DAT_0086be04 + iVar10);

          iVar6 = FUN_0044f120_y2(&worldPos2);


          cVar1 = *(char *)(iVar2 + 0xb29);

          iVar11 = (int)cVar1;

          iVar5 = iVar11;

          if (cVar1 < '\0') {

            iVar5 = iVar11 + 1;

          }

          fVar18 = ((float)(iVar5 >> 1) +

                   ((((*(float *)(iVar2 + 0x85c) + (float)(cVar1 * param_4)) -

                     ((fVar18 / 2.0f + 0.0f) -

                     (worldPos2.x - ((float)iVar6 * 800.0f - 400.0f)) * (fVar18 / 800.0f))) +


                    (float)(int)(((float)(int)cVar3 / 2.0f + 0.0f) -

                                fVar17 * ((float)(int)cVar3 / 800.0f))) - (float)((int)cVar1 << 1)))

                   - 8.0f;

          worldPos1 = *(YajimaVec3 *)(iVar2 + 0x868);

          iVar5 = FUN_0044f170_y2(&worldPos1);


          fVar17 = worldPos1.z - ((float)iVar5 * 800.0f - 400.0f);


          cVar3 = *(char *)(iVar2 + 0xb29);

          worldPos2 = *(YajimaVec3 *)(&DAT_0086be04 + iVar10);

          iVar6 = FUN_0044f170_y2(&worldPos2);


          cVar1 = *(char *)(iVar2 + 0xb29);

          iVar5 = (int)cVar1;

          if (cVar1 < '\0') {

            iVar5 = iVar5 + 1;

          }

          fVar17 = (float)(iVar5 >> 1) +

                   ((((*(float *)(iVar2 + 0x860) + (float)(cVar1 * param_5)) -
                     (((float)(int)cVar3 / 2.0f + 0.0f) -

                     (worldPos2.z - ((float)iVar6 * 800.0f - 400.0f)) * ((float)(int)cVar3 / 800.0f))) +

                    (float)(int)(((float)iVar11 / 2.0f + 0.0f) - fVar17 * ((float)iVar11 / 800.0f))) -

                   (float)((int)cVar1 << 1));

        }

        fVar17 = fVar17 - 8.0f;

        iVar5 = *(int *)(&DAT_0086be00 + iVar15 * 0x10);

        uVar12 = (u8)param_2;

        uVar13 = (u8)param_3;

        switch (iVar5) {
        case 1:

          uVar9 = FUN_001158b0_y2(0,DAT_007ce6e4,7);

          iVar5 = (int)uVar9;

          *(u32 *)(iVar5 + 0x2c) = 0x40000000;

          *(float *)(iVar5 + 0x10) = fVar18;

          *(float *)(iVar5 + 0x14) = fVar17;

          *(u8 *)(iVar5 + 0x18) = 0xff;

          if ((((*(float *)(iVar2 + 0x85c) < fVar18 + 8.0f) &&
               (*(float *)(iVar2 + 0x860) < fVar17 + 8.0f)) &&
              (fVar18 + 12.0f < *(float *)(iVar2 + 0x85c) + 126.0f)) &&
             (fVar17 + 12.0f < *(float *)(iVar2 + 0x860) + 126.0f)) {

            *(u8 *)(iVar5 + 0x18) = 0;

          }

          func_001127d0(uVar9,1);

          FUN_00115980(uVar9);

          break;

        case 2: {
          YajimaVec3 posMain;
          YajimaVec3 posY;
          YajimaVec3 posZ;
          YajimaVec3 delta;


          K_FldFrame_CtlCopyPos(&posMain,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          delta.x = *pfVar14 - posMain.x;

          K_FldFrame_CtlCopyPos(&posY,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          delta.y = *(float *)(&DAT_0086be08 + iVar15 * 0x10) - posY.y;

          K_FldFrame_CtlCopyPos(&posZ,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          delta.z = *(float *)(&DAT_0086be0c + iVar15 * 0x10) - posZ.z;

          fVar16 = (float)RwV3dLength((const RwV3d *)&delta);

          if (fVar16 < 2000.0f) {

            uVar9 = FUN_001158b0_y2(0,DAT_007ce6e4,0xb);

            iVar5 = (int)uVar9;

            *(u32 *)(iVar5 + 0x2c) = 0x40000000;

            *(float *)(iVar5 + 0x10) = fVar18;

            *(float *)(iVar5 + 0x14) = fVar17;

            *(u8 *)(iVar5 + 0x18) = 0xff;

            if (((*(float *)(iVar2 + 0x85c) < fVar18 + 8.0f) &&
                (*(float *)(iVar2 + 0x860) < fVar17 + 8.0f)) &&
               ((fVar18 + 12.0f < *(float *)(iVar2 + 0x85c) + 126.0f &&
                (fVar17 + 12.0f < *(float *)(iVar2 + 0x860) + 126.0f)))) {

              *(u8 *)(iVar5 + 0x18) = 0;

            }

            func_001127d0(uVar9,1);

            FUN_00115980(uVar9);

          }

          }
          break;
        case 3:

          uVar9 = FUN_001158b0_y2(0,DAT_007ce6e4,0xc);

          iVar5 = (int)uVar9;

          *(u32 *)(iVar5 + 0x2c) = 0x40400000;

          *(float *)(iVar5 + 0x10) = fVar18;

          *(float *)(iVar5 + 0x14) = fVar17;

          *(u8 *)(iVar5 + 0x18) = 0xff;

          if (((*(float *)(iVar2 + 0x85c) < fVar18 + 8.0f) &&
              (*(float *)(iVar2 + 0x860) < fVar17 + 8.0f)) &&
             ((fVar18 + 12.0f < *(float *)(iVar2 + 0x85c) + 126.0f &&
              (fVar17 + 12.0f < *(float *)(iVar2 + 0x860) + 126.0f)))) {

            cVar3 = FUN_00433810(uVar12,uVar13);

            if (cVar3 != '\0') {

              uVar7 = FUN_00433810(uVar12,uVar13);

              if (DAT_0095c110[uVar7 & 0xff] == '\x01') {

                *(u8 *)(iVar5 + 0x18) = 0;

              }

            }

            else {

              if (DAT_0095c110[(short)param_3 * 0x10 + (int)param_2] == '\x01') {

                *(u8 *)(iVar5 + 0x18) = 0;

              }

            }

          }

          func_001127d0(uVar9,1);

          FUN_00115980(uVar9);

          break;
        case 4:
          uVar9 = FUN_001158b0_y2(0,DAT_007ce6e4,5);

          iVar5 = (int)uVar9;

          *(u32 *)(iVar5 + 0x2c) = 0x40400000;

          *(float *)(iVar5 + 0x10) = fVar18;

          *(float *)(iVar5 + 0x14) = fVar17;

          *(u8 *)(iVar5 + 0x18) = 0xff;

          if ((((*(float *)(iVar2 + 0x85c) < fVar18 + 8.0f) &&
               (*(float *)(iVar2 + 0x860) < fVar17 + 8.0f)) &&
              (fVar18 + 12.0f < *(float *)(iVar2 + 0x85c) + 126.0f)) &&
             (fVar17 + 12.0f < *(float *)(iVar2 + 0x860) + 126.0f)) {

            cVar3 = FUN_00433810(uVar12,uVar13);

            if (cVar3 != '\0') {

              uVar7 = FUN_00433810(uVar12,uVar13);

              if (DAT_0095c110[uVar7 & 0xff] == '\x01') {

                *(u8 *)(iVar5 + 0x18) = 0;

              }

            }

            else {

              if (DAT_0095c110[(short)param_3 * 0x10 + (int)param_2] == '\x01') {

                *(u8 *)(iVar5 + 0x18) = 0;

              }

            }

          }

          func_001127d0(uVar9,1);

          FUN_00115980(uVar9);

          break;




      }
        }

    }

  }

  return;

}

/* W327 measured: opt_loop_invariants on reduces normalized_diff 1890 -> 1837 (object 2468/2528 -> 2468/2528). */
#pragma opt_loop_invariants on
// FUN_0042EA60 NONMATCHING


void FUN_0042ea60(int param_1,u16 param_2,u16 param_3,int param_4,int param_5)



{

  char cVar1;

  int iVar2;

  char cVar3;

  int iVar4;

  u32 uVar5;

  int lVar6;

  u32 uVar7;

  int iVar8;

  int iVar9;


  float *pfVar10;

  int iVar11;

  float fVar12;

  float fVar13;

  float fVar14;

  float fVar15;

  float fVar16;

  u32 uStack_a0;

  u32 uStack_9c;

  float fStack_98;

  u32 uStack_90;

  u32 uStack_8c;

  float fStack_88;

  float fStack_80;

  u32 uStack_7c;

  u32 uStack_78;

  float fStack_70;

  u32 uStack_6c;

  u32 uStack_68;

  u32 uStack_60;

  u32 uStack_5c;

  float fStack_58;

  YajimaVec3 mainPosZ;

  YajimaVec3 savedMainZ;

  float fStack_30;

  u32 uStack_2c;

  u32 uStack_28;

  YajimaVec3 mainPosX;

  YajimaVec3 savedMainX;

  

  iVar2 = *(int *)(param_1 + 0x3c);

  for (iVar9 = 0; iVar9 < 0x20; iVar9 = iVar9 + 1) {

    if (*(int *)(&DAT_0086be80 + iVar9 * 0x138) != 0) {


      lVar6 = FUN_0044f120_y2(&DAT_0086bf8c + iVar9 * 0x138);

      if (((short)param_2 == lVar6) &&

         (lVar6 = FUN_0044f170_y2(&DAT_0086bf8c + iVar9 * 0x138),

         (short)param_3 == lVar6)) {

        uVar7 = FUN_001158b0_y2(0,DAT_007ce6e4,0xc);

        if (*(char *)(iVar2 + 0x865) != '\0') {

          cVar3 = *(char *)(iVar2 + 0xb29);

          iVar8 = iVar9 * 0x138;

          fStack_80 = *(float *)(&DAT_0086bf8c + iVar8);

          uStack_7c = *(u32 *)(&DAT_0086bf90 + iVar8);

          uStack_78 = *(u32 *)(&DAT_0086bf94 + iVar8);

          iVar4 = FUN_0044f120_y2(&fStack_80);

          fVar14 = fStack_80 - ((float)iVar4 * 800.0f - 400.0f);

          fVar16 = (float)(int)*(char *)(iVar2 + 0xb29);

          fStack_70 = *(float *)(iVar2 + 0x868);

          uStack_6c = *(u32 *)(iVar2 + 0x86c);

          uStack_68 = *(u32 *)(iVar2 + 0x870);

          iVar4 = FUN_0044f120_y2(&fStack_70);

          fVar15 = fStack_70 - ((float)iVar4 * 800.0f - 400.0f);

          cVar1 = *(char *)(iVar2 + 0xb29);

          iVar11 = iVar2 + iVar9 * 8;

          fVar12 = *(float *)(iVar2 + 0x85c);

          iVar4 = (int)cVar1;

          if (cVar1 < '\0') {

            iVar4 = iVar4 + 1;

          }

          fVar13 = (float)func_001126b0(uVar7);

          *(float *)(iVar11 + 0xa00) =

               ((float)(iVar4 >> 1) +

               (((fVar12 + (float)(cVar1 * param_4) +

                 (float)(int)((fVar16 / 2.0f + 0.0f) - fVar15 * (fVar16 / 800.0f))) -

                (((float)(int)cVar3 / 2.0f + 0.0f) - fVar14 * ((float)(int)cVar3 / 800.0f))) -

               (float)((int)cVar1 << 1))) - fVar13 / 2.0f;

          cVar3 = *(char *)(iVar2 + 0xb29);

          uStack_a0 = *(u32 *)(&DAT_0086bf8c + iVar8);

          uStack_9c = *(u32 *)(&DAT_0086bf90 + iVar8);

          fStack_98 = *(float *)(&DAT_0086bf94 + iVar8);

          iVar4 = FUN_0044f170_y2(&uStack_a0);

          fVar14 = fStack_98 - ((float)iVar4 * 800.0f - 400.0f);

          fVar16 = (float)(int)*(char *)(iVar2 + 0xb29);

          uStack_90 = *(u32 *)(iVar2 + 0x868);

          uStack_8c = *(u32 *)(iVar2 + 0x86c);

          fStack_88 = *(float *)(iVar2 + 0x870);

          iVar4 = FUN_0044f170_y2(&uStack_90);

          fVar15 = fStack_88 - ((float)iVar4 * 800.0f - 400.0f);

          cVar1 = *(char *)(iVar2 + 0xb29);

          pfVar10 = (float *)(iVar11 + 0xa04);

          fVar12 = *(float *)(iVar2 + 0x860);

          iVar4 = (int)cVar1;

          if (cVar1 < '\0') {

            iVar4 = iVar4 + 1;

          }

          fVar13 = (float)func_00112740(uVar7);

          *pfVar10 = ((float)(iVar4 >> 1) +

                     (((fVar12 + (float)(cVar1 * param_5) +

                       (float)(int)((fVar16 / 2.0f + 0.0f) - fVar15 * (fVar16 / 800.0f))) -

                      (((float)(int)cVar3 / 2.0f + 0.0f) - fVar14 * ((float)(int)cVar3 / 800.0f))) -

                     (float)((int)cVar1 << 1))) - fVar13 / 2.0f;

        }

        else {

          cVar3 = *(char *)(iVar2 + 0xb29);

          iVar8 = iVar9 * 0x138;

          fStack_30 = *(float *)(&DAT_0086bf8c + iVar8);

          uStack_2c = *(u32 *)(&DAT_0086bf90 + iVar8);

          uStack_28 = *(u32 *)(&DAT_0086bf94 + iVar8);

          iVar4 = FUN_0044f120_y2(&fStack_30);

          fVar14 = fStack_30 - ((float)iVar4 * 800.0f - 400.0f);

          fVar16 = (float)(int)*(char *)(iVar2 + 0xb29);

          K_FldFrame_CtlCopyPos(&mainPosX,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          savedMainX = mainPosX;

          iVar4 = K_FldFrame_CtlGetXGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          fVar15 = savedMainX.x - ((float)iVar4 * 800.0f - 400.0f);

          cVar1 = *(char *)(iVar2 + 0xb29);

          iVar11 = iVar2 + iVar9 * 8;

          fVar12 = *(float *)(iVar2 + 0x85c);

          iVar4 = (int)cVar1;

          if (cVar1 < '\0') {

            iVar4 = iVar4 + 1;

          }

          fVar13 = (float)func_001126b0(uVar7);

          *(float *)(iVar11 + 0xa00) =

               ((float)(iVar4 >> 1) +

               (((fVar12 + (float)(cVar1 * param_4) +

                 (float)(int)((fVar16 / 2.0f + 0.0f) - fVar15 * (fVar16 / 800.0f))) -

                (((float)(int)cVar3 / 2.0f + 0.0f) - fVar14 * ((float)(int)cVar3 / 800.0f))) -

               (float)((int)cVar1 << 1))) - fVar13 / 2.0f;

          cVar3 = *(char *)(iVar2 + 0xb29);

          uStack_60 = *(u32 *)(&DAT_0086bf8c + iVar8);

          uStack_5c = *(u32 *)(&DAT_0086bf90 + iVar8);

          fStack_58 = *(float *)(&DAT_0086bf94 + iVar8);

          iVar4 = FUN_0044f170_y2(&uStack_60);

          fVar14 = fStack_58 - ((float)iVar4 * 800.0f - 400.0f);

          fVar16 = (float)(int)*(char *)(iVar2 + 0xb29);

          K_FldFrame_CtlCopyPos(&mainPosZ,*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          savedMainZ = mainPosZ;

          iVar4 = K_FldFrame_CtlGetZGrid(*(u32 *)(*(u32 *)DAT_008717f4_abs + 0x1e0));

          fVar15 = savedMainZ.z - ((float)iVar4 * 800.0f - 400.0f);

          cVar1 = *(char *)(iVar2 + 0xb29);

          pfVar10 = (float *)(iVar11 + 0xa04);

          fVar12 = *(float *)(iVar2 + 0x860);

          iVar4 = (int)cVar1;

          if (cVar1 < '\0') {

            iVar4 = iVar4 + 1;

          }

          fVar13 = (float)func_00112740(uVar7);

          *pfVar10 = ((float)(iVar4 >> 1) +

                     (((fVar12 + (float)(cVar1 * param_5) +

                       (float)(int)((fVar16 / 2.0f + 0.0f) - fVar15 * (fVar16 / 800.0f))) -

                      (((float)(int)cVar3 / 2.0f + 0.0f) - fVar14 * ((float)(int)cVar3 / 800.0f))) -

                     (float)((int)cVar1 << 1))) - fVar13 / 2.0f;

        }

        iVar8 = (int)uVar7;

        *(u32 *)(iVar8 + 0x2c) = 0x40400000;

        iVar4 = iVar2 + iVar9 * 8;

        *(u32 *)(iVar8 + 0x10) = *(u32 *)(iVar4 + 0xa00);

        *(float *)(iVar8 + 0x14) = *pfVar10;

        *(u8 *)(iVar8 + 0x18) = 0xff;

        fVar12 = *(float *)(iVar4 + 0xa00);

        if (*(float *)(iVar2 + 0x85c) < fVar12 + 8.0f) {
          if (((*(float *)(iVar2 + 0x860) < *pfVar10 + 8.0f) &&
              (fVar12 + 12.0f < *(float *)(iVar2 + 0x85c) + 126.0f)) &&
             (*pfVar10 + 12.0f < *(float *)(iVar2 + 0x860) + 126.0f)) {

            cVar3 = FUN_00433810((char)param_2,(char)param_3);

            if (cVar3 == '\0') {

              if (DAT_0095c110[(short)param_3 * 0x10 + (int)(short)param_2] == '\x01') {

                *(u8 *)(iVar8 + 0x18) = 0;

              }

            }

            else {

              uVar5 = FUN_00433810((char)param_2,(char)param_3);

              if (DAT_0095c110[uVar5 & 0xff] == '\x01') {

                *(u8 *)(iVar8 + 0x18) = 0;

              }

            }

          }

        }

        func_001127d0(uVar7,1);

        FUN_00115980(uVar7);

      }

    }

  }

  return;

}
#pragma opt_loop_invariants reset

// FUN_0042F440 NONMATCHING


void FUN_0042f440(int param_1,short param_2,short param_3,int param_4,int param_5)



{

  char cVar1;

  int iVar2;

  char cVar3;

  short sVar4;

  int iVar5;

  u32 uVar6;

  u64 uVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float fVar11;

  float fVar12;

  float fStack_a0;

  u32 uStack_9c;

  float fStack_98;

  u32 uStack_90;

  u32 uStack_8c;

  float fStack_88;

  float fStack_80;

  u32 uStack_7c;

  float fStack_78;

  float fStack_70;

  u32 uStack_6c;

  u32 uStack_68;

  float fStack_60;

  u32 uStack_5c;

  float fStack_58;

  u32 uStack_50;

  u32 uStack_4c;

  float fStack_48;

  u32 uStack_40;

  u32 uStack_3c;

  float fStack_38;

  float fStack_30;

  u32 uStack_2c;

  float fStack_28;

  YajimaVec3 mainPosX;

  YajimaVec3 savedMainX;

  

  iVar2 = *(int *)(param_1 + 0x3c);

  if (((DAT_0086e580 == 1) && (sVar4 = FUN_0044f120_y2(&DAT_0086e684), param_2 == sVar4)) &&

     (sVar4 = FUN_0044f170_y2(&DAT_0086e684), param_3 == sVar4)) {

    uVar7 = FUN_001158b0_y2(0,DAT_007ce6e4,5);

    if (*(char *)(iVar2 + 0x865) != '\0') {

      cVar3 = *(char *)(iVar2 + 0xb29);

      fStack_80 = DAT_0086e684;

      uStack_7c = DAT_0086e688;

      fStack_78 = DAT_0086e68c;

      iVar5 = FUN_0044f120_y2(&fStack_80);

      fVar10 = fStack_80 - ((float)iVar5 * 800.0f - 400.0f);

      fVar12 = (float)(int)*(char *)(iVar2 + 0xb29);

      fStack_70 = *(float *)(iVar2 + 0x868);

      uStack_6c = *(u32 *)(iVar2 + 0x86c);

      uStack_68 = *(u32 *)(iVar2 + 0x870);

      iVar5 = FUN_0044f120_y2(&fStack_70);

      fVar11 = fStack_70 - ((float)iVar5 * 800.0f - 400.0f);

      cVar1 = *(char *)(iVar2 + 0xb29);

      fVar8 = *(float *)(iVar2 + 0x85c);

      iVar5 = (int)cVar1;

      if (cVar1 < '\0') {

        iVar5 = iVar5 + 1;

      }

      fVar9 = (float)func_001126b0(uVar7);

      *(float *)(iVar2 + 0xb00) =

           ((float)(iVar5 >> 1) +

           (((fVar8 + (float)(cVar1 * param_4) +

             (float)(int)((fVar12 / 2.0f + 0.0f) - fVar11 * (fVar12 / 800.0f))) -

            (((float)(int)cVar3 / 2.0f + 0.0f) - fVar10 * ((float)(int)cVar3 / 800.0f))) -

           (float)((int)cVar1 << 1))) - fVar9 / 2.0f;

      cVar3 = *(char *)(iVar2 + 0xb29);

      fStack_a0 = DAT_0086e684;

      uStack_9c = DAT_0086e688;

      fStack_98 = DAT_0086e68c;

      iVar5 = FUN_0044f170_y2(&fStack_a0);

      fVar10 = fStack_98 - ((float)iVar5 * 800.0f - 400.0f);

      fVar12 = (float)(int)*(char *)(iVar2 + 0xb29);

      uStack_90 = *(u32 *)(iVar2 + 0x868);

      uStack_8c = *(u32 *)(iVar2 + 0x86c);

      fStack_88 = *(float *)(iVar2 + 0x870);

      iVar5 = FUN_0044f170_y2(&uStack_90);

      fVar11 = fStack_88 - ((float)iVar5 * 800.0f - 400.0f);

      cVar1 = *(char *)(iVar2 + 0xb29);

      fVar8 = *(float *)(iVar2 + 0x860);

      iVar5 = (int)cVar1;

      if (cVar1 < '\0') {

        iVar5 = iVar5 + 1;

      }

      fVar9 = (float)func_00112740(uVar7);

      *(float *)(iVar2 + 0xb04) =

           ((float)(iVar5 >> 1) +

           (((fVar8 + (float)(cVar1 * param_5) +

             (float)(int)((fVar12 / 2.0f + 0.0f) - fVar11 * (fVar12 / 800.0f))) -

            (((float)(int)cVar3 / 2.0f + 0.0f) - fVar10 * ((float)(int)cVar3 / 800.0f))) -

           (float)((int)cVar1 << 1))) - fVar9 / 2.0f;

    }

    else {

      cVar3 = *(char *)(iVar2 + 0xb29);

      fStack_30 = DAT_0086e684;

      uStack_2c = DAT_0086e688;

      fStack_28 = DAT_0086e68c;

      iVar5 = FUN_0044f120_y2(&fStack_30);

      fVar10 = fStack_30 - ((float)iVar5 * 800.0f - 400.0f);

      fVar12 = (float)(int)*(char *)(iVar2 + 0xb29);

      K_FldFrame_CtlCopyPos(&mainPosX,*(u32 *)(DAT_008717f4_y2 + 0x1e0));

      savedMainX = mainPosX;

      iVar5 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4_y2 + 0x1e0));

      fVar11 = savedMainX.x - ((float)iVar5 * 800.0f - 400.0f);

      cVar1 = *(char *)(iVar2 + 0xb29);

      fVar8 = *(float *)(iVar2 + 0x85c);

      iVar5 = (int)cVar1;

      if (cVar1 < '\0') {

        iVar5 = iVar5 + 1;

      }

      fVar9 = (float)func_001126b0(uVar7);

      *(float *)(iVar2 + 0xb00) =

           ((float)(iVar5 >> 1) +

           (((fVar8 + (float)(cVar1 * param_4) +

             (float)(int)((fVar12 / 2.0f + 0.0f) - fVar11 * (fVar12 / 800.0f))) -

            (((float)(int)cVar3 / 2.0f + 0.0f) - fVar10 * ((float)(int)cVar3 / 800.0f))) -

           (float)((int)cVar1 << 1))) - fVar9 / 2.0f;

      cVar3 = *(char *)(iVar2 + 0xb29);

      fStack_60 = DAT_0086e684;

      uStack_5c = DAT_0086e688;

      fStack_58 = DAT_0086e68c;

      iVar5 = FUN_0044f170_y2(&fStack_60);

      fVar10 = fStack_58 - ((float)iVar5 * 800.0f - 400.0f);

      fVar12 = (float)(int)*(char *)(iVar2 + 0xb29);

      K_FldFrame_CtlCopyPos(&uStack_50,*(u32 *)(DAT_008717f4_y2 + 0x1e0));

      uStack_40 = uStack_50;

      uStack_3c = uStack_4c;

      fStack_38 = fStack_48;

      iVar5 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4_y2 + 0x1e0));

      fVar11 = fStack_38 - ((float)iVar5 * 800.0f - 400.0f);

      cVar1 = *(char *)(iVar2 + 0xb29);

      fVar8 = *(float *)(iVar2 + 0x860);

      iVar5 = (int)cVar1;

      if (cVar1 < '\0') {

        iVar5 = iVar5 + 1;

      }

      fVar9 = (float)func_00112740(uVar7);

      *(float *)(iVar2 + 0xb04) =

           ((float)(iVar5 >> 1) +

           (((fVar8 + (float)(cVar1 * param_5) +

             (float)(int)((fVar12 / 2.0f + 0.0f) - fVar11 * (fVar12 / 800.0f))) -

            (((float)(int)cVar3 / 2.0f + 0.0f) - fVar10 * ((float)(int)cVar3 / 800.0f))) -

           (float)((int)cVar1 << 1))) - fVar9 / 2.0f;

    }

    iVar5 = (int)uVar7;

    *(u32 *)(iVar5 + 0x2c) = 0x40400000;

    *(u32 *)(iVar5 + 0x10) = *(u32 *)(iVar2 + 0xb00);

    *(u32 *)(iVar5 + 0x14) = *(u32 *)(iVar2 + 0xb04);

    *(u8 *)(iVar5 + 0x18) = 0xff;

    if (*(float *)(iVar2 + 0x85c) < *(float *)(iVar2 + 0xb00) + 8.0f) {

      if (((*(float *)(iVar2 + 0x860) < *(float *)(iVar2 + 0xb04) + 8.0f) &&

          (*(float *)(iVar2 + 0xb00) + 12.0f < *(float *)(iVar2 + 0x85c) + 126.0f)) &&

         (*(float *)(iVar2 + 0xb04) + 12.0f < *(float *)(iVar2 + 0x860) + 126.0f)) {

        cVar3 = FUN_00433810((char)param_2,(char)param_3);

        if (cVar3 == '\0') {

          if (DAT_0095c110[param_3 * 0x10 + (int)param_2] == '\x01') {

            *(u8 *)(iVar5 + 0x18) = 0;

          }

        }

        else {

          uVar6 = FUN_00433810((char)param_2,(char)param_3);

          if (DAT_0095c110[uVar6 & 0xff] == '\x01') {

            *(u8 *)(iVar5 + 0x18) = 0;

          }

        }

      }

    }

    func_001127d0(uVar7,1);

    FUN_00115980(uVar7);

  }

  return;

}

// FUN_0042FD80


void FUN_0042fd80(float *param_1,int param_2)



{

  u8 *fieldData;

  int iVar2;

  int iVar3;

  int scanColumn;

  int scanRow;

  u32 unaff_s5_lo;

  u32 unaff_s4_lo;

  int rowOffset;

  int columnOffset;

  int uVar5;

  int uVar4;

  YajimaVec3 position;

  

  iVar3 = *(int *)(param_2 + 0x3c);

  for (scanRow = 0; scanRow < 0x10; scanRow = scanRow + 1) {

    scanColumn = 0;

    rowOffset = scanRow * 0x100;

    for (; scanColumn < 0x10; scanColumn = scanColumn + 1) {

      columnOffset = scanColumn * 0x10;

      fieldData = (u8 *)(rowOffset + K_Field_Get());

      if (*(u8 *)(fieldData + columnOffset + 0x4a) == '\b') {

        fieldData = (u8 *)(rowOffset + K_Field_Get());

        if (*(u8 *)(fieldData + columnOffset + 0x49) == '\x01') {

          unaff_s5_lo = scanColumn;

          unaff_s4_lo = scanRow;

        }

      }

    }

  }

  *(u8 *)(iVar3 + 0xbb0) = (char)unaff_s5_lo;

  *(u8 *)(iVar3 + 0xbb1) = (char)unaff_s4_lo;

  *(float *)(iVar3 + 0xb10) = (float)(int)unaff_s5_lo * 800.0f;

  *(float *)(iVar3 + 0xb14) = (float)(int)unaff_s4_lo * 800.0f;

  for (uVar5 = unaff_s5_lo; (int)uVar5 < (int)(unaff_s5_lo + 2); uVar5 = uVar5 + 1) {

    uVar4 = unaff_s4_lo;

    iVar3 = uVar5 * 0x10;

    for (; (int)uVar4 < (int)(unaff_s4_lo + 2); uVar4 = uVar4 + 1) {

      iVar2 = uVar4 * 0x100;

      fieldData = (u8 *)(iVar3 + K_Field_Get());

      if (((*(u8 *)(fieldData + iVar2 + 0x53) & 1) != 0) &&

         (fieldData = (u8 *)(iVar3 + K_Field_Get()), *(u8 *)(fieldData + iVar2 + -0xb6) != '\b')) {

        func_001bf220(&position.x,uVar5 & 0xffff,uVar4 - 1 & 0xffff);

      }

      fieldData = (u8 *)(iVar3 + K_Field_Get());

      if (((*(u8 *)(fieldData + iVar2 + 0x53) & 2) != 0) &&

         (fieldData = (u8 *)(iVar3 + K_Field_Get()), *(u8 *)(fieldData + iVar2 + 0x3a) != '\b')) {

        func_001bf220(&position.x,uVar5 - 1 & 0xffff,uVar4 & 0xffff);

      }

      fieldData = (u8 *)(iVar3 + K_Field_Get());

      if (((*(u8 *)(fieldData + iVar2 + 0x53) & 4) != 0) &&

         (fieldData = (u8 *)(iVar3 + K_Field_Get()), *(u8 *)(fieldData + iVar2 + 0x14a) != '\b')) {

        func_001bf220(&position.x,uVar5 & 0xffff,uVar4 + 1 & 0xffff);

      }

      fieldData = (u8 *)(iVar3 + K_Field_Get());

      if (((*(u8 *)(fieldData + iVar2 + 0x53) & 8) != 0) &&

         (fieldData = (u8 *)(iVar3 + K_Field_Get()), *(u8 *)(fieldData + iVar2 + 0x5a) != '\b')) {

        func_001bf220(&position.x,uVar5 + 1 & 0xffff,uVar4 & 0xffff);

      }

    }

  }

  *(YajimaVec3 *)param_1 = position;

  return;

}



typedef int (*code)(...);
typedef u8 bool;

typedef union Vec128 { struct { u32 _0_4_; u32 _4_4_; u32 _8_4_; u32 _12_4_; }; struct { u64 _0_8_; u64 _8_8_; }; u8 _bytes[16]; } Vec128;
static inline Vec128 rwVecZero(void) { Vec128 v; v._0_8_=0; v._8_8_=0; return v; }
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
#pragma alias DAT_006b46d0_abs DAT_006b46d0
#pragma alias DAT_006b477e_abs DAT_006b477e
#pragma alias DAT_006b4784_abs DAT_006b4784
#pragma alias DAT_006b478a_abs DAT_006b478a
extern s8 DAT_006b46d0_abs[];
extern s8 DAT_006b477e_abs[];
extern s8 DAT_006b4784_abs[];
extern s8 DAT_006b478a_abs[];
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
#pragma alias DAT_006b4a78_abs DAT_006b4a78
extern u8 DAT_006b4a78_abs[];
#pragma alias DAT_006b4a90_abs DAT_006b4a90
extern u8 DAT_006b4a90_abs[];
extern u32 DAT_006b4ab0;
extern u32 DAT_006b4ab4;
extern u32 DAT_006b4ab8;
#pragma alias DAT_006b4ab0_abs DAT_006b4ab0
extern u8 DAT_006b4ab0_abs[];
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
extern float DAT_007caf94;
extern float DAT_007cafa8;
extern float DAT_007cafc0;
extern u32 DAT_007cdb10;
extern u32 DAT_007ce290;
extern u32 DAT_007ce6bc;
extern u32 DAT_007ce6c0;
extern u32 DAT_007ce6e0;
extern s8 DAT_007ce6e7;
extern u32 DAT_007ce6e8;
extern u32 DAT_007ce6f0;
extern u32 DAT_007ce6f4;
extern u32 DAT_007ce700;
extern s32 DAT_007ce704;
extern u32 DAT_007ce70c;
extern u32 DAT_007ce710;
extern u32 DAT_007ce714;
extern u32 DAT_007ce718;
extern u32 DAT_007e094e_y2;
extern u32 DAT_007e0952;
extern u32 DAT_007e0958_y2;
extern u32 DAT_007e095a;
extern u32 DAT_0086e6e8;
extern u32 DAT_0086e6f0;
extern u32 DAT_0086e6f4;
extern u32 DAT_0086e808;
extern u32 DAT_0086e810;
extern u32 DAT_0086e848;
extern u32 DAT_0086e9cc;
extern u32 DAT_0086eb8c;
extern u32 DAT_0086ed4c;
extern u32 DAT_0086ef08;
extern u32 DAT_0086ef0c;
extern u32 DAT_0086ef10;
extern u32 DAT_0086ef38;
extern u32 DAT_0086ef39;
extern u32 DAT_0086ef3a;
extern u32 DAT_0086ef3b;
extern u32 DAT_0086ef3c;
extern u32 DAT_008717e8;
#pragma alias DAT_008717e8_rows DAT_008717e8
#pragma alias DAT_008717a0_bytes DAT_008717a0
extern u8 DAT_008717a0_bytes[];
#pragma alias DAT_008717a0_rows_abs DAT_008717a0
extern u8 DAT_008717a0_rows_abs[][0x1c0];
#pragma alias DAT_008717a0_rows_check DAT_008717a0
extern u8 DAT_008717a0_rows_check[][0x1c0];
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
#pragma alias yRuntimeQueueTween FUN_0045afd0
extern u32 yRuntimeQueueTween(float duration, int stateAddress, int startX, int startY, int endX,
                              int endY, u8 delay, u8 hold, short frameCount);
#pragma alias FUN_0045afd0_call FUN_0045afd0
extern u32 FUN_0045afd0_call(float param_1,int param_2,int param_3,int param_4,int param_5,
                              int param_6,u8 param_7,u8 param_8,short param_9);
#pragma alias FUN_0045afd0_call2 FUN_0045afd0
extern u32 FUN_0045afd0_call2(int param_2,int param_3,int param_4,int param_5,int param_6,
                               u8 param_7,u8 param_8,short param_9,float param_1);
#pragma alias FUN_0045afd0_call3 FUN_0045afd0
extern u32 FUN_0045afd0_call3(int param_2,int param_3,int param_4,int param_5,int param_6,
                               float param_1,u8 param_7,u8 param_8,short param_9);
#pragma alias FUN_0045b620_call FUN_0045b620
extern void FUN_0045b620_call(float param_1,float param_2,float param_3,float param_4,
                              u32 param_5,u8 param_6,int param_7);
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
#pragma alias DAT_008717f0_abs DAT_008717f0
extern u8 DAT_008717f0_abs[];
extern u32 DAT_008717f4;
extern u32 DAT_0087193a;
extern u32 DAT_0087193b;
extern u32 DAT_0087193c;
extern u32 DAT_0087194a;
extern u32 DAT_0087194c;
extern u32 DAT_00871954;
extern u32 DAT_00871958;
extern u32 DAT_008719b0;
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
extern u32 DAT_0095c110_y2;
#pragma alias DAT_0095c110_abs DAT_0095c110_y2
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
extern f32 DAT_00960088_y2;
#pragma alias DAT_0087190c_abs DAT_0087190c
#pragma alias DAT_007e094e_abs DAT_007e094e_y2
#pragma alias DAT_007e0952_abs DAT_007e0952
#pragma alias DAT_007e0958_abs DAT_007e0958_y2
#pragma alias DAT_007e095a_abs DAT_007e095a
#pragma alias DAT_007bc730_abs DAT_007bc730
extern u8 DAT_007e094e_abs[];
extern u8 DAT_007e0952_abs[];
extern u8 DAT_007e0958_abs[];
extern u8 DAT_007e095a_abs[];
extern u8 DAT_007bc730_abs[];
#pragma alias DAT_0086e80c_abs DAT_0086e80c
extern u8 DAT_0086e80c_abs[];
#pragma alias DAT_0086e9cc_abs DAT_0086e9cc
extern u8 DAT_0086e9cc_abs[];
#pragma alias DAT_0086eb8c_abs DAT_0086eb8c
extern u8 DAT_0086eb8c_abs[];
#pragma alias DAT_0086ed4c_abs DAT_0086ed4c
extern u8 DAT_0086ed4c_abs[];
#pragma alias DAT_0086e6e8_abs DAT_0086e6e8
extern u8 DAT_0086e6e8_abs[];
#pragma alias DAT_0086e6f4_abs DAT_0086e6f4
extern u8 DAT_0086e6f4_abs[];
#pragma alias FUN_00195020_call FUN_00195020
extern void FUN_00195020_call(u32 param_1);
extern u8 DAT_0087190c_abs[];
#pragma alias DAT_0086ede8_abs DAT_0086ede8
extern u8 DAT_0086ede8_abs[];
#pragma alias DAT_0086ef0c_abs DAT_0086ef0c
#pragma alias DAT_0086ef10_abs DAT_0086ef10
extern u8 DAT_0086ef10_abs[];
#pragma alias DAT_0086ef08_abs DAT_0086ef08
extern u8 DAT_0086ef08_abs[];
extern u8 DAT_0086ef0c_abs[];
#pragma alias DAT_0086ef2c_abs DAT_0086ef2c
extern u8 DAT_0086ef2c_abs[];
#pragma alias DAT_0086ef38_abs DAT_0086ef38
extern u8 DAT_0086ef38_abs[];
#pragma alias DAT_0086ef39_abs DAT_0086ef39
extern u8 DAT_0086ef39_abs[];
#pragma alias DAT_0086ef3a_abs DAT_0086ef3a
extern u8 DAT_0086ef3a_abs[];
#pragma alias DAT_0086ef3c_abs DAT_0086ef3c
extern u8 DAT_0086ef3c_abs[];
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
#pragma alias DAT_0086e6a0_rows DAT_0086e6a0
extern u8 DAT_0086e6a0_rows[][0x1c0];
#pragma alias DAT_0086e6a0_unit_rows DAT_0086e6a0
extern YRuntimeUnitRow DAT_0086e6a0_unit_rows[];
#pragma alias DAT_006b4b20_abs DAT_006b4b20
extern u8 DAT_006b4b20_abs[];
#pragma alias DAT_006b4796_abs DAT_006b4796
extern u8 DAT_006b4796_abs[];
#pragma alias FUN_004d0f00_ptr FUN_004d0f00
extern void FUN_004d0f00_ptr(void *param_1);
#pragma alias FUN_001124b0_ptr FUN_001124b0
extern void FUN_001124b0_ptr(void *param_1);
#pragma alias FUN_00115980_ptr FUN_00115980
extern void FUN_00115980_ptr(void *param_1);
extern void FUN_00456410_noarg(void);
extern u32 FUN_00194b80_u32(u64, u32, u8 *, u32 (*)(int), void (*)(int), u32);
#pragma alias FUN_00194b80_u32arg FUN_00194b80
extern u32 FUN_00194b80_u32arg(u32, u32, u8 *, u32 (*)(int), void (*)(int), u32);
extern u32 PTR_DAT_006b46f0;
extern u32 PTR_DAT_006b4720;
extern u32 PTR_DAT_006b4de0;
extern u32 PTR_FUN_006b4e60;
#pragma alias PTR_FUN_006b4e60_abs PTR_FUN_006b4e60
extern code PTR_FUN_006b4e60_abs[];
extern u8 cGpffffb9cc;
extern f32 fGpffff8110_y2;
extern f32 fGpffff8248_y2;
extern f32 fGpffff82d8;
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
extern float uGpffff82d4;
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
extern u32 FUN_0010c1a0(int param_1, u32 param_2, int param_3, int param_4,
                        int param_5, int param_6, int param_7, int param_8,
                        int param_9, int param_10, u32 param_11, u32 param_12);
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
#pragma alias FUN_001140d0_f3 FUN_001140d0
extern void FUN_001140d0_f3(float param_1, float param_2, float param_3, u32 param_4,
                            u32 param_5, u32 param_6, u32 param_7);
extern u32 FUN_001158b0(int param_1, u32 param_2, u32 param_3);
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
#pragma alias FUN_0016c5f0_u32 FUN_0016c5f0
extern u32 FUN_0016c5f0_u32(s16 pcId);
extern code FUN_0016c920;
#pragma alias FUN_0016c920_typed FUN_0016c920
extern s16 FUN_0016c920_typed(u16 id);
extern u32 FUN_0016c970(u16 param_1);
#pragma alias FUN_0016c970_s32 FUN_0016c970
extern u32 FUN_0016c970_s32(s32 param_1);
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
extern int FUN_00173300(u16 param_1);
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
#pragma alias FUN_0017b660_i32 FUN_0017b660
extern long FUN_0017b660_i32(u16 param_1, int param_2);
#pragma alias FUN_0017b660_i32_s16 FUN_0017b660
extern long FUN_0017b660_i32_s16(s16 param_1, int param_2);
#pragma alias FUN_0017b660_1arg FUN_0017b660
extern long FUN_0017b660_1arg(u16 param_1);
#pragma alias FUN_0017b660_s16 FUN_0017b660
extern s32 FUN_0017b660_s16(s16 param_1);
#pragma alias FUN_0016c570_s16 FUN_0016c570
extern u32 FUN_0016c570_s16(s16 param_1);
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
extern u32 FUN_00194b20_u32_y2(u64, u8 *, u32, u32 (*)(int), void (*)(int), u32);
extern code FUN_00194b80;
extern code FUN_00195020;
extern long FUN_00195460(u32 param_1);
#pragma alias FUN_00195460_int FUN_00195460
extern int FUN_00195460_int(u32 param_1);
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
#pragma alias FUN_001a57a0_f32 FUN_001a57a0
extern void FUN_001a57a0_f32(u32 param_1,float param_2,float param_3);
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
#pragma alias FUN_001adff0_typed FUN_001adff0
extern void FUN_001adff0_typed(void *collisCtlTask, const void *axis, f32 angle);
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
#pragma alias FUN_001c6720_f32 FUN_001c6720
extern u32 FUN_001c6720_f32(u32 param_1,float param_2);
#pragma alias FUN_001c6720_f32first FUN_001c6720
extern u32 FUN_001c6720_f32first(float param_1,u32 param_2);
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
#pragma alias FUN_001c7160_f32_u32 FUN_001c7160
extern u32 FUN_001c7160_f32_u32(f32 param_1, void *param_2, void *param_3);
extern long FUN_001c7160(u32 param_1, void *param_2, void *param_3);
#pragma alias FUN_001c7160_i32 FUN_001c7160
extern int FUN_001c7160_i32(u32 param_1, void *param_2, void *param_3);
#pragma alias FUN_001c7270_typed FUN_001c7270
extern void *FUN_001c7270_typed(void *param_1, f32 param_2);
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
#pragma alias FUN_001d8d80_int FUN_001d8d80
extern int FUN_001d8d80_int(u32 param_1);
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
#pragma alias FUN_00421fe0_s16 FUN_00421fe0
extern float FUN_00421fe0_s16(int param_1, int param_2, int param_3, s16 param_4, int param_5);
extern float FUN_004221a0(float param_1, float param_2, float param_3, float param_4, int param_5);
extern code FUN_004222d0;
#pragma alias FUN_004222d0_typed FUN_004222d0
extern void FUN_004222d0_typed(float *param_1,char param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,short param_8);
#pragma alias FUN_004222d0_s16_counter FUN_004222d0
extern void FUN_004222d0_s16_counter(float *param_1, char param_2, int param_3, int param_4,
                 int param_5, int param_6, s16 param_7, short param_8);
extern u32 FUN_004229d0(int param_1, u64 param_2, int param_3);
extern void FUN_00422c10(u32 param_1, int param_2);
extern void FUN_00422c30(u32 param_1, u64 param_2, void *param_3);
extern void FUN_00422c90(u32 param_1, int param_2, int param_3, int param_4, int param_5);
extern code FUN_00423fe0_y2;
#pragma alias FUN_00423fe0_typed FUN_00423fe0_y2
extern void FUN_00423fe0_typed(float *param_1, char param_2, short param_3, short param_4, short param_5, short param_6);
extern code FUN_00427830_y2;
#pragma alias FUN_00427830_typed FUN_00427830_y2
extern u32 FUN_00427830_typed(float param_1,int param_2,u32 param_3,u64 param_4,u32 param_5,
                               char *param_6,char *param_7,int param_8);
extern code FUN_00427a10_y2;
#pragma alias FUN_00427a10_typed FUN_00427a10_y2
extern u32 FUN_00427a10_typed(float param_1,int param_2,u32 param_3,u64 param_4,u32 param_5,
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
extern void FUN_00427e70_typed(float param_1,u32 param_4,float param_2,float param_3,int param_5,
                               int param_6,u32 param_7);
extern code FUN_00429e80;
#pragma alias FUN_00429e80_typed FUN_00429e80
extern void FUN_00429e80_typed(int param_1, u8 param_2);
extern code FUN_004c31b0;
#pragma alias FUN_004c31b0_ym FUN_004c31b0
extern void FUN_004c31b0_ym(f32 angle, void *matrix, const void *axis, u32 mode);
extern code FUN_004c3880_y2;
#pragma alias FUN_004c3880_typed FUN_004c3880_y2
extern void FUN_004c3880_typed(u32 param_1);
extern code FUN_004c38c0_y2;
#pragma alias FUN_004c38c0_typed FUN_004c38c0_y2
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
short FUN_0043c180(char param_1);
short FUN_0043c340(char param_1);
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
u32 FUN_00433810_y2(char param_1,char param_2);
u32 FUN_004339d0(int param_1);
u32 FUN_00433de0(int param_1);
u32 FUN_00434770(int param_3,float param_1,float param_2,float *param_4);
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
u32 FUN_0045a280(u32 param_1,u32 param_2);
u32 FUN_0045af40(void);
u32 FUN_0045afd0(float param_1,int param_2,int param_3,int param_4,int param_5,int param_6, u8 param_7,u8 param_8,short param_9);
u32 FUN_0045b190(int param_1);
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
u64 FUN_00439f60(int param_1,char param_2);
u64 FUN_0043a0b0(u64 param_1,char param_2);
u32 FUN_0043c690(u32 param_1);
u32 FUN_00447e70(u64 param_1,u8 param_2,u8 param_3);
u64 FUN_0044aaf0(int param_1);
u32 FUN_0044ad20(u64 param_1,char param_2);
u32 FUN_0044e560(int param_1);
u32 FUN_004542c0(char param_1);
u64 FUN_00454620(char param_1);
u32 FUN_00455e00(u32 param_1);
u32 FUN_004560d0(u64 param_1,float param_2,float param_3,u32 param_5,u32 param_6,float param_4);
u32 FUN_004579b0(u64 param_1);
u64 FUN_00457a40(u64 param_1);
u32 FUN_00458630(u64 param_1,char param_2,u8 param_3);
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
u64 FUN_004944b0_y2(u64 param_1,u32 *param_2);
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
u64 FUN_0049c3d0_y2(u64 param_1,int param_2);
u64 FUN_0049c480_y2(u64 param_1,int param_2);
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
char FUN_0043c7f0(char param_1);
char FUN_00449c90(u64 param_1,char param_2);
char FUN_0044a420(int param_1,int param_2,int param_3);
u32 FUN_0044f060(float param_1,int param_2,float *param_3);
u32 FUN_0044f1c0(float param_1,float *param_2,float *param_3);
u8 FUN_0044fab0(int param_1);
char FUN_00453480(void);
u32 FUN_00454400(f32 *param_1,char param_2);
u32 FUN_00454520(float *param_1,char param_2);
u8 FUN_00454a70(char param_1,RwV3d param_2);
u8 FUN_00454d00(RwV3d param_1);
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
void FUN_004311f0(void *param_1,u32 param_2,u32 param_3);
void FUN_00431630(int param_1);
void FUN_004332f0(int param_1);
void FUN_004333d0(int param_1);
void FUN_004334d0(int param_1);
void FUN_004343d0(int param_1);
void FUN_004344f0(float *param_2,float param_1,int param_3,float *param_4,float *param_5);
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
void FUN_00439520(int param_1);
void FUN_0043a1a0(char param_1,u8 param_2);
void FUN_0043a2f0(int param_1);
void FUN_0043a960(int param_1);
void FUN_0043bf50(int param_1);
void FUN_0043c660(int param_1);
void FUN_0043c7a0(char param_1,u8 param_2);
void FUN_00447ad0(int param_1);
void FUN_00447f90(float *param_1,int param_2,char param_3);
void FUN_00448060(int param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6);
void FUN_00448cf0(int param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6,int param_7);
void FUN_00449d10(int param_1);
void FUN_00449d60(int param_1);
void FUN_00449ed0(void);
void FUN_00449fa0(void);
void FUN_0044a240(float param_1,float param_2,float param_3,float param_4,int param_5 ,char param_6);
void FUN_0044a330(float param_1,float param_2,float param_3,float param_4,int param_5 ,char param_6);
void FUN_0044a630(int param_1);
void FUN_0044a790(u32 *param_1);
void FUN_0044a990(int param_1,u32 *param_2);
void FUN_0044acf0(int param_1);
void FUN_0044af60(u32 param_1);
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
void FUN_0045b620(u32 param_5,float param_1,float param_2,float param_3,float param_4,u8 param_6,int param_7);
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
extern float DAT_007caf94;
extern float DAT_007cafa8;
extern float DAT_007cafc0;
extern u32 DAT_007cdb10;
extern u32 DAT_007ce290;
extern u32 DAT_007ce6bc;
extern u32 DAT_007ce6c0;
extern u32 DAT_007ce6e0;
extern u32 DAT_007ce6e8;
extern u32 DAT_007ce6f0;
extern u32 DAT_007ce6f4;
extern u32 DAT_007ce700;
extern s32 DAT_007ce704;
extern u32 DAT_007ce710;
extern u32 DAT_007ce718;
extern u32 DAT_007e094e_y2;
extern u32 DAT_007e0952;
extern u32 DAT_007e0958_y2;
extern u32 DAT_007e095a;
extern u32 DAT_0086e6e8;
extern u32 DAT_0086e6f0;
extern u32 DAT_0086e6f4;
extern u32 DAT_0086e808;
extern u32 DAT_0086e810;
extern u32 DAT_0086e848;
extern u32 DAT_0086e9cc;
extern u32 DAT_0086eb8c;
extern u32 DAT_0086ed4c;
extern u32 DAT_0086ef08;
extern u32 DAT_0086ef0c;
extern u32 DAT_0086ef10;
extern u32 DAT_0086ef38;
extern u32 DAT_0086ef39;
extern u32 DAT_0086ef3a;
extern u32 DAT_0086ef3b;
extern u32 DAT_0086ef3c;
extern u32 DAT_008717e8;
extern u32 DAT_008717f0;
extern u32 DAT_008717f4;
extern u32 DAT_0087193a;
extern u32 DAT_0087193b;
extern u32 DAT_0087193c;
extern u32 DAT_0087194a;
extern u32 DAT_0087194c;
extern u32 DAT_00871954;
extern u32 DAT_00871958;
extern u32 DAT_008719b0;
extern u32 DAT_0095c0e4;
extern u32 DAT_0095c0e8;
extern u32 DAT_0095c0ec;
extern u32 DAT_0095c0f0;
extern u32 DAT_0095c0f4;
extern u32 DAT_0095c0f8;
extern u32 DAT_0095c0fc;
extern u32 DAT_0095c100;
extern u32 DAT_0095c110_y2;
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
extern f32 DAT_00960088_y2;
extern u32 PTR_DAT_006b46f0;
extern u32 PTR_DAT_006b4720;
extern u32 PTR_DAT_006b4de0;
extern u32 PTR_FUN_006b4e60;
extern u8 cGpffffb9cc;
extern f32 fGpffff8110_y2;
extern f32 fGpffff8248_y2;
extern f32 fGpffff82d8;
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
extern float uGpffff82d4;
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
extern code FUN_00423fe0_y2;
extern code FUN_00427830_y2;
extern code FUN_00427a10_y2;
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
extern code FUN_004c2f30_y2;
extern code FUN_004c31b0;
extern code FUN_004c32a0_y2;
extern code FUN_004c33d0;
extern code FUN_004c35d0_y2;
extern code FUN_004c3880_y2;
extern code FUN_004c38c0_y2;
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
extern code FUN_004c6c60_y2;
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
extern code FUN_004cb7f0_y2;
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
extern code FUN_004f1ed0_y2;
extern code FUN_004f1f80_y2;
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
short FUN_0043c180(char param_1);
short FUN_0043c340(char param_1);
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
u32 FUN_00433810_y2(char param_1,char param_2);
u32 FUN_004339d0(int param_1);
u32 FUN_00433de0(int param_1);
u32 FUN_00434770(int param_3,float param_1,float param_2,float *param_4);
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
u32 FUN_0045a280(u32 param_1,u32 param_2);
u32 FUN_0045af40(void);
u32 FUN_0045afd0(float param_1,int param_2,int param_3,int param_4,int param_5,int param_6, u8 param_7,u8 param_8,short param_9);
u32 FUN_0045b190(int param_1);
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
u64 FUN_00439f60(int param_1,char param_2);
u64 FUN_0043a0b0(u64 param_1,char param_2);
u32 FUN_00447e70(u64 param_1,u8 param_2,u8 param_3);
u64 FUN_0044aaf0(int param_1);
u64 FUN_0044aaf0(int param_1);
u32 FUN_0044ad20(u64 param_1,char param_2);
u32 FUN_0044e560(int param_1);
u32 FUN_004542c0(char param_1);
u32 FUN_00455e00(u32 param_1);
u32 FUN_00455e00(u32 param_1);
u32 FUN_004560d0(u64 param_1,float param_2,float param_3,u32 param_5,u32 param_6,float param_4);
u64 FUN_00457a40(u64 param_1);
u64 FUN_00457a40(u64 param_1);
u32 FUN_00458630(u64 param_1,char param_2,u8 param_3);
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
u64 FUN_004944b0_y2(u64 param_1,u32 *param_2);
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
u64 FUN_0049c3d0_y2(u64 param_1,int param_2);
u64 FUN_0049c480_y2(u64 param_1,int param_2);
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
char FUN_0043c7f0(char param_1);
char FUN_00449c90(u64 param_1,char param_2);
char FUN_0044a420(int param_1,int param_2,int param_3);
u32 FUN_0044f060(float param_1,int param_2,float *param_3);
u32 FUN_0044f1c0(float param_1,float *param_2,float *param_3);
u8 FUN_0044fab0(int param_1);
char FUN_00453480(void);
u32 FUN_00454400(f32 *param_1,char param_2);
u32 FUN_00454520(float *param_1,char param_2);
u8 FUN_00454a70(char param_1,RwV3d param_2);
u8 FUN_00454d00(RwV3d param_1);
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
void FUN_004311f0(void *param_1,u32 param_2,u32 param_3);
void FUN_00431630(int param_1);
void FUN_004332f0(int param_1);
void FUN_004333d0(int param_1);
void FUN_004334d0(int param_1);
void FUN_004343d0(int param_1);
void FUN_004344f0(float *param_2,float param_1,int param_3,float *param_4,float *param_5);
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
void FUN_00439520(int param_1);
void FUN_0043a1a0(char param_1,u8 param_2);
void FUN_0043a2f0(int param_1);
void FUN_0043a960(int param_1);
void FUN_0043bf50(int param_1);
void FUN_0043c660(int param_1);
void FUN_0043c7a0(char param_1,u8 param_2);
void FUN_00447ad0(int param_1);
void FUN_00447f90(float *param_1,int param_2,char param_3);
void FUN_00448060(int param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6);
void FUN_00448cf0(int param_1,u8 param_2,u64 param_3,char param_4,short param_5, char param_6,int param_7);
void FUN_00449d10(int param_1);
void FUN_00449d60(int param_1);
void FUN_00449ed0(void);
void FUN_00449fa0(void);
void FUN_0044a240(float param_1,float param_2,float param_3,float param_4,int param_5 ,char param_6);
void FUN_0044a330(float param_1,float param_2,float param_3,float param_4,int param_5 ,char param_6);
void FUN_0044a630(int param_1);
void FUN_0044a790(u32 *param_1);
void FUN_0044a990(int param_1,u32 *param_2);
void FUN_0044acf0(int param_1);
void FUN_0044af60(u32 param_1);
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
void FUN_0045b620(u32 param_5,float param_1,float param_2,float param_3,float param_4,u8 param_6,int param_7);
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
  uVar2 = FUN_00194b20_u32_y2(param_1,DAT_006b44f0,0x18a7,
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

/* W212: first divergence is offset 216 after an exact prefix; the residual begins with
 * retail retaining the divided float in $f2 while this build puts it in $f0.  The
 * FUN_0045b620 template shares calls but not this straight-line float lifetime shape. */
#pragma push
/* W373 singles base 345/684; loop 345/684; common 496/744; life 345/684; propagation 441/656; strength 345/684; dead 324/680. */
#pragma opt_dead_assignments off
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
#pragma opt_dead_assignments reset

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

#pragma opt_loop_invariants off
// FUN_00430BB0

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
      *(u32 *)(pcVar2 + 4) = uVar3;
      *(float *)(pcVar2 + 0x5c) = *(float *)(pcVar2 + 0x14);
      *(float *)(pcVar2 + 0x60) = *(float *)(pcVar2 + 0x18) - 76.0f;
      *(u32 *)(pcVar2 + 0x24) = 0xd3;
      *(u32 *)(pcVar2 + 0x28) = 0x4c;
      FUN_00422c30(*(u32 *)(pcVar2 + 4),*(u64 *)(pcVar2 + 0x5c),pcVar2 + 0x1c);
      FUN_00422c90(*(u32 *)(pcVar2 + 4),0,0,0,0);
      FUN_00422c10(*(u32 *)(pcVar2 + 4),1);
      uVar3 = FUN_004229d0(param_1,*(u64 *)(pcVar2 + 0x14),3);
      *(u32 *)(pcVar2 + 8) = uVar3;
      *(float *)(pcVar2 + 100) = *(float *)(pcVar2 + 0x14) - 76.0f;
      *(float *)(pcVar2 + 0x68) = *(float *)(pcVar2 + 0x18) - 76.0f;
      *(u32 *)(pcVar2 + 0x34) = 0x4c;
      *(u32 *)(pcVar2 + 0x38) = 0xca;
      FUN_00422c30(*(u32 *)(pcVar2 + 8),*(u64 *)(pcVar2 + 100),pcVar2 + 0x2c);
      FUN_00422c90(*(u32 *)(pcVar2 + 8),0,0,0,0);
      FUN_00422c10(*(u32 *)(pcVar2 + 8),1);
      uVar3 = FUN_004229d0(param_1,*(u64 *)(pcVar2 + 0x14),3);
      *(u32 *)(pcVar2 + 0xc) = uVar3;
      *(float *)(pcVar2 + 0x6c) = *(float *)(pcVar2 + 0x14) - 76.0f;
      *(float *)(pcVar2 + 0x70) = *(float *)(pcVar2 + 0x18) + 126.0f;
      *(u32 *)(pcVar2 + 0x44) = 0xca;
      *(u32 *)(pcVar2 + 0x48) = 0x4c;
      FUN_00422c30(*(u32 *)(pcVar2 + 0xc),*(u64 *)(pcVar2 + 0x6c),pcVar2 + 0x3c);
      FUN_00422c90(*(u32 *)(pcVar2 + 0xc),0,0,0,0);
      FUN_00422c10(*(u32 *)(pcVar2 + 0xc),1);
      uVar3 = FUN_004229d0(param_1,*(u64 *)(pcVar2 + 0x14),3);
      *(u32 *)(pcVar2 + 0x10) = uVar3;
      *(float *)(pcVar2 + 0x74) = *(float *)(pcVar2 + 0x14) + 126.0f;
      *(float *)(pcVar2 + 0x78) = *(float *)(pcVar2 + 0x18);
      *(u32 *)(pcVar2 + 0x54) = 0x55;
      *(u32 *)(pcVar2 + 0x58) = 0xca;
      FUN_00422c30(*(u32 *)(pcVar2 + 0x10),*(u64 *)(pcVar2 + 0x74),pcVar2 + 0x4c);
      FUN_00422c90(*(u32 *)(pcVar2 + 0x10),0,0,0,0);
      FUN_00422c10(*(u32 *)(pcVar2 + 0x10),1);
    }
    else {
      uVar3 = FUN_004229d0(param_1,*(u64 *)(pcVar2 + 0x14),3);
      *(u32 *)(pcVar2 + 4) = uVar3;
      *(float *)(pcVar2 + 0x5c) = *(float *)(pcVar2 + 0x14);
      *(u32 *)(pcVar2 + 0x60) = 0;
      *(u32 *)(pcVar2 + 0x24) = 0x140;
      *(u32 *)(pcVar2 + 0x28) = (s32)*(float *)(pcVar2 + 0x18);
      FUN_00422c30(*(u32 *)(pcVar2 + 4),*(u64 *)(pcVar2 + 0x5c),pcVar2 + 0x1c);
      FUN_00422c90(*(u32 *)(pcVar2 + 4),0,0,0,0);
      FUN_00422c10(*(u32 *)(pcVar2 + 4),1);
      uVar3 = FUN_004229d0(param_1,*(u64 *)(pcVar2 + 0x14),3);
      *(u32 *)(pcVar2 + 8) = uVar3;
      *(float *)(pcVar2 + 100) = *(float *)(pcVar2 + 0x14) - 76.0f;
      *(u32 *)(pcVar2 + 0x68) = 0;
      *(u32 *)(pcVar2 + 0x34) = 0x4c;
      *(u32 *)(pcVar2 + 0x38) = (s32)(*(float *)(pcVar2 + 0x18) + 126.0f);
      FUN_00422c30(*(u32 *)(pcVar2 + 8),*(u64 *)(pcVar2 + 100),pcVar2 + 0x2c);
      FUN_00422c90(*(u32 *)(pcVar2 + 8),0,0,0,0);
      FUN_00422c10(*(u32 *)(pcVar2 + 8),1);
      uVar3 = FUN_004229d0(param_1,*(u64 *)(pcVar2 + 0x14),3);
      *(u32 *)(pcVar2 + 0xc) = uVar3;
      *(float *)(pcVar2 + 0x6c) = *(float *)(pcVar2 + 0x14) - 76.0f;
      *(float *)(pcVar2 + 0x70) = *(float *)(pcVar2 + 0x18) + 126.0f;
      *(u32 *)(pcVar2 + 0x44) = 0xca;
      *(u32 *)(pcVar2 + 0x48) = 0x4c;
      FUN_00422c30(*(u32 *)(pcVar2 + 0xc),*(u64 *)(pcVar2 + 0x6c),pcVar2 + 0x3c);
      FUN_00422c90(*(u32 *)(pcVar2 + 0xc),0,0,0,0);
      FUN_00422c10(*(u32 *)(pcVar2 + 0xc),1);
      uVar3 = FUN_004229d0(param_1,*(u64 *)(pcVar2 + 0x14),3);
      *(u32 *)(pcVar2 + 0x10) = uVar3;
      *(float *)(pcVar2 + 0x74) = *(float *)(pcVar2 + 0x14) + 126.0f;
      *(float *)(pcVar2 + 0x78) = *(float *)(pcVar2 + 0x18);
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

// FUN_00431110

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
    uVar2 = FUN_00194b20_u32_y2(param_1,DAT_006b45e0,0x18a6,(u32 (*)(int))FUN_00430bb0,FUN_004310e0,lVar1);
    puVar4 = (u8 *)lVar1;
    *puVar4 = 0;
    *(YajimaVec2 *)(puVar4 + 0x14) = param_2;
    puVar4[0x7c] = param_3 / 2;
    puVar4[0x7d] = param_4;
  }
  return uVar2;
}

// FUN_004311F0

void FUN_004311f0(void *param_1,u32 param_2,u32 param_3)

{
  YVec3f vector;
  
  vector.y = 0.0f;
  vector.x = 800.0f * (float)param_2;
  vector.z = 800.0f * (float)param_3;
  *(YVec3f *)param_1 = vector;
}

#pragma pop
// W418 YMisc3 negative: nested-chain-to-switch probe (labels 0,1,2,5,6) moved nd569/object840 to nd580/object848 (window896); rejected.
// FUN_004312B0 NONMATCHING

u64 FUN_004312b0(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  u8 uVar4;
  u8 uVar5;
  short sVar6;
  int lVar7;
  u8 bVar8;
  YVec3f vector;
  
  iVar2 = *(int *)((int)param_1 + 0x3c);
  bVar8 = 0;
  iVar3 = *(int *)(iVar2 + 4);
  if ((*(u32 *)(DAT_008717e8_abs + iVar3 * 0x70) != 0) &&
      (*(u32 *)(DAT_008717f4_abs + iVar3 * 0x70) != 0)) {
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
          if (cGpffffb9cc != '\0') {
            FUN_0043c7a0(*(u8 *)(iVar2 + 4),2);
          }
          else {
            FUN_0043c7a0(*(u8 *)(iVar2 + 4),1);
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
        FUN_004311f0(&vector,uVar4,uVar5);
        *(YVec3f *)(iVar2 + 0xd0) = vector;
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
    uVar1 = FUN_003b5d10_eb90((u16)((u32)param_2 & 0x3ff | 0x400));
    *(u32 *)(puVar6 + 0xc) = uVar1;
    *puVar6 = 0;
    puVar6[0x1223] = 0;
    puVar6[0x1220] = 0;
    puVar6[1] = 0;
    *(int *)(puVar6 + 4) = (int)param_2;
    *(u32 *)(puVar6 + 0x24) = param_3;
    if (param_2 == 3) {
      puVar6[0x101] = 2;
    }
    else if (param_2 == 2) {
      puVar6[0x101] = 1;
    }
    else if (param_2 == 1) {
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

// FUN_00431880




u32 FUN_00431880(int param_1)

{
  typedef struct {
    u8 pad00[4];
    s32 mode;
    u8 pad08[0xc8];
    RwV3d position;
    s8 mapX;
    s8 mapY;
    u8 padDe[0x1a];
    u8 savedX;
    u8 savedY;
    u8 padFa[0xf];
    u8 counters[0x100];
  } YRuntimeMapWork;
  YRuntimeMapWork *work;
  int cVar1;
  int cVar2;
  u8 uVar4;
  int iVar5;
  
  work = *(YRuntimeMapWork **)(param_1 + 0x3c);
  uVar4 = FUN_0044f120(work->position);
  work->mapX = uVar4;
  uVar4 = FUN_0044f170(work->position);
  work->mapY = uVar4;
  work->savedX = work->mapX;
  work->savedY = work->mapY;
  work->counters[work->mapY * 0x10 + work->mapX]++;
  if (work->mode != 2) {
    cVar1 = work->mapY;
    cVar2 = work->mapX;
    uVar4 = work->counters[work->mapY * 0x10 + work->mapX];
    if (uVar4 % 5 == 0) {
      iVar5 = FUN_001b9120_u32();
      if (*(u8 *)(iVar5 + cVar1 * 0x100 + cVar2 * 0x10 + 0x4a) == 3) {
        return 1;
      }
    }
    if (work->counters[cVar1 * 0x10 + cVar2] % 9 != 0) {
      goto ret0;
    }
    iVar5 = FUN_001b9120_u32();
    if (*(u8 *)(iVar5 + work->mapY * 0x100 + work->mapX * 0x10 + 0x4a) != 1) {
      goto ret0;
    }
    return 1;
  }
  else {
    cVar1 = work->mapY;
    cVar2 = work->mapX;
    uVar4 = work->counters[work->mapY * 0x10 + work->mapX];
    if (uVar4 % 3 == 0) {
      iVar5 = FUN_001b9120_u32();
      if (*(u8 *)(iVar5 + cVar1 * 0x100 + cVar2 * 0x10 + 0x4a) == 3) {
        return 1;
      }
    }
    if (work->counters[cVar1 * 0x10 + cVar2] % 4 != 0) {
      goto ret0;
    }
    iVar5 = FUN_001b9120_u32();
    if (*(u8 *)(iVar5 + work->mapY * 0x100 + work->mapX * 0x10 + 0x4a) != 1) {
      goto ret0;
    }
    return 1;
  }
ret0:
  return 0;
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

#pragma push
#pragma opt_common_subs off
// FUN_00433160

u32 FUN_00433160(int param_1)
{
  u8 *work = *(u8 **)(param_1 + 0x3c);
  u32 result = 0;
  int row = *(s8 *)(work + 0xdd);
  int column = *(s8 *)(work + 0xdc);
  if ((work[column + row * 0x10 + 0x10a] == 0) &&
      ((*((u8 *)FUN_001b9120_u32() + row * 0x100 + column * 0x10 + 0x53) & 8) != 0)) {
    result = 4;
  }
  else {
    if (work[column + row * 0x10 + 0x108] == 0) {
      row = *(s8 *)(work + 0xdd);
      column = *(s8 *)(work + 0xdc);
      if ((*((u8 *)FUN_001b9120_u32() + row * 0x100 + column * 0x10 + 0x53) & 2) != 0) {
        result = 2;
        goto done;
      }
    }
    if (work[column + row * 0x10 + 0xf9] == 0) {
      row = *(s8 *)(work + 0xdd);
      column = *(s8 *)(work + 0xdc);
      if ((*((u8 *)FUN_001b9120_u32() + row * 0x100 + column * 0x10 + 0x53) & 1) != 0) {
        result = 1;
        goto done;
      }
    }
    if ((work[column + row * 0x10 + 0x119] == 0) &&
        ((*((u8 *)FUN_001b9120_u32() + *(s8 *)(work + 0xdd) * 0x100 +
                  *(s8 *)(work + 0xdc) * 0x10 + 0x53) & 4) != 0)) {
      result = 3;
    }
  }
done:
  return result;
}
#pragma pop

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

// FUN_00433810_y2

u32 FUN_00433810_y2(char param_1,char param_2)

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

typedef struct {
  s16 x;
  s16 y;
  s16 previousX;
  s16 previousY;
} YRuntimePathNode;

typedef struct {
  u8 state;
  u8 pad_001[0xf7];
  u8 x;
  u8 y;
  u8 pad_0fa[9];
  u8 targetX;
  u8 targetY;
  u8 pad_105[0x107];
  s32 openCount;
  YRuntimePathNode nodes[256];
  u32 openNodes[256];
} YRuntimePathWork;

// FUN_00433DE0 NONMATCHING

u32 FUN_00433de0(int param_1)
{
  YRuntimePathWork *work;
  YRuntimePathNode *node;
  YRuntimePathNode *target;
  u8 currentX;
  u8 currentY;
  u8 targetIndex;
  u8 index;
  int field;

  work = *(YRuntimePathWork **)(param_1 + 0x3c);
  targetIndex = work->targetX + work->targetY * 16;
  if (work->x == 0) {
    if (work->y == 0) {
      work->state = 0x20;
      return 1;
    }
  }

  currentY = work->y;
  currentX = work->x;
  field = FUN_001b9120_u32();
  if ((*(u8 *)(field + (u32)currentY * 0x100 + (u32)currentX * 0x10 + 0x53) & 1) != 0) {
    index = currentX + (currentY - 1) * 16;
    node = &work->nodes[index];
    if ((node->x == 0) && (node->y == 0)) {
      node->x = currentX;
      node->y = currentY - 1;
      node->previousX = work->x;
      node->previousY = work->y;
      work->openNodes[work->openCount] = index;
      work->openCount++;
      if ((node->x == work->targetX) && (node->y == work->targetY)) {
        target = &work->nodes[targetIndex];
        target->x = work->targetX;
        target->y = work->targetY;
        target->previousX = work->targetX;
        target->previousY = work->targetY + 1;
        return 2;
      }
    }
  }

  currentY = work->y;
  currentX = work->x;
  field = FUN_001b9120_u32();
  if ((*(u8 *)(field + (u32)currentY * 0x100 + (u32)currentX * 0x10 + 0x53) & 2) != 0) {
    if ((work->nodes[(currentX - 1) + (u32)currentY * 16].x == 0) &&
        (work->nodes[(currentX - 1) + (u32)currentY * 16].y == 0)) {
      work->nodes[(work->x - 1) + (u32)work->y * 16].x = work->x - 1;
      work->nodes[(work->x - 1) + (u32)work->y * 16].y = work->y;
      work->nodes[(work->x - 1) + (u32)work->y * 16].previousX = work->x;
      work->nodes[(work->x - 1) + (u32)work->y * 16].previousY = work->y;
      work->openNodes[work->openCount] = (work->x - 1) + (u32)work->y * 16;
      work->openCount++;
      if ((work->nodes[(work->x - 1) + (u32)work->y * 16].x == work->targetX) &&
          (work->nodes[(work->x - 1) + (u32)work->y * 16].y == work->targetY)) {
        target = &work->nodes[targetIndex];
        target->x = work->targetX;
        target->y = work->targetY;
        target->previousX = work->targetX + 1;
        target->previousY = work->targetY;
        return 2;
      }
    }
  }

  currentY = work->y;
  currentX = work->x;
  field = FUN_001b9120_u32();
  if ((*(u8 *)(field + (u32)currentY * 0x100 + (u32)currentX * 0x10 + 0x53) & 8) != 0) {
    if ((work->nodes[currentX + 1 + (u32)currentY * 16].x == 0) &&
        (work->nodes[currentX + 1 + (u32)currentY * 16].y == 0)) {
      work->nodes[work->x + 1 + (u32)work->y * 16].x = work->x + 1;
      work->nodes[work->x + 1 + (u32)work->y * 16].y = work->y;
      work->nodes[work->x + 1 + (u32)work->y * 16].previousX = work->x;
      work->nodes[work->x + 1 + (u32)work->y * 16].previousY = work->y;
      work->openNodes[work->openCount] = work->x + 1 + (u32)work->y * 16;
      work->openCount++;
      if ((work->nodes[work->x + 1 + (u32)work->y * 16].x == work->targetX) &&
          (work->nodes[work->x + 1 + (u32)work->y * 16].y == work->targetY)) {
        target = &work->nodes[targetIndex];
        target->x = work->targetX;
        target->y = work->targetY;
        target->previousX = work->targetX - 1;
        target->previousY = work->targetY;
        return 2;
      }
    }
  }

  currentY = work->y;
  currentX = work->x;
  field = FUN_001b9120_u32();
  if ((*(u8 *)(field + (u32)currentY * 0x100 + (u32)currentX * 0x10 + 0x53) & 4) != 0) {
    index = (u32)currentX + (currentY + 1) * 16;
    node = &work->nodes[index];
    if ((node->x == 0) && (node->y == 0)) {
      node->x = currentX;
      node->y = currentY + 1;
      node->previousX = work->x;
      node->previousY = work->y;
      work->openNodes[work->openCount] = index;
      work->openCount++;
      if ((node->x == work->targetX) && (node->y == work->targetY)) {
        target = &work->nodes[targetIndex];
        target->x = work->targetX;
        target->y = work->targetY;
        target->previousX = work->targetX;
        target->previousY = work->targetY - 1;
        return 2;
      }
    }
  }
  return 0;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_004343D0

void FUN_004343d0(int param_1)

{
  int uVar2;
  int uVar3;
  int iVar4;
  int bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar4 = *(int *)(param_1 + 0x3c);
  bVar5 = 0;
  iVar6 = 0;
  *(u32 *)(iVar4 + 0x20c) = 0;
  for (iVar8 = 0; iVar8 < 0x100; iVar8 = iVar8 + 1) {
    iVar7 = iVar4 + iVar8 * 4;
    *(u16 *)(iVar7 + 0xe10) = 0;
    *(u16 *)(iVar7 + 0xe12) = 0;
  }
  uVar2 = *(u8 *)(iVar4 + 0x103);
  uVar3 = *(u8 *)(iVar4 + 0x104);
  iVar8 = *(int *)(iVar4 + 0x20c) * 4;
  *(u16 *)(iVar8 + iVar4 + 0xe10) = (u16)uVar2;
  iVar8 = *(int *)(iVar4 + 0x20c) * 4;
  *(u16 *)(iVar8 + iVar4 + 0xe12) = (u16)uVar3;
  do {
    iVar9 = iVar4 + *(int *)(iVar4 + 0x20c) * 4;
    iVar7 = (int)*(s16 *)(iVar9 + 0xe12) * 0x10;
    iVar8 = iVar4 + ((int)*(s16 *)(iVar9 + 0xe10) + iVar7) * 8;
    uVar2 = *(s16 *)(iVar8 + 0x214);
    uVar3 = *(s16 *)(iVar8 + 0x216);
    *(int *)(iVar4 + 0x20c) = *(int *)(iVar4 + 0x20c) + 1;
    if ((uVar2 == *(u8 *)(iVar4 + 0x105)) && (uVar3 == *(u8 *)(iVar4 + 0x106))) {
      bVar5 = 1;
    }
    else {
      iVar8 = iVar4 + (uVar2 + uVar3 * 0x10) * 8;
      *(u16 *)(iVar4 + *(int *)(iVar4 + 0x20c) * 4 + 0xe10) = *(s16 *)(iVar8 + 0x210);
      *(u16 *)(iVar4 + *(int *)(iVar4 + 0x20c) * 4 + 0xe12) = *(s16 *)(iVar8 + 0x212);
    }
    iVar6 = iVar6 + 1;
    iVar7 = iVar6 < 100;
    if (iVar7 == 0) {
      bVar5 = 1;
    }
  } while (bVar5 == 0);
  return;
}

#pragma pop
// FUN_004344F0

void FUN_004344f0(float *param_2,float param_1,int param_3,float *param_4,float *param_5)

{
  char cVar1;
  int iVar2;
  float fVar3;
  float fVar5;
  u64 uVar4;
  YVec3f start;
  YVec3f end;
  YVec3f delta;
  YVec3f radial;
  YVec3f point;
  YVec3f axis;

  start = *(YVec3f *)param_4;
  end = *(YVec3f *)param_5;
  iVar2 = *(int *)(param_3 + 0x3c);
  uVar4 = *(volatile u64 *)DAT_006b4608_abs;
  fVar5 = *(volatile float *)DAT_006b4610_abs;
  *(u64 *)&axis = uVar4;
  axis.z = fVar5;
  delta.x = start.x - end.x;
  delta.y = start.y - end.y;
  delta.z = start.z - end.z;
  fVar3 = FUN_004c69f0(&delta.x,&delta.x) - param_1;
  point.x = delta.x * fVar3;
  point.y = delta.y * fVar3;
  point.z = delta.z * fVar3;
  point.x = start.x - point.x;
  point.z = start.z - point.z;
  radial.x = start.x - point.x;
  radial.y = start.y - point.y;
  radial.z = start.z - point.z;
  FUN_004c69f0(&radial.x,&radial.x);
  delta.x = radial.y * axis.z - radial.z * axis.y;
  delta.y = radial.z * axis.x - radial.x * axis.z;
  delta.z = radial.x * axis.y - radial.y * axis.x;
  cVar1 = *(&DAT_007ce6e7 + *(int *)(iVar2 + 4));
  switch (cVar1) {
  case '\x01':
    radial.x = delta.x * 20.0f;
    radial.y = delta.y * 20.0f;
    radial.z = delta.z * 20.0f;
    break;
  case '\x02':
    radial.x = delta.x * -40.0f;
    radial.y = delta.y * -40.0f;
    radial.z = delta.z * -40.0f;
    break;
  case '\x03':
    radial.x = delta.x * 60.0f;
    radial.y = delta.y * 60.0f;
    radial.z = delta.z * 60.0f;
    break;
  default:
    break;
  }
  point.x = point.x + radial.x;
  point.y = point.y + radial.y;
  point.z = point.z + radial.z;
  *(YVec3f *)param_2 = point;
  return;
}

#pragma push
/* W373 singles base 223/416; loop 223/416; common 217/416; life 223/416; propagation 223/416; strength 223/416; dead 223/416. */
#pragma opt_common_subs off
// FUN_00434770 NONMATCHING

u32 FUN_00434770(int param_3,float param_1,float param_2,float *param_4)
{
  int iVar1;
  int iVar2;
  u32 uVar3;
  float fVar4;
  float uVar5;
  YVec3f position;
  YVec3f delta;
  YVec3f result;
  
  position = *(YVec3f *)param_4;
  iVar2 = *(int *)(param_3 + 0x3c);
  uVar3 = 0;
  position.y = 0.0f;
  *(u32 *)(iVar2 + 0xe4) = 0;
  delta.x = position.x - *(float *)(iVar2 + 0xe0);
  delta.y = position.y - *(float *)(iVar2 + 0xe4);
  delta.z = position.z - *(float *)(iVar2 + 0xe8);
  fVar4 = (float)FUN_004c69f0(&delta.x,&delta.x);
  delta.y = 0.0f;
  if (!(fVar4 < param_2)) {
    FUN_004344f0(&result.x,param_1,param_3,(float *)(iVar2 + 0xe0),&position.x);
    uVar5 = FUN_001e13c0_typed();
    FUN_001afa20_typed((uVar5),(void*)(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170)),&result);
    *(YVec3f *)(iVar2 + 0xe0) = result;
  }
  else {
    iVar1 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0xc) + 0x128));
    delta.x = position.x - *(float *)(iVar1 + 0x30);
    iVar1 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0xc) + 0x128));
    delta.y = position.y - *(float *)(iVar1 + 0x34);
    iVar2 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0xc) + 0x128));
    delta.z = position.z - *(float *)(iVar2 + 0x38);
    fVar4 = (float)FUN_004c69f0(&delta.x,&delta.x);
    if (fVar4 < param_1) {
      uVar3 = 1;
    }
  }
  return uVar3;
}

#pragma pop
#pragma opt_common_subs reset
// FUN_00434920 NONMATCHING

u32 FUN_00434920(float param_1,float param_2,int param_3,float *param_4)

{
  char cVar1;
  int iVar2;
  float fVar5;
  u32 uVar6;
  float fVar7;
  float uVar8;
  float fVar9;
  YVec3f start;
  YVec3f delta;
  YVec3f result;
  u64 uVar3;
  float axisX;
  float axisY;
  
  start = *(YVec3f *)param_4;
  iVar2 = *(int *)(param_3 + 0x3c);
  uVar6 = 0;
  FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0xc) + 0x128));
  uVar3 = *(u64 *)DAT_006b4618_abs;
  delta.x = *(float *)(iVar2 + 0xe0) - start.x;
  delta.y = *(float *)(iVar2 + 0xe4) - start.y;
  fVar9 = start.y;
  fVar5 = start.z;
  delta.z = *(float *)(iVar2 + 0xe8) - start.z;
  fVar7 = (float)FUN_004c69f0((float *)&delta,(float *)&delta);
  if (param_2 <= fVar7) {
    cVar1 = *(char *)((int)(u8 *)DAT_007ce6e4 + *(int *)(iVar2 + 4) + 3);
    if (cVar1 == '\x03') {
      result.x = start.x + delta.x * param_1;
      result.y = fVar9 + delta.y * param_1;
      result.z = fVar5 + delta.z * param_1;
    }
    else {
      axisX = *(float *)&uVar3;
      axisY = *(float *)((u8 *)&uVar3 + 4);
      if (cVar1 == '\x02') {
        result.x = start.x + delta.x * 150.0f;
        result.y = fVar9 + delta.y * 150.0f;
        result.z = fVar5 + delta.z * 150.0f;
        delta.x = start.x - result.x;
        delta.y = fVar9 - result.y;
        delta.z = fVar5 - result.z;
        FUN_004c69f0((float *)&delta,(float *)&delta);
        result.x = result.x + (delta.y * *(float *)DAT_006b4620_abs - delta.z * axisY) * 80.0f;
        result.y = result.y + (delta.z * axisX - delta.x * *(float *)DAT_006b4620_abs) * 80.0f;
        result.z = result.z + (delta.x * axisY - delta.y * axisX) * 80.0f;
      }
      else if (cVar1 == '\x01') {
        result.x = start.x + delta.x * 150.0f;
        result.y = fVar9 + delta.y * 150.0f;
        result.z = fVar5 + delta.z * 150.0f;
        delta.x = start.x - result.x;
        delta.y = fVar9 - result.y;
        delta.z = fVar5 - result.z;
        FUN_004c69f0((float *)&delta,(float *)&delta);
        result.x = result.x + (delta.y * *(float *)DAT_006b4620_abs - delta.z * axisY) * -80.0f;
        result.y = result.y + (delta.z * axisX - delta.x * *(float *)DAT_006b4620_abs) * -80.0f;
        result.z = result.z + (delta.x * axisY - delta.y * axisX) * -80.0f;
      }
    }
    uVar8 = FUN_001e13c0_typed();
    FUN_001afa20_typed((uVar8),(void*)(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170)),(void*)(&result));
    *(float *)(iVar2 + 0xe0) = result.x;
    *(float *)(iVar2 + 0xe4) = result.y;
    *(float *)(iVar2 + 0xe8) = result.z;
  }
  else if (fVar7 < param_1) {
    uVar6 = 1;
  }
  return uVar6;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00434C90

void FUN_00434c90(char param_1)
{
  int iVar1;
  int iVar2;
  int iVar4;
  char cVar3;

  for (iVar2 = 1; iVar2 < 4; iVar2 = iVar2 + 1) {
    cVar3 = 0;
    for (iVar1 = 0; iVar1 < 3; iVar1 = iVar1 + 1) {
      iVar4 = ((char *)&DAT_007ce6e8)[iVar1];
      if (iVar4 == iVar2) {
        cVar3 = 1;
      }
    }
    if (cVar3 == 0) {
      ((u8 *)&DAT_007ce6e8)[(char)(param_1 - 1)] = (u8)iVar2;
      return;
    }
  }
}

#pragma pop
// FUN_00434D30

void FUN_00434d30(void)

{
  char cVar1;
  int uVar2;
  int iVar3;
  u8 *row;
  int *unit;
  u8 *clearBase;
  int clearIndex;

  for (iVar3 = 1; iVar3 < 4; iVar3 = iVar3 + 1) {
    row = DAT_008717a0_bytes + iVar3 * 0x1c0;
    unit = (int *)(row + 0x16c);
    if (*(int *)(row + 0x16c) != 0) {
      uVar2 = iVar3;
      cVar1 = FUN_0043c7f0(uVar2);
      if (cVar1 != '\x06') {
        cVar1 = FUN_0043c7f0(uVar2);
        if (cVar1 == '\x05') {
          *(u8 *)(*(int *)(*unit + 0x3c) + 0x1214) = 1;
        }
        else if (*(char *)(*(int *)(*unit + 0x3c) + 0x1222) == '\0') {
          FUN_0043c7a0(uVar2,2);
        }
      }
    }
  }
  *(u8 *)&DAT_007ce6bc = 1;
  clearIndex = 0;
  clearBase = (u8 *)&DAT_007ce6e8;
  for (; clearIndex < 3; clearIndex = clearIndex + 1) {
    clearBase[clearIndex] = 0;
  }
}
// FUN_00434E60
void FUN_00434e60(void)

{
  char cVar1;
  int uVar2;
  int iVar3;
  u8 *row;
  int *unit;

  for (iVar3 = 1; iVar3 < 4; iVar3 = iVar3 + 1) {
    row = DAT_008717a0_bytes + iVar3 * 0x1c0;
    unit = (int *)(row + 0x16c);
    if (*(int *)(row + 0x16c) != 0) {
      uVar2 = iVar3;
      cVar1 = FUN_0043c7f0(uVar2);
      if (cVar1 != '\x06') {
        cVar1 = FUN_0043c7f0(uVar2);
        if (cVar1 == '\x05') {
          *(u8 *)(*(int *)(*unit + 0x3c) + 0x1214) = 0;
        }
        else if (*(char *)(*(int *)(*unit + 0x3c) + 0x1222) == '\0') {
          FUN_0043c7a0(uVar2,1);
        }
      }
    }
  }
  *(u8 *)&DAT_007ce6bc = 0;
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
  YRuntimeUnitRow *row;
  
  for (iVar6 = 1; iVar6 < 4; iVar6 = iVar6 + 1) {
    row = &DAT_008717a0_unit_rows[iVar6];
    if ((row->unk_048 != 0) &&
        (row->unk_054 != 0) &&
        (param_1 != iVar6)) {
      iVar1 = *(int *)((u8 *)row->unit + 0x3c);
      *(char *)(iVar1 + 0x1215) = param_2;
      if (param_2 == '\x01') {
        FUN_001b0260(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x170),1);
        sVar3 = FUN_00318540_typed((void *)(*(u32 *)(iVar1 + 0xc) + 0x128),0);
        sVar4 = FUN_001ded40_typed(row->unit_id);
        if (sVar3 == sVar4) {
          uVar5 = FUN_001dde00_typed(row->unit_id);
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

#pragma opt_loop_invariants reset
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

// FUN_004352E0

#pragma push
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
// W416 measured negative: retail offsets 200 has a 0x10 extension, while ours already has matching 0x10 pairs nearby at 160/164 and 208/212; layout, not width.
// FUN_00435440 NONMATCHING

char FUN_00435440(char param_1)

{
  u32 uVar2;
  u32 uVar3;
  long lVar4;
  char cVar5;
  int iVar6;
  u8 *target;
  u8 *entry;
  cVar5 = '\0';
  target = DAT_008717a0_bytes + param_1 * 0x1c0;
  for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {
    entry = DAT_008717a0_bytes + iVar6 * 0x1c0;
    if ((*(u32 *)(entry + 0x48) != 0) && (*(u32 *)(entry + 0x54) != 0)) {
      if (iVar6 == 0) {
        uVar2 = FUN_0016c5f0_typed(1);
        uVar3 = FUN_0016c4f0(1);
        if (((long)(uVar3 & 0xffff) < (long)(short)(((uVar2 & 0xffff) * 100) / 100)) &&
           (lVar4 = FUN_001c7160_f32(500.0f,target,entry), lVar4 == 1))
        {
          cVar5 = cVar5 + '\x01';
        }
      }
      else {
        uVar2 = FUN_0016c5f0_typed(*(u16 *)((u8 *)DAT_00871948 + (char)iVar6 * 0x1c0));
        uVar3 = FUN_0043c910((char)iVar6);
        if (((long)(uVar3 & 0xffff) < (long)(short)(((uVar2 & 0xffff) * 100) / 100)) &&
           (lVar4 = FUN_001c7160_f32(500.0f,target,entry), lVar4 == 1)) {
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
  char cVar6;
  int lVar8;
  YRuntimeUnitRow *target;
  YRuntimeUnitRow *entry;
  target = &DAT_008717a0_unit_rows[(int)param_1];
  for (lVar8 = 0; lVar8 < 4; lVar8 = lVar8 + 1) {
    if (lVar8 != param_1) {
      bVar2 = 0;
      entry = &DAT_008717a0_unit_rows[lVar8];
      if ((entry->unk_048 != 0) && (entry->unk_054 != 0)) {
        bVar2 = 1;
      }
      if (bVar2) {
        if (lVar8 == 0) {
          uVar3 = FUN_0016c970(entry->unit_id);
          if ((uVar3 & 0x80) != 0) {
            iVar4 = FUN_001c7160_i32(500.0f,target,DAT_008717a0_unit_rows);
joined_r0x004357c4:
            if (iVar4 == 1) {
              return (short)lVar8;
            }
          }
        }
        else {
          cVar6 = '\0';
          sVar1 = *(short *)entry->unk_048;
          if (sVar1 == 0) {
            cVar6 = *(char *)(*(int *)((u8 *)entry->unit + 0x3c) + 1);
          }
          else if (sVar1 == 1) {
            cVar6 = *(char *)(*(int *)((u8 *)entry->unit + 0x3c) + 2);
          }
          if ((cVar6 == '\x01') &&
             (uVar3 = FUN_0016c970(entry->unit_id), (uVar3 & 0x80) != 0)) {
            iVar4 = FUN_001c7160_i32(500.0f,target,entry);
            goto joined_r0x004357c4;
          }
        }
      }
    }
  }
  return 0xffff;
}

#pragma pop
// W416 measured negative: retail offsets 232/328 have 0x18 extensions, while ours already has matching 0x18 pairs nearby; layout, not width.
// FUN_00435810 NONMATCHING

u8 FUN_00435810(void)
{
  short sVar1;
  u8 bVar2;
  u16 uVar3;
  int iVar4;
  char cVar6;
  int iVar7;
  int iVar8;
  u8 uVar9;
  u16 uVar10;
  YRuntimeUnitRow *entry;
  
  uVar10 = 0;
  uVar9 = 0xff;
  for (iVar7 = 1; iVar7 < 4; iVar7 = iVar7 + 1) {
    bVar2 = 0;
    entry = &DAT_008717a0_unit_rows[iVar7];
    if ((entry->unk_048 != 0) && (entry->unk_054 != 0)) {
      bVar2 = 1;
    }
    if (bVar2) {
      iVar4 = (int)FUN_00173380_typed(entry->unit_id);
      cVar6 = '\0';
      if (*(short *)entry->unk_048 == 0) {
        cVar6 = *(char *)(*(int *)((u8 *)entry->unit + 0x3c) + 1);
      }
      else if (*(short *)entry->unk_048 == 1) {
        cVar6 = *(char *)(*(int *)((u8 *)entry->unit + 0x3c) + 2);
      }
      if (cVar6 == '\x01') {
        for (iVar8 = 0; iVar8 < 8; iVar8 = iVar8 + 1) {
          sVar1 = *(short *)(iVar4 + iVar8 * 2);
          if (sVar1 != 0) {
            if (sVar1 == 0xca) {
              uVar3 = FUN_0016c570_typed(entry->unit_id);
              if (uVar10 < uVar3) {
                uVar9 = (char)iVar7;
                uVar10 = uVar3;
              }
            }
            else if (sVar1 == 0xcb) {
              uVar3 = FUN_0016c570_typed(entry->unit_id);
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

// FUN_004359F0

u8 FUN_004359f0(int param_1,u8 param_2,u8 param_3,u32 *param_4,
                 u8 param_5,u8 param_6)

{
  int iVar1;
  char cVar4;
  int iVar2;
  int iVar5;
  int iVar6;
  char state;
  int iVar7;
  YVec3f position;
  
  position = *(YVec3f *)param_4;
  iVar1 = *(int *)((int)param_1 + 0x3c);
  *(u8 *)(iVar1 + 0xdc) = param_2;
  *(u8 *)(iVar1 + 0xf8) = param_2;
  *(u8 *)(iVar1 + 0xdd) = param_3;
  *(u8 *)(iVar1 + 0xf9) = param_3;
  *(float *)(iVar1 + 0xd0) = position.x;
  *(float *)(iVar1 + 0xd8) = position.z;
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
  *(YVec3f *)(iVar1 + 0xe0) = position;
  state = 0;
  do {
    cVar4 = FUN_00433de0(param_1);
    iVar1 = ((u32 *)param_1)[15];
    iVar6 = *(int *)(iVar1 + 0xa10);
    *(u32 *)(iVar1 + 0x20c) = 0;
    for (iVar2 = 0; iVar2 < 0xff; iVar2 = iVar2 + 1) {
      iVar5 = iVar1 + iVar2 * 4;
      iVar7 = *(int *)(iVar5 + 0xa14);
      *(int *)(iVar5 + 0xa10) = iVar7;
      if (iVar7 != 0) {
        *(int *)(iVar1 + 0x20c) = *(int *)(iVar1 + 0x20c) + 1;
      }
    }
    iVar6 = iVar1 + iVar6 * 8;
    *(char *)(iVar1 + 0xf8) = (char)*(s16 *)(iVar6 + 0x210);
    *(char *)(iVar1 + 0xf9) = (char)*(s16 *)(iVar6 + 0x212);
    if (cVar4 == 1) {
      cVar4 = 2;
      state = 1;
    }
  } while (cVar4 != 2);
  if (state == 0) {
    FUN_004343d0(param_1);
    return 1;
  }
  return 0;
}

#pragma push
#pragma opt_loop_invariants on
// Preserve every helper-facing vector as one aggregate; the remaining normalized diff is a stack/codegen floor.
// W418 YMisc3 negative: swapping the top 0x32 branch bodies moved nd6296/object8592 to nd6306/object8592 (window8704); rejected.
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
  YRuntimeUnitRow *row;
  YRuntimeUnitRow *selfRow;
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
  selfRow = &DAT_008717a0_unit_rows[(int)cVar3];
  for (iVar19 = 1; iVar19 < 4; iVar19 = iVar19 + 1) {
    row = &DAT_008717a0_unit_rows[iVar19];
    if (iVar19 != cVar3) {
      bVar18 = 0;
      if ((row->unk_048 != 0) && (row->unk_054 != 0)) {
        bVar18 = 1;
      }
      if (((bVar18) && (cVar4 = FUN_004353f0((int)row), cVar4 == '\x06')) &&
         (lVar13 = FUN_001c7160_f32(500.0f,selfRow,row), lVar13 == 1)) {
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
        if ((DAT_008717e8_rows[iVar19 * 0x70] != 0) && (DAT_008717f4_rows[iVar19 * 0x70] != 0)) {
          bVar18 = 1;
        }
        if (((bVar18) && (cVar4 = FUN_004353f0((int)(DAT_008717a0_bytes + iVar19 * 0x1c0)), cVar4 == '\x06')) &&
           (lVar13 = FUN_001c7160_f32(500.0f,DAT_008717a0_bytes + cVar3 * 0x1c0,
                                  DAT_008717a0_bytes + iVar19 * 0x1c0), lVar13 == 1)) {
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
          if ((DAT_008717e8_rows[iVar19 * 0x70] != 0) && (DAT_008717f4_rows[iVar19 * 0x70] != 0)) {
            bVar18 = 1;
          }
          if (((bVar18) && (cVar4 = FUN_004353f0((int)(DAT_008717a0_bytes + iVar19 * 0x1c0)), cVar4 == '\x06'))
           && (lVar13 = FUN_001c7160_f32(500.0f,DAT_008717a0_bytes + cVar3 * 0x1c0,
                                       DAT_008717a0_bytes + iVar19 * 0x1c0), lVar13 == 1)) {
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
            if ((DAT_008717e8_rows[iVar19 * 0x70] != 0) && (DAT_008717f4_rows[iVar19 * 0x70] != 0)) {
              bVar18 = 1;
            }
            if (((bVar18) && (cVar4 = FUN_004353f0((int)(DAT_008717a0_bytes + iVar19 * 0x1c0)), cVar4 == '\x06')
               ) && (lVar13 = FUN_001c7160_f32(500.0f,DAT_008717a0_bytes + cVar3 * 0x1c0,
                                            DAT_008717a0_bytes + iVar19 * 0x1c0), lVar13 == 1)) {
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
              if ((DAT_008717e8_rows[iVar19 * 0x70] != 0) && (DAT_008717f4_rows[iVar19 * 0x70] != 0)) {
                bVar18 = 1;
              }
              if (((bVar18) &&
                  (cVar4 = FUN_004353f0((int)(DAT_008717a0_bytes + iVar19 * 0x1c0)), cVar4 == '\x06')) &&
                 (lVar13 = FUN_001c7160_f32(500.0f,DAT_008717a0_bytes + cVar3 * 0x1c0,
                                        DAT_008717a0_bytes + iVar19 * 0x1c0), lVar13 == 1)) {
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
            if ((DAT_008717e8_rows[iVar19 * 0x70] != 0) && (DAT_008717f4_rows[iVar19 * 0x70] != 0)) {
              bVar18 = 1;
            }
            if (((bVar18) && (cVar4 = FUN_004353f0((int)(DAT_008717a0_bytes + iVar19 * 0x1c0)), cVar4 == '\x06')
               ) && (lVar13 = FUN_001c7160_f32(500.0f,DAT_008717a0_bytes + cVar3 * 0x1c0,
                                            DAT_008717a0_bytes + iVar19 * 0x1c0), lVar13 == 1)) {
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
              if ((DAT_008717e8_rows[iVar19 * 0x70] != 0) && (DAT_008717f4_rows[iVar19 * 0x70] != 0)) {
                bVar18 = 1;
              }
              if (((bVar18) &&
                  (cVar4 = FUN_004353f0((int)(DAT_008717a0_bytes + iVar19 * 0x1c0)), cVar4 == '\x06')) &&
                   (lVar13 = FUN_001c7160_f32(500.0f,DAT_008717a0_bytes + cVar3 * 0x1c0,
                                        DAT_008717a0_bytes + iVar19 * 0x1c0), lVar13 == 1)) {
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
    if (lVar13 != 0) {
      uVar14 = FUN_00318b60(*(u32 *)(DAT_008717f0_abs + *(int *)(iVar2 + 4) * 0x1c0));
      iVar19 = FUN_00318b60(*(u32 *)DAT_008717f0_abs);
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
    else {
      lVar13 = FUN_001a0250();
      if ((lVar13 == 1) || (lVar13 = FUN_001a02c0(), lVar13 == 1)) {
        *(u8 *)(iVar2 + 0x1223) = 1;
      }
      else {
        *(u8 *)(iVar2 + 0x1223) = 0xd;
      }
    }
    if (*(char *)(iVar2 + 0x1222) == '\x01') {
      *(u8 *)(iVar2 + 0x1222) = 0;
    }
    break;
  case 7:
    *(u8 *)((int)(u8 *)DAT_007ce6e4 + *(int *)(iVar2 + 4) + 3) = 0;
    uVar20 = *(u32 *)(iVar2 + 0x24);
    iVar12 = FUN_00318b60(*(u32 *)DAT_008717f0_abs);
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
    if (lVar13 != 0) {
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
    else {
      *(u8 *)(iVar2 + 0x1223) = 1;
    }
    break;
  case 8:
    if (DAT_007ce6bc != '\x01') {
      lVar13 = FUN_0043a0b0(param_1,*(u8 *)(iVar2 + 4));
      if (lVar13 != 1) {
        lVar13 = FUN_001c7130(800.0f,*(u32 *)(iVar2 + 0x24));
        if (lVar13 != 0) {
          uVar20 = *(u32 *)(iVar2 + 0x24);
          iVar12 = FUN_00318b60(*(u32 *)DAT_008717f0_abs);
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
        else {
          *(u8 *)(iVar2 + 0x1223) = 1;
        }
      }
      else {
        FUN_0043c7a0(*(u8 *)(iVar2 + 4),5);
      }
    }
    else {
      FUN_00434d30();
    }
    break;
  case 9:
    if (DAT_007ce6bc != '\x01') {
      lVar13 = FUN_0043a0b0(param_1,*(u8 *)(iVar2 + 4));
      if (lVar13 != 1) {
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
      else {
        FUN_0043c7a0(*(u8 *)(iVar2 + 4),5);
      }
    }
    else {
      FUN_00434d30();
    }
    break;
  case 10:
    *(u8 *)((int)(u8 *)DAT_007ce6e4 + *(int *)(iVar2 + 4) + 3) = 0;
    uVar20 = *(u32 *)(iVar2 + 0x24);
    iVar12 = FUN_00318b60(*(u32 *)DAT_008717f0_abs);
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
      iVar12 = FUN_00318b60(*(u32 *)DAT_008717f0_abs);
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
      iVar12 = FUN_00318b60(*(u32 *)DAT_008717f0_abs);
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
      iVar12 = FUN_00318b60(*(u32 *)DAT_008717f0_abs);
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
      iVar12 = FUN_00318b60(*(u32 *)(DAT_008717f0_abs + (char)(cVar3 + '\x01') * 0x1c0));
      lVar13 = FUN_00434770(param_1,125.0f,200.0f,(float *)(iVar12 + 0x30));
      if (lVar13 != 0) {
        *(u8 *)(iVar2 + 0x1223) = 0xb;
      }
      cVar3 = '\0';
      for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
        if (((u8 *)DAT_007ce6e8)[iVar12] == '\x02') {
          cVar3 = (char)iVar12;
        }
      }
      iVar12 = FUN_00318b60(*(u32 *)(DAT_008717f0_abs + *(int *)(iVar2 + 4) * 0x1c0));
      iVar19 = FUN_00318b60(*(u32 *)(DAT_008717f0_abs + (char)(cVar3 + '\x01') * 0x1c0));
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
      iVar12 = FUN_00318b60(*(u32 *)(DAT_008717f0_abs + (char)(cVar3 + '\x01') * 0x1c0));
      lVar13 = FUN_00434770(param_1,125.0f,200.0f,(float *)(iVar12 + 0x30));
      if (lVar13 != 0) {
        *(u8 *)(iVar2 + 0x1223) = 0xb;
      }
      cVar3 = '\0';
      for (iVar12 = 0; iVar12 < 3; iVar12 = iVar12 + 1) {
        if (((u8 *)DAT_007ce6e8)[iVar12] == '\x01') {
          cVar3 = (char)iVar12;
        }
      }
      iVar12 = FUN_00318b60(*(u32 *)(DAT_008717f0_abs + *(int *)(iVar2 + 4) * 0x1c0));
      iVar19 = FUN_00318b60(*(u32 *)(DAT_008717f0_abs + (char)(cVar3 + '\x01') * 0x1c0));
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
      lVar13 = FUN_00434770(param_1,125.0f,200.0f,(float *)(iVar12 + 0x30));
      if (lVar13 != 0) {
        *(u8 *)(iVar2 + 0x1223) = 0xb;
      }
      iVar12 = FUN_00318b60(*(u32 *)(DAT_008717f0_abs + *(int *)(iVar2 + 4) * 0x1c0));
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
    if (lVar13 != 1) {
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
    else {
      *(u8 *)(iVar2 + 0x1223) = 3;
    }
    break;
  case 3:
    if (*(int *)(iVar2 + 0x20c) != 0) {
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
    else {
      *(u8 *)(iVar2 + 0x1223) = 5;
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
    if (lVar13 != lVar15) {
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
    else {
      lVar13 = FUN_001ad920(*(u32 *)(DAT_008717f4 + 0x1e0));
      lVar15 = FUN_001ad920(*(u32 *)(*(int *)(*(int *)(iVar2 + 0x24) + 0x54) + 0x1e0));
      if (lVar13 != lVar15) goto LAB_00437890;
      *(u8 *)(iVar2 + 0x1223) = 0;
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
      iVar19 = FUN_00318b60(*(u32 *)(DAT_008717f0_abs + *(int *)(iVar2 + 4) * 0x1c0));
      fStack_40[0] = *(float *)(iVar12 + 0x100) - *(float *)(iVar19 + 0x30);
      iVar19 = FUN_00318b60(*(u32 *)(DAT_008717f0_abs + *(int *)(iVar2 + 4) * 0x1c0));
      fStack_40[1] = *(float *)(iVar12 + 0x104) - *(float *)(iVar19 + 0x34);
      iVar19 = FUN_00318b60(*(u32 *)(DAT_008717f0_abs + *(int *)(iVar2 + 4) * 0x1c0));
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
    if (lVar13 != 1) {
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
    else {
      *(u8 *)(iVar2 + 0x1223) = 10;
    }
    break;
  case 0xf:
    lVar13 = FUN_001c7130(500.0f,*(u32 *)(iVar2 + 0x24));
    if (lVar13 != 1) {
      lVar13 = FUN_001b0220(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
      if (lVar13 == 0) {
        *(u8 *)(iVar2 + 0x1223) = 0xe;
      }
    }
    else {
      *(u8 *)(iVar2 + 0x1223) = 10;
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
// FUN_00437E80

void FUN_00437e80(u32 *param_1,char param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  u8 *row;
  YVec3f position;
  YVec3f delta;
  YVec3f best;
  
  fVar6 = 8000.0f;
  best.z = 0.0f;
  best.y = 0.0f;
  best.x = 0.0f;
  iVar3 = 0;
  iVar2 = (int)param_2;
  row = DAT_008717a0_bytes + iVar2 * 0x1c0;
  for (; iVar3 < 0x10; iVar3 = iVar3 + 1) {
    for (iVar4 = 0; iVar4 < 0x10; iVar4 = iVar4 + 1) {
      iVar1 = FUN_001b9120_u32();
      if (*((u8 *)(iVar3 * 0x10) + iVar1 + iVar4 * 0x100 + 0x4a) == 8) {
        FUN_001bf220(&position.x,iVar3,iVar4);
        iVar1 = FUN_00318b60(*(u32 *)(row + 0x50));
        delta.x = position.x - *(float *)(iVar1 + 0x30);
        iVar1 = FUN_00318b60(*(u32 *)(row + 0x50));
        delta.y = position.y - *(float *)(iVar1 + 0x34);
        iVar1 = FUN_00318b60(*(u32 *)(row + 0x50));
        delta.z = position.z - *(float *)(iVar1 + 0x38);
        fVar5 = (float)FUN_004c69f0(&delta.x,&delta.x);
        if (fVar5 < fVar6) {
          fVar6 = fVar5;
          best = position;
        }
      }
    }
  }
  *(YVec3f *)param_1 = best;
  return;
}

#pragma pop
#pragma push
#pragma opt_loop_invariants on
/* W373 singles base 3602/4976; loop 3602/4976; common 3660/5136; life 3607/4976; propagation 3576/4976; strength 3602/4976; dead 3491/4972; pair propagation+dead 3576/4976. */
#pragma opt_dead_assignments off
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
  u32 iVar10;
  u8 uVar11;
  u8 bVar12;
  char cVar13;
  int iVar14;
  int iVar15;
  YRuntimeUnitRow *row;
  YRuntimeUnitRow *selfRow;
  u32 uStack_70 [3];
  u32 uStack_60 [3];
  u8 auStack_50 [16];
  float fStack_40 [3];
  float fStack_30 [3];
  float fStack_20 [3];
  float fStack_10 [3];
  
  iVar14 = DAT_007ce290;
  iVar2 = *(int *)((int)param_1 + 0x3c);
  iVar10 = FUN_00439f60(param_1,*(u8 *)(iVar2 + 4));
  if (iVar10 == 1) {
    FUN_0043c7a0(*(u8 *)(iVar2 + 4),5);
  }
  else {
    FUN_00439400(*(u8 *)(iVar2 + 4));
    iVar10 = FUN_0016c970(*(u16 *)((u8 *)DAT_00871948 + *(int *)(iVar2 + 4) * 0x1c0));
    if (iVar10 != 0) {
      FUN_00456670(param_1,*(u8 *)(iVar2 + 4));
    }
    cVar13 = *(char *)(iVar2 + 4);
    selfRow = &DAT_008717a0_unit_rows[(int)cVar13];
    for (iVar15 = 1; iVar15 < 4; iVar15 = iVar15 + 1) {
      row = &DAT_008717a0_unit_rows[iVar15];
      if (iVar15 != cVar13) {
        bVar12 = 0;
        if ((row->unk_048 != 0) && (row->unk_054 != 0)) {
          bVar12 = 1;
        }
        if (((bVar12) && (cVar4 = FUN_004353f0((int)row), cVar4 == '\x06')) &&
           (iVar10 = FUN_001c7160(500.0f,selfRow,row), iVar10 == 1)) {
          cVar13 = (char)iVar15;
          goto LAB_004381a4;
        }
      }
    }
    cVar13 = '\0';
LAB_004381a4:
    if (cVar13 != '\0') {
      cVar13 = *(char *)(iVar2 + 4);
      selfRow = &DAT_008717a0_unit_rows[(int)cVar13];
      for (iVar15 = 1; iVar15 < 4; iVar15 = iVar15 + 1) {
        row = &DAT_008717a0_unit_rows[iVar15];
        if (iVar15 != cVar13) {
          bVar12 = 0;
          if ((row->unk_048 != 0) && (row->unk_054 != 0)) {
            bVar12 = 1;
          }
          if (((bVar12) && (cVar4 = FUN_004353f0((int)row), cVar4 == '\x06'))
             && (iVar10 = FUN_001c7160(500.0f,selfRow,row), iVar10 == 1)) {
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
        selfRow = &DAT_008717a0_unit_rows[(int)cVar13];
        for (iVar15 = 1; iVar15 < 4; iVar15 = iVar15 + 1) {
          row = &DAT_008717a0_unit_rows[iVar15];
          if (iVar15 != cVar13) {
            bVar12 = 0;
            if ((row->unk_048 != 0) && (row->unk_054 != 0)) {
              bVar12 = 1;
            }
            if (((bVar12) && (cVar4 = FUN_004353f0((int)row), cVar4 == '\x06')
                ) && (iVar10 = FUN_001c7160(500.0f,selfRow,row), iVar10 == 1)) {
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
          selfRow = &DAT_008717a0_unit_rows[(int)cVar13];
          for (iVar15 = 1; iVar15 < 4; iVar15 = iVar15 + 1) {
            row = &DAT_008717a0_unit_rows[iVar15];
            if (iVar15 != cVar13) {
              bVar12 = 0;
              if ((row->unk_048 != 0) && (row->unk_054 != 0)) {
                bVar12 = 1;
              }
              if (((bVar12) &&
                  (cVar4 = FUN_004353f0((int)row), cVar4 == '\x06')) &&
                  (iVar10 = FUN_001c7160(500.0f,selfRow,row), iVar10 == 1)) {
                uVar11 = (u8)iVar15;
                goto LAB_00438480;
              }
            }
          }
          uVar11 = 0;
LAB_00438480:
          iVar15 = *(int *)(iVar2 + 4);
          sVar5 = FUN_0043c340(uVar11);
          if (iVar15 == sVar5) {
            cVar13 = (char)iVar15;
            selfRow = &DAT_008717a0_unit_rows[(int)cVar13];
            for (iVar15 = 1; iVar15 < 4; iVar15 = iVar15 + 1) {
              row = &DAT_008717a0_unit_rows[iVar15];
              if (iVar15 != cVar13) {
                bVar12 = 0;
                if ((row->unk_048 != 0) && (row->unk_054 != 0))
                {
                  bVar12 = 1;
                }
                if (((bVar12) &&
                    (cVar4 = FUN_004353f0((int)row), cVar4 == '\x06')) &&
                   (iVar10 = FUN_001c7160(500.0f,selfRow,row), iVar10 == 1)) {
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
          selfRow = &DAT_008717a0_unit_rows[(int)cVar13];
          for (iVar15 = 1; iVar15 < 4; iVar15 = iVar15 + 1) {
            row = &DAT_008717a0_unit_rows[iVar15];
            if (iVar15 != cVar13) {
              bVar12 = 0;
              if ((row->unk_048 != 0) && (row->unk_054 != 0)) {
                bVar12 = 1;
              }
              if (((bVar12) &&
                  (cVar4 = FUN_004353f0((int)row), cVar4 == '\x06')) &&
                  (iVar10 = FUN_001c7160(500.0f,selfRow,row), iVar10 == 1)) {
                uVar11 = (u8)iVar15;
                goto LAB_00438680;
              }
            }
          }
          uVar11 = 0;
LAB_00438680:
          iVar15 = *(int *)(iVar2 + 4);
          sVar5 = FUN_0043c180(uVar11);
          if (iVar15 == sVar5) {
            cVar13 = (char)iVar15;
            selfRow = &DAT_008717a0_unit_rows[(int)cVar13];
            for (iVar15 = 1; iVar15 < 4; iVar15 = iVar15 + 1) {
              row = &DAT_008717a0_unit_rows[iVar15];
              if (iVar15 != cVar13) {
                bVar12 = 0;
                if ((row->unk_048 != 0) && (row->unk_054 != 0))
                {
                  bVar12 = 1;
                }
                if (((bVar12) &&
                    (cVar4 = FUN_004353f0((int)row), cVar4 == '\x06')) &&
                   (iVar10 = FUN_001c7160(500.0f,selfRow,row), iVar10 == 1)) {
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
        iVar14 = iVar2;
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
          iVar10 = FUN_001afa20_typed((DAT_007cafa8),(void*)(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170)),(void*)(auStack_50));
          if (iVar10 != 0) {
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
      iVar10 = FUN_001afa20_typed((DAT_007cafa8),(void*)(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170)),(void*)(iVar2 + 0xec));
      if ((iVar10 != 0) &&
         ((iVar14 = FUN_00488f30(), 9 < (short)(iVar14 % 100) ||
          (iVar10 = FUN_001aff70_typed((void *)(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170)),0x3c), iVar10 != 0)
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
      iVar10 = FUN_001b0220(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
      if (iVar10 == 0) {
        *(u8 *)(iVar2 + 0x1220) = 0;
      }
      break;
    case 6:
      iVar10 = (int)FUN_001c7270_typed((void *)*(u32 *)(iVar2 + 0x24), *(float *)(iVar14 + 0x14));
      *(int *)(iVar2 + 0x28) = iVar10;
      if (iVar10 == 0) {
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
      iVar10 = FUN_001b0220(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
      if (iVar10 == 0) {
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
      iVar10 = FUN_00195460(*(u32 *)(iVar2 + 0x2c));
      if (iVar10 == 0) {
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
// FUN_00439400

void FUN_00439400(char param_1)

{
  int iVar1;
  int bVar2;
  int iVar3;
  void *pvVar4;
  int iVar6;
  
  iVar6 = param_1 * 0x1c0;
  iVar1 = *(int *)(*(int *)(DAT_0087190c_abs + iVar6) + 0x3c);
  iVar3 = iGpffffb5a0;
  if (((*(char *)(iVar1 + 0x1222) != '\x01') &&
      (pvVar4 = FUN_001c7270_typed((void *)*(u32 *)(iVar1 + 0x24),*(float *)(iVar3 + 0x14)),
       pvVar4 != NULL)) && (((int *)pvVar4)[1] != 1)) {
    bVar2 = *(u32 *)(DAT_008717e8_abs + iVar6) != 0;
    if (bVar2) {
      bVar2 = *(u32 *)(DAT_008717f4_abs + iVar6) != 0;
    }
    if (bVar2) {
      if (FUN_001c6450_typed(
              FUN_00318b60(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x50)),
              (u8 *)pvVar4 + 0x10c,*(float *)(iVar3 + 0x10),*(float *)(iVar3 + 0x14)) == 1) {
        *(u8 *)(iVar1 + 0x1222) = 1;
        *(u8 *)(iVar1 + 0x1220) = 6;
      }
    }
  }
  return;
}

#pragma opt_dead_assignments reset
// FUN_00439520 NONMATCHING

void FUN_00439520(int param_1)

{
  int iVar1;
  u8 uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  u32 uVar6;
  u32 lVar7;
  u32 uVar8;
  u32 lVar9;
  
  iVar4 = iGpffffb5a0;
  iVar1 = *(int *)(param_1 + 0x3c);
  switch(*(u8 *)(iVar1 + 0x1218)) {
  case 0:
    lVar9 = FUN_001c6720_u32(*(u32 *)(iGpffffb5a0 + 4),*(u32 *)(iVar1 + 0x24));
    if (lVar9 != 0) {
      *(u8 *)(iVar1 + 0x1218) = 2;
    }
    else {
      FUN_001b0240(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x170),0);
      FUN_001b00c0(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x170));
      if (cGpffffb9cc == '\0') {
        lVar9 = FUN_001c6720_u32(*(u32 *)(iVar4 + 0x14),(u32)DAT_008717a0_unit_rows);
        lVar7 = FUN_001c7130(800.0f,*(u32 *)(iVar1 + 0x24));
        if (lVar7 == 0) {
          lVar9 = FUN_001c6720_u32(*(u32 *)(iVar4 + 0x14),*(u32 *)(iVar1 + 0x24));
        }
      }
      else {
        lVar9 = FUN_001c6720_u32(*(u32 *)(iVar4 + 0x14),*(u32 *)(iVar1 + 0x24));
      }
      if (lVar9 != 0) {
        RwV3d sourcePosition;
        RwV3d targetPosition;
        RwV3d delta;
        RwV3d destination;

        iVar4 = FUN_00318b60(*(u32 *)((int)lVar9 + 0x50));
        iVar5 = FUN_00318b60(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x50));
        sourcePosition = *(RwV3d *)(iVar4 + 0x30);
        targetPosition = *(RwV3d *)(iVar5 + 0x30);
        delta.x = targetPosition.x - sourcePosition.x;
        delta.y = targetPosition.y - sourcePosition.y;
        delta.z = targetPosition.z - sourcePosition.z;
        FUN_004c69f0((float *)&delta,(float *)&delta);
        destination.x = delta.x * 200.0f + sourcePosition.x;
        destination.y = delta.y * 200.0f + sourcePosition.y;
        destination.z = delta.z * 200.0f + sourcePosition.z;
        FUN_001afa20_typed(uGpffff82b8,
                           (void *)(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x170)),
                           &destination);
        *(u8 *)(iVar1 + 0x1218) = 1;
      }
      else {
        if (*(char *)(iVar1 + 0x1214) == '\x01') {
          FUN_0043c7a0(*(u8 *)(iVar1 + 4),2);
        }
        else if (*(char *)(iVar1 + 0x1214) == '\0') {
          FUN_0043c7a0(*(u8 *)(iVar1 + 4),1);
        }
      }
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
    lVar9 = FUN_001c6720_u32(*(u32 *)(iVar4 + 0x14),*(u32 *)(iVar1 + 0x24));
    if (lVar9 == 0) {
      *(u8 *)(iVar1 + 0x1218) = 4;
    }
    else {
      lVar7 = FUN_001c6720_u32(*(u32 *)(iVar4 + 4),*(u32 *)(iVar1 + 0x24));
      if (lVar7 == 0) {
        RwV3d sourcePosition;
        RwV3d targetPosition;
        RwV3d delta;
        RwV3d destination;

        iVar4 = FUN_001c6720_u32(*(u32 *)(iVar4 + 0x14),*(u32 *)(iVar1 + 0x24));
        iVar4 = FUN_00318b60(*(u32 *)(iVar4 + 0x50));
        iVar5 = FUN_00318b60(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x50));
        sourcePosition = *(RwV3d *)(iVar4 + 0x30);
        targetPosition = *(RwV3d *)(iVar5 + 0x30);
        delta.x = targetPosition.x - sourcePosition.x;
        delta.y = targetPosition.y - sourcePosition.y;
        delta.z = targetPosition.z - sourcePosition.z;
        FUN_004c69f0((float *)&delta,(float *)&delta);
        destination.x = delta.x * 200.0f + sourcePosition.x;
        destination.y = delta.y * 200.0f + sourcePosition.y;
        destination.z = delta.z * 200.0f + sourcePosition.z;
        FUN_001afa20_typed(uGpffff82b8,
                           (void *)(*(u32 *)(*(int *)(iVar1 + 0x24) + 0x170)),
                           &destination);
        *(u8 *)(iVar1 + 0x1218) = 1;
      }
      else {
        lVar7 = FUN_001d8d80_int(lVar9);
        iVar4 = (int)lVar9;
        if (lVar7 == 0) {
          uVar6 = (u32)FUN_001d8b00_typed((void *)(param_1),(void *)(*(u32 *)(iVar1 + 0x24)),(void *)(lVar9));
          *(u32 *)(iVar1 + 0x1258) = uVar6;
          *(u8 *)(iVar1 + 0x1218) = 3;
          FUN_00453490(*(u32 *)(iVar4 + 0x16c));
          if (*(int *)(iVar4 + 0x18c) == 4) {
            if (DAT_008717a0_unit_rows[*(int *)(iVar1 + 4)].pad_170[0x2b] == '\0') {
              FUN_00456530((char)*(int *)(iVar1 + 4));
            }
          }
          else if (DAT_008717a0_unit_rows[*(int *)(iVar1 + 4)].pad_170[0x2b] == '\0') {
            FUN_00456580((char)*(int *)(iVar1 + 4));
          }
          FUN_0044e530(lVar9,*(u8 *)(iVar1 + 4));
          uVar2 = FUN_0016c470(DAT_008717a0_unit_rows[*(int *)(iVar1 + 4)].unit_id);
          *(u8 *)(iVar1 + 0x121a) = uVar2;
        }
        else {
          uVar8 = FUN_001d8d80_int(lVar9);
          FUN_001d8e60_typed((void *)(uVar8),(void *)(*(u32 *)(iVar1 + 0x24)),(void *)(0));
          uVar6 = FUN_001d8d80_int(lVar9);
          *(u32 *)(iVar1 + 0x1258) = uVar6;
          FUN_00453490(*(u32 *)(iVar4 + 0x16c));
          *(u8 *)(iVar1 + 0x1218) = 3;
          uVar2 = FUN_0016c470(DAT_008717a0_unit_rows[*(int *)(iVar1 + 4)].unit_id);
          *(u8 *)(iVar1 + 0x121a) = uVar2;
        }
      }
    }
    break;
  case 3:
    lVar9 = FUN_00195460_int(*(u32 *)(iVar1 + 0x1258));
    if (lVar9 == 0) {
      DAT_008717a0_unit_rows[*(int *)(iVar1 + 4)].pad_170[0x2b] = 0;
      *(u8 *)(iVar1 + 0x1218) = 4;
      *(u8 *)(iVar1 + 0x1215) = 0;
      if (*(char *)(iVar1 + 0x1222) == '\x01') {
        *(u8 *)(iVar1 + 0x1222) = 0;
      }
      lVar9 = FUN_002ff790_typed(DAT_008717a0_unit_rows[*(int *)(iVar1 + 4)].unk_048);
      if (lVar9 == 1) {
        *(u8 *)(iVar1 + 0x1218) = 4;
        *(u8 *)(iVar1 + 1) = 6;
        *(u8 *)(iVar1 + 0x1223) = 0;
        *(u8 *)(iVar1 + 0x1220) = 0;
        *(u8 *)(iVar1 + 0x1218) = 0;
      }
    }
    lVar9 = FUN_002ff790_typed(DAT_008717a0_unit_rows[*(int *)(iVar1 + 4)].unk_048);
    if (lVar9 == 1) {
      DAT_008717a0_unit_rows[*(int *)(iVar1 + 4)].pad_170[0x2b] = 0;
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
    sVar3 = FUN_0016c920_typed(DAT_008717a0_unit_rows[*(int *)(iVar1 + 4)].unit_id);
    if (sVar3 == 3) {
      FUN_004564e0(*(u8 *)(iVar1 + 4));
    }
    sVar3 = FUN_0016c920_typed(DAT_008717a0_unit_rows[*(int *)(iVar1 + 4)].unit_id);
    if (sVar3 == 4) {
      FUN_004565d0(*(u8 *)(iVar1 + 4));
    }
    else {
      sVar3 = FUN_0016c920_typed(DAT_008717a0_unit_rows[*(int *)(iVar1 + 4)].unit_id);
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
    lVar9 = FUN_001d8d80_int((int)&DAT_0086e6a0_unit_rows[*(char *)(iVar1 + 0x1219) + 4]);
    *(int *)(iVar1 + 0x1258) = (int)lVar9;
    if (lVar9 == 0) {
      *(u8 *)(iVar1 + 0x1218) = 4;
    }
    else {
      *(u8 *)(iVar1 + 0x1218) = 6;
      if (*(int *)&DAT_0086e6a0_unit_rows[*(char *)(iVar1 + 0x1219) + 4].pad_170[0x1c] == 4) {
        if (DAT_008717a0_unit_rows[*(int *)(iVar1 + 4)].pad_170[0x2b] == '\0') {
          FUN_00456530((char)*(int *)(iVar1 + 4));
        }
      }
      else if (DAT_008717a0_unit_rows[*(int *)(iVar1 + 4)].pad_170[0x2b] == '\0') {
        FUN_00456580((char)*(int *)(iVar1 + 4));
      }
    }
    break;
  case 6:
    lVar9 = FUN_00195460_int(*(u32 *)(iVar1 + 0x1258));
    if (lVar9 == 0) {
      *(u8 *)(iVar1 + 0x1218) = 4;
      *(u8 *)(iVar1 + 0x1215) = 0;
      DAT_008717a0_unit_rows[*(int *)(iVar1 + 4)].pad_170[0x2b] = 0;
      if (*(char *)(iVar1 + 0x1222) == '\x01') {
        *(u8 *)(iVar1 + 0x1222) = 0;
      }
      lVar9 = FUN_002ff790_typed(DAT_008717a0_unit_rows[*(int *)(iVar1 + 4)].unk_048);
      if (lVar9 == 1) {
        *(u8 *)(iVar1 + 0x1218) = 4;
        *(u8 *)(iVar1 + 1) = 6;
        *(u8 *)(iVar1 + 0x1223) = 0;
        *(u8 *)(iVar1 + 0x1220) = 0;
        *(u8 *)(iVar1 + 0x1218) = 0;
      }
    }
    lVar9 = FUN_002ff790_typed(DAT_008717a0_unit_rows[*(int *)(iVar1 + 4)].unk_048);
    if (lVar9 == 1) {
      DAT_008717a0_unit_rows[*(int *)(iVar1 + 4)].pad_170[0x2b] = 0;
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

// W419 YMisc4 negative: moving the iGpffffb5a0 load before the row lookup in FUN_00439f60 regressed nd12 -> 28 (object324/window336); rejected.
// FUN_00439F60 NONMATCHING

u64 FUN_00439f60(int param_1,char param_2)

{
  u32 lVar3;
  int iVar1;
  int iVar2;
  u32 uVar4;
  u32 lVar5;

  iVar2 = *(int *)(*(int *)(DAT_0087190c_abs + param_2 * 0x1c0) + 0x3c);
  iVar1 = iGpffffb5a0;
  lVar3 = FUN_001c6720_f32(*(u32 *)(iVar2 + 0x24),*(float *)(iVar1 + 0x14));
  if (*(char *)(iVar2 + 0x1216) == '\0') {
    if (lVar3 != 0) {
      uVar4 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x50));
      iVar2 = FUN_00318b60(*(u32 *)((int)lVar3 + 0x50));
      lVar3 = FUN_001c6450_f32(uVar4,(void *)((u8 *)(uintptr_t)iVar2 + 0x30),
                               *(float *)(iVar1 + 0x10),*(float *)(iVar1 + 0x14));
      if (lVar3 == 1) {
        return 1;
      }
    }
  }
  else if (lVar3 != 0) {
    uVar4 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x50));
    iVar2 = FUN_00318b60(*(u32 *)((int)lVar3 + 0x50));
    lVar5 = FUN_001c6450_f32(uVar4,(void *)((u8 *)(uintptr_t)iVar2 + 0x30),
                             *(float *)(iVar1 + 0x10),*(float *)(iVar1 + 0x14));
    if ((lVar5 == 1) && (FUN_001d8d80(lVar3) != 0)) {
      return 1;
    }
  }
  return 0;
}

// W419 YMisc4 negative: 0043a0b0 declaration reorder held nd12/object236; moving the iGpffffb5a0 assignment first regressed nd12 -> 34 (object236/window240); rejected.
// FUN_0043A0B0 NONMATCHING

u64 FUN_0043a0b0(u64 param_1,char param_2)

{
  u32 lVar3;
  int iVar1;
  u32 rowOffset;
  int iVar2;
  u32 uVar4;

  rowOffset = param_2 * 0x1c0;
  iVar2 = *(int *)(*(int *)(DAT_0087190c_abs + rowOffset) + 0x3c);
  iVar1 = iGpffffb5a0;
  lVar3 = FUN_001c6720_f32first(*(float *)(iVar1 + 0x14),(u32)DAT_008717a0_bytes);
  if ((*(char *)(iVar2 + 0x1216) == '\0') && (lVar3 != 0)) {
    uVar4 = FUN_00318b60(*(u32 *)(DAT_008717f0_abs + rowOffset));
    iVar2 = FUN_00318b60(*(u32 *)((int)lVar3 + 0x50));
    lVar3 = FUN_001c6450_f32(uVar4,(void *)((u8 *)(uintptr_t)iVar2 + 0x30),
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
/* W380 measured FUN_0043A2F0: pre-closure 1524/967; loop_invariants on 1524/967 (window 1648). Restores a setting lost when a leaked file-scope pragma was closed. */
#pragma opt_loop_invariants on
// W418 YMisc3 negative: inverted-guard probe moved nd967/object1524 to nd989/object1528 (window1648); rejected. Switch-label probe moved it to nd984/object1536; rejected.
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
  u32 uVar9;
  int lVar10;
  YRuntimeUnitRow *row;
  YRuntimeUnitRow *loopRow;
  
  iVar2 = *(int *)(param_1 + 0x3c);
  row = (YRuntimeUnitRow *)DAT_008717a0 + *(int *)(iVar2 + 4);
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
      uVar9 = FUN_0035bc00_u32(10,*(u32 *)((u8 *)row + 0x1b4),
                           *(u32 *)((u8 *)row + 0x1b8),0);
      FUN_0035c1a0_typed(uVar9,(s32)row);
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
    uVar9 = FUN_0035bb40_typed(10,*(u32 *)((u8 *)row + 0x1b4),
                         *(u8 *)(iVar2 + 0x1260));
    *(int *)(iVar2 + 0x125c) = (int)uVar9;
    FUN_0035c1a0_typed(uVar9,(s32)row);
    FUN_001b0260(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170),1);
    sVar5 = FUN_00318540_typed((void *)(*(u32 *)(*(int *)(iVar2 + 0xc) + 0x128)),0);
    sVar6 = FUN_001ded40_typed(row->unit_id);
    if (sVar5 == sVar6) {
      uVar7 = FUN_001dde00_typed(row->unit_id);
      FUN_003182d0(*(u32 *)(*(int *)(iVar2 + 0xc) + 0x128),0,uVar7,8,1);
    }
    cVar1 = *(char *)(iVar2 + 4);
    for (iVar8 = 1; (long)iVar8 < 4; iVar8 = iVar8 + 1) {
      loopRow = &DAT_008717a0_unit_rows[iVar8];
      bVar4 = 0;
      if ((DAT_008717e8_rows[iVar8 * 0x70] != 0) && (DAT_008717f4_rows[iVar8 * 0x70] != 0)) {
        bVar4 = 1;
      }
      if ((bVar4) && ((long)cVar1 != (long)iVar8)) {
        iVar3 = *(int *)((u8 *)loopRow->unit + 0x3c);
        *(u8 *)(iVar3 + 0x1215) = 1;
        FUN_001b0260(*(u32 *)(*(int *)(iVar3 + 0x24) + 0x170),1);
        sVar5 = FUN_00318540_typed((void *)(*(u32 *)(*(int *)(iVar3 + 0xc) + 0x128)),0);
        sVar6 = FUN_001ded40_typed(loopRow->unit_id);
        if (sVar5 == sVar6) {
          uVar7 = FUN_001dde00_typed(loopRow->unit_id);
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
        loopRow = &DAT_008717a0_unit_rows[iVar8];
        bVar4 = 0;
        if ((DAT_008717e8_rows[iVar8 * 0x70] != 0) && (DAT_008717f4_rows[iVar8 * 0x70] != 0)) {
          bVar4 = 1;
        }
        if ((bVar4) && ((long)cVar1 != (long)iVar8)) {
          iVar3 = *(int *)((u8 *)loopRow->unit + 0x3c);
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
#pragma opt_loop_invariants reset

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
  lVar12 = FUN_002ff790_typed((void *)DAT_008717e8_rows[iVar9 * 0x10]);
  if (lVar12 == 1) {
    bVar1 = 0;
    goto LAB_0043acec;
  }
  bVar1 = 0;
  if (DAT_008717e8_rows[iVar9 * 0x10] != 0) {
    bVar1 = DAT_008717f4_rows[iVar9 * 0x10] != 0;
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
        lVar12 = FUN_001c7160(500.0f,puVar20,DAT_008717a0_bytes + iVar9 * 0x40);
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
              fVar24 = (float)uVar13;
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
              fVar24 = (float)uVar13;
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
              fVar24 = (float)uVar13;
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
              fVar24 = (float)(iVar11 / iVar9) * fVar26 +
                       fVar24 * (float)(iVar11 / iVar9);
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
              fVar24 = (float)(iVar11 / iVar9) * fVar26 +
                       fVar24 * (float)(iVar11 / iVar9);
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
              fVar24 = (float)(iVar11 / iVar9) * fVar26 +
                       fVar24 * (float)(iVar11 / iVar9);
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
            if ((DAT_008717e8_rows[iVar18 * 0x70] != 0) && (DAT_008717f4_rows[iVar18 * 0x70] != 0)) {
              bVar1 = 1;
            }
            if ((bVar1) &&
               (lVar12 = FUN_001c7160(500.0f,puVar20,DAT_008717a0_bytes + iVar18 * 0x1c0),
               lVar12 == 1)) {
              FUN_0017b860_typed(*(u16 *)((u8 *)DAT_00871948 + iVar19),
                           *(u16 *)((u8 *)DAT_00871948 + iVar18 * 0x1c0),unaff_s3_lo,0);
            }
          }
        }
        bVar3 = 1;
      }
      uVar23 = 1;
    } while (sVar5 < sVar14);
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
  YRuntimeUnitRow *row;
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
  row = (YRuntimeUnitRow *)DAT_008717a0 + param_1;
  iVar4 = (int)FUN_00173380_typed(row->unit_id);
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
           (lVar5 = FUN_0017b660_2arg(row->unit_id,*psVar8), lVar5 == 0)) {
          psVar8 = (short *)(iVar4 + iVar10 * 2);
          FUN_0017be10(row->unit_id,uVar3,*psVar8,0,auStack_4,auStack_8,
                       auStack_c);
          return *psVar8;
        }
        cVar2 = FUN_0043bc20(param_2);
        if ((('\0' < cVar2) && (uVar6 = FUN_0016c970(uVar3), (uVar6 & 0x80) != 0)) &&
           (lVar5 = FUN_0017b660_2arg(row->unit_id,*psVar8), lVar5 == 0)) {
          psVar8 = (short *)(iVar4 + iVar10 * 2);
          FUN_0017be10(row->unit_id,uVar3,*psVar8,0,auStack_4,auStack_8,
                       auStack_c);
          sVar9 = *psVar8;
        }
      }
      else if (((sVar1 == 0xcb) && (lVar5 = FUN_0016c970(uVar3), lVar5 != 0)) &&
              (lVar5 = FUN_0017b660_2arg(row->unit_id,*psVar8), lVar5 == 0)) {
        FUN_0017be10(row->unit_id,uVar3,*psVar8,0,auStack_4,auStack_8,
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
// FUN_0043BC20

char FUN_0043bc20(char param_1)

{
  char cVar3;
  short sVar1;
  int iVar1;
  u32 uVar2;

  cVar3 = 0;
  sVar1 = param_1 == '\0' ? 1 : *(s16 *)(DAT_00871948_abs + param_1 * 0x1c0);
  iVar1 = sVar1;
  uVar2 = FUN_0016c970_s32(iVar1);
  if ((uVar2 & 1) != 0) {
    cVar3++;
  }
  uVar2 = FUN_0016c970_s32(iVar1);
  if ((uVar2 & 2) != 0) {
    cVar3++;
  }
  uVar2 = FUN_0016c970_s32(iVar1);
  if ((uVar2 & 4) != 0) {
    cVar3++;
  }
  uVar2 = FUN_0016c970_s32(iVar1);
  if ((uVar2 & 8) != 0) {
    cVar3++;
  }
  FUN_0016c970_s32(iVar1);
  uVar2 = FUN_0016c970_s32(iVar1);
  if ((uVar2 & 0x20) != 0) {
    cVar3++;
  }
  uVar2 = FUN_0016c970_s32(iVar1);
  if ((uVar2 & 0x40) != 0) {
    cVar3++;
  }
  uVar2 = FUN_0016c970_s32(iVar1);
  if ((uVar2 & 0x80) != 0) {
    cVar3++;
  }
  return cVar3;
}

#pragma push
#pragma opt_loop_invariants on
// W416 measured negative: retail offsets 48/112 have 0x18 extensions, while ours has matching 0x18 pairs nearby at 40/44 and 92/96; layout, not width.
// FUN_0043BDA0 NONMATCHING

short FUN_0043bda0(char param_1,char param_2)
{
  short value;
  long result;
  short *entry;
  int i;
  short selected;
  u8 *actor;
  u8 *target;
  u16 *actorId;
  u16 *targetId;
  u8 auStack_c [4];
  u8 auStack_8 [4];
  u8 auStack_4 [4];

  selected = -1;
  actor = DAT_008717a0_rows_abs[(char)param_1];
  actorId = (u16 *)(actor + 0x1a8);
  entry = (short *)FUN_00173380_typed(*actorId);
  i = 0;
  target = DAT_008717a0_rows_abs[(char)param_2];
  targetId = (u16 *)(target + 0x1a8);
  do {
    if (7 < i) {
      return selected;
    }
    value = entry[i];
    if (value != 0) {
      if (value == 0xcc) {
        result = FUN_0017b660_1arg(*actorId);
        if ((result == 0) &&
           (FUN_0017be10(*actorId, *targetId,
                         entry[i],0,auStack_4,auStack_8,auStack_c), selected != 0xcd)) {
          selected = entry[i];
        }
      }
      else if ((value == 0xcd) &&
              (result = FUN_0017b660_1arg(*actorId), result == 0)) {
        FUN_0017be10(*actorId, *targetId,
                     entry[i],0,auStack_4,auStack_8,auStack_c);
        return entry[i];
      }
    }
    i = i + 1;
  } while( 1 );
}

#pragma pop
#pragma push
/* W373 singles base 348/536; loop 348/536; common 410/592; life 348/536; propagation 259/552; strength 348/536; dead 259/552; pair propagation+dead 259/552. */
#pragma opt_propagation off
#pragma opt_dead_assignments off
// FUN_0043BF50 NONMATCHING

void FUN_0043bf50(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  long lVar4;
  RwV3d source;
  float actorPosition[4];
  RwV3d actorPositionCopy;
  RwV3d direction;
  RwV3d destination;
  float actorY;
  float actorZ;
  
  iVar2 = *(int *)((int)param_1 + 0x3c);
  cVar1 = *(char *)(iVar2 + 0x1255);
  if (cVar1 != '\x02') {
    if (cVar1 != '\x01') {
      if (cVar1 != '\0') {
        return;
      }
      FUN_001b00c0(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170));
      FUN_001b0240(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170),0);
      iVar3 = FUN_00318b60(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x50));
      source = *(RwV3d *)(iVar3 + 0x30);
      FUN_001ad940(actorPosition,
                   *(u32 *)(*(u32 *)(DAT_008717f4_abs + *(short *)(iVar2 + 0x1226) * 0x70) + 0x1e0));
      actorPositionCopy = *(RwV3d *)actorPosition;
      actorY = actorPositionCopy.y;
      actorZ = actorPositionCopy.z;
      direction.x = source.x - actorPosition[0];
      direction.y = source.y - actorPosition[1];
      direction.z = source.z - actorPosition[2];
      FUN_004c69f0((float *)&direction,(float *)&direction);
      destination.x = direction.x * 200.0f + actorPositionCopy.x;
      destination.y = direction.y * 200.0f + actorY;
      destination.z = direction.z * 200.0f + actorZ;
      FUN_001afa20_typed((uGpffff82b8),(void*)(*(u32 *)(*(int *)(iVar2 + 0x24) + 0x170)),(void*)&destination);
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
  else {
    *(u8 *)(iVar2 + 0x1254) = 0;
  }
  return;
}

#pragma pop
#pragma opt_propagation reset
#pragma opt_dead_assignments reset
#pragma push
#pragma opt_loop_invariants on
#pragma opt_common_subs off
/* W420 negative: declaration permutations stayed nd17/object436/window448/rate0.038991; player-character probe nd279/object444/window448/rate0.628378 versus baseline nd17/object436/window448/rate0.038991; reverted. */
// FUN_0043C180

short FUN_0043c180(char param_1)

{
  int uVar1;
  u32 bVar2;
  u32 uVar3;
  u16 *puVar4;
  u8 *sourceRow;
  u8 *checkRow;
  int iVar11;
  int iVar10;
  short sVar9;
  u32 uVar8;
  int player;
  u8 *row;
  u8 *row2;
  sVar9 = 0;
  uVar8 = 0;
  iVar11 = 1;
  player = param_1;
  sourceRow = DAT_008717a0_bytes + player * 0x1c0;
  for (; iVar11 < 4; iVar11 = iVar11 + 1) {
    if (player != iVar11) {
      bVar2 = 0;
      checkRow = DAT_008717a0_rows_check[iVar11];
      if ((*(int *)(checkRow + 0x48) != 0) && (*(int *)(checkRow + 0x54) != 0)) {
        bVar2 = 1;
      }
      bVar2 = bVar2 != 0;
      if ((bVar2 == 1) &&
          (FUN_001c7160_f32_u32(500.0f,sourceRow,checkRow) == 1)) {
        row = DAT_008717a0_rows_abs[iVar11];
        row2 = row;
        puVar4 = FUN_00173380_typed(*(u16 *)(row2 + 0x1a8));
        for (iVar10 = 0; iVar10 < 8; iVar10 = iVar10 + 1) {
          uVar1 = puVar4[iVar10];
          if (((uVar1 != 0) && (uVar1 == 0xcd)) &&
              (FUN_0017b660_i32_s16(*(s16 *)(row2 + 0x1a8),uVar1) == 0)) {
            uVar3 = FUN_0016c570_s16(*(s16 *)(row2 + 0x1a8));
            uVar3 = (u16)uVar3;
            if ((s32)(u16)uVar8 < (s32)uVar3) {
              sVar9 = (short)iVar11;
              uVar8 = uVar3;
            }
          }
        }
      }
    }
  }
  return sVar9;
}

#pragma pop
#pragma push
#pragma opt_loop_invariants on
#pragma opt_common_subs off
// FUN_0043C340

short FUN_0043c340(char param_1)

{
  int uVar1;
  u32 bVar2;
  u32 uVar3;
  u16 *puVar4;
  u8 *sourceRow;
  u8 *checkRow;
  int iVar11;
  int iVar10;
  short sVar9;
  u32 uVar8;
  u8 *row;
  int player;
  u8 *row2;

  sVar9 = 0;
  uVar8 = 0;
  iVar11 = 1;
  player = param_1;
  sourceRow = DAT_008717a0_bytes + player * 0x1c0;
  for (; iVar11 < 4; iVar11 = iVar11 + 1) {
    if (player != iVar11) {
      bVar2 = 0;
      checkRow = DAT_008717a0_rows_check[iVar11];
      if ((*(int *)(checkRow + 0x48) != 0) && (*(int *)(checkRow + 0x54) != 0)) {
        bVar2 = 1;
      }
      bVar2 = bVar2 != 0;
      if ((bVar2 == 1) &&
          (FUN_001c7160_f32_u32(500.0f,sourceRow,checkRow) == 1)) {
        row = DAT_008717a0_rows_abs[iVar11];
        row2 = row;
        puVar4 = FUN_00173380_typed(*(u16 *)(row2 + 0x1a8));
        for (iVar10 = 0; iVar10 < 8; iVar10 = iVar10 + 1) {
          uVar1 = puVar4[iVar10];
          if (((uVar1 != 0) && (uVar1 == 0xcc)) &&
              (FUN_0017b660_i32_s16(*(s16 *)(row2 + 0x1a8),uVar1) == 0)) {
            uVar3 = FUN_0016c570_s16(*(s16 *)(row2 + 0x1a8));
            uVar3 = (u16)uVar3;
            if ((s32)(u16)uVar8 < (s32)uVar3) {
              sVar9 = (short)iVar11;
              uVar8 = uVar3;
            }
          }
        }
      }
    }
  }
  return sVar9;
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

// FUN_0043C7F0

char FUN_0043c7f0(char param_1)
{
  int present;
  char result;
  int index = (int)param_1;
  int rowOffset;

  if (param_1 == 0) {
    result = 0;
  } else if (param_1 < 4) {
    present = 0;
    rowOffset = index * 0x1c0;
    if ((*(int *)(DAT_008717e8_abs + rowOffset) != 0) &&
        (*(int *)(DAT_008717f4_abs + rowOffset) != 0)) {
      present = 1;
    }
    present = present ? 1 : 0;
    if (present == 0) {
      result = 6;
    } else {
      result = *(char *)(*(int *)(*(int *)(DAT_0087190c_abs + rowOffset) + 0x3c) + 1);
    }
  } else {
    present = 0;
    rowOffset = index * 0x1c0;
    if ((*(int *)(DAT_0086e6e8_abs + rowOffset) != 0) &&
        (*(int *)(DAT_0086e6f4_abs + rowOffset) != 0)) {
      present = 1;
    }
    present = present ? 1 : 0;
    if (present == 0) {
      result = 6;
    } else {
      result = *(char *)(*(int *)(*(int *)(DAT_0086e80c_abs + rowOffset) + 0x3c) + 2);
    }
  }
  return result;
}

// FUN_0043C910

u32 FUN_0043c910(char param_1)
{
  int present;
  u32 result;
  int index = (int)param_1;
  int rowOffset;
  int actor;

  if (param_1 == 0) {
    result = FUN_0016c5f0_u32(1);
  } else if (param_1 < 4) {
    present = 0;
    rowOffset = index * 0x1c0;
    actor = *(int *)(DAT_008717e8_abs + rowOffset);
    if ((actor != 0) && (*(int *)(DAT_008717f4_abs + rowOffset) != 0)) {
      present = 1;
    }
    present = present ? 1 : 0;
    if (present == 0) {
      result = 0;
    } else {
      result = *(u16 *)(*(int *)(actor + 4) + 8);
    }
  } else {
    present = 0;
    rowOffset = index * 0x1c0;
    actor = *(int *)(DAT_0086e6e8_abs + rowOffset);
    if ((actor != 0) && (*(int *)(DAT_0086e6f4_abs + rowOffset) != 0)) {
      present = 1;
    }
    present = present ? 1 : 0;
    if (present == 0) {
      result = 0;
    } else {
      result = *(u16 *)(*(int *)(actor + 4) + 8);
    }
  }
  return result;
}

#pragma push
#pragma opt_loop_invariants on
/* W373/W419 measured propagation off: nd34998/object43300; on: nd35860/object44904; on matches retail frame -0x1f0 vs off -0x240. */
#pragma opt_propagation on
/* W419 negative: sinking case29 fVar22 after FUN_004222d0 regressed nd35564/object44892 to nd35841/object44900; reverted. */
/* W419 negative: sinking case23 fVar22 after FUN_00448060 regressed nd35547/object44884 to nd35927/object44900; reverted. */
/* W419 negative: reordering case27 post-call fVar22/fVar23 assignments regressed nd35547/object44884 to nd35800/object44872; reverted. */
/* W419 negative: whole float-census sink candidate (case27/case29 survivors after calls; case23 helper int) regressed nd35545/object44884 (rate .791930) to nd35785/object44864 (rate .797633); reverted. */
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
  int uVar21;
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
  u32 auStack_a4[2];
  float afStack_b0 [2];
  float fStack_b4;
  float fStack_b8;
  float fStack_bc;
  float fStack_c0;
  u32 uStack_c4;
  u32 uStack_c8;
  RwV2d stackD0;
  RwV2d stackE0;
  RwV2d stackD8;
  
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
  case 10:
    *puVar2 = 0xb;
    break;
  case 0xb:
    uVar6 = FUN_0010c1a0(0,0x6b4860,0,0,0,0,0,0,0,0,0x6b4878,0x1cd);
    *(u32 *)(puVar2 + 0x380) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b4890,0,0,0,0,0,0,0,0,0x6b4878,0x1ce);
    *(u32 *)(puVar2 + 900) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b48b0,0,0,0,0,0,0,0,0,0x6b4878,0x1cf);
    *(u32 *)(puVar2 + 0x388) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b48d0,0,0,0,0,0,0,0,0,0x6b4878,0x1d0);
    *(u32 *)(puVar2 + 0x38c) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b48f0,0,0,0,0,0,0,0,0,0x6b4878,0x1d1);
    *(u32 *)(puVar2 + 0x390) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b4910,0,0,0,0,0,0,0,0,0x6b4878,0x1d2);
    *(u32 *)(puVar2 + 0x394) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b4930,0,0,0,0,0,0,0,0,0x6b4878,0x1d4);
    *(u32 *)(puVar2 + 0x398) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b4950,0,0,0,0,0,0,0,0,0x6b4878,0x1d5);
    *(u32 *)(puVar2 + 0x39c) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b4970,0,0,0,0,0,0,0,0,0x6b4878,0x1d6);
    *(u32 *)(puVar2 + 0x3a0) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b4990,0,0,0,0,0,0,0,0,0x6b4878,0x1d7);
    *(u32 *)(puVar2 + 0x3a4) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b49b0,0,0,0,0,0,0,0,0,0x6b4878,0x1d8);
    *(u32 *)(puVar2 + 0x3a8) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b49d0,0,0,0,0,0,0,0,0,0x6b4878,0x1da);
    *(u32 *)(puVar2 + 0x3ac) = uVar6;
    uVar6 = FUN_0010c1a0(0,0x6b49e0,0,0,0,0,0,0,0,0,0x6b4878,0x1db);
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
  case 0x1a: {
    float spriteExtent[2];
    for (iVar17 = 0; iVar17 < 6; iVar17 = iVar17 + 1) {
      iVar13 = **(int **)(puVar2 + iVar17 * 4 + 0x274);
      uVar6 = *(u32 *)(iVar13 + 0x10);
      *(u32 *)(puVar2 + 0x308) = uVar6;
      *(u32 *)(puVar2 + 0x2b0) = uVar6;
      uVar6 = *(u32 *)(iVar13 + 0xc);
      *(u32 *)(puVar2 + 0x304) = uVar6;
      *(u32 *)(puVar2 + 0x2ac) = uVar6;
      FUN_00423fe0_typed(spriteExtent,1,0x280,0x280,*(u16 *)(puVar2 + 0x304),
                   *(u16 *)(puVar2 + 0x308));
      *(float *)(puVar2 + iVar17 * 8 + 0x2cc) = spriteExtent[0];
      *(float *)(puVar2 + iVar17 * 8 + 0x2d0) = spriteExtent[1];
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
  }
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
      if (cVar4 >= '\x06') {
        puVar2[0x93f] = 6;
      }
      else {
        puVar2[0x93f] = cVar4;
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
  case 0x1f: {
    float fVar22;
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
      if (fVar22 >= 2147483648.0f) {
        uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
      }
      else {
        uVar21 = (int)fVar22;
      }
      FUN_001140d0_f3(4.0f,*(float *)(puVar2 + 0x474),*(float *)(puVar2 + 0x478),
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
  }
  case 0x20: {
    float fVar22;
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
      if (fVar22 >= 2147483648.0f) {
        uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
      }
      else {
        uVar21 = (int)fVar22;
      }
      FUN_001140d0_f3(4.0f,*(float *)(puVar2 + 0x474),*(float *)(puVar2 + 0x478),
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
  }
  case 0x21: {
    float fVar22;
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
  }
  case 0x22: {
    float fVar22;
    bVar14 = 0;
    FUN_0044a990((int)(puVar2),(u32*)(*(u32 *)(puVar2 + 0x424)));
    if (*(char *)(DAT_007ce6ec + 0xad) == '\x06') {
      FUN_001140d0_f3(4.0f,*(float *)(puVar2 + 0x474),*(float *)(puVar2 + 0x478),
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
        if (fVar22 >= 2147483648.0f) {
          uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
        }
        else {
          uVar21 = (int)fVar22;
        }
        FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
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
        if (fVar22 >= 2147483648.0f) {
          uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
        }
        else {
          uVar21 = (int)fVar22;
        }
        FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
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
            if (*psVar16 >= 10) {
              fStack_70 = fStack_68 - 240.0f;
            }
            else {
              fStack_70 = (fStack_68 - 240.0f) - 20.0f;
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
          if (*(short *)(puVar2 + iVar13 * 6 + 0x356) >= 10) {
            *(u8 *)(iVar17 + 0x18) = 0;
          }
          else {
            *(u8 *)(iVar17 + 0x18) = 0xff;
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
      FUN_00447f90((float *)&stackD0,param_1,puVar2[0x93e] + puVar2[0x941]);
      *(float *)(puVar2 + 0x944) = stackD0.x;
      *(float *)(puVar2 + 0x948) = stackD0.y;
      *puVar2 = 0x23;
    }
    break;
  }
  case 0x23: {
    int iVar20;
    float fVar22;
    float fVar23;
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
          iVar20 = (int)FUN_00421fe0(1,0,0xff,*(short *)(puVar2 + iVar13 * 6 + 0x8bc),0xf);
          *(u32 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x2c) = 3.0f;
          *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x10) = fVar22;
          *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x14) = fVar23;
          *(char *)(*(int *)(puVar2 + iVar13 * 4 + 0x4a8) + 0x18) = (char)iVar20;
          *(u32 *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x2c) = 3.0f;
          *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x10) = fVar22 - 233.0f;
          *(float *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x14) = fVar23;
          *(char *)(*(int *)(puVar2 + iVar13 * 4 + 0x4c0) + 0x18) = (char)iVar20;
          *psVar16 = *psVar16 + 1;
        }
        if (lVar8 != (char)puVar2[0x93e]) {
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
        else {
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
      FUN_001140d0_f3(4.0f,*(float *)(puVar2 + 0x474),*(float *)(puVar2 + 0x478),
                   0xffffffffffffffff,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xad)) {
      iVar17 = (int)lVar8;
      cVar4 = *(char *)(DAT_007ce6ec + iVar17 + 0xa6);
      if (cVar4 == '\0') {
        FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2d0) - 64.0f,0xffffffffffffffff,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x274));
      }
      else if ((cVar4 == '\x01') && (lVar8 != 0)) {
        FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
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
              if ((int)cVar4 != ((int)(char)puVar2[0x940] - (int)(char)puVar2[0x93f])) {
                puVar2[0x941] = cVar4 + '\x06';
                if (((int)(char)puVar2[0x940] - (int)(char)puVar2[0x93f]) <= (int)(char)(cVar4 + '\x06')) {
                  puVar2[0x941] = (char)((int)(char)puVar2[0x940] - (int)(char)puVar2[0x93f]);
                }
              }
              else {
                puVar2[0x93e] = (puVar2[0x940] - cVar4) + -1;
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
          if (cVar3 >= '\x01') {
            puVar2[0x93e] = cVar3 + -1;
          }
          else {
            puVar2[0x93e] = puVar2[0x93f] + -1;
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
        FUN_00447f90((float *)&stackE0,param_1,puVar2[0x93e] + puVar2[0x941]);
        *(float *)(puVar2 + 0x944) = stackE0.x;
        *(float *)(puVar2 + 0x948) = stackE0.y;
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
      if ((char)puVar2[0x940] >= '\a') {
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
      else {
        if (lVar8 >= (char)puVar2[0x93f] + -1) {
          puVar2[0x93e] = 0;
        }
        else {
          puVar2[0x93e] = cVar3 + '\x01';
        }
      }
      FUN_00447f90((float *)&stackD8,param_1,puVar2[0x93e] + puVar2[0x941]);
      *(float *)(puVar2 + 0x944) = stackD8.x;
      *(float *)(puVar2 + 0x948) = stackD8.y;
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
  }
  case 0x24:
    for (iVar17 = 0; iVar17 < 3; iVar17 = iVar17 + 1) {
      *(u16 *)(puVar2 + iVar17 * 6 + 0x484) = 0;
      *(u16 *)(puVar2 + iVar17 * 6 + 0x486) = 0;
      *(u16 *)(puVar2 + iVar17 * 6 + 0x488) = 0;
      puVar2[iVar17 + 0x496] = (char)iVar17 * '\x02';
    }
    *puVar2 = 0x25;
  case 0x25: {
    float fVar22;
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
      FUN_001140d0_f3(4.0f,*(float *)(puVar2 + 0x474),*(float *)(puVar2 + 0x478),
                   0xffffffffffffffff,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xad)) {
      iVar17 = (int)lVar8;
      cVar4 = *(char *)(DAT_007ce6ec + iVar17 + 0xa6);
      if (cVar4 == '\0') {
        FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2d0) - 64.0f,0xffffffffffffffff,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x274));
      }
      else if ((cVar4 == '\x01') && (lVar8 != 0)) {
        FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
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
  }
  case 0x26: {
    float fVar22;
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
      if (lVar8 != *(char *)(DAT_007ce6ec + 0xae) + -1) {
        FUN_0044a240(afStack_88[0] + 308.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,
                     3.0f,param_1,(char)lVar8 + '\x05');
        FUN_0044a240(afStack_88[0] + 250.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,
                     3.0f,param_1,0xb);
      }
      else {
        FUN_0044a240(afStack_88[0] + 308.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,
                     3.0f,param_1,(char)lVar8 + '\x0f');
        FUN_0044a240(afStack_88[0] + 250.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,
                     3.0f,param_1,0x15);
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
      if (fVar22 >= 2147483648.0f) {
        uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
      }
      else {
        uVar21 = (int)fVar22;
      }
      FUN_001140d0_f3(4.0f,*(float *)(puVar2 + 0x474),*(float *)(puVar2 + 0x478),
                   uVar21 | 0xffffff00,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xad)) {
      iVar17 = (int)lVar8;
      fVar22 = (float)FUN_00421fe0(0,0xff,0,*(u16 *)(DAT_007ce6ec + iVar17 * 6 + 0x7e),10);
      if (fVar22 >= 2147483648.0f) {
        uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
      }
      else {
        uVar21 = (int)fVar22;
      }
      cVar4 = *(char *)(DAT_007ce6ec + iVar17 + 0xa6);
      if (cVar4 == '\0') {
        FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
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
        FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
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
  }
  case 0x27: {
    float fVar22;
    float fVar23;
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
        /* Native casts for each mirrored nine-conversion group measured +36 bytes and worse diff. */
        sVar10 = *(char *)(DAT_007ce6ec + 0xae) + -1;
        FUN_004222d0_typed((float*)(&fStack_90),(char)(0),(int)(0x244),(int)(0x238),(int)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + sVar10 * -0x40),(int)((6 - (char)puVar2[0x253]) * -0x20 + 0x166 + sVar10 * -0x40),(int)(*(u16 *)(puVar2 + 0x882)),(short)(0xf));
        fVar23 = (float)FUN_00421fe0(0,0,0xff,*(u16 *)(puVar2 + 0x882),0xf);
        fVar22 = (float)FUN_004221a0(1.0f,DAT_007caf94,(float)(int)*(short *)(puVar2 + 0x882),
                                     15.0f,0);
        if (fVar23 >= 2147483648.0f) {
          uVar18 = (u8)(int)(fVar23 - 2147483648.0f);
        }
        else {
          uVar18 = (u8)(int)fVar23;
        }
        *(u8 *)(iVar13 + 0x18) = uVar18;
        *(float *)(iVar13 + 0x10) = fStack_90;
        *(float *)(iVar13 + 0x14) = fStack_8c;
        fVar22 = fVar22 * 4096.0f;
        if (fVar22 >= 2147483648.0f) {
          uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
        }
        else {
          uVar19 = (u16)(int)fVar22;
        }
        *(u16 *)(iVar13 + 0x28) = uVar19;
        if (fVar22 >= 2147483648.0f) {
          uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
        }
        else {
          uVar19 = (u16)(int)fVar22;
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
      FUN_001140d0_f3(4.0f,*(float *)(puVar2 + 0x474),*(float *)(puVar2 + 0x478),
                   0xffffffffffffffff,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xa4)) {
      iVar17 = (int)lVar8;
      cVar4 = *(char *)(DAT_007ce6ec + iVar17 + 0xa6);
      if (cVar4 == '\0') {
        FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2d0) - 64.0f,0xffffffffffffffff,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x274));
      }
      else if ((cVar4 == '\x01') && (lVar8 != 0)) {
        FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2c8) - 64.0f,0xffffffffffffffff,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x3c4));
      }
      lVar8 = iVar17 + 1;
    }
    if (*(short *)(puVar2 + 0x87c) < 0xf) {
      fVar22 = (float)FUN_00421fe0(0,0,0xff,*(short *)(puVar2 + 0x87c),0xf);
      if (fVar22 >= 2147483648.0f) {
        uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
      }
      else {
        uVar21 = (int)fVar22;
      }
      iVar17 = (int)*(char *)(DAT_007ce6ec + 0xae);
      FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2c4) - 128.0f,
                   *(float *)(puVar2 + iVar17 * 8 + 0x2c8) - 64.0f,uVar21 | 0xffffff00,0x100,0x80,
                   *(u32 *)(puVar2 + iVar17 * 4 + 0x270));
      for (iVar17 = 0; iVar17 < 3; iVar17 = iVar17 + 1) {
        iVar13 = (int)*(char *)(DAT_007ce6ec + 0xae);
        FUN_00427e70_typed(4.0f,uVar21 | 0xffffff00,
                     *(float *)(puVar2 + iVar13 * 8 + 0x2c4) - 128.0f,
                     *(float *)(puVar2 + iVar13 * 8 + 0x2c8) - 64.0f,0x100,0x80,
                     *(u32 *)(puVar2 + iVar13 * 4 + 0x270));
      }
    }
    else {
      iVar17 = (int)*(char *)(DAT_007ce6ec + 0xae);
      FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2c4) - 128.0f,
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
        if (fVar23 >= 2147483648.0f) {
          uVar18 = (u8)(int)(fVar23 - 2147483648.0f);
        }
        else {
          uVar18 = (u8)(int)fVar23;
        }
        *(u8 *)(iVar13 + 0x18) = uVar18;
        *(float *)(iVar13 + 0x10) = fStack_90;
        *(float *)(iVar13 + 0x14) = fStack_8c;
        fVar22 = fVar22 * 4096.0f;
        if (fVar22 >= 2147483648.0f) {
          uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
        }
        else {
          uVar19 = (u16)(int)fVar22;
        }
        *(u16 *)(iVar13 + 0x28) = uVar19;
        if (fVar22 >= 2147483648.0f) {
          uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
        }
        else {
          uVar19 = (u16)(int)fVar22;
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
      if (fVar23 >= 2147483648.0f) {
        uVar18 = (u8)(int)(fVar23 - 2147483648.0f);
      }
      else {
        uVar18 = (u8)(int)fVar23;
      }
      *(u8 *)(iVar17 + 0x18) = uVar18;
      *(float *)(iVar17 + 0x10) = fStack_90;
      *(float *)(iVar17 + 0x14) = fStack_8c;
      *(u32 *)
       (*(char *)(DAT_007ce6ec + 0xae) * 0x80 + *(int *)(*(int *)(iVar17 + 8) + 0x184) + 0x72c) = 0;
      fVar22 = fVar22 * 4096.0f;
      if (fVar22 >= 2147483648.0f) {
        uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
      }
      else {
        uVar19 = (u16)(int)fVar22;
      }
      *(u16 *)(iVar17 + 0x28) = uVar19;
      if (fVar22 >= 2147483648.0f) {
        uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
      }
      else {
        uVar19 = (u16)(int)fVar22;
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
  }
  case 0x28: {
    float fVar22;
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
      if (lVar8 != *(char *)(DAT_007ce6ec + 0xae) + -1) {
        FUN_0044a240(afStack_a0[0] + 308.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,
                     3.0f,param_1,(char)lVar8 + '\x05');
        FUN_0044a240(afStack_a0[0] + 250.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,
                     3.0f,param_1,0xb);
      }
      else {
        FUN_0044a240(afStack_a0[0] + 308.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,
                     3.0f,param_1,(char)lVar8 + '\x0f');
        FUN_0044a240(afStack_a0[0] + 250.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,
                     3.0f,param_1,0x15);
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
      if (fVar22 >= 2147483648.0f) {
        uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
      }
      else {
        uVar21 = (int)fVar22;
      }
      uVar21 = uVar21 | 0xffffff00;
      FUN_001140d0_f3(4.0f,*(float *)(puVar2 + 0x474),*(float *)(puVar2 + 0x478),uVar21
                   ,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xa4)) {
      iVar17 = (int)lVar8;
      fVar22 = (float)FUN_00421fe0(0,0xff,0,*(u16 *)(DAT_007ce6ec + iVar17 * 6 + 0x7e),10);
      if (fVar22 >= 2147483648.0f) {
        uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
      }
      else {
        uVar21 = (int)fVar22;
      }
      uVar21 = uVar21 | 0xffffff00;
      cVar4 = *(char *)(DAT_007ce6ec + iVar17 + 0xa6);
      if (cVar4 == '\0') {
        FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2d0) - 64.0f,uVar21,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x274));
      }
      else if ((cVar4 == '\x01') && (lVar8 != 0)) {
        FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2c8) - 64.0f,uVar21,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x3c4));
      }
      lVar8 = iVar17 + 1;
    }
    iVar17 = (int)*(char *)(DAT_007ce6ec + 0xae);
    FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2c4) - 128.0f,
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
  }
  case 0x29: {
    float fVar22;
    float fVar23;
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
        fVar22 = (float)FUN_004221a0(1.0f,DAT_007caf94,(float)(int)*(short *)(puVar2 + 0x882),
                                     15.0f,0);
        sVar10 = *(char *)(DAT_007ce6ec + 0xae) + -1;
        FUN_004222d0_typed((float*)auStack_a4,(char)(0),(int)(0x244),(int)(0x238),(int)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + sVar10 * -0x40),(int)((6 - (char)puVar2[0x253]) * -0x20 + 0x166 + sVar10 * -0x40),(int)(*(u16 *)(puVar2 + 0x882)),(short)(0xf));
        fVar23 = (float)FUN_00421fe0(0,0,0xff,*(u16 *)(puVar2 + 0x882),0xf);
        if (fVar23 >= 2147483648.0f) {
          uVar18 = (u8)(int)(fVar23 - 2147483648.0f);
        }
        else {
          uVar18 = (u8)(int)fVar23;
        }
        *(u8 *)(iVar17 + 0x18) = uVar18;
        *(u32 *)(iVar17 + 0x10) = auStack_a4[0];
        *(u32 *)(iVar17 + 0x14) = auStack_a4[1];
        fVar22 = fVar22 * 4096.0f;
        if (fVar22 >= 2147483648.0f) {
          uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
        }
        else {
          uVar19 = (u16)(int)fVar22;
        }
        *(u16 *)(iVar17 + 0x28) = uVar19;
        if (fVar22 >= 2147483648.0f) {
          uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
        }
        else {
          uVar19 = (u16)(int)fVar22;
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
      FUN_001140d0_f3(4.0f,*(float *)(puVar2 + 0x474),*(float *)(puVar2 + 0x478),
                   0xffffffffffffffff,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xa4)) {
      iVar17 = (int)lVar8;
      cVar4 = *(char *)(DAT_007ce6ec + iVar17 + 0xa6);
      if (cVar4 == '\0') {
        FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2d0) - 64.0f,0xffffffffffffffff,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x274));
      }
      else if ((cVar4 == '\x01') && (lVar8 != 0)) {
        FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2c8) - 64.0f,0xffffffffffffffff,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x3c4));
      }
      lVar8 = iVar17 + 1;
    }
    fVar22 = (float)FUN_00421fe0(0,0,0xff,*(u16 *)(puVar2 + 0x87c),0xf);
    if (fVar22 >= 2147483648.0f) {
      uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
    }
    else {
      uVar21 = (int)fVar22;
    }
    iVar17 = (int)*(char *)(DAT_007ce6ec + 0xae);
    FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2c4) - 128.0f,
                 *(float *)(puVar2 + iVar17 * 8 + 0x2c8) - 64.0f,uVar21 | 0xffffff00,0x100,0x80,
                 *(u32 *)(puVar2 + iVar17 * 4 + 0x270));
    if (*(short *)(puVar2 + 0x87c) < 0xf) {
      for (iVar17 = 0; iVar17 < 3; iVar17 = iVar17 + 1) {
        uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),*(char *)(DAT_007ce6ec + 0xae) + 0xe);
        iVar13 = (int)uVar7;
        *(float *)(iVar13 + 0x2c) = 3.0f;
        fVar22 = (float)FUN_004221a0(10.0f,1.0f,(float)(int)*(short *)(puVar2 + 0x87c),
                                     15.0f,1);
        FUN_004222d0_typed((float*)auStack_a4,(char)(0),(int)(0x20),(int)(0x244),(int)(100),(int)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 +
                     (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),(int)(*(u16 *)(puVar2 + 0x87c)),(short)(0xf));
        fVar23 = (float)FUN_00421fe0(2,0xff,0,*(u16 *)(puVar2 + 0x87c),0xf);
        if (fVar23 >= 2147483648.0f) {
          uVar18 = (u8)(int)(fVar23 - 2147483648.0f);
        }
        else {
          uVar18 = (u8)(int)fVar23;
        }
        *(u8 *)(iVar13 + 0x18) = uVar18;
        *(u32 *)(iVar13 + 0x10) = auStack_a4[0];
        *(u32 *)(iVar13 + 0x14) = auStack_a4[1];
        fVar22 = fVar22 * 4096.0f;
        if (fVar22 >= 2147483648.0f) {
          uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
        }
        else {
          uVar19 = (u16)(int)fVar22;
        }
        *(u16 *)(iVar13 + 0x28) = uVar19;
        if (fVar22 >= 2147483648.0f) {
          uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
        }
        else {
          uVar19 = (u16)(int)fVar22;
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
      FUN_004222d0_typed((float*)auStack_a4,(char)(0),(int)(0x20),(int)(0x244),(int)(100),(int)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 +
                   (*(char *)(DAT_007ce6ec + 0xae) + -1) * -0x40),(int)(*(u16 *)(puVar2 + 0x87c)),(short)(0xf));
      if (fVar23 >= 2147483648.0f) {
        uVar18 = (u8)(int)(fVar23 - 2147483648.0f);
      }
      else {
        uVar18 = (u8)(int)fVar23;
      }
      *(u8 *)(iVar17 + 0x18) = uVar18;
      *(u32 *)(iVar17 + 0x10) = auStack_a4[0];
      *(u32 *)(iVar17 + 0x14) = auStack_a4[1];
      fVar22 = fVar22 * 4096.0f;
      if (fVar22 >= 2147483648.0f) {
        uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
      }
      else {
        uVar19 = (u16)(int)fVar22;
      }
      *(u16 *)(iVar17 + 0x28) = uVar19;
      if (fVar22 >= 2147483648.0f) {
        uVar19 = (u16)(int)(fVar22 - 2147483648.0f);
      }
      else {
        uVar19 = (u16)(int)fVar22;
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
  }
  case 0x2a: {
    float fVar22;
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
      if (lVar8 != *(char *)(DAT_007ce6ec + 0xae) + -1) {
        FUN_0044a240(afStack_b0[0] + 308.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,
                     3.0f,param_1,(char)lVar8 + '\x05');
        FUN_0044a240(afStack_b0[0] + 250.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,
                     3.0f,param_1,0xb);
      }
      else {
        FUN_0044a240(afStack_b0[0] + 308.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x172 + iVar17 * -0x40),0,
                     3.0f,param_1,(char)lVar8 + '\x0f');
        FUN_0044a240(afStack_b0[0] + 250.0f,
                     (float)((6 - (char)puVar2[0x253]) * -0x20 + 0x181 + iVar17 * -0x40),0,
                     3.0f,param_1,0x15);
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
      if (fVar22 >= 2147483648.0f) {
        uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
      }
      else {
        uVar21 = (int)fVar22;
      }
      FUN_001140d0_f3(4.0f,*(float *)(puVar2 + 0x474),*(float *)(puVar2 + 0x478),
                   uVar21 | 0xffffff00,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xa4)) {
      iVar17 = (int)lVar8;
      fVar22 = (float)FUN_00421fe0(0,0xff,0,*(u16 *)(DAT_007ce6ec + iVar17 * 6 + 0x7e),10);
      if (fVar22 >= 2147483648.0f) {
        uVar21 = (int)(fVar22 - 2147483648.0f) | 0x80000000;
      }
      else {
        uVar21 = (int)fVar22;
      }
      cVar4 = *(char *)(DAT_007ce6ec + iVar17 + 0xa6);
      if (cVar4 == '\0') {
        FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2d0) - 64.0f,uVar21 | 0xffffff00,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x274));
      }
      else if ((cVar4 == '\x01') && (lVar8 != 0)) {
        FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
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
  }
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
  case 0x2c: {
    float fVar22;
    float fVar23;
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
        if (lVar8 != (char)puVar2[0x93e]) {
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
        else {
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
          iVar13 = (int)DAT_006b4798;
          uVar7 = FUN_001158b0(0,*(u32 *)(puVar2 + 4),DAT_006b4796);
          iVar12 = (int)uVar7;
          fVar23 = (float)((int)DAT_006b479a + iVar17 * -0x40 + (6 - (char)puVar2[0x253]) * -0x20 +
                          0x20) - 32.0f;
          if (*(char *)(DAT_007ce6ec + ((int)(char)puVar2[0x93e] + (int)(char)puVar2[0x941]) * 4 + 4
                       ) + -1 == lVar8) {
            fVar22 = (float)FUN_00421fe0(1,0xff,0,sVar10,1);
          }
          else {
            fVar22 = (float)FUN_00421fe0(1,0,0xff,sVar10,1);
          }
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
      FUN_001140d0_f3(4.0f,*(float *)(puVar2 + 0x474),*(float *)(puVar2 + 0x478),
                   0xffffffffffffffff,0x100,0x1c0,*(u32 *)(puVar2 + 0x428));
    }
    lVar8 = 0;
    while (lVar8 < *(char *)(DAT_007ce6ec + 0xad)) {
      iVar17 = (int)lVar8;
      cVar4 = *(char *)(DAT_007ce6ec + iVar17 + 0xa6);
      if (cVar4 == '\0') {
        FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
                     *(float *)(puVar2 + iVar17 * 8 + 0x2d0) - 64.0f,0xffffffffffffffff,0x100,0x80,
                     *(u32 *)(puVar2 + iVar17 * 4 + 0x274));
      }
      else if ((cVar4 == '\x01') && (lVar8 != 0)) {
        FUN_001140d0_f3(4.0f,*(float *)(puVar2 + iVar17 * 8 + 0x2cc) - 128.0f,
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
      if (puVar2[0x251] != '\x01') {
        FUN_0044a630(param_1);
        *puVar2 = 0x2d;
      }
      else {
        *puVar2 = 0x23;
      }
    }
    break;
  }
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
#pragma opt_propagation reset
#pragma push
#pragma opt_loop_invariants on
#pragma opt_common_subs off
// FUN_00447AD0 NONMATCHING

void FUN_00447ad0(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  u32 value;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  for (iVar4 = 0; iVar4 < 6; iVar4 = iVar4 + 1) {
    iVar3 = iVar1 + iVar4 * 4 + 0x274;
    value = *(u32 *)iVar3;
    if (value != 0) {
      FUN_004d0f00_arg(value);
      *(u32 *)iVar3 = 0;
    }
  }
  for (iVar4 = 0; iVar4 < 5; iVar4 = iVar4 + 1) {
    iVar3 = iVar1 + iVar4 * 4 + 0x3c8;
    if (*(int *)iVar3 != 0) {
      FUN_004d0f00_arg(*(u32 *)iVar3);
      *(u32 *)iVar3 = 0;
    }
  }
  for (iVar4 = 0; iVar4 < 2; iVar4 = iVar4 + 1) {
    iVar3 = iVar1 + iVar4 * 4 + 0x424;
    if (*(int *)iVar3 != 0) {
      FUN_004d0f00_arg(*(u32 *)iVar3);
      *(u32 *)iVar3 = 0;
    }
  }
  if (*(int *)(iVar1 + 4) != 0) {
    FUN_001124b0_u32(*(u32 *)(iVar1 + 4));
    *(u32 *)(iVar1 + 4) = 0;
  }
  if (*(int *)(iVar1 + 0xe8) != 0) {
    FUN_001124b0_u32(*(u32 *)(iVar1 + 0xe8));
    *(u32 *)(iVar1 + 0xe8) = 0;
  }
  for (iVar4 = 0; iVar4 < 0x38; iVar4 = iVar4 + 1) {
    iVar3 = iVar1 + iVar4 * 4 + 8;
    if (*(int *)iVar3 != 0) {
      FUN_00115980_arg(*(u32 *)iVar3);
      *(u32 *)iVar3 = 0;
    }
  }
  for (iVar4 = 0; iVar4 < 6; iVar4 = iVar4 + 1) {
    iVar3 = iVar1 + iVar4 * 4;
    if (*(int *)(iVar3 + 0x4a8) != 0) {
      FUN_00115980_arg(*(u32 *)(iVar3 + 0x4a8));
      *(u32 *)(iVar3 + 0x4a8) = 0;
    }
    if (*(int *)(iVar3 + 0x4c0) != 0) {
      FUN_00115980_arg(*(u32 *)(iVar3 + 0x4c0));
      *(u32 *)(iVar3 + 0x4c0) = 0;
    }
    if (*(int *)(iVar3 + 0x4f0) != 0) {
      FUN_00115980_arg(*(u32 *)(iVar3 + 0x4f0));
      *(u32 *)(iVar3 + 0x4f0) = 0;
    }
    if (*(int *)(iVar3 + 0x4d8) != 0) {
      FUN_00115980_arg(*(u32 *)(iVar3 + 0x4d8));
      *(u32 *)(iVar3 + 0x4d8) = 0;
    }
    for (iVar3 = 0; iVar3 < 3; iVar3 = iVar3 + 1) {
      for (iVar5 = 0; iVar5 < 0xc; iVar5 = iVar5 + 1) {
        iVar2 = iVar1 + iVar4 * 0x90 + iVar3 * 0x30 + iVar5 * 4 + 0x508;
        if (*(int *)iVar2 != 0) {
          FUN_00115980_arg(*(u32 *)iVar2);
          *(u32 *)iVar2 = 0;
        }
      }
    }
  }
  for (iVar4 = 0; iVar4 < 6; iVar4 = iVar4 + 1) {
    iVar3 = iVar1 + iVar4 * 4 + 0x33c;
    if (*(int *)iVar3 != 0) {
      FUN_00115980_arg(*(u32 *)iVar3);
      *(u32 *)iVar3 = 0;
    }
  }
  if (*(int *)(iVar1 + 0x868) != 0) {
    FUN_00115980_arg(*(u32 *)(iVar1 + 0x868));
    *(u32 *)(iVar1 + 0x868) = 0;
  }
  if (*(int *)(iVar1 + 0x86c) != 0) {
    FUN_00115980_arg(*(u32 *)(iVar1 + 0x86c));
    *(u32 *)(iVar1 + 0x86c) = 0;
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
#pragma opt_common_subs reset
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
// FUN_00447F90

void FUN_00447f90(float *param_1,int param_2,char param_3)

{
  struct CoordinateValues {
    s16 unused;
    s16 x;
    s16 y;
  };
  RwV2d position;
  float y;
  int cVar1;
  int cVar2;
  int index;
  int iVar3;
  u8 *table;
  u8 *row;
  
  index = (int)param_3 * 4;
  table = iGpffffb9fc_ptr;
  row = table;
  row = (u8 *)(index + (int)row);
  cVar1 = *(volatile s8 *)(row + 4);
  {
    struct CoordinateValues *coordinateBase;
    
    coordinateBase = (struct CoordinateValues *)DAT_006b4796_abs;
    iVar3 = coordinateBase->y;
    iVar3 = iVar3 - (cVar1 - 1) * 0x40;
    cVar2 = *(s8 *)(*(int *)(param_2 + 0x3c) + 0x253);
    iVar3 = iVar3 - (6 - cVar2) * 0x20;
    iVar3 = iVar3 + 0x20;
    y = (float)iVar3;
    for (index = 0; index < *(char *)(table + 0xa0); index = index + 1) {
    }
    position.y = y - 32.0f;
    position.x = (float)coordinateBase->x;
  }
  *(RwV2d *)param_1 = position;
  return;
}

#pragma pop
#pragma push
/* W373 singles base 2419/3208; loop 2428/3208; common 2617/3520; life 2419/3208; propagation 2363/3164; strength 2419/3208; dead 2424/3208. */
#pragma opt_propagation off
// FUN_00448060 NONMATCHING

void FUN_00448060(int param_1,u8 param_2,u64 param_3,char param_4,short param_5,
                 char param_6)

{
  int iVar1;
  int iVar2;
  u32 uVar3;
  char cVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  short sVar9;
  char cVar10;
  int iVar11;
  float fVar13;
  float fVar15;
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
  if ((char)param_2 == cVar5) {
    iVar1 = 0;
    for (; iVar1 < 2; iVar1 = iVar1 + 1) {
      fVar15 = 255.0f;
      iVar6 = iVar2 + iVar1 * 2;
      if (*(short *)(iVar6 + 0x958) == 0) {
        if (*(short *)(iVar6 + 0x954) < 0x17) {
          *(short *)(iVar6 + 0x954) = *(short *)(iVar6 + 0x954) + 1;
        }
        fVar15 = FUN_004221a0(0,255.0f,(float)(int)*(short *)(iVar6 + 0x954),23.0f,2);
      }
      else {
        *(short *)(iVar6 + 0x958) = *(short *)(iVar6 + 0x958) + -1;
      }
      iVar6 = iVar2 + iVar1 * 2;
      fVar13 = (float)FUN_004221a0(afStack_8[0],afStack_8[0] + 15.0f,
                                   (float)(int)*(short *)(iVar6 + 0x954),23.0f,1);
      FUN_0044a240((float)(1 - iVar1) * 20.0f + (fVar13 - 90.0f) + 0.0f,afStack_8[1],fVar15,3.0f,
                   param_1,9);
      fVar13 = (float)FUN_004221a0(afStack_8[0],afStack_8[0] - 15.0f,(float)(int)*(short *)(iVar6 + 0x954),
                                   23.0f,1);
      FUN_0044a240((float)iVar1 * 20.0f + fVar13 + 61.0f + 0.0f,afStack_8[1],fVar15,3.0f,param_1,0x36
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
    for (; iVar1 < 2; iVar1 = iVar1 + 1) {
      FUN_0044a240((afStack_8[0] - 90.0f) + (float)iVar1 * 20.0f,afStack_8[1] + 2.0f,0,3.0f,param_1,0x26)
      ;
      FUN_0044a240((afStack_8[0] + 61.0f) + (float)iVar1 * 20.0f,afStack_8[1] + 2.0f,0,3.0f,param_1,0x26);
    }
  }
  iVar1 = (int)param_5;
  if (param_5 < 10) {
    sVar9 = param_5;
    if ((char)param_2 != cVar5) {
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
    if ((char)param_2 != cVar5) {
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
    if ((char)param_2 != cVar5) {
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
  if ((char)param_2 != cVar5) {
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
#pragma opt_propagation reset
#pragma push
#pragma opt_loop_invariants on
/* W373 singles base 3031/3984; loop 3031/3984; common 3342/4200; life 3032/3984; propagation 3102/3900; strength 3031/3984; dead 2995/3984. */
#pragma opt_dead_assignments off
// FUN_00448CF0 NONMATCHING

void FUN_00448cf0(int param_1,u8 param_2,u64 param_3,char param_4,short param_5,
                 char param_6,int param_7)

{
  char cVar1;
  int iVar3;
  int iVar4;
  u32 uVar5;
  u8 bVar8;
  int iVar9;
  int iVar10;
  long lVar11;
  char cVar12;
  char cVar13;
  int iVar14;
  float fVar15;
  float fVar17;
  float afStack_8[2];
  
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
  if ((char)param_2 == (char)bVar8) {
    for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {
      fVar17 = 255.0f;
      iVar9 = iVar4 + iVar3 * 2;
      if (*(short *)(iVar9 + 0x958) == 0) {
        if (*(short *)(iVar9 + 0x954) < 0x17) {
          *(short *)(iVar9 + 0x954) = *(short *)(iVar9 + 0x954) + 1;
        }
        fVar17 = FUN_004221a0(0,255.0f,(float)(int)*(short *)(iVar9 + 0x954),23.0f,2);
      }
      else {
        *(short *)(iVar9 + 0x958) = *(short *)(iVar9 + 0x958) + -1;
      }
      iVar9 = iVar4 + iVar3 * 2;
      fVar15 = (float)FUN_004221a0(afStack_8[0],afStack_8[0] + 15.0f,
                                   (float)(int)*(short *)(iVar9 + 0x954),23.0f,1);
      FUN_0044a240((float)(1 - iVar3) * 20.0f + (fVar15 - 90.0f) + 0.0f,afStack_8[1],fVar17,3.0f,
                   param_1,9);
      fVar15 = (float)FUN_004221a0(afStack_8[0],afStack_8[0] - 15.0f,(float)(int)*(short *)(iVar9 + 0x954),
                                   23.0f,1);
      FUN_0044a240((float)iVar3 * 20.0f + fVar15 + 61.0f + 0.0f,afStack_8[1],fVar17,3.0f,param_1,0x36
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
    for (iVar3 = 0; iVar3 < 2; iVar3 = iVar3 + 1) {
      FUN_0044a240((afStack_8[0] - 90.0f) + (float)iVar3 * 20.0f,afStack_8[1] + 2.0f,0,3.0f,param_1,0x26)
      ;
      FUN_0044a240((afStack_8[0] + 61.0f) + (float)iVar3 * 20.0f,afStack_8[1] + 2.0f,0,3.0f,param_1,0x26);
    }
  }
  lVar11 = (long)param_5;
  iVar3 = (int)param_5;
  if (lVar11 < 10) {
    if ((char)param_2 != (char)bVar8) {
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
    if ((char)param_2 != (char)bVar8) {
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
    if ((char)param_2 != (char)bVar8) {
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
  if ((char)param_2 == (char)bVar8) {
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

#pragma opt_dead_assignments reset
// FUN_00449D60 NONMATCHING

void FUN_00449d60(int param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  u32 uStack_8;
  u32 uStack_4;
  
  iVar3 = *(int *)((int)param_1 + 0x3c);
  do {
    if (*(char *)(iVar3 + 0x940) < '\a') {
      if (*(char *)(iVar3 + 0x93e) < *(char *)(iVar3 + 0x93f) + -1) {
        *(char *)(iVar3 + 0x93e) = *(char *)(iVar3 + 0x93e) + '\x01';
      }
      else {
        *(u8 *)(iVar3 + 0x93e) = 0;
      }
    }
    else {
      cVar1 = *(char *)(iVar3 + 0x93e);
      cVar2 = *(char *)(iVar3 + 0x93f);
      if (cVar1 < cVar2 + -2) {
        *(char *)(iVar3 + 0x93e) = cVar1 + '\x01';
      }
      else if (*(char *)(iVar3 + 0x941) < *(char *)(iVar3 + 0x940) - cVar2) {
        *(char *)(iVar3 + 0x941) = *(char *)(iVar3 + 0x941) + '\x01';
      }
      else if (cVar1 < cVar2 + -1) {
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
  } while (*(short *)(iGpffffb9fc + ((int)*(char *)(iVar3 + 0x93e) +
                                     (int)*(char *)(iVar3 + 0x941)) * 4 + 6) !=
           *(short *)(iGpffffb9fc + 0xa2));
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

// FUN_00449FE0

u32
FUN_00449fe0(float param_1,float param_2,float param_3,float param_4,int param_5,short param_6)

{
  RwV2d position;
  YPositionWork *work;
  int iVar3;
  u32 uVar4;
  u32 uVar5;
  
  work = *(YPositionWork **)(param_5 + 0x3c);
  uVar5 = 0;
  if (param_6 == 0) {
    position.x = param_2;
    position.y = param_4;
  }
  else {
    FUN_004222d0_s16_counter(&position.x,(char)(0),(int)((short)(int)param_1),(int)((short)(int)param_2),(int)((short)(int)param_3),(int)((short)(int)param_4),work->counter0,(short)(param_6));
    if (work->counter0 < param_6) {
      work->counter0 += 1;
      uVar5 = 1;
    }
  }
  uVar4 = FUN_001158b0(0,work->resource,0);
  iVar3 = (int)uVar4;
  *(u8 *)(iVar3 + 0x18) = 0;
  *(float *)(iVar3 + 0x10) = position.x;
  *(float *)(iVar3 + 0x14) = position.y;
  *(float *)(iVar3 + 0x2c) = 3.0f;
  FUN_001127d0(uVar4,1);
  FUN_00115980(uVar4);
  return uVar5;
}

// FUN_0044A110

u32
FUN_0044a110(float param_1,float param_2,float param_3,float param_4,int param_5,short param_6)

{
  YPositionWork *work;
  int iVar3;
  u32 uVar4;
  u32 uVar5;
  RwV2d position;
  
  work = *(YPositionWork **)(param_5 + 0x3c);
  uVar5 = 0;
  if (param_6 == 0) {
    position.x = param_2;
    position.y = param_4;
  }
  else {
    FUN_004222d0_s16_counter(&position.x,(char)(0),(int)((short)(int)param_1),(int)((short)(int)param_2),(int)((short)(int)param_3),(int)((short)(int)param_4),work->counter1,(short)(param_6));
    if (work->counter1 < param_6) {
      work->counter1 += 1;
      uVar5 = 1;
    }
  }
  uVar4 = FUN_001158b0(0,work->resource,1);
  iVar3 = (int)uVar4;
  *(u8 *)(iVar3 + 0x18) = 0;
  *(float *)(iVar3 + 0x10) = position.x;
  *(float *)(iVar3 + 0x14) = position.y;
  *(float *)(iVar3 + 0x2c) = 3.0f;
  FUN_001127d0(uVar4,1);
  FUN_00115980(uVar4);
  return uVar5;
}

// FUN_0044A240

void FUN_0044a240(float param_1,float param_2,float param_3,float param_4,int param_5
                 ,char param_6)

{
  u32 uVar3;
  u32 uVar2;
  int iVar1;
  
  uVar2 = FUN_001158b0(0,*(u32 *)(*(int *)(param_5 + 0x3c) + 4),param_6);
  *(float *)(uVar2 + 0x2c) = param_4;
  uVar3 = (u8)param_3;
  *(u8 *)(uVar2 + 0x18) = uVar3;
  *(float *)(uVar2 + 0x10) = param_1;
  *(float *)(uVar2 + 0x14) = param_2;
  FUN_001127d0(uVar2,1);
  FUN_00115980(uVar2);
  return;
}

// FUN_0044A330

void FUN_0044a330(float param_1,float param_2,float param_3,float param_4,int param_5
                 ,char param_6)

{
  u32 uVar3;
  u32 uVar2;
  int iVar1;
  
  uVar2 = FUN_001158b0(0,*(u32 *)(*(int *)(param_5 + 0x3c) + 0xe8),param_6);
  iVar1 = (int)uVar2;
  *(float *)(iVar1 + 0x2c) = param_4;
  uVar3 = (u8)param_3;
  *(u8 *)(iVar1 + 0x18) = uVar3;
  *(float *)(iVar1 + 0x10) = param_1;
  *(float *)(iVar1 + 0x14) = param_2;
  FUN_001127d0(uVar2,1);
  FUN_00115980(uVar2);
  return;
}

// FUN_0044A420 NONMATCHING

char FUN_0044a420(int param_1,int param_2,int param_3)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  int iVar6;
  char bVar7;
  int iVar8;
  float fVar9;
  u32 uVar10;
  
  iVar3 = *(int *)(param_1 + 0x3c);
  bVar7 = 0;
  iVar8 = (int)param_2;
  iVar6 = iVar8 * 6;
  fVar9 = (float)FUN_00421fe0_s16(0,0,0xff,*(short *)(iVar6 + iGpffffb9fc + 0x7c),param_3);
  uVar10 = (u32)fVar9;
  cVar1 = *(char *)(iGpffffb9fc + 0xa6 + iVar8);
  if (cVar1 == '\0') {
    iVar4 = iVar8 * 8 + iVar3;
    FUN_001140d0_f3(4.0f,*(float *)(iVar4 + 0x2cc) - 128.0f,
                 *(float *)(iVar4 + 0x2d0) - 64.0f,
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
    if (sVar2 < (short)param_3) {
      *psVar5 = sVar2 + 1;
      bVar7 = 1;
    }
    iVar6 = iVar8 * 8 + iVar3;
    FUN_001140d0_f3(4.0f,*(float *)(iVar6 + 0x2cc) - 128.0f,*(float *)(iVar6 + 0x2c8) - 64.0f,
                 uVar10 | 0xffffff00,0x100,0x80,
                 *(u32 *)(iVar8 * 4 + iVar3 + 0x3c4));
  }
  return bVar7;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_0044A630

void FUN_0044a630(int param_1)

{
  int iVar1;
  int lVar2;
  int iVar3;
  volatile s8 *slot;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x3c);
  for (lVar2 = 0; lVar2 < *(char *)(iVar1 + 0x93f); lVar2++) {
    iVar3 = iVar1 + lVar2 * 4;
    *(u8 *)(*(int *)(iVar3 + 0x4a8) + 0x18) = 0xff;
    *(u8 *)(*(int *)(iVar3 + 0x4c0) + 0x18) = 0xff;
    *(u8 *)(*(int *)(iVar3 + 0x4f0) + 0x18) = 0xff;
    *(u8 *)(*(int *)(iVar3 + 0x4d8) + 0x18) = 0xff;
  }
  *(u8 *)(*(int *)((u8 *)(DAT_006b46d0_abs[0] * 4) + iVar1 + 8) + 0x18) = 0xff;
  slot = (s8 *)DAT_006b4784_abs;
  *(u8 *)(*(int *)((u8 *)(*(volatile s8 *)slot * 4) + iVar1 + 8) + 0x18) = 0xff;
  slot = (s8 *)DAT_006b477e_abs;
  *(u8 *)(*(int *)((u8 *)(*(volatile s8 *)slot * 4) + iVar1 + 8) + 0x18) = 0xff;
  slot = (s8 *)DAT_006b478a_abs;
  *(u8 *)(*(int *)((u8 *)(*(volatile s8 *)slot * 4) + iVar1 + 8) + 0x18) = 0xff;
  *(u8 *)(*(int *)(iVar1 + 0x868) + 0x18) = 0xff;
  *(u8 *)(*(int *)(iVar1 + 0x86c) + 0x18) = 0xff;
  for (iVar4 = 0; iVar4 < 6; iVar4 = iVar4 + 1) {
    *(u8 *)(*(int *)(iVar1 + iVar4 * 4 + 0x33c) + 0x18) = 0xff;
  }
  for (iVar3 = 0; iVar3 < 0x38; iVar3 = iVar3 + 1) {
    slot = DAT_006b46d0_abs;
    if (slot[iVar3 * 6] != -1) {
      *(u8 *)(*(int *)(iVar1 + iVar3 * 4 + 8) + 0x18) = 0xff;
    }
  }
  return;
}

#pragma pop
// FUN_0044A790

void FUN_0044a790(u32 *param_1)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  f32 fVar5;
  float fVar6;
  float fVar10;
  float scaledX;
  float fVar8;
  float fVar9;
  float fVar7;
  
  iVar3 = param_1[3];
  iVar1 = FUN_00198590_typed();
  fVar10 = 1.0f / *(float *)(iVar1 + 0x80);
  fVar9 = (float)*(int *)(iVar3 + 0x480) / 180.0f;
  iVar3 = param_1[4] * 0x40;
  pfVar2 = (float *)(*(int *)*param_1 + iVar3);
  scaledX = *(float *)(param_1 + 1) * 640.0f;
  fVar8 = *(float *)(param_1 + 2) * 448.0f;
  fVar7 = SQRT((scaledX - 320.0f) * (scaledX - 320.0f) + (fVar8 - 224.0f) * (fVar8 - 224.0f));
  fVar5 = FUN_0052ea18_f32(scaledX - 320.0f,fVar8 - 224.0f);
  fVar6 = (float)FUN_0052e878_typed(fGpffff8248_y2 * ((fVar7 / 200.0f - fVar9) * 2.0f));
  fVar9 = fVar6 * 20.0f + fVar7 + 0.0f;
  fVar6 = FUN_00269c80_f32(fVar5);
  fVar7 = fVar9 * fVar6 + 320.0f;
  fVar6 = FUN_00269ca0_f32(fVar5);
  fVar9 = fVar9 * fVar6 + 224.0f;
  *pfVar2 = scaledX;
  pfVar2[1] = fVar8;
  pfVar2[4] = fVar7 / 640.0f;
  pfVar2[5] = fVar9 / 448.0f;
  pfVar2[8] = 255.0f;
  pfVar2[9] = 255.0f;
  pfVar2[10] = 255.0f;
  pfVar2[0xb] = 255.0f;
  pfVar2[2] = *(float *)DAT_00960088_abs - 100.0f;
  pfVar2[6] = fVar10;
  return;
}

// FUN_0044A990

void FUN_0044a990(int param_1,u32 *param_2)

{
  int iVar1;
  void (**renderState)();
  struct {
    code *callback;
    int context;
  } callback;
  
  iVar1 = *(int *)(param_1 + 0x480) + 1;
  *(int *)(param_1 + 0x480) = iVar1;
  *(int *)(param_1 + 0x480) = iVar1 % 0xb4;
  callback.context = param_1;
  renderState = (void (**)())DAT_00960090_abs;
  (*renderState)(6,1);
  (*renderState)(7,2);
  (*renderState)(8,1);
  (*renderState)(9,2);
  (*renderState)(0xc,1);
  (*renderState)(0xb,6);
  (*renderState)(10,5);
  (*renderState)(2,4);
  FUN_004d7f60_typed(2,0x44);
  FUN_004d7f60_typed(3,0x717fb);
  (*renderState)(1,*param_2);
  FUN_002699d0_typed(*(u32 *)(param_1 + 0x47c));
  callback.callback = (code *)&FUN_0044a790;
  FUN_00269a10_typed(*(u32 *)(param_1 + 0x47c),&callback);
  return;
}

// W415 ORDER probe negative: ascending switch plus 120 local-declaration permutations measured nd290/464 -> nd295/472; rejected.
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

// FUN_0044AD20




u32 FUN_0044ad20(u64 param_1,char param_2)

{
  u32 uVar1;
  u32 uVar3;
  u32 lVar2;
  int *piVar4;
  int iVar5;
  char *puVar6;
  YVec3f vec;
  
  lVar2 = (*DAT_00960184_abs)(1,0x1098,0x40000);
  if (lVar2 == 0) {
    return 0;
  }
  uVar3 = FUN_00194b80_u32(param_1,10,DAT_006b4a18,(u32 (*)(int))FUN_0044aaf0,FUN_0044acf0,lVar2);
  puVar6 = (char *)lVar2;
  *puVar6 = 0;
  puVar6[2] = 4;
  iVar5 = param_2 * 0x1c0;
  piVar4 = (int *)(DAT_0086ef2c_abs + iVar5);
  if (*piVar4 == 4) {
    puVar6[2] = 3;
    uVar1 = (u32)FUN_001aaa20_typed((void *)(uVar3),(u32)(DAT_0086eda0_bytes + iVar5));
    *(u32 *)(puVar6 + 0x10) = uVar1;
  }
  puVar6[3] = 0;
  puVar6[4] = 0;
  puVar6[5] = 0;
  puVar6[1] = param_2;
  puVar6[0x40] = 0;
  if (*(char *)(DAT_0086ef3a_abs + iVar5) != '\0') {
    puVar6[0x18] = *(char *)(DAT_0086ef38_abs + param_2 * 0x1c0);
    puVar6[0x8c] = (u32)*(u8 *)(DAT_0086ef39_abs + param_2 * 0x1c0) >> 4;
    puVar6[0x8b] = *(u8 *)(DAT_0086ef39_abs + param_2 * 0x1c0) % 0x10;
    puVar6[2] = *(char *)(DAT_0086ef3a_abs + iVar5);
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
  if (*(char *)(DAT_0086ef3c_abs + iVar5) == '\x01') {
    puVar6[0x40] = 1;
  }
  if (*piVar4 == 4) {
    FUN_00452f70((u32 *)&vec,uVar3);
    *(YVec3f *)(puVar6 + 0x28) = vec;
  }
  return uVar3;
}

/* W409 measured: baseline NONMATCHING 2080/2160 nd1425; local DAT_0086edf4_abs uses 2104/2160 nd1405. */
// FUN_0044AF60 NONMATCHING






void FUN_0044af60(u32 param_1)

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
  u32 lVar10;
  int iVar11;
  int iVar12;
  YVec3f uStack_10;
  YVec3f uStack_30;
  float auStack_20 [4];
  
  iVar1 = *(int *)((int)param_1 + 0x3c);
  iVar11 = *(char *)(iVar1 + 1) * 0x1c0;
  iVar12 = iGpffffb5a0 + *(int *)((u8 *)DAT_0086ef2c + iVar11) * 0x40;
  switch(*(u8 *)(iVar1 + 4)) {
  case 0:
    uVar3 = FUN_001ad910(*(u32 *)(*(int *)((u8 *)DAT_0086edf4_abs + iVar11) + 0x1e0));
    *(u8 *)(iVar1 + 0x5c) = uVar3;
    uVar3 = FUN_001ad920(*(u32 *)
                          (*(int *)((u8 *)DAT_0086edf4_abs + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    *(u8 *)(iVar1 + 0x5d) = uVar3;
    FUN_001ad940(&uStack_10,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4_abs + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    *(YVec3f *)(iVar1 + 0x50) = uStack_10;
    *(YVec3f *)(iVar1 + 0x60) = *(YVec3f *)(iVar1 + 0x50);
    *(YVec3f *)(iVar1 + 0x6c) = *(YVec3f *)(iVar1 + 0x60);
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
    lVar10 = FUN_001afa20_typed((*(f32 *)(iVar12 + 8)),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0)),(void*)(iVar1 + 0x6c));
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
    uVar3 = FUN_001ad910(*(u32 *)(*(int *)((u8 *)DAT_0086edf4_abs + iVar11) + 0x1e0));
    uVar4 = FUN_001ad920(*(u32 *)
                          (*(int *)((u8 *)DAT_0086edf4_abs + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(&uStack_30,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4_abs + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    uVar5 = FUN_0044f120(*(RwV3d *)(*(int *)((u8 *)DAT_0086ef08 + *(char *)(iVar1 + 1) * 0x1c0) + 0x100));
    uVar6 = FUN_0044f170(*(RwV3d *)(*(int *)((u8 *)DAT_0086ef08 + iVar11) + 0x100));
    lVar10 = FUN_00453ed0(*(u8 *)(iVar1 + 1),uVar3,uVar4,(u32 *)&uStack_30,uVar5,uVar6);
    if (lVar10 == 1) {
      *(u8 *)(iVar1 + 4) = 6;
    }
    ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 2;
    break;
  case 6:
    if (*(int *)(iVar1 + 0x94) != 0) {
      iVar11 = *(int *)(iVar1 + 0x94) + -1;
      *(int *)(iVar1 + 0x94) = iVar11;
      *(float *)(iVar1 + 0x6c) = (float)(int)*(short *)(iVar9 * 4 + iVar1 + 0xc98) * 800.0f;
      *(float *)(iVar1 + 0x74) =
           (float)(int)*(short *)(*(int *)(iVar1 + 0x94) * 4 + iVar1 + 0xc9a) * 800.0f;
      uVar7 = FUN_0044f120(*(RwV3d *)(iVar1 + 0x6c));
      uVar8 = FUN_0044f170(*(RwV3d *)(iVar1 + 0x6c));
      FUN_001bf220(auStack_20,uVar7,uVar8);
      *(YVec3f *)(iVar1 + 0x6c) = *(YVec3f *)auStack_20;
      *(u8 *)(iVar1 + 4) = 7;
    }
    else {
      *(u8 *)(iVar1 + 4) = 8;
    }
    break;
  case 7:
    FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10 + iVar11),0);
    lVar10 = FUN_001afa20_typed((*(f32 *)(iVar12 + 0xc)),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0)),(void*)(iVar1 + 0x6c));
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

/* W409 measured: baseline NONMATCHING 1696/1760 nd1190; local DAT_0086edf4_abs + DAT_0086ef10_abs uses 1752/1760 nd1125. */
// FUN_0044B7D0 NONMATCHING

void FUN_0044b7d0(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int lVar5;
  int lVar6;
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
      FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar1 + 1) * 0x1c0),0);
      FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar1 + 1) * 0x1c0));
      *(char *)(iVar1 + 7) = (char)*(u32 *)(iVar2 + 100);
      *(u8 *)(iVar1 + 4) = 9;
    }
    else {
      iVar7 = FUN_00488f30();
      bVar9 = (u8)((iVar7 % 200) / 0x19);
      iVar7 = FUN_00488f30();
      sVar8 = (short)((iVar7 % 4000) / 10);
      FUN_001ad940(afStack_10,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4_abs + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
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
      FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar1 + 1) * 0x1c0),
                   *(u32 *)(iVar2 + 0x60));
      lVar5 = FUN_001afa20_typed((*(u32 *)(iVar2 + 0x48)),(void*)(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar1 + 1) * 0x1c0)),(void*)(afStack_10))
      ;
      if (lVar5 != 0) {
        iVar7 = *(int *)(iVar2 + 0x58);
        iVar4 = FUN_00488f30();
        FUN_001aff70_typed((void *)(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar1 + 1) * 0x1c0)),iVar7 + (short)(iVar4 % (*(int *)(iVar2 + 0x5c) - iVar7)));
        *(u8 *)(iVar1 + 4) = 2;
      }
    }
    break;
  case 2:
    cVar3 = FUN_0044ffb0(param_1);
    if (cVar3 == '\x01') {
      FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar1 + 1) * 0x1c0),0);
      FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar1 + 1) * 0x1c0));
      *(char *)(iVar1 + 7) = (char)*(u32 *)(iVar2 + 100);
      *(u8 *)(iVar1 + 4) = 9;
    }
    else {
      lVar5 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar1 + 1) * 0x1c0));
      if (lVar5 == 0) {
        *(u8 *)(iVar1 + 4) = 1;
      }
    }
    break;
  case 5:
    FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar1 + 1) * 0x1c0),0);
    iVar7 = *(char *)(iVar1 + 1) * 0x1c0;
    lVar5 = FUN_001afa20_typed((*(u32 *)(iVar2 + 0x48)),(void*)(*(u32 *)((u8 *)DAT_0086ef10_abs + iVar7)),(void*)(*(int *)((u8 *)DAT_0086ef08 + iVar7) + 0x100));
    if (lVar5 == 0) {
      return;
    }
    *(u8 *)(iVar1 + 4) = 6;
  case 6:
    lVar5 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar1 + 1) * 0x1c0));
    if (lVar5 == 0) {
      *(u8 *)(iVar1 + 4) = 5;
      lVar5 = FUN_0044f120(*(RwV3d *)(*(int *)((u8 *)DAT_0086ef08 + *(char *)(iVar1 + 1) * 0x1c0) + 0x100));
      FUN_001ad940(auStack_20,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4_abs + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
      lVar6 = FUN_0044f120(*(RwV3d *)(auStack_20));
      if (lVar5 == lVar6) {
        lVar5 = FUN_0044f170(*(RwV3d *)(*(int *)((u8 *)DAT_0086ef08 + *(char *)(iVar1 + 1) * 0x1c0) + 0x100));
        FUN_001ad940(auStack_30,
                     *(u32 *)(*(int *)((u8 *)DAT_0086edf4_abs + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0)
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

#pragma push
/* W373 singles base 4381/5952; loop 4381/5952; common 4521/6152; life 4379/5952; propagation 4377/5944; strength 4381/5952; dead 4377/5944; pair life+prop 4376/5944; life+dead 4376/5944; prop+dead 4377/5944. */
#pragma opt_lifetimes on
#pragma opt_propagation off
/* W414 YMisc negative: FUN_00452a70 is present after the 0x15, 0x14, and outer FUN_004523c0 paths in retail; direct-call source variants measured object 6028/5968 (over window), with no under-window shape found. */
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
  iVar12 = *(int *)((u8 *)DAT_0086ef2c_abs + iVar18);
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
        if ((DAT_008717e8_rows[iVar12 * 0x70] != 0) && (DAT_008717f4_rows[iVar12 * 0x70] != 0)) {
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
                   *(u32 *)(DAT_008717f4_rows[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0));
      *(u32 *)(iVar3 + 0x1c) = uStack_80[0];
      *(u32 *)(iVar3 + 0x20) = uStack_80[1];
      *(u32 *)(iVar3 + 0x24) = uStack_80[2];
      *(u8 *)(iVar3 + 3) = 0x13;
    }
    lVar15 = FUN_004523c0(param_1,*(u8 *)(iVar3 + 1));
    if (lVar15 == 1) {
      return;
    }
    sVar10 = FUN_001ad910(*(u32 *)(DAT_008717f4_rows[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0));
    sVar11 = FUN_001ad920(*(u32 *)(DAT_008717f4_rows[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0));
    iVar12 = FUN_001b9120_u32();
    if (*(char *)(iVar12 + sVar11 * 0x100 + sVar10 * 0x10 + 0x4a) == '\b') {
      FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar3 + 1) * 0x1c0));
      FUN_001ad940(uStack_90,
                   *(u32 *)(DAT_008717f4_rows[*(char *)(iVar3 + 0x18) * 0x70] + 0x1e0));
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

#pragma pop
#pragma opt_lifetimes reset
#pragma opt_propagation reset
// FUN_0044D600 NONMATCHING

void FUN_0044d600(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  u32 uVar5;
  int lVar6;
  u32 uVar7;
  YVec3f a[2];
  u8 auStack_100 [16];
  u8 auStack_f0 [16];
  u8 auStack_e0 [16];
  u8 auStack_d0 [16];
  u8 auStack_c0 [16];
  u8 auStack_b0 [16];
  u8 auStack_a0 [16];
  u8 auStack_90 [16];
  u8 auStack_80 [16];
  YVec3f v;
  YVec3f spawn;
  u8 auStack_60 [16];
  u8 auStack_50 [16];
  u8 auStack_40 [16];
  
  
  iVar1 = *(int *)(param_1 + 0x3c);
  iVar2 = DAT_007ce290;
  cVar3 = *(char *)(iVar1 + 3);
  switch (cVar3) {
  case '\0': {
      FUN_001ad940(&spawn,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
      spawn.y = spawn.y + 100.0f;
      iVar4 = FUN_001b9120_u32();
      uVar5 = FUN_001a91b0_ret(*(u32 *)(iVar4 + 0x1208),&spawn);
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
  break;
  case '\x01': {
      if (*(char *)(iVar1 + 7) < '\x01') {
        *(u8 *)(iVar1 + 3) = 2;
      }
      else {
        *(char *)(iVar1 + 7) = *(char *)(iVar1 + 7) + -1;
      }
  }
  break;
  case '\x02': {
      FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
      FUN_001ad940(auStack_40,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
      FUN_001ad940(auStack_50,*(u32 *)(DAT_008717f4_rows[0] + 0x1e0));
      uVar7 = FUN_0044f270_ret((float *)(auStack_40),(float *)(auStack_50));
      *(u32 *)(iVar1 + 0x44) = uVar7;
      FUN_001ad940(auStack_60,*(u32 *)(DAT_008717f4_rows[0] + 0x1e0));
      if (FUN_00454520((float *)auStack_60,*(u8 *)(iVar1 + 1)) == 0) {
        *(u8 *)(iVar1 + 3) = 4;
      }
      else {
        FUN_001ad940(&v,*(u32 *)(DAT_008717f4_rows[0] + 0x1e0));
        a[1] = v;
        a[0] = a[1];
        a[0].y = 400.0f;
        a[1].y = -400.0f;
        FUN_001acc30_typed((void*)a,(void*)(&v));
        if (v.y > 50.0f) {
          FUN_004543c0(*(u8 *)(iVar1 + 1),4);
          ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 0;
        }
        else {
          FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0),0);
          lVar6 = FUN_001afa20_typed((*(u32 *)(iVar2 + 0x4c)),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0)),(void*)(&v));
          if (lVar6 != 0) {
            *(char *)(iVar1 + 8) = (char)*(u32 *)(iVar2 + 0x68);
            *(u8 *)(iVar1 + 3) = 3;
          }
        }
      }
  }
  break;
  case '\x03': {
      cVar3 = FUN_0044f300(*(u8 *)(iVar1 + 1));
      if (cVar3 != '\x01') {
        uVar5 = FUN_00318b60(*(u32 *)
                              (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x128));
        FUN_001ad940(auStack_80,*(u32 *)(DAT_008717f4_rows[0] + 0x1e0));
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
  break;
  case '\x04': {
      FUN_001ad940(auStack_90,*(u32 *)(DAT_008717f4_rows[0] + 0x1e0));
      lVar6 = FUN_00454400((f32*)(auStack_90),(char)(*(u8 *)(iVar1 + 1)));
      if (lVar6 == 0) {
        FUN_004543c0(*(u8 *)(iVar1 + 1),4);
        ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 0;
      }
      else {
        FUN_001ad940(auStack_a0,
                     *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0)
                    );
        FUN_001ad940(auStack_b0,*(u32 *)(DAT_008717f4_rows[0] + 0x1e0));
        lVar6 = FUN_0044f1c0(*(float *)(iVar2 + 0x54) * 3.0f,(float *)auStack_a0,(float *)auStack_b0);
        if (lVar6 == 0) {
          FUN_004543c0(*(u8 *)(iVar1 + 1),4);
          ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 0;
        }
        else {
          FUN_001ad940(auStack_c0,*(u32 *)(DAT_008717f4_rows[0] + 0x1e0));
          if (FUN_00454520((float *)auStack_c0,*(u8 *)(iVar1 + 1)) == 1) {
            FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
            *(u8 *)(iVar1 + 3) = 2;
          }
          else {
            uVar5 = FUN_00318b60(*(u32 *)
                                  (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x128));
            FUN_001ad940(auStack_d0,*(u32 *)(DAT_008717f4_rows[0] + 0x1e0));
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
  break;
  case '\x05': {
      FUN_001ad940(auStack_e0,*(u32 *)(DAT_008717f4_rows[0] + 0x1e0));
      if (FUN_00454520((float *)auStack_e0,*(u8 *)(iVar1 + 1)) == 1) {
        FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
        *(u8 *)(iVar1 + 3) = 2;
      }
      else {
        uVar5 = FUN_00318b60(*(u32 *)
                              (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x128));
        FUN_001ad940(auStack_f0,*(u32 *)(DAT_008717f4_rows[0] + 0x1e0));
        lVar6 = FUN_001c6450(*(u32 *)(iVar2 + 0x50),*(u32 *)(iVar2 + 0x44),uVar5,
                             auStack_f0);
        if (lVar6 == 1) {
          FUN_004543c0(*(u8 *)(iVar1 + 1),5);
        }
        else {
          lVar6 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
          if (lVar6 == 0) {
            FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
            FUN_001ad940(auStack_100,*(u32 *)(DAT_008717f4_rows[0] + 0x1e0));
            FUN_001b0020_typed((u32)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0)),(void*)(auStack_100),(s32)(5));
            *(u8 *)(iVar1 + 3) = 4;
          }
        }
      }
  }
  break;
  case '\a':
  case '\b':
    break;
  case '\x18': {
    FUN_00454f50(*(u8 *)(iVar1 + 1),*(u8 *)(iVar1 + 0x18));
  }
  break;
  case '\x19': {
    lVar6 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0));
    if (lVar6 == 0) {
      FUN_004543c0(*(u8 *)(iVar1 + 1),4);
      ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 0;
    }
  }
  break;
  }
  return;
}

// FUN_0044DFC0 NONMATCHING

void FUN_0044dfc0(int param_1)

{
  char cVar1;
  int iVar2;
  u32 uVar3;
  int lVar4;
  u32 uVar5;
  int iVar6;
  u8 bVar7;
  
  iVar2 = *(int *)((int)param_1 + 0x3c);
  cVar1 = *(char *)(iVar2 + 5);
  switch (cVar1) {
  case '\0':{
    FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
    FUN_001b0240(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0),0);
    if (*(int *)(iVar2 + 0xc) != 0) {
      *(u32 *)(iVar2 + 0xc) = 0;
    }
    lVar4 = FUN_001c7b10_typed((const void *)(DAT_008717a0_bytes + *(char *)(iVar2 + 0x18) * 0x1c0));
    if (lVar4 != 1) {
      lVar4 = FUN_001d8d80_int((int)(DAT_008717a0_bytes + *(char *)(iVar2 + 0x18) * 0x1c0));
      if (lVar4 == 0) {
        lVar4 = FUN_002ff790_typed((void *)DAT_008717e8_rows[*(char *)(iVar2 + 0x18) * 0x70]);
        if (lVar4 != 1) {
          uVar3 = (u32)FUN_001d8b00_typed((void *)(param_1),(void *)(DAT_008717a0_bytes + *(char *)(iVar2 + 0x18) * 0x1c0),(void *)((u8 *)DAT_0086eda0 + *(char *)(iVar2 + 1) * 0x1c0));
          *(u32 *)(iVar2 + 0xc) = uVar3;
          *(u8 *)(iVar2 + 5) = 1;
          FUN_0043a1a0(*(u8 *)(iVar2 + 0x18),*(u8 *)(iVar2 + 1));
        }
        else {
          FUN_004543c0(*(u8 *)(iVar2 + 1),4);
          ((u8 *)DAT_0095c210)[*(char *)(iVar2 + 1)] = 0;
        }
      }
      else {
        uVar5 = (u32)FUN_001d8d80_int((int)((u8 *)DAT_008717a0 + *(char *)(iVar2 + 0x18) * 0x1c0));
        FUN_001d8e60_typed((void *)(uVar5),(void *)(0),(void *)((u8 *)DAT_0086eda0 + *(char *)(iVar2 + 1) * 0x1c0));
        uVar3 = (u32)FUN_001d8d80_int((int)((u8 *)DAT_008717a0 + *(char *)(iVar2 + 0x18) * 0x1c0));
        *(u32 *)(iVar2 + 0xc) = uVar3;
        *(u8 *)(iVar2 + 5) = 1;
      }
    }
    else {
      lVar4 = FUN_001d8d80_int((int)((u8 *)DAT_008717a0 + *(char *)(iVar2 + 0x18) * 0x1c0));
      if (lVar4 == 0) {
        DAT_007ce6f4 = (short)*(char *)(iVar2 + 1);
        DAT_007ce6f0 = *(u8 *)(iVar2 + 0x18);
        *(u8 *)(iVar2 + 5) = 1;
        FUN_004532d0(1);
        FUN_00435060(1);
      }
    }
      break;
  }
  case '\x01':{
    lVar4 = FUN_00195460_int(*(u32 *)(iVar2 + 0xc));
    if (lVar4 == 0) {
      bVar7 = 0;
      iVar6 = *(char *)(iVar2 + 1) * 0x1c0;
      if ((*(int *)((u8 *)DAT_0086ede8 + iVar6) != 0) && (*(int *)((u8 *)DAT_0086edf4 + iVar6) != 0)) {
        bVar7 = 1;
      }
      if (bVar7) {
        if (*(int *)((u8 *)DAT_0086ef2c + iVar6) != 4) {
          FUN_004543c0(*(u8 *)(iVar2 + 1),4);
          ((u8 *)DAT_0095c210)[*(char *)(iVar2 + 1)] = 0;
        }
        else {
          FUN_001aaac0_typed((void*)(*(u32 *)(iVar2 + 0x10)),0);
          FUN_004543c0(*(u8 *)(iVar2 + 1),3);
        }
      }
      else {
        *(u8 *)(iVar2 + 2) = 6;
      }
    }
      break;
  }
  case '\x02':{
    if (*(int *)(iVar2 + 0xc) != 0) {
      *(u32 *)(iVar2 + 0xc) = 0;
    }
    lVar4 = FUN_001d8d80_int((int)((u8 *)DAT_008717a0 + *(char *)(iVar2 + 0x18) * 0x1c0));
    *(int *)(iVar2 + 0xc) = lVar4;
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
      break;
  }
  case '\x03':{
    lVar4 = FUN_00195460_int(*(u32 *)(iVar2 + 0xc));
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
      break;
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






u32 FUN_0044e560(int param_1)

{
  int iVar1;
  u8 uVar2;
  u32 iVar3;
  int iVar4;
  u32 lVar5;
  float *puVar6;
  u32 uVar7;
  u32 uVar8;
  short sVar9;
  float fVar10;
  u16 uVar11;
  RwV3d candidate;
  
  iVar1 = *(int *)((int)param_1 + 0x3c);
  uVar8 = 0;
  uVar7 = 0xffffffffffffffff;
  sVar9 = 0;
  puVar6 = (float *)
           (DAT_007ce290 + *(int *)((u8 *)DAT_0086ef2c + *(char *)(iVar1 + 1) * 0x1c0) * 0x40);
  uVar2 = FUN_0044f120(*(RwV3d *)(iVar1 + 0x60));
  *(u8 *)(iVar1 + 0x5c) = uVar2;
  uVar2 = FUN_0044f170(*(RwV3d *)(iVar1 + 0x60));
  *(u8 *)(iVar1 + 0x5d) = uVar2;
  do {
    iVar3 = (FUN_00488f30() % 200) / 0x19;
    iVar4 = FUN_00488f30();
    fVar10 = (float)(int)(short)((((u32)iVar4) % 4000) / 10) + 400.0f;
    if (fVar10 >= 2.1474836e+09f) {
      uVar11 = (u16)(int)(fVar10 - 2.1474836e+09f);
    }
    else {
      uVar11 = (u16)(int)fVar10;
    }
    *(u16 *)(iVar1 + 0x92) = uVar11;
    switch((char)iVar3) {
    case '\0':
      candidate.x = *(float *)(iVar1 + 0x60);
      candidate.y = *(float *)(iVar1 + 0x64);
      candidate.z = *(float *)(iVar1 + 0x68) - (float)*(u16 *)(iVar1 + 0x92);
      lVar5 = FUN_0044f060(*puVar6,param_1,(float *)&candidate);
      if (((lVar5 == 1) && (lVar5 = FUN_00454400((f32 *)&candidate,(char)(*(u8 *)(iVar1 + 1))), lVar5 == 1)
          ) && (lVar5 = FUN_00454d00(candidate), lVar5 == 1)) {
        uVar2 = FUN_0044f120(candidate);
        *(u8 *)(iVar1 + 0x78) = uVar2;
        uVar2 = FUN_0044f170(candidate);
        *(u8 *)(iVar1 + 0x79) = uVar2;
        if (((s32)*(char *)(iVar1 + 0x5c) == (u32)*(u8 *)(iVar1 + 0x78)) &&
           ((s32)*(char *)(iVar1 + 0x5d) == (u32)*(u8 *)(iVar1 + 0x79))) {
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
      candidate.y = *(float *)(iVar1 + 0x64);
      candidate.z = *(float *)(iVar1 + 0x68);
      candidate.x = *(float *)(iVar1 + 0x60) - (float)*(u16 *)(iVar1 + 0x92);
      lVar5 = FUN_0044f060(*puVar6,param_1,(float *)&candidate);
      if (((lVar5 == 1) && (lVar5 = FUN_00454400((f32 *)&candidate,(char)(*(u8 *)(iVar1 + 1))), lVar5 == 1)
          ) && (lVar5 = FUN_00454d00(candidate), lVar5 == 1)) {
        uVar2 = FUN_0044f120(candidate);
        *(u8 *)(iVar1 + 0x78) = uVar2;
        uVar2 = FUN_0044f170(candidate);
        *(u8 *)(iVar1 + 0x79) = uVar2;
        if (((s32)*(char *)(iVar1 + 0x5c) == (u32)*(u8 *)(iVar1 + 0x78)) &&
           ((s32)*(char *)(iVar1 + 0x5d) == (u32)*(u8 *)(iVar1 + 0x79))) {
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
      candidate.x = *(float *)(iVar1 + 0x60);
      candidate.y = *(float *)(iVar1 + 0x64);
      candidate.z = *(float *)(iVar1 + 0x68) + (float)*(u16 *)(iVar1 + 0x92);
      lVar5 = FUN_0044f060(*puVar6,param_1,(float *)&candidate);
      if (((lVar5 == 1) && (lVar5 = FUN_00454400((f32 *)&candidate,(char)(*(u8 *)(iVar1 + 1))), lVar5 == 1)
          ) && (lVar5 = FUN_00454d00(candidate), lVar5 == 1)) {
        uVar2 = FUN_0044f120(candidate);
        *(u8 *)(iVar1 + 0x78) = uVar2;
        uVar2 = FUN_0044f170(candidate);
        *(u8 *)(iVar1 + 0x79) = uVar2;
        if (((s32)*(char *)(iVar1 + 0x5c) == (u32)*(u8 *)(iVar1 + 0x78)) &&
           ((s32)*(char *)(iVar1 + 0x5d) == (u32)*(u8 *)(iVar1 + 0x79))) {
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
      candidate.y = *(float *)(iVar1 + 0x64);
      candidate.z = *(float *)(iVar1 + 0x68);
      candidate.x = *(float *)(iVar1 + 0x60) + (float)*(u16 *)(iVar1 + 0x92);
      lVar5 = FUN_0044f060(*puVar6,param_1,(float *)&candidate);
      if (((lVar5 == 1) && (lVar5 = FUN_00454400((f32 *)&candidate,(char)(*(u8 *)(iVar1 + 1))), lVar5 == 1)
          ) && (lVar5 = FUN_00454d00(candidate), lVar5 == 1)) {
        uVar2 = FUN_0044f120(candidate);
        *(u8 *)(iVar1 + 0x78) = uVar2;
        uVar2 = FUN_0044f170(candidate);
        *(u8 *)(iVar1 + 0x79) = uVar2;
        if (((s32)*(char *)(iVar1 + 0x5c) == (u32)*(u8 *)(iVar1 + 0x78)) &&
           ((s32)*(char *)(iVar1 + 0x5d) == (u32)*(u8 *)(iVar1 + 0x79))) {
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
      candidate.y = *(float *)(iVar1 + 0x64);
      fVar10 = (float)(*(u16 *)(iVar1 + 0x92) >> 1);
      candidate.x = *(float *)(iVar1 + 0x60) + fVar10;
      candidate.z = *(float *)(iVar1 + 0x68) - fVar10;
      lVar5 = FUN_0044f060(*puVar6,param_1,(float *)&candidate);
      if (((lVar5 == 1) && (lVar5 = FUN_00454400((f32 *)&candidate,(char)(*(u8 *)(iVar1 + 1))), lVar5 == 1)
          ) && (lVar5 = FUN_00454d00(candidate), lVar5 == 1)) {
        uVar2 = FUN_0044f120(candidate);
        *(u8 *)(iVar1 + 0x78) = uVar2;
        uVar2 = FUN_0044f170(candidate);
        *(u8 *)(iVar1 + 0x79) = uVar2;
        if (((s32)*(char *)(iVar1 + 0x5c) == (u32)*(u8 *)(iVar1 + 0x78)) &&
           ((s32)*(char *)(iVar1 + 0x5d) == (u32)*(u8 *)(iVar1 + 0x79))) {
          uVar7 = 4;
          *(u8 *)(iVar1 + 4) = 2;
          uVar8 = 1;
        }
      }
      break;
    case '\x05':
      candidate.y = *(float *)(iVar1 + 0x64);
      fVar10 = (float)(*(u16 *)(iVar1 + 0x92) >> 1);
      candidate.x = *(float *)(iVar1 + 0x60) + fVar10;
      candidate.z = *(float *)(iVar1 + 0x68) + fVar10;
      lVar5 = FUN_0044f060(*puVar6,param_1,(float *)&candidate);
      if (((lVar5 == 1) && (lVar5 = FUN_00454400((f32 *)&candidate,(char)(*(u8 *)(iVar1 + 1))), lVar5 == 1)
          ) && (lVar5 = FUN_00454d00(candidate), lVar5 == 1)) {
        uVar2 = FUN_0044f120(candidate);
        *(u8 *)(iVar1 + 0x78) = uVar2;
        uVar2 = FUN_0044f170(candidate);
        *(u8 *)(iVar1 + 0x79) = uVar2;
        if (((s32)*(char *)(iVar1 + 0x5c) == (u32)*(u8 *)(iVar1 + 0x78)) &&
           ((s32)*(char *)(iVar1 + 0x5d) == (u32)*(u8 *)(iVar1 + 0x79))) {
          uVar7 = 5;
          *(u8 *)(iVar1 + 4) = 2;
          uVar8 = 1;
        }
      }
      break;
    case '\x06':
      candidate.y = *(float *)(iVar1 + 0x64);
      fVar10 = (float)(*(u16 *)(iVar1 + 0x92) >> 1);
      candidate.x = *(float *)(iVar1 + 0x60) - fVar10;
      candidate.z = *(float *)(iVar1 + 0x68) - fVar10;
      lVar5 = FUN_0044f060(*puVar6,param_1,(float *)&candidate);
      if (((lVar5 == 1) && (lVar5 = FUN_00454400((f32 *)&candidate,(char)(*(u8 *)(iVar1 + 1))), lVar5 == 1)
          ) && (lVar5 = FUN_00454d00(candidate), lVar5 == 1)) {
        uVar2 = FUN_0044f120(candidate);
        *(u8 *)(iVar1 + 0x78) = uVar2;
        uVar2 = FUN_0044f170(candidate);
        *(u8 *)(iVar1 + 0x79) = uVar2;
        if (((s32)*(char *)(iVar1 + 0x5c) == (u32)*(u8 *)(iVar1 + 0x78)) &&
           ((s32)*(char *)(iVar1 + 0x5d) == (u32)*(u8 *)(iVar1 + 0x79))) {
          uVar7 = 6;
          *(u8 *)(iVar1 + 4) = 2;
          uVar8 = 1;
        }
      }
      break;
    case '\a':
      candidate.y = *(float *)(iVar1 + 0x64);
      fVar10 = (float)(*(u16 *)(iVar1 + 0x92) >> 1);
      candidate.x = *(float *)(iVar1 + 0x60) - fVar10;
      candidate.z = *(float *)(iVar1 + 0x68) + fVar10;
      lVar5 = FUN_0044f060(*puVar6,param_1,(float *)&candidate);
      if (((lVar5 == 1) && (lVar5 = FUN_00454400((f32 *)&candidate,(char)(*(u8 *)(iVar1 + 1))), lVar5 == 1)
          ) && (lVar5 = FUN_00454d00(candidate), lVar5 == 1)) {
        uVar2 = FUN_0044f120(candidate);
        *(u8 *)(iVar1 + 0x78) = uVar2;
        uVar2 = FUN_0044f170(candidate);
        *(u8 *)(iVar1 + 0x79) = uVar2;
        if (((s32)*(char *)(iVar1 + 0x5c) == (u32)*(u8 *)(iVar1 + 0x78)) &&
           ((s32)*(char *)(iVar1 + 0x5d) == (u32)*(u8 *)(iVar1 + 0x79))) {
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
  iVar2 = *(volatile /* Removing this qualifier loses FUN_0044f060 (MATCH nd0 -> MISMATCH nd8, size 188 -> 188) - measured W170. */ int *)(param_2 + 0x3c);
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
  int lVar3;
  int lVar4;
  u32 uVar5;
  char cVar6;
  int *piVar7;
  int iVar8;
  u32 uVar9;
  float fVar10;
  float fVar11;
  RwV3d target;
  RwV3d self;
  RwV3d first;
  RwV3d second;
  RwV3d delta;
  RwV3d target2;
  RwV3d self2;
  RwV3d first2;
  RwV3d second2;
  RwV3d delta2;
  RwV3d target3;
  RwV3d self3;
  RwV3d first3;
  RwV3d second3;
  RwV3d delta3;
  u8 auStack_90 [16];
  u8 auStack_80 [16];
  u8 auStack_50 [16];
  
  iVar1 = *(int *)(*(int *)(DAT_0086ef0c_abs + param_1 * 0x1c0) + 0x3c);
  uVar9 = 0;
  iVar8 = DAT_007ce290 + *(int *)(DAT_0086ef2c_abs + *(char *)(iVar1 + 1) * 0x1c0) * 0x40;
  if ((DAT_007ce6bc == '\x01') && (*(int *)(DAT_0086ef2c_abs + *(char *)(iVar1 + 1) * 0x1c0) == 2)) {
    uVar9 = 0;
  }
  else {
    FUN_001ad940(&target,*(u32 *)(*(u32 *)(DAT_008717f4_abs + *(char *)(iVar1 + 0x18) * 0x70) + 0x1e0));
    FUN_001ad940(&self,
                 *(u32 *)(*(int *)(DAT_0086edf4_abs + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    first = self;
    second = target;
    delta.x = first.x - second.x;
    delta.y = first.y - second.y;
    delta.z = first.z - second.z;
    fVar10 = (float)FUN_004c6ac0_vec(&delta);
    lVar3 = FUN_001c6d70_typed(*(u32 *)(iVar8 + 0x14),(u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0);
    if (lVar3 != 0) {
      lVar3 = FUN_001c6dd0_typed(*(u32 *)(iVar8 + 0x14),(u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0);
      if (*(char *)(iVar1 + 0x18) != lVar3) {
        FUN_001ad940(&target2,
                     *(u32 *)(*(u32 *)(DAT_008717f4_abs + *(char *)(iVar1 + 0x18) * 0x70) + 0x1e0));
        FUN_001ad940(&self2,
                     *(u32 *)(*(int *)(DAT_0086edf4_abs + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
        first2 = self2;
        second2 = target2;
        delta2.x = first2.x - second2.x;
        delta2.y = first2.y - second2.y;
        delta2.z = first2.z - second2.z;
        fVar11 = (float)FUN_004c6ac0_vec(&delta2);
        cVar6 = (char)lVar3;
        if (fVar11 < fVar10) {
          FUN_001ad940(auStack_50,
                       *(u32 *)(*(u32 *)(DAT_008717f4_abs + *(char *)(iVar1 + 0x18) * 0x70) + 0x1e0));
          lVar4 = FUN_00454400((f32*)(auStack_50),(char)(*(u8 *)(iVar1 + 1)));
          if (lVar4 == 1) {
            lVar4 = FUN_001c65e0_typed((void*)((u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0));
            if (lVar4 != 1) {
              lVar4 = FUN_0016f190_typed(0xc65);
              if (lVar4 == 0) {
                *(char *)(iVar1 + 0x18) = cVar6;
                uVar9 = 1;
                ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
                FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                *(u8 *)(iVar1 + 3) = 0x18;
              }
            }
            else {
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
          }
        }
        fVar11 = *(float *)(iVar8 + 4);
        piVar7 = (int *)(DAT_008717f4_abs + (int)lVar3 * 0x70);
        FUN_001ad940(&target3,*(u32 *)(*piVar7 + 0x1e0));
        FUN_001ad940(&self3,
                     *(u32 *)(*(int *)(DAT_0086edf4_abs + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
        first3 = self3;
        second3 = target3;
        delta3.x = first3.x - second3.x;
        delta3.y = first3.y - second3.y;
        delta3.z = first3.z - second3.z;
        fVar10 = (float)FUN_004c6ac0_vec(&delta3);
        if (fVar10 < fVar11) {
          uVar5 = FUN_00318b60(*(u32 *)
                                (*(int *)(DAT_0086edf4_abs + *(char *)(iVar1 + 1) * 0x1c0) + 0x128));
          FUN_001ad940(auStack_80,*(u32 *)(*piVar7 + 0x1e0));
          lVar3 = FUN_001c6450(*(u32 *)(iVar8 + 0x10),*(u32 *)(iVar8 + 0x14),uVar5,
                               auStack_80);
          if (lVar3 == 1) {
            FUN_001ad940(auStack_90,*(u32 *)(*piVar7 + 0x1e0));
            lVar3 = FUN_00454400((f32*)(auStack_90),(char)(*(u8 *)(iVar1 + 1)));
            if (lVar3 == 1) {
              iVar8 = *(char *)(iVar1 + 1) * 0x1c0;
              if (*(int *)(DAT_0086ef2c_abs + iVar8) == 3) {
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
                if (lVar3 != 1) {
                  lVar3 = FUN_0016f190_typed(0xc65);
                  if (lVar3 == 0) {
                    *(char *)(iVar1 + 0x18) = cVar6;
                    uVar9 = 1;
                    ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
                    FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                    *(u8 *)(iVar1 + 3) = 0x18;
                  }
                }
                else {
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
  u32 uVar2;
  char cVar3;
  int lVar4;
  u32 uVar5;
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
      if ((DAT_008717e8_rows[iVar9 * 0x70] != 0) && (DAT_008717f4_rows[iVar9 * 0x70] != 0)) {
        bVar7 = 1;
      }
      if (((bVar7) && (lVar4 = FUN_002ff790_typed((void *)DAT_008717e8_rows[iVar9 * 0x70]), lVar4 != 1)) &&
         (lVar4 = FUN_001c6d70_typed(*(u32 *)(iVar8 + 0x14),
                               (u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0), lVar4 != 0)) {
        uVar5 = FUN_00318b60(*(u32 *)
                              (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x128));
        FUN_001ad940(auStack_10,*(u32 *)(DAT_008717f4_rows[iVar9 * 0x70] + 0x1e0));
        lVar4 = FUN_001c6450(*(u32 *)(iVar8 + 0x10),*(u32 *)(iVar8 + 0x14),uVar5,
                             auStack_10);
        if (lVar4 == 1) {
          FUN_001ad940(auStack_20,*(u32 *)(DAT_008717f4_rows[iVar9 * 0x70] + 0x1e0));
          lVar4 = FUN_00454400((f32*)(auStack_20),(char)(*(u8 *)(iVar1 + 1)));
          if (lVar4 == 1) {
            uVar2 = (u8)FUN_001c6dd0_typed(*(u32 *)(iVar8 + 0x14),
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
                if (iVar9 != 0) {
                  cVar3 = FUN_00437e20(uVar6);
                  if (cVar3 == '\x01') {
                    FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                    *(u8 *)(iVar1 + 0x18) = uVar2;
                    ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
                    return 1;
                  }
                }
                else {
                  lVar4 = FUN_001c7130(*(u32 *)(iVar8 + 0x14),(u32)((u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0));
                  if (lVar4 == 1) {
                    FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                    *(u8 *)(iVar1 + 0x18) = 0;
                    ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
                    return 1;
                  }
                }
              }
              else {
                lVar4 = FUN_0016f190_typed(0xc65);
                if (lVar4 == 0) {
                  if (iVar9 != 0) {
                    cVar3 = FUN_00437e20(uVar6);
                    if (cVar3 == '\x01') {
                      *(u8 *)(iVar1 + 0x18) = uVar6;
                      ((u8 *)DAT_0095c210)[*(char *)(iVar1 + 1)] = 1;
                      FUN_004543c0(*(u8 *)(iVar1 + 1),3);
                      *(u8 *)(iVar1 + 3) = 0x18;
                      return 1;
                    }
                  }
                  else {
                    lVar4 = FUN_001c7130(*(u32 *)(iVar8 + 0x14),(u32)((u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0));
                    if (lVar4 == 1) {
                      *(u8 *)(iVar1 + 0x18) = 0;
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
#pragma push
/* W373 singles base 330/488; loop 330/488; common 327/500; life 330/488; propagation 330/488; strength 330/488; dead 330/488. */
#pragma opt_common_subs off
// FUN_0044FFB0 NONMATCHING

u32 FUN_0044ffb0(int param_1)

{
  int iVar1;
  int iVar2;
  int lVar3;
  u32 uVar4;
  u8 bVar5;
  u32 uVar6;
  u8 auStack_10 [16];
  
  iVar1 = *(int *)(param_1 + 0x3c);
  iVar2 = DAT_007ce290;
  uVar6 = 0;
  if (*(char *)(iVar1 + 0x41) == '\x01') {
    uVar6 = 0;
  }
  else {
    bVar5 = 0;
    if ((DAT_008717e8_rows[0] != 0) && (DAT_008717f4_rows[0] != 0)) {
      bVar5 = 1;
    }
    if (((bVar5) && (lVar3 = FUN_002ff790_typed((void *)(DAT_008717e8_rows[0])), lVar3 != 1)) &&
       (lVar3 = FUN_001c6d70_typed(*(u32 *)(iVar2 + 0x54),
                             (u8 *)DAT_0086eda0 + *(char *)(iVar1 + 1) * 0x1c0), lVar3 != 0)) {
      uVar4 = FUN_00318b60(*(u32 *)
                            (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x128));
      FUN_001ad940(auStack_10,*(u32 *)(DAT_008717f4_rows[0] + 0x1e0));
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

#pragma pop
#pragma opt_common_subs reset
// W418 YMisc3 negative: the 23 rejected case-order variants measured nd1688-1775/object2376 (window2432); retained order nd1666.
// FUN_004501B0 NONMATCHING

void FUN_004501b0(char param_1)

{
  char cVar1;
  int iVar2;
  char cVar3;
  long lVar4;
  u32 uVar5;
  int iVar6;
  u32 uVar7;
  float fVar8;
  float fVar9;
  YVec3f a[2];
  RwV3d selfCopy2;
  RwV3d targetCopy2;
  RwV3d delta2;
  RwV3d selfCopy;
  RwV3d targetCopy;
  RwV3d delta;
  u8 auStack_e0 [16];
  u8 auStack_d0 [16];
  u8 auStack_c0 [16];
  u8 auStack_b0 [16];
  u8 auStack_a0 [16];
  RwV3d target2;
  RwV3d self2;
  u8 auStack_70 [16];
  u8 auStack_60 [16];
  YVec3f v;
  u8 auStack_40 [16];
  RwV3d target;
  RwV3d self;
  
  
  iVar2 = *(int *)(*(int *)((u8 *)DAT_0086ef0c + param_1 * 0x1c0) + 0x3c);
  cVar3 = *(char *)(iVar2 + 1);
  iVar6 = DAT_007ce290 + *(int *)((u8 *)DAT_0086ef2c + cVar3 * 0x1c0) * 0x40;
  cVar1 = *(char *)(iVar2 + 3);
  switch (cVar1) {
  case '\x02':
    FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + cVar3 * 0x1c0));
    FUN_001ad940(&target,*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0)
                );
    FUN_001ad940(&self,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x1e0));
    selfCopy = self;
    targetCopy = target;
    delta.x = selfCopy.x - targetCopy.x;
    delta.y = selfCopy.y - targetCopy.y;
    delta.z = selfCopy.z - targetCopy.z;
    uVar7 = FUN_004c6ac0_vec(&delta);
    *(u32 *)(iVar2 + 0x44) = uVar7;
    FUN_001ad940(auStack_40,*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0)
                );
    lVar4 = FUN_00454520((float *)auStack_40,*(u8 *)(iVar2 + 1));
    if (lVar4 != 0) {
      FUN_001ad940(&v,
                   *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
      a[1] = v;
      a[0] = a[1];
      a[0].y = 400.0f;
      a[1].y = -400.0f;
      FUN_001acc30_typed((void*)a,(void*)(&v));
      if (v.y <= 50.0f) {
        FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0),0);
        lVar4 = FUN_001afa20_typed((*(u32 *)(iVar6 + 0xc)),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0)),(void*)(&v));
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
    else {
      *(u8 *)(iVar2 + 3) = 4;
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
      if (lVar4 != 1) {
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
      else {
        FUN_004543c0(*(u8 *)(iVar2 + 1),5);
      }
    }
    break;
  case '\x05':
    FUN_001ad940(auStack_c0,*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0)
                );
    lVar4 = FUN_00454520((float *)auStack_c0,cVar3);
    if (lVar4 != 1) {
      uVar5 = FUN_00318b60(*(u32 *)
                            (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x128));
      FUN_001ad940(auStack_d0,
                   *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
      lVar4 = FUN_001c6450(*(u32 *)(iVar6 + 0x10),*(u32 *)(iVar6 + 4),uVar5,auStack_d0
                          );
      if (lVar4 != 1) {
        lVar4 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
        if (lVar4 == 0) {
          FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
          FUN_001ad940(auStack_e0,
                       *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
          FUN_001b0020_typed((u32)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0)),(void*)(auStack_e0),(s32)(5));
          *(u8 *)(iVar2 + 3) = 4;
        }
      }
      else {
        FUN_004543c0(*(u8 *)(iVar2 + 1),5);
      }
    }
    else {
      FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
      *(u8 *)(iVar2 + 3) = 2;
    }
    break;
  case '\x04':
    FUN_001ad940(auStack_70,*(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0)
                );
    lVar4 = FUN_00454400((f32*)(auStack_70),(char)(cVar3));
    if (lVar4 != 0) {
      fVar8 = *(float *)(iVar6 + 0x14);
      FUN_001ad940(&target2,
                   *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
      FUN_001ad940(&self2,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x1e0));
      selfCopy2 = self2;
      targetCopy2 = target2;
      delta2.x = selfCopy2.x - targetCopy2.x;
      delta2.y = selfCopy2.y - targetCopy2.y;
      delta2.z = selfCopy2.z - targetCopy2.z;
      fVar9 = (float)FUN_004c6ac0_vec(&delta2);
      if (fVar9 < fVar8 * 3.0f) {
        FUN_001ad940(auStack_a0,
                     *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
        lVar4 = FUN_00454520((float *)auStack_a0,*(u8 *)(iVar2 + 1));
        if (lVar4 != 1) {
          uVar5 = FUN_00318b60(*(u32 *)
                                (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x128));
          FUN_001ad940(auStack_b0,
                       *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
          lVar4 = FUN_001c6450(*(u32 *)(iVar6 + 0x10),*(u32 *)(iVar6 + 4),uVar5,
                               auStack_b0);
          if (lVar4 != 1) {
            lVar4 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
            if (lVar4 == 0) {
              FUN_00454620(*(u8 *)(iVar2 + 1));
              *(u8 *)(iVar2 + 3) = 5;
            }
          }
          else {
            FUN_004543c0(*(u8 *)(iVar2 + 1),5);
          }
        }
        else {
          FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
          *(u8 *)(iVar2 + 3) = 2;
        }
      }
      else {
        FUN_004543c0(*(u8 *)(iVar2 + 1),4);
        ((u8 *)DAT_0095c210)[*(char *)(iVar2 + 1)] = 0;
      }
    }
    else {
      FUN_004543c0(*(u8 *)(iVar2 + 1),4);
      ((u8 *)DAT_0095c210)[*(char *)(iVar2 + 1)] = 0;
    }
    break;
  }
  return;
}

// W418 YMisc3 negative: the 23 rejected case-order variants measured nd1662-1797/object2412 (window2416); retained order nd1634.
// FUN_00450B30 NONMATCHING

void FUN_00450b30(char param_1)

{
  char cVar1;
  int iVar2;
  char cVar3;
  long lVar4;
  u32 uVar5;
  int iVar6;
  u32 uVar7;
  float fVar8;
  float fVar9;
  YVec3f a[2];
  RwV3d selfCopy2;
  RwV3d targetCopy2;
  RwV3d delta2;
  RwV3d selfCopy;
  RwV3d targetCopy;
  RwV3d delta;
  u8 auStack_e0 [16];
  u8 auStack_d0 [16];
  u8 auStack_c0 [16];
  u8 auStack_b0 [16];
  u8 auStack_a0 [16];
  RwV3d target2;
  RwV3d self2;
  u8 auStack_70 [16];
  u8 auStack_60 [16];
  YVec3f v;
  u8 auStack_40 [16];
  RwV3d target;
  RwV3d self;
  
  
  iVar2 = *(int *)(*(int *)((u8 *)DAT_0086ef0c + param_1 * 0x1c0) + 0x3c);
  cVar3 = *(char *)(iVar2 + 1);
  iVar6 = iGpffffb5a0 + *(int *)((u8 *)DAT_0086ef2c + cVar3 * 0x1c0) * 0x40;
  cVar1 = *(char *)(iVar2 + 3);
  switch (cVar1) {
  case '\a':
    FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10_abs + cVar3 * 0x1c0));
    FUN_001ad940(&target,*(u32 *)(((u8 *)DAT_008717f4_abs)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0)
                );
    FUN_001ad940(&self,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x1e0));
    selfCopy = self;
    targetCopy = target;
    delta.x = selfCopy.x - targetCopy.x;
    delta.y = selfCopy.y - targetCopy.y;
    delta.z = selfCopy.z - targetCopy.z;
    uVar7 = FUN_004c6ac0_vec(&delta);
    *(u32 *)(iVar2 + 0x44) = uVar7;
    FUN_001ad940(auStack_40,*(u32 *)(((u8 *)DAT_008717f4_abs)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0)
                );
    if (FUN_00454520((float *)auStack_40,*(u8 *)(iVar2 + 1)) == 0) {
      *(u8 *)(iVar2 + 3) = 9;
    }
    else {
      FUN_001ad940(&v,
                   *(u32 *)(((u8 *)DAT_008717f4_abs)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
      a[1] = v;
      a[0] = a[1];
      a[0].y = 400.0f;
      a[1].y = -400.0f;
      FUN_001acc30_typed((void*)a,(void*)(&v));
      if (v.y <= 50.0f) {
        FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar2 + 1) * 0x1c0),0);
        lVar4 = FUN_001afa20_typed((*(u32 *)(iVar6 + 0xc)),(void*)(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar2 + 1) * 0x1c0)),(void*)(&v));
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
                   *(u32 *)(((u8 *)DAT_008717f4_abs)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
      lVar4 = FUN_001c6450(*(u32 *)(iVar6 + 0x10),*(u32 *)(iVar6 + 4),uVar5,auStack_60
                          );
      if (lVar4 == 1) {
        FUN_004543c0(*(u8 *)(iVar2 + 1),5);
      }
      else {
        lVar4 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar2 + 1) * 0x1c0));
        if (lVar4 == 0) {
          *(u8 *)(iVar2 + 3) = 7;
        }
        if (*(char *)(iVar2 + 8) >= '\x01') {
          *(char *)(iVar2 + 8) = *(char *)(iVar2 + 8) + -1;
        }
        else {
          *(u8 *)(iVar2 + 3) = 7;
        }
      }
    }
    break;
  case '\n':
    FUN_001ad940(auStack_c0,*(u32 *)(((u8 *)DAT_008717f4_abs)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0)
                );
    if (FUN_00454520((float *)auStack_c0,cVar3) == 1) {
      FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar2 + 1) * 0x1c0));
      *(u8 *)(iVar2 + 3) = 7;
    }
    else {
      uVar5 = FUN_00318b60(*(u32 *)
                            (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x128));
      FUN_001ad940(auStack_d0,
                   *(u32 *)(((u8 *)DAT_008717f4_abs)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
      lVar4 = FUN_001c6450(*(u32 *)(iVar6 + 0x10),*(u32 *)(iVar6 + 4),uVar5,auStack_d0
                          );
      if (lVar4 == 1) {
        FUN_004543c0(*(u8 *)(iVar2 + 1),5);
      }
      else {
        lVar4 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar2 + 1) * 0x1c0));
        if (lVar4 == 0) {
          FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar2 + 1) * 0x1c0));
          FUN_001ad940(auStack_e0,
                       *(u32 *)(((u8 *)DAT_008717f4_abs)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
          FUN_001b0020_typed((u32)(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar2 + 1) * 0x1c0)),(void*)(auStack_e0),(s32)(5));
          *(u8 *)(iVar2 + 3) = 9;
        }
      }
    }
    break;
  case '\t':
    FUN_001ad940(auStack_70,*(u32 *)(((u8 *)DAT_008717f4_abs)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0)
                );
    lVar4 = FUN_00454400((f32*)(auStack_70),(char)(cVar3));
    if (lVar4 == 0) {
      FUN_004543c0(*(u8 *)(iVar2 + 1),4);
      ((u8 *)DAT_0095c210)[*(char *)(iVar2 + 1)] = 0;
    }
    else {
      fVar8 = *(float *)(iVar6 + 0x14);
      FUN_001ad940(&target2,
                   *(u32 *)(((u8 *)DAT_008717f4_abs)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
      FUN_001ad940(&self2,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x1e0));
      selfCopy2 = self2;
      targetCopy2 = target2;
      delta2.x = selfCopy2.x - targetCopy2.x;
      delta2.y = selfCopy2.y - targetCopy2.y;
      delta2.z = selfCopy2.z - targetCopy2.z;
      fVar9 = (float)FUN_004c6ac0_vec(&delta2);
      if (fVar9 < fVar8 * 3.0f) {
        FUN_001ad940(auStack_a0,
                     *(u32 *)(((u8 *)DAT_008717f4_abs)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
        if (FUN_00454520((float *)auStack_a0,*(u8 *)(iVar2 + 1)) == 1) {
          FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar2 + 1) * 0x1c0));
          *(u8 *)(iVar2 + 3) = 7;
        }
        else {
          uVar5 = FUN_00318b60(*(u32 *)
                                (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x128));
          FUN_001ad940(auStack_b0,
                       *(u32 *)(((u8 *)DAT_008717f4_abs)[*(char *)(iVar2 + 0x18) * 0x70] + 0x1e0));
          lVar4 = FUN_001c6450(*(u32 *)(iVar6 + 0x10),*(u32 *)(iVar6 + 4),uVar5,
                               auStack_b0);
          if (lVar4 == 1) {
            FUN_004543c0(*(u8 *)(iVar2 + 1),5);
          }
          else {
            lVar4 = FUN_001b0220(*(u32 *)((u8 *)DAT_0086ef10_abs + *(char *)(iVar2 + 1) * 0x1c0));
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
  int lVar10;
  int iVar11;
  short sVar12;
  int lVar13;
  short sVar14;
  short sVar15;
  int iVar16;
  int iVar17;
  int lVar18;
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
  iStack_6b0 = *(int *)(*(int *)(DAT_0086ef0c_abs + iVar7) + 0x3c);
  iStack_6ac = iStack_6b0 >> 0x1f;
  fVar20 = 0.0f;
  sStack_6a0 = 0;
  lVar18 = 1;
  sVar15 = -1;
  pfVar9 = (float *)(iGpffffb5a0 + *(int *)(DAT_0086ef2c_abs + iVar7) * 0x40);
  FUN_001ad940(&uStack_20,*(u32 *)(*(int *)(DAT_0086edf4_abs + iVar7) + 0x1e0));
  FUN_001ad940(&fStack_30,
               *(u32 *)(*(u32 *)(DAT_008717f4_abs + *(char *)(iStack_6b0 + 0x18) * 0x70) + 0x1e0));
  fStack_2c = 0.0f;
  uStack_80 = uStack_20;
  fStack_78 = fStack_18;
  uStack_40 = uStack_20;
  uVar2 = uStack_40;
  fStack_38 = fStack_18;
  uStack_40 = uStack_20;
  sVar14 = (short)(int)((*(float *)&uStack_40 + 400.0f) / 800.0f);
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
    if (sVar1 <= sStack_6a0) {
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

#pragma push
/* W373 singles base 398/600; loop 398/600; common 417/620; life 398/600; propagation 394/608; strength 398/600; dead 394/596; pair propagation+dead 394/608. */
#pragma opt_propagation off
#pragma opt_dead_assignments off
// FUN_00451D70 NONMATCHING

void FUN_00451d70(int param_1)

{
  u8 cVar1;
  int iVar2;
  u8 uVar3;
  u8 uVar4;
  int lVar5;
  YVec3f firstRaw;
  YVec3f firstPos;
  YVec3f secondRaw;
  YVec3f secondPos;
  YVec3f thirdPos;
  YVec3f output;
  
  iVar2 = *(int *)(param_1 + 0x3c);
  cVar1 = *(u8 *)(iVar2 + 0x8b);
  if ((cVar1 == 0) && (*(u8 *)(iVar2 + 0x8c) == 0)) {
    lVar5 = FUN_004514a0(*(u8 *)(iVar2 + 1));
    if (lVar5 == 0) {
      FUN_001b00c0(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar2 + 1) * 0x1c0));
      FUN_001ad940((float *)&firstRaw,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x1e0));
      firstPos = firstRaw;
      FUN_001ad940((float *)&secondRaw,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x1e0));
      secondPos = secondRaw;
      FUN_001bf220(&output,(int)((secondPos.x + 400.0f) / 800.0f) & 0xffff,
                   (int)((firstPos.z + 400.0f) / 800.0f) & 0xffff);
      *(YVec3f *)(iVar2 + 0x6c) = output;
      *(u8 *)(iVar2 + 3) = 0xf;
    }
  }
  else {
    uVar3 = FUN_001ad910(*(u32 *)
                          (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x1e0));
    uVar4 = FUN_001ad920(*(u32 *)
                          (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940((float *)&thirdPos,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar2 + 1) * 0x1c0) + 0x1e0));
    lVar5 = FUN_00453ed0(*(u8 *)(iVar2 + 1),uVar3,uVar4,(u32 *)&thirdPos,(char)cVar1,
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

#pragma pop
#pragma opt_propagation reset
#pragma opt_dead_assignments reset
#pragma push
#pragma opt_loop_invariants on
/* W212: first divergence is the prologue (ours 0x100-byte frame, retail 0x150);
 * the missing 0x50 bytes are live search-state/aggregate structure, not a transfer
 * from the scalar FUN_00431aa0 template. */
/* W373 singles base 683/912; loop 683/912; common 783/1016; life 683/912; propagation 674/908; strength 683/912; dead 674/908; pair propagation+dead 674/908. */
#pragma opt_propagation off
#pragma opt_dead_assignments off
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
  YVec3f mainPos;
  YVec3f savedPos;
  
  FUN_001ad940((float *)&mainPos,*(u32 *)(DAT_008717f4_rows[0] + 0x1e0));
  savedPos = mainPos;
  cVar8 = '\0';
  cVar1 = (char)(int)((mainPos.x + 400.0f) / 800.0f);
  cVar7 = (char)(int)((mainPos.z + 400.0f) / 800.0f);
  iVar10 = 0;
  do {
    if (0xf < iVar10) {
      if (cVar8 != '\0') {
        *param_1 = (float)unaff_s8_lo * 800.0f;
        param_1[1] = 0.0f;
        param_1[2] = (float)(int)cStack_60 * 800.0f;
      }
      else {
        *param_1 = savedPos.x;
        param_1[1] = savedPos.y;
        param_1[2] = savedPos.z;
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
#pragma opt_propagation reset
#pragma opt_dead_assignments reset
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
  u32 uVar9;
  int lVar10;
  int iVar11;
  int iVar12;
  int lVar13;
  float fVar14;
  float fVar15;
  RwV3d first;
  RwV3d second;
  RwV3d delta;
  RwV3d first2;
  RwV3d second2;
  RwV3d delta2;
  u8 auStack_70 [16];
  u8 auStack_60 [16];
  RwV3d target2;
  RwV3d self2;
  u8 auStack_30 [16];
  RwV3d target;
  RwV3d self;
  
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
        FUN_001ad940(&target,*(u32 *)(((u8 *)DAT_008717f4)[iVar12 * 0x70] + 0x1e0));
        FUN_001ad940(&self,
                     *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0)
                    );
        first = self;
        second = target;
        delta.x = first.x - second.x;
        delta.y = first.y - second.y;
        delta.z = first.z - second.z;
        fVar14 = (float)FUN_004c6ac0_vec(&delta);
        if (fVar14 < fVar15) {
          uVar9 = FUN_00318b60(*(u32 *)
                                (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x128));
          FUN_001ad940(auStack_30,*(u32 *)(((u8 *)DAT_008717f4)[iVar12 * 0x70] + 0x1e0));
          lVar10 = FUN_001c6450(*(u32 *)(iVar11 + 0x10),*(u32 *)(iVar11 + 0x14),uVar9,
                                auStack_30);
          if (lVar10 == 1) {
            fVar15 = *(float *)(iVar11 + 0x14);
            FUN_001ad940(&target2,
                         *(u32 *)(((u8 *)DAT_008717f4)[*(char *)(iVar1 + 0x18) * 0x70] + 0x1e0));
            FUN_001ad940(&self2,
                         *(u32 *)
                          (*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
            first2 = self2;
            second2 = target2;
            delta2.x = first2.x - second2.x;
            delta2.y = first2.y - second2.y;
            delta2.z = first2.z - second2.z;
            fVar14 = (float)FUN_004c6ac0_vec(&delta2);
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
  YVec3f auStack_40;
  YVec3f auStack_30;
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
  FUN_001ad940(&auStack_30,*(u32 *)(*piVar11 + 0x1e0));
  fStack_c = auStack_30.y - *(float *)(iVar1 + 0x20);
  FUN_001ad940(&auStack_40,*(u32 *)(*piVar11 + 0x1e0));
  fStack_8 = auStack_40.z - *(float *)(iVar1 + 0x24);
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

/* measured opt_loop_invariants on: 880/864 nd650; off: 864/864 nd109; + opt_lifetimes on: 864/864 nd77; retained */
#pragma opt_loop_invariants off
#pragma opt_lifetimes on
// FUN_00452F70

void FUN_00452f70(u32 *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int columnOffset;
  u32 uVar6;
  u32 uVar5;
  u32 uVar7;
  u32 uVar8;
  YVec3f position;
  YVec3f direction1;
  YVec3f direction2;
  YVec3f direction3;
  YVec3f direction4;
  u32 secondColumn;
  u32 secondRow;
  
  iVar1 = *(int *)(param_2 + 0x3c);
  for (uVar5 = 0; (int)uVar5 < 0x10; uVar5 = uVar5 + 1) {
    uVar6 = 0;
    iVar3 = uVar5 * 0x100;
    for (; (int)uVar6 < 0x10; uVar6 = uVar6 + 1) {
      columnOffset = uVar6 * 0x10;
      iVar4 = FUN_001b9120_u32();
      iVar2 = iVar3 + iVar4;
      iVar2 = iVar2 + columnOffset;
      if ((*(u8 *)(iVar2 + 0x49) == 1) &&
         (iVar4 = FUN_001b9120_u32(), iVar2 = iVar3 + iVar4, iVar2 = iVar2 + columnOffset,
         *(u8 *)(iVar2 + 0x4a) == 8)) {
        uVar7 = uVar6;
        uVar8 = uVar5;
        goto LAB_00453278;
      }
    }
  }
LAB_00453278:
  for (secondColumn = uVar7; (int)secondColumn < (int)(uVar7 + 2); secondColumn = secondColumn + 1) {
    secondRow = uVar8;
    columnOffset = secondColumn * 0x10;
    for (; (int)secondRow < (int)(uVar8 + 2); secondRow = secondRow + 1) {
      iVar3 = secondRow * 0x100;
      iVar2 = FUN_001b9120_u32();
      iVar2 = Yajima_AddIntOffsetFirst(columnOffset, iVar2);
      iVar2 = iVar2 + iVar3;
      if (((*(u8 *)(iVar2 + 0x53) & 1) != 0) &&
         (iVar2 = FUN_001b9120_u32(), iVar2 = Yajima_AddIntOffsetFirst(columnOffset, iVar2), iVar2 = iVar2 + iVar3,
         *(u8 *)(iVar2 + -0xb6) != 8)) {
        FUN_001bf220(&position,secondColumn,secondRow - 1);
        FUN_001bf220(&direction1,secondColumn,secondRow);
        *(YVec3f *)(iVar1 + 0x34) = direction1;
      }
      iVar2 = FUN_001b9120_u32();
      iVar2 = Yajima_AddIntOffsetFirst(columnOffset, iVar2);
      iVar2 = iVar2 + iVar3;
      if (((*(u8 *)(iVar2 + 0x53) & 2) != 0) &&
         (iVar2 = FUN_001b9120_u32(), iVar2 = Yajima_AddIntOffsetFirst(columnOffset, iVar2), iVar2 = iVar2 + iVar3,
         *(u8 *)(iVar2 + 0x3a) != 8)) {
        FUN_001bf220(&position,secondColumn - 1,secondRow);
        FUN_001bf220(&direction2,secondColumn,secondRow);
        *(YVec3f *)(iVar1 + 0x34) = direction2;
      }
      iVar2 = FUN_001b9120_u32();
      iVar2 = Yajima_AddIntOffsetFirst(columnOffset, iVar2);
      iVar2 = iVar2 + iVar3;
      if (((*(u8 *)(iVar2 + 0x53) & 4) != 0) &&
         (iVar2 = FUN_001b9120_u32(), iVar2 = Yajima_AddIntOffsetFirst(columnOffset, iVar2), iVar2 = iVar2 + iVar3,
         *(u8 *)(iVar2 + 0x14a) != 8)) {
        FUN_001bf220(&position,secondColumn,secondRow + 1);
        FUN_001bf220(&direction3,secondColumn,secondRow);
        *(YVec3f *)(iVar1 + 0x34) = direction3;
      }
      iVar2 = FUN_001b9120_u32();
      iVar2 = Yajima_AddIntOffsetFirst(columnOffset, iVar2);
      iVar2 = iVar2 + iVar3;
      if (((*(u8 *)(iVar2 + 0x53) & 8) != 0) &&
         (iVar2 = FUN_001b9120_u32(), iVar2 = Yajima_AddIntOffsetFirst(columnOffset, iVar2), iVar2 = iVar2 + iVar3,
         *(u8 *)(iVar2 + 0x5a) != 8)) {
        FUN_001bf220(&position,secondColumn + 1,secondRow);
        FUN_001bf220(&direction4,secondColumn,secondRow);
        *(YVec3f *)(iVar1 + 0x34) = direction4;
      }
    }
  }
  *(YVec3f *)param_1 = position;
}

#pragma opt_loop_invariants reset
#pragma opt_lifetimes reset
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

/* W212: first divergence is offset 40 (global-base setup and saved work pointer);
 * the 260-byte object deficit confirms a full four-direction path reconstruction,
 * not the matched FUN_00431aa0 dispatch idiom. */
#pragma push
/* W373 singles base 1697/2260; loop 1697/2260; common 1909/2600; life 1697/2260; propagation 1625/2208; strength 1697/2260; dead 1713/2252. */
#pragma opt_propagation off
// FUN_004534B0 NONMATCHING






u32 FUN_004534b0(char param_1)

{
  u8 bVar1;
  u8 *puVar2;
  u32 uVar3;
  u32 uVar4;
  int iVar5;
  int lVar6;
  u32 uVar7;
  s16 *cell;
  YVec3f position;
  
  puVar2 = *(u8 **)(*(int *)(DAT_0086ef0c_abs + param_1 * 0x1c0) + 0x3c);
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
      position.x = (float)bVar1 * 800.0f;
      position.z = (float)(int)((u8)puVar2[0x79] - 1) * 800.0f;
      lVar6 = FUN_00454400((f32*)&position,(char)(puVar2[1]));
      if ((lVar6 == 1) || (*(int *)(DAT_0086ef2c_abs + (char)puVar2[1] * 0x1c0) == 4)) {
        uVar7 = (u32)(u8)puVar2[0x78] + ((u8)puVar2[0x79] - 1) * 0x10 & 0xff;
        cell = (s16 *)(puVar2 + uVar7 * 8 + 0x98);
        if ((cell[0] == 0) && (cell[1] == 0)) {
          cell[0] = (u16)(u8)puVar2[0x78];
          cell[1] = (u8)puVar2[0x79] - 1;
          cell[2] = (u16)(u8)puVar2[0x78];
          cell[3] = (u16)(u8)puVar2[0x79];
          *(u32 *)(puVar2 + *(int *)(puVar2 + 0x94) * 4 + 0x898) = uVar7;
          *(int *)(puVar2 + 0x94) = *(int *)(puVar2 + 0x94) + 1;
          if ((cell[0] == (u16)(u8)puVar2[0x8b]) &&
             (cell[1] == (u16)(u8)puVar2[0x8c])) {
            uVar3 = uVar3 & 0xff;
            cell = (s16 *)(puVar2 + uVar3 * 8 + 0x98);
            cell[0] = (u16)(u8)puVar2[0x8b];
            cell[1] = (u16)(u8)puVar2[0x8c];
            cell[2] = (u16)(u8)puVar2[0x8b];
            cell[3] = (u8)puVar2[0x8c] + 1;
            return 2;
          }
        }
      }
    }
    bVar1 = puVar2[0x78];
    iVar5 = FUN_001b9120_u32();
    if ((*(u8 *)(iVar5 + (u32)(u8)puVar2[0x79] * 0x100 + (u32)bVar1 * 0x10 + 0x53) & 2) != 0)
    {
      position.x = (float)(int)(bVar1 - 1) * 800.0f;
      position.z = (float)(u8)puVar2[0x79] * 800.0f;
      lVar6 = FUN_00454400((f32*)&position,(char)(puVar2[1]));
      if ((lVar6 == 1) || (*(int *)(DAT_0086ef2c_abs + (char)puVar2[1] * 0x1c0) == 4)) {
        if ((*(s16 *)(puVar2 + (((u8)puVar2[0x78] - 1) + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x98) == 0) &&
            (*(s16 *)(puVar2 + (((u8)puVar2[0x78] - 1) + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x9a) == 0)) {
          *(s16 *)(puVar2 + (((u8)puVar2[0x78] - 1) + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x98) = (short)((u8)puVar2[0x78] - 1);
          *(s16 *)(puVar2 + (((u8)puVar2[0x78] - 1) + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x9a) = (u16)(u8)puVar2[0x79];
          *(s16 *)(puVar2 + (((u8)puVar2[0x78] - 1) + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x9c) = (u16)(u8)puVar2[0x78];
          *(s16 *)(puVar2 + (((u8)puVar2[0x78] - 1) + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x9e) = (u16)(u8)puVar2[0x79];
          *(u32 *)(puVar2 + *(int *)(puVar2 + 0x94) * 4 + 0x898) =
              ((u8)puVar2[0x78] - 1) + (u32)(u8)puVar2[0x79] * 0x10;
          *(int *)(puVar2 + 0x94) = *(int *)(puVar2 + 0x94) + 1;
          if ((*(s16 *)(puVar2 + (((u8)puVar2[0x78] - 1) + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x98) == (u16)(u8)puVar2[0x8b]) &&
             (*(s16 *)(puVar2 + (((u8)puVar2[0x78] - 1) + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x9a) == (u16)(u8)puVar2[0x8c])) {
            uVar3 = uVar3 & 0xff;
            cell = (s16 *)(puVar2 + uVar3 * 8 + 0x98);
            cell[0] = (u16)(u8)puVar2[0x8b];
            cell[1] = (u16)(u8)puVar2[0x8c];
            cell[2] = (u8)puVar2[0x8b] + 1;
            cell[3] = (u16)(u8)puVar2[0x8c];
            return 2;
          }
        }
      }
    }
    bVar1 = puVar2[0x78];
    iVar5 = FUN_001b9120_u32();
    if ((*(u8 *)(iVar5 + (u32)(u8)puVar2[0x79] * 0x100 + (u32)bVar1 * 0x10 + 0x53) & 8) != 0)
    {
      position.x = (float)(bVar1 + 1) * 800.0f;
      position.z = (float)(u8)puVar2[0x79] * 800.0f;
      lVar6 = FUN_00454400((f32*)&position,(char)(puVar2[1]));
      if ((lVar6 == 1) || (*(int *)(DAT_0086ef2c_abs + (char)puVar2[1] * 0x1c0) == 4)) {
        if ((*(s16 *)(puVar2 + ((u8)puVar2[0x78] + 1 + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x98) == 0) &&
            (*(s16 *)(puVar2 + ((u8)puVar2[0x78] + 1 + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x9a) == 0)) {
          *(s16 *)(puVar2 + ((u8)puVar2[0x78] + 1 + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x98) = (short)((u8)puVar2[0x78] + 1);
          *(s16 *)(puVar2 + ((u8)puVar2[0x78] + 1 + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x9a) = (u16)(u8)puVar2[0x79];
          *(s16 *)(puVar2 + ((u8)puVar2[0x78] + 1 + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x9c) = (u16)(u8)puVar2[0x78];
          *(s16 *)(puVar2 + ((u8)puVar2[0x78] + 1 + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x9e) = (u16)(u8)puVar2[0x79];
          *(u32 *)(puVar2 + *(int *)(puVar2 + 0x94) * 4 + 0x898) =
              (u8)puVar2[0x78] + 1 + (u32)(u8)puVar2[0x79] * 0x10;
          *(int *)(puVar2 + 0x94) = *(int *)(puVar2 + 0x94) + 1;
          if ((*(s16 *)(puVar2 + ((u8)puVar2[0x78] + 1 + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x98) == (u16)(u8)puVar2[0x8b]) &&
             (*(s16 *)(puVar2 + ((u8)puVar2[0x78] + 1 + (u32)(u8)puVar2[0x79] * 0x10) * 8 + 0x9a) == (u16)(u8)puVar2[0x8c])) {
            uVar3 = uVar3 & 0xff;
            cell = (s16 *)(puVar2 + uVar3 * 8 + 0x98);
            cell[0] = (u16)(u8)puVar2[0x8b];
            cell[1] = (u16)(u8)puVar2[0x8c];
            cell[2] = (u8)puVar2[0x8b] - 1;
            cell[3] = (u16)(u8)puVar2[0x8c];
            return 2;
          }
        }
      }
    }
    bVar1 = puVar2[0x78];
    iVar5 = FUN_001b9120_u32();
    if ((*(u8 *)(iVar5 + (u32)(u8)puVar2[0x79] * 0x100 + (u32)bVar1 * 0x10 + 0x53) & 4) != 0)
    {
      position.x = (float)bVar1 * 800.0f;
      position.z = (float)((u8)puVar2[0x79] + 1) * 800.0f;
      lVar6 = FUN_00454400((f32*)&position,(char)(puVar2[1]));
      if ((lVar6 == 1) || (*(int *)(DAT_0086ef2c_abs + (char)puVar2[1] * 0x1c0) == 4)) {
        if ((*(s16 *)(puVar2 + ((u32)(u8)puVar2[0x78] + ((u8)puVar2[0x79] + 1) * 0x10) * 8 + 0x98) == 0) &&
            (*(s16 *)(puVar2 + ((u32)(u8)puVar2[0x78] + ((u8)puVar2[0x79] + 1) * 0x10) * 8 + 0x9a) == 0)) {
          *(s16 *)(puVar2 + ((u32)(u8)puVar2[0x78] + ((u8)puVar2[0x79] + 1) * 0x10) * 8 + 0x98) = (u16)(u8)puVar2[0x78];
          *(s16 *)(puVar2 + ((u32)(u8)puVar2[0x78] + ((u8)puVar2[0x79] + 1) * 0x10) * 8 + 0x9a) = (short)((u8)puVar2[0x79] + 1);
          *(s16 *)(puVar2 + ((u32)(u8)puVar2[0x78] + ((u8)puVar2[0x79] + 1) * 0x10) * 8 + 0x9c) = (u16)(u8)puVar2[0x78];
          *(s16 *)(puVar2 + ((u32)(u8)puVar2[0x78] + ((u8)puVar2[0x79] + 1) * 0x10) * 8 + 0x9e) = (u16)(u8)puVar2[0x79];
          *(u32 *)(puVar2 + *(int *)(puVar2 + 0x94) * 4 + 0x898) =
              (u32)(u8)puVar2[0x78] + ((u8)puVar2[0x79] + 1) * 0x10;
          *(int *)(puVar2 + 0x94) = *(int *)(puVar2 + 0x94) + 1;
          if ((*(s16 *)(puVar2 + ((u32)(u8)puVar2[0x78] + ((u8)puVar2[0x79] + 1) * 0x10) * 8 + 0x98) == (u16)(u8)puVar2[0x8b]) &&
             (*(s16 *)(puVar2 + ((u32)(u8)puVar2[0x78] + ((u8)puVar2[0x79] + 1) * 0x10) * 8 + 0x9a) == (u16)(u8)puVar2[0x8c])) {
            uVar3 = uVar3 & 0xff;
            cell = (s16 *)(puVar2 + uVar3 * 8 + 0x98);
            cell[0] = (u16)(u8)puVar2[0x8b];
            cell[1] = (u16)(u8)puVar2[0x8c];
            cell[2] = (u16)(u8)puVar2[0x8b];
            cell[3] = (u8)puVar2[0x8c] - 1;
            return 2;
          }
        }
      }
    }
    uVar4 = 0;
  }
  return uVar4;
}

#pragma push
#pragma opt_loop_invariants on
// FUN_00453D90
void FUN_00453d90(char param_1)
{
  int iVar4;
  int bVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  short sVar2;
  int sVar4;
  int sVar5;
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
  bVar2 = *(volatile /* Removing this function's qualifier batch worsens FUN_00453d90 (NONMATCHING nd98 -> NONMATCHING nd113, size 320 -> 320) - measured W170. */ u8 *)(iVar4 + 0x8b);
  bVar1 = *(volatile /* Removing this function's qualifier batch worsens FUN_00453d90 (NONMATCHING nd98 -> NONMATCHING nd113, size 320 -> 320) - measured W170. */ u8 *)(iVar4 + 0x8c);
  iVar7 = *(int *)(iVar4 + 0x94);
  iVar8 = iVar7 * 4;
  iVar8 = iVar8 + iVar4;
  *(u16 *)(iVar8 + 0xc98) = bVar2;
  iVar7 = *(int *)(iVar4 + 0x94);
  iVar8 = iVar7 * 4;
  iVar8 = iVar8 + iVar4;
  *(u16 *)(iVar8 + 0xc9a) = bVar1;
  do {
    iVar7 = *(int *)(iVar4 + 0x94);
    iVar8 = iVar7 * 4 + iVar4;
    sVar2 = *(short *)(iVar8 + 0xc9a);
    iVar9 = (int)sVar2 << 4;
    iVar10 = *(short *)(iVar8 + 0xc98);
    iVar10 = iVar10 + iVar9;
    iVar9 = iVar4 + iVar10 * 8;
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
    if (iVar6 >= 100) {
      bVar5 = 1;
    }
  } while (bVar5 == 0);
}
#pragma pop

// FUN_00453ED0

u32
FUN_00453ed0(char param_1,char param_2,char param_3,u32 *param_4,char param_5,char param_6)

{
  int iVar1;
  int iVar2;
  char bVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  u32 uVar9;
  long lVar10;
  YVec3f vec;
  
  vec = *(YVec3f *)param_4;
  iVar1 = *(int *)(*(int *)(DAT_0086ef0c_abs + param_1 * 0x1c0) + 0x3c);
  *(char *)(iVar1 + 0x5c) = param_2;
  *(char *)(iVar1 + 0x78) = param_2;
  *(char *)(iVar1 + 0x5d) = param_3;
  *(char *)(iVar1 + 0x79) = param_3;
  *(YVec3f *)(iVar1 + 0x50) = vec;
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
  *(YVec3f *)(iVar1 + 0x60) = vec;
  if ((param_2 == param_5) && (param_3 == param_6)) {
    uVar9 = 0;
  }
  else {
    bVar3 = 0;
    do {
      cVar4 = FUN_004534b0(*(u8 *)(iVar1 + 1));
      iVar5 = *(int *)(*(int *)(DAT_0086eda0_bytes + *(char *)(iVar1 + 1) * 0x1c0 + 0x16c) + 0x3c);
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
      *(char *)(iVar5 + 0x78) = (char)*(s16 *)(iVar7 + 0x98);
      *(char *)(iVar5 + 0x79) = (char)*(s16 *)(iVar7 + 0x9a);
      if (cVar4 == '\x01') {
        cVar4 = '\x02';
        bVar3 = 1;
      }
    } while (cVar4 != '\x02');
    lVar10 = bVar3;
    if ((char)lVar10) {
      goto blocked;
    }
    FUN_00453d90(*(u8 *)(iVar1 + 1));
    uVar9 = 1;
    goto path_done;
blocked:
    uVar9 = 0;
path_done:
    ;
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

// FUN_004542C0

u32 FUN_004542c0(char param_1)

{
  u32 uVar2;
  u32 lVar1;
  u8 *puVar3;
  YVec3f vec;
  
  lVar1 = (*DAT_00960184_abs)(1,0x10,0x40000);
  if (lVar1 == 0) {
    return 0;
  }
  uVar2 = FUN_00194b80_u32(0,0x106f,DAT_006b4a30,FUN_004541f0,FUN_00454290,lVar1);
  puVar3 = (u8 *)lVar1;
  *puVar3 = 0;
  FUN_001ad940(&vec,*(u32 *)(*(int *)(DAT_0086edf4_abs + param_1 * 0x1c0) + 0x1e0));
  *(YVec3f *)(puVar3 + 4) = vec;
  FUN_001d0110_typed((void *)(DAT_0086eda0_bytes + param_1 * 0x1c0));
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

// FUN_00454400
u32 FUN_00454400(f32 *param_1,char param_2)
{
  u32 bVar1;
  int lVar2;
  int iVar3;
  YVec3f a[2];
  YVec3f v30;

  v30 = *(YVec3f *)param_1;
  iVar3 = *(int *)(*(int *)(DAT_0086ef0c_abs + param_2 * 0x1c0) + 0x3c);
  a[1] = v30;
  a[0] = a[1];
  a[0].y = 400.0f;
  a[1].y = -400.0f;
  if (*(int *)(DAT_0086ef2c_abs + *(char *)(iVar3 + 1) * 0x1c0) == 4) {
    return 1;
  }
  lVar2 = FUN_001acc30_typed((void*)a,(void*)&v30);
  if (lVar2 != 1) {
    goto no_hit;
  }
  return v30.y <= 50.0f;
no_hit:
  return 0;
}

// FUN_00454520

u32 FUN_00454520(float *param_1,char param_2)

{
  u32 bVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  float fVar5;
  YVec3f input;
  YVec3f delta;

  input = *(YVec3f *)param_1;
  iVar3 = *(int *)(*(int *)(DAT_0086ef0c_abs + param_2 * 0x1c0) + 0x3c);
  bVar1 = 0;
  iVar2 = *(char *)(iVar3 + 1) * 0x1c0;
  pfVar4 = (float *)(DAT_007ce290 + *(int *)(DAT_0086ef2c_abs + iVar2) * 0x40);
  iVar3 = *(int *)(DAT_0086ef08_abs + iVar2);
  delta.x = *(float *)(iVar3 + 0x100) - input.x;
  delta.y = *(float *)(iVar3 + 0x104) - input.y;
  delta.z = *(float *)(iVar3 + 0x108) - input.z;
  fVar5 = FUN_004c6ac0_vec((const RwV3d *)&delta);
  if (fVar5 < *pfVar4) {
    bVar1 = 1;
  }
  return bVar1;
}

#pragma pop
#pragma opt_propagation reset
// FUN_00454620 NONMATCHING

u64 FUN_00454620(char param_1)

{
  int iVar1;
  int iVar2;
  u8 bVar3;
  int lVar4;
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
  
  iVar1 = *(int *)(*(int *)(DAT_0086ef0c_abs + param_1 * 0x1c0) + 0x3c);
  pfVar6 = (float *)(DAT_007ce290 + *(int *)(DAT_0086ef2c_abs + *(char *)(iVar1 + 1) * 0x1c0) * 0x40);
  FUN_001ad940(afStack_30,*(u32 *)(*(u32 *)(DAT_008717f4_abs + *(char *)(iVar1 + 0x18) * 0x70) + 0x1e0));
  fStack_10 = afStack_30[0] -
              *(float *)(*(int *)(DAT_0086ef08_abs + *(char *)(iVar1 + 1) * 0x1c0) + 0x100);
  FUN_001ad940(auStack_40,*(u32 *)(*(u32 *)(DAT_008717f4_abs + *(char *)(iVar1 + 0x18) * 0x70) + 0x1e0));
  fStack_c = fStack_3c - *(float *)(*(int *)(DAT_0086ef08_abs + *(char *)(iVar1 + 1) * 0x1c0) + 0x104);
  FUN_001ad940(auStack_50,*(u32 *)(*(u32 *)(DAT_008717f4_abs + *(char *)(iVar1 + 0x18) * 0x70) + 0x1e0));
  fStack_8 = fStack_48 - *(float *)(*(int *)(DAT_0086ef08_abs + *(char *)(iVar1 + 1) * 0x1c0) + 0x108);
  FUN_004c69f0(&fStack_10,&fStack_10);
  fVar7 = *pfVar6;
  iVar5 = *(char *)(iVar1 + 1) * 0x1c0;
  iVar2 = *(int *)(DAT_0086ef08_abs + iVar5);
  fStack_10 = fStack_10 * fVar7 + *(float *)(iVar2 + 0x100) + 0.0f;
  fStack_c = fStack_c * fVar7 + *(float *)(iVar2 + 0x104);
  fStack_8 = fStack_8 * fVar7 + *(float *)(iVar2 + 0x108);
  FUN_001ad940(afStack_60,*(u32 *)(*(int *)(DAT_0086edf4_abs + iVar5) + 0x1e0));
  fStack_20 = fStack_10 - afStack_60[0];
  FUN_001ad940(auStack_70,
               *(u32 *)(*(int *)(DAT_0086edf4_abs + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
  fStack_1c = fStack_c - fStack_6c;
  FUN_001ad940(auStack_80,
               *(u32 *)(*(int *)(DAT_0086edf4_abs + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
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
    if (*(int *)(DAT_0086ef2c_abs +
                *(char *)(*(int *)(*(int *)(DAT_0086ef0c_abs + *(char *)(iVar1 + 1) * 0x1c0) + 0x3c) +
                         1) * 0x1c0) == 4) {
      bVar3 = 1;
    }
    else {
      lVar4 = FUN_001acc30_typed((void*)(afStack_c0),(void*)(&fStack_90));
      bVar3 = 1;
      if (lVar4 != 1) {
        bVar3 = 0;
      }
      else {
        if (50.0f < fStack_8c) {
          bVar3 = 0;
        }
      }
    }
    if ((bVar3) &&
       (lVar4 = FUN_001afa20_typed((pfVar6[3]),(void*)(*(u32 *)(DAT_0086ef10_abs + *(char *)(iVar1 + 1) * 0x1c0)),(void*)(&fStack_10)), lVar4 == 1)) {
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

#pragma push
/* W373 singles base 432/616; loop 432/616; common 405/620; life 432/616; propagation 426/604; strength 432/616; dead 432/616; pair common+prop 405/620. */
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_00454A70 NONMATCHING

u8 FUN_00454a70(char param_1,RwV3d param_2)

{
  int actor;
  int rowOffset;
  int position;
  int result;
  float *movement;
  float distance;
  RwV3d direction;
  RwV3d destination;
  RwV3d collision;
  RwV3d line[2];

  actor = *(int *)(*(int *)((u8 *)DAT_0086ef0c + param_1 * 0x1c0) + 0x3c);
  rowOffset = *(char *)(actor + 1) * 0x1c0;
  movement = (float *)(DAT_007ce290 + *(int *)((u8 *)DAT_0086ef2c + rowOffset) * 0x40);
  position = *(int *)((u8 *)DAT_0086ef08 + rowOffset);
  direction.x = param_2.x - *(float *)(position + 0x100);
  direction.y = param_2.y - *(float *)(position + 0x104);
  direction.z = param_2.z - *(float *)(position + 0x108);
  FUN_004c69f0((float *)&direction,(float *)&direction);
  distance = *movement;
  rowOffset = *(char *)(actor + 1) * 0x1c0;
  position = *(int *)((u8 *)DAT_0086ef08 + rowOffset);
  destination.x = direction.x * distance + *(float *)(position + 0x100) + 0.0f;
  destination.y = direction.y * distance + *(float *)(position + 0x104);
  destination.z = direction.z * distance + *(float *)(position + 0x108);
  collision = destination;
  line[1] = collision;
  line[0] = line[1];
  line[0].y = 400.0f;
  line[1].y = -400.0f;
  if (*(int *)((u8 *)DAT_0086ef2c +
              *(char *)(*(int *)(*(int *)((u8 *)DAT_0086ef0c + rowOffset) + 0x3c) + 1) * 0x1c0) == 4) {
    result = 1;
  }
  else {
    result = FUN_001acc30_typed((void *)line,(void *)&collision);
    if ((result != 1) || (50.0f < collision.y)) {
      result = 0;
    }
  }
  if ((result == 1) &&
      (FUN_001afa20_typed(movement[3],
                         (void *)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(actor + 1) * 0x1c0)),
                         (void *)&destination) == 1)) {
    return 1;
  }
  return 0;
}

#pragma pop
#pragma opt_common_subs reset
#pragma opt_propagation reset
#pragma push
/* W373 singles base 338/592; loop 338/592; common 500/736; life 338/592; propagation 399/596; strength 338/592; dead 113/588. */
#pragma opt_dead_assignments off
// FUN_00454D00 NONMATCHING

u8 FUN_00454d00(RwV3d param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int rowOffset;
  int columnOffset;
  float fVar4;
  float fVar5;
  RwV3d gridPosition;
  RwV3d localPosition;
  
  gridPosition = param_1;
  iVar2 = (int)(char)(int)((gridPosition.x + 400.0f) / 800.0f);
  localPosition = gridPosition;
  fVar5 = ((localPosition.x + 0.0f) - (float)iVar2 * 800.0f) + 400.0f;
  iVar3 = (int)(char)(int)((gridPosition.z + 400.0f) / 800.0f);
  fVar4 = ((localPosition.z + 0.0f) - (float)iVar3 * 800.0f) + 400.0f;
  rowOffset = iVar3 * 0x100;
  columnOffset = iVar2 * 0x10;
  iVar1 = FUN_001b9120_u32();
  if (*(u8 *)(iVar1 + rowOffset + columnOffset + 0x48) != 1) {
    return 0;
  }
  if (fVar4 < 150.0f) {
    if ((150.0f <= fVar5) && (fVar5 <= 650.0f)) {
      iVar1 = FUN_001b9120_u32();
      return (*(u8 *)(iVar1 + rowOffset + columnOffset + 0x53) & 1) != 0;
    }
  }
  else if (650.0f < fVar4) {
    if ((150.0f <= fVar5) && (fVar5 <= 650.0f)) {
      iVar1 = FUN_001b9120_u32();
      return (*(u8 *)(iVar1 + rowOffset + columnOffset + 0x53) & 4) != 0;
    }
  }
  else {
    if (fVar5 < 150.0f) {
      iVar1 = FUN_001b9120_u32();
      return (*(u8 *)(iVar1 + rowOffset + columnOffset + 0x53) & 2) != 0;
    }
    if (650.0f < fVar5) {
      iVar1 = FUN_001b9120_u32();
      return (*(u8 *)(iVar1 + rowOffset + columnOffset + 0x53) & 8) != 0;
    }
  }
  return 1;
}

#pragma pop
#pragma opt_dead_assignments reset
#pragma push
/* W373 singles base 2278/2876; loop 2278/2876; common 2434/3048; life 2287/2860; propagation 2261/2868; strength 2278/2876; dead 2285/2880. */
#pragma opt_propagation off
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
  YVec3f line2[2];
  YVec3f collision2;
  YVec3f line[2];
  YVec3f collision;
  RwV3d deltaToTarget;
  RwV3d afStack_230;
  
  float afStack_210[4];
  float afStack_200[4];
  float afStack_1f0[4];
  float afStack_1e0[4];
  float afStack_1d0[4];
  float afStack_1c0[4];
  float afStack_1b0[4];
  float afStack_1a0[4];
  float afStack_190[4];
  float afStack_180[4];
  float afStack_170[4];
  float afStack_160[4];
  float afStack_150[4];
  float afStack_140[4];
  float afStack_130[4];
  float afStack_120[4];
  float afStack_110[4];
  float afStack_100[4];
  float afStack_f0[4];
  float afStack_e0[4];
  float afStack_d0[4];
  float afStack_c0[4];
  float afStack_b0[4];
  float afStack_a0[4];
  float afStack_90[4];
  float afStack_80[4];
  float afStack_70[4];
  float afStack_60[4];
  float afStack_50[4];
  float afStack_40[4];
  RwV3d destination;
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
    FUN_001ad940(afStack_60,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(afStack_70,*(u32 *)(*piVar8 + 0x1e0));
    fStack_c = afStack_60[1] - afStack_70[1];
    FUN_001ad940(afStack_80,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(afStack_90,*(u32 *)(*piVar8 + 0x1e0));
    fStack_8 = afStack_80[2] - afStack_90[2];
  }
  else {
    piVar8 = (int *)((u8 *)DAT_008717f4 + param_2 * 0x70);
    FUN_001ad940(afStack_b0,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(afStack_a0,*(u32 *)(*piVar8 + 0x1e0));
    fStack_10 = afStack_a0[0] - afStack_b0[0];
    FUN_001ad940(afStack_d0,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(afStack_c0,*(u32 *)(*piVar8 + 0x1e0));
    fStack_c = afStack_c0[1] - afStack_d0[1];
    FUN_001ad940(afStack_f0,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(afStack_e0,*(u32 *)(*piVar8 + 0x1e0));
    fStack_8 = afStack_e0[2] - afStack_f0[2];
  }
  fVar9 = (float)FUN_004c69f0(&fStack_10,&fStack_10);
  if (fVar9 >= 300.0f) {
    fVar12 = fStack_8 * *(float *)&uStack_20;
    fVar9 = fStack_10 * fStack_18;
    fVar11 = (fStack_c * fStack_18 - fStack_8 * *((float *)&uStack_20 + 1)) * 400.0f;
    fVar10 = (fStack_10 * *((float *)&uStack_20 + 1) - fStack_c * *(float *)&uStack_20) * 400.0f;
    FUN_001ad940(afStack_1f0,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    destination.x = fVar11 + afStack_1f0[0];
    FUN_001ad940(afStack_200,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    destination.y = (fVar12 - fVar9) * 400.0f + afStack_200[1];
    FUN_001ad940(afStack_210,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    destination.z = fVar10 + afStack_210[2];
  }
  else {
    piVar8 = (int *)((u8 *)DAT_008717f4 + param_2 * 0x70);
    FUN_001ad940(afStack_100,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(afStack_110,*(u32 *)(*piVar8 + 0x1e0));
    fStack_10 = afStack_100[0] - afStack_110[0];
    FUN_001ad940(afStack_120,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(afStack_130,*(u32 *)(*piVar8 + 0x1e0));
    fStack_c = afStack_120[1] - afStack_130[1];
    FUN_001ad940(afStack_140,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    FUN_001ad940(afStack_150,*(u32 *)(*piVar8 + 0x1e0));
    fStack_8 = afStack_140[2] - afStack_150[2];
    FUN_004c69f0(&fStack_10,&fStack_10);
    fVar10 = fStack_10 * 400.0f;
    fVar11 = fStack_c * 400.0f;
    fVar9 = fStack_8 * 400.0f;
    FUN_001ad940(afStack_160,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    destination.x = fVar10 + afStack_160[0];
    FUN_001ad940(afStack_170,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    destination.y = fVar11 + afStack_170[1];
    FUN_001ad940(afStack_180,
                 *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    destination.z = fVar9 + afStack_180[2];
    collision.x = destination.x;
    collision.y = destination.y;
    collision.z = destination.z;
    line[1] = collision;
    line[0] = line[1];
    line[0].y = 400.0f;
    line[1].y = -400.0f;
    if (*(int *)((u8 *)DAT_0086ef2c +
                *(char *)(*(int *)(*(int *)((u8 *)DAT_0086ef0c + *(char *)(iVar1 + 1) * 0x1c0) + 0x3c) +
                         1) * 0x1c0) == 4) {
      bVar2 = 1;
    }
    else {
      lVar3 = FUN_001acc30_typed((void*)line,(void*)(&collision));
      bVar2 = 1;
      if (lVar3 != 1) {
        bVar2 = 0;
      }
      else if (50.0f < collision.y) {
          bVar2 = 0;
        }
      }
    if (!bVar2) {
      FUN_001ad940(&destination,
                   *(u32 *)(*(int *)((u8 *)DAT_0086edf4 + *(char *)(iVar1 + 1) * 0x1c0) + 0x1e0));
    }
    if (sVar5 < 0x32) {
      piVar8 = (int *)((u8 *)DAT_008717f4 + param_2 * 0x70);
      FUN_001ad940(afStack_190,*(u32 *)(*piVar8 + 0x1e0));
      fStack_10 = destination.x - afStack_190[0];
      FUN_001ad940(afStack_1a0,*(u32 *)(*piVar8 + 0x1e0));
      fStack_c = destination.y - afStack_1a0[1];
      FUN_001ad940(afStack_1b0,*(u32 *)(*piVar8 + 0x1e0));
      fStack_8 = destination.z - afStack_1b0[2];
    }
    else {
      piVar8 = (int *)((u8 *)DAT_008717f4 + param_2 * 0x70);
      FUN_001ad940(afStack_1c0,*(u32 *)(*piVar8 + 0x1e0));
      fStack_10 = afStack_1c0[0] - destination.x;
      FUN_001ad940(afStack_1d0,*(u32 *)(*piVar8 + 0x1e0));
      fStack_c = afStack_1d0[1] - destination.y;
      FUN_001ad940(afStack_1e0,*(u32 *)(*piVar8 + 0x1e0));
      fStack_8 = afStack_1e0[2] - destination.z;
    }
    FUN_004c69f0(&fStack_10,&fStack_10);
    destination.x = destination.x + (fStack_c * fStack_18 - fStack_8 * *((float *)&uStack_20 + 1)) * 400.0f;
    destination.y = destination.y + (fStack_8 * *(float *)&uStack_20 - fStack_10 * fStack_18) * 400.0f;
    destination.z = destination.z + (fStack_10 * *((float *)&uStack_20 + 1) - fStack_c * *(float *)&uStack_20) * 400.0f;
  }
  FUN_001b0250_typed(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0),0);
  afStack_230 = destination;
  iVar4 = *(char *)(*(int *)(*(int *)((u8 *)DAT_0086ef0c + *(char *)(iVar1 + 1) * 0x1c0) + 0x3c) + 1) *
          0x1c0;
  pfVar6 = (float *)(DAT_007ce290 + *(int *)((u8 *)DAT_0086ef2c + iVar4) * 0x40);
  iVar4 = *(int *)((u8 *)DAT_0086ef08 + iVar4);
  deltaToTarget.x = *(float *)(iVar4 + 0x100) - destination.x;
  deltaToTarget.y = *(float *)(iVar4 + 0x104) - destination.y;
  deltaToTarget.z = *(float *)(iVar4 + 0x108) - destination.z;
  fVar9 = (float)FUN_004c6ac0_vec(&deltaToTarget);
  if (fVar9 >= *pfVar6) {
    lVar3 = FUN_00454a70(*(u8 *)(iVar1 + 1),afStack_230);
    if (lVar3 == 1) {
      *(u8 *)(iVar1 + 3) = 0x19;
      FUN_0010a4e0(1,8,3,6);
    }
  }
  else {
    collision2.x = destination.x;
    collision2.y = destination.y;
    collision2.z = destination.z;
    line2[1] = collision2;
    line2[0] = line2[1];
    line2[0].y = 400.0f;
    line2[1].y = -400.0f;
    if (*(int *)((u8 *)DAT_0086ef2c +
                *(char *)(*(int *)(*(int *)((u8 *)DAT_0086ef0c + *(char *)(iVar1 + 1) * 0x1c0) + 0x3c) +
                         1) * 0x1c0) == 4) {
      bVar2 = 1;
    }
    else {
      lVar3 = FUN_001acc30_typed((void*)line2,(void*)(&collision2));
      bVar2 = 1;
      if (lVar3 != 1) {
        bVar2 = 0;
      }
      else if (50.0f < collision2.y) {
          bVar2 = 0;
        }
      }
    if (bVar2) {
      FUN_001afa20_typed((*(u32 *)(iVar7 + 0xc)),(void*)(*(u32 *)((u8 *)DAT_0086ef10 + *(char *)(iVar1 + 1) * 0x1c0)),(void*)(&destination));
      *(u8 *)(iVar1 + 3) = 0x19;
      FUN_0010a4e0(1,8,3,6);
    }
  }
  return;
}

/* W212: hoisting the first-loop invariants and preserving its distinct one/five
 * values improved nd287 -> nd283 (340 -> 332 bytes).  The remaining offset-0
 * divergence is the combined retail preheader; no window growth was introduced. */
#pragma pop
#pragma opt_propagation reset
#pragma push
/* W380 measured FUN_00455B50: pre-closure 336/243; loop_invariants on 336/243 (window 416). Restores a setting lost when a leaked file-scope pragma was closed. */
#pragma opt_loop_invariants on
// FUN_00455B50 NONMATCHING

void FUN_00455b50(void)
{
  int index;
  int valid;
  int storeOne;
  int stateFive;
  int expectedValid;
  u8 *row;
  u8 *state;

  index = 1;
  valid = index;
  storeOne = index;
  stateFive = 5;
  expectedValid = index;
  for (; index < 4; index = index + 1) {
    int rowValid = 0;
    row = DAT_008717a0_bytes + index * 0x1c0;
    if ((*(int *)(row + 0x48) != 0) && (*(int *)(row + 0x54) != 0)) {
      rowValid = valid;
    }
    if ((rowValid != 0) == expectedValid) {
      state = *(u8 **)(*(int *)(row + 0x16c) + 0x3c);
      row[0x19c] = 0;
      if (*(s8 *)(state + 0x1215) == expectedValid) {
        row[0x19c] = expectedValid;
      }
      row[0x19a] = *(s8 *)(state + 1);
      row[0x19b] = 0;
      if (*(s8 *)(state + 1) == stateFive) {
        row[0x19b] = storeOne;
      }
    }
  }
  index = 0;
  valid = 1;
  for (; index < 0x18; index = index + 1) {
    int rowValid = 0;
    row = DAT_0086eda0_bytes + index * 0x1c0;
    if ((*(int *)(row + 0x48) != 0) && (*(int *)(row + 0x54) != 0)) {
      rowValid = valid;
    }
    if ((rowValid != 0) == valid) {
      state = *(u8 **)(*(int *)(row + 0x16c) + 0x3c);
      row[0x198] = *(s8 *)(state + 0x18);
      row[0x199] = *(u8 *)(state + 0x8b) + *(u8 *)(state + 0x8c) * 0x10;
      row[0x19a] = *(s8 *)(state + 2);
      row[0x19b] = 0;
      row[0x19c] = 0;
      if (*(s8 *)(state + 0x40) == valid) {
        row[0x19c] = valid;
      }
    }
  }
}
#pragma pop
#pragma opt_loop_invariants reset

#pragma push
#pragma opt_loop_invariants on
/* W373 singles base 172/248; loop 172/248; common 190/284; life 152/248; propagation 168/240; strength 172/248; dead 172/248; pair life+prop 145/240. */
#pragma opt_lifetimes on
#pragma opt_propagation off

// W419 YMisc4 negative: direct-global/integer-pointer barriers for the recomputed row pointers in FUN_00455cf0 worsened nd145 -> 152 (object240 -> 248/window272); rejected.
// FUN_00455CF0 NONMATCHING

void FUN_00455cf0(void)
{
  u8 *base;
  int index;
  u8 *checkRow;
  int valid;
  u8 *row;

  index = 1;
  for (; index < 4; index = index + 1) {
    base = DAT_008717a0_bytes;
    valid = 0;
    checkRow = base + index * 0x1c0;
    if ((*(int *)(checkRow + 0x48) != 0) && (*(int *)(checkRow + 0x54) != 0)) {
      valid = 1;
    }
    valid = valid != 0;
    if (valid == 1) {
      row = base + index * 0x1c0;
      row[0x19a] = 0;
      row[0x19c] = 0;
    }
  }
  index = 0;
  for (; index < 0x18; index = index + 1) {
    base = DAT_0086eda0_bytes;
    valid = 0;
    checkRow = base + index * 0x1c0;
    if ((*(int *)(checkRow + 0x48) != 0) && (*(int *)(checkRow + 0x54) != 0)) {
      valid = 1;
    }
    valid = valid != 0;
    if (valid == 1) {
      row = base + index * 0x1c0;
      row[0x198] = 0;
      row[0x199] = 0;
      row[0x19a] = 0;
      row[0x19b] = 0;
      row[0x19c] = 0;
    }
  }
  return;
}

#pragma pop
#pragma opt_lifetimes reset
#pragma opt_propagation reset
// FUN_00455E00 NONMATCHING

u32 FUN_00455e00(u32 param_1)

{
  char cVar2;
  char *pcVar3;
  u32 uVar4;
  int iVar5;
  int uVar6;
  float fVar7;
  float fVar8;
  
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
      *(float *)(pcVar3 + iVar5 * 0x40 + 0x18) = DAT_00960088_y2 - *(float *)(pcVar3 + 0x128);
      *(float *)(pcVar3 + iVar5 * 0x40 + 0x28) = 1.0f / fVar7;
      *(u32 *)(pcVar3 + iVar5 * 0x40 + 0x30) = 0x437f0000;
      *(u32 *)(pcVar3 + iVar5 * 0x40 + 0x34) = 0x437f0000;
      *(u32 *)(pcVar3 + iVar5 * 0x40 + 0x38) = 0x437f0000;
      *(u32 *)(pcVar3 + iVar5 * 0x40 + 0x3c) = 0x437f0000;
    }
    *(u32 *)(pcVar3 + 0x20) = 0;
    *(u32 *)(pcVar3 + 0x24) = 0;
    *(u32 *)(pcVar3 + 0x60) = *(u32 *)(pcVar3 + 0x13c);
    *(u32 *)(pcVar3 + 0x64) = 0;
    *(u32 *)(pcVar3 + 0xa0) = 0;
    *(u32 *)(pcVar3 + 0xa4) = *(u32 *)(pcVar3 + 0x140);
    *(u32 *)(pcVar3 + 0xe0) = *(u32 *)(pcVar3 + 0x13c);
    *(u32 *)(pcVar3 + 0xe4) = *(u32 *)(pcVar3 + 0x140);
    uVar6 = FUN_00318b60(*(u32 *)(*(int *)(pcVar3 + 0x144) + 0x128));
    fVar8 = FUN_001a5aa0_typed((const void *)(uVar6));
    FUN_004561f0(fVar8,param_1);
    (*DAT_009600a0)(4,pcVar3 + 0x10,4);
  }
  return 0;
}

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

// MWCC b210 floor: the mixed-ABI prologue preserves $f14 before $a1/$a2; retail preserves
// $a1, then $a2, then $f14. The remaining body is instruction-identical after relocations.
// FUN_004560D0

u32 FUN_004560d0(u64 param_1,float param_2,float param_3,u32 param_5,u32 param_6,float param_4)
{
  int lVar1;
  u32 uVar2;
  u8 *puVar3;

  lVar1 = (*DAT_00960184_abs)(1,0x150,0x40000);
  if (lVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00194b20_u32_y2(param_1,DAT_006b4a60,0x18a6,(u32 (*)(int))FUN_00455e00,FUN_00456050,lVar1);
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
// FUN_004561F0

void FUN_004561f0(float param_1,int param_2)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  int iVar4;
  u32 uVar5;
  int iVar6;
  u32 *puVar8;
  u32 *puVar7;
  struct {
    u64 xy;
    f32 z;
  } axis;
  YVec3f source[4];
  YVec3f output[4];
  u32 raw[8];
  u8 *axisData;
  u64 xy;
  f32 z;

  iVar1 = *(int *)(param_2 + 0x3c);
  axisData = DAT_006b4a78_abs;
  xy = *(volatile /* Removing this function's qualifier batch loses FUN_004561f0 (MATCH nd0 -> MISMATCH nd5, size 448 -> 448) - measured W170. */ u64 *)axisData;
  z = *(volatile /* Removing this function's qualifier batch loses FUN_004561f0 (MATCH nd0 -> MISMATCH nd5, size 448 -> 448) - measured W170. */ f32 *)(axisData + 8);
  axis.xy = xy;
  axis.z = z;
  puVar8 = (u32 *)DAT_006b4a90_abs;
  puVar7 = raw;
  {
    int i;

    i = 4;
    do {
      uVar2 = *puVar8;
      uVar3 = puVar8[1];
      puVar8 = puVar8 + 2;
      i = i + -1;
      *puVar7 = uVar2;
      puVar7[1] = uVar3;
      puVar7 = puVar7 + 2;
    } while (0 < i);
    for (i = 0; i < 4; i = i + 1) {
      u32 *pair = &raw[i * 2];
      YVec3f *vec = &source[i];

      vec->x = *(float *)&pair[0];
      vec->z = *(float *)&pair[1];
      vec->y = 0.0f;
    }
  }
  uVar5 = FUN_004c38c0_typed();
  if (!(param_1 < 0.0f)) {
    param_1 = param_1 - 180.0f;
  }
  else {
    param_1 = param_1 + 180.0f;
  }
  FUN_004c31b0_ym(param_1 + *(float *)(iVar1 + 0x138),(void *)uVar5,&axis,2);
  for (iVar6 = 0; iVar6 < 4; iVar6 = iVar6 + 1) {
    FUN_004c6be0_typed((float *)&output[iVar6],(const float *)&source[iVar6],
                       (void *)uVar5);
    iVar4 = iVar1 + iVar6 * 0x40;
    *(float *)(iVar4 + 0x10) = *(float *)(iVar1 + 0x120) + output[iVar6].x;
    *(float *)(iVar4 + 0x14) = *(float *)(iVar1 + 0x124) + output[iVar6].z;
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
  RwV3d uStack_20;
  RwV3d uStack_30;
  
  cVar9 = (char)param_2;
  iVar8 = cVar9 * 0x1c0;
  iVar5 = *(int *)(*(int *)((u8 *)DAT_0087190c + iVar8) + 0x3c);
  cVar2 = *(char *)(iVar5 + 0x123b) + '\x01';
  *(char *)(iVar5 + 0x123b) = cVar2;
  if (cVar2 < '2') {
    FUN_001ad940(&uStack_20,*(u32 *)(((u8 *)DAT_008717f4)[cVar9 * 0x70] + 0x1e0));
    *(float *)(iVar5 + 0x123c) = uStack_20.x;
    *(float *)(iVar5 + 0x1240) = uStack_20.y;
    *(float *)(iVar5 + 0x1244) = uStack_20.z;
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
      FUN_001a9760_typed((void *)(*(u32 *)(iVar5 + 0x10)),6,(void *)(&uStack_30),uVar11,uVar7);
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
iVar10 = *(int *)(*(int *)((u8 *)DAT_0087190c + param_2 * 0x1c0) + 0x3c);
cVar2 = *(char *)(iVar10 + 0x123b) + '\x01';
*(char *)(iVar10 + 0x123b) = cVar2;
cVar9 = (char)param_3;
if (cVar2 < '2') {
  FUN_001ad940(&uStack_20,*(u32 *)(((u8 *)DAT_008717f4)[param_2 * 0x70] + 0x1e0));
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
    if ((bVar1) && ((long)iVar10 != (long)param_2)) {
      cVar2 = FUN_004573d0((char)iVar10);
      if ((param_3 == cVar2) && (cVar2 = FUN_00457390((char)iVar10), cVar2 == '\x03')) {
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
    if (lVar7 != 1) {
      uVar12 = 3;
    }
    else {
      FUN_0010a4e0(1,8,3,1);
      uVar8 = uVar12;
    }
    iVar6 = FUN_001b9120_u32();
    FUN_001a9760_typed((void *)(*(u32 *)(iVar6 + 0x10)),6,(void *)(&uStack_10),uVar12,uVar8);
    uVar4 = FUN_0043b980(param_2,param_3);
    FUN_0017b860_typed(*(u16 *)((u8 *)DAT_00871948 + param_2 * 0x1c0),
                 *(u16 *)((u8 *)DAT_00871948 + iVar10),uVar4,0);
    sVar3 = FUN_0017b500_ret(*(u16 *)((u8 *)DAT_00871948 + param_2 * 0x1c0),uVar4);
    if (sVar3 == 1) {
      puVar13 = (u16 *)((u8 *)DAT_00871948 + param_2 * 0x1c0);
      sVar3 = FUN_0016c4f0(*puVar13);
      sVar5 = FUN_0017b5b0(*puVar13,uVar4);
      FUN_0016cf40_typed(*puVar13,sVar3 - sVar5);
    }
    else if (sVar3 == 2) {
      puVar13 = (u16 *)((u8 *)DAT_00871948 + param_2 * 0x1c0);
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
/* W373 singles base 776/1060; loop 776/1060; common 803/1112; life 776/1060; propagation 768/1052; strength 776/1060; dead 754/1056; pair propagation+dead 768/1052. */
#pragma opt_dead_assignments off
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
  int lVar9;
  char cVar10;
  int iVar11;
  u16 *puVar12;
  char cVar13;
  YRuntimeUnitRow *selfRow;
  YRuntimeUnitRow *targetRow;
  YRuntimeUnitRow *loopRow;
  YRuntimeUnitRow *rowBase;
  u64 uVar14;
  u64 uVar15;
  YVec3f target;
  YVec3f origin;
  YVec3f midpoint;
  
  cVar13 = (char)param_2;
  rowBase = DAT_008717a0_unit_rows;
  selfRow = &rowBase[(int)cVar13];
  iVar1 = *(int *)((u8 *)selfRow->unit + 0x3c);
  iVar11 = 1;
  cVar10 = (char)param_3;
  do {
    if (3 < (long)iVar11) {
      sVar4 = FUN_0043bda0(param_2,param_3);
      if (sVar4 != -1) {
        targetRow = &rowBase[(int)cVar10];
        FUN_001ad940(&target,*(u32 *)((u8 *)targetRow->unk_054 + 0x1e0));
        uVar14 = 0xffffffffffffffff;
        FUN_00318ed0_typed(*(u32 *)((u8 *)targetRow->unk_054 + 0x128),2,(float *)(&origin));
        midpoint.x = (origin.x + target.x) / 2.0f;
        midpoint.y = (origin.y + target.y) / 2.0f;
        midpoint.z = (origin.z + target.z) / 2.0f;
        lVar9 = FUN_001c7130(2400.0f,(u32)targetRow);
        if (lVar9 == 1) {
          FUN_0010a4e0(1,8,3,2);
          uVar15 = uVar14;
        }
        else {
          uVar15 = 3;
          uVar14 = 2;
        }
        midpoint.y = midpoint.y - 80.0f;
        iVar8 = FUN_001b9120_u32();
        FUN_001a9760_typed((void *)(*(u32 *)(iVar8 + 0x10)),2,(void *)(&midpoint),uVar15,uVar14);
        iVar8 = FUN_001b9120_u32();
        if (*(int *)(iVar8 + 0x28) != 0) {
          iVar8 = FUN_001b9120_u32();
          FUN_0018bee0_typed(*(u32 *)(iVar8 + 0x28),targetRow->unit_id,0);
        }
        uVar5 = FUN_0043bda0(param_2,*(u8 *)(iVar1 + 0x1226));
        FUN_0017b860_typed(selfRow->unit_id,targetRow->unit_id,uVar5,0);
        lVar9 = FUN_002ff790_typed(targetRow->unk_048);
        if (lVar9 == 0) {
          uVar6 = FUN_001dde00_typed(targetRow->unit_id);
          FUN_003182d0((u32)targetRow->unk_050,0,uVar6,0,1);
        }
        sVar4 = FUN_0017b500_ret(selfRow->unit_id,uVar5);
        if (sVar4 == 1) {
          puVar12 = &selfRow->unit_id;
          sVar4 = FUN_0016c4f0(*puVar12);
          sVar7 = FUN_0017b5b0(*puVar12,uVar5);
          FUN_0016cf40_typed(*puVar12,sVar4 - sVar7);
        }
        else if (sVar4 == 2) {
          puVar12 = &selfRow->unit_id;
          sVar4 = FUN_0016c570_typed(*puVar12);
          sVar7 = FUN_0017b5b0(*puVar12,uVar5);
          FUN_0016cf90_typed(*puVar12,sVar4 - sVar7);
        }
        FUN_00457340(param_2,4,param_3);
      }
      return;
    }
    bVar2 = 0;
    loopRow = &rowBase[iVar11];
    if ((loopRow->unk_048 != 0) && (loopRow->unk_054 != 0)) {
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

// W295: retail reloads row+0x54/row+0x168 for the FUN_001adc20 call (no CSE from the
// previous call) - three volatile-ordered loads reproduce it; not a scheduling floor.
// FUN_00457470

u32 FUN_00457470(int param_1)

{
  u16 uVar1;
  u32 uVar2;
  s32 lVar3;
  u8 *row;
  u64 xy;
  f32 z;
  struct YPackedVec3 {
    u64 xy;
    f32 z;
  } axis;
  
  xy = *(volatile /* Removing this function's qualifier batch worsens FUN_00457470 (NONMATCHING nd6 -> NONMATCHING nd11, size 356 -> 356) - measured W170. */ u64 *)DAT_006b4b20_abs;
  z = *(volatile /* Removing this function's qualifier batch worsens FUN_00457470 (NONMATCHING nd6 -> NONMATCHING nd11, size 356 -> 356) - measured W170. */ f32 *)(DAT_006b4b20_abs + 8);
  axis.xy = xy;
  axis.z = z;
  row = DAT_0086e6a0_rows[param_1];
  if (*(int *)(row + 0x48) == 0) {
    return 1;
  }
  if (*(int *)(row + 0x54) != 0) {
    return 1;
  }
  lVar3 = FUN_00316f70_typed(*(u32 *)(row + 0x50));
  if (lVar3 == 0) {
    return 0;
  }
  uVar1 = FUN_003b6030_typed(param_1 + 10U & 0xffff,0,(void *)(*(u32 *)(row + 0x50)));
  uVar2 = FUN_003b5d10_eb90(uVar1);
  *(u32 *)(row + 0x54) = uVar2;
  FUN_003182d0(*(u32 *)(row + 0x50),0,0,0x10,1);
  FUN_001adff0_typed((void *)(*(u32 *)(*(int *)(row + 0x54) + 0x1e0)),
                      &axis,*(f32 *)(*(int *)(row + 0x168) + 0x10c));
  {
    int b54 = *(volatile int *)(row + 0x54);
    int b168 = *(volatile int *)(row + 0x168);
    u32 hdl = *(volatile u32 *)(b54 + 0x1e0);
    FUN_001adc20_typed((void *)hdl, (const void *)(b168 + 0x100));
  }
  FUN_001a0dc0_typed(**(u16 **)(row + 0x54),1);
  FUN_001ad870_typed((void *)(*(u32 *)(*(int *)(row + 0x54) + 0x1e0)),0x40000000);
  uVar2 = (u32)FUN_001af930_typed((void *)0,(void *)(*(u32 *)(row + 0x54)));
  *(u32 *)(row + 0x170) = uVar2;
  return 1;
}

#pragma opt_dead_assignments reset
// FUN_004575E0

u32 FUN_004575e0(int param_1)

{
  char *puVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 lVar6;
  int iVar7;
  
  puVar1 = *(char **)(param_1 + 0x3c);
  switch(*puVar1) {
  case 0:
    *puVar1 = 1;
    break;
  case 1:
    {
      u32 uVar5a;
    uVar2 = FUN_003b5d10_eb90(0x3c00);
    lVar6 = FUN_00457410();
    if (lVar6 != 0) {
      uVar3 = (u32)FUN_002ff340_typed(2);
      iVar7 = (int)lVar6;
      *(u32 *)(iVar7 + 0x48) = uVar3;
      uVar5a = FUN_00316e00_typed(9,0x201,0);
      FUN_0031c1d0_typed(uVar5a);
      *(int *)(iVar7 + 0x50) = (int)uVar5a;
      *(u16 *)(iVar7 + 0x1a8) = 2;
      uVar4 = FUN_00173300(2);
      *(u32 *)(iVar7 + 0x184) = uVar4 & 0xff;
      *(u32 *)(iVar7 + 0x168) = uVar2;
    }
    *puVar1 = 2;
    }
  case 2:
    lVar6 = FUN_00457470(0);
    if (lVar6 == 1) {
      *(u32 *)DAT_0086e80c_abs = FUN_00458630(0,0,0);
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
      uVar4 = FUN_00173300(4);
      *(u32 *)(iVar7 + 0x184) = uVar4 & 0xff;
      *(u32 *)(iVar7 + 0x168) = uVar2;
    }
    *puVar1 = 4;
  case 4:
    lVar6 = FUN_00457470(1);
    if (lVar6 == 1) {
      *(u32 *)DAT_0086e9cc_abs = FUN_00458630(0,1,2);
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
      uVar4 = FUN_00173300(6);
      *(u32 *)(iVar7 + 0x184) = uVar4 & 0xff;
      *(u32 *)(iVar7 + 0x168) = uVar2;
    }
    *puVar1 = 6;
  case 6:
    lVar6 = FUN_00457470(2);
    if (lVar6 == 1) {
      *(u32 *)DAT_0086eb8c_abs = FUN_00458630(0,2,1);
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
      uVar4 = FUN_00173300(3);
      *(u32 *)(iVar7 + 0x184) = uVar4 & 0xff;
      *(u32 *)(iVar7 + 0x168) = uVar2;
    }
    *puVar1 = 8;
    break;
  case 8:
    lVar6 = FUN_00457470(3);
    if (lVar6 == 1) {
      *(u32 *)DAT_0086ed4c_abs = FUN_00458630(0,3,2);
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
/* W373 singles base 1965/2932; loop 1965/2932; common 2111/3096; life 1965/2932; propagation 1965/2932; strength 1965/2932; dead 1964/2932. */
#pragma opt_dead_assignments off
// FUN_00457A40 NONMATCHING

u64 FUN_00457a40(u64 param_1)

{
  char cVar1;
  char cVar2;
  u8 *puVar3;
  u32 uVar4;
  int iVar5;
  int lVar6;
  int iVar7;
  int iVar8;
  u8 *config;
  YRuntimeUnitRow *unit_row;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  puVar3 = *(u8 **)((int)param_1 + 0x3c);
  cVar1 = puVar3[2];
  iVar7 = cVar1 * 0x1c0;
  iVar8 = cVar1 * 0x1c;
  config = DAT_006b4ab0_abs + iVar8;
  unit_row = &DAT_0086e6a0_unit_rows[(int)cVar1];
  if (puVar3[8] != '\x01') {
    cVar2 = puVar3[7];
    if (cVar2 == '\x01') {
      FUN_00195460(*(u32 *)(puVar3 + 0x10));
    }
    else if (cVar2 == '\x02') {
      lVar6 = FUN_00458cb0(param_1,cVar1,0);
      if ((lVar6 != 1) && (lVar6 = FUN_00195460(*(u32 *)(puVar3 + 0x10)), lVar6 == 0)) {
        *(u32 *)(puVar3 + 0x10) = 0;
        FUN_001b0020_typed(*(u32 *)unit_row->pad_170,(void*)(puVar3 + 0x1c),*(u16 *)(config + 0x16));
        puVar3[7] = 3;
        if (*(int *)(puVar3 + 0x10) != 0) {
          *(u32 *)(puVar3 + 0x10) = 0;
        }
        uVar4 = FUN_00459f60(param_1,*(u16 *)(config + 0x16),0);
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
        uVar4 = FUN_00459f60(param_1,*(u16 *)(config + 0x18),0);
        *(u32 *)(puVar3 + 0x10) = uVar4;
      }
    }
    else if (cVar2 == '\x04') {
      lVar6 = FUN_00458cb0(param_1,cVar1,0);
      if ((lVar6 != 1) && (lVar6 = FUN_00195460(*(u32 *)(puVar3 + 0x10)), lVar6 == 0)) {
        *(u32 *)(puVar3 + 0x10) = 0;
        FUN_003bb010_typed(*(u16 *)unit_row->unk_054,2);
        puVar3[7] = 5;
        if (*(int *)(puVar3 + 0x10) != 0) {
          *(u32 *)(puVar3 + 0x10) = 0;
        }
        uVar4 = FUN_00459f60(param_1,*(u16 *)(config + 0x18),0);
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
        uVar4 = FUN_00459f60(param_1,*(u16 *)(config + 0x14),0);
        *(u32 *)(puVar3 + 0x10) = uVar4;
      }
    }
    else if (cVar2 == '\x06') {
      lVar6 = FUN_00458cb0(param_1,cVar1,0);
      if ((lVar6 != 1) && (lVar6 = FUN_00195460(*(u32 *)(puVar3 + 0x10)), lVar6 == 0)) {
        if (puVar3[2] == '\x01') {
          iVar5 = FUN_003b5d10_eb90(0x4402);
          fStack_10 = *(float *)(iVar5 + 0x100);
          fStack_c = *(float *)(iVar5 + 0x104);
          fStack_8 = *(float *)(iVar5 + 0x108);
          FUN_001b0020_typed(*(u32 *)unit_row->pad_170,(void*)(&fStack_10),*(u16 *)(config + 0x16));
        }
        else if (puVar3[2] == '\x03') {
          iVar5 = FUN_003b5d10_eb90(0x4403);
          fStack_10 = *(float *)(iVar5 + 0x100);
          fStack_c = *(float *)(iVar5 + 0x104);
          fStack_8 = *(float *)(iVar5 + 0x108);
          FUN_001b0020_typed(*(u32 *)unit_row->pad_170,(void*)(&fStack_10),*(u16 *)(config + 0x16));
        }
        else {
          FUN_001b0020_typed(*(u32 *)unit_row->pad_170,(void*)(puVar3 + 0x30),*(u16 *)(config + 0x16));
        }
        puVar3[7] = 7;
        if (*(int *)(puVar3 + 0x10) != 0) {
          *(u32 *)(puVar3 + 0x10) = 0;
        }
        uVar4 = FUN_00459f60(param_1,*(u16 *)(config + 0x16),0);
        *(u32 *)(puVar3 + 0x10) = uVar4;
      }
    }
    else if (cVar2 == '\a') {
      lVar6 = FUN_00458cb0(param_1,cVar1,0);
      if ((lVar6 != 1) && (lVar6 = FUN_00195460(*(u32 *)(puVar3 + 0x10)), lVar6 == 0)) {
        *(u32 *)(puVar3 + 0x10) = 0;
        for (lVar6 = 0; lVar6 < *(short *)(puVar3 + 0x28); lVar6 = lVar6 + 1) {
          FUN_001b01d0_typed((void *)(*(u32 *)unit_row->pad_170),lVar6,(const void *)(puVar3 + (int)lVar6 * 0x18 + 0x2c));
        }
        FUN_001b0230_typed((void *)(*(u32 *)unit_row->pad_170),(s32)lVar6);
        FUN_001b0260(*(u32 *)unit_row->pad_170,1);
        lVar6 = FUN_00459e00(puVar3[2]);
        if (lVar6 != 1) {
          puVar3[7] = 8;
        }
        else {
          for (iVar7 = 0; iVar7 < 4; iVar7 = iVar7 + 1) {
            FUN_001b0260(*(u32 *)((u8 *)DAT_0086e810 + iVar7 * 0x1c0),0);
            FUN_00458920(((u8 *)DAT_0086e80c)[iVar7 * 0x70]);
          }
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
          FUN_001b0240(*(u32 *)unit_row->pad_170,1);
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
                lVar6 = FUN_001b0220(*(u32 *)unit_row->pad_170);
                if (lVar6 == 0) {
                  if (*(short *)(puVar3 + 0x16) >= 0x3c) {
                    puVar3[0x14] = 0;
                  }
                  else {
                    *(short *)(puVar3 + 0x16) = *(short *)(puVar3 + 0x16) + 1;
                  }
                }
              }
              else {
                iVar8 = FUN_003b5d10_eb90(*(u16 *)(puVar3 + 4) & 0x3ff | 0x4000);
                fStack_10 = *(float *)(iVar8 + 0x100);
                fStack_c = *(float *)(iVar8 + 0x104);
                fStack_8 = *(float *)(iVar8 + 0x108);
                FUN_001b0250_typed(*(u32 *)unit_row->pad_170,5);
                lVar6 = FUN_001afa20_typed(((float)*(int *)((u8 *)DAT_007bc6b0 + (char)puVar3[6] * 4)),(void*)(*(u32 *)unit_row->pad_170),(void*)(&fStack_10));
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
              lVar6 = FUN_001b0220(*(u32 *)unit_row->pad_170);
              if (lVar6 == 0) {
                if (*(short *)(puVar3 + 0x16) >= 0x3c) {
                  puVar3[0x14] = 0;
                }
                else {
                  *(short *)(puVar3 + 0x16) = *(short *)(puVar3 + 0x16) + 1;
                }
              }
            }
            else {
              iVar8 = FUN_003b5d10_eb90(*(u16 *)(puVar3 + 4) & 0x3ff | 0x3c00);
              fStack_10 = *(float *)(iVar8 + 0x100);
              fStack_c = *(float *)(iVar8 + 0x104);
              fStack_8 = *(float *)(iVar8 + 0x108);
              FUN_001b0250_typed(*(u32 *)unit_row->pad_170,5);
              lVar6 = FUN_001afa20_typed(((float)*(int *)((u8 *)DAT_007bc6b0 + (char)puVar3[6] * 4)),(void*)(*(u32 *)unit_row->pad_170),(void*)(&fStack_10));
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
        else if (((char)puVar3[6] + 1) * 8 <= *(short *)(puVar3 + 4)) {
          *puVar3 = 3;
        }
        break;
      case 3:
        if ((puVar3[2] == '\0') && (lVar6 = FUN_004589e0(), lVar6 == 1)) {
          if (*(int *)(puVar3 + 0xc) != 0) {
            *(u32 *)(puVar3 + 0xc) = 0;
          }
          if (puVar3[6] != '\x02') {
            lVar6 = 0;
            while (lVar6 < 4) {
              iVar7 = (int)lVar6;
              if ((char)puVar3[2] != lVar6) {
                FUN_001b0260(*(u32 *)((u8 *)DAT_0086e810 + iVar7 * 0x1c0),1);
                FUN_004589d0(((u8 *)DAT_0086e80c)[iVar7 * 0x70],1);
              }
              lVar6 = iVar7 + 1;
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
          else {
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
              lVar6 = iVar7 + 1;
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

// FUN_00458630

u32 FUN_00458630(u64 param_1,char param_2,u8 param_3)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  u8 *puVar3;
  u8 *row;
  u8 *config;
  u8 colors[8];
  YVec3f axis;

  iVar3 = param_2 * 7;
  row = (u8 *)DAT_0086e6a0_rows + iVar3 * 0x40;
  config = DAT_006b4ab0_abs + iVar3 * 4;
  puVar3 = (u8 *)(*DAT_00960184_abs)(1,0x4b4,0x40000);
  if (puVar3 == 0) {
    return 0;
  }
  uVar1 = FUN_00194b80_u32(param_1,10,DAT_006b4b50,(u32 (*)(int))FUN_00457a40,
                           FUN_00458600,(u32)puVar3);
  puVar3[0] = 0;
  puVar3[1] = param_3;
  puVar3[2] = param_2;
  puVar3[6] = 0;
  puVar3[7] = 0;
  puVar3[0x14] = 0;
  *(u16 *)(puVar3 + 0x16) = 0;
  *(u32 *)(puVar3 + 0x10) = 0;
  *(u16 *)(puVar3 + 0x18) = 0;
  puVar3[8] = 0;
  axis.y = 50.0f;
  axis.z = 0.0f;
  axis.x = 0.0f;
  colors[4] = 0xff;
  colors[5] = 0;
  colors[6] = 0;
  colors[7] = 0x80;
  colors[0] = 0;
  colors[1] = 0xff;
  colors[2] = 0;
  colors[3] = 0x80;
  uVar2 = FUN_001a5320_typed(uVar1);
  *(u32 *)(puVar3 + 0x4ac) = uVar2;
  FUN_001a56c0_typed(uVar2,*(u32 *)(row + 0x50));
  FUN_001a5700_typed(*(u32 *)(puVar3 + 0x4ac),colors + 4);
  FUN_001a56d0_typed(*(u32 *)(puVar3 + 0x4ac),&axis);
  FUN_001a57a0_f32(*(u32 *)(puVar3 + 0x4ac),*(float *)(config + 8),
                    *(float *)(config + 4));
  FUN_001a56b0_typed(*(u32 *)(puVar3 + 0x4ac),0);
  uVar2 = FUN_001a5320_typed(uVar1);
  *(u32 *)(puVar3 + 0x4b0) = uVar2;
  FUN_001a56c0_typed(uVar2,*(u32 *)(row + 0x50));
  FUN_001a5700_typed(*(u32 *)(puVar3 + 0x4b0),colors);
  FUN_001a56d0_typed(*(u32 *)(puVar3 + 0x4b0),&axis);
  FUN_001a57a0_f32(*(u32 *)(puVar3 + 0x4b0),360.0f,*(float *)config);
  FUN_001a56b0_typed(*(u32 *)(puVar3 + 0x4b0),0);
  return uVar1;
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
#pragma push
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
#pragma pop
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

#pragma opt_dead_assignments reset
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
  int lVar8;
  u32 uVar9;
  int iVar10;
  int iVar11;
  u8 bVar12;
  int *piVar13;
  int lVar14;
  char unaff_s5;
  int iVar15;
  u32 uVar16;
  u8 *config;
  YRuntimeUnitRow *unit_row;
  YRuntimeUnitRow *other_row;
  YRuntimeUnitRow *loop_row;
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
  
  lVar14 = param_2;
  iVar7 = param_2;
  iVar10 = iVar7 * 0x1c;
  config = DAT_006b4ab0_abs + iVar10;
  unit_row = &DAT_0086e6a0_unit_rows[iVar7];
  bVar12 = 0;
  iVar11 = iVar7 * 0x1c0;
  if ((unit_row->unk_048 != 0) && (unit_row->unk_054 != 0)) {
    bVar12 = 1;
  }
  if (bVar12) {
    for (iVar15 = 0; iVar15 < 4; iVar15 = iVar15 + 1) {
      other_row = &DAT_008717a0_unit_rows[iVar15];
      bVar12 = 0;
      if ((other_row->unk_048 != 0) && (other_row->unk_054 != 0)) {
        bVar12 = 1;
      }
      if (bVar12) {
        iVar2 = (int)((u8 *)unit_row->unit + 0x3c);
        piVar13 = (int *)&other_row->unk_054;
        iVar5 = FUN_00318b60(*(u32 *)((u8 *)unit_row->unk_054 + 0x128));
        FUN_001ad940(auStack_10,*(u32 *)(*piVar13 + 0x1e0));
        lVar8 = FUN_0044f1c0(*(float *)(config + 0xc),(float *)(iVar5 + 0x30),(float *)auStack_10);
        if (lVar8 == 1) {
          *(u8 *)(iVar2 + 7) = 1;
          if (lVar14 == 0) {
            unaff_s5 = 0xd;
            FUN_003182d0(*(u32 *)((u8 *)unit_row->unk_054 + 0x128),0,2,8,0);
          }
          else if (lVar14 == 1) {
            FUN_003182d0(*(u32 *)((u8 *)unit_row->unk_054 + 0x128),0,1,8,0);
            unaff_s5 = 0xf;
          }
          else if (lVar14 == 2) {
            FUN_003182d0(*(u32 *)((u8 *)unit_row->unk_054 + 0x128),0,2,8,0);
            unaff_s5 = 0xe;
          }
          else if (lVar14 == 3) {
            unaff_s5 = 0x10;
          }
          FUN_00459d60();
          FUN_003bb010_typed(*(u16 *)unit_row->unk_054,1);
          if (*(int *)(iVar2 + 0x10) != 0) {
            *(u32 *)(iVar2 + 0x10) = 0;
          }
          uVar6 = FUN_00459f60(param_1,*(u16 *)(config + 0x10),unaff_s5);
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
            loop_row = &DAT_0086e6a0_unit_rows[iVar11];
            FUN_001b0260(*(u32 *)loop_row->pad_170,1);
            if (lVar14 != lVar8) {
              uVar3 = FUN_001dde00_typed(loop_row->unit_id);
              FUN_003182d0(*(u32 *)((u8 *)loop_row->unk_054 + 0x128),0,uVar3,8,1);
              *((u8 *)loop_row->unit + 0x43) = 1;
            }
            lVar8 = iVar11 + 1;
          }
          return 1;
        }
        iVar5 = FUN_00318b60(*(u32 *)((u8 *)unit_row->unk_054 + 0x128));
        FUN_001ad940(auStack_20,*(u32 *)(*piVar13 + 0x1e0));
        lVar8 = FUN_0044f1c0(*(float *)(config + 4),(float *)(iVar5 + 0x30),(float *)auStack_20);
        if (lVar8 != 1) {
          iVar5 = FUN_00318b60(*(u32 *)((u8 *)unit_row->unk_054 + 0x128));
          FUN_001ad940(auStack_60,*(u32 *)(*piVar13 + 0x1e0));
          lVar8 = FUN_0044f1c0(*(float *)config,(float *)(iVar5 + 0x30),(float *)auStack_60);
          if ((lVar8 == 1) && (param_3 == '\x01')) {
            FUN_003bb010_typed(*(u16 *)unit_row->unk_054,0);
            if (*(int *)(iVar2 + 0x10) != 0) {
              *(u32 *)(iVar2 + 0x10) = 0;
            }
            uVar6 = FUN_00459f60(param_1,*(u16 *)(config + 0x12),0);
            *(u32 *)(iVar2 + 0x10) = uVar6;
            *(u8 *)(iVar2 + 7) = 2;
            lVar8 = 0;
            while (lVar8 < 4) {
              iVar7 = (int)lVar8;
              iVar10 = iVar7 * 0x1c0;
              loop_row = &DAT_0086e6a0_unit_rows[iVar7];
              FUN_001b0260(*(u32 *)loop_row->pad_170,1);
              uVar3 = FUN_001dde00_typed(loop_row->unit_id);
              FUN_003182d0(*(u32 *)((u8 *)loop_row->unk_054 + 0x128),0,uVar3,8,1);
              if (lVar14 != lVar8) {
                cVar1 = *((char *)loop_row->unit + 0x43);
                if ((cVar1 == '\0') || (cVar1 == '\b')) {
                  *((u8 *)loop_row->unit + 0x43) = 8;
                }
              }
              lVar8 = iVar7 + 1;
            }
            FUN_001ad940(&uStack_70,*(u32 *)(*piVar13 + 0x1e0));
            *(u32 *)(iVar2 + 0x1c) = uStack_70;
            *(u32 *)(iVar2 + 0x20) = uStack_6c;
            *(u32 *)(iVar2 + 0x24) = uStack_68;
            sVar4 = FUN_001b0220(*(u32 *)unit_row->pad_170);
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
            for (iVar10 = 0; iVar7 = FUN_001b0220(*(u32 *)unit_row->pad_170),
                iVar10 < iVar7; iVar10 = iVar10 + 1) {
              uVar9 = (u32)FUN_001b01b0_typed((void *)(*(u32 *)unit_row->pad_170),iVar10);
              FUN_00521250_typed((void *)(iVar2 + iVar10 * 0x18 + 0x2c),(const void *)(uVar9),0x18);
            }
            FUN_001b00c0(*(u32 *)unit_row->pad_170);
            FUN_001b0260(*(u32 *)unit_row->pad_170,0);
            return 1;
          }
        }
        else {
          uVar9 = FUN_00318b60(*(u32 *)((u8 *)unit_row->unk_054 + 0x128));
          FUN_001ad940(auStack_30,*(u32 *)(*piVar13 + 0x1e0));
          lVar8 = FUN_001c6450(*(u32 *)(config + 8),
                               *(u32 *)(config + 4),uVar9,auStack_30);
          if (lVar8 == 1) {
            *(u8 *)(iVar2 + 7) = 1;
            if (lVar14 == 0) {
              unaff_s5 = 0xd;
              FUN_003182d0(*(u32 *)((u8 *)unit_row->unk_054 + 0x128),0,2,8,0);
            }
            else if (lVar14 == 1) {
              FUN_003182d0(*(u32 *)((u8 *)unit_row->unk_054 + 0x128),0,1,8,0);
              unaff_s5 = 0xf;
            }
            else if (lVar14 == 2) {
              FUN_003182d0(*(u32 *)((u8 *)unit_row->unk_054 + 0x128),0,2,8,0);
              unaff_s5 = 0xe;
            }
            else if (lVar14 == 3) {
              unaff_s5 = 0x10;
            }
            FUN_00459d60();
            FUN_003bb010_typed(*(u16 *)unit_row->unk_054,1);
            if (*(int *)(iVar2 + 0x10) != 0) {
              *(u32 *)(iVar2 + 0x10) = 0;
            }
            uVar6 = FUN_00459f60(param_1,*(u16 *)(config + 0x10),unaff_s5);
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
              loop_row = &DAT_0086e6a0_unit_rows[iVar11];
              FUN_001b0260(*(u32 *)loop_row->pad_170,1);
              if (lVar14 != lVar8) {
                uVar3 = FUN_001dde00_typed(loop_row->unit_id);
                FUN_003182d0(*(u32 *)((u8 *)loop_row->unk_054 + 0x128),0,uVar3,8,1);
                *((u8 *)loop_row->unit + 0x43) = 1;
              }
              lVar8 = iVar11 + 1;
            }
            return 1;
          }
          iVar5 = FUN_00318b60(*(u32 *)((u8 *)unit_row->unk_054 + 0x128));
          FUN_001ad940(auStack_40,*(u32 *)(*piVar13 + 0x1e0));
          lVar8 = FUN_0044f1c0(*(float *)config,(float *)(iVar5 + 0x30),(float *)auStack_40);
          if ((lVar8 == 1) && (param_3 == '\x01')) {
            FUN_003bb010_typed(*(u16 *)unit_row->unk_054,0);
            if (*(int *)(iVar2 + 0x10) != 0) {
              *(u32 *)(iVar2 + 0x10) = 0;
            }
            uVar6 = FUN_00459f60(param_1,*(u16 *)(config + 0x12),0);
            *(u32 *)(iVar2 + 0x10) = uVar6;
            *(u8 *)(iVar2 + 7) = 2;
            lVar8 = 0;
            while (lVar8 < 4) {
              iVar7 = (int)lVar8;
              iVar10 = iVar7 * 0x1c0;
              loop_row = &DAT_0086e6a0_unit_rows[iVar7];
              FUN_001b0260(*(u32 *)loop_row->pad_170,1);
              uVar3 = FUN_001dde00_typed(loop_row->unit_id);
              FUN_003182d0(*(u32 *)((u8 *)loop_row->unk_054 + 0x128),0,uVar3,8,1);
              if (lVar14 != lVar8) {
                cVar1 = *((char *)loop_row->unit + 0x43);
                if ((cVar1 == '\0') || (cVar1 == '\b')) {
                  *((u8 *)loop_row->unit + 0x43) = 8;
                }
              }
              lVar8 = iVar7 + 1;
            }
            FUN_001ad940(&uStack_50,*(u32 *)(*piVar13 + 0x1e0));
            *(u32 *)(iVar2 + 0x1c) = uStack_50;
            *(u32 *)(iVar2 + 0x20) = uStack_4c;
            *(u32 *)(iVar2 + 0x24) = uStack_48;
            sVar4 = FUN_001b0220(*(u32 *)unit_row->pad_170);
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
            for (iVar10 = 0; iVar7 = FUN_001b0220(*(u32 *)unit_row->pad_170),
                iVar10 < iVar7; iVar10 = iVar10 + 1) {
              uVar9 = (u32)FUN_001b01b0_typed((void *)(*(u32 *)unit_row->pad_170),iVar10);
              FUN_00521250_typed((void *)(iVar2 + iVar10 * 0x18 + 0x2c),(const void *)(uVar9),0x18);
            }
            FUN_001b00c0(*(u32 *)unit_row->pad_170);
            FUN_001b0260(*(u32 *)unit_row->pad_170,0);
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
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar10;
  char cVar6;
  int iLoop;
  int iVar12;
  int *piVar13;
  u8 *row;
  u8 *config;
  u8 auStack_30 [16];
  u8 auStack_20 [16];
  u8 auStack_10 [16];
  
  iVar10 = (int)param_2;
  iVar7 = iVar10 * 0x1c;
  iVar8 = iVar10 * 0x1c0;
  config = DAT_006b4ab0_abs + iVar7;
  if ((*(int *)((u8 *)DAT_0086e6e8 + iVar8) != 0) &&
      (*(int *)((u8 *)DAT_0086e6f4 + iVar8) != 0)) {
    for (iVar12 = 0; iVar12 < 4; iVar12 = iVar12 + 1) {
      row = DAT_008717a0_rows_abs[iVar12];
      if ((*(u32 *)(row + 0x48) != 0) && (*(u32 *)(row + 0x54) != 0)) {
        iVar1 = *(int *)(*(int *)(row + 0x16c) + 0x3c);
        piVar13 = (int *)(row + 0x54);
        iVar3 = FUN_00318b60(*(u32 *)(*(int *)(row + 0x54) + 0x128));
        FUN_001ad940(auStack_10,*(u32 *)(*piVar13 + 0x1e0));
        iVar5 = FUN_0044f1c0(*(float *)(config + 0xc),(float *)(iVar3 + 0x30),(float *)auStack_10);
        if (iVar5 == 1) {
          *(u8 *)(iVar1 + 7) = 1;
          if (iVar10 == 0) {
            cVar6 = 0xd;
            FUN_003182d0(*(u32 *)(*(int *)(row + 0x54) + 0x128),0,2,8,0);
          }
          else if (iVar10 == 1) {
            FUN_003182d0(*(u32 *)(*(int *)(row + 0x54) + 0x128),0,1,8,0);
            cVar6 = 0xf;
          }
          else if (iVar10 == 2) {
            FUN_003182d0(*(u32 *)(*(int *)(row + 0x54) + 0x128),0,2,8,0);
            cVar6 = 0xe;
          }
          else if (iVar10 == 3) {
            cVar6 = 0x10;
          }
          FUN_00459d60();
          FUN_003bb010_typed(**(u16 **)(row + 0x54),1);
          if (*(int *)(iVar1 + 0x10) != 0) {
            *(u32 *)(iVar1 + 0x10) = 0;
          }
          uVar4 = FUN_00459f60(param_1,*(s16 *)(config + 0x10),cVar6);
          *(u32 *)(iVar1 + 0x10) = uVar4;
          iVar7 = FUN_001b9120_u32();
          FUN_001e1360(*(u32 *)(iVar7 + 0xc),1);
          iVar7 = FUN_001b9120_u32();
          FUN_001d3810(*(u32 *)(iVar7 + 0x24),1);
          iVar7 = FUN_001b9120_u32();
          FUN_001cd670(*(u32 *)(iVar7 + 8),1);
          for (iLoop = 0; iLoop < 4; iLoop = iLoop + 1) {
            row = DAT_008717a0_rows_abs[iLoop];
            FUN_001b0260(*(u32 *)(row + 0x170),1);
            if (iVar10 != iLoop) {
              uVar2 = FUN_001dde00_typed(*(u16 *)(row + 0x1a8));
              FUN_003182d0(*(u32 *)(*(int *)(row + 0x54) + 0x128),0,uVar2,8,1);
              *(u8 *)(*(int *)(*(int *)(row + 0x16c) + 0x3c) + 7) = 1;
            }
          }
          return 1;
        }
        iVar3 = FUN_00318b60(*(u32 *)(*(int *)(row + 0x54) + 0x128));
        FUN_001ad940(auStack_20,*(u32 *)(*piVar13 + 0x1e0));
        iVar5 = FUN_0044f1c0(*(float *)(config + 4),(float *)(iVar3 + 0x30),(float *)auStack_20);
        if (iVar5 == 1) {
          iVar6 = FUN_00318b60(*(u32 *)(*(int *)(row + 0x54) + 0x128));
          FUN_001ad940(auStack_30,*(u32 *)(*piVar13 + 0x1e0));
          iVar5 = FUN_001c6450_typed(iVar6,auStack_30,*(float *)(config + 8),
                                     *(float *)(config + 4));
          if (iVar5 == 1) {
            *(u8 *)(iVar1 + 7) = 1;
            if (iVar10 == 0) {
              cVar6 = 0xd;
              FUN_003182d0(*(u32 *)(*(int *)(row + 0x54) + 0x128),0,2,8,0);
            }
            else if (iVar10 == 1) {
              FUN_003182d0(*(u32 *)(*(int *)(row + 0x54) + 0x128),0,1,8,0);
              cVar6 = 0xf;
            }
            else if (iVar10 == 2) {
              FUN_003182d0(*(u32 *)(*(int *)(row + 0x54) + 0x128),0,2,8,0);
              cVar6 = 0xe;
            }
            else if (iVar10 == 3) {
              cVar6 = 0x10;
            }
            FUN_00459d60();
            FUN_003bb010_typed(**(u16 **)(row + 0x54),1);
            if (*(int *)(iVar1 + 0x10) != 0) {
              *(u32 *)(iVar1 + 0x10) = 0;
            }
            uVar4 = FUN_00459f60(param_1,*(s16 *)(config + 0x10),cVar6);
            *(u32 *)(iVar1 + 0x10) = uVar4;
            iVar7 = FUN_001b9120_u32();
            FUN_001e1360(*(u32 *)(iVar7 + 0xc),1);
            iVar7 = FUN_001b9120_u32();
            FUN_001d3810(*(u32 *)(iVar7 + 0x24),1);
            iVar7 = FUN_001b9120_u32();
            FUN_001cd670(*(u32 *)(iVar7 + 8),1);
            for (iLoop = 0; iLoop < 4; iLoop = iLoop + 1) {
              row = DAT_008717a0_rows_abs[iLoop];
              FUN_001b0260(*(u32 *)(row + 0x170),1);
              if (iVar10 != iLoop) {
                uVar2 = FUN_001dde00_typed(*(u16 *)(row + 0x1a8));
                FUN_003182d0(*(u32 *)(*(int *)(row + 0x54) + 0x128),0,uVar2,8,1);
                *(u8 *)(*(int *)(*(int *)(row + 0x16c) + 0x3c) + 7) = 1;
              }
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
#pragma opt_loop_invariants reset

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
      uVar1 = *(volatile /* Removing this function's qualifier batch loses FUN_00459e80 (MATCH nd0 -> MISMATCH nd14, size 172 -> 172) - measured W170. */ u32 *)(iVar3 + 0x104c);
      sVar1 = *(volatile /* Removing this function's qualifier batch loses FUN_00459e80 (MATCH nd0 -> MISMATCH nd14, size 172 -> 172) - measured W170. */ short *)(psVar1 + 2);
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
  u32 uVar3;
  float fVar4;
  
  puVar1 = *(u32 **)(param_1 + 0x3c);
  if (*(char *)((int)puVar1 + 0x5d) == '\x01') {
    return 0;
  }
  switch(*(char *)(puVar1 + 1)) {
  case 0:
    uVar3 = FUN_00112370_typed((const char *)(DAT_006b4bc0));
    *puVar1 = uVar3;
    *(u8 *)(puVar1 + 1) = 1;
  case 1:
    if (FUN_00111f30_typed((void*)(*puVar1)) == 1) {
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
    fVar4 = FUN_004221a0(uGpffff82d4,1.0f,(float)(int)*(short *)(puVar1 + 0x11),10.0f,1);
    *(float *)(puVar1 + 0x12) = fVar4;
    *(u16 *)((int)puVar1 + 10) = 0;
    if (((short *)puVar1)[3] < 10) {
      ((short *)puVar1)[3]++;
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
    fVar4 = FUN_004221a0(1.0f,uGpffff82d4,(float)(int)*(short *)(puVar1 + 0x11),10.0f,1);
    *(float *)(puVar1 + 0x12) = fVar4;
    if (*(short *)(puVar1 + 0x11) < 10) {
      *(short *)(puVar1 + 0x11) = *(short *)(puVar1 + 0x11) + 1;
    }
    else {
      *(float *)(puVar1 + 0x12) = uGpffff82d4;
      *(u8 *)(puVar1 + 1) = 6;
    }
    FUN_0045a490();
    break;
  case 6:
    return 0xffffffff;
  case 7:
    break;
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

// FUN_0045A280

u32 FUN_0045a280(u32 param_1,u32 param_2)

{
  char minutes;
  char seconds;
  u32 uVar2;
  int lVar3;
  int iVar4;
  
  lVar3 = (*DAT_00960184_abs)(1,0x60,0x40000);
  if (lVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00194b80_u32arg(param_1,0x106f,DAT_006b4be0,FUN_0045a020,FUN_0045a220,lVar3);
    uGpffffba08 = uVar2;
    iVar4 = (int)lVar3;
    *(u8 *)(iVar4 + 4) = 0;
    *(u8 *)(iVar4 + 5) = 0;
    *(u16 *)(iVar4 + 0x44) = 0;
    *(u32 *)(iVar4 + 0x48) = 0;
    *(u8 *)(iVar4 + 0x42) = 0;
    *(u8 *)(iVar4 + 0x43) = 0;
    *(u8 *)(iVar4 + 0x4c) = 1;
    *(int *)(iVar4 + 0x50) = param_2;
    minutes = (char)(param_2 / 0x3c);
    seconds = (char)(param_2 % 0x3c);
    *(char *)(iVar4 + 0x54) = minutes / '\n';
    *(char *)(iVar4 + 0x55) = minutes % '\n';
    *(char *)(iVar4 + 0x56) = seconds / '\n';
    *(char *)(iVar4 + 0x57) = seconds % '\n';
    *(u8 *)(iVar4 + 0x5c) = 0;
    *(u8 *)(iVar4 + 0x5d) = 0;
    uVar2 = uGpffffba08;
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



// Native `(u8)fVar8` costs +4 bytes (624/608 versus 620/608); retail keeps the expanded conversion.
#pragma opt_propagation reset
#pragma push
/* W380 measured: without 632/608 nd408 (OVER window); opt_loop_invariants off 608/608 nd284.
   Restores the setting this function previously received from a leaked file-scope pragma. */

#pragma pop
#pragma opt_loop_invariants reset









// MWCC b210 floor: the sole residual is commutative addu $v0,$a0,$v0 versus retail's
// addu $v0,$v0,$a0.






#pragma opt_lifetimes reset



#pragma opt_lifetimes reset
#pragma opt_propagation reset
#undef uStack_20
#undef uStack_1c
#undef uStack_18
#undef uStack_14
#undef uStack_10
#undef uStack_c
#undef fStack_8
#undef fStack_4

#pragma opt_lifetimes reset

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




#pragma opt_common_subs reset

#pragma opt_lifetimes reset
