#include "temporary.h"
/* FUSION_GLOBALS */
extern int *piGpffffb98c;
typedef int (*code)(...);
/* FUSION_EXACT_PROTOS */
u32 FUN_003c8b50(u32 param_1,int param_2);
extern void FUN_003c9240(int *);
extern u64 FUN_003c9290(int *,u64,u64);
extern s8 FUN_003c9340(int *);
extern void FUN_003c9390(int *);
extern u32 FUN_003c9460(u32 *);
#pragma alias fclMisc9fe0Call FUN_003c9fe0
extern void fclMisc9fe0Call(int *);
#pragma alias fclMisc9240Call FUN_003c9240
extern void fclMisc9240Call(int *);
#pragma alias fclMisc9290Call FUN_003c9290
extern u64 fclMisc9290Call(int *,u32,u32);
#pragma alias fclMisc9340Call FUN_003c9340
extern u32 fclMisc9340Call(int *);
#pragma alias fclMisc9390Call FUN_003c9390
extern void fclMisc9390Call(int *);
#pragma alias fclMisc9460DirectCall FUN_003c9460
extern u32 fclMisc9460DirectCall(int *);
#include "Kosaka/k_assert.h"
typedef struct FclMiscVec2
{
    f32 x;
    f32 y;
} FclMiscVec2;
typedef struct FclMiscVec3
{
    f32 x;
    f32 y;
    f32 z;
} FclMiscVec3;
typedef struct FclMiscVec4
{
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} FclMiscVec4;
typedef struct FclMiscRGBA
{
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} FclMiscRGBA;
typedef union FclMiscColor
{
    f32 packed;
    FclMiscRGBA rgba;
} FclMiscColor;
typedef union FclMiscPair
{
    FclMiscVec2 vec;
    u64 bits;
} FclMiscPair;
typedef union FclMisc9570SpecialValues
{
    FclMiscVec3 vec;
    s32 raw[3];
} FclMisc9570SpecialValues;
typedef struct FclMisc9570Layout
{
    s32 sizeTable[8];
    FclMisc9570SpecialValues specialValues;
} FclMisc9570Layout;
typedef struct FclMisc9850Work
{
    s32 facility;
    s32 active;
    u8 reserved08[4];
    s16 width;
    s16 height;
    u8 reserved10[8];
    s32 status;
    u8 reserved1c[0xa8];
    s32 drawHandle;
    u8 reservedc8[4];
    u32 battlePackage;
    u8 reservedd0[0xc];
    u32 initialData[3];
    u8 reservede8[4];
} FclMisc9850Work;
#pragma alias fclMiscDrawStatusCall FUN_00133180
extern void fclMiscDrawStatusCall(u64 position, f32 alpha,
                                   void *persona, void *currentStats, s32 fade);
#pragma alias fclMiscDrawStatusNoPersonaCall FUN_001332f0
extern void fclMiscDrawStatusNoPersonaCall(u64 position, f32 alpha,
                                            void *unused, void *persona, s32 fade);
#pragma alias fclMisc106fb0Call FUN_00106fb0
extern void fclMisc106fb0Call(u16 id, u64 position);
typedef u32 undefined3;
typedef u32 int3;
#define CONCAT13(a,b) ((((u32)(a) & 0xffu) << 24) | ((u32)(b) & 0x00ffffffu))

extern u32 gp0xffffaa08;
extern u32 gp0xffffaa10;
extern u32 gp0xffffaa14;

