#include "Yajima/y_misc.h"
#include "Yajima/y_runtime.h"
#if 0
#include "temporary.h"
#include "Main/Social/sfl_res.h"
#endif
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
#pragma alias RwCameraBeginUpdate_u32 RwCameraBeginUpdate
extern int RwCameraBeginUpdate_u32(u32 camera);
#pragma alias RwCameraEndUpdate_u32 RwCameraEndUpdate
extern void RwCameraEndUpdate_u32(u32 camera);
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
extern f32 sinf(f32 value);
extern f32 FUN_001126b0(u32 param_1);
extern f32 FUN_00112740(u32 param_1);
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
void FUN_00427db0(int object, YajimaVec2 value);
void FUN_00427de0(int param_1,u8 param_2,u8 param_3,u8 param_4, u8 param_5);
void FUN_00427e20(float param_1,float param_2,int param_3);
void FUN_00427e50(int param_1,u8 param_2);
void FUN_00427e60(int param_1,u8 param_2);
void FUN_00427e70(float param_1,u32 param_4,float param_2,float param_3,int param_5,int param_6, u32 *param_7);
u32 FUN_004281f0(u32 param_1);
void FUN_00429c60(int param_1);
u32 FUN_00429d40(u32 param_1,u64 param_2);
void FUN_00429e80(int param_1,u8 param_2);
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
#pragma alias FUN_004560d0_typed FUN_004560d0
extern u32 FUN_004560d0_typed(u32 param_1,float param_2,float param_3,float param_4,u32 param_5,u32 param_6);
#pragma alias FUN_00423fe0_vec2 FUN_00423fe0
extern void FUN_00423fe0_vec2(YajimaVec2 *param_1,int param_2,int param_3,int param_4,int param_5,int param_6);
#pragma alias FUN_004c31b0_ymisc FUN_004c31b0
extern void FUN_004c31b0_ymisc(void *matrix,const void *axis,f32 angle,s32 mode);
#pragma alias FUN_004c6be0_ymisc FUN_004c6be0
extern void FUN_004c6be0_ymisc(float *out,const float *in,u32 matrix);
void FUN_004563b0(f32 value, int object);
int FUN_0044f120();
int FUN_0044f170();
extern int FUN_00488f30(void);
extern void FUN_00430780(f32, YajimaVec2, s32, s32, s32);
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
u32 DAT_008717e8[];
#pragma alias DAT_008717e8_abs DAT_008717e8
extern u8 DAT_008717e8_abs[];
int DAT_008717f4[];
#pragma alias DAT_008717f4_abs DAT_008717f4
extern u8 DAT_008717f4_abs[];
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
u8 DAT_0095c100[];
u8 DAT_0095c110[];
u8 DAT_0095c210[];
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
#pragma alias FUN_004d0f00_arg FUN_004d0f00
extern void FUN_004d0f00_arg(u32 param_1);
#pragma alias FUN_00115980_arg FUN_00115980
extern void FUN_00115980_arg(u32 param_1);
#pragma alias FUN_00194b80_u32 FUN_00194b80
extern u32 FUN_00194b80_u32(u32, u32, u8 *, u32 (*)(int), void (*)(int), u32);
#pragma alias FUN_00194b20_u32 FUN_00194b20
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
#pragma alias FUN_004c69f0_typed FUN_004c69f0
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
        H_Cdvd_Destroy();
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
          H_Cdvd_Destroy();
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
        H_Cdvd_Destroy();
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
        H_Cdvd_Destroy();
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

      FUN_004d0f00(lVar2);

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
  if (cVar1 == '@') {
    if ((*(char *)(iVar3 + 5) != '\x02') && (*(char *)(iVar3 + 5) == '\x01')) {
      FUN_004cb7f0(uVar4,auStack_60,*(u32 *)&auStack_20[*(u32 *)(iVar3 + 0x18) & 3]);
    }
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
  else if (cVar1 == '\x03') {
    mdl00318a70(*(u32 *)(iVar2 + 8),auStack_60,*(u32 *)&auStack_20[*(u32 *)(iVar3 + 0x18) & 3]);
  }
  else if (cVar1 == '\x02') {
    FUN_0041bee0(*(u32 *)(iVar2 + 8),auStack_60,
                 *(u32 *)&auStack_20[*(u32 *)(iVar3 + 0x18) & 3]);
  }
  else if (cVar1 == '\x01') {
    FUN_0034fe30_fcl((float)(*(int *)(iVar3 + 0xc) / 0xffff),(float)(*(int *)(iVar3 + 0x10) / 0xffff),
                     (float)(*(int *)(iVar3 + 0x14) / 0xffff),*(u32 *)(iVar2 + 8));
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
  case '\x06':
    afStack_a8[0] = (float)(*(int *)(iVar1 + 0xc) / 0xffff);
    afStack_a8[1] = (float)(*(int *)(iVar1 + 0x10) / 0xffff);
    fVar12 = (float)(*(int *)(iVar1 + 0x14) / 0xffff);
    fVar12 = func_0020c500((const f32 *)(iVar4 + 8),fVar12);
    func_0020c320(iVar4 + 8,afStack_a8,fVar12,afStack_b0);
    sflResSetSpritePosition((void *)*(u32 *)(iVar4 + 8),afStack_b0);
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

  FUN_003bb010(uVar1,*(u8 *)(*param_2 + 0x14));

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

  RwMatrixMultiply((void*)auStack_70,(void*)auStack_70,(void*)iVar3);

  mdl00318a70(*(u32 *)(iVar2 + 8),auStack_70,0);

  mdlScale(*(u32 *)(iVar2 + 8),&uStack_30,1);

  return 1;

}

#pragma push
#pragma opt_loop_invariants on
/* measured opt_loop_invariants: off nd11/obj308, on nd10/obj308; retained */

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

    H_Fade_FadeIn();

  }

  else {

    H_Fade_FadeOut();

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

      fVar11 = center.y;

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
       (float)*(int *)(param_2 + 0xc) == ((float)(int)(uVar4 << 1) + 6.0f) - 1.0f)) {

      *puVar1 = *puVar1 & ~uVar3;

    }

  }

  *(int *)(param_2 + 0xc) = *(int *)(param_2 + 0xc) + 1;

  return (float)(int)(puVar1[1] << 1) + 6.0f < (float)*(int *)(param_2 + 0xc);

}
#pragma opt_loop_invariants off
#pragma pop

