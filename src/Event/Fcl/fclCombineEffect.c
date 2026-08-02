#include "temporary.h"
#include "Main/Social/sfl_res.h"
extern f32 sinf(f32);
extern f32 cosf(f32);
extern f32 FUN_0016bc00(u32 param_1,u32 param_2);
extern int kwlnTaskGetWorkData(void);
typedef int (*code)();
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
/* FUSION_EXACT_PROTOS */
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
void FUN_0041beb0(int param_1);
void FUN_0041bee0(int param_1);
void FUN_0041bf10(int param_1,u32 param_2);
void FUN_0041bf80(u32 *param_1);
void FUN_0041c140(u32 param_1,u32 param_2,u32 param_3,int param_4);
s32 FUN_003c44d0(s32 param_1,code param_2,code param_3,s32 param_4);
extern void *func_0010c3a0(void *entry, u32 *wasReady, s32 *byteCount);
extern void *mdlCreateFromRmdMemory(u16 type, u16 id, void *rmdMemory, u32 rmdSize, u32 readMode);
void FUN_0041c180(int param_1,int param_2,int param_3);
void FUN_0040e3c0(u32 param_1,u32 param_2,u8 param_3,u32 param_4);
#pragma alias FUN_00418130_abs FUN_00418130
extern code FUN_00418130_abs[];
#pragma alias FUN_00418230_abs FUN_00418230
extern code FUN_00418230_abs[];
typedef struct {
  f32 x;
  f32 y;
} FclEffectVec2;
/* FUSION_GLOBALS */
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
u16 DAT_007e094c[];
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
code DAT_00960090;
extern void *(*DAT_00960178)();
#pragma alias DAT_00960178_abs DAT_00960178
extern void *(*DAT_00960178_abs[])(u32, u32);
extern char DAT_006b2ae8[];
extern char DAT_006b2af8[];
extern char DAT_006b2b10[];
extern char DAT_006b2b20[];
extern char DAT_006b2b40[];
extern char DAT_006b2ad0[];
code DAT_0096017c;
#pragma alias DAT_0096017c_abs DAT_0096017c
extern code DAT_0096017c_abs[];
u32 LAB_00417fb0[];
u32 LAB_0041b798[];
#include "Kosaka/k_assert.h"






















 





/* measured opt_loop_invariants: off nd11/obj308, on nd10/obj308; retained */























/* measured opt_loop_invariants: off nd51/obj452, on nd49/obj452; retained */


/* measured opt_loop_invariants: off MISMATCH nd24/obj80, on MATCH nd0/obj80; retained */
/* measured opt_loop_invariants: off MISMATCH nd33/obj452, on MATCH nd0/obj452; retained */





