#ifndef CONCAT44
#define CONCAT44(hi,lo) ((((u64)(hi)) << 32) | (u32)(lo))
#endif
extern char DAT_006a3e18[];
extern char DAT_006a4270[];
extern char DAT_006a42f0[];
#pragma alias DAT_006a3e18_abs DAT_006a3e18
extern char DAT_006a3e18_abs[];
#pragma alias fclMiscSizeTable DAT_006a3f70
extern s32 fclMiscSizeTable[];
#pragma alias fclMiscSpecialValues DAT_006a3f88
extern f32 fclMiscSpecialValues[];
extern u32 DAT_006a41e8;
extern u32 DAT_006a41f8;
#pragma alias DAT_006a41e8_abs DAT_006a41e8
extern u8 DAT_006a41e8_abs[];
#pragma alias DAT_006a41f8_abs DAT_006a41f8
extern u8 DAT_006a41f8_abs[];
#pragma alias fclMiscInitialRotation DAT_006a4218
extern FclMiscVec3 fclMiscInitialRotation[];
#pragma alias fclMiscInitialTranslation DAT_006a4228
extern FclMiscVec3 fclMiscInitialTranslation[];
#pragma alias fclMiscDefaultQuat DAT_006a4240
extern FclMiscVec4 fclMiscDefaultQuat[];
#pragma alias fclMiscDefaultScale DAT_006a4250
extern u64 fclMiscDefaultScale[];
#pragma alias fclMiscDefaultScaleZ DAT_006a4258
extern f32 fclMiscDefaultScaleZ[];
#pragma alias fclMiscDefaultPosition DAT_006a4260
extern u64 fclMiscDefaultPosition[];
#pragma alias fclMiscDefaultPositionZ DAT_006a4268
extern f32 fclMiscDefaultPositionZ[];
extern f32 DAT_007cd718;
extern u8 DAT_007cd720;
extern s32 DAT_007cd728;
extern u32 DAT_007ce0cc;
extern u32 DAT_007ce680;
extern u32 DAT_0095be80;
extern u32 DAT_0095be84;
extern u32 DAT_0095be85;
extern u32 DAT_0095be88;
extern u32 DAT_0095be8c;
extern u32 DAT_0095be8d;
extern u32 DAT_0095be90;
extern u32 DAT_0095be94;
extern u32 DAT_0095be95;
extern u32 DAT_0095be98;
extern u32 DAT_0095be9c;
extern u32 DAT_0095be9d;
extern code DAT_00960090;
extern code DAT_00960178;
#pragma alias DAT_00960178_abs DAT_00960178
extern code DAT_00960178_abs[];
extern code DAT_0096017c;
#pragma alias DAT_0096017c_abs DAT_0096017c
extern code DAT_0096017c_abs[];
#pragma alias FUN_001339a0_f32 FUN_001339a0
extern int FUN_001339a0_f32(float param_1,int param_2,int param_3,int param_4,int param_5);

extern u32 LAB_003c84bc;
extern u32 LAB_003cf728;
extern u32 LAB_003cf7a4;
extern u32 LAB_003cf9d8;
extern u8 * PTR_LAB_006a4060;
#pragma alias PTR_LAB_006a4060_abs PTR_LAB_006a4060
extern u8 *PTR_LAB_006a4060_abs[];
extern u8 * PTR_s_facility_pss_battle_pak_006a4040;
#pragma alias fclMiscFacilityPssBattlePakTable PTR_s_facility_pss_battle_pak_006a4040
extern u8 *fclMiscFacilityPssBattlePakTable[];
#pragma alias fclMiscTaskDescriptor0 DAT_006a40a0
extern u8 fclMiscTaskDescriptor0[];
#pragma alias fclMiscTaskDescriptor1 DAT_006a40b0
extern u8 fclMiscTaskDescriptor1[];
#pragma alias fclMiscTaskDescriptor2 DAT_006a40c0
extern u8 fclMiscTaskDescriptor2[];
#pragma alias fclMiscTaskWork DAT_006a40d8
extern u8 fclMiscTaskWork[];
#pragma alias fclMiscTaskUpdateCallback FUN_003ca230
extern code fclMiscTaskUpdateCallback[];
#pragma alias fclMiscTaskLoadCallback FUN_003ca610
extern code fclMiscTaskLoadCallback[];
#pragma alias fclMiscTaskDrawCallback FUN_003ca660
extern code fclMiscTaskDrawCallback[];
#pragma alias fclMiscTaskDestroyCallback FUN_003ca6b0
extern code fclMiscTaskDestroyCallback[];
extern f32 fGpffff808c;
extern f32 fGpffff80e0;
extern f32 fGpffff8110;
extern f32 fGpffff81f0;
extern u32 iGpffffb730;
extern u32 iGpffffb98c;
extern s16 uGpffffaa18;
extern s16 uGpffffaa1a;
extern s16 uGpffffaa1c;
extern s16 uGpffffaa1e;
extern s16 uGpffffaa20;
extern s16 uGpffffaa22;
extern s16 uGpffffaa24;
extern s16 uGpffffaa26;
extern u32 uGpffffb98c;
extern code DAT_00960090;
extern code DAT_00960178;
extern code DAT_0096017c;