// FUN_0041A900 NONMATCHING


u8 FUN_0041a900(u64 param_1,int param_2)



{

  int iVar1;

  float fVar2;

  u32 uVar3;

  int iVar4;

  float *pfVar5;

  float *pfVar6;

  float fVar7;

  float fVar8;

  float fVar9;

  float fVar10;

  float afStack_c8 [10];

  RwMatrix matrix;

  float afStack_70 [16];

  RwV3d position;

  RwV3d center;

  RwV3d axis;

  

  iVar1 = *(int *)(*(int *)(param_2 + 4) + 8);

  pfVar6 = (float *)&DAT_006b2fd0;

  pfVar5 = afStack_70 + 4;

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

  pfVar5 = afStack_c8 + 2;

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

      lVar5 = FUN_003c4b50(*piVar2,*piVar2 + 4,uVar8);

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

// FUN_0041BF80 NONMATCHING


void FUN_0041bf80(u32 *param_1)



{

  u32 uVar1;

  u32 uVar2;

  int iVar3;

  int lVar4;

  u32 *puVar5;

  u32 *puVar6;

  u32 auStack_40 [16];

  

  (*DAT_00960090)(9,2);

  (*DAT_00960090)(0x14,2);

  (*DAT_00960090)(8,0);

  (*DAT_00960090)(6,0);

  (*DAT_00960090)(0xe,0);

  (*DAT_00960090)(0xc,1);

  (*DAT_00960090)(7,2);

  (*DAT_00960090)(10,5);

  (*DAT_00960090)(0xb,6);

  (*DAT_00960090)(1,*(u32 *)param_1[3]);

  RpSkyRenderStateSet(2,(void*)0x48);

  RpSkyRenderStateSet(3,(void*)0x71801);

  if ((*param_1 & 1) == 0) {

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

  else {

    iVar3 = kwlnGetMainCamera();

    FUN_004c2f30(auStack_40,(const void *)param_1[4],(const void *)(*(int *)(iVar3 + 4) + 0x10));

  }

  lVar4 = FUN_004f1ed0(param_1[1],(short)param_1[2],auStack_40,1);

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
      sVar3 = FUN_0043a9d0((char)unaff_s5_lo,(char)iVar6,0);
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

  DAT_007ce6ac = FUN_00447e70(0,1,0);

  return 1;

}

// FUN_00425070


u32 FUN_00425070(void)
{
  if (DAT_007ce6ac != 0) {
    return 0;
  }
  FUN_00449fa0();
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

  DAT_007ce6ac = FUN_00447e70(0,0,0);

  return 1;

}

// FUN_00425320


u32 FUN_00425320(void)
{
  if (DAT_007ce6ac != 0) {
    return 0;
  }
  FUN_00449fa0();
  return 1;
}

// FUN_00425360


u32 FUN_00425360(void)
{
  int iVar1;
  for (iVar1 = 0; iVar1 < 4; iVar1 = iVar1 + 1) {
    FUN_00458850(*(u32 *)(DAT_0086e6a0 + iVar1 * 0x1c0 + 0x16c));
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

  FUN_0045a280(0,uVar1);

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
  if (FUN_0045a3b0() == 1) {
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

  FUN_0045a3e0();

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

  FUN_0045a430((s8)iVar1);

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
  uVar1 = FUN_0045af40();
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

    if (cVar1 == '\x04') {

      FUN_00317a20((&DAT_0095bec0)[pcVar2[2]]);

    }

    else if (cVar1 == '\x03') {

      FUN_00317a20((&DAT_0095bea0)[pcVar2[3]]);

    }

    else {

      if (cVar1 != '\x02') {

        if (cVar1 != '\x01') {

          if (cVar1 != '\0') goto LAB_00425aec;

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

        }

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

      }

      FUN_00317a20((&DAT_0095bec0)[pcVar2[1]]);

      FUN_00317a20((&DAT_0095bea0)[pcVar2[3]]);

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

  u32 *puVar11;

  u32 *puVar12;

  u32 auStack_60 [16];

  YajimaVec4 directionalColor;

  YajimaVec4 ambientColor;

  

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

    RpSkyRenderStateSet(2,0x44);

    RpSkyRenderStateSet(3,0x717fb);

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

    RpSkyRenderStateSet(2,0x44);

    RpSkyRenderStateSet(3,0x717fb);

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

    RpSkyRenderStateSet(2,0x48);

    RpSkyRenderStateSet(3,0x71801);

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
  uVar2 = FUN_00194b80_u32(param_2, 0x106f, (u8 *)DAT_006b4400 + 0x40,
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


void FUN_00427db0(int object, YajimaVec2 value)
{
    YajimaVec2* destination = (YajimaVec2*)(*(int*)(object + 0x3c) + 0x134);

    *destination = value;
}

// FUN_00427DE0


void FUN_00427de0(int param_1,u8 param_2,u8 param_3,u8 param_4,

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


void FUN_00427e20(float param_1,float param_2,int param_3)



{

  int iVar1;

  

  iVar1 = *(int *)(param_3 + 0x3c);

  *(int *)(iVar1 + 0x128) = (int)param_1;

  *(int *)(iVar1 + 300) = (int)param_2;

  return;

}

// FUN_00427E50


void FUN_00427e50(int param_1,u8 param_2)



{

  *(u8 *)(*(int *)(param_1 + 0x3c) + 0x150) = param_2;

  return;

}

// FUN_00427E60


void FUN_00427e60(int param_1,u8 param_2)



{

  *(u8 *)(*(int *)(param_1 + 0x3c) + 0x18c) = param_2;

  return;

}

#define DAT_00960090 Yajima_setState

/* W327 measured: opt_loop_invariants on reduces normalized_diff 574 -> 566 (object 896/896 -> 872/896). */
#pragma opt_loop_invariants on
// FUN_00427E70 NONMATCHING


void FUN_00427e70(float depth, u32 color, float x, float y, int width, int height,
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
  RpSkyRenderStateSet(2, 0x48);
  RpSkyRenderStateSet(3, 0x71801);

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

  float fVar27;
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

      if ((DAT_008717e8 != 0 && DAT_008717f4 != 0) && (*(int *)(pcVar1 + 0x898) != 0)) {

        FUN_00456400(*(int *)(pcVar1 + 0x898),0);

      }

      for (iVar15 = 0; iVar15 < 4; iVar15 = iVar15 + 1) {

        if (*(int *)(pcVar1 + iVar15 * 4 + 0x4c) != 0) {

          *(u8 *)(*(int *)(pcVar1 + iVar15 * 4 + 0x4c) + 0x18) = 0xff;

        }

      }

      if (*(int *)(pcVar1 + 0xb1c) != 0) {

        FUN_004302a0();

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

    uVar26 = FUN_00431110(param_1,*(u64 *)(pcVar1 + 0x85c),pcVar1[0xb28],0);

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

    uVar12 = FUN_004229d0(param_1,*(u64 *)(pcVar1 + 0x85c),2);

    *(int *)(pcVar1 + 0xb20) = (int)uVar12;

    FUN_00422c30(uVar12,*(u64 *)(pcVar1 + 0x85c),auStack_80);

    FUN_00422c10(*(u32 *)(pcVar1 + 0xb20),10);

    FUN_00422cd0(*(u32 *)(pcVar1 + 0xb20),1);

    uVar26 = FUN_00431110(param_1,*(u64 *)(pcVar1 + 0x85c),pcVar1[0xb28],0);

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

    uVar26 = FUN_00430180(param_1);

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

        FUN_00430a40((char)(iVar15 + 1));
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

      DAT_0095c210[iVar15] = 0;
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
      fVar25 = FUN_0042a3f0((float)cVar6,(float *)0x86e684);
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
      fVar25 = FUN_0042a4a0((float)cVar6,(u32 *)0x86e684);
      fVar24 = fVar24 - fVar25;

      iVar15 = (int)cVar6;
      if (cVar6 < '\0') {
        iVar15 = iVar15 + 3;
      }

      *(float *)(pcVar1 + 0xb04) =
          (float)(iVar15 >> 2) + fVar24 + 2.0f - (float)((int)cVar6 << 1);

      cVar6 = FUN_0044f120(0x86e684);
      pcVar1[0xb08] = cVar6;

      cVar6 = FUN_0044f170(0x86e684);
      pcVar1[0xb09] = cVar6;
    }

    FUN_0042fd80((float *)&vec,param_1);
    vec2 = vec;

    cVar6 = FUN_0044f120(&vec2);
    pcVar1[0xb0b] = cVar6;

    cVar6 = FUN_0044f170(&vec2);
    pcVar1[0xb0c] = cVar6;

    FUN_00430630(param_1);

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

    if (DAT_008717e8 != 0 && DAT_008717f4 != 0) {

      FUN_00423fe0(&fStack_38,0,0x7e,0x7e,4,4);

      *(float *)(pcVar1 + 0x89c) = *(float *)(pcVar1 + 0x85c) + fStack_38;

      *(float *)(pcVar1 + 0x8a0) = *(float *)(pcVar1 + 0x860) + fStack_34;

      FUN_004561d0(*(u32 *)(pcVar1 + 0x89c),*(u32 *)(pcVar1 + 0x8a0),

                   *(u32 *)(pcVar1 + 0x898));

      FUN_00456400(*(u32 *)(pcVar1 + 0x898),1);

      uVar3 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

      uVar4 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4 + 0x1e0));
      FUN_0042a550(param_1,0,(s8)uVar3,(s8)uVar4);


      if (DAT_007ce6c4 == '\0') {

        cVar6 = pcVar1[0xb0b];

        cVar5 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

        if ((cVar6 == cVar5) &&

           (cVar6 = pcVar1[0xb0c], cVar5 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4 + 0x1e0)),

           cVar6 == cVar5)) {

          DAT_007ce6c4 = '\x01';

          DAT_007ce6d8 = 1;

        }

        else {

          iVar15 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

          iVar17 = K_Field_Get();

          iVar13 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

          if (*(char *)(iVar17 + iVar15 * 0x100 + iVar13 * 0x10 + 0x4a) == '\b') {

            DAT_007ce6c4 = '\x01';

            DAT_007ce6d8 = 1;

          }

        }

      }

      if (((DAT_007ce6c8 == '\0') &&

          (cVar6 = pcVar1[0xb08], cVar5 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4 + 0x1e0)),

          cVar6 == cVar5)) &&

         (cVar6 = pcVar1[0xb09], cVar5 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4 + 0x1e0)),

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

        iVar7 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

        iVar13 = (int)pcVar1[0xb28];

        if (pcVar1[0xb28] < '\0') {

          iVar13 = iVar13 + 1;

        }

        iVar7 = iVar17 + (iVar7 - (iVar13 >> 1));

        iVar19 = iVar7 + -2;

        iVar8 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

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

            FUN_00430270(auStack_a0,*(u32 *)(pcVar1 + 0xb1c));

            if (pcVar1[0x865] != '\0') {
              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_0042a0d0((float)cVar6,(float *)(pcVar1 + 0x868));
              fVar27 = *(float *)(pcVar1 + 0x85c) +
                       (float)(cVar6 * iVar17) + fVar24;
              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_0042a3f0((float)cVar6,(float *)(pcVar1 + 0xb10));
              fVar27 = fVar27 - fVar24 - (float)((int)cVar6 << 1);
              iVar7 = (int)cVar6;
              iVar13 = iVar7;
              if (cVar6 < '\0') iVar13 = iVar13 + 1;
              packedCoord.x = (float)(iVar13 >> 1) + fVar27 - 6.0f;

              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_0042a180((float)cVar6,(u32 *)(pcVar1 + 0x868));
              fVar27 = *(float *)(pcVar1 + 0x860) +
                       (float)(cVar6 * iVar15) + fVar24;
              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_0042a4a0((float)cVar6,(u32 *)(pcVar1 + 0xb10));
              fVar27 = fVar27 - fVar24 - (float)((int)cVar6 << 1);
              iVar13 = (int)cVar6;
              if (cVar6 < '\0') iVar13 = iVar13 + 1;
              packedCoord.y = (float)(iVar13 >> 1) + fVar27;
            }
            else {
              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_00429ef0((float)cVar6,0);
              fVar27 = *(float *)(pcVar1 + 0x85c) +
                       (float)(cVar6 * iVar17) + fVar24;
              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_0042a3f0((float)cVar6,(float *)(pcVar1 + 0xb10));
              fVar27 = fVar27 - fVar24 - (float)((int)cVar6 << 1);
              iVar7 = (int)cVar6;
              iVar13 = iVar7;
              if (cVar6 < '\0') iVar13 = iVar7 + 1;
              packedCoord.x = (float)(iVar13 >> 1) + fVar27 - 6.0f;

              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_00429fe0((float)cVar6,0);
              fVar27 = *(float *)(pcVar1 + 0x860) +
                       (float)(cVar6 * iVar15) + fVar24;
              cVar6 = pcVar1[0xb29];
              fVar24 = FUN_0042a4a0((float)cVar6,(u32 *)(pcVar1 + 0xb10));
              fVar27 = fVar27 - fVar24 - (float)((int)cVar6 << 1);
              iVar13 = (int)cVar6;
              if (cVar6 < '\0') iVar13 = iVar13 + 1;
              packedCoord.y = (float)(iVar13 >> 1) + fVar27;
            }

            packedCoord.y = packedCoord.y - 6.0f;

            FUN_00430220(*(u32 *)(pcVar1 + 0xb1c),*(u64 *)&packedCoord);

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

      uVar12 = FUN_004229d0(param_1,*(u64 *)(pcVar1 + 0x85c),2);

      *(int *)(pcVar1 + 0xb20) = (int)uVar12;

      FUN_00422c30(uVar12,*(u64 *)(pcVar1 + 0x85c),auStack_90);

      FUN_00422c10(*(u32 *)(pcVar1 + 0xb20),10);

      FUN_00422cd0(*(u32 *)(pcVar1 + 0xb20),1);

      lVar14 = 0;

      while (lVar14 < pcVar1[0xb2a]) {

        iVar15 = (int)lVar14;

        pcVar20 = pcVar1 + iVar15 * 4 + 4;

        if (*(int *)(pcVar1 + iVar15 * 4 + 4) != 0) {

          H_Cdvd_Destroy();

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

    uVar26 = FUN_00431110(param_1,*(u64 *)(pcVar1 + 0x85c),pcVar1[0xb28],1);

    *(u32 *)(pcVar1 + 0xb24) = uVar26;
    FUN_0042bc10(param_1);


    DAT_007ce6dc = 1;

    FUN_00430630(param_1);

    *pcVar1 = '\x12';

    break;

  case '\x12':

    FUN_00422cd0(*(u32 *)(pcVar1 + 0xb20),1);

    if (DAT_008717e8 != 0 && DAT_008717f4 != 0) {

      FUN_00456400(*(u32 *)(pcVar1 + 0x898),1);

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

    uVar26 = RwV3dLength(&uStack_58);

    uVar12 = FUN_00530da0(uVar26);

    printf(0x6b4458,uVar12);

  }

  return 0;

}

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


void FUN_00429e80(int param_1,u8 param_2)



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

  K_FldFrame_CtlCopyPos(&local_20,*(u32 *)(DAT_008717f4[0] + 0x1e0));

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

  iVar1 = FUN_0044f120(&pos);
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

  iVar1 = FUN_0044f170(&pos);
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

  iVar1 = FUN_0044f120(&pos);
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

  iVar1 = FUN_0044f170(&pos);
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

      *(u8 *)((int)&DAT_0095c100 + iVar9 * 0x10 + iVar6) = 1;

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

    cVar1 = FUN_00435260(param_2);

    if (cVar1 == '\0') {

      cVar1 = FUN_004353f0(row);

      if (((cVar1 != '\x01') && (cGpffffb9d8 == '\0')) &&

         (DAT_0095c110[*(char *)(iVar5 + 0xb09) * 0x10 + (int)*(char *)(iVar5 + 0xb08)] == '\x01'

         )) {

        FUN_00456490(param_2);

        cGpffffb9d8 = '\x01';

      }

      if (cGpffffb9d4 == '\0') {

        cVar1 = *(char *)(iVar5 + 0xb0b);

        cVar2 = K_FldFrame_CtlGetXGrid(*(u32 *)((u8 *)row->unk_054 + 0x1e0));

        if ((cVar1 == cVar2) &&

           (cVar1 = *(char *)(iVar5 + 0xb0c),

           cVar2 = K_FldFrame_CtlGetZGrid(*(u32 *)((u8 *)row->unk_054 + 0x1e0)),

           cVar1 == cVar2)) {

          lVar7 = FUN_0043c730(param_2);

          if (lVar7 == 1) {

            cVar8 = FUN_004353f0(row);

            if (cVar8 != '\x01') {

              FUN_00456450(param_2);

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

    lVar7 = FUN_004352e0();

    if (((lVar7 == 0) && (cGpffffb9d8 == '\0')) &&

       (DAT_0095c110[*(char *)(iVar5 + 0xb09) * 0x10 + (int)*(char *)(iVar5 + 0xb08)] == '\x01'))

    {

      cGpffffb9d8 = '\x01';

    }

  }

  return;

}

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
      sprintf(DAT_0095bee0_abs, DAT_006b4490, param_2,
              table[i].secondary);
      request = H_Cdvd_Request(DAT_0095bee0_abs, 0);
      *(u32 *)(work + result * 4 + 4) = request;
      result++;
    }
  }
  return result;
}

// FUN_0042AC60 NONMATCHING


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
  iVar6 = (cVar2 * 0xf0 + (int)cVar2) * 4;
  piVar4 = (int *)(iVar6 + iGpffffb5c0);
  cVar2 = *(char *)((int)piVar4 + *(short *)(iVar1 + 0xb90) * 0x28 + 4);
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
      sprintf(DAT_0095bfe0_abs,DAT_006b44b0,param_2,*(u16 *)((int)piVar4 + 10));
      uVar3 = FUN_004d1260(DAT_0095bfe0_abs,0);
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

  K_FldFrame_CtlCopyPos(&fStack_50,*(u32 *)(DAT_008717f4 + 0x1e0));

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

      fVar11 = 63.0f - ((((*(float *)(iVar1 + 0xba4) - (*(float *)(iVar4 + -0x749c) - afStack_20[0]))

                        * 2.25f) / 100.0f) * 2.25f) / 100.0f;

      fVar12 = 63.0f - ((((*(float *)(iVar1 + 0xbac) - (*(float *)(iVar4 + -0x7494) - fStack_18)) *

                        2.25f) / 100.0f) * 2.25f) / 100.0f;

      afStack_40[0] = ((afStack_20[0] - fStack_10) * 2.25f) / 100.0f;
      afStack_40[2] = ((fStack_18 - fStack_8) * 2.25f) / 100.0f;

      afStack_40[1] = 0.0f;

      FUN_004c6be0_ymisc(afStack_40,afStack_40,uVar5);

      uVar6 = FUN_001158b0(0,uGpffffb9f4,7);

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

  K_FldFrame_CtlCopyPos(&fStack_50,*(u32 *)(DAT_008717f4 + 0x1e0));

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

      uVar5 = FUN_001158b0(0,uGpffffb9f4,0xb);

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
#pragma opt_common_subs off
// FUN_0042BC10 NONMATCHING


void FUN_0042bc10(int param_1)



{

  int iVar1;

  u32 uVar2;

  long lVar3;

  float fStack_8;

  float fStack_4;

  

  iVar1 = *(int *)((int)param_1 + 0x3c);

  if (*(u32 *)DAT_008717e8_abs != 0) {

    if (*(int *)(iVar1 + 0x898) != 0) {

      *(u32 *)(iVar1 + 0x898) = 0;

    }

    FUN_00423fe0(&fStack_8,0,0x7e,0x7e,0x20,0x20);

    *(float *)(iVar1 + 0x89c) = *(float *)(iVar1 + 0x85c) + fStack_8;

    uVar2 = FUN_004560d0_typed(param_1,*(float *)(iVar1 + 0x89c),
                               *(float *)(iVar1 + 0x8a0),1.0f,0x20,0x20);


    *(int *)(iVar1 + 0x898) = (int)uVar2;

    FUN_004563c0(uVar2,*(u8 *)(iVar1 + 0xb90));

    FUN_004563d0(*(u32 *)(iVar1 + 0x898),*(u64 *)(iVar1 + 0x85c));

    FUN_004563b0(*(f32 *)

                  (*(short *)(iVar1 + 0xb90) * 0x28 + *piGpffffa850 * 0x3c4 + iGpffffb5c0 + -0x74a0)

                 ,*(u32 *)(iVar1 + 0x898));

    *(u32 *)(iVar1 + 0xba4) = 0;

    *(u32 *)(iVar1 + 0xbac) = 0;


    for (lVar3 = 0; lVar3 < *(char *)(iVar1 + 0xb2a); lVar3 = (long)((int)lVar3 + 1)) {

      *(u8 *)(*(int *)(*(int *)(iVar1 + (int)lVar3 * 8 + 0x5c) + 0x3c) + 0x150) = 1;

    }

  }

  return;

}
#pragma opt_common_subs reset

/* W212: first divergence is the prologue (ours 0xc0-byte frame, retail 0xb0),
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

  int iVar7;

  int iVar8;

  int iVar9;

  u8 *row;

  

  work = *(u8 **)((int)param_1 + 0x3c);

  for (iVar7 = 0; iVar7 < 0x10; iVar7 = iVar7 + 1) {

    iVar6 = iVar7 * 0x100;

    row = work + iVar7 * 0x80;

    for (iVar8 = 0; iVar8 < 0x10; iVar8 = iVar8 + 1) {

      iVar4 = K_Field_Get();

      if (*(char *)(iVar6 + iVar4 + iVar8 * 0x10 + 0x48) == '\x01') {

        iVar4 = K_Field_Get();

        if (*(char *)(iVar6 + iVar4 + iVar8 * 0x10 + 0x49) == '\x01') {

          piVar5 = (int *)(row + iVar8 * 8 + 0x5c);

          if (*piVar5 != 0) {

            *piVar5 = 0;

          }

          iVar9 = iVar8 * 0x10;

          K_Field_Get();

          iVar4 = K_Field_Get();

          if (*(u8 *)(iVar6 + iVar4 + iVar9 + 0x4a) < 5) {

            iVar4 = K_Field_Get();

            bVar2 = *(u8 *)(iVar6 + iVar4 + iVar9 + 0x4a);

            iVar4 = K_Field_Get();

            uVar1 = *(u8 *)(iVar6 + iVar4 + iVar9 + 0x4a);

            iVar4 = K_Field_Get();

            iVar4 = FUN_00427670_typed(0.625f,0.625f,param_1,(&DAT_0095c0e0)[bVar2],uVar1,

                                 *(u8 *)(iVar6 + iVar4 + iVar9 + 0x4e));

            *piVar5 = iVar4;

          }

          else {

            iVar4 = K_Field_Get();

            bVar2 = *(u8 *)(iVar6 + iVar4 + iVar9 + 0x4a);

            iVar4 = K_Field_Get();

            uVar1 = *(u8 *)(iVar6 + iVar4 + iVar9 + 0x4a);

            iVar4 = K_Field_Get();

            iVar4 = FUN_00427670_typed(0.59375f,0.59375f,param_1,(&DAT_0095c0e0)[bVar2],uVar1,

                                 *(u8 *)(iVar6 + iVar4 + iVar9 + 0x4e));

            *piVar5 = iVar4;

          }

          *(u8 *)(*(int *)(*piVar5 + 0x3c) + 0x150) = 1;

          *(u8 *)(row + iVar8 * 8 + 0x60) = 0;

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

        piVar12 = DAT_008717f4 + param_2 * 0x70;

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

        iVar5 = FUN_0044f120(&worldPos1);

        fVar17 = worldPos1.x - ((float)iVar5 * 800.0f - 400.0f);

        uVar18 = 0x40000000;

        cVar2 = *(char *)(iVar10 + 0xb29);

        piVar12 = DAT_008717f4 + param_2 * 0x70;

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

        iVar5 = FUN_0044f170(&worldPos2);

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
            uVar9 = FUN_001158b0(0,DAT_007ce6e4,10);
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
            uVar9 = FUN_001158b0(0,DAT_007ce6e4,8);
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
              uVar9 = FUN_001158b0(0,DAT_007ce6e4,10);
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
              uVar9 = FUN_001158b0(0,DAT_007ce6e4,9);
              iVar7 = (int)uVar9;
              *(u32 *)(iVar7 + 0x2c) = uVar18;
              *(u32 *)(iVar7 + 0x10) = *(u32 *)(iVar10 + 0x8b8);
              *(u32 *)(iVar7 + 0x14) = *(u32 *)(iVar10 + 0x8bc);
              *(u8 *)(iVar7 + 0x18) = 0;
              func_001127d0(uVar9,1);
              FUN_00115980(uVar9);
            }
            else {
              uVar9 = FUN_001158b0(0,DAT_007ce6e4,7);
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
  s8 count;
  s32 outer;
  s32 inner;
  s32 end;

  work = *(u8 **)(param_1 + 0x3c);
  for (outer = 0; outer < 3; outer++) {
    if ((*(s8 *)(work + outer + 0x938) == 1) &&
        (FUN_0043a230((s8)(outer + 1)) == 1)) {
      inner = outer * 5;
      row = (YajimaPackedRow *)(work + outer * 8);
      end = (outer + 1) * 5;
      for (; inner < end; inner++) {
        entry = (YajimaPackedEntry *)(work + inner);
        counter = &entry->counter;
        offsetY = (s16 *)(work + inner * 2 + 0x914);
        offsetX = (s16 *)(work + inner * 2 + 0x8f6);
        FUN_00430780(8.0f, row->value,
                     *(s8 *)offsetX, *(s8 *)offsetY, entry->counter);
        delay = &entry->delay;
        if (entry->delay < 1) {
          count = entry->counter + 1;
          entry->counter = count;
          if (count > 20) {
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

          iVar6 = FUN_0044f120(&worldPos1);

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

          iVar6 = FUN_0044f170(&worldPos2);

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

            uVar9 = FUN_001158b0(0,DAT_007ce6e4,0xb);

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

            uVar9 = FUN_001158b0(0,DAT_007ce6e4,0xb);

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

          DAT_0095c210[iVar15] = 0;

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

      lVar8 = FUN_0044f120(&DAT_0086be04 + iVar15 * 0x10);

      if (((short)param_2 == lVar8) &&

         (lVar8 = FUN_0044f170(&DAT_0086be04 + iVar15 * 0x10),

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

          iVar6 = FUN_0044f120(&worldPos1);


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

          iVar6 = FUN_0044f170(&worldPos2);


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

          iVar5 = FUN_0044f120(&worldPos1);


          fVar17 = worldPos1.x - ((float)iVar5 * 800.0f - 400.0f);


          fVar18 = (float)(int)*(char *)(iVar2 + 0xb29);

          iVar10 = iVar15 * 0x10;

          pfVar14 = (float *)(&DAT_0086be04 + iVar10);

          worldPos2 = *(YajimaVec3 *)(&DAT_0086be04 + iVar10);

          iVar6 = FUN_0044f120(&worldPos2);


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

          iVar5 = FUN_0044f170(&worldPos1);


          fVar17 = worldPos1.z - ((float)iVar5 * 800.0f - 400.0f);


          cVar3 = *(char *)(iVar2 + 0xb29);

          worldPos2 = *(YajimaVec3 *)(&DAT_0086be04 + iVar10);

          iVar6 = FUN_0044f170(&worldPos2);


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

        if (iVar5 == 4) {

          uVar9 = FUN_001158b0(0,DAT_007ce6e4,5);

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

        }

        else if (iVar5 == 3) {

          uVar9 = FUN_001158b0(0,DAT_007ce6e4,0xc);

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

        }

        else if (iVar5 == 2) {
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

          fVar16 = (float)RwV3dLength(&delta);

          if (fVar16 < 2000.0f) {

            uVar9 = FUN_001158b0(0,DAT_007ce6e4,0xb);

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

        else if (iVar5 == 1) {

          uVar9 = FUN_001158b0(0,DAT_007ce6e4,7);

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


      lVar6 = FUN_0044f120(&DAT_0086bf8c + iVar9 * 0x138);

      if (((short)param_2 == lVar6) &&

         (lVar6 = FUN_0044f170(&DAT_0086bf8c + iVar9 * 0x138),

         (short)param_3 == lVar6)) {

        uVar7 = FUN_001158b0(0,DAT_007ce6e4,0xc);

        if (*(char *)(iVar2 + 0x865) != '\0') {

          cVar3 = *(char *)(iVar2 + 0xb29);

          iVar8 = iVar9 * 0x138;

          fStack_80 = *(float *)(&DAT_0086bf8c + iVar8);

          uStack_7c = *(u32 *)(&DAT_0086bf90 + iVar8);

          uStack_78 = *(u32 *)(&DAT_0086bf94 + iVar8);

          iVar4 = FUN_0044f120(&fStack_80);

          fVar14 = fStack_80 - ((float)iVar4 * 800.0f - 400.0f);

          fVar16 = (float)(int)*(char *)(iVar2 + 0xb29);

          fStack_70 = *(float *)(iVar2 + 0x868);

          uStack_6c = *(u32 *)(iVar2 + 0x86c);

          uStack_68 = *(u32 *)(iVar2 + 0x870);

          iVar4 = FUN_0044f120(&fStack_70);

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

          iVar4 = FUN_0044f170(&uStack_a0);

          fVar14 = fStack_98 - ((float)iVar4 * 800.0f - 400.0f);

          fVar16 = (float)(int)*(char *)(iVar2 + 0xb29);

          uStack_90 = *(u32 *)(iVar2 + 0x868);

          uStack_8c = *(u32 *)(iVar2 + 0x86c);

          fStack_88 = *(float *)(iVar2 + 0x870);

          iVar4 = FUN_0044f170(&uStack_90);

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

          iVar4 = FUN_0044f120(&fStack_30);

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

          iVar4 = FUN_0044f170(&uStack_60);

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

  if (((DAT_0086e580 == 1) && (sVar4 = FUN_0044f120(DAT_0086e684_abs), param_2 == sVar4)) &&

     (sVar4 = FUN_0044f170(DAT_0086e684_abs), param_3 == sVar4)) {

    uVar7 = FUN_001158b0(0,DAT_007ce6e4,5);

    if (*(char *)(iVar2 + 0x865) != '\0') {

      cVar3 = *(char *)(iVar2 + 0xb29);

      fStack_80 = DAT_0086e684;

      uStack_7c = DAT_0086e688;

      fStack_78 = DAT_0086e68c;

      iVar5 = FUN_0044f120(&fStack_80);

      fVar10 = fStack_80 - ((float)iVar5 * 800.0f - 400.0f);

      fVar12 = (float)(int)*(char *)(iVar2 + 0xb29);

      fStack_70 = *(float *)(iVar2 + 0x868);

      uStack_6c = *(u32 *)(iVar2 + 0x86c);

      uStack_68 = *(u32 *)(iVar2 + 0x870);

      iVar5 = FUN_0044f120(&fStack_70);

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

      iVar5 = FUN_0044f170(&fStack_a0);

      fVar10 = fStack_98 - ((float)iVar5 * 800.0f - 400.0f);

      fVar12 = (float)(int)*(char *)(iVar2 + 0xb29);

      uStack_90 = *(u32 *)(iVar2 + 0x868);

      uStack_8c = *(u32 *)(iVar2 + 0x86c);

      fStack_88 = *(float *)(iVar2 + 0x870);

      iVar5 = FUN_0044f170(&uStack_90);

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

      iVar5 = FUN_0044f120(&fStack_30);

      fVar10 = fStack_30 - ((float)iVar5 * 800.0f - 400.0f);

      fVar12 = (float)(int)*(char *)(iVar2 + 0xb29);

      K_FldFrame_CtlCopyPos(&mainPosX,*(u32 *)(DAT_008717f4 + 0x1e0));

      savedMainX = mainPosX;

      iVar5 = K_FldFrame_CtlGetXGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

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

      iVar5 = FUN_0044f170(&fStack_60);

      fVar10 = fStack_58 - ((float)iVar5 * 800.0f - 400.0f);

      fVar12 = (float)(int)*(char *)(iVar2 + 0xb29);

      K_FldFrame_CtlCopyPos(&uStack_50,*(u32 *)(DAT_008717f4 + 0x1e0));

      uStack_40 = uStack_50;

      uStack_3c = uStack_4c;

      fStack_38 = fStack_48;

      iVar5 = K_FldFrame_CtlGetZGrid(*(u32 *)(DAT_008717f4 + 0x1e0));

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