// Retail calls this with $a0 untouched (no argument), so keep the
// unprototyped decl instead of including kwlnTask.h's real prototype.
int kwlnTaskGetWorkData(void);
/* Region 0x390000-0x3CFFFF recovered prototypes */
u32 fclMisc003c9ab0(void);
void fclMisc003c9b00(u32 param_1, void* param_2, void* param_3);
extern u64 fclMiscCa780Call(float, float, float, float, s32, s32, s32, s32, s32, s32, s32);
#pragma alias fclMisc52e878Call FUN_0052e878
extern f32 fclMisc52e878Call(f32);
u32 fclMisc003c9c10(u32 param_1, void* param_2, void* param_3);
#pragma alias fclMiscCa780Call FUN_003ca780
#pragma alias fclMiscCacc0Call FUN_003cacc0
extern void fclMiscCacc0Call(void *);
#pragma alias fclMiscC31b0Call FUN_004c31b0
extern void fclMiscC31b0Call(f32, void *, void *, s32);
#pragma alias fclMisc6bc80Call FUN_0016bc80
extern void fclMisc6bc80Call(s32, u16, void *);
#pragma alias fclMisc6bdb0Call FUN_0016bdb0
extern void fclMisc6bdb0Call(s32, u16, void *);
#pragma alias fclMiscE2a0Callback FUN_003ce2a0
extern u64 fclMiscE2a0Callback(u64);
#pragma alias fclMiscF080Callback FUN_003cf080
extern void fclMiscF080Callback(void);
#pragma alias fclMiscA2580Call FUN_003a2580
extern s32 fclMiscA2580Call(s32);
#pragma alias fclMiscC49e0Call FUN_003c49e0
extern int *fclMiscC49e0Call(int *, int *, int *);
#pragma alias fclMiscContextCall FUN_00195540
extern s32 fclMiscContextCall(void);
#pragma alias fclMiscAllocCall FUN_00119a60
extern s32 fclMiscAllocCall(s32);
#pragma alias fclMiscReleaseCall FUN_001124b0
extern void fclMiscReleaseCall(s32);
#pragma alias fclMiscFreeCall FUN_00100ec0
extern void fclMiscFreeCall(s32);
#pragma alias fclMiscAssertCall FUN_0019d3f0
extern void fclMiscAssertCall(u32, u32);
#pragma alias fclMisc3174e0Call FUN_003174e0
extern void fclMisc3174e0Call(s32);
#pragma alias fclMisc11f30Call FUN_00111f30
extern u32 fclMisc11f30Call(s16 *);
#pragma alias fclMisc9460Call FUN_003c9460
extern u32 fclMisc9460Call(u32 *);
#pragma alias fclMisc8d80Int FUN_003c8d80
extern u32 fclMisc8d80Int(void);
#pragma alias fclMisc8550Call FUN_003c8550
extern u64 fclMisc8550Call(u32);



/* Region call-cast macros */
#define FUN_003c8400(...) ((u32 (*)(...))FUN_003c8400)(__VA_ARGS__)
#define FUN_003c8550(...) ((u64 (*)(...))FUN_003c8550)(__VA_ARGS__)
#define FUN_003c8770(...) ((u64 (*)(...))FUN_003c8770)(__VA_ARGS__)
#define FUN_003c8810(...) ((u64 (*)(...))FUN_003c8810)(__VA_ARGS__)
#define FUN_003c88d0(...) ((void (*)(...))FUN_003c88d0)(__VA_ARGS__)
#define FUN_003c89a0(...) ((u64 (*)(...))FUN_003c89a0)(__VA_ARGS__)
#define FUN_003c8b50(...) ((u32 (*)(...))FUN_003c8b50)(__VA_ARGS__)
#define FUN_003c8d80(...) ((u8 (*)(...))FUN_003c8d80)(__VA_ARGS__)
#define FUN_003c8da0(...) ((void (*)(...))FUN_003c8da0)(__VA_ARGS__)
#define FUN_003c8dc0(...) ((void (*)(...))FUN_003c8dc0)(__VA_ARGS__)
#undef FUN_003c8d80
extern u8 FUN_003c8d80(void);
#define FUN_003c8d80(...) ((u8 (*)(...))FUN_003c8d80)(__VA_ARGS__)
#undef FUN_003c8dc0
extern void FUN_003c8dc0(u32);
#define FUN_003c8dc0(...) ((void (*)(...))FUN_003c8dc0)(__VA_ARGS__)
#define FUN_003c8dd0(...) ((void (*)(...))FUN_003c8dd0)(__VA_ARGS__)
#define FUN_003c8de0(...) ((u64 (*)(...))FUN_003c8de0)(__VA_ARGS__)
#define FUN_003c8ea0(...) ((u16 (*)(...))FUN_003c8ea0)(__VA_ARGS__)
#define FUN_003c8ec0(...) ((u32 (*)(...))FUN_003c8ec0)(__VA_ARGS__)
#define FUN_003c8f20(...) ((void (*)(...))FUN_003c8f20)(__VA_ARGS__)
#define FUN_003c8f40(...) ((void (*)(...))FUN_003c8f40)(__VA_ARGS__)
#define FUN_003c8f70(...) ((void (*)(...))FUN_003c8f70)(__VA_ARGS__)
#define FUN_003c8fa0(...) ((void (*)(...))FUN_003c8fa0)(__VA_ARGS__)
#define FUN_003c9000(...) ((void (*)(...))FUN_003c9000)(__VA_ARGS__)
#define FUN_003c91b0(...) ((u8 (*)(...))FUN_003c91b0)(__VA_ARGS__)
#define FUN_003c9240(...) ((void (*)(...))FUN_003c9240)(__VA_ARGS__)
#define FUN_003c9290(...) ((u64 (*)(...))FUN_003c9290)(__VA_ARGS__)
#define FUN_003c9340(...) ((s8 (*)(...))FUN_003c9340)(__VA_ARGS__)
#define FUN_003c9390(...) ((void (*)(...))FUN_003c9390)(__VA_ARGS__)
#define FUN_003c9460(...) ((u32 (*)(...))FUN_003c9460)(__VA_ARGS__)
#define FUN_003c94e0(...) ((u32 (*)(...))FUN_003c94e0)(__VA_ARGS__)
#define FUN_003c9570(...) ((void (*)(...))FUN_003c9570)(__VA_ARGS__)
#define FUN_003c9790(...) ((u8 (*)(...))FUN_003c9790)(__VA_ARGS__)
#define FUN_003c9850(...) ((u64 (*)(...))FUN_003c9850)(__VA_ARGS__)
#define FUN_003c9cd0(...) ((void (*)(...))FUN_003c9cd0)(__VA_ARGS__)
#define FUN_003c9d00(...) ((void (*)(...))FUN_003c9d00)(__VA_ARGS__)
#define FUN_003c9d80(...) ((void (*)(...))FUN_003c9d80)(__VA_ARGS__)
#define FUN_003c9e00(...) ((void (*)(...))FUN_003c9e00)(__VA_ARGS__)
#define FUN_003c9e30(...) ((void (*)(...))FUN_003c9e30)(__VA_ARGS__)
#define FUN_003c9e70(...) ((void (*)(...))FUN_003c9e70)(__VA_ARGS__)
#define FUN_003c9ee0(...) ((s8 (*)(...))FUN_003c9ee0)(__VA_ARGS__)
#define FUN_003c9f10(...) ((void (*)(...))FUN_003c9f10)(__VA_ARGS__)
#define FUN_003c9f60(...) ((void (*)(...))FUN_003c9f60)(__VA_ARGS__)
#define FUN_003c9fb0(...) ((void (*)(...))FUN_003c9fb0)(__VA_ARGS__)
#define FUN_003c9fe0(...) ((void (*)(...))FUN_003c9fe0)(__VA_ARGS__)
#define FUN_003ca230(...) ((u64 (*)(...))FUN_003ca230)(__VA_ARGS__)
#define FUN_003ca610(...) ((u64 (*)(...))FUN_003ca610)(__VA_ARGS__)
#define FUN_003ca660(...) ((u64 (*)(...))FUN_003ca660)(__VA_ARGS__)
#define FUN_003ca6b0(...) ((void (*)(...))FUN_003ca6b0)(__VA_ARGS__)
#define FUN_003ca780(...) fclMiscCa780Call(__VA_ARGS__)
#define FUN_003ca960(...) ((void (*)(...))FUN_003ca960)(__VA_ARGS__)
#define FUN_003cacc0(...) ((void (*)(...))FUN_003cacc0)(__VA_ARGS__)
#define FUN_003cb050(...) ((void (*)(...))FUN_003cb050)(__VA_ARGS__)
#define FUN_003cb100(...) ((void (*)(...))FUN_003cb100)(__VA_ARGS__)
#define FUN_003cb1f0(...) ((void (*)(...))FUN_003cb1f0)(__VA_ARGS__)
#define FUN_003cb960(...) ((void (*)(...))FUN_003cb960)(__VA_ARGS__)
#define FUN_003cba50(...) ((void (*)(...))FUN_003cba50)(__VA_ARGS__)
#define FUN_003ccc40(...) ((void (*)(...))FUN_003ccc40)(__VA_ARGS__)
#define FUN_003cd0b0(...) ((void (*)(...))FUN_003cd0b0)(__VA_ARGS__)
#define FUN_003cd5a0(...) ((void (*)(...))FUN_003cd5a0)(__VA_ARGS__)
#define FUN_003cda00(...) ((u32 (*)(...))FUN_003cda00)(__VA_ARGS__)
#define FUN_003cda60(...) ((void (*)(...))FUN_003cda60)(__VA_ARGS__)
#define FUN_003cdba0(...) ((u32 (*)(...))FUN_003cdba0)(__VA_ARGS__)
#define FUN_003cdc80(...) ((u32 (*)(...))FUN_003cdc80)(__VA_ARGS__)
#define FUN_003cdcd0(...) ((u64 (*)(...))FUN_003cdcd0)(__VA_ARGS__)
#define FUN_003cdd80(...) ((u8 (*)(...))FUN_003cdd80)(__VA_ARGS__)
#define FUN_003cde00(...) ((void (*)(...))FUN_003cde00)(__VA_ARGS__)
#define FUN_003cde70(...) ((void (*)(...))FUN_003cde70)(__VA_ARGS__)
#define FUN_003cdee0(...) ((void (*)(...))FUN_003cdee0)(__VA_ARGS__)
#define FUN_003cdf40(...) ((void (*)(...))FUN_003cdf40)(__VA_ARGS__)
#define FUN_003ce060(...) ((void (*)(...))FUN_003ce060)(__VA_ARGS__)
#define FUN_003ce180(...) ((void (*)(...))FUN_003ce180)(__VA_ARGS__)
#define FUN_003ce2a0(...) ((u64 (*)(...))FUN_003ce2a0)(__VA_ARGS__)
#define FUN_003cea50(...) ((u64 (*)(...))FUN_003cea50)(__VA_ARGS__)
#define FUN_003cf6c0(...) ((short (*)(...))FUN_003cf6c0)(__VA_ARGS__)
#define FUN_003cf960(...) ((u64 (*)(...))FUN_003cf960)(__VA_ARGS__)
#define FUN_003cfb50(...) ((void (*)(...))FUN_003cfb50)(__VA_ARGS__)





#undef FUN_003c8400
#define FUN_003c8400(...) ((u32 (*)(...))FUN_003c8400)(__VA_ARGS__)
#undef FUN_003c8550
#define FUN_003c8550(...) ((u64 (*)(...))FUN_003c8550)(__VA_ARGS__)
#undef FUN_003c8770
#define FUN_003c8770(...) ((u64 (*)(...))FUN_003c8770)(__VA_ARGS__)
#undef FUN_003c8810
 
 
#define FUN_003c8810(...) ((u64 (*)(...))FUN_003c8810)(__VA_ARGS__)
#undef FUN_003c88d0
#pragma alias DAT_0095be80_abs DAT_0095be80
extern u8 DAT_0095be80_abs[];
extern u8 DAT_006a3f60[];
#undef FUN_003c89a0
extern u64 FUN_003c89a0(void);
#define FUN_003c88d0(...) ((void (*)(...))FUN_003c88d0)(__VA_ARGS__)
#undef FUN_003c89a0
#undef FUN_003c8770
extern u64 FUN_003c8770(u32, s32);
#undef FUN_003c8810
extern u64 FUN_003c8810(int *);
#undef FUN_003c8dc0
extern void FUN_003c8dc0(u32);
#undef FUN_003c8400
extern u32 FUN_003c8400(u32 param_1,int param_2);
#undef FUN_003c8b50
extern u32 FUN_003c8b50(u32 param_1,int param_2);
#undef FUN_003c91b0
extern u8 FUN_003c91b0(u8 *, u32);
#define FUN_003c89a0(...) ((u64 (*)(...))FUN_003c89a0)(__VA_ARGS__)
#undef FUN_003c8b50
#define FUN_003c8b50(...) ((u32 (*)(...))FUN_003c8b50)(__VA_ARGS__)
#undef FUN_003c8d80
#define FUN_003c8d80(...) ((u8 (*)(...))FUN_003c8d80)(__VA_ARGS__)
#undef FUN_003c8da0
#define FUN_003c8da0(...) ((void (*)(...))FUN_003c8da0)(__VA_ARGS__)
#undef FUN_003c8dc0
#define FUN_003c8dc0(...) ((void (*)(...))FUN_003c8dc0)(__VA_ARGS__)
#undef FUN_003c8dd0
#define FUN_003c8dd0(...) ((void (*)(...))FUN_003c8dd0)(__VA_ARGS__)
#undef FUN_003c8de0
#define FUN_003c8de0(...) ((u64 (*)(...))FUN_003c8de0)(__VA_ARGS__)
#undef FUN_003c8ea0
#define FUN_003c8ea0(...) ((u16 (*)(...))FUN_003c8ea0)(__VA_ARGS__)
#undef FUN_003c8ec0
#define FUN_003c8ec0(...) ((u32 (*)(...))FUN_003c8ec0)(__VA_ARGS__)
#undef FUN_003c8f20
#define FUN_003c8f20(...) ((void (*)(...))FUN_003c8f20)(__VA_ARGS__)
#undef FUN_003c8f40
#undef FUN_003c8810
#define FUN_003c8810(...) ((u64 (*)(...))FUN_003c8810)(__VA_ARGS__)
#define FUN_003c8f40(...) ((void (*)(...))FUN_003c8f40)(__VA_ARGS__)
#undef FUN_003c8f70
#undef FUN_003c8fa0
void FUN_003c8fa0(void);
#define FUN_003c8fa0(...) ((void (*)(...))FUN_003c8fa0)(__VA_ARGS__)
#define FUN_003c8f70(...) ((void (*)(...))FUN_003c8f70)(__VA_ARGS__)
#undef FUN_003c8fa0
#undef FUN_003c9460
u32 FUN_003c9460(u32 *param_1);
#define FUN_003c9460(...) ((u32 (*)(...))FUN_003c9460)(__VA_ARGS__)
#define FUN_003c8fa0(...) ((void (*)(...))FUN_003c8fa0)(__VA_ARGS__)
#undef FUN_003c9000
#define FUN_003c9000(...) ((void (*)(...))FUN_003c9000)(__VA_ARGS__)
#undef FUN_003c91b0
#define FUN_003c91b0(...) ((u8 (*)(...))FUN_003c91b0)(__VA_ARGS__)
#undef FUN_003c9240
#undef FUN_003c9460
u32 FUN_003c9460(u32 *param_1);
#define FUN_003c9460(...) ((u32 (*)(...))FUN_003c9460)(__VA_ARGS__)
#define FUN_003c9240(...) ((void (*)(...))FUN_003c9240)(__VA_ARGS__)
#undef FUN_003c9290

#define FUN_003c9290(...) ((u64 (*)(...))FUN_003c9290)(__VA_ARGS__)
#undef FUN_003c9340
#define FUN_003c9340(...) ((s8 (*)(...))FUN_003c9340)(__VA_ARGS__)
#undef FUN_003c9390
#define FUN_003c9390(...) ((void (*)(...))FUN_003c9390)(__VA_ARGS__)
#undef FUN_003c9460
#define FUN_003c9460(...) ((u32 (*)(...))FUN_003c9460)(__VA_ARGS__)
#undef FUN_003c94e0
#pragma alias DAT_0095be90_abs DAT_0095be90
extern u8 DAT_0095be90_abs[];
#define FUN_003c94e0(...) ((u32 (*)(...))FUN_003c94e0)(__VA_ARGS__)
#undef FUN_003c9570
#define FUN_003c9570(...) ((void (*)(...))FUN_003c9570)(__VA_ARGS__)
#undef FUN_003c9570
#undef FUN_003c9790


#define FUN_003c9570(...) ((void (*)(...))FUN_003c9570)(__VA_ARGS__)
#define FUN_003c9790(...) ((u8 (*)(...))FUN_003c9790)(__VA_ARGS__)
#undef FUN_003c9850
#define FUN_003c9850(...) ((u64 (*)(...))FUN_003c9850)(__VA_ARGS__)
#undef FUN_003c9cd0
#define FUN_003c9cd0(...) ((void (*)(...))FUN_003c9cd0)(__VA_ARGS__)
#undef FUN_003c9d00
#define FUN_003c9d00(...) ((void (*)(...))FUN_003c9d00)(__VA_ARGS__)
#undef FUN_003c9d80
#define FUN_003c9d80(...) ((void (*)(...))FUN_003c9d80)(__VA_ARGS__)
#undef FUN_003c9e00
#define FUN_003c9e00(...) ((void (*)(...))FUN_003c9e00)(__VA_ARGS__)
#undef FUN_003c9e30
#define FUN_003c9e30(...) ((void (*)(...))FUN_003c9e30)(__VA_ARGS__)
#undef FUN_003c9e70
#define FUN_003c9e70(...) ((void (*)(...))FUN_003c9e70)(__VA_ARGS__)
#undef FUN_003c9ee0
#define FUN_003c9ee0(...) ((s8 (*)(...))FUN_003c9ee0)(__VA_ARGS__)
#undef FUN_003c9f10
#define FUN_003c9f10(...) ((void (*)(...))FUN_003c9f10)(__VA_ARGS__)
#undef FUN_003c9f60
#define FUN_003c9f60(...) ((void (*)(...))FUN_003c9f60)(__VA_ARGS__)
#undef FUN_003c9fb0
#define FUN_003c9fb0(...) ((void (*)(...))FUN_003c9fb0)(__VA_ARGS__)
#undef FUN_003c9fe0
#define FUN_003c9fe0(...) ((void (*)(...))FUN_003c9fe0)(__VA_ARGS__)
#undef FUN_003ca230
#define FUN_003ca230(...) ((u64 (*)(...))FUN_003ca230)(__VA_ARGS__)
#undef FUN_003ca610
#define FUN_003ca610(...) ((u64 (*)(...))FUN_003ca610)(__VA_ARGS__)
#undef FUN_003ca660
#define FUN_003ca660(...) ((u64 (*)(...))FUN_003ca660)(__VA_ARGS__)
#undef FUN_003ca6b0

#define FUN_003ca6b0(...) ((void (*)(...))FUN_003ca6b0)(__VA_ARGS__)
#undef FUN_003ca780
#define FUN_003ca780(...) fclMiscCa780Call(__VA_ARGS__)
#undef FUN_003ca960
#define FUN_003ca960(...) ((void (*)(...))FUN_003ca960)(__VA_ARGS__)
#undef FUN_003cacc0
#define FUN_003cacc0(...) ((void (*)(...))FUN_003cacc0)(__VA_ARGS__)
#undef FUN_003cb050
#define FUN_003cb050(...) ((void (*)(...))FUN_003cb050)(__VA_ARGS__)
#undef FUN_003cb100

#define FUN_003cb100(...) ((void (*)(...))FUN_003cb100)(__VA_ARGS__)
#undef FUN_003cb1f0
#define FUN_003cb1f0(...) ((void (*)(...))FUN_003cb1f0)(__VA_ARGS__)
#undef FUN_003cb960
#define FUN_003cb960(...) ((void (*)(...))FUN_003cb960)(__VA_ARGS__)
#undef FUN_003cba50
#undef auStack_28
#define FUN_003cba50(...) ((void (*)(...))FUN_003cba50)(__VA_ARGS__)

#undef FUN_003ccc40
#define FUN_003ccc40(...) ((void (*)(...))FUN_003ccc40)(__VA_ARGS__)

#undef FUN_003cd0b0
#define FUN_003cd0b0(...) ((void (*)(...))FUN_003cd0b0)(__VA_ARGS__)
#undef FUN_003cd5a0
#define FUN_003cd5a0(...) ((void (*)(...))FUN_003cd5a0)(__VA_ARGS__)
#undef FUN_003cda00
#define FUN_003cda00(...) ((u32 (*)(...))FUN_003cda00)(__VA_ARGS__)
#undef FUN_003cda60
#define FUN_003cda60(...) ((void (*)(...))FUN_003cda60)(__VA_ARGS__)
#undef FUN_003cdba0

#define FUN_003cdba0(...) ((u32 (*)(...))FUN_003cdba0)(__VA_ARGS__)
#undef FUN_003cdc80
#define FUN_003cdc80(...) ((u32 (*)(...))FUN_003cdc80)(__VA_ARGS__)
#undef FUN_003cdcd0
#define FUN_003cdcd0(...) ((u64 (*)(...))FUN_003cdcd0)(__VA_ARGS__)
#undef FUN_003cdd80
#define FUN_003cdd80(...) ((u8 (*)(...))FUN_003cdd80)(__VA_ARGS__)
#undef FUN_003cde00
#define FUN_003cde00(...) ((void (*)(...))FUN_003cde00)(__VA_ARGS__)
#undef FUN_003cde70
#define FUN_003cde70(...) ((void (*)(...))FUN_003cde70)(__VA_ARGS__)
#undef FUN_003cdee0
#define FUN_003cdee0(...) ((void (*)(...))FUN_003cdee0)(__VA_ARGS__)
#undef FUN_003cdf40
#define FUN_003cdf40(...) ((void (*)(...))FUN_003cdf40)(__VA_ARGS__)
#undef FUN_003ce060
#define FUN_003ce060(...) ((void (*)(...))FUN_003ce060)(__VA_ARGS__)
#undef FUN_003ce180
#define FUN_003ce180(...) ((void (*)(...))FUN_003ce180)(__VA_ARGS__)
#undef FUN_003ce2a0












#define FUN_003ce2a0(...) ((u64 (*)(...))FUN_003ce2a0)(__VA_ARGS__)
#undef FUN_003cea50
#define FUN_003cea50(...) ((u64 (*)(...))FUN_003cea50)(__VA_ARGS__)
#undef FUN_003cf6c0
#define FUN_003cf6c0(...) ((short (*)(...))FUN_003cf6c0)(__VA_ARGS__)
#undef FUN_003cf960
#define FUN_003cf960(...) ((u32 (*)(...))FUN_003cf960)(__VA_ARGS__)
#undef FUN_003cfb50
#define FUN_003cfb50(...) ((void (*)(...))FUN_003cfb50)(__VA_ARGS__)
